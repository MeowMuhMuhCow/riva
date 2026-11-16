/* === Beschreibung (Katalog) ===
 * Einheit gz_108d10_rand910b (1091c0 - 109430)
 *
 * Überblick
 *
 * Die Einheit gz_108d10_rand910b setzt den in gz_108d10_rand910a begonnenen Listen- und Ressourcen-Container
 * fort und implementiert das Einfügen, Suchen, Entfernen und Auswerten von Listenelementen (f_1091c0 bis
 * f_109330).
 === Ende Beschreibung === */
#include "RIVACTX.H"
// P3 8/10 gleich (suche.py 26.10.2026, Basis gz_108d10_P1.CPP)
// gz_108d10.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x108D10-0x109430
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_03aa20(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2);                                   // reg eax stapel 0
int f_0b9060(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_0bf820(int p1, ...);                                         // reg - stapel 0
int f_0dbb50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
char f_0dd410(int p1, int p2);                           // reg edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0fb630(int p1, int p2);                           // reg eax stapel 0
int f_0fbc60();                                         // reg - stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_1094e0(int p1);                                   // reg eax stapel 0
int f_109800(int p1);                                   // reg eax stapel 0
int f_109c20();                                         // reg - stapel 0
int f_109f30(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_145234(int p1, int p2);
int f_145254();
int f_145300(int p1, int p2, int p3);
extern char d_1bb804[];
extern char d_1bb84c[];
extern char d_1bb860[];
extern char d_1bf230[];
extern int d_1c0004;
extern signed char d_1c030c;
extern signed char d_1c0370;
extern signed char d_1c0384;
extern signed char d_1c0388;
extern signed char d_1c03ac;
extern short d_1c03ad;
extern unsigned char d_1c03b0;
extern short d_1c03b1;
extern unsigned char d_1c03b4;
extern unsigned short d_1c03b5;
extern unsigned char d_1c03b8;
extern short d_1c03b9;
extern unsigned short d_1c212a;
extern int d_1c212c;
extern short d_1c2198;
extern short d_1c219a;
extern char d_1c2c44[];
extern char d_1c2c64[];
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];
#define CH ((int)d_1c2c64)

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_108d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sieben Funktionen gehören zum ersten Teil der gesplitteten Einheit und sind in
 *   gz_108d10_rand910a.md beschrieben.
 * - Eingaben: Siehe gz_108d10_rand910a.md.
 * - Rückgabewert: Siehe gz_108d10_rand910a.md.
 === Ende Beschreibung === */
int f_0fbc60(int p1);
void f_108d10(int p1)
;
//@ f_108fa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet das Öffnen einer verschlossenen Schiffstür in ship3 an den Koordinaten (p2,
 *   p3) mithilfe des Schlüssels p4 oder einer Talent-/Kraftprobe und setzt das Türflag *p5.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Koordinaten p2 und p3, die Schlüssel-ID p4 sowie den
 *   Zeiger p5 auf das Zustandsbyte.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_108fa0(int p1)
;
//@ f_109020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode beendet beim Verlassen von ship3 die laufenden 3D-Unterwasser- und Lichteffekte
 *   (f_120ce0, f_1231b0).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_109020(void)
;

//@ f_109050
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert die Dungeon-Kennung 0x2c (44) von ship3 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 0x2c zurück.
 === Ende Beschreibung === */
void f_109050(void)
;

//@ f_109060
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die 9-Byte-Zustandsstruktur von ship3 bzw. den COMDAT-Destruktor-Wrapper
 *   des Objekts.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 (sowie optional Destruktor-Flags p2).
 * - Rückgabewert: Die Funktion gibt den Objektzeiger zurück bzw. endet ohne Rückgabewert (void).
 === Ende Beschreibung === */
void f_109060(void)
;
//@ f_1090c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert einen Listen- oder Ressourcen-Container, legt die internen Zeiger
 *   und Zähler an und bereitet die verkettete Liste (f_038b70) für die Aufnahme von Elementen vor.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie Konfigurationsparameter (p2, p3).
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_1090c0(void)
;
//@ f_109180
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_108d10_rand910a) gibt
 *   alle in der Liste des Containers (f_1090c0) gespeicherten Knoten und Puffer wieder frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück (int).
 * - Wichtige Variablen: In gz_108d10_rand910b als Vorwärtsdeklaration geführt.
 === Ende Beschreibung === */
