/* === Beschreibung (Katalog) ===
 * Einheit gz_032ab0 (0x00032ab0 - 0x00033d40)
 *
 * Überblick
 *
 * Die Einheit gz_032ab0 implementiert den ersten Teil der Charakter-Ausrüstungs- und Inventarlogik (CH_ITEM.CPP)
 * für die 31 Inventarslots eines Helden (0..14 Körperslots am Charaktermodell, 15..30 Rucksackslots, je 27 =
 * 0x1b Bytes groß ab Offset +0x1a8). Sie regelt das Verschieben, Tauschen und Zusammenstapeln von Gegenständen
 * zwischen Körper und Rucksack, prüft Körperzonen, Klassenverbote und Zweihandwaffen-Konflikte und verrechnet
 * beim An- und Ablegen von Rüstungen, Waffen und magischen Schmuckstücken/Gürteln deren Auswirkungen auf
 * Rüstungsschutz, Behinderung, Waffenwerte, Eigenschaften, Talente und Magieresistenz.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 8/10 gleich (suche.py 29.10.2026, Basis gz_032ab0_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 916 (vorher 917)
// gz_032ab0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x032AB0-0x033D40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
char f_042380(int p1);                                   // reg eax stapel 0
char f_042470(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_042ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_042b50(int p1, int p2);                           // reg eax edx stapel 0
int f_042c40(int p1, int p2);                           // reg eax edx stapel 0
int f_042d00(int p1, int p2);                           // reg eax edx stapel 0
short f_042fd0(int p1, short p2);                       // reg eax edx stapel 0
int f_043000(int p1, short p2, signed char p3);         // reg eax edx ebx stapel 0
signed char f_043030(int p1, short p2);                 // reg eax edx stapel 0
int f_043060(int p1, short p2, signed char p3);         // reg eax edx ebx stapel 0
int f_043130(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0449d0(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_068380(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
int f_149360(int p1, int p2);
extern int d_1a48a8;
extern signed char d_1a4421[]; extern signed char d_1a4422[]; extern signed char d_1a47ac[]; extern signed char d_1a47ad[];
extern int d_1bc890;
extern int d_1bc8f4;
extern int d_1c2a80;

extern int d_1c2c64;
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
#define A(x) ((int)&(x))
#define S(x) (*(short *)(x))
#define C(x) (*(char *)(x))
struct Msg { int h; int *a; int x; int *b; int *c; short *d; int z[2]; short *e; int pad[6]; };
struct Item { char b[27]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
int f_032ab0(int p1, short p2, short p3);
int f_033250(int p1, int p2);
int f_033260(int p1, short p2, int p3);
int f_033450(int p1, short p2, int p3, int p4, int p5);
int f_033530(int p1, int p2);
short f_033590(int p1, int p2);
void f_0335d0(int p1, int p2, int p3);
void f_0338a0(int p1, int p2, short p3, int p4, int p5);
short f_033c50(int p1, short p2, signed char p3);
void f_033ce0(int p1);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_032ab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt oder tauscht Gegenstände zwischen den beiden Slots p2 und p3 (0..30) desselben Helden
 *   p1:
 *   1. Prüft vorab, ob der Held handlungsfähig ist (f_0d4a60), ob die Charakterklasse den Gegenstand tragen darf
 *     (f_045960), ob der Ziel-Körperslot (< 15) zum Gegenstandstyp passt (f_033260) und ob eine Zweihandwaffe
 *     die Nebenhand blockiert (f_033450).
 *   2. Werden Körperslots (< 15) verändert, zieht f_0335d0 die bisherigen Rüstungs-, Waffen- und Attributsboni
 *     ab und f_0338a0 rechnet die neuen Boni an.
 *   3. Sind beide Slots mit demselben stapelbaren Gegenstand belegt (a == b und f_0a7950()), werden die Mengen
 *     bis zur Obergrenze 99 zusammengeführt und eventuelle Giftladungen übertragen. *(Hinweis: Hier liegt ein
 *     Originalfehler vor: Im Zweig für eine Gesamtmenge <= 99 fehlt bei unterschiedlicher Giftart der else-Zweig
 *     n2 = n3, sodass beim Auflegen vergifteter Pfeile/Waffen auf einen unvergifteten Stapel sämtliche
 *     Giftladungen verloren gehen!)*
 *   4. Andernfalls werden die beiden 27-Byte-Inventareinträge (Item) ausgetauscht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 sowie die beiden Slot-Indizes p2 und p3
 *   (0..30) und gibt 1 zurück, wenn die Bewegung erfolgreich durchgeführt wurde, sonst 0.
 * - Wichtige Variablen: Bearbeitet die 27-Byte-Inventarslots p1 + 0x1a8 + slot * 27 (Item-ID bei +0x1a8,
 *   Stückzahl bei +0x1aa) und nutzt die Hilfsfunktionen f_033260, f_033450, f_0335d0 und f_0338a0.
 === Ende Beschreibung === */
