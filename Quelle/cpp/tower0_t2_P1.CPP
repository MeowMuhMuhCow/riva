/* === Beschreibung (Katalog) ===
 * Einheit tower0_t2 (0x128a20 - 0x1295c0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von tower0.cpp (untere Etagen des Magierturms) und implementiert
 * Rätsel-, Fallen-, Labor- und Bibliotheksräume, magische Barrieren (die durch *Odem Arcanum* / *Analüs* oder
 * zwei zusammenwirkende Magiebegabte überwunden werden können) sowie Beutecontainer.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/11 gleich (suche.py 26.10.2026, Basis tower0_t2_P1.CPP)
// tower0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1275B0-0x1295C0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038cb0(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039960(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_060990(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_129750();                                         // reg - stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149a14(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd922;                    // 0x1BD922
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0ca0;                    // 0x1C0CA0
extern int d_1c0ca4;                    // 0x1C0CA4
extern int d_1c0ca8;                    // 0x1C0CA8
extern int d_1c0cac;                    // 0x1C0CAC
extern int d_1c0cc8;                    // 0x1C0CC8
extern int d_1c0ccc;                    // 0x1C0CCC
extern int d_1c0cd4;                    // 0x1C0CD4
extern int d_1c0cdc;                    // 0x1C0CDC
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a8c58[];           // Text 0x1A8C58

// --- Overrides ---
extern signed char d_1c0cb0;
extern signed char d_1c0cb4;
extern signed char d_1c0cb8;
extern signed char d_1c0cbc;
extern signed char d_1c0cc0;
extern signed char d_1c0cd0;
extern signed char d_1c0cd8;
extern int d_1c3498;
extern int d_1c21b4[];
struct P2 { int a; int b; };
extern P2 d_1c0ce0;
typedef RivaTextContextData OB;
struct T { char d[20]; T *f_112df0(int a, int b, int c); void f_112ec0(); int f_1131b0(); T *f_112e70(int a); };
struct V { short (*f)(void *, int, int); };
struct X { char pad[8]; V *vt; };


short f_0d54f0(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_0398c0(int p1, int p2, int p3);
short f_0db9a0(int p1);
short f_0de480(int p1, int p2);
short f_0bf820(int p1, ...);
int f_0bfa20(int p1, ...);
#define EQI(x,v) (((x)==(v))?1:0)
#define PD(x) ((int)&(x))
#define CTOR(o) f_125400(PD(o), PD(d_1c349c), PD(d_1c3870), PD(d_1c3498))
#define DTOR(o) f_1254a0(PD(o), 0)
#define K147(m) f_147323(PD(d_1c2edc), m, 0x7fff, 0x8000, d_1a9820, 0, 1)

struct Int2 { int v[2]; };
extern Int2 d_1a8c78;   // Bild im Original: 0x2700004B, 0x2700004C (p3 hatte 0x11, 0x22 - Fixup-Ziel, Werte unsichtbar fuer den Vergleich)
//@ f_128a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das Untersuchen einer magischen oder alchemistischen Apparatur (d_1c0cb0), prüft ob die
 *   Gruppe ein Schutz- oder Hilfsmittel (0x49 oder 0x5d) besitzt, schwächt andernfalls beim ersten Mal
 *   (d_1c0cb4) die ersten beiden Helden für 24 Stunden (0x1fa40 Ticks) und legt anschließend eine Probe auf das
 *   Talent 0x2e (Zuschlag 7) ab.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128a20(void)
{
  int f_147323u(int,int,int,int,int,int,int);
#pragma aux f_147323u "f_147323" modify [esp];
  OB ob;
  int loc;
  int m;
  int t;
  short s;
  unsigned short u;
  CTOR(ob);
  if (EQI(d_1c0cb0, 0)) {
    if (EQI(d_1c0cd0, 0) && EQI(d_1c0cb0, 0)) {
      *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x1d);
      m = 0x2700002e;
    } else {
      m = 0x2700002f;
    }
    if (f_0bf6f0(PD(d_1c2c64), m) == 1) {
      loc = f_0606a0(0x270001, 1);
      if ((s = f_0d54f0(d_1c0004, 0x49)) != -1 || (s = f_0d54f0(d_1c0004, 0x5d)) != -1) {
        { int snd = d_1a9820; f_147323u(PD(d_1c2edc), 0x27000a, 0x7fff, 0x8000, snd, 0, 1); }
        u = 10;
        f_0bfa20(PD(d_1c2c64), loc, 0, 0x27000030, 0);
      } else {
        if (EQI(d_1c0cb4, 0)) {
          *(int *)(ob.addresses.numbers + 4) = 0x27000032;
        } else {
          *(int *)(ob.addresses.numbers + 4) = 0x20000194;
        }
        { int snd = d_1a9820; f_147323u(PD(d_1c2edc), 0x27000b, 0x7fff, 0x8000, snd, 0, 1); }
        f_0bfa20(PD(d_1c2c64), loc, 0, 0x27000031, 0);
        if (EQI(d_1c0cb4, 0)) {
          d_1c0cb4 = 1;
          f_044090(f_038c40(d_1c0004), 0x1fa40, 2);
          if (f_038cb0(d_1c0004) != 0) {
            f_044090(f_038cb0(d_1c0004), 0x1fa40, 2);
          }
        }
        u = 0x14;

      }
      t = f_039320(d_1c0004, 0x2e);
      *(int *)(ob.addresses.objects + 4) = t;
      s = f_044c90(t, 0x2e, 7);
      if (s > 0) {
        f_0bf730(PD(d_1c2c64), 0x27000033);
        d_1c0cb0 = 1;
      } else f_0bf730(PD(d_1c2c64), 0x27000034);
      f_0bf730(PD(d_1c2c64), 0x27000035);
      if (loc != 0) {
        operator delete((void *)((int)(((RivaRasterImage*)(loc))->f_0fad20( 0))));
      }
      f_125ed0(PD(d_1c2c44), u);
    }
  }
  DTOR(ob);
}
//@ f_128c90
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeigt bei einer Untersuchung (d_1c0cd0 == 0, Bestätigung 0x27000036) das Bild 0x270001 (Index 2) mit
 *   dem Text 0x27000037 an, lässt 10 Minuten Spielzeit verstreichen, setzt einen Tagebucheintrag (0x28) und
 *   vergibt Abenteuerpunkte (0x8030028).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128c90(void)
{
  int loc;
  if (EQI(d_1c0cd0, 0)) {
    if (f_0bf6f0(PD(d_1c2c64), 0x27000036) == 1) {
      loc = f_0606a0(0x270001, 2);
      f_0bfa20(PD(d_1c2c64), loc, 0, 0x27000037, 0);
      f_125ed0(PD(d_1c2c44), 10);
      f_0bf730(PD(d_1c2c64), 0x27000038);
      d_1c0cd0 = 1;
      f_091f70(0x28);
      f_057220(PD(d_1c2c00), 0x8030028, 0);
      if (loc != 0) {
        operator delete((void *)((int)(((RivaRasterImage*)(loc))->f_0fad20( 0))));
      }
    }
  }
}
//@ f_128d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumes (d_1c0cd8 == 0) eine Meldung (0x27000039) mit dem im Talent
 *   0x1d besten Helden aus, aktiviert das Ereignis 0xcb und trägt den Tagebucheintrag 0x29 ein.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128d50(void)
{
  OB ob;
  if (EQI(d_1c0cd8, 0)) {
    CTOR(ob);
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x1d);
    f_0bf730(PD(d_1c2c64), 0x27000039);
    f_149a14(0xcb, 1);
    f_091f70(0x29);
    d_1c0cd8 = 1;
    DTOR(ob);
  }
}
//@ f_128de0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet nach einer 15-minütigen Durchsuchung (d_1c0cb8) den Beutecontainer 0x29 oder gibt eine Meldung
 *   (0x2700003b) aus, falls dieser bereits geleert wurde.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128de0(void)
{
  T *p;
  if (EQI(d_1c0cb8, 0)) {
    f_0bf730(PD(d_1c2c64), 0x2700003a);
    f_125ed0(PD(d_1c2c44), 0xf);
    d_1c0cb8 = 1;
  }
  p = new (mark(d_1a8c58, 0x4c5)) T; p = p ? p->f_112df0(0x29, 1, 0) : p;
  if (p->f_1131b0() != 0) {
    p->f_112ec0();
  } else {
    f_0bf730(PD(d_1c2c64), 0x2700003b);
  }
  if (p != 0) delete p->f_112e70(0);
}
//@ f_128e90
/* === Beschreibung (Katalog) ===
 * - Zweck: Lässt den Gruppenanführer bis zu viermal (*(unsigned short *)(p1 + 0xc) < 4) eine schädliche
 *   Berührung oder Falle (0x2700003c) auslösen, die jeweils 1W6+5 Schadenspunkte verursacht.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128e90(int p1)
{
  OB ob;
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = f_038c40(d_1c0004);
  if ((*(unsigned short *)(p1 + 0xc))++ < 4) {
    f_0bf730(PD(d_1c2c64), 0x2700003c);
    f_044850(f_038c40(d_1c0004), 1, 5);
  }
  DTOR(ob);
}
//@ f_128f10
/* === Beschreibung (Katalog) ===
 * - Zweck: Lässt den Gruppenanführer beim ersten Auslösen (d_1c0cbc == 0) eine besondere Stärkung oder
 *   Veränderung (f_040780, +5) erfahren, gibt die Meldung 0x2700003d aus und setzt den Tagebucheintrag 0x2a.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128f10(void)
{
  OB ob;
  CTOR(ob);
  if (EQI(d_1c0cbc, 0)) {
    *(int *)(ob.addresses.objects + 4) = f_038c40(d_1c0004);
    f_0bf730(PD(d_1c2c64), 0x2700003d);
    f_091f70(0x2a);
    f_040780(f_038c40(d_1c0004), 5);
    d_1c0cbc = 1;
  }
  DTOR(ob);
}
//@ f_128fa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten (d_1c0cc0 == 0) eine Warnmeldung (0x2700003e) mit dem im Talent 0x32 besten
 *   Helden aus und startet den Kampf 0x9a.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128fa0(X *p1)
{
  OB ob;
  CTOR(ob);
  if (EQI(d_1c0cc0, 0)) {
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x32);
    f_0bf730(PD(d_1c2c64), 0x2700003e);
    if (p1->vt->f(p1, 0x9a, 0) == 0) {
      d_1c0cc0 = 1;
    }
  }
  DTOR(ob);
}
//@ f_129030
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion, die prüft, ob ein handlungsfähiger Held magiebegabt ist (f_042a10 != 0), im Zauber
 *   0x1c mindestens einen Wert von -5 besitzt und über mindestens 6 Astralpunkte verfügt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held alle Voraussetzungen erfüllt, sonst 0.
 === Ende Beschreibung === */
