/* === Beschreibung (Katalog) ===
 * Einheit tower1_t2 (0x12b010 - 0x12c190)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von tower1.cpp (obere Etagen des Magierturms, Dungeon-ID 0x13). Sie
 * implementiert das Opfer-/Schacht-Rätsel (f_12b010), zahlreiche Teleporter- und Raum-Trigger, das Aufteilen der
 * Gruppe auf zwei zusammenwirkende Teilgruppen für den Hebel-/Brückenmechanismus (f_12b8b0, f_12ba70) sowie den
 * Endkampf (0x23) gegen den Turmherrn (f_12c0a0).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 40/41 gleich (suche.py 26.10.2026, Basis tower1_t2_P1.CPP)
// tower1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x129D70-0x12C190
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#define EQI(x,v) (((x)==(v))?1:0)
extern int d_1c349c, d_1c3870, d_1c3498, d_1c2c64;
extern signed char d_1c0cec, d_1c0cf0, d_1c0cf4, d_1c0cf8, d_1c0d00, d_1c0d04, d_1c0d08, d_1c0d0c;

struct Tx { char b[0x13e]; Tx(int a, int b, int c); };
struct Tw { char b[0xc]; Tw(int a, int b); };
typedef short (*FNV)(int, int, int);
typedef int (*FNI)(int, int, int);
int f_0bf730(int p1, int p2);

int f_05f220(int p1, int p2);
short f_060760(int p1);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
short f_0db9a0(int p1);
short f_0dcf00(int p1, int p2, int p3);
short f_0de020(int p1, int p2);
short f_0dcc10(int p1);
short f_0dc020(int p1, int p2);





int f_0bf980(int, ...);
int f_0bfa20(int, ...);
int f_12c030(int p1);
int f_12c020(int p1);
int f_044040(int p1);
int f_12c050();
int f_12c0a0(int p1);
#define MSG(n) f_0bf730((int)&d_1c2c64, n)
#define OBJ RivaTextContext obj(&d_1c349c, &d_1c3870, &d_1c3498)
#define PM(o, k) (*(int *)(obj.slots[k] + (o)))
#define DEL(o) if (o) delete (char *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0)))
#define SETF(v) do { short s_; int b_; d_1c0cf8 = (v); s_ = f_060760(0x1f50); b_ = d_1c0cf8 != 0; if ((d_1c0cf8 == 0 && s_ == 2) || (d_1c0cf8 == 1 && s_ == 1)) { f_060740(0x1f50, 1); f_0607e0(0x1f4c, b_); } } while (0)
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041030();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
int f_041ae0(int p1);                                   // reg eax stapel 0
int f_044060(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f560(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1, int p2);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c0ce8;                    // 0x1C0CE8
extern int d_1c0cfc;                    // 0x1C0CFC
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2470;                    // 0x1C2470
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern const char d_1a8c80[];           // Text 0x1A8C80 (Dateiname; L1A8C7F ist im Bau nicht oeffentlich)
//@ f_12b010
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt ein Rätsel an einem Schacht oder Behälter (0x3e, Position 0x1f48), in den der Spieler einen
 *   Gegenstand aus dem Inventar werfen kann: Wird der richtige Schlüsselgegenstand 0x190 hineingelegt, löst dies
 *   den Mechanismus (f_05f470, f_05f480) und den Tagebucheintrag 0x2b aus; bei einem Seil (0x23) geht dieses
 *   verloren (0x27000085), und andere Gegenstände werden abgewiesen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
typedef int (*FI1)(int);
void f_12b010() {
    OBJ;
    int w;
    int done;
    short s, t;
    int item;
    int o;
    int o2;
    {
        int raw = (int)operator new(12, mark(d_1a8c80, 0x326));
        w = raw ? f_05f190(raw, 0x3e, 0x1f48) : raw;
    }
    if (f_05f560(w)) {
        PM(4, 0) = f_039660(d_1c0004, 1);
        MSG(0x2700007d);
        if (f_0bf6f0((int)&d_1c2c64, 0x2700007e) == 1) {
            do {
                done = 1;
                o = f_038e90(d_1c0004, 0x27000081);
                o2 = o;
                if (o != 0) {
                    s = f_032820(o, 0x27000082, 1);
                    if (s != -1) {
                        t = f_042a60((struct hero *)(o), s);
                        done = 0;
                        int *table = (*(int **)&d_1c2c40);
                        item = table[t];
                        PM(4, 2) = item;
                        short value;
                        if (((RivaItemDefinition*)(item))->f_0a7950()) {
                            int full = f_042ac0((struct hero *)(o), s);
                            value = full;
                        } else
                            value = 1;
                        *(short *)(obj.slots[7] + 2) = value;
                        if (f_0d4a60(o2))
                            o = o2;
                        else
                            o = f_038c40(d_1c0004);
                        PM(4, 0) = o;
                        if (t == 0x190) {
                            MSG(0x2700007f);
                            f_0dd1d0(d_1c0004, 0x190);
                            f_05f470(w);
                            f_05f480(w);
                            done = 1;
                            f_091f70(0x2b);
                        } else if (((RivaItemDefinition*)(item))->f_0a7930()) {
                            MSG(0x27000083);
                        } else if (((RivaItemDefinition*)(item))->f_0a7990()) {
                            MSG(0x27000084);
                        } else if (t == 0x23) {
                            MSG(0x27000085);
                            f_033530(o2, s);
                        } else {
                            MSG(0x27000086);
                        }
                    }
                }
            } while (done == 0);
        }
    }
    if (w) delete (char *)f_05f220(w, 0);
}
//@ f_12b230
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x3a an der Position 0x1f49.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b230() {
    f_05fa00(0x3a, 0x1f49);
}
//@ f_12b250
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beobachtungsmeldung (0x27000087) mit dem Helden höchster Klugheit/Eigenschaft 0x0c aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b250() {
    OBJ;
    PM(4, 0) = f_039660(d_1c0004, 0xc);
    MSG(0x27000087);
}
//@ f_12b2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beobachtungsmeldung (0x27000088) mit dem Helden höchster Eigenschaft 6 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b2b0() {
    OBJ;
    PM(4, 0) = f_039660(d_1c0004, 6);
    MSG(0x27000088);
}
//@ f_12b310
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x27000089 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b310() {
    MSG(0x27000089);
}
//@ f_12b330
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x2d aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b330() {
    f_0603b0(0x2d);
}
//@ f_12b340
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x2e aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b340() {
    f_0603b0(0x2e);
}
//@ f_12b350
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x2700008a aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b350() {
    MSG(0x2700008a);
}
//@ f_12b370
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeigt beim ersten Betreten eines Raumes (d_1c0d04 == 0) das Bild 0x270001 (Index 3) mit dem Text
 *   0x2700008b an und startet anschließend den Kampf 6.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b370(int p1) {
    if (EQI(d_1c0d04, 0)) {
        int o = f_0606a0(0x270001, 3);
        f_0bfa20((int)&d_1c2c64, o, 0, 0x2700008b, 0);
        DEL(o);
        FNV *vt = *(FNV **)(p1 + 8);
        if (vt[0](p1, 6, 0) == 0) d_1c0d04 = 1;
    }
}
//@ f_12b3f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt den Spieler an einem magischen Spiegel oder Portal (0x2700008c), ob er hindurchtreten möchte,
 *   und setzt bei Bestätigung die Gruppenaktion 0x67.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b3f0() {
    if (f_0bf6f0((int)&d_1c2c64, 0x2700008c) == 1) f_0de810(d_1c0004, 0x67);
}
//@ f_12b420
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x2f aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b420() {
    f_0603b0(0x2f);
}
//@ f_12b430
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x30 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b430() {
    f_0603b0(0x30);
}
//@ f_12b440
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet das Behälter-Objekt 0x3b an Position 0x1f4a und gibt, falls d_1c0d04 == 0 ist, vorab die
 *   Meldung 0x27000080 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b440() {
    int p1 = (int)new (mark(d_1a8c80, 0x453)) Tw(0x3b, 0x1f4a);
    if (EQI(d_1c0d04, 0)) {
        if (f_05f560(p1) == 1) MSG(0x27000080);
    }
    f_05f280(p1, 0);
    if (p1 != 0) delete (char *)f_05f220(p1, 0);
}
//@ f_12b4c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet das Behälter-Objekt 0x41 an Position 0x1f4b und gibt, falls d_1c0d04 == 0 ist, vorab die
 *   Meldung 0x27000080 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b4c0() {
    int p1 = (int)new (mark(d_1a8c80, 0x461)) Tw(0x41, 0x1f4b);
    if (EQI(d_1c0d04, 0)) {
        if (f_05f560(p1) == 1) MSG(0x27000080);
    }
    f_05f280(p1, 0);
    if (p1 != 0) delete (char *)f_05f220(p1, 0);
}
//@ f_12b540
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt eine Beobachtungsmeldung (0x2700008d) mit dem Helden höchster Eigenschaft 0x0c aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b540() {
    OBJ;
    PM(4, 0) = f_039660(d_1c0004, 0xc);
    MSG(0x2700008d);
}
//@ f_12b5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x2700008e aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b5a0() {
    MSG(0x2700008e);
}
//@ f_12b5c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x31 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b5c0() {
    f_0603b0(0x31);
}
//@ f_12b5d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt den Spieler an einem Brunnen oder Trankgefäß (0x2700008f), ob die Gruppe daraus trinken möchte,
 *   und stillt bei Bestätigung den Durst der Gruppe (f_0dbeb0).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b5d0() {
    if (f_0bf6f0((int)&d_1c2c64, 0x2700008f) == 1) f_0dbeb0(d_1c0004);
}
//@ f_12b600
/* === Beschreibung (Katalog) ===
 * - Zweck: Bietet der Gruppe einmalig (d_1c0cec == 0) an einer Fundstelle (0x27000090) das Aufnehmen von
 *   Gegenstand 4 an und gibt bei späteren Besuchen 0x27000091 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b600() {
    if (EQI(d_1c0cec, 0)) {
        if (f_0bf6f0((int)&d_1c2c64, 0x27000090) == 1) {
            short s = f_0dcf00(d_1c0004, 4, 1);
            if (0 < s) {
                d_1c0cec = 1;
            }
        }
    } else MSG(0x27000091);
}
//@ f_12b660
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x3c an der Position 0x1f45.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b660() {
    f_05fa00(0x3c, 0x1f45);
}
//@ f_12b680
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet den Beutecontainer 0x40 an der Position 0x1f47.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b680() {
    f_05fa00(0x40, 0x1f47);
}
//@ f_12b6a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Bietet der Gruppe einmalig (d_1c0cf0 == 0) an einer Fundstelle (0x27000092) das Aufnehmen des
 *   Gegenstands 0x30 an, verursacht dabei leichten Schaden (2W6+5) und gibt bei späteren Besuchen 0x27000094
 *   aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b6a0() {
    if (EQI(d_1c0cf0, 0)) {
        if (f_0bf6f0((int)&d_1c2c64, 0x27000092) == 1) {
            short s = f_0dcf00(d_1c0004, 0x30, 1);
            if (0 < s) {
                d_1c0cf0 = 1;
                MSG(0x27000093);
                f_0db9d0(d_1c0004, 2, 5);
            }
        }
    } else MSG(0x27000094);
}
//@ f_12b730
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x32 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b730() {
    f_0603b0(0x32);
}
//@ f_12b740
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x33 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b740() {
    f_0603b0(0x33);
}
//@ f_12b750
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x34 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b750() {
    f_0603b0(0x34);
}
//@ f_12b760
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x27000095 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b760() {
    MSG(0x27000095);
}
//@ f_12b780
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x2700008a aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b780() {
    MSG(0x2700008a);
}
//@ f_12b7a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x35 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b7a0() {
    f_0603b0(0x35);
}
//@ f_12b7b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Bietet der Gruppe einmalig (d_1c0cf4 == 0) das Aufnehmen des Gegenstands 400 (0x190) an (0x27000096),
 *   schaltet bei Erfolg das Objekt 0x324 um und gibt bei späteren Besuchen 0x27000097 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b7b0() {
    if (EQI(d_1c0cf4, 0)) {
        if (f_0bf6f0((int)&d_1c2c64, 0x27000096) == 1) {
            short s = f_0dcf00(d_1c0004, 400, 1);
            if (0 < s) {
                f_060740(0x324, 1);
                d_1c0cf4 = 1;
            }
        }
    } else MSG(0x27000097);
}
//@ f_12b820
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst das Dungeon-Ereignis bzw. den Teleporter 0x36 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b820() {
    f_0603b0(0x36);
}
//@ f_12b830
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raumbeschreibung 0x27000098 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b830() {
    MSG(0x27000098);
}
//@ f_12b850
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion für Teilgruppen, die prüft, ob ein Gruppen-Slot aktiv ist und mindestens ein
 *   handlungsfähiges Mitglied enthält.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf ein Gruppen-Objekt.
 * - Rückgabewert: Die Funktion gibt 1 bei einer aktiven, nicht leeren Teilgruppe zurück, sonst 0.
 === Ende Beschreibung === */
