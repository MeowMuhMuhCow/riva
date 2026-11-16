/* === Beschreibung (Katalog) ===
 * Einheit ship1_t1 (0ff6a0 - 100e30)
 *
 * Überblick
 *
 * Die Einheit ship1_t1 bildet den ersten Teil des 3D-Dungeon-Moduls ship1 (das versunkene Schiffswrack am
 * Meeresgrund bzw. Unterwasserschiff, Kennung 0x2a). Sie enthält die beiden großen Ereignis-Verteilerfunktionen
 * (f_0ff6a0, f_100850) für sämtliche Interaktionen und Schritt-Auslöser im Schiffswrack sowie die
 * Synchronisation der beweglichen Schiffstüren und Luken (f_100d80).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/3 gleich (suche.py 28.10.2026, Basis ship1_t1_P1.CPP)
// ship1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FF6A0-0x102E00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
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
int f_03ad80(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
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
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0fdbd0(int p1, int p2);                           // reg eax edx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_126430(int p1);                                   // reg eax stapel 0
int f_126450(int p1);                                   // reg eax stapel 0
int f_126460(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_135200(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_149360();                       // nicht in clobber.tsv
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a687e;                    // 0x1A687E
extern int d_1b834c;                    // 0x1B834C
extern int d_1b834e;                    // 0x1B834E
extern int d_1b8350;                    // 0x1B8350
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1bf4bc;                    // 0x1BF4BC
extern int d_1bf4be;                    // 0x1BF4BE
extern int d_1c0004;                    // 0x1C0004
extern int d_1c02a4;                    // 0x1C02A4
extern int d_1c02a8;                    // 0x1C02A8
extern int d_1c02ac;                    // 0x1C02AC
extern int d_1c02b0;                    // 0x1C02B0
extern int d_1c02b4;                    // 0x1C02B4
extern int d_1c02b8;                    // 0x1C02B8
extern int d_1c02c0;                    // 0x1C02C0
extern int d_1c02c8;                    // 0x1C02C8
extern int d_1c02d0;                    // 0x1C02D0
extern int d_1c02d4;                    // 0x1C02D4
extern int d_1c02d8;                    // 0x1C02D8
extern int d_1c02f0;                    // 0x1C02F0
extern int d_1c02f4;                    // 0x1C02F4
extern int d_1c0300;                    // 0x1C0300
extern int d_1c030c;                    // 0x1C030C
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a6860[];           // Text 0x1A6860

// --- Prototypen (Pass 1, Helfer C) ---
int f_0bf680(void *p1);
int f_0bf6c0(void *p1, int p2);
short f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
short f_0bf820(void *p1, ...);
int f_0bf980(void *p1, int p2, int p3, int p4, int p5);
int f_0bfa20(void *p1, int p2, int p3, int p4, int p5);
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(void *p1, int p2);
int f_125f70(void *p1, int p2);
int f_126410(void *p1);
int f_0d2f90(int p1, int p2);
int f_057220(void *p1, int p2, int p3);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060770(int p1, int p2);
short f_0366e0(int p1, int p2, int p3, int p4);
short f_0dcf00(int p1, int p2, int p3);


short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0d54f0(int p1, int p2);
int f_0fb660(int p1, int p2);
void *f_046d90(int p1, int p2);
void *f_112e70(int p1, int p2);
void *f_010590(int p1, int p2);

int f_0de7d0(int p1, int p2);
void f_100850(int p1);
void f_100e30(int p1);
void f_101230(int p1); void f_1013f0(int p1); void f_1016f0(int p1); void f_101860(int p1); void f_101910(int p1);
void f_1014c0(int p1); void f_1027e0(int p1); void f_101f60(int p1); void f_101c20(int p1);
void f_102620(int p1); void f_102330(int p1); void f_102050(int p1); void f_102170(int p1); void f_1024b0(int p1);
void f_1026d0(int p1, int p2);
void f_102cc0(int p1, int p2, int p3, int p4);
void f_102bb0(int p1);
void f_102a60(int p1);
extern signed char d_1c0294, d_1c02a0, d_1c02c4, d_1c02cc, d_1c02dc, d_1c02e0, d_1c02e8, d_1c02f8, d_1c02fc, d_1c0304, d_1c0308, d_1c0318, d_1c0364;
extern short d_1c21a4;
inline int EQ(int a, int b) { return a == b; }
inline int EQC(char a, char b) { return a == b; }
#define CTOR(b) f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498)
#define SETF(b, v) *(int *)(b[1] + 4) = (v)
#define MSG(n) f_0bf730(&d_1c2c64, n)
#define BODYA(b, E) { int u; CTOR(b); u = f_039320(d_1c0004, 0x2a); SETF(b, u); f_0bf6c0(&d_1c2c64, 5); if (E(d_1c02e0, 0)) { d_1c02e0 = 1; MSG(0x2f00001a); f_125ed0(&d_1c2c44, 2); } else { MSG(0x2f00001b); } f_0bf680(&d_1c2c64); f_1254a0(b, 0); }
#define NEWA(LINE, K) q = (int)operator new(0xc, mark(d_1a6860, LINE)); if (q) q = f_046d10(q, K); f_046de0(q); if (q) operator delete(f_046d90(q, 0));
#define NEWB(LINE, K) q = (int)operator new(0x14, mark(d_1a6860, LINE)); if (q) q = f_112df0(q, K, 0, 0); f_112ec0(q); if (q) operator delete(f_112e70(q, 0));

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0ff6a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Verteilerfunktion verarbeitet sämtliche ortsgebundenen Interaktionen (0x00 bis 0x4c)
 *   im Schiffswrack ship1, darunter das Aufbrechen aufgequollener Holztüren unter Wasser, das Durchsuchen von
 *   Kisten und Skeletten, Begegnungen mit Unterwasserwesen sowie Übergänge zwischen den Schiffsdecks.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktions- oder
 *   Richtungszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Statuscode der ausgeführten Interaktion zurück.
 === Ende Beschreibung === */
