/* === Beschreibung (Katalog) ===
 * Einheit gz_0fdbd0_t2 (0fee00 - 0ff6a0)
 *
 * Überblick
 *
 * Die Einheit gz_0fdbd0_t2 bildet den Abschluss des Orkschiff-Moduls (ship, Kennung 0x29). Sie enthält weitere
 * Kampf- und Untersuchungsroutinen an Bord (f_0fee00 bis f_0ff040) sowie die Rückkehr- und Hilfsmethoden des
 * Schiffs-Dungeons (f_0ff630, f_0ff650).
 === Ende Beschreibung === */
// P3 10/12 gleich (suche.py 24.10.2026, Basis gz_0fdbd0_t2_P1.CPP)
// gz_0fdbd0_t2.cpp - Teil 0FEE00-0FF6A0
#include <string.h>

#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
int f_0dd440(int p1);
int f_0de820(int p1);
int f_039660(int p1, int p2);
int f_0bf730(int p1, int p2);
unsigned short f_0bf820(void *p1, ...);
int f_060240();
int f_060a70();
int f_0fbc60(int p1);
int f_08c920(int p1, int p2);
int f_0fb5f0(int p1, int p2);
int f_100850(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
extern int d_1c0004;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3498;
extern int d_1c3870;
extern signed char d_1c0314;
extern int d_1bb790[];
extern short d_1c212a;
extern char **d_1c212c;
extern char d_1c0298;
extern char d_1c029c;
extern char d_1c02a0;
extern char d_1c02a4;
extern char d_1c02a8;
extern char d_1c02ac;
extern char d_1c02b0;
extern char d_1c02b4;
extern char d_1c02b8;
extern char d_1c02bc;
extern char d_1c02c0;
extern char d_1c02c4;
extern char d_1c02c8;
extern char d_1c02cc;
extern char d_1c02d0;
extern char d_1c02d4;
extern char d_1c02d8;
extern char d_1c02dc;
extern char d_1c02e0;
extern char d_1c02e4;
extern char d_1c02e8;
extern char d_1c02ec;
extern char d_1c02f0;
extern char d_1c02f4;
extern char d_1c02f8;
extern char d_1c02fc;
extern char d_1c0300;
extern char d_1c0304;
extern char d_1c0308;
extern char d_1c030c;
extern char d_1c0310;
extern char d_1c0318;
extern short d_1c0299;
extern short d_1c029d;
extern short d_1c02a1;
extern short d_1c02a5;
extern short d_1c02a9;
extern short d_1c02ad;
extern short d_1c02b1;
extern short d_1c02b5;
extern short d_1c02b9;
extern short d_1c02bd;
extern short d_1c02c1;
extern short d_1c02c5;
extern short d_1c02c9;
extern short d_1c02cd;
extern short d_1c02d1;
extern short d_1c02d5;
extern short d_1c02d9;
extern short d_1c02dd;
extern short d_1c02e1;
extern short d_1c02e5;
extern short d_1c02e9;
extern short d_1c02ed;
extern short d_1c02f1;
extern short d_1c02f5;
extern short d_1c02f9;
extern short d_1c02fd;
extern short d_1c0301;
extern short d_1c0305;
extern short d_1c0309;
extern short d_1c030d;
extern short d_1c0311;
extern short d_1c0315;
extern short d_1c0319;
struct OB { int a; int b; int x1; int x2; int c; int rest[10]; };

//@ f_0fee00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die Untersuchung einer Schiffskiste oder Koje (d_1c0389), prüft auf
 *   eventuelle Fallen und händigt den Helden gefundene Gegenstände aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Schiffs-Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct MsgC { int h; char *q[14]; MsgC(void *, void *, void *); ~MsgC(); };
void f_0fee00(int p1)
{
    short s;
    switch ((unsigned short)f_0de820(d_1c0004)) {
    case 0x17: s = 10; break;
    case 0x18: s = 20; break;
    case 0x19: s = 30; break;
    }
    s += f_0dd440(d_1c0004);
    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
    switch ((unsigned short)s) {
    case 0xe:
    case 0x15:
    case 0x16:
        if ((short)f_0bf820(&d_1c2c64, 0x2f0001c6, 2, 0x2f0001c7, 0x2f0001c8) == 1) {
            f_0bf730((int)&d_1c2c64, 0x2f0001c9);
        } else {
            f_0bf730((int)&d_1c2c64, 0x2f0001ca);
            ((void (*)(int, int, int))(*(int *)((OB *)p1)->x1))(p1, 0x6c, 0);
            f_060a70();
        }
        f_0fbc60(p1);
        break;
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
        {
        ((OB *)m.q[0])->b = f_039660(d_1c0004, 1);
        f_0bf730((int)&d_1c2c64, 0x2f0001c5);
        break;
        }
    case 0xb:
        break;
    }
}
//@ f_0fef70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese acht kurzen Methoden starten jeweils einen vordefinierten Kampf gegen unterschiedliche
 *   Wachposten und Besatzungsgruppen an Bord des Schiffs (0x1f43 bis 0x1f4c) über f_05fa00 bzw. setzen
 *   zugehörige Kampfflags.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Jede Funktion gibt den Rückgabewert des Kampfstarts (f_05fa00) zurück bzw. endet ohne
 *   Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fef70(int p1)
{
    f_0bf730((int)&d_1c2c64, 0x2f0001cb);
    f_0fbc60(p1);
}

//@ f_0fef90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode des Orkschiff-Moduls (gz_0fdbd0_t2) leitet die beiden 16-Bit-Parameter p2 und p3
 *   direkt an die Karten-/Objektfunktion f_08c920 weiter.
 * - Eingaben: Die Funktion erhält den ungenutzten Objektzeiger p1 sowie die beiden 16-Bit-Werte p2 und p3
 *   (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Delegiert direkt an f_08c920(p2, p3).
 === Ende Beschreibung === */
void f_0fef90(int p1, short p2, short p3)
{
    f_08c920(p2, p3);
}

//@ f_0fefa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt an Bord des Orkschiffs die Textmeldung 0x2f01004a über das globale Dialogsystem
 *   d_1c2c64 (f_0bf730) aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: d_1c2c64 (Dialogsystem), 0x2f01004a (Textkennung).
 === Ende Beschreibung === */
void f_0fefa0(void)
{
    f_0bf730((int)&d_1c2c64, 0x2f01004a);
}

//@ f_0fefc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode setzt das Statusfeld bei Offset +0x0d des übergebenen Objekts p1 vorübergehend auf 0,
 *   führt die Aktualisierungsroutine f_060240() aus und setzt das Statusfeld anschließend auf 1.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(int *)(p1 + 0x0d) (Aktiv-/Statusflag des Objekts).
 === Ende Beschreibung === */
void f_0fefc0(int p1)
{
    *(int *)(p1 + 0xd) = 0;
    f_060240();
    *(int *)(p1 + 0xd) = 1;
}

//@ f_0fefe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liest den 32-Bit-Statuswert bei Offset +0x0d des Objekts p1 aus.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1.
 * - Rückgabewert: Die Funktion gibt den Wert *(int *)(p1 + 0x0d) zurück (int).
 * - Wichtige Variablen: *(int *)(p1 + 0x0d).
 === Ende Beschreibung === */
int f_0fefe0(int p1)
{
    return *(int *)(p1 + 0xd);
}

//@ f_0feff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode schreibt den übergebenen 32-Bit-Wert p2 in das Statusfeld bei Offset +0x0d des
 *   Objekts p1.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie den neuen Statuswert p2 (int).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(int *)(p1 + 0x0d).
 === Ende Beschreibung === */
void f_0feff0(int p1, int p2)
{
    *(int *)(p1 + 0xd) = p2;
}

//@ f_0ff000
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Vergleichsfunktion prüft, ob das vorzeichenbehaftete Statusbyte *p1 größer oder gleich dem
 *   Schwellenwert p2 ist.
 * - Eingaben: Die Funktion erhält den Bytezeiger p1 (signed char *) und den Vergleichswert p2 (signed char).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn *p1 >= p2 gilt, andernfalls 0.
 * - Wichtige Variablen: v (ausgelesener Wert *p1).
 === Ende Beschreibung === */
int f_0ff000(signed char *p1, signed char p2)
{
    int v = *p1;
    return v >= p2;
}

//@ f_0ff020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Vergleichsfunktion prüft, ob das vorzeichenbehaftete Statusbyte *p1 kleiner als der
 *   Schwellenwert p2 ist.
 * - Eingaben: Die Funktion erhält den Bytezeiger p1 (signed char *) und den Vergleichswert p2 (signed char).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn *p1 < p2 gilt, andernfalls 0.
 * - Wichtige Variablen: v (ausgelesener Wert *p1).
 === Ende Beschreibung === */
int f_0ff020(signed char *p1, signed char p2)
{
    int v = *p1;
    return v < p2;
}

//@ f_0ff040
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Methode steuert eine komplexe Szene im Unterdeck oder Gefangenenbereich des
 *   Schiffs (d_1c038a bis d_1c0390), bei der die Helden Gefangene befreien, Wachen überlisten oder Kämpfe
 *   austragen und Beute bergen können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct Rff040 { signed char flag; short id; };
#define FF_FIRST(D,K,V) { Rff040 *p = (Rff040 *)&D; short k = K; signed char v = V; int * &t = (int *&)d_1c212c; short &n = d_1c212a; p->flag = v; p->id = k; t[n] = (int)p; }
#define FF_MIDDLE(D,K,V) { Rff040 *p = (Rff040 *)&D; short k = K; signed char v = V; int * &t = (int *&)d_1c212c; short &n = d_1c212a; p->flag = v; p->id = k; t[++n] = (int)p; }
#define FF_IDFIRST(D,K,V) { Rff040 *p = (Rff040 *)&D; short k = K; signed char v = V; int * &t = (int *&)d_1c212c; short &n = d_1c212a; p->id = k; p->flag = v; t[++n] = (int)p; }
#define FF_LAST(D,K,V) { Rff040 *p = (Rff040 *)&D; short k = K; signed char v = V; int * &t = (int *&)d_1c212c; short &n = d_1c212a; p->flag = v; p->id = k; t[++n] = (int)p; ++n; }


#pragma inline_depth(10)
#pragma aux f_0fefc0 "W?f_0fefc0$n(i)v";
#pragma aux f_0feff0 "W?f_0feff0$n(ii)v";
struct E680{signed char value;short id;};
struct R680{short count;E680 **list;};
static inline void add680(E680 &o,R680 &r,short id,signed char value){o.value=value;o.id=id;r.list[r.count]=&o;r.count++;}
struct RR700V3_0ff0408;
struct OR700V3_0ff0408 { signed char flag; short number; char pad; OR700V3_0ff0408 *init(RR700V3_0ff0408 &r,short id,signed char f); };
struct RR700V3_0ff0408 { short count; OR700V3_0ff0408 **list; void append(OR700V3_0ff0408 *o) {list[count]=o;count++;} };
inline OR700V3_0ff0408 *OR700V3_0ff0408::init(RR700V3_0ff0408 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0ff0408 regR700V3_0ff0408;
#pragma aux regR700V3_0ff0408 "d_1c212a"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0298;
#pragma aux obR700V3_0ff040_1c0298 "d_1c0298"
extern OR700V3_0ff0408 obR700V3_0ff040_1c029c;
#pragma aux obR700V3_0ff040_1c029c "d_1c029c"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02a0;
#pragma aux obR700V3_0ff040_1c02a0 "d_1c02a0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02a4;
#pragma aux obR700V3_0ff040_1c02a4 "d_1c02a4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02a8;
#pragma aux obR700V3_0ff040_1c02a8 "d_1c02a8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02ac;
#pragma aux obR700V3_0ff040_1c02ac "d_1c02ac"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02b0;
#pragma aux obR700V3_0ff040_1c02b0 "d_1c02b0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02b4;
#pragma aux obR700V3_0ff040_1c02b4 "d_1c02b4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02b8;
#pragma aux obR700V3_0ff040_1c02b8 "d_1c02b8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02bc;
#pragma aux obR700V3_0ff040_1c02bc "d_1c02bc"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02c0;
#pragma aux obR700V3_0ff040_1c02c0 "d_1c02c0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02c4;
#pragma aux obR700V3_0ff040_1c02c4 "d_1c02c4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02c8;
#pragma aux obR700V3_0ff040_1c02c8 "d_1c02c8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02cc;
#pragma aux obR700V3_0ff040_1c02cc "d_1c02cc"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02d0;
#pragma aux obR700V3_0ff040_1c02d0 "d_1c02d0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02d4;
#pragma aux obR700V3_0ff040_1c02d4 "d_1c02d4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02d8;
#pragma aux obR700V3_0ff040_1c02d8 "d_1c02d8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02dc;
#pragma aux obR700V3_0ff040_1c02dc "d_1c02dc"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02e0;
#pragma aux obR700V3_0ff040_1c02e0 "d_1c02e0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02e4;
#pragma aux obR700V3_0ff040_1c02e4 "d_1c02e4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02e8;
#pragma aux obR700V3_0ff040_1c02e8 "d_1c02e8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02ec;
#pragma aux obR700V3_0ff040_1c02ec "d_1c02ec"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02f0;
#pragma aux obR700V3_0ff040_1c02f0 "d_1c02f0"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02f4;
#pragma aux obR700V3_0ff040_1c02f4 "d_1c02f4"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02f8;
#pragma aux obR700V3_0ff040_1c02f8 "d_1c02f8"
extern OR700V3_0ff0408 obR700V3_0ff040_1c02fc;
#pragma aux obR700V3_0ff040_1c02fc "d_1c02fc"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0300;
#pragma aux obR700V3_0ff040_1c0300 "d_1c0300"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0304;
#pragma aux obR700V3_0ff040_1c0304 "d_1c0304"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0308;
#pragma aux obR700V3_0ff040_1c0308 "d_1c0308"
extern OR700V3_0ff0408 obR700V3_0ff040_1c030c;
#pragma aux obR700V3_0ff040_1c030c "d_1c030c"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0310;
#pragma aux obR700V3_0ff040_1c0310 "d_1c0310"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0314;
#pragma aux obR700V3_0ff040_1c0314 "d_1c0314"
extern OR700V3_0ff0408 obR700V3_0ff040_1c0318;
#pragma aux obR700V3_0ff040_1c0318 "d_1c0318"
void f_0ff040(void) {
obR700V3_0ff040_1c0298.init(regR700V3_0ff0408,0x136,0);
obR700V3_0ff040_1c029c.init(regR700V3_0ff0408,0x137,0);
obR700V3_0ff040_1c02a0.init(regR700V3_0ff0408,0x138,0);
obR700V3_0ff040_1c02a4.init(regR700V3_0ff0408,0x139,0);
obR700V3_0ff040_1c02a8.init(regR700V3_0ff0408,0x13a,80);
obR700V3_0ff040_1c02ac.init(regR700V3_0ff0408,0x13b,0);
obR700V3_0ff040_1c02b0.init(regR700V3_0ff0408,0x13c,0);
obR700V3_0ff040_1c02b4.init(regR700V3_0ff0408,0x13d,0);
obR700V3_0ff040_1c02b8.init(regR700V3_0ff0408,0x13e,0);
obR700V3_0ff040_1c02bc.init(regR700V3_0ff0408,0x13f,0);
obR700V3_0ff040_1c02c0.init(regR700V3_0ff0408,0x140,0);
obR700V3_0ff040_1c02c4.init(regR700V3_0ff0408,0x141,0);
obR700V3_0ff040_1c02c8.init(regR700V3_0ff0408,0x142,0);
obR700V3_0ff040_1c02cc.init(regR700V3_0ff0408,0x143,0);
obR700V3_0ff040_1c02d0.init(regR700V3_0ff0408,0x24f,0);
obR700V3_0ff040_1c02d4.init(regR700V3_0ff0408,0x144,0);
obR700V3_0ff040_1c02d8.init(regR700V3_0ff0408,0x145,0);
obR700V3_0ff040_1c02dc.init(regR700V3_0ff0408,0x146,0);
obR700V3_0ff040_1c02e0.init(regR700V3_0ff0408,0x147,0);
obR700V3_0ff040_1c02e4.init(regR700V3_0ff0408,0x148,0);
obR700V3_0ff040_1c02e8.init(regR700V3_0ff0408,0x149,0);
obR700V3_0ff040_1c02ec.init(regR700V3_0ff0408,0x14a,0);
obR700V3_0ff040_1c02f0.init(regR700V3_0ff0408,0x14b,0);
obR700V3_0ff040_1c02f4.init(regR700V3_0ff0408,0x150,0);
obR700V3_0ff040_1c02f8.init(regR700V3_0ff0408,0x151,0);
obR700V3_0ff040_1c02fc.init(regR700V3_0ff0408,0x152,0);
obR700V3_0ff040_1c0300.init(regR700V3_0ff0408,0x153,0);
obR700V3_0ff040_1c0304.init(regR700V3_0ff0408,0x154,0);
obR700V3_0ff040_1c0308.init(regR700V3_0ff0408,0x155,0);
obR700V3_0ff040_1c030c.init(regR700V3_0ff0408,0x156,0);
obR700V3_0ff040_1c0310.init(regR700V3_0ff0408,0x157,0);
obR700V3_0ff040_1c0314.init(regR700V3_0ff0408,0x25f,0);
obR700V3_0ff040_1c0318.init(regR700V3_0ff0408,0x262,0);
}


//@ f_0ff630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert die Dungeon-Kennung 0x29 (41) des Orkschiffs zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 0x29 zurück.
 === Ende Beschreibung === */
void f_0ff630(int p1)
{
    int r;
    r = f_0fb5f0(p1, 0x17);
    *(int *)(r + 8) = (int)d_1bb790;
}

//@ f_0ff650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode initialisiert eine 9-Byte-Zustandsstruktur des Schiffsmoduls mit Nullwerten.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf die zu löschende Struktur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ff650(int p1)
{
    f_0fefc0(p1);
    f_0feff0(p1, 0);
    if (EQI(d_1c0314, 1)) {
        d_1c0314 = 2;
        f_100850(p1);
    }
    f_0feff0(p1, 1);
}
