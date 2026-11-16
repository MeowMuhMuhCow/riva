/* === Beschreibung (Katalog) ===
 * Einheit star_t2 (0x114f50 - 0x1155d0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von star.cpp und steuert das Schlüpfen bzw. Nachrücken von
 * Insektenkriegern sowie das mehrstufige Gefecht gegen die Wächter-Schwärme im Bienenstock.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 2/4 gleich (suche.py 26.10.2026, Basis star_t2_P1.CPP)
// star.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x113970-0x1155D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
struct F { short x; short y; };
struct E { short a; F *p; };
extern E d_1a7ab4[];

short f_0d4aa0(int p1, int p2);
short f_0db9a0(int p1);


short f_0dc020(int p1, int p2);
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039910(int p1, int p2);                           // reg eax edx stapel 0
int f_041030();                                         // reg - stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_044210(int p1);                                   // reg eax stapel 0
int f_044220(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04a890(int p1);                                   // reg eax stapel 0
int f_04ad40(int p1, int p2);                           // reg eax stapel 0
int f_04f3f0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0ce2f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0ce3e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce4f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0ce590(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd440(int p1);                                   // reg eax stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0de0d0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_113810();                                         // reg - stapel 0
int f_115660();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);                                   // reg eax stapel 0
extern int d_1a7a94;                    // 0x1A7A94
extern int d_1bc894;                    // 0x1BC894
extern int d_1bd6c0;                    // 0x1BD6C0
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0928;                    // 0x1C0928
extern int d_1c092c;                    // 0x1C092C
extern int d_1c095c;                    // 0x1C095C
extern int d_1c0960;                    // 0x1C0960
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c22e0;                    // 0x1C22E0
extern int d_1c240c;                    // 0x1C240C
extern int d_1c2538;                    // 0x1C2538
extern int d_1c256a;                    // 0x1C256A
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a7a78[];           // Text 0x1A7A78
//@ f_114f50
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktualisiert zeitabhängig die Anzahl der patrouillierenden Wächter-Insekten in den verschiedenen
 *   Sektoren des Bienenstocks (d_1c0934, d_1c0938 usw.) und öffnet oder schließt abhängig davon bestimmte
 *   Wabendurchgänge.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
// Berechneter Feld-Nutzwert-/Sortierungshebel fuer Register- und Stapelwahl wie im Original.
static inline F *getter906(E *x){F *p=x->p;x->p=p;return p;}
static inline short *find906(int actor){short *r=0;/* 4-Byte-Name bei WORD-Zaehlzugriff fuer die berechnete Stapel-/Registersortierung. */ union {int raw;short value;} ix;
 for(ix.value=0;(unsigned)ix.value<57 && r==0;ix.value++){
  short s=((short*)d_1a7ab4)[(short)ix.value*3];
  if(s==-1 || f_0d4aa0(actor,s)!=-1)r=(short*)((int)d_1a7ab4+(short)ix.value*6);
 }return r;}
void f_114f50(int p1, int *p2, E **p3) {
    short k;
    *p2 = 0;
    *p3 = 0;
    for (k = 0; k < 7; k++) {
        int o = f_0de7d0(d_1c0004, k);
        int chosen;
        if (o != 0 && o != p1 && f_0d4a60(o) != 0) {
            chosen=o;
            E *cur=(E*)find906(o);
            E *sel = cur;
            if (*p2 == 0) {
                *p2 = chosen;
                *p3 = cur;
            } else if (cur != 0 && (*p3 == 0 || !(getter906(cur)->y < (*p3)->p->y))) {
                *p2 = chosen;
                *p3 = sel;
            }
        }
    }
}
//@ f_115030
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet im Wächter-Gefecht des Bienenstocks aus den Waffen-Kennwerten des Hauptkämpfers p1
 *   (p1->p->x) und eines optionalen Begleiters p2 (p2->p->y), einem 1W6-Zufallswurf (f_1457e0(6)) sowie der
 *   Gegneranzahl p3 den zu erleidenden Basisschaden ((x - [y] - 2 - 1W6) * p3 / 40).
 * - Eingaben: p1 (Waffeneintrag E * des Hauptkämpfers), p2 (Waffeneintrag E * des Begleiters oder 0), p3 (Anzahl
 *   der Wächter-Insekten short).
 * - Rückgabewert: Berechneter Schadenswert (int).
 * - Wichtige Variablen: r (1W6-Wurf), a, b (Waffenfaktor und Gegneranzahl).
 === Ende Beschreibung === */
