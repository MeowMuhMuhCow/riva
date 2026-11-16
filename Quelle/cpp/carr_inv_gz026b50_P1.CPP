/* === Beschreibung (Katalog) ===
 * Einheit carr_inv_gz026b50 (0x00025ac0 - 0x00026ff0)
 *
 * Überblick
 *
 * Die Einheit carr_inv_gz026b50 implementiert das Inventar- und Ausrüstungs-Trägersystem (CARR_INV.CPP) der
 * Helden. Sie verwaltet für jeden Charakter die 23 Ausrüstungs- und Rucksackplätze (0 bis 6 am Körper wie Kopf,
 * Brust, Hände, Ringe, Schuhe sowie 7 bis 22 im Rucksack), prüft Körperzonen-Regeln, Zweihandwaffen-Sperren,
 * Klassenverbote und Tragkraftgrenzen, stapelt Munition oder Kräuter und zeichnet die Gegenstandssymbole in die
 * Inventar-Slots.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 22/25 gleich (suche.py 30.10.2026, Basis carr_inv_gz026b50_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra493: echte Vereinigung carr_inv+gz_026b50, 025ac0-026ff0.
// carr_inv.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x025AC0-0x026B50
#include <string.h>
#include <stdlib.h>
#define A(x) ((int)&(x))
struct T9 { char b[9]; T9(int w, int h); ~T9(); };       // ctor 0x0FAC80, dtor 0x0FAD20
struct Raw27 { char b[27]; };
struct Slot { short n; short idx; Raw27 d; };
struct Msg { int h; int *n; int x[2]; int *s; int pad[10]; };
struct S4 { short a; short b; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define F1(m) (m).n[1]



int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
short f_026b50(int p1, int p2, int p3, int p4);
int f_026cf0(int p1, int p2, int p3, int p4);
short f_026de0(int p1, int p2);
int f_026e80(int p1, int p2, int p3);
int f_033250(int p1, int p2);
int f_033260(int p1, int p2, int p3);
int f_033450(int p1, int p2, int p3, int p4, int p5);
int f_035180(int p1, int p2);
int f_036300(int p1, int p2, int p3);
int f_036a10(int p1, int p2, int p3, int p4, int p5);
signed char f_042a40(int p1, int p2);
short f_042a60(int p1, int p2);
short f_042ac0(int p1, int p2);
int f_042af0(int p1, int p2, int p3);
int f_042bb0(int p1, int p2);
int f_043170(int p1);
Raw27 *f_0431a0(int p1, int p2);
short f_149360(int p1, int p2);
int f_05dec0(int p1);
int f_05ded0(int p1, int p2);
int f_05e320(int p1, int p2, int p3);
int f_05e340(int p1);
short f_0a7800(int p1);
int f_0a7810(int p1);
int f_0a78f0(int p1);
int f_0a7950(int p1);
int f_0bd350(int p1, int p2, int p3);
int f_0bf730(int p1, int p2);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0e9660(int p1, int p2, int p3, int p4);
int f_0e9690(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
extern int d_1a34e0;
extern int d_1a48aa;
extern S4 d_1a4910[];
extern S4 d_1a4912[];
extern char d_1c21b4[];
extern int d_1c2be0;
extern int d_1c2c64;
extern int d_1c3068;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
extern const char d_1a0620[];

#define IT(i) (*(int **)&d_1c2c40)[i]
#define ITB(i) IT(i)
typedef unsigned short FT;
#define M1 0xffff
struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
};
#define LESS(t, l) ((int)(short)(t) > (int)(l))
struct CI {
    int g;
    T9 *i4, *i8, *ic, *i10;
    int i14, i18;
    FT fl[15];
    CI *f_025ac0(int p2, int p3, int p4);
    CI *f_025be0(int p2);
    int f_025c40();
    short f_025c50(Slot *p2);
    void f_025cd0();
    void f_025d90(short idx, int buf);
    short f_025f90(Slot *p2, short p3, int p4, int p5);
    short f_026150(Slot *p2, short p3, int p4, int p5, int p6);
    short f_026280(Slot *p2, short p3, int p4, int p5, int p6);
    short f_0264d0(short p2);
    void f_026570(short k, short frame);
    void f_026600(short p2);
    void f_0266e0(short p2);
    void f_0268c0();
    short f_026a20(short p2);
    short f_026a70(short p2);
    Slot *f_026a80(short p2);
    inline int fit(int n, int price);
    inline void dk(short k, short frame);
};
#define SHRINK(r, price) r = fit(r, price)

inline int CI::fit(int n, int price)
{
    short lim2;
    int tot;
    lim2 = f_042a40(g, 6) * 100;
    tot = f_043170(g) + n * price;
    while (LESS(tot, lim2) && n > 0) {
        n--;
        tot -= price;
    }
    return n;
}

inline void CI::dk(short k, short frame)
{
    f_04fef0(A(d_1c2be0), i14, ((int)(((RivaRasterImage*)((int)i10))->f_0fb0b0())), 0, frame, 0, 0x140);
    MG hf;
    ((RivaRasterImage*)((int)i10))->f_0fae30((void *)( d_1a34e0), (short)(d_1a4910[k].a - 1), (short)(d_1a4912[k].a - 1), 1);
    if (hf.fl == 1) f_0d26e0();
}

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_025ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert das Inventar-Verwaltungsobjekt für die 23 Ausrüstungs- und Rucksackplätze eines
 *   Helden, verknüpft die Bildschirmkoordinaten der Slot-Kästchen und lädt die Hintergrund- und Rahmengrafiken
 *   für die Gegenstandsablage.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie die Koordinaten- und Fensterparameter
 *   der Inventaransicht und gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Eingerichtet werden die Slot-Verwaltung für die 23 Inventarplätze (0x17 Slots), der
 *   Zeiger auf den aktuell betrachteten Helden bei +0x25 und die Maus-Ziehdaten.
 === Ende Beschreibung === */
