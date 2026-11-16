/* === Beschreibung (Katalog) ===
 * Einheit gz_08dae0_rand910a (08dae0 - 08df20)
 *
 * Überblick
 * Die Einheit gz_08dae0_rand910a bildet den Abschluss des ersten Final-Dungeons (FINAL1): Sie verwaltet die
 * Entnahme des mehrteiligen Gegenstandsvorrat 0x182 (f_08dae0), einmalige Raumhinweise und
 * Sinnesschärfe-Beobachtungen (f_08db70, f_08dba0), die regelmäßige Raum- und Fallenprüfung (f_08dc20,
 * f_08dd20), die Auswahl des geschwächtesten Gruppenmitglieds (f_08ddc0), die Endsequenz beim Verlassen des
 * Abschnitts (f_08de20) sowie den Destruktor des Dungeon-Steuerobjekts (f_08dee0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 8/10 gleich (suche.py 24.10.2026, Basis gz_08dae0_P1.CPP)
// gz_08dae0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08DAE0-0x08E320
#include <string.h>
#define EQI(x,v) (((x)==(v))?1:0)
#define GTI(x,v) (((x)>(v))?1:0)
struct BF8 { unsigned char b0:1; };
#define B0(x) (((struct BF8 *)&(x))->b0)
struct SO { char b[4]; int *p; char c[52]; };
int f_0bf6f0(const char *o, int b);
int f_0bf730(const char *o, int b);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_039320(int p1, int p2);
int f_039a80(int p1, int p2);
int f_038c40(int p1);
int f_0390d0(int p1);

int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_0600a0(int p1);
int f_060740(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_0d4a60(int p1);
short f_0db9a0(int p1);
short f_0dcf00(int p1, int p2, int p3);
unsigned short f_0dd480(int p1);
int f_0de210(int p1);
int f_0de7c0(int p1);
int f_0de7d0(int p1, int p2);
int f_155934();
int f_145234(int p1, int p2);
int f_145254();
void f_014710(int p1);
void f_08ccc0(void);
void f_08de20(int p1);
extern char d_1baee0[];
extern int d_1bc940;
extern signed char d_1bdb03;
extern signed char d_1bdb04;
extern signed char d_1bdb20;
extern unsigned char d_1bdb24;
extern signed char d_1bdb84;
extern char d_1bfdbc[];
extern int d_1c0004;
extern int d_1c1078;
extern short d_1c212a;
extern char **d_1c212c;
extern short d_1c21a4;
extern char d_1c2c64[];
extern char d_1c349c[];
extern char d_1c3498[];
extern char d_1c3870[];
extern char d_1baf38[];
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_08dae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt der Heldengruppe nach Rückfrage (0x2900001c), so viele Exemplare des Gegenstands 0x182
 *   aufzunehmen, wie noch im Vorrat d_1bdb20 vorhanden sind (f_0dcf00), reduziert den Vorratszähler um die
 *   entnommene Anzahl s und gibt bei leerem Vorrat (d_1bdb20 <= 0) die Meldung 0x2900001d aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Wie in f_08cd20 (case 0x322) steckt hier ein Originalfehler (siehe Fehlerliste): Die
 *   Abfrage if (0 < s && d_1bdb20 == 0) für f_060740(0x1f41, 1) steht vor der Subtraktion d_1bdb20 -= s und kann
 *   deshalb niemals wahr werden.
 === Ende Beschreibung === */
void f_08dae0(void)
{
  short s;
  if (GTI(d_1bdb20, 0)) {
    int t_58 = f_0bf6f0(d_1c2c64, 0x2900001c);
    if (t_58 == 1) {
      signed char amount = d_1bdb20;
      s = f_0dcf00(d_1c0004, 0x182, amount);
#if FIX_R071   /* R071: Vorratszaehler d_1bdb20 vor der Nullpruefung dekrementieren, damit Flag 0x1f41 gesetzt wird */
      d_1bdb20 -= (signed char)s;
      if (0 < s && EQI(d_1bdb20, 0)) f_060740(0x1f41, 1);
#else
      if (0 < s && EQI(d_1bdb20, 0)) f_060740(0x1f41, 1);
      d_1bdb20 -= (signed char)s;
#endif
    }
  } else f_0bf730(d_1c2c64, 0x2900001d);
}
//@ f_08db70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Auslösen (d_1bdb03 == 0) die Hinweismeldung 0x29000017 an und setzt das Flag
 *   d_1bdb03 = 1.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb03 verhindert ein wiederholtes Einblenden derselben Meldung.
 === Ende Beschreibung === */
