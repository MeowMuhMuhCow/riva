/* === Beschreibung (Katalog) ===
 * Einheit cmask2_t1 (0x04b770 - 0x04cbc0)
 *
 * Überblick
 * Die Einheit cmask2_t1 implementiert den ersten Teil der Seiten- und Kontextmenü-Logik des Charakterblatts
 * (cmask2): die Ausgabe einzelner Zauberzeilen mit farblicher Steigerungsmarkierung, den Porträtwechsel-Dialog
 * für Spielerhelden, die vier seitenspezifischen Aktionsmenüs (für die Grundwerte-, Kampfwerte-, Talent- und
 * Zauberseite) sowie die vollständige Darstellung der ersten Charakterblatt-Seite (Gottheit, 14 Eigenschaften
 * mit Normal- und Aktuellwert, LE, AE, MR, RS, Ausdauer, Traglast und Bewegungspunkte).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 5/7 gleich (suche.py 30.10.2026, Basis cmask2_t1_P1.CPP)
// A4 Arm A: f_04c7e0 31 exakt / 11 Struktur / 4 falsche Abschnitte (vorher 283/272/55); Rest der Einheit unveraendert
// P1 0/7 gleich
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 0 gleich (vorher 0), Rest 994 (vorher 995)
// cmask2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04B770-0x04D730
#include <string.h>
#include <stdio.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_036ee0(int p1, int p2);                           // reg eax edx stapel 0
short f_03aa20(int p1, int p2, int p3); short f_03aa20(int p1, int p2, int p3, int);           // reg eax edx ebx ecx stapel 0
int f_03ad80(int p1, int p2);                           // reg eax edx stapel 0
int f_03d790(int p1, int p2);                           // reg eax edx stapel 0
int f_042330(int p1, int p2);                           // reg eax edx stapel 0
signed char f_042350(int p1);                                   // reg eax stapel 0
char f_042380(int p1);                                   // reg eax stapel 0
signed char f_042390(int p1);                                   // reg eax stapel 0
signed char f_0423a0(int p1);                                   // reg eax stapel 0
signed char f_0423c0(int p1);                                   // reg eax stapel 0
signed char f_0423e0(int p1);                                   // reg eax stapel 0
char f_042400(int p1);                                   // reg eax stapel 0
int f_042890(int p1);                                   // reg eax stapel 0
signed char f_0428d0(int p1);                                   // reg eax stapel 0
int f_0428f0(int p1);                                   // reg eax stapel 0
short f_042960(int p1);                                   // reg eax stapel 0
short f_042970(int p1);                                   // reg eax stapel 0
short f_0429a0(int p1);                                   // reg eax stapel 0
short f_0429b0(int p1);                                   // reg eax stapel 0
char *f_0429c0(int p1, int p2);                           // reg eax edx stapel 0
int f_042a10(int p1);                                   // reg eax stapel 0
signed char f_042a40(int p1, int p2);                           // reg eax edx stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_042ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_042bb0(int p1, int p2);                           // reg eax edx stapel 0
char f_0430f0(int p1, int p2);                           // reg eax edx stapel 0
int f_043170(int p1);                                   // reg eax stapel 0
int f_0437b0(int p1, int p2);                           // reg eax edx stapel 0
int f_043a10(int p1, int p2);                           // reg eax edx stapel 0
short f_045300(int p1);                                   // reg eax stapel 0
int f_045610(int p1);                                   // reg eax stapel 0
int f_045660(int p1);                                   // reg eax stapel 0
int f_0456e0(int p1, int p2);                           // reg eax edx stapel 0
int f_045710(int p1, int p2);                           // reg eax edx stapel 0
int f_046bc0(int p1);           // reg eax stapel 0
int f_04b0d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_04b3a0(int p1);                                   // reg eax stapel 0
int f_04e340(int p1);                                   // reg eax stapel 0
int f_04ed90(int p1);                                   // reg eax stapel 0
int f_04ee60(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_098fe0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
char f_09a040(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820(...);                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4ad0(int p1);                                   // reg eax stapel 0
int f_0d4b00(int p1);                                   // reg eax stapel 0
int f_0e4d80(int p1);                                   // reg eax stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_149360();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a0f46;                    // 0x1A0F46
extern int d_1a0f50;                    // 0x1A0F50
extern int d_1a0f52;                    // 0x1A0F52










extern int d_1a1320;                    // 0x1A1320
extern int d_1a1350;                    // 0x1A1350
extern int d_1a13b4;                    // 0x1A13B4
extern signed char d_1a3204[];
extern signed char d_1a3205[];
extern signed char d_1a3210[];
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a6ba0;                    // 0x1A6BA0
extern int d_1a6ba1;                    // 0x1A6BA1
extern int d_1a7734;                    // 0x1A7734
extern int d_1a7735;                    // 0x1A7735
extern int d_1a7744;                    // 0x1A7744
extern int d_1a7745;                    // 0x1A7745
extern signed char *d_1bc8a0;
extern char d_1bc930;
extern int d_1bfaf0;                    // 0x1BFAF0
extern volatile short d_1c2198;
extern int d_1c21b4;                    // 0x1C21B4
extern char d_1c27a8[];
extern char d_1c27da[];
extern char d_1c280c[];
extern char d_1c283e[];
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c29c8;                    // 0x1C29C8
extern int d_1c29cc;                    // 0x1C29CC
extern int d_1c29d0;                    // 0x1C29D0
extern int d_1c29d4;                    // 0x1C29D4
extern int d_1c29d8;                    // 0x1C29D8
extern int d_1c29dc;                    // 0x1C29DC
extern int d_1c2be0;                    // 0x1C2BE0
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3068;                    // 0x1C3068
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (13), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_04b880  groesse 256 B, 68 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für reguläre Spielerhelden (f_042400(p1) == 0) den Porträtauswahldialog (f_098fe0), in
 *   dem der Spieler aus den zur Heldenklasse (type) und zum Geschlecht (sex) passenden Porträtbildern (Grenzen
 *   aus d_1a3204, d_1a3205, d_1a3210) ein neues Gesicht auswählen kann; bei Begleit-NPCs wird stattdessen die
 *   Ablehnungsmeldung p2 angezeigt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Fehlermeldungskennung für NPCs
 *   (p2) und gibt 1 zurück, wenn ein neues Porträt gewählt wurde, sonst 0.
 * - Wichtige Variablen: Liest die klassen- und geschlechtsspezifischen Porträtbereiche aus d_1a3204, d_1a3205
 *   und d_1a3210 und setzt das neue Porträt über f_042330.
 === Ende Beschreibung === */
