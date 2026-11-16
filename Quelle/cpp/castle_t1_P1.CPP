/* === Beschreibung (Katalog) ===
 * Einheit castle_t1 (0x000286d0 - 0x0002b4c0)
 *
 * Überblick
 *
 * Die Einheit castle_t1 implementiert den ersten großen Teil der Ereignis- und Dungeon-Logik für die Festung /
 * Burg von Riva (CASTLE.CPP). Sie enthält den umfangreichen zentralen Ereignis-Verteiler für die Räume,
 * Kerkerzellen, Wachstuben, Geheimgänge und Begegnungen innerhalb der Burg sowie die Verwaltungs- und
 * Statusfunktionen beim Betreten und Verlassen des Schauplatzes.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P1 15/17 gleich, Rest: f_0286d0 (Rahmen ebp statt esp, this in ecx, Slot-Reihenfolge der Msg), f_02b0a0 (ret 16-ausgerichtet, 5 Befehle)
// castle.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0286D0-0x02D9C0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f4f0(int p1, int p2);                           // reg eax stapel 0
int f_05f560(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05f5a0(int p1, int p2);                           // reg eax edx stapel 0
int f_05f6e0(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069770(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
short f_0bf820();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de480(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de850(int p1, int p2);                           // reg eax edx stapel 0
int f_0de890(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_0f2720();                       // nicht in clobber.tsv
                           // reg eax stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125dc0();                       // nicht in clobber.tsv
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
short f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149640(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a06a8;                    // 0x1A06A8
extern short d_1a06aa;                  // 0x1A06AA
extern short d_1a06ac;                  // 0x1A06AC
extern short d_1a06ae;                  // 0x1A06AE
extern short d_1a06b0;                  // 0x1A06B0
extern int d_1a9820;                    // 0x1A9820
extern signed char d_1bc81c;                    // 0x1BC81C
extern signed char d_1bc81d;                    // 0x1BC81D
extern signed char d_1bc820;                    // 0x1BC820
extern signed char d_1bc824;                    // 0x1BC824
extern signed char d_1bc828;                    // 0x1BC828
extern signed char d_1bc82c;                    // 0x1BC82C
extern signed char d_1bc830;                    // 0x1BC830
extern signed char d_1bc834;                    // 0x1BC834
extern signed char d_1bc838;                    // 0x1BC838
extern signed char d_1bc83c;                    // 0x1BC83C
extern signed char d_1bc840;                    // 0x1BC840
extern signed char d_1bc848;                    // 0x1BC848
extern signed char d_1bc84c;                    // 0x1BC84C
extern signed char d_1bc850;                    // 0x1BC850
extern signed char d_1bc854;                    // 0x1BC854
extern signed char d_1bc858;                    // 0x1BC858
extern signed char d_1bc85c;                    // 0x1BC85C
extern signed char d_1bc860;                    // 0x1BC860
extern signed char d_1bc864;                    // 0x1BC864
extern signed char d_1bc868;                    // 0x1BC868
extern signed char d_1bc86c;                    // 0x1BC86C
extern signed char d_1bc870;                    // 0x1BC870
extern signed char d_1bc874;                    // 0x1BC874
extern signed char d_1bc878;                    // 0x1BC878
extern signed char d_1bc87c;                    // 0x1BC87C
extern short d_1bc880;                    // 0x1BC880
extern signed char d_1bc884;                    // 0x1BC884
extern signed char d_1bc888;                    // 0x1BC888
extern int d_1bd91c;                    // 0x1BD91C
extern short d_1bd922;                    // 0x1BD922
extern int d_1c0004;                    // 0x1C0004
extern int d_1c01e8;                    // 0x1C01E8
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a06f0[];           // Text 0x1A06F0

#define A(x) ((int)&(x))
static inline int EQ2(signed char x, signed char y) { return x == y; }
static inline int Z(int v) { return v == 0; }
static inline int O(int v) { return v == 1; }
static inline int GT(short x, short y) { return x > y; }
static inline int ISF(int f, signed char v) { return f == v; }
static inline int GTS(int f, short v) { return f > v; }
#pragma aux f_147323 modify [esp];   // Aufrufvereinbarung: Hand-ASM veraendert esp (KATALOG, erlaubt)
int f_0bfa20(int p1, ...);   // Ergaenzung: cdecl mit Stapelargumenten (Aufrufer raeumt 0x14)
short f_0bf820(int p1, ...); // Ergaenzung: cdecl mit Stapelargumenten (Aufrufer raeumt 0x14)
struct Msg { int h; int *n; int x[2]; int *s; short *v; int pad[9]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define F1(m) (m).n[1]
#define RET break
#define END return r
struct T9 { char b[9]; ~T9(); };
struct Dlg { char b[12]; Dlg(int a, int c); ~Dlg(); int f_05f280(int); int f_05f580(); int f_05f560(); int f_05f4f0(int); int f_05f480(); int f_05f6e0(int); int f_05f5a0(int); };
struct Dlg2 { char b[20]; Dlg2(int a, int c, int e); ~Dlg2(); int f_1131b0(); int f_112ec0(); };
struct Castle;
typedef short (*Fn)(Castle *, int, int);
struct Castle {
  char pad0[8]; Fn *w;
  int f_0286d0(unsigned short p2);
  inline void bigDialog(int id); inline void callIfFree(int n);
  inline void showPic(int code, unsigned short x, unsigned short y, short a, unsigned short b);
  inline void payIn(); inline void payOut(); inline void case2702(); inline int talk(int n); inline void askOnce(signed char &flag, int n); inline int act(int n, short a); inline void sleepHere(); inline void h402(); inline void h403(); inline void h1905(); inline void h2601(); inline void h2701();
  int f_02b0a0(); void f_02b100(); void f_02b160(); void f_02b1b0(); void f_02b270(); void f_02b2a0(); void f_02b2c0();
  void f_02b3b0(); void f_02b440(); void f_02b450(); void f_02b460(); void f_02b470(); void f_02b480(); void f_02b490(); void f_02b4a0(); void f_02b4b0();
  void f_02b520(); void f_02b650(); void f_02bad0(); void f_02bd60(); void f_02c050(); void f_02c150(); void f_02c3a0(); void f_02c7c0(); void f_02c9a0(); void f_02ceb0();
  void f_02d230(int a); void f_02d7a0(int a, int c); void f_02d900();
};
#define BIG(line, id) { Dlg *d = new (mark(d_1a06f0, line)) Dlg(0, id); \
  if (d->f_05f580() == 0) { \
    CX(m); short s = f_0db9a0(d_1c0004); int code; int u; \
    if (s < 2) { s = f_145760(0, 1); code = s + 0x33000008; u = f_038c40(d_1c0004); } \
    else { s = f_145760(0, 4); code = s + 0x33000003; u = f_039320(d_1c0004, 0x33); } \
    F1(m) = u; \
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, d_1a9820, 0, 1); \
    f_0bf730(A(d_1c2c64), code); \
    CXEND(m); \
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) { \
      d->f_05f6e0(0); \
      if (Z(d_1bc888)) { d_1bd91c = 1; f_0bf730(A(d_1c2c64), 0x3300001f); d_1bd922 = 5; if ((*w)(this, 0xb, 0) == 0) d_1bc888 = 1; } \
      else { d_1bd91c = 1; f_0bf730(A(d_1c2c64), 0x33000020); (*w)(this, 0xb, 0); } \
      f_060a70(); d->f_05f5a0(0); } \
  } else d->f_05f280(0); \
  delete d; END; }

//@ f_0286d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert Dutzende von Ereignisfeldern in der Burg von Riva (CASTLE), darunter
 *   Wachposten-Kontrollen, Kerkerzellen, verschlossene Türen, Hebelmechanismen, Beutefunde, Gespräche mit
 *   Gefangenen oder Burgbewohnern sowie Kämpfe gegen die Burgbesatzung.
 * - Eingaben und Rückgabe: Die Funktion erhält die Nummer des betretenen Ereignisfeldes als Parameter und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden der geladene Burg-Textpuffer d_1bc9a8, der Gruppenanführer d_1c0004
 *   sowie die zahlreichen Ortsflags im Bereich d_1bc81c-d_1bc9a4 (darunter auch der nicht im Spielstand
 *   registrierte Merker d_1bc81d für Feld 1001).
 === Ende Beschreibung === */
