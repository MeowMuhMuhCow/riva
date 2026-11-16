/* === Beschreibung (Katalog) ===
 * Einheit star1_t3 (0x1182a0 - 0x118a10)
 *
 * Überblick
 * Diese Einheit bildet den dritten und letzten Teil von star1.cpp (erste Ebene des Bienenstocks) und enthält die
 * restlichen Raum- und Beute-Interaktionen sowie die Registrierung der Zustandsvariablen für die zweite Ebene
 * (star2).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 4/5 gleich (suche.py 29.10.2026, Basis star1_t3_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 0 gleich (vorher 0), Rest 466 (vorher 491)
// star1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x115D80-0x118A10
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039420(int p1, int p2);
int f_039580(int p1, int p2, int p3);
int f_039660(int p1, int p2);
int f_0396f0(int p1, int p2);
int f_039ac0(int p1, int p2);
int f_039b70(int p1, int p2, int p3);
int f_040780(int p1, int p2);









signed char f_043a80(int p1, int p2);
int f_043d70(int p1, int p2);
int f_043e20(int p1, int p2);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
int f_044900(int p1, int p2, int p3);
int f_0453e0(int p1, int p2, int p3);
int f_057220(int p1, int p2, int p3);
int f_0603b0(int p1);
int f_0606a0(int p1, int p2);
int f_060740(int p1, int p2, int p3, int p4);
int f_060800(int p1, int p2, int p3);
int f_060a70(void);
int f_0697c0(int p1, int p2, int p3);
int f_091f70(int p1);
int f_099ef0(void);
int f_09a0d0(int p1);
int f_09a140(int p1, int p2);


int f_0bde40(int p1);
int f_0bf680(int p1, int p2);
int f_0bf6c0(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0bf820(void);
int f_0bf980(void);
int f_0bfa20(void);
int f_0d4a60(int p1);
int f_0d4aa0(int p1, int p2);
int f_0d4c80(int p1, int p2, int p3, int p4);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0d5ff0(int p1);
int f_0d64a0(void);
int f_0db820(int p1, int p2);
short f_0db9a0(int p1);
short f_0dc020(int p1, int p2);
int f_0dcbb0(int p1, int p2);
int f_0dcd30(int p1, int p2, int p3);
int f_0dd1d0(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
int f_0e9300(int p1, int p2, int p3);
int f_0e93f0(int p1, int p2, int p3);

short f_10b890(int p1);
int f_112df0(int p1, int p2, int p3, int p4);
int f_112e70(int p1, int);
int f_112ec0(int p1);
int f_113340(int p1, int p2, int p3, int p4);
int f_113640(int p1);
int f_1150b0(int p1, int p2, int p3);
int f_1155d0(int p1, int p2);
int f_118e50(void);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_125e50(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_133fe0(int p1, int p2);
int f_1457e0(int p1);
int f_149eb4(void);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a7c2a;                    // 0x1A7C2A
extern short d_1a7c30[];
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0930;                    // 0x1C0930
extern int d_1c093c;                    // 0x1C093C
extern int d_1c0940;                    // 0x1C0940
extern int d_1c0944;                    // 0x1C0944
extern int d_1c0948;                    // 0x1C0948
extern int d_1c094c;                    // 0x1C094C
extern int d_1c0950;                    // 0x1C0950
extern signed char d_1c0954;                    // 0x1C0954
extern int d_1c0958;                    // 0x1C0958
extern short d_1c095c;                    // 0x1C095C
extern signed char d_1c0960;
extern int d_1c0964;                    // 0x1C0964
extern int d_1c0968;                    // 0x1C0968
extern int d_1c096c;                    // 0x1C096C
extern int d_1c0970;                    // 0x1C0970
extern int d_1c0974;                    // 0x1C0974
extern int d_1c0978;                    // 0x1C0978
extern int d_1c097c;                    // 0x1C097C
extern int d_1c0980;                    // 0x1C0980
extern int d_1c0984;                    // 0x1C0984
extern int d_1c0988;                    // 0x1C0988
extern int d_1c098c;                    // 0x1C098C
extern int d_1c0990;                    // 0x1C0990
extern int d_1c0994;                    // 0x1C0994
extern int d_1c0998;                    // 0x1C0998
extern int d_1c099c;                    // 0x1C099C
extern int d_1c09a0;                    // 0x1C09A0
extern int d_1c09a8;                    // 0x1C09A8
extern int d_1c09ac;                    // 0x1C09AC
extern signed char d_1c09b0;                    // 0x1C09B0
extern int d_1c09b4;                    // 0x1C09B4
extern int d_1c09b8;                    // 0x1C09B8
extern int d_1c09bc;                    // 0x1C09BC
extern int d_1c09c0;                    // 0x1C09C0
extern int d_1c09c4;                    // 0x1C09C4
extern int d_1c09c8;                    // 0x1C09C8
extern int d_1c09e8;                    // 0x1C09E8
extern short d_1c219c;
extern int d_1c21b4;                    // 0x1C21B4
extern char d_1c2c00[];
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a7c0c[];           // Text 0x1A7C0C
#define I(p,o) (*(int *)((p)+(o)))
#define M64 ((int)d_1c2c64)
#define M2C ((int)d_1c2c00)
#define CTOR f_125400((int)&ob, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498)
#define DTOR f_1254a0((int)&ob, 0)
struct Ob { int w0; int p4; int p8; int pc; int p10; int p14; int p18; int p1c; char pad[0x1c]; };
struct N14 { char x[0x14]; };
int f_147c84(int p1, int p2);
void f_118250(void);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_1182a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumes eine Warnmeldung (0x2e000090) aus und setzt das Flag d_1c09dc.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1182a0(int p1)
{
    struct Ob ob;
    int h, a, a2 = 0, b;
    h = f_039ac0(d_1c0004, (int)f_118250);
    a2 = f_0606a0(0x2e0001, 5);
    a = a2;
    if (h != 0) {
        CTOR;
        b = f_1155d0(p1, 1);
        I(ob.p4,4) = h;
        ((short (*)(int, ...))f_0bfa20)(M64, a, 0, 0x2e00003e, 0);
        *(signed char *)&d_1c09c8 = 1;
        if (b != 0) {
            I(ob.p4,8) = b;
            f_0bf730(M64, 0x2e00003f);
        }
        DTOR;
    } else {
        ((short (*)(int, ...))f_0bfa20)(M64, a, 0, 0x2e000040, 0);
    }
    if (a2 != 0) {
        operator delete((void *)((int)(((RivaRasterImage*)(a2))->f_0fad20( 0))));
    }
}

//@ f_118380
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchsucht die aktive Heldengruppe (d_1c0004) nach einem handlungsfähigen Helden (f_042400 == 0 und
 *   f_0d4a60 != 0), bevorzugt dabei männliche Helden (f_042380 == 0), Nicht-Magier (f_042350 != 9) sowie den
 *   höchsten Attributswert 2 (f_043a80(..., 2)) und gibt den ausgewählten Heldenzeiger zurück.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den ausgewählten Helden zurück.
 === Ende Beschreibung === */