CI *CI::f_025ac0(int p2, int p3, int p4)
{
    g = p2;
    i4 = new (mark(d_1a0620, 0x39)) T9(0x10, 0x10);
    i8 = new (mark(d_1a0620, 0x3a)) T9(0x10, 0x10);
    ic = new (mark(d_1a0620, 0x3b)) T9(0x10, 0x10);
    i10 = new (mark(d_1a0620, 0x3c)) T9(0x12, 0x12);
    i14 = p3;
    i18 = p4;
    memset(fl, 0, 0x1e);
    f_04fef0(A(d_1c2be0), i14, ((int)(((RivaRasterImage*)((int)i8))->f_0fb0b0())), 0, 0, 0, 0x140);
    f_04fef0(A(d_1c2be0), i14, ((int)(((RivaRasterImage*)((int)ic))->f_0fb0b0())), 0, 1, 0, 0x140);
    return this;
}

//@ f_025be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die Inventar-Trägeransicht beim Schließen des Charakterbogens wieder ab und gibt die
 *   reservierten Grafik- und Verwaltungspuffer frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie die Destruktor-Flags entgegen und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben werden die in f_025ac0 angelegten Unterobjekte und Speicherblöcke.
 === Ende Beschreibung === */
CI *CI::f_025be0(int p2)
{
    delete i4;
    delete i8;
    delete ic;
    delete i10;
    return this;
}

//@ f_025c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wechselt den Helden, dessen 23 Ausrüstungs- und Rucksackplätze aktuell im Inventarfenster
 *   angezeigt und bearbeitet werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie den Zeiger auf die Charakterstruktur
 *   des gewählten Helden und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gespeichert wird der Heldenzeiger im Objektfeld this + 0x25.
 === Ende Beschreibung === */
int CI::f_025c40()
{
    return g;
}

//@ f_025c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versucht einen neu erhaltenen oder gekauften Gegenstand ohne manuelles Ziehen im Inventar
 *   eines Helden unterzubringen, indem zuerst nach einem vorhandenen Stapel gleichen Typs gesucht und
 *   andernfalls der erste freie Rucksackplatz (Slot 7 bis 22) belegt wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den Heldenzeiger, die Gegenstandsdaten
 *   sowie die Stückzahl entgegen und gibt zurück, wie viele Stücke noch nicht untergebracht werden konnten (0
 *   bei vollständigem Erfolg).
 * - Wichtige Variablen: Durchsucht die Rucksackslots 7 bis 22 des Helden und nutzt f_026150 zum Aufstocken
 *   bestehender Stapel sowie f_025cd0 zum Belegen freier Plätze.
 === Ende Beschreibung === */
short CI::f_025c50(Slot *p2)
{
    short r = p2->n;
    short t = f_026de0((int)this, p2->idx);
    if (t != -1) {
        if (f_0a7950(IT(p2->idx)) != 0) {
            short t_165 = f_042ac0(g, t);
            if (t_165 != (short)0) r = f_026150(p2, t, 0, 0, 0);
            else r = f_026280(p2, t, 0, 0, 0);
        } else {
            r = f_025f90(p2, t, 0, 0);
        }
    }
    return r;
}

//@ f_025cd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht ab Beginn des Rucksacks (Slot 7 bis Slot 22) den ersten leeren Inventarplatz des Helden
 *   und legt den übergebenen Gegenstand unter Beachtung der Tragkraft dort ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Heldenzeiger, den Gegenstandszeiger
 *   und die Stückzahl und gibt die Restmenge zurück, falls der Rucksack voll oder der Held überladen ist.
 * - Wichtige Variablen: Geprüft werden die 16 Rucksackplätze (7..22) des Helden über f_025f90.
 === Ende Beschreibung === */
void CI::f_025cd0()
{
    short i;
    char *buf = new (mark(d_1a0620, 0x98)) char[64000];
    MG hf;
    memcpy(buf, (void *)d_1a34e0, 64000);
    for (i = 0; i < 0x1f; i++) f_025d90(i, (int)buf);
    memcpy((void *)d_1a34e0, buf, 64000);
    delete buf;
    if (hf.fl == 1) f_0d26e0();
}

