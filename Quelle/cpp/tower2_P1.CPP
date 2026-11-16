/* === Beschreibung (Katalog) ===
 * Einheit tower2 (0x12C2A0-0x12EA70)
 *
 * Diese Einheit implementiert die Ereignis-, Rätsel- und Interaktionslogik für die zweite Ebene des Magierturms
 * (tower2.cpp) sowie die zugehörigen Spielstands-Registrierungen und den Übergang zur nächsten Ebene. Dazu
 * gehören das Aufbrechen der vier versiegelten Nischen für die vier Silben des Losungswortes, die
 * Passworteingabe, das Einsetzen der farbigen Diamanten (rot, grün, blau, gelb) in drei Fassungen sowie
 * Gefahrenstellen mit Schaden und Waffenbruch.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// tower2 (Schatten ueber Riva) - GANZES Linkermodul 0x12C2A0-0x12EA70 inkl. COMDAT-Schwanz (Forscher 840, 30.10.2026)
// Erzeugt mit comdat/840/bau_modul.py aus: gz_12c190(p3), tower2_t1(p3), tower2_t2(p3), gz_12e960(p3)
#include <string.h>
#include <math.h>
struct B05ff60 { char pad[8]; B05ff60(int k); virtual ~B05ff60(); };   // Basis: ctor f_05ff60, dtor f_060030
// ===== Teil gz_12c190 (p3, 12c190-12c660) =====
#define d_1c0004 d_1c0004_k0
#define d_1c0cf8 d_1c0cf8_k0
#define d_1c0d10 d_1c0d10_k0
#define d_1c0d14 d_1c0d14_k0
#define d_1c0d18 d_1c0d18_k0
#define d_1c0d1c d_1c0d1c_k0
#define d_1c0d20 d_1c0d20_k0
#define d_1c0d24 d_1c0d24_k0
#define d_1c0d28 d_1c0d28_k0
#define d_1c0d2c d_1c0d2c_k0
#define d_1c0d30 d_1c0d30_k0
#define d_1c0d34 d_1c0d34_k0
#define d_1c0d3c d_1c0d3c_k0
#define d_1c0d40 d_1c0d40_k0
#define d_1c212a d_1c212a_k0
#define f_05ff60 f_05ff60_k0
#define f_060030 f_060030_k0
#define f_060740 f_060740_k0
#define f_060760 f_060760_k0
#define f_0607e0 f_0607e0_k0
#define f_145234 f_145234_k0
#define f_145254 f_145254_k0
// P3 2/6 gleich (suche.py 23.10.2026, Basis gz_12c190_P1.CPP)
// gz_12c190.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12C190-0x12C660
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c80(int p1);                                   // reg eax stapel 0
int f_041000();                                         // reg - stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

short f_0dc020(int p1, int p2);
short f_0dcc10(int p1);
int f_0dcc40(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060240();
int f_060740(int p1, int p2);
void f_145234(int p1, int p2);
void f_145254();
extern int d_1c0004, d_1c0028; extern signed char d_1c0cf8;
struct GS { short n; int *tab; };
extern GS d_1c212a, d_1c2132;
extern char d_1c0d08, d_1c0d0c, d_1c0d10, d_1c0d14, d_1c0d18, d_1c0d1c, d_1c0d20, d_1c0d24, d_1c0d28, d_1c0d2c, d_1c0d30, d_1c0d34, d_1c0d38, d_1c0d3c;
extern short d_1c0d09, d_1c0d0d, d_1c0d11, d_1c0d15, d_1c0d19, d_1c0d1d, d_1c0d21, d_1c0d25, d_1c0d29, d_1c0d2d, d_1c0d31, d_1c0d35, d_1c0d39, d_1c0d3d;
extern short d_1c0d40, d_1c0d42, d_1c0d44, d_1c0d46, d_1c0d48, d_1c0d4a;
extern char d_1bbb3c[], d_1bbb94[];
#define EQI(x,v) (((x)==(v))?1:0)
#define ADD(x) d_1c212a.tab[d_1c212a.n] = (int)&x; d_1c212a.n++;
#define ADD2(x) d_1c2132.tab[d_1c2132.n] = (int)&x; d_1c2132.n++;

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
// (anderes Modul)  f_12c190
// (Funktion f_12c190 gehoert zu einem anderen Modul, hier weggelassen)

// (anderes Modul)  f_12c1e0
// (Funktion f_12c1e0 gehoert zu einem anderen Modul, hier weggelassen)

// (anderes Modul)  f_12c260
// (Funktion f_12c260 gehoert zu einem anderen Modul, hier weggelassen)

//@ f_12c2a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Registriert beim Initialisieren des Moduls 14 ein-Byte-Zustandsflags (0xf3 bis 0x24b,
 *   Adresse d_1c0d08 bis d_1c0d3c) im globalen Byte-Spielstandsregister (d_1c212a) sowie 3 zwei-Byte-Werte (0x04
 *   bis 0x06, Adresse d_1c0d40 bis d_1c0d48 für die drei Diamantenfassungen) im globalen
 *   Wort-Spielstandsregister (d_1c2132) und setzt ihre Startwerte auf 0.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Globale Byte-Zustandseinträge d_1c0d08..d_1c0d3c (Merker für ausgelöste Ereignisse,
 *   geöffnete Nischen und gelöste Rätsel auf Turmebene 2) sowie Wort-Einträge d_1c0d40, d_1c0d44, d_1c0d48
 *   (aktuell eingesetzte Diamanten-Gegenstandsnummern in den drei Fassungen).
 === Ende Beschreibung === */
