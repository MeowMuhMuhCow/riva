/* === Beschreibung (Katalog) ===
 * Einheit gz_0b2640 (0x0B2640 - 0x0B3240)
 *
 * Fortsetzung der Orts- und Stadtaktionen (loc_acti.cpp): Stadttor-/Wachen-Dialoge, Bestechung, Kauf von
 * Stadtkarten-Markierungen und Flucht-/Ortswechsel-Abfragen.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
// P3 10/14 gleich (suche.py 24.10.2026, Basis gz_0b2640_P1.CPP)
// gz_0b2640.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B2640-0x0B3240
#include <string.h>
#define EQI(x,v) (((x)==(v))?1:0)
#define I32(p,o) (*(int *)((p)+(o)))
#define A64 ((int)&d_1c2c64)
int f_019fb0(int p1);
int f_019fd0(int p1, int p2, int p3, int p4, int p5);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039660(int p1, int p2);
int f_044850(int p1, int p2, int p3);
int f_056a50(int p1);

int f_0b8490(int p1, int p2);
int f_0b8520(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820(int, ...);
int f_0d5ff0(int p1);
int f_0db8b0(int p1, int p2);
short f_0dcf00(int p1, int p2, int p3);
int f_0dd7f0(int p1, int p2, int p3);
signed char f_0dd410(int p1, int p2);
int f_0de7e0(int p1);
short f_0de820(int p1);
int f_0e93f0(int p1, int p2, int p3);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_125f70(int p1, int p2);
int f_145234(int p1, int p2);
int f_145254();
int f_0b2cc0(unsigned short *p1);
void operator delete(void *p);
extern signed char d_1bed60;
extern short d_1bed61;
extern signed char d_1bed6c;
extern signed char d_1bed90;
extern int d_1c0004;
extern signed char d_1c00b0;
extern signed char d_1c00bc;
extern signed char d_1c00c0;
extern signed char d_1c01d8;
extern signed char d_1c0240;
extern volatile short d_1c212a;
extern int *d_1c212c;
extern int d_1c27a8[];
extern int d_1c2a84;

extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0[];
extern char d_1bb1d0[];
extern char d_1bb1e4[];
extern const char d_1b8214[];
struct SO2 { int a; int *p; char pad[0xc]; short *q; char pad2[0x24]; };
#define Q(x) EQI(x,1)
int f_15ead2(const char *b, const char *c, ...);
#define SS(buf,fmt,x,y) f_15ead2((const char *)(buf), fmt, x, y)
#define SCANLOOP { DECLAB unsigned p5 = 0x120000a2; int p3 = 0x120000a3; do { f_0e93f0((int)d_1c38b0, (int)d_1c27a8, p3); p3 += 2; SS(d_1c27a8, d_1b8214, &a, &b); f_019fd0((int)&d_1c2a84, 0, (int)a << 16, (int)b << 16, p5); p5 += 2; } while (p5 < 0x120000e4); }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0b2640
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion verarbeitet den Aktionscode 6 im Feld +0x50 eines Ortsobjekts: Sofern das
 *   Handlungsflag d_1c0240 gesetzt ist, zeigt sie eine fünfteilige Ereignis-Textsequenz (0x250000f4 bis
 *   0x250000f8) für den Gruppenführer an, zieht ihm über f_044850 Lebenspunkte ab und löst den Szenenübergang
 *   f_0d5ff0(6) aus.
 * - Eingaben: Übergeben wird ein Zeiger auf die Orts-/Gebäudestruktur (p1).
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_0b2640(int p1)
{
  struct SO2 o;
  if (I32(p1, 0x50) == 6) {
    I32(p1, 0x50) = 0;
    if (Q(d_1c0240)) {
      f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      o.p[1] = f_038c40(d_1c0004);
      f_0bf730(A64, 0x250000f4);
      f_0bf730(A64, 0x250000f5);
      f_0bf730(A64, 0x250000f6);
      f_044850(f_038c40(d_1c0004), 5, 5);
      f_0bf730(A64, 0x250000f7);
      f_0d5ff0(6);
      f_0bf730(A64, 0x250000f8);
      f_1254a0((int)&o, 0);
    }
  }
  return 0;
}
//@ f_0b2720
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion initialisiert die globale Spielstandsvariable d_1bed60 mit dem Wert 0 und der
 *   Kennung 0x26c und trägt sie in die globale Spielstands-Variablentabelle (d_1c212a / d_1c212c) ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b2720(void)
{
  d_1bed60 = 0;
  d_1bed61 = 0x26c;
  d_1c212c[d_1c212a] = (int)&d_1bed60;
  ++d_1c212a;
}
//@ f_0b2760
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion gibt für den Ortstyp 0x40 je nach aktuellem Kapitel-/Stadtstatus (d_1c00b0,
 *   d_1c00c0 und d_1bed6c) einen der drei Hinweistexte 0x2201003f, 0x22010040 oder 0x22010041 in einem
 *   Textfenster aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b2760(void)
{
  if (Q(d_1c00b0)) f_0bf730(A64, 0x2201003f);
  else if (Q(d_1c00c0)) { if (Q(d_1bed6c)) f_0bf730(A64, 0x22010040); else f_0bf730(A64, 0x22010041); }
}
//@ f_0b27d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion gibt für den Ortstyp 0x41 abhängig von den Statusflags d_1c00b0 und d_1c00c0
 *   entweder den Hinweistext 0x22010042 oder 0x22010043 aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b27d0(void)
{
  if (Q(d_1c00b0)) f_0bf730(A64, 0x22010042);
  else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010043);
}
//@ f_0b2820
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion gibt für den Ortstyp 0x42 abhängig von den Statusflags d_1c00b0 und d_1c00c0
 *   entweder den Hinweistext 0x22010044 oder 0x22010045 aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b2820(void)
{
  if (Q(d_1c00b0)) f_0bf730(A64, 0x22010044);
  else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010045);
}
//@ f_0b2870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion liest aus den Textressourcen 0x120000a3 bis 0x120000e3 die Koordinatenpaare
 *   ("%d,%d") sämtlicher wichtiger Gebäude von Riva aus, trägt sie mit ihren jeweiligen Beschriftungskennungen
 *   (0x120000a2 bis 0x120000e2) in die Automap-/Stadtkartenverwaltung (d_1c2a84, f_019fd0) ein und aktiviert die
 *   Kartenmarkierungen (f_019fb0).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#define DECLAB short a, b;
void f_0b2870(void)
{
  SCANLOOP
  f_019fb0((int)&d_1c2a84);
}
//@ f_0b2900
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dieser Konstruktor initialisiert ein Stadt-Interaktionsobjekt über den Basiskonstruktor
 *   f_0b8490 und trägt die zugehörige virtuelle Methodentabelle (d_1bb1e4) an Offset +0x58 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das zu initialisierende Ortsobjekt (p1) und die Ortskennung (p2).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf das initialisierte Ortsobjekt zurück.
 === Ende Beschreibung === */
