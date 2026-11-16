/* === Beschreibung (Katalog) ===
 * Einheit fi_olist (07dee0 - 07ed80)
 *
 * Überblick
 * Die Einheit fi_olist (Fight Object List) enthält zunächst die interaktive Bewegungsziel-Auswahl für Helden
 * (f_07dee0) und anschließend die Methoden der doppelt verketteten Darstellungsliste OList (f_07e5c0 bis
 * f_07ec10), die alle Figuren, Leichen, Hindernisse und Bodenmarkierungen auf dem isometrischen Kampffeld nach
 * Tiefen- und Prioritätsreihenfolge sortiert verwaltet.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMOUS.H"
// P3 14/20 gleich (suche.py 25.10.2026, Basis fi_olist_P1.CPP)
// P2h 13/20 gleich
// fi_olist.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07DEE0-0x07ED80
#include <string.h>
#include "RIVAMEM.H"



struct Node {
    signed char x, y;            // 0,1
    char c2, c3, c4, c5;
    char c6;                     // 6
    char c7, c8;
    char id;                     // 9
    signed char prio;            // 0xa
    char vis;                    // 0xb
    char cc;
    char grp;                    // 0xd
    char ce;
    int i0f;                     // 0xf
    int i13;                     // 0x13
    Node *next;                  // 0x17
    Node *prev;                  // 0x1b
    char f1f;                    // 0x1f
    char f20;                    // 0x20
};
struct OList {
    Node *head;                  // 0
    int pad;                     // 4
    char *used;                  // 8
    OList *f_07e5c0();
    OList *f_07e640(int flags);
    void f_07e6c0();
    void f_07e730(char id);
    void f_07e760(char id);
    void f_07e790();
    void f_07e7c0(char id);
    void f_07e850(char id);
    void f_07e8e0();
    void f_07e930();
    int f_07ea20(char id);
    Node *f_07ea60(char id);
    Node *f_07ea90(char c6, signed char x, signed char y);
    Node *f_07ead0(int v);
    Node *f_07eb00(char grp);
    void f_07eb30(char id, short *px, short *py);
    void f_07eb80();
    void f_07eba0(char id, char keep);
    char f_07ec10(signed char id);
};
#define THIS 
void *f_014540(int size, const char *file, int line);   // reg eax edx ebx
                           // reg eax edx stapel 0
int f_071e90(int p1, short *p2, short *p3);             // reg eax edx ebx stapel 0
int f_0757f0(int p1);                                   // reg eax stapel 0
int f_077400(int p1);                                   // reg eax stapel 0
int f_07d6a0(int p1, int p2);                           // reg eax edx stapel 0
int f_07db20(int p1, int p2, short *px, short *py, short *p3, short *p4, short *mode, short *sel);// reg eax edx ebx ecx stapel 16
int f_0bf6f0(void *p1, int p2);                         // reg eax edx stapel 0
int f_0bf730(void *p1, int p2);                         // reg eax edx stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d4850(char *p1, int p2, int p3);                 // reg eax edx ebx
char f_0d54c0(int p1);                                  // reg eax stapel 0
short f_0de820(int p1);                                 // reg eax stapel 0
int f_0e93f0(void *p1, char *p2, int p3);               // reg eax edx ebx stapel 0
struct Obj { char pad[0x14]; char *p; char rest[0x3c - 0x18]; };
int f_125400(Obj *p1, void *p2, void *p3, void *p4);    // reg eax edx ebx ecx
int f_1254a0(Obj *p1, int p2);                          // reg eax
short f_149360(int p1, const void *p2);
void *f_145300(void *p, int c, unsigned n);              // memset
extern const char d_1a1fe4[];           // Text "p:\riva\source\cpp\fi_olist.cpp"
extern char d_1a2814[];
extern char d_1a2834[];
extern short d_1bd766;
extern Node *d_1bd94c;
extern char *d_1bda5c;
extern int d_1bda68;
extern volatile short d_1bf4f0; // Maus-X (Interrupt-aktualisiert, erzwingt Speicherzugriff in f_07dee0)
extern volatile short d_1bf4f2; // Maus-Y (Interrupt-aktualisiert, erzwingt Speicherzugriff in f_07dee0)
extern int d_1c0004;
extern char d_1c21b4[];
extern char d_1c2c64[];
extern Node *d_1c2ecc;
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
#define NIL d_1c2ecc
#define B(p,o) (*(unsigned char *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define NOID ((char)0xff)
#define CUR (*(char *)(p1 + 0x294))
#define MGB(f) int f; if (f_0d3860() == 1) { f_0d2710(); f = 1; } else { f = 0; }
#define MGE(f) if (f == 1) f_0d26e0();


#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_07dee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die interaktive Zielauswahl für die Bewegung eines Helden (p2) per Maus oder Pfeiltasten
 *   durch, bewegt den grünen Zielrahmen über das isometrische Kampfraster, zeigt für jedes angepeilte Feld
 *   laufend die benötigten Aktionspunkte bzw. eine Flucht- oder Blockademeldung in der unteren Textzeile an
 *   (f_07db20) und startet nach Bestätigung (Linksklick oder Enter) die Laufbewegung über f_07d6a0 (bzw. fragt
 *   am Kampffeldrand zuvor, ob der Held wirklich fliehen soll).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie die Zeiger p3 (X)
 *   und p4 (Y) auf die Start- und Endkoordinaten des Helden und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das lokale Array tab[24] begrenzt die maximal begehbare X-Koordinate pro Zeile an der
 *   schrägen rechten Kampffeldgrenze, und CUR (*(char *)(p1 + 0x294)) speichert die Knoten-ID des beweglichen
 *   Auswahlrahmens in der Darstellungsliste.
 === Ende Beschreibung === */