struct Obj12B { signed char v; short id; char pad; };
struct Obj12W { short v; short id; };
struct Reg12B { short count; Obj12B **list; };
struct Reg12W { short count; Obj12W **list; };
extern Reg12B reg12b;
extern Reg12W reg12w;
#pragma aux reg12b "d_1c212a"
#pragma aux reg12w "d_1c2132"
extern Obj12B ob12_d08;
#pragma aux ob12_d08 "d_1c0d08"
extern Obj12B ob12_d0c;
#pragma aux ob12_d0c "d_1c0d0c"
extern Obj12B ob12_d10;
#pragma aux ob12_d10 "d_1c0d10"
extern Obj12B ob12_d14;
#pragma aux ob12_d14 "d_1c0d14"
extern Obj12B ob12_d18;
#pragma aux ob12_d18 "d_1c0d18"
extern Obj12B ob12_d1c;
#pragma aux ob12_d1c "d_1c0d1c"
extern Obj12B ob12_d20;
#pragma aux ob12_d20 "d_1c0d20"
extern Obj12B ob12_d24;
#pragma aux ob12_d24 "d_1c0d24"
extern Obj12B ob12_d28;
#pragma aux ob12_d28 "d_1c0d28"
extern Obj12B ob12_d2c;
#pragma aux ob12_d2c "d_1c0d2c"
extern Obj12B ob12_d30;
#pragma aux ob12_d30 "d_1c0d30"
extern Obj12B ob12_d34;
#pragma aux ob12_d34 "d_1c0d34"
extern Obj12B ob12_d38;
#pragma aux ob12_d38 "d_1c0d38"
extern Obj12B ob12_d3c;
#pragma aux ob12_d3c "d_1c0d3c"
extern Obj12W ob12_d40;
#pragma aux ob12_d40 "d_1c0d40"
extern Obj12W ob12_d44;
#pragma aux ob12_d44 "d_1c0d44"
extern Obj12W ob12_d48;
#pragma aux ob12_d48 "d_1c0d48"
inline signed char zero12b() { signed char c=0; return c; }
inline short zero12w() { short c=0; return c; }
inline void add12b(Obj12B &o,Reg12B &r,short id) { o.v=0; o.id=id; r.list[r.count]=&o; r.count++; }
inline void add12w(Obj12W &o,Reg12W &r,short id) { o.v=0; o.id=id; r.list[r.count]=&o; r.count++; }
struct RR700V3_12c2a08;
struct OR700V3_12c2a08 { signed char flag; short number; char pad; OR700V3_12c2a08 *init(RR700V3_12c2a08 &r,short id,signed char f); };
struct RR700V3_12c2a08 { short count; OR700V3_12c2a08 **list; void append(OR700V3_12c2a08 *o) {list[count]=o;count++;} };
inline OR700V3_12c2a08 *OR700V3_12c2a08::init(RR700V3_12c2a08 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_12c2a08 regR700V3_12c2a08;
#pragma aux regR700V3_12c2a08 "d_1c212a"
struct RR700V3_12c2a016;
struct OR700V3_12c2a016 { short flag; short number;  OR700V3_12c2a016 *init(RR700V3_12c2a016 &r,short id,short f); };
struct RR700V3_12c2a016 { short count; OR700V3_12c2a016 **list; void append(OR700V3_12c2a016 *o) {list[count]=o;count++;} };
inline OR700V3_12c2a016 *OR700V3_12c2a016::init(RR700V3_12c2a016 &r,short id,short f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_12c2a016 regR700V3_12c2a016;
#pragma aux regR700V3_12c2a016 "d_1c2132"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d08;
#pragma aux obR700V3_12c2a0_1c0d08 "d_1c0d08"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d0c;
#pragma aux obR700V3_12c2a0_1c0d0c "d_1c0d0c"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d10;
#pragma aux obR700V3_12c2a0_1c0d10 "d_1c0d10"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d14;
#pragma aux obR700V3_12c2a0_1c0d14 "d_1c0d14"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d18;
#pragma aux obR700V3_12c2a0_1c0d18 "d_1c0d18"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d1c;
#pragma aux obR700V3_12c2a0_1c0d1c "d_1c0d1c"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d20;
#pragma aux obR700V3_12c2a0_1c0d20 "d_1c0d20"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d24;
#pragma aux obR700V3_12c2a0_1c0d24 "d_1c0d24"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d28;
#pragma aux obR700V3_12c2a0_1c0d28 "d_1c0d28"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d2c;
#pragma aux obR700V3_12c2a0_1c0d2c "d_1c0d2c"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d30;
#pragma aux obR700V3_12c2a0_1c0d30 "d_1c0d30"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d34;
#pragma aux obR700V3_12c2a0_1c0d34 "d_1c0d34"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d38;
#pragma aux obR700V3_12c2a0_1c0d38 "d_1c0d38"
extern OR700V3_12c2a08 obR700V3_12c2a0_1c0d3c;
#pragma aux obR700V3_12c2a0_1c0d3c "d_1c0d3c"
extern OR700V3_12c2a016 obR700V3_12c2a0_1c0d40;
#pragma aux obR700V3_12c2a0_1c0d40 "d_1c0d40"
extern OR700V3_12c2a016 obR700V3_12c2a0_1c0d44;
#pragma aux obR700V3_12c2a0_1c0d44 "d_1c0d44"
extern OR700V3_12c2a016 obR700V3_12c2a0_1c0d48;
#pragma aux obR700V3_12c2a0_1c0d48 "d_1c0d48"
void f_12c2a0(void) {
obR700V3_12c2a0_1c0d08.init(regR700V3_12c2a08,0xf3,0);
obR700V3_12c2a0_1c0d0c.init(regR700V3_12c2a08,0xf4,0);
obR700V3_12c2a0_1c0d10.init(regR700V3_12c2a08,0xf5,0);
obR700V3_12c2a0_1c0d14.init(regR700V3_12c2a08,0xf6,0);
obR700V3_12c2a0_1c0d18.init(regR700V3_12c2a08,0xf7,0);
obR700V3_12c2a0_1c0d1c.init(regR700V3_12c2a08,0xf8,0);
obR700V3_12c2a0_1c0d20.init(regR700V3_12c2a08,0xf9,0);
obR700V3_12c2a0_1c0d24.init(regR700V3_12c2a08,0x10c,0);
obR700V3_12c2a0_1c0d28.init(regR700V3_12c2a08,0x10d,0);
obR700V3_12c2a0_1c0d2c.init(regR700V3_12c2a08,0x10e,0);
obR700V3_12c2a0_1c0d30.init(regR700V3_12c2a08,0x135,0);
obR700V3_12c2a0_1c0d34.init(regR700V3_12c2a08,0x22c,0);
obR700V3_12c2a0_1c0d38.init(regR700V3_12c2a08,0x22d,0);
obR700V3_12c2a0_1c0d3c.init(regR700V3_12c2a08,0x24b,0);
obR700V3_12c2a0_1c0d40.init(regR700V3_12c2a016,0x4,0);
obR700V3_12c2a0_1c0d44.init(regR700V3_12c2a016,0x5,0);
obR700V3_12c2a0_1c0d48.init(regR700V3_12c2a016,0x6,0);
}

struct X12c5b0 : B05ff60 { X12c5b0(); virtual ~X12c5b0(){ } };   // inline-virtueller Destruktor -> COMDAT $dt:X12c5b0 = f_12ea30
//@ f_12c5b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor des Dungeon-Steuerobjekts für die zweite Ebene des Magierturms; ruft den
 *   Basiskonstruktor f_05ff60 mit der Dungeon-Kennung 0x14 (20) auf und trägt die virtuelle Methodentabelle der
 *   Ebene ein.
 * - Eingaben: Impliziter this-Zeiger auf das anzulegende Ebenenobjekt.
 * - Rückgabe: Zeiger auf das initialisierte Objekt.
 * - Wichtige Variablen: Basisklassen-Unterobjekt (8 Bytes) mit Zeiger auf die virtuelle Methodentabelle.
 === Ende Beschreibung === */
X12c5b0::X12c5b0() : B05ff60(0x14) { }   // Konstruktor, setzt vtable; erzeugt $dt:X12c5b0 als COMDAT am Modulende (= f_12ea30)
//@ f_12c5d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert bzw. synchronisiert beim Betreten der Turmebene 2 den Zustand des 3D-Objekts
 *   0x1f50 (8016, ein Durchgang oder Gitter) und dessen Automap-Darstellung anhand des gespeicherten Ebenenflags
 *   d_1c0cf8.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: s (aktueller Zustand des 3D-Objekts 0x1f50 über f_060760), b (invertiertes Flag aus
 *   d_1c0cf8 für die Automap-Markierung über f_0607e0).
 === Ende Beschreibung === */
void f_12c5d0(void)
{
    short s;
    short b;
    f_060240();
    s = f_060760(0x1f50);
    b = EQI(EQI(d_1c0cf8, 1), 0);
    if ((EQI(d_1c0cf8, 1) && s == (short)2) || (EQI(d_1c0cf8, 0) && s == (short)1)) {
        f_060740(0x1f50, 1);
        f_0607e0(0x1f50, (signed char)b);
    }
}

#undef ADD
#undef ADD2
#undef EQB
#undef EQI
#undef d_1c0004
#undef d_1c0cf8
#undef d_1c0d10
#undef d_1c0d14
#undef d_1c0d18
#undef d_1c0d1c
#undef d_1c0d20
#undef d_1c0d24
#undef d_1c0d28
#undef d_1c0d2c
#undef d_1c0d30
#undef d_1c0d34
#undef d_1c0d3c
#undef d_1c0d40
#undef d_1c212a
#undef f_05ff60
#undef f_060030
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_145234
#undef f_145254

// ===== Teil tower2_t1 (p3, 12c660-12d850) =====
#define d_1a8ca0 d_1a8ca0_k1
#define d_1a8cbe d_1a8cbe_k1
#define d_1a8cc6 d_1a8cc6_k1
#define d_1a8cd0 d_1a8cd0_k1
#define d_1a8ce0 d_1a8ce0_k1
#define d_1a8cea d_1a8cea_k1
#define d_1a9820 d_1a9820_k1
#define d_1c0004 d_1c0004_k1
#define d_1c040c d_1c040c_k1
#define d_1c0420 d_1c0420_k1
#define d_1c0428 d_1c0428_k1
#define d_1c0900 d_1c0900_k1
#define d_1c0cf8 d_1c0cf8_k1
#define d_1c0d10 d_1c0d10_k1
#define d_1c0d14 d_1c0d14_k1
#define d_1c0d18 d_1c0d18_k1
#define d_1c0d1c d_1c0d1c_k1
#define d_1c0d20 d_1c0d20_k1
#define d_1c0d24 d_1c0d24_k1
#define d_1c0d28 d_1c0d28_k1
#define d_1c0d2c d_1c0d2c_k1
#define d_1c0d30 d_1c0d30_k1
#define d_1c0d34 d_1c0d34_k1
#define d_1c0d3c d_1c0d3c_k1
#define d_1c0d40 d_1c0d40_k1
#define d_1c21b4 d_1c21b4_k1
#define d_1c21c8 d_1c21c8_k1
#define d_1c21dc d_1c21dc_k1
#define d_1c21f0 d_1c21f0_k1
#define d_1c2204 d_1c2204_k1
#define d_1c2268 d_1c2268_k1
#define d_1c22cc d_1c22cc_k1
#define d_1c2330 d_1c2330_k1
#define d_1c299c d_1c299c_k1
#define d_1c2c40 d_1c2c40_k1
#define d_1c2c44 d_1c2c44_k1
#define d_1c2c64 d_1c2c64_k1
#define d_1c2edc d_1c2edc_k1
#define d_1c3498 d_1c3498_k1
#define d_1c349c d_1c349c_k1
#define d_1c3870 d_1c3870_k1
#define d_1c38b0 d_1c38b0_k1
#define f_032820 f_032820_k1
#define f_033c50 f_033c50_k1
#define f_038c40 f_038c40_k1
#define f_038d70 f_038d70_k1
#define f_038e10 f_038e10_k1
#define f_039320 f_039320_k1
#define f_039420 f_039420_k1
#define f_039660 f_039660_k1
#define f_0397d0 f_0397d0_k1
#define f_03d4b0 f_03d4b0_k1
#define f_040780 f_040780_k1
#define f_041030 f_041030_k1
#define f_0423c0 f_0423c0_k1
#define f_042a60 f_042a60_k1
#define f_042ac0 f_042ac0_k1
#define f_042bb0 f_042bb0_k1
#define f_042d00 f_042d00_k1
#define f_044850 f_044850_k1
#define f_044900 f_044900_k1
#define f_046d10 f_046d10_k1
#define f_046d90 f_046d90_k1
#define f_046de0 f_046de0_k1
#define f_047120 f_047120_k1
#define f_05f190 f_05f190_k1
#define f_05f220 f_05f220_k1
#define f_05f4f0 f_05f4f0_k1
#define f_05f580 f_05f580_k1
#define f_05f800 f_05f800_k1
#define f_05fa00 f_05fa00_k1
#define f_0606a0 f_0606a0_k1
#define f_060740 f_060740_k1
#define f_060760 f_060760_k1
#define f_060770 f_060770_k1
#define f_0607e0 f_0607e0_k1
#define f_091f70 f_091f70_k1



#define f_0bde40 f_0bde40_k1
#define f_0bf680 f_0bf680_k1
#define f_0bf6c0 f_0bf6c0_k1
#define f_0bf6f0 f_0bf6f0_k1
#define f_0bf730 f_0bf730_k1
#define f_0bf820 f_0bf820_k1
#define f_0bfa20 f_0bfa20_k1
#define f_0bfea0 f_0bfea0_k1
#define f_0db9a0 f_0db9a0_k1
#define f_0dcbb0 f_0dcbb0_k1
#define f_0dd1d0 f_0dd1d0_k1
#define f_0dd750 f_0dd750_k1
#define f_0dd7f0 f_0dd7f0_k1
#define f_0de880 f_0de880_k1
#define f_0e93f0 f_0e93f0_k1

#define f_112df0 f_112df0_k1
#define f_112e70 f_112e70_k1
#define f_112ec0 f_112ec0_k1
#define f_125400 f_125400_k1
#define f_1254a0 f_1254a0_k1
#define f_125ed0 f_125ed0_k1
#define f_12c050 f_12c050_k1
#define f_12d850 f_12d850_k1
#define f_12d9c0 f_12d9c0_k1
#define f_12db60 f_12db60_k1
#define f_12dce0 f_12dce0_k1
#define f_12e350 f_12e350_k1
#define f_1454d0 f_1454d0_k1
#define f_145850 f_145850_k1
#define f_147323 f_147323_k1
#define f_149360 f_149360_k1
#define f_149640 f_149640_k1
// P3 20/22 gleich (suche.py 30.10.2026, Basis tower2_t1_P1.CPP)
// tower2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12C660-0x12E960
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




#define EQI(x,v) (((x)==(v))?1:0)
extern int d_1c349c, d_1c3870, d_1c3498, d_1c2c64;
extern signed char d_1c0cf8, d_1c0d10, d_1c0d14, d_1c0d18, d_1c0d1c, d_1c0d3c, d_1c0d40;
extern short d_1c0428;
extern int *d_1c2c40;
extern const char d_1a8ca0[];
struct Ctx { int f0; char *p[13]; short s38; Ctx(void *a, void *b, void *c); ~Ctx(); };
struct Ty { char b[0xc]; Ty(int a); };
typedef short (*FNV)(int, int, int);
int f_0bf730(int p1, int p2);

int f_0bf680(int p1, int p2);
int f_0bde40(int p1);
int f_0bfa20(int, ...);
int f_0bf820(int, ...);
short f_0db9a0(int p1);
short f_060760(int p1);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060770(int p1, int p2);
signed char f_0423c0(int p1);
short f_044900(int p1, int p2, int p3);
short f_145850(int p1, int p2, int p3);
signed char f_149640(int p1);
int f_0de880(int p1);
int f_0dd750(int p1, int p2);
int f_12dce0(int, int, int, int, int);
void f_12d850();
void f_12d9c0(int p1);
void f_12db60(int p1);
int f_12e350(int p1, int p2);
int f_12c050();
int f_046d90(int p1, int p2);
int f_047120(int p1);
int f_046de0(int p1);
short f_042a60(int p1, int p2);
short f_042ac0(int p1, int p2);
int f_032820(int p1, int p2, int p3);
int f_042d00(int p1, int p2);
int f_042bb0(int p1, int p2);
int f_033c50(int p1, int p2, int p3);

signed char f_038e10(int p1, int p2);
int f_03d4b0(int p1, int p2, int p3);
int f_044850(int p1, int p2, int p3);
void f_12cbe0();
void f_12cde0();
void f_12ce40();
void f_12ce60();
void f_12ce80();
void f_12cea0();
void f_12cf00();
void f_12cf20(int p1);
void f_12d060(int p1);
void f_12d1a0(int p1);
void f_12d2e0(int p1);
void f_12d300();
void f_12d320();
void f_12d340();
void f_12d490();
void f_12d570(int p1);
void f_12d760(int p1);
void f_12d7a0(int p1);
void f_12d7e0();
void f_12d800();
#define MSG(n) f_0bf730((int)&d_1c2c64, n)
#define OBJ Ctx obj(&d_1c349c, &d_1c3870, &d_1c3498)
#define PM(o, k) (*(int *)(obj.p[k] + (o)))
#define DEL(o) if (o) delete (char *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0)))
#define SETG(v) do { short s_; int b_; d_1c0cf8 = (v); s_ = f_060760(0x1f50); b_ = d_1c0cf8 != 1; if ((d_1c0cf8 == 1 && s_ == 2) || (d_1c0cf8 == 0 && s_ == 1)) { f_060740(0x1f50, 1); f_0607e0(0x1f50, b_); } } while (0)
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041030();                                         // reg - stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f4f0(int p1, int p2);                           // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05f800(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
extern int d_1a8cbe;                    // 0x1A8CBE
extern int d_1a8cc2;                    // 0x1A8CC2
extern int d_1a8cc6;                    // 0x1A8CC6
extern int d_1a8cd0;                    // 0x1A8CD0 Breiten int,unsigned
extern int d_1a8ce0;                    // 0x1A8CE0
extern int d_1a8cea;                    // 0x1A8CEA
extern int d_1a9820;                    // 0x1A9820
extern int d_1c0004;                    // 0x1C0004
extern int d_1c040c;                    // 0x1C040C
extern int d_1c0420;                    // 0x1C0420
extern int d_1c0900;                    // 0x1C0900
extern int d_1c0d20;                    // 0x1C0D20
extern int d_1c0d24;                    // 0x1C0D24
extern int d_1c0d28;                    // 0x1C0D28
extern int d_1c0d2c;                    // 0x1C0D2C
extern int d_1c0d30;                    // 0x1C0D30
extern int d_1c0d34;                    // 0x1C0D34
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c21c8;                    // 0x1C21C8
extern int d_1c21dc;                    // 0x1C21DC
extern int d_1c21f0;                    // 0x1C21F0
extern int d_1c2204;                    // 0x1C2204
extern int d_1c2268;                    // 0x1C2268
extern int d_1c22cc;                    // 0x1C22CC
extern int d_1c2330;                    // 0x1C2330
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0
//@ f_12c660
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zentraler Ereignis-Verteiler (Dispatcher) der zweiten Ebene des Magierturms. Wertet die
 *   übergebene Ereignis- oder Objektkennung aus und verzweigt zu den jeweiligen Raumereignissen, Truhen, Türen,
 *   Nischen-Rätseln (0xd1, 0x192-0x194), Diamantenfassungen (0x1f46-0x1f48), Fallen, Kämpfen und
 *   Ebenenübergängen (0x1f8).
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt), p2 (16-Bit-Kennung des ausgelösten Dungeon-Ereignisses
 *   oder 3D-Objekts).
 * - Rückgabe: 1, wenn die Kennung behandelt wurde, sonst 0 im default-Zweig.
 * - Wichtige Variablen: r (Rückgabewert, Standard 1), obj_cc und obj_131 (lokale 60-Byte-Textkontexte für
 *   Namenseinsetzungen in Meldungen 0x270000b1 und 0x270000dd), q (dynamisch angelegtes Truhen-Objekt bei
 *   Kennung 0x67 mit Truhennummer 0x16).
 === Ende Beschreibung === */
int f_12c660(int p1, short p2) {
    int r = 1;
    char obj_cc[0x3c], obj_131[0x3c];
    switch ((unsigned short)p2) {
    case 0x65:
        ((void (*)(int))f_12cbe0)(p1);
        break;
    case 0x66:
        break;
    case 0x67: {
        int q = (int)new (mark(d_1a8ca0, 0x18b)) Ty(0x16);
        if (f_047120(q) != 0) f_046de0(q);
        if (q != 0) delete (char *)f_046d90(q, 0);
        break;
    }
    case 0xcc: {
        f_125400((int)obj_cc, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        *(int *)(*(int *)(obj_cc + 4) + 4) = f_039320(d_1c0004, 0x22);
        MSG(0x270000b1);
        ((int (*)(int, int))f_1254a0)((int)obj_cc, 0);
        break;
    }
    case 0xcd:
        MSG(0x270000b2);
        break;
    case 0xce:
        f_12cf20(p1);
        break;
    case 0xcf:
        f_12d060(p1);
        break;
    case 0xd0:
        f_12d1a0(p1);
        break;
    case 0xd1: {
        int q = p1;
        f_12dce0(q, (int)&d_1c0d20, p1 = 0x270000b7, 0x1f4b, 0x27000d);
        break;
    }
    case 0x131: {
        f_125400((int)obj_131, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        *(int *)(*(int *)(obj_131 + 4) + 4) = f_038c40(d_1c0004);
        MSG(0x270000dd);
        ((int (*)(int, int))f_1254a0)((int)obj_131, 0);
        break;
    }
    case 0x132:
        ((void (*)(int))f_12d850)(p1);
        break;
    case 0x191:
        MSG(0x270000df);
        break;
    case 0x192: {
        int q = p1;
        f_12dce0(q, (int)&d_1c0d24, p1 = 0x270000e0, 0x1f4d, 0x270010);
        break;
    }
    case 0x193: {
        int q = p1;
        f_12dce0(q, (int)&d_1c0d28, p1 = 0x270000e1, 0x1f4f, 0x27000e);
        break;
    }
    case 0x194: {
        int q = p1;
        f_12dce0(q, (int)&d_1c0d2c, p1 = 0x270000e2, 0x1f4e, 0x27000f);
        break;
    }
    case 0x1f5:
        f_12d9c0(p1);
        break;
    case 0x1f6:
        f_12db60(p1);
        break;
    case 0x1f8:
        if (f_0bf6f0((int)&d_1c2c64, 0x270000ea) == r)
            f_0dd7f0(d_1c0004, 0x15, 0x1392);
        break;
    case 0x1b59:
    case 0x1f41:
        f_05fa00(0x42, 0x1f41);
        break;
    case 0x1b5a:
    case 0x1f42:
        f_05fa00(0x43, 0x1f42);
        break;
    case 0x1b5b:
    case 0x1f43:
        f_05fa00(0x44, 0x1f43);
        break;
    case 0x1b5c:
    case 0x1f44:
        f_05fa00(0x45, 0x1f44);
        break;
    case 0x1b5d:
    case 0x1f45:
        f_05fa00(0x46, 0x1f45);
        break;
    case 0x1776:
    case 0x1f46:
        f_12d570(p1);
        break;
    case 0x1f47:
        if (f_12e350(p1, 1) != 0) {
            f_060770(0x1f47, 0);
            f_0607e0(0x1f47, 1);
            f_0dcbb0(d_1c0004, 5);
        }
        break;
    case 0x1f48:
        if (f_12e350(p1, 2) != 0) {
            f_060770(0x1f48, 0);
            f_0607e0(0x1f48, 1);
            f_0dcbb0(d_1c0004, 5);
        }
        break;
    case 0x1b61:
    case 0x1f49:
        f_05fa00(0x47, 0x1f49);
        break;
    case 0x1b62:
    case 0x1f4a:
        f_05fa00(0x48, 0x1f4a);
        break;
    default: r = 0; break;
    }
    return r;
}
//@ f_12cbe0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Interaktion mit dem versperrten Durchgang bzw. Mechanismus 0x1f50 (Ereignis
 *   0x65). Prüft über f_12c050, ob ein passender Held oder Gegenstand vorhanden ist, fragt den Spieler je nach
 *   Zustand von d_1c0cf8 per Ja/Nein-Dialog (0x270000ac bzw. 0x270000ae), schaltet das Flag d_1c0cf8 auf 0,
 *   aktualisiert Objekt 0x1f50 samt Automap und versetzt die aktive Gruppe über f_0dd7f0 auf Zielposition 0x13fe
 *   (Ebene 0x13).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: r (beteiligter Held aus f_12c050, sonst Gruppenanführer über f_038c40), s_ (Zustand von
 *   Objekt 0x1f50), b_ (Automap-Flag), lokaler Textkontext obj zur Namensformatierung.
 === Ende Beschreibung === */
void f_12cbe0() {
    OBJ;
    int r = f_12c050();
    if (EQI(d_1c0cf8, 1)) {
        if (r == 0) { MSG(0x270000ab); goto ende; }
        PM(4, 0) = f_038c40(r);
        if (f_0bf6f0((int)&d_1c2c64, 0x270000ac) != 1) goto ende;
        {
            short s_;
            unsigned short b_;
            s_ = f_060760((d_1c0cf8 = 0, 0x1f50));
            b_ = EQI(d_1c0cf8, 1) ? 0 : 1;
            if ((EQI(d_1c0cf8, 1) && s_ == (short)2) ||
                (EQI(d_1c0cf8, 0) && s_ == (short)1)) {
                f_060740(0x1f50, 1);
                f_0607e0(0x1f50, (signed char)b_);
            }
            f_0dd7f0(d_1c0004, 0x13, 0x13fe);
        }
    } else {
        if (r == 0) { MSG(0x270000ad); return; }
        PM(4, 0) = f_038c40(r);
        if (f_0bf6f0((int)&d_1c2c64, 0x270000ae) != 1) goto ende;
        {
            short s_;
            unsigned short b_;
            d_1c0cf8 = 0;
            s_ = f_060760(0x1f50);
            b_ = EQI(d_1c0cf8, 1) ? 0 : 1;
            if ((EQI(d_1c0cf8, 1) && s_ == (short)2) ||
                (EQI(d_1c0cf8, 0) && s_ == (short)1)) {
                f_060740(0x1f50, 1);
                f_0607e0(0x1f50, (signed char)b_);
            }
            f_0dd7f0(d_1c0004, 0x13, 0x13fe);
        }
    }
ende:;
}

//@ f_12cdd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leere Platzhalter-Methode in der virtuellen Methodentabelle der Turmebene 2 (entspricht dem
 *   leeren Zweig case 0x66 im Dispatcher).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12cdd0(void)
{
}

//@ f_12cde0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet auf Turmebene 2 die Schatztruhe mit der Kennung 0x16 (22): legt ein temporäres
 *   Truhenobjekt an, prüft über f_047120, ob die Truhe geöffnet werden kann, zeigt den Truheninhalt über
 *   f_046de0 an und gibt das Objekt wieder frei.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: p1 (Zeiger auf das dynamisch erzeugte 12-Byte-Truhenobjekt für Truhe 0x16).
 === Ende Beschreibung === */
void f_12cde0() {
    int p1 = (int)new (mark(d_1a8ca0, 0x18b)) Ty(0x16);
    if (f_047120(p1) != 0) f_046de0(p1);
    if (p1 != 0) delete (char *)f_046d90(p1, 0);
}
//@ f_12ce40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f41 durch Aufruf der allgemeinen Tür-Routine f_05fa00 mit
 *   Tür-Index 0x42 (66).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12ce40() {
    f_05fa00(0x42, 0x1f41);
}
//@ f_12ce60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f42 durch Aufruf der allgemeinen Tür-Routine f_05fa00 mit
 *   Tür-Index 0x43 (67).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12ce60() {
    f_05fa00(0x43, 0x1f42);
}
//@ f_12ce80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f43 durch Aufruf der allgemeinen Tür-Routine f_05fa00 mit
 *   Tür-Index 0x44 (68).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12ce80() {
    f_05fa00(0x44, 0x1f43);
}
//@ f_12cea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt den besten Helden der aktiven Gruppe für Talent 0x22 (34, Sinnenschärfe/Magiekunde
 *   über f_039320), trägt ihn in den Textkontext ein und gibt die Beobachtungsmeldung 0x270000b1 (Ereignis 0xcc)
 *   aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: obj (lokaler Textkontext, in dessen ersten Objektslot der gefundene Held eingetragen
 *   wird).
 === Ende Beschreibung === */
