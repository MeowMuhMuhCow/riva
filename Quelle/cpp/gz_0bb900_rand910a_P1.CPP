/* === Beschreibung (Katalog) ===
 * Einheit gz_0bb900_rand910a (Adresse 0x0bb900 - 0x0bbaf0)
 *
 * Diese Einheit bildet die erste Rand-Aufteilung des Hilfsmoduls gz_0bb900 zwischen der Markthalle und dem
 * Bildschirmmasken-Modul (mask.cpp). In dieser Datei ist der virtuelle Destruktor f_0bb900 der
 * Markthallen-Klasse ausimplementiert, während die nachfolgenden fünf Statusleisten- und Masken-Hilfsfunktionen
 * (f_0bb940 bis f_0bbac0) als Vorwärtsdeklarationen markiert sind und in gz_0bb900_rand910b stehen.
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
 *
 *
 * Vorwärtsdeklarationen (Implementierung in gz_0bb900_rand910b)
 *
 * Die folgenden Funktionen sind in dieser Teileinheit nur als Prototypen deklariert und in gz_0bb900_rand910b
 * beschrieben:
 * - f_0bb940 (0x0bb940)
 * - f_0bb9a0 (0x0bb9a0)
 * - f_0bba10 (0x0bba10)
 * - f_0bba60 (0x0bba60)
 * - f_0bbac0 (0x0bbac0)
 === Ende Beschreibung === */
int f_0bb900(int p, unsigned f)
{
    int r;
    if (f & 4) {
        f_145254(f_145234(p, (int)&d_1bb27c));
        return p;
    }
    r = f_060030(p, 1);
    if (f & 2) operator delete((void *)r);
    return r;
}
//@ f_0bb940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt die beiden kleinen Status-Icons mit den Indizes 3 und 4 aus dem
 *   Grafikarchiv-Eintrag 0x170012 in die globalen Bitmap-Puffer d_1c2a58 und d_1c2a64
 *   (Treffer-/Aktionsmarkierungen für die Heldenporträts).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb940(void)
;
//@ f_0bb9a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine Textzeile p1 im aktuellen Textfenster (d_1c38b0) aus, hängt ein Leerzeichen
 *   bzw. Trennzeichen (d_1b8224) an und rückt den Textcursor auf den Beginn der nächsten Zeile vor (f_05e1d0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die auszugebende Zeichenkette entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
#pragma aux f_0e9550 modify [ebx ecx];
int f_0bb9a0(int p1)
;
//@ f_0bba10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft, ob die Standard-Spielmaske (3D-Ansichtsfenster mit unterer Heldenleiste,
 *   d_1c2a80 == 0x40000 oder 0x40001) aktuell geladen und sichtbar ist und nicht durch einen
 *   Vollbild-Sondermodus (d_1bfb1c == 1) überdeckt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Spielmaske aktiv und zeichenbar ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0bba10(void)
;
//@ f_0bba60
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor-Wrapper initialisiert die beiden Icon-Puffer d_1c2a58 und d_1c2a64 durch das Laden
 *   der Teilgrafiken 3 und 4 aus der Ressource 0x170012 und gibt den übergebenen Objektzeiger p1 zurück.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 unverändert zurück.
 === Ende Beschreibung === */
int f_0bba60(int p1)
;
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
;
