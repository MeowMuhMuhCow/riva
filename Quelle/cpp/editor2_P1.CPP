/* === Beschreibung (Katalog) ===
 * Einheit editor2 (0x061b10 - 0x0625e0)
 *
 * Überblick
 * Diese Einheit enthält den zweiten Teil von editor.cpp: den Konstruktor und Destruktor des mehrzeiligen
 * Texteditors (Ed), das Einfügen und Löschen einzelner Zeichen (Backspace, Entf), Wort- und
 * Zeilenbreiten-Hilfsfunktionen für den Zeilenumbruch sowie die Bewegungsfunktionen für sämtliche Cursortasten
 * (Pfeil links/rechts/hoch/runter, Pos1, Ende).
 === Ende Beschreibung === */
// P3 14/16 gleich (suche.py 26.10.2026, Basis editor2_P1.CPP)
// editor2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x061B10-0x0625E0
#include <string.h>
#include "RIVAMEM.H"



struct Pair { int a; int b; };
struct Ed {
    short n; short w; short bsz; short x0; short y0; short lh; short s0c; short s0e;
    short line; short pos;
    int f14; int f18; int f1c; int f20;
    short cx; short cy;
    int f28; char *f2c; int f30; char **lines;
    unsigned short r[4];
};
char *f_014540(int size, const char *file, int line);
unsigned char f_045db0(int p1, int p2);
int f_05dec0(int p1);
int f_05ded0(int p1, int p2);
int f_05e320(int p1, int p2, int p3);
int f_05e360(int p1, int p2, int p3);
short f_05e420(int p1, int p2);
int f_061050(Ed *p1, char *p2);
int f_061080(Ed *p1, int p2);
int f_061590(Ed *p1);
int f_0616f0(Ed *p1);
int f_061880(Ed *p1);
int f_099f70(int p1, int p2, int p3, int p4);
void f_099fa0(unsigned short *p1);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0621b0(Ed *p1);
extern int d_1c3068;
extern int d_1c3078;
extern int d_1c38b0;
extern char *d_1a34e0;
extern Pair d_1bdbd4;
extern const char d_1a19c4[];
extern const char d_1b6f30[];
#define D3068 ((int)&d_1c3068)
#define D3078 ((int)&d_1c3078)
#define D38B0 ((int)&d_1c38b0)
//@ f_061b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor des mehrzeiligen Texteditors (Ed): speichert Zeilenanzahl n, nutzbare Breite (w
 *   abzüglich einer Leerzeichenbreite für den Cursor) und linke obere Ecke (x, y), übernimmt Zeilenhöhe und
 *   Farben aus dem Textausgabe-Objekt d_1c38b0, legt n + 1 Zeilenpuffer zu je w * 4 Bytes auf dem Heap an, lenkt
 *   die Glyphen-Zeichenfläche d_1c3068 auf den Zielpuffer p6 (oder den Bildschirm d_1a34e0) um und begrenzt bei
 *   p7 != 0 das Clip-Rechteck auf das Editorfeld.
 * - Eingaben und Rückgabe: Der Konstruktor erhält den this-Zeiger, die Zeilenanzahl n, die Breite w in Pixeln,
 *   die Startkoordinaten x und y, ein optionales Hintergrundbild p5 (0 = einfarbig), einen optionalen Zielpuffer
 *   p6 (0 = direkt auf den Bildschirm d_1a34e0) sowie den Clip-Schalter p7 (1 = Clip-Rechteck setzen) und gibt
 *   this zurück.
 * - Wichtige Variablen: Legt in this->lines (+0x34) n + 1 Zeilenzeiger an (eine zusätzliche Reservezeile) und
 *   sichert den bisherigen Zielpuffer der Schrift in this->f30 (+0x30) sowie das alte Clip-Rechteck in this->r
 *   (+0x38).
 === Ende Beschreibung === */
struct R1320 { unsigned short a,b,c,d; R1320() { a=0;b=0;c=0;d=0; } };
struct f_061b10 { 
    short n; short w; short bsz; short x0; short y0; short lh; short s0c; short s0e;
    short line; short pos;
    int f14; int f18; int f1c; int f20;
    short cx; short cy;
    int f28; char *f2c; int f30; char **lines;
    R1320 r;
 f_061b10(short n, short w, short x, short y, int p5, char *p6, short p7); };
