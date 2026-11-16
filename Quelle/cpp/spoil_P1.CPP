/* === Beschreibung (Katalog) ===
 * Einheit spoil (0x112df0 - 0x113770)
 *
 * Überblick
 * Diese Einheit implementiert das Beute- und Schatztruhen-System (spoil.cpp, Klasse Spoil / Beutecontainer). Sie
 * verwaltet das Laden von Beutelisten aus den Spieldateien, das Aufnehmen und Ablegen von Gegenständen,
 * Kräutern, Proviant und Geld durch die Heldengruppe sowie das Speichern veränderter Beutebestände im
 * Spielstand.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 11/15 gleich (suche.py 25.10.2026, Basis spoil_P1.CPP)
// spoil.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x112DF0-0x113770
#include <string.h>
#define MKO(L) int t_o = (int)new (mark(d_1a7a58, L)) Rec16; if (t_o) t_o = f_11c760(t_o, 0x60003); int o = t_o;
#define EQ(a,b) (((a)==(b))?1:0)
struct R27 { char b[27]; };
struct Rec10 { char b[10]; };
struct Rec16 { char b[16]; };
struct Rec5a { char b[90]; };
struct Rec1f { short a; short b; R27 r; };
struct S60 { char b[16]; int *p; char rest[40]; };
struct SD { short s0; short s2; short s4; unsigned short s6; short s8; };
int f_040370(void *p1, int p2);
void f_09a400();
int f_0a8830(int p1, int p2, int p3);
int f_0a8b40(int p1, int p2);
int f_0a8be0(int p1);
int f_0bf730(void *p1, int p2);
short f_0dbff0(int p1);
int f_0dcb60(int p1, int p2);
int f_0db820(int p1, int p2);
int f_11c160(int p1);
int f_11c170(int p1, int p2);
short f_11c320(int p1);
int f_11c350(int p1, void *p2);
int f_11c580(int p1, int p2);
int f_11c5f0(int p1, int p2);
short f_11c620(int p1, int p2);
int f_11c680(int p1, int p2, int p3);
int f_11c760(int p1, int p2);
int f_11c7b0(int p1, int p2);
int f_11c8a0(int p1, int p2);
int f_11c980(int p1, int p2);
int f_11caf0(int p1);
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(void *p1, void *p2);





extern const char d_1a7a58[];
extern R27 d_1c090c;
extern int d_1c0004;

extern short d_1c2198;
extern char d_1c27a8[];
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
struct Spoil {
    int n; SD *d; int pad; int c; int e;
    Spoil *f_112df0(short sz, int p3, int p4);
    Spoil *f_112e70(int fl);
    void f_112ec0();
    void f_112fd0();
    void f_1130a0();
    void f_1130d0();
    void f_113110();
    int f_1131b0();
    short f_113240(short p2, int p3);
    int f_113340(int p2, int p3, int p4);
    short f_1134d0(int p2);
    short f_113500(short p2);
    int f_1135c0();
    void f_113640();
    void f_1136d0(int p2, short *p3, short *p4);
};
//@ f_112df0
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor eines Beutecontainers (Spoil), der den zugehörigen Gegenstandsbestand anhand einer
 *   Beute-ID lädt und optional bereits im Spielstand vermerkte Geldbeträge und Änderungen übernimmt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beute-Objekts, in p2 die Beute-ID, in p3
 *   ein Flag für einmalige/persistente Beutebehälter und in p4 einen optionalen Zusatzparameter.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
Spoil *Spoil::f_112df0(short sz, int p3, int p4) {
    c = p3;
    e = p4;
    n = sz * 10;
    d = (SD *)new (mark(d_1a7a58, 0x3b)) Rec10;
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x40060002, 0x200);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( n, 0);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( d), 10)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    return this;
}
//@ f_112e70
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor eines Beutecontainers, der veränderte Beutebestände zurückschreibt, das interne
 *   Bestands-Objekt (StockCon) freigibt und bei gesetztem Flag den Speicher des Containers selbst löscht.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beute-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
Spoil * Spoil::f_112e70(int fl) {
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x40060002, 0x202);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( n, 0);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( d), 10)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    operator delete(d);
    return this;
}
//@ f_112ec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den grafischen Beute-Dialog, in dem der Spieler Münzen, Proviantpakete, Kräuter und normale
 *   Gegenstände aus dem Beutecontainer entnehmen oder zwischen den Gruppenmitgliedern verteilen kann.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beutecontainers.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn nach dem Schließen des Dialogs noch Gegenstände oder Geld im
 *   Container verbleiben, andernfalls 0.
 === Ende Beschreibung === */
