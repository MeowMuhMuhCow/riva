/* === Beschreibung (Katalog) ===
 * Einheit gz_0dee80 (0dee80 - 0dfca0)
 *
 * Überblick
 * Die Einheit gz_0dee80 bildet den zweiten Teil des Handels- und Waren-Pool-Moduls (pool.cpp). Sie verarbeitet
 * das Auswählen und Abwählen einzelner Waren (inklusive Mengeneingabe bei stapelbaren Gegenständen, Preis-,
 * Gewichts- und Slot-Berechnung) sowie das Blättern und Navigieren durch das 4x5-Warengitter per Maus und
 * Tastatur.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
// P3 19/20 gleich (suche.py 28.10.2026, Basis gz_0dee80_P1.CPP)
// gz_0dee80.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DEE80-0x0DFCA0
#include <string.h>
#include "RIVAMEM.H"



struct P { int x0; short s4, s6, s8, sa; char *tab; short s10; int i12; int i16; short s1a, s1c; char pad[8]; int q26; short s2a; int i2c; };
struct SO { char b[12]; int *p; char c[16]; short *q; char d[24]; };
int f_0bf730(const char *o, int b);
int f_0bf7b0(const char *o, int a, int b, int c, int d, int e);
short f_0d3530(void *p);
int f_0d37b0();
int f_0d3810();
short f_0dacc0(int p1);
int f_0de7e0(int p1);
int f_0e07a0(int p1, int p2, int p3);
int f_0e08e0(int p1, int p2);
int f_0e0a30(int p1, int p2, int p3);
int f_0e0dc0(int p1, int p2);
int f_0e14e0(int p1, int p2);
int f_0e1600(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
extern char d_1a63e4[];
extern short d_1bb572;
extern short d_1bb576;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1bfdb8;
extern int d_1c0004;
extern short d_1c0030;
extern volatile short d_1c0042;
extern volatile short d_1c0044;

extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
struct WareDemo660 { short maximum,id,unknown4,price,unit,weight; int stackable; short selected; char rest[6]; };
#define W660(i) (((WareDemo660*)p->tab)[i])
short f_0df240(int,int,short,short);
//@ f_0dee80
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Erhöht oder verringert (je nach Modus p->i2c) die ausgewählte Stückzahl des Warenfelds n auf der
 *   aktuellen Pool-Seite: fragt bei stapelbaren Gegenständen die gewünschte Menge über f_0df240 ab, prüft beim
 *   Einkauf (p->s4 != 0), ob das Gruppengeld (f_0de7e0) ausreicht (sonst Meldung 0x220101af), aktualisiert
 *   Gesamtpreis (p->i12), Gesamtgewicht (p->i16) und benötigte Inventarplätze (p->s10) und zeichnet die Kachel
 *   sowie die Statusanzeige neu.
 * - Eingaben: Übergeben werden der Zeiger auf das Pool-Objekt (p) sowie der Kachelindex auf der aktuellen Seite
 *   (n, 0..19).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dee80(P *p,short n)
{
 short idx=n+p->s1a*5;
 short mx=W660(idx).maximum;
 short cur=W660(idx).selected;
 short v=cur;
 if(mx==-1)mx=99;
 int off1347=(int)idx*24;
 if(*(int*)(p->tab+off1347+12)==1) {
  short art=W660(idx).id;
  if(p->i2c==1) {
   if(cur>0)v-=f_0df240((int)p,0x220101ae,cur,art);
  } else {
   if(mx-cur>0)v+=f_0df240((int)p,0x220101ad,mx-cur,art);
  }
 } else {
  if(p->i2c==1)v--; else v++;
 }
 if(v<0)v=0;else if(v>mx)v=mx;
 if(v!=cur) {
  short delta=v-cur;
  short i=0;
  long cost=(long)delta*W660(idx).price*W660(idx).unit;
  if(p->s4!=0) {
   if(p->i12+cost>f_0de7e0(d_1c0004)) {
    f_0bf730(d_1c2c64,0x220101af);
    return;
   }
  }
  W660(idx).selected=v;
  p->s10=0;
  for(i=0;i<p->sa;i++) {
   if(W660(i).selected>0) {
    if(W660(i).stackable==1)p->s10++;
    else p->s10+=W660(i).selected;
   }
  }
  p->i16+=delta*(int)W660(idx).weight;
  p->i12+=cost;
  { int color=d_1bb572;
  f_0e14e0(p->q26,n);
  f_0e07a0(p->q26,n,color);
  f_0e1600(p->q26); }
 }
}
#undef W660
//@ f_0df240
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet im Handels-Pool bei stapelbaren Waren einen Mengeneingabe-Dialog (f_0bf7b0) für den
 *   Gegenstand c mit dem Maximalwert b und dem Vorschlagswert min(10, b).
 * - Eingaben: Übergeben werden das Pool-Objekt (u), die Dialog-Textkennung (a), die maximal wählbare Stückzahl
 *   (b) sowie die Gegenstandskennung (c).
 * - Rückgabewert: Gibt die vom Spieler eingegebene Stückzahl (0..b) zurück.
 === Ende Beschreibung === */
