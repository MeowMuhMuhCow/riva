/* === Beschreibung (Katalog) ===
 * Einheit gz_040280 (0x040280 - 0x0417f0)
 *
 * Überblick
 * Diese Einheit bündelt zentrale Helden- und Gruppen-Verwaltungsfunktionen: Änderungen an permanenter Lebens-
 * und Astralenergie (f_0406d0..f_040880), Vergabe und Abzug von Abenteuerpunkten (f_040780, f_0407e0), Auslösen
 * und Heilen von Krankheiten, Vergiftungen und Trunkenheit (f_040900..f_040e40), Prüfung auf kompletten
 * Gruppenverlust (f_040590, f_0405e0) sowie das Teilen und Wiedervereinigen von Heldengruppen
 * (f_041000..f_0416d0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 34/37 gleich (suche.py 29.10.2026, Basis gz_040280_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 11 gleich (vorher 11), Rest 549 (vorher 552)
// gz_040280.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x040280-0x0417F0
#include <string.h>
#include <stdarg.h>
#include "RIVAMEM.H"
#include "R_FIX.H"



typedef signed char SCH;
typedef signed char TCH;
typedef signed char ICH;
typedef char QCH;
typedef short NS;
typedef signed char CC;
#define SI i
#define SAMECHK(p1) d_1c002c == *(signed char *)((p1) + 0x99)
struct PL { int f0; int *a; int f8; int fc; int *b; short *c; int *d; char rest[0x20]; };
struct B28 { int a[7]; };
struct T3 { short a; char b; };
struct R { B28 h; char c1c; int i1d; short s21; short s23; short s25; short s27; short s29; short s2b; int i2d; int i31; int i35; int i39; short s3d; short s3f; int i41; int i45; char c49; char c4a; int i4b; int i4f; int i53; short s57; char c59; T3 t5a; char pad[4]; };
struct E3 { char a; short b; };
#define CPY(d,s) \
    (d)->c1c = (s)->c1c; (d)->i1d = (s)->i1d; (d)->s21 = (s)->s21; (d)->s23 = (s)->s23; \
    (d)->s25 = (s)->s25; (d)->s27 = (s)->s27; (d)->s29 = (s)->s29; (d)->s2b = (s)->s2b; \
    (d)->i2d = (s)->i2d; (d)->i31 = (s)->i31; (d)->i35 = (s)->i35; (d)->i39 = (s)->i39; \
    (d)->s3d = (s)->s3d; (d)->s3f = (s)->s3f; (d)->i41 = (s)->i41; (d)->i45 = (s)->i45; \
    (d)->c49 = (s)->c49; (d)->c4a = (s)->c4a; (d)->i4b = (s)->i4b; (d)->i4f = (s)->i4f; \
    (d)->i53 = (s)->i53; (d)->s57 = (s)->s57; (d)->c59 = (s)->c59; \
    (d)->t5a = (s)->t5a;
int f_030ed0(void *p1, int p2);
int f_038c40(void *p1);
int f_038c80(void *p1);
int f_038e90(void *p1, int p2);
int f_039040(void *p1);
int f_0391b0(void *p1, int p2);
int f_039ac0(void *p1, unsigned (*cb)(char *));
int f_041ae0(int p1);













QCH f_0435c0(void *p1, int p2);
int f_0435e0(void *p1, int p2, int p3);
int f_043620(void *p1, int p2, int p3);
int f_043690(void *p1, int p2, int p3);
int f_043700(void *p1, int p2, int p3);
int f_043770(void *p1, int p2, int p3);
int f_0437e0(void *p1, int p2, int p3);
signed char f_043820(void *p1, int p2);
int f_043840(void *p1, int p2, int p3);
int f_043880(void *p1, int p2, int p3);
int f_0438f0(void *p1, int p2, int p3);
int f_043960(void *p1, int p2, int p3);
int f_0439d0(void *p1, int p2, int p3);
int f_043a40(void *p1, int p2, int p3);
int f_044040(int p1);
int f_044060(int p1, int p2);
int f_045430(void *p1, int p2, int p3);
int f_0b0f40(void *p1);
int f_0bbf00(void *p1);
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
short f_0bf820(...);
int f_0c0020(void *p1, int p2);
short f_044c90(void *p1, int p2, int p3);
short f_0cda50();
int f_0d49b0(void *p1);
int f_0d4a10(int p1);
short f_0d4ad0(void *p1);
short f_0d4b00(void *p1);
short f_0db940(void *p1);
short f_0db970(void *p1);
unsigned short f_0dbfb0(void *p1, void *p2);
short f_0dc020(void *p1, int p2);
short f_0dcc10(void *p1);
int f_0dcc40(void *p1, int p2, int p3);
int f_0dcdf0(void *p1, int p2);
int f_0de0d0(int (*cb)(void *));
int f_0de790(void *p1, int p2, int p3);
int f_0de7a0(void *p1, int p2);
int f_0de7b0(void *p1, int p2);
short f_0de7f0(void *p1);
short f_0de820(void *p1);
int f_0de990(void *p1, int p2);
int f_0de9c0(void *p1);
short f_0de9e0(void *p1);
int f_0e9300(void *p1, void *p2, int p3);
int f_0e93f0(void *p1, void *p2, int p3);
void f_125400(void *p1, void *p2, void *p3, int p4);
int f_1254a0(void *p1, int);
int f_133fe0(void *p1, void *p2);
short f_1457e0(int p1);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_14778f(void *p1, int p2);
extern char d_1a9670;
extern int d_1bc8d0[];
extern int d_1a9820;
extern int d_1bc88c;
extern int d_1bc8cc;
extern char *d_1bc8e8;
extern struct E3 d_1bc8ec;
extern char *d_1bc8f0;
extern int d_1bdb94;
extern int d_1bf230;
extern char d_1bfaec;
extern char d_1bfdbc[];
extern R *d_1c0004;
extern signed char d_1c0028;
extern signed char d_1c002c;
extern unsigned short d_1c20b2;
extern volatile short d_1c212a;
extern struct E3 **d_1c212c;
extern short d_1c2198;
extern volatile int d_1c219c;
extern int d_1c21a4;
extern int d_1c29c4[];
extern int d_1c2a80;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
//@ f_040280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft, ob ein Held mit dem internen Namen p2 bereits in einem der sechs
 *   regulären Heldenslots ab d_1bc8f0 aktiv ist.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und den Namensstring p2 (char *)
 *   und gibt 1 bei Übereinstimmung oder 0 zurück.
 * - Wichtige Variablen: Verglichen wird p2 per strcmp mit f_042320(c) über alle sechs Slots (Stride 0x5ef).
 === Ende Beschreibung === */
