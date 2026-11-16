#!/usr/bin/env python3
"""
pruefe_patch_rechte.py - Rechtepruefung fuer die Binaer-Patches (*.ndp, Format NDP2).

Prueft fuer jede Patchdatei in Patch/, dass KEIN einziges 64-Byte-Fenster:
  1. der unkomprimierten Literal-Daten (lits),
  2. der unkomprimierten Additions-Daten (adds),
  3. der verketteten Literal-/Additionsdaten (adds + lits),
  4. des gesamten unkomprimierten NDP2-Stroms (hdr_s + sub_s + adds + lits),
  5. der komprimierten .ndp-Datei selbst
in Original/RIVA.EXE (2.477.899 Bytes, MD5 fb8f5fc3ba5454c7344c17aaf362de35) vorkommt.
"""

import hashlib
import struct
import sys
import zlib
from pathlib import Path

WURZEL = Path(__file__).resolve().parent.parent
ORIG   = WURZEL / "Original" / "RIVA.EXE"
PATCH  = WURZEL / "Patch"

FENSTER = 64


def zaehle_treffer(daten: bytes, orig_win64: set[bytes]) -> tuple[int, int]:
    """Gibt (anzahl_gepruefter_fenster, anzahl_treffer) zurueck."""
    if len(daten) < FENSTER:
        return 0, 0
    anz = len(daten) - FENSTER + 1
    treffer = sum(1 for i in range(anz) if daten[i : i + FENSTER] in orig_win64)
    return anz, treffer


def main() -> int:
    if not ORIG.is_file():
        print(f"FEHLER: {ORIG} nicht gefunden.", file=sys.stderr)
        return 1

    orig = ORIG.read_bytes()
    orig_md5 = hashlib.md5(orig).hexdigest().lower()
    orig_win64 = set(orig[i : i + FENSTER] for i in range(len(orig) - FENSTER + 1))
    print(f"Original: {ORIG.name} ({len(orig):,} Bytes, MD5 {orig_md5})")
    print(f"Eindeutige {FENSTER}-Byte-Fenster im Original: {len(orig_win64):,}\n")

    patches = sorted(PATCH.glob("*.ndp"))
    if not patches:
        print(f"FEHLER: Keine *.ndp-Dateien in {PATCH} gefunden.", file=sys.stderr)
        return 1

    gesamt_treffer = 0
    for pp in patches:
        p = pp.read_bytes()
        if len(p) < 64 or p[:4] != b"NDP2":
            print(f"FEHLER: {pp.name} ist keine gueltige NDP2-Datei.", file=sys.stderr)
            return 1

        anz_bloecke, len_hdr, len_sub, len_adds, len_lits = struct.unpack_from("<5I", p, 44)
        raw = zlib.decompress(p[64:], -15)
        if len(raw) != len_hdr + len_sub + len_adds + len_lits:
            print(f"FEHLER: {pp.name} unkomprimierte Groesse inkonsistent.", file=sys.stderr)
            return 1

        adds = raw[len_hdr + len_sub : len_hdr + len_sub + len_adds]
        lits = raw[len_hdr + len_sub + len_adds :]
        adds_lits = adds + lits

        print(f"=== {pp.name} ({len(p):,} Bytes / {len(p)/1024:.1f} KB) ===")
        for name, buf in [
            ("Literal-Daten (lits, unkomprimiert)", lits),
            ("Additions-Daten (adds, unkomprimiert)", adds),
            ("Literal + Additions (unkomprimiert)", adds_lits),
            ("Gesamt-Strom (hdr+sub+adds+lits, unkompr.)", raw),
            ("Patchdatei (.ndp auf Platte, komprimiert)", p),
        ]:
            fenster_anz, treffer = zaehle_treffer(buf, orig_win64)
            gesamt_treffer += treffer
            status = "OK (0 Treffer)" if treffer == 0 else f"FEHLER ({treffer} Treffer!)"
            print(f"  {name:44s}: {len(buf):8,} Bytes | {fenster_anz:8,} Fenster | {status}")
        print("")

    if gesamt_treffer == 0:
        print("ERGEBNIS: BESTANDEN (0 uebereinstimmende 64-Byte-Fenster in allen Pruefungen).")
        return 0
    else:
        print(f"ERGEBNIS: FEHLGESCHLAGEN ({gesamt_treffer} Treffer gefunden)!", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
