"""OMF-/COMDAT-Bibliotheksfunktionen (extrahiert aus einbau.py und align1.py, ohne externe Pfade)."""
from pathlib import Path
import re
import shutil
import struct
import omf

ALIGN = {1: 1, 2: 2, 3: 16, 4: 4096, 5: 4, 6: 32}


def records(data):
    pos = 0
    while pos < len(data):
        if pos + 3 > len(data):
            raise ValueError("Abgeschnittener OMF-Kopf")
        typ, size = struct.unpack_from("<BH", data, pos)
        end = pos + 3 + size
        if size < 1 or end > len(data):
            raise ValueError("Abgeschnittener OMF-Satz")
        raw = data[pos:end]
        if raw[-1] and sum(raw) & 255:
            raise ValueError("OMF-Pruefsumme falsch")
        yield typ, raw[3:-1]
        pos = end


def record(typ, body):
    raw = struct.pack("<BH", typ, len(body) + 1) + body
    return raw + bytes([-sum(raw) & 255])


def index(body, pos):
    return omf.idx(body, pos)


def names(body):
    pos = 0
    while pos < len(body):
        size = body[pos]
        end = pos + size + 1
        if end > len(body):
            raise ValueError("Abgeschnittener OMF-Name")
        yield body[pos + 1 : end].decode("latin1")
        pos = end


def namebytes(name):
    raw = name.encode("latin1")
    if len(raw) > 255:
        raise ValueError("OMF-Name zu lang")
    return bytes([len(raw)]) + raw


def scan(path):
    recs = list(records(Path(path).read_bytes()))
    ln = [""]
    segments = {}
    cds = {}
    contexts = {}
    last = None
    for num, (typ, body) in enumerate(recs):
        if typ in (0x96, 0xCA):
            ln.extend(names(body))
        elif typ in (0x98, 0x99):
            acbp = body[0]
            if acbp >> 5 not in ALIGN:
                raise ValueError("Unbekannte/absolute Segmentausrichtung")
            pos = 1
            width = 4 if typ == 0x99 else 2
            size = int.from_bytes(body[pos : pos + width], "little")
            pos += width
            sn, pos = index(body, pos)
            cn, pos = index(body, pos)
            segments[len(segments) + 1] = dict(
                name=ln[sn], cls=ln[cn], length=size, align=ALIGN[acbp >> 5]
            )
        elif typ in (0xC2, 0xC3):
            flags, attr, align = body[:3]
            if flags & 2:
                raise ValueError("Iterierter COMDAT nicht unterstuetzt")
            if attr & 15:
                raise ValueError("COMDAT ohne explizites Segment nicht unterstuetzt")
            if flags & 4:
                raise ValueError("Lokaler COMDAT nicht unterstuetzt")
            width = 4 if typ == 0xC3 else 2
            off = int.from_bytes(body[3 : 3 + width], "little")
            _, pos = index(body, 3 + width)
            _, pos = index(body, pos)
            seg, pos = index(body, pos)
            if not seg:
                raise ValueError("COMDAT ohne SEGDEF nicht unterstuetzt")
            ni, pos = index(body, pos)
            name = ln[ni]
            if name in cds:
                if not flags & 1:
                    raise ValueError("Doppelter COMDAT im selben OBJ: " + name)
                cd = cds[name]
                if (cd["seg"], cd["attr"], cd["alignment"]) != (seg, attr, align):
                    raise ValueError("Inkonsistente COMDAT-Fortsetzung: " + name)
            else:
                if flags & 1:
                    raise ValueError("COMDAT-Fortsetzung ohne Anfang: " + name)
                if align and align not in ALIGN:
                    raise ValueError("Unbekannte COMDAT-Ausrichtung")
                cd = dict(
                    name=name,
                    seg=seg,
                    attr=attr,
                    alignment=align,
                    align=ALIGN[align] if align else segments[seg]["align"],
                    length=0,
                    cls=segments[seg]["cls"],
                    records=[],
                )
                cds[name] = cd
            cd["length"] = max(cd["length"], off + len(body) - pos)
            cd["records"].append(num)
            last = name
            contexts[num] = name
        elif typ in (0xA0, 0xA1, 0xA2, 0xA3):
            last = None
        elif typ in (0x9C, 0x9D):
            contexts[num] = last
    return dict(records=recs, segments=segments, comdats=list(cds.values()), contexts=contexts)


def fixparts(typ, body):
    pos = 0
    while pos < len(body):
        start = pos
        first = body[pos]
        pos += 1
        if not first & 0x80:
            method = (first >> 2) & (7 if first & 0x40 else 3)
            if method < 3:
                _, pos = index(body, pos)
            elif method == 3:
                pos += 2
            thread = True
        else:
            pos += 1
            fd = body[pos]
            pos += 1
            if not fd & 0x80:
                method = (fd >> 4) & 7
                if method < 3:
                    _, pos = index(body, pos)
                elif method == 3:
                    pos += 2
            if not fd & 8:
                if fd & 3 == 3:
                    pos += 2
                else:
                    _, pos = index(body, pos)
            if not fd & 4:
                pos += 4 if typ == 0x9D else 2
            thread = False
        if pos > len(body):
            raise ValueError("Abgeschnittener FIXUPP")
        yield thread, body[start:pos]


