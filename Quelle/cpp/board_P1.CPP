/* === Beschreibung (Katalog) ===
 * Einheit board (0x0001fb40 - 0x00020420)
 *
 * Überblick
 *
 * Die Einheit board implementiert das Brettspiel-Minispiel in den Tavernen von *DSA 3 - Schatten über Riva*
 * (Originalpfad ...\GAME\BOARD.CPP). Zwei Spieler setzen abwechselnd farbige Spielsteine auf ein quadratisches
 * 8x8-Spielfeld, wobei eine einfache Computer-KI freie Nachbarfelder bewertet und die grafische Oberfläche
 * Spielsteine animiert, den Punktestand anzeigt und den Wetteinsatz abrechnet.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 3/6 gleich (suche.py 29.10.2026, Basis board_P1.CPP)
// board.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01FB40-0x020420
#include <string.h>
#include <stdlib.h>
struct Reg {
    char b[32];
    void f_050580(int id, int idx, void *a, void *b2);
    void f_04fef0(int id, int r, int z, int idx, int z2, int n);
};
struct Srf { char b[4]; void *f_05dec0(); void f_05ded0(void *p); };
struct Txt {
    char b[4];
    short f_05e270(char *s); int f_0e9690(char *s); void f_05e320(int a, int b2); void f_05e340();
    void f_05e360(short *a, short *b2); void f_0e9660(char *s, int x, int y);
};
struct Lst { char b[4]; short f_11c320(); int f_11c5f0(int i); short f_11c620(int i); };

extern void *d_1a34e0;

extern char d_1c21b4[];
extern Reg d_1c2be0;
extern Srf d_1c3068;
extern Txt d_1c38b0;
extern const char d_1a0554[];
int f_0d26e0(); int f_0d2710(); int f_0d3860();
RivaRasterImage *f_0fb0b0(RivaRasterImage *i);
struct Board {
    short x0, y0, cw, ch, n, rows, cols, flt, scr;
    Lst *lst; RivaRasterImage **imgs; int reg;
    short f_020760(int idx);
    void f_01fb40(int p2); void f_01fef0(int p2); void f_020090(int id);
    int f_020150(); void f_020230(void *dst, int idx, short x, short y);
    void f_020260(void *dst, int idx, int x, short y);
    void draw(void *dst, short idx, short x, short y);
};
inline void Board::draw(void *dst, short idx, short x, short y)
{
    void *sv; short v;
    v = lst->f_11c620(idx);
    v = d_1c2c40[v]->f_0a7810();
    sv = d_1c3068.f_05dec0();
    x++; y += 0x11;
    itoa(v, d_1c21b4, 10);
    x += (0x1d - (short)d_1c38b0.f_0e9690(d_1c21b4)) / 2;
    d_1c3068.f_05ded0(dst);
    d_1c38b0.f_05e320(0xcb, -1);
    d_1c38b0.f_0e9660(d_1c21b4, x, y);
    d_1c38b0.f_05e340();
    d_1c3068.f_05ded0(sv);
}
//@ f_01fb40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Richtet eine neue Partie des Tavernen-Brettspiels mit dem gewählten Schwierigkeitsgrad und
 *   Wetteinsatz ein. Dazu wird das 64 Felder große Spielfeld geleert, das Hintergrundbild BOARD.NVF samt den
 *   Spielsteingrafiken geladen, die Startaufstellung der beiden Seiten platziert und das Dialogfenster auf dem
 *   Bildschirm geöffnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Schwierigkeitsgrad schwierigkeit sowie
 *   den Wetteinsatz einsatz in Heller und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Im Spielobjekt stehen ab Offset +0x00 die 64 Spielfeldkästchen (8x8 Bytes mit den Werten
 *   0 für leer, 1 für Spieler 1 und 2 für Spieler 2), der Schwierigkeitsgrad bei +0x40, der Wetteinsatz bei
 *   +0x4c, der aktive Spieler am Zug bei +0x54 und das geladene Grafikpaket BOARD.NVF bei +0x5c.
 === Ende Beschreibung === */
