/* === Beschreibung (Katalog) ===
 * Einheit fi_end (0x071880 - 0x071BD0)
 *
 * Überblick
 * Die Einheit fi_end verarbeitet die Beute- und Geldauswertung am Ende eines gewonnenen Kampfes
 * (FiEnd::f_071880): Sie sammelt alle fallengelassenen Waffen, Rüstungen, Stapelgegenstände und Beuteobjekte der
 * besiegten Gegner ein, öffnet den Beute-Verteilungsbildschirm und zahlt gefundene Münzen an die Gruppe aus.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
// I9: aus fi_end_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// fi_end.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x071880-0x071BD0. Stellt am Kampfende die Beuteliste zusammen und zeigt sie an.
#define fi_end_file "p:\\riva\\source\\cpp\\fi_end.cpp"   // 0x1A1C38
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
void *f_014540(long size, const char *file, int line);   // 0x014540
struct Rec { short t; short a; short b; char pad[2]; char fl; char rest[22]; };
struct Unit { unsigned char f_0729c0(); char f_0cf910(); char f_0d00a0();
              signed char f_0cffb0(); signed char f_0cfda0(); char data[0x73]; };
struct Obj { Obj(Rec *buf, int z); ~Obj(); char data[0x10]; };
struct Obj2 { Obj2(Obj *o, int z); ~Obj2(); void f_0a8be0(); char data[0x5a]; };
struct Slot { short a; short b[4]; char pad[5]; };
struct Q { int a; int b; };
struct Big { Big(char *a, char *b, char *c); ~Big(); char p0[0x10]; Q *p10; char p14[0x28]; };
struct Msg { void f_0bf730(long code); }; extern Msg d_1c2c64;
struct Tgt { void f_0db820(int v); }; extern Tgt *d_1c0004;
struct Cnt { void f_040370(int v); }; extern Cnt d_1c27a8;
struct Thing { char x; };
extern char d_1c3498[], d_1c349c[], d_1c3870[];
extern Unit *d_1c2ed4;

int f_071e90(unsigned v, short *a, short *b);

int f_133fe0(char *a, Cnt *b);
void f_0d26e0();
void f_0d2710();

struct FiEnd {
    char p0[0x1ab];
    short w1ab[1];
    char pad1[0xd41];
    Slot slots[20];
    char pad2[0x17];
    short w1031[30];
    short h106d, t106f, o1071;
    void f_071880();
};

//@ f_071880
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt nach Kampfende in einem temporären Puffer buf (160 Einträge zu je 31 Bytes) die
 *   gesamte Kampfbeute zusammen: Übernimmt zunächst die auf dem Schlachtfeld liegenden Gegenstände aus w1ab,
 *   danach für jeden der bis zu 20 Gegnerplätze (d_1c2ed4[0..19]), sofern der Gegner besiegt und nicht geflohen
 *   ist, dessen Hauptwaffe slots[i].a (inklusive Kaputt-Flag aus f_0cfda0) sowie bis zu vier Beutegegenstände
 *   slots[i].b[0..3] (mit Stapelgröße 10 für stapelbare Gegenstände laut f_0a7950) und schließlich die bis zu 30
 *   Zusatzbeute-Einträge aus w1031 (mit Sonderanzahl 50 für Gegenstand 0x17e). Ist mindestens ein Gegenstand
 *   vorhanden (count != 0), wird das Beutefenster (Obj und Obj2::f_0a8be0) angezeigt; anschließend wird das
 *   erbeutete Geld (h106d * 100 + t106f * 10 + o1071 Heller) per Textmeldung 0x1010010 verkündet und dem
 *   Gruppenvermögen über d_1c0004->f_0db820(money) gutgeschrieben.
 * - Eingaben:
 *   - this (Impliziter Zeiger auf die Kampfsteuerungsstruktur FiEnd).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - buf (Dynamisch reserviertes Array von 31-Byte-Beuteeinträgen Rec).
 *   - count (Laufende Anzahl der gesammelten Beutepositionen).
 *   - u (Zeiger auf den jeweiligen Gegner-Datensatz in d_1c2ed4).
 *   - money (Gesamtsumme des erbeuteten Geldes in Hellern, berechnet aus Dukaten h106d, Silbertalern t106f und
 *     Hellern o1071).
 === Ende Beschreibung === */
