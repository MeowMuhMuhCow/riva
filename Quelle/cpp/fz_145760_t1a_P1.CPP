/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t1a (0x145760 - 0x145850)
 *
 * Überblick
 * Diese Einheit implementiert den Basis-Zufallsgenerator und einfachen Einzelwürfel des Spiels (dice.cpp). Alle
 * Talentproben, Kampfwürfe, Schadensberechnungen und zufälligen Ereignisse in *Schatten über Riva* bauen auf
 * diesem Pseudozufallsgenerator auf, der den aktuellen Systemtimer (d_1c3914) mit einem rotierenden
 * 16-Bit-Zustandswert (d_1a97dc) verknüpft.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAAIF.H"
// P3 0/2 gleich (suche.py 28.10.2026, Basis fz_145760_t1a_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra650: Teilungsvorschlag, vor Einbau mit Astra491/Claude abgleichen.
// P3 8/41 gleich (suche.py 26.10.2026, Basis fz_145760_t1_P1.CPP)
// HINWEIS: nur f_1461f4..f_146900 sind im Original unoptimiert (-od, ebp-Rahmen); f_145760..f_146170 (dice/aifload) sind optimiert (-4r -oneatx -zp1 -s)
// fz_145760_t1 (Schatten ueber Riva) - Pass 1 Einheit 145760-146920
#include <string.h>
#include <stdlib.h>
#pragma inline_depth(20)
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
int f_145c20(RivaAifImage *p); int f_145c80(RivaAifImage *p); int f_145d60(RivaAifImage *p, int p3); int f_145e30(RivaAifImage *p, char *dst);
void f_145ee0(RivaAifImage *p, char *dst); void f_146030(RivaAifImage *p, char *dst); void f_146170(RivaAifImage *p, char *dst);
int f_145a60(RivaAifImage *p, int name, int p3, char *buf, char fl);
char f_145df0(RivaAifImage *p);
#define ABS(x) abs(x)
#define ROLL(r,e) { short _e = (e); int _t; if (_e <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f); _t = (int)_lrotl(_lrotl(d_1a97dc ^ d_1c3914, 2) + d_1c3914 ^ d_1a97dc, 3); d_1a97dc = ABS(_t) + 1; r = ABS(_t) % _e + 1; }
//@ f_145760
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt eine ganzzahlige Zufallszahl im abgeschlossenen Intervall zwischen lo und hi
 *   (Reihenfolge der Grenzen beliebig). Dazu mischt die Funktion den 16-Bit-Zufallszustand d_1a97dc mit dem
 *   Systemtimer d_1c3914, rotiert das Wort um 3 Bits nach links, multipliziert mit 23 und addiert 17, bevor mit
 *   Modulo auf die Intervallbreite skaliert wird.
 * - Eingaben:
 *   - lo (übergeben als int, intern auf short gekürzt): Erste Intervallgrenze.
 *   - hi (übergeben als int, intern auf short gekürzt): Zweite Intervallgrenze.
 * - Rückgabewert: Zufällige ganze Zahl zwischen min(lo, hi) und max(lo, hi) einschließlich der Grenzen. Sind
 *   beide Grenzen gleich, wird dieser Wert sofort zurückgegeben.
 * - Wichtige Variablen:
 *   - d_1a97dc: Globaler 16-Bit-Zustandswert (Seed) des Zufallsgenerators.
 *   - d_1c3914: Laufender Systemtimer-Zähler, der in jeden Zufallswurf einfließt.
 *   - span: Breite des Zielintervalls (|lo - hi| + 1).
 === Ende Beschreibung === */
short f_145760(int lo,int hi)
{
#pragma intrinsic(_lrotl,abs)
#pragma inline_depth(20)
 struct Roll491 {static inline short value(short eyes){

#pragma intrinsic(_lrotl,abs)
 int t;
 short copy1,copy2;
 if (eyes <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f);
 d_1a97dc=abs((t=(int)_lrotl(t=((t=(int)_lrotl(t=(d_1a97dc) ^ (d_1c3914),2)) + (d_1c3914)) ^ (d_1a97dc),3),copy1=t,t))+1;
 copy2=t;
 t=abs(t)%eyes+1;
 return t;

 }};
 short base=0;
 base=lo-1;
 return Roll491::value(hi-lo+1)+base;
}
#pragma inline_depth(20)
//@ f_1457e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Simuliert den Wurf eines einzelnen Spielwürfels mit eyes Seiten (z. B. W6 oder W20 für
 *   DSA-Talent- und Kampfwürfe) und liefert ein Ergebnis zwischen 1 und eyes. Sie verwendet denselben Misch-,
 *   Rotations- und linearen Kongruenzschritt auf d_1a97dc und d_1c3914 wie f_145760.
 * - Eingaben:
 *   - eyes (übergeben als int, intern als short verwendet): Augenzahl des Würfels (z. B. 6 oder 20). Ist eyes <=
 *     0, gibt die Funktion 0 zurück.
 * - Rückgabewert: Gewürfelte Augenzahl im Bereich 1 bis eyes (oder 0 bei ungültiger Seitenzahl <= 0).
 * - Wichtige Variablen:
 *   - d_1a97dc: Globaler 16-Bit-Zufallszustand.
 *   - d_1c3914: Systemtimer-Wert zur Entropieerhöhung.
 *   - u: Neu berechneter 16-Bit-Zufallswert vor der Modulo-Reduktion mit eyes.
 === Ende Beschreibung === */
short f_1457e0(short eyes)
{
#pragma intrinsic(_lrotl,abs)
 int t;
 short copy1,copy2;
 if (eyes <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f);
 d_1a97dc=abs((t=(int)_lrotl(t=((t=(int)_lrotl(t=(d_1a97dc) ^ (d_1c3914),2)) + (d_1c3914)) ^ (d_1a97dc),3),copy1=t,t))+1;
 copy2=t;
 t=abs(t)%eyes+1;
 return t;
}
