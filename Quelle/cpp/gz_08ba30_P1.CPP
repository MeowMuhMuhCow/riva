/* === Beschreibung (Katalog) ===
 * Einheit gz_08ba30 (08ba30 - 08bcd0)
 *
 * Überblick
 * Die Einheit gz_08ba30 steuert die abwechselnde Zugreihenfolge zwischen Heldengruppe und Monstern innerhalb
 * einer Kampfrunde (f_08ba30) und ordnet speziellen Kampfbegegnungen eine Kennung für kampfspezifische
 * Sonderregeln zu (f_08bc00).
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 25.10.2026, Basis gz_08ba30_P1.CPP)
// gz_08ba30.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08BA30-0x08BCD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030a40(int p1);                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
int f_07aab0(int p1);
#pragma aux f_07aab0 parm [eax] modify exact [eax]
int f_07b150(int p1, int p2);                           // reg edx stapel 0
int f_07b6b0(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_07eba0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_08af80(int p1);                                   // reg eax stapel 0
int f_08b500(int p1);                                   // reg eax stapel 0
int f_08c820(int p1);                                   // reg eax stapel 0
signed char f_145760(int p1, int p2);                    // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1bd90c;                    // 0x1BD90C
extern short d_1bd920;                    // 0x1BD920
extern short d_1bd924;                    // 0x1BD924
extern char d_1bd928;                    // 0x1BD928
extern int d_1c0004;                    // 0x1C0004
// --- eigene Funktionen (2), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_08ba30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine komplette Kampfrunde durch, indem sie die Anzahl der handlungsfähigen Helden
 *   (first) und Monster (second) ermittelt, anhand des Überraschungsstatus (p1 + 0x1e8) oder per Münzwurf die
 *   startende Seite bestimmt und in einer Schleife abwechselnd Heldenzüge (f_08af80) und Monsterzüge (f_08b500)
 *   aufruft, bis alle Teilnehmer gezogen haben oder der Kampf endet (d_1bd90c == 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Zu Rundenbeginn ruft die Funktion f_08c820 auf, um ausbrechende Spezialkacheln (wie
 *   schlüpfende Kreaturen oder einstürzende Felder) auf dem Kampfraster zu prüfen.
 === Ende Beschreibung === */
void f_08ba30(int p1)
{
  // KRUECKE: berechnete Names-Reihenfolge fuer die Stapelplaetze.
  short second;
  signed char direction;
  short first;
  short count;
  count=0; direction=0;
  short old_state;
  signed char b1;
  unsigned char b2;
  if (d_1bd928) f_069460();
  if (!f_07aab0(p1)) d_1bd90c = 0;
  first = f_030a40(d_1c0004);
  // KRUECKE: globaler WORD-Alias entfernt einen Sortierknoten (t28 vor t27).
  second = f_07b150(p1, (short)*(unsigned short *)&d_1bd924);
  count = 0;
  direction = *(short *)(p1 + 0x1e8) == 2 ? 1 :
              *(short *)(p1 + 0x1e8) == 1 ? 0 : f_145760(0, 1);
  *(short *)(p1+0x1e8)=0;
  if(d_1bd90c)f_08c820(p1);
  while (d_1bd90c && first + second > 0) {
    if (d_1bd928) f_069460();
    if (count == (short)0)
      f_07b6b0(p1, (int)&direction, (int)&count, first, second);
    if (direction == 0) {
      f_08af80(p1);
      if (d_1bd90c && !f_07aab0(p1)) d_1bd90c = 0;
      first = first - 1;
      count = count - 1;
    } else {
      f_08b500(p1);
      if (d_1bd90c && !f_07aab0(p1)) d_1bd90c = 0;
      second = second - 1;
      count = count - 1;
    }
    if (*(signed char *)(p1 + 0x293) != (signed char)-1) {
      f_07eba0(p1 + 0x39, (unsigned char)*(signed char *)(p1 + 0x293), 0);
      *(unsigned char *)(p1 + 0x293) = 0xff;
    }
    if (*(signed char *)(p1+0x294) != (signed char)-1) {
      f_07eba0(p1+0x39, (unsigned char)*(signed char *)(p1+0x294), 0);
      *(unsigned char *)(p1+0x294)=255;
    }
    if (d_1bd928) f_069460();
  }
}
//@ f_08bc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ordnet einer Kampfbegegnungsnummer (a) aus FIGHT.LST eine interne Sonderkampf-Kategorie (1..8,
 *   oder 0 für normale Kämpfe) zu, über die das Kampfsystem Spezialregeln für Boss- und Storykämpfe (wie
 *   Unterwasserkämpfe, Endkampf, Arena oder unsterbliche Gegner) aktiviert.
 * - Eingaben und Rückgabe: Die Funktion nimmt die Kampfnummer a (unsigned short) entgegen und gibt die
 *   zugehörige Sonderkampf-Kennung (0..8) zurück.
 * - Wichtige Variablen: Wenn die globale Variable d_1bd920 auf -1 steht (Sonderkämpfe deaktiviert), gibt die
 *   Funktion unabhängig von a sofort 0 zurück.
 === Ende Beschreibung === */
int f_08bc00(unsigned short a)
{
  int r = 0; if (d_1bd920 == -1) return r;
  switch (a) {
  case 0x5e: case 0x5f: case 0x60: case 0x61: case 0x62: case 0x63: r = 1; break;
  case 0x81: r = 2; break;
  case 0x5c: r = 4; break;
  case 0x82: r = 5; break;
  case 0x3b: r = 6; break;
  case 0x97: r = 7; break;
  case 8: case 10: case 0x1f: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x41: case 0x42: case 0x43: case 0x5d: r = 3; break;
  case 0x3c: r = 8; break;
  }
  return r;
}
