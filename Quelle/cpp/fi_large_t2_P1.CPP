/* === Beschreibung (Katalog) ===
 * Einheit fi_large_t2 (079e80 - 07a470)
 *
 * Überblick
 * Der zweite Teil von fi_large erzeugt die mehrteiligen Kampf-Animationssequenzen (Cmd-Strukturen der Größe 0xa4
 * Bytes) für die Angriffe, Geschosse und Spezialaktionen übergroßer Gegner (f_079e80, f_079f70, f_07a2b0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 1/3 gleich (suche.py 26.10.2026, Basis fi_large_t2_P1.CPP)
// fi_large.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0789B0-0x07A470
#include <string.h>
#include "RIVAMEM.H"

int f_02ffa0(int p1);
int f_038be0(int p1);
int f_038c80(int p1);
int f_0391b0(int p1, int p2);
int f_043450(int p1);
int f_043460(int p1, int p2);
int f_043dc0(int p1);
int f_044300(int p1, int p2);
int f_069460();
int f_069be0(int p1);
int f_06a6c0(int p1, int p2);
int f_06a6e0(int p1, int p2, int p3);
int f_06c930(int p1, int p2, int p3, int p4, int p5);
int f_06d580(int p1, int p2, int p3);
int f_06daa0(int p1, int p2, int p3);
int f_06ed10(int p1, int p2, int p3);
int f_06efc0(int p1, int p2, int p3, int p4);
int f_06f690(int p1, int p2, int p3);
int f_0729c0(int p1);
int f_0735b0(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0757f0(int p1);
int f_0758b0(int p1);
int f_075f10(int p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0765a0(int p1);
int f_07b540();
int f_07bd30(int p1, int p2, int p3);
int f_07beb0(int p1, int p2, int p3, int p4);
int f_07eba0(int p1, int p2, int p3);
int f_09c780(int p1);
int f_09c800(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09c990(int p1);
int f_0bf730(int p1, int p2);
int f_0cfa10(int p1);
int f_0cfc60(int p1, int p2);
int f_0cfc70(int p1);
int f_0cfcb0(int p1, int p2);
int f_0cfce0(int p1);
int f_0cfcf0(int p1, int p2);
int f_0cfd10(int p1, int p2);
int f_0cfd30(int p1, int p2);
int f_0cfd70(int p1);
int f_0cfd90(int p1, int p2);
int f_0cfdd0(int p1, int p2);
int f_0d0160(int p1);
int f_0d08e0(int p1, int p2);
int f_0d0bb0(int p1, int p2, int p3);
int f_0d10c0(int p1, int p2);
int f_0d11e0(int p1);
int f_0d4a10(int p1);
int f_0de4d0(int p1);
int f_133fe0(int p1, int p2);
extern int d_1a1d84;
extern int d_1a1d98;
extern int d_1a1e44;
extern int d_1a1e80;
extern int d_1a1e9a;
extern int d_1bc8f0;
extern int d_1bd90c;
extern int d_1bd918;
extern int d_1bd928;
extern int d_1bd984;
extern int d_1bda60;
extern int d_1bda64;
extern int d_1bda74;
extern int d_1bda78;
extern int d_1bda94;
extern int d_1bda98;
extern int d_1bda9c;
extern int d_1bdaa0;
extern int d_1bdaa4;
extern int d_1bdaa8;
extern int d_1bdaac;
extern int d_1c0004;
extern int d_1c0424;
extern int d_1c21b4;
extern int d_1c2c64;
extern int d_1c2d1c;
extern int d_1c3498;
extern unsigned short d_1c38b0;
extern const char d_1a1d64[];

unsigned char f_0cf930(int p1);

#pragma pack(1)
struct Ent { char a, b, c, d; };
struct Cmd { int w0; short *w4; int w8; Ent e[38]; };
struct Q { char pad[15]; int w; };
struct E40 { short x, y; int rest[9]; };
struct P4 { short x, y; };
extern short d_1a2744, d_1a2746;
int f_014540(int p1, int p2, int p3);
int f_0e9300(int p1, int p2, int p3);
short f_1457e0(int p1);
signed char f_0d0710(int p1);
int f_0d0a60(int p1, int p2);
int f_0d04e0(int p1);
int f_0d08a0(int p1);
unsigned char f_0d54c0(int p1);
int f_0728f0(int p1);
unsigned char f_07ec10(int p1, int p2);
int f_071e90(int p1, int p2, int p3);
int f_06f5c0(int p1, int p2, int p3);
int f_0cdd50(short p1, short p2, short p3, short p4, short *p5);
int f_0708f0(int p1);
int f_069a00(int p1, void *p2);
int f_06a600(int p1, int p2);
int f_072940(int p1);
#define C72940(x) f_072940(x)
unsigned char f_0cfc50(int p1);
#define C0CFC50(x) f_0cfc50(x)
int f_07ea60(int p1, int p2);
#define LOCALS short a, q, n, b, x1, v, u;

//@ f_079e80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die Animationssequenz für die Ruhe- oder Spezialregeneration eines Großgegners p2 auf.
 *   Bei bestimmten Großgegnern (f_0d0710) besteht eine 15-prozentige Chance, dass statt der normalen Animation
 *   (0x1e) eine besondere Regenerationsaktion (0x1f) ausgelöst wird, die eine Textmeldung ausgibt und dem Gegner
 *   über f_0d0a60 1..30 Astralpunkte regeneriert.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2, den Befehlszeiger p3 (Cmd *) sowie
 *   einen ungenutzten Parameter p4 und gibt das Animations-Objekthandle o->w (int) zurück.
 * - Wichtige Variablen: Beschreibt die 0xa4 Byte große Animations-Kommandostruktur p3 und übergibt sie an
 *   f_069a00.
 === Ende Beschreibung === */
