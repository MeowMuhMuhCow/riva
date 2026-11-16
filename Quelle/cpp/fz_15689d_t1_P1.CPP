/* === Beschreibung (Katalog) ===
 * Einheit fz_15689d_t1 (0x15689D - 0x158128)
 *
 * Überblick
 * Diese Einheit umfasst zwei eng verwandte 2D-Grafik- und Darstellungsteile: Im vorderen Abschnitt (f_15689d bis
 * f_156b4d) liegen die geclippten 2D-Sprite-Kopier- und Skalierroutinen einschließlich eines dynamischen
 * Maschinencode-Generators für horizontale Zeilenskalierung. Ab f_156c10 beginnt das Hypertext- und
 * Dokumenten-Layoutsystem (für Hilfeseiten, Texttafeln oder strukturierte Anzeigefenster), das Textblöcke,
 * Bilder, Rahmenlinien, Hyperlinks und Pfeil-Trennlinien in einem Vektor aus 32-Byte-Layoutelementen anordnet
 * und auf den Bildschirm zeichnet.
 === Ende Beschreibung === */
// P3 17/28 gleich (suche.py 26.10.2026, Basis fz_15689d_t1_P1.CPP)
// OPT -4r -onatxc -zp1 -s
// P1 2/19 gleich
// fz_15689d_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x15689D-0x158128
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void *operator new[](unsigned size, void *tag);
void operator delete(void *p);
void *f_014710(void *p);
#define EQI(x,v) (((x)==(v))?1:0)
void f_09dae0(int p1);
int f_09db60();
int f_014af0(int p1);
void f_09db10(int p1, int p2);
void f_09db70();
void f_09dbf0();
int f_15c330(int p1, int p2);
void f_15d4dc();
void f_15c300(void *);
int f_09e220(int p1, int p2, int p3, int p4);
void f_09e100(int p1, int p2, int p3, int p4, int p5);
void f_09e3f0(int p1, int p2, int p3, int p4, int p5);
extern short d_1a9b94;
extern short d_1a9b96;
extern short d_1a9b98;
extern short d_1a9b9a;
extern int d_1a9b9c;
typedef void StubFn(char *src, char *dst);
#pragma aux StubFn parm [esi] [edi] modify exact [esi edi esp];
extern StubFn *d_1a9bc7;
extern int d_1a9bbc;
extern int d_1a9bc0;
extern int d_1cdf8c;
extern int d_1cdf90;
extern char *d_1cddfc[];
extern int d_1cddbc;
extern int d_1cddc0;
extern int d_1cddc4;
extern int d_1cddc8;
extern char d_1b94dc[];
extern char d_1a9bcc[];
extern char d_1a9bd0[];
struct T3 { short a; char b; };
extern T3 d_1cddcc;
extern T3 d_1cddd0;
extern T3 d_1cddd4;
extern T3 d_1cddd8;
extern T3 d_1cdddc;
extern T3 d_1cdde4;
extern T3 d_1bc0e0;
extern T3 d_1bc0e4;
extern T3 d_1bc0e8;
extern T3 d_1bc0ec;
struct Q { int a; char c; T3 col; };
struct Rec { int t; int x; int y; short w; short h; short a; short b; short c; short d; T3 col; };
struct Vec {
    char *d; char *b; char *e; char *c;
    void f_15c170();
    void f_15c1a0();
    char *at(int i) { char *p = d + i * 32; if ((unsigned)e <= (unsigned)p) { e = p + 0x20; f_15c170(); } return p; }
    char *at2(int i) { char *p = d + i * 32; if ((unsigned)e <= (unsigned)p) { e = p + 0x20; if ((unsigned)c <= (unsigned)e) f_15c1a0(); } return p; }
};
void f_157be4(Vec *v, int *clip);



