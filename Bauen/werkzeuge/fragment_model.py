import collections
import hashlib
from pathlib import Path
import re
import struct
from static_check import ANCHORS, IMAGE, LE, MAP, explicit, lib
from object_meta import ix, record
from x86_disasm import MD, padding
import omf_extra
import r3_reloc

HERE = Path(".")


def is_anchor(address):
    return any(a <= address < b for a, b in ANCHORS)


def want(at, relative):
    if relative:
        return (
            at
            + 4
            + int.from_bytes(IMAGE[at - 0x10000 : at - 0x10000 + 4], "little", signed=True)
        ) & 0xFFFFFFFF
    if at not in LE or LE[at][0] != 7:
        raise ValueError("Kein Original-32bit-Fixup bei %06X" % at)
    return LE[at][1]


def native_padding(raw):
    if padding(raw):
        return True
    if len(raw) > 256:
        return False
    cursor = 0
    for ins in MD.disasm(raw, 0):
        if not any(raw[ins.address :]):
            return True
        if not padding(bytes(ins.bytes)):
            return False
        cursor = ins.address + ins.size
    return cursor == len(raw)


def payload_end(body, start, end):
    raw = bytes(body["data"][start:end])
    for ins in MD.disasm(raw, start):
        stop = ins.address + ins.size
        if ins.mnemonic in ("ret", "retf", "jmp") and native_padding(bytes(body["data"][stop:end])):
            if not any(body["mask"][stop:end]):
                return stop
    return end


def expand_lidata(path):
    raw = path.read_bytes()
    rows = list(r3_reloc.records(raw))
    if not any(t in (0xA2, 0xA3) for t, b in rows):
        return path, None
    info = lib["scan"](path)
    out = bytearray()
    last = False
    proof = []
    for typ, b in rows:
        if typ in (0xA2, 0xA3):
            sid, pos = r3_reloc.idx(b, 0)
            width = 4 if typ & 1 else 2
            off = int.from_bytes(b[pos : pos + width], "little")
            pos += width
            if info["segments"][sid]["cls"] == "CODE":
                raise ValueError("Iterierter CODE bleibt gesperrt")

            def block(pos):
                repeat = int.from_bytes(b[pos : pos + width], "little")
                count = int.from_bytes(b[pos + width : pos + width + 2], "little")
                pos += width + 2
                if count:
                    pieces = []
                    for _ in range(count):
                        piece, pos = block(pos)
                        pieces.append(piece)
                    body = b"".join(pieces)
                else:
                    n = b[pos]
                    pos += 1
                    body = b[pos : pos + n]
                    pos += n
                    if len(body) != n:
                        raise ValueError("LIDATA abgeschnitten")
                if len(body) * repeat > 16 * 1024 * 1024:
                    raise ValueError("LIDATA zu gross")
                return body * repeat, pos

            parts = []
            while pos < len(b):
                piece, pos = block(pos)
                parts.append(piece)
            payload = b"".join(parts)
            if off + len(payload) > info["segments"][sid]["length"]:
                raise ValueError("LIDATA hinter Segmentende")
            for start in range(0, len(payload), 1000):
                out += record(
                    0xA1,
                    ix(sid) + struct.pack("<I", off + start) + payload[start : start + 1000],
                )
            proof.append(
                dict(
                    segment=sid,
                    offset=off,
                    length=len(payload),
                    sha256=hashlib.sha256(payload).hexdigest(),
                )
            )
            last = True
            continue
        if typ in (0x9C, 0x9D) and last:
            if any(not thread for thread, part in lib["fixparts"](typ, b)):
                raise ValueError("Relokation innerhalb LIDATA bleibt gesperrt")
        if typ in (0xA0, 0xA1, 0xC2, 0xC3):
            last = False
        out += record(typ, b)
    dest = HERE / "normalisiert" / path.parent.name
    dest.mkdir(parents=True, exist_ok=True)
    target = dest / "lidata.OBJ"
    target.write_bytes(out)
    return target, dict(
        source=str(path),
        source_sha256=hashlib.sha256(raw).hexdigest(),
        sha256=hashlib.sha256(out).hexdigest(),
        records=proof,
    )


