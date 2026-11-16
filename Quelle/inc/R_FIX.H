/* R_FIX.H - erzeugt aus Analyse/Bugs/FIX/inc/r_fix.h + r_fix.inc (bau_header.py). Aenderungen dort machen. */
/* ============================================================================
 * r_fix.h - Zentrale Schalter fuer optionale Fehlerkorrekturen (Schatten ueber Riva)
 *
 * Standard (ohne Schalter):
 *   FIX_BUGS == 0 -> 100 % Originalverhalten von 1997 (V1.12), Byte-fuer-Byte
 *                    identische RIVA.EXE (MD5 fb8f5fc3ba5454c7344c17aaf362de35).
 *
 * Zwei Stufen fuer fehlerbereinigte Builds:
 *   -DFIX_BUGS=1  -> Stufe A ("WICHTIG", empfohlen):
 *                    Nur 100 % sichere Original-Programmierfehler (Tippfehler,
 *                    Vorzeichen-/Ueberlauffehler, falsche Offsets, Abstuerze),
 *                    bei denen die Entwicklerabsicht im Code selbst belegt ist.
 *                    Erzeugt: Build\RIVA_FIX_WICHTIG.EXE
 *
 *   -DFIX_BUGS=2  -> Stufe B ("ALLES"):
 *                    Enthaelt Stufe A plus alle weiteren Korrekturen.
 *                    Erzeugt: Build\RIVA_FIX_ALLES.EXE
 *
 * Zusatzschalter fuer Exploits zum Vorteil des Spielers:
 *   -DFIX_EXPLOITS=0 -> Bugs, die dem Spieler einen Vorteil verschaffen,
 *                       bleiben wie im Original von 1997 erhalten.
 *                       (Standard im Fix-Modus ist FIX_EXPLOITS=1.)
 *
 * Einzelsteuerung:
 *   Jeder Fix hat einen eigenen Schalter FIX_Rnnn (siehe r_fix.inc und
 *   Bauen/FIXES.md), der per -DFIX_R001=0 oder -DFIX_R001=1 einzeln
 *   aus- oder eingeschaltet werden kann.
 * ============================================================================ */

#ifndef RIVA_FIX_H
#define RIVA_FIX_H

#ifndef FIX_BUGS
#define FIX_BUGS 0
#endif

#ifndef FIX_EXPLOITS
#define FIX_EXPLOITS 1
#endif

/* Hilfsmakros fuer die beiden Stufen (mit optionalem Exploit-Filter) */
#define FIX_STUFE_A          (FIX_BUGS >= 1)
#define FIX_STUFE_A_EXPLOIT  ((FIX_BUGS >= 1) && (FIX_EXPLOITS != 0))
#define FIX_STUFE_B          (FIX_BUGS >= 2)
#define FIX_STUFE_B_EXPLOIT  ((FIX_BUGS >= 2) && (FIX_EXPLOITS != 0))

/* Einzel-Schalter FIX_Rnnn (automatisch gepflegt durch Werkzeuge/mkfix.py) */
/* ---- Einzelschalter (aus r_fix.inc) ---- */
/* r_fix.inc - Einzelschalter fuer die Bugfix-Edition von Schatten ueber Riva
 *
 * Zusammengefuehrt aus r_fix_K41.inc und r_fix_K42.inc (Stand 15.11.2026, K45).
 * Wird ausschliesslich von r_fix.h eingebunden.
 *
 *   FIX_STUFE_A          Stufe A (WICHTIG + ALLES): Abstuerze, Haenger, kaputte Spielmechanik
 *   FIX_STUFE_A_EXPLOIT  Stufe A, aber mit RIVA_EXPLOITS_LASSEN abschaltbar
 *   FIX_STUFE_B          Stufe B (nur ALLES): kleinere Logik-, Anzeige- und Randfallfehler
 *   FIX_STUFE_B_EXPLOIT  Stufe B, aber mit RIVA_EXPLOITS_LASSEN abschaltbar
 *
 * Jeder Schalter ist mit #ifndef geschuetzt, damit einzelne Fixes per -DFIX_Rnnn=0
 * oder -DFIX_Rnnn=1 auf der Kommandozeile ueberschrieben werden koennen.
 */

