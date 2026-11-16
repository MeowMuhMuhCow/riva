/* === Beschreibung (Katalog) ===
 * Einheit hyperhlp_t1 (09c9e0-09db80)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des kontextsensitiven Hypertext-Hilfesystems (HYPERHLP.CPP) von *Schatten
 * über Riva*. Sie initialisiert die beiden Hilfearchive, enthält die Druckfunktion zum Ausgeben einer einzelnen
 * Hilfeseite oder des gesamten Handbuchs in eine Datei bzw. auf den Drucker, stellt Zeichen- und
 * Textausgaberoutinen für den Hypertext-Puffer bereit und verwaltet einen 8-teiligen Bild-Cache für eingebettete
 * Hilfegrafiken.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 11/18 gleich (suche.py 30.10.2026, Basis hyperhlp_t1_P1.CPP)
// hyperhlp.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09C9E0-0x0A16B0
#include <string.h>
#include <stdlib.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_099ea0();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f40(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3950(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0d9cc0();                                         // reg - stapel 0
int f_0e4cb0();                                         // reg - stapel 0
                   // reg eax edx ebx stapel 0
           // reg eax edx ebx ecx stapel 0
// reg eax edx ebx ecx stapel 8
// reg eax edx ebx ecx stapel 8
int f_11e9d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_13dba0(int p1, int p2);                           // reg eax edx stapel 0
int f_13e140(int p1);                                   // reg eax stapel 0
int f_13e690(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_15689d(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_156cf4(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_15d4d0(int p1);                                   // reg eax stapel 0
int f_15d4dc();                                         // reg - stapel 0
int f_15d584(int p1);                                   // reg eax stapel 0
int f_15d744();                                         // reg - stapel 0
int f_15dadc(int p1, int p2);                           // reg eax edx stapel 0
int f_15db68(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a3570;                    // 0x1A3570
extern int d_1a3578;                    // 0x1A3578
extern int d_1a3c20;                    // 0x1A3C20
extern int d_1b7022;                    // 0x1B7022
extern int d_1b702a;                    // 0x1B702A
extern int d_1b702c;                    // 0x1B702C
extern int d_1b7034;                    // 0x1B7034
extern int d_1b7037;                    // 0x1B7037
extern int d_1b703a;                    // 0x1B703A
extern int d_1b703d;                    // 0x1B703D
extern int d_1b7040;                    // 0x1B7040
extern int d_1b7043;                    // 0x1B7043
extern int d_1b7046;                    // 0x1B7046
extern int d_1b7049;                    // 0x1B7049
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1bde14;                    // 0x1BDE14
extern int d_1bde18;                    // 0x1BDE18
extern int d_1bde1c;                    // 0x1BDE1C
extern int d_1bde20;                    // 0x1BDE20
extern int d_1bde24;                    // 0x1BDE24
extern short d_1bde28;                    // 0x1BDE28
extern int d_1bde2c;                    // 0x1BDE2C
extern int d_1bde30;                    // 0x1BDE30
extern int d_1bde44;                    // 0x1BDE44
extern int d_1bde48;                    // 0x1BDE48
extern int d_1bde4c;                    // 0x1BDE4C
extern volatile int d_1bde50;                    // 0x1BDE50 - haelt das Lesen in der Schleife wie im Original
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
extern int d_1bde90;                    // 0x1BDE90
extern int d_1bde94;                    // 0x1BDE94
extern int d_1bde98;                    // 0x1BDE98
extern int d_1bdea0;                    // 0x1BDEA0
extern int d_1bdea8;                    // 0x1BDEA8
extern int d_1bdfac;                    // 0x1BDFAC
extern int d_1bdfb0;                    // 0x1BDFB0
extern int d_1bdfb4;                    // 0x1BDFB4
extern int d_1bdfb8;                    // 0x1BDFB8
extern int d_1bdfbc;                    // 0x1BDFBC
extern int d_1bdfc0;                    // 0x1BDFC0
extern int d_1bdfc4;                    // 0x1BDFC4
extern int d_1bdfc8;                    // 0x1BDFC8
extern int d_1bdfcc;                    // 0x1BDFCC
extern int d_1bdfd0;                    // 0x1BDFD0
extern int d_1bdfd4;                    // 0x1BDFD4
extern int d_1bdfd8;                    // 0x1BDFD8
extern int d_1bdfe4;                    // 0x1BDFE4
extern int d_1bdfe8;                    // 0x1BDFE8
extern int d_1be0d8;                    // 0x1BE0D8
extern int d_1bf4f0;                    // 0x1BF4F0
extern int d_1bf4f2;                    // 0x1BF4F2
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
extern const char d_1b706a[];           // Text 0x1B706A
extern const char d_1b7075[];           // Text 0x1B7075
extern const char d_1b7081[];           // Text 0x1B7081
extern const char d_1b708b[];           // Text 0x1B708B

// --- Pass 1 hyperhlp_t1 (Helfer A): eigene Typen/Daten/Prototypen ---
struct VO { char *vt; };
typedef int (*FP1)(VO *);
typedef int (*FP3)(VO *, int, int);
typedef unsigned char (*FPC)(VO *, int);
typedef int (*FP6)(VO *, int, int, int, void *, int);
#define VC(o,off,T) (*(T *)((o)->vt + (off)))
struct HT { const char *n; unsigned v; };
struct E { int used; char name[80]; void *h54; void *o58; };
struct RGB { unsigned char r, g, b; };
struct R { int x0, y0, x1, y1; };
struct Z { char c[0x3fb]; };
extern HT d_1a35a4[];
extern unsigned char d_1bdd14[256];
extern unsigned char d_1bdeac[256];
extern unsigned char *d_1bde9c;
extern unsigned char *d_1bdfec;
extern VO *d_1bde3c;
extern VO *d_1bde40;
extern VO *d_1be0bc;
extern char *d_1a357c;
extern signed char *d_1a3580;
extern E *d_1bde8c;
extern signed char d_1bfaf0;
extern int *d_1c008c;
extern char *d_1bdea4;
extern void *d_1c0088;
extern char d_1bdfdc;
extern short d_1bdfe0;
extern short d_1bdfe2;
extern short d_1bdfde;
extern const char d_1b6fbe[];
extern const char d_1b6fbf[];
extern const char d_1b6fc0[];
extern const char d_1b6fc1[];
extern const char d_1b6fd2[];
extern const char *d_1a3c24;
extern const char *d_1a3c28;
extern char d_1be038[];
extern char d_1be0c0[];
extern char d_1be0dc[];
extern char d_1be160[];
extern short d_1bdff0, d_1bdff2, d_1bdff4, d_1bdff6, d_1bdff8, d_1bdffa, d_1bdffc, d_1bdffe;
extern short d_1be000, d_1be002, d_1be004, d_1be006, d_1be008, d_1be00a, d_1be00c, d_1be00e;
extern short d_1be010, d_1be012, d_1be014, d_1be016, d_1be018, d_1be01a, d_1be01c, d_1be01e;
extern short d_1be020, d_1be022, d_1be024, d_1be026, d_1be028, d_1be02a, d_1be02c, d_1be02e;
extern short d_1be030, d_1be032, d_1be034, d_1be036;
int f_013670(void *, const char *, const char *);

int f_14d17f(void *);
int f_144fbf(const char *, ...);
int f_145547(const char *, const char *, int);
int f_145259(int);
int f_14d717(const char *, const char *);
int f_051870(const char *, int);
int f_0bf730(void *, int);
short f_0bf820(int, ...);
int f_0d2f90(int, int);
int f_0d2e70(void);
int f_0e9240(const void *);
int f_0ce250(void);
int f_133fe0(void *, int);
int f_09f070(int, int);
int f_09ece0(const char *);
int f_15c5c8(void *);
void *f_15c640(void *, int);
int f_15c700(void *, int);
char *f_15c850(void *);
int f_15c860(void *);
int f_15c870(void *, short *, short *);
void *f_15c6d0(void *, int);




R *f_15d90c(void *, int);
int f_15ae98(int, int, R *);
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_09c9e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert beim Programmstart die Rechteck- und Zustandsvariablen des Hilfesystems
 *   (d_1bdff0 bis d_1be036) auf 0 und meldet die beiden Hilfearchive (d_1be038 über d_1be0c0 sowie das
 *   Zusatz-/Lösungsarchiv d_1be0dc über d_1be160) beim Dateimanager an.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Dateimanager d_1be0c0 und d_1be160 verwalten das reguläre Hilfearchiv und das
 *   optionale Hinweisbuch-Archiv.
 === Ende Beschreibung === */