f_061b10::f_061b10(short n, short w, short x, short y, int p5, char *p6, short p7)
{
    short i;
    struct Coord {
        static inline unsigned short get(short v) {
            int a=d_1c3068, b=d_1c3078, c=d_1c38b0;
            d_1c3068=a; d_1c3078=b; d_1c38b0=c; // Codelose Roundtrips fuer die Registerfolge
            return (unsigned short)v;
        }
    };

    this->n = n;
    this->w = w - f_045db0(D3078, ' ');
    this->x0 = x;
    this->y0 = y;
    this->bsz = w << 2;
    this->lh = f_05e420(D38B0, -1);
    f_05e360(D38B0, (int)&this->s0c, (int)&this->s0e);
    this->lines = (char **)f_014540(n * 4 + 4, d_1a19c4, 0x38);
    for (i = 0; i < n + 1; i++)
        this->lines[i] = f_014540(this->bsz, d_1a19c4, 0x3c);
    this->f20 = -1;
    this->line = this->pos = 0;
    this->cx = this->x0;
    this->cy = this->y0;
    this->f28 = p5;
    if (this->f28)
        f_05e320(D38B0, this->s0c, -1);
    this->f2c = (p6 == 0) ? d_1a34e0 : p6;
    this->f30 = f_05dec0(D3068);
    f_05ded0(D3068, (int)this->f2c);
    if (p7) {
        *(Pair *)&this->r = d_1bdbd4;
        f_099f70(Coord::get(x), (unsigned short)y,
                 (unsigned short)(x + w + f_045db0(D3078, ' ') - 1),
                 (unsigned short)((short)(n * this->lh) + y));
    } else
        this->r.a = 0xffff;
}
//@ f_061cd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor des mehrzeiligen Texteditors (Ed): gibt alle n + 1 Zeilenpuffer sowie das
 *   Zeigerarray p1->lines frei, stellt den vorherigen Zielpuffer p1->f30 der Zeichenfläche d_1c3068 wieder her
 *   und setzt ein eventuell gesichertes Clip-Rechteck (p1->r[0] != 0xffff) über f_099fa0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und den ungenutzten
 *   Watcom-Destruktorschalter flag und gibt p1 zurück.
 * - Wichtige Variablen: Gibt in einer Schleife p1->lines[0 .. p1->n] frei.
 === Ende Beschreibung === */
Ed *f_061cd0(Ed *p1, int flag)
{
    short i;
    for (i = 0; i < p1->n + 1; i++)
        delete p1->lines[i];
    delete p1->lines;
    f_05ded0(D3068, p1->f30);
    if (p1->r[0] != (unsigned short)0xffff)
        f_099fa0(p1->r);
    return p1;
}
//@ f_061d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Rückschritt-Taste (Backspace): steht der Cursor in Spalte 0, wird f_061880 zum
 *   Zusammenführen mit der vorherigen Zeile aufgerufen; steht er weiter rechts (p1->pos > 0), wird das Zeichen
 *   links vom Cursor per memmove gelöscht, der Cursor um dessen Zeichenbreite nach links gerückt und die Zeile
 *   zum Neuzeichnen markiert (p1->f18 = 1).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Ein Originalbefund am Ende des p1->pos > 0-Zweigs ist, dass das erste Wort der
 *   Folgezeile p1->lines[p1->line + 1] in einen Hilfspuffer buf kopiert und zusammen mit der aktuellen Zeile
 *   über f_061050 vermessen wird, beide Breitenwerte aber ungenutzt verworfen werden, sodass Wörter aus der
 *   Folgezeile beim Löschen nie nach oben nachrücken.
 === Ende Beschreibung === */
