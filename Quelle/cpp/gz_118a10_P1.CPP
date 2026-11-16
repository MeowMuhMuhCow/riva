/* === Beschreibung (Katalog) ===
 * Einheit gz_118a10 (0x118a10 - 0x118a50)
 *
 * Überblick
 * Diese kleine Einheit enthält den Konstruktor und die Initialisierungs-Hilfsfunktion für das Dungeon-Objekt der
 * zweiten Ebene des Bienenstocks (star2, Dungeon-ID 8).
 === Ende Beschreibung === */
// P1 1/1 gleich
// gz_118a10.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x118A10-0x118A50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_115640(int p1, int p2);                           // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb934;                    // 0x1BB934
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_145234(int p1, int p2);
void f_145254(void);
//@ f_118a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor des Dungeon-Objekts für die zweite Ebene des Bienenstocks (star2, Dungeon-ID 8), der die
 *   Basisklasse (f_115630) initialisiert, die virtuelle Methodentabelle (d_1bb9ac) einträgt und die
 *   Rauminitialisierung f_118a50 aufruft.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_118a10(int p1, int p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)&d_1bb934);
        f_145254();
        return p1;
    }
    r = f_115640(p1, 1);
    if (p2 & 2) operator delete((void*)r);
    return r;
}