// BLIND: f_0286d0 hier komplett neu aus dem Original-Assembler schreiben (orig.sh castle_t1 f_0286d0).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
// (Methode, Deklaration steht in der Klasse)






static inline int ISF_H2330(const signed char &f, signed char v) { return f == v; }
// Haelt den Byte-Parameter und die Register-/Slotbelegung im grossen Switch f_0286d0
static inline int ISF_LOCAL_H2330(const signed char &f, signed char v) { v = (signed char)(v & 0xff); return f == v; }
// Erzeugt den fuer die Slot-Reihenfolge von f_0286d0 noetigen lokalen Kopiernamen
static inline int ISF_COPY_H2330(const signed char &f, signed char v) { signed char z = v; z = (signed char)(z & 0xff); return f == z; }

inline void Castle::sleepHere()
{
  if (Z(d_1bc888)) {
    d_1bd91c = 1;
    f_0bf730(A(d_1c2c64), 0x3300001f);
    d_1bd922 = 5;
    if ((*w)(this, 0xb, 0) == 0) d_1bc888 = 1;
  } else {
    d_1bd91c = 1;
    f_0bf730(A(d_1c2c64), 0x33000020);
    (*w)(this, 0xb, 0);
  }
}

inline void Castle::bigDialog(int id)
{
  Dlg *dlg = new (mark(d_1a06f0, 3428)) Dlg(0, id);
  if (Z(dlg->f_05f580()) == 1) {
    CX(m);
    int text;
    if (f_0db9a0(d_1c0004) > 1) {
      text = f_145760(0, 4) + 0x33000003;
      F1(m) = f_039320(d_1c0004, 0x33);
    } else {
      text = f_145760(0, 1) + 0x33000008;
      F1(m) = f_038c40(d_1c0004);
    }
    int snd;
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
    f_0bf730(A(d_1c2c64), text);
    CXEND(m);
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) {
      dlg->f_05f6e0(0);
      sleepHere();
      f_060a70();
      dlg->f_05f5a0(0);
    }
  } else {
    dlg->f_05f280(0);
  }
  delete dlg;
}

inline void Castle::callIfFree(int n)
{
  if (f_069770(A(pad0[2]), n)) {
    short arg = 0;
    (*w)(this, n, arg);
  }
}

inline void Castle::h402()
{
  if (ISF_H2330(d_1bc84c, 0)) {
    if ((*w)(this, 0xc, 0) == 0) d_1bc84c = 1;
  }
}

inline void Castle::h403()
{
  if (ISF_COPY_H2330(d_1bc850, 0)) {
    if ((*w)(this, 0xd, 0) == 0) d_1bc850 = 1;
  }
}

