/* === Beschreibung (Katalog) ===
 * Einheit gz_0307d0_t1 (0x000307d0 - 0x00032130)
 *
 * Überblick
 *
 * Die Einheit gz_0307d0_t1 enthält zentrale Kampf-, Ziel-, Zustands- und Krankheitsfunktionen für Helden
 * (vergleichbar mit den Charakter-Status- und Krankheitsroutinen aus *Sternenschweif*). Sie verwaltet das
 * aktuelle Angriffsziel eines Helden (Offset +0x98), setzt Kampf-Flags vor und nach Gefechten zurück, ermittelt
 * das Kampfsprite für Nah- und Fernkampfwaffen, spielt Schmerz- und Todesschreie nach Geschlecht ab und
 * berechnet den täglichen Verlauf aller sieben Krankheiten (f_031020: Wundfieber, Dumpfschädel, Blaue Keuche,
 * Paralyse, Schlachtenfieber, Frostschaden und Tollwut).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 12/16 gleich (suche.py 26.10.2026, Basis gz_0307d0_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 5 gleich (vorher 5), Rest 708 (vorher 709)
// gz_0307d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0307D0-0x032820
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_03c210(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040820(int p1, int p2);                           // reg eax edx stapel 0
int f_040980(int p1, int p2);                           // reg eax edx stapel 0
int f_041ae0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_0433f0(int p1, int p2);                           // reg eax edx stapel 0
int f_043420(int p1, int p2);                           // reg eax edx stapel 0
int f_043460(int p1, int p2);                           // reg eax edx stapel 0
signed char f_043820(int p1, int p2);                           // reg eax edx stapel 0
int f_043840(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_043860(int p1, int p2);                           // reg eax edx stapel 0
int f_043880(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0438a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_0438d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0438f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043910(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_043940(int p1, int p2);                           // reg eax edx stapel 0
int f_043960(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043980(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0439b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0439d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_043c60(int p1, int p2);                           // reg eax edx stapel 0
int f_043dd0(int p1, int p2);                           // reg eax edx stapel 0
char f_043e30(int p1);                                   // reg eax stapel 0
int f_043e40(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044ea0(int p1);                                   // reg eax stapel 0
signed char f_045300(int p1);                                   // reg eax stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_071e90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_0729c0(int p1);                                   // reg eax stapel 0
int f_0773b0(int p1);                                   // reg eax stapel 0
int f_09c890(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf8e0();                                         // reg - stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0d54c0(int p1);                                   // reg eax stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dba10(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0dbb20(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbfb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0de410(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);                                   // reg eax stapel 0
short f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_14778f(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a4423[];                    // 0x1A4423
extern int d_1a9670;                    // 0x1A9670
extern unsigned short d_1a9820;                    // 0x1A9820
extern int d_1bc88c;                    // 0x1BC88C
struct Ch { char pad[0x5ef]; };
extern Ch *d_1bc8f0;                    // 0x1BC8F0
extern short d_1bd75a;                    // 0x1BD75A
extern int d_1bd914;                    // 0x1BD914
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c002c;                    // 0x1C002C
extern int d_1c2198;                    // 0x1C2198
extern unsigned short d_1c219c;                    // 0x1C219C
extern int d_1c2a80;                    // 0x1C2A80
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2d1c;                    // 0x1C2D1C
extern int d_1c2ed4;                    // 0x1C2ED4
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
void f_032130(int p1);
void f_030e20(int p1, signed char p2);
#define A(x) ((int)&(x))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define PI(p,o) (*(int*)((p)+(o)))
struct Fl { char pad[0xbc]; unsigned a:1; unsigned b:1; unsigned c:1; unsigned d:1; unsigned e:1; unsigned f:1; unsigned g:1; };
#define FL(p) ((Fl*)(p))
typedef RivaTextContextData Msg;
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define F1(m) (m).tables.p[1]
#define OK(p) f_030fe0(p)
#define MSG(code) if (OK(p1)) f_0bf730(A(d_1c2c64), code)

//@ f_0307d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt fest, ob der übergebene Held entweder gar nicht existiert (!f_042350), tot (f_042470),
 *   bewusstlos (f_0424d0) oder aus dem Kampf geflohen (f_0425f0) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 zurück, wenn der Charakter nicht
 *   am Kampf teilnehmen kann, andernfalls 0.
 * - Wichtige Variablen: Prüft die Zustandsfunktionen f_042350, f_042470, f_0424d0 und f_0425f0.
 === Ende Beschreibung === */
