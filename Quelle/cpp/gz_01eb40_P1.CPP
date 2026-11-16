/* === Beschreibung (Katalog) ===
 * Einheit gz_01eb40
 *
 * Diese Einheit (Adressbereich 0x01eb40-0x01fb40) enthält zwei getrennte Subsysteme:
 * 1. Badehaus / Schwimmort (D : B1, f_01eb80-f_01f350, Textgruppe 0x32xxxxxx): Eine Ortsklasse, in der die
 *   Heldengruppe schwimmen gehen (wobei ein Zwerg in bis zu 3 Unterrichtsstunden TA_SCHWIMMEN + 1 erlernen kann)
 *   oder zwei bezahlte Bade-/Erholungsleistungen zu 10 bzw. 30 Hellern je Held in Anspruch nehmen kann.
 * 2. Gegenstandsraster / Blätter- und Rollbalkenlogik (Bar = Board, f_01f3c0-f_01fa80): Konstruktor, Destruktor,
 *   Kategorie-Filter (0 Kraut/Trank, 1 Waffe/Rüstung, 2 Sonstiges, 3 alles), Rollbalken-Prozentrechnung und
 *   zeilen-/seitenweises Blättern für das Gegenstandsraster (ergänzt die Einheit board).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 19/28 gleich (suche.py 26.10.2026, Basis gz_01eb40_P1.CPP)
// gz_01eb40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01EB40-0x01FB40
#include <string.h>
#pragma pack(1)


struct Obj;
struct Item { ~Item(); };
struct Lst;
struct Bar {
    short x; short y; int v; short total; short cols; short rows; short mode; short pos; Lst *list; Item **items; int p1a;
    void f_01eb40(); void f_01eb50(); int f_01eb60(); void f_01eb70(int p);
    Bar *f_01f3c0(short a, short b, short c, short d, int e, int f, int g);
    Bar *f_01f410(int fl);
    void f_01f450(short m); short f_01f460(); void f_01f470(short p); short f_01f480();
    int f_01f490(); void f_01f560(int p); int f_01f620();
    void f_01f6f0(); void f_01f7d0(); void f_01f8b0(); void f_01f990();
    void f_01fa70(); void f_01fa80();
    int f_020150();
};
struct B1 {
    char pad[0x58];
    B1(short s);
    virtual int f_01ec20(unsigned short m);
    virtual void f_01ec10();
    virtual void v2();
    virtual ~B1();
    virtual void v4(); virtual void v5(); virtual void v6();
};
struct D : B1 {
    D(short s);
    ~D();
    virtual int f_01ec20(unsigned short m);
    virtual void f_01ec10();
    virtual void v2();
};
int f_020090(Bar *p1, int p2);
void *f_038c40(void *p1);
void *f_0391b0(void *p1, void *p2);
signed char f_03ad80(Obj *p1, int p2);
int f_03af20(Obj *p1, int p2, int p3);
int f_039320(void *p1, int p2);
int f_044190(void *p1);



int f_0b9060(void *p1);
int f_0bf730(void *p1, int p2);
int f_0d49b0(void *p1);
int f_0d4a60(void *p1);
int f_0db8b0(void *p1, int p2);
short f_0dbfe0(void *p1);
int f_0dbe20(void *p1, int p2, int p3);
Obj *f_0dd3a0(void *p1, int p2, int p3);
int f_0de5a0(void *p1, int p2);
int f_0de5d0(void *p1, int p2);
int f_0de7e0(void *p1);
int f_0e33a0(void *p1, int p2);
unsigned short f_11c320(Lst *p1);
short f_11c620(Lst *p1, int p2);
int f_125ed0(void *p1, int p2);
int f_125f70(void *p1, int p2);
short f_145760(int p1, int p2);
extern unsigned char d_1bc768;
extern short d_1bc769;
extern void *d_1c0004;
extern volatile short d_1c212a; // Erzwingt separates Laden und Inkrementieren des globalen Zaehlers in f_01eb80
extern void **d_1c212c;

extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3498;
extern int d_1c3870;
extern signed char d_1a9670;
void f_01eee0(void *self);

#define REFRESH \
    { void *o = f_038c40(d_1c0004); \
      do { if (f_0d4a60(o) == 1) f_044190(o); o = f_0391b0(d_1c0004, o); } while (o != f_038c40(d_1c0004)); \
      f_0dbe20(d_1c0004, 0x140, 0x1e0); }

inline int Bar::f_020150()
{
    short cnt;
    short n2, v, i;
    int cls;
    short zero = 0;
    int changed;
    Bar *p = this;
    i = 0;
    n2 = f_11c320(p->list);
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)p->mode != (unsigned short)3) {
                v = f_11c620(p->list, i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if ((short)cls != p->mode) goto next;
            }
            cnt++;
next:
            i++;
        } while (i < n2);
    }
    changed = (int)this ^ (int)this; // Erzeugt xor ecx,ecx erst nach der Zaehlschleife wie im Original
    cnt -= total;
    if (cnt < 0) cnt = 0;
    if (pos < zero) {
        changed = 1;
        pos = zero;
    }
    if (cnt < pos) {
        changed = 1;
        pos = cnt;
    }
    return changed;
}

inline int ok3b() { return (signed char)d_1bc768 < 3; }

#define BODY0A0 \
    short s = f_0dbfe0(d_1c0004); \
    short n = (short)(s * 10); \
    if (f_0de7e0(d_1c0004) > n) { \
        f_0db8b0(d_1c0004, n); \
        f_0de5a0(d_1c0004, 2); \
        f_125ed0(&d_1c2c44, s * 20); \
        f_0de5d0(d_1c0004, 2); \
        f_0bf730(&d_1c2c64, 0x32000003); \
        REFRESH \
        return; \
    } \
    RivaTextContext m(&d_1c349c, &d_1c3870, &d_1c3498); \
    m.tables.tail.short_numbers[1] = n / 10; \
    f_0bf730(&d_1c2c64, 0x32000005);

#define BODY1D0 \
    short s = f_0dbfe0(d_1c0004); \
    short n = (short)(s * 30); \
    if (f_0de7e0(d_1c0004) > n) { \
        f_0db8b0(d_1c0004, n); \
        f_0de5a0(d_1c0004, 2); \
        f_125f70(&d_1c2c44, 5); \
        f_0de5d0(d_1c0004, 2); \
        f_0bf730(&d_1c2c64, 0x32000004); \
        REFRESH \
        return; \
    } \
    RivaTextContext m(&d_1c349c, &d_1c3870, &d_1c3498); \
    m.tables.tail.short_numbers[1] = n / 10; \
    f_0bf730(&d_1c2c64, 0x32000005);

inline void i_0a0() { BODY0A0 }
inline void i_1d0() { BODY1D0 }

//@ f_01eb40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt das 32-Bit-Feld an Offset +0x04 des übergebenen Objekts auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird das int-Feld this->v (+0x04).
 === Ende Beschreibung === */
