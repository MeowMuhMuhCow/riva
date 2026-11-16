/* === Beschreibung (Katalog) ===
 * Einheit use_t4 (0x1386A0 - 0x13A550)
 *
 * Überblick
 * Diese Einheit bildet den vierten Teil von use.cpp und umfasst ein breites Spektrum an Gegenstands-Handlern:
 * die direkte Benutzung von *Schreibzeug*, die 39 Adress-Thunk-Funktionen für die Handler-Tabelle, das
 * Verabreichen oder Einnehmen von Giften und Kampfsubstanzen, das Spielen von Musikinstrumenten (*Flöte*,
 * *Harfe*, *Laute*), die gesamte Lichtquellen-Verwaltung (*Fackel*, *Laterne*, *Öl*, *Zunderkästchen*) sowie das
 * Anbringen und Abnehmen von Schlüsseln am *Schlüsselbund*.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 55/58 gleich (suche.py 29.10.2026, Basis use_t4_P1.CPP)
// use.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x135040-0x13AA40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0458b0(int p1);                                   // reg eax stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068960();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_08ab50(int);                                      // reg eax stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a080(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce710(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10cba0(int p1, int p2);                           // reg eax edx stapel 0
int f_10cbc0(int p1, int p2);                           // reg - stapel 0
int f_10ce80();                       // nicht in clobber.tsv
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a68f4;                    // 0x1A68F4
extern short d_1a92d0;                  // 0x1A92D0
extern short d_1a92f4;                  // 0x1A92F4
extern short d_1a9316;                  // 0x1A9316
extern int d_1a935a;                    // 0x1A935A
extern int d_1a936c;                    // 0x1A936C
extern int d_1a9370;                    // 0x1A9370
extern int d_1a9374;                    // 0x1A9374
extern int d_1a9820;                    // 0x1A9820
extern short d_1bd90c;                    // 0x1BD90C
extern int d_1bf4bc;                    // 0x1BF4BC
extern int d_1bf4be;                    // 0x1BF4BE
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0420;                    // 0x1C0420
extern int d_1c042a;                    // 0x1C042A
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c0e7c;                    // 0x1C0E7C
extern int d_1c0e80;                    // 0x1C0E80
extern int d_1c0e84;                    // 0x1C0E84
extern int d_1c0e88;                    // 0x1C0E88
extern int d_1c2198;                    // 0x1C2198
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c259c;                    // 0x1C259C
extern short d_1c25fe;                  // 0x1C25FE
extern int d_1c2600;                    // 0x1C2600
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c3068;                    // 0x1C3068
extern int d_1c38b0;                    // 0x1C38B0
#pragma inline_depth(8)
#define PD(x) ((int)&(x))
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
extern short d_1a933c[];
extern short d_1a934a[];
extern short d_1c212a;
extern int *d_1c212c;
extern unsigned char d_1c106c;
extern short d_1c106d;
extern signed char d_1c1070;
extern short d_1c1071;
extern short d_1c1074;
extern short d_1c1075;

extern unsigned short d_1c2c64[];
extern char d_1c2edc[];
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern const char d_1a8e28[];
int f_125400(int,int,int);
int f_1254a0(int);
int f_1364f0(int,int); int f_135dc0(int,int,int,int); int f_135ef0(int,int,int,int); int f_1365d0(int,int); int f_136720(int,int);
int f_135d40(int); int f_136ed0(int,int); int f_136ea0(int,int); int f_136340(int,int,int); int f_136290(int,int,int);
int f_136210(int,int,int); int f_136250(int,int,int); int f_136140(int,int,int); int f_137180(int,int); int f_136fe0(int,int);
int f_13a550(int,int); int f_13a620(int); int f_13a8c0(int,int);
int f_0d4aa0(int,int); int f_0bf730(int,int); int f_036300(int,int,int); int f_036a10(int,int,int,int,int); int f_0bf820(void);
int f_038e90(int,int); int f_0d49b0(int); int f_040900(int,int); int f_145760(int,int);   int f_044230(int,int);
int f_044300(int,int); int f_044c90(int,int,int); int f_0d2f90(int,int); int f_147323(int,int,int,int,int,int,int); int f_0ce710(int,int,int,int);
int f_0d2e70(void);     
void f_0a7840(RivaItemDefinition *item,char *dst,short n); int f_133fe0(int,int); int f_08ab50(int);  int f_0c0020(int,int); int f_0458b0(int);
int f_03d8b0(int,int,int,int);   int f_0366e0(int,int,int,int); int f_0dcf00(int,int,int);
struct SO { char b[12]; int *p; char c[16]; short *q; char d[24];
  SO() { f_125400((int)this, (int)d_1c349c, (int)d_1c3870); }
  ~SO() { f_1254a0((int)this); } };
struct SP { short n; short *a; short *b; };
#define PRECHECK(ok, idx) \
  ok = 1; \
  { short sc_ = ((int)(f_042ac0((struct hero *)(p1[4]), (idx)))); \
    if (sc_ < 1 && *p1 != 0) { SO q_; sc_ = ((int)(f_042a60((struct hero *)(p1[4]), (idx)))); q_.p[1] = (*(int **)&d_1c2c40)[sc_]; q_.q[1] = 1; f_0bf730(PD(d_1c2c64), 0x1e010050); ok = 0; } }
#define TAILA(ta, tb, rr) \
  iVar4 = (short)(ta); f_042a90((struct hero *)(p1[4]), iVar4, 0xf9); f_0430c0((struct hero *)(p1[4]), iVar4, 100); \
  iVar4 = (short)(tb); f_036300(p1[4], iVar4, 1); f_036a10(p1[4], 0x2a, 1, iVar4, 0); rr = 0x1e010049; iVar4 = rr;

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_1386a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das direkte Benutzen von *Schreibzeug* (Slot p2) ohne zweiten Gegenstand: Es wird
 *   geprüft, welche Kombination aus *Rezeptbuch* (0xbf), *Notizbuch* (0x1dc) und leerem *Buch* (0x1d) der Held
 *   im Inventar trägt (fl = 0..7); besitzt er keines davon (fl == 0), erscheint 0x1e010088, besitzt er genau ein
 *   beschreibbares Buch (fl == 1 oder 2), wird direkt die Dokument- bzw. Rezeptauswahl geöffnet, und besitzt er
 *   mehrere Möglichkeiten (fl >= 3), fragt ein Menü (0x1e010087), ob er ein Rezept oder ein Dokument abschreiben
 *   möchte.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Inventarslot des Schreibzeugs (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: a, b (b2) und c speichern die gefundenen Inventarslots für *Rezeptbuch*, *Notizbuch* und
 *   leeres *Buch*; das Bitfeld fl kodiert deren Vorhandensein (1, 2, 4).
 === Ende Beschreibung === */
