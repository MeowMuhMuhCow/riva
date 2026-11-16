/* === Beschreibung (Katalog) ===
 * Einheit char_opt (0x03f2a0 - 0x040280)
 *
 * Überblick
 * Diese Einheit implementiert die Charakterverwaltung im Tempel bzw. in der Helden-Verwaltungsstätte (in
 * *Schicksalsklinge* und *Sternenschweif* vergleichbar mit den Tempel-Funktionen zum Aufnehmen, Entlassen,
 * Löschen und Generieren von Helden). Der Spieler kann hier gespeicherte Helden aus den Charakterarchiven
 * (0x90001 und 0x90002) in die Gruppe aufnehmen (f_03f7b0, f_03fc00), Gruppenmitglieder im Tempel zurücklassen
 * (f_03f890), gespeicherte Charaktere von der Festplatte löschen (f_03f9a0, f_03fa80) oder den
 * Charaktergenerator starten (f_03fa30).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
#include "R_FIX.H"
// P3 8/12 gleich (suche.py 26.10.2026, Basis char_opt_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 2 gleich (vorher 2), Rest 637 (vorher 656)
// char_opt.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03F2A0-0x040280
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01c000(int p1);                                   // reg eax stapel 0
int f_01c120(int p1, int p2);                           // reg eax edx stapel 0
int f_01d160(int p1, int p2);                           // reg eax edx stapel 0
int f_01dfc0(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
short f_040400(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_040550();                                         // reg - stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
int f_092f40(int p1);                                   // reg eax stapel 0
int f_0934f0(int p1, int p2);
int f_093bb0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
short f_0b0790(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0b09b0(int p1);                                   // reg eax stapel 0
short f_0b0e60(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0bbe40(int p1, int p2);                           // reg edx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d5780(int p1);
int f_0d64a0();                       // nicht in clobber.tsv
int f_0da910(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_0da990(int p1, int);                                   // reg eax stapel 0
int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_0dacc0(int p1);                                   // reg eax stapel 0
short f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
short f_0dc650(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0de7f0(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0

   // reg eax edx ebx ecx stapel 4
int f_125400(int p1, int p2, int p3);
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0

int f_149eb4(int p1, int p2, int p3);
#pragma aux f_149eb4 parm caller [] modify [eax ebx ecx edx];
extern short d_1bb244;
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a539c;                    // 0x1A539C
extern int d_1bc760;                    // 0x1BC760
extern int d_1bc8c8;                    // 0x1BC8C8
extern int d_1bc8f0;                    // 0x1BC8F0
extern int d_1bf230;                    // 0x1BF230
extern short d_1bf510;                    // 0x1BF510
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern unsigned char d_1c002c;                    // 0x1C002C
                    // 0x1C2098
extern volatile short d_1c2198;                    // 0x1C2198
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a0d24[];           // Text 0x1A0D24
extern int d_1a0d44;
struct T9 { char c[9]; };
struct T42 { char c[0x42]; };
struct T5ef { char c[0x5ef]; };
struct Tcf { char c[0xcf]; };
struct T11f { char c[0x11f]; };
// --- eigene Funktionen (12), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

void f_03f7b0(int p1);
void f_03f890(int p1);
short f_03fdf0(int p1);
void f_03fa80(int p1, int p2);
int f_03fc00(int p1, int p2, int p3);
struct MG { int f; MG() { if (f_0d3860() == 1) { f_0d2710(); f = 1; } else f = 0; } ~MG() { if (f == 1) f_0d26e0(); } };
//@ f_03f2a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zeichnet die Porträts und Statusbalken aller aktiven Helden (sowohl der
 *   aktuellen Hauptgruppe d_1c0004 als auch etwaiger abgespaltener Teilgruppen in d_1bfdbc) in die untere
 *   Charakterleiste des Ziel-Bildschirmpuffers p1.
 * - Eingaben und Rückgabe: Die Funktion erhält die Adresse des Ziel-Bildschirmpuffers p1 und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Über f_0dc650 werden nacheinander die Helden der Hauptgruppe d_1c0004 und der bis zu
 *   sechs Gruppen-Slots ab d_1bfdbc (Stride 0x61) in das temporäre Leisten-Grafikobjekt p (320x44 Pixel)
 *   gezeichnet und per f_0fae30 bei Y-Koordinate 0x9c (156) ausgegeben.
 === Ende Beschreibung === */
