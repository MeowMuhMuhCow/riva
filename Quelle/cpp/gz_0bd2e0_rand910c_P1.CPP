/* === Beschreibung (Katalog) ===
 * Einheit gz_0bd2e0_rand910c (Adresse 0x0bd2e0 - 0x0bde40)
 *
 * Diese Einheit bildet die dritte Rand-Aufteilung von gz_0bd2e0 und ist mit dem nachfolgenden
 * Speichermanager-Modul memory (p:\riva\source\cpp\memory.cpp) zusammengelegt. Sie implementiert den gesamten
 * eigenen Heap- und Pool-Speichermanager von *Schatten über Riva*, der einen großen zusammenhängenden
 * DPMI-Speicherblock in doppelt verkettete Knoten (Node, 36 Bytes) unterteilt, kleine Blöcke (<= 128 KB) vom
 * unteren Ende und große Blöcke (> 128 KB) vom oberen Ende eines freien Bereichs abspaltet, benachbarte freie
 * Blöcke beim Freigeben wieder verschmilzt und alternativ einen linearen Stack-Allokator (Stk) bereitstellt.
 *
 *
 * Vorwärtsdeklarationen (Implementierung in gz_0bd2e0_rand910a und gz_0bd2e0_rand910b)
 *
 * Die Funktionen f_0bd2e0 bis f_0bd490 sind in dieser Teileinheit nur als Prototypen deklariert und in
 * gz_0bd2e0_rand910a bzw. gz_0bd2e0_rand910b beschrieben.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 9/9 gleich (suche.py 25.10.2026, Basis gz_0bd2e0_P1.CPP)
// gz_0bd2e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BD2E0-0x0BD5A0
#include <string.h>
struct Pool; // zusammengelegt: aus Teil 2 (memory)
struct Node { int a0; unsigned size; int used; int fre; Node *prev; Node *next; int a18; char *addr; Pool *pool; }; // zusammengelegt: aus Teil 2 (memory)
struct Pool { char *base; Node *nodes; int count; int c; int d; int size; }; // zusammengelegt: aus Teil 2 (memory)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_057220(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_060a80(int p1);
int f_091f70(int p1);
int f_0dcbb0(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
short f_0de800(int p1);
short f_0de820(int p1);

int f_1457e0(int p1);
int f_145234(int p1, int p2);
void f_145254(void);
extern int d_1bb2c4;
extern char d_1bdb74;
extern int d_1c0004;
extern int d_1c2be0;
extern int d_1c2c00;
//@ f_0bd2e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion lädt das passende Teilbild des Sichtfenster-Innenrahmens aus der Grafikressource
 *   0x40005 (Teilbild 1 bei aktivem Dungeon/Gebäude oder speziellem Stadtbereich, sonst Teilbild 0) in den
 *   übergebenen Bitmap-Puffer p2.
 * - Eingaben: Die Funktion nimmt den ungenutzten this-Zeiger p1 sowie den Ziel-Bitmap-Puffer p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd2e0(int p1, int p2)
;
//@ f_0bd350
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese mathematische Hilfsfunktion begrenzt (clamp) einen ganzzahligen Wert p1 auf das abgeschlossene
 *   Intervall zwischen der Untergrenze p2 und der Obergrenze p3.
 * - Eingaben: Die Funktion nimmt den zu begrenzenden Wert p1, das Minimum p2 und das Maximum p3 entgegen.
 * - Rückgabewert: Die Funktion gibt den auf den Bereich [p2, p3] begrenzten Wert zurück.
 === Ende Beschreibung === */