void f_08db70(void)
{
  if (d_1bdb03 == 0) {
d_1bdb03 = 1;
    f_0bf730(d_1c2c64, 0x29000017);
  }
}
//@ f_08dba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten ((d_1bdb24 & 1) == 0) die Entdeckungsmeldung 0x2900001e sowie eine
 *   Anschlussmeldung 0x2900001f mit dem Helden aus, der den höchsten Wert im Talent 0x25 (*Sinnesschärfe*,
 *   f_039320) besitzt, und setzt Bit 0 in d_1bdb24.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Bitfeld d_1bdb24 speichert mehrere einmalige Beobachtungsflags des Final-Abschnitts.
 === Ende Beschreibung === */
void f_08dba0(void)
{
  unsigned char c = d_1bdb24;
  c &= 1;
  if ((c ? 1 : 0) == 0) {
    SO o;
    B0(d_1bdb24) = 1;
    f_0bf730(d_1c2c64, 0x2900001e);
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = f_039320(d_1c0004, 0x25);
    f_0bf730(d_1c2c64, 0x2900001f);
    f_1254a0(&o, 0);
  }
}
//@ f_08dc20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im laufenden Schrittzyklus des ersten Final-Dungeons, ob eine Endsequenz (d_1c1078 != 0)
 *   ansteht oder ob die Gruppe das Fallenfeld 0x139c zum ersten Mal (d_1bdb04 == 0) betritt, löst dort eine
 *   Decken-/Raumfalle (0x290002, 2..5 SP Schaden an allen Helden über f_08ccc0) samt Wartezeit (f_155934) aus
 *   und ruft anschließend die Basismethode f_0600a0 auf.
 * - Eingaben und Rückgabe: Die Methode erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb04 stellt sicher, dass die Einsturzfalle auf Feld 0x139c nur einmal
 *   ausgelöst wird.
 === Ende Beschreibung === */
void f_08dc20(int p1)
{
  if (d_1c1078 != 0) {
    f_08de20(d_1c1078);
    d_1c1078 = 0;
  }
  if (EQI(d_1bdb04, 0)) {
    if (f_0dd480(d_1c0004) == 0x139c) {
      SO o;
      int a, b;
      f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
      a = f_038c40(d_1c0004);
      b = f_0390d0(d_1c0004);
      f_060800(0x290002, 0, 0);
      o.p[1] = a;
      f_0bf730(d_1c2c64, 0x29000005);
      f_039a80(d_1c0004, (int)f_08ccc0);
      if (b != 0) {
        o.p[1] = b;
        f_0bf730(d_1c2c64, 0x29000006);
      }
      f_1254a0(&o, 0);
      f_155934();
      d_1bdb04 = 1;
    }
  }
  f_0600a0(p1);
}
//@ f_08dd20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Einsturz- oder Raumfalle (0x290002, Meldungen 0x29000005 und 0x29000006) für den
 *   Gruppenanführer (a) und einen zweiten Helden (b) aus und fügt allen lebenden Gruppenmitgliedern über
 *   f_08ccc0 jeweils 2..5 Schadenspunkte zu.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_038c40 und f_0390d0 werden der Anführer und ein zufälliger weiterer Held für die
 *   Meldungstexte bestimmt.
 === Ende Beschreibung === */
void f_08dd20(void)
{
  SO o;
  int a, b;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  a = f_038c40(d_1c0004);
  b = f_0390d0(d_1c0004);
  f_060800(0x290002, 0, 0);
  o.p[1] = a;
  f_0bf730(d_1c2c64, 0x29000005);
  f_039a80(d_1c0004, (int)f_08ccc0);
  if (b != 0) {
    o.p[1] = b;
    f_0bf730(d_1c2c64, 0x29000006);
  }
  f_1254a0(&o, 0);
}
//@ f_08ddc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle sieben Plätze der Heldengruppe (0..6) nach dem lebenden und anwesenden Helden
 *   mit den aktuell wenigsten Lebenspunkten (f_042960) und gibt dessen Zeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den Zeiger auf den am stärksten
 *   verwundeten Helden (oder 0) zurück.
 * - Wichtige Variablen: Bei Gleichstand der Lebenspunkte behält der weiter vorn stehende Held den Vorrang (if (a
 *   > b) continue;).
 === Ende Beschreibung === */
