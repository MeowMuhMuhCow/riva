/* === Beschreibung (Katalog) ===
 * Einheit carrier (0x00026ff0 - 0x00028190)
 *
 * Überblick
 *
 * Die Einheit carrier implementiert die untere Heldenporträt- und Aktionsleiste (CARRIER.CPP) der
 * Benutzeroberfläche. Sie verwaltet die sieben Gruppenplätze am unteren Bildschirmrand, ermöglicht das Umordnen
 * der Helden per Drag-and-Drop, das Ablegen von Gegenständen direkt auf einem Heldenporträt, das Umschalten der
 * Anzeige-Modi sowie das Öffnen des Charakterbogens per Klick auf ein Porträt.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 21/25 gleich (suche.py 30.10.2026, Basis carrier_P1.CPP)
// carrier.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x026FF0-0x028190
#include <string.h>
#include <stdio.h>
void *f_014710(void *p);
struct Img { char d[9]; };
struct Sub { char d[0x3a]; };
struct Clip { short a, b, c, d; };
struct Reg { char b[32]; void f_04fef0(int id, int s, int z, int n, int z2, int w); };
struct Txt { char b[4]; short f_0e9690(char *s); void f_05e320(int p, int q); void f_05e340();
             void f_0e9300(char *s, int v); void f_0e9660(char *s, int x, int y); void f_0e9510(int v, int x, int y); };
Img *f_0fac80(Img *p, int w, int h);
Img *f_0fac10(Img *p, int w, int h, int z);








Sub *f_025ac0(Sub *p, int o, int a, int b);
void *f_025be0(Sub *p, int z);
int f_025cd0(Sub *p);
int f_025d90(Sub *p, int a, int b);

int f_044ea0(int o);

signed char f_043a80(int o, int v);

short f_045300(int o);
int f_045960(int o, int v);
int f_099ea0();
int f_0d26e0();
int f_0d2710();
int f_0d2f40(int a, int b);
int f_0d32f0();
int f_0d3790();
int f_0d3860();
int f_0d38b0(Clip *c);
int f_0d38d0(Clip *c);
extern short d_1a0660[], d_1a0662[], d_1a0680[], d_1a0682[], d_1a48f4[], d_1a48f6[];
extern short d_1a067e, d_1a06a2, d_1a06a4, d_1a06a6;
extern short d_1a06a0;
extern short d_1a069e;
extern short d_1a067c;
extern short d_1bc814, d_1bc816, d_1bc818, d_1bc81a, d_1bf4f0, d_1bf4f2, d_1bf4fc;
extern int d_1a34e0;
extern int d_1bf4e8;
extern volatile char d_1bf4ed;
extern char d_1c27a8[];
extern Reg d_1c2be0;
extern Txt d_1c38b0;
extern const char d_1a0640[];
extern const char d_1b6480[], d_1b6484[], d_1b6487[];
struct Lk { int f; Lk() { if (f_0d3860() == 1) { int k = 1; f_0d2710(); f = k; } else f = 0; } ~Lk() { if (f == 1) f_0d26e0(); } };
struct Car {
  int o; Sub *s; short idx; int fl; int a; int b;
  Car *f_026ff0(int p2, short p3, int p4, int p5);
  Car *f_027050(int p2); int f_027070(); Sub *f_027080(); int f_027090();
  void f_0270a0(int v); void f_0270b0(Sub *v); void f_0270c0(int v);
  void f_0270d0(); void f_027240(); void f_027280(short p2); void f_0272d0(); void f_027420(); void f_027690();
  int f_027750(); void f_027830(short p2); void f_027860(); void f_0279f0(); void f_027b30(); void f_027c50();
  void f_027d90(char *s); void f_027dc0(Img *im); int f_027e20(); void f_027eb0(Img *im, unsigned short k); short f_027f80();
};
//@ f_026ff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert ein einzelnes Slot-Steuerelement der unteren Heldenleiste mit seinen
 *   Bildschirmkoordinaten und seiner Gruppenplatznummer.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, die Slot-Nummer sowie die
 *   Rechteckkoordinaten und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Speichert den Gruppenplatz-Index und bindet das Steuerelement in die GUI-Basisklasse
 *   ein.
 === Ende Beschreibung === */
