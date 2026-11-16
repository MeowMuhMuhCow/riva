/* === Beschreibung (Katalog) ===
 * Einheit gz_0ced30
 *
 * Diese Einheit implementiert erstens die 15 individuellen Monster-Zauberwirkungen (f_0ced30 bis f_0cf7b0 samt
 * deren Funktionszeiger-Gebern f_0cf820 bis f_0cf900, als Teil von mo_spell.cpp) und zweitens die vollständige
 * Menge der Getter-, Setter- und Bitfeld-Zugriffsmethoden (f_0cf910 bis f_0d0230) für die
 * Kampfteilnehmer-/Monsterstruktur (Größe 0x73 Bytes).
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 147/151 gleich (suche.py 26.10.2026, Basis gz_0ced30_P1.CPP)
// OPT -4r -oneatx -zp1 -s -j
// P3 82/151 gleich (suche.py 24.10.2026, Basis gz_0ced30_P1.CPP)
#pragma inline_depth(0)
// P1 52/128 gleich
// P2 Koepfe Stufe 1 (Fable K): 79 gleich (vorher 79), Rest 1032 (vorher 1047)
// gz_0ced30.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CED30-0x0D0260
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_033c50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0348d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_0773b0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0ce9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d0a60(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4c80(int p1);           // reg eax stapel 0
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);                       // nicht in clobber.tsv
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a47ac;                    // 0x1A47AC
extern int d_1bd91a;                    // 0x1BD91A
extern short d_1bd924;                    // 0x1BD924
extern int d_1c0004;                    // 0x1C0004
extern volatile signed char d_1c21b4;                    // 0x1C21B4
extern int d_1c2c40;                    // 0x1C2C40
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (128), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
// --- Vorwaertsdeklarationen eigener Funktionen ---
typedef void (*CODE)(void);
void f_0ced30(short *p1);
void f_0cee40(int p1);
void f_0ceee0(int p1);
void f_0cefb0(int p1);
void f_0cf070(int p1);
void f_0cf0c0(short *p1);
void f_0cf120(int p1);
void f_0cf1c0(short *p1);
void f_0cf2f0(short *p1);
void f_0cf380(short *p1);
void f_0cf5b0(int p1);
void f_0cf670(short *p1);
void f_0cf6c0(short *p1);
void f_0cf710(int p1);
void f_0cf7b0(short *p1);
CODE f_0cf820(void);
CODE f_0cf830(void);
CODE f_0cf840(void);
CODE f_0cf850(void);
CODE f_0cf860(void);
CODE f_0cf870(void);
CODE f_0cf880(void);
CODE f_0cf890(void);
CODE f_0cf8a0(void);
CODE f_0cf8b0(void);
CODE f_0cf8c0(void);
CODE f_0cf8d0(void);
CODE f_0cf8e0(void);
CODE f_0cf8f0(void);
CODE f_0cf900(void);
signed char f_0cf910(signed char *p1);
void f_0cf920(char *p1, char p2);
signed char f_0cf930(int p1);
void f_0cf940(int p1, int p2);
signed char f_0cf950(int p1);
void f_0cf960(int p1, int p2);
void f_0cf970(int p1, int p2);
signed char f_0cf990(int p1);
int f_0cf9b0(int p1, int p2);
short f_0cf9f0(int p1);
void f_0cfa00(int p1, int p2);
unsigned short f_0cfa10(int p1);
void f_0cfa20(int p1, int p2);
short f_0cfa30(int p1);
void f_0cfa40(int p1, int p2);
unsigned short f_0cfa50(int p1);
void f_0cfa60(int p1, int p2);
signed char f_0cfa70(int p1);
signed char f_0cfa90(int p1);
void f_0cfaa0(int p1, int p2);
unsigned char f_0cfab0(int p1);
void f_0cfac0(int p1, int p2);
void f_0cfae0(int p1, int p2);
void f_0cfb00(int p1, int p2);
void f_0cfb10(int p1, int p2);
short f_0cfb30(int p1);
short f_0cfb50(int p1);
short f_0cfb70(int p1);
void f_0cfb80(int p1, int p2);
void f_0cfb90(int p1, int p2);
unsigned char f_0cfbb0(int p1);
void f_0cfbc0(char *p1, signed char p2);
unsigned char f_0cfbd0(int p1);
void f_0cfbe0(int p1, int p2);
signed char f_0cfc10(int p1);
void f_0cfc20(int p1, int p2);
signed char f_0cfc30(int p1);
unsigned char f_0cfc50(int p1);
void f_0cfc60(int p1, int p2);
unsigned char f_0cfc70(int p1);
void f_0cfc80(int p1, int p2);
unsigned char f_0cfc90(int p1);
void f_0cfca0(int p1, int p2);
void f_0cfcb0(int p1, int p2);
signed char f_0cfcc0(int p1);
void f_0cfcd0(int p1, int p2);
unsigned char f_0cfce0(int p1);
void f_0cfcf0(int p1, int p2);
unsigned char f_0cfd00(int p1);
void f_0cfd10(int p1, int p2);
unsigned char f_0cfd20(int p1);
void f_0cfd30(int p1, int p2);
int f_0cfd40(int p1);
unsigned char f_0cfd70(int p1);
void f_0cfd80(int p1, int p2);
void f_0cfd90(int p1, int p2);
unsigned char f_0cfda0(int p1);
void f_0cfdb0(int p1, int p2);
unsigned char f_0cfdc0(int p1);
void f_0cfdd0(int p1, int p2);
unsigned short f_0cfdf0(int p1);
void f_0cfe00(int p1, int p2, int p3);
unsigned short f_0cfe30(int p1);
void f_0cfe40(int p1, int p2);
unsigned short f_0cfe60(int p1);
void f_0cfe70(int p1, int p2);
unsigned short f_0cfe90(int p1);
void f_0cfea0(int p1, int p2);
unsigned short f_0cfec0(int p1);
void f_0cfed0(int p1, int p2);
unsigned short f_0cfef0(int p1);
void f_0cff00(int p1, int p2);
unsigned short f_0cff20(int p1);
void f_0cff30(int p1, int p2);
unsigned short f_0cff50(int p1);
void f_0cff60(int p1, int p2);
unsigned short f_0cff80(int p1);
void f_0cff90(int p1, int p2);
unsigned short f_0cffb0(int p1);
void f_0cffc0(int p1, int p2);
unsigned short f_0cffe0(int p1);
void f_0cfff0(int p1, int p2);
unsigned short f_0d0010(int p1);
void f_0d0020(int p1, int p2);
unsigned short f_0d0040(int p1);
void f_0d0050(int p1, int p2);
unsigned char f_0d0070(int p1);
signed char f_0d0080(int p1);
void f_0d0090(int p1, int p2);
unsigned char f_0d00a0(int p1);
void f_0d00b0(int p1, int p2);
signed char f_0d00c0(int p1);
void f_0d00d0(int p1, int p2);
unsigned short f_0d00e0(int p1);
void f_0d00f0(int p1, int p2);
short f_0d0100(int p1);
void f_0d0110(int p1, int p2);
unsigned short f_0d0120(int p1);
void f_0d0130(int p1, int p2);
short f_0d0140(int p1);
void f_0d0150(int p1, int p2);
unsigned char f_0d0160(int p1);
void f_0d0170(int p1, int p2);
signed char f_0d0180(int p1);
void f_0d0190(int p1, int p2);
unsigned char f_0d01a0(int p1);
void f_0d01b0(int p1, int p2);
unsigned char f_0d01c0(int p1);
void f_0d01d0(int p1, int p2);
unsigned char f_0d01e0(int p1);
void f_0d01f0(int p1, int p2);
int f_0d0200(void);
int f_0d0210(void);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0d0220
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist eine leere Platzhalter- oder Konstruktorfunktion für die Monsterstruktur ohne ausführbare
 *   Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0220()
{
}

//@ f_0ced30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode bricht eine Versteinerung (f_0cfe30) oder einen Schlaf-/Lähmungszustand
 *   (f_0cfef0) eines verbündeten Monsters (*(int *)(p1 + 0x12)) auf, sofern die gewürfelten Kosten 1W10 * 5 die
 *   vorhandenen Astralpunkte (f_0cfa50) nicht übersteigen (0x1700007e, d_1bd91a = 1).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ced30(short *p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; int *p4; int *p8; int *pc; int *p10; short *p14; short *p18; short *p1c; short *p20; char pad[0x18]; } ob;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((signed char)f_0cfe30(*(int *)(p1 + 9))) {
    *p1 = f_1457e0(10) * 5;
    if ((short)f_0cfa50(*(int *)(p1 + 7)) < *p1) {
      *p1 = f_0cfa50(*(int *)(p1 + 7));
    } else {
      f_0cfe40(*(int *)(p1 + 9), 0);
      ob.p8[1] = *(int *)(p1 + 9);
      ob.p1c[1] = 1;
      f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700007e);
    }
  } else if ((signed char)f_0cfef0(*(int *)(p1 + 9))) {
    *p1 = f_1457e0(10) * 5;
    if ((short)f_0cfa50(*(int *)(p1 + 7)) < *p1) {
      *(volatile short *)p1 = f_0cfa50(*(int *)(p1 + 7));
      f_1254a0((int)&ob, 0);
      return;
    }
    f_0cff00(*(int *)(p1 + 9), 0);
    *(volatile unsigned char *)&d_1bd91a = 1;
    f_1254a0((int)&ob, 0);
    return;
  } else {
    *p1 = 2;
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cee40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode belegt den anvisierten Helden (*(int *)(p1 + 0x16)) mit dem Zustand
 *   f_042690(..., 1) (0x1700007f), sofern dieser nicht durch den Schutzgegenstand 0x108 im Inventar (f_0d4aa0)
 *   immun ist (0x170000ea bzw. 0x17000088).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cee40(int p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; int p4; char pad[0x34]; } ob;
  short s;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  s = f_0d4aa0(*(int *)(p1 + 0x16), 0x108);
  if (s == -1) {
    f_042690((struct hero *)(*(int *)(p1 + 0x16)), 1);
    *(int *)(ob.p4 + 4) = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700007f);
  } else {
    *(int *)(ob.p4 + 4) = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, f_0773b0(d_1c0004) ? 0x170000ea : 0x17000088);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0ceee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode versetzt den anvisierten Helden (*(int *)(p1 + 0x16)) in Panik oder
 *   Verwirrung (f_0425b0(..., 1), f_042780(..., 0), f_042760(..., 0), Text 0x170000d5 bzw. 0x17000080), sofern
 *   er nicht den Schutzgegenstand 0x108 trägt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ceee0(int p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; int *p4; char pad[0x34]; } ob;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((short)f_0d4aa0(*(int *)(p1 + 0x16), 0x108) == -1) {
    f_0425b0((struct hero *)(*(int *)(p1 + 0x16)), 1);
    f_042780((struct hero *)(*(int *)(p1 + 0x16)), 0);
    if (f_042a10((struct hero *)(*(int *)(p1 + 0x16)))) f_042760((struct hero *)(*(int *)(p1 + 0x16)), 0);
    ob.p4[1] = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, f_0773b0(d_1c0004) ? 0x170000d5 : 0x17000080);
  } else {
    ob.p4[1] = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, f_0773b0(d_1c0004) ? 0x170000ea : 0x17000088);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cefb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode übernimmt die Kontrolle über den anvisierten Helden bzw. belegt ihn mit
 *   Beherrschung (f_042650(..., 1), f_0425b0(..., 0), Text 0x170000d0 bzw. 0x17000081), falls er nicht durch den
 *   Gegenstand 0x108 geschützt ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cefb0(int p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; int p4; char pad[0x34]; } ob;
  short s;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  s = f_0d4aa0(*(int *)(p1 + 0x16), 0x108);
  if (s == -1) {
    f_042650((struct hero *)(*(int *)(p1 + 0x16)), 1);
    f_0425b0((struct hero *)(*(int *)(p1 + 0x16)), 0);
    *(int *)(ob.p4 + 4) = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, f_0773b0(d_1c0004) ? 0x170000d0 : 0x17000081);
  } else {
    *(int *)(ob.p4 + 4) = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, f_0773b0(d_1c0004) ? 0x170000ea : 0x17000088);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cf070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode stärkt ein Monster (*(int *)(p1 + 0x12)) im Kampf (vermutlich
 *   *Axxeleratus* oder Kampfrausch), indem sie dessen Angriffsanzahl (f_0cfab0/f_0cfac0), Attacke (f_0cfae0) und
 *   Parade (f_0cfb10) jeweils um 1 erhöht und die Bewegungsweite (f_0cfbd0/f_0cfbe0) verdoppelt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf070(int p1)
{
  char cVar1;
  cVar1 = (char)f_0cfab0(*(int *)(p1 + 0x12));
  f_0cfac0(*(int *)(p1 + 0x12), (int)(signed char)(cVar1 + 1));
  f_0cfae0(*(int *)(p1 + 0x12), 1);
  f_0cfb10(*(int *)(p1 + 0x12), 1);
  cVar1 = (char)f_0cfbd0(*(int *)(p1 + 0x12));
  f_0cfbe0(*(int *)(p1 + 0x12), (int)(char)(cVar1 * 2));
}

//@ f_0cf0c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode heilt ein verwundetes Monster (*(int *)(p1 + 0x12)) über f_0d0a60 um die
 *   Hälfte seiner fehlenden Lebenspunkte (mindestens 7 Punkte, begrenzt durch die aktuellen Astralpunkte
 *   f_0cfa50 des Zaubernden).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf0c0(short *p1)
{
  short sVar1;
  int n;
  *p1 = -4;
  n = (short)f_0cf9f0(*(int *)(p1 + 9));
  sVar1 = (short)((n - (short)f_0cfa10(*(int *)(p1 + 9))) / 2);
  if (sVar1 != (short)0) {
    if (sVar1 < 7) *p1 = 7;
    sVar1 = (short)f_0cfa50(*(int *)(p1 + 7));
    if (sVar1 < *p1) {
      sVar1 = (short)f_0cfa50(*(int *)(p1 + 7));
      *p1 = sVar1;
    }
    f_0d0a60(*(int *)(p1 + 9), (int)*p1);
  }
}

//@ f_0cf120
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode erhöht den Rüstungsschutz eines Ziels um 3 Punkte (vermutlich
 *   *Armatrutz*), und zwar bei einem Helden über f_043240(..., 3) (0x17000064) oder bei einem Monster über
 *   f_0cfd80(..., 3) (0x17000063).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf120(int p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; int *p4; int *p8; char pad[0x10]; short *p1c; char pad2[0x1c]; } ob;
  signed char c;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  c = (signed char)f_0cfd40(*(int *)(p1 + 0xe));
  if (c == 2) {
    f_043240((struct hero *)(*(int *)(p1 + 0x16)), 3);
    ob.p4[1] = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x17000064);
  } else {
    f_0cfd80(*(int *)(p1 + 0x12), 3);
    ob.p8[1] = *(int *)(p1 + 0x12);
    ob.p1c[1] = 1;
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x17000063);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cf1c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode zerstört oder beschädigt die Waffe eines Helden am Ausrüstungsplatz 3
 *   (f_033c50, Text 0x1700006a, vermutlich *Eisenrost*), sofern sie nicht unzerstörbar/magisch ist (f_042bb0,
 *   f_042d00), oder schwächt bei einem Monster dessen Angriff über f_0cfdb0(..., 1) (0x17000069).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf1c0(short *p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob {
    int w0, p04, p08, p0c;
    char pad10[0xc];
    int p1c, p20;
    char pad24[0x18];
  } ob;
  short item;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((signed char)f_0cfd40(*(int *)(p1 + 7)) == 2) {
    item = f_042a60((struct hero *)(*(int *)(p1 + 0xb)), 3);
    if (item == (short)0) {
      *p1 = 2;
      goto LAB_000cf2d2;
    }
    if (f_042bb0((struct hero *)(*(int *)(p1 + 0xb)), 3) != 0) goto LAB_000cf2d2;
    if (f_042d00((struct hero *)(*(int *)(p1 + 0xb)), 3) == 0) goto LAB_FAIL;
    f_033c50(*(int *)(p1 + 0xb), 3, 1);
    item=(item&0)?0:item; /* haelt die Registerzuteilung wie im Original */
    { int index=item; index=(*(int **)&d_1c2c40)[index]; *(int *)(ob.p0c+4)=index; }
    *(short *)(ob.p20 + 2) = 1;
    *(int *)(ob.p04 + 4) = *(int *)(p1 + 0xb);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700006a);
    goto LAB_000cf2d2;