int f_08ddc0(void)
{
  int best = 0;
  short i;
  for (i = 0; i < 7; i++) {
    int p = f_0de7d0(d_1c0004, i);
    if (p != 0) {
      if (f_0d4a60(p) != 0) {
        if (best != 0) {
          short a = f_042960((struct hero *)(p));
          short b = f_042960((struct hero *)(best));
          if (a > b) continue;
        }
        best = p;
      }
    }
  }
  return best;
}
//@ f_08de20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wickelt das Finale bzw. das Verlassen des Abschnitts mit dem aktiven Helden p1 ab: Wurde das
 *   Hauptziel erreicht (d_1bdb84 == 1), erscheint die Siegesmeldung 0x29000001 und der Endstatus d_1c21a4 = 1;
 *   andernfalls erscheint 0x29000002, alle aktiven Untergruppen (d_1bfdbc) werden aufgeräumt und der Status
 *   d_1c21a4 = 8 gesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb84 entscheidet über Erfolg oder Scheitern im letzten Spielabschnitt, und
 *   d_1c21a4 steuert die nachfolgende Abspannsequenz.
 === Ende Beschreibung === */
void f_08de20(int p1)
{
  SO o;
  short i;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  o.p[1] = p1;
  d_1bc940 = 1;
  if (EQB(d_1bdb84, 1)) {
    f_0bf730(d_1c2c64, 0x29000001);
    d_1c21a4 = 1;
  } else {
    f_0bf730(d_1c2c64, 0x29000002);
    for (i = 0; i < 6; i++) {
      char *q = d_1bfdbc + i * 0x61;
      if (f_0de7c0((int)q) != 0) {
        if (f_0db9a0((int)q) > 0) f_0de210((int)q);
      }
    }
    d_1c21a4 = 8;
  }
  f_1254a0(&o, 0);
}
//@ f_08dee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut als virtueller Destruktor das Dungeon-Steuerobjekt (p1) des ersten Final-Abschnitts über
 *   die Basisklasse f_060030 ab und gibt bei gesetztem Bit 2 in p2 den Objektspeicher über f_014710 frei.
 * - Eingaben und Rückgabe: Der Destruktor nimmt den Objektzeiger p1 sowie die Abbau-Flags p2 entgegen und gibt
 *   p1 zurück.
 * - Wichtige Variablen: Bei gesetztem Ausnahmebit p2 & 4 wird die Watcom-Ausnahmebehandlung (f_145234/f_145254)
 *   aufgerufen.
 === Ende Beschreibung === */
int f_08dee0(int p1, unsigned p2)
{
  if (p2 & 4) {
    f_145234(p1, (int)d_1baee0);
    f_145254();
    return p1;
  }
  p1 = f_060030(p1, 1);
  if (p2 & 2) f_014710(p1);
  return p1;
}
#define REG(a,b,v) a = 0; b = v; d_1c212c[d_1c212a++] = (char *)&a;
extern char d_1bdb30; extern short d_1bdb31;
extern char d_1bdb34; extern short d_1bdb35;
extern char d_1bdb38; extern short d_1bdb39;
extern char d_1bdb3c; extern short d_1bdb3d;
extern char d_1bdb40; extern short d_1bdb41;
extern char d_1bdb44; extern short d_1bdb45;
extern char d_1bdb48; extern short d_1bdb49;
extern char d_1bdb4c; extern short d_1bdb4d;
extern char d_1bdb50; extern short d_1bdb51;
extern char d_1bdb54; extern short d_1bdb55;
extern char d_1bdb58; extern short d_1bdb59;
extern char d_1bdb5c; extern short d_1bdb5d;
extern char d_1bdb60; extern short d_1bdb61;
extern char d_1bdb64; extern short d_1bdb65;
extern char d_1bdb68; extern short d_1bdb69;
extern char d_1bdb6c; extern short d_1bdb6d;
extern char d_1bdb70; extern short d_1bdb71;
extern char d_1bdb74; extern short d_1bdb75;
extern char d_1bdb78; extern short d_1bdb79;
extern char d_1bdb7c; extern short d_1bdb7d;
extern char d_1bdb80; extern short d_1bdb81;
extern short d_1bdb85;
struct Obj08;
struct Reg08 { short count; Obj08 **list; void append(Obj08 *o) { list[count]=o;count++; } };
struct Obj08 { signed char a; short b; Obj08 *init(Reg08 &r,short id,signed char f) { a=f;b=id;r.append(this);return this; } };

