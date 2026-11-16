/* === Beschreibung (Katalog) ===
 * Einheit spell (0x10CAE0-0x10D6B0)
 *
 * Überblick
 * Die Einheit spell (im Original spell.cpp) bildet den zentralen Zauber-Dispatcher des Spiels: Sie berechnet
 * Astralenergiekosten (inklusive Erleichterungen und Fehlschlag-Halbierung), führt Zauberproben und
 * Immunitäts-/Gebietsprüfungen durch, ruft über die Methodenzeigertabelle d_1c042c die jeweilige Spruchwirkung
 * auf, zieht Schadenspunkte von Helden oder Monstern ab und spielt Sprachausgabe, Soundeffekte sowie die
 * Sternchen-Animation auf dem Heldenporträt ab.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 9/12 gleich (suche.py 29.10.2026, Basis spell_P1.CPP)
// E3 Entwurf 4/12 gleich
// spell.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10CAE0-0x10D6B0
#include <string.h>
int f_030810(int p1);
int f_030890(int p1);
signed char f_030960(int p1);
int f_038d70(int p1, int p2);
int f_03d4b0(int p1, int p2, int p3);
short f_03d3d0(int p1, int p2, int p3);









int f_044230(int p1, int p2);
int f_044300(int p1, int p2);
int f_045660(int p1);
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
int f_0773b0(int p1);
int f_09c800(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_0bbf00(int p1);
int f_0bba10(int p1);
int f_0bf730(int p1, int p2);
signed char f_0cf950(int p1);
int f_0cfa10(int p1);
char f_0cfdc0(int p1);
int f_0d0760(int p1);
int f_0d0960(int p1, int p2, int p3);
signed char f_0d1250(int p1);
int f_0d4730(int p1);
int f_0d49b0(int p1);
short f_0dc020(int p1, int p2);
short f_0de820(int p1);
int f_0e9300(int p1, int p2, int p3);
int f_0e93f0(int p1, int p2, int p3);





int f_133fe0(int p1, int p2);

int f_145300(int p1, int p2, int p3);
int f_145760(int p1, int p2);
short f_149360(int p1, int p2);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
struct SP { signed char b0; char x[5]; int d6; char y[4]; };
struct PM { int a; int b; int c; };
struct OA { char c[12]; OA(int,int); ~OA(); };
struct OB { char c[12]; OB(int,int); ~OB(); };
extern struct SP d_1a7274[];
extern struct PM d_1c042c[];
extern int d_1a34e0;
extern short d_1a5544[];
extern int d_1a9820;
extern short d_1a250a;
extern short d_1a280c[];
extern short d_1a7804[];
extern short d_1a77ca[];
extern short d_1a7786[];
extern short d_1a77a8[];
extern short d_1a77ea[];
extern short d_1a774c[];
extern short d_1bd90c;
extern char d_1bd918;
extern int d_1bd914;
extern short d_1bd910;
extern char d_1bfae0;
extern char d_1bf230[];
extern int d_1c0004;
struct G40C { short c; int e; int f12; char pad[5]; short s1b; char pad2[3]; };
extern G40C d_1c040c;
extern short d_1c040e;
extern int d_1c0412;
extern short d_1c041b;
struct G420 { int a; int b; unsigned short w; signed char c; };
extern G420 d_1c0420;
extern int d_1c0424;
extern signed char d_1c042a;
extern int d_1c08fc;

extern char d_1c21b4[];
extern char d_1c2be0[];
extern char d_1c2c64[];
extern char d_1c2d1c[];
extern unsigned short d_1c38b0[];
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];
void f_10d5e0(short p1, char p2);
void f_10d640(unsigned short p1);
extern char d_1c2edc[];
inline int g_1a9820() { int w = d_1a9820; d_1a9820 = w; return w; } // haelt die Registerzuteilung wie im Original
#define CALLX(t) f_147323((int)d_1c2edc, t, 0x7fff, 0x8000, d_1a9820, 0, 1)
#define I(p,o) (*(int*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))

//@ f_10cae0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet die Astralenergiekosten (AE) für den Zauberspruch p1. Liest die Grundkosten aus
 *   der Zaubertabelle d_1a7274[p1].b0, addiert einen eventuellen Spruch-Modifikator d_1c042a, halbiert die
 *   Kosten bei misslungener Zauberprobe (p2 != 0, bzw. würfelt 5..10 AE aus, falls der Spruch variable Kosten -1
 *   hat) sowie an bestimmten magischen Orten (f_0de820(d_1c0004) gleich 10 oder 11) und stellt sicher, dass
 *   mindestens 1 AE berechnet wird.
 * - Eingaben: short p1 (Zauberspruch-Index), unsigned short p2 (0 = volle Kosten bei Erfolg, != 0 = halbierte
 *   Kosten bei Fehlschlag).
 * - Rückgabewert: short (zu zahlende Astralpunkte, mindestens 1).
 * - Wichtige Variablen:
 *   - d_1a7274 (SP[]): Statische Zauberspruch-Stammdatentabelle (b0 = Grund-AE-Kosten, d6 =
 *     Soundeffekt-Datei-ID).
 *   - d_1c042a (signed char): Zusatzmodifikator auf die AE-Kosten (-1 = kein Modifikator).
 === Ende Beschreibung === */