int f_12b850(int p1) {
    if (f_0de7c0(p1) != 0) {
        if (0 < f_0db9a0(p1)) return 1;
    }
    return 0;
}
//@ f_12b880
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion für Helden, die prüft, ob ein Held handlungsfähig und kein tierischer/temporärer
 *   Begleiter (f_042400 == 0) ist.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held die Bedingung erfüllt, sonst 0.
 === Ende Beschreibung === */
int f_12b880(int p1) {
    if (f_0d4a60(p1) != 0) {
        if (f_042400((struct hero *)(p1)) == 0) return 1;
    }
    return 0;
}
//@ f_12b8b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die erste Wachposition des Zweigruppen-Mechanismus (0x385): Ist dort noch kein Held
 *   postiert (f_12c050() == 0), kann der Spieler einen Helden auswählen, der als eigene Ein-Personen-Teilgruppe
 *   an dieser Stelle zurückbleibt (f_044060(..., 1)) und den Mechanismus bewacht.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12b8b0() {
    int f_041030(int,...);
    OBJ;
    short s = f_0de020((int)f_12c030, (int)&d_1c2470);
    int r;
    if ((int)s == 0) r = 0;
    else r = d_1c2470;
    int t;
    if (r != 0) {
        RivaTextContext obj2(&d_1c349c, &d_1c3870, &d_1c3498);
        *(int *)(obj2.slots[0] + 4) = f_038c40(r);
        MSG(0x27000099);
    } else {
        t = 0;
        if (1 < f_0db9a0(d_1c0004)) {
            if (f_0bf6f0((int)&d_1c2c64, 0x2700009a) == 1) t = f_039a10(d_1c0004, 0x2700009b, (int)f_12b880);
        } else {
            PM(4, 0) = f_038c40(d_1c0004);
            if (f_0bf6f0((int)&d_1c2c64, 0x2700009c) == 1) {
                if (1 < f_0de020((int)f_12b850, (int)&d_1c21b4)) t = f_038c40(d_1c0004);
                else MSG(0x2700009d);
            }
        }
        if (t != 0) {
            if (1 < f_0db9a0(d_1c0004)) {
                f_044060(f_038c40(f_041030(1, t)), 1);
                return;
            }
            f_044060(f_038c40(d_1c0004), 1);
            f_041ae0(0);
        }
    }
}
//@ f_12ba40
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob ein Held einem der elfischen bzw. magischen Archetypen (10, 11 oder 12) angehört.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Archetyp 10, 11 oder 12 ist, sonst 0.
 === Ende Beschreibung === */
