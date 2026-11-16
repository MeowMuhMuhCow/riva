/* === Beschreibung (Katalog) ===
 * Einheit alloc_t2 (0x014be0 - 0x014df0)
 *
 * Überblick
 * Diese Einheit enthält den Beginn der Automap-Implementierung (amap.cpp): das Setzen von
 * Standard-Fensterkoordinaten (f_014be0), die Umrechnung zwischen 3D-Weltkoordinaten und
 * 2D-Automap-Kachelkoordinaten (f_014c20, f_014c80) sowie die zyklische Blink- und Animationsaktualisierung der
 * Automap-Markierungen (f_014cc0).
 === Ende Beschreibung === */
// P3 13/17 gleich (suche.py 29.10.2026, Basis alloc_P1.CPP)
// I9: aus alloc_REST.CPP uebernommen (Stufe-2-Stand), Marken 12 neu
// ALLOC_REST (Helfer A, 22.10.2026): NICHT gleich. Offen: f_014540 16, f_014710 87, f_0149a0 21, f_014b30 35 Befehle (Rest GLEICH, f_014ba0 nur Fuellbytes). Beste Einzelvarianten: 014540=V001, 014710=V000, 014b30=V003 (je Funktion verschieden), diese Datei = V010 (Gesamtbestwert 189).
// alloc.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x014540-0x014DF0. Speicherverwaltung mit Herkunft (Tabelle 2500 Eintraege, Magic-Pruefung), new/delete, radmalloc, Kartenraster.
#include <i86.h>
#include <string.h>
#include <stdio.h>

extern const char alloc_file[];   // 0x1B62F8, Zeichenkette liegt im Original (nicht in dieser Einheit definieren)
struct Ent { unsigned *p; unsigned *e; const char *file; int line; int ser; };
struct Pool {
    void *f_0bda70(long size, const char *file, int line);
    void  f_0bdb00(void *p, int a, int b);
    long  f_0bdbc0();
};
struct Part {
    char b[12];
    Part(); ~Part();
    void f_0fad50(int n, int w, int z);
    void f_0fade0(void *img, short x, short y);
};
struct Mark { const char *file; int line; };
struct Sl { short w; char pad[0x12]; };
struct AMap {
    char a0[9]; short s9; short sb; char a1[0x17 - 0xd]; short s17; short s19; char a2[0x23 - 0x1b]; int i23; int i27;
    char a3[0x89 - 0x2b]; Sl sl[5]; char a4[3]; signed char c0f0; char a5[0x10f - 0xf1]; int f10f;
    void f_016fd0(int idx);
    void f_014c20(short *a, short *b, long px, long py);
    void f_014c80(long *a, long *b, short px, short py);
    void f_014cc0();
};
extern Pool d_1c11a0;
extern Pool *d_1bf240;
extern int d_1a01b4;
extern const char d_1a01b8[];
extern const char d_1a01c8[];
extern const char d_1a01d4[];
extern const char d_1a01e0[];
extern Ent *d_1bc614;
extern short d_1bc61c, d_1bc61e;
extern int d_1bc618, d_1bc610, d_1bc60c, d_1bc608;
extern char d_1bc620[];
extern Mark d_1bc5fc;
extern unsigned d_1bc710, d_1bc714;
extern volatile unsigned d_1c3914;
extern short d_1a0102;
extern short d_1bc74c, d_1bc74e, d_1bc750, d_1bc752;
extern void *d_1a34e0;
void f_1455b5();
int f_051870(const char *s, int z);
void f_0149a0();
void f_0d26e0();
void f_0d2710();
void f_068f40();
void f_145702(int intno, union REGS *in, union REGS *out, struct SREGS *s);
#define NN ((short)0x9c4)
void *f_014710(void *p1);

inline short slot()
{
    short i = d_1bc61c;
    Ent *e = d_1bc614 + i;
    for (; i < NN; i++, e++) { if (e->p == 0) return i; }
    return -1;
}

