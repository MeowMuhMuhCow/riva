/* === Beschreibung (Katalog) ===
 * Einheit gz_0421c0_t2 (0x043360 - 0x044300)
 *
 * Überblick
 * Die Einheit gz_0421c0_t2 bildet den zweiten Teil der Zugriffsmethoden der Heldenklasse (struct hero). Sie
 * verwaltet insbesondere Trunkenheit, Behinderung (BE), Krankheiten (Array ab Offset 0xc0), Gifte (Array ab
 * Offset 0xe8), Grundattribute und AT/PA-Tabellen, Kampfkoordinaten (0x4f1-0x4fb), die höheren Status-Bitfelder
 * im Wort bei Offset 0xbc, die Regenerationszähler (0x503-0x506) sowie das Abziehen und Regenerieren von
 * Astralpunkten (f_044230, f_0442b0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 134/143 gleich (suche.py 25.10.2026, Basis gz_0421c0_t2_P1.CPP)
// gz_0421c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0421C0-0x044300
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bcd30(int p1, int p2, int p3);                   // reg edx ebx stapel 0
short f_0d4c80(int p1);
short f_0d4cd0(int p1, int p2);
int f_0d5040(int a, int b, int c, int d, int e, int f);
int f_0d5290(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfabc;                    // 0x1BFABC
extern int d_1bfac0;                    // 0x1BFAC0
extern int d_1bfac4;                    // 0x1BFAC4
extern short d_1c219a;                    // 0x1C219A
extern int d_1c219c;                    // 0x1C219C
// -



struct E5 { unsigned char a, b, c, d; unsigned char f0:1; unsigned char f1:1; };
struct Fl { unsigned :9; unsigned f9:1; unsigned f10:1; unsigned :1; unsigned f12:1; unsigned :2; unsigned f15:1; unsigned f16:1; unsigned :2;
 unsigned f19:1; unsigned f20:1; unsigned f21:1; unsigned f22:1; unsigned f23:1; unsigned f24:1; unsigned f25:1; unsigned f26:1; unsigned f27:1;
 unsigned f28:1; unsigned f29:1; unsigned f30:1; unsigned f31:1; };
struct S7 { int a; char x, y; signed char b; };
#define FL(p) (*(Fl*)((p)+0xbc))
#define E8(p) ((E5*)((p)+0xe8))
#define EC(p) ((E5*)((p)+0xc0))

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_043360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert die Anzahl der offenen Talentsteigerungsversuche (skill_incs, Offset
 *   0x14e) des Helden um den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf das Byte p[0x14e].
 === Ende Beschreibung === */
void f_043360(char *p, int v)
{
  p[0x14e] += v;
}

//@ f_043370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zeitzähler am Offset 0xa1 (Trunkenheits- bzw. Sonderstatus-Timer) des Helden auf den
 *   angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Timerwert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das 32-Bit-Feld *(int*)(p + 0xa1).
 === Ende Beschreibung === */
void f_043370(char *p, int v)
{
  *(int*)(p+0xa1) = v;
}

//@ f_043380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen Wert des Zeitzählers am Offset 0xa1 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Timerwert als int zurück.
 * - Wichtige Variablen: Liest *(int*)(p + 0xa1).
 === Ende Beschreibung === */
int f_043380(char *p)
{
  return *(int*)(p+0xa1);
}

//@ f_043390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den Zeitzähler am Offset 0xa1 um die vergangene Zeitspanne v und begrenzt ihn nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Abzugswert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert *(int*)(p + 0xa1).
 === Ende Beschreibung === */
void f_043390(char *p, int v)
{
  if (v < *(int*)(p+0xa1)) *(int*)(p+0xa1) -= v; else *(int*)(p+0xa1) = 0;
}

//@ f_0433c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Wert in das Statusbyte bei Offset 0x97 der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x97].
 === Ende Beschreibung === */
void f_0433c0(char *p, int v)
{
  p[0x97] = v;
}

//@ f_0433d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte bei Offset 0x97 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als signed char zurück.
 * - Wichtige Variablen: Liest p[0x97].
 === Ende Beschreibung === */
signed char f_0433d0(char *p)
{
  return p[0x97];
}

//@ f_0433e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte bei Offset 0x95 (Kräuter-/Heilungs-Cooldown) der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x95].
 === Ende Beschreibung === */
char f_0433e0(char *p)
{
  return p[0x95];
}

//@ f_0433f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Statusbyte bei Offset 0x95 auf den angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x95].
 === Ende Beschreibung === */
void f_0433f0(char *p, int v)
{
  p[0x95] = v;
}

//@ f_043400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert das Statusbyte bei Offset 0x95 um den Summanden v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf p[0x95].
 === Ende Beschreibung === */
void f_043400(char *p, int v)
{
  p[0x95] += v;
}

//@ f_043410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt einen zusätzlichen Behinderungswert am Offset 0x45 der Heldenstruktur zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x45].
 === Ende Beschreibung === */
char f_043410(char *p)
{
  return p[0x45];
}

//@ f_043420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Feld bei Offset 0x45 auf den Wert v und begrenzt es nach oben auf maximal 12.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x45] mit Obergrenze 12.
 === Ende Beschreibung === */
void f_043420(char *p, signed char v)
{
  p[0x45] = v; if (v > 12) p[0x45] = 12;
}

//@ f_043430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert das Feld bei Offset 0x45 um v und begrenzt das Ergebnis nach unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert p[0x45] mit Untergrenze 0.
 === Ende Beschreibung === */
void f_043430(char *p, int v)
{
  p[0x45] += v; if ((signed char)p[0x45] < 0) p[0x45] = 0;
}

//@ f_043450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte bei Offset 0xb4 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0xb4].
 === Ende Beschreibung === */
char f_043450(char *p)
{
  return p[0xb4];
}

