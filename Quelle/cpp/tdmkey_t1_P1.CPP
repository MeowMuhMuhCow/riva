/* === Beschreibung (Katalog) ===
 * Einheit tdmkey_t1 (0x120c60 - 0x121ec0)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil der Tastatur-, Maus- und Hauptschleifen-Steuerung für die
 * 3D-Ansicht (tdmkey.cpp und TDMLOOP.CPP). Sie verarbeitet Bewegungstasten, das Umschalten zwischen Fenster- und
 * Vollbild-3D-Ansicht, das Zentrieren des vertikalen Blickwinkels, die Aktualisierung der 3D-Schaltflächenleiste
 * sowie den zentralen Frame-Durchlauf der 3D-Bewegungsschleife.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 9/13 gleich (suche.py 26.10.2026, Basis tdmkey_t1_P1.CPP)
// OPT -4r -oneatx -zp1 -s -j
// P1 2/13 gleich
// tdmkey.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x120C60-0x1227B0
#include <string.h>
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
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_059d50();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_0a7610(int p1, int p2, int p3);                   // reg ebx stapel 0 (SICHERT)
int f_0a77f0();                                         // reg - stapel 0
int f_0b13d0(int p1);                                   // reg eax stapel 0
int f_0bba10(int p_h = 0x0);                                         // reg - stapel 0
int f_0bc060(int p1);                                   // reg eax stapel 0
int f_0bcae0(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0cda50();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int, int);
int f_05b860(int, int);
void f_120e70(void);
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
int f_0dacc0(int p1);                                   // reg eax stapel 0
int f_0db3d0(int p1);                                   // reg eax stapel 0
int f_0dbf10(int p1);                                   // reg eax stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8c0(int p1);                                   // reg eax stapel 0
int f_0de8f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de910(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_0de960(int p1, int p2);                           // reg eax edx stapel 0
int f_0de980(int p1);                                   // reg eax stapel 0
int f_0de9c0(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
   // reg eax edx ebx ecx stapel 4
                           // reg eax stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// reg eax edx ebx ecx stapel 16
int f_10cb70();                                         // reg - stapel 0
int f_11f6e0();                                         // reg - stapel 0
int f_11f920(int p1);                                   // reg eax stapel 0
int f_11fc00();                                         // reg - stapel 0
int f_122800(int p1, int p2);                           // reg eax edx stapel 0
int f_122b70(int p1);                                   // reg eax stapel 0
int f_122c30(int p1);                                   // reg eax stapel 0
int f_1232e0(int p1);                                   // reg eax stapel 0
int f_123690();                                         // reg - stapel 0
int f_149d20();                                         // reg - stapel 0
int f_163b08(int p1, int p2);                           // reg eax edx stapel 0
int f_164880(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern volatile int d_1a0102;                // 0x1A0102 - haelt Schreibfolge in f_1216f0 wie im Original
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a539c;                    // 0x1A539C
extern int d_1a54c0;                    // 0x1A54C0
extern int d_1a8958;                    // 0x1A8958
extern int d_1a897c;                    // 0x1A897C
extern int d_1a8984;                    // 0x1A8984
extern int d_1a89aa;                    // 0x1A89AA
extern int d_1a89b0;                    // 0x1A89B0
extern int d_1a89b4;                    // 0x1A89B4
extern short d_1a89b8;                  // 0x1A89B8
extern int d_1a89f4;                    // 0x1A89F4
extern int d_1a89fc;                    // 0x1A89FC
extern int d_1a9b38;                    // 0x1A9B38
extern int d_1a9b3c;                    // 0x1A9B3C
extern int d_1baac0;                    // 0x1BAAC0
extern unsigned d_1bd6c0;               // 0x1BD6C0
extern short d_1bed5c;                  // 0x1BED5C
extern signed char d_1bed8c;            // 0x1BED8C
extern int d_1bf230;                    // 0x1BF230
extern int d_1bf4f0;                    // 0x1BF4F0
extern int d_1bf4f2;                    // 0x1BF4F2
extern int d_1bf4f8;                    // 0x1BF4F8
extern int d_1bf4fa;                    // 0x1BF4FA
extern volatile int d_1bf510;                // 0x1BF510 - haelt Lade-/Schreibfolge in f_121120/f_1216f0/f_121d80 wie im Original
extern int d_1bf530;                    // 0x1BF530
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern signed char d_1c0314;            // 0x1C0314
extern signed char d_1c0ae4;                    // 0x1C0AE4
extern int d_1c0af0;                    // 0x1C0AF0
extern int d_1c0af4;                    // 0x1C0AF4
extern int d_1c0b18;                    // 0x1C0B18
extern int d_1c0b1c;                    // 0x1C0B1C
extern volatile short d_1c0b28;         // 0x1C0B28 - erzwingt direktes inc WORD PTR in f_1216f0
extern volatile short d_1c0b34;         // 0x1C0B34 - erzwingt direktes inc WORD PTR in f_1216f0
extern int d_1c0b4c;                    // 0x1C0B4C
extern int d_1c0b58;                    // 0x1C0B58
extern int d_1c0b64;                    // 0x1C0B64
extern int d_1c0b8c;                    // 0x1C0B8C
extern int d_1c0b94;                    // 0x1C0B94
extern int d_1c0ba0;                    // 0x1C0BA0
extern int d_1c0ba4;                    // 0x1C0BA4
extern int d_1c0ba8;                    // 0x1C0BA8
extern int d_1c0bac;                    // 0x1C0BAC
extern int d_1c0c06;                    // 0x1C0C06
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile int d_1c0c94;                // 0x1C0C94 - haelt Lade-/Schreibfolge in f_121120/f_1216f0/f_121d80 wie im Original
extern int d_1c2198;                    // 0x1C2198
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c8;                    // 0x1C90C8
extern int d_1cdb78;                    // 0x1CDB78
extern const char d_1a895c[];           // Text 0x1A895C
extern const char d_1a8988[];           // Text 0x1A8988
// --- eigene Funktionen (27), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#include <bios.h>
#define A(x) ((int)&(x))
#define EQM(x,v) (((x)==(v))?1:0)
#define NEM(x,v) (((x)!=(v))?1:0)
extern volatile short d_1c0b2c; // verhindert Wegoptimieren des ersten Schreibzugriffs in f_1216f0
void f_121d70(void);
void f_121f10(void);
void f_122020(void);
void f_1223c0(void);
void f_122190(void);
extern signed char d_1bfb1c, d_1bfb18, d_1bfb08, d_1c0b9a, d_1c0b9b, d_1c0b9c, d_1c0b98, d_1c0904, d_1c0b99;
extern short d_1a0100, d_1a7fbc, d_1a7fbe, d_1a7fc2, d_1a9696, d_1c0b88, d_1c0b8a, d_1c0b84, d_1c21a4;
extern volatile short d_1c2ed8; // haelt Lese-/Schreibfolge in f_121050 und f_1216f0 wie im Original
extern unsigned short d_1a7fc0;
extern volatile unsigned short d_1c0b9e; // erzwingt Nachladen nach f_0de4d0-Aufruf in f_1216f0
extern short d_1bd766;
extern char d_1a994c;
extern float d_1bba48, d_1bba4c;
extern double d_1b84b8, d_1b84c0;
extern void (*d_1a9910)(void);
extern int d_1c0b90, d_1c0b48, d_1bfa78, d_1be1dc;
int f_147c84(int, int, int);
int __cdecl f_149eb4(int p1, int p2, int p3);
int f_11faf0(void);
int f_11fb50(void);
int f_120080(void);
int f_1200b0(void);
int f_1201a0(void);
int f_1202a0(void);
int f_120310(void);
int f_0ce650(void);
int f_0b1340(void);
int f_11fc90(void);
int f_11fee0(int);
int f_0d26e0(void);
int f_0f2720(int, int, int);
int f_060a80(int);
void f_164748(float);
void f_164808(float);
int f_0dac90(int, int);

int f_11f790(void);
int f_122c50(int);
int f_14d17f(int);
#pragma aux f_14d17f modify [ebx edx];
short f_0de820(int);
int f_0de4d0(int);
int f_0de8e0(int);
int f_0de900(int);
short f_120570(void);
int f_1205c0(int);
int f_120620(int);
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_120c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Verarbeitet spezielle Tastatur- und Mausklick-Befehle in der 3D-Ansicht, darunter das Auslösen einer
 *   Interaktion per Leertaste oder Klick ins 3D-Sichtfenster (0x3920), das Öffnen der Automap (0x320d, 0x4000)
 *   und das weiche Überblenden zwischen Fenster- und Vollbildmodus (0x2f16, Taste V).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120c60(void)
{
  char buffer0[4];
  char buffer1[4];
  int result;
  int text;
  signed char flag;

  if (f_0d3800()) {
    flag = d_1bfb1c;
    if (flag != 0 ||
        ((short&)d_1bf4f8 >= 0x10 && (volatile short&)d_1bf4f8 <= 0xe0 && // volatile verhindert Zusammenfassen zur Bereichspruefung sub/cmp jbe
         (short&)d_1bf4fa >= 2 && (volatile short&)d_1bf4fa <= 0x82)) {   // volatile verhindert Zusammenfassen zur Bereichspruefung sub/cmp jbe
      d_1bd766 = 0x3920;
      f_0d37e0();
    }
  }

  if (d_1bd766 == 0x635 || (unsigned short)d_1a0100 == 1 || (unsigned short)d_1bd766 == (unsigned short)0x625)
    f_120e70();

  if (*(unsigned short *)&d_1c0b48 == (unsigned short)0) {
    switch (d_1bd766) {
    case 0x320d:
    case 0x4000:
      f_11f920(1);
      break;

    case 0x3920:
      f_0de960(d_1c0004, 1);
      *(int *)&d_1c0ae4 = 1;
      break;

    case 0x2f16:
      d_1bfb1c = !d_1bfb1c;
      result = f_147c84((int)operator new[](0x300, mark(d_1a895c, 0xb2)), 0x100, A(d_1baac0));
      result = result ? result : 0;
      if (EQ(d_1bfb1c, 0)) {
        f_0ce7c0((int)buffer1);
        f_149eb4(result, 0, 0x100);
        f_09a140(result, 0x19);
        f_121f10();
        f_1223c0();
        text = f_122c50(A(d_1c0bac));
        f_09a120(text, 0x19);
      text = (int)buffer1;
      } else {
        f_0ce7c0((int)buffer0);
        f_149eb4(result, 0, 0x100);
        f_09a140(result, 0x19);
        f_122020();
        f_1223c0();
        text = f_122c50(A(d_1c0bac));
        f_09a120(text, 0x19);
      text = (int)buffer0;
      }
      f_0ce7e0(text, 0);
      f_11fc00();
      operator delete((void *)result);
      break;

    }
  }
}
//@ f_120e70
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den geneigten vertikalen Blickwinkel und die Seitenneigung der 3D-Kamera schrittweise (in
 *   Schritten von 0x38e) wieder in die horizontale Normalposition (0) zurück und zeichnet dabei Zwischenbilder.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120e70(void)
{
  int t;
  short b, a, s;
  short kk = 0x38e;
  a = f_0de8e0(d_1c0004);
  s = (a > 0) ? -0x38e : 0x38e;
  b = f_0de900(d_1c0004);
  if ((b > 0)) t = -kk; else t = kk;
  while (a != 0 || b != 0) {
    if (a != 0) {
      a = a + s;
      if (a < kk && a > -kk) a = 0;
    }
    if ((short)b != 0) {
      b = b + t;
      if (b < kk && b > -kk) b = 0;
    }
    f_0de910(d_1c0004, (unsigned short)b);
    f_0de8f0(d_1c0004, (unsigned short)a);
    f_0de930(d_1c0004, 1);
    f_1223c0();
  }
  f_0de930(d_1c0004, 1);
  d_1a0100 = 0;
}
//@ f_120f60
/* === Beschreibung (Katalog) ===
 * - Zweck: Initialisiert die drei Rasterbilder für die Kompass-Anzeige in der 3D-Ansicht (d_1c0b4c, d_1c0b58,
 *   d_1c0b64) und berechnet die Skalierungsfaktoren für das Kopf-Wippen beim Gehen (d_1c0ba4, d_1c0ba8).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120f60(void)
{
  f_14d17f(A(d_1a897c));
  ((int)(((RivaRasterImage*)(A(d_1c0b4c)))->f_0fac80( 0x2c, 0xd)));
  d_1a8984 = 1;
  ((int)(((RivaRasterImage*)(A(d_1c0b58)))->f_0fac80( 0x78, 9)));
  d_1a8984 = 2;
  ((int)(((RivaRasterImage*)(A(d_1c0b64)))->f_0fac80( 0x2c, 0xd)));
  d_1c0ba4 = (int)(1.0 / d_1bba48 * d_1b84b8);
  d_1a8984 = 3;
  d_1c0ba8 = (int)(d_1bba4c * d_1b84c0 * d_1b84b8);
}
//@ f_121050
/* === Beschreibung (Katalog) ===
 * - Zweck: Übersetzt gedrückte Richtungstasten bzw. Mauszonen-Codes (0x48, 0x50, 0x4b, 0x4d, 0x54-0x57) in die
 *   internen Bewegungsflags (d_1c0b88) und das passende Richtungspfeil-Mauszeigersymbol (d_1c2ed8).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Richtungs- bzw. Tastencode.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121050(short p1)
{
  short v;
  short s;
  v = d_1c0b88;
  if (p1 != (short)0) {
    switch (p1) {
    case 0x48: v = 1; s = 9; break;
    case 0x50: v = 2; s = 8; break;
    case 0x4b: v = 4; s = 6; break;
    case 0x4d: v = 8; s = 7; break;
    case 0x56: v = 6; s = 0xd; break;
    case 0x57: v = 10; s = 0xe; break;
    case 0x54: v = 5; s = 10; break;
    case 0x55: v = 9; s = 0xb; break;
    default: v = -1; s = 0; break;
    }
    if (s != d_1c2ed8) {
      d_1c0b8a = d_1c2ed8;
      d_1c2ed8 = s;
    }
  }
  d_1c0b88 = v;
}
//@ f_121120
/* === Beschreibung (Katalog) ===
 * - Zweck: Konfiguriert das 3D-Renderfenster je nach Einstellung (d_1bfb1c) auf den Fenstermodus (208 x 135
 *   Pixel mit Rahmenbild und Schaltflächenleiste) oder den Vollbildmodus (320 x 200 Pixel) und aktualisiert bei
 *   geänderten Grafikoptionen die Detail- und Sichtweiteneinstellungen der 3D-Engine.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121120(void)
{
  signed char c;
  int p;
  if (NEM(d_1bfb1c, 1)) {
    d_1a9910 = f_121d70;
    f_164880(0xd0, 0x87, 0x10, 2);
    d_1c0b9a = 0;
    f_123690();
    if (d_1bf510 == A(d_1a54c0)) d_1bf510 = A(d_1a539c);
    d_1bfb1c = 0;
    if (d_1c0af4 != 0) {
      d_1c2a80 = 0;
      f_0bc060(A(d_1bf230));
      f_0bcae0(A(d_1bf230), d_1a7fbc + 0x2d000001, 0xff, d_1a34e0);
      f_0daba0(d_1c0af4, d_1a34e0);
    }
    d_1c0c94 = d_1c0b84;
  } else {
    d_1a9910 = f_121d70;
    f_164880(0x140, 200, 0, 0);
    d_1c0b9a = 1;
    f_123690();
    d_1c2a80 = 0;
    if (d_1bf510 == A(d_1a539c)) d_1bf510 = A(d_1a54c0);
    d_1bfb1c = 1;
    d_1c0b84 = (short)d_1c0c94;
    d_1c0c94 = 0;
  }
  f_11fc00();
  if (d_1bfb18 != d_1c0b9c) {
    d_1c0b9c = d_1bfb18;
    d_1a7fc2 = -2;
    d_1a9696 = -1;
  }
  c = d_1bfb08;
  if (c != d_1c0b9b) {
    p = f_120620(d_1a7fbc);
    f_164748((float)*(short *)(p + c * 4 + 0x24));
    d_1a994c = *(char *)(p + 0xe);
    f_164808((float)*(short *)(p + c * 4 + 0x26));
    d_1c0b9b = c;
  }
  f_11fc00();
}
//@ f_1212d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zählt, wie viele der bis zu sechs Heldengruppen-Slots aktuell aktiv und nicht getrennt bzw. gesperrt
 *   sind.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verfügbaren Teilgruppen zurück.
 === Ende Beschreibung === */
