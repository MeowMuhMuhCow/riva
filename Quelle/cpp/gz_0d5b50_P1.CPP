/* === Beschreibung (Katalog) ===
 * Einheit gz_0d5b50
 *
 * Diese zusammengelegte Einheit umfasst das Ende von no_ovl.cpp und den Hauptteil von npc.cpp
 * (0x0D5B50-0x0D6690) und verwaltet das Aufräumen der Helden-Slots im Speicher (f_0d5bb0), die Registrierung der
 * NSC-Spielstandvariablen (f_0d5da0) sowie das Aufnehmen, Laden und Entlassen von Nichtspielercharakteren
 * (Begleit-NSCs) samt deren Vorstellungssequenzen (f_0d5ff0 bis f_0d65c0).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 2/3 gleich (suche.py 30.10.2026, Basis gz_0d5b50_P1.CPP)
// gz_0d5b50.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D5B50-0x0D5FF0
#include <string.h>
void *f_145300(void *p, int c, unsigned n);



#define A(x) ((int)&(x))
#define VOL signed
#define KV
struct S7 { int a[7]; };
struct B { char c[0x5ef]; };
extern unsigned short kb(unsigned cmd);
#pragma aux kb = "mov dh,ah" "int 16h" "jne short L1" "and dh,0fh" "dec dh" "jne short L1" "sub eax,eax" "L1:" parm [ah] value [ax] modify [dh];
int f_039040(int p1);

int f_069460();
int f_0d3780();
int f_0d37b0();
int f_0d3810();
int f_0dc020(int p1, int p2);
int f_0de790(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
extern int d_1bc8f0;
extern int d_1bfa7c;
extern signed char d_1bfa98;
extern short d_1bfa99;
extern signed char d_1bfa9c;
extern short d_1bfa9d;
extern signed char d_1bfaa0;
extern short d_1bfaa1;
extern signed char d_1bfaa4;
extern short d_1bfaa5;
extern signed char d_1bfaa8;
extern short d_1bfaa9;
extern signed char d_1bfaac;
extern short d_1bfaad;
extern signed char d_1bfab0;
extern short d_1bfab1;
extern signed char d_1bfab4;
extern short d_1bfab5;
extern signed char d_1bfab8;
extern short d_1bfab9;
extern signed char d_1bfabc;
extern short d_1bfabd;
extern signed char d_1bfac0;
extern short d_1bfac1;
extern signed char d_1bfac4;
extern short d_1bfac5;
extern int d_1bfdbc;
extern short d_1c212a;
extern int *d_1c212c;
//@ f_0d5b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Wartefunktion blockiert, solange noch eine Maustaste gedrückt gehalten wird (f_0d3780,
 *   f_0d37b0), leert den Tastaturpuffer über den BIOS-Interrupt 0x16 und aktualisiert abschließend den
 *   Mausbewegungsstatus (f_0d3810).
 * - Eingaben: Als Parameter wird das Flag p1 übergeben (1, um während des Wartens die Hintergrund-Update-Routine
 *   f_069460 aufzurufen).
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5b50(int p1)
{
  while (f_0d3780() || f_0d37b0()) {
    if (p1 == 1) f_069460();
  }
  while (kb(1)) kb(0);
  f_0d3810();
}
//@ f_0d5bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion komprimiert das globale Helden-Array d_1bc8f0 (Elementgröße 0x5ef Bytes), indem sie
 *   ungenutzte Lücken zwischen den aktiven Helden durch Aufrücken schließt und die Zeiger in den sechs
 *   Gruppenstrukturen (d_1bfdbc) über f_0de790 entsprechend anpasst.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5bb0(void)
{
 struct Group905 { char data[0x61];
   B *first() { return (B *)f_039040((int)this); }
   B *get(short i) { return (B *)f_0de7d0((int)this, i); }
   int index(B *q) { return f_0dc020((int)this,(int)q); }
   void link(short i,B *q) { f_0de790((int)this,i,(int)q); }
 };
 struct Frame905 { B *first; Group905 *group; int i,k,save,count; } f; int j; int used[7];
 short d; int e;
 B *src,*dst,*x,*base;
 Group905 *owner;
 int found,m;
 f.count=0; f.i=0;
 *(S7 *)used=*(S7 *)&d_1bfa7c;
 for(; (short)f.i<6; ++f.i) {
   f.group=((Group905 *)&d_1bfdbc)+(short)f.i;
   if(f.group) {
     f.first=f.group->first();
     if(f.first) ++f.count;
     for(e=0;(short)e<7;++e) {
       x=f.group->get(e);
       if(x && x!=f.first) {
         base=(B *)d_1bc8f0; for(d=0;d<7-(short)f.count;++d) {
           if(x==base+d) { used[d]=1; break; }
         }
       }
     }
   }
 }
 f.k=0; f.k=0; for(f.k=0;(short)f.k<6-(short)f.count;++f.k) {
   if(used[(short)f.k]) continue;
   found=0;
   for(m=f.k+1;(short)m<7-(short)f.count;++m)
     if(used[(short)m]) { found=1; break; }
   if(!found) break;
   for(j=f.k;(short)j<6-(short)f.count;++j) {
     owner=0;
     src=(B *)d_1bc8f0; src+=(short)j;
     int flag=used[(short)j+1]; /* haelt die Registerzuteilung wie im Original */ used[(short)j+1]=flag; ++src;
     if(flag) {
       owner=((Group905 *)&d_1bfdbc)+(signed char)((char)(f_042430((struct hero *)((int)src))));
       if(owner) f.save=owner->index(src);
     }
     int ji=(short)j; used[ji]=used[ji+1]; int off=(ji+1)*sizeof(B); int off2=ji*sizeof(B); off=(off&0)?0:off; /* haelt die Registerzuteilung wie im Original */ base=(B *)d_1bc8f0; x=(B *)((char *)base+off); dst=(B *)((char *)base+off2);
     *dst=*x;
     if(owner) owner->link((short)f.save,dst);
   }
   used[6-(short)f.count]=0;
   f_145300(((B *)d_1bc8f0)+6-(short)f.count,0,sizeof(B));
