/* === Beschreibung (Katalog) ===
 * Einheit hyperhlp_t3 (09f070-0a1618)
 *
 * Überblick
 * Diese Einheit bildet den dritten und abschließenden Teil des Hypertext-Hilfesystems (HYPERHLP.CPP). Sie
 * enthält den Grafikmodus- und Auflösungsumschalter (320x200 VGA gegenüber 640x480 VESA-SVGA), das Zeichnen des
 * gekachelten Pergamenthintergrunds, die Bildaktualisierungs- und Scrollroutine f_09f7d0 samt
 * Werkzeugleisten-Schaltflächen sowie die zentrale Hauptschleife f_0a01a0 der Online-Hilfe.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 0/4 gleich (suche.py 26.10.2026, Basis hyperhlp_t3_P1.CPP)
// hyperhlp.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09C9E0-0x0A16B0
#include <string.h>
#include <bios.h>
#pragma intrinsic(memcpy)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_051870(int p1, int p2);                           // reg eax edx stapel 0
int f_099ea0();                                         // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce250();                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f40(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3950(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0d9cc0();                                         // reg - stapel 0
int f_0e4cb0();                                         // reg - stapel 0
int f_0e9240(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
// reg eax edx ebx ecx stapel 8
                                   // reg eax stapel 0
// reg eax edx ebx ecx stapel 8
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13e140(int p1);                                   // reg eax stapel 0
int f_13e690(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
   // reg eax edx ebx ecx stapel 4
int f_15689d(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_156cf4(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_15c5c8(int p1);                                   // reg eax stapel 0
int f_15c640();                       // nicht in clobber.tsv
int f_15c6d0(int p1, int p2);                           // reg eax stapel 0
int f_15c700(int p1, int p2);                           // reg eax edx stapel 0
int f_15c850(int p1);                                   // reg eax stapel 0
int f_15c860(int p1);                                   // reg eax stapel 0
int f_15c870(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_15d4d0(int p1);                                   // reg eax stapel 0
int f_15d4dc();                                         // reg - stapel 0
int f_15dadc(int p1, int p2);                           // reg eax edx stapel 0
int f_15db68(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
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
// --- eigene Funktionen (39), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#pragma inline_depth(0)
inline int EQ(int a, int b) { return a == b; }
struct R { int x1, y1, x2, y2; };
struct P { int x, y; };
struct T8 { int a; int b; };
struct T14 { short a; short b; short c; int d; int e; };
struct VB { virtual ~VB(); virtual int v1(); virtual int v2(); virtual char v3(); };
struct Spr9 { char b[9]; };
extern int d_1bde14;
extern int d_1bde18;
extern int d_1bde1c;
extern int d_1bde20;
extern int d_1bde24;
extern int d_1bde28;
extern int d_1bde2c;
extern int d_1bde30;
extern int d_1bde44;
extern int d_1bde48;
extern int d_1bde4c;
extern int d_1bde50;
extern int d_1bde54;
extern int d_1bde58;
extern int d_1bde5c;
extern int d_1bde60;
extern int d_1bde64;
extern int d_1bde68;
extern int d_1bde6c;
extern int d_1bde70;
extern int d_1bde74;
extern int d_1bde78;
extern int d_1bde7c;
extern int d_1bde80;
extern int d_1bde84;
extern int d_1bde88;
extern int d_1bde8c;
extern int d_1bde90;
extern int d_1bde94;
extern int d_1bde98;
extern int d_1bde9c;
extern int d_1bdea0;
extern int d_1bdea4;
extern int d_1bdea8;
extern int d_1bdfac;
extern int d_1bdfb0;
extern int d_1bdfb4;
extern int d_1bdfb8;
extern int d_1bdfbc;
extern int d_1bdfc4;
extern int d_1bdfe4;
extern int d_1bdfe8;
extern int d_1bdfec;
extern int d_1a34e0;
extern int d_1a3c1c;
extern int d_1a3c20;
extern int d_1c0088;
extern int d_1c008c;
extern int d_1c0098;
extern int d_1c0c4c;
extern int d_1c0c94;
extern int d_1be178;
extern int d_1bc944;
extern int d_1bde9c;
extern char *d_1a357c; extern char *d_1a3580; extern char d_1bdeac[];
extern unsigned short d_1c20b0, d_1c2104, d_1c2106;
extern short d_1bf4f0, d_1bf4f2; extern signed char d_1bfaf0, d_1bfb14;
extern struct T14 *d_1bde34, *d_1bde38; extern struct VB *d_1bde3c, *d_1bde40;
extern char d_1c2c64[], d_1c3498[], d_1c2e68[], d_1baac0[], d_1bacd0[], d_1bacc4[];
extern struct T8 d_1a35a4[]; extern struct R d_1bdfc8;
extern const char d_1b6fbe[], d_1b6fbf[], d_1b6fc0[], d_1b6fc1[], d_1b7096[], d_1b709d[], d_1b70a7[];
extern short d_1bdff0;
extern short d_1bdff2;
extern short d_1bdff4;
extern short d_1bdff6;
extern short d_1bdff8;
extern short d_1bdffa;
extern short d_1bdffc;
extern short d_1bdffe;
extern short d_1be000;
extern short d_1be002;
extern short d_1be004;
extern short d_1be006;
extern short d_1be008;
extern short d_1be00a;
extern short d_1be00c;
extern short d_1be00e;
extern short d_1be010;
extern short d_1be012;
extern short d_1be014;
extern short d_1be016;
extern short d_1be018;
extern short d_1be01a;
extern short d_1be01c;
extern short d_1be01e;
extern short d_1be020;
extern short d_1be022;
extern short d_1be024;
extern short d_1be026;
extern short d_1be028;
extern short d_1be02a;
extern short d_1be02c;
extern short d_1be02e;
extern short d_1be030;
extern short d_1be032;
extern short d_1be034;
extern short d_1be036;
int f_099ef0(int, ...);
int f_0bf820(int, ...);

int f_11e9d0(int);
#pragma aux f_11e9d0 parm routine [];
int f_15ae98(int, int, struct R *);
int f_15d744(struct R *);
int f_15d584(struct R *);
struct R f_15d90c(int);
int f_15d754(struct P *);
int f_15da8c(int, char **);
int f_09ea10(struct R *);
unsigned int f_09d540(int);
int f_09d640(const char *);
int f_09d850(int);
void f_09f070(int, int);
void f_09f6a0(int, int);
void f_09f7d0(void);
int f_09ece0(char *);
int f_09eb60(void);
int f_09ade0(int, int, int);
int f_09aed0(int);
int f_09ac80(int, int, int);
int f_0d33d0(short *);
int f_0d3780(void);
int f_0d37b0(void);
int f_0d32f0(void);
int f_0d4880(void *);
int f_0d48a0(void *);
int f_0f0130(void *);
int f_053c50(void);
int f_144570(void);
int f_148534(int);
int f_149d20(void);
int f_149eb4(int, ...);
int f_144fbf(const char *, ...);
int f_147c84(void *, int, void *);
int f_05ded0(void *, int);
void *f_045a90(void *, void *, void *);
int f_045b70(void *, int);
int f_069460(void);
int f_156c70(void);
int f_156c94(void);
int f_145259(int);
int f_0d2f90(int, int);
int f_0d2e70(void);
char f_13dba0(int, int);
struct B420 { char z[0x420]; };
#define MKR(r,a,b,c,d) ((r).x1=(a),(r).y1=(b),(r).x2=(c),(r).y2=(d))
#pragma intrinsic(strcpy, strchr)
#define D2C (d_1bde2c)
//@ f_09f070
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das Hilfesystem zwischen der Standardauflösung 320x200 (p1 == 0, Modus 0x13) und der
 *   hochauflösenden VESA-Auflösung 640x480 (p1 != 0, Modus 0x101) um, passt die Mausgrenzen und Mausposition an,
 *   verwirft auflösungsabhängige Bilder aus dem Hilfebild-Cache d_1bde8c, lädt die passende Werkzeugleiste
 *   (d_1b704e oder d_1b7059) an den unteren Bildschirmrand und trägt die Klickrechtecke aller neun
 *   Hilfeschaltflächen (d_1bdff0 bis d_1be036) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Hochauflösungsflag p1 (0 = 320x200, != 0 = 640x480) sowie das
 *   Zeichenflag p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variablen d_1bde54 und d_1bde58 speichern die Bildschirmauflösung, d_1bde5c die Höhe
 *   des Textfensters oberhalb der Werkzeugleiste und d_1bdfe4 bzw. d_1bdfe8 die RivaRasterImage-Objekte für den
 *   Offscreen-Puffer d_1bdfec.
 === Ende Beschreibung === */
