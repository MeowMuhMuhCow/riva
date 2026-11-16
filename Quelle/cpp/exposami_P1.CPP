/* === Beschreibung (Katalog) ===
 * Einheit exposami (0x0695C0 - 0x069970)
 *
 * Überblick
 * Die Einheit exposami verwaltet die 11-Byte-Objekt- und Interaktionseinträge (Rec) eines Dungeons oder
 * Stadtgebiets sowie deren dynamische Liste (List): Sie stellt Lese- und Schreibmethoden für die einzelnen
 * Objektfelder, die Suche nach einer Objektkennung (id) und das Laden der Liste aus einem verzeichnisbasierten
 * Archivblock (f_0698b0) bereit.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// P3 15/22 gleich (suche.py 25.10.2026, Basis exposami_P1.CPP)
// I9: aus exposami_REST.CPP uebernommen (Stufe-2-Stand), Marken 7 neu
// exposami.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x0695C0-0x069970. Liste von 11-Byte-Eintraegen (Anzahl + Zeiger): Zugriffe, Suche nach Kennung, Laden aus Archiv.
#include <string.h>
extern const char exposami_file[];   // Inhalt in der Basis (Fable 30.10.: nicht hier definieren)
extern const short d_1a1ac8[][4];
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
   extern RivaFileManager d_1c2098;
struct Rec {
  char c0; signed char c1; signed char c2; signed char c3; signed char c4; short s5; short s7; short s9;
  int f_0695c0(); int f_069610(); int f_069620(); void f_069630(int v); int f_069640(); int f_069650(int v);
  int f_069660(); int f_069670(int v); short f_069680(); int f_069690(); int f_0696a0();
};
//@ f_0695c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt für einen 11-Byte-Objekteintrag (Rec) anhand seines Zustands-/Größenwerts c2
 *   (eingeteilt in vier Stufen 0..3 für c2 == 1, 2..7, > 7 und 0) und des Untertyps c1 den zugehörigen
 *   Tabellenwert aus d_1a1ac8[g][c1].
 * - Eingaben:
 *   - this (Impliziter Zeiger auf den Rec-Eintrag).
 * - Rückgabewert: int - Der aus d_1a1ac8 gelesene 16-Bit-Wert.
 * - Wichtige Variablen:
 *   - g (Stufenindex 0..3 anhand von c2).
 *   - y, x (Werte der Felder c1 und c2).
 === Ende Beschreibung === */
int Rec::f_0695c0() {
  short g = 3; Rec *t = this; int y = t->c1; unsigned x = t->c2;
  if (x > 7) g = 2; else if (x > 1) g = 1; else if (x == 1) g = 0;
  return d_1a1ac8[g][(short)y];
}
int Rec::f_069610() { return c1; }
int Rec::f_069620() { return c2; }
void Rec::f_069630(int v) { c2 = v; }
int Rec::f_069640() { return c3; }
int Rec::f_069650(int v) { c3 = v; return c3; }
int Rec::f_069660() { return c4; }
int Rec::f_069670(int v) { c4 = v; return c4; }
short Rec::f_069680() { return s5; }
int Rec::f_069690() { return s7 << 16; }
int Rec::f_0696a0() { return s9 << 16; }
struct List {
  unsigned short n; Rec *p;
  List(); unsigned short f_0696e0(); Rec *f_0696f0(unsigned short i); Rec *f_069710(unsigned short i);
  Rec *f_069730(short id); int f_069770(short id); int f_0697c0(short id, int v);
  int f_069810(short id); int f_069860(short id, int v); int f_0698b0(unsigned long fid, short idx);
};
//@ f_0696b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor der Objektliste List: Initialisiert die Eintragsanzahl n = 0 und den Arrayzeiger
 *   p = 0.
 * - Eingaben:
 *   - self (Zeiger auf das List-Objekt).
 * - Rückgabewert: Keiner (void, bzw. self in eax).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0696b0(List *self) { self->n = 0; self->p = 0; }
//@ f_0696c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor der Objektliste List: Gibt bei n > 0 das dynamisch reservierte Array self->p
 *   frei.
 * - Eingaben:
 *   - self (Zeiger auf das List-Objekt).
 * - Rückgabewert: List * - Der Zeiger self.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_014710(void *p);
#pragma aux f_014710 modify exact [eax edx]
List *f_0696c0(List *self, int) {
  if (self->n > 0) delete self->p;
  return self;
}
unsigned short List::f_0696e0() { return n; }
Rec *List::f_0696f0(unsigned short i) { Rec *r = 0; if (n > 0) r = p + i; return r; }
Rec *List::f_069710(unsigned short i) { Rec *r = 0; if (n > 0) r = p + i; return r; }
//@ f_069730
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchsucht die Liste linear nach dem ersten Eintrag mit der Objektkennung s5 == id und gibt
 *   dessen Zeiger zurück.
 * - Eingaben:
 *   - this (List *).
 *   - id (Gesuchte 16-Bit-Objektkennung).
 * - Rückgabewert: Rec * - Zeiger auf den gefundenen Eintrag oder 0.
 * - Wichtige Variablen:
 *   - q (Laufzeiger über p[0 .. n-1]).
 === Ende Beschreibung === */
