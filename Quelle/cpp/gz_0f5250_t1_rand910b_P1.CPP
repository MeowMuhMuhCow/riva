/* === Beschreibung (Katalog) ===
 * Einheit gz_0f5250_t1_rand910b
 *
 * Diese Einheit bildet die zweite Hälfte des ersten Teils der Kanalisations-Ereignissteuerung (gz_0f5250, Teil
 * 1b) und enthält den Haupt-Ereignisverteiler sowie die einzelnen Raum-, Schalter-, Fallen- und
 * Fundstellen-Handler für den ersten Abschnitt der Kanalisation von Riva.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 22/25 gleich (suche.py 25.10.2026, Basis gz_0f5250_t1_P1.CPP)
// gz_0f5250.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F5250-0x0F6FB0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (38), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern signed char d_1c01c0;
extern signed char d_1c01b0;
extern signed char d_1c0178;
extern signed char d_1c00c4;
extern signed char d_1bee0c;
extern signed char d_1c00bc;
extern signed char d_1c01cc;
extern signed char d_1c0200;
extern signed char d_1c0204;
extern short d_1c0208;
extern signed char d_1c01f8;
extern signed char d_1c01d8;
extern signed char d_1c01dc;
extern signed char d_1c01e0;
extern signed char d_1c01e4;
extern signed char d_1c01e8;
extern signed char d_1c01ec;
extern signed char d_1c01f0;
extern signed char d_1c01f4;
extern signed char d_1c01fc;
extern signed char d_1c020c;
extern signed char d_1c0210;
extern signed char d_1c0214;
extern short d_1c01d9;
extern short d_1c01dd;
extern short d_1c01e1;
extern short d_1c01e5;
extern short d_1c01e9;
extern short d_1c01ed;
extern short d_1c01f1;
extern short d_1c01f5;
extern short d_1c01f9;
extern short d_1c01fd;
extern short d_1c0201;
extern short d_1c0205;
extern short d_1c0209;
extern short d_1c020d;
extern short d_1c0211;
extern short d_1c0215;
extern short d_1c212a;
extern int d_1c0004;
extern int d_1a9820;
extern int d_1c2c64;
extern int d_1bf230;
extern int d_1c2c44;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c3498;
extern int d_1bb680;
extern int d_1bb6d8;
extern int d_1bfdbc;
extern int *d_1c212c;
short f_060760(int p1);
void f_060740(int p1, int p2);
void f_0607e0(int p1, int p2);
int f_0de7c0(int p1);
short f_0de820(int p1);
void f_041920(int p1);
void f_1223c0(void);
void f_0bbf00(int p1);
void f_0bf730(int p1, int p2);
void f_0de210(int p1);
void f_060240(void);
void f_0d5ff0(int p1);
int f_060030(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
int f_05ff60(int p1, int p2);
int f_0bf6f0(int p1, int p2);
void f_0de810(int p1, int p2);
void f_0dd7f0(int p1, int p2, int p3);
int f_0ed760(void);
int f_039780(int p1, int p2);
int f_039320(int p1, int p2);
short f_0db9a0(int p1);
void f_125f70(int p1, int p2);
void f_125ed0(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
int f_0d4a60(int p1);
int f_044900(int p1, int p2, int p3);

short f_1457e0(int p1);
void f_044300(int p1, int p2);

int f_039040(int p1);
int f_039b00(int p1, int p2, int p3);
unsigned short f_0d54f0(int p1, int p2);
void f_0dd1d0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
void f_0f5d20(void);
void f_0f5fb0(void);
void f_0f60b0(void);
int f_0f61a0(void);
void f_0f62e0(void);
void f_0f6400(void);
int f_0f6550(int p1, int p2);
#pragma aux f_147323 modify [esp];
extern int d_1c2edc;
void f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#define K147(m) f_147323(PD(d_1c2edc), m, 0x7fff, 0x8000, d_1a9820, 0, 1)
#define EQ(x,v) (((x)==(v))?1:0)
#define PD(x) ((int)&(x))
typedef RivaTextContextData OB;
#define CTOR(o) f_125400(PD(o), PD(d_1c349c), PD(d_1c3870), PD(d_1c3498))
#define DTOR(o) f_1254a0(PD(o), 0)
#define MSGPAIR K147(0x25001e); K147(0x25001f)

//@ f_0f5250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die lokalen Zustandsflags, Gittertor-Stellungen und Truheninhalte des ersten
 *   Kanalisationsabschnitts beim Start eines neuen Spiels auf ihre Ausgangswerte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den zuletzt gesetzten Initialisierungswert zurück.
 === Ende Beschreibung === */
