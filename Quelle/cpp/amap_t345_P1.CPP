/* === Beschreibung (Katalog) ===
 * Einheit amap_t345
 *
 * Diese Einheit umfasst die Teile 3 bis 5 der Übersichtskarte (amap.cpp, Adressbereich 0x0176f0-0x01a470). Sie
 * implementiert die gesamte interaktive Bedienung des Automap-Bildschirms: Knopfleiste, Anzeige, Eingabe,
 * Bearbeitung und Löschung von Kartennotizen im Infofeld rechts oben, Maus- und Tastatursteuerung des
 * Kartencursors, Zielpunktwahl auf der Karte, Hauptschleife des Kartenfensters sowie die von außen (aus der
 * 3D-/2D-Bewegung, beim Öffnen von Türen oder beim Kauf eines Stadtplans) aufgerufenen Funktionen zur
 * Kartenaufdeckung und zum automatischen Eintragen von Spielnotizen.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAMOUS.H"
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 25/33 gleich (suche.py 30.10.2026, Basis amap_t345_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra493: echte Vereinigung amap_t3+t4+t5, 0176f0-01a470.
// amap.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x015040-0x01A470
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---

typedef signed char SC;
static inline int EQBF(const signed char &x, int v) { return x == v; }
  int f_0d37e0(); int f_0d3800(); 

struct Wnd { char b[0x42]; Wnd(int a, int b2, int c, int d, int e, short f); ~Wnd(); void f_0daba0(void *pal); };
struct Dlg { char b[0x45]; Dlg(int a, int b2, int c, int d, RivaRasterImage *i, int e, int f); ~Dlg(); void f_0619e0(SC *s); void f_060ae0(SC *s, int v); };
struct Txt { char b[4];
  void f_05e2a0(short *a, short *b2, short *c, short *d); void f_05e2d0(int a, int b2, int c, int d);
  void f_05e320(int a, int b2); void f_05e360(short *a, short *b2); int f_05e420(int a);
  void f_05e840(int a); void f_0e9650(SC *s); };
struct Msg { char b[4]; int f_0bf6f0(int id); void f_0bf730(int id); };
struct Grid { char b[10]; unsigned f_04fd60(unsigned short x, unsigned short y); };
struct Strm { char b[14];
  int f_01b060(short *x, short *y); int f_01b0a0(short *x, short *y); int f_01b140(int x, int y);
  void f_01b230(SC *buf, int x, int y); short f_01aa30(int x, int y); int f_01aa90(int idx, void *x, void *y);
  void f_01b3b0(int x, int y); void f_01b320(int x, int y, SC *buf); short f_01b100();
  void f_01b1b0(SC *buf, int idx); void f_01b2f0(int idx, SC *buf, int z, int z2); };
struct Sl { int fl; short x, y; unsigned short k; RivaRasterImage *i81; RivaRasterImage *i85; short w89; };
struct AMap {
  signed char id; unsigned long fid; short s5, s7, w9, wb, wd, hf, w11, w13, s15, s17, s19, s1b, s1d;
  short gw1f, gh21; int i23, i27; Grid *g2b; Grid *g2f; void *t33; unsigned char *d37; RivaRasterImage *i3b; unsigned char *d3f; RivaRasterImage *i43;
  char p47[4]; RivaRasterImage *i4b; Strm *s4f; RivaRasterImage *im53[8]; RivaRasterImage *i73; Sl sl[6];
  signed char cnt; signed char cur; short wf1, wf3, wf5, wf7; char pf9[4]; int ifd; int i101; char p105[4]; short s109; int i10b; char p10f[4];
  void f_015d40(int p2); void f_0156f0(); void f_016bc0(); void f_017280();
  void f_014df0(RivaRasterImage *a, RivaRasterImage *b2, int x, int y, int c, int d);
  void f_0176f0(int p2); int f_0177b0(SC *s, int p3); void f_017ad0(SC *s, short n); void f_017b10(SC *s);
  int f_017dc0(); void f_017e00(); void f_017f70(); void f_018090(); void f_0180d0(short p2); void f_018250(); void f_0182a0();
  void f_018360(int p2); void f_018510(); void f_0185c0(); int f_018630(); short f_018720(); void f_018ab0(short *p2);
};
extern short d_1a0468, d_1a01ea; extern volatile unsigned short d_1a0102; extern void *d_1a34e0; extern const char d_1a01ec[];
extern short d_1bc738, d_1bc73a, d_1bc73c, d_1bc73e, d_1bc740, d_1bc742, d_1bc744, d_1bc746, d_1bc748;
extern RivaRasterImage *d_1bc730; extern RivaRasterImage *d_1bc734; extern int d_1bc754; extern Wnd *d_1bfdb8;
extern short d_1bd760; extern unsigned short d_1bd762; extern short d_1bd766;
extern short d_1bf4fa; extern int d_1bf510; extern int d_1c3910; extern SC d_1c21b4[]; extern Txt d_1c38b0; extern Msg d_1c2c64;
extern int d_1bf4f8;
//@ f_0176f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt eine bereits bestehende Knopfleiste (d_1bfdb8) frei und legt sie mit den
 *   Archivgrafiken 0x310005-0x310008 in der zum aktuellen Kartenzustand passenden Knopfbelegung neu an: Variante
 *   0 während der Texteingabe einer Notiz (p2 == 1), 0x20 im Sondermodus (s109 == 2), 0x1b im Zielwahlmodus
 *   (i101 == 1), 0x19 bei eingeblendeten Notizsymbolen (ifd == 1) und 0x1a bei ausgeblendeten Notizsymbolen.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (1 =
 *   Bearbeitungsleiste erzwingen, 0 = nach Zustand wählen) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden der globale Knopfleisten-Zeiger d_1bfdb8, der Bildschirmpuffer d_1a34e0
 *   sowie die Zustandsfelder s109 (+0x109), i101 (+0x101) und ifd (+0xfd).
 === Ende Beschreibung === */
void AMap::f_0176f0(int p2)
{
    if (d_1bfdb8) { delete d_1bfdb8; d_1bfdb8 = 0; }
    short v;
    if (p2 == 1) v = 0;
    else if (s109 == 2) v = 0x20;
    else if (i101 == 1) v = 0x1b;
    else if (ifd == 1) v = 0x19;
    else v = 0x1a;
    d_1bfdb8 = new (mark(d_1a01ec, 0x9ca)) Wnd(0x310006, 0x310007, 0x310005, 0x310008, 4, v);
    d_1bfdb8->f_0daba0(d_1a34e0);
}
//@ f_0177b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird ein Textzeiger s != 0 übergeben, sichert die Funktion beim ersten Einblenden den
 *   Hintergrund (0x70 x 0x77 Pixel bei (0xcc, 0x4e), wo sonst die Übersichtskarte steht) und die Textparameter,
 *   wandelt Zeilenumbrüche in '@' um, gibt den Notiztext im Infofeld aus und stellt bei p3 == 1 zusätzlich die
 *   Bestätigungsfrage 0x31010005; wird s == 0 übergeben, stellt sie den gesicherten Hintergrund wieder her und
 *   gibt das Infofeld für die Übersichtskarte frei.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), den Textpuffer s (signed char *, 0 zum
 *   Ausblenden) und das Rückfrage-Flag p3 (int); sie liefert 1, wenn die Rückfrage 0x31010005 bejaht wurde,
 *   sonst 0.
 * - Wichtige Variablen: d_1a0468 hält den Index der aktuell gewählten Notiz (-1 = keine), d_1a01ea den zuletzt
 *   angezeigten Notizindex, d_1bc754 zeigt an, ob das Infofeld gerade durch einen Notiztext belegt ist (1/0),
 *   und d_1bc730 speichert das gerettete Hintergrundbild.
 === Ende Beschreibung === */
