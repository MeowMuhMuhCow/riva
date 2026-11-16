/* === Beschreibung (Katalog) ===
 * Einheit fz158128 (0x158128 - 0x15B630)
 *
 * Überblick
 * Diese Einheit enthält den kompletten Parser, Tabellen-Layouter und Hauptzeichner des vorkompilierten
 * Hypertext-Formats (RivaTextLayout) von *Schatten über Riva*. Sie berechnet die Ausdehnung gesetzter Textblöcke
 * (f_158128, f_1581c8), liest binär vorcodierte HTML-Tags samt Attributen (f_158258 bis f_158420), setzt
 * mehrspaltige Tabellen (f_15843c), wandelt #RRGGBB-Farbcodes um (f_1590bc), formatiert vollständige Dokumente
 * mit Überschriften, Listen, Bildern und Hyperlinks (f_15928c) und gibt das Dokument verschoben in einem
 * Scroll-Ausschnitt auf dem Bildschirm aus (f_15a78c, f_15ae98).
 === Ende Beschreibung === */
// OPT -5r -onatxc -zp1 -s
// P3 10/22 gleich (suche.py 25.10.2026, Basis fz_15689d_t2_P1.CPP)
// P1 1/19 gleich
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 2 gleich (vorher 2), Rest 5052 (vorher 5053)
// fz_15689d_t2 (Schatten ueber Riva, Attic 1996) - Pass 1, Helfer B, Code 0x158128-0x15B770
// inline_depth(0) entfernt (Blind832): Original inlinet Methoden, aber keine Auto-Inline (-oe weg)
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

//@ f_158128
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt die maximale rechte X-Ausdehnung (x + w) aller Layoutelemente im Vektor p1,
 *   deren vertikaler Bereich den Abschnitt zwischen p2 und p3 schneidet.
 * - Eingaben: Layoutvektor p1 sowie die vertikale Untergrenze p2 und Obergrenze p3.
 * - Rückgabewert: int - größte gefundene rechte X-Koordinate in Pixeln.
 * - Wichtige Variablen:
 *   - best: Bisheriges Maximum aus c.x + c.w.
 === Ende Beschreibung === */
inline RivaLayoutItem vec_get158128(RivaByteVector *v, int i) { return *(RivaLayoutItem *)(v->d + i * 32); }
int f_158128(RivaByteVector *p1, int p2, int p3)
{
    int n;
    int best;
    int i;

    best = 0;
    n = (p1->e - p1->b) / 32;
    for (i = 0; i < n; i++) {
        RivaLayoutItem c = vec_get158128(p1, i);
        if (c.y < p3 && p2 <= HI16(c, 0xc) + c.y && HI16(c, 0xa) + c.x > best)
            best = HI16(c, 0xa) + c.x;
    }
    p2 = (p2 & 0) ? 0 : p2; // haelt die Registerzuteilung wie im Original
    return best;
}


//@ f_1581c8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt die maximale untere Y-Ausdehnung (y + h, also die Gesamthöhe) aller
 *   Layoutelemente im Vektor p1, die im vertikalen Bereich zwischen p2 und p3 liegen.
 * - Eingaben: Layoutvektor p1 sowie der vertikale Prüfbereich p2..p3.
 * - Rückgabewert: unsigned short - größte gefundene untere Y-Koordinate in Pixeln.
 * - Wichtige Variablen:
 *   - best: Bisheriges Maximum aus c.y + c.h.
 === Ende Beschreibung === */
inline RivaLayoutItem vec_get1581c8(RivaByteVector *v, int i) { return *(RivaLayoutItem *)(v->d + i * 32); }
unsigned short f_1581c8(RivaByteVector *p1, int p2, int p3)
{
    RivaLayoutItem c;
    int n;
    int best;
    int i;

    best = 0;
    n = (p1->e - p1->b) / 32;
    i = 0;
    while (i < n) {
        c = vec_get1581c8(p1, i);
        if (c.y < p3 && p2 <= HI16(c, 0xc) + c.y && HI16(c, 0xc) + c.y > best)
            best = HI16(c, 0xc) + c.y;
        i++;
    }
    return best;
}

//@ f_158258
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in einem geparsten Tag-Datensatz p1 (mit *(u8 *)(p1 + 0x50) Attributen) nach dem
 *   Attributschlüssel p2 und gibt dessen Tabellenindex zurück.
 * - Eingaben: Zeiger p1 auf die Tag-Struktur und gesuchte Attribut-Kennung p2.
 * - Rückgabewert: int - Index des gefundenen Attributs (0..n-1) oder -1, falls das Attribut im Tag nicht
 *   angegeben wurde.
 * - Wichtige Variablen:
 *   - i: Laufindex über die im Tag gespeicherten Attribut-Kennbytes (p1 + 0x40).
 === Ende Beschreibung === */
int f_158258(int p1, unsigned p2)
{
    int i = 0;
    int p = p1;
    for (; i < *(u8 *)(p1 + 0x50); p++, i++) {
        if (*(u8 *)(p + 0x40) == p2)
            return i;
    }
    return -1;
}

//@ f_158288
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in einem Tag-Datensatz p1 anhand des Attributnamens p2 (im Klartext, z. B. "HREF",
 *   "SRC", "BORDER") über die zum Tag-Typ (*(u8 *)(p1 + 0x51)) gehörende Attributnamenstabelle d_1aeba8 nach dem
 *   zugehörigen Attributwert-Index.
 * - Eingaben: Tag-Struktur p1 und Attributname p2 als Zeichenkette.
 * - Rückgabewert: int - Index des Attributwerts im Tag-Array (p1->v[idx]) oder -1 bei Nichtfinden.
 * - Wichtige Variablen:
 *   - d_1aeba8: Globale Tabelle der erlaubten Attributnamen je Tag-Typ (bis 0x52).
 *   - idx: Laufende Attributnummer innerhalb der 16-Byte-Einträge von pc.
 === Ende Beschreibung === */
int f_158288(int p1, char *p2)
{
    char *pc;
    char *pn;
    short cc;
    unsigned len1;
    int idx;
    if (*(u8 *)(p1 + 0x51) < 0x53 && (pc = d_1aeba8[*(u8 *)(p1 + 0x51)]) != 0) {
        len1 = strlen(p2);
        idx = 0;
        pn = pc;
        for (; *pn != '0'; pn += 0x10) {
            if (strlen(pn) >= len1 && f_14d717(p2, pn) == 0)
                return f_158258(p1, idx);
            idx++;
        }
    }
    return -1;
}

//@ f_158314
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest ab der aktuellen Textposition *pp (nach einem 0x00-Steuerbyte) einen binär codierten
 *   Hypertext-Tag samt all seinen Attribut-Kennbytes und nullterminierten Attributwert-Strings (bis zur
 *   Endmarkierung 0xFF) in eine neu reservierte 0x52-Byte-Struktur (Rec52) ein und rückt *pp hinter das Tag vor.
 * - Eingaben: Doppelzeiger pp auf die Leseposition im Dokumentenpuffer und Endzeiger end.
 * - Rückgabewert: int - Zeiger auf die neu angelegte Tag-Struktur oder 0 bei Pufferende oder ungültigem Tag.
 * - Wichtige Variablen:
 *   - o: Reservierte Tag-Struktur mit bis zu 16 Attributwert-Zeigern (p[16]), 16 Attribut-Kennbytes (b[16]),
 *     Attributanzahl (n) und Tag-Typ (id).
 === Ende Beschreibung === */
