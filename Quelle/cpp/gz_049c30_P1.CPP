/* === Beschreibung (Katalog) ===
 * Einheit gz_049c30 (0x049c30 - 0x049da0)
 *
 * Überblick
 * Die Einheit gz_049c30 bildet den Abschluss des Stadt-Riva-Moduls (cityriva): Sie enthält die Auswertung
 * abgeschlossener Stadtkämpfe (insbesondere des Kampfes 0x120016 mit Belohnung, Zeitfortschritt und
 * Beuteübergabe) sowie den virtuellen Destruktor des Stadt-Steuerobjekts.
 === Ende Beschreibung === */
// P3 2/2 gleich (suche.py 24.10.2026, Basis gz_049c30_P1.CPP)
// gz_049c30.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x049C30-0x049DA0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bad44;                    // 0x1BAD44
extern int d_1bc924;                    // 0x1BC924
extern char d_1bca88;                    // 0x1BCA88
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
short f_0dbfe0(int p1);
extern int d_1c3498;
#define A(x) ((int)&x)
struct Q { int a; int b; };
struct L { int x; Q *q; char rest[0x34]; };
//@ f_049c30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft nach einem Ereignis oder Kampf in Riva das globale Kampfergebnis-Flag d_1bc924: War der
 *   Kampf 0x120016 erfolgreich, markiert die Funktion den Gegner als besiegt (f_060800), gibt je nach
 *   Gruppengröße die Siegesmeldungen 0x22010067/0x22010068 bis 0x2201006a aus, lässt 4 Stunden vergehen
 *   (f_125f70), übergibt der Gruppe die Gegenstände 0x16c (1x) und 0x92 (3x) sowie 2000 Heller (f_0db820) und
 *   setzt das Quest-Flag d_1bca88 = 1; auch die Kämpfe 0x120014 und 0x120018 werden als erledigt markiert.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest und löscht d_1bc924, setzt d_1bca88 = 1 und belohnt die aktive Gruppe d_1c0004.
 === Ende Beschreibung === */
void f_049c30(void)
{
    L loc;
    if (d_1bc924 != 0) {
        f_125400((int)&loc, A(d_1c349c), A(d_1c3870), A(d_1c3498));
        if (d_1bc924 == 0x120016) {
            loc.q->b = f_038c40(d_1c0004);
            f_060800(d_1bc924, 1, 0);
            if (f_0dbfe0(d_1c0004) > 1) f_0bf730(A(d_1c2c64), 0x22010067); else f_0bf730(A(d_1c2c64), 0x22010068);
            f_0bf730(A(d_1c2c64), 0x22010069);
            f_125f70(A(d_1c2c44), 4);
            f_0bf730(A(d_1c2c64), 0x2201006a);
            f_0dd1d0(d_1c0004, 0x16c);
            f_0dcf00(d_1c0004, 0x92, 3);
            f_0db820(d_1c0004, 2000);
            d_1bca88 = 1;
        }
        if (d_1bc924 == 0x120014 || d_1bc924 == 0x120018) {
            f_060800(d_1bc924, 1, 0);
        }
        d_1bc924 = 0;
        f_1254a0((int)&loc, 0);
    }
}
//@ f_049d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut als virtueller Destruktor das Stadt-Riva-Steuerobjekt (p1) über den
 *   Basisklassen-Destruktor f_060030 wieder ab und gibt bei gesetztem Bit 2 in p2 den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p1) sowie die Destruktor-Flags (p2) und gibt p1
 *   zurück.
 * - Wichtige Variablen: Prüft die Destruktor-Flags p2 & 4 und p2 & 2.
 === Ende Beschreibung === */
int f_145234(int p1, int p2);
void f_145254(int p1);
int f_049d60(int p1, unsigned p2)
{
    if (p2 & 4) {
        f_145254(f_145234(p1, A(d_1bad44)));
        return p1;
    }
    int r = f_060030(p1, 1);
    if (p2 & 2) operator delete((void *)r);
    return r;
}