void f_07dee0(int p1, int p2, short *p3, short *p4)
{
    short t;
    int guard2;
    short i;
    short xsave;
    short y;
    short sely;
    short sel;
    short mx;
    short mode;
    signed char tab[24] = { 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9 };
    short x;
    Obj obj;
    short selx;
    int guard0;
    int guard3;
    short my;
    short ysave;
    int guard1;
    x = *p3;
    y = *p4;
    f_0d26e0();
    mx = d_1bf4f0;
    my = d_1bf4f2;
    if (CUR != NOID) {
        ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
        CUR = NOID;
    }
    p4 = (short *)(((int)p4 & 0) ? 0 : (int)p4); // haelt Parameter-Stapelplatzfolge fuer p2/p3/p4 wie im Original
    B(p1, 0x1e) = 0;
    B(p1, 0x18) = (char)x;
    B(p1, 0x19) = (char)y;
    B(p1, 0x1f) = 0;
    B(p1, 0x20) = 6;
    B(p1, 0x24) = 0;
    I(p1, 0x27) = 0;
    B(p1, 0x22) = 2;
    B(p1, 0x23) = 1;
    
    I(p1, 0x2b) = I(p1, 0x1f1);
    B(p1, 0x25) = 0xff;
    CUR = ((OList *)(p1 + 0x39))->f_07ec10(-1);
    f_0757f0(p1);
    p3 = (short *)(((int)p3 & 0) ? 0 : (int)p3); // haelt Lebensdauer und Stapelplatz von p3 ueber die Hauptschleife
    p4 = (short *)(((int)p4 & 0) ? 0 : (int)p4); // haelt Lebensdauer und Stapelplatz von p4 ueber die Hauptschleife
    do {
        f_077400(p1);
        xsave = x;
        ysave = y;
        if (f_0d3810()) {
            mx = d_1bf4f0;
            my = d_1bf4f2;
            t = my * 2 + mx - 0xd5;
            if (t < 0) t -= 0x13;
            selx = t / 0x14 - 1;
            t = mx - my * 2 + 0xfb;
            if (t < 0) t -= 0x13;
            sely = t / 0x14 - 1;

            if (selx < -1) selx = -1;
            if (selx > 0x18) selx = 0x18;
            if (sely < -1) sely = -1;
            if (sely > 0x18) sely = 0x18;
            if (selx != x || sely != y) d_1bd766 = (short)999;
        }
        if (f_0d3780()) d_1bd766 = 0x1c0d;
        if (d_1bd766 == 0x4d00 && x < 0x17) x++;
        else if (d_1bd766 == 0x4b00 && x >= 0) x--;
        else if (d_1bd766 == 0x4800 && y <= 0x17) y++;
        else if (d_1bd766 == 0x5000 && y >= 0) y--;
        else if (d_1bd766 == (short)999) { x = selx; y = sely; }
        if (x < 0 && y < 0) x = 0;
        if (x < 0 && y > 0x17) x = 0;
        for (i = 0; i < 0x17; i++) {
            if (x > tab[i] && i == y) { x = tab[i]; break; }
        }
        if (x != xsave || y != ysave) {
            f_07db20(p1, p2, &x, &y, p3, p4, &mode, &sel);
            if (mode == 0) {
                f_125400(&obj, d_1c349c, d_1c3870, d_1c3498);
                *(short *)(obj.p + 2) = sel;
                f_0e93f0(d_1c38b0, d_1c21b4, 0x101000d);
                f_1254a0(&obj, 0);
            } else if (mode == 1) f_0e93f0(d_1c38b0, d_1c21b4, 0x101000e);
            else if (mode == 3) f_0e93f0(d_1c38b0, d_1c21b4, 0x101001f);
            else if (mode == 2) f_0e93f0(d_1c38b0, d_1c21b4, 0x1010021);
            else if (mode == 4) f_0e93f0(d_1c38b0, d_1c21b4, 0x101002b);
            f_0d4850(d_1c21b4, 0x16, 0x20);
            strcpy(d_1bda5c, d_1c21b4);
            d_1bda68 = 1;
            ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
            B(p1, 0x18) = (char)x;
            B(p1, 0x19) = (char)y;
            I(p1, 0x2b) = I(p1, 0x1f1);
            B(p1, 0x25) = 0xff;
            CUR = ((OList *)(p1 + 0x39))->f_07ec10(-1);
            f_0757f0(p1);
        }
        if (f_0d37b0() || d_1bd766 == 0x11b) {
            d_1bd766 = 0x1c0d;
            mode = 5;
        }
    } while (d_1bd766 != 0x1c0d);
    f_0d3870();
    if (*p3 == x && *p4 == y) goto ende;
    if (mode == 0 || mode == 1 || mode == 2) {
        if (mode == 1) {
            (void)&guard0; // bindet Mauswache-Flag ohne inline-Dtor-COMDAT an seinen Stapelplatz
            if (f_0d3860() == 1) { f_0d2710(); guard0 = 1; } else { guard0 = 0; }
            if (f_149360(W(p1, 0x1ea), d_1a2814) != -1 || f_149360(f_0de820(d_1c0004), d_1a2834) != -1) {
                f_0bf730(d_1c2c64, 0x10100a5);
                ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
                CUR = NOID;
            } else {
                if (f_0bf6f0(d_1c2c64, 0x1010024) == 1) {
                    f_042650((struct hero *)(p2), 1);
                    mode = 0;
                } else {
                    ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
                    CUR = NOID;
                }
            }
            
        if (guard0 == 1) f_0d26e0();
            }
        if (mode == 0 || mode == 2) {
            ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
            CUR = NOID;
            {
                (void)&guard1; // bindet Mauswache-Flag an seinen Stapelplatz
            if (f_0d3860() == 1) { f_0d2710(); guard1 = 1; } else { guard1 = 0; }
                f_07d6a0(p1, p2);
                
            if (guard1 == 1) f_0d26e0();
            }
            f_071e90((unsigned char)(f_0d54c0(p2) + 1), p3, p4);
        p3 = (short *)(((int)p3 & 0) ? 0 : (int)p3); // haelt Parameter-Lebensdauer von p3 bis nach dem Aufruf
        }
    } else if (mode == 3) {
        (void)&guard2; // bindet Mauswache-Flag an seinen Stapelplatz
            if (f_0d3860() == 1) { f_0d2710(); guard2 = 1; } else { guard2 = 0; }
        f_0bf730(d_1c2c64, 0x101002c);
        
    if (guard2 == 1) f_0d26e0();
            } else if (mode == 4) {
        (void)&guard3; // bindet Mauswache-Flag an seinen Stapelplatz
            if (f_0d3860() == 1) { f_0d2710(); guard3 = 1; } else { guard3 = 0; }
        f_0bf730(d_1c2c64, 0x101002d);
        
    if (guard3 == 1) f_0d26e0();
            }
ende:
    if (CUR != NOID) {
        ((OList *)(p1 + 0x39))->f_07eba0(CUR, 0);
        CUR = NOID;
    }
    f_0d2710();
    d_1bda68 = 1;
    *d_1bda5c = 0;
}
//@ f_07e5c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor der Darstellungsliste OList: Er reserviert das 255-Byte-Belegungsarray used sowie
 *   den Dummy-Listenkopf head und initialisiert beide für ein neues Kampffeld.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger der OList-Instanz und gibt this zurück.
 * - Wichtige Variablen: Das Array used[0..254] markiert vergebene Knoten-IDs (wobei used[0] = 0xff reserviert
 *   bleibt), und head bildet das Wurzelelement der verketteten Liste.
 === Ende Beschreibung === */
