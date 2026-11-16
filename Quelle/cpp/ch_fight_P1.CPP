/* === Beschreibung (Katalog) ===
 * Einheit ch_fight (0x00030024 - 0x000307d0)
 *
 * Überblick
 *
 * Die Einheit ch_fight implementiert die zentrale Schadensberechnung für Heldenangriffe im Rundenkampf
 * (CH_FIGHT.CPP) - das direkte Gegenstück zur Angriffs- und Waffenschadensberechnung aus *Schicksalsklinge* und
 * *Sternenschweif*. Sie ermittelt für Nahkampf-, Fernkampf- und waffenlose Angriffe eines Helden den
 * Grundschaden der Waffe, verrechnet Körperkraft-Zuschläge, Entfernungsmodifikatoren im Fernkampf, Sonderboni
 * heiliger oder magischer Waffen gegen Untote und Dämonen, Waffengifte (Schurkengift, Arax, Angstgift,
 * Schlafgift, Kukris, Goldleim usw.), kritische Treffer und den Rüstungsschutz des getroffenen Gegners.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P1 1/1 gleich
// ch_fight.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x030080-0x0307D0
#include <string.h>
int f_030e20(int p1, int p2);
short f_0350b0(int p1);
signed char f_042350(int p1);
signed char f_0423f0(int p1);
signed char f_0424e0(int p1);
int f_042650(int p1, int p2);
short f_042960(int p1);
signed char f_042a40(int p1, int p2);
unsigned short f_042a60(char *p1, short p2);
int f_042a90(int p1, int p2, int p3);
int f_042e10(int p1, int p2);
short f_042fd0(char *p1, short p2);
int f_043000(int p1, int p2, int p3);
signed char f_043030(int p1, int p2);
int f_043060(int p1, int p2, int p3);
signed char f_043250(int p1);
int f_0432b0(int p1);
short f_044c90(int p1, int p2, int p3);
int f_069460();
short f_071e20(int p1, int p2, int p3, int p4);
int f_071e90(unsigned char p1, short *p2, short *p3);


signed char f_0cf950(int p1);
short f_0cfa10(int p1);
int f_0cfae0(int p1, int p2);
int f_0cfb10(int p1, int p2);
signed char f_0cfbb0(int p1);
int f_0cfbc0(int p1, int p2);
signed char f_0cfc10(int p1);
int f_0cfe00(int p1, int p2);
signed char f_0cfe30(int p1);
int f_0cff90(int p1, int p2);
int f_0cffc0(int p1, int p2);
signed char f_0d0080(int p1);
int f_0d0440(int p1);
int f_0d0480(int p1);
int f_0d06c0(int p1);
int f_0d06f0(int p1);
signed char f_0d54c0(int p1);
short f_0de820(int p1);
short f_145760(int p1, int p2);
short f_1457e0(short p1);
short f_145850(int p1, int p2, int p3);
short f_149360(int p1, int *p2);
extern int d_1a077c;
extern signed char d_1a43bc[];
extern signed char d_1a43c3[];
extern signed char d_1a441c[];
extern signed char d_1a441d[];
extern signed char d_1a441e[];
extern signed char d_1a4420[];
extern char d_1bd928;
extern char d_1bfaec;
extern int d_1c0004;

//@ f_030080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die endgültigen Schadenspunkte (dmg), die der Held p1 bei einem erfolgreichen
 *   Angriff gegen ein Monster (p3 == 0 oder p3 == 2) oder ein anderes Gruppenmitglied (p3 == 1) verursacht:
 *   1. Grundschaden: Liest die in der rechten Hand (Slot 3) getragene Waffe. Ist sie im Kampf nutzbar (f_0350b0
 *     != -1), wird ihr Würfelschaden (table[0] W6 + table[1]) aus der Waffentabelle d_1a441c gewürfelt
 *     (Unterwasser in den Bereichen 7 und 9 gedrittelt, falls die Waffe nicht in der Unterwasser-Ausnahmeliste
 *     d_1a077c steht); ohne gültige Waffe macht der Faustkampf 1W6 Schaden.
 *   2. Fernkampf vs. Nahkampf: Bei Fernkampfwaffen (table[4] != -1) wird die Distanz auf dem Kampffeld
 *     (f_071e20) in eine von sieben Entfernungszonen (0..6) eingeteilt, eine zusätzliche Schuss-/Wurfprobe
 *     f_044c90 abgelegt und bei einem Schuss mit Pfeil/Bolzen 0x1a3 in der linken Hand (Slot 12) +4 Schaden
 *     addiert; im Nahkampf wird ab einer Körperkraft oberhalb des Waffen-KK-Zuschlagswerts (table[2]) die
 *     Differenz (KK - KK_Basis) addiert.
 *   3. Spezialwaffen gegen besondere Gegner: Bestimmte Waffen erhalten Zusatzschaden gegen bestimmte
 *     Monsterklassen, etwa Waffe 0xac (+1 gegen Untote), 0xc1 und 0xc8 (4..25 bzw. 20..99 Schaden und
 *     Verwandlung der Waffe in 14 bzw. 109), 0xd6 (+4 gegen Untote) sowie 0x15c (+10 gegen Dämonen/Endgegner).
 *   4. Waffengifte: Ist die Waffe (oder bei Schusswaffen das Geschoss in Slot 12) vergiftet (f_043030 > 0), wird
 *     eine Giftladung abgezogen und - falls der Rohschaden den Rüstungsschutz des Ziels übersteigt (severity ==
 *     1) - die Giftwirkung (wound = 1..11) ausgelöst (Zusatzschaden, Lähmung, Panik oder Attributsabzug).
 *     *(Hinweis: Bei wound == 2 gegen ein Gruppenmitglied p3 == 1 springt der Code zu wound_roll und addiert 1W6
 *     Schaden statt der Arax-Abzüge.)*
 *   5. Verdopplung und Rüstungsschutz: Nach eventueller Verdopplung (f_043250) wird der Rüstungsschutz des Ziels
 *     abgezogen (und falls das globale Flag d_1bfaec == 0 ist, zur Hälfte wieder gutgeschrieben),
 *     Unverwundbarkeitsflags (f_0cfe30, f_0cfc10) geprüft und der Schaden auf maximal Lebenspunkte_Ziel + 1
 *     begrenzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf den angreifenden Helden p1, den Zeiger auf das
 *   getroffene Ziel p2 sowie den Zieltyp p3 (0 = normaler Angriff auf Monster, 1 = Angriff auf Helden, 2 =
 *   Sonderangriff auf Monster) und gibt die berechneten Schadenspunkte als short zurück.
 * - Wichtige Variablen: Ausgewertet werden die Waffentabelle d_1a441c, die Entfernungstabelle d_1a43bc, die
 *   Item-Datenbank d_1c2c40, das globale Rüstungsflag d_1bfaec sowie die Charakter- und Monsterwerte von p1 und
 *   p2.
 === Ende Beschreibung === */