int f_0bd350(int p1, int p2, int p3)
;
//@ f_0bd360
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Würfelfunktion wertet ein gepacktes 16-Bit-Würfelformat p1 (wie es für Waffenschaden
 *   und Beutetabellen verwendet wird) aus: Die oberen 4 Bits ((p1 & 0xf000) >> 12) geben die Anzahl der Würfel
 *   an, die nächsten 4 Bits ((p1 & 0x0f00) >> 8) bestimmen den Würfeltyp (1 = W6, 2 = W20, 3 = W3, 4 = W4, sonst
 *   W100), und das untere Vorzeichenbyte (signed char)p1 bildet den festen Zahlenbonus.
 * - Eingaben: Die Funktion nimmt das gepackte 16-Bit-Würfelwort p1 entgegen.
 * - Rückgabewert: Die Funktion gibt die gewürfelte Gesamtsumme einschließlich des vorzeichenbehafteten Bonus
 *   zurück.
 === Ende Beschreibung === */
short f_0bd360(short p1)
;
//@ f_0bd3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Schauplatz-Objekt mit der Kennung 0x1b (27) über den
 *   Basiskonstruktor f_05ff60 und trägt die virtuelle Methodentabelle d_1bb2d8 bei Offset +0x08 ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das zu initialisierende Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
extern int d_1bb2d8;
void f_0bd3e0(int p1)
;
//@ f_0bd400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignis-Methode verarbeitet die Aktionscodes 0x65 (101) und 0x66 (102) des Schauplatzes 0x1b:
 *   Bei 0x65 wechselt die Gruppe über f_0dd7f0 (Typ 0x0b, Ziel 5000) den Schauplatz; bei 0x66 wird das
 *   Handlungsflag d_1bdb74 = 1 gesetzt, der Kampf 0x1e (30, f_091f70) gestartet, die Gruppe mit 20
 *   Abenteuerpunkten (f_0dcbb0) und dem Tagebucheintrag 0x8030048 (f_057220) belohnt und schließlich zum Ziel
 *   0x13f5 (5109) übergeleitet.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie den 16-Bit-Aktionscode p2 entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Code 0x65 oder 0x66 verarbeitet wurde, oder 0 im
 *   Standardfall.
 === Ende Beschreibung === */
short f_0bd400(int p1, unsigned short p2)
;
//@ f_0bd490
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Schauplatz-Objekt der Klasse d_1bb2d8 (d_1bb2c4) oder ein Array
 *   solcher Objekte (p2 & 4) ab, ruft den Basisdestruktor f_060030 auf und gibt bei gesetztem Bit p2 & 2 den
 *   Objektspeicher frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie die Watcom-Destruktor-Flags p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0bd490(int p1, unsigned p2)