void f_12cea0() {
    OBJ;
    PM(4, 0) = f_039320(d_1c0004, 0x22);
    MSG(0x270000b1);
}
//@ f_12cf00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt bei Betreten des Feldes 0xcd die Raum- oder Hinweisbeschreibung 0x270000b2 im
 *   Meldungsfenster aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12cf00() {
    MSG(0x270000b2);
}
//@ f_12cf20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim ersten Betreten (d_1c0d14 == 0, Ereignis 0xce) eine magische Erscheinung samt
 *   Kampf Nr. 0x24 (36) aus. Zeigt zunächst das Grafikelement 4 aus Ressource 0x270001 mit Text 0x270000b3 an;
 *   ist mehr als ein Held in der Gruppe handlungsfähig (f_0db9a0), würfelt ein zufälliger Held eine
 *   Eigenschaftsprobe auf 0xb (11, vermutlich Totenangst/Aberglaube) erschwert um 3 - 2 * d_1c0d10 und flieht
 *   bei Misslingen (s >= 0) mit Meldung 0x270000b4 auf Feld 0x1597; anschließend wird über die virtuelle Methode
 *   des Ebenenobjekts Kampf 0x24 gestartet und bei Sieg d_1c0d14 = 1 sowie der Zähler d_1c0d10 erhöht.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: o (geladenes Bildobjekt), u (ausgewählter Held), k (Probenmodifikator 3 - c * 2, sinkt
 *   mit jedem bereits bestandenen Spuk-Ereignis d_1c0d10), s (Probenergebnis).
 === Ende Beschreibung === */
void f_12cf20(int p1) {
    OBJ;
    if (EQI(d_1c0d14, 0)) {
        int o, u;
        short s;
        f_0bf6c0((int)&d_1c2c64, 5);
        o = f_0606a0(0x270001, 4);
        f_0bde40((int)&d_1c2c64);
        f_0bfa20((int)&d_1c2c64, o, 0x0, 0x270000b3, 0x0);
        DEL(o);
        ((int (*)(int))f_0bf680)((int)&d_1c2c64);
        if (1 < f_0db9a0(d_1c0004)) {
            signed char c;
            short k;
            { int t_ = (int)(d_1c0004); u = f_039660(t_, 0xb); }
            c = d_1c0d10;
            k = 3 - c * 2;
            s = f_044900(u, 0xb, k);
            if (s >= 0) {
                PM(4, 0) = u;
                MSG(0x270000b4);
                f_0dd750(((int (*)(int, ...))f_041030)(1, u), 0x1597);
            }
        }
        FNV *vt = *(FNV **)(p1 + 8);
        if (vt[0](p1, 0x24, 0) == 0) {
            d_1c0d10 = d_1c0d10 + 1;
            d_1c0d14 = 1;
        }
    }
}
//@ f_12d060
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim ersten Betreten (d_1c0d18 == 0, Ereignis 0xcf) das zweite
 *   Spuk-/Erscheinungsereignis samt Kampf Nr. 0x25 (37) aus. Zeigt Bild 5 aus Ressource 0x270001 mit Text
 *   0x270000b5, prüft bei Gruppengröße über 1 eine Angstprobe (0xb, Modifikator 3 - 2 * d_1c0d10), lässt einen
 *   verängstigten Helden auf Feld 0x1521 fliehen und startet danach Kampf 0x25; bei Sieg werden d_1c0d10
 *   inkrementiert und d_1c0d18 = 1 gesetzt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: o (Bildobjekt), u (geprüfter Held), k (Probenmodifikator), s (Probenergebnis).
 === Ende Beschreibung === */
