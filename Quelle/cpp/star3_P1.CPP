/* === Beschreibung (Katalog) ===
 * Einheit star3 (0x11aaa0 - 0x11bd60)
 *
 * Überblick
 * Diese Einheit implementiert die dritte und tiefste Ebene des Bienenstocks (star3.cpp, Dungeon-ID 9)
 * einschließlich der Konfrontation in der Kammer der Bienen-/Insektenkönigin, der Befreiung bzw. Untersuchung
 * von Kokons und den zugehörigen Kämpfen und Beutecontainern.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 24/28 gleich (suche.py 24.10.2026, Basis star3_P1.CPP)
// star3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11AAA0-0x11BD60
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039580(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0

signed char f_043a80(int p1, int p2);
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_060740(int p1, int p2);
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820(int, ...);
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1);
int f_0d5040(int, int, int, int, int, int);
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_1134d0(int p1, int p2);                           // reg eax edx stapel 0
int f_1150b0(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_1155d0(int p1, int p2);                           // reg edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
extern int d_1c0004;
extern signed char d_1c0934, d_1c0938, d_1c0958, d_1c09a8, d_1c0a0c, d_1c0a10, d_1c0a14, d_1c0a1c, d_1c0a20, d_1c0a24;
extern signed char d_1c0a18; extern short d_1c0a19;
extern int d_1c2c00, d_1c2c64, d_1c3498, d_1c349c, d_1c3870;
extern const char d_1a7d6c[];
#define EQ(x,v) (((x)==(v))?1:0)
#define GT(x,v) (((x)>(v))?1:0)
#define A64 ((int)&d_1c2c64)
typedef RivaTextContextData OB;
typedef int (*FP3)(int, int, int);
#define CTOR(o) f_125400((int)&(o), (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498)
#define DTOR(o) f_1254a0((int)&(o), 0)
#define OBST(o,v) *(int *)((o).addresses.objects + 4) = (v)
void f_11b5f0(int p1);
void f_11b790(int p1);
void f_11b9c0(int p1);
void f_11bbc0(void);

void f_112ec0_d(int p);
#pragma aux f_112ec0_d "f_112ec0"
//@ f_11aaa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Verteiler der dritten Bienenstock-Ebene (star3), der anhand des Ereigniscodes (p2)
 *   die einzelnen Raumereignisse, Kämpfe, Beutecontainer und Ebenenübergänge aufruft.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis behandelt wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_11aaa0(int p1, int p2)
{
    int f_0bf6f0_x(int, int);
    #pragma aux f_0bf6f0_x "f_0bf6f0" parm [eax] [edx] modify [esi]

    int r = 1;
    OB ob[5];
    switch ((unsigned short)p2) {
    case 0x321:
        if (f_0bf6f0_x(A64, 0x2e0000be) != 1) goto out;
        f_0dd7f0(d_1c0004, 7, 0x1459);
        return r;
    case 0x322:
        CTOR(ob[4]);
        {
            int m;
            {
                signed char z = 0; int a = d_1c0a0c;
                int c = (a == (int)z);
                if (c) {
                    d_1c0a0c = 1;
                    OBST(ob[4], f_039660(d_1c0004, 10));
                    m = 0x2e0000bf;
                } else {
                    m = 0x2e0000c0;
                }
            }
            if (f_0bf6f0_x(A64, m) == 1) f_0603b0(0x47);
        }
        DTOR(ob[4]);
        return r;
    case 0x323:
        {
            signed char z = 0;
            int c = ((int)d_1c0a10 == (int)z);
            if (!c) goto out;
            d_1c0a10 = 1;
            f_0bf730(A64, 0x2e0000c1);
            return r;
        }
    case 0x324:
        f_0bf730(A64, 0x2e0000c2);
        return r;
    case 0x325:
        {
            signed char z = 0;
            int c = ((int)d_1c0a14 == (int)z);
            if (c) {
                d_1c0a14 = 1;
                CTOR(ob[1]);
                OBST(ob[1], f_039660(d_1c0004, 1));
                f_0bf730(A64, 0x2e0000c3);
                DTOR(ob[1]);
                return r;
            }
            f_0bf730(A64, 0x2e0000c4);
            return r;
        }
    case 0x326:
        { int k = 0x2e0000c5; if (f_0bf6f0_x(A64, k) != 1) goto out; }
        f_0bf730(A64, 0x2e0000c6);
        f_060800(0x2e0011, 0, 0);
        return r;
    case 0x328: { int k = 0x2e0000c8; f_0bf730(A64, k); } return r;
    case 0x329: { int k = 0x2e0000c9; f_0bf730(A64, k); } return r;
    case 0x32a:
        CTOR(ob[3]);
        { int k = 1; OBST(ob[3], f_039660(d_1c0004, k)); }
        f_0bf730(A64, 0x2e0000ca);
        DTOR(ob[3]);
        return r;
    case 0x32b:
        CTOR(ob[2]);
        OBST(ob[2], f_039320(d_1c0004, 0x12));
        f_0bf730(A64, 0x2e0000cb);
        DTOR(ob[2]);
        return r;
    case 0x32c:
        {
            signed char z = 0; int a = d_1c0a18;
            int c = (a == (int)z);
            if (c) {
                signed char one = 1;
                d_1c0a18 = one;
                f_0bf730(A64, 0x2e0000cc);
                return r;
            }
            f_0bf730(A64, 0x2e0000cd);
            return r;
        }
    case 0x32d: f_11b5f0(p1); return r;
    case 0x385:
        if (f_0bf6f0_x(A64, 0x2e0000d5) != 1) goto out;
        f_060800(0x2e0013, 0, 0);
        return r;
    case 0x386:
        if (f_0bf6f0_x(A64, 0x2e0000d6) != 1) goto out;
        f_0603b0(0x47);
        return r;
    case 0x1f43: f_11b790(p1); return r;
    case 0x1f44: f_11b790(p1); return r;
    case 0x388:
        {
            signed char z = 0;
            int c = ((int)d_1c0a20 == (int)z);
            if (c) {
                d_1c0a20 = 1;
                f_0bf730(A64, 0x2e0000d8);
            }
            f_060360(0x12);
            return r;
        }
    case 0x389:
        {
            int base = A64;
            f_0bf730(base, 0x2e0000d9);
            return r;
        }
    case 0x38a: f_11b9c0(p1); return r;
    case 0x38b:
        {
            d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt die Registerfolge in case 0x38b und case 0x322 wie im Original
            int base = A64;
            f_0bf730(base, 0x2e0000de);
            return r;
        }
    case 0x38c: f_0bf730(A64, 0x2e0000df); return r;
    case 0x38d: f_0bf730(A64, 0x2e0000e0); return r;
    case 0x38e: f_0bf730(A64, 0x2e0000e1); return r;
    case 0x38f: f_0bf730(A64, 0x2e0000e2); return r;
    case 0x391: ((void (*)(int))f_11bbc0)(p1); return r;
    case 0x392:
        if (!f_0bf6f0_x(A64, 0x2e0000ea)) goto out;
        f_060800(0x2e0017, 0, 0);
        return r;
    case 0x1b59:
    case 0x1f41:
        {
            int t_ = (int)operator new(0xc, mark(d_1a7d6c, 0x181));
            int q = t_ ? f_05f190(t_, 0, 0x1f41) : t_;
            if (EQ(f_05f580(q), 0)) {
                CTOR(ob[0]);
                OBST(ob[0], f_039320(d_1c0004, 0x30));
                f_0bf730(A64, 0x2e0000c7);
                f_05f480(q);
                DTOR(ob[0]);
            }
            if (!q) goto out;
            operator delete((void *)f_05f220(q, 0));
            return r;
        }
    case 0x1b5a: f_05fa00(0x38, 0x1f42); return r;
    case 0x1f42: f_05fa00(0x38, 0x1f42); return r;
    }
    r = 0;
out:
    return r;
}

//@ f_11b230
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt am Aufgang (0x2e0000be), ob die Gruppe die dritte Ebene verlassen möchte, und wechselt bei
 *   Bestätigung zurück in die erste Bienenstock-Ebene (7, Position 0x1459).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b230(void)
{
    if (f_0bf6f0(A64, 0x2e0000be) == 1) f_0dd7f0(d_1c0004, 7, 0x1459);
}

//@ f_11b260
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Betreten einer Gefahrenstelle eine Meldung (0x2e0000bf bzw. 0x2e0000c0) aus und löst bei
 *   Bestätigung das Ereignis 0x47 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b260(void)
{
    OB ob; int m;
    CTOR(ob);
    if (EQ(d_1c0a0c, 0)) {
        d_1c0a0c = 1;
        OBST(ob, f_039660(d_1c0004, 10));
        m = 0x2e0000bf;
    } else {
        m = 0x2e0000c0;
    }
    if (f_0bf6f0(A64, m) == 1) f_0603b0(0x47);
    DTOR(ob);
}

//@ f_11b2f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumes eine Beschreibungsmeldung (0x2e0000c1) aus und setzt das Flag
 *   d_1c0a10.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b2f0(void)
{
    if (EQ(d_1c0a10, 0)) {
        d_1c0a10 = 1;
        f_0bf730(A64, 0x2e0000c1);
    }
}

//@ f_11b320
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine kurze Raumbeschreibung (0x2e0000c2) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b320(void)
{
    f_0bf730(A64, 0x2e0000c2);
}

//@ f_11b340
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Untersuchen einer Stelle eine Meldung mit dem Namen des besten Helden (0x2e0000c3)
 *   und bei späteren Besuchen eine Folgemeldung (0x2e0000c4) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b340(void)
{
    OB ob;
    if (EQ(d_1c0a14, 0)) {
        d_1c0a14 = 1;
        CTOR(ob);
        OBST(ob, f_039660(d_1c0004, 1));
        f_0bf730(A64, 0x2e0000c3);
        DTOR(ob);
    } else {
        f_0bf730(A64, 0x2e0000c4);
    }
}

//@ f_11b3c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einem Übergang (0x2e0000c5), ob die Gruppe hinüberklettern möchte, gibt bei Zustimmung eine
 *   Meldung (0x2e0000c6) aus und führt die Bewegung (0x2e0011) durch.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b3c0(void)
{
    if (f_0bf6f0(A64, 0x2e0000c5) == 1) {
        f_0bf730(A64, 0x2e0000c6);
        f_060800(0x2e0011, 0, 0);
    }
}

//@ f_11b400
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet ein Objekt oder Versteck an Position 0x1f41 und gibt beim ersten Öffnen nach einer Probe auf
 *   Talent 0x30 eine Meldung (0x2e0000c7) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b400(void)
{
    OB ob; int q;
    { int t_ = (int)operator new(0xc, mark(d_1a7d6c, 0x181)); q = (t_ != 0) ? f_05f190(t_, 0, 0x1f41) : t_; }
    if (EQ(f_05f580(q), 0)) {
        CTOR(ob);
        OBST(ob, f_039320(d_1c0004, 0x30));
        f_0bf730(A64, 0x2e0000c7);
        f_05f480(q);
        DTOR(ob);
    }
    if (q) operator delete((void *)f_05f220(q, 0));
}

//@ f_11b4b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Raummeldung (0x2e0000c8) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b4b0(void)
{
    f_0bf730(A64, 0x2e0000c8);
}

//@ f_11b4d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Raummeldung (0x2e0000c9) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b4d0(void)
{
    f_0bf730(A64, 0x2e0000c9);
}

//@ f_11b4f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beobachtungsmeldung (0x2e0000ca) mit dem Namen eines Helden aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b4f0(void)
{
    OB ob;
    CTOR(ob);
    OBST(ob, f_039660(d_1c0004, 1));
    f_0bf730(A64, 0x2e0000ca);
    DTOR(ob);
}

//@ f_11b550
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt nach einer Probe auf Talent 0x12 eine Beobachtungsmeldung (0x2e0000cb) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b550(void)
{
    OB ob;
    CTOR(ob);
    OBST(ob, f_039320(d_1c0004, 0x12));
    f_0bf730(A64, 0x2e0000cb);
    DTOR(ob);
}

//@ f_11b5b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumes die Meldung 0x2e0000cc und bei späteren Besuchen 0x2e0000cd
 *   aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_119d90(void); void f_119e20(void); void f_119eb0(void); void f_119f00(void); int f_119f80(void); void f_11b5b0(void);
#define P ((int)&d_1c2c64)
#define EQM(x,v) (((x)==(v))?1:0)
void f_11b5b0(void)
{
    int r = EQM(d_1c0a18, 0);
    if (r) {
        d_1c0a18 = 1;
        f_0bf730(P, 0x2e0000cc);
    } else {
        f_0bf730(P, 0x2e0000cd);
    }
}

//@ f_11b5f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt eine Begegnung (d_1c0a1c), bei der der Spieler zwischen zwei Handlungsoptionen (0x2e0000cf
 *   / 0x2e0000d0) wählt, einen Kampf (0x59) austrägt und anschließend eine geschlechtsabhängige Folgeszene
 *   (0x2e0000d1 / 0x2e0000d2) für einen Begleitholden erlebt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b5f0(int p1)
{
    OB ob;
    short r = 0;
    if (EQ(d_1c0a1c, 0))
    {
        CTOR(ob);
        r = (short)f_0bf820(A64, 0x2e0000ce, 2, 0x2e0000cf, 0x2e0000d0);
        if (r == 2 || r == -1)
        {
            OBST(ob, f_039420(d_1c0004, 0x11));
            f_0bf730(A64, 0x2e0000d3);
        }
        {
            FP3 *pf = *(FP3 **)(p1 + 8);
            (*pf)(p1, 0x59, 0);
        }
        f_0697c0(p1 + 2, 0x59, 0);
        d_1c0a1c = 1;
        if (r == 1)
        {
            int q = f_1155d0(p1, 1);
            if (q)
            {
                int v = f_039580(d_1c0004, 1, 0);
                if (!v)
                    v = f_038c40(d_1c0004);
                OBST(ob, q);
                *(int *)(ob.addresses.objects + 8) = v;
                if ((signed char)f_042380((struct hero *)(q)) == 1)
                    f_0bf730(A64, 0x2e0000d1);
                else
                    f_0bf730(A64, 0x2e0000d2);
                d_1c0a24 = 1;
            }
        }
        DTOR(ob);
    }
}
//@ f_11b730
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einem Übergang (0x2e0000d5), ob die Gruppe weitergehen möchte, und führt bei Bestätigung den
 *   Ortswechsel 0x2e0013 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b730(void)
{
    if (f_0bf6f0(A64, 0x2e0000d5) == 1) f_060800(0x2e0013, 0, 0);
}

//@ f_11b760
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einer Gefahrenstelle (0x2e0000d6) nach einer Bestätigung und löst bei Zustimmung das
 *   Ereignis 0x47 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b760(void)
{
    if (f_0bf6f0(A64, 0x2e0000d6) == 1) f_0603b0(0x47);
}

//@ f_11b790
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den Kampf gegen die Wächter-Insekten (d_1c0934, d_1c0938) an den Durchgängen 0x1f43/0x1f45
 *   bzw. 0x1f44/0x1f46 über f_1150b0.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b790(int p1)
{
    if (GT(d_1c0934, 0)) {
        if (f_0bf6f0(A64, 0x2e0000d7) == 1) {
            f_1150b0(p1, f_038c40(d_1c0004), (int)&d_1c0934);
            if (EQ(d_1c0934, 0)) {
                f_060740(0x1f43, 1);
                f_060740(0x1f45, 1);
            }
        }
    }
    if (EQ(d_1c0934, 0) && GT(d_1c0938, 0)) {
        if (f_0bf6f0(A64, 0x2e0000d7) == 1) {
            f_1150b0(p1, f_038c40(d_1c0004), (int)&d_1c0938);
            if (EQ(d_1c0938, 0)) {
                f_060740(0x1f44, 1);
                f_060740(0x1f46, 1);
            }
        }
    }
}

//@ f_11b890
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eine Meldung (0x2e0000d8) aus, setzt das Flag d_1c0a20 und löst den Effekt
 *   0x12 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b890(void)
{
    if (EQ(d_1c0a20, 0)) {
        d_1c0a20 = 1;
        f_0bf730(A64, 0x2e0000d8);
    }
    f_060360(0x12);
}

//@ f_11b8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Raummeldung (0x2e0000d9) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b8d0(void)
{
    f_0bf730(A64, 0x2e0000d9);
}

//@ f_11b8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht analog zu f_114340 in der Heldengruppe nach einem geeigneten zweiten Helden für die Szene in
 *   der Königinnenkammer.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den ersten beteiligten Helden.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den zweiten ausgewählten Helden zurück oder 0, falls keiner
 *   verfügbar ist.
 === Ende Beschreibung === */
