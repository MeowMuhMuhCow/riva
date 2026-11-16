/* === Beschreibung (Katalog) ===
 * Einheit gz_0bb900_rand910b (Adresse 0x0bb900 - 0x0bbaf0)
 *
 * Diese Einheit bildet die zweite Rand-Aufteilung des Übergangsmoduls gz_0bb900 vor dem Bildschirmmasken-Modul
 * (mask.cpp). Sie enthält Hilfsfunktionen zum Laden der Angriffssymbole, zur Textausrichtung in der Statuszeile
 * und zur Abfrage, ob die Haupt-Benutzeroberfläche (Heldenleiste und Sichtfenster-Rahmen) gerade aktiv ist.
 *
 *
 * Vorwärtsdeklarationen (Implementierung in gz_0bb900_rand910a)
 *
 * Die Destruktorfunktion f_0bb900 ist in dieser Teileinheit nur als Prototyp deklariert und in
 * gz_0bb900_rand910a beschrieben.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 4/6 gleich (suche.py 25.10.2026, Basis gz_0bb900_P1.CPP)
// gz_0bb900.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BB900-0x0BBAF0
#include <string.h>
int f_145234(int p1, int p2);
int f_145254(int p1);
int f_060030(int p1, int p2);
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);

int f_0e9550(int p1, int p2);
int f_0e9650(int p1, int p2);
#pragma aux f_0e9650 modify exact [eax edx ebx];
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);
short f_05e200(int p1);
int f_05e1d0(int p1, int p2, int p3);
short f_0de800(int p1);
short f_0de820(int p1);
int f_060a80(int p1);
extern int d_1bb27c;
extern int d_1b8224;
extern int d_1c0004;
extern int d_1c2a58;
extern int d_1c2a64;
extern int d_1c2a80;
extern int d_1c2be0;
extern int d_1c38b0;
extern signed char d_1bfb1c;
//@ f_0bb900
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Markthallen-Gebäudeobjekt (d_1bb27c) oder ein Array solcher
 *   Objekte (f & 4) ab, ruft den Basisdestruktor f_060030 auf und gibt bei gesetztem Bit f & 2 den
 *   Objektspeicher frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p sowie die Watcom-Destruktor-Flags f entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p zurück.
 === Ende Beschreibung === */
int f_0bb900(int p, unsigned f)
;
//@ f_0bb940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt die beiden kleinen Status-Icons mit den Indizes 3 und 4 aus dem
 *   Grafikarchiv-Eintrag 0x170012 in die globalen Bitmap-Puffer d_1c2a58 und d_1c2a64
 *   (Treffer-/Aktionsmarkierungen für die Heldenporträts).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb940(void)
{
    f_04fef0((int)&d_1c2be0, 0x170012, ((int)(((RivaRasterImage*)((int)&d_1c2a58))->f_0fb0b0())), 0, 3, 0, 0x140);
    f_04fef0((int)&d_1c2be0, 0x170012, ((int)(((RivaRasterImage*)((int)&d_1c2a64))->f_0fb0b0())), 0, 4, 0, 0x140);
}
//@ f_0bb9a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine Textzeile p1 im aktuellen Textfenster (d_1c38b0) aus, hängt ein Leerzeichen
 *   bzw. Trennzeichen (d_1b8224) an und rückt den Textcursor auf den Beginn der nächsten Zeile vor (f_05e1d0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die auszugebende Zeichenkette entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
#pragma aux f_0e9550 modify [ebx ecx];
int f_0bb9a0(int p1)
{
    short L[2];
    short a;
    short b;
    short c;
    short sh;
    f_0e9550((int)&d_1c38b0, p1);
    f_0e9650((int)&d_1c38b0, (int)&d_1b8224);
    f_05e2a0((int)&d_1c38b0, (int)L, (int)&c, (int)&a, (int)&b);
    sh = f_05e200((int)&d_1c38b0);
    f_05e1d0((int)&d_1c38b0, (int)L[0], (int)sh);
    return 1;
}
//@ f_0bba10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft, ob die Standard-Spielmaske (3D-Ansichtsfenster mit unterer Heldenleiste,
 *   d_1c2a80 == 0x40000 oder 0x40001) aktuell geladen und sichtbar ist und nicht durch einen
 *   Vollbild-Sondermodus (d_1bfb1c == 1) überdeckt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Spielmaske aktiv und zeichenbar ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0bba10(void)
{
    int r = 1;
    signed char c;
    if (f_0de820(d_1c0004) == -1 || f_0de800(d_1c0004) != -1 || (c = d_1bfb1c) != r) {
        if (d_1c2a80 == 0x40000) goto out;
        if (d_1c2a80 == 0x40001) goto out;
    }
    r = 0;
out:
    return r;
}
//@ f_0bba60
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor-Wrapper initialisiert die beiden Icon-Puffer d_1c2a58 und d_1c2a64 durch das Laden
 *   der Teilgrafiken 3 und 4 aus der Ressource 0x170012 und gibt den übergebenen Objektzeiger p1 zurück.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 unverändert zurück.
 === Ende Beschreibung === */
int f_0bba60(int p1)
{
    f_04fef0((int)&d_1c2be0, 0x170012, ((int)(((RivaRasterImage*)((int)&d_1c2a58))->f_0fb0b0())), 0, 3, 0, 0x140);
    f_04fef0((int)&d_1c2be0, 0x170012, ((int)(((RivaRasterImage*)((int)&d_1c2a64))->f_0fb0b0())), 0, 4, 0, 0x140);
    return p1;
}
//@ f_0bbac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt, welche der beiden Hauptmasken-Varianten (0x40000 oder 0x40001) benötigt
 *   wird, indem sie prüft, ob sich die Gruppe in einem Dungeon bzw. Gebäude (f_0de800 != -1) oder in einem
 *   speziellen Stadtbereich (f_060a80 != 0) befindet.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein Innenraum- oder Sonderbereich vorliegt, oder 0 für die
 *   Standard-Außenansicht.
 === Ende Beschreibung === */
int f_0bbac0(void)
{
    int r = 0;
    if (f_0de800(d_1c0004) != -1 || f_060a80((int)f_0de820(d_1c0004)) != 0) r = 1;
    return r;
}