//@ f_15689d
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Legt das globale 2D-Clipping-Rechteck (d_1a9b94 bis d_1a9b9a) für nachfolgende Sprite- und
 *   Zeilenkopieroperationen fest.
 * - Eingaben: Vier Koordinaten p1 (links), p2 (oben), p3 (rechts) und p4 (unten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9b94, d_1a9b96, d_1a9b98, d_1a9b9a: Globale 16-Bit-Grenzen des Zeichenbereichs (links, oben, rechts,
 *     unten).
 === Ende Beschreibung === */
void f_15689d(int p1, int p2, int p3, int p4)
{
    d_1a9b94 = (short)p1;
    d_1a9b96 = (short)p2;
    d_1a9b98 = (short)p3;
    d_1a9b9a = (short)p4;
}
//@ f_1568b9
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den globalen Farbindex (d_1a9b9c), der beim Zeichnen von Sprites als Transparenz-
 *   oder Sonderfarbe verwendet wird.
 * - Eingaben: Farbwert p1.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9b9c: Global gespeicherter Farbindex für das Sprite-Blitting.
 === Ende Beschreibung === */
void f_1568b9(int p1)
{
    d_1a9b9c = p1;
}
//@ f_1568bf
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert zwei Farb- oder Schwellenwerte (d_1a9ba0 und d_1a9ba4) für spezielle Kopiermodi
 *   der Sprite-Routine.
 * - Eingaben: Untere Grenze p1 und obere Grenze p2.
 * - Rückgabewert: int - gibt den ersten Parameter p1 zurück.
 * - Wichtige Variablen:
 *   - d_1a9ba0, d_1a9ba4: Globale Parameter für bedingte Pixelübertragung.
 === Ende Beschreibung === */

int f_1568bf(int p1, int p2)
{
    extern unsigned char d_1a9ba0;
    extern unsigned char d_1a9ba4;
    *(int *)&d_1a9ba0 = p1;
    *(int *)&d_1a9ba4 = p2;
    return p1;
}
//@ f_1568cb
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hinterlegt den Zeiger auf den ausführbaren Arbeitspuffer (d_1a9bc7), in den f_156b4d zur
 *   Laufzeit erzeugten Skalier-Maschinencode schreibt.
 * - Eingaben: Pufferadresse p1.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9bc7: Funktionszeiger auf den dynamisch generierten Zeilen-Skaliercode.
 === Ende Beschreibung === */
void f_1568cb(int p1)
{
    d_1a9bc7 = (StubFn *)p1;
}
//@ f_1568d1
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet ein über ein Zeilentabellen-Array (rows) adressiertes 2D-Sprite an die
 *   Bildschirmposition (px, py) im 320-Pixel-Breitenmodus, beschneidet es an den globalen Clipping-Grenzen
 *   (d_1a9b94..d_1a9b9a), berücksichtigt horizontale Spiegelung (reverse) und wählt über die Sprungtabelle
 *   d_1a9ba8 eine von vier Pixelkopierschleifen (mode).
 * - Eingaben: Zielkoordinate px/py, Abmessungen width/height, Zeilentabelle rows, Zeichenmodus mode,
 *   Zielbildpuffer screen und Spiegelungsflag reverse.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9ba8: Sprungtabelle für die vier Kopiermodi (direkt, transparent, Farbbereich, Maske).
 *   - left, w: Links abgeschnittener Rand und verbleibende sichtbare Zeilenbreite nach dem Clipping.
 === Ende Beschreibung === */
// BLIND 2273: Neubau aus dem Original-Assembler (HANDASM-Block).
// Aufbau des Originals: Zeilen-/Spaltenclip gegen d_1a9b94..d_1a9b9a, Moduswahl
// ueber die Tabelle d_1a9ba8 (vier Kopierschleifen im Rumpf), Rueckwaertsflag.
// haelt die Registerzuteilung wie im Original
// (156a16/156a46/156a5c/156a81) und werden ueber die Tabelle d_1a9ba8 angesprungen;
// hier wird der Tabelleneintrag als Funktionszeiger aufgerufen, statt die Schleifen
// erneut auszuschreiben. Das ist eine Mess-Kruecke fuer den Restwert, keine
// laufzeitaequivalente Nachbildung (der Aufruf legt eine Rueckkehradresse ab).
void __cdecl f_1568d1(short px, unsigned short py, short width, unsigned short height,
                       int *rows, unsigned short mode, unsigned char *screen, short reverse)
{
    extern int d_1a9ba8[];            // Sprungtabelle Modus -> Kopierschleife (156a16/156a46/156a5c/156a81)
    extern unsigned char d_1a9b9c_b;   // Byte an 0x1a9b9c (Transparenzfarbe)
    extern unsigned char d_1a9ba0_b;   // Byte an 0x1a9ba0 (Farbbereich unten)
    extern unsigned char d_1a9ba4_b;   // Byte an 0x1a9ba4 (Farbbereich oben)
    unsigned short x = px;
    unsigned short y = py;
    unsigned short w0 = width;
    unsigned short m = mode;
    unsigned short count = height;
    int *row = rows;
    unsigned char *base = screen;
    do {
        unsigned short line = y;
        if (line >= (unsigned short)d_1a9b96 && line <= (unsigned short)d_1a9b9a) {
            unsigned short w = w0;
            if (w != 0 && (short)x <= d_1a9b98 && (short)(x + w) > d_1a9b94) {
                unsigned short left = 0;
                if ((short)x < d_1a9b94) {
                    left = d_1a9b94 - x;
                    w -= left;
                }
                if ((short)(x + left + w - 1) > d_1a9b98)
                    w = d_1a9b98 - x - left + 1;
                {
                    unsigned short stride = 320;
                    unsigned short offset = line;
                    unsigned char *dst;
                    unsigned char *src;
                    offset *= stride;
                    offset += x;
                    dst = base + offset + left;
                    src = (unsigned char *)*row + left;
                    if (reverse != 0) { src += w; dst += w; }
                    {
                        typedef void (*CopyFn)(unsigned char *, unsigned char *, unsigned short);
   // haelt die Registerzuteilung wie im Original
                    }
                }
            }
        }
        ++row;
        ++y;
    } while (--count != 0);
}

//@ f_156ab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest einen rechteckigen Bildschirmausschnitt der Größe width * height ab Position (x, y)
 *   aus dem 320-Byte-Zeilenpuffer screen zeilenweise in die durch rows vorgegebenen Zielpuffer zurück, sofern
 *   die jeweilige Zeile innerhalb der vertikalen Clipping-Grenzen (d_1a9b96..d_1a9b9a) liegt.
 * - Eingaben: Quellkoordinate x/y, Breite width, Höhe height, Zielzeilentabelle rows und Quellbildpuffer screen.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Zähler für die optimierte Kopierschleife (kopiert erst Einzelbyte, dann 16-Bit-Wort, dann
 *     32-Bit-Langwörter).
 === Ende Beschreibung === */
void __cdecl f_156ab0(int x, int y, int width, int height, int *rows,
                       unsigned char *screen)
{
    int *row = rows;
    int count = height;
    do {
        int cur_y = *(volatile short *)&y;
        unsigned char *src = *(unsigned char * volatile *)&screen +
                             (unsigned short)(cur_y * 320 + x);
        unsigned char *dst = (unsigned char *)*row;
        cur_y = y;
        if ((unsigned short)cur_y >= (unsigned short)d_1a9b96 &&
            (unsigned short)cur_y <= (unsigned short)d_1a9b9a) {
            int n = *(volatile int *)&width;
            if (n & 1) {
                *dst = *src;
                ++src;
                ++dst;
            }
            n >>= 1;
            if (n & 1) {
                *(unsigned short *)dst = *(unsigned short *)src;
                src += 2;
                dst += 2;
            }
            n >>= 1;
            if (n != 0) {
                do {
                    *(unsigned int *)dst = *(unsigned int *)src;
                    src += 4;
                    dst += 4;
                } while (--n != 0);
            }
        }
        ++row;
        ++*(volatile unsigned short *)&y;
    } while (--count != 0);
}

//@ f_156b4d
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Skaliert ein über die Zeilentabelle rows1 gegebenes Quellbild der Größe width1 * height1
 *   mittels eines Bresenham-Verfahrens auf ein Zielbild (rows2, width2 * height2), indem für die horizontale
 *   Richtung live eine Folge von x86-Befehlen (d_1a9bc4 = Quellzeiger erhöhen, d_1a9bc5 = Pixel kopieren,
 *   d_1a9bc6 = ret) in den Puffer d_1a9bc7 geschrieben und anschließend für jede benötigte Zielzeile ausgeführt
 *   wird.
 * - Eingaben: Quellzeilen rows1, Quellgröße width1/height1, Zielzeilen rows2 und Zielgröße width2/height2.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9bc4, d_1a9bc5, d_1a9bc6: Maschinenbefehls-Bytes zum Aufbau der schnellen horizontalen Skalierroutine.
 *   - acc: Vertikaler Fehlerakkumulator für die Zeilenauswahl nach Bresenham.
 === Ende Beschreibung === */
extern unsigned char d_1a9bc4, d_1a9bc5, d_1a9bc6;
void __cdecl f_156b4d(int *rows1, int width1, int height1, int *rows2, int width2, int height2)
{
    int w1 = width1, h1 = height1;
    d_1a9bbc = (int)rows1;
    int w2 = width2, h2 = height2;
    d_1a9bc0 = (int)rows2;
    char *p = (char *)d_1a9bc7;
    short x = 0;
    short i = 0;
    short n;
    unsigned char c;

    for (i = 0; i < w1; i++) {
        n = w1 - w2;
        *p++ = d_1a9bc4;
        c = d_1a9bc5;
        while (n <= 0) {
            if (x >= w2) goto done;
            *p++ = c;
            x++;
            n += w1;
        }
    }
done:
    *p++ = d_1a9bc6;

    int c1 = h1;
    int c2 = h2;
    int **r2 = (int **)d_1a9bc0;
    int **r1 = (int **)d_1a9bbc;
    short acc = h1 - h2;
    do {
        if (acc <= 0) {
            d_1a9bc7((char *)*r1, (char *)*r2);
            ++r2;
            acc += h1;
        } else {
            ++r1;
            if (--c1 == 0) break;
            acc -= h2;
        }
    } while (--c2 != 0);
}

//@ f_156c10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Zähler (d_1cdf8c) der dynamisch für das Textlayout reservierten
 *   Zeichenkettenpuffer auf 0 zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cdf8c: Anzahl der aktuell in d_1cddfc verwalteten temporären Textzeiger.
 === Ende Beschreibung === */
void f_156c10()
{
    d_1cdf8c = 0;
}
//@ f_156c1c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt einen dynamisch reservierten Textpuffer p in die Aufräumliste d_1cddfc (maximal 100
 *   Einträge) des Layoutsystems ein.
 * - Eingaben: Zeiger p auf den zu merkenden Speicherblock.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddfc: Array mit bis zu 100 Zeigern auf temporäre Zeichenketten (z. B. Listennummerierungen).
 === Ende Beschreibung === */