short f_10cae0(short p1, unsigned short p2)
{
  signed char c;
  c = d_1a7274[(int)p1].b0;
  if (d_1c042a != (short)-1) c = c + d_1c042a;
  if (p2) {
    if (c == -1) c = f_145760(5, 10);
    else if (c >= 2) c = c / 2;
  }
  int s = f_0de820(d_1c0004);
  if (s == 10 || s == 11) c /= 2;
  if (c == 0) c = 1;
  // haelt die Registerzuteilung wie im Original
  {int rt906a=d_1c0412;d_1c0412=rt906a;}
  {int rt906b=d_1c0424;d_1c0424=rt906b;}
  return c;
}

//@ f_10cb70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die Heldengruppe das magische Sonder-Artefakt mit der Gegenstands-ID 0x20000155
 *   besitzt (f_038d70) und dieses im Inventar aktiv bzw. einsatzbereit ist (f_03d4b0(p, 1, 0)).
 * - Eingaben: Keine.
 * - Rückgabewert: short (0, falls der Gegenstand fehlt, sonst Rückgabewert von f_03d4b0).
 * - Wichtige Variablen: d_1c0004 (globaler Spielkontext).
 === Ende Beschreibung === */
short f_10cb70(void)
{
  int p = f_038d70(d_1c0004, 0x20000155);
  if (p) return f_03d4b0(p, 1, 0);
  return 0;
}

//@ f_10cba0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt den zaubernden Helden p2 in die Zauberkontextstruktur p1 (Offset +0x12) sowie in den
 *   globalen Zauberer-Zeiger d_1c08fc ein und initialisiert den Ergebnisstatus *(short *)p1 auf -1.
 * - Eingaben: int p1 (Zeiger auf den Zauber-Kontextblock), int p2 (Zeiger auf den zaubernden Helden).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c08fc (int): Globaler Zeiger auf den aktuell zaubernden Helden.
 === Ende Beschreibung === */
struct Q12 { short s0; char x[0x10]; int h; };
void f_10cba0(int p1, int p2)
{
  I(p1, 0x12) = p2;
  int v = *(volatile int *)(p1 + 0x12);
  *(volatile short *)(p1) = -1;
  d_1c08fc = v;
}