void Bar::f_01eb40() { v = 0; }
//@ f_01eb50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt das 32-Bit-Feld an Offset +0x04 des übergebenen Objekts auf 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird das int-Feld this->v (+0x04).
 === Ende Beschreibung === */
void Bar::f_01eb50() { v = 1; }
//@ f_01eb60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt den aktuellen Wert des 32-Bit-Felds an Offset +0x04 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und liefert this->v (int).
 * - Wichtige Variablen: Gelesen wird das int-Feld this->v (+0x04).
 === Ende Beschreibung === */
int Bar::f_01eb60() { return v; }
//@ f_01eb70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schreibt den übergebenen Wert p in das 32-Bit-Feld an Offset +0x04.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie den Wert p (int) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Geändert wird das int-Feld this->v (+0x04).
 === Ende Beschreibung === */
void Bar::f_01eb70(int p) { v = p; }

//@ f_01eb80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Als statischer Initialisierer setzt die Funktion die 1-Byte-Ortsvariable d_1bc768 (Zähler für
 *   die absolvierten Schwimmstunden des Zwergs, 0..3) auf 0, weist ihr die Spielstandskennung d_1bc769 = 0x11 zu
 *   und trägt ihre Adresse in das globale Register der zu speichernden Byte-Ortsvariablen d_1c212c[d_1c212a++]
 *   ein.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Initialisiert und registriert wird d_1bc768 (mit Kennung d_1bc769 = 0x11) in der Tabelle
 *   d_1c212c (Zähler d_1c212a).
 === Ende Beschreibung === */