void f_03f2a0(int p1)
{
  T9 *p = new (mark(d_1a0d24, 0x44)) T9;
  p = p ? (T9 *)((int)(((RivaRasterImage*)((int)p))->f_0fac80( 0x140, 0x2c))) : p;
  int q;
  f_0bbe40((int)&d_1bf230, (int)p);
  q = (int)&d_1bfdbc;
  short s1 = f_0dc650(d_1c0004, 0, (int)p);
  for (short i = 0; i < 6; i++, q += 0x61) {
    if (q != d_1c0004) {
      short s2 = f_0de7f0(q);
      if (s2) s1 = f_0dc650(q, (short)s1, (int)p);
    }
  }
  MG c;
  ((RivaRasterImage*)((int)p))->f_0fae30((void *)( p1), 0, 0x9c, 1);
  if (p != 0) {
    operator delete((void *)((int)(((RivaRasterImage*)((int)p))->f_0fad20( 0))));
  }
}
//@ f_03f390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dieser Konstruktor initialisiert das 14 Byte große Zustandsobjekt p1 des
 *   Charakterverwaltungs-Menüs mit der aktuellen Tempel-/Ortskennung p2 und setzt die Zeigerfelder auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und die Ortskennung p2 (short) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: *(short *)p1 speichert die Tempelkennung (bzw. -1 für ortsunabhängigen Zugriff), *(int
 *   *)(p1 + 2) den Zeiger auf die geladene Heldenliste, *(int *)(p1 + 6) das Hintergrundbild und *(int *)(p1 +
 *   10) den Palettenpuffer.
 === Ende Beschreibung === */
void f_03f390(int p1, int p2)
{
  *(int *)(p1 + 2) = 0;
  *(int *)(p1 + 6) = 0;
  *(int *)(p1 + 10) = 0;
  *(short *)p1 = (short)p2;
}
//@ f_03f3b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion baut den kompletten Bildschirm der Charakterverwaltung in einem
 *   64000-Byte-Hintergrundpuffer auf (Hintergrundgrafik, Charakterleiste via f_03f2a0, Menü-Icons via f_0daba0
 *   und Animations-Overlay d_1bc760), kopiert das fertige Bild in den Bildschirmpuffer d_1a34e0 und blendet die
 *   Palette p2 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Hintergrund-Grafikhandle p1 und den Palettenzeiger p2 und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: d_1c2198 (das globale Neuzeichnungs-Flag) wird zu Beginn auf 0 zurückgesetzt.
 === Ende Beschreibung === */
void f_03f3b0(int p1, int p2)
{
  char *buf;
  int t;
  buf = new (mark(d_1a0d24, 0x6f)) char[64000];
  d_1c2198 = 0;
  MG fl;
  *(volatile int *)&d_1bf510 = (int)&d_1a539c; // Haelt die Speicherschreibreihenfolge wie im Original
  f_09ade0((int)buf, d_1a0d44, 0);
  f_03f2a0((int)buf);
  if (d_1bc8c8) {
    f_0daba0(d_1bc8c8, d_1a34e0);
  }
  if (d_1bc760 == 0) {
    t = (int)new (mark(d_1a0d24, 0x7f)) Tcf;
    t = t ? f_01c000(t) : t;
    f_01d160(d_1bc760 = t, p1);
    f_01c120(d_1bc760, 3);
  }
  memcpy((void *)d_1a34e0, buf, 64000);
  f_09a120(p2, 0x19);
  delete buf;
}
struct SV { short s; SV(); ~SV(); };
struct T3 { char c[3]; T3(); };
#define MGB(g) MG g;
#define MGE(g)
#define G2198 (d_1c2198)
unsigned f_03fbd0();
//@ f_03f4d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt die Haupt-Ereignisschleife des Charakterverwaltungs-Bildschirms aus. Sie
 *   legt die Klickzonen-Maske (d_1bc8c8) an, zeichnet den Bildschirm und verarbeitet die vier Menüaktionen:
 *   Helden in die Gruppe aufnehmen (0xa0 -> f_03f7b0), Helden aus der Gruppe entlassen (0xa1 -> f_03f890),
 *   gespeicherte Helden löschen (0xa2 -> f_03fa80) und neuen Charakter erschaffen (0xa3 -> Charaktergenerator
 *   f_092f40/f_093bb0), bis der Spieler den Raum verlässt (0x80).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Verwaltungs-Zustandsobjekt und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Die Archivgrößen von 0x40090001 (vorgefertigte Helden) und 0x40090002 (eigene
 *   gespeicherte Helden) werden durch die Datensatzgröße 0x5ef (1519 Bytes pro Held) geteilt, um die maximale
 *   Anzahl gespeicherter Charaktere zu bestimmen.
 === Ende Beschreibung === */
