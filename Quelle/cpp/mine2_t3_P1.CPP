/* === Beschreibung (Katalog) ===
 * Einheit mine2_t3
 *
 * Diese Einheit gehört zu mine2.cpp und bildet den dritten Teil der Ereignis- und Rätsellogik für die zweite
 * Ebene der Zwergenmine (0x35), darunter die Grubengas-Schadensberechnung, eine mehrstufige Klettersequenz,
 * Gegenstandswürfe in einen Schacht sowie die gegenseitige Verriegelung dreier Lorenschalter.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/13 gleich (suche.py 26.10.2026, Basis mine2_t3_P1.CPP)
// mine2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil t3 0x0C88C0-0x0C9940
#include <string.h>
inline int EQ(int a, int b) { return a == b; }
inline int NE(int a, int b) { return a != b; }
#define G(x,v) (((x)==(v))?1:0)
struct SO { char a[4]; int *p; int *r; int *q; char c[16]; short *t; char d[24]; };
struct OB;
struct VTB { short (*f)(OB *, int, int); };
struct OB { int a0, a4; VTB *v; };
struct N14 { char b[0x14]; };
struct N12 { char b[12]; };
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
short f_0bf820(const char *, ...);
int f_041030(int, ...);
int f_041530();
int f_041920(int);
int f_0cda50();
int f_09a400();
int f_0f2720(int);
int f_147323(char *, int, int, int, int, int, int);
extern char d_1c2edc[];
int f_0bf6f0(const char *, int);
int f_0bf730(const char *, int);
int f_038c40(int);
int f_038cb0(int);
int f_038d70(int, int);
int f_038e90(int, int);
int f_0396f0(int, int);
int f_039660(int, int);
int f_039320(int, int);
int f_039a80(int, int);
int f_039ac0(int, int);
int f_040780(int, int);
short f_0d4c80(int);
int f_0d5040(int, int, int, int, int, int);
int f_0d4a60(int);
int f_0de7d0(int, int);




signed char f_043a80(int, int);
unsigned char f_0441b0(int);
int f_0441d0(int, int);
int f_044300(int, int);
int f_044850(int, int, int);
short f_044900(int, int, int);
short f_044c90(int, int, int);
short f_032820(int, int, int);
int f_036300(int, int, int);
short f_145850(int, int, int);
short f_149360(int, const char *);
short f_0d54f0(int, int);
short f_0de480(int, int);
unsigned short f_0db9a0(int);
int f_0dcbb0(int, int);
short f_0dcf00(int, int, int);
int f_0dd7f0(int, int, int);
int f_0de210(int);
int f_0dbeb0(int);
int f_0dcae0(int);
int f_057220(char *, int, int);
int f_060800(int, int, int);
int f_091f70(int);



N14 *f_112df0(N14 *, int, int, int);
int f_113340(N14 *, int, int, int);
void *f_112e70(N14 *, int);
N12 *f_05f190(N12 *, int, int);
void *f_05f220(N12 *, int);
int f_05f280(N12 *, int);
int f_05f360(N12 *);
int f_05f580(N12 *);
int f_05f5a0(N12 *, int);
int f_0c7b50(int);
extern signed char d_1bf2d4, d_1bf2dc, d_1bf2f0, d_1bf2e0, d_1bf2e4, d_1bf2c4, d_1bf2f3, d_1bf2f4, d_1bf2ec, d_1bf2e8;
extern char d_1bf2b8;
extern short d_1c21a4, d_1bd922;
extern int d_1c0004;
extern short d_1a9820;

extern char d_1c2c64[], d_1c2c00[];
extern char d_1a56ea[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[], d_1a56bc[];
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0c88c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt ein Gefahrenereignis in der Mine (d_1bf2d4, d_1bf2dc), spielt den Sound
 *   0x350037 ab, sucht bei Bestätigung (0x3500011d) den handlungsfähigen Helden mit der höchsten Lebensenergie
 *   und lässt diesen zwischen zwei Reaktionen (0x3500011f, 0x35000120) wählen, die entweder 2W6+4 Schadenspunkte
 *   samt Attributsmalus oder 1W6+3 Schadenspunkte verursachen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c88c0(void)
{
    int f_147323_frame_c88c0(char *, int, int, int, int, int, int);
#pragma aux f_147323_frame_c88c0 "f_147323" modify [esp]
    SO o;
    int e;
    int s;
    short i;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = f_038c40(d_1c0004);
    if (G(d_1bf2d4, 0)) {
        if (G(d_1bf2dc, 0)) {
            int snd = *(int *)&d_1a9820;
            f_147323_frame_c88c0(d_1c2edc, 0x350037, 0x7fff, 0x8000, snd, 0, 1);
            if (f_0bf6f0(d_1c2c64, 0x3500011d) == 1) d_1bf2d4 = 1;
            else f_060800(0x350022, 0, 0);
        }
    }
    if (G(d_1bf2d4, 1)) {
        s = 0;
        for (i = 0; ; i++) {
            int k = (short)i;
            if (k >= 7) break;
            if ((e = f_0de7d0(d_1c0004, k)) != 0 && f_0d4a60(e) != 0) {
                if (s != 0) {
                    if (f_042960((struct hero *)(s)) < f_042960((struct hero *)(e))) s = e;
                } else {
                    s = e;
                }
            }
        }
        o.p[2] = s;
        if (f_0bf820(d_1c2c64, 0x3500011e, 2, 0x3500011f, 0x35000120) == 1) {
            f_0bf730(d_1c2c64, 0x35000121);
            f_044850(s, f_145850(2, 6, 4), 1);
            f_0d5040(s, f_0d4c80(s), 0x3f480, 4, -2, 0);
        } else {
            f_044850(s, f_145850(1, 6, 3), 1);
            f_0bf730(d_1c2c64, 0x35000122);
        }
    }
    f_1254a0(&o, 0);
}
//@ f_0c8a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Betreten eines Bereichs (d_1bf2dc == 0), welcher Held den höchsten Wert im
 *   Talent 0xc besitzt, gibt den Hinweis 0x35000123 aus, übergibt der Gruppe den Gegenstand 0x1a9 (f_0dcf00) und
 *   setzt d_1bf2d4 auf 0.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8a90(void)
{
    SO o;
    short s;
    if (G(d_1bf2dc, 0)) {
        f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
        o.p[1] = f_039320(d_1c0004, 0xc);
        f_0bf730(d_1c2c64, 0x35000123);
        s = f_0dcf00(d_1c0004, 0x1a9, 1);
        if (s == 1) d_1bf2dc = 1;
        f_1254a0(&o, 0);
    }
    d_1bf2d4 = 0;
}
//@ f_0c8b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert den Übergang oder Ausgang an einer besonderen Stelle der zweiten
 *   Zwergenminen-Ebene (d_1bf2f0), spielt eine Zwischensequenz (0x803003e) ab, vergibt einen Tagebucheintrag (2)
 *   und versetzt die Gruppe in den Zielbereich 0x11 (Position 5000).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8b20(void)
{
    if (G(d_1bf2f0, 0)) {
        if (f_0f2720(4) == 0) {
            f_0dd7f0(d_1c0004, 0x11, 5000);
            f_057220(d_1c2c00, 0x803003e, 0);
            f_091f70(2);
            d_1bf2f0 = 1;
            return;
        }
        f_0de210(d_1c0004);
        d_1c21a4 = 7;
    } else {
        f_0f2720(4);
        f_0dd7f0(d_1c0004, 0x11, 5000);
    }
}
//@ f_0c8bc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt mit dem übergebenen Fragetext p2 ab, ob die Gruppe in einen Abgrund oder Schacht
 *   hinabsteigen möchte, spielt bei Bestätigung den Sturzsound 0x350032 ab, gibt je nach Seilbesitz (f_0c7b50)
 *   den Todestext 0x350000f3 oder 0x350000f4 aus und löscht die gesamte Gruppe aus (f_0dbeb0, f_0dcae0).
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie die Text-ID p2 für die Bestätigungsfrage.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8bc0(int p1, int p2)
{
    int id;
    if (f_0bf6f0(d_1c2c64, p2) == 1) {
        f_147323(d_1c2edc, 0x350032, 0x7fff, 0x8000, (id = *(int *)&d_1a9820), 0, 1);
        if (f_039ac0(d_1c0004, (int)f_0c7b50)) f_0bf730(d_1c2c64, 0x350000f3);
        else f_0bf730(d_1c2c64, 0x350000f4);
        f_0dbeb0(d_1c0004);
        f_0dcae0(d_1c0004);
    }
}
//@ f_0c8c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft die Begegnungsflags d_1bf2e0 und d_1bf2e4, startet bei Bedarf über die virtuelle
 *   Methode des Dungeon-Handlers die Kämpfe 0x28 und 0x29 (d_1bd922 = 8) und trägt bei einem Sieg im zweiten
 *   Gefecht den Tagebucheintrag 0 (f_091f70(0)) ein.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8c40(OB *p1)
{
    SO o;
    if (G(d_1bf2e0, 0)) {
        f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
        o.p[1] = f_0396f0(d_1c0004, 0);
        f_0bf730(d_1c2c64, 0x350000a8);
        d_1bd922 = 8;
        if (p1->v->f(p1, 0x28, 0) == 0) {
            f_09a400();
            d_1bf2e0 = 1;
            o.p[1] = f_039660(d_1c0004, 0xb);
            f_0bf730(d_1c2c64, 0x350000a9);
        }
        f_1254a0(&o, 0);
    }
    if (G(d_1bf2e4, 0) && d_1c21a4 == 0) {
        d_1bd922 = 8;
        if (p1->v->f(p1, 0x29, 0) == 0) {
            d_1bf2e4 = 1;
            f_091f70(0);
        }
    }
}
//@ f_0c8d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt einen Angriff oder Steinwurf auf die Kreaturen im Schacht aus, spielt das
 *   Geräusch 0x350034 und die Animation 0x35000c ab, verletzt bei gesetztem Flag d_1bf2c4 == 1 den handelnden
 *   Helden p2 (f_044850(p2, 3, 5)) und ruft anschließend die Kampffolgelogik f_0c8c40 auf.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Dungeon-Verwaltungsstruktur, der Zeiger p2 auf den
 *   handelnden Helden sowie das Modusflag p3.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8d50(OB *p1, int p2, int p3)
{
    int f_147323_frame(int, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp]
    SO o;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = p2;
    int snd = *(int *)&d_1a9820;
    f_147323_frame((int)d_1c2edc, 0x350034, 0x7fff, 0x8000, snd, 0, 1);
    if (p3 == 0) {
        if ((short)f_0db9a0(d_1c0004) > 1) f_0bf730(d_1c2c64, 0x350000a5);
        else f_0bf730(d_1c2c64, 0x350000a6);
    }
    f_060800(0x35000c, 0, 0);
    if ((short)f_0cda50() != -1) f_041530();
    if (G(d_1bf2c4, 1)) {
        f_0bf730(d_1c2c64, 0x350000a7);
        f_044850(p2, 3, 5);
    }
    f_0c8c40(p1);
    f_1254a0(&o, 0);
}
//@ f_0c8e40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den Text 0x350000aa aus, fragt bei einer mehrköpfigen Gruppe (0x350000ab), ob ein
 *   zufälliger Held (f_038cb0) oder der Anführer (f_038c40) vorgehen soll, und leitet die Aktion an f_0c8d50
 *   weiter.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8e40(OB *p1)
{
    SO o;
    short s;
    int a, e, fl;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    s = f_0db9a0(d_1c0004);
    a = f_038c40(d_1c0004);
    o.p[1] = a;
    f_0bf730(d_1c2c64, 0x350000aa);
    if (s != 1) {
        if (f_0bf6f0(d_1c2c64, 0x350000ab) == 1) {
            e = f_038cb0(d_1c0004);
            fl = 0;
            goto L1;
        }
        f_041920(f_041030(1, a));
    }
    fl = 1;
    e = f_038c40(d_1c0004);
L1:
    f_0c8d50(p1, e, fl);
    f_1254a0(&o, 0);
}
//@ f_0c8ef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler einen Helden (0x350000ac) und einen Inventargegenstand (0x350000ad)
 *   auswählen, um diesen in den Schacht oder auf das Hindernis zu werfen, entfernt den Gegenstand aus dem
 *   Inventar und legt ihn bei passendem Typ (fl == 1) im Beutelager 0x19 ab, wobei brennbare oder explosive
 *   Gegenstände (f_0a7990() == 1) das Flag d_1bf2c4 = 1 setzen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c8ef0(void)
{
    SO o;
    short u = -1;
    int a = 0, p1, fl, id;
    short sel;
    int k;
    N14 *q;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    sel = -1;
    if ((short)f_0db9a0(d_1c0004) > 1)
        p1 = f_038e90(d_1c0004, 0x350000ac);
    else
        p1 = f_038c40(d_1c0004);
    if (p1) {
        sel = f_032820(p1, 0x350000ad, 0);
        if (sel != -1) {
            u = ((unsigned short)(f_042a60((struct hero *)(p1), sel)));
            a = p1;
            if (!f_0d4a60(p1)) a = f_038c40(d_1c0004);
            o.p[1] = a;
        }
    }
    if (u != -1) {
        k = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[(short)u]))->f_0a7950() ? f_042ac0((struct hero *)(p1), sel) : 1;
        o.p[1] = a;
        int off = (short)u;
        int base = (int)(*(int **)&d_1c2c40);
        int *rec = (int *)(off * 4 + base);
        o.q[1] = *rec;
        o.t[1] = k;
        if (((RivaItemDefinition*)(*rec))->f_0a78f0() == 1) {
            f_0bf730(d_1c2c64, 0x350000ae);
            f_1254a0(&o, 0);
            return;
        }
        { signed char c = d_1bf2e4; fl = c; }
        switch ((unsigned short)u) {
        case 0x16:
            id = (unsigned char)(fl == 1) + 0x350000af;
            fl = 0;
            break;
        case 0x41:
            id = 0x350000b1;
            fl = 1;
            break;
        case 0x19:
            id = 0x350000b2;
            fl = 0;
            break;
        case 0xf9:
            id = 0x350000b3;
            fl = 0;
            break;
        case 0xef:
            id = (unsigned char)(EQ(fl, 1) != 0) + 0x350000b4;
            fl = 0;
            break;
        case 0x105:
        case 0x106:
        case 0x107:
            id = (unsigned char)(fl == 1) + 0x350000b6;
            fl = 1;
            break;
        default:
            if (f_149360(u, d_1a56ea) != -1) {
                id = 0x350000b8;
                fl = 0;
            } else {
                id = 0x350000b9;
                fl = 1;
            }
        }
        f_0bf730(d_1c2c64, id);
        f_036300(p1, sel, (short)k);
        if (fl == 1) {
            N14 *t = new (mark(d_1a56bc, 0x8fa)) N14;
            q = t ? f_112df0(t, 0x19, 0, 0) : t;
            f_113340(q, u, (short)k, 0);
            if (q) operator delete(f_112e70(q, 0));
            int *tab = (*(int **)&d_1c2c40);
            int item = tab[(short)u];
            if (((RivaItemDefinition*)(item))->f_0a7990() == 1) d_1bf2c4 = 1;
        }
    }
    f_1254a0(&o, 0);
}
//@ f_0c91b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wirkt als Gruppen-Callback in den Grubengasfeldern, erhöht den Gas-/Erstickungswert
 *   eines Helden um die Gasdichte d_1bf2f3 (bei hoher Ausdauer oder für Zwerge der Klasse 6 doppelt verrechnet)
 *   und zieht dem Helden bei Überschreiten seiner Konstitutionsschwelle 4 Lebenspunkte ab (0x35000104).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c91b0(int p1)
{
    if (f_0d4a60(p1) != 0) {
        unsigned char b;
        short sc;
        f_0441d0(p1, d_1bf2f3);
        sc = f_042960((struct hero *)(p1)) + f_043a80(p1, 6);
        if (sc - f_0441b0(p1) > 0x50 || f_042350((struct hero *)(p1)) == 6) f_0441d0(p1, d_1bf2f3);
        b = f_0441b0(p1);
        if (b > sc) {
            SO o;
            sc = f_042960((struct hero *)(p1));
            f_044300(p1, (short)(sc - 4));
            f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
            o.p[1] = p1;
            f_0bf730(d_1c2c64, 0x35000104);
            f_1254a0(&o, 0);
        }
    }
}
//@ f_0c9290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft als Gruppen-Callback mit einer um d_1bf2f4 erschwerten Sinnesschärfe-Probe
 *   (0x33), ob ein Held das ausströmende Grubengas bemerkt, gibt bei Erfolg die Warnung 0x35000105 aus und setzt
 *   Bit 0 in d_1bf2b8.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Die Funktion gibt 1 zurück, sobald ein Held das Gas bemerkt hat (damit die Suche abbricht),
 *   andernfalls 0.
 === Ende Beschreibung === */