LAB_FAIL:
      *(volatile short *)p1 = -2;
      f_1254a0((int)&ob, 0);
      return;
  } else {
    if (f_0cfda0(*(int *)(p1 + 9))) goto LAB_000cf2d2;
    f_0cfdb0(*(int *)(p1 + 9), 1);
    *(int *)(ob.p08 + 4) = *(int *)(p1 + 9);
    *(short *)(ob.p1c + 2) = 1;
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x17000069);
  }
LAB_000cf2d2:
  f_1254a0((int)&ob, 0);
}

//@ f_0cf2f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode wirkt einen Kampfzauber (vermutlich *Fulminictus*), der 3W6 + Stufe
 *   (f_0cfcc0) Schadenspunkte berechnet, den Schaden bei Trägern der Schutzgegenstände 0x11e oder 0xdc halbiert,
 *   ihn auf die vorhandenen Astralpunkte (f_0cfa50) begrenzt und über f_0ce9f0 auf das Ziel anwendet.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf2f0(short *p1)
{
  extern signed char f_0cfcc0_alias(int);
#pragma aux f_0cfcc0_alias "f_0cfcc0" parm [eax] value [al] modify exact [eax edx]
  short s;
  signed char c;
  s = f_145850(3, 6, 0);
  c = f_0cfcc0_alias(*(int *)(p1 + 7));
  s = s + c;
  if ((signed char)f_0cfd40(*(int *)(p1 + 7)) == 2) {
    if ((int)(short)f_0d4aa0(*(int *)(p1 + 0xb), 0x11e) != -1 ||
        (int)(short)f_0d4aa0(*(int *)(p1 + 0xb), 0xdc) != -1)
      s /= (short)2;
  }
  if (s > (short)f_0cfa50(*(int *)(p1 + 7)))
    s = f_0cfa50(*(int *)(p1 + 7));
  f_0ce9f0((int)p1, s);
  *p1 = s;
}

