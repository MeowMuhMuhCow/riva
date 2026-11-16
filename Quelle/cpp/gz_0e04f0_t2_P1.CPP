/* === Beschreibung (Katalog) ===
 * Einheit gz_0e04f0_t2
 *
 * Diese Einheit bildet den zweiten Teil von gz_0e04f0 am Beginn des Grafikmoduls für den Gegenstands- und
 * Handelspool (poolgfx.cpp). Sie berechnet die Abmessungen des Pool-Kachelrasters, initialisiert das
 * Grafik-Steuerobjekt des Pools und verarbeitet Mausklicks auf die Schaltflächen des Pool-Fensters.
 === Ende Beschreibung === */
// P3 5/6 gleich (suche.py 26.10.2026, Basis gz_0e04f0_P1.CPP)
// gz_0e04f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E04F0-0x0E06F0
#include <string.h>
#include "RIVAMEM.H"



int f_0d3780();
int f_0d3800();
int f_0d3810();
short f_11c320(int p1);
int f_11c580(int p1, int p2);
short f_11c620(int p1, int p2);
void *f_145300(void *p, int c, unsigned n);              // memset
void *f_14d075(void *d, void *s, unsigned n);            // memmove
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1bb558;                  // 0x1BB558
extern short d_1bb55a;                  // 0x1BB55A
extern short d_1c0034;                  // 0x1C0034
extern short d_1c0036;                  // 0x1C0036
extern volatile short d_1c0042;                  // 0x1C0042
extern short d_1c0046;                  // 0x1C0046
extern short d_1c0048;                  // 0x1C0048
//@ f_0e0650
/* === Beschreibung (Katalog) ===
 * Berechnet aus der konstanten Spaltenanzahl (d_1bb55a = 4) und Zeilenanzahl (d_1bb558 = 5) des Gegenstandspools
 * die Pixelkoordinaten bzw. Ausmaße des Rasters (d_1c0034 = (4 - 1) * 60 - 2 = 178 und d_1c0036 = 5 * 22 - 2 =
 * 108).
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0650()
{
    d_1c0034 = (d_1bb55a - 1) * 0x3c - 2;
    d_1c0036 = d_1bb558 * 0x16 - 2;
}
//@ f_0e0680
/* === Beschreibung (Katalog) ===
 * Initialisiert das 16 Byte große Grafik-Steuerobjekt (p) eines Gegenstandspools, indem der Zeiger auf die
 * Pool-Hauptdatenstruktur (p[0] = v) und der Standard-Bildschirmpuffer (p[2] = d_1a34e0) eingetragen sowie der
 * aktuell ausgewählte Held (p[1] = 0) und der Zwischenpuffer (p[3] = 0) zurückgesetzt werden.
 * - Eingaben: Übergeben werden ein Zeiger auf das Grafik-Steuerobjekt p sowie die Adresse der
 *   Pool-Hauptdatenstruktur v.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0680(int *p, int v)
{
    p[1] = 0;
    p[3] = 0;
    p[0] = v;
    p[2] = d_1a34e0;
}
//@ f_0e06a0
/* === Beschreibung (Katalog) ===
 * Dient als Maus-Rückruffunktion des Pool-Fensters und prüft, ob ein angeklicktes Aktionsfeld (p1 im Bereich
 * 1..20, abweichend vom aktuell ausgewählten Feld d_1c0042) bei gedrückter Maustaste (f_0d3810, f_0d3780 oder
 * f_0d3800) aktiviert wurde, woraufhin die Auswahl in d_1c0046 gespeichert und das Ereignisflag d_1c0048 = 1
 * gesetzt wird.
 * - Eingaben: Die Funktion erhält die Kennung des unter dem Mauszeiger liegenden Klickbereichs p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e06a0(short p1)
{
    if (p1 && (int)p1 != (int)d_1c0042 && p1 >= 1 && (int)p1 <= 0x14) {
        if (f_0d3810() || f_0d3780() || f_0d3800()) {
            d_1c0046 = p1;
            d_1c0048 = 1;
        }
    }
}
