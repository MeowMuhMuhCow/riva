/* === Beschreibung (Katalog) ===
 * Einheit ch_skill (0x03ac38 - 0x03b8d0)
 *
 * Überblick
 * Diese Einheit verwaltet die Talentwerte eines Helden sowie die direkte Anwendung von Gesellschafts- und
 * Handwerkstalenten in Tavernen und Städten. Sie enthält das Auswahlmenü der aktiv benutzbaren Talente
 * (f_03ac50), das allgemeine Talent-Auswahlmenü (f_03b5e0), die Auslese- und Änderungsfunktionen für Talentwerte
 * (f_03ad80, f_03af20, f_03af30, f_03adba inklusive der Verteilung von Waffen-Talentpunkten auf Attacke und
 * Parade) sowie die fünf Tavernen-Einkommenstalente Taschendiebstahl (f_03afe0), Akrobatik (f_03b0b0),
 * Musizieren (f_03b190), Falschspiel (f_03b400) und Gaukelei (f_03b4f0).
 === Ende Beschreibung === */
// P3 6/11 gleich (suche.py 29.10.2026, Basis ch_skill_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 1 gleich (vorher 1), Rest 863 (vorher 870)
// ch_skill.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03AC50-0x03B8D0
#include "R_FIX.H"
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
int sprintf(char *buf, const char *fmt, ...);
struct PL { int f0; int *a; int f8; int fc; int *b; short *c; char rest[0x24]; };
struct Q { int x; };
struct S6 { int x; short y; };
struct S10 { int x; int y; short z; };
short f_036ed0(int p1);
int f_040370(void *p1, int p2);
signed char f_043e30(int p1);
short f_044c90(int p1, int p2, int p3);
int f_09a040(int p1, int p2);
#pragma aux f_09a040 parm [eax edx] modify exact [eax]
int f_0bf680(void *p1, int p2);
int f_0bf6c0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
int f_0bf7b0(void *p1, int p2, int p3, int p4, int p5, int p6);
short f_0bf820();
int f_0ce650();
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1);
short f_0d4aa0(int p1, int p2);
int f_0db820(int p1, int p2);
int f_0dc2d0(int p1, int p2, void *p3, void *p4, void *p5, void *p6);
int f_0de7b0(int p1, int p2);
int f_0e93f0(void *p1, void *p2, int p3);
void f_125400(void *p1, void *p2, void *p3);
int f_1254a0(void *p1, int);
int f_133fe0(void *p1, void *p2);
short f_145760(int p1, int p2);
short f_1457e0(int p1);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
short f_149360(int p1, void *p2);
extern int d_1a0c08;
extern int d_1a0c0c;
extern char d_1a0c10;
extern int d_1a0c12;
extern int d_1a0c16;
extern int d_1a0c1a;
extern int d_1a0c1e;
extern short d_1a0c22;
extern int d_1a0c24;
extern int d_1a0c28;
extern short d_1a0c2c;
extern signed char d_1a6ba0[];
extern unsigned short d_1a9820;
extern char *d_1bc89c;
extern int d_1c0004;
extern int d_1c11e8;
extern volatile int d_1c11ec;
extern int d_1c1240;
extern short d_1c2198;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern int d_1c29c4[];
extern int d_1c2a80;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
void f_03af30(int p1, short p2, signed char p3);
//@ f_03ac50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion baut das Auswahlmenü der im aktuellen Kontext (p2) aktiv anwendbaren Talente
 *   auf (standardmäßig die drei Heilkunde-Talente 0x2c, 0x2d, 0x2e aus d_1a0c08, im Inventar-/Stadtmodus
 *   d_1c2a80 == 0x30000 ergänzt um Schätzen 0x19 sowie je nach Kontext p2 == 1..4 um Taschendiebstahl,
 *   Falschspiel, Abrichten, Akrobatik, Musizieren und Gaukelei) und lässt den Spieler eines davon auswählen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Orts-/Situationskontext p2 (short)
 *   und gibt die Talent-ID des gewählten Talents oder -1 bei Abbruch zurück.
 * - Wichtige Variablen: Das lokale Array buf[12] sammelt die bis zu neun anwendbaren Talent-IDs, deren Namen ab
 *   0x2000005c + talent_id liegen (siehe auch den dokumentierten Originalfehler in der Fehlerliste bei der
 *   doppelten Bedingung d_1c2a80 == 0x30000 || d_1c2a80 == 0x30000).
 === Ende Beschreibung === */