//@ f_0cf380
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode wirkt einen Feuer-/Schadenszauber (vermutlich *Ignifaxius*) mit (Stufe)W6
 *   Schaden (f_0cfcc0), halbiert diesen bei Feuerschutz (0x11e, 0xdc, f_043270), zieht den Schaden über f_0ce9f0
 *   ab, beschädigt zusätzlich den Rüstungsschutz um Schaden / 10 (f_0348d0 am Brustpanzer Slot 10 bzw. f_0cf970
 *   beim Monster) und senkt vorübergehend Attacke und Parade um -Stufe / 2.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf380(short *p1)
{
  short c, v, b;
  c = f_0cfcc0(*(int *)(p1 + 7));
  v = f_145850(c, 6, 0);
  if ((signed char)f_0cfd40(*(int *)(p1 + 7)) == 2) {
    if ((short)f_0d4aa0(*(int *)(p1 + 11), 0x11e) != -1 || (short)f_0d4aa0(*(int *)(p1 + 11), 0xdc) != -1)
      v /= (short)2;
    if ((unsigned char)((int)(f_043270((struct hero *)(*(int *)(p1 + 11))))))
      v /= (short)2;
  }
  if (v > (short)f_0cfa50(*(int *)(p1 + 7)))
    v = f_0cfa50(*(int *)(p1 + 7));
  b = v;
  f_0ce9f0((int)p1, b);
  b = b / 10;
  if ((signed char)f_0cfd40(*(int *)(p1 + 7)) == 2) {
    if ((short)f_042a60((struct hero *)(*(int *)(p1 + 11)), 10) != (short)0 && b != (short)0) {
      int k = (signed char)((int)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[(short)f_042a60((struct hero *)(*(int *)(p1 + 11)), 10)]))->f_0a78a0()));
      k=(k&0)?0:k; /* haelt die Registerzuteilung wie im Original */
      int lim = *((signed char *)&d_1a47ac + k * 2);
      int w = (short)((int)(f_042b50((struct hero *)(*(int *)(p1 + 11)), 10)));
      if (b + w > lim) {
        int k2 = (signed char)((int)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[(short)f_042a60((struct hero *)(*(int *)(p1 + 11)), 10)]))->f_0a78a0()));
        b = *((signed char *)&d_1a47ac + k2 * 2);
        b -= ((int)(f_042b50((struct hero *)(*(int *)(p1 + 11)), 10)));
      }
      f_0348d0(*(int *)(p1 + 11), 10, (signed char)b);
    }
    {
      int nc = -c;
      short r = f_0d4c80(*(int *)(p1 + 11));
      signed char h = nc / 2;
      f_0d5040(*(int *)(p1 + 11), r, 0x1518, (signed char)((int)(f_043120((struct hero *)(*(int *)(p1 + 11))))), h, 2);
      r = f_0d4c80(*(int *)(p1 + 11));
      f_0d5040(*(int *)(p1 + 11), r, 0x1518, (signed char)((int)(f_043120((struct hero *)(*(int *)(p1 + 11))))), h, 3);
    }
    d_1c21b4 = 0;
    *p1 = v;
  } else {
    signed char h;
    f_0cf970(*(int *)(p1 + 9), (signed char)(-b));
    h = -c / 2;
    f_0cfae0(*(int *)(p1 + 9), h);
    f_0cfb10(*(int *)(p1 + 9), h);
    d_1c21b4 = 0;
    *p1 = v;
  }
}
//@ f_0cf5b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode blendet oder schwächt das Ziel (vermutlich *Blitz dich find*), indem sie
 *   bei einem Helden den Attackewert temporär um 3 Punkte senkt (f_0d5040, Text 0x1700006c) bzw. bei einem
 *   Monster f_0cfae0(..., -3) (0x1700006d) anwendet.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf5b0(int p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int a0; int *p4; int *p8; int *pc; int *p10; short *p14; short *p18; short *p1c; short *p20; char pad[0x18]; } ob;
  short s;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((signed char)f_0cfd40(*(int *)(p1 + 0xe)) == 2) {
    s = f_0d4c80(*(int *)(p1 + 0x16));
    f_0d5040(*(int *)(p1 + 0x16), s, 0x1518, (signed char)((int)(f_043120((struct hero *)(*(int *)(p1 + 0x16))))), -3, 2);
    ob.p4[1] = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700006c);
  } else {
    f_0cfae0(*(int *)(p1 + 0x12), -3);
    ob.p8[1] = *(int *)(p1 + 0x12);
    ob.p1c[1] = 1;
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700006d);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cf670
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode versetzt ein Monster (*(int *)(p1 + 0x12)) in blinde Kampfwut (Attacke
 *   +5, Parade -5, Schadensbonus +5 über f_0cfb90, Statusbit 12 über f_0d0020) und setzt die Kosten *p1 auf 1W20
 *   Astralpunkte.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf670(short *p1)
{
  short uVar1;
  f_0cfae0(*(int *)(p1 + 9), 5);
  f_0cfb10(*(int *)(p1 + 9), -5);
  f_0cfb90(*(int *)(p1 + 9), 5);
  f_0d0020(*(int *)(p1 + 9), 1);
  uVar1 = (short)f_1457e0(0x14);
  *p1 = uVar1;
}

