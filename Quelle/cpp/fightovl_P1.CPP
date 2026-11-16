/* === Beschreibung (Katalog) ===
 * Einheit fightovl (08bcd0 - 08cb00)
 *
 * Überblick
 * Die Einheit fightovl (Fight Overlay) bildet die äußere Klammer des gesamten Rundenkampfsystems: Sie enthält
 * den Konstruktor (f_08bcd0) und Destruktor (f_08c2e0) der Hauptkampfstruktur (0x107d Bytes), die äußere
 * Kampfsteuerung (f_08c5b0), den Runden-Spezialeffekt für aufbrechende Bodenkacheln (f_08c820) sowie den
 * Haupteinstiegspunkt f_08c920, über den das Spiel aus Städten, Dungeons und Ereignissen heraus einen
 * Rundenkampf startet.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 0/5 gleich (suche.py 26.10.2026, Basis fightovl_P1.CPP)
// fightovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08BCD0-0x08CB00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e0c0();                                         // reg - stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_050770(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
int f_0712f0(int p1, int p2);                           // reg eax edx stapel 0
int f_071e50(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_0757f0(int p1);                                   // reg eax stapel 0
int f_077540(int p1);                                   // reg eax stapel 0
#pragma aux f_077540 modify [eax ecx edx];
int f_0789a0();                                         // reg - stapel 0
int f_07aec0(int p1);                                   // reg eax stapel 0
int f_07e5c0(int p1);
#pragma aux f_07e5c0 modify [eax ebx ecx];
int f_07ea90(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_08ba30(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a470(int p1);                                   // reg eax stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d38b0(int p1);                                  // reg eax stapel 0
int f_0d38d0(int p1);                                   // reg eax stapel 0
int f_0d3950(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0d4880(int p1);                                  // reg eax stapel 0
int f_125e50(int p1, int p2);                           // reg eax edx stapel 0
int f_13fc70(int p1);                                   // reg eax stapel 0
int f_13fcd0(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a2840[];           // Text 0x1A2840

// --- eigene Deklarationen ---
extern const char d_1a2840[];
int f_014540(int sz, const char *file, int line);
int f_145300(int p1, int p2, int p3);
int f_09c770(int p1, int p2);
int f_09c780(int p1);



#pragma aux f_0fb0b0 parm [eax] [edx] [ecx];
int f_04feb0(int a1, int a2);
#pragma aux f_04feb0 parm [eax] [ebx];
short f_050710(int p1, int p2);
int f_038c80(int p1);
int f_043480(int p1, int p2);
int f_0391b0(int p1, int p2);
int f_0cf920(int p1, int p2);
int f_0cfc60(int p1, int p2);

int f_06a710(int p1, int p2);
int f_0e3390(int p1, int p2);
int f_06fb00();
int f_06fad0();
int f_10a940(int p1);
int f_07e640(int p1, int p2);
int f_1567af(int p1);
int f_147c84(int p1, int p2, int p3);

short f_07a730(int p1, int p2);
short f_0de7f0(int p1);
int f_099ef0(...);
#pragma aux f_099ef0 modify [eax ecx edx];
short f_149360(int p1, int p2);
extern int d_1c0c94, d_1bdaf4, d_1bdafc, d_1bdaec, d_1c2d1c, d_1bd914, d_1bd944, d_1bd940;
extern volatile int d_1bd948; // haelt den Speicherzugriff bei der Freigabe in f_08c2e0 wie im Original
extern int *d_1bd92c; extern int *d_1bd93c; extern char *d_1bd930; extern char *d_1bd984;
extern int d_1c2ed4, d_1c2be0, d_1bd768, d_1bda5c, d_1c0004, d_1c2c64;
extern short d_1bd938, d_1bd910, d_1a250a, d_1bc96c, d_1bc96e, d_1bc970, d_1bc972, d_1bc974, d_1bdaf8;
extern signed char d_1bd90e;
extern short d_1bd920;
extern char d_1bd928;
extern int d_1bd94c, d_1bda64, d_1bda68, d_1bda54, d_1c0c4c, d_1c2a80, d_1c2c44, d_1a34e0, d_1a280c, d_1baac0;
extern short d_1bd90c;
extern unsigned short d_1c2198;
extern int d_1bda60;
extern int d_1bd934;
extern int d_1bdae4, d_1bdae8, d_1c14c4, d_1c349c;
extern int d_1bc760, d_1bf520;
extern short d_1bf524;
extern short d_1bf4bc, d_1bf51c;
extern int d_1bf4be;
#define MAP(x,y) (*(d_1bd984 + (y)*0x19 + (x)))
#define W(o) (*(short *)(p + (o)))
#define I(o) (*(int *)(p + (o)))
#define C(o) (*(char *)(p + (o)))
#define EQ(x,v) (((x)==(v))?1:0)
struct S_73 { char b[0x73]; };
//@ f_08bcd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert als Konstruktor die Hauptkampfstruktur (p), reserviert die großen Grafik- und
 *   Hintergrundpuffer (d_1bdafc, d_1bdaec), das Kampfraster (d_1bd984), die Monstertabelle (d_1c2ed4) sowie die
 *   Kampfstil-Icons (p + 0x1f1, 0x1f5, 0x1f9) und ermittelt über die eingebettete Schaltertabelle die
 *   Sonderkampf-Kategorie d_1bd920.
 * - Eingaben und Rückgabe: Der Konstruktor erhält den Speicherzeiger p, die Kampfbegegnungsnummer a sowie den
 *   Überraschungsstatus b und gibt den initialisierten Kampfzeiger p zurück.
 * - Wichtige Variablen: Das Kampfraster d_1bd984 (600 Bytes für 24 x 25 Felder) und die Monstertabelle d_1c2ed4
 *   (0x8fc Bytes für 20 bzw. 40 Monsterstrukturen à 0x73 Bytes) werden hier dynamisch auf dem Heap angelegt.
 === Ende Beschreibung === */