void f_09c9e0(void)
{
#pragma aux f_14d17f modify [ebx edx];
    f_14d17f(&d_1a3570);
    d_1bdff0 = 0;
    d_1bdff2 = 0;
    d_1bdff4 = 0;
    d_1bdff6 = 0;
    d_1bdff8 = 0;
    d_1bdffa = 0;
    d_1bdffc = 0;
    d_1bdffe = 0;
    d_1be000 = 0;
    d_1be002 = 0;
    d_1be004 = 0;
    d_1be006 = 0;
    d_1be008 = 0;
    d_1be00a = 0;
    d_1be00c = 0;
    d_1be00e = 0;
    d_1be010 = 0;
    d_1be012 = 0;
    d_1be014 = 0;
    d_1be016 = 0;
    d_1be018 = 0;
    d_1be01a = 0;
    d_1be01c = 0;
    d_1be01e = 0;
    d_1be020 = 0;
    d_1be022 = 0;
    d_1be024 = 0;
    d_1be026 = 0;
    d_1be028 = 0;
    d_1be02a = 0;
    d_1be02c = 0;
    d_1be02e = 0;
    d_1be030 = 0;
    d_1be032 = 0;
    d_1be034 = 0;
    d_1be036 = 0;
    f_013670(d_1be038, d_1b6fa5, d_1b6f98);
    d_1a3578 = 1;
    ((int)(((RivaFileManager*)(d_1be0c0))->f_144610((RivaFileDevice *)( 0),(RivaFileDevice *)( d_1be038),(RivaFileDevice *)( 0),(RivaFileDevice *)( 0))));
    f_013670(d_1be0dc, d_1a3c24, d_1a3c28);
    d_1a3578 = 2;
    ((int)(((RivaFileManager*)(d_1be160))->f_144610((RivaFileDevice *)( 0),(RivaFileDevice *)( d_1be0dc),(RivaFileDevice *)( 0),(RivaFileDevice *)( 0))));
}
//@ f_09cb60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler im Hilfesystem, ob er das aktuelle Hilfethema (cnt == 1) oder sämtliche
 *   Hilfeseiten (cnt == 2) ausgeben möchte, und schreibt den formatierten Text je nach Einstellung d_1bfaf0
 *   entweder in eine Textdatei (d_1b6fb2) oder über f_0e9240 auf den angeschlossenen Drucker.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdfb0 = 1 schaltet den Hypertext-Renderer in den Textdruck-Modus (80 Zeichen
 *   Breite in den Zeilenpuffer d_1bdea4), und d_1a35a4 ist die Tabelle aller Hilfethemen bis zur Endmarke
 *   0x1003d.
 === Ende Beschreibung === */
