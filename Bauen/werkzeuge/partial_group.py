from fragment_model import *
from order_audit import layout, stream, audit, expected as original_pages
import heapq
from inverse_blocks import inverse

BASE_STREAM_CACHE = {}


def subtract(a, b, intervals):
    at = a
    for x, y in sorted(intervals):
        if y <= at or x >= b:
            continue
        if x > at:
            yield at, min(x, b)
        at = max(at, y)
    if at < b:
        yield at, b


def native_pieces(staged, lo, hi):
    out = []
    for row in staged:
        used = {c["name"] for c in row["chunks"]}
        md = row["model"]
        for c in md["chunks"]:
            if "N%06X" % c["address"] not in used:
                continue
            if c["address"] >= hi or c["address"] + c["length"] <= lo:
                continue
            if not lo <= c["address"] < c["address"] + c["length"] <= hi:
                raise ValueError("Native Modulgrenze ueberlappt")
            raw = bytes.fromhex(c["data"])
            for part in c["parts"]:
                a = part["address"]
                n = part["end"] - part["offset"]
                body = raw[a - c["address"] : a - c["address"] + n]
                assert hashlib.sha256(body).hexdigest() == part["sha256"]
                out.append(
                    dict(
                        address=a,
                        data=body,
                        fixups=[f for f in c["fixups"] if a <= f["address"] < a + n],
                        cpp=True,
                        source=md["source"],
                        source_sha256=md["source_sha256"],
                        raw=md["raw"],
                        raw_sha256=md["raw_sha256"],
                        part=part,
                    )
                )
    return out