int f_118380(int p1)
{
    int a, b, h = 0;
    short i;
    signed char c2;
    a = 0;
    b = 0;
    for (i = 0; i < 7; i = i + 1) {
        int *pp;
        h = f_0de7d0(d_1c0004, (int)i);
        if (h != 0 && f_042400((struct hero *)(h)) == 0 && f_0d4a60(h) != 0) {
            if (f_042380((struct hero *)(h)) == 0) {
                pp = &a;
            } else {
                pp = &b;
            }
            if (*pp == 0) {
                *pp = h;
            } else if (f_042350((struct hero *)(h)) != 9) {
                if (f_042350((struct hero *)(*pp)) == 9) {
                    *pp = h;
                } else {
                    c2 = f_043a80(*pp, 2);
                    if (c2 <= f_043a80(h, 2)) {
                        *pp = h;
                    }
                }
            }
        }
    }
    if (a != 0) {
        return a;
    } else {
        return b;
    }
}

//@ f_118460
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt eine Zwischenszene mit Bild 6 aus 0x2e0001 und den Textmeldungen 0x2e000044 bis 0x2e000046 aus,
 *   wählt über f_118380 ein Gruppenmitglied aus, setzt dessen Status (f_043d70(u, 1)), vergibt Abenteuerpunkte
 *   (f_057220(..., 0x8030037, 0)) und startet den Sound-/Spracheffekt f_0d5ff0.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_118460(int p1)
{
    struct Ob ob;
    int a, u, u2;
    short s = 0;
    d_1c0954 = 1;
    f_0bf6c0(M64, 5);
    f_0bf730(M64, 0x2e000044);
    a = f_0606a0(0x2e0001, 6);
    f_0bde40(M64);
    ((int (*)(int, ...))f_0bfa20)(M64, a, 0, 0x2e000045, 0);
    if (a != 0) {
        delete (char *)((int)(((RivaRasterImage*)(a))->f_0fad20( 0)));
    }
    ((int (*)(int))f_0bf680)(M64);
    u = ((int (*)(int))f_118380)(p1);
    s = (short)((((signed char)f_042380((struct hero *)(u)) == 0) ? 1 : 0) + 7);
    f_043d70(u, 1);
    f_0bf730(M64, 0x2e000046);
    f_10b890(4);
    CTOR;
    u2 = f_039660(d_1c0004, 5);
    I(ob.p4,4) = u2;
    f_057220(M2C, 0x8030037, 0);
    f_0d5ff0(s);
    f_060a70();
    DTOR;
}

