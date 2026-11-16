/* === Beschreibung (Katalog) ===
 * Einheit tower1_t1 (0x129d70 - 0x12b010)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil der oberen Etagen des Magierturms (tower1.cpp, Dungeon-ID 0x13).
 * Sie enthält den zentralen Ereignis-Verteiler (f_129d70), das umfangreiche Gesprächs- und Verhandlungssystem
 * mit dem Bewohner/Dämonenbeschwörer der oberen Etage (f_12aa30) sowie mehrere Beute- und Raumevents.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 5/8 gleich (suche.py 28.10.2026, Basis tower1_t1_P1.CPP)
// tower1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x129D70-0x12C190
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041030();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
int f_041ae0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_044060(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f560(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de020(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c0cf8;                    // 0x1C0CF8
extern int d_1c0d00;                    // 0x1C0D00
extern int d_1c0d08;                    // 0x1C0D08
extern int d_1c0d0c;                    // 0x1C0D0C
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2470;                    // 0x1C2470
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1a8c7f[];           // Text 0x1A8C7F
extern const char d_1a8c80[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern signed char d_1c0ce8, d_1c0cec, d_1c0cf0, d_1c0cfc, d_1c0d04;
extern signed char d_1c0cf4;
int f_0bf680(int p1);
short f_0bf820(int p1, ...);
unsigned short f_0bf980(int p1, ...);
int f_0bfa20(int p1, ...);
short f_0dcf00(int p1, int p2, int p3);
int f_060740(int p1, int p2);
int f_12b010(int p1);
void f_12aa30(int p1);
int f_12b8b0(int p1);
int f_12ba70(int p1);
typedef short (*VF)(int, int, int);
struct S14 { int a[5]; };
struct S0c { int a[3]; };
struct S13e { char a[0x13e]; };
#define MBOX ((int)&d_1c2c64)
#define MSG(n) f_0bf730(MBOX, n)
#define EQI(x,v) (((x)==(v))?1:0)
#define OBJ RivaTextContext o(d_1c349c, d_1c3870, d_1c3498)
#define OSET(v) *(int *)(o.slots[0] + 4) = (v)
#define VCALL(a) ((*(VF *)*(int *)(p1 + 8))(p1, a, 0))
#define RET return r
#define NEWC(LINE,K,A) { S0c *o = new (mark(d_1a8c80, LINE)) S0c; o = o ? (S0c *)f_05f190((int)o, K, A) : o; if (EQI(d_1c0d04, 0) && f_05f560((int)o) == 1) MSG(0x27000080); f_05f280((int)o, 0); if (o) operator delete((void *)f_05f220((int)o, 0)); }
#define B67 { int b = 1; S14 *o = new (mark(d_1a8c80, 0x29a)) S14; o = o ? (S14 *)f_112df0((int)o, 0x2b, 0, 0) : o; if (f_1131b0((int)o) == 0 && f_0bf6f0(MBOX, 0x27000079) != 1) b = 0; if (b == 1) f_112ec0((int)o); if (o) operator delete((void *)f_112e70((int)o, 0)); }
#define B68 { S14 *o = new (mark(d_1a8c80, 0x2b9)) S14; o = o ? (S14 *)f_112df0((int)o, 0x2c, 0, 0) : o; if (f_1131b0((int)o) == 1 || f_0bf6f0(MBOX, 0x2700007a) == 1) f_112ec0((int)o); if (o) operator delete((void *)f_112e70((int)o, 0)); }


#define EQ(x,v) (((x)==(v))?1:0)
//@ f_129d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Handler der oberen Magierturm-Etage (tower1), der anhand des Ereigniscodes p2
 *   Dialoge, Kämpfe, Teleporter, Beutetruhen, magische Fallen und das Zweigruppen-Rätsel (0x385, 0x386) auslöst.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis behandelt wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_129d70(int p1, unsigned short p2)
{
    struct Raw { int f0; char *p[13]; int s38; };
    struct { Raw o1f5, o12e, oc9, o12d, oca; } st;
#define BOBJ(x) f_125400((int)&st.x, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498)
#define BSET(x, v) *(int *)(st.x.p[0] + 4) = (v)
#define EOBJ(x) ((int (*)(int, int))f_1254a0)((int)&st.x, 0)
    struct H {
        static inline int eq(const signed char &x, signed char y) { return x == y; }
        static inline void c191(int p1) {
            signed char z = 0; signed char q = z;
            if ((((int)d_1c0d04 == (int)q) ? 1 : 0)) {
                int o = f_0606a0(0x270001, 3);
                f_0bfa20(MBOX, o, 0, 0x2700008b, 0);
                if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
                if (VCALL(6) == 0) d_1c0d04 = 1;
            }
        }
    };
    int r = 1;
    switch (p2) {
    case 0x65:
        if (f_0bf6f0(MBOX, 0x27000064) == 1) f_0dd7f0(d_1c0004, 0x12, 0x1533);
        break;
    case 0x66: f_12aa30(p1); break;
    case 0x67: {
        int b = 1;
        unsigned size = 0x14;
        S14 *raw = (S14 *)operator new(size, mark(d_1a8c80, 0x29a));
        S14 *saved = raw;
        S14 *o = raw ? (S14 *)f_112df0((int)raw, 0x2b, 0, 0) : saved;
        if (f_1131b0((int)o) == 0 && f_0bf6f0(MBOX, 0x27000079) != 1) b = 0;
        if (b == 1) f_112ec0((int)o);
        if (o) operator delete((void *)f_112e70((int)o, 0));
        break;
    }
    case 0x68: {
        void *tag = mark(d_1a8c80, 0x2b9);
        S14 *raw = (S14 *)operator new(0x14, tag);
        S14 *saved = raw;
        S14 *o = raw ? (S14 *)f_112df0((int)raw, 0x2c, 0, 0) : saved;
        if (f_1131b0((int)o) == 1 || f_0bf6f0(MBOX, 0x2700007a) == 1) f_112ec0((int)o);
        if (o) operator delete((void *)f_112e70((int)o, 0));
        break;
    }
    case 0xc9: {
        BOBJ(oc9);
        if (H::eq(d_1c0cfc, 0)) {
            BSET(oc9, f_039320(d_1c0004, 0x33));
            MSG(0x2700007b);
            d_1c0cfc = 1;
        }
        EOBJ(oc9);
        break; }
    case 0xca: {
        BOBJ(oca);
        BSET(oca, f_039320(d_1c0004, 0x23));
        MSG(0x2700007c);
        f_125ed0((int)&d_1c2c44, 10);
        EOBJ(oca);
        break; }
    case 0xcb: break;
    case 0x12d: {
        BOBJ(o12d);
        BSET(o12d, f_039660(d_1c0004, 0xc));
        MSG(0x27000087);
        EOBJ(o12d);
        break; }
    case 0x12e: {
        BOBJ(o12e);
        BSET(o12e, f_039660(d_1c0004, 6));
        MSG(0x27000088);
        EOBJ(o12e);
        break; }
    case 0x12f: MSG(0x27000089); break;
    case 0x130: f_0603b0(0x2d); break;
    case 0x131: f_0603b0(0x2e); break;
    case 0x132: case 0x2be: MSG(0x2700008a); break;
    case 0x191: H::c191(p1); break;
    case 0x192:
        if (f_0bf6f0(MBOX, 0x2700008c) == 1) f_0de810(d_1c0004, 0x67);
        break;
    case 0x193: f_0603b0(0x2f); break;
    case 0x194: f_0603b0(0x30); break;
    case 0x1f5: {
        BOBJ(o1f5);
        BSET(o1f5, f_039660(d_1c0004, 0xc));
        MSG(0x2700008d);
        EOBJ(o1f5);
        break; }
    case 0x1f6: MSG(0x2700008e); break;
    case 0x1f7: f_0603b0(0x31); break;
    case 0x1f8:
        if (f_0bf6f0(MBOX, 0x2700008f) == 1) f_0dbeb0(d_1c0004);
        break;
    case 0x1f9: {
        signed char z = 0;
        if ((((int)d_1c0cec == (int)z) ? 1 : 0)) {
            if (f_0bf6f0(MBOX, 0x27000090) == 1) {
                short s = f_0dcf00(d_1c0004, 4, 1);
                if (0 < s) { d_1c0cec = 1; break; }
            }
        } else {
            MSG(0x27000091);
        }
        break; }
    case 0x1fc: {
        signed char z = 0;
        if ((((int)d_1c0cf0 == (int)z) ? 1 : 0)) {
            if (f_0bf6f0(MBOX, 0x27000092) == 1) {
                short s = f_0dcf00(d_1c0004, 0x30, 1);
                if (0 < s) {
                    d_1c0cf0 = 1;
                    MSG(0x27000093);
                    f_0db9d0(d_1c0004, 2, 5);
                    break;
                }
            }
        } else {
            MSG(0x27000094);
        }
        break; }
    case 0x259: f_0603b0(0x32); break;
    case 0x25a: f_0603b0(0x33); break;
    case 0x25b: f_0603b0(0x34); break;
    case 0x2bd: MSG(0x27000095); break;
    case 0x2bf: f_0603b0(0x35); break;
    case 0x321: {
        signed char z = 0;
        if ((((int)d_1c0cf4 == (int)z) ? 1 : 0)) {
            if (f_0bf6f0(MBOX, 0x27000096) == 1) {
                short s = f_0dcf00(d_1c0004, 400, 1);
                if (0 < s) {
                    f_060740(0x324, 1);
                    d_1c0cf4 = 1;
                    break;
                }
            }
        } else {
            MSG(0x27000097);
        }
        break; }
    case 0x322: f_0603b0(0x36); break;
    case 0x323: MSG(0x27000098); break;
    case 0x385: f_12b8b0(p1); break;
    case 0x386: case 0x1f50: f_12ba70(p1); break;
    case 0x1b5a: case 0x1f42: f_05fa00(0x39, 0x1f42); break;
    case 0x1b61: case 0x1f49: f_05fa00(0x3a, 0x1f49); break;
    case 0x1b62: case 0x1f4a: NEWC(0x453, 0x3b, 0x1f4a) break;
    case 0x1b5f: case 0x1f47: f_05fa00(0x40, 0x1f47); break;
    case 0x1b60: case 0x1f48: f_12b010(p1); break;
    case 0x1b5b: case 0x1f43: f_05fa00(0x3d, 0x1f43); break;
    case 0x1b5e: case 0x1f46: f_05fa00(0x3f, 0x1f46); break;
    case 0x1b63: case 0x1f4b: NEWC(0x461, 0x41, 0x1f4b) break;
    case 0x1b5d: case 0x1f45: f_05fa00(0x3c, 0x1f45); break;
    case 0x1b5c: case 0x1f44: f_05fa00(0x3d, 0x1f44); break;
    default:
        r = 0;
        break;
    }
    return r;
}

//@ f_12a990
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an der Treppe nach unten (0x27000064), ob die Gruppe in die untere Etage des Magierturms
 *   zurückkehren möchte, und führt bei Bestätigung den Wechsel nach Ebene 0x12 (0x1533) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12a990(void)
{
    if (f_0bf6f0(MBOX, 0x27000064) == 1) f_0dd7f0(d_1c0004, 0x12, 0x1533);
}

//@ f_12aa30
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert als Zustandsautomat (state == 0 bis 12) die Begegnung und den verzweigten Dialog (0x27000065
 *   bis 0x27000078) mit der Figur im oberen Magierturm (mit Animation 0x2c0014), der entweder in den Kampf 8
 *   (mit Abenteuerpunkten 0x8030029) oder in den Rückzug der Gruppe nach Ebene 0x12 (0x1533) mündet.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12aa30(int p1)
{
    void open923(int,int);
    #pragma aux open923 "f_0bf6c0" modify exact [eax]
    int choose923(int,int,int,...);
    #pragma aux choose923 "f_0bf820" modify exact [eax]
    void close923(int);
    #pragma aux close923 "f_0bf680" modify exact []
    struct Lokal794 { static void flag(unsigned char v) { d_1c0ce8 = v; }
      static short menu(int box) {
        f_0bf6c0(box,5);
        short s = f_0bf820(box,0x2700006a,3,0x2700006b,0x2700006c,0x2700006d);
        f_0bf680(box); return s;
      }
    };
    OBJ;
    int done, state;
    if (!EQI(d_1c0ce8, 2)) {
        if (EQI(d_1c0ce8, 0)) {
            state = 0;
        } else {
            f_0bf6c0(MBOX, 5);
            S13e *q = new (mark(d_1a8c80, 0x177)) S13e;
            q = q ? (S13e *)f_0104b0((int)q, 0x2c0014, 0, 0) : q;
            f_0bf980(MBOX, (int)q, 0, 0x27000065, 0);
            if (q) operator delete((void *)f_010590((int)q, 0));
            f_0bf680(MBOX);
            state = 0xb;
        }
        do {
            done = 0;
            switch (state) {
            case 0: {
                Lokal794::flag(1);
                short u;
                do {
                    S13e *q = new (mark(d_1a8c80, 0x18e)) S13e;
                    q = q ? (S13e *)f_0104b0((int)q, 0x2c0014, 0, 0) : q;
                    u = f_0bf980(MBOX, (int)q, 0, 0x27000066, 2, 0x27000067, 0x27000068);
                    if (q) operator delete((void *)f_010590((int)q, 0));
                } while ((short)u == -1);
                switch (u) {
                case 1: state = 1; break;
                case 2: state = 2; break;
                }
                break; }
            case 1: case 9: state = 0xb; break;
            case 2: {
                OSET(f_038c40(d_1c0004));
                MSG(0x27000069);
                union OpenAddress923 { int all; unsigned short low; } openaddress923;
                openaddress923.all = MBOX;
                openaddress923.low = (openaddress923.low & 0) ? (unsigned short)0 : openaddress923.low;
                int box = openaddress923.all;
                int s;
                open923(box, 5);
                union Address923 { int all; unsigned short low; } address923;
                address923.all = MBOX;
                address923.low = (address923.low & 0) ? (unsigned short)0 : address923.low;
                s = choose923(address923.all, 0x2700006a, 3, 0x2700006b, 0x2700006c, 0x2700006d);
                close923(MBOX);
                switch ((short)s) {
                case 1: state = 3; break;
                case 2: state = 4; break;
                case 3: state = 10; break;
                case -1: state = 0xc; break;
                }
                break; }
            case 3: state = 0xb; MSG(0x2700006e); break;
            case 4: {
                short s = f_0bf820(MBOX, 0x27000070, 3, 0x27000071, 0x27000072, 0x27000073);
                switch (s) {
                case -1: state = 0xc; break;
                case 1: state = 5; break;
                case 2: state = 6; break;
                case 3: state = 9; break;
                }
                break; }
            case 5: state = 0xc; break;
            case 6: {
                short s = f_0bf820(MBOX, 0x27000074, 2, 0x27000075, 0x27000076);
                switch (s) {
                case -1: case 1: state = 7; break;
                case 2: state = 8; break;
                }
                break; }
            case 7:
                OSET(f_039660(d_1c0004, 0xd));
                state = 0xb;
                MSG(0x27000077);
                break;
            case 8:
                OSET(f_039660(d_1c0004, 0xd));
                state = 0xb;
                MSG(0x27000078);
                break;
            case 10: {
                short s = f_0bf820(MBOX, 0x2700006f, 3, 0x27000071, 0x27000072, 0x27000073);
                switch (s) {
                case -1: state = 0xc; break;
                case 1: state = 5; break;
                case 2: state = 6; break;
                case 3: state = 9; break;
                }
                break; }
            case 0xb:
                if (VCALL(8) == 0) {
                    d_1c0ce8 = 2;
                    f_057220((int)&d_1c2c00, 0x8030029, 0);
                }
                done = 1;
                break;
            case 0xc:
                done = 1;
                f_0dd7f0(d_1c0004, 0x12, 0x1533);
                break;
            }
        } while (!done);
    }
}

//@ f_12ae20
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x2b (oder fragt bei bereits geleertem Container über 0x27000079 nach, ob
 *   trotzdem hineingesehen werden soll).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12ae20(void) B67

//@ f_12aea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x2c (mit Rückfrage 0x2700007a, falls er leer ist).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12aea0(void) B68

//@ f_12af10
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x39 an der Position 0x1f42.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12af10(void)
{
    f_05fa00(0x39, 0x1f42);
}

//@ f_12af30
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumes (d_1c0cfc == 0) eine Beobachtungsmeldung (0x2700007b) mit dem
 *   im Talent 0x33 besten Helden aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12af30(void)
{
    OBJ;
    if (EQI(d_1c0cfc, 0)) {
        OSET(f_039320(d_1c0004, 0x33));
        MSG(0x2700007b);
        d_1c0cfc = 1;
    }
}

//@ f_12afa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Durchsuchen eines Raumes eine Meldung (0x2700007c) mit dem im Talent 0x23 besten Helden aus
 *   und lässt 10 Minuten Spielzeit verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12afa0(void)
{
    OBJ;
    OSET(f_039320(d_1c0004, 0x23));
    MSG(0x2700007c);
    f_125ed0((int)&d_1c2c44, 10);
}

//@ f_12b000
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalter-Funktion für das Ereignis 0xcb in tower1.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b000(void)
{
}

