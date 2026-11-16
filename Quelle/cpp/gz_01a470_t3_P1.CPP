// P3 25/29 gleich (suche.py 28.10.2026, Basis gz_01a470_P1.CPP)
// I9: aus G01A470_REST.CPP uebernommen (Stufe-2-Stand), Marken 8 neu
// STAND 22.10. (Helfer C): NICHT GLEICH. 5D0 19 Bef, 4B0 11, 560 14, 840 27; Stubs 6A0-7F0: Watcom faltet identische Rumpfe (offen: COMDAT/Inline-Klassenmethoden, siehe Lauf 6). 470/490/690/820 Struktur ok
// gz_01a470.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4 (Helfer C)
// Code 0x01A470-0x01A880. Kartenobjekt-Kleinfunktionen (amap/amapanno): Zeichen-Rahmen mit Hilfsobjekt, Stubs, Offsetverschiebung.
#include <string.h>
struct Tmp {                                             // 8-Byte-Hilfsobjekt auf dem Stapel
    Tmp(int a);                                          // 0x01B860
    ~Tmp();                                              // 0x01B880
    void f_01b890(int v);                                // 0x01B890
    unsigned char f_01be20();                            // 0x01BE20
    void f_01bc70(int v);                                // 0x01BC70
    int x, y;
};
#pragma pack(1)
struct Obj {
    signed char id;                                      // +0x00
    char p1[8];
    short s09;                                           // +0x09
    short s0b;                                           // +0x0B
    char p2[0x23 - 0x0D];
    int i23;                                             // +0x23
    int i27;                                             // +0x27
    int i2b;                                             // +0x2B
    char p3[0xfd - 0x2f];
    int fd;                                              // +0xFD
    int f101;                                            // +0x101
    int f105;                                            // +0x105
    char p4[2];
    int f10b;                                            // +0x10B
};
#pragma pack()
struct S8 { unsigned short a, b, c, d; };
#pragma pack(1)
struct AnnoHdr { char magic[4]; short a; short b; short n; long ofs; long end; };
struct AnnoEntry { char b0[4]; unsigned long pos; char b8[4]; };
#pragma pack()
struct AMapAnno {
    unsigned long fileid;
    AnnoHdr *hdr;
    AnnoEntry *ent;
    void f_01a840(unsigned long thr, long delta);
};
void f_015af0(Obj *p, int z);
void f_016580(Obj *p, int z);
int f_0ce650();
#define CE(p) f_0ce650()
void f_018f00(Obj *p);
void f_01b860(Tmp *p, int a);
void f_0d26e0();
void f_0d2710();
int f_0d3860();
extern int d_1c0c4c;
extern signed char d_1c21b4;
extern int d_1a34e0;

struct S4 { int x; };

#define EQ(x,v) (((x)==(v))?1:0)

//@ f_01a6b0
static char a_pad[2048] = {1};
inline int a_bar1(void) { return a_pad[0] ? 0 : 0; }
static int (*a_keep1)(void) = a_bar1;
int f_01a6b0()
{
    return 0;
}
inline int a_bar2(void) { return a_pad[0] ? 0 : 0; }
static int (*a_keep2)(void) = a_bar2;
int f_01a6c0() { return 0; }
//@ f_01a6d0
inline int a_bar3(void) { return a_pad[0] ? 0 : 0; }
static int (*a_keep3)(void) = a_bar3;
int f_01a6d0()
{
    return 0;
}
inline int a_bar4(void) { return a_pad[0] ? 0 : 0; }
static int (*a_keep4)(void) = a_bar4;
int f_01a6e0() { return 0; }
//@ f_01a6f0
inline int bar6f0(void) { return a_pad[0] ? 0 : 0; }
static int (*keep6f0)(void) = bar6f0;
int f_01a6f0(void)
{
    return 0;
}
inline int bar6f1(void) { return a_pad[0] ? 0 : 0; }
static int (*keep6f1)(void) = bar6f1;
//@ f_01a700
int f_01a700()
{
    return -1;
}
int f_01a710() { return 0; }
//@ f_01a720
inline int bar720(void) { return a_pad[0] ? 0 : 0; }
static int (*keep720)(void) = bar720;
int f_01a720()
{
    return 0;
}
inline int bar721(void) { return a_pad[0] ? 0 : 0; }
static int (*keep721)(void) = bar721;
unsigned char f_01a730() { return 0xff; }
int f_01a740() { return 0; }
//@ f_01a750
inline int b750a(void) { return a_pad[0] ? 0 : 0; }
static int (*k750a)(void) = b750a;
int f_01a750(void)
{
    return 0;
}
inline int b750b(void) { return a_pad[0] ? 0 : 0; }
static int (*k750b)(void) = b750b;
int f_01a760() { return d_1a34e0; }
int f_01a770() { return 0x140; }
//@ f_01a780
inline int bar780(void) { return a_pad[0] ? 1 : 1; }
static int (*keep780)(void) = bar780;
int f_01a780()
{
    return 1;
}
inline int bar781(void) { return a_pad[0] ? 1 : 1; }
static int (*keep781)(void) = bar781;
S4 *f_01a790(S4 *p, int x) { if (p->x == 1) f_0d26e0(); return p; }
S4 *f_01a7b0(S4 *p) { if (f_0d3860() == 1) { f_0d2710(); p->x = 1; } else p->x = 0; return p; }
int f_01a7e0() { return 1; }
//@ f_01a7f0
int f_01a7f0()
{
    return 0;
}
inline int bar7f0(void) { return a_pad[0] ? 0 : 0; }
static int (*keep7f0)(void) = bar7f0;
int f_01a800() { return 0; }
int f_01a810() { return 0x200; }

//@ f_01a820
S8 *f_01a820(S8 *r, unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    r->a = a;
    r->b = b;
    r->c = c;
    r->d = d;
    return r;
}

//@ f_01a840
void AMapAnno::f_01a840(unsigned long thr, long delta)
{
    short i;
    for (i = 0; i < hdr->n; i++) {
        if (thr < ent[i].pos) ent[i].pos += delta;
    }
    hdr->ofs += delta;
}

