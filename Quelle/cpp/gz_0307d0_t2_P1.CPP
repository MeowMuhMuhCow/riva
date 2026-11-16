/* === Beschreibung (Katalog) ===
 * Einheit gz_0307d0_t2 (0x00032130 - 0x00032820)
 *
 * Überblick
 *
 * Die Einheit gz_0307d0_t2 setzt die Charakter-Hilfsfunktionen aus gz_0307d0_t1 fort. Sie enthält die
 * interaktive Behandlung eines Tollwutanfalls (f_032130) sowie Such- und Aufzählungsfunktionen für Nahrung,
 * Getränke und freie Plätze in den 31 Inventarslots eines Helden (0..14 am Körper, 15..30 im Rucksack).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 5/7 gleich (suche.py 29.10.2026, Basis gz_0307d0_t2_P1.CPP)
// gz_0307d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0307D0-0x032820
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_03c210(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
short f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
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
int f_043820(int p1, int p2);                           // reg eax edx stapel 0
int f_043840(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043860(int p1, int p2);                           // reg eax edx stapel 0
int f_043880(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0438a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0438d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0438f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043910(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043940(int p1, int p2);                           // reg eax edx stapel 0
int f_043960(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043980(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0439b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0439d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_043c60(int p1, int p2);                           // reg eax edx stapel 0
int f_043dd0(int p1, int p2);                           // reg eax edx stapel 0
int f_043e30(int p1);                                   // reg eax stapel 0
int f_043e40(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044ea0(int p1);                                   // reg eax stapel 0
int f_045300(int p1);                                   // reg eax stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_071e90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0729c0(int p1);                                   // reg eax stapel 0
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
int f_0bf8e0(int p1, ...);                                         // reg - stapel 0
short f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d54c0(int p1);                                   // reg eax stapel 0
unsigned short f_0db970(int p1);                                   // reg eax stapel 0
int f_0dba10(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0dbb20(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbfb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
char f_0de410(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
short f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_14778f(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4423;                    // 0x1A4423
extern char d_1a9670;                    // 0x1A9670
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc88c;                    // 0x1BC88C
extern int d_1bc8f0;                    // 0x1BC8F0
extern int d_1bd75a;                    // 0x1BD75A
extern int d_1bd914;                    // 0x1BD914
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern short d_1c002c;                    // 0x1C002C
extern int d_1c2198;                    // 0x1C2198
extern int d_1c219c;                    // 0x1C219C
extern int d_1c2a80;                    // 0x1C2A80
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2d1c;                    // 0x1C2D1C
extern int d_1c2ed4;                    // 0x1C2ED4
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (23), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

typedef RivaTextContextData Msg;
#define A(x) ((int)&(x))
#define TB(i) ((i) * 4 + ((int)d_1c2c40))
static inline int i_032630(int p1)
{
    int i, k;
    for (i = 0; (k = (short)i) < 0x1f; i = i + 1) {
        if (*(short *)(p1 + 0x1a8 + k * 0x1b) == 0x1e) {
            if (f_042d30((struct hero *)(p1), k) == 0) return i;
        }
    }
    return -1;
}

//@ f_032130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird aus dem Krankheitsverlauf (f_031020) aufgerufen, wenn ein an Tollwut erkrankter Held p1
 *   ab dem dritten Krankheitstag einen Tobsuchtsanfall erleidet. Ist die Gruppe größer als ein Held (f_0dbfe0 >
 *   1), müssen die Gefährten im Auswahlfenster (0x2040018) entscheiden, wie sie den Rasenden bändigen:
 *   1. Niederschlagen (s == 1): Kostet den Erkrankten die Hälfte seiner aktuellen Lebensenergie (f_042960 / 2,
 *     Meldung 0x204001c) und erlaubt anschließend einem ausgewählten Helden eine Heilkunde-Behandlung
 *     (f_03c210(a, p1, 10, 1)).
 *   2. Fesseln mit Seil (s == 2): Prüft über f_0de410, ob ein Seil vorhanden ist, beruhigt den Helden ohne
 *     Verletzung (0x204001e) und erlaubt ebenfalls die Behandlung; ohne Seil erscheint 0x204001f.
 *   3. Magie (s == 3, *Sanftmut* / *Somnigravis* 0x0f): Lässt einen magiekundigen Gefährten für 15 Astralpunkte
 *     den Zauber 0x0f wirken (f_03d3d0(a, 0x0f, 0)), zieht bei Erfolg die 15 AE über f_044230(a, 0xf) ab
 *     (0x2040021) und leitet die Behandlung ein.
 *   Misslingt die Bändigung oder ist der Held allein unterwegs (0x2040023), verletzt er in seiner Raserei die
 *   Gruppe um 1W6 + 2 Schadenspunkte (f_0dbb20).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf den tollwütigen Helden p1 und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Nutzt den Text- und Dialogmanager d_1c2c64, die Gruppenliste d_1c0004 und die
 *   Zauberprobe f_03d3d0.
 === Ende Beschreibung === */