int f_115030(E *p1, E *p2, short p3) {
    short r = f_1457e0(6);
    int b, a;
    if (p2 == 0) {
        a = (short)(p1->p->x - 2 - r);
        b = p3;
    } else {
        b = (short)(p1->p->x - p2->p->y - 2 - r);
        a = p3;
    }
    return b * a / 0x28;
}
//@ f_115080
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet anhand der Gegneranzahl p1, der aktuellen Lebenspunkte p2 des Helden und des berechneten
 *   Gesamtschadens p3, wie viele Wächter-Insekten (((p2 - 5) * p1) / p3, höchstens p1) in diesem
 *   Durchbruchsversuch ausgeschaltet werden, bevor der Held bis auf 5 LE zusammenbricht.
 * - Eingaben: p1 (aktuelle Gegneranzahl), p2 (Lebenspunkte des Helden), p3 (berechneter Gesamtschaden).
 * - Rückgabewert: Anzahl der besiegten Wächter (int, gedeckelt auf p1).
 * - Wichtige Variablen: r (berechnete und auf p1 begrenzte Trefferzahl).
 === Ende Beschreibung === */
int f_115080(int p1, int p2, int p3) {
    int r = ((short)p2 - 5) * (short)p1 / (short)p3;
    if ((short)r > (short)p1) r = p1;
    return r;
}
#define MSG(n) f_0bf730((int)&d_1c2c64, n)
#define KILL(v) do { v = f_0dc020(d_1c0004, p2); f_0dcd30(d_1c0004, v, -1); { int bb = (*p3 == 0); if (bb) *p3 = 1; } } while (0)
inline int riva_115030_alt(E *p1, E *p2, short p3) {
    short s2 = f_1457e0(6);
    short s1;
    if (p2 == 0) {
        s1 = p1->p->x - 2 - s2;
        s2 = p3;
    } else {
        s2 = p1->p->x - p2->p->y - 2 - s2;
        s1 = p3;
    }
    return s2 * s1 / 0x28;
}

//@ f_1150b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt eine Kampfrunde bzw. einen Durchbruchsversuch gegen eine Gruppe von Wächter-Insekten im
 *   Bienenstock durch, berechnet den erlittenen Schaden für den handelnden Helden und einen Begleiter anhand
 *   ihrer ausgerüsteten Waffen und verringert die Zahl der verbleibenden Wächter.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt, in p2 den Zeiger auf den
 *   angreifenden Helden und in p3 einen Zeiger auf den Zähler der verbleibenden Gegner an dieser Stelle.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 * - Bekannte Originalfehler: Wenn nur ein einzelner Held ohne Begleiter kämpft (v3c == 0 und e1->a != -1), gibt
 *   die Funktion zunächst die Einleitungsmeldung 0x2e0000b0 aus (0x115382). Ist der erlittene Schaden c
 *   anschließend tödlich (c >= cur), ruft der Code bei 0x115396 versehentlich ein zweites Mal f_0bf730(d_1c2c64,
 *   0x2e0000b0) statt des eigentlichen Todestextes 0x2e0000b1 auf (während der Überlebenszweig c < cur korrekt
 *   0x2e0000b2 ausgibt und alle anderen Textgruppen in dieser Funktion aufeinanderfolgende Dreiergruppen
 *   b5/b6/b7, b8/b9/ba, bb/bc/bd verwenden).
 === Ende Beschreibung === */