void f_061d20(Ed *p1)
{
    char *cur;
    char *buf;
    char *nx;
    signed char *q;
    int n;
    unsigned char c;
    if (p1->pos) {
        buf = new (mark(d_1a19c4, 0x7c)) char[p1->bsz];
        memset(buf, 0, 4);
        int line = p1->line;
        char **lines = p1->lines;
        cur = lines[line];
        c = cur[p1->pos - 1];
        memmove(cur + p1->pos - 1, cur + p1->pos, p1->bsz - p1->pos);
        cur[p1->bsz - 1] = 0;
        p1->pos--;
        f_0616f0(p1);
        p1->cx -= f_045db0(D3078, c);
        f_061590(p1);
        p1->f18 = 1;
        nx = p1->lines[p1->line + 1];
        n = 0;
        q = (signed char *)nx;
        while (*q && *q != ' ') {
            q++;
            n++;
        }
        signed char count = n;
        strncpy(buf, nx, count);
        strcat(buf, d_1b6f30);
        f_061050(p1, cur);
        f_061050(p1, buf);
        delete buf;
    } else
        f_061880(p1);
}
//@ f_061e60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt ein getipptes druckbares Zeichen p2 an der aktuellen Cursorposition (line, pos) in den
 *   Zeilenpuffer ein, führt ab der aktuellen Zeile einen automatischen Wortumbruch (f_061080) durch und rückt,
 *   sofern der Umbruch den Cursor nicht bereits in die nächste Zeile versetzt hat, den Cursor um die
 *   Zeichenbreite nach rechts weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und das einzufügende Zeichen
 *   p2 (unsigned char). Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Setzt bei normalem Weiterrücken den Merker p1->f1c = 1 ("Zeichen angefügt"), damit
 *   f_060ae0 am Zeilenende nur die einzelne Zeichenzelle neu zeichnen muss.
 === Ende Beschreibung === */
void f_061e60(Ed *p1, unsigned char p2)
{
    char *s;
    short w;
    s = p1->lines[p1->line];
    memmove(s + p1->pos + 1, s + p1->pos, p1->bsz - p1->pos - 1);
    s[p1->pos] = p2;
    if (f_061080(p1, p1->line) == 1) {
        p1->pos++;
        w = f_045db0(D3078, p2);
        p1->f1c = 1;
        p1->cx = p1->cx + w;
    }
}
//@ f_061ee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Entf-Taste (Delete): bewegt den Cursor über f_0621b0 um ein Zeichen nach rechts
 *   und führt anschließend einen Rückschritt (f_061d20) aus; steht der Cursor bereits ganz am Textende (f_0621b0
 *   liefert 0), wird lediglich ein Nullbyte an die Cursorposition geschrieben.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Kombiniert f_0621b0 (Cursor rechts) und f_061d20 (Rückschritt).
 === Ende Beschreibung === */
void f_061ee0(Ed *p1)
{
    if (f_0621b0(p1) == 1) {
        f_061d20(p1);
        return;
    }
    char *line = p1->lines[p1->line];
    line[p1->pos] = 0;
}
//@ f_061f10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht vom Ende des Zeilenstrings p2 rückwärts nach dem letzten Leerzeichen ' ' und liefert
 *   dessen Index für den Wortumbruch.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und den Zeilenstring p2 und gibt
 *   den 0-basierten Index des letzten Leerzeichens (oder 0, wenn keines gefunden wurde) als short zurück.
 * - Wichtige Variablen: Startet bei i = strlen(p2) und dekrementiert i, solange p2[i] != ' ' und i > 0 gilt.
 === Ende Beschreibung === */
short f_061f10(int p1, signed char *p2)
{
    short i = strlen((char *)p2);
    while (p2[i] != ' ' && i)
        i--;
    return i;
}
//@ f_061f40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt die Anzahl der Zeichen vom Anfang des Strings p2 bis zum ersten Leerzeichen ' ' oder bis
 *   zum Stringende.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und den String p2 und gibt die
 *   Wortlänge als int zurück.
 * - Wichtige Variablen: Wird von f_061880 genutzt, um beim Rückschritt am Zeilenanfang das erste Wort an die
 *   vorherige Zeile anzuhängen.
 === Ende Beschreibung === */
int f_061f40(int p1, signed char *p2)
{
    int i = 0;
    while (*p2 && *p2 != ' ') {
        ++p2;
        ++i;
    }
    return i;
}
//@ f_061f60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Summiert für ein überlanges Wort ohne Leerzeichen die Zeichenbreiten (f_045db0) vom
 *   Zeilenanfang an auf und liefert den Index des ersten Zeichens, mit dem die nutzbare Zeilenbreite p1->w
 *   überschritten wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und den nicht-leeren
 *   Zeilenstring p2 und gibt den Trennindex als int zurück.
 * - Wichtige Variablen: Vergleicht die laufende Breitensumme w mit der nutzbaren Zeilenbreite p1->w (+0x02).
 === Ende Beschreibung === */
