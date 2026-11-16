/* === Beschreibung (Katalog) ===
 * Einheit use_t5 (0x13A550 - 0x13AA40)
 *
 * Überblick
 * Diese Einheit bildet den fünften und letzten Teil von use.cpp und enthält die Hilfsfunktionen für den
 * *Schlüsselbund* (Auswahlmenüs zum Anhängen und Abnehmen von Schlüsseln, Gewichtsanpassung sowie die grafische
 * Aktualisierung des Schlüsselbund-Symbols je nach Anzahl der daran befestigten Schlüssel).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 4/8 gleich (suche.py 29.10.2026, Basis use_t5_P1.CPP)
// use.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x135040-0x13AA40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_03d860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0458b0(int p1);                                   // reg eax stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068960();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_08ab50();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a080(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce710(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10cba0(int p1, int p2);                           // reg eax edx stapel 0
int f_10cbc0(int p1, int p2);                           // reg - stapel 0
int f_10ce80();                       // nicht in clobber.tsv
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a68f4;                    // 0x1A68F4
extern short d_1a92d0;                  // 0x1A92D0
extern short d_1a92f4;                  // 0x1A92F4
extern short d_1a9316;                  // 0x1A9316
extern int d_1a934a;                    // 0x1A934A
extern int d_1a935a;                    // 0x1A935A
extern int d_1a936c;                    // 0x1A936C
extern int d_1a9370;                    // 0x1A9370
extern int d_1a9374;                    // 0x1A9374
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd90c;                    // 0x1BD90C
extern int d_1bf4bc;                    // 0x1BF4BC
extern int d_1bf4be;                    // 0x1BF4BE
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0420;                    // 0x1C0420
extern int d_1c042a;                    // 0x1C042A
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c0e7c;                    // 0x1C0E7C
extern int d_1c0e80;                    // 0x1C0E80
extern int d_1c0e84;                    // 0x1C0E84
extern int d_1c0e88;                    // 0x1C0E88
extern int d_1c106c;                    // 0x1C106C
extern int d_1c106d;                    // 0x1C106D
extern int d_1c1070;                    // 0x1C1070
extern int d_1c1071;                    // 0x1C1071
extern int d_1c1074;                    // 0x1C1074
extern int d_1c1075;                    // 0x1C1075
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c2198;                    // 0x1C2198
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c259c;                    // 0x1C259C
extern short d_1c25fe;                  // 0x1C25FE
extern int d_1c2600;                    // 0x1C2600
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3068;                    // 0x1C3068
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a8e28[];           // Text 0x1A8E28

extern short d_1a933c[];
extern char d_1c21b4[];

extern int d_1c2c64;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
int f_0bf820(int, ...);
#define CH ((int)&d_1c2c64)
short f_13a9c0(int p1, int p2, int *p3, int p4);
void f_13a8c0(int p1, short p2);

//@ f_13a550
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt alle aktuell am *Schlüsselbund* (Slot p2) befestigten Schlüssel (f_03d860 für die 7
 *   möglichen Schlüssel in d_1a933c) für ein Auswahlmenü (0x1e0100c2) zusammen und lässt den Spieler über
 *   f_13a9c0 auswählen, welchen Schlüssel er vom Bund abnehmen möchte.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Inventarslot des Schlüsselbunds (p2).
 * - Rückgabewert: Gibt die Gegenstandskennung (r aus d_1a933c) des gewählten Schlüssels oder -1 zurück, wenn der
 *   Schlüsselbund leer ist oder abgebrochen wurde.
 * - Wichtige Variablen: arr speichert die formatierten Schlüsselnamen, c die zugehörigen Indizes (0 bis 6) in
 *   d_1a933c und n die Anzahl der am Bund hängenden Schlüssel.
 === Ende Beschreibung === */
short f_13a550(int p1, short p2)
{
  int arr[7];
  signed char c[8];
  short n;
  short r;
  n = 0;
  r = -1;
  for (short i = 0; i < (short)7; i++) {
    int ii = i;
    if (f_03d860(*(int *)(p1 + 0x10), p2, ii)) {
      short k = n;
      f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[d_1a933c[ii]]),(char *)( (int)d_1c21b4 + k * 0x32), 1);
      arr[k] = f_133fe0((int)d_1c3498, (int)d_1c21b4 + k * 0x32);
      c[k] = (signed char)i;
      n++;
    }
  }
  short s = f_13a9c0(p1, 0x1e0100c2, arr, n);
  if (s != -1) {
    r = d_1a933c[c[s]];
  }
  return r;
}

