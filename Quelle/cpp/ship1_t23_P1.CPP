/* === Beschreibung (Katalog) ===
 * Einheit ship1_t23 (100e30 - 102e00)
 *
 * Überblick
 *
 * Die Einheit ship1_t23 umfasst die Teile 2 und 3 des 3D-Dungeon-Moduls ship1 (Kennung 0x2a, Schiffswrack /
 * zweites Schiffs-Szenario). Sie enthält sämtliche Detail-Interaktionen für Kabinen, Frachträume, Kämpfe,
 * Beutefunde und Unterwasser-Gefahren (f_100e30 bis f_102cc0).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// OPT -4r -onetx -zp1 -s
// Astra493: ship1 t2+t3, genuine original shared epilog context.
// P3 15/20 gleich (suche.py 26.10.2026, Basis ship1_t3_P1.CPP)
// P1 10/20 gleich
// ship1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FF6A0-0x102E00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039780(int p1, int p2);                           // reg eax edx stapel 0
int f_039be0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046eb0(int p1);                                   // reg eax stapel 0
int f_046ec0(int p1);                                   // reg eax stapel 0
int f_047120(int p1);                                   // reg eax stapel 0
int f_047570(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_047620(int p1, int p2);                           // reg eax edx stapel 0
int f_047650(int p1, int p2);                           // reg eax edx stapel 0
int f_047660(int p1, int p2);                           // reg eax edx stapel 0
int f_047720(int p1);                                   // reg eax stapel 0
int f_047830(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0bf980();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_135200(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a687e;                    // 0x1A687E
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0294;                    // 0x1C0294
extern int d_1c02a8;                    // 0x1C02A8
extern int d_1c02ac;                    // 0x1C02AC
extern int d_1c02b0;                    // 0x1C02B0
extern int d_1c02b4;                    // 0x1C02B4
extern int d_1c02b8;                    // 0x1C02B8
extern int d_1c02c0;                    // 0x1C02C0
extern int d_1c02c4;                    // 0x1C02C4
extern signed char d_1c02dc;                    // 0x1C02DC
extern int d_1c02e0;                    // 0x1C02E0
extern int d_1c02e4;                    // 0x1C02E4
extern int d_1c02e8;                    // 0x1C02E8
extern int d_1c02f0;                    // 0x1C02F0
extern int d_1c02f4;                    // 0x1C02F4
extern int d_1c02f8;                    // 0x1C02F8
extern int d_1c02fc;                    // 0x1C02FC
extern int d_1c0300;                    // 0x1C0300
extern int d_1c0304;                    // 0x1C0304
extern int d_1c0308;                    // 0x1C0308
extern int d_1c030c;                    // 0x1C030C
extern int d_1c0318;                    // 0x1C0318
extern int d_1c0364;                    // 0x1C0364
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a6860[];           // Text 0x1A6860
// --- eigene Funktionen (63), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

short f_149360(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
signed char f_03ad80(int p1, int p2);

short f_0bf6f0(int p1, int p2);
short __cdecl f_0bf820(int p1, int p2, int p3, int p4, int p5, int p6);
short __cdecl f_0bfa20(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
int f_0fdbd0(int p1);
signed char f_126430(int p1);
signed char f_126450(int p1);
signed char f_126460(int p1);
int f_060740(int p1, int p2);
void __cdecl f_149eb4(void *p1, int p2, int p3);
void __cdecl f_099ef0(void *p1, int p2, int p3);
int f_1254a0(int p1, int p2);
int f_046d90(int p1, int p2);
void *f_147c84(void *p1, int p2, void *p3);
extern signed char d_1c02a0, d_1c02a4, d_1c02c8, d_1c02cc, d_1c02d0, d_1c02d4, d_1c02d8;
extern short d_1bf4bc, d_1bf4be;
extern const char d_1b834c[], d_1b834e[], d_1b8350[];
#define EQI(x,v) (((x)==(v))?1:0)
#define PD(x) ((int)&(x))
struct OB { int a; int b; int x1; int x2; int c; int rest[10]; };
#define CTOR(o) f_125400(PD(o), PD(d_1c349c), PD(d_1c3870), PD(d_1c3498))
#define DTOR(o) f_1254a0(PD(o), 0)
#define DELP(p,call) if (p != 0) { operator delete((void *)(call)); }
struct f_046d10 { char b[0xc]; f_046d10(int a); };
struct f_112df0 { char b[0x14]; f_112df0(int a, int c, int d); };
#define NEWA(p,ln,a) p = (int)new (mark(d_1a6860, ln)) f_046d10(a);
#define NEWB(p,ln,a) p = (int)new (mark(d_1a6860, ln)) f_112df0(a, 0, 0);
#define ARG1 ok
#define CMPA(s) ((s) == (short)1)


extern int ship2_d_1c0004;
#pragma aux ship2_d_1c0004 "d_1c0004"
extern signed char ship2_d_1c02a0, ship2_d_1c02a8, ship2_d_1c02ac, ship2_d_1c02b0, ship2_d_1c02b4, ship2_d_1c02b8, ship2_d_1c02c4, ship2_d_1c030c;
#pragma aux ship2_d_1c02a0 "d_1c02a0"
#pragma aux ship2_d_1c02a8 "d_1c02a8"
#pragma aux ship2_d_1c02ac "d_1c02ac"
#pragma aux ship2_d_1c02b0 "d_1c02b0"
#pragma aux ship2_d_1c02b4 "d_1c02b4"
#pragma aux ship2_d_1c02b8 "d_1c02b8"
#pragma aux ship2_d_1c02c4 "d_1c02c4"
#pragma aux ship2_d_1c030c "d_1c030c"
extern signed char ship2_d_1c02c0;
#pragma aux ship2_d_1c02c0 "d_1c02c0"
extern signed char ship2_d_1c02e0, ship2_d_1c02e4, ship2_d_1c02e8, ship2_d_1c02f0, ship2_d_1c02f4, ship2_d_1c02f8, ship2_d_1c02fc, ship2_d_1c0300, ship2_d_1c0304, ship2_d_1c0308;
#pragma aux ship2_d_1c02e0 "d_1c02e0"
#pragma aux ship2_d_1c02e4 "d_1c02e4"
#pragma aux ship2_d_1c02e8 "d_1c02e8"
#pragma aux ship2_d_1c02f0 "d_1c02f0"
#pragma aux ship2_d_1c02f4 "d_1c02f4"
#pragma aux ship2_d_1c02f8 "d_1c02f8"
#pragma aux ship2_d_1c02fc "d_1c02fc"
#pragma aux ship2_d_1c0300 "d_1c0300"
#pragma aux ship2_d_1c0304 "d_1c0304"
#pragma aux ship2_d_1c0308 "d_1c0308"
extern char ship2_d_1c2c44[];
#pragma aux ship2_d_1c2c44 "d_1c2c44"
extern char ship2_d_1c2c64[];
#pragma aux ship2_d_1c2c64 "d_1c2c64"
extern const char ship2_d_1c349c[];
#pragma aux ship2_d_1c349c "d_1c349c"
extern const char ship2_d_1c3870[];
#pragma aux ship2_d_1c3870 "d_1c3870"
extern const char ship2_d_1c3498[];
#pragma aux ship2_d_1c3498 "d_1c3498"
extern const char ship2_d_1a6860[];
#pragma aux ship2_d_1a6860 "d_1a6860"
struct ContextShip2 { public:
// P3 38/40 gleich (suche.py 26.10.2026, Basis ship1_t2_P1.CPP)
// P1 35/40 gleich
// ship1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1 Teil t2, Code 0x100E30-0x102050
#define EQ(x,v) (((x)==(v))?1:0)
#define SEQ(s,k) ((s) == (short)(k))
struct SO { int a; int *p; char c[52]; };
struct T { char d[20]; T *f_112df0(int a, int b, int c); void f_112ec0(); T *f_112e70(int a); };
struct U { char d[12]; U *f_046d10(int a); int f_046ec0(); void f_046de0(); U *f_046d90(int a); int f_047120(); int f_047720(); void f_047830(int a, void *b, void *c); int f_047660(int a); };
struct W { char d[12]; W *f_05f190(int a, int b); void f_05f280(int a); int f_05f580(); W *f_05f220(int a); };
struct Y { char d[4]; Y *f_0fad20(int a); };
struct V { short (*f)(void *, int, int); };
struct X { char pad[8]; V *vt; };
#define VC(p,a,b) (((X *)(p))->vt->f((void *)(p), (a), (b)))
static int f_125400(void *o, const char *a, const char *b, const char *c);
static int f_1254a0(void *o, int a);
static int f_125ed0(void *a, int b);
static int f_0bf6c0(void *a, int b);
static int f_0bf680(void *a);
static int f_0bf6f0(void *a, int b);
static int f_0bf730(void *a, int b);
static int f_0bf7b0(void *a, int b, int c, int d, int e, int f);
static int f_0bfa20(int a, ...);
static int f_039320(int a, int b);
static int f_039660(int a, int b);
static int f_0396f0(int a, int b);
static int f_039420(int a, int b);
static int f_039780(int a, int b);
static int f_039040(int a);
static int f_039be0(int a, int b, int c);
static int f_038c40(int a);
static int f_0dcf00(int a, int b, int c);
static int f_0dd7f0(int a, int b, int c);
static int f_0d54f0(int a, int b);
static int f_0dbeb0(int a);
static int f_0dcae0(int a);
static int f_044850(int a, int b, int c);
static int f_060740(int a, int b);
static int f_060770(int a, int b);
static int f_0607e0(int a, int b);
static int f_05fa00(int a, int b);
static Y *f_0606a0(int a, int b);
static int f_09a400(void);
static int f_0fdbd0(int a);
static void f_1026d0(int p1, int p2);
static void f_1027e0(int p1);
static void f_100e30(void);
static void f_100f00(void);
static void f_100f30(void);
static void f_100f50(int p1);
static void f_100fd0(int p1);
static void f_101100(int p1);
static void f_101110(int p1);
static void f_101160(int p1);
static void f_101170(void);
static void f_101190(void);
static void f_1011b0(void);
static int f_1011d0(void);
static void f_101210(void);
static void f_101230(void);
static void f_1012e0(void);
static void f_101380(void);
static void f_1013f0(void);
static void f_1014c0(int p1);
static void f_101680(void);
static void f_1016a0(void);
static void f_1016f0(void);
static void f_101860(void);
static void f_101910(void);
static void f_1019c0(void);
static void f_101a30(void);
static void f_101a60(void);
static void f_101ae0(void);
static void f_101b60(void);
static void f_101bd0(void);
static void f_101bf0(void);
static void f_101c20(int p1);
static void f_101cf0(void);
static void f_101d10(void);
static void f_101d30(void);
static void f_101d60(void);
static void f_101e00(void);
static void f_101ea0(void);
static void f_101ec0(void);
static void f_101f10(void);
static void f_101f60(int p1);
};
//@ f_100e30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet das Öffnen einer unter Wasser klemmenden oder verschlossenen Kajütentür an
 *   den Koordinaten (p2, p3) mithilfe eines Schlüssels (p4) oder einer Kraftprobe und setzt bei Erfolg das
 *   Tür-Zustandsflag *p5.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die X-/Y-Koordinaten p2 und p3, die Schlüssel-ID p4 sowie
 *   den Zeiger p5 auf das Türflag.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_100e30(void)
{
  short s;
  SO o;
  T *p;
  if (EQ(ship2_d_1c02e4, 0)) {
    f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
    o.p[1] = f_039320(ship2_d_1c0004, 0x2a);
    s = f_0bf6f0(ship2_d_1c2c64, 0x2f00001c);
    f_1254a0(&o, 0);
  }
  if (EQ(ship2_d_1c02e4, 1) || SEQ(s, 1)) {
    p = new (mark(ship2_d_1a6860, 0x284)) T;
    p = p ? p->f_112df0(0x4d, 0, 0) : p;
    p->f_112ec0();
    if (p != 0) delete p->f_112e70(0);
  }
  ship2_d_1c02e4 = 1;
}
//@ f_100f00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft beim ersten Betreten eines Wrackabschnitts das Flag d_1c03bc und zeigt den
 *   Beschreibungstext 0x2e000001 an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_100f00(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f00001d);
  f_125ed0(ship2_d_1c2c44, 1);
}
//@ f_100f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet den Kampf gegen die Gegnergruppe 1 (0x1f41) im Bereich ship1.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void ContextShip2::f_100f30(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f00001e);
}
//@ f_100f50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lässt die Gruppe einen Schrank oder eine Seekiste (d_1c03bd) durchsuchen und übergibt
 *   die darin gefundenen Gegenstände.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_100f50(int p1)
{
  short s;
  if (EQ(ship2_d_1c02e8, 0)) {
    s = f_0bf6f0(ship2_d_1c2c64, 0x2f00001f);
    if (SEQ(s, 1)) {
      f_060740(0x1f41, 1);
      f_0bf730(ship2_d_1c2c64, 0x2f000020);
      ship2_d_1c02e8 = 1;
      f_060770(0x1f41, 0);
      f_1027e0(p1);
    }
  } else {
    f_060770(0x1f41, 0);
  }
}
//@ f_100fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wickelt die Untersuchung einer Offizierskabine (d_1c03be) ab, in der die Helden
 *   Dokumente oder Wertgegenstände bergen können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_100fd0(int p1)
{
  SO o;
  short s;
  if (EQ(ship2_d_1c02a0, 3)) {
    s = f_0bf6f0(ship2_d_1c2c64, 0x2f000028);
    if (SEQ(s, 1)) {
      s = f_0bf6f0(ship2_d_1c2c64, 0x2f000029);
      if (SEQ(s, 1)) {
        f_0fdbd0(p1);
        f_125ed0(ship2_d_1c2c44, 2);
      } else {
        ship2_d_1c02a0 = 5;
        f_0bf730(ship2_d_1c2c64, 0x2f00002a);
      }
      f_060740(0x1f47, 1);
    }
  } else {
    f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
    o.p[1] = f_039320(ship2_d_1c0004, 0x2a);
    f_0bf6c0(ship2_d_1c2c64, 5);
    if (EQ(ship2_d_1c02e0, 0)) {
      ship2_d_1c02e0 = 1;
      f_0bf730(ship2_d_1c2c64, 0x2f00001a);
      f_125ed0(ship2_d_1c2c44, 2);
    } else {
      f_0bf730(ship2_d_1c2c64, 0x2f00001b);
    }
    f_0bf680(ship2_d_1c2c64);
    f_1254a0(&o, 0);
  }
}
//@ f_101100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt das Statusflag d_1c03b9 auf 1.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101100(int p1)
{
  f_1026d0(p1, 1);
}
//@ f_101110
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim ersten Betreten (d_1c03bf) den Hinweistext 0x2e00000b aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101110(int p1)
{
  if (EQ(ship2_d_1c02a0, 0)) {
    f_05fa00(0x25, 0x1f43);
    f_1027e0(p1);
  } else {
    f_05fa00(0x25, 0x1f43);
  }
}
//@ f_101160
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt das Statusflag d_1c03ba auf 1.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101160(int p1)
{
  f_1026d0(p1, 2);
}
//@ f_101170
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sechs kurzen Methoden starten jeweils vordefinierte Kämpfe (0x1f42 bis 0x1f47) an Bord von
 *   ship1 bzw. setzen die zugehörigen Begegnungsflags.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Jede Funktion gibt den Rückgabewert von f_05fa00 zurück bzw. hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101170(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000033);
}
//@ f_101190
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000034 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Kurzer Text-Trigger in ship1.
 === Ende Beschreibung === */
