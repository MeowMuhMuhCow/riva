/* === Beschreibung (Katalog) ===
 * Einheit gz_0e93f0_t2
 *
 * Diese Einheit bildet den zweiten Teil von gz_0e93f0 und implementiert das Wirtshaus-, Verpflegungs- und
 * Rastmodul (p:\riva\source\cpp\catering.cpp) sowie den Beginn der allgemeinen Riva-Ereignis- und
 * Skript-Hilfsfunktionen (riva.cpp). Sie steuert das Bestellen von Essen und Getränken in Tavernen, das
 * Übernachten und Rasten mit zufälligen Traum- oder Begegnungsereignissen sowie Talent- und Gegenstandsprüfungen
 * der Gruppe.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 32/43 gleich (suche.py 25.10.2026, Basis gz_0e93f0_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 23 gleich (vorher 23), Rest 750 (vorher 752)
// gz_0e93f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E93F0-0x0EA400
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
int f_043ca0(int p1);                                   // reg eax stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_05e490(int p1, int p2);                           // reg eax edx stapel 0
int f_05e770(int p1, int p2, int p3, int p4);           // reg eax ebx ecx stapel 0
int f_05e860(int p1, int p2, int p3, int p4);           // reg eax ebx ecx stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_099b10(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2);
int f_0b9060(int p1);                                   // reg eax stapel 0
int f_0b90a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0bf820(void *p1, ...);
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0daa90(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_10a260(int p1, int p2);                           // reg edx stapel 0
int f_10a270(int p1, int p2);                           // reg eax edx stapel 0
int f_10a2e0(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_10a5a0(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_1254e0(int p1);                                   // reg eax stapel 0
int f_125500(int p1);                                   // reg eax stapel 0
int f_125550(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_134010(int p1, int p2);                           // reg edx stapel 0
int f_134030(int p1, int p2);
#pragma aux f_134030 parm [eax edx] modify exact [eax];
int f_145400(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb5b8;                    // 0x1BB5B8
extern int d_1bb5e8;                    // 0x1BB5E8
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0c48;                    // 0x1C0C48
extern volatile short d_1c212a; // haelt die Lade-/Schreibfolge in f_0e96a0 wie im Original
extern short d_1c212c;                    // 0x1C212C
extern volatile int d_1c2198;   // haelt die Schreibfolge vor dem Aufruf in f_0e9d10 wie im Original
extern int d_1c27a8;                    // 0x1C27A8
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a0710[];           // Text 0x1A0710
// --- eigene Funktionen (40), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_145234(int p1, int p2);
void f_145254(void);
int f_0dbfe0(int p1);
extern int d_1bb5cc;
extern int d_1bb5fc;
extern int d_1c3498;
extern signed char d_1c01d8;
extern signed char d_1bc8fc;
extern signed char d_1c009c; extern short d_1c009d;
extern signed char d_1c00a0; extern short d_1c00a1;
extern signed char d_1c00a4; extern short d_1c00a5;
extern signed char d_1c00a8; extern short d_1c00a9;
extern signed char d_1c00ac; extern short d_1c00ad;
extern signed char d_1c00b0; extern short d_1c00b1;
extern signed char d_1c00b4; extern short d_1c00b5;
extern signed char d_1c00b8; extern short d_1c00b9;
extern signed char d_1c00bc; extern short d_1c00bd;
extern signed char d_1c00c0; extern short d_1c00c1;
extern signed char d_1c00c4; extern short d_1c00c5;
extern signed char d_1c00c8; extern short d_1c00c9;
extern signed char d_1c00cc; extern short d_1c00cd;
extern signed char d_1c00d0; extern short d_1c00d1;
extern signed char d_1c00d4; extern short d_1c00d5;
extern signed char d_1c00d8; extern short d_1c00d9;
extern signed char d_1c00dc; extern short d_1c00dd;
extern signed char d_1c00e0; extern short d_1c00e1;
extern signed char d_1c00e4; extern short d_1c00e5;

#pragma inline_depth(0)
#define EQI(x,v) (((x)==(v))?1:0)
#define PD ((int)&d_1c2c64)
struct TW { struct FV *f; short s4; short s6; short s8; short sa; short sc; short se; short s10; short s12; short s14; };
typedef RivaTextContextData OB;
int f_05e610(int p1, int p2);
int f_0e9450(int p1, char *p2, char *p3);
void f_0e9d10(int p1);
void f_0e9880(void);
struct FV { virtual int d0(); virtual int d1(); virtual unsigned char w(); };
#define f_05e270(a,b) ((int (*)(int,int))f_05e270)((a),(b))
#define f_05e440(a,b) ((int (*)(int,int))f_05e440)((a),(b))
#pragma aux f_05e440_alias "W?f_05e440$n(ii)i";
#pragma aux f_05e610_alias "W?f_05e610$n(ii)i";
#pragma aux f_05e270_alias "W?f_05e270$n(ii)i";
//@ f_0e96a0
/* === Beschreibung (Katalog) ===
 * Registriert den Sättigungs- bzw. Bewirtungs-Timer d_1c009c (mit Kennbyte d_1c009d = 0x91) in der globalen
 * Spielstands- und Zeitgeberliste (d_1c212c / d_1c212a).
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e96a0(void)
{
  d_1c009c = 0;
  d_1c009d = 0x91;
  ((signed char **)*(int **)&d_1c212c)[d_1c212a] = &d_1c009c;
  d_1c212a += 1;
}
//@ f_0e96e0
/* === Beschreibung (Katalog) ===
 * Konstruktor des Tavernen-Gebäudeobjekts (p1), der den Basiskonstruktor f_0b8490 mit der Ortskennung p2 aufruft
 * und die virtuelle Methodentabelle auf d_1bb5cc (f_0e9790) setzt.
 * - Eingaben: Übergeben werden der Objektzeiger p1 sowie die Ortskennung p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0e96e0(int p1, int p2)
{
  int r = f_0b8490(p1, (short)p2);
  *(int *)(r + 0x58) = (int)&d_1bb5cc;
  return r;
}
//@ f_0e96f0
/* === Beschreibung (Katalog) ===
 * Destruktor des Tavernen-Gebäudeobjekts (p1), der die virtuelle Methodentabelle auf d_1bb5cc zurücksetzt, den
 * Basisdestruktor f_0b8520 aufruft und bei gesetztem Bit 1 in p2 den Objektspeicher freigibt.
 * - Eingaben: Übergeben werden der Objektzeiger p1 sowie die Destruktor-Steuerflags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger zurück.
 === Ende Beschreibung === */
