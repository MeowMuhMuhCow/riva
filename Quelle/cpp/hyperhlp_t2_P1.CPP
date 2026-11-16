/* === Beschreibung (Katalog) ===
 * Einheit hyperhlp_t2 (09db80-09f070)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil des Hypertext-Hilfesystems (HYPERHLP.CPP). Sie stellt die
 * Rückruffunktionen für die Layout- und Zeichen-Engine (f_15ae98 / f_156cf4) bereit - darunter
 * Bildgrößenabfrage, Zeichnen von Bildern, Trennlinien und gefüllten Rechtecken, Textmessung und Textausgabe
 * (wahlweise grafisch oder im Textdruckmodus) - und verwaltet außerdem die Hyperlink-Navigation per Tastatur
 * sowie die 30-stufige Seitenhistorie (Zurück-Funktion und Themenwechsel).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 10/17 gleich (suche.py 30.10.2026, Basis hyperhlp_t2_P1.CPP)
// hyperhlp.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09C9E0-0x0A16B0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_051870(int p1, int p2);                           // reg eax edx stapel 0
int f_099ea0();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0ce250();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f40(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3950(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0d9cc0();                                         // reg - stapel 0
int f_0e4cb0();                                         // reg - stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
// reg eax edx ebx ecx stapel 8
// reg eax edx ebx ecx stapel 8
int f_11e9d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13dba0(int p1, int p2);                           // reg eax edx stapel 0
int f_13e140(int p1);                                   // reg eax stapel 0
int f_13e690(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
   // reg eax edx ebx ecx stapel 4
int f_15689d(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_15c5c8(int p1);                                   // reg eax stapel 0
int f_15c640();                       // nicht in clobber.tsv
int f_15c6d0(int p1, int p2);                           // reg eax stapel 0
int f_15c700(int p1, int p2);                           // reg eax edx stapel 0
int f_15c850(int p1);                                   // reg eax stapel 0
int f_15c860(int p1);                                   // reg eax stapel 0
int f_15c870(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_15db68(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a3570;                    // 0x1A3570
extern int d_1a3578;                    // 0x1A3578
extern int d_1a357c;                    // 0x1A357C
extern int d_1a3580;                    // 0x1A3580
extern int d_1a35a8;                    // 0x1A35A8
extern int d_1a3c20;                    // 0x1A3C20
extern int d_1b6fc0;                    // 0x1B6FC0
extern int d_1b6fc1;                    // 0x1B6FC1
extern int d_1b6fd2;                    // 0x1B6FD2
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1bde14;                    // 0x1BDE14
extern int d_1bde18;                    // 0x1BDE18
extern int d_1bde1c;                    // 0x1BDE1C
extern int d_1bde20;                    // 0x1BDE20
extern int d_1bde24;                    // 0x1BDE24
extern int d_1bde28;                    // 0x1BDE28
extern short d_1bde2c;                    // 0x1BDE2C
extern int d_1bde30;                    // 0x1BDE30
extern int d_1bde44;                    // 0x1BDE44
extern int d_1bde48;                    // 0x1BDE48
extern int d_1bde4c;                    // 0x1BDE4C
extern int d_1bde50;                    // 0x1BDE50
extern int d_1bde54;                    // 0x1BDE54
extern int d_1bde58;                    // 0x1BDE58
extern int d_1bde5c;                    // 0x1BDE5C
extern int d_1bde60;                    // 0x1BDE60
extern int d_1bde64;                    // 0x1BDE64
extern int d_1bde68;                    // 0x1BDE68
extern int d_1bde6c;                    // 0x1BDE6C
extern int d_1bde70;                    // 0x1BDE70
extern int d_1bde74;                    // 0x1BDE74
extern int d_1bde78;                    // 0x1BDE78
extern int d_1bde7c;                    // 0x1BDE7C
extern int d_1bde80;                    // 0x1BDE80
extern int d_1bde84;                    // 0x1BDE84
extern int d_1bde88;                    // 0x1BDE88
extern int d_1bde8c;                    // 0x1BDE8C
extern int d_1bde94;                    // 0x1BDE94
extern int d_1bde98;                    // 0x1BDE98
extern unsigned char d_1bde9c;          // 0x1BDE9C
extern int d_1bdea0;                    // 0x1BDEA0
extern int d_1bdfac;                    // 0x1BDFAC
extern int d_1bdfb4;                    // 0x1BDFB4
extern int d_1bdfc4;                    // 0x1BDFC4
extern int d_1bdfe4;                    // 0x1BDFE4
extern int d_1bdfe8;                    // 0x1BDFE8
extern int d_1bdff0;                    // 0x1BDFF0
extern int d_1bdff2;                    // 0x1BDFF2
extern int d_1bdff4;                    // 0x1BDFF4
extern int d_1bdff6;                    // 0x1BDFF6
extern int d_1bdff8;                    // 0x1BDFF8
extern int d_1bdffa;                    // 0x1BDFFA
extern int d_1bdffc;                    // 0x1BDFFC
extern int d_1bdffe;                    // 0x1BDFFE
extern int d_1be000;                    // 0x1BE000
extern int d_1be002;                    // 0x1BE002
extern int d_1be004;                    // 0x1BE004
extern int d_1be006;                    // 0x1BE006
extern int d_1be008;                    // 0x1BE008
extern int d_1be00a;                    // 0x1BE00A
extern int d_1be00c;                    // 0x1BE00C
extern int d_1be00e;                    // 0x1BE00E
extern int d_1be010;                    // 0x1BE010
extern int d_1be012;                    // 0x1BE012
extern int d_1be014;                    // 0x1BE014
extern int d_1be016;                    // 0x1BE016
extern int d_1be018;                    // 0x1BE018
extern int d_1be01a;                    // 0x1BE01A
extern int d_1be01c;                    // 0x1BE01C
extern int d_1be01e;                    // 0x1BE01E
extern int d_1be020;                    // 0x1BE020
extern int d_1be022;                    // 0x1BE022
extern int d_1be024;                    // 0x1BE024
extern int d_1be026;                    // 0x1BE026
extern int d_1be028;                    // 0x1BE028
extern int d_1be02a;                    // 0x1BE02A
extern int d_1be02c;                    // 0x1BE02C
extern int d_1be02e;                    // 0x1BE02E
extern int d_1be030;                    // 0x1BE030
extern int d_1be032;                    // 0x1BE032
extern int d_1be034;                    // 0x1BE034
extern int d_1be038;                    // 0x1BE038
extern int d_1be0bc;                    // 0x1BE0BC
extern int d_1be0c0;                    // 0x1BE0C0
extern int d_1be0d8;                    // 0x1BE0D8
extern int d_1be0dc;                    // 0x1BE0DC
extern int d_1be160;                    // 0x1BE160
extern int d_1bf4f0;                    // 0x1BF4F0
extern int d_1bf4f2;                    // 0x1BF4F2
extern int d_1bfaf0;                    // 0x1BFAF0
extern int d_1c0088;                    // 0x1C0088
extern int d_1c008c;                    // 0x1C008C
extern int d_1c0098;                    // 0x1C0098
extern int d_1c20b0;                    // 0x1C20B0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern const char d_1a3584[];           // Text 0x1A3584
extern const char d_1b6f98[];           // Text 0x1B6F98
extern const char d_1b6fa5[];           // Text 0x1B6FA5
extern const char d_1b6fb2[];           // Text 0x1B6FB2
extern const char d_1b6fd7[];           // Text 0x1B6FD7
extern const char d_1b6ff7[];           // Text 0x1B6FF7
extern const char d_1b6ffe[];           // Text 0x1B6FFE
extern const char d_1b7008[];           // Text 0x1B7008
extern const char d_1b7015[];           // Text 0x1B7015
extern const char d_1b704e[];           // Text 0x1B704E
extern const char d_1b7059[];           // Text 0x1B7059
extern const char d_1b7063[];           // Text 0x1B7063
extern const char d_1b706a[];           // Text 0x1B706a
extern const char d_1b7075[];           // Text 0x1B7075
extern const char d_1b7081[];           // Text 0x1B7081
extern const char d_1b708b[];           // Text 0x1B708B
// --- Uebersteuerungen (Pass 1, Helfer B) ---
#define EQI(x,v) (((x)==(v))?1:0)
struct R { int l, t, r, b; };
struct P2 { int a, b; };
struct B8 { int a, b; };
struct Rec { int used; char name[0x50]; int pos; };
struct Gfx { virtual int v0(); virtual void v1(int c, int x, int y, char *p, int s); virtual unsigned char v2(int c); virtual unsigned char v3(); };
extern short d_1bdfb0;
extern int d_1bdfb8;
extern int d_1bdfbc;
extern int d_1bdfc0;
extern struct R d_1bdfc8;
extern char d_1bdfd8[8];
extern unsigned short d_1bdfe0;
extern short d_1bdfe2;
extern char *d_1bdfec;
extern struct Gfx *d_1bde3c;
extern struct Gfx *d_1bde40;
extern unsigned char d_1bdd14[256];
extern unsigned char d_1bdeac[256];
extern char *d_1bdea4;
extern char *d_1bdea8;
extern struct Rec *d_1bde90;
extern const char d_1b7022[];
extern const char d_1b702a[];
extern const char d_1b702c[];
extern const char d_1b7034[];
extern const char d_1b7037[];
extern const char d_1b703a[];
extern const char d_1b703d[];
extern const char d_1b7040[];
extern const char d_1b7043[];
extern const char d_1b7046[];
extern const char d_1b7049[];


int f_156cf4(int);
int f_15ae98(int, int, struct R *);
int f_15d744(int);
struct R f_15d90c(int);
struct P2 f_15dadc(int);
int f_0d26e0();
int f_0e9240(int);
int f_0d2f90(int, int);
int f_15d4d0(int);
int f_15d584(int);
int f_15d4dc();
int f_09ce70(unsigned char *);
void f_09cf80(int, int, int, int, int);
int f_09d640(char *);
int f_09d540(char *);
#define REFILL if (d_1a3c20 != 0) { int _i; d_1a3c20 = 0; _i = 0; do { struct Gfx *_g; if (d_1bdfb8 != 0) _g = d_1bde40; else _g = d_1bde3c; d_1bdd14[_i] = _g->v2(d_1bdeac[_i]); _i++; } while (_i < 0x100); }
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_09db80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die Breite und Höhe eines im Hilfetext eingebetteten Bildes p1 und schreibt sie in
 *   *p2 und *p3 (wobei im Textdruckmodus d_1bdfb0 != 0 feste Dummy-Maße von 8 x 1 Zeichen zurückgegeben werden).
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildnamen p1 (char *) sowie die Ausgabeparameter p2 und p3
 *   (int *) und gibt 1 bei Erfolg oder 0 bei unbekanntem Bild zurück (int).
 * - Wichtige Variablen: Das Bild wird über f_09d640 aus dem Hilfebild-Cache geholt und über f_0fb210 nach seinen
 *   Abmessungen gefragt.
 === Ende Beschreibung === */