int AMap::f_0177b0(SC *s, int p3)
{
    int r = 0;
    if (s == 0) d_1a0468 = -1;
    if (d_1a0468 == d_1a01ea) {
        return 0;
    }
    if (d_1a01ea != -1 && d_1a0468 == -1) {
        RivaMouseGuard mg;
        d_1c38b0.f_05e2d0(d_1bc73e, d_1bc740, d_1bc742, d_1bc744);
        d_1c38b0.f_05e420(d_1bc73c);
        d_1c38b0.f_05e320(d_1bc738, d_1bc73a);
        d_1bc730->f_0fade0(d_1a34e0, 0xcc, 0x4e);
        delete d_1bc730;
        d_1bc754 = 0;
        d_1a01ea = -1;
    }
    if (d_1a0468 != -1) {
        SC *pc = s;
        while (*pc != 0) {
            unsigned char c = *pc;
            if (c == (unsigned char)'\r' || c == (unsigned char)'\n') *pc = '@';
            pc++;
        }
        RivaMouseGuard mg2;
        if (d_1a01ea == -1) {
            d_1bc730 = new (mark(d_1a01ec, 0xa26)) RivaRasterImage(0x70, 0x77);
            d_1bc730->f_0fafb0(d_1a34e0, 0xcc, 0x4e);
            d_1c38b0.f_05e360(&d_1bc738, &d_1bc73a);
            d_1c38b0.f_05e320(0xff, 0xeb);
            d_1bc73c = d_1c38b0.f_05e420(8);
            d_1c38b0.f_05e2a0(&d_1bc73e, &d_1bc740, &d_1bc742, &d_1bc744);
        }
        d_1c38b0.f_05e2d0(0xcc, 0x70, 0x4e, 0);
        d_1bc734 = new (mark(d_1a01ec, 0xa34)) RivaRasterImage(0x70, 0x77);
        d_1bc734->f_0fb150(0xeb);
        d_1bc734->f_0fade0(d_1a34e0, 0xcc, 0x4e);
        delete d_1bc734;
        d_1bc734 = 0;
        d_1c38b0.f_05e840(0);
        d_1c38b0.f_0e9650(s);
        d_1bc754 = 1;
        d_1a01ea = d_1a0468;
        if (p3 == 1) {
            if (d_1c2c64.f_0bf6f0(0x31010005) == p3) {
                r = 1;
                this->f_0177b0(0, 0);
            }
        }
    }
    d_1a01ea = d_1a0468;
    return r;
}
//@ f_017ad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion geht den Textpuffer s zeilenweise durch, ersetzt jedes Zeilenende ('\r', '\n'
 *   oder '\0') durch einen Zeilenumbruch '\n' und schließt den Puffer nach genau n Zeilen mit einem Nullbyte ab.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), den Textpuffer s (signed char *) und
 *   die Zeilenzahl n (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Bearbeitet wird direkt der übergebene Textpuffer s.
 === Ende Beschreibung === */
void AMap::f_017ad0(SC *s, short n)
{
    SC *p = s;
    short i = 0;
    for (; i < n; i++) {
        while (*(SC *)p != 0 && *p != (SC)'\r' && *p != (SC)'\n') p++;
        *p = '\n';
        p++;
    }
    p--;
    *p = 0;
}
//@ f_017b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion sichert bei Bedarf den Inhalt des Infofelds (0xcc, 0x4e), schaltet die
 *   Knopfleiste über f_0176f0(1) in den Bearbeitungsmodus, öffnet ein 14-zeiliges Texteingabefeld (Dlg, Breite
 *   0x70) zur Eingabe oder Änderung des Notiztextes im Puffer s, normalisiert den eingegebenen Text anschließend
 *   auf 14 Zeilen und stellt Knopfleiste sowie Infofeld-Hintergrund wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den zu bearbeitenden Textpuffer s
 *   (in der Regel d_1c21b4, 0x5f4 Bytes) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc754 (Infofeld-Status), d_1c38b0 (Textausgabe-Zustand), d_1bf510
 *   (Eingabeparameter) und der Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void AMap::f_017b10(SC *s)
{
    extern int f_0d2710_local();
    #pragma aux f_0d2710_local "f_0d2710" modify [esp]
    volatile int fl;
    RivaRasterImage *a, *b;
    short x2;
    if (f_0d3860() == 1) { f_0d2710_local(); fl = 1; } else fl = 0;
    if (d_1bc754 == 0) {
        a = new (mark(d_1a01ec, 0xaa8)) RivaRasterImage(0x70, 0x77);
        { short ra1071 = d_1a01ea; d_1a01ea = ra1071; } // Haelt die Stapelsortierung von a und this wie im Original
        a->f_0fafb0(d_1a34e0, 0xcc, 0x4e);
        RivaRasterImage *t = new (mark(d_1a01ec, 0xaac)) RivaRasterImage(0x70, 0x77);
        t->f_0fb150(0xeb);
        t->f_0fade0(d_1a34e0, 0xcc, 0x4e);
        delete t;
    }
    // 3-Byte-Struktur sorgt dafuer, dass x1 vor den 4-Byte-Zeigern auf dem Stapel liegt
    struct { short value; char pad; } x1;
    short c;
    d_1c38b0.f_05e360(&x1.value, &x2);
    d_1c38b0.f_05e320(0xff, 0xeb);
    c = d_1c38b0.f_05e420(8);
    f_0176f0(1);
    b = new (mark(d_1a01ec, 0xabc)) RivaRasterImage(0x70, 8);
    b = ((unsigned)b & 0) ? (RivaRasterImage *)0 : b; // Trennt das Zeiger-Lebensdauerweb fuer den Original-Spill-Slot [ebp-0x10]
    b->f_0fb150(0xeb);
    if (fl == 1) f_0d26e0();
    Dlg *d = new (mark(d_1a01ec, 0xac1)) Dlg(0xe, 0x70, 0xcc, 0x4e, b, 0, 0);
    if (*(signed char *)s != 0) d->f_0619e0(s);
    d->f_060ae0(s, d_1bf510);
    delete d;
    f_017ad0(s, 0xe);
    delete b;
    f_0176f0(0);
    if (d_1bc754 == 0) {
        volatile int fl2;
        if (f_0d3860() == 1) { f_0d2710(); fl2 = 1; } else fl2 = 0;
        { short rb1071 = d_1a0468; d_1a0468 = rb1071; } // Haelt die Stapelsortierung von a und this wie im Original
        d_1c38b0.f_05e420((short)c);
        d_1c38b0.f_05e320(x1.value, x2);
        a->f_0fade0(d_1a34e0, 0xcc, 0x4e);
        delete a;
        if (fl2 == 1) f_0d26e0();
    }
}
//@ f_017dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist der globale Test-/Schummelschalter d_1c3910 == 1 aktiv und befindet sich die Karte noch im
 *   Normalzustand (s109 == 0), erhöht die Funktion s109 auf 1 und gibt 1 zurück, woraufhin die Hauptschleife in
 *   f_018f00 die gesamte Karte aufdeckt und neu aufbaut.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt 1 zurück, wenn der Sondermodus
 *   eingeschaltet wurde, sonst 0.
 * - Wichtige Variablen: Geprüft und geändert werden der globale Schalter d_1c3910 und das Feld s109 (+0x109).
 === Ende Beschreibung === */
int AMap::f_017dc0()
{
    int r = 0;
    if (d_1c3910 == 1 && s109 == 0) {
        r = 1;
        s109 = s109 + 1;
    }
    return r;
}
//@ f_017e00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Kartencursor (w9, wb) auf die im großen Kartenfenster angeklickte
 *   Stelle (d_1bf4f8/d_1bf4fa zuzüglich Ausschnittversatz s17/s19, begrenzt auf den Kartenrand). Bei einem
 *   Doppelklick (f_0d3800() != 0) wird eine dort vorhandene oder bereits angezeigte Notiz direkt im Editor
 *   (f_017b10 / f_018360(1)) bearbeitet und gespeichert; bei einem einfachen Klick wird eine an der Klickstelle
 *   liegende Notiz im Infofeld angezeigt bzw. das Infofeld geleert und der Kartenausschnitt neu gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Maus-Klickkoordinaten d_1bf4f8/d_1bf4fa, der Kartencursor w9/wb
 *   (+0x09/+0x0b), die Notizverwaltung s4f (+0x4f), der Notizpuffer d_1c21b4 und der Index d_1a0468.
 === Ende Beschreibung === */
void AMap::f_017e00()
{
    short sx = *(volatile short *)&d_1bf4f8 - 3 + s17;
    short sy = *(volatile short *)&d_1bf4fa - 3 + s19;
    if (sx < wd && sy < hf) {
        w9 = sx; wb = sy;
        if (w9 < 1) w9 = 1;
        if (w9 > wd - 2) w9 = wd - 2;
        if (wb < 1) wb = 1;
        if (wb > hf - 2) wb = hf - 2;
        if (f_0d3800()) {
            f_0d37e0();
            if (d_1bc754 != 0) {
                memset(d_1c21b4, 0, 0x5f4);
                s4f->f_01b1b0(d_1c21b4, d_1a0468);
                f_017b10(d_1c21b4);
                s4f->f_01b2f0(d_1a0468, d_1c21b4, 0, 0);
                f_0177b0(0, 0);
            } else {
                f_018360(1);
            }
        } else {
            if (s4f->f_01b140(w9, wb) == 1) {
                s4f->f_01b230(d_1c21b4, w9, wb);
                d_1a0468 = s4f->f_01aa30(w9, wb);
                f_0177b0(d_1c21b4, 0);
            } else f_0177b0(0, 0);
        }
        f_017280();
    }
}
//@ f_017f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Klickt der Spieler in das Feld rechts oben (s1b, s1d, Größe w11 x w13), wird - falls dort
 *   gerade ein Notiztext angezeigt wird (d_1bc754 != 0) - dieser Notiztext im Editor f_017b10 bearbeitet und
 *   gespeichert; ist dort hingegen die Übersichtskarte sichtbar, springt der Kartencursor auf die angeklickte
 *   Position (x * s15, y * s15) und das Hauptkartenfenster wird neu gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden s1b/s1d (+0x1b/+0x1d), w11/w13 (+0x11/+0x13), der Faktor s15 (+0x15),
 *   d_1bc754 und d_1c21b4.
 === Ende Beschreibung === */
void AMap::f_017f70()
{
    short x = d_1bf4f8 - s1b;
    short y = *(volatile short *)&d_1bf4fa - s1d;
    if (x >= 0 && x < w11 && y >= 0 && y < w13) {
        if (d_1bc754 != 0) {
            memset(d_1c21b4, 0, 0x5f4);
            s4f->f_01b1b0(d_1c21b4, d_1a0468);
            f_017b10(d_1c21b4);
            s4f->f_01b2f0(d_1a0468, d_1c21b4, 0, 0);
            f_0177b0(0, 0);
            return;
        }
        w9 = x * s15;
        wb = y * s15;
        if (w9 < 1) w9 = 1;
        if (w9 > wd - 2) w9 = wd - 2;
        if (wb < 1) wb = 1;
        if (wb > hf - 2) wb = hf - 2;
        f_017280();
    }
}
//@ f_018090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Kartencursor (w9, wb) auf die aktuellen Kartenpixel-Koordinaten der
 *   Spielergruppe (s5, s7) zurück und gibt den Kartenausschnitt über f_017280 neu aus (wird u. a. durch die
 *   Taste Pos1 ausgelöst).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Kopiert werden s5/s7 (+0x05/+0x07) nach w9/wb (+0x09/+0x0b).
 === Ende Beschreibung === */
void AMap::f_018090()
{
    w9 = s5;
    wb = s7;
    f_017280();
}
//@ f_0180d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion verschiebt den Kartencursor (w9, wb) entsprechend dem Richtungsbefehl p2 (4 =
 *   hoch, 5 = runter, 6 = links, 7 = rechts) um 1 Pixel oder - bei gedrückter Umschalttaste (d_1bd760 != 0) - um
 *   10 Pixel. Wird gerade eine Notiz im Infofeld angezeigt (d_1bc754 != 0), bleibt der Cursor auf den sichtbaren
 *   194x194-Ausschnitt begrenzt, andernfalls kann er über die gesamte Karte bewegt werden und verschiebt bei
 *   Bedarf den Ausschnitt über f_017280.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den Richtungsbefehl p2 (short) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden w9/wb (+0x09/+0x0b), die Schrittweiten-Umschaltung d_1bd760 und das
 *   Infofeld-Flag d_1bc754.
 === Ende Beschreibung === */
void AMap::f_0180d0(short p2)
{
    int ok = 1;
    short step;
    step = d_1bd760 ? 10 : 1;
    if (d_1bc754 != 0) {
        short v4 = s17 + 1;
        short v5 = s19 + 1;
        short v6 = s17 + 0xc0;
        short v2 = s19 + 0xc0;
        switch (p2) {
        case 6: w9 -= step; break;
        case 7: w9 += step; break;
        case 4: wb -= step; break;
        case 5: wb += step; break;
        default: ok = 0;
        }
        if (w9 > v6) w9 = v6;
        else if (w9 < v4) w9 = v4;
        if (wb > v2) wb = v2;
        else if (wb < v5) wb = v5;
    } else {
        switch (p2) {
        case 6: w9 -= step; if (w9 < 1) w9 = 1; break;
        case 7: w9 += step; if (w9 >= wd - 1) w9 = wd - 2; break;
        case 4: wb -= step; if (wb < 1) wb = 1; break;
        case 5: wb += step; if (wb >= hf - 1) wb = hf - 2; break;
        default: ok = 0;
        }
    }
    if (ok == 1) f_017280();
}
//@ f_018250
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt das Anzeigeflag für Notizsymbole auf 0 (ifd = 0, Taste '-'), baut das
 *   Kartenbild über f_016bc0 ohne Stecknadeln neu auf, falls Notizen auf der Karte existieren, und aktualisiert
 *   Knopfleiste sowie Kartenausschnitt.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird das Feld ifd (+0xfd, Notizsymbole sichtbar).
 === Ende Beschreibung === */
void AMap::f_018250()
{
    short qa, qb;
    ifd = 0;
    if (s4f->f_01b060(&qa, &qb) == 1) f_016bc0();
    f_0176f0(0);
    f_017280();
}
//@ f_0182a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schaltet die Anzeige der Notizsymbole ein (ifd = 1, Taste '+'), nimmt die
 *   Gruppenmarker kurzzeitig vom Kartenbild herunter, zeichnet alle Notiz-Stecknadeln (i4b) ein, setzt die
 *   Gruppenmarker über f_0156f0 wieder darüber und erneuert Knopfleiste sowie Kartenausschnitt.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert wird ifd (+0xfd), genutzt werden s4f (+0x4f), i4b (+0x4b) und i3b (+0x3b).
 === Ende Beschreibung === */
void AMap::f_0182a0()
{
    short qa, qb;
    void f_0156f0_x(AMap *);
    #pragma aux f_0156f0_x "f_0156f0" parm [eax] modify [esp];
    AMap *self = this;
    AMap *live = this;
    ifd = 1;
    for (short i = 0; i < live->cnt; i++)
        live->f_014df0(live->i3b, live->sl[i].i85, live->sl[i].x, live->sl[i].y, 0, -1);
    AMap *p = live;
    live->f_015d40(1);
    if (p->s4f->f_01b060(&qa, &qb) == 1) {
        do {
            p->i3b->f_0fb3a0(p->i4b, qa, qb, 1);
        } while (p->s4f->f_01b0a0(&qa, &qb) == 1);
    }
    f_0156f0_x(live);
    self->f_0176f0(0);
    self->f_017280();
}
//@ f_018360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liegt der Kartencursor (w9, wb) außerhalb des 8 Pixel breiten rechten/unteren Kartenrands,
 *   prüft die Funktion, ob dort bereits eine Notiz existiert: falls ja, wird deren Text geladen und im Editor
 *   f_017b10 bearbeitet; falls nein und p2 == 0 (Aufruf über Enter/Einfg statt Doppelklick), wird bei mindestens
 *   5 freien Notizplätzen (s4f->f_01b100() >= 5) eine neue Notiz eingegeben, unter (w9, wb) gespeichert
 *   (f_01b320) und als Stecknadelsymbol in die Karte gezeichnet (bei weniger als 5 freien Plätzen erscheint die
 *   Meldung 0x31010001).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Modusflag p2 (1 = nur
 *   bestehende Notiz bearbeiten, 0 = auch Neuanlage erlauben) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden w9/wb (Cursor), s4f (+0x4f, Notizverwaltung), der Textpuffer d_1c21b4
 *   (0x5f4 Bytes) und das Meldungsobjekt d_1c2c64.
 === Ende Beschreibung === */