short f_0df240(int u,int a,short b,short c) {
 short r=0, w=10;
 SO o;
 f_125400(&o,d_1c349c,d_1c3870,d_1c3498);
 if(w>b)w=b;
 o.p[1]=(*(int **)&d_1c2c40)[c]; o.q[1]=2;
 r=f_0bf7b0(d_1c2c64,2,a,0,b,w);
 if(r==-1)r=0;
 f_1254a0(&o,0);
 return r;
}
//@ f_0df2d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Blättert im Waren-Pool um eine Spalte nach rechts (++p->s1a), sofern das letzte Spaltenfenster
 *   (p->s8) noch nicht erreicht ist.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df2d0(P *p)
{
  if (p->s1a < p->s8) {
    p->s1c = p->s1a;
    ++p->s1a;
  }
}
//@ f_0df2f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Blättert im Waren-Pool um eine Spalte nach links (--p->s1a), sofern p->s1a > 0 ist.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df2f0(P *p)
{
  if (p->s1a > 0) {
    p->s1c = p->s1a;
    p->s1a = p->s1a + 0xffff;
  }
}
//@ f_0df310
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Blättert im Waren-Pool um eine ganze Seite (bis zu 4 Spalten) nach rechts, begrenzt auf die letzte
 *   verfügbare Spalte p->s8.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df310(P *p)
{
  short t = p->s1a + 4;
  if (p->s8 < t) {
    do {
      t = t - 1;
    } while (p->s8 < t);
  }
  p->s1c = p->s1a;
  p->s1a = t;
}
//@ f_0df340
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Blättert im Waren-Pool um eine ganze Seite (bis zu 4 Spalten) nach links, mindestens bis zur Spalte
 *   0.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df340(P *p)
{
  short t = p->s1a - 4;
  while (t < 0) t = t + 1;
  p->s1c = p->s1a;
  p->s1a = t;
}
//@ f_0df370
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bewegt die Auswahlmarkierung (d_1c0044) im 4x5-Warengitter um eine Spalte (5 Felder) nach links
 *   oder scrollt am linken Rand um eine Spalte zurück (--p->s1a).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df370(P *p)
{
  if (d_1c0044 - 1 >= 5) {
    d_1c0042 = d_1c0044;
    d_1c0044 = d_1c0044 + 0xfffb;
    return;
  }
  if (p->s1a > 0) {
    p->s1c = p->s1a;
    p->s1a = p->s1a + 0xffff;
  }
}
//@ f_0df3b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bewegt die Auswahlmarkierung (d_1c0044) innerhalb der aktuellen Gitterspalte um ein Feld nach oben
 *   (mit Umbruch vom obersten auf das unterste Feld der Spalte).
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df3b0()
{
  if ((d_1c0044 - 1) % 5 == 0) {
    d_1c0042 = d_1c0044;
    d_1c0044 = d_1c0044 + 4;
    return;
  }
  d_1c0042 = d_1c0044;
  d_1c0044 = d_1c0044 + 0xffff;
}
//@ f_0df400
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bewegt die Auswahlmarkierung (d_1c0044) im 4x5-Warengitter um eine Spalte (5 Felder) nach rechts
 *   oder scrollt am rechten Rand um eine Spalte weiter (++p->s1a).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df400(P *p)
{
  if (d_1c0044 - 1 < 0xf) {
    d_1c0042 = d_1c0044;
    d_1c0044 = d_1c0044 + 5;
    return;
  }
  if (p->s1a < p->s8) {
    p->s1c = p->s1a;
    p->s1a = p->s1a + 1;
  }
}
//@ f_0df440
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bewegt die Auswahlmarkierung (d_1c0044) innerhalb der aktuellen Gitterspalte um ein Feld nach unten
 *   (mit Umbruch vom untersten auf das oberste Feld der Spalte).
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df440()
{
  if ((d_1c0044 - 1) % 5 == 4) {
    d_1c0042 = d_1c0044;
    d_1c0044 = d_1c0044 + 0xfffc;
    return;
  }
  d_1c0042 = d_1c0044;
  d_1c0044 = d_1c0044 + 1;
}
//@ f_0df490
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt die Auswahlmarkierung und die Spaltenansicht im Waren-Pool auf den allerersten Eintrag
 *   (d_1c0044 = 1, p->s1a = 0) zurück (Pos1-Taste).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df490(P *p)
{
  if (d_1c0044 - 1 > 0 || p->s1a > 0) {
    d_1c0042 = d_1c0044;
    d_1c0044 = 1;
    short u = p->s1a;
    p->s1a = 0;
    p->s1c = u;
  }
}
//@ f_0df4d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Springt im Waren-Pool auf die letzte verfügbare Spalte (p->s8) und setzt die Auswahlmarkierung
 *   (d_1c0044) auf den letzten belegten Wareneintrag (Ende-Taste).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0df4d0(P *p)
{
  if (d_1c0044 - 1 >= 0x13 && p->s1a >= p->s8) return;
  {
    short base = p->s8 * 5;
    --base;
    short k = 0x14;
    while (*(short *)(p->tab + (k + (int)base) * 0x18 + 2) == 0) k = k - 1;
    d_1c0042 = d_1c0044;
    d_1c0044 = k;
    short old = p->s1a;
    short next = p->s8;
    p->s1c = old;
    p->s1a = next;
  }
}
//@ f_0df540
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest Tastatur-, Mausklick- (Links- und Rechtsklick auf die 20 Gitterfelder d_1a63e4, wobei
 *   Rechtsklick p->i2c = 1 zum Verringern setzt) und Panel-Eingaben (f_0dacc0(d_1bfdb8)) für den Handels-Pool
 *   ein und übersetzt sie in einen einheitlichen Steuercode.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Gibt den ermittelten Steuercode (1..20 für Gitterfelder, 0x15..0x1b für Tastaturbefehle,
 *   0x80..0xa8 für Panel-Schaltflächen) oder 0 zurück.
 === Ende Beschreibung === */