void f_032130(int p1)
{
    extern short f_0dbfe0(int);
    Msg m;
    int a, u;
    short s, done;
    signed char c18;
    f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    // Verhindert Vorziehen der Tabellen-Initialisierung vor die Warteschleife
    *(volatile int *)&m.tables.p[1] = p1;
    done = 0;
    c18 = *(signed char *)&d_1c002c;
    // Erzwingt Speicher-Lesezugriff auf d_1c002c in jeder Runde der Warteschleife
    struct Z { static int ne(volatile signed char *p, signed char v) { return *p != v; } static int ne2(int v) { return *(volatile signed char *)&d_1c002c != v; } };
    while ((u = Z::ne((signed char *)&d_1c002c, f_042430((struct hero *)(p1)))) != 0) f_041ae0(1);
    f_0bbf00(A(d_1bf230));
    while (done == (short)0) {
        if (f_0dbfe0(d_1c0004) > 1) {
            f_0bf6c0(A(d_1c2c64), 6);
            s = f_0bf8e0(A(d_1c2c64), f_044ea0(p1), f_133fe0(A(d_1c3498), ((int)(f_0422b0((struct hero *)(p1))))), 0x2040018, 3, 0x2040019, 0x204001a, 0x204001b);
            f_0bf680(A(d_1c2c64));
            if (s == 1) {
                f_044300(p1, (short)(f_042960((struct hero *)(p1)) / 2));
                f_0bf730(A(d_1c2c64), 0x204001c);
                d_1a9670 = f_0dc020(d_1c0004, p1);
                a = f_038d70(d_1c0004, 0x204001d);
                if (a != 0) f_03c210(a, p1, 10, 1);
                done = 1;
            } else if (s == 2) {
                if (f_0de410(d_1c0004, 2, 0, 0)) {
                    f_0bf730(A(d_1c2c64), 0x204001e);
                    d_1a9670 = f_0dc020(d_1c0004, p1);
                    a = f_038d70(d_1c0004, 0x204001d);
                    if (a != 0) f_03c210(a, p1, 10, 1);
                    done = 1;
                } else {
                    f_0bf730(A(d_1c2c64), 0x204001f);
                }
            } else if (s == 3) {
                d_1a9670 = f_0dc020(d_1c0004, p1);
                a = f_038d70(d_1c0004, 0x2040020);
                if (a != 0 && f_042a10((struct hero *)(a))) {
                    s = f_0429a0((struct hero *)(a));
                    if (s >= 0xf) {
                        s = f_03d3d0(a, 0xf, 0);
                        if (s != (short)0) {
                            f_044230(a, 0xf);
                            f_0bf730(A(d_1c2c64), 0x2040021);
                            d_1a9670 = f_0dc020(d_1c0004, p1);
                            done = 1;
                            a = f_038d70(d_1c0004, 0x204001d);
                            if (a != 0) f_03c210(a, p1, 10, 1);
                        }
                    } else {
                        m.tables.p[1] = a;
                        f_0bf730(A(d_1c2c64), 0x2040022);
                        m.tables.p[1] = p1;
                    }
                }
            }
        } else {
            done = 1;
            f_0bf730(A(d_1c2c64), 0x2040023);
        }
        if (done == (short)0) {
            f_0bf730(A(d_1c2c64), 0x2040024);
            s = f_145850(1, 6, 2);
            done = 1;
            f_0dbb20(d_1c0004, (int)s);
        }
    }
    while ((u = Z::ne2(c18)) != 0) f_041ae0(1);
    d_1a4423 = (d_1a4423 & 0) ? 0 : d_1a4423; // Haelt Konfliktsortierung fuer Registerzuteilung
    f_0bbf00(A(d_1bf230));
    f_1254a0((int)&m, 0);
}

