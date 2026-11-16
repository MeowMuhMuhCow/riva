/* === Beschreibung (Katalog) ===
 * Einheit gz_108d10_rand910a (108d10 - 1091c0)
 *
 * Überblick
 *
 * Die Einheit gz_108d10_rand910a enthält den Abschluss des ship3-Dungeons (f_108d10 bis f_109060) sowie die
 * ersten Verwaltungsfunktionen eines verketteten Animations- oder Ereignislisten-Managers (f_1090c0, f_109180),
 * der in gz_108d10_rand910b fortgesetzt wird.
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
extern int d_1c2198;
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
 * - Zweck: Diese Methode synchronisiert in ship3 alle aufgebrochenen Türen, Gitter und Luken anhand der
 *   aktuellen Zustandsflags (d_1c0418 ff.) mit der 3D-Geometrie.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des ship3-Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fbc60(int p1);
void f_108d10(int p1)
{
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  short r = 0x63;
  if (EQ(d_1c0388, 2))
    f_060770(0x1f41, 0);
  if (EQ(d_1c0388, 1)) {
    f_060770(0x1f41, 0);
    f_0bf730(CH, 0x2f000165);
    f_0de210(d_1c0004);
    f_0fbc60(p1);
  }
  if (EQ(d_1c0388, 0)) {
    if (EQ(d_1c0384, 0)) {
      if ((signed char)f_0dd410(d_1c0004, 1) == 5) {
        d_1c0384 = 1;
        r = f_0bf6f0(CH, 0x2f000156);
      }
    }
    if (r == 0x63 || r == (short)1) {
      int t = f_039320(d_1c0004, 0x33);
      o.tables.p[1] = t;
      r = f_0bf820(CH, 0x2f000157, 3, 0x2f000158, 0x2f000159, 0x2f00015a);
    }
    if (r == 1) {
      f_060770(0x1f41, 0);
      f_0bf730(CH, 0x2f00015b);
    }
    if (r == 2) {
      f_060770(0x1f41, 0);
      f_0bf730(CH, 0x2f00015c);
    }
    if (r == 1 || r == 2) {
      switch (f_0bf820(CH, 0x2f00015d, 4, 0x2f00015e, 0x2f00015f, 0x2f000160, 0x2f000161)) {
      case 1:
        d_1c0388 = 2;
        d_1c030c = 2;
        break;
      case 2:
        f_0bf730(CH, 0x2f000162);
        f_0bf730(CH, 0x2f000163);
        f_0bf730(CH, 0x2f000164);
        f_0de210(d_1c0004);
        break;
      case 4:
        f_0bf730(CH, 0x2f000166);
        d_1c0370 = 0;
        f_0fca60(p1);
        break;
      default:
        d_1c0388 = 1;
        break;
      }
    }
  }
}
//@ f_108fa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet das Öffnen einer verschlossenen Schiffstür in ship3 an den Koordinaten (p2,
 *   p3) mithilfe des Schlüssels p4 oder einer Talent-/Kraftprobe und setzt das Türflag *p5.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Koordinaten p2 und p3, die Schlüssel-ID p4 sowie den
 *   Zeiger p5 auf das Zustandsbyte.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_108fa0(int p1)
{
  switch ((short)f_0bf820(CH, 0x2f000167, 3, 0x2f000168, 0x2f000169, 0x2f00016a)) {
  case 1:
    d_1c0370 = 0;
    f_0fca60(p1);
    break;
  case 2:
    f_0bf730(CH, 0x2f00016b);
    f_0bf730(CH, 0x2f000163);
    f_0bf730(CH, 0x2f000164);
    f_0de210(d_1c0004);
    break;
  }
}
//@ f_109020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode beendet beim Verlassen von ship3 die laufenden 3D-Unterwasser- und Lichteffekte
 *   (f_120ce0, f_1231b0).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_109020(void)
{
  int r = f_0bf6f0(CH, 0x2f00016c);
  if (r != 1)
    return r;
  return f_0dd7f0(d_1c0004, 0x18, 0x146b);
}

//@ f_109050
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert die Dungeon-Kennung 0x2c (44) von ship3 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 0x2c zurück.
 === Ende Beschreibung === */
