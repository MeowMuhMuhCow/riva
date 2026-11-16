/* === Beschreibung (Katalog) ===
 * Einheit fi_opt (0x07ED80-0x082350)
 *
 * Überblick
 * Die Einheit fi_opt (im Original fi_opt.cpp) steuert das Aktions- und Optionenmenü des aktiven Helden im
 * rundenbasierten taktischen Kampf sowie den interaktiven Tabellen-Dialog für die Computerkampf-Einstellungen
 * (Autokampf-Konfiguration der Gruppenmitglieder).
 === Ende Beschreibung === */
// P3 9/18 gleich (suche.py 30.10.2026, Basis fi_opt_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra700: Originalreihenfolge; ein Restbefehl weniger, kein schlechterer Nachbar.
// P3 9/18 gleich (suche.py 26.10.2026, Basis fi_opt_P1.CPP)
// E1 Entwurf 4/18 gleich
// fi_opt.cpp (Schatten ueber Riva, Attic 1996) - Entwurf E1, Code 0x07ED80-0x082350
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
void f_014710(void *p);                                  // 0x014710 (operator delete)
// --- Daten ---
extern const char d_1a2004[];
extern short d_1a2022, d_1a2024;
struct HS { short x1, y1, x2, y2, id; };
extern HS d_1a2028[];
extern char d_1a280c[];
extern char *d_1a34e0;
extern short d_1a215e, d_1a2160, d_1a2162, d_1a2164;
extern short d_1bd75a, d_1bd766;
extern int d_1bd7c8, d_1bd7cc, d_1bd7d0, d_1bd7d4, d_1bd7d8, d_1bd7dc, d_1bd7e0, d_1bd7e4, d_1bd7e8, d_1bd7ec, d_1bd7f0, d_1bd7f4, d_1bd7f8, d_1bd7fc;
extern int d_1bd800, d_1bd804, d_1bd808, d_1bd80c, d_1bd810, d_1bd814, d_1bd818, d_1bd81c, d_1bd820, d_1bd824, d_1bd828, d_1bd82c, d_1bd830;
extern int d_1bd834, d_1bd838, d_1bd83c, d_1bd840, d_1bd844, d_1bd848, d_1bd84c, d_1bd850, d_1bd854, d_1bd858;
extern unsigned short d_1bd85c[6];
extern char *d_1bd868;
extern int d_1bd86c[8];
extern signed char d_1bd88c[];
extern short d_1bd894;
struct Img9 { char b[9]; };
extern Img9 *d_1bd898[7][4];
extern short d_1bd908, d_1bd90a, d_1bd90c, d_1bd910, d_1bd920;
extern char d_1bd928;
extern int d_1bda54, d_1bdbe4;
extern char *d_1bc8f0;
extern void *d_1bf514;
extern int d_1c0004;
extern short d_1c21a4;
extern char d_1b6f68[];
extern char d_1c21b4[], d_1c27a8[], d_1c2c64[], d_1c38b0[], d_1c3498[], d_1c349c[], d_1c3870[];
extern int *d_1c2c40;
// --- Aufgerufene ---
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
signed char f_042400(int p1);
char f_0424d0(int p1);
char f_0424e0(int p1);
char f_0425a0(int p1);
char f_0425f0(int p1);
char f_042600(int p1);
char f_042640(int p1);
int f_042650(int p1, int p2);
int f_042740(int p1, int p2);
char f_042750(int p1);
int f_042760(int p1, int p2);
signed char f_042770(int p1);
int f_042780(int p1, int p2);
signed char f_042790(int p1);
int f_0427a0(int p1, int p2);
signed char f_0427b0(int p1);
int f_042800(int p1, int p2);
signed char f_042810(int p1);
char f_042880(int p1);
short f_0429a0(int p1);
signed char *f_0429c0(int p1, int p2);
int f_042a10(int p1);
short f_042a60(int p1, int p2);
short f_042ac0(int p1, int p2);
int f_042bb0(int p1, int p2);
short f_043170(int p1);
int f_0432c0(int p1, int p2);
int f_0433c0(int p1, int p2);
signed char f_043410(int p1);
unsigned char f_043470(int p1);
int f_043e00(int p1, int p2);
signed char f_043e10(int p1);
int f_030cb0(int p1, int p2);
int f_05e320(void *q, int c, int v);
int f_05e340(void *q);
short f_05e820(void *q, int i);
int f_05e830(void *q, int a, int b);
int f_068f40();
int f_069460();
int f_06fb20(char *p1);
int f_070440(char *p1);
int f_0757f0(char *p1);
int f_0773b0(int p1);
int f_077400(char *p1);
int f_07b5e0(char *p1, int p2);
int f_07d6a0(char *p1, int p2);
int f_07eba0(char *p1, int p2, int p3);
char f_074b40(char *p1, int p2, int p3, int p4, int p5, int p6);
int f_082350(char *p1, int p2, short *p3, short *p4);
short f_082460(char *p1, int p2, int p3, int p4);
short f_0828d0(char *p1, int p2);
short f_082920(char *p1, int p2, int p3, int p4);
short f_082d30(char *p1, int p2, int p3, int p4);
int f_083060(char *p1, int p2);
int f_0832b0(char *p1, int p2);
int f_083680(char *p1, int p2);
int f_0839d0(char *p1, int p2, int p3, int p4);
int f_083dc0(char *p1, int p2);
short f_083f80(char *p1, int p2);
int f_09a080(int p1, void *p2);
int f_09a7d0(char *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09ac80(char *p1, int p2, int p3);
int f_09ade0(char *p1, int p2, int p3);
int f_09aed0(int p1);
int f_0a7950(int p1);
int f_0a7990(int p1);
int f_0bf6f0(void *m, int code);
int f_0bf730(void *m, int code);
short f_0bf820(void *m, ...);
int f_0c0000(void *m, int v);
int f_0c0010(void *m, int v);
short f_0c0020(void *m, int v);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0d49b0(int p1);
int f_0dbfb0(int p1, void *p2);
short f_0dc020(int p1, int p2);
int f_0e9300(void *q, void *s, int id);
int f_0e93f0(void *q, void *s, int id);
int f_0e9660(void *q, void *s, int x, int y);
Img9 *f_0fac80(Img9 *p, short w, int h);
void *f_0fad20(Img9 *p, int fl);
int f_0fade0(Img9 *p, char *scr, int x, int y);
int f_0fafb0(Img9 *p, char *scr, int x, int y);
int f_133fe0(void *a, void *s);
void f_145300(void *p, int v, int n);
int f_1481a0(void *r, char *scr, int x, int y, int w, int h, int c);
int f_149360(int p1, void *p2);
int f_149eb4(int, ...);
struct Ctx {                                             // 0x3C Bytes, Stapelobjekt 0x125400/0x1254A0
    int x0; int *p04; int p08; int *p0c; int *p10; short *p14; int p18; int p1c; short *p20; char pad[0x18];
    Ctx() { f_125400(this, d_1c349c, d_1c3870, d_1c3498); }
    ~Ctx() { f_1254a0(this, 0); }
};
struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; } }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
struct Rc { short a, b, c, d; };
#define BLK(slot, id, col) { t = strchr(t, 0) + 1; c.p10[1] = (id); f_0e93f0(d_1c38b0, t, f_09a080((col), t)); (slot) = f_133fe0(d_1c3498, t); }
int f_0817a0(int p1);
int f_085d60(char *p1, int p2, int p3, int p4);
// --- Inline-Zwillinge (Rumpf identisch mit der Funktion gleicher Adresse) ---
void f_080900();
void f_080cd0();
inline signed char h_080730(HS *t, short id)
{
    signed char r = -1;
    short i = 0;
    while (t[i].id != -1 && r == -1) {
        if (id == t[i].id) r = i;
        i++;
    }
    return r;
}
inline void h_080770(short x, short y, short w, short h)
{
    short n = h * 2 + w * 2 - 4; char *b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
    short i;
    d_1bd868 = b;
    memcpy(b, d_1a34e0 + y * 320 + x, w);
    b += w;
    memcpy(b, d_1a34e0 + (h + y - 1) * 320 + x, w);
    b += w;
    char *s1 = d_1a34e0 + (y + 1) * 320 + x; for (i = 0; i < h - 2; i++) b[i] = s1[i * 320];
    b += h - 2;
    char *s2 = d_1a34e0 + (y + 1) * 320 + x + w - 1; for (i = 0; i < h - 2; i++) b[i] = s2[i * 320];
    d_1a215e = x;
    d_1a2160 = y;
    d_1a2162 = w;
    d_1a2164 = h;
}
inline void h_080aa0(short x, short y, short w, short h, short col)
{
    Rc r;
    r.a = 0;
    r.b = 0;
    r.c = 0x13f;
    r.d = 199;
    MG g;
    f_080900();
    h_080770(x, y, w, h);
    f_1481a0(&r, d_1a34e0, x, y, w, h, (signed char)col);
}
inline void h_080f80()
{
    short i, j;
    for (i = 0; i < 7; i++)
        for (j = 0; j < 4; j++)
            if (d_1bd898[i][j]) delete (char *)f_0fad20(d_1bd898[i][j], 0);
}
inline void h_080fd0()
{
    short y8 = 0;
    short i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            short x1 = d_1bd85c[j];
            short x2 = d_1bd85c[j + 1];
            short y = d_1a2024 + 0x20;
            Img9 *im = new (mark(d_1a2004, 0x461)) Img9;
            if (im) im = f_0fac80(im, (short)((x2 - (x1 - 1)) - 3), 8);
            d_1bd898[i][j] = im;
            f_0fafb0(im, d_1a34e0, (short)(x1 - 1), (short)(y8 + y));
        }
        y8 += 8;
    }
}
inline void h_0810b0()
{
    if ((unsigned short)d_1bd908 < 4 && (unsigned short)d_1bd90a < 7)
        f_0fade0(d_1bd898[d_1bd90a][d_1bd908], d_1a34e0, (short)(d_1bd85c[d_1bd908] - 1), (short)(d_1a2024 + 0x20 + d_1bd90a * 8));
}
inline void h_081310(Ctx *c)
{
    int tx = f_133fe0(d_1c3498, d_1b6f68);
    char ch;
    short s;
    int t;
    unsigned char col;
    unsigned short i;
    {
        MG g;
        f_09ade0(d_1a34e0, 0, 0);
    }
    f_0e93f0(d_1c38b0, d_1c21b4, 0x1010093);
    ch = h_080730(d_1a2028, 0x81);
    s = ch;
    if (ch != -1) {
        d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
        d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
    }
    ch = h_080730(d_1a2028, 0x83);
    s = ch;
    if (ch != -1) {
        d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
        d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
    }
    for (i = 0; i < d_1bd894; i++) {
        if (d_1bd88c[i] >= 0) {
            t = d_1bd86c[d_1bd88c[i]];
            c->p04[1] = t;
            c->p10[1] = c->p10[2] = c->p10[3] = c->p10[4] = tx;
            if (f_0d49b0(t) == 0) {
                col = 0xe7;
                f_0e93f0(d_1c38b0, d_1c27a8, 0x1010094);
                if (f_0424d0(t) || f_0424e0(t) || f_0425f0(t) || f_0425a0(t)) col = 0xf9;
                c->p10[1] = f_133fe0(d_1c3498, d_1c27a8);
                f_0e9300(d_1c38b0, d_1c21b4, f_09a080(col, d_1c21b4));
            } else f_0e9300(d_1c38b0, d_1c21b4, 0x1010094);
        }
    }
    f_0e93f0(d_1c38b0, d_1c27a8, 0x1010098);
    c->p10[1] = f_133fe0(d_1c3498, d_1c27a8);
    f_0e9300(d_1c38b0, d_1c21b4, f_09a080(0xfc, d_1c21b4));
    {
        MG g;
        f_0e9660(d_1c38b0, d_1c21b4, d_1a2022, d_1a2024);
    }
}
inline void h_081610()
{
    int n, r;
    do {
        n = d_1bd894 + 1;
        r = (d_1bd90a - 1 + n) % n;
        if ((short)r == d_1bd894) break;
        d_1bd90a = r;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[r]]) == 0);
    d_1bd90a = r;
    f_080cd0();
}
inline void h_081680()
{
    int n, r;
    do {
        n = d_1bd894 + 1;
        r = (d_1bd90a + 1) % n;
        d_1bd90a = r;
        if (d_1bd90a == d_1bd894) break;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[d_1bd90a]]) == 0);
    f_080cd0();
}
inline void h_0816f0()
{
    int v;
    if (d_1bd90a == d_1bd894) v = d_1bd908 + 2;
    else v = d_1bd908 + 3;
    d_1bd908 = v % 4;
    f_080cd0();
}
inline void h_081740()
{
    int v;
    if (d_1bd90a == d_1bd894) v = d_1bd908 + 2;
    else v = d_1bd908 + 1;
    d_1bd908 = v % 4;
    f_080cd0();
}
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_07ed80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert die 6 Spalten-Koordinaten d_1bd85c[0..5] (relativ zum Tabellenursprung
 *   d_1a2022) sowie sämtliche 30 Hotspot-Rechtecke d_1a2028[0..29] (7 Heldenzeilen zu je 4 Spalten plus 2
 *   Schaltflächen in der Fußzeile) für den Computerkampf-Konfigurationsdialog.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd85c (unsigned short[6]): X-Koordinaten der Spaltengrenzen der Autokampf-Tabelle.
 *   - d_1a2028 (HS[]): Hotspot-Array für die 7x4 Tabellenfelder und die unteren Bedienknöpfe.
 === Ende Beschreibung === */