struct DelC { ~DelC(); };
struct DelD { ~DelD(); };
struct S5C {
    int a;
    char b[0x50];
    DelC *c;
    DelD *d;
};
struct SprC {
    char b[9];
    SprC(short, short, int);
};

void f_09f070(int p1, int p2)
{
    short w, h;
    short i;
    short y1, y2;
    unsigned int id;

    d_1bdfb4 = 1;
    f_09a140(0, 0x19);
    f_0d2710();
    d_1a3c20 = 1;
    d_1bdfbc = 1;
    if (p1 && ((char (*)(short))f_13dba0)(0x101)) {
        d_1bde54 = 0x280;
        d_1bde58 = 0x1e0;
        f_099ef0(d_1bde98, 0, 0x100);
        ((char (*)(short))f_13e140)(0x101);
        f_099ef0(d_1bde98, 0, 0x100);
        f_11e9d0(0);
    } else {
        p1 = 0;
        d_1bde54 = 0x140;
        d_1bde58 = 0xc8;
        f_099ef0(d_1bde98, 0, 0x100);
        ((char (*)(short))f_13e140)(0x13);
        f_099ef0(d_1bde98, 0, 0x100);
        f_09a0d0(d_1a34e0);
    }
    f_0d3950(0, 0, (short)(d_1bde54 - 1), (short)(d_1bde58 - 1));
    f_15689d(0, 0, (short)(d_1bde54 - 1), (short)(d_1bde58 - 1));
    if (p1 != d_1bdfb8) {
        f_0d9cc0();
        if (p1)
            f_0d2f40((short)(d_1bf4f0 * 2), (short)(d_1bf4f2 * 480 / 200));
        else
            f_0d2f40((short)(d_1bf4f0 >> 1), (short)(d_1bf4f2 * 200 / 480));
        for (i = 0; i < 8; i++) {
            if ((*(S5C **)&d_1bde8c)[i].a != 0) {
                id = f_09d540((int)(*(S5C **)&d_1bde8c)[i].b);
                if ((id >= 0x20009 && id <= 0x20022) || (id >= 0x20008 && id <= 0x2003b)) {
                    (*(S5C **)&d_1bde8c)[i].a = 0;
                    delete (*(S5C **)&d_1bde8c)[i].c;
                    delete (*(S5C **)&d_1bde8c)[i].d;
                }
            }
        }
    }
    d_1bdfb8 = p1;
    d_1bde50 = (p1 ? d_1bde40 : d_1bde3c)->v3() + (d_1bdfb8 ? 2 : 0);
    d_1bde60 = d_1bde50 * 2;
    if (d_1bdfb8)
        id = f_09d640(d_1b704e);
    else
        id = f_09d640(d_1b7059);
    ((RivaRasterImage*)(id))->f_0fb210((short *)( &w),(short *)( &h));
    d_1bde5c = d_1bde58 - h;
    if (p2)
        ((RivaRasterImage*)(id))->f_0fade0((void *)( d_1a34e0), 0, (short)(d_1bde58 - h));
    if (d_1bdfb8) {
        y1 = d_1bde5c;
        d_1be028 = 0x118;
        d_1be02a = y1;
        d_1be02c = 0x17c;
        d_1be02e = d_1bde58 - 1;
        d_1bdff0 = 0x226;
        d_1bdff2 = y1;
        d_1bdff4 = 0x248;
        d_1bdff6 = d_1bde58 - 1;
        d_1bdff8 = 0x24a;
        d_1bdffa = y1;
        d_1bdffc = 0x26c;
        d_1bdffe = d_1bde58 - 1;
        d_1be000 = 0x1ba;
        d_1be002 = y1;
        d_1be004 = 0x1dc;
        d_1be006 = d_1bde58 - 1;
        d_1be008 = 0x1de;
        d_1be00a = y1;
        d_1be00c = 0x200;
        d_1be00e = d_1bde58 - 1;
        d_1be020 = 0x8;
        d_1be022 = y1;
        d_1be024 = 0x30;
        d_1be026 = d_1bde58 - 1;
        d_1be018 = 0x3c;
        d_1be01a = y1;
        d_1be01c = 0x5a;
        d_1be01e = d_1bde58 - 1;
        d_1be010 = 0x68;
        d_1be012 = y1;
        d_1be014 = 0x86;
        d_1be016 = d_1bde58 - 1;
        d_1be030 = 0x94;
        d_1be032 = y1;
        d_1be034 = 0xc4;
        d_1be036 = d_1bde58 - 1;
    } else {
        y2 = d_1bde5c;
        d_1be028 = 0x8c;
        d_1be02a = y2;
        d_1be02c = 0xbe;
        d_1be02e = d_1bde58 - 1;
        d_1bdff0 = 0x113;
        d_1bdff2 = y2;
        d_1bdff4 = 0x124;
        d_1bdff6 = d_1bde58 - 1;
        d_1bdff8 = 0x125;
        d_1bdffa = y2;
        d_1bdffc = 0x136;
        d_1bdffe = d_1bde58 - 1;
        d_1be000 = 0xdd;
        d_1be002 = y2;
        d_1be004 = 0xee;
        d_1be006 = d_1bde58 - 1;
        d_1be008 = 0xef;
        d_1be00a = y2;
        d_1be00c = 0x100;
        d_1be00e = d_1bde58 - 1;
        d_1be020 = 0x4;
        d_1be022 = y2;
        d_1be024 = 0x18;
        d_1be026 = d_1bde58 - 1;
        d_1be018 = 0x1e;
        d_1be01a = y2;
        d_1be01c = 0x2d;
        d_1be01e = d_1bde58 - 1;
        d_1be010 = 0x34;
        d_1be012 = y2;
        d_1be014 = 0x43;
        d_1be016 = d_1bde58 - 1;
        d_1be030 = 0x4a;
        d_1be032 = y2;
        d_1be034 = 0x62;
        d_1be036 = d_1bde58 - 1;
    }
    d_1bde2c = d_1bde54;
    d_1bde30 = d_1bde5c + d_1bde60 * 2;
    if (!(d_1bdfb8 ? d_1bdfe4 : d_1bdfe8)) {
        (d_1bdfb8 ? d_1bdfe4 : d_1bdfe8) = (id = (int)new (mark(d_1a3584, 0x922)) Spr9) ? ((int)(((RivaRasterImage*)(id))->f_0fac10( (short)d_1bde2c, (short)d_1bde30,(void *)( d_1bdfec)))) : id;
    }
}


