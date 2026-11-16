/* === Beschreibung (Katalog) ===
 * Einheit gz_0b3300_t1 (0x0B3300 - 0x0B5C00)
 *
 * Umfangreiche Sammlung von Gebäude-, Quest- und Stadtereignissen in Riva (u. a. Badehaus/Bordell, Wahrsagerin,
 * Hafen-/Schmugglerszenen, Öffnungszeitenprüfungen und Registrierung der 51 globalen Orts-Questvariablen).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 32/34 gleich (suche.py 30.10.2026, Basis gz_0b3300_t1_P1.CPP)
// gz_0b3300.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B3300-0x0B5C00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0390a0(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03cd00(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045170(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
                                   // reg eax stapel 0
int f_0b3240();                                         // reg - stapel 0
int f_0b8a00(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8d40(int p1);                                   // reg eax stapel 0
int f_0b8ef0(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20(int p1, ...);
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dbc10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
short f_0de820(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0eb230();                                         // reg - stapel 0
int f_0eca40();                                         // reg - stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_1264f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bc88c;                    // 0x1BC88C
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bdaf8;                    // 0x1BDAF8
extern int d_1bf1ac;                    // 0x1BF1AC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c01d8;                    // 0x1C01D8
extern unsigned short d_1c21a4;                    // 0x1C21A4
// --- eigene Funktionen (34), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#define A(x) ((int)(x))
#define EQI(x,v) (((x)==(v))?1:0)
#define C64 A(d_1c2c64)
#define C44 A(d_1c2c44)
#pragma inline_depth(0)
struct SO { int a; int *p; char c[52]; };
struct SOC { int a; char *p; char c[52]; };
struct KT { short key; short pad; int text; };
extern struct KT d_1a7884[];
struct FL { signed char v; short id; char pad; };
extern struct FL d_1bed64;
extern struct FL d_1bed68;
extern struct FL d_1bed6c;
extern struct FL d_1bed70;
extern struct FL d_1bed74;
extern struct FL d_1bed78;
extern struct FL d_1bed7c;
extern struct FL d_1bed80;
extern struct FL d_1bed84;
extern struct FL d_1bed88;
extern struct FL d_1bed8c;
extern struct FL d_1bed90;
extern struct FL d_1bed94;
extern struct FL d_1bed98;
extern struct FL d_1bed9c;
extern struct FL d_1beda0;
extern struct FL d_1beda4;
extern struct FL d_1beda8;
extern struct FL d_1bedac;
extern struct FL d_1bedb0;
extern struct FL d_1bedb4;
extern struct FL d_1bedb8;
extern struct FL d_1bedbc;
extern struct FL d_1bedc0;
extern struct FL d_1bedc4;
extern struct FL d_1bedc8;
extern struct FL d_1bedcc;
extern struct FL d_1bedd0;
extern struct FL d_1bedd4;
extern struct FL d_1bedd8;
extern struct FL d_1beddc;
extern struct FL d_1bede0;
extern struct FL d_1bede4;
extern struct FL d_1bede8;
extern struct FL d_1bedec;
extern struct FL d_1bedf0;
extern struct FL d_1bedf4;
extern struct FL d_1bedf8;
extern struct FL d_1bedfc;
extern struct FL d_1bee00;
extern struct FL d_1bee04;
extern struct FL d_1bee08;
extern struct FL d_1bee0c;
extern struct FL d_1bee10;
extern struct FL d_1bee14;
extern struct FL d_1bee18;
extern struct FL d_1bee1c;
extern struct FL d_1bee20;
extern struct FL d_1bee24;
extern struct FL d_1bee28;
extern struct FL d_1bee2c;
extern int *d_1c212c;
extern short d_1c212a;
extern signed char d_1bca7c, d_1bca84, d_1bcaa0, d_1c00ac, d_1c00a4, d_1c00b0, d_1c00bc, d_1c00c0, d_1c00c4, d_1c01f0;

extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern char d_1c2c44[], d_1c2c64[], d_1c38b0[], d_1c21b4[];
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
signed char f_03ad80(int p1, int p2);
int f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0bf820(int p1, int p2, ...);
int f_0bde40(int p1);

int f_125dc0(int p1, int p2);
signed char f_126420(int p1);
short f_0de7f0(int p1);
int f_0b2f30();
int f_0b30f0();
#define CHK(n) c = f_03ad80(p1, n); if (c < 3 || (c < 10 && (s = f_1457e0(c)) == 1)) f_03af20(p1, n, 1);
#define CHK2(n) c = f_03ad80(p1, n); if (c > 2) { if (c > 9) return; if ((s = f_1457e0(c)) != 1) return; } f_03af20(p1, n, 1);

#define EQ(x,v) (((x)==(v))?1:0)
struct S_4 { char b[4]; };
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0b3300
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Filterfunktion prüft für einen Helden (p1), ob er handlungsfähig ist (f_0d4a60) und im
 *   Talent mit Index 0x23 (35) einen Talentwert größer als 10 besitzt (f_03ad80).
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held handlungsfähig ist und der Talentwert über 10 liegt,
 *   sonst 0.
 === Ende Beschreibung === */
int f_0b3300(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) != 0) {
    if (f_03ad80(p1, 0x23) > 10) r = 1;
  }
  return r;
}

//@ f_0b3330
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Filterfunktion prüft für einen Helden (p1), ob er handlungsfähig ist (f_0d4a60) und im
 *   Talent mit Index 0x21 (33) einen Talentwert größer als 10 besitzt.
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Bedingung erfüllt ist, und sonst 0.
 === Ende Beschreibung === */
int f_0b3330(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) != 0) {
    if (f_03ad80(p1, 0x21) > 10) r = 1;
  }
  return r;
}

//@ f_0b3360
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Filterfunktion wird in f_0b58f0 für die dritte Besuchsstufe (d_1bca7c == 10)
 *   aufgerufen, prüft im Originalcode jedoch exakt dieselbe Bedingung wie f_0b3330 (Talent 0x21 größer als 10,
 *   vermutlich ein Kopierfehler; siehe Fehlerliste).
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held handlungsfähig ist und im Talent 0x21 einen Wert
 *   über 10 besitzt, sonst 0.
 === Ende Beschreibung === */
int f_0b3360(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) != 0) {
    if (f_03ad80(p1, 0x21) > 10) r = 1;
  }
  return r;
}