OList *OList::f_07e5c0()
{
    Node *n;
    used = (char *)f_014540(0xff, d_1a1fe4, 0x20);
    n = (Node *)f_014540(0x21, d_1a1fe4, 0x21);
    head = n;
    n->next = 0;
    head->prev = n->next;
    head->grp = 0xff;
    head->i13 = 0;
    head->i0f = 0;
    head->x = 0x9d;
    head->y = 0x9d;
    f_145300(used, 0, 0xff);
    *used = 0xff;
    return this;
}
//@ f_07e640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor der Darstellungsliste OList: Er gibt sämtliche verketteten Node-Elemente vom
 *   Listenende rückwärts frei und löscht anschließend auch head sowie das Belegungsarray used.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie das Destruktor-Flag flags und gibt this
 *   zurück.
 * - Wichtige Variablen: Die Schleife wandert zunächst bis NIL (d_1c2ecc) ans Ende der Liste und löscht danach
 *   über q->prev alle Knoten.
 === Ende Beschreibung === */
OList *OList::f_07e640(int flags)
{
    Node *p;
    Node *q;
    OList *that = this;
    p = that->head;
    while (p->next != NIL) p = p->next;
    q = p;
    if (q->prev != 0) do {
        q = q->prev;
        delete q->next;
    } while (q->prev != 0);
    p = that->head;
    p->next = 0;
    that->head->prev = p->next;
    f_145300(that->used, 0, 0xff);
    delete head;
    delete used;
    return this;
}
//@ f_07e6c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leert die Darstellungsliste OList bis auf den Dummy-Kopf head, gibt alle angehängten
 *   Node-Elemente frei und setzt das Belegungsarray used komplett auf 0 zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Wurzelknoten head bleibt erhalten, damit die Liste anschließend sofort neu befüllt
 *   werden kann.
 === Ende Beschreibung === */
