/* === Beschreibung (Katalog) ===
 * Einheit gz_0acac0 (0x0ACAC0 - 0x0ACB00)
 *
 * Diese Einheit enthält ausgelagerte Hilfsfunktionen des dänischen Sprachmoduls (lang_dan.cpp) für
 * numerusabhängige Satz-Token-Auswahl und Sprachkennung.
 === Ende Beschreibung === */
// P1 2/2 gleich
// gz_0acac0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ACAC0-0x0ACB00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1b7df9;                    // 0x1B7DF9
//@ f_0acac0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wählt in einem mit Punkten getrennten Grammatik-Teilstring (p4) je nach Anzahl (p5 <= 1 für
 *   Singular-Modus 1, p5 > 1 für Plural-Modus 2) die passende Wortform über f_0b0460 aus und schreibt sie in den
 *   Zielpuffer (p2).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), ein ungenutzter
 *   Zweitpuffer (p3), der Quell-Vorlagenstring (p4), die Anzahl bzw. der Numerus (p5) sowie zwei weitere
 *   ungenutzte Parameter (p6, p7).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0b0460 (1 bei gefundenem Trennpunkt, sonst 0) zurück.
 === Ende Beschreibung === */
int f_0acac0(int p1, int p2, int p3, int p4, short p5, int p6, int p7)
{
    int k;
    if (p5 > 1) return f_0b0460(p2, p4, 2); else return f_0b0460(p2, p4, 1);
}
//@ f_0acaf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den deutschen Namen der Sprache dieses Moduls ("Dänisch" bei d_1b7df9) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Dänisch" zurück.
 === Ende Beschreibung === */
const char *f_0acaf0(void)
{
    return (const char *)&d_1b7df9;
}