int f_11b8f0(int p1)
{
    volatile int save = p1; // haelt p1 ab Funktionsbeginn auf dem Stapel und sichert die Registerfolge wie im Original
    signed char c, c2;
    int r, p, t;
    short i, best, v;
    r = f_039580(d_1c0004, 1, 1);
    if (r == 0) {
        p = f_039040(d_1c0004);
        if (p != 0) {
            if (f_0d4a60(p) != 0) {
                best = 1000;
                for (i = 0; i < 6; i++) {
                    t = f_0de7d0(d_1c0004, (int)i);
                    if (t != 0) {
                        if (f_0d4a60(t) != 0 && t != save) {
                            c = f_043a80(t, 4);
                            v = c + 100;
                            c2 = f_042380((struct hero *)(t));
                            if (c2 != f_042380((struct hero *)(p))) v -= 100;
                            if (v < best) {
                                best = v;
                                r = t;
                            }
                        }
                    }
                }
            }
        }
    }
    return r;
}

//@ f_11b9c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert die Hauptszene und den Endkampf (0x5a) in der Kammer der Königin (d_1c09a8), lässt zwei
 *   Helden eine traumatische oder gefährliche Begegnung durchleben und vergibt nach dem Sieg Abenteuerpunkte
 *   (0x8030038).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11b9c0(int p1)
{
    OB ob; short s; int a, b, m;
    CTOR(ob);
    if (EQ(d_1c09a8, 0)) m = 0x2e0000da; else m = 0x2e0000dd;
    s = f_0bf6f0(A64, m);
    if (s == (short)1) {
        f_060800(0x2e0015, 0, 0);
        if (EQ(d_1c09a8, 0)) {
            a = f_039660(d_1c0004, 4);
            b = f_11b8f0(a);
            *(int *)(ob.addresses.objects + 4) = a;
            *(int *)(ob.addresses.objects + 8) = b;
            f_0bf730(A64, 0x2e0000db);
            if (b != 0 && b != a) {
                f_0bf730(A64, 0x2e0000dc);
                s = f_0d4c80(b);
                f_0d5040(b, (int)s, 0x3f480, 2, -1, 0);
            }
            s = (short)(**(FP3 **)(p1 + 8))(p1, 0x5a, 0);
            if (s == 0) {
                d_1c09a8 = 1;
                f_057220((int)&d_1c2c00, 0x8030038, 0);
            }
        }
    }
    DTOR(ob);
}

