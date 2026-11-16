/* === Beschreibung (Katalog) ===
 * Einheit tower3_t2 (0x130040 - 0x131490)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von tower3.cpp für die dritte Ebene des Magierturms. Sie enthält vor
 * allem die Stufenlogik für die Untersuchung der vier magisch geschützten Bücherregale in der Bibliothek (in
 * denen Werke wie *Borbarads Testament*, *Daimonikum*, *Die Wege ohne Namen*, *Buch des Zurbaran*, *Trilogie der
 * Kontrolle*, *Arcanum* und *Codex Dimensionis* stehen), den Endkampf dieser Ebene inklusive Durchsuchung aller
 * Gruppen nach verfluchten Beutestücken sowie die Auswertung der drei tödlichen Sicherheitsfallen auf den
 * Gängen.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 16/21 gleich (suche.py 25.10.2026, Basis tower3_t2_P1.CPP)
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
int f_041030();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
int f_0423c0(int p1);                                   // reg eax stapel 0
int f_042470(int p1);                                   // reg eax stapel 0
int f_0425f0(int p1);                                   // reg eax stapel 0
short f_042960(int p1);                                   // reg eax stapel 0
short f_0429a0(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
short f_042ac0(int p1, int p2);                           // reg eax edx stapel 0
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
int f_0602f0(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
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
short f_145850(int p1, int p2, int p3, int p4, int p5);  // reg eax edx ebx ecx stapel 4
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
short f_149360();                       // nicht in clobber.tsv
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
extern volatile signed char d_1c0d54; // volatile verhindert CSE/Registerhaltung des Zustandszaehlers in f_130040
extern volatile signed char d_1c0d58; // volatile verhindert CSE/Registerhaltung des Zustandszaehlers in f_130240
extern volatile signed char d_1c0d5c; // volatile verhindert CSE/Registerhaltung des Zustandszaehlers in f_1304c0
extern volatile signed char d_1c0d60; // volatile verhindert CSE/Registerhaltung des Zustandszaehlers in f_1307b0
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
struct Obj { int f0; char *p[13]; short s38; Obj(const char*, const char*, const char*); ~Obj(); };
struct T14 { char b[0x14]; };
typedef short (*VF2)(int,int);
#define VF(T,p) ((T)(**(int **)((p)+8)))
#define EQI(x,v) (((x)==(v))?1:0)
#define CH ((int)&d_1c2c64)
#define CW ((int)&d_1c2c00)
#define C44 ((int)&d_1c2c44)
#define NEWD(q,ln,K) q = (int)new (mark(d_1a8d0c, ln)) T14; q = q ? f_112df0(q, K, 0, 0) : q;
#define OK1 ok1
#define OK2 ok2
#define OK3 ok3
#define OK4 ok4
int f_131530(int p1, int p2);
void f_131650(int p1, int p2, int p3);

//@ f_130040
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet die schrittweise Untersuchung des ersten verzauberten Bücherregals (d_1c0d54,
 *   Stufen 0 bis 4): Nach erfolgreicher magischer Entschärfung bzw. Auswahl eines Helden (f_131530) liest oder
 *   durchsucht der Held bei jedem Aufruf einen weiteren Abschnitt des Regals, bis er auf Stufe 3 das Werk
 *   "Borbarads Testament" (0x1bf) findet und auf Stufe 4 nur noch die Meldung erhält, dass nichts Weiteres von
 *   Interesse vorhanden ist.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger q bezeichnet den untersuchenden Helden; der globale Stufenzähler d_1c0d54
 *   rückt nur dann auf die nächste Stufe vor, wenn das gefundene Buch (0x1bf) erfolgreich im Inventar
 *   untergebracht wurde (ok == 1).
 === Ende Beschreibung === */