//@ f_04b980  groesse 1664 B, 225 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das große Aktions-Popupmenü (f_0bf820) auf der Grundwerte-Seite (Seite
 *   1) des Charakterblatts: Es bietet Optionen zum Umschalten der Körperansicht, Gegenstand untersuchen,
 *   Gegenstand benutzen (f_03d790), Gegenstand wegwerfen (f_036300), Talent einsetzen (f_03aa20), Zauber
 *   sprechen (f_03d4b0), Porträt ändern (f_04b880), fehlende Abenteuerpunkte bis zum nächsten Stufenanstieg
 *   abfragen (0x304005f), zum Wechseln auf die Kampf-, Talent- oder Zauberseite sowie optional zur Diagnose von
 *   Krankheiten (p->m17), Giften (p->m19) oder zum Entlassen eines Begleit-NPCs (f_0e4d80).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Baut die dynamischen Menüpunkte in d_1c29c4 bis d_1c29e0 auf und setzt bei Änderungen
 *   d_1c2198 = 1.
 === Ende Beschreibung === */
//@ f_04c000  groesse 1472 B, 47 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf der Kampfwerte-Seite (Seite 2) des
 *   Charakterblatts mit den Optionen Körperansicht umschalten, Gegenstand benutzen, Gegenstand wegwerfen, Talent
 *   anwenden, Zaubern sowie Seitenwechsel auf Grundwerte (m0 = 1), Talente (m0 = 3) oder Zauber (m0 = 4).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Schaltet die aktuelle Charakterblatt-Seite in p->m0 um.
 === Ende Beschreibung === */
//@ f_04c360  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf der Talent-Seite (Seite 3) des
 *   Charakterblatts mit den Optionen Talent anwenden, Zaubern sowie Seitenwechsel auf Grundwerte (m0 = 1),
 *   Kampfwerte (m0 = 2) oder Zauber (m0 = 4) und Schließen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Steuert den Seitenindex p->m0 und das Schließ-Flag W1(p).
 === Ende Beschreibung === */
//@ f_04c5c0  groesse 544 B, 39 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf den Zauber-Seiten (Seiten 4 und 5) des
 *   Charakterblatts mit den Optionen Talent anwenden, Zaubern, Seitenwechsel auf Grundwerte (1), Kampfwerte (2)
 *   oder Talente (3), Umblättern zwischen der ersten und zweiten Zauberseite (m0 = 4 <-> 5) sowie Schließen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Schaltet in case 6 über p->m0 = ((signed char)p->m0 == 4) + 4 zwischen den beiden
 *   Zauberseiten 4 und 5 hin und her.
 === Ende Beschreibung === */
//@ f_04c7e0  groesse 992 B, 278 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die rechte Textspalte der Grundwerte-Seite (Seite 1) des Charakterblatts für den
 *   Helden p->m0b: Sie gibt die Schutzgottheit (0x3040014), alle 14 Eigenschaften (MU bis GG im Format
 *   Aktuell/Normal, bei Abweichung rot markiert) sowie den Block der abgeleiteten Werte (0x3040018:
 *   Lebensenergie LE/LE_max, Astralenergie AE/AE_max, Magieresistenz, Rüstungsschutz, Ausdauer LE + KK, Traglast
 *   und Bewegungspunkte, bei Überlastung mit BP == 1 gelb/rot hervorgehoben) auf den Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Formatiert die Werte in die Textpuffer d_1c27a8, d_1c27da, d_1c280c und d_1c283e und
 *   gibt sie über d_1c38b0 aus.
 === Ende Beschreibung === */