void f_0f5250(void)
;
//@ f_0f52a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird beim Betreten des Kanalisationsabschnitts aufgerufen, lädt die
 *   gebietsspezifischen Texte und Grafiken, richtet die Wasser- und Lichtparameter der 3D-Umgebung ein und
 *   platziert bewegliche Gegner- oder Ereignisobjekte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Gebietsinitialisierung zurück.
 === Ende Beschreibung === */
void f_0f52a0(void)
;
//@ f_0f5330
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion räumt beim Verlassen des Kanalisationsabschnitts die lokal angeforderten Text-, Sound-
 *   und Grafikressourcen wieder auf.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Aufräumroutine zurück.
 === Ende Beschreibung === */
void f_0f5330(void)
;
//@ f_0f5450
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest oder schreibt den lokalen Fortschritts- und Schalterzustand des ersten
 *   Kanalisationsabschnitts beim Laden beziehungsweise Speichern eines Spielstands.
 * - Eingaben: Die Funktion erhält den Spielstands-Datenstrom (p1) sowie das Richtungsflag (p2, 0 zum Laden, 1
 *   zum Speichern).
 * - Rückgabewert: Die Funktion gibt 0 bei Erfolg oder einen Fehlercode ungleich null bei einem Dateifehler
 *   zurück.
 === Ende Beschreibung === */
int f_0f5450(int p1, unsigned p2)
;
//@ f_0f5490
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der zentrale Ereignisverteiler des Kanalisationsabschnitts und ruft abhängig von
 *   der übergebenen Auslöser-Kennung (p1) die jeweilige Raum-, Kampf-, Gitter- oder Untersuchungsroutine auf.
 * - Eingaben: Die Funktion erhält die Nummer des ausgelösten Dungeon-Ereignisses (p1).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert des ausgeführten Ereignishandlers zurück.
 === Ende Beschreibung === */
