/* === Beschreibung (Katalog) ===
 * Einheit fi_aceov (0x06fad0 - 0x0709d0)
 *
 * Überblick
 * Die Einheit fi_aceov (fi_aceov.cpp, vermutlich "Fight ACE Overlay") verwaltet den Auf- und Abbau der
 * grafischen Kampfoberfläche (UI-Puffer, Heldenporträts, Aktions-Icons, Ein-/Ausblendung,
 * Kampfbeginn-/-ende-Schriftzüge) sowie den 10-Slot-Pool d_1bd93c für temporäre Kampf-Effektsprites und den
 * Kampftimer-Callback (f_06fad0, f_06fb00).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 2/4 gleich (suche.py 26.10.2026, Basis fi_aceov_P1.CPP)
// fi_aceov.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06FAD0-0x0709D0
#include <string.h>
struct X9 { char b[9]; X9(int w, int h); ~X9(); };
struct Y { char b[0xf4]; Y(void *a, int f); ~Y(); };
struct Item { char p0[9]; unsigned char b9; char p1[2]; signed char t; unsigned char d; char p2; Y *y; char p3[4]; Item *next; char p4[4]; signed char flag; };
struct RGB3 { char r, g, b; };
typedef X9 *XP;
typedef Y *YP;
extern char *d_1a34e0;
extern short d_1bd910;
extern char d_1bd928;
extern Y **d_1bd93c;
extern int d_1bda54;
extern signed char d_1bfb2c;
extern int d_1c0004;
extern char d_1c2be0[];
extern char d_1c2d1c[];
extern char d_1bdbd4[];
extern Item *d_1c2ecc;
extern const char d_1a1be0[];
extern const char d_1b6f42[];
extern const char d_1b6f4f[];
extern const char d_1b6f38[];
static inline Item *F039(void *p) { return *(Item **)p; }
void __cdecl f_149eb4(void *p, int a, int b);
void __cdecl f_099ef0(void *p, int a, int b);
int f_07eba0(char *p, int a, int b);
int f_09a0d0(char *p);
int f_09a120(char *p, int a);
int f_09a140(int a, int b);
int f_0757f0(char *p);
char *f_014540(int a, const char *f, int l);
int f_09aa00(char *a, char *b, int c, int d, int e, int f, int g, int h);
int f_038c80(int a);
int f_0391b0(int a, int b);

int f_044e30(int a);
int f_045080(int a, X9 *o);


int f_04feb0(void *a, int b, int c, int d, int e, int f, void *g, void *h, int i);
int f_0d2710();
int f_0d26e0();
int f_10aad0(int o, const char *s, int a, int b);
int f_10a830(int o, short *a, short *b, short *c);
int f_1481a0(void *o, char *dst, short x, short y, short w, short h, int c);
short f_10af40(int o);
int f_10ac80(int o);
int f_10ae20(int o, int a, int b);
int f_077400(char *p);
int f_07b7e0(char *p);
int f_0d4730(int a);
int f_0d0ac0(int a);
int f_072810(int a, int b);
int f_06f5c0(char *p, int a, char *b);
int f_06ed10(char *p, int a, char *b);
int f_069a00(Y *o, char *b);
int f_06a600(Y *o, int a);
int f_07e930(char *p);
int f_07e8e0(char *p);
int f_09c780(void *p);
static inline int EQ(int a, int b) { return a == b; }
#define F(T,o) (*(T*)(p1 + (o)))
#define XF(o) F(XP,o)
#define XA(o,i) (((XP*)(p1 + (o)))[i])
#define SL ((YP*)(p1 + 0x211))
#define NEWX(line,w,h) new (mark(d_1a1be0, line)) X9(w, h)
//@ f_06fb20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut beim Eintritt in einen Kampf (oder nach dem Schließen eines Untermenüs) die gesamte
 *   grafische Kampfoberfläche für das Kampfsystem p1 auf: Blendet den Kampfscreen (im Graustufen-/Übergangsmodus
 *   d_1bfb2c != 1 über eine temporäre 64-Stufen-Palette pal) ein, räumt alte Sprite-Slots (SL[0..29] und
 *   d_1bd93c[0..9]) frei, alloziert die Hintergrund- und Icon-Puffer XF(0x121..0x141) sowie für jeden
 *   Gruppenhelden die Porträt- und Statuspuffer XA(0xe9, i)/XA(0x105, i), lädt die vier Aktionsicons aus 0x1000e
 *   und zeichnet den zentrierten Kampfbeginn-Schriftzug d_1b6f38.
 * - Eingaben und Rückgabe: Eingabe ist der Zeiger p1 (eax, char *) auf das Kampfsystem-Objekt; kein Rückgabewert
 *   (void).
 * - Wichtige Variablen: SL (p1 + 0x211) ist das 30-Slot-Array der Figuren-Sprites, d_1bd93c das 10-Slot-Array
 *   der Effekt-Sprites und d_1bd928 = 1 markiert den laufenden Aufbau.
 === Ende Beschreibung === */