inline int Castle::act(int n, short a)
{
  return (*w)(this, n, a);
}

inline void Castle::h1905()
{
  struct Invoke { static void run(Castle *self, short arg) { (*self->w)(self, 0x1c, arg); } };
  if (f_069770(A(pad0[2]), 0x1c)) Invoke::run(this, 0);
}

inline void Castle::h2601()
{
  struct Invoke { static void run(Castle *self, short arg) { (*self->w)(self, 0x12, arg); } };
  if (f_069770(A(pad0[2]), 0x12)) Invoke::run(this, 0);
}

inline void Castle::h2701()
{
  if (f_069770(A(pad0[2]), 0x10)) { short zero = 0; (*w)(this, 0x10, zero); }
}

inline void Castle::showPic(int code, unsigned short x, unsigned short y, short a, unsigned short b)
{
  f_147323(A(d_1c2edc), code, x, y, d_1a9820, a, b);
}

inline void Castle::payIn()
{
  short most = f_0de7e0(d_1c0004) / 10;
  if (most > 999) most = 999;
  short n = f_0bf7b0(A(d_1c2c64), 3, 0x3300004c, 0, most, 0);
  if (n > 0) {
    d_1bc880 += n;
    f_0db8b0(d_1c0004, n * 10);
    f_054ca0(1, n);
  }
}

inline void Castle::payOut()
{
  short amount = d_1bc880;
  short most = amount;
  most = (most & 0) ? (short)0 : most; // Haelt das Vorzweig-Web fuer most in f_0286d0
  if (amount > 999) most = 999;
  short n = f_0bf7b0(A(d_1c2c64), 3, 0x3300004d, 0, most, 0);
  if (n > 0) {
    d_1bc880 -= n;
    f_0db820(d_1c0004, n * 10);
    f_054ca0(1, -n);
  }
}

inline void Castle::case2702()
{
  if (f_0bf6f0(A(d_1c2c64), 0x33000067) == 1) {
    unsigned short a7 = 1;
    unsigned short a4;
    int a5;
    short a6;
    unsigned short a3;
    f_147323(A(d_1c2edc), 0x330012, (a3 = 0x7fff), (a4 = 0x8000),
             (a5 = d_1a9820), (a6 = 0), a7);
    f_0bf730(A(d_1c2c64), 0x33000068);
    for (;;) {
      d_1bd91c = 1;
      int answer = (*w)(this, 0x1a, 0);
      if (answer != 0) break;
      f_0bf730(A(d_1c2c64), 0x33000069);
    }
  }
}