int f_1212d0(void)
{
  int n = 0;
  short k;
  int p;
  for (k = 0; k < 6; k++) {
    p = (int)&d_1bfdbc + k * 0x61;
    if (f_0de7c0(p) != 0) {
      if (f_0de980(p) == 0) {
        if (f_0de9c0(p) == 0) n++;
      }
    }
  }
  return n;
}
//@ f_121320
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktualisiert in der 3D-Schaltflächenleiste (d_1c0af4) den Aktivierungszustand der Schalter für das
 *   Aufnehmen liegender Gegenstände (0x30) und für das Teilen/Wechseln von Gruppen (0x31) und gibt im
 *   Vollbildmodus bei neu entdeckten Bodenobjekten eine Hinweismeldung (0x200001db) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
struct Button907 {
  static int update(unsigned char selected) {
    int shown=selected;
    int text=0;
    int state=f_0dab50(d_1c0af4,0x30);
    if(shown==state) {
      if(shown==0) f_0daa90(d_1c0af4,0x30);
      else {text=0x200001db;f_0daaf0(d_1c0af4,0x30);}
    }
    return text;
  }
};
void f_121320(void)
{
  short s, n, k;
  int i2, p, u, many;
  unsigned char valid;
  n = 0;
for (k = 0; k < 6; k++) { p = (int)&d_1bfdbc + k * 0x61; if (f_0de7c0(p) != 0) { if (f_0de980(p) == 0) { if (f_0de9c0(p) == 0) n = n + 1; } } }
  many = n > 1;
  s = f_0cda50();
  i2 = Button907::update(s!=-1);
  u = f_0dab50(d_1c0af4, 0x31);
  if (many == u) {
    if (u == 0)
      f_0daa90(d_1c0af4, 0x31);
    else
      f_0daaf0(d_1c0af4, 0x31);
  }
  if ((short)d_1c2198 == 1) {
    if (f_0bba10(A(d_1bf230)) != 0) {
      f_0daba0(d_1c0af4, d_1a34e0);
    } else {
      int feature = d_1bfb1c == 1;
      if (feature && i2 != 0) f_0bf730(A(d_1c2c64), i2);
    }
    *(short *)&d_1c2198 = 0;
  }
}
//@ f_121460
/* === Beschreibung (Katalog) ===
 * - Zweck: Schaltet das Schritt-Wippen der 3D-Kamera (d_1a9b38, d_1a9b3c) ab, wenn die Gruppe schleicht/schwebt
 *   oder der Anführer sich im Schwimmzustand befindet, und aktiviert es andernfalls mit den Standardwerten.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121460(void)
{
  if (d_1c0b1c == 1 || ((char)(f_042950((struct hero *)(f_038c40(d_1c0004))))) == 0) {
    d_1a9b38 = 0;
    d_1a9b3c = 0;
  } else {
    d_1a9b38 = d_1c0ba4;
    d_1a9b3c = d_1c0ba8;
  }
}
//@ f_1214b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Wertet in jedem Durchlauf der 3D-Schleife die Schaltflächenleiste und Tastatureingaben aus und
 *   verzweigt zu Inventar/Charakterbogen (0xaf), Zaubermenü (0xb0), Gruppenteilung (0xb1), Automap (0xb2),
 *   Optionen (0x8d), Tagebuch (0x83), Spiel-Beenden-Abfrage (0x80) oder zur allgemeinen 3D-Tastenbehandlung
 *   (f_120c60).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1214b0(void)
{
  int f_0d5780(int);
  short f_0bf820(int, ...);
  int f_059d50(int);
  int f_059d50(int, int);
  void k_f_0ce7e0(int, int);
  int p2;
  short s;
  int i3, t;
  char a[4];
  f_121320();
  f_0d5780((int)&d_1bf230);
  if (f_0bba10((int)&d_1bf230) == 0) {
    if (d_1bd766 == 0x4900 || f_0d37b0() == 1) {
      d_1bd766 = f_0db3d0(d_1c0af4);
      p2 = (short)d_1bd766;
      d_1bd766 = f_0dac90(d_1c0af4, p2);
    }
  } else {
    d_1bd766 = f_0dacc0(d_1c0af4);
  }
  if (d_1bd766 != 0) {
    if (d_1bd766 == 0x11b || d_1bd766 == 0x2d00) d_1bd766 = 0x80;
    switch ((unsigned short)d_1bd766) {
      case 0xaf: f_041220(); break;
      case 0xb0: f_041530(); break;
      case 0xb1: f_041ae0(0); break;
      case 0xb2: f_11f920(1); break;
      case 0x8d:
        f_0ce7c0((int)a);
        d_1c0b90 = 1;
        f_10cb70();
        if (EQ(d_1c0904, 1)) {
          d_1c0904 = 0;
          f_11f920(2);
        }
        d_1c0b90 = 0;
        k_f_0ce7e0((int)a, 0);
        break;
      case 0x83:
        t = (int)operator new(0x652, mark(d_1a8988, 0x218));
        i3 = t ? f_059d50(t) : t;
        f_05b860(i3, 0);
        if (i3) operator delete((void *)f_059d50(i3, 0));
        break;
      case 0x80:
        s = f_0bf820((int)&d_1c2c64, 0x9030002, 2, 0x200001d9, 0x200001da);
        if (s == 2) d_1c21a4 = 0x2a;
        break;
      default: f_120c60(); break;
    }
  }
  if (*(unsigned short *)&d_1a0100 == 1) f_120e70();
  while ((short)_bios_keybrd(_KEYBRD_READY) != (short)0) {
    d_1bd766 = _bios_keybrd(_KEYBRD_READ);
  }
}
//@ f_1216f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Haupt-Frameloop-Funktion der 3D-Ansicht (TDMLOOP.CPP), die beim Betreten eines neuen 3D-Szenarios
 *   sämtliche Grafik-, Musik-, Paletten- und Engine-Daten lädt und in jedem regulären Frame Kamerahöhe,
 *   Lichtradius (abhängig von Fackeln/Laternen/Zaubern), Benutzereingaben, Kollisionen, Kompass und
 *   3D-Bildaufbau steuert.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
#define I(p,o) (*(int *)((p)+(o)))
void f_1216f0(void)
{
  short k;
  int s;
  short y;
  if (d_1a9696 < 0) {
    d_1c0b2c = 0;
    d_1be1dc = 1;
    f_0d2f90(5, 1);
    f_0ce650();
    if (f_02fcb7(A(d_1c2e78)) == 1) f_0d4070(A(d_1c2e78));
    if (d_1bd6c0 != 0) {
      d_1c0b2c = 0;
      d_1c2a80 = 0;
      f_11faf0();
      f_11fb50();
    }
    f_1200b0();
    f_0b1340();
    f_149d20();
    f_11fc90();
    f_1201a0();
    f_11fee0(f_0de820(d_1c0004));
    d_1a9696 = f_0de820(d_1c0004);
    d_1a7fc2 = d_1a9696;
    f_1202a0();
    f_120310();
    f_120080();
    *(short *)&d_1c2198 = 0;
    *(short *)&d_1a0102 = 0;
    *(char *)&d_1c0028 = (char)f_041000();
    d_1c0c4c = 0;
    for (k = 0; k < 6; k++) f_0dbf10((int)&d_1bfdbc + k * 0x61);
    f_0b13d0(0);
    if (NEM(d_1bfb1c, 1)) {
      d_1a9910 = f_121d70;
      f_164880(0xd0, 0x87, 0x10, 2);
      d_1c0b9a = 0;
      f_123690();
      if (d_1bf510 == A(d_1a54c0)) d_1bf510 = A(d_1a539c);
      d_1bfb1c = 0;
      if (d_1c0af4 != 0) {
        d_1c2a80 = 0;
        f_0bc060(A(d_1bf230));
        f_0bcae0(A(d_1bf230), d_1a7fbc + 0x2d000001, 0xff, d_1a34e0);
        f_0daba0(d_1c0af4, d_1a34e0);
      }
      d_1c0c94 = d_1c0b84;
    } else {
      d_1a9910 = f_121d70;
      f_164880(0x140, 200, 0, 0);
      d_1c0b9a = 1;
      f_123690();
      d_1c2a80 = 0;
      if (d_1bf510 == A(d_1a539c)) d_1bf510 = A(d_1a54c0);
      d_1bfb1c = 1;
      d_1c0b84 = (short)d_1c0c94;
      d_1c0c94 = 0;
    }
    f_11fc00();
    f_149d20();
    f_0d2f90(0, 1);
    f_0d3f25(A(d_1c2e78), (&d_1a89b8)[(short)f_0de820(d_1c0004)]);
    f_0d26e0();
    if ((short)d_1c2198 == 0) {
      f_122b70(A(d_1c0bac));
      f_09a120(f_122c50(A(d_1c0bac)), 0x19);
      f_1223c0();
    }
    f_149d20();
    (*(void (**)(int))(I(d_1bd6c0, 8) + 0x20))(d_1bd6c0);
  } else {
    if (d_1bed5c != 0 && d_1a9696 == 0 && d_1bed5c == 6) {
      f_0d64a0();
      ((int (*)(unsigned))f_0f2720)(6);   // Definition gz_0f25c0_t1: int f_0f2720(unsigned)
      f_0dd7f0(d_1c0004, 0x17, 0x146b);
      d_1c0314 = 1;
      d_1bed8c = 1;
      d_1bed5c = 0;
    }
    if (d_1bfa78 == 1 || (short)d_1c2198 == 1 || d_1c0b98) {
      if ((short)f_0de820(d_1c0004) == d_1a9696) {
        if (f_060a80((short)f_0de820(d_1c0004)) == 0) d_1c2a80 = 0;
        f_122b70(A(d_1c0bac));
        f_1232e0(A(d_1c0bac));
        f_122190();
        goto ende;
      }
    }
    if (d_1bfa78 == 1) {
      f_11fc00();
      d_1bfa78 = 0;
      goto ende;
    }
    d_1c0b2c = 1;
    d_1be1dc = 0;
    if (f_120570() != d_1a7fbe) {
      d_1a7fbe = f_120570();
      f_0de8b0(d_1c0004, (short)f_1205c0((short)d_1a7fbe) << 16);
      f_0de930(d_1c0004, 1);
    }
    if (d_1c0b9e != (short)f_0de4d0(d_1c0004) + 0xa) {
      unsigned short w = d_1a7fc0;
      int v = f_0de4d0(d_1c0004);
      d_1c0b9e = f_0de4d0(d_1c0004) + 0xa;
      if ((short)v < 0) y = 0;
      else if ((short)v == 0) y = w / 2;
      else y = (v - 3) * 4 + w;
      if ((unsigned short)y >= 0x3f) y = 0x3f;
      f_163b08(0, (unsigned short)y);
    }
    if (d_1c0b1c == 1 || ((char)(f_042950((struct hero *)(f_038c40(d_1c0004))))) == 0) {
      d_1a9b38 = 0;
      d_1a9b3c = 0;
    } else {
      d_1a9b38 = d_1c0ba4;
      d_1a9b3c = d_1c0ba8;
    }
    if (d_1c0b1c == 0) f_1214b0(); else f_149d20();
    if ((short)f_0de820(d_1c0004) == d_1a9696) {
      if ((short)d_1a9696 != -1) {
        if ((short)d_1c21a4 == 0) {
          d_1c0b34++;
          d_1c0b28++;
          if (d_1c0b18 == 1 || d_1c0b1c == 1) {
            int feature = (char)d_1c0b99 * (short)(char)d_1a8958 / 100;
            if (feature != d_1c0b8c) {
              if (d_1c0b8c != 0) {
                d_1c0b8c = feature;
                f_0de8b0(d_1c0004, feature << 16);
                f_0de930(d_1c0004, 1);
              } else {
                d_1c0b8c = feature;
              }
            }
          }
          if (d_1c2ed8 != d_1c0b8a) f_0d2f90((short)d_1c2ed8, 1);
          f_1232e0(A(d_1c0bac));
          if ((short)d_1c2198 == 0) f_1223c0();
          f_019b40(A(d_1c2a84), d_1c90c0, d_1c90c8);
          if (d_1c0b1c == 0 && d_1c0b18 == 0) f_11f790();
        }
      }
    }
  }
ende:
  if ((short)f_0de820(d_1c0004) != d_1a9696 || (short)d_1c21a4 != 0) {
    f_0ce650();
    if (f_02fcb7(A(d_1c2e78)) == 1) f_0d4070(A(d_1c2e78));
    if (d_1bd6c0 != 0) {
      d_1c0b2c = 0;
      d_1c2a80 = 0;
      f_11faf0();
      f_11fb50();
    }
    {
      signed char j;   // haelt Registerwahl eax/edx bei cwde und d_1c2ed8-Vergleich in f_1216f0 wie im Original
      d_1c0b98 = j ^ j;
    }
  }
}

//@ f_121d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Beendet beim Verlassen der 3D-Ansicht die laufende Hintergrundmusik sowie die aktuelle 3D-Szenerie
 *   (f_11faf0, f_11fb50).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den letzten Rückgabewert der Aufräumaufrufe zurück.
 === Ende Beschreibung === */