void ContextShip2::f_101190(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000034);
}
//@ f_1011b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000035 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Kurzer Text-Trigger in ship1.
 === Ende Beschreibung === */
void ContextShip2::f_1011b0(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000035);
}
//@ f_1011d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Schaltet den Dialogmodus in d_1c2c64 über f_0bf6c0 auf 5, zeigt die Meldung
 *   0x2f000036 mit f_0bf730 an und setzt den Modus über f_0bf680 zurück.
 * - Eingaben / Rückgabe: Keine Parameter (void). Gibt den Rückgabewert von f_0bf680 (int) zurück.
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Gekapselte Textausgabe im Rahmenmodus 5.
 === Ende Beschreibung === */
int ContextShip2::f_1011d0(void)
{
  f_0bf6c0(ship2_d_1c2c64, 5);
  f_0bf730(ship2_d_1c2c64, 0x2f000036);
  return f_0bf680(ship2_d_1c2c64);
}

//@ f_101200
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Leere Platzhalter- bzw. No-Op-Funktion in ship1.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Keine.
 * - Besonderheiten: Besteht im Original nur aus ret.
 === Ende Beschreibung === */
void f_101200(void)
{
}

//@ f_101210
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f000037 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Kurzer Text-Trigger in ship1.
 === Ende Beschreibung === */