int f_079e80(int p1, int p2, Cmd *p3, int p4)
{
    int f_0d0710_only(int);
#pragma aux f_0d0710_only "f_0d0710" modify [eax edx]
    short s;
    Q * o = (Q *)f_07ea60(p1 + 0x39, C0CFC50(p2));
    short n;
    n = 0;
    if (f_0d0710_only(p2) && f_1457e0(100) <= 15) {
        s = 0x1f;
        do {
        if (**(char **)(p1 + 0xc)) {
            f_0e9300((int)&d_1c38b0, *(int *)(p1 + 0xc), 0x2000016f);
            f_0e9300((int)&d_1c38b0, *(int *)(p1 + 0xc), 0x2000016f);
        }
        } while (0);
        f_0e9300((int)&d_1c38b0, *(int *)(p1 + 0xc), 0x1700010e);
        f_0d0a60(p2, f_1457e0(0x1e));
    } else {
        s = 0x1e;
    }
    memset(p3, 0, 0xa4);
    p3->w0 = f_0728f0(p2);
    p3->e[n].a = (signed char)s; p3->e[n].b = 0;
    ++n;
    p3->e[n].a = (signed char)0xff;
    f_069a00(o->w, p3);
    return o->w;
}

//@ f_079f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt die Kampfanimation für den Zauber- oder Fernangriff (0x77) eines Großgegners p2.
 *   Handelt es sich um einen der großen Endgegner (f_0d0710 oder f_0d04e0), wird zusätzlich ein fliegendes
 *   Projektil-Objekt ob (f_0708f0) entlang einer mit f_0cdd50 berechneten Flugbahn zum Zielhelden erzeugt und in
 *   die Renderliste p1 + 0x39 eingehängt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 und den Befehlszeiger p3 (Cmd *)
 *   und gibt das Handle des Projektil- oder Monster-Animationsobjekts (int) zurück.
 * - Wichtige Variablen: Berechnet die Flugbahn in src (jeder 10. Punkt wird nach dst übernommen) und verknüpft
 *   das Projektil über p3->w8 = ob.
 === Ende Beschreibung === */