;
//@ f_0bd4d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor setzt sämtliche neun 32-Bit-Felder (36 Bytes) eines Speicherknotens (Node) auf 0.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die zu initialisierende Node-Struktur entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd4d0(int *p)
{
    p[8] = 0;
    p[6] = 0;
    p[7] = 0;
    p[5] = 0;
    p[4] = 0;
    p[1] = 0;
    p[0] = 0;
    p[2] = 0;
    p[3] = 0;
}
//@ f_0bd510
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion richtet einen Speicherknoten (Node) als freien, belegten Listeneintrag
 *   (used = 1, fre = 1) ein und trägt den übergeordneten Pool-Zeiger p2, die Blockadresse p3 sowie die
 *   Blockgröße p4 ein.
 * - Eingaben: Die Funktion nimmt den Knotenzeiger p1, den Pool-Zeiger p2, die Speicheradresse p3 und die
 *   Blockgröße p4 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd510(int *p1, int p2, int p3, int p4)
{
    p1[5] = 0;
    p1[4] = 0;
    p1[2] = 1;
    p1[3] = 1;
    p1[8] = p2;
    p1[7] = p3;
    p1[1] = p4;
}
//@ f_0bd540
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion hängt einen Speicherknoten t aus der doppelt verketteten Liste (prev/next) des
 *   Speicher-Pools aus und setzt alle Felder des Knotens wieder auf 0 zurück, sodass der Knoteneintrag im
 *   Pool-Array wiederverwendet werden kann.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf den freizugebenden Node-Eintrag entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd540(Node *t)
{
    if (t->next != 0) t->next->prev = t->prev;
    if (t->prev != 0) t->prev->next = t->next;
    t->addr = 0; t->a18 = 0; t->next = 0; t->prev = 0;
    t->size = 0; t->a0 = 0; t->used = 0; t->fre = 0;
}
// ===== Teil 2: memory (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// P3 14/17 gleich (suche.py 29.10.2026, Basis memory_P1.CPP)
// Hinweis: f_0bd540 ist Nachbareinheit-Hilfsdefinition (noetig, damit Watcom es in f_0bd780 inlinet)
// memory.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BD5A0-0x0BDE40
// #include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// nach vorn (zusammengelegt): struct Pool;
// nach vorn (zusammengelegt): struct Node { int a0; unsigned size; int used; int fre; Node *prev; Node *next; int a18; char *addr; Pool *pool; };
// nach vorn (zusammengelegt): struct Pool { char *base; Node *nodes; int count; int c; int d; int size; };
struct Stk { unsigned base; unsigned *arr; unsigned n; int cap; int size; };
int f_0144e0();
int f_0ed8f0(const char *, ...);
int f_0ed950(const char *, ...);
void f_145300(char *p, int v, unsigned n);
char *f_15eaf3(int n);
void *f_15ec58(int n, int sz);
void f_15ebd6(void *p);
unsigned f_0bdd50(Stk *s, unsigned sz, int p3, int p4);
Node *f_0bdc40(Pool *p);
extern char d_1c1190[];
extern unsigned char d_1a55c0;
extern int d_1bf23c;
extern Stk d_1c11b8;
extern int *d_1c11bc;
extern short d_1c11c0;
extern const char d_1a55a0[];
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
void f_15ebd6(void *p);
// f_0bd540: Definition steht jetzt in Teil 1 (zusammengelegt 08.11.)
//@ f_0bd5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Kernfunktion reserviert einen Speicherblock der Größe sz innerhalb des freien Speicherknotens
 *   t: Ist der Knoten größer als benötigt, wird bei kleineren Anforderungen (sz <= 0x20000 = 128 KB) der
 *   Restblock hinter t abgespalten, bei großen Anforderungen (> 128 KB) dagegen der vordere Teil frei gelassen
 *   und t vom hinteren Ende bedient, um Fragmentierung zu vermeiden; anschließend wird der reservierte Bereich
 *   mit Nullen gefüllt (f_145300) und die freie Pool-Kapazität aktualisiert.
 * - Eingaben: Die Funktion nimmt den freien Speicherknoten t, die angeforderte Bytegröße sz sowie den
 *   Quelldateinamen p3 und die Zeilennummer p4 (für Fehlermeldungen) entgegen.
 * - Rückgabewert: Die Funktion gibt die Startadresse t->addr des reservierten und genullten Speicherbereichs
 *   oder 0 bei einem Fehler (0x29a0004) zurück.
 === Ende Beschreibung === */
#pragma aux f_0ed8f0 parm caller [] modify [eax]

static inline Node *g_0bdc40(Pool *p)
{
    int i;
    for (i = 0; i < p->count; i++) {
        if (p->nodes[i].used == 0) {
            Node *n = &p->nodes[i];
            n->used = 1;
            n->fre = 1;
            n->pool = p;
            n->addr = 0;
            n->next = 0;
            n->prev = 0;
            n->size = 0;
            return p->nodes + i;
        }
    }
    f_0ed8f0(d_1c1190, 0x29a0007);
    return 0;
}

