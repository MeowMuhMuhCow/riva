/* === Beschreibung (Katalog) ===
 * Einheit gz_0ec070_t1
 *
 * Diese Einheit implementiert den ersten Teil der Skript- und Ereignissteuerung für besondere Schauplätze und
 * Zwischensequenzen (vermutlich das Finale beziehungsweise die Königinnen- und Dämonenszenen im letzten
 * Spielabschnitt) und koordiniert dort Raumwechsel, Dialoge, Kämpfe und Animationen.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 9/10 gleich (suche.py 28.10.2026, Basis gz_0ec070_t1_P1.CPP)
// OPT -4r -onetx -zp1 -s
// P1 5/10 gleich
// gz_0ec070.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0EC070-0x0ED980
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
typedef RivaTextContextData OB;
#define DEL(h) if (h) operator delete(((void *)(((RivaRasterImage*)(h))->f_0fad20( 0))))
#define EQI(x,v) (((x)==(v))?1:0)
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern char d_1c2c64[], d_1c2c44[], d_1c2c00[], d_1c2a84[], d_1bf230[];
extern int d_1c0004;
extern unsigned char d_1bedfc, d_1bed6c, d_1bee1c, d_1c00a0, d_1c00a4, d_1c00b0, d_1c00bc, d_1c00c0, d_1c00cc, d_1c00d0, d_1c00d4, d_1c00e0, d_1c01dc;
extern signed char d_1bfab8, d_1bfaec, d_1c0ca4, d_1c0d64;
extern short d_1bdaf8, d_1c21a4;
extern void f_0ea230(void);
int f_125400(void *, const char *, const char *, const char *);
int f_1254a0(void *, int);

int f_0dd1d0(int, int);
int f_039660(int, int);
int f_038c40(int);
int f_038be0(int);
int f_039040(int);
int f_039320(int, int);
int f_0391b0(int, int);
int f_033530(int, int);




int f_0dd3a0(int, int, int);
int f_044850(int, int, int);
int f_040780(int, int);
int f_039a80(int, int);
int f_060800(int, int, int);
int f_0606a0(int, int);
int f_0dbda0(int);
short f_08c920(int, int);
int f_060a70(void);
int f_091f70(int);
int f_056a50(int);
int f_056a40(int);
int f_056a30(int);
int f_056930(void);
int f_056950(void);
int f_057220(void *, int, int);
int f_0d6690(int);
int f_0d4a60(int);
int f_0d64a0(void);
int f_0dd7f0(int, int, int);
short f_1457e0(int);
short f_0de7f0(int);
short f_0db9a0(int);
int f_10b890(int);
int f_03eca0(int);

int f_09a400(void);
int f_019fd0(void *, int, int, int, int);
int f_126410(void *);
int f_125ed0(void *, int);
int f_125f70(void *, int);
int f_0bf6c0(void *, int);
int f_0bf730(void *, int);
void f_0bf680(void *);
int f_0bde40(void *);
int f_0bbf00(void *);
int f_0bfa20(void *, ...);
short f_0bf820(void *, int, short, ...);

#define EQM(x,v) (((x)==(v))?1:0)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0ec070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der Haupteinstiegspunkt des Schauplatz-Moduls, lädt die zugehörigen Texte und
 *   Grafiken, initialisiert die lokalen Zustandsvariablen und verzweigt anhand der aktuellen Raum- oder
 *   Ereignisnummer in die einzelnen Szenenabläufe.
 * - Eingaben: Die Funktion erhält die Kennung des ausgelösten Ereignisses oder Aktionspunkts (p1).
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der ausgeführten Szene oder 0 zurück.
 === Ende Beschreibung === */
int f_0ec070(void)
{
  OB ob;
  int r, h;
  r = 0;
  if (f_0dd1d0(d_1c0004, 0x16b) == 1) {
    f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
    *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 1);
    f_0bf6c0(d_1c2c64, 6);
    h = f_0606a0(0x120001, 1);
    f_0bfa20(d_1c2c64, h, 0, 0x1200005a, 0);
    DEL(h);
    f_056a50(0x150012);
    d_1bedfc = 0x3c;
    f_091f70(0x3f);
    f_0bf680(d_1c2c64);
    r = 1;
    f_1254a0(&ob, 0);
  }
  return r;
}
//@ f_0ec150
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine mehrstufige Zwischensequenz mit Textdialogen, Kamerafahrten und
 *   Kampfauslösungen, prüft den Besitz bestimmter Schlüsselgegenstände in der Heldengruppe und aktualisiert nach
 *   einem gewonnenen Kampf die Raum- und Questflags.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Statuswert nach Abschluss der Szene zurück.
 === Ende Beschreibung === */
