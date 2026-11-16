/* === Beschreibung (Katalog) ===
 * Einheit gz_02d9c0_t3 (0x0002ddd0 - 0x0002dee0)
 *
 * Überblick
 *
 * Die Einheit gz_02d9c0_t3 enthält eine Reihe kurzer Inline-/Hilfsmethoden zum Lesen und Ändern von 8- und
 * 16-Bit-Statuswerten, Standard-Getter für Sound-Panning und Lautstärke sowie den Konstruktor und Destruktor
 * einer Basisklasse für Orts- oder Gebäude-Ereignisse (d_1bac4c).
 === Ende Beschreibung === */
// P3 15/18 gleich (suche.py 24.10.2026, Basis gz_02d9c0_P1.CPP)
// gz_02d9c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02D9C0-0x02DEE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_041920(int p1);                                   // reg eax stapel 0
int f_060030(int p1, int p2);                           // reg eax edx stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(void *p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dd440(int p1);                                   // reg eax stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de600(int p1, void *p2);                           // reg edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_125400(void *p1, void *p2, void *p3);
int f_125400(void *p1, void *p2, void *p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(void *p1);                                   // reg eax stapel 0
int f_126410(void *p1);                                   // reg eax stapel 0
int f_133fe0(void *p1, void *p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1babf4;                    // 0x1BABF4
extern int d_1bac38;
extern int d_1bac4c;
int lib_dtorarst(int p1, void *p2, int p3);                    // 0x1BAC38
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bfdbc;
#define EL(i) ((int)&d_1bfdbc + (i) * 0x61)
extern int d_1c0004;                    // 0x1C0004
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (18), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_02ddd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht den Wert p2 von der 16-Bit-Variablen *p1 ab und gibt das neue Ergebnis zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf einen short-Wert sowie den Abzugswert p2 und
 *   gibt den aktualisierten 16-Bit-Wert zurück.
 * - Wichtige Variablen: Verändert den über p1 adressierten Speicherplatz.
 === Ende Beschreibung === */
short f_02ddd0(short *p1, int p2)
{
    return *p1 = *p1 - p2;
}

//@ f_02dde0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Addiert den Wert p2 auf die 16-Bit-Variable *p1 und liefert den neuen Stand zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p1 und den Summanden p2 entgegen und gibt den neuen
 *   short-Wert zurück.
 * - Wichtige Variablen: Verändert den über p1 adressierten Speicherplatz.
 === Ende Beschreibung === */
short f_02dde0(short *p1, int p2)
{
    return *p1 = *p1 + p2;
}
//@ f_02ddf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen 16-Bit-Wert aus der übergebenen Adresse p1 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 und gibt den gelesenen short-Wert zurück.
 * - Wichtige Variablen: Liest *p1.
 === Ende Beschreibung === */
short f_02ddf0(short *p1)
{
    return *p1;
}

//@ f_02de00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vergleicht ein vorzeichenbehaftetes Statusbyte *p1 mit dem Vergleichswert p2.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p1 und das Vergleichsbyte p2 entgegen und gibt 1 bei
 *   Gleichheit zurück, sonst 0.
 * - Wichtige Variablen: Liest *p1.
 === Ende Beschreibung === */
int f_02de00(signed char *p1, signed char p2)
{
    short p2_ = p2;
    return *p1 == p2_;
}

//@ f_02de20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den neuen Wert p2 in das Statusbyte *p1 und gibt ihn zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielzeiger p1 und den neuen Wert p2 und gibt p2 als char
 *   zurück.
 * - Wichtige Variablen: Beschreibt *p1.
 === Ende Beschreibung === */
char f_02de20(char *p1, int p2)
{
    *p1 = p2;
    return p2;
}

//@ f_02de30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Virtuelle Hilfsmethode, die konstant den Wahrheitswert 1 zurückgibt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int f_02de30() { return 1; }

//@ f_02de40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Virtuelle Hilfsmethode, die konstant 0 zurückgibt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 0 zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int f_02de40() { return 0; }

//@ f_02de50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Wert der globalen Sound-Konfigurationsvariablen d_1a9820 zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt d_1a9820 zurück.
 * - Wichtige Variablen: Liest d_1a9820.
 === Ende Beschreibung === */
int f_02de50() { return d_1a9820; }

//@ f_02de60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Mittelwert 0x8000 für die Links-Rechts-Balance einer Soundausgabe zurück.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 0x8000 zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int f_02de60() { return 0x8000; }

//@ f_02de70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den Standardwert 0x7fff für die Lautstärke eines Soundeffekts.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 0x7fff zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int f_02de70() { return 0x7fff; }

//@ f_02de80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert die Basisklasse über f_0b8490(p1, p2) und trägt am Offset +0x58 den Zeiger auf
 *   die virtuelle Methodentabelle d_1bac4c ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und die Ortskennung p2 und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Setzt den Vtable-Zeiger *(int *)(r + 0x58) = (int)&d_1bac4c.
 === Ende Beschreibung === */
void f_02de80(int p1, int p2)
{
    int r = f_0b8490(p1, (short)p2);
    *(int *)(r + 0x58) = (int)&d_1bac4c;
}

//@ f_02de90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Vtable-Zeiger bei +0x58 auf d_1bac4c zurück, ruft den Basisklassen-Destruktor
 *   f_0b8520(p1, 1) auf und gibt bei gesetztem Flag p2 & 2 den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger p1 sowie die Destruktor-Flags p2 entgegen und
 *   gibt den Objektzeiger zurück.
 * - Wichtige Variablen: Verwendet d_1bac4c, d_1bac38 und f_0b8520.
 === Ende Beschreibung === */
int f_02de90(int p1, unsigned p2)
{
    int f_145234(int p1, int p2);
    void f_145254();
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)&d_1bac38);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0x58) = (int)&d_1bac4c;
    r = f_0b8520(p1, 1);
    if (p2 & 2) operator delete((void *)r);
    return r;
}