struct R5490 { signed char v; short id; };
inline void put5490(R5490 *p, short id, short v, short &n, int * &tab)
{ p->id = id; p->v = v; tab[n] = (int)p; n++; }
struct RR700V3_0f54908;
struct OR700V3_0f54908 { signed char flag; short number; char pad; OR700V3_0f54908 *init(RR700V3_0f54908 &r,short id,signed char f); };
struct RR700V3_0f54908 { short count; OR700V3_0f54908 **list; void append(OR700V3_0f54908 *o) {list[count]=o;count++;} };
inline OR700V3_0f54908 *OR700V3_0f54908::init(RR700V3_0f54908 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0f54908 regR700V3_0f54908;
#pragma aux regR700V3_0f54908 "d_1c212a"
extern OR700V3_0f54908 obR700V3_0f5490_1c01d8;
#pragma aux obR700V3_0f5490_1c01d8 "d_1c01d8"
extern OR700V3_0f54908 obR700V3_0f5490_1c01dc;
#pragma aux obR700V3_0f5490_1c01dc "d_1c01dc"
extern OR700V3_0f54908 obR700V3_0f5490_1c01e0;
#pragma aux obR700V3_0f5490_1c01e0 "d_1c01e0"
extern OR700V3_0f54908 obR700V3_0f5490_1c01e4;
#pragma aux obR700V3_0f5490_1c01e4 "d_1c01e4"
extern OR700V3_0f54908 obR700V3_0f5490_1c01e8;
#pragma aux obR700V3_0f5490_1c01e8 "d_1c01e8"
extern OR700V3_0f54908 obR700V3_0f5490_1c01ec;
#pragma aux obR700V3_0f5490_1c01ec "d_1c01ec"
extern OR700V3_0f54908 obR700V3_0f5490_1c01f0;
#pragma aux obR700V3_0f5490_1c01f0 "d_1c01f0"
extern OR700V3_0f54908 obR700V3_0f5490_1c01f4;
#pragma aux obR700V3_0f5490_1c01f4 "d_1c01f4"
extern OR700V3_0f54908 obR700V3_0f5490_1c01f8;
#pragma aux obR700V3_0f5490_1c01f8 "d_1c01f8"
extern OR700V3_0f54908 obR700V3_0f5490_1c01fc;
#pragma aux obR700V3_0f5490_1c01fc "d_1c01fc"
extern OR700V3_0f54908 obR700V3_0f5490_1c0200;
#pragma aux obR700V3_0f5490_1c0200 "d_1c0200"
extern OR700V3_0f54908 obR700V3_0f5490_1c0204;
#pragma aux obR700V3_0f5490_1c0204 "d_1c0204"
extern OR700V3_0f54908 obR700V3_0f5490_1c0208;
#pragma aux obR700V3_0f5490_1c0208 "d_1c0208"
extern OR700V3_0f54908 obR700V3_0f5490_1c020c;
#pragma aux obR700V3_0f5490_1c020c "d_1c020c"
extern OR700V3_0f54908 obR700V3_0f5490_1c0210;
#pragma aux obR700V3_0f5490_1c0210 "d_1c0210"
extern OR700V3_0f54908 obR700V3_0f5490_1c0214;
#pragma aux obR700V3_0f5490_1c0214 "d_1c0214"
void f_0f5490(void) {
obR700V3_0f5490_1c01d8.init(regR700V3_0f54908,0x5a,0);
obR700V3_0f5490_1c01dc.init(regR700V3_0f54908,0x5b,0);
obR700V3_0f5490_1c01e0.init(regR700V3_0f54908,0x5d,0);
obR700V3_0f5490_1c01e4.init(regR700V3_0f54908,0x5e,0);
obR700V3_0f5490_1c01e8.init(regR700V3_0f54908,0x62,0);
obR700V3_0f5490_1c01ec.init(regR700V3_0f54908,0x64,0);
obR700V3_0f5490_1c01f0.init(regR700V3_0f54908,0x65,0);
obR700V3_0f5490_1c01f4.init(regR700V3_0f54908,0x68,0);
obR700V3_0f5490_1c01f8.init(regR700V3_0f54908,0x69,0);
obR700V3_0f5490_1c01fc.init(regR700V3_0f54908,0x6a,0);
obR700V3_0f5490_1c0200.init(regR700V3_0f54908,0x6b,0);
obR700V3_0f5490_1c0204.init(regR700V3_0f54908,0x6c,0);
obR700V3_0f5490_1c0208.init(regR700V3_0f54908,0x6d,0);
obR700V3_0f5490_1c020c.init(regR700V3_0f54908,0x6e,0);
obR700V3_0f5490_1c0210.init(regR700V3_0f54908,0x16d,0);
obR700V3_0f5490_1c0214.init(regR700V3_0f54908,0x257,0);
}

//@ f_0f5770
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine beschreibende Textmeldung beim Betreten eines bestimmten Kanalisationsgangs
 *   aus und markiert den Hinweis als gelesen.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5770(int p1)
{
  int r;
  r = f_05ff60(p1, 2);
  *(int *)(r + 8) = PD(d_1bb6d8);
}
//@ f_0f5790
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das Untersuchen einer verschlossenen Vorrichtung oder eines Gitters in der
 *   Kanalisation, prüft passende Schlüssel oder Kraft-/Schlösserknacken-Proben der Helden und öffnet bei Erfolg
 *   den Durchgang.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach Abschluss der Interaktion zurück.
 === Ende Beschreibung === */
void f_0f5d20(int p1);
void f_0f5fb0(int p1);
void f_0f60b0(int p1);
int f_0f61a0(int p1);
void f_0f62e0(int p1);
void f_0f6400(int p1);
int f_0f5790(int p1, int p2)
{
  int r;
  r = 1;
  switch ((unsigned short)p2) {
  case 0xa:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 6);
    break;
  case 0x14:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 0x16);
    break;
  case 0x1e:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 0x1a);
    break;
  case 0x28:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 0x19);
    break;
  case 0x32:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 0x17);
    break;
  case 0x3c:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) f_0de810(d_1c0004, 0x18);
    break;
  case 0x46:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004f) == 1) f_0dd7f0(d_1c0004, 1, 0x16af);
    break;
  case 0x50:
    f_0de810(d_1c0004, 0x11);
    break;
  case 0x5a:
    f_0de810(d_1c0004, 0x66);
    break;
  case 0x64:
    if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
      if (EQ(d_1c01f8, 0)) {
        f_0bf730(PD(d_1c2c64), 0x2500008e);
        d_1c01f8 = 1;
      }
      if (f_0ed760() == 1) f_0dd7f0(d_1c0004, 5, 0x14b4);
    }
    break;
  case 0x6e:
    f_0de810(d_1c0004, 0x21);
    break;
  case 0x79:
    f_0f6550(p1, 0x1853);
    break;
  case 0x78:
    f_0f6550(p1, 0x17dd);
    break;
  case 0x1f41:
    f_0f5d20(p1);
    break;
  case 0x8c:
    f_0f5fb0(p1);
    break;
  case 0x96:
    f_0f60b0(p1);
    break;
  case 0xa0:
    f_0f61a0(p1);
    break;
  case 0x1f42:
    f_0f62e0(p1);
    break;
  case 0xbe:
    f_0f6400(p1);
    break;
  case 0x1f43:
    break;
  default:
    r = 0;
    break;
  }
  return r;
}
//@ f_0f5af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine kurze Ortsbeschreibung an einem markanten Punkt des Abwasserkanals aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Textfensters zurück.
 === Ende Beschreibung === */
