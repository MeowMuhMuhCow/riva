/* === Beschreibung (Katalog) ===
 * Einheit gz_1155d0 (0x1155d0 - 0x115d80)
 *
 * Überblick
 * Diese Einheit schließt das Basismodul star.cpp ab und leitet in die erste Ebene des Bienenstocks (star1.cpp,
 * Dungeon-ID 7) über. Sie enthält Hilfsfunktionen für die Heldenauswahl im Bienenstock, den Konstruktor und
 * Destruktor der Basisklasse für die Bienenstock-Ebenen sowie die Registrierung und Initialisierung der
 * Zustandsvariablen der ersten Ebene (star1).
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 5/9 gleich (suche.py 24.10.2026, Basis gz_1155d0_P1.CPP)
// gz_1155d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1155D0-0x115D80
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_039040(int p1);                                   // reg eax stapel 0
int f_0418e0();                                         // reg - stapel 0
int f_0418f0(int p1, int p2);                                         // reg - stapel 0



int f_05ff60(int p1, int p2);
int f_060030(int p1);                           // reg eax stapel 0
int f_060240();                                         // reg - stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_116670(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c40;                    // 0x1C2C40
// --- eigene Funktionen (9), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#pragma inline_depth(0)
extern signed char d_1c0930, d_1c0934, d_1c0938, d_1c093c, d_1c0940, d_1c0944, d_1c0948, d_1c094c, d_1c0950, d_1c0954, d_1c0958, d_1c095c, d_1c0960, d_1c0964, d_1c0968, d_1c096c, d_1c0970, d_1c0974, d_1c0978, d_1c097c, d_1c0980, d_1c0984, d_1c0988, d_1c098c, d_1c0990, d_1c0994, d_1c0998, d_1c099c, d_1c09a0, d_1c09a4, d_1c09a8, d_1c09ac, d_1c09b0, d_1c09b4, d_1c09b8, d_1c09bc;
extern short d_1c0931, d_1c0935, d_1c0939, d_1c093d, d_1c0941, d_1c0945, d_1c0949, d_1c094d, d_1c0951, d_1c0955, d_1c0959, d_1c095d, d_1c0961, d_1c0965, d_1c0969, d_1c096d, d_1c0971, d_1c0975, d_1c0979, d_1c097d, d_1c0981, d_1c0985, d_1c0989, d_1c098d, d_1c0991, d_1c0995, d_1c0999, d_1c099d, d_1c09a1, d_1c09a5, d_1c09a9, d_1c09ad, d_1c09b1, d_1c09b5, d_1c09b9, d_1c09bd;
extern short d_1c212a;
extern signed char **d_1c212c;
extern int d_1bb900[], d_1bb948[];
#define REG(r) d_1c212c[d_1c212a++] = &r;

//@ f_1155d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Wählt je nach Modus (p2 == 0 oder p2 == 1) über f_1142c0 oder f_114340 einen geeigneten Begleitholden
 *   für Ereignisse im Bienenstock aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt und in p2 die Auswahlart (0
 *   oder 1).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den ausgewählten Helden zurück oder 0, falls keiner gefunden
 *   wurde.
 === Ende Beschreibung === */
int f_1155d0(int p1, int p2)
{
  int r = f_039040(d_1c0004);
  if (r != 0) {
    short c = f_042400((struct hero *)(r));
    if ((c != 7 && c != 8) || (p2 == 1 && f_0d4a60(r) == 0)) r = 0;
  }
  return r;
}

//@ f_115620
/* === Beschreibung (Katalog) ===
 * - Zweck: Schließt die gemeinsame Initialisierung einer Bienenstock-Ebene ab, indem nacheinander f_060240() und
 *   f_0418e0() aufgerufen werden.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Rückgabewert von f_0418e0() (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_115620(void)
{
  f_060240();
  return f_0418e0();
}

//@ f_115630
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor der gemeinsamen Basisklasse der Bienenstock-Dungeon-Ebenen, der den Basis-Dungeon-Handler
 *   initialisiert und dessen virtuelle Methodentabelle (d_1bb960) einträgt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 die Dungeon-ID.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_115630(int p1, int p2)
{
  int r = f_05ff60(p1, (int)(signed char)p2);
  *(int*)(r + 8) = (int)d_1bb900;
  return r;
}

//@ f_115640
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor der gemeinsamen Basisklasse der Bienenstock-Dungeon-Ebenen.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
void f_115640(int p1, int p2)
{
  *(int*)(p1 + 8) = (int)d_1bb900;
  f_0418f0(p1, 1);
  f_060030(p1);
}

//@ f_115660
/* === Beschreibung (Katalog) ===
 * - Zweck: Kurze Hilfs- bzw. Platzhalterfunktion des Bienenstock-Moduls, die konstant 0 zurückgibt.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Immer 0 (int).
 === Ende Beschreibung === */