int f_079f70(int p1, int p2, Cmd *p3)
{
    int f_0d0710_i(int);
#pragma aux f_0d0710_i "f_0d0710"
    short step;
    Cmd t;
    short a, q, n, x2, u;
    int ob = 0;
    Q *bq;
    P4 *dst;
    short i;
    n = 0;
    f_07ea60(p1 + 0x39, C0CFC50(p2));
    memset(p3, 0, 0xa4);
    p3->w0 = f_0728f0(p2);
    p3->e[0].a = 0x77;
    p3->e[0].b = 0;
    if (f_0d0710_i(p2) || f_0d04e0(p2)) {
        P4 *src;
        short cnt, y1, b, v, y2, x1;
        f_071e90((unsigned char)(f_0d54c0(f_0d08a0(p2)) + 1), (int)&b, (int)&a);
        if (f_0d0710_i(p2)) { u = 8; v = 0xc; } else { u = 9; v = 0xb; }
        src = (P4 *)f_014540(0x514, (int)d_1a1d64, 0x44f);
        x1 = d_1a2744 + (u + v) * 10;
        y1 = d_1a2746 + (u - v) * 5;
        x2 = d_1a2744 + (b + a) * 10;
        y2 = d_1a2746 + (b - a) * 5;
        cnt = f_0cdd50(x1, y1, x2, y2, (short *)src) - 1;
        step = 10;
        q = cnt / step;
        dst = (P4 *)f_014540(q * 4, (int)d_1a1d64, 0x45b);
        for (i = 0; i < q; i++) {
            dst[i].x = src[i * step].x;
            dst[i].y = src[i * step].y;
        }
        delete src;
        memset(&t, 0, 0xa4);
        ob = f_0708f0(p1);
        t.w0 = f_0728f0(p2);
        t.w4 = (short *)dst;
        t.e[0].a = (char)0xef; t.e[0].b = 3; t.e[0].c = (char)q; t.e[0].d = 0x1d;
        *(int *)(p1 + 0x27) = ob;
        *(char *)(p1 + 0x1f) = (char)u;
        *(char *)(p1 + 0x18) = *(char *)(p1 + 0x1f);
        *(char *)(p1 + 0x20) = (char)v;
        *(char *)(p1 + 0x19) = *(char *)(p1 + 0x20);
        *(char *)(p1 + 0x24) = 0;
        *(int *)(p1 + 0x1a) = f_0728f0(p2);
        *(int *)(p1 + 0x2b) = 0;
        *(char *)(p1 + 0x22) = (char)0xfe;
        *(char *)(p1 + 0x23) = 1;
        *(char *)(p1 + 0x25) = (char)0xff;
        f_07ec10(p1 + 0x39, -1);
        f_069a00(ob, &t);
        f_06a600(ob, 0);
        p3->w8 = ob;
        // Haelt die Stapelslot-Sortierung fuer i wie im Original.
        (void)(signed char)i;
    }
    n++; p3->e[n].a = 1; p3->e[n].b = 0; p3->e[n].c = 1; n++; p3->e[n].a = (char)0xff;
    bq = (Q *)f_07ea60(p1 + 0x39, C0CFC50(p2));
    f_069a00(bq->w, p3);
    return ob ? ob : bq->w;
}

//@ f_07a2b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt die Animationssequenz (0x87) für den Atem- oder Fernangriff eines Großgegners p2. Beim
 *   Riesendrachen (f_0cf930(p2) == 'R') wird zusätzlich ein stationäres Effekt-Animationsobjekt ob (Kommando
 *   0xa7 an den Bildschirmkoordinaten 0xc5, 0x4a, Rasterfeld 16, 12) für die Feueratem-Wolke angelegt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 und den Befehlszeiger p3 (Cmd *)
 *   und gibt das Handle des Effekt- oder Monster-Animationsobjekts (int) zurück.
 * - Wichtige Variablen: Prüft über f_072940(p2) die Handlungsfähigkeit und fällt andernfalls auf die
 *   Ruheanimation f_06f5c0 zurück.
 === Ende Beschreibung === */
int f_07a2b0(int p1, int p2, Cmd *p3)
{
    short n = 0;
    int ob = 0;
    Q *bq;
    if (C72940(p2)) {
        short *buf;
        short i;
        Cmd t;
        memset(p3, 0, 0xa4);
        p3->w0 = f_0728f0(p2);
        p3->e[0].a = (char)0x87;
        p3->e[0].b = 0;
        if (f_0cf930(p2) == 0x52) {
            buf = (short *)f_014540(0x50, (int)d_1a1d64, 0x4b1);
            for (i = 0; i < 20; i++) { buf[i * 2] = 0xc5; buf[i * 2 + 1] = 0x4a; }
            memset(&t, 0, 0xa4);
            ob = f_0708f0(p1);
            t.w0 = f_0728f0(p2);
            t.w4 = buf;
            t.e[0].a = (char)0xa7; t.e[0].b = 0; t.e[0].d = 0x1d;
            *(char *)(p1 + 0x1f) = 0x10;
            *(char *)(p1 + 0x20) = 0xc;
            *(int *)(p1 + 0x27) = ob;
            *(char *)(p1 + 0x18) = *(char *)(p1 + 0x1f);
            *(char *)(p1 + 0x19) = *(char *)(p1 + 0x20);
            *(char *)(p1 + 0x24) = 0;
            *(int *)(p1 + 0x1a) = f_0728f0(p2);
            *(int *)(p1 + 0x2b) = 0;
            *(char *)(p1 + 0x22) = 0x63;
            *(char *)(p1 + 0x23) = 1;
            *(char *)(p1 + 0x25) = (char)0xff;
            f_07ec10(p1 + 0x39, -1);
            f_069a00(ob, &t);
            f_06a600(ob, 0);
            p3->w8 = ob;
        }
        n++; p3->e[n].a = 1; p3->e[n].b = 0; p3->e[n].c = 1; n++; p3->e[n].a = (char)0xff;
        bq = (Q *)f_07ea60(p1 + 0x39, C0CFC50(p2));
        f_069a00(bq->w, p3);
        return ob ? ob : bq->w;
    }
    return f_06f5c0(p1, p2, (int)p3);
}