void f_01eb80()
{
    d_1bc768 = 0;
    d_1bc769 = 0x11;
    d_1c212c[d_1c212a] = &d_1bc768;
    ++d_1c212a;
}

//@ f_01ebc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor ruft zunächst den Basiskonstruktor f_0b8490(p, s) für allgemeine Orte auf und
 *   trägt anschließend an Offset +0x58 die eigene virtuelle Methodentabelle d_1baaec der Badeort-Klasse D ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p (void *, this) und die Ortskennung s (short)
 *   und gibt p zurück.
 * - Wichtige Variablen: Gesetzt wird der Vtable-Zeiger an +0x58 auf d_1baaec.
 === Ende Beschreibung === */
void *f_01ebc0(void *p, short s)
{
    extern int d_1baaec;
    extern B1 *f_0b8490(B1 *, short);
    B1 *q = f_0b8490((B1 *)p, s);
    *(void **)((char *)q + 0x58) = &d_1baaec;
    return q;
}
//@ f_01ebd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor der Ortsklasse D baut die Orts-Basisklasse B1 ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (D *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Betroffen ist das Ortsobjekt this.
 === Ende Beschreibung === */
D::~D() {}
//@ f_01ec10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese virtuelle Methode der Ortsklasse D hat einen leeren Rumpf und führt keine Aktion aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (D *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void D::f_01ec10() {}

//@ f_01ec20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die virtuelle Methode verarbeitet den vom Spieler im Badeort gewählten Menüpunkt m: bei 0x81
 *   gibt sie die Ortsbeschreibung aus (f_0b9060), bei 0x8f startet sie das Schwimmen gehen (f_01eee0), bei 0x90
 *   die günstige Badeleistung zu 10 Hellern je Held (f_01f0a0), bei 0x91 die teure Badeleistung zu 30 Hellern je
 *   Held (f_01f1d0) und bei 0x80 (Ort verlassen) gibt sie 1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ortsobjekt this (D *) und den Ereigniscode m (unsigned
 *   short); sie liefert 1 bei m == 0x80, sonst 0.
 * - Wichtige Variablen: Delegiert an f_0b9060, f_01eee0, f_01f0a0 und f_01f1d0.
 === Ende Beschreibung === */
int D::f_01ec20(unsigned short m)
{
    int r = 0;
    switch (m) {
    case 0: break;
    case 0x81: f_0b9060(this); break;
    case 0x8f: f_01eee0(this); break;
    case 0x90: i_0a0(); break;
    case 0x91: i_1d0(); break;
    case 0x80: r = 1; break;
    }
    return r;
}

//@ f_01eee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion prüft über f_0dd3a0(d_1c0004, 6, 0), ob sich ein handlungsfähiger Zwerg
 *   (Heldentyp 6 = HERO_TYPE_ZWERG) in der aktiven Gruppe befindet und dieser bisher weniger als 3
 *   Schwimmstunden (d_1bc768 < 3) erhalten hat: falls ja, wird je nach Stunde (0, 1, 2) der Text 0x32000006,
 *   0x32000007 bzw. 0x32000008 mit dem Namen des Zwergs ausgegeben, in der dritten Stunde (d_1bc768 == 2) bei
 *   einem Schwimmen-Talentwert (0x0e = TA_SCHWIMMEN) unter 11 ein 2W6-Wurf (f_145760(2, 12)) gegen den
 *   Talentwert ausgeführt, bei Überwürfeln die Erfolgsmeldung 0x32000009 gezeigt und Schwimmen um +1 gesteigert
 *   (f_03af20) sowie d_1bc768 um 1 erhöht. Anschließend erhalten alle Helden für 3 Zeiteinheiten
 *   (f_125f70(&d_1c2c44, 3)) den Erholungszuschlag +1, Meldung 0x32000002 wird ausgegeben und über REFRESH
 *   werden Statuswirkungen geprüft sowie Hunger und Durst aller Helden um 100 Punkte gesenkt.
 * - Eingaben und Rückgabe: Die Funktion erhält den ungenutzten Ortszeiger self (void *) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: d_1bc768 zählt die Zwergen-Schwimmstunden (0..3), d_1c0004 ist die aktive Heldengruppe,
 *   d_1c2c44 die Spieluhr und d_1c2c64 das Meldungsobjekt.
 === Ende Beschreibung === */
