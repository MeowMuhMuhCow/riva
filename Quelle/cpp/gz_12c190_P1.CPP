/* === Beschreibung (Katalog) ===
 * Einheit gz_12c190 (0x12c190 - 0x12c2a0)
 *
 * Überblick
 * Diese Einheit bildet den Abschluss von tower1.cpp (obere Etage des Magierturms, Dungeon-ID 0x13) und enthält
 * eine Hilfsfunktion zum Wiedervereinigen einer abgespaltenen Teilgruppe mit der Hauptgruppe, eine
 * Synchronisationsfunktion für den Hebelmechanismus 0x1f50/0x1f4c sowie den Destruktor des
 * tower1-Dungeon-Objekts.
 === Ende Beschreibung === */
// P3 2/6 gleich (suche.py 23.10.2026, Basis gz_12c190_P1.CPP)
// gz_12c190.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12C190-0x12C660
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c80(int p1);                                   // reg eax stapel 0
int f_041000();                                         // reg - stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

short f_0dc020(int p1, int p2);
short f_0dcc10(int p1);
int f_0dcc40(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060240();
int f_060740(int p1, int p2);
void f_145234(int p1, int p2);
void f_145254();
extern int d_1c0004, d_1c0028; extern signed char d_1c0cf8;
struct GS { short n; int *tab; };
extern GS d_1c212a, d_1c2132;
extern char d_1c0d08, d_1c0d0c, d_1c0d10, d_1c0d14, d_1c0d18, d_1c0d1c, d_1c0d20, d_1c0d24, d_1c0d28, d_1c0d2c, d_1c0d30, d_1c0d34, d_1c0d38, d_1c0d3c;
extern short d_1c0d09, d_1c0d0d, d_1c0d11, d_1c0d15, d_1c0d19, d_1c0d1d, d_1c0d21, d_1c0d25, d_1c0d29, d_1c0d2d, d_1c0d31, d_1c0d35, d_1c0d39, d_1c0d3d;
extern short d_1c0d40, d_1c0d42, d_1c0d44, d_1c0d46, d_1c0d48, d_1c0d4a;
extern char d_1bbb3c[], d_1bbb94[];
#define EQI(x,v) (((x)==(v))?1:0)
#define ADD(x) d_1c212a.tab[d_1c212a.n] = (int)&x; d_1c212a.n++;
#define ADD2(x) d_1c2132.tab[d_1c2132.n] = (int)&x; d_1c2132.n++;

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_12c190
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst den ersten Helden aus der übergebenen Teilgruppe p2 heraus, gliedert ihn wieder in die aktive
 *   Hauptgruppe (d_1c0004) ein und aktualisiert den Gruppenstatus (d_1c0028).
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 den Zeiger auf
 *   die aufzulösende Teilgruppe.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12c190(int p1, int p2)
{
    int t = f_038c80(p2);
    short s = f_0dc020(p2, t);
    f_0dcdf0(p2, s);
    s = f_0dcc10(d_1c0004);
    f_0dcc40(d_1c0004, t, s);
    *(signed char *)&d_1c0028 = f_041000();
}

//@ f_12c1e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Synchronisiert den Schaltzustand des Hebels 0x1f50 und des Durchgangs 0x1f4c mit dem Flag d_1c0cf8.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12c1e0(void)
{
    short s;
    short b;
    s = f_060760(0x1f50);
    b = EQI(EQI(d_1c0cf8, 0), 0);
    if ((EQB(d_1c0cf8, 0) && s == (short)2) || (EQI(d_1c0cf8, 1) && s == (short)1)) {
        f_060740(0x1f50, 1);
        f_0607e0(0x1f4c, (signed char)b);
    }
}

//@ f_12c260
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor des Dungeon-Objekts für die obere Magierturm-Etage (tower1), der den Basis-Destruktor
 *   f_060030 aufruft und bei gesetztem Flag den Objektspeicher freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_12c260(int p1, int p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bbb3c);
        f_145254();
        return p1;
    }
    r = f_060030(p1, 1);
    if (p2 & 2) delete (char *)r;
    return r;
}
