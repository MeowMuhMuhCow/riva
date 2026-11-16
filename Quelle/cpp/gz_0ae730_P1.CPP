/* === Beschreibung (Katalog) ===
 * Einheit gz_0ae730 (0x0AE730 - 0x0AE770)
 *
 * Diese Einheit enthält ausgelagerte Hilfsfunktionen des norwegischen Sprachmoduls (lang_nor.cpp) für
 * numerusabhängige Satz-Token-Auswahl und Sprachkennung.
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 23.10.2026, Basis gz_0ae730_P1.CPP)
// gz_0ae730.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AE730-0x0AE770
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1b7fa5[];           // Text 0x1B7FA5
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_0ae730
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wählt in einem mit Punkten getrennten Vorlagenstring (p4) je nach Anzahl (p5 <= 1 für
 *   Singular-Modus 1, p5 > 1 für Plural-Modus 2) den passenden Teilstring über f_0b0460 aus und schreibt ihn in
 *   den Zielpuffer (p2).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), ein ungenutzter
 *   Zweitpuffer (p3), der Vorlagenstring (p4), die Anzahl (p5) sowie zwei ungenutzte Parameter (p6, p7).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0b0460 zurück.
 === Ende Beschreibung === */
int f_0ae730(int p1, int p2, int p3, int p4, short p5, int p6, int p7)
{
    if (p5 > 1) return f_0b0460(p2, p4, 2);
    else return f_0b0460(p2, p4, 1);
}
//@ f_0ae760
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den deutschen Namen der Sprache dieses Moduls ("Norwegisch" bei d_1b7fa5) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Norwegisch" zurück.
 === Ende Beschreibung === */
char *f_0ae760(void)
{
  return (char *)d_1b7fa5;
}
