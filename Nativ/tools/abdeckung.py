#!/usr/bin/env python3
"""
abdeckung.py - Auswertungswerkzeug fuer die Laufzeit-Funktionsabdeckung (RIVA_ABDECKUNG=1)
des nativen Windows-Ports von DSA 3: Schatten ueber Riva.

Liest Port/build/abdeckung.tsv sowie Port/src/manifest.json und die Port-Quellen
und zeigt, welche f_xxxxxx-Funktionen und Einheiten bereits liefen bzw. noch nie liefen.
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
PORT_DIR = HERE.parent


def collect_units_and_funcs() -> tuple[dict[str, list[str]], dict[str, str]]:
    manifest_path = PORT_DIR / "src" / "manifest.json"
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    unit_to_funcs: dict[str, list[str]] = {}
    func_to_unit: dict[str, str] = {}

    cpp_dir = PORT_DIR / "src" / "cpp"
    for u in manifest.get("units", []):
        unit = u["unit"]
        cpp_file = cpp_dir / f"{unit}_P1.CPP"
        funcs: list[str] = []
        if cpp_file.exists():
            txt = cpp_file.read_text(encoding="utf-8", errors="ignore")
            for m in re.finditer(r"//@\s*(f_[0-9a-fA-F]{6})\b", txt):
                fn = m.group(1).lower()
                if fn not in funcs:
                    funcs.append(fn)
                    func_to_unit[fn] = unit
            if not funcs:
                for m in re.finditer(r"\b(f_[0-9a-fA-F]{6})\s*\(", txt):
                    fn = m.group(1).lower()
                    if fn not in funcs:
                        funcs.append(fn)
                        func_to_unit.setdefault(fn, unit)
        unit_to_funcs[unit] = funcs

    for plat_unit, plat_path in [
        ("riva_3d_brender", PORT_DIR / "platform" / "riva_3d_brender.cpp"),
        ("riva_crt_and_stubs", PORT_DIR / "platform" / "riva_crt_and_stubs.cpp"),
    ]:
        funcs = []
        if plat_path.exists():
            txt = plat_path.read_text(encoding="utf-8", errors="ignore")
            for m in re.finditer(r"\b(f_[0-9a-fA-F]{6})\s*\([^;{}]*\)\s*\{", txt, re.S):
                fn = m.group(1).lower()
                if fn not in funcs:
                    funcs.append(fn)
                    func_to_unit[fn] = plat_unit
        unit_to_funcs[plat_unit] = funcs

    return unit_to_funcs, func_to_unit


def load_covered(tsv_path: Path) -> dict[str, int]:
    covered: dict[str, int] = {}
    if not tsv_path.exists():
        return covered
    for line in tsv_path.read_text(encoding="utf-8", errors="ignore").splitlines():
        line = line.strip()
        if not line or line.startswith("#") or line.startswith("fkt"):
            continue
        parts = line.split("\t")
        fn = parts[0].strip().lower()
        if fn.startswith("_"):
            fn = fn[1:]
        ms = int(parts[1]) if len(parts) > 1 and parts[1].isdigit() else 0
        if fn not in covered:
            covered[fn] = ms
    return covered


def main() -> int:
    ap = argparse.ArgumentParser(description="Wertet Port/build/abdeckung.tsv aus.")
    ap.add_argument(
        "--tsv",
        type=Path,
        default=PORT_DIR / "build" / "abdeckung.tsv",
        help="Pfad zu abdeckung.tsv (Standard: Port/build/abdeckung.tsv)",
    )
    ap.add_argument(
        "--alle-ungetestet",
        action="store_true",
        help="Listet alle Einheiten auf, die noch nie liefen.",
    )
    args = ap.parse_args()

    unit_to_funcs, func_to_unit = collect_units_and_funcs()
    covered = load_covered(args.tsv)

    total_units = len(unit_to_funcs)
    total_funcs = sum(len(v) for v in unit_to_funcs.values())

    active_units = []
    inactive_units = []
    covered_known_funcs = 0

    for unit, funcs in sorted(unit_to_funcs.items()):
        hit = [f for f in funcs if f in covered]
        covered_known_funcs += len(hit)
        if hit:
            active_units.append((unit, len(hit), len(funcs)))
        else:
            inactive_units.append((unit, len(funcs)))

    print("========================================================================")
    print("DSA 3: Schatten ueber Riva - Laufzeit-Abdeckungsbericht (abdeckung.py)")
    print("========================================================================")
    print(f"Quelle:               {args.tsv}")
    print(f"Gelaufene f_-Aufrufe: {len(covered)} eindeutige Funktionen in abdeckung.tsv")
    print(
        f"Bekannte Funktionen:  {covered_known_funcs} / {total_funcs} "
        f"({(100.0 * covered_known_funcs / max(1, total_funcs)):.1f} %)"
    )
    print(
        f"Erreichte Einheiten:  {len(active_units)} / {total_units} "
        f"({(100.0 * len(active_units) / max(1, total_units)):.1f} %)"
    )
    print(f"Noch nie gelaufen:    {len(inactive_units)} Einheiten")
    print("------------------------------------------------------------------------")
    print("Top 25 aktive Einheiten:")
    for unit, nhit, ntot in sorted(active_units, key=lambda x: (-x[1], x[0]))[:25]:
        print(f"  {unit:<24} {nhit:3d} / {ntot:3d} Funktionen ({100.0 * nhit / max(1, ntot):5.1f} %)")

    print("------------------------------------------------------------------------")
    limit = len(inactive_units) if args.alle_ungetestet else 30
    print(f"Einheiten, die noch nie liefen (zeige {min(limit, len(inactive_units))} von {len(inactive_units)}):")
    for unit, ntot in inactive_units[:limit]:
        print(f"  {unit:<24} (0 / {ntot} Funktionen)")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
