/* === Beschreibung (Katalog) ===
 * Einheit panel_gz0db7b0 (0dade0 - 0dc650)
 *
 * Überblick
 * Die zusammengefasste Einheit panel_gz0db7b0 enthält zwei logische Modulteile:
 * 1. Den zweiten Teil von panel.cpp (f_0dade0 bis f_0db6b0), der das Laden, Freigeben, Rendern und Textmenü der
 *   seitlichen Aktionsschaltflächenleiste (Panel) implementiert.
 * 2. Den ersten Teil des Heldengruppen-Moduls (party.cpp / party2.cpp, f_0db710 bis f_0dc4d0), der die
 *   Verwaltung der bis zu 6 Teilgruppen (d_1bfdbc, je 0x61 Bytes), das Gruppengeld, Gruppen-Regeneration,
 *   Gruppenschaden, Krankheit/Gift-Ansteckung, Gegenstandssuche über die gesamte Gruppe sowie das Umfärben von
 *   Porträts inaktiver Teilgruppen umfasst.
 === Ende Beschreibung === */
// P3 52/55 gleich (suche.py 30.10.2026, Basis panel_gz0db7b0_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// P3 6/10 gleich (suche.py 25.10.2026, Basis panel_P1.CPP)
// panel.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DADE0-0x0DB7B0
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
void *f_145300(void *p, int c, unsigned n);              // memset
int f_0a2230(int p1, int p2);
int f_0a2430(int p1);
int f_0a2440(int p1);
short f_0a2450(int p1);
int f_0a2460(int p1, int p2, int p3, int p4);
int f_0a2480(int p1, int p2, int p3, int p4);
int f_0bf820(const char *fmt, ...);
int f_0d26e0();
int f_0d2710();
int f_0d37b0();
int f_0d3860();
int f_0d5b50(int p1);
int f_0fac80(int p1, int p2, int p3);
int f_0fad20(int p1, int p2);
int f_0fade0(int p1, int p2, int p3, int p4);
int f_0fb0b0(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_149cf0(int p1);
void f_14d17f(void *p);
#pragma aux f_14d17f modify [ebx edx];
void f_147c84(void *a, int n, void *b);
struct File { int f_1448b0(unsigned id, int mode); int f_144920(void *buf, int n); int f_1449a0(); int f_144ab0(int off, int wh); };
extern File d_1c2098;
extern int d_1a34e0;
extern int d_1a62b8;
extern int d_1a62c0;
extern int d_1bb53c;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1be17c;
extern int d_1bfdbc;
extern char d_1c0028;
extern short d_1c0029;
extern char d_1c002c;
extern short d_1c002d;
extern short d_1c212a;
extern int *d_1c212c;
extern const char d_1a628c[];
extern const char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3498[];
extern const char d_1c3870[];
struct Rec { int a, b, c; };
extern Rec d_1a62ac;
struct Panel {
  char pad0[8]; int id; char padc[4]; short sel; short n; char pad14[4];
  short *w; short *h; unsigned short s20; int f22;
  int v26; Rec *p2a; int z2e;
  Rec *recs; int *imgs; int *bufs; short *pos;
};

#include <string.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))
extern unsigned char d_1c2be0;
int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C04fef0_7(int,int,int,int,int,int,int);
#pragma aux C04fef0_7 "f_04fef0" modify exact [eax ebx ecx edx];
int C050580_5(int,int,int,int,int);
#pragma aux C050580_5 "f_050580";
int C0da9a0_1(int);
#pragma aux C0da9a0_1 "f_0da9a0" modify exact [eax];
int C0db0c0_2(int,int);
#pragma aux C0db0c0_2 "f_0db0c0" modify exact [eax];
int C0fac80_3(int,int,int);
#pragma aux C0fac80_3 "f_0fac80" modify exact [eax ebx edx];
int C0fb0b0_1(int);
#pragma aux C0fb0b0_1 "f_0fb0b0" modify exact [eax];
int C11ea00_5(int,int,int,int,int);
#pragma aux C11ea00_5 "f_11ea00" modify exact [eax ebx ecx edx];
//@ f_0dade0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Reserviert sämtliche Tabellen- und Bildpuffer einer Aktionsleiste (Panel, für self->n
 *   Schaltflächenplätze), lädt die Koordinatenliste (self->positions) über f_11ea00, liest die
 *   Schaltflächendefinitionen (f_0db0c0), baut die aktiven Icons (f_0da9a0) auf und entpackt die ungedrückten
 *   und gedrückten Schaltflächen-Hintergrundsprites (self->buffers[0..2*n-1]).
 * - Eingaben: Übergeben wird der Zeiger auf das zu initialisierende Panel-Objekt (self).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct PanelObject12 {
    int unused0,key,unused8,source;short selected,n;int unused20;
    short *w,*h;unsigned short unused32;int unused34,v26;Rec *p2a;int z2e;
    Rec *records;int *images;int *buffers;short *positions;
};
int loadPanel12(int);
#pragma aux loadPanel12 "f_0db0c0" modify exact [eax];
void f_0dade0(PanelObject12 *self)
{
    short i;int obj;
    self->w=(short *)NNEW(self->n*4,d_1a628c,0x145);
    self->h=(short *)NNEW(self->n*4,d_1a628c,0x146);
    memset(&self->v26,0,8);memset(&self->z2e,0,8);
    self->p2a=(Rec *)NNEW(self->n*12,d_1a628c,0x14b);
    self->records=(Rec *)NNEW(self->n*12,d_1a628c,0x14c);
    self->images=(int *)NNEW(self->n*4,d_1a628c,0x14e);
    self->buffers=(int *)NNEW(self->n*8,d_1a628c,0x14f);
    self->positions=(short *)NNEW(self->n*4,d_1a628c,0x150);
    obj=NOBJ(1,d_1a628c,0x153);
    C11ea00_5(obj,self->source,0,(int)self->positions,self->n*4);
    C014710_1(obj);
    loadPanel12((int)self);
    i=0;
    C0da9a0_1((int)self);
    for(;i<self->n*2;i++) {
        C050580_5(NA(d_1c2be0),self->key,i,(int)(self->w+i),(int)(self->h+i));
        int raw=(int)NOBJ(9,d_1a628c,0x16c);int image=raw?(int)C0fac80_3(raw,self->w[i],self->h[i]):raw;
        self->buffers[i]=image;
        C04fef0_7(NA(d_1c2be0),self->key,C0fb0b0_1(self->buffers[i]),0,i,0,320);
    }
}