/* R001: gz_13bb70_t2 / f_13d5d0, f_13d920 - memset-Parameterreihenfolge (0, 12) statt (12, 0) vor DPMI-Interrupt 0x31 */
#ifndef FIX_R001
#define FIX_R001 FIX_STUFE_A
#endif

/* R002: uvesa / f_13efd0, gz_13bb70_t2 / f_13d740, svga1_neu / f_11e760 - VESA-Bankwechsel nutzt immer WinASegment (s8) passend zu BL = 0; doppeltes memset entfernt; Nullpruefung vor Scanline-Division */
#ifndef FIX_R002
#define FIX_R002 FIX_STUFE_A
#endif

/* R003: cdaudio_t1 / CD::f_02ed35 - Rueckgabewert r = 0 initialisieren bei geschlossenem CD-Laufwerk */
#ifndef FIX_R003
#define FIX_R003 FIX_STUFE_A
#endif

/* R004: alloc_t1 / f_014540 - Nullsetzen ab Nutzdatenbeginn (blk + 4) statt vor dem "GUYS"-Header; Slot-Ueberlauf (i < 0) vor d_1bc614[i] abfangen */
#ifndef FIX_R004
#define FIX_R004 FIX_STUFE_A
#endif

/* R005: alfdisk / AL::f_0137e0, AL::f_013a80 - Puffergroesse mx ueber alle ngrp-Module bestimmen; c3e = -1 bei nicht neu geladenem p7e */
#ifndef FIX_R005
#define FIX_R005 FIX_STUFE_A
#endif

/* R006: ace_t1 / Ace::f_010a90, Ace::f_0110f0 - rec nach Freigabe nullen (kein Dangling-Pointer) und tab[100]-Grenzen pruefen */
#ifndef FIX_R006
#define FIX_R006 FIX_STUFE_A
#endif

/* R007: ace_t2a1 / f_011730 - Kapazitaetspruefung p2->n < p2->cap vor Eintrag ins ACE-Variablenregister */
#ifndef FIX_R007
#define FIX_R007 FIX_STUFE_B
#endif

/* R008: import_saveload / f_160790 - 3D-Texturhoehe d->h = h statt w setzen und Mipmap-Verkleinerung ab Stufe 3 korrigieren */
#ifndef FIX_R008
#define FIX_R008 FIX_STUFE_A
#endif

/* R009: stock_neu / Stock::f_11c580 - Nullzeiger-Schutz beim Entfernen des letzten Listenelements (head == 0 -> tail = 0) */
#ifndef FIX_R009
#define FIX_R009 FIX_STUFE_A
#endif

/* R010: smith / f_10b0c0 - Waffen des ersten Schmieds nicht durch EOF-Kennung (-1) ueberschreiben beim Besuch des zweiten Schmieds */
#ifndef FIX_R010
#define FIX_R010 FIX_STUFE_A
#endif

/* R011: poolconv / f_0e0400 - Noch nicht fertigen Schmied-Auftrag per continue ueberspringen statt nachfolgende fertige Waffen per break abzuschneiden; tab freigeben */
#ifndef FIX_R011
#define FIX_R011 FIX_STUFE_A
#endif

/* R012: gz_040280 / f_041220 - Nullzeiger-Pruefung auf p1 bei Abbruch der Gruppenteilung */
#ifndef FIX_R012
#define FIX_R012 FIX_STUFE_A
#endif

/* R013: charact1 / f_044890, ch_skill / f_03ac50 - Copy-Paste-Ortspruefung d_1c2a80 == 0x30001 statt doppeltem 0x30000 bei LE-Regeneration und Talentprobe */
#ifndef FIX_R013
#define FIX_R013 FIX_STUFE_B
#endif

