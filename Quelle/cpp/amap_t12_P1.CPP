/* === Beschreibung (Katalog) ===
 * Einheit amap_t12
 *
 * Diese Einheit bildet den ersten und zweiten Teil der pixelbasierten Übersichtskarte (Automap, amap.cpp,
 * Adressbereich 0x015040-0x0176f0). Im Gegensatz zur kachelbasierten Karte aus *Schicksalsklinge* und
 * *Sternenschweif* (OVL046.CPP:automap_view zeigt dort nur noch den äußeren Ablauf) arbeitet Riva mit einer
 * großen Pixelkarte (fid + 0), einer verkleinerten Übersichtskarte (fid + 1), einem Gelände- und Sichtraster
 * (fid + 2, eine Zelle entspricht 3x3 Kartenpixeln), einem im Spielstand gespeicherten Erkundungsraster (fid + 6
 * | 0x40000000), dynamischen Kartenänderungen für Türen oder Durchbrüche (fid + 3..5) und 72 Sichtstrahlen zur
 * Aufdeckung beim Gehen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 36/41 gleich (suche.py 30.10.2026, Basis amap_t12_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra493: echte Vereinigung amap_t1+t2, Originalbereich 015040-0176f0.
// amap.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x015040-0x01A470
#include <string.h>
extern const char d_1a01ec[];           // Text 0x1A01EC
struct Grid {
    char b[10];
    Grid(unsigned short w, unsigned short h, int z); ~Grid();
    void *f_04fd30(); int f_04fd40();
    unsigned f_04fd60(unsigned short x, unsigned short y);
    void f_04fdb0(unsigned short x, unsigned short y, unsigned v);
};

struct Strm { char b[14]; Strm(unsigned long id); ~Strm(); };
struct Pak {
    char b[164];
    Pak(); ~Pak();
    void f_145b80(unsigned long id, short *w, short *h);
    void f_145a10(unsigned long id, void *buf);
    void *f_145b40(); void *f_145b10();
};

extern RivaFileManager d_1c2098;
struct Reg {
    char b[32];
    Reg(); Reg(int); ~Reg();
    void f_050580(int id, int idx, void *a, void *b2);
    void f_04fef0(int id, int r, int z, int idx, int z2, int n);
};
extern Reg d_1c2be0;
struct Pr { signed char a; signed char b; };
struct Iter {
    char b[8];
    Iter(long x); ~Iter();
    void f_01b890(int id); Pr *f_01ba50(); Pr *f_01bb60(); void f_01b8a0(int v);
};
struct AMap;
struct Bank { short f_13fc70(); void f_13fcd0(int s); };
extern Bank d_1c14c4;
struct Obj {
    char b[0x61];
    int f_0de7c0(); short f_0de820(); int f_0de840(); int f_0de880(); unsigned f_0de8c0();
};
extern Obj d_1bfdbc[];
extern Obj *d_1c0004;
struct Dxy { unsigned short dx, dy; };
extern Dxy d_1a020c[];
extern char *d_1a0208;
extern void *d_1a34e0;
extern char d_1bc718[];
extern const char d_1b641c[];
extern char *d_1a9664;
struct Ent7 { short a0; unsigned char c2; short s3; short s5; };
struct Pt { unsigned short x, y; };
struct Sl {
    int fl; short x; short y; unsigned short k; RivaRasterImage *i81; RivaRasterImage *i85; short w89;
};
struct AMap {
    signed char id;
    unsigned long fid;
    char p5[8];
    short w0d, h0f, w11, h13, s15;
    char p17[8];
    short gw1f, gh21;
    int i23, i27;
    Grid *g2b; Grid *g2f;
    Ent7 *t33;
    unsigned char *d37; RivaRasterImage *i3b; unsigned char *d3f; RivaRasterImage *i43;
    char p47[4];
    RivaRasterImage *i4b; Strm *s4f;
    RivaRasterImage *im53[8];
    RivaRasterImage *i73;
    Sl sl[6];
    signed char cnt; signed char cur;
    short wf1, wf3, wf5, wf7;
    char pf9[0x109 - 0xf9];
    short s109;
    char p10b[8];
    Pt pts[100];
    void f_015040(); void f_0150f0(); void f_015190(); void f_015280(); void f_015310(); void f_0153c0();
    void f_015450(); void f_0155e0(); void f_0156f0(); void f_015af0(int p2);
    void f_015bb0(int p2); void f_015be0(int p2); void f_015c00(int p2); void f_015c40(int p2);
    void f_015c80(int p2); void f_015ce0(int p2); void f_015d40(int p2);
    void f_015dc0(Grid *g, unsigned long id, short n);
    void f_015e30(Pr *p2); void f_015fd0(Pr *p2);
    void f_016080(); void f_0160d0(); void f_016140(int p2);
    void f_016180(unsigned short x, unsigned short y, unsigned v);
    void f_0161d0(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1);
    void f_016300(unsigned short x, unsigned short y);
    void f_016fd0(int idx);
    void f_016bc0();
};
int f_014f20(AMap *a, RivaRasterImage *src, RivaRasterImage *dst, int x, int y, int z);
int f_014df0(AMap *a, RivaRasterImage *src, RivaRasterImage *dst, int x, int y, int z, int w);
short f_0cdd50(int a, int b, int c, int d, Pt *out);
int f_0d3860(); void f_0d2710(); void f_0d26e0(); void __cdecl f_099ef0(void *p, int v, int n);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_015040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion legt das Erkundungsraster (g2b, eine Zelle je 3x3 Kartenpixel) für die aktuelle
 *   Karte im Speicher an und liest die bisher erkundeten Zellen aus der Spielstandsdatei fid + 6 | 0x40000000
 *   ein, sofern im 16-Byte-Dateikopf eine Größe größer null (n > 0) vermerkt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Automap-Objekt (this) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Das Feld +0x2b (g2b) speichert das Erkundungsraster (Bit 0 = selbst gesehen, Bit 1 =
 *   aufgedeckt), +0x1f und +0x21 (gw1f, gh21) enthalten die Rasterbreite und -höhe, +0x01 (fid) ist die
 *   Archiv-Basiskennung der Karte und d_1c2098 ist das globale Archiv- und Dateiobjekt.
 === Ende Beschreibung === */
void AMap::f_015040()
{
    g2b = new (mark(d_1a01ec, 0x235)) Grid(gw1f, gh21, 0);
    d_1c2098.f_1448b0(fid + 6 | 0x40000000, 0x200);
    struct { char b[12]; unsigned n; } h;
    d_1c2098.f_144920(&h, 0x10);
    if (h.n > 0) {
        d_1c2098.f_144920(g2b->f_04fd30(), g2b->f_04fd40());
    }
    d_1c2098.f_1449a0();
}

//@ f_0150f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion legt das Gelände- und Sichtraster (g2f) in den Maßen der aktuellen Karte an,
 *   überliest den 16-Byte-Kopf der Archivdatei fid + 2 und lädt die Zellwerte in den Speicher. Darin
 *   kennzeichnet der Wert 0 eine undurchsichtige Wand, der Wert 3 eine Sonderzelle (vermutlich eine Tür oder
 *   einen Durchgang) und jeder andere Wert ein frei einsehbares bzw. begehbares Feld.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Feld +0x2f (g2f) verweist auf das geladene Geländeraster, während gw1f (+0x1f) und
 *   gh21 (+0x21) die Rastermaße in 3x3-Pixel-Zellen angeben.
 === Ende Beschreibung === */
void AMap::f_0150f0()
{
    g2f = new (mark(d_1a01ec, 0x26e)) Grid(gw1f, gh21, 0);
    d_1c2098.f_1448b0(fid + 2, 0x200);
    char h[16];
    d_1c2098.f_144920(h, 0x10);
    d_1c2098.f_144920(g2f->f_04fd30(), g2f->f_04fd40());
    d_1c2098.f_1449a0();
}

//@ f_015190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Falls zur aktuellen Karte eine Änderungstabelle (fid + 5) im Archiv existiert, lädt die
 *   Funktion deren 7-Byte-Einträge in ein neu angelegtes Array (t33), wobei Eintrag 0 als Kopfsatz die Anzahl
 *   der Einträge speichert; existiert keine solche Datei, wird lediglich ein leerer Kopfsatz mit der Anzahl 0
 *   angelegt.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Das Feld +0x33 (t33) zeigt auf die Tabelle der 7-Byte-Änderungseinträge (mit Basisindex
 *   a0 für Teilbilder/Rasterblöcke sowie der Pixelposition s3, s5 auf der Karte).
 === Ende Beschreibung === */
void AMap::f_015190()
{
    struct { char b[8]; unsigned short n; } h;
    if (d_1c2098.f_144870(fid + 5) == 1) {
        d_1c2098.f_1448b0(fid + 5, 0x200);
        d_1c2098.f_144920(&h, 10);
        t33 = (Ent7 *)new (mark(d_1a01ec, 0x2af)) char[(h.n + 1) * 7];
        d_1c2098.f_144920(t33 + 1, h.n * 7);
        d_1c2098.f_1449a0();
    } else {
        h.n = 0;
        t33 = (Ent7 *)new (mark(d_1a01ec, 0x2c4)) char[7];
    }
    t33->a0 = h.n;
    t33->c2 = 0;
    t33->s3 = 0;
    t33->s5 = 0;
}

//@ f_015280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liest aus dem Grafikarchiv die Pixelmaße der großen Karte (fid) und der
 *   verkleinerten Übersichtskarte (fid + 1), berechnet daraus die Größe des Erkundungs- und Geländerasters
 *   (ceil(Breite / 3) x ceil(Höhe / 3)) und bestimmt den ganzzahligen Verkleinerungsfaktor der Übersichtskarte.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Im Kartenobjekt werden Breite und Höhe der großen Karte (w0d, h0f an +0x0d/+0x0f),
 *   Breite und Höhe der Übersichtskarte (w11, h13 an +0x11/+0x13), der Verkleinerungsfaktor (s15 an +0x15) sowie
 *   die Rastermaße (gw1f, gh21 an +0x1f/+0x21) gesetzt.
 === Ende Beschreibung === */