void f_01eee0(void *self)
{
    Obj *w = f_0dd3a0(d_1c0004, 6, 0);
    if (w != 0 && ok3b()) {
        RivaTextContext m(&d_1c349c, &d_1c3870, &d_1c3498);
        m.tables.p[1] = (int)w;
        switch (d_1bc768) {
        case 0: f_0bf730(&d_1c2c64, 0x32000006); break;
        case 1: f_0bf730(&d_1c2c64, 0x32000007); break;
        case 2:
            f_0bf730(&d_1c2c64, 0x32000008);
            if (f_03ad80(w, 0xe) < 11) {
                int t = f_145760(2, 0xc);
                if (t > f_03ad80(w, 0xe)) {
                    f_0bf730(&d_1c2c64, 0x32000009);
                    f_03af20(w, 0xe, 1);
                }
            }
            break;
        }
        d_1bc768 = d_1bc768 + 1;
    }
    f_0de5a0(d_1c0004, 1);
    f_125f70(&d_1c2c44, 3);
    f_0de5d0(d_1c0004, 1);
    f_0bf730(&d_1c2c64, 0x32000002);
    REFRESH
}

//@ f_01f0a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zählt über f_0dbfe0(d_1c0004) die verfügbaren Helden s und berechnet den
 *   Gesamtpreis n = s * 10 Heller: besitzt die Gruppe mehr Geld (f_0de7e0(d_1c0004) > n), zieht sie den Betrag
 *   ab (f_0db8b0), erhöht den Erholungszuschlag aller Helden um +2, rückt die Spielzeit um s * 20 Minuten vor
 *   (f_125ed0), nimmt den Zuschlag zurück, zeigt die Erfolgsmeldung 0x32000003 und stillt Hunger und Durst der
 *   Gruppe (REFRESH); reicht das Geld nicht, erscheint die Ablehnungsmeldung 0x32000005 mit dem Preis in
 *   Silberstücken (n / 10).
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden d_1c0004 (Heldengruppe), d_1c2c44 (Spieluhr) und d_1c2c64
 *   (Meldungsausgabe). Hinweis (Originalfehler): Die Geldprüfung lautet if (f_0de7e0(d_1c0004) > n) statt >= n;
 *   hat die Gruppe exakt s * 10 Heller, wird die Leistung trotz ausreichendem Geld mit Meldung 0x32000005
 *   verweigert.
 === Ende Beschreibung === */
void f_01f0a0()
{
    BODY0A0
}

//@ f_01f1d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Analog zu f_01f0a0 berechnet die Funktion den Preis n = s * 30 Heller für s verfügbare Helden,
 *   zieht bei ausreichendem Gruppengeld (> n) den Betrag ab, gewährt während einer Zeitspanne von 5 Einheiten
 *   (f_125f70(&d_1c2c44, 5)) den Erholungszuschlag +2, gibt die Erfolgsmeldung 0x32000004 aus und versorgt die
 *   Gruppe über REFRESH; andernfalls gibt sie die Meldung 0x32000005 mit dem Silberpreis n / 10 aus.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden d_1c0004, d_1c2c44 und d_1c2c64. Hinweis (Originalfehler): Auch hier
 *   prüft f_0de7e0(d_1c0004) > n auf strikt größer statt >= n, sodass exakt passendes Geld abgewiesen wird.
 === Ende Beschreibung === */