//@ f_043460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den Wert v in das Statusbyte bei Offset 0xb4 der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0xb4].
 === Ende Beschreibung === */
void f_043460(char *p, int v)
{
  p[0xb4] = v;
}

//@ f_043470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte bei Offset 0x93 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x93].
 === Ende Beschreibung === */
char f_043470(char *p)
{
  return p[0x93];
}

//@ f_043480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den Wert v in das Statusbyte bei Offset 0x93 der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x93].
 === Ende Beschreibung === */
void f_043480(char *p, int v)
{
  p[0x93] = v;
}

//@ f_043490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte bei Offset 0x94 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x94].
 === Ende Beschreibung === */
char f_043490(char *p)
{
  return p[0x94];
}

//@ f_0434a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den Wert v in das Statusbyte bei Offset 0x94 der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x94].
 === Ende Beschreibung === */
void f_0434a0(char *p, int v)
{
  p[0x94] = v;
}

//@ f_0434b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dekrementiert den Tageszähler am Offset 0xa6 (recipe_timer für alchemistische Rezepte), sofern
 *   dieser größer als 0 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Verringert p[0xa6] um 1.
 === Ende Beschreibung === */
void f_0434b0(char *p)
{
  if (*(signed char*)(p+0xa6) > 0) --*(signed char*)(p+0xa6);
}

//@ f_0434d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Tageszähler am Offset 0xa6 (recipe_timer) auf den angegebenen Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Tagesanzahl (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0xa6].
 === Ende Beschreibung === */
void f_0434d0(char *p, int v)
{
  p[0xa6] = v;
}

//@ f_0434e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den 32-Bit-Timer am Offset 0x9d (Kräuter-/Zauber-Wirkungsdauer) um die verstrichene
 *   Zeit v bis minimal 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Zeitabzug (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert *(int*)(p + 0x9d).
 === Ende Beschreibung === */
void f_0434e0(char *p, int v)
{
  if (v < *(int*)(p + 0x9d))
    *(int*)(p + 0x9d) -= v;
  else
    *(int*)(p + 0x9d) = 0;
}

//@ f_043510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den 32-Bit-Timer am Offset 0x9d auf den angegebenen Startwert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Timerwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(int*)(p + 0x9d).
 === Ende Beschreibung === */
void f_043510(char *p, int v)
{
  *(int*)(p+0x9d) = v;
}

//@ f_043520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen Stand des 32-Bit-Timers am Offset 0x9d aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Timerwert als int zurück.
 * - Wichtige Variablen: Liest *(int*)(p + 0x9d).
 === Ende Beschreibung === */
int f_043520(char *p)
{
  return *(int*)(p+0x9d);
}

//@ f_043530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Sättigungs- bzw. Bewegungsmodifikator am Offset 0x90 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x90].
 === Ende Beschreibung === */
char f_043530(char *p)
{
  return p[0x90];
}

//@ f_043540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Feld am Offset 0x90 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x90].
 === Ende Beschreibung === */
void f_043540(char *p, int v)
{
  p[0x90] = v;
}

//@ f_043550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert das Feld am Offset 0x90 um den Summanden v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf p[0x90].
 === Ende Beschreibung === */
void f_043550(char *p, int v)
{
  p[0x90] += v;
}

//@ f_043560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den Hungerwert (p[0x91]) des Helden um v und hält das Ergebnis im gültigen
 *   Prozentbereich 0 bis 100.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Hungeränderung (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert p[0x91] (hunger) mit Begrenzung auf [0, 100].
 === Ende Beschreibung === */
void f_043560(char *p, int v)
{
  p[0x91] += v; if ((signed char)p[0x91] < 0) p[0x91] = 0; if ((signed char)p[0x91] > 100) p[0x91] = 100;
}

//@ f_043590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den Durstwert (p[0x92]) des Helden um v und hält das Ergebnis im gültigen
 *   Prozentbereich 0 bis 100.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Durständerung (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert p[0x92] (thirst) mit Begrenzung auf [0, 100].
 === Ende Beschreibung === */
void f_043590(char *p, int v)
{
  p[0x92] += v; if ((signed char)p[0x92] < 0) p[0x92] = 0; if ((signed char)p[0x92] > 100) p[0x92] = 100;
}

//@ f_0435c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Status (a: -1 = vergiftet, 0 = gesund, 1 = im Heilungsverlauf) des Gifteintrags i
 *   (Array E8 ab Offset 0xe8, je 5 Bytes) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i, 1 bis 9) und gibt
 *   den Status als char zurück.
 * - Wichtige Variablen: Liest E8(p)[i].a.
 === Ende Beschreibung === */
char f_0435c0(char *p, short i)
{
  return E8(p)[i].a;
}

//@ f_0435e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Status (a) des Gifteintrags i im Gift-Array des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den neuen Status
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].a.
 === Ende Beschreibung === */
void f_0435e0(char *p, short i, int v)
{
  E8(p)[i].a = v;
}

//@ f_043600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Zeitzähler (b, vergangene Stunden/Ticks) des Gifteintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i) und gibt den
 *   Zählerstand als char zurück.
 * - Wichtige Variablen: Liest E8(p)[i].b.
 === Ende Beschreibung === */
char f_043600(char *p, short i)
{
  return E8(p)[i].b;
}

//@ f_043620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zeitzähler (b) des Gifteintrags i auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den neuen
 *   Zählerstand (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].b.
 === Ende Beschreibung === */
void f_043620(char *p, short i, int v)
{
  E8(p)[i].b = v;
}

//@ f_043640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den Zeitzähler (b) des Gifteintrags i um v und begrenzt ihn nach unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie die Änderung (v)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert E8(p)[i].b.
 === Ende Beschreibung === */
void f_043640(char *p, short i, int v)
{
  E8(p)[i].b += v; if ((signed char)E8(p)[i].b < 0) E8(p)[i].b = 0;
}

//@ f_043670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den ersten Attributsverlustzähler (c) des Gifteintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i) und gibt den Wert
 *   als char zurück.
 * - Wichtige Variablen: Liest E8(p)[i].c.
 === Ende Beschreibung === */
char f_043670(char *p, short i)
{
  return E8(p)[i].c;
}

//@ f_043690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den ersten Attributsverlustzähler (c) des Gifteintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den neuen Wert (v)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].c.
 === Ende Beschreibung === */
void f_043690(char *p, short i, int v)
{
  E8(p)[i].c = v;
}

//@ f_0436b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den ersten Attributsverlustzähler (c) des Gifteintrags i um v und begrenzt ihn nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie die Änderung (v)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert E8(p)[i].c.
 === Ende Beschreibung === */
void f_0436b0(char *p, short i, int v)
{
  E8(p)[i].c += v; if ((signed char)E8(p)[i].c < 0) E8(p)[i].c = 0;
}

//@ f_0436e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den zweiten Attributsverlustzähler (d) des Gifteintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i) und gibt den Wert
 *   als char zurück.
 * - Wichtige Variablen: Liest E8(p)[i].d.
 === Ende Beschreibung === */
char f_0436e0(char *p, short i)
{
  return E8(p)[i].d;
}

//@ f_043700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den zweiten Attributsverlustzähler (d) des Gifteintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den neuen Wert (v)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].d.
 === Ende Beschreibung === */
void f_043700(char *p, short i, int v)
{
  E8(p)[i].d = v;
}

//@ f_043720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den zweiten Attributsverlustzähler (d) des Gifteintrags i um v und begrenzt ihn nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie die Änderung (v)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert E8(p)[i].d.
 === Ende Beschreibung === */
void f_043720(char *p, short i, int v)
{
  E8(p)[i].d += v; if ((signed char)E8(p)[i].d < 0) E8(p)[i].d = 0;
}

//@ f_043750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das erste Statusbit (f0) des Gifteintrags i.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i) und gibt den Bitwert
 *   (0 oder 1) zurück.
 * - Wichtige Variablen: Liest E8(p)[i].f0.
 === Ende Beschreibung === */
unsigned f_043750(char *p, short i)
{
  return E8(p)[i].f0;
}

//@ f_043770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das erste Statusbit (f0) des Gifteintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den Bitwert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].f0.
 === Ende Beschreibung === */
void f_043770(char *p, short i, int v)
{
  E8(p)[i].f0 = v;
}

//@ f_0437b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das zweite Statusbit (f1, ob das Gift bereits diagnostiziert/bekannt ist) des
 *   Gifteintrags i.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Giftindex (i) und gibt 1 zurück,
 *   wenn die Vergiftung bekannt ist, sonst 0.
 * - Wichtige Variablen: Liest E8(p)[i].f1.
 === Ende Beschreibung === */
unsigned f_0437b0(char *p, short i)
{
  return E8(p)[i].f1;
}

//@ f_0437e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das zweite Statusbit (f1, Vergiftung bekannt) des Gifteintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Giftindex (i) sowie den Bitwert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt E8(p)[i].f1.
 === Ende Beschreibung === */
void f_0437e0(char *p, short i, int v)
{
  E8(p)[i].f1 = v;
}

//@ f_043820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Status (a: -1 = erkrankt, 0 = gesund, 1 = in Heilung) des Krankheitseintrags i
 *   (Array EC ab Offset 0xc0, je 5 Bytes) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i, 1 bis 7) und
 *   gibt den Status als char zurück.
 * - Wichtige Variablen: Liest EC(p)[i].a.
 === Ende Beschreibung === */
