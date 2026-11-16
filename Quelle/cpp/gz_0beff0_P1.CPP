/* === Beschreibung (Katalog) ===
 * Einheit gz_0beff0 (Adresse 0x0beff0 - 0x0bfd80)
 *
 * Diese Einheit gehört zum zentralen Menü- und Dialogfenster-System (menu.cpp / menuovl.cpp). Sie enthält die
 * Layout-Berechnung für Dialogfenster, die Anzeigeschleife für reine Textmeldungen ohne Antwortauswahl (mit
 * automatischer Lesezeit-Berechnung und Sprachausgabe-Synchronisation) sowie die gebräuchlichsten Aufruf-Wrapper
 * (f_0bf6f0 für Ja/Nein-Fragen, f_0bf730 für Textfenster, f_0bf7b0 für Zahleneingaben und f_0bf820 bis f_0bfa20
 * für Auswahlmenüs mit und ohne Porträt/Icon).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 18/21 gleich (suche.py 25.10.2026, Basis gz_0beff0_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 11 gleich (vorher 11), Rest 264 (vorher 265)
// gz_0beff0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BEFF0-0x0BFD80
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_0106d0(int p1);                                   // reg eax stapel 0
int f_010a70(int);                                         // reg - stapel 0
int f_0110f0(int p1, int p2);                           // reg eax edx stapel 0
int f_011350(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0115c0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e7e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e820(int p1, int p2);                           // reg eax edx stapel 0
int f_05e830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_0773b0(int p1);                                   // reg eax stapel 0
int f_0bdf20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bec40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0bfd80(int p1);                                   // reg eax stapel 0
int f_0bff00(int p1);                                   // reg eax stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e3380(int p1);                                   // reg eax stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3970(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3ba0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0e4830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e4a70(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
short f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9610(int p1, int p2);                           // reg eax edx stapel 0
int f_0fabf0(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene (21), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_0beff0  groesse 448 B, 126 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Layout-Funktion berechnet in einer Schleife die erforderliche Breite (s26) und Zeilenhöhe (s5c)
 *   eines Menüfensters p, indem sie die Zeilenanzahl von Überschrift (i68), Haupttext (i6c, über f_0bf480) und
 *   allen s74 Antwortoptionen (i9c) summiert. Überschreitet die Gesamthöhe 0x15 (21) Textzeilen und ist das
 *   Fenster noch schmaler als Stufe 9 (s12 < 9), verbreitert sie das Fenster um 2 Einheiten (64 Pixel) und
 *   berechnet den Zeilenumbruch neu.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf1b0  groesse 720 B, 203 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion hält ein reines Text- oder Meldungsfenster (ohne Antwortoptionen) auf dem Bildschirm
 *   offen, bis der Spieler klickt, eine Taste drückt (d_1bd75c != 0 oder d_1bd766 == 2) oder die aus Textlänge
 *   (p->s28) und eingestellter Lesegeschwindigkeit (d_1bfb00 bzw. d_1bfafc) berechnete Anzeigedauer limit
 *   abgelaufen ist. Während das Fenster offen ist, kann es per Maus verschoben werden (f_0e3ba0), und eine
 *   zugehörige Sprachdatei oder Porträtanimation (p->i8b) wird fortlaufend aktualisiert.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf480  groesse 240 B, 78 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion bestimmt den linken Texteinzug (s50) und die vertikale Startzeile (s52) für den
 *   Haupttext (i6c) eines Dialogfensters - unter Berücksichtigung eines eventuell eingeblendeten Porträts oder
 *   Icons (i7a, i8b, i70) und einer Überschrift (i68) - und ermittelt über f_0e9610 die Zeilenanzahl s28 des
 *   Haupttexts.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf570  groesse 16 B, 2 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die konstante Bildschirmbreite 0x140 (320 Pixel im VGA-Modus 13h) zurück.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets den Wert 0x140 (320) zurück.
 === Ende Beschreibung === */
//@ f_0bf580  groesse 256 B, 23 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein abgeleitetes Menü-Manager-Objekt (d_1c2c64), indem er den
 *   Basiskonstruktor f_0bff00 und den eingebetteten Grafikobjekt-Konstruktor f_0fabf0 (bei Offset +0x93)
 *   aufruft, die virtuelle Methodentabelle d_1bb334 setzt und den Breiten-Stack tab (10 Einträge zu 16 Bit) mit
 *   Nullen füllt.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf das zu initialisierende Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger t zurück.
 === Ende Beschreibung === */