static inline void z_i(int *a, int n) { a[n] = 0; }
static inline void z_c(char *a, int n) { a[n] = (char)0xff; }
static inline short sw(short a)
{
  short r = 0;
  if (d_1bd920 == -1) return r;
  switch ((unsigned short)a) {
    case 0x5e: case 0x5f: case 0x60: case 0x61: case 0x62: case 0x63: r = 1; break;
    case 0x81: r = 2; break;
    case 0x5c: r = 4; break;
    case 0x82: r = 5; break;
    case 0x3b: r = 6; break;
    case 0x97: r = 7; break;
    case 8: case 10: case 0x1f: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x41: case 0x42: case 0x43: case 0x5d: r = 3; break;
    case 0x3c: r = 8; break;
  }
  return r;
}
int f_08bcd0(int p, short a, int b)
{
#pragma aux cut_konv modify exact [eax ebx ecx edx];
typedef int __pragma("cut_konv") cut_t(int,unsigned,int,int,short,char,unsigned short *,unsigned short *,short);
typedef int pix_t(int);

  short i;
  int s, first;
  int obj;

  p = f_07e5c0(p + 0x39) - 0x39;
  f_145300(p, 4, 0);
  d_1bdaf4 = *(volatile int *)&d_1c0c94; // haelt die Befehlsreihenfolge vor dem ersten Speicherblock wie im Original
  I(0) = d_1bdafc = f_014540(0xfa00, d_1a2840, 0xab);
  d_1bdaec = f_014540(0xfa00, d_1a2840, 0xad);
  f_09c770((int)&d_1c2d1c, I(0));
  d_1bd914 = p;
  d_1bd92c = (int *)f_014540(0x258, d_1a2840, 0xb2);
  d_1bd930 = (char *)f_014540(0x96, d_1a2840, 0xb3);
  d_1bd93c = (int *)f_014540(0x28, d_1a2840, 0xb4);
  L_b5: // haelt die Blockgrenze fuer die Befehlsreihenfolge bei d_1bd984 wie im Original
  d_1bd984 = (char *)f_014540(0x258, d_1a2840, 0xb5);
  d_1bd944 = f_014540(((int)f_050710((int)&d_1c2be0, 0x260000) + 1) * 0x1a, d_1a2840, 0xb8);
  d_1c2ed4 = f_014540(0x8fc, d_1a2840, 0xba);
  d_1bd940 = f_014540(((int)(((RivaFileManager*)((int)&d_1c2098))->f_144a30( 0x1000f))), d_1a2840, 0xbb);

  obj = (int)operator new(9, mark(d_1a2840, 0xbd));
  I(0x1f5) = obj ? ((int)(((RivaRasterImage*)(obj))->f_0fac80( 0x16, 0xb))) : obj;
  obj = (int)operator new(9, mark(d_1a2840, 0xbe));
  I(0x1f1) = obj ? ((int)(((RivaRasterImage*)(obj))->f_0fac80( 0x16, 0xb))) : obj;
  obj = (int)operator new(9, mark(d_1a2840, 0xbf));
  I(0x1f9) = obj ? ((int)(((RivaRasterImage*)(obj))->f_0fac80( 0x16, 0xb))) : obj;
  {
    short x;
    ((cut_t *)f_04feb0)((int)&d_1c2be0,0x260000,((pix_t *)f_0fb0b0)(I(0x1f1)),0,7,0,(unsigned short *)&x,(unsigned short *)&x,0x140);
    ((cut_t *)f_04feb0)((int)&d_1c2be0,0x260000,((pix_t *)f_0fb0b0)(I(0x1f5)),0,8,0,(unsigned short *)&x,(unsigned short *)&x,0x140);
    ((cut_t *)f_04feb0)((int)&d_1c2be0,0x260000,((pix_t *)f_0fb0b0)(I(0x1f9)),0,9,0,(unsigned short *)&x,(unsigned short *)&x,0x140);
  }

  for (i = 0; i < (short)0x96; i++) d_1bd92c[i] = 0;
  for (i = 0; i < (short)0x1e; i++) I(i * 4 + 0x211) = 0;
  for (i = 0; i < (short)0xa; i++) z_i(d_1bd93c, i);
  for (i = 0; i < (short)0x1e; i++) W(i * 2 + 0x1031) = 0;
  for (i = 0; i < (short)0x1e; i++) W(i * 2 + 0x1ab) = 0;
  for (i = 0; i < 7; i++) C(i + 0x3d7) = 0;

  s = f_038c80(d_1c0004);
  first = s;
  do {
    f_043480(s, 0xff);
    s = f_0391b0(d_1c0004, s);
  } while (s != first);

  for (i = 0; i < (short)0x14; i++) {
    f_0cf920((int)(*(struct S_73 **)&d_1c2ed4 + (i)), 0);
    f_0cfc60(d_1c2ed4 + i * 0x73, 0xff);
  }
  for (i = 0; i < (short)0x96; i++) z_c(d_1bd930, i);
  C(0x344) = (char)0xff;
  C(0x293) = C(0x294) = C(0x343) = C(0x344);
  for (i = 0; i < 0x90; i++) C(i + 0x295) = (char)0xff;
  W(0x1a9) = (short)0;
  C(0x291) = C(0x1a9);
  C(0x35a) = C(0x291);
  d_1bd938 = (signed char)C(0x35a);
  d_1bd928 = (char)d_1bd938;
  W(0x1e8) = b;
  W(0x1ea) = (unsigned short)a;
  { short r_ = sw(W(0x1ea)); // haelt den Store nach d_1bd920 hinter I(0x205) wie im Original
  *(volatile int *)(p + 0x201) = 0; // haelt die Befehlsreihenfolge im Schlussblock wie im Original
  I(0x205) = 0;
  d_1bd920 = r_; }
  I(0x209) = 0;
  I(0x20d) = 0;
  // haelt die Registerzuteilung im Schlussblock wie im Original
  *(unsigned *)&d_1bd934 = p + 0x39;
  *(unsigned *)&d_1bda60 = 1;
  *(unsigned *)&d_1bda64 = 1;
  *(unsigned *)&d_1bda68 = 1;
  *(unsigned *)&d_1bd94c = p + 0x18;
  C(0x3de) = (char)0xff;
  *(unsigned *)&d_1bda54 = 1;
  d_1a250a = W(0x1ea);
  I(0x10) = f_014540(0x300, d_1a2840, 0x123);
  I(0x0c) = f_014540(0x1f4, d_1a2840, 0x124);
  f_09c780((int)&d_1c2d1c);
  d_1bda5c = f_014540(0x64, d_1a2840, 0x128);
  *(char *)d_1bda5c = 0;
  d_1bd768 = f_014540(0x550, d_1a2840, 0x12b);
  W(0x1a1) = f_050710((int)&d_1c2be0, 0x1000d);
  *(char *)&d_1bd90e = 0;
  f_0e3390((int)&d_1c2c64, 1);
  f_06fb00();
  f_09c780((int)&d_1c2d1c);
  obj = (int)operator new(0x76, mark(d_1a2840, 0x137));
  if (obj) I(0x1077) = f_10a940(obj); else I(0x1077) = obj;
  return p;
}
//@ f_08c2e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut als Destruktor die Hauptkampfstruktur (t) nach Kampfende wieder vollständig ab, gibt
 *   sämtliche geladenen Monster- und Heldenanimationen (d_1bd92c, d_1bd93c), das Kampfraster d_1bd984, die
 *   Monstertabelle d_1c2ed4 sowie die beiden 64000-Byte-Bildschirmpuffer frei und setzt die globalen Kampfzeiger
 *   zurück.
 * - Eingaben und Rückgabe: Der Destruktor nimmt den Kampfzeiger t sowie ein ungenutztes Flag unused entgegen und
 *   gibt den bereinigten Basiszeiger zurück.
 * - Wichtige Variablen: Über f_07e600 (aufgerufen via f_07e640 an t + 0x39) wird abschließend auch die
 *   verkettete Darstellungsliste (OList) abgebaut.
 === Ende Beschreibung === */
