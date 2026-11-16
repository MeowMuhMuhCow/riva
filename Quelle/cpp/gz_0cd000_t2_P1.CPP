/* === Beschreibung (Katalog) ===
 * Einheit gz_0cd000_t2
 *
 * Diese kleine Einheit enthält zwei Bit-/Vergleichs-Hilfsfunktionen am Übergang zwischen der dritten
 * Zwergenminen-Ebene und mirror.cpp sowie die Dialogausgabefunktion f_0cd690 für die gestuften Warnmeldungen
 * beim Betrachten des magischen Spiegels (0x25).
 === Ende Beschreibung === */
// P3 4/11 gleich (suche.py 26.10.2026, Basis gz_0cd000_P1.CPP)
// gz_0cd000.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CD000-0x0CD730
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"






#define EQI(x,v) (((x)==(v))?1:0)
struct SO { char a[4]; int *p; char b[8]; int *q; char c[40]; };
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039780(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_0bf730(const char *p1, int p2);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
extern unsigned short d_1bf358;
extern unsigned short d_1bf35c;
extern char *d_1bf360;
#define SA(i) (d_1bf360[(i)])
#define SB(i) ((i)[d_1bf360])
extern int d_1c0004;
extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
inline void i3e0(char c) { short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf358 = d_1bf358 | (1 << i); } } }
inline void i430(char c) { short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf35c = d_1bf35c | (1 << i); } } }
inline int i470(char c) { int r = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i) && ((unsigned short)(1 << i) & d_1bf358) != 0) { r = 1; break; } } return r; }
inline int i4d0(char c) { int r = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i) && ((unsigned short)(1 << i) & d_1bf35c) != 0) { r = 1; break; } } return r; }
inline int i530(char c) { short n = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i)) { n = n + 1; } } return 1 < n; }
inline int i580(int p1, char c) { int r = 0; short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf358 = d_1bf358 | (1 << i); } } short s = f_044c90(p1, 0x27, 7); if (0 < s) { for (i = 0; SB(i) != 0; i++) { if (c == SB(i)) { d_1bf35c = d_1bf35c | (1 << i); } } r = 1; } return r; }
//@ f_0cd660
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion verknüpft das über p adressierte Byte per bitweisem UND mit der Maske v (*p &= v)
 *   und speichert das Ergebnis zurück.
 * - Eingaben: Übergeben werden der Zeiger p auf das Zielbyte sowie die Bitmaske v.
 * - Rückgabewert: Zurückgegeben wird der neue Wert von *p.
 === Ende Beschreibung === */
unsigned char f_0cd660(unsigned char *p, unsigned char v) { return *p &= v; }
//@ f_0cd670
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion vergleicht das über p1 adressierte vorzeichenbehaftete Byte mit dem
 *   Vergleichswert p2 auf Ungleichheit (*p1 != p2).
 * - Eingaben: Übergeben werden der Zeiger p1 auf das Statusbyte sowie der Vergleichswert p2.
 * - Rückgabewert: Zurückgegeben wird 1 bei Ungleichheit, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd670(signed char *p1, signed char p2)
{
    int v = *p1;
    return v != p2;
}
//@ f_0cd690
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt für den Gruppenanführer in Abhängigkeit vom Zählerstand p2 (2, 3 oder 4) die
 *   gestuften Warn- und Ereignistexte 0x250000fa bis 0x250000fd (aus dem Textbereich 0x25) aus und meldet beim
 *   Erreichen der vierten Stufe (p2 == 4) die Auslösung zurück.
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie der Zählerstand p2.
 * - Rückgabewert: Zurückgegeben wird 1, wenn p2 == 4 erreicht wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd690(int p1, int p2)
{
  SO o;
  int t, r;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  t = f_038c40(d_1c0004);
  r = 0;
  o.p[1] = t;
  switch ((unsigned short)p2) {
    case 2: f_0bf730(d_1c2c64, 0x250000fa); break;
    case 3: f_0bf730(d_1c2c64, 0x250000fb); break;
    case 4:
      f_0bf730(d_1c2c64, 0x250000fc);
      r = 1;
      f_0bf730(d_1c2c64, 0x250000fd);
      break;
  }
  f_1254a0(&o, 0);
  return r;
}
