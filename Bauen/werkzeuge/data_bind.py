from pathlib import Path
from object_meta import record
from r3_reloc import idx, parse, records
import omf_extra


def bind(source, target, ren, image, le, lib):
    raw = Path(source).read_bytes()
    meta = parse(source)
    fix = omf_extra.fixups(raw)
    data = {i: s for i, s in meta["segs"].items() if s["cls"] != "CODE" and len(s["data"])}
    if not data:
        return []
    for f in fix:
        if f["owner"][0] != "seg" or f["owner"][1] in data:
            continue
        for t in (f["target"], f["frame"]):
            if t[0] == "segment" and t[1][1] != "CODE":
                raise ValueError("Datenadresse wird segmentintern verwendet: " + str(t))
    proof = []
    referenced = {ref[1] for f in fix for ref in (f["target"], f["frame"]) if ref[0] == "external"}
    for sid, body in data.items():
        pubs = [(o, n) for s, o, n in meta["pubs"] if s == sid]
        if body["name"] == "_BSS" and pubs and not any(body["data"]) and not any(n in referenced for _, n in pubs):
            proof.append(
                dict(
                    segment=body["name"],
                    symbols=[n for _, n in pubs],
                    length=len(body["data"]),
                    reason="Unreferenzierte Null-BSS; keine Initialisierungs- oder Codewirkung",
                )
            )
            continue
        offsets = sorted({o for o, n in pubs})
        if not offsets or offsets[0] != 0:
            raise ValueError("Datenbeitrag ohne vollstaendige benannte Anfangsdefinition: " + body["name"])
        for k, off in enumerate(offsets):
            end = offsets[k + 1] if k + 1 < len(offsets) else len(body["data"])
            ns = [n for o, n in pubs if o == off]
            addresses = {int(ren[n][1:], 16) for n in ns if n in ren}
            if len(addresses) != 1 or any(n not in ren for n in ns):
                raise ValueError("Originaldatenadresse nicht eindeutig: " + str(ns))
            address = addresses.pop()
            if address < 0x1A0000 or address + end - off > 0x10000 + len(image):
                raise ValueError("Datendefinition ausserhalb Original-DGROUP: " + str(ns))
            mask = set()
            for f in fix:
                if tuple(f["owner"]) != ("seg", sid) or not off <= f["offset"] < end:
                    continue
                pos = address + f["offset"] - off
                if f["relative"] or f["width"] != 4 or f["location"] not in (9, 13) or pos not in le:
                    raise ValueError("Nicht belegte Datenrelokation bei %06X" % pos)
                target_ref = f["target"]
                if target_ref[0] != "external" or target_ref[1] not in ren:
                    raise ValueError("Dateninitialisierung mit unaufgeloestem Ziel " + str(target_ref))
                value = (
                    int(ren[target_ref[1]][1:], 16)
                    + f["displacement"]
                    + int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little")
                ) & 0xFFFFFFFF
                if le[pos] != (7, value):
                    raise ValueError("Dateninitialisierung falsches Ziel bei %06X" % pos)
                mask.update(range(f["offset"], f["offset"] + 4))
            bad = [i for i in range(off, end) if i not in mask and body["data"][i] != image[address + i - off - 0x10000]]
            if bad:
                raise ValueError("Dateninitialisierung weicht ab: %s bei %06X" % (ns, address + bad[0] - off))
            proof.append(dict(segment=body["name"], symbols=ns, address=address, length=end - off))
    bound_names = {n for p in proof if "address" in p for n in p["symbols"]}
    out = bytearray()
    sid = 0
    last_data = False
    for typ, b in records(raw):
        if typ == 0xB4:
            pos = 0
            while pos < len(b):
                start = pos
                size = b[pos]
                name = b[pos + 1 : pos + 1 + size].decode("latin1")
                pos += 1 + size
                _, pos = idx(b, pos)
                out += record(0x8C if name in bound_names else typ, b[start:pos])
            continue
        if typ in (0x98, 0x99):
            sid += 1
            if sid in data:
                pos = 1 + (3 if b[0] >> 5 == 0 else 0)
                width = 4 if typ & 1 else 2
                b = b[:pos] + bytes(width) + b[pos + width :]
        elif typ in (0xA0, 0xA1, 0xA2, 0xA3):
            s, _ = idx(b, 0)
            last_data = s in data
            if last_data:
                continue
        elif typ in (0xC2, 0xC3):
            last_data = False
        elif typ in (0x90, 0x91, 0xB6, 0xB7):
            _, pos = idx(b, 0)
            s, _ = idx(b, pos)
            if s in data:
                continue
        elif typ in (0x9C, 0x9D) and last_data:
            b = b"".join(part for thread, part in lib["fixparts"](typ, b) if thread)
            if not b:
                continue
        out += record(typ, b)
    before = [f for f in fix if not (f["owner"][0] == "seg" and f["owner"][1] in data)]
    after = omf_extra.fixups(out)
    if before != after:
        raise ValueError("Datenbindung veraendert erhaltene Relokationen")
    Path(target).write_bytes(out)
    return proof