void f_03f4d0(int p1)
{
  int sxax(short);
  #pragma aux sxax = "" parm [eax] value [eax] modify exact [eax]
  SV sv;
  int uv;
  short key;
  uv = d_1c2a80;
  {
    T42 *p = new (mark(d_1a0d24, 0x9b)) T42;
    d_1bc8c8 = (p != 0) ? f_0da910((int)p, 0x280000, 0x280001, 0x280002, 0x280003, d_1bb244, 0x15) : (int)p;
  }
  *(int *)(p1 + 10) = (int)(new (mark(d_1a0d24, 0xa1)) T3[256]);
  *(int *)(p1 + 6) = f_01dfc0(d_1bc760);
  G2198 = 0;
  f_149eb4(*(int *)(p1 + 10), 0, 0x100);
  {
    MGB(g1)
    f_0daba0(d_1bc8c8, d_1a34e0);
    f_09ac80(d_1a34e0, d_1a0d44, 0);
    MGE(g1)
  }
  do {
    f_069460();
    if (G2198 == 1) {
      MGB(g2)
      d_1c2a80 = uv;
      f_03f3b0(*(int *)(p1 + 6), *(int *)(p1 + 10));
      MGE(g2)
    }
    f_0d5780((int)&d_1bf230);
    key = f_0dacc0(d_1bc8c8);
    switch (key) {
    case 0:
      break;
    case 0xa0:
      f_03f7b0(p1);
      break;
    case 0xa1:
      f_03f890(p1);
      break;
    case 0xa2: {
      int a = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090001)));
      int b = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090002)));
      int n;
      if (!sxax((short)(n = (unsigned)(b + a) / 0x5ef))) {
        f_0bf730((int)&d_1c2c64, 0x1c000007);
      } else {
        *(int *)(p1 + 2) = (int)(new (mark(d_1a0d24, 0x153)) char[(short)n * 0x26]);
        f_03fa80(p1, (int)f_03fdf0(p1));
        operator delete((void *)*(int *)(p1 + 2));
        *(int *)(p1 + 2) = 0;
      }
      break;
    }
    case 0xa3: {
      int t = (int)new (mark(d_1a0d24, 0x168)) T11f;
      t = (t != 0) ? f_092f40(t) : t;
      f_093bb0(t);
      if (t != 0) {
        t = f_0934f0(t, 0);
        operator delete((void *)t);
      }
      f_09a140(0, 0x19);
      break;
    }
    }
  } while (key != 0x80);
  f_09aed0(d_1a0d44);
  {
    int q = d_1bc8c8;
    if (q != 0) {
      operator delete((void *)f_0da990(q, 0));
    }
  }
  operator delete((void *)*(int *)(p1 + 10));
}

//@ f_03f7b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion bereitet die Menüaktion "Helden in die Gruppe aufnehmen" (0xa0) vor. Sie prüft,
 *   ob überhaupt gespeicherte Helden in den Archiven existieren und wie viele der sechs regulären Plätze in
 *   d_1bc8f0 noch frei sind (k), lädt die Liste der verfügbaren Charaktere über f_03fdf0 und startet die
 *   Auswahlschleife f_03fc00.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1 und hat keinen Rückgabewert.
 * - Wichtige Variablen: Ist die Gruppe mit sechs regulären Helden bereits voll (k == 0), zeigt die Funktion die
 *   Fehlermeldung 0x1c000002 an.
 === Ende Beschreibung === */
