from pathlib import Path
from r3_reloc import parse, records, idx
from static_check import lib


def symbols(m):
    m = Path(m)
    global_names = set()
    modules = {}
    for line in (m / "RIVA.LNK").read_text().splitlines():
        if not line.startswith("file "):
            continue
        name = line[5:-4]
        p = m / (name + ".OBJ")
        meta = parse(p)
        local = set()
        extern = set()
        lextern = set()
        ln = [""]
        for typ, b in records(p.read_bytes()):
            if typ in (0x96, 0xCA):
                pos = 0
                while pos < len(b):
                    n = b[pos]
                    ln.append(b[pos + 1 : pos + 1 + n].decode("latin1"))
                    pos += n + 1
            if typ in (0x90, 0x91, 0xB6, 0xB7):
                _, pos = idx(b, 0)
                seg, pos = idx(b, pos)
                if not seg:
                    pos += 2
                while pos < len(b):
                    n = b[pos]
                    s = b[pos + 1 : pos + 1 + n].decode("latin1")
                    pos += n + 1 + (4 if typ & 1 else 2)
                    _, pos = idx(b, pos)
                    (global_names if typ in (0x90, 0x91) else local).add(s)
            elif typ in (0x8C, 0xB4, 0xBC):
                pos = 0
                while pos < len(b):
                    if typ == 0xBC:
                        ni, pos = idx(b, pos)
                        s = ln[ni]
                    else:
                        n = b[pos]
                        s = b[pos + 1 : pos + 1 + n].decode("latin1")
                        pos += n + 1
                    _, pos = idx(b, pos)
                    (lextern if typ == 0xB4 else extern).add(s)
        global_names.update(c["name"] for c in lib["scan"](p)["comdats"])
        modules[name] = dict(meta=meta, local=local, extern=extern, lextern=lextern)
    missing = {n: sorted(x["extern"] - global_names) for n, x in modules.items() if x["extern"] - global_names}
    badlocal = {n: sorted(x["lextern"] - x["local"]) for n, x in modules.items() if x["lextern"] - x["local"]}
    return modules, missing, badlocal
