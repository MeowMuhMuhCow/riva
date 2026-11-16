#!/usr/bin/env python3
"""
mk_baupaket.py - Stellt Quelle/ (571 aktive C/C++-Einheiten + alle *.H Header)
                 sowie Bauen/baustand.tgz fuer das GitHub-Release zusammen.

WICHTIG:
  - Kopiert NUR die 571 aktiven C/C++-Einheiten gemaess Analyse/Phase4/teile_alle.tsv
    (Vorrangebene wie in gesamtbau.py: Quelle/cpp/p3/ vor Quelle/cpp/p1/).
  - Kopiert alle 21 Header (*.H inkl. R_FIX.H und R_PLOG.H) aus Quelle/cpp/
    sowie r_fix.inc aus Analyse/Bugs/FIX/inc/ nach Quelle/inc/.
  - Erzeugt Bauen/baustand.tgz aus Werkzeuge/werkbank_lokal/baum.tgz (die 1696
    aktiven Linkbaum-Module + RIVA.LNK + D22_GROUPS.json + D22_FRAGMENTS.json)
    samt den statischen Zuordnungstabellen onder meta/.

Standardmaessig laeuft das Skript im Pruefmodus (--dry-run) und gibt nur aus,
welche Dateien kopiert wuerden. Mit --ausfuehren wird tatsaechlich geschrieben.
"""

import argparse
import io
import json
import shutil
import sys
import tarfile
from pathlib import Path

RIVA_DIR = Path(__file__).resolve().parent.parent
PROJEKT = next(
    (p for p in RIVA_DIR.parents if (p / "Analyse" / "Phase4" / "teile_alle.tsv").is_file()),
    RIVA_DIR.parent.parent,
)
TEILE_TSV = PROJEKT / "Analyse" / "Phase4" / "teile_alle.tsv"
QUELLE_CPP = PROJEKT / "Quelle" / "cpp"
FIX_INC = PROJEKT / "Analyse" / "Bugs" / "FIX" / "inc"
BAUM_TGZ = PROJEKT / "Werkzeuge" / "werkbank_lokal" / "baum.tgz"
ZIEL_QUELLE = RIVA_DIR / "Quelle"
ZIEL_BAUSTAND = RIVA_DIR / "Bauen" / "baustand.tgz"

# Die 8 Hand-ASM-/Fremdcode-Anker in teile_alle.tsv
ANKER_EINHEITEN = {
    "fz_1788d0",
    "fz_17c708_t1",
    "fz_17c708_t2",
    "fz_17c708_t3",
    "fz_17e4a0_t2",
    "fz_199700_t1",
    "fz_199700_t2",
    "gz_0d451f_t1",
}


def lade_aktive_einheiten() -> list[tuple[int, str, str, str]]:
    einheiten = []
    for zeile in TEILE_TSV.read_text(encoding="utf-8").splitlines():
        zeile = zeile.strip()
        if not zeile:
            continue
        teile = zeile.split("\t")
        if len(teile) >= 4:
            einheiten.append((int(teile[0]), teile[1], teile[2], teile[3]))
    return einheiten


def finde_beste_quelle(unit: str) -> tuple[Path | None, str]:
    dateiname = f"{unit}_P1.CPP"
    for ebene in ("p3", "p1"):
        kandid = QUELLE_CPP / ebene / dateiname
        if kandid.is_file():
            return kandid, ebene
        ordner = QUELLE_CPP / ebene
        if ordner.is_dir():
            for p in ordner.iterdir():
                if p.is_file() and p.name.upper() == dateiname.upper():
                    return p, ebene
    return None, ""


def baue_baustand_tgz(ziel_tgz: Path) -> int:
    """Erzeugt Bauen/baustand.tgz mit dem schlanken D22-Basisbaum (m/) und den
    statischen Metadaten-Tabellen (meta/)."""
    ziel_tgz.parent.mkdir(parents=True, exist_ok=True)
    meta_quellen = {
        "meta/teile_alle.tsv": PROJEKT / "Analyse" / "Phase4" / "teile_alle.tsv",
        "meta/asm_verbucht.tsv": PROJEKT / "Analyse" / "Pass2" / "asm_verbucht.tsv",
        "meta/funktionen.tsv": PROJEKT / "Analyse" / "Zerlegung" / "funktionen.tsv",
        "meta/clobber.tsv": PROJEKT / "Analyse" / "Phase4" / "clobber.tsv",
        "meta/extra.map": PROJEKT / "Quelle" / "cpp" / "extra.map",
        "meta/EXTRA_MAP_NEU.txt": PROJEKT / "Analyse" / "Pass2" / "emu106" / "EXTRA_MAP_NEU.txt",
        "meta/libmap.json": PROJEKT / "Werkzeuge" / "cpp" / "libmap.json",
        "meta/map_module.json": PROJEKT / "Werkzeuge" / "cpp" / "linker_d22" / "diagnose" / "map_module.json",
    }
    for arcname, src in meta_quellen.items():
        if not src.is_file():
            raise FileNotFoundError(f"Benoetigte Metadatei fehlt: {src} ({arcname})")

    with tarfile.open(BAUM_TGZ, "r:gz") as src_tar:
        lnk_member = src_tar.getmember("m/RIVA.LNK")
        lnk_bytes = src_tar.extractfile(lnk_member).read()
        lnk_text = lnk_bytes.decode("latin1")
        aktive_module = {
            line[5:-4]
            for line in lnk_text.splitlines()
            if line.startswith("file ") and line.endswith(".OBJ")
        }
        wanted_m = {"m/RIVA.LNK", "m/D22_GROUPS.json", "m/D22_FRAGMENTS.json"} | {
            f"m/{mod}.OBJ" for mod in aktive_module
        }

        tmp_tgz = ziel_tgz.with_suffix(".tgz.tmp")
        with tarfile.open(tmp_tgz, "w:gz", compresslevel=6) as dst_tar:
            for member in src_tar.getmembers():
                if member.name in wanted_m and member.isfile():
                    data = src_tar.extractfile(member).read()
                    info = tarfile.TarInfo(name=member.name)
                    info.size = len(data)
                    info.mtime = member.mtime
                    info.mode = 0o644
                    dst_tar.addfile(info, io.BytesIO(data))
            for arcname, src_path in sorted(meta_quellen.items()):
                data = src_path.read_bytes()
                info = tarfile.TarInfo(name=arcname)
                info.size = len(data)
                info.mtime = int(src_path.stat().st_mtime)
                info.mode = 0o644
                dst_tar.addfile(info, io.BytesIO(data))
        tmp_tgz.replace(ziel_tgz)
    return len(aktive_module)