void f_130040(int p1)
{
  int q;
  int ok;
  q = f_131530(p1, EQI(d_1c0d54, 4) != 0);
  if (q != 0) {
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(o.p[0] + 4) = q;
    if (EQI(d_1c0d54, 0)) {
      f_0bf730(CH, 0x27000112);
      ++d_1c0d54;
    } else {
      if (EQI(d_1c0d54, 1)) {
        *(int *)(o.p[0] + 8) = f_039320(d_1c0004, 0x21);
        f_0bf730(CH, 0x27000113);
        ++d_1c0d54;
        return;
      }
      if (EQI(d_1c0d54, 2)) {
        f_0bf730(CH, 0x27000114);
        ++d_1c0d54;
        return;
      }
      if (EQI(d_1c0d54, 3)) {
        f_0bf730(CH, 0x27000115);
        *(int *)(o.p[0] + 8) = f_039320(d_1c0004, 0x27);
        *(int *)(o.p[0] + 0xc) = f_039320(d_1c0004, 0x26);
        ok = 1;
        f_0bf730(CH, 0x27000116);
        if (f_0366e0(q, 0x1bf, 0, 1) != 1) {
          if (f_0dcf00(d_1c0004, 0x1bf, 1) != 1) {
            f_0bf730(CH, 0x2700010a);
            ok = 0;
          }
        }
        if (ok == 1) {
          ++d_1c0d54;
          return;
        }
      } else if (EQI(d_1c0d54, 4)) {
        f_0bf730(CH, 0x27000117);
      }
    }
  }
}

//@ f_130240
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die Untersuchung des zweiten verzauberten Bücherregals (d_1c0d58, Stufen 0 bis 5),
 *   bei der die Gruppe auf Stufe 0 das Buch "Daimonikum" (0x1c0) und auf Stufe 3 das Buch "Die Wege ohne Namen"
 *   (0x1c1) entdeckt, wobei jeweils die Spielzeit um 30 Minuten (0x1e) vorgerückt wird (f_125ed0).
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Stufenzähler d_1c0d58 verfolgt den Fortschritt am zweiten Regal; die Hilfsvariablen
 *   ok1 und ok2 prüfen, ob die Bücher 0x1c0 bzw. 0x1c1 im Inventar Platz gefunden haben, bevor der Zähler erhöht
 *   wird.
 === Ende Beschreibung === */
void f_130240(int p1)
{
  int q = 0;
  int ok, ok1, ok2, ok3, ok4;
  q = f_131530(p1, EQI(d_1c0d58, 5) != 0);
  if (q != 0) {
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(o.p[0] + 4) = q;
    if (EQI(d_1c0d58, 0)) {
      OK1 = 1;
      f_0bf730(CH, 0x27000118);
      f_0bf730(CH, 0x27000119);
      f_125ed0(C44, 0x1e);
      if (f_0366e0(q, 0x1c0, 0, 1) != 1) {
        if (f_0dcf00(d_1c0004, 0x1c0, 1) != 1) {
          f_0bf730(CH, 0x2700010a);
          OK1 = 0;
        }
      }
      if (OK1 == 1) {
        ++d_1c0d58;
        return;
      }
    } else {
      if (EQI(d_1c0d58, 1)) {
        f_0bf730(CH, 0x2700011a);
        ++d_1c0d58;
        return;
      }
      if (EQI(d_1c0d58, 2)) {
        f_0bf730(CH, 0x2700011b);
        ++d_1c0d58;
        return;
      }
      if (EQI(d_1c0d58, 3)) {
        OK2 = 1;
        f_0bf730(CH, 0x2700011c);
        f_125ed0(C44, 0x1e);
        if (f_0366e0(q, 0x1c1, 0, 1) != 1) {
          if (f_0dcf00(d_1c0004, 0x1c1, 1) != 1) {
            f_0bf730(CH, 0x2700010a);
            OK2 = 0;
          }
        }
        if (OK2 == 1) {
          ++d_1c0d58;
          return;
        }
      } else {
        if (EQI(d_1c0d58, 4)) {
          f_0bf730(CH, 0x27000114);
          ++d_1c0d58;
          return;
        }
        if (EQI(d_1c0d58, 5)) {
          f_0bf730(CH, 0x27000117);
        }
      }
    }
  }
}

//@ f_1304c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet die Untersuchung des dritten Bücherregals (d_1c0d5c, Stufen 0 bis 4): Auf Stufe 1
 *   entdeckt der Held mit der höchsten Sinnenschärfe (0x27) das "Buch des Zurbaran" (0x1be), das bevorzugt einem
 *   zweiten Helden (r) mit freiem Inventarplatz übergeben wird, und auf Stufe 3 findet der Untersuchende nach
 *   einer halben Stunde Lesezeit die "Trilogie der Kontrolle" (0x1c2).
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der globale Zähler d_1c0d5c speichert den Untersuchungsstand des dritten Regals; t ist
 *   der scharfsinnigste Held, r ein Begleiter für die Buchübergabe und q der ursprünglich ausgewählte Magier.
 === Ende Beschreibung === */
