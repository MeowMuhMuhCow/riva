/* === Beschreibung (Katalog) ===
 * Einheit dealitem (050860 - 051850)
 *
 * Überblick
 * Diese Einheit (dealitem.cpp) verwaltet den "Am-Mauszeiger-gehaltenen" Gegenstand (struct Deal) beim
 * Verschieben, Stapeln, Tauschen und Ablegen von Gegenständen zwischen einem Helden-Inventar (p1->inv) und einem
 * zweiten Gegenstandscontainer wie einer Truhe, einem Beutelager oder einem zweiten Inventar (p1->src). Sie
 * aktualisiert dabei auch das zum Gegenstand gehörende Mauszeiger-Sprite samt eingeblendeter Stapelzahl und die
 * Gegenstands-Beschreibungszeile.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 13/23 gleich (suche.py 25.10.2026, Basis dealitem_P1.CPP)
// dealitem.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x050860-0x051850
#include <string.h>
#pragma intrinsic(memcpy, memcmp, strlen)
// --- Typen/Daten ---
struct Dat { signed char b[0x1b]; };
struct Item {
    short cnt; short id; Dat d;
    Item() { cnt = 0; id = 0; memset(d.b, 0, 0x1b); }
    Item(const Item &o) { Dat t = o.d; cnt = o.cnt; id = o.id; memcpy(&d, &t, 0x1b); }
    Item(short c, short i, Dat s) { cnt = c; id = i; memcpy(&d, &s, 0x1b); }
};
struct G9 { char c[9]; };
struct Deal { Item *item; int inv; int src; int gfx; int p4; short kind; short idx; int p6; };
extern const char d_1a141c[];
extern int d_1a34e0;
extern signed char d_1bf4ef;
extern char d_1c21b4[];
extern char d_1c2be0[];

extern char d_1c2c64[];
extern char d_1c3068[];
extern char d_1c38b0[];
int f_026a20(int, int);
short f_026a70(int, int);
Item *f_026a80(int, int);
short f_0264d0(int, int);
int f_025c40(int);
short f_025c50(int, Item *);
int f_025cd0(int);
short f_025f90(int, Item *, int, int, int);
short f_026150(int, Item *, int, int, int, int);
short f_026280(int, Item *, int, int, int, int);
int f_026600(int, int);
int f_0268c0(int);

int f_0bf730(void *, int);





void f_0a7840(RivaItemDefinition *item,char *dst,short n);
int f_0e9300(void *, void *, int);
int f_0e9660(void *, void *, int, int);
short f_0e9690(void *, void *);
int f_05dec0(void *);
int f_05ded0(void *, int);
int f_05e320(void *, int, int);
void f_05e360(void *, short *, short *);






int f_04fef0(void *, int, int, int, int, int, int);
int f_050580(void *, int, int, int *, int *);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0d3080();
int f_0d2f90(int, int);
int f_11c160(int);
int f_11c170(int, int);
short f_11c320(int);
int f_11c350(int, Item *);
int f_11c460(int, int, Item *);
int f_11c580(int, int);
short f_11c5f0(int, int);
short f_11c620(int, int);
Dat *f_11c650(int, int);
int f_11c6e0(int, int, int);
int f_148518(int, char *, int);
void f_050ea0(Deal *p1, int p2);
void f_0512b0(Deal *p1, int p2, Item *p3, int p4, int p5, int p6, int p7);
void f_051350(Deal *p1, short p2);
void f_0515f0(Deal *p1, short p2);
void f_051780(Deal *p1);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_050860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert das Transfer-Objekt (Deal) für den Gegenstandsaustausch zwischen Heldeninventar
 *   und Zweitcontainer, legt ein leeres Item-Objekt sowie ein 16x16 Pixel großes Rasterbild für den Mauszeiger
 *   an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (Deal *), den Inventarzeiger p2, den Zweitcontainer
 *   p3 sowie die Hintergrund-Ressourcenkennung p4 und gibt p1 zurück.
 * - Wichtige Variablen: Die Felder p1->inv, p1->src und p1->p6 speichern die Container- und Grafikreferenzen,
 *   p1->item hält den aktuell aufgenommenen Gegenstand, und p1->gfx verweist auf das 16x16-Mauscursor-Bitmap.
 === Ende Beschreibung === */