//@ f_118580
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt ein Ereignis der Bienenstock-Ebene (0x2e000054 und 0x2e000059), setzt abhängig vom Zustand
 *   des Begleiters f_1155d0(p1, 0) die Statusvariable d_1c09c0 (0 bis 3), vergibt gegebenenfalls Abenteuerpunkte
 *   (0x803003a) und legt über ein N14-Ereignisobjekt (0x46) den Gegenstand 0x105 ab.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_118580(int p1)
{
    struct Ob ob;
    int iv;
    CTOR;
    I(ob.p10,4) = 0x20000194;
    f_0bf730(M64, 0x2e000054);
    iv = f_1155d0(p1, 0);
    int iv2 = iv;
    *(short *)&d_1c09c0 = 1;
    if (iv == 0) {
        *(short *)&d_1c09c0 = 0;
    } else {
        if (((signed char)(f_042470((struct hero *)(iv2)))) != (signed char)0) {
            *(short *)&d_1c09c0 = 2;
            d_1c09b0 = 1;
            f_0d64a0();
        } else {
            if ((int)f_042960((struct hero *)(iv2)) < (int)f_042970((struct hero *)(iv2)) / 2) {
                f_057220(M2C, 0x803003a, (*(short *)&d_1c09c0 = 3, 0));
            } else {
                f_057220(M2C, 0x803003a, 0);
            }
        }
    }
    *(signed char *)&d_1c095c = 1;
    f_10b890(5);
    int raw = (int)new (mark(d_1a7c0c, 0x7e0)) N14;
    if (raw) iv = f_112df0(raw, 0x46, 0, 1); else iv = raw;
    f_113640(iv);
    f_113340(iv, 0x105, 1, 0);
    f_112ec0(iv);
    f_113640(iv);
    if (iv != 0) {
        delete (char *)f_112e70(iv, 0);
    }
    f_060a70();
    f_0bf730(M64, 0x2e000059);
    DTOR;
}

