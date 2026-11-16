/* === Beschreibung (Katalog) ===
 * Einheit gz_0add30 (0x0ADD30 - 0x0ADDE0)
 *
 * Diese Einheit enthält die Abschlussfunktionen des deutschen Sprachmoduls (LANG_GER.CPP) für die
 * deklinationsabhängige Satz-Token-Ersetzung und die Sprachkennung.
 === Ende Beschreibung === */
// P1 2/2 gleich
// gz_0add30.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ADD30-0x0ADDE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
char f_0b04e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1b7ec0[];           // Text 0x1B7EC0
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct F6 { unsigned char a:2; unsigned char k:3; unsigned char b:3; };
#define K6(v) (((struct F6 *)&(v))->k)
//@ f_0add30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst im deutschen Sprachmodul mehrteilige, durch Punkte getrennte Wort- und Adjektivvorlagen
 *   (p4) in den Ausgabepuffern p2 und p3 auf: Sie schreibt bei vorhandenem Zweitpuffer p3 im Genitiv (K6(p6) ==
 *   1) den zweiten Teilstring hinein (sonst Leerstring) und wählt für den Hauptpuffer p2 je nach Artikelstatus
 *   (f_0b04e0), Kasus und Numerus (p5) die erste, zweite oder dritte Punkt-Variante über f_0b0460.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (p1), der Haupt-Ausgabepuffer (p2), ein
 *   optionaler Zweitpuffer (p3), der Vorlagenstring (p4), der Numerus bzw. die Anzahl (p5), das Kasus-Bitfeld
 *   (p6) sowie ein ungenutzter Parameter (p7).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0add30(int p1, int p2, char *p3, int p4, short p5, unsigned char p6, int p7)
{
  int k;
  if (p3) {
    if (K6(p6) == 1) f_0b0460((int)p3, p4, 2);
    else *p3 = 0;
  }
  if (f_0b04e0(p1) == 1 && K6(p6) == 3 && p5 <= 1) f_0b0460(p2, p4, 3);
  else if (p5 > 1) f_0b0460(p2, p4, 2);
  else f_0b0460(p2, p4, 1);
}
//@ f_0addd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den Namen der Sprache des deutschen Sprachmoduls ("Deutsch" bei d_1b7ec0) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Deutsch" zurück.
 === Ende Beschreibung === */
char *f_0addd0(void)
{
  return (char *)d_1b7ec0;
}
