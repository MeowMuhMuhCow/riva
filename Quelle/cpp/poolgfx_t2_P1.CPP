/* === Beschreibung (Katalog) ===
 * Einheit poolgfx_t2
 *
 * Diese Einheit (aus p:\riva\source\cpp\poolgfx.cpp, Teil 2) enthält die restlichen fünf Zeichenfunktionen für
 * die drei Statusanzeigen im oberen Kopfbereich des Pool- und Händlerfensters (Gesamtpreis/Vermögen,
 * Gesamtgewicht/Tragkraft sowie belegte Inventarplätze/freie Plätze) sowohl für den Einkaufs- als auch für den
 * Verkaufs- und Beutemodus.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 3/5 gleich (suche.py 30.10.2026, Basis poolgfx_t2_P1.CPP)
// poolgfx.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil t2, Code 0x0E1AB0-0x0E2520
#include <string.h>
struct B9 { char d[9]; };
int f_0de540(int p1);
int f_0de570(int p1, int p2);
int f_0de7e0(int p1);
short f_0de120(int p1);
int f_050580(int p1, int p2, int p3, int *p4, int *p5);


int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);


int f_05e320(int p1, int p2, int p3);
int f_05e340(int p1);
int f_0e9300(int p1, int p2, int p3);
int f_0e9510(int p1, int p2, int p3, int p4);
int f_0e9590(int p1, int p2);
int f_133fe0(int p1, int p2);
int f_148518(int p1, char *p2, int p3);
int f_040370(void *p1, int p2);
int f_09a040(int p1, int p2);
#pragma aux f_09a040 parm [eax edx] modify exact [eax]
void *f_145300(void *p, int c, unsigned n);              // memset
extern int d_1c0004;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c2be0[];
extern short d_1c3498[];
extern char d_1c38b0[];
extern const char d_1a63c4[];
#define A(x) ((int)&(x))
#define I(o) (*(int *)(p1 + (o)))
#define PQ(o) (*(int *)(*(int *)p1 + (o)))
#define PS(o) (*(short *)(*(int *)p1 + (o)))
#define IB(x) ((int)(x))
#define NEWB(l,u,v) int b = (int)new (mark(d_1a63c4, l)) B9; if (b != 0) b = ((int)(((RivaRasterImage*)(b))->f_0fac80( u, v)));
#define DEL(b) if (b != 0) operator delete(((void *)(((RivaRasterImage*)(b))->f_0fad20( 0))));
//@ f_0e1ab0
/* === Beschreibung (Katalog) ===
 * Zeichnet im Einkaufs-Modus das linke untere Statusfeld im Kopfbereich (Position 5, 15, Hintergrundsprite
 * 0x22005d Index 4), das das Gesamtgewicht der ausgewählten Waren (PQ(0x16)) im Verhältnis zur freien Tragkraft
 * der Gruppe (f_0de540) anzeigt und bei Annäherung oder Überschreitung der Tragkraft gelb (0xf9) bzw. rot (0xfd)
 * einfärbt.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e1ab0(int p1)
{
    extern int f_09a040(int c);
    short xa; short xe; short xd; short xb; short xg; short xc; short xf;
    xg = 5;
    xe = 0xf;
    xa = 0;
    xc = 0;
    xf = 0xfc;
    xb = 0;
    { int t_ = (int)(d_1c0004); xd = f_0de540(t_); }
    f_050580(A(d_1c2be0), 0x22005d, 4, (int *)&xa, (int *)&xc);
    int b = (int)new (mark(d_1a63c4, 0x40d)) B9;
    b = b ? ((int)(((RivaRasterImage*)(b))->f_0fac80( (short)xa, (short)xc))) : b;
    {
        f_04fef0(A(d_1c2be0), 0x22005d, (int)((RivaRasterImage*)(IB(b)))->f_0fb0b0(), 0, 4, 0, 0x140);
        ((RivaRasterImage*)(IB(b)))->f_0fade0((void *)( I(8)), 5, 0xf);
        DEL(b)
        f_05e320(A(d_1c38b0), 0xff, -1);
        f_0e9510(A(d_1c38b0), 0x220101ab, (short)xg, (short)xe);
        f_145300(d_1c21b4, 0, 0x80);
        if ((short)xd <= PQ(0x16)) xf = 0xfd;
        else if ((short)xd * 4 / 5 <= PQ(0x16)) xf = 0xf9;
        d_1c21b4[xb] = f_09a040((unsigned char)xf);
        f_148518(PQ(0x16), d_1c27a8, 10);
        strcat(d_1c21b4, d_1c27a8);
        xb = strlen(d_1c21b4);
        d_1c21b4[xb] = f_09a040(0xff);
        f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x220101a9);
        f_148518((short)xd, d_1c27a8, 10);
        strcat(d_1c21b4, d_1c27a8);
        int h = f_133fe0(A(d_1c3498), A(d_1c21b4));
        xg += (0x6f - f_0e9590(A(d_1c38b0), h));
        f_0e9510(A(d_1c38b0), h, (short)xg, (short)xe);
    }
    f_05e340(A(d_1c38b0));
}
//@ f_0e1d10
/* === Beschreibung (Katalog) ===
 * Zeichnet im Einkaufs-Modus das rechte untere Statusfeld im Kopfbereich (Position 125, 15, Hintergrundsprite
 * 0x22005d Index 5), das die Anzahl der für den Einkauf benötigten Inventarplätze (PS(0x10)) der Zahl der freien
 * Rucksackplätze der Gruppe (f_0de570) gegenüberstellt und farblich (grün, gelb oder rot) kennzeichnet.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e1d10(int p1)
{
    extern int f_09a040(int);
    short xa; short xc; short xd; short xf; short xb; short xg; short xe;
    xg = 0x7d;
    xe = 0xf;
    xa = 0;
    xc = 0;
    xf = 0xfc;
    d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt die Registerzuteilung wie im Original
    xb = 0;
    xd = 0;
    xd = f_0de570(d_1c0004, 0);
    f_050580(A(d_1c2be0), 0x22005d, 5, (int *)&xa, (int *)&xc);
    int b = (int)new (mark(d_1a63c4, 0x456)) B9;
    b = b ? ((int)(((RivaRasterImage*)(b))->f_0fac80( (short)xa, (short)xc))) : b;
    {
        f_04fef0(A(d_1c2be0), 0x22005d, (int)((RivaRasterImage*)(IB(b)))->f_0fb0b0(), 0, 5, 0, 0x140);
        ((RivaRasterImage*)(IB(b)))->f_0fade0((void *)( I(8)), 0x7d, 0xf);
        DEL(b)
        f_05e320(A(d_1c38b0), 0xff, -1);
        f_0e9510(A(d_1c38b0), 0x220101ac, (short)xg, (short)xe);
        f_145300(d_1c21b4, 0, 0x80);
        if (PS(0x10) >= (short)xd) xf = 0xfd;
        else if (PS(0x10) >= (short)xd * 4 / 5) xf = 0xf9;
        d_1c21b4[xb] = f_09a040((unsigned char)xf);
        f_148518(PS(0x10), d_1c27a8, 10);
        p1 = (p1 & 0) ? 0 : p1; // haelt die Registerzuteilung wie im Original
        strcat(d_1c21b4, d_1c27a8);
        xb = strlen(d_1c21b4);
        d_1c21b4[xb] = f_09a040(0xff);
        f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x220101a9);
        f_148518((short)xd, d_1c27a8, 10);
        strcat(d_1c21b4, d_1c27a8);
        int h = f_133fe0(A(d_1c3498), A(d_1c21b4));
        xg += (0x6f - f_0e9590(A(d_1c38b0), h));
        f_0e9510(A(d_1c38b0), h, (short)xg, (short)xe);
    }
    f_05e340(A(d_1c38b0));
}
//@ f_0e1f80
/* === Beschreibung (Katalog) ===
 * Zeichnet im Verkaufs- oder Beutelager-Modus das obere Statusfeld im Kopfbereich (Position 5, 3,
 * Hintergrundsprite 0x22005d Index 3), das den Erlös bzw. Wert der ausgewählten Gegenstände (PQ(0x12)) zusammen
 * mit dem aktuellen Gesamtvermögen der Heldengruppe (f_0de7e0) ohne Warnfärbung ausgibt.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e1f80(int p1)
{
    short xg; short xe; short xp; short xq;
    xg = 5;
    xe = 3;
    xq = xp = 0;
    f_050580(A(d_1c2be0), 0x22005d, 3, (int *)&xp, (int *)&xq);
    int b;
    b = (int)new (mark(d_1a63c4, 0x49c)) B9;
    b = b ? ((int)(((RivaRasterImage*)(b))->f_0fac80( (short)xp, (short)xq))) : b;
    f_04fef0(A(d_1c2be0), 0x22005d, (int)((RivaRasterImage*)(IB(b)))->f_0fb0b0(), 0, 3, 0, 0x140);
    ((RivaRasterImage*)(IB(b)))->f_0fade0((void *)( I(8)), 5, 3);
    DEL(b)
    f_05e320(A(d_1c38b0), 0xff, -1);
    f_0e9510(A(d_1c38b0), 0x220101aa, (short)xg, (short)xe);
    { void * t_ = (void *)(d_1c21b4); f_145300(t_, 0, 0x80); }
    f_040370(d_1c27a8, PQ(0x12));
    strcat(d_1c21b4, d_1c27a8);
    f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x220101a9);
    f_040370(d_1c27a8, f_0de7e0(d_1c0004));
    strcat(d_1c21b4, d_1c27a8);
    int h;
    h = f_133fe0(A(d_1c3498), A(d_1c21b4));
    xg += (0xe7 - f_0e9590(A(d_1c38b0), h));
    f_0e9510(A(d_1c38b0), h, (int)(short)(xg & 0xffff), (short)xe);
    f_05e340(A(d_1c38b0));
}
//@ f_0e2160
/* === Beschreibung (Katalog) ===
 * Zeichnet im Verkaufs- oder Beutelager-Modus das linke untere Statusfeld im Kopfbereich (Position 5, 15,
 * Hintergrundsprite 0x22005d Index 4), das das Gewicht der ausgewählten Gegenstände (PQ(0x16)) neben dem aktuell
 * getragenen Gesamtgewicht der Gruppe (f_0de120) darstellt.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2160(int p1)
{
    int v[4];
    v[3] = 5;
    v[0] = 0xf;
    v[2] = 0;
    v[1] = 0;
    f_050580(A(d_1c2be0), 0x22005d, 4, &v[2], &v[1]);
    int t = (int)new (mark(d_1a63c4, 0x4d4)) B9;
    int b = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( (short)v[2], (short)v[1]))) : t;
    f_04fef0(A(d_1c2be0), 0x22005d, (int)((RivaRasterImage*)(IB(b)))->f_0fb0b0(), 0, 4, 0, 0x140);
    ((RivaRasterImage*)(IB(b)))->f_0fade0((void *)( I(8)), 5, 0xf);
    DEL(b)
    int xe = (short)v[0];
    f_05e320(A(d_1c38b0), 0xff, -1);
    f_0e9510(A(d_1c38b0), 0x220101ab, (short)v[3], xe);
    f_145300(d_1c21b4, 0, 0x80);
    f_148518(PQ(0x16), d_1c27a8, 10);
    strcat(d_1c21b4, d_1c27a8);
    f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x220101a9);
    f_148518(f_0de120(d_1c0004), d_1c27a8, 10);
    strcat(d_1c21b4, d_1c27a8);
    int h = f_133fe0(A(d_1c3498), A(d_1c21b4));
    int delta = 0x6f - f_0e9590(A(d_1c38b0), h);
    int vg = v[3];
    vg += delta;
    f_0e9510(A(d_1c38b0), h, (short)vg, xe);
    v[3] = vg;
    f_05e340(A(d_1c38b0));
}
//@ f_0e2340
/* === Beschreibung (Katalog) ===
 * Zeichnet im Verkaufs- oder Beutelager-Modus das rechte untere Statusfeld im Kopfbereich (Position 125, 15,
 * Hintergrundsprite 0x22005d Index 5), das die Anzahl der ausgewählten Posten (PS(0x10)) im Verhältnis zur
 * Gesamtzahl der im Pool vorhandenen Gegenstände (PS(0xa)) anzeigt.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2340(int p1)
{
    short xg; short xe; short xq; short xp;
    xg = 0x7d;
    xe = 0xf;
    xp = 0;
    xq = 0;
    f_050580(A(d_1c2be0), 0x22005d, 5, (int *)&xp, (int *)&xq);
    int b = (int)new (mark(d_1a63c4, 0x50c)) B9;
    b = b ? ((int)(((RivaRasterImage*)(b))->f_0fac80( (short)xp, (short)xq))) : b;
    {
        f_04fef0(A(d_1c2be0), 0x22005d, (int)((RivaRasterImage*)(IB(b)))->f_0fb0b0(), 0, 5, 0, 0x140);
        ((RivaRasterImage*)(IB(b)))->f_0fade0((void *)( I(8)), 0x7d, 0xf);
        DEL(b)
        f_05e320(A(d_1c38b0), 0xff, -1);
        f_0e9510(A(d_1c38b0), 0x220101ac, (short)xg, (short)xe);
        f_145300(d_1c21b4, 0, 0x80);
        f_148518(PS(0x10), d_1c27a8, 10);
        strcat(d_1c21b4, d_1c27a8);
        f_0e9300(A(d_1c38b0), A(d_1c21b4), 0x220101a9);
        f_148518(PS(0xa), d_1c27a8, 10);
        strcat(d_1c21b4, d_1c27a8);
        int h = f_133fe0(A(d_1c3498), A(d_1c21b4));
        xg += (0x6f - f_0e9590(A(d_1c38b0), h));
        f_0e9510(A(d_1c38b0), h, (short)xg, (short)xe);
    }
    f_05e340(A(d_1c38b0));
}