//@ f_09f6a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Füllt im Offscreen-Hilfepuffer d_1bdfec ab der Zeile p1 insgesamt p2 Bildzeilen mit der
 *   nahtlos gekachelten Hintergrundtextur d_1b7063 auf, wobei der vertikale Texturversatz an die aktuelle
 *   Scrollposition d_1bde74 gekoppelt ist, damit der Hintergrund beim Rollen der Seite mitwandert.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startzeile p1 sowie die Zeilenanzahl p2 (int) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Hintergrundbild wird über f_09d640(d_1b7063) aus dem Hilfebild-Cache bezogen.
 === Ende Beschreibung === */
void f_09f6a0(int p1, int p2)
{
    short w, h;
    int hd = f_09d640(d_1b7063);
    int row, cnt, i, off, n;
    char *dst, *src;

    ((RivaRasterImage*)(hd))->f_0fb210((short *)( &w),(short *)( &h));
    row = (h * 16 + (d_1bde74 + p1)) % h;
    int row_offset = w * row;
    src = ((RivaRasterImage*)hd)->f_0fb0b0() + row_offset;
    dst = (char *)d_1bdfec + p1 * d_1bde2c;
    cnt = row;
    for (i = 0; i < p2; i++) {
        for (off = 0; off < d_1bde2c; off += w) {
            n = w;
            if (n >= d_1bde2c - off) n = d_1bde2c - off;
            memcpy(dst + off, src, n);
        }
        dst += d_1bde2c;
        src += w;
        if (++cnt >= h) {
            cnt = 0;
            src = (char *)((int)(((RivaRasterImage*)(hd))->f_0fb0b0()));
        }
    }
}


//@ f_09f7d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die Darstellung der aktuellen Hilfeseite im Offscreen-Puffer d_1bdfec und kopiert
 *   den sichtbaren Bereich samt den aktivierten/deaktivierten Schaltflächen der unteren Werkzeugleiste auf den
 *   Bildschirm. Bei kleinen Scrollbewegungen (diff) verschiebt die Funktion den vorhandenen Pufferinhalt per
 *   memmove und zeichnet nur den neu hereingescrollten Streifen über f_09f6a0 und f_15ae98 nach.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable d_1bde74 enthält die aktuelle, d_1bde1c die vorherige Scrollposition,
 *   d_1bde78 die untere Scrollgrenze, d_1bde84 den aktuell fokussierten und d_1bde88 den zuvor fokussierten
 *   Hyperlink.
 === Ende Beschreibung === */
#define MKR_REV(r, a, b, c, d) { \
    int _d = (d), _c = (c), _b = (b), _a = (a); \
    (r).x1 = _a; (r).y1 = _b; (r).x2 = _c; (r).y2 = _d; \
}
#define SET_CLIP(r1, r2) { \
    int _d = d_1bde30 - 1, _c = d_1bde2c - 1; \
    (r1).x1 = 0; (r1).y1 = 0; (r1).x2 = _c; (r1).y2 = _d; \
    int _d2 = d_1bde80 + _d, _c2 = d_1bde7c + _c, _b2 = d_1bde80, _a2 = d_1bde7c; \
    (r2).x1 = _a2; (r2).y1 = _b2; (r2).x2 = _c2; (r2).y2 = _d2; \
    d_1bdfc8 = (r2); \
}