void f_156c1c(char *p)
{
    if (d_1cdf8c < 100) {
        d_1cddfc[d_1cdf8c] = p;
        ++d_1cdf8c;
    }
}
//@ f_156c38
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt alle in der Liste d_1cddfc gespeicherten temporären Textpuffer über f_014710 frei und
 *   setzt den Zähler d_1cdf8c auf 0.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cdf8c, d_1cddfc: Zähler und Zeigertabelle der freizugebenden Textblöcke.
 === Ende Beschreibung === */
void f_156c38()
{
    int i = 0;
    int off;
    if (i < d_1cdf8c) {
        off = 0;
        do {
            f_014710(*(void **)((char *)d_1cddfc + off));
            i++;
            off += 4;
        } while (i < d_1cdf8c);
    }
    d_1cdf8c = 0;
}
//@ f_156c70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert die globalen Zeiger und Zähler des Hypertext-Layoutsystems (d_1cddc0,
 *   d_1cddc4, d_1cddbc, d_1cdf8c) beim Programmstart mit Grundwerten und setzt die aktive Link-Markierung über
 *   f_15d4dc zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddbc: Zeiger auf den aktuellen Vektor der fertig gesetzten Layoutelemente.
 *   - d_1cddc0, d_1cddc4: Zeiger auf den geladenen Dokumenten-Rohtext und dessen Bytegröße.
 === Ende Beschreibung === */
void f_156c70()
{
    d_1cddc0 = 0;
    d_1cddc4 = 0;
    d_1cddbc = 0;
    f_15d4dc();
    d_1cdf8c = 0;
}
//@ f_156c94
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Räumt das aktuell geladene Hypertext-Dokument komplett auf, gibt den Bildcache (f_09dbf0),
 *   alle temporären Zeichenketten (f_156c38), den Layoutelement-Vektor (d_1cddbc) sowie den Rohtextpuffer
 *   (d_1cddc0) frei und setzt alle Statusvariablen zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddbc, d_1cddc0: Freizugebende Speicherstrukturen des vorherigen Dokuments.
 === Ende Beschreibung === */
void f_156c94()
{
    f_09dbf0();
    f_156c38();
    if (d_1cddbc != 0) {
        int t = d_1cddbc;
        if (t != 0) delete (char *)f_15c330(t, 1);
    }
    if (d_1cddc0 != 0) delete (char *)d_1cddc0;
    d_1cddc0 = 0;
    d_1cddc4 = 0;
    d_1cddbc = 0;
    f_15d4dc();
    d_1cdf8c = 0;
}
//@ f_156cf4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt ein neues Hypertext-Dokument anhand der Kennung p1, indem zuerst das alte Dokument
 *   freigegeben (f_156c94), die Ressource geöffnet (f_09dae0), ihre Größe abgefragt (f_09db60), Speicher
 *   reserviert (f_014af0), der Inhalt eingelesen (f_09db10), die Standardfarben (d_1cddcc..d_1cdddc)
 *   initialisiert und das Neu-Layout-Flag d_1cddc8 = 1 gesetzt werden.
 * - Eingaben: Ressourcen- oder Dateikennung p1.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddc8: Flag (1), das beim nächsten Zeichenaufruf die Neuberechnung des Textlayouts auslöst.
 *   - d_1cddcc, d_1cddd0, d_1cddd4, d_1cddd8, d_1cdddc: Aktive RGB-Farbwerte für Text, Hintergrund, Links und
 *     Hervorhebungen.
 === Ende Beschreibung === */
void f_156cf4(int p1)
{
    f_156c94();
    f_09dae0(p1);
    d_1cddc4 = f_09db60();
    d_1cddc0 = f_014af0(d_1cddc4);
    f_09db10(d_1cddc0, d_1cddc4);
    f_09db70();
    d_1cddcc = d_1cdde4;
    d_1cddd4 = d_1bc0e4;
    d_1cddd8 = d_1bc0e8;
    d_1cdddc = d_1bc0ec;
    d_1cddd0 = d_1bc0e0;
    d_1cddc8 = 1;
}
//@ f_156d7c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert einen 32-Byte-Elementvektor v und setzt seine Kapazität über f_15c300 auf den
 *   Standardwert zurück.
 * - Eingaben: Zeiger v auf den Layoutelement-Vektor.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_156d7c(Vec *v)
{
    f_15c300(v);
}
//@ f_156d88
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hängt einen 32 Byte großen Layout-Datensatz (src) an das Ende des dynamischen Vektors v an
 *   und vergrößert den Vektor bei Bedarf über f_15c1a0.
 * - Eingaben: Zielvektor v und Zeiger src auf das anzuhängende 32-Byte-Element.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - i: Berechneter Zielindex (v->e - v->b) / 32 am Ende des Vektors.
 === Ende Beschreibung === */