void ContextShip2::f_101210(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000037);
}
//@ f_101230
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese fünf Methoden verwalten das Durchsuchen verschiedener Kojen, Fässer und Spinde (d_1c03c0 bis
 *   d_1c03c5) im Schiffsrumpf, prüfen auf versteckte Fallen oder Gegner und übergeben gefundene
 *   Ausrüstungsgegenstände an die Heldengruppe.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101230(void)
{
    int codex_arg_0_211;
  SO o;
  short n;
  signed char c;
  signed char old;
  signed char m;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  o.p[1] = f_039660(ship2_d_1c0004, 1);
  n = f_0bf7b0(ship2_d_1c2c64, 2, 0x2f000038, 0, 0x50, 0);
  c = ship2_d_1c02a8;
  old = c;
  if (n >= 10) {
    f_0bf730(ship2_d_1c2c64, 0x2f000039);
  } else {
    if (c <= 70) f_0bf730(ship2_d_1c2c64, 0x2f00003a);
  }
  m = old;
  m -= n;
  ship2_d_1c02a8 = m;
  if (0 < n) {
    f_0dcf00((codex_arg_0_211 = ship2_d_1c0004), 0x48, n);
  }
  f_1254a0(&o, 0);
}
//@ f_1012e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Initialisiert einen lokalen Textkontext (f_125400), trägt den Gruppenanführer
 *   (f_038c40) ein, gibt die Meldung 0x2f00003b über f_0bf730 aus und öffnet anschließend den 20-Byte-Behälter
 *   0x4e (f_112df0, f_112ec0, f_112e70).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004, d_1c2c64 und d_1a6860 (Zeile 0x3d9).
 * - Besonderheiten: Kombiniert Raummeldung und Behälterinteraktion.
 === Ende Beschreibung === */
void ContextShip2::f_1012e0(void)
{
  SO o;
  T *p;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  o.p[1] = f_038c40(ship2_d_1c0004);
  f_0bf730(ship2_d_1c2c64, 0x2f00003b);
  p = new (mark(ship2_d_1a6860, 0x3d9)) T;
  p = p ? p->f_112df0(0x4e, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
  f_1254a0(&o, 0);
}
//@ f_101380
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Schatz-/Beuteobjekt 0x13 (f_046d10, Zeile 0x3eb); ist noch
 *   Inhalt vorhanden (f_046ec0() == 1), wird der Text 0x2f00003c ausgegeben und die Übergabe über f_046de0
 *   gestartet, bevor das Objekt freigegeben wird.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 und d_1a6860.
 * - Besonderheiten: Prüft vor der Übergabe mittels f_046ec0, ob der Fundort noch Gegenstände enthält.
 === Ende Beschreibung === */
void ContextShip2::f_101380(void)
{
  U *p;
  p = new (mark(ship2_d_1a6860, 0x3eb)) U;
  p = p ? p->f_046d10(0x13) : p;
  if (p->f_046ec0() == 1) {
    f_0bf730(ship2_d_1c2c64, 0x2f00003c);
    p->f_046de0();
  }
  if (p != 0) delete p->f_046d90(0);
}
//@ f_1013f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x14 (f_046d10, Zeile 0x407). Ist es nicht leer
 *   (f_046ec0() == 1), wird beim ersten Öffnen (d_1c02ac == 0) und vorhandenem Spezialinhalt (f_047120() != 0)
 *   ein Held (f_039660(d_1c0004, 10)) bestimmt und Text 0x2f00003d ausgegeben; danach wird d_1c02ac = 1 gesetzt
 *   und f_046de0 aufgerufen.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02ac, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Verknüpft eine einmalige Kommentarmeldung mit dem Beutefund 0x14.
 === Ende Beschreibung === */
void ContextShip2::f_1013f0(void)
{
  SO o;
  U *p;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  p = new (mark(ship2_d_1a6860, 0x407)) U;
  p = p ? p->f_046d10(0x14) : p;
  if (p->f_046ec0() == 1) {
    if (EQ(ship2_d_1c02ac, 0)) {
      if (p->f_047120() != 0) {
        o.p[1] = f_039660(ship2_d_1c0004, 10);
        f_0bf730(ship2_d_1c2c64, 0x2f00003d);
      }
    }
    ship2_d_1c02ac = 1;
    p->f_046de0();
  }
  if (p != 0) delete p->f_046d90(0);
  f_1254a0(&o, 0);
}
//@ f_1014c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Steuert eine Begegnung abhängig von den Flags d_1c02b4, d_1c02b8 und d_1c0300: Je
 *   nach Zustand wird der virtuelle Callback 0x30 des Dungeon-Objekts p1 aufgerufen (bei Rückgabe 0 wird
 *   d_1c0300 = 1 gesetzt, Text 0x2f000193 ausgegeben und f_125ed0(..., 2) ausgeführt) oder der Kampf 0x25
 *   (0x1f42) über f_05fa00 gestartet.
 * - Eingaben / Rückgabe: p1 (this-Zeiger des Dungeon-Objekts). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest d_1c02b4, d_1c02b8, liest und schreibt d_1c0300, nutzt d_1c0004, d_1c2c64
 *   und d_1c2c44.
 * - Besonderheiten: Nutzt einen virtuellen Methodenaufruf (VC(p1, 0x30, 0)) vor dem optionalen Kampfstart.
 === Ende Beschreibung === */
void ContextShip2::f_1014c0(int p1)
{
  SO o;
  short s;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  o.p[1] = f_038c40(ship2_d_1c0004);
  o.p[2] = f_039420(ship2_d_1c0004, 0xd);
  if (EQ(ship2_d_1c02b4, 1) && EQ(ship2_d_1c02b8, 0) && EQ(ship2_d_1c0300, 0)) {
    f_0bf730(ship2_d_1c2c64, 0x2f00003e);
    s = VC(p1, 0x30, 0);
    if (s == 0) {
      f_09a400();
      ship2_d_1c0300 = 1;
      f_0bf730(ship2_d_1c2c64, 0x2f000193);
      f_125ed0(ship2_d_1c2c44, 2);
    }
  }
  if (EQ(ship2_d_1c02b8, 1) && EQ(ship2_d_1c0300, 0)) {
    s = f_0bf6f0(ship2_d_1c2c64, 0x2f00003f);
    if (SEQ(s, 1)) {
      f_0bf730(ship2_d_1c2c64, 0x2f000040);
      s = VC(p1, 0x30, 0);
      if (s == 0) {
        f_09a400();
        ship2_d_1c0300 = 1;
        f_0bf730(ship2_d_1c2c64, 0x2f000193);
        f_125ed0(ship2_d_1c2c44, 2);
      }
    } else {
      f_05fa00(0x25, 0x1f42);
    }
  }
  if (EQ(ship2_d_1c0300, 1) || EQ(ship2_d_1c02b4, 0)) {
    f_05fa00(0x25, 0x1f42);
  }
  f_1254a0(&o, 0);
}
//@ f_101680
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet den Kampf 0x1f48 im Bereich ship1.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void ContextShip2::f_101680(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000042);
}
//@ f_1016a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese neun Methoden steuern weitere Raumuntersuchungen, Textmeldungen und Beutefunde (d_1c03c6 bis
 *   d_1c03ce) in den mittleren Decks von ship1.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_1016a0(void)
{
  SO o;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  o.p[1] = f_0396f0(ship2_d_1c0004, 0);
  f_0bf730(ship2_d_1c2c64, 0x2f000043);
  f_1254a0(&o, 0);
}
//@ f_1016f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet das 12-Byte-Beuteobjekt 0x15 (f_046d10, Zeile 0x48c). Solange d_1c02b0 == 0
 *   ist, speichert die Funktion vor dem Aufruf von f_046de0 die Stückzahlen aller enthaltenen Gegenstände
 *   (f_047720, f_047830, f_047660) in einem temporären Array und prüft danach, ob der Spieler mindestens einen
 *   Gegenstand entnommen hat; falls ja, wird d_1c02b0 = 1 gesetzt.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02b0, nutzt d_1a6860.
 * - Besonderheiten: Überwacht per Vorher-/Nachher-Vergleich der Gegenstandsanzahl, ob aus dem Beutelager 0x15
 *   etwas entnommen wurde.
 === Ende Beschreibung === */
