/* === Beschreibung (Katalog) ===
 * Einheit gz_0cd000_t1
 *
 * Diese Einheit gehört zur dritten Ebene der Zwergenmine (0x11, Text-Overlay 0x35) und verwaltet die
 * Untersuchung der neun Buchstaben-Tafeln (0x82 bis 0x8a) des Passworträtsels sowie die Bitmasken d_1bf358
 * (gesehene Buchstabenpositionen) und d_1bf35c (erkannte/zugeordnete Buchstabenpositionen) für das Lösungswort
 * d_1bf360.
 === Ende Beschreibung === */
// P3 4/11 gleich (suche.py 26.10.2026, Basis gz_0cd000_P1.CPP)
// gz_0cd000.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CD000-0x0CD730
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"






#define EQI(x,v) (((x)==(v))?1:0)
struct SO { char a[4]; int *p; char b[8]; int *q; char c[40]; };
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039780(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_0bf730(const char *p1, int p2);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
extern unsigned short d_1bf358;
extern unsigned short d_1bf35c;
extern char *d_1bf360;
#define SA(i) (d_1bf360[(i)])
#define SB(i) ((i)[d_1bf360])
extern int d_1c0004;
extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
inline void i3e0(char c) { short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf358 = d_1bf358 | (1 << i); } } }
inline void i430(char c) { short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf35c = d_1bf35c | (1 << i); } } }
inline int i470(char c) { int r = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i) && ((unsigned short)(1 << i) & d_1bf358) != 0) { r = 1; break; } } return r; }
inline int i4d0(char c) { int r = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i) && ((unsigned short)(1 << i) & d_1bf35c) != 0) { r = 1; break; } } return r; }
inline int i530(char c) { short n = 0; short i; for (i = 0; SB(i) != 0; i++) { if (c == SB(i)) { n = n + 1; } } return 1 < n; }
inline int i580(int p1, char c) { int r = 0; short i; for (i = 0; SA(i) != 0; i++) { if (c == SA(i)) { d_1bf358 = d_1bf358 | (1 << i); } } short s = f_044c90(p1, 0x27, 7); if (0 < s) { for (i = 0; SB(i) != 0; i++) { if (c == SB(i)) { d_1bf35c = d_1bf35c | (1 << i); } } r = 1; } return r; }
//@ f_0cd000
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird beim Untersuchen einer der neun Buchstaben-Inschriften (p2 = 0 bis 8) aufgerufen,
 *   wählt einen Zwerg (f_039780(d_1c0004, 9)) oder den Helden mit dem besten Wert im Talent 0x27 (Alte
 *   Sprachen/Schriften) aus, markiert den p2-ten Buchstaben des Lösungsworts d_1bf360 in d_1bf358 und gibt
 *   abhängig davon, ob der Buchstabe im Wort mehrfach vorkommt und ob er in d_1bf35c bereits entschlüsselt
 *   wurde, den passenden Hinweistext (0x35000183 bis 0x35000187) aus.
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie der nullbasierte Index p2 (0 bis 8) der
 *   untersuchten Buchstaben-Position.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
// haelt die Registerzuteilung wie im Original
// Separate Else-Helfer begrenzen die Wirkung auf die Original-Registerpaare.
void f_0cd000(int p1, short p2)
{
  int t;
  char c = 0;
  SO o;
  struct H5 {
    static int count(char c) {
      short n = 0;
      for (short i = 0; ((signed char *)((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360)))[i] != 0; i++)
        if (c == ((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360))[i]) n++;
      return n > 1;
    }
    static int test(char c, unsigned short &bits) {
      int r = 0;
      for (short i = 0; ((signed char *)d_1bf360)[i] != 0; i++) {
        if (c == d_1bf360[i]) {
          short mask = 1 << i;
          unsigned short saved = bits;
          mask &= saved;
          int b = mask != (short)0;
          if (b) { r = 1; break; }
        }
      }
      return r;
    }
    static void set(char c, unsigned short &bits) {
      for (short i = 0; ((signed char *)d_1bf360)[i] != 0; i++)
        if (c == d_1bf360[i]) bits = bits | (1 << i);
    }
    static void attempt(int t, char c) {
      H5::set(c, d_1bf358);
      if ((int)f_044c90(t, 0x27, 7) > 0) H5::set((short)(c & 0xffff), d_1bf35c); // haelt die Registerzuteilung wie im Original
    }
    static int testElse(char c, unsigned short &bits) {
      int r = 0;
      for (short i = 0; ((signed char *)((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360)))[i] != 0; i++) {
        if (c == ((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360))[i]) {
          short mask = 1 << i;
          unsigned short saved = bits;
          mask &= saved;
          int b = mask != (short)0;
          if (b) { r = 1; break; }
        }
      }
      return r;
    }
    static void setElse(char c, unsigned short &bits) {
      for (short i = 0; ((signed char *)((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360)))[i] != 0; i++)
        if (c == ((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360))[i]) bits = bits | (1 << i);
    }
    static void attemptElse(int t, char c) {
      H5::setElse(c, d_1bf358);
      if ((int)f_044c90(t, 0x27, 7) > 0) H5::set((short)(c & 0xffff), d_1bf35c); // haelt die Registerzuteilung wie im Original
    }
  };
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  t = f_039780(d_1c0004, 9);
  if (!t) t = f_039320(d_1c0004, 0x27);
  c = ((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360))[(*&p2)];
  c = (c & 0) ? 0 : c; // haelt die Registerzuteilung wie im Original
  o.p[1] = t;
  o.q[1] = (*&p2) + 0x3500017a;
  f_0bf730(d_1c2c64, 0x35000183);
  if (H5::count(c) == 1) {
    if (!H5::test(c, d_1bf358)) {
      H5::attempt(t, c);
      int r = H5::test(c, d_1bf35c);
      if (!r) f_0bf730(d_1c2c64, 0x35000184);
      else f_0bf730(d_1c2c64, 0x35000185);
    } else {
      int r = H5::test(c, d_1bf35c);
      if (!r) f_0bf730(d_1c2c64, 0x35000186);
      else f_0bf730(d_1c2c64, 0x35000187);
    }
  } else {
    int r = H5::testElse(c, d_1bf358);
    if (!r) H5::attemptElse(t, c);
    r = H5::test(c, d_1bf35c);
    if (r == 0) f_0bf730(d_1c2c64, 0x35000184);
    else f_0bf730(d_1c2c64, 0x35000185);
  }
  f_1254a0(&o, 0);
}
//@ f_0cd3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion durchläuft das Lösungswort d_1bf360 und setzt für jede Position i, an der das
 *   Zeichen c auftritt, das korrespondierende Bit (1 << i) in der Bitmaske d_1bf358.
 * - Eingaben: Als Parameter wird das zu markierende Zeichen c übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
