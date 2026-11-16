/* === Beschreibung (Katalog) ===
 * Einheit gz_0fa9b0 (0fa9b0 - 0fb660)
 *
 * Überblick
 *
 * Die Einheit gz_0fa9b0 bildet den Abschluss des dritten Kanalisationsmoduls (sewerag3). Sie enthält die
 * Routinen für das Rosten von Metallwaffen und Rüstungen beim Durchschwimmen überfluteter Kanäle (f_0fa9b0,
 * f_0faa10), eine Hilfsfunktion zum Benutzen der Rattenfänger-Flöte (f_0fab50), den Ortswechsel zurück in den
 * ersten Kanalisationsabschnitt (f_0fab80) sowie den Destruktor-Wrapper und zwei kleine Hilfsmethoden (f_0faba0
 * bis f_0fabf0).
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 6/7 gleich (suche.py 24.10.2026, Basis gz_0fa9b0_P1.CPP)
// gz_0fa9b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FA9B0-0x0FAC10
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb708;                    // 0x1BB708
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern unsigned short d_1c21b4[];
extern int d_1c3498;
short f_0398c0(int p1, int p2, int p3);
short f_0db9a0(int p1);
short f_0d54f0(int p1, int p2);
int f_041030(int, ...);
int f_1254a0(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
void f_0f7120(void);
void f_0f7160(void);
void f_0faa10(int p1, int p2);
typedef RivaTextContextData OB;
struct Q { short a; short b; char c; int d; };

//@ f_0fabe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Abfragemethode gibt konstant 1 zurück, um das Kanalisationsmodul als aktives
 *   Untergrundgebiet zu kennzeichnen.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0fabe0(void)
{
    return 1;
}
//@ f_0fabf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode setzt die vier Felder (a, b, c, d) einer 10-Byte-Zustandsstruktur Q auf 0 zurück.
 * - Eingaben: Die Funktion erhält den Zeiger p auf die zu initialisierende Struktur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fabf0(Q *p)
{
    p->d = 0;
    p->c = 0;
    p->a = 0;
    p->b = 0;
}