short f_03ac50(int p1, short p2)
{
    short __cdecl f_0bf820(void *, int, ...);
    short n;
    char buf[12];
    short r = -1;
    struct Initial { int a; int b; char c; };
    n = 3;
    *(struct Initial *)buf = *(struct Initial *)&d_1a0c08;
#if FIX_R013   /* R013: Copy-Paste-Ortspruefung d_1c2a80 == 0x30001 statt doppeltem 0x30000 */
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) {
#else
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30000) {
#endif
        buf[n++] = 0x19;
    }
    switch ((short)p2) {
    case 4:
        buf[n] = 9;
        buf[n + 1] = 0x2b;
        buf[n + 2] = 0x31;
        buf[n + 3] = 0x2f;
        buf[n + 4] = 0x10;
        n += 5;
        break;
    case 3: buf[n] = 0x20; n++; break;
    case 2: buf[n++] = 9; break;
    case 1: buf[n++] = 0x31; break;
    }
    r = f_0bf820(&d_1c2c64, 0x20000116, (short)n,
                 0x2000005c + (signed char)buf[0],
                 0x2000005c + (signed char)buf[1],
                 0x2000005c + (signed char)buf[2],
                 0x2000005c + (signed char)buf[3],
                 0x2000005c + (signed char)buf[4],
                 0x2000005c + (signed char)buf[5],
                 0x2000005c + (signed char)buf[6],
                 0x2000005c + (signed char)buf[7],
                 0x2000005c + (signed char)buf[8]);
    if (r != -1) r = (signed char)buf[r - 1];
    return r;
}
//@ f_03ad80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion gibt den aktuellen Talentwert des Helden p1 im Talent p2 (0..51) zurück und
 *   berücksichtigt beim Talent 0x0d (13 = Schleichen) einen Abzug von -1, falls der Held den hinderlichen
 *   Gegenstand 0x154 im Inventar trägt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Talentindex p2 (short) und gibt den
 *   effektiven Talentwert als signed char zurück.
 * - Wichtige Variablen: Die 52 Talentwerte eines Helden sind als signed char-Array bei Offset p1 + 0x11a
 *   gespeichert.
 === Ende Beschreibung === */
signed char f_03ad80(int p1, short p2)
{
    signed char r;
    if (p2 == 0xd && f_0d4aa0(p1, 0x154) != -1)
        r = *(signed char *)(p1 + (int)p2 + 0x11a) - 1;
    else
        r = *(signed char *)(p1 + (int)p2 + 0x11a);
    return r;
}

//@ f_03adba
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion von f_03af30 verteilt eine Änderung eines Kampftalents (skill_arg zwischen
 *   0 und 6: Waffenlos, Hiebwaffen, Stichwaffen, Schwerter, Äxte, Speere, Zweihänder) auf den Attacke-Wert
 *   (+0x7a) und den Parade-Wert (+0x81) des Helden. Ist der Held im interaktiven Modus sichtbar, fragt ein
 *   Dialog (0x200001b8) den Spieler, wie viele Punkte auf Attacke entfallen sollen (der Rest geht auf Parade);
 *   im Hintergrundmodus wird die Änderung automatisch hälftig aufgeteilt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger hero (oder 0 als Flag für automatische
 *   Verteilung), den Kampftalent-Index skill_arg (0..6) und die Differenz change_arg (signed char) und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Die sieben Attacke-Werte liegen bei hero + 0x7a..0x80 und die sieben Parade-Werte bei
 *   hero + 0x81..0x87.
 === Ende Beschreibung === */