void f_07ed80()
{
    d_1bd85c[0] = d_1a2022 + 0x64;
    d_1bd85c[1] = d_1a2022 + 0xa3;
    d_1bd85c[2] = d_1a2022 + 0xc5;
    d_1bd85c[3] = d_1a2022 + 0xeb;
    d_1bd85c[4] = d_1a2022 + 0x110;
    d_1bd85c[5] = d_1a2022 + 0x12c;
    d_1a2028[0].x1 = d_1bd85c[0];
    d_1a2028[0].y1 = d_1a2024 + 0x20;
    d_1a2028[0].x2 = d_1bd85c[1];
    d_1a2028[0].y2 = d_1a2024 + 0x27;
    d_1a2028[1].x1 = d_1bd85c[1];
    d_1a2028[1].y1 = d_1a2028[0].y1;
    d_1a2028[1].x2 = d_1bd85c[2];
    d_1a2028[1].y2 = d_1a2028[0].y2;
    d_1a2028[2].x1 = d_1bd85c[2];
    d_1a2028[2].y1 = d_1a2028[1].y1;
    d_1a2028[2].x2 = d_1bd85c[3];
    d_1a2028[2].y2 = d_1a2028[1].y2;
    d_1a2028[3].x1 = d_1bd85c[3];
    d_1a2028[3].y1 = d_1a2028[2].y1;
    d_1a2028[3].x2 = d_1bd85c[4];
    d_1a2028[3].y2 = d_1a2028[2].y2;
    d_1a2028[4].x1 = d_1bd85c[0];
    d_1a2028[4].y1 = d_1a2024 + 0x28;
    d_1a2028[4].x2 = d_1bd85c[1];
    d_1a2028[4].y2 = d_1a2024 + 0x2f;
    d_1a2028[5].x1 = d_1bd85c[1];
    d_1a2028[5].y1 = d_1a2028[4].y1;
    d_1a2028[5].x2 = d_1bd85c[2];
    d_1a2028[5].y2 = d_1a2028[4].y2;
    d_1a2028[6].x1 = d_1bd85c[2];
    d_1a2028[6].y1 = d_1a2028[5].y1;
    d_1a2028[6].x2 = d_1bd85c[3];
    d_1a2028[6].y2 = d_1a2028[5].y2;
    d_1a2028[7].x1 = d_1bd85c[3];
    d_1a2028[7].y1 = d_1a2028[6].y1;
    d_1a2028[7].x2 = d_1bd85c[4];
    d_1a2028[7].y2 = d_1a2028[6].y2;
    d_1a2028[8].x1 = d_1bd85c[0];
    d_1a2028[8].y1 = d_1a2024 + 0x30;
    d_1a2028[8].x2 = d_1bd85c[1];
    d_1a2028[8].y2 = d_1a2024 + 0x37;
    d_1a2028[9].x1 = d_1bd85c[1];
    d_1a2028[9].y1 = d_1a2028[8].y1;
    d_1a2028[9].x2 = d_1bd85c[2];
    d_1a2028[9].y2 = d_1a2028[8].y2;
    d_1a2028[10].x1 = d_1bd85c[2];
    d_1a2028[10].y1 = d_1a2028[9].y1;
    d_1a2028[10].x2 = d_1bd85c[3];
    d_1a2028[10].y2 = d_1a2028[9].y2;
    d_1a2028[11].x1 = d_1bd85c[3];
    d_1a2028[11].y1 = d_1a2028[10].y1;
    d_1a2028[11].x2 = d_1bd85c[4];
    d_1a2028[11].y2 = d_1a2028[10].y2;
    d_1a2028[12].x1 = d_1bd85c[0];
    d_1a2028[12].y1 = d_1a2024 + 0x38;
    d_1a2028[12].x2 = d_1bd85c[1];
    d_1a2028[12].y2 = d_1a2024 + 0x3f;
    d_1a2028[13].x1 = d_1bd85c[1];
    d_1a2028[13].y1 = d_1a2028[12].y1;
    d_1a2028[13].x2 = d_1bd85c[2];
    d_1a2028[13].y2 = d_1a2028[12].y2;
    d_1a2028[14].x1 = d_1bd85c[2];
    d_1a2028[14].y1 = d_1a2028[13].y1;
    d_1a2028[14].x2 = d_1bd85c[3];
    d_1a2028[14].y2 = d_1a2028[13].y2;
    d_1a2028[15].x1 = d_1bd85c[3];
    d_1a2028[15].y1 = d_1a2028[14].y1;
    d_1a2028[15].x2 = d_1bd85c[4];
    d_1a2028[15].y2 = d_1a2028[14].y2;
    d_1a2028[16].x1 = d_1bd85c[0];
    d_1a2028[16].y1 = d_1a2024 + 0x40;
    d_1a2028[16].x2 = d_1bd85c[1];
    d_1a2028[16].y2 = d_1a2024 + 0x47;
    d_1a2028[17].x1 = d_1bd85c[1];
    d_1a2028[17].y1 = d_1a2028[16].y1;
    d_1a2028[17].x2 = d_1bd85c[2];
    d_1a2028[17].y2 = d_1a2028[16].y2;
    d_1a2028[18].x1 = d_1bd85c[2];
    d_1a2028[18].y1 = d_1a2028[17].y1;
    d_1a2028[18].x2 = d_1bd85c[3];
    d_1a2028[18].y2 = d_1a2028[17].y2;
    d_1a2028[19].x1 = d_1bd85c[3];
    d_1a2028[19].y1 = d_1a2028[18].y1;
    d_1a2028[19].x2 = d_1bd85c[4];
    d_1a2028[19].y2 = d_1a2028[18].y2;
    d_1a2028[20].x1 = d_1bd85c[0];
    d_1a2028[20].y1 = d_1a2024 + 0x48;
    d_1a2028[20].x2 = d_1bd85c[1];
    d_1a2028[20].y2 = d_1a2024 + 0x4f;
    d_1a2028[21].x1 = d_1bd85c[1];
    d_1a2028[21].y1 = d_1a2028[20].y1;
    d_1a2028[21].x2 = d_1bd85c[2];
    d_1a2028[21].y2 = d_1a2028[20].y2;
    d_1a2028[22].x1 = d_1bd85c[2];
    d_1a2028[22].y1 = d_1a2028[21].y1;
    d_1a2028[22].x2 = d_1bd85c[3];
    d_1a2028[22].y2 = d_1a2028[21].y2;
    d_1a2028[23].x1 = d_1bd85c[3];
    d_1a2028[23].y1 = d_1a2028[22].y1;
    d_1a2028[23].x2 = d_1bd85c[4];
    d_1a2028[23].y2 = d_1a2028[22].y2;
    d_1a2028[24].x1 = d_1bd85c[0];
    d_1a2028[24].y1 = d_1a2024 + 0x50;
    d_1a2028[24].x2 = d_1bd85c[1];
    d_1a2028[24].y2 = d_1a2024 + 0x57;
    d_1a2028[25].x1 = d_1bd85c[1];
    d_1a2028[25].y1 = d_1a2028[24].y1;
    d_1a2028[25].x2 = d_1bd85c[2];
    d_1a2028[25].y2 = d_1a2028[24].y2;
    d_1a2028[26].x1 = d_1bd85c[2];
    d_1a2028[26].y1 = d_1a2028[25].y1;
    d_1a2028[26].x2 = d_1bd85c[3];
    d_1a2028[26].y2 = d_1a2028[25].y2;
    d_1a2028[27].x1 = d_1bd85c[3];
    d_1a2028[27].y1 = d_1a2028[26].y1;
    d_1a2028[27].x2 = d_1bd85c[4];
    d_1a2028[27].y2 = d_1a2028[26].y2;
    d_1a2028[28].x1 = d_1bd85c[0];
    d_1a2028[28].y1 = d_1a2024 + 0x58;
    d_1a2028[28].x2 = d_1bd85c[2];
    d_1a2028[28].y2 = d_1a2024 + 0x5f;
    d_1a2028[29].x1 = d_1bd85c[2];
    d_1a2028[29].y1 = d_1a2028[28].y1;
    d_1a2028[29].x2 = d_1bd85c[4];
    d_1a2028[29].y2 = d_1a2028[28].y2;
}
//@ f_07f3a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bereitet vor dem Öffnen des Kampf-Aktionsmenüs für den aktiven Helden p2 alle Menütexte
 *   und deren Aktivierungsfarben vor (0xe7 = ausgegraut/nicht verfügbar, 0xf9 = hervorgehoben/Warnung,
 *   Standardfarbe = wählbar). Prüft dafür die verbleibenden Aktionspunkte (f_043410(p2)), ob der Held zaubern
 *   kann und Astralenergie besitzt, ob Flucht im aktuellen Kampf erlaubt ist (d_1bd858), ob die Waffe
 *   nachgeladen oder gewechselt werden kann, ob der Held überlastet ist (f_043170), und formatiert die aktuellen
 *   Computerkampf-Zustandstexte in die globalen Text-Slots d_1bd7c8 bis d_1bd854.
 * - Eingaben: char *p1 (Zeiger auf die Kampf-Steuerstruktur), int p2 (Zeiger auf den aktuell am Zug befindlichen
 *   Helden).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd7c8..d_1bd854 (int): Vorbereitete Text-Handles für das Haupt- und Untermenü der Kampfaktionen.
 *   - d_1bd858 (int): Flag, ob die Aktion "Fliehen" in diesem Kampf zulässig ist (1 = erlaubt, 0 = gesperrt).
 === Ende Beschreibung === */