Deal *f_050860(Deal *p1, int p2, int p3, int p4)
{
    p1->inv = p2;
    p1->src = p3;
    p1->p6 = p4;
    Item *it = new (mark(d_1a141c, 0x3e)) Item;
    p1->p4 = 0;
    p1->kind = -1;
    p1->idx = -1;
    p1->item = it;
    int t = (int)new (mark(d_1a141c, 0x4e)) G9;
    int g = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0x10, 0x10))) : t;
    p1->gfx = g;
    return p1;
}

//@ f_0508f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut das Transfer-Objekt (Deal) beim Schließen des Fensters ab und gibt das gehaltene
 *   Item-Objekt sowie das 16x16-Mauscursor-Bitmap frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 und ein ungenutztes Flag entgegen und gibt p1 zurück.
 * - Wichtige Variablen: Freigegeben werden p1->item und das Rasterbild p1->gfx.
 === Ende Beschreibung === */
Deal *f_0508f0(Deal *p1, int p_unused2)
{
    operator delete(p1->item);
    int gfx = p1->gfx;
    if (gfx) operator delete(((char *)(((RivaRasterImage*)(gfx))->f_0fad20( 0))));
    return p1;
}

//@ f_050920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den Zeiger auf den Ursprungscontainer (p1->p4) des aktuell am Mauszeiger gehaltenen
 *   Gegenstands zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und gibt p1->p4 als int zurück.
 * - Wichtige Variablen: Das Feld p1->p4 gibt an, aus welchem Inventar der gehaltene Gegenstand stammt.
 === Ende Beschreibung === */
int f_050920(Deal *p1)
{
    return p1->p4;
}

//@ f_050930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Herkunftsart (p1->kind: 0 = Heldeninventar, 1 = Zweitcontainer/Truhe, -1 = leer)
 *   des gehaltenen Gegenstands zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und gibt p1->kind als short zurück.
 * - Wichtige Variablen: Ausgelesen wird das Feld p1->kind an Offset +0x14.
 === Ende Beschreibung === */
short f_050930(Deal *p1)
{
    return p1->kind;
}

//@ f_050940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den ursprünglichen Slot-Index (p1->idx) des aktuell aufgenommenen Gegenstands zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und gibt p1->idx als short zurück.
 * - Wichtige Variablen: Ausgelesen wird das Feld p1->idx an Offset +0x16.
 === Ende Beschreibung === */
short f_050940(Deal *p1)
{
    return p1->idx;
}

//@ f_050950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Stückzahl (cnt) des aktuell am Mauszeiger gehaltenen Gegenstands zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und gibt p1->item->cnt als short zurück.
 * - Wichtige Variablen: Gelesen wird das erste short-Feld cnt von p1->item.
 === Ende Beschreibung === */
short f_050950(Deal *p1)
{
    return p1->item->cnt;
}

//@ f_050960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Gegenstands-ID (id) des aktuell am Mauszeiger gehaltenen Gegenstands zurück (0, wenn
 *   kein Gegenstand gehalten wird).
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und gibt p1->item->id als short zurück.
 * - Wichtige Variablen: Gelesen wird das Feld id (+2) von p1->item.
 === Ende Beschreibung === */
short f_050960(Deal *p1)
{
    return p1->item->id;
}

//@ f_050970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zeiger auf das aktuell aktive Heldeninventar (p1->inv) bei einem Heldenwechsel neu.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie den neuen Inventarzeiger p2 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Aktualisiert wird das Feld p1->inv (+4).
 === Ende Beschreibung === */
void f_050970(Deal *p1, int p2)
{
    p1->inv = p2;
}