//@ f_04cbc0  groesse 512 B, 135 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die rechte Textspalte der Kampfwerte-Seite (Seite 2) des Charakterblatts: Sie
 *   berechnet den Fernkampf-Basiswert (KL + FF + KK) / 4, formatiert für alle sieben Nahkampf-Waffengattungen (0
 *   bis 6) die Attacke- und Paradewerte (f_0456e0 / f_045710) und gibt diese zusammen mit dem AT/PA-Basiswert
 *   (f_042890), den aktuellen Waffenkampfwerten (f_045610 / f_045660) sowie den Gesamtwerten für Schusswaffen
 *   (Talent 7) und Wurfwaffen (Talent 8) über den Textblock 0x304001c aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Speichert die sieben formatierten Waffenzeilen in d_1c27a8 bzw. d_1c29c4 und gibt sie
 *   über d_1c38b0 aus.
 === Ende Beschreibung === */
//@ f_04cdc0  groesse 16 B, 1 Bef, reg -, stapel ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet als kurzer Wrapper direkt auf die Hilfsfunktion f_04ef70 weiter.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Greift selbst auf keine Variablen zu.
 === Ende Beschreibung === */
//@ f_04cdd0  groesse 544 B, 126 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die erste Zauber-Übersichtsseite (Seite 4) des Charakterblatts: Sie gibt die acht
 *   Überschriften der ersten acht Zaubergebiete (0x200000ee bis 0x200000f5: Antimagie, Beherrschung,
 *   Dämonologie, Elemente, Bewegung, Heilung, Hellsicht, Illusion) zentriert in ihren Spalten aus und listet
 *   darunter in einer Schleife über die Bereichstabellen d_1a7734/d_1a7735 und d_1a1320 alle zugehörigen
 *   Zaubersprüche samt Fertigkeitswert über f_04b770 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Spaltenkoordinaten d_1a1320 sowie die Start- und Längentabellen d_1a7734 und
 *   d_1a7735.
 === Ende Beschreibung === */
//@ f_04cff0  groesse 352 B, 86 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die zweite Zauber-Übersichtsseite (Seite 5) des Charakterblatts: Sie gibt die vier
 *   Überschriften der verbleibenden Zaubergebiete (0x200000f6 bis 0x200000f9: Kampf, Verständigung, Verwandlung,
 *   Veränderung) aus und listet darunter anhand der Tabellen d_1a7744/d_1a7745 und d_1a1350 alle zugehörigen
 *   Zaubersprüche über f_04b770 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Spaltenkoordinaten d_1a1350 sowie die Start- und Längentabellen d_1a7744 und
 *   d_1a7745.
 === Ende Beschreibung === */
//@ f_04d150  groesse 896 B, 240 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet alle sichtbaren Inventarslots (0 bis 30, wobei die Körperslots 0 bis 14 nur bei
 *   d_1bc930 == 1 gezeichnet werden) des Helden p->m0b auf den Bildschirm: Für belegte Slots wird das
 *   Gegenstands-Icon aus dem Archiv 0x50002 geladen, bei stapelbaren Gegenständen (f_0a7950) die Stückzahl
 *   rechts unten eingeblendet und bei zerbrochenen Gegenständen (f_042bb0 == 1) das "Zerbrochen"-Overlay (Icon
 *   1000) darübergelegt; leere Slots werden mit der Hintergrundfarbe gefüllt, und abschließend wird der
 *   Auswahlrahmen über f_04b0d0 gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Liest die Slot-Koordinaten aus d_1a0f50/d_1a0f52, die Gegenstandsdefinitionen aus
 *   d_1c2c40 und zeichnet auf den Bildschirm d_1a34e0.
 === Ende Beschreibung === */
//@ f_04d4d0  groesse 608 B, 161 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Körper-Ausrüstungsansicht (98x164 Pixel an Position 85, 34) samt allen 15 am
 *   Körper getragenen Gegenständen (Slots 0 bis 14), ihren Stückzahlen und eventuellen "Zerbrochen"-Markierungen
 *   in den Hintergrundpuffer p->m11e und sichert den fertigen Ausschnitt anschließend in das Teilbild p->ff6
 *   (als Vorbereitung für die Auf-/Zuroll-Animation der Pergamentrolle in gz_04d730).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt das Körper-Teilbild p->ff6, das Icon-Bild p->ff2 und den Hintergrundpuffer
 *   p->m11e.
 === Ende Beschreibung === */

#pragma aux f_09a040 parm [eax edx] modify exact [eax]   // gesichert: edx; Aufrufe 46

#define A(x) ((int)&(x))
#define W1(q) (*(short*)&(q)->m1)
struct M {
    char m0; char m1; char m2; char m3; char m4; short m5; char pad7[4];
    int m0b; int m0f; char pad13[4]; short m17; short m19; short m1b; char pad1d[3];
    short m20; short m22; char pad24[0xea - 0x24]; int mea; char pade[0x11e - 0xee]; int m11e;
};
struct F7 { char s[7]; };
struct F11 { char s[11]; };
struct T72 { char s[72]; };
extern F7 d_1a12e4;
extern F11 d_1a130c;
extern F7 d_1a1318;
extern T72 d_1a31bc;
extern int d_1a12c4;
int f_014540(int p1, int p2, int p3);
void f_014710(int p1, int p2);
short f_03d4b0(int p1, int p2, int p3);
int f_0e9690(int p1, int p2);


