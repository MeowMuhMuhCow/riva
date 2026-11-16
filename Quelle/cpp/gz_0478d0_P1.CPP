/* === Beschreibung (Katalog) ===
 * Einheit gz_0478d0 (0x0478d0 - 0x0480a0)
 *
 * Überblick
 * Die Einheit gz_0478d0 enthält die Ereignis- und Gebäudeverteiler für das Betreten von Tavernen, Herbergen und
 * besonderen Bürgerhäusern in der Stadt Riva. Je nach aktuellem Quest-Fortschritt (Flags d_1c00a0-d_1c01c8 und
 * d_1bed7c-d_1bee1c) verzweigen diese Funktionen entweder in spezielle Story-Begegnungen und Dialoge (f_0ea560
 * bis f_0ed1c0, f_11e240) oder öffnen den regulären Tavernen-/Herbergsbetrieb (f_11e500) mit einer Liste der
 * dort verfügbaren Wirtsstuben-Ereignisse.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 11/15 gleich (suche.py 24.10.2026, Basis gz_0478d0_P1.CPP)
// gz_0478d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0478D0-0x0480A0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0d6690(int p1);                                   // reg eax stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd6d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0ea840();                                         // reg - stapel 0
int f_0ea980();                                         // reg - stapel 0
int f_0eab60();                                         // reg - stapel 0
int f_0eac00();                                         // reg - stapel 0
int f_0eadd0();                                         // reg - stapel 0
int f_0ec150();                                         // reg - stapel 0
int f_0ecc70();                                         // reg - stapel 0
int f_0ecdd0();                                         // reg - stapel 0
int f_0ed1c0();                                         // reg - stapel 0
                           // reg eax stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_11e240();                                         // reg - stapel 0

int f_1223c0();                                         // reg - stapel 0
struct Ob { int a; int *p; char pad[0x34]; };
int f_125400(Ob *o, int *p2, int *p3, int *p4);
int f_1254a0(Ob *o, int fl = 0);
int f_126410(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1bc91c;
extern short d_1bc91d;
extern signed char d_1bc920;
extern short d_1bc921;
extern signed char d_1bcaa0;
extern signed char d_1bed7c;
extern signed char d_1bed80;
extern signed char d_1bedb8;
extern signed char d_1bedfc;
extern signed char d_1bee18;
extern signed char d_1bee1c;
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c00a0;
extern signed char d_1c00a4;
extern signed char d_1c00a8;
extern signed char d_1c00b0;
extern signed char d_1c00bc;
extern signed char d_1c00c0;
extern signed char d_1c00c4;
extern signed char d_1c00c8;
extern signed char d_1c00d0;
extern signed char d_1c00d4;
extern int d_1c00e0;                    // 0x1C00E0
extern int d_1c00e4;                    // 0x1C00E4
extern signed char d_1c0178;
extern signed char d_1c01c8;
extern int d_1c01dc;                    // 0x1C01DC
extern signed char d_1c0ca4;
extern signed char d_1c0d64;
extern unsigned short d_1c212a;
extern int *d_1c212c;
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a663c[];           // Text 0x1A663C
// --- eigene Funktionen (15), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1c3498;
int f_11e500(int, ...);
void f_0ea560();int f_0eabb0();int f_0eafa0();int f_0ed040();int f_0ec7b0();
#define P(x) ((int)&(x))
static inline int q_a8_1() { return d_1c00a8 == 1; }
static inline int q_edb8_0() { return d_1bedb8 == 0; }
static inline int q_c4_0() { return d_1c00c4 == 0; }
static inline int q_l178_1() { return d_1c0178 == 1; }
static inline int q_caa0_0() { return d_1bcaa0 == 0; }
static inline int q_caa0_1() { return d_1bcaa0 == 1; }
static inline int q_l1c8_1() { return d_1c01c8 == 1; }
static inline int q_c8_0() { return d_1c00c8 == 0; }
static inline int q_c8_1() { return d_1c00c8 == 1; }
static inline int q_ed7c_0() { return d_1bed7c == 0; }
static inline int q_edfc_lt() { return d_1bedfc < 0x1e; }
static inline int q_edfc_gt() { return d_1bedfc > 0; }
static inline int q_c91c_0() { return d_1bc91c == 0; }
static inline int q_a0_1() { return d_1c00a0 == 1; }
static inline int q_a0_0() { return d_1c00a0 == 0; }
static inline int q_bc_0() { return d_1c00bc == 0; }
static inline int q_bc_1() { return d_1c00bc == 1; }
static inline int q_d4_1() { return d_1c00d4 == 1; }
static inline int q_ed80_1() { return d_1bed80 == 1; }
static inline int q_a4_1() { return d_1c00a4 == 1; }
static inline int q_ee1c_0() { return d_1bee1c == 0; }
static inline int q_ee1c_1() { return d_1bee1c == 1; }
static inline int q_c920_0() { return d_1bc920 == 0; }
static inline int q_ee18_1() { return d_1bee18 == 1; }
static inline int q_c0_0() { return d_1c00c0 == 0; }
static inline int q_d0_0() { return d_1c00d0 == 0; }
static inline int q_b0_0() { return d_1c00b0 == 0; }
static inline int q_d64_1() { return d_1c0d64 == 1; }
static inline int q_ca4_ne0() { return d_1c0ca4 != 0; }
static inline void reg1(int p) { d_1c212c[d_1c212a++] = p; }
static inline void reg2(int p) { d_1c212c[d_1c212a] = p; d_1c212a = d_1c212a + 1; }
//@ f_0478d0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert die beiden Stadt-Ereignisflags d_1bc91c (Kennung 0x261) und d_1bc920 (Kennung
 *   0x268) in der globalen Spielstands-Sektionsliste d_1c212c.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Setzt d_1bc91c und d_1bc920 auf 0 und trägt sie in d_1c212c ein.
 === Ende Beschreibung === */