int f_040280(int p1, char *p2)
{
    short i;
    char *c = d_1bc8f0;
    int r = 0;
    for (i = 0; i < 6; i = i + 1, c = c + 0x5ef) {
        if (((TCH)(f_042350((struct hero *)(c))))) {
            if (strcmp(f_042320((struct hero *)(c)), p2) == 0) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
//@ f_0402d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft, ob der interne Heldenname p2 bereits in einem
 *   0x26-Byte-Archivlisten-Array p4 der Länge p3 enthalten ist.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1, den Suchnamen p2, die Listenlänge
 *   p3 und das Array p4 und gibt 1 zurück, falls der Name gefunden wurde, sonst 0.
 * - Wichtige Variablen: Der interne Name steht in jedem 0x26-Byte-Eintrag ab Offset +0x10.
 === Ende Beschreibung === */
int f_0402d0(int p1, char *p2, NS p3, char *p4)
{
    int r = 0;
    short i = 0;
    for (i = 0; i < p3; i++) {
        if (strcmp(p2, p4 + i * 0x26 + 0x10) == 0) {
            r = 1;
            break;
        }
    }
    return r;
}
//@ f_040310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion entfernt den Eintrag p2 aus dem 0x26-Byte-Archivlisten-Array *(char )(p1 +
 *   2) der Länge p3, indem nachfolgende Einträge per memmove nachgerückt werden.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zustandsobjekt p1, den zu löschenden Index p2 (short) und die
 *   bisherige Listenlänge p3 (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Handelt es sich um das letzte Element (p2 == p3 - 1), wird der Eintrag mit memset
 *   genullt.
 === Ende Beschreibung === */
void f_040310(char *p1, short p2, short p3)
{
    int i = p2;
    if (i == p3 - 1) {
        memset(*(char **)(p1 + 2) + i * 0x26, 0, 0x26);
    } else {
        memmove(*(char **)(p1 + 2) + i * 0x26, *(char **)(p1 + 2) + (i + 1) * 0x26, (p3 - i) * 0x26);
    }
}
//@ f_040360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Konstantenfunktion gibt den festen Wert 0x19 (25, Standard-Überblendgeschwindigkeit bzw.
 *   Talent-ID Schätzen) zurück.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 0x19 zurück.
 * - Wichtige Variablen: Keine Variablen.
 === Ende Beschreibung === */
int f_040360()
{
    return 0x19;
}
//@ f_040370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion rechnet einen Geldbetrag p2 (in Hellern) in Dukaten (p2 / 100), Silberlinge
 *   ((p2 % 100) / 10) und Heller (p2 % 10) um und formatiert ihn über den String 0x20000022 in den Ausgabepuffer
 *   p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielpuffer p1 (void *) und den Betrag p2 (unsigned, in
 *   Hellern) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die drei Teilbeträge werden in die Nachrichten-Platzhalter pl.d[1], pl.c[1] und pl.c[2]
 *   eingetragen.
 === Ende Beschreibung === */
void f_040370(void *p1, unsigned p2)
{
    PL pl;
    unsigned h;
    short t;
    f_125400(&pl, &d_1c349c, &d_1c3870, (int)&d_1c3498);
    h = p2 / 100;
    p2 = p2 % 100;
    t = p2 / 10;
    p2 = p2 % 10;
    pl.d[1] = h;
    pl.c[1] = t;
    pl.c[2] = p2;
    f_0e93f0(&d_1c38b0, p1, 0x20000022);
    f_1254a0(&pl, 0);
}
//@ f_040400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zeigt eine seitenweise blätterbare Auswahlliste (je 10 Einträge pro Seite plus
 *   "Weiterblättern"-Option 0x20000024) für das 0x26-Byte-Charakterlisten-Array p1 mit p2 Einträgen an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Array p1 (char *), die Gesamtanzahl p2 (short) und den Modus
 *   p3 (-1 = Überschrift "Charakter löschen" 0x20000025, sonst "Charakter aufnehmen" 0x20000026) und gibt den
 *   ausgewählten Gesamtindex (0..p2-1) oder -1 bei Abbruch zurück.
 * - Wichtige Variablen: off merkt sich den Seiten-Startindex (0, 10, 20, ...).
 === Ende Beschreibung === */
short f_040400(char *p1, short p2, short p3)
{
    short sel = 0;
    short i = 0;
    short limit;
    short n;
    short off = 0;
    short result;
    while (sel != -1) {
        limit = (off + 10 < p2) ? 10 : p2 - off;
        i = 0;
        while (i < limit) {
            d_1c29c4[i] = f_133fe0(&d_1c3498, p1 + (i + off) * 0x26);
            i = i + 1;
        }
        i = limit;
        n = i;
        if (10 < p2) {
            d_1c29c4[n] = 0x20000024;
            n = n + 1;
        }
        sel = f_0bf820(&d_1c2c64, (p3 != -1) + 0x20000025, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7], d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11]);
        if (10 < p2 && sel == n) {
            off = off + 10;
            if (off < p2) continue;
            off = 0;
        } else if (sel != -1) {
            result = off + sel - 1;
            return result;
        }
    }
    return -1;
}
//@ f_040550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht im globalen Helden-Array d_1bc8f0 (7 Slots inklusive NPC-Slot) nach dem
 *   ersten freien Slot (Klasse == 0).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den freien Slot-Index (0..6) oder -1
 *   zurück.
 * - Wichtige Variablen: Geprüft wird über f_042350(c), ob der Slot belegt ist.
 === Ende Beschreibung === */
