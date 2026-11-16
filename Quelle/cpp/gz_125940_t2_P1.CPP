/* === Beschreibung (Katalog) ===
 * Einheit gz_125940_t2 (0x125dc0 - 0x1261b0)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des Spielzeit- und Kalender-Moduls (time.cpp, globales Uhrzeit-Objekt
 * d_1c2c44) und implementiert die Funktionen zum Vorspulen der Spielzeit um Ticks, Minuten, Stunden, Tage,
 * Monate und Jahre bzw. bis zu einer bestimmten Tageszeit.
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 2/10 gleich (suche.py 26.10.2026, Basis gz_125940_P1.CPP)
// gz_125940.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x125940-0x1261B0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0463e0(int p1);                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
char * f_0a7890(RivaItemDefinition *item);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
signed char f_0d0180(int p1);                                   // reg eax stapel 0
int f_0d03f0(int p1);                                   // reg eax stapel 0
int f_1261b0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0c64;                    // 0x1C0C64
extern int d_1c0c94;                    // 0x1C0C94
extern int d_1c2c60;                    // 0x1C2C60
// --- eigene Funktionen (10), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#define VT(o,off) (*(int*)(*(int*)((o)+1)+(off)))
//@ f_125dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit im Zeit-Objekt p1 schrittweise bis zur angegebenen Tageszeit p2 (in Ticks, bei
 *   kleinerem Zielwert bis zum nächsten Tag mit 0x1fa40 = 129600 Ticks pro Tag) vor und führt in jedem Schritt
 *   die Einzel-Tick-Aktualisierung (f_1261b0) sowie die Hintergrund-Ereignisprüfung (f_069460) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts (d_1c2c44) und in p2 die
 *   Ziel-Tageszeit in Ticks.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125dc0(int p1, int p2)
{
  int n = (p2 < *(volatile int *)(p1 + 1)) ? 0x1fa40 - (*(int *)(p1 + 1) - p2) : p2 - *(volatile int *)(p1 + 1); // erzwingt getrenntes Laden von *(int *)(p1 + 1) in beiden Zweigen wie im Original
  int p = p1;
  int bound = n;
  int sv, i;
  signed char c;
  sv = *(volatile int *)&d_1c0c94; c = 0; d_1c0c94 = 0; i = 0; // haelt die Initialisierungsreihenfolge vor der Schleife wie im Original
  for (; i < bound; i++) { f_1261b0(p); if (d_1c0c64 != 0) c++; if (c >= 2) d_1c0c94 = sv; else d_1c0c94 = 0; f_069460(); if (d_1c0c64 == 0) c = 0; }
  f_0463e0((int)&d_1c2c60); d_1c0c94 = sv;
}

//@ f_125e50
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um genau p2 einzelne Zeitticks vor und aktualisiert nach dem Durchlauf die
 *   Bildschirmanzeige (f_0463e0).
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   vorzuspulenden Ticks.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125e50(int p1, int p2)
{
  signed char c;
  int sv, i, r, n;
  sv = d_1c0c94; c = 0; *(volatile int *)&d_1c0c94 = 0; i = 0; // haelt xor dl,dl vor xor ebx,ebx wie im Original
  for (; i < p2; i++) { f_1261b0(p1); if (d_1c0c64 != 0) c++; if (c >= 2) d_1c0c94 = sv; else d_1c0c94 = 0; f_069460(); if (d_1c0c64 == 0) c = 0; }
  f_0463e0((int)&d_1c2c60); d_1c0c94 = sv;
}

//@ f_125ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 Spielminuten (jeweils 90 Ticks pro Minute, also p2 * 90 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Minuten.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der anschließenden Anzeigeaktualisierung (f_0463e0) zurück.
 === Ende Beschreibung === */