d_1bc8f0=(d_1bc8f0&0)?0:d_1bc8f0;  // haelt die Registerzuteilung wie im Original
    e=f.k; --e; f.k=e;
 }
}
//@ f_0d5da0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion setzt die zwölf globalen NSC-Statusvariablen (d_1bfa98 bis d_1bfac4,
 *   Spielstand-IDs 0x1ed bis 0x1f4, 0x23e und 0x25a bis 0x25c) auf 0 zurück und registriert sie in der globalen
 *   Speicherstand-Serialisierungsliste d_1c212a.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
struct Obj0d5da0 { signed char value; short id; };
struct Reg0d5da0 { short count; Obj0d5da0 **list; };
extern Obj0d5da0 d_o0d5da0_0, d_o0d5da0_1, d_o0d5da0_2, d_o0d5da0_3;
extern Obj0d5da0 d_o0d5da0_4, d_o0d5da0_5, d_o0d5da0_6, d_o0d5da0_7;
extern Obj0d5da0 d_o0d5da0_8, d_o0d5da0_9, d_o0d5da0_10, d_o0d5da0_11;
extern Reg0d5da0 d_r0d5da0;
#pragma aux d_o0d5da0_0 "d_1bfa98"
#pragma aux d_o0d5da0_1 "d_1bfa9c"
#pragma aux d_o0d5da0_2 "d_1bfaa0"
#pragma aux d_o0d5da0_3 "d_1bfaa4"
#pragma aux d_o0d5da0_4 "d_1bfaa8"
#pragma aux d_o0d5da0_5 "d_1bfaac"
#pragma aux d_o0d5da0_6 "d_1bfab0"
#pragma aux d_o0d5da0_7 "d_1bfab4"
#pragma aux d_o0d5da0_8 "d_1bfab8"
#pragma aux d_o0d5da0_9 "d_1bfabc"
#pragma aux d_o0d5da0_10 "d_1bfac0"
#pragma aux d_o0d5da0_11 "d_1bfac4"
#pragma aux d_r0d5da0 "d_1c212a"
inline signed char z_0d5da0()
{
  signed char c = 0;
  return c;
}
inline void add_0d5da0(Obj0d5da0 &o, Reg0d5da0 &r, short id)
{
  o.value = z_0d5da0();
  o.id = id;
  r.list[r.count] = &o;
  r.count++;
}
void f_0d5da0(void)
{
  add_0d5da0(d_o0d5da0_0, d_r0d5da0, 0x1ed);
  add_0d5da0(d_o0d5da0_1, d_r0d5da0, 0x1ee);
  add_0d5da0(d_o0d5da0_2, d_r0d5da0, 0x1ef);
  signed char c = 0;
  d_o0d5da0_3.value = c;
  d_o0d5da0_3.id = 0x1f0;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_3;
  d_r0d5da0.count++;
  d_o0d5da0_4.value = c;
  d_o0d5da0_4.id = 0x1f1;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_4;
  d_r0d5da0.count++;
  d_o0d5da0_5.value = c;
  d_o0d5da0_5.id = 0x1f2;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_5;
  d_r0d5da0.count++;
  d_o0d5da0_6.value = z_0d5da0();
  d_o0d5da0_6.id = 0x1f3;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_6;
  d_r0d5da0.count++;
  d_o0d5da0_7.value = c;
  d_o0d5da0_7.id = 0x1f4;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_7;
  d_r0d5da0.count++;
  d_o0d5da0_8.value = c;
  d_o0d5da0_8.id = 0x23e;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_8;
  d_r0d5da0.count++;
  short idx=d_r0d5da0.count;
  d_o0d5da0_9.value=c; d_o0d5da0_9.id=0x25a; d_r0d5da0.list[idx]=&d_o0d5da0_9; d_r0d5da0.count++;
  d_o0d5da0_10.value = c;
  d_o0d5da0_10.id = 0x25b;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_10;
  d_r0d5da0.count++;
  d_o0d5da0_11.value = c;
  d_o0d5da0_11.id = 0x25c;
  d_r0d5da0.list[d_r0d5da0.count] = &d_o0d5da0_11;
  d_r0d5da0.count++;
}