char f_043820(char *p, short i)
{
  return EC(p)[i].a;
}

//@ f_043840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Status (a) des Krankheitseintrags i im Krankheits-Array des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den neuen
 *   Status (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].a.
 === Ende Beschreibung === */
void f_043840(char *p, short i, int v)
{
  EC(p)[i].a = v;
}

//@ f_043860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Tages-/Verlaufszähler (b) des Krankheitseintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i) und gibt den
 *   Zählerstand als char zurück.
 * - Wichtige Variablen: Liest EC(p)[i].b.
 === Ende Beschreibung === */
char f_043860(char *p, short i)
{
  return EC(p)[i].b;
}

//@ f_043880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Tages-/Verlaufszähler (b) des Krankheitseintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den neuen
 *   Zählerstand (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].b.
 === Ende Beschreibung === */
void f_043880(char *p, short i, int v)
{
  EC(p)[i].b = v;
}

//@ f_0438a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den Tages-/Verlaufszähler (b) des Krankheitseintrags i um v und begrenzt ihn nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie die Änderung
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert EC(p)[i].b.
 === Ende Beschreibung === */
void f_0438a0(char *p, short i, int v)
{
  EC(p)[i].b += v; if ((signed char)EC(p)[i].b < 0) EC(p)[i].b = 0;
}

//@ f_0438d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den ersten Attributsverlustzähler (c) des Krankheitseintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i) und gibt den
 *   Wert als char zurück.
 * - Wichtige Variablen: Liest EC(p)[i].c.
 === Ende Beschreibung === */
char f_0438d0(char *p, short i)
{
  return EC(p)[i].c;
}

//@ f_0438f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den ersten Attributsverlustzähler (c) des Krankheitseintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den neuen
 *   Wert (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].c.
 === Ende Beschreibung === */
void f_0438f0(char *p, short i, int v)
{
  EC(p)[i].c = v;
}

//@ f_043910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den ersten Attributsverlustzähler (c) des Krankheitseintrags i um v und begrenzt ihn
 *   nach unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie die Änderung
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert EC(p)[i].c.
 === Ende Beschreibung === */