extern "C" int abs(int);
#pragma intrinsic(abs)
void f_03adba(int hero, short skill_arg, signed char change_arg);
#pragma aux f_03adba parm [edi] [edx] [ebx]
void f_03adba(int hero, short skill_arg, signed char change_arg)
{
    int f_0bf680(void *);
    int f_0ce7e0(void *, int);
    struct PL pl;
    struct Q q;
    short skill;
    signed char change;
    signed char first, second;
    int r;
    int pb2;
    skill = skill_arg;
    change = change_arg;
    // Maske (change & 0xfe)==0 trifft 0 und 1; change==-1 wird unten nachgezogen,
    // netto identisch zu abs(change) <= 1.
    pb2 = ((change & 0xfe) == 0) ? 0x20000194 : 0x20000164;
    if (hero != 0) {
        pl.b[2] = pb2;
        pl.b[3] = change < 0 ? 0x200001b7 : 0x200001b6;
        pl.c[2] = *(signed char *)(hero + skill + 0x7a);
        pl.c[3] = *(signed char *)(hero + skill + 0x81);
        pl.b[4] = change < 0 ? 0x200001b7 : 0x200001b6;
        f_0bf6c0(&d_1c2c64, 5);
        r = f_0bf7b0(&d_1c2c64, 1, 0x200001b8, 0, (short)abs(change), (short)abs(change));
        first = (signed char)r;
        f_0bf680(&d_1c2c64);
        second = abs(change) - first;
        f_1254a0(&pl, 0);
        f_0ce7e0(&q, 0);
    } else {
        second = abs(change) / 2;
        first = second;
        if (change % 2 != 0) {
            if (f_1457e0(100) < 50) first++;
            else second++;
        }
    }
    if (change < 0) {
        *(signed char *)(hero + skill + 0x7a) -= first;
        *(signed char *)(hero + skill + 0x81) -= second;
    } else {
        *(signed char *)(hero + skill + 0x7a) += first;
        *(signed char *)(hero + skill + 0x81) += second;
    }
    if (d_1c2a80 == 0x30000) d_1c2198 = 1;
}


//@ f_03afe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt einen aktiven Taschendiebstahl-Versuch (Talent 0x31 = 49) des Helden p1
 *   in einer Taverne oder bei einer Begegnung aus. Gelingt die Talentprobe (f_044c90), erbeutet die Gruppe 500
 *   bis 1000 Heller (5 bis 10 Dukaten); misslingt sie, verliert die Gruppe zur Strafe ihr gesamtes Geld
 *   (f_0de7b0(d_1c0004, 0)) und erhält den Fehlercode -2 (Rauswurf).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Probenmodifikator p2 (short) und gibt
 *   1 bei Erfolg oder -2 bei Fehlschlag zurück.
 * - Wichtige Variablen: f_040370 formatiert den erbeuteten Geldbetrag in Dukaten, Silberlingen und Hellern für
 *   die Erfolgsmeldung 0x205001a, und f_0db820 addiert den Betrag zum Gruppenvermögen.
 === Ende Beschreibung === */
short f_03afe0(int p1, short p2)
{
    void f_125400(void *, void *, void *, void *);
    short r = 1;
    struct PL pl;
    int t;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (f_044c90(p1, 0x31, (signed char)p2) <= 0) goto fail;
    {
        int s = f_145760(500, 1000);
        f_040370(d_1c27a8, s);
        pl.b[1] = f_133fe0(&d_1c3498, d_1c27a8);
        t = 0x205001a;
        f_0db820(d_1c0004, s);
        (d_1c2198) = 1;
    }
    goto done;
fail:
    {
        t = 0x205001b;
        r = -2;
        f_0de7b0(d_1c0004, 0);
    }
done:
    f_0bf730(&d_1c2c64, t);
    f_1254a0(&pl, 0);
    return r;
}
//@ f_03b0b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt eine Akrobatik-Vorführung (Talent 0x2b = 43) in einer Taverne aus. Bei
 *   gelungener Probe verdient die Gruppe 500 bis 1000 Heller; bei einem Fehlschlag gibt die Funktion -2 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Probenmodifikator p2 (short) und gibt
 *   1 bei Erfolg oder -2 bei Misslingen zurück.
 * - Wichtige Variablen: Die Meldungs-IDs 0x2050018 (Erfolg) und 0x2050019 (Misserfolg) berichten dem Spieler
 *   über den Ausgang der Vorführung.
 === Ende Beschreibung === */
short f_03b0b0(int p1, short p2)
{
    void f_125400(void *, void *, void *, void *);
    short r = 1;
    struct PL pl;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (f_044c90(p1, 0x2b, (signed char)p2) > 0) {
        int s = f_145760(500, 1000);
        f_040370(d_1c27a8, s);
        pl.b[1] = f_133fe0(&d_1c3498, d_1c27a8);
        f_0bf730(&d_1c2c64, 0x2050018);
        f_0db820(d_1c0004, s);
        (*(volatile short *)&d_1c2198) = r;
    } else {
        r = -2;
        f_0bf730(&d_1c2c64, 0x2050019);
    }
    f_1254a0(&pl, 0);
    return r;
}
//@ f_03b190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt einen Auftritt mit dem Talent Musizieren (Talent 0x2f = 47) in einer
 *   Taverne aus. Sie prüft zunächst die Sperrzeit (d_1c11ec) sowie das Vorhandensein eines Musikinstruments im
 *   Inventar (Laute 0x25/0x160, Flöte 0x5f/0x161 oder Mandoline 0x2e aus d_1a0c12), erleichtert die Probe bei
 *   einem magischen/besonderen Instrument (d_1a0c1e) um 5 Punkte, spielt passend zu Instrument und Ausgang eine
 *   gelungene oder schiefe Musiksequenz (0x30005..0x3000a) ab und bringt bei Erfolg 100 bis 300 Heller ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Probenmodifikator p2 (short) und gibt
 *   1 bei Erfolg oder -1 bei Fehlschlag bzw. fehlendem Instrument zurück.
 * - Wichtige Variablen: Die globale Variable d_1c11ec wird nach jedem Auftritt auf 0xa8c0 (43200 Zeiteinheiten)
 *   gesetzt, damit der Held nicht unmittelbar erneut musizieren kann.
 === Ende Beschreibung === */
