/* === Beschreibung (Katalog) ===
 * Einheit screensa
 *
 * Diese Einheit implementiert die vier grafischen Bildschirmschoner-Effekte (screensa für Screensaver) von
 * *Schatten über Riva*, die bei längerer Inaktivität des Spielers den aktuellen Bildschirminhalt sichern und
 * unterschiedliche geometrische oder bildbasierte Echtzeitanimationen abspielen, bis eine Taste gedrückt oder
 * die Maus bewegt wird.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 0/4 gleich (suche.py 26.10.2026, Basis screensa_P1.CPP)
// screensa.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F04C0-0x0F12F0
#include <string.h>
#include <bios.h>
#include <math.h>
#pragma intrinsic(memcpy)
int f_014540(int p1, int p2, int p3);
int f_099ea0();
int f_0d4163(int p1);
int f_0d4880(int p1);
int f_13e240();
int f_13f8c0();
int f_13f8d0();
int f_144570();
int f_1457e0(int p1);
int f_146dfa(int p1, int p2);
int f_149d20();
void f_148534(int p1);
extern unsigned char *d_1a34e0;
extern short d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fc;
extern short d_1bf4fe;
extern int d_1bf4e8;
extern int d_1c0170;
extern int d_1c0174;
extern short d_1c219e;
extern int d_1c2e78;
extern int d_1c2edc;
extern const char d_1a66b8[];
void f_0f04c0(int p1);
void f_0f0790(int p1);
void f_0f09b0(int p1);
void f_0f1020(int p1);

//@ f_0f04c0  groesse 720 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den ersten Bildschirmschoner aus, der einen 32x32 Pixel großen Bildausschnitt
 *   aus der Bildschirmmitte ausschneidet, den Bildschirm abdunkelt und das ausgeschnittene Kachelbild mit
 *   wechselnden Geschwindigkeiten und Rotationswinkeln (f_0cd690) quer über den Bildschirm prallen lässt.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik- beziehungsweise Bildschirmpuffer-Kontext (p1).
 * - Rückgabewert: Die Funktion gibt das Ergebnis der abschließenden Bildschirmwiederherstellung zurück, sobald
 *   der Benutzer den Bildschirmschoner beendet.
 === Ende Beschreibung === */
static inline void h_f04c0_copy(void *dst,void *src,unsigned n)
{
  d_1bf4e8 = (d_1bf4e8 & 0) ? 0 : d_1bf4e8; // haelt die Symbol- und Registerfolge in f_0f04c0 wie im Original
  d_1c0174 = (d_1c0174 & 0) ? 0 : d_1c0174; // haelt die Symbol- und Registerfolge in f_0f04c0 wie im Original
  memcpy(dst,src,n);
}
static inline void h_f04c0_event(int owner)
{
  f_099ea0();
  if(_bios_keybrd(1)) {
    if(_bios_keybrd(0)==0x1011) { f_144570(); f_148534(0); }
    else { f_0d4880(owner); f_149d20(); }
  }
  if(d_1bf4e8) { f_0d4880(owner); d_1bf4e8=0; }
  if(d_1bf4f0!=d_1bf4fc || d_1bf4f2!=d_1bf4fe) f_0d4880(owner);
  if(d_1c219e==1) {
    f_0d4163((int)&d_1c2e78);
    f_146dfa((int)&d_1c2edc,1);
    d_1c219e=0;
  }
}
static inline int h_f04c0_poll(int arg)
{
  int owner=arg; owner=arg; // haelt die Nutzungsgewichtung von owner vor k wie im Original
  short flag=0;
  d_1c0170|=d_1c0174;
  short k;
  for(k=0;k<(short)9;k++) {
    if(d_1c0170) {
      h_f04c0_event(owner);
      if(!d_1c0170 && d_1c0174) { d_1c0174=0; d_1c0170=1; }
    } else { flag=1; break; }
  }
  return flag;
}
void f_0f04c0(int p1)
{
  (void)&p1; // haelt p1 auf dem Stapel wie im Original
  short h,w;
  w=f_13f8c0();
  short oldy,oldx; oldx=0; oldy=0;
  h=f_13f8d0();
  int stop=0;
  int fra;
  int na=(int)operator new(9,mark(d_1a66b8,0xb6));
  fra=na ? ((int)(((RivaRasterImage*)(na))->f_0fac80(32,20))) : na;
  int nb=(int)operator new(9,mark(d_1a66b8,0xb7));
  int result=nb ? ((int)(((RivaRasterImage*)(nb))->f_0fac80(32,20))) : nb;
  int base=(int)d_1a34e0;
  ((RivaRasterImage*)(fra))->f_0fafb0((void *)(base),0,0);
  for(;;) {
    if(stop) break;
    short tx,ty;
    do {
      tx=f_1457e0((short)(w/32))-1;
      ty=f_1457e0((short)(h/20))-1;
    } while(tx==oldx && ty==oldy);
    oldy=ty;
    oldx=tx;
    short y=ty*20;
    short x=tx*32;
    ((RivaRasterImage*)(result))->f_0fafb0((void *)((int)d_1a34e0),x,y);
    ((RivaRasterImage*)(fra))->f_0fade0((void *)((int)d_1a34e0),x,y);
    d_1a34e0 = (unsigned char *)(((int)d_1a34e0 & 0) ? 0 : (int)d_1a34e0); // haelt die Registerfolge nach f_0fade0 wie im Original
    int src=((int)(((RivaRasterImage*)(result))->f_0fb0b0()));
    int dst=((int)(((RivaRasterImage*)(fra))->f_0fb0b0()));
    h_f04c0_copy((void*)dst,(void*)src,640);
    if(h_f04c0_poll(p1)) { stop=1; break; }
  }
  if(fra) operator delete((void*)((int)(((RivaRasterImage*)(fra))->f_0fad20(0))));
  if(result) operator delete((void*)((int)(((RivaRasterImage*)(result))->f_0fad20(0))));
}

