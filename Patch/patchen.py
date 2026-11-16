#!/usr/bin/env python3
"""
patchen.py - Erzeugt die fehlerbereinigten EXE-Dateien (RIVA_FIX_WICHTIG.EXE,
             RIVA_FIX_ALLES.EXE) ohne Compiler aus der eigenen Original-RIVA.EXE
             und den kompakten Differenzdateien (*.ndp, Format NDP2) in Patch/.

Plattformunabhaengiges Gegenstueck zu Patch/patchen.ps1 (fuer Linux, macOS
und Windows). Benoetigt nur Python 3 (Standardbibliothek).

Aufruf:
    python3 Patch/patchen.py --spiel "/pfad/zu/Realms of Arkania 3" \
                             --name RIVA.EXE \
                             --ziel Build
"""

import argparse
import hashlib
import struct
import sys
import zlib
from pathlib import Path

ERW_ORIG_MD5 = "fb8f5fc3ba5454c7344c17aaf362de35"
ERW_ORIG_GROESSE = 2477899


def finde_datei_case_insensitive(ordner: Path, dateiname: str) -> Path | None:
    """Sucht dateiname in ordner ohne Ruecksicht auf Gross-/Kleinschreibung (wichtig unter Linux)."""
    direkt = ordner / dateiname
    if direkt.is_file():
        return direkt
    ziel = dateiname.lower()
    if ordner.is_dir():
        for kind in ordner.iterdir():
            if kind.is_file() and kind.name.lower() == ziel:
                return kind
    return None


def lese_varint(buf: bytes, pos: int) -> tuple[int, int]:
    val = 0
    shift = 0
    while True:
        b = buf[pos]
        pos += 1
        val |= (b & 0x7F) << shift
        if (b & 0x80) == 0:
            return val, pos
        shift += 7


def lese_svarint(buf: bytes, pos: int) -> tuple[int, int]:
    u, pos = lese_varint(buf, pos)
    val = -((u + 1) >> 1) if (u & 1) else (u >> 1)
    return val, pos


def wende_ndp2_an(orig: bytes, p: bytes, ziel_groesse: int) -> bytearray:
    anz_bloecke, len_hdr, len_sub, len_adds, len_lits = struct.unpack_from("<5I", p, 44)
    raw = zlib.decompress(p[64:], -15)
    erw_raw = len_hdr + len_sub + len_adds + len_lits
    if len(raw) != erw_raw:
        raise RuntimeError(f"Deflate-Stromlaenge stimmt nicht ({len(raw)} != {erw_raw})")

    h_pos = 0
    s_pos = len_hdr
    a_pos = len_hdr + len_sub
    l_pos = len_hdr + len_sub + len_adds

    neu = bytearray(ziel_groesse)
    dst = 0
    last_src_end = 0

    for _ in range(anz_bloecke):
        lit_len, h_pos = lese_varint(raw, h_pos)
        shift_delta, h_pos = lese_svarint(raw, h_pos)
        copy_len, h_pos = lese_varint(raw, h_pos)
        sub_cnt, h_pos = lese_varint(raw, h_pos)

        if lit_len > 0:
            neu[dst : dst + lit_len] = raw[l_pos : l_pos + lit_len]
            dst += lit_len
            l_pos += lit_len

        src = last_src_end + lit_len + shift_delta
        neu[dst : dst + copy_len] = orig[src : src + copy_len]

        cur = dst
        for _ in range(sub_cnt):
            tag = raw[s_pos]
            s_pos += 1
            if tag >= 64:
                ad_len = tag >> 6
                ex_len = tag & 0x3F
            elif tag >= 32:
                ad_len = 4
                ex_len = tag & 0x1F
            elif tag >= 1:
                ad_len = tag
                ex_len, s_pos = lese_varint(raw, s_pos)
            else:
                ex_len, s_pos = lese_varint(raw, s_pos)
                ad_len, s_pos = lese_varint(raw, s_pos)

            cur += ex_len
            for _ in range(ad_len):
                neu[cur] = (neu[cur] + raw[a_pos]) & 0xFF
                cur += 1
                a_pos += 1

        dst += copy_len
        last_src_end = src + copy_len

    if dst < ziel_groesse:
        rem = ziel_groesse - dst
        neu[dst:ziel_groesse] = raw[l_pos : l_pos + rem]
        l_pos += rem

    return neu


