/* === Beschreibung (Katalog) ===
 * Einheit fz_148170 (0x148170-0x1484A9)
 *
 * Überblick
 * Die Einheit fz_148170 enthält kleine Bit-/Byte-Tausch-Routinen (0x148170-0x14819F) sowie grundlegende
 * 2D-Grafikfunktionen zum Zeichnen von ungefüllten Rechteckrahmen, horizontalen Linien und vertikalen Linien auf
 * 320x200-Bildschirmpuffern (wahlweise mit Clipping an einem Rechteck Clip oder ungeclippt).
 === Ende Beschreibung === */
// P3 3/4 gleich (suche.py 26.10.2026, Basis fz_148170_P1.CPP)
// I9: aus fz_148170_REST.CPP uebernommen (Stufe-2-Stand), Marken 5 neu
// REST (Helfer O): Code 0x1481A0-0x1484A9; 0x148170-0x14819F (swab16/bswap/ror16) sind Assembler, hier weggelassen. Offen: Register-Zuordnung in f_148270/f_148320/f_1481a0 (Parameter als int mit (short)-Casts, Original haelt x/w roh in edi/ecx).
// fz_148170.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x148170-0x1484A9. Byte-Tausch und Rechteck-/Linienzeichnen (320 Pixel Zeilenbreite) mit Clipping.
extern const char d_1a9850[];
#define graphics_file d_1a9850
void f_1664d0(const char *a, const char *file, int line);
void f_15f342(char *dst, int n, signed char col);
void f_15f35d(char *dst, int n, int step, signed char col);
struct Clip { unsigned short x0, y1, x2, y3; };


void f_148270(Clip *r, char *p, short x, int y, short w, int c);
void f_148320(Clip *r, char *p, int x, unsigned short y, short h, int c);

//@ f_148190
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Rotiert ein 32-Bit-Langwort value um 16 Bits (ror eax, 16), vertauscht also oberes und
 *   unteres 16-Bit-Wort (Wort-Swap). Hinweis: Direkt davor (0x148170-0x14818F) liegen im Assembler-Vorspann zwei
 *   kleine Byte-Tausch-Helfer für 16-Bit- und 32-Bit-Werte (xchg al, ah bzw. Endian-Swap).
 * - Eingaben: unsigned long value (in eax).
 * - Rückgabewert: unsigned long (um 16 Bits rotiertes Langwort).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
extern "C" unsigned long _lrotr(unsigned long, unsigned int);
#pragma intrinsic(_lrotr)
unsigned long f_148190(unsigned long value);
#pragma aux f_148190 parm [eax] value [eax] modify [ecx];   // haelt die Registerzuteilung wie im Original
unsigned long f_148190(unsigned long value)
{
    return _lrotr(value, 16);
}

//@ f_1481a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet einen ungefüllten, ein Pixel breiten Rechteckrahmen an der Position (x, y) mit
 *   der Breite w, der Höhe h und der Palettenfarbe c in den 320-Pixel-breiten Bildschirmpuffer p, geclippt am
 *   Clipping-Rechteck r. Dazu ruft die Funktion zweimal f_148270 (obere und untere horizontale Kante) und
 *   zweimal f_148320 (linke und rechte vertikale Kante) auf.
 * - Eingaben: Clip *r (Clipping-Rechteck x0, y1, x2, y3), char *p (Ziel-Bildschirmpuffer, 320 Bytes pro Zeile),
 *   int x, int y (linke obere Ecke), int w, int h (Breite und Höhe in Pixeln), int c (Farbindex).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - graphics_file (d_1a9850): Dateiname für die Nullzeiger-Assertion f_1664d0("ptr != NULL", ...).
 === Ende Beschreibung === */
