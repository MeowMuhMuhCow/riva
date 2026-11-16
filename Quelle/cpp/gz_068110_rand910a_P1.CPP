/* === Beschreibung (Katalog) ===
 * Einheit gz_068110_rand910a (0x068110 - 0x068160)
 *
 * Überblick
 * Die kleine Rand-Einheit gz_068110_rand910a enthält zwei kurze Methoden eines Gebiets-/Umgebungsobjekts am
 * Übergang zwischen environ2_t2 und equip: eine Weiterleitung auf die Basismethode f_060240 und den abgeleiteten
 * Destruktor f_068120.
 === Ende Beschreibung === */
// P3 0/2 gleich (suche.py 24.10.2026, Basis gz_068110_P1.CPP)
// gz_068110.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x068110-0x0681F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bae44;                    // 0x1BAE44
extern int d_1c0004;                    // 0x1C0004
extern int d_1c01cc;                    // 0x1C01CC
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3498;
extern int d_1c3870;                    // 0x1C3870
int f_145234(int p, int d);
void f_145254();
#define A(x) ((int)&(x))
static inline int EQ(int a, int b) { return a == b; }
struct PL { int a[15]; };

void call_060240494();
#pragma aux call_060240494 "W?f_060240$n()v";

//@ f_068110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet den Aufruf unmittelbar an die Basisklassenroutine f_060240 weiter.
 * - Eingaben und Rückgabe: Keine expliziten Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen.
 === Ende Beschreibung === */
void f_068110()
{
    call_060240494();
}

//@ f_068120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Abgeleiteter Destruktor eines Gebiets-/Umgebungsobjekts: Führt bei gesetztem Bit 4 in fl die
 *   Ausnahme-Abwicklung über f_145234/f_145254 mit der Tabelle d_1bae44 aus, ruft sonst den
 *   Basisklassendestruktor f_060030(p1, 1) auf und gibt bei gesetztem Bit 2 den Objektspeicher mit operator
 *   delete frei.
 * - Eingaben und Rückgabe: Eingaben sind der Objektzeiger p1 (eax) und die Destruktor-Flags fl (edx, unsigned);
 *   zurückgegeben wird der Objektzeiger (int in eax).
 * - Wichtige Variablen: d_1bae44 ist die Ausnahmetabelle der abgeleiteten Klasse.
 === Ende Beschreibung === */
int f_068120(int p1, unsigned fl)
{
    if (fl & 4) {
        f_145234(p1, A(d_1bae44));
        f_145254();
        return p1;
    }
    int r = f_060030(p1, 1);
    if (fl & 2) delete (void *)r;
    return r;
}
int f_068160(void)
;

