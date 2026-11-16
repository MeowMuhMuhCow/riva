/* === Beschreibung (Katalog) ===
 * Einheit gz_1295c0_rand910a (0x1295c0 - 0x129b40)
 *
 * Überblick
 * Diese Einheit bildet den ersten Abschlussteil von tower0.cpp (untere Etagen des Magierturms) und implementiert
 * eine Kälte-/Schadensprüfung anhand getragener Kleidung, ein Seil-/Kletterhindernis, einen Magierkampf (0x99)
 * sowie die Kampf-Nachbereitungs- und Destruktor-Methoden des tower0-Dungeon-Objekts.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 12/12 gleich (suche.py 28.10.2026, Basis gz_1295c0_P1.CPP)
// gz_1295c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1295C0-0x129D70
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039830(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060100(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060240();                                         // reg - stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060990(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (12), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


short f_0d4aa0(int p1, int p2);
short f_145760(int p1, int p2);
short f_0bf820(void *p1, ...);
int f_05ff60(int p1, int p2);
int f_060230(int p1);
void f_145234(int p1, int p2);
void f_145254();
int f_060740(int p1, int p2);
int f_0bf730(int p1, int p2);
extern int d_1c0004; extern signed char d_1c0ca0, d_1c0cc8, d_1c0cf8; extern char d_1c0cd4; extern short d_1bd922, d_1c212a; extern int *d_1c212c;
extern short d_1a9820;
extern char d_1c0ce8, d_1c0cf0, d_1c0cf4, d_1c0cfc, d_1c0d00, d_1c0d04;
extern char d_1c0cec;
extern short d_1c0ced, d_1c0cf1, d_1c0cf5, d_1c0cf9, d_1c0cfd, d_1c0d01, d_1c0d05;
extern signed char d_1c0ce9;
extern char d_1c2c64[], d_1c2edc[], d_1c349c[], d_1c3870[], d_1c3498[], d_1bbaf8[]; extern int d_1bbb50[];
#pragma aux f_147323 modify [esp];
#define EQI(x,v) (((x)==(v))?1:0)
#define BOTH (a == 1 && b == 1)
#define ADD(x) d_1c212c[d_1c212a] = (int)&x; d_1c212a = d_1c212a + 1;
#define U ((unsigned short)p2)
typedef void (*VF)(int, int, int);

//@ f_1295c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für einen handlungsfähigen Helden p1, ob er wärmende Oberbekleidung/Mäntel (0x2b, 0x4d, 0x1aa,
 *   0x147 usw.) und festes Schuhwerk/Beinkleider (0x4b, 0x4c, 0xe9, 0x19a) trägt, und zieht ihm je nach
 *   fehlendem Schutz 1W3 (beides vorhanden), 3-6 (eines vorhanden) oder 5-10 (keines vorhanden) Schadenspunkte
 *   ab.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den geprüften Helden.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1295c0(int p1)
{
    int b, a;
    int x, y;
    short s;
    if (f_0d4a60(p1) != 1) return;
    if (f_042400((struct hero *)(p1)) != 0) return;
    s = f_0d4aa0(p1, 0x2b);
    a = 0; b = 0;
    if (s != -1 || f_0d4aa0(p1, 0x4d) != -1 || f_0d4aa0(p1, 0x1aa) != -1 ||
        f_0d4aa0(p1, 0x147) != -1 || f_0d4aa0(p1, 0x15e) != -1 || f_0d4aa0(p1, 0x4e) != -1 ||
        f_0d4aa0(p1, 0xc4) != -1 || f_0d4aa0(p1, 0xd5) != -1) a = 1;
    s = f_0d4aa0(p1, 0x4b);
    if (s != -1 || f_0d4aa0(p1, 0x4c) != -1 || f_0d4aa0(p1, 0xe9) != -1 ||
        f_0d4aa0(p1, 0x19a) != -1) b = 1;
    if (a == 0 && b == 0) {
        y = 10; x = 5;
    } else {
        if (BOTH) {
            s = f_145760(1, 3);
            f_044300(p1, s);
            return;
        }
        y = 6; x = 3;
    }
    s = f_145760(x, y);
    f_044300(p1, s);
}

//@ f_129750
/* === Beschreibung (Katalog) ===
 * - Zweck: Bietet dem Spieler an einem Hindernis (0x27000055) vier Möglichkeiten an (darunter Klettern mit Seil
 *   0x23, ein Zauberversuch auf Zauber 0x1c oder das Durchqueren einer Kälte-/Gefahrenzone mit Schaden über
 *   f_1295c0 für alle Helden).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129750(void)
{
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    short s;
    int t;
    *(int *)(obj.slots[0] + 4) = f_039660(d_1c0004, 0xc);
    s = f_0bf820(d_1c2c64, 0x27000055, 4, 0x27000056, 0x27000057, 0x27000058, 0x27000059);
    switch (s) {
    case -1:
        break;
    case 1:
        f_0bf730((int)d_1c2c64, 0x2700005a);
        return;
    case 2:
        if (f_0d54f0(d_1c0004, 0x23) == -1) {
            *(int *)(obj.slots[0] + 4) = f_039320(d_1c0004, 0x30);
            f_0bf730((int)d_1c2c64, 0x2700005b);
            return;
        }
        t = f_0397d0(d_1c0004, 0x23);
        if (t == 0) t = f_039320(d_1c0004, 0x30);
        *(int *)(obj.slots[0] + 4) = t;
        f_0bf730((int)d_1c2c64, 0x2700005c);
        return;
    case 3:
        t = f_039830(d_1c0004, 0x1c);
        if (t != 0) {
            *(int *)(obj.slots[0] + 4) = t;
            f_0bf730((int)d_1c2c64, 0x2700005d);
            return;
        }
        f_0bf730((int)d_1c2c64, 0x2700005e);
        return;
    case 4:
        *(int *)(obj.slots[0] + 4) = f_038c40(d_1c0004);
        { int snd = *(int *)&d_1a9820;
          f_147323((int)d_1c2edc, 0x27000c, 0x7fff, 0x8000, snd, 0, 1);
        }
        f_0bf730((int)d_1c2c64, 0x2700005f);
        f_039a80(d_1c0004, (int)f_1295c0);
        break;
    }
}

//@ f_129940
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst in einem Raum einen Kamera-/Beben-Effekt (f_060990(15, 3)) aus und gibt eine Meldung
 *   (0x27000060) mit dem im Talent 0x27 besten Helden aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129940(void)
{
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(obj.slots[0] + 4) = f_039320(d_1c0004, 0x27);
    f_060990(0xf, 3);
    f_0bf730((int)d_1c2c64, 0x27000060);
}

//@ f_1299a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Meldung (0x27000061) aus, setzt das Flag d_1c0cd4 = 1 und versetzt die Gruppe auf Karte 4
 *   (0x146b).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1299a0(void)
{
    f_0bf730((int)d_1c2c64, 0x27000061);
    d_1c0cd4 = 1;
    f_0dd7f0(d_1c0004, 4, 0x146b);
}

//@ f_1299d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst, wenn der Mechanismus d_1c0ca0 == 1 aktiviert ist und Kampf 0x99 (d_1c0cc8 == 0) noch nicht
 *   stattgefunden hat, die Meldung 0x27000062 und den Kampf 0x99 (12 Gegner) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1299d0(int p1)
{
    if (EQI(d_1c0ca0, 1) && EQI(d_1c0cc8, 0)) {
        f_0bf730((int)d_1c2c64, 0x27000062);
        d_1bd922 = 0xc;
        (**(VF **)(p1 + 8))(p1, 0x99, 0);
        f_0697c0(p1 + 2, 0x99, 0);
        d_1c0cc8 = 1;
    }
}

//@ f_129a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x27000063 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129a50(void)
{
    f_0bf730((int)d_1c2c64, 0x27000063);
}

//@ f_129a70
/* === Beschreibung (Katalog) ===
 * - Zweck: Initialisiert beim Betreten der Ebene die Kampfgruppe 0x99 (f_069860) und ruft die
 *   Basis-Initialisierung f_060230 auf.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129a70(int p1)
{
    f_069860(p1 + 2, 0x99, 0);
    f_060230(p1);
}

//@ f_129a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den Abschluss eines Kampfes (3, 4, 5, 0x99, 0x9a) in tower0 und entfernt die besiegten
 *   Gegnertrupps (f_0697c0) von der Karte.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts, in p2 die Kampf-ID und in
 *   p3 das Kampfergebnis.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Basis-Kampfabschlusses (f_060100) zurück.
 === Ende Beschreibung === */
