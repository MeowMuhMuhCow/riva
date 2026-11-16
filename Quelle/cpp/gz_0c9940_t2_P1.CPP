/* === Beschreibung (Katalog) ===
 * Einheit gz_0c9940_t2
 *
 * Diese Einheit implementiert den zweiten Teil der Dungeon-Logik für die dritte Ebene der Zwergenmine (0x11,
 * Text-Overlay 0x35), darunter weitere Einsturz- und Fallenereignisse, Teleporter-Übergänge, das Betätigen der
 * Buchstaben-Torriegel (0x1f49, 0x1f4a, 0x1f4d) sowie den zweistufigen Endkampf samt Endsequenzen (0x803003f,
 * 0x8030040).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 29/36 gleich (suche.py 26.10.2026, Basis gz_0c9940_t2_P1.CPP)
// gz_0c9940.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C9940-0x0CCF00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0

                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0

                                   // reg eax stapel 0
int f_043ca0(int p1);                                   // reg eax stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_045210(int p1);                                   // reg eax stapel 0
int f_0452a0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060740(int p1, int p2);
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0ccf00();                                         // reg - stapel 0
int f_0cd000(int p1, int p2);                           // reg edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dcf00(int p1, int p2, int p3);
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0de890(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0f2720(int p1, int p2);
int f_0f2720(int p1, int p2, int p3);
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
short f_145850(int p1, int p2, int p3);
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149a14(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a9820;                    // 0x1A9820
extern int d_1bb380;                    // 0x1BB380
extern int d_1bb3c8;                    // 0x1BB3C8
extern int d_1bf230;                    // 0x1BF230
extern signed char d_1bf2f8;                    // 0x1BF2F8
extern int d_1bf2f9;                    // 0x1BF2F9
extern int d_1bf2fc;                    // 0x1BF2FC
extern int d_1bf2fd;                    // 0x1BF2FD
extern signed char d_1bf300;                    // 0x1BF300
extern int d_1bf301;                    // 0x1BF301
extern int d_1bf304;                    // 0x1BF304
extern int d_1bf305;                    // 0x1BF305
extern signed char d_1bf308;                    // 0x1BF308
extern int d_1bf309;                    // 0x1BF309
extern int d_1bf30c;                    // 0x1BF30C
extern int d_1bf30d;                    // 0x1BF30D
extern signed char d_1bf310;                    // 0x1BF310
extern int d_1bf311;                    // 0x1BF311
extern signed char d_1bf314;                    // 0x1BF314
extern int d_1bf315;                    // 0x1BF315
extern signed char d_1bf318;                    // 0x1BF318
extern int d_1bf319;                    // 0x1BF319
extern int d_1bf31c;                    // 0x1BF31C
extern int d_1bf31d;                    // 0x1BF31D
extern int d_1bf320;                    // 0x1BF320
extern int d_1bf321;                    // 0x1BF321
extern int d_1bf324;                    // 0x1BF324
extern int d_1bf325;                    // 0x1BF325
extern int d_1bf328;                    // 0x1BF328
extern int d_1bf329;                    // 0x1BF329
extern int d_1bf32c;                    // 0x1BF32C
extern int d_1bf32d;                    // 0x1BF32D
extern int d_1bf330;                    // 0x1BF330
extern int d_1bf331;                    // 0x1BF331
extern int d_1bf334;                    // 0x1BF334
extern int d_1bf335;                    // 0x1BF335
extern int d_1bf338;                    // 0x1BF338
extern int d_1bf339;                    // 0x1BF339
extern int d_1bf33c;                    // 0x1BF33C
extern int d_1bf33d;                    // 0x1BF33D
extern int d_1bf340;                    // 0x1BF340
extern int d_1bf341;                    // 0x1BF341
extern int d_1bf344;                    // 0x1BF344
extern int d_1bf345;                    // 0x1BF345
extern signed char d_1bf348;                    // 0x1BF348
extern int d_1bf349;                    // 0x1BF349
extern signed char d_1bf34c;                    // 0x1BF34C
extern int d_1bf34d;                    // 0x1BF34D
extern unsigned char d_1bf350;                    // 0x1BF350
extern int d_1bf351;                    // 0x1BF351
extern signed char d_1bf354;                    // 0x1BF354
extern int d_1bf355;                    // 0x1BF355
extern int d_1bf358;                    // 0x1BF358
extern int d_1bf35a;                    // 0x1BF35A
extern int d_1bf35c;                    // 0x1BF35C
extern int d_1bf35e;                    // 0x1BF35E
extern int d_1bf360;                    // 0x1BF360
extern int d_1bf36c;                    // 0x1BF36C
extern int d_1bf370;                    // 0x1BF370
extern int d_1c0004;                    // 0x1C0004
extern int d_1c040c;                    // 0x1C040C
extern int d_1c0412;                    // 0x1C0412
extern int d_1c0416;                    // 0x1C0416
extern int d_1c0428;                    // 0x1C0428
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c2132;                    // 0x1C2132
extern int d_1c2134;                    // 0x1C2134
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c21b5;                    // 0x1C21B5
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
int f_147323b(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#define A64 ((int)&d_1c2c64)
#define A2E ((int)&d_1c2edc)
#define PA(o,k) (*(int *)(*(int *)((o) + 4) + (k)))
#define BT(m) (((int)d_1bf350 & (m)) == 0)
#define GTI(x,v) (((x)>(v))?1:0)
#define EQI(x,v) (((x)==(v))?1:0)
#pragma aux f_147323 modify [esp];
#define DEC(n) (--(n))
#define SWB(v,x49,x4a) switch (v) { case 0x1f4a: x4a; break; case 0x1f49: x49; break; }
void f_0cbb40(int p1, int p2);
void f_0ca7c0(int p1);
void f_0cbda0(int p1, int p2);
void f_0cc010(int p1, int p2, int p3);
void f_0cc7a0(int p1, int p2);
int f_0cc8c0(int p1);

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0cab30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt beim ersten Betreten (d_1bf300 == 0) eine Fallenprüfung durch, bei der ein
 *   einzelner Held sofort stirbt (0x35000143), während eine mehrköpfige Gruppe über eine erleichterte
 *   Sinnesschärfe-Probe (0x33, -3) und eine Attributsprobe auf Eigenschaft 3 (+4) der Gefahr entgehen kann oder
 *   andernfalls Schaden durch f_0ca7c0 erleidet.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cab30(void)
{
  char obj[0x3c]; int l1c, u3;
  int p1, l20;
  short s1, s2;
  f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  p1 = f_038c40(d_1c0004);
  PA(obj, 4) = p1;
  if (EQB(d_1bf300, 0)) {
    { int t_ = (int)(d_1c0004); s1 = f_0db9a0(t_); }
    if (s1 == 1) {
      f_0bf6c0(A64, 5);
      { int snd; f_147323(A2E, 0x35003b, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1); }
      f_0bf730(A64, 0x35000143);
      f_0bf680(A64);
      s1 = f_042960((struct hero *)(p1));
      f_044300(p1, s1);
    } else {
      { unsigned short seed; s1 = f_044c90(p1, 0x33, (signed char)(seed = 0xfffd)); }
      int b = 0;
      if (s1 > 1) b = 1;
#if FIX_R054
      if (b == 1) {
#else
      if (!b) {
#endif
        l1c = f_039320(d_1c0004, 0x32);
        u3 = f_039320(d_1c0004, 0x33);
        l20 = f_039660(d_1c0004, 3);
        f_0bf730(A64, 0x3500013e);
        f_0bf730(A64, 0x3500013f);
        s2 = f_044900(p1, 3, 4);
        if (s2 > 0) b = 1;
        if (b == 1) {
          PA(obj, 4) = l1c;
          PA(obj, 8) = u3;
          f_0bf730(A64, 0x35000140);
          PA(obj, 4) = l20;
          f_0bf730(A64, 0x35000141);
          goto L29;
        }
        { int snd; f_147323(A2E, 0x35003b, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1); }
        PA(obj, 4) = p1;
        f_0bf730(A64, 0x35000142);
      } else {
        f_0bf6c0(A64, 5);
        f_0bf730(A64, 0x35000143);
        f_0bf680(A64);
      }
      f_0ca7c0(p1);
    }
  L29:
    d_1bf300 = 1;
  }
  f_1254a0((int)obj, 0);
}

//@ f_0cad50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Weiterleitungsfunktion löst die Fallenroutine f_0cbda0(p1, 2) aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cad50(int p1)
{
  f_0cbda0(p1, 2);
}

//@ f_0cad60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft die Hindernis- und Überquerungsroutine f_0cc010 auf und übergibt abhängig vom
 *   Zustand d_1bf308 == 2 entweder das Zielfeld 0x15fb oder 0x16c3 (sowie 0x1267).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cad60(int p1)
{
  int p2, p3;
  if (EQI(d_1bf308, 2)) {
    p3 = 0x1267;
    p2 = 0x15fb;
  } else {
    p3 = 0x1267;
    p2 = 0x16c3;
  }
  f_0cc010(p1, p2, p3);
}

//@ f_0cada0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft die Dialog- und Ereignisroutine f_0cc7a0(p1, 0x350028) auf.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cada0(int p1)
{
  f_0cc7a0(p1, 0x350028);
}

//@ f_0cadb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion würfelt für den Helden p1 insgesamt p2 Treffer zu je 1W6 + 6 - Rüstungsschutz
 *   (mindestens 1 Schadenspunkt pro Treffer) aus und zieht die Summe über f_044300 von seiner Lebensenergie ab.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur sowie die Anzahl der Schadenswürfe p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cadb0(int p1, short p2)
{
  short c;
  short tot, r, i;
  c = f_0423c0((struct hero *)(p1));
  tot = 0;
  for (i = 0; i < p2; i++) {
    r = f_1457e0(6) + 6 - c;
    if (r <= 0) r = 1;
    tot += r;
  }
  f_044300(p1, tot);
}

//@ f_0cae10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion durchsucht die Gruppenplätze rückwärts von Index 6 bis 0 und ermittelt den
 *   letzten handlungsfähigen Helden der Gruppe.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die Heldenstruktur des hintersten handlungsfähigen
 *   Gruppenmitglieds (oder 0, falls niemand handlungsfähig ist).
 === Ende Beschreibung === */