void f_1304c0(int p1)
{
  int q;
  int ok, ok1, ok2, ok3, ok4;
  int r;
  int t;
  q = f_131530(p1, EQI(d_1c0d5c, 4) != 0);
  if (q == 0) {
    return;
  }
  Obj o(d_1c349c, d_1c3870, d_1c3498);
  *(int *)(o.p[0] + 4) = q;
  if (EQI(d_1c0d5c, 0)) {
    *(int *)(o.p[0] + 8) = f_039320(d_1c0004, 0x21);
    f_0bf730(CH, 0x2700011d);
    ++d_1c0d5c;
  } else if (EQI(d_1c0d5c, 1)) {
    t = f_039320(d_1c0004, 0x27);
    r = f_039b70(d_1c0004, t, 10);
    *(int *)(o.p[0] + 4) = t;
    f_0bf730(CH, 0x2700011e);
    if (r != 0 && f_032670(r, 0) != -1) {
      *(int *)(o.p[0] + 8) = r;
      f_0bf730(CH, 0x2700011f);
      OK1 = 1;
      if (f_0366e0(r, 0x1be, 0, 1) != 1 && f_0dcf00(d_1c0004, 0x1be, 1) != 1) {
        f_0bf730(CH, 0x2700010a);
        OK1 = 0;
      }
      if (OK1 == 1) {
        ++d_1c0d5c;
        return;
      }
    } else {
      OK2 = 1;
      f_0bf730(CH, 0x27000120);
      if (f_0366e0(q, 0x1be, 0, 1) != 1 && f_0dcf00(d_1c0004, 0x1be, 1) != 1) {
        f_0bf730(CH, 0x2700010a);
        OK2 = 0;
      }
      if (OK2 == 1) {
        ++d_1c0d5c;
        return;
      }
    }
  } else {
    if (EQI(d_1c0d5c, 2)) {
      f_0bf730(CH, 0x27000121);
      ++d_1c0d5c;
      return;
    }
    if (EQI(d_1c0d5c, 3)) {
      OK3 = 1;
      f_0bf730(CH, 0x27000122);
      f_125ed0(C44, 0x1e);
      if (f_0366e0(q, 0x1c2, 0, 1) != 1 && f_0dcf00(d_1c0004, 0x1c2, 1) != 1) {
        f_0bf730(CH, 0x2700010a);
        OK3 = 0;
      }
      if (OK3 == 1) {
        ++d_1c0d5c;
        return;
      }
    } else if (EQI(d_1c0d5c, 4)) {
      f_0bf730(CH, 0x27000117);
    }
  }
}

//@ f_1307b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die Untersuchung des vierten Bücherregals (d_1c0d60, Stufen 0 bis 2), in dem der
 *   untersuchende Held beim ersten Durchgang das "Arcanum" (0x1c3) und beim zweiten Durchgang nach 30 Minuten
 *   den "Codex Dimensionis" (0x1c4) findet.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der globale Stufenzähler d_1c0d60 zählt die erfolgreichen Funde am vierten Regal von 0
 *   bis 2.
 === Ende Beschreibung === */
void f_1307b0(int p1)
{
  int q;
  int ok, ok1, ok2, ok3, ok4;
  q = f_131530(p1, EQI(d_1c0d60, 2) != 0);
  if (q != 0) {
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(o.p[0] + 4) = q;
    if (EQI(d_1c0d60, 0)) {
      OK1 = 1;
      f_0bf730(CH, 0x27000123);
      if (f_0366e0(q, 0x1c3, 0, 1) != 1) {
        if (f_0dcf00(d_1c0004, 0x1c3, 1) != 1) {
          f_0bf730(CH, 0x2700010a);
          OK1 = 0;
        }
      }
      if (OK1 == 1) {
        ++d_1c0d60;
      }
    } else if (EQI(d_1c0d60, 1)) {
      OK2 = 1;
      f_0bf730(CH, 0x27000124);
      f_125ed0(C44, 0x1e);
      if (f_0366e0(q, 0x1c4, 0, 1) != 1) {
        if (f_0dcf00(d_1c0004, 0x1c4, 1) != 1) {
          f_0bf730(CH, 0x2700010a);
          OK2 = 0;
        }
      }
      if (OK2 == 1) {
        ++d_1c0d60;
        return;
      }
    } else if (EQI(d_1c0d60, 2)) {
      f_0bf730(CH, 0x27000125);
    }
  }
}