int f_109180(int p1, int p2)
;
//@ f_1091c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode erzeugt einen neuen Listeneintrag im Container, initialisiert dessen Felder mit den
 *   übergebenen Parametern und hängt ihn in die verkettete Liste (f_038e70) ein.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Elementdaten (p2, p3, p4).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den neu angelegten Eintrag oder einen Statuscode zurück.
 === Ende Beschreibung === */
void f_1091c0(void)
{
  struct Obj { signed char a; short b; };
  struct Reg { short count; Obj **list; };
  extern Obj oac, ob0, ob4, ob8;
  extern Reg r;
#pragma aux oac "d_1c03ac"
#pragma aux ob0 "d_1c03b0"
#pragma aux ob4 "d_1c03b4"
#pragma aux ob8 "d_1c03b8"
#pragma aux r "d_1c212a"
  struct Helper {
    void add(Obj &o, Reg &r, short id) {
      signed char c = 0;
      o.a = c;
      o.b = id;
      r.list[r.count] = &o;
      r.count++;
    }
  } h;
  h.add(oac, r, 0x98);
  h.add(ob0, r, 0x99);
  h.add(ob4, r, 0x9a);
  short n = r.count;
  signed char z = 0;
  ob8.b = 0xe;
  ob8.a = z;
  r.list[n] = &ob8;
  r.count++;
}
//@ f_109290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode durchsucht die verkettete Liste des Containers nach einem Eintrag mit der Kennung p2
 *   und gibt das zugehörige Element zurück.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den gesuchten Schlüsselwert p2.
 * - Rückgabewert: Die Funktion gibt den gefundenen Elementzeiger oder 0 zurück.
 === Ende Beschreibung === */
int f_109290(int p1, int p2)
{
  int t = f_0b8490(p1, (short)p2);
  *(int *)(t + 0x58) = (int)d_1bb860;
  *(short *)(t + 0x5e) = 0;
  *(int *)(t + 0x60) = 0;
  *(int *)(t + 0x66) = 0;
  *(short *)(t + 0x5c) = (short)p2;
  *(int *)(t + 0x6a) = 0;
  f_145300(t + 0x6e, 0, 4);
  return t;
}
//@ f_1092e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode entfernt ein bestimmtes Element aus der verketteten Liste des Containers und gibt
 *   dessen Speicher frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Kennung bzw. den Zeiger p2 des zu löschenden
 *   Eintrags.
 * - Rückgabewert: Die Funktion gibt den Status der Löschoperation zurück.
 === Ende Beschreibung === */
int f_1092e0(int p1, int p2)
{
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb84c); f_145254();
    return p1;
  }
  *(int *)(p1 + 0x58) = (int)d_1bb860;
  int r = f_0b8520(p1, 1);
  if (p2 & 2) delete (char *)r;
  return r;
}
//@ f_109330
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode durchläuft sämtliche aktiven Einträge des Containers und führt für jeden Knoten die
 *   zugehörige Aktualisierungs- oder Zeichenoperation aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie einen Kontextparameter p2.
 * - Rückgabewert: Die Funktion gibt den Ergebnisstatus des Durchlaufs zurück.
 === Ende Beschreibung === */
int f_109330(int p1, int p2)
{
  int r = 0;
  unsigned short key = p2;
  switch (key) {
  case 0x81:
    f_0b9060(p1);
    break;
  case 0x87:
    if ((int)*(short *)(p1 + 0x5c) == 0x1c)
      r = f_109c20();
    else
      f_1094e0(p1);
    break;
  case 0x88:
    f_109800(p1);
    break;
  case 0x8c: {
    int q = f_038d70(d_1c0004, 0x200001bf);
    if (q != 0 && (int)(short)f_03aa20(q, 0, 1, -1) != -3) {
      *(volatile short *)&d_1c2198 = 0; // verhindert Vorziehen von 0 vor den Aufruf f_03aa20 wie im Original
      *(volatile short *)&d_1c219a = 1; // erzwingt direktes Word-Immediate-Schreiben wie im Original
      f_125ed0((int)d_1c2c44, 0x1e);
    }
    break;
  }
  case 0x8e:
    f_109f30(p1);
    break;
  case 0x80:
    r = 1;
    break;
  }
  return r;
}
