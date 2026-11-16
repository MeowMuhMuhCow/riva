/* === Beschreibung (Katalog) ===
 * Einheit gz_0e2ac0
 *
 * Diese Einheit umfasst den zweiten Teil von poolinit.cpp (Zusammenstellen des Händlersortiments,
 * Inventarfilterung und Preisberechnung nach Zustand und Händlerart) sowie den Beginn von popup.cpp
 * (Zugriffsmethoden, Hintergrundsicherung und Rahmenaufbau von Popup-Dialogfenstern).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 21/25 gleich (suche.py 26.10.2026, Basis gz_0e2ac0_P1.CPP)
// gz_0e2ac0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E2AC0-0x0E36D0
#include <string.h>
struct Q { short s0, s2, s4; };
struct E { short s0, s2, s4, s6, s8, sa; int c; short s10, s12; int s14; };
struct A { char p0[4]; short s4; short s6; char p8[2]; short n; struct E *tab; };
struct P { struct A *a; int p4; struct Q *q; void *fn; int adj; };
struct W { char p0[8]; char *buf; char p1[8]; short x, y; char p2[4]; short s1c; char p3[8]; short w; char p4[2]; short h; };
typedef int (*FN)(struct P *, int);
typedef FN (*GN)(struct P *, int *, int, int);
signed char f_01c840x;
void f_01c840(int p1);
unsigned short f_01dfb0(int p1);
int f_038c80(int p1);
int f_0391b0(int p1, int p2);




int f_05e2a0(char *p1, short *p2, short *p3, short *p4, short *p5);
int f_05e2d0(char *p1, int p2, int p3, int p4, int p5);
int f_05e7e0(char *p1, int p2, int p3);
int f_05e800(char *p1, short *p2, short *p3);
void f_0757f0(int p1);












int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0e36d0(struct W *p1, int p2, int p3, int p4);
int f_149d20();
int f_0e2cb0(struct P *p1, short p2, short p3, short p4, int p5);
void f_0e2f70(struct P *p1, short p2, short p3, short p4, int p5);
extern char *d_1a34e0;
extern volatile short d_1bc764;
extern int d_1bc760;
extern int d_1bd914;
extern short d_1bd910;
extern volatile int d_1bda54;
extern short d_1be258;
extern int d_1c0004;

extern char d_1c38b0[];
struct MG {
    int fl;
    MG()
    { fl = 0; if (f_0d3860() == 1) { f_0d2710(); fl = 1; } }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
#define CPY(stmt) for (i = 0; i < p1->h; i++) { stmt; }
#define L12(body) for (i = 1; i < d_1be258; i++) { body }
//@ f_0e2ac0  groesse 208 B, 81 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * Durchläuft für die Händlerkategorie p2 mit dem Filterbit p3 alle Gegenstandsdefinitionen des Spiels (1 bis
 * d_1be258 - 1), prüft, ob die Handelsstufe des Gegenstands (f_0a78d0) mindestens dem Sortimentswert des
 * Händlers (p1->a->s4) entspricht und der Gegenstand zum Kategorienfilter p3 passt (f_0e2cb0), und trägt ihn mit
 * unbegrenzter Stückzahl (-1) über f_0e2f70 in das Händlersortiment ein.
 * - Eingaben: Übergeben werden der Zeiger auf die Pool-Struktur p1, der Kategorieregister-Index p2 (0..3) sowie
 *   das Kategorien-Filterbit p3.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2ac0(struct P *p1, short p2, int p3)
{
    short i;
    int sVar1;
    short iVar5;
    int c;
    p1->q[p2].s2 = p1->a->n;
    L12(iVar5 = i; sVar1 = p1->a->s4; c = ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[iVar5]))->f_0a78d0())); if (c >= sVar1 && f_0e2cb0(p1, iVar5, p3, 0, 0) == 1) f_0e2f70(p1, -1, iVar5, 0, 0);)
    p1->q[p2].s4 = p1->a->n - p1->q[p2].s2;
}
#define SEL if (s3 == 0) goto one; else if (s3 > 1) { if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[q]))->f_0a7950() != 0) goto two; one: s3 = 1; two:; }
#define FORI \
    for (i = 0; i < 0x1f; i++) { \
        s2 = f_042a60((struct hero *)(iVar4), i); \
        q = s2; \
        if (q > 0) { \
            if (f_0e2cb0(p1, q, p3, i, iVar4) != 0) { \
                s3 = f_042ac0((struct hero *)(iVar4), i); \
                SEL \
                f_0e2f70(p1, s3, s2, i, iVar4); \
            } \
        } \
    }
//@ f_0e2b90  groesse 288 B, 91 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * Sammelt für das Kategorieregister p2 (Filterbit p3) im Verkaufs- oder Beutelager-Modus alle passenden
 * Gegenstände aus den 31 Inventarplätzen (0..30) sämtlicher Gruppenmitglieder (f_038c80 / f_0391b0) ein und
 * trägt sie samt Stückzahl, Inventarslot und Heldenzeiger über f_0e2f70 in die Pool-Liste ein.
 * - Eingaben: Übergeben werden der Zeiger auf die Pool-Struktur p1, der Kategorieregister-Index p2 sowie das
 *   Kategorien-Filterbit p3.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2b90(struct P *p1, short p2, short p3)
{
    int iVar4;
    short i, s2, s3;
    short q;
    s2 = (s2 & 0) ? 0 : s2; // haelt die Registerzuteilung wie im Original
    iVar4 = f_038c80(d_1c0004);
    p1->q[p2].s2 = p1->a->n;
    for (;;) {
        FORI
        iVar4 = f_0391b0(d_1c0004, iVar4);
        if (iVar4 == f_038c80(d_1c0004)) {
            p1->q[p2].s4 = p1->a->n - p1->q[p2].s2;
            return;
        }
    }
}
#define OBJ (*(int **)&d_1c2c40)[p2]
#define QO OBJ
//@ f_0e2cb0  groesse 704 B, 217 Bef, reg edx ebx ecx, stapel 4
/* === Beschreibung (Katalog) ===
 * Prüft, ob ein Gegenstand mit der Kennung p2 (optional aus dem Inventarslot p4 des Helden p5) in die durch das
 * Bitflag p3 angeforderte Warenkategorie fällt, sofern er nicht als unverkäuflicher Questgegenstand (f_0a78f0()
 * != 0) markiert ist: 0x02 für Waffen, 0x04 für Rüstungen, 0x08 für gewöhnliche Kräuter/Tränke, 0x10 für
 * Spezialelixiere, 0x20 bzw. 0x40 für beschädigte oder vergiftete/magisch verbrauchte Waffen bzw. Rüstungen,
 * 0x80 für sonstige Gebrauchsgegenstände und 0x100 für allgemeine Waren ohne Nahrung/Kräuter.
 * - Eingaben: Übergeben werden die Pool-Struktur p1, die Gegenstandskennung p2, das Kategorien-Filterbit p3, der
 *   Inventarplatz p4 sowie der Heldenzeiger p5 (0 bei Händlerwaren).
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Gegenstand den Filterkriterien entspricht, andernfalls 0.
 === Ende Beschreibung === */