//@ f_0bf5f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Menü-Manager-Objekt der Klasse d_1bb334 (d_1bb31c) oder ein
 *   Array solcher Objekte (fl & 4) ab, zerstört das eingebettete Grafikobjekt bei Offset +0x93 (f_0fad20), ruft
 *   den Basisdestruktor f_0bff80 auf und gibt bei gesetztem Bit fl & 2 den Objektspeicher frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p sowie die Watcom-Destruktor-Flags fl entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p zurück.
 === Ende Beschreibung === */
//@ f_0bf650  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sichert die aktuelle Fensterbreiten-Stufe (f_0e3380(p)) auf dem internen Stack
 *   p->tab[p->sa0++] der Menüstruktur.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf680  groesse 64 B, 10 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion holt die zuletzt gesicherte Fensterbreiten-Stufe vom internen Stack p->tab[--p->sa0]
 *   zurück und stellt sie im Feld p->s12 wieder her.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf6c0  groesse 48 B, 13 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sichert die aktuelle Fensterbreiten-Stufe auf dem internen Stack p->tab[p->sa0++] und
 *   setzt anschließend die neue Fensterbreiten-Stufe p->s12 = v.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M sowie die neue Breitenstufe v entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bf6f0  groesse 64 B, 19 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese häufig genutzte Dialogfunktion öffnet ein Ja/Nein-Bestätigungsfenster mit dem Fragetext v und
 *   den beiden Standard-Antworten "Ja" (0x200001a8) und "Nein" (0x200001a9), wobei auch die Tastaturkürzel für
 *   Ja/Nein (p->s4e = 1) aktiviert werden.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf den Menü-Manager (d_1c2c64) sowie die Textkennung v der Frage
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei "Ja", 0 bei "Nein" und -1 bei Abbruch mit Escape/Rechtsklick zurück.
 === Ende Beschreibung === */
//@ f_0bf730  groesse 128 B, 37 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Ausgabefunktion zeigt ein einfaches Meldungsfenster mit dem Text p2 (ohne
 *   Antwortoptionen) über f_0e4830 an, sofern der Text existiert und eine Länge größer als 0 besitzt (f_0e9590).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf den Menü-Manager (d_1c2c64) sowie die Textkennung bzw. den
 *   Textzeiger p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0e4830 (oder 0 bei leerem Text) zurück.
 === Ende Beschreibung === */
//@ f_0bf7b0  groesse 112 B, 31 Bef, reg eax edx ecx, stapel 8
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Wrapper öffnet ein interaktives Zahlen-Eingabefenster über f_0e4a70 (z. B. für Mengenangaben,
 *   Geldbeträge oder Versuchsanzahlen) und kümmert sich um das Aus- und Wiedereinblenden des Mauszeigers sowie
 *   die Zustandssicherung (f_0ce7c0/f_0ce7e0).
 * - Eingaben: Die Funktion nimmt den Menü-Manager p1, den Modus p2, die Textkennung p3, den Minimalwert p4, den
 *   Maximalwert p5 und die Stellenanzahl p6 entgegen.
 * - Rückgabewert: Die Funktion gibt den vom Spieler eingegebenen Zahlenwert zurück.
 === Ende Beschreibung === */
//@ f_0bf820  groesse 192 B, 67 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Hauptfunktion öffnet ein Auswahlmenü mit dem Fragetext b und c nachfolgenden
 *   Antwort-Textkennungen: Ist c == 0, zeigt sie ein reines Meldungsfenster über f_0e4830 an; ist c > 0,
 *   übergibt sie die Argumentliste an f_0bec40 zum Aufbau und Ausführen des Multiple-Choice-Menüs.
 * - Eingaben: Die Funktion nimmt den Menü-Manager o (d_1c2c64), den Haupttext b, die Anzahl der Antwortoptionen
 *   c sowie c variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index (1 bis c) der gewählten Option oder -1 bei Abbruch
 *   zurück.
 === Ende Beschreibung === */
//@ f_0bf8e0  groesse 160 B, 55 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einem 32 x 32 Pixel großen Roh-Porträt oder
 *   Icon (a), einer optionalen Überschrift (b), dem Haupttext (c) und d auswählbaren Antwortoptionen über
 *   f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, den Rohbild-Zeiger a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption oder 0/-1 zurück.
 === Ende Beschreibung === */
