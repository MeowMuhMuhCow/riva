/* === Beschreibung (Katalog) ===
 * Einheit shape_gz0fb120 (0x0FAC10 - 0x0FB660)
 *
 * Überblick
 * Die Einheit shape_gz0fb120 fasst die beiden eng zusammengehörigen Teile shape (0x0fac10-0x0fb120) und
 * gz_0fb120 (0x0fb120-0x0fb660) zusammen und implementiert die zentrale 2D-Rasterbild-Klasse RivaRasterImage:
 * Konstruktoren mit eigenem oder externem Pixelpuffer, Destruktoren, Bildschirm-Blitting (für VGA/Mode-X und
 * VESA-SVGA), Auslesen aus dem Bildschirmspeicher, Skalieren, Füllen, Umfärben, Zeichnen von Rahmen und Linien
 * sowie das Kopieren von Teilbildern. Am Ende der Einheit stehen zudem ein Icon-Registrierungs-Helper (f_0fb5b0)
 * und Konstruktor/Destruktor einer Dungeon-Unterklasse (f_0fb5f0, f_0fb630).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// I9: aus shape_REST.CPP uebernommen (Stufe-2-Stand), Marken 12 neu
// shape.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xFAC10-0xFB120. Klasse Img: Bild als Zeilentabelle (Zeiger je Zeile), Zeichenroutinen.
extern const char d_1a67d4[];
#define shape_file d_1a67d4
int f_13e240();
void f_13e690(int adr, int z, short a, short b, short c, short d, short e);
void f_13f360(int adr, int z, short a, short b, short c, short d, short e, int f);
void f_13eab0(int adr, int z, short a, short b, short c, short d, short e);
void __cdecl f_1568d1(short a, short b, short c, short d, int *e, int f, int g, int h);
void __cdecl f_156ab0(short a, short b, short c, short d, int *e, int f);
void f_1568cb(void *p);
void __cdecl f_156b4d(int *a, short b, short c, int *d, short e, short f);
void f_14d075(int a, int b, int n);
#pragma pack(1)


//@ f_0fac10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor von RivaRasterImage für einen bereits vorhandenen externen Pixelpuffer c: Setzt
 *   das Eigentumsflag raster.k = 0, speichert Breite a und Höhe b, legt das Zeilenadressen-Array row_addresses
 *   (b Einträge) an und trägt die Zeilenanfänge a * i + (int)c ein.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - a, b (Breite und Höhe des Bildes in Pixeln).
 *   - c (Zeiger auf den externen Pixelpuffer).
 * - Rückgabewert: RivaRasterImage * - this.
 * - Wichtige Variablen:
 *   - raster.k, raster.w, raster.h, raster.row_addresses (Felder der Bildstruktur).
 === Ende Beschreibung === */
RivaRasterImage *RivaRasterImage::f_0fac10(short a, short b, void *c)
{
    raster.k = 0; raster.w = a; raster.h = b;
    raster.row_addresses = new (mark(shape_file, 0x2c)) int[b];
    short i = 0;
    while (i < b) { raster.row_addresses[i] = a * i + (int)c; i++; }
    return this;
}





//@ f_0fad20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor von RivaRasterImage: Gibt bei raster.k != 0 den eigenen Pixelpuffer
 *   row_addresses[0] und anschließend das Zeilenadressen-Array row_addresses frei.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - flag_unused491 (Destruktor-Flags).
 * - Rückgabewert: RivaRasterImage * - this.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaRasterImage *RivaRasterImage::f_0fad20(int flag_unused491)
{
    if (raster.k != 0) delete (void *)raster.row_addresses[0];
    if (raster.row_addresses) { delete raster.row_addresses; raster.row_addresses = 0; }
    return this;
}
//@ f_0fad50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert ein bestehendes RivaRasterImage-Objekt auf einen externen Pixelpuffer c der
 *   Größe a x b (raster.k = 0) und baut dessen Zeilenadressen-Tabelle neu auf.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - a, b (Breite und Höhe in Pixeln).
 *   - c (Externer Pixelpuffer).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fad50(short a, short b, void *c)
{
    raster.k = 0; raster.w = a; raster.h = b;
    raster.row_addresses = new (mark(shape_file, 0x59)) int[b];
    short i = 0;
    while (i < b) { raster.row_addresses[i] = a * i + (int)c; i++; }
}