//@ f_0cf6c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode erhöht den Rüstungsschutz des zaubernden Monsters (f_0cf970) um einen
 *   Zufallswert result zwischen 1 und sqrt(Astralpunkte) und trägt result * result als Astralpunktekosten in *p1
 *   ein.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf6c0(short *p1)
{
  short sVar1;
  short sVar2;
  int p2;
  short result;
  sVar2 = 0;
  for (;;) {
    p2 = (int)sVar2;
    sVar1 = (short)f_0cfa50(*(int *)(p1 + 7));
    if (p2 * p2 >= (int)sVar1) break;
    sVar2 = sVar2 + 1;
  }
  result = (short)f_145760(1, p2);
  *p1 = result * result;
  f_0cf970(*(int *)(p1 + 7), (int)(signed char)result);
}

//@ f_0cf710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode versteinert oder lähmt das Ziel (vermutlich *Paralü*), indem sie bei
 *   einem Monster das Versteinerungs-Bit f_0cfe40(..., 1) (0x17000075) und bei einem Helden den Zustand
 *   f_0424f0(..., 1) (0x17000109) setzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf710(int p1)
{
  extern int f_125400(int, int, int, int);
  extern int f_0424f0_alias(int, int);
#pragma aux f_0424f0_alias "f_0424f0" parm [eax] [edx] value [eax] modify exact [eax edx ecx]
  extern char d_1c3498[];
  struct Ob { int w0; int *p4, *p8; int pc, p10, p14, p18; short *p1c; char pad[0x1c]; } ob;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((signed char)f_0cfd40(*(int *)(p1 + 0xe)) == 1) {
    f_0cfe40(*(int *)(p1 + 0x12), 1);
    ob.p8[1] = *(int *)(p1 + 0x12);
    ob.p1c[1] = 1;
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x17000075);
  } else {
    f_0424f0_alias(*(int *)(p1 + 0x16), 1);
    ob.p4[1] = *(int *)(p1 + 0x16);
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x17000109);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cf7b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Monster-Zaubermethode löst eine Beschwörung oder Herbeirufung (0x1700010f) aus, sofern die
 *   maximale Anzahl von 20 (0x14) Kampfeinheiten in d_1bd924 noch nicht erreicht ist (andernfalls Fehlschlag *p1
 *   = -2).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monster-Zauberkontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf7b0(short *p1)
{
  extern int f_125400(int, int, int, int);
  extern char d_1c3498[];
  struct Ob { int w0; char pad[4]; int *p8; char pad2[0x10]; short *p1c; char pad3[0x1c]; } ob;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)d_1c3498);
  if ((short)d_1bd924 == (short)0x14) {
    *p1 = -2;
  } else {
    ob.p8[1] = *(int *)(p1 + 7);
    ob.p1c[1] = 1;
    f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x1700010f);
  }
  f_1254a0((int)&ob, 0);
}

//@ f_0cf820
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf7b0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf7b0.
 === Ende Beschreibung === */
CODE f_0cf820(void)
{
    return (CODE)f_0cf7b0;
}
//@ f_0cf830
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf710 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf710.
 === Ende Beschreibung === */
CODE f_0cf830(void)
{
    return (CODE)f_0cf710;
}
//@ f_0cf840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf6c0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf6c0.
 === Ende Beschreibung === */
CODE f_0cf840(void)
{
    return (CODE)f_0cf6c0;
}
//@ f_0cf850
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf670 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf670.
 === Ende Beschreibung === */
CODE f_0cf850(void)
{
    return (CODE)f_0cf670;
}
//@ f_0cf860
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf5b0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf5b0.
 === Ende Beschreibung === */
CODE f_0cf860(void)
{
    return (CODE)f_0cf5b0;
}
//@ f_0cf870
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf380 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf380.
 === Ende Beschreibung === */
CODE f_0cf870(void)
{
    return (CODE)f_0cf380;
}
//@ f_0cf880
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf2f0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf2f0.
 === Ende Beschreibung === */
