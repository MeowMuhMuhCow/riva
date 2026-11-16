/* === Beschreibung (Katalog) ===
 * Einheit charac2 (0x0417f0 - 0x0421c0)
 *
 * Überblick
 * Die Einheit charac2 enthält die weiterführenden Funktionen zur Gruppen- und Heldenverwaltung in der unteren
 * Statusleiste: das Auswählen einer Heldengruppe, das Umschalten auf eine andere Teilgruppe sowie das
 * Vertauschen zweier Heldenpositionen innerhalb der aktiven Gruppe (sowohl per Menüdialog als auch per
 * Drag-and-Drop mit der Maus über die Heldenporträts).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 7/8 gleich (suche.py 11.11.2026, Basis charac2_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 336 (vorher 342)
// charac2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0417F0-0x0421C0
#include <string.h>
int f_014540(int p1, const char *p2, int p3);
int f_038c40(int p1);
int f_038c80(int p1);
int f_038cb0(int p1);
int f_038e90(int p1, int p2);
int f_039040(int p1);
int f_039ac0(int p1, int p2);
int f_041630(int p1, int p2, int p3);
int f_0416d0(int p1, int p2);




int f_044060(int p1, int p2);
int f_069460();
int f_099ea0();
int f_0bbf00(int p1);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0c0020(int p1, int p2);
int f_0ce070(int p1);
int f_0d26e0();
int f_0d2710();
int f_0d2f40(int p1, int p2);
int f_0d3780();
int f_0d3790();
int f_0d3860();
short f_0db940(int p1);
short f_0dc020(int p1, int p2);
char f_0dd410(int p1, int p2);
int f_0ddfc0(int p1);
int f_0de0d0(int p1);
int f_0de7c0(int p1);
int f_0de7d0(int p1, int p2);
short f_0de7f0(int p1);
short f_0de820(int p1);
int f_0de930(int p1, int p2);
int f_0de940(int p1, int p2);
int f_0de980(int p1);
int f_0de9c0(int p1);
short f_0de9e0(int p1);




int f_122120(int p1);
int f_125400(int p1, int p2, int p3);
int f_1254a0(int p1, int);
void f_014710(void *p);
void f_040f30(void);
void f_040f40(void);
extern int d_1a34e0;
extern short d_1a5544[];
extern unsigned short d_1a7fc0;
extern short d_1a966a;
extern signed char d_1a9670;
extern int d_1bc8cc;
extern int d_1bc8d0[];
extern int d_1bc8e8;
extern signed char d_1bc8ec;
extern int d_1bf230;
extern char d_1bf4e8;
extern volatile char d_1bf4ed;
extern short d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fc;
extern short d_1bf528;
extern short d_1bf52a;
extern short d_1bf52c;
extern short d_1bf52e;
extern int d_1bfdbc;
extern int d_1c0004;
extern char d_1c0008[];
extern char d_1c0010[];
extern char d_1c0018[];
extern char d_1c0020[];
extern signed char d_1c002c;
extern int d_1c2198;
extern int d_1c2a80;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a0d68[];
struct CH { char b[0x5ef]; };
struct S9 { char b[9]; };
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0417f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut eine Auswahlliste aller derzeit belegten und nicht gesperrten Heldengruppen (d_1bfdbc,
 *   Schrittweite 0x61) auf, fügt die aktuell gesteuerte Gruppe (d_1c0004) ans Ende der Liste an und öffnet den
 *   Gruppenauswahldialog (f_041630).
 * - Eingaben und Rückgabe: Die Funktion erhält die Textkennung der Dialogüberschrift (p1) und gibt den Zeiger
 *   auf die vom Spieler gewählte Heldengruppe (oder 0 bei Abbruch) zurück.
 * - Wichtige Variablen: Das globale Array d_1bfdbc enthält die sechs möglichen Heldengruppen, d_1c0004 zeigt auf
 *   die aktuell aktive Gruppe, und d_1bc8d0 speichert die Zeiger auf die auswählbaren Gruppen.
 === Ende Beschreibung === */