void f_01f1d0()
{
    BODY1D0
}

//@ f_01f2f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion führt allein den REFRESH-Block aus: sie durchläuft die Ringliste der aktiven
 *   Heldengruppe (f_038c40 / f_0391b0), ruft für jeden verfügbaren Helden (f_0d4a60 == 1) die
 *   Nachbearbeitungsfunktion f_044190 auf und senkt anschließend Hunger und Durst aller Gruppenmitglieder über
 *   f_0dbe20(d_1c0004, 0x140, 0x1e0) um bis zu 100 Punkte.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Bearbeitet wird die aktive Heldengruppe d_1c0004.
 === Ende Beschreibung === */
void f_01f2f0()
{
    REFRESH
}

//@ f_01f350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion ermittelt über f_039320(sl, sel) den Helden mit dem höchsten Wert im Talent sel,
 *   zählt dessen laufende Position n unter allen handlungsfähigen Helden (f_0d49b0) in den Plätzen sl[0..6]
 *   (unter Auslassung des gesperrten Platzes d_1a9670) und trägt n über f_0e33a0(&d_1c2c64, n) als Vorauswahl
 *   für den nächsten Auswahldialog ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das 7-elementige Heldenplatz-Array sl (Obj ) und die Talentnummer
 *   sel (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden der ausgeschlossene Heldenplatz d_1a9670 und das Dialogobjekt d_1c2c64.
 *   Hinweis (Originalfehler): Die Schleife for (i = 0; i <= 6; i++, o = sl[i]) führt nach dem Durchlauf für i ==
 *   6 (falls die Schleife nicht vorher per break verlassen wurde, etwa weil t == 0 ist oder auf Platz d_1a9670
 *   steht) im Inkrementschritt i++ (i = 7) und o = sl[7] aus und liest damit ein Element hinter dem Ende des
 *   Heldenarrays sl[0..6].
 === Ende Beschreibung === */
void f_01f350(Obj **sl, short sel)
{
    void *t = (void *)f_039320(sl, sel);
    short n = 0;
    short i;
    Obj *o = sl[0];
    for (i = 0; i <= 6; i++, o = sl[i]) {
        if (o && f_0d49b0(o) && i != (signed char)d_1a9670) {
            if (o == t) break;
            n++;
        }
    }
    f_0e33a0(&d_1c2c64, n);
}

//@ f_01f3c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert ein Gegenstandsraster-Objekt (Bar / Board, 0x1e Bytes): er
 *   speichert Bildschirmursprung (a, b), Rasterdimensionen (c, d), Gesamtfeldzahl total = c * d und den Zeiger
 *   auf die Gegenstandsliste e, setzt den Blätterversatz pos = 0 sowie den Filter mode = 3 (alle Gegenstände
 *   anzeigen), lädt über f_020090(this, f) (board) die Hintergrundbilder der Rasterfelder und merkt die
 *   Symbolressource g.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (Bar *), die Bildschirmkoordinaten a, b
 *   (short), die Rastermaße c, d (short), die Gegenstandsliste e (int / Lst *), die Hintergrundressource f (int)
 *   sowie die Symbolressource g (int) und gibt this zurück.
 * - Wichtige Variablen: Gesetzt werden x/y (+0x00/+0x02), total (+0x08), cols/rows (+0x0a/+0x0c), mode (+0x0e),
 *   pos (+0x10), list (+0x12), items (+0x16) und p1a (+0x1a).
 === Ende Beschreibung === */
Bar *Bar::f_01f3c0(short a, short b, short c, short d, int e, int f, int g)
{
    x = a;
    y = b;
    list = (Lst *)e; cols = c; rows = d;
    pos = 0;
    total = cols * rows;
    mode = 3;
    f_020090(this, f);
    p1a = g;
    return this;
}

//@ f_01f410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor gibt in einer Schleife alle total Feldhintergrund-Bildobjekte items[0 .. total
 *   - 1] und anschließend das Zeigerarray items selbst frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (Bar *) sowie das ungenutzte
 *   Destruktor-Flag fl (int) und gibt this zurück.
 * - Wichtige Variablen: Freigegeben wird das Array this->items (+0x16) mit this->total (+0x08) Einträgen.
 === Ende Beschreibung === */