void f_09cb60(void)
{
    struct { char path[20]; R r1,r2; int cnt; } st;
    int sv;
    int flag = 0;
    signed char ch;
    int sc = 0;
    int oldw;
    int oldh;
    HT *ppu;
    if ((ch=d_1bfaf0) >= 0 && d_1bdfac == 0) {
        sv = d_1bdfb8;
        f_09f070(0, 0);
        f_09a400();
        f_0d26e0();
        st.cnt = f_0bf820((int)&d_1c2c64, 0x200001d6, 2, 0x200001d8, 0x200001d7);
        if (st.cnt > 0) {
            f_0e4cb0();
            if ((ch=d_1bfaf0) == 0) {
                strcpy(st.path, d_1b6fb2);
                d_1c0098 = f_144fbf(st.path, 0x261, 0x180);
                if (d_1c0098 <= 0) {
                    flag = 1;
                    f_0bf730(&d_1c2c64, f_133fe0(&d_1c3498, d_1c008c[0x6e]));
                }
            } else {
                if (f_0ce250() == 0) {
                    flag = 1;
                    f_0bf730(&d_1c2c64, f_133fe0(&d_1c3498, d_1c008c[1]));
                } else {
                    sc = f_0bf820((int)&d_1c2c64, f_133fe0(&d_1c3498, d_1c008c[0]), 1, f_133fe0(&d_1c3498, d_1c008c[0x6d]));
                }
            }
            if (flag == 0 && sc != (short)-1) {
                oldw = d_1bde2c;
                oldh = d_1bde30;
                f_0d2f90(5, 1);
                d_1bdfb0 = 1;
                d_1bde44 = 0;
                d_1bde48 = 0;
                d_1bde2c = 0x50;
                d_1bde30 = 100000;
                d_1bdea4 = (char *)operator new[](200, mark(d_1a3584, 0x398));
                if (st.cnt == 2) {
                    for (ppu = d_1a35a4; ; ppu++) {
                        d_1bde44 = 0;
                        d_1bde48 = 0;
                        if (f_09ece0(ppu->n) != 0) {
                            int rectY=*(int *)&d_1bde28 + 100, rectX=d_1bde24;
                            st.r1.x0 = 0;
                            st.r1.y0 = 0;
                            st.r1.x1 = rectX;
                            st.r1.y1 = rectY;
                            f_15ae98(0, 0, &st.r1);
                        }
                        f_0e9240(d_1bdea4);
                        *d_1bdea4 = 0;
                        if (ppu->v == 0x1003d) break;
                        f_0e9240(d_1b6fbe);
                        f_0e9240(d_1b6fbf);
                        f_0e9240(d_1b6fc0);
                        f_0e9240(d_1b6fc1);
                    }
                } else {
                    int rectY=*(int *)&d_1bde28, rectX=d_1bde24;
                    st.r2.x0 = 0;
                    st.r2.y0 = 0;
                    st.r2.x1 = rectX;
                    st.r2.y1 = rectY + 100;
                    f_15ae98(0, 0, &st.r2);
                    f_0e9240(d_1bdea4);
                    *d_1bdea4 = 0;
                }
                operator delete(d_1bdea4);
                d_1bde30 = oldh;
                d_1bde2c = oldw;
                d_1bdfb0 = 0;
                f_0d2e70();
                if ((ch=d_1bfaf0) == 0) f_145259(d_1c0098);
            }
            operator delete(d_1c0088);
            operator delete(d_1c008c);
        }
        f_09f070(sv, 1);
    }
}
//@ f_09ce70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht zu einem 8-Bit-RGB-Farbtripel p1[0..2] (das durch Division durch 4 auf 6-Bit-VGA-Werte
 *   skaliert wird) unter den oberen 96 Einträgen (160 bis 255) der Hilfepalette d_1bde9c den Farbindex mit dem
 *   kleinsten quadratischen euklidischen Abstand.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned char *) auf drei RGB-Bytes und gibt den
 *   bestpassenden Palettenindex (160..255) zurück (int).
 * - Wichtige Variablen: Das globale Array d_1bde9c enthält die 256-Farben-Palette des Hilfesystems.
 === Ende Beschreibung === */