int f_0e96f0(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)&d_1bb5b8);
    f_145254();
    return p1;
  }
  *(int *)(p1 + 0x58) = (int)&d_1bb5cc;
  r = f_0b8520(p1, 1);
  if (p2 & 2) operator delete((void *)r);
  return r;
}
//@ f_0e9740
/* === Beschreibung (Katalog) ===
 * Schaltet die Schaltfläche für die Essensbestellung in der Taverne (Button-ID 9 in d_1bfdb8) frei (f_0daaf0),
 * wenn die Gruppe noch nichts gegessen hat (d_1c009c == 0), oder sperrt sie (f_0daa90), solange die Sperrzeit
 * nach einer Mahlzeit noch läuft.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Rückgabewert der Schaltflächen-Steuerfunktion zurück.
 === Ende Beschreibung === */
int f_0e9740(void)
{
  if (EQI(d_1c009c, 0)) return f_0daaf0(d_1bfdb8, 9);
  return f_0daa90(d_1bfdb8, 9);
}
//@ f_0e9780
/* === Beschreibung (Katalog) ===
 * Leere Platzhalterfunktion des Tavernenmoduls, die sofort zurückkehrt.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9780(void)
{
}
//@ f_0e9790
/* === Beschreibung (Katalog) ===
 * Verarbeitet als virtuelle Ereignismethode einer Taverne (p1) die Benutzeraktionen p2: Bei 0x81 wird das
 * Gespräch mit dem Wirt gestartet (f_0b9060), bei 0x89 wird Essen und Trinken für die Gruppe bestellt
 * (f_0e9880), und beim Verlassen (0x80) wird - falls die Zeche (d_1c01d8 == 1) noch offen ist - ein Dialog
 * (0x2200003d) angezeigt, über den die Gruppe bei Weigerung in einen Kampf (f_0dd7f0) verwickelt werden kann.
 * - Eingaben: Übergeben werden der Zeiger auf das Tavernenobjekt p1 sowie der Aktionscode p2.
 * - Rückgabewert: Sie gibt beim Verlassen (0x80) den Wert 1 zurück, sonst 0.
 === Ende Beschreibung === */
