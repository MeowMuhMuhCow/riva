// OPT -4r -oneatx -zp1 -s
#include "R_FIX.H"
// Astra630: Zuschnitt 11e6d0-11e960 aus Quelle/cpp/SVGA1.CPP; erster Entwurf, Einbau separat pr�fen.
// svga.cpp Teil 1 (0x11E6D0-0x11E960): Grafikmodus und Bank-Tabelle. Bytegleich 21.10.2026 (Variantenmaschine, R40-R43, Teiler: d <<= 10)
char f_13dba0(unsigned short mode);
void f_13e140(short mode);
unsigned char f_13d740();
unsigned long f_13e680();
void f_13e690(long adr, int z, short a, short b, short c, short d, short e);
struct Vesa { char pad[6]; short gran; char pad2[8]; unsigned short pitch; };
extern Vesa *d_1c1108;
extern short d_1c0aa0[32];                               // Bank-Tabelle
extern unsigned char d_1c0a98;                           // VESA vorhanden
extern long d_1c0a9c;                                    // Modusnummer
extern unsigned long d_1ce4f8, d_1ce4fc;                 // Breite, Höhe
extern long d_1ce4f4;                                    // Zeilenlänge

//@ f_11e6d0
void f_11e6d0(short m)
{
    if (m == 0x13 || m == 3) {
        f_13e140(0x13);
    } else {
        if (f_13dba0(m)) f_13e140(m);
    }
}
//@ f_11e700
void f_11e700(short step)
{
    short i;
    for (i = 0; i < (short)32; i++) d_1c0aa0[i] = i * step;
}
//@ f_11e730
void __stdcall f_11e730(long x)
{
    short i;
    d_1c0a98 = f_13d740();
    for (i = 0; i < (short)32; i++) d_1c0aa0[i] = i;
}
//@ f_11e760
char __pascal f_11e760(unsigned w, long x)
{
    short i;
    int step;
    unsigned long W, Hh;
    
    if (w <= 800) {
        if (w <= 640) {
            if (w <= 320) { W = 320; Hh = 200; }
            else { W = 640; Hh = 480; }
        } else { W = 800; Hh = 600; }
    } else { W = 1024; Hh = 768; }
    d_1ce4f8 = W;
    d_1ce4fc = Hh;
    switch (W) {
    case 320:
        d_1c0a9c = 0x13;
        for (i = 0; i < (short)32; i++) d_1c0aa0[i] = i;
        d_1ce4f4 = 320;
        return 1;
    case 640: d_1c0a9c = 0x101; break;
    case 800: d_1c0a9c = 0x103; break;
    case 1024: d_1c0a9c = 0x105; break;
    default: return 0;
    }
    if (d_1c0a98 == 1) {
        char r = f_13dba0(d_1c0a9c);
#if FIX_R002   /* R002: Nullpruefung auf VESA-ModeInfo und BytesPerScanLine vor Division */
        unsigned long bps;
        if (!r || !d_1c1108) return 0;
        bps = f_13e680();
        if (!bps) return 0;
        unsigned long d = d_1c1108->gran;
        d <<= 10;
        step = d / bps;
#else
        unsigned long d = d_1c1108->gran;
        d <<= 10;
        step = d / f_13e680();
#endif
        for (i = 0; i < (short)32; i++) d_1c0aa0[i] = i * step;
        d_1ce4f4 = d_1c1108->pitch;
        return r;
    }
    return 0;
}
//@ f_11e8f0
void f_11e8f0() { f_13e140(d_1c0a9c); }
//@ f_11e900
void f_11e900() { f_13e140(3); }
//@ f_11e910
void __cdecl f_11e910(long p1, long p2, long p3, long p4, long p5, long p6, long p7, long p8)
{
    f_13e690(p1 + p2 + p3 * p6, 0, p7, p8, p4, p5, p6);
}
