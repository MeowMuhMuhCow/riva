/* === Beschreibung (Katalog) ===
 * Einheit gz_0c5d80 (Adresse 0x0c5d80 - 0x0c6180)
 *
 * Diese Einheit bildet den Übergang zwischen der ersten Ebene (mine1) und der zweiten Ebene (mine2) der
 * Zwergenmine. Sie enthält eine letzte Kampffolgeroutine aus mine1, zwei Bitfeld-Hilfsfunktionen sowie die
 * Spielstands-Registrierung (__STI) und den Konstruktor für die zweite Ebene der Zwergenmine (mine2, Ortskennung
 * 0x10 = 16).
 === Ende Beschreibung === */
// P3 3/5 gleich (suche.py 23.10.2026, Basis gz_0c5d80_P1.CPP)
// gz_0c5d80.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C5D80-0x0C6180
#include <string.h>
#include "RIVAMEM.H"



struct SO { char a[4]; int *p4; char b[4]; int *pc; char c[4]; short *p14; char d[8]; short *p20; char e[24]; };
struct E3 { char a; short b; };
struct Z { char pad[8]; char *p; };
int f_039320(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_0bf730(char *p1, int p2);
int f_125400(void *p1, char *p2, char *p3, char *p4);
int f_1254a0(void *p1, int p2);
extern char d_1bf288;
extern char d_1bb394[];
extern E3 d_1bf2b0, d_1bf2b4, d_1bf2b8, d_1bf2bc, d_1bf2c0, d_1bf2c4, d_1bf2c8, d_1bf2cc, d_1bf2d0, d_1bf2d4, d_1bf2d8, d_1bf2dc, d_1bf2e0, d_1bf2e4, d_1bf2e8, d_1bf2ec, d_1bf2f0;
extern int d_1c0004;
extern short d_1c212a;
extern void **d_1c212c;
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
//@ f_0c5d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird nach dem Sieg im Wachquartier-Kampf (0x35000a) aufgerufen, setzt den Status
 *   d_1bf288 = 2, lässt den Helden mit dem höchsten Wert in Talent 0x28 (40, Heilkunde/Magiekunde) die Szene
 *   untersuchen (0x35000077) und gibt je nach Ausgang einer Talentprobe (0x28, +5) den Text 0x35000078 oder
 *   0x35000079 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5d80()
{
    SO o;
    int v;
    v = f_039320(d_1c0004, 0x28);
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    f_060800(0x35000a, 1, 0);
    d_1bf288 = 2;
    o.p4[1] = v;
    f_0bf730(d_1c2c64, 0x35000077);
    if (f_044c90(v, 0x28, 5) > 0) f_0bf730(d_1c2c64, 0x35000078);
    else f_0bf730(d_1c2c64, 0x35000079);
    f_1254a0(&o, 0);
}
//@ f_0c5e20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt die in p2 übergebenen Bits im 16-Bit-Wort *p1 mittels bitweisem ODER (*p1
 *   |= p2).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das 16-Bit-Bitfeld sowie die Bitmaske p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Wert des 16-Bit-Bitfelds *p1 zurück.
 === Ende Beschreibung === */
unsigned short f_0c5e20(unsigned short *p1, unsigned p2)
{
    return *p1 |= p2;
}
//@ f_0c5e30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft, welche Bits aus der Maske p2 im 16-Bit-Wort *p1 gesetzt sind (*p1 & p2).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das 16-Bit-Bitfeld sowie die Bitmaske p2 entgegen.
 * - Rückgabewert: Die Funktion gibt das Ergebnis der bitweisen UND-Verknüpfung *p1 & p2 zurück.
 === Ende Beschreibung === */
unsigned short f_0c5e30(unsigned short *p1, unsigned p2)
{
    return *p1 & p2;
}
//@ f_0c5e40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese statische Initialisierungsfunktion (__STI) registriert beim Programmstart 17 Zustandsvariablen
 *   (d_1bf2b0 bis d_1bf2f0, Kennungen 0x1c9 bis 0x23f) für die zweite Ebene der Zwergenmine (mine2) in der
 *   globalen Spielstands-Persistenzliste d_1c212a.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct Registry_E3 { short count; E3 **list; };