extern int flag_1bdfb0;
#pragma aux flag_1bdfb0 "d_1bdfb0";
int f_09db80(char *p1, int *p2, int *p3)
{
  short b[2]; short a[2];
  int r = f_09d640(p1);
  d_1bdfb8 = (d_1bdfb8 & 0) ? 0 : d_1bdfb8; // haelt die Registerzuteilung wie im Original
  if (flag_1bdfb0 != 0) {
    *p2 = 8;
    *p3 = 1;
    return 1;
  }
  if (r != 0) {
    ((RivaRasterImage*)(r))->f_0fb210((short *)( a),(short *)( b));
    *p2 = a[0];
    *p3 = b[0];
    return 1;
  }
  return r;
}
//@ f_09dbe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den globalen Zeichenursprung (d_1bde7c, d_1bde80) für nachfolgende Ausgaben der
 *   Hypertext-Engine.
 * - Eingaben und Rückgabe: Die Funktion erhält den X-Versatz p1 sowie den Y-Versatz p2 (int) und gibt p1 zurück
 *   (int).
 * - Wichtige Variablen: Die globalen Variablen d_1bde7c und d_1bde80 werden bei allen Zeichenoperationen im
 *   Hilfepuffer zu den übergebenen Koordinaten addiert.
 === Ende Beschreibung === */