int f_0417f0(int p1)
{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int p1_00;
  short sVar5;

  d_1bc8e8 = f_014540(600, d_1a0d68, 0x1d4);
  sVar5 = 0;
  sVar3 = 0;
  p1_00 = (int)&d_1bfdbc;
  sVar1 = f_0c0020((int)&d_1c2c64, 6);
  for (; sVar3 < 6; sVar3 = sVar3 + 1, p1_00 = (int)&d_1bfdbc + sVar3 * 0x61) {
    if ((int)sVar3 != (int)d_1a9670) {
      sVar2 = f_0de7f0(p1_00);
      if ((sVar2 != (short)0) && (p1_00 != d_1c0004)) {
        iVar4 = f_0de9c0(p1_00);
        if (iVar4 == 0) {
          iVar4 = (int)sVar5;
          f_0416d0(p1_00, iVar4);
          sVar5 = sVar5 + 1;
          d_1bc8d0[iVar4] = p1_00;
        }
      }
    }
  }
  if (d_1c0004 != 0) {
    if (f_0de7f0(d_1c0004) != (short)0) {
      iVar4 = (int)sVar5;
      f_0416d0(d_1c0004, iVar4);
      sVar5 = sVar5 + 1;
      d_1bc8d0[iVar4] = d_1c0004;
    }
  }
  return f_041630(p1, (int)sVar5, (int)sVar1);
}
//@ f_0418e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sperrt das Umschalten zwischen getrennten Heldengruppen, indem das globale Freigabe-Flag auf 0
 *   gesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Die globale Variable d_1bc8ec gibt an, ob ein Gruppenwechsel derzeit erlaubt (1) oder
 *   gesperrt (0) ist.
 === Ende Beschreibung === */
void f_0418e0(void)
{
  d_1bc8ec = 0;
}
//@ f_0418f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Umschalten zwischen getrennten Heldengruppen wieder frei, indem das globale
 *   Freigabe-Flag auf 1 gesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Die globale Variable d_1bc8ec wird auf 1 gesetzt.
 === Ende Beschreibung === */
void f_0418f0(void)
{
  d_1bc8ec = 1;
}
//@ f_041900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Umschalten zwischen Heldengruppen derzeit erlaubt ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt 1 zurück, wenn ein
 *   Gruppenwechsel erlaubt ist, andernfalls 0.
 * - Wichtige Variablen: Liest das globale Gruppenwechsel-Flag d_1bc8ec.
 === Ende Beschreibung === */
int f_041900(void)
{
  int r = 0; if (EQ(d_1bc8ec, 1)) r = 1; return r;
}
//@ f_041920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet die Steuerung von der bisherigen Heldengruppe (d_1c0004) auf die gewünschte
 *   Zielgruppe (p1) um, sofern Gruppenwechsel erlaubt sind (d_1bc8ec == 1) und die Zielgruppe nicht gesperrt ist
 *   (f_0de980). Falls sich ein abtrünniger oder verwandelter Held in der Gruppe befindet (f_039ac0), wird vorab
 *   eine Sicherheitsabfrage (0x270000af) eingeblendet; anschließend werden der aktive Gruppenzeiger d_1c0004,
 *   der Kartenausschnitt und die Statusleiste (f_0bbf00) aktualisiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf die gewünschte Heldengruppe (p1) und gibt 1
 *   zurück, wenn der Wechsel erfolgreich war (oder die Gruppe bereits aktiv war), sonst 0.
 * - Wichtige Variablen: Die globale Variable d_1c0004 hält die aktive Heldengruppe, d_1bc8ec steuert die
 *   Wechselerlaubnis, und d_1bf230 ist die Statusleiste der Heldenporträts.
 === Ende Beschreibung === */
