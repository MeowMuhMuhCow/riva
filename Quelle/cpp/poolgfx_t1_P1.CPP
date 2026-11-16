/* === Beschreibung (Katalog) ===
 * Einheit poolgfx_t1
 *
 * Diese Einheit (aus p:\riva\source\cpp\poolgfx.cpp, Teil 1) implementiert die grafische Darstellung des
 * Handels-, Beute- und Lagerpools. Sie verwaltet die Maushotspots des Pool-Fensters, zeichnet das
 * 4x5-Kachelraster samt Gegenstandssymbolen, Stückzahlen, Preisen und Gewichten und stellt den Kopfbereich sowie
 * die Gegenstandsbeschreibung am unteren Fensterrand dar.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 7/13 gleich (suche.py 28.10.2026, Basis poolgfx_t1_P1.CPP)
// poolgfx.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E06F0-0x0E1AB0 (t1)
#include <string.h>
#pragma inline_depth(0)
struct Spr9 { char b[9]; };
struct S163 { char b[0xa3]; };
struct Rec { short s0, s2, s4, s6; unsigned short s8; short sa, sc, se, s10, s12; int i14; };
struct H { short s0; short p2; short s4; char p6[6]; Rec *recs; char p10[2]; unsigned u12; char p16[4]; short s1a; char p1c[2]; int i1e; };
struct P { H *h; int x4; int cur; char *buf; };

int f_04fef0(void *t, int id, int a, int b, int c, int d, int e);
void f_050580(void *t, int id, int n, int *c, int *b);
int f_05dec0(void *t);
void f_05ded0(void *t, int v);
void f_05e320(void *t, int c, int m);
void f_05e340(void *t);
void f_040370(char *b, unsigned v);
void f_09a120(int a, int b);
void f_09a140(int a, int b);
void f_09a400();
void f_09a4c0(char *a, int b);
char f_09a040(unsigned char c);
void f_0a7840(RivaItemDefinition *item,char *dst,short n);



void f_0bc1e0(void *t, int v);
void f_0bc3a0(void *t);
void f_0bc6c0(void *t, int a, int b);
void f_0bc8d0(void *t, int a);
void f_0bcae0(void *t, int a);
int f_0d26e0();
int f_0d2710();
int f_0d3770();
int f_0d3860();
int f_0d3870();
void f_0daba0(int a, int b);
int f_0dc020(int a, int b);
int f_0dca30(int a, int b);
int f_0de7e0(int p1);
int f_0e9300(void *t, char *s, int id);
int f_0e9510(void *t, int id, int x, int y);
int f_0e9590(void *t, int id);
int f_0e9660(void *t, char *s, int x, int y);
int f_0e9690(void *t, char *s);
int f_133fe0(void *t, char *s, int id);
int f_133fe0(void *t, char *s);
int f_133fe0(void *t, char *s, int id, int c);
void *f_145300(void *p, int c, unsigned n);
char *f_148518(int v, char *b, int r);
S163 *f_1459b0(S163 *o);
void *f_1459d0(S163 *o, int z);
int f_145a10(S163 *o, int id, int cur);
int f_145b80(S163 *o, int id, int *a, int *b);
Spr9 *f_0fac80(Spr9 *o, int w, int h);





extern int d_1a34e0;
extern int d_1a63e4;
extern volatile int d_1a64b8;
extern short d_1bb558;
extern int d_1bb55a;
extern short d_1bd766;
extern int d_1bf514;
extern volatile short d_1bf51c;
extern volatile int d_1bf520;
extern int d_1bf524;
extern int d_1bfdb8;
extern int d_1c0004;
extern int d_1bdbe4;
extern int d_1c0038;
extern int d_1c003c;
extern short d_1c0040;
extern short d_1c0042;
extern short d_1c0044;

extern char d_1bf230[];
extern char d_1c0e60[];
extern char d_1c21b4[];
extern char d_1c21f4[];
extern char d_1c2234[];
extern char d_1c2274[];
extern char d_1c27a8[];
extern char d_1c2be0[];
extern char d_1c3068[];
extern char d_1c3498[];
extern char d_1c38b0[];
extern char d_1b82d0[];
extern char d_1b82d3[];
extern const char d_1a63c4[];
void f_0e06a0();
void f_0e07a0(P *p1, short p2, short p3);
int f_0e08e0(P *p1, int p2);
void f_0e0a30(P *p1, short p2, int p3);
void f_0e0be0(P *p1);
void f_0e1040(P *p1, short p2);
void f_0e1600(P *p1);
void f_0e1850(P *p1);
void f_0e1ab0(P *p1);
void f_0e1d10(P *p1);
void f_0e1f80(P *p1);
void f_0e2160(P *p1);
void f_0e2340(P *p1);
struct MG {
    int fl;
    MG()
    { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; } }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
//@ f_0e06f0
/* === Beschreibung (Katalog) ===
 * Aktiviert die Maussteuerung für das Pool-Fenster, indem die bisherigen Hotspot-Tabellen und Maus-Callbacks in
 * globalen Sicherungsvariablen (d_1c0038, d_1c003c, d_1c0040) abgelegt und durch die Hotspot-Liste des Pools
 * (d_1a63e4 / d_1a64b8) sowie den Rückruf f_0e06a0 ersetzt werden.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e06f0()
{
    d_1bd766 = 0;
    d_1bf514 = (int)&d_1a63e4;
    d_1c0038 = d_1bf520;
    d_1c003c = d_1bf524;
    d_1c0040 = d_1bf51c;
    d_1c0042 = 1;
    d_1c0044 = 1;
    d_1bf520 = d_1a64b8;
    d_1bf524 = (int)f_0e06a0;
    d_1bf51c = 1;
}
//@ f_0e0760
/* === Beschreibung (Katalog) ===
 * Beendet die Maussteuerung des Pool-Fensters, wartet auf das Loslassen der Maustasten (f_0d3870, f_0d3770) und
 * stellt die zuvor gesicherten Hotspot-Tabellen und Maus-Callbacks (d_1c0038, d_1c003c, d_1c0040) wieder her.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0760()
{
    f_0d3870();
    f_0d3770();
    f_0d3770();
    d_1bf51c = 0;
    d_1bf520 = d_1c0038;
    d_1bf524 = d_1c003c;
    d_1bf51c = d_1c0040;
}
//@ f_0e07a0
/* === Beschreibung (Katalog) ===
 * Zeichnet den Auswahlrahmen (Sprite 0x22005d, Teilbild 1 oder 2 je nach Markierungsmodus p3) um das Kachelfeld
 * p2 im 4x5-Raster des Pool-Fensters (p1).
 * - Eingaben: Übergeben werden der Zeiger auf das Pool-Grafikobjekt p1, der nullbasierte Kachelindex p2 (0..19)
 *   sowie der Darstellungsmodus p3 (1 für den aktiven Auswahlrahmen, sonst 2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e07a0(P *p1, short p2, short p3)
{
    int codex_arg_1_160;
    volatile int flag;
    short A = 2;
    short sy = 0x1a;
    short c = 0;
    short b = 0;
    short n = (p3 == (short)1) ? 1 : 2;
    d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0; // haelt die Registerzuteilung wie im Original
    d_1a63e4 = (d_1a63e4 & 0) ? 0 : d_1a63e4; // haelt die Registerzuteilung wie im Original
    d_1bb55a = (d_1bb55a & 0) ? 0 : d_1bb55a; // haelt die Registerzuteilung wie im Original
    d_1bfdb8 = (d_1bfdb8 & 0) ? 0 : d_1bfdb8; // haelt die Registerzuteilung wie im Original
    { short vrs = d_1c0040; d_1c0040 = vrs; } // haelt die Registerzuteilung wie im Original
    { int vri = d_1c0004; d_1c0004 = vri; } // haelt die Registerzuteilung wie im Original
    A += (p2 / d_1bb558) * 60;
    sy = (p2 % d_1bb558) * 0x16 + sy;
    f_050580(d_1c2be0, 0x22005d, n, (int *)&c, (int *)&b);
    Spr9 *s = new (mark(d_1a63c4, 0x184)) Spr9;
    s = s ? f_0fac80(s, c, b) : s;
    f_04fef0(d_1c2be0, 0x22005d, ((int)(((RivaRasterImage*)(s))->f_0fb0b0())), 0, n, 0, 0x140);
    if (f_0d3860() == 1) {
        int k = 1;
        f_0d2710();
        flag = k;
    } else flag = 0;
    ((RivaRasterImage*)(s))->f_0fae30((void *)( (codex_arg_1_160 = p1->cur)), A, sy, 1);
    if (s) operator delete(((void *)(((RivaRasterImage*)(s))->f_0fad20( 0))));
    if (flag == (short)1) f_0d26e0();
}
//@ f_0e08e0
/* === Beschreibung (Katalog) ===
 * Aktualisiert bei Auswahl der Kachel p2 im Pool-Fenster (p1) die Helden-Porträtleiste (d_1bf230): Im Verkaufs-
 * oder Lager-Modus (i1e == 0) wird das Porträt des Helden, dem der Gegenstand gehört (recs[idx].i14), farblich
 * hervorgehoben (0xfd für im Rucksack getragene, 0xfb für am Körper angelegte Gegenstände), während im
 * Kauf-Modus geprüft wird, ob mindestens ein Gruppenmitglied den Gegenstand verwenden kann (f_0dca30).
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1 sowie die einsbasierte Kachelnummer p2
 *   (1..20).
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Gegenstand verfügbar bzw. nutzbar ist, oder 0, falls kein
 *   Gruppenmitglied den ausgewählten Kaufgegenstand tragen kann.
 === Ende Beschreibung === */