int f_0cae10(void)
{
  short s;
  int r, p;
  r = 0;
  for (s = 6; s >= 0 && r == 0; s--) {
    p = f_0de7d0(d_1c0004, s);
    if (p != 0) {
      if (f_0d4a60(p) != 0) {
        r = p;
      }
    }
  }
  return r;
}

//@ f_0cae50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst beim ersten Betreten (d_1bf310 == 0) einen Hinterhalt oder Steinschlag (0x35003b)
 *   aus, der bei einer Gruppe den Anführer mit 3 Treffern und das hinterste Gruppenmitglied (f_0cae10) mit 4
 *   Treffern über f_0cadb0 verletzt (0x3500016d) oder einen einzelnen Helden dreimal trifft (0x35000170).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cae50(void)
{
    struct Heal899 {
        static inline void run(int actor, short count) {
            // haelt die Stapelplatz-Reihenfolge wie im Original
            (int &)actor = actor;
            short total = 0;
            short c = f_0423c0((struct hero *)(actor));
            short i, roll;
            for (i = 0; i < count; ++i) {
                roll = f_1457e0(6) + 6 - c;
                if (roll <= 0) roll = 1;
                total += roll;
            }
            f_044300(actor, total);
        }
    };
  char obj[0x3c]; int v, u; short s;
  if (EQI(*(volatile signed char *)&d_1bf310, (signed char)0)) {
    f_147323(A2E, 0x35003b, 0x7fff, 0x8000, (v = *(int *)&d_1a9820), 0, 1);
    f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    s = f_0db9a0(d_1c0004);
    if (s > 1) {
      u = f_038c40(d_1c0004);
      v = f_0cae10();
      PA(obj, 4) = u;
      PA(obj, 8) = v;
      f_0bf730(A64, 0x3500016d);
      f_0cadb0(u, 3);
      f_0cadb0(v, 4);
      d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt die Ladereihenfolge wie im Original
      s = f_0db9a0(d_1c0004);
      if (s <= 0) goto L84;
      u = f_039420(d_1c0004, 0xf);
      PA(obj, 4) = u;
      f_0bf730(A64, 0x3500016e);
      f_0bf730(A64, 0x3500016f);
    } else {
      u = f_038c40(d_1c0004);
      PA(obj, 4) = u;
      f_0bf730(A64, 0x35000170);
      Heal899::run(u, 3);
      int t_299 = f_0d4a60(u);
      if (t_299 == (unsigned short)0) goto L84;
      f_0bf730(A64, 0x35000171);
      f_0bf730(A64, 0x35000172);
    }
    d_1bf310 = 1;
  L84:
    f_1254a0((int)obj, 0);
  }
}

