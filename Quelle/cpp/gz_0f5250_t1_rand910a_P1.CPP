/* === Beschreibung (Katalog) ===
 * Einheit gz_0f5250_t1_rand910a
 *
 * Diese Einheit bildet die erste Hälfte des ersten Teils der Kanalisations- und Unterwelt-Ereignissteuerung
 * (gz_0f5250, Teil 1a, zugehörig zur Kanalisation von Riva vor sewerag3) und initialisiert die lokalen
 * Begegnungen, Fallen, Gittertore und Fundstellen im ersten Kanalisationsabschnitt.
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
{
  if (EQ(d_1c01c0, -1)) {
    d_1c01c0 = 0;
    if (f_060760(0x1f46) == 2) {
      f_060740(0x1f46, 1);
      f_0607e0(0x1f46, 0);
    }
  }
}
//@ f_0f52a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird beim Betreten des Kanalisationsabschnitts aufgerufen, lädt die
 *   gebietsspezifischen Texte und Grafiken, richtet die Wasser- und Lichtparameter der 3D-Umgebung ein und
 *   platziert bewegliche Gegner- oder Ereignisobjekte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Gebietsinitialisierung zurück.
 === Ende Beschreibung === */
void f_0f52a0(void)
{
  int p1;
  short k;
  int p;
  p1 = d_1c0004;
  for (k = 0; k < 6; k++) {
    p = (int)&d_1bfdbc + k * 0x61;
    if (f_0de7c0(p) != 0 && p != d_1c0004) {
      if (f_0de820(p) == 1) {
        f_041920(p);
        f_1223c0();
        f_0bbf00(PD(d_1bf230));
        f_0bf730(PD(d_1c2c64), 0x25000016);
        f_0de210(p);
      }
    }
  }
  if (p1 != d_1c0004) {
    f_041920(p1);
  }
}
//@ f_0f5330
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion räumt beim Verlassen des Kanalisationsabschnitts die lokal angeforderten Text-, Sound-
 *   und Grafikressourcen wieder auf.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Aufräumroutine zurück.
 === Ende Beschreibung === */
void f_0f5330(void)
{
  f_060240();
  if (EQ(d_1c01b0, 0) && EQ(d_1c0178, 1) && EQ(d_1c00c4, 1)) {
    f_060740(0x1f48, 0);
    f_0607e0(0x1f48, 1);
    d_1c01b0 = 1;
  }
  if (EQ(d_1bee0c, 1)) {
    if (f_060760(0x1f42) == 1) {
      f_060740(0x1f42, 0);
      f_0607e0(0x1f42, 1);
    }
  }
  if (EQ(d_1c00bc, 1)) {
    if (f_060760(0x1f45) == 1) {
      f_060740(0x1f45, 0);
      f_0607e0(0x1f45, 1);
    }
  }
  if (EQ(d_1c01cc, 2)) {
    f_0bf730(PD(d_1c2c64), 0x250000fe);
    f_0d5ff0(4);
    d_1c01cc = 0;
  }
}
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
{
  int r;
  if (p2 & 4) {
    f_145234(p1, PD(d_1bb680));
    f_145254();
    return p1;
  }
  r = f_060030(p1, 1);
  if (p2 & 2) {
    operator delete((void *)r);
  }
  return r;
}
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
void f_0f5490(void) ;

//@ f_0f5770
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine beschreibende Textmeldung beim Betreten eines bestimmten Kanalisationsgangs
 *   aus und markiert den Hinweis als gelesen.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5770(int p1)
;
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
;
//@ f_0f5af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine kurze Ortsbeschreibung an einem markanten Punkt des Abwasserkanals aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Textfensters zurück.
 === Ende Beschreibung === */
void f_0f5af0(void)
;
//@ f_0f5b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt eine weitere einmalige Beobachtungsmeldung der Heldengruppe im Kanalnetz an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Textanzeige zurück.
 === Ende Beschreibung === */
void f_0f5b20(void)
;
//@ f_0f5b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion meldet eine Entdeckung oder Warnung an einer Abzweigung der Kanalisation.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5b50(void)
;
//@ f_0f5b80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt einen Hinweis- oder Atmosphäretext für einen angrenzenden Kanalraum aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Textaufrufs zurück.
 === Ende Beschreibung === */