int f_0307d0(int p1)
{
    if (!f_042350((struct hero *)(p1)) || ((char)(f_042470((struct hero *)(p1)))) || ((char)(f_0424d0((struct hero *)(p1)))) || ((char)(f_0425f0((struct hero *)(p1))))) return 1;
    return 0;
}

//@ f_030810
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Zielbyte am Offset +0x98 des Helden p1: Bei 0 gibt es den Helden selbst zurück, bei
 *   0xff kein Ziel (0) und bei Werten ab 1 den entsprechenden Eintrag aus dem Heldenarray d_1bc8f0[ziel - 1].
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und liefert den Zeiger auf den
 *   anvisierten Helden oder 0 zurück.
 * - Wichtige Variablen: Liest *(unsigned char *)(p1 + 0x98) und indiziert das globale Heldenarray d_1bc8f0.
 === Ende Beschreibung === */
int f_030810(int p1)
{
    if (!B(p1, 0x98)) return p1;
    if (B(p1, 0x98) == 0xff) return 0;
    return (int)&d_1bc8f0[B(p1, 0x98) - 1];
}

//@ f_030850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt einen anderen Helden p2 als aktuelles Ziel in das Feld p1 + 0x98 ein (0 bei Selbstziel,
 *   0xff bei p2 == 0, sonst SlotIndex + 1) und markiert p2 über f_043e40(p2, 1).
 * - Eingaben und Rückgabe: Die Funktion erhält den handelnden Helden p1 sowie den Zielhelden p2 und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Beschreibt *(unsigned char *)(p1 + 0x98).
 === Ende Beschreibung === */
void f_030850(int p1, int p2)
{
    if (p2 != 0) {
        if (p2 == p1) { B(p1, 0x98) = 0; return; }
        B(p1, 0x98) = f_0d54c0(p2) + 1;
        f_043e40(p2, 1);
        return;
    }
    B(p1, 0x98) = 0xff;
}

//@ f_030890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt anhand des Zielbytes *(unsigned char *)(p1 + 0x98) (Werte ab 10 für normale Gegner,
 *   ab 30 für besondere Kampfeinheiten) den Zeiger auf die Struktur des anvisierten Gegners im Monsterarray
 *   d_1c2ed4 (Eintragsgröße 0x73 Bytes).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt den Zeiger auf den Gegner im
 *   Array d_1c2ed4 oder 0 (bei 0xff) zurück.
 * - Wichtige Variablen: Liest *(unsigned char *)(p1 + 0x98) und berechnet den Offset in d_1c2ed4.
 === Ende Beschreibung === */
int f_030890(int p1)
{
    int u = B(p1, 0x98);
    unsigned short c;
    int i;
    if (u == 0xff) return 0;
    if (u > 0x32) c = 0;
    else if (u == 0) c = 5;
    else if (u < 10) {
        if (d_1bc8f0 + (u - 1) == (Ch*)p1) c = 5; else c = 2;
    }
    else if (u < 0x1e) c = 1;
    else c = 4;
    if ((signed char)c == 4) i = B(p1, 0x98) - 0x1e; else i = B(p1, 0x98) - 10;
    i *= 0x73; int base = d_1c2ed4; return i + base;
}

//@ f_030930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert die Kennung des anvisierten Monsters p2 zuzüglich 10 (f_0729c0(p2) + 10) im Zielfeld
 *   p1 + 0x98 oder löscht das Ziel bei p2 == 0 auf 0xff.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Monsterzeiger p2 und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Beschreibt *(unsigned char *)(p1 + 0x98).
 === Ende Beschreibung === */
void f_030930(int p1, int p2)
{
    if (p2 != 0) { B(p1, 0x98) = f_0729c0(p2) + 10; return; }
    B(p1, 0x98) = 0xff;
}

