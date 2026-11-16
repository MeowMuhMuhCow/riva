/* === Beschreibung (Katalog) ===
 * Einheit tower3_t3 (0x131490 - 0x131A70)
 *
 * Überblick
 * Diese Einheit bildet den dritten und letzten Teil von tower3.cpp für die dritte Ebene des Magierturms. Sie
 * enthält die Zauberprüfung zum Entschärfen der magisch gesicherten Bücherregale, die Schadens- und
 * Rückwurfroutine der Gangfallen, die Schalter- und Wandinteraktionen zum Abschalten der drei Statuenfallen
 * sowie eine Hilfsfunktion, die bestimmte im Turm erbeutete Gegenstände im Heldeninventar in Edelsteine
 * verwandelt.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 6/7 gleich (suche.py 25.10.2026, Basis tower3_t3_P1.CPP)
// tower3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12EDF0-0x131A70
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_032670(int p1, int p2);                           // reg eax edx stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0390a0(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
short f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041030(int, int);
#pragma aux f_041030 parm caller [];
int f_041920(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
short f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0602d0(int p1, int p2);                           // reg edx stapel 0
int f_0602f0(int p1, int p2);           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
short f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_131a70(int p1);                                   // reg eax stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
short f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
short f_149360(int, int);
int f_1497d8(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a8d2a;                    // 0x1A8D2A
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern short d_1c0428;
extern int d_1c08fc;                    // 0x1C08FC
extern signed char d_1c0908;
extern signed char d_1c0d50;
extern signed char d_1c0d54;
extern signed char d_1c0d58;
extern signed char d_1c0d5c;
extern signed char d_1c0d60;
extern signed char d_1c0d64;
extern signed char d_1c0d68;
extern int d_1c0d6c;                    // 0x1C0D6C
extern int d_1c0d70;                    // 0x1C0D70
extern int d_1c0d74;                    // 0x1C0D74
extern signed char d_1c0d78;
extern signed char d_1c0d7c;
extern signed char d_1c0d80;
extern signed char d_1c0d84;
extern int d_1c0d88;                    // 0x1C0D88
extern signed char d_1c0d8c;
extern signed char d_1c0d90;
extern signed char d_1c0d94;
extern int d_1c0e80;                    // 0x1C0E80
extern int d_1c24d4;                    // 0x1C24D4
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a8d0c[];           // Text 0x1A8D0C

extern char d_1c349c[], d_1c3870[], d_1c3498[];
int f_0bde40(int);
int f_0bfa20(int, ...);
int f_0bf680(int);
struct T14 { char b[0x14]; };
#define EQI(x,v) (((x)==(v))?1:0)
#define CH ((int)&d_1c2c64)
#define US(k) (k)
#define VFO(T,p,o) ((T)(*(int *)(*(int *)((p)+8)+(o))))
#define HZ(x) EQI(x, 0)

//@ f_131490
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lässt den Spieler einen Zauberkundigen auswählen (0x2700010d), um den Schutzzauber auf einem
 *   der Bücherregale mit einem Zauber (Zauberindex 5, Kosten 5 Astralpunkte bei Erfolg bzw. 3 Astralpunkte bei
 *   Fehlschlag) zu brechen.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt bei gelungener Zauberprobe den Zeiger auf den erfolgreichen Zauberkundigen (r) zurück,
 *   andernfalls 0.
 * - Wichtige Variablen: p1 ist der gewählte Zauberkundige; geprüft wird zunächst, ob seine aktuelle
 *   Astralenergie (f_0429a0) mindestens 5 beträgt, bevor die Zauberprobe (f_03d3d0) gewürfelt wird.
 === Ende Beschreibung === */
int f_131490(void)
{
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  int r;
  int p1;
  int msg;
  r = 0;
  p1 = f_038e10(d_1c0004, 0x2700010d);
  if (p1 != 0) {
    *(int *)(o.slots[0] + 4) = p1;
    if (f_0429a0((struct hero *)(p1)) >= (short)5) {
      if (f_03d3d0(p1, 5, 0) > 0) {
        f_044230(p1, 5);
        r = p1;
        goto L1;
      }
      f_044230(p1, 3);
      msg = 0x2700010e;
    } else {
      msg = 0x2700010f;
    }
    f_0bf730(CH, msg);
  }
L1:
  return r;
}

