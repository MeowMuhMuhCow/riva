/* === Beschreibung (Katalog) ===
 * Einheit cmask5 (04ee60 - 04f160)
 *
 * Überblick
 * Diese Einheit (cmask5.cpp) zeichnet die Zauber-Übersichtsseite (Reiter 5) des Heldenbogens in einem
 * dreispaltigen Layout. Sie gibt die Überschriften der sieben im Heldenbogen dargestellten Zaubergruppen sowie
 * sämtliche zugehörigen Zaubersprüche samt ihren aktuellen Spruchwerten und farblichen Steigerungsmarkierungen
 * aus.
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 26.10.2026, Basis cmask5_P1.CPP)
// cmask5.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04EE60-0x04F160
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_036ed0(int p1);                                 // reg eax stapel 0
int f_03ad80(int p1, int p2);                           // reg eax edx stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09a040(int p1);                                   // reg eax stapel 0 (SICHERT)
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#pragma aux f_09a040 parm [eax] modify exact [eax]
int f_0e9690(int p1, int p2);
#pragma aux f_0e9690 parm [eax edx] modify exact [eax edx]
int f_14572e(char *, const char *, ...);
struct O { char pad[11]; int f; };
struct S7 { char a[7]; };
struct S42 { short a[21]; };
extern S7 d_1a13ac;
extern S42 d_1a13b4;
extern signed char *d_1bc89c;
extern signed char d_1a6ba0[];
//@ f_04ee60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet eine einzelne Zauberzeile (Spruchname linksbündig und aktueller Zauberwert
 *   rechtsbündig) auf der Zauber-Übersichtsseite des Heldenbogens und färbt den Wert je nach bereits erfolgter
 *   oder ausgeschöpfter Steigerung beim Stufenaufstieg um.
 * - Eingaben und Rückgabe: Die Funktion erhält das Heldenbogen-Objekt p1, den Zauberindex p2, den Startindex der
 *   Gruppe p3, die linke Spaltenkoordinate p4, die rechte Spaltenkoordinate p5 sowie die obere Y-Startkoordinate
 *   p6 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle d_1bc89c verzeichnet die im aktuellen Stufenaufstieg bereits durchgeführten
 *   Steigerungsversuche je Zauber (sodass der Wert über f_09a040 in Rot 0xfd, Gelb 0xfc oder Weiß 0xff
 *   eingefärbt wird), und f_03ad80(p1->f, p2) liefert den aktuellen Zauberwert des Helden.
 === Ende Beschreibung === */
void f_04ee60(O *p1, int p2, int p3, short p4, int p5, int p6)
{
  char buf[12]; S7 fmt; signed char c; int delta; int rowbase;
  signed char *q;
  c = f_09a040(0xff);
  fmt = d_1a13ac;
  delta = p2 - p3;
  f_0e9510((int)&d_1c38b0, *(short *)&p2 + 0x2000005c, (short)p4, (short)(delta * 7 + p6));
  q = (signed char *)((short)p2 * 2);
  if ((q + (int)d_1bc89c)[1] >= f_036ed0((short)p2) || *(q = d_1bc89c + (int)q) == 3)
    c = f_09a040(0xfd);
  else if (q[1] != 0)
    c = f_09a040(0xfc);
  rowbase=delta;
  f_14572e(buf, (char *)&fmt, c, (signed char)f_03ad80(p1->f, (short)p2), f_09a040(0xff) & 0xff);
  f_0e9660((int)&d_1c38b0, (int)buf, (short)(p5 - f_0e9690((int)&d_1c38b0, (int)buf)), (short)(rowbase*7+p6));
}
//@ f_04ef70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet auf dem fünften Reiter des Heldenbogens die sieben Gruppenüberschriften (0x20000090
 *   bis 0x20000096) und durchläuft anschließend alle sieben Zaubergruppen, um deren Sprüche über f_04ee60
 *   spaltenweise auszugeben.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p1 entgegen und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle d_1a13b4 enthält für jede der 7 Gruppen die Spalten- und Zeilenkoordinaten
 *   (a, b, c), während d_1a6ba0 jeweils den ersten Zauberindex und die Anzahl der Sprüche pro Gruppe angibt.
 === Ende Beschreibung === */
void f_04ef70(O *p1)
{
  struct Entry { short a, b, c; };
  S42 t;
  short i, j;
  t = d_1a13b4;
  f_05e320((int)&d_1c38b0, 0xf9, -1);
  i = f_0e95d0((int)&d_1c38b0, 0x20000090, 5, 100);
  f_0e9510((int)&d_1c38b0, 0x20000090, i, 0x28);
  i = f_0e95d0((int)&d_1c38b0, 0x20000094, 0x6e, 100);
  f_0e9510((int)&d_1c38b0, 0x20000094, i, 0x28);
  i = f_0e95d0((int)&d_1c38b0, 0x20000091, 5, 100);
  f_0e9510((int)&d_1c38b0, 0x20000091, i, 0x73);
  i = f_0e95d0((int)&d_1c38b0, 0x20000095, 0xd7, 100);
  f_0e9510((int)&d_1c38b0, 0x20000095, i, 0x73);
  i = f_0e95d0((int)&d_1c38b0, 0x20000093, 0xd7, 100);
  f_0e9510((int)&d_1c38b0, 0x20000093, i, 0x28);
  i = f_0e95d0((int)&d_1c38b0, 0x20000092, 0x6e, 100);
  f_0e9510((int)&d_1c38b0, 0x20000092, i, 0x73);
  i = f_0e95d0((int)&d_1c38b0, 0x20000096, 0xd7, 100);
  f_0e9510((int)&d_1c38b0, 0x20000096, i, 0xaa);
  f_05e320((int)&d_1c38b0, 0xff, -1);
  for (i = 0; i < 7; i++) {
    for (j = d_1a6ba0[i * 2]; j < d_1a6ba0[i * 2 + 1] + d_1a6ba0[i * 2]; j++)
      f_04ee60(p1, j, d_1a6ba0[i * 2], ((Entry *)&t)[i].a, ((Entry *)&t)[i].b, ((Entry *)&t)[i].c);
  }
}