CODE f_0cf880(void)
{
    return (CODE)f_0cf2f0;
}
//@ f_0cf890
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf1c0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf1c0.
 === Ende Beschreibung === */
CODE f_0cf890(void)
{
    return (CODE)f_0cf1c0;
}
//@ f_0cf8a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf120 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf120.
 === Ende Beschreibung === */
CODE f_0cf8a0(void)
{
    return (CODE)f_0cf120;
}
//@ f_0cf8b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf0c0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf0c0.
 === Ende Beschreibung === */
CODE f_0cf8b0(void)
{
    return (CODE)f_0cf0c0;
}
//@ f_0cf8c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cf070 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cf070.
 === Ende Beschreibung === */
CODE f_0cf8c0(void)
{
    return (CODE)f_0cf070;
}
//@ f_0cf8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cefb0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cefb0.
 === Ende Beschreibung === */
CODE f_0cf8d0(void)
{
    return (CODE)f_0cefb0;
}
//@ f_0cf8e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0ceee0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0ceee0.
 === Ende Beschreibung === */
CODE f_0cf8e0(void)
{
    return (CODE)f_0ceee0;
}
//@ f_0cf8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0cee40 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0cee40.
 === Ende Beschreibung === */
CODE f_0cf8f0(void)
{
    return (CODE)f_0cee40;
}
//@ f_0cf900
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Funktionszeiger auf die Zaubermethode f_0ced30 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird die Funktionsadresse von f_0ced30.
 === Ende Beschreibung === */
CODE f_0cf900(void)
{
    return (CODE)f_0ced30;
}

//@ f_0cf910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x00 (Kennung/Untertyp) der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert *p1.
 === Ende Beschreibung === */
signed char f_0cf910(signed char *p1)
{
    return *p1;
}
//@ f_0cf920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Wert p2 in das Byte bei Offset +0x00 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bytewert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf920(char *p1, char p2)
{
    *p1 = p2;
}
//@ f_0cf930
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x01 (Monster-Typ/Grafikkennung) der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x01.
 === Ende Beschreibung === */
signed char f_0cf930(int p1)
{
    return *(signed char *)(p1 + 1);
}
//@ f_0cf940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt das Monster-Typ-Byte bei Offset +0x01 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Typwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf940(int p1, int p2)
{
    *(unsigned char *)(p1 + 1) = (unsigned char)p2;
}
//@ f_0cf950
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest den Rüstungsschutz bei Offset +0x02 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Rüstungsschutz als vorzeichenbehaftetes Byte.
 === Ende Beschreibung === */
signed char f_0cf950(int p1)
{
    return *(signed char *)(p1 + 2);
}
//@ f_0cf960
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Wert p2 in das Rüstungsschutz-Feld bei Offset +0x02 der
 *   Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Rüstungsschutzwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf960(int p1, int p2)
{
    *(unsigned char *)(p1 + 2) = (unsigned char)p2;
}
//@ f_0cf970
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode addiert p2 auf den Rüstungsschutz bei Offset +0x02 der Monsterstruktur p1 und begrenzt
 *   das Ergebnis nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Änderungswert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf970(int p1, int p2)
{
  *(char *)(p1 + 2) += (char)p2;
  if (*(signed char *)(p1 + 2) < 0) *(unsigned char *)(p1 + 2) = 0;
}
//@ f_0cf990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x03 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x03.
 === Ende Beschreibung === */
signed char f_0cf990(int p1)
{
    return *(signed char *)(p1 + 3);
}
//@ f_0cf9a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Wert p2 in das Byte bei Offset +0x03 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf9a0(int p1, int p2)
{
    *(char *)(p1 + 3) = (char)p2;
}
//@ f_0cf9b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode berechnet die Adresse des p2-ten Eigenschafts-Tripels (je 3 Bytes ab Offset +0x04)
 *   innerhalb der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Eigenschaftsindex p2.
 * - Rückgabewert: Zurückgegeben wird die Adresse p1 + 4 + p2 * 3.
 === Ende Beschreibung === */
int f_0cf9b0(int p1, int p2)
{
    return p1 + 4 + (short)p2 * 3;
}
//@ f_0cf9d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode initialisiert sowohl den Basis- als auch den aktuellen Wert des p2-ten
 *   Eigenschafts-Tripels (Offset +4 und +5) in der Monsterstruktur p1 mit dem Wert p3.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur, der Eigenschaftsindex p2 sowie der
 *   Eigenschaftswert p3.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cf9d0(char *p1, short p2, signed char p3)
{
  int n = p2 * 3;
  p1[n + 5] = p3;
  p1[n + 4] = p3;
}
//@ f_0cf9f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die maximale Lebensenergie (16-Bit-Wort bei Offset +0x19) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die maximale Lebensenergie des Monsters.
 === Ende Beschreibung === */
short f_0cf9f0(int p1)
{
    return *(short *)(p1 + 0x19);
}
//@ f_0cfa00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Wert p2 als maximale Lebensenergie in Offset +0x19 der
 *   Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die maximale Lebensenergie p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfa00(int p1, int p2)
{
    *(short *)(p1 + 0x19) = (short)p2;
}
//@ f_0cfa10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die aktuelle Lebensenergie (16-Bit-Wort bei Offset +0x1b) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die aktuelle Lebensenergie des Monsters.
 === Ende Beschreibung === */
unsigned short f_0cfa10(int p1)
{
    return *(unsigned short *)(p1 + 0x1b);
}
//@ f_0cfa20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die aktuelle Lebensenergie bei Offset +0x1b der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die aktuelle Lebensenergie p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfa20(int p1, int p2)
{
    *(unsigned short *)(p1 + 0x1b) = (unsigned short)p2;
}
//@ f_0cfa30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die maximale Astralenergie (16-Bit-Wort bei Offset +0x1d) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die maximale Astralenergie des Monsters.
 === Ende Beschreibung === */
short f_0cfa30(int p1)
{
    return *(short *)(p1 + 0x1d);
}
//@ f_0cfa40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die maximale Astralenergie bei Offset +0x1d der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Maximalwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfa40(int p1, int p2)
{
    *(short *)(p1 + 0x1d) = (short)p2;
}
//@ f_0cfa50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die aktuelle Astralenergie (16-Bit-Wort bei Offset +0x1f) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die aktuelle Astralenergie des Monsters.
 === Ende Beschreibung === */
unsigned short f_0cfa50(int p1)
{
    return *(unsigned short *)(p1 + 0x1f);
}
//@ f_0cfa60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die aktuelle Astralenergie bei Offset +0x1f der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die aktuelle Astralenergie p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfa60(int p1, int p2)
{
    *(unsigned short *)(p1 + 0x1f) = (unsigned short)p2;
}
//@ f_0cfa70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Magieresistenz (vorzeichenbehaftetes Byte bei Offset +0x21) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Magieresistenz des Monsters.
 === Ende Beschreibung === */
