/* === Beschreibung (Katalog) ===
 * Einheit star_t1 (0x11395c - 0x114f50)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil des Dungeon-Komplexes "Bienenstock / Bau der Königin" (star.cpp,
 * *Hive* / *Sternenschweif-artiger Wabenbau*). Sie registriert die globalen Zustandsvariablen des Bienenstocks
 * für den Spielstand und steuert die Raumlogik, Waben-Übergänge, Larven-/Wächter-Begegnungen sowie den
 * Harz-/Wachs-Effekt auf den Bodenfeldern.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 10/14 gleich (suche.py 26.10.2026, Basis star_t1_P1.CPP)
// star.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x113970-0x1155D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039910(int p1, int p2);                           // reg eax edx stapel 0
int __cdecl f_041030(int p1, int p2);                   // reg - stapel 8
int f_042380(int p1);                                   // reg eax stapel 0
signed char f_042400(int p1);
short f_042470(int p1);
short f_042960(int p1);
short f_042a60(int p1, int p2);
short f_042ac0(int p1, int p2);
unsigned short f_044210(int p1);
int f_044220(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04a890(int p1);                                   // reg eax stapel 0
int f_04ad40(int p1, int p2);                           // reg eax stapel 0
int f_04f3f0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_0bf820(int p1, ...);
int f_0ce2f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0ce3e0(int p1, int p2);
int f_0ce4f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0ce590(int p1, int p2, int p3);
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d4aa0(int p1, int p2);
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
short f_0dc020(int p1, int p2);
short f_0dcc10(int p1);
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dd440(int p1);
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0de0d0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
short f_0de820(int p1);
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_113810();                                         // reg - stapel 0
int f_115660();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0

int f_1137e0();
void f_114130(int p1, int p2, int p3, int p4);
void f_1143a0(int p1, short p2, int *p3);
int f_114290(int p1);
extern int d_1bc894;
extern int d_1bd6c0;
extern char d_1bf230[];
extern int d_1c0004;
extern char d_1c0928;
extern int d_1c092c;
extern char d_1c095c;
extern char d_1c0960;
extern char d_1c21b4[];
extern char d_1c22e0[];
extern char d_1c240c[];
extern int d_1c2538[];
extern int d_1c256a[];

extern char d_1c2c64[];
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1a7a78[];
extern short d_1a7a94[];
extern short d_1a7ab4[];
struct SO { int a; int *p; char c[52]; SO(const char*,const char*,const char*); ~SO(); };
struct T2 { int a; int b; T2(); ~T2(); };
struct B128 { char c[0x128]; };
#define CH ((int)d_1c2c64)
#define BODYA(u) f_0ce4f0((u), 0x1bc, 0x2a); a_ = f_042a60((u), 0xe); if (0 < a_) { if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + a_ * 4)))->f_0a7950() == 0) b_ = 1; else b_ = f_042ac0((u), 0xe); do { x_ = f_035180((u), 0xe); } while (x_ == 1); f_0366e0((u), a_, 2, b_); }
#define BLK2(u) f_0ce4f0((u), 0x198, 9999); o_ = f_0de0d0((int)f_1137e0); if (o_ == 0) { t_ = f_041030(); f_0de9d0(t_, 1); f_0de9f0(t_, 2); f_0de830(t_, -1); f_0de810(t_, -1); } else { a_ = f_0dc020(d_1c0004, (u)); f_0dcdf0(d_1c0004, a_); a_ = f_0dcc10(o_); f_0dcc40(o_, (u), a_); }
#define LOOP198 sv = 0; if (0 < (short)p2) { do { u = p3[sv]; BLK2(u) sv++; } while (sv < (short)p2); }
#define LOOPN(X) sv = 0; if (0 < (short)p2) { do { u = p3[sv]; BODYA(u) v5 = f_115660(); sv++; f_036a10(u, 0x1bc, 1, 0xe, v5); d_1bc894 = 0; } while (sv < (short)p2); }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_113970
/* === Beschreibung (Katalog) ===
 * - Zweck: Periodische Prüfroutine für den Bienenstock-Fluch bzw. das Insektensekret-Intervall
 *   (f_044210/f_044220) auf allen sechs Gruppenplätzen: Sie zählt den Zähler jedes lebenden Helden um 1
 *   herunter, gibt beim Erreichen von 1 (n4 > 0) eine Warnmeldung (0x2e000013 bzw. 0x2e000014) aus und bietet
 *   beim Ablauf (u == 0, n10 > 0) im Auswahlfenster 0x2e000015 das Einnehmen des Gegenmittels 0x198 (f_0ce590,
 *   setzt den Zähler auf 20), das Öffnen des Inventars oder das Erleiden tödlichen Schadens (Heal::run) an.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: n4 (Anzahl der Helden mit Restzähler 1 in d_1c2538), n10 (Anzahl der Helden mit
 *   Restzähler 0 in d_1c256a), sv (Auswahl im Dialog 0x2e000015).
 === Ende Beschreibung === */