//@ f_0cb0a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet das Interaktionsobjekt 0x1f44 (d_1bf314), fragt den Spieler nach einer
 *   Betätigung (0x35000173 bis 0x35000175) und öffnet das Objekt erst dann unter Auslösung eines kleinen
 *   Schadens (f_044850(b, 2, 5), Sound 0x35003a), wenn zuvor das Hauptmechanismus-Flag d_1bf318 aktiviert wurde.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
#define SDECL short
#define SEQ1(v) ((v) == 1)
void f_0cb0a0(void)
{
  char obj[0x3c];
  int a, b, c;
  SDECL s;
  f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  a = f_039660(d_1c0004, 0xb);
  b = f_039320(d_1c0004, 9);
  s = -1;
  c = f_039b00(d_1c0004, a, 0x1d);
  if (EQB(d_1bf314, 0)) {
    s = f_0db9a0(d_1c0004);
    if (s > 1) {
      PA(obj, 4) = a;
      PA(obj, 8) = c;
      s = f_0bf6f0(A64, 0x35000173);
    } else {
      PA(obj, 4) = a;
      s = f_0bf6f0(A64, 0x35000174);
    }
    d_1bf314 = 1;
  } else if (EQI(d_1bf314, 1)) {
    s = f_0bf6f0(A64, 0x35000175);
  } else {
    f_0bf730(A64, 0x35000178);
  }
  if (s == (short)1) {
    if (EQI(d_1bf318, 0)) {
      PA(obj, 4) = b;
      f_0bf730(A64, 0x35000176);
    } else {
      { int snd; f_147323(A2E, 0x35003a, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1); }
      PA(obj, 4) = b;
      f_0bf730(A64, 0x35000177);
      f_044850(b, 2, 5);
      f_060770(0x1f44, 0);
      f_0607e0(0x1f44, 1);
      f_0bf730(A64, 0x35000178);
      d_1bf314 = 2;
    }
  }
  f_1254a0((int)obj, 0);
}