//@ f_131530
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Regelt den Zugang zu den vier verzauberten Bücherregalen in der Bibliothek: Beim allerersten
 *   Untersuchungsversuch (d_1c0d50 == 0) spürt ein Held die magische Aura (0x2700010b), und falls ein Magier in
 *   der Gruppe ist, kann dieser sofort versuchen, den Schutzzauber über f_131490 aufzuheben (0x2700010c). Bei
 *   allen weiteren Versuchen (d_1c0d50 != 0) wird direkt gefragt, ob ein Magier den Zauber brechen soll
 *   (0x27000110), oder falls kein Zauberkundiger anwesend und das Regal noch nicht leer ist (p2 == 0), die
 *   Hinweismeldung 0x27000111 ausgegeben.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1) sowie ein Flag (p2), das angibt, ob das jeweilige
 *   Bücherregal bereits vollständig durchsucht wurde.
 * - Rückgabewert: Gibt den Zeiger auf den untersuchenden Magier (r) zurück, wenn der Schutzzauber überwunden
 *   wurde, sonst 0.
 * - Wichtige Variablen: Das globale Flag d_1c0d50 merkt sich, ob die Gruppe die Schutzmagie der Bücherregale
 *   bereits beim ersten Mal bemerkt hat.
 === Ende Beschreibung === */
int f_131530(int p1, int p2)
{
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  int r;
  r = 0;
  if (EQI(d_1c0d50, 0)) {
    d_1c0d50 = 1;
    *(int *)(o.slots[0] + 4) = f_039660(d_1c0004, 0xc);
    f_0bf730(CH, 0x2700010b);
    int b1 = f_0390a0(d_1c0004) != 0;
    if (b1 == 1) {
      *(int *)(o.slots[0] + 4) = f_039320(d_1c0004, 0x27);
      if (f_0bf6f0(CH, 0x2700010c) == 1) {
        r = ((int (*)(int))f_131490)(p1);
      }
    }
  } else {
    int b2 = f_0390a0(d_1c0004) != 0;
    if (b2 == 1) {
      if (f_0bf6f0(CH, 0x27000110) == 1) {
        r = ((int (*)(int))f_131490)(p1);
        *(int *)(o.slots[0] + 4) = r;
      }
    } else if (p2 == 0) {
      f_0bf730(CH, 0x27000111);
    }
  }
  return r;
}

//@ f_131650
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wendet die Auswirkungen einer ausgelösten Gangfalle auf den getroffenen Helden (p2) an: Vom
 *   ausgewürfelten Schaden (p3) wird der Rüstungsschutz (f_0423c0) abgezogen (jedoch mindestens p4
 *   Schadenspunkte angerichtet), der Held wird in eine eigene eingliedrige Teilgruppe (t) abgespalten und auf
 *   die darunterliegende Turmebene (0x12, Position 0x146b) geschleudert; überlebt er den Sturz und ist das
 *   Zusatzflag p5 == 1 gesetzt, erleidet er zusätzlich einen Attributsverlust auf Gewandtheit oder Körperkraft
 *   (f_0453e0).
 * - Eingaben: Ein ungenutzter Ebenen-Zeiger (p1), der getroffene Held (p2), der Rohschaden (p3), der
 *   Mindestschaden (p4) sowie ein Flag für zusätzliche Verletzungsfolgen (p5).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: sv enthält den nach Abzug des Rüstungsschutzes (c) verbleibenden Schaden; t ist die für
 *   den abgestürzten Helden erzeugte Gruppe (f_041030), die bei dessen Tod über f_041920 aufgelöst wird.
 === Ende Beschreibung === */