void f_113970(void)
{
  struct PL { char pad[16]; int *p; char rest[40]; } o;
  void f_1254a0(void *, int);
  struct Heal { static void run(int *pp, short count) {
    short j;
    for (j = 0; j < count; j++) {
      f_044300(pp[j], f_042960(pp[j]));
      f_0bbf00((int)d_1bf230);
    }
  }
  static void rest(short n, int *pp) {
    short j;
    for (j = 0; j < n; j++) {
      f_044300(pp[j], f_042960(pp[j]));
      f_0bbf00((int)d_1bf230);
    }
  } };
  short t;
  struct Test { static int eq(int a, int b) { return a == b; } };
  struct Slot { int a; Slot &operator=(int x) { a = x; return *this; } };
  f_125400((int)&o, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
  char *nm[2];
  int *ls0[1];
  int *ls1[1];
  (void)&nm; (void)&ls0; // Adressnahme haelt die Arrays im Speicher (Stapelplaetze 0x3c-0x48)
  ls0[0] = d_1c2538;
  ls1[0] = d_1c256a;
  nm[0] = d_1c22e0;
  nm[1] = d_1c240c;
  short n4 = 0;
  short n10 = 0;
  short i;
  for (i = 0; (short)i < 6; i++) {
    int v = f_0de7d0(d_1c0004, (short)i);
    int w = v;
    if (v == 0) continue;
    if ((signed char)f_042470(v) != 0) continue;
    if (f_042400(v) != 0) continue;
    unsigned short u = f_044210(v);
    if (u > 0) {
      u--;
      f_044220(v, u);
    }
    if (u == 1) ((Slot *)d_1c2538)[n4++] = w;
    else if (u == 0) ((Slot *)d_1c256a)[n10++] = w;
  }
  if (n4 > 0) {
    int m;
    f_0ce2f0(n4, (int)ls0[0], (int)nm[0]);
    o.p[1] = f_133fe0((int)d_1c3498, (int)nm[0]);
    if (Test::eq((signed char)d_1c0928, 0)) {
      m = 0x2e000013;
      d_1c0928 = 1;
      *(char *)&d_1c092c = 1;
    } else m = 0x2e000014;
    d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt den Register-Web-Gleichstand fuer d_1c0004 vor f_0bf730
    f_0bf730(CH, m);
  }
  if (n10 > 0) {
    short sv;
    f_0ce2f0(n10, (int)ls1[0], (int)nm[1]);
    o.p[1] = f_133fe0((int)d_1c3498, (int)nm[1]);
    if (f_0de820(d_1c0004) == 7) {
      sv = f_0bf820(CH, 0x2e000015, 3, 0x2e000016, 0x2e000017, 0x2e000018);
    } else {
      sv = f_0bf820(CH, 0x2e000015, 2, 0x2e000016, 0x2e000018);
      if (sv == 2) sv = 3;
    }
    switch (sv) {
    case 1: {
      short k = f_0ce590(d_1c0004, 0x198, n10);
      short j;
      for (j = 0; j < k; j++) f_044220(ls1[0][j], 0x14);
      if (k == n10) {
        f_0bf730(CH, 0x2e000019);
        break;
      }
      int used = k;
      f_0ce2f0((short)(n10 - k), (int)(ls1[0] + used), (int)d_1c21b4);
      o.p[1] = f_133fe0((int)d_1c3498, (int)d_1c21b4);
      if (used > 0) f_0bf730(CH, 0x2e00001a);
      else f_0bf730(CH, 0x2e00001b);
      struct Range { int *begin; short count; } range;
      range.begin = ls1[0] + k;
      range.count = n10 - k;
      Heal::rest(range.count, range.begin);
      break;
    }
    case 2: {
      f_0ce7c0((int)&t);
      B128 *q = new (mark(d_1a7a78, 0x1c9)) B128;
      int q2 = (int)q;
      q2 = q2 ? f_04a890(q2) : q2;
      f_04f3f0(q2, f_038c40(d_1c0004));
      if (q2 != 0) delete (char *)f_04ad40(q2, 0);
      f_0ce7e0((int)&t, 0);
      break;
    }
    case -1:
    case 3: {
      int *pp = ls1[0];
      f_0bf730(CH, 0x2e00001c);
      Heal::run(pp, n10);
    }
    }
    f_113810();
  }
  f_1254a0(&o, 0);
}
//@ f_113d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob das globale Auslöseflag d_1bc894 == 1 gesetzt ist, führt in diesem Fall die
 *   Harz-/Wachs-Prüfroutine f_114130(p1) aus und setzt d_1bc894 anschließend auf 0 zurück.
 * - Eingaben: p1 (Zeiger auf das Dungeon-/Szenenobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bc894 (Auslöseflag für das Festkleben der Schuhe).
 === Ende Beschreibung === */
void f_113d20(int p1)
{
  if (d_1bc894 == 1) {
    ((void (*)(int))f_114130)(p1);
    d_1bc894 = 0;
  }
}
//@ f_113d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst für einen einzelnen Helden p1 das Verkleben der Stiefel im Bienenstock aus: Die Funktion
 *   entfernt den Schuh-Gegenstand aus Ausrüstungsslot 0x0e (f_035180), legt ihn über f_0366e0 ins Gepäck zurück,
 *   rüstet stattdessen das verklebte Schuhwerk 0x1bc in Slot 0x0e aus (f_036a10) und setzt d_1bc894 = 0.
 * - Eingaben: p1 (Zeiger auf den betroffenen Helden).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: a_ (bisherige Gegenstands-ID in Slot 0x0e), b_ (Stückzahl).
 === Ende Beschreibung === */
void f_113d40(int p1)
{
  short a_;
  short b_;
  int x_;
  f_0ce4f0(p1, 0x1bc, 0x2a);
  a_ = f_042a60(p1, 0xe);
  if (0 < a_) {
    int i = (int)a_ * 4;
    char *p = (char *)((int)d_1c2c40);
    b_ = (((RivaItemDefinition*)(*(int *)(i + p)))->f_0a7950() != 0) ? f_042ac0(p1, 0xe) : 1;
    do {
      x_ = f_035180(p1, 0xe);
    } while (x_ == 1);
    f_0366e0(p1, a_, 2, b_);
  }
  f_036a10(p1, 0x1bc, 1, 0xe, 0);
  d_1bc894 = 0;
}
//@ f_113de0
/* === Beschreibung (Katalog) ===
 * - Zweck: Entspricht in seiner Wirkung f_113d40, erhält jedoch zusätzlich den Kontextzeiger p1 vor dem
 *   Heldenzeiger p2: Das bisherige Schuhwerk in Slot 0x0e von p2 wird abgelegt und durch den Gegenstand 0x1bc
 *   ersetzt.
 * - Eingaben: p1 (Kontextzeiger), p2 (Zeiger auf den betroffenen Helden).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: late (p2), a_ (Gegenstands-ID in Slot 0x0e), b_ (Stückzahl).
 === Ende Beschreibung === */
void f_113de0(int p1, int p2)
{
  int late = p2;
  short a_, b_;
  int x_;
  f_0ce4f0(p2, 0x1bc, 0x2a);
  a_ = f_042a60(p2, 0xe);
  if (0 < a_) {
    int i = (int)a_ * 4;
    char *p = (char *)((int)d_1c2c40);
    b_ = (((RivaItemDefinition*)(*(int *)(i + p)))->f_0a7950() != 0) ? f_042ac0(p2, 0xe) : 1;
    do {
      x_ = f_035180(late, 0xe);
    } while (x_ == 1);
    f_0366e0(late, a_, 2, b_);
  }
  f_036a10(late, 0x1bc, 1, 0xe, 0);
  d_1bc894 = 0;
}
//@ f_113e80
/* === Beschreibung (Katalog) ===
 * - Zweck: Wendet die Schuh-Verklebungslogik aus f_113d40 in einer Schleife auf alle p2 im Array p3 übergebenen
 *   Helden an (Ablegen des Gegenstands aus Slot 0x0e und Ausrüsten von 0x1bc).
 * - Eingaben: p1 (Kontextzeiger), p2 (Anzahl der Helden short), p3 (Array von Heldenzeigern int *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: sv (Schleifenindex 0..p2-1), u / late (aktueller Held p3[sv]).
 === Ende Beschreibung === */
void f_113e80(int p1, short p2, int *p3)
{
  short a_, b_;
  int x_;
  int sv;
  int u;
  int late;
  int result;
  int slot;
  sv = d_1bc894 ^ d_1bc894; // Nullinitialisierung ueber Selbst-XOR bestimmt die Registerwahl fuer sv
  if ((short)0 < p2) goto init;
  goto done;
init:
  slot = 0xe;
start:
  u = p3[(short)sv];
  f_0ce4f0(u, 0x1bc, 0x2a);
  a_ = f_042a60(u, slot);
  late = u;
  if (a_ <= 0) goto tail;
  {
    int *p = (int *)((int)d_1c2c40);
    if (((RivaItemDefinition*)(p[a_]))->f_0a7950() == 0) goto one;
  }
  result = f_042ac0(late, slot);
  goto positive;
tail:
  f_036a10(late, 0x1bc, 1, slot, 0);
  sv++;
  d_1bc894 = (((int)d_1c2c40) ^ ((int)d_1c2c40)) ^ (d_1bc894 ^ d_1bc894); // Selbst-XOR erzwingt das Nullschreiben ueber Register statt Immediate
  if ((short)sv >= p2) goto done;
  goto start;
one:
  result = 1;
positive:
  b_ = result;
  do {
    x_ = f_035180(late, slot);
  } while (x_ == 1);
  f_0366e0(late, a_, 2, b_);
  goto tail;
done:
  ;
}
//@ f_113f50
/* === Beschreibung (Katalog) ===
 * - Zweck: Sondert einen gefangenen oder handlungsunfähigen Helden p2 aus der aktiven Gruppe aus: Zuerst werden
 *   alle Exemplare von 0x198 entfernt (f_0ce4f0), anschließend wird entweder über f_041030 eine neue abgelegte
 *   Gruppe (t_) für ihn angelegt oder der Held über f_0dcdf0 und f_0dcc40 der bereits bestehenden
 *   Gefangenengruppe o_ (f_0de0d0(f_1137e0)) hinzugefügt.
 * - Eingaben: p1 (Kontextzeiger), p2 (Zeiger auf den abzutrennenden Helden).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: o_ (gefundene Gefangenengruppe), t_ (neu angelegte Gruppe), a_ (Gruppenplatz-Index).
 === Ende Beschreibung === */
void f_113f50(int p1, int p2)
{
  short a_;
  int o_, t_;
  f_0ce4f0(p2, 0x198, 9999);
  o_ = f_0de0d0((int)f_1137e0);
  if (o_ == 0) {
    t_ = ((int (*)(int, ...))f_041030)(1, p2);
    f_0de9d0(t_, 1);
    f_0de9f0(t_, 2);
    f_0de830(t_, -1);
    f_0de810(t_, -1);
    return;
  }
  a_ = f_0dc020(d_1c0004, p2);
  f_0dcdf0(d_1c0004, a_);
  a_ = f_0dcc10(o_);
  f_0dcc40(o_, p2, a_);
}
//@ f_113ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt die Gruppenabtrennung aus f_113f50 nacheinander für alle p2 im Array p3 übergebenen Helden
 *   durch und aktualisiert abschließend die Eingabe-/Oberflächenschleife über f_0bbf00(d_1bf230).
 * - Eingaben: p1 (Kontextzeiger), p2 (Anzahl der Helden short), p3 (Adresse des Heldenzeiger-Arrays).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: sv (Schleifenindex), u (aktueller Held), o_ (Zielgruppe).
 === Ende Beschreibung === */
void f_113ff0(int p1, short p2, int p3)
{
  short a_;
  int o_, t_;
  short sv = 0;
  int u;
  for (sv = 0; sv < p2; sv++) {
      u = *(int *)(p3 + sv * 4);
      f_0ce4f0(u, 0x198, 9999);
      o_ = f_0de0d0((int)f_1137e0);
      if (o_ == 0) {
        t_ = ((int (*)(int, ...))f_041030)(1, u);
        f_0de9d0(t_, 1);
        f_0de9f0(t_, 2);
        f_0de830(t_, -1);
        f_0de810(t_, -1);
      } else {
        a_ = f_0dc020(d_1c0004, u);
        f_0dcdf0(d_1c0004, a_);
        a_ = f_0dcc10(o_);
        f_0dcc40(o_, u, a_);
      }
  }
  f_0bbf00((int)d_1bf230);
}
//@ f_1140c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt anhand der aktuellen Gebiets-/Dungeon-ID (f_0de820) und der Gruppenposition (f_0dd440) den
 *   Umgebungsmodus für die Harz-/Wachs-Ereignisse (0 in Dungeon 7, 1 bzw. 2 auf den Positionen 0xc9/0xca in
 *   Dungeon 8, 3 sonst in Dungeon 8/9, 4 außerhalb).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Ermittelter Umgebungsmodus 0..4 (int).
 * - Wichtige Variablen: s (Dungeon-ID bzw. Positionswert), r (Moduscode).
 === Ende Beschreibung === */
int f_1140c0(void)
{
  short s = f_0de820(d_1c0004);
  int r = 4;
  if (s == 7) {
    r = 0;
  } else {
    s = f_0de820(d_1c0004);
    if (s == 9) {
      r = 3;
    } else {
      s = f_0de820(d_1c0004);
      if (s == 8) {
        s = f_0dd440(d_1c0004);
        if (s == (short)0xc9) {
          r = 1;
        } else if (s == (short)0xca) {
          r = 2;
        } else {
          r = 3;
        }
      }
    }
  }
  return r;
}
//@ f_114130
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchsucht alle sechs Gruppenplätze nach anwesenden, unversteinerten Helden (f_0d4a60 == 1, f_042400
 *   == 0), prüft über f_0ce3e0(e, 0x1bc), ob sie bereits verklebtes Schuhwerk (0x1bc) tragen, sammelt neu
 *   betroffene Helden (k == 0) im Array d_1c2538 und ruft für diese f_1143a0(p1, n, dest) auf.
 * - Eingaben: p1 (Dungeon-/Kontextzeiger), p2, p3, p4 (Registerparameter).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: n (Anzahl der betroffenen Helden), dest (d_1c2538), k (Anzahl von 0x1bc beim Helden).
 === Ende Beschreibung === */
#pragma aux f_114130 parm [eax] [edx] [ebx] [ecx] modify exact [eax gs]
void f_114130(int p1, int p2, int p3, int p4)
{
  short a_, b_;
  int x_;
  short n = 0;
  short i;
  short k;
  int e;
  int *dest = d_1c2538;
  int o = f_039040(d_1c0004);
  if (o != 0) {
    f_0ce4f0(o, 0x1bc, 0x2a);
    d_1bc894 = 0;
  }
  for (i = 0; i < 6; i++) {
    e = f_0de7d0(d_1c0004, i);
    if (e != 0 && f_0d4a60(e) == 1 && f_042400(e) == 0) {
      k = f_0ce3e0(e, 0x1bc);
      if (k == 0) {
        dest[n++] = e;
      } else if (1 < k) {
        int u = e;
        f_0ce4f0(u, 0x1bc, 0x2a);
        a_ = f_042a60(u, 0xe);
        if (0 < a_) {
          int j = (int)a_ * 4;
          char *base = (char *)((int)d_1c2c40);
          b_ = (((RivaItemDefinition*)(*(int *)(j + base)))->f_0a7950() != 0) ? f_042ac0(u, 0xe) : 1;
          do {
            x_ = f_035180(u, 0xe);
          } while (x_ == 1);
          f_0366e0(u, a_, 2, b_);
        }
        f_036a10(u, 0x1bc, 1, 0xe, 0);
        d_1bc894 = 0;
      }
    }
  }
  if (0 < n) {
    f_1143a0(p1, n, dest);
  }
}
//@ f_114290
/* === Beschreibung (Katalog) ===
 * - Zweck: Prädikatsfunktion für f_039910, die prüft, ob ein Held p1 in der aktuellen Gruppe anwesend
 *   (f_0d4a60(p1) != 0) und bei Bewusstsein (f_042400(p1) == 0) ist.
 * - Eingaben: p1 (Zeiger auf den Helden).
 * - Rückgabewert: 1, wenn der Held anwesend und handlungsfähig ist, sonst 0.
 * - Wichtige Variablen: r (Ergebnis von f_0d4a60), u (Rückgabewert).
 === Ende Beschreibung === */
int f_114290(int p1)
{
  int r = f_0d4a60(p1);
  int u = 0;
  if (r != 0) {
    if (f_042400(p1) == 0) {
      u = 1;
    }
  }
  return u;
}
//@ f_1142c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der aktiven Heldengruppe nach einem kampffähigen Helden, der nicht der Gruppenanführer ist
 *   und nicht mit dem übergebenen Helden identisch ist, wobei ein Held anderen Geschlechts bevorzugt wird.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen auszuschließenden Helden.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den gefundenen Begleitholden zurück oder 0, falls kein
 *   weiterer geeigneter Held vorhanden ist.
 === Ende Beschreibung === */
short f_1142c0(int p1, int *p2)
{
  short r = -1;
  short i;
  short t;
  int u;
  if (p2 != 0) {
    *p2 = 0;
  }
  for (i = 0; d_1a7a94[i] != -1 && r == -1; i++) {
    t = f_0d54f0(d_1c0004, d_1a7a94[i]);
    if (t != -1) {
      r = d_1a7a94[i];
      if (p2 != 0) {
        u = f_0de7d0(d_1c0004, t);
        *p2 = u;
        if (f_0d4a60(u) == 0) {
          *p2 = f_038be0(d_1c0004);
        }
      }
    }
  }
  return r;
}
//@ f_114340
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der Heldengruppe nach dem schwächsten bzw. am wenigsten geschützten Begleiter (anhand von
 *   Eigenschaftswert und Geschlecht relativ zum Anführer), der von Gefahren im Bienenstock zuerst betroffen
 *   wird.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen auszuschließenden Helden.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den ausgewählten Helden zurück oder 0, falls kein passender
 *   Begleiter gefunden wurde.
 === Ende Beschreibung === */
void f_114340(int p1, int p2, int p3)
{
  short s;
  int o;
  if ((short)p2 != (short)p3) {
    s = f_0d54f0(d_1c0004, (short)p2);
    o = f_0de7d0(d_1c0004, s);
    s = f_0d4aa0(o, (short)p2);
    f_035180(o, s);
    f_036a10(o, (short)p3, 1, s, 0);
  }
}
//@ f_1143a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Verarbeitet für die p2 im Array p3 gesammelten Helden je nach Umgebungsmodus (mode 0..3, analog zu
 *   f_1140c0) die Folgen des klebrigen Bienenstockbodens: Im Modus 0 (Ebene 1) werden gefangene Helden in die
 *   Waben verschleppt (f_113f50-Logik) oder durch das Amulett/Item 0x1b4 bzw. Ausziehen der Stiefel gerettet; im
 *   Modus 1 (0xc9) kann ein Seil/Hilfsmittel (f_1142c0, 0x105) genutzt werden; in den Modi 2 und 3 werden die
 *   Stiefel verklebt (0x1bc in Slot 0x0e) bzw. 2W6+5 Schadenspunkte (f_044850) verursacht.
 * - Eingaben: p1 (Dungeon-Zeiger), p2 (Anzahl der betroffenen Helden short), p3 (Array der Heldenzeiger int *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: mode (Umgebungscode 0..4), total (Gesamtzahl handlungsfähiger Helden aus f_039910), item
 *   (gefundenes Hilfsmittel aus f_1142c0).
 === Ende Beschreibung === */
static inline int k1_offset(short ix){return (int)ix*4;}
static inline int s906_eq(int a,int b){return a==b;}
void f_1143a0(int p1,short p2,int *p3)
{
  struct PL { int a; int *p1; int b; int c; int *p2; char rest[40]; } o;
  short mode;
  short item;
  short work0_a;
  short work1_count;
  short work20_count;
  short work2_a;
  short free1_count;
  short total;
  short work2_count;
  short work0_count;
  short work21_count;
  short work21_a;
  short free3_count;
  short work1_a;
  short work22_a;
  short free2_count;
  int g906;
  short work20_a;
  short i;
  short free0_count;
  short work22_count;
  int g907;
  void f_1254a0(void *, int);
  int birth;
  birth = p1;
  (void)(short)p1; /* tote Wortansicht fuer die interne Symbolsortierung */
  f_125400((int)&o, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
  short s = f_0de820(d_1c0004);
  mode = 4;
  if (s == 7) {
    mode = 0;
  } else {
    s = f_0de820(d_1c0004);
    if (s == 9) {
      mode = 3;
    } else {
      s = f_0de820(d_1c0004);
      if (s == 8) {
        s = f_0dd440(d_1c0004);
        if (s == (short)0xc9) {
          mode = 1;
        } else if (s == (short)0xca) {
          mode = 2;
        } else {
          mode = 3;
        }
      }
    }
  }
  total = f_039910(d_1c0004, (int)f_114290);
  d_1c21b4[0] = 0;
  switch (mode) {
  case 0:
    if (s906_eq((signed char)d_1c0960, 0)) {
      int m;
      if (p2 == 1) {
        o.p1[1] = p3[0];
        m = 0x2e000001;
      } else {
        f_0ce2f0(p2, (int)p3, (int)d_1c21b4);
        o.p2[1] = f_133fe0((int)d_1c3498, (int)d_1c21b4);
        m = 0x2e000002;
      }
      if (f_0bf6f0(CH, m) == 1) {
        if (total > p2) {
          if (p2 == 1)
            f_0bf730(CH, 0x2e000003);
          else
            f_0bf730(CH, 0x2e000004);
        }
        {
    short a; short i; int o; int u; int t; int *actors;
    free0_count=p2; actors=p3;

  i=0; u=0;
  for(i=0;i<free0_count;i++){
    u=actors[i];f_0ce4f0(u,0x198,9999);o=f_0de0d0((int)f_1137e0);
    if(o==0){t=((int (*)(int,...))f_041030)(1,u);f_0de9d0(t,1);f_0de9f0(t,2);f_0de830(t,-1);f_0de810(t,-1);}
    else{a=f_0dc020(d_1c0004,u);f_0dcdf0(d_1c0004,a);a=f_0dcc10(o);f_0dcc40(o,u,a);}
  }
    }
        f_0bbf00((int)d_1bf230);
      } else {
        f_0bf730(CH, 0x2e000006);
        {
    int late; int *actors; short b; int x; int r; int u;
    work20_count=p2; actors=p3;

  i=0;
  for(i=0;i<work20_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work20_a=f_042a60(u,0xe);late=u;
    if(0<work20_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work20_a]))->f_0a7950()!=0)r=f_042ac0(u,0xe);else r=1;g906=d_1c0004;d_1c0004=g906; /* codeloser Roundtrip fuer die Registerprioritaet */
      b=r;do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work20_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
      }
    } else {
       int found;
      found = 0;
      for (i = 0; i < p2; i++) {
        if (f_0d4aa0(*(int*)((char*)p3+k1_offset(i)), 0x1b4) != -1) {
          found = *(int*)((char*)p3+k1_offset(i));
          break;
        }
      }
      if (found != 0) {
        if (total > p2) {
          f_0bf730(CH, 0x2e000007);
          {
    int u; int *actors; short a; int t; int o;
    free1_count=p2; actors=p3;

  i=0; u=0;
  for(i=0;i<free1_count;i++){
    u=actors[i];f_0ce4f0(u,0x198,9999);o=f_0de0d0((int)f_1137e0);
    if(o==0){t=((int (*)(int,...))f_041030)(1,u);f_0de9d0(t,1);f_0de9f0(t,2);f_0de830(t,-1);f_0de810(t,-1);}
    else{a=f_0dc020(d_1c0004,u);f_0dcdf0(d_1c0004,a);a=f_0dcc10(o);f_0dcc40(o,u,a);}
  }
    }
        } else {
          f_0bf730(CH, 0x2e000008);
          {
    short a; int *actors; int t; int o; int u;
    free2_count=p2; actors=p3;

  i=0; u=0;
  for(i=0;i<free2_count;i++){
    u=actors[i];f_0ce4f0(u,0x198,9999);o=f_0de0d0((int)f_1137e0);
    if(o==0){t=((int (*)(int,...))f_041030)(1,u);f_0de9d0(t,1);f_0de9f0(t,2);f_0de830(t,-1);f_0de810(t,-1);}
    else{a=f_0dc020(d_1c0004,u);f_0dcdf0(d_1c0004,a);a=f_0dcc10(o);f_0dcc40(o,u,a);}
  }
    }
        }
      } else {
        f_0bf730(CH, 0x2e000009);
        {
    int *actors; short a; int o; int t; int u;
    free3_count=p2; actors=p3;

  i=0; u=0;
  for(i=0;i<free3_count;i++){
    int *addr=&actors[i]; {int *v=addr;addr=v;} u=*addr;f_0ce4f0(u,0x198,9999);o=f_0de0d0((int)f_1137e0);
    if(o==0){t=((int (*)(int,...))f_041030)(1,u);f_0de9d0(t,1);f_0de9f0(t,2);f_0de830(t,-1);f_0de810(t,-1);}
    else{a=f_0dc020(d_1c0004,u);f_0dcdf0(d_1c0004,a);a=f_0dcc10(o);f_0dcc40(o,u,a);}
  }
    }
      }
      f_0bbf00((int)d_1bf230);
    }
    f_113810();
    break;
  case 1: {
    item = f_1142c0(p1, 0);
    if (s906_eq((signed char)d_1c095c, 0) || item == -1) {
      o.p1[1] = p3[0];
      f_0bf730(CH, 0x2e00000a);
      f_0bf730(CH, 0x2e00000b);
      {
    int *actors; int late; int x; int u; int b;
    work0_count=p2; actors=p3;

  i=0;
  for(i=0;i<work0_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work0_a=f_042a60(u,0xe);late=u;
    if(0<work0_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work0_a]))->f_0a7950()!=0)b=f_042ac0(u,0xe);else b=1;
      do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work0_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
    }
    if (s906_eq((signed char)d_1c095c, 1) && item == 0x105) {
      o.p1[1] = p3[0];
      f_0bf730(CH, 0x2e00000a);
      if (f_0bf6f0(CH, 0x2e00000c) != 1) {
        f_0bf730(CH, 0x2e00000d);
        {
    int late; int *actors; int u; int r; short b; int x; int q;
    work21_count=p2; actors=p3;

  i=0;
  for(i=0;i<work21_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work21_a=f_042a60(u,0xe);late=u;
    if(0<work21_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work21_a]))->f_0a7950()!=0){r=f_042ac0(u,0xe);r=(r&0)?0:r; /* haelt r vor dem Kopieren in Register */}else r=1;
      q=r; /* Vollkopie fuer den 16-Bit-Transfer nach b */
      b=q; do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work21_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
      } else {
        s=f_0db9a0(d_1c0004);
        if (s > 1)
          f_0bf730(CH, 0x2e00000e);
        else
          f_0bf730(CH, 0x2e00000f);
        {
    int late; int *actors; int u; short b; int x; int r;
    work22_count=p2; actors=p3;

  i=0;
  for(i=0;i<work22_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work22_a=f_042a60(u,0xe);late=u;
    if(0<work22_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work22_a]))->f_0a7950()!=0)r=f_042ac0(u,0xe);else r=1;
      b=r;do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work22_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
        f_0dd750(d_1c0004, 0x1462);
        f_060a70();
        ((void (*)(int, int))(*(int **)(d_1bd6c0 + 8))[9])(d_1bd6c0, 0xc9);
        f_1254a0(&o, 0);
        return;
      }
    }
    break;
  }
  case 2:
    if (p2 == 1) {
      o.p1[1] = p3[0];
      f_0bf730(CH, 0x2e000010);
    } else {
      f_0ce2f0(p2, (int)p3, (int)d_1c21b4);
      o.p2[1] = f_133fe0((int)d_1c3498, (int)d_1c21b4);
      f_0bf730(CH, 0x2e000011);
    }
    {
    int *actors; int b; short i; int late; int x; int u;
    work1_count=p2; actors=p3;

  i=0;
  for(i=0;i<work1_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work1_a=f_042a60(u,0xe);late=u;
    if(0<work1_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work1_a]))->f_0a7950()!=0)b=f_042ac0(u,0xe);else b=1;g907=d_1c0004;d_1c0004=g907; /* codeloser Roundtrip fuer die Registerprioritaet */
      do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work1_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
    break;
  case 3: {
    f_0bf730(CH, 0x2e000012);
    short i;
    for (i = 0; i < p2; i++) {
      f_044850(p3[i], 2, 5);
    }
    {
    int u; int b; int late; int x; int *actors;
    work2_count=p2; actors=p3;

  i=0;
  for(i=0;i<work2_count;i++){
    u=actors[i];f_0ce4f0(u,0x1bc,0x2a);work2_a=f_042a60(u,0xe);late=u;
    if(0<work2_a){ int *table=(int *)((int)d_1c2c40);
      if(((RivaItemDefinition*)(table[work2_a]))->f_0a7950()!=0)b=f_042ac0(u,0xe);else b=1;
      do{x=f_035180(late,0xe);}while(x==1);
      f_0366e0(late,work2_a,2,(short)b);
    }
    int v=f_115660();f_036a10(late,0x1bc,1,0xe,v);d_1bc894=0;
  }
    }
    break;
  }
  }
  f_1254a0(&o, 0);
}

//@ f_114ef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der 57-teiligen Waffentabelle d_1a7ab4 (je 3 short-Werte pro Eintrag) nach dem ersten
 *   Gegenstand, den der Held p1 im Inventar trägt (f_0d4aa0(p1, s) != -1, bis zum Tabellenende s == -1), und
 *   gibt einen Zeiger auf diesen Tabelleneintrag zurück.
 * - Eingaben: p1 (Zeiger auf den Helden).
 * - Rückgabewert: Zeiger auf den passenden 6-Byte-Eintrag in d_1a7ab4 (short *).
 * - Wichtige Variablen: i (Tabellenindex 0..56), r (gefundener Eintragszeiger).
 === Ende Beschreibung === */
short *f_114ef0(int p1)
{
  short *r = 0;
  short i;
  for (i = 0; (unsigned)i < 57 && r == 0; i++) {
    short s = d_1a7ab4[(short)i * 3];
    if (s == -1 || f_0d4aa0(p1, s) != -1)
      r = (short *)((int)d_1a7ab4 + (short)i * 6);
  }
  return r;
}
