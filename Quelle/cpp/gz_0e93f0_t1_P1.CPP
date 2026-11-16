/* === Beschreibung (Katalog) ===
 * Einheit gz_0e93f0_t1
 *
 * Diese Einheit bildet den ersten Teil von gz_0e93f0 (Ende der Text- und Schrift-Wrapper-Methoden rund um
 * d_1c38b0 sowie Beginn von catering.cpp). Sie stellt die zentralen Auflösungs-, Platzhalter-Ersetzungs-, Mess-
 * und Zeichenfunktionen für lokalisierte Textkennungen (p2 / p3) bereit.
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
extern short d_1c212a;                    // 0x1C212A
extern short d_1c212c;                    // 0x1C212C
extern int d_1c2198;                    // 0x1C2198
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
#define PD ((int)&d_1c2c64)
struct TW { struct FV *f; short s4; short s6; short s8; short sa; short sc; short se; short s10; short s12; short s14; };
typedef RivaTextContextData OB;
int f_05e610(int p1, int p2);
int f_0e9450(int p1, char *p2, char *p3);
void f_0e9d10(int p1);
void f_0e9880(void);
struct FV { virtual int d0(); virtual int d1(); virtual unsigned char w(); };
//@ f_05e270
/* === Beschreibung (Katalog) ===
 * Hilfsdeklaration im Kopfbereich für den Aufruf der Textbreiten-Berechnungsfunktion f_05e270.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt sowie der Zeiger auf die Zeichenkette.
 * - Rückgabewert: Sie gibt die Pixelbreite der Zeichenkette zurück.
 === Ende Beschreibung === */
struct F270 { virtual int d0(); virtual int d1(); virtual unsigned char w(int c); };
short f_05e270(int p1, int p2);
#define f_05e270(a,b) ((int (*)(int,int))f_05e270)((a),(b))
//@ f_05e440
/* === Beschreibung (Katalog) ===
 * Hilfsdeklaration im Kopfbereich für den Aufruf der mehrzeiligen Textausgabefunktion f_05e440.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt sowie der Zeiger auf die Zeichenkette.
 * - Rückgabewert: Sie gibt den Rückgabestatus der Textausgabe zurück.
 === Ende Beschreibung === */
short f_05e440(int p1, int p2);
#define f_05e440(a,b) ((int (*)(int,int))f_05e440)((a),(b))
//@ f_05e610
/* === Beschreibung (Katalog) ===
 * Hilfsdeklaration im Kopfbereich für den Aufruf der Zeilenanzahl-Berechnungsfunktion f_05e610.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt sowie der Zeiger auf die Zeichenkette.
 * - Rückgabewert: Sie gibt die Anzahl der umbrochenen Textzeilen zurück.
 === Ende Beschreibung === */
//@ f_0e93f0
/* === Beschreibung (Katalog) ===
 * Löst eine 32-Bit-Textkennung p3 über den Textmanager (f_134010 / f_134030 bzw. f_099b10) in die zugehörige
 * Rohtext-Zeichenkette auf und kopiert diese unter Ersetzung aller Grammatik- und Namensplatzhalter (0x1b) über
 * f_0e9450 in den Zielpuffer p2.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, der Zielpuffer p2 sowie die 32-Bit-Textkennung p3.
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Text gefunden und expandiert wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0e93f0(int p1, int p2, int p3)
{
  int r = 0;
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p3);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p3); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p3);
  if (t != 0) {
    r = 1;
    f_0e9450(p1, (char *)p2, (char *)t);
  }
  return r;
}
//@ f_0e9440
/* === Beschreibung (Katalog) ===
 * Ruft f_0e9450(p1, p2, p3) auf, um einen Rohtext p3 inklusive aller Platzhalter-Sequenzen in den Zielpuffer p2
 * zu expandieren, und liefert anschließend fest 1 zurück.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, der Zielpuffer p2 sowie der Zeiger auf den Rohtext
 *   p3.
 * - Rückgabewert: Die Funktion gibt immer 1 zurück.
 === Ende Beschreibung === */