Car *Car::f_026ff0(int p2, short p3, int p4, int p5) {
  fl = 0; o = p2; idx = p3; a = p4; b = p5;
  if (o) {
    Sub *p = new (mark(d_1a0640, 0x62)) Sub;
    s = p ? f_025ac0(p, o, a, b) : p;
  } else s = 0;
  return this;
}
//@ f_027050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut ein einzelnes Slot-Steuerelement der Porträtleiste wieder ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und die Destruktor-Flags entgegen und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Ruft den Basisklassen-Destruktor des UI-Elements auf.
 === Ende Beschreibung === */
Car *Car::f_027050(int p2) {
  if (s) {
    Sub *p = s;
    if (p) f_014710(f_025be0(p, 0));
  }
  return this;
}
//@ f_027070
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere virtuelle Standardmethode des Porträtslots, die ohne Aktion zurückkehrt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int Car::f_027070()
{
    return o;
}
//@ f_027080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zweite leere virtuelle Standardmethode des Porträtslots.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
Sub *Car::f_027080()
{
    return s;
}
//@ f_027090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dritte leere virtuelle Methode des Porträtslots.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int Car::f_027090()
{
    return fl;
}
//@ f_0270a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vierte leere virtuelle Methode des Porträtslots.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void Car::f_0270a0(int v)
{
    o = v;
}
//@ f_0270b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fünfte leere virtuelle Methode des Porträtslots.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void Car::f_0270b0(Sub *v)
{
    s = v;
}
//@ f_0270c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sechste leere virtuelle Methode des Porträtslots.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void Car::f_0270c0(int v)
{
    fl = v;
}
//@ f_0270d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt die komplette untere Heldenleiste mit allen sieben Porträtplätzen (0 bis 6), lädt die
 *   Rahmengrafik und registriert die Klick- und Ziehbereiche für die Gruppenmitglieder.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie die Konfigurationsparameter der Leiste
 *   entgegen und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Legt die sieben Slot-Objekte anhand der Koordinatentabelle d_1a48f4 an und speichert den
 *   aktuellen Zustand der Porträtleiste.
 === Ende Beschreibung === */
void Car::f_0270d0() {
  Img t;
  f_0fac10(&t, 0x20, 0x20, 0);
  if (o == 0) {
    char *bf = new (mark(d_1a0640, 0xf7)) char[0x400];
    d_1c2be0.f_04fef0(a, (int)bf, 0, 6, 0, 0x140);
    ((RivaRasterImage*)(&t))->f_0fb060((void *)( (int)bf));
    f_027dc0(&t);
    delete bf;
  } else {
    ((RivaRasterImage*)(&t))->f_0fb060((void *)( f_044ea0(o)));
    f_027dc0(&t);
  }
  ((void *)(((RivaRasterImage*)(&t))->f_0fad20( 0)));
  f_027860();
  f_027420();
  f_027690();
  if (idx == 0) {
    f_0279f0();
    f_027b30();
    f_027c50();
    f_025cd0(s);
  }
}
//@ f_027240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Abbau der Benutzeroberfläche die sieben Porträtslots sowie die zugehörigen
 *   Grafikpuffer der Heldenleiste wieder frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und die Destruktor-Flags und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Räumt die in f_0270d0 angelegten Slot-Steuerelemente und Grafikressourcen ab.
 === Ende Beschreibung === */
void Car::f_027240() {
  f_027420();
  f_027690();
  if (idx == 0) {
    f_0279f0();
    f_027b30();
    f_027c50();
    f_025cd0(s);
  }
}
//@ f_027280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet den Anzeige- oder Interaktionsmodus der unteren Porträtleiste um und veranlasst bei
 *   Bedarf das Neuzeichnen aller Heldenköpfe.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie den neuen Moduswert entgegen und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert das Modusfeld der Porträtleiste und ruft f_0259e0 zur Bildschirmdarstellung
 *   auf.
 === Ende Beschreibung === */
