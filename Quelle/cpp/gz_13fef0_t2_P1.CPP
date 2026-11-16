/* === Beschreibung (Katalog) ===
 * Einheit gz_13fef0_t2 (0x140220 - 0x1407A0)
 *
 * Überblick
 *
 * Die Einheit gz_13fef0_t2 implementiert das grafische Steuerelement für vertikale Bildlaufleisten (vslider),
 * das in Listen-, Buch-, Inventar- und Dialogfenstern der Benutzeroberfläche eingesetzt wird. Sie verwaltet
 * Position und Höhe der Leiste, den prozentualen sichtbaren Anteil (a), die relative Schieberposition (b in
 * Prozent), die daraus berechnete Pixelhöhe (t) und Pixelposition (p) des Schiebereglers, das Zeichnen aus vier
 * Teilgrafiken (g0 bis g3) sowie das interaktive Ziehen des Reglers mit der Maus.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 17/22 gleich (suche.py 26.10.2026, Basis gz_13fef0_P1.CPP)
// gz_13fef0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13FEF0-0x1407A0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int f_099ea0();
typedef int GP;
int f_0bd350(int a, int b, int c);


int f_0d3780();

int f_0d38b0(void *p);
int f_0d38d0(void *p);
int f_0d3950(int a, int b, int c, int d);
int f_0d2f40(int a, int b);



void *f_145234(void *p, void *q);
extern int d_1a34e0;
extern int d_1bbc7c;
extern int d_1bf4e8;
extern char d_1bf4ed;
extern signed char d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fe;
struct E { unsigned key; short s; char *ptr; int n; };
struct V { unsigned vp; E tab[200]; void *d; short cur; short st[10]; short cnt; unsigned sel; int pos; int lim; };
struct S { short x, y, h, a, b, p, t, w, m; GP g0, g1, g2, g3; };
#define VT(d,o) (*(int **)(d))[(o)/4]
typedef int (*PF_i_u)(void *, unsigned);
typedef int (*PF_i_uu)(void *, unsigned, int);
typedef void (*PF_v_v)(void *);
typedef void (*PF_v_u)(void *, unsigned);
typedef unsigned (*PF_u_vp)(void *, void *);
typedef unsigned (*PF_u_vpu)(void *, void *, unsigned);
typedef unsigned (*PF_u_v)(void *);
typedef int (*PF_i_ii)(void *, int, int);
unsigned short f_13faf0(V *v, unsigned key);
int f_13fa50(E *e);
int f_13fdd0(V *v, unsigned p2, unsigned p3);
void f_1407a0(S *s, int p);
#define DELP(x) operator delete((void *)(x));

#define HI80 (((unsigned char *)&v->cur)[1] & 0x80)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_140220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor einer vertikalen Bildlaufleiste (S): Speichert die Bildschirmkoordinaten (x = p2,
 *   y = p3) und die Gesamthöhe (h = p4), lädt über f_1407a0(s, p7) die vier Grafikbestandteile der Leiste
 *   (Hintergrund, obere/untere Reglerkappe und Reglermittelstück) und berechnet anschließend aus dem sichtbaren
 *   Flächenanteil p5 (in Prozent) und dem Startwert p6 (in Prozent) die Pixelhöhe t sowie die Pixelposition p
 *   des Schiebereglers.
 * - Eingaben: Zeiger s auf die Bildlaufleisten-Struktur, X-Koordinate p2, Y-Koordinate p3, Gesamthöhe p4,
 *   sichtbarer Anteil p5 (0-100), relative Position p6 (0-100) und Grafikstil-Kennung p7 (int).
 * - Rückgabewert: Der initialisierte Objektzeiger s.
 * - Wichtige Variablen:
 *   - s->t: Berechnete Höhe des Schiebereglers in Pixeln, begrenzt auf das Intervall [s->m * 2, s->h].
 *   - s->p: Berechneter vertikaler Pixelabstand des Reglers vom oberen Leistenrand, begrenzt auf [0, s->h -
 *     s->t].
 === Ende Beschreibung === */
S *f_140220(S *s, short p2, short p3, short p4, short p5, short p6, int p7)
{
struct Setter491 {static inline void area(S*s,short percentage){
  s->a = percentage;
  s->t = s->h * s->a / 100;
  s->t = f_0bd350(s->t, s->m * 2, s->h);
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}static inline void position(S*s,short percentage){
  s->b = percentage;
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}};
  short t;
  s->x = p2;
  s->y = p3;
  s->h = p4;
  f_1407a0(s, p7);
  Setter491::area(s,p5);
  Setter491::position(s,p6);
  return s;
}
//@ f_140300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor der vertikalen Bildlaufleiste (S): Gibt die vier in f_1407a0 angelegten
 *   Grafikobjekte g0, g1, g2 und g3 (Leistenhintergrund, Regleroberteil, Reglerunterteil und Reglermittelstück)
 *   wieder frei.
 * - Eingaben: Zeiger s auf die Bildlaufleiste und Destruktor-Flag p2 (int).
 * - Rückgabewert: Der Objektzeiger s.
 * - Wichtige Variablen:
 *   - s->g0 bis s->g3: Zeiger auf die vier Grafikobjekte der Bildlaufleiste.
 === Ende Beschreibung === */