void *shipSmallCtor493(void*,int);
#pragma aux shipSmallCtor493 "f_046d10" parm [eax] [edx] value [eax] modify exact [eax edx]
struct ShipSmall493 {char bytes[12]; __pragma("shipSmallCtor493") ShipSmall493(int);};
void *construct493(void*,int,int,int);
#pragma aux construct493 "f_112df0" parm [eax] [edx] [ebx] [ecx] value [eax] modify exact [eax ebx edx]
struct NativeSpoil493 {char data[0x14]; __pragma("construct493") NativeSpoil493(int,int,int);};
int dialogInt493(void*,int);
#pragma aux dialogInt493 "f_0bf6f0" parm [eax] [edx] value [eax] modify exact [eax]
int passage493(int);
#pragma aux passage493 "f_0fdbd0" parm [eax] value [eax] modify exact [eax]
short f_0ff6a0(int p1, short m)
{
    struct Flag { static inline int eq(const signed char &x, signed char v) { return x == v; } };
    struct ZeroForward493 {static inline int eq(const signed char &value,signed char target){return value==target;}};
    struct ZeroReverse493 {static inline int eq(signed char target,const signed char &value){return value==target;}};
    int result;
    int object, value, choice;
    struct SceneData493 {int a; int *p; int rest[13];};
    SceneData493 rooms[8];
    result = 0;
    if ((short)m == 0)
        goto END_RANGE;
    result = 1;
    if ((short)m >= (short)0x195 && (short)m <= (short)0x1ad) {
        object=(int)new(mark(d_1a6860,0x866)) ShipSmall493((short)(m-0x17a));
        f_046de0(object);
        if (object) operator delete(f_046d90(object, 0));
END_RANGE:
        return result;
    }
    switch ((unsigned short)m) {
    case 0x65: f_100850(p1); goto END_RANGE;
    case 0x66: {
        int u;
        f_125400(&rooms[1],&d_1c349c,&d_1c3870,&d_1c3498);
        u = f_039320(d_1c0004, 0x2a);
        rooms[1].p[1] = u;
        f_0bf6c0(&d_1c2c64, 5);
        if (ZeroForward493::eq(d_1c02e0,0)) {
            d_1c02e0 = 1;
            MSG(0x2f00001a);
            f_125ed0(&d_1c2c44, 2);
        } else MSG(0x2f00001b);
        f_0bf680(&d_1c2c64);
        f_1254a0(&rooms[1], 0);
        goto END_RANGE;
    }
    case 0x67: f_100e30(p1); goto END_RANGE;
    case 0x68: f_100e30(p1); goto END_RANGE;
    case 0x69: f_100e30(p1); goto END_RANGE;
    case 0x6a: MSG(0x2f00001d); f_125ed0(&d_1c2c44, 1); goto END_RANGE;
    case 0x6b: MSG(0x2f00001e); goto END_RANGE;
    case 0x6d:
        if (Flag::eq(d_1c02a0, 3)) {
            if ((short)dialogInt493(&d_1c2c64, 0x2f000028) != (short)1) goto END_RANGE;
            if ((short)dialogInt493(&d_1c2c64, 0x2f000029) == (short)1) {
                passage493(p1); f_125ed0(&d_1c2c44, 2);
            } else {
                d_1c02a0 = 5; MSG(0x2f00002a);
            }
            f_060740(0x1f47, 1);
            goto END_RANGE;
        }
        f_125400(&rooms[4],&d_1c349c,&d_1c3870,&d_1c3498);
        value = f_039320(d_1c0004, 0x2a);
        rooms[4].p[1] = value;
        f_0bf6c0(&d_1c2c64, 5);
        if (EQB(d_1c02e0, 0)) {
            d_1c02e0 = 1;
            MSG(0x2f00001a);
            f_125ed0(&d_1c2c44, 2);
        } else MSG(0x2f00001b);
        f_0bf680(&d_1c2c64);
        f_1254a0(&rooms[4], 0);
        goto END_RANGE;
    case 0x70: f_1026d0(p1, 1); goto END_RANGE;
    case 0xca: f_1026d0(p1, 2); goto END_RANGE;
    case 0xcb: MSG(0x2f000033); goto END_RANGE;
    case 0xcc: MSG(0x2f000034); goto END_RANGE;
    case 0xcd: MSG(0x2f000035); goto END_RANGE;
    case 0xce:
        f_0bf6c0(&d_1c2c64, 5); MSG(0x2f000036); f_0bf680(&d_1c2c64);
        goto END_RANGE;
    case 0xcf: goto END_RANGE;
    case 0xd0: goto END_RANGE;
    case 0xd1: {int rt1303_d1=d_1c0004;d_1c0004=rt1303_d1;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        MSG(0x2f000037); goto END_RANGE;
    case 0xd2: {int rt1303_d2=d_1c0004;d_1c0004=rt1303_d2;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        f_101230(p1); goto END_RANGE;
    case 0xd3: {int rt1303_d3=d_1c0004;d_1c0004=rt1303_d3;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        f_125400(&rooms[0],&d_1c349c,&d_1c3870,&d_1c3498);
        { int t_ = d_1c0004; rooms[0].p[1] = f_038c40(t_); }
        MSG(0x2f00003b);
        { int allocation=(int)operator new(0x14,mark(d_1a6860,0x3d9));
          object=allocation;
          if(allocation) object=f_112df0(allocation,0x4e,0,0); }
        f_112ec0(object);
        if (object) operator delete(f_112e70(object, 0));
        f_1254a0(&rooms[0], 0);
        goto END_RANGE;
    case 0xd4:
        object = (int)operator new(0xc, mark(d_1a6860, 0x3eb));
        if (object) object = f_046d10(object, 0x13);
        choice = object;
        if (f_046ec0(object) == 1) { MSG(0x2f00003c); f_046de0(object); }
        if (choice) operator delete(f_046d90(choice, 0));
        goto END_RANGE;
    case 0xd5: f_1013f0(p1); goto END_RANGE;
    case 0x12e: {int rt1303_12e=d_1c0004;d_1c0004=rt1303_12e;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        MSG(0x2f000042); goto END_RANGE;
    case 0x12f:
        f_125400(&rooms[2],&d_1c349c,&d_1c3870,&d_1c3498);
        { int t_ = d_1c0004; rooms[2].p[1] = f_0396f0(t_, 0); }
        MSG(0x2f000043);
        f_1254a0(&rooms[2], 0);
        goto END_RANGE;
    case 0x130: f_1016f0(p1); goto END_RANGE;
    case 0x131: f_101860(p1); goto END_RANGE;
    case 0x132: {int rt1303_132=d_1c0004;d_1c0004=rt1303_132;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        f_101910(p1); goto END_RANGE;
    case 0x133:
        if (ZeroReverse493::eq(0,d_1c0304) && dialogInt493(&d_1c2c64, 0x2f000046) == 1) {
            d_1c0304 = 1;
            f_0dcf00(d_1c0004, 0x20, 1);
            f_060740(0x1f4a, 1);
            f_0607e0(0x1f48, 1);
        }
        goto END_RANGE;
    case 0x134:
        f_0bf6c0(&d_1c2c64, 5); MSG(0x2f000047); f_0bf680(&d_1c2c64);
        goto END_RANGE;
    case 0x135:
        goto CHECK135;
MSG49:
        value = 0x2f000049;
SAY135:
        MSG(value);
        object=(int)new (mark(d_1a6860,0x53f)) NativeSpoil493(0x4f,0,0);
        f_112ec0(object);
        if (object) operator delete(f_112e70(object, 0));
        goto END_RANGE;
CHECK135:
        if (!(ZeroReverse493::eq(0,d_1c02f8))) goto MSG49;
        d_1c02f8 = 1; value = 0x2f000048;
        goto SAY135;
    case 0x136: {
        struct ActorHolder1303 { int value; } actor;
        f_125400(&rooms[3],&d_1c349c,&d_1c3870,&d_1c3498);
        actor.value = f_038c40(d_1c0004);
        if (dialogInt493(&d_1c2c64, 0x2f00004a) == 1) {
            rooms[3].p[1] = actor.value; MSG(0x2f00004b); f_044850(actor.value, 1, 5);
        }
        f_1254a0(&rooms[3], 0);
        goto END_RANGE;
    }
    case 0x137:
        if (ZeroReverse493::eq(0,d_1c02fc) && dialogInt493(&d_1c2c64, 0x2f00004c) == 1) {
            d_1c02fc = 1;
            f_0dcf00(d_1c0004, 0x61, 2);
            f_060740(0x1f4b, 1);
            f_0607e0(0x1f49, 1);
        }
        goto END_RANGE;
    case 0x138: {int rt1303_138=d_1c0004;d_1c0004=rt1303_138;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        MSG(0x2f00004d); goto END_RANGE;
    case 0x191:
        if (dialogInt493(&d_1c2c64, 0x2f000051) == 1)
            f_0dd7f0(d_1c0004, 0x18, 0x139a);
        goto END_RANGE;
    case 0x192: f_101c20(p1); goto END_RANGE;
    case 0x193: case 0x194: MSG(0x2f000033); goto END_RANGE;
    case 0x1af:
        if (dialogInt493(&d_1c2c64, 0x2f000051) == 1)
            f_0dd7f0(d_1c0004, 0x18, 0x13fe);
        goto END_RANGE;
    case 0x1f5:
        f_125400(&rooms[5],&d_1c349c,&d_1c3870,&d_1c3498);
        { int t_ = (int)(d_1c0004); object = f_039780(t_, 5); }
        if (object == 0) object = f_039320(d_1c0004, 0x12);
        MSG(0x2f000055);
        if (object && EQB(d_1c02c4, 0)) {
            d_1c02c4 = 1; rooms[5].p[1] = object; MSG(0x2f000056);
        }
        f_1254a0(&rooms[5], 0);
        goto END_RANGE;
    case 0x1f6:
        if (ZeroReverse493::eq(0,d_1c0308)) {
            if (dialogInt493(&d_1c2c64, 0x2f000057) == 1) {
                if ((int)f_0d54f0(d_1c0004, 0x1a) >= 0) {
                    d_1c0308 = 1;
                    f_125ed0(&d_1c2c44, 4);
                    value = 0x2f000058;
                } else value = 0x2f000059;
                MSG(value);
            }
        } else MSG(0x2f00005a);
        if (EQB(d_1c0308, 1)) { f_0dbeb0(d_1c0004); f_0dcae0(d_1c0004); }
        goto END_RANGE;
    case 0x1f7: MSG(0x2f00005b); goto END_RANGE;
    case 0x1f8: {int rt1303_1f8=d_1c0004;d_1c0004=rt1303_1f8;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original
        object=(int)new (mark(d_1a6860,0x65c)) NativeSpoil493(0x52,0,0);
        f_112ec0(object);
        if (object) operator delete(f_112e70(object, 0));
        goto END_RANGE;
    case 0x1f9:
        object=(int)new (mark(d_1a6860,0x66e)) NativeSpoil493(0x53,0,0);
        f_112ec0(object);
        if (object) operator delete(f_112e70(object, 0));
        goto END_RANGE;
    case 0x259: f_102050(p1); goto END_RANGE;
    case 0x25a: {int rt1303_25a=d_1c0004;d_1c0004=rt1303_25a;} // haelt die Symbol- und Registerfolge in f_0ff6a0 wie im Original 
        object = (int)operator new(0xc, mark(d_1a6860, 0x6d8));
        if (object) object = f_046d10(object, 0x34);
        f_046de0(object);
        if (object) operator delete(f_046d90(object, 0));
        f_125ed0(&d_1c2c44, 2);
        goto END_RANGE;
    case 0x25b: f_102170(p1); goto END_RANGE;
    case 0x25c:
        object = (int)operator new(0xc, mark(d_1a6860, 0x718));
        if (object) object = f_046d10(object, 0x36);
        f_046de0(object);
        if (object) operator delete(f_046d90(object, 0));
        f_125ed0(&d_1c2c44, 2);
        goto END_RANGE;
    case 0x25d:
        object = (int)operator new(0xc, mark(d_1a6860, 0x72c));
        if (object) object = f_046d10(object, 0x37);
        f_046de0(object);
        if (object) operator delete(f_046d90(object, 0));
        f_125ed0(&d_1c2c44, 3);
        goto END_RANGE;
    case 0x25e: f_102330(p1); goto END_RANGE;
    case 0x2bd:
        f_125400(&rooms[7],&d_1c349c,&d_1c3870,&d_1c3498);
        if (EQB(d_1c02cc, 0)) {
            d_1c02cc = 1;
            object = f_039780(d_1c0004, 5);
            if (!object) object = f_038be0(d_1c0004);
            rooms[7].p[1] = object;
            MSG(0x2f000061);
        } else MSG(0x2f000062);
        f_1254a0(&rooms[7], 0);
        goto END_RANGE;
    case 0x2be: f_1024b0(p1); goto END_RANGE;
    case 0x2bf:
        object=(int)new (mark(d_1a6860,0x7b8)) NativeSpoil493(0x51,0,0);
        f_112ec0(object);
        if (object) operator delete(f_112e70(object, 0));
        goto END_RANGE;
    case 0x2c0:
        f_125400(&rooms[6],&d_1c349c,&d_1c3870,&d_1c3498);
        value = f_039320(d_1c0004, 0x22);
        rooms[6].p[1] = value;
        MSG(0x2f000064);
        f_1254a0(&rooms[6], 0);
        goto END_RANGE;
    case 0x2c1: f_102620(p1); goto END_RANGE;
    case 0x1f41:
        if (EQB(d_1c02e8, 0)) {
            if ((short)dialogInt493(&d_1c2c64, 0x2f00001f) != (short)1) goto END_RANGE;
            f_060740(0x1f41, 1);
            MSG(0x2f000020);
            d_1c02e8 = 1;
            f_060770(0x1f41, 0);
            f_1027e0(p1);
        } else f_060770(0x1f41, 0);
        goto END_RANGE;
    case 0x1f42: f_1014c0(p1); goto END_RANGE;
    case 0x1f43:
        if (EQB(d_1c02a0, 0)) { f_05fa00(0x25, 0x1f43); f_1027e0(p1); }
        else f_05fa00(0x25, 0x1f43);
        goto END_RANGE;
    case 0x1f44: f_101f60(p1); goto END_RANGE;
    case 0x1f45: f_05fa00(0x28, 0x1f45); goto END_RANGE;
    case 0x1f46: f_05fa00(0x29, 0x1f46); goto END_RANGE;
    case 0x1b59: case 0x1b5a: case 0x1b5b: case 0x1b5c: case 0x1b5d: case 0x1b5e:
        f_0fb660(p1, m); goto END_RANGE;
    default: result = 0; goto END_RANGE;
    }
    goto END_RANGE;
}

//@ f_100850
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zweite Verteilerfunktion verarbeitet die weiteren Karten- und Schrittauslöser im Schiffswrack
 *   ship1, prüft Strömungs- und Einsturzgefahren und verzweigt in die zugehörigen Raum- und Kampfszenen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Parameterzeiger p3.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der ausgelösten Aktion zurück.
 === Ende Beschreibung === */
void f_100850(int p1)
{
  void m4_102cc0(int);
#pragma aux m4_102cc0 "f_102cc0" modify exact [eax esp];
  int m4_bf980(char*,int,int,int,int);
#pragma aux m4_bf980 "f_0bf980" parm caller [] value [eax] modify exact [eax];
  int m4_bfa20(char*,int,int,int,int);
#pragma aux m4_bfa20 "f_0bfa20" parm caller [] value [eax] modify exact [eax];
  struct Menu { static inline short count(const signed char &v) { signed char c=v; int n=(int)c; int b=(n!=1); int m=b+3; return (short)m; } };
  int b[15];
  int i;
  int q, q2, p, u, done;
  short s;
  short ss;
  CTOR(b);
  f_0d2f90(5, 1);
  while (f_126410(&d_1c2c44) < 0xa8c0 || f_126410(&d_1c2c44) > 54000) f_125f70(&d_1c2c44, 1);
  m4_102cc0(p1);
  f_0d2f90(0, 1);
  for (i = 0; (u=(short)i) <= 6; ++i) {
    q = f_0de7d0(d_1c0004, u);
    q2 = q;
    if (q != 0 && !((char)(f_042470((struct hero *)(q))))) {
      signed char c;
      short t;
      f_043e20(q, 1);
      f_0d5040(q, f_0d4c80(q), 0xa8c, 4, -1, 0);
      f_0d5040(q, f_0d4c80(q), 0xa8c, 3, -1, 0);
      f_0d5040(q, f_0d4c80(q), 0xa8c, 6, -1, 0);
      f_0d5040(q, f_0d4c80(q), 0xa8c, 2, -1, 0);
      f_0d5040(q, f_0d4c80(q), 0x1518, 4, -1, 0);
      f_0d5040(q, f_0d4c80(q), 0x1518, 3, -1, 0);
      c = f_042350((struct hero *)(q));
      t = c;
      if (c == 6 || (t >= 10 && t <= 12)) {
        f_0d5040(q2, f_0d4c80(q2), 0x1518, 6, -1, 0);
        f_0d5040(q2, f_0d4c80(q2), 0x1518, 2, -1, 0);
      }
      f_043e20(q2, 0);
    }
  }
  f_0366e0(f_038c40(d_1c0004), 0xf9, 0, 1);
  f_0366e0(f_0391b0(d_1c0004, f_038c40(d_1c0004)), 0xf9, 0, 1);
  u = f_039660(d_1c0004, 6);
  SETF(b, u);
  f_039320(d_1c0004, 0x26);
  f_0bf6c0(&d_1c2c64, 5);
  MSG(0x2f000007);
  int allocation=(int)operator new(0x13e, mark(d_1a6860, 0x1b9));
  q=allocation ? f_0104b0(allocation,0x2c000a,0,0) : allocation;
  m4_bf980((char*)&d_1c2c64, q, 0, 0x2f000008, 0);
  if (q) operator delete(f_010590(q, 0));
  q = f_0606a0(0x2f0002, 2);
  m4_bfa20((char*)&d_1c2c64, q, 0, 0x2f000009, 0);
  m4_bfa20((char*)&d_1c2c64, q, 0, 0x2f00000a, 0);
  if (q) operator delete(((void *)(((RivaRasterImage*)(q))->f_0fad20( 0))));
  allocation=(int)operator new(0x13e, mark(d_1a6860, 0x1c4));
  q=allocation ? f_0104b0(allocation,0x2c000b,0,0) : allocation;
  m4_bf980((char*)&d_1c2c64, q, 0, 0x2f00000b, 0);
  if (q) operator delete(f_010590(q, 0));
  MSG(0x2f00000c);
  f_057220(&d_1c2c00, 0x8030023, 0);
  p = 0;
  done = 0;
  s = 0;
  d_1c0364 = 0x15;
  do {
    ss = f_0bf820(&d_1c2c64, 0x2f00000d, Menu::count(d_1c0318), 0x2f00000e, 0x2f00000f, 0x2f000010, 0x2f000011);
    switch ((unsigned short)(ss + 1)) {
    case 0: s++; break;
    case 2: MSG(0x2f000012); s += 0xc; break;
    case 3:
      s += 2;
      MSG(0x2f000013);
      if (s > 0x14) s = 0xf;
      done = 1;
      break;
    case 4: f_102bb0(p); s += 3; break;
    case 5:
      if (EQB(d_1c0318, 0)) {
        p = (int)&d_1c23a8;
        s += 7;
        f_102a60(p);
        d_1c0318 = 1;
      }
      break;
    }
    if (s > 0x13) {
      MSG(0x2f000014);
      if (EQ(d_1c0318, 1)) {
        if (EQ(d_1c02dc, 0)) { MSG(0x2f000015); } else { MSG(0x2f000016); }
        MSG(0x2f000017);
        d_1c21a4 = 10;
      } else {
        MSG(0x2f000018);
        done = 10;
        MSG(0x2f000019);
        d_1c21a4 = done;
        done = 1;
      }
      done = 1;
    }
  } while (done == 0);
  if (d_1c21a4 == 0) d_1c0294 = (signed char)s;
  f_0bf680(&d_1c2c64);
  f_1254a0(b, 0);
}

//@ f_100d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode synchronisiert beim Laden oder Betreten des Schiffswracks ship1 die Zustände der
 *   aufgebrochenen Türen, Luken und eingestürzten Durchgänge in der 3D-Kartenstruktur mit den gespeicherten
 *   Flags (d_1c03bc ff.).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_100d80(void)
{
  int b[15];
  BODYA(b, EQ)
}
