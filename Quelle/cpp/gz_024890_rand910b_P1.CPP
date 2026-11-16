/* === Beschreibung (Katalog) ===
 * Einheit gz_024890_rand910b (0x000248d0 - 0x00024a90)
 *
 * Überblick
 *
 * Die Randeinheit gz_024890_rand910b enthält den statischen Initialisierer für die Katakomben-Variablen
 * (f_0248d0) sowie eine kleine Hilfsklasse (f_0248e0-f_024980), die einen linearen Puffer oder Stapel für die
 * nachfolgende Ressourcen-Cache-Verwaltung (cache) bereitstellt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 6/7 gleich (suche.py 24.10.2026, Basis gz_024890_P1.CPP)
// gz_024890.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x024890-0x024A90
#include <string.h>
struct Msg { void f_0bf730(long code); int f_0bf820(long code, ...); };
extern Msg d_1c2c64;


extern char d_1c349c[], d_1c3870[], d_1c3498[], d_1c2c44[];
extern char d_1bab80[], d_1babc4[], d_1babd8[];
extern int d_1c0004;
void *f_145234(void *p, void *d);
void f_145254();
int f_060030(int p1, int p2);
int f_0b9060(int p1);
int f_10a260(int p1, int p2);
int f_10a270(int p1, int p2);
void f_10a2c0(int p1);
int f_0db8b0(int p1, int p2);
int f_0dbfe0(int p1);
int f_0dbe20(int p1, int p2, int p3);
int f_0de5a0(int p1, int p2);
int f_0de5d0(int p1, int p2);
int f_0de7e0(int p1);
void f_125f70(void *p, int v);
void f_024980(int p1);
//@ f_024890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Meldet die 22 persistenten Flags der Katakomben (BORON2) im Spielstand-Array an; in dieser
 *   Teileinheit nur als Deklaration für f_0248d0 enthalten.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910a.
 === Ende Beschreibung === */
int f_024890(int p1, unsigned p2)
;
//@ f_0248d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird beim Programmstart automatisch ausgeführt und ruft f_024890 auf, um die
 *   Katakomben-Variablen für das Speichern und Laden anzumelden.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert direkt an f_024890.
 === Ende Beschreibung === */
int f_0248d0(int p1, int p2)
{
    int r = f_10a260(p1, (short)p2);
    *(int *)(r + 0x58) = (int)d_1babd8;
    return r;
}
//@ f_0248e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert ein kleines Verwaltungsobjekt, das für die Nachverfolgung geladener Datenblöcke
 *   im Ressourcen-Cache benötigt wird, und legt dessen internes Array an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie die Kapazität beziehungsweise Größe
 *   und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Gespeichert werden der Zeiger auf den reservierten Speicherblock, die Kapazität und der
 *   aktuelle Füllstand des Objekts.
 === Ende Beschreibung === */
int f_0248e0(int p1, unsigned p2)
{
    if (p2 & 4) {
        f_145234((void *)p1, d_1babc4);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0x58) = (int)d_1babd8;
    int u = f_10a270(p1, 1);
    if (p2 & 2) delete (char *)u;
    return u;
}
//@ f_024920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Zählerstand oder Zeigerwert des Verwaltungsobjekts zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this entgegen und liefert den gespeicherten Wert
 *   zurück.
 * - Wichtige Variablen: Gelesen wird das Statusfeld im Verwaltungsobjekt.
 === Ende Beschreibung === */
void f_024920()
{
}
//@ f_024930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den zweiten Kennwert des Verwaltungsobjekts (etwa die maximale Größe) an den Aufrufer
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und gibt den Wert als Ganzzahl zurück.
 * - Wichtige Variablen: Gelesen wird das Größenfeld des Objekts.
 === Ende Beschreibung === */
void f_024930(int p1)
{
    f_10a2c0(p1);
}
//@ f_024940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den intern angeforderten Speicherblock des Verwaltungsobjekts wieder frei und setzt
 *   dessen Zeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this (sowie optionale Destruktor-Flags) entgegen
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben wird der im Konstruktor f_0248e0 angelegte Pufferzeiger.
 === Ende Beschreibung === */
int f_024940(int p1, short p2)
{
    int r = 0;
    switch ((unsigned short)p2) {
    case 0: break;
    case 0x81: f_0b9060(p1); break;
    case 0x9c: f_024980(p1); break;
    case 0x80: r = 1; break;
    }
    return r;
}
//@ f_024980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die Einträge des Verwaltungsobjekts nach einem bestimmten Schlüssel oder Datenblock
 *   und trägt neue Elemente ein, damit der Cache schnell prüfen kann, welche Ressourcen bereits im
 *   Arbeitsspeicher liegen.
 * - Eingaben und Rückgabe: Die Funktion erwartet den Objektzeiger this sowie den gesuchten Schlüssel oder
 *   Blockzeiger und gibt den gefundenen Index beziehungsweise Zeiger zurück.
 * - Wichtige Variablen: Bearbeitet werden das interne Eintrags-Array und der Füllstandszähler des Objekts.
 === Ende Beschreibung === */
void f_024980(int p1)
{
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    short v = *(short *)(p1 + 0x5e) * 0x19 / 100 + 0x19;
    c.tables.tail.short_numbers[1] = v;
    short r = d_1c2c64.f_0bf820(0x1f000001, 2, 0x1f000002, 0x1f000003);
    if (r == 1) {
        short p2 = (short)(v * 10 * f_0dbfe0(d_1c0004));
        if (f_0de7e0(d_1c0004) >= p2) {
            f_0db8b0(d_1c0004, p2);
            f_0dbe20(d_1c0004, 100, 100);
            d_1c2c64.f_0bf730(0x1f000004);
            f_0de5a0(d_1c0004, 4);
            f_125f70(d_1c2c44, 1);
            f_0de5d0(d_1c0004, 4);
        } else {
            d_1c2c64.f_0bf730(0x20000010);
        }
    }
}