//@ f_11baf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beschreibungsmeldung (0x2e0000de) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11baf0(void)
{
    f_0bf730(A64, 0x2e0000de);
}

//@ f_11bb10
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beschreibungsmeldung (0x2e0000df) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bb10(void)
{
    f_0bf730(A64, 0x2e0000df);
}

//@ f_11bb30
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beschreibungsmeldung (0x2e0000e0) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bb30(void)
{
    f_0bf730(A64, 0x2e0000e0);
}

//@ f_11bb50
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beschreibungsmeldung (0x2e0000e1) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bb50(void)
{
    f_0bf730(A64, 0x2e0000e1);
}

//@ f_11bb70
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beschreibungsmeldung (0x2e0000e2) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bb70(void)
{
    f_0bf730(A64, 0x2e0000e2);
}

//@ f_11bb90
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x38 an der Position 0x1f42.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bb90(void)
{
    f_05fa00(0x38, 0x1f42);
}

//@ f_11bbc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das Untersuchen und Aufschneiden eines großen Kokons oder Beutelagers (0x49, d_1c0958),
 *   bietet dem Spieler drei Vorgehensweisen (0x2e0000e4 bis 0x2e0000e6) an, schaltet bei Erfolg den Beutesatz
 *   0x5b, einen Tagebucheintrag (0x31) sowie Abenteuerpunkte (0x8030039) frei und öffnet den Beutedialog.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bbc0(void)
{
    OB o;
    int q;
    CTOR(o);
    q = (int)operator new(0x14, mark(d_1a7d6c, 0x3f3));
    q = q ? f_112df0(q, 0x49, 0, 0) : q;
    if (EQ(d_1c0958, 0)) {
        unsigned short k = (unsigned short)(f_0bf820(A64, 0x2e0000e3, 3, 0x2e0000e4, 0x2e0000e5, 0x2e0000e6) + 1);
        switch (k) {
        case 1:
            break;
        case 2:
            OBST(o, f_039320(d_1c0004, 0x12));
            f_0bf730(A64, 0x2e0000e7);
            break;
        case 3:
            OBST(o, f_039420(d_1c0004, 0x12));
            f_0bf730(A64, 0x2e0000e8);
            d_1c0958 = 1;
            f_1134d0(q, 0x5b);
            f_060740(0x1f47, 1);
            f_091f70(0x31);
            f_057220((int)&d_1c2c00, 0x8030039, 0);
            break;
        case 0:
        case 4:
            f_112ec0_d(q);
            break;
        }
    } else {
        OBST(o, f_039320(d_1c0004, 0x12));
        f_0bf730(A64, 0x2e0000e9);
        if (f_1131b0(q))
            f_112ec0(q);
    }
    if (q) {
        operator delete((void *)f_112e70(q, 0));
    }
    DTOR(o);
}