//@ f_0db020
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Gibt beim Abbau einer Aktionsleiste (Panel) alle Icon-Objekte (p->imgs[i]), alle
 *   Hintergrund-Sprites (p->bufs[i]) sowie sämtliche dynamischen Tabellenpuffer (pos, bufs, imgs, recs, p2a, h,
 *   w) frei.
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db020(Panel *p)
{
  short i;
  for (i = 0; i < p->n; i++) f_0a2230(d_1be17c, p->imgs[i]);
  for (i = 0; i < p->n * 2; i++) {
    int q = p->bufs[i];
    if (q != 0) operator delete((void *)f_0fad20(q, 0));
  }
  operator delete(p->pos);
  operator delete(p->bufs);
  operator delete(p->imgs);
  operator delete(p->recs);
  operator delete(p->p2a);
  operator delete(p->h);
  operator delete(p->w);
}
//@ f_0db0c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest aus der im Panel hinterlegten Archivressource (p->id) die zum gewählten Gebäudetyp (p->sel)
 *   gehörende Überschrifts-Textkennung (p->v26) sowie die 12-Byte-Datensätze der verfügbaren
 *   Aktionsschaltflächen in p->p2a ein und füllt ungenutzte Plätze mit der Leerkennung d_1a62ac (-1).
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db0c0(Panel *p)
{
  char hdr[12];
  int v18, v1c, v28, v20, v24;
  short s30, cnt, i;
  short *buf = new (mark(d_1a628c, 0x19d)) short[p->n];
  Rec def = d_1a62ac;
  d_1c2098.f_1448b0(p->id, 0x200);
  d_1c2098.f_144920(hdr, 12);
  d_1c2098.f_144920(&v18, 4);
  d_1c2098.f_144920(&v1c, 4);
  d_1c2098.f_144920(&v20, 4);
  d_1c2098.f_144ab0(p->sel * 4 + v18, 0);
  d_1c2098.f_144920(&p->v26, 4);
  d_1c2098.f_144ab0(v20, 0);
  d_1c2098.f_144920(&s30, 2);
  d_1c2098.f_144ab0(p->sel * 8, 1);
  d_1c2098.f_144920(&v24, 4);
  d_1c2098.f_144920(&v28, 4);
  d_1c2098.f_144ab0(v20, 0);
  d_1c2098.f_144ab0(2, 1);
  d_1c2098.f_144ab0(s30 * 8, 1);
  d_1c2098.f_144ab0(v24, 1);
  d_1c2098.f_144920(buf, v28);
  cnt = (unsigned)v28 >> 1;
  for (i = 0; i < cnt; i++) {
    d_1c2098.f_144ab0(v1c, 0);
    d_1c2098.f_144ab0(buf[i] * 12, 1);
    d_1c2098.f_144920(&p->p2a[i], 12);
  }
  for (i = cnt; i < p->n; i++) p->p2a[i] = def;
  d_1c2098.f_1449a0();
  operator delete(buf);
}
//@ f_0db2f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt die aktive Schaltflächentabelle (p->recs) der Aktionsleiste auf Null zurück und gibt
 *   eventuell bereits angelegte Icon-Objekte (p->imgs[i]) über f_0a2230 frei.
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db2f0(Panel *p)
{
  short i;
  f_145300(&p->z2e, 0, 4);
  for (i = 0; i < p->n; i++) f_145300(&p->recs[i], 0, 12);
  for (i = 0; i < p->n; i++) {
    if (p->imgs[i] != 0) { f_0a2230(d_1be17c, p->imgs[i]); p->imgs[i] = 0; }
  }
}
//@ f_0db370
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft die zuletzt gedrückte Sondertaste (d_1bd762) für die Aktionsleiste und liefert bei Bild-Auf
 *   (0x4900) den Code 0xa1 (Textmenü öffnen) bzw. bei Escape (0x11b) den Code p->s20 (Verlassen-Schaltfläche)
 *   unter Setzen des Tastaturflags p->f22 = 1 zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Gibt den ausgelösten Aktionscode (0xa1, p->s20 oder 0) zurück.
 === Ende Beschreibung === */