//@ f_0bf980  groesse 160 B, 53 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einer animierten Gesprächspartner-Sequenz
 *   (p->i8b = a, Abmessungen über f_011350), einer Überschrift (b), dem Haupttext (c) und d Antwortoptionen über
 *   f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, das Animations-Objekt a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption zurück.
 === Ende Beschreibung === */
//@ f_0bfa20  groesse 160 B, 58 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einem Bitmap-Objekt (p->i7a = a, Abmessungen
 *   über f_0fb210), einer Überschrift (b), dem Haupttext (c) und d Antwortoptionen über f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, das Bitmap-Objekt a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption zurück.
 === Ende Beschreibung === */
//@ f_0bfac0  groesse 32 B, 6 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sperrt das Verschieben eines Menüfensters (p->s20 = 1, p->s58 = 1), solange eine
 *   eingebettete Animation aktiv ist, und gibt den bisherigen Zustand von p->s58 zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion gibt den vorherigen Wert des Sperrflags p->s58 zurück.
 === Ende Beschreibung === */
//@ f_0bfae0  groesse 16 B, 3 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion hebt die Verschiebesperre eines Menüfensters wieder auf (p->s20 = 0, p->s58 = 0).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bfaf0  groesse 352 B, 110 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet das im linken oberen Bereich eines Dialogfensters (X = p->s14 + 15, Y =
 *   p->s16 + 15) eingebettete Bild: Je nach gesetztem Feld gibt sie entweder ein animiertes Porträt (p->i8b über
 *   f_0115c0), ein Bitmap-Objekt (p->i7a mit abgedunkeltem Schattenrahmen f_1481a0) oder einen Rohpixel-Block
 *   (p->i70) aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bfc50  groesse 240 B, 70 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die optionale Überschrift (p->i68) eines Dialogfensters in der hervorgehobenen
 *   Schriftfarbe 0xfd aus und passt anschließend den oberen Rand des Textfensters für den nachfolgenden
 *   Haupttext an.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bfd40  groesse 64 B, 18 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion positioniert den Textcursor auf (p->s50, p->s52), gibt den Haupttext (p->i6c) des
 *   Dialogfensters über f_0e9550 aus und setzt den relativen Textoffset danach wieder auf (0, 0) zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */

struct M { int i0; int i4; char *i8; short s0c, s0e; short s10, s12, s14, s16, s18, s1a, s1c, s1e, s20, s22, s24, s26, s28, s2a; char pad2c[28]; int vp48; short s4c, s4e, s50, s52; char pad54[4]; short s58, s5a, s5c; char pad5e[10]; int i68; int i6c; int i70; short s74; char *a76; int i7a; short s7e, s80; char pad82[6]; short s88; signed char c8a; int i8b; char pad8f[13]; int *i9c; short sa0; short tab[10]; };
#define AP I(&ap)
#define I(x) ((int)(x))
#define G ((int)d_1c38b0)
extern int d_1a34e0;
extern short d_1a64fc, d_1a64fe, d_1a6500, d_1a6502;
extern short d_1bd75c, d_1bd760, d_1bd766, d_1bd90c;
extern unsigned short d_1bd762;
extern char d_1bdbd4[];
extern int d_1bf244;
extern short *d_1bf514;
extern char d_1bfb00;
extern short d_1bfafc;
extern short d_1c0004;
extern char d_1c38b0[];
extern int d_1c3914;
short f_0e9590(int p1, int p2);
int f_0bff80(int p1, int p2);
int f_145300(int p1, int p2, int p3);
int f_145234(int p1, int p2);
int f_145254();
void f_014710(void *p);
void f_0bf480(M *p);
void f_0bfc50(M *p);
void f_0bfd40(M *p);
void f_0bfaf0(M *p);
int f_0bf820(int o, int b, int c, ...);

