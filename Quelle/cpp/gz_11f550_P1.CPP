/* === Beschreibung (Katalog) ===
 * Einheit gz_11f550 (0x11f550 - 0x11f570)
 *
 * Überblick
 * Diese kleine Einheit an der Modulgrenze zwischen tavern.cpp und tdmalloc.cpp enthält eine Hilfsfunktion zum
 * Erhöhen des taverneninternen Getränkezählers sowie einen leeren Callback-Stub für die 3D-Engine.
 === Ende Beschreibung === */
// P3 5/7 gleich (suche.py 24.10.2026, Basis gz_11f550_P1.CPP)
// gz_11f550.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11F550-0x11F6E0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060080(int p1);                                   // reg eax stapel 0
int f_15fffc(int p1, int p2);                           // reg eax edx stapel 0
char *f_120640(char *p1);
int f_144bf0(const char *a, const char *b);
int f_15e469(const char *a, const char *b);
int f_15fdd5(int a, int b, int c, int d);
int f_15e836(int a);
int f_14572e(char *, const char *, ...);
extern int d_1c0ae0;
extern const char d_1b8370[];
extern short d_1a9696, d_1a7fc2;
extern char d_1c0b98;
extern char d_1c0b00[];
extern char d_1c27a8[];
extern int d_1bd6c0;
extern int d_1a9900, d_1a9904, d_1a9908;

//@ f_11f550
/* === Beschreibung (Katalog) ===
 * - Zweck: Erhöht den Zähler für die in der aktuellen Taverne konsumierten Getränkerunden an Offset +0x62 um 1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tavernen-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11f550(int p1)
{
    *(short *)(p1 + 0x62) += 1;
}

//@ f_11f560
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere __stdcall-Rückruffunktion für die Speicherverwaltung der 3D-Engine (tdmalloc), die stets 0
 *   zurückliefert.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen ungenutzten ganzzahligen Parameter.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
int __stdcall f_11f560(int p1)
{
    return 0;
}
// f_11f570..f_11f5f0 gehoeren zu tdmalloc_neu (TDMALLOC.OBJ), Grenze 11f550-11f570 laut REST9