void f_06fb20(char *p1)
{
    short lc, lh, lw, y;
    short i1;
    int cur, yy, xx;
    char *pal, *q;
    f_149eb4(F(void *, 0x10), 0, 0x100);
    if (F(unsigned char, 0x293) != (unsigned char)0xff) { f_07eba0(p1 + 0x39, F(unsigned char, 0x293), 0); F(char, 0x293) = 0xff; }
    if (F(unsigned char, 0x294) != (unsigned char)0xff) { f_07eba0(p1 + 0x39, F(unsigned char, 0x294), 0); F(char, 0x294) = 0xff; }
    if (EQ(d_1bfb2c, 1)) {
        f_09a0d0(d_1a34e0);
    } else {
        F(int, 0x201) = 0;
        *(unsigned *)&d_1bda54 = 1; // Haelt die vorzeichenlose Zuweisungssicht fuer die Registerfolge
        f_0757f0(p1);
        short k;
        pal = f_014540(0x300, d_1a1be0, 0x70);
        for (k = 0; k < 0x40; k++) {
            RGB3 *e = (RGB3 *)pal + k; e->r = e->g = e->b = k;
        }
        f_09aa00(d_1a34e0, F(char *, 0), 0, 0, 0x140, 0xc8, 0x140, 0);
        f_09a140(0, 0x19);
        memcpy(d_1a34e0, F(char *, 0), 0xfa00);
        f_09a120(pal, 0x19);
        operator delete(pal);
    }
    d_1bd910 = 0;
    for (i1 = 0; i1 < (short)30; i1++) {
        if (SL[i1] != 0) { delete SL[i1]; SL[i1] = 0; }
    }
    F(char, 0x291) = 0;
    for (i1 = 0; i1 < (short)10; i1++) {
        if (d_1bd93c[i1] != 0) { delete d_1bd93c[i1]; d_1bd93c[i1] = 0; }
    }
    XF(0x131) = NEWX(0x97, 200, 14);
    ((RivaRasterImage*)(XF(0x131)))->f_0fafb0((void *)( d_1a34e0), 0x3c, 0xa0);
    XF(0x135) = NEWX(0x9a, 0x1c, 0x25);
    XF(0x139) = NEWX(0x9b, 200, 14);
    XF(0x13d) = NEWX(0x9c, 0x20, 0x20);
    XF(0x141) = NEWX(0x9d, 0x18, 0x18);
    cur = f_038c80(d_1c0004);
    y = 0x3f;
    i1 = 0;
    do {
        XA(0xe9, i1) = NEWX(0xa3, 0x1c, 0x25);
        ((RivaRasterImage*)(XA(0xe9, i1)))->f_0fafb0((void *)( d_1a34e0), y, 6);
        XA(0x105, i1) = NEWX(0xa6, 0x10, 0x10);
        F(short, 0x16d + i1 * 2) = f_044e30(cur);
        f_045080(cur, XF(0x13d));
        y += 0x1c;
        ((RivaRasterImage*)(XF(0x13d)))->f_0fb0c0((RivaRasterImage *)( XA(0x105, i1)));
        i1++;
        cur = f_0391b0(d_1c0004, cur);
    } while (cur != f_038c80(d_1c0004));
    XF(0x121) = NEWX(0xb1, 0x10, 0x10);
    XF(0x125) = NEWX(0xb2, 0x10, 0x10);
    XF(0x129) = NEWX(0xb3, 0x10, 0x10);
    XF(0x12d) = NEWX(0xb4, 0x10, 0x10);
    q = p1 + 0x19d;
    f_04feb0(d_1c2be0, 0x1000e, ((int)(((RivaRasterImage*)(XF(0x125)))->f_0fb0b0())), 0, 0, 0, q, q, 0x140);
    f_04feb0(d_1c2be0, 0x1000e, ((int)(((RivaRasterImage*)(XF(0x129)))->f_0fb0b0())), 0, 2, 0, q, q, 0x140);
    f_04feb0(d_1c2be0, 0x1000e, ((int)(((RivaRasterImage*)(XF(0x12d)))->f_0fb0b0())), 0, 1, 0, q, q, 0x140);
    f_04feb0(d_1c2be0, 0x1000e, ((int)(((RivaRasterImage*)(XF(0x121)))->f_0fb0b0())), 0, 3, 0, q, q, 0x140);
    F(short, 0x14f) = 0;
    F(short, 0x149) = F(short, 0x14b) = F(short, 0x14d) = F(short, 0x14f);
    memset(p1 + 0x151, 0, 0xe);
    memset(p1 + 0x15f, 0, 0xe);
    memset(p1 + 0x17b, 0, 0x1c);
    f_0d2710();
    f_10aad0(F(int, 0x1077), d_1b6f38, -1, -1);
    f_10a830(F(int, 0x1077), &lw, &lh, &lc);
    yy = (200 - lh) / 2;
    xx = (320 - lw) / 2;
    { char * t_ = (char *)(d_1a34e0); f_1481a0(d_1bdbd4, t_, xx - 1, yy - 1, lw + 2, lh + 2, -21); }
    f_1481a0(d_1bdbd4, d_1a34e0, xx - 2, yy - 2, lw + 4, lh + 4, -21);
    d_1bd928 = 1;
}
//@ f_0701d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beendet die Kampfoberfläche am Ende eines Kampfes: Wartet auf den nächstenAnimationsschritt
 *   (f_10af40), gibt je nach flag den Sieg- oder Niederlagetext (d_1b6f42 bzw. d_1b6f4f) im Kampftextfenster
 *   F(int, 0x1077) aus, räumt über f_07b7e0 auf, gibt sämtliche allozierten UI- und Heldenporträt-Puffer
 *   (XF(0x121..0x141), XA(0xe9), XA(0x105)) wieder frei und blendet den Bildschirm aus (f_09a140/f_09a0d0).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax, char *) und das Ausgangsflag flag (edx,
 *   short); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd928 wird während des Abbaus auf 2 und am Ende auf 0 gesetzt.
 === Ende Beschreibung === */