//@ f_030960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Klassifiziert den Wert im Zielfeld p1 + 0x98 in eine Zielkategorie: 0 bei ungültigem Ziel (>
 *   50), 5 bei Selbstziel, 2 bei einem anderen Gruppenmitglied (1..9), 1 bei einem regulären Monster (10..29)
 *   und 4 bei einem Ziel ab Index 30.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt den Zieltyp (0, 1, 2, 4 oder
 *   5) zurück.
 * - Wichtige Variablen: Wertet *(unsigned char *)(p1 + 0x98) und die Adresse in d_1bc8f0 aus.
 === Ende Beschreibung === */
int f_030960(int p1)
{
    int b;
    b = B(p1, 0x98);
    if (b > 0x32) return 0;
    if (!b) return 5;
    return (b < 10) ? ((d_1bc8f0 + (b - 1) == (Ch*)p1)) ? 5 : 2 : (b < 30) ? 1 : 4;
}

//@ f_0309d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft alle sieben Gruppenplätze (0..6) und gibt 1 zurück, falls ein lebender Held mit
 *   gesetztem Flag f_042640 noch keine gültigen Koordinaten auf dem Taktik-Kampffeld (f_071e90 == 0) besitzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt 1 zurück, wenn ein Held ohne
 *   Kampffeldposition gefunden wurde, sonst 0.
 * - Wichtige Variablen: Prüft f_042470, f_042640 und f_071e90.
 === Ende Beschreibung === */
int f_0309d0(int p1)
{
    short s;
    int p;
    int v;
    int u;
    for (s = 0; s <= 6; s++) {
        p = PI(p1, s * 4);
        if (p != 0 && !((char)(f_042470((struct hero *)(p)))) && ((char)(f_042640((struct hero *)(p))))) {
            if (f_071e90((unsigned char)(f_0d54c0(p) + 1), (int)&u, (int)&v) == 0) return 1;
        }
    }
    return 0;
}

//@ f_030a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Geht vor Beginn einer Kampfrunde alle sieben Gruppenplätze durch, setzt für anwesende Helden
 *   deren Aktionsstatus (f_0433f0, bei Bonusflag f_0427e0 auf 2 Aktionen) sowie ihre Initiative/Bewegungspunkte
 *   (f_043420(p, f_045300(p))) und zählt die Gesamtzahl verfügbarer Heldenaktionen zusammen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Gruppenzeiger p1 entgegen und gibt die Anzahl der
 *   initialisierten Kampfteilnehmer/-aktionen zurück.
 * - Wichtige Variablen: Ruft f_0433f0, f_043420, f_045300 und f_043460 für die Gruppenmitglieder auf.
 === Ende Beschreibung === */
int f_030a40(int p1)
{
    int n = 0;
    short s = 0;
    int p, t;
    int u, v;
    for (; s <= 6; s++) {
        p = PI(p1, s * 4);
        if (p != 0) {
            if (!((char)(f_042640((struct hero *)(p)))) || f_071e90((unsigned char)(f_0d54c0(p) + 1), (int)&u, (int)&v) != 0) {
                f_0433f0(p, 1);
                f_043420(p, f_045300(p));
                if (!((char)(f_042640((struct hero *)(p))))) f_0427d0((struct hero *)(p), 0);
                n++;
                if (((char)(f_0427e0((struct hero *)(p))))) { f_0433f0(p, 2); n++; }
            }
            f_043460(p, 0);
        }
    }
    return n;
}

//@ f_030b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt nach einem Kampf für alle sieben Gruppenmitglieder sowie für abgelegte Helden im Array
 *   d_1bc8f0 sämtliche temporären Kampfzustände (Panik, Verwirrung, Lähmung, Kampfaktionen, Zielmarkierungen)
 *   zurück, ermittelt dabei den verletzten lebenden Helden mit den wenigsten Lebenspunkten und löst mit 3 %
 *   Wahrscheinlichkeit (f_1457e0(100) < 3) über f_040980(v6, 5) eine Wundinfektion (Wundfieber) bei ihm aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Bereinigt die Heldenstrukturen in p1 und d_1bc8f0 (Schrittweite 0x5ef) und prüft über
 *   f_042960/f_042970 die aktuellen gegen die maximalen Lebenspunkte.
 === Ende Beschreibung === */