void f_043910(char *p, short i, int v)
{
  EC(p)[i].c += v; if ((signed char)EC(p)[i].c < 0) EC(p)[i].c = 0;
}

//@ f_043940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den zweiten Attributsverlustzähler (d) des Krankheitseintrags i aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i) und gibt den
 *   Wert als char zurück.
 * - Wichtige Variablen: Liest EC(p)[i].d.
 === Ende Beschreibung === */
char f_043940(char *p, short i)
{
  return EC(p)[i].d;
}

//@ f_043960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den zweiten Attributsverlustzähler (d) des Krankheitseintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den neuen
 *   Wert (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].d.
 === Ende Beschreibung === */
void f_043960(char *p, short i, int v)
{
  EC(p)[i].d = v;
}

//@ f_043980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den zweiten Attributsverlustzähler (d) des Krankheitseintrags i um v und begrenzt
 *   ihn nach unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie die Änderung
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert EC(p)[i].d.
 === Ende Beschreibung === */
void f_043980(char *p, short i, int v)
{
  EC(p)[i].d += v; if ((signed char)EC(p)[i].d < 0) EC(p)[i].d = 0;
}

//@ f_0439b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das erste Statusbit (f0, Heilungsversuch bereits unternommen) des Krankheitseintrags i.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i) und gibt den
 *   Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest EC(p)[i].f0.
 === Ende Beschreibung === */
unsigned f_0439b0(char *p, short i)
{
  return EC(p)[i].f0;
}

//@ f_0439d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das erste Statusbit (f0) des Krankheitseintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].f0.
 === Ende Beschreibung === */
void f_0439d0(char *p, short i, int v)
{
  EC(p)[i].f0 = v;
}

//@ f_043a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das zweite Statusbit (f1, ob die Krankheit diagnostiziert/bekannt ist) des
 *   Krankheitseintrags i.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Krankheitsindex (i) und gibt 1
 *   zurück, wenn die Krankheit bekannt ist, sonst 0.
 * - Wichtige Variablen: Liest EC(p)[i].f1.
 === Ende Beschreibung === */
unsigned f_043a10(char *p, short i)
{
  return EC(p)[i].f1;
}

//@ f_043a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das zweite Statusbit (f1, Krankheit bekannt) des Krankheitseintrags i auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Krankheitsindex (i) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt EC(p)[i].f1.
 === Ende Beschreibung === */
void f_043a40(char *p, short i, int v)
{
  EC(p)[i].f1 = v;
}

//@ f_043a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen unverzerrten Grundwert der Eigenschaft i (Offset 0x47 + i * 3, ohne
 *   temporären Modifikator) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Eigenschaftsindex (i) und gibt den
 *   aktuellen Eigenschaftswert als char zurück.
 * - Wichtige Variablen: Liest p[0x47 + i * 3].
 === Ende Beschreibung === */
char f_043a80(char *p, short i)
{
  return p[0x47 + i*3];
}

//@ f_043aa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den permanenten Maximal-/Normalwert der Eigenschaft i (Offset 0x46 + i * 3) auf den Wert
 *   v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Eigenschaftsindex (i) sowie den neuen
 *   Normalwert (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x46 + i * 3].
 === Ende Beschreibung === */
void f_043aa0(char *p, short i, int v)
{
  p[0x46 + i*3] = v;
}

//@ f_043ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den permanenten Maximal-/Normalwert der Eigenschaft i (Offset 0x46 + i * 3) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Eigenschaftsindex (i) und gibt den
 *   Normalwert als char zurück.
 * - Wichtige Variablen: Liest p[0x46 + i * 3].
 === Ende Beschreibung === */
char f_043ac0(char *p, short i)
{
  return p[0x46 + i*3];
}

//@ f_043ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Heldentypus (type, Offset 0x33) auf den angegebenen Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Typuswert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x33].
 === Ende Beschreibung === */
void f_043ae0(char *p, int v)
{
  p[0x33] = v;
}

//@ f_043af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Geschlecht (sex, Offset 0x34) des Helden auf den angegebenen Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das Geschlecht (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x34].
 === Ende Beschreibung === */
void f_043af0(char *p, int v)
{
  p[0x34] = v;
}

//@ f_043b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Attackewert der Waffengattung i (Offset 0x7a + i, 0 bis 6) auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Waffengattungsindex (i) sowie den
 *   Attackewert (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x7a + i].
 === Ende Beschreibung === */
void f_043b00(char *p, short i, int v)
{
  p[i + 0x7a] = v;
}

//@ f_043b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Paradewert der Waffengattung i (Offset 0x81 + i, 0 bis 6) auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Waffengattungsindex (i) sowie den
 *   Paradewert (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x81 + i].
 === Ende Beschreibung === */
void f_043b10(char *p, short i, int v)
{
  p[i + 0x81] = v;
}

//@ f_043b20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Grund-Attackewert der Waffengattung i (Offset 0x7a + i) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Waffengattungsindex (i) und gibt
 *   den Attackewert als char zurück.
 * - Wichtige Variablen: Liest p[0x7a + i].
 === Ende Beschreibung === */
char f_043b20(char *p, short i)
{
  return p[i + 0x7a];
}

//@ f_043b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Grund-Paradewert der Waffengattung i (Offset 0x81 + i) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Waffengattungsindex (i) und gibt
 *   den Paradewert als char zurück.
 * - Wichtige Variablen: Liest p[0x81 + i].
 === Ende Beschreibung === */
char f_043b30(char *p, short i)
{
  return p[i + 0x81];
}

