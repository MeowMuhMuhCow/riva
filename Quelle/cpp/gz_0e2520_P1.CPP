/* === Beschreibung (Katalog) ===
 * Einheit gz_0e2520
 *
 * Diese Einheit bildet den Abschluss von poolgfx.cpp und den Übergang zu poolinit.cpp. Sie enthält eine
 * Hilfsfunktion für rechtsbündig schattierten Text im Pool-Fenster, eine Initialisierungsroutine für die
 * Preisberechnungs-Methodenzeiger des Handelspools sowie die Vergleichsfunktion zum Sortieren von Waren nach
 * ihrem Preis.
 === Ende Beschreibung === */
// P3 2/3 gleich (suche.py 24.10.2026, Basis gz_0e2520_P1.CPP)
// gz_0e2520.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E2520-0x0E2660
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c004c;                    // 0x1C004C
extern int d_1c0050;                    // 0x1C0050
extern int d_1c0054;                    // 0x1C0054
extern int d_1c0058;                    // 0x1C0058
extern int d_1c005c;                    // 0x1C005C
extern int d_1c0060;                    // 0x1C0060
extern int d_1c0064;                    // 0x1C0064
extern int d_1c0068;                    // 0x1C0068
extern int d_1c006c;                    // 0x1C006C
extern int d_1c0070;                    // 0x1C0070
extern int d_1c0074;                    // 0x1C0074
extern int d_1c0078;                    // 0x1C0078
extern int d_1c007c;                    // 0x1C007C
extern int d_1c0080;                    // 0x1C0080
extern int d_1c0084;                    // 0x1C0084
extern int d_1c38b0;                    // 0x1C38B0
int f_0e9690(int p1, int p2);
void f_0e3310(void);
void f_0e3320(void);
void f_0e3330(void);
void f_0e3340(void);
void f_0e3350(void);
struct R6 { char pad[6]; short a; short b; };
//@ f_0e2520
/* === Beschreibung (Katalog) ===
 * Gibt eine Zeichenkette (p2) innerhalb einer Spalte der Breite p5 rechtsbündig ab Basis-X-Koordinate p3 und
 * Y-Koordinate p4 doppelt aus: zuerst um einen Pixel nach rechts versetzt in der Schattenfarbe p7 und darüber an
 * der eigentlichen Zielposition in der Vordergrundfarbe p6.
 * - Eingaben: Übergeben werden ein ungenutzter Kontextparameter p1, der Textzeiger p2, die linke
 *   Spaltenkoordinate p3, die Y-Koordinate p4, die Spaltenbreite p5, die Vordergrundfarbe p6 sowie die
 *   Schattenfarbe p7.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2520(int p1, int p2, int p3, short p4, int p5, short p6, short p7)
{
    p5 -= f_0e9690((int)&d_1c38b0, p2);
    p3 += p5;
    f_05e320((int)&d_1c38b0, p7, -1);
    f_0e9660((int)&d_1c38b0, p2, (short)p3, p4);
    f_05e340((int)&d_1c38b0);
    p3--;
    f_05e320((int)&d_1c38b0, p6, -1);
    f_0e9660((int)&d_1c38b0, p2, (short)p3, p4);
    f_05e340((int)&d_1c38b0);
}
//@ f_0e25b0
/* === Beschreibung (Katalog) ===
 * Initialisiert die globale Tabelle der fünf C++-Memberfunktionszeiger (d_1c004c bis d_1c0084, jeweils 12 Byte
 * pro Eintrag) mit den Adressen der fünf Preisberechnungs-Hilfsfunktionen (f_0e3350, f_0e3340, f_0e3330,
 * f_0e3320, f_0e3310) für die verschiedenen Händler- und Pool-Arten.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e25b0(void)
{
    d_1c004c = (int)f_0e3350;
    d_1c0050 = 0;
    d_1c0054 = 0;
    d_1c0058 = (int)f_0e3340;
    d_1c005c = 0;
    d_1c0060 = 0;
    d_1c0064 = (int)f_0e3330;
    d_1c0068 = 0;
    d_1c006c = 0;
    d_1c0070 = (int)f_0e3320;
    d_1c0074 = 0;
    d_1c0078 = 0;
    d_1c007c = (int)f_0e3310;
    d_1c0080 = 0;
    d_1c0084 = 0;
}
//@ f_0e2630
/* === Beschreibung (Katalog) ===
 * Vergleicht zwei 24-Byte-Pool-Gegenstandseinträge (p1 und p2) anhand ihres Gesamtwerts in Hellern (Einzelpreis
 * a an Offset +0x06 multipliziert mit der Währungseinheit b an Offset +0x08) für qsort (f_14d7dc).
 * - Eingaben: Die Funktion erhält Zeiger auf die beiden zu vergleichenden Pool-Gegenstandseinträge p1 und p2.
 * - Rückgabewert: Sie gibt -1 zurück, wenn der erste Gegenstand billiger ist, 1, wenn er teurer ist, und 0 bei
 *   gleichem Preis.
 === Ende Beschreibung === */
int f_0e2630(struct R6 *p1, struct R6 *p2)
{
    int x = p1->a * p1->b;
    int y = p2->a * p2->b;
    if (x < y) return -1;
    return x != y;
}