void AMap::f_018360(int p2)
{
    void f_0156f0_x(AMap *);
    #pragma aux f_0156f0_x "f_0156f0" parm [eax] modify [esp];
    struct Calls1030 {
        static void fill(SC *buf, int zero, unsigned n, AMap *py, AMap *slot) {
            memset(buf, zero, n);
            AMap *px = slot;
            AMap *ps = slot;
            ps->s4f->f_01b230(buf, px->w9, py->wb);
        }
        static void edit(AMap *pe, AMap *py, SC *buf, AMap *slot) {
            pe->f_017b10(buf);
            AMap *px = slot;
            AMap *ps = slot;
            ps->s4f->f_01b320(px->w9, py->wb, buf);
        }
    };
    int height;
    short rt1052_0;
    short rt1052_1;
    short rt1052_2;
    short rt1052_3;
    short rt1052_4;
    short rt1052_5;
    short rt1052_6;
    short rt1052_7;
    short rt1052_8;
    short rt1052_9;
    short rt1052_10;
    short rt1052_11;
    short rt1052_12;
    short rt1052_13;
    short rt1052_14;
    short rt1052_15;
    short rt1052_16;
    short rt1052_17;
    short rt1052_18;
    short rt1052_19;
    short rt1052_20;
    short rt1052_21;
    short rt1052_22;
    short rt1052_23;
    short rt1052_24;
    short rt1052_25;
    short rt1052_26;
    short rt1052_27;
    short rt1052_28;
    short rt1052_29;
    short rt1052_30;
    short rt1052_31;
    volatile int arg = p2;
    int ok = 1;
    int fl = 0;
    int h = 0;
    int y;
    short qb, qa;
    // Haelt die interne Symbol- und Stapelplatzsortierung wie im Gesamtmodul amap.cpp
    rt1052_5 = ((short *)d_1c21b4)[5];
    ((short *)d_1c21b4)[5] = rt1052_5;
    rt1052_6 = ((short *)d_1c21b4)[6];
    ((short *)d_1c21b4)[6] = rt1052_6;
    rt1052_7 = ((short *)d_1c21b4)[7];
    ((short *)d_1c21b4)[7] = rt1052_7;
    rt1052_8 = ((short *)d_1c21b4)[8];
    ((short *)d_1c21b4)[8] = rt1052_8;
    rt1052_9 = ((short *)d_1c21b4)[9];
    ((short *)d_1c21b4)[9] = rt1052_9;
    rt1052_10 = ((short *)d_1c21b4)[10];
    ((short *)d_1c21b4)[10] = rt1052_10;
    rt1052_11 = ((short *)d_1c21b4)[11];
    ((short *)d_1c21b4)[11] = rt1052_11;
    rt1052_12 = ((short *)d_1c21b4)[12];
    ((short *)d_1c21b4)[12] = rt1052_12;
    rt1052_13 = ((short *)d_1c21b4)[13];
    ((short *)d_1c21b4)[13] = rt1052_13;
    rt1052_14 = ((short *)d_1c21b4)[14];
    ((short *)d_1c21b4)[14] = rt1052_14;
    rt1052_15 = ((short *)d_1c21b4)[15];
    ((short *)d_1c21b4)[15] = rt1052_15;
    rt1052_16 = ((short *)d_1c21b4)[16];
    ((short *)d_1c21b4)[16] = rt1052_16;
    rt1052_19 = ((short *)d_1c21b4)[19];
    ((short *)d_1c21b4)[19] = rt1052_19;
    rt1052_20 = ((short *)d_1c21b4)[20];
    ((short *)d_1c21b4)[20] = rt1052_20;
    rt1052_21 = ((short *)d_1c21b4)[21];
    ((short *)d_1c21b4)[21] = rt1052_21;
    rt1052_23 = ((short *)d_1c21b4)[23];
    ((short *)d_1c21b4)[23] = rt1052_23;
    rt1052_24 = ((short *)d_1c21b4)[24];
    ((short *)d_1c21b4)[24] = rt1052_24;
    rt1052_25 = ((short *)d_1c21b4)[25];
    ((short *)d_1c21b4)[25] = rt1052_25;
    rt1052_26 = ((short *)d_1c21b4)[26];
    ((short *)d_1c21b4)[26] = rt1052_26;
    rt1052_27 = ((short *)d_1c21b4)[27];
    ((short *)d_1c21b4)[27] = rt1052_27;
    rt1052_28 = ((short *)d_1c21b4)[28];
    ((short *)d_1c21b4)[28] = rt1052_28;
    rt1052_29 = ((short *)d_1c21b4)[29];
    ((short *)d_1c21b4)[29] = rt1052_29;
    rt1052_30 = ((short *)d_1c21b4)[30];
    ((short *)d_1c21b4)[30] = rt1052_30;
    rt1052_31 = ((short *)d_1c21b4)[31];
    ((short *)d_1c21b4)[31] = rt1052_31;
    int x = w9;
    if (x + 8 < wd) {
        int hh = this->hf;
        AMap *yp = ((int)this & 0) ? 0 : this; // Haelt das Zeiger-Lebensdauerweb vor height fuer die Original-Registerzuteilung
        *(int *)&height = hh;
        if (yp) { int rt1052h = yp->i23; yp->i23 = rt1052h; }
        y = yp->wb;
        h = height;
        int sum = y + 8;
        if (sum < h) {
        if (this->s4f->f_01b140(x, y) == ok) {
                Calls1030::fill(d_1c21b4, 0, 0x5f4, this, this);
            } else {
                if (arg == ok) return;
                memset(d_1c21b4, 0, 0x5f4);
                if (5 > this->s4f->f_01b100()) ok = 0;
                fl = 1;
            }
            if (ok == 1) {
                Calls1030::edit(this, this, d_1c21b4, this);
                if (fl == ok) {
                    AMap *live = ((int)this & 0) ? 0 : this; // Trennt das Schleifenweb vom this-Web wie beim Inline-Einsetzen von f_016850
                    for (short i = 0; i < live->cnt; i++)
                        live->f_014df0(live->i3b, live->sl[i].i85, live->sl[i].x, live->sl[i].y, 0, -1);
                    live->f_015d40(1);
                    AMap *cursor = live;
                    if (cursor->s4f->f_01b060(&qa, &qb) == 1) do {
                        cursor->i3b->f_0fb3a0(cursor->i4b, qa, qb, 1);
                    } while (cursor->s4f->f_01b0a0(&qa, &qb) == 1);
                    f_0156f0_x(live);
                    this->f_017280();
                }
            } else {
                d_1c2c64.f_0bf730(0x31010001);
        }
        }
    }
}
#pragma inline_depth(3)
//@ f_018510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion ermittelt die Koordinaten (x, y) der aktuell im Infofeld angezeigten Notiz
 *   (d_1a0468 != -1) bzw. der Notiz unter dem Kartencursor (w9, wb). Nach Bestätigung der Sicherheitsabfrage
 *   0x31010005 (Entf-Taste) schließt sie das Infofeld, löscht die Notiz über f_01b3b0 (am01b3b0) aus der
 *   Notizdatei und baut das Kartenbild ohne die gelöschte Stecknadel neu auf.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1a0468 (gewählter Notizindex), s4f (+0x4f) und d_1c2c64 (Rückfrage
 *   0x31010005).
 === Ende Beschreibung === */
void AMap::f_018510()
{
    int ok = 0;
    unsigned short x, y;
    if (d_1a0468 != -1) {
        int t_353 = s4f->f_01aa90(d_1a0468, &x, &y);
        if (t_353 == (unsigned short)1) ok = 1;
    } else {
        if (s4f->f_01b140(w9, wb) == 1) {
            x = (unsigned short)w9;
            y = (unsigned short)wb;
            ok = 1;
        }
    }
    if (ok == 1) {
        if (d_1c2c64.f_0bf6f0(0x31010005) == 1) {
            f_0177b0(0, 0);
            s4f->f_01b3b0((short)x, (short)y);
            f_016bc0();
            f_017280();
        }
    }
}
//@ f_0185c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Befindet sich an der Kartencursor-Position (w9, wb) eine Notiz (f_01b140 == 1), liest die
 *   Funktion deren Text in den Puffer d_1c21b4, merkt ihren Index in d_1a0468 und zeigt sie über f_0177b0 im
 *   Infofeld rechts oben an; steht dort keine Notiz, wird das Infofeld geleert.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden w9/wb (+0x09/+0x0b), s4f (+0x4f), d_1c21b4 und d_1a0468.
 === Ende Beschreibung === */
void AMap::f_0185c0()
{
    if (s4f->f_01b140(w9, wb) == 1) {
        s4f->f_01b230(d_1c21b4, w9, wb);
        d_1a0468 = s4f->f_01aa30(w9, wb);
        f_0177b0(d_1c21b4, 0);
    } else f_0177b0(0, 0);
}
//@ f_018630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Im Zielwahlmodus (i101 == 1) prüft die Funktion die Rasterzelle (w9 / 3, wb / 3) unter dem
 *   Kartencursor: die Zelle muss überhaupt erkundet sein (g2b != 0, sonst Meldung 0x31010002), begehbares
 *   Gelände besitzen (g2f == 1, sonst Meldung 0x31010003) und von der Gruppe selbst gesehen worden sein (g2b &
 *   1, sonst Meldung 0x31010004). Sind alle drei Bedingungen erfüllt, setzt sie i10b = 1 und gibt 1 zurück, um
 *   den Kartenbildschirm mit gültigem Ziel zu beenden.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert 1 bei gültigem Ziel, sonst
 *   0.
 * - Wichtige Variablen: Geprüft werden g2b (+0x2b, Erkundung) und g2f (+0x2f, Gelände); das Ergebnis landet in
 *   i10b (+0x10b).
 === Ende Beschreibung === */
int AMap::f_018630()
{
    int result = 0;
    i10b = 0;
    int t = g2b->f_04fd60((unsigned short)(w9 / 3), (unsigned short)(wb / 3));
    int msg;
    if (t != 0) {
        if (g2f->f_04fd60((unsigned short)(w9 / 3), (unsigned short)(wb / 3)) == 1) {
            if ((t & 1) != 0) {
                i10b = 1;
                result = i10b;
            } else {
                msg = 0x31010004;
                d_1c2c64.f_0bf730(msg);
            }
        } else {
            msg = 0x31010003;
            d_1c2c64.f_0bf730(msg);
        }
    } else {
        msg = 0x31010002;
        d_1c2c64.f_0bf730(msg);
    }
    return result;
}
//@ f_018720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion wertet den aktuellen Tastencode d_1bd762 aus und setzt ihn in einen internen
 *   Automap-Befehl um (Esc -> 9 Schließen, '-' -> 0xa9 Notizen aus, '+' -> 0xac Notizen an, Leertaste -> 0xae
 *   Notiz zeigen, Enter/Einfg -> 0xaa Notiz bearbeiten, Entf -> 0xab Notiz löschen, Pos1 -> 3 Cursor auf Gruppe,
 *   0x5500 -> 8 Sondermodus, Pfeiltasten -> 4..7 mit Tastenwiederholung über die Richtungsbits in d_1a0102) und
 *   filtert Befehle heraus, die im aktuellen Modus unzulässig sind.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt den ermittelten Befehlscode
 *   (short, 0 = kein Befehl) zurück.
 * - Wichtige Variablen: Genutzt werden d_1bd762 (BIOS-Tastencode), d_1a0102 (gehaltene Richtungsbits) sowie die
 *   Wiederholungsspeicher d_1bc746 und d_1bc748.
 === Ende Beschreibung === */
