/* === Beschreibung (Katalog) ===
 * Einheit gz_01a470_t1 (0x01a470 - 0x01a6a0)
 *
 * Überblick
 * Diese Einheit enthält Steuer- und Aufruf-Wrapper für das Automap-Fenster (Obj aus amap.cpp): das Neuzeichnen
 * der Karte, das Öffnen der Automap im normalen Modus, im Zielauswahl-Modus (z. B. für Teleport-/Reisepunkte)
 * und im Notiz-/Eintragsmodus unter Sichern und Wiederherstellen des Automap-Statusbytes (d_1c21b4).
 === Ende Beschreibung === */
// P3 25/29 gleich (suche.py 28.10.2026, Basis gz_01a470_P1.CPP)
// I9: aus G01A470_REST.CPP uebernommen (Stufe-2-Stand), Marken 8 neu
// STAND 22.10. (Helfer C): NICHT GLEICH. 5D0 19 Bef, 4B0 11, 560 14, 840 27; Stubs 6A0-7F0: Watcom faltet identische Rumpfe (offen: COMDAT/Inline-Klassenmethoden, siehe Lauf 6). 470/490/690/820 Struktur ok
// gz_01a470.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4 (Helfer C)
// Code 0x01A470-0x01A880. Kartenobjekt-Kleinfunktionen (amap/amapanno): Zeichen-Rahmen mit Hilfsobjekt, Stubs, Offsetverschiebung.
#include <string.h>
struct Tmp {                                             // 8-Byte-Hilfsobjekt auf dem Stapel
    Tmp(int a);                                          // 0x01B860
    ~Tmp();                                              // 0x01B880
    void f_01b890(int v);                                // 0x01B890
    unsigned char f_01be20();                            // 0x01BE20
    void f_01bc70(int v);                                // 0x01BC70
    int x, y;
};
#pragma pack(1)
struct Obj {
    signed char id;                                      // +0x00
    char p1[8];
    short s09;                                           // +0x09
    short s0b;                                           // +0x0B
    char p2[0x23 - 0x0D];
    int i23;                                             // +0x23
    int i27;                                             // +0x27
    int i2b;                                             // +0x2B
    char p3[0xfd - 0x2f];
    int fd;                                              // +0xFD
    int f101;                                            // +0x101
    int f105;                                            // +0x105
    char p4[2];
    int f10b;                                            // +0x10B
};
#pragma pack()
struct S8 { unsigned short a, b, c, d; };
#pragma pack(1)
struct AnnoHdr { char magic[4]; short a; short b; short n; long ofs; long end; };
struct AnnoEntry { char b0[4]; unsigned long pos; char b8[4]; };
#pragma pack()
struct AMapAnno {
    unsigned long fileid;
    AnnoHdr *hdr;
    AnnoEntry *ent;
    void f_01a840(unsigned long thr, long delta);
};
void f_015af0(Obj *p, int z);
void f_016580(Obj *p, int z);
int f_0ce650();
#define CE(p) f_0ce650()
void f_018f00(Obj *p);
void f_01b860(Tmp *p, int a);
void f_0d26e0();
void f_0d2710();
int f_0d3860();
extern int d_1c0c4c;
extern signed char d_1c21b4;
extern int d_1a34e0;

