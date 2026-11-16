/* === Beschreibung (Katalog) ===
 * Einheit numinput
 *
 * Diese Einheit gehört zu numinput.cpp und implementiert den Konstruktor des grafischen
 * Mehrstellen-Zahleneingabefeldes (genutzt u. a. beim Aufteilen von Gegenstandsstapeln, bei Geldbeträgen oder
 * Zahlenschlössern).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 29.10.2026, Basis numinput_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 0 gleich (vorher 0), Rest 114 (vorher 133)
// numinput.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D6710-0x0D6AB0
#include <string.h>
struct Obj9 { char c[9]; };


int f_15ec70(int p1);
int f_15eca0(int p1, int);
int f_15f130(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
extern const char d_1a5aa0[];
#define NEWOBJ1(off, line, a, b) tag = mark(d_1a5aa0, line); u = 1; t = new (tag) Obj9; if (t) t = (Obj9 *)((int)(((RivaRasterImage*)((int)t))->f_0fac80( a, b))); *(int *)(p1 + off) = (int)t;
#define NEWOBJ(off, line, a, b) t = new (mark(d_1a5aa0, line)) Obj9; if (t) t = (Obj9 *)((int)(((RivaRasterImage*)((int)t))->f_0fac80( a, b))); *(int *)(p1 + off) = (int)t;
#define CALL(off, k) f_15f130((int)loc34, ((int)(((RivaRasterImage*)(*(int *)(p1 + off)))->f_0fb0b0())), p3, k, 0, (int)loc10, (int)loc10, 0x140);
//@ f_0d6710
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Zahleneingabe-Objekt p1 mit p2 Ziffernstellen (maximal 5), legt
 *   sieben kleine Grafik-Sprites (Ziffernhintergrund 13x16, OK-Schaltfläche ungedrückt/gedrückt 34x16 sowie
 *   Auf-/Ab-Pfeiltasten 13x7, Indizes 14 bis 20) an, entpackt deren Grafiken aus dem Puffer p3, speichert den
 *   zulässigen Wertebereich [p4, p5] und zerlegt den Startwert p6 in seine einzelnen Dezimalziffern ab Offset
 *   +0x0e.
 * - Eingaben: Übergeben werden der this-Zeiger p1, die Ziffernanzahl p2, der Grafikdatenpuffer p3, der
 *   Minimalwert p4, der Maximalwert p5 sowie der anzuzeigende Startwert p6.
 * - Rückgabewert: Zurückgegeben wird der initialisierte Objektzeiger p1.
 === Ende Beschreibung === */
int f_0d6710(int p1, int p2, int p3, int p4, int p5, short p6)
{
  char image[28];
  short tmp;
  short power;
  short i, j;
  f_15ec70((int)image);
  *(int *)(p1+0x33)=0;
  { int t=(int)operator new(9,mark(d_1a5aa0,57));
    power=1;
    *(int *)(p1+23)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(13,16))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,58));
    *(int *)(p1+27)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(34,16))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,59));
    *(int *)(p1+31)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(34,16))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,60));
    *(int *)(p1+35)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(13,7))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,61));
    *(int *)(p1+39)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(13,7))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,62));
    *(int *)(p1+43)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(13,7))) : t; }
  { int t=(int)operator new(9,mark(d_1a5aa0,63));
    *(int *)(p1+47)=t ? ((int)(((RivaRasterImage*)(t))->f_0fac80(13,7))) : t; }
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+23)))->f_0fb0b0())),p3,14,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+27)))->f_0fb0b0())),p3,19,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+31)))->f_0fb0b0())),p3,20,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+35)))->f_0fb0b0())),p3,15,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+39)))->f_0fb0b0())),p3,16,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+43)))->f_0fb0b0())),p3,17,0,(int)&tmp,(int)&tmp,0x140);
  f_15f130((int)image,((int)(((RivaRasterImage*)(*(int *)(p1+47)))->f_0fb0b0())),p3,18,0,(int)&tmp,(int)&tmp,0x140);
  if ((short)p4<0) p4=0;
  if ((short)p5<0) p5=32000;
  if ((int)p6<0) { p6=32000; p6=32000; p6=32000; p6=32000; } // haelt die Registerzuteilung wie im Original
  short len=(p2 & 0) ? 0 : p2; // haelt die Registerzuteilung wie im Original
  if (len>(short)5) len=5;
  *(short *)(p1+8)=len;
  if (!p6) {
    i=0;
    while(i<*(short *)(p1+8)) {
      *(char *)(p1+(int)i+0xe)=0;
      ++i;
    }
  } else {
    for(i=0;(int)i<*(short *)(p1+8)-1;i++) power*=10;
    j=0;
    if (j>=*(short *)(p1+8)) goto digits_done;
    {
      int q;
      goto digit;
lastdigit:
      *(char *)(q+0xe)=p6;
nextdigit:
      ++j;
      if (j>=*(short *)(p1+8)) goto digits_done;
digit:
      q=p1+(int)j;
      if ((int)j==*(short *)(p1+8)-1) goto lastdigit;
      *(char *)(q+0xe)=(int)p6/(int)power;
      p6%=power;
      power/=(short)10;
      goto nextdigit;
    }
digits_done:;
  }
  *(short *)(p1+0x15)=p4;
  *(short *)(p1+0xc)=0;
  *(short *)(p1+0x13)=p5;
  *(short *)(p1+6)=0xe;
  f_15eca0((int)image,0);
  return p1;
}