// r80/r90 als eigene, adressierte Rechtecke (Original: Hilfsrechtecke mit Adressnahme)
static inline void use_09f7d0(R *) {}
void f_09f7d0(void)
{
    
    struct R *f_15d90c(struct R *, int);
    struct P f_15da8c(int);
    short f_0bf820(void *, ...);
    int diff, hd1, f2, hd2, spr, tmp, flag;
    short w, h;
    signed char druck_status;
    struct {
        struct R r00, r10, r20, r30, r40, r50, r60, r70;
    } f;
    struct R ra0v, r90v;
    struct R r20;
    struct R *clip;

#define r00 (f.r00)
#define r10 (f.r10)
#define r20 (f.r20)
#define r30 (f.r30)
#define r40 (f.r40)
#define r50 (f.r50)
#define r60 (f.r60)
#define r70 (f.r70)
#define r80 (r80v)
#define r90 (r90v)
#define ra0 (ra0v)

    clip = &r40;
    { int s = d_1bde28 - d_1bde30; s += d_1bde50; d_1bde78 = s + d_1bde60; }
    {
        int _d = d_1bde30 - 1, _c = d_1bde2c - 1;
        r90.x1 = 0; r90.y1 = 0;
        int _d2 = d_1bde80 + _d, _c2 = d_1bde7c + _c;
        r90.x2 = _c; r90.y2 = _d;
        int _b2 = d_1bde80, _a2 = d_1bde7c;
        r40.y1 = _b2; r40.y2 = _d2; r40.x2 = _c2; r40.x1 = _a2;
        d_1bdfc8 = *clip;
    }
    use_09f7d0(&r90v);
    if (d_1bde84 != d_1bde88 && d_1bde84 != -1) {
        r20 = *f_15d90c(&r00, d_1bde84);
        if (r20.y1 - d_1bde60 < d_1bde74)
            d_1bde74 = r20.y1 - d_1bde60;
        else if (r20.y2 - d_1bde60 >= d_1bde74 + d_1bde5c - 2)
            d_1bde74 = r20.y2 - d_1bde60 - d_1bde5c + 2;
    }
    if (d_1bde74 > d_1bde78)
        d_1bde74 = d_1bde78;
    if (d_1bde74 < -d_1bde60)
        d_1bde74 = -d_1bde60;
    diff = d_1bde74 - d_1bde1c;
    if (diff >= d_1bde30 - d_1bde50 || diff <= d_1bde50 - d_1bde30)
        d_1bdfbc = 1;
    if (d_1bdfbc) {
        f_09f6a0(0, d_1bde30);
        { int cy=d_1bde30-1; int cx=d_1bde2c; --cx; r10.x1=0;r10.y1=0;r10.x2=cx;r10.y2=cy; }
        f_15ae98(0, d_1bde74, &r10);
    } else if (diff > 0) {
        int off = diff * d_1bde2c;
        int n = d_1bde30 - diff; n *= d_1bde2c;
        char *base = (char *)d_1bdfec;
        memmove(base, base + off, n);
        f_09f6a0(d_1bde30 - diff, diff);
        { int _d = d_1bde30 - 1, _c = d_1bde2c - 1, _b = d_1bde30 - diff - d_1bde50; _c = (_c & 0) ? 0 : _c; /* haelt die Registerzuteilung wie im Original */ r60.x1 = 0; r60.y1 = _b; r60.x2 = _c; r60.y2 = _d; }
        f_15ae98(0, d_1bde74, &r60);
    } else if (diff < 0) {
        int off = diff * d_1bde2c;
        int n = (d_1bde30 + diff) * d_1bde2c;
        char *base = (char *)d_1bdfec;
        memmove(base - off, base, n);
        f_09f6a0(0, -diff);
        { int _d = d_1bde50 - diff - 1, _c = d_1bde2c - 1; ra0.x1 = 0; ra0.y1 = 0; ra0.y2 = _d; ra0.x2 = _c; }
        f_15ae98(0, d_1bde74, &ra0);
    }
    { int _d = d_1bde30 - 1, _c = d_1bde2c - 1;
    r30.x1 = 0; r30.y1 = 0; r30.x2 = _c; r30.y2 = _d;
    int _d2 = _d + d_1bde80, _c2 = _c + d_1bde7c;
    r70.x1 = d_1bde7c; r70.y1 = d_1bde80; r70.x2 = _c2; r70.y2 = _d2;
    d_1bdfc8 = r70; }
    if (d_1bde88 != d_1bde84 || d_1bdfbc) {
        if (d_1bde88 != -1) {
            f_15d4dc();
            f_09d850(d_1bde88);
        }
        if (d_1bde84 != -1) {
            f_15d4d0(d_1bde84);
            f_09d850(d_1bde84);
        }
    }
    { 
    int _d = d_1bde30 - 1, _c = d_1bde2c - 1;
    struct R r80v; use_09f7d0(&r80v); r80.x1 = 0; r80.y1 = 0; r80.x2 = _c;
    int _d2 = d_1bde80 + _d; r80.y2 = _d;
    int _c2 = _c + d_1bde7c;
    int _b2 = d_1bde80, _a2 = d_1bde7c;
    r50.x1 = _a2; r50.x2 = _c2; r50.y2 = _d2; r50.y1 = _b2; 
    d_1bdfc8 = r50; \
    }
    if (diff || d_1bdfbc || d_1bde88 != d_1bde84) {
        if (d_1bf4f2 <= d_1bde5c)
            f_0d2710();
        f_099ea0();
        if (d_1bdfb8) {
            f_13e690(*(unsigned *)&d_1bdfec + d_1bde60 * d_1bde2c, 0, 0, 0, (short)d_1bde54, (short)d_1bde5c, (short)d_1bde2c);
            hd1 = f_09d640(d_1b706a);
            hd2 = f_09d640(d_1b7075);
        } else {
            memcpy((void *)d_1a34e0, (void *)(d_1bdfec + d_1bde60 * d_1bde2c), d_1bde2c * d_1bde5c);
            hd1 = f_09d640(d_1b7081);
            hd2 = f_09d640(d_1b708b);
        }
        ((RivaRasterImage*)(hd1))->f_0fb210((short *)( &w),(short *)( &h));
        spr = (tmp = (int)new (mark(d_1a3584, 0x9dd)) Spr9) ? ((int)(((RivaRasterImage*)(tmp))->f_0fac80( w, h))) : tmp;
        if (d_1bdfbc || (flag = (d_1bde74 < d_1bde78)) != (d_1bde1c < d_1bde78)) {
            f_0d2710();
            tmp = (d_1bde74 < d_1bde78) ? hd1 : hd2;
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1bdff8, (short)(d_1bdffa - d_1bde5c), (short)(d_1bdffc - d_1bdff8 + 1), (short)(d_1bdffe - d_1bdffa + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1bdff8, d_1bdffa, (short)(d_1bdffc - d_1bdff8 + 1), (short)(d_1bdffe - d_1bdffa + 1));
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1be008, (short)(d_1be00a - d_1bde5c), (short)(d_1be00c - d_1be008 + 1), (short)(d_1be00e - d_1be00a + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1be008, d_1be00a, (short)(d_1be00c - d_1be008 + 1), (short)(d_1be00e - d_1be00a + 1));
        }
        if (d_1bdfbc || (f2 = (d_1bde74 > -d_1bde60)) != (d_1bde1c > -d_1bde60)) {
            f_0d2710();
            tmp = (d_1bde74 > -d_1bde60) ? hd1 : hd2;
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1bdff0, (short)(d_1bdff2 - d_1bde5c), (short)(d_1bdff4 - d_1bdff0 + 1), (short)(d_1bdff6 - d_1bdff2 + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1bdff0, d_1bdff2, (short)(d_1bdff4 - d_1bdff0 + 1), (short)(d_1bdff6 - d_1bdff2 + 1));
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1be000, (short)(d_1be002 - d_1bde5c), (short)(d_1be004 - d_1be000 + 1), (short)(d_1be006 - d_1be002 + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1be000, d_1be002, (short)(d_1be004 - d_1be000 + 1), (short)(d_1be006 - d_1be002 + 1));
        }
        flag = (stricmp((char *)d_1bdea8, (char *)d_1bdea0) || d_1bde74 != -d_1bde60);
        if (d_1bdfbc || flag != d_1bde18) {
            f_0d2710();
            d_1bde18 = flag;
            tmp = flag ? hd1 : hd2;
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1be018, (short)(d_1be01a - d_1bde5c), (short)(d_1be01c - d_1be018 + 1), (short)(d_1be01e - d_1be01a + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1be018, d_1be01a, (short)(d_1be01c - d_1be018 + 1), (short)(d_1be01e - d_1be01a + 1));
        }
        flag = (d_1bde4c >= 0);
        if (d_1bdfbc || flag != d_1bde14) {
            f_0d2710();
            d_1bde14 = flag;
            tmp = flag ? hd1 : hd2;
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( tmp), d_1be010, (short)(d_1be012 - d_1bde5c), (short)(d_1be014 - d_1be010 + 1), (short)(d_1be016 - d_1be012 + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1be010, d_1be012, (short)(d_1be014 - d_1be010 + 1), (short)(d_1be016 - d_1be012 + 1));
        }
        if (d_1bdfbc) {
            f_0d2710();
            druck_status = d_1bfaf0;
            if (druck_status < 0 || d_1bdfac)
                hd1 = hd2;
            ((RivaRasterImage*)(spr))->f_0fb540((RivaRasterImage *)( hd1), d_1be030, (short)(d_1be032 - d_1bde5c), (short)(d_1be034 - d_1be030 + 1), (short)(d_1be036 - d_1be032 + 1));
            ((RivaRasterImage*)(spr))->f_0faec0((void *)( d_1a34e0), d_1be030, d_1be032, (short)(d_1be034 - d_1be030 + 1), (short)(d_1be036 - d_1be032 + 1));
        }
        if (spr)
            operator delete((void *)((int)(((RivaRasterImage*)(spr))->f_0fad20( 0))));
        if (d_1bdfc4) {
            f_0d2f90(0, 1);
            f_0d26e0();
        }
    }
    d_1bde88 = d_1bde84;
    d_1bdfbc = 0;
    d_1bde1c = d_1bde74;
    if (d_1bdfb4) {
        d_1bdfb4 = 0;
        f_09a120(d_1bde9c, 0x19);
    }
#undef r00
#undef r10
#undef r20
#undef r30
#undef r40
#undef r50
#undef r60
#undef r70
#undef r80
#undef r90
#undef ra0
}