int f_129a90(int p1, short p2, short p3)
{
    int r = f_060100(p1, p2, p3);
    switch ((unsigned short)p2) {
    case 3:
    case 4:
        f_0697c0(p1 + 2, 3, 0);
        f_0697c0(p1 + 2, 4, 0);
        break;
    case 5:
    case 0x99:
        goto one_call;
    case 0x9a:
    one_call:
        f_0697c0(p1 + 2, p2, 0);
        break;
    }
    return r;
}

//@ f_129b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor des tower0-Dungeon-Objekts, der den Basis-Destruktor f_060030 aufruft und bei gesetztem
 *   Flag den Objektspeicher freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_129b00(int p1, int p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bbaf8);
        f_145254();
        return p1;
    }
    r = f_060030(p1, 1);
    if (p2 & 2) delete (char *)r;
    return r;
}

struct Obj129 { signed char a; short b; };
struct Reg129 { short count; Obj129 **list; };
extern Reg129 reg129;
#pragma aux reg129 "d_1c212a"
extern Obj129 o_ce8;
#pragma aux o_ce8 "d_1c0ce8"
extern Obj129 o_cec;
#pragma aux o_cec "d_1c0cec"
extern Obj129 o_cf0;
#pragma aux o_cf0 "d_1c0cf0"
extern Obj129 o_cf4;
#pragma aux o_cf4 "d_1c0cf4"
extern Obj129 o_cf8;
#pragma aux o_cf8 "d_1c0cf8"
extern Obj129 o_cfc;
#pragma aux o_cfc "d_1c0cfc"
extern Obj129 o_d00;
#pragma aux o_d00 "d_1c0d00"
extern Obj129 o_d04;
#pragma aux o_d04 "d_1c0d04"
inline signed char zero129() { signed char c = 0; return c; }
inline void add129(Obj129 &o, Reg129 &r, short id) {
    o.a = zero129(); o.b = id; r.list[r.count] = &o; r.count++;
}
//@ f_129b40
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die acht persistenten Zustandsvariablen der oberen Magierturm-Etage (d_1c0ce8 bis
 *   d_1c0d04, Kennungen 0xc4-0xc9, 0xf2, 0x1fb) in der globalen Spielstands-Tabelle (d_1c212a).
 * - Eingaben: Die Funktion erhält im Parameter p1 einen ungenutzten Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129b40(int p1)
;

//@ f_129cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor des Dungeon-Objekts für die obere Etage des Magierturms (tower1, Dungeon-ID 0x13), der
 *   die Basisklasse (f_05ff60) initialisiert und die virtuelle Methodentabelle (d_1bbb50) einträgt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129cc0(int p1)
;

//@ f_129ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Synchronisiert beim Betreten der oberen Magierturm-Etage den Zustand des Hebels/Mechanismus 0x1f50
 *   und des gekoppelten Durchgangs 0x1f4c anhand des gespeicherten Flags d_1c0cf8.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_129ce0(void)
;