void f_131650(int p1, int p2, int p3, int p4, int p5)
{
  signed char c;
  short sv;
  int t;
  c = f_0423c0((struct hero *)(p2));
  sv = (short)p3 - c;
  if (sv < (short)p4) {
    sv = (short)p4;
  }
  t = f_041030(1, p2);
  f_044300(p2, sv);
  f_0dd7f0(t, 0x12, 0x146b);
  c = ((signed char)(f_042470((struct hero *)(p2))));
  if (c == 0) {
    c = ((signed char)(f_0425f0((struct hero *)(p2))));
    if (c == 0) {
      f_041920(t);
    }
    if (p5 == 1) {
      c = ((signed char)(f_0425f0((struct hero *)(p2))));
      if (c == 1) {
        f_043e20(p2, 1);
      }
      f_0453e0(p2, 8, 1);
      f_043e20(p2, 0);
    }
  }
}

//@ f_1316f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt für die dritte Turmebene, ob sich vor der Gruppe an ihrer aktuellen Position und
 *   Blickrichtung einer der drei versteckten Fallenschalter (lc = 1, 2, 3) befindet, und gibt bei
 *   einerInteraktion (p2 == 4) die zugehörige Aktionskennung (100, 101 oder 102) zurück, sofern die betreffende
 *   Falle (d_1c0d7c, d_1c0d80, d_1c0d84) noch nicht deaktiviert wurde.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1) sowie der Interaktionstyp (p2).
 * - Rückgabewert: Gibt die Aktionskennung des Schalters (100-102) oder den Standardwert der Basisklasse
 *   (f_0602d0) zurück.
 * - Wichtige Variablen: Die lokale Kennung lc wird über die Koordinatenprüfung f_1497d8 anhand der
 *   Gruppenposition (p2b) und Blickrichtung (p3) bestimmt.
 === Ende Beschreibung === */
short f_1316f0(int p1, short p2)
{
  short r;
  short lc;
  int p3;
  int p2b;
  r = 0;
  if (p2 == 4) {
    lc = 0;
    p3 = f_0de880(d_1c0004);
    p2b = f_0de840(d_1c0004);
    if (f_1497d8((int)&lc, p2b, p3) == 0) {
      switch (lc) {
      case 1:
        if (HZ(d_1c0d7c)) r = 100;
        break;
      case 2:
        if (HZ(d_1c0d80)) r = 0x65;
        break;
      case 3:
        if (HZ(d_1c0d84)) r = 0x66;
        break;
      }
    }
  }
  if (r == 0) {
    r = f_0602d0(p1, p2);
  }
  return r;
}

