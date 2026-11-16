/* === Beschreibung (Katalog) ===
 * Einheit face2 (0x06a790 - 0x06ac20)
 *
 * Überblick
 * Die Einheit face2 (face2.cpp) implementiert das Laden und Entpacken der Animationssequenzen und Einzelbilder
 * für Kampfsprites (Face / Gz). Sie öffnet die komprimierten Sprite-Archive (id | 0x80000000), sucht den
 * gewünschten Teil-Animationsheader heraus (f_06a790) und dekomprimiert das aktuelle Einzelbild in ein
 * RivaRasterImage (f_06a900).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 1/2 gleich (suche.py 26.10.2026, Basis face2_P1.CPP)
// face2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06A790-0x06AC20
#include <string.h>
void *f_014540(long size, const char *file, int line);
int f_014a60();

extern RivaFileManager d_1c2098;
extern const char d_1a1b04[];
struct T8 { char b[8]; };
extern const T8 d_1a1b22;
extern unsigned short d_1c0004;
extern unsigned short d_1bfb00;
int f_0773b0(int x);
struct Sub { char d[14]; ~Sub(); };
struct Big { char d[0x8c]; };

void *f_010430(Sub *p, int z);
RivaRasterImage *f_0fac10(RivaRasterImage *p, int w, int h, int z);

Sub *f_010400(Sub *p, short a, short b, short c, short d, long e, unsigned char f, unsigned char g);
short f_010460(Sub *p);
short f_010470(Sub *p);
int f_010480(Sub *p);
unsigned char  f_010490(Sub *p);
int f_0a2520(void *sub, unsigned char c, int e, short w, short h, int img, void *buf);
struct Tab { unsigned char v; char p[3]; };
struct H1 { char p0[4]; short ver; unsigned char n; char p1; };
struct Hd { long e; short a, b, c, d; unsigned char g, f; };
#define RL(o) (*(long *)(r + (o)))
#define RB(o) (*(unsigned char *)(r + (o)))
struct Face {
    unsigned long id;            // +0x00
    char p4[8];
    Tab tab[38];                 // +0x0c
    unsigned char a4;            // +0xa4
    short a5;                    // +0xa5
    char p7[12];
    long b3;                     // +0xb3
    long b7;                     // +0xb7
    char bb;                     // +0xbb
    short bc;                    // +0xbc
    char be;                     // +0xbe
    short bf;                    // +0xbf
    short c1;                    // +0xc1
    char c3;                     // +0xc3
    char c4;                     // +0xc4
    signed char c5;              // +0xc5
    char c6[5];
    unsigned char cb;            // +0xcb
    char cc;                     // +0xcc
    char cd[2];
    Sub *cf;                     // +0xcf
    RivaRasterImage *d3;                     // +0xd3
    char d7[6];
    char *dd;                    // +0xdd
    short e1;                    // +0xe1
    long e3;                     // +0xe3
    void f_06a790();
    void f_06a900();
};
//@ f_06a790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet bei aktivem Sprite (b3 != 0) das Animationsarchiv id | 0x80000000 über den Dateimanager
 *   d_1c2098, bestimmt anhand der Geschwindigkeitseinstellungen (c5, d_1bfb00 und d_1a1b22) die Framedauer c4,
 *   sucht in der Header-Tabelle nach dem Schlüssel tab[a4].v der aktuellen Animationsphase, übernimmt
 *   Dateioffset (b7), Frameanzahl (c3) sowie Offsets (bf, c1, bc, be) und lädt anschließend über f_06a900 das
 *   erste Einzelbild.
 * - Eingaben und Rückgabe: Eingabe ist der this-Zeiger auf das Face-/Gz-Objekt (eax); die Funktion hat keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: d_1c2098 ist der Dateimanager, d_1a1b22 die Geschwindigkeitstabelle und tab[a4] der
 *   Eintrag der aktuellen Animationsphase.
 === Ende Beschreibung === */