//@ f_04b770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet eine einzelne Zeile in der Zauberübersicht des Charakterblatts, bestehend aus dem
 *   Zaubernamen (a + 0x20000097) und dem rechtsbündig formatierten Zauberwert (f_0430f0), wobei der Wert
 *   farblich hervorgehoben wird (0xfc grün bei bereits gesteigertem Spruch, 0xfd rot, wenn das Steigerungslimit
 *   erreicht ist oder drei Fehlversuche in d_1bc8a0 vorliegen).
 * - Eingaben und Rückgabe: Die Funktion erhält das Charakterblatt-Objekt (p), den Zauberindex (a), den
 *   Gruppenstartindex (b), die X-Spalte des Namens (c), die rechte X-Kante des Werts (e) sowie den
 *   Y-Basisversatz (f) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest die Steigerungsversuche aus d_1bc8a0 und den Zauberwert über f_0430f0(p->m0b, a).
 === Ende Beschreibung === */
void f_04b770(M *p, volatile int a, int b, int c, int e, int f)
{
    short f_09a040z(int);
    #pragma aux f_09a040z "f_09a040" parm [eax] modify exact [eax]
    signed char col;
    F7 fmt;
    int d;
    char buf[12];
    signed char init = f_09a040z(0xff);
    fmt = d_1a12e4;
    d = a - b;
    col = init;
    f_0e9510(A(d_1c38b0), (short)a + 0x20000097, (short)c, (short)(d * 7 + f));
    int ai = (short)a;
    int ix = ai * 2;
    if (d_1bc8a0[ix + 1] >= f_036ee0(ai, p->m0b) || d_1bc8a0[ix] == 3) {
        col = f_09a040z(0xfd);
    } else {
        if (d_1bc8a0[ix + 1] != 0) col = f_09a040z(0xfc);
    }
    sprintf(buf, fmt.s, col, (signed char)f_0430f0(p->m0b, (short)a), (unsigned char)f_09a040z(0xff));
    f_0e9660(A(d_1c38b0), (int)buf, (short)(e - f_0e9690(A(d_1c38b0), (int)buf)), (short)(d * 7 + f));
}

//@ f_04b880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für reguläre Spielerhelden (f_042400(p1) == 0) den Porträtauswahldialog (f_098fe0), in
 *   dem der Spieler aus den zur Heldenklasse (type) und zum Geschlecht (sex) passenden Porträtbildern (Grenzen
 *   aus d_1a3204, d_1a3205, d_1a3210) ein neues Gesicht auswählen kann; bei Begleit-NPCs wird stattdessen die
 *   Ablehnungsmeldung p2 angezeigt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Fehlermeldungskennung für NPCs
 *   (p2) und gibt 1 zurück, wenn ein neues Porträt gewählt wurde, sonst 0.
 * - Wichtige Variablen: Liest die klassen- und geschlechtsspezifischen Porträtbereiche aus d_1a3204, d_1a3205
 *   und d_1a3210 und setzt das neue Porträt über f_042330.
 === Ende Beschreibung === */
int f_04b880(int p1, int p2)
{
    short f_098fe0(int, int, int);
    char loc[72];
    short k, hi, lo, s;
    int r = 0;
    if (f_042400(p1)) {
        f_0bf730(A(d_1c2c64), p2);
    } else {
        memcpy(loc, &d_1a31bc, 0x48);
        k = f_042350(p1);
        if (k > 10) k = 10;
        if (f_042380(p1)) {
            hi = d_1a3205[k];
            lo = d_1a3210[k];
        } else {
            hi = d_1a3210[k];
            lo = d_1a3204[k];
        }
        hi = hi - 1;
        short width = hi - lo + 1;
        s = f_098fe0(A(d_1c2c64), width, lo);
        if (s != -1) {
            f_042330(p1, s);
            r = 1;
        } else {
            r = 0;
        }
    }
    return r;
}

#define RET1(o) { f_1254a0((int)(o), 0); return; }

#pragma inline_depth(0)
//@ f_04b980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das große Aktions-Popupmenü (f_0bf820) auf der Grundwerte-Seite (Seite
 *   1) des Charakterblatts: Es bietet Optionen zum Umschalten der Körperansicht, Gegenstand untersuchen,
 *   Gegenstand benutzen (f_03d790), Gegenstand wegwerfen (f_036300), Talent einsetzen (f_03aa20), Zauber
 *   sprechen (f_03d4b0), Porträt ändern (f_04b880), fehlende Abenteuerpunkte bis zum nächsten Stufenanstieg
 *   abfragen (0x304005f), zum Wechseln auf die Kampf-, Talent- oder Zauberseite sowie optional zur Diagnose von
 *   Krankheiten (p->m17), Giften (p->m19) oder zum Entlassen eines Begleit-NPCs (f_0e4d80).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Baut die dynamischen Menüpunkte in d_1c29c4 bis d_1c29e0 auf und setzt bei Änderungen
 *   d_1c2198 = 1.
 === Ende Beschreibung === */
#pragma inline_depth(3)
int dialog730(int,int);
#pragma aux dialog730 "f_04b880" parm [eax] [edx] value [eax] modify exact [eax edx]
void delete730(int,int);
#pragma aux delete730 "f_014710" parm [eax] [edx] modify exact [eax]

