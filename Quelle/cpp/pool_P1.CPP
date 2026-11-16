/* === Beschreibung (Katalog) ===
 * Einheit pool (0dea70 - 0dee80)
 *
 * Überblick
 * Die Einheit pool stammt aus der Quelldatei pool.cpp und implementiert die Hauptsteuerung des Handels- und
 * Waren-Pools (Kaufen, Verkaufen, Reparieren und Beute-Auswahl), einschließlich des Auf- und Abbaus der
 * Pool-Hilfsobjekte (poolinit, poolgfx, panel) und des Ausschreibens der gewählten Waren in die temporäre
 * Übergabedatei good.$$$ (d_1a63a0).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// P3 1/4 gleich (suche.py 26.10.2026, Basis pool_P1.CPP)
// pool.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DEA70-0x0DEE80
#include <string.h>
#include "RIVAMEM.H"



struct Rec { char z[16]; short n; char y[6]; };
struct Obj { char z0[4]; short s4; char z6[4]; short n; Rec *recs; char data[14]; int i1e; int p22; int p26; short s2a; };
int f_068f40();
int f_0bf730(int p1, int p2);
int f_0da910(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_0da990(int p1, int p2);
short f_0df540(Obj *p);
int f_0df6b0(Obj *p, int p2);
int f_0dfbc0(Obj *p);
int f_0e0680(int p1, Obj *p2);
int f_0e06f0();
int f_0e0760(int p1);
int f_0e0dc0(int p1, int p2);
int f_0e2660(int p1, Obj *p2);
int f_0e26d0(int p1, int p2);
int f_0e2700(int p1);
int f_13fc70(int p1);
int f_13fcd0(int p1, int p2);





extern int d_1a63a0;
extern int d_1a965c;
extern int d_1bb574;
extern short d_1bb244;
extern int d_1bfdb8;
extern int d_1c0032;
extern short d_1c0044;
extern short d_1c0046;
extern volatile short d_1c0048;
extern int d_1c0c4c;
extern int d_1c14c4;

extern volatile short d_1c2198;
extern int d_1c2c64;
extern const char d_1a6384[];
int f_0dec50(Obj *p);
void f_0dedf0(Obj *p);
void f_0ded10(Obj *p);
static inline void save_pool_records(Obj *p)
{
  int base, offset;
  d_1a965c = d_1a63a0;
  ((RivaFileManager*)((int)&d_1c2098))->f_144af0( 0);
  ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0, 0x221);
  ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)p->data), 2)));
  for (short i = 0; i < p->n; i++) {
    base = (int)p->recs;
    offset = i * 0x18;
    Rec *r = (Rec *)(offset + base);
    if (r->n > 0) ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)r), 0x18)));
  }
  ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
}

//@ f_0dea70
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt den kompletten Handels-/Waren-Pool-Dialog für das Pool-Objekt p aus: initialisiert Daten,
 *   Grafik und Aktionsleiste über f_0dec50, zeichnet den Bildschirm (f_0e0dc0), verarbeitet in einer Schleife
 *   Maus- und Tastatureingaben (f_0df540, f_0df6b0, f_0dfbc0), schreibt bei Bestätigung (p->s2a == 1) die
 *   ausgewählten Waren über f_0dedf0 nach good.$$$ und gibt alle Hilfsobjekte wieder frei (bzw. zeigt bei leerem
 *   Angebot die Meldung 0x220101b0).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Steuerobjekt (p).
 * - Rückgabewert: Gibt den Abschlussstatus (p->s2a: 1 = Handel bestätigt, 0 = abgebrochen, -1 = keine passenden
 *   Gegenstände vorhanden) zurück.
 === Ende Beschreibung === */