//@ f_0b3390
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion erhöht für einen Helden (p1) den Wert eines bestimmten Talents (p2) über
 *   f_03af20 um 1 Punkt, sofern der bisherige Talentwert (f_03ad80) noch unter 3 liegt oder zwischen 3 und 9
 *   liegt und ein Zufallswurf (f_1457e0(c) == 1) gelingt.
 * - Eingaben: Übergeben werden ein Zeiger auf die Heldenstruktur (p1) und der Talentindex (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b3390(int p1, short p2)
{
  short c;
  short s;
  c = f_03ad80(p1, p2);
  if (c >= 3) {
    if (c >= 10) return;
    s = f_1457e0(c);
    if (s != 1) return;
  }
  f_03af20(p1, p2, 1);
}

//@ f_0b33d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion wendet die Talenterhöhungs-Chance aus f_0b3390 nacheinander auf die sechs
 *   gesellschaftlichen/körperlichen Talente 33, 34, 35, 36, 38 und 40 eines Helden (p1) an.
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b33d0(int p1) {
 { short n=33; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
 { short n=34; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
 { short n=35; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
 { short n=36; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
 { short n=38; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
 { short n=40; short c;
 int q=p1;
 c=f_03ad80(p1,n);
 if (c<3 || (c<10 && (short)f_1457e0(c)==1)) f_03af20(q,n,1);
 }
}

//@ f_0b3560
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion behandelt einen geheimen Übergang (z. B. Kanalisations- oder Schleichweg,
 *   aktiv bei d_1bed74.v == 1): Nach einer Bestätigungsfrage (0x2201001c bzw. 0x2201001d) versetzt sie die
 *   Gruppe über f_0dd7f0 an das Zielgebiet (p1, Position p2), lässt 10 Minuten Spielzeit vergehen (f_125ed0) und
 *   gibt beim allerersten Mal (d_1bedd0.v == 0) den Kommentar 0x2201001f aus.
 * - Eingaben: Übergeben werden die Zielgebietskennung (p1) und die Zielposition (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b3560(short p1, short p2)
{
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  if (EQI(d_1bed74.v, 1)) {
    if (f_0bf6f0(C64, (unsigned char)(!EQ(d_1bedd0.v, 0)) + 0x2201001c) == 1) {
      f_0dd7f0(d_1c0004, p1, p2);
    }
    if (f_0de820(d_1c0004) == p1) {
      f_125ed0(C44, 10);
      if (EQI(d_1bedd0.v, 0)) {
        d_1bedd0.v = 1;
        o.p[1] = f_038c40(d_1c0004);
        f_0bf730(C64, 0x2201001f);
      }
    }
  }
  f_1254a0(&o, 0);
}

//@ f_0b3640
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert das heimliche Überklettern oder Durchqueren einer gesicherten Stelle
 *   bei Tageslicht (0x5460 bis 0x1d010): Bei aktivem Alarmflag (d_1c00bc != 0) besteht eine 10 %-Chance auf
 *   Entdeckung mit anschließendem Wachkampf (0x8d bis 0x90 über f_08c920), andernfalls fragt die Funktion per
 *   Dialog (0x22010075-0x2201007a), ob die Gruppe den Übergang wagen will.
 * - Eingaben: Übergeben wird die Ortskennung des Übergangs (p1, z. B. 0x62 oder 99).
 * - Rückgabewert: Die Funktion gibt 1 bei gelungener Durchquerung, 2 nach einem siegreichen Wachkampf und 0 bei
 *   Abbruch oder zur falschen Tageszeit zurück.
 === Ende Beschreibung === */
short f_0b3640(short p1)
{
 struct LocalState491 {short uVar4,sVar1;} state491;

  int iVar3,uVar5; short sVar2;
  state491.sVar1 = -1;
  iVar3 = f_126410(C44);
  state491.uVar4 = 0;
  if (!(iVar3 <= 0x1d010 && f_126410(C44) >= 0x5460)) {
    f_0bf730(C64, 0x22010073);
  } else {
    if (EQ(d_1c00bc, 0)) {
      if (EQ(d_1bedf0.v, 0)) {
        f_0bf730(C64, 0x22010074);
        d_1bedf0.v = 1;
      }
      state491.sVar1 = f_0de820(d_1c0004);
      uVar5 = 0x22010075;
      if (state491.sVar1 != 0) uVar5 = 0x22010076;
      iVar3 = f_0bf6f0(C64, uVar5);
      if(iVar3 != 1) goto done;
      goto success;
    } else {
      sVar2 = f_1457e0(100);
      if (sVar2 <= 10) {
        f_0bf730(C64, 0x22010077);
        sVar2 = f_0de820(d_1c0004);
        if (sVar2 != 0) {
          if (p1 == 0x62) state491.sVar1 = 0x8d;
          else if (p1 == 99) state491.sVar1 = 0x90;
        } else if (p1 == 0x62) state491.sVar1 = 0x8e;
        else if (p1 == 99) state491.sVar1 = 0x8f;
        d_1bd91c = 1;
        state491.sVar1 = f_08c920(state491.sVar1, 0);
        if (state491.sVar1 != 0) goto done;
        f_09a400();
        state491.uVar4 = 2;
        f_0bf730(C64, 0x22010078);
        goto done;
      }
      state491.sVar1 = f_0de820(d_1c0004);
      uVar5 = 0x22010079;
      if (state491.sVar1 != 0) uVar5 = 0x2201007a;
      iVar3 = f_0bf6f0(C64, uVar5);
    }
    if (iVar3 == 1) state491.uVar4 = 1;
  }
  goto done;
success:
  state491.uVar4 = 1;
done:
  return state491.uVar4;
}

//@ f_0b37d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion lässt den Spieler einen Gegenstand im Inventar eines Helden (p1) zur
 *   Begutachtung auswählen (f_032820), ermittelt dessen magische oder besondere Eigenschaften (f_0a7a90 sowie
 *   die Tabelle d_1a7884), lädt den passenden Beschreibungstext in den Puffer d_1c21b4 und markiert den
 *   Gegenstand im Heldeninventar als identifiziert/untersucht (f_042f20, f_042eb0).
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1), aus deren Inventar ein Gegenstand
 *   untersucht werden soll.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein Gegenstand ausgewählt und untersucht wurde, und 0 bei
 *   Abbruch.
 === Ende Beschreibung === */
int f_0b37d0(int p1)
{
  short sVar1, sVar3, w;
  int iVar2, p2, uVar4;
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  uVar4 = 0;
  w = f_032820(p1, 0x20000103, 1);
  if (w != -1) {
    sVar1 = ((int)(f_042a60((struct hero *)(p1), w)));
    if (0 < sVar1) {
      f_0e93f0(A(d_1c38b0), A(d_1c21b4), 0x17000042);
      sVar3 = 0;
      iVar2 = ((RivaItemDefinition*)(*(int *)((int)(*(struct S_4 **)&d_1c2c40 + (sVar1)))))->f_0a7a90();
      if (iVar2 != 0) {
        f_0e93f0(A(d_1c38b0), A(d_1c21b4), 0x1700008d);
      }
      for (;;) {
        iVar2 = sVar3;
        if (d_1a7884[iVar2].key == -1) break;
        if (sVar1 == d_1a7884[iVar2].key) {
          p2 = w;
          f_0e93f0(A(d_1c38b0), A(d_1c21b4), d_1a7884[iVar2].text);
          f_042f20((struct hero *)(p1), p2, 1);
          f_042eb0((struct hero *)(p1), p2, 1);
          break;
        }
        sVar3 = sVar3 + 1;
      }
    }
    uVar4 = 1;
  }
  f_1254a0(&o, 0);
  return uVar4;
}

//@ f_0b38e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion wählt zufällig (f_1457e0(5)) einen von fünf kurzen Stimmungs- oder
 *   Begrüßungstexten (0x22000006 bis 0x2200000a) aus und zeigt ihn in einem Textfenster an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b38e0(void)
{
  short sVar1;
  sVar1 = f_1457e0(5);
  if (sVar1 == 1) {
    f_0bf730(C64, 0x22000006);
    return 1;
  }
  if (sVar1 == 2) {
    f_0bf730(C64, 0x22000007);
    return 1;
  }
  if (sVar1 == 3) {
    f_0bf730(C64, 0x22000008);
    return 1;
  }
  f_0bf730(C64, (sVar1 != 4) + 0x22000009);
  return 1;
}

//@ f_0b3950
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Hilfsfunktion prüft, ob die aktuelle Spieltageszeit (f_126410(&d_1c2c44)) innerhalb
 *   des angegebenen Zeitfensters von p1 bis p2 liegt (wobei auch Zeitfenster über Mitternacht hinweg korrekt
 *   behandelt werden, wenn p1 > p2 ist).
 * - Eingaben: Übergeben werden die Startzeit (p1) und die Endzeit (p2) in internen Zeiteinheiten.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die aktuelle Uhrzeit innerhalb des Zeitfensters liegt (oder
 *   p1 == p2 gilt), und 0, wenn sie außerhalb liegt.
 === Ende Beschreibung === */
int f_0b3950(int p1, int p2)
{
  int iVar1;
  int uVar2;
  uVar2 = 1;
  iVar1 = f_126410(C44);
  if (p1 != p2 && ((p1 < p2 && (iVar1 < p1 || iVar1 > p2)) || (p1 > p2 && (iVar1 < p1 && iVar1 > p2)))) {
    uVar2 = 0;
  }
  return uVar2;
}

//@ f_0b3990
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion führt den Besuch bei einem Gelehrten oder Analytiker durch, der gegen eine
 *   Gebühr von 100 Heller (f_0db8b0) und 30 Minuten Zeitaufwand (f_125ed0) in einer Schleife beliebige
 *   Gegenstände der Helden über f_0b37d0 untersucht und das Ergebnis (d_1c21b4) in den Textfenstern 0x2201008a
 *   bis 0x22010090 präsentiert.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b3990(void)
{
  int iVar1, uVar2, bVar3;
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  do {
    bVar3 = 1;
    iVar1 = f_0de7e0(d_1c0004);
    if (iVar1 < 100) {
      uVar2 = 0x2201008a;
      goto LAB_a66;
    }
    iVar1 = f_038d70(d_1c0004, 0x2201008b);
    if (iVar1 == 0) {
      goto LAB_no;
    }
    if (f_0b37d0(iVar1) == 1) {
        f_0bf730(C64, 0x2201008d);
        f_125ed0(C44, 0x1e);
        f_0bf730(C64, 0x2201008e);
        (*(int **)(o.c + 8))[1] = f_133fe0(A(d_1c3498), A(d_1c21b4));
        iVar1 = f_0bf6f0(C64, 0x2201008f);
        if (iVar1 == 1) bVar3 = 0;
        else f_0bf730(C64, 0x22010090);
        f_0db8b0(d_1c0004, 100);
    }
    goto LAB_end;
LAB_no:
    uVar2 = 0x2201008c;
LAB_a66:
    f_0bf730(C64, uVar2);
LAB_end:
    if (bVar3) {
      f_1254a0(&o, 0);
      return;
    }
  } while (1);
}

//@ f_0b3a90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft beim Betreten einer gebührenpflichtigen Einrichtung zunächst die
 *   wochentagsabhängigen Öffnungszeiten (Offsets +0x32 und +0x40 des Ortsobjekts p1), ruft die
 *   Standard-Ortsbehandlung (f_0b8d40) auf und zieht bei Eintritt pro Gruppenmitglied (f_0dbfe0) 10 Heller
 *   Eintrittsgeld (f_0db8b0) ab bzw. weist die Gruppe bei Geldmangel ab (0x32000005).
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 0 bei erfolgreichem Eintritt und Bezahlung zurück, oder 1, wenn geschlossen
 *   ist oder das Geld nicht reicht.
 === Ende Beschreibung === */
int f_0b3a90(int p1)
{
  int f_0dbfe0(int);
  struct Window492 {
    static int inside(int result,int a,int b) {
      int now=0; int saved=b; now=f_126410(C44);
      if(a!=b && ((a<b && (now<a || now>b)) ||
                  (a>saved && (now<a && now>saved)))) result=0;
      return result;
    }
  };
  SO o;
  signed char day=f_126420(C44);
  int a=*(short *)(p1+0x32+day*2)*0x1518;
  day=f_126420(C44);
  int b=*(short *)(p1+0x40+day*2)*0x1518;
  int result;
  if(Window492::inside(1,a,b)==0) {
    result=1;
    f_0bf730(C64,0x22010003);
  } else result=f_0b8d40(p1);
  if(result==0) {
    short amount=(short)(f_0dbfe0(d_1c0004)*10);
    if(f_0de7e0(d_1c0004)<amount) {
      f_125400(&o,d_1c349c,d_1c3870,d_1c3498);
      (*(short **)(o.c+0xc))[1]=(short)(amount/10);
      f_0bf730(C64,0x32000005);
      result=1;
      f_1254a0(&o,0);
    } else {
      f_0db8b0(d_1c0004,amount);
      f_0bf730(C64,0x32000001);
      result=0;
    }
  }
  return result;
}

//@ f_0b3c00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion ist ein leerer Platzhalter, der konstant 0 zurückgibt.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt immer 0 zurück.
 === Ende Beschreibung === */
int f_0b3c00(void)
{
  return 0;
}

//@ f_0b3c10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Initialisierungsfunktion registriert 51 globale Orts- und Quest-Zustandsvariablen
 *   (d_1bed64 bis d_1bee2c, mit den Kennungen 0x06 bis 0x26b) mit dem Startwert 0 in der globalen
 *   Spielstands-Variablentabelle (d_1c212a).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#pragma aux f_0b3950 parm [eax] [edx] value [eax];
#pragma inline_depth(1)
struct Reg492 {
 static inline void first(FL *p, short *n, int *&list, short id, signed char value) {p->v=value; p->id=id; list[*n]=(int)p;}
 static inline void next(FL *p, short *n, int *&list, short id, signed char value) {p->v=value; p->id=id; list[++*n]=(int)p;}
 static inline void third(FL *p, short *n, int *&list, short id, signed char value) {p->id=id; p->v=value; list[++*n]=(int)p;}
};
#pragma inline_depth(3)
struct RR700V3_0b3c108;
struct OR700V3_0b3c108 { signed char flag; short number; char pad; OR700V3_0b3c108 *init(RR700V3_0b3c108 &r,short id,signed char f);OR700V3_0b3c108 *initThird(RR700V3_0b3c108 &r,short id,signed char f); };
struct RR700V3_0b3c108 { short count; OR700V3_0b3c108 **list; void append(OR700V3_0b3c108 *o) {list[count]=o;count++;} };
inline OR700V3_0b3c108 *OR700V3_0b3c108::init(RR700V3_0b3c108 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
inline OR700V3_0b3c108 *OR700V3_0b3c108::initThird(RR700V3_0b3c108 &r,short id,signed char f){flag=f;number=id;r.list[r.count]=this;r.count++;return this;}
extern RR700V3_0b3c108 regR700V3_0b3c108;
#pragma aux regR700V3_0b3c108 "d_1c212a"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed64;
#pragma aux obR700V3_0b3c10_1bed64 "d_1bed64"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed68;
#pragma aux obR700V3_0b3c10_1bed68 "d_1bed68"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed6c;
#pragma aux obR700V3_0b3c10_1bed6c "d_1bed6c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed70;
#pragma aux obR700V3_0b3c10_1bed70 "d_1bed70"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed74;
#pragma aux obR700V3_0b3c10_1bed74 "d_1bed74"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed78;
#pragma aux obR700V3_0b3c10_1bed78 "d_1bed78"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed7c;
#pragma aux obR700V3_0b3c10_1bed7c "d_1bed7c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed80;
#pragma aux obR700V3_0b3c10_1bed80 "d_1bed80"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed84;
#pragma aux obR700V3_0b3c10_1bed84 "d_1bed84"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed88;
#pragma aux obR700V3_0b3c10_1bed88 "d_1bed88"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed8c;
#pragma aux obR700V3_0b3c10_1bed8c "d_1bed8c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed90;
#pragma aux obR700V3_0b3c10_1bed90 "d_1bed90"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed94;
#pragma aux obR700V3_0b3c10_1bed94 "d_1bed94"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed98;
#pragma aux obR700V3_0b3c10_1bed98 "d_1bed98"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bed9c;
#pragma aux obR700V3_0b3c10_1bed9c "d_1bed9c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1beda0;
#pragma aux obR700V3_0b3c10_1beda0 "d_1beda0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1beda4;
#pragma aux obR700V3_0b3c10_1beda4 "d_1beda4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1beda8;
#pragma aux obR700V3_0b3c10_1beda8 "d_1beda8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedac;
#pragma aux obR700V3_0b3c10_1bedac "d_1bedac"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedb0;
#pragma aux obR700V3_0b3c10_1bedb0 "d_1bedb0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedb4;
#pragma aux obR700V3_0b3c10_1bedb4 "d_1bedb4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedb8;
#pragma aux obR700V3_0b3c10_1bedb8 "d_1bedb8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedbc;
#pragma aux obR700V3_0b3c10_1bedbc "d_1bedbc"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedc0;
#pragma aux obR700V3_0b3c10_1bedc0 "d_1bedc0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedc4;
#pragma aux obR700V3_0b3c10_1bedc4 "d_1bedc4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedc8;
#pragma aux obR700V3_0b3c10_1bedc8 "d_1bedc8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedcc;
#pragma aux obR700V3_0b3c10_1bedcc "d_1bedcc"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedd0;
#pragma aux obR700V3_0b3c10_1bedd0 "d_1bedd0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedd4;
#pragma aux obR700V3_0b3c10_1bedd4 "d_1bedd4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedd8;
#pragma aux obR700V3_0b3c10_1bedd8 "d_1bedd8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1beddc;
#pragma aux obR700V3_0b3c10_1beddc "d_1beddc"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bede0;
#pragma aux obR700V3_0b3c10_1bede0 "d_1bede0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bede4;
#pragma aux obR700V3_0b3c10_1bede4 "d_1bede4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bede8;
#pragma aux obR700V3_0b3c10_1bede8 "d_1bede8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedec;
#pragma aux obR700V3_0b3c10_1bedec "d_1bedec"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedf0;
#pragma aux obR700V3_0b3c10_1bedf0 "d_1bedf0"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedf4;
#pragma aux obR700V3_0b3c10_1bedf4 "d_1bedf4"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedf8;
#pragma aux obR700V3_0b3c10_1bedf8 "d_1bedf8"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bedfc;
#pragma aux obR700V3_0b3c10_1bedfc "d_1bedfc"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee00;
#pragma aux obR700V3_0b3c10_1bee00 "d_1bee00"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee04;
#pragma aux obR700V3_0b3c10_1bee04 "d_1bee04"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee08;
#pragma aux obR700V3_0b3c10_1bee08 "d_1bee08"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee0c;
#pragma aux obR700V3_0b3c10_1bee0c "d_1bee0c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee10;
#pragma aux obR700V3_0b3c10_1bee10 "d_1bee10"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee14;
#pragma aux obR700V3_0b3c10_1bee14 "d_1bee14"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee18;
#pragma aux obR700V3_0b3c10_1bee18 "d_1bee18"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee1c;
#pragma aux obR700V3_0b3c10_1bee1c "d_1bee1c"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee20;
#pragma aux obR700V3_0b3c10_1bee20 "d_1bee20"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee24;
#pragma aux obR700V3_0b3c10_1bee24 "d_1bee24"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee28;
#pragma aux obR700V3_0b3c10_1bee28 "d_1bee28"
extern OR700V3_0b3c108 obR700V3_0b3c10_1bee2c;
#pragma aux obR700V3_0b3c10_1bee2c "d_1bee2c"
void f_0b3c10(void) {
obR700V3_0b3c10_1bed64.init(regR700V3_0b3c108,0x6,0);
obR700V3_0b3c10_1bed68.init(regR700V3_0b3c108,0x7,0);
obR700V3_0b3c10_1bed6c.init(regR700V3_0b3c108,0xc,0);
obR700V3_0b3c10_1bed70.initThird(regR700V3_0b3c108,0xf,0);
obR700V3_0b3c10_1bed74.init(regR700V3_0b3c108,0x10,0);
obR700V3_0b3c10_1bed78.init(regR700V3_0b3c108,0x12,0);
obR700V3_0b3c10_1bed7c.initThird(regR700V3_0b3c108,0x1a,0);
obR700V3_0b3c10_1bed80.init(regR700V3_0b3c108,0x1d,0);
obR700V3_0b3c10_1bed84.init(regR700V3_0b3c108,0x8a,0);
obR700V3_0b3c10_1bed88.initThird(regR700V3_0b3c108,0x8b,0);
obR700V3_0b3c10_1bed8c.init(regR700V3_0b3c108,0x8e,0);
obR700V3_0b3c10_1bed90.init(regR700V3_0b3c108,0x90,0);
obR700V3_0b3c10_1bed94.initThird(regR700V3_0b3c108,0x92,0);
obR700V3_0b3c10_1bed98.init(regR700V3_0b3c108,0x9b,0);
obR700V3_0b3c10_1bed9c.init(regR700V3_0b3c108,0x9c,0);
obR700V3_0b3c10_1beda0.initThird(regR700V3_0b3c108,0x9d,0);
obR700V3_0b3c10_1beda4.init(regR700V3_0b3c108,0x9e,0);
obR700V3_0b3c10_1beda8.init(regR700V3_0b3c108,0x9f,0);
obR700V3_0b3c10_1bedac.initThird(regR700V3_0b3c108,0xa0,0);
obR700V3_0b3c10_1bedb0.init(regR700V3_0b3c108,0xa1,0);
obR700V3_0b3c10_1bedb4.init(regR700V3_0b3c108,0xa2,0);
obR700V3_0b3c10_1bedb8.initThird(regR700V3_0b3c108,0xa3,0);
obR700V3_0b3c10_1bedbc.init(regR700V3_0b3c108,0xa4,0);
obR700V3_0b3c10_1bedc0.init(regR700V3_0b3c108,0xa5,0);
obR700V3_0b3c10_1bedc4.initThird(regR700V3_0b3c108,0xa6,0);
obR700V3_0b3c10_1bedc8.init(regR700V3_0b3c108,0xa7,0);
obR700V3_0b3c10_1bedcc.init(regR700V3_0b3c108,0xa8,0);
obR700V3_0b3c10_1bedd0.initThird(regR700V3_0b3c108,0xa9,0);
obR700V3_0b3c10_1bedd4.init(regR700V3_0b3c108,0xaa,0);
obR700V3_0b3c10_1bedd8.init(regR700V3_0b3c108,0xab,0);
obR700V3_0b3c10_1beddc.initThird(regR700V3_0b3c108,0xac,0);
obR700V3_0b3c10_1bede0.init(regR700V3_0b3c108,0xad,0);
obR700V3_0b3c10_1bede4.init(regR700V3_0b3c108,0xae,0);
obR700V3_0b3c10_1bede8.initThird(regR700V3_0b3c108,0xaf,0);
obR700V3_0b3c10_1bedec.init(regR700V3_0b3c108,0xb1,0);
obR700V3_0b3c10_1bedf0.init(regR700V3_0b3c108,0xb2,0);
obR700V3_0b3c10_1bedf4.initThird(regR700V3_0b3c108,0xb4,0);
obR700V3_0b3c10_1bedf8.init(regR700V3_0b3c108,0xb5,0);
obR700V3_0b3c10_1bedfc.init(regR700V3_0b3c108,0x15b,0);
obR700V3_0b3c10_1bee00.initThird(regR700V3_0b3c108,0x15c,0);
obR700V3_0b3c10_1bee04.init(regR700V3_0b3c108,0x15d,0);
obR700V3_0b3c10_1bee08.init(regR700V3_0b3c108,0x190,0);
obR700V3_0b3c10_1bee0c.initThird(regR700V3_0b3c108,0x191,0);
obR700V3_0b3c10_1bee10.init(regR700V3_0b3c108,0x192,0);
obR700V3_0b3c10_1bee14.init(regR700V3_0b3c108,0x193,0);
obR700V3_0b3c10_1bee18.initThird(regR700V3_0b3c108,0x194,0);
obR700V3_0b3c10_1bee1c.init(regR700V3_0b3c108,0x195,0);
obR700V3_0b3c10_1bee20.init(regR700V3_0b3c108,0x244,0);
obR700V3_0b3c10_1bee24.initThird(regR700V3_0b3c108,0x245,0);
obR700V3_0b3c10_1bee28.init(regR700V3_0b3c108,0x246,0);
obR700V3_0b3c10_1bee2c.init(regR700V3_0b3c108,0x26b,0);
}

#pragma inline_depth(3)


//@ f_0b4500
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Helden-Callback-Funktion verleiht einem Helden (p1) abhängig von Bit 0 in d_1bee2c.v
 *   entweder für 2 bis 4 Tage (amount * 0x1fa40) einen temporären Bonus von +1 auf die Eigenschaften/Werte 0x25
 *   und 0x23 (f_0d5040) oder führt eine Probe/Wirkung über f_045170 auf beide Werte aus.
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b4500(int p1)
{
    if (p1 && f_0d4a60(p1)) {
        unsigned char mask = d_1bee2c.v;
        mask &= 1;
        if (mask) {
            short amount = f_145760(2, 4);
            int duration = amount * 0x1fa40;
            d_1bc88c = 1;
            f_0d5040(p1, (short)f_0d4c80(p1), duration, 0x25, 1, 1);
            f_0d5040(p1, (short)f_0d4c80(p1), duration, 0x23, 1, 1);
            d_1bc88c = 0;
        } else {
            f_045170(p1, 0x25);
            f_045170(p1, 0x23);
        }
    }
}

//@ f_0b45c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Helden-Callback-Funktion verleiht einem Helden (p1) abhängig von Bit 1 in d_1bee2c.v
 *   entweder für 2 bis 4 Tage einen temporären Bonus von +1 auf die Eigenschaften 3 und 5 (f_0d5040) oder wendet
 *   f_045170 auf die Eigenschaften 3 und 5 an.
 * - Eingaben: Übergeben wird ein Zeiger auf die Heldenstruktur (p1).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b45c0(int p1)
{
    if (p1 && f_0d4a60(p1)) {
        unsigned char mask = d_1bee2c.v;
        mask &= 2;
        if (mask) {
            short amount = f_145760(2, 4);
            int duration = amount * 0x1fa40;
            d_1bc88c = 1;
            f_0d5040(p1, (short)f_0d4c80(p1), duration, 3, 1, 1);
            f_0d5040(p1, (short)f_0d4c80(p1), duration, 5, 1, 1);
            d_1bc88c = 0;
        } else {
            f_045170(p1, 3);
            f_045170(p1, 5);
        }
    }
}

//@ f_0b4680
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert die Ereignisse in einem Tempel oder Versammlungsort abhängig von
 *   Uhrzeit, Wochentag (f_126420) und Stadtstatus (d_1c00bc): Bei Alarm (d_1c00bc == 1) kommt es zu einem Dialog
 *   (0x2200000e) und den Kämpfen 0x88 sowie 0x89; an bestimmten Wochentagen (state == 4 mittags gegen Spende
 *   oder state == 1 abends mit anschließender Übernachtung/Heilung) erhalten alle Helden über f_0b4500 bzw.
 *   f_0b45c0 temporäre Attributsboni.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b4680(void)
{
  int f_0dbfe0(int);
  int room;
  int amount;
  int message;
  short result;
  signed char state;
  if (f_126410(C44) > 0x1d010 || f_126410(C44) < 0x7e90) {
    f_0bf730(C64, 0x2200000d);
    return 1;
  }
  if (EQI(d_1c00bc, 1)) {
    room = f_0606a0(0x120001, 0x17);
    f_0bde40(C64);
    f_0bfa20(C64, room, 0, 0x2200000e, 0);
    d_1bd91c = 1;
    result = f_08c920(0x88, 0);
    if (result == 0) {
      f_09a400();
      if (*(short *)&d_1bdaf8 > 10) {
        do {
          f_09a400();
          f_0bf730(C64, 0x2200000f);
          d_1bd91c = 1;
          result = f_08c920(0x89, 0);
        } while (result != 2);
      } else {
        f_0bf730(C64, 0x22000010);
      }
    }
    if (room != 0) operator delete((void *)((int)(((RivaRasterImage*)(room))->f_0fad20( 0))));
    return 1;
  }
  state = f_126420(C44);
  if (state == 4 && f_126410(C44) > 0xfd20 && f_126410(C44) < 0x12750) {
    if (f_0bf6f0(C64, 0x22000011) != 1) return 1;
    amount = (short)f_0dbfe0(d_1c0004) * 3;
    if (f_0de7e0(d_1c0004) < amount) {
      f_0bf730(C64, 0x22000012);
      return 1;
    }
    f_0db8b0(d_1c0004, amount);
    f_125dc0(C44, 0x12750);
    f_0bf730(C64, 0x22000013);
    f_0bf730(C64, 0x22000014);
    f_0bf730(C64, 0x22000015);
    f_039a80(d_1c0004, A(f_0b4500));
    (d_1bee2c.v) |= 1;
    return 1;
  }
  state = f_126420(C44);
  if (state == 1 && f_126410(C44) > 0x16698 && f_126410(C44) < 0x1a5e0) {
    if (f_126410(C44) > 0x190c8)
      message = f_0bf6f0(C64, 0x22000016);
    else
      message = f_0bf6f0(C64, 0x22000017);
    if (message != 1) return 1;
    if (f_126410(C44) < 0x190c8) f_125dc0(C44, 0x190c8);
    f_0bf730(C64, 0x22000018);
    f_0bf730(C64, 0x22000019);
    f_0bf730(C64, 0x2200001a);
    f_0dbeb0(d_1c0004);
    f_125dc0(C44, 0x1d010);
    f_0dbc10(d_1c0004, (short)f_1457e0(3), 5);
    f_039a80(d_1c0004, A(f_0b45c0));
    (*(volatile unsigned char *)&d_1bee2c.v) |= 2;
    return 1;
  }
  f_0bf730(C64, 0x2200001b);
  return 1;
}

//@ f_0b49b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft beim Betreten eines Gebäudes über f_0b8ef0(p1), ob es geöffnet ist,
 *   gibt bei geschlossenem Gebäude die Meldung 0x2200001c aus und zeigt beim allerersten Betreten (d_1bed84.v ==
 *   0) den Einführungstext 0x2200001d an.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 0 zurück, wenn das Gebäude geöffnet ist, und 1, wenn es geschlossen ist.
 === Ende Beschreibung === */
int f_0b49b0(int p1)
{
  int state=f_0b8ef0(p1);
  int result=0;
  if (EQ(state,0)) {
    result=1;
    f_0bf730(C64,0x2200001c);
  } else if (EQ(d_1bed84.v,0)) {
    f_0bf730(C64,0x2200001d);
    d_1bed84.v=1;
  }
  return result;
}

//@ f_0b4a10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft für ein weiteres Gebäude die Öffnungsbedingung (f_0b8ef0), verweigert
 *   bei geschlossenem Gebäude (0x2200001e) oder aktivem Stadtalarm (d_1c00bc == 1, Meldung 0x2200001f und Setzen
 *   von d_1c21a4 = 0x0b) den Zutritt und zeigt beim ersten regulären Besuch (d_1bed88.v == 0) den
 *   Einführungstext 0x22000020 an.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 0 zurück, wenn das Gebäude betreten werden darf, und 1 bei Abweisung.
 === Ende Beschreibung === */
short f_0b4a10(int p1)
{
  int state=f_0b8ef0(p1);
  int result=0;
  struct SO message;
  if (EQ(state,0)) {
    result=1;
    f_0bf730(C64,0x2200001e);
  } else {
    if (EQ(d_1c00bc,1)) {
      f_0bf730(C64,0x2200001f);
      d_1c21a4=0xb;
      result=1;
      return result;
    }
    if (EQ(d_1bed88.v,0)) {
      f_125400(&message,d_1c349c,d_1c3870,d_1c3498);
      int person=f_038c40(d_1c0004);
      message.p[1]=person;
      f_0bf730(C64,0x22000020);
      d_1bed88.v=1;
      f_1254a0(&message,0);
    }
  }
  return result;
}

//@ f_0b4af0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft vor dem Betreten eines Geschäfts oder Hauses, ob Stadtalarm herrscht
 *   (d_1c00bc == 1, Meldung 0x22000024) oder die aktuelle Uhrzeit außerhalb der Öffnungszeiten (f_0b3950,
 *   Meldung 0x1b000007) liegt, und delegiert andernfalls an die Standard-Ortsroutine f_0b8d40.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei geschlossener Tür/Abweisung oder den Rückgabewert von f_0b8d40 zurück.
 === Ende Beschreibung === */
int f_0b4af0(int p1)
{
  int c, a;
  if (EQ(d_1c00bc, 1)) {
    f_0bf730(C64, 0x22000024);
    return 1;
  }
  c = f_126420(C44);
  a = *(short *)(p1 + 0x32 + c * 2) * 0x1518;
  c = f_126420(C44);
  if (f_0b3950(a, *(short *)(p1 + 0x40 + c * 2) * 0x1518) == 0) {
    f_0bf730(C64, 0x1b000007);
    return 1;
  }
  return f_0b8d40(p1);
}

//@ f_0b4bc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft die Öffnungszeiten (f_0b3950) und den Stadtalarm (d_1c00bc), führt bei
 *   geöffnetem Gebäude f_0b8d40(p1) aus und setzt anschließend das Ereignisflag d_1bed68.v = 1, falls bestimmte
 *   Questbedingungen (d_1c00ac == 1, d_1bca84 == 1) erfüllt sind, der Gruppe aber der Gegenstand 0x16b noch
 *   fehlt.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei Abweisung oder das Ergebnis von f_0b8d40 zurück.
 === Ende Beschreibung === */
int f_0b4bc0(int p1)
{
  signed char c;
  short s;
  int a, r;
  d_1bed68.v = 0;
  c = f_126420(C44);
  a = *(short *)(p1 + 0x32 + c * 2) * 0x1518;
  if (f_0b3950(a, *(short *)(p1 + 0x40 + f_126420(C44) * 2) * 0x1518) == 0) {
    r = 1;
    f_0bf730(C64, 0x1b000007);
  } else {
    if (EQ(d_1c00bc, 1)) {
      r = 1;
      f_0bf730(C64, 0x22000024);
    } else {
      r = f_0b8d40(p1);
      if (EQ(d_1c00ac, 1) && EQ(d_1bee1c.v, 0) && EQ(d_1bca84, 1) && EQ(d_1bed80.v, 0))
        if ((s = f_0d54f0(d_1c0004, 0x16b)) == -1) d_1bed68.v = 1;
    }
  }
  return r;
}

//@ f_0b4d00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion verzweigt beim Passieren des Stadttors je nach aktivem Kapitel-/Torzustand
 *   (d_1c00b0 == 1 oder d_1c00c4 == 1 bei d_1bed90.v == 0) in die Torkontroll-Dialoge f_0b30f0 bzw. f_0b2f30.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 (bzw. das Ergebnis von f_0b2f30) zurück, wenn ein Tordialog ausgelöst
 *   wurde, und sonst 0.
 === Ende Beschreibung === */
int f_0b4d00(void)
{
 int r = 0;
 short state = f_0de820(d_1c0004);
 if (state != 0) *(signed char *)&d_1c01d8 = 1;
 if (EQ(d_1c00b0,1)) {
  f_0b30f0();
  r = 1;
 } else if (EQ(d_1c00c4,1) && EQ(d_1bed90.v,0)) {
  if (f_0bf6f0(C64,0x22000032) == 1) r = f_0b2f30();
  else r = 1;
 }
 return r;
}
//@ f_0b4d90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion ruft zunächst die Standard-Ortsbehandlung f_0b8d40(p1) auf und prüft bei
 *   erfolgreichem Betreten, ob es Nacht ist (vor 06:00 Uhr oder nach 0x1d010), um in diesem Fall die Meldung
 *   0x0f000001 auszugeben und das Nachtflag d_1bed64.v = 1 zu setzen.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0b8d40(p1) zurück.
 === Ende Beschreibung === */
int f_0b4d90(int p1)
{
    int result = f_0b8d40(p1);
    if (result == 0) {
        if (((d_1c01f0 != 1) ? 1 : 0) || ((d_1bed94.v != 0) ? 1 : 0)) {
            if (f_126410(C44) > 0x1d010 || f_126410(C44) < 21600) {
                f_0bf730(C64, 0x0f000001);
                d_1bed64.v = 1;
            } else {
                d_1bed64.v = 0;
            }
        }
    }
    return result;
}

//@ f_0b4e10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft anhand der im Ortsobjekt (p1) hinterlegten Öffnungszeiten (+0x32 und
 *   +0x40), ob das Gebäude geöffnet ist (f_0b3950), gibt bei geschlossener Tür die Meldung 0x22000059 aus und
 *   ruft andernfalls f_0b8d40(p1) auf.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei geschlossener Tür oder das Ergebnis von f_0b8d40(p1) zurück.
 === Ende Beschreibung === */
unsigned f_0b4e10(int p1)
{
    signed char index;
    int first, last;
    unsigned result;
    index = f_126420(C44);
    first = *(short *)(p1 + 0x32 + index * 2) * 0x1518;
    index = f_126420(C44);
    last = *(short *)(p1 + 0x40 + index * 2) * 0x1518;
    result = 0;
    if (f_0b3950(first, last) == 0) {
        result = 1;
        f_0bf730(C64, 0x22000059);
    }
    if (result == 0)
        result = f_0b8d40(p1);
    return result;
}

//@ f_0b4eb0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft vor dem Betreten eines besonderen Gebäudes nacheinander Stadtalarm
 *   (d_1c00bc == 1, Text 0x2200005a), Öffnungszeiten (f_0b3950, Text 0x2200005b) und Sperrflag d_1c00a4 (Text
 *   0x2200005c), startet bei d_1c00b0 == 1 die Sonderszene f_0eca40() und ruft sonst f_0b8d40(p1) auf.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei Abweisung oder Sonderereignis bzw. sonst den Rückgabewert von
 *   f_0b8d40(p1) zurück.
 === Ende Beschreibung === */
int f_0b4eb0(int p1)
{
  int c, a;
  signed char flag;
  flag = d_1c00bc;
  if ((int)flag == 1) {
    f_0bf730(C64, 0x2200005a);
    return 1;
  }
  c = f_126420(C44);
  a = *(short *)(p1 + 0x32 + c * 2) * 0x1518;
  c = f_126420(C44);
  if (f_0b3950(a, *(short *)(p1 + 0x40 + c * 2) * 0x1518) == 0) {
    f_0bf730(C64, 0x2200005b);
    return 1;
  }
  flag = d_1c00a4;
  if ((int)flag == 1) {
    f_0bf730(C64, 0x2200005c);
    return 1;
  }
  flag = d_1c00b0;
  if ((int)flag == 1) {
    f_0eca40();
    f_0b8a00(p1, -1);
    return 1;
  }
  return f_0b8d40(p1);
}

//@ f_0b4fc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft die Öffnungszeiten des Gebäudes (p1) über f_0b3950, zeigt außerhalb der
 *   Öffnungszeiten den Text 0x2200005b an und ruft innerhalb der Öffnungszeiten f_0b8d40(p1) auf.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei geschlossener Tür oder das Ergebnis von f_0b8d40(p1) zurück.
 === Ende Beschreibung === */
int f_0b4fc0(int p1)
{
  int c, a;
  c = f_126420(C44);
  a = *(short *)(p1 + 0x32 + c * 2) * 0x1518;
  c = f_126420(C44);
  if (f_0b3950(a, *(short *)(p1 + 0x40 + c * 2) * 0x1518) == 0) {
    f_0bf730(C64, 0x2200005b);
    return 1;
  }
  return f_0b8d40(p1);
}

//@ f_0b5060
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert einen geheimen Treffpunkt bzw. Übergang: Ist die Vorbedingung
 *   (d_1bed7c.v == 1 und d_1bee18.v == 0) zur richtigen Nachtzeit erfüllt, startet sie die Sequenz f_0eb230();
 *   nach deren Abschluss (d_1bee18.v == 1) ermöglicht sie den Wechsel zwischen den Bereichen 0 (Position 6000)
 *   und 2 (Position 0x1782) über f_0dd7f0.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b5060(void)
{
  if (EQ(d_1bed7c.v, 1) && EQ(d_1bee18.v, 0)) {
    if (EQ(d_1bed70.v, 1) || f_1264f0(C44, 0x1e528, 0x5460) == 1) {
      f_0eb230();
      goto done;
    }
  }
  if (EQ(d_1bee18.v, 1)) {
    if ((int)f_0de820(d_1c0004) == 0) {
      if (EQ(d_1bed74.v, 1)) {
        if (f_0bf6f0(C64, 0x22000088) != 1) goto done;
        f_0dd7f0(d_1c0004, 2, 0x1782);
        return 1;
      }
      f_0bf730(C64, 0x22000089);
      goto done;
    }
    if (f_0bf6f0(C64, 0x22000087) != 1) goto done;
    f_0dd7f0(d_1c0004, 0, 6000);
    return 1;
  } else {
    f_0bf730(C64, 0x22010011);
  }
done:
  return 1;
}

//@ f_0b5180
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion ermöglicht bei freigeschaltetem Flag d_1bed9c.v == 1 über den Auswahldialog
 *   0x2200008a den Wechsel in den Kartenbereich 1 (Position 0x1395, z. B. Kanalisation oder Untergrund) über
 *   f_0dd7f0 und zeigt andernfalls die Abweisungsmeldung 0x2200008d an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b5180(void)
{
  short sVar1;
  if (EQ(d_1bed9c.v, 1)) {
    sVar1 = f_0bf820(C64, 0x2200008a, 2, 0x2200008b, 0x2200008c);
    if (sVar1 == 1) f_0dd7f0(d_1c0004, 1, 0x1395);
  } else {
    f_0bf730(C64, 0x2200008d);
  }
  return 1;
}

//@ f_0b51f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert eine dreistufige nächtliche Begegnung (zwischen 0x1d010 und 0x5460):
 *   In der ersten Nacht (d_1beda4.v == 0) findet ein Gespräch (0x2200008f-0x2200009a) statt, bei dem der
 *   Dateiname eines ausgewählten Helden in die Ressourcendatei 0x40220069 gespeichert wird; in einer späteren
 *   Nacht (d_1beda8.v == 0) folgt die Fortsetzung (0x2200009b-0x220000a2 mit f_0b3240), und sobald die Gruppe
 *   den Gegenstand 0x16c besitzt (d_1bedac.v == 0), wird der Abschlussdialog (0x220000a3-0x220000a4) abgespielt.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b51f0(void)
{
  int f_0dbfe0(int);
  unsigned short count_with_hint(int, int);
  #pragma aux count_with_hint "f_0dbfe0" parm [eax] [edx] value [eax] modify exact [eax]
  int first_with_zero(int, int);
  #pragma aux first_with_zero "f_038c40" parm [eax] [ebx] value [eax] modify exact [eax]
  extern volatile int group790;
  #pragma aux group790 "d_1c0004";
  SO dialogs[3];
  short count;
  if (EQI(d_1beda0.v, 0)) {
    f_0bf730(C64, 0x2200008e);
    d_1beda0.v = 1;
  }
  if (f_126410(C44) > 0x1d010 || f_126410(C44) < 0x5460) {
    if (EQI(d_1beda4.v, 0)) {
      f_125400(&dialogs[0], d_1c349c, d_1c3870, d_1c3498);
      short raw_count = count_with_hint(group790, 9);
      count = raw_count;
      int first = first_with_zero(d_1c0004, 0);
      int other = f_0dd3a0(d_1c0004, 9, 0);
      dialogs[0].p[1] = first;
      f_0bf730(C64, 0x2200008f);
      f_0bf730(C64, 0x22000090);
      if ((short)raw_count > 1 && other && other != first) {
        dialogs[0].p[2] = other;
        f_0bf730(C64, 0x22000091);
      }
      if (f_0390a0(d_1c0004)) {
        short kind;
        do {
          if (f_0bf6f0(C64, 0x22000092) != 1) goto selection_done;
          other = f_038e10(d_1c0004, 0x22000093);
        } while (!other || (kind = (short)f_03cd00(other, 0)) < 0);
        if (kind == 0x13) {
          dialogs[0].p[3] = other;
          f_0bf730(C64, 0x22000094);
        } else {
          f_0bf730(C64, 0x22000095);
        }
      }
selection_done:
      f_0bf730(C64, 0x22000096);
      int recipient;
      if ((short &)count > 1) {
        recipient = f_038be0(d_1c0004);
        dialogs[0].p[4] = recipient;
        f_0bf730(C64, 0x22000097);
      } else {
        dialogs[0].p[4] = first;
        recipient = first;
        f_0bf730(C64, 0x22000098);
      }
      f_0bf730(C64, 0x22000099);
      if ((volatile short &)count > 1) f_0bf730(C64, 0x2200009a);
      ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1448b0( 0x40220069, 0x201);
      int data = ((int)(f_042320((struct hero *)(recipient))));
      ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( data), 0x10)));
      ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1449a0();
      d_1beda4.v = 1;
      d_1bedb0.v = 0xc;
      f_1254a0(&dialogs[0], 0);
    } else if (EQI(d_1beda8.v, 0) && EQI(d_1bedb0.v, 0)) {
      int first, speaker;
      f_125400(&dialogs[2], d_1c349c, d_1c3870, d_1c3498);
      short n = f_0dbfe0(d_1c0004);
      speaker = f_0b3240();
      first = f_038c40(d_1c0004);
      dialogs[2].p[1] = first;
      dialogs[2].p[2] = speaker;
      f_0bf730(C64, 0x2200009b);
      f_0bf730(C64, 0x2200009c);
      f_0bf730(C64, 0x2200009d);
      if ((short)(n & 0xffff) > 1) f_0bf730(C64, 0x2200009e);
      else f_0bf730(C64, 0x2200009f);
      f_0bf730(C64, 0x220000a0);
      f_0bf730(C64, 0x220000a1);
      if (n > 1) f_0bf730(C64, 0x220000a2);
      d_1beda8.v = 1;
      d_1bedb0.v = 0xc;
      f_1254a0(&dialogs[2], 0);
    } else if (EQI(d_1bedac.v, 0) && EQI(d_1bedb0.v, 0)) {
      if ((short)f_0d54f0(d_1c0004, 0x16c) != -1) {
        f_125400(&dialogs[1], d_1c349c, d_1c3870, d_1c3498);
        int speaker = f_0b3240();
        dialogs[1].p[1] = speaker;
        f_0bf730(C64, 0x220000a3);
        f_0bf730(C64, 0x220000a4);
        d_1bedac.v = 1;
        f_1254a0(&dialogs[1], 0);
      }
    }
  }
  return 1;
}

//@ f_0b55e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion wickelt einen Handel bzw. eine Bestechung ab, wenn die Gruppe den Gegenstand
 *   0x1c7 und mindestens 60 Dukaten (6000 Heller) besitzt: Im Dialog 0x220000a6 kann der Spieler über
 *   Feilschen-Talentproben (f_044c90 auf Talent 0x17) oder direkt zahlen, woraufhin 60 Dukaten (f_0db8b0) sowie
 *   Gegenstand 0x1c7 (f_0dd100) abgezogen und vier neue Gegenstände (0x36, 0x0f, 0x6f, 0x06) über f_0dcf00 an
 *   die Gruppe übergeben werden.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Verhandlung scheitert oder das Gebäude gesperrt ist
 *   (+0x2e != 0), und sonst 0.
 === Ende Beschreibung === */
int f_0b55e0(int p1) {
 short pruefe650(int,int,int);
 #pragma aux pruefe650 "f_044c90"
 int r=0; SO o; short choice;
 if (*(int *)(p1+0x2e)!=0) r=1;
 else if ((short)f_0d54f0(d_1c0004,0x1c7)!=-1 && (unsigned)f_0de7e0(d_1c0004)>=6000 && f_0bf6f0(C64,0x220000a5)==1) {
  f_125400(&o,d_1c349c,d_1c3870,d_1c3498);
  choice=-1; int person=f_039320(d_1c0004,0x17); int paid=0; short amount;
  o.p[1]=person;
  while ((short)choice==-1) {
   int selected=f_0bf820(C64,0x220000a6,3,0x220000a7,0x220000a8,0x220000a9); choice=selected;
   switch((unsigned short)selected) {
   case 1:
    amount=f_0de7f0(d_1c0004); amount*=2; amount+=6;
    if ((int)pruefe650(person,0x17,(signed char)amount)>0) paid=1;
    else { f_0bf730(C64,0x220000aa);r=1;f_0b8a00(d_1bf1ac,-1); }
    break;
   case 2:
    amount=f_0de7f0(d_1c0004); amount*=2; amount+=3;
    if ((int)pruefe650(person,0x17,(signed char)amount)>0) paid=1; else {
    f_0bf730(C64,0x220000ab);r=1;f_0b8a00(p1,-1); } break;
   case 3: paid=1;break;
   }
   if (paid==1) {
    f_0bf730(C64,0x220000ac);f_0bf730(C64,0x220000ad);f_0db8b0(d_1c0004,6000);
    f_0dcf00(d_1c0004,0x36,paid);f_0dcf00(d_1c0004,0xf,paid);f_0dcf00(d_1c0004,0x6f,paid);f_0dcf00(d_1c0004,6,paid);
   }
   f_0dd100(d_1c0004,0x1c7);
  }
  f_1254a0(&o,0);
 }
 return r;
}

//@ f_0b5820
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft beim Betreten eines Hauses das Sperrflag d_1bcaa0 (weist bei d_1c00c0
 *   == 0 je nach Tages-/Nachtzeit mit 0x22000001 oder 0x22010001 ab) und führt andernfalls f_0b8d40(p1) aus,
 *   wobei nachts zusätzlich die Meldung 0x22010002 ausgegeben und d_1bed64.v = 1 gesetzt wird.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 bei Abweisung oder das Ergebnis von f_0b8d40(p1) zurück.
 === Ende Beschreibung === */
int f_0b5820(int p1)
{
  int result;
  if (EQ(d_1bcaa0, 1) && EQ(d_1c00c0, 0)) {
    if (f_126410(C44) > 0x1d010 || f_126410(C44) < 21600)
      f_0bf730(C64, 0x22000001);
    else
      f_0bf730(C64, 0x22010001);
    result = 1;
  } else {
    result = f_0b8d40(p1);
    if (result == 0) {
      if (f_126410(C44) > 0x1d010 || f_126410(C44) < 21600) {
        f_0bf730(C64, 0x22010002);
        d_1bed64.v = 1;
      } else {
        d_1bed64.v = 0;
      }
    }
  }
  return result;
}

//@ f_0b58f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert den abendlichen Besuch im Badehaus bzw. Etablissement (zwischen
 *   0x17bb0 und 0x1a5e0 Uhr): Gegen Zahlung von 100 Heller beim ersten Mal bzw. 50 Heller bei Folgebesuchen
 *   (d_1bed78.v) verbringt die Gruppe dort den Abend bis 0x1d010 Uhr, erhält je nach Besuchszähler (d_1bca7c ==
 *   3, 5, 10) besondere Kommentare (0x2201000c-0x2201000f) und hat eine Chance, dass alle Helden über f_0b33d0
 *   ihre gesellschaftlichen Talente steigern.
 * - Eingaben: Übergeben wird ein Zeiger auf das Ortsobjekt (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Abendereignis stattfand, oder sonst den Rückgabewert von
 *   f_0b8d40(p1).
 === Ende Beschreibung === */
int f_0b58f0(int p1)
{
  struct SO o;
  short preis;
  short antwort;
  int text, person, naechste;
  int ergebnis;

  if (f_126410(C44) > 0x17bb0 && f_126410(C44) < 0x1a5e0) {
    ergebnis = 1;
    preis = 50;
    if (EQ(d_1bed78.v, 1)) {
      if (EQ(d_1bca7c, 0)) f_0bf730(C64, 0x22010004);
      else f_0bf730(C64, 0x22010005);
    } else {
      f_0bf730(C64, 0x22010006);
      preis = 100;
    }
    if (f_0de7e0(d_1c0004) >= preis) {
      antwort = f_0bf820(C64, 0x22010007, 2, 0x22010008, 0x22010009);
    } else {
      f_0bf730(C64, 0x2201000a);
      antwort = -1;
    }
    if (antwort == 1) {
      d_1bed78.v = 1;
      f_0db8b0(d_1c0004, preis);
      f_125dc0(C44, 0x1d010);
      if (EQ(d_1bca7c, 0)) {
        f_0bf730(C64, 0x2201000b);
      } else {
        f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
        person = f_039ac0(d_1c0004, A(f_0b3300));
        if (EQ(d_1bca7c, 3) && person) {
          o.p[1] = person;
          text = 0x2201000c;
        } else {
          person = f_039ac0(d_1c0004, A(f_0b3330));
          if (EQ(d_1bca7c, 5) && person) {
            o.p[1] = person;
            text = 0x2201000d;
          } else {
            person = f_039ac0(d_1c0004, A(f_0b3360));
            if (EQ(d_1bca7c, 10) && person) {
              o.p[1] = person;
              text = 0x2201000e;
            } else text = 0x2201000f;
          }
        }
        f_0bf730(C64, text);
        f_1254a0(&o, 0);
      }
      if ((short)f_1457e0(++d_1bca7c) == 1) {
        person = f_038c40(d_1c0004);
        do {
          if (f_0d4a60(person)) f_0b33d0(person);
          naechste = f_0391b0(d_1c0004, person);
          person = naechste;
        } while (naechste != f_038c40(d_1c0004));
      }
    }
  } else {
    if (EQ(d_1bed78.v, 1) && f_126410(C44) > 0x1a5e0 && f_126410(C44) < 0x1d010) {
      ergebnis = 1;
      f_0bf730(C64, 0x22010010);
    } else {
      ergebnis = f_0b8d40(p1);
    }
  }
  return ergebnis;
}

//@ f_0b5bc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion gibt den Hinweis- bzw. Abweisungstext 0x22010011 in einem Textfenster aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b5bc0(void)
{
  f_0bf730(C64, 0x22010011);
  return 1;
}

//@ f_0b5be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion gibt den Hinweis- bzw. Abweisungstext 0x22010012 in einem Textfenster aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0b5be0(void)
{
  f_0bf730(C64, 0x22010012);
  return 1;
}
