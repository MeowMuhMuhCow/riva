/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t1c (0x145920 - 0x145970)
 *
 * Überblick
 * Diese Einheit ergänzt das Würfelmodul (dice.cpp) um eine Hilfsfunktion zur Bestimmung des minimal und maximal
 * möglichen Ergebnisses einer DSA-Würfelformel n W eyes + bonus.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAAIF.H"
// P3 17/26 gleich (suche.py 28.10.2026, Basis fz_145760_t1c_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra650: Teilungsvorschlag, vor Einbau mit Astra491/Claude abgleichen.
// P3 8/41 gleich (suche.py 26.10.2026, Basis fz_145760_t1_P1.CPP)
// HINWEIS: nur f_1461f4..f_146900 sind im Original unoptimiert (-od, ebp-Rahmen); f_145760..f_146170 (dice/aifload) sind optimiert (-4r -oneatx -zp1 -s)
// fz_145760_t1 (Schatten ueber Riva) - Pass 1 Einheit 145760-146920
#include <string.h>
#include <stdlib.h>
#pragma inline_depth(0)
int f_1664d0(const char *a, const char *b, int c);
int f_014540(int sz, const char *file, int line);
int f_099ef0(int, ...);
int f_145547(const char *a, const char *b, int n);
void f_145300(void *p, int v, int n);
void *f_147c84(void *p, int n, int d);
int f_147cd0(int p1);
int f_147ef0(int p1, int p2, char *p3, int p4);
int f_1680f5(int a, int b);
int f_1687c9(int a, int b);
short f_167f75(int a, void *b);
int f_146d86(int a, int b);
extern int d_1a97dc; extern int d_1c3914; extern int d_1a9824; extern short d_1c3918; extern int d_1c391c;
extern int d_1a9698; extern int d_1baac0; 
extern const char d_1b8970[]; extern const char d_1b8979[]; extern const char d_1b8982[]; extern const char d_1b898c[];
extern const char d_1a97e0[]; extern const char d_1a97f4[]; extern const char d_1a980c[]; extern const char d_1b8996[];
struct RivaFileStream;
struct X266 { char d[0x266]; };
struct RGB3 { unsigned char r,g,b; RGB3(); };
int f_145c20(RivaAifImage *p); int f_145c80(RivaAifImage *p); int f_145d60(RivaAifImage *p, int p3); int f_145e30(RivaAifImage *p, char *dst);
void f_145ee0(RivaAifImage *p, char *dst); void f_146030(RivaAifImage *p, char *dst); void f_146170(RivaAifImage *p, char *dst);
short f_145a60(RivaAifImage *p, int name, int p3, char *buf, char fl);
char f_145df0(RivaAifImage *p);
#define ABS(x) abs(x)
#define ROLL(r,e) { short _e = (e); int _t; if (_e <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f); _t = (int)_lrotl(_lrotl(d_1a97dc ^ d_1c3914, 2) + d_1c3914 ^ d_1a97dc, 3); d_1a97dc = ABS(_t) + 1; r = ABS(_t) % _e + 1; }
//@ f_145920
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet ohne Zufallswurf den theoretischen Minimalwert und Maximalwert einer
 *   Würfelformel n W eyes + bonus (z. B. zur Anzeige von Schadensspannen im Inventar oder zur KI-Abschätzung im
 *   Kampf) und schreibt beide Grenzwerte in die übergebenen Ausgabeparameter lo und hi. Negative Ergebnisse
 *   werden jeweils auf 0 angehoben.
 * - Eingaben:
 *   - n: Anzahl der Würfel (als short ausgewertet; bei negativem n werden Minimum und Maximum entsprechend
 *     vertauscht abgezogen).
 *   - eyes: Augenzahl je Würfel.
 *   - bonus: Fester Offset der Würfelformel.
 *   - lo: Zeiger auf ein short, in das das minimale Ergebnis geschrieben wird.
 *   - hi: Zeiger auf ein short, in das das maximale Ergebnis geschrieben wird.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - minv: Berechnetes Minimum (bonus + n bei positivem n, mindestens 0).
 *   - maxv: Berechnetes Maximum (bonus + n * eyes bei positivem n, mindestens 0).
 === Ende Beschreibung === */
void f_145920(short n, short eyes, short bonus, short *lo, short *hi)
{
 if (eyes <= 0) f_1664d0(d_1b8982, d_1a97e0, 0x63);
 *lo = bonus + n; *hi = bonus + n * eyes;
}