int f_0b2900(int p1, short p2)
{
  int r = f_0b8490(p1, p2);
  I32(r, 0x58) = (int)d_1bb1e4;
  return r;
}
//@ f_0b2910
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dieser virtuelle Destruktor baut das Stadt-Interaktionsobjekt über den Basisdestruktor
 *   f_0b8520 ab und gibt bei gesetztem Bit 2 in den Destruktor-Flags (p2 & 2) den Objektspeicher frei.
 * - Eingaben: Übergeben werden ein Zeiger auf das Ortsobjekt (p1) und die Destruktor-Steuerflags (p2).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf das bereinigte Ortsobjekt zurück.
 === Ende Beschreibung === */
int f_0b2910(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb1d0);
    f_145254();
    return p1;
  }
  I32(p1, 0x58) = (int)d_1bb1e4;
  r = f_0b8520(p1, 1);
  if (p2 & 2) delete (char *)r;
  return r;
}
//@ f_0b2950
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion ist eine leere virtuelle Platzhaltermethode der Stadt-Interaktionsklasse.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b2950(void)
{
}
//@ f_0b2960
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese virtuelle Ereignismethode verarbeitet das Betreten oder Untersuchen eines Stadtorts
 *   (p2 == 0x80 oder 0x81, delegiert an f_0b2cc0) und bietet am Ort 0x1e einmalig (d_1bed60 == 0) den Kauf eines
 *   vollständigen Stadtplans von Riva (Gegenstand 0x16a) an, der bei Bezahlung alle Gebäudemarkierungen auf der
 *   Stadtkarte freischaltet (f_019fd0, f_019fb0).
 * - Eingaben: Übergeben werden ein Zeiger auf das Ortsobjekt (p1) und der Ereigniscode (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Ortsinteraktion aktiv verarbeitet wurde, und sonst 0.
 === Ende Beschreibung === */
static inline int h_0b2cc0(unsigned short *p1)
{
  int r = 0;
  switch (*p1) {
  case 0x40:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x2201003f);
    else if (Q(d_1c00c0)) { if (Q(d_1bed6c)) f_0bf730(A64, 0x22010040); else f_0bf730(A64, 0x22010041); }
    break;
  case 0x41:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x22010042);
    else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010043);
    break;
  case 0x42:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x22010044);
    else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010045);
    break;
  case 0x55:
    f_056a50(p1[0x13] + 0x150007);
    if (Q(d_1c00bc)) r = 1;
    break;
  default:
    f_056a50(p1[0x13] + 0x150007);
    if (f_0dd410(d_1c0004, 0) == 1) r = 1;
  }
  return r;
}