def comdat_selection(info, ren=None):
    if ren is None:
        ren = {}
    cds = {c["name"]: c for c in info["comdats"]}
    if not cds:
        return set(), set(), set()
    ln = [""]
    ext = [None]
    edges = {None: set()}
    frame_threads = {}
    target_threads = {}
    for num, (typ, body) in enumerate(info["records"]):
        if typ in (0x96, 0xCA):
            ln.extend(names(body))
        elif typ in (0x8C, 0xB4):
            pos = 0
            while pos < len(body):
                size = body[pos]
                ext.append(body[pos + 1 : pos + 1 + size].decode("latin1"))
                _, pos = index(body, pos + 1 + size)
        elif typ == 0xBC:
            pos = 0
            while pos < len(body):
                ni, pos = index(body, pos)
                ext.append(ln[ni])
                _, pos = index(body, pos)
        elif typ in (0x9C, 0x9D):
            owner = info["contexts"].get(num)
            refs = edges.setdefault(owner, set())
            for thread, part in fixparts(typ, body):
                if thread:
                    first = part[0]
                    method = (first >> 2) & (7 if first & 0x40 else 3)
                    datum = index(part, 1)[0] if method < 3 else None
                    (frame_threads if first & 0x40 else target_threads)[first & 3] = (method, datum)
                    continue
                fd = part[2]
                pos = 3
                if fd & 0x80:
                    key = (fd >> 4) & 3
                    if key not in frame_threads:
                        raise ValueError("Undefinierter FRAME-Thread")
                    frame = frame_threads[key]
                else:
                    method = (fd >> 4) & 7
                    datum = None
                    if method < 3:
                        datum, pos = index(part, pos)
                    elif method == 3:
                        pos += 2
                    frame = (method, datum)
                if fd & 8:
                    if fd & 3 not in target_threads:
                        raise ValueError("Undefinierter TARGET-Thread")
                    target = target_threads[fd & 3]
                else:
                    method = fd & 3
                    datum = index(part, pos)[0] if method < 3 else None
                    target = (method, datum)
                for method, datum in (frame, target):
                    if method == 2:
                        if not datum or datum >= len(ext):
                            raise ValueError("Ungueltiger EXTDEF-Fixup")
                        refs.add(ext[datum])
    typeinfos = {n for n, c in cds.items() if c["cls"] != "CODE" and n.startswith("W?$Wts")}
    helpers = {
        n for n, c in cds.items() if c["cls"] == "CODE" and re.match(r"^W\?\$(?:ct|dt):", n)
    }
    original = {
        n
        for n in cds
        if re.fullmatch(r"L[0-9A-Fa-f]{6}", n)
        or re.match(r"^W\?[fdv]_[0-9a-fA-F]{6}(?:\$|$)", n)
        or re.match(r"^W\?\$(?:ct|dt):f_[0-9a-fA-F]{6}\$", n)
    }
    live = (set(cds) - helpers - typeinfos) | original
    live.update(edges[None] & set(cds))
    pending = list(live)
    while pending:
        name = pending.pop()
        for ref in edges.get(name, set()) & set(cds) - live:
            live.add(ref)
            pending.append(ref)
    dropped = set(cds) - live
    code = {n for n in live if cds[n]["cls"] == "CODE"}
    data = live - code
    return code, data, dropped


def clean_comdats(source, target, ren=None):
    info = scan(source)
    _, _, dropped = comdat_selection(info, ren)
    if not dropped:
        if Path(source) != Path(target):
            shutil.copyfile(source, target)
        return 0
    out = bytearray()
    for num, (typ, body) in enumerate(info["records"]):
        if info["contexts"].get(num) in dropped:
            if typ in (0xC2, 0xC3):
                continue
            if typ in (0x9C, 0x9D):
                body = b"".join(p for thread, p in fixparts(typ, body) if thread)
                if not body:
                    continue
        out += record(typ, body)
    list(records(out))
    Path(target).write_bytes(out)
    return len(dropped)


def layout(path, base=0):
    info = scan(path)
    parsed = omf.modules(str(path))
    if len(parsed) != 1:
        raise ValueError("Genau ein OMF-Modul erforderlich")
    parsed = parsed[0]
    pcd = {c["name"]: c for c in parsed["comdats"]}
    selected, _, _ = comdat_selection(info)
    code = [c for c in info["comdats"] if c["name"] in selected]
    if not code:
        return info, []
    used = {c["seg"] for c in code}
    used.update(i for i, s in info["segments"].items() if s["cls"] == "CODE" and s["length"])
    if len(used) != 1:
        raise ValueError("COMDAT-Modul braucht genau ein aktives CODE-Segment")
    seg = used.pop()
    s = info["segments"][seg]
    blocks = [dict(kind="TEXT", address=base, **parsed["segs"][seg])]
    cur = base + s["length"]
    for cd in reversed(code):
        adr = (cur + cd["align"] - 1) // cd["align"] * cd["align"]
        if adr > cur:
            blocks.append(
                dict(
                    kind="NULL",
                    name="Linkerfuellung",
                    address=cur,
                    data=bytes(adr - cur),
                    mask=bytes(adr - cur),
                    has=bytes([1]) * (adr - cur),
                )
            )
        blocks.append(dict(kind="COMDAT", address=adr, **pcd[cd["name"]]))
        cur = adr + cd["length"]
    return info, blocks