void Car::f_027280(short p2) {
  f_027420();
  f_027690();
  if (idx == 0) {
    f_0279f0();
    f_027b30();
    f_027c50();
    f_025d90(s, p2, d_1a34e0);
  }
}
//@ f_0272d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Reagiert auf das Anklicken eines der sieben Heldenporträts: Hält der Spieler einen Gegenstand
 *   am Mauszeiger, wird dieser in den Rucksack des angeklickten Helden gelegt; andernfalls öffnet ein Klick den
 *   Charakterbogen oder wählt den Helden als aktiven Sprecher beziehungsweise Zaubernden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den angeklickten Gruppenplatz-Index sowie
 *   die Maustasten-Flags und gibt einen Ergebnisstatus zurück.
 * - Wichtige Variablen: Ermittelt über f_0415c0 den Helden auf dem gewählten Gruppenplatz und prüft, ob aktuell
 *   ein Gegenstand gezogen wird oder eine Heldenauswahl aktiv ist.
 === Ende Beschreibung === */
void Car::f_0272d0() {
  Img t;
  f_0fac10(&t, 0x20, 0x20, 0);
  if (o == 0) {
    char *bf = new (mark(d_1a0640, 0xf7)) char[0x400];
    d_1c2be0.f_04fef0(a, (int)bf, 0, 6, 0, 0x140);
    ((RivaRasterImage*)(&t))->f_0fb060((void *)( (int)bf));
    f_027dc0(&t);
    delete bf;
  } else {
    ((RivaRasterImage*)(&t))->f_0fb060((void *)( f_044ea0(o)));
    f_027dc0(&t);
  }
  ((void *)(((RivaRasterImage*)(&t))->f_0fad20( 0)));
}
//@ f_027420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt dem Spieler, ein Heldenporträt in der unteren Leiste mit gedrückter Maustaste
 *   horizontal auf einen anderen der sieben Gruppenplätze zu ziehen, um die Marsch- und Kampfreihenfolge der
 *   Heldengruppe neu zu ordnen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie den Start-Slot des gezogenen Helden
 *   entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verfolgt die Mausposition während des Ziehens, bestimmt über f_027750 beziehungsweise
 *   f_028190 den Zielplatz anhand der Koordinatentabelle d_1a48f4, tauscht die Gruppenplätze und zeichnet die
 *   Leiste über f_0259e0 neu.
 === Ende Beschreibung === */
static inline void h_27420_color(Img *im,unsigned short k)
{
        switch(k) {
        case 20: case 40: case 60: case 80: case 100: ((RivaRasterImage*)(im))->f_0fb150(0); break;
        case 5: ((RivaRasterImage*)(im))->f_0fb150(d_1a069e); break;
        case 25: ((RivaRasterImage*)(im))->f_0fb150(d_1a06a0); break;
        case 45: ((RivaRasterImage*)(im))->f_0fb150(d_1a06a2); break;
        case 65: ((RivaRasterImage*)(im))->f_0fb150(d_1a06a4); break;
        case 85: ((RivaRasterImage*)(im))->f_0fb150(d_1a06a6); break;
        }
}
void Car::f_027420()
{
  short x0=d_1a0660[idx*2], y0=d_1a0662[idx*2];
  Img *t=new(mark(d_1a0640,0x110)) Img;
  Img *a1=t?f_0fac80(t,21,5):t;
  d_1c2be0.f_04fef0(a,((int)(((RivaRasterImage*)(a1))->f_0fb0b0())),0,7,0,320);
  Lk lk;
  ((RivaRasterImage*)(a1))->f_0fade0((void *)(d_1a34e0),(short)(x0-1),(short)(y0-1));
  if(o) {
    unsigned short pct;
    int value=f_027e20();
    short j=1;
    pct=value;
    short k=5;
    t=new(mark(d_1a0640,0x129)) Img;
    Img *a2=t?f_0fac80(t,1,3):t;
    while(k<=(short)pct) {
      h_27420_color(a2,k);
      ((RivaRasterImage*)(a2))->f_0fae30((void *)(d_1a34e0),(short)(x0+j-1),y0,1);
      j++; k=j*5;
    }
    if(a2) f_014710(((void *)(((RivaRasterImage*)(a2))->f_0fad20(0))));
  }
  if(a1) f_014710(((void *)(((RivaRasterImage*)(a1))->f_0fad20(0))));
}
//@ f_027690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übergibt einen mit der Maus gezogenen Gegenstand direkt an den Helden, über dessen Porträt das
 *   Objekt losgelassen wurde, und legt ihn automatisch in dessen Rucksack ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Ziel-Gruppenplatz und die
 *   Gegenstandsdaten und gibt die nicht untergebrachte Restmenge zurück.
 * - Wichtige Variablen: Nutzt die automatische Inventarablage f_025c50 für den Helden des gewählten
 *   Porträtslots.
 === Ende Beschreibung === */
