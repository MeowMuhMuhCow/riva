/* === Beschreibung (Katalog) ===
 * Einheit tdmkey_t2 (0x121ec0 - 0x1227b0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von tdmkey.cpp / TDMLOOP.CPP und steuert das Umschalten der
 * 3D-Viewport-Größe, das Aktualisieren von Sichtweite und Lichtradius, das Rendern und Ausgeben eines einzelnen
 * 3D-Frames auf den Bildschirm sowie das Zeichnen des rotierenden 3D-Kompasses.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 13/14 gleich (suche.py 29.10.2026, Basis tdmkey_t2_P1.CPP)
// tdmkey.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x120C60-0x1227B0
#include <string.h>
#include <stdlib.h>
#pragma inline_depth(0)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0101e0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_019b40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_01a760();                                         // reg - stapel 0
int f_02de20(int p1, int p2);                           // reg eax edx stapel 0
int f_02fcb7(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_041000();                                         // reg - stapel 0
int f_041220();                                         // reg - stapel 0
int f_041530();                                         // reg - stapel 0
int f_041ae0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_059d50();                                         // reg - stapel 0
int f_05b860();                       // nicht in clobber.tsv
int f_060a80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_0a77f0();                                         // reg - stapel 0
int f_0b1340();                                         // reg - stapel 0
int f_0b13d0(int p1);                                   // reg eax stapel 0
int f_0bba10();                                         // reg - stapel 0
int f_0bc060(int p1);                                   // reg eax stapel 0
int f_0bcae0(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0cda50();                                         // reg - stapel 0
int f_0ce650();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d31c0();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d37e0();                                         // reg - stapel 0
int f_0d3800();                                         // reg - stapel 0
int f_0d3980();                                         // reg - stapel 0
int f_0d39b0();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d5780();                                         // reg - stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0daa90(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dab50(int p1, int p2);                           // reg eax edx stapel 0
int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dac90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_0dacc0(int p1);                                   // reg eax stapel 0
int f_0db3d0(int p1);                                   // reg eax stapel 0
int f_0dbf10(int p1);                                   // reg eax stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de4d0(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8c0(int p1);                                   // reg eax stapel 0
int f_0de8e0(int p1);                                   // reg eax stapel 0
int f_0de8f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de900(int p1);                                   // reg eax stapel 0
int f_0de910(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_0de960(int p1, int p2);                           // reg eax edx stapel 0
int f_0de980(int p1);                                   // reg eax stapel 0
int f_0de9c0(int p1);                                   // reg eax stapel 0
int f_0f2720();                       // nicht in clobber.tsv
                   // reg eax edx ebx stapel 0
   // reg eax edx ebx ecx stapel 4
                           // reg eax stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// reg eax edx ebx ecx stapel 16
int f_10cb70();                                         // reg - stapel 0
int f_11f6e0();                                         // reg - stapel 0
int f_11f790(int p1, int p2, int p3, int p4);           // reg ecx stapel 0 (SICHERT)
int f_11f920(int p1);                                   // reg eax stapel 0
int f_11faf0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_11fb50();                                         // reg - stapel 0
int f_11fc00();                                         // reg - stapel 0
int f_11fc90();                                         // reg - stapel 0
int f_11fee0(int p1);                                   // reg eax stapel 0
int f_120080(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_1200b0();                                         // reg - stapel 0
int f_1201a0();                                         // reg - stapel 0
int f_1202a0();                                         // reg - stapel 0
int f_120310();                                         // reg - stapel 0
int f_120570();                                         // reg - stapel 0
int f_1205c0(int p1);                                   // reg eax stapel 0
int f_120620(int p1);                                   // reg eax stapel 0
int f_122800(int p1, int p2);                           // reg eax edx stapel 0
int f_122b70(int p1);                                   // reg eax stapel 0
int f_122c30(int p1);                                   // reg eax stapel 0
int f_1232e0(int p1);                                   // reg eax stapel 0
int f_123690();                                         // reg - stapel 0
int f_149d20();                                         // reg - stapel 0
int f_163b08(int p1, int p2);                           // reg eax edx stapel 0
int f_164880(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a0100;                    // 0x1A0100
extern int d_1a0102;                    // 0x1A0102
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a539c;                    // 0x1A539C
extern int d_1a54c0;                    // 0x1A54C0
extern int d_1a7fbe;                    // 0x1A7FBE
extern int d_1a7fc0;                    // 0x1A7FC0
extern int d_1a8958;                    // 0x1A8958
extern int d_1a897c;                    // 0x1A897C
extern int d_1a8984;                    // 0x1A8984
extern int d_1a89b0;                    // 0x1A89B0
extern int d_1a89b4;                    // 0x1A89B4
extern short d_1a89b8;                  // 0x1A89B8
extern int d_1a89f4;                    // 0x1A89F4
extern int d_1a89fc;                    // 0x1A89FC
extern int d_1a9b38;                    // 0x1A9B38
extern int d_1a9b3c;                    // 0x1A9B3C
extern int d_1baac0;                    // 0x1BAAC0
extern unsigned d_1bd6c0;               // 0x1BD6C0
extern int d_1bd766;                    // 0x1BD766
extern int d_1be1dc;                    // 0x1BE1DC
extern int d_1bed5c;                    // 0x1BED5C
extern int d_1bed8c;                    // 0x1BED8C
extern int d_1bf230;                    // 0x1BF230
extern int d_1bf4f8;                    // 0x1BF4F8
extern int d_1bf4fa;                    // 0x1BF4FA
extern int d_1bf530;                    // 0x1BF530
extern int d_1bfa78;                    // 0x1BFA78
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c0314;                    // 0x1C0314
extern int d_1c0904;                    // 0x1C0904
extern int d_1c0ae4;                    // 0x1C0AE4
extern unsigned short d_1c0af0;                    // 0x1C0AF0
extern int d_1c0af4;                    // 0x1C0AF4
extern int d_1c0b18;                    // 0x1C0B18
extern int d_1c0b1c;                    // 0x1C0B1C
extern int d_1c0b28;                    // 0x1C0B28
extern int d_1c0b2c;                    // 0x1C0B2C
extern int d_1c0b34;                    // 0x1C0B34
extern int d_1c0b48;                    // 0x1C0B48
extern int d_1c0b4c;                    // 0x1C0B4C
extern int d_1c0b58;                    // 0x1C0B58
extern int d_1c0b64;                    // 0x1C0B64
extern int d_1c0b88;                    // 0x1C0B88
extern int d_1c0b8a;                    // 0x1C0B8A
extern int d_1c0b8c;                    // 0x1C0B8C
extern int d_1c0b90;                    // 0x1C0B90
extern int d_1c0b94;                    // 0x1C0B94
extern int d_1c0b99;                    // 0x1C0B99
extern int d_1c0ba0;                    // 0x1C0BA0
extern int d_1c0ba4;                    // 0x1C0BA4
extern int d_1c0ba8;                    // 0x1C0BA8
extern int d_1c0bac;                    // 0x1C0BAC
extern int d_1c0c06;                    // 0x1C0C06
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile int d_1c0c94;           // 0x1C0C94: haelt die Lade-/Speicherfolge bei d_1c0b84 = d_1c0c94; d_1c0c94 = 0 wie im Original
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c2a80;
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2ed8;                    // 0x1C2ED8
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c8;                    // 0x1C90C8
extern int d_1cdb78;                    // 0x1CDB78
extern const char d_1a895c[];           // Text 0x1A895C
extern const char d_1a8988[];           // Text 0x1A8988
// --- eigene Funktionen (27), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


extern void (*d_1a9910)(void);
extern int * d_1bf510;
#define PA(x) (&x)
extern signed char d_1bfb1c, d_1c0b9a, d_1c0b9b, d_1bfb18, d_1c0b9c, d_1bfb08, d_1c0b98, d_1a994c;
extern short d_1c0b84, d_1a7fbc, d_1a7fc2, d_1a9696, d_1c2198, d_1bf4f0, d_1bf4f2;
extern int d_1c0b9e;
extern unsigned short d_1a89aa;
int __cdecl f_149eb4(int p1, int p2, int p3);
int __cdecl f_099ef0(int p1, int p2, int p3);
void f_164748(float p1);
void f_164808(float p1);
int f_0a7610();
int f_122c50(int p1);
int f_147c84(int p1, int p2, int p3);
int f_14d17f(int p1);
#pragma aux f_14d17f modify [edx];
void f_121d70(void);
void f_1223c0(void);
void f_1225e0(void);
int f_122760(void);
short f_122770(void);
#define EQM(x,v) (((x)==(v))?1:0)
#define NEM(x,v) (((x)!=(v))?1:0)
#define EQX(x,v) ((x)==(v))

//@ f_121ec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Schaltet den 3D-Viewport der Engine auf die Fenstergröße (208 x 135 Pixel an Position 16, 2) um und
 *   gibt eventuell angelegte Wasserwellen-Tabellen (f_123690) frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121ec0(void)
{
  d_1a9910 = f_121d70;
  f_164880(0xd0, 0x87, 0x10, 2);
  d_1c0b9a = 0;
  f_123690();
  if (d_1bf510 == PA(d_1a54c0)) {
    d_1bf510 = PA(d_1a539c);
  }
}
//@ f_121f10
/* === Beschreibung (Katalog) ===
 * - Zweck: Wechselt vollständig in den 3D-Fenstermodus (208 x 135 Pixel), lädt das Hintergrundrahmenbild
 *   (0x2d000001 + Szenario-Index) und zeichnet die 3D-Schaltflächenleiste neu.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121f10(void)
{
  d_1a9910 = f_121d70;
  f_164880(0xd0, 0x87, 0x10, 2);
  d_1c0b9a = 0;
  f_123690();
  if (d_1bf510 == PA(d_1a54c0)) {
    d_1bf510 = PA(d_1a539c);
  }
  d_1bfb1c = 0;
  if (d_1c0af4 != 0) {
    d_1c2a80 = 0;
    f_0bc060((int)&d_1bf230);
    f_0bcae0((int)&d_1bf230, d_1a7fbc + 0x2d000001, 0xff, d_1a34e0);
    f_0daba0(d_1c0af4, d_1a34e0);
  }
  d_1c0c94 = d_1c0b84;
}
//@ f_121fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Schaltet den 3D-Viewport der Engine auf Vollbildgröße (320 x 200 Pixel an Position 0, 0) um und gibt
 *   die Wasserwellen-Tabellen frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121fd0(void)
{
  d_1a9910 = f_121d70;
  f_164880(0x140, 200, 0, 0);
  d_1c0b9a = 1;
  f_123690();
  (*(volatile int *)&d_1c2a80) = 0; // haelt den Null-Store ueber Register frei wie im Original
  if (d_1bf510 == PA(d_1a539c)) {
    d_1bf510 = PA(d_1a54c0);
  }
}
//@ f_122020
/* === Beschreibung (Katalog) ===
 * - Zweck: Wechselt vollständig in den 3D-Vollbildmodus (320 x 200 Pixel), setzt das Vollbild-Flag d_1bfb1c = 1
 *   und sichert den bisherigen Statusleisten-Zustand (d_1c0c94).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_122020(void)
{
  d_1a9910 = f_121d70;
  f_164880(0x140, 200, 0, 0);
  d_1c0b9a = 1;
  f_123690();
  (*(volatile int *)&d_1c2a80) = 0; // haelt den Null-Store und die Registerfolge wie im Original
  if (d_1bf510 == PA(d_1a539c)) {
    d_1bf510 = PA(d_1a54c0);
  }
  d_1bfb1c = 1;
  d_1c0b84 = d_1c0c94;
  d_1c0c94 = 0;
}
//@ f_122090
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob die Texturdetailstufe (d_1bfb18) in den Optionen geändert wurde, und markiert das aktuelle
 *   3D-Szenario in diesem Fall zum Neuladen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_122090(void)
{
  if (d_1bfb18 != d_1c0b9c) {
    d_1c0b9c = d_1bfb18;
    d_1a7fc2 = -2;
    d_1a9696 = -1;
  }
}
//@ f_1220c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktualisiert bei geänderter Sichtweiten-Stufe (d_1bfb08) die Nah- und Fernsichtgrenzen (f_164748,
 *   f_164808) der 3D-Engine anhand der aktuellen Szenariotabelle.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1220c0(void)
{
  signed char c = d_1bfb08;
  if (c != d_1c0b9b) {
    int q = f_120620(d_1a7fbc); int e = q + c * 4u;
    f_164748((float)*(short *)(e + 0x24));
    d_1a994c = *(char *)(q + 0xe);
    f_164808((float)*(short *)(e + 0x26));
    (*(volatile signed char *)&d_1c0b9b) = c; // verhindert Zusammenlegen von c mit d_1c0b9b wie im Original
  }
}
//@ f_122120
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet aus der Grundhelligkeit p1 des 3D-Szenarios und der aktuellen Beleuchtungsstärke der
 *   Heldengruppe (f_0de4d0, z. B. Fackel, Laterne oder *Flim Flam*) den effektiven Lichtradius (0 bis 0x3f) und
 *   übergibt ihn an die 3D-Engine (f_163b08).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Grundhelligkeitswert des Szenarios.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_122120(int p1)
{
  int p = 0;
  p = p1;
  int iv = 0;
  iv = f_0de4d0(d_1c0004);
  unsigned short u;
  *(short *)&d_1c0b9e = f_0de4d0(d_1c0004) + 10;
  if ((short)iv < 0) u = 0; else if ((short)iv == 0) u = (unsigned short)p / 2; else u = (iv - 3) * 4 + p;
  if (u >= 0x3f) {
    u = 0x3f;
  }
  f_163b08(0, u);
}
//@ f_122190
/* === Beschreibung (Katalog) ===
 * - Zweck: Baut die gesamte 3D-Bildschirmanzeige nach einem Moduswechsel, dem Schließen eines Menüs oder dem
 *   Verlassen der Automap neu auf, einschließlich Paletten-Überblendung, Rahmenbild, 3D-Viewport und
 *   Statusleiste.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void *paletteCtor492(void *);
#pragma aux paletteCtor492 "f_01e100" parm [eax] value [eax] modify exact []
struct Palette492 { unsigned char red,green,blue; __pragma("paletteCtor492") Palette492(); };
typedef char PaletteSize492[(sizeof(Palette492)==3)?1:-1];
void f_122190(void)
{
  int lifetime;
  int entry;
  int record;
  signed char current;
  int f_1232e0_x(int p1);
  int f_120620_x(int p1);
  void f_014710_x(void *p);
  #pragma aux f_1232e0_x "f_1232e0" parm [eax] modify exact [eax edx]
  #pragma aux f_120620_x "f_120620" parm [eax] value [eax] modify exact [eax edx]
  #pragma aux f_014710_x "f_014710" parm [eax] modify exact [eax edx]

  f_0ce7c0((int)&lifetime);
  Palette492 *colors = new (mark(d_1a8988, 0x418)) Palette492[256];
  f_149eb4((int)colors, 0, 256);
  if (d_1bfa78 == 1 && d_1c0ba0 == 0)
    f_09a140((int)colors, 25);
  f_09a0d0(d_1a34e0);

  if (NEM(d_1bfb1c, 1)) {
    f_121ec0();
    f_02de20((int)&d_1bfb1c, 0);
    if (d_1c0af4) {
      d_1c2a80 = 0;
      f_0bc060((int)&d_1bf230);
      int first = f_122760();
      short second = f_122770();
      f_0bcae0((int)&d_1bf230, d_1a7fbc + 0x2d000001, second, first);
      int image = f_01a760();
      f_0daba0(d_1c0af4, image);
    }
    d_1c0c94 = d_1c0b84;
  } else {
    f_121fd0();
    f_02de20((int)&d_1bfb1c, 1);
    d_1c0b84 = d_1c0c94;
    d_1c0c94 = 0;
  }

  f_11fc00();
  if (d_1bfb18 != d_1c0b9c) {
    d_1c0b9c = d_1bfb18;
    d_1a7fc2 = -2;
    d_1a9696 = -1;
  }

  current = d_1bfb08;
  if (current != d_1c0b9b) {
    record = f_120620_x(d_1a7fbc);
    entry = record + current * 4u;
    f_164748((float)*(short *)(entry + 0x24));
    d_1a994c = *(char *)(record + 0x0e);
    f_164808((float)*(short *)(entry + 0x26));
    *(volatile signed char *)&d_1c0b9b = current; // verhindert Zusammenlegen von current mit d_1c0b9b wie im Original
  }

  f_11fc00();
  if (d_1bfa78 == 1)
    f_09a120(f_122c50((int)&d_1c0bac), 25);
  else
    f_099ef0(f_122c50((int)&d_1c0bac), 0, 256);
  f_1223c0();
  f_122b70((int)&d_1c0bac);
  f_1232e0_x((int)&d_1c0bac);
  d_1bfa78 = 0;
  *(volatile short *)&d_1c2198 = 0; // erzwingt direkten Speicher-Nullstore wie im Original
  operator delete(colors);
  f_0ce7e0((int)&lifetime, 0);
}
//@ f_1223c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Rendert ein einzelnes Bild der 3D-Szenerie (f_0a7610), zeichnet bei eingeschaltetem Kompass
 *   (d_1a89b0) die Kompassgrafik darüber, kopiert das Bild unter Beachtung des Mauszeiger-Ausschnitts auf den
 *   Bildschirm und aktualisiert bei Bedarf die Farbpalette.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
#define MX (*(volatile short *)&d_1bf4f0) // erzwingt erneutes Laden von d_1bf4f0 wie im Original
#define MY (*(volatile short *)&d_1bf4f2) // erzwingt erneutes Laden von d_1bf4f2 wie im Original
void f_1223c0(void)
{
  short w;
  int d = 0, s = 0;
  short h;
  if (d_1c0b98 == 1) {
    f_0d2f90(5, 1);
    f_0a7610();
    f_11f6e0();
    d_1c0b98 = 0;
    f_0d2f90(0, 1);
  }
  f_0a7610();
  f_1225e0();
  s = 0;
  d = 0;
  if (d_1c0b94 == 1) {
    f_0101e0(d_1cdb78, 0, 0, 0x13f, 0xc7, 0x140);
  }
  if (d_1a89b0 == 1) {
    short x, y;
    if (NEM(d_1bfb1c, d_1a89b0)) {
      y = 2;
      x = 0x62;
    } else {
      x = 0x8a;
      y = 0;
    }
    ((RivaRasterImage*)((int)&d_1c0b64))->f_0fae30((void *)( d_1cdb78), x, y, 1);
  }
  signed char state = d_1bfb1c;
  d_1bfb1c = state; // typgleicher Byte-Roundtrip fuer getrennten Load/MOVSX wie im Original
  if (state == 0) {
    ((RivaRasterImage*)(*(int *)&d_1c0af0))->f_0fae30((void *)( d_1cdb78), 0x10, 2, 1);
  }
  if (NEM(d_1bfb1c, 1)) {
    short x1, y1;
    short mx, my;
    short x0, y0;
    short x2;
    short y2 = 0;
    ((RivaRasterImage*)((int)&d_1bf530))->f_0fb210((short *)( (int)&w),(short *)( (int)&h));
    mx = MX;
    my = MY;
    x2 = MX + w - 1;
    y2 = MY + h - 1;
    x0 = 0x10;
    y0 = 2;
    x1 = 0xdf;
    y1 = 0x88;
    if ((short)(mx & 0xffff) > (short)0x10 && x1 >= x2 && my > (short)2 && y1 >= y2) { // 16-Bit-Maske haelt den Vergleichsausdruck wie im Original
      s = 1;
    } else if ((my < y0 && (int)mx != 0 && mx <= x1) ||
               ((int)mx != 0 && mx <= x0 && my <= y1) ||
               (my <= y1 && y1 <= y2 && mx <= x1) ||
               (mx <= x1 && x1 <= x2 && my <= y1)) {
      d = 1;
    }
  } else {
    s = 1;
  }
  if (s == 1) {
    f_0d3980();
    f_0d31c0();
  }
  if (d == 1) {
    f_0d2710();
  }
  f_0a77f0();
  int finish = d_1c0c06;
  finish = (finish & 0) ? 0 : finish; // haelt das DWORD-Lesen von d_1c0c06 in einem Register wie im Original
  if (finish == 1) {
    f_122c30((int)&d_1c0bac);
  }
  if (s == 1) {
    f_0d39b0();
  }
  if (d == 1) {
    f_0d26e0();
  }
}
//@ f_1225e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktualisiert das Bild des 3D-Kompasses (d_1c0b64), indem beim ersten Aufruf die Kompass-Grafiken
 *   (0x40006) geladen werden und anschließend der zur aktuellen Blickrichtung der Gruppe (f_0de8c0) passende
 *   Ausschnitt des Kompassstreifens (d_1c0b58) in das Kompassgehäuse (d_1c0b4c) kopiert wird.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1225e0(void)
{
  int loc;
  if (d_1a89b0 == 1) {
    if (d_1a89b4 == 1) {
      f_04feb0((int)&d_1c2be0, 0x40006, ((int)(((RivaRasterImage*)((int)&d_1c0b4c))->f_0fb0b0())), 0, 0, 0, (int)&loc, (int)&loc, 0x140);
      f_04feb0((int)&d_1c2be0, 0x40006, ((int)(((RivaRasterImage*)((int)&d_1c0b58))->f_0fb0b0())), 0, 1, 0, (int)&loc, (int)&loc, 0x140);
      d_1a89b4 = 0;
    }
    unsigned short r = f_0de8c0(d_1c0004);
    int a = r / 0xb6;
    int q = a;
    if (a > 0x168) {
      q = 0x168;
    }
    short t = (abs(q - 0x168) * 4) / 15;
    if (t > 0x60) {
      t -= 0x60;
    }
    if (d_1a89aa != t) {
      ((RivaRasterImage*)((int)&d_1c0b64))->f_0fb090((void *)( ((int)(((RivaRasterImage*)((int)&d_1c0b4c))->f_0fb0b0()))));
      ((RivaRasterImage*)((int)&d_1c0b58))->f_0fb3e0((char *)( ((int)(((RivaRasterImage*)((int)&d_1c0b64))->f_0fb0b0())) + 0x62), 0x2c, t, 0, 0x18, 9, 1);
      d_1a89aa = t;
    }
  }
}
//@ f_122710
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeichnet das fertige Kompass-Sprite (d_1c0b64) an der für den Fenster- bzw. Vollbildmodus
 *   vorgesehenen Position (98, 2 oder 138, 0) in den 3D-Renderpuffer.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_122710(void)
{
  if (d_1a89b0 == 1) {
    short a, b;
    if (NEM(d_1bfb1c, 1)) {
      a = 2;
      b = 0x62;
    } else {
      b = 0x8a;
      a = 0;
    }
    ((RivaRasterImage*)((int)&d_1c0b64))->f_0fae30((void *)( d_1cdb78), b, a, 1);
  }
}
//@ f_122760
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert das globale Bildschirm-Zielobjekt (d_1a34e0) zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Wert von d_1a34e0 zurück.
 === Ende Beschreibung === */
int f_122760(void)
{
  return d_1a34e0;
}
//@ f_122770
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert den Standard-Transparenz- bzw. Farbmaskenwert 0xff zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt 0xff (255) zurück.
 === Ende Beschreibung === */
short f_122770(void)
{
  return 0xff;
}
//@ f_122780
/* === Beschreibung (Katalog) ===
 * - Zweck: Statische Initialisierungsfunktion, die das globale 3D-Paletten-Verwaltungsobjekt (d_1c0bac) über
 *   f_122800 konstruiert.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_122780(void)
{
  f_14d17f((int)&d_1a89f4);
  f_122800((int)&d_1c0bac, 1);
  d_1a89fc = 1;
}
