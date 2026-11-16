#!/usr/bin/env python3
"""
mkfix.py - Pflegt die 52 Einzel-Schalter FIX_Rnnn fuer DSA 3: Schatten ueber Riva.

Standardmaessig prueft das Skript die 52 Schalter gegen Quelle/inc/r_fix.inc.
Mit --schreiben wird Quelle/inc/r_fix.inc neu geschrieben.

Stufen:
  - Stufe "A" ("wichtig"):  31 sichere Original-Bugs (-DFIX_BUGS=1, davon 2 Exploits: R042, R043)
  - Stufe "B" ("alles"):    21 weitere Korrekturen   (-DFIX_BUGS=2, davon 3 Exploits: R025, R037, R041)
  - exploit=True:           Bug zum Vorteil des Spielers (abschaltbar mit -DFIX_EXPLOITS=0)
"""

import argparse
from pathlib import Path

WURZEL = Path(__file__).resolve().parent.parent
INC_PFAD = WURZEL / "Quelle" / "inc" / "r_fix.inc"

# Liste aller 52 Einzel-Fixes (31 Stufe A, 21 Stufe B):
#   (Schaltername, Stufe "A"|"B", exploit_bool, Einheit/Funktion, Kurzbeschreibung)
FIX_LISTE: list[tuple[str, str, bool, str, str]] = [
    ("FIX_R001", "A", False, "gz_13bb70_t2 / f_13d5d0, f_13d920", "memset-Parameterreihenfolge (0, 12) statt (12, 0) vor DPMI-Interrupt 0x31"),
    ("FIX_R002", "A", False, "uvesa / f_13efd0, gz_13bb70_t2 / f_13d740, svga1_neu / f_11e760", "VESA-Bankwechsel nutzt immer WinASegment (s8) passend zu BL = 0; doppeltes memset entfernt; Nullpruefung vor Scanline-Division"),
    ("FIX_R003", "A", False, "cdaudio_t1 / CD::f_02ed35", "Rueckgabewert r = 0 initialisieren bei geschlossenem CD-Laufwerk"),
    ("FIX_R004", "A", False, "alloc_t1 / f_014540", "Nullsetzen ab Nutzdatenbeginn (blk + 4) statt vor dem \"GUYS\"-Header; Slot-Ueberlauf (i < 0) vor d_1bc614[i] abfangen"),
    ("FIX_R005", "A", False, "alfdisk / AL::f_0137e0, AL::f_013a80", "Puffergroesse mx ueber alle ngrp-Module bestimmen; c3e = -1 bei nicht neu geladenem p7e"),
    ("FIX_R006", "A", False, "ace_t1 / Ace::f_010a90, Ace::f_0110f0", "rec nach Freigabe nullen (kein Dangling-Pointer) und tab[100]-Grenzen pruefen"),
    ("FIX_R007", "B", False, "ace_t2a1 / f_011730", "Kapazitaetspruefung p2->n < p2->cap vor Eintrag ins ACE-Variablenregister"),
    ("FIX_R008", "A", False, "import_saveload / f_160790", "3D-Texturhoehe d->h = h statt w setzen und Mipmap-Verkleinerung ab Stufe 3 korrigieren"),
    ("FIX_R009", "A", False, "stock_neu / Stock::f_11c580", "Nullzeiger-Schutz beim Entfernen des letzten Listenelements (head == 0 -> tail = 0)"),
    ("FIX_R010", "A", False, "smith / f_10b0c0", "Waffen des ersten Schmieds nicht durch EOF-Kennung (-1) ueberschreiben beim Besuch des zweiten Schmieds"),
    ("FIX_R011", "A", False, "poolconv / f_0e0400", "Noch nicht fertigen Schmied-Auftrag per continue ueberspringen statt nachfolgende fertige Waffen per break abzuschneiden; tab freigeben"),
    ("FIX_R012", "A", False, "gz_040280 / f_041220", "Nullzeiger-Pruefung auf p1 bei Abbruch der Gruppenteilung"),
    ("FIX_R013", "B", False, "charact1 / f_044890, ch_skill / f_03ac50", "Copy-Paste-Ortspruefung d_1c2a80 == 0x30001 statt doppeltem 0x30000 bei LE-Regeneration und Talentprobe"),
    ("FIX_R014", "B", False, "gz_028190 / f_028190, f_0281d0, carrier / Car::f_027750", "Untergrenze s > 0 bzw. i > 0 fuer d_1a48f4 pruefen; Burg-Einmal-Flags d_1bc81c/d_1bc81d beim Reset nullen"),
    ("FIX_R015", "A", False, "import / f_0a2e30", "Sternenschweif-Stirnreif (0xd9, MR +2) beim Import auf Kopf-Slot 0 statt Brust-Slot 8 legen"),
    ("FIX_R016", "A", False, "amap_t12 / AMap::f_0156f0", "Array-Unterlauf sl[-1] abfangen, wenn keine Gruppe auf der Automap-Karte steht"),
    ("FIX_R017", "B", False, "amap_t345 / ContextAMap5::f_019fd0", "Bestehende Automap-Notiz nicht ueberschreiben, wenn alle 3x3-Nachbarfelder belegt sind"),
    ("FIX_R021", "A", False, "gz_032ab0 / f_032ab0, gz_0350b0_t1 / f_0352c0", "Giftladungen n2 = n3 beim Stapeln auf unvergiftete Projektile uebernehmen; Pluralpruefung beim Gegenstandstausch auf item_to statt item_from"),
    ("FIX_R025", "B", True,  "alchemy / f_012dd0, gz_0132a0 / f_0133b0", "Unterlauf work.tab[-1] bei Rezeptauswahl-Abbruch verhindern; Braudauer in Stunden statt Tagen gegen Reststunden pruefen; bei Scherzrezept 0x153 letzten Helden nicht entfernen"),
    ("FIX_R026", "A", False, "gz_038ba0_t1 / f_039cf0", "Klammerung !(f_043600(p1, i) % 12) bei Krankheits-Nachheilung (Dumpfschaedel heilt alle 12 Stunden aus)"),
    ("FIX_R027", "B", False, "gz_1099f0_t1 / f_109a50", "Feilschen-Rabatt vor Textausgabe auf 30 % deckeln und 32-Bit-Rabattbetrag ohne short-Abschnitt zurueckgeben"),
    ("FIX_R028", "B", False, "shop / f_1094e0, f_109800, gz_040280 / f_040cb0", "Negative Preise nach Feilschen abfangen und +1-Probenaufschlag bei 0 % Gebot weglassen"),
    ("FIX_R029", "B", False, "ch_level_t1 / Lv::f_037030, Lv::f_037140", "Keine Steigerungsversuche bei Zauber-/Talentwert >= 18 verbrauchen"),
    ("FIX_R030", "B", False, "fi_ini / f_077760", "Attackewert der Spiegelbilder im Magierturm (2 * Heldenstufe) bei 18 deckeln"),
    ("FIX_R033", "A", False, "gz_13bb70_t1 / f_13bc30, f_13cc50", "Keine Glasflasche aus Gegenstand 0x17 erzeugen; Expurgicum-Schaden auf Ziel statt Anwender anwenden"),
    ("FIX_R037", "B", True,  "shop / f_1094e0", "Bei vollem Inventar nach Einkauf vollen Kaufpreis statt halbem Wiederverkaufswert erstatten"),
    ("FIX_R038", "B", False, "chest / f_047420", "In Truhen nur stapelbare Gegenstaende (f_0a7950() != 0) zusammenfassen"),
    ("FIX_R039", "B", False, "fi_g_tar_t1 / f_074680, fi_g_tar_t2 / X::f_074b40", "Brettgrenzen 0..23 fuer das Zweitfeld zweifeldgrosser Kampfeinheiten vor G2V-Zugriff pruefen"),
    ("FIX_R040", "A", False, "fi_ac_co / f_06bdd0, f_06c380, f_06c930", "Geschoss-Schrittzahl mindestens 1; Obergrenze d_1bd924 < 20 bei Beschwoerung im Kampf pruefen"),
    ("FIX_R041", "B", True,  "spell / f_10ce80, gz_110d90 / f_111930, gz_10d6b0_t1 / f_10f910", "Zauber mit variablen Kosten erfordern mind. 1 AE; AE-Pruefung bei Karnifilo und Skelettarius/Untoten-Zauber vor Wirkung"),
    ("FIX_R042", "A", True,  "spell3_t1 / f_110200", "Hexenspeichel prueft verfuegbare AE gegen Heilungskosten (amount * 2) statt gegen Vorabwert -4"),
    ("FIX_R043", "A", True,  "gz_110d90 / f_111e00", "Armatrutz-Auswahlmenue bietet nur RS-Stufen an, deren AE-Kosten ((s + 1)^2) der Zaubernde bezahlen kann"),
    ("FIX_R044", "A", False, "gz_110d90 / f_111a80", "Axxeleratus bricht bei bereits aktivem Zauber sauber mit Kostenkennung -4 statt 0 ab"),
    ("FIX_R045", "A", False, "gz_112590 / f_1127e0", "Auswahlvariable initialisieren und Zauber sauber mit -4 abbrechen, wenn kein passender Gegenstand (0x41/0x19) vorhanden ist"),
    ("FIX_R047", "B", False, "spell3_t1 / f_10fc90", "Transversalis setzt bei verbotenem Ort Kostenkennung -4 statt 0 (verhindert doppelte Fehlermeldung)"),
    ("FIX_R049", "A", False, "gz_10d6b0_t1 / f_10dce0", "Destructibo prueft AE-Kosten vor dem Loeschen des Gegenstands statt danach"),
    ("FIX_R051", "B", False, "tower1_t2 / f_12ba70", "Teilgruppe am Gegenhebel im Magierturm nach dem Hebelkampf automatisch mit der Hauptgruppe auf Ebene 20 wiedervereinigen"),
    ("FIX_R052", "A", False, "mine1_t1 / f_0c0e30, Z832_c192", "Lorenfahrt in der Zwergenbinge auch dann mit Kampf und Schrankenoeffnung fortsetzen, wenn alle Helden die GE+8-Probe bestehen"),
    ("FIX_R053", "B", False, "char_opt / f_03f890", "NPC-Praesenzflag a nach NPC-Entlassung in der Schleife aktualisieren"),
    ("FIX_R054", "A", False, "gz_0c9940_t2 / f_0cab30", "Sinnesschaerfe-Probe meldet Warnung bei bestandener Probe (b == 1) statt bei misslungener (!b)"),
    ("FIX_R055", "A", False, "street / f_11e500, gz_11caf0_t12 / Context11CA493::f_11e350, f_11e380", "Schleife ueber Strassenbegegnungen von 1..20 statt 0..19 (20. Begegnung wird nicht mehr uebersprungen)"),
    ("FIX_R056", "A", False, "castle_t3 / f_02c9a0, f_02d230", "Seil-/Hebel-Flag d_1bc82c im else-Zweig auf 0 zuruecksetzen; Index -1 vor d_1a06a8-Zugriff abfangen"),
    ("FIX_R058", "A", False, "ship_t1 / f_0fbd80", "Zufallsobergrenze p4 in der Heldenschleife nicht mit dem ersten Zufallswert ueberschreiben"),
    ("FIX_R059", "B", False, "final2 / f_08e320, f_08fcc0", "Einmal-Trigger-Flag d_1bdb74 bei Feld 0x385 nach Ausloesen auf 1 setzen"),
    ("FIX_R068", "A", False, "tower3_t2 / f_130fd0", "Endlosschleife bei der Suche nach einem zweiten handlungsfaehigen Helden verhindern, wenn nur noch der Anfuehrer bei Bewusstsein ist"),
    ("FIX_R071", "B", False, "gz_08cb00 / f_08cd20, gz_08dae0_rand910a / f_08dae0", "Vorratszaehler d_1bdb20 vor der Nullpruefung dekrementieren, damit das Folge-Flag 0x1f41 gesetzt wird"),
    ("FIX_R072", "A", False, "gz_126c40 / f_126f80", "Kalender-Tagesueberlauf p1->b -= 30 (statt 30 - p1->b) und Monatsueberlauf p1->c -= 12 (statt -= 1)"),
    ("FIX_R074", "B", False, "dialog_t1 / f_055650", "In case 42/43 Nachbar-Flag d_1bc78c statt Kopierfehler d_1bc788 (aus case 40/41) pruefen"),
    ("FIX_R076", "B", False, "gz_0f25c0_t1 / f_0f2de0, sewerag1_neu / f_0f5110", "Flut-Trigger d_1c01a0 = 1 nach Truhe 0x489 in der Kanalisation unbedingt setzen und bei Gegenstandsentnahme res = 1 zurueckgeben"),
    ("FIX_R077", "B", False, "gz_0dc9a0_ta / f_0dc9a0", "Helden-Slots per memmove statt ueberlappendem memcpy nachruecken und aufeinanderfolgende Luecken erfassen"),
    ("FIX_R084", "A", False, "diary / f_057a00", "Tagebuch-Stichwort-ID als unsigned char (0..255) statt signed char lesen"),
    ("FIX_R092", "A", False, "lang_cze / f_0abc00, f_0abc30", "Nullzeiger-Aufruf strcat(p2, 0) entfernen"),
]