// BLIND-Neufassung: naechster Paletteneintrag 160..255 aus d_1bde9c (3 Byte/Eintrag),
// quadratischer Abstand der auf p[0..2]/4 reduzierten Farbwerte.
// Eigener Farbtyp mit Konstruktor (nur hier benutzt, laesst struct RGB unveraendert).
struct RGB2526 {
    unsigned char r, g, b;
    RGB2526() {}
    RGB2526(unsigned char rr, unsigned char gg, unsigned char bb) : r(rr), g(gg), b(bb) {}
};
int f_09ce70(unsigned char *p1)
{
    RGB2526 c(p1[0] / 4, p1[1] / 4, p1[2] / 4);
    int i;
    unsigned best = 0xffffffff;
    int besti = 0xa0;

    for (i = 0xa0; i < 0x100; i++) {
        unsigned r2 = (c.r - d_1bde9c[i * 3]) * (c.r - d_1bde9c[i * 3]);
        unsigned d = r2 + (c.g - d_1bde9c[i * 3 + 1]) * (c.g - d_1bde9c[i * 3 + 1])
                   + (c.b - d_1bde9c[i * 3 + 2]) * (c.b - d_1bde9c[i * 3 + 2]);
        if (d < best) {
            best = d;
            besti = i;
        }
    }
    return besti;
}

//@ f_09cf50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt im Offscreen-Puffer d_1bdfec des Hilfesystems an den Koordinaten (p1, p2) einen
 *   einzelnen Bildpunkt auf die Farbe p3.
 * - Eingaben und Rückgabe: Die Funktion erhält die X-Koordinate p1, die Y-Koordinate p2 sowie den Farbindex p3
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Grenzabfrage prüft versehentlich p1 <= d_1bde2c && p2 <= d_1bde30 statt <, sodass am
 *   rechten und unteren Rand außerhalb des Puffers d_1bdfec geschrieben werden kann (siehe Fehlerliste).
 === Ende Beschreibung === */
void f_09cf50(int p1, int p2, int p3)
{
    if (p1 >= 0 && p1 <= d_1bde2c && p2 >= 0 && p2 <= d_1bde30) {
        d_1bdfec[p2 * d_1bde2c + p1] = (unsigned char)p3;
    }
}
//@ f_09cf80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im Offscreen-Puffer d_1bdfec des Hilfesystems mit einem Festkomma-Linienalgorithmus
 *   eine Linie von (x0, y0) nach (x1, y1) in der Farbe color.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startkoordinaten x0, y0, die Endkoordinaten x1, y1 sowie den
 *   Farbindex color und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die eingebettete Punktsetzroutine f_09cf80_put verwendet dieselbe um 1 zu weite
 *   Grenzabfrage <= d_1bde2c und <= d_1bde30 wie f_09cf50.
 === Ende Beschreibung === */