//@ f_0a01a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette interaktive Sitzung des Hypertext-Hilfesystems für das Startthema p1 (und
 *   das Inhaltsverzeichnis-Thema p2) aus: Die Funktion sichert den aktuellen Spielbildschirm und die Palette,
 *   reserviert den Offscreen-Puffer d_1bdfec, die Schriftarten (d_1bde3c, d_1bde40), den Bild-Cache (d_1bde8c)
 *   und die 30-stufige Historie (d_1bde90), verarbeitet Maus- und Tastatureingaben (Scrollen, Tab-Navigation
 *   zwischen Hyperlinks, Folgen von Verweisen, Zurückspringen, Auflösungswechsel mit F10 und Drucken) und stellt
 *   beim Verlassen den Spielbildschirm wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dateinamen des Startthemas p1 (char *) sowie den optionalen
 *   Namen des Hauptindex p2 (char *) und gibt 1 bei Erfolg oder 0 bei fehlendem Startthema zurück (int).
 * - Wichtige Variablen: Der Offscreen-Puffer d_1bdfec umfasst 0x55000 (348.160) Bytes für bis zu 640x544 Pixel,
 *   d_1bdea0 verweist auf die Startseite für die Inhalts-Schaltfläche (F1) und d_1bdfb8 steuert den aktiven
 *   Auflösungsmodus.
 === Ende Beschreibung === */
#pragma inline_depth(255)
#pragma aux f_09d640 parm [eax edx] modify exact [eax]
struct S58 {
    int a;
    char b[0x54];
};

static inline signed char get_bfaf0(void) { return d_1bfaf0; }
static inline signed char get_bfb14(void) { return d_1bfb14; }
static inline int as_int(int x) { return x; }

static inline void del_c(void *p) {
    if (p)
        operator delete((void *)((int)(((RivaRasterImage*)((int)p))->f_0fad20( 0))));
}

static inline void del_d(void *p) {
    if (p)
        operator delete((void *)f_15c6d0((int)p, 0));
}

static inline void set_rp(struct R *r, int a, int b, int c, int d) {
    r->x1 = a;
    r->y1 = b;
    r->x2 = c;
    r->y2 = d;
}

static inline void set_r(struct R &r, int a, int b, int c, int d) {
    r.x1 = a;
    r.y1 = b;
    r.x2 = c;
    r.y2 = d;
}

static inline int db80s(const char *p1, int *p2, int *p3, short *pa, short *pb)
{
  int r = f_09d640(p1);
  if (d_1bdfb0 != 0) {
    *p2 = 8;
    *p3 = 1;
    return 1;
  }
  if (r != 0) {
    ((RivaRasterImage*)(r))->f_0fb210((short *)( pa),(short *)( pb));
    *p2 = *pa;
    *p3 = *pb;
    return 1;
  }
  return r;
}

static inline int db80(const char *p1, int *p2, int *p3)
{
  short b; short a;
  int r = f_09d640(p1);
  if (d_1bdfb0 != 0) {
    *p2 = 8;
    *p3 = 1;
    return 1;
  }
  if (r != 0) {
    ((RivaRasterImage*)(r))->f_0fb210((short *)( &a),(short *)( &b));
    *p2 = a;
    *p3 = b;
    return 1;
  }
  return r;
}

static inline int db80b(const char *p1, int *p2, int *p3)
{
  short a; short b;
  int r = f_09d640(p1);
  if (d_1bdfb0 != 0) {
    *p2 = 8;
    *p3 = 1;
    return 1;
  }
  if (r != 0) {
    ((RivaRasterImage*)(r))->f_0fb210((short *)( &a),(short *)( &b));
    *p2 = a;
    *p3 = b;
    return 1;
  }
  return r;
}

#define MKR_KD(r, a, b, c, d) { \
    int _d = (d), _c = (c), _b = (b), _a = (a);  /* haelt die Auswertungsreihenfolge wie im Original */ \
    (r).x1 = _a; (r).y1 = _b; (r).x2 = _c; (r).y2 = _d; \
}
#define MKR_O1(r, a, b, c, d) { \
    int _a = (a), _b = (b), _c = (c), _d = (d); \
    (r).x1 = _a; (r).y1 = _b; (r).x2 = _c; (r).y2 = _d; \
}
#define MKR_S1(r, a, b, c, d) { \
    (r).y1 = (b); (r).x2 = (c); (r).y2 = (d); (r).x1 = (a); \
}
#define MKR_S2(r, a, b, c, d) { \
    (r).x2 = (c); (r).y2 = (d); (r).x1 = (a); (r).y1 = (b); \
}
#define MKR_S3(r, a, b, c, d) { \
    int _d = (d), _c = (c), _b = (b), _a = (a); \
    (r).y1 = _b; (r).x2 = _c; (r).y2 = _d; (r).x1 = _a; \
}
#define MKR_REV3(r, a, b, c, d) { \
    int _d = (d), _c = (c), _b = (b), _a = (a); { int u_ = _c; _c = u_; } /* haelt die Registerzuteilung wie im Original */ \
    (r).x1 = _a; (r).y1 = _b; (r).x2 = _c; (r).y2 = _d; \
}
static inline int inl_09ea10(struct R *r) {
    int last = -1;
    int cur = f_15d744(r);
    if (cur == -1) {
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
        cur = f_15d584(r);
    }
}

struct T14_c {
    short a, b, c;
    int d, e;
    T14_c(short _a, short _b, short _c, int _d, int _e) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        e = _e;
    }
};