int f_040550()
{
    char *c = d_1bc8f0;
    int i = 0;
    for (; (short)i <= 6; i = i + 1, c = c + 0x5ef) {
        if (!((TCH)(f_042350((struct hero *)(c))))) return i;
    }
    return -1;
}
//@ f_040590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zählt, wie viele Helden insgesamt (über alle nicht gefangenen Teilgruppen in
 *   d_1bfdbc) noch am Leben und handlungsfähig (f_0d49b0 != 0) sind.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt die Anzahl handlungsfähiger Helden zurück.
 * - Wichtige Variablen: f_042430(c) liefert die Gruppennummer k des Helden, und f_0de9c0(d_1bfdbc + k * 0x61)
 *   prüft, ob diese Teilgruppe ausgeschaltet/gefangen ist.
 === Ende Beschreibung === */
int f_040590()
{
    char *c = d_1bc8f0;
    short i = 0;
    int n = 0;
    SCH k;
    for (; i <= 6; i = i + 1, c = c + 0x5ef) {
        if (f_0d49b0(c) != 0) {
            k = ((SCH)(f_042430((struct hero *)(c))));
            if (f_0de9c0(d_1bfdbc + k * 0x61) == 0) n = n + 1;
        }
    }
    return n;
}
//@ f_0405e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion prüft nach Kämpfen oder Schadensereignissen, ob die gesamte Heldengruppe (bzw.
 *   alle regulären Helden außer dem NPC in Slot 6, p5 = d_1bc8f0 + 0x239a) kampfunfähig oder tot ist, und setzt
 *   in diesem Fall die Spielende-Kennung d_1c21a4 (7 für allgemeines Game Over, 9 bei Niederlage in den
 *   Bereichen 7..9) oder schaltet bei ausgelöschter aktiver Teilgruppe über f_041ae0(0) auf eine noch lebende
 *   andere Teilgruppe um.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: p5 zeigt auf den siebten Heldenslot (6 * 0x5ef = 0x239a), den NPC-Begleiter, der allein
 *   die Gruppe nicht weiterführen kann.
 === Ende Beschreibung === */
void f_0405e0()
{
    short n;
    char *p5 = d_1bc8f0 + 0x239a;
    char *p6 = d_1bc8f0;
    short i = 0;
    SCH k;
    unsigned short u;
    short s;
    n = 0;
    for (; i <= 6; i = i + 1, p6 = p6 + 0x5ef) {
        if (f_0d49b0(p6) != 0) {
            k = ((SCH)(f_042430((struct hero *)(p6))));
            if (f_0de9c0(d_1bfdbc + k * 0x61) == 0) n = n + 1;
        }
    }
    *(short *)&d_1c219c = 0;
    if (n == 0) goto check_range;
    if (n == 1 && f_0d49b0(p5) != 0) goto check_range;
    goto second_case;
set_nine:
    *(short *)&d_1c21a4 = 9;
    goto after_range;
check_range:
    u = ((unsigned short (*)(void *))f_0de820)(d_1c0004);
    if (u < (unsigned short)7) goto after_range;
    if (u <= (unsigned short)9) goto set_nine;
after_range:
    if (*(short *)&d_1c21a4 == 0) {
        *(short *)&d_1c21a4 = 7;
        return;
    }
    goto finished;
second_case:
    s = f_0db940(d_1c0004);
    if (s == 0 || (s == 1 && ((int (*)(void *, void *))f_0dbfb0)(d_1c0004, p5) != 0 && f_0d49b0(p5) != 0)) {
        *(short *)&d_1c21a4 = 0;
        f_041ae0(0);
    }
finished:
    ;
}
//@ f_0406d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion senkt sowohl die maximale (+0x74) als auch die aktuelle (+0x76) Astralenergie
 *   eines lebenden magiebegabten Helden p1 permanent um p2 Punkte (mindestens auf 0, z. B. bei einem
 *   Stabzauber).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 (char *) und den Abzug p2 (short) und hat
 *   keinen Rückgabewert.
 * - Wichtige Variablen: *(short *)(p1 + 0x74) ist die permanente Maximal-AE, *(short *)(p1 + 0x76) die aktuelle
 *   AE.
 === Ende Beschreibung === */
void f_0406d0(char *p1, NS p2)
{
    if (!((QCH)(f_042470((struct hero *)(p1)))) && 0 < (short)p2) {
        if (f_042a10((struct hero *)(p1)) != 0) {
            if ((*(short *)(p1 + 0x74) -= p2) < 0) *(short *)(p1 + 0x74) = 0;
            if ((*(short *)(p1 + 0x76) -= p2) < 0) *(short *)(p1 + 0x76) = 0;
        }
    }
}
//@ f_040730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion erhöht sowohl die maximale (+0x74) als auch die aktuelle (+0x76) Astralenergie
 *   eines lebenden magiebegabten Helden p1 permanent um p2 Punkte (z. B. beim Stufenaufstieg oder durch ein
 *   starkes Zauberelixier).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Zuwachs p2 (short) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Überschreitet die aktuelle AE nach der Addition die maximale AE, wird sie auf das
 *   Maximum begrenzt.
 === Ende Beschreibung === */
void f_040730(char *p1, NS p2)
{
    short s;
    if (!((QCH)(f_042470((struct hero *)(p1)))) && 0 < (short)p2) {
        if (f_042a10((struct hero *)(p1)) != 0) {
            *(short *)(p1 + 0x74) = *(short *)(p1 + 0x74) + p2;
            s = (*(short *)(p1 + 0x76) += p2);
            if (*(short *)(p1 + 0x74) < s) *(short *)(p1 + 0x76) = *(short *)(p1 + 0x74);
        }
    }
}
//@ f_040780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion schreibt einem lebenden Helden p1 Abenteuerpunkte (AP) gut, wobei der Basiswert
 *   p2 leicht zufällig gestreut ((p2 + 6 - 1W6) * d_1c20b2) und im Einsteigermodus (d_1bfaec == 0) für Helden
 *   unter Stufe 10 (p1 + 0x39 < 10) verdoppelt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den AP-Basiswert p2 (short) und gibt den
 *   neuen Gesamt-AP-Stand (*(int *)(p1 + 0x3a)) zurück.
 * - Wichtige Variablen: d_1bdb94 wird auf 1 gesetzt, damit die Hauptschleife anschließend auf einen erreichten
 *   Stufenaufstieg prüft.
 === Ende Beschreibung === */
