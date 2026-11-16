from pathlib import Path
import struct
import omf_extra
from r3_reloc import records, idx


def ix(n):
    return bytes([n]) if n < 128 else bytes([128 | (n >> 8), n & 255])


def record(t, b):
    raw = struct.pack("<BH", t, len(b) + 1) + b
    return raw + bytes([-sum(raw) & 255])


def rewrite_fixups(t, b, extmap):
    out = bytearray()
    pos = 0
    while pos < len(b):
        start = pos
        head = b[pos]
        pos += 1
        if not head & 128:
            method = (head >> 2) & (7 if head & 64 else 3)
            if method < 3:
                value, pos = idx(b, pos)
                if method == 2:
                    if value in extmap:
                        out += bytes([head]) + ix(extmap[value])
                else:
                    out += b[start:pos]
            elif method == 3:
                pos += 2
                out += b[start:pos]
            else:
                out += b[start:pos]
            continue
        pos += 1
        desc = b[pos]
        pos += 1
        part = bytearray(b[start:pos])
        if not desc & 128:
            method = (desc >> 4) & 7
            if method < 3:
                value, pos = idx(b, pos)
                part += ix(extmap[value] if method == 2 else value)
            elif method == 3:
                part += b[pos : pos + 2]
                pos += 2
        if not desc & 8:
            method = desc & 3
            if method < 3:
                value, pos = idx(b, pos)
                part += ix(extmap[value] if method == 2 else value)
            else:
                part += b[pos : pos + 2]
                pos += 2
        if not desc & 4:
            width = 4 if t & 1 else 2
            part += b[pos : pos + width]
            pos += width
        out += part
    return bytes(out)


def prune(source, target):
    raw = Path(source).read_bytes()
    before = omf_extra.fixups(raw)
    used = {ref[1] for f in before for ref in (f["frame"], f["target"]) if ref[0] == "external"}
    recs = list(records(raw))
    names = [""]
    entries = {}
    old = 0
    new = 0
    mapping = {}
    for k, (t, b) in enumerate(recs):
        if t in (0x96, 0xCA):
            p = 0
            while p < len(b):
                n = b[p]
                names.append(b[p + 1 : p + 1 + n].decode("latin1"))
                p += n + 1
        if t not in (0x8C, 0xB4, 0xBC):
            continue
        out = bytearray()
        p = 0
        while p < len(b):
            start = p
            if t == 0xBC:
                ni, p = idx(b, p)
                name = names[ni]
            else:
                n = b[p]
                name = b[p + 1 : p + 1 + n].decode("latin1")
                p += n + 1
            _, p = idx(b, p)
            old += 1
            if name in used:
                new += 1
                mapping[old] = new
                out += b[start:p]
        entries[k] = bytes(out)
    result = bytearray()
    for k, (t, b) in enumerate(recs):
        if k in entries:
            b = entries[k]
            if not b:
                continue
        elif t in (0x9C, 0x9D):
            b = rewrite_fixups(t, b, mapping)
            if not b:
                continue
        result += record(t, b)
    after = omf_extra.fixups(result)
    if before != after:
        raise ValueError("Externe-Bereinigung veraendert kanonische Relokationen")
    kinds = {0xA0, 0xA1, 0xA2, 0xA3, 0xC2, 0xC3, 0x90, 0x91, 0xB6, 0xB7}
    if [(t, b) for t, b in recs if t in kinds] != [(t, b) for t, b in records(result) if t in kinds]:
        raise ValueError("Externe-Bereinigung veraendert Code/Daten/Publics")
    Path(target).write_bytes(result)
    return old - new