int f_125400(int,int,int,int);
int f_1254a0(int,int);
int f_0bf820(int,...);
static inline void put1386(int p1, int v, int k)
{
    int w = v;
    f_036300(I32(p1, 0x10), (short)v, 1);
    f_036a10(I32(p1, 0x10), k, 1, (short)w, 0);
}
void f_1386a0(int p1, short p2)
{
    short s2;
    int b2;
    short r;
    int a;
    p2 = f_1364f0(p1, p2);
    if (p2 != -1) {
        a = f_0d4aa0(I32(p1, 0x10), 0xbf);
        int b = f_0d4aa0(I32(p1, 0x10), 0x1dc);
        b2 = b;
        int c = f_0d4aa0(I32(p1, 0x10), 0x1d);
        struct O { int f0; int *p; char rest[52]; } o;
        f_125400((int)&o,(int)d_1c349c,(int)d_1c3870,(int)d_1c3498);
        o.p[1] = I32(p1, 0x10);
        unsigned char fl=0;
        if ((short)b != -1) fl=1;
        if ((short)a != -1) fl = fl | 2;
        if ((short)c != -1) fl = fl | 4;
        switch (fl) {
        case 0:
            f_0bf730(PD(d_1c2c64), 0x1e010088);
            f_1254a0((int)&o,0); return;
        case 1: {
            short iv = (short)b2;
            short r = f_1365d0(p1, iv);
            if ((short)r != -1) {
                if (iv == -1) {
                    put1386(p1, b2 = c, 0x1dc);
                }
                f_135ef0(p1, (short)b2, (short)r, p2);
                f_1254a0((int)&o,0); return;
            }
            break; }
        case 2: {
            short iv = (short)a;
            r = f_136720(p1, iv);
            if ((short)r != -1) {
                if (iv == -1) {
                    put1386(p1, a = c, 0xbf);
                }
                f_135dc0(p1, (short)a, p2, (short)r);
                f_1254a0((int)&o,0); return;
            }
            break; }
        case 3: case 4: case 5: case 6: case 7: {
            unsigned short u=f_0bf820(PD(d_1c2c64),0x1e010087,2,0x1e010085,0x1e010086);
            int v=-1;
            switch(u) {
            case 1:v=0xbf;break;
            case 2:v=0x1dc;break;
            }
            switch((unsigned short)v) {
            case 0xbf: {
                s2=(short)a != -1 ? a : c;
                int s5=f_136720(p1,s2);
                if((short)s5 != -1) {
                    f_135dc0(p1,s2,(short)p2,(short)s5);
                    f_1254a0((int)&o,0); return;
                }
                break;
            }
            case 0x1dc: {
                s2=(short)b2 != -1 ? b2 : c;
                short s5=f_1365d0(p1,s2);
                if(s5 != -1) {
                    f_135ef0(p1,s2,(short)s5,(short)p2);
                    f_1254a0((int)&o,0); return;
                }
                break;
            }
            }
            break; }
        }
        f_1254a0((int)&o,0);
    }
}

//@ f_138960
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert als Konstruktor eine Hilfsstruktur (p1) mit zwei dynamischen 16-Bit-Arrays (a
 *   für Inventarslots, b für Gegenstandskennungen) der Länge n.
 * - Eingaben: Ein Zeiger auf die Struktur (p1) sowie die gewünschte Arraygröße (n).
 * - Rückgabewert: Gibt den Zeiger auf die initialisierte Struktur (p1) zurück.
 * - Wichtige Variablen: Setzt den Zähler p1->n = 0 und reserviert Speicher für p1->a und p1->b.
 === Ende Beschreibung === */
SP *f_138960(SP *p1, short n)
{
    p1->n = 0;
    p1->a = new (mark(d_1a8e28, 0xc55)) short[n];
    p1->b = new (mark(d_1a8e28, 0xc56)) short[n];
    return p1;
}

//@ f_1389b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt als Destruktor die beiden dynamischen Arrays (p1->b und p1->a) der Hilfsstruktur wieder
 *   frei.
 * - Eingaben: Ein Zeiger auf die Struktur (p1) sowie ein ungenutzter Destruktor-Parameter.
 * - Rückgabewert: Gibt den Zeiger p1 zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
SP *f_1389b0(SP *p1, int p_unused1)
{
    delete p1->b;
    delete p1->a;
    return p1;
}

extern char d_13bb50[];
//@ f_1389d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese 39 kleinen Hilfsfunktionen (Compiler-Thunks für Memberfunktionszeiger) liefern jeweils
 *   die Code-Adresse eines der 39 Gegenstands-Handler (f_13bb50 abwärts bis f_134f90) zurück, wenn ein Handler
 *   über die Sprungtabelle d_1c0e8c in f_134d50 aufgerufen wird:
 *   - f_1389d0 (0x1389D0): Gibt die Adresse von f_13bb50 zurück.
 *   - f_1389e0 (0x1389E0): Gibt die Adresse von f_13bb30 zurück.
 *   - f_1389f0 (0x1389F0): Gibt die Adresse von f_13bb10 zurück.
 *   - f_138a00 (0x138A00): Gibt die Adresse von f_13baf0 zurück.
 *   - f_138a10 (0x138A10): Gibt die Adresse von f_13bad0 zurück.
 *   - f_138a20 (0x138A20): Gibt die Adresse von f_13bab0 zurück.
 *   - f_138a30 (0x138A30): Gibt die Adresse von f_13ba90 zurück.
 *   - f_138a40 (0x138A40): Gibt die Adresse von f_13ba70 zurück.
 *   - f_138a50 (0x138A50): Gibt die Adresse von f_13ba50 zurück.
 *   - f_138a60 (0x138A60): Gibt die Adresse von f_13b9b0 zurück.
 *   - f_138a70 (0x138A70): Gibt die Adresse von f_13b990 zurück.
 *   - f_138a80 (0x138A80): Gibt die Adresse von f_13b8f0 zurück.
 *   - f_138a90 (0x138A90): Gibt die Adresse von f_13b840 zurück.
 *   - f_138aa0 (0x138AA0): Gibt die Adresse von f_13b7b0 zurück.
 *   - f_138ab0 (0x138AB0): Gibt die Adresse von f_13b180 zurück.
 *   - f_138ac0 (0x138AC0): Gibt die Adresse von f_13aea0 zurück.
 *   - f_138ad0 (0x138AD0): Gibt die Adresse von f_13ae40 zurück.
 *   - f_138ae0 (0x138AE0): Gibt die Adresse von f_13adb0 zurück.
 *   - f_138af0 (0x138AF0): Gibt die Adresse von f_13ad00 zurück.
 *   - f_138b00 (0x138B00): Gibt die Adresse von f_13acf0 zurück.
 *   - f_138b10 (0x138B10): Gibt die Adresse von f_13abb0 zurück.
 *   - f_138b20 (0x138B20): Gibt die Adresse von f_13aa40 zurück.
 *   - f_138b30 (0x138B30): Gibt die Adresse von f_13a030 zurück.
 *   - f_138b40 (0x138B40): Gibt die Adresse von f_139f80 zurück.
 *   - f_138b50 (0x138B50): Gibt die Adresse von f_139f70 zurück.
 *   - f_138b60 (0x138B60): Gibt die Adresse von f_139e00 zurück.
 *   - f_138b70 (0x138B70): Gibt die Adresse von f_139da0 zurück.
 *   - f_138b80 (0x138B80): Gibt die Adresse von f_139020 zurück.
 *   - f_138b90 (0x138B90): Gibt die Adresse von f_138fe0 zurück.
 *   - f_138ba0 (0x138BA0): Gibt die Adresse von f_138e90 zurück.
 *   - f_138bb0 (0x138BB0): Gibt die Adresse von f_138c90 zurück.
 *   - f_138bc0 (0x138BC0): Gibt die Adresse von f_135920 zurück.
 *   - f_138bd0 (0x138BD0): Gibt die Adresse von f_135870 zurück.
 *   - f_138be0 (0x138BE0): Gibt die Adresse von f_135600 zurück.
 *   - f_138bf0 (0x138BF0): Gibt die Adresse von f_135590 zurück.
 *   - f_138c00 (0x138C00): Gibt die Adresse von f_1354d0 zurück.
 *   - f_138c10 (0x138C10): Gibt die Adresse von f_135040 zurück.
 *   - f_138c20 (0x138C20): Gibt die Adresse von f_135010 zurück.
 *   - f_138c30 (0x138C30): Gibt die Adresse von f_134f90 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_1389d0(void)
{
    return (int)d_13bb50;
}