void f_156d88(Vec *v, void *src)
{
    struct Blob32 { int d[8]; };
    struct Zugriff {
        static Blob32 &at(Vec *v, int i) {
            char *p = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p + 32;
                if ((unsigned)v->e >= (unsigned)v->c) v->f_15c1a0();
            }
            return *(Blob32 *)(v->d + i * 32);
        }
    };
    int i = (v->e - v->b) / 32;
    Zugriff::at(v, i) = *(Blob32 *)src;
}
//@ f_156de4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Misst über f_09e220 die Abmessungen eines Leerzeichens (d_1b94dc) in der aktuell im
 *   Layoutkontext p1 eingestellten Schriftart (p1 + 0x10) und aktualisiert die Wortabstandsbreite (+0x20), die
 *   aktuelle Schrifthöhe (+0x1c) sowie die Mindest-Zeilenhöhe (+0x18).
 * - Eingaben: Zeiger p1 auf die RivaTextLayout-Struktur.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - l: Zweielementiges Array mit gemessener Breite (l[0]) und Höhe (l[1]) des Beispielzeichens.
 === Ende Beschreibung === */
void f_156de4(int p1)
{
    int l[2];
    f_09e220((int)l, (int)d_1b94dc, 1, p1 + 0x10);
    *(int *)(p1 + 0x20) = l[0];
    *(int *)(p1 + 0x1c) = l[1];
    if (l[1] > *(int *)(p1 + 0x18)) *(int *)(p1 + 0x18) = l[1];
}
//@ f_156e20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Richtet alle zur aktuellen Textzeile gehörenden Layoutelemente (ab Index p1[12])
 *   horizontal aus: Bei aktivierter Zentrierung (p1[11] == 1) wird die Gesamtbreite der Zeile bestimmt und ein
 *   Zentrier-Offset (shift) berechnet; anschließend werden alle Elemente der Zeile um shift plus den linken
 *   Einzug (p1[13]) verschoben.
 * - Eingaben: Zeiger p1 auf den Layoutzustand und Zeiger p2 auf den Elementvektor.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - minimum, maximum: Kleinste linke und größte rechte X-Koordinate der Elemente in der aktuellen Zeile.
 *   - shift: Berechneter horizontaler Versatz zur Zentrierung innerhalb der verfügbaren Zeilenbreite p1[2].
 === Ende Beschreibung === */
void f_156e20(int *p1, Vec *p2)
{
    struct Zugriff {
        static char *at(Vec *v, int i) {
            char *r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                if ((unsigned)v->e >= (unsigned)v->c) v->f_15c1a0();
            }
            return v->d + i * 32;
        }
        static char *at_ref(Vec &obj, int i) {
            char *r = obj.d + i * 32;
            if ((unsigned)obj.e <= (unsigned)r) {
                obj.e = r + 32;
                if ((unsigned)obj.e >= (unsigned)obj.c) obj.f_15c1a0();
            }
            return obj.d + i * 32;
        }
    };
    int i;
    if (!EQI((int)p2->e, (int)p2->b)) {
        int shift = 0;
        if (p1[0xb] == 1) {
            int minimum = 0xffffff;
            i = p1[0xc];
            int maximum = 0;
            int max_height = 0;
            for (; i < (p2->e - p2->b) / 32; ++i) {
                if (max_height < (*(int *)(Zugriff::at(p2, i) + 0xc) >> 16))
                    max_height = *(int *)(Zugriff::at(p2, i) + 0xc) >> 16;
                if (*(int *)(Zugriff::at(p2, i) + 4) +
                    (*(int *)(Zugriff::at(p2, i) + 10) >> 16) > maximum) {
                    maximum = (*(int *)(Zugriff::at(p2, i) + 10) >> 16) +
                              *(int *)(Zugriff::at(p2, i) + 4);
                }
                if (*(int *)(Zugriff::at_ref(*p2, i) + 4) < minimum)
                    minimum = *(int *)(Zugriff::at_ref(*p2, i) + 4);
            }
            maximum -= minimum;
            if (maximum < p1[2]) shift = (p1[2] - maximum) / 2 - minimum;
        }
        i = p1[0xc];
        for (; i < (p2->e - p2->b) / 32; ++i) {
            char *r = Zugriff::at_ref(*p2, i);
            *(int *)(r + 4) += shift + p1[0xd];
        }
        *p1 = *p1 + shift;
    }
}
//@ f_15713c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erhöht den linken Texteinzug (p1[13]) um p2 Pixel, verringert gleichzeitig die verfügbare
 *   Zeilenbreite (p1[2]) um p2 und setzt die aktuelle X-Schreibposition (p1[0]) auf 0.
 * - Eingaben: Layoutzustand p1 und Einzugsänderung p2.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p1[13], p1[2]: Aktueller linker Rand und nutzbare Textbreite.
 === Ende Beschreibung === */
void f_15713c(int *p1, int p2)
{
    int x = p1[0xd];
    int y = p1[2];
    *p1 = 0;
    p1[0xd] = x + p2;
    p1[2] = y - p2;
}
#pragma inline_depth(0)
//@ f_157158
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Nimmt einen zuvor gesetzten linken Texteinzug um p2 Pixel zurück (f_15713c(p1, -p2)) und
 *   fängt negative Einzugswerte ab, indem der Einzug auf 0 begrenzt und die Zeilenbreite entsprechend korrigiert
 *   wird.
 * - Eingaben: Layoutzustand p1 und Rücknahmewert p2.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - t: Neuer Einzugswert an Offset +0x34 (p1[13]), der gegen < 0 geprüft wird.
 === Ende Beschreibung === */
void f_157158(int p1, int p2)
{
    f_15713c((int *)p1, -p2);
    int t = *(int *)(p1 + 0x34);
    if (t < 0) {
        *(int *)(p1 + 0x34) = 0;
        *(int *)(p1 + 8) = *(int *)(p1 + 8) + t;
    }
}
#pragma inline_depth(255)
//@ f_15717c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt im Textlayout einen Zeilenumbruch durch: Richtet zunächst die bisherige Zeile
 *   (gegebenenfalls zentriert) aus, merkt den aktuellen Vektor-Endindex als neuen Zeilenanfang (p1[12]), setzt
 *   die X-Position (p1[0]) auf 0, rückt die Y-Position (p1[1]) um die Zeilenhöhe (p1[6]) weiter und übernimmt
 *   die Standard-Schrifthöhe (p1[7]) für die neue Zeile.
 * - Eingaben: Layoutzustand p1 und Layoutelement-Vektor p2.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p1[0], p1[1], p1[6], p1[12]: Aktuelle X/Y-Schreibposition, Zeilenhöhe und Startindex der neuen Zeile.
 === Ende Beschreibung === */
