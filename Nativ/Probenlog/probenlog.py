#!/usr/bin/env python3
"""
probenlog.py - Live-Anzeige fuer PROBEN.CSV im Terminal (Linux / macOS / Windows).

Plattformunabhaengiges Gegenstueck zu Probenlog/probenlog_fenster.ps1.
Liest fortlaufend neue Zeilen aus PROBEN.CSV (Codepage 437) und gibt Talent-,
Zauber-, Eigenschafts- und Kampfproben farbig formatiert im Terminal aus.

Aufruf:
    python3 Probenlog/probenlog.py PROBEN.CSV
"""

import sys
import time
from pathlib import Path

# ANSI-Farbcodes
C_RESET   = "\033[0m"
C_CYAN    = "\033[36m"
C_GRAY    = "\033[90m"
C_GREEN   = "\033[32m"
C_RED     = "\033[31m"
C_YELLOW  = "\033[33m"
C_MAGENTA = "\033[35m"

ATTR_NAMEN = [
    "MU", "KL", "CH", "FF", "GE", "IN", "KK",
    "AG", "HA", "RA", "GG", "TA", "NG", "JZ",
]

TALENT_NAMEN = [
    "Waffenlos", "Hiebwaffen", "Stichwaffen", "Schwerter", "Äxte",
    "Speere", "Zweihänder", "Schusswaffen", "Wurfwaffen", "Akrobatik",
    "Klettern", "Körperbeh.", "Reiten", "Schleichen", "Schwimmen",
    "Selbstbeh.", "Tanzen", "Verstecken", "Zechen", "Bekehren",
    "Betören", "Feilschen", "Gassenwissen", "Lügen", "Menschenkenntnis",
    "Schätzen", "Fährtensuchen", "Fesseln", "Orientierung", "Pflanzenkunde",
    "Tierkunde", "Wildnisleben", "Alchimie", "Alte Sprachen", "Geographie",
    "Geschichte", "Götter/Kulte", "Kriegskunst", "Lesen", "Magiekunde",
    "Sprachen", "Abrichten", "Fahrzeuge", "Falschspiel", "Heilk. Gift",
    "Heilk. Krankh.", "Heilk. Wunden", "Musizieren", "Schlösser", "Taschendiebstahl",
    "Gefahreninstinkt", "Sinnesschärfe",
]

ZAUBER_NAMEN = [
    "-",
    "Beherrschung brechen", "Destructibo", "Gardianum", "Illusionen zerstören", "Verwandlung beenden",
    "Band und Fessel", "Bannbaladin", "Böser Blick", "Große Gier", "Große Verwirrung",
    "Herr über das Tierreich", "Horriphobus", "Magischer Raub", "Respondami", "Sanftmut",
    "Somnigravis", "Zwingtanz",
    "Furor Blut", "Geister bannen", "Geister rufen", "Heptagon", "Krähenruf", "Skelettarius",
    "Elementar beschwören", "Nihilogravo", "Solidirid",
    "Axxeleratus", "Foramen", "Motoricus", "Spurlos", "Transversalis", "Über Eis",
    "Balsam", "Hexenspeichel", "Klarum Purum", "Ruhe Körper", "Tiere heilen",
    "Adleraug", "Analüs", "Eigenschaften seid gelesen", "Exposami", "Odem Arcanum", "Penetrizzel", "Sensibar",
    "Chamaelioni", "Duplicatus", "Harmlose Gestalt", "Hexenknoten",
    "Blitz dich find", "Ecliptifactus", "Eisenrost", "Fulminictus", "Ignifaxius", "Plumbumbarum", "Radau", "Saft Kraft", "Scharfes Auge",
    "Hexenblick", "Nekropathia",
    "Adler Wolf", "Arcano Psychostabilis", "Armatrutz", "CH steigern", "Feuerbann", "FF steigern", "GE steigern", "IN steigern", "KK steigern", "KL steigern", "MU steigern", "Mutabili", "Paralü", "Salander", "See und Fluss", "Visibili",
    "Abvenenum", "Aeolitus", "Brenne toter Stoff", "Claudibus", "Dunkelheit", "Erstarre", "Flim Flam", "Schmelze", "Silentium", "Sturmgebrüll",
]


def attr_name(idx: int) -> str:
    return ATTR_NAMEN[idx] if 0 <= idx < len(ATTR_NAMEN) else f"A{idx}"


def talent_name(idx: int) -> str:
    return TALENT_NAMEN[idx] if 0 <= idx < len(TALENT_NAMEN) else f"Talent #{idx}"


def zauber_name(idx: int) -> str:
    return ZAUBER_NAMEN[idx] if 0 <= idx < len(ZAUBER_NAMEN) else f"Zauber #{idx}"


def mod_text(m: int) -> str:
    return f"+{m}" if m > 0 else f"{m}"


