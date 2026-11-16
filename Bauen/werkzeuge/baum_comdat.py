import partial_group as pg


def existing(path, lo, hi, intervals, retain, allowed):
    raw = path.read_bytes()
    obj = pg.lib["omf"].modules(str(path))[0]
    assert obj["comdats"]
    assert not any(s["data"] for s in obj["segs"].values() if s["cls"] != "CODE")
    _, blocks = pg.lib["layout"](path, lo)
    active = [(i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and s["data"]]
    assert len(active) == 1
    sid = active[0][0]
    owners = {("seg", sid): next(b for b in blocks if b["kind"] == "TEXT")}
    pubs = set()
    for b in blocks:
        if b["kind"] == "COMDAT":
            assert b["name"] == "L%06X" % b["address"]
            owners[("comdat", b["name"])] = b
            pubs.add(b["address"])
    assert blocks[0]["address"] == lo
    assert blocks[-1]["address"] + len(blocks[-1]["data"]) == hi
    fixes = []
    for f in pg.omf_extra.fixups(raw):
        b = owners[f["owner"]]
        assert f["width"] == 4 and f["location"] in (9, 13)
        at = b["address"] + f["offset"]
        value = int.from_bytes(b["data"][f["offset"] : f["offset"] + 4], "little")
        add = (value + f["displacement"]) & 0xFFFFFFFF
        target = f["target"]
        if target[0] == "external":
            assert target[1].startswith("L")
            resolved = (int(target[1][1:], 16) + add) & 0xFFFFFFFF
        else:
            assert target == ("segment", sid)
            resolved = lo + add
        assert resolved == pg.want(at, f["relative"]), (path.name, hex(at))
        fixes.append(
            dict(original=f, address=at, value=value, add=add, want=resolved, target=resolved)
        )
    saved = []
    for b in blocks:
        a = b["address"]
        for left, right in pg.subtract(a, a + len(b["data"]), intervals):
            cuts = (
                [left]
                + sorted({x for g in allowed for x in (g["lo"], g["hi"]) if left < x < right})
                + [right]
            )
            for x, y in zip(cuts, cuts[1:]):
                refs = [f for f in fixes if x <= f["address"] < y]
                assert all(f["address"] + f["original"]["width"] <= y for f in refs)
                piece = retain(path.stem, lo, sid, x, y, bytes(b["data"][x - a : y - a]), refs, raw)
                if b["kind"] == "NULL":
                    assert not refs and not any(piece["data"])
                    piece["saved_linker_parent"] = piece.pop("saved_asm_raw")
                    piece.pop("asm_segment")
                    piece.pop("asm_offset")
                    piece["source"] = "Bestehende Linkerausrichtung zwischen CODE/COMDAT: " + path.name
                    piece["linker_padding"] = dict(
                        parent_lo=lo, block_lo=a, block_hi=a + len(b["data"]), kind="NULL"
                    )
                saved.append(piece)
    return fixes, saved, pubs