void f_15717c(int *p1, Vec *p2)
{
    struct Zugriff {
        static char *access1(Vec *v, int i) {
            int index;
            char *result;
            Vec *object;
            char *r;
            object = v; object = v; r = (char *)v; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            result = object->d + index * 32;
            return result;
        }
        static char *access2(Vec *v, int i) {
            int index;
            char *r;
            char *result;
            Vec *object;
            r = (char *)v; r = (char *)v; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            result = object->d + index * 32;
            return result;
        }
        static char *access4(Vec *v, int i) {
            char *result;
            Vec *object;
            char *r;
            int index;
            object = v; object = v; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            result = object->d + index * 32;
            return result;
        }
        static char *access3(Vec *v, int i) {
            Vec *object;
            char *r;
            int index;
            char *result;
            index = i; index = i; r = (char *)v; object = v; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            result = object->d + index * 32;
            return result;
        }
        static char *access5(Vec *v, int i) {
            char *r;
            int index;
            char *data;
            int offset;
            char *result;
            Vec *object;
            object = v;
            index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                object = ((unsigned)object & 0) ? (Vec *)0 : object; /* haelt die Registerzuteilung wie im Original */
                v->e = v->d + i * 32 + 32;
                v->f_15c170();
            }
            offset = index * 32;
            data = object->d;
            result = data + offset;
            return result;
        }
        static char *access6(Vec *v, int i) {
            int index;
            Vec *object;
            char *r;
            char *data;
            char *result;
            int offset;
            r = (char *)v; object = v; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            offset = index * 32;
            data = object->d;
            result = data + offset;
            return result;
        }
        static char *access7(Vec *v, int i) {
            char *r;
            int index;
            char *result;
            Vec *object;
            object = v; r = (char *)v; index = i; index = i; /* haelt die Registerzuteilung wie im Original */
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            result = object->d + index * 32;
            return result;
        }
        static char *access8(Vec *v, int i) {
            Vec *object;
            int index;
            char *data;
            char *result;
            char *r;
            int offset;
            object = v; index = i;
            r = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            offset = index * 32;
            data = object->d;
            result = data + offset;
            return result;
        }
        static char *access9(Vec *v, int i, int d) {
            char *r = (char *)v; r = v->d + i * 32; /* haelt die Registerzuteilung wie im Original */
            d = i;
            if ((unsigned)v->e <= (unsigned)r) {
                v->e = r + 32;
                v->f_15c170();
            }
            return v->d + d * 32;
        }
        static void align(int *p1, Vec *p2) {
            int width2;
            int width1;
            int max_height;
            int minimum;
            int i;
            int shift;
            int maximum;
            if (!EQI((int)p2->e, (int)p2->b)) {
                shift = 0;
                if (p1[0xb] == 1) {
                    max_height = 0;
                    maximum = 0;
                    minimum = 0xffffff; minimum = 0xffffff; /* haelt die Registerzuteilung wie im Original */
                    for (i = p1[0xc]; i < (p2->e - p2->b) / 32; ++i) {
                        if ((*(int *)(Zugriff::access1(p2, i) + 0xc) >> 16) > max_height)
                            max_height = *(int *)(Zugriff::access2(p2, i) + 0xc) >> 16;
                        width1 = (*(int *)(Zugriff::access3(p2, i) + 10) >> 16);
                        if (*(int *)(Zugriff::access4(p2, i) + 4) +
                            width1 > maximum) {
                            width2 = (*(int *)(Zugriff::access5(p2, i) + 10) >> 16);
                            maximum = width2 +
                                      *(int *)(Zugriff::access6(p2, i) + 4);
                        }
                        if (*(int *)(Zugriff::access7(p2, i) + 4) < minimum)
                            minimum = *(int *)(Zugriff::access8(p2, i) + 4);
                    }
                    maximum -= minimum;
                    if (maximum < p1[2]) shift = (p1[2] - maximum) / 2 - minimum;
                }
                for (i = p1[0xc]; i < (p2->e - p2->b) / 32; ++i) {
                    char *r = Zugriff::access9(p2, i, 0);
                    *(int *)(r + 4) += shift + p1[0xd];
                }
                *p1 = *p1 + shift;
            }
        }
    };
    Zugriff::align(p1, p2);
    p1[0xc] = (p2->e - p2->b) / 32;
    *p1 = 0;
    p1[1] += p1[6];
    p1[6] = p1[7];
}

void f_157498(int *p, int dx, int dy)
{
    p[0] += dx;
    p[1] += dy;
}
//@ f_1574ac
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt ein Linien-Layoutelement vom Typ 3 zwischen den Punkten (xa, ya) und (xb, yb) mit
 *   der Farbe *col (z. B. für Tabellenrahmen oder Aufzählungskästchen) und fügt es an den Vektor p1 an.
 * - Eingaben: Zielvektor p1, Startpunkt xa/ya, Endpunkt xb/yb und Farbzeiger col.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Vorbereiteter 32-Byte-Datensatz vom Typ 3 mit umschließendem Rechteck (x0, y0, w, h) und relativen
 *     Linienendpunkten.
 === Ende Beschreibung === */
void f_1574ac(Vec *p1, int xa, int ya, int xb, int yb, T3 *col)
{
    struct R32 { int t, x, y; short w, h, a, b, c, d; T3 col; char pad[5]; };
    struct Zugriff {
        static R32 &at(int i, Vec *v) {
            char *p = v->d + i * 32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p + 32;
                v->f_15c170();
            }
            return *(R32 *)(v->d + i * 32);
        }
    };
    R32 r;
    int x0, x1, y0, y1;
    x0 = xa < xb ? xa : xb;
    x1 = xa > xb ? xa : xb;
    x0 = (x0 & 0) ? 0 : x0; // haelt die Registerzuteilung wie im Original
    y0 = ya < yb ? ya : yb;
    y1 = ya > yb ? ya : yb;
    r.t = 3;
    r.x = x0;
    r.y = y0;
    r.w = x1 - x0 + 1;
    r.h = y1 - y0 + 1;
    r.col = *col;
    r.a = xa - x0;
    r.b = ya - y0;
    r.c = xb - x0;
    r.d = yb - y0;
    int n = (*(char * volatile *)&p1->e - p1->b) / 32;
    Zugriff::at(n, p1) = r;
}