//@ f_0fadc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt ausschließlich das Zeilenadressen-Array raster.row_addresses frei und setzt den Zeiger
 *   auf 0.
 * - Eingaben: this (RivaRasterImage *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fadc0()
{
    if (raster.row_addresses) { delete raster.row_addresses; raster.row_addresses = 0; }
}

//@ f_0fade0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet das gesamte Rasterbild deckend (Modus 0) an die Position (x_input, y_input) in den
 *   Zielpuffer bzw. Bildschirm e (je nach Grafikmodus f_13e240() über f_1568d1 oder die VESA-Routine f_13e690).
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Ziel-Bildschirm- oder Pufferzeiger).
 *   - x_input, y_input (Zielkoordinaten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fade0(void *e, int x_input, int y_input)
{
    short x = x_input;
    short y = y_input;
    if (f_13e240() == 0) f_1568d1(x, y, raster.w, raster.h, raster.row_addresses, 0, (int)e, 0);
    else f_13e690(raster.row_addresses[0], 0, x, y, raster.w, raster.h, raster.w);
}

//@ f_0fae30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet das gesamte Rasterbild an die Position (x_input, y_input) in das Ziel e unter
 *   Berücksichtigung des Transparenzmodus m_input (0 = deckend über f_13e690, 1 = transparent über f_13f360 bzw.
 *   f_1568d1).
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Zielpuffer).
 *   - x_input, y_input (Zielkoordinaten).
 *   - m_input (Zeichenmodus: 0 = deckend, 1 = mit Transparenz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fae30(void *e, int x_input, int y_input, int m_input)
{
    short x = x_input;
    short y = y_input;
    unsigned short m = m_input;
    if (0) f_1568d1(f_13e240() ? 0 : 0, 0, 0, 0, 0, 0, 0, 0);
    if (f_13e240() == 0) f_1568d1(x, y, raster.w, raster.h, raster.row_addresses, (short)m, (int)e, 0);
    else switch (m) {
    case 0: f_13e690(raster.row_addresses[0], 0, x, y, raster.w, raster.h, raster.w); break;
    case 1: f_13f360(raster.row_addresses[0], 0, x, y, raster.w, raster.h, raster.w, 0); break;
    }
}

//@ f_0faec0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet einen Teilbereich der Breite s1 und Höhe s2 des Rasterbildes deckend an die
 *   Position (x, y) in das Ziel e.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Zielpuffer).
 *   - x, y (Zielkoordinaten).
 *   - s1, s2 (Zu zeichnende Breite und Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0faec0(void *e, short x, short y, short s1, short s2)
{
    if (0) f_1568d1(f_13e240() ? 0 : 0, 0, 0, 0, 0, 0, 0, 0);
    int t_130 = f_13e240();
    if (t_130 == 0) {
        f_1568d1(x, y, s1, s2, raster.row_addresses, 0, (int)e, 0);
        return;
    }
    f_13e690(raster.row_addresses[0], 0, x, y, s1, s2, raster.w);
    return;
}

//@ f_0faf20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet einen Teilbereich der Breite s1 und Höhe s2 des Rasterbildes mit dem Zeichenmodus m
 *   (0 = deckend, 1 = transparent) an die Position (x, y) in das Ziel e.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Zielpuffer).
 *   - x, y (Zielkoordinaten).
 *   - s1, s2 (Breite und Höhe).
 *   - m (Zeichenmodus 0 oder 1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0faf20(void *e, short x, short y, short s1, short s2, unsigned short m)
{
    if (0) f_1568d1(f_13e240() ? 0 : 0, 0, 0, 0, 0, 0, 0, 0);
    if (f_13e240() == 0) f_1568d1(x, y, s1, s2, raster.row_addresses, (short)m, (int)e, 0);
    else switch (m) {
    case 0: f_13e690(raster.row_addresses[0], 0, x, y, s1, s2, raster.w); break;
    case 1: f_13f360(raster.row_addresses[0], 0, x, y, s1, s2, raster.w, 0); break;
    }
}

//@ f_0fafb0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest einen Bildschirmbereich der vollen Bildgröße (raster.w x raster.h) ab der Position (x,
 *   y) aus dem Quellpuffer/Bildschirm e in das RivaRasterImage ein (über f_156ab0 bzw. VESA f_13eab0).
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Quell-Bildschirmpuffer).
 *   - x, y (Quellkoordinaten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fafb0(void *e, short x, short y)
{
    if (f_13e240() == 0) f_156ab0(x, y, raster.w, raster.h, raster.row_addresses, (int)e);
    else f_13eab0(raster.row_addresses[0], 0, x, y, raster.w, raster.h, raster.w);
}

//@ f_0fb000
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest einen Teilbereich der Größe s1 x s2 ab der Position (x, y) aus dem
 *   Quellpuffer/Bildschirm e in das RivaRasterImage ein.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Quell-Bildschirmpuffer).
 *   - x, y (Quellkoordinaten).
 *   - s1, s2 (Zu lesende Breite und Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb000(void *e, short x, short y, short s1, short s2)
{
    if (0) f_156ab0(f_13e240() ? 0 : 0, 0, 0, 0, 0, 0);
    int t_130 = f_13e240();
    if (t_130 == 0) {
        f_156ab0(x, y, s1, s2, raster.row_addresses, (int)e);
        return;
    }
    f_13eab0(raster.row_addresses[0], 0, x, y, s1, s2, raster.w);
    return;
}

//@ f_0fb060
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert alle Einträge der Zeilenadressen-Tabelle raster.row_addresses auf eine neue
 *   Basisadresse base (raster.w * i + (int)base).
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - base (Neue Basisadresse des Pixelpuffers).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb060(void *base)
{
    short i = 0;
    while (i < raster.h) { raster.row_addresses[i] = raster.w * i + (int)base; i++; }
}

//@ f_0fb090
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert über f_14d075 (memmove/memcpy) genau raster.w * raster.h Bytes aus dem Puffer e in
 *   den Pixelpuffer raster.row_addresses[0] des Bildes.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - e (Quellpuffer).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb090(void *e)
{
    f_14d075(raster.row_addresses[0], (int)e, raster.w * raster.h);
}

char *RivaRasterImage::f_0fb0b0() { return raster.rows[0]; }

//@ f_0fb0c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Skaliert das Rasterbild this mithilfe eines temporären 0x1400-Byte-Arbeitspuffers t über die
 *   Assembler-Skalierroutine f_156b4d auf die Abmessungen des Zielbildes o.
 * - Eingaben:
 *   - this (Quell-RivaRasterImage *).
 *   - o (Ziel-RivaRasterImage *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - t (Temporärer Skalierungspuffer auf dem Heap).
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb0c0(RivaRasterImage *o)
{
    char *t = new (mark(shape_file, 0xfa)) char[0x1400];
    f_1568cb(t + 0x200);
    f_156b4d(raster.row_addresses, raster.w, raster.h, o->raster.row_addresses, o->raster.w, o->raster.h);
    delete t;
}


// P3 9/12 gleich (suche.py 25.10.2026, Basis gz_0fb120_P1.CPP)
// I9: aus gz_0fb120_REST.CPP uebernommen (Stufe-2-Stand), Marken 11 neu
// REST: 86 Befehle offen (0FB1A0 Schleifenform, 0FB220 Register/Stapel, 0FB3E0 Stapelplatz this/src, 0FB5B0 Initialisierer, 0FB5F0/0FB630 Ctor/Dtor edx-Erhalt). Stand Lauf 7.
// gz_0fb120.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xFB120-0xFB660. ImgRight493-Methoden (Fuellen, Rechteck, Kopieren), ein Initialisierer und Konstruktor/Destruktor einer Ableitung.
#include <string.h>
#pragma pack(1)
void f_145300(void *p, int v, int n);
void *f_05ff60(void *self, signed char c);
void *f_060030(void *self, int fl);
extern void *d_1bb74c[];
struct Cur { char f_1264e0(int v); void f_1264d0(int v); };

extern Cur d_1c2c44;




#include <string.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))

int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C05ff60_2(int,int);
#pragma aux C05ff60_2 "f_05ff60";
int C060030_2(int,int);
#pragma aux C060030_2 "f_060030" modify exact [eax edx];
int C1264d0_2(int,int);
#pragma aux C1264d0_2 "f_1264d0";
char C1264e0_2(int);
#pragma aux C1264e0_2 "f_1264e0" modify exact [eax];
//@ f_0fb120
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löscht das gesamte Rasterbild (füllt alle raster.h Zeilen über f_145300 mit dem Farbwert 0).
 * - Eingaben: this (RivaRasterImage *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb120() {
    short i;
    for (i = 0; i < raster.h; i++) f_145300(raster.rows[i], 0, raster.w);
}
//@ f_0fb150
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Füllt alle raster.h Zeilen des Rasterbildes über f_145300 komplett mit dem Farbindex v.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - v (Farbindex zum Füllen).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb150(short v) {
    short i;
    for (i = 0; i < raster.h; i++) f_145300(raster.rows[i], v, raster.w);
}
//@ f_0fac80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor von RivaRasterImage mit eigener Speicherreservierung: Setzt raster.k = 1, legt
 *   das Zeilenadressen-Array (b Einträge) sowie einen eigenen Pixelpuffer der Größe a * b Bytes auf dem Heap an
 *   und berechnet alle Zeilenzeiger row_addresses[0 .. b-1].
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - a, b (Breite und Höhe des Bildes in Pixeln).
 * - Rückgabewert: RivaRasterImage * - this.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaRasterImage *RivaRasterImage::f_0fac80(short a, short b)
{
    raster.k = 1; raster.w = a; raster.h = b;
    raster.row_addresses = new (mark(shape_file, 0x3a)) int[b];
    int count = b;
    raster.row_addresses[0] = (int)new (mark(shape_file, 0x3b)) char[count * a];
    short i = 1; for (; i < b; i++) { int base; int product = a * i; base = raster.row_addresses[0]; raster.row_addresses[i] = base + product; }
    return this;
}

//@ f_0fb4d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert aus dem größeren Quellbild o ab der Koordinate (x, y) einen Ausschnitt der Größe
 *   this->raster.w x this->raster.h deckend in das Bild this.
 * - Eingaben:
 *   - this (Ziel-RivaRasterImage *).
 *   - o (Quell-RivaRasterImage *).
 *   - x, y (Startkoordinate im Quellbild o).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb4d0(RivaRasterImage *o, short x, short y) {
    short i;
    for (i = 0; i < raster.h; i++) memcpy(raster.rows[i], o->raster.rows[y + i] + x, raster.w);
}
//@ f_0fb1a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ersetzt im gesamten Rasterbild jeden Pixel mit dem Farbindex a durch den neuen Farbindex b.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - a (Zu ersetzender alter Farbindex).
 *   - b (Neuer Farbindex).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb1a0(char a, signed char b) {
    short i,j;
    for(i=0;i<raster.h;i++) {
      for(j=0;j<raster.w;j++) if(raster.rows[i][j]==a) raster.rows[i][j]=b;
    }
}
void RivaRasterImage::f_0fb210(short *pw, short *ph) { *pw = raster.w; *ph = raster.h; }
//@ f_0fb220
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet im Rasterbild einen ungefüllten Rechteckrahmen an der Position (x, y) mit der
 *   Breite bw, Höhe bh und Farbe c durch je zwei Aufrufe von f_0fb320 (waagerechte Kanten) und f_0fb350
 *   (senkrechte Kanten).
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - x, y, bw, bh (Position und Abmessungen des Rechtecks).
 *   - c (Farbindex des Rahmens).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb220(short x, short y, short bw, short bh, short c) {
    f_0fb320(x,y,bw,c);
    f_0fb320(x,y+bh-1,bw,c);
    f_0fb350(x,y,bh,c);
    f_0fb350(x+bw-1,y,bh,c);
}
//@ f_0fb320
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet im Rasterbild eine waagerechte Linie ab (x, y) der Länge bw mit dem Farbindex c.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - x, y (Startkoordinate).
 *   - bw (Länge in Pixeln).
 *   - c (Farbindex).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb320(short x, short y, short bw, short c) {
    f_145300(raster.rows[y] + x, c, bw);
}
//@ f_0fb350
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet im Rasterbild eine senkrechte Linie ab (x, y) der Höhe bh mit dem Farbindex c.
 * - Eingaben:
 *   - this (RivaRasterImage *).
 *   - x, y (Startkoordinate).
 *   - bh (Höhe in Pixeln).
 *   - c (Farbindex).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb350(short x, short y, short bh, short c) {
    short i;
    for (i = y; i < y + bh; i++) raster.rows[i][x] = c;
}
//@ f_0fb3a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert das Quellbild o an die Position (x, y) in das aktuelle Bild this unter Verwendung
 *   des Kopiermodus n (0 = deckend, 1 = transparent ohne Farbe 0) über f_0fb3e0.
 * - Eingaben:
 *   - this (Ziel-RivaRasterImage *).
 *   - o (Quell-RivaRasterImage *).
 *   - x, y (Zielposition innerhalb von this).
 *   - n (Kopiermodus 0 oder 1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb3a0(RivaRasterImage *o, short x, short y, short n) {
    o->f_0fb3e0(raster.rows[0] + y * raster.w + x, raster.w, 0, 0, o->raster.w, o->raster.h, n);
}
struct Pixel493 { static short word(char *p,short i) {return *(signed char *)(p+i);} static int full(char *p,short i) {return *(signed char *)(p+i);} };
//@ f_0fb3e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert einen rechteckigen Ausschnitt (x, y, cw, ch) aus dem Bild this in den Zielpuffer dst
 *   (mit Zeilenabstand stride): Bei mode == 0 zeilenweise per memcpy, bei mode == 1 pixelweise unter Auslassung
 *   transparenter Pixel (Farbe == 0).
 * - Eingaben:
 *   - this (Quell-RivaRasterImage *).
 *   - dst (Zielpufferadresse).
 *   - stride (Zeilenbreite des Zielpuffers in Bytes).
 *   - x, y, cw, ch (Quellausschnitt).
 *   - mode (0 = deckend, 1 = transparent).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - src (Laufender Quellzeiger innerhalb von this).
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb3e0(char *dst, short stride, short x, short y, short cw, short ch, short mode) {
    { extern int g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11,g12,g13,g14,g15,g16,g17,g18,g19,g20,g21,g22,g23,g24,g25,g26,g27,g28,g29,g30,g31,g32,g33,g34,g35,g36,g37,g38,g39,g40,g41,g42,g43,g44,g45,g46,g47,g48,g49,g50,g51,g52; if(g1&0)g1=0; if(g2&0)g2=0; if(g3&0)g3=0; if(g4&0)g4=0; if(g5&0)g5=0; if(g6&0)g6=0; if(g7&0)g7=0; if(g8&0)g8=0; if(g9&0)g9=0; if(g10&0)g10=0; if(g11&0)g11=0; if(g12&0)g12=0; if(g13&0)g13=0; if(g14&0)g14=0; if(g15&0)g15=0; if(g16&0)g16=0; if(g17&0)g17=0; if(g18&0)g18=0; if(g19&0)g19=0; if(g20&0)g20=0; if(g21&0)g21=0; if(g22&0)g22=0; if(g23&0)g23=0; if(g24&0)g24=0; if(g25&0)g25=0; if(g26&0)g26=0; if(g27&0)g27=0; if(g28&0)g28=0; if(g29&0)g29=0; if(g30&0)g30=0; if(g31&0)g31=0; if(g32&0)g32=0; if(g33&0)g33=0; if(g34&0)g34=0; if(g35&0)g35=0; if(g36&0)g36=0; if(g37&0)g37=0; if(g38&0)g38=0; if(g39&0)g39=0; if(g40&0)g40=0; if(g41&0)g41=0; if(g42&0)g42=0; if(g43&0)g43=0; if(g44&0)g44=0; if(g45&0)g45=0; if(g46&0)g46=0; if(g47&0)g47=0; if(g48&0)g48=0; if(g49&0)g49=0; if(g50&0)g50=0; if(g51&0)g51=0; if(g52&0)g52=0; } // haelt die Registerzuteilung wie im Original
    char *src = raster.w * y + raster.rows[0] + x;
    if (mode == 0) {
        short j;
        for (j = 0; j < ch; j++) { memcpy(dst, src, cw); src += raster.w; dst += (*&stride); }
    } else if (mode == 1) {
        short j, i;
        for (j = 0; j < ch; j++) {
            for (i = 0; i < cw; i++) { short color=Pixel493::word(src,i); if(Pixel493::full(src,i)) dst[i]=color; }
            src += raster.w; dst += stride;
        }
    }
}
//@ f_0fb540
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert aus dem Quellbild o ab der Koordinate (x, y) einen Ausschnitt der explizit
 *   angegebenen Größe bw x bh zeilenweise nach this (oben links ab (0, 0)).
 * - Eingaben:
 *   - this (Ziel-RivaRasterImage *).
 *   - o (Quell-RivaRasterImage *).
 *   - x, y (Startkoordinate in o).
 *   - bw, bh (Zu kopierende Breite und Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void RivaRasterImage::f_0fb540(RivaRasterImage *o, short x, short y, short bw, short bh) {
    short i;
    for (i = 0; i < bh; i++) memcpy(raster.rows[i], o->raster.rows[y + i] + x, bw);
}

struct Reg { char a; short b; };
extern Reg d_1c0294;
extern volatile short d_1c212a;
extern Reg **d_1c212c;
//@ f_0fb5b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Trägt das Aktionsicon 0x250 (Typ 0) über die Struktur d_1c0294 in die globale
 *   Aktionsicon-Leiste d_1c212c an Position d_1c212a ein und erhöht d_1c212a um 1.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0294 (Statischer Icon-Eintrag 0x250).
 === Ende Beschreibung === */
void f_0fb5b0() {
    d_1c0294.a = 0; d_1c0294.b = 0x250;
    d_1c212c[d_1c212a] = &d_1c0294;
    d_1c212a += 1;
}

struct Base { char b[8]; Base(signed char c); ~Base(); };
struct W : Base { void *vt; signed char c; int i; W(signed char ch); ~W(); };


//@ f_0fb5f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor einer abgeleiteten Dungeon-/Gebiets-Steuerklasse: Ruft den Basiskonstruktor
 *   f_05ff60(p, ch) auf, setzt die virtuelle Methodentabelle d_1bb74c, sichert den aktuellen Zustand von
 *   d_1c2c44 (f_1264e0) in Feld +12, schaltet d_1c2c44 über f_1264d0 auf Modus 7 und initialisiert Feld +13 mit
 *   0.
 * - Eingaben:
 *   - p (Zeiger auf das zu konstruierende Objekt).
 *   - ch (Dungeon-/Gebietskennung).
 * - Rückgabewert: int - Der initialisierte Objektzeiger p.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0fb5f0(int p,signed char ch)
{
    p=C05ff60_2(p,ch);*(int *)((char *)p+8)=NA(d_1bb74c);NB(p,12)=(unsigned char)C1264e0_2(NA(d_1c2c44));
    C1264d0_2(NA(d_1c2c44),7);NI(p,13)=0;return p;
}



//@ f_0fb630
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor der abgeleiteten Dungeon-/Gebiets-Steuerklasse: Setzt die virtuelle
 *   Methodentabelle auf d_1bb74c, stellt an d_1c2c44 über f_1264d0 den Modus 0 wieder her und ruft den
 *   Basisdestruktor f_060030(p, 1) auf.
 * - Eingaben:
 *   - p (Zeiger auf das Objekt).
 *   - unused (Destruktor-Flags).
 * - Rückgabewert: int - Rückgabewert von f_060030.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0fb630(int p,int unused)
{
    NI(p,8)=NA(d_1bb74c);C1264d0_2(NA(d_1c2c44),0);return C060030_2(p,1);
}