Bar *Bar::f_01f410(int fl)
{
    for (short i = 0; i < total; i++) {
        Item *q = items[i];
        delete q;
    }
    delete items;
    return this;
}

//@ f_01f450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion stellt den Kategorie-Filter this->mode auf den gewünschten Wert m (0 =
 *   Kraut/Trank, 1 = Waffe/Rüstung, 2 = Sonstiges, 3 = alle Gegenstände) und setzt den Blätterversatz this->pos
 *   auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und den Filtermodus m (short) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert werden this->mode (+0x0e) und this->pos (+0x10).
 === Ende Beschreibung === */
void Bar::f_01f450(short m) { pos = 0; mode = m; }
//@ f_01f460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt den aktuell eingestellten Kategorie-Filter this->mode (0..3) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und liefert this->mode (short).
 * - Wichtige Variablen: Gelesen wird this->mode (+0x0e).
 === Ende Beschreibung === */
short Bar::f_01f460() { return mode; }
//@ f_01f470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schreibt den übergebenen Versatz p ohne Bereichsbegrenzung direkt in das Feld
 *   this->pos.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und den neuen Blätterversatz p
 *   (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10).
 === Ende Beschreibung === */
void Bar::f_01f470(short p) { pos = p; }
//@ f_01f480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liefert den aktuellen Blätterversatz this->pos (Index des ersten im Raster
 *   sichtbaren passenden Gegenstands) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und gibt this->pos (short) zurück.
 * - Wichtige Variablen: Gelesen wird this->pos (+0x10).
 === Ende Beschreibung === */
short Bar::f_01f480() { return pos; }

//@ f_01f490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zählt alle Einträge der Gegenstandsliste this->list, die zum aktuellen
 *   Kategorie-Filter this->mode passen, zieht davon die Anzahl der sichtbaren Rasterfelder this->total ab und
 *   berechnet - sofern mehr Gegenstände als Felder vorhanden sind (cnt > 0) - die prozentuale Position des
 *   Rollbalkens pos * 100 / cnt (0..100).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und gibt den Prozentwert (0..100,
 *   int) zurück.
 * - Wichtige Variablen: Genutzt werden this->list, this->mode, this->total, this->pos und die globale
 *   Gegenstands-Beschreibungsliste d_1c2c40.
 === Ende Beschreibung === */
int Bar::f_01f490()
{
    short cnt;
    short n2, v, i;
    int cls;
    int r = 0;
    Bar *p = this;
    i = 0;
    n2 = f_11c320(p->list);
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)p->mode != (unsigned short)3) {
                v = f_11c620(p->list, i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if ((short)cls != p->mode) goto next;
            }
            cnt++;
next:
            i++;
        } while ((short)(i & 0xffff) < n2); // 16-Bit-Maske haelt den Schleifenvergleich und die Registerwahl wie im Original
    }
    cnt -= total;
    if (cnt > 0) {
        short value = pos;
        r = (value * 100) / cnt;
    }
    return r;
}

//@ f_01f560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Als Umkehrung zu f_01f490 zählt die Funktion alle zum Filter this->mode passenden Gegenstände
 *   in this->list, zieht this->total ab und setzt den Blätterversatz this->pos = (cnt - total) * p / 100 passend
 *   zur vom Spieler gezogenen Rollbalken-Position p.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und den Prozentwert p (int, 0..100)
 *   und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10) anhand von this->list, this->mode, this->total und
 *   d_1c2c40.
 === Ende Beschreibung === */
void Bar::f_01f560(int p)
{
    short cnt;
    short n2, v, cls, i;
    Bar *obj = this;
    i = 0;
    n2 = (short)f_11c320(obj->list);
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)obj->mode != (unsigned short)3) {
                v = f_11c620(obj->list, i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if (cls != obj->mode) goto f_01f560_next;
            }
            cnt++;
f_01f560_next:
            i++;
        } while (i < n2);
    }
    cnt -= total;
    pos = ((int)cnt * (int)(short)p) / 100;
}