def main() -> int:
    ap = argparse.ArgumentParser(description="Stellt Quelle/ und Bauen/baustand.tgz fuer das GitHub-Release zusammen.")
    ap.add_argument(
        "--ausfuehren",
        action="store_true",
        help="Dateien tatsaechlich nach Quelle/ und Bauen/baustand.tgz schreiben (sonst nur Prueflauf)",
    )
    ap.add_argument(
        "--ohne-baustand",
        action="store_true",
        help="Bauen/baustand.tgz nicht neu packen",
    )
    args = ap.parse_args()

    einheiten = lade_aktive_einheiten()
    headers = sorted(QUELLE_CPP.glob("*.H"))
    r_fix_inc = FIX_INC / "r_fix.inc"

    cpp_quellen: list[tuple[str, Path, str]] = []
    anker_liste: list[str] = []
    fehlend: list[str] = []

    for _, unit, _, _ in einheiten:
        if unit in ANKER_EINHEITEN:
            anker_liste.append(unit)
            continue
        q, ebene = finde_beste_quelle(unit)
        if q is None:
            fehlend.append(unit)
        else:
            cpp_quellen.append((unit, q, ebene))

    p3_anz = sum(1 for _, _, e in cpp_quellen if e == "p3")
    p1_anz = sum(1 for _, _, e in cpp_quellen if e == "p1")

    print(f"Projekt-Wurzel:                       {PROJEKT}")
    print(f"Ziel-Paket:                           {RIVA_DIR}")
    print(f"Aktive Einheiten laut teile_alle.tsv: {len(einheiten)}")
    print(f"  - C/C++-Einheiten gefunden:         {len(cpp_quellen)} ({p3_anz} p3, {p1_anz} p1; Soll: 571)")
    print(f"  - Hand-ASM-/Anker-Einheiten:        {len(anker_liste)} (Soll: 8)")
    print(f"  - Gemeinsame Header in Quelle/cpp/: {len(headers)} (inkl. R_FIX.H, R_PLOG.H)")
    print(f"  - Zusatz-Schalterdatei r_fix.inc:   {'gefunden' if r_fix_inc.is_file() else 'FEHLT'}")

    if fehlend or not r_fix_inc.is_file():
        if fehlend:
            print(f"FEHLER: {len(fehlend)} Einheiten ohne Quelle: {fehlend}", file=sys.stderr)
        if not r_fix_inc.is_file():
            print(f"FEHLER: {r_fix_inc} nicht gefunden", file=sys.stderr)
        return 1

    if not args.ausfuehren:
        print("\n(Prueflauf abgeschlossen. Mit --ausfuehren werden die Dateien geschrieben.)")
        return 0

    ziel_inc = ZIEL_QUELLE / "inc"
    ziel_cpp = ZIEL_QUELLE / "cpp"
    ziel_inc.mkdir(parents=True, exist_ok=True)
    if ziel_cpp.exists():
        shutil.rmtree(ziel_cpp)
    ziel_cpp.mkdir(parents=True, exist_ok=True)

    # Vorhandene Header in Quelle/inc leeren (verhindert Gross-/Kleinschreibungsreste auf NTFS)
    for alt in list(ziel_inc.glob("*.[hH]*")) + list(ziel_inc.glob("*.inc")):
        if alt.is_file():
            alt.unlink()

    for h in headers:
        shutil.copy2(h, ziel_inc / h.name.upper())
    shutil.copy2(r_fix_inc, ziel_inc / "r_fix.inc")

    for unit, q, _ in cpp_quellen:
        shutil.copy2(q, ziel_cpp / f"{unit}_P1.CPP")

    print(f"[OK] {len(headers)} Header + r_fix.inc nach {ziel_inc} und {len(cpp_quellen)} C/C++-Einheiten nach {ziel_cpp} kopiert.")

    if not args.ohne_baustand:
        anz_obj = baue_baustand_tgz(ZIEL_BAUSTAND)
        groesse_mb = ZIEL_BAUSTAND.stat().st_size / (1024 * 1024)
        print(f"[OK] Bauen/baustand.tgz erzeugt ({anz_obj} Basis-OBJs + Metadaten, {groesse_mb:.2f} MB): {ZIEL_BAUSTAND}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