//@ f_050980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet einen Klick auf den Helden-Inventarslot p2: Je nachdem, ob bereits ein Gegenstand
 *   am Mauszeiger hängt und ob der Zielslot belegt oder stapelbar ist, wird der Gegenstand aufgenommen,
 *   gestapelt (f_026150), in einen leeren Slot abgelegt (f_0512b0) oder mit dem Inhalt des Zielslots getauscht
 *   (f_051350).
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie den angeklickten Inventarslot p2 (short) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Vor dem Ablegen prüft die Funktion, ob ein persönlicher/magisch gebundener Gegenstand
 *   (d.b[9] > 0) einem NPC (f_042350 == 3) gegeben werden soll, und verweigert dies mit der Meldung 0x501003a.
 === Ende Beschreibung === */
void f_050980(Deal *p1, short p2)
{
    struct H { static inline void chk(Deal *p1) { if (p1->item->cnt == 0) p1->item->id = 0; } static inline Item *take(Deal *p1, short p2) { Item *r = 0; if (f_026a70(p1->inv, p2) != 0) { short a = f_026a20(p1->inv, p2); r = f_026a80(p1->inv, p2); if (f_0264d0(p1->inv, p2) == a) { delete r; r = new (mark(d_1a141c, 0x207)) Item; } } return r; } static inline void set(Deal *p1, int p2, short p3, short p4) { p1->p4 = p2; p1->kind = p3; p1->idx = p4; } }; short sVar2 = f_026a20(p1->inv, p2);
    short sVar3 = f_026a70(p1->inv, (short)p2);
    int iVar5 = f_025c40(p1->inv);
    if (p1->item->cnt > 0 && p1->item->d.b[9] > 0 && iVar5 != 0 && (signed char)((int)(f_042350((struct hero *)(iVar5)))) == 3) {
        f_0bf730(d_1c2c64, 0x501003a);
        return;
    }
    if (p1->item->id == sVar3 && sVar2 < 99 && d_1c2c40[p1->item->id]->f_0a7950() == 1) {
        p1->item->cnt = f_026150(p1->inv, p1->item, (short)p2, 1, 1, 0);
        H::chk(p1);
    } else if (sVar2 == 0) {
        f_0512b0(p1, p1->inv, p1->item, p2, 1, 1, 0);
    } else if (p1->item->cnt == 0) {
        delete p1->item;
        p1->item = H::take(p1, p2); H::set(p1, p1->inv, 0, p2);
    } else {
        f_051350(p1, (short)p2);
    }
    f_050ea0(p1, 0);
    f_026600(p1->inv, p1->item->id);
    f_0268c0(p1->inv);
}

//@ f_050b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet einen Klick auf den Slot p2 des Zweitcontainers (z. B. Truhe oder Beutelager):
 *   Stapelbare gleiche Gegenstände werden zusammengefügt, andernfalls wird mit dem Truhenslot getauscht
 *   (f_0515f0) oder bei p2 == -1 der Gegenstand ans Ende des Containers angehängt (f_051780).
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie den Container-Slotindex p2 (short) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Hilfsfunktion can_stack prüft, ob die Item-ID übereinstimmt, die Stückzahl < 99 ist
 *   und der Gegenstand stapelbar ist oder identische Zustandsdaten d.b[4..0x1a] besitzt.
 === Ende Beschreibung === */
void f_050b40(Deal *p1, short p2)
{
    struct H {
        static inline int can_stack(Deal *p1, short p2) {
            short s = f_11c620(p1->src, p2);
            short c = f_11c5f0(p1->src, p2);
            int r = 0;
            Dat *d = f_11c650(p1->src, p2);
            if (p1->item->id == s && c < 99) {
                if (d_1c2c40[s]->f_0a7950() == 1 || EQ(memcmp((char *)d + 4, &p1->item->d.b[4], 0x17), 0)) r = 1;
            }
            return r;
        }
        static inline void stack(Deal *p1, short p2) {
            short t = f_11c5f0(p1->src, p2);
            short m = p1->item->cnt < (99 - t) ? p1->item->cnt : (99 - t);
            f_11c6e0(p1->src, p2, m);
            p1->item->cnt -= m;
            if (p1->item->cnt == 0) p1->item->id = 0;
        }
    };
    if (p2 != -1) {
        if (H::can_stack(p1, p2) == 1) {
            H::stack(p1, p2);
        } else {
            f_0515f0(p1, p2);
        }
    } else {
        f_051780(p1);
    }
    f_050ea0(p1, 0);
    f_026600(p1->inv, p1->item->id);
    f_0268c0(p1->inv);
}