struct MsgC { int h; char *q[14]; MsgC(void*, void*, void*); ~MsgC(); };
extern int d_1c3498;
int f_041920(int p1)
{
  int fl;
  int r = 0;
  if (p1 == d_1c0004) {
    r = 1;
  } else {
    int ok = 0;
    if (EQ(d_1bc8ec, 1)) ok = 1;
    if (!ok) {
      f_0bf730((int)&d_1c2c64, 0x20000036);
    } else if (f_0de980(p1) == 1) {
      f_0bf730((int)&d_1c2c64, 0x20000037);
    } else {
      int h = f_039ac0(p1, (int)f_040f30);
      fl = 0;
      if (h) {
        if (f_0de0d0((int)f_040f40)) {
          MsgC m((void*)&d_1c349c, (void*)&d_1c3870, (void*)&d_1c3498);
          int v = f_038c40(p1);
          *(int*)(m.q[0] + 4) = v;
          if (!(f_0bf6f0((int)&d_1c2c64, 0x270000af))) fl = 1;
        }
        if (!fl) f_044060(h, 0);
      }
      if (fl != 1) {
        int old;
        short a;
        if ((short)f_0de820(p1) == 3 && (short)f_0de9e0(p1) == 1) {
          d_1bc8cc = f_038c40(p1);
        }
        old = d_1c0004;
        d_1c0004 = p1;
        d_1c002c = f_0ce070(p1);
        f_0de940(d_1c0004, -1);
        a = f_0de820(d_1c0004);
        if (a == f_0de820(old)) {
          f_0ddfc0(d_1c0004);
          f_0bbf00((int)&d_1bf230);
        } else {
          d_1c2a80 = 0;
          *(short*)&d_1c2198 = 1;
        }
        f_0de930(d_1c0004, 1);
        r = 1;
      }
    }
  }
  f_122120(d_1a7fc0);
  return r;
}
//@ f_041ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fordert den Spieler in einer Schleife solange zur Auswahl einer handlungsfähigen Heldengruppe
 *   über f_0417f0 auf (etwa wenn die bisherige Gruppe kampfunfähig, ausgelöscht oder gefangen wurde), bis eine
 *   gültige Gruppe mit mindestens einem aktiven Helden gewählt und über f_041920 aktiviert wurde.
 * - Eingaben und Rückgabe: Die Funktion erhält ein Flag (p1), das bei 0 eine Fehlermeldung (0x20000037)
 *   einblendet, wenn eine ungültige Gruppe gewählt wurde, und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Nutzt den Dialogkontext d_1c2c64 für Hinweismeldungen.
 === Ende Beschreibung === */
void f_041ae0(int p1)
{
  int zero = 0;
  int p;
  int r;
  do {
    p = f_0417f0(0x20000197);
    r = p;
    if (p == 0) goto fail;
    if (f_0de7c0(p) == 0) goto fail;
    if ((short)f_0db940(p) == 0) goto fail;
    if ((short)f_0db940(p) != 1) goto check;
    if ((signed char)f_0dd410(p, 1) == 0) goto check;
fail:
    r = zero;
    if ((short)p1 == 0) f_0bf730((int)&d_1c2c64, 0x20000037);
    goto done;
check:
    if (f_041920(r) == 0) r = zero;
done:
    ;
  } while (r == 0);
}
//@ f_041b60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Tauscht die Gruppenpositionen zweier lebender Nicht-NPC-Helden innerhalb der aktiven
 *   Heldengruppe (d_1c0004) über zwei aufeinanderfolgende Heldenauswahldialoge (0x20000038 und 0x20000039,
 *   beziehungsweise direkt bei genau zwei Helden in der Gruppe). Dabei werden die 0x5ef Byte großen
 *   Heldenstrukturen im Speicher sowie die vier zugehörigen Positions-Arrays (d_1c0008, d_1c0010, d_1c0018,
 *   d_1c0020) vertauscht und die Statusleiste (f_0bbf00) neu gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Die globale Variable d_1a966a prüft die Eingabefreigabe, d_1c0004 ist die aktive Gruppe,
 *   und die Arrays d_1c0008 bis d_1c0020 speichern die Kampfformations- und Slot-Zuordnungen der Gruppenplätze.
 === Ende Beschreibung === */