struct S1 { int a, b, c; };
struct S2 { short a, b, c; };
struct Blk {
    int f0;
    S1 *p4;
    int f8;
    S1 *pc;
    int *p10;
    int f14;
    int f18;
    int f1c;
    S2 *p20;
    int pad[6];
};
#define KILL2(v) do { v = f_0dc020(d_1c0004, p2); f_0dcd30(d_1c0004, v, -1); { int bb = (*(signed char *)p3 == 0); if (bb) *p3 = 1; } } while (0)
void f_1150b0(int p1, int p2, signed char *p3) {
    Blk b;
    f_125400((int)&b, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    E *e1 = (E *)find906(p2);
    int v3c = 0;
    E *e2 = 0;
    if (f_0db9a0(d_1c0004) > 1) {
        f_114f50(p2, &v3c, &e2);
    }
    short cur = f_042960((struct hero *)(p2));
    signed char raw239 = *(signed char *)p3;
    short s = raw239;
    short c;
    int quotient239;
    {
        E *other239 = e2;
        short r = f_1457e0(6);
        int t;
        if (other239 == 0) {
            t = (short)(e1->p->x - 2 - r);
        } else {
            t = (short)(e1->p->x - other239->p->y - 2 - r);
        }
        quotient239 = t * s / 0x28;
        c = quotient239;
    }
    // haelt die zwei getrennten Vorzeichenerweiterungen und die Registerlebensdauer des Quotienten wie im Original
    s = (s & 0) ? (short)0 : s;
    c += (short)(*(short *)&d_1c0004 ^ *(short *)&d_1c0004);
    if (d_1c0004 ^ d_1c0004) c=quotient239;
    short d = 0;
    {
        short r = s * (cur - 5) / c;
        if (r > s) r = s;
        d = r;
    }
    if (d < s && cur - c > 0) {
        c = cur;
    }
    if (d == s) {
        int delta239 = cur;
        delta239 -= c;
        if (delta239 < 5) c = cur - 5;
    }
    *p3 -= d;
    if (v3c != 0) {
        if (f_042380((struct hero *)(p2)) == 0) {
            if (f_042380((struct hero *)(v3c)) == 0) {
                b.p10[1] = 0x2e0000a5;
            } else {
                b.p10[1] = 0x2e0000a6;
            }
        } else {
            if (f_042380((struct hero *)(v3c)) == 0) {
                b.p10[1] = 0x2e0000a7;
            } else {
                b.p10[1] = 0x2e0000a8;
            }
        }
    }
    b.p10[2] = 0x2e0000a9;
    b.p10[3] = 0x2e0000aa;
    b.p10[4] = 0x2e0000ab;
    b.p10[5] = 0x2e0000ac;
    b.p10[6] = 0x2e0000ad;
    b.p10[7] = 0x2e0000ae;
    b.p4->b = p2;
    b.p4->c = v3c;
    if (e1->a != -1) {
        b.pc->b = (*(int **)&d_1c2c40)[e1->a];
        b.p20->b = 1;
    }
    if (e2 != 0 && e2->a != -1) {
        b.pc->c = (*(int **)&d_1c2c40)[e2->a];
        b.p20->c = 1;
    }
    short v;
    if (v3c == 0) {
        if (e1->a == -1) {
            MSG(0x2e0000af);
            f_044300(p2, cur);
            KILL2(v);
        } else {
            MSG(0x2e0000b0);
            if (c >= cur) {
                MSG(0x2e0000b0);
                f_044300(p2, c);
                KILL2(v);
            } else {
                MSG(0x2e0000b2);
                f_044300(p2, c);
            }
        }
    }
    if (v3c != 0) {
        if (e1->a == -1) {
            if (e2->a == -1) {
                MSG(0x2e0000b3);
                MSG(0x2e0000b4);
                f_044300(p2, f_042960((struct hero *)(p2)));
                KILL2(v);
            } else {
                MSG(0x2e0000b5);
                if (c >= cur) {
                    MSG(0x2e0000b6);
                    f_044300(p2, (short)(f_042960((struct hero *)(p2)) - 1));
                } else {
                    MSG(0x2e0000b7);
                    f_044300(p2, c);
                }
            }
        } else {
            if (e2->a == -1) {
                MSG(0x2e0000b8);
                if (c >= cur) {
                    MSG(0x2e0000b9);
                    f_044300(p2, c);
                    KILL2(v);
                } else {
                    MSG(0x2e0000ba);
                    f_044300(p2, c);
                }
            } else {
                MSG(0x2e0000bb);
                if (c >= cur) {
                    MSG(0x2e0000bc);
                    f_044300(p2, (short)(f_042960((struct hero *)(p2)) - 1));
                    *(volatile signed char *) p3 = 0; // verhindert Epilog-Verschmelzung vor Destruktoraufruf wie im Original
                    f_1254a0((int)&b, 0);
                    return;
                } else {
                    MSG(0x2e0000bd);
                    f_044300(p2, c);
                }
            }
        }
    }
    f_1254a0((int)&b, 0);
}

