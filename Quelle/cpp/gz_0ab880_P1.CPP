/* === Beschreibung (Katalog) ===
 * Einheit gz_0ab880 (0x0AB880 - 0x0AB910)
 *
 * Diese Einheit enthält ausgelagerte Hilfsmethoden des Gegenstandsverteilungs-Fensters (itemdist.cpp) zur
 * Synchronisation zwischen Bildlaufleiste und Gegenstandsgitter.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P1 2/2 gleich
// gz_0ab880.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AB880-0x0AB910
#include <string.h>
#include "RIVAMEM.H"



short f_01f480(int p1);
short f_01f490(int p1);
int f_01f560(int p1, int p2);
short f_01f620(int p1);
int f_01f6f0(int p1);
int f_01f7d0(int p1);
int f_01f8b0(int p1);
int f_01f990(int p1);
int f_01fa70(int p1);
int f_01fa80(int p1);
int f_01fb40(int p1, int p2);
int f_020640(int p1, int p2, int p3);
int f_027070(int p1);

int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf820(int, ...);
int f_0d37e0();
int f_0d3800();
int f_133fe0(int p1, int p2);
short f_140360(int p1);
short f_140370(int p1);
short f_140380(int p1);
int f_140390(int p1, int p2, int p3);
int f_1404e0(int p1);
int f_1405c0(int p1);
extern short d_1a49c2;
extern int d_1c2c64;
extern int d_1c29c4[7];
extern int d_1c3498;
#define RT int
#define RET(x) return x;
#define RETP return p2;
#define RETX return 0;
struct IT {
  int z[2];
  int a[7];
  int o24;
  int o28;
  char pad[0x20];
  short s4c;
  short pad4e;
  short s50;
  short pad52;
  short s54;
  void f_0ab880();
  RT f_0ab8e0();
};
#define REFRESH(p) f_01fb40((p)->o24, 0); if ((p)->s4c == (short)1) f_020640((p)->o24, (p)->s50, 0xfd);
#define ARGS (int)&d_1c2c64, p2, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]
int f_0bf680(int p1, int p2);
//@ f_0ab880
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt das Ziehen des Scrollbalken-Reglers (f_1405c0) im Gegenstandsverteilungs-Fenster aus,
 *   überträgt die neue Scrollposition auf das Gegenstandsgitter (f_01f560) und zeichnet das Gitter samt
 *   Auswahlmarkierung neu, sobald sich die sichtbare Zeile geändert hat.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void IT::f_0ab880()
{
  short v = f_01f480(o24);
  f_1405c0(o28);
  f_01f560(o24, f_140380(o28));
  if (f_01f480(o24) != v) {
    REFRESH(this)
  }
}
//@ f_0ab8e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert die Position und Ausdehnung des Schiebebalkens (f_140390) anhand des aktuellen
 *   Zeilenoffsets und der Gesamtzahl des Gegenstandsgitters und zeichnet die Bildlaufleiste neu (f_1404e0).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der Scrollbalken-Zeichenfunktion (f_1404e0) zurück.
 === Ende Beschreibung === */
RT IT::f_0ab8e0()
{
  f_140390(o28, f_01f490(o24), f_01f620(o24));
  RET(f_1404e0(o28))
}