def wende_patch_an(orig: bytes, orig_md5: str, patch_pfad: Path, ziel_pfad: Path, name: str) -> bool:
    p = patch_pfad.read_bytes()
    if len(p) < 64 or p[:4] != b"NDP2":
        print(f"FEHLER: Ungueltige oder veraltete Patch-Datei: {patch_pfad}", file=sys.stderr)
        return False

    erw_groesse, ziel_groesse = struct.unpack_from("<II", p, 4)
    erw_md5 = p[12:28].hex().lower()
    soll_md5 = p[28:44].hex().lower()

    if len(orig) != erw_groesse or orig_md5 != erw_md5:
        print(
            f"\nFEHLER: Deine '{name}' passt nicht zur erwarteten deutschen GOG-Originalversion (V1.12)!",
            file=sys.stderr,
        )
        print(f"  Gefunden: {len(orig):,} Bytes, MD5 {orig_md5}", file=sys.stderr)
        print(f"  Erwartet: {erw_groesse:,} Bytes, MD5 {erw_md5}", file=sys.stderr)
        print("Abbruch: Bitte die unveraenderte deutsche Original-RIVA.EXE (Version 1.12) verwenden.", file=sys.stderr)
        return False

    try:
        neu = wende_ndp2_an(orig, p, ziel_groesse)
    except Exception as exc:
        print(f"\nFEHLER beim Entpacken/Anwenden von {patch_pfad.name}: {exc}", file=sys.stderr)
        return False

    ist_md5 = hashlib.md5(neu).hexdigest().lower()
    if len(neu) != ziel_groesse or ist_md5 != soll_md5:
        print(f"\nFEHLER: Pruefsummenfehler nach dem Patchen von {ziel_pfad.name}!", file=sys.stderr)
        print(f"  Ergebnis: {len(neu):,} Bytes, MD5 {ist_md5}", file=sys.stderr)
        print(f"  Erwartet: {ziel_groesse:,} Bytes, MD5 {soll_md5}", file=sys.stderr)
        print("Abbruch: Die erzeugte Zieldatei stimmt nicht bitgenau ueberein.", file=sys.stderr)
        return False

    ziel_pfad.parent.mkdir(parents=True, exist_ok=True)
    ziel_pfad.write_bytes(neu)
    print(f"  [OK] {ziel_pfad.name} erzeugt ({len(neu):,} Bytes, MD5 {ist_md5})")
    return True


def main() -> int:
    ap = argparse.ArgumentParser(description="Wendet .ndp-Patches (NDP2) auf die Original-RIVA.EXE an.")
    ap.add_argument("--spiel", required=True, type=Path, help="Pfad zum GOG-Installationsordner des Spiels")
    ap.add_argument("--name", required=True, help="Name der Original-EXE (RIVA.EXE)")
    ap.add_argument("--ziel", required=True, type=Path, help="Zielordner fuer die gepatchten EXEs (Build/)")
    args = ap.parse_args()

    orig_pfad = finde_datei_case_insensitive(args.spiel, args.name)
    if orig_pfad is None:
        print(f"FEHLER: '{args.name}' wurde in '{args.spiel}' nicht gefunden!", file=sys.stderr)
        print("Abbruch: Bitte den Hauptordner der deutschen GOG-Installation angeben.", file=sys.stderr)
        return 1

    orig_bytes = orig_pfad.read_bytes()
    orig_md5 = hashlib.md5(orig_bytes).hexdigest().lower()
    print(f"Originaldatei: {orig_pfad}")
    print(f"  Groesse: {len(orig_bytes):,} Bytes, MD5: {orig_md5}")

    if len(orig_bytes) != ERW_ORIG_GROESSE or orig_md5 != ERW_ORIG_MD5:
        print(
            f"\nFEHLER: Deine '{args.name}' passt nicht zur erwarteten deutschen GOG-Originalversion (V1.12)!",
            file=sys.stderr,
        )
        print(f"  Gefunden: {len(orig_bytes):,} Bytes, MD5 {orig_md5}", file=sys.stderr)
        print(f"  Erwartet: {ERW_ORIG_GROESSE:,} Bytes, MD5 {ERW_ORIG_MD5}", file=sys.stderr)
        print("Abbruch: Bitte die unveraenderte deutsche Original-RIVA.EXE (Version 1.12) verwenden.", file=sys.stderr)
        return 1

    print("")
    patch_ordner = Path(__file__).resolve().parent
    patches = sorted(patch_ordner.glob("*.ndp"))
    if not patches:
        print(f"FEHLER: Keine *.ndp-Patchdateien in '{patch_ordner}' gefunden!", file=sys.stderr)
        return 1

    for patch in patches:
        ziel_name = patch.stem + ".EXE"
        ziel_pfad = args.ziel / ziel_name
        if not wende_patch_an(orig_bytes, orig_md5, patch, ziel_pfad, args.name):
            return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
