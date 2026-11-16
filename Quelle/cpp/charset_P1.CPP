/* === Beschreibung (Katalog) ===
 * Einheit charset (0x045B70 - 0x045DB0)
 *
 * Überblick
 * Die Einheit charset implementiert das Laden und Aufbereiten eines proportionalen Spiel-Zeichensatzes
 * (Charset::f_045b70) aus einem Datenarchiv inklusive Breiten-/Höhentabelle, Leerzeichen-Ersatzblock und
 * Zeigertabelle auf die einzelnen Zeichen-Bitmaps.
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 25.10.2026, Basis charset_P1.CPP)
// I9: aus charset_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// charset.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x45B70-0x45DB0. Laedt einen Zeichensatz (Breiten/Hoehen-Tabelle plus Bitmuster) und legt die Zeiger je Zeichen an.
#include <string.h>
extern const char charset_file[];   // Inhalt in der Basis (Fable 30.10.: nicht hier definieren)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
struct Src;
struct Ops { char p0[0x14]; int (*f14)(Src *s, int a, int b); char p18[4]; void (*f1c)(Src *s, void *buf); char p20[8];
             void (*f28)(Src *s); char p2c[4]; unsigned (*f30)(Src *s); };
struct Src { char p0[0x14]; Ops *ops; };
struct Ent { unsigned short w, h; };

struct Charset {
    char p0[8];
    Src *src;
    unsigned short n, maxw, maxh;
    unsigned char *buf;
    char *ptrs[256];
    Ent *tab;
    char *blank;
    int f_045b70(int p2);
};

//@ f_045b70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt aus der Datenquelle src den Zeichensatz mit der Ressourcenkennung p2 in einen neu
 *   angelegten Puffer buf, liest die Zeichenanzahl n sowie die Breiten-/Höhentabelle tab (n Einträge ab buf +
 *   3), ermittelt die maximale Zeichenbreite maxw und -höhe maxh, reserviert einen mit 1 gefüllten Ersatzblock
 *   blank (maxh * maxw Bytes) und trägt für jedes der n Zeichen den Zeiger ptrs[j] auf seine Bitmapdaten (bzw.
 *   bei Breite 0 auf blank, wobei für Steuerzeichen 0xf0..0xf7 die Breite 0 bleibt und für alle anderen leeren
 *   Zeichen auf maxw gesetzt wird) ein.
 * - Eingaben:
 *   - this (Impliziter Zeiger auf das Charset-Objekt).
 *   - p2 (Ressourcen- bzw. Dateikennung des zu ladenden Zeichensatzes).
 * - Rückgabewert: int - 1 bei erfolgreichem Laden und Initialisieren des Zeichensatzes, 0 wenn die Ressource
 *   nicht geöffnet werden konnte.
 * - Wichtige Variablen:
 *   - n, maxw, maxh (Anzahl der Zeichen im Font sowie maximale Zeichenbreite und -höhe in Pixeln).
 *   - buf (Dynamisch reservierter Speicherblock mit den gesamten Rohdaten des Zeichensatzes).
 *   - tab (Zeiger auf das Array der n Zeichenabmessungen Ent { w, h } ab buf + 3).
 *   - blank (Ersatz-Bitmap der Größe maxw * maxh für Zeichen ohne eigene Pixelbreite).
 *   - ptrs (Array von 256 Zeigern auf die einzelnen Zeichen-Bitmaps innerhalb von buf).
 === Ende Beschreibung === */
int Charset::f_045b70(int p2)
{
    n = 0;
    maxw = 0;
    maxh = 0;
    buf = 0;
    memset(ptrs, 0, 0x400);
    int ok = 0;
    if (src->ops->f14(src, p2, 0x200) == 1) {
        unsigned sz = src->ops->f30(src);
        buf = new (mark(charset_file, 0xa9)) unsigned char[sz];
        src->ops->f1c(src, buf);
        src->ops->f28(src);
        n = *(unsigned short *)(buf + 1);
        maxw = 0;
        maxh = 0;
        tab = (Ent *)(buf + 3);
        for (short i = 0; i < n; i++) {
            if (tab[i].w > maxw) maxw = tab[i].w;
            Ent *t = tab;
            if (t[i].h > maxh) maxh = t[i].h;
        }
        blank = new (mark(charset_file, 0xd4)) char[maxh * maxw];
        memset(blank, 1, maxh * maxw);
        {
            unsigned char *data = buf + 3 + n * 4;
            short off = 0;
            for (short j = 0; j < n; j++) {
                if (tab[j].w > 0) {
                    ptrs[j] = (char *)(data + off);
                    off += tab[j].w * maxh;
                } else {
                    if (j < 0xf0 || j > 0xf7) {
                        tab[j].w = maxw;
                        tab[j].h = maxh;
                        ptrs[j] = blank;
                    } else {
                        tab[j].w = 0;
                        tab[j].h = maxh;
                        ptrs[j] = blank;
                    }
                }
            }
        }
        ok = 1;
    }
    return ok;
}