extern char d_13bb30[];
//@ f_1389e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13bb30 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13bb30 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_1389e0(void)
{
    return (int)d_13bb30;
}

extern char d_13bb10[];
//@ f_1389f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13bb10 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13bb10 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_1389f0(void)
{
    return (int)d_13bb10;
}

extern char d_13baf0[];
//@ f_138a00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13baf0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13baf0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a00(void)
{
    return (int)d_13baf0;
}

extern char d_13bad0[];
//@ f_138a10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13bad0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13bad0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a10(void)
{
    return (int)d_13bad0;
}

extern char d_13bab0[];
//@ f_138a20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13bab0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13bab0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a20(void)
{
    return (int)d_13bab0;
}

extern char d_13ba90[];
//@ f_138a30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13ba90 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13ba90 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a30(void)
{
    return (int)d_13ba90;
}

extern char d_13ba70[];
//@ f_138a40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13ba70 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13ba70 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a40(void)
{
    return (int)d_13ba70;
}

extern char d_13ba50[];
//@ f_138a50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13ba50 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13ba50 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a50(void)
{
    return (int)d_13ba50;
}

extern char d_13b9b0[];
//@ f_138a60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b9b0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b9b0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a60(void)
{
    return (int)d_13b9b0;
}

extern char d_13b990[];
//@ f_138a70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b990 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b990 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a70(void)
{
    return (int)d_13b990;
}

extern char d_13b8f0[];
//@ f_138a80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b8f0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b8f0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a80(void)
{
    return (int)d_13b8f0;
}

extern char d_13b840[];
//@ f_138a90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b840 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b840 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138a90(void)
{
    return (int)d_13b840;
}

extern char d_13b7b0[];
//@ f_138aa0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b7b0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b7b0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138aa0(void)
{
    return (int)d_13b7b0;
}

extern char d_13b180[];
//@ f_138ab0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13b180 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13b180 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138ab0(void)
{
    return (int)d_13b180;
}

extern char d_13aea0[];
//@ f_138ac0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13aea0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13aea0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138ac0(void)
{
    return (int)d_13aea0;
}

extern char d_13ae40[];
//@ f_138ad0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13ae40 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13ae40 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138ad0(void)
{
    return (int)d_13ae40;
}

extern char d_13adb0[];
//@ f_138ae0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13adb0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13adb0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138ae0(void)
{
    return (int)d_13adb0;
}

extern char d_13ad00[];
//@ f_138af0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13ad00 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13ad00 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138af0(void)
{
    return (int)d_13ad00;
}

extern char d_0646b0[];
extern char d_13acf0[];
//@ f_138b00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13acf0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13acf0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b00(void)
{
    return (int)d_13acf0;
}

extern char d_13abb0[];
//@ f_138b10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13abb0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13abb0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b10(void)
{
    return (int)d_13abb0;
}

extern char d_13aa40[];
//@ f_138b20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13aa40 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13aa40 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b20(void)
{
    return (int)d_13aa40;
}

extern char d_13a030[];
//@ f_138b30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_13a030 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_13a030 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b30(void)
{
    return (int)d_13a030;
}

extern char d_139f80[];
//@ f_138b40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_139f80 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_139f80 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b40(void)
{
    return (int)d_139f80;
}

extern char d_139f70[];
//@ f_138b50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_139f70 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_139f70 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b50(void)
{
    return (int)d_139f70;
}

extern char d_139e00[];
//@ f_138b60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_139e00 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_139e00 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b60(void)
{
    return (int)d_139e00;
}

extern char d_139da0[];
//@ f_138b70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_139da0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_139da0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b70(void)
{
    return (int)d_139da0;
}

extern char d_139020[];
//@ f_138b80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_139020 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_139020 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b80(void)
{
    return (int)d_139020;
}

extern char d_138fe0[];
//@ f_138b90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_138fe0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_138fe0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138b90(void)
{
    return (int)d_138fe0;
}

extern char d_138e90[];
//@ f_138ba0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_138e90 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_138e90 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138ba0(void)
{
    return (int)d_138e90;
}

extern char d_138c90[];
//@ f_138bb0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_138c90 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_138c90 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138bb0(void)
{
    return (int)d_138c90;
}

extern char d_135920[];
//@ f_138bc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135920 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135920 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138bc0(void)
{
    return (int)d_135920;
}

extern char d_135870[];
//@ f_138bd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135870 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135870 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138bd0(void)
{
    return (int)d_135870;
}

extern char d_135600[];
//@ f_138be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135600 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135600 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138be0(void)
{
    return (int)d_135600;
}

extern char d_135590[];
//@ f_138bf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135590 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135590 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138bf0(void)
{
    return (int)d_135590;
}

extern char d_1354d0[];
//@ f_138c00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_1354d0 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_1354d0 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138c00(void)
{
    return (int)d_1354d0;
}

