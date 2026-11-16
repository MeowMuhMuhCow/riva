/* === Beschreibung (Katalog) ===
 * Einheit gz_09af30 (09af30-09b0f0)
 *
 * Überblick
 * Diese kleine Brückeneinheit zwischen gfx_t3 und headquar registriert sieben globale Quest- und
 * Gebäude-Zustandsvariablen in der zentralen Spielstandsliste d_1c212a und stellt den Konstruktor sowie
 * Destruktor des Hauptquartier-Gebäudeobjekts bereit.
 === Ende Beschreibung === */
// P3 2/3 gleich (suche.py 25.10.2026, Basis gz_09af30_P1.CPP)
// gz_09af30.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09AF30-0x09B0F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define A(x) ((int)&(x))
extern char d_1bdcf4; extern short d_1bdcf5;
extern char d_1bdcf8; extern short d_1bdcf9;
extern char d_1bdcfc; extern short d_1bdcfd;
extern char d_1bdd00; extern short d_1bdd01;
extern char d_1bdd04; extern short d_1bdd05;
extern char d_1bdd08; extern short d_1bdd09;
extern char d_1bdd0c; extern short d_1bdd0d;
extern int d_1bafb8;
extern int d_1bafcc;
extern short d_1c212a;
extern int *d_1c212c;
int f_10a260(int p1, int p2);
int f_10a270(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254();
#define INC d_1c212a++
#define REC(b,w,v) b = 0; w = v; d_1c212c[d_1c212a] = A(b); INC;
//@ f_09af30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert sieben globale 3-Byte-Zustandsobjekte (d_1bdcf4 bis d_1bdd0c) mit den Kennungen
 *   0x66, 0x5c, 0x63, 0x5f, 0x67, 0x60 und 0x61 auf den Startwert 0 und trägt ihre Adressen in die zentrale
 *   Spielstands-Registrierungstabelle d_1c212a ein.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Struktur d_1c212a (RegAF) verwaltet die Anzahl count und das Zeigerarray list der
 *   beim Speichern und Laden automatisch serialisierten Zustandsvariablen.
 === Ende Beschreibung === */
struct ObjAF { signed char a; short b; };
struct RegAF { short count; ObjAF **list; };
extern ObjAF d_af4, d_af8, d_afc, d_b00, d_b04, d_b08, d_b0c;
extern RegAF d_regaf;
#pragma aux d_af4 "d_1bdcf4"
#pragma aux d_af8 "d_1bdcf8"
#pragma aux d_afc "d_1bdcfc"
#pragma aux d_b00 "d_1bdd00"
#pragma aux d_b04 "d_1bdd04"
#pragma aux d_b08 "d_1bdd08"
#pragma aux d_b0c "d_1bdd0c"
#pragma aux d_regaf "d_1c212a"
inline signed char zero_af()
{
    signed char c = 0;
    return c;
}
inline void add_af(ObjAF &o, RegAF &r, short id)
{
    o.a = zero_af();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
void f_09af30(void)
{
    add_af(d_af4, d_regaf, 0x66);
    add_af(d_af8, d_regaf, 0x5c);
    d_afc.a = zero_af();
    d_afc.b = 0x63;
    d_regaf.list[d_regaf.count] = &d_afc;
    d_regaf.count++;
    d_b00.a = zero_af();
    d_b00.b = 0x5f;
    d_regaf.list[d_regaf.count] = &d_b00;
    d_regaf.count++;
    d_b04.a = zero_af();
    d_b04.b = 0x67;
    d_regaf.list[d_regaf.count] = &d_b04;
    d_b08.a = zero_af();
    d_regaf.count += 1;
    d_b08.b = 0x60;
    d_regaf.list[d_regaf.count] = &d_b08;
    d_regaf.count++;
    d_b0c.a = zero_af();
    d_b0c.b = 0x61;
    d_regaf.list[d_regaf.count] = &d_b0c;
    d_regaf.count++;
}
//@ f_09b080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Hauptquartier-Gebäudeobjekt (headquar) über den Basiskonstruktor f_10a260,
 *   trägt die virtuelle Methodentabelle d_1bafcc an Offset 0x58 ein und initialisiert das Statusfeld an Offset
 *   0x60 mit 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Gebäudekennung p2 (short) und gibt
 *   den initialisierten Objektzeiger zurück (int).
 * - Wichtige Variablen: Das Feld *(int *)(r + 0x58) speichert den Zeiger auf die Methodentabelle d_1bafcc, und
 *   *(int *)(r + 0x60) merkt sich, ob der Raum bereits betreten wurde.
 === Ende Beschreibung === */
int f_09b080(int p1, short p2)
{
  int r = f_10a260(p1, p2);
  *(int *)(r + 0x58) = A(d_1bafcc);
  *(int *)(r + 0x60) = 0;
  return r;
}
//@ f_09b0a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des Hauptquartier-Gebäudeobjekts, ruft den Basisdestruktor f_10a270 auf
 *   und gibt bei gesetztem Bit 2 in p2 den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2 (unsigned) und
 *   gibt die Objektadresse zurück (int).
 * - Wichtige Variablen: Bei Array-Freigaben (p2 & 4) wird der Typdeskriptor d_1bafb8 an f_145234 übergeben.
 === Ende Beschreibung === */
int f_09b0a0(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) { f_145234(p1, A(d_1bafb8)); f_145254(); return p1; }
  *(int *)(p1 + 0x58) = A(d_1bafcc);
  r = f_10a270(p1, 1);
  if (p2 & 2) operator delete((void *)r);
  return r;
}
