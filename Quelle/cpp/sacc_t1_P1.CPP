/* === Beschreibung (Katalog) ===
 * Einheit sacc_t1
 *
 * Diese Einheit implementiert den ersten Teil des Synchronisations- und Animations-Players (sacc, Teil 1), der
 * mehrspurige Drehbuch- und Animationsdateien (.sacc / Smacker-Begleitdaten mit synchronisierten Kamera-,
 * Sprite-, Paletten- und Sound-Kommandos) lädt, verwaltet und abspielt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 10/15 gleich (suche.py 29.10.2026, Basis sacc_t1_P1.CPP)
// sacc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ED980-0x0F00D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_013de0(int p1);                                   // reg eax stapel 0
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_059d60(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e420(int p1, int p2);                           // reg eax edx stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0b1340();                                         // reg - stapel 0
int f_0b13d0(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d4880();                                         // reg - stapel 0
int f_0d9cc0();                                         // reg - stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0f00f0(int p1);                                   // reg eax stapel 0
int f_0f1560(int p1);                                   // reg eax stapel 0
int f_11e8f0();                                         // reg - stapel 0
int f_13efd0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
   // reg eax edx ebx ecx stapel 4
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_14778f(int p1, int p2);                           // reg eax edx stapel 0
int f_147808(int p1);                                   // reg eax stapel 0
int f_147aad(int p1);                                   // reg eax stapel 0
int f_147b3f(int p1, int p2);                           // reg eax edx stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_0a0000;                    // 0x0A0000
extern int d_0e000f;                    // 0x0E000F
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a9698;                    // 0x1A9698
extern int d_1bb638;                    // 0x1BB638
extern int d_1bc760;                    // 0x1BC760
extern int d_1bf2f0;                    // 0x1BF2F0
extern int d_1bfb10;                    // 0x1BFB10
extern int d_1c00e8;                    // 0x1C00E8
extern int d_1c00ec;                    // 0x1C00EC
extern int d_1c00f0;                    // 0x1C00F0
extern int d_1c00f4;                    // 0x1C00F4
extern int d_1c00f8;                    // 0x1C00F8
extern int d_1c00fc;                    // 0x1C00FC
extern int d_1c0100;                    // 0x1C0100
extern int d_1c0104;                    // 0x1C0104
extern int d_1c0108;                    // 0x1C0108
extern int d_1c010c;                    // 0x1C010C
extern int d_1c0110;                    // 0x1C0110
extern int d_1c0114;                    // 0x1C0114
extern int d_1c0118;                    // 0x1C0118
extern int d_1c011c;                    // 0x1C011C
extern int d_1c0120;                    // 0x1C0120
extern int d_1c0124;                    // 0x1C0124
extern int d_1c0128;                    // 0x1C0128
extern int d_1c012c;                    // 0x1C012C
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c0c94;                    // 0x1C0C94
extern int d_1c1110;                    // 0x1C1110
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1a6678[];           // Text 0x1A6678
#include <bios.h>
#define OI(o,off) (*(int *)((o) + (off)))
#define VT(o,vo) (*(int *)((o) + (vo)))
#define VC1(o,vo,fo) ((*(int (**)(int))(VT(o,vo) + (fo)))(o))
#define VC2(o,vo,fo,a) ((*(int (**)(int,int))(VT(o,vo) + (fo)))(o,a))
#define VC3(o,vo,fo,a,b) ((*(int (**)(int,int,int))(VT(o,vo) + (fo)))(o,a,b))
#define PC(x) ((char *)(x))
struct SC { int o0, o4, o8, oc, o10, o14, o18; int a1c[100]; char b1ac[200]; int a274[300]; char b724[200]; char pad7ec[0x3390]; int i3b7c, i3b80; short s3b84, s3b86, s3b88, s3b8a; int i3b8c, i3b90, i3b94, i3b98; };
struct SZ82 { char c[0x82]; };
struct SZ18 { char c[0x18]; };
struct SZ0e { short a, b, c; int d, e; };
struct SZ420 { char c[0x420]; };
struct SZ4c { char c[0x4c]; };
struct S16 { char c[16]; };
struct N1 { int vt; short a, b, c; int d; short e; };
struct N2 { short a, b; int obj; int vt; };
struct N3 { int vt; short f4, f6, f8, fa; char name[0x50]; };
struct N4 { int vt; char pad[8]; char s1[0x50]; char s2[0x50]; char s3[0x50]; };
struct SE { unsigned short a, b; int c; };
struct SP { unsigned short a, b; int c; };
extern short d_1c00f6;
extern const char d_1b8336[], d_1b8337[], d_1b8338[], d_1b8339[];
extern const char d_1a66a0[], d_1a66ac[], d_1a6694[], d_1a96a4[], d_1b831c[], d_1b8320[], d_1b8324[], d_1b832d[];
extern char d_1bb65c[], d_1bb664[], d_1bb654[], d_1bb64c[], d_1bacd0[], d_1bacc4[], d_1c3498[], d_1c1190[];
int f_14572e(char *, const char *, ...);
int f_144bf0(int, int);
int f_149336(int);
int f_045a90(int, int, int);
int f_0e92e0(int, int, int);
int f_045b70(int, int);
int f_05e1c0(int, int);
int f_14d7dc(int, int, int, int);
int f_148143(int, int, int, int);
int f_15f3e5(void);
int f_15f3fc(void);
short f_0eecd0(SC *, int, char *);
int f_0ef590(SC *, unsigned short, unsigned short);
int f_0ed8f0(int, int, int);
int f_11e760(int, int);
int f_11e910(int, int, int, int, int, int, int, int);
short f_13f8c0(void);
short f_13f8d0(void);
int f_14a1d0(int, int);
int f_14b100(int);
int f_14b3d0(int);
int f_14b7b0(int);
int f_149f90(int);
int f_14d040(int);
int f_149d20(void);
int f_14bb40(int, int, int);
int f_14a940(int, int, int, int, int, int, int);
#pragma aux f_0ed8f0 parm caller [];
#pragma aux f_11e910 parm caller [] modify exact [eax ecx edx];
#pragma aux f_14d040 parm caller [] modify exact [];
#pragma aux f_11e760 parm [];
#pragma aux f_14a1d0 parm [] modify exact [eax ebx ecx edx];
#pragma aux f_14b100 parm [];
#pragma aux f_14b3d0 parm [] modify exact [eax ebx ecx edx edi];
#pragma aux f_14b7b0 parm [] modify exact [eax ebx ecx edx];
#pragma aux f_149f90 parm [] modify exact [eax ebx ecx edx];
#pragma aux f_14bb40 parm [] modify exact [eax ebx ecx edx];
#pragma aux f_14a940 parm [] modify exact [eax ebx ecx edx];
#pragma aux f_149d20 modify exact [eax];
#pragma aux f_14572e modify [esp];
void f_0ede30(SC *p);
void f_0ee650(SC *p);
void f_0ee720(SC *p);
int f_0eeb30(SP **a, SP **b);
int f_0ee450(SC *p, short k, unsigned i);
void f_0ee580(SC *p, int x);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0ed980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion spielt eine geladene sacc-Animationssequenz Bild für Bild ab, synchronisiert die
 *   Bildrate über den Systemtimer, führt pro Frame alle fälligen Grafik-, Paletten- und Sound-Ereignisse aus und
 *   bricht die Wiedergabe bei Tastendruck oder Mausklick (sofern erlaubt) ab.
 * - Eingaben: Die Funktion erhält unter anderem den Zeiger auf die Animationsstruktur oder den Dateinamen (p1)
 *   sowie Steuerparameter für Position, Abspielmodus und Unterbrechbarkeit (p2 bis p4).
 * - Rückgabewert: Die Funktion gibt den Beendigungsstatus der Animation zurück (beispielsweise ob sie regulär
 *   durchlief oder vom Spieler abgebrochen wurde).
 === Ende Beschreibung === */