// ===== Teil 2: npc (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// P3 1/4 gleich (suche.py 25.10.2026, Basis npc_P1.CPP)
// npc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D5FF0-0x0D6690
// #include <string.h>




#define A(x) ((int)&(x))
#define EQI(x,v) (((x)==(v))?1:0)
#define EQ1(x) EQI(x, 0)
inline int EQC(signed char a, signed char b) { return a == b; }
struct OA { int a; int *p; int r[13]; };
struct OB { int a[4]; int *p; int r[10]; };
int f_039040(int p1);
int f_039580(int p1, int p2, int p3);




int f_057220(int p1, int p2, int p3);
int f_0bbf00(int p1);
int f_0dc020(int p1, int p2);
void f_0dc9a0(int p1);
int f_0dcc10(int p1);
int f_0dcc40(int p1, int p2, int p3);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);





int f_0d6420(int p1, short p2);
void f_0d64a0(void);
void f_0d5bb0(void);
void f_0d65c0(int p1, short p2);
extern unsigned d_1a5a7c[];
extern int d_1bf230;
extern signed char d_1bfa98;
extern signed char d_1bfa9c;
extern signed char d_1bfaa0;
extern signed char d_1bfaa4;
extern signed char d_1bfaa8;
extern signed char d_1bfaac;
extern signed char d_1bfab0;
extern signed char d_1bfab4;
extern signed char d_1bfab8;
extern int d_1bc8f0;
extern int d_1bfdbc;
extern int d_1c0004;
extern char d_1c002c;
extern signed char d_1c01c8;
extern signed char d_1c0240;