int f_0e9790(int p1, unsigned short p2)
{
  int r = 0;
  short x, y, s;
  int mb;
  switch (p2) {
  case 0: break;
  case 0x81: f_0b9060(p1); break;
  case 0x89: f_0e9880(); break;
  case 0x80:
    if (EQI(d_1c01d8, 1)) {
      s = f_0de820(d_1c0004);
      if (s == 2) { mb = 0x22000040; r = 0x22000041; x = 0x18b4; y = 0; }
      else { mb = 0x2200003e; r = 0x2200003f; y = 2; x = 0x165f; }
      if ((short)f_0bf820(&d_1c2c64, 0x2200003d, 2, mb, r) == 1) f_0dd7f0(d_1c0004, y, x);
    }
    r = 1;
    break;
  }
  return r;
}
//@ f_0e9850
/* === Beschreibung (Katalog) ===
 * Prüft als Filterfunktion für f_0398c0, ob ein Held (p1) lebendig bzw. handlungsfähig ist (f_0d4a60), aber
 * aufgrund eines besonderen Zustands (f_043ca0, z. B. Vampirismus oder Versteinerung) im Wirtshaus nichts essen
 * kann.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Heldenstruktur p1.
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Held von der Mahlzeit ausgeschlossen ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0e9850(int p1)
{
  if (f_043ca0(p1)) {
    if (f_0d4a60(p1)) return 1;
  }
  return 0;
}
//@ f_0e9880
/* === Beschreibung (Katalog) ===
 * Führt die Essens- und Getränkebestellung im Wirtshaus durch: Sie zählt die teilnehmenden Helden, berechnet den
 * Preis von 10 Hellern pro Person (mit 1 Heller Rabatt, falls ein Held eine bestimmte Vergünstigung
 * f_0dd3a0(..., 6, 0) besitzt), zieht den Betrag vom Gruppengeld ab (f_0db8b0), sperrt weitere Mahlzeiten für 30
 * Zeiteinheiten (d_1c009c = 0x1e), regeneriert bei allen essenden Helden Lebens- und Ausdauerpunkte (f_044850)
 * und senkt ihren Hunger- und Durstwert (f_0d5040).
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9880(void)
{
  OB ob;
  int *item = &d_1c27a8;
  short sVar1, sVar2, sVar6;
  int iVar3, iVar4, uVar5;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  sVar1 = f_0398c0(d_1c0004, (int)f_0e9850, (int)item);
  sVar2 = f_0dbfe0(d_1c0004);
  sVar2 = sVar2 - sVar1;
  sVar6 = sVar2 * 10;
  if ((0 < sVar1) && (sVar1 < sVar2)) {
    sVar2 = sVar2 - sVar1;
    sVar6 = sVar2 * 10;
  }
  f_0bf730(PD, 0x22000042);
  if (0 < sVar1) {
    *(int *)(ob.addresses.objects + 8) = *item;
    f_0bf730(PD, 0x220000ae);
    sVar1 = f_0de7f0(d_1c0004);
    if (sVar1 == 1) goto LAB_end;
  }
  iVar3 = f_0de7e0(d_1c0004);
  if (d_1bb5b8 & 0) d_1bb5b8 = 0; // haelt die Registervergabe fuer Konstanten in f_0e9880 wie im Original
  if (d_1bb5e8 & 0) d_1bb5e8 = 0; // haelt die Registervergabe fuer Konstanten in f_0e9880 wie im Original
  if (d_1bd91c & 0) d_1bd91c = 0; // haelt die Registervergabe fuer Konstanten in f_0e9880 wie im Original
  if (iVar3 < sVar6) {
    f_0bf730(PD, 0x22000043);
  }
  else {
    iVar3 = f_0dd3a0(d_1c0004, 6, 0);
    if (iVar3 != 0) {
      iVar4 = f_043ca0(iVar3);
      if ((iVar4 == 0) && (1 < sVar2)) {
        *(int *)(ob.addresses.objects + 4) = iVar3;
        sVar6 = sVar6 - 1;
        f_0bf730(PD, 0x22000044);
      }
    }
    f_0db8b0(d_1c0004, sVar6);
    d_1c009c = 0x1e;
    f_0daa90(d_1bfdb8, 9);
    uVar5 = f_038c40(d_1c0004);
    *(int *)(ob.addresses.objects + 8) = uVar5;
    f_0bf730(PD, 0x22000045);
    f_0bf730(PD, 0x22000046);
    f_0bf730(PD, 0x22000047);
    if (1 < sVar2) {
      f_0bf730(PD, 0x22000048);
    }
    {
      register int five = 5;
      register int one = 1;
      iVar3 = f_038c80(d_1c0004);
      do {
        if (f_0d4a60(iVar3) && !f_043ca0(iVar3)) {
          f_044850(iVar3, one, five);
        }
        iVar3 = f_0391b0(d_1c0004, iVar3);
        iVar4 = f_038c40(d_1c0004);
      } while (iVar3 != iVar4);
    }
    iVar3 = f_038c80(d_1c0004);
    do {
      iVar4 = f_0d4a60(iVar3);
      if (iVar4 != 0) {
        iVar4 = f_043ca0(iVar3);
        if (iVar4 == 0) {
          f_0d5040(iVar3, (short)f_0d4c80(iVar3), 0x3f480, 2, 1, 0);
        }
      }
      iVar3 = f_0391b0(d_1c0004, iVar3);
      iVar4 = f_038c40(d_1c0004);
    } while (iVar3 != iVar4);
  }
LAB_end:
  f_1254a0((int)&ob, 0);
}
//@ f_0e9ac0
/* === Beschreibung (Katalog) ===
 * Prüft beim Verlassen einer Taverne als eigenständige Hilfsfunktion, ob das Zechpreller-Flag d_1c01d8 == 1
 * gesetzt ist, und stellt den Spieler vor die Wahl (0x2200003d), woraufhin bei entsprechender Antwort ein Kampf
 * (f_0dd7f0, je nach Ort 0x18b4 oder 0x165f) ausgelöst wird.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9ac0(void)
{
  short x, y, s;
  int ma, mb;
  if (EQI(d_1c01d8, 1)) {
    s = f_0de820(d_1c0004);
    if (s == 2) { ma = 0x22000040; mb = 0x22000041; x = 0x18b4; y = 0; }
    else { ma = 0x2200003e; mb = 0x2200003f; y = 2; x = 0x165f; }
    if ((short)f_0bf820(&d_1c2c64, 0x2200003d, 2, ma, mb) == 1) f_0dd7f0(d_1c0004, y, x);
  }
}
//@ f_0e9b40
/* === Beschreibung (Katalog) ===
 * Konstruktor des Rast- bzw. Herbergsobjekts (p1), der den Basiskonstruktor f_10a260 mit p2 aufruft und die
 * virtuelle Methodentabelle auf d_1bb5fc (f_0e9ba0) setzt.
 * - Eingaben: Übergeben werden der Objektzeiger p1 sowie der Initialisierungsparameter p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0e9b40(int p1, int p2)
{
  int r = f_10a260(p1, (short)p2);
  *(int *)(r + 0x58) = (int)&d_1bb5fc;
  return r;
}
//@ f_0e9b50
/* === Beschreibung (Katalog) ===
 * Destruktor des Rast- bzw. Herbergsobjekts (p1), der die virtuelle Methodentabelle auf d_1bb5fc setzt, den
 * Basisdestruktor f_10a270 aufruft und bei gesetztem Bit 1 in p2 den Speicher freigibt.
 * - Eingaben: Übergeben werden der Objektzeiger p1 sowie die Destruktor-Steuerflags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger zurück.
 === Ende Beschreibung === */