//@ f_01f620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zählt alle zum Filter this->mode passenden Gegenstände cnt: sind mehr Gegenstände
 *   vorhanden, als gleichzeitig in das Raster passen (cnt > total), gibt sie den sichtbaren Anteil total * 100 /
 *   cnt in Prozent zurück, andernfalls 100.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und liefert die relative
 *   Rollbalken-Größe in Prozent (1..100, int).
 * - Wichtige Variablen: Genutzt werden this->list, this->mode, this->total und d_1c2c40.
 === Ende Beschreibung === */
int Bar::f_01f620()
{
    int r = 100;
    short cnt;
    short n2, v, cls, i;
    Bar *obj = this;
    i = 0;
    n2 = (short)f_11c320(obj->list);
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)obj->mode != (unsigned short)3) {
                v = f_11c620(obj->list, i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if (cls != obj->mode) goto f_01f620_next;
            }
            cnt++;
        f_01f620_next:
            i++;
        } while ((short)(i & 0xffff) < n2); // 16-Bit-Maske haelt den Schleifenvergleich und die Registerwahl wie im Original
    }
    if (cnt > total) r = (total * 100) / (int)cnt;
    return r;
}

//@ f_01f6f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion verringert den Blätterversatz this->pos um die Zeilenbreite this->rows (Offset
 *   +0x0c) und begrenzt this->pos anschließend auf den gültigen Bereich 0 .. max(0, passende_eintraege - total).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10) unter Nutzung von this->rows (+0x0c) und this->total
 *   (+0x08).
 === Ende Beschreibung === */
void Bar::f_01f6f0()
{
    pos -= rows;
    f_020150();
}

//@ f_01f7d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion erhöht den Blätterversatz this->pos um this->rows (Offset +0x0c) und begrenzt ihn
 *   anschließend auf 0 .. max(0, passende_eintraege - total).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10).
 === Ende Beschreibung === */
void Bar::f_01f7d0()
{
    pos += rows;
    f_020150();
}

//@ f_01f8b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion verringert den Blätterversatz this->pos um die gesamte Feldanzahl this->total
 *   (eine volle Rasterseite) und begrenzt ihn anschließend auf 0 .. max(0, passende_eintraege - total).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10) unter Nutzung von this->total (+0x08).
 === Ende Beschreibung === */
void Bar::f_01f8b0()
{
    pos -= total;
    f_020150();
}

//@ f_01f990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion erhöht den Blätterversatz this->pos um die gesamte Feldanzahl this->total (eine
 *   volle Rasterseite) und begrenzt ihn anschließend auf 0 .. max(0, passende_eintraege - total).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10) unter Nutzung von this->total (+0x08).
 === Ende Beschreibung === */
void Bar::f_01f990()
{
    pos += total;
    f_020150();
}

//@ f_01fa70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Blätterversatz this->pos auf 0 (erste Seite).
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10).
 === Ende Beschreibung === */
void Bar::f_01fa70() { pos = 0; }

//@ f_01fa80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zählt alle zum Filter this->mode passenden Gegenstände cnt und setzt den
 *   Blätterversatz this->pos auf max(0, cnt - total), sodass die letzten Einträge der Liste das Raster füllen.
 * - Eingaben und Rückgabe: Die Funktion erhält das Rasterobjekt this (Bar *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird this->pos (+0x10) anhand von this->list, this->mode und this->total.
 === Ende Beschreibung === */
void Bar::f_01fa80()
{
    int cnt;
    short n2, v, cls, i;
    Bar *obj = this;
    i = 0;
    n2 = (short)f_11c320(obj->list);
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)obj->mode != (unsigned short)3) {
                v = f_11c620(obj->list, i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if (cls != obj->mode) goto f_01fa80_next;
            }
            cnt++;
f_01fa80_next:
            i++;
        } while (i < n2);
    }
    pos = cnt - total;
    if (pos < 0) pos = 0;
}
