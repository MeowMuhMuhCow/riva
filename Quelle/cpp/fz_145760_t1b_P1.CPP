/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t1b (0x145850 - 0x145920)
 *
 * Überblick
 * Diese Einheit enthält die kombinierte Würfelfunktion (f_145850 aus dice.cpp) für zusammengesetzte
 * DSA-Würfelformeln der Form N W M + Bonus (z. B. 2W6+4 für Waffenschaden oder Zauberwirkung).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAAIF.H"
// OPT -4r -oneatx -oe=1000 -zp1 -s
// Astra650: Teilungsvorschlag, vor Einbau mit Astra491/Claude abgleichen.
// P3 8/41 gleich (suche.py 26.10.2026, Basis fz_145760_t1_P1.CPP)
// HINWEIS: nur f_1461f4..f_146900 sind im Original unoptimiert (-od, ebp-Rahmen); f_145760..f_146170 (dice/aifload) sind optimiert (-4r -oneatx -oe=1000 -zp1 -s)
// fz_145760_t1 (Schatten ueber Riva) - Pass 1 Einheit 145760-146920
#include <string.h>
#include <stdlib.h>
#pragma inline_depth(20)
int f_1664d0(const char *a, const char *b, int c);
int f_014540(int sz, const char *file, int line);
int f_099ef0(int, ...);
int f_145547(const char *a, const char *b, int n);
void f_145300(void *p, int v, int n);
void *f_147c84(void *p, int n, int d);
int f_147cd0(int p1);
int f_147ef0(int p1, int p2, char *p3, int p4);
int f_1680f5(int a, int b);
int f_1687c9(int a, int b);
short f_167f75(int a, void *b);
int f_146d86(int a, int b);
extern int d_1a97dc; extern int d_1c3914; extern int d_1a9824; extern short d_1c3918; extern int d_1c391c;
extern int d_1a9698; extern int d_1baac0; 
extern const char d_1b8970[]; extern const char d_1b8979[]; extern const char d_1b8982[]; extern const char d_1b898c[];
extern const char d_1a97e0[]; extern const char d_1a97f4[]; extern const char d_1a980c[]; extern const char d_1b8996[];
struct RivaFileStream;
struct X266 { char d[0x266]; };
int f_145c20(RivaAifImage *p); int f_145c80(RivaAifImage *p); int f_145d60(RivaAifImage *p, int p3); int f_145e30(RivaAifImage *p, char *dst);
void f_145ee0(RivaAifImage *p, char *dst); void f_146030(RivaAifImage *p, char *dst); void f_146170(RivaAifImage *p, char *dst);
int f_145a60(RivaAifImage *p, int name, int p3, char *buf, char fl);
char f_145df0(RivaAifImage *p);
#define ABS(x) abs(x)
#define ROLL(r,e) { short _e = (e); int _t; if (_e <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f); _t = (int)_lrotl(_lrotl(d_1a97dc ^ d_1c3914, 2) + d_1c3914 ^ d_1a97dc, 3); d_1a97dc = ABS(_t) + 1; r = ABS(_t) % _e + 1; }

union Narrow491 {int raw;short low;};
struct DiceFrame491 {Narrow491 range,bonus,sides,count;};
//@ f_145850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Würfelt eine komplette DSA-Würfelformel aus rawcnt Würfeln mit jeweils raweyes Seiten aus,
 *   summiert alle Einzelergebnisse, addiert den Modifikator rawadd und begrenzt das Endergebnis nach unten auf
 *   mindestens 0 (sodass z. B. ein hoher negativer Schadensmodifikator keinen negativen Gesamtwert erzeugt). Ist
 *   die Würfelanzahl negativ, wird ihre Betragszahl gewürfelt und das Würfelergebnis vom Modifikator abgezogen.
 * - Eingaben:
 *   - rawcnt: Anzahl der Würfel (N, als short ausgewertet; darf auch negativ sein).
 *   - raweyes: Augenzahl je Würfel (M, z. B. 6 für W6 oder 20 für W20).
 *   - rawadd: Fester Zuschlag oder Abzug (Bonus), der zur Würfelsumme addiert wird.
 * - Rückgabewert: Gesamtergebnis des Würfelwurfs als ganze Zahl (>= 0).
 * - Wichtige Variablen:
 *   - count: Betrag der Würfelanzahl (|rawcnt|).
 *   - sum: Laufende Summe der einzelnen Würfelwürfe.
 *   - d_1a97dc, d_1c3914: Globaler Zufallsseed und Systemtimer für die Berechnung jedes Einzelwurfs.
 === Ende Beschreibung === */
short f_145850(int rawcnt,int raweyes,int rawadd)
{
#pragma intrinsic(_lrotl,abs)
 struct Roll491 {static inline short value(DiceFrame491 &v) {
int argument491=v.range.raw=v.sides.raw;

  int t,copy1,copy2;
  if((short)argument491<=0)f_1664d0(d_1b8970,d_1a97e0,0x2f);
  (d_1a97dc)=abs((t=(int)_lrotl(t=((t=(int)_lrotl(t=(d_1a97dc) ^ (d_1c3914),2)) + (d_1c3914)) ^ (d_1a97dc),3),copy1=t,t))+1;
  copy2=t;
  t=abs(t)%v.range.low+1;
  return t;

 }};
 DiceFrame491 v;
 v.count.raw=rawcnt;
 v.sides.raw=raweyes;
 v.bonus.raw=rawadd;
 register short i;
 register short sum=0;
 if((short)raweyes<=0)f_1664d0(d_1b8979,d_1a97e0,0x47);
 for(i=0;i<v.count.low;i++)sum+=Roll491::value(v);
 sum+=v.bonus.low;
 if(sum<0)sum=0;
 return sum;
}