//@ f_043b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert den Attackewert der Waffengattung i (Offset 0x7a + i) um v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Waffengattungsindex (i) sowie die
 *   Änderung (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf p[0x7a + i].
 === Ende Beschreibung === */
void f_043b40(char *p, short i, int v)
{
  p[i + 0x7a] += v;
}

//@ f_043b50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert den Paradewert der Waffengattung i (Offset 0x81 + i) um v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Waffengattungsindex (i) sowie die
 *   Änderung (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf p[0x81 + i].
 === Ende Beschreibung === */
void f_043b50(char *p, short i, int v)
{
  p[i + 0x81] += v;
}

//@ f_043b60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuellen Lebenspunkte (le, Offset 0x72) des Helden direkt auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen LE-Wert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x72).
 === Ende Beschreibung === */
void f_043b60(char *p, int v)
{
  *(short*)(p+0x72) = v;
}

//@ f_043b70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die maximalen Lebenspunkte (le_max, Offset 0x70) des Helden direkt auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Maximal-LE-Wert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x70).
 === Ende Beschreibung === */
void f_043b70(char *p, int v)
{
  *(short*)(p+0x70) = v;
}

//@ f_043b80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuellen Astralpunkte (ae, Offset 0x76) des Helden direkt auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen AE-Wert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x76).
 === Ende Beschreibung === */
void f_043b80(char *p, int v)
{
  *(short*)(p+0x76) = v;
}

//@ f_043b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die maximalen Astralpunkte (ae_max, Offset 0x74) des Helden direkt auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Maximal-AE-Wert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x74).
 === Ende Beschreibung === */
void f_043b90(char *p, int v)
{
  *(short*)(p+0x74) = v;
}

//@ f_043ba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Körpergröße (height, Offset 0x35) des Helden auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Körpergröße (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x35].
 === Ende Beschreibung === */
void f_043ba0(char *p, int v)
{
  p[0x35] = v;
}

//@ f_043bb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Körpergewicht (weight, Offset 0x36) des Helden auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das Gewicht (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x36).
 === Ende Beschreibung === */
void f_043bb0(char *p, int v)
{
  *(short*)(p+0x36) = v;
}

//@ f_043bc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Bytefeld am Offset 0x38 (Haar-/Augenfarbe bzw. Charaktermerkmal) auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x38].
 === Ende Beschreibung === */
void f_043bc0(char *p, int v)
{
  p[0x38] = v;
}

//@ f_043bd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Erfahrungsstufe (level, Offset 0x39) des Helden auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Stufe (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x39].
 === Ende Beschreibung === */
void f_043bd0(char *p, int v)
{
  p[0x39] = v;
}

//@ f_043be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Zusatzbyte am Offset 0x12 innerhalb des Inventarslots i (Gesamtoffset 0x1b8 + i *
 *   0x1b) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i) und gibt den
 *   Bytewert als short zurück.
 * - Wichtige Variablen: Liest (signed char)p[0x1b8 + i * 0x1b].
 === Ende Beschreibung === */
short f_043be0(char *p, short i)
{
  return (signed char)p[0x1b8 + i*0x1b];
}

//@ f_043c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das 16-Bit-Feld am Offset 0x4f1 (Kampf-/Animationskoordinate X) der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als short zurück.
 * - Wichtige Variablen: Liest *(short*)(p + 0x4f1).
 === Ende Beschreibung === */
short f_043c10(char *p)
{
  return *(short*)(p+0x4f1);
}

//@ f_043c20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das 16-Bit-Feld am Offset 0x4f1 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x4f1).
 === Ende Beschreibung === */
void f_043c20(char *p, int v)
{
  *(short*)(p+0x4f1) = v;
}

//@ f_043c30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das 16-Bit-Feld am Offset 0x4f3 (Kampf-/Animationskoordinate Y) der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als short zurück.
 * - Wichtige Variablen: Liest *(short*)(p + 0x4f3).
 === Ende Beschreibung === */
short f_043c30(char *p)
{
  return *(short*)(p+0x4f3);
}

//@ f_043c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das 16-Bit-Feld am Offset 0x4f3 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x4f3).
 === Ende Beschreibung === */
void f_043c40(char *p, int v)
{
  *(short*)(p+0x4f3) = v;
}

//@ f_043c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den 16-Bit-Zähler am Offset 0x4f5 (Aktionspunkte/Kampfrunden-Zähler) der Heldenstruktur
 *   aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als short zurück.
 * - Wichtige Variablen: Liest *(short*)(p + 0x4f5).
 === Ende Beschreibung === */
short f_043c50(char *p)
{
  return *(short*)(p+0x4f5);
}

//@ f_043c60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den 16-Bit-Zähler am Offset 0x4f5 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x4f5).
 === Ende Beschreibung === */
void f_043c60(char *p, int v)
{
  *(short*)(p+0x4f5) = v;
}

//@ f_043c70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Addiert den Wert v auf den 16-Bit-Zähler am Offset 0x4f5.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert *(short*)(p + 0x4f5).
 === Ende Beschreibung === */
void f_043c70(char *p, int v)
{
  *(short*)(p+0x4f5) += v;
}

//@ f_043c80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f9 (Bit 9 im 32-Bit-Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f9.
 === Ende Beschreibung === */
unsigned f_043c80(char *p)
{
  return FL(p).f9;
}

//@ f_043c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f12 (Bit 12 im Statusfeld bei Offset 0xbc, Sonderporträt-Zustand z. B.
 *   Verwandlung/Verfluchung) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f12.
 === Ende Beschreibung === */
unsigned f_043c90(char *p)
{
  return FL(p).f12;
}

//@ f_043ca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f19 (Bit 19 im Statusfeld bei Offset 0xbc, zweiter Sonderporträt-Zustand)
 *   des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f19.
 === Ende Beschreibung === */
unsigned f_043ca0(char *p)
{
  return FL(p).f19;
}

//@ f_043cb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f20 (Bit 20 im Statusfeld bei Offset 0xbc, heller Lichtzauber z. B. *Flim
 *   Flam*) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f20.
 === Ende Beschreibung === */