void *ctxCtor730(void *,const char *,const char *,const char *);
#pragma aux ctxCtor730 "f_125400" parm [eax] [edx] [ebx] [ecx] value [eax] modify exact [eax ebx ecx edx]
void *ctxDtor730(void *,int);
#pragma aux ctxDtor730 "f_1254a0" parm [eax] [edx] value [eax] modify exact [eax]
struct Context730 {int data[15]; __pragma("ctxCtor730") Context730(const char*,const char*,const char*); __pragma("ctxDtor730") ~Context730();};

void f_04b980(M *p)
{
    int f_04b3a0_1120(int);
    #pragma aux f_04b3a0_1120 "f_04b3a0" parm [eax] modify exact [eax edx]
    int f_0e4d80_1120(int);
    #pragma aux f_0e4d80_1120 "f_0e4d80" parm [eax] modify exact [eax edx]
    struct Inline730 {
       static int flag(){unsigned char c=d_1bc930;return c? (unsigned char)1 : (unsigned char)0;}
       static signed char party(){return *(signed char*)&d_1bfaf0;}
    };
    extern int d_1c29e0;

    short second = 99;
    short first = 99;
    short third;
    unsigned short i;
    short result;
    int value;
    Context730 o((const char*)&d_1c349c,(const char*)&d_1c3870,(const char*)&d_1c3498);
    p->m1b = 12;
    d_1c29c4 = 0x3040002;
    d_1c29c8 = 0x3040003;
    d_1c29cc = 0x3040004;
    p->m17 = f_0d4ad0(p->m0b);
    i = 3;
    p->m19 = f_0d4b00(p->m0b);
    if (p->m17) {
        first = 11;
        d_1c29d0 = 0x3040005;
        i = 4;
        p->m1b++;
    }
    if (p->m19) {
        second = i + 8;
        (&d_1c29c4)[(short)i] = 0x3040035;
        i++;
        p->m1b++;
    }
    if (Inline730::party() != (short)-1) {
        (&d_1c29c4)[(short)i] = 0x3040055;
        third = i + 8;
        i++;
        p->m1b++;
    } else {
        third = 99;
    }
    ((volatile int *)&d_1c29c4)[(short)i] = 0x3040006;
    p->m5 = f_0bf820(A(d_1c2c64), 0x20000194, p->m1b,
        Inline730::flag() + 0x304003c, 0x3040007,
        0x304005b, 0x304005e, 0x3040008, 0x3040009,
        0x304000a, 0x304000b, d_1c29c4, d_1c29c8,
        d_1c29cc, d_1c29d0, d_1c29d4, d_1c29d8,
        d_1c29dc, d_1c29e0) - 1;
    if (p->m5 != -2) {
        if (p->m5 == p->m1b - 1) {
            W1(p) = 1;
            f_04b3a0((int)p);
        } else {
            if (p->m5 == third) {
                if (f_0bf6f0(A(d_1c2c64), 0x3040056) != 1) return;
                f_0e4d80_1120(p->m0b);
                return;
            } else {
    if (p->m5 == second) {
        ((int*)o.data[1])[1] = p->m0b;
        f_0e93f0(A(d_1c38b0), A(d_1c21b4), p->m19 + 0x304002b);
        if (f_0437b0(p->m0b, p->m19)) {
            ((int*)o.data[4])[1] = p->m19 + 0x20000176;
            f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x3040057);
        }
        f_0bf730(A(d_1c2c64), f_133fe0(A(d_1c3498), A(d_1c21b4)));
        return;
    }
    if (p->m5 == first) {
        ((int*)o.data[1])[1] = p->m0b;
        f_0e93f0(A(d_1c38b0), A(d_1c21b4), p->m17 + 0x304000c);
        if (f_043a10(p->m0b, p->m17)) {
            ((int*)o.data[4])[1] = p->m17 + 0x2000003a;
            f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x3040036);
        }
        f_0bf730(A(d_1c2c64), f_133fe0(A(d_1c3498), A(d_1c21b4)));
        return;
    }
    switch (p->m5) {
    case 0:
        f_04e340((int)p);
        d_1c2198 = 1;
        return;
    case 1:
        d_1c2198 = f_04ed90((int)p);
        return;
    case 2:
        d_1c2198 = dialog730(p->m0b, 0x304005c);
        return;
    case 3:
        ((int*)o.data[1])[1] = p->m0b;
        ((int*)o.data[6])[1] = f_046bc0((short)((signed char)f_0428d0(p->m0b) + 1)) - f_0428f0(p->m0b);
        f_0bf730(A(d_1c2c64), 0x304005f);
        return;
    case 4:
        if (p->m0f != p->m0b) {
            f_0bf730(A(d_1c2c64), 0x3040039);
            return;
        }
        f_03d790(p->m0b, p->m20);
        f_04b3a0((int)p);
        d_1c2198 = 1;
        return;
    case 5:
        if (p->m0f != p->m0b) {
            f_0bf730(A(d_1c2c64), 0x3040039);
            return;
        }
        f_036300(p->m0b, p->m20, -1);
        f_04b3a0((int)p);
        d_1c2198 = 1;
        return;
    case 6:
        if (p->m22 != -1) value = (short)f_042a60(p->m0b,p->m20); else value = -1;
        result=f_03aa20(p->m0b,0,0,(short)value);
        if (result == -2) {
            W1(p) = 1;
            f_04b3a0_1120((int)p);
            return;
        }
        if ((int)result == -1) {
            ((int*)o.data[1])[1] = p->m0b;
            f_0bf730(A(d_1c2c64), 0x3040053);
            return;
        }
        break;
    case 7:
        if (!f_042a10(p->m0b)) {
            f_0bf730(A(d_1c2c64), 0x304003a);
            return;
        }
        delete730(*(volatile int*)&p->m11e,1);
        if ((short)f_03d4b0(p->m0b, 1, 0) != -2)
            f_04b3a0((int)p);
        p->m11e = f_014540(0xfa00, A(d_1a12c4), 0x15f);
        ((RivaRasterImage*)(p->mea))->f_0fb060((void *)(p->m11e));
        d_1c2198 = 1;
        return;
    case 8:
        p->m0 = 2;
        d_1c2198 = 1;
        return;
    case 9:
        f_04b3a0((int)p);
        p->m0 = 3;
        d_1c2198 = 1;
        return;
    case 10:
        if (!f_042a10(p->m0b)) {
            f_0bf730(A(d_1c2c64), 0x304003a);
            return;
        }
        f_04b3a0((int)p);
        p->m0 = 4;
        d_1c2198 = 1;
        return;
    }
            }
        }
    }
    return;
}
#pragma inline_depth(3)