void Car::f_027690() {
  unsigned t = (unsigned)operator new(9, mark(d_1a0640, 0x14e));
  Img *im = t ? f_0fac80((Img *)t, 4, 3) : (Img *)t;
  if (fl == 1) ((RivaRasterImage*)(im))->f_0fb150( d_1a067e);
  else ((RivaRasterImage*)(im))->f_0fb150( d_1a067c);
  Lk lk;
  int ix = idx;
  int dst = d_1a34e0;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( dst), d_1a0680[ix + ix], d_1a0682[ix + ix]);
  if (im) f_014710(((void *)(((RivaRasterImage*)(im))->f_0fad20( 0))));
}
//@ f_027750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt anhand der horizontalen Mausposition pos, über welchem der sieben Porträtplätze (6
 *   abwärts bis 0) sich ein gezogenes Heldenporträt gerade befindet. *(Hinweis: Hier liegt ein Originalfehler
 *   vor, da die Rückwärtsschleife über d_1a48f4[i * 2] - 20 keine Untergrenze i >= 0 prüft und bei weit links
 *   liegender Mausposition vor den Arrayanfang liest.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie die X-Koordinate pos entgegen und gibt
 *   den ermittelten Gruppenplatz-Index zurück.
 * - Wichtige Variablen: Vergleicht pos rückwärts ab Index i = 6 mit den X-Koordinaten der Porträtslots in
 *   d_1a48f4.
 === Ende Beschreibung === */
int Car::f_027750() {
  Clip cs;
  Clip nw;
  f_0d38b0(&cs);
  Lk lk;
  nw.a = d_1bc814; nw.b = d_1bc816; nw.c = d_1bc818; nw.d = d_1bc81a;
  f_0d38d0(&nw);
  int i = 6;
  short pos = f_027f80();
  int ok = 0;
  do {
    int lim = d_1a48f4[(short)i * 2];
    lim = (lim & 0) ? 0 : lim; // Haelt pos (si) im Schleifenkoerper statt Vorab-Hoisting in ecx
#if FIX_R014   /* R014: Untergrenze i > 0 vor Dekrement in der Rueckwaertsschleife ueber d_1a48f4 pruefen */
    if (i > 0 && pos < lim - 0x14) i = i - 1;
#else
    if (pos < lim - 0x14) i = i - 1;
#endif
    else ok = 1;
  } while (ok == 0);
  Clip rs;
  rs.a = cs.a; rs.b = cs.b; rs.c = cs.c; rs.d = cs.d;
  f_0d38d0(&rs);
  return i;
}
//@ f_027830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das Porträt und die Statusbalken eines einzelnen Gruppenmitglieds neu, wenn sich
 *   dessen Lebens- oder Astralpunkte geändert haben.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und den Gruppenplatz-Index und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Delegiert an die Zeichenfunktion f_0257f0.
 === Ende Beschreibung === */
void Car::f_027830(short p2) {
  fl = 0;
  if (o != 0 && 0 < p2) {
    if (f_045960(o, p2) != 0) fl = 1;
  }
}
//@ f_027860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fordert den Spieler auf, durch Anklicken eines Porträts in der unteren Leiste ein
 *   Gruppenmitglied für eine Aktion (etwa Zaubern, Talentprobe oder Gegenstandsnutzung) auszuwählen, und hebt
 *   die wählbaren Helden hervor.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie Filterflags für zulässige Helden
 *   entgegen und gibt den Index oder Zeiger des gewählten Helden zurück.
 * - Wichtige Variablen: Prüft über f_0415c0 die Anwesenheit und Handlungsfähigkeit der Helden auf den Plätzen 0
 *   bis 6.
 === Ende Beschreibung === */
void Car::f_027860() {
  if (idx != 0) return;
  int t = (int)operator new(9, mark(d_1a0640, 0x19b));
  Img *im = t ? f_0fac80((Img *)t, 0x33, 8) : (Img *)t;
  char *buf = (char *)operator new[](0x10, mark(d_1a0640, 0x19c));
  short x = 0x2c;
  strcpy(buf, f_0422b0((struct hero *)(o)));
  struct Trim {
    static void run(char *s) {
      short i = 8;
      s[i] = 0;
      while (i > 0) {
        i--;
        if (((signed char *)s)[i] == ' ') s[i] = 0;
      }
    }
  };
  Trim::run(buf);
  ((RivaRasterImage*)(im))->f_0fb150( 0x78);
  d_1c38b0.f_05e320(0, -1);
  Lk lk;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( d_1a34e0), 0x2c, 0x98);
  short w = d_1c38b0.f_0e9690(buf);
  x += (0x33 - w) / 2;
  d_1c38b0.f_0e9660(buf, x, 0x98);
  d_1c38b0.f_05e340();
  delete buf;
  if (im) f_014710(((void *)(((RivaRasterImage*)(im))->f_0fad20( 0))));
}
//@ f_0279f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet einen farbigen Auswahl- oder Statusrahmen um ein Heldenporträt in der unteren Leiste,
 *   um den aktiven Charakter oder das aktuelle Ziel zu markieren.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Gruppenplatz-Index und die Rahmenfarbe
 *   beziehungsweise den Stil und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt die Slot-Koordinaten aus d_1a48f4 und zeichnet das Rechteck in den
 *   Bildschirmpuffer.
 === Ende Beschreibung === */