void OList::f_07e6c0()
{
    Node *p;
    Node *q;
    p = head;
    while (p->next != NIL) p = p->next;
    q = p;
    if (q->prev != 0) do {
        q = q->prev;
        delete q->next;
    } while (q->prev != 0);
    p = head;
    p->next = 0;
    head->prev = p->next;
    f_145300(used, 0, 0xff);
}
//@ f_07e730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht den Knoten mit der Kennung id in der Darstellungsliste und setzt dessen Löschvormerkung
 *   p->f1f = 1, damit er beim nächsten Listen-Update (f_07e930) entfernt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Feld p->f1f (+0x1f) markiert einen Knoten zum verzögerten Entfernen.
 === Ende Beschreibung === */
void OList::f_07e730(char id)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return;
        p = p->next;
    }
    p->f1f = 1;
}
//@ f_07e760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht den Knoten mit der Kennung id in der Darstellungsliste und setzt dessen Umsortier-Flag
 *   p->f20 = 1, damit er beim nächsten Listen-Update (f_07e930) entsprechend seiner neuen Position neu
 *   einsortiert wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Feld p->f20 (+0x20) kennzeichnet einen Knoten, dessen Rasterkoordinaten oder
 *   Zeichenpriorität sich geändert haben.
 === Ende Beschreibung === */
