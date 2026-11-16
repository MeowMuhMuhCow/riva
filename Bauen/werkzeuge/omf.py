import struct

LOCSZ = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 11: 6, 13: 4}


def idx(b, i):
    if b[i] & 0x80:
        return ((b[i] & 0x7F) << 8) | b[i + 1], i + 2
    return b[i], i + 1


def modules(path):
    with open(path, "rb") as f:
        d = f.read()
    i = 0
    mods = []
    if d[0] == 0xF0:
        psz = struct.unpack("<H", d[1:3])[0] + 3
        i = psz
    else:
        psz = None
    while i < len(d):
        t = d[i]
        if t == 0xF1:
            break
        if t != 0x80:
            i += 1
            continue
        m = parse(d, i)
        mods.append(m)
        i = m["end"]
        if psz:
            i = ((i + psz - 1) // psz) * psz
    return mods


def parse(d, i):
    lnames = [""]
    segs = [None]
    m = {"name": "", "segs": {}, "end": 0, "comdats": []}
    last = None
    while True:
        t = d[i]
        l = struct.unpack("<H", d[i + 1 : i + 3])[0]
        c = d[i + 3 : i + 3 + l - 1]
        i += 3 + l
        if t == 0x80:
            m["name"] = c[1 : 1 + c[0]].decode("latin1")
        elif t == 0x96:
            j = 0
            while j < len(c):
                n = c[j]
                lnames.append(c[j + 1 : j + 1 + n].decode("latin1"))
                j += 1 + n
        elif t in (0x98, 0x99):
            acbp = c[0]
            j = 1
            if (acbp >> 5) == 0:
                j += 3
            if t == 0x99:
                ln = struct.unpack("<I", c[j : j + 4])[0]
                j += 4
            else:
                ln = struct.unpack("<H", c[j : j + 2])[0]
                j += 2
            sn, j = idx(c, j)
            cn, j = idx(c, j)
            segs.append((lnames[sn], lnames[cn], ln))
            m["segs"][len(segs) - 1] = {
                "name": lnames[sn],
                "cls": lnames[cn],
                "data": bytearray(ln),
                "mask": bytearray(ln),
                "has": bytearray(ln),
            }
        elif t in (0xA0, 0xA1):
            s, j = idx(c, 0)
            if t == 0xA1:
                off = struct.unpack("<I", c[j : j + 4])[0]
                j += 4
            else:
                off = struct.unpack("<H", c[j : j + 2])[0]
                j += 2
            data = c[j:]
            S = m["segs"][s]
            if off + len(data) > len(S["data"]):
                ext = off + len(data) - len(S["data"])
                S["data"] += bytearray(ext)
                S["mask"] += bytearray(ext)
                S["has"] += bytearray(ext)
            S["data"][off : off + len(data)] = data
            for k in range(len(data)):
                S["has"][off + k] = 1
            last = ("seg", S, off)
        elif t in (0xC2, 0xC3):
            fl = c[0]
            attr = c[1]
            j = 3
            if t == 0xC3:
                off = struct.unpack("<I", c[j : j + 4])[0]
                j += 4
            else:
                off = struct.unpack("<H", c[j : j + 2])[0]
                j += 2
            _, j = idx(c, j)
            if (attr & 0x0F) == 0:
                g, j = idx(c, j)
                s, j = idx(c, j)
                if g == 0 and s == 0:
                    j += 2
            else:
                s = None
            ni, j = idx(c, j)
            data = c[j:]
            name = lnames[ni] if ni < len(lnames) else "?"
            cd = None
            for x in m["comdats"]:
                if x["name"] == name and (fl & 1):
                    cd = x
            if cd is None:
                cd = {
                    "name": name,
                    "seg": s,
                    "attr": attr,
                    "data": bytearray(),
                    "mask": bytearray(),
                    "has": bytearray(),
                }
                m["comdats"].append(cd)
            need = off + len(data)
            if need > len(cd["data"]):
                ext = need - len(cd["data"])
                cd["data"] += bytearray(ext)
                cd["mask"] += bytearray(ext)
                cd["has"] += bytearray(ext)
            cd["data"][off : off + len(data)] = data
            for k in range(len(data)):
                cd["has"][off + k] = 1
            last = ("cd", cd, off)
        elif t in (0x9C, 0x9D):
            j = 0
            while j < len(c):
                b = c[j]
                if not b & 0x80:
                    meth = (b >> 2) & 7
                    D = b & 0x40
                    j += 1
                    if D:
                        if meth < 3:
                            _, j = idx(c, j)
                        elif meth == 3:
                            j += 2
                    else:
                        if meth in (0, 1, 2):
                            _, j = idx(c, j)
                        elif meth == 3:
                            j += 2
                    continue
                loc = (b >> 2) & 0xF
                doff = ((b & 3) << 8) | c[j + 1]
                j += 2
                fd = c[j]
                j += 1
                F = fd & 0x80
                fm = (fd >> 4) & 7
                T = fd & 8
                P = fd & 4
                tm = fd & 3
                if not F:
                    if fm < 3:
                        _, j = idx(c, j)
                    elif fm == 3:
                        j += 2
                if not T:
                    if tm < 3:
                        _, j = idx(c, j)
                    else:
                        j += 2
                if not P:
                    j += 4 if t == 0x9D else 2
                if last:
                    obj = last[1]
                    o = last[2] + doff
                    for k in range(LOCSZ.get(loc, 4)):
                        if o + k < len(obj["mask"]):
                            obj["mask"][o + k] = 1
        elif t in (0x8A, 0x8B):
            m["end"] = i
            return m