extern char d_1bb334[];
extern char d_1bb31c[];
//@ f_0beff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Layout-Funktion berechnet in einer Schleife die erforderliche Breite (s26) und Zeilenhöhe (s5c)
 *   eines Menüfensters p, indem sie die Zeilenanzahl von Überschrift (i68), Haupttext (i6c, über f_0bf480) und
 *   allen s74 Antwortoptionen (i9c) summiert. Überschreitet die Gesamthöhe 0x15 (21) Textzeilen und ist das
 *   Fenster noch schmaler als Stufe 9 (s12 < 9), verbreitert sie das Fenster um 2 Einheiten (64 Pixel) und
 *   berechnet den Zeilenumbruch neu.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0beff0(M *p)
{
    short t131_8;
  M *q_ = p;
  int *l30;
  int **cursor;
  short l2c, l28;
  short l24;
  short l20;
  short l1c;
  short flag;
  short a, sum, c;
  do {
    a = (q_->s12 + 2) * 0x20;
    q_->s26 = a;
    q_->s14 = f_0e3970(I(q_), a);
    f_05e2d0(G, (short)(q_->s14 + 0xf), (short)(q_->s26 - 0x1e), -1, -1);
    f_0bf480(q_);
    q_->s88 = f_05e820(G, 0);
    f_05e830(G, (short)(q_->s14 + q_->s26 - 0x24), 0);
    if (q_->i68 != 0) {
      q_->s28 += f_0e9610(G, q_->i68) + 1;
    }
    if ((t131_8 = q_->s28) < q_->s52) q_->s28 = q_->s52;
    l30 = q_->i9c;
    cursor = &l30;
    l1c = q_->s74;
    f_05e2a0(G, I(&l20), I(&l24), I(&l20), I(&l20));
    f_05e800(G, I(&l28), I(&l2c));
    f_05e2d0(G, -1, (short)(l24 - 10), -1, -1);
    sum = 0;
    f_05e7e0(G, 0, 0);
    c = 0;
    if (l1c > (short)0) {
      do {
        c++;
        sum += f_0e9610(G, *(++*cursor - 1));
      } while (c < (short)l1c);
    }
    f_05e2d0(G, -1, (short)l24, -1, -1);
    f_05e7e0(G, l28, l2c);
    q_->s5a = sum;
    q_->s5c = q_->s28 + q_->s5a;
    flag = 0;
    if ((int)q_->s5c > 0x15) {
      if ((q_->s12 = q_->s12 + 2) < 9) flag = 1;
    }
  } while (flag);
}
//@ f_0bf1b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion hält ein reines Text- oder Meldungsfenster (ohne Antwortoptionen) auf dem Bildschirm
 *   offen, bis der Spieler klickt, eine Taste drückt (d_1bd75c != 0 oder d_1bd766 == 2) oder die aus Textlänge
 *   (p->s28) und eingestellter Lesegeschwindigkeit (d_1bfb00 bzw. d_1bfafc) berechnete Anzeigedauer limit
 *   abgelaufen ist. Während das Fenster offen ist, kann es per Maus verschoben werden (f_0e3ba0), und eine
 *   zugehörige Sprachdatei oder Porträtanimation (p->i8b) wird fortlaufend aktualisiert.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#pragma aux f_0bfd40 "*";
#pragma aux f_0bfaf0 "*";
void f_0bf1b0(M *p)
{
  extern int f_0e4370(int);
  struct Guard {
    int flag;
    Guard() { if (f_0d3860() == 1) { f_0d2710(); flag = 1; } else flag = 0; }
    ~Guard() { if (flag == 1) f_0d26e0(); }
  };
  short *saved_area = d_1bf514;
  int saved_time = d_1c3914;
  int limit;
  if (d_1bd90c != (short)0 && f_0773b0(*(int *)&d_1c0004)) {
    limit = p->s28 * 12 * ((signed char)(d_1bfb00 + 1) * 3);
  } else {
    limit = p->s28 * 12 * ((signed char)(*(signed char *)&d_1bfafc + 1) * 3);
  }
  while (d_1bd760 != (short)0) {
    f_0e4370(I(p));
  }
  do {
    d_1a64fc = p->s14;
    d_1a6500 = d_1a64fc + p->s26;
    d_1a64fe = p->s16 + 1;
    d_1a6502 = p->s16 + 0xe;
    *(short * volatile *)&d_1bf514 = &d_1a64fc;
    f_0e4370(I(p));
    d_1bf514 = saved_area;
    if (d_1bd762 == 0x4900 || d_1bd762 == 0x5100 || f_0d37b0()) {
      d_1bd766 = 2;
      d_1bd75c = 0x1b;
    }
    if (p->s58 == 0 && (d_1bd766 == 1 || d_1bd760 != (short)0) && (!f_0d3790() || d_1bd760 != (short)0)) {
      { Guard guard; f_0e3430(I(p)); }
      f_0e3ba0(I(p), p->s14, p->s16, p->s26, p->s2a);
      {
        Guard guard;
        p->s14 = p->s18;
        p->s16 = p->s1a;
        f_0bf480(p);
        f_05e320(G, 0xff, -1);
        f_05e2d0(G, (short)(p->s14 + 0xf), (short)(p->s26 - 0x1e), (short)(p->s16 + 0xf), 0);
        f_05e7e0(G, p->s50, p->s52);
        f_0bdf20(I(p), p->s74, I(&p->i9c));
        f_0bfc50(p);
        f_0bfd40(p);
        f_0bfaf0(p);
        f_0bfd80(I(p));
        f_05e7e0(G, 0, 0);
        d_1bd766 = 0;
      }
    }
    if (abs(saved_time - d_1c3914) > limit) break;
    if (p->i8b != 0 && (f_010a70(p->i8b) & 1) == 0 && f_0106d0(p->i8b) > 1) {
      f_0110f0(p->i8b, 1);
    }
  } while (d_1bd766 != 2 && d_1bd75c == (short)0);
}