struct P1016 { short x; short y; };
void ContextShip2::f_1016f0(void)
{
  int c;
  U *q;
  short n;
  short i, j;
  short b, a;
  P1016 *arr;
  int t = (int)operator new(0xc, mark(ship2_d_1a6860, 0x48c));
  q = t ? ((U *)t)->f_046d10(0x15) : (U *)t;
  if (q->f_046ec0() == 1) {
    n = -1;
    arr = 0;
    if (EQ(ship2_d_1c02b0, 0)) {
      n = q->f_047720();
      arr = (P1016 *)operator new[](n * 4, mark(ship2_d_1a6860, 0x499));
      for (i = 0; i < n; i++) {
        q->f_047830(i, &a, &b);
        arr[i].x = b;
        arr[i].y = q->f_047660((short)b);
      }
    }
    q->f_046de0();
    c = 0;
    if (EQ(ship2_d_1c02b0, 0)) {
      for (j = 0; j < n; j++) {
        if (c) break;
        if ((short)q->f_047660(arr[j].x) < arr[j].y)
          c = 1;
      }
      operator delete(arr);
    }
    if (c)
      ship2_d_1c02b0 = 1;
  }
  if (q)
    operator delete(q->f_046d90(0));
}
//@ f_101860
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c02f0 == 0) mit dem Gruppenanführer (f_038c40) die
 *   Meldung 0x2f000044 aus (d_1c02f0 = 1) und öffnet anschließend das 20-Byte-Behälterobjekt 0x54 (f_112df0,
 *   Zeile 0x4dd).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02f0, nutzt d_1c0004, d_1c2c64 und d_1a6860.
 * - Besonderheiten: Kombiniert einmalige Erstbeschreibung mit Behälter 0x54.
 === Ende Beschreibung === */
void ContextShip2::f_101860(void)
{
  SO o;
  T *p;
  if (EQ(ship2_d_1c02f0, 0)) {
    f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
    o.p[1] = f_038c40(ship2_d_1c0004);
    ship2_d_1c02f0 = 1;
    f_0bf730(ship2_d_1c2c64, 0x2f000044);
    f_1254a0(&o, 0);
  }
  p = new (mark(ship2_d_1a6860, 0x4dd)) T;
  p = p ? p->f_112df0(0x54, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
}
//@ f_101910
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c02f4 == 0) mit dem Gruppenanführer (f_038c40) die
 *   Meldung 0x2f000045 aus (d_1c02f4 = 1) und öffnet anschließend das 20-Byte-Behälterobjekt 0x55 (f_112df0,
 *   Zeile 0x4fb).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02f4, nutzt d_1c0004, d_1c2c64 und d_1a6860.
 * - Besonderheiten: Kombiniert einmalige Erstbeschreibung mit Behälter 0x55.
 === Ende Beschreibung === */
void ContextShip2::f_101910(void)
{
  SO o;
  T *p;
  if (EQ(ship2_d_1c02f4, 0)) {
    f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
    o.p[1] = f_038c40(ship2_d_1c0004);
    ship2_d_1c02f4 = 1;
    f_0bf730(ship2_d_1c2c64, 0x2f000045);
    f_1254a0(&o, 0);
  }
  p = new (mark(ship2_d_1a6860, 0x4fb)) T;
  p = p ? p->f_112df0(0x55, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
}
//@ f_1019c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Stellt bei d_1c0304 == 0 die Entscheidungsfrage 0x2f000046 (f_0bf6f0); stimmt der
 *   Spieler zu (1), wird d_1c0304 = 1 gesetzt, Gegenstand 0x20 übergeben (f_0dcf00) und die Kartenobjekte 0x1f4a
 *   (f_060740) sowie 0x1f48 (f_0607e0) umgeschaltet.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0304, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Einmalige Gegenstandsaufnahme mit Kartenstatus-Update.
 === Ende Beschreibung === */
void ContextShip2::f_1019c0(void)
{
  int r;
  if (EQ(ship2_d_1c0304, 0)) {
    r = f_0bf6f0(ship2_d_1c2c64, 0x2f000046);
    if (r == 1) {
      ship2_d_1c0304 = 1;
      f_0dcf00(ship2_d_1c0004, 0x20, 1);
      f_060740(0x1f4a, 1);
      f_0607e0(0x1f48, 1);
    }
  }
}
//@ f_101a30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Setzt den Dialogmodus über f_0bf6c0 auf 5, gibt den Text 0x2f000047 über f_0bf730
 *   aus und stellt den Standardmodus mit f_0bf680 wieder her.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Gekapselte Textausgabe im Rahmenmodus 5.
 === Ende Beschreibung === */
void ContextShip2::f_101a30(void)
{
  f_0bf6c0(ship2_d_1c2c64, 5);
  f_0bf730(ship2_d_1c2c64, 0x2f000047);
  f_0bf680(ship2_d_1c2c64);
}
//@ f_101a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Zeigt beim ersten Aufruf (d_1c02f8 == 0) den Text 0x2f000048 (und setzt d_1c02f8 =
 *   1), bei späteren Aufrufen 0x2f000049 an und öffnet danach das 20-Byte-Behälterobjekt 0x4f (f_112df0, Zeile
 *   0x53f).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02f8, nutzt d_1c2c64 und d_1a6860.
 * - Besonderheiten: Unterscheidet Erst- und Folgebesuch vor dem Öffnen von Behälter 0x4f.
 === Ende Beschreibung === */
void ContextShip2::f_101a60(void)
{
  int m;
  T *p;
  if (EQ(ship2_d_1c02f8, 0)) {
    m = 0x2f000048;
    ship2_d_1c02f8 = 1;
  } else {
    m = 0x2f000049;
  }
  f_0bf730(ship2_d_1c2c64, m);
  p = new (mark(ship2_d_1a6860, 0x53f)) T;
  p = p ? p->f_112df0(0x4f, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
}
//@ f_101ae0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ermittelt den Gruppenanführer (f_038c40) und stellt die Ja/Nein-Frage 0x2f00004a
 *   (f_0bf6f0); bei Bestätigung (1) wird Text 0x2f00004b ausgegeben und dem Helden über f_044850(m, 1, 5)
 *   Schaden bzw. ein Effekt zugefügt.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Gefahren-/Schadensinteraktion bei Bestätigung.
 === Ende Beschreibung === */
void ContextShip2::f_101ae0(void)
{
  SO o;
  int m, r;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  m = f_038c40(ship2_d_1c0004);
  r = f_0bf6f0(ship2_d_1c2c64, 0x2f00004a);
  if (r == 1) {
    o.p[1] = m;
    f_0bf730(ship2_d_1c2c64, 0x2f00004b);
    f_044850(m, 1, 5);
  }
  f_1254a0(&o, 0);
}
//@ f_101b60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Fragt bei d_1c02fc == 0 über f_0bf6f0 mit Text 0x2f00004c nach; bei Zustimmung (1)
 *   wird d_1c02fc = 1 gesetzt, der Gruppe zweimal Gegenstand 0x61 übergeben (f_0dcf00) und die Kartenobjekte
 *   0x1f4b (f_060740) sowie 0x1f49 (f_0607e0) aktualisiert.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02fc, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Gegenstück zu f_1019c0 für Fundstelle d_1c02fc.
 === Ende Beschreibung === */
void ContextShip2::f_101b60(void)
{
  int r;
  if (EQ(ship2_d_1c02fc, 0)) {
    r = f_0bf6f0(ship2_d_1c2c64, 0x2f00004c);
    if (r == 1) {
      ship2_d_1c02fc = 1;
      f_0dcf00(ship2_d_1c0004, 0x61, 2);
      f_060740(0x1f4b, 1);
      f_0607e0(0x1f49, 1);
    }
  }
}
//@ f_101bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese beiden Methoden starten die Kämpfe 0x1f49 und 0x1f4a in ship1.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Jede Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void ContextShip2::f_101bd0(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f00004d);
}
//@ f_101bf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Stellt über f_0bf6f0 die Entscheidungsfrage 0x2f000051 und führt bei Zustimmung (1)
 *   einen Orts-/Ebenenwechsel nach 0x18, Position 0x139a über f_0dd7f0 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Übergangspunkt aus ship1 in Gebiet 0x18.
 === Ende Beschreibung === */