void f_0ec150(void)
{
      int codex_arg_0_154;
      int codex_arg_0_148;
  struct Prev { static inline void run(char *box, int h) { f_0bfa20(box,h,0,0x12000065,0); } };
  OB ob;
  int h6, h5, v1, h2, h3, h1, h4, s;
  short k;
  if (f_126410(d_1c2c44) >= 0xbdd8 && f_126410(d_1c2c44) <= 0x13c68) {
    f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
    h1 = f_0606a0(0x120001, 0xb);
    h2 = f_0606a0(0x120001, 0xc);
    h3 = f_0606a0(0x120001, 0xd);
    h4 = f_0606a0(0x120001, 0xe);
    h5 = f_0606a0(0x120001, 0xf);
    h6 = f_0606a0(0x120001, 0x10);
    v1 = f_038c40(d_1c0004);
    k = -1;
    s = f_0dd3a0(d_1c0004, 1, 0);
    if (s == 0) {
      s = f_0dd3a0(d_1c0004, 4, 0);
      if (s == 0)
        s = f_039320(d_1c0004, 0x17);
    }
    *(int *)(ob.addresses.objects + 4) = v1;
    *(int *)(ob.addresses.objects + 8) = s;
    f_0bf6c0(d_1c2c64, 6);
    f_0bfa20(d_1c2c64, h1, 0, 0x1200005b, 0);
    while (k == -1)
      k = f_0bf820(d_1c2c64, 0x1200005c, 2, 0x1200005d, 0x1200005e);
    if (k == 1) {
      k = -1;
      while (k == -1)
        k = f_0bf820(d_1c2c64, 0x1200005f, 2, 0x1200005d, 0x12000060);
    }
    switch (k) {
    case 1:
      f_0bf730(d_1c2c64, 0x12000061);
      if (f_08c920(0x83, 0) == 0) {
        f_060a70();
        f_0bf730(d_1c2c64, 0x12000062);
        d_1c21a4 = 0xb;
      }
      break;
    case 2:
      f_0bf730(d_1c2c64, 0x12000063);
      f_044850(s, 1, 5);
      f_0bbf00(d_1bf230);
      f_0bde40(d_1c2c64);
      f_0bfa20(d_1c2c64, f_042380((struct hero *)(s)) == 0 ? h2 : h3, 0, 0x12000064, 0);
      f_040780(s, 0xf);
      f_039a80((codex_arg_0_148 = d_1c0004), (int)f_0ea230);
      Prev::run(d_1c2c64,h4);
      f_060800(0x120010, 1, 0);
      f_0bfa20(d_1c2c64, h4, 0, 0x12000066, 0);
      f_0bf730(d_1c2c64, 0x12000067);
      f_0dbda0((codex_arg_0_154 = d_1c0004));
      f_0bf6c0(d_1c2c64, 5);
      f_0bfa20(d_1c2c64, h5, 0, 0x12000068, 0);
      f_0bf680(d_1c2c64);
      f_0bfa20(d_1c2c64, h4, 0, 0x12000069, 0);
      f_125ed0(d_1c2c44, 0x14);
      f_0bfa20(d_1c2c64, h6, 0, 0x1200006a, 0);
      f_0bfa20(d_1c2c64, h6, 0, 0x1200006b, 0);
      f_0bfa20(d_1c2c64, h4, 0, 0x1200006c, 0);
      f_0bfa20(d_1c2c64, h4, 0, 0x1200006d, 0);
      d_1c00c0 = 1;
      d_1c00cc = 0xf;
      f_091f70(0x40);
      f_057220(d_1c2c00, 0x803001b, 0);
      break;
    }
    f_0bf680(d_1c2c64);
    DEL(h1);
    DEL(h2);
    DEL(h3);
    DEL(h4);
    DEL(h5);
    DEL(h6);
    f_1254a0(&ob, 0);
  }
}
//@ f_0ec5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt einen interaktiven Auswahldialog an einer Tür oder Vorrichtung des Schauplatzes
 *   durch, wertet die Entscheidung des Spielers aus und startet je nach Wahl einen Kampf, eine Schadenswirkung
 *   oder einen Raumübergang.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der letzten Dialog- oder Ereignisaktion zurück.
 === Ende Beschreibung === */