void f_0478d0()
{
    struct Obj { signed char a; short b; };
    struct Reg { short count; Obj **list; };
    Obj &a = *(Obj *)&d_1bc91c;
    Obj &b = *(Obj *)&d_1bc920;
    Reg &r = *(Reg *)&d_1c212a;
    signed char c = 0;
    a.a = c;
    a.b = 0x261;
    int i = r.count;
    ((Obj ** &)d_1c212c)[i] = &a;
    struct Helper {
        void add(Obj &o, Reg &q, short id) {
            signed char z = 0;
            o.a = z;
            o.b = id;
            q.count++;
            ((Obj ** &)q.list)[q.count] = &o;
            q.count++;
        }
    } h;
    h.add(b, r, 0x268);
}
//@ f_047940  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten des ersten besonderen Gebäudes/Treffpunkts in Riva (entspricht Ereignis
 *   0x7d1 in cityriva_t1) der Reihe nach acht mögliche Quest-Zustände und startet die zugehörige Story-Szene
 *   (f_0ea560, f_0eab60, f_0eac00, f_0eadd0, f_0eafa0, f_11e240, f_0ed040 oder f_0ed1c0).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft die Quest-Flags d_1c00a8, d_1bedb8, d_1c00c4, d_1c0178, d_1bcaa0, d_1c01c8,
 *   d_1c00c8, d_1bed7c, d_1bedfc, d_1bc91c, d_1c00a0, d_1c00bc und d_1c00d4.
 === Ende Beschreibung === */
void f_047940()
{
    if (q_a8_1() && q_edb8_0()) { f_0ea560(); return; }
    if (q_c4_0() && q_l178_1()) { f_0eab60(); return; }
    if (q_caa0_0()) { f_0eac00(); return; }
    if (q_caa0_1() && q_l1c8_1() && q_c8_0()) { f_0eadd0(); return; }
    if (q_c8_1() && q_ed7c_0()) { f_0eafa0(); return; }
    if (q_edfc_lt() && q_edfc_gt() && q_c91c_0()) { f_11e240(); d_1bc91c = 1; return; }
    if (q_a0_1() && q_bc_0() && q_d4_1()) { f_0ed040(); return; }
    if (q_bc_1()) f_0ed1c0();
}
//@ f_047ac0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten des zweiten Treffpunkts (entspricht Ereignis 0x7d2 in cityriva_t1) fünf
 *   Quest-Bedingungen und verzweigt in die passende Story-Szene (f_0eabb0, f_0eac00, f_0ecc70, f_11e240 oder
 *   f_0ed1c0).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00c4, d_1c0178, d_1bcaa0, d_1bed80, d_1c00a4, d_1bee1c, d_1bedfc, d_1bc91c und
 *   d_1c00bc.
 === Ende Beschreibung === */
