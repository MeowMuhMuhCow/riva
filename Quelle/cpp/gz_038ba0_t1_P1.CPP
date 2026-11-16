/* === Beschreibung (Katalog) ===
 * Einheit gz_038ba0_t1 (0x038ba0 - 0x03aa20)
 *
 * Überblick
 * Diese Einheit stellt eine umfangreiche Sammlung von Gruppen-Such-, Auswahl- und Filterfunktionen bereit (etwa
 * um den besten oder schlechtesten Helden für eine Talent-, Zauber- oder Attributsprobe zu ermitteln, zufällige
 * Gruppenmitglieder auszuwählen oder ein Helden-Auswahlmenü anzuzeigen) und enthält darüber hinaus mit f_039cf0
 * die zentrale Tick-Funktion für den Krankheitsverlauf aller neun Krankheiten im Spiel.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 36/42 gleich (suche.py 29.10.2026, Basis gz_038ba0_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 4 gleich (vorher 4), Rest 1488 (vorher 1489)
// gz_038ba0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x038BA0-0x03AC50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define W4(a,i) (*(int*)((a)+(i)*4))
typedef signed char c8;
typedef signed char CNTT;
#define CNT(p) (*(CNTT*)((p)+0x1c))
extern signed char d_1a9670;
extern int d_1bc88c;
extern int d_1bc8f0;
extern short d_1bd90c;
extern int d_1bf230;
extern int d_1c0004;
extern short d_1c2198;
extern int d_1c2a80;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1bc8a8[];
extern int d_1c29c4[];
extern signed char d_1a6ad0[];
extern signed char d_1a6ad1[];
extern signed char d_1a6ad2[];
int f_030e20(int p1, int p2);
int f_030fe0(int p1);
short f_0350b0(int p1);
c8 f_03ad80(int p1, int p2);













signed char f_0435c0(int p1, int p2);
int f_0435e0(int p1, int p2, int p3);
c8 f_043600(int p1, int p2);
int f_043620(int p1, int p2, int p3);
int f_043640(int p1, int p2, int p3);
c8 f_043670(int p1, int p2);
int f_0436b0(int p1, int p2, int p3);
c8 f_0436e0(int p1, int p2);
int f_043720(int p1, int p2, int p3);
int f_043750(int p1, int p2);
int f_043770(int p1, int p2, int p3);
c8 f_043a80(int p1, int p2);
int f_044230(int p1, int p2);
int f_0442b0(int p1, int p2);
int f_044300(int p1, int p2);
int f_045430(int p1, int p2, int p3);
int f_0bbf00(int p1);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820(...);
short f_0c0020(int p1, int p2);
short f_0ce070(int p1);
int f_0d49b0(int p1);
int f_0d4a60(int p1);
short f_0d54f0(int p1, int p2);
int f_0de7d0(int p1, int p2);
int f_0e3360(int p1);
int f_0e33a0(int p1, int p2);
short f_0e33b0(int p1);
short f_10cae0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int);
int f_133fe0(int p1, int p2);
short f_1457e0(int p1);
short f_145850(int p1, int p2, int p3);
int f_038f20(int p1, int p2, short p3, short p4, short p5);
unsigned f_039510(int p1);
int f_039960(int p1, int p2, int *p3);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_038ba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wählt aus einer Gruppe p1 zufällig einen lebenden Helden (!f_042470) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den zufällig
 *   gezogenen lebenden Helden oder 0 (bei leerer Gruppe) zurück.
 * - Wichtige Variablen: CNT(p1) (*(signed char *)(p1 + 0x1c)) gibt die Anzahl der Helden in der Gruppe an;
 *   W4(p1, i) liest den Heldenzeiger aus Slot 0..6.
 === Ende Beschreibung === */
int f_038ba0(int p1)
{
  int p1_00; c8 cVar1; short sVar2;
  if (CNT(p1)) {
    do {
      do {
        sVar2 = f_1457e0(7);
        p1_00 = W4(p1, (short)(sVar2 - 1));
      } while (p1_00 == 0);
      cVar1 = ((c8)(f_042470((struct hero *)(p1_00))));
    } while (cVar1);
    return p1_00;
  }
  return 0;
}
//@ f_038be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wählt aus einer Gruppe p1 zufällig einen handlungsfähigen Helden (f_0d49b0 !=
 *   0) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ausgewählten
 *   Helden oder 0 zurück.
 * - Wichtige Variablen: f_0d49b0 prüft, ob ein Held weder tot noch bewusstlos, versteinert oder gelähmt ist.
 === Ende Beschreibung === */
int f_038be0(int p1)
{
  short sVar1; int iVar2; int p1_00;
  if (CNT(p1) != 0) {
    do {
      do {
        sVar1 = f_1457e0(7);
        p1_00 = W4(p1, (short)(sVar1 - 1));
      } while (p1_00 == 0);
      iVar2 = f_0d49b0(p1_00);
    } while (!iVar2);
  } else {
    p1_00 = 0;
  }
  return p1_00;
}
//@ f_038c20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wählt aus einer Gruppe p1 völlig zufällig irgendeinen belegten Heldenslot aus
 *   (unabhängig davon, ob der Held lebt oder handlungsfähig ist).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Gewürfelt wird über f_1457e0(7) ein Slot-Index zwischen 0 und 6.
 === Ende Beschreibung === */
int f_038c20(int p1)
{
  short sVar1; int p1_00;
  if (*(signed char *)(p1 + 0x1c) != 0) {
    do {
      sVar1 = f_1457e0(7);
      p1_00 = W4(p1, (short)(sVar1 - 1));
    } while (p1_00 == 0);
    return p1_00;
  }
  return 0;
}
//@ f_038c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion liefert den ersten lebenden und handlungsfähigen Helden einer Gruppe (den
 *   aktuellen Gruppenanführer für Dialoge und Proben).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ersten
 *   handlungsfähigen Helden oder ersatzweise den Basiszeiger d_1bc8f0 zurück.
 * - Wichtige Variablen: Die Schleife durchläuft die Gruppenslots 0..6 in aufsteigender Reihenfolge.
 === Ende Beschreibung === */
int f_038c40(int p1)
{
  int p1_00; c8 cVar1; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if (p1_00 != 0) {
      cVar1 = ((c8)(f_042470((struct hero *)(p1_00))));
      if (cVar1) continue;
      iVar1 = f_0d49b0(p1_00);
      if (iVar1 != 0) return p1_00;
    }
  }
  return d_1bc8f0;
}
//@ f_038c80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion gibt den ersten überhaupt belegten Heldenslot einer Gruppe zurück (auch wenn
 *   dieser Held tot oder bewusstlos sein sollte).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den ersten Heldenzeiger != 0 oder 0
 *   zurück.
 * - Wichtige Variablen: Es werden lediglich die sieben Zeiger W4(p1, 0..6) auf Ungleichheit mit 0 geprüft.
 === Ende Beschreibung === */