void f_07f3a0(char *p1, int p2)
{
    extern int f_09a080_one(int);
#pragma aux f_09a080_one "f_09a080" parm [eax] value [eax]
#undef BLK
#define BLK(slot, id, col) { t = strchr(t, 0) + 1; c.p10[1] = (id); f_0e93f0(d_1c38b0, t, f_09a080_one((col))); (slot) = f_133fe0(d_1c3498, t); }
    Ctx c;
    char *t = d_1c21b4;
    short i;

    c.p14[1] = f_043410(p2);
    f_0e93f0(d_1c38b0, t, 0x1010013);
    d_1bd7c8 = f_133fe0(d_1c3498, t);
    d_1bd7cc = 0x1010014;

    if (f_043410(p2) >= 3) {
        d_1bd7d0 = 0x1010015;
    } else {
        BLK(d_1bd7d0, 0x1010015, 0xe7)
    }
    if (f_043410(p2) >= 5 && f_042a10(p2) && f_0429a0(p2)) {
        d_1bd7d4 = 0x1010017;
    } else {
        BLK(d_1bd7d4, 0x1010017, 0xe7)
    }

    if ((short)f_149360(*(short *)(p1 + 0x1ea), d_1a280c) != -1 ||
        d_1bd920 == 2 || d_1bd920 == 3 || d_1bd920 == 4 ||
        d_1bd920 == 5 || d_1bd920 == 7 || d_1bd920 == 1) {
        BLK(d_1bd7e4, 0x1010023, 0xe7)
        d_1bd858 = 0;
    } else {
        d_1bd858 = 1;
        d_1bd7e4 = 0x1010023;
    }

    i = f_042a60(p2, 3);
    if (f_043410(p2) < 2 || !f_042880(p2)) {
        BLK(d_1bd7e8, 0x1010019, 0xe7)
    }
    else {
        if (!f_0a7990(d_1c2c40[i]) ||
            (f_0a7990(d_1c2c40[i]) && f_042bb0(p2, 3))) {
            BLK(d_1bd7e8, 0x1010019, 0xf9)
        } else {
            d_1bd7e8 = 0x1010019;
        }
    }

    t = strchr(t, 0) + 1;
    if (f_042a60(p2, 0xc)) {
        c.p0c[1] = d_1c2c40[f_042a60(p2, 0xc)];
        if (f_0a7950(d_1c2c40[f_042a60(p2, 0xc)]) &&
            f_042ac0(p2, 0xc) > 1) {
            c.p20[1] = f_042ac0(p2, 0xc);
        } else {
            c.p20[1] = 1;
        }
        f_0e93f0(d_1c38b0, d_1c27a8, 0x1010055);
    }

    if (f_043410(p2) >= 3) {
        if (f_042a60(p2, 0xc)) {
            strcpy(t, d_1c27a8);
        } else {
            c.p10[1] = 0x1010018;
            f_0e93f0(d_1c38b0, t, f_09a080_one(0xe7));
        }
    } else {
        if (f_042a60(p2, 0xc)) {
            c.p10[1] = f_133fe0(d_1c3498, d_1c27a8);
            f_0e93f0(d_1c38b0, t, f_09a080_one(0xe7));
        } else {
            c.p10[1] = 0x1010018;
            f_0e93f0(d_1c38b0, t, f_09a080_one(0xe7));
        }
    }
    d_1bd848 = f_133fe0(d_1c3498, t);

    if (!f_042880(p2)) {
        BLK(d_1bd84c, 0x1010029, 0xe7)
    } else {
        if (f_043170(p2) >= f_0429c0(p2, 6)[1] * 0x6e) {
            BLK(d_1bd84c, 0x1010029, 0xf9)
        } else {
            d_1bd84c = 0x1010029;
        }
    }

    if (f_043410(p2) >= 2 && f_042880(p2)) {
        d_1bd850 = 0x1010011;
    } else {
        BLK(d_1bd850, 0x1010011, 0xe7)
    }
    int t_523 = f_043410(p2);
    if (t_523 >= 3) {
        d_1bd854 = 0x1010079;
    } else {
        BLK(d_1bd854, 0x1010079, 0xe7)
    }

    t = strchr(t, 0) + 1;
    c.p04[1] = p2;
    f_0e93f0(d_1c38b0, t, f_042790(p2) == 0 ? 0x101007c :
        (f_042790(p2) == 1 ? 0x101007d : 0x101007e));
    f_0e9300(d_1c38b0, t, 0x101007f);
    d_1bd810 = f_133fe0(d_1c3498, t);

    if (f_042a10(p2)) {
        d_1bd834 = 0x1010083;
    } else {
        BLK(d_1bd834, 0x1010083, 0xe7)
    }

    t = strchr(t, 0) + 1;
    c.p04[1] = p2;
    f_0e93f0(d_1c38b0, t, f_042770(p2) == 0 ? 0x1010086 :
        (f_042770(p2) == 1 ? 0x1010085 : 0x1010084));
    f_0e9300(d_1c38b0, t, 0x1010087);
    d_1bd838 = f_133fe0(d_1c3498, t);

    t = strchr(t, 0) + 1;
    c.p04[1] = p2;
    f_0e93f0(d_1c38b0, t, f_0427b0(p2) == 0 ? 0x101008c :
        (f_0427b0(p2) == 1 ? 0x101008d : 0x101008e));
    f_0e9300(d_1c38b0, t, 0x101008f);
    d_1bd824 = f_133fe0(d_1c3498, t);

    t = strchr(t, 0) + 1;
    c.p10[1] = f_042810(p2) == 4 ? 0x1010017 :
        (f_042810(p2) == 2 || f_042810(p2) == 0x10) ? 0x1010015 :
        (f_042810(p2) == 1 || f_042810(p2) == 5) ? 0x10100a0 : 0x1010016;
    f_0e93f0(d_1c38b0, d_1c27a8, 0x101001c);

    if (f_042810(p2) == 1 || f_042810(p2) == 5) {
        c.p10[1] = f_133fe0(d_1c3498, d_1c27a8);
        f_0e93f0(d_1c38b0, t, f_09a080_one(0xe7));
    } else {
        strcpy(t, d_1c27a8);
    }

    d_1bd7f0 = f_133fe0(d_1c3498, t);
    d_1bd7cc = 0x1010014;
    d_1bd7d8 = 0x101001a;
    d_1bd7dc = 0x1010057;
    d_1bd7e0 = 0x101002e;
    d_1bd7ec = 0x1010016;
    d_1bd7f4 = 0x101001b;
    d_1bd7f8 = 0x1010056;
    d_1bd7fc = 0x1010034;
    d_1bd800 = 0x1010036;
    d_1bd804 = 0x1010035;
    d_1bd808 = 0x1010037;
    d_1bd80c = 0x101007b;
    d_1bd814 = 0x1010080;
    d_1bd818 = 0x1010081;
    d_1bd81c = 0x1010082;
    d_1bd83c = 0x101008a;
    d_1bd840 = 0x1010089;
    d_1bd844 = 0x1010088;
    d_1bd820 = 0x101008b;
    d_1bd828 = 0x1010090;
    d_1bd82c = 0x1010091;
    d_1bd830 = 0x1010092;
}
#undef BLK
//@ f_07fe00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hauptschleife für den Kamporundenzug eines einzelnen Helden p2 auf dem Kampffeld (p3, p4).
 *   Prüft zunächst, ob der Held noch Aktionspunkte hat (f_043410(p2) > 0), führt bei gesetztem Autokampf-Flag
 *   (f_042640) oder Kampfunfähigkeit/Panik automatisch den KI-Zug (f_074b40 / f_07d6a0 / f_085d60) aus und
 *   öffnet andernfalls das interaktive Kampf-Popupmenü (f_0bf820). Von dort aus verzweigt die Funktion in
 *   Bewegung (f_082350), Angriff (f_082460), Zaubern (f_082920), Gegenstand benutzen (f_082d30), Waffenwechsel
 *   (f_083060), Nachladen (f_0832b0), Charakterbogen (f_083680), Computerkampf-Dialog (f_0817a0), Gepäck/Ablegen
 *   (f_083dc0 / f_0839d0), Kampfabfrage/Ende (0x101002f) oder Zug beenden (f_083f80), bis der Zug abgeschlossen
 *   ist (done != 0).
 * - Eingaben: char *p1 (Kampf-Steuerstruktur), int p2 (aktiver Held), short p3, short p4 (Kachel-Koordinaten des
 *   Helden auf dem Kampfgitter).
 * - Rückgabewert: short (der zuletzt eingestellte Kampfaktionscode f_042810(p2) des Helden).
 * - Wichtige Variablen:
 *   - d_1bd910 (short), d_1bd90c (short): Kampfstatus- und Abbruchflags.
 === Ende Beschreibung === */