#pragma aux f_147323 modify exact [eax esp]
// BLIND: f_03b190 hier komplett neu aus dem Original-Assembler schreiben (orig.sh ch_skill f_03b190).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
struct BL12 { int a; int b; int c; };
struct BL6 { int a; short b; };
short f_03b190(int p1, short p2)
{
    void f_125400(void *, void *, void *, void *);
    short r = 1;
    struct PL pl;
    struct BL12 v30 = *(struct BL12 *)&d_1a0c12;
    struct BL6 v24 = *(struct BL6 *)&d_1a0c1e;
    int msg;
    unsigned short v8;
    short v14;
    short v10;
    short n;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (d_1c11ec > 0) {
        f_0bf730(&d_1c2c64, 0x2050017);
        goto done;
    }
    if (f_0dc2d0(d_1c0004, p1, &v30, &v10, &v14, &v8) == 0) {
        f_0bf730(&d_1c2c64, 0x205001c);
        r = -1;
        goto done;
    }
    if (f_149360((short)v8, &v24) != -1) p2 -= 5;
    if (f_044c90(p1, 0x2f, (signed char)p2) <= 0) r = -1;
    d_1c11ec = 0xa8c0;
    switch (v8) {
    case 0xffff:
        n = 7;
        break;
    case 0x25:
    case 0x160:
        n = (r == -1) ? 4 : 3;
        break;
    case 0x5f:
    case 0x161:
        n = (r == -1) ? 6 : 5;
        break;
    case 0x2e:
        n = (r == -1) ? 2 : 1;
        break;
    default:
        n = 0;
        break;
    }
    if (n >= 1 && n <= 6) {
        switch (n) {
        case 1: msg = 0x30005; break;
        case 2: msg = 0x30006; break;
        case 3: msg = 0x30007; break;
        case 4: msg = 0x30008; break;
        case 5: msg = 0x30009; break;
        case 6: msg = 0x3000a; break;
        }
        { unsigned short *qh7 = &d_1a9820; f_147323(&d_1c2edc, msg, 0x7fff, 0x8000, *(volatile int *)&(*qh7), 0, 1); } // Erzwingt direkte Speicherladung mov eax,ds:d_1a9820
        f_0ce650();
    }
    if (r != -1) {
        int s = f_145760(100, 300);
        f_040370(d_1c27a8, s);
        pl.b[1] = f_133fe0(&d_1c3498, d_1c27a8);
        f_0bf730(&d_1c2c64, 0x2050015);
        f_0db820(d_1c0004, s);
        (d_1c2198) = 1;
    } else {
        f_0bf730(&d_1c2c64, 0x2050016);
    }
done:
    f_1254a0(&pl, 0);
    return r;
}

//@ f_03b400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt einen Falschspiel-Versuch (Talent 9) in einer Taverne aus. Sofern die
 *   Sperrzeit d_1c11e8 abgelaufen ist, würfelt sie eine Talentprobe auf Falschspiel aus, schreibt bei Erfolg 10
 *   bis 200 Heller gut und setzt die Sperrzeit d_1c11e8 = 0xa8c0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Probenmodifikator p2 (short) und gibt
 *   1 bei Erfolg (oder aktiver Sperrzeit) bzw. -1 bei ertapptem Falschspiel zurück.
 * - Wichtige Variablen: d_1c11e8 ist der Cooldown-Timer für Falschspiel.
 === Ende Beschreibung === */
