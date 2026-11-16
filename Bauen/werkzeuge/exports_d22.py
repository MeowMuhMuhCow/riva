from pathlib import Path
import struct
from r3_reloc import parse, records
from static_check import MAP_MODULE


def idx(n):
    return bytes([n]) if n < 128 else bytes([128 | (n >> 8), n & 255])


def rec(typ, body):
    data = struct.pack("<BH", typ, len(body) + 1) + body
    return data + bytes([-sum(data) & 255])


def export(row):
    src = Path(row["prepared"])
    dst = src.with_name("export.OBJ")
    meta = parse(src)
    code = [(i, s) for i, s in meta["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
    if len(code) != 1:
        dst.write_bytes(src.read_bytes())
        return str(dst), []
    seg, body = code[0]
    lo = row["lo"]
    hi = lo + len(body["data"])
    existing = {p[2] for p in meta["pubs"]}
    names = sorted(
        {
            "L%06X" % addr
            for m in MAP_MODULE.values()
            for actual, addr in m["pub"]
            if lo <= addr < hi and addr == actual
        }
        - existing
    )
    out = bytearray()
    for typ, b in records(src.read_bytes()):
        if typ in (0x8A, 0x8B):
            for k in range(0, len(names), 60):
                nb = b"\0" + idx(seg)
                for name in names[k : k + 60]:
                    nb += (
                        bytes([len(name)])
                        + name.encode("ascii")
                        + struct.pack("<I", int(name[1:], 16) - lo)
                        + b"\0"
                    )
                out += rec(0x91, nb)
        out += rec(typ, b)
    dst.write_bytes(out)
    return str(dst), names