//@ f_050c70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt einen am Mauszeiger gehaltenen Gegenstand beim Abbrechen oder Schließen des Fensters
 *   automatisch wieder an seinen Ursprungsort (Heldeninventar p1->p4 oder Zweitcontainer p1->src) zurück, damit
 *   kein Gegenstand verloren geht.
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Je nach p1->kind (0 = Heldeninventar, 1 = Truhenslot) wird versucht, den Gegenstand
 *   wieder in den alten Slot p1->idx oder über f_025c50 / f_11c350 in einen freien Platz des jeweiligen
 *   Containers einzufügen.
 === Ende Beschreibung === */
void f_050c70(Deal *p1)
{
    if (!p1->kind) {
        short cnt0 = p1->item->cnt;
        int src = p1->p4;
        if (f_026a70(src, p1->idx) == 0 || f_026a70(src, p1->idx) == p1->item->id) {
            f_0512b0(p1, src, p1->item, p1->idx, 0, 0, 0);
        } else {
            Deal *self = p1;
            int owner = src;
            short a;
            do {
                a = self->item->cnt;
                self->item->cnt = f_025c50(owner, self->item);
            } while (a != self->item->cnt);
            if (self->item->cnt == 0) {
                self->item->id = 0;
                self->kind = -1;
                self->idx = -1;
                self->p4 = 0;
            }
            f_050ea0(self, 0);
            f_026600(self->inv, self->item->id);
            f_0268c0(self->inv);
            f_025cd0(src);
        }
        if (p1->item->cnt == cnt0) {
            if (f_025c50(src, p1->item) != 0) goto L1;
            f_025cd0(src);
        }
        p1->p4 = 0;
        p1->kind = -1;
        p1->idx = -1;
        delete p1->item;
        goto L2;
L1:
        f_11c350(p1->src, p1->item);
        p1->p4 = p1->src;
        p1->idx = -1;
    } else {
        if (p1->kind == (short)1) {
            if (p1->idx < 0) p1->idx = 0;
            f_11c460(p1->src, p1->idx, p1->item);
        } else if (p1->item->id != 0) {
            f_11c350(p1->src, p1->item);
        }
        p1->p4 = 0;
        p1->kind = -1;
        p1->idx = -1;
        p1 = ((int)p1 & 0) ? 0 : p1; // Haelt die Registerfolge am Zweigende
    }
L2:
    p1->item = new (mark(d_1a141c, 0x13c)) Item;
    f_050ea0(p1, 0);
    f_026600(p1->inv, p1->item->id);
    f_0268c0(p1->inv);
}

//@ f_050e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übergibt den aktuell am Mauszeiger gehaltenen Gegenstand (auch mehrteilige Stapel) automatisch
 *   in freie Slots des angegebenen Heldeninventars p2 und aktualisiert anschließend die Anzeige.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie den Ziel-Inventarzeiger p2 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Eine Schleife ruft f_025c50(p2, p1->item) auf, solange noch Stücke untergebracht werden
 *   können, und setzt p1->item bei cnt == 0 auf leer zurück.
 === Ende Beschreibung === */
void f_050e30(Deal *p1, int p2)
{
    short a;
    do {
        a = p1->item->cnt;
        p1->item->cnt = f_025c50(p2, p1->item);
    } while (a != p1->item->cnt);
    if (p1->item->cnt == 0) {
        p1->item->id = 0;
        p1->kind = -1;
        p1->idx = -1;
        p1->p4 = 0;
    }
    f_050ea0(p1, 0);
    f_026600(p1->inv, p1->item->id);
    f_0268c0(p1->inv);
}