//@ f_0bf480
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion bestimmt den linken Texteinzug (s50) und die vertikale Startzeile (s52) für den
 *   Haupttext (i6c) eines Dialogfensters - unter Berücksichtigung eines eventuell eingeblendeten Porträts oder
 *   Icons (i7a, i8b, i70) und einer Überschrift (i68) - und ermittelt über f_0e9610 die Zeilenanzahl s28 des
 *   Haupttexts.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bf480(M *p)
{
  p->s52 = 0;
  p->s50 = p->s52;
  if (p->i7a != 0 || p->i8b != 0) {
    p->s50 = p->s7e + 6;
    p->s52 = p->s80 / 8 + (p->s80 % 8 ? 2 : 1);
  } else if (p->i70 != 0) {
    p->s50 = 0x26;
    p->s52 = 5;
  }
  if (p->i68 != 0) {
    p->s52 -= f_0e9610(G, p->i68) + 1;
  }
  f_05e7e0(G, p->s50, p->s52);
  p->s28 = f_0e9610(G, p->i6c);
  if (p->i68 != 0) {
    p->s52 += f_0e9610(G, p->i68) + 1;
  }
  f_05e7e0(G, p->s50, p->s52);
}
//@ f_0bf570
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die konstante Bildschirmbreite 0x140 (320 Pixel im VGA-Modus 13h) zurück.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets den Wert 0x140 (320) zurück.
 === Ende Beschreibung === */
int f_0bf570()
{
  return 0x140;
}
//@ f_0bf580
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein abgeleitetes Menü-Manager-Objekt (d_1c2c64), indem er den
 *   Basiskonstruktor f_0bff00 und den eingebetteten Grafikobjekt-Konstruktor f_0fabf0 (bei Offset +0x93)
 *   aufruft, die virtuelle Methodentabelle d_1bb334 setzt und den Breiten-Stack tab (10 Einträge zu 16 Bit) mit
 *   Nullen füllt.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf das zu initialisierende Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger t zurück.
 === Ende Beschreibung === */
int f_0bf580(int t)
{
  t = f_0bff00(t);
  t = f_0fabf0(t + 0x93) - 0x93;
  M *m = (M *)t;
  m->vp48 = (int)&d_1bb334;
  m->s4e = 0;
  m->c8a = 1;
  m->i8b = 0;
  m->i7a = 0;
  m->s4c = m->s1e = m->s4e;
  m->sa0 = 0;
  f_145300(I(m->tab), 0, 0x14);
  return I(m);
}
//@ f_0bf5f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Menü-Manager-Objekt der Klasse d_1bb334 (d_1bb31c) oder ein
 *   Array solcher Objekte (fl & 4) ab, zerstört das eingebettete Grafikobjekt bei Offset +0x93 (f_0fad20), ruft
 *   den Basisdestruktor f_0bff80 auf und gibt bei gesetztem Bit fl & 2 den Objektspeicher frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p sowie die Watcom-Destruktor-Flags fl entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p zurück.
 === Ende Beschreibung === */