//@ f_0cb250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft die Überquerungsroutine f_0cc010 auf und wählt abhängig von d_1bf308 == 2 das
 *   Zielfeld 0x164d oder 0x1585 (mit 0x1267).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb250(int p1)
{
  int p2, p3;
  if (EQI(d_1bf308, 2)) {
    p3 = 0x1267;
    p2 = 0x164d;
  } else {
    p3 = 0x1267;
    p2 = 0x1585;
  }
  f_0cc010(p1, p2, p3);
}

//@ f_0cb290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft die Dialog- und Ereignisroutine f_0cc7a0(p1, 0x35002a) auf.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb290(int p1)
{
  f_0cc7a0(p1, 0x35002a);
}

//@ f_0cb2a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst beim ersten Betreten (d_1bf2f8 == 0) die Fallenroutine f_0cbb40(p1, 1) aus und
 *   versetzt die Gruppe anschließend (d_1bf2f8 == 1) auf das Feld 0x146b.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb2a0(int p1)
{
  if (EQI(d_1bf2f8, 0)) {
    f_0cbb40(p1, 1);
  }
  if (EQI(d_1bf2f8, 1)) {
    f_0dd750(d_1c0004, 0x146b);
  }
}

//@ f_0cb2f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Weiterleitungsfunktion ruft die Fallenroutine f_0cbda0(p1, 3) auf.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb2f0(int p1)
{
  f_0cbda0(p1, 3);
}