char *f_0bd5a0(Node *t, int sz, int p3, int p4)
{
    t->a18 = p3;
    t->a0 = p4;
    if (sz > t->size || t->fre == 0) {
        f_0ed8f0(d_1c1190, 0x29a0004, sz, t->a18, t->a0);
        return 0;
    }
    if (sz == t->size) {
        if (t->next != 0 && (d_1a55c0 & 2)) {
            --d_1bf23c;
        }
    } else if (sz <= 0x20000) {
        Node *nn = g_0bdc40(t->pool);
        nn->next = t->next;
        nn->prev = t;
        if (t->next != 0) t->next->prev = nn;
        t->next = nn;
        nn->size = t->size - sz;
        nn->used = 1;
        nn->fre = 1;
        nn->addr = t->addr + sz;
        t->size = sz;
    } else {
        Node *nn = g_0bdc40(t->pool);
        nn->prev = t->prev;
        nn->next = t;
        if (t->prev != 0) t->prev->next = nn;
        t->prev = nn;
        nn->size = t->size - sz;
        nn->used = 1;
        nn->fre = 1;
        nn->addr = t->addr;
        t->addr = t->addr + nn->size;
        t->size = sz;
    }
    f_145300(t->addr, 0, t->size);
    t->pool->d -= t->size;
    if (t->pool->d < t->pool->c) t->pool->c = t->pool->d;
    t->fre = 0;
    return t->addr;
}
//@ f_0bd780
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den zum Speicherknoten n gehörenden Speicherblock p wieder frei (n->fre = 1),
 *   erhöht den Zähler des freien Pool-Speichers und verschmilzt (coalesce) den Knoten sofort mit einem
 *   unmittelbar nachfolgenden (n->next) und/oder vorangehenden (n->prev) freien Nachbarknoten über f_0bd540.
 *   Stimmt die übergebene Adresse p nicht mit n->addr überein, wird der Speicherfehler 0x29a0005 gemeldet.
 * - Eingaben: Die Funktion nimmt den Speicherknoten n, die freizugebende Adresse p sowie die Debug-Markierungen
 *   p3 (Quelldatei) und p4 (Zeilennummer) entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
// BLIND: f_0bd780 hier komplett neu aus dem Original-Assembler schreiben (orig.sh memory f_0bd780).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
void f_0bd780(Node *n, char *p, int p3, int p4)
{
    if (p != n->addr) {
        f_0ed950(d_1c1190, 0x29a0005, n->a18, n->a0);
        return;
    }

    n->fre = 1;
    n->pool->d += n->size;

    if (d_1a55c0 & 2) {
        if (n->next != 0 && n->next->fre != 0 &&
            n->prev != 0 && n->prev->fre != 0)
            --d_1bf23c;

        if (n->next != 0 && n->next->fre == 0 &&
            (n->prev == 0 || n->prev->fre == 0))
            ++d_1bf23c;
    }

    if (n->next != 0 && n->next->fre != 0) {
        n->size += n->next->size;
        f_0bd540(n->next);
    }

    if (n->prev != 0 && n->prev->fre != 0) {
        n->addr = n->prev->addr;
        n->size += n->prev->size;
        f_0bd540(n->prev);
    }
}

//@ f_0bd900
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion gibt an, ob der Speicher-Pool p erfolgreich initialisiert wurde und über einen
 *   gültigen Basisspeicherblock (p->base != 0) verfügt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn p->base ungleich 0 ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0bd900(Pool *p)
{
    return p->base != 0;
}
//@ f_0bd910
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor legt einen neuen Speicher-Pool p1 mit maximal p5 Verwaltungsknoten (calloc,
 *   f_15ec58) an und versucht, vom Betriebssystem (malloc, f_15eaf3) einen möglichst großen zusammenhängenden
 *   Speicherblock (höchstens p3 Bytes, mindestens p2 Bytes unter Freihaltung einer Reserve p4) in
 *   64-KB-Schritten (0x10000) anzufordern. Gelingt die Reservierung, wird der erste Knoten über die gesamte
 *   Pool-Größe eingerichtet; reicht der freie Speicher nicht für das Minimum p2 und ist p6 != 0, bricht das
 *   Spiel mit dem Fehler 0x29a0003 (zu wenig Speicher) ab.
 * - Eingaben: Die Funktion nimmt den Pool-Zeiger p1, die Mindestgröße p2, die Maximalgröße p3, die Systemreserve
 *   p4, die Knotenanzahl p5 sowie das Abbruch-Flag p6 entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Pool-Zeiger p1 zurück.
 === Ende Beschreibung === */
