/* === Beschreibung (Katalog) ===
 * Einheit gz_03d3d0_t2 (0x03D900 - 0x03D980)
 *
 * Überblick
 * Die Einheit gz_03d3d0_t2 bildet den zweiten Teil von gz_03d3d0 und enthält zwei zusammengehörige
 * Bildschirm-Hilfsfunktionen (f_03d900 und f_03d940), die vor bzw. nach einer Zauber- oder Kampfdarstellung den
 * Bildschirmhintergrund sichern, das Heldenporträt bzw. die Figur positionieren und den Hintergrund anschließend
 * wiederherstellen.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/9 gleich (suche.py 25.10.2026, Basis gz_03d3d0_P1.CPP)
// I9: aus gz_03d3d0_REST.CPP uebernommen (Stufe-2-Stand), Marken 9 neu
// gz_03d3d0.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x03D3D0-0x03D980. Zauber-Hilfen: Pruefung/Kosten, Zauber-Ablauf, Effekt-Fenster, Bitfelder, Hintergrund auf/ab.
#include <string.h>
#include <stdlib.h>
#pragma intrinsic(_lrotl)
struct Ent; struct Game;
struct SpT { char b0; signed char b1; signed char b2; signed char b3; char b4; signed char b5; char b6; signed char b7; char b8; unsigned char b9; char pad[4]; };
extern SpT d_1a7270[];
extern int d_1c0420, d_1c11d0, d_1c040e;
extern char d_1c040c[0x14];
extern short d_1bd90c;
extern short d_1c0428;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern void *d_1a34e0;
struct Sl { char pad[0xb]; unsigned long bits; char pad2[0xc]; };
struct Ent : hero {
    
    signed char f_030960(); Ent *f_030890(); Ent *f_030810();
       
     short f_044940(int a, int b, int c, int d);
    short f_03cd00(int k); void f_030850(Ent *x);  signed char f_0433d0(); 
    short f_03d3d0(short idx, signed char b); short f_03d4b0(short mode, short arg);
};
signed char f_0cfa70(Ent *x); char f_0cfef0(Ent *x); int f_0d49b0(Ent *e);
struct Game { Ent *f_038e90(long code); };
extern Game *d_1c0004;
struct Msg { void f_0bf730(long code); void f_0bf6c0(int a); void f_0bf680(); };
extern Msg d_1c2c64;


struct Sp { char b[0x20]; Sp(Ent *e); ~Sp(); short f_10ce80(int a, int b); };
struct Eff { char b[0x20]; Eff(Ent *a, Ent *b, int c, int d, int e); Eff(Ent *a, int b, int c, int d, int e, int f); ~Eff(); void f_134910(); void f_134d50(); void f_13bc30(); };
void f_09ac80(void *p, int a, int b); void f_09a140(int a, int b); void f_10a980(Ent *e, int a, int b); void f_09ade0(void *p, int a, int b);
int f_09aed0(int a); void f_0d2710(); void f_0d26e0();

//@ f_03d900
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bereitet die Bildschirmdarstellung für eine Zauber- oder Effektanimation des Helden e vor:
 *   Blendet den Mauszeiger über f_0d2710() aus, sichert den Bildschirmbereich über f_09ac80(d_1a34e0, 0, 0),
 *   setzt den Grafik-/Ausschnittmodus f_09a140(0, 0x19) und zeichnet bzw. positioniert die Darstellung des
 *   Helden e an den Koordinaten (a, b) über f_10a980.
 * - Eingaben:
 *   - e (Zeiger auf den darzustellenden Helden Ent).
 *   - a (Horizontale Koordinate bzw. Parameter für f_10a980).
 *   - b (Vertikale Koordinate bzw. Parameter für f_10a980).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a34e0 (Globaler Pufferzeiger für den gesicherten Bildschirmhintergrund).
 === Ende Beschreibung === */
void f_03d900(Ent *e, int a, short b)
{
    f_0d2710();
    f_09ac80(d_1a34e0, 0, 0);
    f_09a140(0, 0x19);
    f_10a980(e, (short)a, b);
}

//@ f_03d940
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt nach Abschluss der in f_03d900 gestarteten Darstellung den ursprünglichen
 *   Bildschirmzustand wieder her: Setzt die Position des Helden e auf (320, 200) (f_10a980(e, 0x140, 200)),
 *   aktualisiert den Ausschnitt f_09a140(0, 0x19), restauriert den gesicherten Hintergrund aus d_1a34e0 über
 *   f_09ade0 und f_09aed0(0) und schaltet den Mauszeiger über f_0d26e0() wieder ein.
 * - Eingaben:
 *   - e (Zeiger auf den Helden Ent).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a34e0 (Globaler Pufferzeiger für den wiederherzustellenden Bildschirmhintergrund).
 === Ende Beschreibung === */
void f_03d940(Ent *e)
{
    f_10a980(e, 0x140, 200);
    f_09a140(0, 0x19);
    f_09ade0(d_1a34e0, 0, 0);
    f_09aed0(0);
    f_0d26e0();
}