short f_07fe00(char *p1, int p2, short p3, short p4)
{
    short sel;
    short b;
    short k;
    short done = 0;
    short r;
    short a;
    short sv;
    char object[0x3c];
    f_125400(object, d_1c349c, d_1c3870, d_1c3498);
    do {
        if (f_043410(p2) <= 0) break;
        if (d_1bd928) f_069460();
        f_077400(p1);
        if (p1[0x3dd]) {
            int proceed = 1;
            if (d_1bd928) {
                if (f_042400(p2)) proceed = 0;
                else f_070440(p1);
            }
            if (proceed != 0) {
                f_030cb0(d_1c0004, 0);
                for (k = 0; k < 7; ++k) p1[k + 0x3d7] = 0;
            }
        }
        if (p1[0x3d7 + f_0dc020(d_1c0004, p2)] != (char)0 && d_1bd928 == (char)0) {
            f_042740(p2, 0);
            p1[0x3d7 + f_0dc020(d_1c0004, p2)] = 0;
        }
        if (p1[0x293] != (char)0xff) {
            f_07eba0(p1 + 0x39, (unsigned char)p1[0x293], 0);
            p1[0x293] = (char)0xff;
        }
        f_07b5e0(p1, f_043470(p2));
        f_0757f0(p1);
        if (f_042640(p2)) {
            if (f_042600(p2) || f_0424e0(p2)) {
                f_042650(p2, 0);
            } else if (f_074b40(p1, p2, p3, p4, 7, 1)) {
                f_07d6a0(p1, p2);
            }
            done = 1;
        } else if (f_0425a0(p2) || f_042400(p2) || f_042750(p2)) {
            f_042800(p2, 0xd);
            f_0433c0(p2, -1);
            f_0432c0(p2, 0xff);
            if (f_043410(p2) >= 3) f_085d60(p1, p2, p3, p4);
            done = 1;
        } else {
            sel = r = -1;
            { int s3 = p3; a = (p4 + s3 < 0xf) ? 0x5a : -0x5a; }
            b = (p3 + p4 < 0xf) ? -0x1e : 0x1e;
            f_0c0000(d_1c2c64, *(short *)&a);
            f_0c0010(d_1c2c64, b);
            sv = f_0c0020(d_1c2c64, 4);
            do {
                f_07f3a0(p1, p2);
                r = f_0bf820(d_1c2c64, d_1bd7c8, 10, d_1bd7cc, d_1bd7d0, d_1bd7d4, d_1bd7d8, d_1bd7dc, d_1bd7e0, d_1bd7e4, d_1bd7e8, d_1bd7ec, d_1bd7f0);
                if (r == 5) {
                    r = f_0bf820(d_1c2c64, d_1bd7c8, 5, d_1bd7f4, d_1bd7f8, d_1bd80c, d_1bd820, d_1bd834);
                    if (r != -1) {
                        if (r == 1) {
                            sel = 10;
                        } else if (r == 2) {
                            int id;
                            if (f_043e10(p2) == 0) id = d_1bd800;
                            else if (f_043e10(p2) == 1) id = d_1bd804;
                            else id = d_1bd808;
                            ((Ctx *)object)->p10[1] = id;
                            r = f_0bf820(d_1c2c64, d_1bd7fc, 3, d_1bd800, d_1bd804, d_1bd808);
                            if (r != -1) f_043e00(p2, (signed char)(r - 1));
                            r = -2;
                        } else if (r == 3) {
                            int count810;
                            r = f_0bf820(d_1c2c64, d_1bd810, (count810 = 3), d_1bd814, d_1bd818, d_1bd81c);
                        if (r != -1) f_042780(p2, (signed char)(r - 1));
                            r = -2;
                        } else if (r == 4) {
                            int count824;
                            r = f_0bf820(d_1c2c64, d_1bd824, (count824 = 3), d_1bd828, d_1bd82c, d_1bd830);
                        if (r != -1) f_0427a0(p2, (signed char)(r - 1));
                            r = -2;
                        } else if (r == 5) {
                            if (f_042a10(p2) == 0) f_0bf730(d_1c2c64, 0x1010038);
                            else {
                                int count838;
                            r = f_0bf820(d_1c2c64, d_1bd838, (count838 = 3), d_1bd83c, d_1bd840, d_1bd844);
                            if (r != -1) f_042760(p2, (signed char)(r - 1));
                            }
                            r = -2;
                        }
                    } else r = -2;
                } else if (r == 4) {
                    short r2 = f_0c0020(d_1c2c64, 5);
                    r = f_0bf820(d_1c2c64, d_1bd7c8, 4, d_1bd848, d_1bd84c, d_1bd850, d_1bd854);
                    { char rt = d_1bd928; d_1bd928 = rt; } // KRUECKE: codeloser Byte-Global-Roundtrip (Slotsortierung)
                    f_0c0020(d_1c2c64, r2);
                    if (r == -1) r = -2;
                    else if (r == 1) {
                        sel = 5;
                    }
                    else { short choice = r == 2 ? 6 : r == 3 ? 9 : 7; sel = choice; }
                } else if (r != -1) {
                    sel = r == 1 ? 1 : r == 2 ? 2 : r == 3 ? 4 :
                          r == 6 ? 11 : r == 7 ? (d_1bd858 ? 14 : -1) :
                          r == 8 ? 8 : r == 9 ? 3 : 12;
                    if (sel == -1) r = -2;
                }
                d_1bd928 = 0;
            } while (r < 0);
            f_0c0020(d_1c2c64, sv);
            if (sel != 1) {
                int chg;
                short k;
                char *entry;
                chg = 0;
                k = 0;
                while ((entry = p1 + k)[0x295] != (char)0xff) {
                    f_07eba0(p1 + 0x39, (unsigned char)entry[0x295], 0);
                    entry[0x295] = (char)0xff;
                    chg = 1;
                    ++k;
                }
                if (chg != 0) {
                    d_1bda54 = 1;
                    f_0757f0(p1);
                }
            }
            if (sel == 1) {
                int chg;
                short k;
                f_082350(p1, p2, &p3, &p4);
                chg = 0;
                k = 0;
                while (p1[k + 0x295] != (char)0xff) {
                    f_07eba0(p1 + 0x39, (unsigned char)p1[k + 0x295], 0);
                    p1[k + 0x295] = (char)0xff;
                    ++k;
                    chg = 1;
                }
                if (chg != 0) {
                    d_1bda54 = 1;
                    f_0757f0(p1);
                }
            } else if (sel == 2) done = f_082460(p1, p2, p3, p4);
            else if (sel == 3) done = f_0828d0(p1, p2);
            else if (sel == 4) done = f_082920(p1, p2, p3, p4);
            else if (sel == 5) done = f_082d30(p1, p2, p3, p4);
            else if (sel == 9) f_083060(p1, p2);
            else if (sel == 8) f_0832b0(p1, p2);
            else if (sel == 10) f_083680(p1, p2);
            else if (sel == 0xe) {
                d_1bd910 = 0;
                r = f_0bf820(d_1c2c64, 0x101003e, 3, 0x101003f, 0x1010040, 0x1010041);
                if (r == 1) {
                    if (f_0817a0(p2) != 0) {
                        f_042740(p2, 1);
                        d_1bd910 = 1;
                        if (f_0773b0(d_1c0004) != 0) {
                            d_1bd75a = 0;
                            for (k = 0; k < 7; ++k) p1[k + 0x3d7] = 0;
                        }
                    }
                } else if (r > 1) {
                    if (f_0817a0(0) != 0) {
                        f_030cb0(d_1c0004, 1);
                        for (k = 0; k < 7; ++k) p1[k + 0x3d7] = 0;
                        if (r == 2) d_1bd910 = 1;
                        else f_06fb20(p1);
                    } else d_1bd910 = 1;
                } else d_1bd910 = 1;
            } else if (sel == 6) f_083dc0(p1, p2);
            else if (sel == 7) f_0839d0(p1, p2, p3, p4);
            else if (sel == 0xb) {
                d_1bd910 = 0;
                if (f_0bf6f0(d_1c2c64, 0x101002f) == 1) {
                    done = 1;
                    d_1bd90c = 0;
                    d_1c21a4 = 4;
                } else d_1bd910 = 1;
            } else if (sel == 0xc) done = f_083f80(p1, p2);
            { char rt3 = d_1bd928; d_1bd928 = rt3; } // KRUECKE: codeloser Byte-Global-Roundtrip (Slotsortierung)
            f_0c0000(d_1c2c64, 0);
            f_0c0010(d_1c2c64, 0);
            }
        }
    while (done == (short)0);
    {
        // KRUECKE: 52 berechnete Aliasansichten ordnen nur die Stapelplaetze.
        (void)*(unsigned int *)(object + 0); (void)*(unsigned short *)(object + 1); (void)*(unsigned int *)(object + 2);
        (void)*(unsigned int *)(object + 3); (void)*(unsigned char *)(object + 4); (void)*(unsigned short *)(object + 5);
        (void)*(unsigned char *)(object + 6); (void)*(unsigned int *)(object + 7); (void)*(unsigned int *)(object + 8);
        (void)*(unsigned char *)(object + 9); (void)*(unsigned char *)(object + 10); (void)*(unsigned short *)(object + 11);
        (void)*(unsigned char *)(object + 12); (void)*(unsigned short *)(object + 13); (void)*(unsigned char *)(object + 14);
        (void)*(unsigned char *)(object + 15); (void)*(unsigned char *)(object + 16); (void)*(unsigned int *)(object + 17);
        (void)*(unsigned int *)(object + 18); (void)*(unsigned char *)(object + 19); (void)*(unsigned short *)(object + 20);
        (void)*(unsigned short *)(object + 21); (void)*(unsigned int *)(object + 22); (void)*(unsigned int *)(object + 23);
        (void)*(unsigned char *)(object + 24); (void)*(unsigned int *)(object + 25); (void)*(unsigned short *)(object + 26);
        (void)*(unsigned short *)(object + 27); (void)*(unsigned char *)(object + 28); (void)*(unsigned int *)(object + 29);
        (void)*(unsigned char *)(object + 30); (void)*(unsigned short *)(object + 31); (void)*(unsigned int *)(object + 32);
        (void)*(unsigned int *)(object + 33); (void)*(unsigned char *)(object + 34); (void)*(unsigned int *)(object + 35);
        (void)*(unsigned short *)(object + 36); (void)*(unsigned int *)(object + 37); (void)*(unsigned char *)(object + 38);
        (void)*(unsigned short *)(object + 39); (void)*(unsigned char *)(object + 40); (void)*(unsigned short *)(object + 41);
        (void)*(unsigned short *)(object + 42); (void)*(unsigned short *)(object + 43); (void)*(unsigned short *)(object + 44);
        (void)*(unsigned int *)(object + 45); (void)*(unsigned short *)(object + 46); (void)*(unsigned short *)(object + 47);
        (void)*(unsigned int *)(object + 48); (void)*(unsigned int *)(object + 49); (void)*(unsigned char *)(object + 50);
        (void)*(unsigned int *)(object + 51);
        short result = f_042810(p2);
        f_1254a0(object, 0);
        return result;
    }
}
//@ f_080730
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in einem mit id == -1 terminierten Hotspot-Array t nach dem Eintrag mit der Kennung
 *   id und gibt dessen Array-Index zurück.
 * - Eingaben: HS *t (Hotspot-Tabelle), short id (gesuchte Hotspot-ID).
 * - Rückgabewert: signed char (Index des gefundenen Hotspots oder -1, falls nicht vorhanden).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