void f_047ac0()
{
    if (q_c4_0() && q_l178_1()) { f_0eabb0(); return; }
    if (q_caa0_0()) { f_0eac00(); return; }
    if (q_ed80_1() && q_a4_1() && q_ee1c_0()) { f_0ecc70(); return; }
    if (q_edfc_lt() && q_edfc_gt() && q_c91c_0()) { f_11e240(); d_1bc91c = 1; return; }
    if (q_bc_1()) f_0ed1c0();
}
//@ f_047bb0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten einer Taverne (entspricht Ereignis 0x7d3 in cityriva_t1) vorrangige
 *   Quest-Szenen (f_0eab60, f_0eac00, f_0ed1c0) und startet andernfalls den regulären Tavernenbetrieb f_11e500
 *   mit den beiden Unterhaltungsoptionen 0x10 und 0x12.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00c4, d_1c0178, d_1bcaa0 und d_1c00bc.
 === Ende Beschreibung === */
void f_047bb0()
{
    if (q_c4_0() && q_l178_1()) { f_0eab60(); return; }
    if (q_caa0_0()) { f_0eac00(); return; }
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(2, 0x10, 0x12);
}
//@ f_047c30  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten einer weiteren Lokalität (entspricht Ereignis 0x7d4/0x7d5 in cityriva_t1)
 *   laufende Quest-Ereignisse (f_0eadd0, f_0ecc70, f_11e240, f_0ed1c0) und ruft andernfalls f_11e500(1, 1) auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bcaa0, d_1c01c8, d_1c00c8, d_1bed80, d_1c00a4, d_1bee1c, d_1bedfc, d_1bc91c und
 *   d_1c00bc.
 === Ende Beschreibung === */
void f_047c30()
{
    if (q_caa0_1() && q_l1c8_1() && q_c8_0()) { f_0eadd0(); return; }
    if (q_ed80_1() && q_a4_1() && q_ee1c_0()) { f_0ecc70(); return; }
    if (q_edfc_lt() && q_edfc_gt() && q_c91c_0()) { f_11e240(); d_1bc91c = 1; return; }
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(1, 1);
}
//@ f_047d30  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim erstmaligen Betreten dieser Lokalität (d_1bc920 == 0, entspricht Ereignis 0x7d7 in
 *   cityriva_t1) die Begrüßungsmeldung 0x1600005e mit dem Namen des Gruppenführers aus, prüft die Quest-Szenen
 *   f_0ec150, f_0ecdd0 und f_0ed1c0 und startet sonst f_11e500(1, 1). *(Hinweis: Ruft zu Beginn f_1457e0(100)
 *   auf, ohne das Würfelergebnis auszuwerten).*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Setzt d_1bc920 = 1 und prüft d_1bee18, d_1c00c0, d_1bee1c, d_1c00a0, d_1c00d0 sowie
 *   d_1c00bc.
 === Ende Beschreibung === */