#define F680(a) (((int (*)(int))f_0bf680)(a))
#define F1030(a, b) (((int (*)(int, ...))f_041030)(a, b))
void f_12d060(int p1) {
    OBJ;
    if (EQI(d_1c0d18, 0)) {
        int o, u;
        short s;
        f_0bf6c0((int)&d_1c2c64, 5);
        o = f_0606a0(0x270001, 5);
        f_0bde40((int)&d_1c2c64);
        f_0bfa20((int)&d_1c2c64, o, 0x0, 0x270000b5, 0x0);
        DEL(o);
        F680((int)&d_1c2c64);
        if (1 < f_0db9a0(d_1c0004)) {
            signed char c;
            short k;
            { int t_ = (int)(d_1c0004); u = f_039660(t_, 0xb); }
            c = d_1c0d10;
            k = 3 - c * 2;
            s = f_044900(u, 0xb, k);
            if (s >= 0) {
                PM(4, 0) = u;
                MSG(0x270000b4);
                f_0dd750(F1030(1, u), 0x1521);
            }
        }
        FNV *vt = *(FNV **)(p1 + 8);
        if (vt[0](p1, 0x25, 0) == 0) {
            d_1c0d10 = d_1c0d10 + 1;
            d_1c0d18 = 1;
        }
    }
}
//@ f_12d1a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst beim ersten Betreten (d_1c0d1c == 0, Ereignis 0xd0) das dritte
 *   Spuk-/Erscheinungsereignis samt Kampf Nr. 0x26 (38) aus. Zeigt Bild 4 aus Ressource 0x270001 mit Text
 *   0x270000b6, führt bei mehr als einem aktiven Helden die Angstprobe (0xb, Modifikator 3 - 2 * d_1c0d10) mit
 *   eventueller Flucht nach 0x13fe durch und startet anschließend Kampf 0x26; bei Sieg werden d_1c0d10 erhöht
 *   und d_1c0d1c = 1 gesetzt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: o (Bildobjekt), u (geprüfter Held), k (Probenmodifikator), s (Probenergebnis).
 === Ende Beschreibung === */
#define F680(a) (((int (*)(int))f_0bf680)(a))
#define F1030(a, b) (((int (*)(int, ...))f_041030)(a, b))
void f_12d1a0(int p1) {
    OBJ;
    if (EQI(d_1c0d1c, 0)) {
        int o, u;
        short s;
        f_0bf6c0((int)&d_1c2c64, 5);
        o = f_0606a0(0x270001, 4);
        f_0bde40((int)&d_1c2c64);
        f_0bfa20((int)&d_1c2c64, o, 0x0, 0x270000b6, 0x0);
        DEL(o);
        F680((int)&d_1c2c64);
        if (1 < f_0db9a0(d_1c0004)) {
            signed char c;
            short k;
            { int t_ = (int)(d_1c0004); u = f_039660(t_, 0xb); }
            c = d_1c0d10;
            k = 3 - c * 2;
            s = f_044900(u, 0xb, k);
            if (s >= 0) {
                PM(4, 0) = u;
                MSG(0x270000b4);
                f_0dd750(F1030(1, u), 0x13fe);
            }
        }
        FNV *vt = *(FNV **)(p1 + 8);
        if (vt[0](p1, 0x26, 0) == 0) {
            d_1c0d10 = d_1c0d10 + 1;
            d_1c0d1c = 1;
        }
    }
}
//@ f_12d2e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die erste der vier versiegelten Wandnischen (0x1f4b, Ereignis 0xd1) durch Aufruf
 *   von f_12dce0 mit dem Statusflag d_1c0d20, dem Silbentext 0x270000b7 und dem Klang 0x27000d.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Übergibt die Adresse des Nischenflags d_1c0d20.
 === Ende Beschreibung === */
void f_12d2e0(int p1) {
    f_12dce0(p1, (int)&d_1c0d20, 0x270000b7, 0x1f4b, 0x27000d);
}
//@ f_12d300
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f44 über die allgemeine Tür-Routine f_05fa00 mit Tür-Index 0x45
 *   (69).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d300() {
    f_05fa00(0x45, 0x1f44);
}
//@ f_12d320
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f45 über die allgemeine Tür-Routine f_05fa00 mit Tür-Index 0x46
 *   (70).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d320() {
    f_05fa00(0x46, 0x1f45);
}
//@ f_12d340
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lässt den Spieler einen Helden und einen Gegenstand aus dessen Inventar auswählen, um an der
 *   Apparatur 0x1f46 (Option "Gegenstand benutzen") zu hantieren. Handelt es sich um eine zerbrechliche
 *   Nahkampfwaffe, zerbricht diese bei dem Versuch (f_033c50, Meldung 0x270000c9), während bei bereits
 *   zerbrochener Waffe (0x270000ca), unzerbrechlicher Waffe (0x270000cb) oder einem sonstigen Gegenstand
 *   (0x270000cc) passende Fehlschlagsmeldungen erscheinen.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: a (ausgewählter Held), w / i5 (gewählter Inventarplatz), sx (Gegenstands-ID), uv6
 *   (Zeiger auf die Gegenstandsdefinition in d_1c2c40), uv2 (Stückzahl), m (auszugebende Textkennung).
 === Ende Beschreibung === */
void f_12d340() {
    int a, i5, i4, uv6, m;
    short w;
    int sx;
    a = f_038d70(d_1c0004, 0x270000d3);
    if (a == 0) return;
    OBJ;
    PM(4, 0) = a;
    w = f_032820(a, 0x270000d4, 1);
    if ((i5 = (short)w) == -1) return;
    sx = f_042a60(a, i5);
    uv6 = d_1c2c40[sx];
    PM(4, 2) = uv6;
    int uv2;
    uv2 = ((RivaItemDefinition*)(uv6))->f_0a7950() ? f_042ac0(a, i5) : 1;
    sx = (sx & 0) ? 0 : sx; // haelt den Register-Web-Gleichstand fuer sx
    *(short *)(obj.p[7] + 2) = uv2;
    PM(4, 0) = a;
    if (((RivaItemDefinition*)(uv6))->f_0a7990() == 1) {
        i4 = (short)w;
        if (f_042d00(a, i4) == 1 && ((RivaItemDefinition*)(uv6))->f_0a78f0() == 0) {
            if (f_042bb0(a, i4) == 0) {
                MSG(0x270000c9);
                f_033c50(a, i4, 1);
                return;
            }
            m = 0x270000ca;
            goto Lmsg;
        }
    }
    if (((RivaItemDefinition*)(uv6))->f_0a7990() == 1) {
        if (f_042d00(a, (int)w) == 0) {
            m = 0x270000cb;
            goto Lmsg;
        }
    }
    m = 0x270000cc;
Lmsg:
    MSG(m);
}
//@ f_12d490
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den Versuch des Gruppenanführers aus, mit bloßen Händen in die Apparatur 0x1f46 zu
 *   greifen. Würfelt eine Probe auf Eigenschaft 4 (Fingerfertigkeit/Geschicklichkeit) ohne Zuschlag; bei Erfolg
 *   erleidet der Anführer je nach Rüstungsschutz (rs_bonus < 5) 1 oder 2 Schadenspunkte (Meldung 0x270000c7),
 *   bei Misslingen 1W6+2 bzw. 1W4+1 Schadenspunkte (Meldung 0x270000c8) über f_044850.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: p1 (Gruppenanführer), s (Ergebnis der Eigenschaftsprobe), v (berechneter
 *   Lebenspunkte-Schaden).
 === Ende Beschreibung === */
void f_12d490() {
    OBJ;
    int p1;
    short v, s;
    p1 = f_038c40(d_1c0004);
    PM(4, 0) = p1;
    s = f_044900(p1, 4, 0);
    if (s > 0) {
        {
            unsigned char codex_bool_392 = (f_0423c0(p1) < 5);
            v = codex_bool_392 + 1;
        }
        MSG(0x270000c7);
    } else {
        if (f_0423c0(p1) < 5)
            v = f_145850(1, 6, 2);
        else
            v = f_145850(1, 4, 1);
        MSG(0x270000c8);
    }
    f_044850(p1, v, 1);
}
//@ f_12d570
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hauptinteraktion mit der ersten Diamantenfassung bzw. dem Kristallmechanismus 0x1f46. Ist
 *   das Rätsel bereits gelöst (d_1c0d3c == 1) und steht das Objekt im Zustand 2, wird es je nach Gruppenposition
 *   direkt umgeschaltet; andernfalls öffnet die Funktion ein Auswahlmenü (0x270000c0: Zaubern,
 *   Hineingreifen/Gegenstand benutzen oder Diamanten einsetzen über f_12e350(p1, 0)), vergibt beim erstmaligen
 *   Lösen 10 Abenteuerpunkte (f_0dcbb0), setzt Flag 0x2c (f_091f70) und startet die Objektanimation 0x1f46.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: obj (lokaler 60-Byte-Textkontext), t (zauberkundiger Held bei Wahl der Zauberoption).
 === Ende Beschreibung === */
void f_12d570(int p1) {
    char obj[0x3c];
    if (EQI(d_1c0d3c, 1) && ((int (*)(int))f_149640)(0x1f46) == 2 &&
        (f_0de880(d_1c0004) >> 16) > -0xd2) {
        f_060770(0x1f46, 0);
        f_0607e0(0x1f46, 1);
        return;
    }
    if ((*(short *)&d_1c0d40 != -1) ? 1 : 0) {
        f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        switch ((unsigned short)(f_0bf820((int)&d_1c2c64, 0x270000c0, 3, 0x270000c1, 0x270000c2, 0x270000c3) + 1)) {
        case 0:
            break;
        case 1:
            break;
        case 2: {
            int t = ((int (*)(int, int))f_038e10)(d_1c0004, 0x20000155);
            if (t) {
                d_1c0428 = 1;
                f_03d4b0(t, 1, 0);
            }
            break;
        }
        case 3:
            switch ((unsigned short)((unsigned short (*)(int,...))f_0bf820)((int)&d_1c2c64, 0x270000c4, 2, 0x270000c5, 0x270000c6)) {
            case 1: f_12d490(); break;
            case 2: f_12d340(); break;
            }
            break;
        case 4:
            if (f_12e350(p1, 0) == 0) break;
            if (EQI(d_1c0d3c, 0)) {
                d_1c0d3c = 1;
                f_091f70(0x2c);
                f_0dcbb0(d_1c0004, 10);
            }
            f_060770(0x1f46, 0);
            f_0607e0(0x1f46, 1);
            ((int (*)(int, int))f_1254a0)((int)obj, 0);
            return;
        }
        ((int (*)(int, int))f_1254a0)((int)obj, 0);
    }
}

//@ f_12d760
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die zweite Diamantenfassung (0x1f47, Index 1 in f_12e350, erwartet blauen und
 *   grünen Diamanten). Wurde die richtige Diamantenkombination eingesetzt, spielt die Funktion die Animation von
 *   Objekt 0x1f47 ab, aktualisiert die Automap und vergibt 5 Abenteuerpunkte an die Gruppe.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d760(int p1) {
    if (f_12e350(p1, 1) != 0) {
        f_060770(0x1f47, 0);
        f_0607e0(0x1f47, 1);
        f_0dcbb0(d_1c0004, 5);
    }
}
//@ f_12d7a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die dritte Diamantenfassung (0x1f48, Index 2 in f_12e350, erwartet roten und
 *   blauen Diamanten). Bei erfolgreicher Kombination werden Objekt 0x1f48 und die Automap umgeschaltet und 5
 *   Abenteuerpunkte vergeben.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d7a0(int p1) {
    if (f_12e350(p1, 2) != 0) {
        f_060770(0x1f48, 0);
        f_0607e0(0x1f48, 1);
        f_0dcbb0(d_1c0004, 5);
    }
}
//@ f_12d7e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f49 über die allgemeine Tür-Routine f_05fa00 mit Tür-Index 0x47
 *   (71).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d7e0() {
    f_05fa00(0x47, 0x1f49);
}
//@ f_12d800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt den Gruppenanführer (f_038c40) und gibt mit seinem Namen die Raum- bzw.
 *   Ereignismeldung 0x270000dd (Ereignis 0x131) aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: obj (lokaler Textkontext für den Namen des Gruppenanführers).
 === Ende Beschreibung === */
void f_12d800() {
    OBJ;
    PM(4, 0) = f_038c40(d_1c0004);
    MSG(0x270000dd);
}

