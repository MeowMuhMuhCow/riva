/* === Beschreibung (Katalog) ===
 * Einheit misc
 *
 * Diese Einheit gehört zu misc.cpp und versammelt allgemeine Hilfsfunktionen: das Ausführen des Schnellmenüs
 * (Zaubern, Gegenstand benutzen, Tagebuch, Optionen), eine Zeichenketten-Kürzungsfunktion, einen
 * Bresenham-Linienalgorithmus für Rasterkoordinaten sowie die Indexbestimmung einer Heldengruppe.
 === Ende Beschreibung === */
// P3 1/4 gleich (suche.py 25.10.2026, Basis misc_P1.CPP)
// misc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CDAD0-0x0CE0B0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
inline int EQ(int a, int b) { return a == b; }
inline int GT(int a, int b) { return a > b; }
#include <stdlib.h>
int f_01e0c0();
int f_056d90(char *p1, int p2);
int f_092b90();
int f_09a0d0(int p1);
int f_09a140(int p1, int p2);
int f_0a8830(int p1, int p2, int p3);
int f_0a8b40(int p1, int p2);
int f_0a8be0(int p1);
int f_0bf730(const char *p1, int p2);
short f_0bf820(const char *p1, ...);
int f_0d5a90();
short f_0de7f0(int p1);
int f_11c0f0(int p1, int p2, int p3);
int f_11c120(int p1, int p2);
extern int d_1a34e0;
extern int d_1bc760;
extern signed char d_1bcac8;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1bfdbc;
extern int d_1c0004;
extern short d_1c2198;
extern char d_1c2c00[];
extern char d_1c2c64[];
extern const char d_1a57a8[];
//@ f_0cdad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet bei den Tastatur-/Aktionscodes 0xfd oder 0x1e01 das Aktions-Auswahlmenü
 *   (0x20000194 mit 3 bzw. im Kampf/Dungeon d_1bcac8 == 1 mit 4 Einträgen) und führt anschließend die gewählte
 *   Aktion aus: Zauberspruch wirken (0xe1), Gegenstand benutzen/wegwerfen (0xe2, Dialog f_0a8be0),
 *   Tagebuch/Notizen öffnen (0xe4, f_092b90) oder das Optionsmenü aufrufen (f_0d5a90).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen, sondern liest und aktualisiert die globalen
 *   Aktionscodes d_1bd766 und d_1bd762.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cdad0()
{
  int f_0a8be0_x(int p1);
  #pragma aux f_0a8be0_x "f_0a8be0" parm [eax] modify exact [eax ebx];
  short v;
  if (d_1bd766 == 0xfd || d_1bd762 == 0x1e01) {
    v = 3;
    if (EQ(d_1bcac8, 1)) v = 4;
    switch ((unsigned short)(f_0bf820(d_1c2c64, 0x20000194, v, 0x20000183, 0x200001c1, 0x200001c2, 0x20000181) - 1)) {
    case 0: d_1bd766 = 0xe0; break;
    case 1: d_1bd766 = 0xe2; break;
    case 2: d_1bd766 = 0xe4; break;
    case 3: d_1bd766 = 0xe1; break;
    default: d_1bd766 = 0;
    }
  }
  if (d_1bd766 == 0xe1) {
    if (EQ(d_1bcac8, 1)) {
      if (d_1bc760 != 0) f_01e0c0();
      f_056d90(d_1c2c00, 0);
      f_09a140(0, 0x19);
      f_09a0d0(d_1a34e0);
      d_1c2198 = 1;
    }
  } else if (d_1bd766 == 0xe2) {
    if (f_0de7f0(d_1c0004)) {
      int p, a, x;
      if (d_1bc760 != 0) f_01e0c0();
      p = (int)operator new(0x1f, mark(d_1a57a8, 0x8b));
      if (p != 0) { *(short *)p = 0; *(short *)((char *)p + 2) = 0; memset((char *)p + 4, 0, 0x1b); }
      a = p;
      { int t_ = (int)operator new(0x10, mark(d_1a57a8, 0x95)); p = (t_ != 0) ? f_11c0f0(t_, a, 0) : t_; }
      x = p;
      { int t_ = (int)operator new(0x5a, mark(d_1a57a8, 0x9f)); p = (t_ != 0) ? f_0a8830(t_, x, 0) : t_; }
      f_0a8be0_x(p);
      if (p != 0) operator delete((void *)f_0a8b40(p, 0));
      if (x != 0) operator delete((void *)f_11c120(x, 0));
      operator delete((void *)a);
      d_1c2198 = 1;
      return;
    } else {
      f_0bf730(d_1c2c64, 0x1c000001);
      return;
    }
  } else if (d_1bd766 == 0xe4) {
    if (d_1bc760 != 0) f_01e0c0();
    f_092b90();
    return;
  } else {
    f_0d5a90();
  }
}
//@ f_0cdd30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zeichenketten-Hilfsfunktion sucht in der nullterminierten Zeichenkette p1 nach dem ersten
 *   Vorkommen des Trennzeichens p2 und ersetzt dieses durch ein Nullbyte ('\0'), um den String dort
 *   abzuschneiden.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die zu kürzende Zeichenkette sowie das gesuchte Trennzeichen
 *   p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cdd30(char *p1, char p2)
{
  while (*p1 && p2 != *p1)
    p1++;
  *p1 = 0;
}
//@ f_0cdd50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet mittels eines Bresenham-Linienalgorithmus alle Rasterpunkte auf der
 *   Verbindungsstrecke zwischen (x1, y1) und (x2, y2), kehrt die Reihenfolge des Punkt-Arrays bei rückwärts
 *   verlaufenden Linien um, hängt das Endmarkierungspaar (-1, -1) an und gibt die Anzahl der Punkte zurück
 *   (genutzt u. a. für Sichtlinien- und Fernkampf-/Zauberbahnen im Kampf).
 * - Eingaben: Übergeben werden die Startkoordinaten x1, y1, die Zielkoordinaten x2, y2 sowie der Zeiger p5 auf
 *   das Ausgabearray für die (x, y)-Koordinatenpaare.
 * - Rückgabewert: Zurückgegeben wird die Anzahl n der berechneten Linienpunkte (ohne das abschließende (-1,
 *   -1)-Paar).
 === Ende Beschreibung === */