//@ f_0cb300
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion versetzt die Heldengruppe innerhalb des Dungeons auf die Zielposition 0x13f5.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb300(void)
{
  f_0dd750(d_1c0004, 0x13f5);
}

//@ f_0cb320
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion versetzt die Heldengruppe innerhalb des Dungeons auf die Zielposition 0x1533.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb320(void)
{
  f_0dd750(d_1c0004, 0x1533);
}

//@ f_0cb340
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet die Überquerungsroutine f_0cc010(p1, 0x1585, 0x1267).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb340(int p1)
{
  f_0cc010(p1, 0x1585, 0x1267);
}

//@ f_0cb360
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet die Überquerungsroutine f_0cc010(p1, 0x16c3, 0x1267).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb360(int p1)
{
  f_0cc010(p1, 0x16c3, 0x1267);
}

//@ f_0cb380
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet das Dungeon-Objekt 0x1f45 über f_05fa00(0x17, 0x1f45) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb380(void)
{
  f_05fa00(0x17, 0x1f45);
}

//@ f_0cb3a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet das Dungeon-Objekt 0x1f46 über f_05fa00(0x18, 0x1f46) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb3a0(void)
{
  f_05fa00(0x18, 0x1f46);
}

//@ f_0cb3c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet das Dungeon-Objekt 0x1f47 über f_05fa00(0x19, 0x1f47) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb3c0(void)
{
  f_05fa00(0x19, 0x1f47);
}

//@ f_0cb3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Warteschleife aktualisiert p1-mal hintereinander die 3D-Ansicht (f_1223c0) und das Soundsystem
 *   (f_146dfa), um eine kurze Animationspause zu erzeugen.
 * - Eingaben: Als Parameter wird die Anzahl der darzustellenden Einzelframes p1 übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb3e0(short p1)
{
  while (DEC(p1) != (short)0xffff) {
    f_1223c0();
    f_146dfa(A2E, 1);
  }
}

//@ f_0cb410
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert die animierte Betätigung und Passwortprüfung (f_0cc8c0) an den Vorrichtungen
 *   0x1f49, 0x1f4a und 0x1f4d, aktualisiert die Statusbits in d_1bf350 und schaltet das jeweilige Tor- oder
 *   Schalterobjekt p2 bei erfolgreicher Eingabe (r == 1) frei.
 * - Eingaben: Übergeben werden der Zeiger p1 auf den Dungeon-Handler, die Objekt-ID p2 (0x1f49, 0x1f4a oder
 *   0x1f4d) sowie der Aktionsmodus p3.
 * - Rückgabewert: Zurückgegeben wird das Ergebnis der Passwortprüfung r (1 bei Erfolg, 0 bei Misserfolg oder
 *   Abbruch).
 === Ende Beschreibung === */