void f_0701d0(char *p1, short flag)
{
    unsigned char b;
    short i, i2;
    int cur;
    b = f_10af40(F(int, 0x1077)) + 1;
    while (f_10af40(F(int, 0x1077)) < b) f_077400(p1);
    f_10ac80(F(int, 0x1077));
    f_10aad0(F(int, 0x1077), flag ? d_1b6f42 : d_1b6f4f, -1, -1);
    f_10ae20(F(int, 0x1077), 1, 0);
    f_10ac80(F(int, 0x1077));
    f_0d26e0();
    d_1bd928 = 2;
    f_07b7e0(p1);
    f_0d4730(0x32);
    delete XF(0x12d); XF(0x12d) = 0;
    delete XF(0x129); XF(0x129) = 0;
    delete XF(0x125); XF(0x125) = 0;
    delete XF(0x121); XF(0x121) = 0;
    cur = f_038c80(d_1c0004);
    i = 0;
    do {
        delete XA(0xe9, i); XA(0xe9, i) = 0;
        delete XA(0x105, i); XA(0x105, i) = 0;
        cur = f_0391b0(d_1c0004, cur);
        i++;
    } while (cur != f_038c80(d_1c0004));
    delete XF(0x141); XF(0x141) = 0;
    delete XF(0x13d); XF(0x13d) = 0;
    delete XF(0x139); XF(0x139) = 0;
    delete XF(0x135); XF(0x135) = 0;
    delete XF(0x131); XF(0x131) = 0;
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_099ef0(F(void *, 0x10), 0, 0x100);
    d_1bd928 = 0;
}
//@ f_070440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut nach einem Kampfbildschirm-Wechsel (z. B. Rückkehr aus dem Automap- oder Options-Overlay
 *   während des Kampfes) die Figuren-Sprites auf dem Kampffeld neu auf: Löscht zunächst die temporären UI- und
 *   Sprite-Listen (XF, XA, SL[0..29], d_1bd93c[0..9]), durchläuft anschließend die verkettete Kampfraster-Liste
 *   ab *(Item )(p1 + 0x39) bis d_1c2ecc, legt für jedes sichtbare Monster (c->t == 1), jeden Helden (c->t == 2)
 *   und jedes Hindernis/Objekt (c->t == 0, Sprite 0xda in 0x1000b) ein neues Y-Kampfsprite in SL an und zeichnet
 *   das Kampffeld über f_0757f0(p1) neu.
 * - Eingaben und Rückgabe: Eingabe ist der Kampfsystem-Zeiger p1 (eax, char *); kein Rückgabewert (void).
 * - Wichtige Variablen: SL (p1 + 0x211) und der Zähler F(signed char, 0x291) verwalten die bis zu 30 aktiven
 *   Kampffeld-Sprites.
 === Ende Beschreibung === */
