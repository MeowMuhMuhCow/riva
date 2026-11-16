// OPT -4r -oneatx -zp1 -s
// Astra650: Original 0d3860 bis 0d3a30 exklusiv.
// I9: aus gz_0d3860_REST.CPP uebernommen (Stufe-2-Stand), Marken 5 neu
// gz_0d3860.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xD3860-0xD39DA (Einheit A). Maus-Zustand, Punkt/Rechteck-Kopien.
struct S8 { int a, b; };
struct Pt { unsigned short a, b, c, d; Pt(unsigned short, unsigned short, unsigned short, unsigned short); Pt &operator=(const Pt &); };
struct Rect { unsigned short a, b, c, d; Rect(const Rect &); Rect &operator=(const Rect &); };
extern int d_1bf508;
extern short d_1bd756, d_1bd758, d_1bd75c, d_1bd75e, d_1bd760, d_1bd762, d_1bd766;
extern Pt d_1bf528;
extern signed char d_1bf4ef; extern short d_1bf4a2, d_1bf49e, d_1bf500; extern int d_1bf4a8, d_1bf54c, d_1bf548;
void f_0d2b70();
void f_0d39d0(S8 *, const S8 *);
#pragma aux f_0d39d0 "f_0d39d0"
Rect *f_0d39e0(Rect *, const Rect *);
#pragma aux f_0d39e0 "f_0d39e0"
//@ f_0d3860
int f_0d3860()
{
    return d_1bf508;
}
//@ f_0d3870
void f_0d3870()
{
    d_1bd75c = 0;
    d_1bd75e = 0;
    d_1bd760 = 0;
    d_1bd756 = 0;
    d_1bd758 = 0;
    d_1bd762 = 0;
    d_1bd766 = 0;
}
//@ f_0d38b0
Rect f_0d38b0()
{
    return *(const Rect *)&d_1bf528;
}
void f_0d38d0(Pt p);
#pragma aux f_0d38d0 "f_0d38d0"
//@ f_0d38d0
void f_0d38d0(Pt p) {
    if (d_1bf4ef != 1) {
        f_0d39d0((S8 *)&d_1bf528, (const S8 *)&p);
        d_1bf4a2 = d_1bf528.a; d_1bf4a8 = d_1bf528.c; d_1bf49e = 7; f_0d2b70();
        d_1bf4a2 = d_1bf528.b; d_1bf4a8 = d_1bf528.d; d_1bf49e = 8; f_0d2b70();
    }
}
//@ f_0d3950
void f_0d3950(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    f_0d38d0(Pt(a, b, c, d));
}
//@ f_0d3980
short f_0d3980()
{
    *(volatile int *)&d_1bf54c = 1;
    *(volatile int *)&d_1bf548 = 1;
    short r = *(volatile short *)&d_1bf500;
    --*(volatile short *)&d_1bf500;
    return r;
}
//@ f_0d39b0
void f_0d39b0()
{
    d_1bf54c = 0;
    d_1bf548 = 0;
}
//@ f_0d39c0
void f_0d39c0() {}
//@ f_0d39d0
void f_0d39d0(S8 *p, const S8 *q)
{
    *p = *q;
}