void Spoil::f_112ec0() {
    S60 s;
    SD *q0 = d;
    int x = ((volatile SD *)q0)->s2; // haelt das erneute Lesen von q0->s2 nach der Nullpruefung wie im Original
    if (x) {
        f_0bf730(d_1c2c64, q0->s2 + 0x6050002);
        d->s2 = 0;
    }
    f_112fd0();
    SD *q = d;
    if (q->s4 != 0) {
        short v = f_0dbff0(d_1c0004);
        f_0dcb60(d_1c0004, (short)(v * q->s4));
        d->s4 = 0;
    }
    f_09a400();
    if (d->s6 != 0) {
        f_125400(&s, d_1c349c, d_1c3870, d_1c3498);
        f_040370(d_1c27a8, d->s6);
        s.p[1] = f_133fe0(d_1c3498, d_1c27a8);
        f_0bf730(d_1c2c64, 0x6050001);
        f_0db820(d_1c0004, d->s6);
        d->s6 = 0;
        f_1254a0(&s, 0);
    }
    d_1c2198 = 1;
}
//@ f_112fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet die zur Beuteliste d->s8 gehörige Bestandsdatei (0x60003) über ein temporäres
 *   Rec16-Archivobjekt (f_11c760, f_11c8a0), startet das grafische Beuteverteilungsfenster (f_0a8830, f_0a8be0)
 *   für die Gegenstandsliste list und speichert anschließend den aktualisierten Beutebestand über f_11c980(o,
 *   d->s8) zurück.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: o (temporäres Bestandsarchiv-Objekt), list (Zeiger auf die Gegenstandsliste), p
 *   (Beutefenster-Objekt Rec5a).
 === Ende Beschreibung === */
void Spoil::f_112fd0() {
    Rec16 *q = new (mark(d_1a7a58, 0x71)) Rec16;
    int o = q ? f_11c760((int)q, 0x60003) : (int)q;
    f_11c8a0(o, d->s8);
    int list = f_11caf0(o);
    if (list != 0) f_11c170(list, c);
    Rec5a *r = new (mark(d_1a7a58, 0x86)) Rec5a;
    int p = r ? f_0a8830((int)r, list, (e == 0)) : (int)r;
    f_0a8be0(p);
    if (p) operator delete((void *)f_0a8b40(p, 0));
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
//@ f_1130a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob im Beutedatensatz d ein Meldungs-Index d->s2 != 0 hinterlegt ist, zeigt die zugehörige
 *   Textmeldung d->s2 + 0x6050002 über f_0bf730 an und setzt d->s2 danach auf 0 zurück.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d->s2 (Meldungs-Offset im Beutedatensatz).
 === Ende Beschreibung === */
void Spoil::f_1130a0() {
    SD *q = d;
    int n = q->s2;
    if (n) {
        f_0bf730(d_1c2c64, *(volatile short *)&q->s2 + 0x6050002); // haelt das erneute Lesen von q->s2 nach der Nullpruefung wie im Original
        d->s2 = 0;
    }
}
//@ f_1130d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Vergibt bei d->s4 != 0 die im Beutecontainer hinterlegten Abenteuerpunkte (f_0dbff0(d_1c0004) *
 *   d->s4) über f_0dcb60 an die Heldengruppe und setzt d->s4 anschließend auf 0.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d->s4 (AP-Multiplikator im Beutedatensatz), v (Gruppenfaktor aus f_0dbff0).
 === Ende Beschreibung === */
void Spoil::f_1130d0() {
    SD *q = d;
    if (q->s4 != 0) {
        short v = f_0dbff0(d_1c0004);
        f_0dcb60(d_1c0004, (short)(v * q->s4));
        d->s4 = 0;
    }
}
//@ f_113110
/* === Beschreibung (Katalog) ===
 * - Zweck: Überträgt bei d->s6 != 0 den im Beutecontainer enthaltenen Geldbetrag d->s6 an die Heldengruppe
 *   (f_0db820), formatiert den Betrag über f_040370 als Text, gibt die Fundmeldung 0x6050001 über f_0bf730 aus
 *   und setzt d->s6 auf 0.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d->s6 (Geldbetrag in Kreuzern/Hellern), s (Textkontext S60).
 === Ende Beschreibung === */
