/* === Beschreibung (Katalog) ===
 * Einheit gz_11c070 (0x11c070 - 0x11c180)
 *
 * Überblick
 * Diese Einheit enthält eine Aufräumroutine zum Löschen temporärer Dateien im Verzeichnis ..\TEMP\ sowie den
 * Konstruktor, Destruktor und die Zugriffsmethoden der Klasse Stock (stock.cpp), die verkettete
 * Gegenstandsbestände (etwa für Händler, Kräuterkundige und Beutecontainer) im Speicher verwaltet.
 === Ende Beschreibung === */
// P1 4/5 gleich
// gz_11c070.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11C070-0x11C180
#include <string.h>
#include "RIVAMEM.H"



int f_11c180(int p1, int p2);
int f_14572e(char *p1, const char *p2, ...);
short f_1492b4(char *p1, int p2, void *p3);
int f_149336(char *p1);
short f_1492d1(void *p1);
int f_1492ed(void *p1);
int f_15f2b5(char *p1);
extern const char *d_1a9674;
extern char d_1b8364[];
extern char d_1c2148[];
extern char d_1c21b4[];
struct FT { char r[30]; char name[13]; };
struct N { char *a; char *b; N *next; };
struct S { short s; N *h; char *p6; short pad; int fc; };
//@ f_11c070
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchsucht beim Aufräumen das temporäre Arbeitsverzeichnis ..\TEMP\*.*, löscht sämtliche darin
 *   gefundenen Dateien und schließt anschließend das globale System-Handle (d_1c2148).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Programm-/Start-Objekt und in p2 einen
 *   ungenutzten Parameter.
 * - Rückgabewert: Die Funktion gibt den übergebenen Zeiger p1 zurück.
 === Ende Beschreibung === */
int f_11c070(int p1, int p2)
{
  FT st;
  f_14572e(d_1c21b4, d_1a9674, d_1b8364);
  if (!f_1492b4(d_1c21b4, 0, &st)) {
    do {
      f_14572e(d_1c21b4, d_1a9674, st.name);
      f_149336(d_1c21b4);
    } while (!f_1492d1(&st));
  }
  f_1492ed(&st);
  f_15f2b5(d_1c2148);
  return p1;
}
//@ f_11c0f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor eines Bestands-Objekts (Stock), der die verkettete Liste initialisiert, den
 *   Preis-/Sperrfaktor (fc an Offset +12) speichert und die übergebene Gegenstandstabelle über f_11c180 in die
 *   Liste einfügt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Stock-Objekts, in p2 einen Zeiger auf das
 *   Array von Gegenstandsdatensätzen und in p3 den zugehörigen Faktor bzw. Statuswert.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
S *f_11c0f0(S *p1, int p2, int p3)
{
  p1->p6 = 0;
  p1->s = 0;
  p1->fc = p3;
  p1->h = (N *)p1->p6;
  f_11c180((int)p1, p2);
  return p1;
}
//@ f_11c120
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor eines Bestands-Objekts (Stock), der alle Knoten und dynamisch allokierten Gegenstandsdaten
 *   der verketteten Liste freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Stock-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
S *f_11c120(S *p1, int p2)
{
  N *h = p1->h;
  if (h) {
    if (h) {
      do {
        operator delete(h->a);
        if (h->b) operator delete(h->b);
        h = h->next;
      } while (h);
    }
    operator delete(p1->p6);
  }
  return p1;
}
//@ f_11c160
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert den im Bestands-Objekt (Stock) gespeicherten Faktor bzw. Statuswert (fc an Offset +12)
 *   zurück.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Stock-Objekts.
 * - Rückgabewert: Die Funktion gibt den ganzzahligen Feldwert p1->fc zurück.
 === Ende Beschreibung === */
int f_11c160(S *p1)
{
  return p1->fc;
}
//@ f_11c170
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt den Faktor bzw. Statuswert (fc an Offset +12) im Bestands-Objekt (Stock) auf einen neuen Wert.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Stock-Objekts und in p2 den neuen Wert.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11c170(S *p1, int p2)
{
  p1->fc = p2;
}
