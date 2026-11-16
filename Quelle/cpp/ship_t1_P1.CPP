/* === Beschreibung (Katalog) ===
 * Einheit ship_t1 (0fb660 - 0fca60)
 *
 * Überblick
 *
 * Die Einheit ship_t1 bildet den ersten Teil des 3D-Dungeon-Moduls ship (das Orkschiff / Kaperschiff im Hafen
 * bzw. vor der Küste von Riva, Kennung 0x29). Sie enthält die Initialisierung des Schiffszustands (f_0fb660,
 * f_0fb740), Talentproben für alle Gruppenmitglieder mit optionalem Schadenswurf (f_0fbd80), das Öffnen und
 * Aufbrechen von Kabinentüren (f_0fbe10) sowie die ersten großen Ereignis- und Interaktionsroutinen an Bord
 * (f_0fbee0, f_0fc0d0, f_0fc5a0, f_0fc6e0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 6/9 gleich (suche.py 29.10.2026, Basis ship_t1_P1.CPP)
// ship.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FB660-0x0FCA60
#include <string.h>
#define I32(p,o) (*(int *)((p)+(o)))
#define DD ((int)&d_1c2c64)
#define DEC(x) (--(x))
#define INCV(x) (++*(volatile signed char *)&(x)) // erzwingt inc BYTE PTR im Speicher wie im Original
typedef short (*VF)(int, int, int);
#define VC(p,a) ((VF)(*(*(int **)((p) + 8))))((p), (a), 0)
#define KSEL(k) switch (u) { case 0x17: k = 10; break; case 0x18: k = 0x14; break; case 0x19: k = 0x1e; break; }
#define NEWC(V,ln,ctor) { int t_ = (int)operator new(0x13e, mark(d_1a67f4, ln)); V = (t_ != 0) ? f_0104b0(t_, ctor, 0, 0) : t_; }
#define ENDC(V,K) f_0bf6c0(DD, 6); f_0bf980(DD, V, 0, K, 0); f_0bf680(DD); if (V != 0) operator delete((void *)f_010590(V, 0));
#define DELO(V) if (V != 0) operator delete((void *)((int)(((RivaRasterImage*)(V))->f_0fad20( 0))));
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_038c40(int p1);
int f_038c80(int p1);
int f_0391b0(int p1, int p2);
int f_0391f0(int p1, int p2);
int f_039420(int p1, int p2);
int f_0396f0(int p1, int p2);




int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_05f190(int p1, int p2, int p3);
int f_05f220(int p1, int p2);
int f_05f580(int p1);
int f_05f5a0(int p1, int p2);
int f_0606a0(int p1, int p2);
int f_060a70(void);
int f_0bbf00(int p1);
int f_0bde40(int p1);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820(int, ...);
short f_0bf980(int, ...);
short f_0bfa20(int, ...);
int f_0d4a60(int p1);
int f_0d64a0(void);
short f_0db940(int p1);
short f_0db9a0(int p1);
int f_0dd440(int p1);
int f_0dd750(int p1, int p2);
short f_0de1c0(int p1, int p2, int p3);
int f_0de210(int p1, int p2);
short f_0de820(int p1);

void f_0fca60(int p1);
int f_0fdd10(int p1);
int f_0fdf00(int p1);
int f_0fe5c0(int p1);
int f_0feb40(int p1);
int f_0fee00(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_1457e0(int p1);
#pragma aux f_0de210 parm [eax edx] modify exact [eax];
#pragma aux f_0fdd10 parm [eax] modify exact [eax];
#pragma aux f_0fe5c0 parm [eax] modify exact [eax];
extern int d_1bd91c;
extern int d_1bf230;
extern int d_1c0004;
extern signed char d_1c0294;
extern volatile signed char d_1c036c; // haelt Speicherzugriffe und Registerfolge wie im Original
extern volatile signed char d_1c0368; // haelt Speicherzugriffe und Registerfolge wie im Original
extern unsigned short d_1c0364;
extern signed char d_1c0370;
extern volatile signed char d_1c0374; // haelt das direkte Speicherschreiben in f_0fc0d0 wie im Original
extern signed char d_1c0378;
extern signed char d_1c038c;
extern int d_1c21a4;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a67f4[];
struct SO { int a; int *p; char pad[0x34]; };
void f_0fb660(int p1, int p2);
void f_0fb740(int p1);
void f_0fbc60(void);
int f_0fbe10(int p1);
void f_0fbee0(int p1, unsigned short p2);
void f_0fc0d0(int p1, int p2, int p3);
void f_0fc5a0(int p1, int p2);
void f_0fc6e0(int p1, int p2);
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0fb660
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt beim ersten Betreten des Orkschiffs (d_1c036c == 0) alle 66 schiffsweiten Tür-,
 *   Luken-, Kampf- und Ereignisflags (d_1c0372 bis d_1c03b6) auf ihre Ausgangswerte.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Schiffs-Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
void f_0fb660(int p1, int p2)
{
  int a = (int)operator new(0xc, mark(d_1a67f4, 0xf9));
  p2 += 1000;
  int b = a ? f_05f190(a, 0, (short)p2) : a;
  if (f_05f580(b)) f_05f5a0(b, 1);
  if (b) operator delete((void *)f_05f220(b, 0));
}
//@ f_0fb740
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode synchronisiert sämtliche 3D-Türen, Falltüren, Gitter und zerstörbaren Schiffswände in
 *   der geladenen 3D-Kartenstruktur mit den aktuellen Zustandsvariablen (d_1c0372 bis d_1c03a1) des Orkschiffs.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Schiffs-Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fb740(int p1)
{
  struct SO o;
  unsigned short typ;
  short antwort;
  int zeit1, zeit3, zeit2;
  unsigned char timer;
  signed char zustand;

  int activity = I32(p1, 0xd);
  if (activity == 1) {

  switch (f_0de820(d_1c0004)) {
  case 0x17: zeit1 = 10; break;
  case 0x18: zeit1 = 20; break;
  case 0x19: zeit1 = 30; break;
  }
  zeit1 += f_0dd440(d_1c0004);
  typ = (unsigned short)zeit1;
  (*(unsigned char *)&d_1c0294) += 5;

  timer = d_1c036c;
  switch (timer) {
  case 0: break;
  case 1: {
      d_1bd91c = 1;
      switch (typ) {
      case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
        while ((antwort = f_0bf820(DD, 0x2f0001cc, 2, 0x2f0001cd, 0x2f0001ce)) == -1) {}
        if (antwort == 1) {
          if (VC(p1, 0x6e) == 0) *(signed char *)&d_1c0364 = 2;
        } else {
          f_0bf730(DD, 0x2f0001cf);
          *(signed char *)&d_1c0364 = 3;
        }
        break;
      case 0x26:
        f_0bf730(DD, 0x2f0001d0);
        if (VC(p1, 0x6e) == 0) *(signed char *)&d_1c0364 = 2;
        int f_060a70_alias(void);
#pragma aux f_060a70_alias "W?f_060a70$n()i" modify exact [eax ebp]
        f_060a70_alias();
        break;
      case 0x18: case 0x19:
        while ((antwort = f_0bf820(DD, 0x2f0001d1, 2, 0x2f0001cd, 0x2f0001ce)) == -1) {}
        if (antwort == 1) {
          if (VC(p1, 0x6a) == 0) {
            *(signed char *)&d_1c0364 = 2;
            f_0dd750(d_1c0004, 0x13fe);
          }
        } else {
          f_0bf730(DD, 0x2f0001cf);
          *(signed char *)&d_1c0364 = 3;
        }
        break;
      case 0x1a:
        f_0bf730(DD, 0x2f0001d2);
        VC(p1, 0x6b);
        break;
      case 0x1b:
        f_0bf730(DD, 0x2f0001d3);
        VC(p1, 0x6a);
        break;
      default:
        *(signed char *)&d_1c0364 = 3;
        break;
      }
      *(volatile int *)&d_1bd91c = 0; // haelt das zweite Schreiben vor Funktionsende wie im Original
    } break;
  default:
      --d_1c036c;
  }

  if (EQ(d_1c0368, 0)) {
  zustand = *(signed char *)&d_1c0364;
  if (zustand >= 1) {
  *(signed char *)&d_1c0364 = --zustand;
  switch (zustand) {
  case 19:
    f_0bf730(DD, 0x2f000175);
    return;
  case 18:
    f_0fdd10(p1);
    return;
  case 16:
    f_0fdf00(p1);
    return;
  case 15:
    f_0fe5c0(p1);
    return;
  case 13:
    f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    switch (f_0de820(d_1c0004)) {
    case 0x17: zeit3 = 10; break;
    case 0x18: zeit3 = 20; break;
    case 0x19: zeit3 = 30; break;
    }
    zeit3 += f_0dd440(d_1c0004);
    switch ((unsigned short)(zeit3 - 11)) {
    case 11:
      o.p[1] = f_0396f0(d_1c0004, 0);
      f_0bf730(DD, 0x2f0001a3);
      f_0bf730(DD, 0x2f0001a4);
      break;
    case 3:
      o.p[1] = f_0396f0(d_1c0004, 0);
      f_0bf730(DD, 0x2f0001a5);
      break;
    case 4: case 5: case 6:
      f_0bf730(DD, 0x2f0001a6);
      break;
    case 0: case 1: case 2:
      f_0bf730(DD, 0x2f0001a7);
      break;
    }
    f_1254a0((int)&o, 0);
    return;
  case 12:
    f_0de820(d_1c0004);
    return;
  case 10:
    f_0feb40(p1);
    return;
  case 6:
    if (f_0de820(d_1c0004) == 0x19) {
      switch (f_0de820(d_1c0004)) {
      case 0x17: zeit2 = 10; break;
      case 0x18: zeit2 = 20; break;
      case 0x19: zeit2 = 30; break;
      }
      zeit2 += f_0dd440(d_1c0004);
      if ((short)zeit2 != 0x26 && (short)zeit2 != 0x21)
        f_0bf730(DD, 0x2f0001c4);
    }
    return;
  case 2:
    f_0fee00(p1);
    return;
  case 1:
    f_0bf730(DD, 0x2f0001cb);
    ((void (*)(int))f_0fbc60)(p1);
    return;
  }
  }
  } else {
    --d_1c0368;
  }
  }
}

//@ f_0fbc60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion durchsucht die Heldengruppe nach einem Gegenstand mit der ID p2, entfernt ihn
 *   optional (p4 != 0) oder verringert dessen Stapelzähler (p3 != 0) und gibt den Helden zurück, der den
 *   Gegenstand trägt.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Gegenstands-ID p2, das Zähler-Dekrement-Flag p3 sowie
 *   das Lösch-Flag p4.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den gefundenen Helden oder 0 zurück.
 === Ende Beschreibung === */
