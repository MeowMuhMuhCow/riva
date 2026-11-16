/* === Beschreibung (Katalog) ===
 * Einheit gz_0a7d00 (0x0A7D00 - 0x0A7D50)
 *
 * Diese Einheit enthält die Aufräumroutine zum Freigeben der globalen Gegenstands- und Beschreibungstabellen
 * beim Beenden oder Zurücksetzen des Spiels.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
// P3 0/1 gleich (suche.py 25.10.2026, Basis gz_0a7d00_P1.CPP)
// gz_0a7d00.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A7D00-0x0A7D50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (0), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern char *d_1be264;                  // 0x1BE264
extern char *d_1be268;                  // 0x1BE268
                  // 0x1C2C40

//@ f_0a7d00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt die drei im Heap reservierten globalen Speicherblöcke für Gegenstandsdaten - die
 *   Gegenstandsdefinitionstabelle (d_1c2c40) sowie die beiden zugehörigen Namens- und Textpuffer (d_1be264 und
 *   d_1be268) - über die Speicherverwaltung (f_014710) frei und setzt deren Zeiger auf Null zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen, sondern greift direkt auf die drei globalen
 *   Tabellenzeiger zu.
 * - Rückgabewert: Die Funktion gibt konstant 1 als Bestätigung zurück.
 === Ende Beschreibung === */
void f_014710(void *p);
#pragma aux f_014710 modify exact [eax edx];
int f_0a7d00(void)
{
    int result = 1;
    char *p;
    f_014710(d_1be264);
    p = d_1be268;
    d_1be264 = 0;
    if (p) {
        f_014710(p);
    }
    d_1be268 = 0;
    f_014710((*(char **)&d_1c2c40));
    (*(char **)&d_1c2c40) = 0;
    return result;
}