def prepare(source, target, ren):
    info = scan(source)
    code, data, dropped = comdat_selection(info, ren)
    for name in data:
        if not re.fullmatch(r"L[0-9A-Fa-f]{6}", ren.get(name, "")) or ren[name] == "L014710":
            raise ValueError("Originaladresse fuer Daten-COMDAT fehlt: " + name)
    if len({ren.get(n, n) for n in code}) != len(code):
        raise ValueError("Umbenennung vereinigt Code-COMDATs")
    if any(ren.get(n) == "L014710" for n in code):
        raise ValueError("Platzhalter L014710 fuer Code-COMDAT")
    cd_by_name = {c["name"]: c for c in info["comdats"]}
    out = bytearray()
    for num, (typ, body) in enumerate(info["records"]):
        if typ == 0x88 and len(body) > 1 and body[1] in (0x9F, 0xA8, 0xA9):
            continue
        if typ in (0xC2, 0xC3) and info["contexts"][num] in data | dropped:
            continue
        if typ in (0xC2, 0xC3) and not body[2]:
            cd = cd_by_name[info["contexts"][num]]
            inherited = info["segments"][cd["seg"]]["align"]
            explicit = next(k for k, v in ALIGN.items() if v == inherited)
            body = body[:2] + bytes([explicit]) + body[3:]
        if typ in (0x9C, 0x9D) and info["contexts"].get(num) in data | dropped:
            body = b"".join(part for thread, part in fixparts(typ, body) if thread)
            if not body:
                continue
        if typ in (0x96, 0xCA):
            body = b"".join(namebytes(ren.get(n, n)) for n in names(body))
        elif typ in (0x8C, 0xB4, 0x90, 0x91, 0xB6, 0xB7):
            pos = 0
            new = bytearray()
            pub = typ not in (0x8C, 0xB4)
            if pub:
                _, pos = index(body, pos)
                seg, pos = index(body, pos)
                if not seg:
                    pos += 2
                new += body[:pos]
            while pos < len(body):
                size = body[pos]
                name = body[pos + 1 : pos + 1 + size].decode("latin1")
                pos += size + 1
                new += namebytes(ren.get(name, name))
                if pub:
                    width = 4 if typ & 1 else 2
                    new += body[pos : pos + width]
                    pos += width
                end = index(body, pos)[1]
                new += body[pos:end]
                pos = end
            body = bytes(new)
        out += record(typ, body)
    list(records(out))
    Path(target).write_bytes(out)
    return len(code), len(data)


def code_comdats(path):
    info = scan(path)
    selected, _, _ = comdat_selection(info)
    return [c for c in info["comdats"] if c["name"] in selected]


def segdefs(path):
    d = Path(path).read_bytes()
    i = 0
    ln_ = [""]
    out = []
    while i + 3 <= len(d):
        t = d[i]
        k = struct.unpack_from("<H", d, i + 1)[0]
        b = d[i + 3 : i + 2 + k]
        i += 3 + k
        if t == 0x96:
            j = 0
            while j < len(b):
                q = b[j]
                ln_.append(b[j + 1 : j + 1 + q].decode("latin1"))
                j += 1 + q
        elif t in (0x98, 0x99):
            acbp = b[0]
            j = 1
            if (acbp >> 5) == 0:
                j += 3
            L = struct.unpack_from("<I" if t == 0x99 else "<H", b, j)[0]
            j += 4 if t == 0x99 else 2
            sn, j = index(b, j)
            cn, j = index(b, j)
            out.append((ln_[sn], ln_[cn], L, ALIGN.get(acbp >> 5, 16)))
    return out


def align1(path):
    p = Path(path)
    d = bytearray(p.read_bytes())
    i = 0
    while i < len(d):
        t = d[i]
        n = struct.unpack_from("<H", d, i + 1)[0]
        if t in (0x98, 0x99) and d[i + 3] >> 5 != 1:
            d[i + 3] = (d[i + 3] & 0x1F) | (1 << 5)
            d[i + 2 + n] = (-sum(d[i : i + 2 + n])) & 0xFF
        i += 3 + n
    p.write_bytes(d)


LIB = {
    "omf": omf,
    "records": records,
    "record": record,
    "index": index,
    "names": names,
    "namebytes": namebytes,
    "scan": scan,
    "fixparts": fixparts,
    "comdat_selection": comdat_selection,
    "clean_comdats": clean_comdats,
    "layout": layout,
    "prepare": prepare,
    "code_comdats": code_comdats,
    "segdefs": segdefs,
    "align1": align1,
}
