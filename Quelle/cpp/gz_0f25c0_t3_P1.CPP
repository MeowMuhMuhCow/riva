/* === Beschreibung (Katalog) ===
 * Einheit gz_0f25c0_t3
 *
 * Diese Einheit bildet den dritten und letzten Teil des Options- und Spielstandsmenüs (gz_0f25c0, Teil 3) und
 * verwaltet das Speichern und Laden des Miniatur-Vorschaubilds (Screenshots) der aktuellen 3D-Ansicht in den
 * Spielstandsdateien.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P1 2/2 gleich
// gz_0f25c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F25C0-0x0F5110
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_060230();                                         // reg - stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0cda50();                                         // reg - stapel 0
int f_0ce650();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0ef8d0();                                         // reg - stapel 0
int f_0ef8f0();                                         // reg - stapel 0
int f_0ef910();                                         // reg - stapel 0
int f_0ef930();                                         // reg - stapel 0
int f_0ef950();                                         // reg - stapel 0
int f_0ef970();                                         // reg - stapel 0
int f_0ef990();                                         // reg - stapel 0
int f_0ef9b0();                                         // reg - stapel 0
int f_0ef9e0();                                         // reg - stapel 0
int f_0efa10();                                         // reg - stapel 0
int f_0efa30();                                         // reg - stapel 0
int f_0efa50();                                         // reg - stapel 0
int f_0efaa0();                                         // reg - stapel 0
int f_0efb10();                                         // reg - stapel 0
int f_0efb30();                                         // reg - stapel 0
int f_0efb50();                                         // reg - stapel 0
int f_0f5110();                                         // reg - stapel 0
                           // reg eax stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc7a8;                    // 0x1BC7A8
extern int d_1bed80;                    // 0x1BED80
extern int d_1bed9c;                    // 0x1BED9C
extern int d_1bee00;                    // 0x1BEE00
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c00c4;                    // 0x1C00C4
extern int d_1c0178;                    // 0x1C0178
extern int d_1c0179;                    // 0x1C0179
extern int d_1c017c;                    // 0x1C017C
extern int d_1c017d;                    // 0x1C017D
extern int d_1c0180;                    // 0x1C0180
extern int d_1c0181;                    // 0x1C0181
extern int d_1c0184;                    // 0x1C0184
extern int d_1c0185;                    // 0x1C0185
extern int d_1c0188;                    // 0x1C0188
extern int d_1c0189;                    // 0x1C0189
extern int d_1c018c;                    // 0x1C018C
extern int d_1c018d;                    // 0x1C018D
extern int d_1c0190;                    // 0x1C0190
extern int d_1c0191;                    // 0x1C0191
extern int d_1c0194;                    // 0x1C0194
extern int d_1c0195;                    // 0x1C0195
extern int d_1c0198;                    // 0x1C0198
extern int d_1c0199;                    // 0x1C0199
extern int d_1c019c;                    // 0x1C019C
extern int d_1c019d;                    // 0x1C019D
extern int d_1c01a0;                    // 0x1C01A0
extern int d_1c01a1;                    // 0x1C01A1
extern int d_1c01a4;                    // 0x1C01A4
extern int d_1c01a5;                    // 0x1C01A5
extern int d_1c01a8;                    // 0x1C01A8
extern int d_1c01a9;                    // 0x1C01A9
extern int d_1c01ac;                    // 0x1C01AC
extern int d_1c01ad;                    // 0x1C01AD
extern int d_1c01b0;                    // 0x1C01B0
extern int d_1c01b1;                    // 0x1C01B1
extern int d_1c01b4;                    // 0x1C01B4
extern int d_1c01b5;                    // 0x1C01B5
extern int d_1c01b9;                    // 0x1C01B9
extern int d_1c01bd;                    // 0x1C01BD
extern int d_1c01c0;                    // 0x1C01C0
extern int d_1c01c1;                    // 0x1C01C1
extern int d_1c01c4;                    // 0x1C01C4
extern int d_1c01c5;                    // 0x1C01C5
extern int d_1c01c8;                    // 0x1C01C8
extern int d_1c01c9;                    // 0x1C01C9
extern int d_1c01cc;                    // 0x1C01CC
extern int d_1c01cd;                    // 0x1C01CD
extern int d_1c01d0;                    // 0x1C01D0
extern int d_1c01d1;                    // 0x1C01D1
extern int d_1c01d4;                    // 0x1C01D4
extern int d_1c01d5;                    // 0x1C01D5
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c2198;                    // 0x1C2198
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0

extern signed char d_1c01b8;
extern signed char d_1c01bc;
extern char d_1c2c64[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_0bfa20(void *, ...);
int f_0bde40(int p1);
int f_0d5ff0(int p1);
short f_0db9a0(int p1);
int f_0f2c10(int p1);
int f_0f2c50(int p1);
int f_0f2c80(int p1);
#define A(x) ((int)(x))
#define EQI(x,v) (((x)==(v))?1:0)
#define CND ((short)p2 == (short)0x4ba)
struct SO { int a; int *p; char c[52]; };

//@ f_0f4e00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion erzeugt vor dem Öffnen des Spielstandsmenüs eine verkleinerte Kopie des aktuellen
 *   Spielbildschirms samt angepasster Farbpalette im Speicher, damit sie beim Speichern eines Spielstands als
 *   Vorschaubild in die .SAV-Datei eingebettet werden kann.
 * - Eingaben: Die Funktion erhält den Zeiger auf den aktuellen Bildschirmpuffer oder Grafikkontext (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreicher Erstellung des Vorschaubilds oder 0 bei Speichermangel
 *   zurück.
 === Ende Beschreibung === */