void f_1481a0(Clip *r, char *p, int x, int y, int w, int h, int c)
{
    int v[6];
    v[4]=x; v[5]=y;
    if (!p) f_1664d0("ptr != NULL", graphics_file, 0x17);
    v[0]=(signed char)c;
    int y2=(short)v[5];
    
    ((void (*)(Clip*,char*,int,int,int,int))f_148270)(r,p,v[2]=(short)v[4], y2, v[1]=(short)w, v[0]);
    ((void (*)(Clip*,char*,int,int,int,int))f_148320)(r,p,v[2], y2, v[3]=(short)h, v[0]);
    ((void (*)(Clip*,char*,int,int,int,int))f_148320)(r,p,(short)(v[4]+w-1),y2,v[3],v[0]);
    ((void (*)(Clip*,char*,int,int,int,int))f_148270)(r,p,v[2],(short)(v[5]+h-1),v[1],v[0]);
}
//@ f_148270
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet eine horizontale Linie der Länge w ab (x, y) in der Farbe c in den
 *   320-Pixel-breiten Bildschirmpuffer p, wobei die Linie zuvor an den Grenzen r->x0..r->x2 und r->y1..r->y3 des
 *   Clipping-Rechtecks r abgeschnitten und anschließend über f_15f342 (memset-artiger Zeilenfüller) ausgegeben
 *   wird.
 * - Eingaben: Clip *r, char *p, short x, int y, short w, int c.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_148270(Clip *r, char *p, short x, int y, short w, int c)
{
    if (!p) f_1664d0("ptr != NULL", graphics_file, 0x22);
    if ((short)x <= r->x2 && (short)y >= r->y1 && (short)y <= r->y3) {
        if ((short)x < r->x0) { w = w + x - r->x0; x = r->x0; }
        if ((short)x + (short)w - 1 > r->x2) w = w - (x + w - r->x2 - 1);
        if ((short)w > 0) f_15f342(p + ((short)y * 320 + (short)x), (short)w, (signed char)c);
    }
}

//@ f_148320
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet eine vertikale Linie der Höhe h ab (x, y) in der Farbe c in den 320-Pixel-breiten
 *   Bildschirmpuffer p, geclippt am Clipping-Rechteck r, und gibt die verbleibenden Pixel mit Zeilenabstand 320
 *   über die Assembler-Routine f_15f35d aus.
 * - Eingaben: Clip *r, char *p, int x, short y, short h, signed char c.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_148320(Clip *r, char *p, int x, short y, short h, signed char c)
{
    if (!p) f_1664d0("ptr != NULL", graphics_file, 0x3a);
    int top = r->y3;
    if ((int)y > top || (short)x < r->x0 || (short)x > r->x2) return;
    int bottom = r->y1;
    if ((int)y < bottom) { h = h + y - r->y1; y = r->y1; }
    if ((int)y + (int)h - 1 > r->y3) h = h - (h + y - r->y3 - 1);
    if ((int)h > 0) {
        p += (short)x + (int)y * 320;
        ((void (*)(char *,int,signed char,int))f_15f35d)(p, h, (signed char)c, 320);
    }
}


//@ f_1483f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet eine ungeclippte horizontale Linie der Breite w ab (x, y) in der Farbe c direkt
 *   in den 320-Pixel-breiten Bildschirmpuffer p über f_15f342.
 * - Eingaben: char *p, short x, short y, short w, signed char c.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1483f0(char *p, short x, short y, short w, signed char c)
{
    if (!p) f_1664d0("ptr != NULL", graphics_file, 0x52);
    if (w > 0) {
        p += y * 320 + x;
        f_15f342(p, w, c);
    }
}

//@ f_148450
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet eine ungeclippte vertikale Linie der Höhe h ab (x, y) in der Farbe c mit
 *   Schrittweite 320 direkt in den Bildschirmpuffer p über f_15f35d.
 * - Eingaben: char *p, short x, short y, short h, signed char c.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_148450(char *p, short x, short y, short h, signed char c)
{
    if (!p) f_1664d0("ptr != NULL", graphics_file, 0x5e);
    if (h > 0) {
        p += y * 320 + x;
        ((void (*)(char *, int, signed char, int))f_15f35d)(p, h, c, 320);
    }
}