void f_0f5af0(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 6);
  }
}
//@ f_0f5b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt eine weitere einmalige Beobachtungsmeldung der Heldengruppe im Kanalnetz an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Textanzeige zurück.
 === Ende Beschreibung === */
void f_0f5b20(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 0x16);
  }
}
//@ f_0f5b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion meldet eine Entdeckung oder Warnung an einer Abzweigung der Kanalisation.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5b50(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 0x1a);
  }
}
//@ f_0f5b80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt einen Hinweis- oder Atmosphäretext für einen angrenzenden Kanalraum aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Textaufrufs zurück.
 === Ende Beschreibung === */
void f_0f5b80(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 0x19);
  }
}
//@ f_0f5bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt eine Textmeldung über Spuren oder Geräusche in der Kanalisation an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Textanzeige zurück.
 === Ende Beschreibung === */
void f_0f5bb0(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 0x17);
  }
}
//@ f_0f5be0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt beim erstmaligen Betreten einer Kammer eine Beschreibung der Umgebung aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5be0(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    f_0de810(d_1c0004, 0x18);
  }
}
//@ f_0f5c10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet einen weiteren ortsgebundenen Hinweistext in der Kanalisation ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert des Textfensters zurück.
 === Ende Beschreibung === */
void f_0f5c10(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004f) == 1) {
    f_0dd7f0(d_1c0004, 1, 0x16af);
  }
}
//@ f_0f5c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst an einer bestimmten Stelle des Kanals einen Kampf oder ein Ereignis aus und setzt
 *   das zugehörige Erledigt-Flag.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status des ausgelösten Ereignisses zurück.
 === Ende Beschreibung === */
void f_0f5c40(void)
{
  f_0de810(d_1c0004, 0x11);
}
//@ f_0f5c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet eine weitere festgelegte Gegnerbegegnung im Kanalisationsabschnitt, sofern
 *   diese noch nicht besiegt wurde.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Kampfstarts zurück.
 === Ende Beschreibung === */
void f_0f5c60(void)
{
  f_0de810(d_1c0004, 0x66);
}
//@ f_0f5c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft und verarbeitet das Durchsuchen eines Verstecks oder Überrests im Kanal und
 *   übergibt gefundene Gegenstände an die Heldengruppe.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Beuteübergabe zurück.
 === Ende Beschreibung === */