int Castle::f_0286d0(unsigned short id)
{
  struct Frame {
    Msg messages[22];
    Castle *self5e;
    int text62, text66;
    Fn *dispatch;
    int text6e;
    Castle *self72, *self76, *self7a;
    int text7e;
  } frame; // belegter 0x54c-Rahmen: 22 Kontexte, vier Text/Objekt-Paare, Aufrufzeiger
  int done = 1;
  switch (id) {
  case 101: { f_125400((int)&frame.messages[6], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[6].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x33000002); f_1254a0((int)&frame.messages[6], 0); } break;
  case 102: break;
  case 103: break;
  case 104: break;
  case 105: { f_125400((int)&frame.messages[21], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[21].n[1] = f_039660(d_1c0004, 0xc); f_0bf730(A(d_1c2c64), 0x3300000c); f_1254a0((int)&frame.messages[21], 0); } break;
  case 106: { f_125400((int)&frame.messages[7], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[7].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x3300000d); f_1254a0((int)&frame.messages[7], 0); } break;
  case 107: {
  f_125400((int)&frame.messages[2], A(d_1c349c), A(d_1c3870), A(d_1c3498));
  if (ISF_LOCAL_H2330(d_1bc870, 0)) {
    if (f_0bf6f0(A(d_1c2c64), 0x3300000e) == 1) {
      int p = f_039320(d_1c0004, 0x1d);
      frame.messages[2].n[1] = p;
      f_0bf730(A(d_1c2c64), 0x3300000f);
      f_125ed0(A(d_1c2c44), 10);
      f_0366e0(p, 0x3c, 2, 2);
      d_1bc870 = 1;
    }
  } else {
    f_0bf730(A(d_1c2c64), 0x33000010);
  }
  f_1254a0((int)&frame.messages[2], 0);
} break;
  case 108: f_02b270(); break;
  case 109: f_02b2a0(); break;
  case 110: f_02b2c0(); break;
  case 111: {
  if (ISF_COPY_H2330(d_1bc85c, 0)) {
    int p = f_038be0(d_1c0004);
    if (f_044c90(p, 0x33, 0) > 0) {
      f_125400((int)&frame.messages[13], A(d_1c349c), A(d_1c3870), A(d_1c3498));
      frame.messages[13].n[1] = p;
      f_0bf730(A(d_1c2c64), 0x33000017);
      f_060740(0x6e, 1);
      d_1bc85c = 1;
      f_1254a0((int)&frame.messages[13], 0);
    }
  }
} break;
  case 112: f_02b440(); break;
  case 113: f_02b450(); break;
  case 115: f_02b470(); break;
  case 116: f_02b480(); break;
  case 117: f_02b490(); break;
  case 118: f_02b4a0(); break;
  case 200: f_02b4b0(); break;
  case 201: f_02b520(); break;
  case 202: {
    Dlg *dlg = new (mark(d_1a06f0, 1161)) Dlg(0, 0x1f65);
    dlg->f_05f6e0(0);
    f_060800(0x330004, 1, 0);
    dlg->f_05f5a0(0);
    delete dlg;
    break;
  }
  case 203: f_02b650(); break;
  case 301:
    if (ISF_COPY_H2330(d_1bc888, 0)) {
      d_1bd91c = 1;
      f_0bf730(A(d_1c2c64), 0x3300001f);
      d_1bd922 = 5;
      if ((*w)(this, 0xb, 0) == 0) d_1bc888 = 1;
    } else {
      d_1bd91c = 1;
      f_0bf730(A(d_1c2c64), 0x33000020);
      (*w)(this, 0xb, 0);
    }
    break;
  case 401:
    if (ISF_COPY_H2330(d_1bc854, 0)) {
      if (f_0bf6f0(A(d_1c2c64), 0x33000021) == 1) {
        f_0dcf00(d_1c0004, 0x1ce, 1);
        d_1bc854 = 1;
      }
    } else {
      f_0bf730(A(d_1c2c64), 0x33000022);
    }
    break;
  case 402: h402(); break;
  case 403: h403(); break;
  case 501: f_0bf730(A(d_1c2c64), 0x33000023); break;
  case 601: { f_125400((int)&frame.messages[20], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[20].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x33000024); f_1254a0((int)&frame.messages[20], 0); break; }
  case 701: { f_125400((int)&frame.messages[10], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[10].n[1] = f_0396f0(d_1c0004, 0); f_0bf730(A(d_1c2c64), 0x33000025); f_1254a0((int)&frame.messages[10], 0); break; }
  case 702: f_0bf730(A(d_1c2c64), 0x33000026); break;
  case 703: f_02bad0(); break;
  case 704: { f_125400((int)&frame.messages[11], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[11].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x3300002c); f_1254a0((int)&frame.messages[11], 0); break; }
  case 801: break;
  case 802: f_0bf730(A(d_1c2c64), 0x3300002d); break;
  case 901: f_0bf730(A(d_1c2c64), 0x3300002e); f_0603b0(0xc); break;
  case 902: f_0bf730(A(d_1c2c64), 0x3300002f); f_0603b0(0xd); break;
  case 903: break;
  case 1001: {
    f_125400((int)&frame.messages[4], A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (d_1bc81d == 0) {
      d_1bc81d = 1;
      frame.messages[4].n[1] = f_039320(d_1c0004, 0x12);
      f_0bf730(A(d_1c2c64), 0x33000031);
    }
    f_1254a0((int)&frame.messages[4], 0);
    break;
  }
  case 1002: f_02bd60(); break;
  case 1004: {
    Dlg2 *dlg = new (mark(d_1a06f0, 1792)) Dlg2(0xe, 0, 0);
    if (dlg->f_1131b0() == 1) {
      if (Z(d_1bc884)) {
        f_0bf730(A(d_1c2c64), 0x33000037);
        d_1bc884 = 1;
      }
      dlg->f_112ec0();
    }
    delete dlg;
    break;
  }
  case 1005: { f_125400((int)&frame.messages[1], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[1].n[1] = f_039320(d_1c0004, 0x33); f_0bf730(A(d_1c2c64), 0x33000038); f_1254a0((int)&frame.messages[1], 0); break; }
  case 1101: break;
  case 1102: f_060360(0xc); break;
  case 1103: f_0bf730(A(d_1c2c64), 0x33000039); break;
  case 1201: break;
  case 1202: f_060360(0xd); break;
  case 1203: f_02c050(); break;
  case 1301:
    if (ISF_COPY_H2330(d_1bc868, 0)) {
      f_125400((int)&frame.messages[15], A(d_1c349c), A(d_1c3870), A(d_1c3498));
      frame.messages[15].n[1] = f_038c40(d_1c0004);
      f_0bf730(A(d_1c2c64), 0x3300003d);
      f_057220(A(d_1c2c00), 0x8030006, 0);
      d_1bc868 = 1;
      f_1254a0((int)&frame.messages[15], 0);
    } else if (O(d_1bc86c)) {
      f_0bf730(A(d_1c2c64), 0x3300003e);
    }
    break;
  case 1302: f_0bf730(A(d_1c2c64), 0x3300003f); break;
  case 1401: f_0bf730(A(d_1c2c64), 0x33000040); break;
  case 1402: f_0bf730(A(d_1c2c64), 0x33000040); break;
  case 1403: f_0bf730(A(d_1c2c64), 0x33000041); f_0603b0(0x68); break;
  case 1404: f_02c3a0(); break;
  case 1501: { f_125400((int)&frame.messages[19], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[19].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x33000046); f_1254a0((int)&frame.messages[19], 0); break; }
  case 1603: f_0bf730(A(d_1c2c64), 0x33000047); f_0603b0(0x11); break;
  case 1601: f_0bf730(A(d_1c2c64), 0x33000047); f_0603b0(0xf); break;
  case 1602: f_0bf730(A(d_1c2c64), 0x33000047); f_0603b0(0x10); break;
  case 1604: f_0bf730(A(d_1c2c64), 0x33000047); f_0603b0(0x12); break;
  case 1701: f_0bf730(A(d_1c2c64), 0x33000048); break;
  case 1702: {
    f_125400((int)&frame.messages[12], A(d_1c349c), A(d_1c3870), A(d_1c3498));
    short bankWord = d_1bc880;
    frame.messages[12].v[1] = bankWord;
    bankWord = 0;
    if (GTS(d_1bc880, bankWord)) {
      short choice = f_0bf820(A(d_1c2c64), 0x33000049, 2, 0x3300004a, 0x3300004b);
      switch (choice) {
      case -1: break;
      case 1: payIn(); break;
      case 2: payOut(); break;
      }
    } else if (f_0bf6f0(A(d_1c2c64), 0x3300004e) == 1) {
      payIn();
    }
    f_1254a0((int)&frame.messages[12], 0);
    break;
  }
  case 1703: f_02c7c0(); break;
  case 1801:
    if (ISF_COPY_H2330(d_1bc874, 1)) f_0bf730(A(d_1c2c64), 0x33000053);
    break;
  case 1802: f_0603b0(0x13); break;
  case 1803:
    if (ISF_COPY_H2330(d_1bc874, 0)) {
      T9 *t = (T9 *)f_0606a0(0x330001, 4);
      f_0bfa20(A(d_1c2c64), (int)t, 0, 0x33000054, 0);
      delete t;
      d_1bc874 = 1;
    }
    break;
  case 8039: f_02c9a0(); break;
  case 1901: break;
  case 1903:
    f_060360(0xf);
    if (ISF_COPY_H2330(d_1bc878, 0)) {
      if (f_0d54f0(d_1c0004, 0x187) != -1) {
        d_1bc878 = 1;
        f_091f70(0x1a);
        f_057220(A(d_1c2c00), 0x803000a, 0);
      }
    }
    break;
  case 1904: break;
  case 1905: h1905(); break;
  case 7031: case 8031: {
    Dlg *dlg = new (mark(d_1a06f0, 473)) Dlg(8, 0x1f5f);
    int was = dlg->f_05f560();
    dlg->f_05f280(0);
    if (was == 1 && dlg->f_05f560() == 0) f_0dd1d0(d_1c0004, 0x189);
    delete dlg;
    break;
  }
  case 2001:
    if (f_0bf6f0(A(d_1c2c64), 0x33000059) == 1) {
      f_0bf730(A(d_1c2c64), 0x3300005a);
      f_125ed0(A(d_1c2c44), 0xf);
    }
    break;
  case 2002:
    if (ISF_H2330(d_1bc828, 0)) {
      if (f_0bf6f0(A(d_1c2c64), 0x3300005b) == 1) {
        f_125400((int)&frame.messages[14], A(d_1c349c), A(d_1c3870), A(d_1c3498));
        frame.messages[14].n[1] = f_038c40(d_1c0004);
        f_0bf730(A(d_1c2c64), 0x3300005c);
        f_125ed0(A(d_1c2c44), 0xf);
        f_0dcf00(d_1c0004, 0x188, 1);
        d_1bc828 = 1;
        f_1254a0((int)&frame.messages[14], 0);
      }
    } else {
      f_0bf730(A(d_1c2c64), 0x3300005d);
    }
    break;
  case 2003: { f_125400((int)&frame.messages[5], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[5].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x3300005e); f_1254a0((int)&frame.messages[5], 0); break; }
  case 2101: break;
  case 2102: f_0bf730(A(d_1c2c64), 0x3300005f); break;
  case 2103: break;
  case 114: f_02b460(); break;
  case 2104:
    if (ISF_COPY_H2330(d_1bc824, 0)) {
      f_125400((int)&frame.messages[17], A(d_1c349c), A(d_1c3870), A(d_1c3498));
      frame.messages[17].n[1] = f_038c40(d_1c0004);
      f_0bf730(A(d_1c2c64), 0x33000060);
      f_125ed0(A(d_1c2c44), 0xf);
      f_0dcf00(d_1c0004, 0xcf, 1);
      d_1bc824 = 1;
      f_1254a0((int)&frame.messages[17], 0);
    } else {
      f_0bf730(A(d_1c2c64), 0x33000061);
    }
    break;
  case 2201:
    if (ISF_COPY_H2330(d_1bc868, 0) || Z(d_1bc860)) f_0bf730(A(d_1c2c64), 0x33000062);
    else f_0bf730(A(d_1c2c64), 0x33000063);
    break;
  case 2202: f_0bf730(A(d_1c2c64), 0x33000064); break;
  case 2203: f_0603b0(0x14); break;
  case 2204: f_02ceb0(); break;
  case 2301: break;
  case 2302: f_060360(0x10); break;
  case 2303: break;
  case 2401: { f_125400((int)&frame.messages[3], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[3].n[1] = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x33000065); f_1254a0((int)&frame.messages[3], 0); break; }
  case 2402: break;
  case 2403: break;
  case 2501: break;
  case 2502: f_060360(0x11); break;
  case 2503:
    if (ISF_COPY_H2330(d_1bc820, 0)) {
      T9 *t = (T9 *)f_0606a0(0x330001, 5);
      f_0bfa20(A(d_1c2c64), (int)t, 0, 0x33000066, 0);
      delete t;
      if ((*w)(this, 0x11, 0) == 0) d_1bc820 = 1;
    }
    break;
  case 2601: h2601(); break;
  case 2602: break;
  case 2701: h2701(); break;
  case 2702: case2702(); break;
  case 2703: break;
  case 2801:
    if (ISF_LOCAL_H2330(d_1bc864, 0)) {
      f_10b890(3);
      d_1bc864 = 1;
      f_091f70(0x18);
      f_125ed0(A(d_1c2c44), 0xf);
      f_057220(A(d_1c2c00), 0x8030008, 0);
      f_057220(A(d_1c2c00), 0x8030009, 0);
    }
    break;
  case 1003: { f_125400((int)&frame.messages[8], A(d_1c349c), A(d_1c3870), A(d_1c3498)); frame.messages[8].n[1] = f_039320(d_1c0004, 0x20); f_0bf730(A(d_1c2c64), 0x33000036); f_1254a0((int)&frame.messages[8], 0); break; }
  case 7001: case 8001: {
  void *tag = mark(d_1a06f0, 3428);
  frame.self7a = this;
  Dlg *dlg = new (tag) Dlg(0, 0x1f41);
  if (Z(dlg->f_05f580()) == 1) {
    f_125400((int)&frame.messages[16], A(d_1c349c), A(d_1c3870), A(d_1c3498));

    if (f_0db9a0(d_1c0004) > 1) {
      frame.text7e = f_145760(0, 4) + 0x33000003;
      frame.messages[16].n[1] = f_039320(d_1c0004, 0x33);
    } else {
      frame.text7e = f_145760(0, 1) + 0x33000008;
      frame.messages[16].n[1] = f_038c40(d_1c0004);
    }
    int snd;
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
    f_0bf730(A(d_1c2c64), frame.text7e);
    f_1254a0((int)&frame.messages[16], 0);
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) {
      dlg->f_05f6e0(0);
      {
        int state = d_1bc888;
        Castle *who = frame.self7a;
        if (Z(state)) {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x3300001f);
          d_1bd922 = 5;
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          if ((*frame.dispatch)((Castle *)callValue, 0xb, 0) == 0) d_1bc888 = 1;
        } else {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x33000020);
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          (*frame.dispatch)((Castle *)callValue, 0xb, 0);
        }
      }
      f_060a70();
      dlg->f_05f5a0(0);
    }
  } else {
    dlg->f_05f280(0);
  }
  delete dlg;
} break;
  case 7008: case 8008: {
  void *tag = mark(d_1a06f0, 3428);
  frame.self5e = this;
  Dlg *dlg = new (tag) Dlg(0, 0x1f48);
  if (Z(dlg->f_05f580()) == 1) {
    f_125400((int)&frame.messages[18], A(d_1c349c), A(d_1c3870), A(d_1c3498));

    if (f_0db9a0(d_1c0004) > 1) {
      frame.text62 = f_145760(0, 4) + 0x33000003;
      frame.messages[18].n[1] = f_039320(d_1c0004, 0x33);
    } else {
      frame.text62 = f_145760(0, 1) + 0x33000008;
      frame.messages[18].n[1] = f_038c40(d_1c0004);
    }
    int snd;
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
    f_0bf730(A(d_1c2c64), frame.text62);
    f_1254a0((int)&frame.messages[18], 0);
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) {
      dlg->f_05f6e0(0);
      {
        int state = d_1bc888;
        Castle *who = frame.self5e;
        if (Z(state)) {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x3300001f);
          d_1bd922 = 5;
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          if ((*frame.dispatch)((Castle *)callValue, 0xb, 0) == 0) d_1bc888 = 1;
        } else {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x33000020);
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          (*frame.dispatch)((Castle *)callValue, 0xb, 0);
        }
      }
      f_060a70();
      dlg->f_05f5a0(0);
    }
  } else {
    dlg->f_05f280(0);
  }
  delete dlg;
} break;
  case 7025: case 8025: {
  void *tag = mark(d_1a06f0, 3428);
  frame.self72 = this;
  Dlg *dlg = new (tag) Dlg(0, 0x1f59);
  if (Z(dlg->f_05f580()) == 1) {
    f_125400((int)&frame.messages[0], A(d_1c349c), A(d_1c3870), A(d_1c3498));

    if (f_0db9a0(d_1c0004) > 1) {
      frame.text6e = f_145760(0, 4) + 0x33000003;
      frame.messages[0].n[1] = f_039320(d_1c0004, 0x33);
    } else {
      frame.text6e = f_145760(0, 1) + 0x33000008;
      frame.messages[0].n[1] = f_038c40(d_1c0004);
    }
    int snd;
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
    f_0bf730(A(d_1c2c64), frame.text6e);
    f_1254a0((int)&frame.messages[0], 0);
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) {
      dlg->f_05f6e0(0);
      {
        int state = d_1bc888;
        Castle *who = frame.self72;
        if (Z(state)) {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x3300001f);
          d_1bd922 = 5;
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          if ((*frame.dispatch)((Castle *)callValue, 0xb, 0) == 0) d_1bc888 = 1;
        } else {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x33000020);
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          (*frame.dispatch)((Castle *)callValue, 0xb, 0);
        }
      }
      f_060a70();
      dlg->f_05f5a0(0);
    }
  } else {
    dlg->f_05f280(0);
  }
  delete dlg;
} break;
  case 7034: case 8034: {
  void *tag = mark(d_1a06f0, 3428);
  frame.self76 = this;
  Dlg *dlg = new (tag) Dlg(0, 0x1f62);
  if (Z(dlg->f_05f580()) == 1) {
    f_125400((int)&frame.messages[9], A(d_1c349c), A(d_1c3870), A(d_1c3498));

    if (f_0db9a0(d_1c0004) > 1) {
      frame.text66 = f_145760(0, 4) + 0x33000003;
      frame.messages[9].n[1] = f_039320(d_1c0004, 0x33);
    } else {
      frame.text66 = f_145760(0, 1) + 0x33000008;
      frame.messages[9].n[1] = f_038c40(d_1c0004);
    }
    int snd;
    f_147323(A(d_1c2edc), 0x33000e, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
    f_0bf730(A(d_1c2c64), frame.text66);
    f_1254a0((int)&frame.messages[9], 0);
    if (f_0bf6f0(A(d_1c2c64), 0x3300000a) == 1) {
      dlg->f_05f6e0(0);
      {
        int state = d_1bc888;
        Castle *who = frame.self76;
        if (Z(state)) {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x3300001f);
          d_1bd922 = 5;
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          if ((*frame.dispatch)((Castle *)callValue, 0xb, 0) == 0) d_1bc888 = 1;
        } else {
          d_1bd91c = 1;
          f_0bf730(A(d_1c2c64), 0x33000020);
          void *callValue = who->w;
          frame.dispatch = (Fn *)callValue;
          callValue = who;
          (*frame.dispatch)((Castle *)callValue, 0xb, 0);
        }
      }
      f_060a70();
      dlg->f_05f5a0(0);
    }
  } else {
    dlg->f_05f280(0);
  }
  delete dlg;
} break;
  case 7010: case 8010: f_02d7a0(0, 0x1f4a); break;
  case 7016: case 8016: f_02d7a0(0, 0x1f50); break;
  case 7027: case 8027: f_05fa00(0, 0x1f5b); break;
  case 7032: case 8032: f_05fa00(0, 0x1f60); break;
  case 7028: case 8028: f_05fa00(9, 0x1f5c); break;
  case 7029: case 8029: f_05fa00(0xa, 0x1f5d); break;
  case 7033: case 8033: f_05fa00(0, 0x1f61); break;
  case 7022: case 8022: f_05fa00(0, 0x1f56); break;
  case 7024: case 8024: f_05fa00(0xc, 0x1f58); break;
  case 7019: case 8019: f_05fa00(0xd, 0x1f53); break;
  case 7017: case 8017: f_02c150(); break;
  case 7003: case 8003: f_05fa00(0, 0x1f43); break;
  case 7006: case 8006: f_05fa00(0, 0x1f46); break;
  case 7007: case 8007: f_05fa00(0, 0x1f47); break;
  case 7014: case 8014: f_05fa00(0, 0x1f4e); break;
  case 7009: case 8009:
    f_05fa00(0, 0x1f49);
    if (f_149640(0x1f49) == 1) f_02c3a0();
    break;
  case 7036: case 8036: {
    Dlg *dlg = new (mark(d_1a06f0, 617)) Dlg(0, 0x1f64);
    if (Z(dlg->f_05f580())) {
      dlg->f_05f480();
      f_0607e0(0x1f65, 1);
    } else {
      dlg->f_05f4f0(0);
      f_0607e0(0x1f65, 0);
    }
    delete dlg;
    break;
  }
  case 7011: case 8011: f_05fa00(0, 0x1f4b); break;
  case 7015: case 8015: {
    Dlg *dlg = new (mark(d_1a06f0, 3558)) Dlg(0x12, 0x1f4f);
    dlg->f_05f280(0);
    if (Z(d_1bc858) && Z(dlg->f_05f580()) && Z(d_1bc85c)) {
      f_060740(0x6e, 1);
      d_1bc85c = 1;
    }
    delete dlg;
    break;
  }
  case 7021: case 8021: f_05fa00(0x13, 0x1f55); break;
  case 7002: case 8002: f_05fa00(0, 0x1f42); break;
  case 7004: case 8004: f_05fa00(0, 0x1f44); break;
  case 7005: case 8005: f_05fa00(0, 0x1f45); break;
  case 7012: case 8012: f_05fa00(0x10, 0x1f4c); break;
  case 7013: case 8013: f_05fa00(0x11, 0x1f4d); break;
  case 7018: case 8018: f_05fa00(0xe, 0x1f52); break;
  case 7020: case 8020: f_05fa00(0, 0x1f54); break;
  case 7023: case 8023: f_02d900(); break;
  case 7030: case 8030: f_05fa00(0xb, 0x1f5e); break;
  case 7035: case 8035: f_05fa00(0, 0x1f63); break;
  default: done = 0; break;
  }
  return done;
}