#undef DEL
#undef EQI
#undef F1030
#undef F680
#undef MSG
#undef OBJ
#undef PM
#undef SETG
#undef d_1a8ca0
#undef d_1a8cbe
#undef d_1a8cc6
#undef d_1a8cd0
#undef d_1a8ce0
#undef d_1a8cea
#undef d_1a9820
#undef d_1c0004
#undef d_1c040c
#undef d_1c0420
#undef d_1c0428
#undef d_1c0900
#undef d_1c0cf8
#undef d_1c0d10
#undef d_1c0d14
#undef d_1c0d18
#undef d_1c0d1c
#undef d_1c0d20
#undef d_1c0d24
#undef d_1c0d28
#undef d_1c0d2c
#undef d_1c0d30
#undef d_1c0d34
#undef d_1c0d3c
#undef d_1c0d40
#undef d_1c21b4
#undef d_1c21c8
#undef d_1c21dc
#undef d_1c21f0
#undef d_1c2204
#undef d_1c2268
#undef d_1c22cc
#undef d_1c2330
#undef d_1c299c
#undef d_1c2c40
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef d_1c38b0
#undef f_032820
#undef f_033c50
#undef f_038c40
#undef f_038d70
#undef f_038e10
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0397d0
#undef f_03d4b0
#undef f_040780
#undef f_041030
#undef f_0423c0
#undef f_042a60
#undef f_042ac0
#undef f_042bb0
#undef f_042d00
#undef f_044850
#undef f_044900
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_047120
#undef f_05f190
#undef f_05f220
#undef f_05f4f0
#undef f_05f580
#undef f_05f800
#undef f_05fa00
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_060770
#undef f_0607e0
#undef f_091f70



#undef f_0bde40
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf820
#undef f_0bfa20
#undef f_0bfea0
#undef f_0db9a0
#undef f_0dcbb0
#undef f_0dd1d0
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de880
#undef f_0e93f0

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_12c050
#undef f_12d850
#undef f_12d9c0
#undef f_12db60
#undef f_12dce0
#undef f_12e350
#undef f_1454d0
#undef f_145850
#undef f_147323
#undef f_149360
#undef f_149640

// ===== Teil tower2_t2 (p3, 12d850-12e960) =====
#define d_1a8ca0 d_1a8ca0_k2
#define d_1a8cbe d_1a8cbe_k2
#define d_1a8cc6 d_1a8cc6_k2
#define d_1a8cd0 d_1a8cd0_k2
#define d_1a8ce0 d_1a8ce0_k2
#define d_1a8cea d_1a8cea_k2
#define d_1a9820 d_1a9820_k2
#define d_1c0004 d_1c0004_k2
#define d_1c040c d_1c040c_k2
#define d_1c0420 d_1c0420_k2
#define d_1c0428 d_1c0428_k2
#define d_1c0900 d_1c0900_k2
#define d_1c0cf8 d_1c0cf8_k2
#define d_1c0d10 d_1c0d10_k2
#define d_1c0d14 d_1c0d14_k2
#define d_1c0d18 d_1c0d18_k2
#define d_1c0d1c d_1c0d1c_k2
#define d_1c0d20 d_1c0d20_k2
#define d_1c0d24 d_1c0d24_k2
#define d_1c0d28 d_1c0d28_k2
#define d_1c0d2c d_1c0d2c_k2
#define d_1c0d30 d_1c0d30_k2
#define d_1c0d34 d_1c0d34_k2
#define d_1c0d3c d_1c0d3c_k2
#define d_1c0d40 d_1c0d40_k2
#define d_1c21b4 d_1c21b4_k2
#define d_1c21c8 d_1c21c8_k2
#define d_1c21dc d_1c21dc_k2
#define d_1c21f0 d_1c21f0_k2
#define d_1c2204 d_1c2204_k2
#define d_1c2268 d_1c2268_k2
#define d_1c22cc d_1c22cc_k2
#define d_1c2330 d_1c2330_k2
#define d_1c299c d_1c299c_k2
#define d_1c2c40 d_1c2c40_k2
#define d_1c2c44 d_1c2c44_k2
#define d_1c2c64 d_1c2c64_k2
#define d_1c2edc d_1c2edc_k2
#define d_1c3498 d_1c3498_k2
#define d_1c349c d_1c349c_k2
#define d_1c3870 d_1c3870_k2
#define d_1c38b0 d_1c38b0_k2
#define f_032820 f_032820_k2
#define f_033c50 f_033c50_k2
#define f_038c40 f_038c40_k2
#define f_038d70 f_038d70_k2
#define f_038e10 f_038e10_k2
#define f_039320 f_039320_k2
#define f_039420 f_039420_k2
#define f_039660 f_039660_k2
#define f_0397d0 f_0397d0_k2
#define f_03d4b0 f_03d4b0_k2
#define f_040780 f_040780_k2
#define f_0423c0 f_0423c0_k2
#define f_042a60 f_042a60_k2
#define f_042ac0 f_042ac0_k2
#define f_042bb0 f_042bb0_k2
#define f_042d00 f_042d00_k2
#define f_044850 f_044850_k2
#define f_044900 f_044900_k2
#define f_046d10 f_046d10_k2
#define f_046d90 f_046d90_k2
#define f_046de0 f_046de0_k2
#define f_047120 f_047120_k2
#define f_05f190 f_05f190_k2
#define f_05f220 f_05f220_k2
#define f_05f4f0 f_05f4f0_k2
#define f_05f580 f_05f580_k2
#define f_05f800 f_05f800_k2
#define f_05fa00 f_05fa00_k2
#define f_0606a0 f_0606a0_k2
#define f_060740 f_060740_k2
#define f_060760 f_060760_k2
#define f_060770 f_060770_k2
#define f_0607e0 f_0607e0_k2
#define f_091f70 f_091f70_k2



#define f_0bde40 f_0bde40_k2
#define f_0bf680 f_0bf680_k2
#define f_0bf6c0 f_0bf6c0_k2
#define f_0bf6f0 f_0bf6f0_k2
#define f_0bf730 f_0bf730_k2
#define f_0bf820 f_0bf820_k2
#define f_0bfa20 f_0bfa20_k2
#define f_0db9a0 f_0db9a0_k2
#define f_0dcbb0 f_0dcbb0_k2
#define f_0dd1d0 f_0dd1d0_k2
#define f_0dd750 f_0dd750_k2
#define f_0dd7f0 f_0dd7f0_k2
#define f_0de880 f_0de880_k2
#define f_0e93f0 f_0e93f0_k2