//@ f_050ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das Beschreibungsfeld oben im Transferfenster neu und gibt darin den Namen des
 *   aktuell gehaltenen (oder übergebenen) Gegenstands sowie bei nicht stapelbaren Waffen das zugehörige
 *   Kampftalent aus, wobei überlange Texte passend auf die Feldbreite gekürzt werden.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie optional eine Item-Definitionsadresse p2 (bei 0 wird die
 *   Definition von p1->item->id verwendet) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0a7840 wird der Gegenstandsname nach d_1c21b4 geholt, in einer Schleife mittels
 *   f_0e9690 auf maximal w - 4 Pixel gekürzt und bei (0x8c, 1) ausgegeben.
 === Ende Beschreibung === */
void f_050ea0(Deal *p1, int p2)
{
    struct Lock {
        int r;
        void init() { if (f_0d3860() == 1) { int k = 1; f_0d2710(); r = k; } else r = 0; }
        ~Lock() { if (r == 1) f_0d26e0(); }
    } lock;
    int w, h;
    f_050580(d_1c2be0, p1->p6, 8, &w, &h);
    int t = (int)new (mark(d_1a141c, 0x176)) G9;
    int gfx = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( (short)w, (short)h))) : t;
    if (p2 == 0) p2 = (int)d_1c2c40[p1->item->id];
    f_04fef0(d_1c2be0, p1->p6, ((int)(((RivaRasterImage*)(gfx))->f_0fb0b0())), 0, 8, 0, 0x140);
    f_0a7840((RivaItemDefinition *)(p2),(char *)( d_1c21b4), 1);
    if (((RivaItemDefinition*)(p2))->f_0a7990() == 1 && ((RivaItemDefinition*)(p2))->f_0a7950() == 0) {
        f_0e9300(d_1c38b0, d_1c21b4, 0x200001b5);
        f_0e9300(d_1c38b0, d_1c21b4, (signed char)((int)(((RivaItemDefinition*)(p2))->f_0a78b0())) + 0x2000005c);
    }
    int limit = w - 4;
    while (f_0e9690(d_1c38b0, d_1c21b4) > (short)limit)
        d_1c21b4[(short)(strlen(d_1c21b4) - 1)] = 0;
    lock.init();
    ((RivaRasterImage*)(gfx))->f_0fade0((void *)( d_1a34e0), 0x8a, 1);
    if (((short)(((RivaItemDefinition*)(p2))->f_0a78e0())) > 0) {
        f_05e320(d_1c38b0, 0xff, -1);
        f_0e9660(d_1c38b0, d_1c21b4, 0x8c, 1);
    }
    if (gfx) delete ((char *)(((RivaRasterImage*)(gfx))->f_0fad20( 0)));
}

//@ f_051060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt aus dem Icon des aktuell am Mauszeiger gehaltenen Gegenstands (und bei Stapeln cnt > 1
 *   aus der rechts unten eingezeichneten Stückzahl) ein 16x16-Mauscursor-Bild und setzt dieses als aktiven
 *   Hardware-/Software-Mauszeiger; ist kein Gegenstand aufgenommen, wird wieder der Standard-Pfeilcursor
 *   aktiviert.
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Icon wird aus dem Archiv 0x50002 in p1->gfx geladen, bei cnt > 1 die Zahl mit
 *   f_148518 (itoa) formatiert und eingezeichnet und schließlich f_0d3080 zum Setzen des Mauszeigers aufgerufen.
 === Ende Beschreibung === */