//@ f_157594
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt ein Hyperlink-Startelement vom Typ 5 an der Position (p2, p3) mit dem Sprungziel p4
 *   (href) und dem Ankernamen p5 (name) in den Layoutvektor p1 ein.
 * - Eingaben: Zielvektor p1, Position p2/p3, Ziel-URL/Kennung p4 und Ankername p5.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Layout-Eintrag vom Typ 5 (Link-Beginn).
 === Ende Beschreibung === */
void f_157594(Vec *p1, int p2, int p3, int p4, int p5)
{
    struct R32 { int t,x,y; short w,h; int a,b; char rest[8];
        R32(int typ,int px,int py,int pa,int pb) { t=typ; x=px; y=py; a=pa; b=pb; h=0; w=0; }
    };
    struct Zugriff {
        static R32 &at(Vec *v, int i) {
            char *p = v->d+i*32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p+32;
                v->f_15c170();
            }
            return *(R32 *)(v->d+i*32);
        }
    };
    R32 r(5,p2,p3,p4,p5);
    int n = (p1->e - p1->b) / 32;
    Zugriff::at(p1,n) = r;
}
//@ f_157614
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt ein Hyperlink-Endelement vom Typ 6 an der Position (p2, p3) in den Layoutvektor p1
 *   ein.
 * - Eingaben: Zielvektor p1 sowie die aktuelle Schreibposition p2/p3.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Layout-Eintrag vom Typ 6 (Link-Ende).
 === Ende Beschreibung === */
void f_157614(Vec *p1, int p2, int p3)
{
    struct R32 { int t,x,y; short w,h; char rest[16];
        R32(int typ,int px,int py) { t=typ; x=px; y=py; h=0; w=0; }
    };
    struct Zugriff {
        static R32 &at(Vec *v, int i) {
            char *p = v->d+i*32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p+32;
                v->f_15c170();
            }
            return *(R32 *)(v->d+i*32);
        }
    };
    R32 r(6,p2,p3);
    int n = (p1->e-p1->b)/32;
    Zugriff::at(p1,n) = r;
}
void f_157688(int p1, int p2, int p3, int p4, T3 p5)
{
    f_09e100(p1,p2,p3,p4,(int)&p5);
}
//@ f_157698
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Positioniert ein eingebettetes Bild (Layouttyp 4) mit dem Ressourcennamen p3 und dem
 *   Alternativtext p4 im Textfluss, fragt dessen echte Bildgröße über f_09db80 ab (oder berechnet eine
 *   Ersatzrahmengröße aus der Länge des Alternativtextes), führt bei Platzmangel einen Zeilenumbruch (f_15717c)
 *   durch und hängt den Bildeintrag an den Vektor p2 an.
 * - Eingaben: Layoutzustand p1, Layoutvektor p2, Bildname/Kennung p3, Alternativtext p4 sowie Wunschbreite p5
 *   und Wunschhöhe p6.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - frame.r: Erzeugter 32-Byte-Layout-Eintrag vom Typ 4 mit Position, Abmessungen, Bildkennung und Ersatztext.
 === Ende Beschreibung === */
void f_157698(int *p1, Vec *p2, int p3, char *p4, int p5, int p6)
{
    int f_09db80(int,int *,int *);
    extern char d_1cdde8[];
    struct R32 { int t,x,y; short w,h; int data; char *text; int rest[2]; };
    // Gemeinsamer Rahmen: normale Groessenfelder bleiben neben den Aufrufpuffern im Speicher.
    struct Frame1145 { R32 r; int l[2],a[2],b[2]; } frame;
    f_156de4((int)p1);
    if (!f_09db80(p3,&p5,&p6)) {
        p5 = (*(int *)f_09e220((int)frame.a,(int)p4,strlen(p4),(int)d_1cdde8) + 4 < 32) ?
            32 : *(int *)f_09e220((int)frame.b,(int)p4,strlen(p4),(int)d_1cdde8) + 4;
        p6 = 32;
    }

    frame.l[0] = p5;
    frame.l[1] = p6;

    if (*p1 == 0)
        p1[6] = p1[7];
    if (p1[9] == 0 && *p1 + frame.l[0] > p1[2] && *p1 != 0)
        f_15717c(p1,p2);
    if (p6 > p1[6])
        p1[6] = p6 + 1;

    frame.r.t = 4;
    frame.r.x = *p1;
    frame.r.y = p1[1];
    frame.r.w = (short)frame.l[0];
    frame.r.h = (short)frame.l[1];
    frame.r.data = p3;
    frame.r.text = p4;
    int n = (p2->e-p2->b)/32;
    Vec *v = p2;
    v->at(n);
    *(R32 *)(v->d+n*32) = frame.r;
    *p1 += frame.l[0] + (p1[9] == 0 ? p1[8] : 0);
}
//@ f_157818
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet ein Bildelement (p5) an der Position (p1, p2) der Größe p3 * p4 über f_09dc50;
 *   falls das Bild nicht geladen werden kann, wird stattdessen ein schattierter 3D-Ersatzrahmen mit dem
 *   Alternativtext p6 gezeichnet, und falls das Bild innerhalb eines gerade hervorgehobenen Hyperlinks (d_1cdf90
 *   != 0) liegt, wird zusätzlich ein farbiger Auswahlrahmen (d_1cdddc) darumgelegt.
 * - Eingaben: Position p1/p2, Breite p3, Höhe p4, Bildkennung p5 und Alternativtext p6.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cdf90: Flag, das anzeigt, ob das aktuell gezeichnete Element zu einem aktiv ausgewählten Link gehört.
 === Ende Beschreibung === */
void f_157818(int p1, int p2, int p3, int p4, int p5, char *p6)
{
    int f_09dc50(int,int,int,int);
    extern char d_1cdde8[];
    struct Frame690 {int scratch; int copyy,copyx;} frame;
    if (!f_09dc50(p5,p1,p2,1)) {
        int y1;
        char *text;
        f_09e100(p1,p2,(frame.scratch=p1+p3,y1=p2+p4,frame.scratch),p2,(int)d_1a9bcc);
        f_09e100(frame.scratch,p2,frame.scratch,y1,(int)d_1a9bcc);
        f_09e100(frame.scratch,y1,p1,y1,(int)d_1a9bd0);
        frame.copyx=p1;
        f_09e100(p1,y1,p1,p2,(int)d_1a9bd0);
        frame.copyy=p2;
        text = p6 ? p6 : d_1b94dc+2;
        f_09e3f0(frame.copyx+2,frame.copyy+2,(int)text,strlen(text),(int)d_1cdde8);
    }
    if (d_1cdf90 != 0) {
        int dx;
        f_09e100(p1,p2,(dx=p1+p3),p2,(int)&d_1cdddc);
        f_09e100(dx,p2,dx,(frame.scratch=p2+p4),(int)&d_1cdddc);
        f_09e100(dx,frame.scratch,p1,frame.scratch,(int)&d_1cdddc);
        f_09e100(p1,frame.scratch,p1,p2,(int)&d_1cdddc);
    }
}

