/* === Beschreibung (Katalog) ===
 * Einheit fz_14d2a3 (0x14D2A3 - 0x14D50B)
 *
 * Überblick
 * Diese Einheit gehört zur Watcom-C-Laufzeitbibliothek (graph / Konsolenausgabe) und implementiert das Löschen
 * des Bildschirms bzw. einzelner Bildschirmfenster (_clearscreen) sowohl im Grafikmodus als auch im
 * DOS-Textmodus.
 === Ende Beschreibung === */
// P3 3/4 gleich (suche.py 29.10.2026, Basis fz_14d2a3_P1.CPP)
#include <i86.h>
extern short d_1ce6c6, d_1aa841, d_1aa843, d_1aa7c0;
extern unsigned short d_1aa83f;
extern unsigned d_1aa849, d_1aa84d;
extern int d_1aa851;
extern unsigned char d_1aa7b9;
// OPT -4r -oneasx -r -ms -zfp -zgp -zp1 -s
// P3 0/1 gleich (suche.py 25.10.2026, Basis fz_14d2a3_P1.CPP)
// CC wcc386
int f_14d1c1(int p1, int p2);
int f_16b122(void);
int f_16b24a(void);
int f_16b3bf(void);
int f_16b433(int p1);
#pragma aux f_16b433 modify exact [eax]
int f_16b484(int p1);
int f_16b4ae(int p1);
int f_16b525(void);
int f_16b52c(int p1);
#pragma aux f_16b52c modify exact [eax]
int f_16b568(int p1, int p2, int p3, int p4);
extern char d_1aa7ad;
extern short d_1ce6b8, d_1ce6bc, d_1ce6be, d_1ce6d2, d_1ce6d4, d_1ce6d6, d_1ce6d8;
extern short d_1ce6ba;
extern short d_1ce706, d_1ce708, d_1ce70a, d_1ce70c;
void f_14d3ee(short p1, short p2, short p3, short p4);
void f_14d44c(short p1, short p2, short p3, short p4);
//@ f_14d2a3
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löscht im Grafikmodus abhängig vom Bereichsparameter m entweder das aktive
 *   Grafik-Clippingfenster (m == 1), das aktuelle Textfenster umgerechnet in Pixelkoordinaten (m == 2) oder den
 *   gesamten Grafikbildschirm (default, 0 bis d_1ce6b8 - 1 x d_1ce6ba - 1) über f_14d3ee. Außer beim reinen
 *   Viewport-Löschen (m == 1) setzt sie anschließend die Textcursor-Position über f_14d1c1(1, 1) auf die linke
 *   obere Ecke zurück.
 * - Eingaben: m (Löschmodus als short: 0 = ganzer Bildschirm, 1 = Grafik-Viewport, 2 = Textfenster).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1ce6b8, d_1ce6ba: Horizontale und vertikale Grafikauflösung in Pixeln.
 *   - d_1ce6bc, d_1ce6be: Anzahl der Textspalten und Textzeilen.
 *   - d_1ce6d2..d_1ce6d8: Grenzen des aktiven Grafik-Viewports.
 *   - d_1ce706..d_1ce70c: Grenzen des aktiven Textfensters.
 === Ende Beschreibung === */
#pragma aux f_14d2a3 "*";
void f_14d2a3(short m)
{
    short q1,q2;
    switch (m) {
    case 1:
        f_14d3ee(d_1ce6d2, d_1ce6d6, d_1ce6d4, d_1ce6d8);
        return;
    case 2:
        q1 = d_1ce6b8 / d_1ce6bc;
        q2 = d_1ce6ba / d_1ce6be;
        f_14d3ee(q1 * d_1ce706, q2 * d_1ce70c,
                 (d_1ce70a + 1) * q1 - 1, (d_1ce708 + 1) * q2 - 1);
        break;
    default:
        f_14d3ee(0, 0, d_1ce6b8 - 1, d_1ce6ba - 1);
        break;
    }
    f_14d1c1(1, 1);
}
//@ f_14d36e
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffentliche Laufzeitfunktion _clearscreen(m). Sie prüft anhand des Modusflags d_1aa7ad, ob
 *   sich die Anzeige im Grafikmodus befindet (Weiterleitung an f_14d2a3) oder im Textmodus (Direktfüllung des
 *   Textbildspeichers über f_14d44c) und setzt bei m != 1 den Textcursor auf (1, 1) zurück.
 * - Eingaben: m (Bereichsmodus als unsigned short: 0 = ganzer Bildschirm, 1 = Viewport, 2 = Textfenster).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1aa7ad (Flag für aktiven Grafikmodus).
 === Ende Beschreibung === */