int f_12ba40(int p1) {
    short c = f_042350((struct hero *)(p1));
    if (c == 10 || c == 11 || c == 12) return 1;
    return 0;
}
//@ f_12ba70
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den Haupthebel (0x386 / 0x1f50) des Zweigruppen-Mechanismus: Befindet sich ein postierter
 *   Held an der Gegenstelle (r != 0), wird ein weiterer Held (a) ausgewählt, gegebenenfalls der Endkampf
 *   (f_12c0a0, Kampf 0x23) ausgelöst und nach dem Sieg der Durchgang 0x1f4c geöffnet sowie die Gruppe in Ebene
 *   20 (0x139a) versetzt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_12ba70(int p1) {
  int f_041030(int,...);
  int f_12c0a0(int,int);
  OBJ;
  int r,a,o2,o0,u;
  short s;
  r=f_12c050();
  r=r?f_038c40(r):r;
  if(EQI(d_1c0cf8,0)) {
    if (r == (short)0) {
      if(EQI(d_1c0d00,0)) {
        u=f_039660((d_1c0d00=1,d_1c0004),12);
        r=f_039b70(d_1c0004,u,1);
        PM(4,0)=u; PM(8,0)=r;
        MSG(0x2700009e);
        if(r) MSG(0x2700009f);
      } else {
        PM(4,0)=f_039660(d_1c0004,1);
        MSG(0x270000a0);
        return;
      }
    } else {
      if(f_0db9a0((d_1c0d00=1,d_1c0004))>1) {
        a=f_038d70(d_1c0004,0x270000a1);
        if(a) {
          PM(4,0)=a;
          if(f_042350((struct hero *)(a))==6) MSG(0x270000a2);
          else if(f_12ba40(a)) MSG(0x270000a3);
        }
      } else a=f_038c40(d_1c0004);
      if(!a) return;
      PM(4,0)=a; PM(8,0)=r;
      short t_424 = f_042380((struct hero *)(r));
      if (t_424 == 1) MSG(0x270000a4);
      else MSG(0x270000a5);
      if(EQI(d_1c0d08,0)) {
        o0=d_1c0004;
        if((o2=(f_0db9a0(o0)>1)?f_041030(1,a):d_1c0004)!=d_1c0004) f_041920(o2);
        f_09a0d0(d_1a34e0);
        s=f_12c0a0(p1,o2);
        if(o0!=d_1c0004) f_041920(o0);
        if(s==0) {
          f_060a70(); MSG(0x270000a6);
          { short sf; short bf; sf=f_060760((d_1c0cf8=1,0x1f50)); bf=EQI(EQI(d_1c0cf8,0),0); if((EQI(d_1c0cf8,0)&&sf==(short)2)||(EQI(d_1c0cf8,1)&&sf==(short)1)){f_060740(0x1f50,1);f_0607e0(0x1f4c,(signed char)bf);} }
          f_0dd7f0(d_1c0004,20,0x139a);
#if FIX_R051   /* R051: Am Gegenhebel postierte Teilgruppe nach dem Sieg automatisch wieder mit der Hauptgruppe vereinen */
          { int g2 = f_12c050(); if (g2 && g2 != d_1c0004) { f_044060(r, 0); f_0dcdf0(g2, f_0dc020(g2, r)); f_0dcc40(d_1c0004, r, f_0dcc10(d_1c0004)); *(signed char *)&d_1c0028 = f_041000(); } }
#endif
          if(o2!=d_1c0004) {
      u=f_038c80(o2);
      f_0dcdf0(o2,f_0dc020(o2,u));
      f_0dcc40(d_1c0004,u,f_0dcc10(d_1c0004));
      *(signed char *)&d_1c0028=f_041000();
      return;
    }
        } else if(s==1||s==3) {
          PM(4,0)=a; PM(8,0)=r; MSG(0x270000a7);
          if(o2!=d_1c0004) {
      u=f_038c80(o2);
      f_0dcdf0(o2,f_0dc020(o2,u));
      f_0dcc40(d_1c0004,u,f_0dcc10(d_1c0004));
      *(volatile signed char *)&d_1c0028=f_041000(); // volatile verhindert das Zusammenlegen des Stores mit dem ersten Zweig
      return;
    }
        }
      } else {
        if(f_0db9a0(d_1c0004)>1) {PM(4,0)=a;PM(8,0)=r;MSG(0x270000a8);}
        { short sf; short bf; sf=f_060760((d_1c0cf8=1,0x1f50)); bf=EQI(EQI(d_1c0cf8,0),0); if((EQI(d_1c0cf8,0)&&sf==(short)2)||(EQI(d_1c0cf8,1)&&sf==(short)1)){f_060740(0x1f50,1);f_0607e0(0x1f4c,(signed char)bf);} }
        f_0dd7f0(d_1c0004,20,0x139a);
#if FIX_R051
        { int g2 = f_12c050(); if (g2 && g2 != d_1c0004) { f_044060(r, 0); f_0dcdf0(g2, f_0dc020(g2, r)); f_0dcc40(d_1c0004, r, f_0dcc10(d_1c0004)); *(signed char *)&d_1c0028 = f_041000(); } }
#endif
        return;
      }
    }
  } else {
    if(!r) {MSG(0x270000a9);return;}
    PM(4,0)=r;
    if(f_0bf6f0((int)&d_1c2c64,0x270000aa)==1) { short sf; short bf; d_1c0cf8=0; sf=f_060760(0x1f50); bf=EQI(EQI(d_1c0cf8,0),0); if((EQI(d_1c0cf8,0)&&sf==(short)2)||(EQI(d_1c0cf8,1)&&sf==(short)1)){f_060740(0x1f50,1);f_0607e0(0x1f4c,(signed char)bf);} }
  }
}
//@ f_12c020
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für einen Helden p1, ob das spezielle Wachpositions-Flag (f_044040) gesetzt ist.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt den Statuswert von f_044040(p1) zurück.
 === Ende Beschreibung === */