//@ f_10cbc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löscht den globalen Zeiger auf den aktuell zaubernden Helden (d_1c08fc = 0).
 * - Eingaben: int p1, int p2 (ungenutzt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c08fc (int).
 === Ende Beschreibung === */
void f_10cbc0(int p1, int p2)
{
  d_1c08fc = 0;
}

//@ f_10cbd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Spielt bei einem erfolgreich auf ein Gruppenmitglied (I(p1, 0x16)) gewirkten Zauber
 *   außerhalb des Kampfes die 5-stufige Glitzer-/Sternchen-Animation (0x170012) in einem 32x32-Fenster über dem
 *   entsprechenden Heldenporträt in der unteren Statusleiste (d_1a5544[idx], Y = 0x9d) ab und stellt
 *   anschließend den gesicherten Hintergrund wieder her.
 * - Eingaben: int p1 (Zeiger auf den Zauber-Kontextblock mit Zielheld I(p1, 0x16)).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a5544 (short[]): X-Koordinaten der Heldenporträts in der Statusleiste.
 *   - d_1a34e0 (int): Haupt-Bildschirmpuffer.
 === Ende Beschreibung === */
struct A5_10cbd0 { short v[5]; };
struct BLK_10cbd0 {
  A5_10cbd0 arr;
  char pad[2];
  char b[12];
  char a[12];
  int tmp;
};
void f_10cbd0(int p1)
{
  short sv, i, idx;
  BLK_10cbd0 o;
  o.arr = *(A5_10cbd0 *)(d_1a7804 + 20);
  ((int)(((RivaRasterImage*)((int)o.a))->f_0fac80( 0x20, 0x20)));
  ((int)(((RivaRasterImage*)((int)o.b))->f_0fac80( 0x20, 0x20)));
  if (((char)(f_042400((struct hero *)(I(p1, 0x16)))))) idx = 6;
  else idx = f_0dc020(d_1c0004, I(p1, 0x16));
  sv = d_1a5544[idx];
  ((RivaRasterImage*)((int)o.b))->f_0fafb0((void *)( d_1a34e0), sv, 0x9d);
  for (i = 0; i < 5; i++) {
    ((RivaRasterImage*)((int)o.b))->f_0fae30((void *)( d_1a34e0), sv, 0x9d, 0);
    f_04feb0((int)d_1c2be0, 0x170012, ((int)(((RivaRasterImage*)((int)o.a))->f_0fb0b0())), 0, o.arr.v[i], 0, (int)&o.tmp, (int)&o.tmp, 0x140);
    ((RivaRasterImage*)((int)o.a))->f_0fae30((void *)( d_1a34e0), sv, 0x9d, 1);
    f_0d4730(10);
  }
  f_0bbf00((int)d_1bf230);
  ((int)(((RivaRasterImage*)((int)o.b))->f_0fad20( 0)));
  ((int)(((RivaRasterImage*)((int)o.a))->f_0fad20( 0)));
}

//@ f_10ccf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zieht p2 Schadenspunkte durch einen Kampfzauber vom getroffenen Ziel ab. Handelt es sich
 *   beim Ziel (I(p1, 0x12)) um einen Helden (f_030960 == 2), wird der Schaden auf dessen aktuelle Lebensenergie
 *   begrenzt (f_042960), über f_044300 abgezogen, im Kampf-Log (f_09c800) protokolliert und bei Kampfunfähigkeit
 *   (f_042470) das Flag d_1bd918 = 1 gesetzt; handelt es sich um ein Monster, erfolgt dasselbe über die
 *   Monster-Funktionen f_0cfa10, f_0d0960 und f_0cfdc0.
 * - Eingaben: int p1 (Zauber-Kontextblock), short p2 (berechnete Schadenspunkte).
 * - Rückgabewert: short (tatsächlich abgezogene Schadenspunkte, gekappt auf die restlichen Lebenspunkte des
 *   Ziels).
 * - Wichtige Variablen:
 *   - d_1bd918 (char): Kampfflag, das anzeigt, dass ein Kampfteilnehmer durch den Zauber ausgeschaltet wurde.
 === Ende Beschreibung === */
short f_10ccf0(int p1, short p2)
{
  char c;
  if ((short)p2 <= 0) {
    p2 = 0;
  } else {
    if (f_030960(I(p1, 0x12)) == 2) {
      I(p1, 0x16) = f_030810(I(p1, 0x12));
      if ((short)((int)(f_042960((struct hero *)(I(p1, 0x16))))) < (short)p2) p2 = ((int)(f_042960((struct hero *)(I(p1, 0x16)))));
      f_044300(I(p1, 0x16), (short)p2);
      f_09c800((int)d_1c2d1c, 0x18, (short)p2, 2, I(p1, 0x12), 2, I(p1, 0x16));
      if (((char)(f_042470((struct hero *)(I(p1, 0x16)))))) d_1bd918 = 1;
    } else {
      I(p1, 0x1a) = f_030890(I(p1, 0x12));
      if ((short)f_0cfa10(I(p1, 0x1a)) < (short)p2) p2 = f_0cfa10(I(p1, 0x1a));
      f_0d0960(I(p1, 0x1a), (short)p2, 0);
      f_09c800((int)d_1c2d1c, 8, (short)p2, 2, I(p1, 0x12), 1, I(p1, 0x1a));
      if (f_0cfdc0(I(p1, 0x1a))) d_1bd918 = 1;
    }
  }
  return p2;
}

//@ f_10cde0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt die Magieresistenz (MR) des vom Zauber anvisierten Ziels: Bei einem Helden oder
 *   Gruppenmitglied (C(p1, 5) gleich 2 oder 5) über f_045660(I(p1, 0x16)), bei einem feindlichen Monster über
 *   f_0d1250(I(p1, 0x1a)).
 * - Eingaben: int p1 (Zauber-Kontextblock).
 * - Rückgabewert: short (Magieresistenz des Ziels).
 * - Wichtige Variablen: C(p1, 5) (Zieltyp: 2/5 = Held, sonst Monster).
 === Ende Beschreibung === */
short f_10cde0(int p1)
{
  if (C(p1, 5) == 2 || C(p1, 5) == 5) return f_045660(I(p1, 0x16));
  return f_0d1250(I(p1, 0x1a));
}

//@ f_10ce10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt die Stufe des vom Zauber anvisierten Ziels: Bei einem Helden (C(p1, 5) gleich 2
 *   oder 5) über f_0423f0(I(p1, 0x16)), bei einem Monster über f_0cf950(I(p1, 0x1a)).
 * - Eingaben: int p1 (Zauber-Kontextblock).
 * - Rückgabewert: short (Stufe des Ziels).
 * - Wichtige Variablen: I(p1, 0x16) (Zielheld), I(p1, 0x1a) (Zielmonster).
 === Ende Beschreibung === */