unsigned short f_0db370(Panel *p)
{
  unsigned short r = 0;
  unsigned short k = d_1bd762;
  switch (k) {
  case 0x4900:
    p->f22 = 1;
    r = 0xa1;
    break;
  case 0x11b:
    r = p->s20;
    p->f22 = 1;
  }
  return r;
}
//@ f_0db3b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Übernimmt bei noch leerem Aktionscode (*p2 == 0) den aktuellen Maus-Hot-Spot (d_1bd766) und
 *   überschreibt *p2 bei gedrückter rechter Maustaste (f_0d37b0) mit 0xa1 (Textmenü öffnen).
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (a) sowie ein Zeiger auf den 16-Bit-Aktionscode
 *   (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db3b0(int a, short *p2)
{
  if (*p2 == 0) *p2 = d_1bd766;
  if (f_0d37b0()) *p2 = 0xa1;
}
//@ f_0db3d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet ein Auswahlmenü (f_0bf820) mit den Textbeschreibungen (p->recs[i].c) aller derzeit aktiven
 *   Schaltflächen der Aktionsleiste unter der Überschrift p->z2e und liefert die vom Spieler gewählte
 *   Schaltfläche als Hot-Spot-Code (Auswahl + 0x80) zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Gibt den gewählten Schaltflächencode (0x81..0x89) oder 0 bei Abbruch zurück.
 === Ende Beschreibung === */
int f_0db3d0(Panel *p)
{
  struct { char obj[60]; int res; } state;
  short cnt = 0;
  short i;
  int r;
  state.res = 0;
  cnt = (short)state.res ^ (short)state.res; // haelt die Registerzuteilung wie im Original
  f_125400(state.obj, d_1c349c, d_1c3870, d_1c3498);
  for (i = 0; i < p->n; i++) if (p->recs[i].c != 0) cnt++;
  f_0d5b50(1);
  r = f_0bf820(d_1c2c64, p->z2e, (int)cnt, p->recs[0].c, p->recs[1].c, p->recs[2].c, p->recs[3].c, p->recs[4].c, p->recs[5].c, p->recs[6].c, p->recs[7].c, p->recs[8].c);
  f_0d5b50(1);
  if ((short)r > 0) { p->f22 = 1; state.res = r + 0x80; }
  f_1254a0(state.obj, 0);
  return state.res;
}
//@ f_0db4a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet die einzelne Panel-Schaltfläche idx im ungedrückten (mode == 0) oder eingedrückten (mode
 *   == 1) Zustand, indem das passende Hintergrund-Sprite (p->bufs[idx*2 + mode]) kopiert, das Aktionssymbol
 *   (p->imgs[idx]) mittig daraufgelegt und das Ergebnis an der Panel-Position p->pos in den Zielbildpuffer p4
 *   ausgegeben wird.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p), der Schaltflächenindex (idx), der
 *   Darstellungsmodus (mode, 0 = normal, 1 = gedrückt) sowie der Zielbildpuffer (p4).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db4a0(Panel *p, short idx, short mode, int p4)
{
  extern short width997(int), height997(int);
#pragma aux width997 "f_0a2430" modify exact [eax]
#pragma aux height997 "f_0a2440" modify exact [eax]
  volatile int fl;
  int o[3];
  short *ph;
  short hy, hx; short area;
  short j;
  void *target1109;
  short draw1109;
  (void)&mode; // haelt die Registerzuteilung wie im Original
  if (f_0a2450(p->imgs[idx]) > 0) {
    j = idx * 2;
    int round1109 = d_1a34e0; d_1a34e0 = round1109; // haelt die Registerzuteilung wie im Original
    ph = p->h + j;
    short *widths997 = (idx & 0) ? 0 : p->w; // haelt die Registerzuteilung wie im Original
    area = widths997[j] * *(short *&)ph;
    hx = (widths997[j] - width997(p->imgs[idx])) / 2;
    hy = (p->h[j] - height997(p->imgs[idx])) / 2;
    f_0fac80((int)o, p->w[j], p->h[j]);
    short select1109 = (mode & 0) ? (short)0 : mode; // haelt die Registerzuteilung wie im Original
    if (select1109 == (short)1) j += select1109;
    memcpy((target1109 = (void *)f_0fb0b0((int)o),
            draw1109 = (mode & 0) ? (short)0 : mode, target1109), // haelt die Registerzuteilung wie im Original
           (void *)f_0fb0b0(p->bufs[j]), (short &)area);
    if (draw1109 == (short)1) {
      int image1109 = p->imgs[idx];
      int roundA1109 = d_1a34e0; d_1a34e0 = roundA1109; // haelt die Registerzuteilung wie im Original
      f_0a2460(image1109, (int)o, hx, hy);
    } else {
      int roundB1109 = d_1a34e0; d_1a34e0 = roundB1109; // haelt die Registerzuteilung wie im Original
      f_0a2480(p->imgs[idx], (int)o, hx, hy);
    }
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; }
    else fl = 0;
    f_0fade0((int)o, p4, p->pos[idx * 2], p->pos[idx * 2 + 1]);
    if (fl == 1) f_0d26e0();
    f_0fad20((int)o, 0);
  }
}
//@ f_0db640
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet den leeren (ungedrückten) Schaltflächen-Hintergrund des Platzes idx ohne Aktionssymbol an
 *   seine Bildschirmposition im Zielpuffer col.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p), der Platzindex (idx) sowie der
 *   Zielbildpuffer (col).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db640(Panel *p, short idx, int col)
{
  struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    ~MG() { if (fl == 1) f_0d26e0(); }
  } mg;
  f_0fade0(p->bufs[idx * 2], col, p->pos[idx * 2], p->pos[idx * 2 + 1]);
}
//@ f_0db6b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt die kurze Eindrück-Animation der Panel-Schaltfläche idx aus: zeichnet die Schaltfläche
 *   gedrückt (mode = 1), wartet 50 (bzw. bei Tastaturauslösung zusätzlich 200) Timer-Ticks, wartet auf das
 *   Loslassen der Maustaste (f_0d5b50(1)) und zeichnet die Schaltfläche wieder ungedrückt (mode = 0).
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p) sowie der Schaltflächenindex (idx).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db6b0(Panel *p, short idx)
{
  f_0db4a0(p, idx, 1, d_1a34e0);
  f_149cf0(0x32);
  if (p->f22 == 1) f_149cf0(0xc8);
  f_0d5b50(1);
  f_0db4a0(p, idx, 0, d_1a34e0);
}
//@ f_0db710
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Initialisiert beim Programmstart das Array der 6 Heldengruppen-Objekte (d_1bfdbc, Konstruktor
 *   d_1bb53c) und registriert die beiden globalen Gruppen-Statusvariablen d_1c0028 (ID 0x17) und d_1c002c (ID
 *   0x18) in der Spielstands-Registrierung d_1c212a.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db710()
{
  f_14d17f(&d_1a62b8);
  f_147c84(&d_1bfdbc, 6, &d_1bb53c);
  d_1a62c0 = 1;
  d_1c0028 = 0;
  d_1c0029 = 0x17;
  *(int *)&(*(int **)&d_1c212c)[d_1c212a] = (int)&d_1c0028;
  struct Obj { signed char a; short b; };
  struct Reg { short count; Obj **list; };
  Obj &b = *(Obj *)&d_1c002c;
  Reg &r = *(Reg *)&d_1c212a;
  struct Helper {
    void add(Obj &o, Reg &q, short id) {
      signed char z = 0;
      o.b = id;
      o.a = z;
      q.count++;
      ((Obj ** &)q.list)[q.count] = &o;
      q.count++;
    }
  } h;
  h.add(b, r, 0x18);
}

