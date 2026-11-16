/* === Beschreibung (Katalog) ===
 * Einheit tdmwater (0x123330 - 0x123730)
 *
 * Überblick
 * Diese Einheit implementiert die Sinus-Wellentabellen für den Unterwasser- bzw.
 * Wasseroberflächen-Verzerrungseffekt der 3D-Engine (tdmwater.cpp).
 === Ende Beschreibung === */
// P1 2/2 gleich
// tdmwater.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x123330-0x123730
#include <string.h>
#include <math.h>
#include "RIVAMEM.H"



extern int d_1a0108;
extern int d_1a8af0;
extern int d_1a8af4;
extern int d_1a8af8;
extern int d_1a8afc;
extern float d_1a8ae8;
extern float d_1a8aec;
extern int *d_1c0c14;
extern int *d_1c0c18;
extern int d_1c0c1c;
extern int d_1c0c20;
extern char *d_1c0c24;
extern int *d_1c0c28;
extern int *d_1c0c2c;
extern const char d_1a8ac8[];
struct K { float f2; double d2; double pi; };
extern const K d_1b84f0;   // CONST des Originalmoduls: 2.0f, 2.0, 3.141592653589
//@ f_123330
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet bei geänderter Viewport-Breite p1, Höhe p2 oder Zeilenbreite p3 die horizontalen und
 *   vertikalen Sinus-Verzerrungs- und Skalierungstabellen (d_1c0c14 bis d_1c0c2c) für den 3D-Wassereffekt neu.
 * - Eingaben: Die Funktion erhält im Parameter p1 die Bildbreite, in p2 die Bildhöhe und in p3 das Zeilen-Offset
 *   (Stride).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_123330(int p1, int p2, int p3)
{
  int r1, r2, i, t;
  if (p1 != d_1a8af4 || p2 != d_1a8af8 || p3 != d_1a8afc) {
    float a = d_1b84f0.f2 * p1 / d_1a8ae8;
    float b = d_1b84f0.f2 * p2 / d_1a8aec;
    d_1c0c1c = (int)a;
    d_1c0c20 = (int)b;
  if (d_1c0c14 != 0) { operator delete(d_1c0c14); d_1c0c14 = 0; }
  if (d_1c0c18 != 0) { operator delete(d_1c0c18); d_1c0c18 = 0; }
  if (d_1c0c24 != 0) { operator delete(d_1c0c24); d_1c0c24 = 0; }
  if (d_1c0c28 != 0) { operator delete(d_1c0c28); d_1c0c28 = 0; }
  if (d_1c0c2c != 0) { operator delete(d_1c0c2c); d_1c0c2c = 0; }
    d_1c0c14 = new (mark(d_1a8ac8, 0x7f)) int[d_1c0c1c];
    d_1c0c18 = new (mark(d_1a8ac8, 0x80)) int[d_1c0c20];
    d_1c0c24 = new (mark(d_1a8ac8, 0x81)) char[p1 * p2];
    d_1c0c28 = new (mark(d_1a8ac8, 0x82)) int[p1];
    d_1c0c2c = new (mark(d_1a8ac8, 0x83)) int[p2];
    for (i = 0; i < d_1c0c1c; i++) {
      d_1c0c14[i] = (int)(d_1a0108 + sin(i / (double)d_1c0c1c * d_1a8ae8 * d_1b84f0.d2 * d_1b84f0.pi) * d_1a0108);
      d_1c0c14[i] *= p3;
    }
    for (i = 0; i < d_1c0c20; i++) {
      d_1c0c18[i] = (int)(d_1a8af0 + sin(i / (double)d_1c0c20 * d_1a8aec * d_1b84f0.d2 * d_1b84f0.pi) * d_1a8af0);
    }
    r1 = p2 - 1 - 2 * d_1a0108;
    for (i = 0; i < p2; i++) d_1c0c2c[i] = (i * r1) / p2 * p3;
    r2 = p1 - 1 - 2 * d_1a8af0;
    for (i = 0; i < p1; i++) d_1c0c28[i] = (i * r2) / p1;
    d_1a8af4 = p1;
    d_1a8af8 = p2;
    d_1a8afc = p3;
  }
}
//@ f_123690
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt sämtliche für den 3D-Wassereffekt allokierten Sinus- und Indextabellen (d_1c0c14 bis d_1c0c2c)
 *   frei und setzt die gespeicherten Abmessungen auf -1 zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_123690(void)
{
  if (d_1c0c14 != 0) { operator delete(d_1c0c14); d_1c0c14 = 0; }
  if (d_1c0c18 != 0) { operator delete(d_1c0c18); d_1c0c18 = 0; }
  if (d_1c0c24 != 0) { operator delete(d_1c0c24); d_1c0c24 = 0; }
  if (d_1c0c28 != 0) { operator delete(d_1c0c28); d_1c0c28 = 0; }
  if (d_1c0c2c != 0) { operator delete(d_1c0c2c); d_1c0c2c = 0; }
  d_1a8af4 = d_1a8af8 = d_1a8afc = -1;
}