int f_0e9b50(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)&d_1bb5e8);
    f_145254();
    return p1;
  }
  *(int *)(p1 + 0x58) = (int)&d_1bb5fc;
  r = f_10a270(p1, 1);
  if (p2 & 2) operator delete((void *)r);
  return r;
}
//@ f_0e9ba0
/* === Beschreibung (Katalog) ===
 * Verarbeitet als virtuelle Ereignismethode des Rast- bzw. Herbergsobjekts (p1) den Aktionscode p2: Bei 0x9b
 * wird der Schlaf- und Rastdialog (f_0e9d10) aufgerufen, bei 0x80 wird das Verlassen mit 1 bestätigt.
 * - Eingaben: Übergeben werden der Objektzeiger p1 sowie der Aktionscode p2.
 * - Rückgabewert: Sie gibt 1 beim Verlassen (0x80) zurück, sonst 0.
 === Ende Beschreibung === */
int f_0e9ba0(int p1, unsigned short p2)
{
  int r = 0;
  switch (p2) {
    case 0x9b: f_0e9d10(p1); break;
    case 0x80: r = 1; break;
  }
  return r;
}
//@ f_0e9bc0
/* === Beschreibung (Katalog) ===
 * Leere Platzhalterfunktion, die ohne Aktion zurückkehrt.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9bc0(void)
{
}
//@ f_0e9be0
/* === Beschreibung (Katalog) ===
 * Leitet den übergebenen 16-Bit-Zeiger p1 direkt an die Hilfsfunktion f_02dee0 weiter.
 * - Eingaben: Die Funktion erhält den Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
extern void f_02dee0_alias(short *);
#pragma aux f_02dee0_alias "W?f_02dee0$n(p)v";
void f_0e9be0(short *p1) { f_02dee0_alias(p1); }
//@ f_0e9bf0
/* === Beschreibung (Katalog) ===
 * Wählt anhand der aktuellen Ortskennung der Gruppe (f_0de820) und eines Prozentwurfs (f_1457e0(100)) ein
 * zufälliges nächtliches Ereignis oder eine Traumsequenz aus (0x6f..0x78 bzw. 0x92..0x93) und startet diese bei
 * einem Treffer über f_08c920.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt 1 zurück, wenn ein Ereignis ausgelöst wurde, andernfalls 0.
 === Ende Beschreibung === */