//@ f_032470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle 31 Inventarplätze (0 bis 0x1e) des Helden p1 nach dem ersten Gegenstand, der
 *   als Nahrungsmittel/Proviant gekennzeichnet ist (f_0a7930() != 0 und Untertyp f_0a78b0() == 1), und schreibt
 *   dessen Slot-Index nach *p2 sowie die Item-ID nach *p3.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 sowie die Ausgabezeiger p2 (Slot) und p3
 *   (Item-ID) entgegen und gibt 1 bei Erfolg oder 0 bei Fehlschlag zurück.
 * - Wichtige Variablen: Prüft die 31 Slots über f_042a60 und schlägt die Gegenstandseigenschaften in d_1c2c40
 *   nach.
 === Ende Beschreibung === */
int f_032470(int p1, short *p2, short *p3)
{
    int ret;
    short i, r;
    ret = 0;
    for (i = 0; i <= 0x1e; i = i + 1) {
        r = f_042a60((struct hero *)(p1), (int)i);
        if (d_1c2c40[r]->f_0a7930() != 0 && (signed char)d_1c2c40[r]->f_0a78b0() == 1) {
            *p2 = i;
            ret = 1;
            *p3 = r;
            break;
        }
    }
    return ret;
}

//@ f_0324e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht im Inventar des Helden p1 in bevorzugter Reihenfolge nach einem Getränk: zuerst nach
 *   Gegenstand 0x17, dann nach einem nicht leeren Wasserschlauch 0x1e (i_032630), danach nach 0x5c, 0x5b und
 *   0x142 und schließlich allgemein nach jedem trinkbaren Gegenstand (f_0a7930() != 0 und f_0a78b0() == 0).
 *   Gefundener Slot und Item-ID werden in *p2 und *p3 abgelegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 sowie die Ausgabezeiger p2 (Slot) und p3
 *   (Item-ID) und gibt 1 zurück, wenn ein Getränk gefunden wurde, sonst 0.
 * - Wichtige Variablen: Nutzt f_0d4aa0 für gezielte Gegenstandssuchen und d_1c2c40 für die allgemeine
 *   Getränkeprüfung.
 === Ende Beschreibung === */
int f_0324e0(int p1, short *p2, short *p3)
{
    int t239_8;
    short s, t;
    int ok, k;
    ok = 1;
    *p3 = 0x17;
    s = f_0d4aa0(p1, 0x17);
    *p2 = s;
    if ((t239_8 = *p2) == -1) {
        *p3 = 0x1e;
        s = i_032630(p1);
        *p2 = s;
        if (s == -1) {
            *p3 = 0x5c;
            s = f_0d4aa0(p1, 0x5c);
            *p2 = s;
            if (s == -1) {
                *p3 = 0x5b;
                s = f_0d4aa0(p1, 0x5b);
                *p2 = s;
                if (s == -1) {
                    *p3 = 0x142;
                    s = f_0d4aa0(p1, 0x142);
                    *p2 = s;
                    if (s == -1) ok = 0;
                }
            }
        }
    }
    if (ok == 0) {
        for (s = 0; s <= 0x1e; s = s + 1) {
            t = f_042a60((struct hero *)(p1), (int)s);
            if (((RivaItemDefinition *)(*(int *)TB(t)))->f_0a7930() != 0 && (signed char)((RivaItemDefinition *)(*(int *)TB(t)))->f_0a78b0() == 0 && t != 0x1e) {
                *p2 = s;
                *p3 = t;
                ok = 1;
                break;
            }
        }
    }
    return ok;
}
//@ f_032630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die 31 Inventarslots (0 bis 30) des Helden p1 nach einem Wasserschlauch (Item-ID
 *   0x1e), der noch nicht leer ist (f_042d30(p1, k) == 0), und gibt dessen Slot-Index zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt den gefundenen Slot-Index
 *   (0..30) oder -1 zurück.
 * - Wichtige Variablen: Liest die Item-IDs an p1 + 0x1a8 + k * 0x1b und prüft den Leer-Status über f_042d30.
 === Ende Beschreibung === */