int f_0e9440(int p1, char *p2, char *p3)
{
  f_0e9450(p1, p2, p3);
  return 1;
}
//@ f_0e9450
/* === Beschreibung (Katalog) ===
 * Expandiert einen Rohtext p3 Zeichen für Zeichen in den Zielpuffer p2, indem sie dreibytige Escape-Platzhalter
 * (0x1b gefolgt von drei Steuerbytes a, b, d) an den Grammatik- und Textgenerator (f_125550 / f_125500 auf
 * d_1c0c48) übergibt und deren dynamische Ersetzung (wie Heldennamen, Pronomen oder Artikel) in den
 * Ausgabestring einfügt.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, der Zielpuffer p2 sowie der Zeiger auf den
 *   nullterminierten Rohtext p3.
 * - Rückgabewert: Sie gibt die Anzahl der geschriebenen Bytes (einschließlich des abschließenden Nullbytes)
 *   zurück.
 === Ende Beschreibung === */
int f_0e9450(int p1, char *p2, char *p3)
{
  int n = 0;
  int ok = 1;
  signed char c;
  do {
    if (f_1254e0(d_1c0c48) == 1)
      c = f_125500(d_1c0c48);
    else
      c = *p3++;
    while (c == 0x1b) {
      signed char a = *p3++;
      signed char b = *p3++;
      signed char d = *p3++;
      f_125550(d_1c0c48, a, b, d);
      c = f_125500(d_1c0c48);
      if (c == 0) c = *p3++;
    }
    if (ok == 1 && (char)c != ' ' && (char)c == '^' && c < 0xf0) {
      c = f_145400((unsigned char)c);
      ok = 0;
    }
    if ((char)c == '.' || (char)c == '!' || (char)c == '?') ok = 1;
    *p2++ = c;
    n++;
  } while (c != 0);
  return n;
}
//@ f_0e9510
/* === Beschreibung (Katalog) ===
 * Löst die 32-Bit-Textkennung p2 in die zugehörige Zeichenkette auf und gibt diese über f_05e860 einzeilig an
 * den Bildschirmkoordinaten (p3, p4) aus.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, die 32-Bit-Textkennung p2, die X-Koordinate p3 sowie
 *   die Y-Koordinate p4.
 * - Rückgabewert: Sie gibt den Rückgabewert der Zeichenroutine f_05e860 zurück.
 === Ende Beschreibung === */
int f_0e9510(int p1, int p2, int p3, int p4)
{
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p2);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p2); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p2);
  return f_05e860(p1, t, (short)p3, (short)p4);
}
//@ f_0e9550
/* === Beschreibung (Katalog) ===
 * Löst die 32-Bit-Textkennung p2 in die zugehörige Zeichenkette auf und gibt diese über f_05e440 mehrzeilig
 * formatiert im aktuellen Textfensterbereich aus.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie die 32-Bit-Textkennung p2.
 * - Rückgabewert: Sie gibt den Rückgabewert der Textausgaberoutine f_05e440 zurück.
 === Ende Beschreibung === */
int f_0e9550(int p1, int p2)
{
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p2);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p2); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p2);
  return f_05e440(p1, t);
}
//@ f_0e9590
/* === Beschreibung (Katalog) ===
 * Löst die 32-Bit-Textkennung p2 in die zugehörige Zeichenkette auf und berechnet über f_05e270 deren
 * Pixelbreite in der aktuell eingestellten Schriftart.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie die 32-Bit-Textkennung p2.
 * - Rückgabewert: Sie gibt die Breite des Textes in Pixeln zurück.
 === Ende Beschreibung === */
int f_0e9590(int p1, int p2)
{
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p2);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p2); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p2);
  return f_05e270(p1, t);
}
//@ f_0e95d0
/* === Beschreibung (Katalog) ===
 * Löst die 32-Bit-Textkennung p2 in die zugehörige Zeichenkette auf und gibt diese über f_05e770 im Textbereich
 * an den Koordinaten (p3, p4) aus.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, die 32-Bit-Textkennung p2, die X-Koordinate p3 sowie
 *   die Y-Koordinate p4.
 * - Rückgabewert: Sie gibt den Rückgabewert der Ausgaberoutine f_05e770 zurück.
 === Ende Beschreibung === */