int f_09dbe0(int p1, int p2)
{
  d_1bde7c = p1;
  d_1bde80 = p2;
  return p1;
}
//@ f_09dbf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Rückruffunktion für die Hypertext-Engine ohne Operation.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */
void f_09dbf0(void)
{
}
//@ f_09dc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Clipping-Rechteck d_1bdfc8 des Hilfepuffers auf das um den aktuellen Ursprung
 *   (d_1bde7c, d_1bde80) verschobene Rechteck *p.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct R *) auf das lokale Clipping-Rechteck und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Struktur d_1bdfc8 speichert die vier Grenzen l, t, r und b in Pufferkoordinaten.
 === Ende Beschreibung === */
void f_09dc00(struct R *p) {
 struct R r;
 struct Build700 {static void init(R &o,int l,int t,int r,int b){o.l=l;o.t=t;o.r=r;o.b=b;}};
 Build700::init(r,p->l+d_1bde7c,p->t+d_1bde80,p->r+d_1bde7c,p->b+d_1bde80);
 d_1bdfc8=r;
}
//@ f_09dc50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet ein im Hilfetext eingebettetes Bild p1 an die Position (p2, p3) im Hilfepuffer.
 *   Handelt es sich um eine der drei dekorativen Trennleisten (d_1b6ffe, d_1b7008, d_1b7015), wird das Bild in
 *   fünf Segmente zerlegt und durch Wiederholen der linken und rechten Endstücke dynamisch auf die aktuelle
 *   Seitenbreite d_1bde2c gestreckt; alle anderen Bilder werden normal über f_09d900_in gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildnamen p1 (char *), die Koordinaten p2 und p3 sowie das
 *   Transparenzflag p4 und gibt 1 bei Erfolg oder 0 bei Ladefehler zurück (int).
 * - Wichtige Variablen: Im Textdruckmodus (d_1bdfb0 != 0) oder beim Platzhalterbild d_1b6ff7 kehrt die Funktion
 *   sofort mit 1 zurück, ohne zu zeichnen.
 === Ende Beschreibung === */
int f_14d717(const char *, const char *);
static inline int f_09d900_in(int p1, int p2, int p3, int p4)
{
    short copy_width, width, height;
    char *source;
    unsigned char *screen;
    if (p1 == 0) return 0;
    ((RivaRasterImage*)(p1))->f_0fb210((short *)( &width),(short *)( &height));
    if (p2 <= d_1bdfc8.r && p3 <= d_1bdfc8.b &&
        width + p2 >= d_1bdfc8.l && height + p3 >= d_1bdfc8.t) {
        source = ((RivaRasterImage*)(p1))->f_0fb0b0();
        screen = (unsigned char *)d_1bdfec + *(int *)&d_1bde2c * p3 + p2;
        copy_width = width;
        height = height - 1;
        if (p3 < d_1bdfc8.t) {
            height -= d_1bdfc8.t - p3;
            source += width * (d_1bdfc8.t - p3);
            screen += (d_1bdfc8.t - p3) * *(int *)&d_1bde2c;
            p3 = d_1bdfc8.t;
        }
        if (p2 < d_1bdfc8.l) {
            copy_width -= d_1bdfc8.l - p2;
            source += d_1bdfc8.l - p2;
            screen += d_1bdfc8.l - p2;
            p2 = d_1bdfc8.l;
        }
        if (copy_width + p2 > d_1bdfc8.r)
            copy_width -= p2 + copy_width - d_1bdfc8.r;
        if (height + p3 > d_1bdfc8.b)
            height -= p3 + height - d_1bdfc8.b;
        if (!p4) {
            for (; height >= 0; height--) {
                memcpy(screen, source, copy_width);
                source += width;
                screen += *(int *)&d_1bde2c;
            }
        } else {
            signed char c;
            for (; height >= 0; height--) {
                for (p2 = 0; p2 < copy_width; p2++) {
                    if ((c = *source++) != 0) *screen = c;
                    screen++;
                }
                screen += *(int *)&d_1bde2c - copy_width;
                source += width - copy_width;
            }
        }
    }
    return 1;
}