struct MsgDtor {
    int h; int *a; int x; int *b; int *c; short *d; int z[2]; short *e; int pad[6];
    ~MsgDtor() { f_1254a0((int)this, 0); }
};
int f_032ab0(int p1, short p2, short p3)
{
    int f_042870(int, int);
    int done = 0;
    MsgDtor m;
    f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    m.a[1] = p1;

    if (!f_0d4a60(p1) || p2 == p3) {
        if (p2 == p3)
            done = 1;
        else
            f_0bf730(A(d_1c2c64), 0x3040052);
        return done;
    }

    short b;
    short a;
    if (p3 >= 15 && p2 >= 15) {
        done = 1;
        a = S(p1 + p2 * 27 + 0x1a8);
        b = S(p1 + p3 * 27 + 0x1a8);
    } else {
        a = S(p1 + p2 * 27 + 0x1a8);
        b = S(p1 + p3 * 27 + 0x1a8);
        if (p3 < p2 || (p2 < 15 && p3 < 15)) {
            if (p2 < 15) {
                if (a != (short)0) done = 1;
            } else {
                done = 1;
            }
            if (done == 1) {
                short t = p2;
                p2 = p3;
                p3 = t;
                t = a;
                a = b;
                b = t;
            }
        }
        done = 0;
        if (a == (short)0 && b == (short)0) {
            f_0bf730(A(d_1c2c64), 0x5010018);
        } else if (b != (short)0) {
            int slot_value;
            if (a == b && d_1c2c40[a]->f_0a7950()) {
                done = 1;
            } else if (!f_045960(p1, b)) {
                m.c[1] = f_040e90(p1);
                m.b[1] = (int)d_1c2c40[b];
                m.e[1] = 1;
                f_0bf730(A(d_1c2c64), 0x20000106);
            } else if (!f_033260(p1, b, p2)) {
                m.b[1] = (int)d_1c2c40[b];
                m.e[1] = 1;
                if (d_1c2c40[b]->f_0a7ad0() ||
                    ((short)f_042ac0(p1, p3) > 1 && d_1c2c40[b]->f_0a7950())) {
                    m.c[1] = 0x20000108;
                    m.e[1] = f_042ac0(p1, p3);
                } else {
                    m.c[1] = 0x20000109;
                }
                f_0bf6c0(A(d_1c2c64), 6);
                f_0bf730(A(d_1c2c64), 0x20000107);
                f_0bf680(A(d_1c2c64));
            } else if (a != (short)0 && p3 < 15 && !f_033260(p1, a, p3)) {
                m.b[1] = (int)d_1c2c40[a];
                m.e[1] = 1;
                if (d_1c2c40[a]->f_0a7ad0() ||
                    ((short)f_042ac0(p1, p2) > 1 && d_1c2c40[a]->f_0a7950())) {
                    m.c[1] = 0x20000108;
                    m.e[1] = f_042ac0(p1, p2);
                } else {
                    m.c[1] = 0x20000109;
                }
                f_0bf6c0(A(d_1c2c64), 6);
                f_0bf730(A(d_1c2c64), 0x20000107);
                f_0bf680(A(d_1c2c64));
            } else if (f_033450(p1, b, slot_value = p2, p1, p3)) {
                f_0bf730(A(d_1c2c64), 0x2000010a);
            } else {
                if (a != (short)0 && slot_value < 15)
                    f_0335d0(p1, a, slot_value);
                if (p3 < 15)
                    f_0335d0(p1, b, p3);
                f_0338a0(p1, p1, b, p3, p2);
                if (a != (short)0 && p3 < 15)
                    f_0338a0(p1, p1, a, p2, p3);
                done = 1;
            }
        } else {
            f_0335d0(p1, a, p2);
            done = 1;
        }
    }

    if (done == 1) {
        if (a == b && d_1c2c40[a]->f_0a7950()) {
            if (S(p1 + p2 * 27 + 0x1aa) + S(p1 + p3 * 27 + 0x1aa) > 99) {
                if (f_043030(p1, p3) > 0) {
                    short count, n2, room, kind3, kind2, n3;
                    room = 99 - S(p1 + p2 * 27 + 0x1aa);
                    n3 = 0;
                    n3 = f_043030(p1, p3);
                    kind3 = f_042fd0(p1, p3);
                    { short u_ = kind3; kind3 = u_; } // Haelt Registerzuteilung fuer kind3 im Ueberlaufzweig
                    n2 = f_043030(p1, p2);
                    kind2 = f_042fd0(p1, p2);
                    if (n3 < room)
                        count = n3;
                    else
                        count = room;
                    if (kind3 == kind2)
                        n2 += count;
                    else
                        n2 = count;
                    kind2 = kind3;
                    f_043000(p1, p2, kind2);
                    f_043060(p1, p2, n2);
                    count = n3 - room;
                    if (count <= 0) {
                        f_043000(p1, p3, 0);
                        count = 0;
                    }
                    f_043060(p1, p3, count);
                }
                S(p1 + p3 * 27 + 0x1aa) =
                    S(p1 + p2 * 27 + 0x1aa) + S(p1 + p3 * 27 + 0x1aa) - 99;
                S(p1 + p2 * 27 + 0x1aa) = 99;
            } else {
                if (f_043030(p1, p3) > 0) {
                    short kind2, kind3, n3, n2;
                    n3 = p3; // Haelt fruehe Namenssortierung im Stapelzweig
                    n3 = f_043030(p1, p3);
                    kind3 = f_042fd0(p1, p3);
                    n2 = f_043030(p1, p2);
                    kind2 = n2; // Haelt fruehe Namenssortierung im Stapelzweig
                    kind2 = f_042fd0(p1, p2);
#if FIX_R021   /* R021: Giftladungen n2 = n3 beim Stapeln auf unvergiftete Projektile uebernehmen */
                    if (kind3 == kind2) n2 += n3;
                    else n2 = n3;
#else
                    if (kind3 == kind2) n2 += n3;
#endif
                    kind2 = kind3;
                    f_043000(p1, p2, kind2);
                    f_043060(p1, p2, n2);
                }
                S(p1 + p2 * 27 + 0x1aa) += S(p1 + p3 * 27 + 0x1aa);
                memset((void *)(p1 + 0x1a8 + p3 * 27), 0, 27);
                f_042870(p1, -1);
            }
        } else {
            Item temp = *(Item *)(p1 + p2 * 27 + 0x1a8);
            done = (done & 0) ? 0 : done; // Haelt done ueber den 27-Byte-Kopierblock im selben Slot
            *(Item *)(p1 + p2 * 27 + 0x1a8) = *(Item *)(p1 + p3 * 27 + 0x1a8);
            *(Item *)(p1 + p3 * 27 + 0x1a8) = temp;
        }
    }
    { short u_ = p3; p3 = u_; } // Haelt Lebensdauer von p3 bis Funktionsende fuer die Registerzuteilung
    return done;
}
//@ f_033250
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft über f_045960(p1, p2), ob der Held p1 aufgrund seines Heldentypus den Gegenstand mit der
 *   Item-ID p2 grundsätzlich anlegen darf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 und die Gegenstands-ID p2 entgegen und gibt 1
 *   bei Erlaubnis oder 0 bei Verbot zurück.
 * - Wichtige Variablen: Delegiert direkt an f_045960.
 === Ende Beschreibung === */