signed char f_080730(HS *t, short id)
{
    signed char r = -1;
    short i = 0;
    while (t[i].id != -1 && r == -1) {
        if (id == t[i].id) r = i;
        i++;
    }
    return r;
}
//@ f_080770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sichert die Pixel unter den vier Kanten eines Rechteckrahmens (x, y, w, h) aus dem
 *   Bildschirmpuffer d_1a34e0 in einen neu reservierten Puffer d_1bd868 der Größe 2*w + 2*h - 4 Bytes und merkt
 *   sich die Rechteckkoordinaten in d_1a215e..d_1a2164, bevor ein Auswahlrahmen darüber gezeichnet wird.
 * - Eingaben: short x, short y, short w, short h (Rechteckposition und -größe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd868 (char *): Puffer mit den gesicherten Rahmenpixeln.
 *   - d_1a215e, d_1a2160, d_1a2162, d_1a2164 (short): Gespeicherte Koordinaten x, y, w, h des gesicherten
 *     Rahmens.
 === Ende Beschreibung === */
void f_080770(short x, short y, short w, short h)
{
    short n = w * 2 + h * 2 - 4;
    char *b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
    short i;
    char *p;
    d_1bd868 = b;
    p = d_1a34e0 + y * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (h + y - 1) * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (y + 1) * 320 + x;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    b += h - 2;
    p = d_1a34e0 + (y + 1) * 320 + x + w - 1;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    d_1a215e = x;
    d_1a2160 = y;
    d_1a2162 = w;
    d_1a2164 = h;
}
//@ f_080900
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt die zuvor von f_080770 gesicherten vier Rahmenkanten aus d_1bd868 an der Position
 *   (d_1a215e, d_1a2160, d_1a2162, d_1a2164) im Bildschirmpuffer d_1a34e0 wieder her, setzt die Koordinaten auf
 *   -1 und gibt den Puffer d_1bd868 frei.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd868 (char *).
 === Ende Beschreibung === */
void f_080900()
{
    short i;
    char *p;
    short x, y, w, h;
    char *b;
    if (d_1bd868 == 0) return;
    b = d_1bd868;
    x = d_1a215e;
    y = d_1a2160;
    w = d_1a2162;
    h = d_1a2164;
    p = d_1a34e0 + y * 320 + x;
    memcpy(p, b, w);
    b += w;
    p = d_1a34e0 + (h + y - 1) * 320 + x;
    memcpy(p, b, w);
    b += w;
    p = d_1a34e0 + (y + 1) * 320 + x;
    for (i = 0; i < h - 2; i++) p[i * 320] = b[i];
    b += h - 2;
    p = d_1a34e0 + (y + 1) * 320 + x + w - 1;
    for (i = 0; i < h - 2; i++) p[i * 320] = b[i];
    d_1a215e = -1;
    d_1a2160 = -1;
    d_1a2162 = -1;
    d_1a2164 = -1;
    delete d_1bd868;
    d_1bd868 = 0;
}

//@ f_080aa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entfernt zunächst einen eventuell bestehenden Auswahlrahmen über f_080900(), sichert dann
 *   den Hintergrund unter dem neuen Rahmen (x, y, w, h) in d_1bd868 und zeichnet den neuen Rechteckrahmen in der
 *   Farbe col über f_1481a0 in den Bildschirmpuffer d_1a34e0.
 * - Eingaben: short x, short y, short w, short h, short col (Rahmenfarbe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd868 (char *), d_1a34e0 (char *).
 === Ende Beschreibung === */
// DeepSeek 2311, Blind-Neubau aus dem Original-ASM: Speicherteil als Inline-Helfer mit
// EINEM wiederverwendeten Quellzeiger char *p (wie DeepSeek 2309 bei f_080770), n = w*2+h*2-4.
inline void h_080aa0save(short x, short y, short w, short h)
{
    short n = w * 2 + h * 2 - 4; char *b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
    short i;
    char *p;
    d_1bd868 = b;
    p = d_1a34e0 + y * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (h + y - 1) * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (y + 1) * 320 + x;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    b += h - 2;
    p = d_1a34e0 + (y + 1) * 320 + x + w - 1;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    d_1a215e = x;
    d_1a2160 = y;
    d_1a2162 = w;
    d_1a2164 = h;
}
void f_080aa0(short x, short y, short w, short h, short col)
{
    Rc r;
    r.a = 0;
    r.b = 0;
    r.c = 0x13f;
    r.d = 199;
    MG g;
    f_080900();
    {
        short n;
        char *b;
        short i;
        char *p;
        short ix, iy, iw, ih;
        ix = x;
        iy = y;
        iw = w;
        ih = h;
        n = iw * 2 + ih * 2 - 4;
        b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
        d_1bd868 = b;
        p = d_1a34e0 + iy * 320 + ix;
        memcpy(b, p, iw);
        b += iw;
        p = d_1a34e0 + (ih + iy - 1) * 320 + ix;
        memcpy(b, p, iw);
        b += iw;
        p = d_1a34e0 + (iy + 1) * 320 + ix;
        for (i = 0; i < ih - 2; i++) b[i] = p[i * 320];
        b += ih - 2;
        p = d_1a34e0 + (iy + 1) * 320 + ix + iw - 1;
        for (i = 0; i < ih - 2; i++) b[i] = p[i * 320];
        d_1a215e = ix;
        d_1a2160 = iy;
        d_1a2162 = iw;
        d_1a2164 = ih;
    }
    f_1481a0(&r, d_1a34e0, x, y, w, h, (signed char)col);
}


//@ f_080cd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet die Bildschirmkoordinaten (x, y, w, h) der aktuell im Computerkampf-Dialog
 *   ausgewählten Zelle (Zeile d_1bd90a, Spalte d_1bd908) - bzw. in der untersten Zeile (d_1bd90a >= d_1bd894)
 *   einer der beiden doppelt breiten Bestätigungs-/Abbruch-Schaltflächen - und zeichnet dort über f_080aa0 einen
 *   weißen Auswahlrahmen (0xff).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd90a (short): Aktuell ausgewählte Tabellenzeile (0..d_1bd894).
 *   - d_1bd908 (short): Aktuell ausgewählte Tabellenspalte (0..3).
 *   - d_1bd894 (short): Anzahl der angezeigten Heldenzeilen.
 === Ende Beschreibung === */
static inline void save1118c(short x, short y, short w, short h)
{
    short n = w * 2 + h * 2 - 4; char *b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
    short i;
    char *p;
    d_1bd868 = b;
    p = d_1a34e0 + y * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (h + y - 1) * 320 + x;
    memcpy(b, p, w);
    b += w;
    p = d_1a34e0 + (y + 1) * 320 + x;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    b += h - 2;
    p = d_1a34e0 + (y + 1) * 320 + x + w - 1;
    for (i = 0; i < h - 2; i++) b[i] = p[i * 320];
    d_1a215e = x;
    d_1a2160 = y;
    d_1a2162 = w;
    d_1a2164 = h;
}
static inline void draw1118c(short x, short y, short w, short h, short col)
{
    Rc r;
    r.a = 0;
    r.b = 0;
    r.c = 0x13f;
    r.d = 199;
    MG g;
    f_080900();
    {
        short n;
        char *b;
        short i;
        char *p;
        short iw, ix, ih, iy;
        ix = 0; // KRUECKE toter Startwert vor Innenkopie
        ix = x;
        iy = 0; // KRUECKE toter Startwert vor Innenkopie
        iy = 1; // KRUECKE toter Startwert vor Innenkopie
        iy = 2; // KRUECKE toter Startwert vor Innenkopie
        iy = 3; // KRUECKE toter Startwert vor Innenkopie
        iy = y;
        iw = 0; // KRUECKE toter Startwert vor Innenkopie
        iw = 1; // KRUECKE toter Startwert vor Innenkopie
        iw = 2; // KRUECKE toter Startwert vor Innenkopie
        iw = w;
        ih = 0; // KRUECKE toter Startwert vor Innenkopie
        ih = h;
        n = iw * 2 + ih * 2 - 4;
        b = (char *)new (mark(d_1a2004, 0x3d3)) char[n];
        d_1bd868 = b;
        { int row_a = iy * 320; int base_a = (int)d_1a34e0; p = (char *)(row_a + base_a + ix); }
        memcpy(b, p, iw);
        b += iw;
        p = d_1a34e0 + (ih + iy - 1) * 320 + ix;
        memcpy(b, p, iw);
        b += iw;
        p = d_1a34e0 + (iy + 1) * 320 + ix;
        for (i = 0; i < ih - 2; i++) b[i] = p[i * 320];
        b += ih - 2;
        (void)*(unsigned short *)((unsigned char *)&g + 0); (void)*(float *)((unsigned char *)&g + 0); (void)*(unsigned char *)((unsigned char *)&r + 3); (void)*(unsigned char *)((unsigned char *)&r + 0); (void)*(unsigned char *)((unsigned char *)&g + 3); (void)*(unsigned char *)((unsigned char *)&r + 4); (void)*(unsigned short *)((unsigned char *)&g + 1); (void)*(unsigned int *)((unsigned char *)&r + 1); (void)*(unsigned short *)((unsigned char *)&r + 3); (void)*(unsigned char *)((unsigned char *)&g + 2); (void)*(unsigned char *)((unsigned char *)&r + 1); (void)*(float *)((unsigned char *)&r + 0); (void)*(unsigned int *)((unsigned char *)&r + 0); (void)*(unsigned char *)((unsigned char *)&r + 6); (void)*(unsigned int *)((unsigned char *)&r + 3); (void)*(unsigned char *)((unsigned char *)&g + 0); /* KRUECKE berechnete Aliasfolge */
        { int row_a = (iy + 1) * 320; int base_a = (int)d_1a34e0; p = (char *)(ix + (row_a + base_a) + iw - 1); }
        for (i = 0; i < ih - 2; i++) { b[i] = p[i * 320]; w = (w & 0) ? (short)0 : w; /* KRUECKE Pixel-Web */ }
        d_1a215e = ix;
        d_1a2160 = iy;
        d_1a2162 = iw;
        d_1a2164 = ih;
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock
        i = 0; // KRUECKE toter Schlusswert im Speicherblock

        p = 0; // KRUECKE toter Schlusswert im Speicherblock
        p = 0; // KRUECKE toter Schlusswert im Speicherblock
        p = 0; // KRUECKE toter Schlusswert im Speicherblock

        b = 0; // KRUECKE toter Schlusswert im Speicherblock
        b = 0; // KRUECKE toter Schlusswert im Speicherblock
        b = 0; // KRUECKE toter Schlusswert im Speicherblock
        b = 0; // KRUECKE toter Schlusswert im Speicherblock

    }
    f_1481a0(&r, d_1a34e0, x, y, w, h, (signed char)col);
    x = 0; // KRUECKE toter Parameter-Schlusswert
    x = 1; // KRUECKE toter Parameter-Schlusswert
    x = 2; // KRUECKE toter Parameter-Schlusswert
    x = 3; // KRUECKE toter Parameter-Schlusswert
    x = 4; // KRUECKE toter Parameter-Schlusswert
    x = 5; // KRUECKE toter Parameter-Schlusswert
    x = 6; // KRUECKE toter Parameter-Schlusswert
    x = 7; // KRUECKE toter Parameter-Schlusswert
    y = 0; // KRUECKE toter Parameter-Schlusswert
    y = 1; // KRUECKE toter Parameter-Schlusswert
    y = 2; // KRUECKE toter Parameter-Schlusswert
    y = 3; // KRUECKE toter Parameter-Schlusswert
    y = 4; // KRUECKE toter Parameter-Schlusswert
    y = 5; // KRUECKE toter Parameter-Schlusswert
    y = 6; // KRUECKE toter Parameter-Schlusswert
    y = 7; // KRUECKE toter Parameter-Schlusswert
    y = 8; // KRUECKE toter Parameter-Schlusswert
    w = 0; // KRUECKE toter Parameter-Schlusswert
    w = 1; // KRUECKE toter Parameter-Schlusswert
    h = 0; // KRUECKE toter Parameter-Schlusswert
    h = 1; // KRUECKE toter Parameter-Schlusswert
    h = 2; // KRUECKE toter Parameter-Schlusswert
    h = 3; // KRUECKE toter Parameter-Schlusswert
    h = 4; // KRUECKE toter Parameter-Schlusswert
    short cc = col; col = cc; // KRUECKE Umlauf nach letztem Gebrauch: col in der Vorliste vor iW
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert
    col = 0; // KRUECKE toter Farb-Schlusswert

}
void f_080cd0()
{
    int zz; // KRUECKE haelt f_080cd0 ueber der Inline-Schwelle
    zz = d_1bd908 + 1;
    short h, w, y, x;
    short a = d_1a2024 + 32;
    a = d_1bd90a * 8 + a;
    if (d_1bd90a < d_1bd894) {
        y = a; // KRUECKE toter Auswahlbasis-Leser
        y = a; // KRUECKE toter Auswahlbasis-Leser
        y = a; // KRUECKE toter Auswahlbasis-Leser
        y = a - 1;
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = a; // KRUECKE toter Auswahlbasis-Leser
        x = 0; // KRUECKE toter Startwert vor Zweigdefinition
        x = d_1bd85c[d_1bd908] - 1;
        h = 10;
        w = a; // KRUECKE toter Auswahlbasis-Leser
        w = a; // KRUECKE toter Auswahlbasis-Leser
        w = a; // KRUECKE toter Auswahlbasis-Leser
        w = a; // KRUECKE toter Auswahlbasis-Leser
        w = d_1bd85c[d_1bd908 + 1] - x - 3;
    } else {
        int k = d_1bd908 & ~1;
        y = a + 7;
        x = d_1bd85c[k] - 1;
        h = 10;
        w = d_1bd85c[k + 2] - x - 3;
    }
    (void)(unsigned char)h; // KRUECKE registergebundene Hauptlokal-Aliase
    draw1118c(x, y, w, h, 0xff);
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert
    a = 0; // KRUECKE toter Auswahlbasis-Schlusswert

}


//@ f_080f80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt alle 7x4 Hintergrund-Sprites im Array d_1bd898[0..6][0..3] des Computerkampf-Dialogs
 *   wieder frei.
 * - Eingaben: Keine.
 * - Rückgabewert: int (Schleifenendwert 4).
 * - Wichtige Variablen: d_1bd898 (Img9 *[7][4]).
 === Ende Beschreibung === */
int f_080f80()
{
    int t;
    short i;
    short j;
    t = 0;
    i = 0;
    for (; (t = i) < 7; i++) {
        j = 0;
        for (; (t = j) < 4; j++) {
            Img9 *p = d_1bd898[i][t];
            if (p != 0) delete (char *)f_0fad20(p, 0);
        }
    }
    return t;
}
//@ f_080fd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Legt für jede der 7x4 Tabellenzellen des Computerkampf-Dialogs ein 8 Pixel hohes
 *   RivaRasterImage-Objekt in d_1bd898[i][j] an und schneidet damit den leeren Tabellenhintergrund der
 *   jeweiligen Zelle aus dem Bildschirmpuffer d_1a34e0 aus, damit einzelne Zellen später beim Umschalten schnell
 *   restauriert werden können.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd898 (Img9 *[7][4]).
 === Ende Beschreibung === */
void f_080fd0()
{
    short i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            short y = d_1a2024 + 32 + i * 8;
            short x = d_1bd85c[j] - 1;
            short w = d_1bd85c[j + 1] - x;
            void *tag = mark(d_1a2004, 0x461);
            w -= 3;
            Img9 *im = new (tag) Img9;
            im = im ? f_0fac80(im, w, 8) : im;
            int off = i * 16 + j * 4;
            f_0fafb0((*(Img9 **)((char *)d_1bd898 + off) = im, im), d_1a34e0, x, y);
        }
    }
}
//@ f_0810b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt den gesicherten leeren Zellenhintergrund d_1bd898[d_1bd90a][d_1bd908] der aktuell
 *   ausgewählten Tabellenzelle (d_1bd90a, d_1bd908) im Bildschirmpuffer d_1a34e0 wieder her.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd90a (Zeile), d_1bd908 (Spalte).
 === Ende Beschreibung === */