void OList::f_07e760(char id)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return;
        p = p->next;
    }
    p->f20 = 1;
}
//@ f_07e790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft die verkettete Darstellungsliste vom Kopf head bis zum letzten Knoten vor NIL, ohne
 *   dabei eine Änderung vorzunehmen (wirkungslose Leerschleife; siehe Fehlerliste).
 * - Eingaben und Rückgabe: Die Methode erhält lediglich den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der lokale Zeiger p wandert bis p->next == d_1c2ecc und verfällt beim Rücksprung.
 === Ende Beschreibung === */
void OList::f_07e790()
{
    Node *p;
    p = head;
    while (p->next != NIL) p = p->next;
}
//@ f_07e7c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet den Knoten mit der Kennung id (und bei zweifeldrigen Figuren über p->grp auch das
 *   zugehörige zweite Körpersegment) in der Kampfdarstellung aus, indem vis = 0 gesetzt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Feld p->vis (+0x0b) steuert die Sichtbarkeit des Knotens, und p->grp (+0x0d) koppelt
 *   Vorder- und Hinterteil zweifeldriger Figuren im Abstand 0x14.
 === Ende Beschreibung === */
void OList::f_07e7c0(char id)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return;
        p = p->next;
    }
    p->vis = 0;
    if (p->grp != (char)0xff) {
        if (p->grp > 0x14) p = f_07eb00(p->grp - 0x14); else p = f_07eb00(p->grp + 0x14);
        p->vis = 0;
    }
}
//@ f_07e850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet den Knoten mit der Kennung id (sowie bei zweifeldrigen Figuren auch das gekoppelte
 *   Partnersegment) wieder auf sichtbar (vis = 1).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Über f_07eb00(p->grp +/- 0x14) wird bei Großgegnern das zweite Segment ermittelt.
 === Ende Beschreibung === */
void OList::f_07e850(char id)
{
    Node *p;
    char g;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return;
        p = p->next;
    }
    p->vis = 1;
    if (p->grp != (char)0xff) {
        if (p->grp > 0x14) p = f_07eb00(p->grp - 0x14); else p = f_07eb00(p->grp + 0x14);
        p->vis = 1;
    }
}
//@ f_07e8e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sortiert sämtliche derzeit aktiven Knoten (used[1..254] != 0) der Darstellungsliste komplett
 *   neu nach ihrer Tiefenreihenfolge, indem jeder Knoten nacheinander über f_07eba0 entnommen und über f_07ec10
 *   neu eingefügt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der globale Zwischenpuffer d_1bd94c hält jeweils die Knotendaten während des Aus- und
 *   Wiedereinhängens.
 === Ende Beschreibung === */
void OList::f_07e8e0()
{
    unsigned char i;
    i = 1;
    while (i < 0xff) {
        if (used[i]) {
            f_07eba0(i, 1);
            f_07ec10((signed char)i);
        }
        i++;
    }
}
//@ f_07e930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Arbeitet alle vorgemerkten Änderungen in der Darstellungsliste ab: Knoten mit gesetztem
 *   Löschflag f1f werden endgültig entfernt (f_07eba0(id, 0)), und Knoten mit gesetztem Update-Flag f20 werden
 *   aus- und an ihrer neuen Tiefenposition wieder eingehängt (f_07eba0 + f_07ec10).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable frame.nid merkt sich vor dem Aushängen die ID des Nachfolgeknotens, damit
 *   der Listendurchlauf nahtlos fortgesetzt werden kann.
 === Ende Beschreibung === */