int f_040780(char *p1, short p2)
{
    short sv;
    short r;
    signed char c;
    int n;
    int old;
    int v;
    if (!((QCH)(f_042470((struct hero *)(p1))))) {
        n = p2;
        sv = d_1c20b2;
        r = f_1457e0(6);
        v = ((n + 6) - r) * sv;
        c = d_1bfaec;
        if (c == 0 && *(signed char *)(p1 + 0x39) < 10) v = v * 2;
        old = *(int *)(p1 + 0x3a);
        old += v;
        *(volatile int *)&d_1bdb94 = 1;
        *(int *)(p1 + 0x3a) = old;
    }
    return *(int *)(p1 + 0x3a);
}
//@ f_0407e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zieht einem lebenden Helden p1 den Betrag p2 * d_1c20b2 von seinen
 *   Abenteuerpunkten (+0x3a, bis minimal 0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Abzugsfaktor p2 (short) und gibt den
 *   neuen AP-Stand zurück.
 * - Wichtige Variablen: d_1c20b2 ist der globale AP-Multiplikator.
 === Ende Beschreibung === */
int f_0407e0(char *p1, NS p2)
{
    if (!((QCH)(f_042470((struct hero *)(p1))))) {
        *(int *)(p1 + 0x3a) -= p2 * d_1c20b2;
        if (*(int *)(p1 + 0x3a) < 0) *(int *)(p1 + 0x3a) = 0;
    }
    return *(int *)(p1 + 0x3a);
}
//@ f_040820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion senkt die permanente maximale Lebensenergie (+0x70) eines lebenden Helden p1 um
 *   p2 Punkte (bis auf mindestens 1) und kappt gegebenenfalls auch die aktuelle Lebensenergie (+0x72) auf das
 *   neue Maximum.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den permanenten LE-Abzug p2 (short) und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Im Charakterbogenmodus (d_1c2a80 == 0x30000 oder 0x30001) setzt die Funktion das
 *   Neuzeichnungs-Flag d_1c2198 = 1.
 === Ende Beschreibung === */
void f_040820(char *p1, NS p2)
{
    short s;
    if (!((QCH)(f_042470((struct hero *)(p1)))) && 0 < (short)p2) {
        s = *(short *)(p1 + 0x70) -= p2;
        if (s <= 0) *(short *)(p1 + 0x70) = 1;
        if (*(short *)(p1 + 0x72) > *(short *)(p1 + 0x70)) *(short *)(p1 + 0x72) = *(short *)(p1 + 0x70);
    }
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) d_1c2198 = 1;
}
//@ f_040880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion erhöht sowohl die maximale (+0x70) als auch die aktuelle (+0x72) Lebensenergie
 *   eines lebenden Helden p1 permanent um p2 Punkte und hebt bei mindestens 5 aktuellen Lebenspunkten eine
 *   eventuelle Bewusstlosigkeit (f_030ed0(p1, 0)) auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den permanenten LE-Zuwachs p2 (short) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: *(short *)(p1 + 0x70) ist die maximale LE, *(short *)(p1 + 0x72) die aktuelle LE.
 === Ende Beschreibung === */
void f_040880(char *p1, NS p2)
{
    if (!((QCH)(f_042470((struct hero *)(p1)))) && 0 < (short)p2) {
        *(short *)(p1 + 0x70) += p2;
        *(short *)(p1 + 0x72) += p2;
        if (*(short *)(p1 + 0x72) > *(short *)(p1 + 0x70))
            *(short *)(p1 + 0x72) = *(short *)(p1 + 0x70);
        if (*(short *)(p1 + 0x72) >= 5) {
            if (((QCH)(f_0425f0((struct hero *)(p1))))) f_030ed0(p1, 0);
        }
    }
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) d_1c2198 = 1;
}
//@ f_040900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion vergiftet einen lebenden Helden p1 mit dem Gift p2 (1..9), sofern er nicht
 *   bereits an diesem Gift leidet (wobei Gift 9 nur magiebegabte Helden betreffen kann), und setzt die
 *   Gift-Verlaufszähler zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und die Gift-ID p2 (short) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: f_0435e0(p1, p2, -1) aktiviert das Gift im Status -1 (akut vergiftet).
 === Ende Beschreibung === */
void f_040900(char *p1, short p2)
{
    short i;
    if (!((QCH)(f_042470((struct hero *)(p1))))) {
        if (!f_0435c0(p1, p2)) {
            if (p2 == 9 && f_042a10((struct hero *)(p1)) == 0) return;
            i = p2;
            f_0435e0(p1, i, -1);
            f_043620(p1, i, 0);
            f_043690(p1, i, 0);
            f_043700(p1, i, 0);
            f_043770(p1, i, 0);
            f_0437e0(p1, i, 0);
        }
    }
}
//@ f_040980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion infiziert einen lebenden Helden p1 mit der Krankheit p2 (1..7), sofern die
 *   Krankheit noch nicht aktiv ist und der Held bei Krankheit 2 (Dumpfschädel) nicht durch das Flag *(p1 + 0xcf)
 *   geschützt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und die Krankheits-ID p2 (short) und hat
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Die Krankheitsdaten liegen als 5-Byte-Einträge ab p1 + 0xc0 + p2 * 5; f_043840(p1, p2,
 *   -1) markiert die Krankheit als akut ausgebrochen.
 === Ende Beschreibung === */
void f_040980(char *p1, short p2)
{
    int i;
    if (!((QCH)(f_042470((struct hero *)(p1)))) && !*(p1 + 0xc0 + p2 * 5) && (p2 != 2 || !*(p1 + 0xcf))) {
        i = p2 + 1 - 1;
        f_043840(p1, i, -1);
        f_043880(p1, i, 0);
        f_0438f0(p1, i, 0);
        f_043960(p1, i, 0);
        f_0439d0(p1, i, 0);
        f_043a40(p1, i, 0);
    }
}
//@ f_040a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion infiziert den Helden p1 mit einer prozentualen Wahrscheinlichkeit von p3 %
 *   (1W100 <= p3) mit der Krankheit p2.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die Krankheits-ID p2 (short) und die
 *   Ansteckungschance p3 (1..100) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Bei Erfolg wird f_040980(p1, p2) aufgerufen.
 === Ende Beschreibung === */