//@ f_130950
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Untersuchen eines Raumobjekts (Ereignis 0x196) den Beschreibungstext 0x27000126
 *   an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt das Ergebnis des Textdialogs (f_0bf730) zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_130950(void)
{
  return f_0bf730(CH, 0x27000126);
}

//@ f_130970
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leere Platzhalterfunktion für das Raumereignis 0x197, bei dem keine Aktion ausgeführt wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine Variablen.
 === Ende Beschreibung === */
void f_130970(void)
{
}

//@ f_130980
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Untersuchen eines weiteren Raumdetails (Ereignis 0x198) den Beschreibungstext
 *   0x27000127 an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_130980(void)
{
  f_0bf730(CH, 0x27000127);
}

//@ f_1309a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Standard-Türinteraktion für die verschlossene Tür mit dem Türindex 0x4d und der
 *   3D-Objektkennung 0x1f4a aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen; ruft f_05fa00(0x4d, 0x1f4a) auf.
 === Ende Beschreibung === */
void f_1309a0(void)
{
  f_05fa00(0x4d, 0x1f4a);
}

//@ f_1309c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler an der aufwärts führenden Treppe (0x27000128), ob die Gruppe in das vierte
 *   Stockwerk des Magierturms hinaufsteigen möchte, und versetzt die Gruppe bei Bestätigung auf die vierte
 *   Turmebene (0x16, Zielposition 0x139a).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen; nutzt d_1c0004 als Zeiger auf die aktive Gruppe.
 === Ende Beschreibung === */
void f_1309c0(void)
{
  if (f_0bf6f0(CH, 0x27000128) == 1) {
    f_0dd7f0(d_1c0004, 0x16, 0x139a);
  }
}

//@ f_1309f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Inszeniert die zentrale Begegnung auf der dritten Turmebene (Ereignis 0x1f7): Beim ersten
 *   Betreten (d_1c0d64 == 0) wird ein Bild (0x270001, Index 8) zusammen mit dem Text 0x27000129 eingeblendet und
 *   anschließend der Kampf 0x82 gestartet; nach dem Sieg werden ein Tagebucheintrag (0x2e) angelegt, bei allen
 *   sechs Teilgruppen eventuelle verzauberte Gegenstände über f_131a70 in Edelsteine verwandelt und die
 *   Videosequenz 0x803002c abgespielt.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Bildzeiger q hält die geladene Grafik für den Dialog; das globale Flag d_1c0d64
 *   verhindert eine Wiederholung der Begegnung, und die Schleifenvariable s durchläuft alle sechs möglichen
 *   Heldengruppen ab d_1bfdbc.
 === Ende Beschreibung === */
void f_1309f0(int p1)
{
  typedef short (*FNV)(int, int, int);
  short s;
  int q;
  int p;
  if (EQI(d_1c0d64, 0)) {
    q = f_0606a0(0x270001, 8);
    f_0bde40(CH);
    f_0bfa20(CH, q, 0, 0x27000129, 0);
    if (q != 0) delete (char *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0)));
    d_1bd91c = 1;
    FNV *vt = *(FNV **)(p1 + 8);
    if (vt[0](p1, 0x82, 0) == 0) {
      f_0697c0(p1 + 2, 0x82, 0);
      d_1c0d64 = 1;
      f_091f70(0x2e);
      f_060a70();
      for (s = 0; s < 6; s = s + 1) {
        p = (int)&d_1bfdbc + s * 0x61;
        if (f_0de7c0(p) != 0) {
          f_131a70(p);
        }
      }
      f_057220(CW, 0x803002c, 0);
    }
  }
}