Pool *f_0bd910(Pool *p1, int p2, int p3, int p4, int p5, int p6)
{
    int t;
    if (f_0144e0() > 0x800000) p4 = p4 * 2;
    p1->count = p5;
    p1->nodes = (Node *)f_15ec58(p5, 0x24);
    p1->base = 0;
    if (p1->nodes == 0) {
        f_0ed8f0(d_1c1190, 0x29a0006, p1->count, 0x24);
    } else {
        p1->size = (f_0144e0() - p4) & 0xffff0000;
        if (p3 < p1->size) p1->size = p3;
        p1->base = 0;
        while (p1->base == 0) {
            t = p2 + p4;
            if (p2 > p1->size) {
                if (p6 == 0) {
                    f_15ebd6(p1->nodes);
                    return p1;
                }
                f_0ed8f0(d_1c1190, 0x29a0003, t - f_0144e0());
            }
            p1->base = f_15eaf3(p1->size);
            if (p1->base == 0) p1->size -= 0x10000;
        }
        p1->c = p1->size - 8;
        p1->d = p1->size - 8;
        {
            Node *nd = p1->nodes;
            char *bb = p1->base;
            int ss = p1->size;
            nd->next = 0; nd->prev = 0; nd->used = 1; nd->fre = 1;
            nd->pool = p1; nd->addr = bb; nd->size = ss;
        }
    }
    return p1;
}
//@ f_0bda30
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt den Basisspeicher (base) und das Zeiger-Array (arr) eines Stack-Allokators
 *   (Stk) über free (f_15ebd6) frei.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Stk-Struktur sowie ein ungenutztes zweites Argument
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger p zurück.
 === Ende Beschreibung === */
Stk *f_0bda30(Stk *p, int)
{
    if (p->base) f_15ebd6((void *)p->base);
    if (p->arr) f_15ebd6(p->arr);
    return p;
}

//@ f_0bda70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert sz Bytes aus dem Speicher-Pool pool (oder bei gesetztem Debug-/Stack-Bit
 *   d_1a55c0 & 8 aus dem globalen Stack-Allokator d_1c11b8): Sie rundet die Größe auf ein Vielfaches von 4 Bytes
 *   auf, sucht in der Knotenliste den ersten freien Knoten mit ausreichender Größe (sz <= q->size) und teilt ihn
 *   über f_0bd5a0 zu. Wird kein passender Block gefunden, löst sie den Out-of-Memory-Fehler 0x29a0004 aus.
 * - Eingaben: Die Funktion nimmt den Pool-Zeiger pool, die Bytegröße sz sowie Quelldatei p3 und Zeilennummer p4
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den reservierten Speicherblock oder 0 zurück.
 === Ende Beschreibung === */
char *f_0bda70(Pool *pool, int sz, int p3, int p4)
{
    Node *q;
    if (d_1a55c0 & 8) return (char *)f_0bdd50(&d_1c11b8, sz, p3, p4);
    switch (sz % 4) {
    case 0: break;
    case 1: sz += 3; break;
    case 2: sz += 2; break;
    case 3: sz += 1;
    }
    for (q = pool->nodes; q != 0; q = q->next) {
        if (sz <= q->size && q->fre != 0)
            return f_0bd5a0(q, sz, p3, p4);
    }
    f_0ed8f0(d_1c1190, 0x29a0004, sz, p3, p4);
    return 0;
}
//@ f_0bdb00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sucht in der verketteten Knotenliste des Speicher-Pools pool nach dem Knoten, dessen
 *   Startadresse mit dem freizugebenden Zeiger p übereinstimmt, und gibt ihn über f_0bd780 frei (bzw. entfernt
 *   ihn bei aktivem Stack-Modus d_1a55c0 & 8 aus dem Array d_1c11bc). Wird der Zeiger in der Knotenliste nicht
 *   gefunden, gibt sie die Warnung 0x29a0005 aus.
 * - Eingaben: Die Funktion nimmt den Pool-Zeiger pool, den freizugebenden Speicherzeiger p sowie Quelldatei p3
 *   und Zeilennummer p4 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct DummyB { char a; unsigned char b; };
