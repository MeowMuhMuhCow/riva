/* === Beschreibung (Katalog) ===
 * Einheit gz_014df0 (0x014df0 - 0x015040)
 *
 * Überblick
 * Diese Einheit enthält zwei eng verwandte Grafik-Hilfsfunktionen (f_014df0 und f_014f20), die ein kleineres
 * Rasterbild (p3) zentriert um einen Zielpunkt (p4, p5) mit vollständigem Clipping an den Rändern auf oder aus
 * einer größeren Bildfläche (p2) kopieren.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
// P3 0/2 gleich (suche.py 30.10.2026, Basis gz_014df0_P1.CPP)
// I9: aus G014DF0_REST.CPP uebernommen (Stufe-2-Stand), Marken 2 neu
// STAND 22.10.2026 Helfer D: nicht GLEICH (95+82 Bef.). Stapel passt mit Struct-Variante (D1), Registerwahl p2/p3 esi/edi und y=eax/ch=edx offen
// gz_014df0.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x014DF0-0x015040. Bild (p3) mittig auf Flaeche (p2) bei (p4,p5) mit Beschneidung kopieren.
struct Surf;



inline int sum901(int a,int b){return a+b;}
//@ f_014df0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014df0
 * - Aufgabe im Spiel: Zeichnet das Quellbild p3 mittig zentriert auf die Koordinaten (p4, p5) in das Zielbild
 *   p2. Ragt das Quellbild über den linken, oberen, rechten oder unteren Rand von p2 (w1 x h1) hinaus, werden
 *   Quellversatz (sx, sy), Zielkoordinaten (x, y) und Kopiergröße (cw, ch) entsprechend beschnitten und
 *   anschließend der sichtbare Ausschnitt über p3->f_0fb3e0 mit dem Zeilenstride p7 (falls < 1, wird w1
 *   verwendet) und Transparenz-/Kopiermodus p6 in den Pixelpuffer von p2 übertragen.
 * - Eingaben: Ungenutzter Kontextparameter (p1), Zielbild (p2), Quellbild (p3), Mittelpunktkoordinaten (p4, p5),
 *   Zeichenmodus (p6) und optionaler Zeilenstride (p7).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Bildabmessungen w1, h1 (Zielbild p2) und w2, h2 (Quellbild p3).
 *   - Lokale geclippte Quelloffsets (sx, sy), Zielkoordinaten (x, y) und Ausschnittgröße (cw, ch).
 === Ende Beschreibung === */
void f_014df0(int p1, Surf *p2, Surf *p3, short p4, short p5, short p6, short p7)
{
    struct Word1309 { short v; short pad; };
    short w1;
    Word1309 h2;
    short h1;
    short w2;
    short sx;
    short sy;
    short y;
    short cw;
    short x;
    short ch;
    ch = (ch & 0) ? 0 : ch; // haelt die Registerzuteilung wie im Original
    ((RivaRasterImage*)(p2))->f_0fb210((short *)( &w1),(short *)( &h1));
    ((RivaRasterImage*)(p3))->f_0fb210((short *)( &w2),(short *)( &h2.v));
    if (p7 < (unsigned short)1) p7 = w1;
    x = p4 - w2 / 2;
    y = p5 - h2.v / 2;
    sx = 0;
    sy = 0;
    cw = w2;
    ch = h2.v;
    if (x < 0) {
        sx = -x;
        cw = w2 - sx;
        x = 0;
    }
    if (y < 0) {
        sy = -y;
        ch -= sy;
        y = 0;
    }
    extern short d_1bf49e;signed char &g971=*(signed char*)&d_1bf49e;signed char keep971=g971;int right944=x;g971=keep971;right944+=cw;if(w1<=right944)cw=w1-x; // haelt die Registerzuteilung wie im Original
    if (y + ch >= h1) ch = h1 - y;
    ((RivaRasterImage*)(p3))->f_0fb3e0((char *)( x + (((int)(((RivaRasterImage*)(p2))->f_0fb0b0())) + y * p7)), p7, sx, sy, cw, ch, p6);
}
#undef h2
#undef w2
#undef h1
#undef sx
#undef cw
#undef w1
#undef sy
//@ f_014f20
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014f20
 * - Aufgabe im Spiel: Gegenstück zu f_014df0 (Hintergrund-Sicherung bzw. Rückkopie): Berechnet für denselben um
 *   (p4, p5) zentrierten und an den Rändern von p2 (w1 x h1) beschnittenen Bereich des Teilbilds p3 (w2 x h2)
 *   die geclippten Koordinaten und kopiert über p2->f_0fb3e0 den entsprechenden Ausschnitt zwischen p2 und dem
 *   Puffer von p3 an der Position (sx, sy) mit der Zeilenbreite w2.
 * - Eingaben: Ungenutzter Kontextparameter (p1), Hauptbild (p2), Teilbildpuffer (p3), Mittelpunktkoordinaten
 *   (p4, p5) und Kopiermodus (p6).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale Abmessungen w1, h1 und w2, h2 sowie geclippte Koordinaten (x, y, sx, sy, cw, ch).
 === Ende Beschreibung === */
void f_014f20(int p1, Surf *p2, Surf *p3, short p4, short p5, short p6)
{
    short w1;
    short w2;
    short h1;
    short h2;
    short sy;
    short sx;
    short ch;
    short cw;
    ((RivaRasterImage*)(p2))->f_0fb210((short *)( (short *)&w1),(short *)( (short *)&h1));
    ((RivaRasterImage*)(p3))->f_0fb210((short *)( (short *)&w2),(short *)( (short *)&h2));
    unsigned short x = p4 - (short)w2 / 2;
    int y = (*&p5) - (short)h2 / 2;
    sx = 0; sy = 0;
    cw = w2;
    ch = h2;
    if ((short)x < 0) {
        sx = -x;
        cw = w2;
        cw -= sx;
        x = 0;
    }
    do {
    if ((short)y < 0) {
        sy = -y;
        ch = ch - sy;
        y = 0;
    }
    } while (0);
    do { if ((short)cw + (short)(unsigned short)(x & 0xffff) >= (short)w1) cw = w1 - x; } while (0);
    do { if (sum901(ch,(short)y) >= h1) ch = h1 - y; } while (0);
    ((RivaRasterImage*)(p2))->f_0fb3e0((char *)( (short)sx + (((int)(((RivaRasterImage*)(p3))->f_0fb0b0())) + (short)sy * (short)w2)), w2, (short)x, (short)y, (short)cw, (short)ch, p6);
}