void f_03f7b0(int p1)
{
  char c;
  short len, n, k, i;
  int a, b, q;
  a = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090001)));
  b = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090002)));
  len = (short)((unsigned)(b + a) / 0x5ef);
  if ((short)len == 0) {
    f_0bf730((int)&d_1c2c64, 0x1c000003);
    return;
  }
  k = 6;
  *(int *)(p1 + 2) = (int)(new (mark(d_1a0d24, 0xed)) char[(short)len * 0x26u]);
  n = f_03fdf0(p1);
  q = d_1bc8f0;
  for (i = 0; i < 6; i++, q += 0x5ef) {
    c = ((char)(f_042350((struct hero *)(q))));
    if (c) {
      k--;
    }
  }
  if (k == 0) {
    f_0bf730((int)&d_1c2c64, 0x1c000002);
  } else {
    f_03fc00(p1, (int)n, (int)k);
  }
  operator delete((void *)*(int *)(p1 + 2));
  *(int *)(p1 + 2) = 0;
}
//@ f_03f890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wickelt die Menüaktion "Helden aus der Gruppe entlassen" (0xa1) ab. Solange
 *   noch mehr als ein regulärer Held in der Hauptgruppe d_1c0004 verbleibt, lässt sie den Spieler einen Helden
 *   auswählen und speichert diesen entweder am aktuellen Tempelort (f_0dcd30) ab oder entlässt ihn als NPC
 *   (f_0d64a0). Bleibt am Ende nur noch ein einziger regulärer Held zusammen mit einem NPC übrig, wird der NPC
 *   ebenfalls automatisch verabschiedet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: a = (f_039040(d_1c0004) != 0) stellt sicher, dass ein angeschlossener NPC nicht als
 *   einziger verbleibender "Held" der Gruppe gezählt wird.
 === Ende Beschreibung === */
void f_03f890(int p1)
{
  int a, b;
  if (f_0de7f0(d_1c0004) == (short)0) {
    f_0bf730((int)&d_1c2c64, 0x1c000001);
  } else {
    a = f_039040(d_1c0004) != 0;
    do {
      b = f_038e90(d_1c0004, 0x1c000004);
      f_069460();
      if (b != 0) {
        f_0d2f90(5, 1);
        if (((char)(f_042400((struct hero *)(b))))) {
          f_0d64a0();
#if FIX_R053   /* R053: Nach Entlassung des NPCs Flag a aktualisieren, damit die Schleifenbedingung stimmt */
          a = f_039040(d_1c0004) != 0;
#endif
        } else {
          f_0dcd30(d_1c0004, (int)f_0dc020(d_1c0004, b), (int)*(short *)p1);
        }
        f_0bbf00((int)&d_1bf230);
        f_0d2e70();
      }
      if (b == 0) break;
    } while (f_0de7f0(d_1c0004) > (short)a);
  }
  if (f_0de7f0(d_1c0004) != (short)0) {
    a = f_039040(d_1c0004);
    b = f_038c80(d_1c0004);
    if (a == b) {
      f_0d64a0();
      f_0bbf00((int)&d_1bf230);
    }
  }
}
//@ f_03f9a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion bereitet die Menüaktion "Gespeicherten Charakter löschen" vor, indem sie den
 *   Listenpuffer allokiert, die verfügbaren Helden über f_03fdf0 zusammenstellt und den Löschdialog f_03fa80
 *   aufruft.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Sind keine gespeicherten Helden vorhanden (n == 0), erscheint sofort die Meldung
 *   0x1c000007.
 === Ende Beschreibung === */
void f_03f9a0(int p1)
{
  short n;
  int b, a;
  a = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090001)));
  b = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090002)));
  n = (short)((unsigned)(b + a) / 0x5ef);
  if ((short)n == 0) {
    f_0bf730((int)&d_1c2c64, 0x1c000007);
    return;
  }
  *(int *)(p1 + 2) = (int)(new (mark(d_1a0d24, 0x153)) char[(short)n * 0x26u]);
  n = f_03fdf0(p1);
  f_03fa80(p1, (int)n);
  operator delete((void *)*(int *)(p1 + 2));
  *(int *)(p1 + 2) = 0;
}
//@ f_03fa30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion instanziiert das Charaktergenerator-Objekt (T11f, 0x11f Bytes), führt die
 *   Charaktererschaffung über f_092f40 und f_093bb0 aus und räumt das Generator-Objekt danach wieder auf.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und keinen Rückgabewert.
 * - Wichtige Variablen: Nach dem Schließen des Generators blendet f_09a140(0, 0x19) den Bildschirm wieder aus.
 === Ende Beschreibung === */