//@ f_1186f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt die große Abschluss- und Übergangsszene der Bienenstock-Ebene mit Farbpaletten-Überblendung
 *   (f_149eb4 / f_099ef0) aus, legt bei Überleben des Begleiters (d_1c09c0 == 1) den Gegenstand 0x1b4 ab,
 *   entfernt die Quest-Gegenstände aus d_1a7c30 aus dem Inventar, vergibt Belohnungen (0x803003c, f_0dcbb0,
 *   f_040780) und entlässt auf Wunsch (f_10b890(7) == 2) den temporären Begleiter unter Sicherung seiner
 *   Ausrüstung aus der Gruppe (f_0dcd30).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1186f0(int p1)
{
    extern char d_1baac0[];
    int f_147c84(void *, int, void *);
    int __cdecl f_149eb4(int, int, int);
    int __cdecl f_099ef0(int, int, int);
    
    struct Make {
        static int run(int line) {
            int p = (int)new (mark(d_1a7c0c, line)) N14;
            if (p != 0) return f_112df0(p, 0x46, 0, 1);
            return p;
        }
    };

    Ob ob;
    int lh, st; short item;
    int u, h, index, off; short amount;
    int v = 0;
    short i;
    f_125400((int)&ob, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
    u = f_1155d0(p1, 0);
    lh = f_039580(d_1c0004, 0, 0);
    char *buf = new (mark(d_1a7c0c, 0x810)) char[0x300];
    st = f_147c84(buf, 0x100, d_1baac0);
    st = st ? st : 0;
    *(short *)&d_1c09c0 = (((signed char)(f_042470((struct hero *)(u)))) != (signed char)0) + 1;
    f_0d64a0();
    f_149eb4(st, 0, 0x100);
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_10b890(6);

    if (*(short *)&d_1c09c0 == 1) {
        v = Make::run(0x82a);
        f_113640(v);
        f_113340(v, 0x1b4, 1, 0);
        f_112ec0(v);
        f_113640(v);
        if (v != 0) delete (char *)f_112e70(v, 0);

        d_1c0960 = 1;
        i = 0;
        goto scan_test;
        do {
            ++i;
            f_0dd1d0(d_1c0004, index);
scan_test:
            index = d_1a7c30[(int)i];
        } while (index != -1);
        f_057220(M2C, 0x803003c, 0);
        f_091f70(0x33);
        f_0dcbb0(d_1c0004, 0x14);
        h = lh;
        f_040780(lh, 0x14);
        if (h == 0 || ((signed char)(f_042470((struct hero *)(h)))) == 1) {
            f_10b890(8);
        } else if (f_10b890(7) == 2) {
            int raw = (int)new (mark(d_1a7c0c, 0x84e)) N14;
            if (raw) v = f_112df0(raw, 0x46, 0, 1); else v = raw;
            int event = v;
            h = lh;
            f_113640(v);
            for (i = 0; (index = (int)i) < 31; ++i) {
                short itemValue = ((int)(f_042a60((struct hero *)((void *)h), index)));
                item = itemValue;
                itemValue = (short)itemValue;
                if (itemValue > 0) {
                    off = itemValue * 4;
                    if (((RivaItemDefinition*)(I(((int)d_1c2c40), off)))->f_0a78f0() == 0) {
                        amount = ((RivaItemDefinition*)(I(((int)d_1c2c40), off)))->f_0a7950() != 0 ? (int)f_042ac0((struct hero *)(h), index) : 1;
                        f_113340(v, (short)item, (short)amount, 0);
                    }
                }
            }
            short s = f_0dc020(d_1c0004, lh);
            f_0dcd30(d_1c0004, (int)s, -1);
            if (f_0db9a0(d_1c0004) == 0) d_1c219c = 1;
            else f_112ec0(event);
            v = event;
            f_113640(event);
            if (v != 0) delete (char *)f_112e70(v, 0);
        }
    }

    u = st;
    f_099ef0(u, 0, 0x100);
    f_060a70();
    delete (char *)u;
    f_1254a0((int)&ob, 0);
}
