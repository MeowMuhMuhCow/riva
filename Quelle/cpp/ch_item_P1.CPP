/* === Beschreibung (Katalog) ===
 * Einheit ch_item (0x032820 - 0x032AB0)
 *
 * Überblick
 * Die Einheit ch_item implementiert das seitenweise blätterbare Gegenstands-Auswahlmenü für einen Helden
 * (f_032820), in dem bis zu 30 Inventargegenstände in Seiten zu je 12 Einträgen plus einer "Weiter"-Schaltfläche
 * angezeigt und ausgewählt werden können.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 0/1 gleich (suche.py 26.10.2026, Basis ch_item_P1.CPP)
// I9: aus ch_item_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// ch_item.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x032820-0x032AB0. Gegenstandsliste: Auswahlmenue mit Seiten zu je 12 Eintraegen.
// REST: 37 Befehle abweichend (sel liegt im Stapel statt in edx, Rueckgabe-/Schleifenregister, Stapelplatz n+1/sel)
extern const char ch_item_file[];   // Inhalt in der Basis (Fable 30.10.: nicht hier definieren)
extern char d_1c349c[], d_1c3870[], d_1c3498[];
struct Ent { short id; long txt; };
struct Msg {
    void f_0bf6c0(int a);
    int f_0bf820(long p2, int n, ...);
    void f_0bf680();
    void f_0bf730(long code);
};
extern Msg d_1c2c64;
char *f_014540(long size, const char *file, int line);
void operator delete(void *p);
int f_032730(long p1, long p3, Ent *e, char **bufs);


//@ f_032820
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt für einen Helden (p1) ein seitenweises Auswahlmenü seiner passenden
 *   Inventargegenstände (gefiltert über p3 mittels f_032730) mit dem Fragetext p2 dar. Besitzt der Held keinen
 *   passenden Gegenstand, wird die Meldung 0x20000102 ausgegeben und -1 zurückgegeben; bei mehr als 12
 *   Gegenständen blendet die Funktion als 13. Option den Blättertext 0x20000104 ("Weiter") ein und gibt nach
 *   Auswahl eines Gegenstands dessen Inventar-Slot- bzw. Gegenstands-ID zurück.
 * - Eingaben:
 *   - p1 (Zeiger bzw. Kennung des Helden, dessen Gegenstände aufgelistet werden).
 *   - p2 (Textkennung der Überschrift bzw. Eingabeaufforderung des Auswahlmenüs).
 *   - p3 (Filter- oder Modusparameter für die Gegenstandszusammenstellung in f_032730).
 * - Rückgabewert: short - Die Kennung (id) des ausgewählten Gegenstands bzw. Inventarplatzes oder -1 bei leerer
 *   Liste bzw. Abbruch.
 * - Wichtige Variablen:
 *   - bufs (Array von 31 dynamisch zugewiesenen Textpuffern zu je 39 Bytes für die Gegenstandsnamen).
 *   - e (Array von 31 Ent-Strukturen mit Gegenstands-ID id und Textzeiger txt).
 *   - n (Gesamtanzahl der von f_032730 gefundenen Gegenstände).
 *   - off (Startindex der aktuell angezeigten 12er-Seite: 0, 12 oder 24).
 *   - sel (Vom Spieler im Dialog d_1c2c64.f_0bf820 gewählte Optionsnummer 1..i oder -1 bei Abbruch).
 *   - saved (Zwischenspeicher für den ursprünglichen Textzeiger e[k].txt, der vorübergehend durch die
 *     "Weiter"-Textkennung 0x20000104 überschrieben wird).
 === Ende Beschreibung === */
short f_032820(long p1, long p2, long p3)
{
    short result = -1;
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    long saved = 0x20000104;
    c.tables.p[1] = p1;
    char *bufs[31];
    Ent e[31];
    short off;
    short n;
    short sel;
    short i;
    for (i = 0; i < 31; i++) bufs[i] = f_014540(0x27, ch_item_file, 0x117);
    n = f_032730(p1, p3, e, bufs);
    if (n == (short)0) {
        d_1c2c64.f_0bf730(0x20000102);
        for (i = 0; i < 31; i++) delete bufs[i];
        p1 = -1;
        return p1;
    }
    sel = 0;
    off = 0;
    while (sel != -1) {
        short k = -1;
        if (n > 12) {
            if (off == (short)0) {
                i = 13;
                k = 12;
            } else if (n > off + 12) {
                i = 13;
                k = 24;
            } else {
                i = (n + 1) - off;
                k = n;
            }
            saved = e[k].txt;
            e[k].txt = 0x20000104;
        } else i = n;
        d_1c2c64.f_0bf6c0(6);
        sel = d_1c2c64.f_0bf820(p2, i, e[off].txt, e[off+1].txt, e[off+2].txt, e[off+3].txt, e[off+4].txt, e[off+5].txt, e[off+6].txt, e[off+7].txt, e[off+8].txt, e[off+9].txt, e[off+10].txt, e[off+11].txt, e[off+12].txt);
        d_1c2c64.f_0bf680();
        if (k != -1) e[k].txt = saved;
        if (n > 12 && sel == i) {
            off = off + 12;
            if (off >= n) off = 0;
        } else if (sel != -1) {
            result = e[sel + off - 1].id;
            sel = -1;
        }
    }
    for (i = 0; i < 31; i++) delete bufs[i];
    p1 = (unsigned short)result;
    return p1;
}