int f_0e08e0(P *p1, int p2)
{
    H *h = p1->h;
    short idx = h->s1a * d_1bb558 + p2 - 1;
    short s2 = h->recs[idx].s2;
    int n = s2;
    int ret = 1;
    if (n > 0) {
        if (p1->h->i1e == 0) {
            int a = p1->h->recs[idx].i14;
            int v;
            if (p1->x4 == 0) p1->x4 = a;
            v = f_042400((struct hero *)(p1->x4)) == 0 ? f_0dc020(d_1c0004, p1->x4) : 6;
            if (a != p1->x4) {
                if (p1->x4 != 0)
                    f_0bc8d0(d_1bf230, (short)v);
                p1->x4 = a;
            }
            v = f_042400((struct hero *)(p1->x4)) == 0 ? f_0dc020(d_1c0004, p1->x4) : 6;
            a = idx;
            if (p1->h->recs[a].s12 < 0xf)
                f_0bc6c0(d_1bf230, (short)v, 0xfd);
            else
                f_0bc6c0(d_1bf230, (short)v, 0xfb);
        } else {
            ret = f_0dca30(d_1c0004, n);
        }
    } else {
        p1->x4 = 0;
        f_145300(d_1c0e60, 0, 0x1c);
        f_0bc3a0(d_1bf230);
    }
    return ret;
}