//@ f_130ae0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet das Beutelager 0x3d (Ereignis 0x1f8): Beim ersten Mal (d_1c0d68 == 0) wird der
 *   Fundtext 0x2700012a gezeigt und direkt das Beutefenster geöffnet; bei späteren Besuchen erscheint der Text
 *   0x2700012b und das Beutefenster öffnet sich nur noch, wenn noch Gegenstände im Lager verblieben sind
 *   (f_1131b0).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger q verweist auf das temporäre Beutelager-Objekt für den Stapel 0x3d; das
 *   globale Flag d_1c0d68 speichert, ob dieser Fundort bereits untersucht wurde.
 === Ende Beschreibung === */
void f_130ae0(void)
{
  int q;
  NEWD(q, 0x5e5, 0x3d)
  if (EQI(d_1c0d68, 0)) {
    d_1c0d68 = 1;
    f_0bf730(CH, 0x2700012a);
  } else {
    f_0bf730(CH, 0x2700012b);
    if (f_1131b0(q) == 0) goto L1;
  }
  f_112ec0(q);
L1:
  if (q != 0) delete (char *)f_112e70(q, 0);
}

//@ f_130b80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt den Helden mit der niedrigsten Körperkraft (Attribut 6) in der aktiven Gruppe und
 *   gibt mit dessen Namen die Raummeldung 0x2700012c aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der lokale Textkontext (o) speichert den Zeiger auf den schwächsten Helden im ersten
 *   Namensplatzhalter.
 === Ende Beschreibung === */
void f_130b80(void)
{
  Obj o(d_1c349c, d_1c3870, d_1c3498);
  *(int *)(o.p[0] + 4) = f_0396f0(d_1c0004, 6);
  f_0bf730(CH, 0x2700012c);
}

//@ f_130be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Untersuchen des Ortsereignisses 0x1fa den Beschreibungstext 0x2700012d an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_130be0(void)
{
  f_0bf730(CH, 0x2700012d);
}

//@ f_130c00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Untersucht das Beutelager 0x38 (Ereignis 0x1fb): Solange sich noch Gegenstände darin
 *   befinden (f_1131b0(q) == 1), wird der Text 0x2700012e angezeigt und das Beutefenster geöffnet; ist es leer,
 *   erscheint die Meldung 0x2700012f.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger q verwaltet die Instanz des Beutelagers 0x38.
 === Ende Beschreibung === */
void f_130c00(void)
{
  int q;
  NEWD(q, 0x62f, 0x38)
  if (f_1131b0(q) == 1) {
    f_0bf730(CH, 0x2700012e);
    f_112ec0(q);
  } else {
    f_0bf730(CH, 0x2700012f);
  }
  if (q != 0) delete (char *)f_112e70(q, 0);
}

//@ f_130c80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das magische Rätselfeld bei Ereignis 0x1fc: Solange die Barriere oder Erscheinung
 *   noch aktiv ist (d_1c0908 == 0), wird der Beschreibungstext 0x27000130 angezeigt, und falls sich ein
 *   Zauberkundiger in der Gruppe befindet, kann der Spieler auf Rückfrage (0x27000131) einen Magier auswählen
 *   (0x20000155) und im Kontext d_1c0428 = 2 einen Zauber wirken; ist das Rätsel bereits gelöst, erscheint
 *   0x27000132.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger r enthält den vom Spieler gewählten Zauberkundigen; d_1c0908 speichert, ob
 *   die magische Ursache bereits gebannt wurde.
 === Ende Beschreibung === */
void f_130c80(void)
{
  int r;
  if (EQI(d_1c0908, 0)) {
    f_0bf730(CH, 0x27000130);
    if (f_0390a0(d_1c0004) != 0) {
      if (f_0bf6f0(CH, 0x27000131) == 1) {
        r = f_038e10(d_1c0004, 0x20000155);
        if (r != 0) {
          d_1c0428 = 2;
          f_03d4b0(r, 1, 0);
          return;
        }
      }
    }
  } else {
    f_0bf730(CH, 0x27000132);
  }
}

//@ f_130d10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Untersucht das Beutelager 0x3e (Ereignis 0x1fd) und öffnet bei vorhandenem Inhalt nach
 *   Anzeige von 0x27000133 das Beutefenster; falls bereits alles entnommen wurde, wird 0x27000134 ausgegeben.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger q hält das temporäre Beutelager-Objekt für den Stapel 0x3e.
 === Ende Beschreibung === */