signed char f_0cfa70(int p1)
{
    return *(signed char *)(p1 + 0x21);
}
//@ f_0cfa80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Magieresistenzwert p2 in Offset +0x21 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfa80(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x21) = (unsigned char)p2;
}
//@ f_0cfa90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x22 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x22.
 === Ende Beschreibung === */
signed char f_0cfa90(int p1)
{
    return *(signed char *)(p1 + 0x22);
}
//@ f_0cfaa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt den Wert p2 in Offset +0x22 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfaa0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x22) = (unsigned char)p2;
}
//@ f_0cfab0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Anzahl der Angriffe pro Kampfrunde (Byte bei Offset +0x23) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Angriffsanzahl des Monsters.
 === Ende Beschreibung === */
unsigned char f_0cfab0(int p1)
{
    return *(unsigned char *)(p1 + 0x23);
}
//@ f_0cfac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die Anzahl der Angriffe pro Kampfrunde bei Offset +0x23 der
 *   Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die neue Angriffsanzahl p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfac0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x23) = (unsigned char)p2;
}
//@ f_0cfad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Attackewert bei Offset +0x24 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Attackewert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfad0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x24) = (unsigned char)p2;
}
//@ f_0cfae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verändert den Attackewert bei Offset +0x24 der Monsterstruktur p um v und begrenzt das
 *   Ergebnis nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p auf die Monsterstruktur sowie die Änderung v.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfae0(char *p, int v)
{
  p[0x24] += v; if ((signed char)p[0x24] < 0) p[0x24] = 0;
}
//@ f_0cfb00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Paradewert bei Offset +0x25 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Paradewert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb00(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x25) = (unsigned char)p2;
}
//@ f_0cfb10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verändert den Paradewert bei Offset +0x25 der Monsterstruktur p1 um p2 und begrenzt das
 *   Ergebnis nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die Änderung p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb10(int p1, int p2)
{
  ((char *)p1)[0x25] += p2;
  if ((signed char)((char *)p1)[0x25] < 0) ((char *)p1)[0x25] = 0;
}
//@ f_0cfb30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das erste Trefferpunkte-Würfelwort bei Offset +0x26 der Monsterstruktur p1
 *   aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird das kodierte Schadenswürfel-Wort bei Offset +0x26.
 === Ende Beschreibung === */
short f_0cfb30(int p1)
{
    return *(short *)(p1 + 0x26);
}
//@ f_0cfb40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode speichert das erste Trefferpunkte-Würfelwort p2 bei Offset +0x26 der
 *   Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie das kodierte Würfelwort p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb40(int p1, int p2)
{
    *(short *)(p1 + 0x26) = (short)p2;
}
//@ f_0cfb50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das zweite Trefferpunkte-Würfelwort bei Offset +0x28 der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird das kodierte Schadenswürfel-Wort bei Offset +0x28.
 === Ende Beschreibung === */
short f_0cfb50(int p1)
{
    return *(short *)(p1 + 0x28);
}
//@ f_0cfb60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode speichert das zweite Trefferpunkte-Würfelwort p2 bei Offset +0x28 der
 *   Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie das kodierte Würfelwort p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb60(int p1, int p2)
{
    *(short *)(p1 + 0x28) = (short)p2;
}
//@ f_0cfb70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest den zusätzlichen Schadensbonus (vorzeichenbehaftetes Byte bei Offset
 *   +0x35) der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Schadensbonus als 16-Bit-Ganzzahl.
 === Ende Beschreibung === */
short f_0cfb70(int p1)
{
    return (short)*(char *)(p1 + 0x35);
}
//@ f_0cfb80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Schadensbonus bei Offset +0x35 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Schadensbonus p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb80(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x35) = (unsigned char)p2;
}
//@ f_0cfb90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode addiert p2 auf den Schadensbonus bei Offset +0x35 der Monsterstruktur p1 und begrenzt
 *   ihn nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Änderungswert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfb90(int p1, int p2)
{
  char *p = (char *)p1;
  p[0x35] += p2;
  if ((signed char)p[0x35] < 0) p[0x35] = 0;
}
//@ f_0cfbb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x2a (Aktions-/Bewegungspunkte) der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Bytewert bei Offset +0x2a.
 === Ende Beschreibung === */
unsigned char f_0cfbb0(int p1)
{
    return *(unsigned char *)(p1 + 0x2a);
}
//@ f_0cfbc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in das Byte bei Offset +0x2a der Monsterstruktur p1 und begrenzt den
 *   Wert nach oben auf 10.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfbc0(char *p1, signed char p2)
{
  p1[0x2a] = p2;
  if (p2 > 10) p1[0x2a] = 10;
}
//@ f_0cfbd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest den Bewegungs-/Geschwindigkeitswert bei Offset +0x2b der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x2b.
 === Ende Beschreibung === */
unsigned char f_0cfbd0(int p1)
{
    return *(unsigned char *)(p1 + 0x2b);
}
//@ f_0cfbe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Bewegungswert bei Offset +0x2b der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfbe0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x2b) = (unsigned char)p2;
}
//@ f_0cfbf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode addiert p2 auf den Bewegungswert bei Offset +0x2b der Monsterstruktur p1 und begrenzt
 *   das Ergebnis nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die Änderung p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfbf0(int p1, int p2)
{
  char *p = (char *)p1;
  if ((signed char)(p[0x2b] += p2) < 0) p[0x2b] = 0;
}
//@ f_0cfc10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x2c (Magie-/Immunitätsflag gegen normale Waffen) der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x2c.
 === Ende Beschreibung === */
signed char f_0cfc10(int p1)
{
    return *(signed char *)(p1 + 0x2c);
}
//@ f_0cfc20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x2c der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfc20(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x2c) = (unsigned char)p2;
}
//@ f_0cfc30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x2d der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x2d.
 === Ende Beschreibung === */
signed char f_0cfc30(int p1)
{
    return *(signed char *)(p1 + 0x2d);
}
//@ f_0cfc40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x2d der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfc40(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x2d) = (unsigned char)p2;
}
//@ f_0cfc50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Kampffeld-/Einheiten-ID bei Offset +0x2e der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x2e.
 === Ende Beschreibung === */
unsigned char f_0cfc50(int p1)
{
    return *(unsigned char *)(p1 + 0x2e);
}
//@ f_0cfc60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x2e der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfc60(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x2e) = (unsigned char)p2;
}
//@ f_0cfc70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x2f der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x2f.
 === Ende Beschreibung === */
unsigned char f_0cfc70(int p1)
{
    return *(unsigned char *)(p1 + 0x2f);
}
//@ f_0cfc80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x2f der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfc80(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x2f) = (unsigned char)p2;
}
//@ f_0cfc90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x30 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x30.
 === Ende Beschreibung === */