void f_041b60(void)
{
  if (d_1a966a) {
    if (f_0de7f0(d_1c0004) > 1) {
      int local_34;
      int p1_00;
      local_34 = 0; p1_00 = 0;
      if (f_0de7f0(d_1c0004) == 2) {
        p1_00 = f_038c80(d_1c0004);
        local_34 = f_038cb0(d_1c0004);
      }
      if (p1_00 == 0) p1_00 = f_038e90(d_1c0004, 0x20000038);
      if (p1_00 != 0) {
        if (!((char)(f_042400((struct hero *)(p1_00))))) {
          if (local_34 == 0) local_34 = f_038e90(d_1c0004, 0x20000039);
          if (local_34 != 0 && p1_00 != local_34) {
            if (!((char)(f_042400((struct hero *)(local_34))))) {
              char *p1 = (char *)f_014540(0x5ef, d_1a0d68, 0x2f8);
              short sVar7, sVar6;
              sVar6 = f_0dc020(d_1c0004, p1_00);
              sVar7 = f_0dc020(d_1c0004, local_34);
              char uVar2, uVar4, uVar3, uVar1;
              uVar1 = d_1c0008[sVar6];
              uVar2 = d_1c0010[sVar6];
              uVar3 = d_1c0018[sVar6];
              uVar4 = d_1c0020[sVar6];
              *(CH *)p1 = *(CH *)p1_00;
              *(CH *)p1_00 = *(CH *)local_34;
              *(CH *)local_34 = *(CH *)p1;
              d_1c0008[sVar6] = d_1c0008[sVar7];
              d_1c0010[sVar6] = d_1c0010[sVar7];
              d_1c0018[sVar6] = d_1c0018[sVar7];
              d_1c0020[sVar6] = d_1c0020[sVar7];
              d_1c0008[sVar7] = uVar1;
              d_1c0010[sVar7] = uVar2;
              d_1c0018[sVar7] = uVar3;
              d_1c0020[sVar7] = uVar4;
              if (((char)(f_042350((struct hero *)(p1_00))))) f_042800((struct hero *)(p1_00), 100);
              if (((char)(f_042350((struct hero *)(local_34))))) f_042800((struct hero *)(local_34), 100);
              f_042450((struct hero *)(p1_00), (short)(sVar6 + 1));
              f_042450((struct hero *)(local_34), (short)(sVar7 + 1));
              delete p1;
            }
          }
        }
      }
      f_0bbf00((int)&d_1bf230);
    }
  }
}
//@ f_041d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt das Ziehen und Vertauschen (Drag-and-Drop) eines Heldenporträts mit der Maus in der
 *   unteren Statusleiste durch. Während die Maustaste gedrückt gehalten wird (!f_0d3790()), wird das
 *   32x32-Porträt des gezogenen Helden horizontal zwischen den X-Grenzen 3 und 219 auf Höhe Y = 157 mitgeführt;
 *   beim Loslassen wird der Zielslot anhand der X-Koordinatentabelle d_1a5544 bestimmt und der Held bei einem
 *   gültigen Zielplatz mit dem dortigen Helden vertauscht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenplatz-Index (p1, 0 bis 5) des gezogenen Helden und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Die Tabelle d_1a5544 enthält die X-Koordinaten der sechs Porträtslots in der
 *   Statusleiste, d_1bf4f0 und d_1bf4f2 sind die aktuellen Mauskoordinaten, und d_1bf528 bis d_1bf52e begrenzen
 *   den Bewegungsbereich des Mauszeigers.
 === Ende Beschreibung === */
