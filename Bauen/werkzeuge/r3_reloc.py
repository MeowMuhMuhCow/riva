import bisect
import json
import os
import re
import struct
from pathlib import Path


def atomic(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + ".r3tmp." + str(os.getpid()))
    temp.write_bytes(data)
    os.replace(temp, path)


class Fixups(dict):
    def freeze(self):
        self.addresses = sorted(self)

    def within(self, lo, hi):
        a = bisect.bisect_left(self.addresses, lo)
        b = bisect.bisect_left(self.addresses, hi)
        return ((k, self[k]) for k in self.addresses[a:b])


def records(data):
    i = 0
    while i < len(data):
        if i + 3 > len(data):
            raise ValueError("OMF abgeschnitten")
        t, n = struct.unpack_from("<BH", data, i)
        if n < 1 or i + 3 + n > len(data):
            raise ValueError("OMF-Satzlaenge")
        rec = data[i : i + 3 + n]
        if rec[-1] and sum(rec) & 255:
            raise ValueError("OMF-Pruefsumme")
        yield t, rec[3:-1]
        i += 3 + n


def idx(b, j):
    if b[j] & 128:
        return ((b[j] & 127) << 8) | b[j + 1], j + 2
    return b[j], j + 1


def parse(path):
    names = [""]
    ext = [""]
    segs = {}
    pubs = []
    fix = []
    ft = {}
    tt = {}
    last = None
    unknown = []
    for t, b in records(Path(path).read_bytes()):
        if t == 0x96:
            j = 0
            while j < len(b):
                n = b[j]
                names.append(b[j + 1 : j + 1 + n].decode("latin1"))
                j += 1 + n
        elif t in (0x98, 0x99):
            j = 1 + (3 if b[0] >> 5 == 0 else 0)
            w = 4 if t & 1 else 2
            n = int.from_bytes(b[j : j + w], "little")
            sn, j = idx(b, j + w)
            cn, j = idx(b, j)
            segs[len(segs) + 1] = dict(name=names[sn], cls=names[cn], data=bytearray(n))
        elif t in (0x8C, 0xB4):
            j = 0
            while j < len(b):
                n = b[j]
                ext.append(b[j + 1 : j + 1 + n].decode("latin1"))
                _, j = idx(b, j + 1 + n)
        elif t == 0xBC:
            j = 0
            while j < len(b):
                ni, j = idx(b, j)
                _, j = idx(b, j)
                ext.append(names[ni])
        elif t in (0x90, 0x91, 0xB6, 0xB7):
            _, j = idx(b, 0)
            s, j = idx(b, j)
            if s == 0:
                j += 2
            while j < len(b):
                n = b[j]
                nm = b[j + 1 : j + 1 + n].decode("latin1")
                j += 1 + n
                w = 4 if t & 1 else 2
                off = int.from_bytes(b[j : j + w], "little")
                _, j = idx(b, j + w)
                pubs.append((s, off, nm))
        elif t in (0xA0, 0xA1):
            s, j = idx(b, 0)
            w = 4 if t & 1 else 2
            off = int.from_bytes(b[j : j + w], "little")
            data = b[j + w :]
            segs[s]["data"][off : off + len(data)] = data
            last = (s, off)
        elif t in (0xA2, 0xA3):
            last = None
            unknown.append("LIDATA")
        elif t in (0xC2, 0xC3):
            last = None
            unknown.append("COMDAT")
        elif t in (0x9C, 0x9D):
            j = 0

            def datum(m, j):
                if m < 3:
                    return idx(b, j)
                if m == 3:
                    return int.from_bytes(b[j : j + 2], "little"), j + 2
                return None, j

            while j < len(b):
                head = b[j]
                j += 1
                if not head & 128:
                    m = (head >> 2) & 7
                    v, j = datum(m, j)
                    (ft if head & 64 else tt)[head & 3] = (m, v)
                    continue
                loc = (head >> 2) & 15
                off = ((head & 3) << 8) | b[j]
                desc = b[j + 1]
                j += 2
                if desc & 128:
                    frame = ft.get((desc >> 4) & 3, (None, None))
                else:
                    fm = (desc >> 4) & 7
                    fv, j = datum(fm, j)
                    frame = (fm, fv)
                if desc & 8:
                    m, v = tt.get(desc & 3, (None, None))
                else:
                    m = desc & 3
                    v, j = datum(m, j)
                disp = 0
                if not desc & 4:
                    w = 4 if t & 1 else 2
                    disp = int.from_bytes(b[j : j + w], "little")
                    j += w
                if last:
                    fix.append(
                        dict(
                            seg=last[0],
                            off=last[1] + off,
                            loc=loc,
                            relative=not bool(head & 64),
                            method=m,
                            value=v,
                            disp=disp,
                            frame=frame,
                            external=ext[v] if m == 2 and v and v < len(ext) else None,
                        )
                    )
                else:
                    unknown.append("FIXUPP ausserhalb LEDATA")
    return dict(segs=segs, pubs=sorted(set(pubs)), ext=ext, fix=fix, unknown=sorted(set(unknown)))