void ContextShip2::f_101bf0(void)
{
  int r;
  r = f_0bf6f0(ship2_d_1c2c64, 0x2f000051);
  if (r == 1) {
    f_0dd7f0(ship2_d_1c0004, 0x18, 0x139a);
  }
}
//@ f_101c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese dreißig Ereignis- und Interaktionsmethoden decken die restlichen Räume, Luken, Kämpfe (0x1f4b
 *   bis 0x1f52) und Truhen (d_1c03cf bis d_1c03ea) in den unteren Decks von ship1 ab, darunter das Bergen von
 *   Schätzen, das Auslösen von Einsturz- oder Wasserschäden bei misslungenen Talentproben sowie das Verlassen
 *   des Schiffsbereichs.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1 des Dungeon-Objekts.
 * - Rückgabewert: Die Kampffunktionen geben den Status von f_05fa00 zurück; die Untersuchungsroutinen haben
 *   keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextShip2::f_101c20(int p1)
{
  SO o;
  short s;
  int m;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  if (f_039040(ship2_d_1c0004) == 0) {
    m = f_0396f0(ship2_d_1c0004, 1);
  } else {
    m = f_039040(ship2_d_1c0004);
    m = f_039be0(ship2_d_1c0004, m, 1);
  }
  o.p[1] = m;
  if (EQ(ship2_d_1c02c0, 1)) {
    f_0bf730(ship2_d_1c2c64, 0x2f000052);
    s = VC(p1, 0x5b, 0);
    if (s == 1) {
      ship2_d_1c030c = 4;
    } else if (s == 0) {
      ship2_d_1c02c0 = 2;
    }
  } else {
    f_0bf730(ship2_d_1c2c64, 0x2f000053);
  }
  f_1254a0(&o, 0);
}
//@ f_101cf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Hinweistext 0x2f000033 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Identischer Text-Trigger wie f_101170 und f_101d10.
 === Ende Beschreibung === */
void ContextShip2::f_101cf0(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000033);
}
//@ f_101d10
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Hinweistext 0x2f000033 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Identischer Text-Trigger wie f_101170 und f_101cf0.
 === Ende Beschreibung === */
void ContextShip2::f_101d10(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f000033);
}
//@ f_101d30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Stellt über f_0bf6f0 die Entscheidungsfrage 0x2f000051 und führt bei Zustimmung (1)
 *   einen Orts-/Ebenenwechsel nach 0x18, Position 0x13fe über f_0dd7f0 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Zweiter Übergangspunkt nach Gebiet 0x18 (Zielkoordinate 0x13fe).
 === Ende Beschreibung === */
void ContextShip2::f_101d30(void)
{
  int r;
  r = f_0bf6f0(ship2_d_1c2c64, 0x2f000051);
  if (r == 1) {
    f_0dd7f0(ship2_d_1c0004, 0x18, 0x13fe);
  }
}
//@ f_101d60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft über f_039780(d_1c0004, 5) bzw. f_039320(d_1c0004, 0x12), ob ein passender
 *   Held anwesend ist, gibt die Raummeldung 0x2f000055 aus und ergänzt beim ersten Mal (d_1c02c4 == 0, sofern
 *   ein Held gefunden wurde) den Zusatztext 0x2f000056 (d_1c02c4 = 1).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02c4, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Talent-/Heldenabhängiger Zusatzhinweis beim ersten Betreten.
 === Ende Beschreibung === */
void ContextShip2::f_101d60(void)
{
  SO o;
  int r;
  f_125400(&o, ship2_d_1c349c, ship2_d_1c3870, ship2_d_1c3498);
  r = f_039780(ship2_d_1c0004, 5);
  if (r == 0) {
    r = f_039320(ship2_d_1c0004, 0x12);
  }
  f_0bf730(ship2_d_1c2c64, 0x2f000055);
  if (r != 0 && EQ(ship2_d_1c02c4, 0)) {
    ship2_d_1c02c4 = 1;
    o.p[1] = r;
    f_0bf730(ship2_d_1c2c64, 0x2f000056);
  }
  f_1254a0(&o, 0);
}
//@ f_101e00
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Verarbeitet eine Interaktion mit Flag d_1c0308: Ist es 0, wird Frage 0x2f000057
 *   gestellt und bei Zustimmung geprüft, ob Gegenstand 0x1a vorhanden ist (f_0d54f0); falls ja, wird d_1c0308 =
 *   1 gesetzt, f_125ed0(..., 4) aufgerufen und Text 0x2f000058 (sonst 0x2f000059) gezeigt. Ist d_1c0308 == 1,
 *   werden f_0dbeb0 und f_0dcae0 ausgeführt.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0308, nutzt d_1c0004, d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Gegenstandsgekoppelte Freischaltung mit anschließendem Gruppen-Update (f_0dbeb0, f_0dcae0).
 === Ende Beschreibung === */
void ContextShip2::f_101e00(void)
{
  short s;
  int m, r;
  if (EQ(ship2_d_1c0308, 0)) {
    r = f_0bf6f0(ship2_d_1c2c64, 0x2f000057);
    if (r == 1) {
      s = f_0d54f0(ship2_d_1c0004, 0x1a);
      if (s >= 0) {
        ship2_d_1c0308 = 1;
        f_125ed0(ship2_d_1c2c44, 4);
        m = 0x2f000058;
      } else {
        m = 0x2f000059;
      }
      f_0bf730(ship2_d_1c2c64, m);
    }
  } else {
    f_0bf730(ship2_d_1c2c64, 0x2f00005a);
  }
  if (EQ(ship2_d_1c0308, 1)) {
    f_0dbeb0(ship2_d_1c0004);
    f_0dcae0(ship2_d_1c0004);
  }
}
//@ f_101ea0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f00005b über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Kurze Textausgabe-Routine.
 === Ende Beschreibung === */
void ContextShip2::f_101ea0(void)
{
  f_0bf730(ship2_d_1c2c64, 0x2f00005b);
}
//@ f_101ec0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x52 (f_112df0, Zeile 0x65c), führt dessen
 *   Interaktion über f_112ec0 aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6860 für mark.
 * - Besonderheiten: Standard-Behälter-Wrapper.
 === Ende Beschreibung === */
