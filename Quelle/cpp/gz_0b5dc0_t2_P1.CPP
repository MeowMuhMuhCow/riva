/* === Beschreibung (Katalog) ===
 * Einheit gz_0b5dc0_t2 (Adresse 0x0b8490 - 0x0b8530)
 *
 * Diese Einheit enthält den Basiskonstruktor und den Basisdestruktor für die allgemeine Orts- und
 * Gebäudestruktur (Location), auf der sämtliche betretbaren Häuser, Läden, Tempel und Schauplätze in Riva
 * aufbauen.
 === Ende Beschreibung === */
// P1 1/2 gleich
// gz_0b5dc0_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B8490-0x0B8530
#include <string.h>
#include "RIVAMEM.H"



int f_145300(int p1, int p2, int p3);
extern const char d_1bb248[];
#define W16(p,o) (*(short *)((char *)(p) + (o)))
#define I32(p,o) (*(int *)((char *)(p) + (o)))
//@ f_0b8490
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein 92 Byte großes Basis-Gebäudeobjekt (0x5c Bytes), speichert die
 *   übergebene Ortskennung v bei Offset +0, setzt alle Funktionszeiger- und Statusfelder zurück, löscht die
 *   Öffnungszeiten- und Zeitfenster-Arrays (+0x2a und +0x32) mit memset (f_145300), setzt den
 *   Standard-gebäudetyp bei +0x54 auf 8 und trägt die Basis-Methodentabelle d_1bb248 bei Offset +0x58 ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das zu initialisierende Gebäudeobjekt sowie die
 *   16-Bit-Ortskennung v entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p zurück.
 === Ende Beschreibung === */
int f_0b8490(int p, short v)
{
  char *q = (char *)p + 10;
  I32(q, 0x4e) = (int)d_1bb248;
  *(volatile short *)((char *)q - 10) = v;
  I32(q, 0) = 0;
  I32(q, 4) = 0;
  I32(q, 8) = 0;
  char *r = (char *)p + 0x16;
  I32(r, 0) = 0; I32(r, 4) = 0; I32(r, 8) = 0;
  I32(p, 0x22) = 0;
  W16(p, 0x26) = 0;
  W16(p, 0x28) = 0;
  W16(p, 0x4e) = 0;
  I32(p, 0x50) = 0;
  I32(p, 0x54) = 8;
  f_145300(p + 0x2a, 0, 8);
  f_145300(p + 0x32, 0, 0x1c);
  return p;
}
//@ f_0b8520
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Basisdestruktor stellt beim Abbau eines Gebäudeobjekts den Zeiger auf die
 *   Basis-Methodentabelle d_1bb248 bei Offset +0x58 wieder her.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das abzubauende Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8520(int p)
{
  I32(p, 0x58) = (int)d_1bb248;
}