void AMap::f_015280()
{
    Pak pk;
    pk.f_145b80(fid, &w0d, &h0f);
    gw1f = (w0d + 2) / 3;
    gh21 = (h0f + 2) / 3;
    pk.f_145b80(fid + 1, &w11, &h13);
    s15 = w0d / w11;
}

//@ f_015310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion reserviert den Pixelpuffer für die große Karte (w0d x h0f Bytes), entpackt das
 *   Kartenbild fid aus dem Archiv hinein, legt das zugehörige Grafikobjekt an und aktiviert die 160 (0xa0)
 *   Palettenfarben der Karte über f_099ef0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Feld +0x37 (d37) hält den Rohpixelpuffer der großen Karte, und +0x3b (i3b) speichert
 *   das darübergelegte Grafikobjekt.
 === Ende Beschreibung === */
void AMap::f_015310()
{
    Pak pk;
    d37 = new (mark(d_1a01ec, 0x309)) unsigned char[w0d * h0f];
    pk.f_145a10(fid, d37);
    i3b = new (mark(d_1a01ec, 0x30e)) RivaRasterImage(w0d, h0f, d37);
    f_099ef0(pk.f_145b40(), 0, 0xa0);
}

//@ f_0153c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion reserviert den Pixelpuffer für die Übersichtskarte (w11 x h13 Bytes), lädt das
 *   Bild fid + 1 aus dem Grafikarchiv hinein und erzeugt das zugehörige Grafikobjekt für das
 *   Übersichts-Teilfenster rechts oben.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Das Feld +0x3f (d3f) enthält den Pixelpuffer der Übersichtskarte, und +0x43 (i43)
 *   verweist auf das zugehörige Grafikobjekt.
 === Ende Beschreibung === */
void AMap::f_0153c0()
{
    Pak pk;
    d3f = new (mark(d_1a01ec, 0x32a)) unsigned char[w11 * h13];
    pk.f_145a10(fid + 1, d3f);
    i43 = new (mark(d_1a01ec, 0x32f)) RivaRasterImage(w11, h13, d3f);
}

//@ f_015450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion lädt das Stecknadelsymbol für Kartennotizen aus dem Archiveintrag 0x310002 (im
 *   Sondermodus s109 == 2 wird Bildvariante 1 statt 0 gewählt) und legt die Kartennotiz-Verwaltung (s4f, Einheit
 *   gz_01a9b0) an, die im Normalbetrieb auf die Spielstandsdatei fid + 7 | 0x40000000 und im Sondermodus auf
 *   eine externe Hilfsdatei zugreift.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Das Feld +0x4b (i4b) speichert das Grafikobjekt des Notizsymbols, +0x4f (s4f) verweist
 *   auf die Notizverwaltung, +0x109 (s109) kennzeichnet den Sondermodus und d_1a9664 nimmt im Sondermodus den
 *   umgebauten Dateinamen (d_1bc718) auf.
 === Ende Beschreibung === */
struct R2 {
    char b[32];
    R2(int z); ~R2();
    void f_050580(int id, int idx, void *a, void *b2);
    void f_04fef0(int id, int r, int z, int idx, int z2, int n);
};
void AMap::f_015450()
{
    R2 r(0);
    short a, b;
    short fl = EQ(s109, 2);
    r.f_050580(0x310002, fl, &a, &b);
    i4b = new (mark(d_1a01ec, 0x353)) RivaRasterImage(a, b);
    r.f_04fef0(0x310002, ((int)(((RivaRasterImage*)(i4b))->f_0fb0b0())), 0, fl, 0, 0x140);
    if (s109 == 2) {
        strcpy(d_1bc718, d_1c2098.f_144850(fid + 7));
        strcpy(strchr(d_1bc718, '.') + 1, d_1b641c);
        d_1a9664 = d_1bc718;
        s4f = new (mark(d_1a01ec, 0x370)) Strm(2);
    } else {
        s4f = new (mark(d_1a01ec, 0x374)) Strm(fid + 7 | 0x40000000);
    }
}
//@ f_0155e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liest aus dem Archiveintrag 0x310004 die Abmessungen der Richtungspfeile
 *   (Teilbild 0x19) und der Gruppenmarkierungen (Teilbild 0), lädt die 8 Markierungsbilder in das Array
 *   im53[0..7] und legt ein Arbeitsbild in Pfeilgröße für den Marker der aktiven Gruppe an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Die Felder wf1/wf3 (+0xf1/+0xf3) und wf5/wf7 (+0xf5/+0xf7) speichern die Pfeil- und
 *   Symbolmaße, im53[0..7] (+0x53) hält die 8 Markierungssymbole und i73 (+0x73) ist das Arbeitsbild für den
 *   aktiven Gruppenpfeil.
 === Ende Beschreibung === */
void AMap::f_0155e0()
{
    Reg r(0);
    r.f_050580(0x310004, 0x19, &wf1, &wf3);
    r.f_050580(0x310004, 0, &wf5, &wf7);
    for (short i = 0; i < 8; i++) {
        im53[i] = new (mark(d_1a01ec, 0x3a2)) RivaRasterImage(wf5, wf7);
        r.f_04fef0(0x310004, ((int)(((RivaRasterImage*)(im53[i]))->f_0fb0b0())), 0, i, 0, 0x140);
    }
    i73 = new (mark(d_1a01ec, 0x3a9)) RivaRasterImage(wf1, wf3);
}

//@ f_0156f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion durchläuft alle 6 möglichen Heldengruppen (d_1bfdbc[0..5]): für jede aktive
 *   Gruppe, die sich auf der aktuellen Karte befindet, rechnet sie die 16.16-Weltkoordinaten in Kartenpixel um,
 *   bestimmt aus dem Blickwinkel den 8er-Richtungssektor, sichert den Kartenhintergrund unter dem Marker, lädt
 *   den passenden Richtungspfeil aus 0x310004 und zeichnet alle Gruppenmarker in die große Karte sowie in die
 *   Übersichtskarte ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Array sl[0..5] (+0x77) speichert die bis zu 6 Gruppenmarker, cnt (+0xef) deren
 *   Anzahl, cur (+0xf0) den Index der aktiven Spielergruppe (d_1c0004) und d_1bfdbc die globale Gruppentabelle.
 *   Hinweis (Originalfehler): cur wird mit -1 vorbesetzt und nur gesetzt, wenn sich die aktive Gruppe d_1c0004
 *   auf der Karte id befindet; am Ende greift die Funktion jedoch ungesichert auf sl[cur] zu, was bei
 *   Abwesenheit der aktiven Gruppe vor den Beginn des Arrays (sl[-1]) liest.
 === Ende Beschreibung === */
void AMap::f_0156f0()
{
    Reg r(0);
    short sel = (*(volatile short *)&s15 <= 2); // Haelt den Speicherzugriff auf s15 wie im Original
    cur = -1;
    short i;
    for (i = 0; i < 6; i++) {
        Obj *o = &d_1bfdbc[i];
        int t_230 = o->f_0de7c0();
        if (t_230 == 1) {
            if (o->f_0de820() == id) {
                int yy = o->f_0de880();
                int xx = o->f_0de840();
                short *xp = &sl[cnt].x;
                short *yp = &sl[cnt].y;
                *xp = ((xx / 65536) - i23) / 5;
                *yp = ((yy / 65536) - i27) / 5;
                unsigned short v = o->f_0de8c0();
                int cv = (v & 0xffff); // Haelt die Auswertungs- und Registerfolge fuer kv wie im Original
                short kv = ((cv + 0xfff) >> 13) & 7;
                sl[cnt].k = kv;
                sl[cnt].i85 = new (mark(d_1a01ec, 0x3f8)) RivaRasterImage(wf1, wf3);
                f_014f20(this, i3b, sl[cnt].i85, sl[cnt].x, sl[cnt].y, 0);
                sl[cnt].w89 = 0;
                RivaRasterImage *im2;
                if (&d_1bfdbc[i] == d_1c0004) {
                    cv = (cv & 0) ? 0 : cv; // Haelt die Lebensdauer und Registerzuteilung wie im Original
                    kv = (kv & 0) ? 0 : kv;
                    sl[cnt].fl = 1;
                    cur = cnt;
                    im2 = new (mark(d_1a01ec, 0x411)) RivaRasterImage(wf1, wf3);
                } else {
                    sl[cnt].fl = 0;
                    f_014df0(this, i43, im53[4 + sel], (short)(sl[cnt].x / s15), (short)(sl[cnt].y / s15), 1, -1);
                    im2 = new (mark(d_1a01ec, 0x42a)) RivaRasterImage(wf1, wf3);
                }
                sl[cnt].i81 = im2;
                r.f_04fef0(0x310004, ((int)(((RivaRasterImage*)(sl[cnt].i81))->f_0fb0b0())), 0, (short)(sl[cnt].k + 0x19), 0, 0x140);
                cnt = cnt + 1;
            }
        }
    }
    for (i = 0; i < cnt; i++) {
        if (sl[i].fl == 0) f_016fd0(i);
    }
#if FIX_R016   /* R016: Zugriff auf sl[cur] (sl[-1]) verhindern, wenn aktive Gruppe nicht auf Karte id ist */
    if (cur >= 0) {
        f_014f20(this, i3b, sl[cur].i85, sl[cur].x, sl[cur].y, 0);
        f_014df0(this, i43, im53[sel], (short)(sl[cur].x / s15), (short)(sl[cur].y / s15), 1, -1);
    }
#else
    f_014f20(this, i3b, sl[cur].i85, sl[cur].x, sl[cur].y, 0);
    f_014df0(this, i43, im53[sel], (short)(sl[cur].x / s15), (short)(sl[cur].y / s15), 1, -1);
#endif
}

