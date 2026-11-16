/* === Beschreibung (Katalog) ===
 * Einheit gz_092ee0 (092ee0 - 092f40)
 *
 * Überblick
 * Die Einheit gz_092ee0 enthält drei kleine arithmetische und vergleichende Hilfsfunktionen (f_092ee0, f_092f00,
 * f_092f20), die von gamepoin für die Proportionaleinteilung des Fortschrittsbalkens und für das Auslesen von
 * short- und signed char-Statusvariablen genutzt werden.
 === Ende Beschreibung === */
// P1 3/3 gleich
// gz_092ee0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x092EE0-0x092F40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_092ee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den Dreisatz (p1 * p2) / p3 mit vorzeichenbehafteten 16-Bit-Eingabewerten, unter
 *   anderem zur Umrechnung des Spielpunktestands in Prozent- und Pixelhöhen der Fortschrittssäule.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zählerwert p1, den Multiplikator p2 sowie den Teiler p3 und
 *   gibt das ganzzahlige Divisionsergebnis als int zurück.
 * - Wichtige Variablen: Alle drei Parameter werden vor der Multiplikation und Division auf short gecastet.
 === Ende Beschreibung === */
int f_092ee0(int p1, int p2, int p3)
{
    return ((int)(short)p1 * (int)(short)p2) / (int)(short)p3;
}
//@ f_092f00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der 16-Bit-Wert an der Adresse p1 (z. B. der Spielpunktestand d_1bdbb0) größer als
 *   der Schwellenwert p2 (z. B. 1000) ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p1 (short *) und den Vergleichswert p2 entgegen und
 *   gibt 1 zurück, wenn *p1 > (short)p2 gilt, sonst 0.
 * - Wichtige Variablen: Es werden nur der übergebene Zeiger p1 und der Schwellenwert p2 ausgewertet.
 === Ende Beschreibung === */
int f_092f00(short *p1, int p2)
{
    int t = *p1; return t > (short)p2;
}
//@ f_092f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das vorzeichenbehaftete Byte an der Adresse p1 (z. B. ein Kapitelflag wie d_1bdcfc)
 *   größer als der Vergleichswert p2 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (signed char *) sowie den Vergleichswert p2 und
 *   gibt 1 zurück, wenn *p1 > (signed char)p2 gilt, sonst 0.
 * - Wichtige Variablen: Es werden keine globalen Variablen direkt referenziert.
 === Ende Beschreibung === */
int f_092f20(signed char *p1, int p2)
{
    int t = *p1; return t > (signed char)p2;
}