// Getrennte Quellsicht gz_0db7b0; keine neuen Datenobjekte.
// P3 40/44 gleich (suche.py 26.10.2026, Basis gz_0db7b0_P1.CPP)
// gz_0db7b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DB7B0-0x0DC650
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
int ag700_1_f_032470(int p1, int p2, int p3);
int ag700_1_f_0324e0(int p1, int p2, int p3);
int ag700_1_f_039040(int p1);
int ag700_1_f_0406d0(int p1, int p2);
int ag700_1_f_040730(int p1, int p2);
int ag700_1_f_040820(int p1, int p2);
int ag700_1_f_040880(int p1, int p2);
int ag700_1_f_040980(int p1, int p2);
signed char ag700_1_f_0423c0(int p1);
char ag700_1_f_042400(int p1);
int ag700_1_f_042410(int p1);
int ag700_1_f_042420(int p1, int p2);
char ag700_1_f_042470(int p1);
int ag700_1_f_0428f0(int p1);
int ag700_1_f_042920(int p1, int p2);
int ag700_1_f_042930(int p1, int p2);
signed char ag700_1_f_042940(int p1);
short ag700_1_f_042960(int p1);
short ag700_1_f_042970(int p1);
short ag700_1_f_042a60(int p1, int p2);
int ag700_1_f_044230(int p1, int p2);
int ag700_1_f_0442b0(int p1, int p2);
int ag700_1_f_044300(int p1, int p2);
int ag700_1_f_044890(int p1, int p2);
int ag700_1_f_045190(int p1, int p2);
int ag700_1_f_0451c0(int p1, int p2);
int ag700_1_f_0d49b0(int p1);
int ag700_1_f_0d4a10(int p1);
int ag700_1_f_0d4a60(int p1);
short ag700_1_f_0d4aa0(int p1, int p2);
short ag700_1_f_0d4c80(int p1);
int ag700_1_f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
unsigned short ag700_1_f_0d54c0(int p1);
int ag700_1_f_0d54f0(int p1, int p2);
int ag700_1_f_0de840(int p1);
int ag700_1_f_0de850(int p1, int p2);
int ag700_1_f_0de860(int p1);
int ag700_1_f_0de870(int p1, int p2);
int ag700_1_f_0de880(int p1);
int ag700_1_f_0de890(int p1, int p2);
short ag700_1_f_0de8c0(int p1);
int ag700_1_f_0de8d0(int p1, int p2);
short ag700_1_f_1457e0(int p1);
int ag700_1_f_145234(int p1, const char *p2);
int ag700_1_f_145254();
int ag700_1_f_1512d8(int p1, int p2, int p3, int p4, int p5, int p6);
extern signed char ag700_1_d_1a9670;
extern const char ag700_1_d_1bb53c[];
extern const char ag700_1_d_1bb554[];
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define SL(p,i) (*(int *)((p)+(i)*4))
#define SR(p,i) (*(int *)((i)*4+(p)))
#pragma aux ag700_1_d_1a9670 "d_1a9670"
#pragma aux ag700_1_d_1bb53c "d_1bb53c"
#pragma aux ag700_1_d_1bb554 "d_1bb554"
#pragma aux ag700_1_f_032470 "f_032470"
#pragma aux ag700_1_f_0324e0 "f_0324e0"
#pragma aux ag700_1_f_039040 "f_039040"
#pragma aux ag700_1_f_0406d0 "f_0406d0"
#pragma aux ag700_1_f_040730 "f_040730"
#pragma aux ag700_1_f_040820 "f_040820"
#pragma aux ag700_1_f_040880 "f_040880"
#pragma aux ag700_1_f_040980 "f_040980"
#pragma aux ag700_1_f_0423c0 "f_0423c0"
#pragma aux ag700_1_f_042400 "f_042400"
#pragma aux ag700_1_f_042410 "f_042410"
#pragma aux ag700_1_f_042420 "f_042420"
#pragma aux ag700_1_f_042470 "f_042470"
#pragma aux ag700_1_f_0428f0 "f_0428f0"
#pragma aux ag700_1_f_042920 "f_042920"
#pragma aux ag700_1_f_042930 "f_042930"
#pragma aux ag700_1_f_042940 "f_042940"
#pragma aux ag700_1_f_042960 "f_042960"
#pragma aux ag700_1_f_042970 "f_042970"
#pragma aux ag700_1_f_042a60 "f_042a60"
#pragma aux ag700_1_f_044230 "f_044230"
#pragma aux ag700_1_f_0442b0 "f_0442b0"
#pragma aux ag700_1_f_044300 "f_044300"
#pragma aux ag700_1_f_044890 "f_044890"
#pragma aux ag700_1_f_045190 "f_045190"
#pragma aux ag700_1_f_0451c0 "f_0451c0"
#pragma aux ag700_1_f_0d49b0 "f_0d49b0"
#pragma aux ag700_1_f_0d4a10 "f_0d4a10"
#pragma aux ag700_1_f_0d4a60 "f_0d4a60"
#pragma aux ag700_1_f_0d4aa0 "f_0d4aa0"
#pragma aux ag700_1_f_0d4c80 "f_0d4c80"
#pragma aux ag700_1_f_0d5040 "f_0d5040"
#pragma aux ag700_1_f_0d54c0 "f_0d54c0"
#pragma aux ag700_1_f_0d54f0 "f_0d54f0"
#pragma aux ag700_1_f_0de840 "f_0de840"
#pragma aux ag700_1_f_0de850 "f_0de850"
#pragma aux ag700_1_f_0de860 "f_0de860"
#pragma aux ag700_1_f_0de870 "f_0de870"
#pragma aux ag700_1_f_0de880 "f_0de880"
#pragma aux ag700_1_f_0de890 "f_0de890"
#pragma aux ag700_1_f_0de8c0 "f_0de8c0"
#pragma aux ag700_1_f_0de8d0 "f_0de8d0"
#pragma aux ag700_1_f_145234 "f_145234"
#pragma aux ag700_1_f_145254 "f_145254"
#pragma aux ag700_1_f_1457e0 "f_1457e0"
#pragma aux ag700_1_f_1512d8 "f_1512d8"
//@ f_0db7b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Konstruiert ein einzelnes Heldengruppen-Objekt (0x61 Bytes), setzt die virtuelle Methodentabelle
 *   d_1bb554 an Offset +0x5d, löscht die Struktur mit memset(p1, 0, 0x61) und initialisiert die Gebiets- und
 *   Positionsfelder (+0x21 = -1, +0x23 = -1, +0x25 = 0). (Hinweis: Da memset über alle 0x61 Bytes läuft, wird
 *   der zuvor an +0x5d gesetzte vtable-Zeiger im Originalcode sofort wieder mit Nullen überschrieben.)
 * - Eingaben: Übergeben wird der Zeiger auf das zu initialisierende Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den Zeiger auf das Gruppen-Objekt (p1) zurück.
 === Ende Beschreibung === */
int f_0db7b0(int p1)
{
    I(p1, 0x5d) = (int)ag700_1_d_1bb554;
    memset((void *)p1, 0, 0x61);
    W(p1, 0x21) = -1;
    W(p1, 0x23) = -1;
    W(p1, 0x25) = 0;
    I(p1, 0x41) = 0;
    I(p1, 0x45) = 0;
    return p1;
}
//@ f_0db7f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zerstört ein Heldengruppen-Objekt (p1, oder ein ganzes Array bei gesetztem Bit 4 in p2) und gibt
 *   bei gesetztem Bit 2 in p2 den Speicher frei.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Destruktor-Steuerflags (p2).
 * - Rückgabewert: Gibt den Zeiger auf das Gruppen-Objekt (p1) zurück.
 === Ende Beschreibung === */
int f_0db7f0(int p1, unsigned p2)
{
    if (p2 & 4) {
        ag700_1_f_145234(p1, ag700_1_d_1bb53c);
        ag700_1_f_145254();
        return p1;
    }
    I(p1, 0x5d) = (int)ag700_1_d_1bb554;
    if (p2 & 2)
        operator delete((void *)p1);
    return p1;
}
//@ f_0db820
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Fügt der Gruppenkasse (I(p1, 0x1d)) einen Geldbetrag p2 (in Hellern) hinzu, zieht zuvor den
 *   prozentualen Beuteanteil eines anwesenden bezahlten NPC-Begleiters (f_039040(p1), f_042940) ab und
 *   synchronisiert den neuen Kassenstand in allen regulären Helden der Gruppe (f_042420).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der hinzuzufügende Geldbetrag in
 *   Hellern (p2).
 * - Rückgabewert: Gibt den neuen Gesamtbestand der Gruppenkasse in Hellern zurück.
 === Ende Beschreibung === */
int f_0db820(int p1, int p2)
{
    int e;
    int t;
    short i;
    if (p2 > 0) {
        e = ag700_1_f_039040(p1);
        if (e != 0) {
            t = (ag700_1_f_042940(e) * p2) / 100;
            p2 = p2 - t;
            ag700_1_f_042420(e, t + ag700_1_f_042410(e));
        }
        I(p1, 0x1d) = I(p1, 0x1d) + p2;
        for (i = 0; (t = i) <= 6; i = i + 1) {
            e = SL(p1, t);
            if (e != 0) {
                if (!ag700_1_f_042400(e))
                    ag700_1_f_042420(e, I(p1, 0x1d));
            }
        }
    }
    return I(p1, 0x1d);
}
//@ f_0db8b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zieht einen Geldbetrag p2 (in Hellern) von der Gruppenkasse (I(p1, 0x1d)) ab (mindestens bis 0) und
 *   aktualisiert den gespeicherten Kassenstand bei allen regulären Helden der Gruppe (f_042420).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der abzuziehende Geldbetrag in
 *   Hellern (p2).
 * - Rückgabewert: Gibt den verbleibenden Bestand der Gruppenkasse in Hellern zurück.
 === Ende Beschreibung === */