Rec *List::f_069730(short id) {
    short id_ = id;
  Rec *r = 0; short i = 0;
  Rec *q; short t;
  for (; i < n; i++) { q = p + i; t = q->s5; if (id_ == t) { r = q; break; } }
  return r;
}
//@ f_069770
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht den Eintrag mit der Kennung id in der Liste und gibt dessen Statusfeld c3 zurück (oder
 *   0, wenn die Kennung nicht existiert).
 * - Eingaben:
 *   - this (List *).
 *   - id (Gesuchte Objektkennung).
 * - Rückgabewert: int - Wert von c3 des gefundenen Eintrags oder 0.
 * - Wichtige Variablen:
 *   - r (Gefundener Rec-Zeiger).
 === Ende Beschreibung === */
int List::f_069770(short id) {
  short t;
  int v = 1; Rec *r; short i;
  v = 0; r = 0; i = 0;
  for (; i < n; i++) { Rec *q = p + i; t = q->s5; if (id == t) { r = q; break; } }
  if (r != 0) v = r->c3;
  return v;
}
//@ f_0697c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht über f_069730 den Eintrag mit der Kennung id und setzt dessen Statusfeld c3 über
 *   f_069650(a) auf den Wert a.
 * - Eingaben:
 *   - this (List *).
 *   - id (Objektkennung).
 *   - a (Neuer Wert für c3).
 * - Rückgabewert: int - Der gesetzte Wert a (oder 0, falls id nicht gefunden wurde).
 * - Wichtige Variablen:
 *   - r (Gefundener Rec-Zeiger).
 === Ende Beschreibung === */
int List::f_0697c0(short id,int a) {
 int v=0; Rec *r=f_069730(id);
 if(r!=0) v=r->f_069650(a);
 return v;
}
//@ f_069810
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht den Eintrag mit der Kennung id in der Liste und gibt dessen zweites Statusfeld c4
 *   zurück (oder 0, wenn nicht vorhanden).
 * - Eingaben:
 *   - this (List *).
 *   - id (Gesuchte Objektkennung).
 * - Rückgabewert: int - Wert von c4 des gefundenen Eintrags oder 0.
 * - Wichtige Variablen:
 *   - r (Gefundener Rec-Zeiger).
 === Ende Beschreibung === */
int List::f_069810(short id) {
  short t;
  int v = 1; Rec *r; short i;
  v = 0; r = 0; i = 0;
  for (; i < n; i++) { Rec *q = p + i; t = q->s5; if (id == t) { r = q; break; } }
  if (r != 0) v = r->c4;
  return v;
}
//@ f_069860
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht über f_069730 den Eintrag mit der Kennung id und setzt dessen zweites Statusfeld c4
 *   über f_069670(a) auf den Wert a.
 * - Eingaben:
 *   - this (List *).
 *   - id (Objektkennung).
 *   - a (Neuer Wert für c4).
 * - Rückgabewert: int - Der gesetzte Wert a (oder 0, falls id nicht gefunden wurde).
 * - Wichtige Variablen:
 *   - r (Gefundener Rec-Zeiger).
 === Ende Beschreibung === */
int List::f_069860(short id,int a) {
 int v=0; Rec *r=f_069730(id);
 if(r!=0) v=r->f_069670(a);
 return v;
}
struct Dir { char h[10]; struct { short n; long ofs; } e[28]; };
//@ f_0698b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt die Teilliste mit dem Index idx aus der Archivdatei fid (mit Flag 0x40000000 in
 *   d_1c2098): Liest zunächst den 0xb2 Bytes großen Verzeichnis-Header Dir (mit bis zu 28 Unterlisten aus Anzahl
 *   n und Dateioffset ofs), reserviert bei n > 0 ein Array von n Rec-Strukturen (je 11 Bytes) und liest die
 *   Eintragsdaten ab d.e[idx].ofs ein.
 * - Eingaben:
 *   - this (List *).
 *   - fid (Archiv-Ressourcenkennung, z. B. 0x2d0001).
 *   - idx (Index des Gebiets bzw. Dungeons im Verzeichnis-Header 0..27).
 * - Rückgabewert: int - 1 bei erfolgreichem Laden, 0 bei Dateifehler.
 * - Wichtige Variablen:
 *   - d (Lokaler Verzeichnis-Header Dir mit 28 Einträgen { n, ofs }).
 === Ende Beschreibung === */
int List::f_0698b0(unsigned long fid, short idx) {
  int ok = 0; Dir d;
  if (d_1c2098.f_1448b0(fid | 0x40000000, 0x200) == 1) {
    d_1c2098.f_144920(&d, 0xb2);
    n = d.e[idx].n;
    if (n > 0) {
      p = new (mark(exposami_file, 376)) Rec[n];
      d_1c2098.f_144ab0(d.e[idx].ofs, 0);
      d_1c2098.f_144920(p, n * 11);
    }
    ok = 1;
    d_1c2098.f_1449a0();
  }
  return ok;
}