//@ f_025d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Anklicken eines der 23 Inventarplätze mit der Maus: Hält der Spieler noch
 *   keinen Gegenstand am Mauszeiger, wird das angeklickte Objekt (bei Stapeln optional nach Mengenabfrage)
 *   aufgenommen; hält er bereits ein Objekt, wird es auf dem Zielplatz abgelegt, gestapelt oder mit dem dort
 *   liegenden Gegenstand getauscht.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den angeklickten Slot-Index (0 bis 22) und
 *   die Mausflags entgegen und gibt einen Statuswert über die ausgeführte Aktion zurück.
 * - Wichtige Variablen: Verwendet werden der aktive Held bei this + 0x25, der aktuell gezogene Gegenstand am
 *   Mauszeiger sowie die Hilfsfunktionen f_025f90 (auf leeren Platz legen), f_026150 (stapeln) und f_026280
 *   (tauschen).
 === Ende Beschreibung === */
void CI::f_025d90(short idx, int buf)
{
    short cnt, y, x;
    int sv;
    cnt = f_042a60(g, idx);
    x = d_1a4910[idx].a;
    y = d_1a4912[idx].a;
    MG hf;
    if (cnt > 0) {
        f_04fef0(A(d_1c2be0), i18, ((int)(((RivaRasterImage*)((int)i4))->f_0fb0b0())), 0, f_0a7800(IT(cnt)), 0, 0x140);
        ((RivaRasterImage*)((int)i4))->f_0fade0((void *)( buf), x, y);
        if (f_0a7950(IT(cnt)) != 0) {
            sv = f_05dec0(A(d_1c3068));
            f_05ded0(A(d_1c3068), buf);
            f_05e320(A(d_1c38b0), 0xff, 0);
            itoa(f_042ac0(g, idx), d_1c21b4, 10);
            f_0e9660(A(d_1c38b0), A(d_1c21b4), (short)((x + 0xf) - f_0e9690(A(d_1c38b0), A(d_1c21b4))), (short)(y + 8));
            f_05e340(A(d_1c38b0));
            f_05ded0(A(d_1c3068), sv);
        }
        if (f_042bb0(g, idx) == 1) {
            f_04fef0(A(d_1c2be0), i18, ((int)(((RivaRasterImage*)((int)i4))->f_0fb0b0())), 0, 1000, 0, 0x140);
            ((RivaRasterImage*)((int)i4))->f_0fae30((void *)( buf), x, y, 1);
        }
        ((RivaRasterImage*)((int)ic))->f_0fae30((void *)( buf), x, y, 1);
    } else {
        if (idx == 7) ((RivaRasterImage*)((int)ic))->f_0fade0((void *)( buf), x, y);
        else ((RivaRasterImage*)((int)i8))->f_0fade0((void *)( buf), x, y);
    }
    if (hf.fl == 1) f_0d26e0();
}
//@ f_025f90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt einen Gegenstand auf einen leeren Ausrüstungs- oder Rucksackplatz (0 bis 22), nachdem
 *   über f_0268c0 geprüft wurde, ob der Held das Objekt an dieser Körperstelle tragen darf, und kappt bei
 *   Überschreitung der maximalen Tragkraft die abgelegte Stückzahl mit der Meldung "zu schwer" (0x20000035).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Heldenzeiger, die Zielslot-Nummer p2,
 *   den Quell-Gegenstand p3, die gewünschte Menge p4 und ein Meldungsflag p5 und gibt die nicht untergebrachte
 *   Restmenge zurück.
 * - Wichtige Variablen: Geprüft werden die freie Tragkraft des Helden über f_041ae0, das Einzelgewicht des
 *   Gegenstands aus der Item-Datenbank f_051c80 und bei Zweihandwaffen das Sperren der linken Hand (Slot 4) mit
 *   der Kennung 0xffff.
 === Ende Beschreibung === */
short CI::f_025f90(Slot *p2, short p3, int p4, int p5)
{
    short lim, s1, s2;
    Msg m2;
    int codex_arg_1_246;
    int n, ok;
    s1 = p2->n;
    if (s1 > 0) {
        short sum;
        s2 = p2->idx;
        lim = f_042a40(g, 6) * 100;
        sum = f_0a7810(IT(s2)) + f_043170(g);
        if (!LESS((int)sum, lim) || p5 == 1) {
            ok = 1;
            CX(m);
            n = (*&p3);
            if (n < 15) {
                if (f_033250(g, s2) == 0 ||
                    f_033260(g, s2, n) == 0 ||
                    f_033450(g, s2, n, g, -1) > 0) ok = 0;
            }
            CXEND(m);
            if (ok != 0) {
                f_036a10(g, (codex_arg_1_246 = p2->idx), 1, p3, A(p2->d));
                s1--;
                p4 = (p4 & 0) ? 0 : p4; // Haelt Parameter p4 ueber beide Zweige im vorgesehenen Register
            } else if (p4 == 1) {
                f_026e80((int)this, s2, p3);
                return s1;
            }
        } else if (p4 == 1) {
            f_125400((int)&m2, A(d_1c349c), A(d_1c3870), A(d_1c3498));
            F1(m2) = g;
            f_0bf730(A(d_1c2c64), 0x20000035);
            CXEND(m2);
        }
    }
    return s1;
}