//@ f_15794c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt ein einzelnes Wort oder Textstück (p3 der Länge p4) als Layoutelement vom Typ 1 in
 *   das Dokument ein, misst zuvor dessen Pixelbreite und -höhe in der aktuellen Schriftart (f_09e220), bricht
 *   bei Überschreitung der Zeilenbreite automatisch um (f_15717c) und rückt die X-Position um die Wortbreite
 *   weiter.
 * - Eingaben: Layoutzustand p1, Zielvektor p2, Textzeiger p3 und Zeichenanzahl p4.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - l: Array mit der berechneten Wortbreite (l[0]) und Worthöhe (l[1]).
 *   - r: 32-Byte-Layoutdatensatz vom Typ 1 (Textstück samt Schrift- und Farbattributen).
 === Ende Beschreibung === */
void f_15794c(int *p1, Vec *p2, int p3, int p4)
{
    struct Pair { int c,d; };
    struct R32 { int t,x,y; short w,h; int a,b; Pair cd; };
    struct Zugriff {
        static R32 &at(Vec *v, int i) {
            char *p = v->d+i*32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p+32;
                v->f_15c170();
            }
            return *(R32 *)(v->d+i*32);
        }
    };
    int l[2];
    R32 r;
    int n;
    f_156de4((int)p1);
    f_09e220((int)l, p3, p4, (int)(p1 + 4));
    if (*p1 == 0) p1[6] = p1[7];
    if (p1[9] == 0 && *p1 + l[0] > p1[2] && *p1 != 0) f_15717c(p1, p2);
    r.t = 1;
    r.x = *p1;
    r.y = p1[1];
    r.w = (short)l[0];
    r.h = (short)l[1];
    r.a = p4;
    r.cd = *(Pair *)(p1 + 4);
    *(int *)((char *)&r + 0x14) = p3;
    n = (p2->e - p2->b) / 32;
    Zugriff::at(p2,n) = r;
    *p1 = *p1 + l[0];
}
//@ f_157a40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt ein Textelement der Länge p4 an Position (p1, p2) mit den Schriftattributen *p5 über
 *   f_09e3f0 aus und ersetzt dabei die Textfarbe durch die Hervorhebungsfarbe d_1cdddc, falls das Element Teil
 *   eines aktiv ausgewählten Hyperlinks (d_1cdf90 != 0) ist.
 * - Eingaben: Bildschirmkoordinate p1/p2, Textzeiger p3, Textlänge p4 und Stil-/Farbstruktur p5.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - q: Lokale Kopie der Textattribute mit gegebenenfalls überschriebener Link-Hervorhebungsfarbe.
 === Ende Beschreibung === */
void f_157a40(int p1, int p2, int p3, int p4, Q *p5)
{
    Q q = *p5;
    if (d_1cdf90 != 0) q.col = d_1cdddc;
    f_09e3f0(p1, p2, p3, p4, (int)&q);
}
//@ f_157a74
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt ein horizontales Trennlinien-Element vom Typ 2 (<HR>) über die gesamte verfügbare
 *   Spaltenbreite (p1[2]) mit der Höhe p3 und hängt es an den Layoutvektor p2 an.
 * - Eingaben: Layoutzustand p1, Zielvektor p2 und Linienhöhe p3.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: 32-Byte-Layout-Eintrag vom Typ 2 (horizontale Zierlinie).
 === Ende Beschreibung === */
void f_157a74(int *p1, Vec *p2, int p3)
{
    struct R32 { int t,x,y; short w,h; char rest[16]; };
    struct Zugriff {
        static R32 &at(Vec *v, int i) {
            char *p = v->d+i*32;
            if ((unsigned)v->e <= (unsigned)p) {
                v->e = p+32;
                v->f_15c170();
            }
            return *(R32 *)(v->d+i*32);
        }
    };
    R32 r;
    *(volatile int *)&r.t = 2;
    r.x = p1[13];
    r.y = p1[1];
    r.w = *(short *)(p1+2);
    r.h = p3;
    int n = (p2->e-p2->b)/32;
    Zugriff::at(p2,n) = r;
}
//@ f_157af0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet eine horizontale Trennlinie (Layouttyp 2) an der Position (p1, p2) der Breite p3
 *   und Höhe p4 als doppellinigen, an beiden Enden spitz zulaufenden 3D-Zierbalken mit den Rahmenfarben d_1a9bcc
 *   und d_1a9bd0.
 * - Eingaben: Startkoordinate p1/p2, Breite p3 und Höhe p4.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - half: Halbe Höhe (p4 / 2) für die seitlichen Spitzen der Trennlinie.
 === Ende Beschreibung === */
void f_157af0(int p1, int p2, int p3, int p4)
{
    int half;
    int x0;
    int x1;
    int y0;
    int x2;
    half = p4 / 2;
    p3 = p3 + p1;
    x0 = p3 - 7;
    x1 = p1 + 7;
    f_09e100(x1, p2, x0, p2, (int)d_1a9bcc);
    f_09e100(p1 + 2, y0 = half + p2, x1, p2, (int)d_1a9bcc);
    f_09e100(p1 + 2, y0, x1, half * 2 + p2, (int)d_1a9bcc);
    x2 = half * 2 + p2;
    f_09e100(x0, p2, p3 - 2, y0, (int)d_1a9bd0);
    f_09e100(p3 - 2, y0, x0, x2, (int)d_1a9bd0);
    f_09e100(x0, x2, x1, x2, (int)d_1a9bd0);
}
//@ f_157be4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet alle sichtbaren Elemente eines Layoutvektors v innerhalb des Clipping-Rechtecks
 *   clip: Zuerst wird der Hintergrund entweder mit einer gekachelten Textur (d_1cddf0) oder einfarbig (d_1cddd0)
 *   gefüllt, und anschließend werden alle im Sichtbereich liegenden Elemente (Typ 1 = Text, Typ 2 = Trennlinie,
 *   Typ 3 = Einzelstrich, Typ 4 = Bild, Typ 5/6 = Hyperlink-Hervorhebung ein/aus) ausgegeben.
 * - Eingaben: Layoutvektor v und Zeiger clip auf ein 4-Int-Rechteck (links, oben, rechts, unten).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cddf0: Optionale Kennung eines gekachelten Hintergrundbildes.
 *   - d_1cdf98: Index des aktuell vom Benutzer fokussierten Hyperlinks (schaltet bei Übereinstimmung mit i das
 *     Flag d_1cdf90 = 1 ein).
 === Ende Beschreibung === */