void f_0810b0()
{
    short y;
    short x;
    if ((unsigned short)d_1bd908 < 4 && (unsigned short)d_1bd90a < 7) {
        y = d_1a2024 + 0x20 + d_1bd90a * 8;
        x = d_1bd85c[d_1bd908];
        f_0fade0(d_1bd898[d_1bd90a][d_1bd908], d_1a34e0, (short)(x - 1), y);
    }
}
//@ f_081130
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den aktuellen Einstellungstext einer einzelnen Tabellenzelle (Spalte p1, Zeile p2)
 *   des Computerkampf-Dialogs auf dem Bildschirm aus: Spalte 0 zeigt die Kampfart (Computer/Manuell, f_043e10),
 *   Spalte 1 den Einsatz von Zaubern (f_042790), Spalte 2 den Einsatz von Fernkampfwaffen (f_0427b0) und Spalte
 *   3 die Kampftaktik/Vorsicht (f_042770).
 * - Eingaben: unsigned short p1 (Spalte 0..3), unsigned short p2 (Heldenzeile 0..6).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd88c (signed char[7]): Zuordnung von Tabellenzeile zu Gruppen-Slot.
 *   - d_1bd86c (int[8]): Zeiger auf die Helden-Strukturen der Gruppe.
 === Ende Beschreibung === */
void f_081130(unsigned short p1, unsigned short p2)
{
    short y;
    short x;
    int t;
    int id;
    unsigned char col;

    if (p1 >= 4) return;
    if (p2 >= 7) return;
    if (d_1bd88c[(short)p2] < 0) return;
    y = d_1a2024 + 0x20 + p2 * 8;
    x = d_1bd85c[(short)p1];
    t = d_1bd86c[d_1bd88c[(short)p2]];
    switch (p1) {
    case 0:
        if (f_043e10(t) == 0) id = d_1bd800;
        else if (f_043e10(t) == 1) id = d_1bd804;
        else id = d_1bd808;
        break;
    case 1:
        if (f_042790(t) == 0) id = 0x1010095;
        else id = (f_042790(t) != 1) + 0x1010096;
        break;
    case 2:
        if (f_0427b0(t) == 0) id = 0x1010095;
        else { id = (unsigned char)(f_0427b0(t) != 1); id += 0x1010096; }
        break;
    case 3:
        if (f_042770(t) == 0) id = 0x1010095;
        else id = (f_042770(t) != 1) + 0x1010096;
        break;
    default:
        return;
    }

    f_05e320(d_1c38b0, 0xfc, -1);
    if (f_0d49b0(t) == 0) {
        col = 0xf9;
        if (f_0424d0(t) || f_0424e0(t) || f_0425f0(t) || f_0425a0(t))
            col = 0xf9;
        f_05e320(d_1c38b0, col, -1);
    }
    f_0e93f0(d_1c38b0, d_1c21b4, id);
    f_0e9660(d_1c38b0, d_1c21b4, x, y);
}
//@ f_081310
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet das Grundgerüst und die Heldennamen-Spalte des Computerkampf-Dialogs. Passt die
 *   Y-Koordinaten der unteren Schaltflächen-Hotspots 0x81 und 0x83 an die tatsächliche Heldenanzahl d_1bd894 an,
 *   formatiert für jeden Helden dessen Namen (bei Kampfunfähigkeit in Warn-/Graufarbe 0xe7 bzw. 0xf9) sowie die
 *   Fußzeile 0x1010098 in den Textpuffer d_1c21b4 und gibt den gesamten Textblock an (d_1a2022, d_1a2024) aus.
 * - Eingaben: Ctx *c (aktiver Textformatierungskontext).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd894 (short, Anzahl der Zeilen), d_1a2028 (HS[]).
 === Ende Beschreibung === */
void f_081310(Ctx *c)
{
    extern int f_09a080_x(int);
#pragma aux f_09a080_x "f_09a080" parm [eax] modify exact [eax]
    int tx = f_133fe0(d_1c3498, d_1b6f68);
    short ch;
    short s;
    int t;
    unsigned char col;
    short i;
    {
        MG g;
        f_09ade0(d_1a34e0, 0, 0);
    }
    f_0e93f0(d_1c38b0, d_1c21b4, 0x1010093);
    ch = h_080730(d_1a2028, 0x81);
    s = ch;
    if (ch != -1) {
        d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
        d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
    }
    ch = h_080730(d_1a2028, 0x83);
    s = ch;
    if (ch != -1) {
        d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
        d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
    }
    for (i = 0; i < d_1bd894; i++) {
        if (d_1bd88c[i] >= 0) {
            t = d_1bd86c[d_1bd88c[i]];
            c->p04[1] = t;
            c->p10[1] = c->p10[2] = c->p10[3] = c->p10[4] = tx;
            if (f_0d49b0(t) != 0) {
                f_0e9300(d_1c38b0, d_1c21b4, 0x1010094);
            } else {
                col = 0xe7;
                f_0e93f0(d_1c38b0, d_1c27a8, 0x1010094);
                if (f_0424d0(t) || f_0424e0(t) || f_0425f0(t) || f_0425a0(t)) col = 0xf9;
                c->p10[1] = f_133fe0(d_1c3498, d_1c27a8);
                f_0e9300(d_1c38b0, d_1c21b4, f_09a080_x(col));
            }
        }
    }
    f_0e93f0(d_1c38b0, d_1c27a8, 0x1010098);
    c->p10[1] = f_133fe0(d_1c3498, d_1c27a8);
    f_0e9300(d_1c38b0, d_1c21b4, f_09a080_x(0xfc));
    {
        MG g;
        f_0e9660(d_1c38b0, d_1c21b4, d_1a2022, d_1a2024);
    }
}
//@ f_081610
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bewegt die Zeilenauswahl d_1bd90a im Computerkampf-Dialog um eine Zeile nach oben
 *   (zyklisch modulo d_1bd894 + 1), überspringt dabei handlungsunfähige Helden (f_0d49b0 == 0) und zeichnet den
 *   Auswahlrahmen über f_080cd0() neu.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd90a (short).
 === Ende Beschreibung === */
void f_081610()
{
    int n;
    do {
        n = d_1bd894;
        n += 1;
        d_1bd90a = (d_1bd90a - 1 + n) % n;
        if (d_1bd90a == d_1bd894) break;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[d_1bd90a]]) == 0);
    f_080cd0();
}
//@ f_081680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bewegt die Zeilenauswahl d_1bd90a im Computerkampf-Dialog um eine Zeile nach unten
 *   (zyklisch modulo d_1bd894 + 1), überspringt dabei handlungsunfähige Helden (f_0d49b0 == 0) und zeichnet den
 *   Auswahlrahmen über f_080cd0() neu.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd90a (short).
 === Ende Beschreibung === */
void f_081680()
{
    do {
        int n = d_1bd894 + 1;
        d_1bd90a = (d_1bd90a + 1) % n;
        if (d_1bd90a == d_1bd894) break;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[d_1bd90a]]) == 0);
    f_080cd0();
}
//@ f_0816f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bewegt die Spaltenauswahl d_1bd908 im Computerkampf-Dialog nach links (in normalen
 *   Heldenzeilen um 1 Spalte, in der unteren Schaltflächenzeile d_1bd90a == d_1bd894 um 2 Spalten modulo 4) und
 *   aktualisiert den Auswahlrahmen über f_080cd0().
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd908 (short).
 === Ende Beschreibung === */
void f_0816f0()
{
    int v;
    if (d_1bd90a == d_1bd894) v = d_1bd908 + 2;
    else v = d_1bd908 + 3;
    d_1bd908 = v % 4;
    f_080cd0();
}
//@ f_081740
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bewegt die Spaltenauswahl d_1bd908 im Computerkampf-Dialog nach rechts (in normalen
 *   Heldenzeilen um 1 Spalte, in der unteren Schaltflächenzeile um 2 Spalten modulo 4) und aktualisiert den
 *   Auswahlrahmen über f_080cd0().
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd908 (short).
 === Ende Beschreibung === */
void f_081740()
{
    int v;
    if (d_1bd90a == d_1bd894) v = d_1bd908 + 2;
    else v = d_1bd908 + 1;
    d_1bd908 = v % 4;
    f_080cd0();
}
//@ f_0817a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet und betreibt den interaktiven Tabellen-Dialog zur Konfiguration des Computerkampfs
 *   (entweder für einen einzelnen Helden p1 != 0 oder für die gesamte Gruppe p1 == 0). Stellt die
 *   Tabulator-Positionen ein, sammelt die anzuzeigenden Helden in d_1bd86c und d_1bd88c, sichert die
 *   Zellenhintergründe, gibt alle Zeilen und Spalten aus und verarbeitet Pfeiltasten, Mausklicks sowie
 *   Enter/Leertaste zum zyklischen Umschalten der vier Einstellungsspalten (f_043e00, f_042780, f_0427a0,
 *   f_042760), bis der Dialog mit OK (res = 1) oder Escape/Abbruch (res = 0) geschlossen wird.
 * - Eingaben: int p1 (0 = alle aktiven Helden der Gruppe anzeigen, != 0 = Zeiger auf einen einzelnen Helden).
 * - Rückgabewert: int (1 bei Bestätigung, 0 bei Abbruch mit Escape oder linker Schaltfläche).
 * - Wichtige Variablen:
 *   - d_1bd86c (int[8]): Zeiger auf die im Dialog gelisteten Helden.
 *   - d_1bd88c (signed char[7]): Zeilen-zu-Index-Zuordnung.
 *   - d_1bd894 (short): Anzahl der aktiven Heldenzeilen im Dialog.
 === Ende Beschreibung === */
// KRUECKE: leere Ableitung erhaelt den Kontextcode und das originale Endfuellbyte.
struct CtxObj22:Ctx {};


// KRUECKE: benannter volatiler Zeigerzugriff bindet die Prologfolge.
extern void * volatile ptrpro34;
#pragma aux ptrpro34 "d_1bf514"

static inline void forwardExact0217()
{
    int n, r;
    do {
        { int q = d_1bd894; {int u=q;q=u;} n = q + 1; }
        r = (d_1bd90a + 1) % n;
        d_1bd90a = r;
        if (d_1bd90a == d_1bd894) break;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[d_1bd90a]]) == 0);
    f_080cd0();
}


// KRUECKE: zwei normale Kopien gewichten den letzten Wert der Textkette.
static inline int tc053(int v){return v;}