void f_130d10(void)
{
  int q;
  NEWD(q, 0x678, 0x3e)
  if (f_1131b0(q) == 1) {
    f_0bf730(CH, 0x27000133);
    f_112ec0(q);
  } else {
    f_0bf730(CH, 0x27000134);
  }
  if (q != 0) delete (char *)f_112e70(q, 0);
}

//@ f_130d90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt beim Auslösen von Ereignis 0x1fe den Raumtext 0x27000135 aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_130d90(void)
{
  f_0bf730(CH, 0x27000135);
}

//@ f_130db0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet das Beutelager 0x39 (Ereignis 0x1ff), indem beim ersten Mal (d_1c0d90 == 0) der
 *   Entdeckungstext 0x27000136 samt Beutefenster und bei späteren Aufrufen ohne Text direkt das Beutefenster
 *   (sofern noch nicht leer) geöffnet wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Der Zeiger q repräsentiert das Beutelager 0x39; das globale Flag d_1c0d90 merkt sich die
 *   Erstentdeckung.
 === Ende Beschreibung === */
void f_130db0(void)
{
  int q;
  NEWD(q, 0x6a8, 0x39)
  if (EQI(d_1c0d90, 0)) {
    d_1c0d90 = 1;
    f_0bf730(CH, 0x27000136);
  } else {
    if (f_1131b0(q) == 0) goto L2;
  }
  f_112ec0(q);
L2:
  if (q != 0) delete (char *)f_112e70(q, 0);
}

//@ f_130e40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler bei Ereignis 0x259 (0x27000137), ob die Gruppe an eine bestimmte Stelle
 *   innerhalb der Ebene (0x67) wechseln bzw. klettern möchte, und versetzt die aktive Gruppe bei Bestätigung
 *   dorthin (f_0de810).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_130e40(void)
{
  if (f_0bf6f0(CH, 0x27000137) == 1) {
    f_0de810(d_1c0004, 0x67);
  }
}

//@ f_130e70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft für einen Helden (p1), ob dieser im angegebenen Ausrüstungsslot (p2, z. B. Waffenhand
 *   oder Schildhand) einen nicht-magischen bzw. zerstörbaren Gegenstand trägt (f_0a78f0 == 0), der von einer der
 *   Gangfallen entrissen oder beschädigt werden kann.
 * - Eingaben: Ein Zeiger auf den Helden (p1) sowie der Index des Ausrüstungsplatzes (p2).
 * - Rückgabewert: Gibt die Gegenstandskennung (s) im Erfolgsfall oder -1 zurück, wenn der Slot leer oder der
 *   Gegenstand unzerstörbar ist.
 * - Wichtige Variablen: s ist die aus dem Heldeninventar gelesene Gegenstandskennung; über die globale
 *   Gegenstandstabelle d_1c2c40 wird deren Eigenschaft geprüft.
 === Ende Beschreibung === */
int f_130e70(int p1, short p2)
{
  int s,r;
  s=f_042a60(p1,p2);
  r=-1;
  if((short)s>0) {if(((RivaItemDefinition*)((*(int **)&d_1c2c40)[(short)s]))->f_0a78f0()==0)r=s;}
  return r;
}

//@ f_130ea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Entfernt bei einer ausgelösten Gangfalle die in den Ausrüstungsslots 12 (linke Hand,
 *   Gegenstand p2) und 3 (rechte Hand, Gegenstand p3) getragenen Waffen oder Gegenstände aus dem Inventar des
 *   Helden (p1) und legt sie in das am Boden liegende Beutelager 0x2a ab, sodass der Spieler sie dort später
 *   wieder einsammeln kann.
 * - Eingaben: Ein Zeiger auf den betroffenen Helden (p1) sowie die Gegenstandskennungen aus dem ersten (p2) und
 *   zweiten (p3) Ausrüstungsslot.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Das Beutelager-Objekt q repräsentiert den Beutestapel 0x2a; s ermittelt bei stapelbaren
 *   Gegenständen (f_0a7950) die genaue Stückzahl im Slot (f_042ac0), ansonsten 1.
 === Ende Beschreibung === */