int f_09dc50(char *p1, int p2, int p3, int p4)
{
    
    int img;
    int xoff;
    short w1, h1;
    signed char c;


    if (*(int *)&d_1bdfb0 != 0 || f_14d717(p1, d_1b6ff7) == 0)
        return 1;
    { int u = p4; p4 = u; } // haelt die Registerzuteilung wie im Original
    { int u = p4; p4 = u; }
    img = f_09d640(p1);
    if (img == 0)
        return 0;
    if (!(f_14d717(p1, d_1b6ffe) != 0 && f_14d717(p1, d_1b7008) != 0 && f_14d717(p1, d_1b7015) != 0)) {
        int rep = 0, seg;
        char *source;
        char *screen;
        int i = 0, j;
        ((RivaRasterImage*)(img))->f_0fb210((short *)( &w1),(short *)( &h1));
        p3 += d_1bde80;
        p2 += d_1bde7c;
        if (p3 >= 0 && p3 + h1 < d_1bde30 && p2 >= 0 && p2 + w1 < *(int *)&d_1bde2c) {
            seg = w1 / 5;
            rep = ((*(int *)&d_1bde2c - 20 - seg * 3) / seg) / 2;
            { int u = rep; rep = u; } // haelt die Registerzuteilung wie im Original
            xoff = (*(int *)&d_1bde2c - (rep * 2 + 3) * seg) / 2;
            screen = d_1bdfec + (p3 + 4) * *(int *)&d_1bde2c + xoff;
            source = ((RivaRasterImage*)(img))->f_0fb0b0() + w1 * 4;
            for (p3 = 4; p3 < h1; p3++) {
                j = 0;
                { int u = j; j = u; } // haelt die Registerzuteilung wie im Original
                for (; j < rep; j++) {
                    for (i = 0; i < seg; i++) {
                        if ((c = source[i]) != 0)
                            *(screen + j * seg + i) = c;
                    }
                }
                for (i = 0; i < seg * 3; i++) {
                    { int v_rt = d_1bdfb8; d_1bdfb8 = v_rt; } // haelt die Ladereihenfolge wie im Original
                    if ((c = source[seg + i]) != 0)
                        *(screen + rep * seg + i) = c;
                }
                i = (i & 0) ? 0 : i; // haelt die Registerzuteilung wie im Original
                xoff = seg * 4; // haelt die Auswertungsreihenfolge wie im Original
                xoff = seg * 4;
                for (j = 0; j < rep; j++) {
                    xoff = (int)source; // haelt die Auswertungsreihenfolge wie im Original
                    for (i = 0; i < seg; i++) {
                        if ((c = *(source + i + seg * 4)) != 0)
                            *(screen + (j + rep + 3) * seg + i) = c;
                    }
                }
                source += w1;
                screen += *(int *)&d_1bde2c;
            }
        }
        return 1;
    }
    return f_09d900_in(img, p2 + d_1bde7c, p3 + d_1bde80, p4);
}

//@ f_09e100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im Grafikmodus (d_1bdfb0 == 0) eine um den Ursprung (d_1bde7c, d_1bde80) verschobene
 *   Linie von (p1, p2) nach (p3, p4) in der zum RGB-Tripel p5 nächstgelegenen Hilfepalettenfarbe (f_09ce70).
 * - Eingaben und Rückgabe: Die Funktion erhält die Koordinaten p1, p2, p3, p4 sowie den RGB-Farbzeiger p5 und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Linienzeichnung erfolgt über f_09cf80.
 === Ende Beschreibung === */
void f_09e100(int p1, int p2, int p3, int p4, int p5)
{
  if (*(int *)&d_1bdfb0 == 0) {
    p1 += d_1bde7c;
    p3 += d_1bde7c;
    p2 += d_1bde80;
    p4 += d_1bde80;
    f_09cf80(p1, p2, p3, p4, f_09ce70((unsigned char *)p5));
  }
}
//@ f_09e140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im Grafikmodus (d_1bdfb0 == 0) ein ausgefülltes Rechteck am Punkt (p1, p2) mit der
 *   Breite p3 und der Höhe p4 durch zeilenweises Ziehen horizontaler Linien (f_09cf80) in der zu p5 gehörenden
 *   Palettenfarbe.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startkoordinaten p1, p2, die Ausdehnung p3, p4 sowie den
 *   RGB-Farbzeiger p5 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Jede sichtbare Zeile y im Bereich 0 <= y < d_1bde30 wird einzeln gezeichnet.
 === Ende Beschreibung === */
void f_09e140(int p1, int p2, int p3, int p4, int p5)
{
  int x1, end;
  if (*(int *)&d_1bdfb0 == 0) {
    p1 += d_1bde7c;
    p2 += d_1bde80;
    int y = p2;
    end = p2 + p4;
    x1 = p1 + p3;
    for (; y < end; y++) {
      if (y >= 0 && y < d_1bde30) {
        int c = f_09ce70((unsigned char *)p5);
        f_09cf80(p1, y, x1, y, c);
      }
    }
  }
}
//@ f_09e1b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Invalidierungsflag d_1bdfc0 = 1, damit beim nächsten Setzen der Textattribute
 *   (f_09e1c0 / f_09e330) die Schriftfarbe auf jeden Fall neu berechnet wird.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdfc0 erzwingt die Aktualisierung des 8-Byte-Schriftattributblocks d_1bdfd8.
 === Ende Beschreibung === */