int f_12c020(int p1) {
    return f_044040(p1);
}
//@ f_12c030
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für eine Teilgruppe p1, ob sich darin ein Held mit gesetztem Wachpositions-Flag (f_12c020)
 *   befindet.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf ein Gruppen-Objekt.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Teilgruppe den postierten Helden enthält, sonst 0.
 === Ende Beschreibung === */
int f_12c030(int p1) {
    return f_039ac0(p1, (int)f_12c020) != 0;
}
//@ f_12c050
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht unter allen Teilgruppen nach derjenigen, die am Zweigruppen-Mechanismus postiert ist
 *   (f_12c030).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die gefundene Teilgruppe zurück oder 0, falls keine
 *   Teilgruppe postiert ist.
 === Ende Beschreibung === */
int f_12c050() {
    short s = f_0de020((int)f_12c030, (int)&d_1c2470);
    int r = s;
    if (s != 0) r = d_1c2470;
    return r;
}
//@ f_12c070
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt den Anführer der am Zweigruppen-Mechanismus postierten Teilgruppe (f_12c050).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt im Register EAX den Zeiger auf den Anführer der postierten Teilgruppe zurück
 *   oder 0, falls niemand postiert ist.
 === Ende Beschreibung === */
void f_12c070() {
    short s = f_0de020((int)f_12c030, (int)&d_1c2470);
    int p = s;
    if (s != 0) p = d_1c2470;
    if (p != 0) f_038c40(p);
}
//@ f_12c0a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Spielt beim ersten Mal (d_1c0d0c == 0) die Zwischensequenz (0x2c0015) und Ansprache (0x270000b0) des
 *   Gegners ab und startet anschließend den Kampf 0x23, wobei nach einem Sieg (r == 0) das Flag d_1c0d08 = 1
 *   gesetzt wird.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt und in p2 den Zeiger auf die
 *   kämpfende Teilgruppe.
 * - Rückgabewert: Die Funktion gibt das Kampfergebnis (0 bei Sieg) zurück.
 === Ende Beschreibung === */
int f_12c0a0(int p1, int p2) {
    int r;
    OBJ;
    if (EQI(d_1c0d0c, 0)) {
        int o = (int)new (mark(d_1a8c80, 0x71f)) Tx(0x2c0015, 0, 0);
        d_1c0d0c = 1;
        PM(4, 0) = f_038c40(d_1c0004);
        f_0bf6c0((int)&d_1c2c64, 6);
        f_0bf980((int)&d_1c2c64, o, 0, 0x270000b0, 0);
        ((int (*)(int))f_0bf680)((int)&d_1c2c64);
        if (o) delete (char *)f_010590(o, 0);
    }
    r = (**(FNI **)(p1 + 8))(p1, 0x23, 0);
    if ((short)r == 0) d_1c0d08 = 1;
    return r;
}
