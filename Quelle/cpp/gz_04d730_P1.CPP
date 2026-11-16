/* === Beschreibung (Katalog) ===
 * Einheit gz_04d730 (0x04d730 - 0x04dbf0)
 *
 * Überblick
 * Die Einheit gz_04d730 enthält die beiden Pergamentrollen-Animationen auf dem Charakterblatt (CMask), mit denen
 * die Körper-Ausrüstungsansicht an der Position (85, 34) in 12 bzw. 13 Animationsschritten von unten nach oben
 * aufgerollt (f_04d730) beziehungsweise von oben nach unten abgerollt (f_04d9b0) wird.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 0/2 gleich (suche.py 24.10.2026, Basis gz_04d730_P1.CPP)
// gz_04d730.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04D730-0x04DBF0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_04b0d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_04b3a0(int p1);                                   // reg eax stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0

           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1c2be0;                    // 0x1C2BE0
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


struct S {
 char a0[7]; char f07[4]; int f0b; char p1[0x1d-0x0f]; unsigned short f1d; char p2[1]; short f20; short f22;
 char p3[0xea-0x24]; int fea; char p4[0xf2-0xee]; int ff2; int ff6; int ffa; int ffe;
 char p5[0x112-0x102]; int f112; char p6[0x11e-0x116]; int f11e;
};
#define B1C38B0 ((int)&d_1c38b0)

struct Obj { int x[3]; };

//@ f_04d730  groesse 640 B, 165 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt die 12-stufige Einroll-Animation (s = 12 abwärts bis 1, Höhe t = s * 13 Pixel) ab, mit
 *   der die Körper-Ausrüstungsansicht (p->ff6, 98x164 Pixel bei X = 85, Y = 34) nach oben zusammengerollt wird,
 *   um den Blick auf die darunterliegende Rucksack-/Charakterblattansicht freizugeben; gleichzeitig wird die
 *   animierte Rollenkante (p->ffa, Bilder 7 bis 18 aus Archiv 0x3000b) bei (67, 20) gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Teilbilder p->ff6 (Körperansicht), p->ffa (Rollenleiste) und p->ffe sowie den
 *   Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void f_04d730(S *p)
{
 Obj b; Obj c; Obj a; int l20; short s; short t;
 ((int)(((RivaRasterImage*)((int)&b))->f_0fac10( 0x62, 0xa4,(void *)( p->f11e))));
 ((int)(((RivaRasterImage*)((int)&a))->f_0fac80( 0x62, 0xa4)));
 ((RivaRasterImage*)((int)&a))->f_0fafb0((void *)( p->f11e), 0x55, 0x22);
 ((RivaRasterImage*)(p->ff6))->f_0fade0((void *)( p->f11e), 0x55, 0x22);
 ((RivaRasterImage*)(p->fea))->f_0fade0((void *)( d_1a34e0), 0, 0);
 if (!p->f1d && p->f20 >= 0xf) {
  f_04b0d0((int)p, d_1a34e0, p->f20, 0xfd);
 }
 l20 = ((int)(((RivaRasterImage*)(p->ff6))->f_0fb0b0()));
 for (s = 0xc; s >= 1; s--) {
  t = s * 0xd;
  if (t > (short)0xa4) t = 0xa4;
  ((int)(((RivaRasterImage*)((int)&c))->f_0fac10( 0x62, t,(void *)( (0xa4 - t) * 0x62 + l20))));
  ((RivaRasterImage*)((int)&b))->f_0fb4d0((RivaRasterImage *)( (int)&a), 0, 0);
  ((RivaRasterImage*)((int)&b))->f_0fb3a0((RivaRasterImage *)( (int)&c), 0, 0, 1);
  f_04feb0((int)&d_1c2be0, 0x3000b, ((int)(((RivaRasterImage*)(p->ffa))->f_0fb0b0())), 0, (short)(0x13 - s), 0, (int)p + 7, (int)p + 7, 0x140);
  ((RivaRasterImage*)(p->ffe))->f_0fade0((void *)( d_1a34e0), 0x43, 0x14);
  ((RivaRasterImage*)(p->ffa))->f_0fae30((void *)( d_1a34e0), 0x43, 0x14, 1);
  ((RivaRasterImage*)((int)&b))->f_0fade0((void *)( d_1a34e0), 0x55, 0x22);
  ((int)(((RivaRasterImage*)((int)&c))->f_0fad20( 0)));
 }
 ((RivaRasterImage*)((int)&a))->f_0fade0((void *)( d_1a34e0), 0x55, 0x22);
 if (p->f22 == -1 && p->f20 < 0xf) {
  f_04b3a0((int)p);
 } else if (p->f22 >= 0 && p->f22 < 0xf) {
  p->f22 = 0xf;
 }
 f_04feb0((int)&d_1c2be0, 0x3000b, ((int)(((RivaRasterImage*)(p->ffa))->f_0fb0b0())), 0, 0x12, 0, (int)p + 7, (int)p + 7, 0x140);
 ((RivaRasterImage*)(p->ffe))->f_0fade0((void *)( d_1a34e0), 0x43, 0x14);
 ((RivaRasterImage*)(p->ffa))->f_0fae30((void *)( d_1a34e0), 0x43, 0x14, 1);
 ((int)(((RivaRasterImage*)((int)&a))->f_0fad20( 0)));
 ((int)(((RivaRasterImage*)((int)&b))->f_0fad20( 0)));
}

//@ f_04d9b0  groesse 576 B, 143 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt die 13-stufige Ausroll-Animation (s = 1 aufwärts bis 13, Höhe t = s * 13 Pixel) ab, mit
 *   der die Körper-Ausrüstungsansicht (p->ff6, 98x164 Pixel bei X = 85, Y = 34) von oben nach unten über den
 *   Hintergrund gerollt wird, und setzt abschließend die untere Rollenkante (Bild 6 aus Archiv 0x3000b) an
 *   Position (67, 20).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt p->ff6, p->ffa, p->ffe, p->f11e und den Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void f_04d9b0(S *p)
{
 Obj c; Obj b; Obj a; int l20; short s; short t;
 ((int)(((RivaRasterImage*)((int)&b))->f_0fac10( 0x62, 0xa4,(void *)( p->f11e))));
 ((int)(((RivaRasterImage*)((int)&a))->f_0fac10( 0x62, 0xa4,(void *)( p->f11e + 0x3ec8))));
 if (p->f1d == (unsigned short)0 && p->f20 >= (unsigned short)0xf)
  f_04b0d0((int)p, d_1a34e0, p->f20, 0xfd);
 ((RivaRasterImage*)((int)&a))->f_0fafb0((void *)( d_1a34e0), 0x55, 0x22);
 l20 = ((int)(((RivaRasterImage*)(p->ff6))->f_0fb0b0()));
 for (s = 1; s <= 0xd; s++) {
  t = s * 0xd;
  if (t > (short)0xa4) t = 0xa4;
  ((int)(((RivaRasterImage*)((int)&c))->f_0fac10( 0x62, t,(void *)( (0xa4 - t) * 0x62 + l20))));
  ((RivaRasterImage*)((int)&b))->f_0fb4d0((RivaRasterImage *)( (int)&a), 0, 0);
  ((RivaRasterImage*)((int)&b))->f_0fb3a0((RivaRasterImage *)( (int)&c), 0, 0, 1);
  f_04feb0((int)&d_1c2be0, 0x3000b, ((int)(((RivaRasterImage*)(p->ffa))->f_0fb0b0())), 0, (short)(0x13 - s), 0, (int)p + 7, (int)p + 7, 0x140);
  ((RivaRasterImage*)(p->ffe))->f_0fade0((void *)( d_1a34e0), 0x43, 0x14);
  ((RivaRasterImage*)(p->ffa))->f_0fae30((void *)( d_1a34e0), 0x43, 0x14, 1);
  ((RivaRasterImage*)((int)&b))->f_0fade0((void *)( d_1a34e0), 0x55, 0x22);
  ((int)(((RivaRasterImage*)((int)&c))->f_0fad20( 0)));
 }
 f_04feb0((int)&d_1c2be0, 0x3000b, ((int)(((RivaRasterImage*)(p->ffa))->f_0fb0b0())), 0, 6, 0, (int)p + 7, (int)p + 7, 0x140);
 ((RivaRasterImage*)(p->ffe))->f_0fade0((void *)( d_1a34e0), 0x43, 0x14);
 ((RivaRasterImage*)(p->ffa))->f_0fae30((void *)( d_1a34e0), 0x43, 0x14, 1);
 ((RivaRasterImage*)(p->ff6))->f_0fae30((void *)( d_1a34e0), 0x55, 0x22, 1);
 ((int)(((RivaRasterImage*)((int)&a))->f_0fad20( 0)));
 ((int)(((RivaRasterImage*)((int)&b))->f_0fad20( 0)));
}