extern DummyB d_dummy_b;
void f_0bdb00(Pool *pool, char *p, int p3, int p4)
{
    unsigned char t_210;
    Node *q;
    int i;
    if (*(volatile unsigned char *)&d_1a55c0 & 8) {
        unsigned char v = d_dummy_b.b;
        t_210 = d_1a55c0;
        d_dummy_b.b = v;
        char *searchP = p;
        if (t_210 & 0x10) {
            --*(unsigned *)&d_1c11c0;
            return;
        }
        for (i = 0; i < *(unsigned *)&d_1c11c0; ++i) {
            if ((int)searchP == d_1c11bc[i]) {
                for (; i < *(unsigned *)&d_1c11c0; ++i)
                    d_1c11bc[i] = d_1c11bc[i + 1];
                *(unsigned *)&d_1c11c0 = *(unsigned *)&d_1c11c0 - 1;
                return;
            }
        }
        return;
    }
    for (q = pool->nodes; q != 0; q = q->next) {
        if (p == q->addr) {
            f_0bd780(q, p, p3, p4);
            return;
        }
    }
    f_0ed950(d_1c1190, 0x29a0005, p3, p4);
}
//@ f_0bdbc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Diagnosefunktion durchläuft alle Knoten des Speicher-Pools p und ermittelt die Bytegröße des
 *   größten zusammenhängenden freien Speicherblocks.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt die Größe des größten freien Blocks in Bytes zurück.
 === Ende Beschreibung === */
unsigned f_0bdbc0(Pool *p)
{
    Node *q = p->nodes;
    unsigned m = 0;
    for (; q != 0; q = q->next) {
        if (q->fre != 0 && m < q->size) m = q->size;
    }
    return m;
}
//@ f_0bdbf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion summiert die Größen sämtlicher freien Knoten (q->fre != 0) im Speicher-Pool p,
 *   aktualisiert damit das Feld p->d (aktuell freier Gesamtspeicher) und gibt die Summe zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt die Gesamtzahl freier Bytes im Pool zurück.
 === Ende Beschreibung === */
int f_0bdbf0(Pool *p)
{
    int s = 0;
    Node *q;
    for (q = p->nodes; q != 0; q = q->next) {
        if (q->fre != 0) s += q->size;
    }
    p->d = s;
    return s;
}
//@ f_0bdc20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion gibt die gesamte Kapazität (p->size) des Speicher-Pools p in Bytes zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt die Gesamtgröße des Pools in Bytes zurück.
 === Ende Beschreibung === */
int f_0bdc20(Pool *p)
{
    return p->size;
}
//@ f_0bdc30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion gibt den historischen Tiefststand des freien Speichers (p->c, Low-Water-Mark)
 *   im Speicher-Pool p zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt den minimalen bisherigen freien Speicherstand in Bytes zurück.
 === Ende Beschreibung === */
int f_0bdc30(Pool *p)
{
    return p->c;
}
//@ f_0bdc40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sucht im Knoten-Array (p->nodes, Länge p->count) des Speicher-Pools p nach einem
 *   unbenutzten Knoteneintrag (q->used == 0), markiert ihn als belegt und initialisiert seine Grundfelder. Sind
 *   alle Knoteneinträge erschöpft, bricht sie mit dem Fehler 0x29a0007 ab.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Pool-Struktur entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den neu zugeteilten Node-Eintrag oder 0 zurück.
 === Ende Beschreibung === */