void OList::f_07e930()
{
    Node *p;
    struct { char nid; char pad[3]; char id; } frame;
    int again;
    p = head;
    do {
        again = 0;
        if (p->f1f) {
            again = 1;
            frame.nid = 0xff;
            if (p->next != NIL) frame.nid = p->next->id;
            f_07eba0(p->id, 0);
        } else if (p->f20) {
            again = 1;
            
            frame.nid = 0xff;
            if (p->next != NIL) frame.nid = p->next->id;
            frame.id = p->id;
            f_07eba0(frame.id, 1);
            d_1bd94c->f20 = 0;
            f_07ec10((signed char)frame.id);
        }
        if (again) {
            if (frame.nid != (char)0xff) p = f_07ea60(frame.nid); else p = NIL;
        } else p = p->next;
    } while (p != NIL);
}
//@ f_07ea20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein Knoten mit der Kennung id in der Darstellungsliste existiert.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt 1 zurück, wenn der
 *   Knoten gefunden wurde, sonst 0.
 * - Wichtige Variablen: Die Suche endet mit 0, sobald p->next == d_1c2ecc erreicht wird.
 === Ende Beschreibung === */
int OList::f_07ea20(char id)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return 0;
        p = p->next;
    }
    return 1;
}
//@ f_07ea60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht den Knoten mit der Kennung id in der Darstellungsliste und gibt dessen Zeiger zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Knoten-ID id und gibt den Node-Zeiger
 *   (oder 0, falls nicht vorhanden) zurück.
 * - Wichtige Variablen: Das Feld p->id (+0x09) speichert die eindeutige Knoten-ID.
 === Ende Beschreibung === */
Node *OList::f_07ea60(char id)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return 0;
        p = p->next;
    }
    return p;
}
//@ f_07ea90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der Darstellungsliste nach einem Knoten mit dem Typcode c6 an den Rasterkoordinaten
 *   (x, y).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, den Typcode c6 sowie die Koordinaten x und y und
 *   gibt den gefundenen Node-Zeiger (oder 0) zurück.
 * - Wichtige Variablen: Verglichen werden die Knotenfelder p->c6 (+0x06), p->x (+0x00) und p->y (+0x01).
 === Ende Beschreibung === */
Node *OList::f_07ea90(char c6, signed char x, signed char y)
{
    Node *p;
    p = head;
    while (p->c6 != c6 || p->x != x || p->y != y) {
        if (p->next == NIL) return 0;
        p = p->next;
    }
    return p;
}
//@ f_07ead0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der Darstellungsliste nach dem Knoten, dessen Animations-Handle i0f mit dem
 *   übergebenen Wert v übereinstimmt.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie das Animations-Handle v und gibt den
 *   zugehörigen Node-Zeiger (oder 0) zurück.
 * - Wichtige Variablen: Das Feld p->i0f (+0x0f) verknüpft den Darstellungsknoten mit seinem aktiven
 *   Animationsslot.
 === Ende Beschreibung === */
Node *OList::f_07ead0(int v)
{
    Node *p;
    p = head;
    while (p->i0f != v) {
        if (p->next == NIL) return 0;
        p = p->next;
    }
    return p;
}
//@ f_07eb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der Darstellungsliste nach einem Knoten mit der Gruppen- bzw. Figurenkennung grp.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die Gruppenkennung grp und gibt den
 *   gefundenen Node-Zeiger (oder 0) zurück.
 * - Wichtige Variablen: Das Feld p->grp (+0x0d) identifiziert die Kampffigur bzw. deren zweites Körpersegment
 *   (+0x14).
 === Ende Beschreibung === */
Node *OList::f_07eb00(char grp)
{
    Node *p;
    p = head;
    while (p->grp != grp) {
        if (p->next == NIL) return 0;
        p = p->next;
    }
    return p;
}
//@ f_07eb30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuellen Kampfraster-Koordinaten (x, y) des Knotens mit der Kennung id aus der
 *   Darstellungsliste aus.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Knoten-ID id sowie die Ausgabezeiger px und
 *   py und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Falls die ID nicht gefunden wird, liefert die Schleife die Koordinaten des letzten
 *   Knotens der Liste zurück.
 === Ende Beschreibung === */