void ContextShip2::f_101ec0(void)
{
  T *p;
  p = new (mark(ship2_d_1a6860, 0x65c)) T;
  p = p ? p->f_112df0(0x52, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
}
//@ f_101f10
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x53 (f_112df0, Zeile 0x66e), führt dessen
 *   Interaktion über f_112ec0 aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6860 für mark.
 * - Besonderheiten: Standard-Behälter-Wrapper.
 === Ende Beschreibung === */
void ContextShip2::f_101f10(void)
{
  T *p;
  p = new (mark(ship2_d_1a6860, 0x66e)) T;
  p = p ? p->f_112df0(0x53, 0, 0) : p;
  p->f_112ec0();
  if (p != 0) delete p->f_112e70(0);
}
//@ f_101f60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Kampfobjekt (f_05f190(0x27, 0x1f44), Zeile 0x683) und startet es
 *   über f_05f280(0). Nach erfolgreichem Kampf (f_05f580() != 0) und d_1c02c0 == 0 wird ein Porträtbild
 *   (f_0606a0(0x2f0002, 4)) mit Dialog 0x2f00005c (f_0bfa20) angezeigt und über den virtuellen Aufruf VC(p1,
 *   0x35, 0) ggf. d_1c02c0 = 2 gesetzt.
 * - Eingaben / Rückgabe: p1 (this-Zeiger des Dungeon-Objekts). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02c0, nutzt d_1c2c64 und d_1a6860.
 * - Besonderheiten: Verknüpft den Kampf 0x1f44 mit einer nachfolgenden Bild-/Dialogszene.
 === Ende Beschreibung === */
void ContextShip2::f_101f60(int p1)
{
  W *q;
  Y *r;
  short s;
  q = new (mark(ship2_d_1a6860, 0x683)) W;
  q = q ? q->f_05f190(0x27, 0x1f44) : q;
  q->f_05f280(0);
  if (EQ(ship2_d_1c02c0, 0)) {
    if (q->f_05f580() != 0) {
      f_0bf6c0(ship2_d_1c2c64, 5);
      r = f_0606a0(0x2f0002, 4);
      f_0bfa20((int)ship2_d_1c2c64, r, 0, 0x2f00005c, 0);
      if (r) delete r->f_0fad20(0);
      s = VC(p1, 0x35, 0);
      if (s == 0) ship2_d_1c02c0 = 2;
      f_0bf680(ship2_d_1c2c64);
    }
  }
  if (q) delete q->f_05f220(0);
}

#undef EQ
//@ f_102050
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt bei d_1c02d4 == 0 einen Dialog zwischen zwei Helden (f_0396f0, f_039be0,
 *   f_039660) mit den Texten 0x2f00005d und - falls zwei verschiedene Helden beteiligt sind - 0x2f00005e über
 *   f_0bf730 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest d_1c02d4, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Zweistufiger Gruppenkommentar mit bis zu zwei Sprechern.
 === Ende Beschreibung === */
void f_102050(void)
{
    struct OB ob;
    int p2;
    int p3;
    CTOR(ob);
    if (EQI(d_1c02d4, 0)) {
        p2 = f_0396f0(d_1c0004, 1);
        if (p2 == f_039040(d_1c0004)) {
            p2 = f_039be0(d_1c0004, p2, 1);
        }
        p3 = f_039660(d_1c0004, 1);
        *(int *)(ob.b + 4) = p2;
        f_0bf730(PD(d_1c2c64), 0x2f00005d);
        if (p2 != p3) {
            *(int *)(ob.b + 8) = p3;
            f_0bf730(PD(d_1c2c64), 0x2f00005e);
        }
    }
    DTOR(ob);
}
//@ f_102110
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x34 (f_046d10, Zeile 0x6d8), führt f_046de0 aus,
 *   gibt das Objekt frei und aktualisiert den Kartenstatus über f_125ed0(&d_1c2c44, 2).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c44 und d_1a6860.
 * - Besonderheiten: Fundstellen-Wrapper mit anschließendem Status-Update.
 === Ende Beschreibung === */
void f_102110(void)
{
    int p;
    NEWA(p, 0x6d8, 0x34);
    f_046de0(p);
    DELP(p, f_046d90(p, 0));
    f_125ed0(PD(d_1c2c44), 2);
}
//@ f_102170
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet im Dialogmodus 6 (f_0bf6c0) das 12-Byte-Beuteobjekt 0x35 (f_046d10, Zeile
 *   0x6f0). Ist Inhalt vorhanden (f_046ec0 == 1), wird beim ersten Mal (d_1c02d8 == 0) ein Held ermittelt
 *   (f_039780 bzw. f_039320) und Text 0x2f00005f ausgegeben (d_1c02d8 = 1), bevor f_046de0 und
 *   f_125ed0(&d_1c2c44, 3) aufgerufen werden.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02d8, nutzt d_1c0004, d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Nutzt Dialogmodus 6 und Status-Update 3.
 === Ende Beschreibung === */
void f_102170(void)
{
    struct OB ob;
    int p;
    int r;
    CTOR(ob);
    f_0bf6c0(PD(d_1c2c64), 6);
    NEWA(p, 0x6f0, 0x35);
    if (f_046ec0(p) == 1) {
        if (EQI(d_1c02d8, 0)) {
            d_1c02d8 = 1;
            r = f_039780(d_1c0004, 5);
            if (r == 0) {
                r = f_039320(d_1c0004, 0x1c);
            }
            *(int *)(ob.b + 4) = r;
            f_0bf730(PD(d_1c2c64), 0x2f00005f);
        }
        f_046de0(p);
    }
    f_0bf680(PD(d_1c2c64));
    DELP(p, f_046d90(p, 0));
    f_125ed0(PD(d_1c2c44), 3);
    DTOR(ob);
}
//@ f_102270
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x36 (f_046d10, Zeile 0x718), führt f_046de0 aus,
 *   gibt das Objekt frei und ruft f_125ed0(&d_1c2c44, 2) auf.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c44 und d_1a6860.
 * - Besonderheiten: Fundstellen-Wrapper mit Status-Update 2.
 === Ende Beschreibung === */
void f_102270(void)
{
    int p;
    NEWA(p, 0x718, 0x36);
    f_046de0(p);
    DELP(p, f_046d90(p, 0));
    f_125ed0(PD(d_1c2c44), 2);
}
//@ f_1022d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x37 (f_046d10, Zeile 0x72c), führt f_046de0 aus,
 *   gibt das Objekt frei und ruft f_125ed0(&d_1c2c44, 3) auf.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c44 und d_1a6860.
 * - Besonderheiten: Fundstellen-Wrapper mit Status-Update 3.
 === Ende Beschreibung === */
void f_1022d0(void)
{
    int p;
    NEWA(p, 0x72c, 0x37);
    f_046de0(p);
    DELP(p, f_046d90(p, 0));
    f_125ed0(PD(d_1c2c44), 3);
}
//@ f_102330
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft bei d_1c02c8 == 0 eine Talentprobe (0x33, Erschwernis 0xc) des Anführers
 *   (f_038c40, f_044c90). Gelingt sie (oder war d_1c02c8 bereits 1), wird beim ersten Mal d_1c02c8 = 1 gesetzt,
 *   Text 0x2f000060 sowie f_125ed0(&d_1c2c44, 1) ausgelöst und anschließend der 20-Byte-Behälter 0x50 (f_112df0,
 *   Zeile 0x75f) geöffnet.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02c8, nutzt d_1c0004, d_1c2c64, d_1c2c44 und d_1a6860.
 * - Besonderheiten: Durch eine Talentprobe (0x33) gesicherter Behälter 0x50.
 === Ende Beschreibung === */
void f_102330(void)
{
    struct OB ob;
    int ok;
    int p;
    int q;
    short s;
    CTOR(ob);
    if (EQI(d_1c02c8, 0)) {
        p = f_038c40(d_1c0004);
        s = f_044c90(p, 0x33, 0xc);
        if (s > 0) {
            d_1c02c8 = 1;
            *(int *)(ob.b + 4) = p;
            ok = 1;
            f_0bf730(PD(d_1c2c64), 0x2f000060);
            f_125ed0(PD(d_1c2c44), ARG1);
        } else {
            ok = 0;
        }
    } else {
        ok = 1;
    }
    if (ok == 1) {
        NEWB(q, 0x75f, 0x50);
        f_112ec0(q);
        DELP(q, f_112e70(q, 0));
    }
    DTOR(ob);
}
//@ f_102420
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Zeigt beim ersten Aufruf (d_1c02cc == 0) mit einem ausgewählten Helden (f_039780
 *   bzw. f_038be0) den Text 0x2f000061 an (d_1c02cc = 1) und gibt bei weiteren Aufrufen 0x2f000062 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02cc, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Zweistufige Raumbeschreibung (Erst-/Folgebesuch).
 === Ende Beschreibung === */
void f_102420(void)
{
    struct OB ob;
    int r;
    CTOR(ob);
    if (EQI(d_1c02cc, 0)) {
        d_1c02cc = 1;
        r = f_039780(d_1c0004, 5);
        if (r == 0) {
            r = f_038be0(d_1c0004);
        }
        *(int *)(ob.b + 4) = r;
        f_0bf730(PD(d_1c2c64), 0x2f000061);
    } else {
        f_0bf730(PD(d_1c2c64), 0x2f000062);
    }
    DTOR(ob);
}
//@ f_1024b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x38 (f_046d10, Zeile 0x794). Ist d_1c02d0 == 0,
 *   wird geprüft, ob Inhalt vorhanden ist (f_046ec0 == 1); falls ja, wird d_1c02d0 = 1 gesetzt, Text 0x2f000063
 *   ausgegeben und f_046de0 aufgerufen.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02d0, nutzt d_1c0004, d_1c2c64 und d_1a6860.
 * - Besonderheiten: Überspringt f_046de0 beim Erstversuch, falls f_046ec0(p) != 1.
 === Ende Beschreibung === */
void f_1024b0(void)
{
    struct OB ob;
    int p;
    CTOR(ob);
    NEWA(p, 0x794, 0x38);
    if (EQI(d_1c02d0, 0)) {
        if (f_046ec0(p) != 1) goto L1;
        d_1c02d0 = 1;
        *(int *)(ob.b + 4) = f_038c40(d_1c0004);
        f_0bf730(PD(d_1c2c64), 0x2f000063);
    }
    f_046de0(p);
L1:
    DELP(p, f_046d90(p, 0));
    DTOR(ob);
}
//@ f_102570
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x51 (f_112df0, Zeile 0x7b8), führt f_112ec0
 *   aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6860 für mark.
 * - Besonderheiten: Standard-Behälter-Wrapper (NEWB).
 === Ende Beschreibung === */
void f_102570(void)
{
    int p;
    NEWB(p, 0x7b8, 0x51);
    f_112ec0(p);
    DELP(p, f_112e70(p, 0));
}
//@ f_1025c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ermittelt einen Helden über f_039320(d_1c0004, 0x22), trägt ihn in den lokalen
 *   Textkontext ein und gibt die Meldung 0x2f000064 über f_0bf730 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Heldenbezogene Raummeldung.
 === Ende Beschreibung === */
void f_1025c0(void)
{
    struct OB ob;
    CTOR(ob);
    *(int *)(ob.b + 4) = f_039320(d_1c0004, 0x22);
    f_0bf730(PD(d_1c2c64), 0x2f000064);
    DTOR(ob);
}
//@ f_102620
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x39 (f_046d10, Zeile 0x7dc). Ist f_046eb0(p) != 0,
 *   wird direkt f_046de0(p) aufgerufen; andernfalls wird bei f_046ec0(p) == 1 ein Held (f_039320(d_1c0004,
 *   0x20)) ermittelt, Text 0x2f000065 ausgegeben und danach f_046de0(p) gestartet.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004, d_1c2c64 und d_1a6860.
 * - Besonderheiten: Prüft f_046eb0 und f_046ec0 vor der Beuteübergabe.
 === Ende Beschreibung === */
void f_102620(void)
{
    struct OB ob;
    int p;

    CTOR(ob);
    NEWA(p, 0x7dc, 0x39);
    if (f_046eb0(p) != 0) {
        f_046de0(p);
    } else {
        if (f_046ec0(p) == 1) {
            *(int *)(ob.b + 4) = f_039320(d_1c0004, 0x20);
            f_0bf730(PD(d_1c2c64), 0x2f000065);
            f_046de0(p);
        } else {
            goto L2;
        }
    }
L2:
    DELP(p, f_046d90(p, 0));
    DTOR(ob);
}
inline int EQ(int a, int b) { return a == b; }
#define FZ2(x) EQ(x,0)
//@ f_1026d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Steuert ein Auswahlmenü (0x2f00002b / 0x2f00002c bzw. 0x2f00002d, Flag d_1c02a4):
 *   Bei Option 1 wird je nach Parameter p2 die Animation/Sequenz 0x2f0003 (p2 == 1) oder 0x2f0005 (f_060800)
 *   abgespielt; bei Option 2 wird d_1c02a4 = 0 zurückgesetzt, 0x1f48/0x1f49 über f_060740 geschaltet, Text
 *   0x2f000031 ausgegeben und f_125ed0(&d_1c2c44, 1) aufgerufen.
 * - Eingaben / Rückgabe: p1 (int, ungenutzter this-Zeiger), p2 (short, Richtungs-/Sequenzkennung 1 oder 2). Kein
 *   Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02a4, nutzt d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Wird von f_101100 (p2 = 1) und f_101160 (p2 = 2) aufgerufen.
 === Ende Beschreibung === */
void f_1026d0(int p1, short p2)
{
 int ask493(int,int);
#pragma aux ask493 "f_0bf6f0"

  short menu493(int,int,int,int,int,int);
#pragma aux menu493 "f_0bf820" parm caller [] value [ax] modify exact [eax];

    short s;
    if (EQI(d_1c02a4, 0)) {
        s = ask493(PD(d_1c2c64), 0x2f00002b);
        if (CMPA(s)) {
            d_1c02a4 = 1;
            f_060740(0x1f48, 1);
            f_060740(0x1f49, 1);
            s = menu493(PD(d_1c2c64), 0x2f00002c, 3, 0x2f00002e, 0x2f00002f, 0x2f000030);
        }
    } else {
        s = menu493(PD(d_1c2c64), 0x2f00002d, 3, 0x2f00002e, 0x2f00002f, 0x2f000030);
    }
    if (s == 1) {
        if (p2 == 1) {
            f_060800(0x2f0003, 0, 0);
            return;
        }
        f_060800(0x2f0005, 0, 0);
        return;
    }
    if (s == 2) {
        d_1c02a4 = 0;
        f_060740(0x1f48, 1);
        f_060740(0x1f49, 1);
        f_0bf730(PD(d_1c2c64), 0x2f000031);
        f_125ed0(PD(d_1c2c44), 1);
    }
}
#pragma inline_depth(0)
//@ f_1027e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Zeigt bei d_1c02a0 == 0 das Bild f_0606a0(0x2f0002, 3) samt 3-Wege-Auswahlmenü
 *   0x2f000021 (f_0bfa20) an: Option 1 ruft f_0fdbd0(p1) auf, Option 2 setzt d_1c02a0 = 2 und zeigt Text
 *   0x2f000026, Option 3 setzt d_1c02a0 = 3, zeigt Text 0x2f000027, schaltet 0x1f47 (f_060740) und ruft
 *   f_125ed0(&d_1c2c44, 5) auf.
 * - Eingaben / Rückgabe: p1 (int, Dungeon-Kontextzeiger). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02a0, nutzt d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Zentrale Begegnungsszene, die u. a. aus f_100f50 und f_101110 aufgerufen wird.
 === Ende Beschreibung === */
void f_1027e0(int p1)
{
  short menu493b(int,int,int,int,int,int,int,int);
#pragma aux menu493b "f_0bfa20" parm caller [] value [ax] modify exact [eax];

    int p;
    short result;

    if (EQI(d_1c02a0, 0)) {
        p = f_0606a0(0x2f0002, 3);
        do {
            result = menu493b(PD(d_1c2c64), p, 0, 0x2f000021, 3,
                              0x2f000022, 0x2f000023, 0x2f000024);
        } while (result == -1);

        switch ((short)result) {
        case 1:
            f_0fdbd0(p1);
            break;
        case 2:
            d_1c02a0 = 2;
            f_0bf730(PD(d_1c2c64), 0x2f000026);
            break;
        case 3:
            d_1c02a0 = 3;
            f_0bf730(PD(d_1c2c64), 0x2f000027);
            f_060740(0x1f47, 1);
            f_125ed0(PD(d_1c2c44), 5);
            break;
        }

        DELP(p, ((int)(((RivaRasterImage*)(p))->f_0fad20( 0))));
    }
}
//@ f_1028c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet ein dynamisch über p2 - 0x17a indiziertes 12-Byte-Beuteobjekt (f_046d10,
 *   Zeile 0x866), führt f_046de0 aus und gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: p1 (int, ungenutzt), p2 (short, Ereignis-ID ab 0x17a). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6860 für mark.
 * - Besonderheiten: Generischer Beute-Handler für fortlaufende Ereignis-IDs.
 === Ende Beschreibung === */
