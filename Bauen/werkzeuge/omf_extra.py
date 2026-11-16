import hashlib
import json
from pathlib import Path
import struct

LOCSZ = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 11: 6, 13: 4}
KNOWN_RECORDS = {
    0x80, 0x88, 0x8A, 0x8B, 0x8C, 0x8E, 0x90, 0x91, 0x94, 0x95,
    0x96, 0x98, 0x99, 0x9A, 0x9C, 0x9D, 0xA0, 0xA1, 0xA2, 0xA3,
    0xB4, 0xB6, 0xB7, 0xBC, 0xC2, 0xC3, 0xC4, 0xC5, 0xCA, 0xCC,
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def idx(data, pos):
    if pos >= len(data):
        raise ValueError("OMF-Index fehlt")
    if data[pos] & 128:
        if pos + 1 >= len(data):
            raise ValueError("OMF-Index abgeschnitten")
        return ((data[pos] & 127) << 8) | data[pos + 1], pos + 2
    return data[pos], pos + 1


def records(raw):
    pos = 0
    while pos < len(raw):
        if pos + 3 > len(raw):
            raise ValueError("OMF-Kopf abgeschnitten")
        typ, size = struct.unpack_from("<BH", raw, pos)
        end = pos + size + 3
        if not size or end > len(raw):
            raise ValueError("OMF-Satz abgeschnitten")
        rec = raw[pos:end]
        if rec[-1] and sum(rec) & 255:
            raise ValueError("OMF-Pruefsumme falsch")
        yield typ, rec[3:-1]
        pos = end


def fixups(raw):
    ln = [""]
    ext = [None]
    segs = {}
    groups = {}
    result = []
    frames = {}
    targets = {}
    cds = {}
    last = None
    recs = list(records(raw))
    if not recs or recs[0][0] != 0x80 or recs[-1][0] not in (0x8A, 0x8B):
        raise ValueError("Genau ein vollstaendiges OMF-Modul erwartet")
    if sum(t == 0x80 for t, _ in recs) != 1:
        raise ValueError("Mehrere OMF-Module")

    def word(data, pos, width):
        if pos + width > len(data):
            raise ValueError("OMF-Zahl abgeschnitten")
        return int.from_bytes(data[pos : pos + width], "little"), pos + width

    def names(data):
        pos = 0
        while pos < len(data):
            size = data[pos]
            pos += 1
            if pos + size > len(data):
                raise ValueError("OMF-Name abgeschnitten")
            yield data[pos : pos + size].decode("latin1")
            pos += size

    for typ, data in recs:
        if typ in (0xB0, 0xB8):
            raise ValueError(f"0x{typ:02x} nicht unterstuetzt")
        if typ not in KNOWN_RECORDS:
            raise ValueError(f"Nicht unterstuetzter OMF-Satz 0x{typ:02x}")
        if typ in (0x96, 0xCA):
            ln.extend(names(data))
        elif typ in (0x98, 0x99):
            pos = 1 + (3 if data[0] >> 5 == 0 else 0)
            _, pos = word(data, pos, 4 if typ & 1 else 2)
            name, pos = idx(data, pos)
            cls, pos = idx(data, pos)
            overlay, pos = idx(data, pos)
            segs[len(segs) + 1] = (ln[name], ln[cls], ln[overlay])
        elif typ == 0x9A:
            name, pos = idx(data, 0)
            members = []
            while pos < len(data):
                if data[pos] != 0xFF:
                    raise ValueError("Unbekannter GRPDEF-Eintrag")
                seg, pos = idx(data, pos + 1)
                members.append(seg)
            groups[len(groups) + 1] = (ln[name], members)
        elif typ in (0x8C, 0xB4):
            pos = 0
            while pos < len(data):
                size = data[pos]
                pos += 1
                if pos + size > len(data):
                    raise ValueError("EXTDEF abgeschnitten")
                ext.append(data[pos : pos + size].decode("latin1"))
                _, pos = idx(data, pos + size)
        elif typ == 0xBC:
            pos = 0
            while pos < len(data):
                ni, pos = idx(data, pos)
                ext.append(ln[ni])
                _, pos = idx(data, pos)
        elif typ in (0xA0, 0xA1):
            seg, pos = idx(data, 0)
            off, pos = word(data, pos, 4 if typ & 1 else 2)
            last = (("seg", seg), off)
        elif typ in (0xA2, 0xA3):
            raise ValueError("LIDATA wird fuer EXTRA nicht geraten")
        elif typ in (0xC2, 0xC3):
            flags, attr = data[:2]
            if flags & 2:
                raise ValueError("Iterierter COMDAT ungeprueft")
            off, pos = word(data, 3, 4 if typ & 1 else 2)
            _, pos = idx(data, pos)
            if attr & 15 == 0:
                group, pos = idx(data, pos)
                seg, pos = idx(data, pos)
                if not group and not seg:
                    _, pos = word(data, pos, 2)
            ni, pos = idx(data, pos)
            name = ln[ni]
            if not flags & 1:
                cds[name] = cds.get(name, 0) + 1
            if cds.get(name) != 1:
                raise ValueError("Mehrdeutiger COMDAT: " + name)
            last = (("comdat", name), off)
        elif typ in (0x9C, 0x9D):
            pos = 0

            def datum(method):
                nonlocal pos
                if method < 3:
                    value, pos = idx(data, pos)
                    return value
                if method == 3:
                    value, pos = word(data, pos, 2)
                    return value
                if method in (4, 5):
                    return None
                raise ValueError("Unbekannte FIXUPP-Methode")

            while pos < len(data):
                head = data[pos]
                pos += 1
                if not head & 128:
                    method = (head >> 2) & (7 if head & 64 else 3)
                    value = datum(method)
                    (frames if head & 64 else targets)[head & 3] = (method, value)
                    continue
                loc = (head >> 2) & 15
                if loc not in LOCSZ:
                    raise ValueError("Unbekannte FIXUPP-Breite")
                if pos + 2 > len(data):
                    raise ValueError("FIXUPP abgeschnitten")
                offset = ((head & 3) << 8) | data[pos]
                desc = data[pos + 1]
                pos += 2
                if desc & 128:
                    frame = frames[(desc >> 4) & 3]
                else:
                    method = (desc >> 4) & 7
                    frame = (method, datum(method))
                if desc & 8:
                    target = targets[desc & 3]
                else:
                    method = desc & 3
                    target = (method, datum(method))
                disp = 0
                if not desc & 4:
                    disp, pos = word(data, pos, 4 if typ & 1 else 2)
                if last is None:
                    raise ValueError("FIXUPP ohne Dateneigentuemer")
                result.append(
                    dict(
                        owner=last[0],
                        offset=last[1] + offset,
                        width=LOCSZ[loc],
                        location=loc,
                        relative=not bool(head & 64),
                        frame=frame,
                        target=target,
                        displacement=disp,
                    )
                )

    def segment(index):
        value = segs[index]
        if list(segs.values()).count(value) != 1:
            raise ValueError("Mehrdeutige SEGDEF-Identitaet")
        return value

    def canon(pair):
        method, value = pair
        if method == 0:
            return ("segment", segment(value))
        if method == 1:
            name, members = groups[value]
            return ("group", name, [segment(i) for i in members])
        if method == 2:
            if not value or value >= len(ext):
                raise ValueError("EXTDEF-Index fehlt")
            return ("external", ext[value])
        return ("absolute" if method == 3 else "location" if method == 4 else "target", value)

    for entry in result:
        entry["frame"] = canon(entry["frame"])
        entry["target"] = canon(entry["target"])
    return result