int f_0e2cb0(struct P *p1, short p2, short p3, short p4, int p5)
{
    int result = 0;
    volatile int local_10;
    short sVar2 = 0;
    local_10 = 0;
    if (p5) {
        local_10 = f_042bb0((struct hero *)(p5), p4);
        sVar2 = f_042b50((struct hero *)(p5), p4);
    }
    if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a78f0()) return result;
    switch ((unsigned short)p3) {
    case 2:
        result = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7990();
        break;
    case 4:
        result = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a79b0();
        break;
    case 8:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7910() == 1 && ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a78b0())) != 1)
            result = 1;
        break;
    case 0x10:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7910() == 1 && ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a78b0())) == 1)
            result = 1;
        break;
    case 0x20:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7990() == 1 && (local_10 == 1 || sVar2 != 0))
            result = 1;
        break;
    case 0x40:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a79b0() == 1 && (local_10 == 1 || sVar2 != 0))
            result = 1;
        break;
    case 0x80:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7910() == 0 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7990() == 0 &&
            ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a79b0() == 0)
            result = 1;
        break;
    case 0x100:
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7910() == 0 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7990() == 0 &&
            ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a79b0() == 0 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7930() == 0)
            result = 1;
        break;
    }
    return result;
}
//@ f_0e2f70  groesse 1008 B, 153 Bef, reg eax edx ebx ecx, stapel 4
/* === Beschreibung (Katalog) ===
 * Erzeugt einen neuen 24-Byte-Eintrag am Ende der Pool-Gegenstandstabelle (p1->a->tab[p1->a->n]), berechnet aus
 * dem Grundpreis (f_0a7820) und der Währungseinheit (f_0a7830) über die eingestellte Preisberechnungsmethode
 * (p1->fn) den tatsächlichen Kauf- oder Verkaufspreis (mindestens 1 Heller) und speichert Stückzahl p2,
 * Gegenstands-ID p3, Grafik-Icon, Gewicht, Stapelbarkeit, Inventarslot p4 und Heldenzeiger p5.
 * - Eingaben: Übergeben werden die Pool-Struktur p1, die vorhandene Stückzahl p2 (-1 für unbegrenzt), die
 *   Gegenstands-ID p3, der Inventarplatz p4 sowie der Heldenzeiger p5.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2f70(struct P *p1, short p2, short p3, short p4, int p5)
{
    int local_24 = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p3]))->f_0a7830();
    int iVar5 = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p3]))->f_0a7820() * local_24;
    int local_20 = 0;
    short sVar2 = 0;
    int adj; short iVar7;
    if (p5 != 0) {
        local_20 = f_042bb0((struct hero *)(p5), p4);
        sVar2 = f_042b50((struct hero *)(p5), p4);
    }
    typedef int (P::*MF)(int, int, short);
    iVar5 = (p1->*(*(MF *)&p1->fn))(iVar5, local_20, sVar2);
    if (iVar5 == 1) {
        local_24 = 1;
    } else {
        iVar5 = iVar5 / local_24;
    }
    struct Limit { static int one(int n) { if (n < 1) n = 1; return n; } };
    iVar5 = Limit::one(iVar5);
    p1->a->tab[p1->a->n].s0 = p2;
    p1->a->tab[p1->a->n].s2 = p3;
    iVar7 = p3;
    p1->a->tab[p1->a->n].s4 = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[iVar7]))->f_0a7800();
    p1->a->tab[p1->a->n].s6 = iVar5;
    p1->a->tab[p1->a->n].s8 = local_24;
    p1->a->tab[p1->a->n].sa = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[iVar7]))->f_0a7810();
    p1->a->tab[p1->a->n].c = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[iVar7]))->f_0a7950();
    p1->a->tab[p1->a->n].s10 = 0;
    p1->a->tab[p1->a->n].s12 = p4;
    p1->a->tab[p1->a->n].s14 = p5;
    ++(p1->a->n);
}
#define G3190 p2 + (p2 * p1->a->s6) / 100
#define SUMT int t = (p1->a->s6 * p2) / 100; t += p2;
//@ f_0e3190  ?
/* === Beschreibung (Katalog) ===
 * Berechnet einen um den prozentualen Händleraufschlag (p1->a->s6) modifizierten Preis nach der Formel p2 + (p2
 * * s6) / 100.
 * - Eingaben: Übergeben werden die Pool-Struktur p1 sowie der Grundpreis p2.
 * - Rückgabewert: Die Funktion gibt den um den Prozentsatz angepassten Preis zurück.
 === Ende Beschreibung === */