//@ f_026150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt weitere Exemplare desselben stapelbaren Gegenstands (etwa Pfeile, Bolzen, Wurfwaffen oder
 *   Kräuter) einem bereits im Zielslot liegenden Stapel hinzu, begrenzt die Gesamtmenge auf maximal 99 Stück
 *   (0x63) sowie auf die verbleibende Tragkraft des Helden und führt die beiden Stapel über f_026cf0 zusammen.
 * - Eingaben und Rückgabe: Die Funktion erwartet den Objektzeiger this, den Heldenzeiger p1, den Zielslot p2,
 *   den aufzulegenden Gegenstand p3, die gewünschte Stückzahl p4 und das Meldungsflag p5 und gibt die
 *   verbleibende Restmenge zurück.
 * - Wichtige Variablen: Geprüft werden die Stapelbarkeit (Bit 0x10 in den Itemflags), die Obergrenze 99 -
 *   aktuelle_menge, die Tragkraft über f_041ae0 und die Verschmelzungsfunktion f_026cf0.
 === Ende Beschreibung === */
short CI::f_026150(Slot *p2, short p3, int p4, int p5, int p6)
{
    short r = 0, lim;
    r = p2->n;
    lim = 99 - f_042ac0(g, (*&p3));
    short price;
    price = f_0a7810(IT(p2->idx));
    if (p4 == 1) {
        { int t_ = (int)(p2->idx); r = f_026b50((int)this, r, lim, t_); }
        if (r == -1) r = 0;
    }
    if (r > 0) {
        int n;
        r = n = f_0bd350(r, 0, lim);
        if (p6 == 0) {
            short lim2;
            short tot, count = n, price2 = price;
            lim2 = f_042a40(g, 6) * 100;
            tot = f_043170(g) + count * price2;
            while (LESS(tot, lim2) && (short)count > 0) {
                count--;
                tot -= price2;
            }
            r = count;
        }
        if (0 == (short)(r & 0xffff) && (*&p5) == 1) { // 16-Bit-Maske haelt den Vergleich auf r == 0 wie im Original
            CX(m);
            F1(m) = g;
            f_0bf730(A(d_1c2c64), 0x20000035);
            CXEND(m);
        } else {
            f_026cf0((int)this, p3, r, (int)p2);
        }
    }
    return p2->n - r;
}

//@ f_026280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Tauscht den am Mauszeiger gehaltenen Gegenstand mit dem Objekt auf einem bereits belegten
 *   Ausrüstungs- oder Rucksackplatz aus, sofern der Held das neue Objekt an dieser Körperstelle tragen darf und
 *   die Tragkraft auch nach Abzug des entnommenen Gegenstands ausreicht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Heldenzeiger p1, die Zielslot-Nummer
 *   p2, den abzulegenden Gegenstand p3 und das Meldungsflag p4 und gibt 0 bei erfolgreichem Tausch oder die
 *   Restmenge bei Ablehnung zurück.
 * - Wichtige Variablen: Berücksichtigt bei Zweihandwaffen in der rechten Hand (Slot 3) auch einen eventuell in
 *   der linken Hand (Slot 4) getragenen Schild oder Zweitgegenstand und prüft die Gewichtsdifferenz über
 *   f_041ae0.
 === Ende Beschreibung === */