void f_09e1b0(void)
{
  d_1bdfc0 = 1;
}
//@ f_09e1c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übernimmt einen 8-Byte-Schriftattributblock p1 (mit Unterstreichungsflag und RGB-Schriftfarbe
 *   ab p1 + 5) in den globalen Zustand d_1bdfd8, sofern sich die Attribute geändert haben oder d_1bdfc0 gesetzt
 *   war, und ermittelt den zugehörigen Palettenindex d_1bdfe0 über f_09ce70.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned char *) auf den 8-Byte-Attributblock und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable d_1bdfe0 speichert die ermittelte Textvordergrundfarbe, und d_1bdfe2 wird
 *   auf -1 (transparenter Texthintergrund) gesetzt.
 === Ende Beschreibung === */
void f_09e1c0(unsigned char *p1)
{
  if (d_1bdfc0 == 0) {
    if (memcmp(p1, d_1bdfd8, 8) == 0) {
      return;
    }
  }
  d_1bdfc0 = 0;
  *(struct B8 *)d_1bdfd8 = *(struct B8 *)p1;
  d_1bdfe0 = f_09ce70(p1 + 5);
  d_1bdfe2 = -1;
}
//@ f_09e220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Breite und Höhe eines Textstücks s der Länge n mit den Schriftattributen font.
 *   Im Textdruckmodus (d_1bdfb0 != 0) zählt die Funktion die Zeichenanzahl (wobei deutsche Umlaute in d_1b7022
 *   wegen ihrer Umschreibung als ae/oe/ue/ss doppelt zählen) bei Höhe 1; im Grafikmodus summiert sie die
 *   Pixelbreiten aus d_1bdd14 bei Zeilenhöhe d_1bde50.
 * - Eingaben und Rückgabe: Die Funktion erhält den Textzeiger s (unsigned char *), die Zeichenanzahl n (int)
 *   sowie den Attributblock font (char *) und gibt ein TextSize670-Paar (w, h) zurück.
 * - Wichtige Variablen: Bei gesetztem Flag d_1a3c20 wird die Zeichenbreitentabelle d_1bdd14 vor der Summierung
 *   aus der aktiven Schriftart (d_1bde3c oder d_1bde40) neu aufgebaut.
 === Ende Beschreibung === */
struct TextSize670 {int w,h;TextSize670(int width,int height){w=width;h=height;}};
TextSize670 f_09e220(unsigned char *s, int n, char *font)
{
  int w;
  if (*(int *)&d_1bdfb0 != 0) {
    unsigned char *p;
    int i;
    w = 0;
    i = 0;
    if (i < n) {
      p = s;
      do {
        w++;
        if (d_1bde20 == 1 && strchr(d_1b7022, *p)) w++;
        i++;
        p++;
      } while (i < n);
    }
    return TextSize670(w, 1);
  } else {
    int h = d_1bde50 + (font[4] != (char)0);
    unsigned char *p = s;
    int i;
    w = 0;
    if (d_1a3c20 != 0) {
      d_1a3c20 = 0;
      for (i = 0; i < 0x100; i++) {
        struct Gfx *g;
        if (d_1bdfb8 != 0) g = d_1bde40; else g = d_1bde3c;
        d_1bdd14[i] = g->v2(d_1bdeac[i]);
      }
    }
    { unsigned char *q; int k; k = 0; if (k < n) { q = p; do { w += d_1bdd14[*q]; q++; k++; } while (k < n); } }
    return TextSize670(w, h);
  }
}
//@ f_09e330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die aktuellen Schriftattribute anhand von p1, fragt die Zeilenhöhe der aktiven
 *   Schriftart ab (im SVGA-Modus d_1bdfb8 != 0 zuzüglich 2 Pixel Zeilenabstand) und gibt im Druckmodus 1, sonst
 *   die Pixelhöhe d_1bde50 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den 8-Byte-Schriftattributblock p1 (unsigned char *) und gibt die
 *   Zeilenhöhe zurück (int).
 * - Wichtige Variablen: Die Variable d_1bde50 speichert die ermittelte Zeilenhöhe in Pixeln.
 === Ende Beschreibung === */
// Der Fontcache-Teil (ehemals inline eingebettet; als static-Helfer geschrieben,
// Watcom bettet ihn mit -oneatx wieder ein -> Register ebx/ebp wie im Original).
static inline void zc_set(unsigned char *p1)
{
  if (d_1bdfc0 == 0) {
    if (memcmp(p1, d_1bdfd8, 8) == 0) return;
  }
  d_1bdfc0 = 0;
  *(struct B8 *)d_1bdfd8 = *(struct B8 *)p1;
  d_1bdfe0 = f_09ce70(p1 + 5);
  d_1bdfe2 = -1;
}
int f_09e330(unsigned char *p1)
{
  struct Gfx *g;
  zc_set(p1);
  if (d_1bdfb8 != 0) g = d_1bde40; else g = d_1bde3c;
  d_1bde50 = (unsigned char)g->v3() + (d_1bdfb8 != 0 ? 2 : 0);
  return *(int *)&d_1bdfb0 != 0 ? 1 : d_1bde50;
}
//@ f_09e3e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt als Rückruffunktion der Hypertext-Engine konstant 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt 0 zurück (int).
 * - Wichtige Variablen: Die Funktion verwendet keine Variablen.
 === Ende Beschreibung === */