void f_040a00(char *p1, short p2, short p3)
{
    short r = f_1457e0(100);
    if (r <= p3) {
        if (f_043820(p1, p2) != -1) f_040980(p1, p2);
    }
}
//@ f_040a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion versetzt den Helden p1 in den Zustand der Trunkenheit (*(p1 + 0xb3) = 1),
 *   verändert vorübergehend alle 14 positiven und schlechten Eigenschaften (MU, KK, IN und vier Ängste +1, KL,
 *   CH, FF, GE und drei Ängste -1) und spielt das Rülps-/Trunkenheitsgeräusch (0x20009) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Flag *(p1 + 0xb3) verhindert, dass die Attributsmodifikationen bei weiterem Trinken
 *   mehrfach gestapelt werden.
 === Ende Beschreibung === */
void f_040a40(char *p1)
{
        int codex_arg_4_419;
    if (!*(p1 + 0xb3)) {
        d_1bc88c = 1;
        *(p1 + 0xb3) = 1;
        f_045430(p1, 0, 1);
        f_045430(p1, 1, -1);
        f_045430(p1, 2, -1);
        f_045430(p1, 3, -1);
        f_045430(p1, 4, -1);
        f_045430(p1, 5, 1);
        f_045430(p1, 6, 1);
        f_045430(p1, 7, 1);
        f_045430(p1, 8, -1);
        f_045430(p1, 9, -1);
        f_045430(p1, 10, 1);
        f_045430(p1, 0xb, -1);
        f_045430(p1, 0xc, 1);
        f_045430(p1, 0xd, 1);
        d_1bc88c = 0;
    }
    if (f_14778f(&d_1c2edc, 0x20009) == 0) {
        f_147323(&d_1c2edc, 0x20009, 0x7fff, 0x8000, (codex_arg_4_419 = d_1a9820), 0, 1);
    }
}
//@ f_040b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion nüchtert einen betrunkenen Helden p1 (*(p1 + 0xb3) != 0) wieder aus und macht
 *   sämtliche 14 Eigenschaftsänderungen aus f_040a40 exakt rückgängig.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und hat keinen Rückgabewert.
 * - Wichtige Variablen: *(p1 + 0xb3) wird wieder auf 0 gesetzt.
 === Ende Beschreibung === */
void f_040b90(char *p1)
{
    if (*(p1 + 0xb3)) {
        d_1bc88c = 1;
        *(p1 + 0xb3) = 0;
        f_045430(p1, 0, -1);
        f_045430(p1, 1, 1);
        f_045430(p1, 2, 1);
        f_045430(p1, 3, 1);
        f_045430(p1, 4, 1);
        f_045430(p1, 5, -1);
        f_045430(p1, 6, -1);
        f_045430(p1, 7, -1);
        f_045430(p1, 8, 1);
        f_045430(p1, 9, 1);
        f_045430(p1, 10, -1);
        f_045430(p1, 0xb, 1);
        f_045430(p1, 0xc, -1);
        f_045430(p1, 0xd, -1);
        d_1bc88c = 0;
    }
}
//@ f_040cb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt eine Feilschen-Talentprobe (Talent 0x15 = 21) für den Helden p1 beim
 *   Einkaufen oder Verkaufen durch, wobei der Probenmodifikator aus der Stückzahl p2, dem Warenpreis p3, dem
 *   geforderten Rabattprozentsatz p4 und einem Händleraufschlag p5 berechnet wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die Menge p2, den Preis p3, den Rabattwunsch
 *   p4 und den Basismodifikator p5 und gibt das Ergebnis der Talentprobe f_044c90(p1, 0x15, c) zurück.
 * - Wichtige Variablen: Kleine Mengen (p2 <= 2), billige Waren (p3 < 500) und hohe Rabattforderungen (p4 / 5 +
 *   1) erschweren die Probe zusätzlich.
 === Ende Beschreibung === */
int f_040cb0(void *p1, short p2, int p3, short p4, short p5)
{
    signed char c = p5;
    c += p2 == 1 ? 2 : p2 == 2 ? 1 : p2 < 5 ? 0 : (p2 < 9) - 2;
    c += p3 < 100 ? 2 : p3 < 500 ? 1 : p3 < 1000 ? 0 : (p3 < 2000) - 2;
#if FIX_R028   /* R028: Keinen +1-Probenaufschlag bei 0 % Rabattforderung (p4 == 0) addieren */
    if (p4 > 0) c += p4 / 5 + 1;
#else
    c += p4 / 5 + 1;
#endif
    return f_044c90(p1, 0x15, (signed char)c);
}
//@ f_040d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion hebt eine magische Versteinerung oder Paralyse (f_0425a0) eines Helden p1 auf,
 *   sofern sich der Held im selben Gebiet (d_1c002c == *(signed char *)(p1 + 0x99)) wie die aktive Gruppe
 *   befindet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 zurück, wenn der Zustand
 *   aufgehoben wurde, sonst 0.
 * - Wichtige Variablen: *(signed char *)(p1 + 0x99) speichert die Orts-/Dungeonkennung des Helden.
 === Ende Beschreibung === */
int f_040d60(char *p1)
{
    if (((QCH)(f_0425a0((struct hero *)(p1))))) {
        signed char c = *(signed char *)(p1 + 0x99);
        int eq = (d_1c002c == (int)c) ? 1 : 0;
        if (eq) {
            f_0425b0((struct hero *)(p1), 0);
            return 1;
        }
    }
    return 0;
}
//@ f_040da0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion leitet für die aktuell schwerste Krankheit (f_0d4ad0) des Helden p1 die
 *   Heilungs-/Genesungsphase (Status = 1, Dauer = 0) ein, sofern sich der Held am aktuellen Ort d_1c002c
 *   befindet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 bei eingeleiteter Heilung oder 0
 *   zurück.
 * - Wichtige Variablen: f_043840(p1, s, 1) stellt den Krankheitsstatus von -1 (akut) auf 1 (abklingend) um.
 === Ende Beschreibung === */
