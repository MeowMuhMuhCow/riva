/* === Beschreibung (Katalog) ===
 * Einheit dodungeo (0x05ec80 - 0x05f190)
 *
 * Überblick
 * Diese Einheit (dodungeo.cpp) enthält die zentrale Fabrikmethode für die Orts- und Dungeon-Objekte des Spiels.
 * Je nach übergebener Ortsnummer (0..27) legt sie das zum jeweiligen Schauplatz (Stadt Riva, Kanalisation,
 * Zwergenbinge, Burg, Tempel, Turm, Schiff usw.) gehörende C++-Ortsobjekt auf dem Heap an und ruft dessen
 * Konstruktor auf.
 === Ende Beschreibung === */
// P1 1/1 gleich
// dodungeo.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x05ECF0-0x05F190
#include <string.h>
#include "RIVAMEM.H"



extern const char d_1a18b0[];

int f_048110(void *p);
int f_0f2dc0(void *p);
int f_0f5770(void *p);
int f_0f7260(void *p);
int f_0627a0(void *p);
int f_064880(void *p);
int f_0286b0(void *p);
int f_115d40(void *p);
int f_118e60(void *p);
int f_11aa80(void *p);
int f_08cd00(void *p);
int f_08e300(void *p);
int f_0211a0(void *p);
int f_022960(void *p);
int f_0c0c80(void *p);
int f_0c6150(void *p);
int f_0c9e60(void *p);
int f_127590(void *p);
int f_129cc0(void *p);
int f_12c5b0(void *p);
int f_12edd0(void *p);
int f_131f10(void *p);
int f_0ff630(void *p);
int f_1034b0(void *p);
int f_107360(void *p);
int f_0bb020(void *p);
int f_0bd3e0(void *p);
#define NE(F,LN,SZ) { void *p = operator new(SZ, mark(d_1a18b0, LN)); if (p) F(p); }
#define NL(F,LN,SZ) { void *p = operator new(SZ, mark(d_1a18b0, LN)); if (p) F(p); }
//@ f_05ecf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt anhand der Ortsnummer n (0..27, ohne den unbenutzten Fall 12) per operator new das
 *   passende Ortsobjekt (0x0c bis 0x22 Bytes groß) und ruft dessen spezifischen Ortskonstruktor auf (z. B.
 *   f_048110 für Ort 0 Stadt Riva, f_0f7260 für Ort 3 Kanalisation, f_0627a0 für Ort 4, f_064880 für Ort 5,
 *   f_0286b0 für Ort 6 Burg, f_0211a0/f_022960 für die Boron-Grüfte 13/14, f_12c5b0/f_12edd0 für den Magierturm
 *   20/21 oder f_1034b0/f_107360 für das Schiff 24/25). Jeder dieser Konstruktoren trägt sich über den
 *   Basiskonstruktor f_05ff60(this, n) selbst als aktiver Spielort ein.
 * - Eingaben und Rückgabe: Die Funktion erhält die Ortsnummer n (unsigned short) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Der String d_1a18b0 enthält den Quelldateinamen (dodungeo.cpp) für die
 *   Speichermarkierung mark(d_1a18b0, Zeile) bei operator new.
 === Ende Beschreibung === */
void f_05ecf0(unsigned short n)
{
    void *p;
    switch (n) {
    case 0: NE(f_048110, 0x2f, 0xc) break;
    case 1: NE(f_0f2dc0, 0x33, 0xc) break;
    case 2: NE(f_0f5770, 0x37, 0xc) break;
    case 3: NE(f_0f7260, 0x3b, 0xc) break;
    case 4: NE(f_0627a0, 0x3f, 0xc) break;
    case 5: NE(f_064880, 0x43, 0x20) break;
    case 6: NE(f_0286b0, 0x47, 0xe) break;
    case 7: NE(f_115d40, 0x4b, 0xc) break;
    case 8: NE(f_118e60, 0x4f, 0xc) break;
    case 9: NE(f_11aa80, 0x53, 0xc) break;
    case 10: NE(f_08cd00, 0x57, 0xc) break;
    case 11: NE(f_08e300, 0x5b, 0xc) break;
    case 13: NE(f_0211a0, 0x65, 0xc) break;
    case 14: NL(f_022960, 0x69, 0xc) break;
    case 15: NL(f_0c0c80, 0x6d, 0xc) break;
    case 16: NL(f_0c6150, 0x71, 0xc) break;
    case 17: NL(f_0c9e60, 0x75, 0x22) break;
    case 18: NL(f_127590, 0x79, 0xe) break;
    case 19: NL(f_129cc0, 0x7d, 0xc) break;
    case 20: NL(f_12c5b0, 0x81, 0xc) break;
    case 21: NL(f_12edd0, 0x85, 0xc) break;
    case 22: NL(f_131f10, 0x89, 0xc) break;
    case 23: NL(f_0ff630, 0x8d, 0x11) break;
    case 24: NL(f_1034b0, 0x91, 0x11) break;
    case 25: NL(f_107360, 0x95, 0x11) break;
    case 26: NL(f_0bb020, 0x99, 0x10) break;
    case 27: NL(f_0bd3e0, 0x9d, 0xc) break;
    }
}