int f_0bf5f0(int p, unsigned fl)
{
  int r;
  if (fl & 4) {
    f_145234(p, (int)&d_1bb31c);
    f_145254();
    return p;
  }
  int q = p + 0x93;
  *(int *)(q - 0x4b) = (int)&d_1bb334;
  r = f_0bff80(((int)(((RivaRasterImage*)(q))->f_0fad20( 0))) - 0x93, 1);
  if (fl & 2) f_014710((void *)r);
  return r;
}
//@ f_0bf650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sichert die aktuelle Fensterbreiten-Stufe (f_0e3380(p)) auf dem internen Stack
 *   p->tab[p->sa0++] der Menüstruktur.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bf650(M *p)
{
  p->tab[p->sa0++] = f_0e3380(I(p));
}
//@ f_0bf680
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion holt die zuletzt gesicherte Fensterbreiten-Stufe vom internen Stack p->tab[--p->sa0]
 *   zurück und stellt sie im Feld p->s12 wieder her.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bf680(M *p)
{
  short n = p->sa0 - 1;
  p->sa0 = n;
  p->s12 = p->tab[n];
  p->tab[p->sa0] = 0;
}
//@ f_0bf6c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sichert die aktuelle Fensterbreiten-Stufe auf dem internen Stack p->tab[p->sa0++] und
 *   setzt anschließend die neue Fensterbreiten-Stufe p->s12 = v.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M sowie die neue Breitenstufe v entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bf6c0(M *p, int v)
{
  p->tab[p->sa0++] = f_0e3380(I(p));
  p->s12 = v;
}
//@ f_0bf6f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese häufig genutzte Dialogfunktion öffnet ein Ja/Nein-Bestätigungsfenster mit dem Fragetext v und
 *   den beiden Standard-Antworten "Ja" (0x200001a8) und "Nein" (0x200001a9), wobei auch die Tastaturkürzel für
 *   Ja/Nein (p->s4e = 1) aktiviert werden.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf den Menü-Manager (d_1c2c64) sowie die Textkennung v der Frage
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei "Ja", 0 bei "Nein" und -1 bei Abbruch mit Escape/Rechtsklick zurück.
 === Ende Beschreibung === */
int f_0bf6f0(M *p, int v)
{
  short s;
  int r;
  p->s4e = 1;
  s = f_0bf820(I(p), v, 2, 0x200001a8, 0x200001a9);
  r = s;
  p->s4e = 0;
  if (r != 1) r = (r != -1) - 1;
  return r;
}
//@ f_0bf730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Ausgabefunktion zeigt ein einfaches Meldungsfenster mit dem Text p2 (ohne
 *   Antwortoptionen) über f_0e4830 an, sofern der Text existiert und eine Länge größer als 0 besitzt (f_0e9590).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf den Menü-Manager (d_1c2c64) sowie die Textkennung bzw. den
 *   Textzeiger p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0e4830 (oder 0 bei leerem Text) zurück.
 === Ende Beschreibung === */