void f_030b00(int p1)
{
    short a = 10000, i;
    int v6 = 0, v5;
    #pragma inline_depth(0)
    for (i = 0; i <= 6; i++) {
        v5 = PI(p1, i * 4);
        if (v5 != 0) {
            f_042610((struct hero *)(v5), 0);
            f_030e20(v5, 0);
            f_042570((struct hero *)(v5), 0);
            f_043dd0(v5, 0);
            f_042650((struct hero *)(v5), 0);
            f_043240((struct hero *)(v5), 0);
            f_043260((struct hero *)(v5), 0);
            f_042800((struct hero *)(v5), 0xd);
            f_042740((struct hero *)(v5), 0);
            f_043e40(v5, 0);
            f_043c60(v5, 0);
            f_0425b0((struct hero *)(v5), 0);
            if (!((char)(f_042470((struct hero *)(v5))))) {
                if (f_042960((struct hero *)(v5)) < a) {
                    if (f_042960((struct hero *)(v5)) != f_042970((struct hero *)(v5))) { a = f_042960((struct hero *)(v5)); v6 = v5; }
                }
            }
        }
    }
    a = f_1457e0(100);
    if (a < 3 && v6 != 0) f_040980(v6, 5);
    v6 = (int)d_1bc8f0;
    for (a = 0; a <= 6; a++, v6 += 0x5ef) {
        if (f_042350((struct hero *)(v6))) {
            if (f_0dbfb0(p1, v6) == 0) {
                f_042610((struct hero *)(v6), 0);
                f_030e20(v6, 0);
                f_042570((struct hero *)(v6), 0);
                f_043dd0(v6, 0);
                f_042650((struct hero *)(v6), 0);
                f_043240((struct hero *)(v6), 0);
                f_043260((struct hero *)(v6), 0);
                f_042800((struct hero *)(v6), 0xd);
                f_042740((struct hero *)(v6), 0);
                f_043e40(v6, 0);
                f_043c60(v6, 0);
                f_0425b0((struct hero *)(v6), 0);
            }
        }
    }
}

//@ f_030cb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt für alle sieben Gruppenmitglieder, sofern sie nicht den Zustand f_042400 besitzen, das
 *   Statusflag f_042740(p, p2) und nullt den globalen Zähler d_1bd75a.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den neuen Flagwert p2 und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Aktualisiert alle Helden in p1 sowie d_1bd75a = 0.
 === Ende Beschreibung === */
void f_030cb0(int p1, signed char p2)
{
    short s;
    int p;
    for (s = 0; s <= 6; s++) {
        p = PI(p1, s * 4);
        if (p != 0) {
            if (!((char)(f_042400((struct hero *)(p))))) f_042740((struct hero *)(p), p2);
        }
    }
    d_1bd75a = 0;
}

//@ f_030d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft die in der rechten Hand (Slot 3) getragene Waffe des Helden p1: Ist es eine nicht
 *   zerbrochene Waffe (f_0a7990() != 0 und f_042bb0 == 0), deren Animationskennung in d_1a4423[typ * 10] kleiner
 *   als 4 ist (Nahkampfwaffe), wird dieser Index (0..3) zurückgegeben, andernfalls -1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt den Nahkampf-Animationsindex
 *   (0..3) oder -1 zurück.
 * - Wichtige Variablen: Liest den Waffentyp über d_1c2c40 und schlägt in der Tabelle d_1a4423 nach.
 === Ende Beschreibung === */
short f_030d00(int p1)
{
    short s = f_042a60((struct hero *)(p1), 3);
    signed char c;
    short v;
    if (d_1c2c40[s]->f_0a7990() != 0 && f_042bb0((struct hero *)(p1), 3) == 0) {
        c = (signed char)d_1c2c40[s]->f_0a78a0();
        v = d_1a4423[c * 10];
        if (d_1a4423[c * 10] >= 4) v = -1;
    } else v = -1;
    return v;
}

//@ f_030d80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft analog zu f_030d00, ob der Held p1 in der rechten Hand (Slot 3) eine intakte
 *   Fernkampfwaffe trägt (d_1a4423[typ * 10] >= 4 und Waffentyp ungleich '5'), und gibt deren Animationskennung
 *   oder -1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt den Fernkampf-Animationsindex oder
 *   -1 zurück.
 * - Wichtige Variablen: Wertet die Waffe in Slot 3 über d_1c2c40 und d_1a4423 aus.
 === Ende Beschreibung === */
