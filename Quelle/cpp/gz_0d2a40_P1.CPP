/* === Beschreibung (Katalog) ===
 * Einheit gz_0d2a40
 *
 * Diese kleine Einheit gehört zu mouse.cpp und enthält die Funktion zum Neuzeichnen des Mauszeigers nach einer
 * Bewegung sowie die Haupt-Initialisierungsfunktion des Maussystems.
 === Ende Beschreibung === */
// P1 1/1 gleich
// gz_0d2a40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D2A40-0x0D2B10
#include <string.h>
#define EQI(x,v) (((x)==(v))?1:0)
#include "RIVAMEM.H"



short f_0d3150();
int f_0d31c0();
int f_0d3750();
int f_13f900();
int f_13f930();
extern char d_1bf4ec;
extern int d_1bf508;
extern short d_1bf51c;
extern int d_1bf548;

void f_0d2d50();
void f_0d2b70();
void f_0d2920();
void f_0d2b10();
int f_147b97(void *, unsigned short, void (*)());
int f_15e181(void (*)());
extern short d_1bf49e, d_1bf4a2;
extern unsigned short d_1bf4f0;
extern short d_1bf4f2;
extern int d_1bf4a8;
extern signed char d_1bf4ef;
extern char d_1c2edc[];

//@ f_0d2a40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft bei aktivierter Region-Überwachung (d_1bf51c == 1) über f_0d3750 den aktuellen
 *   Mausbereich und zeichnet bei gesetztem Bewegungsflag d_1bf4ec und sichtbarem Cursor (d_1bf508 == 1) den
 *   Mauszeiger durch Wiederherstellen des alten Hintergrunds (f_0d3150) und Neuzeichnen an der neuen Position
 *   (f_0d31c0) neu.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2a40()
{
    if (d_1bf51c == 1)
        f_0d3750();
    if (d_1bf4ec && d_1bf548 == 0)
    {
        if (d_1bf508 == 1) {
            f_13f900();
            f_0d3150();
            f_0d31c0();
            f_13f930();
        }
        d_1bf4ec = 0;
    }
}
//@ f_0d2a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert das gesamte Maussystem: Sie lädt die Cursor-Grafiken (f_0d2d50), setzt
 *   den Maustreiber zurück (d_1bf49e = 0, f_0d2b70), positioniert den Zeiger bei vorhandenem Treiber (d_1bf49e
 *   == -1) auf die Startkoordinaten, registriert den 100-Hz-Abfragetimer f_0d2920 (f_147b97) sowie die
 *   atexit-Aufräumroutine f_0d2b10 (f_15e181) oder deaktiviert andernfalls die Maus (d_1bf4ef = 1).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2a90()
{
    f_0d2d50();
    d_1bf49e = 0;
    f_0d2b70();
    if (d_1bf49e == -1) {
        *(volatile short *)&d_1bf49e = 4;
        d_1bf4a2 = d_1bf4f0;
        d_1bf4a8 = *(volatile short *)&d_1bf4f2;
        f_0d2b70();
        f_147b97(d_1c2edc, 100, f_0d2920);
        *(volatile signed char *)&d_1bf4ef = 0;
        f_15e181(f_0d2b10);
    } else {
        d_1bf4ef = 1;
    }
}