int f_033250(int p1, int p2)
{
    return f_045960(p1, (short)p2);
}
//@ f_033260
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Überprüft anhand der Item-Flags in d_1c2c40[p2], ob der Gegenstand p2 im Körperslot p3
 *   getragen werden darf: Waffen (f_0a7990() != 0) dürfen nur in die rechte Hand (Slot 3) oder linke Hand (Slot
 *   12), Helme/Kopfbedeckungen nach Slot 0, Arm-/Bein-/Brust-/Schuh- und Ringslots (1, 2, 4, 5, 6, 7, 8, 9, 10,
 *   11, 13, 14) jeweils nur zu den passenden Rüstungs- und Schmuckkategorien, während sonstige Gegenstände
 *   (f_0a7990() == 0) auch in den beiden Handslots (3 und 12) gehalten werden können.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die Item-ID p2 und die Zielslot-Nummer p3
 *   und gibt 1 zurück, wenn der Slot zulässig ist, sonst 0.
 * - Wichtige Variablen: Wertet die Typ- und Körperzonenmethoden f_0a78b0 bis f_0a7a80 von RivaItemDefinition in
 *   d_1c2c40[p2] aus.
 === Ende Beschreibung === */
int f_033260(int p1, short p2, int p3)
{
    int result = 0;
    if (p2 == 0) {
        result = 1;
    } else {
        if (d_1c2c40[p2]->f_0a7990()) {
            if ((short)p3 == 3 || (short)p3 == 12) result = 1;
            else result = 0;
        } else if (((short)p3 == 0 && (signed char)d_1c2c40[p2]->f_0a78b0() == 0 && d_1c2c40[p2]->f_0a79b0())
            || ((short)p3 == 0 && d_1c2c40[p2]->f_0a7a60())
            || ((short)p3 == 10 && (signed char)d_1c2c40[p2]->f_0a78b0() == 10)
            || ((short)p3 == 5 && (signed char)d_1c2c40[p2]->f_0a78b0() == 5)
            || ((short)p3 == 14 && (signed char)d_1c2c40[p2]->f_0a78b0() == 14)
            || ((short)p3 == 7 && d_1c2c40[p2]->f_0a79c0())
            || ((short)p3 == 8 && d_1c2c40[p2]->f_0a7a20())
            || ((short)p3 == 9 && d_1c2c40[p2]->f_0a7a40())
            || (((short)p3 == 2 || (short)p3 == 11) && d_1c2c40[p2]->f_0a7a00())
            || (((short)p3 == 4 || (short)p3 == 13) && d_1c2c40[p2]->f_0a79e0())
            || (((short)p3 == 6 || (short)p3 == 1) && d_1c2c40[p2]->f_0a7a80())
            || (short)p3 == 3 || (short)p3 == 12)
            result = 1;
    }
    return result;
}
//@ f_033450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt beim Ablegen eines Gegenstands p2 in die rechte Hand (Slot 3) oder linke Hand (Slot 12)
 *   fest, ob in der jeweils anderen Hand (s5 = 12 bzw. 3) bereits ein Gegenstand liegt und einer der beiden
 *   Gegenstände eine Zweihandwaffe ist (f_0a7990() != 0 und Waffenuntertyp f_0a78b0() == 6).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zielhelden p1, die Item-ID p2, den Zielslot p3, den
 *   Quellhelden p4 und den Quellslot p5 entgegen und gibt 1 bei einem Zweihand-Konflikt zurück, sonst 0.
 * - Wichtige Variablen: Prüft die beiden Handslots 3 und 12 (0x0c) an p1 + 0x1a8 + slot * 0x1b.
 === Ende Beschreibung === */