int f_040da0(char *p1)
{
    short s = f_0d4ad0(p1);
    int i;
    if (s != (short)0) {
        signed char c = *(signed char *)(p1 + 0x99);
        int eq = (d_1c002c == (int)c) ? 1 : 0;
        if (eq) {
            i = s;
            f_043840(p1, SI, 1);
            f_043880(p1, SI, 0);
            return 1;
        }
    }
    return 0;
}
//@ f_040e00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion leitet für das aktuell stärkste aktive Gift (f_0d4b00) des Helden p1 die
 *   Entgiftungs-/Erholungsphase (Status = 1, Dauer = 0) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 zurück, falls eine Vergiftung
 *   neutralisiert wurde, sonst 0.
 * - Wichtige Variablen: f_0435e0(p1, s, 1) setzt den Giftstatus auf 1 (abklingend).
 === Ende Beschreibung === */
int f_040e00(void *p1)
{
    short s = f_0d4b00(p1);
    int i;
    if (s != (short)0) {
        i = s;
        f_043620(p1, SI, 0);
        f_0435e0(p1, SI, 1);
        return 1;
    }
    return 0;
}
//@ f_040e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion gibt einem Helden p1 vorübergehend abgezogene maximale Lebenspunkte (*(signed
 *   char *)(p1 + 0x8c)) wieder auf seine permanente Lebensenergie (+0x70) zurück und löscht den Abzugszähler.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und hat keinen Rückgabewert.
 * - Wichtige Variablen: Das Feld p1 + 0x8c speichert temporär reduzierte Maximal-LE.
 === Ende Beschreibung === */
void f_040e40(char *p1)
{
    short c = *(signed char *)(p1 + 0x8c);
    *(p1 + 0x8c) = 0;
    *(short *)(p1 + 0x70) += c;
}
//@ f_040e60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion entfernt einen Helden p1 vollständig aus dem aktiven Spiel (etwa beim Tod oder
 *   endgültigen Ausscheiden), setzt seinen Verbleib-Status auf p2, speichert/bereinigt ihn über f_0b0f40 und
 *   nullt den gesamten 0x5ef-Byte-Heldendatensatz im Speicher.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Abgangsgrund p2 (signed char) und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: memset(p1, 0, 0x5ef) gibt den Heldenslot wieder frei.
 === Ende Beschreibung === */
void f_040e60(char *p1, signed char p2)
{
    f_0429e0((struct hero *)(p1), p2);
    f_042450((struct hero *)(p1), 0);
    f_0b0f40(p1);
    memset(p1, 0, 0x5ef);
}
//@ f_040e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt die passende Text-ID für die Berufs-/Klassenbezeichnung eines Helden
 *   p1 unter Berücksichtigung des Geschlechts (f_042380 == 1 weiblich ab 0x2000004f, männlich ab 0x20000042)
 *   sowie spezieller NPC-Bezeichnungen (ID 7 -> 0x200001bb, ID 8 -> 0x200001bc).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt die 32-Bit-Text-ID der
 *   Klassenbezeichnung zurück.
 * - Wichtige Variablen: Die Charakterklasse wird über f_042350(p1) auf die Basis-Text-ID addiert.
 === Ende Beschreibung === */
int f_040e90(void *p1)
{
    int v;
    if (f_042400((struct hero *)(p1)) == 7) return 0x200001bb;
    if (f_042400((struct hero *)(p1)) == 8) return 0x200001bc;
    if (f_042380((struct hero *)(p1)) == 1) v = 0x2000004f; else v = 0x20000042;
    return ((TCH)(f_042350((struct hero *)(p1)))) + v;
}
//@ f_040ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion trägt ein spezielles Ereignis-Tripel (d_1bc8ec = {1, 0x227}) in die globale
 *   Ereigniswarteschlange d_1c212c ein.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und keinen Rückgabewert.
 * - Wichtige Variablen: d_1c212a ist der aktuelle Schreibindex in d_1c212c.
 === Ende Beschreibung === */
void f_040ef0()
{
    d_1bc8ec.a = 1;
    d_1bc8ec.b = 0x227;
    d_1c212c[d_1c212a] = &d_1bc8ec;
    d_1c212a += 1;
}
//@ f_040f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Callback-Wrapper-Funktion leitet den Heldenzeiger p1 direkt an f_044040 weiter (Prüfung,
 *   ob ein Held verwundet/behandlungsbedürftig ist oder eine bestimmte Eigenschaft aufweist).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt das Ergebnis von f_044040 zurück.
 * - Wichtige Variablen: Wird als Prädikat in f_040f70 und f_041530 verwendet.
 === Ende Beschreibung === */
unsigned f_040f30(char *p1)
{
    return f_044040((int)p1);
}
//@ f_040f40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Callback-Prüffunktion stellt fest, ob sich eine Teilgruppe p1 in einem der Bereiche 20,
 *   21 oder 22 (f_0de820(p1)) befindet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt 1 zurück, falls die Ortskennung
 *   zwischen 20 und 22 liegt, sonst 0.
 * - Wichtige Variablen: Wird als Callback an f_0de0d0 in f_040f70 übergeben.
 === Ende Beschreibung === */
int f_040f40(void *p1)
{
    short s = f_0de820(p1);
    int r = 0;
    if (s >= 20) {
        s = f_0de820(p1);
        if (s <= 22) r = 1;
    }
    return r;
}
//@ f_040f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion prüft, ob sich in der Gruppe p1 ein Held mit dem Status f_040f30 (f_044040)
 *   befindet, fragt den Spieler beim Betreten der Bereiche 20..22 mit der Sicherheitsabfrage 0x270000af, ob er
 *   wirklich fortfahren möchte, und setzt bei Bestätigung den Status über f_044060(h, 0) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt 1 zurück, wenn der Spieler die
 *   Aktion abgebrochen hat, sonst 0.
 * - Wichtige Variablen: h ist der über f_039ac0 gefundene betroffene Held.
 === Ende Beschreibung === */
int f_040f70(void *p1)
{
    int h;
    int b;
    PL pl;
    h = f_039ac0(p1, f_040f30);
    b = 0;
    if (h != 0) {
        if (f_0de0d0(f_040f40) != 0) {
            f_125400(&pl, &d_1c349c, &d_1c3870, (int)&d_1c3498);
            pl.a[1] = f_038c40(p1);
            if (f_0bf6f0(&d_1c2c64, 0x270000af) == 0) b = 1;
            f_1254a0(&pl, 0);
        }
        if (b == 0) f_044060(h, 0);
    }
    return b;
}
//@ f_041000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zählt, wie viele der sechs möglichen Teilgruppen-Slots im Array d_1bfdbc
 *   (Stride 0x61) aktuell mit mindestens einem Helden belegt sind.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt die Anzahl aktiver Teilgruppen (1..6) als
 *   char zurück.
 * - Wichtige Variablen: f_0de7f0 liefert die Heldenanzahl einer Teilgruppe.
 === Ende Beschreibung === */