short f_0e9bf0(void)
{
  short r = f_1457e0(100);
  short ret = 0;
  short u = (short)f_0de820(d_1c0004);
  int m;
  switch (u) {
  case 0: m = (r > 0x32) + 0x77; break;
  case 1: m = (r > 0x32) + 0x92; break;
  case 5:
    if (r <= 0x22) m = 0x6f;
    else m = (r > 0x43) + 0x70;
    break;
  case 0xf: case 0x10: case 0x11: m = (r > 0x32) + 0x72; break;
  case 0x13: case 0x15: case 0x16:
    if (r <= 0x22) m = 0x75;
    else if (r <= 0x43) m = 0x74;
    else m = 0x76;
    break;
  default: m = 0; break;
  }
  if ((short)m > 0) {
    d_1bd91c = 1;
    ret = 1;
    f_08c920((short)m, 0);
  }
  return ret;
}
//@ f_0e9d10
/* === Beschreibung (Katalog) ===
 * Steuert das Rasten und Schlafen im Objekt p1: Ist keine freie Wahl der Schlafdauer erlaubt (d_1bc8fc == 0),
 * wird direkt über f_10a2e0 gerastet; andernfalls fragt ein Dialog (f_0bf7b0, Text 0x220101b7) die gewünschte
 * Stundenzahl (0..24) ab, teilt die Schlafzeit zufällig in zwei Abschnitte (a und d), lässt den ersten Teil über
 * f_10a5a0 vergehen, würfelt ein Ortsereignis (f_08c920) aus und setzt anschließend die restliche Schlafzeit d
 * fort.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Rast- bzw. Herbergsobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9d10(int p1)
{
  int m, v, d, r;
  short a, x;
  unsigned short s;
  if (EQI(d_1bc8fc, 0)) {
    f_10a2e0(p1, 0, 0x18, 1, 2);
  } else {
    r = f_0bf7b0(PD, 2, 0x220101b7, 0, 0x18, 0x18);
    if ((short)r > 0) {
      d = f_1457e0((short)((short)r / 2 + 1));
      a = (short)d;
      d = r - d;
      f_10a5a0(p1, 0, a, 1, 2);
      x = f_1457e0(0x64);
      m = 0;
      s = (unsigned short)f_0de820(d_1c0004);
      switch (s) {
      case 0:  v = (x > 0x32) + 0x77; break;
      case 1:  v = (x > 0x32) + 0x92; break;
      case 5:  if (x <= 0x22) v = 0x6f; else v = (x > 0x43) + 0x70; break;
      case 0xf: case 0x10: case 0x11:
        v = (x > 0x32) + 0x72; break;
      case 0x13: case 0x15: case 0x16:
        if (x <= 0x22) v = 0x75; else if (x <= 0x43) v = 0x74; else v = 0x76; break;
      default: v = 0; break;
      }
      v = (short)v;
      if (v > 0) {
        d_1bd91c = 1;
        f_08c920(v, 0);
        m = 1;
      }
      if ((short)d > 0) {
        if (m == 1) {
          *(short *)&d_1c2198 = 0;
          f_0b90a0(p1, m);
        }
        f_10a5a0(p1, 0, (short)d, 1, 2);
      }
    }
  }
}
//@ f_0e9ee0
/* === Beschreibung (Katalog) ===
 * Registriert beim Programmstart 18 globale Zustandsobjekte (d_1c00a0 bis d_1c00e4) mit ihren festen Orts- bzw.
 * Ereigniskennungen (0x02, 0x03, 0x04, 0x05, 0x09, 0x29, 0x2a, 0x89, 0x169, 0x16a, 0x196, 0x1b0, 0x1b1, 0x1b2,
 * 0x1b3, 0x248, 0x263, 0x269) in der zentralen Verwaltungsliste d_1c212a.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
#pragma inline_depth(3)
struct RR700V3_0e9ee08;
struct OR700V3_0e9ee08 { signed char flag; short number; char pad; OR700V3_0e9ee08 *init(RR700V3_0e9ee08 &r,short id,signed char f);OR700V3_0e9ee08 *initDirect(RR700V3_0e9ee08 &r,short id,signed char f); };
struct RR700V3_0e9ee08 { short count; OR700V3_0e9ee08 **list; void append(OR700V3_0e9ee08 *o) {list[count]=o;count++;} };
inline OR700V3_0e9ee08 *OR700V3_0e9ee08::init(RR700V3_0e9ee08 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
inline OR700V3_0e9ee08 *OR700V3_0e9ee08::initDirect(RR700V3_0e9ee08 &r,short id,signed char f){flag=f;number=id;r.list[r.count]=this;r.count++;return this;}
extern RR700V3_0e9ee08 regR700V3_0e9ee08;
#pragma aux regR700V3_0e9ee08 "d_1c212a"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00a0;
#pragma aux obR700V3_0e9ee0_1c00a0 "d_1c00a0"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00a4;
#pragma aux obR700V3_0e9ee0_1c00a4 "d_1c00a4"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00a8;
#pragma aux obR700V3_0e9ee0_1c00a8 "d_1c00a8"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00ac;
#pragma aux obR700V3_0e9ee0_1c00ac "d_1c00ac"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00b0;
#pragma aux obR700V3_0e9ee0_1c00b0 "d_1c00b0"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00b4;
#pragma aux obR700V3_0e9ee0_1c00b4 "d_1c00b4"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00b8;
#pragma aux obR700V3_0e9ee0_1c00b8 "d_1c00b8"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00bc;
#pragma aux obR700V3_0e9ee0_1c00bc "d_1c00bc"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00c0;
#pragma aux obR700V3_0e9ee0_1c00c0 "d_1c00c0"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00c4;
#pragma aux obR700V3_0e9ee0_1c00c4 "d_1c00c4"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00c8;
#pragma aux obR700V3_0e9ee0_1c00c8 "d_1c00c8"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00cc;
#pragma aux obR700V3_0e9ee0_1c00cc "d_1c00cc"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00d0;
#pragma aux obR700V3_0e9ee0_1c00d0 "d_1c00d0"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00d4;
#pragma aux obR700V3_0e9ee0_1c00d4 "d_1c00d4"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00d8;
#pragma aux obR700V3_0e9ee0_1c00d8 "d_1c00d8"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00dc;
#pragma aux obR700V3_0e9ee0_1c00dc "d_1c00dc"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00e0;
#pragma aux obR700V3_0e9ee0_1c00e0 "d_1c00e0"
extern OR700V3_0e9ee08 obR700V3_0e9ee0_1c00e4;
#pragma aux obR700V3_0e9ee0_1c00e4 "d_1c00e4"
void f_0e9ee0(void) {
obR700V3_0e9ee0_1c00a0.init(regR700V3_0e9ee08,0x2,0x0);
obR700V3_0e9ee0_1c00a4.init(regR700V3_0e9ee08,0x3,0x0);
obR700V3_0e9ee0_1c00a8.init(regR700V3_0e9ee08,0x4,0x0);
obR700V3_0e9ee0_1c00ac.initDirect(regR700V3_0e9ee08,0x5,0x0);
obR700V3_0e9ee0_1c00b0.init(regR700V3_0e9ee08,0x9,0x0);
obR700V3_0e9ee0_1c00b4.init(regR700V3_0e9ee08,0x29,0x0);
obR700V3_0e9ee0_1c00b8.initDirect(regR700V3_0e9ee08,0x2a,0x0);
obR700V3_0e9ee0_1c00bc.init(regR700V3_0e9ee08,0x89,0x0);
obR700V3_0e9ee0_1c00c0.init(regR700V3_0e9ee08,0x169,0x0);
obR700V3_0e9ee0_1c00c4.initDirect(regR700V3_0e9ee08,0x16a,0x0);
obR700V3_0e9ee0_1c00c8.init(regR700V3_0e9ee08,0x196,0x0);
obR700V3_0e9ee0_1c00cc.init(regR700V3_0e9ee08,0x1b0,0x0);
obR700V3_0e9ee0_1c00d0.initDirect(regR700V3_0e9ee08,0x1b1,0x0);
obR700V3_0e9ee0_1c00d4.init(regR700V3_0e9ee08,0x1b2,0x0);
obR700V3_0e9ee0_1c00d8.init(regR700V3_0e9ee08,0x1b3,0x0);
obR700V3_0e9ee0_1c00dc.initDirect(regR700V3_0e9ee08,0x248,0x0);
obR700V3_0e9ee0_1c00e0.init(regR700V3_0e9ee08,0x263,0x0);
obR700V3_0e9ee0_1c00e4.init(regR700V3_0e9ee08,0x269,0x0);
}

#pragma inline_depth(0)

//@ f_0ea210
/* === Beschreibung (Katalog) ===
 * Ruft die Steuerfunktion f_030ed0(p1, 1) auf, um eine Eigenschaft oder Option am Zielobjekt p1 zu aktivieren.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea210(int p1)
{
  f_030ed0(p1, 1);
}
//@ f_0ea220
/* === Beschreibung (Katalog) ===
 * Ruft die Steuerfunktion f_030ed0(p1, 0) auf, um eine Eigenschaft oder Option am Zielobjekt p1 zu deaktivieren.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea220(int p1)
{
  f_030ed0(p1, 0);
}
//@ f_0ea230
/* === Beschreibung (Katalog) ===
 * Ruft für den Helden bzw. das Objekt p1 die Funktion f_040780 mit dem Parameterwert 10 auf.
 * - Eingaben: Die Funktion erhält den Objekt- bzw. Heldenzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea230(int p1)
{
  f_040780(p1, 10);
}
//@ f_0ea240
/* === Beschreibung (Katalog) ===
 * Ruft für den Helden bzw. das Objekt p1 die Funktion f_040780 mit dem Parameterwert 5 auf.
 * - Eingaben: Die Funktion erhält den Objekt- bzw. Heldenzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea240(int p1)
{
  f_040780(p1, 5);
}
//@ f_0ea250
/* === Beschreibung (Katalog) ===
 * Ruft für den Helden bzw. das Objekt p1 die Funktion f_040780 mit dem Parameterwert 2 auf.
 * - Eingaben: Die Funktion erhält den Objekt- bzw. Heldenzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea250(int p1)
{
  f_040780(p1, 2);
}
//@ f_0ea260
/* === Beschreibung (Katalog) ===
 * Legt für alle Gruppenmitglieder (f_038c40 / f_0391b0) eine Talentprobe auf das Talent p1 mit dem Zuschlag p2
 * ab (f_044c90) und ermittelt denjenigen Helden, der die Probe bestanden hat (v <= 0) und dabei die meisten
 * Punkte übrig behalten hat (kleinster negativer Wert v).
 * - Eingaben: Übergeben werden der Talentindex p1 sowie die Probenerschwernis bzw. der Modifikator p2.
 * - Rückgabewert: Sie gibt den Zeiger auf den erfolgreichsten Helden zurück oder 0, falls kein Gruppenmitglied
 *   die Talentprobe bestanden hat.
 === Ende Beschreibung === */