void f_0f5b80(void)
;
//@ f_0f5bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt eine Textmeldung über Spuren oder Geräusche in der Kanalisation an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Textanzeige zurück.
 === Ende Beschreibung === */
void f_0f5bb0(void)
;
//@ f_0f5be0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt beim erstmaligen Betreten einer Kammer eine Beschreibung der Umgebung aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textausgabe zurück.
 === Ende Beschreibung === */
void f_0f5be0(void)
;
//@ f_0f5c10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet einen weiteren ortsgebundenen Hinweistext in der Kanalisation ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert des Textfensters zurück.
 === Ende Beschreibung === */
void f_0f5c10(void)
;
//@ f_0f5c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst an einer bestimmten Stelle des Kanals einen Kampf oder ein Ereignis aus und setzt
 *   das zugehörige Erledigt-Flag.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status des ausgelösten Ereignisses zurück.
 === Ende Beschreibung === */
void f_0f5c40(void)
;
//@ f_0f5c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet eine weitere festgelegte Gegnerbegegnung im Kanalisationsabschnitt, sofern
 *   diese noch nicht besiegt wurde.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Kampfstarts zurück.
 === Ende Beschreibung === */
void f_0f5c60(void)
;
//@ f_0f5c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft und verarbeitet das Durchsuchen eines Verstecks oder Überrests im Kanal und
 *   übergibt gefundene Gegenstände an die Heldengruppe.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Beuteübergabe zurück.
 === Ende Beschreibung === */
void f_0f5c80(void)
;
//@ f_0f5ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst eine weitere Kampfbegegnung an einem Knotenpunkt des Kanalsystems aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Kampfinitialisierung zurück.
 === Ende Beschreibung === */
void f_0f5ce0(void)
;
//@ f_0f5d00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter-Handler für ein nicht belegtes Kanalisationsereignis.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f5d00(int p1)
;
//@ f_0f5d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient ebenfalls als leerer Platzhalter-Callback innerhalb der Ereignistabelle dieses
 *   Gebiets.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f5d10(int p1)
;
//@ f_0f5d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine umfangreichere interaktive Szene an einem Wasserdurchlass oder
 *   Mechanismus, lässt einen ausgewählten Helden eine Probe ablegen und verändert je nach Ausgang den
 *   Wasserstand, den Durchgangsstatus oder die Lebenspunkte des Helden.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach Abschluss der Aktion zurück.
 === Ende Beschreibung === */
void f_0f5d20(void)
;
//@ f_0f5fb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt das Durchsuchen einer Nische oder eines Behälters im Kanal ab, wobei der
 *   aktive Held gegebenenfalls eine Probe besteht oder sich an einer Falle verletzt.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Untersuchung zurück.
 === Ende Beschreibung === */
struct MsgC { int h; OB *q[14];
  MsgC(int a, int b, int c);
  ~MsgC();
};
void f_0f5fb0(void)
;
//@ f_0f60b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt die Betätigung eines Hebels oder Schalters im Kanalnetz und schaltet das
 *   zugehörige Schleusen- oder Gittertor im 3D-Level um.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach dem Umschalten zurück.
 === Ende Beschreibung === */
void f_0f60b0(void)
;
//@ f_0f61a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet einen Ausstieg oder Übergangspunkt aus der Kanalisation zurück in das
 *   Stadtgebiet von Riva (beziehungsweise in eine angrenzende Ebene) nach einer Bestätigungsabfrage.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Ortswechsels zurück.
 === Ende Beschreibung === */
int f_0f61a0(void)
;

//@ f_0f62d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter für ein deaktiviertes Ereignis im Kanalisationsskript.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
void f_0f62d0(void)
;

//@ f_0f62e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Rasten oder Verweilen im Kanalisationsgebiet, ob die Gruppe von streunenden
 *   Kreaturen überrascht wird, und leitet gegebenenfalls einen Zufallskampf ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status der Rastprüfung zurück.
 === Ende Beschreibung === */
void f_0f62e0(void)
;