int f_125ed0(int p1, int p2)
{
  int n = p2 * 90;
  int p = p1;
  int bound = n;
  int sv, i, r;
  signed char c;
  sv = d_1c0c94; c = 0; *(volatile int *)&d_1c0c94 = 0; i = 0; // verhindert das Verschraenken der Schleifeninitialisierung mit p2 * 90
  for (; i < bound; i++) { f_1261b0(p); if (d_1c0c64 != 0) c++; if (c >= 2) d_1c0c94 = sv; else d_1c0c94 = 0; f_069460(); if (d_1c0c64 == 0) c = 0; }
  r = f_0463e0((int)&d_1c2c60); d_1c0c94 = sv; return r;
}

//@ f_125f60
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalter-Funktion im Zeitmodul.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125f60(void)
{
}

//@ f_125f70
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 Spielstunden (jeweils 5.400 Ticks pro Stunde, also p2 * 5400 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Stunden.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 als signed char zurück.
 === Ende Beschreibung === */
signed char f_125f70(int p1, int p2)
{
  int i;
  int n = p2 * 5400;
  int bound = n;
  int sv, r;
  signed char c;
  sv = d_1c0c94;
  c = 0;
  d_1c0c94 = 0;
  i = 0;
  for (; i < bound; i++) {
    f_1261b0(p1);
    if (d_1c0c64 != 0) c++;
    if (c >= 2) *(volatile int *)&d_1c0c94 = sv; // verhindert das Verschraenken der Schleifeninitialisierung mit p2 * 5400
    else d_1c0c94 = 0;
    f_069460();
    if (d_1c0c64 == 0) c = 0;
  }
  r = f_0463e0((int)&d_1c2c60); d_1c0c94 = sv; return r;
}

//@ f_126000
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle Spieltage (jeweils 0x1fa40 = 129.600 Ticks pro Tag) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Tage.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */
int f_126000(int p1, int p2)
{
  int i;
  int n = p2 * 0x1fa40;
  int bound = n;
  int sv, r;
  signed char c;
  sv = d_1c0c94;
  c = 0;
  d_1c0c94 = 0;
  i = 0;
  for (; i < bound; i++) { f_1261b0(p1); if (d_1c0c64 != 0) c++; if (c >= 2) d_1c0c94 = sv; else *(volatile int *)&d_1c0c94 = 0; f_069460(); if (d_1c0c64 == 0) c = 0; } // haelt Registerfolge und Scheduling vor der Schleife wie im Original
  r = f_0463e0((int)&d_1c2c60); d_1c0c94 = sv; return r;
}

//@ f_126090
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle Monate zu je 30 Tagen (p2 * 3.888.000 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Monate.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */
int f_126090(int p1, int p2)
{
  int i;
  int n = p2 * 3888000;
  int bound = n;
  int sv, r;
  signed char c;
  sv = *(volatile int *)&d_1c0c94; // verhindert das Verschraenken der Schleifeninitialisierung mit p2 * 3888000
  c = 0;
  d_1c0c94 = 0;
  i = 0;
  for (; i < bound; i++) { f_1261b0(p1); if (d_1c0c64 != 0) c++; if (c >= 2) d_1c0c94 = sv; else d_1c0c94 = 0; f_069460(); if (d_1c0c64 == 0) c = 0; }
  r = f_0463e0((int)&d_1c2c60); d_1c0c94 = sv; return r;
}

//@ f_126120
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle aventurische Jahre zu je 365 Tagen (p2 * 47.304.000 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Jahre.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */
int f_126120(int p1, int p2)
{
  int i;
  int n = p2 * 47304000;
  int bound = n;
  int sv, r;
  signed char c;
  sv = d_1c0c94; c = 0; d_1c0c94 = 0; i = 0;
  for (; i < bound; i++) {
    f_1261b0(p1);
    if (d_1c0c64 != 0) c++;
    if (c >= 2) d_1c0c94 = sv;
    else d_1c0c94 = 0;
    f_069460();
    if (d_1c0c64 == 0) c = 0;
  }
  r = f_0463e0((int)&d_1c2c60); *(volatile int *)&d_1c0c94 = sv; return r; // verhindert das Verschraenken der Schleifeninitialisierung mit p2 * 47304000
}
