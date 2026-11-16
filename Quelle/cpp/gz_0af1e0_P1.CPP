/* === Beschreibung (Katalog) ===
 * Einheit gz_0af1e0 (0x0AF1E0 - 0x0AF220)
 *
 * Diese Einheit enthält ausgelagerte Hilfsfunktionen des spanischen Sprachmoduls (lang_spa.cpp) für
 * Satz-Token-Verarbeitung und Sprachkennung.
 === Ende Beschreibung === */
// P1 2/2 gleich
// gz_0af1e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AF1E0-0x0AF220
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1b7ff3[];           // Text 0x1B7FF3
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

//@ f_0af1e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wendet die Platzhalter-Ersetzungsfunktion der Sprach-Engine (f_0b0460) auf den ersten
 *   Textpuffer (p2, Modus 1) und - sofern vorhanden - auch auf den zweiten Textpuffer (p3, Modus 2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), zwei Textpuffer-Zeiger (p2, p3),
 *   der Vorlagenstring (p4) sowie drei ungenutzte Zusatzparameter (p5-p7).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0af1e0(int p1, int p2, int p3, int p4, int p5, int p6, int p7)
{
  f_0b0460(p2, p4, 1);
  if (p3) {
    f_0b0460(p3, p4, 2);
  }
}
//@ f_0af210
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den englischen Namen der Sprache dieses Moduls ("Spanish" bei d_1b7ff3) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Spanish" zurück.
 === Ende Beschreibung === */
const char *f_0af210(void)
{
  return d_1b7ff3;
}