int f_0ec5a0(void)
{
  OB ob;
  int r, p1, p2, iv;
  short c;
  p1 = f_0606a0(0x120001, 0xe);
  p2 = f_0606a0(0x120001, 0xf);
  f_0bf6c0(d_1c2c64, 6);
  f_0bfa20(d_1c2c64, p1, 0, 0x1200006f, 0);
  f_125ed0(d_1c2c44, 5);
  f_0bf730(d_1c2c64, 0x12000070);
  iv = f_0d6690(0);
  if (iv != 0) {
    c = f_042400((struct hero *)(f_039040(iv)));
    if (iv == d_1c0004 && (c == 1 || c == 3) && EQI(d_1bfab8, 0)) {
      if (f_0d4a60(f_039040(iv))) {
        f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
        *(int *)(ob.addresses.objects + 4) = f_039040(d_1c0004);
        f_0bf730(d_1c2c64, 0x12000071);
        f_1254a0(&ob, 0);
      }
      f_0d64a0();
    }
  }
  f_0bf6c0(d_1c2c64, 5);
  f_0bfa20(d_1c2c64, p2, 0, 0x12000072, 0);
  f_0bf680(d_1c2c64);
  d_1bed6c = 1;
  f_091f70(0x41);
  f_057220(d_1c2c00, 0x803001c, 0);
  r = 1;
  f_0dd7f0(d_1c0004, 4, 0x13f5);
  f_0bf680(d_1c2c64);
  DEL(p1);
  DEL(p2);
  return r;
}
//@ f_0ec760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft und schaltet den Zustand eines Mechanismus oder Durchgangs im aktuellen Gebiet
 *   um und gibt eine passende Statusmeldung auf dem Bildschirm aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der Textausgabe oder Zustandsänderung zurück.
 === Ende Beschreibung === */
int f_0ec760(void)
{
  int p;
  p = f_0606a0(0x120001, 0x11);
  f_0bfa20(d_1c2c64, p, 0, 0x1200006e, 0);
  DEL(p);
  return 1;
}
//@ f_0ec7b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt eine Untersuchungsszene an einem besonderen Objekt ab, lässt Helden Proben
 *   ablegen, vergibt gefundene Gegenstände oder Abenteuerpunkte und löst bei einem Fehlschlag eine Falle oder
 *   einen Angriff aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Statuscode der Szene zurück.
 === Ende Beschreibung === */
void f_0ec7b0(void)
{
  OB oa;
  OB ob;
  short s, n;
  int i2, i3, u4, u5, p1;
  int rr;
  if (EQM(d_1c0d64, 1)) {
  f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
  i2 = f_039660(d_1c0004, 5);
  i3 = f_038be0(d_1c0004);
  u4 = f_039660(d_1c0004, 1);
  p1 = f_0606a0(0x120001, 0x12);
  n = f_0de7f0(d_1c0004);
  if (1 < n) {
    while (i3 == i2) {
      i3 = f_038be0(d_1c0004);
    }
  }
  *(int *)(ob.addresses.objects + 4) = i2;
  *(int *)(ob.addresses.objects + 8) = i3;
  *(int *)(ob.addresses.objects + 0xc) = u4;
  f_0bf6c0(d_1c2c64, 6);
  f_0bf730(d_1c2c64, 0x12000073);
  f_0bfa20(d_1c2c64, p1, 0, 0x12000074, 0);
  f_0bfa20(d_1c2c64, p1, 0, 0x12000075, 0);
  f_10b890(0xe);
  f_0bf730(d_1c2c64, 0x12000076);
  if (1 < n) {
    f_0bf730(d_1c2c64, 0x12000077);
  }
  f_0bf680(d_1c2c64);
  DEL(p1);
  d_1c00b0 = 1;
  f_057220(d_1c2c00, 0x803001d, 0);
  f_091f70(0x42);
  f_056930();
  f_056a40(2);
  f_056950();
  f_1254a0(&ob, 0);
  } else {
    if (((d_1c0ca4 != 0) ? 1 : 0)) {
      f_125400(&oa, d_1c349c, d_1c3870, d_1c3498);
      u4 = f_039660(d_1c0004, 2);
      u5 = f_039660(d_1c0004, 0xd);
      *(int *)(oa.addresses.objects + 4) = u4;
      *(int *)(oa.addresses.objects + 8) = u5;
      f_0bf6c0(d_1c2c64, 6);
      if (EQM(d_1c0ca4, 1) || (EQM(d_1c0ca4, 2) && (rr = f_1457e0(100)) < 10)) {
        f_0bf730(d_1c2c64, 0x12000078);
        if (EQM(d_1c0ca4, 1)) {
          f_057220(d_1c2c00, 0x803001e, 0);
          d_1c0ca4 = 2;
        }
      }
      f_0bf680(d_1c2c64);
      f_1254a0(&oa, 0);
    }
  }
}
//@ f_0eca40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine Begegnung mit einem wichtigen Nichtspielercharakter oder Gegner in diesem
 *   Bereich, zeigt das zugehörige Porträt samt Dialogoptionen an und leitet abhängig von der Antwort einen Kampf
 *   oder eine friedliche Einigung ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Ergebniswert der Begegnung zurück.
 === Ende Beschreibung === */
