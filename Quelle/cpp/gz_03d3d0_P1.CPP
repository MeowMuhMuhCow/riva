/* === Beschreibung (Katalog) ===
 * Einheit gz_03d3d0 (0x03D3D0 - 0x03D900)
 *
 * Überblick
 * Die Einheit gz_03d3d0 enthält zentrale Hilfsfunktionen des Zaubersystems: die Talent-/Eigenschaftsprobe für
 * einen Zauberspruch unter Berücksichtigung der Magieresistenz des Ziels (f_03d3d0), den kompletten Auswahl-,
 * Zielprüfungs- und Ausführungsablauf eines Zaubers (f_03d4b0), drei Wrapper für grafische Zaubereffekt-Fenster
 * (f_03d790, f_03d7d0, f_03d820) sowie Lese- und Schreibzugriffe auf zauberbezogene Bitfelder im Heldendatensatz
 * (f_03d860, f_03d8b0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/9 gleich (suche.py 25.10.2026, Basis gz_03d3d0_P1.CPP)
// I9: aus gz_03d3d0_REST.CPP uebernommen (Stufe-2-Stand), Marken 9 neu
// gz_03d3d0.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x03D3D0-0x03D980. Zauber-Hilfen: Pruefung/Kosten, Zauber-Ablauf, Effekt-Fenster, Bitfelder, Hintergrund auf/ab.
#include <string.h>
#include <stdlib.h>
#pragma intrinsic(_lrotl)
struct Ent; struct Game;
struct SpT { char b0; signed char b1; signed char b2; signed char b3; char b4; signed char b5; char b6; signed char b7; char b8; unsigned char b9; char pad[4]; };
extern SpT d_1a7270[];
extern int d_1c0420, d_1c11d0, d_1c040e;
extern char d_1c040c[0x14];
extern short d_1bd90c;
extern short d_1c0428;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern void *d_1a34e0;
struct Sl { char pad[0xb]; unsigned long bits; char pad2[0xc]; };
struct Ent : hero {
    
    signed char f_030960(); Ent *f_030890(); Ent *f_030810();
       
     short f_044940(int a, int b, int c, int d);
    short f_03cd00(int k); void f_030850(Ent *x);  signed char f_0433d0(); 
    short f_03d3d0(short idx, signed char b); short f_03d4b0(short mode, short arg);
};
signed char f_0cfa70(Ent *x); char f_0cfef0(Ent *x); int f_0d49b0(Ent *e);
struct Game { Ent *f_038e90(long code); };
extern Game *d_1c0004;
struct Msg { void f_0bf730(long code); void f_0bf6c0(int a); void f_0bf680(); };
extern Msg d_1c2c64;


struct Sp { char b[0x20]; Sp(Ent *e); ~Sp(); short f_10ce80(int a, int b); };
struct Eff { char b[0x20]; Eff(Ent *a, Ent *b, int c, int d, int e); Eff(Ent *a, int b, int c, int d, int e, int f); ~Eff(); void f_134910(); void f_134d50(); void f_13bc30(); };
void f_09ac80(void *p, int a, int b); void f_09a140(int a, int b); void f_10a980(Ent *e, int a, int b); void f_09ade0(void *p, int a, int b);
int f_09aed0(int a); void f_0d2710(); void f_0d26e0();

//@ f_03d3d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt für den zaubernden Helden (this) die dreifache Eigenschaftsprobe für den Zauberspruch
 *   idx (1..85) mit dem Basis-Zuschlag b durch. Ist das Flag b9 in der Zaubertabelle d_1a7270[idx] gesetzt
 *   (Opfer-Magieresistenz berücksichtigen), wird die Magieresistenz des Ziel-Monsters (f_0cfa70) bzw.
 *   Ziel-Helden (f_0423a0) auf die Erschwernis b addiert und bei vollständiger Zauberimmunität des Monsters
 *   (f_0cfef0) sofort 0 (Fehlschlag) geliefert; andernfalls zieht die Funktion den Zauberfertigkeitswert
 *   (f_0430f0) von b ab und würfelt die Probe über f_044940 auf die drei Eigenschaften b1, b2, b3.
 * - Eingaben:
 *   - this (Impliziter Zeiger auf den zaubernden Helden Ent).
 *   - idx (Zauberspruch-Index 1..85).
 *   - b (Anfänglicher Proben-Modifikator / Erschwernis).
 * - Rückgabewert: short - Ergebnis der Zauberprobe (> 0 gelungen, 0 oder <= 0 misslungen, -1 wenn Zaubern durch
 *   d_1c11d0 blockiert ist, 99 bei Sonderflag d_1c0420).
 * - Wichtige Variablen:
 *   - t (Zeiger auf den Zaubertabelleneintrag &d_1a7270[idx]).
 *   - b (Laufend angepasster Proben-Zuschlag aus Magieresistenz minus Zauberwert).
 *   - r (Rückgabewert der Probe).
 === Ende Beschreibung === */