int f_0e3190(struct P *p1, int p2)
{
    int t = p2;
    p2 *= p1->a->s6;
    p2 /= 100;
    t += p2;
    return t;
}
//@ f_0e31c0  ?
/* === Beschreibung (Katalog) ===
 * Begrenzt einen Preiswert p2 nach unten auf mindestens 1 (if (p2 < 1) p2 = 1;).
 * - Eingaben: Übergeben werden ein ungenutzter Objektzeiger p1 sowie der zu prüfende Preiswert p2.
 * - Rückgabewert: Die Funktion gibt den auf mindestens 1 angehobenen Wert zurück.
 === Ende Beschreibung === */
int f_0e31c0(int p1, int p2)
{
    if (p2 < 1) p2 = 1;
    return p2;
}
//@ f_0e31d0  ?
/* === Beschreibung (Katalog) ===
 * Berechnet den vollen Händlerpreis (p2 + (p2 * s6) / 100), setzt ihn jedoch auf 1 herab, falls der Gegenstand
 * kaputt ist (p3 == 1) oder verbrauchte Ladungen bzw. Beschädigungsstufen aufweist (p4 > 0).
 * - Eingaben: Übergeben werden die Pool-Struktur p1, der Grundpreis p2, das Zerstörungsflag p3 sowie der
 *   Beschädigungsgrad p4.
 * - Rückgabewert: Die Funktion gibt den berechneten Preis zurück.
 === Ende Beschreibung === */
