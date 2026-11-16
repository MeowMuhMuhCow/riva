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
//@ f_01a6a0
int f_01a6a0() { return 0; }