short f_0df540(P *p)
{
  short t = 0;
  switch (d_1bd762) {
    case 0x4800: t = 0x16; break;
    case 0x5000: t = 0x18; break;
    case 0x4b00: t = 0x15; break;
    case 0x4d00: t = 0x17; break;
    case 0x4700: t = 0x19; break;
    case 0x4f00: t = 0x1a; break;
    case 0x1b2b: case 0x1c0d: case 0x342e: case 0x4e2b: case 0x5200: t = 0x1b; break;
    case 0x0e08: case 0x352d: case 0x4a2d: case 0x5300: t = 0x1b; p->i2c = 1; break;
  }
  if (t == 0 && d_1bd766 >= 1 && d_1bd766 <= 0x14) t = d_1bd766;
  else f_0d3810();
  if (f_0d37b0()) {
    t = f_0d3530(d_1a63e4);
    if (t > 0) p->i2c = 1;
    while (f_0d37b0() == 1) {
    }
  }
  if (t == 0) {
    short u = f_0dacc0(d_1bfdb8);
    if (u >= 0x80 && u <= 0xb7) t = u;
  }
  return t;
}
//@ f_0df6b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt den von f_0df540 gelieferten Steuercode k im Handels-Pool p aus (Blättern, Cursorbewegung,
 *   Warenmenge ändern über f_0dee80, Handel bestätigen bei 0xa6 oder abbrechen bei 0x80) und setzt anschließend
 *   das Abzugs-Flag p->i2c = 0 zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Pool-Objekt (p) sowie der auszuführende Steuercode (k).
 * - Rückgabewert: Gibt 1 zurück, wenn der Pool-Dialog beendet werden soll (0x80 oder 0xa6), sonst 0.
 === Ende Beschreibung === */