struct Rec52 { char *p[16]; unsigned char b[16]; unsigned char n; unsigned char id; };
int f_158314(char **pp, char *end)
{
    struct Rec52 *o;
    while (*pp < end && *(unsigned char *)*pp != 0) (*pp)++;
    if (end - 1 <= *pp) return 0;
    (*pp)++;
    o = (struct Rec52 *)f_014ad0(0x52);
    o->id = **pp;
    o->n = 0;
    if (*pp < end && o->id < 0x53) {
        (*pp)++;
        if (d_1aeba8[o->id] == 0) return (int)o;
        while (*pp < end && *(unsigned char *)*pp != 0xff) {
            o->b[o->n] = *(*pp)++;
            *(char **)((char *)o + (o->n << 2)) = *pp;
            o->n++;
            while (*pp < end && *(unsigned char *)*pp != 0) (*pp)++;
            (*pp)++;
        }
        if (*pp < end) {
            (*pp)++;
            return (int)o;
        }
    }
    delete o;
    return 0;
}

//@ f_1583f8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Überspringt im Dokumentenpuffer ab p1 den Parameterblock eines Tags vom Typ p3 (bis
 *   einschließlich zum Abschlussbyte 0xFF), sofern dieser Tag-Typ laut d_1aeba8 Attribute besitzen kann.
 * - Eingaben: Aktuelle Leseposition p1, Pufferende p2 und Tag-Kennung p3.
 * - Rückgabewert: char * - neue Leseposition hinter dem Parameterblock.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
char *f_1583f8(char *p1, char *p2, int p3)
{
    if (p3 < 0x53 && d_1aeba8[p3] != 0) {
        while (p1 < p2) { if (*(u8 *)p1 == 0xff) break; p1 = p1 + 1; }
        p1 = p1 + 1;
    }
    return p1;
}

//@ f_158420
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Rückt den Lesezeiger p1 im Dokumentenpuffer bis hinter das nächste Nullbyte (0x00) vor, um
 *   zum Beginn des nächsten Tags zu gelangen.
 * - Eingaben: Aktuelle Leseposition p1 und Pufferende p2.
 * - Rückgabewert: char * - Zeiger direkt hinter das gefundene Nullbyte (oder p2).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
char *f_158420(char *p1, char *p2)
{
    if (p1 < p2) {
        do {
            if (*p1 == 0)
                break;
            p1 = p1 + 1;
        } while (p1 < p2);
    }
    if (p1 < p2)
        p1 = p1 + 1;
    return p1;
}

V32 *f_15928c(RivaTextLayout *c, char *p2, int p3);

//@ f_15843c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt eine komplette Hypertext-Tabelle (<TABLE> bis Tag 0x46 = </TABLE>): Im ersten
 *   Durchlauf wird die maximale Spaltenzahl (maxcols) aus den Zeilen-Tags (0x4B = <TR>) und Zellen-Tags (0x47 =
 *   <TH>, 0x49 = <TD>) gezählt, im zweiten Durchlauf wird der Inhalt jeder Zelle rekursiv über f_15928c
 *   formatiert, danach werden die maximalen Spaltenbreiten (colw) und Zeilenhöhen (rowh) bestimmt und
 *   schließlich alle Zellenelemente samt optionalen 3D-Tabellenrahmen (p3 != 0) in einen gemeinsamen
 *   Ergebnisvektor übertragen.
 * - Eingaben: Doppelzeiger p1 auf den Tabellenbeginn im Textstrom, Pufferende p2 und Rahmenflag p3 (1 = mit
 *   Rahmenlinien).
 * - Rückgabewert: V32 * - Zeiger auf den neu angelegten Vektor aller fertig positionierten Tabellenelemente.
 * - Wichtige Variablen:
 *   - maxcols: Höchste Spaltenanzahl einer Zeile zur Aufteilung der Gesamtbreite d_1cddf4.
 *   - rows: Zweidimensionale Vektorstruktur aller gesetzten Tabellenzellen (rows[r][c]).
 *   - colw, rowh: Vektoren mit den ermittelten Pixelbreiten jeder Spalte und Pixelhöhen jeder Zeile.
 === Ende Beschreibung === */