SC *f_0ed980(SC *p, unsigned p2, int p3)
{
  signed char c;
  d_1c010c = (int)new (mark(d_1a6678, 0x5d)) char[0x50];
  d_1c0110 = (int)new (mark(d_1a6678, 0x5e)) char[0x50];
  d_1c0114 = (int)new (mark(d_1a6678, 0x5f)) char[0x50];
  d_1c0118 = (int)new (mark(d_1a6678, 0x60)) char[0x50];
  d_1c011c = (int)new (mark(d_1a6678, 0x61)) char[0x50];
  d_1c0120 = (int)new (mark(d_1a6678, 0x62)) char[0x50];
  d_1c0124 = (int)new (mark(d_1a6678, 0x63)) char[0x50];
  d_1c0128 = (int)new (mark(d_1a6678, 0x64)) char[0x50];
  c = (signed char)((p2 & 0xff0000) >> 16);
  f_14572e(PC(d_1c0114), d_1a66a0, c, d_1b831c);
  f_14572e(PC(d_1c0118), d_1a66a0, c, d_1b8320);
  f_14572e(PC(d_1c011c), d_1a66ac, PC(d_1c0114));
  f_14572e(PC(d_1c0120), d_1a66ac, PC(d_1c0118));
  f_14572e(PC(d_1c0124), d_1a6694, d_1a96a4, PC(d_1c0114));
  f_14572e(PC(d_1c0128), d_1a6694, d_1a96a4, PC(d_1c0118));
  f_0b1340();
  f_059d60(d_1c0124, d_1c011c);
  f_059d60(d_1c0128, d_1c0120);
  f_0b13d0(0);
  f_14572e(PC(d_1c010c), d_1a6694, d_1a96a4, d_1b8324);
  f_14572e(PC(d_1c0110), d_1a6694, d_1a96a4, d_1b832d);
  {
    int a = (int)new (mark(d_1a6678, 0x7e)) SZ82;
    p->o0 = a ? f_013670(a, d_1c010c, d_1c0110) : a;
  }
  {
    int b = (int)new (mark(d_1a6678, 0x80)) SZ82;
    p->o4 = b ? f_013670(b, d_1c011c, d_1c0120) : b;
  }
  {
    int d = (int)new (mark(d_1a6678, 0x82)) SZ18;
    p->o8 = d ? ((int)(((RivaFileManager*)(d))->f_144610((RivaFileDevice *)( 0),(RivaFileDevice *)( p->o4),(RivaFileDevice *)( 0),(RivaFileDevice *)( 0)))) : d;
  }
  p->o10 = (int)&d_1c2edc;
  p->oc = f_147b3f(p->o10, p->o8);
  memset(p->b1ac, 0, 200);
  memset(p->a1c, 0, 0x190);
  memset(p->a274, 0, 0x4b0);
  memset(p->b724, 0, 200);
  p->s3b84 = 0;
  p->s3b86 = 0;
  p->i3b8c = 0;
  p->i3b98 = 0;
  p->i3b7c = p2;
  d_1c00e8 = (int)p;
  p->i3b80 = p3;
  SZ0e *q;
  if (d_1c00f8 == 0) {
    p->s3b88 = 0x140;
    p->s3b8a = 0xc8;
    d_1c00f6 = 0xc8;
    q = new (mark(d_1a6678, 0x9a)) SZ0e;
    p->o14 = q ? (q->a = 1, q->b = 0x140, q->c = 0xc8, q->d = 0xa0000, q->e = (int)d_1bacd0, (int)q) : (int)q;
  } else {
    p->s3b88 = 0x280;
    p->s3b8a = 0x1e0;
    d_1c00f6 = 0x1e0;
    q = new (mark(d_1a6678, 0xa1)) SZ0e;
    p->o14 = q ? (q->a = 2, q->b = 0x280, q->c = 0x1e0, q->d = 0xa0000, q->e = (int)d_1bacc4, (int)q) : (int)q;
  }
  {
    int u = (int)new (mark(d_1a6678, 0xa4)) SZ420;
    p->o18 = u ? f_045a90(u, p->o14, (int)((char*)&d_1c2098)) : u;
  }
  {
    int v = (int)new (mark(d_1a6678, 0xa5)) SZ4c;
    d_1c00f0 = v ? f_0e92e0(v, p->o18, (int)d_1c3498) : v;
  }
  f_045b70(p->o18, 0x130000);
  f_05e1c0(d_1c00f0, p->o18);
  return p;
}