char f_041000()
{
    ICH i = 0;
    char n = 0;
    do {
        if (0 < f_0de7f0(d_1bfdbc + i * 0x61)) n = n + 1;
        i = i + 1;
    } while (i < 6);
    return n;
}
//@ f_041030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese programmatische Gruppenteilungs-Funktion spaltet n per variadischer Argumentliste
 *   übergebene Helden aus der aktuellen Hauptgruppe d_1c0004 in eine neue Teilgruppe im Array d_1bfdbc ab,
 *   kopiert die Orts- und Positionsdaten der Hauptgruppe in die neue Teilgruppe und aktualisiert die Gesamtzahl
 *   der Teilgruppen in d_1c0028.
 * - Eingaben und Rückgabe: Die Funktion erhält die Anzahl n der abzuspaltenen Helden gefolgt von n Heldenzeigern
 *   und gibt den Zeiger R * auf die neu gebildete Teilgruppe zurück.
 * - Wichtige Variablen: Ist die Hauptgruppe d_1c0004 nach dem Abspalten leer (k == 0), wird d_1c0004 automatisch
 *   auf die neue Teilgruppe p1 umgesetzt.
 === Ende Beschreibung === */
R *f_041030(int n, ...)
{
    R *p1;
    R *src;
    short i;
    short k;
    int off;
    int p2;
    va_list ap;
    ICH ci;
    char cnt;
    signed char flag;
    va_start(ap, n);
    flag = *(volatile signed char *)&d_1c0028;
    p1 = 0;
    if (flag != 6) {
        i = 0;
        do {
            off = i * 0x61;
            p1 = (R *)(d_1bfdbc + off);
            i = i + 1;
            k = f_0de7f0(p1);
        } while (k != (short)0);
        src = d_1c0004;
        p1->h = src->h;
        CPY(p1, src)
        for (i = 0; i <= 6; i = i + 1) {
            f_0de790(p1, i, 0);
        }
        f_0de7b0(p1, 0);
        f_0de7a0(p1, 0);
        i = 0;
        if ((short)n > (short)0) {
            do {
                p2 = va_arg(ap, int);
                k = f_0dc020(d_1c0004, p2);
                f_0dcdf0(d_1c0004, k);
                k = f_0dcc10(p1);
                i = i + 1;
                f_0dcc40(p1, p2, k);
            } while (i < (short)n);
        }
        *(short *)&d_1c219c = 1;
        f_0bbf00(&d_1bf230);
    }
    if (p1 != 0) {
        k = f_0de7f0(p1);
        if (k <= 0) p1 = 0;
        k = f_0de7f0(d_1c0004);
        if ((int)k == 0) d_1c0004 = p1;
    } else {
        p1 = d_1c0004;
    }
    ci = 0;
    cnt = 0;
    do {
        k = f_0de7f0(d_1bfdbc + ci * 0x61);
        if (0 < k) cnt = cnt + 1;
        ci = ci + 1;
    } while (ci < 6);
    d_1c0028 = cnt;
    return p1;
}
//@ f_041220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt das interaktive "Gruppe teilen" über das Spielmenü aus. Sie prüft, ob
 *   genügend Helden zum Teilen vorhanden sind und ob das Teilen im aktuellen Bereich erlaubt ist (verboten in
 *   den Gebieten 7..9 sowie 0x17..0x19), legt einen freien Teilgruppen-Slot in d_1bfdbc an und lässt den Spieler
 *   über f_038e90 nacheinander Helden in die neue Teilgruppe verschieben.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Zeiger R * auf die neue Teilgruppe oder
 *   0 (bei Abbruch bzw. Verbot) zurück.
 * - Wichtige Variablen: Ein angeschlossener NPC (f_039040) darf weder allein in der alten Gruppe zurückbleiben
 *   noch als einziger Held eine neue Teilgruppe bilden (siehe auch den dokumentierten Originalfehler in der
 *   Fehlerliste, da am Ende f_0de7f0(p1) ohne vorherige Nullzeigerprüfung aufgerufen wird).
 === Ende Beschreibung === */
