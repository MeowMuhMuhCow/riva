/* === Beschreibung (Katalog) ===
 * Einheit poolinit
 *
 * Diese Einheit (aus p:\riva\source\cpp\poolinit.cpp) verwaltet das Erstellen, Befüllen und Sortieren von
 * Gegenstands- und Händlerpools. Sie lädt die zulässigen Warenkategorien und Sonderangebote aus den
 * Spieldateien, stellt das Sortiment aus den Gegenstandsdefinitionen oder dem Gruppeninventar zusammen und
 * sortiert die Angebote nach Kategorien und Preis.
 === Ende Beschreibung === */
// P3 5/7 gleich (suche.py 26.10.2026, Basis poolinit_P1.CPP)
// poolinit.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E2660-0x0E2AC0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a64bc[];           // Text 0x1A64BC
struct Ent { short a; short b; char pad[0x14]; };
struct S { short s0; short s2; short s4; short s6; short s8; short s10; struct Ent *p12; };
struct E6 { short a; short b; short c; };
struct T3 { int a; int b; int c; };
struct Pool { struct S *s; short *u1; struct E6 *u2; struct T3 t; int f6; };
extern short d_1bb558;
extern int d_du1, d_du2, d_du3, d_du4, d_du5, d_du6, d_du7, d_du8, d_du9, d_du10, d_du11;
extern short d_1bb55a;
extern int d_du2_1, d_du2_2, d_du2_3, d_du2_4, d_du2_5, d_du2_6, d_du2_7, d_du2_8, d_du2_9, d_du2_10, d_du2_11, d_du2_12, d_du2_13, d_du2_14, d_du2_15, d_du2_16, d_du2_17, d_du2_18, d_du2_19, d_du2_20, d_du2_21, d_du2_22;
extern int d_du2_23, d_du2_24, d_du2_25, d_du2_26, d_du2_27, d_du2_28, d_du2_29, d_du2_30, d_du2_31, d_du2_32, d_du2_33, d_du2_34, d_du2_35, d_du2_36, d_du2_37, d_du2_38, d_du2_39, d_du2_40, d_du2_41, d_du2_42, d_du2_43;
extern struct T3 d_1c004c[];
int f_0e2ac0(struct Pool *p1, int p2, int p3);
int f_0e2b90(struct Pool *p1, int p2, int p3);
int f_0e2f70(struct Pool *p1, int p2, int p3, int p4, int p5);
int f_11ea00(void *q, int a, int b, void *c, int d);
short f_11eae0(void *q, int a);
int f_0e2630(void *a, void *b);
void f_14d7dc(void *base, int n, int w, int (*cmp)(void *, void *));
void f_0e27a0(struct Pool *p1);
void f_0e28a0(struct Pool *p1);
void f_0e29b0(struct Pool *p1, short p2);
//@ f_0e2660
/* === Beschreibung (Katalog) ===
 * Konstruktor der Pool-Verwaltungsstruktur (p1), der den Zeiger auf den Pool-Kopf (p2) speichert, Speicher für
 * die Kategorie-Bitmaske (u1) sowie die vier Kategorieregister (u2) reserviert, den
 * Preisberechnungs-Methodenzeiger (t) nullt und in f6 vermerkt, ob bereits ein fertiges Gegenstandsarray
 * (p2->p12 != 0) übergeben wurde.
 * - Eingaben: Übergeben werden der Zeiger auf die zu initialisierende Pool-Struktur p1 sowie der Zeiger auf den
 *   zugehörigen Pool-Kopfblock p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Pool-Zeiger p1 zurück.
 === Ende Beschreibung === */
struct Pool *f_0e2660(struct Pool *p1, struct S *p2)
{
    p1->s = p2;
    p1->u1 = (short *)new (mark(d_1a64bc, 0x5c)) int;
    p1->u2 = new (mark(d_1a64bc, 0x5d)) struct E6[4];
    struct T3 *z = &p1->t;
    z->a = 0;
    z->b = 0;
    z->c = 0;
    p1->f6 = (p2->p12 != 0);
    return p1;
}
//@ f_0e26d0
/* === Beschreibung (Katalog) ===
 * Destruktor der Pool-Verwaltungsstruktur (p1), der das Gegenstandsarray (s->p12) freigibt, sofern es vom Pool
 * selbst angelegt wurde (f6 == 0), und anschließend die Arbeitsstrukturen u1 und u2 löscht.
 * - Eingaben: Übergeben werden der Pool-Zeiger p1 sowie ein ungenutztes Freigabeflag kp2.
 * - Rückgabewert: Die Funktion gibt den Pool-Zeiger p1 zurück.
 === Ende Beschreibung === */
struct Pool *f_0e26d0(struct Pool *p1, int kp2)
{
    if (p1->f6 == 0) {
        delete p1->s->p12;
        p1->s->p12 = 0;
    }
    delete p1->u1;
    delete p1->u2;
    return p1;
}