void f_051060(Deal *p1)
{
int image670(int);
#pragma aux image670 "f_0fb0b0"
void mouse670(int,int,int,int,int,int);
#pragma aux mouse670 "f_0d3080"
    short b; short a; int s; short cnt;
    if (d_1bf4ef == 0) {
        short id = p1->item->id;
        if (id != 0) {
            char *buf = new (mark(d_1a141c, 0x1bb)) char[0x1400];
            RivaItemDefinition **table = d_1c2c40;
            cnt = p1->item->cnt;
            f_04fef0(d_1c2be0, 0x50002, ((int)(((RivaRasterImage*)(p1->gfx))->f_0fb0b0())), 0, table[id]->f_0a7800(), 0, 0x140);
            ((RivaRasterImage*)(p1->gfx))->f_0fade0((void *)( (int)buf), 0, 0);
            if (cnt > 1) {
                a = 0; b = 0;
                s = f_05dec0(d_1c3068);
                f_05ded0(d_1c3068, (int)buf);
                f_148518(cnt, d_1c21b4, 10);
                int w = ((int (*)(void *, void *))f_0e9690)(d_1c38b0, d_1c21b4);
                f_05e360(d_1c38b0, &a, &b);
                f_05e320(d_1c38b0, 0xff, -1);
                f_0e9660(d_1c38b0, d_1c21b4, (short)(0x10 - w), 9);
                f_05e320(d_1c38b0, (short)a, (short)b);
                // Haelt die Registerbreiten und Lebensdauern bis nach f_05e320
                (void)(signed char)(int)table;
                (void)(signed char)id;
                (void)(short)(int)p1;
                f_05ded0(d_1c3068, s);
            }
            ((RivaRasterImage*)(p1->gfx))->f_0fafb0((void *)( (int)buf), 0, 0);
            delete buf;
            mouse670(image670(p1->gfx),0x10,0x10,8,8,1);
        } else {
            f_0d2f90(0, 1);
        }
    }
}

//@ f_051200
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die drei Herkunftsfelder (p4, kind, idx) des Transfer-Objekts p1 auf die übergebenen
 *   Werte.
 * - Eingaben und Rückgabe: Die Funktion erhält p1, den Containerzeiger p2, die Herkunftsart p3 sowie den
 *   Slotindex p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beschrieben werden p1->p4, p1->kind und p1->idx.
 === Ende Beschreibung === */
void f_051200(Deal *p1, int p2, int p3, int p4)
{
    p1->p4 = p2;
    p1->kind = (short)p3;
    p1->idx = (short)p4;
}

//@ f_051210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Nimmt einen Gegenstand aus dem Slot p2 des Heldeninventars p1->inv auf und gibt ihn als neu
 *   alloziertes Item-Objekt zurück (oder liefert ein leeres Item, falls das Ablegen aus
 *   Rüstungs-/Traglastgründen verweigert wurde).
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und den Slotindex p2 und gibt einen Zeiger Item * auf das
 *   entnommene Gegenstandsobjekt zurück.
 * - Wichtige Variablen: Über f_026a80 wird der Gegenstand aus dem Inventarslot kopiert und mit f_0264d0 aus dem
 *   Slot entfernt.
 === Ende Beschreibung === */
Item *f_051210(Deal *p1, int p2)
{
    Item *r = 0;
    int t_362 = f_026a70(p1->inv, (short)p2);
    if (t_362 != 0) {
        short a = f_026a20(p1->inv, (short)p2);
        r = f_026a80(p1->inv, (short)p2);
        if (f_0264d0(p1->inv, (short)p2) == a) {
            delete r;
            r = new (mark(d_1a141c, 0x207)) Item;
        }
    }
    return r;
}

//@ f_0512b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt den Gegenstand p3 in den Slot p4 des Heldeninventars p2 ab (wobei zwischen stapelbaren
 *   und einzelnen Gegenständen unterschieden wird) und aktualisiert die verbleibende Stückzahl p3->cnt.
 * - Eingaben und Rückgabe: Die Funktion erhält p1, das Zielinventar p2, das Item-Objekt p3, den Zielslot p4
 *   sowie drei Steuerflags p5, p6, p7 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Je nach Stapelbarkeit (f_0a7950) und Belegung des Slots (f_026a20) wird f_026150,
 *   f_026280 oder f_025f90 aufgerufen; sinkt p1->item->cnt auf 0, wird p1->item->id = 0 gesetzt.
 === Ende Beschreibung === */