int f_121d20(void)
{
  int r;
  f_0ce650();
  r = f_02fcb7(A(d_1c2e78));
  if (r == 1) r = f_0d4070(A(d_1c2e78));
  if (d_1bd6c0 != 0) {
    d_1c0b2c = 0;
    d_1c2a80 = 0;
    f_11faf0();
    r = f_11fb50();
  }
  return r;
}
//@ f_121d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Callback-Funktion (d_1a9910) für die 3D-Render-Engine.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121d70(void)
{
}
//@ f_121d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Richtet die Auflösung und das Rahmenbild des 3D-Sichtfensters (208 x 135 im Fenstermodus bzw. 320 x
 *   200 im Vollbildmodus) sowie die zugehörige Steuerungstabelle (f_11fc00) ein.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_121d80(void)
{
  if (NEM(d_1bfb1c, 1)) {
    d_1a9910 = f_121d70;
    f_164880(0xd0, 0x87, 0x10, 2);
    d_1c0b9a = 0;
    f_123690();
    if (d_1bf510 == A(d_1a54c0)) d_1bf510 = A(d_1a539c);
    d_1bfb1c = 0;
    if (d_1c0af4 != 0) {
      d_1c2a80 = 0;
      f_0bc060(A(d_1bf230));
      f_0bcae0(A(d_1bf230), d_1a7fbc + 0x2d000001, 0xff, d_1a34e0);
      f_0daba0(d_1c0af4, d_1a34e0);
    }
    d_1c0c94 = d_1c0b84;
    f_11fc00();
    return;
  }
  d_1a9910 = f_121d70;
  f_164880(0x140, 200, 0, 0);
  d_1c0b9a = 1;
  f_123690();
  d_1c2a80 = 0;
  if (d_1bf510 == A(d_1a539c)) d_1bf510 = A(d_1a54c0);
  d_1bfb1c = 1;
  d_1c0b84 = (short)d_1c0c94;
  d_1c0c94 = 0;
  f_11fc00();
}