int f_038c80(int p1)
{
  int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    iVar1 = W4(p1, sVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}
//@ f_038cb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht den *zweiten* lebenden und handlungsfähigen Helden einer Gruppe heraus
 *   (beispielsweise für Dialoge oder Ereignisse, an denen zwei Gruppenmitglieder beteiligt sind).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den zweiten
 *   handlungsfähigen Helden zurück, oder 0, falls weniger als zwei Helden handlungsfähig sind.
 * - Wichtige Variablen: Der Zähler sVar4 zählt die gefundenen handlungsfähigen Gruppenmitglieder.
 === Ende Beschreibung === */
short f_038cb0(int p1)
{
  int p1_00; short sVar3; short sVar4;
  sVar4 = 0;
  for (sVar3 = 0; sVar3 <= 6; sVar3 = sVar3 + 1) {
    p1_00 = W4(p1, sVar3);
    if (p1_00 != 0) {
      if (((c8)(f_042470((struct hero *)(p1_00))))) continue;
      if (f_0d49b0(p1_00) != 0) {
        sVar4 = sVar4 + 1;
        if (sVar4 != (short)1) return p1_00;
      }
    }
  }
  return 0;
}
//@ f_038d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt den am schwersten verwundeten lebenden Helden der Gruppe, also
 *   denjenigen mit der größten Differenz zwischen maximaler und aktueller Lebensenergie.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den Helden mit den
 *   meisten fehlenden Lebenspunkten zurück (oder 0, falls alle lebenden Helden unverletzt sind).
 * - Wichtige Variablen: Die Differenz diff wird aus f_042970(item) - f_042960(item) (LE_max - LE_aktuell)
 *   berechnet.
 === Ende Beschreibung === */
int f_038d00(int p1)
{
  short diff; short i; short max; int best; int item;
  max = 0;
  best = 0;
  for (i = 0; i <= 6; i = i + 1) {
    item = W4(p1, i);
    if (item != 0) {
      if (!((c8)(f_042470((struct hero *)(item))))) {
        diff = f_042970((struct hero *)(item)) - f_042960((struct hero *)(item));
        if (diff > max) {
          max = diff;
          best = item;
        }
      }
    }
  }
  if (max != 0) return best;
  return (int)max;
}
//@ f_038d70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion stellt alle handlungsfähigen Helden der Gruppe p1 (mit Ausnahme eines eventuell
 *   in d_1a9670 ausgeschlossenen Slots) für ein Auswahlmenü zusammen und ruft f_038f20 mit dem Abfragetext p2
 *   auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Text-ID p2 und gibt über den
 *   Tail-Call f_038f20 den vom Spieler gewählten Heldenzeiger (oder 0) zurück.
 * - Wichtige Variablen: d_1c29c4 nimmt die formatierten Namensstrings der wählbaren Helden auf, und d_1bc8a8
 *   speichert die zugehörigen Heldenzeiger.
 === Ende Beschreibung === */
void f_038d70(int p1, int p2)
{
  short sVar1; short sVar4; short sVar6; int p1_00; int uVar3;
  sVar1 = f_0c0020((int)&d_1c2c64, 3);
  sVar4 = 0;
  for (sVar6 = 0; sVar6 <= 6; sVar6 = sVar6 + 1) {
    p1_00 = W4(p1, sVar6);
    if (p1_00 != 0) {
      if ((f_0d49b0(p1_00) != 0) && (sVar6 != d_1a9670)) {
        uVar3 = f_133fe0((int)&d_1c3498, ((int)(f_0422b0((struct hero *)(p1_00)))));
        uVar3 = (uVar3 & 0) ? 0 : uVar3; // Haelt die Registerreihenfolge bei Gleichstand
        d_1c29c4[sVar4] = uVar3;
        d_1bc8a8[sVar4] = p1_00;
        sVar4 = sVar4 + 1;
      }
    }
  }
  f_038f20(p1, p2, (int)sVar4, (int)sVar1, 0);
}
//@ f_038e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion stellt alle handlungsfähigen *magiebegabten* Helden (f_042a10 != 0) der Gruppe
 *   p1 für ein Auswahlmenü zusammen und zeigt dieses über f_038f20 an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Text-ID p2 und gibt den ausgewählten
 *   magiebegabten Helden (oder 0) zurück.
 * - Wichtige Variablen: Gefiltert wird zusätzlich auf f_042a10(p1_00) != 0 sowie sVar6 != d_1a9670.
 === Ende Beschreibung === */
void f_038e10(int p1, int p2)
{
  short sVar1; short sVar4; short sVar6; int p1_00; int a;
  sVar1 = f_0c0020((int)&d_1c2c64, 3);
  sVar4 = 0;
  for (sVar6 = 0; sVar6 <= 6; sVar6 = sVar6 + 1) {
    p1_00 = W4(p1, sVar6);
    if (p1_00 != 0) {
      if ((f_0d49b0(p1_00) != 0) && (sVar6 != d_1a9670) && (f_042a10((struct hero *)(p1_00)) != 0)) {
        a = ((int)(f_0422b0((struct hero *)(p1_00))));
        a = (a & 0) ? 0 : a; // Haelt die Registerreihenfolge bei Gleichstand
        d_1c29c4[sVar4] = f_133fe0((int)&d_1c3498, a);
        d_1bc8a8[sVar4] = p1_00;
        sVar4 = sVar4 + 1;
      }
    }
  }
  f_038f20(p1, p2, (int)sVar4, (int)sVar1, 0);
}
//@ f_038e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion stellt *alle* vorhandenen Helden der Gruppe p1 (auch bewusstlose, verletzte
 *   oder tote Helden, außer dem Slot d_1a9670) für ein Auswahlmenü zusammen - etwa zur Auswahl eines Patienten
 *   beim Heilen oder Verbinden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Text-ID p2 und gibt den vom Spieler
 *   ausgewählten Heldenzeiger (oder 0) zurück.
 * - Wichtige Variablen: Wie in f_038d70 werden die Namen in d_1c29c4 und die Heldenzeiger in d_1bc8a8 abgelegt.
 === Ende Beschreibung === */
void f_038e90(int p1, int p2)
{
  int p1_00; short sVar1; int iVar2; int uVar3; short sVar4; short sVar5;
  sVar1 = f_0c0020((int)&d_1c2c64, 3);
  sVar4 = 0;
  for (sVar5 = 0; sVar5 <= 6; sVar5 = sVar5 + 1) {
    p1_00 = W4(p1, sVar5);
    if ((p1_00 != 0) && (sVar5 != d_1a9670)) {
      uVar3 = ((int)(f_0422b0((struct hero *)(p1_00))));
      uVar3 = f_133fe0((int)&d_1c3498, uVar3);
      d_1c29c4[sVar4] = uVar3;
      d_1bc8a8[sVar4] = p1_00;
      sVar4 = sVar4 + 1;
    }
  }
  f_038f20(p1, p2, (int)sVar4, (int)sVar1, 0);
}
//@ f_038f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese gemeinsame Hilfsfunktion zeigt das von f_038d70, f_038e10 oder f_038e90 vorbereitete
 *   Helden-Auswahlmenü auf dem Bildschirm an, setzt das Ausschluss-Flag d_1a9670 auf 0xff zurück und gibt den
 *   ausgewählten Heldenzeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, die Titel-Text-ID p2, die Anzahl wählbarer
 *   Helden p3, den vorherigen Dialogmodus p4 und ein Pflichtwahl-Flag p5 (1 = Rechtsklick-Abbruch nicht erlaubt)
 *   und gibt den gewählten Heldenzeiger aus d_1bc8a8 oder 0 zurück.
 * - Wichtige Variablen: Handelt es sich um die aktive Hauptgruppe d_1c0004, wird vor dem Dialog für alle
 *   Gruppenmitglieder der aktuelle Gruppenstatus über f_042440 synchronisiert.
 === Ende Beschreibung === */