static inline void set491(char c,unsigned short &bits) { short i; for(i=0;;i++){ int idx=i; char *p=d_1bf360+idx; if((signed char)*p==0)break; if(c==*p)bits=bits|(1<<i); } }
void f_0cd3e0(char c) { set491(c,d_1bf358); }
//@ f_0cd430
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion durchläuft das Lösungswort d_1bf360 und setzt für jede Position i, an der das
 *   Zeichen c auftritt, das korrespondierende Bit (1 << i) in der Bitmaske d_1bf35c.
 * - Eingaben: Als Parameter wird das zu markierende Zeichen c übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cd430(char c) { set491(c,d_1bf35c); }
//@ f_0cd470
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Zeichen c im Lösungswort d_1bf360 an mindestens einer Position
 *   vorkommt, deren Bit in der Maske d_1bf358 bereits gesetzt ist.
 * - Eingaben: Als Parameter wird das zu suchende Zeichen c übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Zeichen in d_1bf358 bereits markiert ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd470(char c)
{
    int r = 0;
    short i;
    for (i = 0; (signed char)d_1bf360[i] != 0; i++)
{
    if (c == d_1bf360[i])
{
    unsigned short *bitptr = &d_1bf358;
    short mask = 1 << i;
    unsigned short bits = *bitptr;
    int hit = (mask &= bits) != (short)0;
    if (hit)
{
    r = 1;
    break;
}
}
}
    return r;
}
//@ f_0cd4d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Zeichen c im Lösungswort d_1bf360 an mindestens einer Position
 *   vorkommt, deren Bit in der Maske d_1bf35c bereits gesetzt ist.
 * - Eingaben: Als Parameter wird das zu suchende Zeichen c übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Zeichen in d_1bf35c bereits markiert ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd4d0(char c)
{
    int r = 0;
    short i;
    for (i = 0; (signed char)d_1bf360[i] != 0; i++)
{
    if (c == d_1bf360[i])
{
    unsigned short *bitptr = &d_1bf35c;
    short mask = 1 << i;
    unsigned short bits = *bitptr;
    int hit = (mask &= bits) != (short)0;
    if (hit)
{
    r = 1;
    break;
}
}
}
    return r;
}
//@ f_0cd530
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion zählt, wie oft das Zeichen c im Lösungswort d_1bf360 auftritt, und prüft, ob es
 *   mehrfach (> 1) im Wort enthalten ist.
 * - Eingaben: Als Parameter wird das zu zählende Zeichen c übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Buchstabe mindestens zweimal im Lösungswort vorkommt,
 *   andernfalls 0.
 === Ende Beschreibung === */
int f_0cd530(char c)
{
    short n = 0;
    short i;
    for (i = 0; (signed char)SB(i) != 0; i++)
{
    if (c == SB(i))
{
    n = n + 1;
}
}
    return 1 < n;
}
//@ f_0cd580
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion markiert alle Vorkommen des Zeichens c im Lösungswort d_1bf360 als gesehen (d_1bf358),
 *   führt für den Helden p1 eine um 7 erschwerte Probe auf das Talent 0x27 durch und schaltet das Zeichen bei
 *   bestandener Probe auch in der Entschlüsselungsmaske d_1bf35c frei.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur sowie das untersuchte Buchstabenzeichen c.
 * - Rückgabewert: Zurückgegeben wird 1 bei bestandener Talentprobe, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd580(int p1, char c)
{
    volatile char saved = c;
    int p = p1;
    char key = c;
    int r = 0;
    short i;
    for (i = 0; (signed char)SA(i) != 0; i++)
{
    if (key == SA(i))
{
    d_1bf358 = d_1bf358 | (1 << i);
}
}
    short s = f_044c90(p, 0x27, 7);
    if (0 < s)
{
    key = saved;
    for (i = 0; (signed char)SB(i) != 0; i++)
{
    if (key == SB(i))
{
    d_1bf35c = d_1bf35c | (1 << i);
}
}
    r = 1;
}
    return r;
}
//@ f_0cd630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion legt für den Helden p1 eine Sinnesschärfe-Probe (0x33) mit der Erschwernis p2 ab
 *   und prüft, ob mehr als 1 Punkt übrig bleibt.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur sowie der Proben-Modifikator p2.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Probenergebnis größer als 1 ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0cd630(int p1, char p2)
{
    int r = 0;
    if (f_044c90(p1, 0x33, (signed char)p2) > 1) r = 1;
    return r;
}