short f_030d80(int p1)
{
    short s = f_042a60((struct hero *)(p1), 3);
    signed char c;
    short v;
    if (d_1c2c40[s]->f_0a7990() != 0 && f_042bb0((struct hero *)(p1), 3) == 0) {
        c = (signed char)d_1c2c40[s]->f_0a78a0();
        v = d_1a4423[c * 10];
        if (d_1a4423[c * 10] < 4) v = -1;
        c = (signed char)d_1c2c40[s]->f_0a78a0();
        if (c == '5') v = -1;
    } else v = -1;
    return v;
}

int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp];

//@ f_030e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert das Zustandsbit b am Offset +0xbc des Helden p1, spielt beim Übergang von 1 auf 0
 *   (sofern d_1bd914 == 0 ist) je nach Geschlecht des Helden (f_042380) den Soundeffekt 0x20000 (weiblich) oder
 *   0x20001 (männlich) ab und markiert die Anzeige über d_1c219c = 1 zur Aktualisierung.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 und den neuen Zustandswert p2 entgegen und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert FL(p1)->b, nutzt den Sound-Manager d_1c2edc und setzt d_1c219c.
 === Ende Beschreibung === */
void f_030e20(int p1, signed char p2)
{
    int c;
    int r;
    if (d_1bd914 == 0 && p2 == (signed char)0 && FL(p1)->b) {
        c = f_042380((struct hero *)(p1));
        if (c == 1) f_147323_frame(A(d_1c2edc), 0x20000, 0x7fff, 0x8000, (r = *(int *)&d_1a9820), 0, c);
        else f_147323_frame(A(d_1c2edc), 0x20001, 0x7fff, 0x8000, (r = *(int*)&d_1a9820), 0, 1);
    }
    if (p2 != FL(p1)->b) {
        d_1c219c = 1;
        FL(p1)->b = p2;
    }
}

//@ f_030ed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Zustandsbit g am Offset +0xbc des Helden p1. Wird das Bit neu aktiviert (p2 != 0 bei
 *   bisher !FL(p1)->g), ertönt außerhalb des Kampfes (d_1bd914 == 0) geschlechtsabhängig der Schrei 0x20003
 *   (männlich) bzw. 0x20002 (weiblich), während im Kampf (d_1bd914 != 0) eine Kampfmeldung über f_09c890
 *   ausgelöst wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und das neue Flag p2 und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Aktualisiert FL(p1)->g, d_1c219c und ruft f_043dd0(p1, 0) auf.
 === Ende Beschreibung === */
void f_030ed0(int p1, signed char p2)
{
    signed char c;
    int r;
    if (d_1bd914 == 0) {
        if (p2 != (signed char)0 && !FL(p1)->g) {
            c = f_042380((struct hero *)(p1));
            if (c == 0) {
                if (f_14778f(A(d_1c2edc), 0x20003) == 0)
                    f_147323_frame(A(d_1c2edc), 0x20003, 0x3fff, 0x8000, (r = *(int*)&d_1a9820), 0, 1);
            } else {
                int t_364 = f_14778f(A(d_1c2edc), 0x20002);
                if (t_364 == 0)
                    f_147323_frame(A(d_1c2edc), 0x20002, 0x3fff, 0x8000, (r = *(int*)&d_1a9820), 0, 1);
            }
            f_043dd0(p1, 0);
            d_1c219c = 1;
        }
    } else {
        if (p2 != (signed char)0 && !FL(p1)->g) {
            f_09c890(A(d_1c2d1c), 7, 0, 2, p1);
            f_043dd0(p1, 0);
        }
    }
    FL(p1)->g = (signed char)p2;
}

