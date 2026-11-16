/* === Beschreibung (Katalog) ===
 * Einheit gz_04b5f0 (0x04b5f0 - 0x04b770)
 *
 * Überblick
 * Die Einheit gz_04b5f0 enthält drei Navigationsfunktionen für das Charakterblatt (CMask): das Weiterschalten
 * des ausgewählten Inventarslots nach vorne (f_04b5f0) und nach hinten (f_04b670) per Tastatur sowie das
 * Blättern zum nächsten oder vorherigen Helden der Gruppe (f_04b6f0).
 === Ende Beschreibung === */
// P3 0/3 gleich (suche.py 24.10.2026, Basis gz_04b5f0_P1.CPP)
// gz_04b5f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04B5F0-0x04B770
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_039160(int p1, int p2);                           // reg eax edx stapel 0
int f_0391f0(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1bc8f4;                    // 0x1BC8F4
extern char d_1bc930;                    // 0x1BC930
extern short d_1c0004;                    // 0x1C0004
extern int d_1c2198;                    // 0x1C2198
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct M { signed char k; char p1[10]; int a; int b; char p2[10]; short c; char p3; short v; short w; };
int f_04b3a0(int p);
//@ f_04b5f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt den Auswahlrahmen im Inventar des Charakterblatts um einen Slot vorwärts (je nach
 *   eingeblendeter Körperansicht d_1bc930 von Slot 0 bzw. 15 bis 30 oder 32) und springt am Ende wieder auf den
 *   ersten sichtbaren Slot zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bc930 (Körperansicht aktiv) und inkrementiert den Zielslot p->w (im
 *   Tauschmodus) oder den Hauptslot p->v.
 === Ende Beschreibung === */
void f_04b5f0(M *p)
{
    short lim, nv;
    char test;
    test = !d_1bc930;
    lim = test ? 0xf : 0;
    test = !d_1bc930;
    if (test || p->w == -1) nv = 0x1e; else nv = 0x20;
    if (p->w != -1) {
        if (nv == p->w) p->w = lim;
        else p->w = p->w + 1;
    } else {
        if (nv == p->v) { p->v = lim; return; }
        p->v = p->v + 1;
    }
}
//@ f_04b670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt den Auswahlrahmen im Inventar des Charakterblatts um einen Slot rückwärts und springt
 *   beim Unterschreiten des ersten sichtbaren Slots (0 bzw. 15) ans Ende der Slotliste (30 bzw. 32).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bc930 und dekrementiert p->w oder p->v.
 === Ende Beschreibung === */
void f_04b670(M *p)
{
    short lim, nv;
    char test;
    test = !d_1bc930;
    lim = test ? 0xf : 0;
    test = !d_1bc930;
    if (test || p->w == -1) nv = 0x1e; else nv = 0x20;
    if (p->w != -1) {
        if (lim == p->w) p->w = nv;
        else p->w = p->w - 1;
    } else {
        if (lim == p->v) { p->v = nv; return; }
        p->v = p->v - 1;
    }
}
//@ f_04b6f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blättert auf dem Charakterblatt zum nächsten oder vorherigen Helden (f_039160 bzw. f_0391f0)
 *   der aktiven Gruppe d_1c0004. Ist gerade ein Gegenstand zum Übergeben/Tauschen ausgewählt (p->w != -1),
 *   bleibt der Quellheld in p->b erhalten, damit Gegenstände direkt zwischen zwei Helden übergeben werden
 *   können; andernfalls wird die Auswahl über f_04b3a0 zurückgesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Aktualisiert den angezeigten Heldenzeiger p->a sowie d_1bc8f4 und setzt das
 *   Neuzeichnungs-Flag d_1c2198 = 1.
 === Ende Beschreibung === */
void f_04b6f0(M *p)
{
    int r;
    if (p->k > 3) r = f_039160(*(int *)&d_1c0004, p->a);
    else r = f_0391f0(*(int *)&d_1c0004, p->a);
    if (r != p->a) {
        if (p->w != -1) {
            if (!p->c) p->b = p->a;
            p->c = 1;
            *(int *)&d_1bc8f4 = r;
            p->a = r;
        } else {
            p->a = r;
            *(int *)&d_1bc8f4 = r;
            p->b = r;
            p->c = 0;
            f_04b3a0((int)p);
        }
        *(short *)&d_1c2198 = 1;
    }
}