void f_0512b0(Deal *p1, int p2, Item *p3, int p4, int p5, int p6, int p7)
{
    if (d_1c2c40[p3->id]->f_0a7950() == 1) {
        if (((short (*)(int,int))f_026a20)(p2, (short)p4) != 0)
            p3->cnt = f_026150(p2, p3, (short)p4, p5, p6, p7);
        else
            p3->cnt = f_026280(p2, p3, (short)p4, p5, p6, p7);
    } else {
        p3->cnt = f_025f90(p2, p3, (short)p4, p6, p7);
    }
    if (p1->item->cnt == 0) p1->item->id = 0;
}

//@ f_051350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Tauscht einen einzelnen am Mauszeiger gehaltenen Gegenstand (cnt == 1) mit dem bereits im
 *   Helden-Inventarslot p2 liegenden Gegenstand aus; schlägt das Einsetzen ins Inventar fehl, wird der alte
 *   Slotinhalt wiederhergestellt.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 sowie den Zielslot p2 (short) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Zuerst wird der bestehende Slotinhalt r entnommen, dann der gehaltene Gegenstand über
 *   f_0512b0 eingesetzt; bleibt p1->item->cnt > 0 (Einsetzen nicht möglich), wird r zurückgelegt und die
 *   Sicherungskopie n behalten.
 === Ende Beschreibung === */
void f_051350(Deal *p1, short p2)
{
    if (p1->item->cnt == 1) {
        Item *q = 0;
        {
            int t_362 = f_026a70(p1->inv, (short)p2);
            if (t_362 != 0) {
                short a = f_026a20(p1->inv, (short)p2);
                q = f_026a80(p1->inv, (short)p2);
                if (f_0264d0(p1->inv, (short)p2) == a) {
                    delete q;
                    q = new (mark(d_1a141c, 0x207)) Item;
                }
            }
        }
        Item *r = q;
        if (r != 0 && r->cnt != 0 && r->id != 0) {
            Item *n = new (mark(d_1a141c, 0x24a)) Item(p1->item->cnt, p1->item->id, p1->item->d);
            short k = (short)p2;
            f_0512b0(p1, p1->inv, p1->item, k, 0, 1, 0);
            if (p1->item->cnt > 0) {
                f_0512b0(p1, p1->inv, r, k, 0, 0, 1);
                delete p1->item;
                p1->item = n;
                delete r;
            } else {
                delete p1->item;
                p1->item = r;
                delete n;
            }
        }
    }
}
//@ f_0514e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Gegenstands-ID p1->item->id auf 0, sobald die Stückzahl p1->item->cnt auf 0 gefallen
 *   ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Geprüft und bereinigt wird p1->item.
 === Ende Beschreibung === */
void f_0514e0(Deal *p1)
{
    if (p1->item->cnt == 0) p1->item->id = 0;
}

//@ f_051500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der aktuell am Mauszeiger gehaltene Gegenstand auf den Slot p2 des Zweitcontainers
 *   (p1->src) gestapelt werden kann.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und den Container-Slot p2 (short) und gibt als int den Wert 1
 *   zurück, wenn beide Gegenstände dieselbe ID haben, die Stückzahl im Slot < 99 ist und sie stapelbar bzw.
 *   zustandsgleich sind, sonst 0.
 * - Wichtige Variablen: Verglichen werden f_11c620(p1->src, p2) (Slot-ID), f_11c5f0 (Slot-Menge) und bei Bedarf
 *   per memcmp die 0x17 Zustandsbytes ab Offset +4.
 === Ende Beschreibung === */
int f_051500(Deal *p1, short p2)
{
    short s = f_11c620(p1->src, p2); short c = f_11c5f0(p1->src, p2); int r = 0; Dat *d = f_11c650(p1->src, p2); if (p1->item->id == s && c < 99) { if (d_1c2c40[s]->f_0a7950() == 1 || EQ(memcmp((char *)d + 4, &p1->item->d.b[4], 0x17), 0)) r = 1;
    }
    return r;
}