//@ f_031020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet für einen lebenden Helden p1 den täglichen Verlauf (Status -1 = akut krank, Status
 *   1 = in Genesung) sämtlicher sieben Krankheiten (merkmal = 1..7):
 *   - 1 (Dumpfschädel): Heilt nach 13 Tagen von selbst (0x204000d), verursacht vorher täglich 2W6 - (Tage - 1)
 *     LE-Schaden und senkt KK (Attr 6) um 1.
 *   - 2 (Blaue Keuche): Senkt einmalig GE (Attr 4) um 2 und KK (Attr 6) um 5 (0x204000e), steckt ab Tag 3 andere
 *     Gruppenmitglieder an (f_0dba10), schlägt mit 5 % Wahrscheinlichkeit in Paralyse (Krankheit 3) um oder
 *     kostet täglich 1W6 - 1 LE.
 *   - 3 (Paralyse): Halbiert zu Beginn GE und KK (0x2040010), senkt ab Tag 4 mit 25 % Chance dauerhaft KK um 1
 *     samt permanentem LE-/AE-Verlust, steckt Gefährten an und kostet täglich 1W6 + 2 LE.
 *   - 4 (Wundfieber): Verursacht bis zur spontanen Besserung nach 1W3 + 4 Tagen täglich 1W6 Abzug auf GE und KK
 *     (0x2040012).
 *   - 5 (Schlachtenfieber): Führt ab Tag 8 mit 20 % (bzw. 30 % ab Stufe 10) direkt zum Tod (0x2040013), senkt ab
 *     Tag 4 KK um 5 (0x2040014), steckt Gefährten an und verursacht 1W6 bzw. 2W6 + (Tage - 1) Schaden.
 *   - 6 (Frostschaden): Senkt mit Tage * 5 % Wahrscheinlichkeit dauerhaft GE um 1 (0x2040016), kostet 1W6 LE und
 *     zieht täglich je 1 Punkt KK und GE ab.
 *   - 7 (Tollwut): Kostet bis zu 3W6 LE sowie 2 Punkte KK, steckt Gefährten an und löst ab Tag 3 einen
 *     Tollwutanfall (f_032130) aus.
 *   Fällt durch die Abzüge KK (Attr 6) oder GE (Attr 4) auf 0 oder darunter, stirbt der Held nach Rückrechnung
 *   der temporären Abzüge (f_044300).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest und ändert die Krankheitsfelder über f_043820-f_0439d0, die Attribute über
 *   f_045430/f_0453e0 und die Lebensenergie über f_044300.
 === Ende Beschreibung === */
void f_031020(int p1)
{
    CX(m);
    char anfang;
    short zahl;
    short merkmal;

#undef MSG
#define MSG(code) { int r = 0; if (d_1bc88c == 0) { if (!((char)(f_042470((struct hero *)(p1))))) { if (!f_043e30(p1)) { if (!f_0773b0(d_1c0004)) r = 1; } } } if (r == 1) f_0bf730(A(d_1c2c64), code); }

    F1(m) = p1;
    if (!((char)(f_042470((struct hero *)(p1))))) {
        anfang = ((char)(f_0425f0((struct hero *)(p1))));
        merkmal = 1;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (f_043860(p1, merkmal) > 13) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 1);
                MSG(0x204000d);
            } else {
                f_044300(p1, f_145850(2, 6, (short)-(f_043860(p1, merkmal) - 1)));
                if (!((char)(f_042470((struct hero *)(p1))))) { if (f_043a80(p1, 6) > 1) {
                    f_043910(p1, merkmal, 1);
                    f_045430(p1, 6, -1);
                } }
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            if (!f_0438d0(p1, merkmal)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 0);
            } else {
                f_043910(p1, merkmal, -1);
                f_045430(p1, 6, 1);
            }
        }
        merkmal = 2;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (!f_0439b0(p1, merkmal)) {
                MSG(0x204000e);
                f_0439d0(p1, merkmal, 1);
                f_045430(p1, 4, -2);
                f_045430(p1, 6, -5);
            }
            if (f_043860(p1, merkmal) > 2)
                f_0dba10(d_1c0004, 2, 0x14, p1);
            if (f_1457e0(100) < 5) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 0);
                if (f_0439b0(p1, merkmal)) {
                    f_0439d0(p1, merkmal, 0);
                    d_1bc88c = 1;
                    f_045430(p1, 4, 2);
                    f_045430(p1, 6, 5);
                    d_1bc88c = 0;
                }
                f_040980(p1, 3);
            } else if (f_043860(p1, merkmal) > f_145850(1, 3, 4)) {
                f_043840(p1, merkmal, 1);
            } else {
                f_044300(p1, f_145850(1, 6, -1));
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            f_043880(p1, merkmal, 0);
            f_043840(p1, merkmal, 0);
            if (f_0439b0(p1, merkmal)) {
                f_0439d0(p1, merkmal, 0);
                f_045430(p1, 4, 2);
                f_045430(p1, 6, 5);
            }
            MSG(0x204000f);
        }

        merkmal = 3;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (!f_0439b0(p1, merkmal)) {
                f_0439d0(p1, merkmal, 1);
                MSG(0x2040010);
                zahl = f_043a80(p1, 4);
                f_045430(p1, 4, (signed char)(-zahl / 2));
                f_043960(p1, merkmal, (signed char)(zahl / 2));
                zahl = f_043a80(p1, 6);
                f_045430(p1, 6, (signed char)(-zahl / 2));
                f_0438f0(p1, merkmal, (signed char)(zahl / 2));
            }
            if (f_043860(p1, merkmal) > 3 && f_1457e0(100) <= 25) {
                f_0453e0(p1, 6, -1);
                f_040820(p1, (short)(f_043860(p1, merkmal) / 3));
                f_044300(p1, (short)(f_043860(p1, merkmal) / 3));
                f_043840(p1, merkmal, 1);
                goto nach_drei;
            }
            f_0dba10(d_1c0004, 2, 0x14, p1);
            f_044300(p1, f_145850(1, 6, 2));
        }