// BLIND-Neufassung: Bresenham-Linie (x0,y0)-(x1,y1) in Farbe p5.
inline void f_09cf80_put(int px, int py, int col)
{
    if (px >= 0 && px <= d_1bde2c && py >= 0 && py <= d_1bde30) {
        d_1bdfec[d_1bde2c * py + px] = (unsigned char)col;
    }
}
void f_09cf80(int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int step;

    if ((dx | dy) == 0) {
        f_09cf80_put(x0, y0, color);
        return;
    }
    if (abs(dx) > abs(dy)) {
        step = (dy << 16) / abs(dx);
        y0 = (y0 << 16) | 0x8000;
        if (x0 < x1) {
            for (;;) {
                if (x0 > x1) return;
                f_09cf80_put(x0, y0 >> 16, color);
                x0++;
                y0 += step;
            }
        } else {
            for (;;) {
                if (x0 < x1) return;
                f_09cf80_put(x0, y0 >> 16, color);
                x0--;
                y0 += step;
            }
        }
    } else {
        step = (dx << 16) / abs(dy);
        x0 = (x0 << 16) | 0x8000;
        if (y0 < y1) {
            for (;;) {
                if (y0 > y1) return;
                f_09cf80_put(x0 >> 16, y0, color);
                y0++;
                x0 += step;
            }
        } else {
            for (;;) {
                if (y0 < y1) return;
                f_09cf80_put(x0 >> 16, y0, color);
                y0--;
                x0 += step;
            }
        }
    }
}

//@ f_09d1a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Gesamtbreite einer Zeichenkette p1 der Länge p2 in Pixeln anhand der aktuellen
 *   Hilfeschriftart (d_1bde40 im SVGA-Modus, sonst d_1bde3c) und füllt bei gesetztem Invalidierungsflag d_1a3c20
 *   zuvor die 256-Byte-Zeichenbreitentabelle d_1bdd14 neu auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeichenkettenzeiger p1 (unsigned char *) sowie die
 *   Zeichenanzahl p2 (int) und gibt die summierte Pixelbreite zurück (int).
 * - Wichtige Variablen: Das Array d_1bdeac übersetzt Eingabezeichen in den internen Zeichensatz, und d_1bdd14
 *   cached die Pixelbreite jedes Zeichens.
 === Ende Beschreibung === */
inline int f_09d1a0_inline(unsigned char *p1, int p2)
{
    int sum = 0;
    int i;
    if (d_1a3c20 != 0) {
        d_1a3c20 = 0;
        for (i = 0; i < 0x100; ++i) {
            VO *o;
            if (d_1bdfb8 != 0) o = d_1bde40;
            else o = d_1bde3c;
            d_1bdd14[i] = VC(o, 8, FPC)(o, d_1bdeac[i]);
        }
    }
    i = 0;
    if (0 < p2) {
        do {
            sum += d_1bdd14[p1[i]];
            ++i;
        } while (i < p2);
    }
    return sum;
}
int f_09d1a0(unsigned char *p1, int p2)
{
    return f_09d1a0_inline(p1, p2);
}
//@ f_09d230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung:Gibt p2 Zeichen aus der Zeichenkette p1 ab der Position (p3, p4) mit der aktiven
 *   Hilfeschriftart (d_1bde3c bzw. d_1bde40) in den Hilfepuffer aus und zieht bei aktivierter Unterstreichung
 *   (d_1bdfdc und Farbe 0x36 = Hyperlink) über f_09cf80 eine Unterstreichungslinie unter den Text.
 * - Eingaben und Rückgabe: Die Funktion erhält den Textzeiger p1 (unsigned char *), die Zeichenanzahl p2 sowie
 *   die Startkoordinaten p3 und p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variablen d_1bde64 und d_1bde68 merken sich die Endposition des letzten
 *   Zeichenblocks, damit durch Leerzeichen getrennte Wörter desselben Hyperlinks durchgehend unterstrichen
 *   werden.
 === Ende Beschreibung === */