def make_group(base, m, name, lo, hi, staged, dest, basenames=None):
    pieces = native_pieces(staged, lo, hi)
    intervals = [(c["address"], c["address"] + len(c["data"])) for c in pieces]
    basenames = basenames or ([name] if name != "SPELL" else ["SPELL", "SPELL3"])
    base_layout = layout(base)
    ff = []
    for basename in basenames:
        baselo, basehi = base_layout[basename]
        raw = (base / (basename + ".OBJ")).read_bytes()
        obj = lib["omf"].modules(str(base / (basename + ".OBJ")))[0]
        active = [(i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
        assert len(active) == 1 and not obj["comdats"]
        sid, body = active[0]
        assert len(body["data"]) == basehi - baselo
        assert not any(s["data"] for s in obj["segs"].values() if s["cls"] != "CODE")
        labels = {
            baselo + o for sid0, o, n in r3_reloc.parse(base / (basename + ".OBJ"))["pubs"] if sid0 == sid
        }
        fx = omf_extra.fixups(raw)
        baseff = []
        for f in fx:
            assert f["owner"] == ("seg", sid) and (
                (f["width"] == 4 and f["location"] in (9, 13))
                or (f["width"] == 6 and f["location"] == 11 and not f["relative"])
            )
            at = baselo + f["offset"]
            val = int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little")
            add = (val + f["displacement"]) & 0xFFFFFFFF
            target = f["target"]
            if target[0] == "external":
                resolved = (int(target[1][1:], 16) + add) & 0xFFFFFFFF
                assert target[1].startswith("L")
            elif target[0] == "segment":
                resolved = baselo + add
            else:
                raise ValueError("Unbelegtes ASM-Ziel " + str(target))
            expected_target = (
                LE[at][1] if f["width"] == 6 and LE.get(at, (None,))[0] == 6 else want(at, f["relative"])
            )
            assert resolved == expected_target, (hex(at), resolved, expected_target)
            baseff.append(
                dict(original=f, address=at, value=val, add=add, want=resolved, target=resolved)
            )
        ff += baseff
        for typ, b in r3_reloc.records(raw):
            if typ not in (0xA0, 0xA1):
                continue
            sn, j = r3_reloc.idx(b, 0)
            w = 4 if typ & 1 else 2
            off = int.from_bytes(b[j : j + w], "little")
            data = b[j + w :]
            assert sn == sid
            for left, right in subtract(baselo + off, baselo + off + len(data), intervals):
                cuts = [left] + sorted(x for x in labels if left < x < right) + [right]
                for a, z in zip(cuts, cuts[1:]):
                    assert (base / (basename + ".ASM")).exists(), "C++-Beitrag ausserhalb der belegten Fragmente"
                    refs = [f for f in baseff if a <= f["address"] < z]
                    assert all(f["address"] + f["original"]["width"] <= z for f in refs)
                    pieces.append(
                        dict(
                            address=a,
                            data=data[a - baselo - off : z - baselo - off],
                            fixups=refs,
                            cpp=False,
                            source=basename + ".ASM",
                            raw_sha256=hashlib.sha256(raw).hexdigest(),
                        )
                    )
    pieces.sort(key=lambda c: c["address"])
    at = lo
    owner = {}
    for i, c in enumerate(pieces):
        assert c["address"] == at, ("Luecke/Overlap", hex(at), hex(c["address"]))
        at += len(c["data"])
        for f in c["fixups"]:
            assert f["address"] not in owner
            owner[f["address"]] = i
    assert at == hi
    expected = [f["address"] for f in ff if not f["original"]["relative"]]
    actual = {f["address"] for c in pieces for f in c["fixups"] if not f["original"]["relative"]}
    assert set(expected) == actual
    edges = {i: set() for i in range(len(pieces))}
    degree = [0] * len(pieces)
    for i, c in enumerate(pieces):
        seq = [f["address"] for f in c["fixups"] if not f["original"]["relative"]]
        assert set(seq) == {a for a in expected if owner[a] == i}
    pages, sizes, _ = original_pages()
    streams = []
    block_choices = []
    key = str(base)
    if key not in BASE_STREAM_CACHE:
        BASE_STREAM_CACHE[key] = stream(base)
    global_rows = BASE_STREAM_CACHE[key]
    for pg_idx, page in enumerate(pages):
        if not any(lo <= a < hi for a in page):
            continue
        wanted = set(page)
        before = [r["address"] for r in global_rows if r["address"] in wanted]
        candidates = [before]

        def fits(candidate):
            outsiders = [a for a in candidate if a not in owner]
            if outsiders != [a for a in before if a not in owner]:
                return False
            signature = lambda seq: [a if a not in owner else "GROUP" for a in seq]

            def compact(seq):
                out = []
                for a in signature(seq):
                    if a != "GROUP" or not out or out[-1] != "GROUP":
                        out.append(a)
                return out

            if compact(candidate) != compact(before):
                return False
            groups = []
            for a in candidate:
                if a not in owner:
                    continue
                v = owner[a]
                if not groups or groups[-1] != v:
                    groups.append(v)
            if len(groups) != len(set(groups)):
                return False
            for i in groups:
                own = [
                    f["address"]
                    for f in pieces[i]["fixups"]
                    if not f["original"]["relative"] and f["address"] in wanted
                ]
                if own != [a for a in candidate if owner.get(a) == i]:
                    return False
            return True

        if not fits(before):
            candidates += inverse(page, {a: sizes[(pg_idx, a)] for a in page})
        choices = [c for c in candidates if fits(c)]
        if not choices:
            raise ValueError("Keine ganze Beitragsfolge fuer Seite %d" % pg_idx)
        chosen = choices[0]
        sequence = [a for a in chosen if a in owner]
        streams.append(sequence)
        if chosen != before:
            block_choices.append(
                dict(
                    page=pg_idx,
                    reason="Mehrdeutige Umkehrung der 512-Byte-Blockliste; ganze Funktionen bleiben zusammen",
                    input=chosen,
                )
            )
        for a, b in zip(sequence, sequence[1:]):
            x, y = owner[a], owner[b]
            if x != y and y not in edges[x]:
                edges[x].add(y)
                degree[y] += 1
    ready = [i for i, d in enumerate(degree) if not d]
    heapq.heapify(ready)
    order = []
    while ready:
        i = heapq.heappop(ready)
        order.append(i)
        for j in edges[i]:
            degree[j] -= 1
            if not degree[j]:
                heapq.heappush(ready, j)
    assert len(order) == len(pieces), ("Zyklus", name, [hex(pieces[i]["address"]) for i, d in enumerate(degree) if d])
    outname = "B%06X" % lo
    source = ("D22 partial link " + name + ".OBJ").encode()
    seg = body["name"]
    out = bytearray(record(0x80, bytes([len(source)]) + source))
    out += record(0x96, b"\0" + bytes([len(seg)]) + seg.encode() + b"\x04CODE")
    out += record(0x99, b"\x29" + struct.pack("<I", hi - lo) + b"\x02\x03\x01")
    targets = sorted({f["target"] for c in pieces for f in c["fixups"]})
    ext = {a: i + 1 for i, a in enumerate(targets)}
    for k in range(0, len(targets), 70):
        out += record(0x8C, b"".join(b"\x07" + ("L%06X" % a).encode() + b"\0" for a in targets[k : k + 70]))
    current = layout(m)
    inputs = [n for n, (a, b) in current.items() if a < hi and b > lo and a < b]
    pubs = set()
    for n in inputs:
        a, z = current[n]
        assert lo <= a < z <= hi
        for s, off, nm in r3_reloc.parse(m / (n + ".OBJ"))["pubs"]:
            assert nm == "L%06X" % (a + off), (n, nm, hex(a + off))
            pubs.add(a + off)
    pubs.update(a for a in targets if lo <= a < hi)
    labels = sorted(pubs)
    for k in range(0, len(labels), 40):
        out += record(
            0x91,
            b"\0\x01"
            + b"".join(
                b"\x07" + ("L%06X" % a).encode() + struct.pack("<I", a - lo) + b"\0"
                for a in labels[k : k + 40]
            ),
        )
    for i in order:
        c = pieces[i]
        pos = 0
        while pos < len(c["data"]):
            end = min(pos + 1000, len(c["data"]))
            for f in c["fixups"]:
                off = f["address"] - c["address"]
                if off < end < off + f["original"]["width"]:
                    end = off
            out += record(0xA1, b"\x01" + struct.pack("<I", c["address"] - lo + pos) + c["data"][pos:end])
            parts = []
            for f in c["fixups"]:
                off = f["address"] - c["address"] - pos
                if not 0 <= off < end - pos:
                    continue
                old = f["original"]
                head = 0x80 | (0 if old["relative"] else 0x40) | (old["location"] << 2) | (off >> 8)
                parts.append(
                    bytes([head, off & 255, 0x52])
                    + ix(ext[f["target"]])
                    + struct.pack("<I", (-f["value"]) & 0xFFFFFFFF)
                )
            if parts:
                out += record(0x9D, b"".join(parts))
            pos = end
    out += record(0x8A, b"\0")
    dest = Path(dest)
    dest.mkdir(exist_ok=True)
    path = dest / (outname + ".OBJ")
    path.write_bytes(out)
    parsed = r3_reloc.parse(path)
    for c in pieces:
        off = c["address"] - lo
        assert parsed["segs"][1]["data"][off : off + len(c["data"])] == c["data"]
    seq = [lo + f["off"] for f in parsed["fix"] if not f["relative"]]
    for sequence in streams:
        assert [a for a in seq if a in set(sequence)] == sequence
    proof = dict(
        name=outname,
        base_module=name,
        base_modules=basenames,
        block_choices=block_choices,
        lo=lo,
        hi=hi,
        inputs=inputs,
        sha256=hashlib.sha256(out).hexdigest(),
        order=[pieces[i]["address"] for i in order],
        spans=[
            {k: v for k, v in c.items() if k not in ("data", "fixups")}
            | dict(hi=c["address"] + len(c["data"]), payload_sha256=hashlib.sha256(c["data"]).hexdigest())
            for c in pieces
        ],
    )
    return path, proof