//@ f_02b0a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Verlassen der Festung von Riva den reservierten Textpuffer der Burgdialoge frei und
 *   setzt temporäre Zustandsdaten zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben wird der globale Textpufferzeiger d_1bc9a8.
 === Ende Beschreibung === */
int Castle::f_02b0a0() { CX(m); F1(m) = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x33000002); return CXEND(m); }

//@ f_02b0f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dient als leerer Einhängepunkt in der Ortsverwaltung der Burg, der ohne weitere Aktion
 *   zurückkehrt.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02b0f0(void)
{
}

//@ f_02b100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim Betreten der Burg die Textressource mit sämtlichen Raum-, Wach- und Kerkerdialogen
 *   in den Arbeitsspeicher und richtet den Schauplatz ein.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Initialisiert wird der Textpufferzeiger d_1bc9a8 über den Ressourcenlader f_0a27a0.
 === Ende Beschreibung === */
void Castle::f_02b100() { CX(m); F1(m) = f_039660(d_1c0004, 0xc); f_0bf730(A(d_1c2c64), 0x3300000c); CXEND(m); }
//@ f_02b160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten eines Übergangs- oder Türfeldes in der Burg, ob der Durchgang offen ist,
 *   und führt die entsprechende Orts- oder Etagenbewegung aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt die Feldkennung (oder keine Parameter) entgegen und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Gelesen werden die Burg-Flags im Bereich d_1bc820-d_1bc9a4 sowie der Textpuffer
 *   d_1bc9a8.
 === Ende Beschreibung === */
