/* === Beschreibung (Katalog) ===
 * Einheit gz_0e04f0_t1
 *
 * Diese Einheit gehört zum Übergangsbereich zwischen der Gegenstandslisten-Konvertierung (poolconv.cpp) und der
 * grafischen Darstellung des Waren- und Beutepools (poolgfx.cpp). Sie stellt Hilfsfunktionen bereit, um
 * Gegenstände in einer externen Liste zu suchen und übertragene Pool-Einträge abzugleichen sowie einen
 * Pool-Kopfblock zu initialisieren.
 === Ende Beschreibung === */
// P3 5/6 gleich (suche.py 26.10.2026, Basis gz_0e04f0_P1.CPP)
// gz_0e04f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E04F0-0x0E06F0
#include <string.h>
#include "RIVAMEM.H"



int f_0d3780();
int f_0d3800();
int f_0d3810();
short f_11c320(int p1);
int f_11c580(int p1, int p2);
short f_11c620(int p1, int p2);
void *f_145300(void *p, int c, unsigned n);              // memset
void *f_14d075(void *d, void *s, unsigned n);            // memmove
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1bb558;                  // 0x1BB558
extern short d_1bb55a;                  // 0x1BB55A
extern short d_1c0034;                  // 0x1C0034
extern short d_1c0036;                  // 0x1C0036
extern short d_1c0042;                  // 0x1C0042
extern short d_1c0046;                  // 0x1C0046
extern short d_1c0048;                  // 0x1C0048
//@ f_0e04f0
/* === Beschreibung (Katalog) ===
 * Sucht in einer übergebenen Gegenstandsliste (p1, deren Länge über f_11c320 abgefragt wird) linear nach einem
 * bestimmten Gegenstandsindex p2 (über f_11c620) und liefert dessen Listenposition zurück.
 * - Eingaben: Die Funktion erhält den Zeiger oder das Handle auf die Gegenstandsliste p1 sowie die gesuchte
 *   Gegenstandskennung p2.
 * - Rückgabewert: Sie gibt den nullbasierten Index des gefundenen Eintrags zurück oder -1, falls der Gegenstand
 *   nicht in der Liste enthalten ist.
 === Ende Beschreibung === */
short f_0e04f0(int p1, short p2)
{
    short n = f_11c320(p1);
    short i;
    for (i = 0; i < n; i++) {
        if (f_11c620(p1, i) == p2) return i;
    }
    return -1;
}
//@ f_0e0530
/* === Beschreibung (Katalog) ===
 * Bereinigt ein Array aus 15-Byte-Gegenstandseinträgen (p2 mit *p3 Elementen) nach einer Pool-Transaktion, indem
 * sie markierte Einträge (Bit 0 im Flag-Byte +0x01) zuerst über f_0e04f0 in der externen Liste p1 sucht und dort
 * mittels f_11c580 entfernt. Alle danach noch markierten Einträge werden per Speicherverschiebung (f_14d075)
 * direkt aus dem Array p2 gelöscht, wobei die Eintragsanzahl *p3 entsprechend verringert wird.
 * - Eingaben: Übergeben werden die Gegenstandsliste p1, das Array der 15-Byte-Gegenstandseinträge p2 sowie ein
 *   Zeiger auf die aktuelle Anzahl der Einträge p3.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e0530(int p1, char *p2, short *p3)
{
    int t54_8;
    short i;
    i = 0;
    if (*p3 > (short)0) {
        do {
            char *r = (char *)(i * 0xf);
            r += (int)(*&p2);
            if (r[1] & 1) {
                short j = f_0e04f0((*&p1), *(short *)(r + 4));
                if (j != -1) {
                    p2[i * 0xf + 1] &= 0xfe;
                    f_11c580(p1, j);
                }
            }
            i++;
        } while (i < *p3);
    }
    for (i = 0; i < *p3; i++) {
            if (p2[i * 0xf + 1] & 1) {
                char *r = p2 + i * 0xf;
                f_14d075(r, r + 0xf, (*p3 - i - 1) * 0xf);
                *p3 += -1;
                i--;
            }
    }
}
//@ f_0e0620
/* === Beschreibung (Katalog) ===
 * Initialisiert eine 31 Byte große Verwaltungsstruktur (p), indem die ersten beiden 16-Bit-Worte (p[0] und p[1])
 * auf 0 gesetzt und die folgenden 27 Bytes (0x1b) ab p + 2 per f_145300 (memset) genullt werden.
 * - Eingaben: Die Funktion erwartet einen Zeiger auf die zu initialisierende Struktur p.
 * - Rückgabewert: Sie gibt den übergebenen Strukturzeiger p zurück.
 === Ende Beschreibung === */
void *f_0e0620(short *p)
{
    p[0] = 0;
    p[1] = 0;
    f_145300(p + 2, 0, 0x1b);
    return p;
}