void f_03fa30()
{
  int t = (int)new (mark(d_1a0d24, 0x168)) T11f;
  t = t ? f_092f40(t) : t;
  f_093bb0(t);
  if (t != 0) {
    t = f_0934f0(t, 0);
    operator delete((void *)t);
  }
  f_09a140(0, 0x19);
}
//@ f_03fa80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion lässt den Spieler in einer Schleife gespeicherte Charaktere aus der Liste *(p1
 *   + 2) auswählen und löscht den gewählten Charakter nach einer Sicherheitsabfrage (0x1c000006) sowohl aus dem
 *   Spielstandsarchiv (f_0b09b0) als auch aus der angezeigten Liste.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1 und die aktuelle Listenlänge p2
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Jeder Listeneintrag ist 0x26 (38) Bytes groß (16 Bytes Anzeigename, 16 Bytes interner
 *   Dateiname ab +0x10, 4 Bytes Archiv-ID bei +0x20 und 2 Bytes Archiv-Index bei +0x24).
 === Ende Beschreibung === */
struct MsgC { int h; char *q[14]; MsgC(void*,void*,void*); ~MsgC(); };
int f_145300(int p1, int p2, int p3);
int f_14d075(int p1, int p2, int p3);
void f_03fa80(int p1, int p2)
{
  int close172();
#pragma aux close172 "f_0d2e70" modify exact [eax edx]
  short r;
  int off = 0;
  do {
    if ((short)(*&p2) > 0) {
      r = f_040400(*(int *)((*&p1) + 2), (short)(*&p2), -1);
    } else {
      f_0bf730((int)&d_1c2c64, 0x1c000007);
      r = -1;
    }
    if (r != -1) {
      MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
      off = r * 0x26;
      {
        char *src = (char *)p1; src=*(char **)(src+2); src+=off;
        int s = (int)strcpy((char *)&d_1c21b4, src);
        ((int *)m.q[3])[1] = f_133fe0((int)&d_1c3498, s);
      }
      if (f_0bf6f0((int)&d_1c2c64, 0x1c000006) == 1) {
        f_0d2f90(5, 1);
        f_0b09b0(*(int *)((*&p1) + 2) + off + 0x10);
        if (r == (short)(*&p2) - 1) {
          f_145300(*(int *)((*&p1) + 2) + off, 0, 0x26);
        }
        else {
          int cnt = ((short)(*&p2) - r) * 0x26;
          int sp = (r + 1) * 0x26;
          int b = *(int *)((*&p1) + 2);
          f_14d075(b + off, sp + b, cnt);
        }
        {
          off = p2 - 1;
          close172();
          p2 = off;
        }
      }
    }
  } while (r != -1);
}
//@ f_03fbd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion berechnet die Gesamtzahl aller in den beiden Charakterarchiven (0x40090001
 *   und 0x40090002) vorhandenen Heldendatensätze (Größe / 0x5ef).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt die Gesamtanzahl der Heldendatensätze
 *   als unsigned zurück.
 * - Wichtige Variablen: Die Datensatzgröße eines Helden beträgt exakt 0x5ef (1519) Bytes.
 === Ende Beschreibung === */
unsigned f_03fbd0()
{
  int a, b;
  a = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090001)));
  b = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090002)));
  return (unsigned)(b + a) / 0x5ef;
}
//@ f_03fc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion lässt den Spieler in einer Schleife bis zu p3 Helden aus der vorbereiteten
 *   Kandidatenliste *(p1 + 2) auswählen, lädt den gewählten Helden über f_0b0e60 in einen freien Heldenslot (c2
 *   = f_040550()), fügt ihn über f_0dcc40 in die Hauptgruppe d_1c0004 ein und aktualisiert die Charakterleiste.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1, die Anzahl wählbarer
 *   Kandidaten p2 (short) und die Anzahl freier Gruppenplätze p3 (short) und gibt 1 zurück, falls mindestens ein
 *   Held aufgenommen wurde, sonst 0.
 * - Wichtige Variablen: Nach jeder Aufnahme wird der übernommene Eintrag über del26 aus der Kandidatenliste
 *   entfernt und p2 sowie p3 um 1 verringert.
 === Ende Beschreibung === */