void f_0eca40(void)
{
  OB ob;
  int u1, u2, p1, i3, h;
  short n;
  f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
  u1 = f_038c40(d_1c0004);
  u2 = f_039320(d_1c0004, 0x1b);
  p1 = f_039320(d_1c0004, 0x18);
  i3 = f_038be0(d_1c0004);
  h = f_0606a0(0x120001, 0x13);
  n = f_0db9a0(d_1c0004);
  if (1 < n) {
    while (i3 == p1) {
      i3 = f_038be0(d_1c0004);
    }
  }
  *(int *)(ob.addresses.objects + 4) = u1;
  *(int *)(ob.addresses.objects + 8) = u2;
  *(int *)(ob.addresses.objects + 0xc) = p1;
  *(int *)(ob.addresses.objects + 0x10) = i3;
  f_0bf6c0(d_1c2c64, 6);
  f_0bfa20(d_1c2c64, h, 0, 0x12000079, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x1200007a, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x1200007b, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x1200007c, 0);
  f_125f70(d_1c2c44, 2);
  f_0bfa20(d_1c2c64, h, 0, 0x1200007d, 0);
  if (1 < n) {
    f_0bf730(d_1c2c64, 0x1200007e);
  }
  f_0bfa20(d_1c2c64, h, 0, 0x1200007f, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x12000080, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x12000081, 0);
  f_0bfa20(d_1c2c64, h, 0, 0x12000082, 0);
  f_0bf680(d_1c2c64);
  DEL(h);
  f_040780(p1, 5);
  d_1c00a4 = 1;
  f_057220(d_1c2c00, 0x803001f, 0);
  f_091f70(0x43);
  f_056930();
  f_056a30(0xb);
  f_056950();
  f_1254a0(&ob, 0);
}
//@ f_0ecc70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet das Betreten einer Gefahrenzone oder Rätselkammer, prüft Schutzzauber oder
 *   Ausrüstungsgegenstände der Gruppe und zieht bei ungeschützten Helden Lebenspunkte ab.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach der Gefahrenprüfung zurück.
 === Ende Beschreibung === */
void f_0ecc70(void)
{
  OB ob;
  int i;
  int u;
  if (f_126410(d_1c2c44) >= 0x7e90 && f_126410(d_1c2c44) <= 0x15180) {
    {
      f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
      u = f_038c40(d_1c0004);
      i = f_0606a0(0x120001, 1);
      *(int *)(ob.addresses.objects + 4) = u;
      f_0bf6c0(d_1c2c64, 6);
      f_0bfa20(d_1c2c64, i, 0, 0x12000083, 0);
      f_0bfa20(d_1c2c64, i, 0, 0x12000084, 0);
      f_0bfa20(d_1c2c64, i, 0, 0x12000085, 0);
      f_0bfa20(d_1c2c64, i, 0, 0x12000086, 0);
      f_0bfa20(d_1c2c64, i, 0, 0x12000087, 0);
      f_10b890(0xb);
      f_0bf680(d_1c2c64);
      DEL(i);
      f_057220(d_1c2c00, 0x8030020, 0);
      d_1bee1c = 1;
      d_1c00d0 = 8;
      d_1c00e0 = 0x19;
      f_091f70(0x44);
      f_1254a0(&ob, 0);
    }
  }
}
//@ f_0ecdd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt eine komplexe Raumszene mit mehreren aufeinanderfolgenden Textfenstern,
 *   Soundeffekten und einer anschließenden Kampf- oder Fluchtentscheidung aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Szenensteuerung zurück.
 === Ende Beschreibung === */