//@ f_0e2700
/* === Beschreibung (Katalog) ===
 * Steuert den kompletten Aufbau eines Händler- oder Beutepools (p1): Sie lädt die Pool-Parameter (f_0e27a0),
 * zerlegt die Warenkategorie-Bitmaske (*p->u1) in bis zu vier Einzelkategorien (p->u2[index].a), befüllt und
 * sortiert die Gegenstandsliste (f_0e28a0) und berechnet schließlich die maximale Scroll-Zeilenanzahl (s->s8)
 * für das 4x5-Kachelfenster.
 * - Eingaben: Die Funktion erwartet den Zeiger auf die Pool-Verwaltungsstruktur p1.
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Pool mindestens einen Gegenstand enthält (s->s10 > 0), andernfalls
 *   0.
 === Ende Beschreibung === */
int f_0e2700(struct Pool *p1)
{
    int ret;
    short index, mask;
    int total;
    f_0e27a0(p1);
    mask = 1;
    Pool *p = p1;
    ret = 0;
    index = 0;
    do {
        if (*p->u1 & mask) {
            p->u2[index].a = mask;
            index++;
        }
        mask = mask * 2;
    } while (mask < (short)0x200);
    f_0e28a0(p1);
    struct S *s = p1->s;
    total = s->s10;
    if (total > (short)0) {
        ret = 1;
        int width, height;
        width = *(short *)&d_1bb558;
        height = d_1bb55a;
        if (total > width * height) {
            s->s8 = total / width - height;
            if (p1->s->s10 % width > (short)0)
                p1->s->s8++;
        }
    }
    if (d_du1 & 0) { d_du1 = (int)&ret; } // haelt die Registerzuteilung wie im Original
    if (d_du2 & 0) d_du2 = 0;
    if (d_du3 & 0) d_du3 = 0;
    if (d_du4 & 0) d_du4 = 0;
    if (d_du5 & 0) d_du5 = 0;
    if (d_du6 & 0) d_du6 = 0;
    if (d_du7 & 0) d_du7 = 0;
    if (d_du8 & 0) d_du8 = 0;
    if (d_du9 & 0) d_du9 = 0;
    if (d_du10 & 0) d_du10 = 0;
    if (d_du11 & 0) d_du11 = 0;
    return ret;
}
//@ f_0e27a0
/* === Beschreibung (Katalog) ===
 * Liest aus den Pool-Konfigurationsdateien (0x22000c und 0x22000e) über f_11ea00 den Preisberechnungstyp (s->s0)
 * sowie die 32-Bit-Kategorie- und Angebotskennung (*p1->u1) ein und kopiert den passenden
 * Preisberechnungs-Methodenzeiger aus der globalen Tabelle d_1c004c in das Pool-Objekt (p1->t).
 * - Eingaben: Die Funktion erhält den Zeiger auf die Pool-Verwaltungsstruktur p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e27a0(struct Pool *p1)
{
    char *q = new (mark(d_1a64bc, 0xb3)) char;
    int local = 0;
    struct S *s;
    f_11ea00(q, 0x22000c, p1->s->s0, &local, 4);
    p1->s->s0 = (short)local;
    s = p1->s;
    if (s->s4 <= 0 && s->s0 != 2 && s->s0 != 3) s->s0 = 1;
    struct T3 *dst = &p1->t;
    struct T3 *src = &d_1c004c[p1->s->s0];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    f_11ea00(q, 0x22000e, p1->s->s2, p1->u1, 4);
    delete q;
}
//@ f_0e2860
/* === Beschreibung (Katalog) ===
 * Zerlegt die 16-Bit-Kategorie-Bitmaske (*p1->u1) durch Prüfen der Bits 0x001 bis 0x100 in aufsteigende
 * Einzel-Bitwerte und trägt diese nacheinander in das Kategorieregister-Array (p1->u2[k].a) ein.
 * - Eingaben: Die Funktion erwartet den Zeiger auf die Pool-Verwaltungsstruktur p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e2860(struct Pool *p1)
{
    short m = 1;
    short k = 0;
    do {
        if (*p1->u1 & m) { p1->u2[k].a = m; k++; }
        m *= 2;
    } while (m < (short)0x200);
}
//@ f_0e28a0
/* === Beschreibung (Katalog) ===
 * Erzeugt und befüllt das bis zu 200 Einträge fassende Gegenstandsarray (s->p12) des Pools (p1) über die vier
 * Kategorieregister - entweder aus dem Inventar der Heldengruppe (f_0e2b90 bei Verkauf/Lager, s4 <= 0), aus
 * einer festen Angebotsliste (f_0e29b0 bei Kategorie 1) oder aus dem globalen Gegenstandskatalog (f_0e2ac0) -
 * und sortiert im Händler-Modus (s4 > 0) jede Kategorie mittels qsort (f_14d7dc mit f_0e2630) aufsteigend nach
 * dem Preis.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Pool-Verwaltungsstruktur p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e28a0(struct Pool *p1)
{
    int t129_8;
    int ix;
    short k, b, c;
    if (p1->f6 == 0) {
        if (p1->s->p12 != 0) {
            delete p1->s->p12;
            p1->s->p12 = 0;
        }
        p1->s->p12 = new (mark(d_1a64bc, 0x109)) struct Ent[200];
        k = 0;
        for (; k < (short)4; k++) {
            if (p1->s->s4 <= 0) {
                f_0e2b90(p1, k, p1->u2[k].a);
            } else {
                ix = k;
                ix *= 6;
                if (*(short *)((char *)p1->u2 + ix) == (short)1) f_0e29b0(p1, k);
                else f_0e2ac0(p1, k, *(short *)((char *)p1->u2 + ix));
            }
        }
    } else {
        while ((p1->s->p12 + p1->s->s10)->b > 0) p1->s->s10++;
    }
    if ((t129_8 = p1->s->s4) > 0) {
        k = 0;
        for (; k < (short)4; k++) {
            b = p1->u2[k].b;
            c = p1->u2[k].c;
            if ((short)(c & 0x1ffff) > 0) {
                int tb = (b & 0) ? 0 : b; // haelt die Registerzuteilung wie im Original
                f_14d7dc(p1->s->p12 + tb, (short)(c & 0xffff), 0x18, f_0e2630);
            }
        }
    }
    if (d_du2_1 & 0) d_du2_1 = 0; if (d_du2_2 & 0) d_du2_2 = 0; if (d_du2_3 & 0) d_du2_3 = 0; if (d_du2_4 & 0) d_du2_4 = 0; if (d_du2_5 & 0) d_du2_5 = 0; if (d_du2_6 & 0) d_du2_6 = 0; if (d_du2_7 & 0) d_du2_7 = 0; if (d_du2_8 & 0) d_du2_8 = 0; if (d_du2_9 & 0) d_du2_9 = 0; if (d_du2_10 & 0) d_du2_10 = 0; if (d_du2_11 & 0) d_du2_11 = 0; if (d_du2_12 & 0) d_du2_12 = 0; if (d_du2_13 & 0) d_du2_13 = 0; if (d_du2_14 & 0) d_du2_14 = 0; if (d_du2_15 & 0) d_du2_15 = 0; if (d_du2_16 & 0) d_du2_16 = 0; if (d_du2_17 & 0) d_du2_17 = 0; if (d_du2_18 & 0) d_du2_18 = 0; if (d_du2_19 & 0) d_du2_19 = 0; if (d_du2_20 & 0) d_du2_20 = 0; if (d_du2_21 & 0) d_du2_21 = 0; if (d_du2_22 & 0) d_du2_22 = 0; if (d_du2_23 & 0) d_du2_23 = 0; if (d_du2_24 & 0) d_du2_24 = 0; if (d_du2_25 & 0) d_du2_25 = 0; if (d_du2_26 & 0) d_du2_26 = 0; if (d_du2_27 & 0) d_du2_27 = 0; if (d_du2_28 & 0) d_du2_28 = 0; if (d_du2_29 & 0) d_du2_29 = 0; if (d_du2_30 & 0) d_du2_30 = 0; if (d_du2_31 & 0) d_du2_31 = 0; if (d_du2_32 & 0) d_du2_32 = 0; if (d_du2_33 & 0) d_du2_33 = 0; if (d_du2_34 & 0) d_du2_34 = 0; if (d_du2_35 & 0) d_du2_35 = 0; if (d_du2_36 & 0) d_du2_36 = 0; if (d_du2_37 & 0) d_du2_37 = 0; if (d_du2_38 & 0) d_du2_38 = 0; if (d_du2_39 & 0) d_du2_39 = 0; if (d_du2_40 & 0) d_du2_40 = 0; if (d_du2_41 & 0) d_du2_41 = 0; if (d_du2_42 & 0) d_du2_42 = 0; if (d_du2_43 & 0) d_du2_43 = 0; // haelt die Registerzuteilung wie im Original
}
//@ f_0e29b0
/* === Beschreibung (Katalog) ===
 * Lädt für ein spezielles Händlersortiment (Kategorie 1 im Register p2) die Liste vordefinierter Gegenstands-IDs
 * aus der Ressourcendatei 0x22000f, überspringt bis zum gewünschten Teilabschnitt p1->u1[1] die vorangehenden
 * nullterminierten Blöcke und fügt alle Gegenstände des Zielabschnitts mit unbegrenztem Vorrat (-1) über
 * f_0e2f70 in den Pool ein.
 * - Eingaben: Übergeben werden der Pool-Zeiger p1 sowie der Index des Kategorieregisters p2 (0..3).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e29b0(struct Pool *p1, short p2)
{
    char *q;
    short *buf;
    short n, h, k, m;
    q = new (mark(d_1a64bc, 0x14c)) char;
    n = f_11eae0(q, 0x22000f);
    h = (unsigned)(int)n >> 1;
    buf = (short *)new (mark(d_1a64bc, 0x15d)) char[h * 2];
    f_11ea00(q, 0x22000f, 0, buf, n);
    delete q;
    p1->u2[p2].b = p1->s->s10;
    k = 0;
    m = 0;
    for (m = 0; m < p1->u1[1]; k++, m++) {
        while (buf[k] > 0) k++;
    }
    while (buf[k] > 0) {
        f_0e2f70(p1, -1, buf[k], 0, 0);
        k++;
    }
    p1->u2[p2].c = p1->s->s10 - p1->u2[p2].b;
    delete buf;
}