void f_0f4e00(int p1, int p2)
{
  int p1_00, p1_01, p1_02, iVar3;
  short sVar1;
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  if (EQI(d_1c01b8, 0)) {
    p1_00 = f_0606a0(0x250001, 2);
    p1_01 = f_0606a0(0x250001, 3);
    p1_02 = f_0f2c80(A(f_0f2c10));
    if (p1_02 == 0) {
      p1_02 = f_0f2c80(A(f_0f2c50));
    }
    o.p[1] = f_038c40(d_1c0004);
    if (CND) f_0bf730(A(d_1c2c64), 0x2500003d); else f_0bf730(A(d_1c2c64), 0x2500003e);
    f_0bde40(A(d_1c2c64));
    f_0bfa20(d_1c2c64, p1_00, 0, 0x2500003f, 0);
    f_0bde40(A(d_1c2c64));
    f_0bfa20(d_1c2c64, p1_00, 0, 0x25000040, 0);
    o.p[1] = p1_02;
    iVar3 = f_0f2c10(p1_02);
    if (iVar3 == 1) {
      f_0bde40(A(d_1c2c64));
      f_0bfa20(d_1c2c64, p1_00, 0, 0x25000041, 0);
      f_0bde40(A(d_1c2c64));
      f_0bfa20(d_1c2c64, p1_00, 0, 0x25000042, 0);
      if (f_0db9a0(d_1c0004) > 1) {
        f_0bde40(A(d_1c2c64));
        f_0bfa20(d_1c2c64, p1_00, 0, 0x25000043, 0);
        f_0bde40(A(d_1c2c64));
        f_0bfa20(d_1c2c64, p1_00, 0, 0x25000044, 0);
        f_0d5ff0(4);
        d_1c01b8 = 1;
      } else {
        f_0bde40(A(d_1c2c64));
        f_0bfa20(d_1c2c64, p1_01, 0, 0x25000045, 0);
        f_044300(p1_02, (short)(((int)(f_042960((struct hero *)(p1_02)))) - 4));
        f_0dd7f0(d_1c0004, 3, 0xc9);
      }
    } else {
      f_0bde40(A(d_1c2c64));
      f_0bfa20(d_1c2c64, p1_00, 0, 0x25000046, 0);
      f_0bde40(A(d_1c2c64));
      f_0bfa20(d_1c2c64, p1_00, 0, 0x25000042, 0);
      if (f_0db9a0(d_1c0004) > 1) {
        f_0bde40(A(d_1c2c64));
        f_0bfa20(d_1c2c64, p1_00, 0, 0x25000047, 0);
      } else {
        f_0bde40(A(d_1c2c64));
        f_0bfa20(d_1c2c64, p1_00, 0, 0x25000048, 0);
      }
      f_0d5ff0(4);
      d_1c01b8 = 1;
    }
    if (EQI(d_1c01b8, 1)) {
      f_091f70(0x11);
    }
    if (p1_01 != 0) {
      operator delete((void *)((int)(((RivaRasterImage*)(p1_01))->f_0fad20( 0))));
    }
    if (p1_00 != 0) {
      operator delete((void *)((int)(((RivaRasterImage*)(p1_00))->f_0fad20( 0))));
    }
  }
  f_1254a0(&o, 0);
}

//@ f_0f50e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den für das Spielstands-Vorschaubild und dessen Palette reservierten
 *   Zwischenspeicher wieder frei.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Speicherfreigabe zurück.
 === Ende Beschreibung === */
void f_0f50e0(void)
{
  if (EQI(d_1c01bc, 0)) {
    f_0bf730(A(d_1c2c64), 0x25000049);
    d_1c01bc = 1;
  }
}