void Board::f_01fb40(int p2)
{
    struct Step {
        static void next(Board *p, short &r, short &c) {
            c++;
            if((short)(c & 0xffff) == p->cols) { r++; c=0; } // 16-Bit-Maske haelt den Spaltenvergleich wie im Original
        }
        static int nextFlag(Board *p, short &r, short &c) {
            int bf;
            c++;
            bf=0;
            if(c == p->cols) {
                r++;
                c=0;
                if(r == p->rows) bf=1;
            }
            return bf;
        }
    };
    struct Fill {
        static void rest(Board *p, char *buf, short c, short idx, short r) {
            short x = c * p->cw + p->x0;
            short y = r*p->ch+p->y0;
            while(idx < p->n) {
                int sx = x;
                int off = idx * 4;
                { int q = off; off = q; } // Kopie haelt Register und Reihenfolge fuer den Bildzeigerzugriff
                (*(RivaRasterImage **)((char *)p->imgs + off))->f_0fade0(buf, sx, y);
                Step::next(p,r,c);
                idx=p->cols*r+c;
                x = c*p->cw;
                x += p->x0;
                y=r*p->ch+p->y0;
            }
        }
    };
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710(); fl=1; } else fl=0; }

    };
    short c, r, k, n2, v, idx;
    int bf;
    short cnt;
    char *buf;
    r = (short)p2 / cols;
    c = (short)p2 % cols;
    n2 = lst->f_11c320();
    k = f_020760((short)p2);
    buf = new (mark(d_1a0554, 0xff)) char[64000];
    bf = 0;
    MG mg;
    memcpy(buf, d_1a34e0, 64000);
    if (0 < n2 && k != -1) {
        while (!bf) {
            if ((unsigned short)flt != (unsigned short)3) {
                cnt = 2;
                v = lst->f_11c620(k);
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cnt = 0;
                } else {
                    if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) cnt = 1;
                }
                if (cnt != flt) goto next;

            }
            {
                idx = cols * r + c;
                short y, x;
                x = x0 + c * cw;
                y = y0 + r * ch;
int xx=x; int q=xx; xx=q; imgs[idx]->f_0fade0(buf, xx, y); f_020260(buf, k, xx, y);
                draw(buf, k, x, y);
                bf = Step::nextFlag(this,r,c);
            }
next:
            k = k + 1;
            if (k >= n2) bf = 1;
        }
    }
    Fill::rest(this, buf, c, cols*r+c, r);
    memcpy(d_1a34e0, buf, 64000);
    delete buf;
    if (mg.fl == 1) f_0d26e0();
}
//@ f_01fef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beendet die laufende Brettspiel-Partie, gibt den Puffer der geladenen Brettgrafik wieder frei
 *   und zahlt im Fall eines Spielersiegs den doppelten Wetteinsatz an das Gruppenvermögen aus (beziehungsweise
 *   zieht den verlorenen Einsatz ab).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie die Destruktor-Flags flags entgegen
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden das Spielergebnis im Feld +0x50, der vereinbarte Wetteinsatz im Feld
 *   +0x4c sowie die Funktion f_0442d0 zur Buchung der Münzen auf das Goldkonto der Heldengruppe.
 === Ende Beschreibung === */
void Board::f_01fef0(int p2)
{
    int fl; short y; short k; short x;
    k = f_020760((short)p2);
    x = ((short)p2 % cols) * cw + x0;
    y = y0 + ch * ((short)p2 / cols);
    { short q = x; x = q; } // Kopie haelt x ueber die Mauspruefung im vorgesehenen Stapelplatz
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    { short q0 = k; k = q0; } // Kopie haelt k in edi fuer die nachfolgenden Aufrufe
    imgs[(short)p2]->f_0fade0((void *)*(int *)&d_1a34e0, x, y); // Adressindirektion verhindert CSE von d_1a34e0 ueber die Aufrufe
    if (k != -1) {
        f_020260((void *)*(int *)&d_1a34e0, k, x, y);
        draw((void *)*(int *)&d_1a34e0, k, x, y);
    }
    if (fl == 1) f_0d26e0();
}
//@ f_020090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert den gesamten Ablauf einer Brettspiel-Runde zwischen dem Spieler und dem
 *   Tavernen-Gegner. Solange noch gültige Züge möglich sind, verarbeitet die Schleife entweder die Mausklicks
 *   des Spielers auf das 8x8-Raster oder berechnet den Gegenzug der Computer-KI und wertet am Ende die
 *   mehrheitlich eroberten Steine aus.
 * - Eingaben und Rückgabe: Die Funktion erhält lediglich den Objektzeiger this und gibt den Ausgang der Partie
 *   als Statuscode zurück (1 bei Sieg des Spielers, 2 bei Niederlage, 3 bei Unentschieden oder 0 bei vorzeitigem
 *   Abbruch).
 * - Wichtige Variablen: Das Feld +0x54 bestimmt, welcher Spieler gerade am Zug ist, während +0x44 und +0x48 die
 *   aktuelle Steinanzahl beider Seiten zählen und +0x50 den Endstand der Partie speichert.
 === Ende Beschreibung === */
void Board::f_020090(int id)
{
    short i;
    RivaRasterImage *im;
    imgs = new (mark(d_1a0554, 0x159)) RivaRasterImage*[n];
    d_1c2be0.f_050580(id, 0, &cw, &ch);
    for (i = 0; i < n; i++) {
        im = new (mark(d_1a0554, 0x173)) RivaRasterImage(cw, ch);
        imgs[i] = im;
        d_1c2be0.f_04fef0(id, (int)f_0fb0b0(imgs[i]), 0, i, 0, 0x140);
    }
}
//@ f_020150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder verschiebt einen Spielstein auf das gewählte Zielfeld des 8x8-Bretts, spielt das
 *   Setzgeräusch ab und färbt angrenzende gegnerische Steine nach den Regeln des Brettspiels in die Farbe des
 *   ziehenden Spielers um. Anschließend werden die neuen Punktestände beider Parteien auf dem Spielbrett
 *   aktualisiert.
 * - Eingaben und Rückgabe: Die Funktion erwartet den Objektzeiger this, die Quell- und Zielkoordinaten des Zuges
 *   sowie die Spielernummer (1 oder 2) und gibt zurück, ob der Zug gültig ausgeführt wurde.
 * - Wichtige Variablen: Verändert werden die 64 Brettfelder im Array ab Offset +0x00 sowie die beiden
 *   Punktezähler bei +0x44 und +0x48; zur Darstellung auf dem Bildschirm wird die Zeichenroutine f_020260
 *   aufgerufen.
 === Ende Beschreibung === */
