/* === Beschreibung (Katalog) ===
 * Einheit options_t2 (0d87e0 - 0d99d0)
 *
 * Überblick
 * Die Einheit options_t2 enthält den zweiten Teil des ursprünglichen Moduls options.cpp. Sie implementiert die
 * Aktions- und Zeichenroutinen für die einzelnen Steuerelemente des Optionsmenüs (Umschalter, Zahlenregler,
 * Aktionsschaltflächen wie Laden/Speichern/Standard/Intro-Video) sowie das Zeichnen des gesamten
 * Optionsbildschirms.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMOUS.H"
#include "RIVAFILE.H"
// P3 4/11 gleich (suche.py 26.10.2026, Basis options_t2_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 826 (vorher 828)
// options.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D87E0-0x0D99D0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bios.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
int f_012700(int p1, int p2);
int f_012870(int p1, int p2);
int f_014540(int p1, const char *p2, int p3);
int f_02de20(int p1, int p2);
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
int f_050580(int p1, int p2, int p3, short *p4, short *p5);
int f_05e320(int p1, int p2, int p3);
int f_09a0d0(int p1);
int f_09a120(int p1, int p2);
int f_09a140(int p1, int p2);
signed char f_0bd350(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820();
int f_0bf8e0();



int f_0d3f25(int p1, int p2);
int f_0d4070(int p1);
int f_0d451f(int p1, int p2, const char *p3);
int f_0d4800(int p1);
int f_0e9510(int p1, int p2, int p3, int p4);
unsigned short f_0e95d0(int p1, int p2, int p3, int p4);





int f_10a8b0(int p1);
int f_10a940(int p1);
int f_10a980(int p1, int p2, int p3);
int f_10aad0(int p1, const char *p2, int p3, int p4);
int f_10ac80(int p1);
int f_10ae20(int p1, int p2, int p3);
int f_125400(int p1, int p2, int p3);
int f_1254a0(int p1, int);
int f_133fe0(int p1, int p2);



int f_145a20(int p1, int p2, int p3, int p4);
int f_146dfa(int p1, int p2);
int f_147b97(int p1, int p2, int p3);
int f_147c02(int p1, int p2);
void f_0d9cb0();
struct Ent { signed char v; int s; };
struct Item { short x; short y; signed char t; signed char kind; signed char *val; int text; int h; struct Ent e[5]; };
struct Pr { signed char *p; signed char d; };
struct B10 { char c[10]; };
extern struct Item d_1a5b88[];
extern struct Pr d_1a5afc[];
extern struct B10 d_1bfda8;
extern char *d_1a34e0;
extern char *d_1a5aec;
extern char *d_1a965c;
extern short d_1a5af4, d_1a5af6, d_1a5afa;
extern short d_1bf51c, d_1bd766, d_1bfac8, d_1bfb3e, d_1bfb4c, d_1bfb54;
extern short d_1bfb38[];
extern short d_1bfb4e[];
extern int d_1bfad0, d_1bfdb4, d_1bfb34, d_1c2a80;
extern int d_1c3908;
extern signed char d_1bfb0c, d_1bfb08, d_1bfb18, d_1bfb1c, d_1bfb24, d_1bfb10, d_1bfb14, d_1bfae0, d_1bfae4;
extern char d_1c2edc[], d_1c2e78[], d_1c2be0[], d_1c38b0[], d_1c3498[], d_1c2c64[], d_1c349c[], d_1c3870[], d_1bfad4[];
extern const char d_1a5acc[], d_1b8284[], d_1b8291[], d_1b829f[];
void f_0d78c0(int p1, int p2);
void f_0d9b20(int p1);
void f_0d9670(int p1, int p2);
void f_0d97b0(int p1);
void f_0d99d0(int p1, struct Item *p2, short p3, int p4);
void f_0d98c0(int p1, struct Item *p2, short p3, int p4);

#define FLAG_BEGIN RivaMouseGuard mg;
#define DELP(x) operator delete((void *)(x));
#define FREEOBJ(p1) if (*(int *)((p1) + 0x111) != 0) DELP(((int)(((RivaRasterImage*)(*(int *)((p1) + 0x111)))->f_0fad20( 0))))
#define LOOP1 for (i = 0; i < 0x26; i++) { struct Item *it = &d_1a5b88[i]; if (it->kind == 1) f_0d99d0(p1, it, i, 1); else if (it->kind == 3) f_0d98c0(p1, it, i, 1); }
#define RESET i = 0; do { *d_1a5afc[i].p = d_1a5afc[i].d; i++; } while (i < 0x19);
#define OQ (*(int *)(o + 0x14))
#define FLUSH(p1) d_1bf51c = 0; if (*(int *)((p1) + 0x111) != 0) { FLAG_BEGIN ((RivaRasterImage*)(*(int *)((p1) + 0x111)))->f_0fade0((void *)( (int)d_1a34e0), d_1a5b88[d_1a5afa].x, d_1a5b88[d_1a5afa].y); FREEOBJ(p1); *(int *)((p1) + 0x111) = 0; } d_1bf51c = 1;

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0d87e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Spielt über die entsprechende Schaltfläche im Optionsmenü das Intro-Video CHAPT00S.SMK (d_1b8284)
 *   im hochauflösenden VESA-Modus (640x480) mittels Smacker-Player ab, schaltet danach zurück auf 320x200 und
 *   zeichnet das Optionsmenü samt Hintergrundmusik neu.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d87e0(int p1)
{
    int t = (int)operator new(0x76, mark(d_1a5acc, 0x38b));
    int s = t ? f_10a940(t) : t;
    FLAG_BEGIN
    f_0d4070((int)d_1c2e78);
    f_09a0d0((int)d_1a34e0);
    f_10a980(s, 0x280, 0x1e0);
    d_1bfdb4 = 0;
    int h = f_147b97((int)d_1c2edc, 1, (int)f_0d9cb0);
    signed char c;
    do {
        f_146dfa((int)d_1c2edc, 1);
        c = d_1bfb0c;
        if (c == d_1bfdb4) break;
    } while (1);
    f_147c02((int)d_1c2edc, h);
    if (f_10aad0(s, d_1b8284, -1, -1) == 1) {
        f_10a8b0(s);
        d_1bd766 = f_10ae20(s, 0, 0);
        while (!_bios_keybrd(_KEYBRD_READY)) ;
        _bios_keybrd(_KEYBRD_READ);
        f_10ac80(s);
    }
    f_10a980(s, 0x140, 200);
    f_0d9670(p1, 1);
    f_0d3f25((int)d_1c2e78, 4);
    DELP(s)
}

//@ f_0d8950
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schaltet ein Mehrstufen-Optionsfeld (Typ 1, z. B. Ein/Aus oder Detailstufen) auf den nächsten
 *   gültigen Wert weiter, führt vor dem Aktivieren von CD-/Festplatten-Optionen (p3 == 2 oder 4) eine
 *   CD-ROM-Prüfung (d_1c3908) sowie einen Geschwindigkeitstest auf DATA\SEQS.ALF (f_0d451f) durch, zeichnet die
 *   Schaltfläche neu und übernimmt die Änderung über f_0d78c0.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2) sowie der Feldindex (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
// BLIND: f_0d8950 hier komplett neu aus dem Original-Assembler schreiben (orig.sh options_t2 f_0d8950).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
typedef RivaTextContextData Ctx;
typedef int (*CtxNew)(void *, void *, void *, void *);
typedef int (*CtxDel)(void *, int);
void f_0d8950(int p1, struct Item *p2, short p3)
{
    Ctx c;
    short idx;
    int ok = 1;
    ((CtxNew)f_125400)(&c, d_1c349c, d_1c3870, d_1c3498);
    for (short i = 0; i < 4; i++) {
        if (*p2->val == p2->e[i].v) {
            if (i == 3 || p2->e[i + 1].v == -1) idx = 0;
            else idx = i + 1;
            break;
        }
    }
    signed char n;
    if ((p3 == 2 || p3 == 4) && p2->e[idx].v == 1 && d_1c3908 == 0) {
            ((int (__cdecl *)(int,int,int,int,int))f_0bf8e0)((int)d_1c2c64, 0, 0, 0x18030045, 0);
            ok = 0;
        } else if (p3 == 2 && p2->e[idx].v == 1 && (n = d_1bfb24) <= 0x23) {
            c.tables.tail.short_numbers[1] = n * 10;
            c.tables.tail.short_numbers[2] = 0x15e;
            if (((short (__cdecl *)(int,int,int,int,int))f_0bf820)((int)d_1c2c64, 0x18030046, 2, 0x18030047, 0x18030048) == 2) {
                f_0bf730((int)d_1c2c64, 0x200001c6);
                signed char v = (signed char)f_0d451f((int)d_1c2e78, 0x14, d_1b8291);
                d_1bfb24 = v;
                if (v <= 0x23) {
                    c.tables.tail.short_numbers[1] = v * 10;
                    ((int (__cdecl *)(int,int,int,int,int))f_0bf8e0)((int)d_1c2c64, 0, 0, 0x1803004a, 0);
                    ok = 0;
                }
            } else ok = 0;
        } else if (d_1bfad0 == 0 && p3 == 0xa) ok = 0;
    if (ok) {
        int q = p1;
        signed char v = p2->e[idx].v;
        *p2->val = v;
        d_1bf51c = 0;
        if (*(int *)(q + 0x111)) {
            unsigned fl;
            if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
            int k = d_1a5afa;
            Item *table = d_1a5b88;
            int off = k * 0x2b;
            int y = *(short *)((char *)table + off + 2);
            int x = *(short *)((char *)table + off);
            ((RivaRasterImage*)(*(int *)(q + 0x111)))->f_0fade0((void *)( (int)d_1a34e0), x, y);
            int obj = *(int *)(q + 0x111);
            if (obj) operator delete((void *)((int)(((RivaRasterImage*)(obj))->f_0fad20( 0))));
            *(int *)(q + 0x111) = 0;
            if ((*&fl) == 1) f_0d26e0();
        }
        *(volatile short *)&d_1bf51c = 1;
        f_0d99d0(p1, p2, (p3 & 0) ? 0 : p3, 0); // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        f_0d9b20(p1);
    }
    f_0d78c0(p1, (int)p2->val);
    if (p2->val == &d_1bfb08 || p2->val == &d_1bfb18 || p2->val == &d_1bfb1c)
        f_0d97b0(p1);
    ((CtxDel)f_1254a0)(&c, 0);
}


//@ f_0d8c00
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Erhöht oder verringert den Wert eines numerischen Optionsreglers (Typ 3, z. B. Lautstärke,
 *   Sichtweite oder Seitenlänge) um die hinterlegte Schrittweite (p2->e[2].v), begrenzt das Ergebnis mittels
 *   f_0bd350 auf das Intervall [min, max], zeichnet den Regler über f_0d98c0 neu und wendet den geänderten Wert
 *   über f_0d78c0 an.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2) sowie der Zonenindex (p3, wobei < 0x26 für Verringern und >= 0x26 für Erhöhen
 *   steht).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d8c00(int p1, struct Item *p2, short p3)
{
    signed char mx = p2->e[1].v;
    signed char mn = p2->e[0].v;
    signed char st = p2->e[2].v;
    signed char old = *p2->val;
    struct { signed char v; } cell;
    if (p3 < 0x26) st = -st;
    cell.v = old + st;
    signed char result;
    signed char *pnw = &cell.v;
    result = f_0bd350(*pnw, mn, mx);
    p2 = ((int)p2 & 0) ? 0 : p2; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
    signed char *dest = p2->val;
    {
        int q = p1;
        cell.v = result;
        *dest = result;
        d_1bf51c = 0;
        if (*(int *)(q + 0x111)) {
            unsigned fl;
            if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
            int k = d_1a5afa;
            Item *t = (Item *)((char *)d_1a5b88 + k * 0x2b);
            ((RivaRasterImage*)(*(int *)(q + 0x111)))->f_0fade0((void *)( (int)d_1a34e0), t->x, t->y);
            int obj = *(int *)(q + 0x111);
            if (obj) operator delete((void *)((int)(((RivaRasterImage*)(obj))->f_0fad20( 0))));
            *(int *)(q + 0x111) = 0;
            if ((*&fl) == 1) f_0d26e0();
        }
    }
    *(volatile short *)&d_1bf51c = 1;
    f_0d98c0(p1, p2, p3, 0);
    f_0d9b20(p1);
    if (cell.v != old) f_0d78c0(p1, (int)p2->val);
}

//@ f_0d8d20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt eine Aktionsschaltfläche (Typ 2) im Optionsmenü nach einer Sicherheitsabfrage (f_0bf6f0) aus:
 *   setzt bei Index 0 alle Optionen auf Standardwerte zurück, spielt bei Index 0x23 das Intro-Video (f_0d87e0)
 *   ab, lädt bei Index 0x24 die Datei RIVA.CFG neu und speichert bei Index 0x25 die aktuellen Einstellungen in
 *   RIVA.CFG.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2) sowie der Schaltflächenindex (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d8d20(int p1, struct Item *p2, unsigned short p3)
{
    void f_0d99d0(int, Item *, int, int);
#define R4RESET i = 0; do { *d_1a5afc[i].p = d_1a5afc[i].d; i++; } while (i < (short)0x19);
#define R4LOOP for (i = 0; i < 0x26; i++) { Item *it = &d_1a5b88[i]; int kind = it->kind; if (kind == 1) f_0d99d0(p1, it, i, 1); else if (kind == 3) f_0d98c0(p1, it, i, 1); }
    short i;
    signed char v10, v14;
    struct { int guard, key, saved; } frame;
    frame.saved = p1;
    d_1bf51c = 0;
    if (*(int *)(frame.saved + 0x111)) {
        if (f_0d3860() == 1) { f_0d2710(); frame.guard = 1; } else frame.guard = 0;
        d_1bfdb4 = (d_1bfdb4 & 0) ? 0 : d_1bfdb4; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        int k = d_1a5afa;
        Item *table = d_1a5b88;
        int off = k * 0x2b;
        int y = *(short *)((char *)table + off + 2);
        int x = *(short *)((char *)table + off);
        ((RivaRasterImage*)(*(int *)(frame.saved + 0x111)))->f_0fade0((void *)( (int)d_1a34e0), x, y);
        int obj = *(int *)(frame.saved + 0x111);
        if (obj) operator delete((void *)((int)(((RivaRasterImage*)(obj))->f_0fad20( 0))));
        *(int *)(frame.saved + 0x111) = 0;
        if (frame.guard == 1) f_0d26e0();
    }
    *(volatile short *)&d_1bf51c = 1;
    int key = frame.key = (short)p3;
    f_0d99d0(p1, p2, key, 0);
    f_0d9b20(p1);
    if (key == 0x23 && (v10 = d_1bfb10) == 0 && (v14 = d_1bfb14) == 0) {
        ((int (__cdecl *)(int,int,int,int,int))f_0bf8e0)((int)d_1c2c64, 0, 0, 0x18030049, 0);
    } else {
        if (f_0bf6f0((int)d_1c2c64, p2->h) == 1) {
        switch (p3) {
        case 0x24: {
            int q = p1;
            d_1a965c = d_1a5aec;
            if (((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448b0( 0, 0x200) == 1) {
                f_012700((int)d_1bfad4, (int)((char*)&d_1c2098));
                ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1449a0();
                if (d_1bfb34 == 1) {
                    if (d_1bfad0 == 0) d_1bfae0 = 0;
                    R4LOOP
                    f_0d97b0(p1);
                    f_0d78c0(q, 0);
                    return;
                } else {
                    if (d_1bfad0 == 0) d_1bfae0 = 0;
                    f_0d78c0(q, 0);
                    return;
                }
            } else {
                R4RESET
                if (d_1bfb34 == 1) {
                    p1 = q;
                    if (d_1bfad0 == 0) f_02de20((int)&d_1bfae0, 0);
                    R4LOOP
                    f_0d97b0(p1);
                    f_0d78c0(q, 0);
                    return;
                } else if (d_1bfad0 == 0) d_1bfae0 = 0;
            }
            return;
        }
        case 0x25:
            d_1a965c = d_1a5aec;
            ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_144890( 0);
            f_012870((int)d_1bfad4, (int)((char*)&d_1c2098));
            ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1449a0();
            return;
        case 0: {
            int q = p1;
            R4RESET
            if (d_1bfb34 == 1) {
                p1 = q;
                if (d_1bfad0 == 0) d_1bfae0 = 0;
                R4LOOP
                f_0d97b0(p1);
                f_0d78c0(q, 0);
                return;
            }
            if (d_1bfad0 == 0) {
                d_1bfae0 = 0;
                return;
            }
            break;
        }
        case 0x23:
            f_0d87e0(p1);
            return;
        }
        }
    }
#undef R4RESET
#undef R4LOOP
}

//@ f_0d90e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Gibt eine Beschriftung oder einen Werttext im Optionsmenü mit dunklem Schattenversatz (+1 Pixel in
 *   X-Richtung, Farbe d_1bfac8) und wählbarer Vordergrundfarbe (d_1a5af6 oder d_1a5af4) auf dem Bildschirm aus.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), die Textkennung (p2), die X- und
 *   Y-Koordinaten (p3, p4) sowie der Farbmodus (p5).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d90e0(int p1, int p2, short p3, short p4, int p5)
{
    FLAG_BEGIN
    f_05e320((int)d_1c38b0, d_1bfac8, -1);
    f_0e9510((int)d_1c38b0, p2, (short)(p3 + 1), p4);
    f_05e320((int)d_1c38b0, p5 == 1 ? d_1a5af6 : d_1a5af4, -1);
    f_0e9510((int)d_1c38b0, p2, p3, p4);
}

//@ f_0d9190
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt für ein Umschalt-Optionsfeld (d_1a5b88[p2]), welcher der bis zu 4 Auswahleinträge
 *   (e[0..3].v) dem aktuellen Wert der Optionsvariable (*it->val) entspricht, und setzt die Variable bei einem
 *   ungültigen Wert zuvor auf ihren Standardwert aus d_1a5afc zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1) sowie der Index des Optionsfelds (p2).
 * - Rückgabewert: Gibt den gefundenen Auswahlindex (0..3) oder -1 zurück.
 === Ende Beschreibung === */