struct TbFmt { u8 b10, b11, b12, b13, b14; RivaRgb col; };
struct TbInts {
    int *d; int *b; int *e; int *c; int u4; int u5; int mn;
    int cnt() { return e - b; }
    TbInts() { f_15b990((RivaByteVector *)this, 0x10); }
    void chk() { if (e >= c) f_15b790((RivaByteVector *)this); }
    int &at(int i) { int *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
    int &at_line(int i) {  int *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
    int &at_indexcopy2(int i) { i = (i & 0) ? 0 : i; i = (i & 0) ? 0 : i; /* haelt die Registerzuteilung wie im Original */ int *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
};
struct TbItems {
    RivaLayoutItem *d; RivaLayoutItem *b; RivaLayoutItem *e; RivaLayoutItem *c; int u4; int u5; int mn;
    TbItems(int n) { f_15c3f0((V32 *)this, n); }
    int cnt() { return e - b; }
    void chk() { if (e >= c) f_15c1a0((V32 *)this); }
    RivaLayoutItem &at(int i) { RivaLayoutItem *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
    RivaLayoutItem &at_copy(int i) { RivaLayoutItem *q = d + i; if (q >= e) { e = q + 1; chk(); } int n = i * 32; int b = (int)d; return *(RivaLayoutItem *)(b + n); }
    RivaLayoutItem &at_itemearly1(int i) { i = (i & 0) ? 0 : i; /* haelt die Registerzuteilung wie im Original */ RivaLayoutItem *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
};
struct TbCells {
    TbItems **d; TbItems **b; TbItems **e; TbItems **c; int u4; int u5; int mn;
    int cnt() { return e - b; }
    void chk() { if (e >= c) f_15be60((RivaByteVector *)this); }
    TbItems *&at(int i) { TbItems **q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
    TbItems *&at_early5(int i) { i = (i & 0) ? 0 : i; i = (i & 0) ? 0 : i; i = (i & 0) ? 0 : i; i = (i & 0) ? 0 : i; i = (i & 0) ? 0 : i; /* haelt die Registerzuteilung wie im Original */ TbItems **q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
};
struct TbRows {
    TbCells *d; TbCells *b; TbCells *e; TbCells *c; int u4; int u5; int mn;
    TbRows() { f_15bcd0((RivaByteVector *)this, 0x10); }
    void chk() { if (e >= c) f_15bad0((RivaByteVector *)this); }
    TbCells &at(int i) { TbCells *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
    TbCells &at_early1(int i) { i = (i & 0) ? 0 : i; /* haelt die Registerzuteilung wie im Original */ TbCells *q = d + i; if (q >= e) { e = q + 1; chk(); } return d[i]; }
};
V32 *f_15843c(char **p1, char *p2, int p3)
{
    int maxcols;
    char *start;
    int col;
    TbItems *res;
    int row;
    int tag;
    int r;
    int x;
    int y;
    int c;
    int maxx;
    int hdr;
    char *cell;

    col = 0;
    row = 0;
    *p1 = f_1583f8(*p1, p2, *(u8 *)*p1);
    { int v_ = d_1cddf4; d_1cddf4 = v_; } // haelt die Registerzuteilung wie im Original
    *p1 = f_158420(*p1, p2);
    start = *p1;
    maxcols = 1;
    while (*p1 < p2 && *(u8 *)*p1 != 0x46) {
        tag = *(u8 *)(*p1)++;
        switch (tag) {
        case 0x4b:
            if (col)
                row++;
            col = 0;
            *p1 = f_1583f8(*p1, p2, tag);
            *p1 = f_158420(*p1, p2);
            break;
        case 0x47:
        case 0x49:
            *p1 = f_1583f8(*p1, p2, tag);
            *p1 = f_158420(*p1, p2);
            while (*p1 < p2 && *(u8 *)*p1 != 0x49 && *(u8 *)*p1 != 0x47 && *(u8 *)*p1 != 0x4b && *(u8 *)*p1 != 0x46) {
                tag = *(u8 *)(*p1)++;
                *p1 = f_1583f8(*p1, p2, tag);
                *p1 = f_158420(*p1, p2);
            }
            col++;
            if (col > maxcols)
                maxcols = col;
            break;
        default:
            *p1 = f_1583f8(*p1, p2, tag);
            *p1 = f_158420(*p1, p2);
            break;
        }
    }
    *p1 = start;
    row = 0;
    TbRows rows;
    col = 0;
    while (*p1 < p2 && *(u8 *)*p1 != 0x46) {
        hdr = 0;
        tag = *(u8 *)(*p1)++;
        switch (tag) {
        case 0x4b:
            if (col)
                row++;
            col = 0;
            *p1 = f_1583f8(*p1, p2, tag);
            *p1 = f_158420(*p1, p2);
            break;
        case 0x47:
            hdr = 1;
        case 0x49:
            {
                RivaTextLayout cx;
                cell = f_1583f8(*p1, p2, tag);
                *p1 = cell;
                *p1 = f_158420(*p1, p2);
                while (*p1 < p2 && *(u8 *)*p1 != 0x49 && *(u8 *)*p1 != 0x47 && *(u8 *)*p1 != 0x4b && *(u8 *)*p1 != 0x46) {
                    tag = *(u8 *)(*p1)++;
                    *p1 = f_1583f8(*p1, p2, tag);
                    *p1 = f_158420(*p1, p2);
                }
                *(TbFmt *)&cx.b10 = *(TbFmt *)&d_1cdde8;
                cx.col = d_1cddcc;
                if (hdr == 1) {
                    cx.b12 = 1;
                    cx.b14 = 1;
                }
                cx.center = 0;
                cx.f10 = 0;
                cx.nowrap = 0;
                cx.lh = 0;
                cx.y = 0;
                cx.x = 0;
                cx.w = d_1cddf4 / maxcols - 0x10;
                cx.cnt = 0;
                cx.f3 = d_1cddf8;
                cx.cur = 0;
                if (*p1 < p2)
                    rows.at_early1(row).at_early5(col++) = (TbItems *)f_15928c(&cx, cell, *p1 - cell - 1);
            }
            break;
        default:
            *p1 = f_1583f8(*p1, p2, tag);
            *p1 = f_158420(*p1, p2);
            break;
        }
    }
    (*p1)++;
    *p1 = f_1583f8(*p1, p2, 0x46);
    TbInts rowh;
    TbInts colw;
    for (r = 0; r <= row; r++) {
        for (c = 0; c < rows.at(r).cnt(); c++) {
            int w, h;
            w = ((int (*)(RivaByteVector *, int, int))f_158128)((RivaByteVector *)rows.at(r).at(c), 0, 0xffffff); // haelt die Registerzuteilung wie im Original
            h = ((int (*)(RivaByteVector *, int, int))f_1581c8)((RivaByteVector *)rows.at(r).at(c), 0, 0xffffff); // haelt die Registerzuteilung wie im Original
            if (c >= colw.cnt())
                colw.at(c) = 0;
            if (w > colw.at(c))
                colw.at(c) = w;
            if (r >= rowh.cnt())
                rowh.at(r) = 0;
            if (h > rowh.at(r))
                rowh.at(r) = h;
        }
    }
    res = new TbItems(0x10);
    y = 8;
    maxx = 0;
    for (r = 0; r <= row; r++) {
        x = 8;
        for (c = 0; c < rows.at(r).cnt(); c++) {
            TbItems *sub = rows.at(r).at(c);
            for (int k = 0; k < sub->cnt(); k++) {
                sub->at(k).x += x;
                sub->at_itemearly1(k).y += y;
                res->at(res->cnt()) = sub->at_copy(k);
            }
            if (p3) {
                f_1574ac((V32 *)res, x - 2, y - 2, x - 2, y + rowh.at(r) + 2, d_1a9bcc);
                f_1574ac((V32 *)res, x + colw.at(c) + 2, y - 2, x + colw.at(c) + 2, y + rowh.at(r) + 2, d_1a9bd0);
                { int v_ = d_1cddf4; d_1cddf4 = v_; } // haelt die Registerzuteilung wie im Original
                f_1574ac((V32 *)res, x - 2, y - 2, x + colw.at(c) + 2, y - 2, d_1a9bcc);
                f_1574ac((V32 *)res, x - 2, y + rowh.at(r) + 2, x + colw.at(c) + 2, y + rowh.at(r) + 2, d_1a9bd0);
            }
            x += colw.at(c) + 8;
            maxx = (maxx > x) ? maxx : x;
            if (sub)
                operator delete(f_15c330((V32 *)sub, 1));
        }
        y += rowh.at_indexcopy2(r) + 8;
    }
    { int v_ = d_1cddf4; d_1cddf4 = v_; } // haelt die Registerzuteilung wie im Original
    x = maxx - 2;
    y -= 2;
    if (p3) {
        f_1574ac((V32 *)res, 2, 2, 2, y, d_1a9bd0);
        f_1574ac((V32 *)res, 2, 2, x, 2, d_1a9bd0);
        f_1574ac((V32 *)res, x, 2, x, y, d_1a9bcc);
        f_1574ac((V32 *)res, 2, y, x, y, d_1a9bcc);
    }
    ((void (*)(RivaByteVector *, int))f_15b8d0)((RivaByteVector *)&colw, 1); // haelt die Registerzuteilung wie im Original
    ((void (*)(RivaByteVector *, int))f_15b8d0)((RivaByteVector *)&rowh, 1); // haelt die Registerzuteilung wie im Original
    ((void (*)(RivaByteVector *, int))f_15bc00)((RivaByteVector *)&rows, 1); // haelt die Registerzuteilung wie im Original
    return (V32 *)res;
}

#undef f_1583f8
//@ f_1590bc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wandelt eine hexadezimale HTML-Farbangabe der Form "#RRGGBB" im String s über f_15ead2
 *   (sscanf) in eine 3-Byte-RivaRgb-Struktur um; fehlt das '#'-Zeichen, wird die Standardfarbe d_1cdf94
 *   zurückgegeben.
 * - Eingaben: Zeichenkette s mit dem Farbcode.
 * - Rückgabewert: RivaRgb - geparster RGB-Farbwert.
 * - Wichtige Variablen:
 *   - x: Aus dem Hex-String gelesener 24-Bit-Farbwert.
 === Ende Beschreibung === */
RivaRgb f_1590bc(char *s)
{
    RivaRgb c;
    unsigned x;
    char *p;
    c = d_1cdf94;
    p = strchr(s, '#');
    if (!p)
        return c;
    f_15ead2(p + 1, d_1b94e4, &x);
    c.c = (u8)x;
    c.b = (x >> 8) & 0xff;
    c.a = (x >> 16) & 0xff;
    return c;
}

//@ f_15928c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Haupt-Parser und Formatierer für ein Hypertext-Textstück (p der Länge len): Zerlegt den
 *   Text in Wörter (f_15794c), wertet sämtliche eingebetteten Formatierungs-Tags aus (Dokumentfarben 0x25,
 *   Hyperlinks 0x2D/0x2E, Bilder 0x2F, Tabellen 0x45, Überschriften 0x16..0x21, Zentrierung 0x0E/0x0F, Einzüge
 *   0x10..0x13, nummerierte und unnummerierte Listen 0x02..0x06, Trennlinien 0x01, Schriftstile und
 *   Zeilenumbrüche) und gibt den fertigen Vektor aller Layoutelemente zurück.
 * - Eingaben: Layoutkontext c, Textpuffer p und Textlänge len.
 * - Rückgabewert: V32 * - Zeiger auf den neu erzeugten Vektor (Y8Lv) mit allen 32-Byte-Layoutelementen.
 * - Wichtige Variablen:
 *   - workspace: Arbeitsstruktur mit den Stacks für Einzüge (indents) und geschachtelte Listen (lists) sowie
 *     Vorlagen für Links, Bilder und Trennlinien.
 *   - ordered, number: Flag für nummerierte Liste (<OL>) vs. Aufzählungsliste (<UL>) und laufende
 *     Listenpunktnummer.
 *   - inlink: Flag, ob sich der Parser aktuell innerhalb eines geöffneten <A ...>-Hyperlinks befindet.
 === Ende Beschreibung === */
struct Z8Fmt { u8 b10, b11, b12, b13, b14; RivaRgb col; };
struct Z8It { int type; int x; int y; short w; short h; int a; int b; int p2; int p3; };
struct Z8Sz { int w; int h; };
struct Z8Tag { char *v[16]; u8 key[16]; u8 n; u8 type; };
struct Z8Vb {
    char *d; char *b; char *e; char *c; int u4; int u5; int mn;
    void *room() { if (e >= c) f_15b790((RivaByteVector *)this); void *r = e; e += 4; return r; }
    
    // haelt die Registerzuteilung wie im Original
    void *roomLast() { if(e>=c)f_15b790((RivaByteVector*)this);char*r=e;e=r;*(char* volatile*)&e=r+4;return r; }
    void *roomFirstFix(){if(e>=c)f_15b790((RivaByteVector*)this);{char*q=c;c=q;}char*r=e;e+=4;return r;}
    void *take() { if (e - b < mn) f_15b770((RivaByteVector *)this); e -= 4; return e; }
};
struct Z8St : Z8Vb {
    int empty() { return e == b; }
    void push(const int &x) { *(int *)room() = x; }
    int pop() { return *(int *)take(); }
    int top() { return ((int *)e)[-1]; }
};
struct Z8Lv {
    Z8Lv(int n) { f_15c3f0((V32*)this,n); }
    Z8It *d; Z8It *b; Z8It *e; Z8It *c; int u4; int u5; int mn;
    int cnt() { return e - b; }
    Z8It &at(int i) { Z8It *q = d + i; if (q >= e) { e = q + 1; if (e >= c) f_15c1a0((V32 *)this); } return d[i]; }
};
void f_15b8d0(RivaByteVector *v, int f);
int *f_09e220(int *out, const char *s, int n, void *font);
int z8_1581c8(RivaByteVector *v, int a, int b);
#pragma aux z8_1581c8 "f_1581c8"
#define Z8_NL() f_15717c(c, res)
#define Z8_FMT(c) (*(Z8Fmt *)&(c)->b10)

inline void z8_place904(RivaTextLayout *c,V32 *res,char *name,char *alt,const int &h,const Z8Sz &sz)
{
    if (c->x == 0) c->lh = c->f7;
    if (c->nowrap == 0 && c->x + sz.w > c->w && c->x != 0) f_15717c(c, res);
    if (h > c->lh) c->lh = h + 1;
    {
        Z8It it;
        int n;
        it.type = 4;
        it.x = c->x;
        it.y = c->y;
        it.w = sz.w;
        it.h = sz.h;
        it.a = (int)name;
        it.b = (int)alt;
        n = ((Z8Lv *)res)->cnt();
        f_15c140(res, n);
        ((Z8Lv *)res)->d[n] = it;
    }
    c->x += (c->nowrap == 0 ? c->sp : 0) + sz.w;
}
inline void z8_img(RivaTextLayout *c, V32 *res, char *name, char *alt, int w, int h)
{
    Z8Sz sz;
    f_156de4(c);
    if (f_09db80(name, &w, &h) == 0) {
        int t1[2], t2[2];
        w = (f_09e220(t1, alt, strlen(alt), &d_1cdde8)[0] + 4 < 0x20) ? 0x20 : f_09e220(t2, alt, strlen(alt), &d_1cdde8)[0] + 4;
        h = 0x20;
    }
    sz.w = w;
    sz.h = h;
    z8_place904(c,res,name,alt,h,sz);
}
struct Y8Stk : Z8Vb {
    int emptyValue() { unsigned char r=e==b; return r; }
    int empty() { return e == b; }
    void push(const int &x) { *(int *)room() = x; }
    void pushLast(const int &x) { *(int*)roomLast()=x; }
    void pushFirstFix(const int&x){*(int*)roomFirstFix()=x;}
    int pop() { return *(int *)take(); }
    int &top() { return ((int *)e)[-1]; }
};
struct Y8Lv {
    Y8Lv(int n) { f_15c3f0((V32 *)this, n); }
    Z8It *d; Z8It *b; Z8It *e; Z8It *c; int u4; int u5; int mn;
    int cnt() { return e - b; }
    Z8It &at(int i) { Z8It *q = d + i; if (q >= e) { e = q + 1; if (e >= c) f_15c1a0((V32 *)this); } return d[i]; }
    void addLine(const Z8It&it){int n=cnt(); { short v_=*(short*)&d_1cddf4; *(short*)&d_1cddf4=v_; } f_15c140((V32*)this,n); d[n]=it;}
    void add(const Z8It &it) { int n = cnt(); f_15c140((V32 *)this, n); d[n] = it; }
    Z8It &atSecond(int i){Z8It*q=d+i;if(q>=e){e=q+1;if(e>=c)f_15c1a0((V32*)this);}return d[i];}
    Z8It &atSecondCopy(int i){Z8It*q=d+i;if(q>=e){e=q+1;if(e>=c)f_15c1a0((V32*)this);}return d[i];}
    Z8It &atJ(int i) {  /* haelt die Registerzuteilung wie im Original */ i = (i & 0) ? 0 : i; Z8It *q = d + i; if (q >= e) { e = q + 1; if (e >= c) f_15c1a0((V32 *)this); } return d[i]; }
    Z8It &atK(int i) {   /* haelt die Registerzuteilung wie im Original */ Z8It *q = d + i; if (q >= e) { e = q + 1; if (e >= c) f_15c1a0((V32 *)this); } return d[i]; }
};
struct Y8Link : Z8It {
    Y8Link() {}
    void set(int x_, int y_, char *href, char *name) { type = 5; x = x_; y = y_; a = (int)href; b = (int)name; h = 0; w = 0; }
    Y8Link(int x_, int y_, char *href, char *name) { type = 5; x = x_; y = y_; a = (int)href; b = (int)name; h = 0; w = 0; }
};
struct Y8Sz {
    int w; int h;
    Y8Sz() {}
    Y8Sz(int w_, int h_) { w = w_; h = h_; }
};
struct Y8It : Z8It {
    void size(int w_, int h_) { h = h_; w = w_; }
};
inline void y8_free(void *q) { if (q) operator delete(q); } // haelt die Registerzuteilung wie im Original
struct Y8Workspace {
    Y8Link link;
    Z8It image;
    Z8It rule;
    Y8Stk indents;
    Y8Stk lists;
    int text[2];
    int first[2];
    int second[2];
    void line(RivaTextLayout *c,Y8Lv *res,int height) { rule.type=2; rule.x=c->cur; rule.y=c->y; rule.w=c->w; rule.h=height; res->addLine(rule); }
    Y8Sz size;
};
inline void y8_img(RivaTextLayout *c, Y8Lv *res, char *name, char *alt, int w, int h, Y8Workspace &workspace)
{
    f_156de4(c);
    if (f_09db80(name, &w, &h) == 0) {
        w = (f_09e220(workspace.first, alt, strlen(alt), &d_1cdde8)[0] + 4 < 0x20) ? 0x20 : f_09e220(workspace.second, alt, strlen(alt), &d_1cdde8)[0] + 4;
        h = 0x20;
    }
    workspace.size.w = w;
    workspace.size.h = h;
    if (c->x == 0)
        c->lh = c->f7;
    if (c->nowrap == 0 && c->x + workspace.size.w > c->w && c->x != 0)
        f_15717c(c, (V32 *)res);
    if (h > c->lh)
        c->lh = h + 1;
    workspace.image.type = 4;
    workspace.image.x = c->x;
    workspace.image.y = c->y;
    workspace.image.w = workspace.size.w;
    workspace.image.h = workspace.size.h;
    workspace.image.a = (int)name;
    workspace.image.b = (int)alt;
    res->add(workspace.image);
    c->x += (c->nowrap == 0 ? c->sp : 0) + workspace.size.w;
}
inline Z8It &y8_at_second(Y8Lv*t,int i){Z8It*q=t->d+i;if(q>=t->e){t->e=q+1;if(t->e>=t->c)f_15c1a0((V32*)t);}return t->d[i];}
inline Z8It &y8_at(int i, Y8Lv *t) { Z8It *q = t->d + i; if (q >= t->e) { t->e = q + 1; if (t->e >= t->c) f_15c1a0((V32 *)t); } return t->d[i]; }
#define Y8_WS(q) (d_1bbfdc[(u8)(*(q) + 1)] & 2)
#define Y8_FIND(t, s) f_158288((int)(t), (char *)(s))
#define Y8_NL() f_15717c(c, (V32 *)res)
#define Y8_WHITE() \
    if (*p == 10) Y8_NL(); \
    if (*p == 9) c->x = (c->x & ~0x3f) + 0x40; \
    if (*p == 32) c->x += c->sp;

V32 *f_15928c(RivaTextLayout *c, char *p, int len)
{
    Y8Workspace workspace;
    int ordered; int number; int inlink; char *end; Z8Tag *tag;
    int attrHeight; Y8Lv *imageResult; char *imageName; char *imageAlt; int imageWidth; int imageHeight; int tableHeight;
    Y8Lv *tableDestination;
    Y8Lv *res;
    f_15b990((RivaByteVector*)&workspace.lists,0x10); f_15b990((RivaByteVector*)&workspace.indents,0x10);
    ordered=-16;ordered=4;ordered=9;ordered=12;ordered=100;ordered=-64;ordered=78;ordered=2;ordered=6;ordered=64;ordered=10;ordered=-4;ordered=-6;ordered=-1;ordered=0; // haelt die Registerzuteilung wie im Original
    number=1;inlink=0;res=new Y8Lv(0x80);f_15c300((V32*)res);
    end = p + len;
    while (p < end) {
        int space = 0;
        char *start;
        int n;
        int lvl;

        while (p < end && Y8_WS(p)) {
            if (c->nowrap != 0) {
                Y8_WHITE()
            } else
                space = 1;
            p++;
        }
        if (space == 1 && c->b14 == 0 && c->x != 0)
            c->x += c->sp;
        start = p;
        while (p < end && !Y8_WS(p) && *p != 0) {
            if (c->nowrap != 0) {
                Y8_WHITE()
            }
            p++;
        }
        n = p - start;
        if (n > 0) {
            if (c->b14)
                while (start[n] == 32)
                    n++;
            f_15794c(c, (V32 *)res, start, n);
        }
        lvl = 0;
        if (p < end) {
            switch (*p) {
            case 0:
                tag = (Z8Tag *)f_158314(&p, end);
                if (tag == 0)
                    break;
                {
                    switch (tag->type) {
                    case 0x25: {
                        RivaRgb color4;
                        int i;
                        i = Y8_FIND(tag, d_1b94e7);
                        if (i != -1)
                            d_1cddf0 = (int)tag->v[i];
                        i = Y8_FIND(tag, d_1b94f3);
                        if (i != -1)
                            d_1cddd4 = f_1590bc(tag->v[i]);
                        i = Y8_FIND(tag, d_1b94f9);
                        if (i != -1)
                            d_1cddcc = f_1590bc(tag->v[i]);
                        i = Y8_FIND(tag, d_1b94ff);
                        if (i != -1)
                            d_1cddd0 = f_1590bc(tag->v[i]);
                        i = Y8_FIND(tag, d_1b9508);
                        if (i != -1)
                            d_1cddd8 = f_1590bc(tag->v[i]);
                        i = Y8_FIND(tag, d_1b950f);
                        if (i != -1)
                            { color4 = f_1590bc(tag->v[i]); d_1cdddc = color4; }
                        c->col = d_1cddcc;
                        break;
                    }
                    case 0x2d: {
                        char *name;
                        char *href;
                        int i;
                        if (inlink)
                            f_157614((V32 *)res, c->x, c->y);
                        i = Y8_FIND(tag, d_1b9516);
                        href = 0;
                        name = 0;
                        inlink = 1;
                        if (i != -1)
                            href = tag->v[i];
                        i = Y8_FIND(tag, d_1b951c);
                        if (i != -1)
                            name = tag->v[i];
                        workspace.link.set(c->x, c->y, href, name);
                        res->add(workspace.link);
                        if (href)
                            c->col = d_1cddd4;
                        c->b14 = 1;
                        break;
                    }
                    case 0x2e:
                        if (inlink)
                            f_157614((V32 *)res, c->x, c->y);
                        c->col = d_1cddcc;
                        c->b14 = 0;
                        break;
                    case 0x2f: {
                        char *src = (char *)d_1b9522;
                        char *alt = 0;
                        int w = 0x20;
                        int i;
                        i = Y8_FIND(tag, d_1b952c);
                        attrHeight = 0x20;
                        if (i != -1)
                            src = tag->v[i];
                        i = Y8_FIND(tag, d_1b9531);
                        if (i != -1)
                            alt = tag->v[i];
                        i = Y8_FIND(tag, d_1b9536);
                        if (i != -1)
                            w = f_14d5c9(tag->v[i]);
                        i = Y8_FIND(tag, d_1b953d);
                        if (i != -1)
                            attrHeight = f_14d5c9(tag->v[i]);
                        if (alt == 0)
                            alt = src;
                        { RivaTextLayout*imageContext=c;imageResult=res;imageName=src;imageAlt=alt;imageWidth=w;imageHeight=attrHeight;
    f_156de4(imageContext);
    if (f_09db80(imageName, &imageWidth, &imageHeight) == 0) {
        imageWidth = (f_09e220(workspace.first, imageAlt, strlen(imageAlt), &d_1cdde8)[0] + 4 < 0x20) ? 0x20 : f_09e220(workspace.second, imageAlt, strlen(imageAlt), &d_1cdde8)[0] + 4;
        imageHeight = 0x20;
    }
    workspace.size.w = imageWidth;
    workspace.size.h = imageHeight;
    if (imageContext->x == 0)
        imageContext->lh = imageContext->f7;
    if (imageContext->nowrap == 0 && imageContext->x + workspace.size.w > imageContext->w && imageContext->x != 0)
        f_15717c(imageContext, (V32 *)imageResult);
    if (imageHeight > imageContext->lh)
        imageContext->lh = imageHeight + 1;
    workspace.image.type = 4;
    workspace.image.x = imageContext->x;
    workspace.image.y = imageContext->y;
    workspace.image.w = workspace.size.w;
    workspace.image.h = workspace.size.h;
    workspace.image.a = (int)imageName;
    workspace.image.b = (int)imageAlt;
    imageResult->add(workspace.image);
    imageContext->x += (imageContext->nowrap == 0 ? imageContext->sp : 0) + workspace.size.w;
 }
                        break;
                    }
                    case 0x0f:
                        if (c->center == 1 && c->x != 0)
                            Y8_NL();
                        // haelt die Registerzuteilung wie im Original
                        c->center = 0;
                        break;
                    case 0x45: {
                        int border;
                        Y8Lv *tbl;
                        int i;
                        Y8_NL();
                        border = 0;
                        if (Y8_FIND(tag, d_1b9545) != -1)
                            border = 1;
                        tbl = (Y8Lv *)f_15843c(&p, end, border);
                        tableHeight = ((int (*)(RivaByteVector *, int, int))f_1581c8)((RivaByteVector *)tbl, 0, 0xffffff); // haelt die Registerzuteilung wie im Original
                        for (i = 0; i < tbl->cnt(); i++) {
                            tbl->atJ(i).x += c->x + 4;
                            tbl->atJ(i).y += c->y;
                            { const Z8It &sourceItem = y8_at(i,tbl); int targetIndex=res->cnt(); tableDestination=res;  targetIndex=(targetIndex&0)?0:targetIndex; Z8It*q=tableDestination->d+targetIndex; if(q>=tableDestination->e){tableDestination->e=q+1;if(tableDestination->e>=tableDestination->c)f_15c1a0((V32*)tableDestination);} tableDestination->d[targetIndex]=sourceItem; }
                        }
                        if (tbl)
                            operator delete(f_15c330((V32 *)tbl, 1));
                        c->y += tableHeight;
                        Y8_NL();
                        break;
                    }
                    case 0x0a:
                        c->b12 = 1;
                        c->b14 = 1;
                        break;
                    case 0x0b:
                        c->b12 = 0;
                        c->b14 = 0;
                        break;
                    case 0x14:
                    case 0x35:
                        c->b11 = 1;
                        break;
                    case 0x15:
                    case 0x36:
                        c->b11 = 0;
                        break;
                    case 0x3b:
                    case 0x3d:
                    case 0x43:
                    case 0x4d:
                        Y8_NL();
                        c->nowrap = 1;
                    case 0x39:
                    case 0x3f:
                        c->b13 = 1;
                        break;
                    case 0x3c:
                    case 0x3e:
                    case 0x44:
                    case 0x4e:
                        Y8_NL();
                        c->nowrap = 0;
                    case 0x3a:
                    case 0x40:
                        c->b13 = 0;
                        break;
                    case 0x08:
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        break;
                    case 0x09:
                        if (c->x != 0)
                            Y8_NL();
                    case 0x00:
                        Y8_NL();
                        break;
                    case 0x33: {
                        int i = Y8_FIND(tag, d_1b954c);
                        if (i != -1)
                            c->b10 = f_14d5c9(tag->v[i]);
                        break;
                    }
                    case 0x01: {
                        if (c->x != 0)
                            Y8_NL();
                        *(volatile int *)&c->y += 4;
                        workspace.line(c,res,4);
                        c->cnt = res->cnt();
                        c->y += 8;
                        break;
                    }
                    case 0x12:
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        f_15713c(c, 0x10);
                        workspace.indents.push(c->cur);
                        workspace.indents.push(c->w);
                        break;
                    case 0x11:
                        if (c->x != 0)
                            Y8_NL();
                        if (!workspace.indents.empty()) {
                            c->w = workspace.indents.pop();
                            c->cur = workspace.indents.top();
                            workspace.indents.push(c->w);
                        }
                        break;
                    case 0x10:
                        if (c->x != 0)
                            Y8_NL();
                        if (!workspace.indents.empty()) {
                            c->w = workspace.indents.pop();
                            c->cur = workspace.indents.top();
                            workspace.indents.push(c->w);
                        }
                        f_15713c(c, 0x10);
                        break;
                    case 0x13:
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        if (!workspace.indents.empty()) {
                            c->w = workspace.indents.pop();
                            c->cur = workspace.indents.pop();
                        }
                        f_157158(c, 0x10);
                        break;
                    case 0x04:
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        workspace.lists.pushFirstFix(ordered);
                        workspace.lists.pushLast(number);
                        ordered = 1;
                        number = 1;
                        f_15713c(c, 0x10);
                        break;
                    case 0x02:
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        ordered = 0;
                        number = 1;
                        f_15713c(c, 0x10);
                        break;
                    case 0x03:
                    case 0x05:
                        if (!workspace.lists.emptyValue()) {
                            number = workspace.lists.pop();
                            ordered = workspace.lists.pop();
                        }
                        if (c->x != 0)
                            Y8_NL();
                        Y8_NL();
                        f_157158(c, 0x10);
                        break;
                    case 0x06: {
                        if (c->x != 0)
                            Y8_NL();
                        Z8_FMT(c) = *(Z8Fmt *)&d_1cdde8;
                        if (c->cur >= 0x10)
                            c->x -= 0x10;
                        if (ordered) {
                            char *buf = f_014af0(8);
                            if (d_1cdf8c < 100) {
                                d_1cddfc[d_1cdf8c] = buf;
                                d_1cdf8c++;
                            }
                            // haelt die Registerzuteilung wie im Original
                            f_14572e(buf, d_1b9552, number);
                            number++;
                            f_09e220(workspace.text, buf, strlen(buf), &c->b10);
                            if (workspace.text[0] < 12)
                                c->x += 12 - workspace.text[0];
                            f_15794c(c, (V32 *)res, buf, strlen(buf));
                        } else {
                            int x = c->x + 6;
                            int y = c->y + (c->lh - 6) / 2;
                            f_1574ac((V32 *)res, x, y, x + 6, y, d_1a9bcc);
                            f_1574ac((V32 *)res, x, y, x, y + 6, d_1a9bcc);
                            f_1574ac((V32 *)res, x + 6, y, x + 6, y + 6, d_1a9bd0);
                            f_1574ac((V32 *)res, x + 6, y + 6, x, y + 6, d_1a9bd0);
                            c->x += 0x10;
                        }
                        if (c->x < 0)
                            c->x = 0;
                        break;
                    }
                    case 0x16:
                        lvl++;
                    case 0x18:
                        lvl++;
                    case 0x1a:
                        lvl++;
                    case 0x1c:
                        lvl++;
                    case 0x1e:
                        lvl++;
                    case 0x20: {
                        int i;
                        Y8_NL();
                        Y8_NL();
                        c->lh = 0;
                        Z8_FMT(c) = ((Z8Fmt *)d_1a9bd4)[lvl];
                        i = Y8_FIND(tag, d_1b9556);
                        if (i != -1) {
                            if (f_14d717(tag->v[i], d_1b955d) == 0)
                                c->center = 1;
                        }
                        break;
                    }
                    case 0x0e:
                        c->center = 1;
                        break;
                    case 0x17:
                    case 0x19:
                    case 0x1b:
                    case 0x1d:
                    case 0x1f:
                    case 0x21:
                        Y8_NL();
                        Y8_NL();
                        c->lh = 0;
                        Z8_FMT(c) = *(Z8Fmt *)&d_1cdde8;
                        c->center = 0;
                        break;
                    case 0x27:
                        do {
                            while (p < end && *p != 0)
                                p++;
                            p++;
                        } while (p < end && *p != 0x28);
                        p++;
                        break;
                    }
                    y8_free(tag);
                }
                break;
            }
        }
    }
    Y8_NL();
    f_15b8d0((RivaByteVector *)&workspace.indents, 1); // haelt die Registerzuteilung wie im Original
    f_15b8d0((RivaByteVector *)&workspace.lists, 1); // haelt die Registerzuteilung wie im Original
    return (V32 *)res;
}


//@ f_15a78c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft unter Schutz des Reentranz-Zählers d_1cddb0, ob das globale Hypertext-Dokument neu
 *   gesetzt werden muss (d_1cddc8 == 1), ruft in diesem Fall den Parser f_15928c auf und berechnet Gesamtbreite
 *   (d_1bde24) und Gesamthöhe (d_1bde28); anschließend zeichnet die Funktion den im Rechteck clip sichtbaren
 *   Ausschnitt des Dokuments inklusive Hintergrundkachelung und Link-Hervorhebung.
 * - Eingaben: Zeiger clip auf das 4-Int-Sichtrechteck (links, oben, rechts, unten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddb0: Reentranz-Sperrzähler (verhindert rekursive Neuformatierung während des Zeichnens).
 *   - d_1bde24, d_1bde28: Berechnete Gesamtbreite und Gesamthöhe des formatierten Dokuments.
 === Ende Beschreibung === */
#pragma aux f_15a78c "*";
void f_15a78c(int *clip)
{
    struct Style78c { int value; char flags; RivaRgb color; };
    RivaTextLayout cx;
    if (d_1cddb0 != 0)
        return;
    d_1cddb0 = d_1cddb0 + 1;
    if (d_1cddc8 == 1) {
        *(Style78c *)&cx.b10 = *(Style78c *)&d_1cdde8;
        d_1cddc8 = 0;
        cx.center = 0;
        cx.f10 = 0;
        cx.nowrap = 0;
        cx.lh = 0;
        cx.y = 0;
        cx.x = 0;
        cx.w = d_1cddf4;
        cx.cnt = 0;
        cx.f3 = d_1cddf8;
        cx.cur = 4;
        cx.w -= 8;
        f_156de4(&cx);
        if (d_1cddbc != 0) {
            V32 *t = d_1cddbc;
            if (t != 0)
                delete (char *)f_15c330(t, 1);
        }
        f_156c38();
        d_1cddf0 = 0;
        d_1cddbc = f_15928c(&cx, d_1cddc0, d_1cddc4);
        d_1bde24 = f_158128(d_1cddbc, 0, 0xffffff);
        d_1bde28 = z8_1581c8(d_1cddbc, 0, 0xffffff);
    }
    RivaByteVector *v = d_1cddbc;

    struct T1 { int len; const char *text; Style78c q; };
    struct ColSub { short a, b, c, d; RivaRgb col; };
    struct T4 { int data; const char *text; };
    struct Elem {
        int t, x, y;
        short w, h;
        union {
            T1 _t1;
            ColSub _t3;
            T4 _t4;
        };
        T1 *t1() { return &_t1; }
        ColSub *t3() { return &_t3; }
        T4 *t4() { return &_t4; }
    };
    struct Zugriff {
        static Elem get(RivaByteVector *v, int i) {
            return *(Elem *)(v->d + i * 32);
        }
        static void draw1(int p1, int p2, const char *p3, int p4, Style78c *p5) {
            Style78c q = *p5;
            if (d_1cdf90 != 0) q.color = d_1cdddc;
            f_09e3f0(p1, p2, p3, p4, &q);
        }
        static void draw2(int p1, int p2, int p3, int p4) {
            int half = p4;
            half /= 2;
            p3 += p1;
            f_09e100(p1 + 7, p2, p3 - 7, p2, d_1a9bcc);
            f_09e100(p1 + 2, p2 + half, p1 + 7, p2, d_1a9bcc);
            f_09e100(p1 + 2, p2 + half, p1 + 7, p2 + (half + half), d_1a9bcc);
            f_09e100(p3 - 7, p2, p3 - 2, p2 + half, d_1a9bd0);
            f_09e100(p3 - 2, p2 + half, p3 - 7, p2 + (half + half), d_1a9bd0);
            f_09e100(p3 - 7, p2 + (half + half), p1 + 7, p2 + (half + half), d_1a9bd0);
        }
        static void draw3(int p1, int p2, int p3, int p4, RivaRgb p5) {
            f_09e100(p1, p2, p3, p4, &p5);
        }
        static void draw4(int p1, int saved_p3, int p5, int p3, int p2, int p4, const char *p6) {
            int copyx;
 

            if (!f_09dc50(p5, p1, p2, 1)) {
                int copyy;
                const char *text;
                f_09e100(p1, p2, p1 + p3, p2, d_1a9bcc);
                f_09e100(p1 + p3, p2, p1 + p3, p2 + p4, d_1a9bcc);
                f_09e100(p1 + p3, p2 + p4, p1, p2 + p4, d_1a9bd0);
                copyx = p1;
                copyy = p2;
                f_09e100(p1, p2 + p4, p1, p2, d_1a9bd0);
                text = p6 ? p6 : d_1b94de;
                f_09e3f0(copyx + 2, copyy + 2, text, strlen(text), &d_1cdde8);
            }
            if (d_1cdf90 != 0) {
                f_09e100(p1, p2, p1 + saved_p3, p2, &d_1cdddc);
                f_09e100(p1 + saved_p3, p2, p1 + saved_p3, p2 + p4, &d_1cdddc);
                f_09e100(p1 + saved_p3, p2 + p4, p1, p2 + p4, &d_1cdddc);
                f_09e100(p1, p2 + p4, p1, p2, &d_1cdddc);
            }
        }
    };

    int &c0 = clip[0];
    int &c2 = clip[2];
    int &c1 = clip[1];
    int &c3 = clip[3];
    f_09dc00(clip);
    if (d_1cddf0 != 0) {
        int w, h;
        int x0, x, y, x1, y0, y1;
        if (f_09db80((char *)d_1cddf0, &w, &h)) {
            x0 = c0 / w - 1;
            x1 = c2 / w + 1;
            y0 = c1 / h - 1;
            y1 = c3 / h + 1;
            for (y = y0; y <= y1; ++y) {
                for (x = x0; x <= x1; ++x) {
                    f_09dc50(d_1cddf0, x * w, y * h, 0);
                }
            }
        } else {
            f_09e140(c0, c1, c2 - c0 + 1, c3 - c1 + 1, &d_1cddd0);
        }
    } else {
        f_09e140(c0, c1, c2 - c0 + 1, c3 - c1 + 1, &d_1cddd0);
    }

    d_1cdf90 = 0;
    for (int i = 0; i < (v->e - v->b) / 32; ++i) {
        Elem r;
        Elem temp = *(Elem *)(v->d + i * 32);
        r = temp;
        Elem *p = &r;
        if (r.t == 5 || r.t == 6 ||
            (r.x <= c2 && r.x + (*(int *)((char *)&r + 0xa) >> 16) > c0 &&
             r.y <= c3 && r.y + (*(int *)((char *)&r + 0xc) >> 16) > c1)) {
            switch (p->t) {
            case 1:
                Zugriff::draw1(p->x, p->y, p->t1()->text, p->t1()->len, &p->t1()->q);
                break;
            case 2:
                Zugriff::draw2(p->x, p->y, *(int *)((char *)p + 0xa) >> 16, *(int *)((char *)p + 0xc) >> 16);
                break;
            case 3:
                Zugriff::draw3(p->x + p->t3()->a,
                               p->y + (*(int *)((char *)p->t3() + 0) >> 16),
                               p->x + (*(int *)((char *)p->t3() + 2) >> 16),
                               p->y + (*(int *)((char *)p->t3() + 4) >> 16),
                               p->t3()->col);
                break;
            case 4:
                Zugriff::draw4(p->x, *(int *)((char *)p + 0xa) >> 16, p->t4()->data, *(int *)((char *)p + 0xa) >> 16, p->y, *(int *)((char *)p + 0xc) >> 16, p->t4()->text);
                break;
            case 5:
                if (d_1cdf98 == i) d_1cdf90 = 1;
                break;
            case 6:
                d_1cdf90 = 0;
                break;
            }
        }
    }
    --d_1cddb0;
}

//@ f_15ae98
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffentliche Zeichenfunktion für das Hypertext-Fenster: Übernimmt die aktuelle
 *   Fensterbreite (d_1bde2c) und Fensterhöhe (d_1bde30), löst bei einer Breitenänderung automatisch eine
 *   Neuformatierung (d_1cddc8 = 1) aus, verschiebt den Grafik-Ursprung über f_09dbe0 um den aktuellen
 *   Scroll-Offset (-p1, -p2), zeichnet den sichtbaren Dokumentausschnitt p3 und setzt den Grafik-Ursprung danach
 *   wieder auf (0, 0) zurück.
 * - Eingaben: Horizontaler Scroll-Offset p1, vertikaler Scroll-Offset p2 und Zeiger p3 auf das
 *   Bildschirm-Sichtrechteck.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddb4, d_1cddf4: Zuletzt verwendete und aktuelle Layoutbreite zur Erkennung von Größenänderungen des
 *     Anzeigefensters.
 === Ende Beschreibung === */
struct Rc494 { int x1, y1, x2, y2; Rc494(int a, int b, int c, int d) { x1 = a; y1 = b; x2 = c; y2 = d; } };
struct Q494 { int a; char c; RivaRgb col; };
struct T1494 { int len; int text; Q494 q; };
struct T3Sub494 { short a, b, c, d; RivaRgb col; };
struct T4494 { int data; char *text; };
struct Elem494 {
    int t, x, y;
    short w, h;
    union {
        T1494 _t1;
        T3Sub494 _t3;
        T4494 _t4;
    };
    T1494 *t1() { return &_t1; }
    T3Sub494 *t3() { return &_t3; }
    T4494 *t4() { return &_t4; }
};
struct Zugriff494 {
    static Elem494 get(V32 *v, int i) {
        return *(Elem494 *)(v->d + i * 32);
    }
    static void draw1(int p1, int p2, int p3, int p4, Q494 *p5) {
        Q494 q = *p5;
        if (d_1cdf90 != 0) q.col = d_1cdddc;
        f_09e3f0(p1, p2, (const char *)p3, p4, &q);
    }
    static void draw2(int p1, int p2, int p3, int p4) {
        int half = p4 / 2;
        p3 += p1;
        f_09e100(p1 + 7, p2, p3 - 7, p2, d_1a9bcc);
        f_09e100(p1 + 2, p2 + half, p1 + 7, p2, d_1a9bcc);
        f_09e100(p1 + 2, p2 + half, p1 + 7, p2 + half * 2, d_1a9bcc);
        f_09e100(p3 - 7, p2, p3 - 2, p2 + half, d_1a9bd0);
        f_09e100(p3 - 2, p2 + half, p3 - 7, p2 + half * 2, d_1a9bd0);
        f_09e100(p3 - 7, p2 + half * 2, p1 + 7, p2 + half * 2, d_1a9bd0);
    }
    static void draw3(int p1, int p2, int p3, int p4, RivaRgb p5) {
        f_09e100(p1, p2, p3, p4, &p5);
    }
    static void draw4(int p1, int p2, int p3, int p4, int p5, char *p6) {
        if (!f_09dc50(p5, p1, p2, 1)) {
            int copyy, copyx;
            const char *text;
            f_09e100(p1, p2, p1 + p3, p2, d_1a9bcc);
            f_09e100(p1 + p3, p2, p1 + p3, p2 + p4, d_1a9bcc);
            f_09e100(p1 + p3, p2 + p4, p1, p2 + p4, d_1a9bd0);
            copyx = p1;
            copyy = p2;
            f_09e100(p1, p2 + p4, p1, p2, d_1a9bd0);
            text = p6 ? p6 : d_1b94de;
            f_09e3f0(copyx + 2, copyy + 2, text, strlen(text), &d_1cdde8);
        }
        if (d_1cdf90 != 0) {
            f_09e100(p1, p2, p1 + p3, p2, &d_1cdddc);
            f_09e100(p1 + p3, p2, p1 + p3, p2 + p4, &d_1cdddc);
            f_09e100(p1 + p3, p2 + p4, p1, p2 + p4, &d_1cdddc);
            f_09e100(p1, p2 + p4, p1, p2, &d_1cdddc);
        }
    }
};
inline void items494(V32 *v, int *clip)
{
    int *c0, *c2, *c3, *c1;
    c0 = clip;
    c2 = clip + 2;
    c1 = clip + 1;
    c3 = clip + 3;
    f_09dc00(clip);
    if (d_1cddf0 != 0) {
        int w, x, x1, h, y1, y, y0, x0;
        if (f_09db80((const char *)d_1cddf0, &w, &h)) {
            x0 = (*c0) / w - 1;
            x1 = (*c2) / w + 1;
            y0 = (*c1) / h - 1;
            y1 = (*c3) / h + 1;
            for (y = y0; y <= y1; ++y) {
                for (x = x0; x <= x1; ++x) {
                    f_09dc50(d_1cddf0, x * w, y * h, 0);
                }
            }
        } else {
            f_09e140((*c0), (*c1), (*c2) - (*c0) + 1, (*c3) - (*c1) + 1, &d_1cddd0);
        }
    } else {
        f_09e140((*c0), (*c1), (*c2) - (*c0) + 1, (*c3) - (*c1) + 1, &d_1cddd0);
    }

    d_1cdf90 = 0;
    for (int i = 0; i < (v->e - v->b) / 32; ++i) {
        Elem494 r = Zugriff494::get(v, i);
        Elem494 *p = &r;
        if (r.t == 5 || r.t == 6 ||
            (r.x <= (*c2) && r.x + (*(int *)((char *)&r + 0xa) >> 16) > (*c0) &&
             r.y <= (*c3) && r.y + (*(int *)((char *)&r + 0xc) >> 16) > (*c1))) {
            switch (p->t) {
            case 1:
                Zugriff494::draw1(p->x, p->y, p->t1()->text, p->t1()->len, &p->t1()->q);
                break;
            case 2:
                Zugriff494::draw2(p->x, p->y, *(int *)((char *)p + 0xa) >> 16, *(int *)((char *)p + 0xc) >> 16);
                break;
            case 3:
                Zugriff494::draw3(p->x + p->t3()->a,
                               p->y + (*(int *)((char *)p->t3() + 0) >> 16),
                               p->x + (*(int *)((char *)p->t3() + 2) >> 16),
                               p->y + (*(int *)((char *)p->t3() + 4) >> 16),
                               p->t3()->col);
                break;
            case 4:
                Zugriff494::draw4(p->x, p->y, *(int *)((char *)p + 0xa) >> 16, *(int *)((char *)p + 0xc) >> 16, p->t4()->data, p->t4()->text);
                break;
            case 5:
                if (d_1cdf98 == i) d_1cdf90 = 1;
                break;
            case 6:
                d_1cdf90 = 0;
                break;
            }
        }
    }
}
inline void draw494(int *r)
{
    if (d_1cddb0 != 0)
        return;
    d_1cddb0 = d_1cddb0 + 1;
    if (d_1cddc8 == 1) {
        RivaTextLayout cx;
        d_1cddc8 = 0;
        *(Z8Fmt *)&cx.b10 = *(Z8Fmt *)&d_1cdde8;
        cx.center = 0;
        cx.f10 = 0;
        cx.nowrap = 0;
        cx.lh = 0;
        cx.y = 0;
        cx.x = 0;
        cx.w = d_1cddf4;
        cx.cnt = 0;
        cx.f3 = d_1cddf8;
        cx.cur = 4;
        cx.w -= 8;
        f_156de4(&cx);
        if (d_1cddbc != 0) {
            V32 *t = d_1cddbc;
            if (t != 0)
                delete (char *)f_15c330(t, 1);
        }
        f_156c38();
        d_1cddf0 = 0;
        d_1cddbc = f_15928c(&cx, d_1cddc0, d_1cddc4);
        d_1bde24 = f_158128(d_1cddbc, 0, 0xffffff);
        d_1bde28 = z8_1581c8(d_1cddbc, 0, 0xffffff);
    }
    items494(d_1cddbc, r);
    --d_1cddb0;
}
void f_15ae98(int p1, int p2, int *p3)
{
    if (d_1cddc0 == 0)
        return;
    d_1cddf4 = d_1bde2c;
    d_1cddf8 = d_1bde30;
    if (d_1cddb4 != d_1cddf4) {
        d_1cddb4 = d_1cddf4;
        d_1cddb8 = d_1cddf8;
        d_1cddc8 = 1;
    }
    f_09e1b0();
    f_09dbe0(-p1, -p2);
    Rc494 r(p3[0] + p1, p3[1] + p2, p3[2] + p1, p3[3] + p2);
    draw494(&r.x1);
    f_09dbe0(0, 0);
}
