/* === Beschreibung (Katalog) ===
 * Einheit timeovl (0x1265c0 - 0x126c40)
 *
 * Überblick
 * Diese Einheit implementiert die grafische Tageszeit-, Himmels- und Datumsanzeige (timeovl.cpp, *Time
 * Overlay*), darunter die Formatierung des vollständigen aventurischen Datums- und Uhrzeit-Strings (inklusive
 * Jahreszeit, Wochentag und der fünf Namenlosen Tage) sowie das Zeichnen des Sonnen-/Mondlaufs im Himmelsfenster
 * der Benutzeroberfläche.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 2/4 gleich (suche.py 29.10.2026, Basis timeovl_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 0 gleich (vorher 0), Rest 219 (vorher 222)
// timeovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1265C0-0x126C40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_0bba10(int p1);                                  // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3420(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
unsigned short f_0de820(int p1);                                   // reg eax stapel 0
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
short f_1493c0(int p1, int p2);
#define DA(x) ((int)&(x))                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a8c00;                    // 0x1A8C00
extern int d_1a8c04;                    // 0x1A8C04
extern int d_1a8c08;                    // 0x1A8C08
extern unsigned short d_1a8c0c[];                    // 0x1A8C0C
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0294;                    // 0x1C0294
extern volatile int d_1c0c50;           // 0x1C0C50 - volatile verhindert CSE/Zusammenfassen der Zugriffe in f_126840
extern int d_1c0c94;                    // 0x1C0C94
extern short d_1c0c98;                    // 0x1C0C98
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern int d_1d0000;                    // 0x1D0000
extern const char d_1a8be0[];           // Text 0x1A8BE0
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

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

int C014540_3(int,int,int);
#pragma aux C014540_3 "f_014540" modify exact [eax ebx edx];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C04feb0_9(int,int,int,int,int,int,int,int,int);
#pragma aux C04feb0_9 "f_04feb0" modify exact [eax ebx ecx edx];
//@ f_1265c0  groesse 640 B, 153 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Erzeugt für das Zeit-Objekt p1 den ausgeschriebenen aventurischen Datums- und Uhrzeit-Text in
 *   d_1c21b4 (mit Sonderbehandlung für die Namenlosen Tage bei p1[7] < 0, Zuordnung des Monats p1[8] zu den vier
 *   Jahreszeiten und Ergänzung von Unterwasser-Atemluftinformationen in den Szenarien 0x17-0x19).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt (d_1c2c44).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_1267e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Bestimmt anhand des aktuellen Monats (p1[8]) die aktuelle Jahreszeit (0: Sommer, 1: Frühling, 2:
 *   Herbst, 3: Winter) durch Suche in den Monatstabellen d_1a8c00 bis d_1a8c08.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt den Jahreszeiten-Index (0 bis 3) zurück.
 === Ende Beschreibung === */
//@ f_126840  groesse 800 B, 229 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeichnet das Himmels-Overlay (72 x 22 Pixel an Bildschirmposition 244, 30), berechnet aus der
 *   Tageszeit (*(int *)(p1 + 1)), ob Tag (07:00-19:00 Uhr, 0x93a8-0x190c8) oder Nacht herrscht, lädt bei einem
 *   Tag-/Nacht-Wechsel die passenden Hintergrund- und Vordergrundgrafiken (0x1d0000) nach und setzt das Sonnen-
 *   bzw. Mondsymbölchen (4 x 4 Pixel) entlang der Bahnkurve d_1a8c0c.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt und in p2 ein Flag, das ein
 *   sofortiges Neuzeichnen erzwingt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */

struct OB { char b[16]; int pa; int pb; char rest[36]; };
struct N0 { char b[9]; N0(int a, int b2, int c) { ((int)(((RivaRasterImage*)((int)this))->f_0fac10( a, b2,(void *)( c)))); } };
struct N1 { char b[9]; N1(int a, int b2) { ((int)(((RivaRasterImage*)((int)this))->f_0fac80( a, b2))); } };
//@ f_1265c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Erzeugt für das Zeit-Objekt p1 den ausgeschriebenen aventurischen Datums- und Uhrzeit-Text in
 *   d_1c21b4 (mit Sonderbehandlung für die Namenlosen Tage bei p1[7] < 0, Zuordnung des Monats p1[8] zu den vier
 *   Jahreszeiten und Ergänzung von Unterwasser-Atemluftinformationen in den Szenarien 0x17-0x19).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt (d_1c2c44).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1265c0(signed char *p1)
{
  struct Context : OB {
    Context() { int f_125400(int, int, int, int); extern int d_1c3498; f_125400((int)this, DA(d_1c349c), DA(d_1c3870), DA(d_1c3498)); }
    ~Context() { f_1254a0((int)this, 0); }
  } ob;
  short s5;
  int arg;
  unsigned short u;
  signed char ch;
  // volatile auf den p1-Feldzugriffen erzwingt das erneute Laden aus dem Speicher statt Registerhaltung (CSE)
  s5 = (short)((*(volatile int *)(p1 + 1) % 0x1518) / 0x5a);
  if (p1[7] < 0) {
    int msg;
    *(int *)(ob.pa + 4) = p1[5] + 0x20000117;
    *(short *)(ob.pb + 2) = (short)*(volatile signed char *)(p1 + 9);
    *(short *)(ob.pb + 4) = (short)(*(volatile int *)(p1 + 1) / 0x1518);
    *(short *)(ob.pb + 6) = s5;
    if ((s5 == 1)) msg = 0x20000194; else msg = 0x200001ba;
    *(int *)(ob.pa + 8) = msg;
    arg = 0x20000142;
  } else {
    short k;
    int msg;
    *(int *)(ob.pa + 4) = p1[5] + 0x20000117;
    *(short *)(ob.pb + 2) = (short)*(volatile signed char *)(p1 + 7);
    *(int *)(ob.pa + 8) = p1[8] + 0x20000012;
    k = f_1493c0((int)*(volatile signed char *)(p1 + 8), DA(d_1a8c08));
    if (k != -1) k = 0;
    else {
      k = f_1493c0((int)*(volatile signed char *)(p1 + 8), DA(d_1a8c04));
      if (k != -1) k = 2;
      else {
        k = f_1493c0((int)*(volatile signed char *)(p1 + 8), DA(d_1a8c00));
        if (k != -1) k = 1; else k = 3;
      }
    }
    *(int *)(ob.pa + 0xc) = k + 0x20000151;
    *(short *)(ob.pb + 4) = (short)*(volatile signed char *)(p1 + 9);
    *(short *)(ob.pb + 6) = (short)(*(volatile int *)(p1 + 1) / 0x1518);
    *(short *)(ob.pb + 8) = s5;
    msg = (s5 == 1) ? 0x20000194 : 0x200001ba;
    *(int *)(ob.pa + 0x10) = msg;
    arg = 0x2000011e;
  }
  f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, arg);
  if (*(volatile signed char *)p1) {
    *(int *)(ob.pa + 4) = *p1 + 0x20000120;
    f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x2000011f);
  }
  u = f_0de820(d_1c0004);
  switch (u) { case 0x17: case 0x18: case 0x19: {
    ch = d_1c0294;
    *(short *)(ob.pb + 10) = ch;
    f_0e9300((int)&d_1c38b0, (int)&d_1c21b4, 0x20000120);
  } }
}
//@ f_1267e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Bestimmt anhand des aktuellen Monats (p1[8]) die aktuelle Jahreszeit (0: Sommer, 1: Frühling, 2:
 *   Herbst, 3: Winter) durch Suche in den Monatstabellen d_1a8c00 bis d_1a8c08.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt den Jahreszeiten-Index (0 bis 3) zurück.
 === Ende Beschreibung === */