nach_drei:
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            MSG(0x2040011);
            f_043880(p1, merkmal, 0);
            f_043840(p1, merkmal, 0);
            if (f_0439b0(p1, merkmal)) {
                f_0439d0(p1, merkmal, 0);
                f_045430(p1, 4, f_043940(p1, merkmal));
                f_045430(p1, 6, f_0438d0(p1, merkmal));
                f_043960(p1, merkmal, 0);
                f_0438f0(p1, merkmal, 0);
            }
        }
        merkmal = 4;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (f_043860(p1, merkmal) > f_145850(1, 3, 4)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 1);
            } else {
                MSG(0x2040012);
                zahl = f_1457e0(6);
                f_043980(p1, merkmal, (signed char)zahl);
                f_045430(p1, 4, (signed char)-zahl);
                zahl = f_1457e0(6);
                f_043910(p1, merkmal, (signed char)zahl);
                f_045430(p1, 6, (signed char)-zahl);
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            if (!f_0438d0(p1, merkmal) && !f_043940(p1, merkmal)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 0);
            } else {
                if (f_0438d0(p1, merkmal)) {
                    f_043910(p1, merkmal, -1);
                    f_045430(p1, 6, 1);
                }
                if (f_043940(p1, merkmal)) {
                    f_043980(p1, merkmal, -1);
                    f_045430(p1, 4, 1);
                }
            }
        }
        merkmal = 5;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (f_043860(p1, merkmal) > 7) {
                if (f_1457e0(100) <= (f_042350((struct hero *)(p1)) >= 10 ? 30 : 20)) {
                    MSG(0x2040013);
                    f_044300(p1, f_042960((struct hero *)(p1)));
                } else if (f_0439b0(p1, merkmal)) {
                    f_043840(p1, merkmal, 1);
                }
            } else if (f_043860(p1, merkmal) > 3) {
                if (!f_0439b0(p1, merkmal)) {
                    MSG(0x2040014);
                    f_0439d0(p1, merkmal, 1);
                    f_045430(p1, 6, -5);
                }
                f_0dba10(d_1c0004, 5, 5, p1);
                { union {int full; unsigned char low; unsigned short word;} seiten;
                  int bonus=(short)(f_043860(p1,merkmal)-1);
                  seiten.full=6;
                  
                  int anzahl=f_042350((struct hero *)(p1))>=10?2:1;
                  seiten.low=(seiten.low&0)?(unsigned char)0:seiten.low; // Haelt seiten.full im Merkmal-5-Block fuer die Registerzuteilung
                  f_044300(p1,f_145850((short)anzahl,seiten.full,bonus)); }
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            f_043880(p1, merkmal, 0);
            f_043840(p1, merkmal, 0);
            if (f_0439b0(p1, merkmal)) {
                f_0439d0(p1, merkmal, 0);
                f_045430(p1, 6, 5);
                MSG(0x2040015);
            }
        }
        merkmal = 6;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            zahl = 0;
            if (f_1457e0(100) <= f_043860(p1, merkmal) * 5) {
                MSG(0x2040016);
                f_0453e0(p1, 4, -1);
                zahl = 1;
            }
            if (zahl == (short)0)
                MSG(0x2040017);
            f_044300(p1, f_145850(1, 6, 0));
            if (!((char)(f_042470((struct hero *)(p1))))) {
                if (f_043a80(p1, 6)) {
                    f_043910(p1, merkmal, 1);
                    f_045430(p1, 6, -1);
                }
                if (f_043a80(p1, 4)) {
                    f_043980(p1, merkmal, 1);
                    f_045430(p1, 4, -1);
                }
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            if (!f_0438d0(p1, merkmal) && !f_043940(p1, merkmal)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 0);
            } else {
                if (f_0438d0(p1, merkmal)) {
                    f_043910(p1, merkmal, -1);
                    f_045430(p1, 6, 1);
                }
                if (f_043940(p1, merkmal)) {
                    f_043980(p1, merkmal, -1);
                    f_045430(p1, 4, 1);
                }
            }
        }
        merkmal = 7;
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == -1) {
            if (f_043860(p1, merkmal) > f_145850(1, 6, 6)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 1);
            } else {
                f_0dba10(d_1c0004, 7, 10, p1);
                f_044300(p1, f_145850((short)(f_043860(p1, merkmal) > 3 ?
                                               3 : f_043860(p1, merkmal)), 6, 0));
                if (!((char)(f_042470((struct hero *)(p1))))) {
                    f_043910(p1, merkmal, 2);
                    f_045430(p1, 6, -2);
                    if (f_043860(p1, merkmal) > 2) {
                        if(d_1bc88c == 0 && !f_043e30(p1) && !f_0773b0(d_1c0004))
                            f_032130(p1);
                    }
                }
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && f_043820(p1, merkmal) == 1) {
            if (!f_0438d0(p1, merkmal)) {
                f_043880(p1, merkmal, 0);
                f_043840(p1, merkmal, 0);
            } else {
                f_043910(p1, merkmal, -1);
                f_045430(p1, 6, 1);
            }
        }

        for (zahl = 1; zahl <= 7; zahl++) {
            if ((int)f_043820(p1, zahl) != 0) f_0438a0(p1, zahl, 1);
        }
        if (f_043a80(p1, 6) <= 0 || f_043a80(p1, 4) <= 0) {
            d_1bc88c = 1;
            int sechs=6, vier=4;
            for (zahl = 1; zahl <= 7; zahl++) {
                if (f_0438d0(p1, zahl)) {
                    f_045430(p1, sechs, f_0438d0(p1, zahl));
                    f_043910(p1, zahl, (signed char)-f_0438d0(p1, zahl));
                }
                if (f_043940(p1, zahl)) {
                    f_045430(p1, vier, f_043940(p1, zahl));
                    f_043980(p1, zahl, (signed char)-f_043940(p1, zahl));
                }
            }
            d_1bc88c = 0;
            f_044300(p1, f_042960((struct hero *)(p1)));
        }
        if (((char)(f_0425f0((struct hero *)(p1)))) != anfang && !((char)(f_042470((struct hero *)(p1)))) &&
            !f_0e3360(A(d_1c2c64))) {
            MSG(0x204002b);
            if (d_1c2a80 == 0x30000)
                *(short *)&d_1c2198 = 1;
        }
    }
    CXEND(m);
}

//@ f_030fe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt 1 zurück, wenn die globale Meldungssperre d_1bc88c nicht aktiv ist, der Held p1 lebt
 *   (!f_042470), nicht abwesend/stumm (!f_043e30) ist und kein Kampf (!f_0773b0(d_1c0004)) läuft.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt 1 (Meldung erlaubt) oder 0
 *   zurück.
 * - Wichtige Variablen: Prüft d_1bc88c, f_042470, f_043e30 und f_0773b0.
 === Ende Beschreibung === */
int f_030fe0(int p1)
{
    int result = 0;
    if (d_1bc88c == 0 &&
        !((char)(f_042470((struct hero *)(p1)))) &&
        !f_043e30(p1) &&
        !f_0773b0(d_1c0004))
        result = 1;
    return result;
}