int f_033450(int p1, short p2, int p3, int p4, int p5)
{
    int ret;
    short s5, s1;
    ret = 0;
    if ((short)p3 == 3 || (short)p3 == 0xc) {
        s5 = 3;
        if ((short)p3 == 3) s5 = 0xc;
        s1 = S(p1 + 0x1a8 + s5 * 0x1b);
        if (s1 != (short)0 && (p1 != p4 || s5 != (short)p5)) {
            if ((d_1c2c40[(short)p2]->f_0a7990() != 0 && (signed char)d_1c2c40[(short)p2]->f_0a78b0() == 6)
                || (d_1c2c40[(short)s1]->f_0a7990() != 0 && (signed char)d_1c2c40[(short)s1]->f_0a78b0() == 6)) {
                ret = 1;
            }
        }
    }
    return ret;
}
//@ f_033530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für den Gegenstand im Slot p2 des Helden p1, ob er nicht gesperrt (f_0a78f0() == 0) und
 *   nicht in der Ausnahmeliste d_1a48a8 enthalten ist, und löst anschließend über f_036300(p1, p2, menge) dessen
 *   Benutzung (etwa Trank trinken, Kraut essen oder Gegenstand anwenden) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Slot-Index p2 und gibt den
 *   Rückgabewert von f_036300 (oder 0) zurück.
 * - Wichtige Variablen: Liest Item-ID (f_042a60) und Stückzahl (f_042ac0) des Slots und prüft die Sperrliste
 *   d_1a48a8.
 === Ende Beschreibung === */