unsigned f_043cb0(char *p)
{
  return FL(p).f20;
}

//@ f_043cc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f21 (Bit 21 im Statusfeld bei Offset 0xbc, Dunkelheitszauber *Dunkelheit*)
 *   des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f21.
 === Ende Beschreibung === */
unsigned f_043cc0(char *p)
{
  return FL(p).f21;
}

//@ f_043cd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f23 (Bit 23 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f23.
 === Ende Beschreibung === */
unsigned f_043cd0(char *p)
{
  return FL(p).f23;
}

//@ f_043ce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f15 (Bit 15 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f15.
 === Ende Beschreibung === */
unsigned f_043ce0(char *p)
{
  return FL(p).f15;
}

//@ f_043cf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f16 (Bit 16 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f16.
 === Ende Beschreibung === */
unsigned f_043cf0(char *p)
{
  return FL(p).f16;
}

//@ f_043d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f10 (Bit 10 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f10.
 === Ende Beschreibung === */
unsigned f_043d00(char *p)
{
  return FL(p).f10;
}

//@ f_043d10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f24 (Bit 24 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f24.
 === Ende Beschreibung === */
unsigned f_043d10(char *p)
{
  return FL(p).f24;
}

//@ f_043d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f24 (Bit 24 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f24.
 === Ende Beschreibung === */
void f_043d20(char *p, unsigned v)
{
  FL(p).f24 = v;
}

//@ f_043d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f25 (Bit 25 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f25.
 === Ende Beschreibung === */
unsigned f_043d40(char *p)
{
  return FL(p).f25;
}

//@ f_043d50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f25 (Bit 25 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f25.
 === Ende Beschreibung === */
void f_043d50(char *p, unsigned v)
{
  FL(p).f25 = v;
}

//@ f_043d70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f23 (Bit 23 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f23.
 === Ende Beschreibung === */
void f_043d70(char *p, unsigned v)
{
  FL(p).f23 = v;
}

//@ f_043d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f10 (Bit 10 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f10.
 === Ende Beschreibung === */
void f_043d90(char *p, signed char v)
{
  FL(p).f10 = v;
}

//@ f_043dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Kampf-Statusbyte am Offset 0x4f7 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x4f7].
 === Ende Beschreibung === */
char f_043dc0(char *p)
{
  return p[0x4f7];
}

//@ f_043dd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Kampf-Statusbyte am Offset 0x4f7 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x4f7].
 === Ende Beschreibung === */
void f_043dd0(char *p, int v)
{
  p[0x4f7] = v;
}

//@ f_043de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Porträtleisten-Slotnummer am Offset 0x4f9 des Helden auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Slotnummer (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x4f9].
 === Ende Beschreibung === */
void f_043de0(char *p, int v)
{
  p[0x4f9] = v;
}

//@ f_043df0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Porträtleisten-Slotnummer am Offset 0x4f9 des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Slotnummer als char zurück.
 * - Wichtige Variablen: Liest p[0x4f9].
 === Ende Beschreibung === */
char f_043df0(char *p)
{
  return p[0x4f9];
}

//@ f_043e00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Statusbyte am Offset 0x4fa der Heldenstruktur auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x4fa].
 === Ende Beschreibung === */
void f_043e00(char *p, int v)
{
  p[0x4fa] = v;
}

//@ f_043e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte am Offset 0x4fa der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x4fa].
 === Ende Beschreibung === */
char f_043e10(char *p)
{
  return p[0x4fa];
}

//@ f_043e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Aufenthalts-/Sonderstatusbyte am Offset 0x4fb (z. B. 5 = in Herberge zurückgelassen)
 *   auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Status (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x4fb].
 === Ende Beschreibung === */
void f_043e20(char *p, int v)
{
  p[0x4fb] = v;
}

//@ f_043e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Aufenthalts-/Sonderstatusbyte am Offset 0x4fb des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Statuswert als char zurück.
 * - Wichtige Variablen: Liest p[0x4fb].
 === Ende Beschreibung === */
char f_043e30(char *p)
{
  return p[0x4fb];
}

//@ f_043e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Bytefeld am Offset 0xb6 der Heldenstruktur auf v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0xb6].
 === Ende Beschreibung === */
void f_043e40(char *p, int v)
{
  p[0xb6] = v;
}

//@ f_043e50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Bytefeld am Offset 0xb6 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0xb6].
 === Ende Beschreibung === */
char f_043e50(char *p)
{
  return p[0xb6];
}

//@ f_043e60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Abenteuerpunkte (ap, Offset 0x3a) des Helden direkt auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen AP-Stand (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(int*)(p + 0x3a).
 === Ende Beschreibung === */
void f_043e60(char *p, int v)
{
  *(int*)(p+0x3a) = v;
}

//@ f_043e70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f26 (Bit 26 im Statusfeld bei Offset 0xbc, Regenerationsbonus durch
 *   Schlaf/Rast) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f26.
 === Ende Beschreibung === */
unsigned f_043e70(char *p)
{
  return FL(p).f26;
}

//@ f_043e80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f26 (Bit 26 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f26.
 === Ende Beschreibung === */
void f_043e80(char *p, unsigned v)
{
  FL(p).f26 = v;
}

//@ f_043ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f30 (Bit 30 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f30.
 === Ende Beschreibung === */
unsigned f_043ea0(char *p)
{
  return FL(p).f30;
}

//@ f_043eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f30 (Bit 30 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f30.
 === Ende Beschreibung === */
void f_043eb0(char *p, unsigned v)
{
  FL(p).f30 = v;
}

//@ f_043ed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f31 (Bit 31 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f31.
 === Ende Beschreibung === */
unsigned f_043ed0(char *p)
{
  return FL(p).f31;
}