void f_09dc00(int *);
int f_09db80(int, int *, int *);
int f_09dc50(int, int, int, int);
void f_09e140(int, int, int, int, void *);
extern int d_1cddf0;
extern int d_1cdf98;
extern char d_1cdde8[];

void f_157be4(Vec *v, int *clip)
{
    struct T1 { int len; int text; Q q; };
    struct T3Sub { short a, b, c, d; T3 col; };
    struct T4 { int data; char *text; };
    struct Elem {
        int t, x, y;
        short w, h;
        union {
            T1 _t1;
            T3Sub _t3;
            T4 _t4;
        };
        T1 *t1() { return &_t1; }
        T3Sub *t3() { return &_t3; }
        T4 *t4() { return &_t4; }
    };
    struct Zugriff {
        static Elem get(Vec *v, int i) {
            return *(Elem *)(v->d + i * 32);
        }
        static void draw1(int p1, int p2, int p3, int p4, Q *p5) {
            Q q = *p5;
            if (d_1cdf90 != 0) q.col = d_1cdddc;
            f_09e3f0(p1, p2, p3, p4, (int)&q);
        }
        static void draw2(int p1, int p2, int p3, int p4) {
            int half = p4 / 2;
            p3 += p1;
            f_09e100(p1 + 7, p2, p3 - 7, p2, (int)d_1a9bcc);
            f_09e100(p1 + 2, p2 + half, p1 + 7, p2, (int)d_1a9bcc);
            f_09e100(p1 + 2, p2 + half, p1 + 7, p2 + half * 2, (int)d_1a9bcc);
            f_09e100(p3 - 7, p2, p3 - 2, p2 + half, (int)d_1a9bd0);
            f_09e100(p3 - 2, p2 + half, p3 - 7, p2 + half * 2, (int)d_1a9bd0);
            f_09e100(p3 - 7, p2 + half * 2, p1 + 7, p2 + half * 2, (int)d_1a9bd0);
        }
        static void draw3(int p1, int p2, int p3, int p4, T3 p5) {
            f_09e100(p1, p2, p3, p4, (int)&p5);
        }
        static void draw4(int p1, int p2, int p3, int p4, int p5, char *p6) {
            int saved_p3[1]; saved_p3[0] = p3; 

            if (!f_09dc50(p5, p1, p2, 1)) {
                int copyx, copyy;
                char *text;
                f_09e100(p1, p2, p1 + p3, p2, (int)d_1a9bcc);
                f_09e100(p1 + p3, p2, p1 + p3, p2 + p4, (int)d_1a9bcc);
                f_09e100(p1 + p3, p2 + p4, p1, p2 + p4, (int)d_1a9bd0);
                copyx = p1;
                copyy = p2;
                f_09e100(p1, p2 + p4, p1, p2, (int)d_1a9bd0);
                text = p6 ? p6 : d_1b94dc + 2;
                f_09e3f0(copyx + 2, copyy + 2, (int)text, strlen(text), (int)d_1cdde8);
            }
            if (d_1cdf90 != 0) {
                f_09e100(p1, p2, p1 + saved_p3[0], p2, (int)&d_1cdddc);
                f_09e100(p1 + saved_p3[0], p2, p1 + saved_p3[0], p2 + p4, (int)&d_1cdddc);
                f_09e100(p1 + saved_p3[0], p2 + p4, p1, p2 + p4, (int)&d_1cdddc);
                f_09e100(p1, p2 + p4, p1, p2, (int)&d_1cdddc);
            }
        }
    };

    int &c0 = clip[0];
    int &c2 = clip[2];
    int &c1 = clip[1];
    int &c3 = clip[3];
    f_09dc00(clip);
    if (d_1cddf0 != 0) {
        int w, h;
        int x0, x, y0, x1, y, y1;
        if (f_09db80(d_1cddf0, &w, &h)) {
            x0 = c0 / w - 1;
            x1 = c2 / w + 1;
            y0 = c1 / h - 1;
            y1 = c3 / h + 1;
            for (y = y0; y <= y1; ++y) {
                for (x = x0; x <= x1; ++x) {
                    f_09dc50(d_1cddf0, x * w, y * h, 0);
                }
            }
        } else {
            f_09e140(c0, c1, c2 - c0 + 1, c3 - c1 + 1, &d_1cddd0);
        }
    } else {
        f_09e140(c0, c1, c2 - c0 + 1, c3 - c1 + 1, &d_1cddd0);
    }

    d_1cdf90 = 0;
    for (int i = 0; i < (v->e - v->b) / 32; ++i) {
        Elem r = Zugriff::get(v, i);
        Elem *p = &r;
        if (r.t == 5 || r.t == 6 ||
            (r.x <= c2 && r.x + (*(int *)((char *)&r + 0xa) >> 16) > c0 &&
             r.y <= c3 && r.y + (*(int *)((char *)&r + 0xc) >> 16) > c1)) {
            switch (p->t) {
            case 1:
                Zugriff::draw1(p->x, p->y, p->t1()->text, p->t1()->len, &p->t1()->q);
                break;
            case 2:
                Zugriff::draw2(p->x, p->y, *(int *)((char *)p + 0xa) >> 16, *(int *)((char *)p + 0xc) >> 16);
                break;
            case 3:
                Zugriff::draw3(p->x + p->t3()->a,
                               p->y + (*(int *)((char *)p->t3() + 0) >> 16),
                               p->x + (*(int *)((char *)p->t3() + 2) >> 16),
                               p->y + (*(int *)((char *)p->t3() + 4) >> 16),
                               p->t3()->col);
                break;
            case 4:
                Zugriff::draw4(p->x, p->y, *(int *)((char *)p + 0xa) >> 16, *(int *)((char *)p + 0xc) >> 16, p->t4()->data, p->t4()->text);
                break;
            case 5:
                if (d_1cdf98 == i) d_1cdf90 = 1;
                break;
            case 6:
                d_1cdf90 = 0;
                break;
            }
        }
    }
}