short CI::f_026280(Slot *p2, short p3, int p4, int p5, int p6)
{
    short idx;
    int price;
    short n;
    int ok;
    // Codelose Temp-Kopie ordnet die Stapelplaetze von n und p3 wie im Original
    { short t = p2->n; n = t; }
    price = f_0a7810(IT(p2->idx));
    ok = 1;
    idx = p2->idx;
    CX(m);
    if (p3 < 15) {
        if (f_033250(g, idx) == 0 || f_033260(g, idx, p3) == 0 || f_033450(g, idx, p3, g, -1) > 0) ok = 0;
    }
    CXEND(m);
    if (ok == 1) {
        if (p4 == 1) {
            { int t_ = (int)(p2->idx); n = f_026b50((int)this, n, 99, t_); }
            if (n == -1) { n = 0; n = 0; } // Doppelte Zuweisung ordnet die Wortregisterzuteilung fuer n
        }
        if (n > 0) {
            if (p6 == 0) {
                short lim2;
                short tot, count = n;
                int price2 = price;
                lim2 = f_042a40(g, 6) * 100;
                tot = f_043170(g) + count * price2;
                while (LESS(tot, lim2) && count > 0) {
                    count--;
                    tot -= price2;
                }
                n = count;
            }
            // Codelose Referenz ordnet den Schleifenvergleich und die Stapelplaetze
            { int *tv = (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = tv; }
            if (n == 0) {
                if (p5 == 1) {
                    CX(m2);
                    F1(m2) = g;
                    f_0bf730(A(d_1c2c64), 0x20000035);
                    CXEND(m2);
                }
            } else {
                if (n > 0) f_036a10(g, (short)p2->idx, n, p3, A(p2->d));
                f_042af0(g, (short)p3, (signed char)n);
            }
        }
    } else {
        if (p5 == 1) f_026e80((int)this, (short)p2->idx, p3);
        n = 0;
    }
    return p2->n - n;
}
short CI::f_0264d0(short p2)
{
    short r = 1;
    short k = f_042a60(g, p2);
    if (f_0a7950(IT(k)) == 1) r = f_042ac0(g, p2);
    if (f_0a78f0(IT(k)) != 0) {
        if (f_149360(k, (int)&d_1a48aa) != -1 && f_035180(g, p2) == 1) r = 0;
    } else {
        if (f_036300(g, p2, r) == 1) r = 0;
    }
    return r;
}

//@ f_026570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet beim Anklicken eines gestapelten Gegenstands (Stückzahl größer als 1) einen kleinen
 *   Auswahlregler, mit dem der Spieler festlegen kann, wie viele Stücke er vom Stapel abheben möchte, und
 *   entnimmt diese Teilmenge über f_0264d0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Heldenzeiger p1, den Slot-Index p2,
 *   einen Ausgabepuffer p3 sowie das Dialogflag p4 und gibt die aufgenommene Stückzahl zurück.
 * - Wichtige Variablen: Liest die vorhandene Stückzahl im Slot (Offset +2 des Inventareintrags) und nutzt bei p4
 *   != 0 den Mengendialog f_056920.
 === Ende Beschreibung === */
void CI::f_026570(short k, short frame)
{
    f_04fef0(A(d_1c2be0), i14, ((int)(((RivaRasterImage*)((int)i10))->f_0fb0b0())), 0, frame, 0, 0x140);
    MG hf;
    ((RivaRasterImage*)((int)i10))->f_0fae30((void *)( d_1a34e0), (short)(d_1a4910[k].a - 1), (short)(d_1a4912[k].a - 1), 1);
    if (hf.fl == 1) f_0d26e0();
}

//@ f_026600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt für den gerade aus dem Inventar aufgenommenen Gegenstand das passende
 *   16x16-Gegenstandssymbol und heftet es an den Mauszeiger, damit der Spieler beim Ziehen über den Bildschirm
 *   das Objekt direkt an der Hand sieht.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this sowie die Gegenstandsdaten entgegen und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Ermittelt über f_051c80 die Icon-Nummer des Gegenstands und übergibt das geladene Bild
 *   an die Mauszeiger-Verwaltung.
 === Ende Beschreibung === */
void CI::f_026600(short p2)
{
    short i;
    int ok;
    for (i = 0; i < 15; i++) {
        if (p2 > 0) {
            ok = 1;
            CX(m);
            if (i < 15) {
                if (f_033250(g, p2) == 0 || f_033260(g, p2, i) == 0 || f_033450(g, p2, i, g, -1) > 0) ok = 0;
            }
            CXEND(m);
            if (ok == 1) {
                fl[i] = 1;
                continue;
            }
        }
        if ((short)fl[i] == (short)1) fl[i] = -1;
        else fl[i] = 0;
    }
}

//@ f_0266e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im geöffneten Inventarfenster sämtliche 23 Ausrüstungs- und Rucksackkästchen des
 *   aktuellen Helden, stellt darin getragene Gegenstände, Zweihand-Sperrsymbole oder kaputte Waffen dar und
 *   blendet bei Stapeln die kleine Stückzahl in der Ecke ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie optionale Zeichenflags und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Durchläuft die 23 Slots des Helden (this + 0x25), liest deren Item-IDs und Mengen und
 *   zeichnet die Icons an die jeweiligen Kästchenkoordinaten.
 === Ende Beschreibung === */
void CI::f_0266e0(short p2)
{
    int p2_ = p2;
    if (p2_ >= 0xf || !fl[p2_]) dk(p2, 2);
    short i;
    for (i = 0; i < 15; i++) {
        if ((short)fl[i] == (short)-1) {
            fl[i] = 0;
            dk(i, 2);
        }
    }
    for (i = 0; i < 15; i++) {
        if ((short)fl[i] == (short)1) dk(i, 5);
    }
}

//@ f_0268c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft vor dem Anlegen eines Gegenstands in einen Körperslot (0 bis 6), ob der Gegenstandstyp
 *   überhaupt an diese Körperstelle gehört (Helm auf Kopf, Waffe in rechte Hand, Ring an Finger, Schuhe an
 *   Füße), ob eine Zweihandwaffe die linke Hand blockiert, ob der Held wegen seiner Charakterklasse (etwa Magier
 *   oder Druide bei Metallrüstungen) gesperrt ist oder ob es sich um einen persönlichen Gegenstand eines anderen
 *   Helden handelt.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den Heldenzeiger p1, die Zielslot-Nummer
 *   p2, den Gegenstandszeiger p3 und das Meldungsflag p4 entgegen und gibt 1 zurück, wenn das Ablegen erlaubt
 *   ist, sonst 0.
 * - Wichtige Variablen: Vergleicht die Körperzonen-Tabelle d_1a48e8[p2] mit der Trageposition des Items (Offset
 *   +5 der Item-Stammdaten), prüft das Zweihand-Flag (0x08 in Offset +3), ruft die Klassenprüfung f_0343a0 auf
 *   und gibt bei Verstoß die passende Ablehnungsmeldung (0x20000034 bis 0x20000072) aus.
 === Ende Beschreibung === */
void CI::f_0268c0()
{
    short i;
    for (i = 0; i < 15; i++) {
        if ((short)fl[i] == (short)-1) {
            fl[i] = 0;
            dk(i, 2);
        }
    }
    for (i = 0; i < 15; i++) {
        if ((short)fl[i] == (short)1) dk(i, 5);
    }
}
//@ f_026a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt fest, ob ein bestimmter der 23 Inventarplätze eines Helden momentan unbesetzt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Heldenzeiger p1 und den Slot-Index p2
 *   und gibt 1 zurück, wenn der Slot leer ist (Item-ID == 0), andernfalls 0.
 * - Wichtige Variablen: Geprüft wird das 16-Bit-Feld Item-ID am Beginn des 20-Byte-Inventareintrags p1 + p2 *
 *   0x14 + 0x217.
 === Ende Beschreibung === */
short CI::f_026a20(short p2)
{
    short s, r;
    r = 0;
    s = f_042a60(g, p2);
    if (s != 0) {
        if (f_0a7950(ITB(s)) == 1) r = f_042ac0(g, p2);
        else r = 1;
    }
    return r;
}

//@ f_026a70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zeiger auf den Helden zurück, dessen Inventar gerade in der Trägeransicht dargestellt
 *   wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this entgegen und liefert den Heldenzeiger aus
 *   this + 0x25 zurück.
 * - Wichtige Variablen: Gelesen wird das Feld this + 0x25.
 === Ende Beschreibung === */
short CI::f_026a70(short p2)
{
    return f_042a60(g, p2);
}

//@ f_026a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die Inventar-Trägeransicht, wenn der Spieler zu einem anderen Gruppenmitglied
 *   blättert oder sich die Ausrüstung geändert hat, und zeichnet alle Slots neu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (sowie optionale Parameter) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Synchronisiert den Heldenzeiger this + 0x25 und stößt das Neuzeichnen der Slot-Symbole
 *   über f_0266e0 an.
 === Ende Beschreibung === */
Slot *CI::f_026a80(short p2)
{
    Slot *r = new (mark(d_1a0620, 0x27e)) Slot;
    if (r != 0) {
        Raw27 *q;
        Raw27 tmp;
        short b, a;
        q = f_0431a0(g, p2);
        a = f_026a70(p2);
        b = f_026a20(p2);
        tmp = *q;
        r->n = b;
        r->idx = a;
        memcpy(&r->d, &tmp, 27);
        return r;
    }
    return 0;
}

extern short gz026_d_1bc814;
#pragma aux gz026_d_1bc814 "d_1bc814"
extern short gz026_d_1bc816;
#pragma aux gz026_d_1bc816 "d_1bc816"
extern short gz026_d_1bc818;
#pragma aux gz026_d_1bc818 "d_1bc818"
extern short gz026_d_1bc81a;
#pragma aux gz026_d_1bc81a "d_1bc81a"


extern short gz026_d_1c2c64;
#pragma aux gz026_d_1c2c64 "d_1c2c64"
extern char gz026_d_1c3498[];
#pragma aux gz026_d_1c3498 "d_1c3498"
extern char gz026_d_1c349c[];
#pragma aux gz026_d_1c349c "d_1c349c"
extern char gz026_d_1c3870[];
#pragma aux gz026_d_1c3870 "d_1c3870"
struct ContextGz026 { public:
// gz_026b50.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x026B50-0x026FF0
static int f_033250(int p1, int p2);
static int f_033260(int p1, int p2, int p3);
static int f_033450(int p1, int p2, int p3, int p4, int p5);
static int f_036a10(int p1, int p2, int p3, int p4, int p5);
static int f_040e90(int p1);
static signed char f_042a40(int p1, int p2);
static short f_042a60(int p1, int p2);
static short f_042ac0(int p1, int p2);
static int f_042b20(int p1, int p2, int p3);
static short f_042fd0(int p1, int p2);
static int f_043000(int p1, int p2, int p3);
static signed char f_043030(int p1, int p2);
static int f_043060(int p1, int p2, int p3);
static int f_043170(int p1);
static int f_043190(int p1, int p2);
static int f_0a7810(int p1);
static int f_0a7950(int p1);
static int f_0a7ad0(int p1);
static int f_0bf680(int p1);
static int f_0bf6c0(int p1, int p2);
static int f_0bf730(int p1, int p2);
static int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
static int f_125400(int p1, int p2, int p3, int p4);
static int f_1254a0(int p1, int p2);
#define A(x) ((int)&(x))
struct Msg { int h; int *a; int x; int *b; int *c; short *d; int z[2]; short *e; int pad[6]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
struct MsgC_026b50 : Msg { MsgC_026b50(int, int, int); ~MsgC_026b50(); };
static int f_026b50(int *p1, int p2, int p3, short p4);
static int f_026c10(int *p1, int p2, int p3);
static int f_026c60(int *p1, int p2, int p3);
static void f_026cf0(int *p1, short p2, short p3, char *p4);
static void f_026db0(int *p1, int p2, int p3, char *p4);
static int f_026de0(int *p1, short p2);
static void f_026e80(int *p1, short p2, int p3);
static void f_026fb0(void);
};
//@ f_026b50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die 20-Byte-Struktur eines Gegenstands in den angegebenen Inventarplatz des Helden,
 *   erhöht das getragene Gesamtgewicht des Charakters entsprechend der Stückzahl und rechnet bei angelegter
 *   Kleidung oder Rüstung (Slot 0..6) den Rüstungsschutz (RS) und die Behinderung (BE) auf den Helden an.
 * - Eingaben und Rückgabe: Die Funktion erwartet den Objektzeiger this, den Heldenzeiger p1, den
 *   Quell-Gegenstand p2, die Stückzahl p3 und den Zielslot p4 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Beschrieben werden der Inventarslot p1 + p4 * 0x14 + 0x217, das getragene Gewicht bei p1
 *   + 0x3eb, der Rüstungsschutz bei p1 + 0x90 sowie die Behinderung bei p1 + 0x91 (über die Rüstungstabelle
 *   d_1a5be8).
 === Ende Beschreibung === */
int ContextGz026::f_026b50(int *p1, int p2, int p3, short p4)
{
    if (1 < (short)p2) {
        MsgC_026b50 m((int)(A(gz026_d_1c349c)), (int)(A(gz026_d_1c3870)), (int)(A(gz026_d_1c3498)));
        short q;
        if ((short)p2 < (short)p3) q = p2;
        else q = (*&p3);
        f_0bf6c0(A(gz026_d_1c2c64), 5);
        m.a[1] = *p1;
        m.d[1] = (short)p2;
        m.b[1] = (*(int **)&d_1c2c40)[(short)p4];
        m.e[1] = (short)p2;
        p2 = f_0bf7b0(A(gz026_d_1c2c64), 2, 0x21040004, 0, (short)p2, (short)q);
        f_0bf680(A(gz026_d_1c2c64));
    }
    return p2;
}
//@ f_026c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt alle Felder eines einzelnen 20-Byte-Inventarplatzes (Item-ID, Stückzahl, Flags,
 *   Haltbarkeit, Giftstatus und Namen) auf null zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und den Zeiger auf den zu löschenden
 *   20-Byte-Inventareintrag p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nullt die Strukturfelder an den Offsets +0x00 bis +0x0f des übergebenen Inventarslots.
 === Ende Beschreibung === */
int ContextGz026::f_026c10(int *p1, int p2, int p3)
{
    signed char c = f_042a40(*p1, 6);
    unsigned short lim = c * 100;
    int v;
    v = f_043170(*p1) + p2 * p3;
    for (;;) {
        int a = (short)v;
        int b = (short)lim;
        if (a <= b) break;
        int c2 = (short)p2;
        if (c2 <= 0) break;
        p2--;
        v = v - p3;
    }
    return p2;
}
//@ f_026c60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht beim Ablegen oder Verlieren eines Gegenstands dessen Gewicht vom getragenen
 *   Gesamtgewicht des Helden ab, vermindert bei Rüstungsstücken in den Körperslots (0..6) den Rüstungsschutz
 *   sowie die Behinderung, hebt bei Zweihandwaffen die Sperre der linken Hand auf und löscht schließlich den
 *   Slot über f_026c10.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den Heldenzeiger p1 und den Slot-Index p2
 *   entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden das getragene Gewicht bei p1 + 0x3eb, der Rüstungsschutz bei p1 +
 *   0x90, die Behinderung bei p1 + 0x91, der Zweihand-Sperrslot Slot 4 (p1 + 0x267) und der geleerte Slot
 *   selbst.
 === Ende Beschreibung === */
int ContextGz026::f_026c60(int *p1, int p2, int p3)
{
    int ret = 1;
    short r3 = p3;
    CX(m);
    if (r3 < 0xf) {
        int s = (short)p2;
        if (f_033250(*p1, s) == 0 || f_033260(*p1, s, r3) == 0 || f_033450(*p1, s, r3, *p1, -1) > 0) ret = 0;
    }
fin:
    CXEND(m);
    return ret;
}
//@ f_026cf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht die Stückzahl eines bereits im Inventar liegenden Stapels um p2 Exemplare, addiert
 *   deren Gewicht zum getragenen Gesamtgewicht des Helden und führt bei vergifteten Waffen oder Geschossen die
 *   Giftart und Giftladungen zusammen. *(Hinweis: Hier liegt ein Originalfehler vor, da beim Auflegen anders
 *   vergifteter Stücke die bisherige Giftart und Ladungszahl des gesamten Zielstapels durch das Gift des neu
 *   aufgelegten Teils überschrieben wird.)*
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Quell-Gegenstand p1, die hinzukommende
 *   Stückzahl p2 und den Zielslot-Index p3 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert werden die Stückzahl im Zielslot (Offset +2), die Giftflags (Offset +4), die
 *   Giftladungen (Offset +9), die Giftart (Offset +0xd) und das Gesamtgewicht des Helden (+0x3eb).
 === Ende Beschreibung === */
void ContextGz026::f_026cf0(int *p1, short p2, short p3, char *p4)
{
    short t;
    if (0 < (short)p3) {
        f_043190(*p1, (short)(f_0a7810((*(int **)&d_1c2c40)[*(short *)(p4 + 2)]) * p3));
        f_042b20(*p1, (short)p2, (signed char)p3);
        if (0 < *(signed char *)(p4 + 0xe)) {
            short c1 = *(signed char *)(p4 + 0xe);
            t = f_043030(*p1, (short)p2);
            short s3 = f_042fd0(*p1, (short)p2);
            short q = p3;
            if (c1 < (short)p3) q = c1;
            if (*(signed char *)(p4 + 0xd) == s3) t += q;
            else t = q;
            f_043000(*p1, (short)p2, *(signed char *)(p4 + 0xd));
            f_043060(*p1, (short)p2, (signed char)t);
        }
    }
}
//@ f_026db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht p2 Exemplare von einem Inventarplatz des Helden ab; fällt die verbleibende Menge auf
 *   null oder darunter, wird der Gegenstand über f_026c60 vollständig aus dem Slot entfernt, andernfalls werden
 *   nur die Stückzahl und das getragene Gewicht reduziert.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den Heldenzeiger p1, die abzuziehende Menge
 *   p2 und den Slot-Index p3 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden die Stückzahl des Slots (Offset +2) und das getragene Gewicht des
 *   Helden bei p1 + 0x3eb.
 === Ende Beschreibung === */
void ContextGz026::f_026db0(int *p1, int p2, int p3, char *p4)
{
    if (0 < (short)p3) f_036a10(*p1, *(short *)(p4 + 2), (short)p3, (short)p2, (int)(p4 + 4));
}
//@ f_026de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert sämtliche Eigenschaften eines 20-Byte-Inventareintrags (Kennung, Stückzahl, Flags,
 *   Ladungen, Giftwerte und den eingebetteten Kurznamen) von einer Quellstruktur in eine Zielstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this, den Zielzeiger p1 und den Quellzeiger p2
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Überträgt die Felder +0x00 bis +0x13 des 20-Byte-Gegenstandseintrags.
 === Ende Beschreibung === */