int f_129030(int p1)
{
  int r;
  r = 0;
  if (f_0d4a60(p1) != 0) {
    if (f_042a10((struct hero *)(p1)) != 0) {
      if (f_0430f0((struct hero *)(p1), 0x1c) >= -5) {
        if (f_0429a0((struct hero *)(p1)) >= (short)6) {
          r = 1;
        }
      }
    }
  }
  return r;
}
//@ f_129080
/* === Beschreibung (Katalog) ===
 * - Zweck: Lässt den Spieler nacheinander zwei verschiedene magiebegabte Helden aus der Liste der nach f_129030
 *   geeigneten Gruppenmitglieder auswählen und speichert deren Zeiger im übergebenen 2-Elemente-Array p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf ein Array für zwei Heldenzeiger.
 * - Rückgabewert: Die Funktion gibt die Anzahl der tatsächlich ausgewählten Helden (0, 1 oder 2) zurück.
 === Ende Beschreibung === */
unsigned short f_129080(int p1)
{
  short i;
  short k;
  short cnt;
  short n;
  Int2 a = d_1a8c78;
  int b;
  int r;
  cnt = f_0398c0(d_1c0004, (int)f_129030, PD(d_1c21b4));
  n = 0;
  for (i = 0; i < 2; i++, n++, cnt--) {
    if (!(r = f_039960(d_1c0004, a.v[i], PD(d_1c21b4)))) break;
    b = 0;
    *(int *)(i * 4 + p1) = r;
    for (k = 0; k < (short)cnt; k++) {
      { int *q = d_1c21b4 + k;
        if (*q == *(int *)(i * 4 + p1)) b = 1;
      }
      if (b == 1) {
        int *q = d_1c21b4 + k;
        *q = q[1];
      }
    }
  }
  return n;
}
//@ f_1291a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert als Zustandsautomat (st == 0 bis 9) das Überwinden einer magischen Schwelle oder Barriere im
 *   Magierturm, wofür die Gruppe entweder zwei Seile (0x23), zwei gemeinsam zaubernde Magier (f_129030 /
 *   f_129080, kostet je 6 AE) oder eine Kombination aus einem Magier und einem Seil einsetzen kann, um in die
 *   nächste Etage (0x13, Position 0x1391) aufzusteigen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1291a0(void)
{
  struct L {OB ob;int q[7];char arr[28];P2 l;} v;
  int st;
  short s;
  unsigned short u;
  CTOR(v.ob);
  st = 0;
  v.l = d_1c0ce0;
  do {
    switch (st) {
    case 0: {
      switch ((unsigned short)(f_0bf820(PD(d_1c2c64), 0x2700003f, 3, 0x27000056, 0x27000040, 0x27000059) + 1)) {
      case 2:
        st = 1;
        break;
      case 3:
        st = 2;
        break;
      case 4:
        st = 6;
        break;
      case 0:
        st = 9;
        break;
      }
      break;
    }
    case 1:
      f_0bf730(PD(d_1c2c64), 0x2700005a);
      st = 9;
      break;
    case 2:
      *(int *)(v.ob.addresses.objects + 4) = f_038c40(d_1c0004);
      u = f_0bf820(PD(d_1c2c64), 0x27000042, 3, 0x27000043, 0x27000044, 0x27000045);
      if ((short)u == -1) {
        st = 0;
      } else {
        s = f_0db9a0(d_1c0004);
        if (s < 2) {
          f_0bf730(PD(d_1c2c64), 0x27000046);
          st = 9;
        } else {
          switch (u) {
          case 1:
            st = 3;
            break;
          case 2:
            st = 4;
            break;
          case 3:
            st = 5;
            break;
          }
        }
      }
      break;
    case 3:
      s = f_0de480(d_1c0004, 0x23);
      if (s < 2) {
        f_0bf730(PD(d_1c2c64), 0x27000047);
        st = 9;
      } else {
        *(int *)(v.ob.addresses.objects + 4) = f_038c40(d_1c0004);
        *(int *)(v.ob.addresses.objects + 8) = f_038cb0(d_1c0004);
        st = 8;
        f_0bf730(PD(d_1c2c64), 0x27000048);
      }
      break;
    case 4:
      s = f_0398c0(d_1c0004, (int)f_129030, PD(v.q[0]));
      if (s < 2) {
        f_0bf730(PD(d_1c2c64), 0x27000049);
        st = 9;
      } else if (s == 2) {
        *(int *)(v.ob.addresses.objects + 4) = v.q[0];
        *(int *)(v.ob.addresses.objects + 8) = v.q[1];
        st = f_0bf6f0(PD(d_1c2c64), 0x2700004a);
        if (st == 1) {
          v.l.a = v.q[0];
          st = 7;
          v.l.b = v.q[1];
        } else st=0;
      } else {
        s = f_129080(PD(v.l));
        if (s != 2) {
          st = 0;
        } else {
          st = 7;
        }
      }
      break;
    case 5:
      s = f_0398c0(d_1c0004, (int)f_129030, (int)v.arr);
      if (s == 0) {
        f_0bf730(PD(d_1c2c64), 0x2700004e);
        st = 9;
      } else {
        s = f_0d54f0(d_1c0004, 0x23);
        if (s == -1) {
          f_0bf730(PD(d_1c2c64), 0x2700004f);
          st = 9;
        } else {
          v.l.a = f_039960(d_1c0004, 0x27000050, (int)v.arr);
          if (v.l.a == 0) {
            st = 9;
          } else {
            f_0bf730(PD(d_1c2c64), 0x27000051);
            st = 8;
            f_044230(v.l.a, 6);
          }
        }
      }
      break;
    case 6:
      f_0bf730(PD(d_1c2c64), 0x27000041);
      st = 9;
      break;
    case 7:
      *(int *)(v.ob.addresses.objects + 4) = v.l.a;
      *(int *)(v.ob.addresses.objects + 8) = v.l.b;
      f_0bf730(PD(d_1c2c64), 0x2700004d);
      f_044230(v.l.a, 6);
      st = 8;
      f_044230(v.l.b, 6);
      break;
    case 8:
      st = 9;
      f_0dd7f0(d_1c0004, 0x13, 0x1391);
      break;
    case 9: break;
    }
  } while (st != 9);
  DTOR(v.ob);
}
//@ f_129500
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft den Beutecontainer 0x2a und öffnet ihn nach einer Bestätigungsabfrage (0x27000052), sofern er
 *   noch Gegenstände enthält.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129500(void)
{
  OB ob;
  T *p;
  p = new (mark(d_1a8c58, 0x70a)) T; p = p ? p->f_112df0(0x2a, 0, 0) : p;
  if (p->f_1131b0() != 0) {
    CTOR(ob);
    *(int *)(ob.addresses.objects + 4) = f_038c40(d_1c0004);
    if (f_0bf820(PD(d_1c2c64), 0x27000052, 2, 0x27000053, 0x27000054) == 1) {
      p->f_112ec0();
    }
    DTOR(ob);
  }
  if (p != 0) delete p->f_112e70(0);
}