//@ f_1317c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt das Umlegen eines der drei Fallenschalter (Aktionskennungen 100, 101 und 102) aus:
 *   Beim allerersten abgeschalteten Mechanismus (d_1c0d78 == 0) wird ein allgemeines Ereignisflag (0x14) im
 *   Spielstatus gesetzt, danach erscheint die Meldung 0x270000ed, das jeweilige Fallen-Statusflag (d_1c0d7c,
 *   d_1c0d80 bzw. d_1c0d84) wird auf 1 gesetzt und sowohl das Schalterobjekt (0x1f46-0x1f48) als auch das
 *   zugehörige Fallenobjekt (0x1f4b-0x1f4d) werden in der 3D-Szene umgeschaltet.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1) sowie der Interaktionsparameter (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn ein Schalter betätigt wurde, oder leitet den Aufruf an die Basismethode
 *   f_0602f0 weiter.
 * - Wichtige Variablen: a und b enthalten die 3D-Objektkennungen des jeweiligen Schalter- und Statuenpaares;
 *   d_1c0d78 merkt sich, ob bereits mindestens einer der drei Schalter betätigt wurde.
 === Ende Beschreibung === */
int f_1317c0(int p1, int p2)
{
  int r;
  unsigned short a;
  unsigned short b;
  switch (VFO(unsigned short (*)(int,int), p1, 0x28)(p1, (short)p2)) {
  case 100:
    a = 0x1f46;
    b = 0x1f4d;
    r = 0;
    if (HZ(d_1c0d7c)) {
      if (EQI(d_1c0d78, 0)) {
        d_1c0d78 = 1;
        f_040780(d_1c08fc, 0x14);
      }
      f_0bf730(CH, 0x270000ed);
      d_1c0d7c = 1;
      f_060740(a, 0);
      f_060740(b, 0);
      r = 1;
    }
    return r;
  case 101:
    a = 0x1f47;
    b = 0x1f4b;
    r = 0;
    if (HZ(d_1c0d80)) {
      if (EQI(d_1c0d78, 0)) {
        d_1c0d78 = 1;
        f_040780(d_1c08fc, 0x14);
      }
      f_0bf730(CH, 0x270000ed);
      d_1c0d80 = 1;
      f_060740(a, 0);
      f_060740(b, 0);
      r = 1;
    }
    return r;
  case 102:
    b = 0x1f48;
    a = 0x1f4c;
    r = 0;
    if (HZ(d_1c0d84)) {
      if (EQI(d_1c0d78, 0)) {
        d_1c0d78 = 1;
        f_040780(d_1c08fc, 0x14);
      }
      f_0bf730(CH, 0x270000ed);
      d_1c0d84 = 1;
      f_060740(b, 0);
      f_060740(a, 0);
      r = 1;
    }
    return r;
  default:
    return f_0602f0(p1, (short)p2);
  }
}

//@ f_1319a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kapselt als eigenständige Hilfsfunktion exakt die Schalterlogik zum Deaktivieren einer der
 *   drei Gangfallen (Setzen von d_1c0d78, Ausgeben von 0x270000ed, Setzen des Fallenflags *p2 = 1 und Umschalten
 *   der beiden 3D-Objekte p3 und p4), wurde vom Compiler jedoch direkt in die drei switch-Zweige von f_1317c0
 *   eingebettet.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1), ein Zeiger auf das Statusflag der Falle (p2) sowie die
 *   beiden 3D-Objektkennungen (p3, p4).
 * - Rückgabewert: Gibt 1 zurück, wenn die Falle zuvor noch aktiv war (*p2 == 0), andernfalls 0.
 * - Wichtige Variablen: *p2 ist das Statusflag der jeweiligen Falle, d_1c0d78 das einmalige Erstbetätigungsflag.
 === Ende Beschreibung === */
int f_1319a0(int p1, signed char *p2, unsigned short p3, unsigned short p4)
{
  int r;
  r = 0;
  if (EQI(*p2, 0)) {
    if (EQI(d_1c0d78, 0)) {
      d_1c0d78 = 1;
      f_040780(d_1c08fc, 0x14);
    }
    f_0bf730(CH, 0x270000ed);
    *p2 = 1;
    f_060740(p3, 0);
    f_060740(p4, 0);
    r = 1;
  }
  return r;
}

//@ f_131a10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchsucht alle 31 Inventarplätze (0 bis 30) eines Helden (p1) nach bestimmten aus dem
 *   Magierturm stammenden Gegenständen (Liste d_1a8d2a), zerstört jeden gefundenen Treffer (f_035180) und legt
 *   stattdessen Edelsteine (0xfa) in das Inventar des Helden.
 * - Eingaben: Ein Zeiger auf den zu prüfenden Helden (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn mindestens ein Gegenstand bei diesem Helden umgewandelt wurde, sonst 0.
 * - Wichtige Variablen: Die Schleifenvariable i (j) läuft über alle Inventarslots; s nimmt die
 *   Gegenstandskennung im jeweiligen Slot sowie das Suchergebnis in der Liste d_1a8d2a (f_149360) auf.
 === Ende Beschreibung === */
int f_131a10(int p1)
{
  int r;
  short i;
  int j;
  short s;
  r = 0;
  for (i = 0; i < 0x1f; i = i + 1) {
    j = i;
    s = ((int)(f_042a60((struct hero *)(p1), j)));
    if (s > 0) {
      s = f_149360(s, (int)&d_1a8d2a);
      if (s != -1) {
        f_035180(p1, j);
        f_0366e0(p1, 0xfa, 0, 1);
        r = 1;
      }
    }
  }
  return r;
}