void Car::f_0279f0() {
  if (idx != 0) return;
  int t = (int)new (mark(d_1a0640, 0x1c8)) Img;
  Img *im = t ? f_0fac80((Img *)t, 0x33, 8) : (Img *)t;
  ((RivaRasterImage*)(im))->f_0fb150( 0x78);
  sprintf(d_1c27a8, d_1b6480, f_045300(o));
  d_1c38b0.f_0e9300(d_1c27a8, 0x21040001);
  short x = 0x2c;
  d_1c38b0.f_05e320(0, -1);
  Lk lk;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( d_1a34e0), 0x2c, 0xa4);
  short w = d_1c38b0.f_0e9690(d_1c27a8);
  int d = (0x33 - w) / 2;
  int cx = x;
  cx = (cx & 0) ? 0 : cx; // Haelt this in ecx und x in di wie im Original
  d_1c38b0.f_0e9660(d_1c27a8, (short)(cx + d), 0xa4);
  d_1c38b0.f_05e340();
  if (im) f_014710(((void *)(((RivaRasterImage*)(im))->f_0fad20( 0))));
}
//@ f_027b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt bei Rechtsklick oder Sonderinteraktion auf einem Heldenporträt Kurzinformationen zum
 *   Zustand des Charakters an oder öffnet dessen Detailansicht.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this und den Gruppenplatz-Index entgegen und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Liest die Charakterwerte des Helden auf dem gewählten Slot über f_0415c0.
 === Ende Beschreibung === */