extern char d_135040[];
//@ f_138c10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135040 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135040 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138c10(void)
{
    return (int)d_135040;
}

extern char d_135010[];
//@ f_138c20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_135010 zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_135010 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138c20(void)
{
    return (int)d_135010;
}

extern char d_134f90[];
//@ f_138c30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert als Adress-Thunk für die Sprungtabelle d_1c0e8c die Code-Adresse des
 *   Gegenstands-Handlers f_134f90 (d_134f90) zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die Funktionsadresse von f_134f90 als 32-Bit-Wert zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_138c30(void)
{
    return (int)d_134f90;
}

int f_138c40(void)
{
    return 0;
}

//@ f_138c50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Registriert beim Programmstart das persistente Statusflag d_1c106c (Kennung 0x10f) in der
 *   globalen Speicherstand-Liste (d_1c212a/d_1c212c).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Setzt den Anfangswert d_1c106c = 0 und die Kennung d_1c106d = 0x10f.
 === Ende Beschreibung === */
struct Reg138;
struct Obj138 { signed char a; short b; Obj138 *init(Reg138 &r, short id, signed char f); };
struct Reg138 { short count; Obj138 **list; };
inline Obj138 *Obj138::init(Reg138 &r, short id, signed char f) { a = f; b = id; r.list[r.count] = this; ++r.count; return this; }
extern Obj138 ob138_6c;
extern Reg138 reg138;
#pragma aux ob138_6c "d_1c106c"
#pragma aux reg138 "d_1c212a"
void f_138c50(void)
{
    ob138_6c.init(reg138, 0x10f, 0);
}

//@ f_138c90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als neunter Gegenstands-Handler (Index 9 in d_1c0e8c) das Anwenden
 *   gefährlicher alchemistischer Substanzen außerhalb des Kampfes (!d_1bd90c) auf einen ausgewählten Helden (h,
 *   Auswahl über 0x1e0100ae): *Goldleim* (0x3b) vergiftet mit Gift 5, verursacht 1-20 Schadenspunkte und
 *   hinterlässt eine *Glasflasche* (0x1f); *Lotosgift* (0x8d) vergiftet mit Gift 7 und richtet 10-40 Schaden an;
 *   *Bannstaub* (0x8f) entzieht einem Magier 10-20 Astralpunkte (f_044230); *Hylailer Feuer* (0xef) und
 *   *Miasthmaticum* (0xee) verursachen 10-25 bzw. 5-10 Schadenspunkte (f_044300).
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: h ist der ausgewählte Zielheld, r der ausgewürfelte Lebenspunkteschaden und sc die
 *   gegebenenfalls zurückbleibende leere Flasche (0x1f).
 === Ende Beschreibung === */
