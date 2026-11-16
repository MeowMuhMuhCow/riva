/* === Beschreibung (Katalog) ===
 * Einheit gz_0d9cb0 (0d9cb0 - 0d9d20)
 *
 * Überblick
 * Die kleine Einheit gz_0d9cb0 gehört zum Übergangsbereich hinter options.cpp und implementiert eine
 * Timer-gestützte Warteschleife über den Sound-/Timer-Dienst (d_1c2edc), deren Dauer über die globale
 * Geschwindigkeitsoption d_1bfb0c gesteuert wird.
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 24.10.2026, Basis gz_0d9cb0_P1.CPP)
// gz_0d9cb0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D9CB0-0x0D9D20
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147b97(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147c02(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1bfb0c;

extern int d_1bfdb4;

extern int d_1c2edc;                    // 0x1C2EDC
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


//@ f_0d9cb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Erhöht als periodische Timer-Rückruffunktion bei jedem Timer-Tick den globalen Wartezähler d_1bfdb4
 *   um 1.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9cb0(void)
{
    d_1bfdb4++;
}
//@ f_0d9cc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Registriert die Zählfunktion f_0d9cb0 über f_147b97 als Timer-Ereignis am Sound-/Timer-System
 *   d_1c2edc, wartet in einer Schleife unter Aufruf von f_146dfa, bis d_1bfdb4 den eingestellten
 *   Verzögerungswert d_1bfb0c erreicht hat, und meldet den Timer anschließend über f_147c02 wieder ab.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9cc0(void)
{
    int h;
    signed char c;
    d_1bfdb4 = 0;
    h = f_147b97((int)&d_1c2edc, 1, (int)f_0d9cb0);
    do {
        f_146dfa((int)&d_1c2edc, 1);
        c = d_1bfb0c;
        if (c == d_1bfdb4) break;
    } while (1);
    f_147c02((int)&d_1c2edc, h);
}