void Car::f_027b30() {
  if (idx != 0) return;
  int t = (int)operator new(9, mark(d_1a0640, 0x1f3));
  Img *im = t ? f_0fac80((Img *)t, 0x33, 8) : (Img *)t;
  ((RivaRasterImage*)(im))->f_0fb150( 0x78);
  sprintf(d_1c27a8, d_1b6484, f_043170((struct hero *)(o)));
  d_1c38b0.f_05e320(0, -1);
  Lk lk;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( d_1a34e0), 0x2c, 0xb0);
  d_1c38b0.f_0e9660(d_1c27a8, 0x2c, 0xb0);
  d_1c38b0.f_0e9510(0x21040002, 0x4b, 0xb0);
  d_1c38b0.f_05e340();
  if (im) f_014710(((void *)(((RivaRasterImage*)(im))->f_0fad20( 0))));
}
//@ f_027c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vertauscht die Position zweier Helden innerhalb der siebenköpfigen Gruppenaufstellung und
 *   aktualisiert anschließend die Porträtleiste sowie den Gruppenanführer.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie die beiden Gruppenplatz-Indizes und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Tauscht die Slot-Zuweisungen der beiden Gruppenmitglieder und zeichnet die betroffenen
 *   Porträts über f_0257f0 neu.
 === Ende Beschreibung === */
void Car::f_027c50() {
  if (idx != 0) return;
  short v = f_043a80(o, 6) * 100;
  int t = (int)operator new(9, mark(d_1a0640, 0x21c));
  Img *im = t ? f_0fac80((Img *)t, 0x33, 8) : (Img *)t;
  ((RivaRasterImage*)(im))->f_0fb150( 0x78);
  v = v - f_043170((struct hero *)(o));
  if (v < 0) v = 0;
  sprintf(d_1c27a8, d_1b6487, v);
  d_1c38b0.f_05e320(0, -1);
  Lk lk;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( d_1a34e0), 0x2c, 0xb8);
  d_1c38b0.f_0e9660(d_1c27a8, 0x2c, 0xb8);
  d_1c38b0.f_0e9510(0x21040003, 0x4b, 0xb8);
  d_1c38b0.f_05e340();
  if (im) f_014710(((void *)(((RivaRasterImage*)(im))->f_0fad20( 0))));
}
//@ f_027d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein aktuelles Status- oder Modusfeld der Porträtleiste zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this entgegen und liefert den gespeicherten
 *   Statuswert zurück.
 * - Wichtige Variablen: Gelesen wird ein Statusfeld innerhalb des carrier-Objekts.
 === Ende Beschreibung === */
void Car::f_027d90(char *s) {
  short i = 8;
  s[i] = 0;
  while (i > 0) {
    i--;
    if (((signed char *)s)[i] == ' ') s[i] = 0;
  }
}
//@ f_027dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sperrt oder entsperrt die Interaktion mit der unteren Porträtleiste während laufender
 *   Zwischensequenzen oder modaler Dialoge.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie das neue Sperrflag und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Aktualisiert die Aktivierungsflags der sieben Slot-Steuerelemente.
 === Ende Beschreibung === */
void Car::f_027dc0(Img *im) {
  Lk mg;
  ((RivaRasterImage*)(im))->f_0fade0((void *)( d_1a34e0), d_1a48f4[idx * 2], d_1a48f6[idx * 2]);
}
//@ f_027e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Nimmt Mausklicks und Ziehbewegungen auf einem einzelnen Porträtkästchen entgegen und leitet
 *   sie an die übergeordnete Heldenleiste (f_0272d0 bzw. f_027420) weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält den Slot-Objektzeiger this sowie die Mausereignis-Struktur und
 *   gibt zurück, ob das Ereignis verarbeitet wurde.
 * - Wichtige Variablen: Liest die Gruppenplatz-Nummer des Slots und ruft die entsprechende Methode der
 *   Hauptleiste auf.
 === Ende Beschreibung === */