void Face::f_06a790()
{
    char r[16]; H1 hd; T8 t = d_1a1b22;
    if (b3 != 0) {
        if (d_1c2098.f_1448b0(id | 0x80000000, 0x200) != -1) {
            d_1c2098.f_144920(&hd, 8);
            if (hd.ver == 1) {
                if (c5 != -1) c4 = c5;
                else if (f_0773b0(*(int *)&d_1c0004)) { signed char ix = *(signed char *)&d_1bfb00; c4 = t.b[ix * 2]; }
                else { signed char ix = *(signed char *)&d_1bfb00; c4 = t.b[ix * 2 + 2]; }
                short key = tab[a4].v;
                Face *q = this;
                int n = hd.n;
                short bound = n;
                short i;
                for (i = 0; i < bound; i++) {
                    d_1c2098.f_144920(r, 0x10);
                    if (key == *(short *)(r + 4)) {
                        q->b7 = RL(0);
                        q->c3 = RB(0xe);
                        q->bf = RL(0xa);
                        q->c1 = RL(0xc);
                        q->bc = RL(6);
                        q->be = RB(8);
                        q->a5 = key;
                        break;
                    }
                }
                d_1c2098.f_1449a0();
                cc = -1;
                bb = 1;
                f_06a900();
            } else {
                d_1c2098.f_1449a0();
            }
        }
    }
}
//@ f_06a900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Positioniert im Animationsarchiv id | 0x80000000 auf das Einzelbild cb (entweder direkt über
 *   den gespeicherten Dateioffset e3 des Vorgängerbildes e1 + 1 == cb oder durch Durchlaufen ab Sequenzbeginn
 *   b7), legt einen neuen Pixelpuffer dd und ein RivaRasterImage d3 der Größe h.c x h.d sowie den
 *   Frame-Deskriptor cf an, liest die komprimierten Bilddaten in buf ein und entpackt sie mit f_0a2520 in d3.
 *   *(Hinweis: Siehe Fehlerliste - wenn f_014a60() <= n + h.e ist, wird buf nicht alloziert und das Archiv nicht
 *   geschlossen, aber trotzdem f_0a2520 und operator delete(buf) mit uninitialisiertem buf aufgerufen.)*
 * - Eingaben und Rückgabe: Eingabe ist der this-Zeiger auf das Face-/Gz-Objekt (eax); die Funktion gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: e1 und e3 cachen den letzten Frameindex und Dateioffset für schnelles Vorwärtsblättern,
 *   d3 und dd halten das entpackte Einzelbild.
 === Ende Beschreibung === */
void Face::f_06a900()
{
    Big sub; Hd h; char *buf; int n;
    if (d_1c2098.f_1448b0(id | 0x80000000, 0x200) != -1) {
        n = e1; n++; if ((int)cb == n) {
            d_1c2098.f_144ab0(e3, 0);
            d_1c2098.f_144920(&h, 14);
            e3 = e3 + 14;
            d_1c2098.f_144ab0(h.e, 1);
            e3 += h.e;
        } else {
            short i;
            d_1c2098.f_144ab0(b7, 0);
            e3 = b7;
            for (i = 0; i < cb; i++) {
                d_1c2098.f_144920(&h, 14);
                e3 += 14;
                d_1c2098.f_144ab0(h.e, 1);
                e3 = e3 + h.e;
            }
        }
        e1 = cb;
        d_1c2098.f_144920(&h, 14);
        if (d3 != 0) {
            delete d3;
            delete dd;
            d3 = 0;
        }
        { int c = h.c; n = c * h.d; }
        dd = (char *)f_014540(n, d_1a1b04, 0xdb);
        d3 = new (mark(d_1a1b04, 0xdd)) RivaRasterImage(h.c, h.d, dd);
        if (cf != 0) {
            delete cf;
            cf = 0;
        }
        { Sub *t2 = new (mark(d_1a1b04, 0xe5)) Sub; cf = t2 ? f_010400(t2, h.a, h.b, h.c, h.d, h.e, h.f, h.g) : t2; }
        if (f_014a60() > n + h.e) {
            buf = (char *)f_014540(h.e, d_1a1b04, 0xf1);
            d_1c2098.f_144920(buf, h.e);
            d_1c2098.f_1449a0();
        }
        f_0a2520(&sub, f_010490(cf), f_010480(cf), f_010460(cf), f_010470(cf), ((int)(((RivaRasterImage*)(d3))->f_0fb0b0())), buf);
        operator delete(buf);
    }
    cc = cb;
}