unsigned char f_0cfc90(int p1)
{
    return *(unsigned char *)(p1 + 0x30);
}
//@ f_0cfca0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x30 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfca0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x30) = (unsigned char)p2;
}
//@ f_0cfcb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode addiert p2 auf das Byte bei Offset +0x30 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Summand p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfcb0(int p1, int p2)
{
    *(char *)(p1 + 0x30) = *(char *)(p1 + 0x30) + (char)p2;
}
//@ f_0cfcc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Stufe (vorzeichenbehaftetes Byte bei Offset +0x31) der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Stufe des Monsters.
 === Ende Beschreibung === */
signed char f_0cfcc0(int p1)
{
    return *(signed char *)(p1 + 0x31);
}
//@ f_0cfcd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die Stufe bei Offset +0x31 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die neue Stufe p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfcd0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x31) = (unsigned char)p2;
}
//@ f_0cfce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x32 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x32.
 === Ende Beschreibung === */
unsigned char f_0cfce0(int p1)
{
    return *(unsigned char *)(p1 + 0x32);
}
//@ f_0cfcf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x32 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfcf0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x32) = (unsigned char)p2;
}
//@ f_0cfd00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die aktuell gewählte Zauberspruch-ID bei Offset +0x33 der Monsterstruktur
 *   p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Zauberspruch-ID bei Offset +0x33.
 === Ende Beschreibung === */
unsigned char f_0cfd00(int p1)
{
    return *(unsigned char *)(p1 + 0x33);
}
//@ f_0cfd10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt die Zauberspruch-ID p2 in Offset +0x33 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die Zauberspruch-ID p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfd10(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x33) = (unsigned char)p2;
}
//@ f_0cfd20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Zielkennung bei Offset +0x34 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Zielkennung (1..9 für Helden, >= 10 für Monster, 0xff für kein Ziel).
 === Ende Beschreibung === */
unsigned char f_0cfd20(int p1)
{
    return *(unsigned char *)(p1 + 0x34);
}
//@ f_0cfd30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt die Zielkennung p2 in Offset +0x34 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die Zielkennung p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfd30(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x34) = (unsigned char)p2;
}
//@ f_0cfd40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode klassifiziert den Zieltyp anhand der Zielkennung bei Offset +0x34 der Monsterstruktur
 *   p1: 5 bei 0, 2 bei 1..9 (Held) und 1 bei >= 10 (Monster).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zieltyp-Code (1 für Monster, 2 für Held, 5 für leer).
 === Ende Beschreibung === */
int f_0cfd40(int p1)
{
  unsigned char v = *(unsigned char *)(p1 + 0x34);
  if (v < 10) {
    if (v == 0) return 5;
    return 2;
  }
  return 1;
}
//@ f_0cfd70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest den temporären Rüstungs-/Zustandsbonus bei Offset +0x36 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x36.
 === Ende Beschreibung === */
unsigned char f_0cfd70(int p1)
{
    return *(unsigned char *)(p1 + 0x36);
}
//@ f_0cfd80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x36 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfd80(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x36) = (unsigned char)p2;
}
//@ f_0cfd90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode addiert p2 auf das Byte bei Offset +0x36 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Summand p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfd90(int p1, int p2)
{
    *(char *)(p1 + 0x36) = *(char *)(p1 + 0x36) + (char)p2;
}
//@ f_0cfda0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Waffenzerstörungs-/Schwächungsflag bei Offset +0x37 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x37.
 === Ende Beschreibung === */
unsigned char f_0cfda0(int p1)
{
    return *(unsigned char *)(p1 + 0x37);
}
//@ f_0cfdb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt das Flag bei Offset +0x37 der Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfdb0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x37) = (unsigned char)p2;
}
//@ f_0cfdc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 0 (Tot-/Kampfunfähig-Status) des 16-Bit-Zustandsworts bei Offset +0x38
 *   der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn Bit 0 gesetzt ist, andernfalls 0.
 === Ende Beschreibung === */
