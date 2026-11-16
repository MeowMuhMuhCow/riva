/* === Beschreibung (Katalog) ===
 * Einheit gz_02fedc_t2 (0x0002ff70 - 0x00030024)
 *
 * Überblick
 *
 * Die Einheit gz_02fedc_t2 enthält zwei Hilfsfunktionen zur Auswahl und Ermittlung eines handlungsfähigen, auf
 * dem Kampffeld platzierten Helden der Gruppe vor Beginn oder während eines Kampfes.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Privater Profilteilungsvorschlag Astra493; noch nicht registriert.
// gz_02fedc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02FEDC-0x030080
#include <string.h>
#include "RIVAMEM.H"



int f_038c20(int p1);




char f_0433e0(int p1);
int f_069460();
int f_071e90(int p1, int p2, int p3);
char f_0d54c0(int p1);
extern signed char d_1bd928;
//@ f_02ff70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft in einer Schleife die Heldenauswahl f_038c20(p1) auf und wiederholt die Abfrage so lange,
 *   bis der gewählte Charakter laut f_0433e0(r) tatsächlich einsatzbereit ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gruppenzeiger p1 und gibt den Zeiger auf den ausgewählten
 *   Helden zurück.
 * - Wichtige Variablen: Prüft bei jedem Durchlauf das Event-/Sound-Flag d_1bd928 (f_069460) und die
 *   Einsatzbereitschaft über f_0433e0.
 === Ende Beschreibung === */
int f_02ff70(int p1)
{
  int r;
  char c;
  do {
    r = f_038c20(p1);
    if (d_1bd928) {
      f_069460();
    }
    c = f_0433e0(r);
  } while (!c);
  return r;
}
//@ f_02ffa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die sieben Gruppenplätze (0 bis 6) nach dem ersten Helden, der weder tot
 *   (f_042470), bewusstlos (f_0424e0), versteinert (f_0425a0) noch geflohen (f_0425f0) ist und für den über
 *   f_071e90 eine gültige Position auf dem Taktik-Kampffeld existiert.
 * - Eingaben und Rückgabe: Die Funktion nimmt das Array der sieben Gruppen-Heldenzeiger p1 entgegen und gibt den
 *   Zeiger auf den ersten gefundenen Kampfteilnehmer oder 0 zurück.
 * - Wichtige Variablen: Prüft die Statusfunktionen f_042470, f_0424e0, f_0425a0, f_0425f0 sowie die
 *   Kampffeld-Positionsabfrage f_071e90.
 === Ende Beschreibung === */
int f_02ffa0(int p1)
{
  if (d_1bd928) {
    f_069460();
  }
  short i;
  for (i = 0; i <= 6; i = i + 1) {
    int q = ((int *)p1)[i];
    if (q != 0 && !((char)(f_042470((struct hero *)(q)))) && !((char)(f_0424e0((struct hero *)(q)))) && !((char)(f_0425a0((struct hero *)(q)))) && !((char)(f_0425f0((struct hero *)(q))))) {
      int u, v;
      if (f_071e90((unsigned char)(f_0d54c0(q) + 1), (int)&v, (int)&u)) {
        return q;
      }
    }
  }
  return 0;
}