// Demo: Getter/Setter-Aufrufe (call 0x13650 / 0x13620), im Original inline.
static inline signed char get_sb(signed char *p) { return *p; }
static inline void set_sb(signed char *p, signed char v) { *p = v; }
signed char f_0d9190(int p1, short p2)
{
    signed char r = -1;
    struct Item *it = &d_1a5b88[p2];
    short i;
    for (i = 0; i < 4; i++) {
        if (get_sb(it->val) == it->e[i].v) {
            r = i;
            break;
        }
    }
    if (r == -1) {
        short k;
        for (k = 0; k < (short)0x19; k++) {
            if (it->val == d_1a5afc[k].p) {
                set_sb(d_1a5afc[k].p, d_1a5afc[k].d);
                for (i = 0; i < 4; i++) {
                    int scale = (int)i * 5;
                    if (((Ent *)((char *)it->e + scale))->v == get_sb(it->val)) {
                        r = i;
                        break;
                    }
                }
            }
        }
    }
    return r;
}

//@ f_0d9250
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet den Text bzw. Zahlenwert eines einzelnen Optionsfelds je nach Feldtyp (kind == 0:
 *   Überschrift/Label, kind == 1: aktueller Auswahltext, kind == 2: Aktionsknopf-Text, kind == 3: Zahlenwert
 *   oder Verhältnis %d/%d bei d_1bfae4) zentriert in das zugehörige Steuerelement.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2) sowie der Feldindex (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9250(int p1, struct Item *p2, short p3)
{
    int token_133fe0(void *, void *);
#pragma aux token_133fe0 "f_133fe0" parm [eax] [edx] value [eax] modify exact [eax edx];
    B10 b = d_1bfda8;
    int h = token_133fe0(d_1c3498, &b);
    int t; short a, y;
    h = (h & 0) ? 0 : h; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
    h = (h & 0) ? 0 : h; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
    unsigned char kind = (unsigned char)p2->kind;
    switch (kind) {
    case 0:
        { unsigned char rt_case0_0=*(unsigned char *)&d_1bfb3e; *(unsigned char *)&d_1bfb3e=rt_case0_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original

            kind = (kind & 0) ? 0 : kind; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
            kind = (kind & 0) ? 0 : kind; // haelt die Register- und Stapelplatz-Reihenfolge wie im Original

        f_0d90e0(p1, p2->text, p2->x + 2, p2->y + 2, 0);
        break;
    case 1:
        

        t = p2->e[f_0d9190(p1, p3)].s;
        a = f_0e95d0((int)d_1c38b0, t, p2->x, d_1bfb38[p2->t]);
        { short rt_case1_xy_0=d_1bfb4c; d_1bfb4c=rt_case1_xy_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        
        { unsigned char rt_case1_xy_2=*(unsigned char *)&d_1bfb3e; *(unsigned char *)&d_1bfb3e=rt_case1_xy_2; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case1_xy_3=d_1bfad0; d_1bfad0=rt_case1_xy_3; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { unsigned char rt_case1_xy_4=*(unsigned char *)&d_1bfac8; *(unsigned char *)&d_1bfac8=rt_case1_xy_4; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        y = (d_1bfb4e[p2->t] - 8) / 2 + p2->y;
        f_0d90e0(p1, t, a, y, 1);
        break;
    case 2:
        { int rt_case2_0=d_1bfad0; d_1bfad0=rt_case2_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case2_1=d_1bfdb4; d_1bfdb4=rt_case2_1; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { unsigned char rt_case2_2=*(unsigned char *)&d_1bfb3e; *(unsigned char *)&d_1bfb3e=rt_case2_2; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case2_3=d_1bfb34; d_1bfb34=rt_case2_3; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original

        a = f_0e95d0((int)d_1c38b0, p2->text, p2->x, d_1bfb38[p2->t]);
        y = (d_1bfb4e[p2->t] - 8) / 2 + p2->y;
        f_0d90e0(p1, p2->text, a, y, 1);
        break;
    case 3:
        { int rt_case3_0=d_1bfad0; d_1bfad0=rt_case3_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case3_1=d_1bfdb4; d_1bfdb4=rt_case3_1; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case3_2=d_1bfb34; d_1bfb34=rt_case3_2; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case3_3=d_1c2a80; d_1c2a80=rt_case3_3; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        { int rt_case3_4=d_1c3908; d_1c3908=rt_case3_4; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original

        if (p2->val == &d_1bfae4)
            sprintf((char *)&b, d_1b829f, 100 - (int)get_sb(p2->val), (int)get_sb(p2->val));
        else
            itoa((int)get_sb(p2->val), (char *)&b, 10);
        t = h;
        a = f_0e95d0((int)d_1c38b0, t, (short)(p2->x + d_1bfb3e + 2), d_1bfb4c) - 1;
        y = (d_1bfb54 - 8) / 2 + p2->y;
        { int rt_case3_draw_0=d_1bfad0; d_1bfad0=rt_case3_draw_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        
        { short rt_case3_draw_2=d_1bfb4c; d_1bfb4c=rt_case3_draw_2; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        f_0d90e0(p1, t, a, y, 1);
        { int rt_end_0=d_1bfad0; d_1bfad0=rt_end_0; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        
        { short rt_end_2=d_1bfb4c; d_1bfb4c=rt_end_2; } // haelt die Register- und Stapelplatz-Reihenfolge wie im Original
        break;
    }
}
//@ f_0d9670
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Lädt das Hintergrundbild des Optionsmenüs (0x80180000), zeichnet die Beschriftungen und Werte
 *   sämtlicher 38 Optionsfelder über f_0d9250 sowie das 3D-Vorschau-Symbol über f_0d97b0 und blendet bei
 *   Erstaufruf (p2 == 1) die Palette weich ein.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1) sowie ein Flag für das Einblenden der
 *   Palette (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9670(int p1, int p2)
{
    int p4 = 0;
    short i;
    if (p2 == 1) {
        p4 = f_014540(0x300, d_1a5acc, 0x4c0);
        f_09a140(0, 0x19);
    }
    FLAG_BEGIN
    d_1c2a80 = 0x180000;
    f_145a20(p1, 0x80180000, (int)d_1a34e0, p4);
    for (i = 0; i < 0x26; i++) f_0d9250(p1, &d_1a5b88[i], i);
    f_0d97b0(p1);
    if (p2 == 1) {
        f_09a120(p4, 0x19);
        DELP(p4)
    }
}

//@ f_0d9740
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet sämtliche Umschalter (Typ 1) und Zahlenregler (Typ 3) der 38 Optionsfelder sowie das
 *   Vorschau-Symbol (f_0d97b0) im Optionsmenü komplett neu.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9740(int p1)
{
    short i;
    if (d_1bfad0 == 0) d_1bfae0 = 0;
    LOOP1
    f_0d97b0(p1);
}

//@ f_0d97b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet im Optionsmenü an Position (23, 127) das passende Kombinations-Vorschaubild aus dem Archiv
 *   0x180001 (Sprite-Index 11..22), das die aktuell gewählte Kombination der drei
 *   Grafik-/3D-Darstellungsoptionen (d_1bfb08, d_1bfb18, d_1bfb1c) veranschaulicht.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d97b0(int p1)
{
    struct { int flag; short la, pad; int lb; short lc, pad2; } v;
    if (f_0d3860() == 1) { int one = 1; f_0d2710(); v.flag = one; } else { v.flag = 0; }
    signed char c0 = d_1bfb08;
    short base = c0;
    signed char c1 = d_1bfb18;
    short h = base + 0xb;
    if (c1 == 0) h += 3;
    signed char c2 = d_1bfb1c;
    if (c2 == 0) h += 6;
    f_050580((int)d_1c2be0, 0x180001, h, &v.la, &v.lc);
    int t = (int)operator new(9, mark(d_1a5acc, 0x507));
    int o = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( v.la, v.lc))) : t;
    f_04feb0((int)d_1c2be0, 0x180001, ((int)(((RivaRasterImage*)(o))->f_0fb0b0())), 0, h, 0, (int)&v.lb, (int)&v.lb, 0x140);
    ((RivaRasterImage*)(o))->f_0fade0((void *)( (int)d_1a34e0), 0x17, 0x7f);
    if (o) DELP(((int)(((RivaRasterImage*)(o))->f_0fad20( 0))))
    if (v.flag == 1) f_0d26e0();
}

//@ f_0d98c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet einen numerischen Optionsregler (Typ 3) samt Plus-/Minus-Pfeilknöpfen (bei p4 == 0 mit
 *   kurzer gedrückter Knopf-Animation und Klickgeräusch 7), Zahlenfeld-Hintergrund und aktuellem Werttext
 *   (f_0d9250).
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2), der Zonenindex (p3, < 0x26 links/Minus, >= 0x26 rechts/Plus) sowie das
 *   Stumm-/Direktzeichen-Flag (p4).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d98c0(int p1, struct Item *p2, short p3, int p4)
{
    short y, y4, x4, n, x;
    n = 3;
    x4 = 0;
    x = p2->x;
    y = p2->y;
    x4 = d_1bfb3e + x + 1;
    y4 = y;
    if (p3 >= 0x26) {
        n = 4;
        x = x4 + d_1bfb4c + 1;
    }
    volatile int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; }
    if (p4 == 0) {
        ((RivaRasterImage*)(*(int *)(p1 + n * 4 + 0xb7)))->f_0fae30((void *)( (int)d_1a34e0), x, y, 1);
        f_0d4800(7);
        ((RivaRasterImage*)(*(int *)(p1 + n * 4 + 0xa3)))->f_0fae30((void *)( (int)d_1a34e0), x, y, 1);
    }
    ((RivaRasterImage*)(*(int *)(p1 + 0xcb)))->f_0fae30((void *)( (int)d_1a34e0), x4, y4, 1);
    f_0d9250(p1, p2, p3);
    if (fl == 1) f_0d26e0();
}
