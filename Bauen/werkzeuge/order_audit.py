import collections
from pathlib import Path
import struct
import omf_extra
import r3_reloc
from static_check import ORIG_EXE_BYTES, lib
from wlrule import simulate


def expected():
    raw = bytes(ORIG_EXE_BYTES[0x38D64:])
    le = struct.unpack_from("<I", raw, 0x3C)[0]
    u = lambda off: struct.unpack_from("<I", raw, le + off)[0]
    pages = []
    size = {}
    records = {}
    objects = [struct.unpack_from("<6I", raw, le + u(0x40) + i * 24) for i in range(u(0x44))]
    for pg in range(u(0x14)):
        obj = next(o for o in objects if o[3] - 1 <= pg < o[3] - 1 + o[4])
        if obj[1] != 0x10000:
            break
        pb = obj[1] + (pg - (obj[3] - 1)) * 4096
        a, b = struct.unpack_from("<II", raw, le + u(0x68) + pg * 4)
        pos = le + u(0x6C) + a
        end = le + u(0x6C) + b
        out = []
        while pos < end:
            start = pos
            st, fl = raw[pos : pos + 2]
            pos += 2
            if st & 32:
                raise ValueError("Original-Quellliste noch nicht modelliert")
            so = struct.unpack_from("<h", raw, pos)[0]
            pos += 2
            pos += 2 if fl & 64 else 1
            if st & 15 != 2:
                pos += 4 if fl & 16 else 2
            addr = pb + so
            out.append(addr)
            size[(pg, addr)] = pos - start
            records[(pg, addr)] = raw[start:pos].hex()
        pages.append(out)
    return pages, size, records


def layout(m):
    m = Path(m)
    files = [l[5:-4] for l in (m / "RIVA.LNK").read_text().splitlines() if l.startswith("file ")]
    cd_models = {}
    for f in files:
        po = m / (f + ".OBJ")
        if po.exists() and lib["code_comdats"](str(po)):
            cd_models[f] = str(po)
    segs = {}
    ord_s = []
    lay = {}
    for f in files:
        po = m / (f + ".OBJ")
        if not po.exists():
            continue
        cs = [(x[0], x[2], x[3]) for x in lib["segdefs"](str(po)) if x[1] == "CODE"]
        if not cs:
            continue
        haupt = next((c[0] for c in cs if c[1] > 0), cs[0][0])
        for sn, L, al in cs:
            if sn not in segs:
                segs[sn] = []
                ord_s.append(sn)
            segs[sn].append((f, L, al, sn == haupt))
    code = 0x10000
    for sn in ord_s:
        seg_align = max(x[2] for x in segs[sn])
        code = (code + seg_align - 1) // seg_align * seg_align
        seg_base = code
        for f, L, al, haupt in segs[sn]:
            if al > 1:
                code = seg_base + ((code - seg_base + al - 1) // al * al)
            if haupt and f in cd_models:
                _, cb = lib["layout"](cd_models[f], code)
                L = cb[-1]["address"] + len(cb[-1]["data"]) - code
            if haupt:
                lay[f] = (code, code + L)
            code += L
    return {f: lay[f] for f in files if f in lay}


def stream(m):
    m = Path(m)
    lay = layout(m)
    rows = []
    files = [l[5:-4] for l in (m / "RIVA.LNK").read_text().splitlines() if l.startswith("file ")]
    for name in files:
        if name not in lay or lay[name][0] == lay[name][1]:
            continue
        p = m / (name + ".OBJ")
        if not p.exists():
            raise ValueError("OBJ fehlt: " + name)
        meta = r3_reloc.parse(p)
        active = [(i, s) for i, s in meta["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
        if len(active) > 1:
            raise ValueError("Mehrere aktive Codesegmente: " + name)
        base = lay[name][0]
        for f in meta["fix"]:
            if meta["segs"][f["seg"]]["cls"] == "CODE" and not f["relative"]:
                rows.append(
                    dict(
                        address=base + f["off"],
                        module=name,
                        segment=meta["segs"][f["seg"]]["name"],
                    )
                )
        if "COMDAT" in meta["unknown"]:
            _, blocks = lib["layout"](p, base)
            cds = {b["name"]: b["address"] for b in blocks if b["kind"] == "COMDAT"}
            for f in omf_extra.fixups(p.read_bytes()):
                if f["owner"][0] == "comdat" and f["owner"][1] in cds and not f["relative"]:
                    rows.append(
                        dict(
                            address=cds[f["owner"][1]] + f["offset"],
                            module=name,
                            segment="_TEXT",
                        )
                    )
    return rows


def audit(m, capacities=None):
    orig, size, _ = expected()
    rows = stream(m)
    wanted = set(a for pg in orig for a in pg)
    actual = {r["address"] for r in rows}
    missing = sorted(wanted - actual)
    extra = sorted(actual - wanted)
    incoming = [[] for _ in orig]
    membership = collections.defaultdict(list)
    for pg, seq in enumerate(orig):
        for a in seq:
            membership[a].append(pg)
    for r in rows:
        for pg in membership[r["address"]]:
            incoming[pg].append(r["address"])
    results = []
    for capacity in capacities or (128, 256, 512, 1024, 2048, 4096):
        bad = []
        for pg, (got, want) in enumerate(zip(incoming, orig)):
            predicted = simulate(got, {a: size[(pg, a)] for a in got}, capacity)
            if predicted != want:
                bad.append(pg)
        results.append(dict(capacity=capacity, bad_pages=bad, count=len(bad)))
    return dict(
        directory=str(m),
        missing=missing,
        extra=extra,
        results=results,
        rows=len(rows),
        pages=len(orig),
    )