short f_026de0(int p1, int p2)
{
    short r = -1;
    short i = 15;
    short j;
    short k = p2;
    if (f_0a7950(IT(k)) != 0) {
        while (r == -1 && i <= 30) {
            if (f_042a60(*(int *)p1, i) == k && f_042ac0(*(int *)p1, i) < 99) r = i;
            i++;
        }
    }
    if (r == -1) {
    j = 15;
    while (r == -1 && j <= 30) {
        if (f_042a60(*(int *)p1, j) == 0) r = j;
        j++;
    }
    }
    return r;
}

//@ f_026e80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Befüllt eine leere 20-Byte-Inventarstruktur anhand einer Gegenstands-Kennung aus der
 *   Stammdatenbank (ITEMS.DAT): Ist das Objekt stapelbar, wird die übergebene Stückzahl eingetragen, andernfalls
 *   wird die Menge auf 1 gesetzt und die Standardanzahl magischer Ladungen übernommen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger this, den Zielpuffer p1, die Gegenstands-ID p2
 *   und die gewünschte Menge p3 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest die Stammdaten über f_051c80(p2) und setzt im Zielpuffer p1 die Item-ID (+0x00),
 *   die Menge (+0x02), die Flags (+0x04) und die magischen Ladungen (+0x08).
 === Ende Beschreibung === */