void OList::f_07eb30(char id, short *px, short *py)
{
    Node *p;
    p = head;
    while (p->id != id && p->next != NIL) p = p->next;
    *px = p->x;
    *py = p->y;
}
//@ f_07eb80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht den ersten freien Eintrag im Belegungsarray used und markiert ihn als belegt (1).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array used verwaltet die Vergabe der Knoten-IDs 1..254.
 === Ende Beschreibung === */
void OList::f_07eb80()
{
    unsigned char i;
    i = 0;
    while (used[i]) i++;
    used[i] = 1;
}
//@ f_07eba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entfernt den Knoten mit der Kennung id aus der doppelt verketteten Darstellungsliste und gibt
 *   entweder dessen ID in used frei (keep == 0) oder sichert seine Daten für ein anschließendes Wiedereinfügen
 *   nach *d_1bd94c (keep != 0).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Knoten-ID id sowie das Sicherungsflag keep
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der globale Knotenpuffer d_1bd94c dient als Vorlage beim anschließenden Aufruf von
 *   f_07ec10.
 === Ende Beschreibung === */
void OList::f_07eba0(char id, char keep)
{
    Node *p;
    p = head;
    while (p->id != id) {
        if (p->next == NIL) return;
        p = p->next;
    }
    if (!keep) used[id] = 0;
    else *d_1bd94c = *p;
    if (p->next == NIL) p->prev->next = NIL;
    else { p->prev->next = p->next; p->next->prev = p->prev; }
    delete p;
}
//@ f_07ec10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt einen neuen Knoten aus den im globalen Puffer *d_1bd94c vorbereiteten Daten, vergibt
 *   bei id == -1 automatisch eine freie Knoten-ID und fügt den Knoten entsprechend seiner isometrischen
 *   Tiefenposition (x, y) und Zeichenpriorität (prio) sortiert in die verkettete Liste ein.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die gewünschte Knoten-ID id (oder -1 für
 *   Neuvergabe) und gibt die tatsächliche Knoten-ID als char zurück.
 * - Wichtige Variablen: Knoten mit prio == -2 erhalten am Ende die hohe Vordergrundpriorität 0x63 (für
 *   schwebende Markierungen und Geschosse).
 === Ende Beschreibung === */
char OList::f_07ec10(signed char id)
{
    int end_priority;
    char r;
    short x, y;
    Node *n;
    Node *p;
    n = (Node *)f_014540(0x21, d_1a1fe4, 0x24c);
    x = d_1bd94c->x;
    y = d_1bd94c->y;
    *n = *d_1bd94c;
#define CX x
#define CY y
    if (id == -1) {
        unsigned char i;
        OList *q = this;
        char *used_base;
        i = 0;
        while ((used_base = q->used)[i]) { i++; d_1bd94c = ((int)d_1bd94c & 0) ? 0 : d_1bd94c; } // haelt d_1bd94c im Register ebp mit Epilog-Rueckschreiben
        used_base[i] = 1;
        n->id = i;
    } else n->id = id;
    p = THIS head;
    if (d_1bd94c->prio >= 0) {
        for (;;) {
            if ((CX < p->x || (CX == p->x && CY > p->y) || (CX == p->x && CY == p->y && p->prio > d_1bd94c->prio)) && p->prio >= 0) break;
            if (p->next == NIL) {
                p->next = n;
                n->prev = p;
                n->next = NIL;
                r = n->id;
                goto done;
            }
            p = p->next;
        }
    }
    if (p == THIS head) {
        n->next = THIS head->next;
        if (n->next != NIL) n->next->prev = n;
        p->next = n;
        n->prev = p;
    } else {
        n->prev = p->prev;
        n->prev->next = n;
        p->prev = n;
        n->next = p;
    }
    end_priority = (n->prio & 0) ? 0 : n->prio; // haelt die Registerfolge (ebx/edx) in den beiden Schleifen
    if (end_priority == -2) n->prio = 0x63;
    r = n->id;
done:
    return r;
#undef CX
#undef CY
}
