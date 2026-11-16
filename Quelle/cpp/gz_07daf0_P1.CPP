/* === Beschreibung (Katalog) ===
 * Einheit gz_07daf0 (07daf0 - 07dee0)
 *
 * Überblick
 * Die Einheit gz_07daf0 enthält zwei Hilfsfunktionen für die manuelle Bewegungsplanung eines Helden im
 * Rundenkampf: das Zählen der Schritte im aktuellen Pfadpuffer (f_07daf0) und das Prüfen eines vom Spieler
 * angewählten Zielfeldes auf Erreichbarkeit, Aktionspunktekosten und Fluchtrand (f_07db20).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 1/2 gleich (suche.py 26.10.2026, Basis gz_07daf0_P1.CPP)
// P2h 1/2 gleich
// gz_07daf0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07DAF0-0x07DEE0
#include <string.h>
#pragma pack(1)

signed char f_043410(int p1);
int f_071e50(int p1, int p2, int p3, int p4);
int f_071f20(int p1, int p2);
unsigned char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0d12e0(int p1);
unsigned char f_0d54c0(int p1);
extern int d_1bc8f0;
extern signed char d_1bd950[];
extern signed char d_1bd951[];
extern char *d_1bd984;
extern char *d_1c2ed4;
#define MAP(x,y) (*(d_1bd984 + (y) * 0x19 + (x)))

//@ f_07daf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt die Anzahl der Einzelschritte im globalen Bewegungspfadpuffer d_1bd950 bis zur
 *   Endmarkierung -1 und gibt 99 zurück, falls unmittelbar dahinter die Markierung -2 (Ziel nicht erreichbar
 *   bzw. Pfad abgeschnitten) steht.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt die Schrittanzahl (oder 99 bei
 *   unvollständigem Pfad) als short zurück.
 * - Wichtige Variablen: Das Array d_1bd950 speichert die Richtungen der einzelnen Bewegungsschritte bis zum
 *   Sentinel -1.
 === Ende Beschreibung === */
short f_07daf0()
{
    short k;
    k = 0;
    while (d_1bd950[k] != -1) k++;
    if (d_1bd951[k] == -2) k = 99;
    return k;
}

//@ f_07db20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft während der interaktiven Bewegungsauswahl eines Helden (p2), ob das angepeilte Zielfeld
 *   (*x, *y) von der Startposition (*x0, *y0) aus über einen freien Pfad (f_074b40 mit Modus 0xf) erreichbar
 *   ist, berechnet die benötigten Aktionspunkte (*cnt), erkennt Schritte über den Kampffeldrand als
 *   Fluchtversuch (*res = 1) und meldet zurück, ob das Feld frei (0), ein Fluchtfeld (1), wegen AP-Mangel zu
 *   weit entfernt (2), durch ein Hindernis/eine Figur belegt (3) oder ohne gültigen Weg (4) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2, die Zeiger auf die
 *   Zielkoordinaten x und y, die Startkoordinaten x0 und y0 sowie die Ausgabezeiger res (Statuscode 0..4) und
 *   cnt (AP-Kosten) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Für Zielfelder knapp außerhalb des Rasters (*x < 0, *y < 0 oder *y > 23) klemmt mode
 *   (1..3) die Koordinate zunächst auf das Randfeld, berechnet den Pfad dorthin und hängt anschließend den
 *   letzten Ausstiegsschritt vom Schlachtfeld an d_1bd950 an.
 === Ende Beschreibung === */
void f_07db20(int p1, int p2, short *x, short *y, short *x0, short *y0, short *res, short *cnt)
{
    // Haelt die lokale Registersortierung und Additionsreihenfolge wie im Original.
#undef MAP
#define MAP(x,y) (*(*(char **)&d_1bd984 + (y) * 0x19 + (x)))
    short t40_21;
    int ok;
    short mode;
    unsigned char c2, c1;
    short k;
    int n;
    *res = 0;
    *cnt = 0;
    if (*x == *x0 && (t40_21 = *y) == *y0) return;
    mode = 0;
    if (*x < 0 || *y < 0 || *y > 0x17) {
        if (*x < 0) { *x = 0; mode = 1; }
        else if (*y < 0) { *y = 0; mode = 2; }
        else { *y = 0x17; mode = 3; }
        if (MAP(*x, *y) && (*x != *x0 || *y != *y0)) {
            *res = 3;
            if (mode == 1) *x = -1;
            else if (mode == 2) *y = -1;
            else if (mode == 2) *y = 0x18;
            else *y = 0x18;
        } else {
            {
                int rv_ = (int)d_1bd984;
                d_1bd984 = (char *)rv_;
                int a_ = *y * 0x19 + rv_;
                int b_ = *x + a_;
                c2 = *(char *)b_;
            }
        }
    } else {
        c1 = MAP(*x, *y);
    }
    if (*res == 3) return;
    if (mode && *x == *x0 && *y == *y0) {
        d_1bd950[0] = 0xff;
        *cnt = 0;
    } else {
        f_071e50(p1, *x, *y, 0xcb);
        ok = f_074b40(p1, p2, *x0, *y0, 0xf, 1);
        *cnt = f_07daf0();
    }
    ok = (ok & 0) ? 0 : ok;
    if (mode) {
        f_071e50(p1, *x, *y, c2);
        k = 0;
        while (d_1bd950[k] != -1) k++;
        c2 = (c2 & 0) ? 0 : c2;
        if (mode == 1) {
            *x = -1;
            if (f_043410(p2) > *cnt) { d_1bd950[k] = 2; d_1bd951[k] = 0xff; }
        } else if (mode == 2) {
            *y = -1;
            if (f_043410(p2) - 1 > *cnt) { d_1bd950[k] = 1; d_1bd951[k] = 0xff; }
        } else {
            *y = 0x18;
            if (f_043410(p2) - 1 > *cnt) { d_1bd950[k] = 3; d_1bd951[k] = 0xff; }
        }
        (*cnt)++;
    } else {
        f_071e50(p1, *x, *y, c1);
    }
    if (ok == 0) { *res = 4; return; }
    n = f_043410(p2);
    if (*cnt > n) { *res = 2; return; }
    if (f_071f20(*x, *y)) { *res = 1; return; }
    c2 = c1;
    if (c2 < 0x32) {
        if (c2 >= 10) {
            int off;
            if (c2 >= 0x1e) off = 0x14; else off = 0;
            off = (off & 0) ? 0 : off;
            off = (off & 0) ? 0 : off;
            off = (off & 0) ? 0 : off;
            int t_94 = f_0d12e0((int)((c1 - 10 - off) * 0x73 + (*(char **)&d_1c2ed4)));
            if (t_94 != (unsigned short)0) *res = 3;
        } else {
            if (c2 >= 1 && !((char)(f_042470((struct hero *)((*(int *)&d_1bc8f0) + (c2 - 1) * 0x5ef)))) && !((char)(f_0425f0((struct hero *)((*(int *)&d_1bc8f0) + (c2 - 1) * 0x5ef)))) && c2 != f_0d54c0(p2) + 1) *res = 3;
        }
    } else *res = 3;
}