//@ f_0f0790  groesse 544 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den zweiten Bildschirmschoner aus, der ein rotierendes und im Raum schwingendes
 *   3D-Punktgitter aus 8x8 Knotenpunkten über die 3D-Projektionsroutinen (f_13f6e0, f_13f470) auf den
 *   abgedunkelten Bildschirm zeichnet.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Bildschirmwiederherstellung nach dem Aufwecken zurück.
 === Ende Beschreibung === */
static inline void h_f0790_event(int owner)
{
  f_099ea0();
  if (_bios_keybrd(1)) {
    if (_bios_keybrd(0) == 0x1011) { f_144570(); f_148534(0); }
    else { f_0d4880(owner); f_149d20(); }
  }
  if (d_1bf4e8 != 0) { f_0d4880(owner); d_1bf4e8 = 0; }
  if (d_1bf4f0 != d_1bf4fc || d_1bf4f2 != d_1bf4fe) f_0d4880(owner);
  if (d_1c219e == 1) {
    f_0d4163((int)&d_1c2e78);
    f_146dfa((int)&d_1c2edc, 1);
    d_1c219e = 0;
  }
}
static inline int h_f0790_poll(int owner, short limit)
{
  short result = 0;
  short k;
  d_1c0170 |= d_1c0174;
  for (k = 0; k < limit; ++k) {
    if (d_1c0170) {
      h_f0790_event(owner);
      if (!d_1c0170 && d_1c0174) {
        d_1c0174 = 0;
        d_1c0170 = 1;
      }
    } else { result = 1; break; }
  }
  // haelt die Nutzungsgewichtung von result fuer die Registervergabe wie im Original
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  { short u_ = result; result = u_; }
  return result;
}
#define RND ((short (*)(short))f_1457e0)
void f_0f0790(int p1)
{
  unsigned char *screen;
  int dir;
  unsigned swaps;
  short i, x1, y2, x2, y1;
  unsigned char cb, ca, *a, *b;
  screen = d_1a34e0;
  dir = 0; swaps = 0;
  do {
    // haelt die Nutzungsgewichtung von p1 fuer die Registervergabe wie im Original
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    { int u_ = p1; p1 = u_; }
    for (i = 0; i < 50; ++i) {
      x1 = x2 = RND(319) - 1;
      y1 = y2 = RND(199) - 1;
      switch ((unsigned short)RND(2)) { case 0: break; case 1: ++x2; break; case 2: ++y2; break; }
      a = &screen[y1 * 320 + x1];
      b = &screen[y2 * 320 + x2];
      ca = *a; cb = *b;
      if (dir == 1) { if (ca < cb) { *a = cb; *b = ca; ++swaps; } }
      else { if (ca > cb) { *a = cb; *b = ca; ++swaps; } }
    }
    if (swaps < 10) dir = !dir;
    swaps = 0;
  } while (!h_f0790_poll(p1, 1));
}
#undef RND
//@ f_0f09b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den dritten Bildschirmschoner aus, der den aktuellen Bildschirminhalt
 *   schrittweise auf den Kopf und seitenverkehrt stellt, indem er zufällig benachbarte Bildschirmzeilen (0..199)
 *   und Bildspalten (0..319) miteinander vertauscht (Bubble-Reversal), bis das gesamte Bild gespiegelt ist oder
 *   der Spieler eine Eingabe tätigt.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Wiederherstellen des ursprünglichen Bildschirminhalts
 *   zurück.
 === Ende Beschreibung === */