int f_061f60(Ed *p1, signed char *p2)
{
    int i = -1;
    short w = 0;
    signed char *q;
    do {
        i++;
        q = p2 + (short)i;
        w += f_045db0(D3078, (unsigned char)*q);
        if (p1->w < w)
            return i;
    } while (q[1] != 0);
    return i;
}
//@ f_061fa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt die Cursorzeile p1->line um eine Zeile nach unten (+1) und erhöht die vertikale
 *   Pixelposition p1->cy um die Zeilenhöhe p1->lh, sofern der Cursor noch nicht in der letzten Zeile (p1->n - 1)
 *   steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Verändert nur p1->line und p1->cy; die Spalte p1->pos und p1->cx werden vom Aufrufer
 *   gesetzt.
 === Ende Beschreibung === */
void f_061fa0(Ed *p1)
{
    if (p1->line < p1->n - 1) {
        p1->line++;
        p1->cy += p1->lh;
    }
}
//@ f_061fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt die Cursorzeile p1->line um eine Zeile nach oben (-1) und verringert die vertikale
 *   Pixelposition p1->cy um die Zeilenhöhe p1->lh, sofern der Cursor nicht in Zeile 0 steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Verändert p1->line und p1->cy.
 === Ende Beschreibung === */
void f_061fd0(Ed *p1)
{
    if (p1->line) {
        p1->line--;
        p1->cy -= p1->lh;
    }
}
//@ f_062000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Pfeil links: setzt den Cursor um ein Zeichen nach links (oder in Spalte 0,
 *   falls line > 0, an das Zeilenende der vorherigen Zeile) und kopiert anschließend bei Verwendung eines
 *   eigenen Hintergrundpuffers (f2c != d_1a34e0) diesen auf den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Zieht die Zeichenbreite f_045db0(D3078, c) von p1->cx ab bzw. berechnet am Ende der
 *   Vorzeile p1->cx = p1->x0 + f_061050(...).
 === Ende Beschreibung === */
void f_062000(Ed *p1)
{
    unsigned char c;
    f_0616f0(p1);
    if (p1->pos) {
        c = *(p1->lines[p1->line] + p1->pos - 1);
        if (!c)
            c = 0x20;
        p1->cx -= f_045db0(D3078, c);
        p1->pos--;
    } else {
        if (p1->line) {
            if (p1->line) {
                p1->line--;
                p1->cy -= p1->lh;
            }
            p1->pos = strlen(p1->lines[p1->line]);
            p1->cx = p1->x0 + f_061050(p1, p1->lines[p1->line]);
        }
    }
    f_061590(p1);
    Ed *q = p1;
    if (q->f2c != d_1a34e0) {
        volatile int fl;
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, q->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
}
//@ f_062120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Pos1 (Home): setzt den Cursor an den Anfang der aktuellen Zeile (pos = 0,
 *   cx = x0) und aktualisiert den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Setzt p1->pos = 0 und p1->cx = p1->x0 zwischen f_0616f0 und f_061590.
 === Ende Beschreibung === */