short AMap::f_018720()
{
    short r = 0;
    switch (d_1bd762) {
    case 0: break;
    case 0x11b: r = 9; d_1bc746 = 0; break;
    case 0x352d: r = 0xa9; d_1bc746 = 0; break;
    case 0x1b2b: r = 0xac; d_1bc746 = 0; break;
    case 0x3920: r = 0xae; d_1bc746 = 0; break;
    case 0x1c0d: case 0x5200: r = 0xaa; d_1bc746 = 0; break;
    case 0x5300: r = 0xab; d_1bc746 = 0; break;
    case 0x4700: r = 3; d_1bc746 = 0; break;
    case 0x5500: r = 8; d_1bc746 = 0; break;
    case 0x4800: r = 4; if ((short)d_1bc746 != (short)r) d_1bc746 = 0; if ((short)r == (short)d_1bc748) d_1bc746 = d_1bc748; break;
    case 0x5000: r = 5; if ((short)d_1bc746 != (short)r) d_1bc746 = 0; if ((short)r == (short)d_1bc748) d_1bc746 = d_1bc748; break;
    case 0x4b00: r = 6; if ((short)d_1bc746 != (short)r) d_1bc746 = 0; if ((short)r == (short)d_1bc748) d_1bc746 = d_1bc748; break;
    case 0x4d00: r = 7; if ((short)d_1bc746 != (short)r) d_1bc746 = 0; if ((short)r == (short)d_1bc748) d_1bc746 = r; break;
    default: d_1bc746 = 0; break;
    }
    if ((short)r != (short)0) d_1bc748 = r;
    unsigned short bits = d_1a0102; switch ((unsigned short)d_1bc748) {
    case 4: if ((bits & 1) == 0) d_1bc748 = 0; break;
    case 5: if ((bits & 2) == 0) d_1bc748 = 0; break;
    case 6: if ((bits & 4) == 0) d_1bc748 = 0; break;
    case 7: if ((bits & 8) == 0) d_1bc748 = 0; break;
    }
    switch ((unsigned short)d_1bc746) {
    case 4: if ((bits & 1) == 0) d_1bc746 = 0; break;
    case 5: if ((bits & 2) == 0) d_1bc746 = 0; break;
    case 6: if ((bits & 4) == 0) d_1bc746 = 0; break;
    case 7: if ((bits & 8) == 0) d_1bc746 = 0; break;
    }
    if ((short)d_1bc746 != (short)0) r = d_1bc746;
    else {
        switch ((unsigned short)r) {
        case 0xa9: if (s109 == 2 || i101 == 1 || ifd == 0) r = 0; break;
        case 0xac: if (s109 == 2 || i101 == 1 || ifd == 1) r = 0; break;
        case 0xaa:
            if (ifd == 0) r = 0;
            else if (s109 == 2 || i101 == 1) r = 0xae;
            break;
        case 0xab: if (s109 == 2 || i101 == 1 || ifd == 0) r = 0; break;
        }
    }
    return r;
}
//@ f_018ab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist noch kein Tastaturbefehl gesetzt (*p2 == 0), übernimmt die Funktion den allgemeinen
 *   UI-Eingabecode d_1bd766 und verwirft anschließend Codes im Bereich 0x81..0x84 sowie 0x4900 (Bild auf).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und einen Zeiger p2 (short *) auf den
 *   Befehlscode, den sie direkt anpasst; sie hat keinen Rückgabewert.
 * - Wichtige Variablen: Gelesen wird die globale Eingabevariable d_1bd766.
 === Ende Beschreibung === */
void AMap::f_018ab0(short *p2)
{
    if (*p2 == 0) *p2 = d_1bd766;
    if ((*p2 >= 0x81 && *p2 <= 0x84) || *p2 == 0x4900) *p2 = 0;
}

struct AMap4_493;
struct ContextAMap4 { public:
// amap.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x018AF0-0x019C90
struct Grid {
    char b[10];
    Grid(unsigned short w, unsigned short h, int z); ~Grid();
    void *f_04fd30(); int f_04fd40();
    unsigned f_04fd60(unsigned short x, unsigned short y);
    void f_04fdb0(unsigned short x, unsigned short y, unsigned v);
};
struct RivaRasterImage {
    char b[9];
    RivaRasterImage(short w, short h); RivaRasterImage(short w, short h, unsigned char *d); ~RivaRasterImage();
    void f_0fb3a0(RivaRasterImage *src, int x, int y, int f);
};
struct Strm {
    char b[14]; Strm(unsigned long id); ~Strm();
    int f_01b060(short *x, short *y);
    int f_01b0a0(short *x, short *y);
    int f_01b140(int x, int y);
    void f_01b230(void *buf, int x, int y);
    short f_01aa30(int x, int y);
};
struct Pak {
    char b[164];
    Pak(); ~Pak();
    void f_145a10(unsigned long id, void *buf);
    void *f_145b10();
};
struct File {
    void  f_1448b0(unsigned long id, int mode);
    void  f_144920(void *buf, int n);
    void  f_1449a0();
};
struct Pr { signed char a; signed char b; };
struct Iter {
    char b[8];
    Iter(long x); ~Iter();
    void f_01b890(int id); Pr *f_01ba50(); Pr *f_01bb60();
};
struct Cur { char b[4]; ~Cur(); short f_0dacc0(); };
struct Lk { short saved; Lk(); ~Lk(); };
struct Rect { short x, y, w, h; };
struct P8 { int a; int b; };
struct Dxy { unsigned short dx, dy; };
struct Pt { unsigned short x, y; };
struct Hdr12 { char b[12]; unsigned n; };
typedef AMap4_493 AMap;
struct Sl {
    int fl; short x; short y; unsigned short k; RivaRasterImage *i81; RivaRasterImage *i85; short w89;
};
static int f_014cc0(AMap *a);
static int f_014df0(AMap *a, RivaRasterImage *src, RivaRasterImage *dst, int x, int y, int z, int w);
static int f_0d3810();    static void f_0d3870();
static int f_0d3390(int x, int y, int w, int h);
static void f_0ce650(); static void f_060a10(int n);
static signed char f_01a730();

};
extern ContextAMap4::File amap4_d_1c2098;
extern const char amap4_d_1a01ec[];
extern void *amap4_d_1a34e0;
extern ContextAMap4::Dxy amap4_d_1a020c[];
extern ContextAMap4::P8 amap4_d_1a0388[];
extern int amap4_d_1a0388i[];
extern ContextAMap4::Rect amap4_d_1a032c;
extern ContextAMap4::Rect *amap4_d_1bf510;
extern volatile short amap4_d_1bf51c;
extern short amap4_d_1bf4f0;
extern short amap4_d_1bf4f2;
extern short amap4_d_1bd766;
extern short amap4_d_1a0468;
extern short amap4_d_1c2198;
extern int amap4_d_1c0c4c;
extern int amap4_d_1c0c94;
extern int amap4_d_1c2a80;
extern int amap4_d_1c3910;
extern ContextAMap4::Cur *amap4_d_1bfdb8;
extern char *amap4_d_1a9664;
extern char amap4_d_1c21b4[];

#pragma aux amap4_d_1c2098 "d_1c2098"
#pragma aux amap4_d_1a01ec "d_1a01ec"
#pragma aux amap4_d_1a34e0 "d_1a34e0"
#pragma aux amap4_d_1a020c "d_1a020c"
#pragma aux amap4_d_1a0388 "d_1a0388"
#pragma aux amap4_d_1a0388i "d_1a0388"
#pragma aux amap4_d_1a032c "d_1a032c"
#pragma aux amap4_d_1bf510 "d_1bf510"
#pragma aux amap4_d_1bf51c "d_1bf51c"
#pragma aux amap4_d_1bf4f0 "d_1bf4f0"
#pragma aux amap4_d_1bf4f2 "d_1bf4f2"
#pragma aux amap4_d_1bd766 "d_1bd766"
#pragma aux amap4_d_1a0468 "d_1a0468"
#pragma aux amap4_d_1c2198 "d_1c2198"
#pragma aux amap4_d_1c0c4c "d_1c0c4c"
#pragma aux amap4_d_1c0c94 "d_1c0c94"
#pragma aux amap4_d_1c2a80 "d_1c2a80"
#pragma aux amap4_d_1c3910 "d_1c3910"
#pragma aux amap4_d_1bfdb8 "d_1bfdb8"
#pragma aux amap4_d_1a9664 "d_1a9664"
#pragma aux amap4_d_1c21b4 "d_1c21b4"
struct AMap4_493 {
    signed char id;
    unsigned long fid;
    short s5, s7, s9, sb, w0d, h0f, w11, h13, s15;
    short s17, s19, s1b, s1d;
    short gw1f, gh21;
    int i23, i27;
    ContextAMap4::Grid *g2b; ContextAMap4::Grid *g2f;
    unsigned char *t33;
    unsigned char *d37; ContextAMap4::RivaRasterImage *i3b; unsigned char *d3f; ContextAMap4::RivaRasterImage *i43;
    ContextAMap4::RivaRasterImage *i47;
    ContextAMap4::RivaRasterImage *i4b; ContextAMap4::Strm *s4f;
    ContextAMap4::RivaRasterImage *im53[8];
    ContextAMap4::RivaRasterImage *i73;
    ContextAMap4::Sl sl[6];
    signed char cnt; signed char cur;
    short wf1, wf3, wf5, wf7;
    int i0f9;
    int fd;
    int i101;
    int i105;
    short s109;
    int i10b;
    int i10f;
    ContextAMap4::Pt pts[11];
    char c13f;
    short s140;
    short s142;
    int i144;
    void f_015190(); void f_015280(); void f_0156f0();
    void f_015af0(int p2); void f_015d40(int p2);
    void f_015e30(ContextAMap4::Pr *p2);
    void f_0161d0(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
    void f_016580(int p2); void f_016bc0(); void f_0176f0(int p2); void f_017280();
    void f_0177b0(void *p2, int p3); void f_017e00(); void f_017f70(); void f_0180d0(int p2);
    void f_018360(int p2); void f_018510(); int f_018630(); short f_018720();
    int f_018af0(); void f_018f00(); void f_019460(); AMap4_493 *f_019620(int fl);
    void f_019800(signed char cid, int px, int py); void f_019b30(int v); void f_019b40(int px, int py);
    // --- vor 0x018AF0 liegende Funktionen (inline-Kopien fuer das Einsetzen durch den Compiler) ---
    void f_015040()
    {
        g2b = new (mark(amap4_d_1a01ec, 0x235)) ContextAMap4::Grid(gw1f, gh21, 0);
        amap4_d_1c2098.f_1448b0(fid + 6 | 0x40000000, 0x200);
        ContextAMap4::Hdr12 h;
        amap4_d_1c2098.f_144920(&h, 0x10);
        if (h.n > 0) {
            amap4_d_1c2098.f_144920(g2b->f_04fd30(), g2b->f_04fd40());
        }
        amap4_d_1c2098.f_1449a0();
    }
    void f_0150f0()
    {
        g2f = new (mark(amap4_d_1a01ec, 0x26e)) ContextAMap4::Grid(gw1f, gh21, 0);
        amap4_d_1c2098.f_1448b0(fid + 2, 0x200);
        char h[16];
        amap4_d_1c2098.f_144920(h, 0x10);
        amap4_d_1c2098.f_144920(g2f->f_04fd30(), g2f->f_04fd40());
        amap4_d_1c2098.f_1449a0();
    }
    void f_015c00(int p2)
    {
        if (p2 != 1) return;
        delete i3b;
        i3b = 0;
        delete d37;
        d37 = 0;
    }
    void f_015c40(int p2)
    {
        if (p2 != 1) return;
        delete i43;
        i43 = 0;
        delete d3f;
        d3f = 0;
    }
    void f_015c80(int p2)
    {
        if (p2 == 1) {
            delete s4f;
            delete i4b;
            s4f = 0;
            i4b = 0;
            if (s109 == 2) amap4_d_1a9664 = 0;
        }
    }
    void f_015ce0(int p2)
    {
        if (p2 == 1) {
            delete i73;
            i73 = 0;
            for (short i = 0; i < 8; i++) {
                delete im53[i];
                im53[i] = 0;
            }
        }
    }
    void f_016300(unsigned short x, unsigned short y)
    {
        if (0 <= x && x < gw1f && 0 <= y && y < gh21) {
            g2b->f_04fdb0(x, y, g2b->f_04fd60(x, y) | 1);
        }
        for (short i = 0; i < 0x48; i++) f_0161d0(x, y, x + amap4_d_1a020c[i].dx, y + amap4_d_1a020c[i].dy);
    }
    void f_0182a0()
    {
        fd = 1;
        f_016850();
        f_0176f0(0);
        f_017280();
    }
    void f_016850()
    {
        for (short i = 0; i < cnt; i++) {
            ContextAMap4::f_014df0(this, i3b, sl[i].i85, sl[i].x, sl[i].y, 0, -1);
        }
        f_015d40(1);
        short x, y;
        int r = s4f->f_01b060(&x, &y);
        while (r == 1) {
            i3b->f_0fb3a0(i4b, x, y, 1);
            r = s4f->f_01b0a0(&x, &y);
        }
        f_0156f0();
    }
};


//@ f_018af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion führt einen Schritt der interaktiven Kartenschleife aus: sie holt einen
 *   Tastaturbefehl (f_018720), wertet ohne Tastendruck die Mausposition über dem Kartenfenster (zeigt
 *   automatisch die Notiz unter dem Mauszeiger an oder reagiert auf Klicks in Karte/Übersicht) bzw. die
 *   Knopfleiste (d_1bfdb8) aus und verzweigt anschließend in die jeweilige Aktion (Schließen bei 9/0x80, Klicks
 *   1/2, Gruppe zentrieren 3, Sondermodus 8, Notizbefehle 0xa9..0xae, Zielprüfung 0xad oder Cursorbewegung
 *   f_0180d0).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert 1, wenn der
 *   Kartenbildschirm beendet werden soll, sonst 0.
 * - Wichtige Variablen: Genutzt werden d_1bfdb8 (Knopfleiste), d_1bf4f0/d_1bf4f2 (Mausposition), d_1a032c
 *   (Rechteck des Kartenfensters) und die Methoden des AMap-Objekts.
 === Ende Beschreibung === */
struct Help18af0 {
    static inline void f_018090(AMap4_493 *self)
    {
        self->s9 = self->s5;
        self->sb = self->s7;
        self->f_017280();
    }
    static inline int f_017dc0(AMap4_493 *self)
    {
        int r = 0;
        if (amap4_d_1c3910 == 1 && self->s109 == 0) {
            r = 1;
            self->s109 = self->s109 + 1;
        }
        return r;
    }
    static inline void f_0185c0(AMap4_493 *self)
    {
        if (self->s4f->f_01b140(self->s9, self->sb) == 1) {
            self->s4f->f_01b230(amap4_d_1c21b4, self->s9, self->sb);
            amap4_d_1a0468 = self->s4f->f_01aa30(self->s9, self->sb);
            self->f_0177b0(amap4_d_1c21b4, 0);
        } else {
            self->f_0177b0(0, 0);
        }
    }
};
int AMap4_493::f_018af0()
{
    int r = 0;
    struct { short w; char pad; } key;
    key.w = 0;
    key.w = f_018720();
    if (key.w == 0) key.w = amap4_d_1bd766;
    if ((key.w >= 0x81 && key.w <= 0x84) || key.w == 0x4900) key.w = 0;
    if (key.w == 0) {
        if (ContextAMap4::f_0d3810() && ContextAMap4::f_0d3390(amap4_d_1a032c.x, amap4_d_1a032c.y, amap4_d_1a032c.w, amap4_d_1a032c.h)) {
            short sx = *(volatile short *)&amap4_d_1bf4f0 - 3 + s17;
            short sy = *(volatile short *)&amap4_d_1bf4f2 - 3 + s19;
            { short u_ = sy; sy = u_; } { short u_ = sy; sy = u_; } // Haelt die Stapelsortierung von sy wie im Original
            if (s4f->f_01b140(sx, sy) == 1) {
                s4f->f_01b230(amap4_d_1c21b4, sx, sy);
                amap4_d_1a0468 = s4f->f_01aa30(sx, sy);
                f_0177b0(amap4_d_1c21b4, 0);
            } else {
                f_0177b0(0, 0);
            }
        } else if (amap4_d_1bfdb8) {
            key.w = amap4_d_1bfdb8->f_0dacc0();
        }
    }
    switch (key.w) {
    case 9:
    case 0x80:
        r = 1;
        break;
    case 1:
        f_017e00();
        break;
    case 2:
        f_017f70();
        break;
    case 3:
        Help18af0::f_018090(this);
        break;
    case 8:
        r = Help18af0::f_017dc0(this);
        break;
    case 0xa9: {
        AMap4_493 *self = this;
        short qa, qb;
        self->fd = 0;
        if (self->s4f->f_01b060(&qa, &qb) == 1) self->f_016bc0();
        self->f_0176f0(0);
        self->f_017280();
        break;
    }
    case 0xaa:
        f_018360(0);
        break;
    case 0xab:
        f_018510();
        break;
    case 0xac: {
        short qb, qa;
        void f_0156f0_x(AMap *);
        AMap4_493 *self = ((int)this & 0) ? 0 : this; // Trennt das Schleifenweb vom this-Web wie beim Inline-Einsetzen von f_0182a0/f_016850
        fd = 1;
        for (short i = 0; i < cnt; i++)
            ContextAMap4::f_014df0(this, i3b, sl[i].i85, sl[i].x, sl[i].y, 0, -1);
        AMap4_493 *p = this;
        f_015d40(1);
        if (p->s4f->f_01b060(&qa, &qb) == 1) {
            do {
                p->i3b->f_0fb3a0(p->i4b, qa, qb, 1);
            } while (p->s4f->f_01b0a0(&qa, &qb) == 1);
        }
        f_0156f0_x((AMap *)this);
        self->f_0176f0(0);
        self->f_017280();
        break;
    }
    case 0xad:
        r = f_018630();
        break;
    case 0xae:
        Help18af0::f_0185c0(this);
        break;
    default:
        f_0180d0(key.w);
        break;
    }
    { int u_ = r; r = u_; } // Haelt die Stapelsortierung von r wie im Original
    return r;
}


//@ f_018f00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet und betreibt den gesamten Automap-Bildschirm (Gegenstück zum äußeren
 *   Ablauf von OVL046.CPP:automap_view in *Sternenschweif*): sie hält die Spieluhr an, lädt das Hintergrundbild
 *   0x310000, richtet das 194x194-Kartenfenster (i47), die Notizverwaltung (f_015450), die Gruppensymbole
 *   (f_0155e0) und die Knopfleiste (f_0176f0) ein, baut die Karte über f_016bc0 auf und arbeitet in einer
 *   Schleife f_018af0() ab, bis der Spieler die Karte schließt (oder in den Sondermodus s109 umschaltet); beim
 *   Verlassen gibt sie alle temporären Grafik- und Notizpuffer wieder frei und fordert über d_1c2198 = 1 einen
 *   Neuaufbau des Hauptbildschirms an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesichert und restauriert werden die Uhr-/Sperrvariablen d_1c2a80, d_1c0c94 und
 *   d_1c0c4c, das Mausbegrenzungsrechteck d_1bf510 sowie die Puffer des Kartenobjekts (i47, s4f, i3b, i43).
 === Ende Beschreibung === */