short f_0cdd50(short x1, short y1, short x2, short y2, short *p5)
{
    struct V905 {
       static short sub(short a,short b) { return a-b; }
       static short twice(short a) { return a+a; }
       static int extend(short a) { return a; }
    };
    short n=0, ox=x2, oy=y2;
    // haelt die Vergleichsform wie im Original
    unsigned short dx=abs(x2-x1);short nx=dx,dy=abs(y2-y1);
    short ex=x2,ey=y2;
    short x, y, stepy, stepx, twice, error, delta, straight, i;
    if ((int)(short)dx==0) {
        dy = (dy & 0) ? 0 : dy; // haelt die Registerzuteilung wie im Original
        if(y1>y2) { y=y1; y1=y2; y2=y; ey=y2; }
        y=y1;
        while(y<y2) {
            p5[n*2]=x1;
            p5[n++*2+1]=y++;
        }
    } else if ((int)dy==0) {
        if(x1>x2) { x=x1; x1=x2; x2=x; ex=x2; }
        x=x1;
        while(x<x2) {
            p5[n*2]=x++;
            p5[n++*2+1]=y1;
        }
    } else if((short)dx>=dy) {
        short twiceX905,errorX905,deltaX905,straightX905;
        if(x1>x2) {
            ex=x1; ey=y1; x=x2; y=y2;
            if(y2<=y1)goto plusX905; else goto minusX905;
        } else {
            x=x1;y=y1;
            if(y2<=y1)goto minusX905;
        }
        plusX905: stepy=1; goto readyX905;
        minusX905: stepy=-1;
        readyX905:
        twiceX905=V905::twice(dy);
        errorX905=twiceX905-nx;
        straightX905=twiceX905;
        deltaX905=(dy-nx)+(dy-nx);
        while((int)nx>0) {
            p5[n*2]=x;
            p5[n++*2+1]=y;
            x++;
            if((int)errorX905>=0) { dx = (dx & 0) ? 0 : dx;errorX905+=deltaX905;y+=stepy;}else errorX905+=straightX905; // haelt die Registerzuteilung wie im Original
            nx--;
        }
    } else {
        x = (x & 0) ? 0 : x; // haelt die Registerzuteilung wie im Original
        short twiceY905, errorY905, straightY905, deltaY905;
            errorY905 = (errorY905 & 0) ? 0 : errorY905; // haelt die Registerzuteilung wie im Original
        if(y1>y2) {
            ex=x1;ey=y1;x=x2;y=y2;
            if(x2<=x1)goto plusY905; else goto minusY905;
        } else {
            x=x1;y=y1;
            if(x2<=x1)goto minusY905;
        }
        plusY905: stepx=1; goto readyY905;
        minusY905: stepx=-1;
        readyY905:
        twiceY905=V905::twice(nx);
        errorY905=twiceY905-dy;
        straightY905=twiceY905;
        deltaY905=(nx-dy)+(nx-dy);
        while((int)dy>0) {
            p5[n*2]=x;
            p5[n++*2+1]=y;
            y++;
            if((int)errorY905>=0) {errorY905+=deltaY905;x+=stepx;}else errorY905+=straightY905;
            dy--;
        }
    }
    p5[n*2]=ex;p5[n*2+1]=ey;
    if(p5[0] == ox && p5[1] == oy) {
        for(i=0;(int)i<n/2;i++) {
            dx=p5[(n-i)*2];dy=p5[(n-i)*2+1];
            p5[(n-i)*2]=p5[i*2];
            p5[(n-i)*2+1]=p5[i*2+1];
            p5[i*2]=dx;p5[i*2+1]=dy;
        }
    }
    n++;
    p5[n*2]=-1;p5[n*2+1]=-1;
    return n;
}

//@ f_0ce070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion vergleicht den übergebenen Gruppenzeiger p1 mit den sechs Gruppenstrukturen im
 *   globalen Array d_1bfdbc (Schrittweite 0x61 Bytes) und ermittelt die zugehörige Gruppennummer.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf eine Gruppenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Gruppenindex (0 bis 5) oder -1, falls der Zeiger zu keinem der sechs
 *   Einträge gehört.
 === Ende Beschreibung === */
short f_0ce070(int *p1)
{
  short r = -1;
  int *q = &d_1bfdbc;
  int i = 0;
  for (; (short)i < 6; i = i + 1, q = (int *)((int)&d_1bfdbc + (short)i * 0x61)) {
    if (q == p1) r = i;
  }
  return r;
}