int f_033530(int p1, int p2)
{
    int p2_00 = (short)p2;
    short s;
    int r;
    s = f_042a60(p1, p2_00);
    r = 0;
    if (d_1c2c40[s]->f_0a78f0() == 0) {
        s = f_042a60(p1, p2_00);
        s = f_149360((int)s, A(d_1a48a8));
        if (s == -1) {
            s = f_042ac0(p1, p2_00);
            r = f_036300(p1, p2_00, (int)s);
        }
    }
    return r;
}
//@ f_033590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle 31 Inventarslots (0 bis 30) des Helden p1 nach einem bereits vorhandenen
 *   Stapel der Gegenstands-ID p2, dessen Stückzahl noch unter 99 liegt.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 und die gesuchte Item-ID p2 entgegen und gibt
 *   den gefundenen Slot-Index (0..30) oder -1 zurück.
 * - Wichtige Variablen: Prüft S(b + 0x1a8) == p2 und S(b + 0x1aa) < 99 für alle 31 Slots.
 === Ende Beschreibung === */
short f_033590(int p1, int p2)
{
    short i;
    int b;
    for (i = 0; (short)i < 0x1f; i = i + 1) {
        b = (short)i * 0x1b + p1;
        if ((short)p2 == S(b + 0x1a8) && S(b + 0x1aa) < 99) return i;
    }
    return -1;
}
//@ f_0335d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Nimmt beim Entfernen des Gegenstands p2 aus dem Körperslot p3 (0..14) sämtliche passiven
 *   Ausrüstungseffekte vom Helden p1 zurück:
 *   1. Bei Rüstungen und Schilden (f_0a79b0() != 0, außer nicht-Schild-Items in den Handslots 3/12) werden
 *     Rüstungsschutz (p1 + 0x42, abzüglich eventueller Rüstungsabnutzung p1 + 0x1af + p3 * 0x1b) und Behinderung
 *     (p1 + 0x44) anhand der Tabellen d_1a47ac und d_1a47ad abgezogen.
 *   2. Wird eine Waffe aus der rechten Hand (p3 == 3) genommen, setzt f_043130(p1, 0, 0, 0) die aktuellen
 *     AT-/PA-Waffenmodifikatoren auf waffenlos zurück.
 *   3. Wird eines der magischen Schmuckstücke, Amulette oder Gürtel (0xb7 Kraftgürtel KK-5, 0xc4 Attr2+1, 0xd7
 *     Attr11+2, 0xd9/0xa5 MR-2, 0xb6 Attr11+4, 0x143 Attr8+3, 0x144 CH-5, 0x1ab FF-4, 0x1ba Schleichen-4, 0x195
 *     MR-5) von einem Körperslot außerhalb der Hände (p3 != 3 && p3 != 12) abgelegt, wird dessen Eigenschafts-,
 *     Talent- oder Magieresistenz-Bonus rückgängig gemacht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die abgelegte Item-ID p2 und die
 *   Körperslot-Nummer p3 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ändert RS (p1 + 0x42), BE (p1 + 0x44), Waffenwerte (f_043130), Attribute (f_045430),
 *   Talente (f_03af20), Magieresistenz (f_0449d0) und setzt bei Änderungen das Neuzeichnungsflag d_1bc890 = 1.
 === Ende Beschreibung === */