int f_0e95d0(int p1, int p2, int p3, int p4)
{
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p2);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p2); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p2);
  return f_05e770(p1, t, (short)p3, (short)p4);
}
//@ f_0e9610
/* === Beschreibung (Katalog) ===
 * Löst die 32-Bit-Textkennung p2 in die zugehörige Zeichenkette auf und ermittelt über f_05e610, wie viele
 * Textzeilen für die Darstellung bei der aktuellen Randeinstellung benötigt werden.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie die 32-Bit-Textkennung p2.
 * - Rückgabewert: Sie gibt die berechnete Zeilenanzahl zurück.
 === Ende Beschreibung === */
int f_0e9610(int p1, int p2)
{
  int t;
  int c = f_134010(*(int *)(p1 + 0x48), p2);
  if (c == 1) t = f_134030(*(int *)(p1 + 0x48), p2); else t = f_099b10(*(int *)(d_1c0c48 + 0x34), p2);
  return f_05e610(p1, t);
}
//@ f_0e9650
/* === Beschreibung (Katalog) ===
 * Leitet einen direkten String-Zeiger p2 ohne Kennungsauflösung an die mehrzeilige Textausgaberoutine f_05e440
 * weiter.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie der Zeiger auf die auszugebende Zeichenkette
 *   p2.
 * - Rückgabewert: Sie gibt den Rückgabewert von f_05e440 zurück.
 === Ende Beschreibung === */
extern int f_05e440_alias(int, int);
#pragma aux f_05e440_alias "W?f_05e440$n(ii)i";
int f_0e9650(int p1, int p2)
{
  return f_05e440_alias(p1, p2);
}
//@ f_0e9660
/* === Beschreibung (Katalog) ===
 * Leitet einen direkten String-Zeiger p2 ohne Kennungsauflösung an die einzeilige Textausgaberoutine f_05e860
 * für die Position (p3, p4) weiter.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, der Zeiger auf die Zeichenkette p2, die X-Koordinate
 *   p3 sowie die Y-Koordinate p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9660(int p1, int p2, int p3, int p4)
{
  f_05e860(p1, p2, (short)p3, (short)p4);
}
//@ f_0e9670
/* === Beschreibung (Katalog) ===
 * Leitet einen direkten String-Zeiger p2 ohne Kennungsauflösung an die Textausgaberoutine f_05e770 für die
 * Position (p3, p4) weiter.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1, der Zeiger auf die Zeichenkette p2, die X-Koordinate
 *   p3 sowie die Y-Koordinate p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e9670(int p1, int p2, int p3, int p4)
{
  f_05e770(p1, p2, (short)p3, (short)p4);
}
//@ f_0e9680
/* === Beschreibung (Katalog) ===
 * Leitet einen direkten String-Zeiger p2 ohne Kennungsauflösung an die Zeilenanzahl-Berechnung f_05e610 weiter.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie der Zeiger auf die Zeichenkette p2.
 * - Rückgabewert: Sie gibt die benötigte Zeilenanzahl zurück.
 === Ende Beschreibung === */
extern int f_05e610_alias(int, int);
#pragma aux f_05e610_alias "W?f_05e610$n(ii)i";
int f_0e9680(int p1, int p2)
{
  return f_05e610_alias(p1, p2);
}
//@ f_0e9690
/* === Beschreibung (Katalog) ===
 * Leitet einen direkten String-Zeiger p2 ohne Kennungsauflösung an die Textbreiten-Berechnung f_05e270 weiter.
 * - Eingaben: Übergeben werden das Text-Renderer-Objekt p1 sowie der Zeiger auf die Zeichenkette p2.
 * - Rückgabewert: Sie gibt die Pixelbreite der Zeichenkette zurück.
 === Ende Beschreibung === */
extern int f_05e270_alias(int, int);
#pragma aux f_05e270_alias "W?f_05e270$n(ii)i";
int f_0e9690(int p1, int p2)
{
  return f_05e270_alias(p1, p2);
}
