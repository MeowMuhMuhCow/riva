/* === Beschreibung (Katalog) ===
 * Einheit menuovl (Adresse 0x0bfd80 - 0x0bff80)
 *
 * Diese Einheit stammt aus der Originaldatei p:\riva\source\cpp\menuovl.cpp und ergänzt das Menü-System um die
 * Erstausgabe der Antwortoptionen (samt Speicherung ihrer vertikalen Bildschirmpositionen für die Mausauswahl)
 * sowie den Basiskonstruktor des Menü-Overlays.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 2/3 gleich (suche.py 30.10.2026, Basis menuovl_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 1 gleich (vorher 1), Rest 70 (vorher 72)
// menuovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BFD80-0x0BFF80
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0be200(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0e4830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a55e0[];           // Text 0x1A55E0
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_0bfd80  groesse 288 B, 92 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert für ein Auswahlmenü mit p->s74 Antwortoptionen das Positions-Array p->a76,
 *   gibt jede Option der Reihe nach in der passenden Textfarbe (0xf9 für bereits gewählte/markierte Zeilen i ==
 *   p->s10, sonst 0xe0) über f_0be200 aus und speichert die jeweils erreichte relative Y-Koordinate in
 *   p->a76[i], damit die Mausabfrage in f_0be4f0 erkennt, über welcher Zeile sich der Mauszeiger befindet.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
//@ f_0bfea0  groesse 96 B, 28 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Wrapper zeigt ein Meldungsfenster über f_0e4830 mit explizitem Modusparameter p2 und dem Text
 *   p3 an, während der Mauszeiger vorübergehend ausgeblendet und der Zustand über f_0ce7c0/f_0ce7e0 gesichert
 *   wird.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p1, den 16-Bit-Anzeigemodus p2 sowie den Textzeiger bzw. die
 *   Textkennung p3 entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0e4830 zurück.
 === Ende Beschreibung === */
//@ f_0bff00  groesse 128 B, 28 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Basiskonstruktor initialisiert ein Menü-Overlay-Objekt (vp48 = &d_1bb330), lädt die
 *   Menü-Rahmengrafik (0x140001 aus dem Archiv d_1c2098) in den neu reservierten Puffer p->i0, legt einen 64.000
 *   Byte großen Hintergrund-Sicherungspuffer p->i8 an und setzt die Statusfelder (s24 = 0, s10 = -1) auf ihre
 *   Ausgangswerte.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf das zu initialisierende Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger t zurück.
 === Ende Beschreibung === */

struct M { int i0; int i4; char *i8; short s0c, s0e; short s10, s12, s14, s16, s18, s1a, s1c, s1e, s20, s22, s24, s26, s28, s2a; char pad2c[28]; int vp48; short s4c, s4e, s50, s52; char pad54[4]; short s58, s5a, s5c; char pad5e[10]; int i68; int i6c; int i70; short s74; char *a76; int i7a; short s7e, s80; char pad82[6]; short s88; signed char c8a; int i8b; char pad8f[13]; int *i9c; short sa0; short tab[10]; };
#define I(x) ((int)(x))
#define G ((int)d_1c38b0)
extern short d_1bd90c;
extern int d_1bf244;
extern signed char d_1bfaec;

extern char d_1c38b0[];


inline int EQ(int a, int b) { return a == b; }
inline char EQC(int a, int b) { return a == b; }
#define EQI(x,v) (((x)==(v))?1:0)