void f_0fbc60(void)
{
  struct SO o;
  short s;
  int iVar2;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  s = f_0db9a0(d_1c0004);
  if (0 < s) {
    f_0bf6c0(DD, 5);
    iVar2 = f_0606a0(0x2f0002, 0);
    f_0bfa20(DD, iVar2, 0, 0x2f000001, 0);
    DELO(iVar2)
    iVar2 = f_0606a0(0x2f0002, 1);
    f_0bfa20(DD, iVar2, 0, 0x2f000002, 0);
    DELO(iVar2)
    iVar2 = f_0606a0(0x2f0002, 2);
    f_0bfa20(DD, iVar2, 0, 0x2f000003, 0);
    DELO(iVar2)
    f_0bf680(DD);
    int f_0d64a0_alias(void);
#pragma aux f_0d64a0_alias "W?f_0d64a0$n()i" value [edx] modify exact [eax]
    f_0de210(*(volatile int *)&d_1c0004, 10); // haelt die Auswertungsreihenfolge (this vor Argument) wie im Original
    *(short *)&d_1c21a4 = (short)f_0d64a0_alias();
  }
  f_1254a0((int)&o, 0);
}
//@ f_0fbd80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt für jedes lebende und handlungsfähige Mitglied der Heldengruppe eine Talentprobe
 *   auf das Talent p2 mit der Erschwernis p3 durch, zählt die bestandenen Proben und würfelt bei jedem
 *   gescheiterten Helden 1W(p4) Schadenspunkte (f_044850), sofern p4 > 0 angegeben ist (etwa beim Schwimmen oder
 *   Klettern während des Schiffsuntergangs).
 *   - Hinweis (Originalfehler): Da der Programmierer innerhalb der Heldenschleife den oberen Würfelgrenzwert p4
 *     mit dem Würfelergebnis p4 = f_1457e0(p4) überschreibt (mov edi, eax), sinkt der maximal mögliche Schaden
 *     mit jedem verletzten Helden immer weiter ab, bis ab dem ersten gewürfelten 1-Ergebnis alle nachfolgenden
 *     Helden nur noch genau 1 Schadenspunkt erhalten.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Talentnummer p2, den Probenmodifikator p3 sowie den
 *   maximalen Würfelschaden p4.
 * - Rückgabewert: Die Funktion gibt die Anzahl der Helden zurück, die die Talentprobe bestanden haben.
 === Ende Beschreibung === */