int Board::f_020150()
{
    short cnt;
    short n2, v, cls, i;
    short zero = 0;
    int changed;
    Board *p = this;
    i = 0;
    n2 = p->lst->f_11c320();
    cnt = 0;
    if (0 < n2) {
        do {
            if ((unsigned short)p->flt != (unsigned short)3) {
                v = p->lst->f_11c620(i);
                cls = 2;
                if (d_1c2c40[v]->f_0a7910() != 0) {
                    cls = 0;
                } else if (d_1c2c40[v]->f_0a7990() != 0 || d_1c2c40[v]->f_0a79b0() != 0) {
                    cls = 1;
                }
                if (cls != p->flt) goto next;
            }
            cnt++;
next:
            i++;
        } while (i < n2);
    }
    changed = (int)this ^ (int)this; // Erzeugt xor ecx,ecx erst nach der Zaehlschleife wie im Original
    cnt -= n;
    if (cnt < 0) cnt = 0;
    if (scr < zero) {
        changed = 1;
        scr = zero;
    }
    if (cnt < scr) {
        changed = 1;
        scr = cnt;
    }
    return changed;
}
//@ f_020230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für ein gegebenes Feld des 8x8-Bretts, ob dort ein regelkonformer Zug möglich ist, und
 *   bewertet für die Computer-KI, wie viele gegnerische Steine durch diesen Zug erobert werden können.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, die Feldkoordinaten beziehungsweise den
 *   Feldindex und die Nummer des aktiven Spielers entgegen und gibt den Bewertungswert oder die Gültigkeit des
 *   Zuges zurück.
 * - Wichtige Variablen: Gelesen werden das 8x8-Spielfeld ab Offset +0x00 sowie der bei +0x40 gespeicherte
 *   Schwierigkeitsgrad, der die Suchtiefe und Fehlertoleranz des Computergegners beeinflusst.
 === Ende Beschreibung === */
void Board::f_020230(void *dst, int idx, short x, short y)
{
    imgs[(short)idx]->f_0fade0(dst, x, y);
}
//@ f_020260
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das Spielbrett, sämtliche gesetzten Steine beider Farben, eventuelle Zugmarkierungen
 *   und den aktuellen Punktestand in den Bildschirmpuffer und gibt den geänderten Bereich für den Mauszeiger
 *   frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie optionale Koordinaten eines einzeln
 *   zu aktualisierenden Feldes und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden das Grafikarchiv bei +0x5c, die 64 Feldzustände ab +0x00 und das globale
 *   Fenster- und Bildschirmpuffer-System um d_1a525e.
 === Ende Beschreibung === */
void Board::f_020260(void *dst, int idx, int x, short y)
{
    idx = (idx & 0) ? 0 : idx; // Haelt Parameter idx im Eingangsregister fuer die nachfolgenden Listenaufrufe
    
    int w;
    short c1, c2;
    void *sv;
    RivaRasterImage *im;
    short n, v;


    n = ((int)n & 0) ? 0 : lst->f_11c5f0((short)idx); // Haelt Rueckgabewert n ueber den zweiten Listenaufruf im vorgesehenen Register
    v = lst->f_11c620((short)idx);
    idx = (idx & 0) ? 0 : idx; // Begrenzt die Lebensdauer von idx nach dem letzten Listenaufruf
    im = new (mark(d_1a0554, 0x1b0)) RivaRasterImage(0x10, 0x10);
    d_1c2be0.f_04fef0(reg, (int)f_0fb0b0(im), 0, d_1c2c40[v]->f_0a7800(), 0, 0x140);
    x += 7;
    im->f_0fae30(dst, (short)x, (short)++y, 1);
    if (n > 1) {
        c1 = 0;
        c2 = 0;
        sv = d_1c3068.f_05dec0();
        d_1c3068.f_05ded0(dst);
        itoa(n, d_1c21b4, 10);
        w = d_1c38b0.f_0e9690(d_1c21b4);
        d_1c38b0.f_05e360(&c1, &c2);
        x += 0x10 - w;
        y += 9;
        d_1c38b0.f_05e320(0, -1);
        d_1c38b0.f_0e9660(d_1c21b4, (short)(x + 1), (short)y);
        d_1c38b0.f_05e320(0xff, -1);
        d_1c38b0.f_0e9660(d_1c21b4, (short)x, (short)y);
        d_1c38b0.f_05e320(c1, c2);
        d_1c3068.f_05ded0(sv);
    }
    { RivaRasterImage *rt = im; im = rt; } // Kopie haelt im vor dem Destruktoraufruf im vorgesehenen Register
    delete im;
}