void f_0f5c80(void)
{
  if (f_0bf6f0(PD(d_1c2c64), 0x2500004e) == 1) {
    if (EQ(d_1c01f8, 0)) {
      f_0bf730(PD(d_1c2c64), 0x2500008e);
      d_1c01f8 = 1;
    }
    if (f_0ed760() == 1) {
      f_0dd7f0(d_1c0004, 5, 0x14b4);
    }
  }
}
//@ f_0f5ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst eine weitere Kampfbegegnung an einem Knotenpunkt des Kanalsystems aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Kampfinitialisierung zurück.
 === Ende Beschreibung === */
void f_0f5ce0(void)
{
  f_0de810(d_1c0004, 0x21);
}
//@ f_0f5d00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter-Handler für ein nicht belegtes Kanalisationsereignis.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f5d00(int p1)
{
  f_0f6550(p1, 0x1853);
}
//@ f_0f5d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient ebenfalls als leerer Platzhalter-Callback innerhalb der Ereignistabelle dieses
 *   Gebiets.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f5d10(int p1)
{
  f_0f6550(p1, 0x17dd);
}
//@ f_0f5d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine umfangreichere interaktive Szene an einem Wasserdurchlass oder
 *   Mechanismus, lässt einen ausgewählten Helden eine Probe ablegen und verändert je nach Ausgang den
 *   Wasserstand, den Durchgangsstatus oder die Lebenspunkte des Helden.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach Abschluss der Aktion zurück.
 === Ende Beschreibung === */
void f_0f5d20(void)
{
  void f_147323_frame(int, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  OB ob;
  int i;
  short n;
  int p;
  int q;
  short r;
  if (EQ(d_1c0200, 0) && f_0bf6f0(PD(d_1c2c64), 0x2500009d) == 1) {
      CTOR(ob);
      p = f_039780(d_1c0004, 6);
      q = f_039320(d_1c0004, 0x30);
      if (p != 0) *(int *)(ob.addresses.objects + 4) = p;
      else *(int *)(ob.addresses.objects + 4) = q;
      if (f_0db9a0(d_1c0004) > 1)
        f_0bf730(PD(d_1c2c64), 0x2500009e);
      else
        f_0bf730(PD(d_1c2c64), 0x2500009f);
      f_125f70(PD(d_1c2c44), 8);
      if (p == 0) {
        if (f_044c90(q, 0x30, 0xc) <= 0) {
          i = 0;
          f_0bf730(PD(d_1c2c64), 0x250000a0);
          { int snd = d_1a9820; f_147323_frame(PD(d_1c2edc), 0x250022, 0x7fff, 0x8000, snd, 0, 1); }
          for (n = 0; n < 7 && i == 0; n++) {
            p = f_0de7d0(d_1c0004, n);
            if (p != 0) {
              if (f_0d4a60(p) != 0) {
                r = f_044900(p, 4, 8);
                *(int *)(ob.addresses.objects + 8) = p;
                if ((signed char)((unsigned short)(f_042400((struct hero *)(p)))) > 0) r = 1;
                if (r > 0) {
                  f_0bf730(PD(d_1c2c64), 0x250000a1);
                } else {
                  r = f_1457e0(8) + 8;
                  f_044300(p, r);
                  if (f_042960((struct hero *)(p)) > 0) {
                    f_0bf730(PD(d_1c2c64), 0x250000a2);
                  } else {
                    f_0bf730(PD(d_1c2c64), 0x250000a3);
                    if (f_0db9a0(d_1c0004) > 1)
                      f_0bf730(PD(d_1c2c64), 0x250000a4);
                    else
                      f_0bf730(PD(d_1c2c64), 0x250000a5);
                    i = 1;
                  }
                }
              }
            }
          }
          f_125ed0(PD(d_1c2c44), 10);
          if ((unsigned)(d_1c0004 + (int)&f_0db9a0) <= 0u) goto done_0f5d20;
          if (f_0bf6f0(PD(d_1c2c64), 0x250000a6) != 1) goto done_0f5d20;
          f_0bf730(PD(d_1c2c64), 0x250000a7);
          f_125f70(PD(d_1c2c44), 5);
        }
      }
      f_060740(0x1f41, 1);
      f_0607e0(0x1f41, 1);
      d_1c0200 = 1;
done_0f5d20:
      DTOR(ob);
  }
}
//@ f_0f5fb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt das Durchsuchen einer Nische oder eines Behälters im Kanal ab, wobei der
 *   aktive Held gegebenenfalls eine Probe besteht oder sich an einer Falle verletzt.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Untersuchung zurück.
 === Ende Beschreibung === */

void f_0f5fb0(void)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  int p1 = f_039320(d_1c0004, 0x33);
  if (f_060760(0x1f44) == 1 && f_044c90(p1, 0x33, 0xf) > 0) {
    RivaTextContext ob((void*)PD(d_1c349c), (void*)PD(d_1c3870), (void*)PD(d_1c3498));
    ob.tables.p[1] = p1;
    f_0bf730(PD(d_1c2c64), 0x250000a8);
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001f, 0x7fff, 0x8000, snd, 0, 1); }
    f_060740(0x1f44, 1);
    f_0607e0(0x1f44, 1);
    d_1c0204 = 1;
  }
}
//@ f_0f60b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt die Betätigung eines Hebels oder Schalters im Kanalnetz und schaltet das
 *   zugehörige Schleusen- oder Gittertor im 3D-Level um.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach dem Umschalten zurück.
 === Ende Beschreibung === */