int f_125400(int,int,int,int);
int f_1254a0(int,int);
void f_138c90(int p1)
{
    struct O {
        int f0;
        int *p;
        char rest[52];
    } o;
    f_125400((int)&o, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
    short r = 0;
    int msg;
    if (!d_1bd90c) {
        int h = f_038e90(d_1c0004, 0x1e0100ae);
        short sc = 0;
        if (h != 0) {
            o.p[1] = h;
            if (f_0d49b0(h) != 0) {
                switch (U16(p1,0x1a)) {
                case 0x3b:
                    f_040900(h,5);
                    sc=0x1f;
                    msg=0x1e0100af;
                    r=f_145760(1,0x14);
                    break;
                case 0x8d:
                    f_040900(h,7);
                    msg=0x1e0100b0;
                    r=f_145760(10,0x28);
                    break;
                case 0x8f:
                    if (f_042a10((struct hero *)(h)) && (short)((int)(f_0429a0((struct hero *)(h))))>0) {
                        int s=f_145760(10,0x14);
                        msg=0x1e0100b1;
                        f_044230(h,(short)s);
                    } else msg=0x1e0100b2;
                    break;
                case 0xef:
                    msg=0x1e0100a0;
                    r=f_145760(10,0x19);
                    break;
                case 0xee:
                    msg=0x1e0100b3;
                    r=f_145760(5,10);
                    break;
                }
                f_036300(I32(p1, 0x10), S16(p1, 0x18), 1);
                if (sc != (short)0) f_036a10(I32(p1, 0x10), sc, 1, S16(p1, 0x18), 0);
                f_0bf730(PD(d_1c2c64), msg);
                if ((short)r != 0) {
                    f_044300(h, (short)r);
                    f_1254a0((int)&o,0);
                    return;
                }
            } else {
                f_0bf730(PD(d_1c2c64), 0x1e0100a1);
            }
        }
    }
    f_1254a0((int)&o,0);
}

//@ f_138e90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als zehnter Gegenstands-Handler (Index 10 in d_1c0e8c) das Musizieren mit
 *   einer *Flöte* (0x2e), einer *Harfe* (0x25), einer *Laute* (0x5f) sowie den beiden elfischen Instrumenten
 *   *Harfe \<Vardari\>* (0x160) und *Laute \<Vardari\>* (0x161): Der Held legt eine Probe auf das Talent
 *   *Musizieren* (0x2f) ab (bei den Vardari-Instrumenten um -5 erleichtert!), und je nachdem, ob die Probe
 *   gelingt oder misslingt, wird eine gelungene oder schiefe Melodie (0x30005/0x30006 für Flöte, 0x30007/0x30008
 *   für Harfe, 0x30009/0x3000a für Laute) über das Soundsystem abgespielt.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: s enthält die berechnete Soundkennung (Basiswert + 0 bei gelungener Probe > 0, Basiswert
 *   + 1 bei misslungener Probe <= 0).
 === Ende Beschreibung === */
void f_138e90(int p1)
{
    int s = 0;
    switch ((unsigned short)U16(p1, 0x1a)) {
    case 0x2e:
        s = ((short)f_044c90(I32(p1, 0x10), 0x2f, 0) <= 0) + 0x30005;
        break;
    case 0x25:
        s = ((short)f_044c90(I32(p1, 0x10), 0x2f, 0) <= 0) + 0x30007;
        break;
    case 0x160:
        s = ((short)f_044c90(I32(p1, 0x10), 0x2f, -5) <= 0) + 0x30007;
        break;
    case 0x5f: {
        unsigned char c = ((short)f_044c90(I32(p1, 0x10), 0x2f, 0) <= 0);
        s = c + 0x30009;
        break;
    }
    case 0x161:
        s = ((short)f_044c90(I32(p1, 0x10), 0x2f, -5) <= 0) + 0x30009;
        break;
    }
    if (s != 0) {
        int snd;
        f_0d2f90(5, 1);
        snd = d_1a9820;
        f_147323((int)d_1c2edc, s, 0x7fff, 0x8000, snd, 0, 1);
        f_0ce710(s);
        f_0d2e70();
    }
}
//@ f_138fe0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert den elften Gegenstands-Handler (Index 11 in d_1c0e8c), der beim Benutzen eines
 *   speziellen Gegenstands die Meldung 0x1e01006c ausgibt, beim Helden den Statuswert 0x15 um 2 verändert
 *   (f_043110) und den Gegenstand aus dem Inventar entfernt.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_138fe0(int p1)
{
    f_0bf730(PD(d_1c2c64), 0x1e01006c);
    f_043110((struct hero *)(I32(p1, 0x10)), 0x15, 2);
    f_036300(I32(p1, 0x10), S16(p1, 0x18), 1);
}

//@ f_139020
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als zwölfter Gegenstands-Handler (Index 12 in d_1c0e8c) die gesamte Logik für
 *   Lichtquellen und Zündmittel (*unangezündete Fackel* 0x41, *brennende Fackel* 0x16, *unangezündete Laterne*
 *   0x19, *brennende Laterne* 0xf9, *Öl* 0x29 und *Zunderkästchen* 0x55): Je nachdem, ob der Spieler einen
 *   Gegenstand einzeln benutzt oder zwei davon kombiniert, prüft die Funktion das Vorhandensein der benötigten
 *   Zusatzgegenstände im Inventar des Helden (p1[4]), fragt bei Benutzung des Zunderkästchens (0x55), falls
 *   sowohl Fackel als auch Laterne vorhanden sind, über ein Auswahlmenü (0x1e010047), welche Lichtquelle
 *   entzündet werden soll, wandelt unangezündete Fackeln in brennende Fackeln (0x16, Brenndauer 10) bzw.
 *   Laternen unter Verbrauch von *Öl* (0x29 -> *Bronzeflasche* 0x2a) in brennende Laternen (0xf9, Brenndauer
 *   100) um oder füllt eine bereits brennende Laterne (0xf9) wieder auf Brenndauer 100 auf.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: a41, a19, af9, a55 und a29 speichern die im Heldeninventar gefundenen Slots für
 *   unangezündete Fackel, unangezündete Laterne, brennende Laterne, Zunderkästchen und Öl; result enthält die
 *   auszugebende Erfolgs- oder Fehlermeldung (0x1e010048 bis 0x1e01004d).
 === Ende Beschreibung === */
short quantity139(int,int);
#pragma aux quantity139 "f_042ac0"
short item139(int,int);
#pragma aux item139 "f_042a60"

short select139(...);
#pragma aux select139 "f_0bf820"
short find139(int,short);
#pragma aux find139 "f_0d4aa0"
struct Obj { int f0; char *p[13]; short s38; Obj(void *,void *,void *); ~Obj(); };
struct ItemUse139 { int verbose; int pad[3]; int user;
inline int check139(short ix) {
    int accepted = 1;
    if (quantity139(user, ix) <= 0 && verbose != 0) {
        Obj q(d_1c349c,d_1c3870,d_1c3498);
        *(int *)(q.p[2]+4) = (*(int **)&d_1c2c40)[item139(user, ix)];
        *(short *)(q.p[7]+2) = 1;
        f_0bf730(PD(d_1c2c64), 0x1e010050);
        accepted = 0;
    }
    return accepted;
}
inline int light139(short lamp, short oil, short ix) {
    int r = 0;
    if (check139(ix) == 1) {
        f_042a90((struct hero *)(user), lamp, 0xf9);
        f_0430c0((struct hero *)(user), lamp, 100);
        f_036300(user, oil, 1);
        f_036a10(user, 0x2a, 1, oil, 0);
        r = 0x1e010049;
    }
    return r;
}
inline int torch139(short t) {
    int r = 0;
    if (check139(t) == 1) {
        f_042a90((struct hero *)(user), t, 0x16);
        f_0430c0((struct hero *)(user), t, 10);
        r = 0x1e010048;
    }
    return r;
}
inline int refill139(short lamp, short oil) {
    f_0430c0((struct hero *)(user), lamp, 100);
    f_036300(user, oil, 1);
    f_036a10(user, 0x2a, 1, oil, 0);
    return 0x1e01004d;
}
};
void f_139020(int *p1)
{
    short answer = -1, a41, a19, af9, a55, a29;
    int result;

    a41 = find139(p1[4], 0x41);
    a19 = find139(p1[4], 0x19);
    af9 = find139(p1[4], 0xf9);
    a55 = find139(p1[4], 0x55);
    a29 = find139(p1[4], 0x29);
    result = 0;
    Obj o(d_1c349c,d_1c3870,d_1c3498);
    *(int *)(o.p[0]+4) = p1[4];

    if (((short *)p1)[15] != -1) {
        if ((((short *)p1)[13] == 0xf9 && ((short *)p1)[15] == 0x29) ||
            (((short *)p1)[13] == 0x29 && ((short *)p1)[15] == 0xf9)) {
            result = ((ItemUse139 *)p1)->refill139(af9, a29);
        } else if ((((short *)p1)[13] == 0x19 && ((short *)p1)[15] == 0x29) ||
                   (((short *)p1)[13] == 0x29 && ((short *)p1)[15] == 0x19) ||
                   (((short *)p1)[13] == 0x55 && ((short *)p1)[15] == 0x29) ||
                   (((short *)p1)[13] == 0x29 && ((short *)p1)[15] == 0x55) ||
                   (((short *)p1)[13] == 0x55 && ((short *)p1)[15] == 0x19) ||
                   (((short *)p1)[13] == 0x19 && ((short *)p1)[15] == 0x55)) {
            if (a29 == -1) result = 0x1e01004a;
            else if (a19 == -1) result = 0x1e01004b;
            else if (a55 == -1) result = 0x1e01004c;
            else result = ((ItemUse139 *)p1)->light139(a19, a29, a55);
        } else if ((((short *)p1)[13] == 0x55 && ((short *)p1)[15] == 0x41) ||
                   (((short *)p1)[13] == 0x41 && ((short *)p1)[15] == 0x55)) {
            f_042a90((struct hero *)(p1[4]), a41, 0x16);
            f_0430c0((struct hero *)(p1[4]), a41, 10);
            result = 0x1e010048;
            
        }
    } else if (((short *)p1)[13] == 0xf9) {
        if (a29 == -1) result = 0x1e01004a;
        else result = ((ItemUse139 *)p1)->refill139(af9, a29);
    } else if (((short *)p1)[13] == 0x19) {
        if (a29 == -1) result = 0x1e01004a;
        else if (a55 == -1) result = 0x1e01004c;
        else result = ((ItemUse139 *)p1)->light139(a19, a29, a55);
    } else if (((short *)p1)[13] == 0x29) {
        if (a19 == -1 && af9 == -1) result = 0x1e01004b;
        else if (af9 == -1 && a55 == -1) result = 0x1e01004c;
        else if (a19 != -1) result = ((ItemUse139 *)p1)->light139(a19, a29, a55);
        else if (af9 != -1) {
            result = ((ItemUse139 *)p1)->refill139(af9, a29);
        }
    } else if (((short *)p1)[13] == 0x55) {
        if (a19 == -1 && a41 == -1) result = 0x1e01004b;
        else if (a19 != -1 && a41 != -1) {
            f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[65]),(char *)( PD(d_1c21b4)), 1);
            f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[25]),(char *)( PD(d_1c27a8)), 1);
            answer = select139(PD(d_1c2c64), 0x1e010047, 2,
                f_133fe0(PD(d_1c3498), PD(d_1c21b4)),
                f_133fe0(PD(d_1c3498), PD(d_1c27a8)));
            if (answer == 1) a19 = -1;
            else if (answer == 2) a41 = -1;
            else a41 = a19 = -1;
        }
        if (a41 != -1) result = ((ItemUse139 *)p1)->torch139(a41);
        else if (a19 != -1) {
            if (a29 == -1) result = 0x1e01004a;
            else result = ((ItemUse139 *)p1)->light139(a19, a29, a55);
        }
    } else if (((short *)p1)[13] == 0x41) {
        if (a55 == -1) result = 0x1e01004c;
        else result = ((ItemUse139 *)p1)->torch139(((short *)p1)[12]);
    }