short f_10ce10(int p1)
{
  if (C(p1, 5) == 2 || C(p1, 5) == 5) return f_0423f0((struct hero *)(I(p1, 0x16)));
  return f_0cf950(I(p1, 0x1a));
}

//@ f_10ce40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hilfsfunktion zum Abbrechen eines Zaubers mit einer Fehlermeldung p3. Setzt das Fehlerflag
 *   d_1c040e_i = 1, trägt den zaubernden Helden I(p1, 0x12) als ersten Textplatzhalter in den Textkontext p2
 *   ein, lädt den Fehlertext p3 in den Ausgabepuffer d_1c21b4 und setzt den Rückgabewert *p4 auf -1.
 * - Eingaben: int p1 (Zauber-Kontextblock), int p2 (RivaTextContext *), int p3 (Text-ID der Fehlermeldung),
 *   short *p4 (Ergebnisvariable).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c21b4 (char[], formatierter Ausgabetext).
 === Ende Beschreibung === */
extern int d_1c040e_i;
#pragma aux d_1c040e_i "d_1c040e";
void f_10ce40(int p1, int p2, int p3, short *p4)
{
  d_1c040e_i = 1;
  *(int*)(*(int*)(p2 + 4) + 4) = I(p1, 0x12);
  f_0e93f0((int)d_1c38b0, (int)d_1c21b4, p3);
  *p4 = -1;
}