int f_032630(int p1)
{
    int i, k;
    for (i = 0; (k = (short)i) < 0x1f; i = i + 1) {
        if (*(short *)(p1 + 0x1a8 + k * 0x1b) == 0x1e) {
            if (f_042d30((struct hero *)(p1), k) == 0) return i;
        }
    }
    return -1;
}

//@ f_032670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht je nach Parameter p2 entweder unter den 15 Körperslots (p2 == 1: Slots 0 bis 14) oder
 *   unter den 16 Rucksackslots (p2 != 1: Slots 15 bis 30) des Helden p1 den ersten leeren Platz (Item-ID == 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Bereichswähler p2 (1 = Körper, 0 =
 *   Rucksack) und gibt den ersten freien Slot-Index oder -1 zurück.
 * - Wichtige Variablen: Prüft das 16-Bit-Feld *(short *)(p1 + 0x1a8 + i * 0x1b).
 === Ende Beschreibung === */
short f_032670(int p1, int p2)
{
    unsigned short i;
    short lo, hi;
    if (p2 == 1) i = 0; else i = 0xf;
    lo = i;
    if (p2 == 1) hi = 0xe; else hi = 0x1e;
    for (i = lo; (short)i <= hi; i = i + 1) {
        if (*(short *)(p1 + 0x1a8 + (short)i * 0x1b) == 0) return i;
    }
    return -1;
}

//@ f_0326d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt, wie viele freie Inventarplätze der Held p1 im gewählten Bereich (p2 == 1: Körperslots
 *   0..14; p2 != 1: Rucksackslots 15..30) momentan noch frei hat.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 und den Bereichswähler p2 entgegen und gibt
 *   die Anzahl der leeren Slots als short zurück.
 * - Wichtige Variablen: Durchläuft die Slots 0..14 bzw. 15..30 an p1 + 0x1a8 + i * 0x1b.
 === Ende Beschreibung === */
short f_0326d0(int p1, int p2)
{
    short n, i;
    short lo, hi;
    n = 0;
    if (p2 == 1) i = 0; else i = 0xf;
    lo = i;
    if (p2 == 1) hi = 0xe; else hi = 0x1e;
    for (i = lo; (short)i <= hi; i = i + 1) {
        if (*(short *)(p1 + 0x1a8 + (short)i * 0x1b) == 0) n = n + 1;
    }
    return n;
}

//@ f_032730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft ab Slot 0 (p2 != 0, alle Slots) oder ab Slot 15 (p2 == 0, nur Rucksack) alle bis
 *   Slot 30 belegten Inventarplätze des Helden p1, erzeugt über f_0a7840 den grammatisch passenden
 *   Gegenstandsnamen (Singular oder Plural mit Stückzahl) und trägt Slot-Index sowie Textzeiger in die
 *   Auswahlliste p3 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, das Bereichsflag p2, das Ausgabearray p3
 *   (6-Byte-Einträge aus Slot und Textzeiger) und das Stringpuffer-Array p4 und gibt die Anzahl der
 *   eingetragenen Gegenstände zurück.
 * - Wichtige Variablen: Greift auf die Item-Stammdaten d_1c2c40 zu und formatiert die Namen mit f_0a7840 und
 *   f_133fe0.
 === Ende Beschreibung === */
short f_032730(int p1, int p2, int p3, int p4)
{
    short s8, n, s1, l14;
    n = 0;
    s8 = (p2 == 0) ? 0xf : 0;
    for (; s8 < 0x1f; s8++) {
        s1 = f_042a60((struct hero *)(p1), s8);
        if (s1 != 0) {
            l14 = 1;
            *(short *)(n * 6 + p3) = s8;
            if (d_1c2c40[s1]->f_0a7950() && f_042ac0((struct hero *)(p1), s8) > 1) {
                l14 = f_042ac0((struct hero *)(p1), s8);
            }
            f_0a7840(d_1c2c40[s1], (char *)(*(int *)(p4 + n * 4)), l14);
            *(int *)(n * 6 + p3 + 2) = f_133fe0(A(d_1c3498), *(int *)(p4 + n * 4));
            n++;
        }
    }
    return n;
}