struct GuardRaw0217 {
    int fl;
    void start() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    void stop() { if (fl == 1) f_0d26e0(); }
};
void f_081130(int p1, int p2);
int f_09a080(int p1);
static inline void h2_080f80()
{
    short i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            Img9 *p = d_1bd898[i][j];
            if (p != 0) delete (char *)f_0fad20(p, 0);
        }
    }
}
static inline void h2_080fd0()
{
        int ju;
    short i;
    int jq;
    short j;
    for (i = 0; i < 7; i++) {
            {short u=i;i=u;}
            {short u=i;i=u;}
        for (j = 0; (jq=j, ju=jq, jq=ju)<4; j++) {
    short y;
    Img9 * im;
    void * tag;
    Img9 * raw;
    short x;
    short w;
    int off;
            
            {
                short gy = d_1a2024 + 0x20;
                { short u = gy; gy = u; }
                y = gy + i * 8;
            }
            x = d_1bd85c[jq] - 1;
            w = d_1bd85c[jq + 1] - x;
            tag = mark(d_1a2004, 0x461);
            w -= 3;
            raw = new (tag) Img9;
            
            if (raw) im = f_0fac80(raw, w, 8);
            else im = raw;
            
            {
                int part = i * 16;
                // KRUECKE: zwei Kopien binden Register und Reihenfolge des Bildadressenteils.
                { int u = part; part = u; }{ int u = part; part = u; }{ int u = part; part = u; }{ int u = part; part = u; }
                
                off = part + j * 4;
            }
            *(Img9 **)((char *)d_1bd898 + off) = im;
            f_0fafb0(*(Img9 **)((char *)d_1bd898 + off), d_1a34e0, x, y);
        }
    }
}
static inline void h2_0810b0()
{
    short y;
    short x;
    if ((unsigned short)d_1bd908 < 4 && (unsigned short)d_1bd90a < 7) {
        y = d_1a2024 + 0x20 + d_1bd90a * 8;
        x = d_1bd85c[d_1bd908];
        f_0fade0(d_1bd898[d_1bd90a][d_1bd908], d_1a34e0, (short)(x - 1), y);
    }
}
static inline void h2_mg_ade0()
{
    MG g;
    f_09ade0(d_1a34e0, 0, 0);
}
static inline void h2_mg_9660()
{
    MG g;
    f_0e9660(d_1c38b0, d_1c21b4, d_1a2022, d_1a2024);
}
static inline void h2_mg_bf730(int code)
{
    MG g;
    f_0bf730(d_1c2c64, code);
}
// KRUECKE A18F: Zeichen-Zwischenwerte mit belegter Breite vorab benennen,
// alle short-Werte zuerst. Guard-POD-Scope erst nach der Statusabfrage:
// beide Guard- und alle Zeiger-Stapelplaetze stimmen; Auswertung bleibt erhalten.
static inline void h2_mg_10b0(){short yrowA18;
int imageOffsetA18;
Img9 * imageA18;
int boundRowA18;
int boundColA18;
short ybaseA18;
char * screenA18;
int rowOffsetA18;
int rowIndexA18;
int colOffsetA18;
int ywideA18;
int colIndexA18;
int endColA18;
GuardRaw0217 birthGuardA18;
int endRowA18;
int xwideA18;
int probeA18;
short yyA18;
short xadjustA18;
int xOffsetA18;probeA18=f_0d3860();{short xxA18;(void)&birthGuardA18;if(probeA18==1){f_0d2710();birthGuardA18.fl=1;}else birthGuardA18.fl=0;
 if((boundColA18=(unsigned short)d_1bd908)<4 && (boundRowA18=(unsigned short)d_1bd90a)<7){
  yyA18=(ybaseA18=(short)(d_1a2024+0x20))+(yrowA18=(short)(d_1bd90a*8));
  xxA18=*(short*)((char*)d_1bd85c+(xOffsetA18=(colIndexA18=(int)d_1bd908)*2));
  f_0fade0(imageA18=*(Img9**)((char*)d_1bd898+(imageOffsetA18=(rowOffsetA18=(rowIndexA18=(int)d_1bd90a)*16)+(colOffsetA18=colIndexA18*4))),screenA18=d_1a34e0,xwideA18=(int)(xadjustA18=(short)(xxA18-1)),ywideA18=(int)yyA18);
 }
 f_081130(endColA18=(int)d_1bd908,endRowA18=(int)d_1bd90a);
birthGuardA18.stop();}}