static inline int objekt_offset(const int &offset) { return *(int *)((*(int*)&d_1c2c40) + offset); }
static inline int other_get(const int &v) { return v; }
short f_030080(int p1, int p2, short p3)
{
  short target;
  short y1;
  short x2;
  short usable;
  short x1;
  short item;
  unsigned char position;
  short zone;
  short dmg;
  int severity;
  int actor;
  int other;
  short defence;
  signed char * table;
  signed char place;
  short wound;
  short check;
  short distance;
  int attack = 0; // KRUECKE toter Startwert fuer Watcom-Namenssortierung
  short y2;
  signed char * weapon;
  short delta;
  short capacity;
  signed char kind;
  signed char value;

  delta = 0;
  y2 = x2 = y1 = x1 = 0;
  other = actor = 0;
  wound = 0;
  place = 3;
  if (d_1bd928) f_069460();
  if (!p3 || p3 == 2) actor = p2;
  else other = p2;

  item = (short)f_042a60((char*)p1, 3);
  if ((usable = f_0350b0(p1)) != -1) {
    int off = item * 4; int base = ((*(int*)&d_1c2c40) & 0) ? 0 : (*(int*)&d_1c2c40); // KRUECKE Basis-Lebensdauer
    kind = ((signed char)(((RivaItemDefinition*)(*(int *)(off + base)))->f_0a78a0()));
    table = d_1a441c + kind * 10;
    dmg = f_145850(table[0], 6, table[1]);
    check = f_0de820(d_1c0004);
    if ((check == 7 || check == 9) &&
        f_149360(item, &d_1a077c) == -1) {
      dmg /= 3;
    }
    if (table[4] != -1) {
      position = f_0d54c0(p1);
      f_071e90(++position, &x1, &y1);
      if (f_071e90((unsigned char)f_0432b0(p1), &x2, &y2) == 1) {
        distance = f_071e20((short)x1, (short)y1, (short)x2, (short)y2);
        if (distance <= 2) zone = 0;
        else if (distance <= 4) zone = 1;
        else if (distance <= 6) zone = 2;
        else if (distance <= 9) zone = 3;
        else if (distance <= 15) zone = 4;
        else if (distance <= 20) zone = 5;
        else zone = 6;
        weapon = d_1a43bc + table[4] * 8;
        if (p3 == 1) {
          if (f_042350(other_get(other)) == 6) target = 2;
          else target = 3;
        } else {
          target = f_0d0080(actor);
        }
        attack = (signed char)(zone * 2 + weapon[7] - target * 2);
        int item_offset = item * 4;
        defence = (((signed char)(((RivaItemDefinition*)(objekt_offset(item_offset)))->f_0a78b0())) == 8) ? 8 : 7;
        if (f_044c90(p1, defence, attack) > 0)
          { int ti = (int)table; ti = *(signed char *)(ti + 4); ti <<= 3; delta = (short)d_1a43bc[zone + ti]; }
        else
          delta = -dmg;
        int *inventory = (int *)(*(int*)&d_1c2c40);
        dmg += delta;
        if (((signed char)(((RivaItemDefinition*)(inventory[item]))->f_0a78b0())) == 7) place = 12;
        if ((short)f_042a60((char*)p1, 12) == 0x1a3) dmg += 4;
      } else {
        dmg = 0;
      }
    } else {
      delta = f_042a40(p1, 6) - (short)table[2];
      if (delta > 0) dmg += delta;
    }
  } else {
    dmg = f_1457e0(6);
  }

  if (d_1bd928) f_069460();
  if (!p3 || p3 == 2) {
    if (item == 0xac && (f_0d0440(actor) || f_0d0480(actor))) {
      dmg++;
    } else if (item == 0xc1) {
      if (f_0d06c0(actor)) dmg = f_145760(4, 25);
      else dmg = f_145760(20, 99);
      f_042a90(p1, 3, 14);
    } else if (item == 0xc8) {
      if (f_0d06c0(actor)) dmg = f_145760(4, 25);
      else dmg = f_145760(20, 99);
      f_042a90(p1, 3, 109);
    } else if (item == 0xd6 && f_0d0440(actor)) {
      dmg += 4;
    } else if (item == 0x15c && f_0d06f0(actor)) {
      dmg += 10;
    }
  }
  dmg += (short)*(signed char *)(p1 + 0xaa);
  if (d_1bd928) f_069460();

  severity = 0;
  if (f_043030(p1, place) > 0) {
    wound = f_042fd0((char*)p1, place);
    if (((!p3 || p3 == 2) && (short)dmg > f_0cf950(actor)) ||
        (p3 == 1 && (short)dmg > f_0423f0(other_get(other)))) severity = 1;
    f_043060(p1, place, (signed char)(f_043030(p1, place) - 1));
    if (f_043030(p1, place) <= 0) f_043000(p1, place, 0);
  }
  if (severity && wound != (short)0) {
    if ((!p3 || p3 == 2) && f_0d06c0(actor)) {
      switch ((unsigned short)(wound - 1)) {
        case 9: dmg += f_145760(1, 5); break;
        case 0: case 5: case 10: dmg++; break;
        case 7: dmg += f_145760(4, 25); break;
      }
    } else if ((p3 && p3 != 2) || !f_0cfc10(actor)) {
      switch ((unsigned short)(wound - 1)) {
        case 9: dmg += f_145760(5, 25); break;
        case 10: dmg += f_145760(3, 8); break;
        case 0:
        wound_roll:
          dmg += f_145760(1, 6);
          break;
        case 1:
          if (p3 && p3 != 2) goto wound_roll;
          f_0cfbc0(actor, (signed char)(f_0cfbb0(actor) - 2));
          f_0cfae0(actor, -1);
          f_0cfb10(actor, -1);
          break;
        case 3:
          if (!p3 || p3 == 2) f_0cfe00(actor, 1);
          else f_030e20(other_get(other), 1);
          break;
        case 5: dmg += f_145760(1, 3); break;
        case 7: dmg += f_145760(20, 99); break;
        case 2:
          if (!p3 || p3 == 2) {
            f_0cffc0(actor, 1);
            f_0cff90(actor, 0);
          } else f_042650(other_get(other), 1);
          break;
      }
    }
  }

  if (f_043250(p1)) dmg *= 2;
  if (!p3 || p3 == 2) {
    if (!p3) {
      value = f_0cf950(actor);
      short value16 = value;
      signed char gate = d_1bfaec;
      dmg -= value16;
      if (gate == 0) {
        dmg = (short)dmg;
        dmg += value / 2;
      }
    } else dmg += f_1457e0(10);
    if (f_0cfe30(actor)) dmg = 0;
    if (f_0cfc10(actor) && !f_042e10(p1, 3)) dmg = 0;
    capacity = f_0cfa10(actor);
    if ((short)dmg > capacity) {
      dmg = f_0cfa10(actor);
      dmg++;
    }
  } else {
    dmg -= (short)f_0423f0(other_get(other));
    if (f_0424e0(other_get(other))) dmg = 0;
    capacity = f_042960(other_get(other));
    if ((short)dmg > capacity) {
      dmg = f_042960(other_get(other));
      dmg++;
    }
  }
  if (d_1bd928) f_069460();
  return dmg;
}