short f_03b400(int p1, short p2)
{
    void f_125400(void *, void *, void *, void *);
    short r = 1;
    int s;
    struct PL pl;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (*(volatile int *)&d_1c11e8 > 0) {
        f_0bf730(&d_1c2c64, 0x2050014);
    } else {
        s = f_044c90(p1, 9, (signed char)p2);
        if (s > 0) {
            s = f_145760(10, 200);
            f_040370(d_1c27a8, s);
            pl.b[1] = f_133fe0(&d_1c3498, d_1c27a8);
            f_0bf730(&d_1c2c64, 0x2050015);
            f_0db820(d_1c0004, s);
            (*(volatile short *)&d_1c2198) = r;
        } else {
            r = -1;
            f_0bf730(&d_1c2c64, 0x2050016);
        }
        d_1c11e8 = 0xa8c0;
    }
    f_1254a0(&pl, 0);
    return r;
}
//@ f_03b4f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt eine Gaukelei-Vorführung (Menü-Option 0x10) in einer Taverne aus, prüft
 *   und setzt den Cooldown-Timer d_1c1240 = 0xa8c0 und bringt bei gelungener Probe 100 bis 300 Heller ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Probenmodifikator p2 (short) und gibt
 *   1 bei Erfolg oder -1 bei Fehlschlag zurück.
 * - Wichtige Variablen: d_1c1240 ist der Cooldown-Timer für Gaukelei; beim Aufruf von f_044c90 wurde im
 *   Originalcode versehentlich die Talent-ID 0x2f (Musizieren) statt 0x10 (Gaukelei) übergeben (siehe
 *   Fehlerliste).
 === Ende Beschreibung === */
short f_03b4f0(int p1, short p2)
{
    void f_125400(void *, void *, void *, void *);
    short r = 1;
    struct PL pl;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (*(volatile int *)&d_1c1240 > 0) {
        f_0bf730(&d_1c2c64, 0x2050014);
    } else {
        if (f_044c90(p1, 0x2f, (signed char)p2) > 0) {
            int s = f_145760(100, 300);
            f_040370(d_1c27a8, s);
            pl.b[1] = f_133fe0(&d_1c3498, d_1c27a8);
            f_0bf730(&d_1c2c64, 0x2050015);
            f_0db820(d_1c0004, s);
            (*(volatile short *)&d_1c2198) = r;
        } else {
            r = -1;
            f_0bf730(&d_1c2c64, 0x2050016);
        }
        d_1c1240 = 0xa8c0;
    }
    f_1254a0(&pl, 0);
    return r;
}
//@ f_03b5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zeigt das zweistufige Talent-Auswahlmenü eines Helden an (zuerst Wahl einer der
 *   sieben Talentgruppen Kampf, Körper, Gesellschaft, Natur, Wissen, Handwerk, Intuition, danach Wahl des
 *   konkreten Talents). Im Stufenaufstiegsmodus (p2 == 1) zeigt sie hinter jedem Talentnamen den aktuellen Wert
 *   und markiert bereits gesteigerte oder gesperrte Talente farbig.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Modus p2 (1 = Stufenaufstieg mit
 *   Werten und Farben, 0 = einfache Talentauswahl) und gibt den ausgewählten Talentindex (0..51), -1 (Rückkehr
 *   aus Untermenü) oder -2 (Abbruch im Hauptmenü) zurück.
 * - Wichtige Variablen: Die Tabelle d_1a6ba0 enthält für jede der sieben Talentkategorien den Startindex und die
 *   Anzahl der zugehörigen Talente.
 === Ende Beschreibung === */
