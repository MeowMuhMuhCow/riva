/* === Beschreibung (Katalog) ===
 * Einheit gz_11bd60_rand910a (0x11bd60 - 0x11bdd0)
 *
 * Überblick
 * Diese Einheit bildet den ersten Abschlussteil von star3.cpp und enthält die letzte Übergangsroutine der
 * dritten Bienenstock-Ebene sowie den Destruktor des star3-Dungeon-Objekts.
 === Ende Beschreibung === */
// P1 3/3 gleich
// gz_11bd60.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11BD60-0x11BDE0
#include <string.h>
#include "RIVAMEM.H"



int f_060800(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);
int f_115640(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
extern int d_1bb9bc;
extern int d_1c2c64;
//@ f_11bd60
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einem Übergang (0x2e0000ea), ob die Gruppe hinüberwechseln möchte, und führt bei Bestätigung
 *   den Ortswechsel 0x2e0017 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11bd60(void)
{
  if (f_0bf6f0((int)&d_1c2c64, 0x2e0000ea)) {
    f_060800(0x2e0017, 0, 0);
  }
}
//@ f_11bd90
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor des Dungeon-Objekts der dritten Bienenstock-Ebene (star3), der den Basis-Destruktor
 *   f_115640 aufruft und bei gesetztem Flag den Objektspeicher freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_11bd90(int p1, int p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)&d_1bb9bc);
    f_145254();
    return p1;
  }
  r = f_115640(p1, 1);
  if (p2 & 2) {
    operator delete((void *)r);
  }
  return r;
}
//@ f_11bdd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert einen konstanten Statuswert (1) für die virtuelle Abfrage des star3-Dungeon-Objekts zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_11bdd0(void)
;