static inline short g_10cae0(short p1, unsigned short p2)
{
  signed char c;
  c = d_1a7274[(int)p1].b0;
  if (d_1c0420.c != (short)-1) c = c + d_1c0420.c;
  if (p2) {
    if (c == -1) c = f_145760(5, 10);
    else if (c >= 2) c = c / 2;
  }
  int s = f_0de820(d_1c0004);
  if (s == 10 || s == 11) c /= 2;
  if (c == 0) c = 1;
  return c;
}
static inline void g_10ce40(int p1, RivaTextContext &o, int p3, short &p4)
{
  d_1c040c.e = 1;
  o.tables.p[1] = I(p1, 0x12);
  f_0e93f0((int)d_1c38b0, (int)d_1c21b4, p3);
  p4 = -1;
}
static inline void g_10d5e0(short p1, char p2)
{
  if (d_1bfae0) {
    if (f_0773b0(d_1c0004) == 0) {
      int t;
      if (p2 == 0) t = p1 + 0xcffff;
      else t = p1 + 0xd0054;
      CALLX(t);
    }
  }
}
static inline void g_10d640(short p1)
{
  int p2;
  if (((RivaFileManager*)((int)((char*)&d_1c2098)))->f_144870( d_1a7274[p1].d6) == 0) p2 = 0x170009;
  else p2 = d_1a7274[p1].d6;
  CALLX(p2);
}

struct Host10ce80;
typedef void (Host10ce80::*Cb10ce80)();
struct Host10ce80 { char prefix[6]; Cb10ce80 callback; };
extern Cb10ce80 d_1c042c_cb[];
#pragma aux d_1c042c_cb "d_1c042c";
//@ f_10ce80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hauptfunktion zum Ausführen eines Zauberspruchs p2 mit Probenerschwernis p3. Prüft
 *   zunächst Zauberbefähigung (f_042a10), Handlungsfähigkeit (f_0d49b0), minimalen Talentwert (>= -5) und
 *   ausreichende Astralenergie (f_0429a0), bestimmt das Ziel (Held I(p1, 0x16) oder Monster I(p1, 0x1a)), fängt
 *   im jeweiligen Gebiet oder gegen bestimmte Gegner verbotene/wirkungslose Zauber über die Sperrlisten
 *   d_1a7804, d_1a7786, d_1a77a8, d_1a77ca und d_1a77ea ab, legt die Zauberprobe f_03d3d0 ab und ruft bei Erfolg
 *   den Spruch-Handler d_1c042c_cb[p2] auf. Anschließend spielt die Funktion die Sprachausgabe (f_10d5e0) und
 *   den Zauber-Soundeffekt (f_10d640) ab, zieht die vollen oder (bei Fehlschlag -2) halbierten AE-Kosten über
 *   f_044230 ab und zeigt außerhalb des Kampfes (!d_1bd90c) die Meldung sowie die Porträt-Animation f_10cbd0 an.
 * - Eingaben: int p1 (Zauber-Kontextblock), short p2 (Zauberspruch-ID), short p3 (Probenmodifikator).
 * - Rückgabewert: short (1 bei Erfolg, 0 bei harmlosem Abbruch -4, -1 bei Fehlschlag oder verbotenem Spruch).
 * - Wichtige Variablen:
 *   - d_1c042c_cb (Cb10ce80[]): Tabelle der Member-Funktionszeiger für die einzelnen Zaubersprüche.
 *   - d_1c040c (G40C): Ergebnisblock des letzten Zaubers (gespeicherte Spruch-ID, Fehlerflag, verbrauchte AE).
 *   - d_1bd90c (short): Kampfflag (0 = außerhalb des Kampfes, != 0 = im Kampf).
 === Ende Beschreibung === */