#define EQ(x,v) (((x)==(v))?1:0)
#pragma inline_depth(0)
#pragma inline_depth(3)
//@ f_014be0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014be0
 * - Aufgabe im Spiel: Initialisiert die vier globalen 16-Bit-Koordinaten bzw. Abmessungen (d_1bc74c = 204,
 *   d_1bc74e = 78, d_1bc750 = 315, d_1bc752 = 196) für den Automap-Anzeigebereich.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Koordinaten d_1bc74c, d_1bc74e, d_1bc750, d_1bc752.
 === Ende Beschreibung === */
void f_014be0()
{
    d_1bc74c = 0xcc;
    d_1bc74e = 0x4e;
    d_1bc750 = 0x13b;
    d_1bc752 = 0xc4;
}

//@ f_014c20
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014c20
 * - Aufgabe im Spiel: Rechnet ein Paar aus 16.16-Festkomma-Weltkoordinaten (px, py) unter Abzug des
 *   Kartenursprungs (i23, i27) und Division durch die Kachelgröße 5 in ganzzahlige 2D-Automap-Rasterkoordinaten
 *   (*a, *b) um.
 * - Eingaben: Impliziter this-Zeiger (AMap), Ausgabezeiger für Raster-X (a) und Raster-Y (b) sowie die
 *   Weltkoordinaten (px, py).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Instanzfelder i23 und i27 (Weltursprung der aktuellen Karte).
 === Ende Beschreibung === */
void AMap::f_014c20(short *a, short *b, long px, long py)
{
    *a = (px / 0x10000 - i23) / 5;
    *b = (py / 0x10000 - i27) / 5;
}

//@ f_014c80
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014c80
 * - Aufgabe im Spiel: Umkehrfunktion zu f_014c20: Sie wandelt 2D-Automap-Rasterkoordinaten (px, py) durch
 *   Multiplikation mit der Kachelgröße 5, Addition des Kartenursprungs (i23, i27) und Linksshift um 16 Bits
 *   zurück in 16.16-Festkomma-Weltkoordinaten (*a, *b).
 * - Eingaben: Impliziter this-Zeiger (AMap), Ausgabezeiger für Welt-X (a) und Welt-Y (b) sowie die
 *   Rasterkoordinaten (px, py).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Instanzfelder i23 und i27.
 === Ende Beschreibung === */
void AMap::f_014c80(long *a, long *b, short px, short py)
{
    *a = (px * 5 + i23) << 16;
    *b = (py * 5 + i27) << 16;
}

//@ f_014cc0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014cc0
 * - Aufgabe im Spiel: Aktualisiert während der geöffneten Automap zeitgesteuert über den globalen Timer d_1c3914
 *   das Blinken des Gruppenpfeils bzw. Cursors: Alle 8 Ticks (d_1bc710) wird das Blinkflag f10f umgeschaltet,
 *   und alle 3 Ticks (d_1bc714) wird die Animationsphase des ausgewählten Slots sl[c0f0].w weitergeschaltet, das
 *   zugehörige Kartensymbol (f_016fd0) neu gezeichnet und der kleine 3x3-Markierungspunkt an der aktuellen
 *   Kartenposition (s9 - s17 + 2, sb - s19 + 2) auf den Bildschirm d_1a34e0 ausgegeben.
 * - Eingaben: Impliziter this-Zeiger (AMap).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Zeitstempel d_1bc710, d_1bc714 und Systemtimer d_1c3914.
 *   - Instanzfelder s9, sb (aktuelle Rasterposition), s17, s19 (Scroll-Offset), c0f0 (aktiver Slot) und f10f
 *     (Blinkphase).
 === Ende Beschreibung === */
void AMap::f_014cc0()
{
    { short v = d_1a0102; if (v & 0xf) f_0d2710(); else f_0d26e0(); }
    if (d_1bc710 < d_1c3914) {
        d_1bc710 = d_1c3914 + 8;
        f10f = (f10f == 0);
    }
    if (d_1bc714 < d_1c3914) {
        d_1bc714 = d_1c3914 + 3;
        sl[c0f0].w = (sl[c0f0].w + 1) % 4;
        f_016fd0(c0f0);
        Part o;
        short x = s9 - s17 - 1;
        short y = sb - s19 - 1;
        o.f_0fad50(3, 3, (int)(f10f == 1 ? d_1a01e0 : d_1a01d4));
        o.f_0fade0(d_1a34e0, x + 3, y + 3);
    }
    f_068f40();
}