def erzeuge_r_fix_inc_text() -> str:
    zeilen = [
        "/* r_fix.inc - Einzelschalter fuer die Bugfix-Edition von Schatten ueber Riva",
        " *",
        " * Wird ausschliesslich von R_FIX.H eingebunden.",
        " *",
        " *   FIX_STUFE_A          Stufe A (WICHTIG + ALLES): Abstuerze, Haenger, kaputte Spielmechanik",
        " *   FIX_STUFE_A_EXPLOIT  Stufe A, aber mit -DFIX_EXPLOITS=0 abschaltbar",
        " *   FIX_STUFE_B          Stufe B (nur ALLES): kleinere Logik-, Anzeige- und Randfallfehler",
        " *   FIX_STUFE_B_EXPLOIT  Stufe B, aber mit -DFIX_EXPLOITS=0 abschaltbar",
        " *",
        " * Jeder Schalter ist mit #ifndef geschuetzt, damit einzelne Fixes per -DFIX_Rnnn=0",
        " * oder -DFIX_Rnnn=1 auf der Kommandozeile ueberschrieben werden koennen.",
        " */",
        "",
    ]
    for name, stufe, exploit, datei, beschr in FIX_LISTE:
        if stufe == "A":
            makro = "FIX_STUFE_A_EXPLOIT" if exploit else "FIX_STUFE_A"
        else:
            makro = "FIX_STUFE_B_EXPLOIT" if exploit else "FIX_STUFE_B"
        zeilen.append(f"/* {name.replace('FIX_', '')}: {datei} - {beschr} */")
        zeilen.append(f"#ifndef {name}")
        zeilen.append(f"#define {name} {makro}")
        zeilen.append("#endif")
        zeilen.append("")
    return "\n".join(zeilen)


def main() -> int:
    ap = argparse.ArgumentParser(description="Prueft oder erzeugt Quelle/inc/r_fix.inc (52 Bugfix-Schalter).")
    ap.add_argument("--schreiben", action="store_true", help="Quelle/inc/r_fix.inc tatsaechlich neu schreiben")
    args = ap.parse_args()

    anz_a = sum(1 for _, s, _, _, _ in FIX_LISTE if s == "A")
    anz_b = sum(1 for _, s, _, _, _ in FIX_LISTE if s == "B")
    anz_ex = sum(1 for _, _, ex, _, _ in FIX_LISTE if ex)
    print(f"FIX_LISTE: {len(FIX_LISTE)} Schalter ({anz_a} Stufe A, {anz_b} Stufe B, davon {anz_ex} Exploits)")

    if args.schreiben:
        INC_PFAD.parent.mkdir(parents=True, exist_ok=True)
        INC_PFAD.write_text(erzeuge_r_fix_inc_text(), encoding="utf-8")
        print(f"[OK] {INC_PFAD} aktualisiert ({len(FIX_LISTE)} Schalter).")
    else:
        print(f"(Pruefmodus. Mit --schreiben wird {INC_PFAD} neu erzeugt.)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