short f_03b5e0(int p1, short p2)
{
    unsigned char f_09a040(int);
    void f_125400(void *, void *, void *, void *);
    short __cdecl f_0bf820(void *, int, ...);
    // Getter wie in der Demo; die negierte Oder-Form haelt die Indexkonversion vor der Adresse.
    struct Getter {
        char padding[0x11a];
        signed char skills[0x34];
        int get(short index) {
            signed char result;
            if (!(index != 13 || f_0d4aa0((int)this, 0x154) == -1))
                result = *(signed char *)((int)this + (int)index + 0x11a) - 1;
            else
                result = *(signed char *)((int)this + (int)index + 0x11a);
            return result;
        }
    };
    // Word-Zwischenwert vor f_036ed0 bestimmt die Stapelreihenfolge
    struct Extend {
        static short get(short x) { return x; }
    };
    // Deklarationsreihenfolge fuer die Register- und Stapelplatzvergabe
    struct PL pl;
    int title;
    signed char ch;
    short i;
    short r = -1;
    struct S10 fmt = *(S10 *)&d_1a0c24;
    short s2 = 0;
    short base;
    ch = f_09a040(0xff);
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    pl.a[1] = p1;
    if (p2) {
        pl.b[1] = *(unsigned char *)(p1 + 0x14e) > 1 ? 0x20000114 : 0x20000113;
        pl.c[1] = *(unsigned char *)(p1 + 0x14e);
        pl.b[2] = *(unsigned char *)(p1 + 0x14e) > 1 ? 0x20000112 : 0x20000111;
        title = 0x20000110;
    } else title = 0x20000115;
    s2 = f_0bf820(&d_1c2c64, title, 7,
                 0x20000090, 0x20000091, 0x20000092, 0x20000095,
                 0x20000093, 0x20000094, 0x20000096);
    s2 = s2 - 1;
    if (s2 != -2) {
        base = d_1a6ba0[s2 * 2];
        for (i = 0; i < d_1a6ba0[s2 * 2 + 1]; i++) {
            r = (r & 0) ? 0 : r; // Haelt die Registerbelegung in der Schleife
            if (p2) {
                ch = f_09a040(0xff);
                if (f_036ed0(Extend::get((short)(base + i))) <= (signed char)d_1bc89c[(base + i) * 2 + 1] || (signed char)d_1bc89c[(base + i) * 2] == 3) {
                    ch = (ch & 0) ? 0 : ch; // Haelt ch im selben Registerweb
                    ch = f_09a040(0xfd);
                } else if ((signed char)d_1bc89c[(base + i) * 2 + 1] != 0) {
                    ch = f_09a040(0xfc);
                }
                f_0e93f0(&d_1c38b0, d_1c27a8, base + 0x2000005c + i);
                sprintf(d_1c21b4 + i * 0x32, (char *)&fmt, d_1c27a8, ch,
                    ((Getter *)p1)->get(base + i),
                    f_09a040(0xff));
                d_1c29c4[i] = f_133fe0(&d_1c3498, d_1c21b4 + i * 0x32);
            } else {
                d_1c29c4[i] = base + 0x2000005cu + i;
            }
        }
        r = f_0bf820(&d_1c2c64, 0x20000116, d_1a6ba0[s2 * 2 + 1],
            d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3],
            d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
            d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11],
            d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15]);
        if (r != -1) r = base - 1 + r;
    } else r = -2;
    f_1254a0(&pl, 0);
    return r;
}

//@ f_03af20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion verändert den Talentwert des Helden p1 im Talent p2 relativ um die Differenz p3
 *   (signed char) und ruft dazu f_03af30 mit dem neuen Zielwert auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Talentindex p2 (short) und die Änderung
 *   p3 (signed char) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gelesen wird der bisherige Talentwert aus *(signed char *)(p1 + p2 + 0x11a).
 === Ende Beschreibung === */
void f_03af20(int p1, short p2, signed char p3)
{
    f_03af30(p1, p2, p3 + *(signed char *)(p1 + p2 + 0x11a));
}

//@ f_03af30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion setzt den Talentwert des Helden p1 im Talent p2 absolut auf den neuen Wert p3
 *   und ruft bei Kampftalenten (p2 <= 6), sofern sich der Wert geändert hat, die Aufteilungsfunktion f_03adba
 *   für Attacke und Parade auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Talentindex p2 (short) und den neuen
 *   Talentwert p3 (signed char) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ist das Stumm-Flag f_043e30(p1) nicht gesetzt, bereitet die Funktion vor dem Aufruf von
 *   f_03adba den Nachrichtenkontext pl mit dem Namen des Kampftalents (0x2000005c + skill) und der Punktzahl
 *   vor.
 === Ende Beschreibung === */
extern "C" int abs(int);
#pragma intrinsic(abs)
void f_03adba(int, short, signed char);
void f_03af30(int p1, short p2, signed char p3)
{
    void f_125400(void *, void *, void *, void *);
    struct PL pl;
    struct Q q;
    volatile short skill;
    signed char change;

    skill = p2;
    change = (signed char)(p3 - *(signed char *)(p1 + p2 + 0x11a));
    *(signed char *)(p1 + p2 + 0x11a) = p3;
    if (change == 0) return;
    if (p2 > 6) return;
    if (f_043e30(p1) == 0) {
        f_0ce7c0(&q);
        f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
        pl.b[1] = 0x2000005c + skill;
        pl.a[1] = p1;
        pl.c[1] = abs(change);
        pl.b[2] = abs(change) > 1 ? 0x20000164 : 0x20000194;
    }
    f_03adba(p1, skill, change); // Fortsetzung im eigenen Einsprungpunkt 0x03ADBA
}