#undef I
#undef W
#undef C
#define I(o) (*(int *)(t + (o)))
#define W(o) (*(short *)(t + (o)))
#define C(o) (*(char *)(t + (o)))
#pragma aux del_konv parm [eax] modify exact [eax];
typedef void __pragma("del_konv") del_t(void *);
#define delf(x) ((del_t *)(void (*)(void *))operator delete)(x)
int f_08c2e0(int t, int unused)
{
  short i;
  short j;
  int q;

  delf((void *)I(0x1077));
  I(0x1077) = 0;
  delf((void *)d_1bd768);
  d_1bd768 = 0;
  delf((void *)d_1bda5c);
  d_1bda5c = 0;
  delf((void *)I(0x0c));
  I(0x0c) = 0;
  delf((void *)I(0x10));
  I(0x10) = 0;
  d_1bd910 = 0;
  d_1bd914 = 0;
  for (i = 0; i < (short)0x96; i++) {
    if (d_1bd92c[i] != 0) {
      q = d_1bd92c[i];
      if (q) delf((void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))));
      d_1bd92c[i] = 0;
    }
  }
  for (i = 0; i < (short)0x1e; i++) {
    if (I(i * 4 + 0x211) != 0) {
      q = I(i * 4 + 0x211);
      if (q) delf((void *)f_06a710(q, 0));
      I(i * 4 + 0x211) = 0;
    }
  }
  for (j = 0; j < (short)0xa; j++) {
    if (d_1bd93c[j] != 0) {
      q = d_1bd93c[j];
      if (q) delf((void *)f_06a710(q, 0));
      d_1bd93c[j] = 0;
    }
  }
  q = I(0x1f1);
  if (q) delf((void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))));
  I(0x1f1) = 0;
  q = I(0x1f5);
  if (q) delf((void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))));
  I(0x1f5) = 0;
  q = I(0x1f9);
  if (q) delf((void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))));
  I(0x1f9) = 0;
  delf((void *)d_1bd984);
  d_1bd984 = 0;
  delf((void *)d_1bd92c);
  d_1bd92c = 0;
  delf((void *)d_1bd930);
  d_1bd930 = 0;
  delf((void *)d_1bd93c);
  d_1bd93c = 0;
  delf((void *)d_1bd944);
  d_1bd944 = 0;
  delf((void *)d_1bd940);
  q = d_1bd948;
  d_1bd940 = 0;
  if (q) {
    delf((void *)q);
    d_1bd948 = 0;
  }
  delf((void *)d_1c2ed4);
  d_1c2ed4 = 0;
  delf((void *)I(0x1073));
  // haelt j (ebx) bis hierher lebendig fuer die originale Registerzuteilung
  I(0x1073) = j - j;
  delf((void *)I(0x1fd));
  I(0x1fd) = 0;
  delf((void *)d_1bdaec);
  q = I(0);
  d_1bdaec = 0;
  delf((void *)q);
  I(0) = 0;
  f_0e3390((int)&d_1c2c64, 0);
  f_06fad0();
  *(volatile int *)&d_1c0c94 = *(unsigned *)&d_1bdaf4; // haelt die Befehlsreihenfolge beim Schreiben von d_1c0c94 wie im Original
  d_1bd934 = 0;
  *(unsigned *)&d_1bd94c = 0; // haelt die Registerzuteilung der Schleifen wie im Original
  d_1a250a = -1;

  return f_07e640(t + 0x39, 0) - 0x39;
}
#undef I
#undef W
#undef C
#define W(o) (*(short *)(p + (o)))
#define I(o) (*(int *)(p + (o)))
#define C(o) (*(char *)(p + (o)))
//@ f_08c5b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das Kampfszenario (f_07a730), blendet das Schlachtfeld ein (f_077540), führt in einer
 *   Schleife Runde für Runde f_08ba30 und die Rundenabschlussprüfung f_07aec0 aus, bis der Kampf beendet ist
 *   (d_1bd90c == 0), wertet anschließend Beute und Abenteuerpunkte über f_0712f0 aus und speichert die
 *   Kampfstatistik (Ausgang, Rundenzahl, Dauer) in d_1bc96c..d_1bc974.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p und gibt den Kampfausgang (result: 0 = Sieg, 1
 *   = abgebrochen/leer, 2 = Niederlage, 3 = Einzelheld kampfunfähig) zurück.
 * - Wichtige Variablen: Das Feld W(0x1ec) zählt die absolvierten Kampfrunden hoch, und d_1bc974 speichert die
 *   verstrichene Echtzeitdauer des Kampfes.
 === Ende Beschreibung === */