void Spoil::f_113110() {
    S60 s;
    if (d->s6 != 0) {
        f_125400(&s, d_1c349c, d_1c3870, d_1c3498);
        f_040370(d_1c27a8, d->s6);
        s.p[1] = f_133fe0(d_1c3498, d_1c27a8);
        f_0bf730(d_1c2c64, 0x6050001);
        f_0db820(d_1c0004, d->s6);
        d->s6 = 0;
        f_1254a0(&s, 0);
    }
}
//@ f_1131b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob der Beutecontainer aktuell noch mindestens einen Gegenstand oder einen Geldbetrag größer
 *   als null enthält.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beutecontainers.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn noch Beute vorhanden ist, oder 0, wenn der Container
 *   vollständig geleert wurde.
 === Ende Beschreibung === */
int Spoil::f_1131b0() {
    int res = 0;
    int o;
    Rec16 *p = new (mark(d_1a7a58, 0xd4)) Rec16;
    o = (p) ? f_11c760((int)p, 0x60003) : (int)p;
    f_11c8a0(o, d->s8);
    if (f_11c320(f_11caf0(o)) > 0) res = 1;
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return res;
}
//@ f_113240
/* === Beschreibung (Katalog) ===
 * - Zweck: Entnimmt bis zu p3 Stück des Gegenstands mit der ID p2 aus der Beuteliste d->s8: Ist die vorhandene
 *   Stückzahl have größer als p3, wird der Bestand über f_11c680 um p3 reduziert, andernfalls wird der gesamte
 *   Posten über f_11c580 aus der Liste entfernt.
 * - Eingaben: this (Spoil *), p2 (Gegenstands-ID short), p3 (gewünschte Stückzahl int).
 * - Rückgabewert: Anzahl der tatsächlich entnommenen Gegenstände (short).
 * - Wichtige Variablen: idx (gefundener Listenindex), have (vorhandene Stückzahl), ret (entnommene Menge).
 === Ende Beschreibung === */
short Spoil::f_113240(short p2, int p3) {
    short ret = 0;
    int o = (int)new (mark(d_1a7a58, 0x100)) Rec16;
    o = o ? f_11c760(o, 0x60003) : o;
    short idx = -1;
    f_11c8a0(o, d->s8);
    short k = 0;
    int list = f_11caf0(o);
    goto test;
next:
    ++k;
test:
    if (k >= f_11c320(list)) goto done;
    if (idx != -1) goto done;
    if (f_11c620(list, k) == (short)p2) idx = k;
    goto next;
done:
    {
        int i = idx;
        if (i != -1) {
            int have = f_11c5f0(list, i);
            if ((short)have > (short)p3) {
                ret = p3;
                f_11c680(list, i, (short)(have - p3));
            } else {
                ret = have;
                f_11c580(list, i);
            }
        }
    }
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return ret;
}

//@ f_113340
/* === Beschreibung (Katalog) ===
 * - Zweck: Entfernt einen Gegenstandstyp ersatzlos aus dem Beutecontainer.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beutecontainers und in p2 die
 *   Gegenstands-ID.
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Löschoperation zurück.
 === Ende Beschreibung === */
static inline Rec1f *ini1f(Rec1f *n, short a, short b, R27 r) {
    n->a = (short)a;
    n->b = (short)b;
    memcpy(&n->r, &r, 27);
    return n;
}
int Spoil::f_113340(int p2, int p3, int p4) {
    int r;
    int o = 0;
    short k;
    short i;
    int t_o = (int)new (mark(d_1a7a58, 0x147)) Rec16;
    o = t_o ? f_11c760(t_o, 0x60003) : t_o;
    f_11c8a0(o, d->s8);
    int l = f_11caf0(o);
    if (p4 == 0) {
        k = -1;
        for (i = 0; i < f_11c320(l) && k == -1; i++) {
            if (f_11c620(l, i) == (short)p2) k = i;
        }
    } else {
        k = -1;
    }
    if (k != -1) {
        r = p3;
        short v = f_11c5f0(l, k) + r;
        f_11c680(l, k, v);
    } else {
        R27 loc = d_1c090c;
        int t = (int)new (mark(d_1a7a58, 0x180)) Rec1f;
        Rec1f *n = t ? ini1f((Rec1f *)t, p3, p2, loc) : (Rec1f *)t;
        int cnt = f_11c160(l);
        f_11c170(l, 0);
        f_11c350(l, n);
        r = p3;
        f_11c170(l, cnt);
    }
    f_11c980(o, d->s8);
    if (o) {
        operator delete((void *)f_11c7b0(o, 0));
    }
    return r;
}
//@ f_1134d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Lädt einen vordefinierten Beutesatz aus der Beutedatei (0x2e0002), würfelt den zufälligen Geldbetrag
 *   zwischen Minimal- und Maximalwert aus und überträgt die enthaltenen Gegenstände in den aktuellen
 *   Beutecontainer.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Beutecontainers und in p2 den Index des zu
 *   ladenden Beutesatzes.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