int f_115660(void)
{
  return 0;
}

//@ f_115670
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die 36 persistenten Zustandsvariablen der ersten Bienenstock-Ebene (d_1c0930 bis
 *   d_1c09bc, mit den Kennungen 0x110..0x12d, 0x134, 0x1ac..0x1ae, 0x251, 0x252 und den Startzahlen 40, 60, 60
 *   für die Wächter-Schwärme in d_1c0930..d_1c0938) in der globalen Spielstands-Variablenliste d_1c212c
 *   (d_1c212a).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0930..d_1c09bc (Zustandsobjekte OR700V3_1156708), d_1c212a / d_1c212c (globale
 *   Registrierungsliste).
 === Ende Beschreibung === */
struct R115670 { signed char v; short id; };
#define PUT115670(D,I,K,V) { R115670 *p = (R115670 *)&D; short &n = d_1c212a; int * &t = (int *&)d_1c212c; p->v = V; p->id = K; t[++n] = (int)p; }
#define PUTK115670(D,I,K,V) { R115670 *p = (R115670 *)&D; short &n = d_1c212a; int * &t = (int *&)d_1c212c; p->v = V; p->id = K; t[++n] = (int)p; }
#define PUTB115670(D,I,K,V) { R115670 *p = (R115670 *)&D; signed char v = V; short &n = d_1c212a; int * &t = (int *&)d_1c212c; p->v = v; p->id = K; t[++n] = (int)p; }