//@ f_015a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion blendet einen sichtbaren Mauszeiger vorübergehend aus, entpackt das
 *   Hintergrundbild des Kartenbildschirms (Archivkennung 0x310000) direkt in den Bildschirmpuffer d_1a34e0 und
 *   schaltet die Maus anschließend wieder ein.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Die globale Variable d_1a34e0 verweist auf den 320 Pixel breiten
 *   Bildschirm-Zeichenpuffer.
 === Ende Beschreibung === */
void f_015a80()
{
    Pak pk;
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
        ~MG() { if (fl == 1) f_0d26e0(); }
    } mg;
    pk.f_145a10(0x310000, d_1a34e0);
    pk.f_145b10();
}

//@ f_015af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schreibt das aktuelle Erkundungsraster (g2b) samt einem 16-Byte-Kopfsatz
 *   (Magiekennung aus d_1a0208, Rastermaße und Datenlänge) in die Spielstandsdatei fid + 6 | 0x40000000 und gibt
 *   das Rasterobjekt anschließend frei, falls der Parameter p2 == 1 übergeben wurde.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Freigabeflag p2 (1 = nach dem
 *   Speichern freigeben, 0 = behalten) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden das Erkundungsraster g2b (+0x2b), die Rastermaße gw1f/gh21 (+0x1f/+0x21),
 *   die Magiekennung d_1a0208 und das Dateiobjekt d_1c2098.
 === Ende Beschreibung === */
void AMap::f_015af0(int p2)
{
    struct { long magic; short a, b, w, h; long size; } hh;
    hh.magic = *(long *)d_1a0208;
    hh.a = 0;
    hh.b = 1;
    hh.w = gw1f;
    hh.h = gh21;
    hh.size = g2b->f_04fd40();
    d_1c2098.f_144890(fid + 6 | 0x40000000);
    d_1c2098.f_144960(&hh, 0x10);
    d_1c2098.f_144960(g2b->f_04fd30(), hh.size);
    d_1c2098.f_1449a0();
    if (p2 == 1) {
        delete g2b;
        g2b = 0;
    }
}

//@ f_015bb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist das Flag p2 == 1 gesetzt, gibt die Funktion das Geländeraster g2f frei und setzt den
 *   Zeiger im Automap-Objekt auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Betroffen ist das Zeigerfeld g2f (+0x2f).
 === Ende Beschreibung === */
void AMap::f_015bb0(int p2)
{
    if (p2 == 1) {
        delete g2f;
        g2f = 0;
    }
}

//@ f_015be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist das Flag p2 == 1 gesetzt, gibt die Funktion die Tabelle der Kartenänderungen (t33) frei
 *   und setzt den Zeiger auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Betroffen ist das Zeigerfeld t33 (+0x33).
 === Ende Beschreibung === */
void AMap::f_015be0(int p2)
{
    if (p2 == 1) {
        delete t33;
        t33 = 0;
    }
}

//@ f_015c00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist p2 == 1, gibt die Funktion das Grafikobjekt (i3b) und den Rohpixelpuffer (d37) der großen
 *   Karte frei und nullt beide Zeiger.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Betroffen sind die Felder i3b (+0x3b) und d37 (+0x37).
 === Ende Beschreibung === */
void AMap::f_015c00(int p2)
{
    if (p2 != 1) return;
    delete i3b;
    i3b = 0;
    delete d37;
    d37 = 0;
}

//@ f_015c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist p2 == 1, gibt die Funktion das Grafikobjekt (i43) und den Rohpixelpuffer (d3f) der
 *   Übersichtskarte frei und nullt beide Zeiger.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Betroffen sind die Felder i43 (+0x43) und d3f (+0x3f).
 === Ende Beschreibung === */
void AMap::f_015c40(int p2)
{
    if (p2 != 1) return;
    delete i43;
    i43 = 0;
    delete d3f;
    d3f = 0;
}

//@ f_015c80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist p2 == 1, baut die Funktion die Kartennotiz-Verwaltung (s4f, speichert dabei offene
 *   Änderungen) und das Stecknadelsymbol (i4b) ab, setzt beide Zeiger auf 0 und löscht im Sondermodus (s109 ==
 *   2) den Hilfsdateinamen d_1a9664.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Betroffen sind s4f (+0x4f), i4b (+0x4b), s109 (+0x109) und die globale
 *   Dateinamen-Vorgabe d_1a9664.
 === Ende Beschreibung === */
void AMap::f_015c80(int p2)
{
    if (p2 == 1) {
        delete s4f;
        delete i4b;
        s4f = 0;
        i4b = 0;
        if (s109 == 2) d_1a9664 = 0;
    }
}

//@ f_015ce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist p2 == 1, gibt die Funktion das Arbeitsbild i73 sowie alle 8 Markierungsbilder im53[0..7]
 *   frei und setzt deren Zeiger auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und liefert
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Betroffen sind i73 (+0x73) und das Array im53[0..7] (+0x53).
 === Ende Beschreibung === */
void AMap::f_015ce0(int p2)
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

//@ f_015d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist p2 == 1, gibt die Funktion für alle cnt angelegten Gruppenmarker die Richtungspfeil-Bilder
 *   (sl[i].i81) und die gesicherten Hintergrundausschnitte (sl[i].i85) frei und setzt die Markeranzahl cnt auf
 *   0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Flag p2 (int) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Betroffen sind das Marker-Array sl[0..5] (+0x77) und der Zähler cnt (+0xef).
 === Ende Beschreibung === */
void AMap::f_015d40(int p2)
{
    if (p2 == 1) {
        for (short i = 0; i < cnt; i++) {
            delete sl[i].i81;
            sl[i].i81 = 0;
            delete sl[i].i85;
            sl[i].i85 = 0;
        }
        cnt = 0;
    }
}

//@ f_015dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet die Archivdatei id, überliest deren 14-Byte-Kopf, überspringt n
 *   Rasterblöcke und liest den n-ten Block in das übergebene Rasterobjekt g ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), das Zielraster g (Grid *), die
 *   Archivkennung id (unsigned long) und den Blockindex n (short); sie hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt wird der globale Dateimanager d_1c2098.
 === Ende Beschreibung === */
void AMap::f_015dc0(Grid *g, unsigned long id, short n)
{
    char h[14];
    d_1c2098.f_1448b0(id, 0x200);
    d_1c2098.f_144920(h, 0xe);
    d_1c2098.f_144ab0(n * g->f_04fd40(), 1);
    d_1c2098.f_144920(g->f_04fd30(), g->f_04fd40());
    d_1c2098.f_1449a0();
}

//@ f_015e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Für eine eingetragene Kartenänderung (p2->a = Index in der Änderungstabelle t33, p2->b =
 *   Zustand/Variante, z. B. offene oder geschlossene Tür) lädt die Funktion den zugehörigen 6x6-Rasterblock aus
 *   der Datei fid + 4 und kopiert alle von null verschiedenen Zellen an die Zielposition (s3 / 3, s5 / 3) in das
 *   Geländeraster g2f.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den Änderungseintrag p2 (Pr *) und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden die Änderungstabelle t33 (+0x33), das Geländeraster g2f (+0x2f) und die
 *   Archivdatei fid + 4.
 === Ende Beschreibung === */
void AMap::f_015e30(Pr *p2)
{
    char h[14];
    Ent7 e = t33[p2->a];
    e.s3 /= (short)3;
    e.s5 /= (short)3;
    Grid *g;
    unsigned short i;
    short y;
    {
        short yy;
        g = new (mark(d_1a01ec, 0x5b7)) Grid(6, 6, 0);
        short n = (short)p2->b + *(int *)&e; // Adressnahme &e haelt die Stapelplatzfolge wie im Original
        d_1c2098.f_1448b0(fid + 4, 0x200);
        d_1c2098.f_144920(h, 0xe);
        d_1c2098.f_144ab0((short)(n & 0xffff) * g->f_04fd40(), 1); // Haelt die Registerzuteilung (edi/esi) wie im Original
        d_1c2098.f_144920(g->f_04fd30(), g->f_04fd40());
        d_1c2098.f_1449a0();
        y = e.s5;
        for (i = 0; i < 6; y++, i++) {
            unsigned short j;
            short x = 0;
            yy = y;
            x = e.s3;
            for (j = 0; j < 6; x++, j = j + 1) {
                unsigned v = g->f_04fd60(j, i);
                if (v)
                    g2f->f_04fdb0(x, yy, v);
            }
        }
    }
    delete g;
}
//@ f_015fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Passend zur Rasteränderung in f_015e30 lädt diese Funktion für den Änderungseintrag p2 das
 *   zugehörige 18x18 Pixel große Teilbild (Index a0 + b) aus der Archivdatei fid + 3 und zeichnet es an der
 *   Pixelposition (s3, s5) in das große Kartenbild i3b ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den Änderungseintrag p2 (Pr *) und
 *   liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Änderungstabelle t33 (+0x33), das große Kartenbild i3b (+0x3b) und
 *   der Grafikarchiv-Leser d_1c2be0.
 === Ende Beschreibung === */
void AMap::f_015fd0(Pr *p2)
{
    Ent7 *q = &t33[p2->a];
    RivaRasterImage *im = new (mark(d_1a01ec, 0x5e3)) RivaRasterImage(0x12, 0x12);
    d_1c2be0.f_04fef0(fid + 3, ((int)(((RivaRasterImage*)(im))->f_0fb0b0())), 0, (short)(p2->b + q->a0), 0, 0x140);
    i3b->f_0fb3a0(im, q->s3, q->s5, 1);
    delete im;
}