int f_038f20(int p1, int p2, short p3, short p4, short p5)
{
  short local_14; int uVar3; short sVar4; short local_10; short sVar1; short result;
  local_14 = -1;
  d_1a9670 = 0xff;
  if (p1 == d_1c0004) {
    sVar1 = f_0ce070(d_1c0004);
    for (sVar4 = 0; sVar4 <= 6; sVar4 = sVar4 + 1) {
      if (W4(p1, sVar4) != 0) {
        f_042440((struct hero *)(W4(p1, sVar4)), (int)sVar1);
      }
    }
  }
  if (p3) {
    if ((short)p5 == 1) {
      local_10 = f_0e33b0((int)&d_1c2c64);
    }
    do {
      if (p5) {
        f_0e33a0((int)&d_1c2c64, (int)local_10);
      }
      result = f_0bf820((int)&d_1c2c64, p2, (short)p3,
                          d_1c29c4[0], d_1c29c4[1], d_1c29c4[2],
                          d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]);
      result = result - 1;
    } while ((result == -2) && ((short)p5 == 1));
    if (result != -2) {
      local_14 = result;
    }
  }
  f_0c0020((int)&d_1c2c64, (int)(short)p4);
  if (local_14 == -1) {
    uVar3 = 0;
  } else {
    uVar3 = d_1bc8a8[local_14];
  }
  return uVar3;
}
//@ f_039040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 nach einem angeschlossenen NPC-Begleiter (f_042400 != 0)
 *   und gibt dessen Heldenzeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ersten NPC in
 *   der Gruppe oder 0 zurück.
 * - Wichtige Variablen: Das Feld f_042400 (p1_00 + 0x22) kennzeichnet computergesteuerte Begleiter.
 === Ende Beschreibung === */
int f_039040(int p1)
{
  int p1_00; c8 cVar1; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if ((p1_00 != 0) && (cVar1 = ((c8)(f_042400((struct hero *)(p1_00)))), cVar1)) {
      return p1_00;
    }
  }
  return 0;
}
//@ f_039070
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion prüft, ob sich in der Gruppe p1 ein toter Held (f_042470 != 0) befindet, und
 *   gibt dessen Zeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ersten toten
 *   Helden oder 0 zurück.
 * - Wichtige Variablen: f_042470 liest das Todes-Bit aus den Statusflags des Helden.
 === Ende Beschreibung === */
int f_039070(int p1)
{
  int p1_00; c8 cVar1; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if ((p1_00 != 0) && (cVar1 = ((c8)(f_042470((struct hero *)(p1_00)))), cVar1)) {
      return p1_00;
    }
  }
  return 0;
}
//@ f_0390a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 nach dem ersten magiebegabten Helden (f_042a10 != 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ersten
 *   Magiekundigen oder 0 zurück.
 * - Wichtige Variablen: f_042a10 prüft, ob die Charakterklasse des Helden >= 7 ist.
 === Ende Beschreibung === */
int f_0390a0(int p1)
{
  int p1_00; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if (p1_00 != 0) {
      iVar1 = f_042a10((struct hero *)(p1_00));
      if (iVar1 != 0) {
        return p1_00;
      }
    }
  }
  return 0;
}
//@ f_0390d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 nach dem ersten magiebegabten Helden, der zugleich
 *   einsatzfähig ist (f_0d4a60 == 1).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ersten
 *   einsatzfähigen Magiekundigen oder 0 zurück.
 * - Wichtige Variablen: f_0d4a60 prüft die volle Einsatzfähigkeit eines Helden für aktive Aktionen.
 === Ende Beschreibung === */
int f_0390d0(int p1)
{
  int p1_00; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if (p1_00 != 0) {
      iVar1 = f_042a10((struct hero *)(p1_00));
      if (iVar1 != 0) {
        iVar1 = f_0d4a60(p1_00);
        if (iVar1 == 1) {
          return p1_00;
        }
      }
    }
  }
  return 0;
}
//@ f_039110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion blättert ausgehend vom aktuellen Helden p2 zyklisch vorwärts zum nächsten
 *   magiebegabten Helden in der Gruppe p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den aktuellen Heldenzeiger p2 und gibt
 *   den nächsten magiebegabten Helden in der Gruppe zurück.
 * - Wichtige Variablen: Am Ende der Gruppengröße *(signed char *)(p1 + 0x1c) springt der Laufindex wieder auf 0.
 === Ende Beschreibung === */
int f_039110(int p1, int p2)
{
  int p1_00; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if (p1_00 == p2) break;
  }
  do {
    sVar2 = sVar2 + 1;
    if ((int)sVar2 == (int)*(signed char *)(p1 + 0x1c)) {
      sVar2 = 0;
    }
    p1_00 = W4(p1, sVar2);
    if (p1_00 != 0) {
      iVar1 = f_042a10((struct hero *)(p1_00));
      if (iVar1 != 0) break;
    }
  } while (1);
  return p1_00;
}
//@ f_039160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion blättert ausgehend vom aktuellen Helden p2 zyklisch rückwärts zum vorherigen
 *   magiebegabten Helden in der Gruppe p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den aktuellen Heldenzeiger p2 und gibt
 *   den vorherigen magiebegabten Helden zurück.
 * - Wichtige Variablen: Unterschreitet der Index 0, wird er auf *(signed char *)(p1 + 0x1c) - 1 gesetzt.
 === Ende Beschreibung === */
int f_039160(int p1, int p2)
{
  int p1_00; int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    p1_00 = W4(p1, sVar2);
    if (p1_00 == p2) break;
  }
  do {
    do {
      sVar2 = sVar2 - 1;
      if (sVar2 == -1) {
        sVar2 = *(signed char *)(p1 + 0x1c) - 1;
      }
      p1_00 = W4(p1, sVar2);
    } while (p1_00 == 0);
    iVar1 = f_042a10((struct hero *)(p1_00));
  } while (iVar1 == 0);
  return p1_00;
}
//@ f_0391b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion blättert ausgehend vom aktuellen Helden p2 zyklisch vorwärts zum nächsten
 *   belegten Heldenslot der Gruppe p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den aktuellen Heldenzeiger p2 und gibt
 *   den nächsten Heldenzeiger in der Gruppe zurück.
 * - Wichtige Variablen: Übersprungen werden lediglich leere Gruppenslots (W4(p1, sVar2) == 0).
 === Ende Beschreibung === */