//@ f_0e0a30
/* === Beschreibung (Katalog) ===
 * Gibt den vollständigen Namen des in Kachel p2 liegenden Gegenstands (bei gestapelten Magiegegenständen ergänzt
 * um die Ladungsanzahl in Klammern) in der Statuszeile am unteren Bildschirmrand (d_1bf230) aus, wobei die
 * Textfarbe je nach Nutzbarkeit (p3 == 1) weiß (0xff) oder ausgegraut (0xcb) gewählt wird.
 * - Eingaben: Übergeben werden das Pool-Grafikobjekt p1, die einsbasierte Kachelnummer p2 sowie das
 *   Nutzbarkeitsflag p3 (1 für normal hervorgehoben, sonst abgedunkelt).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0a30(P *p1, short p2, int p3)
{
    H *h = p1->h;
    short idx = h->s1a * d_1bb558 + p2 - 1;
    short s2 = h->recs[idx].s2;
    signed char col;
    if (p3 == 1) col = 0xff;
    else col = 0xcb;
    short color = (unsigned char)col;
    int n = s2;
    if (n > 0) {
        short ln;
        f_145300(d_1c21b4, 0, 0x5f4);
        f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[n]),(char *)( d_1c21b4), 1);
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[n]))->f_0a7990() == 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[n]))->f_0a7950() == 0) {
            ln = strlen(d_1c21b4);
            d_1c21b4[ln] = f_09a040(0xe7);
            strcat(d_1c21b4, d_1b82d0);
            f_0e9300(d_1c38b0, d_1c21b4, 0x2000005c + ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[n]))->f_0a78b0())));
            strcat(d_1c21b4, d_1b82d3);
            ln = strlen(d_1c21b4);
            d_1c21b4[ln] = f_09a040(0xff);
        }
        f_0bcae0(d_1bf230, f_133fe0(d_1c3498, d_1c21b4, color, p1->cur));
    } else {
        f_0bc1e0(d_1bf230, p1->cur);
    }
}
//@ f_0e0be0
/* === Beschreibung (Katalog) ===
 * Baut das gesamte Pool-Fenster (p1) im Grafikpuffer neu auf: Sie lädt das Hintergrundbild (0x22005c), schreibt
 * die zentrierte Überschrift (s0 + 0x220101b2), zeichnet die Schaltflächen (f_0daba0), stellt alle 20
 * Gegenstandskacheln (f_0e1040) sowie die Kopfzeilen-Statuswerte (f_0e1600) dar und hebt die aktuell ausgewählte
 * Kachel (d_1c0044) samt Heldenmarkierung und Namenszeile hervor.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0be0(P *p1)
{
    short n = d_1bb558 * d_1bb55a;
    int own = 0;
    int saved;
    if (p1->buf == 0) {
        own = 1; p1->buf = new (mark(d_1a63c4, 0x231)) char[64000];
    }
    p1->cur = (int)p1->buf;
    {
    volatile int flag;
    if (f_0d3860() == 1) {
        f_0d2710();
        flag = 1;
    } else {
        flag = 0;
    }
    register P *pp = p1;
    S163 *t = (S163 *)operator new(0xa3, mark(d_1a63c4, 0x299));
    S163 *q = t ? f_1459b0(t) : t;
    f_145a10(q, 0x22005c, pp->cur);
    if (q) operator delete(f_1459d0(q, 0));
    int s = p1->h->s0;
    saved = f_05dec0(d_1c3068);
    f_05ded0(d_1c3068, p1->cur);
    int id = s + 0x220101b2;
    short w = f_0e9590(d_1c38b0, id);
    short x = (0x50 - w) / 2 + 0xf2;
    f_05e320(d_1c38b0, 0xff, -1);
    f_0e9510(d_1c38b0, id, (short)x, 0x25);
    f_05e340(d_1c38b0);
    f_05ded0(d_1c3068, saved);
    f_0daba0(d_1bfdb8, p1->cur);
    int i = 0;
    if (n > (short)0) {
        do {
            short t = i;
            i++;
            f_0e1040(p1, t);
        } while ((short)i < n);
    }
    f_0e1600(p1);
    f_0e07a0(p1, d_1c0044 - 1, 1);
    int rr = f_0e08e0(p1, d_1c0044);
    f_0e0a30(p1, d_1c0044, rr);
    if (flag == 1) f_0d26e0();
    }
    p1->cur = d_1a34e0;
    if (own == 1) {
        operator delete(p1->buf);
        p1->buf = 0;
    }
}
//@ f_0e0dc0
/* === Beschreibung (Katalog) ===
 * Rendert das Pool-Fenster (p1) zunächst in einen temporären 64000-Byte-Hintergrundpuffer (f_0e0be0) und
 * überträgt es anschließend gemäß dem Überblendmodus p2 auf den sichtbaren Bildschirm (d_1a34e0) - entweder mit
 * Überblendeffekt (p2 == 0), mit Aus- und Einblenden der Palette (p2 == 1) oder durch direktes Kopieren (p2 ==
 * 2).
 * - Eingaben: Übergeben werden das Pool-Grafikobjekt p1 sowie der Überblendmodus p2 (0, 1 oder 2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0dc0(P *p1, unsigned short p2)
{
    volatile int fl;
    int b;
    int a;
    int sz = 0;
    a = 0;
    d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0; // haelt die Registerzuteilung wie im Original
    a = 0;
    b = 0;
    S163 *t = new (mark(d_1a63c4, 0x25c)) S163;
    S163 *q = t ? f_1459b0(t) : t;
    f_145b80(q, 0x22005c, &a, &b);
    if (q) operator delete(f_1459d0(q, 0));
    sz = a * b;
    p1->buf = new (mark(d_1a63c4, 0x272)) char[64000];
    f_0e0be0(p1);
    if (f_0d3860() == 1) {
        f_0d2710();
        fl = 1;
    } else {
        fl = 0;
    }
    switch (p2) {
    case 0:
        memcpy(p1->buf + (unsigned short)sz, (char *)d_1a34e0 + (unsigned short)sz, 64000 - (unsigned short)sz);
        f_09a4c0(p1->buf, 1);
        break;
    case 1:
        f_09a140(0, 0x19);
        f_09a400();
        memcpy((char *)d_1a34e0, p1->buf, (unsigned short)sz);
        f_09a120(d_1bdbe4, 0x19);
        break;
    case 2:
        memcpy((char *)d_1a34e0, p1->buf, (unsigned short)sz);
        break;
    }
    operator delete(p1->buf);
    p1->buf = 0;
    if (fl == 1) f_0d26e0();
}
//@ f_0e0f50
/* === Beschreibung (Katalog) ===
 * Lädt das Hintergrundbild des Pool-Fensters (Ressourcenkennung 0x22005c) über ein temporäres
 * Bild-Decoder-Objekt (f_1459b0 / f_145a10) in den aktuellen Zielpuffer (p1->cur).
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0f50(P *p1)
{
    S163 *t = (S163 *)operator new(0xa3, mark(d_1a63c4, 0x299));
    S163 *q = t ? f_1459b0(t) : t;
    f_145a10(q, 0x22005c, p1->cur);
    if (q) operator delete(f_1459d0(q, 0));
}
//@ f_0e0fa0
/* === Beschreibung (Katalog) ===
 * Gibt den Titel des aktuellen Pool- oder Händlerfensters (Textkennung p1->h->s0 + 0x220101b2) horizontal
 * zentriert im rechten Kopfbereich (um X-Position 0xf2, Breite 0x50, Y-Position 0x25) in weißer Schrift (0xff)
 * aus.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0fa0(P *p1)
{
    int s = p1->h->s0;
    int saved = f_05dec0(d_1c3068);
    f_05ded0(d_1c3068, p1->cur);
    int id = s + 0x220101b2;
    short w = f_0e9590(d_1c38b0, id);
    short x = (0x50 - w) / 2 + 0xf2;
    f_05e320(d_1c38b0, 0xff, -1);
    f_0e9510(d_1c38b0, id, (short)x, 0x25);
    f_05e340(d_1c38b0);
    f_05ded0(d_1c3068, saved);
}
//@ f_0e1040
/* === Beschreibung (Katalog) ===
 * Zeichnet den Inhalt einer einzelnen Gegenstandskachel p2 im 4x5-Raster des Pool-Fensters (p1), einschließlich
 * des 16x16-Gegenstands-Icons (0x50002), der vorhandenen Stückzahl (s0, weiß), der zum Kauf/Verkauf ausgewählten
 * Menge (s10, gelb/rot), des Preises samt Währungseinheit (s6 und s8: Heller, Silbertaler oder Dukaten) sowie
 * des Gewichts in Unzen (sa).
 * - Eingaben: Übergeben werden das Pool-Grafikobjekt p1 sowie der nullbasierte Kachelindex p2 (0..19).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
char *riva_148518(int v, char *b, int r);
#pragma aux riva_148518 "f_148518" parm [eax] [edx] [ebx] value [eax] modify [eax ebx ecx edx];
void f_0e1040(P *p1, short p2)
{
    short idx = p1->h->s1a * d_1bb558 + p2;
    short a = (p2 / d_1bb558) * 60;
    short A;
    short R = (p2 % d_1bb558) * 0x16;
    A = a + 2;
    short B = R + 0x1a;
    volatile int flag;
    int saved;

    saved = 0;
    saved = f_05dec0(d_1c3068);
    f_05ded0(d_1c3068, p1->cur);
    if (p1->h->recs[idx].s2 > 0) {
        Spr9 *s = new (mark(d_1a63c4, 0x2dc)) Spr9;
        s = s ? f_0fac80(s, 0x10, 0x10) : s;
        f_145300(d_1c21b4, 0, 0x100);
        riva_148518(p1->h->recs[idx].s0, d_1c21b4, 0xa);
        riva_148518(p1->h->recs[idx].s10, d_1c21f4, 0xa);
        riva_148518(p1->h->recs[idx].s6, d_1c2234, 0xa);
        riva_148518(p1->h->recs[idx].sa, d_1c2274, 0xa);
        if (f_0d3860() == 1) {
            f_0d2710();
            flag = 1;
        } else flag = 0;
        f_04fef0(d_1c2be0, 0x50002, ((int)(((RivaRasterImage*)(s))->f_0fb0b0())), 0, (short)p1->h->recs[idx].s4, 0, 0x140);
        ((RivaRasterImage*)(s))->f_0fade0((void *)( p1->cur), (short)(A + 2), (short)(B + 2));
        if (s) operator delete(((void *)(((RivaRasterImage*)(s))->f_0fad20( 0))));
        if (p1->h->recs[idx].s0 > 1) {
            short x1 = B + 1;
            short t = 0x14 - f_0e9690(d_1c38b0, d_1c21b4) + A;
            f_05e320(d_1c38b0, 0xfe, -1);
            f_0e9660(d_1c38b0, d_1c21b4, t, x1);
            f_05e340(d_1c38b0);
            t--;
            f_05e320(d_1c38b0, 0xff, -1);
            f_0e9660(d_1c38b0, d_1c21b4, t, x1);
            f_05e340(d_1c38b0);
        }
        if (p1->h->recs[idx].s10 > 0) {
            short x2 = B + 0xb;
            short t = 0x14 - f_0e9690(d_1c38b0, d_1c21f4) + A;
            f_05e320(d_1c38b0, 0xfe, -1);
            f_0e9660(d_1c38b0, d_1c21f4, t, x2);
            f_05e340(d_1c38b0);
            t--;
            f_05e320(d_1c38b0, 0xfc, -1);
            f_0e9660(d_1c38b0, d_1c21f4, t, x2);
            f_05e340(d_1c38b0);
        }
        short t = 0x38 - f_0e9690(d_1c38b0, d_1c2234);
        f_05e320(d_1c38b0, 0xcb, -1);
        f_0e9660(d_1c38b0, d_1c2234, (short)(a + t), (short)(R + 0x1c));
        switch (p1->h->recs[idx].s8) {
        case 1:
            f_0e9510(d_1c38b0, 0x220101a5, (short)(a + 0x18), (short)(R + 0x1c));
            break;
        case 0xa:
            f_0e9510(d_1c38b0, 0x220101a6, (short)(a + 0x18), (short)(R + 0x1c));
            break;
        case 0x64:
            f_0e9510(d_1c38b0, 0x220101a7, (short)(a + 0x18), (short)(R + 0x1c));
            break;
        }
        {
        short t = 0x38 - f_0e9690(d_1c38b0, d_1c2274);
        f_0e9660(d_1c38b0, d_1c2274, (short)(a + t), (short)(R + 0x24));
        f_0e9510(d_1c38b0, 0x220101a8, (short)(a + 0x18), (short)(R + 0x24));
        }
        f_05e340(d_1c38b0);
        if (flag == 1) f_0d26e0();
    }
    f_05ded0(d_1c3068, saved);
}
//@ f_0e14e0
/* === Beschreibung (Katalog) ===
 * Löscht den Hintergrund einer einzelnen Kachel p2 im Pool-Fenster (p1), indem das leere Kachel-Sprite
 * (0x22005d, Teilbild 0) an die entsprechende Rasterposition gezeichnet wird, und ruft anschließend f_0e1040
 * auf, um den Gegenstand samt Beschriftung neu einzutragen.
 * - Eingaben: Übergeben werden das Pool-Grafikobjekt p1 sowie der nullbasierte Kachelindex p2 (0..19).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e14e0(P *p1, short p2)
{
    short A, B;
    short b, c;
    volatile int g;
    A = (p2 / d_1bb558) * 60 + 2;
    B = (p2 % d_1bb558) * 0x16 + 0x1a;
    c = 0;
    b = 0;
    f_050580(d_1c2be0, 0x22005d, 0, (int *)&c, (int *)&b);
    Spr9 *s = new (mark(d_1a63c4, 0x33d)) Spr9;
    s = s ? f_0fac80(s, c, b) : s;
    f_04fef0(d_1c2be0, 0x22005d, ((int)(((RivaRasterImage*)(s))->f_0fb0b0())), 0, 0, 0, 0x140);
    if (f_0d3860() == 1) {
        int k = 1;
        f_0d2710();
        g = k;
    } else {
        g = 0;
    }
    ((RivaRasterImage*)(s))->f_0fade0((void *)( p1->cur), (short)A, (short)B);
    if (g == 1) f_0d26e0();
    if (s) operator delete(((void *)(((RivaRasterImage*)(s))->f_0fad20( 0))));
    f_0e1040(p1, p2);
}
//@ f_0e1600
/* === Beschreibung (Katalog) ===
 * Aktualisiert die drei Statusfelder im oberen Kopfbereich des Pool-Fensters (p1) - je nach Modus (p1->h->s4 !=
 * 0 für Kauf/Handel über f_0e1850, f_0e1ab0, f_0e1d10 oder s4 == 0 für Verkauf/Beutelager über f_0e1f80,
 * f_0e2160, f_0e2340) - und kopiert bei direktem Bildschirmzeichnen die drei Teilbereiche flackerfrei in den
 * Bildschirmpuffer (d_1a34e0).
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e1600(P *p1)
{
    int saved = f_05dec0(d_1c3068);
    int own = 0;
    if (p1->buf == 0) {
        p1->buf = new (mark(d_1a63c4, 0x369)) char[64000];
        own = 1;
        p1->cur = (int)p1->buf;
    }
    f_05ded0(d_1c3068, p1->cur);
    if (p1->h->s4 != 0) {
        f_0e1850(p1);
        f_0e1ab0(p1);
        f_0e1d10(p1);
    } else {
        f_0e1f80(p1);
        f_0e2160(p1);
        f_0e2340(p1);
    }
    if (own == 1) {
        Spr9 *t = new (mark(d_1a63c4, 0x380)) Spr9;
        Spr9 *a = t ? f_0fac80(t, 0xe7, 8) : t;
        t = new (mark(d_1a63c4, 0x381)) Spr9;
        Spr9 *b = t ? f_0fac80(t, 0x6f, 8) : t;
        t = new (mark(d_1a63c4, 0x382)) Spr9;
        Spr9 *c = t ? f_0fac80(t, 0x6f, 8) : t;
        ((RivaRasterImage*)(a))->f_0fafb0((void *)( p1->cur), 5, 3);
        ((RivaRasterImage*)(b))->f_0fafb0((void *)( p1->cur), 5, 0xf);
        ((RivaRasterImage*)(c))->f_0fafb0((void *)( p1->cur), 0x7d, 0xf);
        volatile int lock;
        if (f_0d3860() == 1) {
            int k = 1;
            f_0d2710();
            lock = k;
        } else lock = 0;
        ((RivaRasterImage*)(a))->f_0fade0((void *)( d_1a34e0), 5, 3);
        ((RivaRasterImage*)(b))->f_0fade0((void *)( d_1a34e0), 5, 0xf);
        ((RivaRasterImage*)(c))->f_0fade0((void *)( d_1a34e0), 0x7d, 0xf);
        if (lock == 1) f_0d26e0();
        if (a) operator delete(((void *)(((RivaRasterImage*)(a))->f_0fad20( 0))));
        if (b) operator delete(((void *)(((RivaRasterImage*)(b))->f_0fad20( 0))));
        if (c) operator delete(((void *)(((RivaRasterImage*)(c))->f_0fad20( 0))));
        operator delete(p1->buf);
        p1->buf = 0;
        p1->cur = d_1a34e0;
    }
    f_05ded0(d_1c3068, saved);
}
//@ f_0e1850
/* === Beschreibung (Katalog) ===
 * Zeichnet im Kauf-Modus das obere Statusfeld (Position 5, 3, Hintergrundsprite 0x22005d Index 3) für den
 * Gesamtpreis der ausgewählten Waren (p1->h->u12) im Verhältnis zum vorhandenen Gruppengeld (f_0de7e0), wobei
 * der Betrag grün (0xfc), gelb (0xf9, ab 80 % des Vermögens) oder rot (0xfd, wenn das Geld nicht reicht)
 * eingefärbt wird.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Pool-Grafikobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e1850(P *p1)
{
    unsigned codex_arg_1_512;
    short a;
    short c;
    short b;
    short f;
    short e;
    short d;
    f = 5;
    a = 3;
    c = 0;
    b = 0;
    e = 0xfc;
    d = 0;
    int n;
    Spr9 *s;
    int id;
    int len;

    n = f_0de7e0(d_1c0004);
    f_050580(d_1c2be0, 0x22005d, 3, (int *)&c, (int *)&b);
    s = new (mark(d_1a63c4, 0x3c4)) Spr9;
    s = s ? f_0fac80(s, c, b) : s;
    f_04fef0(d_1c2be0, 0x22005d, ((int)(((RivaRasterImage*)(s))->f_0fb0b0())), 0, 3, 0, 0x140);
    ((RivaRasterImage*)(s))->f_0fade0((void *)( p1->cur), 5, 3);
    if (s != 0) operator delete(((void *)(((RivaRasterImage*)(s))->f_0fad20( 0))));
    f_05e320(d_1c38b0, 0xff, -1);
    f_0e9510(d_1c38b0, 0x220101aa, (short)f, a);
    f_145300(d_1c21b4, 0, 0x80);
    if (n <= p1->h->u12)
        e = 0xfd;
    else if ((unsigned int)n * 4 / 5 <= p1->h->u12)
        e = 0xf9;
    d_1c21b4[(short)d] = f_09a040(e);
    f_040370(d_1c27a8, (codex_arg_1_512 = p1->h->u12));
    strcat(d_1c21b4, d_1c27a8);
    len = strlen(d_1c21b4);
    d_1c21b4[(short)len] = f_09a040(0xff);
    f_0e9300(d_1c38b0, d_1c21b4, 0x220101a9);
    f_040370(d_1c27a8, f_0de7e0(d_1c0004));
    strcat(d_1c21b4, d_1c27a8);
    id = f_133fe0(d_1c3498, d_1c21b4);
    f += 0xe7 - f_0e9590(d_1c38b0, id);
    f_0e9510(d_1c38b0, id, (short)f, a);
    f_05e340(d_1c38b0);
}