int f_0db8b0(int p1, int p2)
{
    int e;
    short i;
    if (p2 > 0) {
        I(p1, 0x1d) -= p2;
        if ((unsigned)I(p1, 0x1d) <= 0)
            I(p1, 0x1d) = 0;
        for (i = 0; i <= 6; i = i + 1) {
            e = SL(p1, i);
            if (e != 0) {
                if (!ag700_1_f_042400(e))
                    ag700_1_f_042420(e, I(p1, 0x1d));
            }
        }
    }
    return I(p1, 0x1d);
}
//@ f_0db900
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Berechnet den gleichmäßigen Pro-Kopf-Geldanteil eines Gruppenmitglieds, indem die Gruppenkasse
 *   (I(p1, 0x1d)) durch die aktuelle Mitgliederzahl (*(signed char *)(p1 + 0x1c)) geteilt wird.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den Pro-Kopf-Anteil der Gruppenkasse in Hellern zurück.
 === Ende Beschreibung === */
unsigned f_0db900(int p1)
{
    return (unsigned)I(p1, 0x1d) / (unsigned)(int)*(signed char *)((p1) + 0x1c);
}
//@ f_0db910
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Summiert die Stufen (f_0428f0) aller in der Gruppe p1 vorhandenen Gruppenmitglieder auf.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Summe aller Heldenstufen der Gruppe zurück.
 === Ende Beschreibung === */
int f_0db910(int p1)
{
    int e;
    int s;
    short i;
    s = 0;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            s = s + ag700_1_f_0428f0(e);
    }
    return s;
}
//@ f_0db940
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zählt, wie viele Mitglieder der Gruppe p1 das Statuskriterium f_0d49b0 erfüllen (z. B.
 *   männlich/kampffähig bzw. bestimmter Heldenstatus).
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Anzahl der zutreffenden Gruppenmitglieder zurück.
 === Ende Beschreibung === */
int f_0db940(int p1)
{
    int e;
    int s;
    short i;
    s = 0;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            if (ag700_1_f_0d49b0(e) != 0)
                s = s + 1;
        }
    }
    return s;
}
//@ f_0db970
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zählt, wie viele Mitglieder der Gruppe p1 das Statuskriterium f_0d4a10 (lebend und bei Bewusstsein)
 *   erfüllen.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Anzahl der handlungsfähigen Gruppenmitglieder zurück.
 === Ende Beschreibung === */
int f_0db970(int p1)
{
    int e;
    int s;
    short i;
    s = 0;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            if (ag700_1_f_0d4a10(e) != 0)
                s = s + 1;
        }
    }
    return s;
}
//@ f_0db9a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zählt, wie viele Mitglieder der Gruppe p1 das Statuskriterium f_0d4a60 (aktiv/ansprechbar)
 *   erfüllen.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Anzahl der aktiven Gruppenmitglieder zurück.
 === Ende Beschreibung === */