void f_03f2a0(int p1);
void f_03f3b0(int p1, int p2);
int f_145300(int p1, int p2, int p3);
int f_14d075(int p1, int p2, int p3);
#define DW16 (d_1c2198)
struct E26 { char a[0x20]; int x20; short x24; };
static inline void del26(int p1, short r, short n)
{
  if (r == n - 1)
    f_145300(*(int *)(p1 + 2) + r * 0x26, 0, 0x26);
  else {
    int cnt = (n - r) * 0x26;
    int sp = (r + 1) * 0x26;
    int b = *(int *)(p1 + 2);
    f_14d075(b + r * 0x26, sp + b, cnt);
  }
}
int f_03fc00(int p1, short p2, short p3)
{
  short r = -1;
  int uv = d_1c2a80;
  int ret = 0;

  do {
    f_069460();
    if ((short)p2 == 0) {
      f_0bf730((int)&d_1c2c64, 0x1c000003);
    } else {
      r = f_040400(*(int *)(p1 + 2), (short)p2, 1);
      if (r != -1) {
        short c1 = f_0dcc10(d_1c0004);
        if (c1 != -1) {
          short c2 = f_040550();
          { char j; c2 = j - j + c2; } // Haelt die Registervergabe fuer c2 wie im Original
          if (c2 != -1) {
            f_0d2f90(5, 1);
            d_1c2198 = 0;
            signed char ch = d_1c002c;
            volatile int fl; // Haelt den Stapelplatz im Rohlisten-Schwanz wie im Original
            if (f_0b0e60(((E26 *)*(int *)(p1 + 2))[r].x20, ((E26 *)*(int *)(p1 + 2))[r].x24,
                         c2, ch) == 1) {
              int q = d_1bc8f0;
              f_0dcc40(d_1c0004, c2 * 0x5ef + q, c1);
              f_0bbf00((int)&d_1bf230);
              f_03f2a0(d_1a34e0);
              del26(p1, r, (short)p2);
              p3--;
              p2--;
              ret = 1;
              { int u_ = ret; ret = u_; } // Haelt ret im Stapelplatz wie im Original
            }
            if (d_1c2198 == 1) {
              d_1c2198 = 0;
              if (f_0d3860() == 1) {
                f_0d2710();
                fl = 1;
              } else fl = 0;
              d_1c2a80 = uv;
              f_03f3b0(*(int *)(p1 + 6), *(int *)(p1 + 0xa));
              if (fl == 1) f_0d26e0();
            }
            f_0d2e70();
          }
        }
      }
    }
  } while (r != -1 && p3 > 0 && (short)p2 > 0);
  // Haelt den Nutzwert von ret hoch genug fuer die Stapelplatzvergabe wie im Original
  { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; } { int u_ = ret; ret = u_; }
  return ret;
}


#undef uv
#undef fl
#undef ret
#undef c1
#undef c2
#undef off

int f_144bf0(int p1, int p2);
//@ f_03fdf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion durchsucht beide Charakterarchive (0x90002 für bereits im Spiel gespeicherte
 *   Helden und 0x90001 für Stamm-Helden) und stellt alle Charaktere in der Liste *(p1 + 2) zusammen, die noch
 *   nicht aktiv in der Gruppe (d_1bc8f0) sind und sich am aktuellen Tempelort *(short *)p1 (oder im Startzustand
 *   1) befinden.
 * - Eingaben und Rückgabe: Die Funktion erhält das Verwaltungs-Zustandsobjekt p1 und gibt die Anzahl c1 der
 *   gefundenen aufnehmbaren Helden als short zurück.
 * - Wichtige Variablen: Das temporäre Array arr sammelt bereits im Spiel befindliche, aber an einem anderen Ort
 *   geparkte Helden aus 0x90002, damit deren ursprüngliche Vorlagen aus dem Stamm-Archiv 0x90001 nicht
 *   fälschlicherweise ein zweites Mal zur Auswahl angeboten werden.
 === Ende Beschreibung === */