//@ f_04c000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf der Kampfwerte-Seite (Seite 2) des
 *   Charakterblatts mit den Optionen Körperansicht umschalten, Gegenstand benutzen, Gegenstand wegwerfen, Talent
 *   anwenden, Zaubern sowie Seitenwechsel auf Grundwerte (m0 = 1), Talente (m0 = 3) oder Zauber (m0 = 4).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Schaltet die aktuelle Charakterblatt-Seite in p->m0 um.
 === Ende Beschreibung === */
void f_04c000(M *p)
{
    int f_04b3a0_d(int);
#pragma aux f_04b3a0_d "f_04b3a0" parm [eax] modify exact [eax edx]
    struct Inline {
        static int flag() { unsigned char c = d_1bc930; return c ? 1 : 0; }
        static int limit(M *p) { int n = p->m22; if (n != -1) n = (short)f_042a60(p->m0b, p->m20); return n; }
    };
    int o[15];
    int s;
    int value;
    f_125400((int)o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    p->m5 = f_0bf820(A(d_1c2c64), 0x20000194, 9, 0x304003c + Inline::flag(), 0x3040008, 0x3040009, 0x304000a, 0x304000b, 0x304001a, 0x3040003, 0x3040004, 0x3040006) - 1;
    if (p->m5 != -2) {
        switch (p->m5) {
        case 0:
            f_04e340((int)p);
            d_1c2198 = 1;
            RET1(o)
        case 1:
            if ((value = p->m0f) != p->m0b) {
                f_0bf730(A(d_1c2c64), 0x3040039);
                RET1(o)
            }
            f_03d790(value, p->m20);
            f_04b3a0((int)p);
            d_1c2198 = 1;
            RET1(o)
        case 2:
            if ((value = p->m0f) != p->m0b) {
                f_0bf730(A(d_1c2c64), 0x3040039);
                RET1(o)
            }
            f_036300(value, p->m20, -1);
            f_04b3a0((int)p);
            d_1c2198 = 1;
            RET1(o)
        case 3:
            s = f_03aa20(p->m0b, 0, 0, (short)Inline::limit(p));
            if (s == -2) {
                W1(p) = 1;
                f_04b3a0_d((int)p);
                RET1(o)
            }
            if (s == -1) {
                ((int*)o[1])[1] = p->m0b;
                f_0bf730(A(d_1c2c64), 0x3040053);
                RET1(o)
            }
            break;
        case 8:
            W1(p) = 1;
            f_04b3a0_d((int)p);
            RET1(o)
        case 4:
            if (f_042a10(p->m0b) == 0) {
                f_0bf730(A(d_1c2c64), 0x304003a);
                RET1(o)
            }
            {
                ((void (*)(int))f_014710)(p->m11e);
                if ((short)f_03d4b0(p->m0b, 1, 0) != -2) f_04b3a0((int)p);
                p->m11e = f_014540(0xfa00, A(d_1a12c4), 0x1ce);
                ((RivaRasterImage*)(p->mea))->f_0fb060((void *)( p->m11e));
                d_1c2198 = 1;
                RET1(o)
            }
        case 5:
            p->m0 = 1;
            d_1c2198 = 1;
            RET1(o)
        case 6:
            f_04b3a0((int)p);
            p->m0 = 3;
            d_1c2198 = 1;
            RET1(o)
        case 7:
            if (f_042a10(p->m0b) == 0) {
                f_0bf730(A(d_1c2c64), 0x304003a);
                RET1(o)
            }
            f_04b3a0((int)p);
            p->m0 = 4;
            d_1c2198 = 1;
            RET1(o)
        }
    }
    RET1(o)
}

//@ f_04c360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf der Talent-Seite (Seite 3) des
 *   Charakterblatts mit den Optionen Talent anwenden, Zaubern sowie Seitenwechsel auf Grundwerte (m0 = 1),
 *   Kampfwerte (m0 = 2) oder Zauber (m0 = 4) und Schließen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Steuert den Seitenindex p->m0 und das Schließ-Flag W1(p).
 === Ende Beschreibung === */
void f_04c360(M *p)
{
    int f_04b3a0_e(int);
#pragma aux f_04b3a0_e "f_04b3a0" parm [eax] modify exact [eax edx]
    void f_014710_local(int, int);
#pragma aux f_014710_local "f_014710" parm [eax] [edx] modify exact [eax]
    struct Inline {
        static int limit(M *p) { int n = p->m22; if (n != -1) n = (short)f_042a60(p->m0b, p->m20); return n; }
    };
    int o[15];
    int s;
    f_125400((int)o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    p->m5 = f_0bf820(A(d_1c2c64), 0x20000194, 6, 0x304000a, 0x304000b, 0x304001a, 0x3040002, 0x3040004, 0x3040006);
    if (p->m5 != -1) {
        switch (p->m5) {
        case 1:
            s = f_03aa20(p->m0b, 0, 0, (short)Inline::limit(p));
            if (s == -2) {
                W1(p) = 1;
                f_04b3a0_e((int)p);
                RET1(o)
            }
            if (s == -1) {
                ((int*)o[1])[1] = p->m0b;
                f_0bf730(A(d_1c2c64), 0x3040053);
                RET1(o)
            }
            break;
        case 2:
            if (f_042a10(p->m0b) == 0) {
                f_0bf730(A(d_1c2c64), 0x304003a);
                RET1(o)
            }
            {
                f_014710_local(*(volatile int *)&p->m11e, 1);
                if ((short)f_03d4b0(p->m0b, 1, 0) != -2) f_04b3a0((int)p);
                p->m11e = f_014540(0xfa00, A(d_1a12c4), 0x221);
                ((RivaRasterImage*)(p->mea))->f_0fb060((void *)( p->m11e));
                d_1c2198 = 1;
                RET1(o)
            }
        case 3:
            p->m0 = 1;
            d_1c2198 = 1;
            RET1(o)
        case 4:
            p->m0 = 2;
            d_1c2198 = 1;
            RET1(o)
        case 5:
            if (f_042a10(p->m0b) == 0) {
                f_0bf730(A(d_1c2c64), 0x304003a);
                RET1(o)
            }
            p->m0 = 4;
            d_1c2198 = 1;
            RET1(o)
        case 6:
            (*(volatile short *)&p->m1) = 1;
            RET1(o)
        }
    }
    RET1(o)
}

//@ f_04c5c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet und verarbeitet das Aktions-Popupmenü auf den Zauber-Seiten (Seiten 4 und 5) des
 *   Charakterblatts mit den Optionen Talent anwenden, Zaubern, Seitenwechsel auf Grundwerte (1), Kampfwerte (2)
 *   oder Talente (3), Umblättern zwischen der ersten und zweiten Zauberseite (m0 = 4 <-> 5) sowie Schließen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Schaltet in case 6 über p->m0 = ((signed char)p->m0 == 4) + 4 zwischen den beiden
 *   Zauberseiten 4 und 5 hin und her.
 === Ende Beschreibung === */
void f_04c5c0(M *p)
{
    int f_04b3a0_f(int);
#pragma aux f_04b3a0_f "f_04b3a0" parm [eax] modify exact [eax edx]
    void f_014710_local(int, int);
#pragma aux f_014710_local "f_014710" parm [eax] [edx] modify exact [eax]
    struct Inline {
        static int limit(M *p) { int n = p->m22; if (n != -1) n = (short)f_042a60(p->m0b, p->m20); return n; }
    };
    int o[15];
    short s;
    f_125400((int)o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    p->m5 = f_0bf820(A(d_1c2c64), 0x20000194, 7, 0x304000a, 0x304000b, 0x304001a, 0x3040002, 0x3040003, 0x304003b, 0x3040006);
    if (p->m5 != -1) {
        switch (p->m5) {
        case 1:
            s = f_03aa20(p->m0b, 0, 0, (short)Inline::limit(p));
            if (s == -2) {
                W1(p) = 1;
                f_04b3a0_f((int)p);
                RET1(o)
            }
            if (s == -1) {
                ((int*)o[1])[1] = p->m0b;
                f_0bf730(A(d_1c2c64), 0x3040053);
                RET1(o)
            }
            break;
        case 2:
            f_014710_local(*(volatile int *)&p->m11e, 1);
            if ((short)f_03d4b0(p->m0b, 1, 0) != -2) f_04b3a0((int)p);
            p->m11e = f_014540(0xfa00, A(d_1a12c4), 0x26b);
            ((RivaRasterImage*)(p->mea))->f_0fb060((void *)( p->m11e));
            d_1c2198 = 1;
            RET1(o)
        case 3:
            p->m0 = 1;
            d_1c2198 = 1;
            RET1(o)
        case 4:
            p->m0 = 2;
            d_1c2198 = 1;
            RET1(o)
        case 5:
            p->m0 = 3;
            d_1c2198 = 1;
            RET1(o)
        case 6:
            p->m0 = ((signed char)p->m0 == 4) + 4;
            d_1c2198 = 1;
            RET1(o)
        case 7:
            (*(volatile short *)&p->m1) = 1;
            RET1(o)
        }
    }
    RET1(o)
}

//@ f_04c7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die rechte Textspalte der Grundwerte-Seite (Seite 1) des Charakterblatts für den
 *   Helden p->m0b: Sie gibt die Schutzgottheit (0x3040014), alle 14 Eigenschaften (MU bis GG im Format
 *   Aktuell/Normal, bei Abweichung rot markiert) sowie den Block der abgeleiteten Werte (0x3040018:
 *   Lebensenergie LE/LE_max, Astralenergie AE/AE_max, Magieresistenz, Rüstungsschutz, Ausdauer LE + KK, Traglast
 *   und Bewegungspunkte, bei Überlastung mit BP == 1 gelb/rot hervorgehoben) auf den Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Formatiert die Werte in die Textpuffer d_1c27a8, d_1c27da, d_1c280c und d_1c283e und
 *   gibt sie über d_1c38b0 aus.
 === Ende Beschreibung === */
extern const char d_1b6650[];
extern const char d_1b6653[];
char f_09a040x(int p1);
char f_09a040y(int p1);
#pragma aux f_09a040y "f_09a040" parm [eax] modify exact [eax]
#pragma aux f_09a040x "f_09a040" parm [eax] modify exact [eax]
#pragma aux f_04c7e0 parm [eax] modify exact [eax]
#define C1(a) f_09a040x(a)
#define CL(a) f_09a040x(a)
#define SHDECL short a, bb, s1, d = 0, e, i; short c, ci, v2;
#define LFORM (((int)v != *(signed char *)f_0429c0(p->m0b, i)) ? CL(0xfd) : CL(0xff))
#define G2A d
#define G2B s1
#define G3A d
#define G3B i
#define T1A d
#define T1B s1
#define T2A bb
#define T2C c
#define SV i
#define CC0 v2
void f_04c7e0(M *p)
{
    F11 fa = d_1a130c;
    F7 fb = d_1a1318;
    int o[15];
    SHDECL
    short v;
    char *b;
    f_125400((int)o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    f_05e830(A(d_1c38b0), 0x10e, 0);
    int first = (signed char)f_042390(p->m0b);
    first += 0x20000012;
    ((int*)o[4])[1] = first;
    f_0e9510(A(d_1c38b0), 0x3040014, 0xd7, 0x2d);
    f_05e830(A(d_1c38b0), 0xeb, 0);
    f_05e830(A(d_1c38b0), 0x10e, 1);
    i = 0;
    f_05e830(A(d_1c38b0), 0x122, 2);
    for (; i <= 13; i++) {
        v = f_042a40(p->m0b, i);
        b = d_1c27a8 + i * 10;
        sprintf(b, fa.s, LFORM, (int)v, CL(0xff), *(signed char *)f_0429c0(p->m0b, i));
        ((int*)o[4])[1 + i] = f_133fe0(A(d_1c3498), (int)b);
    }
    f_0e9510(A(d_1c38b0), 0x3040017, 0xd7, 0x3b);
    SV = f_045300(p->m0b);
    if (SV == 1) {
        sprintf(d_1c27a8, fb.s, C1(0xf9), (short)f_043170(p->m0b), C1(0xff));
        sprintf(d_1c27da, fb.s, C1(0xf9), SV, C1(0xff));
    } else {
        sprintf(d_1c27a8, d_1b6650, (short)f_043170(p->m0b));
        sprintf(d_1c27da, d_1b6653, SV);
    }
    int sort902; // Haelt den Sortierknoten vor G2A
    G2A = f_042960((sort902=d_1a0f46,d_1a0f46=sort902,p->m0b));
    G2B = f_042970(p->m0b);
    sprintf(d_1c280c, fa.s, C1((G2A != G2B) ? 0xfd : 0xff), G2A, C1(0xff), G2B);
    G3A = f_0429a0(p->m0b);
    G3B = f_0429b0(p->m0b);
    sprintf(d_1c283e, fa.s, C1((G3A != G3B) ? 0xfd : 0xff), G3A, C1(0xff), G3B);
    ((int*)o[4])[1] = f_133fe0(A(d_1c3498), (int)d_1c280c);
    ((int*)o[4])[2] = f_133fe0(A(d_1c3498), (int)d_1c283e);
    ((short*)o[5])[1] = f_0423a0(p->m0b);
    int sort1010; // Haelt die Sortierkorrektur fuer G2 und T1
    T1A = f_0423c0((sort1010=d_1a0f50, d_1a0f50=sort1010, p->m0b));
    T1B = f_0423e0(p->m0b);
    ((short*)o[5])[2] = T1A + T1B;
    T2A = f_042960(p->m0b);
    signed char delta1010 = f_042a40(p->m0b, 6);
    short *q1010 = (short*)o[5];
    o[5] = (int)q1010; // Haelt den Roundtrip vor dem Wertstore
    q1010[3] = (T2A += delta1010);
    ((int*)o[4])[3] = f_133fe0(A(d_1c3498), (int)d_1c27a8);
    ((int*)o[4])[4] = f_133fe0(A(d_1c3498), (int)d_1c27da);
    f_0e9510(A(d_1c38b0), 0x3040018, 0xd7, 0x7a);
    RET1(o)
}