int f_0db9a0(int p1)
{
    int e;
    int s;
    short i;
    s = 0;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            if (ag700_1_f_0d4a60(e) != 0)
                s = s + 1;
        }
    }
    return s;
}
//@ f_0db9d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Würfelt für jedes Mitglied der Gruppe p1 eine Prozentprobe (1..100 <= p3) und steckt den Helden bei
 *   Erfolg über f_040980(e, p2) mit der Krankheit p2 an.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Krankheitskennung (p2) sowie die
 *   Ansteckungswahrscheinlichkeit in Prozent (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0db9d0(int p1, short p2, short p3)
{
    short i;
    int e;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            if (ag700_1_f_1457e0(100) <= p3)
                ag700_1_f_040980(e, p2);
        }
    }
}
//@ f_0dba10
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Würfelt für jedes Mitglied der Gruppe p1 mit Ausnahme des bereits erkrankten Helden p4 eine
 *   Prozentprobe (1..100 <= p3) und steckt die getroffenen Gefährten über f_040980(e, p2) mit der Krankheit p2
 *   an.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Krankheitskennung (p2), die
 *   Ansteckungswahrscheinlichkeit in Prozent (p3) sowie der auszuschließende Held (p4).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dba10(int p1, short p2, short p3, int p4)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0 && e != p4) {
            if (ag700_1_f_1457e0(100) <= p3)
                ag700_1_f_040980(e, p2);
        }
    }
}
//@ f_0dba60
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Heilt bzw. regeneriert bei jedem Mitglied der Gruppe p1 eine feste Anzahl von p2 Lebenspunkten über
 *   f_044890.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die zu regenerierende
 *   Lebenspunktzahl (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dba60(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_044890(e, p2);
    }
}
//@ f_0dba90
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Heilt sämtliche Mitglieder der Gruppe p1 vollständig auf ihre maximalen Lebenspunkte (max_LE -
 *   cur_LE über f_044890).
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dba90(int p1)
{
    int e;
    short a;
    short b;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            a = ag700_1_f_042970(e);
            b = ag700_1_f_042960(e);
            ag700_1_f_044890(e, (short)(a - b));
        }
    }
}
//@ f_0dbad0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Regeneriert bei jedem Mitglied der Gruppe p1 eine individuell ausgewürfelte Anzahl von
 *   Lebenspunkten im Bereich [p2, p3] über f_044890.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Mindest- (p2) und Höchstwert
 *   (p3) der Lebenspunkt-Heilung.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbad0(int p1, short p2, short p3)
{
    int e;
    short n;
    short i;
    n = (p3 - p2) + 1;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            short r = ag700_1_f_1457e0(n);
            ag700_1_f_044890(e, (short)(r + p2 - 1));
        }
    }
}
//@ f_0dbb20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Fügt jedem Mitglied der Gruppe p1 einen festen Lebenspunktschaden in Höhe von p2 über f_044300 zu.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Schadenswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbb20(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_044300(e, p2);
    }
}
//@ f_0dbb50
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Fügt jedem Mitglied der Gruppe p1 einen individuell im Bereich [p2, p3] ausgewürfelten
 *   Lebenspunktschaden über f_044300 zu.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Mindest- (p2) und Höchstschaden
 *   (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbb50(int p1, short p2, short p3)
{
    int e;
    short n;
    short i;
    n = (p3 - p2) + 1;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            short r = ag700_1_f_1457e0(n);
            ag700_1_f_044300(e, (short)(r + p2 - 1));
        }
    }
}
//@ f_0dbb90
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Würfelt für jedes Mitglied der Gruppe p1 einen Schadensbetrag (1..p2 + p3) aus, zieht bei p4 == 0
 *   den Rüstungsschutz (f_0423c0) ab und wendet den resultierenden Schaden über f_044300 an.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Würfelspanne (p2), der
 *   Schadenszuschlag (p3) sowie ein Flag zum Ignorieren des Rüstungsschutzes (p4).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbb90(int p1, char p2, char p3, int p4)
{
    int t;
    int e;
    short r;
    short i;
    t = 0;
    for (i = 0; (t = i) <= 6; i = i + 1) {
        e = SL(p1, t);
        if (e != 0) {
            if (p4 == 0) {
                r = ag700_1_f_1457e0((signed char)p2);
                ag700_1_f_044300(e, (short)(((signed char)p3 + r) - (short)ag700_1_f_0423c0(e)));
            } else {
                r = ag700_1_f_1457e0((signed char)p2);
                ag700_1_f_044300(e, (short)(r + (signed char)p3));
            }
        }
    }
}
//@ f_0dbc10
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Fügt allen Mitgliedern der Gruppe p1, deren aktuelle Lebenspunkte (f_042960) über der Untergrenze
 *   p3 liegen, bis zu p2 Schadenspunkte zu, sodass ihre Lebenspunkte höchstens bis auf p3 absinken.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der maximale Schadensbetrag (p2) sowie
 *   die verbleibende Mindest-Lebenspunktzahl (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbc10(int p1, short p2, short p3)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0 && ag700_1_f_042960(e) > p3) {
            if ((int)p2 + (int)p3 <= (int)ag700_1_f_042960(e))
                ag700_1_f_044300(e, p2);
            else
                ag700_1_f_044300(e, (short)(ag700_1_f_042960(e) - p3));
        }
    }
}
//@ f_0dbc80
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verändert den Erschöpfungs- bzw. Zustandswert bei allen Mitgliedern der Gruppe p1 über f_040880(e,
 *   p2).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Änderungswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbc80(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_040880(e, p2);
    }
}
//@ f_0dbcb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verändert den zweiten Zustandswert (z. B. Ausdauer/Trunkenheit) bei allen Mitgliedern der Gruppe p1
 *   über f_040820(e, p2).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Änderungswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbcb0(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_040820(e, p2);
    }
}
//@ f_0dbce0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Regeneriert bei allen Mitgliedern der Gruppe p1 p2 Astralpunkte über f_0442b0.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die zu regenerierende
 *   Astralpunktzahl (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbce0(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_0442b0(e, p2);
    }
}
//@ f_0dbd10
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zieht allen Mitgliedern der Gruppe p1 p2 Astralpunkte über f_044230 ab.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der abzuziehende Astralpunktbetrag
 *   (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbd10(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_044230(e, p2);
    }
}
//@ f_0dbd40
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verändert den Hungerwert aller Mitglieder der Gruppe p1 über f_040730(e, p2).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Änderungswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbd40(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_040730(e, p2);
    }
}
//@ f_0dbd70
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verändert den Durstwert aller Mitglieder der Gruppe p1 über f_0406d0(e, p2).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Änderungswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbd70(int p1, short p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_0406d0(e, p2);
    }
}
//@ f_0dbda0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt Hunger und Durst sämtlicher Mitglieder der Gruppe p1 vollständig auf 0 zurück (f_042920(e, 0)
 *   und f_042930(e, 0)).
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbda0(int p1)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            ag700_1_f_042920(e, 0);
            ag700_1_f_042930(e, 0);
        }
    }
}
//@ f_0dbde0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verändert die beiden Gruppen-Statuszähler aller Mitglieder der Gruppe p1 um p2 bzw. p3 (f_045190
 *   und f_0451c0).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die beiden Änderungswerte (p2, p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbde0(int p1, short p2, short p3)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            ag700_1_f_045190(e, p2);
            ag700_1_f_0451c0(e, p3);
        }
    }
}
//@ f_0dbe20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Begrenzt die beiden Eingabewerte p2 und p3 auf höchstens 100 und wendet sie anschließend über
 *   f_045190 und f_0451c0 auf alle Mitglieder der Gruppe p1 an.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die beiden Werte (p2, p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbe20(int p1, short p2, short p3)
{
    int e;
    short i;
    if (p2 > 100)
        p2 = 100;
    if (p3 > 100)
        p3 = 100;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            ag700_1_f_045190(e, p2);
            ag700_1_f_0451c0(e, p3);
        }
    }
}
//@ f_0dbe80
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt den Hungerwert aller Mitglieder der Gruppe p1 über f_042920(e, 0) auf 0 zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbe80(int p1)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_042920(e, 0);
    }
}
//@ f_0dbeb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt den Durstwert aller Mitglieder der Gruppe p1 über f_042930(e, 0) auf 0 zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbeb0(int p1)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0)
            ag700_1_f_042930(e, 0);
    }
}
//@ f_0dbee0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sichert die aktuelle 3D-/Kartenposition (X, Y, Z an +0x4b..+0x53) und Blickrichtung (+0x57) der
 *   Gruppe p1 in deren Sicherungsfeldern und markiert die Sicherung durch Setzen des Flags *(p1 + 0x59) = 1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbee0(int p1)
{
    short s;
    I(p1, 0x4b) = ag700_1_f_0de840(p1);
    I(p1, 0x4f) = ag700_1_f_0de860(p1);
    I(p1, 0x53) = ag700_1_f_0de880(p1);
    s = ag700_1_f_0de8c0(p1);
    *(char *)((p1) + 0x59) = 1;
    W(p1, 0x57) = s;
}
//@ f_0dbf10
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Stellt die zuvor mit f_0dbee0 gesicherte Position und Blickrichtung der Gruppe p1 wieder her,
 *   sofern das Sicherungsflag *(p1 + 0x59) == 1 gesetzt ist, und löscht das Flag anschließend.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dbf10(int p1)
{
    if (*(unsigned char *)((p1) + 0x59) == 1) {
        ag700_1_f_0de850(p1, I(p1, 0x4b));
        ag700_1_f_0de870(p1, I(p1, 0x4f));
        ag700_1_f_0de890(p1, I(p1, 0x53));
        ag700_1_f_0de8d0(p1, *(unsigned short *)((p1) + 0x57));
        *(char *)((p1) + 0x59) = 0;
    }
}
int f_156870(int p1, int p2, int p3);
int f_0422b0(int p1);
int f_144bf0(int p1, int p2);

void f_0dbf50(int p1, int p2)
{
    f_156870(p1, 0x6, (int)&ag700_1_d_1bb53c);
}

int f_0dbf70(int p1, int p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0 && f_144bf0(f_0422b0(e), p2) == 0)
            return 1;
    }
    return 0;
}
//@ f_0dbfb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob der durch den Zeiger p2 gegebene Held Mitglied der Gruppe p1 ist.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Heldenzeiger (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn der Held in der Gruppe enthalten ist, sonst 0.
 === Ende Beschreibung === */
int f_0dbfb0(int p1, int p2)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0 && e == p2)
            return 1;
    }
    return 0;
}
//@ f_0dbfe0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Gibt die Anzahl der handlungsfähigen Mitglieder der Gruppe p1 durch Weiterleitung an f_0db970
 *   zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Anzahl der handlungsfähigen Gruppenmitglieder zurück.
 === Ende Beschreibung === */