short f_10ce80(int p1, short p2, short p3)
{
  int ok = 1;
  short r;
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  short v;
  short fl = d_1bd90c;
  f_145300((int)&d_1c040c, 0, sizeof(d_1c040c));
  r = 1;
  d_1c21b4[0] = 0;
  if ((!f_042a10((struct hero *)(I(p1, 0x12))) || (!f_0d49b0(I(p1, 0x12)) && !((char)(f_0425a0((struct hero *)(I(p1, 0x12))))))) && !d_1c0420.a) {
    if (!f_042a10((struct hero *)(I(p1, 0x12)))) f_0bf730((int)d_1c2c64, 0x20000161);
    else g_10ce40(p1, o, 0x1700009f, r);
  } else if (f_0430f0((struct hero *)(I(p1, 0x12)), p2) < -5 && !d_1c0420.a) {
    g_10ce40(p1, o, 0x170000a0, r);
  } else {
    v = g_10cae0(p2, 0);
#if FIX_R041   /* R041: Zauber mit variablen AE-Kosten (v == -1) erfordern mindestens 1 AE beim Zaubernden */
    if (d_1c0420.c != -1 && (v != -1 ? v : 1) > f_0429a0((struct hero *)(I(p1, 0x12)))) {
#else
    if (d_1c0420.c != -1 && v != -1 && v > f_0429a0((struct hero *)(I(p1, 0x12)))) {
#endif
      g_10ce40(p1, o, 0x17000083, r);
    } else {
      int d;
      C(p1, 5) = ((int (*)(int))f_030960)(I(p1, 0x12)); // haelt die Registerzuteilung wie im Original
      C(p1, 4) = p3;
      S(p1, 2) = 0;
      if (C(p1, 5) == 2 || C(p1, 5) == 5) {
        I(p1, 0x16) = f_030810(I(p1, 0x12));
        I(p1, 0x1a) = 0;
      } else {
        I(p1, 0x1a) = f_030890(I(p1, 0x12));
        I(p1, 0x16) = 0;
        if (f_149360(d_1a250a, (int)d_1a280c) != -1) C(p1, 4) += 5;
      }
      if (C(p1, 5) == 5 && f_149360(p2, (int)d_1a7804) != -1) {
        switch ((unsigned short)p2) {
        case 1: f_0e93f0((int)d_1c38b0, (int)d_1c21b4, 0x17000010); break;
        case 0x22: o.tables.p[1] = I(p1, 0x12); f_0e93f0((int)d_1c38b0, (int)d_1c21b4, 0x17000024); break;
        default: f_0e93f0((int)d_1c38b0, (int)d_1c21b4, 0x1700007c); break;
        }
        S(p1, 0) = -4;
        ok = 0;
      }
      if (ok == 1 && f_149360(d_1a250a, (int)d_1a280c) != -1 && (I(p1, 0x1a) != 0 || I(p1, 0x16) == I(p1, 0x12))) {
        const short *t = 0;
        int m = 0;
        switch ((unsigned short)d_1a250a) {
        case 1: t = d_1a7786; m = 0x1700010b; break;
        case 2: t = d_1a77a8; m = 0x1700010d; break;
        case 0: t = d_1a77ca; m = 0x1700010c; break;
        }
        if (t != 0 && f_149360(p2, (int)t) != -1) {
          S(p1, 0) = -2;
          d_1c040c.c = p2;
          o.tables.p[1] = I(p1, 0x12);
          ok = 0;
          f_0e9300((int)d_1c38b0, (int)d_1c21b4, m);
        }
      }
      if (I(p1, 0x1a) != 0 && f_0d0760(I(p1, 0x1a)) != 0 && f_149360(p2, (int)d_1a77ea) != -1) {
        S(p1, 0) = -2;
        ok = 0;
        d_1c040c.c = p2;
      }
      if (ok == 1) {
        if (f_149360(p2, (int)d_1a774c) != -1 || f_03d3d0(I(p1, 0x12), p2, C(p1, 4)) > 0) {
          Host10ce80 *caster = (Host10ce80 *)p1;
          caster->callback = d_1c042c_cb[p2];
          (caster->*caster->callback)();
          d_1c040c.c = p2;
        } else {
          S(p1, 0) = -2;
        }
      }
      if (S(p1, 0) != 0 && S(p1, 0) != -4 && d_1c0420.b == 0) {
        char c = ((char)(f_042380((struct hero *)(I(p1, 0x12)))));
        f_10d5e0(p2, c);
        if (d_1a7274[p2].d6 != 0 && (d_1bd914 == 0 || d_1bd910 == 1)) f_10d640(p2);
      }
      switch (S(p1, 0)) {
      case -2: {
        d = S(p1, 2);
        if (d == 0) d = g_10cae0(p2, 1);
        f_044230(I(p1, 0x12), d);
      }
      case 0:
        r = -1;
        if (!d_1c21b4[0]) f_0e9300((int)d_1c38b0, (int)d_1c21b4, 0x17000084);
        break;
      case -4:
        d_1c040c.e = 1;
        r = 0;
        break;
      default: {
        short s;
        v = S(p1, 0);
        s = f_0de820(d_1c0004);
        if (s == 10 || s == 11) v /= 2;
        if (v == 0) v = 1;
      }
      case -1:
        if (d_1c0420.c != -1) f_044230(I(p1, 0x12), v);
        d_1c040c.f12 = 1;
        d_1c040c.s1b = v;
        break;
      }
    }
  }
  if (!fl) {
    f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, (int)d_1c21b4));
    if (r > 0 && d_1c040c.e == 0 && C(p1, 5) == 2 && f_0bba10((int)d_1bf230)) f_10cbd0(p1);
  }
  f_145300((int)&d_1c0420, 0, sizeof(d_1c0420));
  {int rt28;rt28=d_1c0004;d_1c0004=rt28;rt28=d_1a9820;d_1a9820=rt28;rt28=d_1bd914;d_1bd914=rt28;rt28=d_1c0004;d_1c0004=rt28;rt28=d_1a9820;d_1a9820=rt28;} // haelt die Registerzuteilung wie im Original
  return r;
}
//@ f_10d5e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Spielt die gesprochene Zauberformel (Sprachausgabe) zum Zauberspruch p1 ab, sofern die
 *   Sprachausgabe aktiviert ist (d_1bfae0 != 0) und der Sound nicht stummgeschaltet ist (f_0773b0 == 0).
 *   Abhängig vom Geschlecht p2 des Zaubernden wird entweder die männliche (p1 + 0x0cffff) oder die weibliche (p1
 *   + 0x0d0054) Sprachsample-ID über f_147323 abgespielt.
 * - Eingaben: short p1 (Zauberspruch-ID), char p2 (Geschlecht des Zaubernden: 0 = männlich, != 0 = weiblich).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bfae0 (char, Schalter für Zauber-Sprachausgabe).
 === Ende Beschreibung === */