struct IMG { ~IMG(); };
S *f_140300(S *s, int p2)
{
  delete (IMG *)s->g0;
  delete (IMG *)s->g1;
  delete (IMG *)s->g2;
  delete (IMG *)s->g3;
  return s;
}

//@ f_140360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen vertikalen Pixelversatz (p) des Schiebereglers innerhalb der Bildlaufleiste
 *   zurück.
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Pixelposition s->p (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_140360(S *s) { return s->p; }
//@ f_140370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle Höhe (t) des Schiebereglers in Pixeln zurück.
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Reglerhöhe s->t (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_140370(S *s) { return s->t; }
//@ f_140380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle relative Stellung (b) des Schiebereglers als Prozentwert (0 bis 100) zurück.
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Prozentuale Reglerstellung s->b (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_140380(S *s) { return s->b; }
//@ f_140390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert gleichzeitig die prozentuale Reglerstellung (b = p2) und den prozentualen
 *   sichtbaren Anteil (a = p3) der Bildlaufleiste und berechnet daraus die neue Reglerhöhe s->t sowie die neue
 *   Pixelposition s->p (jeweils über f_0bd350 auf die gültigen Grenzen beschränkt).
 * - Eingaben: Zeiger s auf die Bildlaufleiste, neue Prozentposition p2 (int) und neuer sichtbarer Prozentanteil
 *   p3 (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_140390(S *s, int p2, int p3)
{
  s->b = p2;
  s->a = p3;
  s->t = s->h * s->a / 100;
  s->t = f_0bd350(s->t, s->m * 2, s->h);
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}
//@ f_140410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die prozentuale Stellung des Schiebereglers auf p2 (0-100) und berechnet daraus bei
 *   unveränderter Reglerhöhe s->t die neue vertikale Pixelposition s->p im Bereich [0, s->h - s->t].
 * - Eingaben: Zeiger s auf die Bildlaufleiste und neue Prozentposition p2 (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_140410(S *s, int p2)
{
  s->b = p2;
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}
//@ f_140460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den prozentualen sichtbaren Inhaltsanteil auf p2 (0-100), berechnet daraus die neue
 *   Pixelhöhe s->t des Schiebereglers (mindestens 2 * s->m, höchstens s->h) und passt anschließend auch die
 *   Pixelposition s->p an die geänderte Reglerhöhe an.
 * - Eingaben: Zeiger s auf die Bildlaufleiste und neuer sichtbarer Prozentanteil p2 (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_140460(S *s, int p2)
{
  s->a = p2;
  s->t = s->h * s->a / 100;
  s->t = f_0bd350(s->t, s->m * 2, s->h);
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}
//@ f_1404e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die komplette vertikale Bildlaufleiste auf den Bildschirm (d_1a34e0): Blendet während
 *   des Zeichenvorgangs den Mauszeiger aus (RivaMouseGuard), synchronisiert über f_099ea0 den vertikalen
 *   Bildrücklauf, zeichnet zuerst den Leistenhintergrund g0 an (s->x, s->y), darüber an s->y + s->p die obere
 *   Reglerkappe g1, bei einer Mittelstückhöhe a3 > 0 das gestreckte Mittelstück g3 (f_0faec0) und schließlich am
 *   unteren Reglerende loc die untere Reglerkappe g2.
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - a3: Höhe des variablen Reglermittelstücks (s->t - 2 * s->m).
 *   - a2: Y-Koordinate der oberen Reglerkante (s->y + s->p).
 *   - a4: Y-Koordinate des Reglermittelstücks (a2 + s->m).
 *   - loc: Y-Koordinate der unteren Reglerkappe (a4 + a3).
 === Ende Beschreibung === */
void f_1404e0(S *s)
{
  int codex_arg_1_255;
  int codex_arg_2_255;
  int codex_arg_3_255;
  short a3 = s->t + s->m * -2;
  short a2 = s->y + s->p;
  short a4 = a2 + s->m;
  short loc = a4 + a3;
  RivaMouseGuard mg;
  f_099ea0();
  ((RivaRasterImage*)(s->g0))->f_0fade0((void *)( (codex_arg_1_255 = d_1a34e0)), (codex_arg_2_255 = s->x), (codex_arg_3_255 = s->y));
  ((RivaRasterImage*)(s->g1))->f_0fade0((void *)( d_1a34e0), s->x, a2);
  if (a3 != (short)0) ((RivaRasterImage*)(s->g3))->f_0faec0((void *)( d_1a34e0), s->x, a4, s->w, a3);
  ((RivaRasterImage*)(s->g2))->f_0fade0((void *)( d_1a34e0), s->x, loc);
}
//@ f_1405c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert das interaktive Ziehen des Schiebereglers bei gedrückter linker Maustaste (f_0d3780):
 *   Sichert die aktuellen Mausbewegungsgrenzen (f_0d38b0), schränkt den Mausbereich auf den zulässigen
 *   Bewegungsraum [s->x .. s->x + s->w, s->y .. s->y + s->h - s->t] ein, verfolgt in einer Schleife jede
 *   vertikale Mausbewegung (d_1bf4f2), rechnet die Y-Position in den neuen Prozentwert s->b und den Pixelversatz
 *   s->p um und zeichnet die Leiste über f_1404e0 sofort neu. Nach dem Loslassen der Maustaste werden die
 *   ursprünglichen Mausgrenzen wiederhergestellt und der Mauszeiger an die neue Reglerposition gesetzt.
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - pair: Gesichertes vorheriges Maus-Begrenzungsrechteck (Rc).
 *   - mx, my, p0: Ursprüngliche Mauskoordinaten und Reglerposition zu Beginn des Ziehvorgangs.
 *   - nu, de: Zähler ((MausY - s->y) * 100) und Nenner (s->h - s->t) zur Berechnung der neuen Prozentposition
 *     s->b.
 === Ende Beschreibung === */
struct Rc { short a, b, c, d; };
void f_1404e0(S *s);
#define MXV (*(volatile short *)&d_1bf4f0) // haelt das 16-Bit-Laden der Mausposition vor f_0d38b0 wie im Original
#define MYV (*(volatile short *)&d_1bf4f2) // verhindert das Verschieben des Maus-Y-Ladens hinter f_0d38b0
void f_1405c0(S *s)
{
  Rc pair[2];
  short my;
  short p0 = s->p;
  short mx = MXV;
  my = MYV;
  f_0d38b0(&pair[0]);
  struct G { volatile int fl; G() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; } ~G() { if (fl == 1) f_0d26e0(); } } mg; // haelt das Guard-Flag auf dem Stapel wie im Original
  { short right = s->x + s->w; short bottom = s->y + s->h - s->t; f_0d3950(s->x, s->y, right, bottom); }
  f_0d2f40(mx, (short)(s->y + s->p));
  d_1bf4fe = d_1bf4f2;
  while (f_0d3780()) {
    if (d_1bf4f2 != d_1bf4fe) {
      f_099ea0();
      d_1bf4ed = 1;
      short nu = d_1bf4f2;
      nu -= s->y;
      nu = nu * 100;
      short de = s->h - s->t;
      struct Divide491 { static inline short value(short n,short d) {n/=d;return n;} }; s->b=Divide491::value(nu,de);
      s->p = s->b * (s->h - s->t) / 100;
      s->p = f_0bd350(s->p, 0, s->h - s->t);
      f_1404e0(s);
      d_1bf4fe = d_1bf4f2;
      d_1bf4ed = 0;
    }
  }
  {
    pair[1].a = *(int *)&pair[0]; // erzeugt 32-Bit-Laden fuer das erste Wort von pair[0] wie im Original
    pair[1].b = *(int *)((char *)&pair[0] + 2);
    pair[1].c = *(int *)((char *)&pair[0] + 4);
    pair[1].d = *(int *)((char *)&pair[0] + 6);
    f_0d38d0(&pair[1]);
  }
  f_0d2f40(mx, (short)(my + s->p - p0));
  d_1bf4e8 = 0;
}
//@ f_140760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beschränkt den Bewegungsbereich des Mauszeigers über f_0d3950 auf den gültigen
 *   Verschiebebereich der Bildlaufleiste (s->x bis s->x + s->w horizontal und s->y bis s->y + s->h - s->t
 *   vertikal).
 * - Eingaben: Zeiger s auf die Bildlaufleiste.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - x2, y2: Rechte und untere Begrenzungskoordinate für den Mauszeiger.
 === Ende Beschreibung === */
void f_140760(S *s)
{
  short x2 = s->x + s->w;
  short y2 = s->y + s->h - s->t;
  f_0d3950(s->x, s->y, x2, y2);
}