#pragma inline_depth(10)
#pragma aux f_115620 "W?f_115620$n()i";
#pragma aux f_115630 "W?f_115630$n(ii)i";
struct E680{signed char value;short id;};
struct R680{short count;E680 **list;};
static inline void add680(E680 &o,R680 &r,short id,signed char value){o.value=value;o.id=id;r.list[r.count]=&o;r.count++;}
struct RR700V3_1156708;
struct OR700V3_1156708 { signed char flag; short number; char pad; OR700V3_1156708 *init(RR700V3_1156708 &r,short id,signed char f); };
struct RR700V3_1156708 { short count; OR700V3_1156708 **list; void append(OR700V3_1156708 *o) {list[count]=o;count++;} };
inline OR700V3_1156708 *OR700V3_1156708::init(RR700V3_1156708 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_1156708 regR700V3_1156708;
#pragma aux regR700V3_1156708 "d_1c212a"
extern OR700V3_1156708 obR700V3_115670_1c0930;
#pragma aux obR700V3_115670_1c0930 "d_1c0930"
extern OR700V3_1156708 obR700V3_115670_1c0934;
#pragma aux obR700V3_115670_1c0934 "d_1c0934"
extern OR700V3_1156708 obR700V3_115670_1c0938;
#pragma aux obR700V3_115670_1c0938 "d_1c0938"
extern OR700V3_1156708 obR700V3_115670_1c093c;
#pragma aux obR700V3_115670_1c093c "d_1c093c"
extern OR700V3_1156708 obR700V3_115670_1c0940;
#pragma aux obR700V3_115670_1c0940 "d_1c0940"
extern OR700V3_1156708 obR700V3_115670_1c0944;
#pragma aux obR700V3_115670_1c0944 "d_1c0944"
extern OR700V3_1156708 obR700V3_115670_1c0948;
#pragma aux obR700V3_115670_1c0948 "d_1c0948"
extern OR700V3_1156708 obR700V3_115670_1c094c;
#pragma aux obR700V3_115670_1c094c "d_1c094c"
extern OR700V3_1156708 obR700V3_115670_1c0950;
#pragma aux obR700V3_115670_1c0950 "d_1c0950"
extern OR700V3_1156708 obR700V3_115670_1c0954;
#pragma aux obR700V3_115670_1c0954 "d_1c0954"
extern OR700V3_1156708 obR700V3_115670_1c0958;
#pragma aux obR700V3_115670_1c0958 "d_1c0958"
extern OR700V3_1156708 obR700V3_115670_1c095c;
#pragma aux obR700V3_115670_1c095c "d_1c095c"
extern OR700V3_1156708 obR700V3_115670_1c0960;
#pragma aux obR700V3_115670_1c0960 "d_1c0960"
extern OR700V3_1156708 obR700V3_115670_1c0964;
#pragma aux obR700V3_115670_1c0964 "d_1c0964"
extern OR700V3_1156708 obR700V3_115670_1c0968;
#pragma aux obR700V3_115670_1c0968 "d_1c0968"
extern OR700V3_1156708 obR700V3_115670_1c096c;
#pragma aux obR700V3_115670_1c096c "d_1c096c"
extern OR700V3_1156708 obR700V3_115670_1c0970;
#pragma aux obR700V3_115670_1c0970 "d_1c0970"
extern OR700V3_1156708 obR700V3_115670_1c0974;
#pragma aux obR700V3_115670_1c0974 "d_1c0974"
extern OR700V3_1156708 obR700V3_115670_1c0978;
#pragma aux obR700V3_115670_1c0978 "d_1c0978"
extern OR700V3_1156708 obR700V3_115670_1c097c;
#pragma aux obR700V3_115670_1c097c "d_1c097c"
extern OR700V3_1156708 obR700V3_115670_1c0980;
#pragma aux obR700V3_115670_1c0980 "d_1c0980"
extern OR700V3_1156708 obR700V3_115670_1c0984;
#pragma aux obR700V3_115670_1c0984 "d_1c0984"
extern OR700V3_1156708 obR700V3_115670_1c0988;
#pragma aux obR700V3_115670_1c0988 "d_1c0988"
extern OR700V3_1156708 obR700V3_115670_1c098c;
#pragma aux obR700V3_115670_1c098c "d_1c098c"
extern OR700V3_1156708 obR700V3_115670_1c0990;
#pragma aux obR700V3_115670_1c0990 "d_1c0990"
extern OR700V3_1156708 obR700V3_115670_1c0994;
#pragma aux obR700V3_115670_1c0994 "d_1c0994"
extern OR700V3_1156708 obR700V3_115670_1c0998;
#pragma aux obR700V3_115670_1c0998 "d_1c0998"
extern OR700V3_1156708 obR700V3_115670_1c099c;
#pragma aux obR700V3_115670_1c099c "d_1c099c"
extern OR700V3_1156708 obR700V3_115670_1c09a0;
#pragma aux obR700V3_115670_1c09a0 "d_1c09a0"
extern OR700V3_1156708 obR700V3_115670_1c09a4;
#pragma aux obR700V3_115670_1c09a4 "d_1c09a4"
extern OR700V3_1156708 obR700V3_115670_1c09a8;
#pragma aux obR700V3_115670_1c09a8 "d_1c09a8"
extern OR700V3_1156708 obR700V3_115670_1c09ac;
#pragma aux obR700V3_115670_1c09ac "d_1c09ac"
extern OR700V3_1156708 obR700V3_115670_1c09b0;
#pragma aux obR700V3_115670_1c09b0 "d_1c09b0"
extern OR700V3_1156708 obR700V3_115670_1c09b4;
#pragma aux obR700V3_115670_1c09b4 "d_1c09b4"
extern OR700V3_1156708 obR700V3_115670_1c09b8;
#pragma aux obR700V3_115670_1c09b8 "d_1c09b8"
extern OR700V3_1156708 obR700V3_115670_1c09bc;
#pragma aux obR700V3_115670_1c09bc "d_1c09bc"
void f_115670(void) {
obR700V3_115670_1c0930.init(regR700V3_1156708,0x110,40);
obR700V3_115670_1c0934.init(regR700V3_1156708,0x111,60);
obR700V3_115670_1c0938.init(regR700V3_1156708,0x112,60);
obR700V3_115670_1c093c.init(regR700V3_1156708,0x113,0);
obR700V3_115670_1c0940.init(regR700V3_1156708,0x114,0);
obR700V3_115670_1c0944.init(regR700V3_1156708,0x115,0);
obR700V3_115670_1c0948.init(regR700V3_1156708,0x116,0);
obR700V3_115670_1c094c.init(regR700V3_1156708,0x117,0);
obR700V3_115670_1c0950.init(regR700V3_1156708,0x118,0);
obR700V3_115670_1c0954.init(regR700V3_1156708,0x119,0);
obR700V3_115670_1c0958.init(regR700V3_1156708,0x11a,0);
obR700V3_115670_1c095c.init(regR700V3_1156708,0x11b,0);
obR700V3_115670_1c0960.init(regR700V3_1156708,0x11c,0);
obR700V3_115670_1c0964.init(regR700V3_1156708,0x11d,0);
obR700V3_115670_1c0968.init(regR700V3_1156708,0x11e,0);
obR700V3_115670_1c096c.init(regR700V3_1156708,0x11f,0);
obR700V3_115670_1c0970.init(regR700V3_1156708,0x120,0);
obR700V3_115670_1c0974.init(regR700V3_1156708,0x121,0);
obR700V3_115670_1c0978.init(regR700V3_1156708,0x122,0);
obR700V3_115670_1c097c.init(regR700V3_1156708,0x123,0);
obR700V3_115670_1c0980.init(regR700V3_1156708,0x124,0);
obR700V3_115670_1c0984.init(regR700V3_1156708,0x125,0);
obR700V3_115670_1c0988.init(regR700V3_1156708,0x126,0);
obR700V3_115670_1c098c.init(regR700V3_1156708,0x127,0);
obR700V3_115670_1c0990.init(regR700V3_1156708,0x128,0);
obR700V3_115670_1c0994.init(regR700V3_1156708,0x129,0);
obR700V3_115670_1c0998.init(regR700V3_1156708,0x12a,0);
obR700V3_115670_1c099c.init(regR700V3_1156708,0x12b,0);
obR700V3_115670_1c09a0.init(regR700V3_1156708,0x12c,0);
obR700V3_115670_1c09a4.init(regR700V3_1156708,0x12d,0);
obR700V3_115670_1c09a8.init(regR700V3_1156708,0x134,0);
obR700V3_115670_1c09ac.init(regR700V3_1156708,0x1ac,0);
obR700V3_115670_1c09b0.init(regR700V3_1156708,0x1ad,0);
obR700V3_115670_1c09b4.init(regR700V3_1156708,0x1ae,0);
obR700V3_115670_1c09b8.init(regR700V3_1156708,0x251,0);
obR700V3_115670_1c09bc.init(regR700V3_1156708,0x252,0);
}


//@ f_115cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchläuft alle 31 Inventarplätze (0..0x1e) eines gefangenen oder abgelegten Helden p1, prüft für
 *   jeden vorhandenen Gegenstand sVar1, ob dieser nicht als unablösbar markiert ist (f_0a78f0() == 0), ermittelt
 *   bei stapelbaren Gegenständen (f_0a7950() != 0) die Stückzahl über f_042ac0 und legt den Gegenstand über
 *   f_113340(p2, sVar1, sVar2, 0) in den Beutecontainer p2.
 * - Eingaben: p1 (Zeiger auf den Helden), p2 (Zeiger auf den Ziel-Beutecontainer Spoil).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: sVar5 (Inventarslot 0..30), sVar1 (Gegenstands-ID), sVar2 (Stückzahl).
 === Ende Beschreibung === */
void f_115cc0(int p1, int p2)
{
  short sVar1; short sVar2; int iVar3; int iVar4; int p2_00; short sVar5;
  for (sVar5 = 0; sVar5 < 0x1f; sVar5 = sVar5 + 1) {
    p2_00 = sVar5;
    sVar1 = f_042a60((struct hero *)(p1), p2_00);
    if (0 < sVar1) {
      iVar4 = sVar1;
      iVar3 = ((RivaItemDefinition*)(((int*)d_1c2c40)[iVar4]))->f_0a78f0();
      if (iVar3 == 0) {
        iVar4 = ((RivaItemDefinition*)(((int*)d_1c2c40)[iVar4]))->f_0a7950();
        sVar2 = (iVar4 != 0) ? f_042ac0((struct hero *)(p1), p2_00) : 1;
        f_113340(p2, (int)sVar1, (int)sVar2, 0);
      }
    }
  }
}

//@ f_115d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor des Dungeon-Handlers für die erste Ebene des Bienenstocks (star1, Dungeon-ID 7): Er ruft
 *   den Basiskonstruktor f_115630(p1, 7) auf und trägt die virtuelle Methodentabelle d_1bb948 bei Offset +8 ein.
 * - Eingaben: p1 (this-Zeiger des Dungeon-Objekts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: iVar1 (initialisierter Objektzeiger), d_1bb948 (Vtable von star1).
 === Ende Beschreibung === */
void f_115d40(int p1)
{
  int iVar1 = f_115630(p1, 7);
  *(int*)(iVar1 + 8) = (int)d_1bb948;
}

//@ f_115d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Eintrittsmethode der ersten Bienenstock-Ebene (star1), die zunächst die Basisinitialisierung
 *   f_115620() ausführt und anschließend über f_116670(p1) die Eingangssequenz der Ebene startet.
 * - Eingaben: p1 (this-Zeiger des Dungeon-Objekts).
 * - Rückgabewert: Rückgabewert von f_116670(p1) (int).
 === Ende Beschreibung === */
int f_115d60(int p1)
{
  f_115620();
  return f_116670(p1);
}