struct E26_fd {
  char s0[0x10];
  char s10[0x10];
  int x20;
  short x24;
};
short f_03fdf0(int p1)
{
  int found2, flag1, flag2;
  E26_fd *arr;
  int found1;
  short j, n1, c1, c2, i;
  int a, b, hero, q, found3, found4, s, list1;
  E26_fd *list2;
  char *entry;
  short total, k, count1, count2;

  { int rt = d_1bc8f0; d_1bc8f0 = rt; } // Haelt die Register- und Stapelvergabe wie im Original
  f_0d2f90(5, 1);
  c1 = 0;
  a = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090001)));
  b = ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x40090002)));
  total = (short)((unsigned)(b + a) / 0x5ef);
  T5ef *p = new (mark(d_1a0d24, 0x215)) T5ef;
  hero = p ? ((int)(f_0421c0((struct hero *)((int)p)))) : (int)p;
  arr = (E26_fd *)new (mark(d_1a0d24, 0x216)) char[(short)total * 0x26];
  i = 0;
  c2 = 0;
  flag1 = 0;
  do {
    if (f_0b0790(i, 0x90002, hero) == 0x5ef) {
      s = ((int)(f_042320((struct hero *)(hero))));
      found1 = 0;
      q = d_1bc8f0;
      for (k = 0; k < 6; k++, q += 0x5ef) {
        if (((char)(f_042350((struct hero *)(q))))) {
          if (f_144bf0(((int)(f_042320((struct hero *)(q)))), s) == 0) {
            found1 = 1;
            break;
          }
        }
      }
      if (!found1 && ((signed char)((char)(f_042940((struct hero *)(hero)))) == *(short *)p1 || (signed char)((char)(f_042940((struct hero *)(hero)))) == 1 || *(short *)p1 == -1)) {
        strcpy((*(E26_fd **)(p1 + 2))[c1].s0, (char *)((int)(f_0422b0((struct hero *)(hero)))));
        strcpy((*(E26_fd **)(p1 + 2))[c1].s10, (char *)((int)(f_042320((struct hero *)(hero)))));
        (*(E26_fd **)(p1 + 2))[c1].x20 = 0x90002;
        (*(E26_fd **)(p1 + 2))[c1].x24 = i;
        c1++;
      } else {
        strcpy(arr[c2].s0, (char *)((int)(f_0422b0((struct hero *)(hero)))));
        strcpy(arr[c2].s10, (char *)((int)(f_042320((struct hero *)(hero)))));
        arr[c2].x20 = 0x90002;
        arr[c2].x24 = i;
        c2++;
      }
    } else {
      flag1 = 1;
    }
    { short u_ = i; i = u_; } { short u_ = i; i = u_; }
    { short cc = c2; c2 = cc; }
    i++;
  } while (!flag1);
  n1 = c1; { short nn = n1; n1 = nn; }
  flag2 = 0;
  j = 0;
  do {
    if (f_0b0790(j, 0x90001, hero) == 0x5ef) {
      count1 = n1;
      s = ((int)(f_042320((struct hero *)(hero))));
      found2 = 0;
      list1 = *(int *)(p1 + 2);
      for (k = 0; k < count1; k++) {
        if (f_144bf0(s, list1 + k * 0x26 + 0x10) == 0) {
          found2 = 1;
          break;
        }
      }
      if (!found2) {
        count2 = c2;
        list2 = arr;
        s = ((int)(f_042320((struct hero *)(hero))));
        found3 = 0;
        for (k = 0; k < count2; k++) {
          entry = (char *)list2;
          entry += k * 0x26;
          if (f_144bf0(s, (int)(entry + 0x10)) == 0) {
            found3 = 1;
            break;
          }
        }
        if (!found3) {
          s = ((int)(f_042320((struct hero *)(hero))));
          found4 = 0;
          q = d_1bc8f0;
          for (k = 0; k < 6; k++, q += 0x5ef) {
            if (((char)(f_042350((struct hero *)(q))))) {
              if (f_144bf0(((int)(f_042320((struct hero *)(q)))), s) == 0) {
                found4 = 1;
                break;
              }
            }
          }
          if (!found4 && ((signed char)((char)(f_042940((struct hero *)(hero)))) == *(short *)p1 || (signed char)((char)(f_042940((struct hero *)(hero)))) == 1 || *(short *)p1 == -1)) {
            strcpy((*(E26_fd **)(p1 + 2))[c1].s0, (char *)((int)(f_0422b0((struct hero *)(hero)))));
            strcpy((*(E26_fd **)(p1 + 2))[c1].s10, (char *)((int)(f_042320((struct hero *)(hero)))));
            (*(E26_fd **)(p1 + 2))[c1].x20 = 0x90001;
            (*(E26_fd **)(p1 + 2))[c1].x24 = j;
            c1++;
          }
        }
      }
    } else {
      flag2 = 1;
    }
    { short jj = j; j = jj; } { short jj = j; j = jj; }
    j++;
  } while (!flag2);
  delete arr;
  if (hero != 0) {
    operator delete((void *)((int)(f_0421e0((struct hero *)(hero), 0))));
  }
  f_0d2e70();
  return c1;
}