void AMap4_493::f_018f00()
{
    ContextAMap4::Iter it(-1);
    int save94;
    save94 = amap4_d_1c0c94;
    ContextAMap4::f_0ce650();
    ContextAMap4::f_060a10(2500000);
    *(volatile int *)&amap4_d_1c2a80 = 0;
    *(volatile int *)&amap4_d_1c0c94 = 0;
    ++amap4_d_1c0c4c;
    {
        ContextAMap4::Pak pk;
        volatile int active;
        int a = ::f_0d3860();
        if (a == 1) {
            ::f_0d2710();
            active = 1;
        } else {
            active = 0;
        }
        pk.f_145a10(0x310000, amap4_d_1a34e0);
        pk.f_145b10();
        if (active == 1) ::f_0d26e0();
    }
    this->i47 = new (mark(amap4_d_1a01ec, 0xe54)) ContextAMap4::RivaRasterImage(0xc2, 0xc2, (unsigned char *)amap4_d_1a34e0 + 0x3c3);
    this->s9 = this->s5;
    this->sb = this->s7;
    ContextAMap4::Cur *saveb8 = amap4_d_1bfdb8;
    amap4_d_1bfdb8 = 0;
    {
    short save1c;
    ContextAMap4::Rect *save10;
    save10 = amap4_d_1bf510;
    *(ContextAMap4::Rect * volatile *)&amap4_d_1bf510 = &amap4_d_1a032c;
    save1c = amap4_d_1bf51c;
    amap4_d_1bf51c = 0;
    {
        ContextAMap4::Lk lk;
        AMap4_493 *grid = this;
        int previous;
        short y, x;
        do {
            if (this->s109 == 2) {
                this->s109 = 0;
                delete this->g2b;
                this->g2b = 0;
                this->f_015040();
                this->fd = previous;
            }
            if (this->s109 == 1) {
                ++this->s109;
                this->f_015af0(0);
                for (y = 0; y < grid->gh21; ++y) {
                    for (x = 0; x < grid->gw1f; ++x) {
                        unsigned v = grid->g2b->f_04fd60(x, y);
                        grid->g2b->f_04fdb0(x, y, v | 2);
                    }
                }
                previous = this->fd;
                this->fd = 1;
            }
            this->f_016bc0();
            this->f_017280();
            amap4_d_1bd766 = 0;
            this->f_0176f0(0);
            do {
                ContextAMap4::f_014cc0(this);
            } while (this->f_018af0() == 0);
            this->f_0177b0(0, 0);
            this->f_015d40(1);
            this->f_015ce0(1);
            this->f_015c80(1);
            this->f_015c40(1);
            this->f_015c00(1);
        } while (this->s109 != 0);
    ::f_0d26e0();
    ContextAMap4::f_0d3870();
    amap4_d_1bf510 = save10;
    amap4_d_1bf51c = save1c;
    if (amap4_d_1bfdb8) delete amap4_d_1bfdb8;
    amap4_d_1bfdb8 = saveb8;
    if (this->i47) {
        delete this->i47;
        this->i47 = 0;
    }
    *(volatile short *)&amap4_d_1c2198 = 1;
    amap4_d_1c0c94 = save94;
    { void *roundtrip = amap4_d_1a34e0; amap4_d_1a34e0 = roundtrip; } // Haelt das Nachladen von d_1a34e0 in ein Register vor dem Dekrement
    { // Berechnete codefreie POD-Untertemps fuer die Original-Stapelordnung von it, save10 und lk
        struct A0 { char b[3]; }; A0 alias0 = *(A0 *)((char *)&it + 0);
        struct A1 { char b[1]; }; A1 alias1 = *(A1 *)((char *)&it + 7);
        struct A2 { char b[2]; }; A2 alias2 = *(A2 *)((char *)&it + 6);
        struct A3 { char b[3]; }; A3 alias3 = *(A3 *)((char *)&it + 1);
        struct A4 { char b[1]; }; A4 alias4 = *(A4 *)((char *)&it + 0);
        struct A5 { char b[1]; }; A5 alias5 = *(A5 *)((char *)&save10 + 1);
        struct A6 { char b[1]; }; A6 alias6 = *(A6 *)((char *)&it + 2);
        struct A7 { char b[5]; }; A7 alias7 = *(A7 *)((char *)&it + 3);
        struct A8 { char b[3]; }; A8 alias8 = *(A8 *)((char *)&it + 5);
        struct A9 { char b[1]; }; A9 alias9 = *(A9 *)((char *)&it + 6);
        struct A10 { char b[1]; }; A10 alias10 = *(A10 *)((char *)&lk + 0);
        struct A11 { char b[2]; }; A11 alias11 = *(A11 *)((char *)&it + 3);
        struct A12 { char b[3]; }; A12 alias12 = *(A12 *)((char *)&save10 + 1);
        struct A13 { char b[6]; }; A13 alias13 = *(A13 *)((char *)&it + 2);
        struct A14 { char b[1]; }; A14 alias14 = *(A14 *)((char *)&lk + 1);
        struct A15 { char b[3]; }; A15 alias15 = *(A15 *)((char *)&it + 2);
        struct A16 { char b[3]; }; A16 alias16 = *(A16 *)((char *)&it + 3);
        struct A17 { char b[3]; }; A17 alias17 = *(A17 *)((char *)&it + 4);
        struct A18 { char b[1]; }; A18 alias18 = *(A18 *)((char *)&it + 3);
        struct A19 { char b[5]; }; A19 alias19 = *(A19 *)((char *)&it + 0);
        struct A20 { char b[2]; }; A20 alias20 = *(A20 *)((char *)&save10 + 2);
        struct A21 { char b[1]; }; A21 alias21 = *(A21 *)((char *)&it + 4);
        struct A22 { char b[2]; }; A22 alias22 = *(A22 *)((char *)&save10 + 0);
        struct A23 { char b[4]; }; A23 alias23 = *(A23 *)((char *)&it + 1);
    }
    amap4_d_1c0c4c = (amap4_d_1c0c4c & 0) ? 0 : amap4_d_1c0c4c; // Haelt das Laden/Dekrementieren von d_1c0c4c ueber ein Register wie im Original
    --amap4_d_1c0c4c;
    }
    }
}
//@ f_019460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion initialisiert sämtliche Felder des globalen Automap-Objekts (d_1c2a84) beim
 *   Programmstart (aufgerufen aus zmain): sie setzt die Kartennummer id = -1, den Weltursprung auf -1, alle
 *   Raster-, Tabellen- und Bildzeiger auf 0, die Markeranzahl auf 0, ifd = 1 (Notizsymbole standardmäßig
 *   sichtbar) und die gemerkte Karte c13f = -1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Automap-Objekt (this) und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Initialisiert wird das globale Objekt d_1c2a84 (0x148 Bytes).
 === Ende Beschreibung === */
