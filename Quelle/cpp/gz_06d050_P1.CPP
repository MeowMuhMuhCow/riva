/* === Beschreibung (Katalog) ===
 * Einheit gz_06d050 (0x06d050 - 0x06d580)
 *
 * Überblick
 * Die Einheit gz_06d050 enthält vier Animations-Aufbauroutinen für Kampffiguren: einfache Aktionssequenzen
 * (f_06d050), das Benutzen oder Werfen von Kampfgegenständen mit Effekt-Sprite (f_06d0d0) sowie
 * Treffer-/Sterbeeffekte für große oder spezielle Gegner (f_06d380, f_06d4a0).
 === Ende Beschreibung === */
// P1 2/3 gleich
// gz_06d050.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06D050-0x06D580
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"




// --- Typen ---
typedef short idx_t;
struct E { char a, b, c, d; };
struct R { int w0; int w4; int w8; E e[38]; };
struct Q { char pad[0xf]; int q; };
struct T {
    char pad0[0x18];
    unsigned char b18, b19;
    int d1a;
    char pad1;
    unsigned char b1f, b20;
    char pad2;
    unsigned char b22, b23, b24, b25;
    char pad3;
    int d27;
    int d2b;
    char pad4[10];
    char sub[1];
};
inline int NE(int a, int b) { return a != b; }
// --- Aufgerufene ---
int f_06ed10(void *a, int b, void *c);
int f_07a470(void *a, int b, void *c);
int f_0d06c0(int a);
int f_0d0760(int a);
int f_0d4a60(int a);
int f_0727e0(int a);
int f_0728f0(int a);
signed char f_043490(int a);
unsigned char f_043470(int a);
short f_0722a0(void *a, int b);
int f_06e9e0(void *a, int b, int c, int d, short *e, void *f, int g);
Q *f_07ea60(void *a, int b);
signed char f_030960(int a);
int f_030890(int a);
unsigned char f_0729c0(int a);
int f_030810(int a);
unsigned char f_0d54c0(int a);
void f_071e90(unsigned char a, unsigned char *b, unsigned char *c);
int f_0708f0(void *a, short b, int c);
#pragma aux f_0708f0 parm [eax edx ebx] modify exact [eax]
int f_0708f0(void *a);
void f_07ec10(void *a, int b);
void f_069a00(int a, void *b);
void f_06a600(int a, int b);
unsigned char f_0cfc70(int a);
unsigned char f_0cfc50(int a);
int f_06f400(void *a, int b, unsigned char *c, int d, short *e, void *f, int g);
int f_06d380(void *a, int b, short *c, void *d);
extern const char d_1a27a4[];
extern const char d_1a27a8[];

//@ f_06d050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erstellt für einen handlungsfähigen Helden p2 eine kurze Kampfanimationssequenz mit der
 *   richtungsabhängigen Aktion d_1a27a4[f_043490(p2)] (z. B. Parade oder kurze Aktion) und übergibt sie an das
 *   Figuren-Sprite x->q; ist der Held nicht handlungsfähig, wird stattdessen die Standard-Standsequenz f_06ed10
 *   gesetzt.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax, T *), der Heldenzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, R *); zurückgegeben wird das Figuren-Sprite (int in eax).
 * - Wichtige Variablen: d_1a27a4 enthält die Animationskennungen für die vier Blickrichtungen.
 === Ende Beschreibung === */
int f_06d050(T *self, int p2, R *p3)
{
    if (f_0d4a60(p2)) {
        memset(p3, 0, 0xa4);
        p3->w0 = f_0727e0(p2);
        p3->e[0].a = d_1a27a4[f_043490(p2)];
        p3->e[0].b = 0;
        p3->e[1].a = 0xff;
        Q *x = f_07ea60(self->sub, f_043470(p2));
        f_069a00(x->q, p3);
        return x->q;
    }
    return f_06ed10(self, p2, p3);
}

//@ f_06d0d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen handlungsfähigen Helden p2 die Animationssequenz beim Einsatz eines Gegenstands
 *   p4 im Kampf auf: Dreht den Helden über f_06e9e0 zum Ziel, wählt die Gebrauchsanimation aus d_1a27a8 und
 *   erzeugt, falls p4 != 0 ist (z. B. Wurfflasche/Elixier 0xee, 0xef, 0x3b, 0x8d), auf dem Zielfeld (u, w) ein
 *   Effekt-Sprite (0xe7..0xeb in Archiv 0x1000b).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Heldenzeiger p2 (edx), der
 *   Sequenzpuffer p3 (ebx) und der Gegenstandscode p4 (ecx, short); zurückgegeben wird das Effekt-Sprite v bzw.
 *   das Figuren-Sprite x->q.
 * - Wichtige Variablen: u und w speichern die Kampfraster-Koordinaten des Ziels, v das temporäre Effekt-Sprite
 *   (f_0708f0).
 === Ende Beschreibung === */
