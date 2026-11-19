#!/usr/bin/env python3
"""
pruefe_port_rechte.py - 64-Byte-Fenster-Rechtepruefung fuer die nativen Port-EXEs
und Release-Dateien gegen Original/RIVA.EXE (analog pruefe_patch_rechte.py).

Prueft fuer jede Port-EXE (RIVA_PORT.EXE, RIVA_PORT_ORIG.EXE, RIVA_PORT_WICHTIG.EXE,
RIVA_PORT_ALLES.EXE) und alle Dateien in Port/release/, dass KEIN einziges 64-Byte-Fenster
in Original/RIVA.EXE (2.477.899 Bytes, MD5 fb8f5fc3ba5454c7344c17aaf362de35) vorkommt.
"""

import argparse
import hashlib
import json
import sys
from pathlib import Path

PORT_DIR = Path(__file__).resolve().parents[1]
WURZEL   = PORT_DIR.parent
ORIG     = WURZEL / "Original" / "RIVA.EXE"
FENSTER  = 64


def zaehle_treffer(daten: bytes, orig_win64: set[bytes]) -> tuple[int, int]:
    """Gibt (anzahl_gepruefter_fenster, anzahl_treffer) zurueck."""
    if len(daten) < FENSTER:
        return 0, 0
    anz = len(daten) - FENSTER + 1
    treffer = sum(1 for i in range(anz) if daten[i : i + FENSTER] in orig_win64)
    return anz, treffer


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--exe-dir", type=Path, default=PORT_DIR / "release" / "bin")
    ap.add_argument("--json-out", type=Path, default=None)
    args = ap.parse_args()

    if not ORIG.is_file():
        print(f"FEHLER: {ORIG} nicht gefunden.", file=sys.stderr)
        return 1

    orig = ORIG.read_bytes()
    orig_md5 = hashlib.md5(orig).hexdigest().lower()
    orig_win64 = set(orig[i : i + FENSTER] for i in range(len(orig) - FENSTER + 1))
    print(f"Original: {ORIG.name} ({len(orig):,} Bytes, MD5 {orig_md5})")
    print(f"Eindeutige {FENSTER}-Byte-Fenster im Original: {len(orig_win64):,}\n")

    exe_names = [
        "RIVA_PORT.EXE",
        "RIVA_PORT_ORIG.EXE",
        "RIVA_PORT_WICHTIG.EXE",
        "RIVA_PORT_ALLES.EXE",
    ]
    files_to_check: list[Path] = []
    for name in exe_names:
        p = args.exe_dir / name
        if not p.is_file():
            print(f"FEHLER: {p} fehlt.", file=sys.stderr)
            return 1
        files_to_check.append(p)

    for p in sorted((PORT_DIR / "release").rglob("*")):
        if p.is_file() and p.name.upper() not in exe_names:
            files_to_check.append(p)

    gesamt_treffer = 0
    report = {
        "orig_exe": str(ORIG.name),
        "orig_size": len(orig),
        "orig_md5": orig_md5,
        "window_size": FENSTER,
        "unique_orig_windows": len(orig_win64),
        "files": {},
    }

    for fp in files_to_check:
        buf = fp.read_bytes()
        f_md5 = hashlib.md5(buf).hexdigest().lower()
        fenster_anz, treffer = zaehle_treffer(buf, orig_win64)
        gesamt_treffer += treffer
        rel = str(fp.resolve().relative_to(PORT_DIR.resolve())) if fp.resolve().is_relative_to(PORT_DIR.resolve()) else fp.name
        report["files"][rel] = {
            "size": len(buf),
            "md5": f_md5,
            "windows": fenster_anz,
            "hits": treffer,
        }
        if fp.suffix.upper() in (".EXE", ".DLL") or treffer > 0:
            status = "OK (0 Treffer)" if treffer == 0 else f"FEHLER ({treffer} Treffer!)"
            print(f"  {rel:44s}: {len(buf):10,} Bytes | MD5 {f_md5} | {fenster_anz:10,} Fenster | {status}")

    report["total_hits"] = gesamt_treffer
    report["passed"] = (gesamt_treffer == 0)
    if args.json_out:
        args.json_out.write_text(json.dumps(report, indent=2), encoding="utf-8")

    print("")
    if gesamt_treffer == 0:
        print(f"ERGEBNIS: BESTANDEN (0 uebereinstimmende 64-Byte-Fenster in {len(files_to_check)} geprueften Dateien).")
        return 0
    else:
        print(f"ERGEBNIS: FEHLGESCHLAGEN ({gesamt_treffer} Treffer gefunden)!", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