int f_0cb410(int p1, unsigned short p2, short p3)
{
  int r;
  short n;
  int m;
  if (p3 == 1) {
    f_060770(p2, 1);
    f_0607e0(p2, 0);
    r = f_0de880(d_1c0004);
    f_0de890(d_1c0004, r - 0x310000);
    f_0de930(d_1c0004, 1);
    SWB(p2, d_1bf350 = d_1bf350 & 0xfc, d_1bf350 = d_1bf350 & 0xfe)
  }
  n = 3;
  f_060740(p2, 1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  n = 3;
  f_060740(p2, 1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  m = 10;
  f_060740(p2, 1);
  while ((short)DEC(m) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  n = 3;
  r = f_0cc8c0(p1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  n = 3;
  f_060740(p2, 1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  n = 3;
  f_060740(p2, 1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  n = 3;
  f_060740(p2, 1);
  while (DEC(n) != (short)0xffff) { f_1223c0(); f_146dfa(A2E, 1); }
  if (r == 1 && p3 != 2) {
    f_05fa00(0, (short)p2);
    f_0607e0(p2, 1);
    SWB(p2, d_1bf350 = d_1bf350 | 2, d_1bf350 = d_1bf350 | 1)
  }
  return r;
}

//@ f_0cb630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft für das Objekt 0x1f4a die Prüfroutine f_0cb410(p1, 0x1f4a, 0) auf, sofern Bit 0
 *   in d_1bf350 noch nicht gesetzt ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb630(int p1)
{
  unsigned char b = d_1bf350 & 1;
  if (!b) {
    f_0cb410(p1, 0x1f4a, 0);
  }
}

//@ f_0cb650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion betätigt die Hauptvorrichtung 0x1f4d über f_0cb410(p1, 0x1f4d, 2) und vergibt beim
 *   erstmaligen Lösen des Rätsels (d_1bf318 == 0) unter Abspielen des Sounds 0x35003e 60 Abenteuerpunkte (0x3c),
 *   den Tagebucheintrag 3 sowie die Erfolgsmeldung 0x35000196.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb650(int p1)
{
  int r;
  int eq;
  r = f_0cb410(p1, 0x1f4d, 2);
  if (r == 1) {
    if ((eq = EQI(d_1bf318, 0))) {
      { int snd = *(int *)&d_1a9820; f_147323b(A2E, 0x35003e, 0x7fff, 0x8000, snd, 0, 1); }
      f_0bf730(A64, 0x35000196);
      f_0dcbb0(d_1c0004, 0x3c);
      d_1bf318 = 1;
      f_091f70(3);
      return;
    }
    { int snd; f_147323b(A2E, 0x35003f, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), eq, 1); }
    f_0bf730(A64, 0x35000197);
  }
}

//@ f_0cb710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft für das Objekt 0x1f49 die Prüfroutine f_0cb410(p1, 0x1f49, 0) auf, sofern Bit 1
 *   in d_1bf350 noch nicht gesetzt ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb710(int p1)
{
  unsigned char b = d_1bf350 & 2;
  if (!b) {
    f_0cb410(p1, 0x1f49, 0);
  }
}

//@ f_0cb730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft f_0cb410(p1, 0x1f4a, 1) auf, um die Vorrichtung 0x1f4a im Modus 1 zurückzusetzen
 *   bzw. erneut zu prüfen.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Rückgabewert von f_0cb410.
 === Ende Beschreibung === */
int f_0cb730(int p1)
{
  return f_0cb410(p1, 0x1f4a, 1);
}

void f_0cb750(void)
{
}

//@ f_0cb760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ruft f_0cb410(p1, 0x1f49, 1) auf, um die Vorrichtung 0x1f49 im Modus 1 zu schalten.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb760(int p1)
{
  f_0cb410(p1, 0x1f49, 1);
}

//@ f_0cb780
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den Begegnungsstatus d_1bf348 von 0 auf 1, schaltet das Objekt 0x1f4b um und
 *   löst die geskriptete Sequenz 0x35002e aus.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb780(void)
{
  if (EQI(d_1bf348, 0)) {
    d_1bf348 = 1;
  }
  f_05fa00(0, 0x1f4b);
  f_060800(0x35002e, 0, 0);
  f_05fa00(0, 0x1f4b);
}

//@ f_0cb7d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft an einer Vorrichtung (0x1f4b), ob die Gruppe den Schlüsselgegenstand 0x1bd
 *   besitzt (f_0d54f0), und bietet nach mehr als drei Fehlversuchen (++d_1bf354 > 3) an, den Gegenstand 0x1bd
 *   einzusetzen und aus dem Inventar zu entfernen (d_1bf34c = 1, 0x3500019a, 0x3500019b).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
struct MsgC {
  int h;
  char *q[14];
  MsgC(int a, int b, int c) { f_125400((int)this, a, b, c); }
  ~MsgC() { f_1254a0((int)this, 0); }
};

void f_0cb7d0(void)
{
  MsgC m((int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  int ok;
  int r = (short)f_0d54f0(d_1c0004, 0x1bd);
  ok = 0;
  if (r != -1) {
    ok = 1;
    f_0bf730(A64, 0x35000198);
  } else {
    if (EQI(d_1bf34c, 1)) {
      f_05fa00(0, 0x1f4b);
      f_060800(0x35002c, 0, 0);
      f_05fa00(0, 0x1f4b);
    } else {
      PA((int)&m, 4) = f_0396f0(d_1c0004, 7);
      f_0bf730(A64, 0x35000199);
    }
  }
  if (ok == 1) {
    if (GTI(++d_1bf354, 3)) {
      PA((int)&m, 8) = f_039320(d_1c0004, 0x27);
      PA((int)&m, 0xc) = f_039660(d_1c0004, 7);
      if (f_0bf6f0(A64, 0x3500019a) == ok) {
        f_0bf730(A64, 0x3500019b);
        d_1bf34c = 1;
        f_0dd1d0(d_1c0004, 0x1bd);
      }
    }
  }
}
//@ f_0cb920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet im Begegnungszustand d_1bf348 == 1 den Kampf 2 über die virtuelle Methode des
 *   Dungeon-Handlers und spielt bei einem Sieg (s == 0) das Video 0x803003f ab, trägt den Tagebucheintrag 5 ein
 *   und schaltet d_1bf348 auf 2 weiter.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb920(int p1)
{
  int f_0f2720_one(int);
#pragma aux f_0f2720_one "f_0f2720"
  short s;
  if (EQB(d_1bf348, 1)) {
    f_0f2720_one(10);
    s = ((short(*)(int,int,int))(**(int**)((p1)+8)))((p1),(2),(0));
    if (s == 0) {
      d_1bf348 = 2;
      f_0f2720_one(0xc);
      f_091f70(5);
      f_057220((int)&d_1c2c00, 0x803003f, 0);
    }
  }
}

//@ f_0cb990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt im Begegnungszustand d_1bf348 == 2 den Text 0x3500019c aus, startet den Endkampf
 *   0x3c über die virtuelle Methode des Dungeon-Handlers und spielt bei einem Sieg (s == 0) die Zwischensequenz
 *   0x8030040 (d_1bf348 = 3) ab.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cb990(int p1)
{
int quest670(unsigned);
#pragma aux quest670 "f_0f2720"
  short s;
  if (EQB(d_1bf348, 2)) {
    f_0bf730(A64, 0x3500019c);
    s = (*(short (**)(int, int, int))*(int *)(p1 + 8))(p1, 0x3c, 0);
    if (s == 0) {
      d_1bf348 = 3;
quest670(5);f_057220((int)&d_1c2c00,0x8030040,0);
    }
  }
}

//@ f_0cba00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt am Objekt 0x1f48 (d_1bf34c == 0), ob der Spieler den Gegenstand 0x1bd an sich
 *   nehmen möchte (0x3500019d), übergibt ihn über f_0dcf00 an die Gruppe und schaltet das Objekt 0x1f48 um
 *   (d_1bf34c = 1).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cba00(void)
{
  short s;
  if (EQI(d_1bf34c, 0)) {
    if (f_0bf6f0(A64, 0x3500019d) == 1) {
      s = f_0dcf00(d_1c0004, 0x1bd, 1);
      if (s == 1) {
        d_1bf34c = 1;
        f_060740(0x1f48, 1);
        f_0607e0(0x1f48, 1);
        return;
      }
    }
  } else {
    f_0bf730(A64, 0x3500019e);
  }
}

//@ f_0cba80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine Statusmeldung (0x35000198 oder 0x35000199) aus, abhängig davon, ob die
 *   Gruppe den Gegenstand 0x1bd bereits im Inventar trägt oder d_1bf34c noch nicht gesetzt ist.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cba80(void)
{
  char obj[0x3c];
  short s;
  s = f_0d54f0(d_1c0004, 0x1bd);
  if (s != -1) {
    f_0bf730(A64, 0x35000198);
  } else {
    if (!EQI(d_1bf34c, 1)) {
      f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      PA(obj, 4) = f_0396f0(d_1c0004, 7);
      f_0bf730(A64, 0x35000199);
      f_1254a0((int)obj, 0);
    }
  }
}

//@ f_0cbb10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als Gruppen-Callback für eine Falle und zieht jedem handlungsfähigen Helden 3W6
 *   Lebenspunkte (f_145850(3, 6, 0)) über f_044300 ab.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cbb10(int p1)
{
  short s;
  if (f_0d4a60(p1) != 0) {
    s = f_145850(3, 6, 0);
    f_044300(p1, s);
  }
}

//@ f_0cbb40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt beim ersten Betreten (d_1bf2f8 == 0) eine schwere Decken- oder Stollenfalle
 *   ab, die einen einzelnen Helden sofort tötet (0x35000125), während bei einer Gruppe eine Sinnesschärfe-Probe
 *   (0x33, +5) und eine Attributsprobe (3, +5) entscheiden, ob kein Schaden, 3W6 Schaden an einem Helden oder
 *   3W6 Schaden an allen Helden (f_0cbb10) entsteht, bevor die Objekte 0x1f41 und 0x1f4b umgeschaltet werden.
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie ein ebenfalls ungenutzter Parameter p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cbb40(int p1, int p2)
{
  char obj[0x3c];
  if (EQI(d_1bf2f8, 0)) {
    int g1, g2;
    int a = f_038c40(d_1c0004);
    int b = a;
    int c = f_039660(d_1c0004, 3);
    short r1, r2;
    f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    if (f_0db9a0(d_1c0004) == 1) {
      short s;
      PA(obj, 4) = a;
      f_0bf730(A64, 0x35000125);
      s = f_042960((struct hero *)(a));
      f_044300(a, s);
    } else {
      g1 = 0;
      r1 = f_044c90(a, 0x33, (signed char)(r1 = 5));
      if (r1 > 1) g1 = 1;
      if (g1 == 1) {
        PA(obj, 4) = b;
        f_0bf730(A64, 0x35000126);
        PA(obj, 4) = f_039320(d_1c0004, 0x32);
        f_0bf730(A64, 0x35000127);
        g2 = 0;
        r2 = f_044900(c, 3, 5);
        if (r2 > 0) g2 = g1;
        if (g2 == 1) {
          PA(obj, 4) = c;
          f_0bf730(A64, 0x35000128);
          f_0bf730(A64, 0x35000129);
        } else {
          short s2, s3, d;
          PA(obj, 4) = c;
          f_0bf730(A64, 0x35000128);
          f_0bf730(A64, 0x3500012a);
          s2 = f_145850(3, 6, 0);
          s3 = s2;
          d = f_042960((struct hero *)(c)) - s2;
          if (d <= 0) {
            f_0bf730(A64, 0x3500012b);
          } else if (d <= 5) {
            f_0bf730(A64, 0x3500012c);
          } else {
            f_0bf730(A64, 0x3500012d);
          }
          f_044300(c, s3);
        }
      } else {
        f_039a80(d_1c0004, (int)f_0cbb10);
        f_0bf730(A64, 0x3500012e);
      }
    }
    f_060740(0x1f41, 1);
    f_0607e0(0x1f41, 1);
    f_0607e0(0x1f4b, 1);
    d_1bf2f8 = 1;
    f_1254a0((int)obj, 0);
  }
}
//@ f_0cbd50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Schadens-Hilfsfunktion würfelt für einen handlungsfähigen Helden p1 1W6 + 4 Schadenspunkte
 *   abzüglich seines Rüstungsschutzes (f_045210, mindestens 1 Punkt) aus und wendet den Schaden über
 *   f_044850(p1, a, 1) an.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cbd50(int p1)
{
  short a, b;
  if (f_0d4a60(p1) != 0) {
    a = f_145850(1, 6, 4);
    b = f_045210(p1);
    a = a - b;
    if (a < 1) a = 1;
    f_044850(p1, a, 1);
  }
}