int f_0e31d0(struct P *p1, int p2, int p3, short p4)
{
    int iVar1 = (p1->a->s6 * p2) / 100 + p2;
    if (p3 == 1 || 0 < p4) iVar1 = 1;
    return iVar1;
}
//@ f_0e3200  ?
/* === Beschreibung (Katalog) ===
 * Berechnet den halben Händlerpreis ((p2 + (p2 * s6) / 100) / 2, typischerweise beim Ankauf durch einen Händler)
 * und setzt ihn bei beschädigten Gegenständen (p3 == 1 oder p4 > 0) auf 1 Heller herab.
 * - Eingaben: Übergeben werden die Pool-Struktur p1, der Grundpreis p2, das Zerstörungsflag p3 sowie der
 *   Beschädigungsgrad p4.
 * - Rückgabewert: Die Funktion gibt den berechneten Ankaufspreis zurück.
 === Ende Beschreibung === */
int f_0e3200(struct P *p1, int p2, int p3, short p4)
{
    SUMT
    int iVar1 = t / 2;
    if (p3 == 1 || 0 < p4) iVar1 = 1;
    return iVar1;
}
//@ f_0e3240  ?
/* === Beschreibung (Katalog) ===
 * Berechnet den Preis für die Reparatur oder den Handel beim Schmied: Unbeschädigte Gegenstände kosten den
 * vollen modifizierten Preis (t), komplett zerbrochene Gegenstände (p3 == 1) die Hälfte (t / 2) und leicht
 * beschädigte Gegenstände (p4 > 0) ein Viertel (t / 4).
 * - Eingaben: Übergeben werden die Pool-Struktur p1, der Grundpreis p2, das Zerstörungsflag p3 sowie der
 *   Beschädigungsgrad p4.
 * - Rückgabewert: Die Funktion gibt den ermittelten Preis zurück.
 === Ende Beschreibung === */
int f_0e3240(struct P *p1, int p2, int p3, short p4)
{
    SUMT
    int r_ = t;
    if (p3 == 1) r_ = t / 2;
    else if (0 < p4) r_ = t / 4;
    return r_;
}
//@ f_0e3290  ?
/* === Beschreibung (Katalog) ===
 * Berechnet den halben modifizierten Preis (t / 2), gibt jedoch 0 zurück, sobald der Gegenstand beschädigt ist
 * (p3 == 1 oder p4 > 0).
 * - Eingaben: Übergeben werden die Pool-Struktur p1, der Grundpreis p2, das Zerstörungsflag p3 sowie der
 *   Beschädigungsgrad p4.
 * - Rückgabewert: Die Funktion gibt den berechneten Preis oder 0 zurück.
 === Ende Beschreibung === */
int f_0e3290(struct P *p1, int p2, int p3, short p4)
{
    SUMT
    int iVar1 = t / 2;
    if (p3 == 1 || 0 < p4) iVar1 = 0;
    return iVar1;
}
//@ f_0e32d0  ?
/* === Beschreibung (Katalog) ===
 * Berechnet 60 Prozent des um den Händleraufschlag angepassten Preises ((p2 + (p2 * s6) / 100) * 6 / 10),
 * unabhängig vom Beschädigungszustand.
 * - Eingaben: Übergeben werden die Pool-Struktur p1, der Grundpreis p2 sowie zwei ungenutzte Zustandsparameter
 *   p3 und p4.
 * - Rückgabewert: Die Funktion gibt den auf 60 % skalierten Preis zurück.
 === Ende Beschreibung === */
int f_0e32d0(struct P *p1, int p2, int p3, int p4)
{
    struct A *a = p1->a;
    int iVar1 = (a->s6 * p2) / 100;
    p2 += iVar1;
    return p2 * 6 / 10;
}

//@ f_0e3310  ?
/* === Beschreibung (Katalog) ===
 * Liefert die Funktionsadresse der Preisberechnungsroutine f_0e32d0 zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Funktionszeiger auf f_0e32d0 zurück.
 === Ende Beschreibung === */
FN f_0e3310(void) { return (FN)f_0e32d0; }
//@ f_0e3320  ?
/* === Beschreibung (Katalog) ===
 * Liefert die Funktionsadresse der Preisberechnungsroutine f_0e3290 zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Funktionszeiger auf f_0e3290 zurück.
 === Ende Beschreibung === */