short f_08c5b0(int p)
{

  // beide Lokalen als short fuer den 8-Byte-Stapelrahmen wie im Original
  short local = 0;
  short obj;
  int flag = 1;
  short result;

  if (f_0de7f0(d_1c0004) == 1 && (char)((short)(f_043290((struct hero *)(f_038c40(d_1c0004)))))) {
    d_1bd90e = f_07a730(p, W(0x1ea));
    result = 3;
    goto ende;
  }
  if (!f_07a730(p, W(0x1ea))) {
    d_1c2198 = 1;
    result = 1;
    goto ende;
  }
  {
    ++d_1c0c4c;
    f_0d2710();
    f_0ce7c0((int)&obj);
    f_09a0d0(d_1a34e0);
    f_050770((int)&d_1c2be0, 0x10005, I(0x10), 0xa0);
    if (f_149360(W(0x1ea), (int)&d_1a280c) == -1)
      f_099ef0(I(0x10), 0, 0x40);
    f_099ef0(I(0x10) + 0x180, 0x80, 0x20);
    d_1c2a80 = 0;
    f_077540(p);
    d_1bd910 = 1;
    while (d_1bd90c) {
      if (d_1bd928) f_069460();
      if (d_1c2198) {
        if (flag) {
          flag = 0;
          if (!C(0xee6)) {
            f_0757f0(p);
            ((int (*)(int))f_0789a0)(p);
            C(0xee6) = 1;
          }
        }
        f_0757f0(p);
        d_1c2198 = 0;
      }
      if (d_1bd90c) f_08ba30(p);
      --d_1c0c4c;
      W(0x1ec)++;
      f_125e50((int)&d_1c2c44, 9);
      ++d_1c0c4c;
      if (d_1bd90c) f_07aec0(p);
      if (d_1bd928) f_069460();
    }
    d_1bd910 = 0;
    f_0712f0(p, (int)&local);
    f_0d26e0();
    d_1bdae4 = f_1567af(0);
    d_1bc96c = W(0x1ea);
    d_1bc96e = local;
    d_1bc970 = W(0x1ec);
    d_1bc972 = d_1bd90e;
    d_1bc974 = d_1bdae4 - d_1bdae8;
    d_1bdaf8 = W(0x1ec);
    result = local;
    f_0ce7e0((int)&obj, 0);
  }
ende:
  return result;
}