extern Reg08 reg08;
#pragma aux reg08 "d_1c212a"
extern Obj08 o08_1bdb30;
#pragma aux o08_1bdb30 "d_1bdb30"
extern Obj08 o08_1bdb34;
#pragma aux o08_1bdb34 "d_1bdb34"
extern Obj08 o08_1bdb38;
#pragma aux o08_1bdb38 "d_1bdb38"
extern Obj08 o08_1bdb3c;
#pragma aux o08_1bdb3c "d_1bdb3c"
extern Obj08 o08_1bdb40;
#pragma aux o08_1bdb40 "d_1bdb40"
extern Obj08 o08_1bdb44;
#pragma aux o08_1bdb44 "d_1bdb44"
extern Obj08 o08_1bdb48;
#pragma aux o08_1bdb48 "d_1bdb48"
extern Obj08 o08_1bdb4c;
#pragma aux o08_1bdb4c "d_1bdb4c"
extern Obj08 o08_1bdb50;
#pragma aux o08_1bdb50 "d_1bdb50"
extern Obj08 o08_1bdb54;
#pragma aux o08_1bdb54 "d_1bdb54"
extern Obj08 o08_1bdb58;
#pragma aux o08_1bdb58 "d_1bdb58"
extern Obj08 o08_1bdb5c;
#pragma aux o08_1bdb5c "d_1bdb5c"
extern Obj08 o08_1bdb60;
#pragma aux o08_1bdb60 "d_1bdb60"
extern Obj08 o08_1bdb64;
#pragma aux o08_1bdb64 "d_1bdb64"
extern Obj08 o08_1bdb68;
#pragma aux o08_1bdb68 "d_1bdb68"
extern Obj08 o08_1bdb6c;
#pragma aux o08_1bdb6c "d_1bdb6c"
extern Obj08 o08_1bdb70;
#pragma aux o08_1bdb70 "d_1bdb70"
extern Obj08 o08_1bdb74;
#pragma aux o08_1bdb74 "d_1bdb74"
extern Obj08 o08_1bdb78;
#pragma aux o08_1bdb78 "d_1bdb78"
extern Obj08 o08_1bdb7c;
#pragma aux o08_1bdb7c "d_1bdb7c"
extern Obj08 o08_1bdb80;
#pragma aux o08_1bdb80 "d_1bdb80"
extern Obj08 o08_1bdb84;
#pragma aux o08_1bdb84 "d_1bdb84"
inline signed char zero08() { signed char c=0; return c; }
inline void add08(Obj08 &o, Reg08 &r, short id) { o.a=0; o.b=id; r.list[r.count]=&o; r.count++; }
//@ f_08df20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert beim Programmstart 22 persistente Zustands- und Ereignisvariablen (d_1bdb30 bis
 *   d_1bdb84 mit den Kennungen 0xd1..0xe0, 0xfa, 0x186, 0x224..0x226, 0x25e) im globalen Spielstands-Register
 *   d_1c212a.
 * - Eingaben und Rückgabe: Die Initialisierungsfunktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Alle 22 Statusbytes werden beim Anlegen auf den Startwert 0 gesetzt.
 === Ende Beschreibung === */
void f_08df20(void) ;

//@ f_08e300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert das Dungeon-Steuerobjekt (X08e300) für den zweiten Final-Dungeon mit der
 *   Kartenkennung 11 (f_05ff60) und trägt dessen virtuelle Methodentabelle d_1baf38 ein.
 * - Eingaben und Rückgabe: Der Konstruktor erhält den this-Zeiger der Instanz und gibt diesen zurück.
 * - Wichtige Variablen: Die Basisklasse B05ff60 initialisiert die Grundfelder des Dungeon-Handlers.
 === Ende Beschreibung === */
void f_08e300(int p1)
;