void f_070440(char *p1)
{
    short i, i2;
    int cur;
    Item *c;
    char *e;
    int k;
    d_1bd928 = 2;
    delete XF(0x12d);
    XF(0x12d) = 0;
    delete XF(0x129);
    XF(0x129) = 0;
    delete XF(0x125);
    XF(0x125) = 0;
    delete XF(0x121);
    XF(0x121) = 0;
    cur = f_038c80(d_1c0004);
    i = 0;
    do {
        delete XA(0xe9, i);
        XA(0xe9, i) = 0;
        delete XA(0x105, i);
        XA(0x105, i) = 0;
        cur = f_0391b0(d_1c0004, cur);
        i++;
    } while (cur != f_038c80(d_1c0004));
    delete XF(0x141);
    XF(0x141) = 0;
    delete XF(0x13d);
    XF(0x13d) = 0;
    delete XF(0x139);
    XF(0x139) = 0;
    delete XF(0x135);
    XF(0x135) = 0;
    delete XF(0x131);
    XF(0x131) = 0;
    for (i = 0; i < (short)30; i++) {
        if (SL[i] != 0) {
            delete SL[i];
            SL[i] = 0;
        }
    }
    F(char, 0x291) = 0;
    { short rt = i; i = rt; } // Codeloser Roundtrip fuer die Registerfolge
    for (i2 = 0; i2 < (short)10; i2++) {
        if (d_1bd93c[i2] != 0) {
            delete d_1bd93c[i2];
            d_1bd93c[i2] = 0;
        }
    }
    c = F039(p1 + 0x39);
    e = p1 + 0x45;
    { char *rt = e; e = rt; } // Codeloser Roundtrip fuer die Registerfolge
    e = (char *)(((int)e & 0) ? 0 : (int)e); // Haelt e als eigenes Web fuer die Registervergabe
    do {
        if (c->flag == (signed char)0) {
            if (c->t == 1 || c->t == 2 || (c->t == 0 && c->y != 0)) {
                if (c->t == 1) {
                    if (c->d == (unsigned char)0xff || c->d <= 0x14) {
                        int r = f_0d0ac0(c->b9);
                        Y *o = new (mark(d_1a1be0, 0x16c)) Y(e, 1);
                        c->y = (SL[F(signed char, 0x291)++] = o);
                        f_06f5c0(p1, r, e);
                    }
                } else if (c->t == 0) {
                    Y *o = new (mark(d_1a1be0, 0x173)) Y(e, 1);
                    k = F(signed char, 0x291)++;
                    SL[k] = o;
                    c->y = o;
                    memset(e, 0, 0xa4);
                    F(int, 0x45) = 0x1000b;
                    F(char, 0x51) = 0xda;
                    F(char, 0x52) = 3;
                    F(char, 0x53) = 0xff;
                    F(char, 0x55) = 0xff;
                    f_069a00(c->y, e);
                    f_06a600(c->y, 0xf);
                } else {
                    int r = f_072810(d_1c0004, c->b9);
                    Y *o = new (mark(d_1a1be0, 0x184)) Y(e, 1);
                    c->y = (SL[F(signed char, 0x291)++] = o);
                    f_06ed10(p1, r, e);
                }
            }
        }
        c = c->next;
    } while (c != d_1c2ecc);
    f_07e930(p1 + 0x39);
    f_07e8e0(p1 + 0x39);
    f_09c780(d_1c2d1c);
    f_10ac80(F(int, 0x1077));
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_099ef0(F(void *, 0x10), 0, 0x100);
    d_1bd928 = 0;
    d_1bd910 = 1;
    d_1bda54 = 1;
    f_0757f0(p1);
}
//@ f_0708f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Reserviert im 10-Elemente-Pool d_1bd93c[0..9] ein neues temporäres Effekt-/Projektil-Sprite
 *   (Y, initialisiert mit einem genullten 0xa4-Byte-Block); sind alle 10 Plätze belegt (i == 9), wird der erste
 *   Slot d_1bd93c[0] freigegeben und neu belegt.
 * - Eingaben und Rückgabe: Keine verwendeten Parameter; zurückgegeben wird der Zeiger auf das neu angelegte
 *   Effekt-Sprite Y * (eax).
 * - Wichtige Variablen: Das globale Array d_1bd93c[0..9] verwaltet bis zu zehn gleichzeitige Geschoss- oder
 *   Zaubereffekt-Sprites im Kampf.
 === Ende Beschreibung === */