short Spoil::f_1134d0(int p2) {
    short sum = 0;
    short v;
    do {
        v = f_113240((short)p2, 10000);
        sum += v;
    } while (v > 0);
    return sum;
}

//@ f_113500
/* === Beschreibung (Katalog) ===
 * - Zweck: Zählt über alle Einträge der Beuteliste d->s8 hinweg zusammen, wie viele Exemplare des Gegenstands
 *   mit der ID p2 insgesamt im Beutecontainer liegen.
 * - Eingaben: this (Spoil *), p2 (gesuchte Gegenstands-ID short).
 * - Rückgabewert: Gesamtstückzahl des Gegenstands p2 im Container (short).
 * - Wichtige Variablen: sum (aufsummierte Stückzahl), s (Schleifenindex über die Beuteliste).
 === Ende Beschreibung === */
short Spoil::f_113500(short p2) {
    int o = (int)new (mark(d_1a7a58, 0x1c3)) Rec16;
    short sum = 0;
    o = o ? f_11c760(o, 0x60003) : o;
    f_11c8a0(o, d->s8);
    short s = 0;
    int list = f_11caf0(o);
    goto test;
next:
    ++s;
test:
    if (s >= f_11c320(list)) goto done;
    {
        int k = s;
        if (f_11c620(list, k) == (short)p2) sum += f_11c5f0(list, k);
        goto next;
    }
done:
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return sum;
}
//@ f_1135c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Lädt die Beuteliste d->s8 aus dem Archiv 0x60003 und gibt über f_11c320 die Anzahl der darin
 *   enthaltenen Gegenstandsposten zurück.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Anzahl der Gegenstandsposten in der Beuteliste (int).
 * - Wichtige Variablen: o (temporäres Rec16-Archivobjekt), r (Eintragsanzahl).
 === Ende Beschreibung === */
int Spoil::f_1135c0() {
    int o = (int)new (mark(d_1a7a58, 0x1eb)) Rec16;
    o = o ? f_11c760(o, 0x60003) : o;
    f_11c8a0(o, d->s8);
    int r = ((int (*)(int))f_11c320)(f_11caf0(o));
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return r;
}
//@ f_113640
/* === Beschreibung (Katalog) ===
 * - Zweck: Leert den gesamten Gegenstandsbestand der Beuteliste d->s8, indem in einer Schleife solange der
 *   jeweils erste Eintrag (Index 0) über f_11c580(list, 0) gelöscht wird, bis f_11c320(list) den Wert 0 liefert,
 *   und speichert die leere Liste über f_11c980 zurück.
 * - Eingaben: this (Spoil *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: o (Archivobjekt), list (Gegenstandsliste).
 === Ende Beschreibung === */
void Spoil::f_113640() {
    Rec16 *q = new (mark(d_1a7a58, 0x20e)) Rec16;
    int o = q ? f_11c760((int)q, 0x60003) : (int)q;
    f_11c8a0(o, d->s8);
    int list = f_11caf0(o);
    while (f_11c320(list) > 0) f_11c580(list, 0);
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
//@ f_1136d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest zum Listenindex p2 innerhalb der Beuteliste d->s8 die Stückzahl (f_11c5f0) und die
 *   Gegenstands-ID (f_11c620) aus und schreibt sie in die Ausgabezeiger *p3 und *p4.
 * - Eingaben: this (Spoil *), p2 (Index in der Beuteliste), p3 (Ausgabezeiger für die Stückzahl), p4
 *   (Ausgabezeiger für die Gegenstands-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: list (Zeiger auf die geladene Gegenstandsliste).
 === Ende Beschreibung === */
void Spoil::f_1136d0(int p2, short *p3, short *p4) {
    int o;
    o = (int)new (mark(d_1a7a58, 0x232)) Rec16;
    o = o ? f_11c760(o, 0x60003) : o;
    f_11c8a0(o, d->s8);
    p2 = (short)p2;
    int list = f_11caf0(o);
    *p3 = f_11c5f0(list, p2);
    *p4 = f_11c620(list, p2);
    f_11c980(o, d->s8);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