void f_0ecdd0(void)
{
  OB ob;
  int h14, h15, h13, u28, u24;
  short n;
  if (f_126410(d_1c2c44) >= 0xa8c0 && f_126410(d_1c2c44) <= 0x17bb0) {
    f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
    u28 = f_038c40(d_1c0004);
    u24 = f_039660(d_1c0004, 1);
    h14 = f_0606a0(0x120001, 0x14);
    h15 = f_0606a0(0x120001, 0x15);
    h13 = f_0606a0(0x120001, 0x13);
    n = f_0db9a0(d_1c0004);
    *(int *)(ob.addresses.objects + 4) = u28;
    *(int *)(ob.addresses.objects + 8) = u24;
    f_03eca0(2);
    f_0bf6c0(d_1c2c64, 6);
    f_0bfa20(d_1c2c64, h14, 0, 0x12000088, 0);
    f_0bfa20(d_1c2c64, h14, 0, 0x12000089, 0);
    f_0bfa20(d_1c2c64, h14, 0, 0x1200008a, 0);
    f_0bfa20(d_1c2c64, h14, 0, 0x1200008b, 0);
    f_060800(0x120012, 1, 0);
    f_0bfa20(d_1c2c64, h15, 0, 0x1200008c, 0);
    f_0bfa20(d_1c2c64, h15, 0, 0x1200008d, 0);
    if (n > 1) f_0bfa20(d_1c2c64, h13, 0, 0x1200008e, 0);
    else f_0bfa20(d_1c2c64, h13, 0, 0x1200008f, 0);
    f_0bfa20(d_1c2c64, h15, 0, 0x12000090, 0);
    f_0bfa20(d_1c2c64, h15, 0, 0x12000091, 0);
    f_0bf680(d_1c2c64);
    DEL(h14);
    DEL(h15);
    DEL(h13);
    f_039a80(d_1c0004, (int)f_0ea230);
    d_1c00a0 = 1;
    d_1c00d4 = 0xd;
    f_057220(d_1c2c00, 0x8030021, 0);
    f_091f70(0x45);
    f_1254a0(&ob, 0);
  }
}
//@ f_0ed040
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion überprüft beim Durchqueren eines Korridors oder beim Betätigen eines Schalters die
 *   aktuellen Fortschrittsflags des Gebiets und schaltet versteckte Türen oder Ereignisse frei.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der Aktion zurück.
 === Ende Beschreibung === */
void f_0ed040(void)
{
  OB ob;
  short s;
  int i, u3, u4, i5, i4;
  if (f_126410(d_1c2c44) >= 0xa8c0 && f_126410(d_1c2c44) <= 0x17bb0) {
    f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
    u3 = f_038c40(d_1c0004);
    u4 = f_039040(d_1c0004);
    i = f_0606a0(0x120001, 1);
    *(int *)(ob.addresses.objects + 4) = u3;
    f_0bf6c0(d_1c2c64, 6);
    f_0bfa20(d_1c2c64, i, 0, 0x12000092, 0);
    f_10b890(0xc);
    f_0bf680(d_1c2c64);
    DEL(i);
    d_1c00bc = 1;
    d_1c01dc = 1;
    f_057220(d_1c2c00, 0x8030022, 0);
    f_091f70(0x46);
    i = f_0d6690(3);
    i5 = f_0d6690(1);
    i4 = 0;
    if (i != 0) i4 = i; else if (i5 != 0) i4 = i5;
    if (i4 != 0) {
      if (i4 == d_1c0004) {
        s = f_042960((struct hero *)(f_039040(i4)));
        if (s >= 5) {
          *(int *)(ob.addresses.objects + 4) = u4;
          f_0bf730(d_1c2c64, 0x12000093);
        }
      }
      f_0d64a0();
    }
    f_019fd0(d_1c2a84, 1, 0x7490000, 0x38e0000, 0x12000094);
    f_1254a0(&ob, 0);
  }
}
//@ f_0ed1c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das abschließende Ereignis dieses Teilgebiets, spielt eine
 *   Vollbild-Animation oder Zwischensequenz ab, vergibt Belohnungen an die Heldengruppe und bereitet den
 *   Übergang in den nächsten Spielabschnitt vor.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Statuswert des Szenenabschlusses zurück.
 === Ende Beschreibung === */
