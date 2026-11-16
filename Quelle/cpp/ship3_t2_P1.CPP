/* === Beschreibung (Katalog) ===
 * Einheit ship3_t2 (1087c0 - 108d10)
 *
 * Überblick
 *
 * Die Einheit ship3_t2 bildet den zweiten Teil des 3D-Dungeon-Moduls ship3 (Kennung 0x2c). Sie enthält die
 * restlichen Raum- und Kampffunktionen (f_1087c0 bis f_108ca0) sowie die Synchronisationsroutine für die
 * beweglichen Türen und Luken (f_108cc0).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 11/12 gleich (suche.py 24.10.2026, Basis ship3_t2_P1.CPP)
// ship3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x107380-0x108D10
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);
int f_046de0(int p1);
int f_047650(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf820(int p1, ...);
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbb50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0dd410(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_108d10(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a6834;                    // 0x1A6834
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0364;                    // 0x1C0364
extern int d_1c0370;                    // 0x1C0370
extern int d_1c037c;                    // 0x1C037C
extern int d_1c0390;                    // 0x1C0390
extern int d_1c03a0;                    // 0x1C03A0
extern int d_1c03a4;                    // 0x1C03A4
extern int d_1c0428;                    // 0x1C0428
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a68a4[];           // Text 0x1A68A4
// --- eigene Funktionen (32), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern signed char d_1c03a8, d_1c0380;
extern int d_1c3498;
typedef RivaTextContextData OB;
struct S0C {int a[3];};
#define D2C64 ((int)&d_1c2c64)
#define D349C ((int)&d_1c349c)
#define D3870 ((int)&d_1c3870)
#define D3498 ((int)&d_1c3498)
#define FL(x,v) (((x)==(v))?1:0)
#define GT(x,v) (((x)>(v))?1:0)
#define M(x) f_0bf730(D2C64, x)
#define OBCTOR f_125400((int)&ob, D349C, D3870, D3498)
#define OBDTOR f_1254a0((int)&ob, 0)
#define SETB(v) *(int*)(ob.addresses.objects+4) = (v)
#define NEW0C(LN,CD) { int q; int t_ = (int)new (mark(d_1a68a4, LN)) S0C; q = (t_ != 0) ? f_046d10(t_, CD) : t_; f_046de0(q); if (q) operator delete((void*)f_046d90(q, 0)); }
#define NEW0CX(LN,CD) { int q; int t_ = (int)new (mark(d_1a68a4, LN)) S0C; q = (t_ != 0) ? f_046d10(t_, CD) : t_; f_047650(q, 0); f_046de0(q); if (q) operator delete((void*)f_046d90(q, 0)); }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_1087c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Methode steuert eine mehrstufige Untersuchung einer Schatz- oder Vorratskammer
 *   (d_1c0426) in ship3 und übergibt den Helden nach erfolgreicher Prüfung die gefundenen Gegenstände.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_1087c0(void)
{
  OB ob;
  OBCTOR;
  short r = 0x63;
  if (GT(d_1c03a8, 1)) {
    f_05fa00(0x35, 0x1f46);
  } else {
    if (EQ(d_1c03a8, 1)) {
      r = f_0bf820(D2C64, 0x2f000143, 3, 0x2f000147, 0x2f000148, 0x2f000149);
    }
    if (EQ(d_1c03a8, 0)) {
      if (EQ(d_1c0380, 0)) {
        if (f_0dd410(d_1c0004, 1) == 5) {
          d_1c0380 = 1;
          r = f_0bf6f0(D2C64, 0x2f000144);
        }
      }
      if (r == (short)1 || r == 99) {
        d_1c03a8 = 1;
        SETB(f_038c40(d_1c0004));
        M(0x2f000145);
        r = f_0bf820(D2C64, 0x2f000146, 3, 0x2f000147, 0x2f000148, 0x2f000149);
      }
    }
    if (r == 1 || r == 2) {
      f_05fa00(0x35, 0x1f46);
    }
    while (r != 0 && r != -1) {
      if (r == 3) {
        OBDTOR;
        return;
      }
      switch (r) {
      case 1:
        do {
          r = f_0bf820(D2C64, 0x2f00014a, 2, 0x2f00014b, 0x2f00014c);
        } while (r == -1);
        switch (r) {
        case 1:
          M(0x2f00014d);
          d_1c03a8 = 3;
          r = 0;
          break;
        case 2:
          M(0x2f00014e);
          r = 0;
          d_1c03a8 = 2;
          break;
        }
        break;
      case 2:
        {
          int w;
          do {
            w = f_0bf820(D2C64, 0x2f00014f, 2, 0x2f000150, 0x2f000151);
          } while (w == -1);
          if (w == 2) {
            r = 1;
          } else {
            M(0x2f000152);
            r = 0;
            f_05fa00(0x35, 0x1f46);
          }
        }
        break;
      }
    }
  }
  OBDTOR;
}
//@ f_108a30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese fünf Methoden geben Raumhinweise aus, prüfen Interaktionspunkte (d_1c0427 bis d_1c0429) und
 *   übergeben vereinzelte Fundstücke in den hinteren Sektionen von ship3.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_108a30(void)
{
  NEW0CX(0x3f6, 0x47)
}

//@ f_108a90
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x48 (Quellzeile
 *   0x40a), führt die Interaktion über f_046de0 aus und baut das Objekt mit f_046d90 wieder ab.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEW0C).
 === Ende Beschreibung === */