int f_1267e0(signed char *p1)
{
  // volatile erzwingt das erneute Laden von p1[8] vor jedem f_1493c0-Aufruf
  int v = *(volatile signed char *)(p1 + 8);
  if (f_1493c0(v, DA(d_1a8c08)) != -1) return 0;
  v = *(volatile signed char *)(p1 + 8);
  if (f_1493c0(v, DA(d_1a8c04)) != -1) return 2;
  v = *(volatile signed char *)(p1 + 8);
  if (f_1493c0(v, DA(d_1a8c00)) != -1) return 1;
  return 3;
}
//@ f_126840
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeichnet das Himmels-Overlay (72 x 22 Pixel an Bildschirmposition 244, 30), berechnet aus der
 *   Tageszeit (*(int *)(p1 + 1)), ob Tag (07:00-19:00 Uhr, 0x93a8-0x190c8) oder Nacht herrscht, lädt bei einem
 *   Tag-/Nacht-Wechsel die passenden Hintergrund- und Vordergrundgrafiken (0x1d0000) nach und setzt das Sonnen-
 *   bzw. Mondsymbölchen (4 x 4 Pixel) entlang der Bahnkurve d_1a8c0c.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt und in p2 ein Flag, das ein
 *   sofortiges Neuzeichnen erzwingt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
