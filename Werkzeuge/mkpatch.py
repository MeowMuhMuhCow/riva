#!/usr/bin/env python3
"""
mkpatch.py - Erzeugt kompakte Binaer-Patch-Dateien (.ndp) im Format "NDP2"
             fuer RIVA_FIX_WICHTIG.EXE und RIVA_FIX_ALLES.EXE gegenueber der
             deutschen Original-RIVA.EXE (V1.12).

Format "NDP2" (.ndp):
  Kopf (64 Bytes, unkomprimiert):
    0..3    4 Byte  Magic "NDP2"
    4..7    4 Byte  uint32 LE: erwartete Groesse der Original-EXE (2.477.899)
    8..11   4 Byte  uint32 LE: Ziel-Groesse der gepatchten EXE (2.507.083)
   12..27  16 Byte  MD5 der Original-EXE (fb8f5fc3ba5454c7344c17aaf362de35)
   28..43  16 Byte  MD5 der gepatchten Ziel-EXE
   44..47   4 Byte  uint32 LE: Anzahl Kopierbloecke (anz_bloecke)
   48..51   4 Byte  uint32 LE: Laenge des Blocksteuerstroms hdr_s (Bytes)
   52..55   4 Byte  uint32 LE: Laenge des Subrun-Stroms sub_s (Bytes)
   56..59   4 Byte  uint32 LE: Laenge des Additionsstroms adds (Bytes)
   60..63   4 Byte  uint32 LE: Laenge des Literalstroms lits (Bytes)
  Ab Byte 64:
    Raw-Deflate-Strom (RFC 1951, wbits=-15), der entpackt exakt
    (hdr_s + sub_s + adds + lits) ergibt.

Funktionsweise (bsdiff-artig mit spuerbaren Kopierbloecken + Nicht-Null-ADD):
  - Kopierbloecke (dst, src, copy_len) kopieren verschobene Abschnitte aus der
    Original-EXE.
  - Innerhalb jedes Kopierblocks geben Subruns (ex_len, ad_len) an, wie viele
    Bytes unveraendert bleiben (ex_len) und auf wie viele nachfolgende Bytes
    (ad_len, z. B. verschobene rel32-Sprungziele oder LE-Fixups) byteweise
    Differenzen aus dem Additionsstrom (adds) addiert werden.
  - Da unveraenderte Bytes durch ex_len uebersprungen werden, enthaelt adds
    ausschliesslich Nicht-Null-Differenzen (1..255) und niemals Null-Laeufe
    oder Original-Datenfenster.
  - Kurze neue Code-Stuecke zwischen Kopierbloecken liegen im Literalstrom (lits).
"""

import bisect
from collections import defaultdict
import hashlib
import struct
import sys
import time
import zlib
from pathlib import Path

WURZEL = Path(__file__).resolve().parent.parent
ORIG   = WURZEL / "Original" / "RIVA.EXE"
BUILD  = WURZEL / "Build"
PATCH  = WURZEL / "Patch"

ERW_ORIG_GROESSE = 2477899
ERW_ORIG_MD5     = "fb8f5fc3ba5454c7344c17aaf362de35"


def write_varint(buf: bytearray, val: int) -> None:
    while val >= 0x80:
        buf.append((val & 0x7F) | 0x80)
        val >>= 7
    buf.append(val)


def write_svarint(buf: bytearray, val: int) -> None:
    u = ((-val) << 1) - 1 if val < 0 else (val << 1)
    write_varint(buf, u)


def baue_index6(orig: bytes) -> dict[bytes, list[int]]:
    index6: dict[bytes, list[int]] = defaultdict(list)
    for i in range(0, len(orig) - 6, 1):
        k = orig[i : i + 6]
        if len(index6[k]) < 512:
            index6[k].append(i)
    return index6


