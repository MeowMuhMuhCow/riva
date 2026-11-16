import struct


def page_entries(fn, L=0x2C90):
    with open(fn, "rb") as f:
        d = f.read()
    fp = struct.unpack_from("<I", d, L + 0x68)[0] + L
    fr = struct.unpack_from("<I", d, L + 0x6C)[0] + L
    res = []
    for pg in range(427):
        a, b = struct.unpack_from("<II", d, fp + 4 * pg)
        i = fr + a
        e = fr + b
        pb = 0x10000 + pg * 4096 if pg < 398 else 0x1A0000 + (pg - 398) * 4096
        lst = []
        while i < e:
            j = i
            st = d[i]
            fl = d[i + 1]
            i += 2
            so = struct.unpack_from("<h", d, i)[0]
            i += 2
            i += 1 if not fl & 0x40 else 2
            if (st & 0xF) != 2:
                i += 4 if fl & 0x10 else 2
            lst.append((pb + so, i - j))
        res.append(lst)
    return res


def simulate(order, size, C):
    blocks = [[]]
    used = 0
    for x in order:
        s = size[x]
        if used + s > C:
            blocks.append([])
            used = 0
        blocks[-1].append(x)
        used += s
    out = []
    for b in reversed(blocks):
        out += b
    return out