void f_130ea0(int p1, short p2, short p3)
{
  int q;
  short s;
  NEWD(q, 0x72d, 0x2a)
  if (p2 > 0) {
    int i = p2 * 4;
    int t_559 = ((RivaItemDefinition*)(*(int *)((char *)(*(int **)&d_1c2c40) + i)))->f_0a78f0();
    if (t_559 == (short)0) {
      s = (((RivaItemDefinition*)(*(int *)((char *)(*(int **)&d_1c2c40) + i)))->f_0a7950() != 0) ? f_042ac0(p1, 0xc) : 1;
      f_113340(q, p2, s, 0);
      f_036300(p1, 0xc, s);
    }
  }
  if (p3 > 0) {
    int i = p3 * 4;
    if (((RivaItemDefinition*)(*(int *)(i + (char *)(*(int **)&d_1c2c40))))->f_0a78f0() == 0) {
      s = (((RivaItemDefinition*)(*(int *)(i + (char *)(*(int **)&d_1c2c40))))->f_0a7950() != 0) ? f_042ac0(p1, 3) : 1;
      f_113340(q, p3, s, 0);
      f_036300(p1, 3, s);
    }
  }
  if (q != 0) delete (char *)f_112e70(q, 0);
}

//@ f_130fd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die komplette Logik der drei Statuen- bzw. Lichtschrankenfallen (p2 = 0, 1, 2) auf den
 *   Gängen der dritten Turmebene aus: Ist die Falle noch aktiv (*p3 == 0), legt der Gruppenanführer (q) zwei
 *   erschwerte Proben (+2) auf Gewandtheit (Attribut 4) und Körperkraft/Intuition (Attribut 5) ab. Besteht er
 *   beide, weicht er aus (wobei er bei den Fallen 0 und 1 unter Abspielen des Videos 0x803002a eventuell seine
 *   getragenen Handgegenstände in das Beutelager 0x2a verliert). Misslingt mindestens eine Probe, wird das
 *   Treffer-Video 0x803002b gezeigt und der Anführer erleidet bei den Fallen 0 und 1 schweren Schaden (2W20,
 *   mindestens 8) samt Rückwurf auf Ebene 0x12, während er bei der dritten Falle (p2 == 2) sofort stirbt. Ist
 *   die Falle hingegen bereits abgeschaltet (*p3 != 0), kann der Spieler mutwillig an der Vorrichtung hantieren
 *   (0x270000f6/0x270000f7), was ebenfalls 3W20 Schaden bzw. bei p2 == 2 den Tod des Anführers nach sich zieht.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1), die Fallennummer (p2: 0, 1 oder 2) sowie ein Zeiger auf das
 *   zugehörige Abschalt-Statusflag (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: m hält das geladene Fallen-Ereignisbild (0x270001, Index 7), q ist der Gruppenanführer,
 *   left und right speichern die Ergebnisse der beiden Eigenschaftsproben (f_044900), und first sowie second
 *   bezeichnen die aus den Händen geschlagenen Gegenstände. *(Hinweis: Die beiden Fehlerzweige für "eine Probe
 *   misslungen" und "beide Proben misslungen" ab Label both_negative führen exakt denselben Code aus - siehe
 *   Fehlerliste).*
 === Ende Beschreibung === */
short choice492(int,int);
#pragma aux choice492 "f_0bf6f0";
struct Search1108 {
    static short get(int q, short kind) {
        short value = f_042a60(q, kind);
        short found = -1;
        if (value > 0) {
            int off = value * 4;
            off = (off & 0) ? 0 : off; // haelt den Index off als eigenen berechneten Registerwert
            if (((RivaItemDefinition*)(*(int *)((char *)(*(int **)&d_1c2c40) + off)))->f_0a78f0() == 0)
                found = value;
        }
        return found;
    }
};
void f_130fd0(int p1, int p2, signed char *p3)
{
    // Same-definition contracts: Dice has three arguments; Damage has five.
    short Dice680(int,int,int);
    #pragma aux Dice680 "f_145850";
    void Damage680(int,int,int,int,int);
    #pragma aux Damage680 "f_131650";
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    int m;
    int q;
    int r;
    short left;
    short first;
    short right;
    short second;

    m = f_0606a0(0x270001, 7);
    q = f_038c40(d_1c0004);
    *(int *)(o.p[0] + 4) = q;
    f_0bf6c0(CH, 5);

    if (EQI(*p3, 0)) {
        left = f_044900(q, 4, 2);
        right = f_044900(q, 5, 2);
        f_0bf730(CH, 0x270000ee);

        if (left >= 0 && right >= 0) {
            f_0bde40(CH);
            f_0bfa20(CH, m, 0, 0x270000ef, 0);
            if ((short)p2 != 2) {
                short rawFirst = Search1108::get(q, 12);
                int rawSecond = f_130e70(q, 3);
                if (EQI(d_1c0d8c, 0)) {
                    d_1c0d8c = 1;
                    f_057220(CW, 0x803002a, 0);
                }
                first=(short)rawFirst; second=(short)rawSecond;
                f_130ea0(q, first, second);
                if (second != -1 || first != -1) {
                    f_0bde40(CH);
                    f_0bfa20(CH, m, 0, 0x270000f0, 0);
#if FIX_R068   /* R068: Zweiten Helden nur suchen, wenn neben Anfuehrer q ein weiterer Held bei Bewusstsein ist */
                    if (f_0db9a0(d_1c0004) >= 2 && f_039c50(d_1c0004, q) != 0) {
#else
                    if (f_0db9a0(d_1c0004) >= 2) {
#endif
                        *(int *)(o.p[0] + 8) = f_039c50(d_1c0004, q);
                        f_0bde40(CH);
                        f_0bfa20(CH, m, 0, 0x270000f1, 0);
                    }
                }
#if FIX_R068   /* R068: Endlosschleife verhindern, wenn alle uebrigen Gruppenmitglieder bewusstlos sind */
            } else if (f_0db9a0(d_1c0004) > 1 && f_039c50(d_1c0004, q) != 0) {
#else
            } else if (f_0db9a0(d_1c0004) > 1) {
#endif
                do {
                    r = f_038ba0(d_1c0004);
                } while (f_0d4a60(r) == 0 || r == q);
                *(int *)(o.p[0] + 8) = r;
                f_0bde40(CH);
                f_0bfa20(CH, m, 0, 0x270000f2, 0);
            }
            goto done;
        }

        if (!(left >= 0 || right >= 0)) goto both_negative;
        if (EQI(d_1c0d94, 0)) {
            d_1c0d94 = 1;
            f_057220(CW, 0x803002b, 0);
        }
        if ((short)p2 == 2) goto second_case;
        *(int *)(o.p[3] + 4) = 0x270000f4;
        f_0bde40(CH);
        f_0bfa20(CH, m, 0, 0x270000f3, 0);
        Damage680(p1,q,Dice680(2,20,0),8,0);
        goto done;
second_case:
        *(int *)(o.p[3] + 4) = 0x270000f5;
        f_0bde40(CH);
        f_0bfa20(CH, m, 0, 0x270000f3, 0);
        goto final_case;
both_negative:
        *(int *)(o.p[0] + 4) = q;
        if (EQI(d_1c0d94, 0)) {
            d_1c0d94 = 1;
            f_057220(CW, 0x803002b, 0);
        }
        if ((short)p2 == 2) goto second_case;
        *(int *)(o.p[3] + 4) = 0x270000f4;
        f_0bde40(CH);
        f_0bfa20(CH, m, 0, 0x270000f3, 0);
        Damage680(p1,q,Dice680(2,20,0),8,0);
        goto done;
    } else {
        short reply;
        if ((short)p2 != 2) reply = choice492(CH, 0x270000f6);
        else reply = choice492(CH, 0x270000f7);
        if (reply != (short)1) goto done;
        f_0bde40(CH);
        f_0bfa20(CH, m, 0, 0x270000f8, 0);
        if ((short)p2 != 2) {
            Damage680(p1,q,Dice680(3,20,0),10,1);
            goto done;
        }
        f_0bde40(CH);
        f_0bfa20(CH, m, 0, 0x270000f9, 0);
    }

final_case:
    first = f_042960(q);
    f_044300(q, first);
    first = f_0dc020(d_1c0004, q);
    f_0dcd30(d_1c0004, first, -1);
done:
    f_0bf680(CH);
    if (m) delete (char *)((int)(((RivaRasterImage*)(m))->f_0fad20( 0)));
}