void ContextGz026::f_026e80(int *p1, short p2, int p3)
{
    short s = p2;
    CX(m);
    int r = f_033250(*p1, s);
    int o4 = s * 4;
    if (r == 0) {
        m.a[1] = *p1;
        m.b[1] = (*(int **)&d_1c2c40)[s];
        m.e[1] = 1;
        m.c[1] = f_040e90(*p1);
        f_0bf730(A(gz026_d_1c2c64), 0x20000106);
    } else {
        if (!f_033260(*p1, s, (short)p3)) {
            m.b[1] = *(int *)(o4 + (int)(*(int **)&d_1c2c40));
            m.e[1] = 1;
            if (f_0a7ad0(*(int *)(o4 + (int)(*(int **)&d_1c2c40))) != 0 || f_0a7950(*(int *)(o4 + (int)(*(int **)&d_1c2c40))) != 0) {
                m.c[1] = 0x20000108;
                m.e[1] = 2;
            } else {
                m.c[1] = 0x20000109;
            }
            f_0bf730(A(gz026_d_1c2c64), 0x20000107);
        } else if (f_033450(*p1, s, (short)p3, *p1, -1) != 0) {
            m.a[1] = *p1;
            f_0bf730(A(gz026_d_1c2c64), 0x2000010a);
        }
    }
    CXEND(m);
}
//@ f_026fb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schlägt für einen Inventargegenstand in der Gegenstands-Datenbank nach, wie viele Unzen ein
 *   einzelnes Exemplar wiegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this und den Zeiger auf den Inventargegenstand
 *   p1 und gibt dessen Einzelgewicht als 16-Bit-Zahl zurück (0 bei leerem Slot).
 * - Wichtige Variablen: Liest die Item-ID am Offset +0x00 von p1, ruft f_051c80 auf und gibt das Gewichtsfeld am
 *   Offset +0x06 des Datenbankeintrags zurück.
 === Ende Beschreibung === */
void ContextGz026::f_026fb0(void)
{
    gz026_d_1bc814 = 1;
    gz026_d_1bc816 = 0x9c;
    gz026_d_1bc818 = 0x11f;
    gz026_d_1bc81a = 0xbc;
}