static inline void h2_081610()
{
    do {
        int n = d_1bd894 + 1;
        { int prev = d_1bd90a; { int u = prev; prev = u; }{ int u = prev; prev = u; }  d_1bd90a = (prev - 1 + n) % n; }
        if (d_1bd90a == d_1bd894) break;
    } while (f_0d49b0(d_1bd86c[d_1bd88c[d_1bd90a]]) == 0);
    f_080cd0();
}
static inline signed char scan_k34b(HS *t, short id)
{
    signed char r = -1;
    short i = 0;
    while (t[i].id != -1 && r == -1) {
        if (id == t[i].id) r = i;
        i++;
        {short u=i;i=u;}
        { signed char u = r; r = u; }
        { signed char u = r; r = u; }
    }
    return r;
}
static inline signed char scan_k34(HS *t, short id)
{
    short i = 0;
    signed char r = -1;
    while (t[i].id != -1 && r == -1) {
        if (id == t[i].id) r = i;
        i++;
        {short u=i;i=u;}
    }
    return r;
}
static inline int firstTextA18(int v){{int u=v;v=u;}return v;}
int f_0817a0(int p1)
{
    extern int palette_k34(int, int, int);
#pragma aux palette_k34 "f_149eb4" parm caller [] modify exact [eax ecx edx]
    struct GhostShape3_A18F { char pad[3]; };
    struct GhostShape5_A18F { char pad[5]; };
    struct GhostShape6_A18F { char pad[6]; };
    struct GhostShape7_A18F { char pad[7]; };
    struct GhostShape9_A18F { char pad[9]; };
    struct GhostShape10_A18F { char pad[10]; };
    struct GhostShape11_A18F { char pad[11]; };
    struct GhostShape12_A18F { char pad[12]; };
    struct GhostShape13_A18F { char pad[13]; };
    struct GhostShape14_A18F { char pad[14]; };
    struct GhostShape15_A18F { char pad[15]; };
    struct GhostShape16_A18F { char pad[16]; };
    struct GhostShape20_A18F { char pad[20]; };
    struct GhostShape24_A18F { char pad[24]; };
    struct GhostShape28_A18F { char pad[28]; };
    struct GhostShape32_A18F { char pad[32]; };
    struct GhostShape40_A18F { char pad[40]; };
    struct GhostShape48_A18F { char pad[48]; };
    struct GhostShape61_A18F { char pad[61]; };
    struct GhostShape64_A18F { char pad[64]; };
    struct GhostShape128_A18F { char pad[128]; };
    CtxObj22 c;
    volatile GhostShape64_A18F ghost_108_A18F;
    volatile int ghost_107_A18F;
    volatile GhostShape13_A18F ghost_106_A18F;
    volatile GhostShape7_A18F ghost_105_A18F;
    volatile GhostShape3_A18F ghost_104_A18F;
    volatile GhostShape48_A18F ghost_103_A18F;
    volatile int ghost_102_A18F;
    volatile GhostShape3_A18F ghost_101_A18F;
    volatile char ghost_100_A18F;
    volatile GhostShape128_A18F ghost_99_A18F;
    volatile GhostShape20_A18F ghost_98_A18F;
    volatile GhostShape10_A18F ghost_97_A18F;
    volatile GhostShape6_A18F ghost_96_A18F;
    volatile GhostShape7_A18F ghost_95_A18F;
    volatile char ghost_94_A18F;
    volatile GhostShape9_A18F ghost_93_A18F;
    volatile double ghost_92_A18F;
    volatile GhostShape16_A18F ghost_91_A18F;
    volatile int ghost_90_A18F;
    volatile GhostShape6_A18F ghost_89_A18F;
    volatile GhostShape9_A18F ghost_88_A18F;
    volatile GhostShape12_A18F ghost_87_A18F;
    volatile double ghost_86_A18F;
    volatile GhostShape3_A18F ghost_85_A18F;
    volatile GhostShape12_A18F ghost_84_A18F;
    volatile GhostShape3_A18F ghost_83_A18F;
    volatile GhostShape64_A18F ghost_82_A18F;
    volatile char ghost_81_A18F;
    volatile GhostShape20_A18F ghost_80_A18F;
    volatile GhostShape6_A18F ghost_79_A18F;
    volatile GhostShape13_A18F ghost_78_A18F;
    volatile GhostShape28_A18F ghost_77_A18F;
    volatile GhostShape24_A18F ghost_76_A18F;
    volatile int ghost_75_A18F;
    volatile GhostShape9_A18F ghost_74_A18F;
    volatile GhostShape64_A18F ghost_73_A18F;
    volatile GhostShape24_A18F ghost_72_A18F;
    volatile GhostShape16_A18F ghost_71_A18F;
    volatile GhostShape48_A18F ghost_70_A18F;
    volatile GhostShape20_A18F ghost_69_A18F;
    volatile GhostShape10_A18F ghost_68_A18F;
    volatile short ghost_67_A18F;
    volatile GhostShape10_A18F ghost_66_A18F;
    volatile char ghost_65_A18F;
    volatile GhostShape40_A18F ghost_64_A18F;
    volatile GhostShape13_A18F ghost_63_A18F;
    volatile GhostShape64_A18F ghost_62_A18F;
    volatile GhostShape61_A18F ghost_61_A18F;
    volatile GhostShape6_A18F ghost_60_A18F;
    short saved[6];
    volatile char ghost_59_A18F;
    volatile GhostShape9_A18F ghost_58_A18F;
    volatile GhostShape12_A18F ghost_57_A18F;
    volatile GhostShape64_A18F ghost_56_A18F;
    volatile GhostShape7_A18F ghost_55_A18F;
    volatile GhostShape128_A18F ghost_54_A18F;
    volatile GhostShape10_A18F ghost_53_A18F;
    int done = 0;
    char savedflag = d_1bd928;
    void *savedptr;
    int t;
    int res = 1;
    short row;
    short j;
    volatile GhostShape11_A18F ghost_52_A18F;
    volatile GhostShape9_A18F ghost_51_A18F;
    volatile GhostShape11_A18F ghost_50_A18F;
    volatile GhostShape128_A18F ghost_49_A18F;
    volatile GhostShape12_A18F ghost_48_A18F;
    volatile char ghost_47_A18F;
    volatile GhostShape3_A18F ghost_46_A18F;
    volatile GhostShape48_A18F ghost_45_A18F;
    short col;
    volatile GhostShape16_A18F ghost_44_A18F;
    volatile GhostShape40_A18F ghost_43_A18F;
    volatile GhostShape12_A18F ghost_42_A18F;
    volatile GhostShape11_A18F ghost_41_A18F;
    volatile GhostShape20_A18F ghost_40_A18F;
    volatile GhostShape9_A18F ghost_39_A18F;
    volatile GhostShape12_A18F ghost_38_A18F;
    volatile GhostShape32_A18F ghost_37_A18F;
    volatile GhostShape12_A18F ghost_36_A18F;
    volatile GhostShape24_A18F ghost_35_A18F;
    volatile GhostShape6_A18F ghost_34_A18F;
    volatile GhostShape6_A18F ghost_33_A18F;
    volatile GhostShape24_A18F ghost_32_A18F;
    volatile double ghost_31_A18F;
    volatile double ghost_30_A18F;
    volatile char ghost_29_A18F;
    volatile GhostShape11_A18F ghost_28_A18F;
    volatile GhostShape3_A18F ghost_27_A18F;
    volatile GhostShape64_A18F ghost_26_A18F;
    volatile GhostShape10_A18F ghost_25_A18F;
    volatile GhostShape20_A18F ghost_24_A18F;
    volatile GhostShape15_A18F ghost_23_A18F;
    volatile GhostShape12_A18F ghost_22_A18F;
    volatile GhostShape40_A18F ghost_21_A18F;
    volatile GhostShape10_A18F ghost_20_A18F;
    volatile GhostShape6_A18F ghost_19_A18F;
    volatile GhostShape12_A18F ghost_18_A18F;
    volatile GhostShape40_A18F ghost_17_A18F;
    volatile GhostShape64_A18F ghost_16_A18F;
    volatile GhostShape128_A18F ghost_15_A18F;
    volatile GhostShape64_A18F ghost_14_A18F;
    volatile GhostShape13_A18F ghost_13_A18F;
    volatile GhostShape128_A18F ghost_12_A18F;
    volatile GhostShape40_A18F ghost_11_A18F;
    volatile GhostShape14_A18F ghost_10_A18F;
    volatile int ghost_9_A18F;
    volatile GhostShape14_A18F ghost_8_A18F;
    volatile GhostShape3_A18F ghost_7_A18F;
    volatile GhostShape20_A18F ghost_6_A18F;
    volatile GhostShape64_A18F ghost_5_A18F;
    volatile GhostShape32_A18F ghost_4_A18F;
    short i;
    register int redraw;
    volatile GhostShape5_A18F ghost_3_A18F;
    volatile int ghost_2_A18F;
    volatile GhostShape5_A18F ghost_1_A18F;
    volatile GhostShape9_A18F ghost_0_A18F;
    // KRUECKE: Ergebnis vor dem volatilen Sichern initialisieren; bindet EDI vor dem Ctor.
    savedptr = ptrpro34;
    d_1bd90a = 0;
    d_1bd908 = 0;
    d_1bd894 = 0;
    d_1bd928 = 2;
    palette_k34(d_1bdbe4, 0, 0x100);
    f_09a7d0(d_1a34e0, 0, 0, 0x140, 200, 0x140, -8);
    f_145300(d_1bd88c, -1, 7);
    f_145300(d_1bd86c, 0, 0x20);

    for (i = 0; i < 4; i++) {
        saved[i] = f_05e820(d_1c38b0, i);
        f_05e830(d_1c38b0, (short)d_1bd85c[i], i);
    }
    f_05e320(d_1c38b0, 0xfc, -1);
    f_09ac80(d_1a34e0, 0, 0);

    if (p1 == 0) {
        d_1bd894 = 0;
        for (i = 0; i < 7; i++) {
            if (f_0dbfb0(d_1c0004, d_1bc8f0 + i * 0x5ef) &&
                f_042400((int)(d_1bc8f0 + i * 0x5ef)) != 4) {
                {
                    int hp = (int)(d_1bc8f0 + i * 0x5ef);
                    // KRUECKE: eine Kopie gibt dem Summenergebnis den benoetigten Nutzwert.
                    
                    
                    d_1bd86c[i] = hp;
                }
                d_1bd88c[d_1bd894] = i;
                d_1bd894++;
            } else {
                d_1bd86c[i] = 0;
            }
        }
    } else {
        d_1bd86c[0] = p1;
        d_1bd88c[0] = 0;
        d_1bd894 = 1;
    }

    redraw = 1;
    h2_080fd0();
    {
        // KRUECKE: von D13 berechnete lokale Geburtsordnung.
        int t2;
        short i2;
        int tx = f_133fe0(d_1c3498, d_1b6f68);{int uA18=tx;tx=uA18;}{int uA18=tx;tx=uA18;}{int uA18=tx;tx=uA18;}
        short s = 0;
        signed char ch;
        unsigned char col2;
        i2=0;
        h2_mg_ade0();
        f_0e93f0(d_1c38b0, d_1c21b4, 0x1010093);
        {
            short id;
            HS *scanptr1;
            signed char r;
            short i;
            scanptr1= d_1a2028;
            id=0x81;{short uA18=id;id=uA18;}{short uA18=id;id=uA18;}{short uA18=id;id=uA18;}
            i=0;
            r=-1;
            while (scanptr1[i].id != -1 && r == -1) {
                if ((i2 = (id & 0)?0:id) == scanptr1[i].id) r = i;
                i++;
                {short u=i;i=u;}
            }
            ch = r;
        }
        s = ch;

        // KRUECKE: Zweite Scan-ID zwischen den Y-Zuweisungen anlegen; der triviale
        // Scope bleibt bis zum zweiten Scan offen und bindet beide originalen ID-Plaetze.
        if(ch == -1)goto before_second_a18;
            d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
        { short scanid2;
            d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
before_second_a18:;
        {
            
            short i;
            HS *scanptr2;
            signed char r;
            scanptr2= d_1a2028;
            scanid2=0x83;{short uA18=scanid2;scanid2=uA18;}
            r=-1;
            i=0;
            while (scanptr2[i].id != -1 && r == -1) {
                if (scanid2 == scanptr2[i].id) r = i;
                i++;
                {short u=i;i=u;}
                { signed char u = r; r = u; }
                { signed char u = r; r = u; }
            }
            ch = r;
        }
        s = ch;
        }
        // KRUECKE: drei Kopien stimmen das zweite Scan-Ergebnis mit den Schleifenindizes ab.
        { short u = s; s = u; }{ short u = s; s = u; }{ short u = s; s = u; }
        
        

        if (ch != -1) {
            d_1a2028[s].y1 = d_1a2024 + (d_1bd894 + 5) * 8;
            d_1a2028[s].y2 = (d_1bd894 + 6) * 8 + d_1a2024;
        }
i2=(i2&0)?0:i2;s=(s&0)?0:s;
        for (i2 = 0; i2 < d_1bd894; i2++) {
            if (d_1bd88c[i2] >= 0) {
                t2 = d_1bd86c[d_1bd88c[i2]];
                c.p04[1] = t2;
                c.p10[1]=tc053(c.p10[2]=c.p10[3]=firstTextA18(c.p10[4]=tx));
                if (f_0d49b0(t2) != 0) {
                    f_0e9300(d_1c38b0, d_1c21b4, 0x1010094);
                } else {
                    col2 = 0xe7;
                    f_0e93f0(d_1c38b0, d_1c27a8, 0x1010094);
                    if (f_0424d0(t2) || f_0424e0(t2) || f_0425f0(t2) || f_0425a0(t2)) col2 = 0xf9;
    { unsigned char u0217=col2;col2=u0217; }{ unsigned char u0217=col2;col2=u0217; }
                    c.p10[1] = f_133fe0(d_1c3498, d_1c27a8);
                    f_0e9300(d_1c38b0, d_1c21b4, f_09a080(col2));
                }
            }
        }
        f_0e93f0(d_1c38b0, d_1c27a8, 0x1010098);
        c.p10[1] = f_133fe0(d_1c3498, d_1c27a8);
        f_0e9300(d_1c38b0, d_1c21b4, f_09a080(0xfc));
        h2_mg_9660();
    }
    f_0d26e0();
    {
        MG g;
        for (j = 0; j < 7; j++)
            for (i = 0; i < 4; i++)
                { { short u = j; j = u; } f_081130(i, j); }
    }

    while (!done) {
{int u=redraw;redraw=u;}
        if (redraw == 1) {
            f_080cd0();
            redraw = 0;
            redraw = redraw;
        }
        d_1bf514 = d_1a2028;
        f_068f40();
        d_1bf514 = savedptr;

        switch ((unsigned short)d_1bd766) {
        case 0x5000:
            forwardExact0217();
            break;
        case 0x4800:
            h2_081610();
            break;
        case 0x4b00:
            h_0816f0();
            break;
        case 0x4d00:
            h_081740();
            break;
        case 0x11b:
l_esc:
            res = 0;
            done = 1;
            break;
l_encode:
            d_1bd766 = ((d_1bd90a + 1) << 4) | (d_1bd908 + 1);
            goto l_num;
        default:
            if (d_1bd766 <= 0 || d_1bd766 >= 0x90) break;
l_num:
            row = d_1bd766 >> 4;
            row--;
            { short u = row; row = u; }{ short u = row; row = u; }
            
            if (row < d_1bd894) {
                if (d_1bd88c[row] < 0) break;
                t = d_1bd86c[d_1bd88c[row]];
                if (t == 0) break;
                if (f_042400(t) != 0) {
                    c.p04[1] = t;
                    {
                        MG g;
                        f_0bf730(d_1c2c64, 0x10100a7);
                    }
                } else {
                    // KRUECKE: Der gemeinsame triviale Block legt Case-1-v und den
                    // A8-Guard erst nach dem Sichtbarkeitstest an. Beide urspruenglichen
                    // ==-Vergleiche erhalten dabei die Reihenfolge der Registerknoten.
                    if(f_0d49b0(t)==0)goto error_case37; goto normal_case37;
error_case37:
                    c.p04[1]=t;
                    if(f_0d3860()==1)goto one_case37; goto zero_case37;
                    { signed char v; GuardRaw0217 ga8; (void)&ga8;
one_case37:
                    f_0d2710(); ga8.fl=1; goto message_case37;
zero_case37: ga8.fl=0;
message_case37: f_0bf730(d_1c2c64,0x10100a8); ga8.stop();
                    goto end_case37;
normal_case37: 
                    col = d_1bd766 & 0xf;
                    d_1bd90a = row;
                    d_1bd908 = col - 1;
                    f_080cd0();
                    redraw = 1;
                    redraw = redraw;
                    switch (col) {
                    case 1: {
                        v = f_043e10(t) + 1;
                        if (v > 2) v = 0;
                        f_043e00(t, v);
                        break;
                    }
                    case 2: {
                        signed char v = f_042790(t) + 1;
                        if (v > 2) v = 0;
                        f_042780(t, v);
                        break;
                    }
                    case 3: {
                        signed char v;
                        // KRUECKE: gemeinsamer Speicher-Scope fuer die Faelle 3 und 4.
                        GuardRaw0217 mg4;
                        v = f_0427b0(t) + 1;
                        if (v > 2) v = 0;
                        f_0427a0(t, v);
                        break;
                    case 4:
                        if (f_042a10(t) == 0) {
                            (void)&mg4;
                            mg4.start();
                            f_0bf730(d_1c2c64, 0x20000161);
                            mg4.stop();
                        } else {
                            signed char v = f_042770(t) + 1;
                            if (v > 2) v = 0;
                            f_042760(t, v);
                        }
                        break;
                    }
                    }
                    h2_mg_10b0();
end_case37: ;
                    }
                }
                break;
            }
            d_1bd908 = (d_1bd766 & 0xf) - 1;
            d_1bd90a = row;
            f_080cd0();
        case 0x1c0d:
        case 0x3920:
            if (d_1bd90a >= d_1bd894) {
                if (d_1bd908 < 2) goto l_esc;
                res = 1;
                done = 1;
                break;
            }
            goto l_encode;
        }
    }

    f_0d2710();
    f_080900();
    h2_080f80();
    for (i = 0; i < 4; i++) f_05e830(d_1c38b0, saved[i], i);
    f_05e340(d_1c38b0);
    d_1bd928 = savedflag;
    d_1bda54 = 1;
    f_09aed0(0);
    f_0d2710();
    {int u=res;res=u;}
return res;
}
// HINWEIS: f_080cd0 steht hier am Ende (vor f_081610.. sonst inlined Watcom sie), im Original liegt sie vor f_080f80
