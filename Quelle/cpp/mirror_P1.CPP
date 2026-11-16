/* === Beschreibung (Katalog) ===
 * Einheit mirror
 *
 * Diese Einheit gehört zu mirror.cpp und implementiert die Ereignis- und Kampfabwicklung rund um den magischen
 * Spiegel (Textbereich 0x25), einschließlich des Spiegelbild-Kampfes, der Belohnung mit Abenteuerpunkten und des
 * Entfernens des Spiegel-Gegenstands (399 / 0x18f).
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 29.10.2026, Basis mirror_P1.CPP)
// mirror.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CD730-0x0CD990
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
inline int EQ(int a, int b) { return a == b; }
inline int GT(int a, int b) { return a > b; }
inline int G2(int a, int b) { return b > a; }
struct SO { char a[4]; int *p; char b[8]; int *q; char c[40]; };
int f_038c40(int p1);
int f_040780(int p1, int p2);
int f_04a890(int p1);
int f_04ad40(int p1, int p2);
int f_04f3f0(int p1, int p2);
int f_091f70(int p1);
int f_09a0d0(int p1);
int f_0bf6f0(const char *p1, int p2);
int f_0bf730(const char *p1, int p2);
#pragma aux f_0bf730 modify [ebx];
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1, int p2);
int f_0dd1d0(int p1, int p2);
short f_0de820(int p1);
int f_0f2720(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
extern int d_1a34e0;
extern int d_1c0004;
extern char d_1c01e4;
extern char d_1c0258;
extern char d_1c025c;
extern char d_1c0274;
extern char d_1c0278;
extern volatile char d_1c0288;
extern char d_1c0290;
extern signed char d_1c1070;
extern signed char d_1c1074;
extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
extern const char d_1a5788[];
inline int i690(unsigned short v)
{
  SO o;
  int t, r;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  t = f_038c40(d_1c0004);
  r = 0;
  o.p[1] = t;
  if (v < 3) {
    if (v == 2) f_0bf730(d_1c2c64, 0x250000fa);
  } else if (v < 4) {
    f_0bf730(d_1c2c64, 0x250000fb);
  } else if (v == 4) {
    f_0bf730(d_1c2c64, 0x250000fc);
    r = 1;
    f_0bf730(d_1c2c64, 0x250000fd);
  }
  f_1254a0(&o, 0);
  return r;
}
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0cd730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verarbeitet die Ereignisse des Spiegel-Objekts (p1) anhand des Aktionscodes p2, zählt
 *   bei p2 == 0 den Betrachtungszähler *(short *)(p1 + 0x5c) hoch (Texte 0x250000fa bis 0x250000fd), startet bei
 *   p2 == 0x80 oder 0xb3 den Spezialkampf (f_04f3f0) des Gruppenanführers, vergibt bei gesetztem Siegesflag
 *   d_1c1074 == 1 100 Abenteuerpunkte (0x250000f9) und entfernt bei Abschluss (result == 1) den Gegenstand 399
 *   aus dem Gruppenbesitz (f_0dd1d0), wobei im Kapitelstatus 3 die zugehörigen Story-Flags und der
 *   Tagebucheintrag 0x14 gesetzt werden.
 * - Eingaben: Übergeben werden der this-Zeiger p1 des Spiegel-Ereignisobjekts sowie der Aktions- oder
 *   Ereigniscode p2.
 * - Rückgabewert: Zurückgegeben wird 1, wenn die Spiegel-Episode abgeschlossen wurde, andernfalls 0.
 === Ende Beschreibung === */
static inline int cmp720(signed char a,const signed char &b){return b>a;}
int f_0cd730(int p1, unsigned short p2)
{
  int value, query;
  int result = 0;
  char local[4];
  switch (p2) {
    case 0: {
      signed char old = *(signed char *)(p1 + 0x5c);
      value=cmp720(old,d_1c1070);
      if (value && *(int *)(p1 + 0x50) == 0) {
        *(short *)(p1 + 0x5c) += 1;
        d_1c1070 = *(char *)(p1 + 0x5c);
        unsigned short count = *(unsigned short *)(p1 + 0x5c);
        SO obj;
        f_125400(&obj, d_1c349c, d_1c3870, d_1c3498);
        obj.p[1] = f_038c40(d_1c0004);
        result = 0;
        switch (count) {
          case 2: f_0bf730(d_1c2c64, 0x250000fa); break;
          case 3: f_0bf730(d_1c2c64, 0x250000fb); break;
          case 4:
            f_0bf730(d_1c2c64, 0x250000fc);
            result = 1;
            f_0bf730(d_1c2c64, 0x250000fd);
            break;
        }
        f_1254a0(&obj, 0);
      }
      break;
    }
    case 0x80:
      query = f_0bf6f0(d_1c2c64, 0x220101be);
      if (query == 1) result = query;
    case 0xb3:
      f_0ce7c0(local);
      {
        int memory = (int)operator new(0x128, mark(d_1a5788, 0x8e));
        value = memory ? f_04a890(memory) : memory;
      }
      f_04f3f0(value, f_038c40(d_1c0004));
      if (value) operator delete((void *)f_04ad40(value, 0));
      f_09a0d0(d_1a34e0);
      f_0ce7e0(local, 0);
      break;
  }
  if (EQB(d_1c1074, 1)) {
    f_0f2720(2);
    result = 1;
    f_0bf730(d_1c2c64, 0x250000f9);
    f_040780(f_038c40(d_1c0004), 100);
  }
  if (result == 1) {
    f_0dd1d0(d_1c0004, 399);
    if (f_0de820(d_1c0004) == 3) {
      d_1c0288 = 1;
      d_1c01e4 = 1;
      d_1c0290 = 1;
      d_1c0258 = 1;
      d_1c025c = 1;
      d_1c0274 = 1;
      d_1c0278 = 1;
      if (EQI(d_1c1074, result)) f_091f70(0x14);
    }
  }
  return result;
}