int f_0b2960(unsigned short *p1, short p2)
{
  struct SO2 o;
  int r = 0;
  short s;
  int found;
  switch ((unsigned short)p2) {
  case 0x80:
    r = 1;
    break;
  case 0x81:
    r = h_0b2cc0(p1);
    break;
  }
  if (r == 1 && *p1 == 0x1e && EQI(d_1bed60, 0)) {
    f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    s = ((int)(((RivaItemDefinition*)(I32((*(int*)&d_1c2c40), 0x5a8)))->f_0a7820()));
    o.p[1] = f_039660(d_1c0004, 10);
    o.q[1] = s;
    f_0bf730(A64, 0x22000082);
    found = 0;
    if (f_0bf6f0(A64, 0x22000083) == 1) {
      if (f_0de7e0(d_1c0004) >= s * 100 && f_0dcf00(d_1c0004, 0x16a, 1) == 1) {
        d_1bed60 = 1;
        f_0bf730(A64, 0x22000084);
        f_0db8b0(d_1c0004, s * 100);
        SCANLOOP
        found = 1;
        f_019fb0((int)&d_1c2a84);
      }
    }
    if (!found) f_0bf730(A64, 0x22000085);
    f_1254a0((int)&o, 0);
  }
  return r;
}
//@ f_0b2cc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion führt die ortsabhängige Untersuchung oder Namensanzeige anhand der
 *   Ortskennung (*p1) aus: Für 0x40-0x42 gibt sie statische Ortsbeschreibungen aus, während sie für 0x55 und
 *   alle anderen Kennungen die Ortsbezeichnung auf der Statuszeile anzeigt (f_056a50) und prüft, ob ein Betreten
 *   möglich ist (f_0dd410).
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1), dessen erstes unsigned short-Feld die
 *   Ortskennung enthält.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Ort betreten werden kann, und sonst 0.
 === Ende Beschreibung === */
int f_0b2cc0(unsigned short *p1)
{
  int r = 0;
  switch (*p1) {
  case 0x40:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x2201003f);
    else if (Q(d_1c00c0)) { if (Q(d_1bed6c)) f_0bf730(A64, 0x22010040); else f_0bf730(A64, 0x22010041); }
    break;
  case 0x41:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x22010042);
    else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010043);
    break;
  case 0x42:
    if (Q(d_1c00b0)) f_0bf730(A64, 0x22010044);
    else if (Q(d_1c00c0)) f_0bf730(A64, 0x22010045);
    break;
  case 0x55:
    f_056a50(p1[0x13] + 0x150007);
    if (Q(d_1c00bc)) r = 1;
    break;
  default:
    f_056a50(p1[0x13] + 0x150007);
    if (f_0dd410(d_1c0004, 0) == 1) r = 1;
  }
  return r;
}
//@ f_0b2e80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion fragt den Spieler je nach aktuellem Umgebungsbereich (f_0de820(d_1c0004) == 0
 *   bei gesetztem Flag d_1c01d8 oder Bereich != 0) über ein Auswahlfenster (0x2200003d), ob die Gruppe zwischen
 *   Stadtgebiet und Umland wechseln möchte, und führt bei Zustimmung den Ortswechsel über f_0dd7f0 (nach
 *   Position 0x165f im Bereich 2 bzw. 0x18b4 im Bereich 0) aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b2e80(void)
{
  if (f_0de820(d_1c0004) == 0) {
    if (!Q(d_1c01d8)) return;
    if (f_0bf820(A64, 0x2200003d, 2, 0x2200003e, 0x2200003f) != 1) return;
    f_0dd7f0(d_1c0004, 2, 0x165f);
  } else {
    if (f_0bf820(A64, 0x2200003d, 2, 0x22000040, 0x22000041) != 1) return;
    f_0dd7f0(d_1c0004, 0, 0x18b4);
  }
}
//@ f_0b2f30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert den Dialog am Stadttor (Auswahlmenü 0x22000033 mit drei Optionen): Je
 *   nach Wahl vergeht eine Viertelstunde (f_125ed0), der Torwächter lässt sich gegebenenfalls überreden bzw.
 *   nimmt Gegenstand 0x162 an (d_1bed90 = 1), oder die Gruppe wechselt zwischen Stadt und Umland (f_0dd7f0).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe das Tor passiert bzw. die Szene verlässt, und 0,
 *   wenn das Gespräch vorher endet.
 === Ende Beschreibung === */