#pragma aux f_14d36e "*";
void f_14d36e(unsigned short m)
{
    f_16b122();f_16b24a();
    if(d_1aa7ad) {f_14d2a3((short)m);goto done;}
    switch(m) {
    case 1:goto done;
    case 2:f_14d44c(d_1ce70c,d_1ce706,d_1ce708,d_1ce70a);break;
    default:f_14d44c(0,0,(short)(d_1ce6be-1),(short)(d_1ce6bc-1));break;
    }
    f_14d1c1(1,1);
done:f_16b3bf();
}
//@ f_14d3ee
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt im Grafikmodus das durch (p1, p2) bis (p3, p4) begrenzte Rechteck mit der aktuellen
 *   Hintergrundfarbe. Dazu sichert sie vorübergehend Zeichenmodus, Füllmuster und Farbe (f_16b433, f_16b484,
 *   f_16b525), zeichnet ein ausgefülltes Rechteck mit Farbe 0 über f_16b568 und stellt anschließend die
 *   vorherigen Grafikeinstellungen wieder her.
 * - Eingaben: p1, p2 (linke obere Ecke), p3, p4 (rechte untere Ecke als short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s1, s2 (gesicherte Grafikattribute), loc (8-Byte-Puffer für das gesicherte Füllmuster).
 === Ende Beschreibung === */
#pragma aux f_14d3ee "*";
void f_14d3ee(short p1, short p2, short p3, short p4)
{
    short s1, s2;
    char loc[8];
    s1 = f_16b433(3);
    f_16b484((int)loc);
    f_16b4ae(0);
    s2 = f_16b525();
    f_16b52c(0);
    f_16b568(p1, p2, p3, p4);
    f_16b52c(s2);
    f_16b4ae((int)loc);
    f_16b433(s1);
}
//@ f_14d44c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löscht im DOS-Textmodus einen rechteckigen Zellbereich (top, left bis bottom, right)
 *   direkt im Text-Videospeicher (Monochrom-Segment d_1aa841 bei Modus 7, sonst Farb-Segment d_1aa843), indem
 *   jede Zeichenzelle mit einem Leerzeichen (0x20) und dem aktuellen Textattribut d_1aa7b9 überschrieben wird.
 * - Eingaben: top (Startzeile), left (Startspalte), bottom (Endzeile), right (Endspalte).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sel, row, dst: Segment-Selektor und Far-Zeiger in den Textbildspeicher unter Berücksichtigung der aktiven
 *     Bildschirmseite page.
 *   - cell: 16-Bit-Zeichenzelle aus Attribut (d_1aa7b9 << 8) und Leerzeichen 0x20.
 === Ende Beschreibung === */
#pragma aux f_14d44c "*";
void f_14d44c(short top, short left, short bottom, short right)
{
    __segment sel;
    int page;
    unsigned short __based(sel) *dst;
    unsigned short __based(sel) *row;
    short width;
    unsigned short cell;
    short j;
    int mode;
    int offset;
    { int u_ = d_1aa7ad; } mode = d_1ce6c6; { void __based(sel) *t0_ = (void __based(sel) *)mode; mode = (int)t0_; } { void __based(sel) *t1_ = (void __based(sel) *)mode; mode = (int)t1_; } { void __based(sel) *t2_ = (void __based(sel) *)mode; mode = (int)t2_; } { void __based(sel) *t3_ = (void __based(sel) *)mode; mode = (int)t3_; } { void __based(sel) *t4_ = (void __based(sel) *)mode; mode = (int)t4_; }
    if (mode == 7) {
        { __segment s1_ = d_1aa841; sel = s1_; }
        row = (unsigned short __based(sel) *)d_1aa84d;
    } else {
        { __segment s2_ = d_1aa843; sel = s2_; }
        row = (unsigned short __based(sel) *)d_1aa851;
    }
    offset = (left + d_1ce6bc * top) * 2;
    page = *(short __far *)MK_FP(d_1aa83f, d_1aa849 + 0x4c);
    { char r1_ = mode; short r2_ = mode; char r3_ = offset; short r4_ = offset; } row = (unsigned short __based(sel) *)((char __based(sel) *)row + (page * d_1aa7c0 + offset));
    { unsigned short w_ = right - left + 1; width = w_; }
    { short c1_ = (d_1aa7b9 << 8) + 0x20; unsigned short c2_ = c1_; cell = c2_; }
    for (; top <= bottom; top++) {
        dst = row;
        for (j = 0; j < width; j++)
            *dst++ = cell;
        row = (unsigned short __based(sel) *)((char __based(sel) *)row + d_1ce6bc * 2);
    }
}