//@ f_051590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stapelt so viele Exemplare wie möglich (bis zur Obergrenze von 99 Stück) vom
 *   Mauszeiger-Gegenstand p1->item auf den Slot p2 des Zweitcontainers p1->src.
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 und den Container-Slot p2 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Über f_11c6e0 wird die Menge im Container-Slot erhöht und p1->item->cnt entsprechend
 *   verringert.
 === Ende Beschreibung === */
void f_051590(Deal *p1, short p2)
{
    short t = f_11c5f0(p1->src, (short)p2);
    short m = p1->item->cnt < (99 - t) ? p1->item->cnt : (99 - t);
    f_11c6e0(p1->src, (short)p2, (short)m);
    p1->item->cnt -= (short)m;
    if (p1->item->cnt == 0) p1->item->id = 0;
}

//@ f_0515f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Tauscht den am Mauszeiger gehaltenen Gegenstand mit dem Eintrag an Position p2 des
 *   Zweitcontainers (p1->src) oder entnimmt einen Gegenstand aus diesem Slot, sofern der Container das
 *   Hineinlegen fremder Gegenstände nicht sperrt.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 und die Container-Position p2 (short) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Ist der Container für das Einlegen gesperrt (f_11c160(p1->src) != 0, z. B. reine
 *   Beuteansicht) und stammt der gehaltene Gegenstand nicht selbst aus dem Container (p1->kind != 1), wird die
 *   Meldung 0x21040011 ausgegeben.
 === Ende Beschreibung === */
void f_0515f0(Deal *p1, short p2)
{
    short pos;
    pos = p2;
    if (f_11c160(*(volatile int *)&p1->src) != 0 && p1->item->id > 0 && p1->kind != (short)1) {
        f_0bf730(d_1c2c64, 0x21040011);
    } else {
        int sv = f_11c160(p1->src);
        f_11c170(p1->src, 0);
        Item *r;
        int t_457 = f_11c620(p1->src, pos);
        if (t_457 != (short)0) {
            r = new (mark(d_1a141c, 0x2b7)) Item(f_11c5f0(p1->src, pos), f_11c620(p1->src, pos), *f_11c650(p1->src, pos));
            f_11c580(p1->src, pos);
        } else {
            r = new (mark(d_1a141c, 0x2c0)) Item;
        }
        Item *c = p1->item;
        if (c->id != (short)0) f_11c460(p1->src, pos, c);
        else delete c;
        p1->kind = 1;
        p1->idx = pos;
        p1->item = r;
        f_11c170(p1->src, sv);
    }
}

//@ f_051780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt den aktuell am Mauszeiger gehaltenen Gegenstand als neuen Eintrag an das Ende des
 *   Zweitcontainers p1->src an (sofern dieser nicht gegen das Einlegen gesperrt ist).
 * - Eingaben und Rückgabe: Die Funktion nimmt p1 entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_11c350(p1->src, p1->item) wird der Gegenstand eingetragen; hat sich die
 *   Eintragszahl f_11c320(p1->src) erhöht, wird p1->item durch ein neues leeres Item ersetzt.
 === Ende Beschreibung === */
void f_051780(Deal *p1)
{
    if (p1->item->id > 0) {
        short s1 = f_11c320(p1->src);
        if (f_11c160(p1->src) != 0 && p1->kind != (short)1) {
            f_0bf730(d_1c2c64, 0x21040011);
            return;
        }
        int t = f_11c160(p1->src);
        f_11c170(p1->src, 0);
        f_11c350(p1->src, p1->item);
        f_11c170(p1->src, t);
        if (s1 < f_11c320(p1->src)) {
            p1->p4 = 0;
            p1->kind = -1;
            p1->idx = -1;
            p1->item = new (mark(d_1a141c, 0x2ff)) Item;
        }
    }
}