def finde_bloecke(orig: bytes, ziel: bytes, index6: dict[bytes, list[int]]) -> list[tuple[int, int, int]]:
    i = 0
    last_shift = 0
    matches: list[tuple[int, int, int]] = []
    n_w = len(ziel)
    n_o = len(orig)

    while i < n_w - 6:
        cand_j = i + last_shift
        best_i = -1
        best_j = -1
        best_len = 0
        best_score = 0
        candidates: list[int] = []

        if 0 <= cand_j < n_o - 6 and ziel[i : i + 3] == orig[cand_j : cand_j + 3]:
            candidates.append(cand_j)

        k4 = ziel[i : i + 4]
        lo = max(0, cand_j - 512)
        hi = min(n_o, cand_j + 256)
        p = orig.find(k4, lo, hi)
        while p != -1:
            candidates.append(p)
            p = orig.find(k4, p + 1, hi)

        k6 = ziel[i : i + 6]
        if k6 in index6:
            lst = index6[k6]
            pos = bisect.bisect_left(lst, cand_j)
            for idx in range(max(0, pos - 4), min(len(lst), pos + 5)):
                candidates.append(lst[idx])

        prev_end = matches[-1][0] + matches[-1][2] if matches else 0
        for j in set(candidates):
            b = 0
            while i - b > prev_end and j - b > 0 and ziel[i - b - 1] == orig[j - b - 1]:
                b += 1
            length = 0
            mismatches = 0
            while i + length < n_w and j + length < n_o:
                if ziel[i + length : i + length + 64] == orig[j + length : j + length + 64]:
                    length += min(64, n_w - (i + length), n_o - (j + length))
                    continue
                if ziel[i + length] == orig[j + length]:
                    length += 1
                else:
                    found = False
                    for gap in range(1, 13):
                        req = 3 if gap <= 4 else 6
                        if (
                            i + length + gap + req <= n_w
                            and j + length + gap + req <= n_o
                            and ziel[i + length + gap : i + length + gap + req]
                            == orig[j + length + gap : j + length + gap + req]
                        ):
                            length += gap + req
                            mismatches += gap
                            found = True
                            break
                    if not found:
                        break
            tot_len = b + length
            score = tot_len - mismatches * 3
            is_local = abs((j - i) - last_shift) <= 512
            if is_local:
                score += 6
            min_req = 4 if (j - i == last_shift) else (10 if is_local else 16)
            if score >= min_req and score > best_score:
                best_score = score
                best_i = i - b
                best_j = j - b
                best_len = tot_len

        if best_j >= 0:
            if (
                matches
                and best_j - best_i == matches[-1][1] - matches[-1][0]
                and best_i - (matches[-1][0] + matches[-1][2]) <= 32
            ):
                prev_i, prev_j, _ = matches[-1]
                matches[-1] = (prev_i, prev_j, (best_i + best_len) - prev_i)
            else:
                matches.append((best_i, best_j, best_len))
            if best_len >= 24 or abs((best_j - best_i) - last_shift) <= 512:
                last_shift = best_j - best_i
            i = best_i + best_len
        else:
            i += 1

    return matches


def pruefe_64b_fenster(daten: bytes, orig_win64: set[bytes]) -> int:
    if len(daten) < 64:
        return 0
    return sum(1 for i in range(len(daten) - 63) if daten[i : i + 64] in orig_win64)