Y *f_0708f0()
{
    char buf[0xa4];
    short i;
    memset(buf, 0, 0xa4);
    for (i = 0; i < (short)10; i++) {
        if (d_1bd93c[i] == 0) {
            d_1bd93c[i] = new (mark(d_1a1be0, 0x1b0)) Y(buf, 0);
            break;
        } else if (i == 9) {
            i = 0;
            delete d_1bd93c[i];
            d_1bd93c[i] = 0;
            d_1bd93c[i] = new (mark(d_1a1be0, 0x1b7)) Y(buf, 0);
            break;
        }
    }
    return d_1bd93c[i];
}

extern int d_1a1c00;
extern char d_1c2edc;
void n630_stop(void *,int);
#pragma aux n630_stop "f_147c02";
int n630_start(void *,int,void (*)());
#pragma aux n630_start "f_147b97";
void f_0a71c0();
//@ f_06fad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stoppt den periodischen Kampftimer-Callback d_1a1c00 im Sound-/Timersystem d_1c2edc über
 *   f_147c02 und setzt das Handle d_1a1c00 auf -1 zurück.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1a1c00 speichert das aktive Timer-Handle (-1 = inaktiv).
 === Ende Beschreibung === */
void f_06fad0() { if (d_1a1c00 != -1) { n630_stop(&d_1c2edc,d_1a1c00); d_1a1c00=-1; } }
//@ f_06fb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet im Timersystem d_1c2edc über f_147b97 einen periodischen Timer (Intervall 100) mit der
 *   Callback-Funktion f_0a71c0 und speichert dessen Handle in d_1a1c00.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1a1c00 hält das registrierte Timer-Handle.
 === Ende Beschreibung === */
void f_06fb00() { d_1a1c00=n630_start(&d_1c2edc,100,f_0a71c0); }