R *f_041220()
{
    short f_0dbfe0(void *);
    PL pl;
    R *p1;
    R *src;
    short s2;
    short s3;
    short flag;
    int need;
    int off;
    int h;
    int it;
    int t;
    ICH ci;
    char cnt;
    f_125400(&pl, &d_1c349c, &d_1c3870, (int)&d_1c3498);
    p1 = 0;
    h = f_039040(d_1c0004);
    need = (h != 0) + 1;
    s2 = f_0de820(d_1c0004);
    s3 = f_0de7f0(d_1c0004);
    if (s3 <= (short)need) {
        f_0bf730(&d_1c2c64, 0x20000027);
    } else if ((int)s2 == 7 || (int)s2 == 8 || (int)s2 == 9) {
            f_0bf730(&d_1c2c64, 0x2e00001f);
        } else if (s2 == 0x17 || s2 == 0x18 || s2 == 0x19) {
            pl.a[1] = f_038c40(d_1c0004);
            f_0bf730(&d_1c2c64, 0x2f000004);
        } else {
            flag = 0;
            s2 = 0;
            do {
                d_1c3870 = (d_1c3870 & 0) ? 0 : d_1c3870; // Haelt die Registervergabe im Schleifenrumpf wie im Original gleichstand
                off = s2;
                off *= 0x61;
                p1 = (R *)(d_1bfdbc + off);
                s2 = s2 + 1;
                s3 = f_0de7f0(p1);
            } while (s3 != (short)0);
            src = d_1c0004;
            p1->h = src->h;
            CPY(p1, src)
            for (s2 = 0; s2 <= 6; s2++) {
                f_0de790(p1, s2, 0);
            }
            f_0de7b0(p1, 0);
            f_0de7a0(p1, 0);
            h = f_039040(d_1c0004);
            s2 = (h) ? f_0d4a10(h) : 0;
            int remaining = need; while (f_0dbfe0(d_1c0004) >= 1 && f_0de7f0(d_1c0004) > (short)remaining) {
                if (s2 != 0) {
                    t = f_039040(d_1c0004);
                    d_1a9670 = f_0dc020(d_1c0004, t);
                }
                it = f_038e90(d_1c0004, 0x20000028);
                if (it == 0) break;
                if (f_0d4a10(it) == 0 || (f_0db970(d_1c0004) - s2 != 1)) {
                    flag = 1;
                    s3 = f_0dc020(d_1c0004, it);
                    f_0dcdf0(d_1c0004, s3);
                    s3 = f_0dcc10(p1);
                    f_0dcc40(p1, it, s3);
                }
            }
            if (flag) f_0bbf00(&d_1bf230);
        }
#if FIX_R012   /* R012: Nullzeiger-Dereferenzierung auf p1 vermeiden, wenn Gruppenteilung abgelehnt wurde */
    s2 = p1 ? f_0de7f0(p1) : 0;
#else
    s2 = f_0de7f0(p1);
#endif
    if (s2 <= 0) p1 = 0;
    ci = 0;
    cnt = 0;
    do {
        s2 = f_0de7f0(d_1bfdbc + ci * 0x61);
        if (0 < s2) cnt = cnt + 1;
        ci = ci + 1;
    } while (ci < 6);
    d_1c0028 = cnt;
    f_1254a0(&pl, 0);
    return p1;
}
//@ f_041530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt das Wiedervereinigen getrennter Teilgruppen ("Gruppen zusammenlegen") am
 *   selben Ort durch. Sie sucht über f_0cda50 nach benachbarten Teilgruppen, überträgt deren sämtliche Helden
 *   zurück in die aktive Hauptgruppe d_1c0004 und aktualisiert die Teilgruppenanzahl d_1c0028.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und hat keinen Rückgabewert.
 * - Wichtige Variablen: Befindet sich keine zweite Teilgruppe in Reichweite (s == -1), gibt die Funktion die
 *   Meldung 0x20000029 aus.
 === Ende Beschreibung === */
void f_041530()
{
    short s;
    int p2;
    ICH ci;
    char cnt;
    char *c;
    int h;
    s = f_0cda50();
    if (s == -1) {
        f_0bf730(&d_1c2c64, 0x20000029);
    } else {
        do {
            c = d_1bfdbc + s * 0x61;
            s = f_0de9e0(c);
            // Haelt die Registervergabe bei Gleichstand wie im Original.
            if (s == 1) { int *q = &d_1bc8cc; *q = f_038c40(c); }
            while (f_0de7f0(c)) {
                p2 = f_038c80(c);
                s = f_0dc020(c, p2);
                f_0dcdf0(c, s);
                s = f_0dcc10(d_1c0004);
                f_0dcc40(d_1c0004, p2, s);
            }
            ci = 0;
            cnt = 0;
            do {
                s = f_0de7f0(d_1bfdbc + ci * 0x61);
                if (0 < s) cnt = cnt + 1;
                ci = ci + 1;
            } while (ci < 6);
            d_1c0028 = cnt;
            s = f_0cda50();
        } while (s != -1);
        f_0bbf00(&d_1bf230);
        f_0de990(d_1c0004, 0);
        h = f_039ac0(d_1c0004, f_040f30);
        if (h != 0) f_044060(h, 0);
    }
}
//@ f_041630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion zeigt ein Auswahlmenü mit bis zu p2 vorbereiteten Teilgruppen-Namenszeilen
 *   (d_1c29c4) an, gibt den Puffer d_1bc8e8 frei und liefert den Zeiger auf die vom Spieler gewählte Teilgruppe
 *   aus d_1bc8d0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Titel-Text-ID p1, die Anzahl der Teilgruppen p2 (short) und
 *   den vorherigen Dialogmodus p3 (short) und gibt den gewählten Gruppenzeiger d_1bc8d0[r] oder 0 zurück.
 * - Wichtige Variablen: Bricht der Spieler den Dialog per Rechtsklick ab (r == -2), wählt die Funktion
 *   standardmäßig den letzten Eintrag (p2 - 1).
 === Ende Beschreibung === */
int f_041630(int p1, short p2, short p3)
{
    short r = -1;
    d_1a9670 = 0xff;
    if (p2 != (short)0) {
        r = f_0bf820(&d_1c2c64, p1, p2, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]) - 1;
        if (r == -2) r = p2 - 1;
    }
    f_0c0020(&d_1c2c64, p3);
    delete d_1bc8e8;
    if (r == -1) return 0;
    return d_1bc8d0[r];
}
//@ f_0416d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion baut für die Teilgruppe p1 (Listenindex p2) eine Beschreibungszeile im Puffer
 *   d_1bc8e8 + p2 * 100 auf, die die Gruppennummer und die durch Kommas getrennten Namen aller Helden dieser
 *   Teilgruppe enthält, und trägt den formatierten String in d_1c29c4[p2] für das Auswahlmenü f_041630 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Teilgruppenzeiger p1 (void *) und den Menüindex p2 (short)
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Schleife durchläuft alle Helden der Teilgruppe zyklisch über f_0391b0(p1, h), bis
 *   wieder der erste Held f_038c80(p1) erreicht ist.
 === Ende Beschreibung === */
void f_0416d0(void *p1, short p2)
{
    PL pl;
    char *name;
    int h;

    char *s; short cnt;
    f_125400(&pl, &d_1c349c, &d_1c3870, (int)&d_1c3498);
    name = d_1bc8e8 + p2 * 100;
    pl.c[1] = p2 + 1;
    f_0e93f0(&d_1c38b0, name, 0x20000192);
    h = f_038c80((*&p1));
    cnt = 0;
    do {
        if (cnt) f_0e9300(&d_1c38b0, name, 0x20000193);
        // Haelt die Registervergabe im Schleifenrumpf wie im Original
        d_1c3870 = (d_1c3870 & 0) ? 0 : d_1c3870; s = f_0422b0((struct hero *)(h)); strcat(name, s);

        h = f_0391b0(p1, h);
        cnt = cnt + 1;
    } while (h != f_038c80(p1));
    f_0e9300(&d_1c38b0, name, 0x20000196);
    d_1c29c4[p2] = f_133fe0(&d_1c3498, name);
    f_1254a0(&pl, 0);
}
