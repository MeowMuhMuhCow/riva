/* === Beschreibung (Katalog) ===
 * Einheit fi_gfx (075bc0 - 076a40)
 *
 * Überblick
 * Die Einheit fi_gfx (*Fight Graphics*) verwaltet die Grafik-Engine des rundenbasierten Kampfes: das Zeichnen
 * von Gegner-Porträtfenstern (f_075bc0), die Dirty-Rectangle-Verwaltung (f_075e90, f_0762e0, f_076480), das
 * Sortieren und Rendern aller isometrischen Kampfsprites (f_0765a0) sowie die Ausgabe der geänderten
 * Bildausschnitte auf den Bildschirm (f_075f10).
 === Ende Beschreibung === */
// P3 4/6 gleich (suche.py 30.10.2026, Basis fi_gfx_P1.CPP)
// F4 Stand (Basis p3 FI_GFX_P1.CPP)
// fi_gfx.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x075BC0-0x076A40
// OPT -4r -oneatx -zp1 -s -oe=0
#include <string.h>
#include "RIVAMEM.H"

struct N { signed char s0, s1; char pad2[4]; signed char s6, s7, s8; unsigned char s9; char pa; signed char sb, sc; unsigned char sd; char pe; int p0f; int p13; N *next; };
struct L { N *first; };
struct E { unsigned char id; short x0, y0, x1, y1, z; };
struct P { int buf; char pad0[0x35]; L list; char pad1[0x1ea-0x3d]; short w1ea; char pad2[0x15]; int a201, a205, a209, a20d; char pad3[0x1cd]; E arr[255]; };
struct R { short x0, y0, x1, y1, f; };
struct B { char x[12]; };
struct SP { char x[9]; };

void f_145300(void *p, int c, int n);
void f_0762e0(short x0, short y0, short x1, short y1);
void f_075bc0(P *g, int flag, int p3);
E *f_014540(int size, const char *file, int line);
void f_076480(P *p, E *ptr, unsigned char id, short x0, short y0, short x1, short y1, short z, unsigned char flag);
int f_045080(int a, SP *s);
int f_05ded0(void *a, int b);
int f_05e2a0(void *a, void *b, void *c, void *d, void *e);
int f_05e2d0(void *a, int b, int c, int d, int e);
int f_05e320(void *a, int b, int c);
int f_05e360(void *a, void *b, void *c);
int f_05e7e0(void *a, int b, int c);
int f_05e800(void *a, void *b, void *c);
int f_069460();
int f_069c10(int q, int buf, int x, int y, int code, short *x0, short *y0, short *x1, short *y1, short *z, int flag);
unsigned short f_06a5f0(int q);
int f_06e4f0(P *p, N *n, char c);
N *f_07eb00(L *l, unsigned char idx);
int f_07e930(L *l);
int f_075930(P *p, int a, int b);
int f_078a90(P *p, N *n, short *x, short *y);
int f_078ab0(P *p, N *n);
short f_09a020();
int f_09a030(int a);
int f_0c0550(void *a, int b);
int f_0cf910x(int a);
unsigned short f_0cf910(int p);
signed char f_0cfc70(int a);
int f_0d0ac0(int a);
short f_0d0200(int p);
short f_0d0210(int p);
int f_0d0350(int a, void *b, int c, int d);
int f_0d0400(int a, int b);
int f_0d26e0();
int f_0d2710();
int f_0d3420(short a, short b, short c, short d);
int f_0d3860();
int f_0de7d0(int a, short b);
int f_0e3360(void *a);
int f_0e9660(void *a, void *b, int c, int d);
void *f_0fac10(B *b, int w, int h, int z);
void *f_0fac80(SP *s, int w, int h);
void *f_0fad20(void *b, int f);
int f_0fade0(SP *s, int a, int b, int c);
int f_0fae30(int a, int b, int x, int y, int z);
int f_0faec0(B *b, int a, int x, int y, int w, int h);
int f_0faf20(B *b, int a, int x, int y, int w, int h, int z);
int f_0fb060(B *b, int p);
int f_0fb0b0(SP *s);
int f_0fb210(int a, short *w, int *h);
int f_1481a0(void *a, int b, int c, int d, int e, int f, int g);
int f_149360(short a, int b);
extern short d_1bd920;
extern char d_1bd928;
extern R d_1bd988[];
extern signed char d_1bda50;
extern int d_1bda54;
extern int d_1bda58;
extern signed char *d_1bda5c;
extern int d_1bda60;
extern int d_1bda64;
extern int d_1bda68;
extern char d_1bdbd4[];
extern int d_1c0004;
extern char d_1c2c64[];
extern char d_1c3068[];
extern char d_1c38b0[];
extern int d_1a34e0;
extern short d_1a2744;
extern short d_1a2746;
extern char d_1a280c[];
extern N *d_1c2ecc;
extern const char d_1a1d00[];