void f_1028c0(int p1, short p2)
{
    int p;
    NEWA(p, 0x866, (short)(p2 - 0x17a));
    f_046de0(p);
    DELP(p, f_046d90(p, 0));
}
//@ f_102910
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Durchläuft in einer Schleife alle Beuteobjekt-IDs von 0x1b bis 0x33, instanziiert
 *   jeweils temporär das 12-Byte-Objekt (f_046d10, Zeile 0x87b), ruft f_047120 und f_046eb0 zur
 *   Initialisierung/Markierung auf und gibt es wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6860 für mark.
 * - Besonderheiten: Initialisiert sämtliche Beutelager 0x1b..0x33 des Abschnitts auf einmal.
 === Ende Beschreibung === */
void f_102910(void)
{
    short k;
    int p;
    k = 0x1b;
    while (k <= 0x33) {
        NEWA(p, 0x87b, k);
        f_047120(p);
        k++;
        f_046eb0(p);
        DELP(p, f_046d90(p, 0));
    }
}
//@ f_102980
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Formatiert abhängig vom Vorzeichen von f_126430(&d_1c2c44) Koordinaten- und
 *   Statuswerte (f_126430, f_126450, f_126460) über f_0e93f0(&d_1c38b0, p1, ...) (Format-ID 0x8030077 bzw.
 *   0x8030053) in den Textpuffer p1.
 * - Eingaben / Rückgabe: p1 (int, Zeiger auf Ziel-Stringpuffer). Gibt p1 zurück.
 * - Wichtige Variablen & Daten: Nutzt d_1c2c44 und d_1c38b0.
 * - Besonderheiten: Hilfsfunktion für f_102a60 zum Aufbau einer Status-/Positionsbeschreibung.
 === Ende Beschreibung === */