void f_047d30()
{
    Ob ob;
    f_1457e0(100);
    if (q_c920_0()) {
        f_125400(&ob, &d_1c349c, &d_1c3870, &d_1c3498);
        ob.p[1] = f_038c40(d_1c0004);
        f_0bf730(P(d_1c2c64), 0x1600005e);
        d_1bc920 = 1;
        f_1254a0(&ob, 0);
    }
    if (q_ee18_1() && q_c0_0()) {
        f_0ec150();
    } else {
        if (q_ee1c_1() && q_a0_0() && q_d0_0()) { f_0ecdd0(); return; }
        int r = 0;
        if (q_bc_1()) r = f_0ed1c0();
        if (r == 0) f_11e500(1, 1);
    }
}
//@ f_047e50  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Betreten des Orts (entspricht Ereignis 0x7d8 in cityriva_t1), ob die Szene f_0ec7b0
 *   (d_1c00b0 == 0 && (d_1c0d64 == 1 || d_1c0ca4 != 0)) oder f_0ed1c0 (d_1c00bc == 1) ausgelöst werden soll.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00b0, d_1c0d64, d_1c0ca4 und d_1c00bc.
 === Ende Beschreibung === */
void f_047e50()
{
    if (q_b0_0() && (q_d64_1() || q_ca4_ne0())) { f_0ec7b0(); return; }
    if (q_bc_1()) f_0ed1c0();
}
//@ f_047eb0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet beim Betreten des Orts (entspricht Ereignis 0x7d9 in cityriva_t1) die Szene f_0eac00,
 *   falls d_1bcaa0 == 0 ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bcaa0.
 === Ende Beschreibung === */
void f_047eb0()
{
    if (q_caa0_0()) f_0eac00();
}
//@ f_047ed0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für eine Gruppe von Tavernen (entspricht Ereignis 0x7da-0x7e0 in cityriva_t1) entweder
 *   die Sonderszene f_0ed1c0 (d_1c00bc == 1) oder den Tavernenbetrieb f_11e500 mit 8 möglichen
 *   Wirtsstuben-Interaktionen (1, 4, 5, 6, 7, 8, 9, 11).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_047ed0()
{
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(8, 1, 4, 5, 6, 7, 8, 9, 0xb);
}
//@ f_047f10  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für eine zweite Gruppe von Tavernen (entspricht Ereignis 0x7e4-0x7e6 in cityriva_t1)
 *   entweder f_0ed1c0 oder den Tavernenbetrieb f_11e500 mit 4 möglichen Interaktionen (12, 13, 14, 15).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_047f10()
{
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(4, 0xc, 0xd, 0xe, 0xf);
}
//@ f_047f50  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für eine dritte Gruppe von Tavernen (entspricht Ereignis 0x7ee-0x7f1 in cityriva_t1)
 *   vorab die Szene f_0ecc70 sowie f_0ed1c0 und startet andernfalls f_11e500 mit den beiden Optionen 0x10 und
 *   0x12.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bed80, d_1c00a4, d_1bee1c und d_1c00bc.
 === Ende Beschreibung === */
void f_047f50()
{
    int r = 0;
    if (q_ed80_1() && q_a4_1() && q_ee1c_0()) f_0ecc70();
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(2, 0x10, 0x12);
}
//@ f_047fd0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für eine vierte Gruppe von Tavernen (entspricht Ereignis 0x7f8-0x7fb in cityriva_t1)
 *   entweder f_0ed1c0 oder den Tavernenbetrieb f_11e500 mit den 3 Optionen 0x11, 0x13, 0x14.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_047fd0()
{
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(3, 0x11, 0x13, 0x14);
}
//@ f_048010  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für die Taverne mit Kennung 0x802 entweder f_0ed1c0 oder f_11e500(1, 10).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_048010()
{
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(1, 0xa);
}
//@ f_048040  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet für eine große Gruppe von Bürgerhäusern/Schenken (0x80c-0x81a, 0x821-0x823) entweder
 *   f_0ed1c0 oder f_11e500 mit 9 Optionen (2, 3, 4, 5, 6, 7, 8, 9, 11).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_048040()
{
    int r = 0;
    if (q_bc_1()) r = f_0ed1c0();
    if (r == 0) f_11e500(9, 2, 3, 4, 5, 6, 7, 8, 9, 0xb);
}
//@ f_048080  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst für die Gebäude 0x81b-0x820 bei gesetztem Quest-Flag d_1c00bc == 1 die Szene f_0ed1c0
 *   aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1c00bc.
 === Ende Beschreibung === */
void f_048080()
{
    if (q_bc_1()) f_0ed1c0();
}