struct Pair09 { short x,y; };
struct Flags09 { int running,active; };
#define rand_f09b0 ((short (*)(short))f_1457e0) // ruft f_1457e0 mit 16-Bit-Parameter und -Rueckgabe auf wie im Original
static inline void h_f09b0_event(int owner)
{
  f_099ea0();
  if (_bios_keybrd(1)) {
    if (_bios_keybrd(0) == 0x1011) { f_144570(); f_148534(0); }
    else { f_0d4880(owner); f_149d20(); }
  }
  if (d_1bf4e8 != 0) { f_0d4880(owner); d_1bf4e8 = 0; }
  if ((((Pair09 *)&d_1bf4f0)->x) != (((Pair09 *)&d_1bf4fc)->x) || (((Pair09 *)&d_1bf4f0)->y) != (((Pair09 *)&d_1bf4fc)->y)) f_0d4880(owner);
  if (d_1c219e == 1) {
    f_0d4163((int)&d_1c2e78);
    f_146dfa((int)&d_1c2edc, 1);
    d_1c219e = 0;
  }
}
static inline int h_f09b0_poll(int owner, short n)
{
  short result = 0;
  short k;
  (((Flags09 *)&d_1c0170)->running) |= (((Flags09 *)&d_1c0170)->active);
  for (k = 0; k < n; ++k) {
    if ((((Flags09 *)&d_1c0170)->running)) {
      h_f09b0_event(owner);
      if (!(((Flags09 *)&d_1c0170)->running) && (((Flags09 *)&d_1c0170)->active)) {
        (((Flags09 *)&d_1c0170)->active) = 0;
        (((Flags09 *)&d_1c0170)->running) = 1;
      }
    } else { result = 1; break; }
  }
  { int u_ = owner; owner = u_; } // haelt die Nutzungsgewichtung von owner wie im Original
  return result;
}

static inline int h_f09b0_pollb(int owner, short n)
{
  short result = 0;
  short k;
  (((Flags09 *)&d_1c0170)->running) |= (((Flags09 *)&d_1c0170)->active);
  for (k = 0; k < n; ++k) {
    if ((((Flags09 *)&d_1c0170)->running)) {
      h_f09b0_event(owner);
      if (!(((Flags09 *)&d_1c0170)->running) && (((Flags09 *)&d_1c0170)->active)) {
        (((Flags09 *)&d_1c0170)->active) = 0;
        (((Flags09 *)&d_1c0170)->running) = 1;
      }
    } else { result = 1; break; }
  }
  return result;
}

