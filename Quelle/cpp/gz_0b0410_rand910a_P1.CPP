/* === Beschreibung (Katalog) ===
 * Einheit gz_0b0410_rand910a (0x0B0410 - 0x0B0460)
 *
 * Diese Einheit enthält die Abschlussfunktionen des englischen Sprachmoduls (LANG_US.CPP, f_0b0410 bis f_0b0450)
 * sowie Vorwärtsdeklarationen der Basisklasse language (f_0b0460 bis f_0b04f0).
 === Ende Beschreibung === */
// P1 6/7 gleich
// gz_0b0410.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B0410-0x0B0530
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern char d_1b81a4;                    // 0x1B81A4
extern char d_1b81a7;                    // 0x1B81A7
// --- eigene Funktionen (7), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_0b0460(signed char *p1, signed char *p2, short p3);
//@ f_0b0410
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wählt im englischen Sprachmodul aus einem mit Punkten getrennten Vorlagenstring (p4) je nach
 *   Anzahl (p5 <= 1 für Singular-Modus 1, p5 > 1 für Plural-Modus 2) den passenden Teilstring über f_0b0460 aus
 *   und schreibt ihn in den Zielpuffer (p2).
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), der Zielpuffer (p2), ein
 *   ungenutzter Zweitpuffer (p3), der Vorlagenstring (p4), die Anzahl (p5) sowie zwei ungenutzte Parameter (p6,
 *   p7).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0b0460 zurück.
 === Ende Beschreibung === */
int f_0b0410(int p1, int p2, int p3, int p4, short p5, int p6, int p7)
{
    if (p5 > 1) return f_0b0460((signed char *)p2, (signed char *)p4, 2);
    else return f_0b0460((signed char *)p2, (signed char *)p4, 1);
}
//@ f_0b0440
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert die Sprachkennung für britisches Englisch ("UK" bei d_1b81a4) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "UK" zurück.
 === Ende Beschreibung === */
char *f_0b0440(void) { return &d_1b81a4; }
//@ f_0b0450
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert die Sprachkennung für amerikanisches Englisch ("US" bei d_1b81a7) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "US" zurück.
 === Ende Beschreibung === */
char *f_0b0450(void) { return &d_1b81a7; }
//@ f_0b0460
/* === Beschreibung (Katalog) ===
 * - f_0b0460: Diese Funktion zerlegt einen durch Punkte '.' getrennten Stamm- und Endungs-Vorlagenstring und
 *   kopiert den Wortstamm samt gewählter Endungsvariante in den Zielpuffer.
 * - f_0b04d0: Diese Funktion schreibt das Status- und Modusbyte des Sprachmoduls.
 * - f_0b04e0: Diese Funktion liest die unteren 4 Bits des Status- und Modusbytes des Sprachmoduls.
 * - f_0b04f0: Diese Funktion liest die oberen 4 Bits des Status- und Modusbytes des Sprachmoduls.
 === Ende Beschreibung === */
int f_0b0460(signed char *p1, signed char *p2, short p3)
;

//@ f_0b04d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt das kombinierte Status- und Modusbyte am Anfang des Sprachmodul-Objekts (*p = v).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul-Objekt (p) und der zu speichernde Bytewert (v).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b04d0(char *p, int v) ;
//@ f_0b04e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest die unteren 4 Bits (*p & 0x0f) des Status- und Modusbytes am Anfang des
 *   Sprachmodul-Objekts aus (z. B. den aktuellen Artikelstatus).
 * - Eingaben: Übergeben wird ein Zeiger auf das Sprachmodul-Objekt (p).
 * - Rückgabewert: Die Funktion gibt den unteren 4-Bit-Wert (0-15, unsigned char) zurück.
 === Ende Beschreibung === */
unsigned char f_0b04e0(unsigned char *p) ;
//@ f_0b04f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest die oberen 4 Bits ((*p >> 4) & 0x0f) des kombinierten Status- und Modusbytes am Anfang
 *   des Sprachmodul-Objekts (language, in dieser Teileinheit vorwärtsdeklariert und in language_rand910
 *   definiert) aus.
 * - Eingaben: Übergeben wird ein Zeiger auf das Sprachmodul-Objekt (p).
 * - Rückgabewert: Die Funktion gibt den oberen 4-Bit-Wert (0-15, unsigned char) zurück.
 * - Wichtige Variablen: *p (Status- und Modusbyte bei Offset +0x00 des Sprachmoduls).
 === Ende Beschreibung === */
unsigned char f_0b04f0(unsigned char *p) ;