def format_zeile(zeile: str) -> None:
    t = zeile.split(";")
    if len(t) < 2:
        return
    typ = t[0]
    held = t[1].strip() or "(Held)"

    try:
        if typ == "T" and len(t) >= 15:
            nr, tw, mod = int(t[2]), int(t[3]), int(t[4])
            a1, v1, w1 = attr_name(int(t[5])), t[6], int(t[7])
            a2, v2, w2 = attr_name(int(t[8])), t[9], int(t[10])
            a3, v3, w3 = attr_name(int(t[11])), t[12], int(t[13])
            erg = int(t[14])
            name = talent_name(nr)
            info = (f"[Talent] {held:<10} {name:<16} ({a1} {v1}/{a2} {v2}/{a3} {v3}) "
                    f"TW {tw:2d} Mod {mod_text(mod):>3} -> [{w1:2d}, {w2:2d}, {w3:2d}] ")
            if erg == 99:
                print(f"{info}{C_YELLOW}GLÜCKLICH (Doppel-1!){C_RESET}", flush=True)
            elif erg <= -98:
                print(f"{info}{C_MAGENTA}PATZER (Doppel-20!){C_RESET}", flush=True)
            elif erg > 0:
                print(f"{info}{C_GREEN}OK (Rest +{erg - 1}){C_RESET}", flush=True)
            else:
                print(f"{info}{C_RED}MISS{C_RESET}", flush=True)

        elif typ == "Z" and len(t) >= 15:
            nr, zw, mod = int(t[2]), int(t[3]), int(t[4])
            a1, v1, w1 = attr_name(int(t[5])), t[6], int(t[7])
            a2, v2, w2 = attr_name(int(t[8])), t[9], int(t[10])
            a3, v3, w3 = attr_name(int(t[11])), t[12], int(t[13])
            erg = int(t[14])
            name = zauber_name(nr)
            info = (f"[Zauber] {held:<10} {name:<20} ({a1} {v1}/{a2} {v2}/{a3} {v3}) "
                    f"ZW {zw:2d} Mod {mod_text(mod):>3} -> [{w1:2d}, {w2:2d}, {w3:2d}] ")
            if erg == 99:
                print(f"{info}{C_YELLOW}GLÜCKLICH (Doppel-1!){C_RESET}", flush=True)
            elif erg <= -98:
                print(f"{info}{C_MAGENTA}PATZER (Doppel-20!){C_RESET}", flush=True)
            elif erg > 0:
                print(f"{info}{C_GREEN}OK (Rest +{erg - 1}){C_RESET}", flush=True)
            else:
                print(f"{info}{C_RED}MISS{C_RESET}", flush=True)

        elif typ == "A" and len(t) >= 7:
            a = attr_name(int(t[2]))
            wert, mod, w, erg = int(t[3]), int(t[4]), int(t[5]), int(t[6])
            ziel = wert - mod
            info = f"[Attr]   {held:<10} {a} {wert:2d} (Mod {mod_text(mod):>3}, Ziel <={ziel:2d}) -> W20 = {w:2d}  "
            if erg > 0:
                print(f"{info}{C_GREEN}OK (Diff +{erg}){C_RESET}", flush=True)
            else:
                print(f"{info}{C_RED}MISS (Diff {erg}){C_RESET}", flush=True)

        elif typ in ("AT", "PA", "FK") and len(t) >= 6:
            ziel, mod, w, erg = int(t[2]), int(t[3]), int(t[4]), int(t[5])
            info = f"[{typ:<2}]     {held:<10} Ziel {ziel:2d} (Mod {mod_text(mod):>3}) -> W20 = {w:2d}  "
            if erg >= 2:
                print(f"{info}{C_YELLOW}KRITISCHER TREFFER!{C_RESET}", flush=True)
            elif erg == 1:
                print(f"{info}{C_GREEN}OK{C_RESET}", flush=True)
            elif erg <= -1:
                print(f"{info}{C_MAGENTA}PATZER!{C_RESET}", flush=True)
            else:
                print(f"{info}{C_RED}FEHL{C_RESET}", flush=True)
    except ValueError:
        pass


def finde_csv(ziel_pfad: Path) -> Path | None:
    if ziel_pfad.is_file():
        return ziel_pfad
    ordner = ziel_pfad.parent
    if ordner.is_dir():
        ziel_name = ziel_pfad.name.lower()
        for kind in ordner.iterdir():
            if kind.is_file() and kind.name.lower() == ziel_name:
                return kind
    return None


def main() -> int:
    if len(sys.argv) < 2:
        print(f"Aufruf: {sys.argv[0]} <Pfad/zu/PROBEN.CSV>", file=sys.stderr)
        return 1

    csv_soll = Path(sys.argv[1])
    print(f"{C_CYAN}=============================================================================={C_RESET}")
    print(f"{C_CYAN}  DSA Schatten über Riva – Live-Probenlog{C_RESET}")
    print(f"{C_GRAY}  Datei: {csv_soll}{C_RESET}")
    print(f"{C_GRAY}  (Wartet auf die erste Probe im Spiel... Beenden mit Strg+C){C_RESET}")
    print(f"{C_CYAN}=============================================================================={C_RESET}\n", flush=True)

    pos = 0
    try:
        while True:
            gef = finde_csv(csv_soll)
            if gef is not None:
                try:
                    groesse = gef.stat().st_size
                    if groesse < pos:
                        pos = 0
                    if groesse > pos:
                        with open(gef, "rb") as f:
                            f.seek(pos)
                            daten = f.read()
                            pos = f.tell()
                        text = daten.decode("cp437", errors="replace")
                        for z in text.splitlines():
                            if z.strip():
                                format_zeile(z.strip())
                except OSError:
                    pass
            time.sleep(0.2)
    except KeyboardInterrupt:
        return 0


if __name__ == "__main__":
    sys.exit(main())
