/* === Beschreibung (Katalog) ===
 * Einheit gz_095600 (095600 - 095820)
 *
 * Überblick
 * Die Einheit gz_095600 enthält die beiden Würfelroutinen f_095600 und f_095710, mit denen bei der automatischen
 * Heldenerschaffung (f_094c70) ein einzelnes Talent bzw. ein einzelner Zauberspruch so lange mit 2W6 (bis Wert
 * 10) bzw. 3W6 (ab Wert 11) gesteigert wird, bis ein Steigerungswurf gelingt, drei Fehlversuche in Folge
 * erreicht sind oder keine freien Steigerungsversuche mehr übrig bleiben.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/2 gleich (suche.py 24.10.2026, Basis gz_095600_P1.CPP)
// gz_095600.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x095600-0x095820
#include <string.h>
struct E2 { signed char a; char b; };
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
signed char f_03ad80(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_043360(int p1, int p2);                           // reg eax edx stapel 0
short f_145760(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern struct E2 *d_1bc89c;                   // 0x1BC89C
extern struct E2 *d_1bc8a0;                   // 0x1BC8A0
//@ f_095600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versucht für den aktuellen Helden (*(int *)(p1 + 0xdf)), das Talent p2 automatisch um 1 Punkt
 *   zu steigern, indem pro Versuch ein freier Talentsteigerungspunkt abgezogen (f_043360(..., -1)) und mit 2W6
 *   (bei Talentwert < 11) bzw. 3W6 (ab Talentwert 11) gegen den aktuellen Talentwert gewürfelt wird, bis die
 *   Probe gelingt, drei Fehlversuche (d_1bc89c[p2].a == 3) vorliegen oder der Maximalwert 18 erreicht ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p1 sowie den Talentindex p2 (0..51) und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1bc89c protokolliert pro Talent die Anzahl der aufeinanderfolgenden
 *   Fehlversuche (a), die nach einer erfolgreichen Steigerung wieder auf 0 zurückgesetzt wird.
 === Ende Beschreibung === */
void f_095600(int p1, short p2)
{
  short done = 0;
  short s;
  int i;
  do {
    if (d_1bc89c[p2].a == 3 || f_03ad80(*(int *)(p1 + 0xdf), p2) == 0x12) {
      done = 1;
    } else {
      f_043360(*(int *)(p1 + 0xdf), -1);
      if (!((char)(f_043340((struct hero *)(*(int *)(p1 + 0xdf)))))) done = 1;
      if (f_03ad80(*(int *)(p1 + 0xdf), p2) >= 11)
        s = f_145760(3, 18);
      else
        s = f_145760(2, 12);
      i = p2;
      if (s > f_03ad80(*(int *)(p1 + 0xdf), i)) {
        f_03af20(*(int *)(p1 + 0xdf), i, 1);
        d_1bc89c[i].a = 0;
        done = 1;
      } else {
        d_1bc89c[i].a++;
      }
    }
  } while (!done);
}
//@ f_095710
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versucht analog zu f_095600 für einen magiebegabten Helden (*(int *)(p1 + 0xdf)), den
 *   Zauberspruch p2 automatisch um 1 Punkt zu steigern (2W6 bis Zauberfertigkeit 10, 3W6 ab 11), bis der Wurf
 *   den aktuellen Zauberwert übertrifft, drei Fehlversuche in d_1bc8a0[p2].a erreicht sind oder keine freien
 *   Zaubersteigerungen (f_0432f0) mehr vorhanden sind.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p1 sowie den Zauberindex p2 (0..85)
 *   entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1bc8a0 speichert für jeden der 86 Zaubersprüche die Zahl der Fehlversuche
 *   und bisherigen Steigerungen während der Generierung.
 === Ende Beschreibung === */
void f_095710(int p1, short p2)
{
  short done = 0;
  short s;
  int i;
  do {
    if (d_1bc8a0[p2].a == 3 || f_0430f0((struct hero *)(*(int *)(p1 + 0xdf)), p2) == 0x12) {
      done = 1;
    } else {
      f_043310((struct hero *)(*(int *)(p1 + 0xdf)), -1);
      if (!((char)(f_0432f0((struct hero *)(*(int *)(p1 + 0xdf)))))) done = 1;
      if (f_0430f0((struct hero *)(*(int *)(p1 + 0xdf)), p2) >= 11)
        s = f_145760(3, 18);
      else
        s = f_145760(2, 12);
      i = p2;
      if (s > f_0430f0((struct hero *)(*(int *)(p1 + 0xdf)), i)) {
        f_043110((struct hero *)(*(int *)(p1 + 0xdf)), i, 1);
        d_1bc8a0[i].a = 0;
        done = 1;
      } else {
        d_1bc8a0[i].a++;
      }
    }
  } while (!done);
}