void f_10d5e0(short p1, char p2)
{
  char flag = d_1bfae0;
  if (flag) {
    if (f_0773b0(d_1c0004) == 0) {
      int t, v;
      if (p2 == 0) t = p1 + 0xcffff;
      else t = p1 + 0xd0054;
      f_147323((int)d_1c2edc, t, 0x7fff, 0x8000, g_1a9820(), 0, 1);
    }
  }
}

//@ f_10d640
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Spielt das Klang-Sample (Soundeffekt) des Zauberspruchs p1 ab. Prüft über den Dateimanager
 *   d_1c2098.f_144870, ob die in d_1a7274[p1].d6 hinterlegte Sound-Ressource existiert, und spielt andernfalls
 *   den Standard-Zauberklang 0x170009 über f_147323 ab.
 * - Eingaben: unsigned short p1 (Zauberspruch-Index).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a7274[p1].d6 (int, Soundeffekt-Ressourcen-ID des Spruchs).
 === Ende Beschreibung === */
void f_10d640(unsigned short p1)
{
  int v;
  if (((RivaFileManager*)((int)((char*)&d_1c2098)))->f_144870( d_1a7274[(short)p1].d6) != 0)
    f_147323((int)d_1c2edc, d_1a7274[(short)p1].d6, 0x7fff, 0x8000, g_1a9820(), 0, 1);
  else
    f_147323((int)d_1c2edc, 0x170009, 0x7fff, 0x8000, g_1a9820(), 0, 1);
}
