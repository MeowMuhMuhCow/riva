/* === Beschreibung (Katalog) ===
 * Einheit gz_09b900_rand910a (09b900-09b940)
 *
 * Überblick
 * Dieses kurze Randsegment am Ende von headquar enthält eine Hilfsfunktion zum Bereinigen der Gruppenausrüstung
 * samt Setzen des Questflags 0x176 sowie eine virtuelle Rückgabefunktion.
 === Ende Beschreibung === */
// P3 4/5 gleich (suche.py 23.10.2026, Basis gz_09b900_P1.CPP)
// gz_09b900.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09B900-0x09B9E0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_039a80(int p1, int p2);
int f_0dcf00(int p1, int p2, int p3);
int f_109290(int p1, int p2);
int f_1092e0(int p1, int p2);
int f_145234(int p1, int p2);
int f_145254(void);
void f_09b8c0(void);
extern int d_1bafe8;
extern char d_1baffc[];
extern char d_1bdd10;
extern short d_1bdd11;
extern void **d_1c212c;
extern short d_1c212a;
//@ f_09b900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für alle Helden der übergebenen Gruppe p2 die Inventarbereinigung f_09b8c0 über f_039a80
 *   auf und setzt anschließend das Gruppen-Questflag 0x176 auf 1.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Objektzeiger p1 sowie den Gruppenzeiger p2 und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion delegiert die eigentliche Inventarprüfung an f_09b8c0 aus headquar.
 === Ende Beschreibung === */
void f_09b900(int p1, int p2)
{
    f_039a80(p2, (int)f_09b8c0);
    f_0dcf00(p2, 0x176, 1);
}
//@ f_09b930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt als virtuelle Statusabfrage konstant den Wert 1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt 1 zurück (int).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */
int f_09b930(void)
{
    return 1;
}
//@ f_09b940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert die Zustandsvariable d_1bdd10 mit 0 sowie ihre Kennung d_1bdd11 mit 0x16 und
 *   trägt ihre Adresse in die globale Spielstands-Registrierungstabelle d_1c212c (d_1c212a) ein.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Byte d_1bdd10 zählt den Fortschritt der kostenpflichtigen Auskünfte/Gerüchte beim
 *   Heiler (0 bis 7).
 === Ende Beschreibung === */
void f_09b940(void)
;
//@ f_09b980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Heiler-Gebäudeobjekt über den Basiskonstruktor f_109290 und setzt dessen
 *   virtuelle Methodentabelle an Offset 0x58 auf d_1baffc.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Gebäudekennung p2 (short) und gibt
 *   die initialisierte Objektadresse zurück (int).
 * - Wichtige Variablen: Das Feld *(void )(r + 0x58) verweist auf die Methodentabelle d_1baffc des Heilers.
 === Ende Beschreibung === */
int f_09b980(int p1, short p2)
;
//@ f_09b990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des Heiler-Gebäudeobjekts, ruft den Basisdestruktor f_1092e0 auf und gibt
 *   bei gesetztem Bit 2 in p2 den Speicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2 und gibt die
 *   Objektadresse zurück (int).
 * - Wichtige Variablen: Bei Array-Abbau (p2 & 4) wird der Deskriptor d_1bafe8 an f_145234 übergeben.
 === Ende Beschreibung === */
int f_09b990(int p1, int p2)
;