//@ f_016080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion durchläuft über einen Iter-Iterator (am01b420) sämtliche für die aktuelle Karte
 *   id im Spielstand vermerkten Kartenänderungen und überträgt jede davon per f_015e30 in das Geländeraster g2f.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden die aktuelle Kartennummer id (+0x00) und die Änderungsliste aus am01b420
 *   (f_01b890, f_01ba50, f_01bb60).
 === Ende Beschreibung === */
void AMap::f_016080()
{
    Iter it(-1);
    it.f_01b890(id);
    Pr *p = it.f_01ba50();
    while (p != 0) {
        f_015e30(p);
        p = it.f_01bb60();
    }
}

//@ f_0160d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion sichert die aktuelle Archivbank (d_1c14c4), durchläuft alle für die Karte id
 *   gespeicherten Kartenänderungen, zeichnet deren 18x18-Teilbilder über f_015fd0 in die große Karte ein und
 *   stellt anschließend die Archivbank wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden id (+0x00), das Bank-Objekt d_1c14c4 und der Änderungslisten-Iterator.
 === Ende Beschreibung === */
void AMap::f_0160d0()
{
    Iter it(-1);
    it.f_01b890(id);
    short s = d_1c14c4.f_13fc70();
    Pr *p = it.f_01ba50();
    while (p != 0) {
        f_015fd0(p);
        p = it.f_01bb60();
    }
    d_1c14c4.f_13fcd0(s);
}

//@ f_016140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion trägt ein 16-Bit-Änderungspaar p2 (Tabellenindex und Variante) über f_01b8a0
 *   (am01b420) dauerhaft für die aktuelle Karte id in die Punkt-/Änderungsdatei des Spielstands ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie den gepackten Änderungswert p2
 *   (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt wird die aktuelle Kartennummer id (+0x00).
 === Ende Beschreibung === */
void AMap::f_016140(int p2)
{
    Iter it(-1);
    it.f_01b890(id);
    it.f_01b8a0(p2);
}

//@ f_016180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liegt die übergebene Rasterkoordinate (x, y) innerhalb der Kartengrenzen (0 <= x < gw1f und 0
 *   <= y < gh21), verknüpft die Funktion den bisherigen Wert der Zelle im Erkundungsraster g2b per Bit-ODER mit
 *   den neuen Erkundungsbits v.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), die Rasterkoordinaten x und y
 *   (unsigned short) sowie die Bitmaske v (unsigned) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Betroffen ist das Erkundungsraster g2b (+0x2b) mit den Grenzen gw1f (+0x1f) und gh21
 *   (+0x21).
 === Ende Beschreibung === */
void AMap::f_016180(unsigned short x, unsigned short y, unsigned v)
{
    if (0 <= x && x < gw1f && 0 <= y && y < gh21) {
        g2b->f_04fdb0(x, y, v | g2b->f_04fd60(x, y));
    }
}