//@ f_13a620
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchsucht die ersten 30 Inventarslots (0 bis 29) des Helden nach losen Schlüsseln, die in
 *   der Tabelle d_1a933c verzeichnet sind, und lässt den Spieler über f_13a9c0 (0x1e0100c3) auswählen, welchen
 *   davon er an den Schlüsselbund hängen möchte.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1).
 * - Rückgabewert: Gibt den Inventarslot (r) des ausgewählten Schlüssels oder -1 zurück.
 * - Wichtige Variablen: lc durchläuft die Inventarslots 0 bis 29, arr sammelt die Namen der gefundenen Schlüssel
 *   und c deren Slotindizes.
 === Ende Beschreibung === */
short f_13a620(int p1)
{
  int arr[7];
  signed char c[8];
  short capture;
  short r;
  int found;
  short n;
  short lc;
  short s;
  int k;
  n = 0;
  r = -1;
  lc = 0;
  goto loop_test_13a620;
inner_increment_13a620:
  s = s + 1;
  if (s < (short)7) goto inner_compare_13a620;
  goto inner_done_13a620;
loop_body_13a620:
  {
    short x;
    x = ((int)(f_042a60((struct hero *)(*(int *)(p1 + 0x10)), lc)));
    found = 0;
    x = (capture = x);
    s = 0;
inner_compare_13a620:
    if ((short)x != d_1a933c[s]) goto inner_increment_13a620;
    found = 1;
inner_done_13a620:
    if (found) {
      k = n;
      f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[capture]),(char *)( (int)d_1c21b4 + k * 0x32), 1);
      arr[k] = f_133fe0((int)d_1c3498, (int)d_1c21b4 + k * 0x32);
      n = n + 1;
      c[k] = (char)lc;
    }
  }
  lc = lc + 1;
loop_test_13a620:
  if (lc < 0x1e)
    goto loop_body_13a620;
  n = f_13a9c0(p1, 0x1e0100c3, arr, n);
  if (n != -1) {
    r = (short)c[n];
  }
  return r;
}

//@ f_13a700
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht im Inventar des Helden (*(int *)(p1 + 0x10)) über f_0458b0 nach dem *Schlüsselbund*
 *   und gibt, falls der Held keinen Schlüsselbund besitzt (r == -1), die Fehlermeldung 0x1e0100c1 aus.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1).
 * - Rückgabewert: Gibt den Inventarslot des Schlüsselbunds (r) oder -1 zurück.
 * - Wichtige Variablen: r speichert das Suchergebnis von f_0458b0.
 === Ende Beschreibung === */
int f_13a700(int p1)
{
  int r;
  r = f_0458b0(*(int *)(p1 + 0x10));
  if ((short)r == -1) {
    RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(o.slots[0] + 4) = *(int *)(p1 + 0x10);
    f_0bf730(CH, 0x1e0100c1);
  }
  return r;
}

//@ f_13a760
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt einen einzelnen Schlüssel aus dem Inventarslot p3 an den *Schlüsselbund* in Slot p2:
 *   Das entsprechende Schlüssel-Bit wird am Schlüsselbund gesetzt (f_03d8b0), das Schlüsselbund-Symbol über
 *   f_13a8c0 aktualisiert, das Gewicht des Schlüssels zum Gesamtgewicht addiert (f_043190), der Einzelschlüssel
 *   aus Slot p3 entfernt und die Bestätigungsmeldung 0x1e0100ce angezeigt.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Slot des Schlüsselbunds (p2) und der Slot des
 *   anzuhängenden Schlüssels (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: s1 enthält zunächst die Gegenstandskennung und danach das Gewicht des Schlüssels; s2 ist
 *   sein Index (0-6) in d_1a933c.
 === Ende Beschreibung === */
union Home900 { int full; short low; }; // haelt Parameter p2 in einem Stapelslot
#pragma aux f_13a760 parm [eax] [edx] [ebx];
void f_13a760(int p1, Home900 p2, int p3)
{
  short f_13aa20(int, short);
  void f_13a8c0(int,int);
  int saved_slot; *(int *)&saved_slot = p3; // haelt saved_slot ohne volatile auf dem Stapel
  short s1;
  short s2;
  int one = 1;
  s1 = ((int)(f_042a60((struct hero *)(*(int *)(p1 + 0x10)), (short)p3)));
  s2 = f_13aa20(p1, s1);
  int target = *(short *)&p2; // haelt die Stapelheimat von p2 und die Registerfolge wie im Original
  f_03d8b0(*(int *)(p1 + 0x10), target, s2, one);
  f_13a8c0(p1, target);
  s1 = ((int)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[s1]))->f_0a7810()));
  f_043190((struct hero *)(*(int *)(p1 + 0x10)), s1);
  f_036300(*(int *)(p1 + 0x10), (short)saved_slot, 1);
  f_0bf730(CH, 0x1e0100ce);
}