void f_0335d0(int p1, int p2, short p3)
{
    signed char c1, c2, c3;
    int t;
    if (!(short)p2) return;
    if (d_1c2c40[(short)p2]->f_0a79b0() != 0 &&
        (((short)p3 != 3 && (short)p3 != 0xc) || (signed char)d_1c2c40[(short)p2]->f_0a78b0() == 9)) {
        c2 = C(p1 + 0x42);
        c1 = C(p1 + 0x44);
        C(p1 + 0x42) -= d_1a47ac[(signed char)d_1c2c40[(short)p2]->f_0a78a0() * 2];
        C(p1 + 0x42) = C(p1 + 0x42) + C(p1 + 0x1af + (short)p3 * 0x1b);
        C(p1 + 0x44) -= d_1a47ad[(signed char)d_1c2c40[(short)p2]->f_0a78a0() * 2];
        if ((signed char)C(p1 + 0x42) != c2 || c1 != (signed char)C(p1 + 0x44)) d_1bc890 = 1;
    }
    if (d_1c2c40[(short)p2]->f_0a7990() != 0 && (short)p3 == 3) {
        f_043130(p1, 0, 0, 0);
        d_1bc890 = 1;
    }
    if ((short)p3 != 3 && (short)p3 != 0xc) {
        if ((short)p2 == 0xb7) {
            f_045430(p1, 6, -5);
            d_1bc890 = 1;
        } else if ((short)p2 == 0xc4) { f_045430(p1, 2, 1); d_1bc890 = 1; return; }
        else if ((short)p2 == 0xd7) { f_045430(p1, 0xb, 2); d_1bc890 = 1; }
        else if ((short)p2 == 0xd9 || (short)p2 == 0xa5) { f_0449d0(p1, -2); d_1bc890 = 1; return; }
        else if ((short)p2 == 0xb6) { f_045430(p1, 0xb, 4); d_1bc890 = 1; return; }
        else if ((short)p2 == 0x143) { f_045430(p1, 8, 3); d_1bc890 = 1; return; }
        else if ((short)p2 == 0x144) { f_045430(p1, 2, -5); d_1bc890 = 1; return; }
        else if ((short)p2 == 0x1ab) { f_045430(p1, 3, -4); d_1bc890 = 1; return; }
        else if ((short)p2 == 0x1ba) { f_03af20(p1, 0xe, -4); d_1bc890 = 1; return; }
        else if ((short)p2 == 0x195) { f_0449d0(p1, -5); d_1bc890 = 1; }
    }
}
//@ f_0338a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Rechnet beim Anlegen des Gegenstands p3 in den Körperslot p5 (0..14) alle Ausrüstungseffekte
 *   auf den Helden p1 an: Aktualisiert im Charakterbogen die Papierpuppen-Grafik (f_068380), addiert
 *   Rüstungsschutz (d_1a47ac abzüglich Schadensmalus f_042b50) und Behinderung (d_1a47ad), trägt bei Waffen in
 *   der rechten Hand (p5 == 3) die AT-/PA-Modifikatoren aus d_1a4421/d_1a4422 über f_043130 ein und verleiht bei
 *   den besonderen Gegenständen (0xb7, 0xc4, 0xd7, 0xd9, 0xa5, 0xb6, 0x143, 0x144, 0x1ab, 0x1ba, 0x195)
 *   außerhalb der Handslots die jeweiligen Attributs-, Talent- und Magieresistenz-Zuschläge.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zielhelden p1, den Quellhelden p2, die Item-ID p3, den
 *   Quellslot p4 und den Ziel-Körperslot p5 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gegenstück zu f_0335d0; setzt bei Wertänderungen ebenfalls d_1bc890 = 1.
 === Ende Beschreibung === */