/* R014: gz_028190 / f_028190, f_0281d0, carrier / Car::f_027750 - Untergrenze s > 0 bzw. i > 0 fuer d_1a48f4 pruefen; Burg-Einmal-Flags d_1bc81c/d_1bc81d beim Reset nullen */
#ifndef FIX_R014
#define FIX_R014 FIX_STUFE_B
#endif

/* R015: import / f_0a2e30 - Sternenschweif-Stirnreif (0xd9, MR +2) beim Import auf Kopf-Slot 0 statt Brust-Slot 8 legen */
#ifndef FIX_R015
#define FIX_R015 FIX_STUFE_A
#endif

/* R016: amap_t12 / AMap::f_0156f0 - Array-Unterlauf sl[-1] abfangen, wenn keine Gruppe auf der Automap-Karte steht */
#ifndef FIX_R016
#define FIX_R016 FIX_STUFE_A
#endif

/* R017: amap_t345 / ContextAMap5::f_019fd0 - Bestehende Automap-Notiz nicht ueberschreiben, wenn alle 3x3-Nachbarfelder belegt sind */
#ifndef FIX_R017
#define FIX_R017 FIX_STUFE_B
#endif

/* R021: gz_032ab0 / f_032ab0, gz_0350b0_t1 / f_0352c0 - Giftladungen n2 = n3 beim Stapeln auf unvergiftete Projektile uebernehmen; Pluralpruefung beim Gegenstandstausch auf item_to statt item_from */
#ifndef FIX_R021
#define FIX_R021 FIX_STUFE_A
#endif

/* R025: alchemy / f_012dd0, gz_0132a0 / f_0133b0 - Unterlauf work.tab[-1] bei Rezeptauswahl-Abbruch verhindern; Braudauer in Stunden statt Tagen gegen Reststunden pruefen; bei Scherzrezept 0x153 letzten Helden nicht entfernen */
#ifndef FIX_R025
#define FIX_R025 FIX_STUFE_B_EXPLOIT
#endif

/* R026: gz_038ba0_t1 / f_039cf0 - Klammerung !(f_043600(p1, i) % 12) bei Krankheits-Nachheilung (Dumpfschaedel heilt alle 12 Stunden aus) */
#ifndef FIX_R026
#define FIX_R026 FIX_STUFE_A
#endif

/* R027: gz_1099f0_t1 / f_109a50 - Feilschen-Rabatt vor Textausgabe auf 30 % deckeln und 32-Bit-Rabattbetrag ohne short-Abschnitt zurueckgeben */
#ifndef FIX_R027
#define FIX_R027 FIX_STUFE_B
#endif

/* R028: shop / f_1094e0, f_109800, gz_040280 / f_040cb0 - Negative Preise nach Feilschen abfangen und +1-Probenaufschlag bei 0 % Gebot weglassen */
#ifndef FIX_R028
#define FIX_R028 FIX_STUFE_B
#endif

/* R029: ch_level_t1 / Lv::f_037030, Lv::f_037140 - Keine Steigerungsversuche bei Zauber-/Talentwert >= 18 verbrauchen */
#ifndef FIX_R029
#define FIX_R029 FIX_STUFE_B
#endif

/* R030: fi_ini / f_077760 - Attackewert der Spiegelbilder im Magierturm (2 * Heldenstufe) bei 18 deckeln */
#ifndef FIX_R030
#define FIX_R030 FIX_STUFE_B
#endif

/* R033: gz_13bb70_t1 / f_13bc30, f_13cc50 - Keine Glasflasche aus Gegenstand 0x17 erzeugen; Expurgicum-Schaden auf Ziel statt Anwender anwenden */
#ifndef FIX_R033
#define FIX_R033 FIX_STUFE_A
#endif

/* R037: shop / f_1094e0 - Bei vollem Inventar nach Einkauf vollen Kaufpreis statt halbem Wiederverkaufswert erstatten */
#ifndef FIX_R037
#define FIX_R037 FIX_STUFE_B_EXPLOIT
#endif