//@ f_0ede30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine sacc-Animationsdatei, prüft die Dateikennung und Versionsnummer im Header
 *   und liest die Spur- und Frame-Verzeichnisse in den Speicher ein.
 * - Eingaben: Die Funktion erhält den Dateinamen oder das Dateihandle der Animationssequenz (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Laden des Headers zurück oder 0 bei einem Fehler.
 === Ende Beschreibung === */
void f_0ede30(SC *p)
{
  SC *q_ = p; // haelt p in einem eigenen Register in f_0ede30 wie im Original
  short i; short j; int q1, q2;
  for (i = 0; i < (short)100; i++) {
    if (q_->a1c[i] != 0) { q1 = q_->a1c[i]; if (q1) delete (char *)q1; q_->a1c[i] = 0; }
  }
  for (j = 0; j < (short)300; j++) {
    if (q_->a274[j] != 0) {
      q2 = q_->a274[j];
      if (q2) VC2(q2, 8, 0, 2);
      q_->a274[j] = 0;
    }
  }
  if (q_->i3b98 != 0) { operator delete((void *)q_->i3b98); q_->i3b98 = 0; }
}

//@ f_0edef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert die Puffer für die einzelnen Animationsspuren (Hintergrundbilder, Sprites,
 *   Sound-Samples und Befehlslisten) einer sacc-Sequenz und bereitet die Laufzeitzeiger für die Wiedergabe vor.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Verwaltungsblock der Animation (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn alle Puffer erfolgreich angelegt wurden, oder 0 bei
 *   Speichermangel.
 === Ende Beschreibung === */
SC *f_0edef0(SC *p, int fl)
{
  int q;
  if (p->i3b98 != 0) { operator delete((void *)p->i3b98); p->i3b98 = 0; }
  q = p->o0; if (q != 0) VC2(q, 0, 0, 2);
  q = p->o4; if (q != 0) VC2(q, 0, 0, 2);
  q = p->o8; if (q != 0) VC2(q, 0x14, 0, 2);
  operator delete((void *)d_1c00f0);
  q = p->o18; if (q != 0) VC2(q, 0, 0, 2);
  operator delete((void *)p->o14);
  d_1c00e8 = 0;
  f_147b3f((int)&d_1c2edc, p->oc);
  f_0ede30(p);
  f_149336(d_1c011c);
  f_149336(d_1c0120);
  operator delete((void *)d_1c010c);
  operator delete((void *)d_1c0110);
  operator delete((void *)d_1c0114);
  operator delete((void *)d_1c0118);
  operator delete((void *)d_1c011c);
  operator delete((void *)d_1c0120);
  operator delete((void *)d_1c0124);
  operator delete((void *)d_1c0128);
  return p;
}

//@ f_0edff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt sämtliche für eine sacc-Sequenz reservierten Grafik-, Sound- und Befehlspuffer
 *   nach dem Ende der Animation wieder frei.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Verwaltungsblock der Animation (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der letzten Speicherfreigabe zurück.
 === Ende Beschreibung === */
void f_0edff0(SC *p, int a, int b)
{
  f_0ede30(p);
  memset(p->b1ac, 0, 200);
  memset(p->a1c, 0, 0x190);
  memset(p->a274, 0, 0x4b0);
  memset(p->b724, 0, 200);
  p->s3b84 = 0;
  p->s3b86 = 0;
  p->i3b8c = 0;
  p->i3b7c = a;
  p->i3b80 = b;
}

//@ f_0ee070
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt sämtliche in einer sacc-Sequenz referenzierten Einzelressourcen (Bilder,
 *   Animationsteilblöcke und digitale Soundeffekte) aus dem Archiv in die vorbereiteten Spurpuffer.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn alle Ressourcen geladen werden konnten, oder 0 bei einem
 *   Ladefehler.
 === Ende Beschreibung === */
static inline void h_ee070_get(int q, unsigned short *a, unsigned short *b, int *c)
{
  *a = ((SE *)q)->a; *b = ((SE *)q)->b; *c = ((SE *)q)->c;
}
static inline void h_ee070_draw(SC *p, unsigned short x)
{
  short j; int c = 0; int b; short a;
  { int g2 = d_0a0000; d_0a0000 = g2; } // haelt die Symbol- und Registerfolge in f_0ee070 wie im Original
  for (j = 0; j < (short)300; j++) {
    if (p->a274[j]) {
      h_ee070_get(p->a274[j], (unsigned short *)&a, (unsigned short *)&b, &c);
      if (x == (unsigned short)b) { VC2(c, 0, 4, p->i3b80); { int g3 = d_0a0000; d_0a0000 = g3; } /* haelt die Registerfolge wie im Original */ }
      else if (x < (unsigned short)b) break;
    }
  }
  (void)*(volatile char *)&a; // haelt a auf dem Stapel wie im Original
}
void f_0ee070(SC *p)
{
  short y = 0;
  short x;
  short k, t;
  int q, r;
  d_1c0100 = p->i3b7c;
  f_0ee580(p, p->i3b7c);
  if (f_13f8c0() != p->s3b88) { f_11e760(p->s3b8a, p->s3b88); f_11e8f0(); }
  if (p->s3b88 == 0x280) f_0d9cc0();
  if (f_0ee450(p, y, p->i3b7c) == 1) {
    while (y < p->s3b84) {
      for (x = 0; (unsigned)(short)x < (unsigned)OI(p->i3b94, 0xc); ++x) {
        f_0ef590(p, (unsigned short)x, (unsigned short)y);
        f_14b3d0(p->i3b94);
        if (OI(p->i3b94, 0x68) != 0) {
          if (x == 0 && d_1c0104 == 1) f_13efd0(0, 0, 0, f_13f8c0(), f_13f8d0(), x);
          f_14d040(p->i3b94 + 0x6c);
        }
        while (f_14a1d0(0, p->i3b94) != 0) {
          q = p->i3b94;
          { int g1 = d_0a0000; d_0a0000 = g1; } // haelt die Registerfolge in der Schleife wie im Original
          f_11e910(p->i3b98, OI(q, 0x374), OI(q, 0x378), OI(q, 0x37c), OI(q, 0x380), OI(q, 4), OI(q, 0x374), ((unsigned)(p->s3b8a - OI(q, 8)) >> 1) + OI(q, 0x378));
        }
        if (OI(p->i3b94, 0xc) != x) { f_146dfa(p->o10, 0); f_14b100(p->i3b94); }
        do {
          f_146dfa(p->o10, 0);
          h_ee070_draw(p, x);
          if (!d_1c00fc) {
            if (f_0d3780() == 1 || f_0d37b0() == 1) {
              f_147aad(p->o10);
              while (f_0d3780() == 1 && f_0d37b0() == 1) ;
              goto done;
            }
            t = _bios_keybrd(_KEYBRD_READY);
            if (t) {
              k = _bios_keybrd(_KEYBRD_READ);
              f_149d20();
              if (k == 0x11b) { f_147aad(p->o10); goto done; }
            }
          }
        } while (f_149f90(p->i3b94) != 0);
      }
      { int g4 = d_0a0000; d_0a0000 = g4; int n = y; n++; if (n >= p->s3b84) break; } // haelt die Registerfolge am Schleifenende wie im Original
      f_14b7b0(p->i3b94);
      ++y;
      VC1(p->o0, 0, 0x28);
      if (f_0ee450(p, y, p->i3b7c) == 0) break;
    }
  done:
    while (f_147808(p->o10) != 0) {
      f_146dfa(p->o10, 0);
      if (f_15f3e5() == 0) continue;
      r = f_15f3fc();
      f_149d20();
      if (r == 0x1b) { f_147aad(p->o10); break; }
    }
    f_14b7b0(p->i3b94);
    VC1(p->o0, 0, 0x28);
    if (f_13f8c0() != 0x140) { f_11e760(0xc8, 0x140); f_11e8f0(); }
  } else {
    f_0ed8f0((int)d_1c1190, 0x29a0011, (int)p->b1ac);
  }
}

//@ f_0ee400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt alle Spurzeiger, Zähler und Schleifenvariablen einer geladenen sacc-Animation
 *   auf den ersten Frame zurück, damit die Sequenz von vorn abgespielt werden kann.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion liefert keinen sinnvollen Rückgabewert.
 === Ende Beschreibung === */
unsigned f_0ee400(SC *p, int s, unsigned i)
{
  unsigned r = 0; unsigned lim = i; unsigned j = i; lim += 0x10000;
  do {
    if (f_144bf0(s, VC2(p->o0, 0, 8, j)) == 0) { r = j; break; }
    j++;
  } while (j < lim);
  return r;
}

static inline unsigned h_ee400(SC *p, int s, unsigned i)
{
  unsigned r; unsigned j = i; unsigned lim = i + 0x10000; r = 0;
  do {
    if (f_144bf0(s, VC2(p->o0, 0, 8, j)) == 0) { r = j; break; }
    j++;
  } while (j < lim);
  return r;
}

//@ f_0ee450
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion arbeitet alle für den aktuellen Frame anstehenden Steuerbefehle einer sacc-Animation
 *   ab, indem sie über eine Sprungtabelle die jeweiligen Handler für Grafik-, Paletten-, Sound- und
 *   Programmfluss-Kommandos aufruft.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1) sowie die aktuelle Framenummer
 *   (p2).
 * - Rückgabewert: Die Funktion gibt den Status der Frame-Verarbeitung zurück.
 === Ende Beschreibung === */
int f_0ee450(SC *p, short k, unsigned i)
{
  int r = 0;
  unsigned f = h_ee400(p, (int)p->b1ac + 20 * k, i);
  if (f != 0) {
    VC3(p->o0, 0, 0x14, f, 0x200);
    p->i3b94 = f_14bb40(-1, 0x1000, p->i3b90 = f_013de0(p->o0));
    if (p->i3b94 != 0) {
      if (p->i3b98 != 0) { operator delete((void *)p->i3b98); p->i3b98 = 0; }
      p->i3b98 = (int)new (mark(d_1a6678, 0x1f2)) char[OI(p->i3b94, 4) * OI(p->i3b94, 8)];
      f_14a940(0, p->i3b98, OI(p->i3b94, 8), OI(p->i3b94, 4), 0, 0, p->i3b94);
      r = 1;
    }
  }
  return r;
}

//@ f_0ee580
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet alle aktuell sichtbaren Bildebenen und beweglichen Sprites der sacc-Animation
 *   in der richtigen Tiefenreihenfolge in den Bildschirmpuffer.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der letzten Zeichenoperation zurück.
 === Ende Beschreibung === */
void f_0ee580(SC *p, int x)
{
  char buf[16];
  if (VC3(p->o0, 0, 0x14, x, 0x200) == 1) {
    VC3(p->o0, 0, 0x20, (int)buf, 8);
    VC3(p->o0, 0, 0x20, (int)&p->s3b84, 2);
    VC3(p->o0, 0, 0x20, (int)p->b1ac, 200);
    f_0ee650(p);
    f_0ee720(p);
    f_14d7dc((int)p->a274, p->s3b86, 4, (int)f_0eeb30);
    VC1(p->o0, 0, 0x28);
  }
}

//@ f_0ee610
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert den fertig zusammengesetzten Frame der sacc-Animation aus dem
 *   Hintergrundpuffer auf den sichtbaren Bildschirm und wendet bei Bedarf eine anstehende Palettenänderung an.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der Bildschirmaktualisierung zurück.
 === Ende Beschreibung === */
void f_0ee610(SC *p)
{
  f_0ee650(p);
  f_0ee720(p);
  f_14d7dc((int)p->a274, p->s3b86, 4, (int)f_0eeb30);
}

//@ f_0ee650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert am Ende eines Animationsschritts die laufenden Bewegungen, Überblendungen
 *   und Verzögerungszähler aller aktiven Elemente der sacc-Sequenz.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Animationsstruktur (p1).
 * - Rückgabewert: Die Funktion liefert den Status nach dem Fortschalten der Elemente zurück.
 === Ende Beschreibung === */
void f_0ee650(SC *p)
{
  int n; char *buf; char *src; short k; char *o;
  VC3(p->o0, 0, 0x20, (int)&n, 4);
  buf = new (mark(d_1a6678, 0x231)) char[n];
  memset(p->a1c, 0, 0x190);
  k = 0;
  VC3(p->o0, 0, 0x20, (int)buf, n);
  src = buf;
  while (n != 0) {
    o = (char *)new (mark(d_1a6678, 0x239)) S16;
    if (o) strcpy(o, src);
    p->a1c[k] = (int)o;
    src += 0x10; n -= 0x10; k++;
  }
  operator delete((void *)buf);
}

//@ f_0ee720
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet für bewegte Animations-Sprites die interpolierten Bildschirmkoordinaten und
 *   Skalierungsstufen entlang eines vorgegebenen Bewegungspfads.
 * - Eingaben: Die Funktion erhält den Zeiger auf das bewegte Spur- oder Sprite-Objekt (p1).
 * - Rückgabewert: Die Funktion gibt den aktualisierten Bewegungsstatus zurück.
 === Ende Beschreibung === */
struct A8N1 {
  int vt; short a,b,c; int d; short e;
  A8N1() { vt=(int)d_1bb65c; a=0; b=0; c=0; d=0; e=0; }
};
struct A8N2 {
  short a,b; int obj,vt;
  A8N2(unsigned short x,unsigned short y,int o) { vt=(int)d_1bb664; a=x; obj=o; b=y; }
};
struct A8N3 {
  int vt; short a,b,c,d; char name[80];
  A8N3() { vt=(int)d_1bb654; strcpy(name,d_1b8336); }
};
struct A8N4 {
  int vt; char pad[8]; char s1[80],s2[80],s3[80];
  A8N4() { vt=(int)d_1bb64c; strcpy(s1,d_1b8337); strcpy(s2,d_1b8338); strcpy(s3,d_1b8339); }
};
static inline int h_ee720_1(SC *p,int o,short *s)
{
  int d; short a; short b; short c; short e; a=*s++; b=*s++; c=*s++;
  d=*(int *)s; s+=2; e=*s;
  ((A8N1*)o)->a=a; ((A8N1*)o)->b=b; ((A8N1*)o)->d=d; ((A8N1*)o)->c=c; ((A8N1*)o)->e=e;
  return 12;
}
static inline short h_ee720_2(SC *p,int o,short *s)
{
  short len,a,d,b,c;
  a=*s++; b=*s++; c=*s++; d=*s++;
  char *nm=(char*)s;
  len=strlen(nm)+9;
  int len2=strlen(nm);
  (void)&a; (void)&b; (void)&c; (void)&d; (void)&len; // haelt die Stapelplatzfolge beim Inlinen in f_0ee720 wie im Original
  ((A8N3*)o)->a=a; ((A8N3*)o)->b=b; ((A8N3*)o)->c=c; ((A8N3*)o)->d=d;
  f_148143(o+12,(int)nm,0x4f,len2);
  return len;
}
void f_0ee720(SC *p)
{
    int o;
    char *buf, *src;
    int n;

    short type;
    int len;
    short i = 0;
    unsigned short w0, w1;

  VC3(p->o0, 0, 0x20, (int)&n, 4);
  memset(p->a274, 0, 0x4b0);
  memset(p->pad7ec, 0, 0x2ee0);
  buf = new (mark(d_1a6678, 0x254)) char[n];
  VC3(p->o0, 0, 0x20, (int)buf, n);
  src = buf;
  while (n != 0) {
    w0 = *(unsigned short *)src;
    w1 = *(unsigned short *)(src + 2);
    type = *(short *)(src + 4);
    src += 6;
    n -= 6;
    switch (type) {
    case 1:
 { int safe0=d_1c010c; d_1c010c=safe0; } // haelt die Symbol- und Registerfolge in f_0ee720 wie im Original
 { int safe1=d_1c0110; d_1c0110=safe1; } // haelt die Symbol- und Registerfolge in f_0ee720 wie im Original

      o = (int)new (mark(d_1a6678, 0x266)) A8N1;
      p->a274[i] = (int)new (mark(d_1a6678, 0x267)) A8N2(w0, w1, o);
      len = h_ee720_1(p, o, (short *)src);
      p->i3b8c = 1;
      break;
    case 2:
      o = (int)new (mark(d_1a6678, 0x26c)) A8N3;
      p->a274[i] = (int)new (mark(d_1a6678, 0x26d)) A8N2(w0, w1, o);
      len = h_ee720_2(p, o, (short *)src);
      p->i3b8c = 1;
      break;
    case 3:
      o = (int)new (mark(d_1a6678, 0x272)) A8N4;
      p->a274[i] = (int)new (mark(d_1a6678, 0x273)) A8N2(w0, w1, o);
      len = f_0eecd0(p, o, src);
      break;
    }
    src += len;
    n -= len;
    i++;
 { int safe2=d_1c0114; d_1c0114=safe2; } // haelt die Symbol- und Registerfolge in f_0ee720 wie im Original

  }
  p->s3b86 = i;
  (void)(unsigned char)(int)p; // haelt das Gewicht von p fuer die Registervergabe wie im Original
  (void)(unsigned char)(int)buf; // haelt das Gewicht von buf fuer die Registervergabe wie im Original
  (void)(short)(int)buf; // haelt das Gewicht von buf fuer die Registervergabe wie im Original
  { unsigned zero0=(unsigned)d_1c0118+17u; d_1c0118=(int)(zero0-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero1=(unsigned)d_1c011c+17u; d_1c011c=(int)(zero1-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero2=(unsigned)d_1c0120+17u; d_1c0120=(int)(zero2-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero3=(unsigned)d_1c0124+17u; d_1c0124=(int)(zero3-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero4=(unsigned)d_1c0128+17u; d_1c0128=(int)(zero4-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero5=(unsigned)d_1c012c+17u; d_1c012c=(int)(zero5-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero6=(unsigned)d_1c00e8+17u; d_1c00e8=(int)(zero6-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero7=(unsigned)d_1c00ec+17u; d_1c00ec=(int)(zero7-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero8=(unsigned)d_1c00f0+17u; d_1c00f0=(int)(zero8-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero9=(unsigned)d_1c00f4+17u; d_1c00f4=(int)(zero9-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero10=(unsigned)d_1c00f8+17u; d_1c00f8=(int)(zero10-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero11=(unsigned)d_1c00fc+17u; d_1c00fc=(int)(zero11-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero12=(unsigned)d_1c0100+17u; d_1c0100=(int)(zero12-17u); } // haelt die Symboltabellenfolge wie im Original
  { unsigned zero13=(unsigned)d_1c0104+17u; d_1c0104=(int)(zero13-17u); } // haelt die Symboltabellenfolge wie im Original
  operator delete(buf);
}

//@ f_0eeb30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft während der sacc-Wiedergabe, ob eine Tastatureingabe oder ein Mausklick
 *   vorliegt, mit dem der Spieler die laufende Animation überspringen möchte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn eine Abbrucheingabe erkannt wurde, oder 0, wenn die Animation
 *   weiterlaufen soll.
 === Ende Beschreibung === */
static inline void h_eeea0(SP *p1, short *p2, short *p3, int *p4)
{
  *p2 = p1->a;
  *p3 = p1->b;
  *p4 = p1->c;
}
int f_0eeb30(SP **a, SP **b)
{
  int yc, yb, xb, ya, xa;
  h_eeea0(*a, (short *)&xa, (short *)&xb, &yc);
  h_eeea0(*b, (short *)&ya, (short *)&yb, &yc);
  if ((unsigned short)xa == (unsigned short)ya) {
    if ((unsigned short)xb < (unsigned short)yb) return -1;
    if ((unsigned short)yb == 0) return -1;
    if ((unsigned short)yb == (unsigned short)xb) return 0;
    return 1;
  }
  if ((unsigned short)xa > (unsigned short)ya) return 1;
  return -1;
}

//@ f_0eebb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wartet in einer kurzen Synchronisationsschleife, bis die für den aktuellen
 *   Animationsframe vorgesehene Anzeigezeit auf dem Systemtimer abgelaufen ist.
 * - Eingaben: Die Funktion erhält die Zielzeit oder Dauer des Frames (p1).
 * - Rückgabewert: Die Funktion liefert den aktuellen Timerwert zurück.
 === Ende Beschreibung === */
void f_0eebb0(SC *p)
{
  f_14d7dc((int)p->a274, p->s3b86, 4, (int)f_0eeb30);
}

//@ f_0eebe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stoppt am Ende oder beim Abbruch einer sacc-Sequenz alle noch laufenden digitalen
 *   Soundkanäle, die von der Animation gestartet wurden.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Status des letzten gestoppten Soundkanals zurück.
 === Ende Beschreibung === */
int f_0eebe0(SC *p, int o, short *s)
{
  short a = *s++; short b = *s++; short c = *s++;
  int d = *(int *)s; s += 2;
  short e = *s;
  *(short *)(o + 4) = a; *(short *)(o + 6) = b; *(short *)(o + 8) = c;
  *(int *)(o + 0xa) = d; *(short *)(o + 0xe) = e;
  p->i3b8c = 1;
  return 12;
}

//@ f_0eec30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion überwacht die aktiven Soundkanäle der sacc-Animation und gibt Kanalslots wieder frei,
 *   sobald deren Sample-Wiedergabe beendet ist.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Index oder Status nach der Kanalprüfung zurück.
 === Ende Beschreibung === */
int f_0eec30(SC *p, int o, short *s)
{
  s = ((int)s & 0) ? (short *)0 : s; // haelt das Gewicht von s fuer die Registervergabe wie im Original
  short d, b, a, c;
  a = *s++; b = *s++; c = *s++; d = *s++;
  int len = strlen((char *)s);
  int len2 = strlen((char *)s);
  len2 = (len2 & 0) ? 0 : len2; // haelt len2 im Register wie im Original
  len = len + 4;
  *(short *)(o+4)=a; *(short *)(o+6)=b; *(short *)(o+8)=c;
  char *nm = (char *)s;
  (void)&nm; // haelt nm auf dem Stapel wie im Original
  *(short *)(o+0xa)=d;
  f_148143(o+12,(int)nm,0x4f,len2);
  p->i3b8c=1;
  len = len + 5;
  return len;
}
