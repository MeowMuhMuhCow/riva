/* === Beschreibung (Katalog) ===
 * Einheit gz_107200 (107200 - 107380)
 *
 * Überblick
 *
 * Die Einheit gz_107200 bildet den Übergangsblock zwischen den Unterwasser-Schiffswrack-Dungeons ship2 (Kennung
 * 0x2b) und ship3 (Kennung 0x2c). Sie enthält die vier Abschlussfunktionen von ship2 (f_107200 bis f_107280)
 * sowie den Konstruktor und den Destruktor von ship3 (f_1072c0, f_107360).
 === Ende Beschreibung === */
// P3 5/6 gleich (suche.py 25.10.2026, Basis gz_107200_P1.CPP)
// gz_107200.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x107200-0x107380
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0fb5f0(int p1, int p2);
int f_0fb630(int p1, int p2);                           // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c64;                    // 0x1C2C64
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1bb7c0[];
extern int f_145234(int p1, int p2);
extern int f_145254();
extern int d_1bb818[];
extern char d_1c03a0;
extern short d_1c03a1;
extern char d_1c03a4;
extern short d_1c03a5;
extern short d_1c03a8;
extern short d_1c03a9;
extern short d_1c212a;
extern int *d_1c212c;
struct Obj107 { signed char a; short b; };
struct Reg107 { short count; Obj107 **list; };
extern Obj107 ob0, ob1, ob2; extern Reg107 registry107;
#pragma aux ob0 "d_1c03a0"
#pragma aux ob1 "d_1c03a4"
#pragma aux ob2 "d_1c03a8"
#pragma aux registry107 "d_1c212a"
inline signed char z107() { signed char c=0; return c; }
inline void add107(Obj107 &o,Reg107 &r,short id) { o.a=z107();o.b=id;r.list[r.count]=&o;r.count++; }
//@ f_1072c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das 3D-Dungeon-Objekt ship3 (Kennung 0x2c), trägt die virtuelle
 *   Methodentabelle d_19e51c ein, lädt die .LXT-Textdatei nach d_1c0410 und initialisiert beim ersten Betreten
 *   (d_1c0414 == 0) alle Raum- und Türflags (d_1c0418 bis d_1c0429).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den Konstruktor-Parameter p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_1072c0(void)
{
    add107(ob0, registry107, 0x180);
    add107(ob1, registry107, 0x181);
    add107(ob2, registry107, 0x182);
}
//@ f_107360
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt beim Verlassen von ship3 den geladenen .LXT-Textpuffer d_1c0410 wieder frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
void f_107360(int p1)
{
    int r = f_0fb5f0(p1, 0x19);
    *(int *)(r + 8) = (int)d_1bb818;
}