extern char d_1bb330[];
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0bfd80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert für ein Auswahlmenü mit p->s74 Antwortoptionen das Positions-Array p->a76,
 *   gibt jede Option der Reihe nach in der passenden Textfarbe (0xf9 für bereits gewählte/markierte Zeilen i ==
 *   p->s10, sonst 0xe0) über f_0be200 aus und speichert die jeweils erreichte relative Y-Koordinate in
 *   p->a76[i], damit die Mausabfrage in f_0be4f0 erkennt, über welcher Zeile sich der Mauszeiger befindet.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfd80(M *p)
{
  p = (M *)(((int)p & 0) ? 0 : (int)p); // haelt die Registerzuteilung wie im Original
  // haelt die Registerzuteilung wie im Original
  short draw16_904(int, int, short, short);
#pragma aux draw16_904 "f_0be200";
  short x, y, z;

  short i;
  int *q;
  int arg;
  char *dst;
  short n;
  signed char v;
  p->a76 = 0;
  dst = (char *)(((int)dst & 0) ? 0 : (int)dst); // haelt die Registerzuteilung wie im Original
  do {
  if (p->s74) {
    p->a76 = new (mark(d_1a55e0, 0x1b3)) char[p->s74 + 1];
    x = p->s14 + 0x1c;
    i = 0;
    q = p->i9c;
    z = ((p->s28 + 2) << 3) + p->s16 - 1;
    y = z;
    for (i = 0; i < p->s74; i++) {
        int check = EQB(d_1bfaec, 0);
        if (check && i == p->s10) {
          f_05e320(G, 0xf9, -1);
        } else {
          f_05e320(G, 0xe0, -1);
        }
        signed char flag1329 = d_1bfaec;
        d_1bfaec = flag1329; // haelt die Registerzuteilung wie im Original
        arg = *q;

        q++;
        n = draw16_904(I(p), arg, (short)x, z);
        v = (char)(short)(z & 0xffff);
        dst = p->a76 + (short)(i & 0xffff);
        *dst = v - (char)y;
        z += n << 3;
    }
    p->a76[i] = 0xc7 - (char)y;
  }
  } while (0);
}
//@ f_0bfea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Wrapper zeigt ein Meldungsfenster über f_0e4830 mit explizitem Modusparameter p2 und dem Text
 *   p3 an, während der Mauszeiger vorübergehend ausgeblendet und der Zustand über f_0ce7c0/f_0ce7e0 gesichert
 *   wird.
 * - Eingaben: Die Funktion nimmt den Menü-Manager p1, den 16-Bit-Anzeigemodus p2 sowie den Textzeiger bzw. die
 *   Textkennung p3 entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0e4830 zurück.
 === Ende Beschreibung === */
int f_0bfea0(int p1, short p2, int p3)
{
  int loc;
  int r;
  d_1bf244 = 1;
  f_0ce7c0(I(&loc));
  if (d_1bd90c) f_0d26e0();
  r = f_0e4830(p1, p2, p3);
  if (d_1bd90c) f_0d2710();
  d_1bf244 = 0;
  f_0ce7e0(I(&loc), 0);
  return r;
}
//@ f_0bff00
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Basiskonstruktor initialisiert ein Menü-Overlay-Objekt (vp48 = &d_1bb330), lädt die
 *   Menü-Rahmengrafik (0x140001 aus dem Archiv d_1c2098) in den neu reservierten Puffer p->i0, legt einen 64.000
 *   Byte großen Hintergrund-Sicherungspuffer p->i8 an und setzt die Statusfelder (s24 = 0, s10 = -1) auf ihre
 *   Ausgangswerte.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf das zu initialisierende Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger t zurück.
 === Ende Beschreibung === */
int f_0bff00(int t)
{
  M *p = (M *)t;
  p->vp48 = (int)&d_1bb330;
  p->i0 = f_014540(((int)(((RivaFileManager*)(I(((char*)&d_1c2098))))->f_144a30( 0x140001))), I(d_1a55e0), 500);
  ((RivaFileManager*)(I(((char*)&d_1c2098))))->f_1448d0( 0x140001,(void *)( p->i0));
  p->i8 = (char *)f_014540(64000, I(d_1a55e0), 0x1f7);
  p->s24 = 0;
  p->s10 = -1;
  p->s1c = p->s22 = p->s24;
  return t;
}