//@ f_13a800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Nimmt den Schlüssel mit der Gegenstandskennung b vom *Schlüsselbund* in Slot a ab: Das
 *   Schlüssel-Bit am Bund wird gelöscht (f_03d8b0), das Symbol des Schlüsselbunds über f_13a8c0 aktualisiert,
 *   das Gewicht um das Schlüsselgewicht reduziert (f_043190) und der Schlüssel in das Inventar des Helden (oder
 *   bei vollem Inventar eines Gruppenmitglieds f_0dcf00) gelegt.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p), der Slot des Schlüsselbunds (a) sowie die
 *   Gegenstandskennung des abzunehmenden Schlüssels (b).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: i ermittelt den Index des Schlüssels b in der Tabelle d_1a933c.
 === Ende Beschreibung === */
void f_13a800(int p, short a, short b)
{
    short key = b;
    int z = 0;
    short i;
    i = 0;
    while (d_1a933c[i] != key) i++;
    f_03d8b0(*(int *)(p + 0x10), a, i, z);
    f_13a8c0(p, a);
    f_043190((struct hero *)(*(int *)(p + 0x10)), (short)-((int)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[b]))->f_0a7810())));
    if (f_0366e0(*(int *)(p + 0x10), b, 0, 1) == -1)
        f_0dcf00(d_1c0004, b, 1);
    else
        f_0bf730(CH, 0x1e0100cf);
}

//@ f_13a8c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zählt, wie viele der sieben möglichen Schlüssel aktuell am *Schlüsselbund* in Slot p2
 *   befestigt sind (n = 0..7), und ändert die Gegenstandskennung des Schlüsselbunds entsprechend (0x145 für 0
 *   Schlüssel, 0x19d bis 0x1a1 für 1 bis 5 Schlüssel, 0x1cf für 6 Schlüssel und 0x1d0 für 7 Schlüssel), damit im
 *   Inventar das passende Schlüsselbund-Icon angezeigt wird.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Inventarslot des Schlüsselbunds (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: n summiert die gesetzten Schlüssel-Flags (f_03d860) für i = 0..6.
 === Ende Beschreibung === */
void f_13a8c0(int p1, short p2)
{
  short n;
  short i;
  n = 0;
  for (i = 0; i < (short)7; i++) {
    if (f_03d860(*(int *)(p1 + 0x10), (short)p2, i)) {
      n = n + 1;
    }
  }
  switch (n) {
  case 0: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x145); return;
  case 1: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x19d); return;
  case 2: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x19e); return;
  case 3: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x19f); return;
  case 4: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x1a0); return;
  case 5: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x1a1); return;
  case 6: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x1cf); return;
  case 7: f_042a90((struct hero *)(*(int *)(p1 + 0x10)), (short)p2, 0x1d0); return;
  default: return;
  }
}

//@ f_13a9c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt bei mehr als einem zur Auswahl stehenden Schlüssel (p4 > 1) ein Auswahlmenü (f_0bf820)
 *   mit den Namen aus p3 an und gibt bei genau einem Schlüssel (p4 == 1) sofort den Index 0 ohne Rückfrage
 *   zurück.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1), die Überschrifts-Textkennung (p2), das Array der
 *   Schlüsselnamen (p3) sowie die Anzahl der Einträge (p4).
 * - Rückgabewert: Gibt den 0-basierten Index (result) des gewählten Schlüssels oder -1 zurück.
 * - Wichtige Variablen: result enthält die um 1 reduzierte Rückgabe des Auswahldialogs.
 === Ende Beschreibung === */
short f_13a9c0(int p1, int p2, int *p3, int p4)
{
  short result;
  result = -1;
  if ((short)p4 == 1) {
    return 0;
  }
  if ((short)p4 > 1) {
    p3 = (int *)f_0bf820(CH, p2, (short)p4, p3[0], p3[1], p3[2], p3[3], p3[4], p3[5], p3[6], p3[7], p3[8], p3[9]);
    result = (short)(int)p3;
    if (result != -1) {
      result = result - 1;
    }
  }
  return result;
}

//@ f_13aa20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht den Tabellenindex (0 bis 6) einer Schlüssel-Gegenstandskennung (p2) in der
 *   Schlüsseltabelle d_1a933c.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die Gegenstandskennung des Schlüssels (p2).
 * - Rückgabewert: Gibt den gefundenen Index (s) in d_1a933c zurück.
 * - Wichtige Variablen: s läuft von 0 aufwärts bis zum Treffer p2 == d_1a933c[s].
 === Ende Beschreibung === */
short f_13aa20(int p1, short p2)
{
  short s;
  s = 0;
  while (p2 != d_1a933c[s]) {
    s = s + 1;
  }
  return s;
}