int f_0dbfe0(int p1)
{
    int f_0db970_alias(int);
#pragma aux f_0db970_alias "W?f_0db970$n(i)i" parm [eax] value [eax]
    return f_0db970_alias(p1);
}
//@ f_0dbff0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zählt alle lebenden (nicht toten, !f_042470(e)) Mitglieder der Gruppe p1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die Anzahl der lebenden Gruppenmitglieder zurück.
 === Ende Beschreibung === */
#pragma code_seg("zzz")
static void a_flush(void) {}
#pragma code_seg()
static void (*a_keep)(void) = a_flush;
int f_0dbff0(int p1)
{
    int e;
    int s;
    short i;
    s = 0;
    for (i = 0; i <= 6; i = i + 1) {
        e = SL(p1, i);
        if (e != 0) {
            if (!ag700_1_f_042470(e))
                s = s + 1;
        }
    }
    return s;
}
//@ f_0dc020
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt den Gruppenplatz-Index (0..6), auf dem sich der Held p2 innerhalb der Gruppe p1 befindet.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der gesuchte Heldenzeiger (p2).
 * - Rückgabewert: Gibt den Platzindex (0..6) oder -1 zurück, falls der Held nicht in der Gruppe ist.
 === Ende Beschreibung === */
int f_0dc020(int p1, int p2)
{
    int i;
    int v;
    int base = p1;
    v = p2;
    for (i = 0; (short)i <= 6; i = i + 1) {
        int e = SL(base, (short)i);
        if (e == v)
            return i;
    }
    return -1;
}
//@ f_0dc050
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 nach einem Helden, der den Gegenstand p2 besitzt: prüft bei p3 >= 0 gezielt
 *   den Ausrüstungsplatz p3, bei p3 == -2 die am Körper getragenen Plätze (0..14), bei p3 == -3 das
 *   Rucksack-Inventar (15..30) und bei p3 == -1 das gesamte Inventar über f_0d54f0.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Gegenstandskennung (p2) sowie der
 *   Suchbereich (p3).
 * - Rückgabewert: Gibt den Gruppenplatz-Index (0..6) des gefundenen Helden oder -1 zurück.
 === Ende Beschreibung === */
short f_0dc050(int p1, short p2, short p3)
{
    int e;
    int r;
    short k;
    if (p3 == -1) {
        r = ag700_1_f_0d54f0(p1, p2);
    } else {
        for (r = 0; (short)r <= 6; r = r + 1) {
            e = SL(p1, (short)r);
            if (e != 0) {
                if (p3 >= 0 && ag700_1_f_042a60(e, p3) == p2)
                    return r;
                if (p3 == -2) {
                    for (k = 0; k < 0xf; k = k + 1) {
                        if (ag700_1_f_042a60(e, k) == p2)
                            return r;
                    }
                }
                if (p3 == -3) {
                    for (k = 0xf; k <= 0x1e; k = k + 1) {
                        if (ag700_1_f_042a60(e, k) == p2)
                            return r;
                    }
                }
            }
        }
        r = -1;
    }
    return r;
}
//@ f_0dc110
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob der bevorzugte Held p2 oder andernfalls ein anderes Mitglied der Gruppe p1 (unter
 *   Ausschluss des zuletzt benutzten Platzes d_1a9670) einen Gegenstand vom Typ p4 über f_032470
 *   einsetzen/benutzen kann, und speichert den Platzindex des ausführenden Helden in *p3.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der bevorzugte Held (p2), ein
 *   Ausgabezeiger für die Heldenplatznummer (p3) sowie die beiden Aktionsparameter (p4, p5).
 * - Rückgabewert: Gibt 1 bei Erfolg oder 0 zurück, wenn kein Gruppenmitglied die Aktion ausführen konnte.
 === Ende Beschreibung === */
int f_0dc110(int p1, int p2, unsigned short *p3, int p4, int p5)
{
    int r;
    int e;
    unsigned short u;
    short i;
    r = 0;
    u = 99;
    if (ag700_1_d_1a9670 != -1) {
        u = ag700_1_f_0d54c0(p2);
        u = u & 0xff;
    }
    if ((short)u != ag700_1_d_1a9670 && ag700_1_f_032470(p2, p4, p5) != 0) {
        r = 1;
        u = ag700_1_f_0d54c0(p2);
        goto found;
    }
    for (i = 0; i <= 6; i = i + 1) {
        e = SR((*&p1), i);
        if (e != 0 && (unsigned char)ag700_1_f_0d54c0(e) != ag700_1_d_1a9670 && e != p2 && ag700_1_f_032470(e, p4, p5) != 0) {
            r = 1;
            u = ag700_1_f_0d54c0(e);
            goto found;
        }
    }
    goto done;
found:
    *p3 = u & 0xff;
done:
    ag700_1_d_1a9670 = 0xff;
    return r;
}
//@ f_0dc1f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft analog zu f_0dc110, ob der Held p2 oder ein anderes Mitglied der Gruppe p1 die
 *   Gegenstandsaktion f_0324e0(e, p4, p5) ausführen kann, und trägt den verwendeten Heldenplatz in *p3 ein.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der bevorzugte Held (p2), ein
 *   Ausgabezeiger für die Heldenplatznummer (p3) sowie die beiden Aktionsparameter (p4, p5).
 * - Rückgabewert: Gibt 1 bei Erfolg oder 0 zurück.
 === Ende Beschreibung === */
int f_0dc1f0(int p1, int p2, unsigned short *p3, int p4, int p5)
{
    int r;
    int e;
    unsigned short u;
    short i;
    r = 0;
    u = 99;
    if (ag700_1_d_1a9670 != -1) {
        u = ag700_1_f_0d54c0(p2);
        u = u & 0xff;
    }
    if ((short)u != ag700_1_d_1a9670 && ag700_1_f_0324e0(p2, p4, p5) != 0) {
        r = 1;
        u = ag700_1_f_0d54c0(p2);
        goto found;
    }
    for (i = 0; i <= 6; i = i + 1) {
        e = SR((*&p1), i);
        if (e != 0 && (unsigned char)ag700_1_f_0d54c0(e) != ag700_1_d_1a9670 && e != p2 && ag700_1_f_0324e0(e, p4, p5) != 0) {
            r = 1;
            u = ag700_1_f_0d54c0(e);
            goto found;
        }
    }
    goto done;
found:
    *p3 = u & 0xff;
done:
    ag700_1_d_1a9670 = 0xff;
    return r;
}
//@ f_0dc2d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Durchsucht die Gruppe p1 (beginnend beim bevorzugten Helden p2) nach dem ersten vorhandenen
 *   Gegenstand aus einer mit -1 terminierten Liste von Gegenstandskennungen (p3) und gibt bei Erfolg die
 *   Heldenplatznummer (*p4), den Inventarslot (*p5) und die gefundene Gegenstandskennung (*p6) zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der bevorzugte Held (p2), das
 *   -1-terminierte Array gesuchter Gegenstands-IDs (p3) sowie Ausgabezeiger für Heldenplatz (p4), Inventarslot
 *   (p5) und Gegenstands-ID (p6).
 * - Rückgabewert: Gibt 1 zurück, sobald einer der gesuchten Gegenstände gefunden wurde, sonst 0.
 === Ende Beschreibung === */