static inline void sr_dbac(struct R &r, int d, int b, int a, int c) {
    r.x1 = a;
    r.y1 = b;
    r.x2 = c;
    r.y2 = d;
}
static inline void sr_bacd(struct R &r, int b, int a, int c, int d) {
    r.x1 = a;
    r.y1 = b;
    r.x2 = c;
    r.y2 = d;
}
static inline void sb_abcd_abdc(struct R &r, int a, int b, int c, int d) {
    r.x1 = a;
    r.y1 = b;
    r.y2 = d;
    r.x2 = c;
}
static inline void sb_dbac_bacd(struct R &r, int d, int b, int a, int c) {
    r.y1 = b;
    r.x1 = a;
    r.x2 = c;
    r.y2 = d;
}
static inline void sp_adcb_abcd(struct R*r,int a,int d,int c,int b){r->x1=a;r->y1=b;r->y2=d;r->x2=c;}
static inline void sb_abcd_dbca(struct R &r, int a, int b, int c, int d) {
    r.y2 = d;
    r.x1 = b;
    r.x2 = c;
    r.y1 = a;
}

static inline void sb_dbac_adcb(struct R &r, int d, int b, int a, int c) {
    r.x1 = a;
    r.y2 = d;
    r.x2 = c;
    r.y1 = b;
}

