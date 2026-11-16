/* === Beschreibung (Katalog) ===
 * Einheit gz_0cd990
 *
 * Diese Einheit bildet die Fortsetzung von mirror.cpp und enthält die Konstruktor-, Destruktor- und
 * Steuerfunktionen des Spiegel-Ereignisobjekts (d_1bb420) sowie eine Suchfunktion über die sechs Gruppen-Slots
 * (d_1bfdbc).
 === Ende Beschreibung === */
// P1 4/5 gleich
// gz_0cd990.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CD990-0x0CDAD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
inline int EQ(int a, int b) { return a == b; }
inline int GT(int a, int b) { return a > b; }
int f_0b8490(int p1, int p2);
int f_0b8520(int p1, int p2);
int f_0daa90(int p1, int p2);
int f_0dc430(int p1, int p2);
short f_0de7f0(int p1);
int f_0de9c0(int p1);
int f_145234(int p1, const void *p2);
int f_145254();
extern signed char d_1c01e4;
extern signed char d_1c1070;
extern signed char d_1c0028;
extern int d_1bfdb8;
extern int d_1c0004;
extern char d_1bfdbc[];
extern char d_1bb40c[];
extern int d_1bb420[];
//@ f_0cd990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt in Abhängigkeit vom Story-Flag d_1c01e4 entweder das Spiegel-Triggerflag
 *   d_1c1070 = 1 oder ruft f_0daa90(d_1bfdb8, 0x33) auf und trägt im Objekt p1 bei Offset +0x50 den Statuswert 6
 *   ein.
 * - Eingaben: Als Parameter wird der this-Zeiger p1 des Spiegel-Objekts übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cd990(int p1)
{
  if (EQI(d_1c01e4, 0)) d_1c1070 = 1; else f_0daa90(d_1bfdb8, 0x33);
  *(int *)(p1 + 0x50) = 6;
}
//@ f_0cd9d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt das globale Spiegel-Triggerflag d_1c1070 auf 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cd9d0() { d_1c1070 = 0; }
//@ f_0cd9e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein von der Orts-Basisklasse (f_0b8490) abgeleitetes
 *   Spiegel-Ereignisobjekt, trägt die virtuelle Methodentabelle d_1bb420 bei Offset +0x58 ein und setzt den
 *   Zähler bei Offset +0x5c auf 0.
 * - Eingaben: Übergeben werden der this-Zeiger p1 sowie die Orts- oder Objektkennung p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cd9e0(int p1, short p2)
{
  int r = f_0b8490(p1, p2);
  *(int *)(r + 0x58) = (int)d_1bb420;
  *(short *)(r + 0x5c) = 0;
}
//@ f_0cda00
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser löschende Destruktor baut ein Spiegel-Ereignisobjekt (d_1bb420) über den Basisdestruktor
 *   f_0b8520(p1, 1) ab und gibt bei gesetztem Bit 2 in p2 den Speicher frei.
 * - Eingaben: Übergeben werden der this-Zeiger p1 sowie das Destruktor-Steuerflag p2.
 * - Rückgabewert: Zurückgegeben wird die Adresse des abgebauten Objekts p1.
 === Ende Beschreibung === */
int f_0cda00(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) { f_145234(p1, d_1bb40c); f_145254(); return p1; }
  *(int *)(p1 + 0x58) = (int)d_1bb420;
  r = f_0b8520(p1, 1);
  if (p2 & 2) operator delete((void *)r);
  return r;
}
//@ f_0cda50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht - sofern nicht der Modus d_1c0028 == 1 aktiv ist - alle sechs
 *   Gruppenstrukturen im Array d_1bfdbc (je 0x61 Bytes) nach einer weiteren aktiven Teilgruppe (p != d_1c0004),
 *   die sich am selben Ort wie die Hauptgruppe befindet (f_0dc430) und nicht blockiert ist (f_0de9c0 == 0).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Index (0 bis 5) der gefundenen zweiten Teilgruppe oder -1, falls keine
 *   passende Teilgruppe existiert.
 === Ende Beschreibung === */
int f_0cda50()
{
  int r = -1;
  int i;
  char *p;
  signed char mode = d_1c0028;
  if (mode != 1) {
    for (i = 0, p = d_1bfdbc; (short)i < 6; i++, p += 0x61) {

      if ((int)p != d_1c0004) {
        if (f_0de7f0((int)p)) {
          if (f_0dc430(d_1c0004, (int)p) != 0) {
            if (f_0de9c0((int)p) == 0) r = i;
          }
        }
      }
    }
  }
  return r;
}