/* R038: chest / f_047420 - In Truhen nur stapelbare Gegenstaende (f_0a7950() != 0) zusammenfassen */
#ifndef FIX_R038
#define FIX_R038 FIX_STUFE_B
#endif

/* R039: fi_g_tar_t1 / f_074680, fi_g_tar_t2 / X::f_074b40 - Brettgrenzen 0..23 fuer das Zweitfeld zweifeldgrosser Kampfeinheiten vor G2V-Zugriff pruefen */
#ifndef FIX_R039
#define FIX_R039 FIX_STUFE_B
#endif

/* R040: fi_ac_co / f_06bdd0, f_06c380, f_06c930 - Geschoss-Schrittzahl mindestens 1; Obergrenze d_1bd924 < 20 bei Beschwoerung im Kampf pruefen */
#ifndef FIX_R040
#define FIX_R040 FIX_STUFE_A
#endif

/* R041: spell / f_10ce80, gz_110d90 / f_111930, gz_10d6b0_t1 / f_10f910 - Zauber mit variablen Kosten erfordern mind. 1 AE; AE-Pruefung bei Karnifilo und Skelettarius/Untoten-Zauber vor Wirkung */
#ifndef FIX_R041
#define FIX_R041 FIX_STUFE_B_EXPLOIT
#endif

/* R042: spell3_t1 / f_110200 - Hexenspeichel prueft verfuegbare AE gegen Heilungskosten (amount * 2) statt gegen Vorabwert -4 */
#ifndef FIX_R042
#define FIX_R042 FIX_STUFE_A_EXPLOIT
#endif

/* R043: gz_110d90 / f_111e00 - Armatrutz-Auswahlmenue bietet nur RS-Stufen an, deren AE-Kosten ((s + 1)^2) der Zaubernde bezahlen kann */
#ifndef FIX_R043
#define FIX_R043 FIX_STUFE_A_EXPLOIT
#endif

/* R044: gz_110d90 / f_111a80 - Axxeleratus bricht bei bereits aktivem Zauber sauber mit Kostenkennung -4 statt 0 ab */
#ifndef FIX_R044
#define FIX_R044 FIX_STUFE_A
#endif

/* R045: gz_112590 / f_1127e0 - Auswahlvariable initialisieren und Zauber sauber mit -4 abbrechen, wenn kein passender Gegenstand (0x41/0x19) vorhanden ist */
#ifndef FIX_R045
#define FIX_R045 FIX_STUFE_A
#endif

/* R047: spell3_t1 / f_10fc90 - Transversalis setzt bei verbotenem Ort Kostenkennung -4 statt 0 (verhindert doppelte Fehlermeldung) */
#ifndef FIX_R047
#define FIX_R047 FIX_STUFE_B
#endif

/* R049: gz_10d6b0_t1 / f_10dce0 - Destructibo prueft AE-Kosten vor dem Loeschen des Gegenstands statt danach */
#ifndef FIX_R049
#define FIX_R049 FIX_STUFE_A
#endif

/* R051: tower1_t2 / f_12ba70 - Teilgruppe am Gegenhebel im Magierturm nach dem Hebelkampf automatisch mit der Hauptgruppe auf Ebene 20 wiedervereinigen */
#ifndef FIX_R051
#define FIX_R051 FIX_STUFE_B
#endif

/* R052: mine1_t1 / f_0c0e30, Z832_c192 - Lorenfahrt in der Zwergenbinge auch dann mit Kampf und Schrankenoeffnung fortsetzen, wenn alle Helden die GE+8-Probe bestehen */
#ifndef FIX_R052
#define FIX_R052 FIX_STUFE_A
#endif

/* R053: char_opt / f_03f890 - NPC-Praesenzflag a nach NPC-Entlassung in der Schleife aktualisieren */
#ifndef FIX_R053
#define FIX_R053 FIX_STUFE_B
#endif