def model(row):
    source = Path(row["source"])
    if hashlib.sha256(source.read_bytes()).hexdigest() != row["source_sha256"]:
        raise ValueError("Quelle seit dem gebundenen Compilerbefund geaendert: " + row["unit"])
    compiled = Path(row["details"]["work"]) / "source.CPP"
    if compiled.read_bytes().replace(b"\r", b"") != source.read_bytes().replace(b"\r", b""):
        raise ValueError("Compilerobjekt gehoert zu einer anderen Quellfassung: " + row["unit"])
    path = Path(row["details"]["work"]) / "clean.OBJ"
    path, lidata = expand_lidata(path)
    raw = path.read_bytes()
    meta = r3_reloc.parse(path)
    obj = lib["omf"].modules(str(path))[0]
    owners = {("seg", i): s for i, s in obj["segs"].items() if s["cls"] == "CODE" and s["data"]}
    if not owners:
        raise ValueError("Kein CODE")
    all_bodies = {("seg", i): s for i, s in obj["segs"].items()}
    cds = {c["name"]: c for c in obj["comdats"]}
    for name, c in cds.items():
        key = ("comdat", name)
        all_bodies[key] = c
        if obj["segs"][c["seg"]]["cls"] == "CODE":
            owners[key] = c
    fx = omf_extra.fixups(raw)
    anchors = collections.defaultdict(dict)
    chunks = []
    dropped = []
    data_proof = []
    unmapped = collections.defaultdict(dict)
    tables = collections.defaultdict(set)
    recovered = []
    for sid, off, name in meta["pubs"]:
        key = ("seg", sid)
        if key not in owners:
            continue
        addr = explicit(name)
        if addr is None:
            addr = MAP.get(name)
        if addr is None:
            match = re.match(r"^W\?\$ct:X([0-9a-fA-F]{6})\$", name)
            if match and re.search(
                r"//@\s*f_" + match[1] + r"\s*\nX" + match[1] + r"::X" + match[1] + r"\(",
                Path(row["source"]).read_text(encoding="latin1"),
            ):
                addr = int(match[1], 16)
        if addr is None:
            unmapped[key].setdefault(off, []).append(name)
            continue
        if off in anchors[key] and anchors[key][off] != addr:
            raise ValueError("Widerspruechliche PUBDEF-Adresse")
        anchors[key][off] = addr
    for name, c in cds.items():
        key = ("comdat", name)
        address = explicit(name)
        if address is None and key in owners:
            address = row["details"].get("original_comdat_names", {}).get(name)
        if address is not None:
            anchors[key][0] = address
    function_starts = {key: dict(a) for key, a in anchors.items()}

    def belongs_anchor(key, off):
        choices = [(o, a) for o, a in function_starts.get(key, {}).items() if o <= off]
        return bool(choices) and is_anchor(max(choices)[1])

    first = {key: min(a) if a else len(owners[key]["data"]) for key, a in anchors.items()}
    for key, body in owners.items():
        first.setdefault(key, len(body["data"]))

    def locate(key, offset):
        options = [(o, a) for o, a in anchors[key].items() if o <= offset]
        if not options:
            return None
        off, addr = max(options)
        if any(off < u <= offset for u in unmapped[key]):
            return None
        return addr + offset - off

    segment_ids = {(s["name"], s["cls"], ""): ("seg", i) for i, s in obj["segs"].items()}
    for f in fx:
        key = tuple(f["owner"])
        if key not in owners or f["offset"] < first[key] or belongs_anchor(key, f["offset"]):
            continue
        at = locate(key, f["offset"])
        if at is None:
            continue
        if f["width"] != 4:
            raise ValueError("Nur belegte 32bit-Relokationen")
        target = f["target"]
        body = owners[key]
        value = (
            int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little") + f["displacement"]
        ) & 0xFFFFFFFF
        if target[0] == "segment" and tuple(target[1]) in segment_ids:
            dst = segment_ids[tuple(target[1])]
            table_entry = any(
                tuple(g["owner"]) == dst and g["offset"] == value and not g["relative"] and g["width"] == 4
                for g in fx
            )
            if dst in owners and (
                value < first[dst]
                or (not f["relative"] and table_entry and value not in function_starts.get(dst, {}))
            ):
                address = want(at, f["relative"])
                if value in anchors[dst] and anchors[dst][value] != address:
                    raise ValueError("Widerspruechliche Tabellenadresse")
                anchors[dst][value] = address
                tables[dst].add(value)
    graph_names = collections.defaultdict(set)

    def data_matches(key):
        body = all_bodies[key]
        if not anchors[key] or min(anchors[key]) != 0:
            return False
        for i, v in enumerate(body["data"]):
            at = locate(key, i)
            if at is None or not 0x10000 <= at < 0x10000 + len(IMAGE):
                return False
            if not body["mask"][i] and v != IMAGE[at - 0x10000]:
                return False
        return True

    for _ in range(30):
        old = sum(len(a) for a in anchors.values())
        for f in fx:
            key = tuple(f["owner"])
            body = all_bodies.get(key)
            if body is None or not anchors[key] or f["width"] != 4:
                continue
            if key in owners and belongs_anchor(key, f["offset"]):
                continue
            if key[0] == "comdat" and key in owners and is_anchor(anchors[key].get(0, 0)):
                continue
            if key not in owners and not data_matches(key):
                continue
            if key[0] == "comdat" and key in owners and not data_matches(key):
                live = any(
                    tuple(g["owner"]) in owners
                    and g["target"][0] == "external"
                    and g["target"][1] == key[1]
                    for g in fx
                )
                if not live and explicit(key[1]) is None:
                    continue
            at = locate(key, f["offset"])
            if at is None:
                continue
            add = (
                int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little") + f["displacement"]
            ) & 0xFFFFFFFF
            target = f["target"]
            address = want(at, f["relative"])
            if target[0] == "external":
                name = target[1]
                value = (address - add) & 0xFFFFFFFF
                if (
                    key not in owners
                    and ("comdat", name) in owners
                    and anchors[("comdat", name)]
                    and anchors[("comdat", name)].get(0) != value
                ):
                    continue
                graph_names[name].add(value)
                if len(graph_names[name]) != 1:
                    raise ValueError("Mehrere Originalziele fuer " + name + ": " + str(graph_names[name]))
                known = explicit(name)
                if known is not None and known != value:
                    raise ValueError("Explizites Symbol " + name + ": %06X statt %06X" % (known, value))
                if name in cds:
                    dst = ("comdat", name)
                    if 0 in anchors[dst] and anchors[dst][0] != value:
                        raise ValueError("COMDAT-Adresse widerspruechlich")
                    anchors[dst][0] = value
            elif target[0] == "segment":
                dst = segment_ids.get(tuple(target[1]))
                if dst and dst not in owners:
                    pubs = sorted((o, n) for ss, o, n in meta["pubs"] if ss == dst[1] and o <= add)
                    origin = (
                        pubs[-1][0]
                        if pubs
                        else (add if all_bodies[dst]["name"].startswith("CONST") else 0)
                    )
                    value = address - add + origin
                    if origin in anchors[dst] and anchors[dst][origin] != value:
                        raise ValueError("Interne Datenadresse widerspruechlich")
                    anchors[dst][origin] = value
        if sum(len(a) for a in anchors.values()) == old:
            break
    for key in list(owners):
        if key[0] == "comdat":
            live = any(
                tuple(g["owner"]) in owners
                and g["target"][0] == "external"
                and g["target"][1] == key[1]
                for g in fx
            )
            if not anchors[key] or (not live and explicit(key[1]) is None and not data_matches(key)):
                dropped.append(
                    dict(
                        name=key[1],
                        reason="Kein gebundener CODE-Verweis oder verifizierter Original-Datenverweis",
                    )
                )
                del owners[key]
            else:
                first[key] = 0
    for key, body in all_bodies.items():
        if key in owners:
            continue
        if anchors[key]:
            data_proof.append(
                dict(
                    owner=key,
                    anchors=anchors[key],
                    unmasked_bytes_identical=data_matches(key),
                    action="Originaldaten unveraendert erhalten",
                )
            )
    for f in fx:
        if tuple(f["owner"]) not in owners or f["target"][0] != "segment":
            continue
        dst = segment_ids.get(tuple(f["target"][1]))
        if dst and dst not in owners and not data_matches(dst):
            raise ValueError("Interne Daten nicht vollstaendig identisch: " + str(dst))
    for key, body in owners.items():
        if key[0] != "seg":
            continue
        starts = sorted(set(anchors[key]) | set(unmapped[key]))
        for i, off in enumerate(starts):
            if off not in anchors[key] or off in tables[key] or is_anchor(anchors[key][off]):
                continue
            end = starts[i + 1] if i + 1 < len(starts) else len(body["data"])
            end = payload_end(body, off, end)
            for ins in MD.disasm(bytes(body["data"][off:end]), off):
                data = bytes(ins.bytes)
                disp_off = (
                    1
                    if len(data) == 5 and data[0] in (0xE8, 0xE9)
                    else 2
                    if len(data) == 6 and data[0] == 15 and 0x80 <= data[1] <= 0x8F
                    else None
                )
                if disp_off is None or any(body["mask"][ins.address : ins.address + ins.size]):
                    continue
                displacement = int.from_bytes(data[disp_off : disp_off + 4], "little", signed=True)
                dst = ins.address + ins.size + displacement
                if off <= dst < end or not 0 <= dst < len(body["data"]):
                    continue
                target = locate(key, dst)
                at = locate(key, ins.address + disp_off)
                if target is None or at is None or target != want(at, True):
                    continue
                f = dict(
                    owner=key,
                    offset=ins.address + disp_off,
                    width=4,
                    location=9,
                    relative=True,
                    frame=("target", None),
                    target=("segment", (body["name"], body["cls"], "")),
                    displacement=ins.address + ins.size,
                    reconstructed=True,
                )
                fx.append(f)
                body["mask"][f["offset"] : f["offset"] + 4] = bytes([1]) * 4
                recovered.append(
                    dict(
                        owner=key,
                        instruction=ins.address,
                        native_target=dst,
                        address=at,
                        target=target,
                        reason="Compilerintern aufgeloester rel32-Verweis ueber eine jetzt getrennte Funktionsgrenze",
                    )
                )
    for key in list(owners):
        for off, names0 in list(unmapped[key].items()):
            values = {v for n in names0 for v in graph_names.get(n, set())}
            if len(values) == 1:
                anchors[key][off] = values.pop()
                del unmapped[key][off]
            elif values:
                raise ValueError("Mehrdeutiger privater Helfer " + str(names0))
            else:
                dropped.append(
                    dict(
                        names=names0,
                        owner=key,
                        offset=off,
                        reason="Kein Verweis aus erhaltenem CODE; privater Zusatz nicht eingebaut",
                    )
                )
        if not anchors[key] and unmapped[key]:
            del owners[key]
    for key, body in owners.items():
        if not anchors[key] or min(set(anchors[key]) | set(unmapped[key])) != 0:
            raise ValueError("Nicht gebundener CODE-Anfang " + str(key))
        starts = sorted(set(anchors[key]) | set(unmapped[key]))
        for i, off in enumerate(starts):
            if off not in anchors[key]:
                continue
            if is_anchor(anchors[key][off]):
                dropped.append(
                    dict(
                        owner=key,
                        offset=off,
                        address=anchors[key][off],
                        reason="Verbucht als HANDASM/Fremdcode; Originalbeitrag bleibt erhalten",
                    )
                )
                continue
            end = starts[i + 1] if i + 1 < len(starts) else len(body["data"])
            kind = "table" if off in tables[key] or off < first[key] else "function"
            if kind == "function":
                end = payload_end(body, off, end)
            else:
                refs = [f for f in fx if tuple(f["owner"]) == key and off <= f["offset"] < end]
                if not refs:
                    raise ValueError("Tabelle ohne belegte Relokation")
                used = max(f["offset"] + f["width"] for f in refs)
                if used < end and not padding(bytes(body["data"][used:end])):
                    raise ValueError("Nicht belegter Tabellenrest")
                end = used
            if end <= off:
                continue
            source_end = starts[i + 1] if i + 1 < len(starts) else len(body["data"])
            address = anchors[key][off]
            bad = [
                j
                for j in range(off, end)
                if not body["mask"][j] and body["data"][j] != IMAGE[address + j - off - 0x10000]
            ]
            if bad:
                raise ValueError(
                    "Compilerbeitrag %06X ab +%X ungleich (%d Bytes)"
                    % (address, bad[0] - off, len(bad))
                )
            chunks.append(
                dict(
                    owner=key,
                    offset=off,
                    end=end,
                    address=address,
                    length=end - off,
                    kind=kind,
                    source_end=source_end,
                    data=bytes(body["data"][off:end]),
                    fixups=[],
                )
            )
    inferred = collections.defaultdict(set)
    for c in chunks:
        for f in fx:
            if tuple(f["owner"]) != c["owner"] or not c["offset"] <= f["offset"] < c["end"]:
                continue
            if f["width"] != 4 or f["location"] not in (9, 13):
                raise ValueError("Nicht belegter Fixuptyp")
            at = c["address"] + f["offset"] - c["offset"]
            value = int.from_bytes(
                c["data"][f["offset"] - c["offset"] : f["offset"] - c["offset"] + 4], "little"
            )
            wanted = want(at, f["relative"])
            add = (value + f["displacement"]) & 0xFFFFFFFF
            if f["target"][0] == "external":
                inferred[f["target"][1]].add((wanted - add) & 0xFFFFFFFF)
            c["fixups"].append(dict(original=f, address=at, value=value, add=add, want=wanted))
    names = {}
    for name, values in inferred.items():
        if len(values) != 1:
            raise ValueError("Mehrere Ziele fuer " + name + ": " + str(values))
        address = next(iter(values))
        known = explicit(name)
        if known is not None and address != known:
            raise ValueError("Explizites Symbol " + name + ": %06X statt %06X" % (known, address))
        names[name] = address
    for c in chunks:
        for f in c["fixups"]:
            target = f["original"]["target"]
            resolved = None
            if target[0] == "external":
                resolved = (names[target[1]] + f["add"]) & 0xFFFFFFFF
            elif target[0] == "segment":
                dst = segment_ids.get(tuple(target[1]))
                if dst in all_bodies:
                    resolved = locate(dst, f["add"])
            if resolved is None:
                raise ValueError("Ungebundenes Segmentziel: " + str(target))
            if resolved != f["want"]:
                raise ValueError(
                    "Relokationsziel %06X: %06X statt %06X" % (f["address"], resolved, f["want"])
                )
            f["target"] = resolved
    for sid, body in obj["segs"].items():
        if body["cls"] != "CODE" and len(body["data"]) and not anchors[("seg", sid)]:
            data_proof.append(
                dict(
                    owner=("seg", sid),
                    length=len(body["data"]),
                    action="Ohne Verweis aus erhaltenem CODE; nicht eingebaut",
                )
            )
    chunks.sort(key=lambda c: c["address"])
    for a, b in zip(chunks, chunks[1:]):
        if a["address"] + a["length"] > b["address"]:
            raise ValueError("Compilerbeitraege ueberlappen nach Adressbindung")
    for i, c in enumerate(chunks):
        body = owners[c["owner"]]
        limit = chunks[i + 1]["address"] if i + 1 < len(chunks) else row["hi"]
        end = c["end"]
        while end < c["source_end"] and c["address"] + end - c["offset"] < limit:
            if body["mask"][end] or body["data"][end] != IMAGE[c["address"] + end - c["offset"] - 0x10000]:
                break
            end += 1
        while end > c["end"] and not padding(bytes(body["data"][c["end"] : end])):
            end -= 1
        c["end"] = end
        c["data"] = bytes(body["data"][c["offset"] : end])
        c["length"] = end - c["offset"]
        c["parts"] = [
            dict(
                owner=c["owner"],
                offset=c["offset"],
                end=end,
                address=c["address"],
                sha256=hashlib.sha256(c["data"]).hexdigest(),
            )
        ]
    merged = []
    boundaries = {0x15689D, 0x15DE10, 0x175FFE}
    for c in chunks:
        if (
            merged
            and merged[-1]["address"] + merged[-1]["length"] == c["address"]
            and c["address"] not in boundaries
        ):
            prev = merged[-1]
            prev["data"] += c["data"]
            prev["length"] += c["length"]
            prev["fixups"] += c["fixups"]
            prev["parts"] += c["parts"]
            prev["kind"] = "joined"
        else:
            merged.append(dict(c))
    return dict(
        unit=row["unit"],
        source=row["source"],
        source_sha256=row["source_sha256"],
        raw=str(path),
        raw_sha256=hashlib.sha256(raw).hexdigest(),
        chunks=merged,
        names=names,
        dropped_comdats=dropped,
        data_bindings=data_proof,
        lidata=lidata,
        reconstructed_rel32=recovered,
    )


def serializable(model):
    return {
        k: (
            [{kk: vv.hex() if kk == "data" else vv for kk, vv in c.items()} for c in v]
            if k == "chunks"
            else v
        )
        for k, v in model.items()
    }