//@ f_043ee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f31 (Bit 31 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f31.
 === Ende Beschreibung === */
void f_043ee0(char *p, int v)
{
  FL(p).f31 = v;
}

//@ f_043f00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f27 (Bit 27 im Statusfeld bei Offset 0xbc, hoher Regenerationsbonus z. B.
 *   gutes Herbergszimmer) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f27.
 === Ende Beschreibung === */
unsigned f_043f00(char *p)
{
  return FL(p).f27;
}

//@ f_043f10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f27 (Bit 27 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f27.
 === Ende Beschreibung === */
void f_043f10(char *p, unsigned v)
{
  FL(p).f27 = v;
}

//@ f_043f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f28 (Bit 28 im Statusfeld bei Offset 0xbc, mittlerer Regenerationsbonus)
 *   des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f28.
 === Ende Beschreibung === */
unsigned f_043f30(char *p)
{
  return FL(p).f28;
}

//@ f_043f50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f28 (Bit 28 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f28.
 === Ende Beschreibung === */
void f_043f50(char *p, unsigned v)
{
  FL(p).f28 = v;
}

//@ f_043f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den LE-Regenerationsraten-Modifikator am Offset 0x503 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Modifikator als char zurück.
 * - Wichtige Variablen: Liest p[0x503].
 === Ende Beschreibung === */
char f_043f70(char *p)
{
  return p[0x503];
}

//@ f_043f80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den gebrochenen LE-Regenerations-Akkumulator (0 bis 99) am Offset 0x505 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Akkumulatorstand als char
 *   zurück.
 * - Wichtige Variablen: Liest p[0x505].
 === Ende Beschreibung === */
char f_043f80(char *p)
{
  return p[0x505];
}

//@ f_043f90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert den neuen Stand des gebrochenen LE-Regenerations-Akkumulators am Offset 0x505.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Akkumulatorwert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x505].
 === Ende Beschreibung === */
void f_043f90(char *p, int v)
{
  p[0x505] = v;
}

//@ f_043fa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den AE-Regenerationsraten-Modifikator am Offset 0x504 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Modifikator als char zurück.
 * - Wichtige Variablen: Liest p[0x504].
 === Ende Beschreibung === */
char f_043fa0(char *p)
{
  return p[0x504];
}

//@ f_043fb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den gebrochenen AE-Regenerations-Akkumulator (0 bis 99) am Offset 0x506 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Akkumulatorstand als char
 *   zurück.
 * - Wichtige Variablen: Liest p[0x506].
 === Ende Beschreibung === */
char f_043fb0(char *p)
{
  return p[0x506];
}

//@ f_043fc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert den neuen Stand des gebrochenen AE-Regenerations-Akkumulators am Offset 0x506.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Akkumulatorwert (v) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x506].
 === Ende Beschreibung === */
void f_043fc0(char *p, int v)
{
  p[0x506] = v;
}

//@ f_043fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht sowohl den LE- als auch den AE-Regenerationsraten-Modifikator (p[0x503] und p[0x504])
 *   um den Bonus v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bonuswert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Addiert v auf p[0x503] und p[0x504].
 === Ende Beschreibung === */
void f_043fd0(char *p, int v)
{
  p[0x503] += v; p[0x504] += v;
}

//@ f_043ff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert sowohl den LE- als auch den AE-Regenerationsraten-Modifikator (p[0x503] und
 *   p[0x504]) um v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Abzugswert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Subtrahiert v von p[0x503] und p[0x504].
 === Ende Beschreibung === */
void f_043ff0(char *p, int v)
{
  p[0x503] -= v; p[0x504] -= v;
}

//@ f_044010
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt über das Buff-System (f_0d5040) einen zeitlich befristeten Modifikator des Typs 0x16 mit
 *   Stärke v und Dauer w auf dem Helden an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), die Effektstärke (v) sowie die
 *   Wirkungsdauer (w) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Ruft f_0d4c80 (freier Buff-Slot) und f_0d5040 (Buff eintragen) auf.
 === Ende Beschreibung === */
void f_044010(char *p, int v, int w)
{
  short s = f_0d4c80((int)p);
  f_0d5040((int)p, s, w, 0, (signed char)v, 0x16);
}

//@ f_044030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Tötet den Helden sofort, indem ihm über f_044300 Schaden in Höhe seiner gesamten aktuellen
 *   Lebenspunkte (*(short*)(p + 0x72)) zugefügt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt p->le (0x72) an die Schadensfunktion f_044300.
 === Ende Beschreibung === */
void f_044030(char *p)
{
  f_044300((int)p, *(short*)(p+0x72));
}

//@ f_044040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f29 (Bit 29 im Statusfeld bei Offset 0xbc) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f29.
 === Ende Beschreibung === */
unsigned f_044040(char *p)
{
  return FL(p).f29;
}

//@ f_044060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Statusbit f29 (Bit 29 im Statusfeld bei Offset 0xbc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Bitwert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt FL(p).f29.
 === Ende Beschreibung === */
void f_044060(char *p, unsigned v)
{
  FL(p).f29 = v;
}

//@ f_044080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbit f22 (Bit 22 im Statusfeld bei Offset 0xbc, Trunkenheits-/Wirtshaus-Sperre)
 *   des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Liest FL(p).f22.
 === Ende Beschreibung === */
unsigned f_044080(char *p)
{
  return FL(p).f22;
}

//@ f_044090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt dem Helden einen zeitlich befristeten Gewandtheits-Malus (Buff-Typ 0x15, Attribut 2 = GE,
 *   z. B. durch Alkohol oder Übermüdung) hinzu oder verlängert und verstärkt einen bereits laufenden Effekt im
 *   Buff-Array (p + 0x55b, begrenzt auf maximal 0x13c680 Ticks und -6 GE).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), die Wirkungsdauer (v) sowie die
 *   Malus-Stärke (n) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft Bit 0x40 in p[0xbe], verwaltet die Buff-Struktur S7 ab p + 0x55b und passt GE über
 *   f_045430 an.
 === Ende Beschreibung === */