//@ f_075bc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im Kampf das Porträt und den Namen eines Monsters p3 in die obere linke Ecke (flag ==
 *   0, aktuell agierender Gegner) oder in die untere linke Ecke (flag != 0, anvisiertes Ziel). Im
 *   Doppelgänger-/Spiegelkampf (d_1bd920 == 2) wird statt eines Monsterbildes das Porträt des entsprechenden
 *   Gruppenhelden (f_045080) geladen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g, das Positionsflag flag (0 = oben, 1 = unten) sowie den
 *   Monsterzeiger p3 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Erzeugt ein temporäres RivaRasterImage sp, liest das Monsterporträt über f_0d0400 und
 *   den Monsternamen über f_0d0350 und registriert den geänderten Bereich mit f_0762e0.
 === Ende Beschreibung === */
void f_075bc0(P *g, int flag, int p3)
{
  int f_045080x(int a, SP *b);
  #pragma aux f_045080x "f_045080" parm [eax] [edx] modify exact [eax edx ebx]
  int codex_arg_1_124; // haelt die Stapelplatzfolge wie im Original
  int codex_arg_1_128; // haelt die Stapelplatzfolge wie im Original
  char buf[40];
  short a38, a3c, a2c, a40, a30, a34;
  signed char c1, c2;
  SP *sp = 0;
  signed char y;
  if (p3 != 0) {
    f_05e2a0(d_1c38b0, &a40, &a40, &a40, &a3c);
    f_05e800(d_1c38b0, &a38, &a30);
    f_05e2d0(d_1c38b0, -1, -1, -1, 0);
    f_05e7e0(d_1c38b0, 0, 0);
    f_05e360(d_1c38b0, &a2c, &a34);
    f_05e320(d_1c38b0, 0xff, -1);
    f_05ded0(d_1c3068, g->buf);
    if (d_1bd920 == 2) {
      sp = new (mark(d_1a1d00, 0xd0)) SP; sp = sp ? (SP *)f_0fac80(sp, 0x20, 0x20) : sp;
      c1 = 0x22;
      c2 = c1;
      f_045080x(f_0de7d0(d_1c0004, (short)(((unsigned char)f_0cf910(p3)) - 1)), sp);
    } else {
      sp = new (mark(d_1a1d00, 0xdd)) SP; sp = sp ? (SP *)f_0fac80(sp, f_0d0200(p3), f_0d0210(p3)) : sp;
      f_0d0400(p3, f_0fb0b0(sp));
      c1 = f_0d0200(p3) + 2;
      c2 = f_0d0210(p3) + 2;
    }
    if ((short)flag == (short)0) {
      f_1481a0(d_1bdbd4, g->buf, 1, 9, c1, c2, -3);
      f_0d0350(p3, buf, 1, 0);
      f_0e9660(d_1c38b0, buf, 1, 1);
      f_0fade0(sp, (codex_arg_1_124 = g->buf), 2, 10);
      f_0762e0(0, 0, 100, 0x37);
    } else {
      y = c2;
      f_1481a0(d_1bdbd4, (codex_arg_1_128 = g->buf), 1, (short)(0xbf - y), c1, c2, -3);
      f_0d0350(p3, buf, 1, 0);
      f_0e9660(d_1c38b0, buf, 1, 0xc0);
      f_0fade0(sp, g->buf, 2, (short)(0xbf - (y - 1)));
      f_0762e0(0, 0x91, 100, 0xc7);
    }
    if (sp) operator delete(f_0fad20(sp, 0));
    f_05e320(d_1c38b0, a2c, a34);
    f_05ded0(d_1c3068, d_1a34e0);
    f_05e2d0(d_1c38b0, -1, -1, -1, a3c);
    f_05e7e0(d_1c38b0, a38, a30);
  }
}
//@ f_075e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob sich zwei achsenparallele Bildschirmrechtecke (p2, p3)-(p4, p5) und (p6, p7)-(p8,
 *   p9) überschneiden (jedoch nicht exakt identisch sind), um festzustellen, ob ein Dirty-Rectangle die Porträt-
 *   oder Textbereiche am Bildschirmrand überdeckt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g sowie die Koordinaten beider Rechtecke (short) und gibt 1
 *   bei Überschneidung oder 0 zurück.
 * - Wichtige Variablen: Ruft bei gesetztem d_1bd928 zwischendurch f_069460 auf.
 === Ende Beschreibung === */