void f_062120(Ed *p1)
{
    f_0616f0(p1);
    p1->cx = p1->x0;
    p1->pos = 0;
    f_061590(p1);
    Ed *q = p1;
    if (q->f2c != d_1a34e0) {
        volatile int fl;
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, q->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
}
//@ f_0621b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Pfeil rechts: rückt den Cursor innerhalb der aktuellen Zeile um ein
 *   Zeichen nach rechts oder springt am Zeilenende an den Anfang (pos = 0, cx = x0) der nächsten Zeile, sofern
 *   noch eine Folgezeile (line < n - 1) existiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt 1 zurück, wenn der
 *   Cursor bewegt werden konnte, oder 0, wenn er bereits am Ende der letzten Zeile stand.
 * - Wichtige Variablen: Der Rückgabewert wird von f_061ee0 (Entf-Taste) ausgewertet.
 === Ende Beschreibung === */
int f_0621b0(Ed *p1)
{
    char c = p1->lines[(short)p1->line][p1->pos];
    int r;
    f_0616f0(p1);
    r = 1;
    if ((unsigned)(short)p1->pos < strlen(p1->lines[p1->line])) {
        p1->cx += f_045db0(D3078, (unsigned char)c);
        p1->pos++;
    } else if (p1->line < p1->n - r) {
        p1->pos = 0;
        int line = p1->line;
        int limit = p1->n - r;
        if (line < limit) {
            p1->line++;
            p1->cy += p1->lh;
        }
        p1->cx = p1->x0;
    } else {
        r = 0;
    }
    f_061590(p1);
    Ed *q = p1;
    if (q->f2c != d_1a34e0) {
        volatile int fl;
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, q->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
    return r;
}
//@ f_0622e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Ende (End): setzt den Cursor hinter das letzte Zeichen der aktuellen Zeile
 *   (pos = strlen(line), cx = x0 + f_061050(...)) und aktualisiert den Bildschirm.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Berechnet die Pixelposition des Zeilenendes über f_061050(p1, p1->lines[p1->line]).
 === Ende Beschreibung === */
void f_0622e0(Ed *p1)
{
    f_0616f0(p1);
    p1->pos = strlen(p1->lines[p1->line]);
    p1->cx = p1->x0 + f_061050(p1, p1->lines[p1->line]);
    f_061590(p1);
    Ed *q = p1;
    if (q->f2c != d_1a34e0) {
        volatile int fl;
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, q->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
}
//@ f_062390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Pfeil hoch: bewegt den Cursor (sofern line > 0) um eine Zeile nach oben,
 *   behält die bisherige Zeichenspalte pos bei (oder kürzt sie auf die Länge der oberen Zeile, falls diese
 *   kürzer ist) und berechnet die neue Pixelkoordinate cx anhand der Textbreite vor der Cursorspalte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Kopiert die ersten p1->pos Zeichen der oberen Zeile per strncpy in einen mit f_014540
 *   angeforderten Puffer buf, um deren Pixelbreite über f_061050 zu messen.
 === Ende Beschreibung === */
void f_062390(Ed *p1)
{
    char *buf = f_014540(p1->bsz, d_1a19c4, 0x192);
    char *s;
    volatile int fl;
    short len;
    if (p1->line != (short)0) {
        f_0616f0(p1);
        if (p1->line != (short)0) {
            p1->line--;
            p1->cy -= p1->lh;
        }
        s = p1->lines[p1->line];
        strncpy(buf, s, p1->pos);
        len = strlen(s);
        if (len >= p1->pos) {
            p1->cx = p1->x0 + f_061050(p1, buf);
        } else {
            p1->pos = len;
            p1->cx = p1->x0 + f_061050(p1, s);
        }
        f_061590(p1);
    }
    delete buf;
    Ed *q = p1;
    if (q->f2c != d_1a34e0) {
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, q->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
}
//@ f_0624b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Taste Pfeil runter: bewegt den Cursor (sofern line < n - 1) um eine Zeile nach
 *   unten, behält die bisherige Zeichenspalte pos bei (bzw. setzt den Cursor an das Ende der unteren Zeile,
 *   falls diese kürzer ist) und berechnet die neue Pixelkoordinate cx über f_061050.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Arbeitet spiegelbildlich zu f_062390 für den Schritt in die nächste Zeile p1->line + 1.
 === Ende Beschreibung === */
void f_0624b0(Ed *p1)
{
    char *buf = 0;
    buf = f_014540(p1->bsz, d_1a19c4, 0x1af);
    if (p1->line < p1->n - 1) {
        f_0616f0(p1);
        if (p1->line < p1->n - 1) {
            p1->line++;
            p1->cy += p1->lh;
        }
        char *s = p1->lines[p1->line];
        strncpy(buf, s, p1->pos);
        if (strlen(s) >= p1->pos) {
            p1->cx = p1->x0 + f_061050(p1, buf);
        } else {
            p1->pos = strlen(s);
            p1->cx = p1->x0 + f_061050(p1, s);
        }
        f_061590(p1);
    }
    delete buf;
    Ed *e = p1;
    if (e->f2c != d_1a34e0) {
        volatile int fl;
        if (f_0d3860() == 1) {
            int one = 1;
            f_0d2710();
            fl = one;
        } else fl = 0;
        memcpy(d_1a34e0, e->f2c, 64000);
        if (fl == 1) f_0d26e0();
    }
}