int f_09e3e0(void)
{
  return 0;
}
//@ f_09e3f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein Textstück p3 der Länge p4 an der Position (p1, p2) mit den Attributen p5 aus. Im
 *   Grafikmodus (d_1bdfb0 == 0) zeichnet die Funktion den Text (samt eventueller Link-Unterstreichung) über
 *   f_09d230_in in den Hilfepuffer; im Druckmodus (d_1bdfb0 != 0) füllt sie Leerzeilen und Leerzeichen bis zur
 *   Zielspalte (p1, p2) auf, wandelt deutsche Umlaute in zweibuchstabige ASCII-Umschreibungen (ae, oe, ue, Ae,
 *   Oe, Ue, ss) um und hängt den Text an den Druckzeilenpuffer d_1bdea4 an.
 * - Eingaben und Rückgabe: Die Funktion erhält die Koordinaten p1 und p2, den Textzeiger p3 (unsigned char *),
 *   die Länge p4 sowie den Attributblock p5 (unsigned char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Im Druckmodus verfolgen d_1bde44 und d_1bde48 die aktuelle Druckspalte und Druckzeile,
 *   während f_0e9240 abgeschlossene Zeilen an den Drucker oder die Ausgabedatei schickt.
 === Ende Beschreibung === */
extern char d_1bdfdc;
extern short d_1bdfde;
struct VO_t2 { char *vt; };
typedef unsigned char (*FPC_t2)(VO_t2 *, int);
typedef int (*FPCD_t2)(VO_t2 *, unsigned char, short, short, void *, int);
#define VC_t2(o,off,T) (*(T *)((o)->vt + (off)))

static inline int f_09d230_w(unsigned char *p1, int p2)
{
    int sum = 0;
    int i = 0;
    if (d_1a3c20 != 0) {
        d_1a3c20 = 0;
        for (i = 0; i < 0x100; ++i) {
            VO_t2 *o;
            if (d_1bdfb8 != 0) o = (VO_t2 *)d_1bde40;
            else o = (VO_t2 *)d_1bde3c;
            d_1bdd14[i] = VC_t2(o, 8, FPC_t2)(o, d_1bdeac[i]);
        }
    }
    for (i = 0; i < p2; ++i)
        sum += d_1bdd14[p1[i]];
    return sum;
}

static inline void f_09d230_in(unsigned char *p1, int p2, int p3, int p4)
{
    int c;
    int w;
    int i = 0;

    for (; i < p2; i++) {
        c = d_1bdeac[p1[i]];
        w = f_09d230_w(p1 + i, 1);
        if (p3 >= 0 && p3 + w < *(int *)&d_1bde2c && p4 >= 0 && p4 + d_1bde50 < d_1bde30) {
            if (d_1bde68 == p4 && d_1bde64 >= 0 && d_1bde64 <= p3) {
                VO_t2 *o;
                if (d_1bdfb8 != 0) o = (VO_t2 *)d_1bde40;
                else o = (VO_t2 *)d_1bde3c;
                if (d_1bde64 + 2 * VC_t2(o, 8, FPC_t2)(o, 0x20) > p3)
                    goto keepcursor;
            }
            d_1bde64 = p3;
        keepcursor:
            if (*(short *)&d_1bdfe0 == 0xfe) d_1bdfe0 = 0x36;
            if (*(short *)&d_1bdfe0 == 0xba) d_1bdfe0 = 0x40;
            if (*(short *)&d_1bdfe0 == 0xb6) d_1bdfe0 = 0xfc;
            {
                VO_t2 *o;
                if (d_1bdfb8 != 0) o = (VO_t2 *)d_1bde40;
                else o = (VO_t2 *)d_1bde3c;
                VC_t2(o, 4, FPCD_t2)(o, (unsigned char)c, (short)p3, (short)(p4 + 0x7d0), &d_1bdfde, d_1bdfe2);
            }
            p3 += w;
            if (d_1bdfdc && *(short *)&d_1bdfe0 == 0x36) {
                f_09cf80(d_1bde64, p4 + d_1bde50 - (d_1bdfb8 != 0 ? 2 : 0), p3 - 1,
                         p4 + *(volatile int *)&d_1bde50 - (d_1bdfb8 != 0 ? 2 : 0), *(short *)&d_1bdfe0);
                d_1bde64 = p3;
            } else {
                d_1bde64 = -1;
            }
            d_1bde68 = p4;
        } else {
            d_1bde68 = -1;
            d_1bde64 = -1;
            break;
        }
    }
}

void f_09e3f0(int p1, int p2, unsigned char *p3, int p4, unsigned char *p5)
{
    int i;
    if (*(int *)&d_1bdfb0 != 0) {
        if (p2 > d_1bde48 + 2) {
            d_1bde48 = p2 - 2;
        }
        while (p2 > d_1bde48) {
            f_0e9240((int)d_1bdea4);
            *d_1bdea4 = 0;
            d_1bde48++;
            d_1bde44 = 0;
        }
        while (p1 > d_1bde44) {
            strcat(d_1bdea4, d_1b702a);
            d_1bde44++;
        }
        for (i = 0; i < p4; i++) {
            if (d_1bde20 == 1 && strchr(d_1b702c, p3[i]) != 0) {
                switch (d_1bdeac[p3[i]]) {
                case 0x84:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b7034, 2);
                    break;
                case 0x81:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b7037, 2);
                    break;
                case 0x94:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b703a, 2);
                    break;
                case 0x8e:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b703d, 2);
                    break;
                case 0x99:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b7040, 2);
                    break;
                case 0x9a:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b7043, 2);
                    break;
                case 0xe1:
                    d_1bde44 += 2;
                    strncat(d_1bdea4, d_1b7046, 2);
                    break;
                default:
                    d_1bde44++;
                    strncat(d_1bdea4, (const char *)&d_1bdeac[p3[i]], 1);
                    break;
                }
            } else {
                d_1bde44++;
                strncat(d_1bdea4, (const char *)&d_1bdeac[p3[i]], 1);
            }
        }
    } else {
        zc_set(p5);
        f_09d230_in(p3, p4, p1 + d_1bde7c, p2 + d_1bde80);
    }
}