def erzeuge_patch(
    orig: bytes,
    ziel: bytes,
    index6: dict[bytes, list[int]],
    orig_win64: set[bytes],
) -> bytes:
    t0 = time.time()
    matches = finde_bloecke(orig, ziel, index6)

    hdr_s = bytearray()
    sub_s = bytearray()
    adds = bytearray()
    lits = bytearray()

    pos = 0
    last_src_end = 0
    for dst, src, length in matches:
        lit_len = dst - pos
        shift_delta = src - last_src_end - lit_len
        write_varint(hdr_s, lit_len)
        write_svarint(hdr_s, shift_delta)
        write_varint(hdr_s, length)
        lits.extend(ziel[pos:dst])

        k = 0
        sub_runs: list[tuple[int, int]] = []
        while k < length:
            ex_start = k
            while k < length and ziel[dst + k] == orig[src + k]:
                k += 1
            ex_len = k - ex_start
            ad_start = k
            while k < length and ziel[dst + k] != orig[src + k]:
                adds.append((ziel[dst + k] - orig[src + k]) & 0xFF)
                k += 1
            ad_len = k - ad_start
            if ad_len > 0:
                sub_runs.append((ex_len, ad_len))

        write_varint(hdr_s, len(sub_runs))
        for ex_len, ad_len in sub_runs:
            if 1 <= ad_len <= 3 and ex_len < 64:
                sub_s.append((ad_len << 6) | ex_len)
            elif ad_len == 4 and ex_len < 32:
                sub_s.append(0x20 | ex_len)
            elif 1 <= ad_len <= 31:
                sub_s.append(ad_len)
                write_varint(sub_s, ex_len)
            else:
                sub_s.append(0)
                write_varint(sub_s, ex_len)
                write_varint(sub_s, ad_len)

        pos = dst + length
        last_src_end = src + length

    if pos < len(ziel):
        lits.extend(ziel[pos:])

    raw = bytes(hdr_s + sub_s + adds + lits)
    comp = zlib.compressobj(9, zlib.DEFLATED, -15)
    deflated = comp.compress(raw) + comp.flush()

    out = bytearray()
    out += b"NDP2"
    out += struct.pack("<II", len(orig), len(ziel))
    out += hashlib.md5(orig).digest()
    out += hashlib.md5(ziel).digest()
    out += struct.pack("<5I", len(matches), len(hdr_s), len(sub_s), len(adds), len(lits))
    out += deflated

    # Rechte-Selbstpruefung (64-Byte-Fenster gegen Original/RIVA.EXE)
    hits_lits = pruefe_64b_fenster(bytes(lits), orig_win64)
    hits_adds = pruefe_64b_fenster(bytes(adds), orig_win64)
    hits_raw  = pruefe_64b_fenster(raw, orig_win64)
    hits_out  = pruefe_64b_fenster(bytes(out), orig_win64)
    if hits_lits or hits_adds or hits_raw or hits_out:
        raise RuntimeError(
            f"Rechtepruefung fehlgeschlagen: 64-Byte-Fenster in Original gefunden "
            f"(lits={hits_lits}, adds={hits_adds}, raw={hits_raw}, out={hits_out})"
        )

    dt = time.time() - t0
    print(
        f"  {len(matches):,} Kopierbloecke, {len(adds):,} ADD-Bytes, {len(lits):,} Literal-Bytes\n"
        f"  Unkomprimiert: {len(raw):,} Bytes -> NDP2-Patch: {len(out):,} Bytes ({len(out)/1024:.1f} KB, {dt:.1f}s)\n"
        f"  Rechtepruefung (64-Byte-Fenster gegen Original): lits=0, adds=0, raw=0, ndp=0"
    )
    return bytes(out)


def main() -> int:
    if not ORIG.is_file():
        print(f"FEHLER: {ORIG} fehlt.", file=sys.stderr)
        return 1
    orig = ORIG.read_bytes()
    orig_md5 = hashlib.md5(orig).hexdigest().lower()
    if len(orig) != ERW_ORIG_GROESSE or orig_md5 != ERW_ORIG_MD5:
        print(
            f"FEHLER: {ORIG} passt nicht zur deutschen GOG-Originalversion V1.12!\n"
            f"  Gefunden: {len(orig)} Bytes, MD5 {orig_md5}\n"
            f"  Erwartet: {ERW_ORIG_GROESSE} Bytes, MD5 {ERW_ORIG_MD5}",
            file=sys.stderr,
        )
        return 1

    PATCH.mkdir(exist_ok=True)
    print("Baue Index und 64-Byte-Fenstermenge der Original-RIVA.EXE ...")
    index6 = baue_index6(orig)
    orig_win64 = set(orig[i : i + 64] for i in range(len(orig) - 63))

    gefundene = 0
    for name in ("RIVA_FIX_WICHTIG.EXE", "RIVA_FIX_ALLES.EXE"):
        zp = BUILD / name
        if not zp.is_file():
            print(f"UEBERSPRINGE: {zp} noch nicht gebaut.")
            continue
        ziel = zp.read_bytes()
        ziel_md5 = hashlib.md5(ziel).hexdigest().lower()
        print(f"\n{name} ({len(ziel):,} Bytes, MD5 {ziel_md5}):")
        pdata = erzeuge_patch(orig, ziel, index6, orig_win64)
        pp = PATCH / (zp.stem + ".ndp")
        pp.write_bytes(pdata)
        print(f"  geschrieben: {pp}")
        gefundene += 1

    if gefundene == 0:
        print("HINWEIS: Noch keine RIVA_FIX_*.EXE in Build/ vorhanden.", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
