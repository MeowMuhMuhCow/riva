/* === Beschreibung (Katalog) ===
 * Einheit gz_0d6690
 *
 * Diese kleine Einheit bildet den Übergang zwischen npc.cpp (Suche nach der Gruppe eines Begleit-NSCs) und
 * numinput.cpp (Getter/Setter für das Zahleneingabe-Steuerelement).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 2/3 gleich (suche.py 24.10.2026, Basis gz_0d6690_P1.CPP)
// gz_0d6690.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D6690-0x0D6710
#include <string.h>
#include "RIVAMEM.H"



int f_039040(int p1);

int f_0de7c0(int p1);
extern int d_1bfdbc;
//@ f_0d6690
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle sechs Gruppenstrukturen in d_1bfdbc (je 0x61 Bytes) nach einer aktiven
 *   Gruppe (f_0de7c0), der ein Begleit-NSC (f_039040) angeschlossen ist, und prüft, ob dieser die gesuchte
 *   NSC-Kennung p1 (f_042400, oder beliebig bei p1 == 0) besitzt.
 * - Eingaben: Als Parameter wird die gesuchte NSC-Kennung p1 (0 für einen beliebigen NSC) übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die gefundene Gruppenstruktur oder 0, falls der gesuchte NSC
 *   keiner Gruppe angehört.
 === Ende Beschreibung === */
int f_0d6690(short p1)
{
  int result = 0;
  short k;
  int q;
  for (k = 0; k < 6; k++) {
    q = (int)&d_1bfdbc + k * 0x61;
    if (f_0de7c0(q) != 0 && f_039040(q) != 0) {
      if (p1 == 0 || p1 == (signed char)((char)(f_042400((struct hero *)(f_039040(q)))))) {
        result = q;
        break;
      }
    }
  }
  return result;
}
//@ f_0d66f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die konfigurierte Ziffernanzahl bei Offset +8 (ndig) eines
 *   Zahleneingabe-Objekts p1 aus.
 * - Eingaben: Als Parameter wird der this-Zeiger p1 des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Zurückgegeben wird die Anzahl der Ziffernstellen als 16-Bit-Ganzzahl.
 === Ende Beschreibung === */
short f_0d66f0(int p1)
{
  return *(short *)(p1 + 8);
}
//@ f_0d6700
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Index der aktuell ausgewählten Ziffernstelle bei Offset +0xc (sel)
 *   eines Zahleneingabe-Objekts p1 auf den Wert p2.
 * - Eingaben: Übergeben werden der this-Zeiger p1 des Zahleneingabe-Objekts sowie der neue Auswahlindex p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d6700(int p1, short p2)
{
  *(short *)(p1 + 0xc) = p2;
}
