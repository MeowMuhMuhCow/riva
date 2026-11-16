/* === Beschreibung (Katalog) ===
 * Einheit gz_091ea0 (091ea0 - 091f70)
 *
 * Überblick
 * Die Einheit gz_091ea0 enthält die Initialisierungsfunktion f_091ea0, die beim Programmstart die drei
 * 32-Bit-Bitmasken (d_1bdb98, d_1bdba0, d_1bdba8) und den Gesamtpunktezähler (d_1bdbb0) des Spielpunktesystems
 * (gamepoin) in den globalen Spielstands-Registern anmeldet.
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 25.10.2026, Basis gz_091ea0_P1.CPP)
// gz_091ea0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x091EA0-0x091F70
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct R6 { int a; short b; };
struct S4 { short a; short b; };
extern R6 d_1bdb98;
extern R6 d_1bdba0;
extern R6 d_1bdba8;
extern S4 d_1bdbb0;
extern void **d_1c213c;
extern short d_1c213a;
extern void **d_1c2134;
extern short d_1c2132;
//@ f_091ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt die drei Bitfeld-Variablen für bereits erreichte Spielziele (d_1bdb98 bis d_1bdba8 mit
 *   den Kennungen 3, 4 und 5) sowie den aktuellen Spielpunktestand (d_1bdbb0 mit Kennung 1) in die
 *   Spielstands-Verwaltungstabellen d_1c213a und d_1c2132 ein, damit der Fortschritt (von 1000 möglichen
 *   Spielpunkten) beim Speichern und Laden erhalten bleibt.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Registerstrukturen d_1c213a und d_1c2132 verwalten die persistenten Langwort- und
 *   Kurzwort-Variablen des Spielstands.
 === Ende Beschreibung === */
struct Reg_091ea0 { short count; void **list; };
extern Reg_091ea0 r_091ea0;
#pragma aux r_091ea0 "d_1c213a"
struct Reg2_091ea0 { short count; void **list; };
extern Reg2_091ea0 r2_091ea0;
#pragma aux r2_091ea0 "d_1c2132"
inline void add_091ea0(R6 &o, Reg_091ea0 &r, short id)
{
    o.a = 0;
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
inline void add3_091ea0(R6 &o, Reg_091ea0 &r, short id)
{
    o.a = 0;
    o.b = id;
    r.list[r.count] = &o;
}
inline void addlast_091ea0(S4 &o, Reg_091ea0 &r0, Reg2_091ea0 &r, short id)
{
    o.a = 0;
    o.b = id;
    r0.count += id;
    r.list[r.count] = &o;
    r.count++;
}
void f_091ea0(void)
{
    add_091ea0(d_1bdb98, r_091ea0, 3);
    add_091ea0(d_1bdba0, r_091ea0, 4);
    add3_091ea0(d_1bdba8, r_091ea0, 5);
    addlast_091ea0(d_1bdbb0, r_091ea0, r2_091ea0, 1);
}