inline void put_E3(Registry_E3 &r, E3 &v, short id, char flag)
{
    v.a = flag;
    v.b = id;
    r.list[r.count] = &v;
    ++r.count;
}
#define PUT(v,id) put_E3((Registry_E3 &)d_1c212a, (v), (id), 0)
struct RR700V3_0c5e408;
struct OR700V3_0c5e408 { signed char flag; short number; char pad; OR700V3_0c5e408 *init(RR700V3_0c5e408 &r,short id,signed char f); };
struct RR700V3_0c5e408 { short count; OR700V3_0c5e408 **list; void append(OR700V3_0c5e408 *o) {list[count]=o;count++;} };
inline OR700V3_0c5e408 *OR700V3_0c5e408::init(RR700V3_0c5e408 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0c5e408 regR700V3_0c5e408;
#pragma aux regR700V3_0c5e408 "d_1c212a"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2b0;
#pragma aux obR700V3_0c5e40_1bf2b0 "d_1bf2b0"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2b4;
#pragma aux obR700V3_0c5e40_1bf2b4 "d_1bf2b4"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2b8;
#pragma aux obR700V3_0c5e40_1bf2b8 "d_1bf2b8"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2bc;
#pragma aux obR700V3_0c5e40_1bf2bc "d_1bf2bc"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2c0;
#pragma aux obR700V3_0c5e40_1bf2c0 "d_1bf2c0"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2c4;
#pragma aux obR700V3_0c5e40_1bf2c4 "d_1bf2c4"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2c8;
#pragma aux obR700V3_0c5e40_1bf2c8 "d_1bf2c8"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2cc;
#pragma aux obR700V3_0c5e40_1bf2cc "d_1bf2cc"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2d0;
#pragma aux obR700V3_0c5e40_1bf2d0 "d_1bf2d0"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2d4;
#pragma aux obR700V3_0c5e40_1bf2d4 "d_1bf2d4"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2d8;
#pragma aux obR700V3_0c5e40_1bf2d8 "d_1bf2d8"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2dc;
#pragma aux obR700V3_0c5e40_1bf2dc "d_1bf2dc"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2e0;
#pragma aux obR700V3_0c5e40_1bf2e0 "d_1bf2e0"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2e4;
#pragma aux obR700V3_0c5e40_1bf2e4 "d_1bf2e4"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2e8;
#pragma aux obR700V3_0c5e40_1bf2e8 "d_1bf2e8"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2ec;
#pragma aux obR700V3_0c5e40_1bf2ec "d_1bf2ec"
extern OR700V3_0c5e408 obR700V3_0c5e40_1bf2f0;
#pragma aux obR700V3_0c5e40_1bf2f0 "d_1bf2f0"
void f_0c5e40(void) {
obR700V3_0c5e40_1bf2b0.init(regR700V3_0c5e408,0x1c9,0);
obR700V3_0c5e40_1bf2b4.init(regR700V3_0c5e408,0x1ca,0);
obR700V3_0c5e40_1bf2b8.init(regR700V3_0c5e408,0x1cb,0);
obR700V3_0c5e40_1bf2bc.init(regR700V3_0c5e408,0x1cc,0);
obR700V3_0c5e40_1bf2c0.init(regR700V3_0c5e408,0x1cd,0);
obR700V3_0c5e40_1bf2c4.init(regR700V3_0c5e408,0x1ce,0);
obR700V3_0c5e40_1bf2c8.init(regR700V3_0c5e408,0x1cf,0);
obR700V3_0c5e40_1bf2cc.init(regR700V3_0c5e408,0x1d0,0);
obR700V3_0c5e40_1bf2d0.init(regR700V3_0c5e408,0x200,0);
obR700V3_0c5e40_1bf2d4.init(regR700V3_0c5e408,0x201,0);
obR700V3_0c5e40_1bf2d8.init(regR700V3_0c5e408,0x202,0);
obR700V3_0c5e40_1bf2dc.init(regR700V3_0c5e408,0x1ff,0);
obR700V3_0c5e40_1bf2e0.init(regR700V3_0c5e408,0x1e7,0);
obR700V3_0c5e40_1bf2e4.init(regR700V3_0c5e408,0x1e8,0);
obR700V3_0c5e40_1bf2e8.init(regR700V3_0c5e408,0x24e,0);
obR700V3_0c5e40_1bf2ec.init(regR700V3_0c5e408,0x25d,0);
obR700V3_0c5e40_1bf2f0.init(regR700V3_0c5e408,0x23f,0);
}

//@ f_0c6150
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Schauplatz-Objekt für die zweite Ebene der Zwergenmine (mine2,
 *   Ortskennung 0x10 = 16 über f_05ff60) und trägt die virtuelle Methodentabelle d_1bb394 bei Offset +0x08 ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das zu initialisierende mine2-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c6150(int p1)
{
    int r = f_05ff60(p1, 0x10);
    *(int *)(r + 8) = (int)d_1bb394;
}