int f_075e90(P *g, short p2, short p3, short p4, short p5, short p6, short p7, short p8, short p9)
{
  int r = 0;
  if (d_1bd928) f_069460();
  if (p2 == p6 && p3 == p7 && p4 == p8 && p5 == p9) r = 0;
  else if (((p2 >= p6 && p2 <= p8) || (p4 >= p6 && p4 <= p8)) && ((p3 >= p7 && p3 <= p9) || (p5 >= p7 && p5 <= p9))) r = 1;
  return r;
}
//@ f_075f10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Überträgt alle in der Dirty-Rectangle-Liste d_1bd988 gesammelten geänderten Bildausschnitte
 *   aus dem Offscreen-Puffer g->buf auf den sichtbaren VGA-Bildschirm d_1a34e0. Schneidet eines der Rechtecke
 *   die Helden-/Monster-Infoboxen oben links (d_1bda60), unten links (d_1bda64) oder die Statuszeile unten
 *   (d_1bda68), werden diese UI-Elemente zuvor neu in den Puffer eingezeichnet.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (P *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durchläuft das Array d_1bd988 bis zum Endmarker x0 == -1 und blendet während des
 *   Kopierens eines unter dem Mauszeiger liegenden Rechtecks (f_0d3420) den Mauszeiger kurzzeitig aus
 *   (f_0d2710/f_0d26e0).
 === Ende Beschreibung === */
#pragma inline_depth(0)
void f_075f10(P *g)
{
  int snd;
  B b;
  int col;
  short v18;
  short v38;
  int done;
  short sa;
  short i;
  short j;

  i = 0;
  done = 0;
  col = 0;
  snd = 0;
  f_0fac10(&b, 0x140, 0xc8, 0);
  snd = 0;
  if (f_0e3360(d_1c2c64)) {
    f_0c0550(d_1c2c64, g->buf);
    col = 1;
  }
  while (d_1bd988[i].x0 != -1) {
    short x1;
    short y0;
    short y1;
    short x0;
    x1 = d_1bd988[i].x1;
    x0 = d_1bd988[i].x0;
    y0 = d_1bd988[i].y0;
    y1 = d_1bd988[i].y1;
    if (f_075e90(g, x0, y0, x1, y1, 0, 0, 0x64, 0x37)) d_1bda60 = 1;
    if (f_075e90(g, x0, y0, x1, y1, 0, 0x91, 0x64, 0xc7)) d_1bda64 = 1;
    if (f_075e90(g, x0, y0, x1, y1, 0, 0xc0, 0x12c, 0xc7)) d_1bda68 = 1;
    i++;
  }
  if (d_1bda60) {
    if (g->a201) f_075930(g, 0, g->a201);
    else if (g->a205) f_075bc0(g, 0, g->a205);
    d_1bda60 = 0;
  }
  if (d_1bda64) {
    if (g->a209) f_075930(g, 1, g->a209);
    else if (g->a20d) f_075bc0(g, 1, g->a20d);
    d_1bda64 = 0;
  }
  if (d_1bda68) {
    if (!*d_1bda5c) {
      f_145300(d_1bda5c, 0x20, 0x32);
      // Haelt die globale Zeiger-Lebensdauer wie im Original.
      d_1bda5c = (signed char *)(((int)d_1bda5c & 0) ? 0 : (int)d_1bda5c);
      snd = 1;
      d_1bda5c[0x32] = 0;
    }
    if (*d_1bda5c != 1) {
      f_05e360(d_1c38b0, &v38, &v18);
      f_05e320(d_1c38b0, 0xff, -1);
      f_05ded0(d_1c3068, g->buf);
      f_0e9660(d_1c38b0, d_1bda5c, 1, 0xc0);
      f_05e320(d_1c38b0, v38, v18);
      // Haelt die globale Ladefolge wie im Original.
      d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0;
      f_05ded0(d_1c3068, d_1a34e0);
    } else {
      *d_1bda5c = 0;
    }
    if (snd) *d_1bda5c = 0;
    f_0762e0(0, 0xc0, 0x12c, 0xc7);
    d_1bda68 = 0;
  }
  j = 0;
  while (d_1bd988[j].x0 != -1) {
    f_0fb060(&b, (int)(*(char **)g + d_1bd988[j].y0 * 0x140 + d_1bd988[j].x0)); // buf als Zeiger gelesen (Original faltet [esi] nicht)
    short x0 = d_1bd988[j].x0;
    short x1 = d_1bd988[j].x1;
    short y0 = d_1bd988[j].y0;
    short y1 = d_1bd988[j].y1;
    if (f_0d3420(x0, y0, x1, y1)) {
      if (f_0d3860() == 1) {
        done = 1;
        f_0d2710();
      }
    }
    if (col) {
      { short r = f_09a020(); sa = r; sa = r; } // haelt die Registerfolge von sa wie im Original
      f_09a030(0xff);
      f_0faf20(&b, d_1a34e0, x0, y0, (short)(x1 - x0 + 1), (short)(y1 - y0 + 1), 1);
      f_09a030((unsigned char)sa);
    } else {
      { int w; // haelt die Breitenberechnung auf dem Stapel wie im Original
      f_0faec0(&b, d_1a34e0, x0, y0, (w = (short)(x1 - x0 + 1), w = (short)(x1 - x0 + 1)), (short)(y1 - y0 + 1)); }
    }
    if (done) {
      f_0d26e0();
      done = 0;
    }
    j++;
  }
  d_1bda54 = 0;
  f_0fad20(&b, 0);
}

#pragma inline_depth(3)
//@ f_0762e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt ein geändertes Bildschirmrechteck (x0, y0)-(x1, y1) (geclippt auf 0..319 und 0..199) in
 *   die Dirty-Rectangle-Liste d_1bd988 ein. Werden mehr als 19 Einzelrechtecke (0x13) gemeldet, schaltet die
 *   Funktion automatisch auf ein einziges Vollbild-Update (0, 0, 319, 199) mit gesetztem Vollbild-Flag d_1bda58
 *   = 1 um.
 * - Eingaben und Rückgabe: Empfängt die Eckkoordinaten x0, y0, x1 und y1 (short) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Verwaltet den Zähler d_1bda50, das Vollbild-Flag d_1bda58 und das Array d_1bd988.
 === Ende Beschreibung === */
static inline void s0_490(int idx, int v) { d_1bd988[idx].x0 = v; }
static inline void sy0_490(int idx, int v) { d_1bd988[idx].y0 = v; }
static inline void sx1_170(int idx, short v) { d_1bd988[idx].x1 = (short)(v); }
void f_0762e0(short x0, short y0, short x1, short y1)
{
  if (d_1bda58 != 0) return;
  if (x0 == x1 && y0 == y1) return;
  if (d_1bda50 == 0x13) {
    d_1bd988[0].x0 = 0;
    d_1bd988[0].y0 = 0;
    d_1bd988[0].x1 = 0x13f;
    d_1bd988[0].y1 = 0xc7;
    d_1bd988[0].f = 1;
    d_1bda58 = 1;
    return;
  }
  if ((x0 < 0 && x1 < 0) || (x0 > 0x13f && x1 > 0x13f) ||
      (y0 < 0 && y1 < 0) || (y0 > 0xc7 && y1 > 0xc7)) return;

  s0_490(d_1bda50, x0 < 0 ? 0 : (x0 > 0x13f ? 0x13f : x0));
  sy0_490(d_1bda50, y0 < 0 ? 0 : (y0 > 0xc7 ? 0xc7 : y0));
  short xc = x1 < 0 ? 0 : (x1 > 0x13f ? 0x13f : x1);
  sx1_170(d_1bda50, xc);
  short v = y1 < 0 ? 0 : (y1 > 0xc7 ? 0xc7 : y1);
  int i = d_1bda50;
  d_1bd988[i].y1 = (short)(v);
  d_1bd988[i].f = 1;
  ++d_1bda50;
}
//@ f_076480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vergleicht das aktuelle Bildschirmrechteck und die Tiefenebene z eines Kampfsprites id mit
 *   dessen vorheriger Position im Array ptr. Hat sich das Sprite bewegt, vergrößert oder seine Tiefe geändert
 *   (oder ist es neu hinzugekommen bzw. verschwunden), wird das umschließende Rechteck aus alter und neuer
 *   Position über f_0762e0 als neu zu zeichnend markiert.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p, das Vergleichsarray ptr, die Sprite-ID id, die
 *   Koordinaten x0, y0, x1, y1, den Tiefenwert z sowie das Richtungsflag flag (0 = neu gegen alt, 1 = alt gegen
 *   neu) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durchsucht ptr bis zum Endmarker id == 0xff.
 === Ende Beschreibung === */
void f_076480(P *p, E *ptr, unsigned char id, short x0, short y0, short x1, short y1, short z, unsigned char flag)
{
  short i = 0;
  short found = -1;
  while (ptr[i].id != 0xff) {
    if (ptr[i].id == id) {
      found = i;
      break;
    }
    i++;
  }
  if (found == -1) {
    f_0762e0(x0, y0, x1, y1);
    return;
  }
  if (flag) return;
  if (ptr[found].x0 == x0 && ptr[found].x1 == x1 &&
      ptr[found].y0 == y0 && ptr[found].y1 == y1 &&
      ptr[found].z == z) return;
  f_0762e0(ptr[found].x0 < x0 ? ptr[found].x0 : x0,
           ptr[found].y0 < y0 ? ptr[found].y0 : y0,
           ptr[found].x1 > x1 ? ptr[found].x1 : x1,
           ptr[found].y1 > y1 ? ptr[found].y1 : y1);
}
//@ f_0765a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet sämtliche sichtbaren Objekte und Figuren der Kampfszene (p->list) in isometrischer
 *   Tiefenreihenfolge in den Offscreen-Puffer p->buf, speichert ihre aktuellen Bildschirmrechtecke in p->arr,
 *   vergleicht diese über f_076480 mit den Rechtecken des vorherigen Frames (old), um Dirty-Rectangles zu
 *   erzeugen, und stößt bei Animations-Triggern (rc != 0) über f_06e4f0 Folgeeffekte oder Sounds an.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p (P *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Rechnet die Rasterkoordinaten (s0, s1) mit dem Ursprung (d_1a2744, d_1a2746) über x = x0
 *   + (s0 + s1) * 10 und y = y0 + (s0 - s1) * 5 in isometrische Bildschirmkoordinaten um und sortiert die Liste
 *   anschließend mit f_07e930.
 === Ende Beschreibung === */
static inline N *l_first(L *l) { return l->first; }
void f_0765a0(P *p)
{
  signed char c8;
  short cnt = 0;
  short i;
  short dir;
  N *n;
  short h;
  int skip = 0;
  short w;
  E *old;
  short s1;
  short x;
  short rc;
  short y;
  N *m;
  short s0;

  old = f_014540(0xaf5, d_1a1d00, 0x246);
  // Haelt die Zeiger-Lebensdauer von old wie im Original.
  old = (E *)(((unsigned)old & 0) ? 0 : (unsigned)old);
  memcpy(old, p->arr, 0xaf5);
  f_145300(p->arr, 0, 0xaf5);
  n = l_first(&p->list);
  // Haelt die Zeiger-Lebensdauer von n wie im Original.
  n = ((unsigned)n & 0) ? (N *)0 : n;
  do {
    if (n->sb == 1 && n->p13 != 0) {
      f_0fb210(n->p13, &w, (int *)&h); // Fremder Prototyp fuehrt den 3. Parameter als int*, uebergeben wird short* &h.
      s0 = n->s0;
      s1 = n->s1;
      x = d_1a2744 - w / 2 + (s0 + s1) * 10;
      y = d_1a2746 - h + (s0 - s1) * 5;
      x += n->s7;
      y += n->s8;
      f_0fae30(n->p13, p->buf, x, y, 1);
      p->arr[cnt].id = n->s9;
      p->arr[cnt].x0 = x;
      p->arr[cnt].y0 = y;
      p->arr[cnt].x1 = x + w;
      p->arr[cnt].y1 = y + h;
      p->arr[cnt].z = n->s6;
      if (!d_1bda58) {
        f_076480(p, old, p->arr[cnt].id, p->arr[cnt].x0, p->arr[cnt].y0, p->arr[cnt].x1, p->arr[cnt].y1, p->arr[cnt].z, 0);
      }
      cnt++;
    } else if (n->sb == 1 && (n->p0f != 0 || (n->sd > 0x14 && n->sd != (unsigned char)0xff))) {
      m = n;
      if (n->sd != (unsigned char)0xff && n->sd > 0x14) {
        m = f_07eb00(&p->list, n->sd - 0x14);
      }
      if (((signed char (*)(int))f_06a5f0)(m->p0f) == 0) { // Fremder Prototyp liefert unsigned short, Original prueft als signed char (al).
        m->s7 = m->s0;
        m->s8 = m->s1;
      }
      s0 = m->s7;
      s1 = m->s8;
      x = d_1a2744 + (s0 + s1) * 10;
      y = d_1a2746 + (s0 - s1) * 5;
      if ((short)f_149360(p->w1ea, (int)d_1a280c) != -1 && m->sc == 1) {
        f_078a90(p, m, &x, &y);
      }
      dir = 0;
      if (n->sd != (unsigned char)0xff) {
        c8 = f_0cfc70(f_0d0ac0(m->s9));
        if (n->sd > 0x14) {
          dir = (c8 == 0) ? 1 : (c8 == 1) ? 4 : (c8 == 2) ? 2 : 3;
        } else if (c8 == 0) {
          dir = 2;
        } else {
          dir = (c8 == 1) ? (short)3 : (c8 == 2) ? (short)1 : (short)4;
        }
      }
      p->arr[cnt].id = m->s9;
      rc = f_069c10(m->p0f, p->buf, x, y, (signed char)dir,
                    &p->arr[cnt].x0, &p->arr[cnt].y0, &p->arr[cnt].x1, &p->arr[cnt].y1, &p->arr[cnt].z,
                    (n->sd != (unsigned char)0xff && n->sd > 0x14) ? 1 : 0);
      if (!d_1bda58) {
        f_076480(p, old, p->arr[cnt].id, p->arr[cnt].x0, p->arr[cnt].y0, p->arr[cnt].x1, p->arr[cnt].y1, p->arr[cnt].z, 0);
      }
      cnt++;
      skip = 0;
      if ((short)f_149360(p->w1ea, (int)d_1a280c) != -1) {
        skip = f_078ab0(p, m);
      }
      if (!skip) {
        if (rc != 0 && rc != 9 && rc != 10) {
          f_06e4f0(p, n, (char)rc);
        }
      }
    }
    n = n->next;
  } while (n != d_1c2ecc);
  p->arr[cnt++].id = 0xff;
  f_07e930(&p->list);
  i = 0;
  while (!d_1bda58 && old[i].id != 0xff) {
    f_076480(p, p->arr, old[i].id, old[i].x0, old[i].y0, old[i].x1, old[i].y1, old[i].z, 1);
    i++;
  }
  delete old;
}