DONE:
    if (result != 0) f_0bf730(PD(d_1c2c64), result);
}

//@ f_139b10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Füllt als Hilfsfunktion von f_139020 eine Laterne in Slot p2 auf die maximale Brenndauer 100
 *   (f_0430c0) auf und ersetzt das verbrauchte *Öl* in Slot p3 durch eine leere *Bronzeflasche* (0x2a).
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Laternenslot (p2) und der Ölslot (p3).
 * - Rückgabewert: Gibt die Meldungskennung 0x1e01004d zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_139b10(int p1, short p2, short p3)
{
    f_0430c0((struct hero *)(I32(p1, 0x10)), p2, 100);
    f_036300(I32(p1, 0x10), p3, 1);
    f_036a10(I32(p1, 0x10), 0x2a, 1, p3, 0);
    return 0x1e01004d;
}

//@ f_139b60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Entzündet als Hilfsfunktion von f_139020 eine unangezündete Laterne (0x19 in Slot p2),
 *   sofern das *Zunderkästchen* in Slot p4 noch Ladungen besitzt (f_042ac0 > 0): Die Laterne wird in eine
 *   brennende Laterne (0xf9, Brenndauer 100) umgewandelt und das *Öl* in Slot p3 durch eine *Bronzeflasche*
 *   (0x2a) ersetzt.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Laternenslot (p2), der Ölslot (p3) und der
 *   Zunderkästchen-Slot (p4).
 * - Rückgabewert: Gibt bei Erfolg die Meldungskennung 0x1e010049 zurück, bei leerem Zunderkästchen 0.
 * - Wichtige Variablen: sc prüft die Ladungszahl in Slot p4, ok steuert die Ausführung.
 === Ende Beschreibung === */
int f_139b60(int *p1, int p2, short p3, short p4)
{
    int ok = 1;
    short sc = ((int)(f_042ac0((struct hero *)(p1[4]), p4)));
    int r = 0;
    if (sc <= 0 && *p1 != 0) {
        struct { char b[12]; int *p; char c[16]; short *q; char d[24]; } q;
        f_125400((int)&q, PD(d_1c349c), PD(d_1c3870), PD(d_1c3498));
        sc = ((int)(f_042a60((struct hero *)(p1[4]), p4)));
        q.p[1] = (*(int **)&d_1c2c40)[sc];
        q.q[1] = 1;
        f_0bf730(PD(d_1c2c64), 0x1e010050);
        f_1254a0((int)&q, 0);
        ok = 0;
    }
    if (ok == 1) {
        f_042a90((struct hero *)(p1[4]), (short)p2, 0xf9);
        f_0430c0((struct hero *)(p1[4]), (short)p2, 100);
        f_036300(p1[4], p3, 1);
        f_036a10(p1[4], 0x2a, 1, p3, 0);
        r = 0x1e010049;
    }
    return r;
}