#define f_112df0 f_112df0_k2
#define f_112e70 f_112e70_k2
#define f_112ec0 f_112ec0_k2
#define f_125400 f_125400_k2
#define f_1254a0 f_1254a0_k2
#define f_125ed0 f_125ed0_k2
#define f_12c050 f_12c050_k2
#define f_1454d0 f_1454d0_k2
#define f_145850 f_145850_k2
#define f_147323 f_147323_k2
#define f_149360 f_149360_k2
#define f_149640 f_149640_k2
// P3 15/17 gleich (suche.py 30.10.2026, Basis tower2_t2_P1.CPP)
// tower2_t2 (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12D850-0x12E960
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_032820(int,int,int);                   // reg eax edx ebx stapel 0
int f_033c50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041030(int, int);                                         // reg - stapel 0
int f_0423c0(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_042ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_042bb0(int p1, int p2);                           // reg eax edx stapel 0
int f_042d00(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044900(int,int,int);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_047120(int p1);                                   // reg eax stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f4f0(int p1, int p2);                           // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
short f_05f800(int,int);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int,int);           // reg eax stapel 0
int f_060760(int);                                   // reg eax stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int,int);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820(int, ...);                                         // reg - stapel 0
int f_0bfa20(int, ...);                                         // reg - stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
short f_0db9a0(int);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_12c050();                                         // reg - stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
short f_149360(int, int);                       // nicht in clobber.tsv
int f_149640(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a8cea;                    // 0x1A8CEA
extern int d_1a9820;                    // 0x1A9820
extern int d_1c0004;                    // 0x1C0004
extern int d_1c040c;                    // 0x1C040C
extern int d_1c0420;                    // 0x1C0420
extern int d_1c0428;                    // 0x1C0428
extern int d_1c0900;                    // 0x1C0900
extern int d_1c0cf8;                    // 0x1C0CF8
extern int d_1c0d10;                    // 0x1C0D10
extern int d_1c0d14;                    // 0x1C0D14
extern int d_1c0d18;                    // 0x1C0D18
extern int d_1c0d1c;                    // 0x1C0D1C
extern int d_1c0d3c;                    // 0x1C0D3C
extern int d_1c0d40;                    // 0x1C0D40
extern int d_1c2c40;                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a8ca0[];           // Text 0x1A8CA0
int f_14572e(char *, const char *, ...);
int f_144bf0(const char *, const char *);
#pragma aux f_041030 "*" parm caller [];
#define NE1(e) ((e) != -1)
typedef signed char FL;
extern FL d_1c0d20, d_1c0d24, d_1c0d28, d_1c0d2c, d_1c0d30, d_1c0d34;
extern char d_1c21b4[], d_1c21c8[], d_1c21dc[], d_1c21f0[], d_1c2204[], d_1c2268[], d_1c22cc[], d_1c2330[], d_1c299c[];
extern const char d_1b8510[], d_1b851c[], d_1c349c[], d_1c3870[], d_1c3498[];
extern char d_1a8ce0[];
extern short d_1a8cc6[];
extern int d_1a8cd0[];
struct S8 { short s[4]; };
extern S8 d_1a8cbe;
struct Rec { short id; int a; int b; int v; };
struct T12 { int a[3]; };
struct T20 { int a[5]; };
struct SO { int a; int *p; char c[52]; SO(const char*,const char*,const char*); ~SO(); };
void f_12dce0(int, FL *, int, unsigned, int);
int f_12df80(int, int);
#define CH ((int)&d_1c2c64)
#define EQI(x,v) (((x)==(v))?1:0)
#define SLOT(o,off) (*(int **)((char *)&(o) + (off)))
#define VC3(p,a,b) ((short(*)(int,int,int))(**(int**)((p)+8)))((p),(a),(b))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_12d850
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Fallgrube bzw. das Bodenluken-Objekt 0x1f46 bei Ereignis 0x132. Legt ein
 *   12-Byte-Fallgrubenobjekt an, prüft über f_05f580, ob die Gruppe hineinfällt, gibt die Meldung 0x270000de aus
 *   und versetzt alle betroffenen Teilgruppen (f_05f800) über f_0dd750 auf das Zielfeld 0x15f2 der
 *   darunterliegenden Ebene.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: p1 (Fallgrubenobjekt), sVar1 (Anzahl betroffener Gruppen in Puffer d_1c21b4), sVar4
 *   (Schleifenzähler).
 === Ende Beschreibung === */
void f_12d850(void)
{
  struct LD { int a; int get() { return a; } };
  int t, p1, iVar3;
  short sVar1, sVar4;
  t = (int)new (mark(d_1a8ca0, 0x406)) T12;
  p1 = (t) ? f_05f190(t, 0, 0x1f46) : t;
  iVar3 = f_05f580(p1);
  if (iVar3 != 0) {
    SO o(d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = f_038c40(d_1c0004);
    f_0bf730(CH, 0x270000de);
    sVar4 = 0;
    sVar1 = f_05f800(p1, (int)d_1c21b4);
    if (sVar1 > (short)0) {
      do {
        f_0dd750(((LD *)&d_1c21b4)[sVar4].get(), 0x15f2);
        sVar4 = sVar4 + 1;
      } while (sVar4 < sVar1);
    }
    f_05f4f0(p1, 0);
  }
  if (p1 != 0) delete (char *)f_05f220(p1, 0);
}
//@ f_12d940
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt bei Ereignis 0x191 die Textmeldung 0x270000df im Meldungsfenster aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12d940(void)
{
  f_0bf730(CH, 0x270000df);
}
//@ f_12d960
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die zweite versiegelte Wandnische (0x1f4d, Ereignis 0x192) durch Aufruf von
 *   f_12dce0 mit Statusflag d_1c0d24, Silbentext 0x270000e0 und Klang 0x270010.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Übergibt die Adresse des Nischenflags d_1c0d24.
 === Ende Beschreibung === */
void f_12d960(int p1)
{
  f_12dce0(p1, &d_1c0d24, 0x270000e0, 0x1f4d, 0x270010);
}
//@ f_12d980
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die dritte versiegelte Wandnische (0x1f4f, Ereignis 0x193) durch Aufruf von
 *   f_12dce0 mit Statusflag d_1c0d28, Silbentext 0x270000e1 und Klang 0x27000e.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Übergibt die Adresse des Nischenflags d_1c0d28.
 === Ende Beschreibung === */
void f_12d980(int p1)
{
  f_12dce0(p1, &d_1c0d28, 0x270000e1, 0x1f4f, 0x27000e);
}
//@ f_12d9a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die vierte versiegelte Wandnische (0x1f4e, Ereignis 0x194) durch Aufruf von
 *   f_12dce0 mit Statusflag d_1c0d2c, Silbentext 0x270000e2 und Klang 0x27000f.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Übergibt die Adresse des Nischenflags d_1c0d2c.
 === Ende Beschreibung === */
void f_12d9a0(int p1)
{
  f_12dce0(p1, &d_1c0d2c, 0x270000e2, 0x1f4e, 0x27000f);
}
//@ f_12d9c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Mehrstufiges Gefahren- und Kampffeld (Ereignis 0x1f5, Status d_1c0d34). Beim ersten Betreten
 *   (d_1c0d34 == 0) erleidet ein Held mit niedrigem Wert in Talent 0x12 (18) 3 Schadenspunkte (f_044850) und
 *   flieht bei mehreren Helden nach Feld 0x146b; danach (d_1c0d34 == 1) erscheint Bild 6 aus 0x270001 mit Text
 *   0x270000e5, ein Held würfelt eine erschwerte Angstprobe (0xb, Zuschlag -6) mit eventueller Flucht nach
 *   0x146b, und schließlich startet Kampf Nr. 0x27 (39), dessen Sieg d_1c0d34 = 2 setzt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: uVar2 (betroffener Held), p1_00 (geladenes Bildobjekt), sVar1 (Gruppengröße bzw.
 *   Probenergebnis).
 === Ende Beschreibung === */
void f_12d9c0(int p1)
{
  short sVar1;
  int uVar2, p1_00;
  SO o(d_1c349c, d_1c3870, d_1c3498);
  if (EQI(d_1c0d34, 0)) {
    uVar2 = f_039420(d_1c0004, 0x12);
    o.p[1] = uVar2;
    f_0bf730(CH, 0x270000e3);
    f_044850(uVar2, 3, 5);
    sVar1 = f_0db9a0(d_1c0004);
    if (1 < sVar1) {
      f_0bf730(CH, 0x270000e4);
      uVar2 = f_041030(1, uVar2);
      f_0dd750(uVar2, 0x146b);
    }
    d_1c0d34 = 1;
  }
  if (EQI(d_1c0d34, 1)) {
    p1_00 = f_0606a0(0x270001, 6);
    f_0bfa20(CH, p1_00, 0, 0x270000e5, 0);
    sVar1 = f_0db9a0(d_1c0004);
    if (1 < sVar1) {
      uVar2 = f_039660(d_1c0004, 0xb);
      sVar1 = f_044900(uVar2, 0xb, -6);
      if (0 < sVar1) {
        o.p[1] = uVar2;
        f_0bf730(CH, 0x270000e6);
        uVar2 = f_041030(1, uVar2);
        f_0dd750(uVar2, 0x146b);
      }
    }
    if (p1_00 != 0) delete (char *)((int)(((RivaRasterImage*)(p1_00))->f_0fad20( 0)));
  }
  if (EQI(d_1c0d34, 1)) {
    sVar1 = VC3(p1, 0x27, 0);
    if (sVar1 == 0) {
      d_1c0d34 = 2;
    }
  }
}
//@ f_12db60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert den sprechenden Durchgang bzw. Wächter und die anschließende Beutevergabe bei
 *   Ereignis 0x1f6 (Status d_1c0d30). Fragt im Status 0 oder 1 über f_12df80 das viersilbige Losungswort ab; bei
 *   richtiger Eingabe ertönt Sprachausgabe 0x270011, Objekt 0x1f4c wird geöffnet und auf der Automap markiert
 *   (d_1c0d30 = 2), und im Status 2 wird die Beute 0x37 (55) über ein spoil-Objekt (f_112df0/f_112ec0)
 *   übergeben.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: iVar2 (Textkennung der Eingabeaufforderung 0x270000e7 beim ersten Mal bzw. 0x270000e9
 *   bei Wiederholung; danach Zeiger auf das Beuteobjekt).
 === Ende Beschreibung === */
void f_12db60(int p1)
{
  int t, iVar2;
  iVar2 = 0;
  if (EQI(d_1c0d30, 0)) {
    iVar2 = 0x270000e7;
    d_1c0d30 = 1;
  }
  else if (EQ(d_1c0d30, 1)) {
    iVar2 = 0x270000e9;
  }
  if (iVar2 != 0) {
    if ((iVar2 = f_12df80(p1, iVar2)) == 1) {
      f_147323((int)&d_1c2edc, 0x270011, 0x7fff, 0x8000, (t = d_1a9820), 0, iVar2);
      f_0bf730(CH, 0x270000e8);
      f_060740(0x1f4c, 1);
      f_0607e0(0x1f4c, 1);
      d_1c0d30 = 2;
    }
  }
  if (EQI(d_1c0d30, 2)) {
    t = (int)new (mark(d_1a8ca0, 0x4e3)) T20;
    iVar2 = t ? f_112df0(t, 0x37, 0, 0) : t;
    f_112ec0(iVar2);
    if (iVar2 != 0) delete (char *)f_112e70(iVar2, 0);
  }
}
//@ f_12dc70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Tür-Objekt 0x1f4a über die allgemeine Tür-Routine f_05fa00 mit Tür-Index 0x48
 *   (72).
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12dc70(void)
{
  f_05fa00(0x48, 0x1f4a);
}
//@ f_12dc90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler an der Treppe (Ereignis 0x1f8) per Ja/Nein-Dialog 0x270000ea, ob die
 *   Gruppe hinabsteigen möchte, und versetzt die aktive Gruppe bei Bestätigung über f_0dd7f0 auf Ebene 0x15 (21)
 *   an Position 0x1392.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: iVar1 (Antwort des Ja/Nein-Dialogs, 1 = Ja).
 === Ende Beschreibung === */
void f_12dc90(void)
{
  int iVar1;
  iVar1 = f_0bf6f0(CH, 0x270000ea);
  if (iVar1 == 1) {
    f_0dd7f0(d_1c0004, 0x15, 0x1392);
  }
}
//@ f_12dce0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gemeinsame Routine für die vier versiegelten Wandnischen (0x1f4b, 0x1f4d, 0x1f4e, 0x1f4f),
 *   in denen die vier Silben des Losungswortes stehen. Spielt den Nischenklang p5 ab und bietet dem Spieler drei
 *   Möglichkeiten (0x270000b8): Aufbrechen mit einem Werkzeug aus Tabelle d_1a8cbe (Hacke 93, Hammer 27,
 *   Brecheisen 26, Kriegshammer 101, dauert 15 Minuten und bringt 2 AP), Aufbrechen per Zauber (Zauberindex 5,
 *   kostet 8 AE über f_040780 und bringt 2 AP) oder Abbrechen.
 * - Eingaben: p1 (Dungeon-Steuerobjekt), p2 (Zeiger auf das 1-Byte-Erledigt-Flag der Nische), p3 (Textkennung
 *   der in der Nische sichtbaren Silbe), p4 (3D-Objektnummer der Nische), p5 (Klangkennung).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: tab (Liste der 4 erlaubten Schlagwerkzeuge), r (Held mit Werkzeug bzw. ausgewählter
 *   Zauberer), w (gefundene Werkzeug-ID).
 === Ende Beschreibung === */
int f_038e10(int, int);
void f_12dce0(int p1, FL *p2, int p3, unsigned short p4, int p5)
{
  int f_147323u(int,int,int,int,int,int,int);
#pragma aux f_147323u "f_147323" modify [esp];
  int r; SO o(d_1c349c, d_1c3870, d_1c3498);
  if (EQI(*p2, 0)) {
    SLOT(o, 0x10)[1] = p3;
    int snd = d_1a9820;
    f_147323u((int)&d_1c2edc, p5, 0x7fff, 0x8000, snd, 0, 1);
    switch ((short)f_0bf820(CH, 0x270000b8, 3, 0x270000b9, 0x270000ba, 0x270000bb)) {
    case -1:
      break;
    case 1:
    {
      S8 tab = d_1a8cbe;
      r = 0;
      short k = 0;
      short w;
      for (; (unsigned)k < 4 && r == 0; k++) {
        w = tab.s[k];
        r = f_0397d0(d_1c0004, w);
      }
      if (r == 0) {
        f_0bf730(CH, 0x270000bc);
        return;
      }
      SLOT(o, 4)[1] = r;
      int *names = *(int **)&d_1c2c40; SLOT(o, 0xc)[1] = names[w];
      ((short *)SLOT(o, 0x20))[1] = 1;
      f_0bf730(CH, 0x270000bd);
      int snd1 = d_1a9820;
      f_147323u((int)&d_1c2edc, 0x270011, 0x7fff, 0x8000, snd1, 0, 1);
      f_060740((unsigned short)p4, 1);
      f_0607e0((unsigned short)p4, 1);
      f_125ed0((int)&d_1c2c44, 0xf);
      f_0dcbb0(d_1c0004, 2);
      (*(volatile FL *)p2) = 1; // volatile verhindert das Zusammenlegen des Stores mit dem zweiten Zweig
      return;
    }
    case 2:
    {
      r = f_038e10(d_1c0004, 0x20000155);
      if (r) {
        *(volatile short *)&d_1c0428 = 6; // volatile erzwingt die Store-Reihenfolge fuer d_1c0428 vor d_1c0420 = 1
        d_1c0420 = 1;
        f_03d4b0(r, 1, 0);
        if (*(short *)&d_1c040c == 5) {
          SLOT(o, 4)[1] = r;
          if (d_1c0900 == 1) {
            *p2 = 1;
            int snd2 = d_1a9820;
            f_147323u((int)&d_1c2edc, 0x270012, 0x7fff, 0x8000, snd2, 0, d_1c0900);
            f_0bf730(CH, 0x270000be);
            f_060740((unsigned short)p4, 1);
            f_0dcbb0(d_1c0004, 2);
            f_040780(r, 8);
            return;
          } else {
            f_0bf730(CH, 0x270000bf);
            return;
          }
        }
      }
      break;
    }
    case 3:
      break;
    }
  }
}
//@ f_12df80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liest die vier Silbentexte (0x270000e2, 0x270000e0, 0x270000b7, 0x270000e1), bildet daraus
 *   die beiden gültigen Zusammensetzungen (%s_%s_%s_%s in Original- und vertauschter Paarfolge), öffnet das
 *   Texteingabefeld (f_0bfea0), ersetzt die drei Trennzeichen in der Spielereingabe durch Unterstriche '_' und
 *   prüft per Groß-/Kleinschreibungs-unabhängigem Stringvergleich (f_144bf0), ob das eingegebene Losungswort
 *   stimmt.
 * - Eingaben: p1 (ungenutzt/Kontext), p2 (Textkennung der Eingabeaufforderung).
 * - Rückgabe: 1 bei richtigem Losungswort, 0 bei falscher Eingabe.
 * - Wichtige Variablen: a, b, c, d (Zeichenlängen der vier Silben), count (Gesamtlänge der Eingabe), d_1c2204
 *   und d_1c2268 (die beiden gültigen Ziel-Zeichenketten), d_1c22cc und d_1c2330 (Kopien der Spielereingabe
 *   d_1c299c mit normierten Trennzeichen).
 === Ende Beschreibung === */
#pragma aux f_0bfea0 modify [esp]
struct A7Text { static char &a(short index) { return d_1c22cc[index]; } static char &b(short index) { return d_1c2330[index]; } };
int f_12df80(int p1, int p2)
{
  union A7LengthView { unsigned raw; unsigned short low; };
  unsigned short a;
  unsigned short b;
  unsigned c_raw;
  unsigned short &c = *(unsigned short *)&c_raw; // 16-Bit-Referenzansicht auf die 32-Bit-Rueckgabe von strlen
  unsigned short d;
  short count;
  short ab;
  p2 = (p2 & 0) ? 0 : p2; // haelt p2 in der Registervergabe ueber die strlen/sprintf-Ketten
  f_0e93f0((int)&d_1c38b0, (int)d_1c21b4, 0x270000e2);
  f_1454d0((int)d_1c21b4);
  d_1a8cd0[0] = (d_1a8cd0[0] & 0) ? 0 : d_1a8cd0[0]; // globale Dummy-Ausdruecke steuern das interne Symbol-/Registergewicht in f_12df80
  d_1a8cd0[1] = (d_1a8cd0[1] & 0) ? 0 : d_1a8cd0[1]; // s.o.
  d_1a8cd0[2] = (d_1a8cd0[2] & 0) ? 0 : d_1a8cd0[2]; // s.o.
  d_1a8cd0[3] = (d_1a8cd0[3] & 0) ? 0 : d_1a8cd0[3]; // s.o.
  d_1a8cd0[0] = (d_1a8cd0[0] & 0) ? 0 : d_1a8cd0[0]; // s.o.
  d_1a8cd0[1] = (d_1a8cd0[1] & 0) ? 0 : d_1a8cd0[1]; // s.o.
  d_1a8cd0[2] = (d_1a8cd0[2] & 0) ? 0 : d_1a8cd0[2]; // s.o.
  d_1a8cd0[0] = (d_1a8cd0[0] & 0) ? 0 : d_1a8cd0[0]; // s.o.
  f_0e93f0((int)&d_1c38b0, (int)d_1c21c8, 0x270000e0);
  f_1454d0((int)d_1c21c8);
  f_0e93f0((int)&d_1c38b0, (int)d_1c21dc, 0x270000b7);
  f_1454d0((int)d_1c21dc);
  f_0e93f0((int)&d_1c38b0, (int)d_1c21f0, 0x270000e1);
  f_1454d0((int)d_1c21f0);
  f_14572e(d_1c2204, d_1b8510, d_1c21b4, d_1c21c8, d_1c21dc, d_1c21f0);
  f_14572e(d_1c2268, d_1b851c, d_1c21dc, d_1c21f0, d_1c21b4, d_1c21c8);
  a = strlen(d_1c21b4);
  b = strlen(d_1c21c8);
  c_raw = strlen(d_1c21dc);
  d = strlen(d_1c21f0);
  count = 1 + a + b + 1 + c + 1 + d;
  int sound = d_1a9820;
  f_147323((int)&d_1c2edc, 0x270013, 0x7fff, 0x8000, sound, 0, 1);
  f_0bfea0(CH, count, p2);
  strcpy(d_1c22cc, d_1c299c);
  strcpy(d_1c2330, d_1c299c);
  ab=a+b+1; count=c+ab+1; short cd=c+d+1, acd=a+cd+1;
  if (cd&0) cd=0; // haelt cd als eigenen 16-Bit-Wert fuer die Indexberechnung
  A7Text::a(a) = A7Text::a(ab) = A7Text::a(count) = '_';
  A7Text::b(c) = A7Text::b(cd) = A7Text::b(acd) = '_';
  if (f_144bf0(d_1c22cc, d_1c2204) != 0 && f_144bf0(d_1c2330, d_1c2268) != 0) return 0;
  return 1;
}
//@ f_12e1d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lässt den Spieler einen Helden (f_038d70) und anschließend einen Gegenstand aus dessen
 *   Inventar (f_032820) auswählen und gibt die Gegenstands-ID des gewählten Platzes zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Gegenstands-ID (short) des ausgewählten Inventargegenstands oder -1 bei Abbruch.
 * - Wichtige Variablen: p1 (gewählter Held), sVar1 (Inventarslot), uVar2 (Gegenstands-ID).
 === Ende Beschreibung === */
short f_12e1d0(void)
{
  short sVar1 = 0;
  short uVar2;
  int p1;
  uVar2 = -1;
  p1 = f_038d70(d_1c0004, 0x270000d3);
  if (p1 != 0) {
    SO o(d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = p1;
    sVar1 = f_032820(p1, 0x270000d4, 1);
    if (sVar1 != -1) {
      uVar2 = f_042a60(p1, sVar1);
    }
  }
  return uVar2;
}
//@ f_12e250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht eine Gegenstands-ID in der Tabelle der vier farbigen Diamanten d_1a8cc6 (401 rot, 402
 *   grün, 403 blau, 404 gelb) und liefert die zugehörige Farb-Textkennung aus d_1a8cd0 (0x270000cf..0x270000d2).
 * - Eingaben: p1 (Gegenstands-ID).
 * - Rückgabe: Textkennung der Diamantenfarbe oder 0, wenn es kein farbiger Diamant aus der Liste ist.
 * - Wichtige Variablen: sVar1 (Tabellenindex 0..3 oder -1).
 === Ende Beschreibung === */
int f_12e250(int p1)
{
  short sVar1;
  int uVar2;
  uVar2 = 0;
  sVar1 = f_149360((short)p1, (int)d_1a8cc6);
  if (sVar1 != -1) {
    uVar2 = d_1a8cd0[sVar1];
  }
  return uVar2;
}
//@ f_12e280
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft über f_149360, ob eine Gegenstands-ID in der Liste der vier farbigen Diamanten
 *   (d_1a8cc6) enthalten ist.
 * - Eingaben: p1 (Gegenstands-ID).
 * - Rückgabe: 1, wenn der Gegenstand einer der vier farbigen Diamanten ist, sonst 0.
 * - Wichtige Variablen: r_ (Boolesches Prüfergebnis).
 === Ende Beschreibung === */
int f_12e280(int p1)
{
  int r_ = 0;
  if (f_149360((short)p1, (int)d_1a8cc6) != -1) r_ = 1;
  return r_;
}
//@ f_12e2a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob die übergebene Diamanten-ID p2 zu den beiden für eine bestimmte Fassung p1
 *   geforderten Diamanten (p1 + 4) gehört.
 * - Eingaben: p1 (Zeiger auf den 14-Byte-Tabelleneintrag der Fassung in d_1a8ce0), p2 (Gegenstands-ID des
 *   Diamanten).
 * - Rückgabe: 1, wenn der Diamant für diese Fassung richtig ist, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_12e2a0(int p1, short p2)
{
  return NE1(f_149360((short)p2, p1 + 4));
}
//@ f_12e2c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Füllt eine 14-Byte-Hilfsstruktur (Rec) für einen eingesetzten oder ausgewählten Gegenstand:
 *   speichert die Gegenstands-ID, ob es ein farbiger Diamant ist (a), ob er zur aktuellen Fassung passt (b),
 *   sowie die zugehörige Farb-Textkennung (v).
 * - Eingaben: p1 (Zeiger auf die Zielstruktur Rec), p2 (Gegenstands-ID oder -1), p3 (Zeiger auf den
 *   Fassungseintrag in d_1a8ce0).
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: a (Diamant-Flag bzw. Farbtext-ID), k (Index in d_1a8cc6).
 === Ende Beschreibung === */
void f_12e2c0(Rec *p1, short p2, int p3)
{
  if (p2 == -1) {
    p1->id = -1;
    p1->a = 0;
    p1->b = 0;
    p1->v = 0;
    return;
  }
  p1->id = p2;
  int a = 0;
  if (f_149360(p2, (int)d_1a8cc6) != -1) a = 1;
  p1->a = a;
  p1->b = NE1(f_149360(p2, p3 + 4));
  int k = f_149360(p2, (int)d_1a8cc6);
  a = 0;
  if (k != -1) {
    a = d_1a8cd0[k];
  }
  p1->v = a;
}
//@ f_12e350
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den kompletten Dialog zum Einsetzen und Kombinieren von zwei farbigen Diamanten in
 *   einer der drei Fassungen (p2 = 0: rot+gelb, p2 = 1: blau+grün, p2 = 2: rot+blau) durch. Verbraucht
 *   eingesetzte Diamanten aus dem Gruppeninventar (f_0dd1d0), stößt zwei falsch kombinierte Diamanten wieder aus
 *   (bzw. behält den einen passenden im Sockel) und meldet Erfolg (1), sobald beide zur Fassung gehörenden
 *   verschiedenen Diamanten eingesetzt wurden (Status -1).
 * - Eingaben: p1 (Dungeon-Steuerobjekt), p2 (Index der Fassung 0, 1 oder 2 in Tabelle d_1a8ce0).
 * - Rückgabe: 1, wenn die Fassung durch die richtige Zweierkombination aktiviert wurde, sonst 0.
 * - Wichtige Variablen: ent (Zeiger auf den Fassungseintrag in d_1a8ce0), cur (aktuell in der Fassung liegender
 *   erster Diamant: 0 = leer, -1 = fertig aktiviert, sonst Gegenstands-ID), fr.A (neu ausgewählter Gegenstand),
 *   fr.B (bereits im Sockel liegender Diamant), fr.ret (Erfolgsflag).
 === Ende Beschreibung === */
unsigned f_12e350(int p1, int p2)
{
  int f_1254a0(void *, int);
  struct OB {
    int a;
    int *p;
    int *p8;
    int *pc;
    int *p10;
    char g[12];
    int *p20;
    char rest[24];
  };
  struct Record494 {
    short id;int a,b,v;
    void assign(int entry,short value) {
      entry = (entry & 0) ? 0 : entry; // haelt entry im eigenen Register-Web beim Inlining
      if (value == -1) {
        id = -1;
        a = 0;
        b = 0;
        v = 0;
      } else {
        id = value;
        int flag = 0;
        if (f_149360(value, (int)d_1a8cc6) != -1) flag = 1;
        a = flag;
        b = NE1(f_149360(value, entry + 4));
        int vv = 0;
        int k = f_149360(value, (int)d_1a8cc6);
        k = (k & 0) ? 0 : k; // haelt den Rueckgabewert k vor dem Tabellenzugriff im Register
        if (k != -1) vv = d_1a8cd0[k];
        v = vv;
      }
    }
    void assign4(int entry,short value) {
      if (value == -1) {
        id = -1;
        a = 0;
        b = 0;
        v = 0;
      } else {
        id = value;
        int flag = 0;
        if (f_149360(value, (int)d_1a8cc6) != -1) flag = 1;
        a = flag;
        b = NE1(f_149360(value, entry + 4));
        int vv = 0;
        int k = f_149360(value, (int)d_1a8cc6);
        k = (k & 0) ? 0 : k; // haelt den Rueckgabewert k vor dem Tabellenzugriff im Register
        if (k != -1) vv = d_1a8cd0[k];
        v = vv;
      }
    }
    void assignSaved(int entry,short value,int &saved) {
      saved=entry;
      assign(saved,value);
    }
  };
  struct Frame {
    OB o2;
    OB o;
    Record494 A;
    short padA;
    Record494 B;
    short padB;
    int ret;
    int savedentry;
    int done;
  } fr;
  short sel;
  int ent;
  short t;
  short cur;
  fr.ret = 0;
  f_125400((int)&fr.o, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
  { int q8 = d_1c2c44; d_1c2c44 = q8; } // codeloser Global-Roundtrip fuer die Registerreihenfolge
  { int q9 = d_1c0d10; d_1c0d10 = q9; } // codeloser Global-Roundtrip fuer die Registerreihenfolge
  ent = (int)(d_1a8ce0 + (short)p2 * 14);
  t = **(short **)ent;
  cur = t;
  if (t != (short)-1) {
    fr.done = 0;
    if (t != (short)0) {
      fr.B.assign(ent,t);
      fr.o.p10[1] = fr.B.v;
      fr.o.p[1] = f_039660(d_1c0004, 0x30);
      f_0bf730(CH, 0x270000ce);
    } else {
      fr.o.p[1] = f_039660(d_1c0004, 0x30);
      f_0bf730(CH, *(int *)(ent + 10));
    }
    while (fr.done == 0) {
      { int q7 = d_1c0004; d_1c0004 = q7; } // codeloser Global-Roundtrip am Schleifenkopf
      int p;
      sel = -1;
      p = f_038d70(d_1c0004, 0x270000d3);
      if (p != 0) {
        short k;
        f_125400((int)&fr.o2, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
        fr.o2.p[1] = p;
        k = f_032820(p, 0x270000d4, 1);
        if (k != -1) sel = f_042a60(p, k);
        f_1254a0(&fr.o2, 0);
      }
      fr.A.assign(ent,(short)sel);
      {
        int aid = fr.A.id;
        if (aid == -1) {
          fr.done = 1;
        } else if (fr.A.a == 0) {
          int off = aid * 4;
          int base = *(int *)&d_1c2c40;
          fr.o.pc[1] = *(int *)(off + base);
          *(short *)((char *)fr.o.p20 + 2) = 1;
          f_0bf730(CH, 0x270000d5);
        } else if (cur == (short)0) {
          f_0dd1d0(d_1c0004, aid);
          fr.o.p[1] = f_038c40(d_1c0004);
          fr.o.p[2] = f_039660(d_1c0004, 5);
          f_0bf730(CH, 0x270000d6);
          cur = fr.A.id;
          fr.savedentry = ent;
          {
            short value = cur;
            if (value == -1) {
              fr.B.id = -1;
              fr.B.a = 0;
              fr.B.b = 0;
              fr.B.v = 0;
            } else {
              fr.B.id = value;
              int flag = 0;
              if (f_149360(value, (int)d_1a8cc6) != -1) flag = 1;
              fr.B.a = flag;
              int ep = fr.savedentry;
              ep += 4;
              fr.B.b = NE1(f_149360(value, ep));
              int vv = 0;
              int k = f_149360(value, (int)d_1a8cc6);
              k = (k & 0) ? 0 : k; // haelt den Rueckgabewert k vor dem Tabellenzugriff im Register
              if (k != -1) vv = d_1a8cd0[k];
              fr.B.v = vv;
            }
          }
        } else if (fr.A.b == 0 && fr.B.b == 0) {
          fr.o.p10[1] = fr.B.v;
          fr.o.p[1] = f_038c40(d_1c0004);
          f_0bf730(CH, 0x270000d8);
          fr.o.p[1] = f_039660(d_1c0004, 10);
          f_0bf730(CH, 0x270000d9);
          fr.B.id = -1;
          fr.B.a = 0;
          fr.B.b = 0;
          fr.B.v = 0;
          cur = 0;
        } else {
          if (fr.A.b == 1 && fr.B.b == 1) {
            if (fr.A.id == fr.B.id) {
              fr.o.p[1] = f_038c40(d_1c0004);
              f_0bf730(CH, 0x270000da);
            } else {
              fr.o.p[1] = f_038c40(d_1c0004);
              cur = -1;
              fr.ret = 1;
              f_0bf730(CH, 0x270000db);
              fr.done = 1;
              f_0dd1d0(d_1c0004, fr.A.id);
            }
          } else {
            Record494 *pb;
            Record494 *pa;
            if (fr.A.b == 1) {
              pb = &fr.A;
              pa = &fr.B;
            } else {
              pb = &fr.B;
              pa = &fr.A;
            }
            fr.o.p10[1] = pa->v;
            fr.o.p10[2] = pb->v;
            fr.o.p[1] = f_038c40(d_1c0004);
            f_0bf730(CH, 0x270000d7);
            f_0dd1d0(d_1c0004, fr.A.id);
            cur = pb->id;
            fr.B.assign4(ent,cur);
          }
        }
      }
    }
  }
  **(short **)ent = cur;
  f_1254a0(&fr.o, 0);
  return fr.ret;
}


#undef CH
#undef EQ
#undef EQI
#undef NE1
#undef SLOT
#undef UA
#undef UB
#undef VC3
#undef d_1a8ca0
#undef d_1a8cbe
#undef d_1a8cc6
#undef d_1a8cd0
#undef d_1a8ce0
#undef d_1a8cea
#undef d_1a9820
#undef d_1c0004
#undef d_1c040c
#undef d_1c0420
#undef d_1c0428
#undef d_1c0900
#undef d_1c0cf8
#undef d_1c0d10
#undef d_1c0d14
#undef d_1c0d18
#undef d_1c0d1c
#undef d_1c0d20
#undef d_1c0d24
#undef d_1c0d28
#undef d_1c0d2c
#undef d_1c0d30
#undef d_1c0d34
#undef d_1c0d3c
#undef d_1c0d40
#undef d_1c21b4
#undef d_1c21c8
#undef d_1c21dc
#undef d_1c21f0
#undef d_1c2204
#undef d_1c2268
#undef d_1c22cc
#undef d_1c2330
#undef d_1c299c
#undef d_1c2c40
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef d_1c38b0
#undef f_032820
#undef f_033c50
#undef f_038c40
#undef f_038d70
#undef f_038e10
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0397d0
#undef f_03d4b0
#undef f_040780
#undef f_0423c0
#undef f_042a60
#undef f_042ac0
#undef f_042bb0
#undef f_042d00
#undef f_044850
#undef f_044900
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_047120
#undef f_05f190
#undef f_05f220
#undef f_05f4f0
#undef f_05f580
#undef f_05f800
#undef f_05fa00
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_060770
#undef f_0607e0
#undef f_091f70



#undef f_0bde40
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf820
#undef f_0bfa20
#undef f_0db9a0
#undef f_0dcbb0
#undef f_0dd1d0
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de880
#undef f_0e93f0

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_12c050
#undef f_1454d0
#undef f_145850
#undef f_147323
#undef f_149360
#undef f_149640

// ===== Teil gz_12e960 (p3, 12e960-12edf0) =====
#define d_1c0cf8 d_1c0cf8_k3
#define d_1c212a d_1c212a_k3
#define f_05ff60 f_05ff60_k3
#define f_060030 f_060030_k3
#define f_060740 f_060740_k3
#define f_060760 f_060760_k3
#define f_0607e0 f_0607e0_k3
#define f_145234 f_145234_k3
#define f_145254 f_145254_k3
// P3 5/7 gleich (suche.py 25.10.2026, Basis gz_12e960_P1.CPP)
// OPT-aus-Teil (gilt nicht fuer das Modul) -4r -oneatxu -zp1 -s
// P1 3/7 gleich (von Hand: f_12e960 f_12ea30 f_12edd0)
// gz_12e960.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12E960-0x12EDF0
#pragma inline_depth(0)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05ff60(int p1, int p2);                       // nicht in clobber.tsv
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060100(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
short f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_11f920(int p1);                                   // reg eax stapel 0
extern int d_1bd91c;
extern signed char d_1c0cf8;
extern char d_1bbb80[];
extern char d_1bbbd8[];
int f_145234(int p1, int p2);
void f_145254(void);
extern short d_1c212a;
extern int *d_1c212c;
extern unsigned char d_1c0d4c;
extern short d_1c0d4d;
extern unsigned char d_1c0d50;
extern short d_1c0d51;
extern unsigned char d_1c0d54;
extern short d_1c0d55;
extern unsigned char d_1c0d58;
extern short d_1c0d59;
extern unsigned char d_1c0d5c;
extern short d_1c0d5d;
extern unsigned char d_1c0d60;
extern short d_1c0d61;
extern unsigned char d_1c0d64;
extern short d_1c0d65;
extern unsigned char d_1c0d68;
extern short d_1c0d69;
extern unsigned char d_1c0d6c;
extern short d_1c0d6d;
extern unsigned char d_1c0d70;
extern short d_1c0d71;
extern unsigned char d_1c0d74;
extern short d_1c0d75;
extern unsigned char d_1c0d78;
extern short d_1c0d79;
extern unsigned char d_1c0d7c;
extern short d_1c0d7d;
extern unsigned char d_1c0d80;
extern short d_1c0d81;
extern unsigned char d_1c0d84;
extern short d_1c0d85;
extern unsigned char d_1c0d88;
extern short d_1c0d89;
extern unsigned char d_1c0d8c;
extern short d_1c0d8d;
extern unsigned char d_1c0d90;
extern short d_1c0d91;
extern unsigned char d_1c0d94;
extern short d_1c0d95;

// (anderes Modul)  f_060230
// (Funktion f_060230 gehoert zu einem anderen Modul, hier weggelassen)

//@ f_12e960
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt den Abschluss eines Kampfes (p2) auf der zweiten Turmebene (tower2), setzt das
 *   globale Flag d_1bd91c = 1, ruft die Basis-Kampfabschlussroutine f_060100(p1, p2, p3) auf und entfernt bei
 *   erfolgreichem Abschluss ((short)r == 0) die besiegte Gegnergruppe über f_0697c0(p1 + 2, p2, 0) von der
 *   Karte.
 * - Eingaben: p1 (this-Zeiger des Dungeon-Steuerobjekts), p2 (Kampf-ID), p3 (Kampfergebnis).
 * - Rückgabe: Gibt den Rückgabewert r von f_060100 zurück.
 * - Wichtige Variablen: d_1bd91c (Kampfstatus-Flag), r (Ergebnis des Basis-Kampfabschlusses).
 === Ende Beschreibung === */
int f_12e960(int p1, short p2, short p3)
{
    d_1bd91c = 1;
    int r = f_060100(p1, p2, p3);
    if ((short)r == 0)
        f_0697c0(p1 + 2, p2, 0);
    return r;
}

//@ f_12e9a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leitet als dünner Wrapper für das tower2-Dungeon-Objekt direkt auf die
 *   Basis-Initialisierungsroutine f_060230 weiter.
 * - Eingaben: Impliziter this-Zeiger des Dungeon-Steuerobjekts.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_12e9a0(void)
{
    void f_060230_direct(void);
#pragma aux f_060230_direct "f_060230";
    f_060230_direct();
}

//@ f_12e9b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Synchronisiert den 3D-Zustand des Hebel-/Schalterobjekts 0x1f50 auf der zweiten Turmebene
 *   anhand des gespeicherten Zustandsflags d_1c0cf8, indem über f_060760(0x1f50) der aktuelle Objektzustand s
 *   abgefragt und bei Abweichung über f_060740(0x1f50, 1) sowie f_0607e0(0x1f50, b) umgeschaltet wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: s (aktueller Zustand des 3D-Objekts 0x1f50), d_1c0cf8 (persistentes Schalter-Flag), b
 *   (invertierter Zielwert d_1c0cf8 != 1).
 === Ende Beschreibung === */
#define EQI(x,v) (((x)==(v))?1:0)
void f_12e9b0(void)
{
    int f_060760_int(int);
#pragma aux f_060760_int "f_060760";
    int s = 0;
    s = f_060760_int(0x1f50);
    short b = EQI(EQI(d_1c0cf8, 1), 0);
    if ((EQI(d_1c0cf8, 1) && (short)2 == (short)s) || (EQI(d_1c0cf8, 0) && (short)s == (short)1))
    {
        f_060740(0x1f50, 1);
        f_0607e0(0x1f50, (signed char)b);
    }
}

// f_12ea30 = $dt:X12c5b0 (COMDAT aus virtual ~X12c5b0(){ }), steht hinter dem normalen Code
// (anderes Modul)  f_12ea70
#define RIVA_REG_FIRST(OBJ, IDFIELD, ID) \
    do { (OBJ) = 0; (IDFIELD) = (ID); \
         ((int *&)d_1c212c)[(short &)d_1c212a] = (int)&(OBJ); } while (0)
#define RIVA_REG_NEXT(OBJ, IDFIELD, ID) \
    do { (OBJ) = 0; (IDFIELD) = (ID); \
         ((int *&)d_1c212c)[++d_1c212a] = (int)&(OBJ); } while (0)
#pragma inline_depth(3)
struct RR700V3_12ea708;
struct OR700V3_12ea708 { signed char flag; short number; char pad; OR700V3_12ea708 *init(RR700V3_12ea708 &r,short id,signed char f); };
struct RR700V3_12ea708 { short count; OR700V3_12ea708 **list; void append(OR700V3_12ea708 *o) {list[count]=o;count++;} };
inline OR700V3_12ea708 *OR700V3_12ea708::init(RR700V3_12ea708 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_12ea708 regR700V3_12ea708;
#pragma aux regR700V3_12ea708 "d_1c212a"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d4c;
#pragma aux obR700V3_12ea70_1c0d4c "d_1c0d4c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d50;
#pragma aux obR700V3_12ea70_1c0d50 "d_1c0d50"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d54;
#pragma aux obR700V3_12ea70_1c0d54 "d_1c0d54"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d58;
#pragma aux obR700V3_12ea70_1c0d58 "d_1c0d58"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d5c;
#pragma aux obR700V3_12ea70_1c0d5c "d_1c0d5c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d60;
#pragma aux obR700V3_12ea70_1c0d60 "d_1c0d60"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d64;
#pragma aux obR700V3_12ea70_1c0d64 "d_1c0d64"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d68;
#pragma aux obR700V3_12ea70_1c0d68 "d_1c0d68"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d6c;
#pragma aux obR700V3_12ea70_1c0d6c "d_1c0d6c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d70;
#pragma aux obR700V3_12ea70_1c0d70 "d_1c0d70"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d74;
#pragma aux obR700V3_12ea70_1c0d74 "d_1c0d74"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d78;
#pragma aux obR700V3_12ea70_1c0d78 "d_1c0d78"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d7c;
#pragma aux obR700V3_12ea70_1c0d7c "d_1c0d7c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d80;
#pragma aux obR700V3_12ea70_1c0d80 "d_1c0d80"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d84;
#pragma aux obR700V3_12ea70_1c0d84 "d_1c0d84"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d88;
#pragma aux obR700V3_12ea70_1c0d88 "d_1c0d88"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d8c;
#pragma aux obR700V3_12ea70_1c0d8c "d_1c0d8c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d90;
#pragma aux obR700V3_12ea70_1c0d90 "d_1c0d90"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d94;
#pragma aux obR700V3_12ea70_1c0d94 "d_1c0d94"
// (Funktion f_12ea70 gehoert zu einem anderen Modul, hier weggelassen)

#pragma inline_depth(0)

#undef RIVA_REG_FIRST
#undef RIVA_REG_NEXT

// (anderes Modul)  f_12edd0
// (Funktion f_12edd0 gehoert zu einem anderen Modul, hier weggelassen)

#pragma inline_depth(3)

#undef EQI
#undef RIVA_REG_FIRST
#undef RIVA_REG_NEXT
#undef d_1c0cf8
#undef d_1c212a
#undef f_05ff60
#undef f_060030
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_145234
#undef f_145254