int f_0fbd80(int p1, short p2, short p3, short p4)
{
  int s;
  int p1_00, iVar3;
  p1_00 = f_038c40(d_1c0004);
  iVar3 = 0;
  do {
    if (p1_00 != 0) {
      if (f_0d4a60(p1_00) != 0) {
        s = f_044c90(p1_00, (short)p2, (signed char)p3);
        if (s > 0) {
          iVar3 = iVar3 + 1;
        } else {
          if (0 < p4) {
#if FIX_R058
            f_044850(p1_00, f_1457e0(p4), 5);
#else
            p4 = f_1457e0(p4);
            f_044850(p1_00, p4, 5);
#endif
          }
        }
      }
    }
    p1_00 = f_0391b0(d_1c0004, p1_00);
  } while (p1_00 != f_038c40(d_1c0004));
  return iVar3;
}
//@ f_0fbe10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet das Öffnen einer verschlossenen Schiffstür an den Kartenkoordinaten (p2,
 *   p3) mithilfe eines passenden Schlüssels (p4), eines Dietrichs oder durch rohe Gewalt und aktualisiert bei
 *   Erfolg das zugehörige Türflag *p5 sowie die 3D-Wanddaten.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die X-/Y-Koordinaten p2 und p3, die Schlüssel-ID p4 sowie
 *   den Zeiger p5 auf das Zustandsbyte der Tür.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fbe10(int p1)
{
  short s;
  int q, r;
  r = 1;
  q = f_038c80(d_1c0004);
  do {
    if (q != 0 && f_0d4a60(q) != 0 && (signed char)((short)(f_042400((struct hero *)(q)))) == 0) {
      s = f_042a60((struct hero *)(q), 10);
      if (f_042380((struct hero *)(q)) == 1) {
        if (s != 0x1b8) r = 0;
      } else {
        if (s != 0 && s != 0x1b8) r = 0;
      }
      if (f_042a60((struct hero *)(q), 5) != 0x1b9) r = 0;
      if (f_042a60((struct hero *)(q), 0) != 0) r = 0;
    }
    q = f_0391b0(d_1c0004, q);
  } while (q != f_038c80(d_1c0004) && r == 1);
  return r;
}
//@ f_0fbee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert die Interaktion mit einer Schiffskabine oder Vorratskammer (d_1c0372/d_1c03a1),
 *   in der die Helden Vorräte oder Ausrüstung durchsuchen und bei bestimmten Aktionen Kämpfe oder Alarme
 *   auslösen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fbee0(int p1, unsigned short p2)
{
  struct SO o;
  short s;
  int iVar2;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  switch (p2) {
  case 1:
    f_0fc0d0(p1, 0x2f010006, 0);
    break;
  case 2:
    if (f_0fbe10(p1) == 1) {
      o.p[1] = f_038c40(d_1c0004);
      do { s = f_0bf820(DD, 0x2f01001d, 2, 0x2f01001e, 0x2f01001f); } while (s == -1);
      if (s == 1) {
        NEWC(iVar2, 0x291, 0x2c000c)
        ENDC(iVar2, 0x2f010020)
        d_1c0370 = 2;
        f_0fca60(p1);
        f_1254a0((int)&o, 0);
        return;
      }
      f_0fc5a0(p1, 0x2f010021);
      f_1254a0((int)&o, 0);
      return;
    } else {
      d_1c038c = d_1c038c + 1;
      f_0fc0d0(p1, 0x2f010026, 0);
      f_1254a0((int)&o, 0);
      return;
    }
  case 3:
    s = f_0de1c0(d_1c0004, 0xd, 10);
    if (s == 0) {
      f_0fc5a0(p1, 0x2f010027);
    } else {
      f_0fc0d0(p1, 0x2f010028, 0);
    }
    f_1254a0((int)&o, 0);
    return;
  }
  f_1254a0((int)&o, 0);
  return;
}
//@ f_0fc0d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Methode steuert die Ereignisse in der Kapitäns- oder Offizierskajüte
 *   (d_1c0373/d_1c0374), darunter das Durchsuchen von Seekarten und Logbüchern, das Öffnen gesicherter Truhen
 *   und das Auslösen von Wachen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fc0d0(int p1, int p2, int p3)
{
  extern void f_0fca60_clobber_local(int);
#pragma aux f_0fca60_clobber_local "f_0fca60" parm [eax] modify [edx]
  struct SO o;
  short s, v;
  int iVar3, iVar5, uVar4;
  signed char cVar1;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  iVar3 = f_038c40(d_1c0004);
  o.p[1] = iVar3;
  uVar4 = f_039420(d_1c0004, 0xd);
  o.p[2] = uVar4;
  if ((short)p3 == 0) {
    iVar5 = f_0606a0(0x2f0002, 10);
    do { v = f_0bfa20(DD, iVar5, 0, p2, 2, 0x2f010007, 0x2f010008); } while (v == -1);
    DELO(iVar5)
  }
  if (v == 2) {
    NEWC(iVar3, 0x2dd, 0x2c000c)
    ENDC(iVar3, 0x2f010009)
    signed char *status = &d_1c0370; // haelt die Registerfolge (ch statt dh) im spaeteren Zweig wie im Original
    d_1c0370 = 2;
    *status = 2;
    d_1c0370 = 2;
    *status = 2;
    d_1c0370 = 2;
    f_0fca60_clobber_local(p1);
    f_1254a0((int)&o, 0);
    return;
  }
  if ((short)p3 == 0) {
    s = f_0db940(d_1c0004);
    if (1 < s) {
      o.p[1] = iVar3;
      do {
        do { iVar3 = f_0391b0(d_1c0004, iVar3); } while (iVar3 == 0);
        iVar5 = f_0d4a60(iVar3);
      } while (iVar5 == 0);
      iVar5 = f_0606a0(0x2f0002, 0xc);
      o.p[2] = iVar3;
      f_0bfa20(DD, iVar5, 0, 0x2f01000a, 0);
      DELO(iVar5)
      iVar3 = f_0606a0(0x2f0002, 0xd);
      do { s = f_0bfa20(DD, iVar3, 0, 0x2f01000b, 3, 0x2f010008, 0x2f01000d, 0x2f01000e); } while (s == -1);
      DELO(iVar3)
    } else {
      p2 = f_0606a0(0x2f0002, 0xd);
      do { s = f_0bfa20(DD, p2, 0, 0x2f01000c, 3, 0x2f010008, 0x2f01000d, 0x2f01000e); } while (s == -1);
      DELO(p2)
      INCV(d_1c038c);
    }
  } else {
    iVar3 = f_0606a0(0x2f0002, 0xd);
    uVar4 = f_038c40(d_1c0004);
    o.p[1] = uVar4;
    do { s = f_0bfa20(DD, iVar3, 0, p2, 3, 0x2f010008, 0x2f01000d, 0x2f01000e); } while (s == -1);
    DELO(iVar3)
  }
  if (s == 2) {
    iVar3 = f_038c40(d_1c0004);
    do {
      do { uVar4 = iVar3 = f_0391f0(d_1c0004, iVar3); } while (iVar3 == 0);
      iVar5 = f_0d4a60(iVar3);
    } while (iVar5 == 0);
    o.p[1] = uVar4;
    iVar3 = f_0606a0(0x2f0002, 0xb);
    do { f_0bde40(DD); s = f_0bfa20(DD, iVar3, 0, 0x2f01000f, 2, 0x2f010008, 0x2f01000e); } while (s == -1);
    signed char one;
    if (iVar3 != 0) { operator delete((void *)((int)(((RivaRasterImage*)(iVar3))->f_0fad20( 0)))); one = 1; }
    else { one = 1; }
    int keep32 = d_1c0004;
    keep32 = (keep32 & 0) ? 0 : keep32; // haelt die Registerfolge wie im Original
    unsigned char keep8 = *(unsigned char *)&d_1c0370;
    keep8 = (keep8 & 0) ? 0 : keep8; // haelt die Registerfolge wie im Original
    signed char remaining = d_1c038c - one;
    d_1c0374 = one;
    d_1c038c = remaining;
    d_1c0004 = keep32;
    *(unsigned char *)&d_1c0370 = keep8;
  }
  if (s == 1) {
    NEWC(iVar3, 0x343, 0x2c000c)
    ENDC(iVar3, 0x2f010009)
    d_1c0370 = 2;
    f_0fca60_clobber_local(p1);
    f_1254a0((int)&o, 0);
    return;
  }
  uVar4 = f_038c40(d_1c0004);
  o.p[1] = uVar4;
  iVar3 = f_0606a0(0x2f0002, 0xe);
  f_0bfa20(DD, iVar3, 0, 0x2f010010, 0);
  DELO(iVar3)
  short amount = f_1457e0(6) + 3;
  cVar1 = f_0423c0((struct hero *)(uVar4));
  s = amount - (short)cVar1;
  if (s < 4) { s = 4; }
  f_044300(uVar4, s);
  f_0bbf00((int)&d_1bf230);
  s = f_0db940(d_1c0004);
  if (s > 1) {
    uVar4 = 0x2f010011;
  } else {
    if (s != 1) goto done;
    uVar4 = 0x2f010012;
  }
  f_0fc6e0(p1, uVar4);
done:
  f_1254a0((int)&o, 0);
}
//@ f_0fc5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet das Öffnen und Durchsuchen einer verschlossenen Kiste oder Koje (d_1c0375) an
 *   Bord des Schiffs, einschließlich Schlüssel- und Schlösserknacken-Probe sowie Beuteübergabe.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fc5a0(int p1, int p2)
{
  extern void f_0fca60_clobber(int);
#pragma aux f_0fca60_clobber "f_0fca60" parm [eax] modify [edx]
  struct SO o;
  short s;
  int iVar3;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  o.p[1] = f_038c40(d_1c0004);
  iVar3 = f_0606a0(0x2f0002, 10);
  do { s = f_0bfa20(DD, iVar3, 0, p2, 2, 0x2f010022, 0x2f010023); } while (s == -1);
  DELO(iVar3)
  if (s == 1) {
    NEWC(iVar3, 0x389, 0x2c000c)
    ENDC(iVar3, 0x2f010024)
    d_1c0370 = 2;
    f_0fca60_clobber(p1);
    f_1254a0((int)&o, 0);
    return;
  }
  f_0fc0d0(p1, 0x2f010025, 1);
  f_1254a0((int)&o, 0);
}
//@ f_0fc6e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wickelt die mehrstufige Untersuchung eines Schiffsraums (d_1c0376) ab, in dem die
 *   Helden Hinweise, Schlüssel oder nützliche Werkzeuge für die Sabotage des Schiffs finden können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fc6e0(int p1, int p2)
{
  struct SO o;
  short s, t;
  int iVar3;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  o.p[1] = f_038c40(d_1c0004);
  { int t_ = (int)operator new(0x13e, mark(d_1a67f4, 0x3aa)); iVar3 = (t_ != 0) ? f_0104b0(t_, 0x2c000d, 0, 0) : t_; }
  f_0bf6c0(DD, 7);
  do { s = f_0bf980(DD, iVar3, 0, p2, 3, 0x2f01000d, 0x2f010013, 0x2f010014); } while (s == -1);
  f_0bf680(DD);
  if (iVar3 != 0) operator delete((void *)f_010590(iVar3, 0));
  if (s == 1) {
    t = f_0db940(d_1c0004);
    if (t > 1 && ((d_1c038c < 1) & 1)) {
      extern signed char d_1c0374_nv;
#pragma aux d_1c0374_nv "d_1c0374"
      extern signed char d_1c0378_nv;
#pragma aux d_1c0378_nv "d_1c0378"
      d_1c0374_nv = 1;
      d_1c0378_nv = 1;
      d_1c038c++;
      do { s = f_0bf820(DD, 0x2f01001b, 2, 0x2f010013, 0x2f010014); } while (s == -1);
      s = s + 1;
    } else {
      do { s = f_0bf820(DD, 0x2f010015, 2, 0x2f010016, 0x2f010017); } while (s == -1);
      if (s == 2) {
        s = 0;
        d_1c0370 = 2;
        NEWC(iVar3, 0x3d7, 0x2c000c)
        ENDC(iVar3, 0x2f01001a)
      } else {
        s = 3;
      }
    }
  }
  if (s == 2) {
    d_1c0370 = 1;
    s = 0;
    NEWC(iVar3, 0x3f0, 0x2c000c)
    ENDC(iVar3, 0x2f01001c)
  } else if (s == 3) {
    if ((int)t == 1 || ((d_1c038c >= 1) & 1)) {
      f_0bf730(DD, 0x2f010019);
      int f_0de210_alias(int, int);
#pragma aux f_0de210_alias "f_0de210" parm [eax edx] value [edx] modify exact [eax];
      *(short *)&d_1c21a4 = (short)f_0de210_alias(*(volatile int *)&d_1c0004, 10); // haelt die Auswertungsreihenfolge (this vor Argument) wie im Original
    } else {
      f_0bf730(DD, 0x2f010018);
      NEWC(iVar3, 0x40a, 0x2c000c)
      ENDC(iVar3, 0x2f010009)
      d_1c038c++;
      d_1c0370 = 1;
      s = 0;
    }
  }
  if (s == 0) { f_0fca60(p1); }
  f_1254a0((int)&o, 0);
}