Node *f_0bdc40(Pool *p)
{
    int i;
    Node *q;
    for (i = 0; i < p->count; i++) {
        q = &p->nodes[i];
        if (q->used == 0) {
            q->used = 1; q->fre = 1; q->pool = p; q->addr = 0;
            q->next = 0; q->prev = 0; q->size = 0;
            return &p->nodes[i];
        }
    }
    f_0ed8f0(d_1c1190, 0x29a0007);
    return 0;
}
//@ f_0bdcb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert einen linearen Stack-Allokator (Stk), indem er über operator new[]
 *   einen Datenpuffer der Größe sz sowie ein Verwaltungs-Array für cap Zeigereinträge anlegt und den ersten
 *   Eintrag auf die Pufferbasis setzt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Stk-Struktur, die Puffergröße sz in Bytes und die maximale
 *   Eintragsanzahl cap entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Stk-Zeiger p zurück.
 === Ende Beschreibung === */
Stk *f_0bdcb0(Stk *p, int sz, int cap)
{
    p->base = (unsigned)(new (mark(d_1a55a0, 0x323)) char[sz]);
    p->arr = new (mark(d_1a55a0, 0x324)) unsigned[cap];
    p->arr[0] = p->base;
    p->n = 0;
    p->cap = cap;
    p->size = sz;
    return p;
}
//@ f_0bdd10
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt den Datenpuffer (base) und das Zeiger-Array (arr) eines Stack-Allokators (Stk)
 *   über operator delete wieder frei.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Stk-Struktur sowie ein ungenutztes zweites Argument
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger p zurück.
 === Ende Beschreibung === */
Stk *f_0bdd10(Stk *p, int)
{
    if (p->base) operator delete((void *)p->base);
    if (p->arr) operator delete(p->arr);
    return p;
}
//@ f_0bdd50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert sz Bytes (aufgerundet auf 4-Byte-Grenzen) fortlaufend im linearen
 *   Stack-Allokator s, speichert die neue Obergrenze im nächsten Slot s->arr[s->n + 1] und prüft, ob das
 *   Pufferende (s->base + s->size) überschritten wurde (Fehler 0x29a0008).
 * - Eingaben: Die Funktion nimmt den Zeiger s auf den Stack-Allokator, die angeforderte Größe sz sowie
 *   Quelldatei p3 und Zeilennummer p4 entgegen.
 * - Rückgabewert: Die Funktion gibt die Startadresse des neu zugeteilten Speicherstücks zurück.
 === Ende Beschreibung === */
unsigned f_0bdd50(Stk *s, unsigned sz, int p3, int p4)
{
    unsigned t;
    switch (sz & 3) {
    case 0: break;
    case 1: sz += 3; break;
    case 2: sz = sz + 2; break;
    case 3: sz += 1;
    }
    t = s->arr[s->n] + sz;
    s->arr[s->n + 1] = t;
    ++s->n;
    if (s->base + s->size <= s->arr[s->n]) {
        f_0ed8f0(d_1c1190, 0x29a0008, sz, p3, p4);
    }
    // haelt die Registerzuteilung wie im Original
    // regforce: t24 EDX statt EAX ist die einzige erforderliche Registerwahl.
    unsigned nn = s->n;
    unsigned off = nn * 4;
    s->n = nn;
    return *(unsigned *)((char *)s->arr + off - 4);
}
//@ f_0bdde0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entfernt einen zuvor im Stack-Allokator s reservierten Zeiger p wieder: Bei aktivem
 *   LIFO-Bit (d_1a55c0 & 0x10) wird lediglich der Zähler s->n dekrementiert, andernfalls wird p im Array s->arr
 *   gesucht und durch Aufrücken der nachfolgenden Einträge gelöscht.
 * - Eingaben: Die Funktion nimmt den Zeiger s auf den Stack-Allokator, die Adresse p sowie die ungenutzten
 *   Debug-Parameter p3 und p4 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bdde0(Stk *s, unsigned p, int p3, int p4)
{
    unsigned i;
    if (d_1a55c0 & 0x10) {
        --s->n;
        return;
    }
    for (i = 0; i < s->n; ++i) {
        if (p == s->arr[i]) {
            for (; i < s->n; ++i)
                s->arr[i] = s->arr[i + 1];
            s->n = s->n - 1;
            return;
        }
    }
}