FN f_0e3320(void) { return (FN)f_0e3290; }
//@ f_0e3330  ?
/* === Beschreibung (Katalog) ===
 * Liefert die Funktionsadresse der Preisberechnungsroutine f_0e3240 zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Funktionszeiger auf f_0e3240 zurück.
 === Ende Beschreibung === */
FN f_0e3330(void) { return (FN)f_0e3240; }
//@ f_0e3340  ?
/* === Beschreibung (Katalog) ===
 * Liefert die Funktionsadresse der Preisberechnungsroutine f_0e3200 zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Funktionszeiger auf f_0e3200 zurück.
 === Ende Beschreibung === */
FN f_0e3340(void) { return (FN)f_0e3200; }
//@ f_0e3350  ?
/* === Beschreibung (Katalog) ===
 * Liefert die Funktionsadresse der Preisberechnungsroutine f_0e31d0 zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Funktionszeiger auf f_0e31d0 zurück.
 === Ende Beschreibung === */
FN f_0e3350(void) { return (FN)f_0e31d0; }
//@ f_0e3360  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Liest das Sichtbarkeits- bzw. Aktivitätsflag (+0x1c) eines Popup-Fensterobjekts (p1) aus.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Sie gibt den 16-Bit-Wert an Offset +0x1c als Ganzzahl zurück.
 === Ende Beschreibung === */
int f_0e3360(int p1)
{
    return *(short *)(p1 + 0x1c);
}
//@ f_0e3370  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Liest das Verschiebungs-Statusflag (+0x1e, ob das Fenster gerade bewegt wird) eines Popup-Fensterobjekts (p1)
 * aus.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Sie gibt den 16-Bit-Wert an Offset +0x1e als Ganzzahl zurück.
 === Ende Beschreibung === */
int f_0e3370(int p1)
{
    return *(short *)(p1 + 0x1e);
}
//@ f_0e3380  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Liest die innere Spaltenbreite (+0x12, Anzahl der 32-Pixel-Mittelstücke) eines Popup-Fensterobjekts (p1) aus.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Sie gibt die 16-Bit-Spaltenanzahl an Offset +0x12 zurück.
 === Ende Beschreibung === */
short f_0e3380(int p1)
{
    return *(short *)(p1 + 0x12);
}
//@ f_0e3390  stub
/* === Beschreibung (Katalog) ===
 * Setzt das 32-Bit-Feld an Offset +0x42 eines Popup-Fensterobjekts (p1) auf den Wert p2.
 * - Eingaben: Übergeben werden der Zeiger auf das Popup-Fensterobjekt p1 sowie der zu speichernde 32-Bit-Wert
 *   p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e3390(int p1, int p2)
{
    *(int *)(p1 + 0x42) = p2;
}
//@ f_0e33a0  groesse 16 B, 2 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * Speichert die ausgewählte Schaltflächen- oder Antwortkennung p2 im Feld +0x10 eines Popup-Fensterobjekts (p1).
 * - Eingaben: Übergeben werden der Zeiger auf das Popup-Fensterobjekt p1 sowie der 16-Bit-Wert p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e33a0(int p1, short p2)
{
    *(short *)(p1 + 0x10) = p2;
}
//@ f_0e33b0  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Liest die ausgewählte Schaltflächen- oder Antwortkennung aus dem Feld +0x10 eines Popup-Fensterobjekts (p1)
 * aus.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Sie gibt den 16-Bit-Wert an Offset +0x10 zurück.
 === Ende Beschreibung === */