//@ f_0161d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion berechnet über f_0cdd50 eine Punktlinie von der Startzelle (x0, y0) zur Zielzelle
 *   (x1, y1) und markiert die Zellen entlang des Strahls im Erkundungsraster g2b mit Bit 1 als selbst gesehen.
 *   Der Sichtstrahl bricht am Kartenrand, an einer Wand (g2f == 0), nach mehr als zwei Sonderzellen (g2f == 3,
 *   z. B. Türrahmen) oder am ersten normalen Feld hinter einer Sonderzelle sofort ab.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie Start- (x0, y0) und Zielzelle
 *   (x1, y1, jeweils unsigned short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden der Linienpuffer pts[100] (+0x113), das Geländeraster g2f (+0x2f) und das
 *   Erkundungsraster g2b (+0x2b).
 === Ende Beschreibung === */
void AMap::f_0161d0(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1)
{
    unsigned v;
    short y, x;
    short n;
    short i;
    int c;
    c = 0;
    n = f_0cdd50((short)x0, (short)y0, (short)x1, (short)y1, pts);
    for (i = 1; i < n; i++) {
        x = pts[i].x;
        y = pts[i].y;
        if (x < 0 || x >= gw1f || y < 0 || y >= gh21) return;
        v = g2f->f_04fd60(x, y);
        if (v == 3) c++;
        if (c > 2) return;
        if (c > 0 && v != 3) return;
        if (v == 0) return;
        f_016180(x, y, 1);
    }
}
//@ f_016300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion markiert die eigene Rasterzelle (x, y) als gesehen (Bit 1) und schickt von dort
 *   aus 72 Sichtstrahlen anhand der Richtungsvektortabelle d_1a020c[0..71] über f_0161d0 nach außen, um den
 *   Sichtbereich der Gruppe aufzudecken.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie die Rasterzelle x, y (unsigned
 *   short) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden das Erkundungsraster g2b (+0x2b) und die globale Tabelle d_1a020c mit 72
 *   Richtungsvektoren.
 === Ende Beschreibung === */
void AMap::f_016300(unsigned short x, unsigned short y)
{
    short i;
    unsigned short x1, y1;
    if (0 <= x && x < gw1f && 0 <= y && y < gh21) {
        g2b->f_04fdb0(x, y, g2b->f_04fd60(x, y) | 1);
    }
    i = 0;
    for (; i < 0x48; i++) {
        x1 = x + d_1a020c[i].dx;
        y1 = y + d_1a020c[i].dy;
        f_0161d0(x, y, x1, y1);
    }
}

#include <stdlib.h>
struct AMap2XY493 { unsigned short x, y; };
extern int amap2_d_1a0102;                    // 0x1A0102
#pragma aux amap2_d_1a0102 "d_1a0102"
extern int amap2_d_1a01d4;                    // 0x1A01D4
#pragma aux amap2_d_1a01d4 "d_1a01d4"
extern int amap2_d_1a01e0;                    // 0x1A01E0
#pragma aux amap2_d_1a01e0 "d_1a01e0"
extern int amap2_d_1a01ea;                    // 0x1A01EA
#pragma aux amap2_d_1a01ea "d_1a01ea"
extern int amap2_d_1a0208;                    // 0x1A0208
#pragma aux amap2_d_1a0208 "d_1a0208"
extern AMap2XY493 amap2_d_1a020c[];
#pragma aux amap2_d_1a020c "d_1a020c"
extern int amap2_d_1a032c;                    // 0x1A032C
#pragma aux amap2_d_1a032c "d_1a032c"
extern int amap2_d_1a032e;                    // 0x1A032E
#pragma aux amap2_d_1a032e "d_1a032e"
extern int amap2_d_1a0330;                    // 0x1A0330
#pragma aux amap2_d_1a0330 "d_1a0330"
extern int amap2_d_1a0332;                    // 0x1A0332
#pragma aux amap2_d_1a0332 "d_1a0332"
extern int amap2_d_1a0388;                    // 0x1A0388
#pragma aux amap2_d_1a0388 "d_1a0388"
extern int amap2_d_1a038c;                    // 0x1A038C
#pragma aux amap2_d_1a038c "d_1a038c"
extern int amap2_d_1a0468;                    // 0x1A0468
#pragma aux amap2_d_1a0468 "d_1a0468"
extern char *amap2_d_1a34e0;
#pragma aux amap2_d_1a34e0 "d_1a34e0"
extern int amap2_d_1a9664;                    // 0x1A9664
#pragma aux amap2_d_1a9664 "d_1a9664"
extern int amap2_d_1b641c;                    // 0x1B641C
#pragma aux amap2_d_1b641c "d_1b641c"
extern int amap2_d_1bc718;                    // 0x1BC718
#pragma aux amap2_d_1bc718 "d_1bc718"
extern short amap2_d_1bc726;
#pragma aux amap2_d_1bc726 "d_1bc726"
extern short amap2_d_1bc728;
#pragma aux amap2_d_1bc728 "d_1bc728"
extern short amap2_d_1bc72a;
#pragma aux amap2_d_1bc72a "d_1bc72a"
extern short amap2_d_1bc72c;
#pragma aux amap2_d_1bc72c "d_1bc72c"
extern int amap2_d_1bc730;                    // 0x1BC730
#pragma aux amap2_d_1bc730 "d_1bc730"
extern int amap2_d_1bc734;                    // 0x1BC734
#pragma aux amap2_d_1bc734 "d_1bc734"
extern int amap2_d_1bc738;                    // 0x1BC738
#pragma aux amap2_d_1bc738 "d_1bc738"
extern int amap2_d_1bc73a;                    // 0x1BC73A
#pragma aux amap2_d_1bc73a "d_1bc73a"
extern int amap2_d_1bc73c;                    // 0x1BC73C
#pragma aux amap2_d_1bc73c "d_1bc73c"
extern int amap2_d_1bc73e;                    // 0x1BC73E
#pragma aux amap2_d_1bc73e "d_1bc73e"
extern int amap2_d_1bc740;                    // 0x1BC740
#pragma aux amap2_d_1bc740 "d_1bc740"
extern int amap2_d_1bc742;                    // 0x1BC742
#pragma aux amap2_d_1bc742 "d_1bc742"
extern int amap2_d_1bc744;                    // 0x1BC744
#pragma aux amap2_d_1bc744 "d_1bc744"
extern int amap2_d_1bc746;                    // 0x1BC746
#pragma aux amap2_d_1bc746 "d_1bc746"
extern int amap2_d_1bc748;                    // 0x1BC748
#pragma aux amap2_d_1bc748 "d_1bc748"
extern int amap2_d_1bc754;                    // 0x1BC754
#pragma aux amap2_d_1bc754 "d_1bc754"
extern int amap2_d_1bd760;                    // 0x1BD760
#pragma aux amap2_d_1bd760 "d_1bd760"
extern int amap2_d_1bd762;                    // 0x1BD762
#pragma aux amap2_d_1bd762 "d_1bd762"
extern int amap2_d_1bd766;                    // 0x1BD766
#pragma aux amap2_d_1bd766 "d_1bd766"
extern int amap2_d_1bf4f0;                    // 0x1BF4F0
#pragma aux amap2_d_1bf4f0 "d_1bf4f0"
extern int amap2_d_1bf4f2;                    // 0x1BF4F2
#pragma aux amap2_d_1bf4f2 "d_1bf4f2"
extern int amap2_d_1bf4f8;                    // 0x1BF4F8
#pragma aux amap2_d_1bf4f8 "d_1bf4f8"
extern int amap2_d_1bf4fa;                    // 0x1BF4FA
#pragma aux amap2_d_1bf4fa "d_1bf4fa"
extern int amap2_d_1bf510;                    // 0x1BF510
#pragma aux amap2_d_1bf510 "d_1bf510"
extern int amap2_d_1bf51c;                    // 0x1BF51C
#pragma aux amap2_d_1bf51c "d_1bf51c"
extern int amap2_d_1bfdb8;                    // 0x1BFDB8
#pragma aux amap2_d_1bfdb8 "d_1bfdb8"
extern int amap2_d_1bfdbc;                    // 0x1BFDBC
#pragma aux amap2_d_1bfdbc "d_1bfdbc"
extern int amap2_d_1c0004;                    // 0x1C0004
#pragma aux amap2_d_1c0004 "d_1c0004"
extern int amap2_d_1c0c4c;                    // 0x1C0C4C
#pragma aux amap2_d_1c0c4c "d_1c0c4c"
extern int amap2_d_1c0c94;                    // 0x1C0C94
#pragma aux amap2_d_1c0c94 "d_1c0c94"
extern int amap2_d_1c14c4;                    // 0x1C14C4
#pragma aux amap2_d_1c14c4 "d_1c14c4"
extern int amap2_d_1c2098;                    // 0x1C2098
#pragma aux amap2_d_1c2098 "d_1c2098"
extern int amap2_d_1c21b4;                    // 0x1C21B4
#pragma aux amap2_d_1c21b4 "d_1c21b4"
extern int amap2_d_1c2a80;                    // 0x1C2A80
#pragma aux amap2_d_1c2a80 "d_1c2a80"
extern int amap2_d_1c2be0;                    // 0x1C2BE0
#pragma aux amap2_d_1c2be0 "d_1c2be0"
extern int amap2_d_1c2c64;                    // 0x1C2C64
#pragma aux amap2_d_1c2c64 "d_1c2c64"
extern int amap2_d_1c38b0;                    // 0x1C38B0
#pragma aux amap2_d_1c38b0 "d_1c38b0"
extern int amap2_d_1c3910;                    // 0x1C3910
#pragma aux amap2_d_1c3910 "d_1c3910"
extern const char amap2_d_1a01ec[];           // Text 0x1A01EC
#pragma aux amap2_d_1a01ec "d_1a01ec"
struct ContextAMap2 { public:
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
static void *f_01afd0(int p1, int);
static int f_01b060(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b0a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b140(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b230(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_01b320(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_01b3b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_01b860(int p1, int p2);                           // reg eax edx stapel 0
static int f_01b860(int p1);                                   // f_016bc0: orig uebergibt nur eax
static int f_01b880(int, int);                                         // reg - stapel 0
static int f_01b890(int p1, int p2);                           // reg eax edx stapel 0
static int f_01b8a0(int p1, int p2);                           // reg eax edx stapel 0
static int f_01ba50(int p1);                                   // reg eax stapel 0
static int f_01bb60(int p1);                                   // reg eax stapel 0
static int f_04fc60(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static void *f_04fce0(int p1, int);
static int f_04fcf0(int p1, int p2);                           // reg eax edx stapel 0
static int f_04fd30(int p1);                                   // reg eax stapel 0
static int f_04fd40(int p1);                                   // reg eax stapel 0
static int f_04fd60(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_04fdb0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_04fe30(int p1, int p2);
static int f_04fe60(int p1, int);
static int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
static int f_050580(int p1, int p2, int p3, int p4);
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
static unsigned short f_0696e0(int p1);                        // reg eax stapel 0
static int f_0696f0(int p1, int p2);                           // reg eax edx stapel 0
static int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
static int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
static int f_0cdd50(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
static int f_0ce650();                                         // reg - stapel 0
static int f_0ce7c0(int p1);                                   // reg eax stapel 0
static int f_0d26e0();                                         // reg - stapel 0
static int f_0d2710();                                         // reg - stapel 0
static int f_0d2e70();                                         // reg - stapel 0
static int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
static int f_0d3390(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_0d3420(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
static int f_0d37e0();                                         // reg - stapel 0
static int f_0d3800();                                         // reg - stapel 0
static int f_0d3810();                                         // reg - stapel 0
static int f_0d3860();                                         // reg - stapel 0
static int f_0da910();                       // nicht in clobber.tsv
static int f_0da990(int p1);                                   // reg eax stapel 0
static int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0dacc0(int p1);                                   // reg eax stapel 0
static int f_0de7c0(int p1);                                   // reg eax stapel 0
static int f_0de820(int p1);                                   // reg eax stapel 0
static int f_0de840(int p1);                                   // reg eax stapel 0
static int f_0de880(int p1);                                   // reg eax stapel 0
static int f_0de8c0(int p1);                                   // reg eax stapel 0
static int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0fabf0(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0

           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0

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
static int f_1459d0(int p1);                                   // reg eax stapel 0
static int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
static int f_145b10(int p1);                                   // reg eax stapel 0
static int f_145b40(int p1);                                   // reg eax stapel 0
static int f_145b80(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (74), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

struct B10 { char d[10]; };
struct B9 { char d[9]; };
#define I(o) (*(int *)(p1 + (o)))
#define S(o) (*(short *)(p1 + (o)))
#define SQ(o) (*(signed char *)(p1 + (o)))
#define A(x) ((int)&(x))
#define TS short
#define CH signed char
#define DV(x) ((x) / 65536)
static void f_015190(int);
static void f_015280(int);
static void f_015310(int, int);
static void f_0153c0(int);
static void f_015450(int);
static void f_0155e0(int);
static void f_0156f0(int);
static void f_015af0(int, int);
static void f_015d40(int, int);
static void f_015e30(int, int);
static void f_015fd0(int, int);
static void f_0161d0(int, TS, TS, TS, TS);
static int f_0696f0(int, unsigned short);
static int f_050580(int, int, int, int, int);
static void f_0163b0(int p1, TS p2, TS p3, TS p4, TS p5);
static void f_0164b0(int p1, unsigned short p2, unsigned short p3);
static void f_016580(int p1, int p2);
static void f_016660(int p1, int p2, int p3, int p4);
static void f_016800(int p1);
static void f_016850(int p1);
static void f_0168f0(int p1, int p2);
static void f_0169b0(int p1);
static void f_016bc0(int p1);
static void f_016f50(int p1);
static void f_016fd0(int p1, short p2);
static void f_017280(int p1);
static void f_0174b0(int p1, short p2, short p3, short p4, short p5, short w, unsigned char val);
static void f_017530(int p1, short p2, short p3);
};
//@ f_0163b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ähnlich wie f_0161d0 zieht die Funktion eine Linie von (x0, y0) nach (x1, y1), bricht jedoch
 *   an Wänden nicht ab, sondern setzt in allen auf dem Strahl liegenden Zellen mit Geländewert != 0 das
 *   Erkundungsbit 2 (aufgedeckt, ohne selbst gesehen zu sein).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie Start- und Zielzelle (x0, y0, x1,
 *   y1, jeweils unsigned short) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden pts (+0x113), g2f (+0x2f) und g2b (+0x2b).
 === Ende Beschreibung === */
void ContextAMap2::f_0163b0(int p1, TS p2, TS p3, TS p4, TS p5)
{
    unsigned v;
    short y, x;
    short n;
    short i;
    n = f_0cdd50(p2, p3, p4, p5, p1 + 0x113);
    for (i = 1; i < n; i++) {
        x = *(short *)(p1 + 0x113 + i * 4);
        y = *(short *)(p1 + 0x115 + i * 4);
        if (x < 0 || x >= *(short *)(p1 + 0x1f) || y < 0 || y >= *(short *)(p1 + 0x21)) return;
        v = f_04fd60(*(int *)(p1 + 0x2f), (unsigned short)x, (unsigned short)y);
        if (v != 0 && (int)(unsigned short)x >= 0 && (unsigned short)x < *(short *)(p1 + 0x1f) && (int)(unsigned short)y >= 0 && (unsigned short)y < *(short *)(p1 + 0x21)) {
            f_04fdb0(*(int *)(p1 + 0x2b), (unsigned short)x, (unsigned short)y, f_04fd60(*(int *)(p1 + 0x2b), (unsigned short)x, (unsigned short)y) | 2);
        }
    }
}
//@ f_0164b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt in der Zelle (x, y) das Erkundungsbit 2 und sendet anschließend alle 72
 *   Strahlen aus d_1a020c über f_0163b0 (ohne Wandstopp) aus, um einen Umkreis auch durch Wände hindurch
 *   aufzudecken (z. B. für magische Kartenaufdeckung in amap_t345 f_019db0).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie die Rasterzelle x, y (unsigned
 *   short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden g2b (+0x2b) und die Vektortabelle d_1a020c.
 === Ende Beschreibung === */
void ContextAMap2::f_0164b0(int p1, unsigned short p2, unsigned short p3)
{
    short i;
    unsigned short x1, y1;
    if (!(0 <= p2 && p2 < S(0x1f) && 0 <= p3 && p3 < S(0x21))) return;
    if (0 <= p2 && p2 < S(0x1f) && 0 <= p3 && p3 < S(0x21)) {
        f_04fdb0(I(0x2b), p2, p3, f_04fd60(I(0x2b), p2, p3) | 2);
    }
    i = 0;
    for (; i < 0x48; i++) {
        x1 = p2 + amap2_d_1a020c[i].x;
        y1 = p3 + amap2_d_1a020c[i].y;
        ((void (*)(int, unsigned short, unsigned short, unsigned short, unsigned short))f_0163b0)(p1, p2, p3, x1, y1);
    }
}
//@ f_016580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist eine Karte geöffnet (id != -1), speichert die Funktion bei p2 == 1 das Erkundungsraster im
 *   Spielstand (f_015af0(1)) bzw. verwirft es bei p2 != 1, gibt Geländeraster und Änderungstabelle frei und
 *   setzt alle Kartenmaße sowie die Kartennummer id = -1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) sowie das Speicherflag p2 (1 =
 *   Erkundung sichern, 0 = verwerfen) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Betroffen sind id (+0x00), g2b (+0x2b), g2f (+0x2f), t33 (+0x33) sowie die Maßfelder
 *   +0x05 bis +0x21.
 === Ende Beschreibung === */
void ContextAMap2::f_016580(int p1, int p2)
{
    int t;
    if (p2 == 1) {
        f_015af0(p1, 1);
        int owner = p1;
        int a = I(0x2f);
        if (a != 0) operator delete(f_04fce0(a, 0));
        *(int *)(owner + 0x2f) = 0;
        t = I(0x33);
    } else {
        int a = I(0x2b);
        if (a != 0) operator delete(f_04fce0(a, 0));
        int b = I(0x2f);
        I(0x2b) = 0;
        if (b != 0) operator delete(f_04fce0(b, 0));
        t = I(0x33);
        *(int *)(p1 + 0x2f) = 0;
    }
    operator delete((void *)t);
    I(0x33) = 0;
    I(0x01) = 0;
    S(0x05) = 0;
    S(0x07) = 0;
    S(0x09) = 0;
    S(0x0b) = 0;
    S(0x0d) = 0;
    S(0x0f) = 0;
    S(0x11) = 0;
    S(0x13) = 0;
    S(0x15) = 0;
    S(0x1f) = 0;
    S(0x21) = 0;
    I(0x23) = 0;
    I(0x27) = 0;
    I(0xf9) = 0;
    *(unsigned char *)p1 = 0xff;
}
//@ f_016660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet die Automap-Daten für die Karte p2 bei der Gruppenposition (p3, p4): sie
 *   berechnet die Archivbasis fid = p2 * 8 + 0x310009, ermittelt die Kartenmaße (f_015280), lädt Gelände- und
 *   Erkundungsraster sowie die Änderungstabelle und spielt alle bisherigen Kartenänderungen der Ebene in das
 *   Geländeraster ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this), die Kartennummer p2 (signed char)
 *   sowie die Kartenpixel-Position p3, p4 (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt werden id (+0x00), fid (+0x01), die Gruppenposition s5/s7 (+0x05/+0x07), g2f
 *   (+0x2f), g2b (+0x2b) und t33 (+0x33).
 === Ende Beschreibung === */
void ContextAMap2::f_016660(int p1, int p2, int p3, int p4)
{
    extern int f_014ab0(int, int);
    struct { char pad[12]; int n; } h1;
    char h2[16];
    char it[8];
    S(5) = (short)p3;
    S(7) = (short)p4;
    *(char *)p1 = (char)p2;
    I(1) = (CH)p2 * 8 + 0x310009;
    f_015280(p1);
    int owner = p1;
    int o = f_014ab0(0xa, (int)mark(amap2_d_1a01ec, 0x26e));
    o = o ? (int)f_04fc60(o, (unsigned short)S(0x1f), (unsigned short)S(0x21), 0) : 0;
    *(int *)(owner + 0x2f) = o;
    ((RivaFileManager*)(A(amap2_d_1c2098)))->f_1448b0( *(int *)(owner + 1) + 2, 0x200);
    ((int)(((RivaFileManager*)(A(amap2_d_1c2098)))->f_144920((void *)( (int)h2), 0x10)));
    int a = f_04fd40(*(int *)(owner + 0x2f));
    int b = f_04fd30(*(int *)(owner + 0x2f));
    ((int)(((RivaFileManager*)(A(amap2_d_1c2098)))->f_144920((void *)( b), a)));
    ((RivaFileManager*)(A(amap2_d_1c2098)))->f_1449a0();
    owner = p1;
    o = f_014ab0(0xa, (int)mark(amap2_d_1a01ec, 0x235));
    o = o ? (int)f_04fc60(o, (unsigned short)S(0x1f), (unsigned short)S(0x21), 0) : 0;
    *(int *)(owner + 0x2b) = o;
    ((RivaFileManager*)(A(amap2_d_1c2098)))->f_1448b0( (*(int *)(owner + 1) + 6) | 0x40000000, 0x200);
    ((int)(((RivaFileManager*)(A(amap2_d_1c2098)))->f_144920((void *)( (int)&h1), 0x10)));
    if ((unsigned)h1.n > 0) {
        a = f_04fd40(*(int *)(owner + 0x2b));
        b = f_04fd30(*(int *)(owner + 0x2b));
        ((int)(((RivaFileManager*)(A(amap2_d_1c2098)))->f_144920((void *)( b), a)));
    }
    ((RivaFileManager*)(A(amap2_d_1c2098)))->f_1449a0();
    f_015190(p1);
    f_01b860((int)it, -1);
    f_01b890((int)it, (CH)*(CH *)p1);
    int observer = p1;
    int q = f_01ba50((int)it);
    while (q != 0) {
        f_015e30(observer, q);
        q = f_01bb60((int)it);
    }
    f_01b880((int)it, 0);
}
//@ f_016800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion durchläuft über den Notiz-Iterator (f_01b060 / f_01b0a0) alle auf der aktuellen
 *   Karte vorhandenen Notizen und zeichnet an jeder Notizkoordinate (x, y) das Stecknadelsymbol i4b in das große
 *   Kartenbild i3b.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Notizverwaltung s4f (+0x4f), das Stecknadelsymbol i4b (+0x4b) und das
 *   große Kartenbild i3b (+0x3b).
 === Ende Beschreibung === */
void ContextAMap2::f_016800(int p1)
{
    short a, b;
    int r = f_01b060(I(0x4f), (int)&a, (int)&b);
    while (r == 1) {
        ((RivaRasterImage*)(I(0x3b)))->f_0fb3a0((RivaRasterImage *)( I(0x4b)), a, b, 1);
        r = f_01b0a0(I(0x4f), (int)&a, (int)&b);
    }
}
//@ f_016850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion stellt unter allen aktiven Gruppenmarkern zunächst den gesicherten
 *   Kartenhintergrund wieder her, gibt die Gruppenmarker frei (f_015d40(1)), zeichnet sämtliche
 *   Notiz-Stecknadeln ein und setzt anschließend die Gruppenmarker über f_0156f0 neu darüber.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden sl[0..cnt-1] (+0x77), s4f (+0x4f), i4b (+0x4b) und i3b (+0x3b).
 === Ende Beschreibung === */
void ContextAMap2::f_016850(int p1)
{
    short a, b;
    void f_0156f0_x(int);
    #pragma aux f_0156f0_x "f_0156f0" parm [eax] modify [esp];
    for (short i = 0; i < SQ(0xef); i++) {
        int k = i * 0x14;
        f_014df0(p1, I(0x3b), *(int *)(p1 + 0x85 + k), *(short *)(p1 + 0x7b + k), *(short *)(p1 + 0x7d + k), 0, -1);
    }
    f_015d40(p1, 1);
    int p = p1;
    if (f_01b060(*(int *)(p + 0x4f), (int)&a, (int)&b) == 1) {
        do {
            ((RivaRasterImage*)(*(int *)(p + 0x3b)))->f_0fb3a0((RivaRasterImage *)( *(int *)(p + 0x4b)), a, b, 1);
        } while (f_01b0a0(*(int *)(p + 0x4f), (int)&a, (int)&b) == 1);
    }
    f_0156f0_x(p1);
}
//@ f_0168f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion lädt das Teilbild 0x18 (Umkreis- bzw. Suchradiussymbol) aus dem Archiveintrag
 *   0x310004 und zeichnet es zentriert auf die aktuelle Gruppenposition (s5, s7) in das übergebene Kartenbild
 *   p2.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und das Zielbild p2 (Img *) und hat
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Gruppenkoordinaten s5 und s7 (+0x05, +0x07).
 === Ende Beschreibung === */
void ContextAMap2::f_0168f0(int p1, int p2)
{
    struct { char pad[0x20]; short w; short w2; short h; short h2; } o;
    f_04fe30((int)&o, 0);
    extern int f_050580(int, int, int, int, int);
    f_050580((int)&o, 0x310004, 0x18, (int)&o.h, (int)&o.w);
    int b = (int)new (mark(amap2_d_1a01ec, 0x7be)) B9;
    b = b ? ((int)(((RivaRasterImage*)(b))->f_0fac80( o.h, o.w))) : b;
    f_04fef0((int)&o, 0x310004, (int)((RivaRasterImage*)(b))->f_0fb0b0(), 0, 0x18, 0, 0x140);
    f_014df0(p1, p2, b, S(5), S(7), 1, -1);
    if (b != 0) operator delete(((void *)(((RivaRasterImage*)(b))->f_0fad20( 0))));
    f_04fe60((int)&o, 0);
}
//@ f_0169b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zeichnet zunächst über f_0168f0 das Umkreissymbol um die Gruppe und durchläuft
 *   anschließend die Ebenen-Objektliste (+0xf9, aus exposami.cpp): für jedes aktive Objekt, dessen euklidischer
 *   Abstand zur Gruppe höchstens 75 Kartenpixel beträgt, wird das zugehörige Objektsymbol aus dem Archiveintrag
 *   0x310003 geladen und auf der großen Karte eingezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden die Objektliste an +0xf9, das große Kartenbild i3b (+0x3b), der
 *   Weltursprung i23/i27 (+0x23/+0x27) und die Gruppenposition s5/s7.
 === Ende Beschreibung === */
// Wurzel als Rechen-Pragma, MooMoos Freigabe 05.11.2026 (nur dieses): js entsteht nicht aus C, ein jmp im Zwischencode loest StraightenCode aus.
extern "C" int w15_inedx(int v);
#pragma aux w15_inedx = "" parm [edx] value [edx] modify exact [edx];
extern "C" unsigned wurzel32(int v);
#pragma aux wurzel32 = "xor eax,eax" "mov edx,1" "L1: sub ebx,edx" "js L2" "inc eax" "add edx,2" "jmp L1" "L2:" parm [ebx] value [eax] modify [ebx edx];
void ContextAMap2::f_0169b0(int p1)
{
    struct H {
        static void pos(int p, short &xp, short &yp, int fx, int fy) {
            xp = ((fx / 65536) - *(int *)(p + 0x23)) / 5;
            yp = ((fy / 65536) - *(int *)(p + 0x27)) / 5;
        }
    };
    short x, w, y, h, s, i;
    f_0168f0(p1, I(0x3b));
    if (I(0xf9) == 0) return;
    s = f_13fc70(A(amap2_d_1c14c4));
    // Haelt die Register- und Stapelgewichtung in der Schleife wie im Original.
    for (i = 0; i < w15_inedx(f_0696e0(I(0xf9))); i++) {
        { short k = s; s = k; }
        { short k = s; s = k; }
        { short k = s; s = k; }
        { short k = i; i = k; }
        { short k = i; i = k; }
        int item = f_0696f0(I(0xf9), (unsigned short)i);
        if (!f_069640(item) || !f_069660(item)) continue;
        H::pos(p1, x, y, f_069690(item), f_0696a0(item));
        int ax = x; { int k = ax; ax = k; }
        short dx = abs(ax - S(5));
        int ay = y; { int k = ay; ay = k; }
        short dy = abs(ay - S(7));
        if (dx != 0 || dy != 0) {
            if (dx > (short)0x4b || dy > (short)0x4b) continue;
            if (wurzel32(dx * dx + dy * dy) >= 0x4b) continue;
        }
        f_050580(A(amap2_d_1c2be0), 0x310003, (short)f_0695c0(item), (int)&h, (int)&w);
        int image = (int)new (mark(amap2_d_1a01ec, 0x7ff)) B9;
        image = image ? ((int)(((RivaRasterImage*)(image))->f_0fac80( h, w))) : image;
        f_04fef0(A(amap2_d_1c2be0), 0x310003, (int)((RivaRasterImage*)(image))->f_0fb0b0(), 0, (short)f_0695c0(item), 0, 0x140);
        f_014df0(p1, I(0x3b), image, x, y, 1, -1);
        if (image != 0) operator delete(((void *)(((RivaRasterImage*)(image))->f_0fad20( 0))));
    }
    f_13fcd0(A(amap2_d_1c14c4), s);
}
//@ f_016bc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion baut das Arbeitsbild der Automap vollständig neu auf: sie gibt eventuelle alte
 *   Kartenbilder frei, lädt große Karte und Übersichtskarte neu, zeichnet alle aktiven Kartenänderungen ein
 *   (f_0160d0), schwärzt alle noch unerkundeten 3x3-Pixel-Zellen (g2b == 0) sowohl auf der großen Karte als auch
 *   auf der Übersichtskarte, zeichnet bei Bedarf Umkreisobjekte (+0x105), Notizsymbole (+0xfd) sowie die
 *   Gruppenmarker (f_0156f0) ein und markiert den Bildschirmausschnitt (s17 = -1) als erneuerungsbedürftig.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden i3b/d37 (große Karte), i43/d3f (Übersichtskarte), g2b (+0x2b,
 *   Erkundungsraster), +0xfd (Notizen anzeigen) und +0x105 (Umkreisobjekte anzeigen).
 === Ende Beschreibung === */
void AMap::f_016bc0() {
struct Draw { static void run(int p1) { short a; union { short full; unsigned char byte[2]; unsigned short word[1]; } b;
int r=ContextAMap2::f_01b060(*(int*)(p1+0x4f),(int)&a, (int)&b.full);
while(r==1) {
                int view_b_0 = b.byte[0]; // Haelt die Stapelplatz- und Registerfolge wie im Original
((RivaRasterImage*)(*(int*)(p1+0x3b)))->f_0fb3a0((RivaRasterImage *)(*(int*)(p1+0x4b)),a,b.full,1);
r=ContextAMap2::f_01b0a0(*(int*)(p1+0x4f),(int)&a, (int)&b.full);
} } };

    ContextAMap2::f_0d2f90(5, 1);
    if ((d37)) f_015c00(1);
    if ((d3f)) f_015c40(1);
    if ((i4b)) f_015c80(1);
    if (cnt > 0) f_015d40(1);
    ContextAMap2::f_069460();
    f_015310();
    ContextAMap2::f_069460();
    f_0160d0();
    f_0153c0();
    ContextAMap2::f_069460();
    f_015450();
    if (!(im53[0])) f_0155e0();
    unsigned short y;
    unsigned short x;
    unsigned short w;
    unsigned short h;
    unsigned short dy;
    unsigned short dx;
    for (y = 0; y < h0f; y += 3) {
        ContextAMap2::f_069460();
        for (x = 0; x < w0d; x += 3) {
            if (g2b->f_04fd60( (unsigned short)(x / 3), (unsigned short)(y / 3)) == 0) {
                w = x + 3 > w0d ? w0d - x : 3;
                h = y + 3 > h0f ? h0f - y : 3;
                for (dy = 0; dy < h; ++dy) {
                    for (dx = 0; dx < w; ++dx) {
                        int adr = dx + (x + (dy + y) * w0d);
                        unsigned char *zgr = d37; d37 = zgr; // Haelt die Registerfolge in der inneren Schleife wie im Original
                        zgr[adr] = 0;
                    }
                }
            }
        }
    }
    {
    unsigned short sx, sy, yy;
    for (yy = 0, sy = 0; yy < h13; ++yy, sy += s15) {
        unsigned short sc = sy; sy = sc; // Haelt die Registerfolge fuer sy wie im Original
        int src = sy * w0d;
        {
            int row = yy * w11;
            struct Gr { static int hole(AMap *m) { int k = amap2_d_1a032c; int r = m->w11; amap2_d_1a032c = k; return r; } }; // Haelt die Auswertung von w11 in der Schleifenbedingung wie im Original
            for (dx = 0, sx = 0; dx < Gr::hole(this); ++dx, sx += s15) {
                if (((signed char *)d37)[src + sx] == 0) {
                    char *rund = d_1a9664; d_1a9664 = rund; // Haelt die Registerfolge wie im Original
                    d3f[row + (unsigned)dx] = 0;
                }
            }
        }
    }
    }
    if ((*(int *)(pf9 + 12)) == 1) ContextAMap2::f_0169b0((int)this);
    if ((*(int *)(pf9 + 4)) == 1) Draw::run((int)this);
    ContextAMap2::f_069460();
    f_0156f0();
    (*(short *)(p17)) = -1;
    (*(short *)(p17 + 2)) = -1;
    (*(short *)(p17 + 4)) = -1;
    (*(short *)(p17 + 6)) = -1;
    char *same = d_1a9664; d_1a9664 = same; // Haelt die Register- und Stapelzuteilung wie im Original
    ContextAMap2::f_0d2e70();
}
//@ f_016f50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zeichnet den 3x3 Pixel großen Kartencursor an seiner Position (s9, sb) relativ
 *   zum aktuellen Kartenausschnitt (s17, s19) direkt in den Bildschirmpuffer d_1a34e0, wobei die Farbe über das
 *   Feld +0x10f zwischen 0xf9 und 0xff gewählt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Cursorposition s9/sb (+0x09/+0x0b), der Ausschnittursprung s17/s19
 *   (+0x17/+0x19), der Farbschalter +0x10f und der Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void ContextAMap2::f_016f50(int p1)
{
    char o[12];
    f_0fabf0((int)o);
    short l1 = S(9) - S(0x17) - 1;
    short l2 = S(0xb) - S(0x19) - 1;
    int t;
    if (I(0x10f) == 1) t = A(amap2_d_1a01e0); else t = A(amap2_d_1a01d4);
    ((RivaRasterImage*)((int)o))->f_0fad50( 3, 3,(void *)( t));
    ((RivaRasterImage*)((int)o))->f_0fade0((void *)( (int)amap2_d_1a34e0), (short)(l1 + 3), (short)(l2 + 3));
    ((void *)(((RivaRasterImage*)((int)o))->f_0fad20( 0)));
}
//@ f_016fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zeichnet den Gruppenmarker mit Index idx: handelt es sich um die aktive
 *   Spielergruppe (sl[idx].fl == 1), wird im Arbeitsbild i73 ein Komposit aus gesichertem Hintergrund,
 *   Richtungspfeil und Markierungssymbol zusammengesetzt und in die große Karte (sowie bei sichtbarem Fenster
 *   direkt in das Kartenfenster i47) kopiert; andere Gruppen erhalten ihren Richtungspfeil und ein farbiges
 *   Markierungssymbol (im53[5] bzw. im53[7]).
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und den Markerindex idx (int) und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden sl[idx] (+0x77), das Arbeitsbild i73 (+0x73), die Markierungsbilder
 *   im53[0..7] (+0x53), die große Karte i3b (+0x3b) und das Kartenfenster i47 (+0x47).
 === Ende Beschreibung === */
void ContextAMap2::f_016fd0(int p1, short p2)
{
    extern int f_0d2710_local();
#pragma aux f_0d2710_local "f_0d2710" modify [esp]
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710_local(); fl = 1; } else fl = 0; }
        ~MG() { if (fl == 1) f_0d26e0(); }
    };
    if (*(int *)(p1 + p2 * 0x14 + 0x77) == 1) {
        int n = S(0xf1) * S(0xf3);
        memcpy(((RivaRasterImage*)(I(0x73)))->f_0fb0b0(), ((RivaRasterImage*)(*(int *)(p1 + p2 * 0x14 + 0x85)))->f_0fb0b0(), n);
        ((RivaRasterImage*)(I(0x73)))->f_0fb3a0((RivaRasterImage *)( *(int *)(p1 + p2 * 0x14 + 0x81)), 0, 0, 1);
        ((RivaRasterImage*)(I(0x73)))->f_0fb3a0((RivaRasterImage *)( *(int *)(*(short *)(p1 + p2 * 0x14 + 0x89) * 4 + p1 + 0x53)), (short)((S(0xf1) - S(0xf5)) / 2), (short)((S(0xf3) - S(0xf7)) / 2), 1);
        f_014df0(p1, I(0x3b), I(0x73), *(short *)(p1 + p2 * 0x14 + 0x7b), *(short *)(p1 + p2 * 0x14 + 0x7d), 0, -1);
        if (*(short *)(p1 + p2 * 0x14 + 0x7b) + S(0xf5) / 2 >= S(0x17) &&
            *(short *)(p1 + p2 * 0x14 + 0x7d) + S(0xf7) / 2 >= S(0x19) &&
            *(short *)(p1 + p2 * 0x14 + 0x7b) - S(0xf5) / 2 < S(0x17) + 0xc2 &&
            *(short *)(p1 + p2 * 0x14 + 0x7d) - S(0xf7) / 2 < S(0x19) + 0xc2) {
            MG mg;
            f_014df0(p1, I(0x47), I(0x73), (short)(*(short *)(p1 + p2 * 0x14 + 0x7b) - S(0x17)), (short)(*(short *)(p1 + p2 * 0x14 + 0x7d) - S(0x19)), 0, 0x140);
        }
    } else {
        f_014df0(p1, I(0x3b), *(int *)(p1 + p2 * 0x14 + 0x81), *(short *)(p1 + p2 * 0x14 + 0x7b), *(short *)(p1 + p2 * 0x14 + 0x7d), 1, -1);
        f_014df0(p1, I(0x3b), I(0x67), *(short *)(p1 + p2 * 0x14 + 0x7b), *(short *)(p1 + p2 * 0x14 + 0x7d), 1, -1);
        f_014df0(p1, I(0x3b), I(0x6f), *(short *)(p1 + p2 * 0x14 + 0x7b), *(short *)(p1 + p2 * 0x14 + 0x7d), 1, -1);
    }
}
//@ f_017280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion berechnet den 194x194 Pixel (0xc2 x 0xc2) großen Kartenausschnitt zentriert um
 *   den Kartencursor (s9, sb) (begrenzt auf die Kartenränder), kopiert bei einer Verschiebung des Ausschnitts
 *   das neue Teilbild in das Kartenfenster und aktualisiert, falls gerade kein Notiztext im Infofeld steht
 *   (d_1bc754 == 0), auch die Übersichtskarte samt Ausschnittrahmen (f_017530); zuletzt wird der 3x3-Cursorpunkt
 *   eingezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden s9/sb (Cursor), s17/s19 (Ausschnitt links/oben), i3b (große Karte), i47
 *   (+0x47, Kartenfenster im Bildschirmpuffer d_1a34e0) und das Flag d_1bc754 (Infofeld durch Notiztext belegt).
 === Ende Beschreibung === */
void ContextAMap2::f_017280(int p1)
{
    int fl=0;
    char o[12];
    int a;
    if (amap2_d_1bc754 == 0) {
        amap2_d_1bc726 = S(9) - 0x61;
        amap2_d_1bc728 = S(0xb) - 0x61;
        if (amap2_d_1bc726 + 0xc2 > S(0xd))
            amap2_d_1bc726 = S(0xd) - 0xc2;
        if (amap2_d_1bc728 + 0xc2 > S(0xf))
            amap2_d_1bc728 = S(0xf) - 0xc2;
        if (amap2_d_1bc726 < 0)
            amap2_d_1bc726 = 0;
        if (amap2_d_1bc728 < 0)
            amap2_d_1bc728 = 0;
        if (amap2_d_1bc726 + 0xc2 > S(0xd))
            a = S(0xd) - amap2_d_1bc726;
        else
            a = 0xc2;
        int y = amap2_d_1bc728;
        a=(a&0)?0:a; a=(a&0)?0:a; // Haelt die Registerfolge fuer die Breitenberechnung wie im Original
        amap2_d_1bc72a = a;
        int end = y + 0xc2;
        int limit = S(0xf);
        int height901; if(end>limit){height901=limit-y;}else height901=0xc2; amap2_d_1bc72c=height901;
    }
    int r = f_0d3420(0xd6, 0, 0x13f, 0x3e);
    if(r==0) { int on901=f_0d3860(); if(on901==1){ fl=on901; f_0d2710(); } }
    ((RivaRasterImage*)(I(0x3b)))->f_0fb3e0((char *)( (int)(amap2_d_1a34e0 + 0x3c3)), 0x140, amap2_d_1bc726, amap2_d_1bc728, amap2_d_1bc72a, amap2_d_1bc72c, 0);
    if (amap2_d_1bc754 == 0 && (amap2_d_1bc726 != S(0x17) || amap2_d_1bc728 != S(0x19))) {
        S(0x17) = amap2_d_1bc726;
        S(0x19) = amap2_d_1bc728;
        f_017530(p1, amap2_d_1bc726, amap2_d_1bc728);
    }
    f_0fabf0((int)o);
    short l1 = S(9) - S(0x17) - 1;
    short l2 = S(0xb) - S(0x19) - 1;
    int t;
    t = (I(0x10f) == 1) ? A(amap2_d_1a01e0) : A(amap2_d_1a01d4);
    ((RivaRasterImage*)((int)o))->f_0fad50( 3, 3,(void *)( t));
    ((RivaRasterImage*)((int)o))->f_0fade0((void *)( (int)amap2_d_1a34e0), (short)(l1 + 3), (short)(l2 + 3));
    ((void *)(((RivaRasterImage*)((int)o))->f_0fad20( 0)));
    if(fl==1) f_0d26e0();
}
//@ f_0174b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zeichnet in einen 8-Bit-Pixelpuffer einen hohlen Rechteckrahmen an der Position
 *   (p2, p3) mit der Breite p4 und der Höhe p5 in der Farbe val (wird für den gelben Ausschnittrahmen auf der
 *   Übersichtskarte genutzt).
 * - Eingaben und Rückgabe: Die Funktion erhält das Zielbild-Objekt (p1), die Koordinaten p2, p3 (short), Breite
 *   p4 und Höhe p5 (short) sowie den Farbwert val (unsigned char) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Gezeichnet wird direkt in den Pixelpuffer des übergebenen Bildobjekts p1.
 === Ende Beschreibung === */
void ContextAMap2::f_0174b0(int p1, short p2, short p3, short p4, short p5, short w, unsigned char val)
{
    extern void *f_145300(void *, int, unsigned);
    p1 += p2 + p3 * w;
    f_145300((void *)p1, val, p4);
    f_145300((void *)(p1 + (p5 - 1) * w), val, p4);
    for (short i = 0; i < p5; i++, p1 += w) {
        *(char *)p1 = val;
        ((char *)p1)[p4 - 1] = val;
    }
}
//@ f_017530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion zentriert die verkleinerte Übersichtskarte (i43) in einem 0x70 x 0x77 Pixel
 *   großen Rahmenfeld, zeichnet bei großen Karten (+0x144 != 0) den aktuellen 194x194-Sichtausschnitt als Rahmen
 *   (f_0174b0, Farbe 0xdc) ein und gibt das Ergebnis rechts oben bei (0xcc, 0x4e) in den Bildschirmpuffer
 *   d_1a34e0 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält das Automap-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden die Übersichtskarte i43 (+0x43), deren Bildschirmposition s1b/s1d
 *   (+0x1b/+0x1d), der Verkleinerungsfaktor s15 (+0x15) und das Flag i144 (+0x144, Karte größer als 194x194
 *   Pixel).
 === Ende Beschreibung === */
void ContextAMap2::f_017530(int p1, short p2, short p3)
{
    int o;
    int div;
    char *pixels, *line;
    short count, row, i;
    short x, y;
    int t_690;

    o = (int)new (mark(amap2_d_1a01ec, 0x976)) B9;
    o = o ? ((int)(((RivaRasterImage*)(o))->f_0fac80( 0x70, 0x77))) : o;
    ((RivaRasterImage*)(o))->f_0fb120();

    x = (short)((0x70 - S(0x11)) / 2);
    y = (short)((0x77 - S(0x13)) / 2);
    S(0x1b) = (short)(x + 0xcc);
    S(0x1d) = (short)(y + 0x4e);
    ((RivaRasterImage*)(o))->f_0fb3a0((RivaRasterImage *)( I(0x43)), x, y, 0);

    struct Bounds { short a, b, c, d; Bounds() { a = 0; b = 0; c = 0x70; d = 0x77; } };
    Bounds bounds;

    if (I(0x144) == 1) {
        div = S(0x15);
        count = (short)(0xc2 / div);
        row = (short)(p3 / div + y);
        y = (short)((*&p2) / div + x);
        pixels = ((RivaRasterImage*)(o))->f_0fb0b0();
        f_0174b0((int)pixels, y, row, count, count, 0x70, 0xff);
    }

    ((RivaRasterImage*)(o))->f_0fade0((void *)( (int)amap2_d_1a34e0), 0xcc, 0x4e);
    if (o) operator delete(((void *)(((RivaRasterImage*)(o))->f_0fad20( 0))));
}