static inline void init_chars_A9H(){int i,v;char*q;for(i=0;i<256;i++){v=i;v=i;v=i;v=i;v=i;if(d_1bde20+(d_1bde74^d_1bde74)==1){q=strchr(d_1a357c,i);if(q)v=(signed char)d_1a3580[q-d_1a357c];}d_1bdeac[i]=(unsigned char)v;}}
static inline void native_r84_A9H(R &r,int a,int b,int c,int d){r.x1=a;r.x2=c;r.y2=d;r.y1=b;}
static inline void rfperm_A17(R&r,int a,int b,int c,int d){r.x1=a;r.y1=b;r.y2=d;r.x2=c;}
static inline void matched84_A17(R&r,int b,int a,int c,int d){r.y1=b;r.x2=c;r.y2=d;r.x1=a;}
static inline void touch_R_A17(R*){}
static inline void touch_P_A17(P*){}
static inline void scalar_pair_touch_A17(void*){}
static inline void inverse_re4_A17(R&r,int a,int b,int c,int d){r.x2=c;r.x1=a;r.y2=d;r.y1=b;}
static inline void load_r14_A17(R&r,int a,int b,int d,int c){r.x1=a;r.y1=b;r.y2=d;r.x2=c;}
static inline void orig84sig_A17(R&r,int b,int a,int d,int c){r.y1=b;r.x2=c;r.y2=d;r.x1=a;}
static inline void two124_A17(R&r,int d,int c){int d0=d;int d1=d0+1;int c0=c;r.x1=0;r.y1=r.x1;r.y2=d1;r.x2=c0;}
int f_0a01a0(char *p1, char *p2)
{
    struct R *f_15d90c(struct R *, int);
    struct {char buf[0x14];R r14,r24,r34,r44,r54,r64;} f;
    R re4;
    R rd4;
    R r124;
    R ra4;
    R r104;
    R rc4;
    R r94;
    P p144;
    R r84;
    P p134;
    R rb4;
    R rf4;
    P p13c;
    R r114;
    R r74;
    int i;
    int saved_c94;
    int saved_b8;
    int saved_width;
    int mouse_l;
    int mouse_vis;
    char *name = p2;
    int rc = 1;
    int mouse_r;
    int choice;
    int p_res;
    int tmp;
    int old_x, old_y;
    short key;
    short b1, b2, a1, a2;
    touch_R_A17(&rb4);touch_R_A17(&r74);touch_P_A17(&p144);scalar_pair_touch_A17(&old_y);scalar_pair_touch_A17(&saved_b8);

    switch (d_1c20b0) {
    case 1:
        goto one;
    case 2:
    case 3:
    one:
        d_1bde20 = 1;
        break;
    default:
        d_1bde20 = 0;
        break;
    }
    mouse_vis = f_0d3860();
    f_0d2710();
    d_1bde94 = (tmp = f_147c84(new (mark(d_1a3584, 0xa9e)) char[0x300], 0x100, d_1baac0)) ? tmp : 0;
    d_1bde9c = (tmp = f_147c84(new (mark(d_1a3584, 0xa9f)) char[0x300], 0x100, d_1baac0)) ? tmp : 0;
    d_1bde98 = (tmp = f_147c84(new (mark(d_1a3584, 0xaa0)) char[0x300], 0x100, d_1baac0)) ? tmp : 0;
    memset((void *)d_1bde98, 0, 0x300);
    f_149eb4(d_1bde94, 0, 0x100);
    d_1c0c4c++;
    saved_c94 = *(volatile int *)&d_1c0c94; // haelt die Ladereihenfolge wie im Original
    d_1c0c94 = 0;
    f_09ac80(d_1a34e0, 0, 0);
    f_09a140(0, 0x19);
    d_1bdfc4 = 1;
    mouse_l = 0;
    d_1bdfbc = 1;
    d_1bde64 = -1;
    d_1bde68 = -1;
    d_1bdfb8 = 0;
    d_1bde84 = 0;
    d_1bdea8 = (int)new (mark(d_1a3584, 0xab8)) char[0x50];
    d_1bdfe4 = 0;
    d_1bdfe8 = 0;
    d_1bde38 = 0;
    d_1bde34 = 0;
    d_1bde40 = 0;
    d_1bde3c = 0;
    d_1bde4c = -1;
    mouse_r = 0;
    d_1bde90 = (int)new (mark(d_1a3584, 0xac2)) char[0xa50];
    d_1bde70 = -1;
    for (i = 0; i < 0x1e; i++) {
        (*(S58 **)&d_1bde90)[i].a = 0;
    }
    d_1bde8c = (int)new (mark(d_1a3584, 0xac8)) char[0x2e0];
    d_1bde6c = 0;
    for (i = 0; i < 8; i++) {
        (*(S5C **)&d_1bde8c)[i].b[0] = 0;
        (*(S5C **)&d_1bde8c)[i].a = 0;
    }
    f_09d640(d_1b7096);
    d_1bdfec = (int)new (mark(d_1a3584, 0xad3)) char[0x55000];
    db80s(d_1b709d, &p144.x, &p144.y, &a1, &b1);
    d_1bde34 = (T14 *)new (mark(d_1a3584, 0xada)) T14_c(1, 0x140, 0xc8 - p144.y + 0x40, 0xa0000, (int)d_1bacd0);
    f_05ded0(d_1bde34, d_1bdfec);
    db80s(d_1b70a7, &p144.x, &p144.y, &a2, &b2);
    d_1bde38 = (T14 *)new (mark(d_1a3584, 0xadd)) T14_c(2, 0x280, 0x1e0 - p144.y + 0x40, 0xa0000, (int)d_1bacc4);
    f_05ded0(d_1bde38, d_1bdfec);
    d_1bde3c = (VB *)((tmp = (int)new (mark(d_1a3584, 0xaef)) B420) ? f_045a90((void *)tmp, d_1bde34, ((char*)&d_1c2098)) : (void *)tmp);
    f_045b70(d_1bde3c, 0x130000);
    d_1bde40 = (VB *)((tmp = (int)new (mark(d_1a3584, 0xaf5)) B420) ? f_045a90((void *)tmp, d_1bde38, ((char*)&d_1c2098)) : (void *)tmp);
    f_045b70(d_1bde40, 0x130000);
    init_chars_A9H();
    f_09f070(get_bfb14() != 0, 1);
    {
        int _d=d_1bde30-1,_c=d_1bde2c-1;
        R *clip_view_D11=&r74,*bounds_view_D11=&rb4;
        bounds_view_D11->x1=0;bounds_view_D11->y1=0;
        {int keep_D11=_d;_d=keep_D11;}
        int y_D11=d_1bde80,right_D11=d_1bde7c+_c,x_D11=d_1bde7c;
        {int keep_D11=right_D11;right_D11=keep_D11;}
        {int keep_D11=x_D11;x_D11=keep_D11;}
        clip_view_D11->x2=right_D11;
        clip_view_D11->x1=x_D11;
        bounds_view_D11->y2=_d;
        clip_view_D11->y1=y_D11;
        int bottom_D11=_d+y_D11;
        clip_view_D11->y2=bottom_D11;
        {int keep_D11=_c;_c=keep_D11;}
        {int keep_D11=_c;_c=keep_D11;}
        bounds_view_D11->x2=_c;
        d_1bdfc8=r74;
    }
    f_156c70();
    if (!f_09ece0(p1)) {
        rc = 0;
    } else {
        if (name)
            d_1bdea0 = (int)name;
        else
            d_1bdea0 = d_1a3c1c;
        old_x = old_y = -10;
        do {
            do {
                f_069460();
                if (old_x != d_1bf4f0 || d_1bf4f2 != old_y) {
                    if (!d_1bdfc4) {
                        d_1bdfc4 = 1;
                        f_0d2f90(0, 1);
                        f_0d26e0();
                    }
                    const int&viewport_A17=(int)d_1bf4f2;
                    if (viewport_A17 < d_1bde5c) {
                        int py=*(volatile short*)&d_1bf4f2;int output_A17=d_1bde60;py+=d_1bde74;output_A17+=py;
                        p134.x = d_1bf4f0;
                        p134.y = output_A17;
                        d_1bde84 = f_15d754(&p134);
                    }
                    old_x = d_1bf4f0;
                    old_y = d_1bf4f2;
                }
                key = _bios_keybrd(1);
                if ((_bios_keybrd(2) & 0x0f) == 0x0b && !d_1bc944)
                    f_053c50();
                if (as_int(key) == 0x1011) {
                    f_144570();
                    f_148534(0);
                }
                f_0d32f0();
                f_09f7d0();
                f_0f0130(d_1c2e68);
                f_0d48a0(d_1c2e68);
            } while (as_int(key) == 0 && f_0d3780() == mouse_l && (!f_0d3780() || d_1bf4f2 < d_1bde5c) && f_0d37b0() == mouse_r);
            f_0d4880(d_1c2e68);
            if (key) {
                d_1bdfc4 = 0;
                f_0d2710();
                mouse_l = 0;
                mouse_r = 0;
                f_149d20();
            } else if (f_0d3780()) {
                if (f_0d33d0(&d_1bdff8))
                    key = 0x5000;
                else if (f_0d33d0(&d_1bdff0))
                    key = 0x4800;
                else
                    mouse_l = 1;
            } else if (mouse_l) {
                mouse_l = 0;
                mouse_r = 0;
                if (f_0d33d0(&d_1be020))
                    key = 0x11b;
                else if (f_0d33d0(&d_1be010))
                    key = 0xe08;
                else if (f_0d33d0(&d_1be030))
                    key = d_1c2104;
                else if (f_0d33d0(&d_1be018))
                    key = 0x3b00;
                else if (f_0d33d0(&d_1be008))
                    key = 0x5100;
                else if (f_0d33d0(&d_1be000))
                    key = 0x4900;
                else if (f_0d33d0(&d_1be028))
                    key = 0x4400;
                else if (d_1bde84 != -1 && d_1bf4f2 < d_1bde5c)
                    key = 0x3920;
            } else if (f_0d37b0()) {
                mouse_r = 1;
            } else if (mouse_r) {
                key = 0xe08;
                mouse_l = 0;
                mouse_r = 0;
            }
            switch (key) {
            case 0x3b00:
                if (stricmp((char *)d_1bdea8, (char *)d_1bdea0)) {
                    f_09ece0((char *)d_1bdea0);
                    d_1bde74 = -d_1bde60;
                    d_1bdfbc = 1;
                } else {
                    d_1bde74 = -d_1bde60;
                }
                break;
            case 0x4400:
                f_0d2710();
                f_09f070(d_1bdfb8 == 0, 1);
                break;
            case 0x4700:
                d_1bde74 = -d_1bde60;
                break;
            case 0x4f00:
                d_1bde74 = d_1bde78;
                break;
            case 0x4900:
                d_1bde74 -= d_1bde5c - d_1bde50 * 3;
                break;
            case 0x5100:
                d_1bde74 += d_1bde5c - d_1bde50 * 3;
                break;
            case 0x4800:
                d_1bde74 -= d_1bde50;
                break;
            case 0x5000:
                d_1bde74 += d_1bde50;
                break;
            case 0x0f00:
                if (d_1bde84 == -1) {
                    inverse_re4_A17(re4,0,0,d_1bde2c*2,d_1bde74+d_1bde60+d_1bde5c+1);
                    d_1bde84 = inl_09ea10(&re4);
                    if (d_1bde84 == -1) {
                        set_r(f.r24, 0, 0, d_1bde2c * 2, d_1bde28 + 1);
                        d_1bde84 = f_15d744(&f.r24);
                    }
                } else {
                    f.r64 = *f_15d90c(&rd4, d_1bde84);
                    if (d_1bde74 + d_1bde60 > f.r64.y1 || d_1bde74 + d_1bde60 + d_1bde5c < f.r64.y2) {
                        set_r(f.r54, 0, d_1bde74 + d_1bde60, d_1bde2c * 2, d_1bde74 + d_1bde60 + d_1bde5c + 1);
                        tmp = inl_09ea10(&f.r54);
                        if (tmp == -1)
                            d_1bde88 = -1;
                        else
                            d_1bde84 = tmp;
                    } else {
                        two124_A17(r124,d_1bde74+d_1bde60+d_1bde5c,d_1bde2c*2);
                        d_1bde84 = f_09ea10(&r124);
                        if (d_1bde84 == -1) {
                            rfperm_A17(rf4,0,0,d_1bde2c*2,d_1bde28+1);
                            d_1bde84 = inl_09ea10(&rf4);
                        }
                    }
                }
                break;
            case 0x0f09:
                if (d_1bde84 == -1) {
                    {int h=d_1bde28+1;orig84sig_A17(r84,d_1bde74+d_1bde60,0,h,d_1bde2c*2);}
                    d_1bde84 = f_15d744(&r84);
                    if (d_1bde84 == -1) {
                        {int h_A17=d_1bde28+1;load_r14_A17(f.r14,0,0,h_A17,d_1bde2c*2);}
                        d_1bde84 = f_15d744(&f.r14);
                    }
                } else {
                    f.r64 = *f_15d90c(&f.r34, d_1bde84);
                    if (d_1bde74 + d_1bde60 > f.r64.y1 || d_1bde5c + (d_1bde74 + d_1bde60) < f.r64.y2) {
                        {int top_A15=d_1bde74+d_1bde60;{int a=top_A15;top_A15=a;}{int a=top_A15;top_A15=a;}int bottom_A17=top_A15+d_1bde5c+1;{int a=bottom_A17;bottom_A17=a;}int width_A15=d_1bde2c*2;{int a=width_A15;width_A15=a;}{int a=width_A15;width_A15=a;}sp_adcb_abcd(&r114,0,bottom_A17,width_A15,top_A15);}
                        tmp = f_15d744(&r114);
                        if (tmp == -1)
                            d_1bde88 = -1;
                        else
                            d_1bde84 = tmp;
                    } else {
                        {int d=d_1bde28+1,c=d_1bde2c*2;{int copy_A17=c;c=copy_A17;}r94.x1=0;r94.y1=d_1bde74+d_1bde60;r94.x2=c;r94.y2=d;}
                        d_1bde84 = f_09ea10(&r94);
                        f_15d4d0(d_1bde84);
                        {int d=d_1bde28+1,c=d_1bde2c*2,b=d_1bde74+d_1bde60;const int &a=0;r104.x1=a;r104.y1=b;r104.x2=c;r104.y2=d;}
                        d_1bde84 = f_15d584(&r104);
                        if (d_1bde84 == -1) {
                            set_rp(&ra4, 0, 0, d_1bde2c * 2, d_1bde28 + 1);
                            d_1bde84 = f_15d744(&ra4);
                        }
                    }
                }
                break;
            case 0x3920:
            case 0x1c0d:
                if (d_1bde84 != -1) {
                    p13c = f_15da8c(d_1bde84);
                    d_1bde88 = d_1bde84;
                    d_1bde84 = -1;
                    f_09f7d0();
                    old_y = old_x = -10;
                    f_09ece0((char *)p13c.x);
                }
                break;
            case 0x0e08:
                f_09eb60();
                old_y = old_x = -10;
                d_1bde88 = -1;
                break;
            default:
                if (key == d_1c2104) {
                    int err = 0;
                    p_res = 0;
                    if (get_bfaf0() >= 0 && !d_1bdfac) {
                        saved_b8 = d_1bdfb8;
                        f_09f070(0, 0);
                        f_09a400();
                        f_0d26e0();
                        choice = f_0bf820(d_1c2c64, 0x200001d6, 2, 0x200001d8, 0x200001d7);
                        if (choice > 0) {
                            f_0e4cb0();
                            if (get_bfaf0() == 0) {
                                strcpy(f.buf, d_1b6fb2);
                                d_1c0098 = f_144fbf(f.buf, 0x261, 0x180);
                                if (d_1c0098 <= 0) {
                                    f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, ((int *)d_1c008c)[0x6e]));
                                    err = 1;
                                }
                            } else {
                                if (!f_0ce250()) {
                                    f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, ((int *)d_1c008c)[1]));
                                    err = 1;
                                } else {
                                    p_res = f_0bf820(d_1c2c64, f_133fe0((int)d_1c3498, ((int *)d_1c008c)[0]), 1, f_133fe0((int)d_1c3498, ((int *)d_1c008c)[0x6d]));
                                }
                            }
                            if (!err && p_res != -1) {
                                int saved_height = d_1bde30;
                                saved_width = d_1bde2c;
                                { int u_ = saved_height; saved_height = u_; } // haelt die Registerzuteilung wie im Original
                                f_0d2f90(5, 1);
                                d_1bdfb0 = 1;
                                d_1bde44 = 0;
                                d_1bde48 = 0;
                                d_1bde2c = 0x50;
                                d_1bde30 = 100000;
                                d_1bdea4 = (int)new (mark(d_1a3584, 0x398)) char[0xc8];
                                if (choice == 2) {
                                    T8 *p;
                                    for (p = d_1a35a4; ; p++) {
                                        d_1bde44 = 0;
                                        d_1bde48 = 0;
                                        if (f_09ece0((char *)p->a)) {
                                            MKR_REV3(rc4, 0, 0, d_1bde24, d_1bde28 + 0x64);
                                            f_15ae98(0, 0, &rc4);
                                        }
                                        f_0e9240(d_1bdea4);
                                        *(char *)d_1bdea4 = 0;
                                        if (p->b == 0x1003d)
                                            break;
                                        f_0e9240((int)d_1b6fbe);
                                        f_0e9240((int)d_1b6fbf);
                                        f_0e9240((int)d_1b6fc0);
                                        f_0e9240((int)d_1b6fc1);
                                    }
                                } else {
                                    MKR_REV3(f.r44, 0, 0, d_1bde24, d_1bde28 + 0x64);
                                    f_15ae98(0, 0, &f.r44);
                                    f_0e9240(d_1bdea4);
                                    *(char *)d_1bdea4 = 0;
                                }
                                operator delete((void *)d_1bdea4);
                                d_1bde30 = saved_height;
                                d_1bde2c = saved_width;
                                d_1bdfb0 = 0;
                                f_0d2e70();
                                if (get_bfaf0() == 0)
                                    f_145259(d_1c0098);
                            }
                            operator delete((void *)d_1c0088);
                            operator delete((void *)d_1c008c);
                        }
                        f_09f070(saved_b8, 1);
                    }
                }
                break;
            }
        } while (as_int(key) != 0x11b && key != d_1c2106);
    }
    f_0d2710();
    f_09f070(0, 1);
    f_09ade0(d_1a34e0, 0, 0);
    f_09aed0(0);
    if (!d_1be178)
        f_09a120(d_1bde94, 0x19);
    d_1c0c94 = saved_c94;
    d_1c0c4c--;
    if (d_1bde40)
        delete d_1bde40;
    if (d_1bde3c)
        delete d_1bde3c;
    if (d_1bde38)
        operator delete(d_1bde38);
    if (d_1bde34)
        operator delete(d_1bde34);
    if (d_1bdfe4)
        del_c((void *)d_1bdfe4);
    if (d_1bdfe8)
        del_c((void *)d_1bdfe8);
    if (d_1bdfec)
        operator delete((void *)d_1bdfec);
    operator delete((void *)d_1bde94);
    operator delete((void *)d_1bde9c);
    operator delete((void *)d_1bde98);
    if (d_1bdea8)
        operator delete((void *)d_1bdea8);
    operator delete((void *)d_1bde90);
    for (i = 0; i < 8; i++) {
        if ((*(S5C **)&d_1bde8c)[i].a != 0) {
            del_c((*(S5C **)&d_1bde8c)[i].c);
            del_d((*(S5C **)&d_1bde8c)[i].d);
        }
    }
    operator delete((void *)d_1bde8c);
    f_156c94();
    if (mouse_vis)
        f_0d26e0();
    return rc;
}