void f_108a90(void)
{
  NEW0C(0x40a, 0x48)
}

//@ f_108ae0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x49 (Quellzeile
 *   0x41c), ruft zusätzlich f_047650(q, 0) vor f_046de0(q) auf und gibt das Objekt anschließend über f_046d90
 *   frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Erweiterter Fundstellen-Wrapper (NEW0CX mit f_047650).
 === Ende Beschreibung === */
void f_108ae0(void)
{
  NEW0CX(0x41c, 0x49)
}

//@ f_108b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x4a (Quellzeile
 *   0x430), ruft f_047650(q, 0) sowie f_046de0(q) auf und gibt den Speicher wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Erweiterter Fundstellen-Wrapper (NEW0CX).
 === Ende Beschreibung === */
void f_108b40(void)
{
  NEW0CX(0x430, 0x4a)
}

//@ f_108ba0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x4b (Quellzeile
 *   0x449), führt f_046de0 aus und gibt das Objekt wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEW0C).
 === Ende Beschreibung === */
void f_108ba0(void)
{
  NEW0C(0x449, 0x4b)
}

//@ f_108bf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese fünf kurzen Methoden starten vordefinierte Kämpfe (0x1f44 bis 0x1f48) bzw. schalten zugehörige
 *   Begegnungsflags in ship3 frei.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Kampffunktionen geben das Ergebnis von f_05fa00 zurück; Status-Setter haben keinen
 *   Rückgabewert (void).
 === Ende Beschreibung === */
void f_108bf0(void)
{
  M(0x2f000127);
}

//@ f_108c10
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000153 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (D2C64).
 * - Besonderheiten: Kurze Textausgabe-Routine.
 === Ende Beschreibung === */
void f_108c10(void)
{
  M(0x2f000153);
}

//@ f_108c30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000154 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (D2C64).
 * - Besonderheiten: Kurze Textausgabe-Routine.
 === Ende Beschreibung === */
void f_108c30(void)
{
  M(0x2f000154);
}

//@ f_108c50
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x4c (Quellzeile
 *   0x483), führt f_046de0 aus und gibt das Objekt wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEW0C).
 === Ende Beschreibung === */
void f_108c50(void)
{
  NEW0C(0x483, 0x4c)
}

//@ f_108ca0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000155 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (D2C64).
 * - Besonderheiten: Kurze Textausgabe-Routine.
 === Ende Beschreibung === */
void f_108ca0(void)
{
  M(0x2f000155);
}

//@ f_108cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode synchronisiert beim Laden oder Betreten von ship3 den Zustand der beweglichen Türen und
 *   Durchgänge in der 3D-Kartenstruktur mit den gespeicherten Flags.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_108cc0(void)
{
  NEW0C(0x4a3, 0x4d)
}
