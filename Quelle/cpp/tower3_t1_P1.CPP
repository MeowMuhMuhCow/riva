/* === Beschreibung (Katalog) ===
 * Einheit tower3_t1 (0x12EDF0 - 0x130040)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des Moduls tower3.cpp und implementiert die Ereignis- und Raumlogik für
 * die dritte Ebene des Magierturms (unter anderem die magische Bibliothek, den Schreibtisch mit den Briefen über
 * Tariks Experimente, die mit einem Lösungswort gesicherte Tür, die vier verzauberten Bücherregale sowie die
 * drei gefährlichen Lichtschranken- bzw. Statuenfallen).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 15/23 gleich (suche.py 24.10.2026, Basis tower3_t1_P1.CPP)
// tower3_t1 (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12EDF0-0x130040
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032670(int p1, int p2);                           // reg eax edx stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0366e0(int,int,int,int);           // reg eax edx ebx ecx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0390a0(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
short f_0398c0(int,int,int);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041030();                                         // reg - stapel 0
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
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0602d0(int p1, int p2);                           // reg edx stapel 0
int f_0602f0(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int,int);           // reg eax stapel 0
int f_0607e0(int,int);                           // reg eax edx stapel 0
int f_060800(int,int,int);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0dcf00(int,int,int);                   // reg eax edx ebx stapel 0
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
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_131a70(int p1);                                   // reg eax stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
int f_1497d8(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a8d2a;                    // 0x1A8D2A
extern short d_1a9820;                    // 0x1A9820
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0428;                    // 0x1C0428
extern int d_1c08fc;                    // 0x1C08FC
extern int d_1c0d50;                    // 0x1C0D50
extern int d_1c0d54;                    // 0x1C0D54
extern int d_1c0d58;                    // 0x1C0D58
extern int d_1c0d5c;                    // 0x1C0D5C
extern int d_1c0d60;                    // 0x1C0D60
extern int d_1c0d64;                    // 0x1C0D64
extern int d_1c0d78;                    // 0x1C0D78
extern int d_1c0d8c;                    // 0x1C0D8C
extern int d_1c0d94;                    // 0x1C0D94
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a8d0c[];           // Text 0x1A8D0C
int f_144bf0(const char *, const char *);
typedef signed char FL;
#define EQI(x,v) (((x)==(v))?1:0)
#define EQZ(x) EQI(x, 0)
extern int d_1c0d90; // als int deklariert, haelt die Registerfolge in f_12edf0 wie im Original
extern FL d_1c0d68, d_1c0d6c, d_1c0d70, d_1c0d74, d_1c0d7c, d_1c0d80, d_1c0d84, d_1c0d88, d_1c0908, d_1c0e80;
extern char d_1c299c[];
extern int d_1c24d4[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern int d_1c0428;
struct T12 { int a[3]; };
struct T20 { int a[5]; };
void f_130fd0(int, int, FL *);
void f_130240(int);
void f_1304c0(int);
void f_1307b0(int);
void f_130040(int);
void f_1309f0(int);
void f_10fc50(void);
void f_12ff60(void);
void f_12fa20(int);
void f_12fae0(void);
void f_12fbe0(void);
void f_12fd30(void);
#define CH ((int)&d_1c2c64)
#define CH2 ((int)&d_1c2edc)
#define VC2(p,a) ((int(*)(int,int))(**(int**)((p)+8)))((p),(a))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_12edf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese zentrale Ereignis-Verteilerfunktion der dritten Turmebene wertet die übergebene
 *   Ereignis- oder Objektkennung aus und verzweigt zu den jeweiligen Reaktionen für Treppen, Statuenfallen,
 *   Bücherregale, Schreibtische, Beutelager, Truhen und Türen. Zudem enthält sie eine eingebettete Hilfsroutine
 *   (g_130c80), die beim Betreten eines bestimmten magischen Feldes prüft, ob ein Zauberkundiger in der Gruppe
 *   ist, und diesem das Sprechen eines Zaubers anbietet.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1) sowie die 16-Bit-Ereignis- oder Objektkennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn die Kennung erkannt und verarbeitet wurde, andernfalls 0.
 * - Wichtige Variablen: Mehrere lokale Textkontext-Strukturen (frame) dienen zum Einsetzen von Heldennamen
 *   (Gruppenanführer oder Held mit dem niedrigsten Attributswert) in die jeweiligen Meldungstexte; verschiedene
 *   globale Statusflags (d_1c0d68, d_1c0d7c, d_1c0d80, d_1c0d84, d_1c0d88, d_1c0d90, d_1c0908) speichern den
 *   Fortschritt der Rätsel und Fallen auf dieser Ebene.
 === Ende Beschreibung === */