def original_fixups(exe_bytes):
    start = exe_bytes.find(b"LE\0\0", 0x30000)
    if start < 0:
        raise ValueError("LE-Header fehlt in Original/RIVA.EXE")
    u = lambda off: struct.unpack_from("<I", exe_bytes, start + off)[0]
    objects = [struct.unpack_from("<6I", exe_bytes, start + u(0x40) + 24 * i) for i in range(u(0x44))]
    table, base = start + u(0x68), start + u(0x6C)
    result = []
    for page in range(u(0x14)):
        first, end = struct.unpack_from("<II", exe_bytes, table + 4 * page)
        owner = next(o for o in objects if o[3] - 1 <= page < o[3] - 1 + o[4])
        address = owner[1] + (page - (owner[3] - 1)) * 4096
        pos = base + first
        while pos < base + end:
            typ, flags = exe_bytes[pos], exe_bytes[pos + 1]
            pos += 2
            if typ & 0x20:
                count = exe_bytes[pos]
                pos += 1
            else:
                offset = struct.unpack_from("<h", exe_bytes, pos)[0]
                pos += 2
            width = 2 if flags & 0x40 else 1
            target_obj = int.from_bytes(exe_bytes[pos : pos + width], "little")
            pos += width
            target = 0
            if typ & 15 != 2:
                width = 4 if flags & 0x10 else 2
                target = int.from_bytes(exe_bytes[pos : pos + width], "little")
                pos += width
            dest = objects[target_obj - 1][1] + target
            if typ & 0x20:
                for _ in range(count):
                    offset = struct.unpack_from("<h", exe_bytes, pos)[0]
                    pos += 2
                    result.append((address + offset, typ & 15, dest))
            else:
                result.append((address + offset, typ & 15, dest))
    return result


def build_flat_image(exe_bytes):
    """Rekonstruiert das flache Speicherabbild (riva_flat.bin, 0x1c7d40 Bytes ab 0x10000)
    direkt im Speicher aus Original/RIVA.EXE."""
    le = exe_bytes[0x38D64:]
    hdr = struct.unpack_from("<I", le, 0x3C)[0]
    u = lambda off: struct.unpack_from("<I", le, hdr + off)[0]
    data_off = u(0x80)
    flat = bytearray(0x1C7D40)
    flat[0:0x18D630] = le[data_off : data_off + 0x18D630]
    obj2_data_off = data_off + 398 * 4096
    obj2_len = len(le) - obj2_data_off
    flat[0x190000 : 0x190000 + obj2_len] = le[obj2_data_off : obj2_data_off + obj2_len]
    for addr, typ, dest in original_fixups(exe_bytes):
        off = addr - 0x10000
        if typ in (6, 7):
            flat[off : off + 4] = struct.pack("<I", dest)
        elif typ == 5:
            flat[off : off + 2] = struct.pack("<H", dest & 0xFFFF)
    return bytes(flat)


def load_context(meta_dir, orig_exe_path):
    meta_dir = Path(meta_dir)
    exe_bytes = Path(orig_exe_path).read_bytes()
    mapping = {"W?$nwn(uipnv)pnv": 0x14AB0, "W?$dln(pnv)v": 0x14710, "W?$nan(uipnv)pnv": 0x14AC0}
    for l in (meta_dir / "extra.map").read_text(encoding="latin1").splitlines():
        if "=" in l:
            a, b = l.split("=", 1)
            if re.fullmatch("L[0-9A-Fa-f]{6}", b):
                mapping[a] = int(b[1:], 16)
    lib = json.loads((meta_dir / "libmap.json").read_text(encoding="utf-8"))
    for name, target in lib.items():
        if isinstance(target, str) and re.fullmatch("L[0-9A-Fa-f]{6}", target):
            for n in (name, name + "_", "_" + name):
                mapping.setdefault(n, int(target[1:], 16))
    for l in (meta_dir / "EXTRA_MAP_NEU.txt").read_text(encoding="latin1").splitlines():
        if "=" in l:
            a, b = l.split("=", 1)
            if re.fullmatch("L[0-9A-Fa-f]{6}", b):
                mapping[a] = int(b[1:], 16)
    fix = Fixups()
    for a, t, d in original_fixups(exe_bytes):
        if a in fix and fix[a] != (t, d):
            raise ValueError("Widerspruechliche LE-Fixups")
        fix[a] = (t, d)
    fix.freeze()
    fun = set()
    for p in (meta_dir / "funktionen.tsv", meta_dir / "clobber.tsv"):
        if p.exists():
            for l in p.read_text(encoding="latin1").splitlines():
                m = re.match(r"(?:f_)?([0-9a-fA-F]{6})\t", l)
                if m:
                    fun.add(int(m[1], 16))
    flat_img = build_flat_image(exe_bytes)
    return mapping, fix, flat_img, sorted(fun)
