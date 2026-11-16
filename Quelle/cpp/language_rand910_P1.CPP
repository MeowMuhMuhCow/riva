/* === Beschreibung (Katalog) ===
 * Einheit language_rand910 (0x0B0460 - 0x0B05F0)
 *
 * Diese Einheit enthält die Basisklasse und die Fabrikmethode des mehrsprachigen Grammatiksystems
 * (p:\riva\source\cpp\language.cpp).
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
//@ f_0b0460
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zerlegt einen durch Punkte '.' getrennten Flexions-Vorlagenstring (p2, z. B.
 *   "Wortstamm.Endung1.Endung2"): Sie kopiert zunächst den Wortstamm bis zum ersten Punkt in den Zielpuffer
 *   (p1), überspringt dann entsprechend dem Variantenindex (p3) die vorangehenden Punkte und hängt die
 *   ausgewählte Endung bis zum nächsten Punkt an den Wortstamm an.
 * - Eingaben: Übergeben werden der Ziel-Zeichenpuffer (p1), der mit Punkten getrennte Quell-Vorlagenstring (p2)
 *   und der 1-basierte Index der gewünschten Endungsvariante (p3).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die angeforderte Punkt-Endung im Vorlagenstring gefunden
 *   wurde, und sonst 0.
 === Ende Beschreibung === */
int f_0b0460(signed char *p1, signed char *p2, short p3)
{
    int r = 0;
    signed char *s = p2, *d = p1;
    for (; *s != 0 && (char)*s != '.'; ) *d++ = *s++;
    while (p3 > 1 && *s != 0) { s++; if ((char)*s == '.') p3--; }
    if ((char)*s == '.') { r = 1; s++; while (*s != 0 && (char)*s != '.') *d++ = *s++; }
    *d = 0;
    return r;
}

//@ f_0b04d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt das kombinierte Status- und Modusbyte am Anfang des Sprachmodul-Objekts (*p = v).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul-Objekt (p) und der zu speichernde Bytewert (v).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b04d0(char *p, int v) { *p = v; }
//@ f_0b04e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest die unteren 4 Bits (*p & 0x0f) des Status- und Modusbytes am Anfang des
 *   Sprachmodul-Objekts aus (z. B. den aktuellen Artikelstatus).
 * - Eingaben: Übergeben wird ein Zeiger auf das Sprachmodul-Objekt (p).
 * - Rückgabewert: Die Funktion gibt den unteren 4-Bit-Wert (0-15, unsigned char) zurück.
 === Ende Beschreibung === */
unsigned char f_0b04e0(unsigned char *p) { return *p & 0xf; }
//@ f_0b04f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest die oberen 4 Bits (*p >> 4) des Status- und Modusbytes am Anfang des
 *   Sprachmodul-Objekts aus.
 * - Eingaben: Übergeben wird ein Zeiger auf das Sprachmodul-Objekt (p).
 * - Rückgabewert: Die Funktion gibt den oberen 4-Bit-Wert (0-15, unsigned char) zurück.
 === Ende Beschreibung === */
unsigned char f_0b04f0(unsigned char *p) { unsigned char t = *p; t >>= 4; return t; }

struct S { char c; int w; S() {} S(int v) { w = v; } };
extern const char d_1a5194[];
extern char d_1bb09c[], d_1bb0bc[], d_1bb0dc[], d_1bb0fc[], d_1bb11c[], d_1bb13c[], d_1bb17c[], d_1bb19c[], d_1bb15c[];
#define CASE(n, l, vt) case n: return new (mark(d_1a5194, l)) S((int)vt);
//@ f_0b0530
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als Fabrikmethode der Sprach-Engine: Sie erzeugt auf dem Heap anhand der übergebenen
 *   Sprachkennung (k) die passende Sprachmodul-Instanz mit ihrer virtuellen Methodentabelle (1 = Deutsch
 *   d_1bb09c, 2 = Englisch UK d_1bb0bc, 3 = Englisch US d_1bb0dc, 4 = Spanisch d_1bb0fc, 5 = Tschechisch
 *   d_1bb11c, 6 = Finnisch d_1bb13c, 7 = Schwedisch d_1bb15c, 8 = Norwegisch d_1bb17c, 11 = Dänisch d_1bb19c).
 * - Eingaben: Übergeben wird die numerische Sprachkennung (k).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf das neu allokierte Sprachmodul-Objekt oder 0 bei einer
 *   nicht unterstützten Sprachkennung (9, 10 oder ungültig) zurück.
 === Ende Beschreibung === */
S *f_0b0530(int k)
{
    switch (k) {
    CASE(1, 0x67, d_1bb09c)
    CASE(2, 0x6b, d_1bb0bc)
    CASE(3, 0x6f, d_1bb0dc)
    CASE(4, 0x73, d_1bb0fc)
    CASE(5, 0x77, d_1bb11c)
    CASE(6, 0x7b, d_1bb13c)
    CASE(8, 0x7f, d_1bb17c)
    CASE(11, 0x83, d_1bb19c)
    CASE(7, 0x87, d_1bb15c)
    case 9: case 10: default: return 0;
    }
    return 0;
}
