/* === Beschreibung (Katalog) ===
 * Einheit itemdist_t4 (0x0AB550 - 0x0AB880)
 *
 * Diese Einheit bildet den vierten Teil des Gegenstandsverteilungs-Fensters (p:\riva\source\cpp\itemdist.cpp)
 * und enthält das Heldenauswahl-Popup für den Positionstausch sowie die Steuerung der Bildlaufleiste des
 * Gegenstandsgitters.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/3 gleich (suche.py 25.10.2026, Basis itemdist_t4_P1.CPP)
// itemdist_t4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AB550-0x0AB880
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
extern unsigned short d_1a49c2;
extern int d_1c2c64;
extern int d_1c29c4[7];
extern int d_1c3498;
#define RT void
#define RET(x) x; return;
#define RETP return;
#define RETX return;
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
#define REFRESH(p) f_01fb40((p)->o24, 0); if ((p)->s4c == 1) f_020640((p)->o24, (p)->s50, 0xfd);
#define ARGS (int)&d_1c2c64, p2, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]
int f_0bf680(int p1, int p2);
//@ f_0ab550
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet ein Auswahl-Popup (f_0bf820), das die Namen aller derzeit belegten Heldenplätze der
 *   Gruppe auflistet (f_0422b0), damit der Spieler einen Helden für den Platztausch auswählen kann.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie die
 *   Text-Ressourcenkennung der Überschrift (p2, z. B. erster oder zweiter Tauschpartner).
 * - Rückgabewert: Die Funktion gibt den nullbasierten Gruppenindex des gewählten Helden (0-6) oder -1 bei
 *   Abbruch zurück.
 === Ende Beschreibung === */
short f_0ab550(struct IT *p1, int p2)
{
  short n, i, s;
  int t;
  f_0bf6c0((int)&d_1c2c64, 3);
  n = 0;
  for (i = 0; i < 7; i++) {
    t = p1->a[i];
    if (f_027070(t)) {
      d_1c29c4[n++] = f_133fe0((int)&d_1c3498, ((int)(f_0422b0((struct hero *)(f_027070(t))))));
    }
  }
  s = (short)f_0bf820(ARGS) - 1;
  f_0bf680((int)&d_1c2c64);
  return s;
}
RT f_0ab6f0(struct IT *p1);
//@ f_0ab610
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verarbeitet Klicks auf die drei Bereiche der vertikalen Bildlaufleiste des
 *   Gegenstandsgitters: Pfeil nach oben (0xc2, f_01f6f0), Schiebebalken bzw. Schacht (0xc3, f_0ab6f0) und Pfeil
 *   nach unten (0xc4, f_01f7d0), und zeichnet anschließend Gitter sowie Scrollbalken neu.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Hotspot-Code des
 *   Scrollbalken-Elements (0xc2-0xc4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
RT f_0ab610(struct IT *p1, int p2)
{
  switch ((unsigned short)p2) {
  case 0xc2:
    f_01f6f0(p1->o24);
    f_01fb40(p1->o24, 0);
    if (p1->s4c == (short)1) f_020640(p1->o24, p1->s50, 0xfd);
    RET(p1->f_0ab8e0())
  case 0xc3:
    RET(f_0ab6f0(p1))
  case 0xc4:
    f_01f7d0(p1->o24);
    f_01fb40(p1->o24, 0);
    if (p1->s4c == (short)1) f_020640(p1->o24, p1->s50, 0xfd);
    RET(p1->f_0ab8e0())
  }
  RETP
}
//@ f_0ab6f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die Interaktion mit dem Schacht und dem Schieberegler der Bildlaufleiste: Klickt der
 *   Spieler oberhalb oder unterhalb des Reglers (verglichen mit der Maus-Y-Position bei Offset +0x54), wird
 *   seitenweise bzw. bei gedrückter rechter Maustaste (f_0d3800) direkt an den Anfang oder das Ende gescrollt;
 *   beim Ziehen des Reglers selbst wird die Gitterposition fortlaufend an die Reglerposition angepasst
 *   (f_1405c0, f_01f560).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
RT f_0ab6f0(struct IT *p1)
{
  int base = (short)d_1a49c2;
  if (p1->s54 < base + f_140360(p1->o28)) {
    if (f_0d3800()) {
      f_0d37e0();
      f_01fa70(p1->o24);
    } else {
      f_01f8b0(p1->o24);
    }
    f_01fb40(p1->o24, 0);
    if (p1->s4c == (short)1) f_020640(p1->o24, p1->s50, 0xfd);
    RET(p1->f_0ab8e0())
  }
  base = (short)d_1a49c2;
  if (p1->s54 > base + f_140360(p1->o28) + f_140370(p1->o28) - 1) {
    if (f_0d3800()) {
      f_0d37e0();
      f_01fa80(p1->o24);
    } else {
      f_01f990(p1->o24);
    }
    f_01fb40(p1->o24, 0);
    if (p1->s4c == (short)1) f_020640(p1->o24, p1->s50, 0xfd);
    RET(p1->f_0ab8e0())
  }
  if (f_01f620(p1->o24) < 100) {
    short v = f_01f480(p1->o24);
    f_1405c0(p1->o28);
    f_01f560(p1->o24, f_140380(p1->o28));
    if (f_01f480(p1->o24) != v) {
      f_01fb40(p1->o24, 0);
      if (p1->s4c == (short)1) f_020640(p1->o24, p1->s50, 0xfd);
    }
  }
  RETX
}
inline void IT::f_0ab880()
{
  short v = f_01f480(o24);
  f_1405c0(o28);
  f_01f560(o24, f_140380(o28));
  if (f_01f480(o24) != v) {
    REFRESH(this)
  }
}
inline RT IT::f_0ab8e0()
{
  f_140390(o28, f_01f490(o24), f_01f620(o24));
  RET(f_1404e0(o28))
}