unsigned char f_0cfdc0(int p1)
{
    unsigned short v = *(unsigned short *)(p1 + 0x38);
    return v & 1;
}
//@ f_0cfdd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 0 (Tot-Status) des Zustandsworts bei Offset +0x38 der Monsterstruktur
 *   p1 auf p2 & 1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfdd0(int p1, signed char p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xfe;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)(v & 1);
}
//@ f_0cfdf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 1 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 1 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfdf0(int p1)
{
    struct Bits
    {
        unsigned short low:1, bit:1, high:14;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfe00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 1 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfe00(int p1, signed char p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xfd;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 1);
}
//@ f_0cfe30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 2 (Versteinerungs-Status) des Zustandsworts bei Offset +0x38 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 2 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfe30(int p1)
{
    struct Bits
{
    unsigned short low:2, bit:1, high:13;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfe40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 2 (Versteinerungs-Status) des Zustandsworts bei Offset +0x38 der
 *   Monsterstruktur p1 auf p2 & 1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfe40(int p1, signed char p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xfb;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 2);
}
//@ f_0cfe60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 3 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 3 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfe60(int p1)
{
    struct Bits
{
    unsigned short low:3, bit:1, high:12;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfe70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 3 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfe70(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xf7;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 3);
}
//@ f_0cfe90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 4 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 4 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfe90(int p1)
{
    struct Bits
{
    unsigned short low:4, bit:1, high:11;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 4 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfea0(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xef;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 4);
}
//@ f_0cfec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 5 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 5 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfec0(int p1)
{
    struct Bits
{
    unsigned short low:5, bit:1, high:10;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 5 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfed0(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xdf;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 5);
}
//@ f_0cfef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 6 (Schlaf-/Paralyse-Status) des Zustandsworts bei Offset +0x38 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 6 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cfef0(int p1)
{
    struct Bits
{
    unsigned short low:6, bit:1, high:9;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cff00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 6 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cff00(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0xbf;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 6);
}
//@ f_0cff20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 7 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 7 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cff20(int p1)
{
    struct Bits
{
    unsigned short low:7, bit:1, high:8;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cff30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 7 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cff30(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x38) &= 0x7f;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 7);
}
//@ f_0cff50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 8 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 8 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cff50(int p1)
{
    struct Bits
{
    unsigned short low:8, bit:1, high:7;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cff60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 8 des Zustandsworts bei Offset +0x38 (p1 + 0x39, Bit 0) der
 *   Monsterstruktur p1 auf p2 & 1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cff60(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= 0xfe;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 8);
}
//@ f_0cff80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 9 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 9 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cff80(int p1)
{
    struct Bits
{
    unsigned short low:9, bit:1, high:6;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cff90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 9 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cff90(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= 0xfd;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 9);
}
//@ f_0cffb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 10 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 10 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cffb0(int p1)
{
    struct Bits
{
    unsigned short low:10, bit:1, high:5;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cffc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 10 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cffc0(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= 0xfb;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 10);
}
//@ f_0cffe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 11 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 11 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0cffe0(int p1)
{
    struct Bits
{
    unsigned short low:11, bit:1, high:4;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0cfff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 11 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cfff0(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= (unsigned char)0xf7;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 11);
}
//@ f_0d0010
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 12 (Kampfwut-Status) des Zustandsworts bei Offset +0x38 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 12 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0d0010(int p1)
{
    struct Bits
{
    unsigned short low:12, bit:1, high:3;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0d0020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 12 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0020(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= 0xef;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 12);
}
//@ f_0d0040
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest Bit 13 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Wert von Bit 13 (0 oder 1).
 === Ende Beschreibung === */
unsigned short f_0d0040(int p1)
{
    struct Bits
{
    unsigned short low:13, bit:1, high:2;
    };
    return ((Bits *)(p1 + 0x38))->bit;
}
//@ f_0d0050
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt Bit 13 des Zustandsworts bei Offset +0x38 der Monsterstruktur p1 auf p2 &
 *   1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Bitwert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0050(int p1, int p2)
{
    short v = (signed char)p2;
    *(unsigned char *)(p1 + 0x39) &= 0xdf;
    *(unsigned short *)(p1 + 0x38) |= (unsigned short)((v & 1) << 13);
}
//@ f_0d0070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x3a der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x3a.
 === Ende Beschreibung === */
unsigned char f_0d0070(int p1)
{
    return *(unsigned char *)(p1 + 0x3a);
}
//@ f_0d0080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x3b der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x3b.
 === Ende Beschreibung === */
signed char f_0d0080(int p1)
{
    return *(signed char *)(p1 + 0x3b);
}
//@ f_0d0090
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x3b der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0090(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x3b) = (unsigned char)p2;
}
//@ f_0d00a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x3c der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x3c.
 === Ende Beschreibung === */
unsigned char f_0d00a0(int p1)
{
    return *(unsigned char *)(p1 + 0x3c);
}
//@ f_0d00b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x3c der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d00b0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x3c) = (unsigned char)p2;
}
//@ f_0d00c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x3d der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x3d.
 === Ende Beschreibung === */
signed char f_0d00c0(int p1)
{
    return *(signed char *)(p1 + 0x3d);
}
//@ f_0d00d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x3d der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d00d0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x3d) = (unsigned char)p2;
}
//@ f_0d00e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest die Anzahl der Geschosse der ersten Fernkampfwaffe (16-Bit-Wort bei Offset
 *   +0x3e) der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Munitionsvorrat bei Offset +0x3e.
 === Ende Beschreibung === */
unsigned short f_0d00e0(int p1)
{
    return *(unsigned short *)(p1 + 0x3e);
}
//@ f_0d00f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Munitionsvorrat der ersten Fernkampfwaffe bei Offset +0x3e der
 *   Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d00f0(int p1, int p2)
{
    *(unsigned short *)(p1 + 0x3e) = (unsigned short)p2;
}
//@ f_0d0100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Schadenswürfel-Wort der ersten Fernkampfwaffe bei Offset +0x40 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird das 16-Bit-Wort bei Offset +0x40.
 === Ende Beschreibung === */
short f_0d0100(int p1)
{
    return *(short *)(p1 + 0x40);
}
//@ f_0d0110
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt das Schadenswürfel-Wort der ersten Fernkampfwaffe bei Offset +0x40 der
 *   Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie das Würfelwort p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0110(int p1, int p2)
{
    *(short *)(p1 + 0x40) = (short)p2;
}
//@ f_0d0120
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest den Munitionsvorrat der zweiten Fernkampfwaffe (16-Bit-Wort bei Offset
 *   +0x42) der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Munitionsvorrat bei Offset +0x42.
 === Ende Beschreibung === */
unsigned short f_0d0120(int p1)
{
    return *(unsigned short *)(p1 + 0x42);
}
//@ f_0d0130
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt den Munitionsvorrat der zweiten Fernkampfwaffe bei Offset +0x42 der
 *   Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0130(int p1, int p2)
{
    *(unsigned short *)(p1 + 0x42) = (unsigned short)p2;
}
//@ f_0d0140
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Schadenswürfel-Wort der zweiten Fernkampfwaffe bei Offset +0x44 der
 *   Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird das 16-Bit-Wort bei Offset +0x44.
 === Ende Beschreibung === */
short f_0d0140(int p1)
{
    return *(short *)(p1 + 0x44);
}
//@ f_0d0150
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt das Schadenswürfel-Wort der zweiten Fernkampfwaffe bei Offset +0x44 der
 *   Monsterstruktur p1 auf p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie das Würfelwort p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0150(int p1, int p2)
{
    *(unsigned short *)(p1 + 0x44) = (unsigned short)p2;
}
//@ f_0d0160
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x46 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x46.
 === Ende Beschreibung === */
unsigned char f_0d0160(int p1)
{
    return *(unsigned char *)(p1 + 0x46);
}
//@ f_0d0170
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x46 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0170(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x46) = (unsigned char)p2;
}
//@ f_0d0180
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x47 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenbehaftete Bytewert bei Offset +0x47.
 === Ende Beschreibung === */
signed char f_0d0180(int p1)
{
    return *(signed char *)(p1 + 0x47);
}
//@ f_0d0190
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x47 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0190(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x47) = (unsigned char)p2;
}
//@ f_0d01a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x48 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x48.
 === Ende Beschreibung === */
unsigned char f_0d01a0(int p1)
{
    return *(unsigned char *)(p1 + 0x48);
}
//@ f_0d01b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x48 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d01b0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x48) = (unsigned char)p2;
}
//@ f_0d01c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x71 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x71.
 === Ende Beschreibung === */
unsigned char f_0d01c0(int p1)
{
    return *(unsigned char *)(p1 + 0x71);
}
//@ f_0d01d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x71 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d01d0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x71) = (unsigned char)p2;
}
//@ f_0d01e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode liest das Byte bei Offset +0x72 der Monsterstruktur p1 aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der vorzeichenlose Bytewert bei Offset +0x72.
 === Ende Beschreibung === */
unsigned char f_0d01e0(int p1)
{
    return *(unsigned char *)(p1 + 0x72);
}
//@ f_0d01f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode schreibt p2 in Offset +0x72 der Monsterstruktur p1.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der neue Wert p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d01f0(int p1, int p2)
{
    *(unsigned char *)(p1 + 0x72) = (unsigned char)p2;
}
//@ f_0d0200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode gibt konstant den Wert 0x20 (32, Breite/Größe eines Monster-Sprites) zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der konstante Wert 0x20.
 === Ende Beschreibung === */
int f_0d0200(void)
{
    return 0x20;
}
//@ f_0d0210
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode gibt konstant den Wert 0x28 (40, Höhe/Größe eines Monster-Sprites) zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der konstante Wert 0x28.
 === Ende Beschreibung === */
int f_0d0210(void)
{
    return 0x28;
}

//@ f_0d0230
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode kopiert die Zeichenkette name mittels strcpy in das Namensfeld bei Offset +0x49
 *   der Monsterstruktur p.
 * - Eingaben: Übergeben werden der Zeiger p auf die Monsterstruktur sowie der Zeiger name auf die zu kopierende
 *   Namenszeichenkette.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0230(char *p, const char *name) { strcpy(p + 0x49, name); }