//@ f_08c820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft zu Beginn jeder Kampfrunde, ob noch schlüpfende oder aufbrechende Spezialfelder
 *   (W(0x107b) > 0) im Kampf vorgesehen sind, durchsucht das gesamte Kampfraster nach Kacheln mit dem Wert 0x9a
 *   und lässt diese mit einer Wahrscheinlichkeit von 10 % pro Runde aufbrechen (f_071e50(..., 0)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zähler W(0x107b) begrenzt, wie viele solcher Spezialfelder im Verlauf des Kampfes
 *   noch ausgelöst werden können.
 === Ende Beschreibung === */
void f_08c820(int p)
{
  short y, x;
  if (W(0x107b) > 0) {
    for (y = 0; y < (short)0x18; y++) {
      for (x = 0; x < (short)0x19; x++) {
        unsigned int cell = (unsigned char)MAP(x, y);
        if (cell == 0x9a) {
          if (f_1457e0(100) < (unsigned short)10) {
            int r = f_07ea90(p + 0x39, 0x68, (signed char)x, (signed char)y);
            ((char *)r)[0x1f] = 1;
            f_071e50(p, x, y, 0);
            W(0x107b) = W(0x107b) - 1;
          }
        }
      }
    }
  }
}
struct R8 { int a, b; };

//@ f_08c910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Anweisungen (ret), die im Kampf-Overlay als ungenutzter Rückruf
 *   oder abgeschalteter Debug-Haken verblieben ist.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden weder lokale noch globale Variablen verwendet.
 === Ende Beschreibung === */
void f_08c910(void)
{
}

//@ f_08c920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet aus dem laufenden Spiel heraus den Rundenkampf mit der Begegnungsnummer a und dem
 *   Überraschungsmodus b: Sie sichert den aktuellen Maus-, Grafik- und Musikzustand, legt das Kampfobjekt
 *   (0x107d Bytes) auf dem Heap an, führt den gesamten Kampf über f_08c5b0 aus, gibt das Kampfobjekt wieder frei
 *   und stellt danach Farbpalette, Musik und Bildschirmbereich der Oberwelt bzw. des Dungeons wieder her.
 * - Eingaben und Rückgabe: Die Funktion nimmt die Kampfnummer a (unsigned short) sowie den Überraschungsmodus b
 *   (int) entgegen und gibt das Kampfergebnis aus f_08c5b0 zurück.
 * - Wichtige Variablen: Über f_13fc70 und f_13fcd0 wird das vor dem Kampf laufende Musikstück gemerkt und nach
 *   dem Kampf nahtlos fortgesetzt.
 === Ende Beschreibung === */
int f_08c920(unsigned short a, int b)
{
  extern int d_1c2e68;
  struct Rect {
    short a, b, c, d;
    Rect() { a = 0; b = 0; c = 0; d = 0; }
  };
  int temp[2];
  short image[4];
  Rect q;
  int saved524, saved520;
  unsigned short saved51c, saved4bc, saved4be;
  int message;
  int obj, palette, result;
  if (d_1bc760) f_01e0c0();
  saved51c = d_1bf51c;
  saved524 = *(int *)&d_1bf524;
  saved520 = d_1bf520;
  d_1bf51c = 0;
  saved4bc = d_1bf4bc;
  saved4be = d_1bf4be;
  f_0d2f90(0, 1);
  *(R8 *)&q = *(R8 *)f_0d38b0((int)temp);
  f_0d3950(0, 0, 0x13f, 0xc7);
  f_060a10(0x2625a0);
  message = f_13fc70((int)&d_1c14c4);
  f_0d4880((int)&d_1c2e68);
  { int t_ = (int)operator new(0x107d, mark(d_1a2840, 0x414)); obj = (t_ != 0) ? ((int (*)(int, short, short))f_08bcd0)(t_, a, (short)b) : t_; }
  result = 0;
  result = ((int (*)(int))f_08c5b0)(obj); // liest das ganze eax (mov esi, eax) wie im Original
  if (obj) operator delete((void *)f_08c2e0(obj, 0));
  f_13fcd0((int)&d_1c14c4, (short)message);
  f_0d2f90((short)saved4bc, 1);
  *(volatile short *)&d_1bf4be = saved4be; // haelt die Schreibreihenfolge von d_1bf4be wie im Original
  image[0] = q.a;
  image[1] = q.b;
  image[2] = q.c;
  image[3] = q.d;
  f_0d38d0((int)image);
  *(volatile short *)&d_1bf51c = saved51c; // haelt die Schreibreihenfolge von d_1bf51c wie im Original
  *(int *)&d_1bf524 = saved524;
  *(volatile int *)&d_1bf520 = saved520; // haelt die Schreibreihenfolge von d_1bf520 wie im Original
  palette = 0;
  palette = f_147c84((int)operator new[](0x300, mark(d_1a2840, 0x427)), 0x100, (int)&d_1baac0);
  palette = palette ? palette : 0;
  f_09a470(palette);
  f_09a140(0, 1);
  f_09a0d0(d_1a34e0);
  f_099ef0(palette, 0, 0x100);
  operator delete((void *)palette);
  return result;
}