void f_0338a0(int p1, int p2, short p3, int p4, int p5)
{
    char o42, o44;
    char o8a, o88, o89;
    if (!p3 || (short)p5 >= 15) return;

    if (d_1c2a80 == 0x30000 && p1 == d_1bc8f4)
        f_068380((signed char)f_042380(p1), (short)p5, p3);

    if (d_1c2c40[p3]->f_0a79b0() != 0
        && (((short)p5 != 3 && (short)p5 != 0xc) || (signed char)d_1c2c40[p3]->f_0a78b0() == 9)) {
        o42 = C(p1 + 0x42);
        o44 = C(p1 + 0x44);
        { char u_ = o44; o44 = u_; } { char u_ = o44; o44 = u_; } // Haelt Registergewicht fuer o44 im Ruestungszweig
        C(p1 + 0x42) += d_1a47ac[(signed char)d_1c2c40[p3]->f_0a78a0() * 2];
        if ((short)p4 != -1)
            C(p1 + 0x42) -= (signed char)f_042b50(p2, (short)p4);
        C(p1 + 0x44) += d_1a47ad[(signed char)d_1c2c40[p3]->f_0a78a0() * 2];
        if (o42 != C(p1 + 0x42) || o44 != C(p1 + 0x44)) d_1bc890 = 1;
    }

    if (d_1c2c40[p3]->f_0a7990() != 0 && (short)p5 == 3) {
        o8a = C(p1 + 0x8a);
        o88 = C(p1 + 0x88);
        o89 = C(p1 + 0x89);
        { char u_ = o89; o89 = u_; } { char u_ = o89; o89 = u_; } { char u_ = o89; o89 = u_; } { char u_ = o89; o89 = u_; } { char u_ = o89; o89 = u_; } // Haelt Registergewicht fuer o89 im Waffenzweig
        f_043130(p1, (signed char)d_1c2c40[p3]->f_0a78b0(),
                 d_1a4421[(signed char)d_1c2c40[p3]->f_0a78a0() * 10],
                 d_1a4422[(signed char)d_1c2c40[p3]->f_0a78a0() * 10]);
        if (o8a != C(p1 + 0x8a) || o88 != C(p1 + 0x88) || o89 != C(p1 + 0x89)) d_1bc890 = 1;
    }

    if ((short)p5 == 3 || (short)p5 == 0xc) return;

    if (p3 == 0xb7) { f_045430(p1, 6, 5); d_1bc890 = 1; }
    else if (p3 == 0xc4) { f_045430(p1, 2, -1); d_1bc890 = 1; }
    else if (p3 == 0xd7) { f_045430(p1, 0xb, -2); d_1bc890 = 1; }
    else if (p3 == 0xd9 || p3 == 0xa5) { f_0449d0(p1, 2); d_1bc890 = 1; }
    else if (p3 == 0xb6) { f_045430(p1, 0xb, -4); d_1bc890 = 1; }
    else if (p3 == 0x143) { f_045430(p1, 8, -3); d_1bc890 = 1; }
    else if (p3 == 0x144) { f_045430(p1, 2, 5); d_1bc890 = 1; }
    else if (p3 == 0x1ab) { f_045430(p1, 3, 4); d_1bc890 = 1; }
    else if (p3 == 0x1ba) { f_03af20(p1, 0xe, 4); d_1bc890 = 1; }
    else if (p3 == 0x195) { f_0449d0(p1, 5); d_1bc890 = 1; }
}

//@ f_033c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das unterste Bit (enabled) im Statusfeld p1 + 0x1ac + p2 * 0x1b eines im
 *   Slot p2 getragenen Gegenstands, sofern dieser laut f_042d00(p1, p2) schaltbar ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Slot-Index p2 und den neuen Bitwert p3
 *   (0 oder 1) und gibt 1 zurück, wenn die Änderung durchgeführt wurde, sonst 0.
 * - Wichtige Variablen: Modifiziert Bit 0 des Bytes an p1 + 0x1ac + p2 * 0x1b.
 === Ende Beschreibung === */
short f_033c50(int p1, short p2, signed char p3)
{
    struct Flag { unsigned short enabled:1; };
    int r = 1;
    r = 0; // Toter Startwert erhaelt die Registerverteilung von Watcom.
    if (f_042d00(p1, (short)p2) != 0 && (p3 == (signed char)0 || (C(p1 + 0x1ac + (short)p2 * 0x1b) & 1) == 0)) {
        int q;
        q = p1 + (short)p2 * 0x1b;
        ((Flag *)(q + 0x1ac))->enabled = p3;
        r = 1;
    }
    return r;
}
//@ f_033ce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft für einen lebenden Helden p1 alle 31 Inventarslots (0 bis 30) und ruft für jede
 *   darin gefundene Waffe (f_0a7990() != 0) zweimal hintereinander die Funktion f_042c40(p1, slot) auf (etwa bei
 *   Säure-, Rost- oder Fallenwirkung auf die Waffen des Helden).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft alle 31 Slots an p1 + 0x1a8 + p2 * 0x1b über d_1c2c40.
 === Ende Beschreibung === */
void f_033ce0(int p1)
{
    short s, v;
    int p2, i;
    if (!f_042470(p1)) {
        for (s = 0; (p2 = s) < 0x1f; s = s + 1) {
            v = S(p1 + 0x1a8 + p2 * 0x1b);
            if (v != 0) {
                i = d_1c2c40[v]->f_0a7990();
                if (i != 0) {
                    f_042c40(p1, p2);
                    f_042c40(p1, p2);
                }
            }
        }
    }
}