int f_0ea260(short p1, short p2)
{
  short best = 99;
  short v;
  int cur = f_038c40(d_1c0004);
  int res = 0;
  do {
    v = f_044c90(cur, (short)p1, (signed char)p2);
    if (v <= 0 && v < best) {
      res = cur;
      best = v;
    }
    cur = f_0391b0(d_1c0004, cur);
  } while (cur != f_038c40(d_1c0004));
  return res;
}
//@ f_0ea2d0
/* === Beschreibung (Katalog) ===
 * Durchsucht die aktuelle Heldengruppe nach einem weiblichen Gruppenmitglied (f_042380(p) == 1) und gibt dessen
 * Zeiger zurück; falls sich keine Heldin in der Gruppe befindet, wird der Gruppenanführer (f_038c40)
 * zurückgegeben.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den Zeiger auf das gefundene weibliche Gruppenmitglied oder ersatzweise auf den
 *   ersten Helden der Gruppe zurück.
 === Ende Beschreibung === */
int f_0ea2d0(void)
{
  int p = f_038c40(d_1c0004);
  int res = p;
  do {
    if ((signed char)((int)(f_042380((struct hero *)(p)))) == 1) { res = p; break; }
    p = f_0391b0(d_1c0004, p);
  } while (p != f_038c40(d_1c0004));
  return res;
}
//@ f_0ea320
/* === Beschreibung (Katalog) ===
 * Kapselt den Aufruf der Grafik-/Animationsroutine f_056a30((short)p1) zwischen den Vorbereitungs- und
 * Abschlussfunktionen f_056930() und f_056950().
 * - Eingaben: Die Funktion erhält den 16-Bit-Parameter p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea320(int p1)
{
  f_056930();
  f_056a30((short)p1);
  f_056950();
}
//@ f_0ea340
/* === Beschreibung (Katalog) ===
 * Kapselt den Aufruf der Grafik-/Animationsroutine f_056a40((short)p1) zwischen den Vorbereitungs- und
 * Abschlussfunktionen f_056930() und f_056950().
 * - Eingaben: Die Funktion erhält den 16-Bit-Parameter p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea340(int p1)
{
  f_056930();
  f_056a40((short)p1);
  f_056950();
}
//@ f_0ea360
/* === Beschreibung (Katalog) ===
 * Überprüft bei allen Mitgliedern der Heldengruppe die beiden Waffenhand-Inventarplätze 3 (rechte Hand) und 12
 * (linke Hand) und zerstört bzw. entfernt (f_033530) jeden dort angelegten Gegenstand, der nicht für den
 * Unterwasser- oder Spezialeinsatz zugelassen ist (f_0a7a90() == 0, etwa brennende Fackeln beim Tauchen).
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0ea360(void)
{
  const int b = 12;
  int p1 = f_038c40(d_1c0004);
  const int a = 3;
  do {
    short s1 = (short)((unsigned short)(f_042a60((struct hero *)(p1), a)));
    short s2 = (short)((unsigned short)(f_042a60((struct hero *)(p1), b)));
    int item = *(int *)((*(char **)&d_1c2c40) + (int)s1 * 4);
    if (((RivaItemDefinition*)(item))->f_0a7a90() == 0) f_033530(p1, a);
    item = *(int *)((*(char **)&d_1c2c40) + (int)s2 * 4);
    if (((RivaItemDefinition*)(item))->f_0a7a90() == 0) f_033530(p1, b);
    p1 = f_0391b0(d_1c0004, p1);
  } while (p1 != f_038c40(d_1c0004));
}

#pragma inline_depth(3)