short f_0e33b0(int p1)
{
    return *(short *)(p1 + 0x10);
}
//@ f_0e33c0  groesse 112 B, 45 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Sichert im 2D-Grafikmodus (d_1bd910 == 0) den rechteckigen Bildschirmausschnitt (x, y, w, h), der von einem
 * Popup-Fenster (p1) überdeckt wird, zeilenweise aus dem Bildschirmpuffer (d_1a34e0) in den fenstereigenen
 * Hintergrundpuffer (p1->buf).
 * - Eingaben: Die Funktion erhält den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e33c0(struct W *p1)
{
    short i;
    if (d_1bd910 == 0) {
        for (i = 0; i < p1->h; i++) {
            char *dst = d_1a34e0 + (p1->y + i) * 0x140 + p1->x;
            memcpy(p1->buf + i * p1->w, dst, p1->w);
        }
    }
}
//@ f_0e3430  groesse 336 B, 113 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Stellt den Hintergrund unter einem geschlossenen oder verschobenen Popup-Fenster (p1) wieder her: Im 3D-Modus
 * (d_1bd910 == 1) wird die 3D-Ansicht über f_0757f0 neu gerendert, während im 2D-Modus (d_1bd910 == 0) der zuvor
 * gesicherte Rechteckbereich aus p1->buf zurück in den Bildschirmpuffer (d_1a34e0) kopiert und gegebenenfalls
 * ein aktives Animations-Overlay (d_1bc760) aktualisiert wird.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e3430(struct W *p1)
{
    struct Frame905 { short x3, p3, x0, p0, x1, p1, x2, p2, y0, py0, y1, py1; } frame;
#define x3 frame.x3
#define x0 frame.x0
#define x1 frame.x1
#define x2 frame.x2
#define y0 frame.y0
#define y1 frame.y1
    short i;
    if (d_1bd910 == 1) {
        f_05e2a0(d_1c38b0, &x0, &x1, &x2, &x3);
        f_05e800(d_1c38b0, &y0, &y1);
        f_05e2d0(d_1c38b0, 0, 0x140, 0, 0);
        f_05e7e0(d_1c38b0, 0, 0);
        int value = d_1bd914;
        p1->s1c = 0;
        d_1bda54 = 1;
        f_0757f0(value);
        p1->s1c = 1;
        f_05e2d0(d_1c38b0, x0, x1, x2, x3);
        f_05e7e0(d_1c38b0, y0, y1);
        return;
    }
    for (i = 0; i < p1->h; ++i) {
        {int rtA905=d_1bd914;d_1bd914=rtA905;} // haelt die Registerzuteilung wie im Original
        int line = i;
        int rowOffset = p1->y; rowOffset += line; rowOffset *= 320;
        char *row = d_1a34e0 + rowOffset;
        int scaled = line * p1->w;
        int x = p1->x;
        char *dst = row + x;
        char *src = p1->buf + scaled;
        memcpy(dst, src, p1->w);
        {short rtB905=d_1bd910;d_1bd910=rtB905;} // haelt die Registerzuteilung wie im Original
    }
    if (d_1bc760 != 0) {
        d_1bc764 = 1;
        short t_309 = f_01dfb0(d_1bc760);
        if (t_309 != (short)0) f_01c840(d_1bc760);
    }
}
#undef x3
#undef x0
#undef x1
#undef x2
#undef y0
#undef y1
//@ f_0e3580  groesse 336 B, 163 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * Sichert bei Bedarf den Bildschirmhintergrund unter dem Popup-Fenster (p1) und zeichnet anschließend den
 * kompletten grafischen Fensterrahmen für p2 Textzeilen durch wiederholtes Aufrufen von f_0e36d0 (oberer Rand,
 * gekachelte Mittelstreifen in 4-Zeilen-Schritten plus Reststreifen sowie unterer Abschlussrand).
 * - Eingaben: Übergeben werden der Zeiger auf das Popup-Fensterobjekt p1 sowie die benötigte Innenhöhe p2 in
 *   8-Pixel-Einheiten (Textzeilen).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e3580(struct W *p1, unsigned short p2)
{
    short i, n, j, k;
    short r;
    volatile int mg;
    struct W *w;
    int t_331 = f_0d3860();
    if (t_331 == 1) { f_0d2710(); mg = 1; }
    else mg = 0;
    w = p1;
    if ((int)d_1bd910 == 0) {
        for (i = 0; i < w->h; i++) {
            char *src = d_1a34e0 + (w->y + i) * 0x140 + w->x;
            memcpy(w->buf + i * w->w, src, w->w);
        }
    }
    f_0e36d0(p1, 0, 0, 0x20);
    k = 0;
    n = p2 - (r = (short)p2 % 4);
    if (n > 0) {
        for (j = 0; j < n; j += 4, k += 4)
            f_0e36d0(p1, (short)(j + 2), 1, 0x20);
    }
    if (r) f_0e36d0(p1, (short)(k + 2), 1, (short)(r << 3));
    f_0e36d0(p1, (short)(p2 + 2), 2, 0x20);
    f_149d20();
    if (mg == 1) f_0d26e0();
}