/* R054: gz_0c9940_t2 / f_0cab30 - Sinnesschaerfe-Probe meldet Warnung bei bestandener Probe (b == 1) statt bei misslungener (!b) */
#ifndef FIX_R054
#define FIX_R054 FIX_STUFE_A
#endif

/* R055: street / f_11e500, gz_11caf0_t12 / Context11CA493::f_11e350, f_11e380 - Schleife ueber Strassenbegegnungen von 1..20 statt 0..19 (20. Begegnung wird nicht mehr uebersprungen) */
#ifndef FIX_R055
#define FIX_R055 FIX_STUFE_A
#endif

/* R056: castle_t3 / f_02c9a0, f_02d230 - Seil-/Hebel-Flag d_1bc82c im else-Zweig auf 0 zuruecksetzen; Index -1 vor d_1a06a8-Zugriff abfangen */
#ifndef FIX_R056
#define FIX_R056 FIX_STUFE_A
#endif

/* R058: ship_t1 / f_0fbd80 - Zufallsobergrenze p4 in der Heldenschleife nicht mit dem ersten Zufallswert ueberschreiben */
#ifndef FIX_R058
#define FIX_R058 FIX_STUFE_A
#endif

/* R059: final2 / f_08e320, f_08fcc0 - Einmal-Trigger-Flag d_1bdb74 bei Feld 0x385 nach Ausloesen auf 1 setzen */
#ifndef FIX_R059
#define FIX_R059 FIX_STUFE_B
#endif

/* R068: tower3_t2 / f_130fd0 - Endlosschleife bei der Suche nach einem zweiten handlungsfaehigen Helden verhindern, wenn nur noch der Anfuehrer bei Bewusstsein ist */
#ifndef FIX_R068
#define FIX_R068 FIX_STUFE_A
#endif

/* R071: gz_08cb00 / f_08cd20, gz_08dae0_rand910a / f_08dae0 - Vorratszaehler d_1bdb20 vor der Nullpruefung dekrementieren, damit das Folge-Flag 0x1f41 gesetzt wird */
#ifndef FIX_R071
#define FIX_R071 FIX_STUFE_B
#endif

/* R072: gz_126c40 / f_126f80 - Kalender-Tagesueberlauf p1->b -= 30 (statt 30 - p1->b) und Monatsueberlauf p1->c -= 12 (statt -= 1) */
#ifndef FIX_R072
#define FIX_R072 FIX_STUFE_A
#endif

/* R074: dialog_t1 / f_055650 - In case 42/43 Nachbar-Flag d_1bc78c statt Kopierfehler d_1bc788 (aus case 40/41) pruefen */
#ifndef FIX_R074
#define FIX_R074 FIX_STUFE_B
#endif

/* R076: gz_0f25c0_t1 / f_0f2de0, sewerag1_neu / f_0f5110 - Flut-Trigger d_1c01a0 = 1 nach Truhe 0x489 in der Kanalisation unbedingt setzen und bei Gegenstandsentnahme res = 1 zurueckgeben */
#ifndef FIX_R076
#define FIX_R076 FIX_STUFE_B
#endif

/* R077: gz_0dc9a0_ta / f_0dc9a0 - Helden-Slots per memmove statt ueberlappendem memcpy nachruecken und aufeinanderfolgende Luecken erfassen */
#ifndef FIX_R077
#define FIX_R077 FIX_STUFE_B
#endif

/* R084: diary / f_057a00 - Tagebuch-Stichwort-ID als unsigned char (0..255) statt signed char lesen */
#ifndef FIX_R084
#define FIX_R084 FIX_STUFE_A
#endif

/* R092: lang_cze / f_0abc00, f_0abc30 - Nullzeiger-Aufruf strcat(p2, 0) entfernen */
#ifndef FIX_R092
#define FIX_R092 FIX_STUFE_A
#endif
/* ---- Ende Einzelschalter ---- */

/* Optionales Live-Probenlog im Fix-Modus */
#if FIX_BUGS >= 1
#include "R_PLOG.H"
#endif

#endif /* RIVA_FIX_H */