void f_109050(void)
{
}

//@ f_109060
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die 9-Byte-Zustandsstruktur von ship3 bzw. den COMDAT-Destruktor-Wrapper
 *   des Objekts.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 (sowie optional Destruktor-Flags p2).
 * - Rückgabewert: Die Funktion gibt den Objektzeiger zurück bzw. endet ohne Rückgabewert (void).
 === Ende Beschreibung === */
void f_109060(void)
{
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  f_038c40(d_1c0004);
  f_060800(0x2f000b, 0, 0);
  f_0dbb50(d_1c0004, 1, 6);
}
//@ f_1090c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert einen Listen- oder Ressourcen-Container, legt die internen Zeiger
 *   und Zähler an und bereitet die verkettete Liste (f_038b70) für die Aufnahme von Elementen vor.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie Konfigurationsparameter (p2, p3).
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_1090c0(void)
{
  RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
  o.tables.p[1] = f_038c40(d_1c0004);
  {
    RivaTextContext o2(d_1c349c, d_1c3870, d_1c3498);
    f_038c40(d_1c0004);
    f_060800(0x2f000b, 0, 0);
    f_0dbb50(d_1c0004, 1, 6);
  }
  f_0bf730(CH, 0x2f000174);
  f_0dbb50(d_1c0004, 1, 6);
  f_0bbf00((int)d_1bf230);
}
//@ f_109180
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt alle in der Liste des Containers (f_1090c0) gespeicherten Knoten und Puffer
 *   wieder frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 (sowie Destruktor-Flags p2).
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_109180(int p1, int p2)
{
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb804); f_145254();
    return p1;
  }
  int r = f_0fb630(p1, 1);
  if (p2 & 2) delete (char *)r;
  return r;
}
//@ f_1091c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese vier Funktionen sind im gemeinsamen Kopfbereich deklariert und werden in der nachfolgenden
 *   Teileinheit gz_108d10_rand910b definiert.
 * - Eingaben: Siehe gz_108d10_rand910b.md.
 * - Rückgabewert: Siehe gz_108d10_rand910b.md.
 === Ende Beschreibung === */
void f_1091c0(void)
;
//@ f_109290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_108d10_rand910b) durchsucht
 *   die verkettete Liste des Containers nach einem Eintrag mit der Kennung p2 und gibt das zugehörige Element
 *   zurück.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den gesuchten Schlüsselwert p2.
 * - Rückgabewert: Die Funktion gibt den gefundenen Elementzeiger oder 0 zurück (int).
 * - Wichtige Variablen: In gz_108d10_rand910a als Vorwärtsdeklaration geführt.
 === Ende Beschreibung === */
int f_109290(int p1, int p2)
;
//@ f_1092e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_108d10_rand910b) entfernt
 *   ein bestimmtes Element aus der verketteten Liste des Containers und gibt dessen Speicher frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Kennung bzw. den Zeiger p2 des zu löschenden
 *   Eintrags.
 * - Rückgabewert: Die Funktion gibt den Status der Löschoperation zurück (int).
 * - Wichtige Variablen: In gz_108d10_rand910a als Vorwärtsdeklaration geführt.
 === Ende Beschreibung === */
int f_1092e0(int p1, int p2)
;
//@ f_109330
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_108d10_rand910b) durchläuft
 *   sämtliche aktiven Einträge des Containers und führt für jeden Knoten die zugehörige Aktualisierungs- oder
 *   Zeichenoperation aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie einen Kontextparameter p2.
 * - Rückgabewert: Die Funktion gibt den Ergebnisstatus des Durchlaufs zurück (int).
 * - Wichtige Variablen: In gz_108d10_rand910a als Vorwärtsdeklaration geführt.
 === Ende Beschreibung === */
int f_109330(int p1, int p2)
;