int f_102980(int p1)
{
    struct OB ob;
    int p3;
    short t;
    if (p1 != 0) {
        CTOR(ob);
        if (f_126430(PD(d_1c2c44)) < 0) {
            t = f_126430(PD(d_1c2c44));
            *(short *)(ob.rest[0] + 2) = t + 6;
            *(short *)(ob.rest[0] + 4) = f_126460(PD(d_1c2c44));
            f_0e93f0(PD(d_1c38b0), p1, 0x8030077);
        } else {
            *(short *)(ob.rest[0] + 2) = f_126430(PD(d_1c2c44));
            *(short *)(ob.rest[0] + 4) = f_126460(PD(d_1c2c44));
            *(int *)(ob.c + 4) = f_126450(PD(d_1c2c44)) + 0x20000012;
            f_0e93f0(PD(d_1c38b0), p1, 0x8030053);
        }
        DTOR(ob);
    }
    return p1;
}
//@ f_102a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Baut in p1 einen Statusbericht auf: Ruft zuerst f_102980 auf, hängt d_1b834c an und
 *   durchläuft alle 7 Gruppenplätze (f_0de7d0); für jeden aktiven Helden (f_0d4a60 == 1) wird dessen Name
 *   (f_0422b0) bzw. bei niedrigem Attribut/Talent 0x26 (f_03ad80 <= 6) der Spezialtext d_1b8350 angehängt und
 *   d_1c02dc = 1 gesetzt.
 * - Eingaben / Rückgabe: p1 (char *, Ziel-Textpuffer). Gibt p1 zurück.
 * - Wichtige Variablen & Daten: Schreibt d_1c02dc, nutzt d_1c0004, d_1b834c, d_1b834e, d_1b8350.
 * - Besonderheiten: Erzeugt einen dynamischen Text über den Zustand der Gruppenmitglieder.
 === Ende Beschreibung === */
char *f_102a60(char *p1)
{
    int iVar3;
    int iVar5;
    short k;
    if (p1 != 0) {
        iVar3 = f_039420(d_1c0004, 0x26);
        f_102980((int)p1);
        strcat(p1, d_1b834c);
        for (k = 0; k < 7; k++) {
            iVar5 = f_0de7d0(d_1c0004, k);
            if (iVar5 != 0 && f_0d4a60(iVar5) == 1) {
                strcat(p1, d_1b834e);
                if (iVar5 == iVar3 && f_03ad80(iVar5, 0x26) <= 6) {
                    strcat(p1, d_1b8350);
                    d_1c02dc = 1;
                } else {
                    strcat(p1, f_0422b0((struct hero *)(iVar5)));
                }
            }
        }
    }
    return p1;
}
struct RGB3 {unsigned char r,g,b; RGB3();};
//@ f_102bb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Sichert die aktuelle 256-Farben-Palette in einen temporären RGB3[0x100]-Puffer
 *   (f_149eb4), spielt über f_135200 die Sequenz 0x1e01000d (sowie bei p1 != 0 eine zweite Sequenz über
 *   f_133fe0(&d_1c3498, p1)) ab und stellt anschließend Palette (f_099ef0) und Anzeigestatus (f_0d2f90,
 *   d_1bf4bc, d_1bf4be) wieder her.
 * - Eingaben / Rückgabe: p1 (int, optionale Zusatz-Animationskennung). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1bf4bc, d_1bf4be, nutzt d_1c3498 und d_1a6860.
 * - Besonderheiten: Kapselt das Abspielen einer Zwischensequenz inklusive Palettensicherung.
 === Ende Beschreibung === */
void f_102bb0(int p1)
{
    char *buf;
    short a;
    short b;

    buf=(char*)new (mark(d_1a6860,0x8f1)) RGB3[0x100];
    a = (*(volatile short *)&d_1bf4bc); // haelt die Befehlsfolge nach new wie im Original
    b = d_1bf4be;
    f_0d2f90(0, 1);
    f_149eb4(buf, 0, 0x100);
    if (!p1) {
        f_135200(0x1e01000d, 3, 0);
    } else {
        f_135200(0x1e01000d, 1, 0);
        f_135200(f_133fe0(PD(d_1c3498), p1), 2, 0);
    }
    f_0d2f90(a, 1);
    (d_1bf4be) = b;
    f_099ef0(buf, 0, 0x100);
    operator delete(buf);
}
//@ f_102c90
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft für den Helden p1 und den Inventarslot p2 (f_042a60), ob dort ein Gegenstand
 *   liegt (s > 0), der nicht in der Ausnahmeliste d_1a687e (f_149360(s, &d_1a687e) == -1) enthalten ist.
 * - Eingaben / Rückgabe: p1 (int, Heldenzeiger), p2 (short, Slot-Index). Gibt 1 zurück, wenn der Gegenstand
 *   betroffen/abnehmbar ist, sonst 0.
 * - Wichtige Variablen & Daten: Nutzt d_1a687e.
 * - Besonderheiten: Filter-/Prädikatfunktion für f_102cc0 (wird dort auch als Funktionszeiger an f_047570
 *   übergeben).
 === Ende Beschreibung === */
int f_102c90(int p1, short p2)
{
    short s;
    int r;
    s = f_042a60((struct hero *)(p1), p2);
    r = 0;
    if (s > 0) {
        s = f_149360(s, PD(d_1a687e));
        if (s == -1) {
            r = 1;
        }
    }
    return r;
}
//@ f_102cc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Transferiert bei einer Gefangennahme oder Ausrüstungsverlust die nicht geschützten
 *   Gegenstände aller 7 Helden (f_102c90, Slots 0..30) über f_047570 und f_035180 in das Beutelager 0x14
 *   (f_046d10), vergibt Ersatzkleidung (0x1b8, 0x1b9 über f_036a10) und überträgt 70 % des Gruppengeldes
 *   (f_0de7e0, maximal 0xfde8) über f_0db8b0 und f_047620 in das Lager.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1a6860 (Zeile 0x943).
 * - Besonderheiten: Komplette Ausrüstungs- und Geldsicherung der Heldengruppe in das Beuteobjekt 0x14.
 === Ende Beschreibung === */
int f_0de7d0(int p1, int p2);
int f_043e20(int p1, int p2);
int f_047570(int p1, int p2, int p3);
int f_035180(int p1, int p2);
int f_036a10(int p1, int p2, int p3, int p4, int p5);
int f_0de7e0(int p1);
int f_0db8b0(int p1, int p2);
int f_047620(int p1, int p2);
int f_047650(int p1, int p2);
int f_102c90(int p1, short p2);
void f_102cc0(void)
{
    int p;
    int iv;
    short k;
    short j;
    int v;

    NEWA(p, 0x943, 0x14)
    for (k = 0; k < 7; k++) {
        iv = f_0de7d0(d_1c0004, k);
        if (iv != 0) {
            f_047570(p, iv, (int)f_102c90);
            f_043e20(iv, 1);
            for (j = 0; j < 31; j++) {
                if (f_102c90(iv, j) == 1) {
                    f_035180(iv, j);
                }
            }
            f_036a10(iv, 0x1b8, 1, 9, 0);
            f_036a10(iv, 0x1b9, 1, 5, 0);
            f_043e20(iv, 0);
        }
    }
    v = f_0de7e0(d_1c0004) * 70 / 100;
    if (v > 0xfde8) {
        v = 0xfde8;
    }
    f_0db8b0(d_1c0004, v);
    f_047620(p, (unsigned short)v);
    f_047650(p, 0);
    DELP(p, f_046d90(p, 0))
}