#if FIX_BUGS >= 1
short f_1457e0(int p1);
#endif
short Ent::f_03d3d0(short idx, signed char b)
{
    short r = 1;
    if (d_1c0420 == 0) {
        if (d_1c11d0 != 0) r = -1;
        else {
            SpT *t = &d_1a7270[idx];
            if (t->b9) {
                if (f_030960() == 1) {
                    b = b + f_0cfa70(f_030890());
                    if (f_0cfef0(f_030890())) r = 0;
                } else {
                    b = b + ::f_0423a0((hero *)(f_030810()));
                }
            }
            if (r && idx >= 1 && idx <= 85) {
                if (d_1c0420 != 0) return 99;
#if FIX_BUGS >= 1
                signed char mod = b;
                signed char zw = ::f_0430f0((hero *)(this), idx);
                short w[3] = { 0, 0, 0 };
                unsigned short sum = 0;
                short ones = 0, i, w_r;
                b = b - zw;
                for (i = 0; i < 3; i++) {
                    w_r = f_1457e0(20);
                    w[i] = w_r;
                    if (w_r == 20) {
                        ones = ones + 1;
                        if (ones == 2) break;
                    }
                    sum = sum + w_r;
                }
                sum += b;
                short v1 = (signed char)::f_042a40((hero *)(this), t->b1);
                short v2 = (signed char)::f_042a40((hero *)(this), t->b2);
                short v3 = ::f_042a40((hero *)(this), t->b3);
                r = (ones == 2) ? -99 : (short)((v2 + v1) + v3 - sum + 1);
                PLOG_3W20('Z', (const char *)this + 0x22, idx, zw, mod, t->b1, v1, w[0], t->b2, v2, w[1], t->b3, v3, w[2], r);
#else
                b = b - ::f_0430f0((hero *)(this), idx);
                r = f_044940(t->b1, t->b2, t->b3, b);
#endif
            }
        }
    }
    return r;
}