void f_0f60b0(void)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  int p1 = f_039320(d_1c0004, 0x33);
  if (f_060760(0x1f45) == 1 && f_044c90(p1, 0x33, 10) > 0) {
    RivaTextContext ob((void*)PD(d_1c349c), (void*)PD(d_1c3870), (void*)PD(d_1c3498));
    ob.tables.p[1] = p1;
    f_0bf730(PD(d_1c2c64), 0x250000a9);
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001f, 0x7fff, 0x8000, snd, 0, 1); }
    f_060740(0x1f45, 1);
    f_0607e0(0x1f45, 1);
  }
}
//@ f_0f61a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet einen Ausstieg oder Übergangspunkt aus der Kanalisation zurück in das
 *   Stadtgebiet von Riva (beziehungsweise in eine angrenzende Ebene) nach einer Bestätigungsabfrage.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Ortswechsels zurück.
 === Ende Beschreibung === */
int f_0f61a0(void)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  OB ob;
  CTOR(ob);
  if ((short)f_0d54f0(d_1c0004, 0x162) != -1) {
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x30);
    f_0bf730(PD(d_1c2c64), 0x250000aa);
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
    { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001f, 0x7fff, 0x8000, snd, 0, 1); }
    f_060740(0x1f46, 1);
    f_0607e0(0x1f46, 1);
    f_0607e0(0x1f47, 1);
    f_0dd1d0(d_1c0004, 0x162);
    return DTOR(ob);
  } else {
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x33);
    f_0bf730(PD(d_1c2c64), 0x250000ab);
    return DTOR(ob);
  }
}

//@ f_0f62d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter für ein deaktiviertes Ereignis im Kanalisationsskript.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f62d0(void)
{
}

//@ f_0f62e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Rasten oder Verweilen im Kanalisationsgebiet, ob die Gruppe von streunenden
 *   Kreaturen überrascht wird, und leitet gegebenenfalls einen Zufallskampf ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Rastprüfung zurück.
 === Ende Beschreibung === */
void f_0f62e0(void)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  if (f_039040(d_1c0004) != 0) {
    if ((signed char)((unsigned short)(f_042400((struct hero *)(f_039040(d_1c0004))))) == 6 && EQ(*(signed char *)&d_1c0208, 0)) {
      RivaTextContext ob((void*)PD(d_1c349c), (void*)PD(d_1c3870), (void*)PD(d_1c3498));
      ob.tables.p[1] = f_039b00(d_1c0004, f_039040(d_1c0004), 0x33);
      f_0bf730(PD(d_1c2c64), 0x250000ac);
      { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
      { int snd = d_1a9820; f_147323(PD(d_1c2edc), 0x25001f, 0x7fff, 0x8000, snd, 0, 1); }
      *(signed char *)&d_1c0208 = 1;
      f_060740(0x1f42, 1);
      f_0607e0(0x1f42, 1);
    }
  }
}