short f_0df6b0(P *p, short k)
{
    struct Schritte {
      static void versatz(P *q,short d) { q->s1c=q->s1a; q->s1a=q->s1a+d; }
      static void global(short d) { d_1c0042=d_1c0044; d_1c0044=d_1c0044+d; }
      static void global5(int d) { d_1c0042=d_1c0044; d_1c0044=d_1c0044+d; }
      static void weiter(P *q) { if (q->s1a<q->s8) versatz(q,1); }
      static void links(P *q) { if (d_1c0044-1>=5) global(-5); else if (q->s1a>0) versatz(q,-1); }
      static void rechts(P *q) { if (d_1c0044-1<15) global5(5); else if (q->s1a<q->s8) versatz(q,1); }
      static void ende(P *q) {
        if (d_1c0044-1 < 19 || q->s1a < q->s8) {
          short base=q->s8*5-1;
          short i=20;
          while (*(short *)(q->tab+(i+(int)base)*24+2)==0) --i;
          d_1c0042=d_1c0044;
          d_1c0044=i;
          short a=q->s1a, b=q->s8;
          q->s1c=a; q->s1a=b;
        }
      }
    };
    volatile int r=0;
    short s;
    switch(k) {
    case 0xa8:
      if (p->s1a > 0) {
        p->s1c = p->s1a;
        p->s1a = p->s1a + 0xffff;
      }
      break;
    case 0xa7:
      Schritte::weiter(p);
      break;
    case 0xa6:
      s = 0;
      for (s = 0; s < (short)p->sa; ++s) {
          if (*(short *)(p->tab + 0x10 + s * 0x18) > 0) {
            p->s2a = 1;
            break;
          }
      }
      r = 1;
      break;
    case 0xa5:
      f_0df340(p);
      break;
    case 0xa4:
      f_0df310(p);
      break;
    case 0x80:
      p->s2a = 0;
      r = 1;
      break;
    case 0x15:
      Schritte::links(p);
      break;
    case 0x16:
      if ((d_1c0044-1)%5 == 0) {
        Schritte::global(4);
        break;
      } else {
        Schritte::global(-1);
        break;
      }
    case 0x17:
      Schritte::rechts(p);
      break;
    case 0x18:
      if ((d_1c0044-1)%5 == 4) {
        d_1c0042=d_1c0044;
        d_1c0044=d_1c0044+0xfffc;
        break;
      } else {
        d_1c0042=d_1c0044;
        ++d_1c0044;
        break;
      }
    case 0x1a:
      Schritte::ende(p);
      break;
    case 0x1b:
      f_0dee80(p, d_1c0044 - 1);
      break;
    case 0x19:
      f_0df490(p);
      break;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
      f_0dee80(p, k - 1);
      break;
    default: break;
    }
    short v=r;
    p->i2c=0;
    return v;
}
//@ f_0dfb20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft bei einem Rechtsklick im Handels-Pool über f_0d3530(d_1a63e4), welche Warenkachel unter dem
 *   Mauszeiger liegt, und aktiviert bei einem Treffer (r > 0) den Abzugsmodus (p->i2c = 1).
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Gibt den getroffenen Kachelindex (1..20) oder 0 zurück.
 === Ende Beschreibung === */
