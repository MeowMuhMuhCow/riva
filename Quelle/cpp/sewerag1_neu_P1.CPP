/* === Beschreibung (Katalog) ===
 * Einheit sewerag1_neu (0x0F5110 - 0x0F5250)
 *
 * Überblick
 * Die Einheit sewerag1_neu enthält die Ereignisroutine f_0f5110 für die erste Ebene der Kanalisation von Riva,
 * die den Dialog-/Interaktionsgraphen 0x24 ausführt und überwacht, ob dabei mindestens ein Zählerwert der
 * Graphknoten verringert wurde.
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0f5110-0f5250 aus Quelle/cpp/SEWERAG1.CPP; erster Entwurf, Einbau separat prüfen.
// sewerag1.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x0F5110-0x0F5250. Kanalisation Ebene 1: Zustand aller EintrÃ¤ge merken und prÃ¼fen, ob sich einer verringert hat.
extern const char d_1a6750[];
#define sewerag1_file d_1a6750
#include "R_FIX.H"
#include "RIVAMEM.H"



struct Graph {                                           // 0x14 Bytes, Konstruktor 0x112DF0, Destruktor 0x112E70
    char b[0x14];
    Graph(int a, int b_, int c);
    ~Graph();
    int   f_1131b0();
    short f_1135c0();
    void  f_1136d0(int i, short *x, short *y);
    short f_113500(int id);
    void  f_112ec0();
};
struct Pair { short id, v; };
struct Pair2 { short id, v; Pair2() {} };
extern char d_1c01a0;
//@ f_0f5110
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Legt den Interaktionsgraphen 0x24 (Graph(0x24, 0, 0)) an, sichert vor dessen Ausführung
 *   für alle n Knoten (f_1135c0) deren Knoten-ID y (f_1136d0) und aktuellen Zählerstand f_113500(y) in einem
 *   temporären Array tab, führt den Graphen über g->f_112ec0() aus und prüft anschließend, ob mindestens ein
 *   Knotenzähler kleiner als vor dem Aufruf geworden ist; falls ja, wird das globale
 *   Kanalisations-Fortschrittsflag d_1c01a0 = 1 gesetzt.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 0 (res).
 * - Wichtige Variablen:
 *   - g: Instanz des Interaktionsgraphen 0x24.
 *   - tab: Dynamisch reserviertes Array von n (id, v)-Paaren (Pair) zur Sicherung der Zählerstände vor dem
 *     Dialog.
 *   - d_1c01a0: Globales Ereignisflag der Kanalisation Ebene 1, das bei Verringerung eines Knotenzählers auf 1
 *     gesetzt wird.
 === Ende Beschreibung === */
int f_0f5110()
{
    Pair *tab;
    short n;
    int res = 0;
    short i;
    int hit;
    short j;
    Graph *g = new (mark(sewerag1_file, 1668)) Graph(0x24, 0, 0);
    if (g->f_1131b0()) {
        n = g->f_1135c0();
        tab = new (mark(sewerag1_file, 1691)) Pair[n];
        for (i = 0; i < n; i++) {
            short y, x;
            g->f_1136d0(i, &x, &y);
            tab[i].id = y;
            tab[i].v = g->f_113500(y);
        }
        g->f_112ec0();
        hit = 0;
        for (j = 0; j < n; j++) {
            if (g->f_113500(tab[j].id) < tab[j].v) {
                hit = 1;
                break;
            }
        }
#if FIX_R076   /* R076: Bei Gegenstandsentnahme aus Truhe 0x24 auch Rueckgabewert res = 1 setzen */
        if (hit) { d_1c01a0 = 1; res = 1; }
#else
        if (hit) d_1c01a0 = 1;
#endif
        delete tab;
    }
    delete g;
    return res;
}