int f_0c9290(int p1)
{
    SO o;
    int r = 0;
    if (f_0d4a60(p1) != 0) {
        if (f_044c90(p1, 0x33, d_1bf2f4) > 0) {
            f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
            o.p[1] = p1;
            f_0bf730(d_1c2c64, 0x35000105);
            d_1bf2b8 |= 1;
            r = 1;
            f_1254a0(&o, 0);
        }
    }
    return r;
}
//@ f_0c9310
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion koordiniert die Wirkung eines Grubengasfeldes der Stärke p2, indem sie zunächst
 *   f_0c91b0 auf alle Helden anwendet und anschließend - sofern das Gas noch nicht erkannt wurde ((d_1bf2b8 & 1)
 *   == 0) - über f_0c9290 eine Sinnesschärfe-Probe mit der Erschwernis p3 durchführt.
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1, die Gasintensität p2 sowie der
 *   Proben-Modifikator p3.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c9310(int p1, int p2, short p3)
{
    d_1bf2f3 = p2;
    f_039a80(d_1c0004, (int)f_0c91b0);
    if ((short)f_0db9a0(d_1c0004) <= 0) return;
    unsigned char flag = d_1bf2b8;
    flag = !!(flag &= 1);
    if (flag != 0) return;
    *(short *)&d_1bf2f4 = p3;
    f_039ac0(d_1c0004, (int)f_0c9290);
}
//@ f_0c9380
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine mehrstufige Klettersequenz (s = 0 bis 6), bei der ein ausgewählter Held
 *   (0x350000bb) unter Berücksichtigung von Hilfsmitteln (0x167 gibt +5, Questflag 0x79 gibt +3) eine
 *   Attributsprobe auf 4 (-6) und vier aufeinanderfolgende Kletterproben (Talent 10) ablegen muss, bei
 *   Fehlschlägen Sturzschaden oder Wunden erleidet und beim Erreichen des Ziels Abenteuerpunkte (20 bzw. 40 AP,
 *   d_1bf2ec = 1) erhält.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c9380(void)
{
    
    struct Actor905 {
      short skill(short n,signed char m) { return f_044c90((int)this,n,m); }
      short attribute(short n,signed char m) { return f_044900((int)this,n,m); }
      void hurt(short n) { f_044300((int)this,n); }
      void injury(short n,short m) { f_044850((int)this,n,m); }
      void reward(short n) { f_040780((int)this,n); }
    };
    struct Value905 {
      static int i(int x) { return x; }
      static int count(short x) { return x; }
    };
    SO o;
    union { int n; short lo; } count905; count905.n=0; Actor905 *a; int zero;
    short s;
    unsigned char lv,t;
    signed char c3,c2,c1;
    if(f_0bf6f0(d_1c2c64,0x350000ba)!=1) return;
    a=(Actor905*)f_038d70(d_1c0004,0x350000bb);
    if (a == 0) return;
    short r=f_0d54f0(d_1c0004,0x167);
    t=0;
    if(r!=-1) t=5;
    else if(f_0de480(d_1c0004,0x79)>0) t=3;
    lv=t;
    if(Value905::i(lv)==0 && (short)f_0db9a0(d_1c0004)>1) f_041920(f_041030(1,a));
    s=0;
    f_125400(&o,d_1c349c,d_1c3870,d_1c3498);
    o.p[1]=(int)a;
    c1=-5-lv;
    c2=-7-lv;
    c3=-2-lv;
    zero=0;
    do {
      switch((unsigned short)s) {
      case 0:
        if(a->attribute(4,-6)>0) {
          if (Value905::i(lv) != 0) f_0bf730(d_1c2c64,0x350000bc);
          else f_0bf730(d_1c2c64,0x350000bd);
          s=1; f_060800(0x35000e,zero,zero);
        } else {
          f_0bf730(d_1c2c64,0x350000be);
          s=6; f_060800(0x350010,zero,zero);
          a->hurt(2);
        } break;
      case 1:
        if(a->skill(10,c1)>0 && Value905::i(count905.lo)<8) {
          f_0bf730(d_1c2c64,0x350000bf);
          s=2; f_060800(0x350012,zero,zero);
        } else {
          ++count905.n; f_0bf730(d_1c2c64,0x350000c0);
          a->hurt(3);
          s=6; f_060800(0x35001a,zero,zero);
        } break;
      case 2:
        if(a->skill(10,c2)>0 && Value905::i(count905.lo)<8)
          f_0bf730(d_1c2c64,0x350000c1);
        else {
          ++count905.n; f_0bf730(d_1c2c64,0x350000c2);
          a->injury(3,5);
        }
        s=3; f_060800(0x350014,zero,zero); break;
      case 3:
        if(a->skill(10,(signed char)-lv)>0 && Value905::i(count905.lo)<8) {
          f_0bf730(d_1c2c64,0x350000c3);
          s=4; f_060800(0x350016,zero,zero);
        } else {
          f_0bf730(d_1c2c64,0x350000c4);
          ++count905.n; f_060800(0x35001c,zero,zero); s=2;
        } break;
      case 4:
        if(a->skill(10,c3)>0 && Value905::i(count905.lo)<8) {
          f_0bf730(d_1c2c64,0x350000c5);
          s=5; f_060800(0x350018,zero,zero);
        } else {
          f_0bf730(d_1c2c64,0x350000c6);
          ++count905.n; a->hurt(4);
          s=6; f_060800(0x35001e,zero,zero);
        } break;
      case 6: break;
      case 5:
        if(Value905::i(lv) && (short)f_0db9a0(d_1c0004)>1) {
          f_0bf730(d_1c2c64,0x350000c7);
          if(EQ(d_1bf2ec,0)) {
            f_0dcbb0(d_1c0004,0x14); a->reward(0x14); d_1bf2ec=1;
          }
        } else if(EQ(d_1bf2ec,0)) {
          a->reward(0x28); d_1bf2ec=1;
        }
        s=6; break;
      }
    } while(s!=6);
    { signed char round905=d_1bf2e8; d_1bf2e8=round905; } // haelt die Stapelplatz-Reihenfolge wie im Original
    f_1254a0(&o,0);
}
//@ f_0c9790
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet die gegenseitige Verriegelung der drei Weichen- bzw. Hebelobjekte 0x1f41
 *   (0x15), 0x1f42 (0x52) und 0x1f43 (0x16), sodass beim Umlegen des Schalters p2 die jeweils anderen aktiven
 *   Schalter zurückgestellt werden.
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie der Index p2 (0 bis 2) des betätigten
 *   Schalters.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c9790(int p1, short p2)
{
    N12 *o[3];
    short k;
    short a, b;
    {
        void *t = operator new(12, mark(d_1a56bc, 0xa7e));
        o[0] = t ? f_05f190((N12 *)t, 0x15, 0x1f41) : (N12 *)t;
    }
    {
        void *t = operator new(12, mark(d_1a56bc, 0xa7f));
        o[1] = t ? f_05f190((N12 *)t, 0x52, 0x1f42) : (N12 *)t;
    }
    {
        void *t = operator new(12, mark(d_1a56bc, 0xa80));
        o[2] = t ? f_05f190((N12 *)t, 0x16, 0x1f43) : (N12 *)t;
    }
    k = p2;
    a = (p2 + 1) % 3;
    b = (p2 + 2) % 3;
    if (G(f_05f580(o[p2]), 0) && (f_05f580(o[a]) != 0 || f_05f580(o[b]) != 0)) {
        if (f_05f360(o[k]) == 1) {
            if (f_05f580(o[a]) != 0) f_05f5a0(o[a], 1);
            if (f_05f580(o[b]) != 0) f_05f5a0(o[b], 1);
            f_05f280(o[k], 0);
        }
    } else {
        d_1bf2e8 = 0;
        f_05f280(o[k], 0);
    }
    if (o[2]) operator delete(f_05f220(o[2], 0));
    if (o[1]) operator delete(f_05f220(o[1], 0));
    if (o[0]) operator delete(f_05f220(o[0], 0));
}
