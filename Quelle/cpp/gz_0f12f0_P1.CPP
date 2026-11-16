/* === Beschreibung (Katalog) ===
 * Einheit gz_0f12f0
 *
 * Diese Einheit enthält die Steuerung und Zeitüberwachung des Bildschirmschoners (gz_0f12f0), die bei fehlenden
 * Maus- und Tastatureingaben nach Ablauf der eingestellten Wartezeit einen der Bildschirmschoner-Effekte aus
 * screensa startet und während der Effektschleife auf Benutzereingaben prüft.
 === Ende Beschreibung === */
// P3 4/5 gleich (suche.py 29.10.2026, Basis gz_0f12f0_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// P1 3/5 gleich
// gz_0f12f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F12F0-0x0F1580
#include <string.h>
#include <bios.h>
int f_099ea0();
int f_0d4163(int p1);
int f_0d4880(int p1);
void f_0f04c0(int p1);
void f_0f0790(int p1);
void f_0f09b0(int p1);
void f_0f1020(int p1);
int f_13e240();
int f_144570();
int f_144bf0(const char *a, const char *b);
int f_1457e0(int p1);
int f_146dfa(int p1, int p2);
int f_149d20();
void f_148534(int p1);
extern short d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fc;
extern short d_1bf4fe;
extern int d_1bf4e8;
extern int d_1c0170;
extern int d_1c0174;
extern short d_1c219e;
extern int d_1c2e78;
extern int d_1c2edc;
#define BODY(Q) f_099ea0(); if (_bios_keybrd(1)) { if (_bios_keybrd(0) == 0x1011) { f_144570(); f_148534(0); } else { f_0d4880(p1); f_149d20(); } } if (d_1bf4e8 != 0) { f_0d4880(p1); d_1bf4e8 = 0; } if (d_1bf4f0 != d_1bf4fc || d_1bf4f2 != d_1bf4fe) f_0d4880(p1); if (Q) { f_0d4163((int)&d_1c2e78); f_146dfa((int)&d_1c2edc, 1); d_1c219e = 0; }
inline void h_poll(int p1) { BODY(d_1c219e == 1) }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0f12f0  groesse 80 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wählt beim Aktivieren des Bildschirmschoners per Zufallsgenerator (f_1457e0(3) - 1)
 *   einen der Bildschirmschoner-Effekte aus screensa (f_0f04c0, f_0f0790, f_0f09b0 oder f_0f1020) aus und
 *   startet ihn (wobei Fall 3 durch den Parameter 3 statt 4 nie erreicht wird).
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert des aufgerufenen Bildschirmschoner-Effekts zurück.
 === Ende Beschreibung === */
void f_0f12f0(int p1)
{
  if (f_13e240() != 0) { f_0f04c0(p1); return; }
  switch ((unsigned short)(f_1457e0(3) - 1)) {
  case 0: f_0f04c0(p1); return;
  case 1: f_0f0790(p1); return;
  case 2: f_0f09b0(p1); return;
  case 3: f_0f1020(p1); return;
  }
}

//@ f_0f1340  groesse 336 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion bildet die Warteschleife zwischen zwei Animationsschritten des Bildschirmschoners,
 *   fragt dabei über den BIOS-Tastaturinterrupt (int 0x16), den Mausstatus (d_1bf4e8, d_1bf4f0, d_1bf4f2) und
 *   die Screenshot-Tastenkombination (Alt+Q / 0x1011) ab, ob der Benutzer aktiv geworden ist, und signalisiert
 *   bei einer Eingabe das sofortige Ende des Bildschirmschoners.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1) sowie die Anzahl der abzuwartenden
 *   Zeitschritte (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Bildschirmschoner durch eine Benutzereingabe beendet
 *   werden soll, oder 0, wenn die Pause ohne Eingabe verstrichen ist.
 === Ende Beschreibung === */
int f_0f1340(int p1, short n)
{
  short result = 0;
  short k;
  d_1c0170 |= d_1c0174;
  for (k = 0; k < n; ++k) {
    if (d_1c0170) {
    h_poll(p1);
    if (!d_1c0170 && d_1c0174) {
      d_1c0174 = 0;
      d_1c0170 = 1;
    }
    } else { result = 1; break; }
  }
  return result;
}

//@ f_0f1490  groesse 208 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sichert vor dem Start eines Bildschirmschoners den aktuellen Bildschirminhalt und den
 *   Mauszeigerstatus in einem Hintergrundpuffer, damit das Spielbild beim Aufwecken nahtlos wiederhergestellt
 *   werden kann.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Grafik-Kontext (p1).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Bildschirmpuffer erfolgreich gesichert wurde, oder 0 bei
 *   Speichermangel.
 === Ende Beschreibung === */
void f_0f1490(int p1)
{
  // KRUECKE: codeloser Roundtrip stellt den Registergleichstand wieder her.
  int saved = d_1bf4e8;
  d_1bf4e8 = saved;
  BODY(d_1c219e == 1)
}

//@ f_0f1560  groesse 16 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet den Bildschirmschoner global frei oder sperrt ihn, indem sie das
 *   entsprechende Steuerflag (d_1c0170) setzt.
 * - Eingaben: Die Funktion erhält den gewünschten Freigabestatus (p1).
 * - Rückgabewert: Die Funktion gibt den gesetzten Statuswert zurück.
 === Ende Beschreibung === */
void f_0f1560(int p1)
{
  *(int *)(p1 + 8) = 0;
}

//@ f_0f1570  groesse 16 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt das Anforderungsflag (d_1c0174), mit dem ein laufender Bildschirmschoner beim
 *   nächsten Prüfschritt beendet wird.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück.
 === Ende Beschreibung === */
int f_0f1570(const char *a, const char *b)
{
  return f_144bf0(a, b);
}