void f_044090(char *p, int v, short n)
{
  short i;
  int amount;
  short change;
  int scratch;
  short saved_n = n;
  if (!(p[0xbe] & 0x40)) {
    f_0d5040((int)p, f_0d4c80((int)p), v, 2, (signed char)-*(signed char *)&saved_n, 0x15);
  } else {
    i = f_0d4cd0((int)p, 0x15);
    scratch=i;
    scratch = (scratch & 0) ? 0 : scratch; // Haelt die Registervergabe fuer scratch wie im Original
    change = saved_n;
    amount = v;
    if (amount + ((volatile S7*)(p+0x55b))[scratch].a >= 0x13c680)
      amount = 0x13c680 - ((S7*)(p+0x55b))[scratch].a;
    scratch=((S7*)(p+0x55b))[i].b;
    if ((int)change - scratch >= 6)
      change = ((S7*)(p+0x55b))[i].b + 6;
    if (amount > 0)
      ((S7*)(p+0x55b))[i].a += amount;
    if (change > 0) {
      ((S7*)(p+0x55b))[i].b -= change;
      f_045430((int)p, 2, (signed char)-change);
    }
  }
  d_1bfabc = (d_1bfabc & 0) ? 0 : d_1bfabc; // Neutrale Globalkopie haelt das Epilog-Layout wie im Original
}


//@ f_044190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hebt einen aktiven Gewandtheits-Malus (Buff-Typ 0x15) beim Helden vorzeitig über f_0d5290 auf,
 *   sofern das entsprechende Statusbit (p[0xbe] & 0x40) gesetzt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft p[0xbe] & 0x40 und ruft f_0d5290(p, 0x15) auf.
 === Ende Beschreibung === */
void f_044190(char *p)
{
  if (p[0xbe] & 0x40) f_0d5290((int)p, 0x15);
}

//@ f_0441b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Statusbyte am Offset 0x507 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als char zurück.
 * - Wichtige Variablen: Liest p[0x507].
 === Ende Beschreibung === */
char f_0441b0(char *p)
{
  return p[0x507];
}

//@ f_0441c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Statusbyte am Offset 0x507 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p[0x507].
 === Ende Beschreibung === */
void f_0441c0(char *p, int v)
{
  p[0x507] = v;
}

//@ f_0441d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Addiert den vorzeichenbehafteten Wert v auf das Byte am Offset 0x507 und begrenzt das Ergebnis
 *   auf den Bereich 0 bis 255.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Änderung (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert p[0x507] mit Clamping auf [0, 0xff].
 === Ende Beschreibung === */
void f_0441d0(char *p, int v)
{
  short n = (unsigned char)p[0x507] + (signed char)v;
  if (n < 0) n = 0; else if (n > 0xff) n = 0xff;
  p[0x507] = n;
}

//@ f_044210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das 16-Bit-Feld am Offset 0x508 der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als short zurück.
 * - Wichtige Variablen: Liest *(short*)(p + 0x508).
 === Ende Beschreibung === */
short f_044210(char *p)
{
  return *(short*)(p+0x508);
}

//@ f_044220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das 16-Bit-Feld am Offset 0x508 auf den Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(short*)(p + 0x508).
 === Ende Beschreibung === */
void f_044220(char *p, int v)
{
  *(short*)(p+0x508) = v;
}

//@ f_044230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht einem lebenden, magiebegabten Helden (f_042a10) beim Zaubern n Astralpunkte (ae, Offset
 *   0x76) ab. Handelt es sich um einen Magier (type == 9) mit mindestens dem 4. Stabzauber (f_0432d0 >= 4,
 *   *Kraftfokus*), werden die Astralkosten um 2 Punkte reduziert (jedoch nicht unter 0), und die blaue AE-Säule
 *   in der Statusleiste (f_0bcd30) wird aktualisiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die abzuziehenden Astralpunkte (n) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Verringert *(short*)(p + 0x76) (ae) und aktualisiert die Statusleiste d_1bf230.
 === Ende Beschreibung === */
void f_044230(char *p, short n)
{
  if (!((char)(f_042470((struct hero *)((int)p)))) && n > 0 && f_042a10((struct hero *)((int)p))) {
      if ((signed char)p[0x33] == 9) {
        if (f_0432d0((struct hero *)((int)p)) >= 4) { n -= 2; if (n < 0) n = 0; }
      }
#pragma aux f_043df0 "f_043df0"
      f_0bcd30((int)&d_1bf230, (signed char)f_043df0(p), 1);
      *(short*)(p+0x76) -= n;
      if (*(short*)(p+0x76) < 0) *(short*)(p+0x76) = 0;
  }
}

//@ f_0442b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt einem lebenden, magiebegabten Helden n Astralpunkte (ae, Offset 0x76) hinzu, begrenzt den
 *   neuen Stand auf das Maximum (ae_max, Offset 0x74) und setzt das Neuzeichnungs-Flag d_1c219a = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die hinzuzufügenden Astralpunkte (n)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Erhöht *(short*)(p + 0x76) bis maximal *(short*)(p + 0x74) und setzt d_1c219a.
 === Ende Beschreibung === */
void f_0442b0(char *p, short n)
{
  if (!((char)(f_042470((struct hero *)((int)p)))) && n > 0) {
    if (f_042a10((struct hero *)((int)p))) {
      *(short*)(p+0x76) = *(short*)(p+0x76) + n;
      short t = (*(short*)(p+0x76));
      if (*(short*)(p+0x74) < t) *(short*)(p+0x76) = *(short*)(p+0x74);
      d_1c219a = 1;
    }
  }
}
