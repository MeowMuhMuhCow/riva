/* === Beschreibung (Katalog) ===
 * Einheit fz_15689d_t2b (0x15B710 - 0x15B740)
 *
 * Überblick
 * Diese kleine Einheit enthält eine Kapazitätsprüfungs- und Indexerweiterungsfunktion (f_15b710) für
 * 4-Byte-Elementvektoren (RivaIntVector).
 === Ende Beschreibung === */
// OPT -5r -oneatxc -zp1 -s
// P3 10/22 gleich (suche.py 25.10.2026, Basis fz_15689d_t2_P1.CPP)
// P1 1/19 gleich
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 2 gleich (vorher 2), Rest 5052 (vorher 5053)
// fz_15689d_t2 (Schatten ueber Riva, Attic 1996) - Pass 1, Helfer B, Code 0x158128-0x15B770
#pragma inline_depth(0)
#include <string.h>
#include "RIVAMEM.H"




typedef unsigned char u8;
#include "RIVATEXT.H"


typedef RivaByteVector V32;


#define ENS(vp, idx, esz, grow) { unsigned q_ = (unsigned)(vp)->d + (idx) * (esz); if ((unsigned)(vp)->e <= q_) { q_ += (esz); (vp)->e = (char *)q_; if ((unsigned)(vp)->c <= q_) grow(vp); } }
#define POP(v, dst) { if ((int)(v).e - (int)(v).b < (v).mn) f_15b770(&(v)); (v).e -= 4; (dst) = *(int *)(v).e; }
#define PUSH(v, val) { if ((v).c <= (v).e) f_15b790(&(v)); *(int *)(v).e = (val); (v).e += 4; }
#define HI16(o, off) (*(int *)((char *)&(o) + (off)) >> 16)
#define CNT32(v) (((v)->e - (v)->b) / 32)
#define CNT4(v) (((v)->e - (v)->b) / 4)
#define CNT1C(v) (((v)->e - (v)->b) / 28)
#define SKIPF(sp_, cc_) { char *t_ = f_1583f8(sp_, p2, cc_); *p1 = t_; t_ = f_158420(t_, p2); *p1 = t_; }

extern int d_1a9bd4[];
extern int d_1a9bd8[];
extern char d_1a9bcc[];
extern char d_1a9bd0[];
extern char *d_1aeba8[];
extern u8 d_1bbfdc[];
extern int d_1bde24;
extern int d_1bde28;
extern int d_1bde2c;
extern int d_1bde30;
extern int d_1cddb0;
extern int d_1cddb4;
extern int d_1cddb8;
extern V32 *d_1cddbc;
extern char *d_1cddc0;
extern int d_1cddc4;
extern int d_1cddc8;
extern RivaRgb d_1cddcc;
extern RivaRgb d_1cddd0;
extern RivaRgb d_1cddd4;
extern RivaRgb d_1cddd8;
extern RivaRgb d_1cdddc;
extern int d_1cdde8;
extern int d_1cddec;
extern int d_1cddf0;
extern int d_1cddf4;
extern int d_1cddf8;
extern char *d_1cddfc[];
extern int d_1cdf8c;
extern int d_1cdf90;
extern RivaRgb d_1cdf94;
extern int d_1cdf98;
extern const char d_1b94de[];
extern const char d_1b94e4[];
extern const char d_1b94e7[];
extern const char d_1b94f3[];
extern const char d_1b94f9[];
extern const char d_1b94ff[];
extern const char d_1b9508[];
extern const char d_1b950f[];
extern const char d_1b9516[];
extern const char d_1b951c[];
extern const char d_1b9522[];
extern const char d_1b952c[];
extern const char d_1b9531[];
extern const char d_1b9536[];
extern const char d_1b953d[];
extern const char d_1b9545[];
extern const char d_1b954c[];
extern const char d_1b9552[];
extern const char d_1b9556[];
extern const char d_1b955d[];

void *f_014ad0(int n);
char *f_014af0(int n);
int f_14d717(const char *a, const char *b);
int f_14d5c9(const char *s);
int f_14572e(char *buf, const char *fmt, ...);
int f_15ead2(const char *s, const char *fmt, ...);
int f_09db80(const char *p, int *w, int *h);
void f_09dbe0(int dx, int dy);
void f_09dc00(int *r);
int f_09dc50(int bmp, int x, int y, int m);
void f_09e100(int x1, int y1, int x2, int y2, void *col);
void f_09e140(int x, int y, int w, int h, void *col);
void f_09e1b0();
int *f_09e220(int *out, const char *s, int n);
void f_09e3f0(int x, int y, const char *s, int n, void *col);
void f_156c38();
void f_156de4(RivaTextLayout *c);
void f_15713c(RivaTextLayout *c, int v);
void f_157158(RivaTextLayout *c, int v);
void f_15717c(RivaTextLayout *c, V32 *l);
void f_1574ac(V32 *l, int x1, int y1, int x2, int y2, void *col);
void f_157614(V32 *l, int x, int y);
void f_15794c(RivaTextLayout *c, V32 *l, char *s, int n);
void f_15b770(RivaByteVector *v);
void f_15b790(RivaByteVector *v);
void f_15b8d0(RivaByteVector *v);
void f_15b990(RivaByteVector *v, int n);
void f_15bad0(RivaByteVector *v);
void f_15bc00(RivaByteVector *v);
void f_15bcd0(RivaByteVector *v, int n);
void f_15be60(RivaByteVector *v);
V32 *f_15bfa0(V32 *p, int q);
void f_15bfe0(int p, int q);
void f_15c140(V32 *v, int i);
void f_15c1a0(V32 *v);
void f_15c300(V32 *v);
void *f_15c330(V32 *v); void *f_15c330(V32 *v, int);
void f_15c3f0(V32 *v, int n);

//@ f_15b710
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt sicher, dass der 4-Byte-Elementvektor p mindestens bis zum Index i reicht,
 *   verschiebt bei Bedarf den Endzeiger p->c auf p->a + i + 1 und vergrößert den Speicherblock über f_15b790,
 *   falls die Kapazitätsgrenze p->d erreicht wird.
 * - Eingaben: Zeiger p auf den Integer-Vektor und angeforderter Elementindex i.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - q: Berechnete Elementadresse p->a + i.
 === Ende Beschreibung === */
struct E4 { int w; };
struct VE4 { E4 *a, *b, *c, *d; int cap, th, th4; };
void f_15b710(VE4 *p, int i)
{
    i <<= 2;
    E4 *q = (E4 *)((char *)p->a + i);
    if (p->c <= q)
{
    q++;
    p->c = q;
    if (p->d <= q) f_15b790((RivaByteVector *)(p));
}
}