typedef int (*FPCD)(VO *, unsigned char, short, short, void *, int);
inline int f_09d230_w(unsigned char *p1, int p2)
{
    int sum = 0;
    int i = 0;   // Vorbelegung: Cache-Schleife wird eigener Web, Summenzaehler behaelt den Namen
    if (d_1a3c20 != 0) {
        d_1a3c20 = 0;
        for (i = 0; i < 0x100; ++i) {
            VO *o;
            if (d_1bdfb8 != 0) o = d_1bde40;
            else o = d_1bde3c;
            d_1bdd14[i] = VC(o, 8, FPC)(o, d_1bdeac[i]);
        }
    }
    for (i = 0; i < p2; ++i)
        sum += d_1bdd14[p1[i]];
    return sum;
}
void f_09d230(unsigned char *p1, int p2, int p3, int p4)
{
    int c;
    int w;
    int i = 0;

    for (; i < p2; i++) {
        c = d_1bdeac[p1[i]];
        w = f_09d230_w(p1 + i, 1);
        if (p3 >= 0 && p3 + w < d_1bde2c && p4 >= 0 && p4 + d_1bde50 < d_1bde30) {
        if (p4 == d_1bde68 && d_1bde64 >= 0 && d_1bde64 <= p3) {
            VO *o;
            if (d_1bdfb8 != 0) o = d_1bde40;
            else o = d_1bde3c;
            if (d_1bde64 + 2 * VC(o, 8, FPC)(o, 0x20) > p3)
                goto keepcursor;
        }
        d_1bde64 = p3;
    keepcursor:
        if (d_1bdfe0 == 0xfe) d_1bdfe0 = 0x36;
        if (d_1bdfe0 == 0xba) d_1bdfe0 = 0x40;
        if (d_1bdfe0 == 0xb6) d_1bdfe0 = 0xfc;
        {
            VO *o;
            if (d_1bdfb8 != 0) o = d_1bde40;
            else o = d_1bde3c;
            VC(o, 4, FPCD)(o, (unsigned char)c, (short)p3, (short)(p4 + 0x7d0), &d_1bdfde, d_1bdfe2);
        }
        p3 += w;
        if (d_1bdfdc && d_1bdfe0 == 0x36) {
            f_09cf80(d_1bde64, p4 + d_1bde50 - (d_1bdfb8 != 0 ? 2 : 0), p3 - 1,
                     p4 + d_1bde50 - (d_1bdfb8 != 0 ? 2 : 0), d_1bdfe0);
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


//@ f_09d4c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die 256-Byte-Zeichenübersetzungstabelle d_1bdeac für das Hilfesystem auf und ersetzt bei
 *   aktivierter Codepage-Umsetzung (d_1bde20 == 1) deutsche Sonderzeichen aus d_1a357c durch die Zielcodes aus
 *   d_1a3580.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1bdeac (256 Bytes) wird bei jeder Textmessung und Textausgabe des
 *   Hilfesystems konsultiert.
 === Ende Beschreibung === */
void f_09d4c0(void)
{
    int i;
    int v;
    char *q;
    for (i = 0; i < 0x100; i++) {
        v = i;
        if (d_1bde20 == 1) {
            q = strchr(d_1a357c, (char)i);
            if (q != 0) v = d_1a3580[q - d_1a357c];
        }
        d_1bdeac[i] = (unsigned char)v;
    }
}
//@ f_09d540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt zu einem symbolischen Dateinamen p1 eines Hilfethemas oder Hilfebildes die
 *   zugehörige 32-Bit-Archivkennung, indem entweder ein Hex-Suffix nach d_1b6fd2 ausgewertet oder die
 *   Zuordnungstabelle d_1a35a4 durchsucht wird (wobei für hochauflösende SVGA-Grafiken bei d_1bdfb8 != 0 die
 *   jeweils um 1 höhere Ressourcen-ID gewählt wird).
 * - Eingaben und Rückgabe: Die Funktion erhält den Dateinamen p1 (const char *) und gibt die
 *   32-Bit-Ressourcenkennung oder 0 bei Nichtfinden zurück (int).
 * - Wichtige Variablen: Die Tabelle d_1a35a4 ordnet Klartextnamen ihre Archiv-IDs zu; d_1bdfb8 kennzeichnet den
 *   hochauflösenden 640x480-Hilfemodus.
 === Ende Beschreibung === */
int f_09d540(const char *p1)
{
    int i;
    char buf[3];
    if (f_145547(p1, d_1b6fd2, 4) == 0) {
        buf[0] = p1[4];
        buf[1] = p1[5];
        buf[2] = 0;
        return f_15c5c8(buf) + 0x10000;
    }
    for (i = 0; d_1a35a4[i].n != 0; i++) {
        if (f_14d717(d_1a35a4[i].n, p1) == 0) {
            if (d_1a35a4[i].v >= 0x20009 && d_1a35a4[i].v <= 0x20021 && d_1bdfb8 != 0)
                return d_1a35a4[i].v + 1;
            if (d_1a35a4[i].v >= 0x20008 && d_1a35a4[i].v <= 0x2003a && d_1bdfb8 != 0 && d_1bdfac == 1)
                return d_1a35a4[i].v + 1;
            return d_1a35a4[i].v;
        }
    }
    return 0;
}
//@ f_09d640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht ein Hilfebild mit dem Namen p1 im 8-teiligen Hilfebild-Cache d_1bde8c oder lädt es über
 *   f_09d540 und f_15c700 neu in den nächsten freien (bzw. im Rundlauf ab Index 1 überschriebenen) Cache-Slot,
 *   wobei beim allerersten Slot (d_1bde6c == 0) auch die 256-Farben-Hilfepalette nach d_1bde9c kopiert wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildnamen p1 (const char *) und gibt den Zeiger auf das
 *   RivaRasterImage-Objekt (h54) des geladenen Bildes zurück (int).
 * - Wichtige Variablen: Slot 0 von d_1bde8c bleibt nach dem ersten Laden dauerhaft reserviert (if (d_1bde6c >=
 *   8) d_1bde6c = 1;), während die Slots 1..7 im Ringpufferverfahren wiederverwendet werden.
 === Ende Beschreibung === */
struct HZ { char c[0x3fb]; HZ(int); ~HZ(); };
struct HS { char c[9]; HS(int, int, int); ~HS(); };
int f_09d640(const char *p1)
{
    int i;
    short h, w;
    int v;
    RGB *src;
    for (i = 0; i < 8; i++) {
        if (d_1bde8c[i].used != 0 && f_14d717(d_1bde8c[i].name, p1) == 0)
            return (int)d_1bde8c[i].h54;
    }
    v = (v & 0) ? 0 : v; // haelt die Registerzuteilung fuer v wie im Original
    v = f_09d540(p1);
    if (v == 0)
        f_051870(d_1b6fd7, 0);
    if (d_1bde6c >= 8)
        d_1bde6c = 1;
    if (d_1bde8c[d_1bde6c].used != 0) {
        delete (HZ *)d_1bde8c[d_1bde6c].h54;
        delete (HS *)d_1bde8c[d_1bde6c].o58;
    }
    d_1bde8c[d_1bde6c].used = 1;
    strcpy(d_1bde8c[d_1bde6c].name, p1);
    d_1bde8c[d_1bde6c].o58 = new (mark(d_1a3584, 0x541)) HZ(d_1be0d8);
    f_15c700(d_1bde8c[d_1bde6c].o58, v);
    f_15c870(d_1bde8c[d_1bde6c].o58, &h, &w);
    d_1bde8c[d_1bde6c].h54 = new (mark(d_1a3584, 0x544)) HS(h, w, f_15c860(d_1bde8c[d_1bde6c].o58));
    if (d_1bde6c == 0) {
        src = (RGB *)f_15c850(d_1bde8c[d_1bde6c].o58);
        for (i = 0; i < 0x100; i++)
            ((RGB *)d_1bde9c)[i] = src[i];
    }
    d_1bde6c++;
    return (int)d_1bde8c[d_1bde6c - 1].h54;
}

//@ f_09d850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den rechteckigen Bereich eines Hyperlinks mit dem Index p1 im Hilfepuffer neu
 *   (f_15ae98), sofern der Link im aktuell sichtbaren Scrollausschnitt (d_1bde74 bis d_1bde74 + d_1bde30) liegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Hyperlink-Index p1 (int, -1 für keinen Link) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Variable d_1bde74 gibt den aktuellen vertikalen Scrollversatz der Hilfeseite an.
 === Ende Beschreibung === */
void f_09d850(int p1)
{
    char tmp[16];
    R r;
    if (p1 != -1) {
        r = *f_15d90c(tmp, p1);
        r.y0 = r.y0 - d_1bde74;
        r.y1 = r.y1 - d_1bde74;
        if (r.y1 >= 0 && r.y0 < d_1bde30) {
            if (r.x0 < 0) r.x0 = 0;
            if (r.y0 < 0) r.y0 = 0;
            if (d_1bde2c - 1 < r.x1) r.x1 = d_1bde2c - 1;
            if (d_1bde30 - 1 < r.y1) r.y1 = d_1bde30 - 1;
            f_15ae98(0, d_1bde74, &r);
        }
    }
}
//@ f_09d900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert ein RivaRasterImage-Bild p1 an die Position (p2, p3) in den Offscreen-Hilfepuffer
 *   d_1bdfec, beschneidet es an den Grenzen des aktuellen Clipping-Rechtecks (d_1bdfc8..d_1bdfd4) und kopiert
 *   die Pixel je nach Flag p4 entweder deckend (memcpy) oder transparent (Farbe 0 ausgelassen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildzeiger p1, die Zielkoordinaten p2 und p3 sowie das
 *   Transparenzflag p4 und gibt 1 bei Erfolg oder 0 bei p1 == 0 zurück (int).
 * - Wichtige Variablen: Die globalen Variablen d_1bdfc8 (l), d_1bdfcc (t), d_1bdfd0 (r) und d_1bdfd4 (b)
 *   definieren das Clipping-Rechteck des Hilfepuffers.
 === Ende Beschreibung === */
int f_09d900(int p1, int p2, int p3, int p4)
{
    short width, height;
    char *source;
    unsigned char *screen;
    short copy_width;
    if (p1 == 0) return 0;
    ((RivaRasterImage*)(p1))->f_0fb210((short *)( &width),(short *)( &height));
    if (p2 <= d_1bdfd0 && p3 <= d_1bdfd4 &&
        width + p2 >= d_1bdfc8 && height + p3 >= d_1bdfcc) {
        source = ((RivaRasterImage*)(p1))->f_0fb0b0();
        screen = d_1bdfec + d_1bde2c * p3 + p2;
        copy_width = width;
        height = height - 1;
        if (p3 < d_1bdfcc) {
            height -= d_1bdfcc - p3;
            source += width * (d_1bdfcc - p3);
            screen += (d_1bdfcc - p3) * d_1bde2c;
            p3 = d_1bdfcc;
        }
        if (p2 < d_1bdfc8) {
            copy_width -= d_1bdfc8 - p2;
            source += d_1bdfc8 - p2;
            screen += d_1bdfc8 - p2;
            p2 = d_1bdfc8;
        }
        if (copy_width + p2 > d_1bdfd0)
            copy_width -= p2 + copy_width - d_1bdfd0;
        if (height + p3 > d_1bdfd4)
            height -= p3 + height - d_1bdfd4;
        if (!p4) {
            for (; height >= 0; height--) {
                memcpy(screen, source, copy_width);
                source += width;
                screen += d_1bde2c;
            }
        } else {
            for (; height >= 0; height--) {
                for (p2 = 0; p2 < copy_width; p2++) {
                    signed char c;
                    if ((c = *source++) != 0) *screen = c;
                    screen++;
                }
                screen += d_1bde2c - copy_width;
                source += width - copy_width;
            }
        }
    }
    return 1;
}

//@ f_09dae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet im aktuell gewählten Hilfearchiv d_1be0bc die zum Namen p1 gehörende Hilferessource
 *   über die virtuelle Methode an Offset 0x14.
 * - Eingaben und Rückgabe: Die Funktion erhält den Ressourcennamen p1 (const char *) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Der Zeiger d_1be0bc verweist auf das aktive RivaFileDevice des Hilfesystems.
 === Ende Beschreibung === */
void f_09dae0(const char *p1)
{
    VO *o = d_1be0bc;
    char *vt = o->vt;
    int v = f_09d540(p1);
    (*(FP3 *)(vt + 0x14))(o, v, 0x200);
}
//@ f_09db10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus der im Hilfearchiv d_1be0bc geöffneten Ressource p2 Bytes in den Puffer p1 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält die Zielpufferadresse p1 sowie die Byteanzahl p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Der Aufruf erfolgt über den virtuellen Methodenslot 0x20 von d_1be0bc.
 === Ende Beschreibung === */
void f_09db10(int p1, int p2)
{
    VC(d_1be0bc, 0x20, FP3)(d_1be0bc, p1, p2);
}
//@ f_09db30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über den virtuellen Methodenslot 0x3c die aktuelle Dateiposition im Hilfearchiv d_1be0bc
 *   ab.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt in EAX die aktuelle Dateiposition
 *   zurück.
 * - Wichtige Variablen: Das Archivobjekt d_1be0bc führt die Positionsabfrage aus.
 === Ende Beschreibung === */
void f_09db30(void)
{
    {
        VO *o = d_1be0bc;
        char *vt = o->vt;
        (*(FP1 *)(vt + 0x3c))(o);
    }
}
//@ f_09db40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Lesezeiger der im Hilfearchiv d_1be0bc geöffneten Ressource über den virtuellen
 *   Methodenslot 0x40 auf den Datei-Offset p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Ziel-Offset p1 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Positionierung erfolgt relativ zum Dateianfang (0).
 === Ende Beschreibung === */
void f_09db40(int p1)
{
    VC(d_1be0bc, 0x40, FP3)(d_1be0bc, p1, 0);
}
//@ f_09db60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über den virtuellen Methodenslot 0x30 die Gesamtgröße der im Hilfearchiv d_1be0bc
 *   geöffneten Ressource ab.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt in EAX die Dateigröße zurück.
 * - Wichtige Variablen: Das aktive Archivobjekt ist d_1be0bc.
 === Ende Beschreibung === */
void f_09db60(void)
{
    VC(d_1be0bc, 0x30, FP1)(d_1be0bc);
}
//@ f_09db70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt die aktuell im Hilfearchiv d_1be0bc geöffnete Ressource über den virtuellen
 *   Methodenslot 0x28.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Aufruf schließt den aktiven Stream in d_1be0bc.
 === Ende Beschreibung === */
void f_09db70(void)
{
    VC(d_1be0bc, 0x28, FP1)(d_1be0bc);
}