int f_0b2f30(void)
{
  struct SO2 o;
  int r;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  r = 0;
  switch ((unsigned short)(f_0bf820(A64, 0x22000033, 3, 0x22000034, 0x22000035, 0x22000036) + 1)) {
  case 0:
  case 2:
    f_125ed0((int)&d_1c2c44, 0xf);
    f_0bf730(A64, 0x2200003a);
    d_1c01d8 = 1;
    goto done;
  case 3:
    o.p[1] = f_039320(d_1c0004, 0x30);
    if (f_0bf6f0(A64, 0x2200003b) == 1) f_0dcf00(d_1c0004, 0x162, 1);
    d_1bed90 = 1;
    f_125ed0((int)&d_1c2c44, 0xf);
    f_0bf730(A64, 0x2200003c);
    goto done;
  case 1:
  case 4:
    break;
  }
  if (f_0de820(d_1c0004) == 0) {
    if (Q(d_1c01d8) && f_0bf820(A64, 0x2200003d, 2, 0x2200003e, 0x2200003f) == 1) f_0dd7f0(d_1c0004, 2, 0x165f);
  } else {
    if (f_0bf820(A64, 0x2200003d, 2, 0x22000040, 0x22000041) == 1) f_0dd7f0(d_1c0004, 0, 0x18b4);
  }
  r = 1;
done:
  f_1254a0((int)&o, 0);
  return r;
}
//@ f_0b30f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion führt die erweiterte Stadttor-Kontrolle durch, bei der nach einer
 *   Bestätigungsfrage (0x22000032) und dem Auswahlmenü (0x22000033) entweder 2 Stunden Wartezeit (f_125f70) oder
 *   15 Minuten Diskussionszeit (f_125ed0) vergehen, bevor der eigentliche Übergang zwischen Stadt und Umland
 *   (f_0dd7f0) angeboten wird.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b30f0(void)
{
  if (f_0bf6f0(A64, 0x22000032) == 1) {
    switch (f_0bf820(A64, 0x22000033, 3, 0x22000034, 0x22000035, 0x22000036)) {
    case -1:
      goto La;
    case 1:
    La:
      f_125f70((int)&d_1c2c44, 2);
      f_0bf730(A64, 0x22000037);
      break;
    case 2:
      f_125ed0((int)&d_1c2c44, 0xf);
      switch (f_0bf820(A64, 0x22000038, 2, 0x22000034, 0x22000039)) {
      case -1:
        goto La;
      case 1:
        goto La;
      case 2:
        break;
      }
      break;
    case 3:
      break;
    }
  }
  if (f_0de820(d_1c0004) == 0) {
    if (!Q(d_1c01d8)) return;
    if (f_0bf820(A64, 0x2200003d, 2, 0x2200003e, 0x2200003f) != 1) return;
    f_0dd7f0(d_1c0004, 2, 0x165f);
  } else {
    if (f_0bf820(A64, 0x2200003d, 2, 0x22000040, 0x22000041) != 1) return;
    f_0dd7f0(d_1c0004, 0, 0x18b4);
  }
}