#pragma inline_depth(8)
inline int address907(short offset, int base) { return base+offset; }
void f_126840(int p1, int p2)
{
  extern int d_1bf230;
  struct Locals {
    int status, second, index;
    void show(int handle) { ((RivaRasterImage*)(second))->f_0fae30((void *)(handle),(short)index,((signed char *)d_1a8c0c)[(short)index],1); }
    void release() {
      second=(second&0)?0:second; // haelt second im eigenen Register-Web fuer den Nulltest
      if(second) operator delete((void*)((int)(((RivaRasterImage*)(second))->f_0fad20(0))));
    }
    void hide(int found) {
      if(found) {
        ((int (*)())f_0d2710)();
        { // Global-Roundtrips entfallen nach der Registervergabe und halten EDX am Statusstore frei
          int a=d_1a34e0,b=d_1c0c94,c=d_1c2c64,d=d_1c2be0,e=d_1bf230;
          d_1c0c94=b; d_1bf230=e;
          status=1;
          d_1c2be0=d; d_1c2c64=c; d_1a34e0=a;
        }
      }
    }
  } l;
  short offset;
  int oldflag=0, time, handle, first, third, found, raw, newflag, one; // toter Startwert trennt das Register-Web
  p2=(p2&0)?0:p2; // haelt den Register-Web-Gleichstand zwischen p2 und oldflag
  if (!f_0bba10(DA(d_1bf230))) return;
  if (f_0e3360(DA(d_1c2c64)) || !d_1c0c94) return;
  time = *(int *)(p1 + 1);
  oldflag = d_1c0c50;
  l.status = 0;
  if (time >= 0x93a8 && time < 0x190c8) {
    d_1c0c50 = 1;
    time -= 0x93a8;
  } else {
    d_1c0c50 = 0;
    time -= 0x190c8;
    if (time < 0) time += 0x1fa40;
  }
  l.index = time / 0x355;
  if (!p2 && (short)l.index == d_1c0c98) return;
  handle = f_014540(0x1b80, (int)d_1a8be0, 0x101);
  offset = 0x30;
  d_1c0c98 = (short)l.index;
  if (d_1c0c50) {
    offset = 0;
    if ((short)l.index > 0x44) offset = 0x20;
    else if ((short)l.index > 5) offset = 0x10;
  }
  if (p2 || oldflag != d_1c0c50) {
    unsigned short buf; // Wort-Ausgabe von f_04feb0; Lebensdauer nur im Grafikzweig
    newflag = d_1c0c50;
    if (newflag) {
      f_04feb0(DA(d_1c2be0), 0x1d0000, *(int *)(p1 + 0xe), 0, 0, 3, (int)&buf, (int)&buf, 0x140);
      f_04feb0(DA(d_1c2be0), 0x1d0000, *(int *)(p1 + 0x16), 0, 1, 3, (int)&buf, (int)&buf, 0x140);
    } else {
      f_04feb0(DA(d_1c2be0), 0x1d0000, *(int *)(p1 + 0xe), newflag, 2, 3, (int)&buf, (int)&buf, 0x140);
      f_04feb0(DA(d_1c2be0), 0x1d0000, *(int *)(p1 + 0x16), 0, 3, 3, (int)&buf, (int)&buf, 0x140);
    }
  }
  first = (int)operator new(9, mark(d_1a8be0, 0x123));
  first = first ? ((int)(((RivaRasterImage*)(first))->f_0fac10( 0x48, 0x16,(void *)( *(int *)(p1 + 0xe))))) : first;
  ((RivaRasterImage*)(first))->f_0fae30((void *)( handle), 0, 0, 0);
  raw = (int)operator new(9, mark(d_1a8be0, 0x133));
  if(raw) { l.second=((int)(((RivaRasterImage*)(raw))->f_0fac10( 4, 4,(void *)( address907((short)offset, *(int *)(p1 + 0x12))))));  } else l.second=raw;
  l.show(handle);
  l.release();
  ((RivaRasterImage*)(first))->f_0fb060((void *)( *(int *)(p1 + 0x16)));
  ((RivaRasterImage*)(first))->f_0fae30((void *)( handle), 0, 0, 1);
  if (first) operator delete((void *)((int)(((RivaRasterImage*)(first))->f_0fad20( 0))));
  third = (int)operator new(9, mark(d_1a8be0, 0x148));
  third = third ? ((int)(((RivaRasterImage*)(third))->f_0fac80( 0x48, 0x16))) : third;
  ((RivaRasterImage*)(third))->f_0fafb0((void *)( handle), 0, 0);
  found = f_0d3420(0xf0, 0x1e, 0x13f, 0x37);
  l.hide(found);
  ((RivaRasterImage*)(third))->f_0fae30((void *)( d_1a34e0), 0xf4, 0x1e, 0);
  if (third) operator delete((void *)((int)(((RivaRasterImage*)(third))->f_0fad20( 0))));
  if (l.status) f_0d26e0();
  operator delete((void *)handle);
}
//@ f_126b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Allokiert beim Initialisieren des Zeit-Objekts p die drei Grafikpuffer für Himmelshintergrund (+14),
 *   Gestirnsymbole (+18, vier Phasen zu je 16 Bytes) und Himmelsvordergrund (+22) und lädt die Startgrafiken aus
 *   dem Archiv 0x1d0000.
 * - Eingaben: Die Funktion erhält im Parameter p den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_126b60(int p)
{
    int scratch;
    short slot;
    short picture;
    NI(p, 14) = C014540_3(0x630, NA(d_1a8be0), 0x173);
    NI(p, 18) = C014540_3(0x40, NA(d_1a8be0), 0x174);
    NI(p, 22) = C014540_3(0x630, NA(d_1a8be0), 0x175);
    C04feb0_9(NA(d_1c2be0), 0x1d0000, NI(p, 14), 0, 0, 3, (int)&scratch, (int)&scratch, 0x140);
    picture = 4;
    slot = 0;
    C04feb0_9(NA(d_1c2be0), 0x1d0000, NI(p, 22), 0, 1, 3, (int)&scratch, (int)&scratch, 0x140);
    for (; slot < 4; ++slot) {
        int base,address; // Feld-Roundtrip haelt Basis bis zur Registervergabe separat
        C04feb0_9(NA(d_1c2be0), 0x1d0000, (base=NI(p,18),NI(p,18)=base,address=(int)slot*16,address+=base), 0, picture, 3, (int)&scratch, (int)&scratch, 0x140);
        ++picture;
    }
}