int f_0dea70(Obj *p)
{
  short sv;
  int r = 0;
  sv = f_13fc70((int)&d_1c14c4);
  d_1c0c4c = d_1c0c4c + 1;
  if (f_0dec50(p) == 1) {
    f_0e0dc0(p->p26, *(short *)&d_1c0032);
    d_1c2198 = 0;
    short z = 0;
    do {
      if (d_1c2198 == 1) {
        d_1c2198 = z;
        if (p->i1e == 0) f_0e2700(p->p22);
        f_0e0dc0(p->p26, *(short *)&d_1bb574);
      }
      f_0dfbc0(p);
      f_068f40();
      if (d_1c0048 == 1) {
        d_1c0048 = z;
        d_1c0044 = d_1c0046;
      } else {
        r = f_0df6b0(p, f_0df540(p));
      }
    } while (r == 0);
    {
      int g, v2;
      Obj *q;
      g = d_1bfdb8;
      q = p;
      if (g) operator delete((void *)f_0da990(g, 0));
      d_1bfdb8 = 0;
      f_0e0760(q->p26);
      operator delete((void *)q->p26);
      if (q->s2a == 1) save_pool_records(q);
      v2 = q->p22;
      if (v2) operator delete((void *)f_0e26d0(v2, 0));
    }
  } else {
    if (p->s4 <= 0) {
      f_0bf730((int)&d_1c2c64, 0x220101b0);
      p->s2a = -1;
    }
  }
  f_13fcd0((int)&d_1c14c4, sv);
  d_1c0c4c = d_1c0c4c - 1;
  return p->s2a;
}
//@ f_0dec50
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Erzeugt und initialisiert für den Handels-Pool p das Daten-Initialisierungsobjekt (p->p22, f_0e2660
 *   / f_0e2700), legt bei vorhandenem Warenangebot (r == 1) zusätzlich das Grafikobjekt (p->p26, f_0e0680 /
 *   f_0e06f0) sowie die seitliche Aktionsleiste (d_1bfdb8, f_0da910 mit den Archiven 0x280000..0x280003) an.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Steuerobjekt (p).
 * - Rückgabewert: Gibt 1 zurück, wenn mindestens ein Gegenstand im Pool-Angebot vorhanden ist, sonst 0.
 === Ende Beschreibung === */
int f_0dec50(Obj *p)
{
  int f_0e06f0(int);
  int o, r;
  o = (int)operator new(0x1c, mark(d_1a6384, 0xa6));
  o = o ? f_0e2660(o, p) : o;
  p->p22 = o;
  r = f_0e2700(o);
  if (r == 1) {
    o = (int)operator new(0x10, mark(d_1a6384, 0xb8));
    o = o ? f_0e0680(o, p) : o;
    p->p26 = o;
    f_0e06f0(o);
    o = (int)operator new(0x42, mark(d_1a6384, 200));
    o = o ? f_0da910(o, 0x280000, 0x280001, 0x280002, 0x280003, d_1bb244, 0x16) : o;
    d_1bfdb8 = o;
  }
  return r;
}
//@ f_0ded10
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Räumt die Hilfsobjekte des Handels-Pools (d_1bfdb8, p->p26, p->p22) ab und speichert bei
 *   bestätigter Auswahl (p->s2a == 1) alle Wareneinträge mit gewählter Stückzahl (r->n > 0) in die Übergabedatei
 *   good.$$$ (d_1a63a0).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Steuerobjekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ded10(Obj *p)
{
  int v, v2;
  v = d_1bfdb8;
  if (v != 0) operator delete((void *)f_0da990(v, 0));
  d_1bfdb8 = 0;
  f_0e0760(p->p26);
  operator delete((void *)p->p26);
  if (p->s2a == 1) {
    short i;
    d_1a965c = d_1a63a0;
    ((RivaFileManager*)((int)&d_1c2098))->f_144af0( 0);
    Obj *q = p;
    ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0, 0x221);
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)q->data), 2)));
    for (i = 0; i < q->n; i++) {
      Rec *r = (Rec *)((char *)q->recs + (int)i * 0x18);
      if (r->n > 0) ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)r), 0x18)));
    }
    ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
  }
  v2 = p->p22;
  if (v2 != 0) operator delete((void *)f_0e26d0(v2, 0));
}
//@ f_0dedf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schreibt die im Handels-Pool p ausgewählten Warensätze (r->n > 0, jeweils 24 Bytes) samt
 *   2-Byte-Kopfsatz (p->data) in die temporäre Übergabedatei good.$$$ (d_1a63a0).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Steuerobjekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dedf0(Obj *p)
{
  int base, offset;
  d_1a965c = d_1a63a0;
  ((RivaFileManager*)((int)&d_1c2098))->f_144af0( 0);
  ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0, 0x221);
  ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)p->data), 2)));
  for (short i = 0; i < p->n; i++) {
    base = (int)p->recs;
    offset = i * 0x18;
    Rec *r = (Rec *)(offset + base);
    if (r->n > 0) ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( (int)r), 0x18)));
  }
  ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
}