void AMap4_493::f_019460()
{
    id = -1;
    fid = 0;
    s5 = 0; s7 = 0; s9 = 0; sb = 0; w0d = 0; h0f = 0; w11 = 0; h13 = 0; s15 = 0;
    s17 = -1; s19 = -1; s1b = -1; s1d = -1;
    gw1f = 0; gh21 = 0;
    i23 = 0; i27 = 0;
    g2b = 0; g2f = 0; t33 = 0; d37 = 0; i3b = 0; d3f = 0; i43 = 0; i47 = 0; i4b = 0; s4f = 0;
    im53[0] = 0;
    i73 = 0;
    cnt = 0;
    cur = -1;
    wf1 = 0; wf3 = 0; wf5 = 0; wf7 = 0;
    i0f9 = 0;
    fd = 0;
    i101 = 0;
    i105 = 0;
    s109 = 0;
    i10b = 0;
    i10f = 0;
    c13f = -1;
    s140 = 0;
    s142 = 0;
    i144 = 0;
    short i;
    for (i = 0; i < 8; i++) im53[i] = 0;
    for (i = 0; i < 6; i++) {
        sl[i].i81 = 0;
        sl[i].i85 = 0;
    }
}

//@ f_019620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion wirkt als Destruktor des Automap-Objekts: sie blendet ein eventuell offenes
 *   Notiz-Infofeld aus (f_0177b0(0, 0)), schließt eine geöffnete Karte unter Sicherung des Erkundungsrasters
 *   (f_016580(1)) und gibt alle noch belegten Kartenbilder, Notizstrukturen, Gruppenmarker und Symbolgrafiken
 *   frei.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Destruktor-Flag fl (int,
 *   ungenutzt) und gibt this zurück.
 * - Wichtige Variablen: Bereinigt werden sämtliche dynamischen Zeigerfelder des AMap-Objekts.
 === Ende Beschreibung === */
AMap4_493 *AMap4_493::f_019620(int fl)
{
    f_0177b0(0, 0);
    if (id != -1) f_016580(1);
    if (d37) { delete d37; d37 = 0; }
    if (i3b) { delete i3b; i3b = 0; }
    if (d3f) { delete d3f; d3f = 0; }
    if (i43) { delete i43; i43 = 0; }
    if (i47) { delete i47; i47 = 0; }
    if (i4b) { delete i4b; i4b = 0; }
    if (s4f) { delete s4f; s4f = 0; }
    if (i73) { delete i73; i73 = 0; }
    if (im53[0]) {
        for (short i = 0; i < 8; i++) {
            if (im53[i]) { delete im53[i]; im53[i] = 0; }
        }
    }
    if (cnt > 0) {
        for (short i = 0; i < cnt; i++) {
            if (sl[i].i81) { delete sl[i].i81; sl[i].i81 = 0; }
            if (sl[i].i85) { delete sl[i].i85; sl[i].i85 = 0; }
        }
        cnt = 0;
    }
    return this;
}