short f_0dfb20(P *p)
{
  short r = f_0d3530(d_1a63e4);
  if (r > 0) p->i2c = 1;
  return r;
}
//@ f_0dfb50
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verschiebt die aktuelle Spaltenposition (p->s1a) im Waren-Pool relativ um d und merkt sich die
 *   vorherige Spalte in p->s1c.
 * - Eingaben: Übergeben werden der Zeiger auf das Pool-Objekt (p) sowie das Spalten-Delta (d).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfb50(P *p, short d)
{
  p->s1c = p->s1a;
  p->s1a = p->s1a + d;
}
//@ f_0dfb70
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt die aktuelle Spaltenposition (p->s1a) im Waren-Pool absolut auf v und sichert die vorherige
 *   Spalte in p->s1c.
 * - Eingaben: Übergeben werden der Zeiger auf das Pool-Objekt (p) sowie der neue Spaltenindex (v).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfb70(P *p, short v)
{
  p->s1c = p->s1a;
  p->s1a = v;
}
//@ f_0dfb80
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verschiebt den aktuell markierten Kachelindex (d_1c0044) relativ um d und speichert den bisherigen
 *   Index in d_1c0042.
 * - Eingaben: Übergeben werden ein ungenutzter Objektzeiger (u) sowie das Index-Delta (d).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfb80(int u, short d)
{
  d_1c0042 = d_1c0044;
  d_1c0044 = d_1c0044 + d;
}
//@ f_0dfba0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt den aktuell markierten Kachelindex (d_1c0044) absolut auf v und speichert den bisherigen
 *   Index in d_1c0042.
 * - Eingaben: Übergeben werden ein ungenutzter Objektzeiger (u) sowie der neue Kachelindex (v).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfba0(int u, short v)
{
  d_1c0042 = d_1c0044;
  d_1c0044 = v;
}
//@ f_0dfbc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Aktualisiert die Grafikanzeige des Waren-Pools (p->q26), sobald sich die sichtbare Spalte (p->s1a
 *   != p->s1c) oder die ausgewählte Kachel (d_1c0044 != d_1c0042) geändert hat, indem das Gitter (f_0e0dc0), der
 *   Auswahlrahmen (f_0e07a0), die Heldenmarkierungen (f_0e08e0) und die Statuszeile (f_0e0a30) neu gezeichnet
 *   werden.
 * - Eingaben: Übergeben wird der Zeiger auf das Pool-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfbc0(P *p)
{
  if (p->s1a != p->s1c) {
      if ((short)(p->s1a - p->s1c) != 0) f_0e0dc0(p->q26, d_1bb576);
    if (d_1c0044 == d_1c0042) {
      int r = f_0e08e0(p->q26, d_1c0044);
      f_0e0a30(p->q26, d_1c0044, r);
    }
    p->s1c = p->s1a;
  }
  if (d_1c0044 != d_1c0042) {
    f_0e07a0(p->q26, (short)(d_1c0042 - 1), d_1c0030);
    f_0e07a0(p->q26, (short)(d_1c0044 - 1), d_1bb572);
    int r2 = f_0e08e0(p->q26, d_1c0044);
    f_0e0a30(p->q26, d_1c0044, r2);
    d_1c0042 = d_1c0044;
  }
}