struct S4 { int x; };

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_01a470
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a470
 * - Aufgabe im Spiel: Aktualisiert die Automap-Anzeige über f_015af0(p, 0), sofern eine gültige Karten-ID (p->id
 *   != -1) geladen und ein Grafikpuffer (p->i2b != 0) vorhanden ist.
 * - Eingaben: Zeiger auf das Automap-Objekt (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Objektfelder p->id (aktuelle Kartenkennung) und p->i2b (Zeiger auf Kartenpuffer).
 === Ende Beschreibung === */
void f_01a470(Obj *p)
{
    if (p->id != -1 && p->i2b != 0)
        f_015af0(p, 0);
}

//@ f_01a490
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a490
 * - Aufgabe im Spiel: Gibt die Ressourcen der aktuell geladenen Automap über f_016580(p, 0) frei, sofern eine
 *   gültige Karte (p->id != -1) aktiv ist.
 * - Eingaben: Zeiger auf das Automap-Objekt (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Objektfeld p->id.
 === Ende Beschreibung === */
void f_01a490(Obj *p)
{
    if (p->id != -1)
        f_016580(p, 0);
}

//@ f_01a4b0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a4b0
 * - Aufgabe im Spiel: Öffnet den interaktiven Automap-Bildschirm (f_018f00(p)): Vor dem Öffnen wird über das
 *   Hilfsobjekt Tmp das gespeicherte Statusbyte der aktuellen Karte (p->id) abgefragt (f_01be20), daraus das
 *   Anzeige-Flag p->fd = ((a & 1) == 0) abgeleitet und nach dem Schließen der Automap das unterste Bit in
 *   d_1c21b4 passend zum neuen Stand von p->fd zurückgeschrieben (f_01bc70).
 * - Eingaben: Zeiger auf das Automap-Objekt (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Sperrvariable d_1c0c4c und Kartenstatusbyte d_1c21b4.
 *   - Objektfeld p->fd (Anzeige-Umschaltflag der Karte).
 === Ende Beschreibung === */
void f_01a4b0(Obj *p)
{
    CE(p);
    Tmp t(-1);
    d_1c0c4c++;
    t.f_01b890(p->id);
    unsigned char a = t.f_01be20();
    d_1c21b4 = a;
    p->fd = (a & 1) == 0;
    f_018f00(p);
    unsigned char b = t.f_01be20();
    signed char *save = &d_1c21b4;
    *save = b;
    if (p->fd == 1)
        d_1c21b4 = b & 0xfe;
    else
        d_1c21b4 = b | 1;
    t.f_01bc70(d_1c21b4);
    d_1c0c4c--;
}

//@ f_01a560
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a560
 * - Aufgabe im Spiel: Öffnet die Automap im Positionsauswahl-Modus (p->f101 = 1), lässt den Spieler in
 *   f_018f00(p) ein Kartenfeld auswählen und rechnet anschließend die gewählte Rasterposition (p->s09, p->s0b)
 *   in 16.16-Festkomma-Weltkoordinaten (*a, *b) um.
 * - Eingaben: Zeiger auf das Automap-Objekt (p) sowie zwei Ausgabezeiger (a, b) für die gewählten
 *   Weltkoordinaten.
 * - Rückgabewert: Das Ergebnis-Flag p->f10b (ob eine gültige Position gewählt wurde).
 * - Wichtige Variablen:
 *   - Objektfelder p->f101 (Auswahlmodus-Flag), p->f10b (Auswahlergebnis), p->s09/p->s0b (gewählte
 *     Rasterkoordinaten) und p->i23/p->i27 (Kartenursprung).
 === Ende Beschreibung === */
int f_01a560(Obj *p, int *a, int *b)
{
    p->fd = 1;
    p->f101 = 1;
    p->f10b = 0;
    f_018f00(p);
    p->f101 = 0;
    short sa = p->s09;
    short sb = p->s0b;
    *a = (sa * 5 + p->i23) << 16;
    *b = (sb * 5 + p->i27) << 16;
    return p->f10b;
}

//@ f_01a5d0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a5d0
 * - Aufgabe im Spiel: Öffnet die Automap im Spezialmodus p->f105 = 1 (z. B. direktes Eintragen einer
 *   Kartennotiz), führt dabei wie f_01a4b0 das Laden und Zurückschreiben des Karten-Statusbits über Tmp und
 *   d_1c21b4 durch und setzt p->f105 anschließend wieder auf 0 zurück.
 * - Eingaben: Zeiger auf das Automap-Objekt (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Objektfelder p->f105, p->fd sowie globale Variablen d_1c0c4c und d_1c21b4.
 === Ende Beschreibung === */
void f_01a5d0(Obj *p)
{
    Obj *q = p;
    p->f105 = 1;
    CE(p);
    {
    Tmp t(-1);
    d_1c0c4c++;
    t.f_01b890(q->id);
    d_1c21b4 = t.f_01be20();
    p->fd = (d_1c21b4 & 1) == 0;
    f_018f00(p);
    {
        unsigned char b = t.f_01be20();
        signed char *save = &d_1c21b4;
        *save = b;
        if (q->fd == 1)
            d_1c21b4 = b & 0xfe;
        else
            d_1c21b4 = b | 1;
    }
    t.f_01bc70(d_1c21b4);
    d_1c0c4c--;
    }
    p->f105 = 0;
}

//@ f_01a690
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01a690
 * - Aufgabe im Spiel: Initialisiert ein Tmp-Kartenhilfsobjekt (p), indem dessen Konstruktor f_01b860(p, -1) mit
 *   dem Standardwert -1 aufgerufen wird.
 * - Eingaben: Zeiger auf das zu initialisierende Tmp-Objekt (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_01a690(Tmp *p)
{
    f_01b860(p, -1);
}