int f_0ed1c0(void)
{
  short chance;
  int handle;
  short kind;
  int result;
  int event;
  short choice;
  int actor;
  short item_a;
  short item_b;
  int slot;
  int *table;
  short f_0bf820(char *, int, short, ...);
  if (f_126410(d_1c2c44) > 0x93a8 && f_126410(d_1c2c44) <= 0x190c8)
    chance = 10;
  else
    chance = 15;
  handle = f_0606a0(0x120001, 0x16);
  kind = f_1457e0(2);
  result = 0;
  if (EQ(d_1bfaec, 1)) chance = chance + chance;
  if (f_1457e0(100) < 30) {
    f_0bf6c0(d_1c2c64, 6);
    f_0bde40(d_1c2c64);
    f_0bfa20(d_1c2c64, handle, 0, 0x12000095, 0);
    if (f_1457e0(100) < chance) {
      f_0bde40(d_1c2c64);
      result = 1;
      f_0bfa20(d_1c2c64, handle, 0, 0x12000096, 0);
      event = f_08c920((short)((kind == 1) ? 0x84 : 0x86), 0);
      if (event == 2) goto CLEANUP;
      if (event == 0) chance = d_1bdaf8 * 3;
      else if (event == 1) chance = 100;
      if (chance > 100) chance = 100;
POLL:
      if (f_1457e0(100) > chance) goto CLEANUP;
      if (d_1c21a4 != 0) goto CLEANUP;
      f_09a400();
      do {
        choice = (short)f_0bf820(d_1c2c64, 0x12000098, 2, 0x12000099, 0x1200009a);
      } while (choice == -1);
      switch (choice) {
      case 1:
        choice = (short)f_0bf820(d_1c2c64, 0x1200009b, 2, 0x1200009c, 0x1200009d);
        if (choice != 2) {
          if (f_1457e0(100) <= 50) {
            actor = f_038c40(d_1c0004);
            do {
              item_a = f_042a60((struct hero *)(actor), 3);
              item_b = f_042a60((struct hero *)(actor), 12);
              table = (int *)(*(int*)&d_1c2c40);
              slot = ((RivaItemDefinition*)(table[item_a]))->f_0a7a90();
              if (slot == 0) f_033530(actor, 3);
              table = (int *)(*(int*)&d_1c2c40);
              slot = ((RivaItemDefinition*)(table[item_b]))->f_0a7a90();
              if (slot == 0) f_033530(actor, 12);
              actor = f_0391b0(d_1c0004, actor);
            } while (actor != f_038c40(d_1c0004));
            f_0bf730(d_1c2c64, 0x1200009e);
            d_1c21a4 = -1;
          } else {
            f_0bf730(d_1c2c64, 0x1200009f);
            d_1c21a4 = 11;
          }
        } else {
          f_0bf730(d_1c2c64, 0x120000a0);
          d_1c21a4 = 11;
        }
        goto POLL;
      case 2:
        event = f_08c920((short)((kind == 1) ? 0x85 : 0x87), 0);
        if (event == 0) chance = d_1bdaf8 * 3;
        else if (event == 1) chance = 100;
        if (chance > 100) chance = 100;
        goto POLL;
      default:
        goto POLL;
      }
    } else {
      f_0bde40(d_1c2c64);
      f_0bfa20(d_1c2c64, handle, 0, 0x12000097, 0);
    }
CLEANUP:
    if (d_1c21a4 == -1) d_1c21a4 = 0;
    f_0bf680(d_1c2c64);
  }
  DEL(handle);
  return result;
}