void f_0f09b0(int p1)
{
  short cols[320];
  short rows[200];
  int stop;
  signed char mode;
  unsigned char *base;
  unsigned char *tmp;
  int need_init;
  short step;
  short i;
  unsigned short c2;

  stop = 0;
  mode = 0;
  base = d_1a34e0;
  tmp = base + 0xfa00;
  need_init = 1;
  step = 0;
  c2 = 0;
  do {
    for (step = 0; step < 25; step++) {
      if (need_init == 1) {
        mode = rand_f09b0(2) - 1;
        need_init = 0;
        for (i = 0; i < 200; i++) rows[i] = i;
        for (i = 0; i < 320; i++) cols[i] = i;
      }
      if (mode == 0) {
        unsigned short r1, r2;
        do {
          r1 = (r2 = rand_f09b0(199)) - 1;
        } while (rows[r1] > rows[r2]);
        int off1 = r1 * 320;
        int off2 = r2 * 320;
        memcpy(tmp, base + off1, 320);
        memcpy(base + off1, base + off2, 320);
        memcpy(base + off2, tmp, 320);
        short t = rows[r1];
        rows[r1] = rows[r2];
        rows[r2] = t;
        for (i = 0; i < 200; i++) {
          if (rows[i] != 199 - i) break;
        }
        if (i == 200) {
          if (h_f09b0_poll(p1, 60)) { stop = 1; break; }
          need_init = 1;
        }
      } else {
        unsigned short c1;
        do {
          c1 = (c2 = rand_f09b0(319)) - 1;
        } while (cols[c1] > cols[c2]);
        unsigned char *p = base;
        for (i = 0; i < 200; i++) {
          unsigned char tc = p[c1];
          p[c1] = p[c2];
          p[c2] = tc;
          p += 320;
        }
        short t = cols[c1];
        cols[c1] = cols[c2];
        cols[c2] = t;
        for (i = 0; i < 320; i++) {
          if (cols[i] != 319 - i) break;
        }
        if (i == 320) {
          if (h_f09b0_pollb(p1, 60)) { stop = 1; break; }
          need_init = 1;
        }
      }
    }
    if (h_f09b0_poll(p1, 1)) break;
  } while (!stop);
}

//@ f_0f1020  groesse 700 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion implementiert den vierten Bildschirmschoner, der einen 32x32-Bildausschnitt entlang
 *   zweier überlagerter Sinus- und Kosinus-Kreisbahnen (Lissajous-Kurve über f_13f670 und f_13f590) über den
 *   Bildschirm wandern lässt; wegen eines Off-by-One-Fehlers beim Zufallswurf in f_0f12f0 (f_1457e0(3) statt
 *   f_1457e0(4)) wird dieser vierte Effekt im fertigen Spiel jedoch nie ausgewählt.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Wiederherstellen des Bildschirms zurück.
 === Ende Beschreibung === */
static inline void h_f1020_event(int owner)
{
  f_099ea0();
  if (_bios_keybrd(1)) {
    if (_bios_keybrd(0) == 0x1011) { f_144570(); f_148534(0); }
    else { f_0d4880(owner); f_149d20(); }
  }
  if (d_1bf4e8) { f_0d4880(owner); d_1bf4e8 = 0; }
  if (d_1bf4f0 != d_1bf4fc || d_1bf4f2 != d_1bf4fe) f_0d4880(owner);
  if (d_1c219e == 1) {
    f_0d4163((int)&d_1c2e78);
    f_146dfa((int)&d_1c2edc, 1);
    d_1c219e = 0;
  }
}

static inline int f1020_poll(int owner, short n)
{
  short flag = 0;
  d_1c0170 |= d_1c0174;
  short k;
  for (k = 0; k < n; k++) {
    if (d_1c0170) {
      h_f1020_event(owner);
      if (!d_1c0170 && d_1c0174) { d_1c0174 = 0; d_1c0170 = 1; }
    } else { flag = 1; break; }
  }
  return flag;
}

static inline void h_f12f0(int p1)
{
  if (f_13e240() != 0) { f_0f04c0(p1); return; }
  switch ((short)f_1457e0(3)) {
  case 1: f_0f04c0(p1); return;
  case 2: f_0f0790(p1); return;
  case 3: f_0f09b0(p1); return;
  case 4: f_0f1020(p1); return;
  }
}

void f_0f1020(int p1)
{
  int done;
  unsigned char *base;
  short tab[360];
  short i;
  void *buf;
  short x;
  short y;
  done = 0;
  base = d_1a34e0;
  buf = (void *)f_014540(0xfa00, (int)d_1a66b8, 0x1a3);
  if (!buf) {
    h_f12f0(p1);
    return;
  }
  memcpy(buf, base, 0xfa00);
  for (i = 0; i < 360; i++) {
    tab[i] = (short)(sin((double)i * (3.1415 / 180.0)) * 100.0);
  }
  for (;;) {
    if (done) break;
    for (i = 0; i < 360; i++) {
      x = (i & 0) ? (short)0 : (short)(tab[i % 360] + 160); // haelt die Mehrblock-Definition von x fuer die Registervergabe wie im Original
      y = tab[(i + 90) % 360] + 100;
      base[y * 320 + x] = 0xff;
    }
    if (f1020_poll(p1, 1)) { done = 1; break; }
  }
  operator delete(buf);
}