int Car::f_027e20() {
  int pa = f_043170((struct hero *)(o));
  short loc = f_043a80(o, 6) * 100;
  int n = 0;
  short k;
  for (k = 0xf; k <= 0x1e; k++) {
    if (f_042a60((struct hero *)(o), k) != 0) n++;
  }
  n = n * 100;
  int cp = n / 16;
  pa = pa * 100;
  int r = (short)(pa / loc);
  if (cp > r) r = cp;
  if ((short)r > 100) r = 100;
  return r;
}
//@ f_027eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gleicht die sieben Slots der Porträtleiste mit der aktuellen Gruppenzusammensetzung ab,
 *   aktiviert belegte Plätze und deaktiviert leere Slots.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft in einer Schleife über die Plätze 0 bis 6 mit f_0415c0, auf welchen Slots
 *   tatsächlich Helden eingetragen sind.
 === Ende Beschreibung === */
void Car::f_027eb0(Img *im, unsigned short k) {
  switch (k) {
    case 0x14: case 0x28: case 0x3c: case 0x50: case 0x64: ((RivaRasterImage*)(im))->f_0fb150( 0); break;
    case 5: ((RivaRasterImage*)(im))->f_0fb150( d_1a069e); break;
    case 0x19: ((RivaRasterImage*)(im))->f_0fb150( d_1a06a0); break;
    case 0x2d: ((RivaRasterImage*)(im))->f_0fb150( d_1a06a2); break;
    case 0x41: ((RivaRasterImage*)(im))->f_0fb150( d_1a06a4); break;
    case 0x55: ((RivaRasterImage*)(im))->f_0fb150( d_1a06a6); break;
  }
}
//@ f_027f80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den gesamten unteren Leistenbereich einschließlich Hintergrund, allen sieben
 *   Heldenporträts, Lebens-/Astralbalken und Rahmenmarkierungen vollständig neu auf den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt keinen Wert zurück.
 * - Wichtige Variablen: Kombiniert die Synchronisation f_027eb0 mit dem Neuzeichnen aller Porträts über
 *   f_0259e0.
 === Ende Beschreibung === */
short Car::f_027f80() {
  Img *t = new (mark(d_1a0640, 700)) Img;
  Img *p = t ? f_0fac80(t, 0x20, 0x20) : t;
  t = new (mark(d_1a0640, 0x2bd)) Img;
  Img *q = t ? f_0fac10(t, 0x20, 0x20, 0) : t;
  char *buf = new (mark(d_1a0640, 0x2be)) char[0x400];
  short r = 0;
  ((RivaRasterImage*)(p))->f_0fb090((void *)( f_044ea0(o)));
  d_1c2be0.f_04fef0(a, (int)buf, 0, 6, 0, 0x140);
  ((RivaRasterImage*)(q))->f_0fb060((void *)( (int)buf));
  short off = d_1bf4f0 - d_1a48f4[idx * 2];
  // Mauskoordinaten in der Interrupt-Schleife frisch aus dem Speicher laden
  f_0d2f40(d_1a48f4[idx * 2], *(volatile short *)&d_1bf4f2);
  (*(volatile short *)&d_1bf4fc) = d_1bf4f0;
  while (!f_0d3790()) {
    if (d_1bf4f0 != d_1bf4fc) {
      f_099ea0();
      ((RivaRasterImage*)(q))->f_0fade0((void *)( d_1a34e0), d_1bf4fc, 0x9c);
      d_1bf4ed = 1;
      ((RivaRasterImage*)(q))->f_0fafb0((void *)( d_1a34e0), d_1bf4f0, 0x9c);
      ((RivaRasterImage*)(p))->f_0fade0((void *)( d_1a34e0), d_1bf4f0, 0x9c);
      d_1bf4fc = d_1bf4f0;
      r = *(volatile short *)&d_1bf4f0;
      d_1bf4ed = 0;
    }
    f_0d32f0();
  }
  d_1bf4e8 = 0;
  f_0d2f40((short)(d_1bf4f0 + off), d_1bf4f2);
  ((RivaRasterImage*)(q))->f_0fade0((void *)( d_1a34e0), d_1bf4fc, 0x9c);
  delete buf;
  if (p) f_014710(((void *)(((RivaRasterImage*)(p))->f_0fad20( 0))));
  if (q) f_014710(((void *)(((RivaRasterImage*)(q))->f_0fad20( 0))));
  return r;
}