//@ f_03d4b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die Auswahl, Zielwahl und Ausführung eines Zauberspruchs durch den Helden this:
 *   Prüft zunächst, ob der Held überhaupt magiekundig und handlungsfähig ist, lässt bei mode == 1 den Zauber
 *   interaktiv über f_03cd00(0) und ggf. das Ziel über d_1c0004->f_038e90 wählen (inklusive Prüfung, ob auf Tote
 *   nur passende Zauber wie 0x3b oder 0x21 gewirkt werden dürfen), prüft anschließend, ob der Zauber im Kampf
 *   (d_1bd90c != 0) bzw. außerhalb des Kampfes (d_1bd90c == 0) erlaubt ist (p->b5), und führt den Zauber
 *   schließlich über Sp::f_10ce80(sel, arg) aus.
 * - Eingaben:
 *   - this (Impliziter Zeiger auf den zaubernden Helden Ent).
 *   - mode (Auswahlmodus: 1 für interaktive Spruch- und Zielauswahl durch den Spieler, sonst direkter Abruf des
 *     voreingestellten Zaubers über f_0433d0()).
 *   - arg (Zusatzargument für die Zauberausführung Sp::f_10ce80).
 * - Rückgabewert: short - Ergebnis der Zauberausführung (-1 bei Abbruch oder unzulässigem Zauber, sonst
 *   Rückgabewert von Sp::f_10ce80).
 * - Wichtige Variablen:
 *   - sel (Ausgewählter Zauberspruch-Index).
 *   - p (Zeiger auf den Zaubertabelleneintrag &d_1a7270[sel]).
 *   - code (Kennung einer auszugebenden Fehlermeldung, z. B. 0x20000161, 0x1700009f, 0x20000167 "nicht außerhalb
 *     des Kampfes" oder 0x20000168 "nicht im Kampf").
 *   - o (Lokales Zauberausführungs-Objekt Sp).
 === Ende Beschreibung === */
short Ent::f_03d4b0(short mode, short arg)
{
    int ok = 1;
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    memset(d_1c040c, 0, 0x14);
    d_1c2c64.f_0bf6c0(3);
    short r = 1;
    long code = 0;
    short sel;
    SpT *p = 0;

    if (::f_042a10((hero *)(this)) != 0 && (f_0d49b0(this) != 0 || ::f_0425a0((hero *)(this)))) {
        // Continue with normal selection.
    } else if (d_1c0420 == 0) {
        d_1c040e = 1;
        memset(&d_1c0420, 0, 0xb);
        c.tables.objects[1] = this;
        if (::f_042a10((hero *)(this)) == 0) code = 0x20000161L;
        else code = 0x1700009fL;
        r = -1;
        goto fertig;
    }

    if (mode == 1) {
        sel = f_03cd00(0);
        if (sel > 0) {
            p = &d_1a7270[sel];
            f_030850(this);
            int k = 0; k = p->b7;
            if (k != 0 && k != 4) {
                if (k == 1) {
                    d_1c2c64.f_0bf730(0x2000016bL);
                    sel = -1;
                } else if (sel == 5 && d_1c0428 == 6) {
                    f_030850(0);
                } else {
                    f_030850(d_1c0004->f_038e90(0x2000016cL));
                    if ((unsigned char)::f_0432b0((hero *)(this)) == 0xff) sel = -1;
                    else if (::f_042470((hero *)(f_030810())) && sel != 0x3b && sel != 0x21) {
                        d_1c2c64.f_0bf730(0x1700005eL);
                        sel = -1;
                    }
                }
        }
        } else code = 0;
    } else {
        sel = f_0433d0();
    }

    if (sel > 0) {
            p = &d_1a7270[sel];
            if ((unsigned short)d_1bd90c == (unsigned short)0 && p->b5 == 1) {
                code = 0x20000167L;
                r = -1;
                d_1c040e = 1;
            } else if ((unsigned short)d_1bd90c != (unsigned short)0 && p->b5 == -1) {
                code = 0x20000168L;
                r = -1;
                d_1c040e = 1;
            }
            if (r != -1) {
                Sp o(this);
                r = o.f_10ce80(sel, arg);
                ok = r ^ r;
            }
    } else {
            d_1c040e = 1;
            r = -1;
            code = 0;
    }
fertig:
    if ((unsigned short)d_1bd90c == (unsigned short)0 && ok != 0 && code != 0) d_1c2c64.f_0bf730(code);
    d_1c2c64.f_0bf680();
    memset(&d_1c0420, 0, 0xb);
    return r;
}

//@ f_03d790
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt ein Zaubereffekt-Fenster (Eff) für einen einzelnen Attribut-/Statuswert a des Helden
 *   e und spielt die zugehörige visuelle Effektanimation über Eff::f_134910() ab.
 * - Eingaben:
 *   - e (Zeiger auf den betroffenen Helden Ent).
 *   - a (Index des betroffenen Attributs oder Statuswerts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - w (Lokales Effekt-Objekt Eff).
 === Ende Beschreibung === */
void f_03d790(Ent *e, short a)
{
    Eff w(e, e, a, ::f_042a60((hero *)(e), a), 1);
    w.f_134910();
}

//@ f_03d7d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt ein Zaubereffekt-Fenster (Eff) für zwei Attribut-/Statuswerte a und b desselben
 *   Helden e und spielt die Doppelwert-Effektanimation über Eff::f_134d50() ab.
 * - Eingaben:
 *   - e (Zeiger auf den betroffenen Helden Ent).
 *   - a (Erster Attribut-/Status-Index).
 *   - b (Zweiter Attribut-/Status-Index).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - w (Lokales Effekt-Objekt Eff).
 === Ende Beschreibung === */
void f_03d7d0(Ent *e, short a, short b)
{
    Eff w(e, a, ::f_042a60((hero *)(e), a), b, ::f_042a60((hero *)(e), b), 1);
    w.f_134d50();
}

//@ f_03d820
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt ein Zaubereffekt-Fenster (Eff) für eine Übertragung oder Wirkung zwischen dem
 *   zaubernden Helden e und dem Ziel-Helden e2 bezüglich des Attribut-/Statuswerts a und startet die Animation
 *   über Eff::f_13bc30().
 * - Eingaben:
 *   - e (Zeiger auf den ersten/zaubernden Helden Ent).
 *   - e2 (Zeiger auf den zweiten/betroffenen Helden Ent).
 *   - a (Index des betroffenen Attributs oder Statuswerts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - w (Lokales Effekt-Objekt Eff).
 === Ende Beschreibung === */
void f_03d820(Ent *e, Ent *e2, short a)
{
    Eff w(e, e2, a, ::f_042a60((hero *)(e2), a), 1);
    w.f_13bc30();
}

//@ f_03d860
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft im Heldendatensatz e innerhalb des 27-Byte-Eintrags a ab Offset +0x1a8
 *   (Ausrüstungs-/Inventarslot a, Feld +0xb), ob das Bit mit der Nummer bit gesetzt ist.
 * - Eingaben:
 *   - e (Zeiger auf den Helden Ent).
 *   - a (Slot-Index des 27-Byte-Eintrags ab Offset +0x1a8).
 *   - bit (Bitposition 0..31, berechnet über Linksrotation _lrotl(1, bit)).
 * - Rückgabewert: int - 1, wenn das Bit gesetzt ist, sonst 0.
 * - Wichtige Variablen:
 *   - p (Zeiger auf das 32-Bit-Bitfeld bei (char *)e + 0x1a8 + a * 27 + 0xb).
 *   - mask (Rotationsmaske 1 << bit).
 === Ende Beschreibung === */
int f_03d860(Ent *e, short a, short bit)
{
    int r = 0;
    unsigned long *p = (unsigned long *)((char *)e + 0x1a8 + a * 27 + 0xb);
    unsigned long v = *p;
    unsigned long mask = _lrotl(1, bit);
    if ((mask & v) != 0) r = 1;
    return r;
}

//@ f_03d8b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt (on != 0) oder löscht (on == 0) im Heldendatensatz e innerhalb des 27-Byte-Eintrags a
 *   ab Offset +0x1a8 (Feld +0xb) das Bit mit der Nummer bit.
 * - Eingaben:
 *   - e (Zeiger auf den Helden Ent).
 *   - a (Slot-Index des 27-Byte-Eintrags ab Offset +0x1a8).
 *   - bit (Bitposition 0..31).
 *   - on (Schaltwert: 0 zum Löschen, != 0 zum Setzen des Bits).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p (Zeiger auf das 32-Bit-Bitfeld bei (char *)e + 0x1a8 + a * 27 + 0xb).
 *   - m (Bitmaske _lrotl(1, bit)).
 === Ende Beschreibung === */
void f_03d8b0(Ent *e, short a, short bit, int on)
{
    char *q = (char *)e + 0x1a8 + a * 27; unsigned long v = *(unsigned long *)(q + 0xb); unsigned long *p = (unsigned long *)e; p = (unsigned long *)(q + 0xb);
    unsigned long m = _lrotl(1, bit);
    if (!(short)on) *p = v & ~m; else *p = v | m;
}