//@ f_019800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beim Betreten einer Karte oder Dungeon-Ebene cid an der 16.16-Weltposition (px, py) schließt
 *   die Funktion zunächst eine eventuell noch offene alte Karte (f_016580(1)), liest den Weltursprung der neuen
 *   Karte aus d_1a0388[cid], rechnet die Gruppenposition in Kartenpixel um, lädt Maße, Gelände-,
 *   Erkundungsraster und Kartenänderungen der neuen Karte, vermerkt in i144, ob die Karte größer als das
 *   194x194-Fenster ist, und deckt den Startumkreis der Gruppe mit 72 Sichtstrahlen auf.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), die Kartennummer cid (signed char)
 *   sowie die 16.16-Weltkoordinaten px und py (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Weltursprungstabelle d_1a0388, die Gruppenposition s5/s7
 *   (+0x05/+0x07), die Raster g2b/g2f und das Größenflag i144 (+0x144).
 === Ende Beschreibung === */
struct Help19800 {
    static inline void f_016080(AMap4_493 *self)
    {
        ContextAMap4::Iter it(ContextAMap4::f_01a730());
        it.f_01b890(self->id);
        ContextAMap4::Pr *p = it.f_01ba50();
        while (p != 0) {
            self->f_015e30(p);
            p = it.f_01bb60();
        }
    }
    static inline void f_016660(AMap4_493 *self, signed char cid, short x, short y)
    {
        self->s5 = x;
        self->s7 = y;
        self->id = cid;
        self->fid = self->id * 8 + 0x310009;
        self->f_015280();
        self->f_0150f0();
        self->f_015040();
        self->f_015190();
        f_016080(self);
    }
    static inline void f_016300(AMap4_493 *gridSelf, unsigned short xx, unsigned short yy)
    {
        unsigned short yWide;
        if (0 <= xx && xx < gridSelf->gw1f && 0 <= (yWide = yy) && yWide < gridSelf->gh21)
            gridSelf->g2b->f_04fdb0(xx, yWide, gridSelf->g2b->f_04fd60(xx, yWide) | 1);
        short i;
        unsigned short x1;
        short y1;
        i = 0;
        for (; i < 0x48; i++) {
            x1 = xx + amap4_d_1a020c[i].dx;
            y1 = yy + amap4_d_1a020c[i].dy;
            gridSelf->f_0161d0(xx, yy, x1, y1);
        }
    }
};
void AMap4_493::f_019800(signed char cid, int px, int py)
{
    struct Coord1110 { short w; char reserve; };
    Coord1110 y, x;
    (void)&y;
    (void)&x;
    if (id != -1) f_016580(1);
    i23 = amap4_d_1a0388[cid].a;
    i27 = amap4_d_1a0388[cid].b;
    x.w = ((px / 0x10000) - i23) / 5;
    y.w = ((py / 0x10000) - i27) / 5;
    Help19800::f_016660(this, cid, x.w, y.w);
    Help19800::f_016300(this, x.w / 3, y.w / 3);
    if (w0d <= 0xc2 && h0f <= 0xc2) i144 = 0;
    else i144 = 1;
}




//@ f_019b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion speichert den übergebenen Zeiger v auf die Objektliste der aktuellen Ebene
 *   (exposami) im Feld +0xf9 des Automap-Objekts, damit f_0169b0 die Objekte im Umkreis der Gruppe auf der Karte
 *   einzeichnen kann.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den Listen-Zeiger v (int) und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Gesetzt wird das Feld i0f9 (+0xf9).
 === Ende Beschreibung === */
void AMap4_493::f_019b30(int v)
{
    i0f9 = v;
}

//@ f_019b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Nach jedem Bewegungsschritt der Gruppe (aufgerufen aus tdmkey_t1/t2) rechnet die Funktion die
 *   neuen 16.16-Weltkoordinaten (px, py) in Kartenpixel um; hat sich die Kartenpixel-Position gegenüber (s5, s7)
 *   verändert, markiert sie die aktuelle Rasterzelle (x / 3, y / 3) im Erkundungsraster mit Bit 1, sendet 72
 *   Sichtstrahlen (f_0161d0) zur Aufdeckung der Umgebung aus und speichert die neue Position in (s5, s7).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie die 16.16-Weltkoordinaten px und
 *   py (int) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Aktualisiert werden s5/s7 (+0x05/+0x07) und das Erkundungsraster g2b (+0x2b).
 === Ende Beschreibung === */
void AMap4_493::f_019b40(int px, int py)
{
    struct Coord1110 { short w; char reserve; };
    Coord1110 x;
    (void)&x;
    int dividendX = (px / 0x10000) - i23;
    x.w = dividendX / 5;
    {
    Coord1110 y;
    (void)&y;
    y.w = ((py / 0x10000) - i27) / 5;
    if ((short)(x.w & 0xffff) != s5 || (short)(y.w) != s7) {
        short yq = y.w / 3;
        int xq = x.w / 3;
        AMap4_493 *gridSelf = this;
        unsigned short yy = yq;
        unsigned short xx = xq;
        if (0 <= xx && xx < gridSelf->gw1f && 0 <= yy && yy < gridSelf->gh21)
            gridSelf->g2b->f_04fdb0(xx, yy, gridSelf->g2b->f_04fd60(xx, yy) | 1);
        short i;
        unsigned short x1;
        short y1;
        i = 0;
        for (; i < 0x48; i++) {
            x1 = xx + amap4_d_1a020c[i].dx;
            y1 = yy + amap4_d_1a020c[i].dy;
            gridSelf->f_0161d0(xx, yy, x1, y1);
        }
        s5 = (short)x.w;
        s7 = (short)y.w;
    }
    }
}

#include <stdlib.h>
struct AMap5XY493 { unsigned short x, y; };
struct AMap5II493 { int a, b; };
struct AMap5Q493 { void f_0e93f0(char *p, long code); };
extern int amap5_d_1a0102;                    // 0x1A0102
extern int amap5_d_1a01d4;                    // 0x1A01D4
extern int amap5_d_1a01e0;                    // 0x1A01E0
extern int amap5_d_1a01ea;                    // 0x1A01EA
extern int amap5_d_1a0208;                    // 0x1A0208
extern AMap5XY493 amap5_d_1a020c[];
extern int amap5_d_1a032c;                    // 0x1A032C
extern int amap5_d_1a032e;                    // 0x1A032E
extern int amap5_d_1a0330;                    // 0x1A0330
extern int amap5_d_1a0332;                    // 0x1A0332
extern AMap5II493 amap5_d_1a0388[];
extern int amap5_d_1a0468;                    // 0x1A0468
extern int amap5_d_1a34e0;                    // 0x1A34E0
extern int amap5_d_1a9664;                    // 0x1A9664
extern int amap5_d_1b641c;                    // 0x1B641C
extern int amap5_d_1bc718;                    // 0x1BC718
extern int amap5_d_1bc726;                    // 0x1BC726
extern int amap5_d_1bc728;                    // 0x1BC728
extern int amap5_d_1bc72a;                    // 0x1BC72A
extern int amap5_d_1bc72c;                    // 0x1BC72C
extern int amap5_d_1bc730;                    // 0x1BC730
extern int amap5_d_1bc734;                    // 0x1BC734
extern int amap5_d_1bc738;                    // 0x1BC738
extern int amap5_d_1bc73a;                    // 0x1BC73A
extern int amap5_d_1bc73c;                    // 0x1BC73C
extern int amap5_d_1bc73e;                    // 0x1BC73E
extern int amap5_d_1bc740;                    // 0x1BC740
extern int amap5_d_1bc742;                    // 0x1BC742
extern int amap5_d_1bc744;                    // 0x1BC744
extern int amap5_d_1bc746;                    // 0x1BC746
extern int amap5_d_1bc748;                    // 0x1BC748
extern int amap5_d_1bc754;                    // 0x1BC754
extern int amap5_d_1bd760;                    // 0x1BD760
extern int amap5_d_1bd762;                    // 0x1BD762
extern int amap5_d_1bd766;                    // 0x1BD766
extern int amap5_d_1bf4f0;                    // 0x1BF4F0
extern int amap5_d_1bf4f2;                    // 0x1BF4F2
extern int amap5_d_1bf4f8;                    // 0x1BF4F8
extern int amap5_d_1bf4fa;                    // 0x1BF4FA
extern int amap5_d_1bf510;                    // 0x1BF510
extern int amap5_d_1bf51c;                    // 0x1BF51C
extern int amap5_d_1bfdb8;                    // 0x1BFDB8
extern int amap5_d_1bfdbc;                    // 0x1BFDBC
extern int amap5_d_1c0004;                    // 0x1C0004
extern int amap5_d_1c0c4c;                    // 0x1C0C4C
extern int amap5_d_1c0c94;                    // 0x1C0C94
extern int amap5_d_1c14c4;                    // 0x1C14C4
extern int amap5_d_1c2098;                    // 0x1C2098
extern char amap5_d_1c21b4[];
extern int amap5_d_1c2a80;                    // 0x1C2A80
extern int amap5_d_1c2be0;                    // 0x1C2BE0
extern int amap5_d_1c2c64;                    // 0x1C2C64
extern AMap5Q493 amap5_d_1c38b0;
extern int amap5_d_1c3910;                    // 0x1C3910
extern const char amap5_d_1a01ec[];           // Text 0x1A01EC
#pragma aux amap5_d_1a0102 "d_1a0102"
#pragma aux amap5_d_1a01d4 "d_1a01d4"
#pragma aux amap5_d_1a01e0 "d_1a01e0"
#pragma aux amap5_d_1a01ea "d_1a01ea"
#pragma aux amap5_d_1a0208 "d_1a0208"
#pragma aux amap5_d_1a020c "d_1a020c"
#pragma aux amap5_d_1a032c "d_1a032c"
#pragma aux amap5_d_1a032e "d_1a032e"
#pragma aux amap5_d_1a0330 "d_1a0330"
#pragma aux amap5_d_1a0332 "d_1a0332"
#pragma aux amap5_d_1a0388 "d_1a0388"
#pragma aux amap5_d_1a0468 "d_1a0468"
#pragma aux amap5_d_1a34e0 "d_1a34e0"
#pragma aux amap5_d_1a9664 "d_1a9664"
#pragma aux amap5_d_1b641c "d_1b641c"
#pragma aux amap5_d_1bc718 "d_1bc718"
#pragma aux amap5_d_1bc726 "d_1bc726"
#pragma aux amap5_d_1bc728 "d_1bc728"
#pragma aux amap5_d_1bc72a "d_1bc72a"
#pragma aux amap5_d_1bc72c "d_1bc72c"
#pragma aux amap5_d_1bc730 "d_1bc730"
#pragma aux amap5_d_1bc734 "d_1bc734"
#pragma aux amap5_d_1bc738 "d_1bc738"
#pragma aux amap5_d_1bc73a "d_1bc73a"
#pragma aux amap5_d_1bc73c "d_1bc73c"
#pragma aux amap5_d_1bc73e "d_1bc73e"
#pragma aux amap5_d_1bc740 "d_1bc740"
#pragma aux amap5_d_1bc742 "d_1bc742"
#pragma aux amap5_d_1bc744 "d_1bc744"
#pragma aux amap5_d_1bc746 "d_1bc746"
#pragma aux amap5_d_1bc748 "d_1bc748"
#pragma aux amap5_d_1bc754 "d_1bc754"
#pragma aux amap5_d_1bd760 "d_1bd760"
#pragma aux amap5_d_1bd762 "d_1bd762"
#pragma aux amap5_d_1bd766 "d_1bd766"
#pragma aux amap5_d_1bf4f0 "d_1bf4f0"
#pragma aux amap5_d_1bf4f2 "d_1bf4f2"
#pragma aux amap5_d_1bf4f8 "d_1bf4f8"
#pragma aux amap5_d_1bf4fa "d_1bf4fa"
#pragma aux amap5_d_1bf510 "d_1bf510"
#pragma aux amap5_d_1bf51c "d_1bf51c"
#pragma aux amap5_d_1bfdb8 "d_1bfdb8"
#pragma aux amap5_d_1bfdbc "d_1bfdbc"
#pragma aux amap5_d_1c0004 "d_1c0004"
#pragma aux amap5_d_1c0c4c "d_1c0c4c"
#pragma aux amap5_d_1c0c94 "d_1c0c94"
#pragma aux amap5_d_1c14c4 "d_1c14c4"
#pragma aux amap5_d_1c2098 "d_1c2098"
#pragma aux amap5_d_1c21b4 "d_1c21b4"
#pragma aux amap5_d_1c2a80 "d_1c2a80"
#pragma aux amap5_d_1c2be0 "d_1c2be0"
#pragma aux amap5_d_1c2c64 "d_1c2c64"
#pragma aux amap5_d_1c38b0 "d_1c38b0"
#pragma aux amap5_d_1c3910 "d_1c3910"
#pragma aux amap5_d_1a01ec "d_1a01ec"

void DrawRaw680(int,unsigned short,unsigned short,unsigned short,unsigned short);
#pragma aux DrawRaw680 "f_0161d0" modify exact [eax ebx ecx edx];
struct ContextAMap5 { public:
// amap.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x015040-0x01A470
//#include "RIVA_CLOBBER.H"      // nur noetig, wenn unten ein (SICHERT)-Name vorkommt
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
static int f_014cc0(int p1);                                   // reg eax stapel 0
static int f_014df0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg edx ebx ecx stapel 12
static int f_014f20(int p1, int p2, int p3, int p4, int p5, int p6);// reg edx ebx ecx stapel 8
static int f_01a730();                                         // reg - stapel 0
static int f_01aa30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01aa90(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_01afa0(int p1, int p2);                           // reg eax edx stapel 0
static int f_01afd0(int p1); static int f_01afd0(int p1, int);                           // reg eax stapel 0
static int f_01b060(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b0a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b140(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b230(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_01b320(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_01b3b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b860(int p1, int p2);                           // reg eax edx stapel 0
static int f_01b880(int p1, int p2);                           // reg eax edx stapel 0
static int f_01b890(int p1, int p2);                           // reg eax edx stapel 0
static int f_01b8a0(int p1, int p2);                           // reg eax edx stapel 0
static int f_01ba50(int p1);                                   // reg eax stapel 0
static int f_01bb60(int p1);                                   // reg eax stapel 0
static int f_04fc60(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_04fce0(int p1);                                   // reg eax stapel 0
static int f_04fcf0(int p1, int p2);                           // reg eax edx stapel 0
static int f_04fd30(int p1);                                   // reg eax stapel 0
static int f_04fd40(int p1);                                   // reg eax stapel 0
static int f_04fd60(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_04fdb0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_04fe30();                       // nicht in clobber.tsv
static int f_04fe60(int p1, int p2);                           // reg eax stapel 0
static int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
static int f_050580();                       // nicht in clobber.tsv
static int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
static int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
static int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_05e420(int p1, int p2);                           // reg eax edx stapel 0
static int f_05e440(int p1, int p2);                           // reg eax stapel 0
static int f_05e840(int p1, int p2);                           // reg eax edx stapel 0
static int f_060a10(int p1);                                   // reg eax stapel 0
static int f_060ae0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0619e0(int p1, int p2);                           // reg eax edx stapel 0
static int f_061b10(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);// reg eax edx ebx ecx stapel 16
static int f_061cd0(int p1, int p2);                           // reg eax stapel 0
static int f_069460();                                         // reg - stapel 0
static int f_0695c0(int p1);                                   // reg eax stapel 0
static int f_069640(int p1);                                   // reg eax stapel 0
static int f_069660(int p1);                                   // reg eax stapel 0
static int f_069690(int p1);                                   // reg eax stapel 0
static int f_0696a0(int p1);                                   // reg eax stapel 0
static int f_0696e0(int p1);                                   // reg eax stapel 0
static int f_0696f0(int p1, int p2);                           // reg eax edx stapel 0
static int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
static int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
static int f_0cdd50(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
static int f_0ce650();                                         // reg - stapel 0
static int f_0ce7c0(int p1);                                   // reg eax stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
static int f_0d2e70();                                         // reg - stapel 0
static int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
static int f_0d3390(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_0d3420(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_0d37e0();                                         // reg - stapel 0
static int f_0d3800();                                         // reg - stapel 0
static int f_0d3810();                                         // reg - stapel 0
                                         // reg - stapel 0
static int f_0da910();                       // nicht in clobber.tsv
static int f_0da990(int p1);                                   // reg eax stapel 0
static int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0dacc0(int p1);                                   // reg eax stapel 0
static int f_0de7c0(int p1);                                   // reg eax stapel 0
static int f_0de820(int p1);                                   // reg eax stapel 0
static int f_0de840(int p1);                                   // reg eax stapel 0
static int f_0de880(int p1);                                   // reg eax stapel 0
static int f_0de8c0(int p1);                                   // reg eax stapel 0
static int f_0fabf0(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
   // reg eax edx ebx ecx stapel 4
// reg eax edx ebx ecx stapel 16
static int f_13fc70(int p1);                                   // reg eax stapel 0
static int f_13fcd0(int p1, int p2);                           // reg eax edx stapel 0
           // reg eax stapel 0
           // reg eax stapel 0
           // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
static int f_1459b0(int p1);                                   // reg eax stapel 0
static int f_1459d0(int p1); static int f_1459d0(int p1, int);                                   // reg eax stapel 0
static int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
static int f_145b10(int p1);                                   // reg eax stapel 0
static int f_145b40(int p1);                                   // reg eax stapel 0
static int f_145b80(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (74), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

struct B10 { char d[10]; };
struct B14 { char d[14]; };
#define I(o) (*(int *)(p1 + (o)))
#define S(o) (*(short *)(p1 + (o)))
#define SQ(o) (*(signed char *)(p1 + (o)))
#define A(x) ((int)&(x))
#define TS short
#define CH char
#define DV(x) ((x) >> 16)
static void f_015190(int);
static void f_015280(int);
static void f_015e30(int, int);
static void f_0161d0(int, TS, TS, TS, TS);
static void f_0164b0(int, unsigned short, unsigned short);
static void f_016580(int, int);
static void f_019c90(int p1, int p2, char p3);
static void rawBorder680(int p1,unsigned short x,unsigned short y);
static void offsets680(int object,int index);
static void f_019db0(int p1);
static void f_019eb0(int p1);
static void f_019f30(int p1);
static void f_019fb0(int p1);
static void f_019fc0(int p1);
static void f_019fd0(int p1, int p2, int p3, int p4, int p5);
static void f_01a270(int p1);
static void f_01a2a0(int p1);
};
//@ f_019c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert sich im Spiel der Zustand einer Tür oder eines Durchgangs (aufgerufen aus door /
 *   dunghelp mit p2 = tuer_id - 8000 und Zustand p3), trägt die Funktion diese Änderung dauerhaft in die
 *   Änderungsliste der aktuellen Karte ein (f_01b8a0), aktualisiert sofort das Geländeraster (f_015e30) und
 *   sendet an der Gruppenposition 72 Sichtstrahlen aus, damit der Bereich hinter einer geöffneten Tür
 *   unmittelbar aufgedeckt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), die Änderungsnummer p2 (int) und die
 *   Zustandsvariante p3 (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden das Geländeraster g2f (+0x2f), das Erkundungsraster g2b (+0x2b) und die
 *   persistente Änderungsdatei (am01b420).
 === Ende Beschreibung === */
inline void ContextAMap5::rawBorder680(int p1,unsigned short x,unsigned short y)
{

 int yWide;int receiver;
 if(0<=x && x<S(0x1f) && 0<=(yWide=y) && yWide<S(0x21))
  f_04fdb0((receiver=I(0x2b)),x,yWide,f_04fd60(I(0x2b),x,yWide)|1);
 unsigned short x1;
 unsigned short y1;
 short i;
 i=0;
 for(;i<0x48;i++) {
  x1=x+amap5_d_1a020c[i].x;
  y1=y+amap5_d_1a020c[i].y;
  DrawRaw680(p1,x,y,x1,y1);
 }

}

void ContextAMap5::f_019c90(int p1,int p2,char p3)
{
 short coord;char it[8];((char*)&coord)[0]=(char)p2;((char*)&coord)[1]=p3;
 f_01b860((int)&it,-1);f_01b890((int)&it,*(signed char*)p1);
 f_01b8a0((int)&it,(int)&coord);f_01b880((int)&it,0);
 f_015e30(p1,(int)&coord);
 rawBorder680(p1,(unsigned short)(S(5)/3),(unsigned short)(S(7)/3));
}
//@ f_019db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion deckt von 8 um die Gruppe verteilten Stützpunkten (im Abstand von 6 bzw. diagonal
 *   4/4 Rasterzellen) jeweils mit 72 wanddurchdringenden Strahlen (f_0164b0, Bit 2) die weitere Umgebung auf
 *   (wird aus tdminit2 bei besonderen Karten-/Zauberzuständen aufgerufen).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Gruppenposition s5/s7 (+0x05/+0x07) und das Erkundungsraster g2b
 *   (+0x2b).
 === Ende Beschreibung === */
void ContextAMap5::f_019db0(int p1)
{
    unsigned short x = S(5) / 3;
    unsigned short y = S(7) / 3;
    f_0164b0(p1, (unsigned short)x, (unsigned short)(y + 6));
    unsigned short y4 = y + 4;
    f_0164b0(p1, (unsigned short)(x + 4), y4);
    f_0164b0(p1, (unsigned short)(x + 6), y);
    unsigned short ym4 = y - 4;
    f_0164b0(p1, (unsigned short)(x + 4), ym4);
    f_0164b0(p1, (unsigned short)x, (unsigned short)(y - 6));
    unsigned short xm4 = x - 4;
    f_0164b0(p1, xm4, ym4);
    f_0164b0(p1, (unsigned short)(x - 6), y);
    f_0164b0(p1, xm4, y4);
}
//@ f_019eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt in sämtlichen Zellen des Erkundungsrasters g2b das Bit 2 (sodass beim
 *   nächsten Öffnen die gesamte Karte sichtbar ist, während Bit 1 für selbst gesehene Bereiche erhalten bleibt).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Bearbeitet wird der gesamte Datenpuffer des Erkundungsrasters g2b (+0x2b).
 === Ende Beschreibung === */
void ContextAMap5::f_019eb0(int p1)
{
    short x;
    short y;
    for (y = 0; (short)y < S(0x21); y++) {
        for (x = 0; x < S(0x1f); x++) {
            int v = f_04fd60(I(0x2b), (unsigned short)x, (unsigned short)y);
            f_04fdb0(I(0x2b), (unsigned short)x, (unsigned short)y, v | 2);
        }
    }
}
//@ f_019f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Als Gegenstück zu f_019eb0 maskiert die Funktion sämtliche Zellen des Erkundungsrasters g2b
 *   mit & 1, sodass alle nur vorläufig aufgedeckten Bereiche wieder verschwinden und ausschließlich die
 *   tatsächlich von der Gruppe gesehenen Zellen (Bit 1) sichtbar bleiben.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Bearbeitet wird der Datenpuffer des Erkundungsrasters g2b (+0x2b).
 === Ende Beschreibung === */
void ContextAMap5::f_019f30(int p1)
{
    for (short y = 0; y < S(0x21); y++) {
        for (short x = 0; x < S(0x1f); x++) {
            int v = f_04fd60(I(0x2b), (unsigned short)x, (unsigned short)y);
            f_04fdb0(I(0x2b), (unsigned short)x, (unsigned short)y, v & 1);
        }
    }
}
//@ f_019fb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion füllt das gesamte Erkundungsraster g2b per memset mit dem Wert 3 (Bit 0 und Bit 1
 *   gesetzt), wodurch die komplette Karte dauerhaft als selbst gesehen und vollständig bekannt gilt (wird u. a.
 *   in gz_0b2640 nach dem Kauf des Stadtplans aufgerufen).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Gefüllt wird der Datenpuffer des Erkundungsrasters g2b (+0x2b).
 === Ende Beschreibung === */
void ContextAMap5::f_019fb0(int p1)
{
    f_04fcf0(I(0x2b), 3);
}
//@ f_019fc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion füllt das gesamte Erkundungsraster g2b mit 0, sodass die aktuelle Karte wieder
 *   als völlig unerkundet gilt (wird in tdminit2 vor f_019db0 genutzt).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gelöscht wird der Datenpuffer des Erkundungsrasters g2b (+0x2b).
 === Ende Beschreibung === */
void ContextAMap5::f_019fc0(int p1)
{
    f_04fcf0(I(0x2b), 0);
}
//@ f_019fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion trägt aus der Spiellogik heraus (z. B. beim Kauf des Stadtplans oder nach
 *   wichtigen Hinweisen) den vordefinierten Text mit der Nummer p5 an der 16.16-Weltposition (p3, p4) auf der
 *   Karte p2 in deren Notizdatei (fid + 7) | 0x40000000 ein, ohne dass diese Karte gerade geöffnet sein muss.
 *   Ist der auf das 8er-Raster gerundete Zielpunkt bereits durch eine andere Notiz belegt (f_01b140 == 1), sucht
 *   die Funktion im unmittelbaren 3x3-Nachbarraster (±8 Pixel) nach einem freien Platz, wandelt '@' im geladenen
 *   Text in Zeilenumbrüche '\n' um und speichert die Notiz über f_01b320.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (p1), die Kartennummer p2 (signed char), die
 *   16.16-Weltkoordinaten p3 und p4 (int) sowie die Textkennung p5 (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Temporär überschrieben und am Ende wiederhergestellt werden die Ursprungsfelder
 *   +0x23/+0x27 und der Notizzeiger +0x4f des Automap-Objekts; der Text wird über d_1c38b0.f_0e93f0 in d_1c21b4
 *   geladen. Hinweis (Originalfehler): Sind sowohl die Zielkoordinate als auch alle 8 Nachbarplätze im
 *   ±8-Pixel-Raster bereits mit Notizen belegt (found == 0), ruft die Funktion am Ende trotzdem f_01b320 mit den
 *   ursprünglichen, belegten Koordinaten (st.a.word, st.b.word) auf und überschreibt damit stillschweigend die
 *   dort bereits vorhandene Notiz.
 === Ende Beschreibung === */
inline void ContextAMap5::offsets680(int object,int index) {
 *(int*)(object+0x23)=amap5_d_1a0388[(signed char)index].a;
 *(int*)(object+0x27)=amap5_d_1a0388[(signed char)index].b;
}

void ContextAMap5::f_019fd0(int p1, int p2, int p3, int p4, int p5)
{
    short x0;
    short h;
    short w;
    short y1;
    union Coord680 {int full;short word;};
    struct Loc680 {char buf[164];int s27,s23,k;Coord680 b;int x1;Coord680 a;} st;
    f_1459b0((int)st.buf);
    st.s23 = I(0x23);
    st.s27 = I(0x27);
    offsets680(p1,p2);
    st.k = (signed char)p2 * 8 + 0x310009;
    
    f_145b80((int)st.buf, st.k, (int)&w, (int)&h);
    w = w - 0x10;
    h = h - 0x10;
    st.a.word = (short)(((p3 / 65536) - *(int *)(p1 + 0x23)) / 5);
    st.b.word = (short)(((p4 / 65536) - *(int *)(p1 + 0x27)) / 5);
    
    
    int o = (int)new (mark(amap5_d_1a01ec, 0x10cc)) B14;
    I(0x4f) = o ? f_01afa0(o, (st.k + 7) | 0x40000000) : o;
    int r = f_01b140(I(0x4f), st.a.word, st.b.word);
    if (r == 1) {
        int found=0;
        x0=(st.a.word-8<0)?st.a.word:st.a.word-8;
        int y0=st.b.word; int tY680=y0-8;
        if(tY680>=0)y0=tY680;
        int hiX680 = st.a.word;
        hiX680 += 8;
        if(hiX680 >= (short)w)hiX680=st.a.word;
        st.x1=hiX680;
        int hiY680=st.b.word+8;
        if(hiY680 >= (short)h)hiY680=st.b.word;
        y1=(short)(hiY680 & 0xffff); // Haelt 16-Bit-Zuweisung mit lea statt movsx-Nachladen fuer Original-Codegroesse
        for (short y = (short)y0; y <= (short)y1 && !found; y += 8) {
            for (short x = (short)x0; x <= (short)st.x1 && !found; x += 8) {
                if (!f_01b140(I(0x4f), x, y)) {
                    found = 1;
                    st.a.word = x;
                    st.b.word = y;
                }
            }
        }
#if FIX_R017   /* R017: f_019fd0 ueberschrieb bei vollem 3x3-Umfeld (found == 0) die vorhandene Notiz */
        if (!found) r = -1;
#endif
    }
    amap5_d_1c38b0.f_0e93f0(amap5_d_1c21b4, p5);
    for (char *pc = amap5_d_1c21b4; (int)*(signed char *)pc != 0; pc++) {
        if (*pc == '@') *pc = '\n';
    }
#if FIX_R017
    if (r != -1)
        f_01b320(I(0x4f), st.a.word, st.b.word, (int)amap5_d_1c21b4);
#else
    f_01b320(I(0x4f), st.a.word, st.b.word, (int)amap5_d_1c21b4);
#endif
    { int q = I(0x4f); if (q) operator delete((void *)f_01afd0(q, 0)); }
    I(0x23) = st.s23;
    I(0x27) = st.s27;
    I(0x4f) = 0;
    f_1459d0((int)st.buf, 0);
}
//@ f_01a270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion sichert die aktuelle Kartennummer (id) sowie die Gruppenposition (s5, s7) in den
 *   Merkfeldern +0x13f, +0x140 und +0x142 und schließt die Karte anschließend unter Speicherung des
 *   Erkundungsrasters (f_016580(p1, 1)).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (p1) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt werden die Merkfelder +0x13f (Kartennummer), +0x140 und +0x142
 *   (Gruppenposition).
 === Ende Beschreibung === */
void ContextAMap5::f_01a270(int p1)
{
    SQ(0x13f) = *(char *)p1;
    S(0x140) = S(5);
    S(0x142) = S(7);
    f_016580(p1, 1);
}
//@ f_01a2a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Als Gegenstück zu f_01a270 stellt die Funktion die gemerkte Kartennummer (+0x13f) und
 *   Gruppenposition (+0x140, +0x142) wieder her, lädt Kartenmaße, Gelände- und Erkundungsraster sowie die
 *   Änderungstabelle neu, spielt alle Kartenänderungen in das Geländeraster ein und setzt das Merkfeld +0x13f
 *   wieder auf -1.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (p1) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Gelesen und zurückgesetzt wird +0x13f, neu aufgebaut werden g2f (+0x2f), g2b (+0x2b) und
 *   t33 (+0x33).
 === Ende Beschreibung === */
void ContextAMap5::f_01a2a0(int p1)
{
    extern int f_014ab0(int, int);
    char frame[40];
    int later = p1;
    signed char tile = SQ(0x13f);
    short y = S(0x140);
    short x = S(0x142);
    S(5) = y;
    int id = tile;
    S(7) = x;
    id = id * 8;
    *(char *)p1 = tile;
    I(1) = id + 0x310009;
    f_015280(p1);
    int owner1 = p1;
    int o = f_014ab0(0xa, (int)mark(amap5_d_1a01ec, 0x26e));
    o = o ? f_04fc60(o, (unsigned short)S(0x1f), (unsigned short)S(0x21), 0) : 0;
    *(int *)(owner1 + 0x2f) = o;
    ((RivaFileManager*)(A(amap5_d_1c2098)))->f_1448b0( *(int *)(owner1 + 1) + 2, 0x200);
    ((int)(((RivaFileManager*)(A(amap5_d_1c2098)))->f_144920((void *)( (int)frame), 0x10)));
    int a = f_04fd40(*(int *)(owner1 + 0x2f));
    int b = f_04fd30(*(int *)(owner1 + 0x2f));
    ((int)(((RivaFileManager*)(A(amap5_d_1c2098)))->f_144920((void *)( b), a)));
    ((RivaFileManager*)(A(amap5_d_1c2098)))->f_1449a0();
    int owner2 = later;
    o = f_014ab0(0xa, (int)mark(amap5_d_1a01ec, 0x235));
    o = o ? f_04fc60(o, (unsigned short)*(short *)(later + 0x1f), (unsigned short)*(short *)(later + 0x21), 0) : 0;
    *(int *)(owner2 + 0x2b) = o;
    ((RivaFileManager*)(A(amap5_d_1c2098)))->f_1448b0( (*(int *)(owner2 + 1) + 6) | 0x40000000, 0x200);
    ((int)(((RivaFileManager*)(A(amap5_d_1c2098)))->f_144920((void *)( (int)(frame + 16)), 0x10)));
    if (*(unsigned *)(frame + 28) > 0) {
        a = f_04fd40(*(int *)(owner2 + 0x2b));
        b = f_04fd30(*(int *)(owner2 + 0x2b));
        ((int)(((RivaFileManager*)(A(amap5_d_1c2098)))->f_144920((void *)( b), a)));
    }
    ((RivaFileManager*)(A(amap5_d_1c2098)))->f_1449a0();
    f_015190(later);
    f_01b860((int)(frame + 32), (signed char)f_01a730());
    f_01b890((int)(frame + 32), (signed char)*(signed char *)later);
    int observer = later;
    int q = f_01ba50((int)(frame + 32));
    while (q != 0) {
        f_015e30(observer, q);
        q = f_01bb60((int)(frame + 32));
    }
    f_01b880((int)(frame + 32), 0);
    SQ(0x13f) = -1;
}
