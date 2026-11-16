/* === Beschreibung (Katalog) ===
 * Einheit loc_acti (0x0B2180 - 0x0B2640)
 *
 * Spezielle Gebäude- und Ortsinteraktionen (p:\riva\source\cpp\loc_acti.cpp), darunter ereignisgesteuerte
 * Fallen/Kämpfe, Dialogsequenzen mit Animationen und ein Beutefund.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 1/2 gleich (suche.py 23.10.2026, Basis loc_acti_P1.CPP)
// loc_acti.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B2180-0x0B2640
#include <string.h>
#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
#define I32(p,o) (*(int *)((p)+(o)))
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_038c40(int p1);
int f_040780(int p1, int p2);

int f_044300(int p1, int p2);
int f_057220(int p1, int p2, int p3);
short f_08c920(int p1, int p2);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0bf980(int, ...);
short f_0d54f0(int p1, int p2);
int f_112df0(int p1, int p2, int p3, int p4);
int f_112e70(int p1, int p2);
int f_112ec0(int p1);
int f_113340(int p1, int p2, int p3, int p4);
int f_113640(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
extern char d_1bd708;
extern int d_1bd91c;
extern signed char d_1bed94;
extern int d_1c0004;
extern volatile short d_1c2198;
extern int d_1c2c00;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a51f4[];
struct SO { int a; int *p; char pad[0x34]; };
#define CHUNK(ln,K) { int t = (int)operator new(0x13e, mark(d_1a51f4, ln)); iVar3 = (t != 0) ? f_0104b0(t, 0x2c0004, 0, 0) : t; f_0bf980((int)&d_1c2c64, iVar3, 0, K, 0); if (iVar3 != 0) operator delete((void *)f_010590(iVar3, 0)); }
#define CH1(ln,K) iVar3 = (int)operator new(0x13e, mark(d_1a51f4, ln)); if (iVar3 != 0) { iVar3 = f_0104b0(iVar3, 0x2c0004, 0, 0); } else { iVar3 = r; } f_0bf980((int)&d_1c2c64, iVar3, 0, K, 0); if (iVar3 != 0) operator delete((void *)f_010590(iVar3, 0));
//@ f_0b2180
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion führt anhand des im Ortsobjekt bei Offset +0x50 gespeicherten Aktionscodes (1
 *   bis 5) eine besondere Ortsaktion aus: Code 1 und 5 spielen mehrteilige animierte Dialogsequenzen (0x2c0004,
 *   Texte 0x36000051-0x36000057) ab, Code 2 startet den Kampf 0x95 (f_08c920) und zieht bei Flucht 4
 *   Lebenspunkte ab, Code 3 gibt die Meldung 0x36000058 aus, vergibt 30 Abenteuerpunkte (f_040780) sowie den
 *   Tagebucheintrag 0x803002f, und Code 4 zeigt Text 0x36000056 und zieht dem Anführer 4 Lebenspunkte ab
 *   (f_044300).
 * - Eingaben: Übergeben wird ein Zeiger auf die aktuelle Orts-/Gebäudestruktur (p1), deren Feld bei Offset +0x50
 *   den auszuführenden Aktionscode enthält.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn durch Kampf, Schaden oder Abschluss (Codes 2, 3, 4) die Szene
 *   beendet bzw. unterbrochen wird, und sonst 0.
 === Ende Beschreibung === */
int f_0b2180(int p1)
{
  struct SO o;
  int r = 0;
  int iVar1, iVar3, uVar4;
  short s;
  if (I32(p1, 0x50) != 0) {
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  iVar1 = I32(p1, 0x50);
  uVar4 = f_038c40(d_1c0004);
  o.p[1] = uVar4;
  switch (I32(p1, 0x50)) {
  case 4:
    f_0bf730((int)&d_1c2c64, 0x36000056);
    f_044300(uVar4, (short)(f_042960((struct hero *)(uVar4)) - 4));
    r = 1;
    break;
  case 1:
    f_0bf6c0((int)&d_1c2c64, 8);
    { int t = (int)operator new(0x13e, mark(d_1a51f4, 0x2a2)); iVar3 = (t != 0) ? f_0104b0(t, 0x2c0004, 0, 0) : t; f_0bf980((int)&d_1c2c64, iVar3, 0, 0x36000051, 0); if (iVar3 != 0) operator delete((void *)f_010590(iVar3, 0)); }
    CHUNK(0x2a5, 0x36000052)
    CHUNK(0x2a8, 0x36000053)
    CHUNK(0x2ab, 0x36000054)
    CHUNK(0x2ae, 0x36000055)
    f_0bf680((int)&d_1c2c64);
    break;
  case 2:
    d_1bd91c = 1;
    s = f_08c920(0x95, 0);
    if (s == 0) {
      d_1c2198 = 1;
      I32(p1, 0x50) = 3;
    } else {
      if (s != 2) {
        f_044300(uVar4, (short)(f_042960((struct hero *)(uVar4)) - 4));
      }
      r = 1;
    }
    break;
  case 3:
    f_0bf730((int)&d_1c2c64, 0x36000058);
    d_1bd708 = 1;
    f_040780(uVar4, 0x1e);
    r = 1;
    f_057220((int)&d_1c2c00, 0x803002f, 0);
    break;
  /* - */
  case 5:
    { int t = (int)operator new(0x13e, mark(d_1a51f4, 0x2e7)); iVar3 = (t != 0) ? f_0104b0(t, 0x2c0004, 0, 0) : t; f_0bf980((int)&d_1c2c64, iVar3, 0, 0x36000057, 0); if (iVar3 != 0) operator delete((void *)f_010590(iVar3, 0)); }
    break;
  default:
    I32(p1, 0x50) = 0;
  }
  if (iVar1 == I32(p1, 0x50)) I32(p1, 0x50) = 0;
  f_1254a0((int)&o, 0);
  }
  return r;
}
//@ f_0b2510
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft einmalig (d_1bed94 == 0), ob die Gruppe den Schlüsselgegenstand 0x1b4
 *   besitzt (f_0d54f0), gibt in diesem Fall vier Entdeckungstexte (0x22000049 bis 0x2200004c) mit dem Namen des
 *   Gruppenführers aus und öffnet anschließend ein Beutefenster (f_112df0 bis f_112ec0), das den Questgegenstand
 *   0x163 enthält.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_0b2510(void)
{
  struct SO o;
  int r = 0;
  int iVar3;
  if (EQI(d_1bed94, 0)) {
    if (f_0d54f0(d_1c0004, 0x1b4) != -1) {
      f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      o.p[1] = f_038c40(d_1c0004);
      f_0bf730((int)&d_1c2c64, 0x22000049);
      f_0bf730((int)&d_1c2c64, 0x2200004a);
      f_0bf730((int)&d_1c2c64, 0x2200004b);
      f_0bf730((int)&d_1c2c64, 0x2200004c);
      iVar3 = (int)operator new(0x14, mark(d_1a51f4, 0x317));
      if (iVar3 != 0) { iVar3 = f_112df0(iVar3, 0x46, 0, 1); } else { iVar3 = r; }
      f_113640(iVar3);
      f_113340(iVar3, 0x163, 1, 0);
      f_112ec0(iVar3);
      if (iVar3 != 0) operator delete((void *)f_112e70(iVar3, 0));
      d_1bed94 = 1;
      f_1254a0((int)&o, 0);
    }
  }
  return r;
}