//@ f_139c50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob der Gegenstand im Inventarslot p2 (z. B. Zunderkästchen oder Fackel) noch
 *   mindestens eine Ladung besitzt (f_042ac0 > 0), und gibt andernfalls die Verbrauchsmeldung 0x1e010050 aus.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der zu prüfende Inventarslot (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn noch mindestens eine Ladung vorhanden ist, sonst 0.
 * - Wichtige Variablen: sc speichert die abgefragte Ladungszahl.
 === Ende Beschreibung === */
int f_139c50(int *p1, short p2)
{
    int ok = 1;
    short sc = ((int)(f_042ac0((struct hero *)(p1[4]), p2)));
    if (sc <= 0 && *p1 != 0) {
        struct { char b[12]; int *p; char c[16]; short *q; char d[24]; } q;
        f_125400((int)&q, PD(d_1c349c), PD(d_1c3870), PD(d_1c3498));
        sc = ((int)(f_042a60((struct hero *)(p1[4]), p2)));
        q.p[1] = (*(int **)&d_1c2c40)[sc];
        q.q[1] = 1;
        f_0bf730(PD(d_1c2c64), 0x1e010050);
        f_1254a0((int)&q, 0);
        ok = 0;
    }
    return ok;
}
//@ f_139ce0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Entzündet eine unangezündete *Fackel* (0x41) in Slot p2, indem sie nach erfolgreicher
 *   Ladungsprüfung in eine brennende *Fackel* (0x16) mit der Brenndauer 10 umgewandelt wird.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Fackelslot (p2).
 * - Rückgabewert: Gibt bei Erfolg die Textkennung 0x1e010048 zurück, sonst 0.
 * - Wichtige Variablen: sc enthält die Ladungszahl, ok das Prüfergebnis.
 === Ende Beschreibung === */
int f_139ce0(int *p1, short p2)
{
    int ok = 1;
    int r = 0;
    int sc = (short)((int)(f_042ac0((struct hero *)(p1[4]), p2)));
    if (sc <= 0 && *p1 != 0) {
        struct { char b[12]; int *p; char c[16]; short *q; char d[24]; } q;
        f_125400((int)&q, PD(d_1c349c), PD(d_1c3870), PD(d_1c3498));
        sc = (short)((int)(f_042a60((struct hero *)(p1[4]), p2)));
        q.p[1] = (*(int **)&d_1c2c40)[sc];
        q.q[1] = 1;
        f_0bf730(PD(d_1c2c64), 0x1e010050);
        f_1254a0((int)&q, 0);
        ok = 0;
    }
    if (ok == 1) {
        f_042a90((struct hero *)(p1[4]), p2, 0x16);
        r = 0x1e010048;
        f_0430c0((struct hero *)(p1[4]), p2, 10);
    }
    return r;
}

//@ f_139da0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert den dreizehnten Gegenstands-Handler (Index 13 in d_1c0e8c), der bei erfüllter
 *   Ortsbedingung (d_1bd90c != 0) die Spezialfunktion f_08ab50(d_1bd914) aufruft, eine Ladung des Gegenstands
 *   abzieht und den erzeugten Text ausgibt, oder andernfalls 0x1e01006b anzeigt.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft das globale Ortsflag d_1bd90c.
 === Ende Beschreibung === */
void f_139da0(int p1)
{
    extern int d_1bd914;
    if (d_1bd90c != (short)0) {
        f_08ab50(d_1bd914);
        f_042b20((struct hero *)(I32(p1, 0x10)), S16(p1, 0x18), -1);
        f_0bf730(PD(d_1c2c64), f_133fe0(PD(d_1c3498), PD(d_1c21b4)));
    } else {
        f_0bf730(PD(d_1c2c64), 0x1e01006b);
    }
}

//@ f_139e00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als vierzehnter Gegenstands-Handler (Index 14 in d_1c0e8c) den zentralen
 *   Verteiler für das Lesen und Beschreiben von Büchern: Bei Einzelbenutzung (S16(p1, 0x1e) == -1) verzweigt er
 *   je nach Gegenstand zu f_1386a0 (*Schreibzeug* 0x24), f_137180 (*Rezeptbuch* 0xbf), f_136fe0 (*Notizbuch*
 *   0x1dc) oder meldet bei einem leeren *Buch* (0x1d) 0x1e010089. Bei Kombination von *Schreibzeug* (0x24) mit
 *   einem Rezept, Dokument oder Buch ruft er die entsprechende Schreibroutine (f_136340, f_136290, f_136210,
 *   f_136250 oder f_136140) auf.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: v hält die Gegenstandskennung des zweiten Gegenstands nach eventueller Normierung durch
 *   f_135d40.
 === Ende Beschreibung === */
void f_139e00(int p1)
{
    if (S16(p1, 0x1e) == -1) {
        switch (U16(p1, 0x1a)) {
        case 0x24: f_1386a0(p1, S16(p1, 0x18)); break;
        case 0xbf: f_137180(p1, S16(p1, 0x18)); break;
        case 0x1dc: f_136fe0(p1, S16(p1, 0x18)); break;
        case 0x1d: {
            struct { int x; int *p; char rest[52]; } o;
            f_125400((int)&o, PD(d_1c349c), PD(d_1c3870), PD(d_1c3498));
            o.p[1] = I32(p1, 0x10);
            f_0bf730(PD(d_1c2c64), 0x1e010089);
            f_1254a0((int)&o, 0);
            break;
        }
        }
    } else {
        if (S16(p1, 0x1e) == 0x24) f_135d40(p1);
        if (f_136ed0(p1, S16(p1, 0x1e)) != 0) {
            f_136340(p1, S16(p1, 0x18), S16(p1, 0x1c));
            return;
        }
        if (f_136ea0(p1, S16(p1, 0x1e)) != 0) {
            f_136290(p1, S16(p1, 0x18), S16(p1, 0x1c));
            return;
        }
        int v = S16(p1, 0x1e);
        if (v == 0xbf) {
            f_136210(p1, S16(p1, 0x18), S16(p1, 0x1c));
            return;
        }
        if (v == 0x1dc) {
            f_136250(p1, S16(p1, 0x18), S16(p1, 0x1c));
            return;
        }
        if (v == 0x1d) {
            f_136140(p1, S16(p1, 0x18), S16(p1, 0x1c));
        }
    }
    
}

//@ f_139f70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leerer Platzhalter-Handler (Index 15 in d_1c0e8c).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine Variablen.
 === Ende Beschreibung === */
void f_139f70(void)
{
}

//@ f_139f80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert den sechzehnten Gegenstands-Handler (Index 16 in d_1c0e8c), der unter
 *   vorübergehender Umschaltung des Dialogmodus (f_0c0020(..., 7)) die Meldung 0x1e0100a4 ausgibt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: s sichert den vorherigen Dialogmodus zur anschließenden Wiederherstellung.
 === Ende Beschreibung === */
void f_139f80(void)
{
    short s = f_0c0020(PD(d_1c2c64), 7);
    f_0bf730(PD(d_1c2c64), 0x1e0100a4);
    f_0c0020(PD(d_1c2c64), s);
}

//@ f_139fc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Registriert beim Programmstart die beiden persistenten Statusflags d_1c1070 (Kennung 0x87)
 *   und d_1c1074 (Kennung 0x1c8) in der globalen Speicherstand-Liste (d_1c212a/d_1c212c).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Initialisiert die beiden Flag-Werte mit 0.
 === Ende Beschreibung === */
void f_139fc0(void)
{
    struct Obj { signed char a; short b; };
    struct Reg { short count; Obj **list; };
    Obj &a = *(Obj *)&d_1c1070;
    Obj &b = *(Obj *)&d_1c1074;
    Reg &r = *(Reg *)&d_1c212a;
    signed char c = 0;
    a.a = c;
    a.b = 0x87;
    int i = r.count;
    ((Obj ** &)d_1c212c)[i] = &a;
    signed char z = 0;
    b.a = z;
    b.b = 0x1c8;
    r.count++;
    ((Obj ** &)r.list)[r.count] = &b;
    r.count++;
}

struct ItemAccess907 {
 static short weight(short id) { return ((int)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810())); }
 static short index(short id) {short k=0;while(id!=d_1a933c[k])++k;return k;}
};
//@ f_13a030
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als siebzehnter Gegenstands-Handler (Index 17 in d_1c0e8c) die Verwaltung des
 *   *Schlüsselbunds* (0x145 sowie dessen gefüllte Varianten 0x19d-0x1a1, 0x1cf, 0x1d0 in d_1a934a) und der
 *   sieben anschließbaren Einzelschlüssel (d_1a933c): Wird der Schlüsselbund einzeln benutzt (f1e == -1), kann
 *   der Spieler einen bereits angehängten Schlüssel wieder abnehmen (f_13a550 -> swap) oder, falls der Bund noch
 *   leer ist, einen passenden Schlüssel aus dem Inventar anhängen (f_13a620 -> putB). Wird ein einzelner
 *   Schlüssel benutzt oder mit dem Schlüsselbund kombiniert, wird er an den Bund gehängt, sein Gewicht
 *   (f_0a7810) zum Schlüsselbund addiert (f_043190) und das Icon des Schlüsselbunds entsprechend der neuen
 *   Schlüsselanzahl über f_13a8c0 angepasst.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (this / p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: f10 ist der handelnde Held, f18/f1a und f1c/f1e sind die Slots und Kennungen von
 *   Schlüsselbund und Schlüssel, und s speichert den im Auswahlmenü gewählten Schlüssel bzw. Slot.
 === Ende Beschreibung === */
void *ctxCtorK20(void *, const char *, const char *, const char *);
#pragma aux ctxCtorK20 "f_125400"
struct Ctx1 {
    int r0; char *a4; char rest[52];
    __pragma("ctxCtorK20") Ctx1(const char *, const char *, const char *);

};

inline int in_4a(short id)
{
    int r = 0;
    for (short i = 0; i < 8; i++) {
        if (id == d_1a934a[i]) { r = 1; break; }
    }
    return r;
}

inline int hasA(short idA){int rA=0;for(short iA=0;;iA++){int jA=iA;if(jA>=8)break;if(idA==d_1a934a[jA]){rA=jA;rA=jA;rA=jA;rA=jA;rA=1;break;}}return rA;}
inline int hasD(short idD){int rD=0;for(short iD=0;;iD++){int jD=iD;if(jD>=8)break;if(idD==d_1a934a[jD]){rD=jD;rD=jD;rD=jD;rD=1;break;}}return rD;}
inline int hasE(short idE){int rE=0;for(short iE=0;;iE++){int jE=iE;if(jE>=8)break;if(idE==d_1a934a[jE]){rE=jE;rE=jE;rE=jE;rE=1;break;}}return rE;}
inline int in_3c(short id)
{
    int r = 0;
    for (short i = 0; i < (short)7; i++) {
        if (id == d_1a933c[i]) { r = 1; break; }
    }
    return r;
}

struct Use1 {
    int r0, r4, r8, rc;
    int f10;
    int r14;
    short f18, f1a, f1c, f1e;
    void f_13a030();
    short f_13a550(short);
    short f_13a620();
    void f_13a8c0(short);
    short index(short k);
    short take();
    void put(short a, short b);
    void putB(short a,short b);
    void putC(short a,short b);
    void putD(short a,short b);
    void putE(short a,short b);
    void swap(short a, short b);
};

void Use1::f_13a030()
{
    Ctx1 o(d_1c349c, d_1c3870, d_1c3498);
    if (f1e == -1) {
        if (hasA(f1a)) {
            short s = f_13a550(f18);
            if (s != -1) {
                swap(f18, s);
            } else {
                s = f_13a620();
                if (s != -1) {
                    putB(f18, s);
                } else {
                    Ctx1 o2(d_1c349c, d_1c3870, d_1c3498);
                    *(int *)(o2.a4 + 4) = f10;
                    f_0bf730(PD(d_1c2c64), 0x1e0100c4);
                    f_1254a0((int)&o2,0);
                }
            }
        } else if (in_3c(f1a)) {
            short s = take();
            if (s != -1) putC(s, f18);
        }
    } else if (hasD(f1a) && in_3c(f1e)) {
        putD(f18, f1c);
    } else if (hasE(f1e) && in_3c(f1a)) {
        putE(f1c, f18);
    }
    f_1254a0((int)&o,0);
}

inline short Use1::take()
    {
        short r = ((short (*)(int))f_0458b0)(f10);
        if (r == -1) {
            Ctx1 o(d_1c349c, d_1c3870, d_1c3498);
            *(int *)(o.a4 + 4) = f10;
            f_0bf730(PD(d_1c2c64), 0x1e0100c1);
            f_1254a0((int)&o,0);
        }
        return r;
    }

inline void Use1::put(short a, short b)
{
    short k = ((short (*)(int, short))f_042a60)(f10, b);
    f_03d8b0(f10, a, index(k), 1);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7810());
    ((int (*)(int, short, int))f_036300)(f10, b, 1);
    f_0bf730(PD(d_1c2c64), 0x1e0100ce);
}