int f_0391b0(int p1, int p2)
{
  int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    iVar1 = W4(p1, sVar2);
    if (iVar1 == p2) break;
  }
  do {
    sVar2 = sVar2 + 1;
    if ((int)sVar2 == (int)*(signed char *)(p1 + 0x1c)) {
      sVar2 = 0;
    }
    iVar1 = W4(p1, sVar2);
  } while (iVar1 == 0);
  return iVar1;
}
//@ f_0391f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion blättert ausgehend vom aktuellen Helden p2 zyklisch rückwärts zum vorherigen
 *   belegten Heldenslot der Gruppe p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den aktuellen Heldenzeiger p2 und gibt
 *   den vorherigen Heldenzeiger in der Gruppe zurück.
 * - Wichtige Variablen: Wie in f_039160 läuft der Index rückwärts über die Gruppengröße bei p1 + 0x1c.
 === Ende Beschreibung === */
int f_0391f0(int p1, int p2)
{
  int iVar1; short sVar2;
  for (sVar2 = 0; sVar2 <= 6; sVar2 = sVar2 + 1) {
    iVar1 = W4(p1, sVar2);
    if (iVar1 == p2) break;
  }
  do {
    sVar2 = sVar2 - 1;
    if (sVar2 == -1) {
      sVar2 = *(signed char *)(p1 + 0x1c) - 1;
    }
    iVar1 = W4(p1, sVar2);
  } while (iVar1 == 0);
  return iVar1;
}
//@ f_039230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wählt zufällig einen einsatzfähigen Helden der Gruppe p1 aus, der eine
 *   anzündbare Lichtquelle (Fackel oder Laterne) samt Zunderkästchen im Inventar trägt (f_0350b0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und einen gewünschten Slot-Filter p2 (-1 =
 *   beliebiger Inventarslot) und gibt den gefundenen Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Vor der Zufallsschleife prüft die Funktion über bVar1 und bVar2, ob überhaupt ein
 *   passender Held in der Gruppe existiert, um eine Endlosschleife zu verhindern.
 === Ende Beschreibung === */
short f_039230(int p1, int p2)
{
  int p1_00; int bVar1; int bVar2; short sVar3; short sVar4; int iVar5; int iVar6;
  bVar1 = 0;
  bVar2 = 0;
  for (sVar4 = 0; sVar4 <= 6; sVar4 = sVar4 + 1) {
    p1_00 = W4(p1, sVar4);
    iVar5 = f_0d4a60(p1_00);
    if (iVar5 != 0) {
      sVar3 = f_0350b0(p1_00);
      if (sVar3 >= 0) {
        bVar1 = 1;
      }
      if (sVar3 == (short)p2) {
        bVar2 = 1;
      }
    }
  }
  if (*(signed char *)(p1 + 0x1c) >= 1) {
    if (((short)p2 == -1) && (bVar1)) {
      do {
        do {
          sVar4 = f_1457e0(7);
          iVar5 = W4(p1, (short)(sVar4 - 1));
          sVar4 = f_0350b0(iVar5);
        } while (iVar5 == 0);
        iVar6 = f_0d4a60(iVar5);
      } while ((iVar6 == 0) || (sVar4 == -1));
      return iVar5;
    }
    if (((short)p2) && (bVar2)) {
      do {
        do {
          sVar4 = f_1457e0(7);
          iVar5 = W4(p1, (short)(sVar4 - 1));
          sVar4 = f_0350b0(iVar5);
        } while (iVar5 == 0);
        iVar6 = f_0d4a60(iVar5);
      } while ((iVar6 == 0) || (sVar4 != (short)p2));
      return iVar5;
    }
  }
  return 0;
}
//@ f_039320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt denjenigen einsatzfähigen Helden der Gruppe p1, der die besten
 *   Erfolgsaussichten für eine Probe auf das Talent p2 hat (höchste Summe aus den drei Prüfattributen des
 *   Talents und dem Talentwert selbst).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den Talentindex p2 (short) und gibt den
 *   Zeiger auf den besten Helden für dieses Talent zurück.
 * - Wichtige Variablen: Die drei Prüfattribute des Talents p2 werden aus d_1a6ad0[p2 * 4], d_1a6ad1[p2 * 4] und
 *   d_1a6ad2[p2 * 4] gelesen und mit dem Talentwert f_03ad80(actor, p2) addiert.
 === Ende Beschreibung === */
int f_039320(int p1, short p2)
{
  short highest;
  short first;
  short second;
  int list;
  int actor;
  int chosen;
  int result;
  short score;

  highest = -1;
  list = p1;
  for (first = 0; first <= 6; first++) {
    actor = W4(list, first);
    if (actor && !((c8)(f_042470((struct hero *)(actor)))) && f_0d49b0(actor)) {
      chosen = actor;
      goto found;
    }
  }
  chosen = d_1bc8f0;
found:
  result = chosen;
  for (second = 0; second <= 6; second++) {
    actor = W4(p1, second);
    if (actor && f_0d4a60(actor)) {
      score = ((c8)(f_042a40((struct hero *)(actor), d_1a6ad0[(short)p2 * 4])))
            + ((c8)(f_042a40((struct hero *)(actor), d_1a6ad1[(short)p2 * 4])))
            + ((c8)(f_042a40((struct hero *)(actor), d_1a6ad2[(short)p2 * 4])))
            + f_03ad80(actor, (short)p2);
      if (score > highest) {
        highest = score;
        result = actor;
      }
    }
  }
  return result;
}
//@ f_039420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Gegenstück-Funktion zu f_039320 ermittelt denjenigen einsatzfähigen Helden der Gruppe
 *   p1, der die *schlechtesten* Voraussetzungen für eine Probe auf das Talent p2 hat (etwa wenn der
 *   ungeschickteste Held über eine Falle stolpert oder beim Schleichen auffällt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den Talentindex p2 (short) und gibt den
 *   Zeiger auf den schwächsten Helden für dieses Talent zurück.
 * - Wichtige Variablen: Gesucht wird das Minimum der Summe aus den drei Prüfattributen (d_1a6ad0..d_1a6ad2) und
 *   dem Talentwert f_03ad80.
 === Ende Beschreibung === */
int f_039420(int p1, short p2)
{
  short lowest;
  short first;
  short second;
  int list;
  int actor;
  int chosen;
  int result;
  short score;

  lowest = 999;
  list = p1;
  for (first = 0; first <= 6; first++) {
    actor = W4(list, first);
    if (actor && !((c8)(f_042470((struct hero *)(actor)))) && f_0d49b0(actor)) {
      chosen = actor;
      goto found;
    }
  }
  chosen = d_1bc8f0;
found:
  result = chosen;
  for (second = 0; second <= 6; second++) {
    actor = W4(p1, second);
    if (actor && f_0d4a60(actor)) {
      score = ((c8)(f_042a40((struct hero *)(actor), d_1a6ad0[(short)p2 * 4])))
            + ((c8)(f_042a40((struct hero *)(actor), d_1a6ad1[(short)p2 * 4])))
            + ((c8)(f_042a40((struct hero *)(actor), d_1a6ad2[(short)p2 * 4])))
            + f_03ad80(actor, (short)p2);
      if (score < lowest) {
        lowest = score;
        result = actor;
      }
    }
  }
  return result;
}
//@ f_039510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Weiterleitungsfunktion ruft f_043cd0 auf (Prüffunktion auf einen bestimmten
 *   Heldenstatus, die als Callback-Zeiger in f_039580 verwendet wird).
 * - Eingaben und Rückgabe: Die Funktion wird als Prädikat übergeben und leitet direkt an f_043cd0 weiter.
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_043cd0(void);
void f_039510(void)
{
    f_043cd0();
}

//@ f_039520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion prüft, ob der erste in der Hauptgruppe d_1c0004 gefundene NPC die NPC-Kennung 7
 *   oder 8 besitzt, und gibt in diesem Fall dessen Heldenzeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den Heldenzeiger des NPCs (ID 7 oder
 *   8) oder 0 zurück.
 * - Wichtige Variablen: Abgefragt wird das NPC-Feld über f_042400(q) in der Hauptgruppe d_1c0004.
 === Ende Beschreibung === */
int f_039520(void)
{
  int r;
  short i;
  int p;
  int q;
  int *a;
  a = (int *)d_1c0004;
  r = 0;
  for (i = 0; i <= 6; i++) {
    q = a[i];
    if (q == 0) continue;
    switch (((c8)(f_042400((struct hero *)(q))))) {
      case 0: continue;
      default: goto found;
    }
  }
  q = 0;
found:
  p = q;
  if (p != 0 && (((c8)(f_042400((struct hero *)(p)))) == 8 || ((c8)(f_042400((struct hero *)(p)))) == 7)) r = p;
  return r;
}
//@ f_039580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 nach einem Helden, der die Bedingung f_039510 (f_043cd0)
 *   erfüllt, und prüft optional (p2, p3), ob sowohl dieser Held als auch ein etwaiger NPC (ID 7 oder 8)
 *   einsatzfähig sind.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 sowie zwei Prüf-Flags p2 und p3 und gibt den
 *   gefundenen Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: check zeigt auf f_039510, und other_value hält den gefundenen NPC aus d_1c0004.
 === Ende Beschreibung === */
int f_039580(int p1, int p2, int p3)
{
  unsigned (*check)(int);
  int other;
  int result;
  int found;
  int item;
  short j = 0;
  int index;
  short i;
  int list;

  list = p1;
  check = f_039510;
  result = 0;
  found = 0;
  item = 0;
  for (i = 0; i < 7 && found == 0; i++) {
    item = f_0de7d0(list, i);
    if (item != 0) {
      if (check(item) == 1) found = item;
    }
  }

  p1 = found;
  int *tb = (int *)d_1c0004;
  other = 0;
  for (j=0;;j++) {
    index=j;
    index=(index&0)?0:index; // Haelt den Schleifenindex im Register
    if(index>6)break;
    item = tb[index];
    if (item == 0) continue;
    switch (((c8)(f_042400((struct hero *)(item))))) {
      case 0: continue;
      default: goto got_item;
    }
  }
  item = 0;
got_item:
  int candidate = item;
  if (candidate != 0 && (((c8)(f_042400((struct hero *)(candidate)))) == 8 || ((c8)(f_042400((struct hero *)(candidate)))) == 7)) other = candidate;

  int other_value = other;
  if (p1 != 0) {
    if (p3 == 0 || f_0d4a60(p1) == 1) {
      if (p2 == 0 || (other_value != 0 && f_0d4a60(other_value) == 1)) result = p1;
    }
  }
  // Steuert die berechnete Namens-Sortierung der lokalen Variablen
  (void)(signed char)candidate;
  (void)(short)candidate;
  return result;
}
//@ f_039660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt den einsatzfähigen Helden der Gruppe p1 mit dem *höchsten* aktuellen
 *   Wert in der Eigenschaft p2 (z. B. den stärksten Helden für eine Körperkraft-Probe).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den Eigenschaftsindex p2 (0..13) und
 *   gibt den Heldenzeiger mit dem höchsten Eigenschaftswert zurück.
 * - Wichtige Variablen: Der aktuelle Eigenschaftswert wird über f_043a80(p, p2) abgefragt.
 === Ende Beschreibung === */
int f_039660(int p1, int p2)
{
  short best;
  short i;
  int result;
  int p;
  int selected = 0;
  signed char value;

  best = -1;
  result = p1;
  for (i = 0; i <= 6; i++) {
    p = W4(result, i);
    if (p != 0 && !((c8)(f_042470((struct hero *)(p)))) && f_0d49b0(p)) {
      selected = p;
      goto found;
    }
  }
  selected = d_1bc8f0;
found:
  result = selected;
  for (i = 0; i <= 6; i++) {
    p = W4(p1, i);
    if (p != 0 && f_0d4a60(p)) {
      value = f_043a80(p, (short)p2);
      if ((short)value > best) {
        best = (short)value;
        result = p;
      }
    }
  }
  return result;
}
//@ f_0396f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt den einsatzfähigen Helden der Gruppe p1 mit dem *niedrigsten*
 *   aktuellen Wert in der Eigenschaft p2 (z. B. den Helden mit der geringsten Gewandtheit oder dem
 *   höchsten/niedrigsten Angstwert).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den Eigenschaftsindex p2 (0..13) und
 *   gibt den Heldenzeiger mit dem niedrigsten Eigenschaftswert zurück.
 * - Wichtige Variablen: Gesucht wird das Minimum von f_043a80(p, p2) unter allen einsatzfähigen
 *   Gruppenmitgliedern.
 === Ende Beschreibung === */
int f_0396f0(int p1, int p2)
{
  short best;
  short i;
  int result;
  int p;
  int selected = 0;
  signed char value;

  best = 999;
  result = p1;
  for (i = 0; i <= 6; i++) {
    p = W4(result, i);
    if (p != 0 && !((c8)(f_042470((struct hero *)(p)))) && f_0d49b0(p)) {
      selected = p;
      goto found;
    }
  }
  selected = d_1bc8f0;
found:
  result = selected;
  for (i = 0; i <= 6; i++) {
    p = W4(p1, i);
    if (p != 0 && f_0d4a60(p)) {
      value = f_043a80(p, (short)p2);
      if ((short)value < best) {
        best = (short)value;
        result = p;
      }
    }
  }
  return result;
}
//@ f_039780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 nach einem einsatzfähigen Helden einer bestimmten
 *   Charakterklasse p2 (z. B. einem Zwerg, Magier oder Krieger für klassenspezifische Ereignisse).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die gesuchte Klassen-ID p2 (signed char)
 *   und gibt den ersten passenden einsatzfähigen Helden oder 0 zurück.
 * - Wichtige Variablen: Die Charakterklasse wird über f_042350 gelesen.
 === Ende Beschreibung === */
int f_039780(int p1, signed char p2)
{
  c8 cVar2; int iVar3; short sVar4; int result = 0;
  for (sVar4 = 0; sVar4 < (int)*(signed char *)(p1 + 0x1c); sVar4 = sVar4 + 1) {
    int *puVar1 = (int *)(p1 + sVar4 * 4);
    iVar3 = f_0d4a60(*puVar1);
    if (iVar3 != 0) {
      cVar2 = ((c8)(f_042350((struct hero *)(*puVar1))));
      if (cVar2 == p2) return *puVar1;
    }
  }
  return result;
}
//@ f_0397d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion gibt den Helden an einer bestimmten Marschformations-Position p2 der Gruppe p1
 *   zurück; ist dieser Held nicht einsatzfähig, wählt sie ersatzweise einen zufälligen handlungsfähigen Helden
 *   der Gruppe aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Formationsposition p2 (short) und
 *   gibt den getroffenen Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: f_0d54f0(p1, p2) ermittelt den Gruppenslot zur Marschposition p2.
 === Ende Beschreibung === */
short f_0397d0(int p1, short p2)
{
  short sVar1; int iVar2; int p1_00;
  sVar1 = f_0d54f0(p1, (int)(short)p2);
  p1_00 = 0;
  if (sVar1 != -1) {
    p1_00 = f_0de7d0(p1, (int)sVar1);
    iVar2 = f_0d4a60(p1_00);
    if (iVar2 == 0) {
      p1_00 = f_038be0(p1);
    }
  }
  return p1_00;
}
//@ f_039830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 denjenigen einsatzfähigen Zauberkundigen heraus, der den
 *   höchsten Zauberwert im Spruch p2 besitzt und zugleich über genügend Astralenergie verfügt, um den Zauber
 *   auszusprechen (f_0429a0 >= f_10cae0(p2, 0)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und den Zauberindex p2 (short) und gibt den
 *   besten geeigneten Zauberer oder 0 zurück.
 * - Wichtige Variablen: score startet bei -6 (dem minimal zulässigen Zauberwert für erlernbare Sprüche);
 *   f_10cae0(p2, 0) liefert die Grund-Astralkosten des Zaubers.
 === Ende Beschreibung === */
int f_039830(int p1, short p2)
{
  int current;
  short value;
  short score;
  int best;
  short i;
  int result;

  score = -6;
  best = 0;
  i = 0;
  for (; i <= 6; i++) {
    current = W4(p1, i);
    if (current != 0 && f_0d4a60(current)) {
      value = ((c8)(f_0430f0((struct hero *)(current), p2)));
      if (value > score && f_0429a0((struct hero *)(current)) >= f_10cae0(p2, 0)) {
        score = value;
        best = current;
      }
    }
  }
  return best;
}
//@ f_0398c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese generische Filterfunktion prüft alle Helden einer Gruppe p1 mit einer übergebenen
 *   Callback-Prüffunktion p2, trägt alle Helden mit p2(hero) == 1 in das Ziel-Array p3 ein und gibt deren Anzahl
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, den Funktionszeiger p2 (int (*)(int)) und
 *   das Ergebnis-Array p3 (int[7]) und gibt die Anzahl der Treffer (0..7) zurück.
 * - Wichtige Variablen: iVar5 zählt die in p3 eingetragenen Heldenzeiger.
 === Ende Beschreibung === */
int f_0398c0(int p1, int (*p2)(int), int p3)
{
  int iVar1; short sVar2; int iVar3; short sVar4; int iVar5;
  iVar5 = 0;
  for (sVar2 = 0; sVar2 < 7; sVar2 = sVar2 + 1) {
    iVar3 = sVar2;
    W4(p3, iVar3) = 0;
    iVar3 = f_0de7d0(p1, iVar3);
    if (iVar3 != 0) {
      iVar1 = (*p2)(iVar3);
      if (iVar1 == 1) {
        sVar4 = (short)iVar5;
        iVar5 = iVar5 + 1;
        W4(p3, sVar4) = iVar3;
      }
    }
  }
  return iVar5;
}
//@ f_039910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zählt, wie viele Helden der Gruppe p1 die Callback-Bedingung p2(hero) == 1
 *   erfüllen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Prüffunktion p2 und gibt die
 *   Trefferanzahl (0..7) zurück.
 * - Wichtige Variablen: Sie ruft f_0398c0 mit einem temporären lokalen Array lst[7] auf.
 === Ende Beschreibung === */
int f_039910(int p1, int (*p2)(int))
{
  int lst[7];
  return f_0398c0(p1, p2, (int)lst);
}
//@ f_039960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zeigt für eine zuvor gefilterte Liste von Heldenzeigern p3 ein Auswahlmenü mit
 *   der Überschrift p2 an und gibt den vom Spieler ausgewählten Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, die Text-ID p2 und das Null-terminierte
 *   Heldenzeiger-Array p3 und gibt den gewählten Heldenzeiger oder 0 (bei Abbruch) zurück.
 * - Wichtige Variablen: Das lokale Array lst[7] speichert die Text-Handles der Heldennamen für den Dialogaufruf
 *   f_0bf820.
 === Ende Beschreibung === */
int f_039960(int p1, int p2, int*p3)
{
  int result;
  int lst[7];
  short i;
  short selected;
  f_0bf6c0((int)&d_1c2c64, 3);
  for (i = 0; p3[i] != 0 && i < 7; i++) {
    lst[i] = f_133fe0((int)&d_1c3498, ((int)(f_0422b0((struct hero *)(p3[i])))));
  }
  selected = f_0bf820(&d_1c2c64, p2, i, lst[0], lst[1], lst[2], lst[3], lst[4], lst[5], lst[6]);
  if (selected == -1) result = 0;
  else result = p3[selected - 1];
  f_0bf680((int)&d_1c2c64);
  return result;
}
//@ f_039a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Komfortfunktion kombiniert das Filtern einer Gruppe nach dem Kriterium p3 (f_0398c0) mit
 *   der anschließenden Anzeige eines Auswahlmenüs (f_039960), falls mindestens ein Held das Kriterium erfüllt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, die Titel-Text-ID p2 und die Filterfunktion
 *   p3 und gibt den vom Spieler ausgewählten Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Ist die Trefferzahl n == 0, kehrt die Funktion sofort ohne Dialog mit 0 zurück.
 === Ende Beschreibung === */
int f_039a10(int p1, int p2, int (*p3)(int))
{
  int lst[7];
  short n = f_0398c0(p1, p3, (int)lst);
  if (n != 0) {
    return f_039960(p1, p2, lst);
  }
  return 0;
}
//@ f_039a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Iterator-Funktion führt eine übergebene Callback-Funktion p2 nacheinander für jeden
 *   vorhandenen Helden der Gruppe p1 aus (for_each_hero).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und die Callback-Funktion p2 und gibt die
 *   Anzahl der durchlaufenen Helden zurück.
 * - Wichtige Variablen: iVar2 zählt die belegten Gruppenslots.
 === Ende Beschreibung === */
int f_039a80(int p1, int (*p2)(int))
{
  int iVar1; int iVar2; short sVar3;
  iVar2 = 0;
  for (sVar3 = 0; sVar3 < 7; sVar3++) {
    iVar1 = f_0de7d0(p1, (int)sVar3);
    if (iVar1 != 0) {
      (*p2)(iVar1);
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}
//@ f_039ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Suchfunktion gibt den ersten Helden der Gruppe p1 zurück, für den die Callback-Funktion
 *   p2(hero) den Wert 1 liefert (find_first_hero).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und das Prädikat p2 und gibt den ersten
 *   passenden Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Sobald iVar3 != 0 ist, bricht die Schleife ab.
 === Ende Beschreibung === */
int f_039ac0(int p1, int (*p2)(int))
{
  int iVar1; int iVar2; int iVar3; short sVar4;
  iVar3 = 0;
  for (sVar4 = 0; sVar4 < 7 && iVar3 == 0; sVar4++) {
    iVar1 = f_0de7d0(p1, (int)sVar4);
    if (iVar1 != 0) {
      iVar2 = (*p2)(iVar1);
      if (iVar2 == 1) {
        iVar3 = iVar1;
      }
    }
  }
  return iVar3;
}
//@ f_039b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 unter Ausschluss eines bestimmten Helden p2 denjenigen
 *   einsatzfähigen Helden heraus, der den höchsten Wert im Talent p3 besitzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, den auszuschließenden Helden p2 (oder 0)
 *   und den Talentindex p3 (short) und gibt den besten gefundenen Heldenzeiger zurück.
 * - Wichtige Variablen: Verglichen wird der reine Talentwert f_03ad80(p, p3).
 === Ende Beschreibung === */
short f_039b00(int p1, int p2, short p3)
{
  int best, p;
  c8 a;
  best = 0;
  short i;
  for (i = 0; i < 7; i++) {
    p = f_0de7d0(p1, i);
    if (p != 0 && p != p2 && f_0d4a60(p) != 0) {
      if (best == 0) best = p;
      else {
        a = f_03ad80(p, p3);
        if (f_03ad80(best, p3) <= a) best = p;
      }
    }
  }
  return best;
}
//@ f_039b70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 unter Ausschluss des Helden p2 denjenigen einsatzfähigen
 *   Helden mit dem *höchsten* Wert in der Eigenschaft p3.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, den ausgeschlossenen Helden p2 und den
 *   Eigenschaftsindex p3 (short) und gibt den besten Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Verglichen wird f_043a80(p, p3).
 === Ende Beschreibung === */
int f_039b70(int p1, int p2, short p3)
{
  int best = 0, p;
  c8 a;
  short i;
  for (i = 0; i < 7; i++) {
    p = f_0de7d0(p1, i);
    if (p != 0 && p != p2 && f_0d4a60(p) != 0) {
      if (best == 0) best = p;
      else {
        a = f_043a80(p, p3);
        if (f_043a80(best, p3) <= a) best = p;
      }
    }
  }
  return best;
}
//@ f_039be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Gruppe p1 unter Ausschluss des Helden p2 denjenigen einsatzfähigen
 *   Helden mit dem *niedrigsten* Wert in der Eigenschaft p3.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, den ausgeschlossenen Helden p2 und den
 *   Eigenschaftsindex p3 (short) und gibt den gefundenen Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: Wie in f_039b70, jedoch mit der Bedingung a <= b.
 === Ende Beschreibung === */
int f_039be0(int p1, int p2, short p3)
{
  int best; int p; c8 a; c8 b; short i;
  best = 0;
  for (i = 0; i < 7; i = i + 1) {
    p = f_0de7d0(p1, i);
    if (p == 0) continue;
    if (p == p2) continue;
    if (f_0d4a60(p) == 0) continue;
    if (best == 0) { best = p; continue; }
    a = f_043a80(p, (short)p3);
    b = f_043a80(best, (short)p3);
    if (a <= b) best = p;
  }
  return best;
}
//@ f_039c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht in der Hauptgruppe d_1c0004 nach dem ersten einsatzfähigen Helden, der
 *   nicht mit p2 identisch ist (z. B. einem Kameraden, der dem Helden p2 zu Hilfe eilt).
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und den auszuschließenden Helden
 *   p2 und gibt den ersten anderen einsatzfähigen Helden aus d_1c0004 oder 0 zurück.
 * - Wichtige Variablen: Durchsucht wird fest die globale Hauptgruppe d_1c0004.
 === Ende Beschreibung === */
int f_039c50(int p1, int p2)
{
  int r = 0, p;
  short i;
  for (i = 0; i < 7 && r == 0; i++) {
    p = f_0de7d0(d_1c0004, i);
    if (p != 0) {
      if (p != p2) {
        if (f_0d4a60(p) != 0) r = p;
      }
    }
  }
  return r;
}
//@ f_039c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese generische Maximierungsfunktion sucht unter allen Helden der Gruppe p1, die das
 *   Filterprädikat p3(p) == 1 erfüllen, denjenigen Helden heraus, für den die Bewertungsfunktion p2(p) den
 *   höchsten short-Wert liefert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1, die Bewertungsfunktion p2 (short (*)(int))
 *   und die Filterfunktion p3 (int (*)(int)) und gibt den bestbewerteten Heldenzeiger oder 0 zurück.
 * - Wichtige Variablen: best hält den bisher führenden Heldenzeiger.
 === Ende Beschreibung === */
int f_039c90(int p1, short (*p2)(int), int (*p3)(int))
{
  short i;
  int best;
  int p;
  short a, b;
  for (best = 0, i = 0; i < 7; i++) {
    p = f_0de7d0(p1, i);
    if (p != 0 && p3(p) == 1) {
      if (best == 0) best = p;
      else {
        a = p2(p);
        b = p2(best);
        if (a >= b) best = p;
      }
    }
  }
  return best;
}

//@ f_039cf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese zentrale Krankheits-Tick-Funktion berechnet für einen lebenden Helden p1 die
 *   periodischen Auswirkungen und den Heilungsverlauf aller neun Krankheiten (Index 1..9, darunter Wundfieber,
 *   Dumpfschädel, Blaue Keuche, Paralyse, Schlachtenfieber, Frostschäden und Tollwut). Sie zieht je nach
 *   Krankheit und Krankheitsstatus (-1 = akut krank, 1 = auf dem Weg der Besserung) Lebenspunkte, Körperkraft
 *   (Attribut 6), Gewandtheit (Attribut 4), Mut (Attribut 0) oder Astralenergie ab, erhöht schlechte
 *   Eigenschaften, prüft auf den Tod durch Attributsverlust (KK <= 0 oder GE <= 0) und zählt die Krankheitsdauer
 *   um 1 hoch.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: f_0435c0(p1, i) liefert den Status der Krankheit i (-1 = krank, 0 = gesund, 1 =
 *   abklingend), f_043600(p1, i) die bisherige Dauer, und f_043670/f_0436e0 speichern die durch die Krankheit
 *   verlorenen Punkte in Körperkraft bzw. Gewandtheit (siehe auch den dokumentierten Originalfehler in der
 *   Fehlerliste bei der Erholungsformel (!f_043600(p1, i)) % 12 für Krankheit 1).
 === Ende Beschreibung === */
void f_039cf0(int p1)
{
  c8 c; short j; short i;
  int fr[15];
  f_125400((int)fr, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  *(int *)(fr[1] + 4) = p1;
  if (((c8)(f_042470((struct hero *)(p1))))) goto LAB_end;
  c = ((c8)(f_0425f0((struct hero *)(p1))));
  i = 1;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    f_044300(p1, f_1457e0(6));
    if (f_043600(p1, i) >= 6) {
      if (!((c8)(f_042470((struct hero *)(p1)))) && f_043a80(p1, 6)) {
        f_0436b0(p1, i, 1);
        f_045430(p1, 6, -1);
      }
      if (!((c8)(f_042470((struct hero *)(p1)))) && f_043a80(p1, 4)) {
        f_043720(p1, i, 1);
        f_045430(p1, 4, -1);
      }
    }
  }
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == 1) {
    if (!f_043670(p1, i) && !f_0436e0(p1, i)) {
      f_043620(p1, i, 0);
      f_0435e0(p1, i, 0);
    }
#if FIX_R026
    if (f_043670(p1, i) && !(f_043600(p1, i) % 12)) {
      f_0436b0(p1, i, -1);
      f_045430(p1, 6, 1);
    }
    if (f_0436e0(p1, i) && !(f_043600(p1, i) % 12)) {
      f_043720(p1, i, -1);
      f_045430(p1, 4, 1);
    }
#else
    if (f_043670(p1, i) && (!f_043600(p1, i)) % 12) {
      f_0436b0(p1, i, -1);
      f_045430(p1, 6, 1);
    }
    if (f_0436e0(p1, i) && (!f_043600(p1, i)) % 12) {
      f_043720(p1, i, -1);
      f_045430(p1, 4, 1);
    }
#endif
  }
  i = 2;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= 2 && !f_043750(p1, i)) {
      f_043770(p1, i, 1);
      if (!((c8)(f_042470((struct hero *)(p1)))) && f_043a80(p1, 6)) {
        f_0436b0(p1, i, 2);
        f_045430(p1, 6, -2);
      }
      if (!((c8)(f_042470((struct hero *)(p1)))) && f_043a80(p1, 4)) {
        f_043720(p1, i, 2);
        f_045430(p1, 4, -2);
      }
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x2040005);
    }
    if (f_043600(p1, i) >= 0x78) f_0435e0(p1, i, 1);
  }
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == 1) {
    f_0435e0(p1, i, 0);
    f_043620(p1, i, 0);
    if (f_043750(p1, i)) {
      f_043770(p1, i, 0);
      f_043720(p1, i, -2);
      f_045430(p1, 4, 2);
      f_0436b0(p1, i, -2);
      f_045430(p1, 6, 2);
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x2040006);
    }
  }
  i = 3;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (!f_043750(p1, i)) {
      f_043770(p1, i, 1);
      f_045430(p1, 0, -2);
      f_045430(p1, 7, 2);
      f_045430(p1, 8, 2);
      f_045430(p1, 9, 2);
      f_045430(p1, 10, 2);
      f_045430(p1, 0xb, 2);
      f_045430(p1, 0xc, 2);
      f_045430(p1, 0xd, 2);
      if (d_1bd90c != (short)0) f_042650((struct hero *)(p1), 1);
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x2040007);
    }
    if (f_043600(p1, i) >= 7) f_0435e0(p1, i, 1);
  }
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == 1) {
    f_0435e0(p1, i, 0);
    f_043620(p1, i, 0);
    if (f_043750(p1, i)) {
      f_043770(p1, i, 0);
      f_045430(p1, 0, 2);
      f_045430(p1, 7, -2);
      f_045430(p1, 8, -2);
      f_045430(p1, 9, -2);
      f_045430(p1, 10, -2);
      f_045430(p1, 0xb, -2);
      f_045430(p1, 0xc, -2);
      f_045430(p1, 0xd, -2);
      f_042650((struct hero *)(p1), 0);
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x2040008);
    }
  }
  i = 4;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (!f_043750(p1, i)) {
      f_043770(p1, i, 1);
      f_030e20(p1, 1);
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x2040009);
    }
    if (f_043600(p1, i) >= 0x14) f_0435e0(p1, i, 1);
  }
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == 1) {
    f_0435e0(p1, i, 0);
    f_043620(p1, i, 0);
    if (f_043750(p1, i)) {
      f_043770(p1, i, 0);
      f_030e20(p1, 0);
      if (f_030fe0(p1) == 1) {
        f_0bf730((int)&d_1c2c64, 0x204000a);
        f_0bbf00((int)&d_1bf230);
        d_1c2198 = 1;
      }
    }
  }
  i = 5;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= f_145850(2, 6, 0) * 12) f_0435e0(p1, i, 0);
    if (f_043600(p1, i) % 12 == 0) f_044300(p1, f_145850(2, 6, -3));
  }
  if (f_0435c0(p1, i) == 1) f_0435e0(p1, i, 0);
  i = 6;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= 0x30) f_0435e0(p1, i, 0);
    if (f_043600(p1, i) % 12 == 0) f_044300(p1, f_145850(1, 6, 2));
  }
  if (f_0435c0(p1, i) == 1) f_0435e0(p1, i, 0);
  i = 7;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= 0x18) f_0435e0(p1, i, 0);
    f_044300(p1, f_145850(2, 6, 0));
  }
  if (f_0435c0(p1, i) == 1) f_0435e0(p1, i, 0);
  i = 8;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= 3) f_0435e0(p1, i, 0);
    f_044300(p1, f_145850(0x32, 6, 0));
  }
  if (f_0435c0(p1, i) == 1) f_0435e0(p1, i, 0);
  i = 9;
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == -1) {
    if (f_043600(p1, i) >= f_145850(3, 6, 0)) f_0435e0(p1, i, 1);
    j = f_145850(1, 6, 2);
    if (f_0429a0((struct hero *)(p1)) >= j) {
      f_0436b0(p1, i, (c8)j);
      f_044230(p1, j);
      *(short *)(fr[5] + 2) = j;
      *(int *)(fr[4] + 4) = (j == 1) ? 0x20000194 : 0x20000164;
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x204000b);
    }
  }
  if (!((c8)(f_042470((struct hero *)(p1)))) && f_0435c0(p1, i) == 1) {
    if (!f_043670(p1, i)) {
      f_0435e0(p1, i, 0);
    } else if (f_043600(p1, i) % 12 == 0) {
      f_0436b0(p1, i, -1);
      f_0442b0(p1, 1);
      if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x204000c);
    }
  }
  for (j = 1; j <= 9; j++) {
    if (f_0435c0(p1, j) != 0) f_043640(p1, j, 1);
  }
  if (f_043a80(p1, 6) <= 0 || f_043a80(p1, 4) <= 0) {
    d_1bc88c = 1;
    for (j = 1; j <= 9; j++) {
      if (j == 3 && f_043750(p1, j)) {
        f_045430(p1, 0, 2);
        f_045430(p1, 7, -2);
        f_045430(p1, 8, -2);
        f_045430(p1, 9, -2);
        f_045430(p1, 10, -2);
        f_045430(p1, 0xb, -2);
        f_045430(p1, 0xc, -2);
        f_045430(p1, 0xd, -2);
      } else {
        if (f_043670(p1, j) && j != 9) {
          f_045430(p1, 6, f_043670(p1, j));
          f_0436b0(p1, j, (c8)-f_043670(p1, j));
        }
        if (f_0436e0(p1, j)) {
          f_045430(p1, 4, f_0436e0(p1, j));
          f_043720(p1, j, (c8)-f_0436e0(p1, j));
        }
      }
    }
    d_1bc88c = 0;
    f_044300(p1, f_042960((struct hero *)(p1)));
  }
  if (((c8)(f_0425f0((struct hero *)(p1)))) != c && !f_0e3360((int)&d_1c2c64) && !((c8)(f_042470((struct hero *)(p1))))) {
    if (f_030fe0(p1) == 1) f_0bf730((int)&d_1c2c64, 0x204002b);
    if (d_1c2a80 == 0x30000) d_1c2198 = 1;
  }
LAB_end:
  f_1254a0((int)fr, 0);
}