static inline int IS12(const signed char &x, signed char v) { return x == v; }
static inline int IS12c(const signed char &x, signed char v) { return v == x; }
static inline void g_130c80(void)
{
  int r;
  if (IS12(d_1c0908, 0)) {
    f_0bf730(CH, 0x27000130);
    if (f_0390a0(d_1c0004) != 0) {
      if (f_0bf6f0(CH, 0x27000131) == 1) {
        r = f_038e10(d_1c0004, 0x20000155);
        if (r != 0) {
          *(short *)&d_1c0428 = 2;
          f_03d4b0(r, 1, 0);
          return;
        }
      }
    }
  } else {
    f_0bf730(CH, 0x27000132);
  }
}
int f_12edf0(int p1, unsigned short p2)
{
  int iVar2;
  int iVar3 = 0;
  int t = 0, saved = 0;
  int r = 1;
  struct Raw { int a; int *p; char c[52]; };
  int f_1254a0(int, int);
  struct Frame { Raw o68, o6a, o1f9, o66; } frame;
  struct E { static int eq(int a, int b) { return a == b ? 1 : 0; } };

  switch (p2) {
  case 0x65:
    if (f_0bf6f0(CH, 0x270000eb) == r)
      f_0dd7f0(d_1c0004, 0x14, 0x14ba);
    break;
  case 0x66:
    if (IS12(d_1c0d80, 0)) {
      f_125400((int)&frame.o66, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
      frame.o66.p[1] = f_038c40(d_1c0004);
      f_0bf730(CH, 0x270000ec);
      f_1254a0((int)&frame.o66, 0);
    }
    break;
  case 0x67: {
    int a = p1;
    f_130fd0(a, 0, &d_1c0d80);
    break;
  }
  case 0x68:
    if (IS12(d_1c0d7c, 0)) {
      f_125400((int)&frame.o68, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
      frame.o68.p[1] = f_038c40(d_1c0004);
      f_0bf730(CH, 0x270000ec);
      f_1254a0((int)&frame.o68, 0);
    }
    break;
  case 0x69: {
    int a = p1;
    f_130fd0(a, r, &d_1c0d7c);
    break;
  }
  case 0x6a:
    if (IS12(d_1c0d84, 0)) {
      f_125400((int)&frame.o6a, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
      frame.o6a.p[1] = f_038c40(d_1c0004);
      f_0bf730(CH, 0x270000fa);
      f_1254a0((int)&frame.o6a, 0);
    }
    break;
  case 0x6b: {
    int a = p1;
    f_130fd0(a, 2, &d_1c0d84);
    break;
  }
  case 0xca: f_0bf730(CH, 0x270000fb); break;
  case 0x12f: ((void (*)(int))f_12fbe0)(p1); break;
  case 0x130: f_0bf730(CH, 0x27000101); break;
  case 0x131: break;
  case 0x132: f_0603b0(0x3c); break;
  case 0x1f49: ((void (*)(int))f_12fd30)(p1); break;
  case 0x134:
    if (IS12(d_1c0d88, 0))
      f_0bf730(CH, 0x27000105);
    else
      f_0bf730(CH, 0x27000106);
    break;
  case 0x135: f_060360(0x17); break;
  case 0x191: ((void (*)(int))f_12ff60)(p1); break;
  case 0x192: f_130040(p1); break;
  case 0x193: f_130240(p1); break;
  case 0x194: f_1304c0(p1); break;
  case 0x195: f_1307b0(p1); break;
  case 0x196: f_0bf730(CH, 0x27000126); break;
  case 0x197: break;
  case 0x198: f_0bf730(CH, 0x27000127); break;
  case 0x1f6:
    if (f_0bf6f0(CH, 0x27000128) == r)
      f_0dd7f0(d_1c0004, 0x16, 0x139a);
    break;
  case 0x1f7: f_1309f0(p1); break;
  case 0x1f8: {
    int t;
    t = (int)new (mark(d_1a8d0c, 0x5e5)) T20;
    if (t) t = f_112df0(t, 0x3d, t ^ t, 0); // haelt t in ebx ueber den Nulltest und erzeugt xor ebx,ebx wie im Original
    iVar3 = t;
    if (EQZ(d_1c0d68)) {
      d_1c0d68 = 1;
      f_0bf730(CH, 0x2700012a);
      f_112ec0(iVar3);
    } else {
      f_0bf730(CH, 0x2700012b);
      iVar2 = f_1131b0(iVar3);
      if (iVar2 != 0) f_112ec0(iVar3);
    }
    if (iVar3 != 0) delete (char *)f_112e70(iVar3, 0);
    break;
  }
  case 0x1f9:
    f_125400((int)&frame.o1f9, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
    frame.o1f9.p[1] = f_0396f0(d_1c0004, 6);
    f_0bf730(CH, 0x2700012c);
    f_1254a0((int)&frame.o1f9, 0);
    break;
  case 0x1fa: f_0bf730(CH, 0x2700012d); break;
  case 0x1fb: {
    int t, object;
    t = (int)new (mark(d_1a8d0c, 0x62f)) T20;
    object = t;
    if (t) object = f_112df0(t, 0x38, t ^ object, 0); // haelt object in ebx ueber den Nulltest und erzeugt xor ebx,ebx wie im Original
    iVar3 = object;
    iVar2 = f_1131b0(iVar3);
    if (iVar2 == 1) {
      f_0bf730(CH, 0x2700012e);
      f_112ec0(iVar3);
    } else {
      f_0bf730(CH, 0x2700012f);
    }
    if (iVar3 != 0) delete (char *)f_112e70(iVar3, 0);
    break;
  }
  case 0x1fc:
    g_130c80();
    break;
  case 0x1fd: {
    t = (int)new (mark(d_1a8d0c, 0x678)) T20;
    saved = t;
    iVar3 = t ? f_112df0(t, 0x3e, 0, 0) : saved;
    iVar2 = f_1131b0(iVar3);
    if (iVar2 == 1) {
      f_0bf730(CH, 0x27000133);
      f_112ec0(iVar3);
    } else {
      f_0bf730(CH, 0x27000134);
    }
    if (iVar3 != 0) delete (char *)f_112e70(iVar3, 0);
    break;
  }
  case 0x1fe: f_0bf730(CH, 0x27000135); break;
  case 0x1ff: {
    int t;
    t = (int)new (mark(d_1a8d0c, 0x6a8)) T20;
    iVar3 = t ? f_112df0(t, 0x39, 0, 0) : t;
    if (EQZ(*(FL *)&d_1c0d90)) {
      *(FL *)&d_1c0d90 = 1;
      f_0bf730(CH, 0x27000136);
      f_112ec0(iVar3);
    } else {
      iVar2 = f_1131b0(iVar3);
      if (iVar2 != 0) f_112ec0(iVar3);
    }
    if (iVar3 != 0) delete (char *)f_112e70(iVar3, 0);
    break;
  }
  case 0x259:
    if (f_0bf6f0(CH, 0x27000137) == r)
      f_0de810(d_1c0004, 0x67);
    break;
  case 0x1b5d: case 0x1f45: f_05fa00(0, 0x1f45); break;
  case 0x1b5a: case 0x1f42: f_12fa20(p1); break;
  case 0x1b5b: case 0x1f43: f_05fa00(0, 0x1f43); break;
  case 0x1b59: case 0x1f41: f_05fa00(0x4c, 0x1f41); break;
  case 0x1b62: case 0x1f4a: f_05fa00(0x4d, 0x1f4a); break;
  case 0x1b5c: case 0x1f44: ((void (*)(int))f_12fae0)(p1); break;
  default: r = 0; break;
  }
  return r;
}
//@ f_12f840
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler an der abwärts führenden Treppe (0x270000eb), ob die Gruppe in das
 *   darunterliegende Stockwerk des Magierturms hinabsteigen möchte, und versetzt die aktive Gruppe bei
 *   Bestätigung auf die zweite Turmebene (0x14, Zielposition 0x14ba).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Die Rückgabe des Ja/Nein-Dialogs (iVar1) entscheidet darüber, ob der Ebenenwechsel für
 *   die aktive Gruppe (d_1c0004) ausgeführt wird.
 === Ende Beschreibung === */
void f_12f840(void)
{
  { int iVar1 = f_0bf6f0(CH, 0x270000eb); if (iVar1 == 1) { f_0dd7f0(d_1c0004, 0x14, 0x14ba); } }
}
//@ f_12f870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Annähern an die erste noch aktive Sicherheitsfalle (d_1c0d80 == 0) eine
 *   Warnmeldung (0x270000ec) mit dem Namen des aktuellen Gruppenanführers an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Statusflag der ersten Falle (d_1c0d80) verhindert die Meldung nach deren
 *   Abschaltung; der Textkontext (o) nimmt den Zeiger auf den Gruppenanführer (d_1c0004) auf.
 === Ende Beschreibung === */
void f_12f870(void)
{
  if (EQZ(d_1c0d80)) { RivaTextContext o(d_1c349c, d_1c3870, d_1c3498); o.tables.p[1] = f_038c40(d_1c0004); f_0bf730(CH, 0x270000ec); }
}
//@ f_12f8d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim Betreten des Auslöserfeldes die erste der drei Sicherheitsfallen (Index 0) aus,
 *   sofern diese noch nicht über ihren zugehörigen Schalter (d_1c0d80) deaktiviert wurde.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Adresse des ersten Fallen-Statusflags (&d_1c0d80) sowie den Fallenindex 0
 *   an die gemeinsame Fallenroutine f_130fd0.
 === Ende Beschreibung === */
void f_12f8d0(int p1)
{
  f_130fd0(p1, 0, &d_1c0d80);
}
//@ f_12f8f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Annähern an die zweite noch aktive Sicherheitsfalle (d_1c0d7c == 0) dieselbe
 *   Warnmeldung (0x270000ec) mit dem Namen des Gruppenanführers an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft das globale Statusflag der zweiten Falle (d_1c0d7c) und trägt den Gruppenanführer
 *   in den lokalen Textkontext (o) ein.
 === Ende Beschreibung === */
void f_12f8f0(void)
{
  if (EQZ(d_1c0d7c)) { RivaTextContext o(d_1c349c, d_1c3870, d_1c3498); o.tables.p[1] = f_038c40(d_1c0004); f_0bf730(CH, 0x270000ec); }
}
//@ f_12f950
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim Betreten des Auslöserfeldes die zweite Sicherheitsfalle (Index 1) aus, indem die
 *   gemeinsame Fallenroutine mit dem zugehörigen Statusflag (d_1c0d7c) aufgerufen wird.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Übergibt den Ebenen-Zeiger (p1), den Fallenindex 1 und die Adresse des zweiten
 *   Fallenflags (&d_1c0d7c) an f_130fd0.
 === Ende Beschreibung === */
void f_12f950(int p1)
{
  f_130fd0(p1, 1, &d_1c0d7c);
}
//@ f_12f970
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt beim Annähern an die dritte, besonders tödliche Sicherheitsfalle (d_1c0d84 == 0) eine
 *   eigene Warnmeldung (0x270000fa) mit dem Namen des Gruppenanführers aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft das globale Statusflag der dritten Falle (d_1c0d84) und belegt den ersten
 *   Platzhalter des Textkontexts (o) mit dem Gruppenanführer.
 === Ende Beschreibung === */
void f_12f970(void)
{
  if (EQZ(d_1c0d84)) { RivaTextContext o(d_1c349c, d_1c3870, d_1c3498); o.tables.p[1] = f_038c40(d_1c0004); f_0bf730(CH, 0x270000fa); }
}
//@ f_12f9d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim Betreten des Auslöserfeldes die dritte Sicherheitsfalle (Index 2) aus, die bei
 *   Fehlschlag oder Trotzreaktion zum sofortigen Tod des Anführers führen kann.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Übergibt den Ebenen-Zeiger (p1), den Fallenindex 2 und die Adresse des dritten
 *   Fallenflags (&d_1c0d84) an f_130fd0.
 === Ende Beschreibung === */
void f_12f9d0(int p1)
{
  f_130fd0(p1, 2, &d_1c0d84);
}
//@ f_12f9f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Standard-Türinteraktion für die unverschlossene Innentür mit der Objektkennung
 *   0x1f45 aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen; ruft unmittelbar f_05fa00(0, 0x1f45) auf.
 === Ende Beschreibung === */
void f_12f9f0(void)
{
  f_05fa00(0, 0x1f45);
}
//@ f_12fa00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt einen beschreibenden Raumtext (0x270000fb) für einen Bereich der dritten Turmebene in
 *   einem Textfenster an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt den globalen Dialogkontext (d_1c2c64) zur Textausgabe.
 === Ende Beschreibung === */
void f_12fa00(void)
{
  f_0bf730(CH, 0x270000fb);
}
//@ f_12fa20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Öffnen der Tür 0x1f42 (Türindex 0x4a) und löst beim allerersten Betreten des
 *   dahinterliegenden Raumes (d_1c0d74 == 0) eine Meldung (0x270000fc) sowie einen Kampf (0x1f) über die
 *   virtuelle Kampffunktion der Ebene aus.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Das temporäre Türobjekt (p1_00) liefert über f_05f580 den Öffnungszustand (iVar2); das
 *   globale Flag d_1c0d74 stellt sicher, dass der Kampf (0x1f) nur einmal stattfindet und danach im Ebenenstatus
 *   (f_0697c0) abgehakt wird.
 === Ende Beschreibung === */
void f_12fa20(int p1)
{
  int t, p1_00, iVar2;
  t = (int)new (mark(d_1a8d0c, 0x1d6)) T12;
  p1_00 = t ? f_05f190(t, 0x4a, 0x1f42) : t;
  f_05f280(p1_00, 0);
  iVar2 = f_05f580(p1_00);
  if (iVar2 == 1 && EQ(d_1c0d74, 0)) {
    f_0bf730(CH, 0x270000fc);
    ((int(*)(int,int,int))(**(int**)(p1+8)))(p1, 0x1f, 0);
    d_1c0d74 = 1;
    f_0697c0(p1 + 2, 0x1f, 0);
  }
  if (p1_00 != 0) delete (char *)f_05f220(p1_00, 0);
}
//@ f_12fad0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Standard-Türinteraktion für die Innentür mit der Objektkennung 0x1f43 aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen; delegiert direkt an f_05fa00(0, 0x1f43).
 === Ende Beschreibung === */
void f_12fad0(void)
{
  f_05fa00(0, 0x1f43);
}
//@ f_12fae0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die magisch gesicherte Tür 0x1f44, die den Spieler per Sprachausgabe (0x270014) und
 *   Texteingabefeld (0x270000fe) nach einem Passwort (0x270000fd) fragt und sich bei richtiger Antwort
 *   entriegelt, einen Tagebucheintrag (0x2d) anlegt sowie 5 Abenteuerpunkte vergibt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der lokale Stringpuffer (local_2c) enthält das erwartete Lösungswort in Großbuchstaben
 *   zum Vergleich mit der Spielereingabe (d_1c299c); das globale Flag d_1c0d6c speichert, ob das Passwort
 *   bereits gelöst wurde.
 === Ende Beschreibung === */
void f_12fae0(void)
{
  int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  int t, p1, iVar3;
  char local_2c[20];
  t = (int)new (mark(d_1a8d0c, 0x20b)) T12;
  p1 = t ? f_05f190(t, 0, 0x1f44) : t;
  if (EQZ(d_1c0d6c)) {
    f_0e93f0((int)&d_1c38b0, (int)local_2c, 0x270000fd);
    f_1454d0((int)local_2c);
    int snd = *(int *)&d_1a9820;
    f_147323_frame(CH2, 0x270014, 0x7fff, 0x8000, snd, 0, 1);
    f_0bfea0(CH, (short)strlen(local_2c), 0x270000fe);
    iVar3 = f_144bf0(local_2c, d_1c299c);
    if (iVar3 == 0) {
      d_1c0d6c = 1;
      f_05f480(p1);
      f_091f70(0x2d);
      f_0dcbb0(d_1c0004, 5);
    }
  }
  if (p1 != 0) delete (char *)f_05f220(p1, 0);
}
//@ f_12fbe0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet die Untersuchung des Schreibtisches bzw. Beutelagers 0x3a: Beim ersten Durchsuchen
 *   (d_1c0d70 == 0) bemerkt der Held mit dem höchsten Wert in einem Wissenstalent (0x11, Lesen/Schreiben) ein
 *   Geheimfach (0x27000100), woraufhin der "Brief von Abu Terfas" (0x1b1) und der "Brief über T's Experimente"
 *   (0x1b2) dem Beutelager hinzugefügt und dem Spieler zur Mitnahme angeboten werden.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Das dynamisch erzeugte Beutelager-Objekt (p1) repräsentiert den Inhalt des Tisches
 *   (0x3a); das globale Flag d_1c0d70 vermerkt, ob das Geheimfach bereits entdeckt und befüllt wurde.
 === Ende Beschreibung === */
void f_12fbe0(void)
{
  int t, p1;
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  t = (int)new (mark(d_1a8d0c, 0x253)) T20;
  p1 = t ? f_112df0(t, 0x3a, 0, 0) : t;
  if (EQZ(d_1c0d70)) f_0bf730(CH, 0x270000ff);
  f_112ec0(p1);
  if (EQZ(d_1c0d70)) {
    f_060a70();
    d_1c0d70 = 1;
    o.tables.p[1] = f_039320(d_1c0004, 0x11);
    f_0bf730(CH, 0x27000100);
    f_113340(p1, 0x1b2, 1, 0);
    f_113340(p1, 0x1b1, 1, 0);
    f_112ec0(p1);
  }
  if (p1 != 0) delete (char *)f_112e70(p1, 0);
}
//@ f_12fcf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Untersuchen eines Raumelements den zugehörigen Beschreibungstext (0x27000101) an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt den Rückgabewert des Textdialogs (f_0bf730) zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_12fcf0(void)
{
  return f_0bf730(CH, 0x27000101);
}

//@ f_12fd10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leere Platzhalterfunktion für das Raumereignis 0x131, bei dem im Spiel keine Aktion
 *   ausgelöst wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine Variablen.
 === Ende Beschreibung === */
void f_12fd10(void)
{
}

//@ f_12fd20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet das Beutelager mit der Kennung 0x3c zur Übergabe der dort gelagerten Gegenstände an
 *   die Heldengruppe.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen; ruft f_0603b0(0x3c) auf.
 === Ende Beschreibung === */
void f_12fd20(void)
{
  f_0603b0(0x3c);
}
//@ f_12fd30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Interaktion mit dem versperrten Durchgang bzw. Wandobjekt 0x1f49: Zwei Helden
 *   (höchster Wert in Talent 0x27 Sinnenschärfe und niedrigster Wert in Talent 0x24) bemerken eine Besonderheit
 *   (0x27000102), und wenn der Spieler bestätigt (0x27000103), durchbricht oder öffnet der kräftigste Held
 *   (Attribut 6, Körperkraft) unter Abspielen eines Soundeffekts (0x270015) das Hindernis, schaltet das
 *   3D-Objekt (0x1f49) sowie die Automap um und setzt das Statusflag d_1c0d88.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Textkontext (o) speichert bis zu drei beteiligte Helden für die Dialogtexte; das
 *   globale Flag d_1c0d88 markiert, dass der Durchgang 0x1f49 bereits geöffnet wurde.
 === Ende Beschreibung === */
void f_12fd30(void)
{
  int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  int iVar2;
  if (EQZ(d_1c0d88)) {
    RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    o.tables.p[1] = f_039320(d_1c0004, 0x27);
    o.tables.p[2] = f_039420(d_1c0004, 0x24);
    f_0bf730(CH, 0x27000102);
    iVar2 = f_0bf6f0(CH, 0x27000103);
    if (iVar2 == 1) {
      o.tables.p[3] = f_039660(d_1c0004, 6);
      int snd = *(int *)&d_1a9820;
      f_147323_frame(CH2, 0x270015, 0x7fff, 0x8000, snd, 0, 1);
      f_0bf730(CH, 0x27000104);
      f_060740(0x1f49, 1);
      f_0607e0(0x1f49, 1);
      d_1c0d88 = 1;
    }
  }
}
//@ f_12fe40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt je nachdem, ob das Hindernis 0x1f49 noch verschlossen (d_1c0d88 == 0) oder bereits
 *   geöffnet ist, den passenden Beschreibungstext (0x27000105 bzw. 0x27000106) aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft ausschließlich das globale Statusflag d_1c0d88.
 === Ende Beschreibung === */
void f_12fe40(void)
{
  if (EQI(d_1c0d88, 0)) f_0bf730(CH, 0x27000105);
  else f_0bf730(CH, 0x27000106);
}
//@ f_12fe70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet die Schatztruhe mit der Kennung 0x17 über die allgemeine Truhenverwaltung des
 *   Dungeons.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen; ruft f_060360(0x17) auf.
 === Ende Beschreibung === */
void f_12fe70(void)
{
  f_060360(0x17);
}
//@ f_12fe80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Standard-Türinteraktion für die verschlossene Tür mit dem Türindex 0x4c und der
 *   3D-Objektkennung 0x1f41 aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine eigenen Variablen; ruft f_05fa00(0x4c, 0x1f41) auf.
 === Ende Beschreibung === */
void f_12fe80(void)
{
  f_05fa00(0x4c, 0x1f41);
}
//@ f_12fea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt einen handlungsfähigen Helden aus der aktiven Gruppe für ein Raumereignis in der
 *   Bibliothek, indem zunächst nach der Filterfunktion f_10fc50 gesucht und der erste bei Bewusstsein
 *   befindliche Treffer gewählt wird; falls keiner davon handlungsfähig ist, wird der erste verfügbare Held der
 *   Gruppe zurückgegeben.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt einen Zeiger auf den ausgewählten Helden (r) oder 0 zurück, wenn kein passender Held in
 *   der Gruppe ist.
 * - Wichtige Variablen: Das globale Puffer-Array d_1c24d4 nimmt die gefilterten Heldenzeiger (n Treffer) auf;
 *   die Schleifenvariable i prüft der Reihe nach deren Handlungsfähigkeit (f_0d4a60).
 === Ende Beschreibung === */
int f_12fea0(void)
{
  short n = -1;
  int r = 0;
  short i;
  n = f_0398c0(d_1c0004, (int)f_10fc50, (int)d_1c24d4);
  if (n > 0) {
    r = 0;
    for (i = 0; i < n && r == 0; i++) {
      int *p = &d_1c24d4[i];
      if (f_0d4a60(*p) != 0) r = *p;
    }
    if (r == 0) r = f_038be0(d_1c0004);
  } else {
    r = 0;
  }
  return r;
}
#pragma aux f_12fea0 "*";
//@ f_12ff10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Versucht, einem bestimmten Helden (p3) ein gefundenes Buch oder einen Gegenstand (p2) ins
 *   Inventar zu legen; falls sein Inventar voll ist, wird versucht, den Gegenstand einem anderen Gruppenmitglied
 *   zu übergeben (f_0dcf00), und falls auch das fehlschlägt, erscheint eine Meldung über Überladung
 *   (0x2700010a).
 * - Eingaben: Ein ungenutzter Kontextparameter (p1), die Gegenstandskennung (p2) sowie der Zeiger auf den
 *   bevorzugten Empfänger-Helden (p3).
 * - Rückgabewert: Gibt 1 zurück, wenn der Gegenstand erfolgreich in der Gruppe untergebracht wurde, sonst 0.
 * - Wichtige Variablen: Das Statusflag uVar2 merkt sich den Erfolg der Übergabe, während sVar1 die Rückgabewerte
 *   der Inventarfunktionen aufnimmt.
 === Ende Beschreibung === */
int f_12ff10(int p1, int p2, int p3)
{
  short sVar1;
  int uVar2;
  uVar2 = 1;
  sVar1 = f_0366e0(p3, (short)p2, 0, 1);
  if (sVar1 != 1) {
    sVar1 = f_0dcf00(d_1c0004, (short)p2, 1);
    if (sVar1 != 1) {
      f_0bf730(CH, 0x2700010a);
      uVar2 = 0;
    }
  }
  return uVar2;
}
//@ f_12ff60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim Betreten oder Untersuchen eines bestimmten Punktes in der Bibliothek (Ereignis
 *   0x191) eine aufsteigende Folge von Warn- bzw. Beobachtungstexten (0x27000107, 0x27000108, 0x27000109) für
 *   einen ausgewählten Helden aus und schaltet einen Licht- oder Umgebungseffekt (0x270002) im Raum.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zähler d_1c0e80 wird bei jedem Auslösen bis zum Höchstwert 10 inkrementiert und
 *   bestimmt anhand der Schwellenwerte < 3, 3..6 und >= 7, welcher der drei Texte (p2) angezeigt wird.
 === Ende Beschreibung === */
void f_12ff60(void)
{
  int iVar1, p2;
  iVar1 = f_12fea0();
  if (iVar1 != 0) {
    RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    p2 = 0;
    if ((d_1c0e80 < 10) ? 1 : 0) {
      d_1c0e80 = d_1c0e80 + 1;
    }
    if ((d_1c0e80 < 3) ? 1 : 0) {
      p2 = 0x27000107;
    }
    else if (((d_1c0e80 >= 3) ? 1 : 0) && ((d_1c0e80 < 7) ? 1 : 0)) {
      p2 = 0x27000108;
    }
    else if ((d_1c0e80 >= 7) ? 1 : 0) {
      p2 = 0x27000109;
    }
    o.tables.p[1] = iVar1;
    f_0bf730(CH, p2);
    f_060800(0x270002, 1, 0);
  }
}