void Castle::f_02b160() { CX(m); F1(m) = f_038c40(d_1c0004); f_0bf730(A(d_1c2c64), 0x3300000d); CXEND(m); }
//@ f_02b1b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wickelt an einem Ereignispunkt der Burg eine Dialog- oder Untersuchungsszene ab und
 *   aktualisiert je nach Entscheidung des Spielers den Alarm- oder Queststatus der Festung.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Burg-Textpuffer d_1bc9a8, das Dialogfenster f_056000 und die
 *   zugehörigen Ortsmerker.
 === Ende Beschreibung === */
void Castle::f_02b1b0()
{
  CX(m);
  if (ISF(d_1bc870, 0)) {
    if (f_0bf6f0(A(d_1c2c64), 0x3300000e) == 1) {
      int p = f_039320(d_1c0004, 0x1d);
      F1(m) = p;
      f_0bf730(A(d_1c2c64), 0x3300000f);
      f_125ed0(A(d_1c2c44), 10);
      f_0366e0(p, 0x3c, 2, 2);
      d_1bc870 = 1;
    }
  } else {
    f_0bf730(A(d_1c2c64), 0x33000010);
  }
  CXEND(m);
}
//@ f_02b270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim erstmaligen Betreten von Feld 108 in der Burg von Riva eine Beobachtungsmeldung aus
 *   und sperrt das Feld anschließend über ein Statusbyte gegen Wiederholung. *(Hinweis: Da das hier gesetzte
 *   Statusbyte d_1bc81c in f_0281d0 nicht für den Spielstand registriert wurde, erscheint die Meldung nach dem
 *   Laden eines Spielstands erneut.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft und setzt den Einmal-Merker d_1bc81c und zeigt den Text über d_1bc9a8 an.
 === Ende Beschreibung === */
void Castle::f_02b270() { if (d_1bc81c == 0) { d_1bc81c = 1; f_0bf730(A(d_1c2c64), 0x33000011); } }
//@ f_02b2a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt an einem Ereignispunkt der Burg einen Statusmerker oder gibt einen kurzen Hinweis aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Zugegriffen wird auf die Burg-Flags im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b2a0() { f_0bf730(A(d_1c2c64), 0x33000012); }
//@ f_02b2c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt die Gruppe eine Einrichtung oder Tür in der Burg untersuchen, stellt eine
 *   Entscheidungsfrage im Textfenster und schaltet bei Erfolg den zugehörigen Zustand frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc9a8, der Gruppenanführer d_1c0004 und die Ortsflags der Burg.
 === Ende Beschreibung === */
void Castle::f_02b2c0()
{
  CX(m);
  F1(m) = f_038be0(d_1c0004);
  if (Z(d_1bc85c)) { d_1bc85c = 1; f_0bf730(A(d_1c2c64), 0x33000013); f_060740(0x6e, 1); }
  if (O(d_1bc858)) {
    f_0bf730(A(d_1c2c64), 0x33000014);
  } else {
    if (f_0bf6f0(A(d_1c2c64), 0x33000015) == 1) {
      f_0bf730(A(d_1c2c64), 0x33000016);
      f_060740(0x6e, 1);
      f_125ed0(A(d_1c2c44), 5);
      d_1bc858 = 1;
    }
  }
  CXEND(m);
}
//@ f_02b3b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt in einem Raum der Burg einen Beschreibungstext an, prüft Vorbedingungen und aktualisiert
 *   das entsprechende Fortschrittsflag.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Textpuffer d_1bc9a8 und die Statusmerker im Bereich
 *   d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b3b0()
{
  if (ISF(d_1bc85c, 0)) {
    int p = f_038be0(d_1c0004);
    if (f_044c90(p, 0x33, 0) > 0) {
      CX(m);
      F1(m) = p;
      f_0bf730(A(d_1c2c64), 0x33000017);
      f_060740(0x6e, 1);
      d_1bc85c = 1;
      CXEND(m);
    }
  }
}
//@ f_02b440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Wert eines persistenten Statusmerkers der Burg von Riva zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert den Flagwert als Ganzzahl.
 * - Wichtige Variablen: Gelesen wird ein Statusbyte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b440() { f_02d230(0x13); }
//@ f_02b450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen zweiten Fortschrittsmerker der Burg aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt das gelesene Statusbyte zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b450() { f_02d230(0x14); }
//@ f_02b460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den Zustand eines dritten Burg-Flags an aufrufende Module.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Flagwert als Ganzzahl zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b460() { f_02d230(0x15); }
//@ f_02b470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Wert eines vierten Ereignismerkers der Burg zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert das Statusbyte zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b470() { f_02d230(0x16); }
//@ f_02b480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Stand eines fünften Burg-Merkers ab.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt den gespeicherten Wert zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b480() { f_02d230(0x17); }
//@ f_02b490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen sechsten Statusmerker der Burg von Riva aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt das Statusbyte zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b490() { f_02d230(0x18); }
//@ f_02b4a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zustand eines siebten Fortschrittsflags der Burg zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und liefert den Wert als Ganzzahl zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b4a0() { f_02d230(0x19); }
//@ f_02b4b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den achten über Modul-Grenzen hinweg abgefragten Statusmerker der Burg von Riva.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt das gelesene Statusbyte zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc820-d_1bc9a4.
 === Ende Beschreibung === */
void Castle::f_02b4b0()
{
  if (f_0bf6f0(A(d_1c2c64), 0x33000018) == 1) {
    f_0de830(d_1c0004, 3);
    f_0de8d0(d_1c0004, 0x7ffc);
    f_0de850(d_1c0004, 0xf8a80000);
    f_0de890(d_1c0004, 0xfca40000);
    f_0de930(d_1c0004, 1);
  }
}