//@ f_09e9c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht innerhalb des Suchrechtecks p1 den letzten sichtbaren Hyperlink (f_15d744 / f_15d584),
 *   stellt am Ende die Markierung des aktuell gewählten Links d_1bde84 über f_15d4d0 wieder her und gibt den
 *   gefundenen Link-Index zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Suchrechteck und gibt den Index des letzten
 *   darin liegenden Hyperlinks oder -1 zurück (int).
 * - Wichtige Variablen: Die Variable d_1bde84 hält den Index des aktuell fokussierten Hyperlinks.
 === Ende Beschreibung === */
int f_09e9c0(int p1)
{
  int cur, last;
  last = -1;
  cur = f_15d744(p1);
  if (cur != last)
    goto check;
  f_15d4d0(d_1bde84);
  return last;
check:
  if (cur != -1)
    goto body;
  f_15d4d0(d_1bde84);
  return last;
body:
  f_15d4d0(cur);
  last = cur;
  cur = f_15d584(p1);
  goto check;
}
//@ f_09ea10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Navigiert bei Tastendruck (Rückwärtstabulator / Umschalttaste+Tab) innerhalb des Suchbereichs
 *   p1 zum jeweils vorhergehenden Hyperlink vor d_1bde84 (oder zum letzten Link im Bereich, falls d_1bde84 == -1
 *   oder außerhalb von p1 liegt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (int *) auf das Suchrechteck und gibt den Index des
 *   neu ausgewählten Hyperlinks oder -1 zurück (int).
 * - Wichtige Variablen: Die Hypertext-Engine-Funktionen f_15d744 und f_15d584 durchlaufen die verkettete Liste
 *   der Hyperlinks auf der aktuellen Seite.
 === Ende Beschreibung === */
int f_09ea10(int *p1)
{
  int f_15d584(int, int);
  struct R *f_15d90c(struct R *, int);
  int cur, last, previous;
  int *query;
  struct R r, tmp;
  if (d_1bde84 == -1) {
    query = p1;
    last = d_1bde84;
    cur = f_15d744((int)query);
    if (cur == last) {
      f_15d4d0(d_1bde84);
      return -1;
    }
    for (;;) {
      if (cur == -1) {
        f_15d4d0(d_1bde84);
        return last;
      }
      f_15d4d0(cur);
      last = cur;
      cur = f_15d584((int)query, cur);
    }
  }

  r = *f_15d90c(&tmp, d_1bde84);
  if (r.l < p1[0] || r.t < p1[1] || r.r > p1[2] || r.b > p1[3]) {
    last = -1;
    query = p1;
    cur = f_15d744((int)query);
    if (cur == last) {
      f_15d4d0(d_1bde84);
      return last;
    }
    for (;;) {
      if (cur == -1) {
        f_15d4d0(d_1bde84);
        return last;
      }
      f_15d4d0(cur);
      last = cur;
      cur = f_15d584((int)query, cur);
    }
  }

  last = -1;
  previous = cur = d_1bde84;
  for (;;) {
    previous = cur;
    cur = f_15d584((int)p1, cur);
    if (cur == last) {
      previous = last;
      cur = f_15d744((int)p1);
    }
    if (cur == d_1bde84) {
      f_15d4dc();
      f_15d4d0(d_1bde84);
      return previous;
    }
    f_15d4dc();
    f_15d4d0(cur);
  }
}
//@ f_09eb60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Springt in der 30-stufigen Seitenhistorie (d_1bde90) des Hilfesystems um einen Eintrag zurück
 *   (Zurück-Taste / Backspace / Rechtsklick). Wechselt dabei der Dateiname der Hilfeseite (d_1bdea8), wird die
 *   vorherige Seite über f_156cf4 neu geladen und an die gespeicherte Scrollposition pos (d_1bde74) gesetzt.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Ringpuffer d_1bde90 umfasst 30 Einträge (0..0x1d) mit dem aktuellen Schreibindex
 *   d_1bde70 und dem Füllstandszähler d_1bde4c.
 === Ende Beschreibung === */
int f_14d717(const char *, const char *);
static inline void mkr(R &o,int l,int t,int r,int b){o.l=l;o.t=t;o.r=r;o.b=b;}
static inline void setz(int l, int t, int rr, int b)
{
  R r;
  r.l = l; r.t = t; r.r = rr; r.b = b;
  d_1bdfc8 = r;
}
static inline void versch(const R *p)
{
  setz(p->l + d_1bde7c, p->t + d_1bde80, p->r + d_1bde7c, p->b + d_1bde80);
}
void f_09eb60(void)
{
  int old, n, w1, h1;
  struct R pair0, pair1;
  if (d_1bde70 < 0)
    return;
  n = d_1bde70;
  { int rt = n; n = rt; }
  old = n;
  d_1bde70 = old - 1;
  if (d_1bde70 < 0)
    d_1bde70 = 0x1d;
  struct Rec *p = &d_1bde90[d_1bde70];
  if (p->used == 0) {
    { int rt = old; old = rt; }
    d_1bde70 = old;
    return;
  }
  p->used = 0;
  --d_1bde4c;
  f_0d2f90(5, 1);
  f_0d26e0();
  if (f_14d717(d_1bdea8, d_1bde90[d_1bde70].name) != 0) {
    strcpy(d_1bdea8, d_1bde90[d_1bde70].name);
    h1 = d_1bde30 - 1;
    w1 = *(int *)&d_1bde2c - 1;
    mkr(pair1, 0, 0, w1, h1);
    versch(&pair1);
    f_15ae98((f_156cf4((int)d_1bdea8), pair0.l = 0, pair0.t = 0, pair0.r = 0, pair0.b = 0, 0), 0, &pair0);
    d_1bdfbc = 1;
  }
  d_1bde84 = -1;
  f_15d4dc();
  d_1bde74 = d_1bde90[d_1bde70].pos;
}


//@ f_09ece0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt ein neues Hilfethema anhand des Verweisziels p1 (das optional einen Dateinamen vor . und
 *   einen Sprungmarken-Anker nach # enthalten kann), sichert zuvor die aktuelle Seite und Scrollposition in der
 *   Historie d_1bde90, parst die neue Seite über f_156cf4 und positioniert den sichtbaren Ausschnitt d_1bde74
 *   gegebenenfalls auf den Anker #... (f_15db68 / f_15dadc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Verweistext p1 (char *) und gibt 1 zurück, wenn die
 *   Hilfeseite oder Sprungmarke gefunden wurde, andernfalls 0 (int).
 * - Wichtige Variablen: Das globale Array d_1bdea8 speichert den Dateinamen der aktuell geladenen Hilfeseite
 *   (mit erzwungener Endung aus d_1b7049).
 === Ende Beschreibung === */
int f_09ece0(char *p1)
{
  int res;
  P2 pp;
  int n;
  char *a, *bq, *c, *dot, *hash;
  int off, id, w1, h1;
  R z, ra;
  void f_15dadc(P2 *, int);
  hash = strchr(p1, '#');
  strchr(p1, '.');
  res = 0;
  f_0d2f90(5, 1);
  f_0d26e0();
  off = hash - p1;
  if (d_1bde70 >= 0) {
    Rec *rec = &d_1bde90[d_1bde70];
    rec->pos = d_1bde74;
    strcpy(rec->name, d_1bdea8);
  }
  if (hash != 0) {
    a = new (mark(d_1a3584, 0x824)) char[off + 1];
    strncpy(a, p1, off);
    off++;
    bq = new (mark(d_1a3584, 0x826)) char[strlen(p1) - off + 1];
    strcpy(bq, p1 + off);
  } else {
    a = new (mark(d_1a3584, 0x82b)) char[strlen(p1) + 1];
    strcpy(a, p1);
    bq = 0;
  }
  if (a != 0) {
    dot = strrchr(a, '.');
    if (dot != 0) {
      *dot = '\0';
      c = new (mark(d_1a3584, 0x839)) char[(dot - a) + 5];
      strcpy(c, a);
      strcat(c, d_1b7049);
      delete a;
      a = c;
    }
    if (strlen(a) > 0 && f_09d540(a) != 0) {
      h1 = d_1bde30 - 1;
      { int t = h1; h1 = t; } // haelt die Registerzuteilung wie im Original
      w1 = *(int *)&d_1bde2c - 1;
      mkr(ra, 0, 0, w1, h1);
      versch(&ra);
      f_156cf4((int)a);
      d_1bde74 = -d_1bde50 * 2;
      strcpy(d_1bdea8, a);
      res = 1;
    }
    z.l = 0;
    z.t = 0;
    z.r = 0;
    z.b = 0;
    f_15ae98(0, 0, &z);
    d_1bde84 = -1;
    d_1bdfbc = 1;
    delete a;
  }
  if (bq != 0) {
    n = f_15db68((int)bq);
    if (n != -1) {
      if (n != -1) { n = (n & 0) ? 0 : n; } // haelt die Registerzuteilung wie im Original
      f_15dadc(&pp, n);
      d_1bde74 = pp.b - d_1bde60;
      res = 1;
    }
    delete bq;
  }
  { int t = res; res = t; } // haelt die Registerzuteilung wie im Original
  if (res != 0) {
    if (d_1bde70 >= 0) {
      d_1bde90[d_1bde70].used = 1;
      if (++d_1bde4c >= 0x1e) {
        d_1bde4c = 0x1d;
      }
    }
    if (++d_1bde70 >= 0x1e) {
      d_1bde70 = 0;
    }
  }
  return res;
}