int f_0dc2d0(int p1, int p2, int p3, unsigned short *p4, short *p5, short *p6)
{
    extern unsigned short get_place_172(int);
#pragma aux get_place_172 "f_0d54c0" modify exact [eax edx]
    int t622_12;
    int r;
    short idx;
    short val;
    short sub;
    int e;
    short *q;
    short next_idx = 0;
    r = 0;
    idx = 0;
    for (;;) {
        q = idx + (short *)p3;
        if ((t622_12 = *q) == -1)
            break;
        val = *q;
        if (p2 != 0) {
            sub = ag700_1_f_0d4aa0(p2, val);
            e = p2;
        } else {
            sub = -1;
        }
        if (sub == -1) {


            for (next_idx = 0; next_idx <= 6; next_idx = next_idx + 1) {
                e = SL(p1, next_idx);
                if (e != 0 && e != p2) {
                    sub = ag700_1_f_0d4aa0(e, val);
                    if (sub != -1)
                        goto found;
                }
            }
        } else {
found:
            r = 1;
        }
        if (r == 1 && e != 0) {
            unsigned short u = get_place_172(e);
            d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0; // haelt die Registerzuteilung wie im Original
            d_1bb53c = (d_1bb53c & 0) ? 0 : d_1bb53c; // haelt die Registerzuteilung wie im Original
            d_1be17c = (d_1be17c & 0) ? 0 : d_1be17c; // haelt die Registerzuteilung wie im Original
            *p4 = u & 0xff;
            *p6 = val;
            *p5 = sub;
        }
        next_idx = (next_idx & 0) ? (short)0 : next_idx; // haelt die Registerzuteilung wie im Original
        int hold_a = (d_1a34e0 & 0) ? 0 : d_1a34e0;
        int hold_b = d_1be17c;
        next_idx = (short)(idx & 0xffff) + 1;
        int cur_r = r;
        r = (cur_r & 0) ? 0 : cur_r; // haelt die Registerzuteilung wie im Original
        d_1a34e0 = hold_a;
        d_1be17c = hold_b;
        { int slot905=d_1bb53c; d_1bb53c=slot905; }
        idx = (next_idx & 0) ? (short)0 : next_idx;
        if (cur_r != 0) break;
    }


    return r;
}
//@ f_0dc3c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet auf den Porträts aller lebenden Mitglieder der Gruppe p1 eine farbige
 *   Status-/Schadens-Überblendung (f_0d5040) mit der Dauer p2 und den Parametern p3..p5.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Animationsdauer (p2) sowie die
 *   Farb-/Animationsparameter (p3, p4, p5).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dc3c0(int p1, int p2, signed char p3, signed char p4, signed char p5)
{
    int e;
    short i;
    for (i = 0; i <= 6; i = i + 1) {
        e = SR(p1, i);
        if (e != 0) {
            if (!ag700_1_f_042470(e)) {
                ag700_1_f_0d5040(e, ag700_1_f_0d4c80(e), p2, (*&p3), p4, p5);
            }
        }
    }
}
//@ f_0dc430
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob sich zwei Teilgruppen (p1 und p2) auf derselben Karte (W(p1, 0x25) == W(p2, 0x25) != -1),
 *   innerhalb eines Koordinatenabstands von höchstens 0x320000 in X-, Y- und Z-Richtung und in direkter
 *   Sicht-/Begegnungslinie (f_1512d8 == 0) befinden.
 * - Eingaben: Übergeben werden die Zeiger auf die beiden zu vergleichenden Gruppen-Objekte (p1, p2).
 * - Rückgabewert: Gibt 1 zurück, wenn die beiden Teilgruppen in Reichweite füreinander stehen, sonst 0.
 === Ende Beschreibung === */
int f_0dc430(int p1, int p2)
{
    int r;
    r = 0;
    if (W(p1, 0x25) != -1)
    if (W(p1, 0x25) == W(p2, 0x25)) {
        if (I(p1, 0x2d) - 0x320000 <= I(p2, 0x2d))
        if (I(p1, 0x2d) + 0x320000 >= I(p2, 0x2d)) {
            if (I(p1, 0x31) - 0x320000 <= I(p2, 0x31))
            if (I(p1, 0x31) + 0x320000 >= I(p2, 0x31)) {
                if (I(p1, 0x35) - 0x320000 <= I(p2, 0x35))
                if (I(p1, 0x35) + 0x320000 >= I(p2, 0x35)) {
                    if (ag700_1_f_1512d8(I(p1, 0x2d), I(p1, 0x31), I(p1, 0x35), I(p2, 0x2d), I(p2, 0x31), I(p2, 0x35)) == 0)
                        r = 1;
                }
            }
        }
    }
    return r;
}
//@ f_0dc4d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Rechnet die Farbbytes eines 32x32 Pixel großen Heldenporträts (0x400 Bytes in p1) auf abgedunkelte
 *   bzw. entsättigte Palettenindizes um, um Mitglieder einer derzeit inaktiven Teilgruppe optisch in der
 *   Statusleiste zu kennzeichnen.
 * - Eingaben: Übergeben wird der Zeiger auf den 1024-Byte-Pixelpuffer des Heldenporträts (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dc4d0(unsigned char *p1)
{
    short i;
    unsigned char c;
    for (i = 0; i < 0x400; i = i + 1) {
        c = *p1;
        if (c == 0xbd || (c >= 0xd0 && c < 0xd5) || (c >= 0xe0 && c < 0xee)) {
            c = c + 2;
        } else if (c == 0xa3 || c == 0xa9 || c == 0xc7 || c == 0xcf || c == 0xd7 || c == 0xdf || c == 0xef || c == 0xf6 || c == 0xfe) {
            c = 0xfe;
        } else if (c == 0xa6) {
            c = 0xcc;
        } else if (c == 0xad) {
            c = 0xed;
        } else if (c == 0xae) {
            c = 0xd7;
        } else if (c == 0xaf) {
            c = 0xd5;
        } else if (c == 0xb7 || c == 0xbc) {
            c = 0xea;
        } else if (c == 0xbf) {
            c = 0xb5;
        } else if (c == 0xd6) {
            c = 0xae;
        } else if (c == 0xf7) {
            c = 0xa1;
        } else if (c == 0xf8) {
            c = 0xbe;
        } else if (c == 0xf9) {
            c = 0xb0;
        } else if (c == 0xfa) {
            c = 0xf7;
        } else if (c == 0xfb) {
            c = 0xf4;
        } else if (c == 0xfc) {
            c = 0xd1;
        } else if (c == 0xfd) {
            c = 0xb9;
        } else if (c == 0xff) {
            c = 0xc8;
        } else if (c == 0) {
            c = 0;
        } else {
            c = c + 1;
        }
        *p1++ = c;
    }
}