int f_0bf730(int p1, int p2)
{
  int loc;
  int r;
  f_0ce7c0(I(&loc));
  d_1bf244 = 1;
  if (d_1bd90c) f_0d26e0();
  if (p2 != 0 && f_0e9590(G, p2) > 0) {
    r = f_0e4830(p1, 0, p2);
  } else {
    r = 0;
  }
  if (d_1bd90c) f_0d2710();
  d_1bf244 = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bf7b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Wrapper öffnet ein interaktives Zahlen-Eingabefenster über f_0e4a70 (z. B. für Mengenangaben,
 *   Geldbeträge oder Versuchsanzahlen) und kümmert sich um das Aus- und Wiedereinblenden des Mauszeigers sowie
 *   die Zustandssicherung (f_0ce7c0/f_0ce7e0).
 * - Eingaben: Die Funktion nimmt den Menü-Manager p1, den Modus p2, die Textkennung p3, den Minimalwert p4, den
 *   Maximalwert p5 und die Stellenanzahl p6 entgegen.
 * - Rückgabewert: Die Funktion gibt den vom Spieler eingegebenen Zahlenwert zurück.
 === Ende Beschreibung === */
int f_0bf7b0(int p1, short p2, int p3, short p4, short p5, short p6)
{
  int loc;
  int r;
  d_1bf244 = 1;
  if (d_1bd90c) f_0d26e0();
  f_0ce7c0(I(&loc));
  r = f_0e4a70(p1, p2, p3, p4, p5, p6);
  if (d_1bd90c) f_0d2710();
  d_1bf244 = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bf820
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Hauptfunktion öffnet ein Auswahlmenü mit dem Fragetext b und c nachfolgenden
 *   Antwort-Textkennungen: Ist c == 0, zeigt sie ein reines Meldungsfenster über f_0e4830 an; ist c > 0,
 *   übergibt sie die Argumentliste an f_0bec40 zum Aufbau und Ausführen des Multiple-Choice-Menüs.
 * - Eingaben: Die Funktion nimmt den Menü-Manager o (d_1c2c64), den Haupttext b, die Anzahl der Antwortoptionen
 *   c sowie c variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index (1 bis c) der gewählten Option oder -1 bei Abbruch
 *   zurück.
 === Ende Beschreibung === */
int f_0bf820(int o, int b, int c, ...)
{
  char *ap;
  int loc2;
  int loc1;
  int r;
  short cs;
  f_0ce7c0(I(&loc1));
  ap = (char *)&c + 4;
  f_0d5b50(0);
  cs = c;
  r = 0;
  if (cs == (short)0) {
    int oo = 0;
    oo = o;
    d_1bf244 = 1;
    f_0ce7c0(I(&loc2));
    if (d_1bd90c) f_0d26e0();
    f_0e4830(oo, cs, b);
    if (d_1bd90c) f_0d2710();
    d_1bf244 = 0;
    f_0ce7e0(I(&loc2), 0);
  } else {
    char *save;
    save = ap;
    r = f_0bec40(o, 0, 0, b, cs, AP);
    ap = save;
  }
  ap = 0;
  f_0ce7e0(I(&loc1), 0);
  return r;
}
//@ f_0bf8e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einem 32 x 32 Pixel großen Roh-Porträt oder
 *   Icon (a), einer optionalen Überschrift (b), dem Haupttext (c) und d auswählbaren Antwortoptionen über
 *   f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, den Rohbild-Zeiger a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption oder 0/-1 zurück.
 === Ende Beschreibung === */
int f_0bf8e0(M *p, int a, int b, int c, short d, ...)
{
  char *ap;
  int loc;
  int r;
  f_0ce7c0(I(&loc));
  p->i7a = 0;
  r = 0;
  ap = (char *)&d + 4;
  if (a != 0) {
    p->s80 = 0x20;
    p->s7e = p->s80;
  }
  if (c != 0) {
    if (f_0e9590(G, c) > 0) {
      char *save;
      r = f_0bec40((save = ap, I(p)), a, b, c, d, AP);
      ap = save;
    }
  }
  ap = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bf980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einer animierten Gesprächspartner-Sequenz
 *   (p->i8b = a, Abmessungen über f_011350), einer Überschrift (b), dem Haupttext (c) und d Antwortoptionen über
 *   f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, das Animations-Objekt a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption zurück.
 === Ende Beschreibung === */
int f_0bf980(M *p, int a, int b, int c, short d, ...)
{
  char *ap;
  int loc;
  int r;
  f_0ce7c0(I(&loc));
  ap = (char *)&d + 4;
  r = 0;
  if (c != 0) {
    if (f_0e9590(G, c) > 0) {
      char *save;
      save = ap;
      f_011350((p->i8b = a), I(&p->s7e), I(&p->s80));
      r = f_0bec40(I(p), p->i8b, b, c, d, AP);
      p->i8b = 0;
      ap = save;
    }
  }
  ap = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bfa20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese variadische Funktion öffnet ein Dialogfenster mit einem Bitmap-Objekt (p->i7a = a, Abmessungen
 *   über f_0fb210), einer Überschrift (b), dem Haupttext (c) und d Antwortoptionen über f_0bec40.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p, das Bitmap-Objekt a, den Titel b, den Haupttext c, die
 *   Optionsanzahl d sowie d variadische Antwort-Textkennungen entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption zurück.
 === Ende Beschreibung === */
int f_0bfa20(M *p, int a, int b, int c, short d, ...)
{
  char *ap;
  int loc;
  int r;
  f_0ce7c0(I(&loc));
  ap = (char *)&d + 4;
  r = 0;
  if (c != 0) {
    if (f_0e9590(G, c) > 0) {
      char *save;
      save = ap;
      ((RivaRasterImage*)((p->i7a = a)))->f_0fb210((short *)( I(&p->s7e)),(short *)( I(&p->s80)));
      r = f_0bec40(I(p), ((int)(((RivaRasterImage*)(a))->f_0fb0b0())), b, c, d, AP);
      p->i7a = 0;
      ap = save;
    }
  }
  ap = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bfac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sperrt das Verschieben eines Menüfensters (p->s20 = 1, p->s58 = 1), solange eine
 *   eingebettete Animation aktiv ist, und gibt den bisherigen Zustand von p->s58 zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion gibt den vorherigen Wert des Sperrflags p->s58 zurück.
 === Ende Beschreibung === */
int f_0bfac0(M *p)
{
  int o;
  p->s20 = 1;
  o = p->s58;
  p->s58 = 1;
  return o;
}
//@ f_0bfae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion hebt die Verschiebesperre eines Menüfensters wieder auf (p->s20 = 0, p->s58 = 0).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfae0(M *p)
{
  p->s20 = 0;
  p->s58 = 0;
}
//@ f_0bfaf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet das im linken oberen Bereich eines Dialogfensters (X = p->s14 + 15, Y =
 *   p->s16 + 15) eingebettete Bild: Je nach gesetztem Feld gibt sie entweder ein animiertes Porträt (p->i8b über
 *   f_0115c0), ein Bitmap-Objekt (p->i7a mit abgedunkeltem Schattenrahmen f_1481a0) oder einen Rohpixel-Block
 *   (p->i70) aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfaf0(M *p)
{
  char obj[12];
  if (p->i8b != 0) {
    f_0115c0(p->i8b, (short)(p->s14 + 0xf), (short)(p->s16 + 0xf), 0);
  } else {
    if (p->i7a != 0) {
      if (p->c8a == 1) {
        f_1481a0(I(d_1bdbd4), d_1a34e0, (short)(p->s14 + 0xf), (short)(p->s16 + 0xf), (short)(p->s7e + 2), (short)(p->s80 + 2), -32);
      }
      ((RivaRasterImage*)(p->i7a))->f_0fae30((void *)( d_1a34e0), (short)(p->s14 + 0x10), (short)(p->s16 + 0x10), 1);
      return;
    }
    if (p->i70 != 0) {
      ((int)(((RivaRasterImage*)(I(obj)))->f_0fac10( p->s7e, p->s80,(void *)( p->i70))));
      f_1481a0(I(d_1bdbd4), d_1a34e0, (short)(p->s14 + 0xf), (short)(p->s16 + 0xf), (short)(p->s7e + 2), (short)(p->s80 + 2), -32);
      ((RivaRasterImage*)(I(obj)))->f_0fade0((void *)( d_1a34e0), (short)(p->s14 + 0x10), (short)(p->s16 + 0x10));
      ((int)(((RivaRasterImage*)(I(obj)))->f_0fad20( 0)));
    }
  }
}
//@ f_0bfc50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die optionale Überschrift (p->i68) eines Dialogfensters in der hervorgehobenen
 *   Schriftfarbe 0xfd aus und passt anschließend den oberen Rand des Textfensters für den nachfolgenden
 *   Haupttext an.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfc50(M *p)
{
  int l28, l24, l20, l1c, l18;
  short n;
  if (p->i68) {
    f_05e320(G, 0xfd, -1);
    f_05e2a0(G, I(&l1c), I(&l18), I(&l20), I(&l28));
    f_05e7e0(G, p->s50, p->s52);
    f_05e2d0(G, -1, (short)(p->s26 - 0xf), (short)(p->s16 + 0xf), -1);
    n = f_0e9550(G, p->i68);
    ++n;
    f_05e2a0(G, I(&l28), I(&l28), I(&l24), I(&l28));
    f_05e2d0(G, (short)l1c, (short)l18, (short)((n << 3) + l24 - 2), (short)l28);
    f_05e320(G, 0xff, -1);
    p->s52 -= n;
  }
}
//@ f_0bfd40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion positioniert den Textcursor auf (p->s50, p->s52), gibt den Haupttext (p->i6c) des
 *   Dialogfensters über f_0e9550 aus und setzt den relativen Textoffset danach wieder auf (0, 0) zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfd40(M *p)
{
  f_05e7e0(G, p->s50, p->s52);
  if (p->s28) f_0e9550(G, p->i6c);
  f_05e7e0(G, 0, 0);
}