extern short d_1c2198;
extern int d_1c2c00;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a5a60[];
//@ f_0d5ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion nimmt den Begleit-NSC mit der Kennung p1 in die aktuelle Heldengruppe d_1c0004 auf:
 *   Sie räumt zuvor vorhandene NSCs ab (f_0d5bb0, f_0d64a0), lädt den neuen NSC über f_0d6420 in den siebten
 *   Helden-Slot (d_1bc8f0 + 0x239a), gliedert ihn per f_0dcc40 ein und spielt abhängig von seiner NSC-Nummer (1
 *   bis 8, f_042400) den zugehörigen Einführungs- oder Wiedersehensdialog (0x803007f bis 0x803008c, 0x803002e)
 *   ab.
 * - Eingaben: Als Parameter wird die Kennung p1 des aufzunehmenden Nichtspielercharakters übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5ff0(short p1)
{
  struct Eq { static inline int same(const signed char &a,signed char b) { return a == b; } };
  int buf;
  short r;
  int flag;
  struct OA o1;
  struct OA o2;
  signed char z;
  buf = d_1bc8f0;
  f_0d5bb0();
  f_0d64a0();
  r = f_0dcc10(d_1c0004);
  buf = buf + 0x239a;
  if (r != -1) {
    flag = f_0d6420(buf, p1);
    if (flag) {
      f_0dcc40(d_1c0004, buf, r);
      switch (((char)(f_042400((struct hero *)(buf))))) {
      case 1:
        if (Eq::same(d_1bfa98,0)) {
          f_057220(A(d_1c2c00), 0x803007f, 0);
          d_1bfa98 = 1;
          break;
        }
        f_057220(A(d_1c2c00), 0x8030080, 0);
        f_0bbf00(A(d_1bf230));
        return;
      case 2:
        if (Eq::same(d_1bfa9c, 0)) {
          f_057220(A(d_1c2c00), 0x803002e, 0);
          d_1bfa9c = 1;
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      case 3:
        if (Eq::same(d_1bfaa0, 0)) {
          f_057220(A(d_1c2c00), 0x8030081, 0);
          d_1bfaa0 = 1;
          f_0bbf00(A(d_1bf230));
          return;
        }
        f_057220(A(d_1c2c00), 0x8030082, 0);
        f_0bbf00(A(d_1bf230));
        return;
      case 4:
        if (Eq::same(d_1bfaa4, 0)) {
          f_057220(A(d_1c2c00), 0x8030083, 0);
          d_1bfaa4 = 1;
          f_0bbf00(A(d_1bf230));
          return;
        }
        if (Eq::same(d_1bfaa4, 1) && Eq::same(d_1c01c8, 0)) {
          f_057220(A(d_1c2c00), 0x8030085, 0);
          *(volatile signed char*)&d_1bfaa4 = 2;
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      case 5:
        if (Eq::same(d_1bfaa8, 0)) {
          f_057220(A(d_1c2c00), 0x8030087, 0);
          *(volatile signed char*)&d_1bfaa8 = 1;
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      case 6:
        if (Eq::same(d_1bfaac, 0)) {
          d_1bfaac = 1;
          f_0bbf00(A(d_1bf230));
          return;
        }
        if (Eq::same(d_1bfaac, 1) && Eq::same(d_1c0240, 0)) {
          f_057220(A(d_1c2c00), 0x803008a, 0);
          *(volatile signed char*)&d_1bfaac = 2;
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      case 7:
        if (Eq::same(d_1bfab0, 0)) {
          f_125400(A(o1), A(d_1c349c), A(d_1c3870), A(d_1c3498));
          o1.p[1] = f_039580(d_1c0004, 0, 0);
          f_057220(A(d_1c2c00), 0x803008b, 0);
          d_1bfab0 = 1;
          f_1254a0(A(o1), 0);
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      case 8:
        if (Eq::same(d_1bfab4, 0)) {
          f_125400(A(o2), A(d_1c349c), A(d_1c3870), A(d_1c3498));
          o2.p[1] = f_039580(d_1c0004, 0, 0);
          f_057220(A(d_1c2c00), 0x803008c, 0);
          d_1bfab4 = 1;
          f_1254a0(A(o2), 0);
          f_0bbf00(A(d_1bf230));
          return;
        }
        break;
      }
      f_0bbf00(A(d_1bf230));
    }
  }
}
//@ f_0d6420
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt den Datensatz des Begleit-NSCs p2 (0x5ef Bytes) anhand der Dateikennung
 *   d_1a5a7c[p2] | 0x40000000 aus dem Spielstand-/Datenarchiv d_1c2098 in den Zielpuffer p1 und trägt dort die
 *   aktuelle Gruppennummer d_1c002c ein (f_042440).
 * - Eingaben: Übergeben werden der Zielpuffer p1 (NSC-Heldenstruktur) sowie der NSC-Index p2.
 * - Rückgabewert: Zurückgegeben wird 1 bei erfolgreichem Laden, andernfalls 0.
 === Ende Beschreibung === */
int f_0d6420(int p1, short p2)
{
  int f = 0;
  if (((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1448b0( d_1a5a7c[p2] | 0x40000000, 0x200) != -1) {
    ((int)(((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_144920((void *)( p1), 0x5ef)));
    ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1449a0();
    { signed char t_ = (signed char)(d_1c002c); f_042440((struct hero *)(p1), t_); }
    f = 1;
  }
  return f;
}
//@ f_0d64a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle sechs Teilgruppen (d_1bfdbc) nach einem aktuell angeschlossenen
 *   Begleit-NSC (f_039040), entfernt diesen über f_0d65c0 aus der Gruppe und gibt bei den NSC-Typen 1, 2, 3 und
 *   5 die Abschiedsmeldung 0x20000175 mit dessen Namen aus.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d64a0(void)
{
  int save;
  char kind;
  struct OB obj;
  char *name;
  int p1;
  int cur; short i;
  save = d_1c0004;
  name = (char *)new (mark(d_1a5a60, 0xe7)) char[0x14];
  kind = 0;
  cur = (int)&d_1bfdbc;
  f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
  for (i = 0; i < 6; cur += 0x61, i++) {
    d_1c0004 = cur;
    p1 = f_039040(cur);
    if (p1) {
      kind = ((char)(f_042400((struct hero *)(p1))));
      strcpy(name, f_0422b0((struct hero *)(p1)));
      ((void (*)(int, int))f_0d65c0)(d_1c0004, p1);
      break;
    }
  }
  d_1c0004 = save;
  switch (kind) {
  case 2:
    d_1bfab8 = 1;
  case 1:
  case 3:
  case 5:
    obj.p[1] = f_133fe0(A(d_1c3498), (int)name);
    f_057220(A(d_1c2c00), 0x20000175, 0);
  case 4:
  case 6:
  case 7:
  case 8:
  default:
    delete name;
  }
  f_1254a0(A(obj), 0);
}
//@ f_0d65c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entfernt den Begleit-NSC p2 aus der Gruppe p1, speichert seinen aktuellen Zustand
 *   (0x5ef Bytes) unter der Kennung d_1a5a7c[c] | 0x40000000 zurück in das Archiv d_1c2098, löscht den Slot im
 *   Speicher (memset) und ordnet die Gruppe über f_0dc9a0(p1) neu.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Gruppenstruktur sowie der Zeiger p2 auf die Heldenstruktur
 *   des zu entlassenden NSCs.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d65c0(int p1, int p2)
{
  int cur; short i;
  short r;
  short one;
  int c;
  if (((char)(f_042400((struct hero *)(p2))))) {
    cur = (int)&d_1bfdbc;
    for (i = 0; i < 6 && cur != p1; i++, cur += 0x61) ;
    r = f_0dc020(p1, p2);
    *(char *)(p1 + 0x1c) = *(char *)(p1 + 0x1c) - 1;
    f_042440((struct hero *)(p2), 0);
    f_042450((struct hero *)(p2), 0);
    c = (signed char)((char)(f_042400((struct hero *)(p2))));
    ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_144890( d_1a5a7c[c] | 0x40000000);
    ((int)(((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_144960((void *)( p2), 0x5ef)));
    ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1449a0();
    memset((void *)p2, 0, 0x5ef);
    *(int *)(p1 + (short)r * 4) = 0;
    f_0dc9a0(p1); d_1c2198 = 1;
  }
}