void f_041d90(short p1)
{
  int t = (int)operator new(9, mark(d_1a0d68, 0x334));
  int first = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 32, 32))) : t;
  t = (int)operator new(9, mark(d_1a0d68, 0x335));
  int second;
  if (t) second = ((int)(((RivaRasterImage*)(t))->f_0fac80( 32, 32)));
  else second = t;
  if ((short)p1 != 6 && f_0d3780()) {
    volatile int lock;
    if (f_0d3860() == 1) {
      lock = (f_0d2710(), 1);
    } else lock = 0;
    d_1bf52a = 157;
    d_1bf52e = 189;
    d_1bf528 = 3;
    d_1bf52c = 219;
    int index = (short)p1;
    ((RivaRasterImage*)(second))->f_0fafb0((void *)( d_1a34e0), d_1a5544[index], 157);
    ((RivaRasterImage*)(first))->f_0fafb0((void *)( d_1a34e0), d_1a5544[index], 157);
    short offset = d_1bf4f0 - d_1a5544[index];
    f_0d2f40(d_1a5544[index], *(volatile short *)&d_1bf4f2);
    (*(volatile short *)&d_1bf4fc) = d_1bf4f0;
    while (!f_0d3790()) {
      if (d_1bf4f0 != d_1bf4fc) {
        f_099ea0();
        ((RivaRasterImage*)(first))->f_0fade0((void *)( d_1a34e0), d_1bf4fc, 157);
        d_1bf4ed = 1;
        ((RivaRasterImage*)(first))->f_0fafb0((void *)( d_1a34e0), d_1bf4f0, 157);
        ((RivaRasterImage*)(second))->f_0fade0((void *)( d_1a34e0), *(volatile short *)&d_1bf4f0, 157);
        d_1bf4ed = 0;
        d_1bf4fc = d_1bf4f0;
      }
      f_069460();
    }
    *(volatile int *)&d_1bf4e8 = 0;
    ((RivaRasterImage*)(first))->f_0fade0((void *)( d_1a34e0), d_1bf4fc, 157);
    short target = 6;
    do {
      target -= 1;
      int slotx = d_1a5544[target];
      int mousex = d_1bf4f0;
      if(mousex + 25 >= slotx) break;
    } while(1);

    if (target < 0) target = 0;
    short count = f_0de7f0(d_1c0004);
    if (f_039040(d_1c0004)) --count;
    if ((short)p1 != target && target != 6 && target < count) {
      char *buf = (char *)f_014540(0x5ef, d_1a0d68, 0x374);
      int destination;
      int source;
      int to = target;
      int from = (short)p1;
      short saved_from = p1;
      short saved_target = target;
      { int u = from; from = u; } // Haelt die Register- und Stapelvergabe wie im Original
      int grp = d_1c0004;
      destination = f_0de7d0(grp, to);
      (void)(short)from;
      source = f_0de7d0(d_1c0004, from);
      char v08 = d_1c0010[from];
      char v10 = d_1c0008[from];
      { char u = v08; v08 = u; } // Haelt die Registervergabe beim Ringtausch wie im Original
      {
          char v20 = d_1c0020[from];
          char v18 = d_1c0018[from];
          *(CH *)buf = *(CH *)source;
          *(CH *)source = *(CH *)destination;
          *(CH *)destination = *(CH *)buf;
          d_1c0008[from] = d_1c0008[to];
          d_1c0010[from] = d_1c0010[to];
          d_1c0018[from] = d_1c0018[to];
          d_1c0020[from] = d_1c0020[to];
          d_1c0020[to] = v20;
          d_1c0010[to] = v08;
          d_1c0018[to] = v18;
          d_1c0008[to] = v10;
      }
      if (((char)(f_042350((struct hero *)(source))))) f_042800((struct hero *)(source), 100);
      if (((char)(f_042350((struct hero *)(destination))))) f_042800((struct hero *)(destination), 100);
      f_042450((struct hero *)(source), (short)(saved_from + 1));
      f_042450((struct hero *)(destination), (short)(saved_target + 1));
      operator delete(buf);
    }
    d_1bf52a = 0;
    d_1bf52e = 199;
    d_1bf528 = 0;
    d_1bf52c = 319;
    f_0d2f40((short)(d_1bf4f0 + offset), d_1bf4f2);
    f_0bbf00((int)&d_1bf230);
    if (lock == 1) f_0d26e0();
  }
  if (first) operator delete((void *)((int)(((RivaRasterImage*)(first))->f_0fad20( 0))));
  if (second) operator delete((void *)((int)(((RivaRasterImage*)(second))->f_0fad20( 0))));
}