void FiEnd::f_071880()
{
    Rec *buf = 0;
    short b, a;
    short i, count, j;
    buf = (Rec *)f_014540(0x1360, fi_end_file, 0x206);
    count = 0;
    i = 0;
    while (w1ab[i] != (short)0) {
        buf[count].t = 1;
        buf[count].a = w1ab[i];
        buf[count].b = buf[count].a;
        ++count;
        ++i;
    }
    for (i = 0; i < (short)20; ++i) {
        int offset = i;
        offset *= 0x73;
        Unit *u = (Unit *)((char *)d_1c2ed4 + offset);
        int state = f_071e90((unsigned char)(u->f_0729c0() + 10), &a, &b);
        char on = u->f_0cf910();
        if ((signed char)(on & 0xff) && !u->f_0d00a0() &&
            (state == 1 || (state == 0 && (int)u->f_0cffb0() == 0))) {
            if (slots[i].a != (short)0) {
                int dest = count;
                dest *= 31;
                Rec *r = (Rec *)((char *)buf + dest);
                r->t = 1;
                r->a = slots[i].a;
                r->b = r->a;
                if ((int)u->f_0cfda0() == 1) r->fl |= 1;
                ++count;
            }
            for (j = 0; j < (short)4; ++j) {
                if (slots[i].b[j] != (short)0) {
                    short index = slots[i].b[j];
                    short type = ((RivaItemDefinition*)((*(Thing ***)&d_1c2c40)[index]))->f_0a7950() ? 10 : 1;
                    buf[count].t = type;
                    buf[count].a = slots[i].b[j];
                    buf[count].b = buf[count].a;
                    ++count;
                }
            }
        }
    }
    for (i = 0; i < (short)30; ++i) {
        if (w1031[i] != (short)0) {
            if ((int)w1031[i] == 0x17e) buf[count].t = 50;
            else {
                buf[count].t = 1;
                Tgt *e1 = d_1c0004; d_1c0004 = e1; Unit *e2 = d_1c2ed4; d_1c2ed4 = e2; Thing **e3 = (*(Thing ***)&d_1c2c40); (*(Thing ***)&d_1c2c40) = e3; // haelt die Registerzuteilung wie im Original
            }
            buf[count].a = w1031[i];
            buf[count].b = buf[count].a;
            ++count;
            Tgt *d1 = d_1c0004; d_1c0004 = d1; Unit *d2 = d_1c2ed4; d_1c2ed4 = d2; Thing **d3 = (*(Thing ***)&d_1c2c40); (*(Thing ***)&d_1c2c40) = d3; // haelt die Registerzuteilung wie im Original
        }
    }
    if ((int)count != 0) {
        Obj *obj = new(mark(fi_end_file, 0x24d)) Obj(buf, 0);
        operator delete(buf);
        f_0d26e0();
        Obj2 *view = new(mark(fi_end_file, 0x252)) Obj2(obj, 0);
        view->f_0a8be0();
        delete view;
        delete obj;
        f_0d2710();
        Tgt *h1 = d_1c0004; d_1c0004 = h1; Unit *h2 = d_1c2ed4; d_1c2ed4 = h2; // haelt die Registerzuteilung wie im Original
    } else {
        operator delete(buf);
        Tgt *g1 = d_1c0004; d_1c0004 = g1; Unit *g2 = d_1c2ed4; d_1c2ed4 = g2; // haelt die Registerzuteilung wie im Original
    }
    int money = h106d * 100;
    money += t106f * 10;
    money += o1071;
    if (money > 0) {
        Big text(d_1c349c, d_1c3870, d_1c3498);
        d_1c27a8.f_040370(money);
        text.p10->b = f_133fe0(d_1c3498, &d_1c27a8);
        f_0d26e0();
        d_1c2c64.f_0bf730(0x1010010);
        f_0d2710();
        d_1c0004->f_0db820(money);
    }
}