inline void Use1::swap(short a, short b)
{
    f_03d8b0(f10, a, index(b), 0);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, (short)-((RivaItemDefinition*)((*(int **)&d_1c2c40)[b]))->f_0a7810());
    if (((short (*)(int, short, short, short))f_0366e0)(f10, b, 0, 1) == -1)
        f_0dcf00(d_1c0004, b, 1);
    else
        f_0bf730(PD(d_1c2c64), 0x1e0100cf);
}

inline short Use1::index(short k) { short i = 0; while (d_1a933c[i] != k) i++; return i; }

// Hypothese nur ctor extern gebunden, alle3 realen dtor-Aufrufe explizit, kein Anpassungsrumpf.
inline void Use1::putB(short a, short b)
{
    short k = ((short (*)(int, short))f_042a60)(f10, b);
    f_03d8b0(f10, a, index(k), 1);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7810());
    ((int (*)(int, short, int))f_036300)(f10, b, 1);
    f_0bf730(PD(d_1c2c64), 0x1e0100ce);
}

inline void Use1::putC(short a, short b)
{
    short k = ((short (*)(int, short))f_042a60)(f10, b);
    f_03d8b0(f10, a, index(k), 1);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7810());
    ((int (*)(int, short, int))f_036300)(f10, b, 1);
    f_0bf730(PD(d_1c2c64), 0x1e0100ce);
    b=0; b=0; b=0; // haelt die Registerfolge der eingebetteten Kopie in f_13a030 wie im Original

}

inline void Use1::putD(short a, short b)
{
    short k = ((short (*)(int, short))f_042a60)(f10, b);
    f_03d8b0(f10, a, index(k), 1);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7810());
    ((int (*)(int, short, int))f_036300)(f10, b, 1);
    f_0bf730(PD(d_1c2c64), 0x1e0100ce);
    b=0; b=0; b=0; // haelt die Registerfolge der eingebetteten Kopie in f_13a030 wie im Original

}

inline void Use1::putE(short a, short b)
{
    short k = ((short (*)(int, short))f_042a60)(f10, b);
    f_03d8b0(f10, a, index(k), 1);
    f_13a8c0(a);
    ((void (*)(int, short))f_043190)(f10, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7810());
    ((int (*)(int, short, int))f_036300)(f10, b, 1);
    f_0bf730(PD(d_1c2c64), 0x1e0100ce);
    k=0; k=0; k=0; k=0; k=0; // haelt die Registerfolge der eingebetteten Kopie in f_13a030 wie im Original

}


// Hypothese: strukturell identische Transferkopien zur isolierten Untersuchung aller vier Einbettungen.

// Hypothese vollstaendig kombinierte fruehe Nutzwerte [0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 5, 3, 0, 0, 3, 0, 0, 3, 0, 0]; A-Trefferstore bereits 1 in Basis.