int f_06d0d0(T *self, int p2, R *p3, short p4)
{
    short w; idx_t idx = 0; int v = 0;
    unsigned char u;
    R r;
    if (f_0d4a60(p2)) {
        memset(p3, 0, 0xa4);
        p3->w0 = f_0727e0(p2);
        signed char c = f_043490(p2);
        short s = f_0722a0(self, p2);
        f_06e9e0(self, p2, c, s, (short *)&idx, p3, 0);
        char tb = d_1a27a8[f_043490(p2)]; p3->e[(short)idx].a = tb;
        p3->e[(short)idx].b = 0;
        Q *x = f_07ea60(self->sub, f_043470(p2));
        if (p4) {
            int q = 0;
            ;
            if (f_030960(p2) == 1 || f_030960(p2) == 4) q = f_030890(p2);
            unsigned char t;
            if (f_030960(p2) == 1) {
                if (!q) goto skip;
                t = f_0729c0(q) + 10;
            } else if (f_030960(p2) == 4) {
                if (!q) goto skip;
                t = f_0729c0(q) + 0x1e;
            } else {
                t = f_0d54c0(f_030810(p2)) + 1;
            }
            f_071e90(t, &u, (unsigned char *)&w);
        skip:;
            memset(&r, 0, 0xa4);
            v = f_0708f0(self);
            r.w0 = 0x1000b;
            r.e[0].a = (p4 == 0xee) ? 0xe7 : (p4 == 0xef) ? 0xe9 : (p4 == 0x3b) ? 0xe8 : (p4 == 0x8d) ? 0xea : 0xeb;
            r.e[0].b = 0;
            r.e[0].d = 0x1d;
            r.e[0].c = 1; self->d27 = v;
            self->b1f = u;
            self->b18 = self->b1f;
            self->b20 = w;
            self->b19 = self->b20;
            self->b24 = 0;
            self->d1a = 0x1000b;
            self->d2b = 0;
            self->b22 = 0x64;
            self->b23 = 1;
            self->b25 = 0xff;
            f_07ec10(self->sub, -1);
            f_069a00(v, &r);
            f_06a600(v, 0);
            p3->e[(short)idx].d = 0x1c;
            p3->w8 = v;
        }
        idx++;
        p3->e[(short)idx].a = 0xff;
        f_069a00(x->q, p3);
        (void)p2; if (v) return v; return x->q;
    }
    return f_06ed10(self, p2, p3);
}

//@ f_06d380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen Gegner b über f_0d0760(b), ob beim Tod oder Treffer ein zusätzlicher
 *   Spezialeffekt (0xdb in Archiv 0x1000b) auf seiner Rasterposition (x, y) abgespielt werden soll, legt dafür
 *   über f_0708f0 ein Effekt-Sprite v an und hängt drei Sequenzeinträge mit Animationscode 9
 *   (Tod/Am-Boden-Liegen) und den Aktionscodes 0x1c und 0x23 an p3 an.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem a (eax), der Gegnerzeiger b (edx), der
 *   Sequenzindexzeiger c (ebx, short *) und der Sequenzpuffer d (ecx, R *); zurückgegeben wird das Effekt-Sprite
 *   v (0 wenn keines erzeugt wurde).
 * - Wichtige Variablen: *c wird um 3 Einträge weitergeschaltet, v hält das Effekt-Sprite.
 === Ende Beschreibung === */
int f_06d380(void *a, int b, short *c, void *d)
{
    T *self = (T *)a;
    R *p3 = (R *)d;
    R r;
    unsigned char x, y;
    int v = 0;
    if (f_0d0760(b)) {
        f_071e90((unsigned char)(f_0729c0(b) + 10), &x, &y);
        p3->e[(short)*c].a = 9;
        memset(&r, 0, 0xa4);
        v = f_0708f0(self);
        r.w0 = 0x1000b;
        r.e[0].a = 0xdb;
        r.e[0].b = 0;
        r.e[0].d = 0x1d;
        self->d27 = v;
        self->b1f = x;
        self->b18 = self->b1f;
        self->b20 = y;
        self->b19 = self->b20;
        self->d1a = 0x1000b;
        self->d2b = 0;
        self->b22 = 0x63;
        self->b23 = 1;
        self->b24 = 0;
        self->b25 = 0xff;
        f_07ec10(self->sub, -1);
        f_069a00(v, &r);
        f_06a600(v, 0);
        p3->e[(short)*c].d = 0x1c;
        p3->w8 = v;
        ++*c;
        p3->e[(short)*c].a = 9;
        p3->e[(short)*c].c = 4;
        ++*c;
        p3->e[(short)*c].a = 9;
        p3->e[(short)*c].d = 0x23;
        ++*c;
    }
    return v;
}

//@ f_06d4a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die Sterbe- oder Treffersequenz für einen Gegner p2 auf (bei großen zweiteiligen Monstern
 *   f_0d06c0(p2) über f_07a470): Dreht den Gegner über f_06f400 in Richtung 1, fügt den Animationscode 0x26
 *   sowie über f_06d380 eventuelle Spezialeffekte an und startet die Sequenz auf dem Gegner-Sprite x->q.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Gegnerzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx); zurückgegeben wird das Effekt-Sprite r bzw. das Gegner-Sprite x->q.
 * - Wichtige Variablen: idx zählt die geschriebenen Phasen im Sequenzpuffer p3.
 === Ende Beschreibung === */
int f_06d4a0(T *self, int p2, R *p3)
{
    idx_t idx = 0;
    unsigned char c;
    if (f_0d06c0(p2)) return f_07a470(self, p2, (char *)self + 0x45);
    memset(p3, 0, 0xa4);
    p3->w0 = f_0728f0(p2);
    c = f_0cfc70(p2);
    f_06f400(self, p2, &c, 1, (short *)&idx, p3, 0);
    p3->e[(short)idx].a = 0x26;
    p3->e[(short)idx++].b = 0;
    int r = f_06d380(self, p2, (short *)&idx, p3);
    p3->e[(short)idx].a = 0xff;
    Q *x = f_07ea60(self->sub, f_0cfc50(p2));
    f_069a00(x->q, p3);
    if (r) return r; return x->q;
}
