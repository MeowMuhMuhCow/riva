/* === Beschreibung (Katalog) ===
 * Einheit final2 (08df20 - 091bd0)
 *
 * Überblick
 * Die große Einheit final2 implementiert den zweiten und entscheidenden Abschnitt des Final-Dungeons (die
 * Königin der Insekten / den Bienenstock bzw. das Endlabyrinth): Sie registriert 22 persistente Zustandsflags
 * (f_08df20), initialisiert das Dungeon-Steuerobjekt (f_08e300), verteilt sämtliche Raumereignisse über f_08e320
 * und enthält die zugehörigen Einzelhandler für Fallen, Schleim-/Säuregruben, das neunteilige Rätsel (f_08fa70
 * mit f_090190..f_090900), die Zerstörung nicht-metallischer oder ungeschützter Ausrüstung (f_0915c0..f_091770)
 * sowie den Endkampf gegen die Königin (f_090a90..f_090c60).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// final2.cpp (Schatten ueber Riva) - GANZES Modul 0x08DF20-0x091BD0 inkl. COMDAT-Schwanz (Forscher 840, 30.10.2026)
// Zusammengesetzt aus p3: gz_08dae0 (nur f_08df20, f_08e300), final2_t1, final2_t2, final2_t3; Schwanz siehe comdat/BERICHT.md
#include <string.h>
#include <math.h>
// --- COMDAT-Schwanz 091b90-091bc0: inline-Funktionen, nur per (void)-Ausdruck in f_08df20 genannt
//     (Watcom erzeugt das COMDAT, die Lokale faellt weg -> im EXE kein Verweis; Erzeugung vor $dt:X -> EXE-Reihenfolge $dt,h,z,sub,inc)
inline char f_091bc0(char *p, int){ return (*p)++; }
inline char f_091bb0(char *p, char d){ return *p-d; }
inline int f_091ba0(){ return 0; }
inline int f_091b90(){ return 0; }

// ===== Teil gz_08dae0 (f_08df20) =====
#define d_1bc940 d_1bc940_a
#define d_1bdb24 d_1bdb24_a
#define d_1bdb30 d_1bdb30_a
#define d_1bdb34 d_1bdb34_a
#define d_1bdb38 d_1bdb38_a
#define d_1bdb3c d_1bdb3c_a
#define d_1bdb40 d_1bdb40_a
#define d_1bdb44 d_1bdb44_a
#define d_1bdb48 d_1bdb48_a
#define d_1bdb4c d_1bdb4c_a
#define d_1bdb50 d_1bdb50_a
#define d_1bdb54 d_1bdb54_a
#define d_1bdb58 d_1bdb58_a
#define d_1bdb5c d_1bdb5c_a
#define d_1bdb60 d_1bdb60_a
#define d_1bdb64 d_1bdb64_a
#define d_1bdb68 d_1bdb68_a
#define d_1bdb6c d_1bdb6c_a
#define d_1bdb70 d_1bdb70_a
#define d_1bdb74 d_1bdb74_a
#define d_1bdb7c d_1bdb7c_a
#define d_1bdb80 d_1bdb80_a
#define d_1bdb84 d_1bdb84_a
#define d_1c0004 d_1c0004_a
#define d_1c1078 d_1c1078_a
#define d_1c21a4 d_1c21a4_a
#define d_1c2c64 d_1c2c64_a
#define d_1c3498 d_1c3498_a
#define d_1c349c d_1c349c_a
#define d_1c3870 d_1c3870_a
#define f_014710 f_014710_a
#define f_038c40 f_038c40_a
#define f_039320 f_039320_a
#define f_039a80 f_039a80_a
#define f_060740 f_060740_a
#define f_060800 f_060800_a
#define f_08de20 f_08de20_a
#define f_0bf6f0 f_0bf6f0_a
#define f_0bf730 f_0bf730_a
#define f_0d4a60 f_0d4a60_a
#define f_0db9a0 f_0db9a0_a
#define f_0dcf00 f_0dcf00_a
#define f_0dd480 f_0dd480_a
#define f_125400 f_125400_a
#define f_1254a0 f_1254a0_a
#define SO SO_a
#define T14 T14_a
#define EQBF EQBF_a
// P3 8/10 gleich (suche.py 24.10.2026, Basis gz_08dae0_P1.CPP)
// gz_08dae0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08DAE0-0x08E320
#define EQI(x,v) (((x)==(v))?1:0)
#define GTI(x,v) (((x)>(v))?1:0)
struct BF8 { unsigned char b0:1; };
#define B0(x) (((struct BF8 *)&(x))->b0)
struct SO { char b[4]; int *p; char c[52]; };
int f_0bf6f0(const char *o, int b);
#pragma aux f_0bf6f0_a "f_0bf6f0"
int f_0bf730(const char *o, int b);
#pragma aux f_0bf730_a "f_0bf730"
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
#pragma aux f_125400_a "f_125400"
int f_1254a0(void *p1, int p2);
#pragma aux f_1254a0_a "f_1254a0"
int f_039320(int p1, int p2);
#pragma aux f_039320_a "f_039320"
int f_039a80(int p1, int p2);
#pragma aux f_039a80_a "f_039a80"
int f_038c40(int p1);
#pragma aux f_038c40_a "f_038c40"
int f_0390d0(int p1);
short f_042960(int p1);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_0600a0(int p1);
int f_060740(int p1, int p2);
#pragma aux f_060740_a "f_060740"
int f_060800(int p1, int p2, int p3);
#pragma aux f_060800_a "f_060800"
int f_0d4a60(int p1);
#pragma aux f_0d4a60_a "f_0d4a60"
short f_0db9a0(int p1);
#pragma aux f_0db9a0_a "f_0db9a0"
short f_0dcf00(int p1, int p2, int p3);
#pragma aux f_0dcf00_a "f_0dcf00"
unsigned short f_0dd480(int p1);
#pragma aux f_0dd480_a "f_0dd480"
int f_0de210(int p1);
int f_0de7c0(int p1);
int f_0de7d0(int p1, int p2);
int f_155934();
int f_145234(int p1, int p2);
int f_145254();
void f_014710(int p1);
#pragma aux f_014710_a "f_014710"
void f_08ccc0(void);
void f_08de20(int p1);
#pragma aux f_08de20_a "f_08de20"
extern char d_1baee0[];
extern int d_1bc940;
#pragma aux d_1bc940_a "d_1bc940"
extern signed char d_1bdb03;
extern signed char d_1bdb04;
extern signed char d_1bdb20;
extern unsigned char d_1bdb24;
#pragma aux d_1bdb24_a "d_1bdb24"
extern signed char d_1bdb84;
#pragma aux d_1bdb84_a "d_1bdb84"
extern char d_1bfdbc[];
extern int d_1c0004;
#pragma aux d_1c0004_a "d_1c0004"
extern int d_1c1078;
#pragma aux d_1c1078_a "d_1c1078"
extern short d_1c212a;
extern char **d_1c212c;
extern short d_1c21a4;
#pragma aux d_1c21a4_a "d_1c21a4"
extern char d_1c2c64[];
#pragma aux d_1c2c64_a "d_1c2c64"
extern char d_1c349c[];
#pragma aux d_1c349c_a "d_1c349c"
extern char d_1c3498[];
#pragma aux d_1c3498_a "d_1c3498"
extern char d_1c3870[];
#pragma aux d_1c3870_a "d_1c3870"
extern char d_1baf38[];
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define REG(a,b,v) a = 0; b = v; d_1c212c[d_1c212a++] = (char *)&a;
extern char d_1bdb30; extern short d_1bdb31;
#pragma aux d_1bdb30_a "d_1bdb30"
extern char d_1bdb34; extern short d_1bdb35;
#pragma aux d_1bdb34_a "d_1bdb34"
extern char d_1bdb38; extern short d_1bdb39;
#pragma aux d_1bdb38_a "d_1bdb38"
extern char d_1bdb3c; extern short d_1bdb3d;
#pragma aux d_1bdb3c_a "d_1bdb3c"
extern char d_1bdb40; extern short d_1bdb41;
#pragma aux d_1bdb40_a "d_1bdb40"
extern char d_1bdb44; extern short d_1bdb45;
#pragma aux d_1bdb44_a "d_1bdb44"
extern char d_1bdb48; extern short d_1bdb49;
#pragma aux d_1bdb48_a "d_1bdb48"
extern char d_1bdb4c; extern short d_1bdb4d;
#pragma aux d_1bdb4c_a "d_1bdb4c"
extern char d_1bdb50; extern short d_1bdb51;
#pragma aux d_1bdb50_a "d_1bdb50"
extern char d_1bdb54; extern short d_1bdb55;
#pragma aux d_1bdb54_a "d_1bdb54"
extern char d_1bdb58; extern short d_1bdb59;
#pragma aux d_1bdb58_a "d_1bdb58"
extern char d_1bdb5c; extern short d_1bdb5d;
#pragma aux d_1bdb5c_a "d_1bdb5c"
extern char d_1bdb60; extern short d_1bdb61;
#pragma aux d_1bdb60_a "d_1bdb60"
extern char d_1bdb64; extern short d_1bdb65;
#pragma aux d_1bdb64_a "d_1bdb64"
extern char d_1bdb68; extern short d_1bdb69;
#pragma aux d_1bdb68_a "d_1bdb68"
extern char d_1bdb6c; extern short d_1bdb6d;
#pragma aux d_1bdb6c_a "d_1bdb6c"
extern char d_1bdb70; extern short d_1bdb71;
#pragma aux d_1bdb70_a "d_1bdb70"
extern char d_1bdb74; extern short d_1bdb75;
#pragma aux d_1bdb74_a "d_1bdb74"
extern char d_1bdb78; extern short d_1bdb79;
extern char d_1bdb7c; extern short d_1bdb7d;
#pragma aux d_1bdb7c_a "d_1bdb7c"
extern char d_1bdb80; extern short d_1bdb81;
#pragma aux d_1bdb80_a "d_1bdb80"
extern short d_1bdb85;
struct Obj08;
struct Reg08 { short count; Obj08 **list; void append(Obj08 *o) { list[count]=o;count++; } };
struct Obj08 { signed char a; short b; Obj08 *init(Reg08 &r,short id,signed char f) { a=f;b=id;r.append(this);return this; } };

extern Reg08 reg08;
#pragma aux reg08 "d_1c212a"
extern Obj08 o08_1bdb30;
#pragma aux o08_1bdb30 "d_1bdb30"
extern Obj08 o08_1bdb34;
#pragma aux o08_1bdb34 "d_1bdb34"
extern Obj08 o08_1bdb38;
#pragma aux o08_1bdb38 "d_1bdb38"
extern Obj08 o08_1bdb3c;
#pragma aux o08_1bdb3c "d_1bdb3c"
extern Obj08 o08_1bdb40;
#pragma aux o08_1bdb40 "d_1bdb40"
extern Obj08 o08_1bdb44;
#pragma aux o08_1bdb44 "d_1bdb44"
extern Obj08 o08_1bdb48;
#pragma aux o08_1bdb48 "d_1bdb48"
extern Obj08 o08_1bdb4c;
#pragma aux o08_1bdb4c "d_1bdb4c"
extern Obj08 o08_1bdb50;
#pragma aux o08_1bdb50 "d_1bdb50"
extern Obj08 o08_1bdb54;
#pragma aux o08_1bdb54 "d_1bdb54"
extern Obj08 o08_1bdb58;
#pragma aux o08_1bdb58 "d_1bdb58"
extern Obj08 o08_1bdb5c;
#pragma aux o08_1bdb5c "d_1bdb5c"
extern Obj08 o08_1bdb60;
#pragma aux o08_1bdb60 "d_1bdb60"
extern Obj08 o08_1bdb64;
#pragma aux o08_1bdb64 "d_1bdb64"
extern Obj08 o08_1bdb68;
#pragma aux o08_1bdb68 "d_1bdb68"
extern Obj08 o08_1bdb6c;
#pragma aux o08_1bdb6c "d_1bdb6c"
extern Obj08 o08_1bdb70;
#pragma aux o08_1bdb70 "d_1bdb70"
extern Obj08 o08_1bdb74;
#pragma aux o08_1bdb74 "d_1bdb74"
extern Obj08 o08_1bdb78;
#pragma aux o08_1bdb78 "d_1bdb78"
extern Obj08 o08_1bdb7c;
#pragma aux o08_1bdb7c "d_1bdb7c"
extern Obj08 o08_1bdb80;
#pragma aux o08_1bdb80 "d_1bdb80"
extern Obj08 o08_1bdb84;
#pragma aux o08_1bdb84 "d_1bdb84"
inline signed char zero08() { signed char c=0; return c; }
inline void add08(Obj08 &o, Reg08 &r, short id) { o.a=0; o.b=id; r.list[r.count]=&o; r.count++; }
//@ f_08df20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert beim Programmstart 22 persistente Zustands- und Ereignisvariablen (d_1bdb30 bis
 *   d_1bdb84 mit den Kennungen 0xd1..0xe0, 0xfa, 0x186, 0x224..0x226, 0x25e) im globalen Spielstands-Register
 *   d_1c212a.
 * - Eingaben und Rückgabe: Die Initialisierungsfunktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Alle 22 Statusbytes werden beim Anlegen auf den Startwert 0 gesetzt.
 === Ende Beschreibung === */
void f_08df20(void) {
    o08_1bdb30.init(reg08,0xd1,0);
    o08_1bdb34.init(reg08,0xd2,0);
    o08_1bdb38.init(reg08,0xd3,0);
    o08_1bdb3c.init(reg08,0xd4,0);
    o08_1bdb40.init(reg08,0xd5,0);
    o08_1bdb44.init(reg08,0xd6,0);
    o08_1bdb48.init(reg08,0xd7,0);
    o08_1bdb4c.init(reg08,0xd8,0);
    o08_1bdb50.init(reg08,0xd9,0);
    o08_1bdb54.init(reg08,0xda,0);
    o08_1bdb58.init(reg08,0xdb,0);
    o08_1bdb5c.init(reg08,0xdc,0);
    o08_1bdb60.init(reg08,0xdd,0);
    o08_1bdb64.init(reg08,0x186,0);
    o08_1bdb68.init(reg08,0x224,0);
    o08_1bdb6c.init(reg08,0x225,0);
    o08_1bdb70.init(reg08,0x226,0);
    o08_1bdb74.init(reg08,0xfa,0);
    o08_1bdb78.init(reg08,0x25e,0);
    o08_1bdb7c.init(reg08,0xde,0);
    o08_1bdb80.init(reg08,0xdf,0);
    o08_1bdb84.init(reg08,0xe0,0);
    (void)f_091bc0; (void)f_091bb0; (void)f_091ba0; (void)f_091b90;   // erzeugt die COMDATs 091b90-091bc0 ohne Verweis im EXE
}

#undef B0
#undef EQB
#undef EQI
#undef GTI
#undef REG
#undef d_1bc940
#undef d_1bdb24
#undef d_1bdb30
#undef d_1bdb34
#undef d_1bdb38
#undef d_1bdb3c
#undef d_1bdb40
#undef d_1bdb44
#undef d_1bdb48
#undef d_1bdb4c
#undef d_1bdb50
#undef d_1bdb54
#undef d_1bdb58
#undef d_1bdb5c
#undef d_1bdb60
#undef d_1bdb64
#undef d_1bdb68
#undef d_1bdb6c
#undef d_1bdb70
#undef d_1bdb74
#undef d_1bdb7c
#undef d_1bdb80
#undef d_1bdb84
#undef d_1c0004
#undef d_1c1078
#undef d_1c21a4
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_014710
#undef f_038c40
#undef f_039320
#undef f_039a80
#undef f_060740
#undef f_060800
#undef f_08de20
#undef f_0bf6f0
#undef f_0bf730
#undef f_0d4a60
#undef f_0db9a0
#undef f_0dcf00
#undef f_0dd480
#undef f_125400
#undef f_1254a0
#undef SO
#undef T14
#undef EQBF

// --- Klasse X: Konstruktor 08e300 setzt vtable 1baf38; inline virtueller Destruktor -> COMDAT $dt:X am Modulende (091b50)
struct B05ff60 { char pad[8]; B05ff60(int k); virtual ~B05ff60(); };   // Ctor f_05ff60, Dtor f_060030
struct X08e300 : B05ff60 { X08e300(); virtual ~X08e300(){ } };
//@ f_08e300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert das Dungeon-Steuerobjekt (X08e300) für den zweiten Final-Dungeon mit der
 *   Kartenkennung 11 (f_05ff60) und trägt dessen virtuelle Methodentabelle d_1baf38 ein.
 * - Eingaben und Rückgabe: Der Konstruktor erhält den this-Zeiger der Instanz und gibt diesen zurück.
 * - Wichtige Variablen: Die Basisklasse B05ff60 initialisiert die Grundfelder des Dungeon-Handlers.
 === Ende Beschreibung === */
X08e300::X08e300() : B05ff60(11) { }

// ===== Teil final2_t1 =====
#define d_1a2880 d_1a2880_t1
#define d_1a2884 d_1a2884_t1
#define d_1a28c8 d_1a28c8_t1
#define d_1a28ce d_1a28ce_t1
#define d_1a28da d_1a28da_t1
#define d_1a9820 d_1a9820_t1
#define d_1bc940 d_1bc940_t1
#define d_1bdb24 d_1bdb24_t1
#define d_1bdb28 d_1bdb28_t1
#define d_1bdb2c d_1bdb2c_t1
#define d_1bdb30 d_1bdb30_t1
#define d_1bdb34 d_1bdb34_t1
#define d_1bdb38 d_1bdb38_t1
#define d_1bdb3c d_1bdb3c_t1
#define d_1bdb40 d_1bdb40_t1
#define d_1bdb44 d_1bdb44_t1
#define d_1bdb48 d_1bdb48_t1
#define d_1bdb4c d_1bdb4c_t1
#define d_1bdb50 d_1bdb50_t1
#define d_1bdb54 d_1bdb54_t1
#define d_1bdb58 d_1bdb58_t1
#define d_1bdb5c d_1bdb5c_t1
#define d_1bdb60 d_1bdb60_t1
#define d_1bdb64 d_1bdb64_t1
#define d_1bdb68 d_1bdb68_t1
#define d_1bdb6c d_1bdb6c_t1
#define d_1bdb70 d_1bdb70_t1
#define d_1bdb74 d_1bdb74_t1
#define d_1bdb7c d_1bdb7c_t1
#define d_1bdb80 d_1bdb80_t1
#define d_1bdb84 d_1bdb84_t1
#define d_1bfaec d_1bfaec_t1
#define d_1c0004 d_1c0004_t1
#define d_1c1078 d_1c1078_t1
#define d_1c107c d_1c107c_t1
#define d_1c21a4 d_1c21a4_t1
#define d_1c27a8 d_1c27a8_t1
#define d_1c2c00 d_1c2c00_t1

#define d_1c2c64 d_1c2c64_t1
#define d_1c2edc d_1c2edc_t1
#define d_1c3498 d_1c3498_t1
#define d_1c349c d_1c349c_t1
#define d_1c3870 d_1c3870_t1
#define f_0104b0 f_0104b0_t1
#define f_010590 f_010590_t1
#define f_014710 f_014710_t1
#define f_032820 f_032820_t1
#define f_033530 f_033530_t1
#define f_036300 f_036300_t1
#define f_038be0 f_038be0_t1
#define f_038c40 f_038c40_t1
#define f_038d70 f_038d70_t1
#define f_039320 f_039320_t1
#define f_039660 f_039660_t1
#define f_0397d0 f_0397d0_t1
#define f_0398c0 f_0398c0_t1
#define f_039a80 f_039a80_t1
#define f_039ac0 f_039ac0_t1
#define f_039b00 f_039b00_t1
#define f_042380 f_042380_t1
#define f_042a60 f_042a60_t1
#define f_043120 f_043120_t1
#define f_043d40 f_043d40_t1
#define f_043d50 f_043d50_t1
#define f_044300 f_044300_t1
#define f_044900 f_044900_t1
#define f_044c90 f_044c90_t1
#define f_0453e0 f_0453e0_t1
#define f_057220 f_057220_t1
#define f_060230 f_060230_t1
#define f_0606a0 f_0606a0_t1
#define f_060740 f_060740_t1
#define f_060760 f_060760_t1
#define f_0607e0 f_0607e0_t1
#define f_060800 f_060800_t1
#define f_0609d0 f_0609d0_t1
#define f_060a70 f_060a70_t1
#define f_069630 f_069630_t1
#define f_069730 f_069730_t1
#define f_0697c0 f_0697c0_t1
#define f_08de20 f_08de20_t1
#define f_08f6c0 f_08f6c0_t1
#define f_08fa70 f_08fa70_t1
#define f_08fd60 f_08fd60_t1
#define f_090b90 f_090b90_t1
#define f_090de0 f_090de0_t1
#define f_090fa0 f_090fa0_t1
#define f_0911e0 f_0911e0_t1
#define f_091280 f_091280_t1
#define f_091370 f_091370_t1
#define f_0914a0 f_0914a0_t1
#define f_091770 f_091770_t1
#define f_091f70 f_091f70_t1

#define f_0bde40 f_0bde40_t1
#define f_0bf6f0 f_0bf6f0_t1
#define f_0bf730 f_0bf730_t1
#define f_0bf820 f_0bf820_t1
#define f_0bf980 f_0bf980_t1
#define f_0d4a60 f_0d4a60_t1
#define f_0d4c80 f_0d4c80_t1
#define f_0d5040 f_0d5040_t1
#define f_0d54f0 f_0d54f0_t1
#define f_0db9a0 f_0db9a0_t1
#define f_0dc020 f_0dc020_t1
#define f_0dcb60 f_0dcb60_t1
#define f_0dcbb0 f_0dcbb0_t1
#define f_0dcf00 f_0dcf00_t1
#define f_0dd480 f_0dd480_t1
#define f_0dd750 f_0dd750_t1
#define f_0dd7f0 f_0dd7f0_t1
#define f_0de840 f_0de840_t1
#define f_0de880 f_0de880_t1
#define f_0f2720 f_0f2720_t1

#define f_112df0 f_112df0_t1
#define f_112e70 f_112e70_t1
#define f_112ec0 f_112ec0_t1
#define f_1131b0 f_1131b0_t1
#define f_113340 f_113340_t1
#define f_113500 f_113500_t1
#define f_125400 f_125400_t1
#define f_1254a0 f_1254a0_t1
#define f_145760 f_145760_t1
#define f_1457e0 f_1457e0_t1
#define f_149360 f_149360_t1
#define f_149a14 f_149a14_t1
#define SO SO_t1
#define T14 T14_t1
#define EQBF EQBF_t1
// P3 15/19 gleich (suche.py 24.10.2026, Basis final2_t1_P1.CPP)
// OPT-Hinweis: f_08f4e0 im Original unoptimiert (ebp-Rahmen), Rest -oneatx
// final2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08E320-0x091B50
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042380(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_043120(int p1);                                   // reg eax stapel 0
int f_043d40(int p1);                                   // reg eax stapel 0
int f_043d50(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060230();                                         // reg - stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0609d0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069630(int p1, int p2);                           // reg eax edx stapel 0
int f_069730(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_08de20(int p1);                                   // reg eax stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bf980(...);                                         // reg - stapel 0
int f_0bfa20(int,int,int,int,int);
#pragma aux f_0bfa20 parm caller [];                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcb60(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd480(int p1);                                   // reg eax stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0f2720(int p1);                       // nicht in clobber.tsv
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
short f_113500(int p1, int p2);                           // reg eax edx stapel 0
short f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
#pragma aux f_147323 modify [esp];   // Hand-ASM aendert esp -> ebp-Rahmen der Aufrufer (Blind831, erlaubt MooMoo 30.10.)
int f_149360();                       // nicht in clobber.tsv
int f_149a14(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a2880;                    // 0x1A2880
extern int d_1a28c8;                    // 0x1A28C8
extern int d_1a28cc;                    // 0x1A28CC
extern int d_1a28ce;                    // 0x1A28CE
extern int d_1a28da;                    // 0x1A28DA
extern short d_1a9820;                    // 0x1A9820
extern int d_1bc940;                    // 0x1BC940
extern char d_1bdb24;                    // 0x1BDB24
extern int d_1bdb28;                    // 0x1BDB28
extern signed char d_1bdb2c;                    // 0x1BDB2C
extern signed char d_1bdb30;                    // 0x1BDB30
extern int d_1bdb34;                    // 0x1BDB34
extern int d_1bdb38;                    // 0x1BDB38
extern int d_1bdb3c;                    // 0x1BDB3C
extern int d_1bdb40;                    // 0x1BDB40
extern signed char d_1bdb44;                    // 0x1BDB44
extern signed char d_1bdb48;                    // 0x1BDB48
extern signed char d_1bdb4c;                    // 0x1BDB4C
extern signed char d_1bdb50;                    // 0x1BDB50
extern signed char d_1bdb54;                    // 0x1BDB54
extern int d_1bdb58;                    // 0x1BDB58
extern int d_1bdb5c;                    // 0x1BDB5C
extern int d_1bdb60;                    // 0x1BDB60
extern int d_1bdb64;                    // 0x1BDB64
extern int d_1bdb68;                    // 0x1BDB68
extern int d_1bdb6c;                    // 0x1BDB6C
extern int d_1bdb70;                    // 0x1BDB70
extern signed char d_1bdb74;                    // 0x1BDB74
extern signed char d_1bdb7c;                    // 0x1BDB7C
extern signed char d_1bdb80;                    // 0x1BDB80
extern signed char d_1bdb84;                    // 0x1BDB84
extern signed char d_1bfaec;                    // 0x1BFAEC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c1078;                    // 0x1C1078
extern int d_1c107c;                    // 0x1C107C
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1c3498[];                    // 0x1C3498
extern const char d_1c349c[];                    // 0x1C349C
extern const char d_1c3870[];                    // 0x1C3870
extern const char d_1a2884[];           // Text 0x1A2884
#define EQI(x,v) (((x)==(v))?1:0)
#define C64 ((int)&d_1c2c64)
struct SO { int a; int *p; char c[52]; };
struct T13e { char b[0x13e]; };
struct T14 { char b[0x14]; };
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
#pragma aux f_125400_t1 "f_125400"
int f_1254a0(void *p1, int p2);
#pragma aux f_1254a0_t1 "f_1254a0"
int f_08f6c0();
#pragma aux f_08f6c0_t1 "f_08f6c0"
void f_08f1c0(int p1);
void f_08f580(void);
int f_090de0(int p1, int p2);
int f_090fa0(int p1, int p2, int p3);
int f_0911e0(int p1, int p2);
int f_091280();
#pragma aux f_091280_t1 "f_091280"
int f_091370(int p1, int p2);
#pragma aux f_091370_t1 "f_091370"
int f_0914a0(int p1);
#pragma aux f_0914a0_t1 "f_0914a0"
int f_091770(int p1, int p2, int p3, int p4);
#pragma aux f_091770_t1 "f_091770"
int f_08fa70(int p1, int p2);
#pragma aux f_08fa70_t1 "f_08fa70"
int f_08fd60(int p1);
#pragma aux f_08fd60_t1 "f_08fd60"
int f_090b90(int p1);
#pragma aux f_090b90_t1 "f_090b90"
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_08e320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verzweigt als zentrale Ereignis-Methode des zweiten Final-Dungeons anhand der ausgelösten
 *   Ereigniskennung (p2 von 0x65 bis 0x515) in sämtliche Raumaktionen, Fallen, Kämpfe, Rätsel und den Endkampf.
 * - Eingaben und Rückgabe: Die Methode nimmt den Dungeon-Objektzeiger p1 sowie die Ereigniskennung p2 entgegen
 *   und gibt 1 zurück, wenn das Ereignis behandelt wurde, sonst 0.
 * - Wichtige Variablen: Im Zweig case 0x385 (wie auch in f_08fcc0) steckt ein Originalfehler (siehe
 *   Fehlerliste): Es wird if (d_1bdb74 == 0) geprüft, das Flag d_1bdb74 danach jedoch nicht auf 1 gesetzt,
 *   sodass das Ereignis immer wieder ausgelöst wird.
 === Ende Beschreibung === */
static inline int h_e320id(int n){return n;}
static inline int h_e320eq995(const signed char&a,signed char b){b=(b&0)?(signed char)0:b; /* haelt die Registerzuteilung beim Byte-Vergleich wie im Original */ return a==b;}
static inline int h_e320eq(const signed char&a,signed char b){return a==b;}
static inline int h_e320lt(const signed char&a,signed char b){return a<b;}
static inline int h_e320lt2(signed char a,int b){return a<b;}
static inline void h_e320shop68(int p1){f_090fa0(p1,0x29000a,0x1657);}
static inline void h_e320shop73(int p1){f_090fa0(p1,0x29000c,0x15e7);}
static inline void h_e320case_6f(int p1){short uVar1,sVar2;int iVar3,uVar4;

    uVar1 = 0x1e;
    if (h_e320eq((signed char&)d_1bfaec,0)) uVar1 /= (short)2;
    (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x49, uVar1);
    return;

}
static inline void h_e320case_70(int p1){short uVar1,sVar2;int iVar3,uVar4;

    uVar1 = 0x1e;
    if (h_e320eq((signed char&)d_1bfaec,0)) uVar1 /= (short)2;
    (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x4a, uVar1);
    return;

}
static inline void h_e320case_71(int p1){short uVar1,sVar2;int iVar3,uVar4;

    uVar1 = 0x1e;
    if (h_e320eq((signed char&)d_1bfaec,0)) uVar1 /= (short)2;
    (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x4b, uVar1);
    return;

}
static inline void h_e320case_cb(int p1){short uVar1,sVar2;int iVar3,uVar4;

    if (!h_e320eq((signed char&)d_1bdb4c,0)) return;
    f_0bf730(C64, 0x29000039);
    sVar2 = ((short (*)(int, int, int)) * *(int **)(p1 + 8))(p1, 0x4c, 0);
    if (sVar2 != 0) return;
    d_1bdb4c = 1;
    return;

}
static inline void h_e320case_12e(int p1){short uVar1,sVar2;int iVar3,uVar4;

    if (!h_e320eq((signed char&)d_1bdb48,0)) return;
    sVar2 = ((short (*)(int, int, int)) * *(int **)(p1 + 8))(p1, 0x4d, 0);
    if (sVar2 != 0) return;
    d_1bdb48 = 1;
    return;

}
static inline void h_e320case_192(int p1){short uVar1,sVar2;int iVar3,uVar4;

    if (!h_e320eq((signed char&)d_1bdb40,0)) return;
    sVar2 = ((short (*)(int, int, int)) * *(int **)(p1 + 8))(p1, 0x4e, 0);
    if (sVar2 != 0) return;
    *(signed char*)&d_1bdb40=1;
    return;

}
static inline void h_e320case_44e(int p1,SO&ob){short uVar1,sVar2;int iVar3,uVar4;

    f_125400(&ob, d_1c349c, d_1c3870, d_1c3498);
    uVar4 = f_038c40(d_1c0004);
    ob.p[1] = uVar4;
    if (h_e320eq((signed char&)d_1bdb84,1))
      f_0bf730(C64, 0x290000c7);
    else
      f_0bf730(C64, 0x290000c6);
    int receiver = p1;
    if (h_e320eq((signed char&)d_1bdb84,0) && h_e320eq((signed char&)d_1bdb80,1)) {
      f_0f2720(7);
      sVar2 = ((short (*)(int,int,int)) * *(int **)(receiver + 8))(receiver,1,0);
      if (sVar2 == 0) {
        f_0f2720(0xd);
        d_1bdb84 = 1;
        f_091f70(0x21);
        f_057220((int)&d_1c2c00, 0x803004a, 0);
      }
    }
    f_1254a0(&ob, 0);
    return;

}
static inline void h_e320case_515(int p1){short uVar1,sVar2;int iVar3,uVar4;

    if (!h_e320eq((signed char&)d_1bdb84,0)) return;
    if (!h_e320eq((signed char&)d_1bdb80,1)) return;
    f_0f2720(7);
    sVar2 = ((short (*)(int,int,int)) * *(int **)(p1 + 8))(p1,1,0);
    if (sVar2 != 0) return;
    f_0f2720(0xd);
    d_1bdb84 = 1;
    f_091f70(0x21);
    f_057220((int)&d_1c2c00, 0x803004a, 0);
    return;
}
int f_08e320(int p1, int p2)
{
  short sVar2, uVar1;
  int iVar3, uVar4;
  struct L{SO o75,o66,o385,o6c,o44e;}l;
  int r=1;
  {int keep995=d_1c0004; d_1c0004=keep995;} // haelt die Registerzuteilung in f_08e320 wie im Original
  struct T13e *q;
  switch ((unsigned short)p2) {
  case 0x65:
    if (!h_e320eq((signed char&)d_1bdb30,0)) goto done;
    d_1bdb30 = 1;
    f_0bf730(C64, 0x29000021);
    goto done;
  case 0x66:
    f_125400(&l.o66, d_1c349c, d_1c3870, d_1c3498);
    iVar3 = f_0397d0(d_1c0004, 0x175);
    if (iVar3 != 0) {
      if (d_1bdb2c == 0) {
        l.o66.p[1] = iVar3;
        d_1bdb2c = 1;
        f_0bf730(C64, 0x29000022);
      }
    } else {
      l.o66.p[1] = f_039320(d_1c0004, 0x27);
      f_0bf730(C64, 0x29000023);
      f_0609d0(0xf, 3);
      f_0dd7f0(d_1c0004, 10, 0x13f0);
    }
    f_1254a0(&l.o66, 0);
    goto done;
  case 0x67:
    f_090de0(p1, 0x290008);
    goto done;
  case 0x68:
    h_e320shop68(p1);
    goto done;
  case 0x69:
    f_0911e0(p1, 0x29000e);
    goto done;
  case 0x6a:
    iVar3 = f_0bf6f0(C64, 0x2900002c);
    if (iVar3 != 1) goto done;
    f_060800(0x290012, 0, 0);
    f_0bf730(C64, 0x2900002d);
    f_039a80(d_1c0004, (int)f_08f1c0);
    goto done;
  case 0x6b:
    if (!h_e320eq((signed char&)d_1bdb40,0)) goto done;
    { int t = (int)operator new(0x13e, mark(d_1a2884, 0x1a8));
      q = (T13e *)(t ? f_0104b0(t, 0x2c0007, 0, 0) : t);
    }
    f_0bf980(C64, (int)q, 0, 0x2900002e, 0);
    if (q) delete (char *)f_010590((int)q, 0);
    goto done;
  case 0x6c:
    f_125400(&l.o6c, d_1c349c, d_1c3870, d_1c3498);
    if (h_e320eq((signed char&)d_1bdb44,0)) {
      uVar4 = f_039660(d_1c0004, 0xd);
      l.o6c.p[1] = uVar4;
      uVar4 = f_039660(d_1c0004, 5);
      l.o6c.p[2] = uVar4;
      f_0bf730(C64, 0x2900002f);
      l.o6c.p[2] = l.o6c.p[1];
      f_0bf730(C64, 0x29000030);
      d_1bdb44 = 1;
    }
    f_1254a0(&l.o6c, 0);
    goto done;
  case 0x6d:
    if (!h_e320eq((signed char&)d_1bdb48,0)) goto done;
    { int t = (int)operator new(0x13e, mark(d_1a2884, 0x1db));
      q = (T13e *)(t ? f_0104b0(t, 0x2c0008, 0, 0) : t);
    }
    f_0bf980(C64, (int)q, 0, 0x29000031, 0);
    if (q) delete (char *)f_010590((int)q, 0);
    goto done;
  case 0x6e:
    ((int(*)(int))f_091280)(p1);
    goto done;
  case 0x6f:h_e320case_6f(p1);goto done;
  case 0x70:h_e320case_70(p1);goto done;
  case 0x71:h_e320case_71(p1);goto done;
  case 0x72:
    f_090de0(p1, 0x290006);
    goto done;
  case 0x73:
    h_e320shop73(p1);
    goto done;
  case 0x74:
    f_0911e0(p1, 0x290010);
    goto done;
  case 0x75: {
      unsigned char mask = 2;
      mask &= d_1bdb24;
      int flag = mask ? 1 : 0;
    { short hold = d_1a9820; d_1a9820 = hold; } // haelt die Registerzuteilung im Zweig 0x75 wie im Original
      if (flag != 0) goto done;
    d_1bdb24 |= 2;
    int snd;
    f_147323((int)&d_1c2edc, 0x290024, 0x7fff, 0x8000, (snd=*(int *)&d_1a9820), flag, 1);
    f_125400(&l.o75, d_1c349c, d_1c3870, d_1c3498);
    uVar4 = f_039660(d_1c0004, 5);
    {int keep75_0=d_1c0004; d_1c0004=keep75_0;} // haelt die Registergewichte in f_08e320 wie im Original
    {signed char keep75_1=d_1bdb30; d_1bdb30=keep75_1;} // haelt die Registergewichte in f_08e320 wie im Original
    {int keep75_2=d_1bdb40; d_1bdb40=keep75_2;} // haelt die Registergewichte in f_08e320 wie im Original
    {signed char keep75_3=d_1bdb48; d_1bdb48=keep75_3;} // haelt die Registergewichte in f_08e320 wie im Original
    {signed char keep75_4=d_1bdb50; d_1bdb50=keep75_4;} // haelt die Registergewichte in f_08e320 wie im Original
    l.o75.p[1] = uVar4;
    f_0bf730(C64, 0x29000033);
    f_1254a0(&l.o75, 0);
    goto done; }
  case 0xc9:
    ((int(*)(int))f_08f580)(p1);
    goto done;
  case 0xca:
    ((int(*)(int))f_08f6c0)(p1);
    goto done;
  case 0xcb:h_e320case_cb(p1);goto done;
  case 0x12d:
    f_0bf730(C64, 0x2900003a);
    goto done;
  case 0x12e:h_e320case_12e(p1);goto done;
  case 0x191:
    if (h_e320lt(d_1bdb50,6)) {
      iVar3 = f_0bf6f0(C64, 0x2900003b);
      if (iVar3 != 1) goto done;
      d_1bdb50 = d_1bdb50 + 1;
      f_0dcf00(d_1c0004, 0x183, 2);
      if (h_e320lt(d_1bdb50,6)) {
        f_0bf730(C64, 0x2900003c);
        goto done;
      }
      f_0bf730(C64, 0x2900003d);
      goto done;
    }
    f_0bf730(C64, 0x2900003e);
    goto done;
  case 0x192:h_e320case_192(p1);goto done;
  case 0x1f5:
    f_091370(p1, 0x290018);
    goto done;
  case 0x1f6:
    f_091370(p1, 0x290016);
    goto done;
  case 0x1f7:
    f_091370(p1, 0x290014);
    goto done;
  case 0x1f8:
    f_091370(p1, 0x29001a);
    goto done;
  case 0x1f9:
    f_0914a0(p1);
    goto done;
  case 0x1fa:{ unsigned char v=(unsigned char)p2; *(unsigned char*)&d_1bdb6c=v^(unsigned char)p2; }goto done;
  case 0x1fb:{ unsigned char v=(unsigned char)p2; *(unsigned char*)&d_1bdb6c=v^(unsigned char)p2; }goto done;
  case 0x1fc:{ unsigned char v=(unsigned char)p2; *(unsigned char*)&d_1bdb6c=v^(unsigned char)p2; }goto done;
  case 0x1fd:{ unsigned char v=(unsigned char)p2; *(unsigned char*)&d_1bdb6c=v^(unsigned char)p2; }goto done;
  case 0x259:
    goto done;
  case 0x25a:
    f_091770(p1, 0x29001e, 0x290022, 0x290022);
    goto done;
  case 0x25b:
    f_091770(p1, 0x29001c, 0x290020, 0x290020);
    goto done;
  case 0x2bd:
    if (!h_e320eq995((signed char&)d_1bdb54,0)) goto done;
    d_1bdb54 = 1;
    iVar3 = f_0606a0(0x290001, 2);
    f_0bfa20(C64,iVar3,0,0x29000054,0);
    if (iVar3) delete (char *)((int)(((RivaRasterImage*)(iVar3))->f_0fad20( 0)));
    goto done;
  case 0x321:
    ((int(*)(int))f_08fa70)(p1);
    goto done;
  case 0x322:
    goto done;
  case 0x385:
    if (!h_e320eq((signed char&)d_1bdb74,0)) goto done;
#if FIX_R059   /* R059: Einmal-Flag d_1bdb74 beim Ausloesen von Feld 0x385 auf 1 setzen */
    d_1bdb74 = 1;
#endif
    f_125400(&l.o385, d_1c349c, d_1c3870, d_1c3498);
    uVar4 = f_039660(d_1c0004, 0xd);
    l.o385.p[1] = uVar4;
    f_0bf730(C64, 0x290000c3);
    f_0609d0(0xf, 3);
    f_0dd7f0(d_1c0004, 0x1b, 0x13a3);
    f_1254a0(&l.o385, 0);
    goto done;
  case 0x386:
    goto done;
  case 0x3e9:
    f_08fd60(p1);
    goto done;
  case 0x3ea:
    goto done;
  case 0x44d:
    if (!h_e320eq((signed char&)d_1bdb7c,0)) goto done;
    d_1bdb7c = 1;
    f_0bf730(C64, 0x290000c5);
    goto done;
  case 0x44e:h_e320case_44e(p1,l.o44e);goto done;
  case 0x4b1:
    f_0bf730(C64, 0x290000c8);
    goto done;
  case 0x4b2:
    f_090b90(p1);
    goto done;
  case 0x515:h_e320case_515(p1);goto done;

  }
  r=0;
 done:return r;
}
//@ f_08f090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim erstmaligen Betreten des Ereignisfelds 0x65 (d_1bdb30 == 0) die Beschreibungsmeldung
 *   0x29000021 aus und setzt d_1bdb30 = 1.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb30 verhindert eine erneute Ausgabe der Meldung.
 === Ende Beschreibung === */
void f_08f090(void)
{
  if (EQI(d_1bdb30, 0)) {
    d_1bdb30 = 1;
    f_0bf730(C64, 0x29000021);
  }
}
//@ f_08f0c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft am Ereignisfeld 0x66, ob ein Held den Schlüssel- oder Schutzgegenstand 0x175 trägt
 *   (f_0397d0); falls ja, erscheint einmalig (d_1bdb2c == 0) die Meldung 0x29000022, andernfalls bemerkt der
 *   Held mit dem höchsten Talentwert 0x27 (*Gefahreninstinkt*) die Gefahr (0x29000023) und die Gruppe wird auf
 *   Feld 0x13f0 in Karte 10 versetzt (f_0dd7f0).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb2c merkt sich, dass der Hinweis auf den Gegenstand 0x175 bereits
 *   ausgegeben wurde.
 === Ende Beschreibung === */
void f_08f0c0(void)
{
  int iVar1, uVar2;
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  iVar1 = f_0397d0(d_1c0004, 0x175);
  if (iVar1 != 0) {
    if (d_1bdb2c == 0) {
      d_1bdb2c = 1;
      o.p[1] = iVar1;
      f_0bf730(C64, 0x29000022);
    }
  } else {
    uVar2 = f_039320(d_1c0004, 0x27);
    o.p[1] = uVar2;
    f_0bf730(C64, 0x29000023);
    f_0609d0(0xf, 3);
    f_0dd7f0(d_1c0004, 10, 0x13f0);
  }
  f_1254a0(&o, 0);
}
//@ f_08f180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x67 die Körperkraft-/Schadensprüfung f_090de0 mit der
 *   Animationskennung 0x290008 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die eigentliche Abwicklung erfolgt in f_090de0.
 === Ende Beschreibung === */
void f_08f180(int p1)
{
  f_090de0(p1, 0x290008);
}
//@ f_08f190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x68 die Selbstbeherrschungs-/Krankheitsprüfung f_090fa0 mit der
 *   Animation 0x29000a und dem Zielpunkt 0x1657 auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Parameter werden direkt an f_090fa0 weitergereicht.
 === Ende Beschreibung === */
void f_08f190(int p1)
{
  f_090fa0(p1, 0x29000a, 0x1657);
}
//@ f_08f1b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x69 die Prüfroutine f_0911e0 mit der Animationskennung 0x29000e
 *   auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Gesteuert wird der Ablauf über das Flag d_1bdb3c in f_0911e0.
 === Ende Beschreibung === */
void f_08f1b0(int p1)
{
  f_0911e0(p1, 0x29000e);
}
//@ f_08f1c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt einem lebenden Gruppenmitglied (p1) bei einer Falle oder Explosion 2..5 Schadenspunkte
 *   (f_145760(2, 5)) zu.
 * - Eingaben und Rückgabe: Die Rückruffunktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sie wird über f_039a80 für alle Helden der aktiven Gruppe aufgerufen.
 === Ende Beschreibung === */
void f_08f1c0(int p1)
{
  short sVar1;
  int iVar2;
  iVar2 = f_0d4a60(p1);
  if (iVar2 != 0) {
    sVar1 = f_145760(2, 5);
    f_044300(p1, (int)sVar1);
  }
}
//@ f_08f1f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler am Ereignisfeld 0x6a (0x2900002c), spielt bei Zustimmung die Animation
 *   0x290012 und die Meldung 0x2900002d ab und fügt allen Helden über f_08f1c0 jeweils 2..5 Schadenspunkte zu.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Gruppeniteration erfolgt über f_039a80(d_1c0004, f_08f1c0).
 === Ende Beschreibung === */
void f_08f1f0(void)
{
  int iVar1;
  iVar1 = f_0bf6f0(C64, 0x2900002c);
  if (iVar1 == 1) {
    f_060800(0x290012, 0, 0);
    f_0bf730(C64, 0x2900002d);
    f_039a80(d_1c0004, (int)f_08f1c0);
  }
}
//@ f_08f240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt am Ereignisfeld 0x6b, solange der zugehörige Gegner noch nicht besiegt ist (d_1bdb40 ==
 *   0), die Animationssequenz 0x2c0007 mit dem Text 0x2900002e ab.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb40 wird erst nach dem Sieg im zugehörigen Kampf (f_08f8c0) auf 1 gesetzt.
 === Ende Beschreibung === */
void f_08f240(void)
{
  int p1;
  int t;
  if (EQI((signed char)d_1bdb40, 0)) {
    t = (int)operator new(0x13e, mark(d_1a2884, 0x1a8)); p1 = (t != 0) ? f_0104b0(t, 0x2c0007, 0, 0) : t;
    f_0bf980(C64, p1, 0, 0x2900002e, 0);
    if (p1) operator delete((void *)f_010590(p1, 0));
  }
}
//@ f_08f2c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Betreten von Feld 0x6c (d_1bdb44 == 0) einen Dialog (0x2900002f und
 *   0x29000030) zwischen zwei ausgewählten Gruppenmitgliedern (f_039660 mit Kriterien 0xd und 5) an und setzt
 *   anschließend d_1bdb44 = 1.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Textplatzhalter o.p[1] und o.p[2] nehmen die Zeiger auf die beiden sprechenden
 *   Helden auf.
 === Ende Beschreibung === */
void f_08f2c0(void)
{
  int uVar1;
  struct SO o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  if (EQI(d_1bdb44, 0)) {
    uVar1 = f_039660(d_1c0004, 0xd);
    o.p[1] = uVar1;
    uVar1 = f_039660(d_1c0004, 5);
    o.p[2] = uVar1;
    f_0bf730(C64, 0x2900002f);
    o.p[2] = o.p[1];
    f_0bf730(C64, 0x29000030);
    d_1bdb44 = 1;
  }
  f_1254a0(&o, 0);
}
//@ f_08f360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt am Ereignisfeld 0x6d, solange der Kampf 0x4d noch offen ist (d_1bdb48 == 0), die
 *   Animationssequenz 0x2c0008 mit der Meldung 0x29000031 ab.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb48 wird nach dem Gewinn des Kampfes 0x4d (f_08f800) auf 1 gesetzt.
 === Ende Beschreibung === */
void f_08f360(void)
{
  int p1;
  int t;
  if (EQI(d_1bdb48, 0)) {
    t = (int)operator new(0x13e, mark(d_1a2884, 0x1db)); p1 = (t != 0) ? f_0104b0(t, 0x2c0008, 0, 0) : t;
    f_0bf980(C64, p1, 0, 0x29000031, 0);
    if (p1) operator delete((void *)f_010590(p1, 0));
  }
}
//@ f_08f3e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst über die virtuelle Methode an Offset +4 der Dungeon-Steuerung (p1) die Zufalls- oder
 *   Wachbegegnung 0x49 mit einer Basiswahrscheinlichkeit von 30 % (0x1e, im Einsteigermodus d_1bfaec == 0
 *   halbiert auf 15 %) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bfaec reduziert im Einsteigermodus die Kampfhäufigkeit auf die Hälfte.
 === Ende Beschreibung === */
void f_08f3e0(int p1)
{
  short uVar1;
  uVar1 = 0x1e;
  if (EQI(d_1bfaec, 0)) uVar1 /= (short)2;
  (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x49, uVar1);
}
//@ f_08f420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst analog zu f_08f3e0 die Wachbegegnung 0x4a mit einer Wahrscheinlichkeit von 30 % (bzw. 15
 *   % im Einsteigermodus) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Auch hier steuert d_1bfaec die Halbierung der Auslösechance im Einsteigermodus.
 === Ende Beschreibung === */
void f_08f420(int p1)
{
  short uVar1;
  uVar1 = 0x1e;
  if (EQI(d_1bfaec, 0)) uVar1 /= (short)2;
  (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x4a, uVar1);
}
//@ f_08f460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst analog zu f_08f3e0 die Wachbegegnung 0x4b mit einer Wahrscheinlichkeit von 30 % (bzw. 15
 *   % im Einsteigermodus) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Auslösewahrscheinlichkeit uVar1 beträgt 30 bzw. 15.
 === Ende Beschreibung === */
void f_08f460(int p1)
{
  short uVar1;
  uVar1 = 0x1e;
  if (EQI(d_1bfaec, 0)) uVar1 /= (short)2;
  (*(void (**)(int, int, short))(*(int *)(p1 + 8) + 4))(p1, 0x4b, uVar1);
}
//@ f_08f4a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x72 die Prüfroutine f_090de0 mit der Animationskennung 0x290006
 *   auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Delegiert direkt an f_090de0.
 === Ende Beschreibung === */
void f_08f4a0(int p1)
{
  f_090de0(p1, 0x290006);
}
//@ f_08f4b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x73 die Prüfroutine f_090fa0 mit der Animation 0x29000c und dem
 *   Zielpunkt 0x15e7 auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Delegiert direkt an f_090fa0.
 === Ende Beschreibung === */
void f_08f4b0(int p1)
{
  f_090fa0(p1, 0x29000c, 0x15e7);
}
//@ f_08f4d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Hindernisfeld 0x74 die Prüfroutine f_0911e0 mit der Animationskennung 0x290010
 *   auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Delegiert direkt an f_0911e0.
 === Ende Beschreibung === */
void f_08f4d0(int p1)
{
  f_0911e0(p1, 0x290010);
}
//@ f_08f4e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt beim ersten Betreten des Ereignisfelds 0x75 ((d_1bdb24 & 2) == 0) das Geräusch 0x290024
 *   ab, gibt die Meldung 0x29000033 für einen ausgewählten Helden (f_039660(..., 5)) aus und setzt Bit 1 (0x02)
 *   in d_1bdb24.
 * - Eingaben und Rückgabe: Die Funktion erhält den (ungenutzten) Kontextzeiger p1 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Bit 1 von d_1bdb24 merkt vor, dass dieser Geräusch- und Texteffekt bereits ausgelöst
 *   wurde.
 === Ende Beschreibung === */
void f_08f4e0(int p1)
{
  enum { flag_mask = 2 };
  unsigned char t = d_1bdb24;
  t &= flag_mask;
  unsigned char flag = t ? (unsigned char)1 : (unsigned char)0;
  if (flag == 0) {
    d_1bdb24 |= 2;
    { int snd = *(int *)&d_1a9820; f_147323((int)&d_1c2edc, 0x290024, 0x7fff, 0x8000, snd, 0, 1); }
    struct SO o;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = f_039660(d_1c0004, 5);
    f_0bf730(C64, 0x29000033);
    f_1254a0(&o, 0);
  }
}
//@ f_08f580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet am Ereignisfeld 0xc9 den Beutecontainer Nr. 0x44, legt zuvor ein Exemplar des wichtigen
 *   Gegenstands 0x179 hinein, falls die Gruppe ihn noch nicht besitzt (f_0d54f0 == -1), und gibt je nach
 *   Entnahme die Meldung 0x29000034 oder 0x29000035 aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Dadurch wird sichergestellt, dass der Questgegenstand 0x179 in Truhe 0x44 auffindbar
 *   bleibt, solange er noch keinem Helden gehört.
 === Ende Beschreibung === */
int f_014b10(const char *p1, int p2);
int f_014ab0(int p1, int p2);
int f_038c40(int p1);
#pragma aux f_038c40_t1 "f_038c40"
int f_039b00(int p1, int p2, int p3);
#pragma aux f_039b00_t1 "f_039b00"
void f_014710(int p1);
#pragma aux f_014710_t1 "f_014710"
struct MsgC {
  int a;
  int *p;
  char c[52];
  MsgC(const char *a, const char *b, const char *c);   // = f_125400 (extern wie Obj in t3, kein COMDAT)
  ~MsgC();                                             // = f_1254a0
};
void f_08f580(void)
{
  MsgC m(d_1c349c, d_1c3870, d_1c3498);
  int q;
  int h;
  {
    int t = f_014ab0(0x14, f_014b10(d_1a2884, 0x28c));
    q = t ? f_112df0(t, 0x44, 0, 0) : t;
  }
  h = q;
  if (f_0d54f0(d_1c0004, 0x179) == -1) {
    if (f_113500(q, 0x179) == 0) {
      f_113340(q, 0x179, 1, 0);
    }
  }
  m.p[1] = f_038c40(d_1c0004);
  m.p[2] = f_039b00(d_1c0004, m.p[1], 0x2f);
  if (m.p[2] == 0)
    m.p[2] = m.p[1];
  if (f_1131b0(h) == 1) {
    if (f_113500(h, 0x17b) > 0)
      f_0bf730(C64, 0x29000034);
    f_112ec0(h);
  } else {
    f_0bf730(C64, 0x29000035);
  }
  if (h)
    f_014710(f_112e70(h, 0));
}

#undef C64
#undef EQB
#undef EQI
#undef d_1a2880
#undef d_1a2884
#undef d_1a28c8
#undef d_1a28ce
#undef d_1a28da
#undef d_1a9820
#undef d_1bc940
#undef d_1bdb24
#undef d_1bdb28
#undef d_1bdb2c
#undef d_1bdb30
#undef d_1bdb34
#undef d_1bdb38
#undef d_1bdb3c
#undef d_1bdb40
#undef d_1bdb44
#undef d_1bdb48
#undef d_1bdb4c
#undef d_1bdb50
#undef d_1bdb54
#undef d_1bdb58
#undef d_1bdb5c
#undef d_1bdb60
#undef d_1bdb64
#undef d_1bdb68
#undef d_1bdb6c
#undef d_1bdb70
#undef d_1bdb74
#undef d_1bdb7c
#undef d_1bdb80
#undef d_1bdb84
#undef d_1bfaec
#undef d_1c0004
#undef d_1c1078
#undef d_1c107c
#undef d_1c21a4
#undef d_1c27a8
#undef d_1c2c00

#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_014710
#undef f_032820
#undef f_033530
#undef f_036300
#undef f_038be0
#undef f_038c40
#undef f_038d70
#undef f_039320
#undef f_039660
#undef f_0397d0
#undef f_0398c0
#undef f_039a80
#undef f_039ac0
#undef f_039b00
#undef f_042380
#undef f_042a60
#undef f_043120
#undef f_043d40
#undef f_043d50
#undef f_044300
#undef f_044900
#undef f_044c90
#undef f_0453e0
#undef f_057220
#undef f_060230
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060800
#undef f_0609d0
#undef f_060a70
#undef f_069630
#undef f_069730
#undef f_0697c0
#undef f_08de20
#undef f_08f6c0
#undef f_08fa70
#undef f_08fd60
#undef f_090b90
#undef f_090de0
#undef f_090fa0
#undef f_0911e0
#undef f_091280
#undef f_091370
#undef f_0914a0
#undef f_091770
#undef f_091f70

#undef f_0bde40
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf820
#undef f_0bf980
#undef f_0d4a60
#undef f_0d4c80
#undef f_0d5040
#undef f_0d54f0
#undef f_0db9a0
#undef f_0dc020
#undef f_0dcb60
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd480
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de840
#undef f_0de880
#undef f_0f2720

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_113340
#undef f_113500
#undef f_125400
#undef f_1254a0
#undef f_145760
#undef f_1457e0
#undef f_149360
#undef f_149a14
#undef SO
#undef T14
#undef EQBF

// ===== Teil final2_t2 =====
#define d_1a2880 d_1a2880_t2
#define d_1a2884 d_1a2884_t2
#define d_1a28c8 d_1a28c8_t2
#define d_1a28ce d_1a28ce_t2
#define d_1a28da d_1a28da_t2
#define d_1a9820 d_1a9820_t2
#define d_1bc940 d_1bc940_t2
#define d_1bdb24 d_1bdb24_t2
#define d_1bdb28 d_1bdb28_t2
#define d_1bdb2c d_1bdb2c_t2
#define d_1bdb30 d_1bdb30_t2
#define d_1bdb34 d_1bdb34_t2
#define d_1bdb38 d_1bdb38_t2
#define d_1bdb3c d_1bdb3c_t2
#define d_1bdb40 d_1bdb40_t2
#define d_1bdb44 d_1bdb44_t2
#define d_1bdb48 d_1bdb48_t2
#define d_1bdb4c d_1bdb4c_t2
#define d_1bdb50 d_1bdb50_t2
#define d_1bdb54 d_1bdb54_t2
#define d_1bdb58 d_1bdb58_t2
#define d_1bdb5c d_1bdb5c_t2
#define d_1bdb60 d_1bdb60_t2
#define d_1bdb64 d_1bdb64_t2
#define d_1bdb68 d_1bdb68_t2
#define d_1bdb6c d_1bdb6c_t2
#define d_1bdb70 d_1bdb70_t2
#define d_1bdb74 d_1bdb74_t2
#define d_1bdb7c d_1bdb7c_t2
#define d_1bdb80 d_1bdb80_t2
#define d_1bdb84 d_1bdb84_t2
#define d_1bfaec d_1bfaec_t2
#define d_1c0004 d_1c0004_t2
#define d_1c1078 d_1c1078_t2
#define d_1c107c d_1c107c_t2
#define d_1c21a4 d_1c21a4_t2
#define d_1c27a8 d_1c27a8_t2
#define d_1c2c00 d_1c2c00_t2

#define d_1c2c64 d_1c2c64_t2
#define d_1c2edc d_1c2edc_t2
#define d_1c3498 d_1c3498_t2
#define d_1c349c d_1c349c_t2
#define d_1c3870 d_1c3870_t2
#define f_0104b0 f_0104b0_t2
#define f_010590 f_010590_t2
#define f_032820 f_032820_t2
#define f_033530 f_033530_t2
#define f_036300 f_036300_t2
#define f_038be0 f_038be0_t2
#define f_038c40 f_038c40_t2
#define f_038d70 f_038d70_t2
#define f_039320 f_039320_t2
#define f_039660 f_039660_t2
#define f_0397d0 f_0397d0_t2
#define f_0398c0 f_0398c0_t2
#define f_039a80 f_039a80_t2
#define f_039ac0 f_039ac0_t2
#define f_039b00 f_039b00_t2
#define f_042380 f_042380_t2
#define f_042a60 f_042a60_t2
#define f_043120 f_043120_t2
#define f_043d40 f_043d40_t2
#define f_043d50 f_043d50_t2
#define f_044300 f_044300_t2
#define f_044900 f_044900_t2
#define f_044c90 f_044c90_t2
#define f_0453e0 f_0453e0_t2
#define f_057220 f_057220_t2
#define f_060230 f_060230_t2
#define f_0606a0 f_0606a0_t2
#define f_060740 f_060740_t2
#define f_060760 f_060760_t2
#define f_0607e0 f_0607e0_t2
#define f_060800 f_060800_t2
#define f_0609d0 f_0609d0_t2
#define f_060a70 f_060a70_t2
#define f_069630 f_069630_t2
#define f_069730 f_069730_t2
#define f_0697c0 f_0697c0_t2
#define f_08de20 f_08de20_t2
#define f_08f1c0 f_08f1c0_t2
#define f_091370 f_091370_t2
#define f_091770 f_091770_t2
#define f_091f70 f_091f70_t2

#define f_0bde40 f_0bde40_t2
#define f_0bf6f0 f_0bf6f0_t2
#define f_0bf730 f_0bf730_t2
#define f_0bf820 f_0bf820_t2
#define f_0bf980 f_0bf980_t2
#define f_0bfa20 f_0bfa20_t2
#define f_0d4a60 f_0d4a60_t2
#define f_0d4c80 f_0d4c80_t2
#define f_0d5040 f_0d5040_t2
#define f_0d54f0 f_0d54f0_t2
#define f_0db9a0 f_0db9a0_t2
#define f_0dc020 f_0dc020_t2
#define f_0dcb60 f_0dcb60_t2
#define f_0dcbb0 f_0dcbb0_t2
#define f_0dcf00 f_0dcf00_t2
#define f_0dd480 f_0dd480_t2
#define f_0dd750 f_0dd750_t2
#define f_0dd7f0 f_0dd7f0_t2
#define f_0de840 f_0de840_t2
#define f_0de880 f_0de880_t2
#define f_0f2720 f_0f2720_t2

#define f_112df0 f_112df0_t2
#define f_112e70 f_112e70_t2
#define f_112ec0 f_112ec0_t2
#define f_1131b0 f_1131b0_t2
#define f_113340 f_113340_t2
#define f_113500 f_113500_t2
#define f_125400 f_125400_t2
#define f_1254a0 f_1254a0_t2
#define f_145760 f_145760_t2
#define f_1457e0 f_1457e0_t2
#define f_147323 f_147323_t2
#define f_149360 f_149360_t2
#define f_149a14 f_149a14_t2
#define SO SO_t2
#define T14 T14_t2
#define EQBF EQBF_t2
// P3 27/35 gleich (suche.py 26.10.2026, Basis final2_t2_P1.CPP)
// final2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08E320-0x091B50
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, void (*p2)());
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042380(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_043120(int p1);                                   // reg eax stapel 0
int f_043d40(int p1);                                   // reg eax stapel 0
int f_043d50(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060230();                                         // reg - stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
short f_060760(int p1);
#pragma aux f_060760_t2 "f_060760"
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0609d0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069630(int p1, int p2);                           // reg eax edx stapel 0
int f_069730(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_08de20(int p1);                                   // reg eax stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_0bf820(...);
#pragma aux f_0bf820_t2 "f_0bf820"
int f_0bf980();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcb60(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
unsigned short f_0dd480(int p1);
#pragma aux f_0dd480_t2 "f_0dd480"
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0f2720(int,int,int,int);
#pragma aux f_0f2720_t2 "f_0f2720"
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113500(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
short f_145760(int p1, int p2);
#pragma aux f_145760_t2 "f_145760"
unsigned short f_1457e0(int p1);
#pragma aux f_1457e0_t2 "f_1457e0"
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
int f_149a14(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a2880;                    // 0x1A2880
extern int d_1a28ce;                    // 0x1A28CE
extern int d_1a28da;                    // 0x1A28DA
extern signed char d_1a9820;                    // 0x1A9820
extern int d_1bc940;                    // 0x1BC940
extern int d_1bdb24;                    // 0x1BDB24
extern int d_1bdb28;                    // 0x1BDB28
extern int d_1bdb2c;                    // 0x1BDB2C
extern int d_1bdb30;                    // 0x1BDB30
extern int d_1bdb34;                    // 0x1BDB34
extern int d_1bdb38;                    // 0x1BDB38
extern int d_1bdb3c;                    // 0x1BDB3C
extern signed char d_1bdb40;                    // 0x1BDB40
extern volatile signed char d_1bdb44;                    // 0x1BDB44 - haelt das erneute Lesen aus dem Speicher wie im Original
extern signed char d_1bdb48;                    // 0x1BDB48
extern volatile signed char d_1bdb4c;                    // 0x1BDB4C - haelt das erneute Lesen aus dem Speicher wie im Original
extern signed char d_1bdb54;                    // 0x1BDB54
extern unsigned short d_1bdb58;                    // 0x1BDB58
extern short d_1bdb5c;                    // 0x1BDB5C
extern signed char d_1bdb60;                    // 0x1BDB60
extern int d_1bdb64;                    // 0x1BDB64
extern int d_1bdb68;                    // 0x1BDB68
extern char d_1bdb6c;                    // 0x1BDB6C
extern int d_1bdb70;                    // 0x1BDB70
extern signed char d_1bdb74;                    // 0x1BDB74
extern signed char d_1bdb7c;                    // 0x1BDB7C
extern signed char d_1bdb80;                    // 0x1BDB80
extern signed char d_1bdb84;                    // 0x1BDB84
extern int d_1bfaec;                    // 0x1BFAEC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c1078;                    // 0x1C1078
extern int d_1c107c;                    // 0x1C107C
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1c3498[];                    // 0x1C3498
extern const char d_1c349c[];                    // 0x1C349C
extern const char d_1c3870[];                    // 0x1C3870
extern const char d_1a2884[];           // Text 0x1A2884
extern signed char d_1bdb50;
#pragma aux d_1bdb50_t2 "d_1bdb50"
struct T9 { int a[9]; };
struct S6 { short s[3]; };
extern T9 d_1a28a4;
extern S6 d_1a28c8;
#pragma aux d_1a28c8_t2 "d_1a28c8"
struct T14 { int a[5]; };
struct SO { int a; int *p; char c[52]; SO(const char*,const char*,const char*); ~SO(); };
int f_091370(int, int);
int f_091770(int, int, int, int);
void f_08f1c0();
#pragma aux f_08f1c0_t2 "f_08f1c0"
#define CH ((int)&d_1c2c64)
#define WAIT do { u = f_0bf820(); } while (u == 0xffff);
#define VC3(p,a,b) ((short(*)(int,int,int))(**(int**)((p)+8)))((p),(a),(b))
#define VC1(p) ((short(*)(int))(**(int**)((p)+8)))(p)
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_08f6c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler am Ereignisfeld 0xca (0x29000036), öffnet bei Zustimmung den Beutecontainer
 *   Nr. 0x45 (0x29000037) und gibt nach dem Einsammeln die Meldung 0x29000038 mit dem Namen eines Helden
 *   (f_038be0) aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das temporäre Containerobjekt q verwaltet den Beuteinhalt der Fundstelle 0x45.
 === Ende Beschreibung === */
void f_08f6c0(void)
{
  SO o(d_1c349c, d_1c3870, d_1c3498);
  int q = 0;
  if (f_0bf6f0(CH, 0x29000036) == 1) {
    q = (int)new (mark(d_1a2884, 0x2c0)) T14;
    q = q ? f_112df0(q, 0x45, 0, 0) : q;
    f_0bf730(CH, 0x29000037);
    if (f_1131b0(q) == 1) {
      o.p[1] = f_038be0(d_1c0004);
      f_0bf730(CH, 0x29000038);
      f_112ec0(q);
    }
    if (q != 0) delete (char *)f_112e70(q, 0);
  }
}
//@ f_08f790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Betreten von Feld 0xcb (d_1bdb4c == 0) die Kampfmeldung 0x29000039 an,
 *   startet den Kampf Nr. 0x4c und setzt nach einem Sieg (s == 0) das Flag d_1bdb4c = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb4c speichert den Sieg über die Gegnerwelle 0x4c.
 === Ende Beschreibung === */
void f_08f790(int p1)
{
  short s;
  if (EQ(d_1bdb4c, 0)) {
    f_0bf730(CH, 0x29000039);
    s = VC3(p1, 0x4c, 0);
    if (s == 0) d_1bdb4c = 1;
  }
}
//@ f_08f7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt am Ereignisfeld 0x12d die Beschreibungsmeldung 0x2900003a aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt das globale Textfenster d_1c2c64.
 === Ende Beschreibung === */
void f_08f7e0(void)
{
  f_0bf730(CH, 0x2900003a);
}
//@ f_08f800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet beim ersten Auslösen von Feld 0x12e (d_1bdb48 == 0) den Kampf Nr. 0x4d und setzt nach
 *   einem Sieg (s == 0) das Flag d_1bdb48 = 1 (wodurch auch die Vorschauanimation in f_08f360 abgeschaltet
 *   wird).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Flag d_1bdb48 synchronisiert den Kampfstatus mit dem Beobachtungsfeld 0x6d.
 === Ende Beschreibung === */
void f_08f800(int p1)
{
  int s;
  if (EQB(d_1bdb48, 0)) {
    s = VC3(p1, 0x4d, 0);
    if (s == 0) d_1bdb48 = 1;
  }
}
//@ f_08f840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt der Gruppe am Ereignisfeld 0x191 bis zu sechsmal (d_1bdb50 < 6), nach Bestätigung
 *   (0x2900003b) jeweils 2 Exemplare des Gegenstands 0x183 aufzunehmen (f_0dcf00), und meldet je nach
 *   verbleibendem Vorrat 0x2900003c, 0x2900003d (gerade geleert) oder 0x2900003e (bereits leer).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zähler d_1bdb50 zählt die bisherigen Entnahmen (0..6) hoch.
 === Ende Beschreibung === */
void f_08f840(void)
{
  if (((d_1bdb50 < 6) ? 1 : 0)) {
    if (f_0bf6f0(CH, 0x2900003b) != 1) return;
    d_1bdb50 = d_1bdb50 + 1;
    f_0dcf00(d_1c0004, 0x183, 2);
    if (((d_1bdb50 < 6) ? 1 : 0)) f_0bf730(CH, 0x2900003c);
    else f_0bf730(CH, 0x2900003d);
  } else {
    f_0bf730(CH, 0x2900003e);
  }
}
//@ f_08f8c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet beim ersten Betreten von Feld 0x192 (d_1bdb40 == 0) den Kampf Nr. 0x4e und setzt bei
 *   einem Sieg (s == 0) das Flag d_1bdb40 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sobald d_1bdb40 == 1 gesetzt ist, entfällt auch die Vorschauanimation am Feld 0x6b
 *   (f_08f240).
 === Ende Beschreibung === */
void f_08f8c0(int p1)
{
  int s;
  if (EQB(d_1bdb40, 0)) {
    s = VC3(p1, 0x4e, 0);
    if (s == 0) d_1bdb40 = 1;
  }
}
//@ f_08f900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Ereignisfeld 0x1f5 die Prüf- und Kampffunktion f_091370 mit der Animationskennung
 *   0x290018 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Delegiert direkt an f_091370.
 === Ende Beschreibung === */
void f_08f900(int p1)
{
  f_091370(p1, 0x290018);
}
//@ f_08f910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Ereignisfeld 0x1f6 die Funktion f_091370 mit der Animationskennung 0x290016 auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Delegiert direkt an f_091370.
 === Ende Beschreibung === */
void f_08f910(int p1)
{
  f_091370(p1, 0x290016);
}
//@ f_08f920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Ereignisfeld 0x1f7 die Funktion f_091370 mit der Animationskennung 0x290014 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Delegiert direkt an f_091370.
 === Ende Beschreibung === */
void f_08f920(int p1)
{
  f_091370(p1, 0x290014);
}
//@ f_08f930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Ereignisfeld 0x1f8 die Funktion f_091370 mit der Animationskennung 0x29001a auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Delegiert direkt an f_091370.
 === Ende Beschreibung === */
void f_08f930(int p1)
{
  f_091370(p1, 0x29001a);
}
//@ f_08f940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt beim Verlassen des Gefahrenbereichs (0x1fa..0x1fd) den Schrittzähler d_1bdb6c wieder auf
 *   0 zurück; direkt dahinter liegt an Adresse 0x08f950 ein einzelnes ret als leerer Ereignishaken für 0x259.
 * - Eingaben und Rückgabe: Die Funktion erhält die Parameter p1 und p2 und gibt das untere Byte von p1 zurück.
 * - Wichtige Variablen: Die globale Variable d_1bdb6c zählt in f_0914a0 die Schritte durch den Gefahrenkorridor.
 === Ende Beschreibung === */
char f_08f940(int p1, int p2)
{
  d_1bdb6c = 0;
  return p1;
}
void f_08f950(void) {}
//@ f_08f960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Durchgangsfeld 0x25a die Ausrüstungs- und Prüfroutine f_091770 mit den
 *   Animationskennungen 0x29001e und 0x290022 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Delegiert direkt an f_091770.
 === Ende Beschreibung === */
void f_08f960(int p1)
{
  f_091770(p1, 0x29001e, 0x290022, 0x290022);
}
//@ f_08f980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für das Durchgangsfeld 0x25b die Ausrüstungs- und Prüfroutine f_091770 mit den
 *   Animationskennungen 0x29001c und 0x290020 auf.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Delegiert direkt an f_091770.
 === Ende Beschreibung === */
void f_08f980(int p1)
{
  f_091770(p1, 0x29001c, 0x290020, 0x290020);
}
//@ f_08f9a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Betreten des Ereignisfelds 0x2bd (d_1bdb54 == 0) das Bild 0x290001 (Index 2)
 *   mit dem Text 0x29000054 an und setzt d_1bdb54 = 1.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb54 verhindert eine Wiederholung des Bilddialogs.
 === Ende Beschreibung === */
void f_08f9a0(void)
{
  int o;
  if (EQ(d_1bdb54, 0)) {
    d_1bdb54 = 1;
    o = f_0606a0(0x290001, 2);
    ((int (*)(int,...))f_0bfa20)(CH, o, 0, 0x29000054, 0);
    if (o != 0) delete (char *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0)));
  }
}
//@ f_08fa00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht p2 paarweise verschiedene Zufallszahlen aus dem Bereich 0..p3 (f_145760(0, p3)) und
 *   speichert sie ohne Duplikate im 16-Bit-Array ab p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielarray-Zeiger p1, die gewünschte Anzahl p2 sowie den
 *   Höchstwert p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Eine innere Schleife prüft jedes neu gezogene Element gegen alle bisherigen Einträge
 *   0..i-1 und wiederholt den Wurf bei Gleichheit.
 === Ende Beschreibung === */
void f_08fa00(int p1, short p2, short p3);
#pragma aux f_08fa00 modify exact [eax ebx ecx edx]
void f_08fa00(int p1, short p2, short p3)
{
#if FIX_BUGS >= 1
  int roll(int,int);
#else
  short roll(int,int);
#endif
  #pragma aux roll "f_145760" parm [eax] [edx] value [eax] modify exact [eax edx ecx]
  short i;
  short j;
  i = 0;
  if (p2 > (short)0) {
    do {
      int ok;
      *(short *)(p1 + i * 2) = roll(0, p3);
      ok = 1;
      for (j = 0; j < i; j++) {
        if (*(short *)(p1 + i * 2) == *(short *)(p1 + j * 2)) ok = 0;
      }
      if (ok == 1) i++;
    } while (i < (short)p2);
  }
}
//@ f_08fa70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt am Ereignisfeld 0x321 das dreistufige Prüfungsrätsel durch: Es werden drei verschiedene
 *   aus neun Frageroutinen (d_1a28a4: f_090190 bis f_090900) zufällig gezogen; beantwortet der Spieler alle drei
 *   Fragen richtig (a == 1 && b == 1 && c == 1), wird die Gruppe zum Ziel 0x1586 versetzt, erhält 20
 *   Abenteuerpunkte (f_0dcbb0) sowie die Spielpunkte 0x1d (f_091f70(0x1d)), andernfalls landet sie auf einem der
 *   Strafpunkte 0x14d5 oder 0x1531.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Statusvariable d_1bdb60 zählt die Fehlversuche (1 -> 2 -> 3) mit wechselnden
 *   Kommentaren der Gefährten und steht nach gelöstem Rätsel auf 4.
 === Ende Beschreibung === */
int f_038c40(int);
#pragma aux f_038c40_t2 "f_038c40"
int f_039660(int, int);
#define NE(x,v) (((x)!=(v))?1:0)
struct TF { int (*f[9])(int); };
void f_08fa70()
{
  if (NE(d_1bdb60, 4)) {
    if (EQ(d_1bdb60, 0)) d_1bdb60 = 1;
    SO so(d_1c349c, d_1c3870, d_1c3498);
    TF tab = *(TF *)&d_1a28a4;
    S6 idx = d_1a28c8;
    short i = 0;
    short *ip = idx.s;
    short j;
    short *pa, *pb;
    int ok;
    int a, b, c;
    do {
      ip[i] = f_145760(0, 8);
      ok = 1;
      for (j = 0; j < i; j++) {
        pa = ip + i;
        pb = ip + j;
        if (*pa == *pb) ok = 0;
      }
      if (ok == 1) i++;
    } while (i < (short)3);
    so.p[1] = f_038c40(d_1c0004);
    f_0bf730(CH, 0x29000055);
    a = tab.f[idx.s[0]](idx.s[0]);
    f_0bf730(CH, 0x2900005a);
    b = tab.f[idx.s[1]](idx.s[1]);
    f_0bf730(CH, 0x2900005a);
    c = tab.f[idx.s[2]](idx.s[2]);
    if (a == 1 && b == a && c == b) {
      f_0dd750(d_1c0004, 0x1586);
      f_0bf730(CH, 0x29000056);
      if (EQ(*(signed char *)&d_1bdb58, 0)) {
        signed char one = 1;
        *(signed char *)&d_1bdb58 = one;
        f_091f70(0x1d);
        f_0dcbb0(d_1c0004, 0x14);
      }
      d_1bdb60 = 4;
    } else {
      int m = ((short)f_1457e0(0x64) <= 0x32) ? 0x14d5 : 0x1531;
      int t;
      f_0dd750(d_1c0004, m);
      f_0bf730(CH, 0x29000057);
      t = d_1bdb60;
      if (EQ(t, 1)) {
        signed char v = 2;
        int arg = d_1c0004;
        d_1bdb60 = v;
        so.p[1] = f_038c40(arg);
        f_0bf730(CH, 0x29000058);
      } else if (EQ(t, 2)) {
        signed char v = 3;
        int arg = d_1c0004;
        d_1bdb60 = v;
        so.p[1] = f_039660(arg, 5);
        f_0bf730(CH, 0x29000059);
      }
    }
  }
}

//@ f_08fcb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Ereignishaken (ret) für das Feld 0x322.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Variablen verwendet.
 === Ende Beschreibung === */
void f_08fcb0(void)
{
}

//@ f_08fcc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt am Ereignisfeld 0x385 (sofern d_1bdb74 == 0) eine Warnmeldung (0x290000c3) durch ein
 *   Gruppenmitglied (f_039660(..., 0xd)) aus, dreht oder bewegt die Sicht (f_0609d0(0xf, 3)) und versetzt die
 *   Gruppe auf den Punkt 0x13a3 in Karte 0x1b (f_0dd7f0).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Hier (wie in f_08e320 bei case 0x385) liegt ein Originalfehler vor (siehe Fehlerliste):
 *   Das geprüfte Einmal-Flag d_1bdb74 wird in der Funktion nicht auf 1 gesetzt.
 === Ende Beschreibung === */
void f_08fcc0(void)
{
  if (EQ(d_1bdb74, 0)) {
#if FIX_R059   /* R059: Einmal-Flag d_1bdb74 beim Ausloesen von Feld 0x385 auf 1 setzen */
    d_1bdb74 = 1;
#endif
    SO o(d_1c349c, d_1c3870, d_1c3498);
    o.p[1] = f_039660(d_1c0004, 0xd);
    f_0bf730(CH, 0x290000c3);
    f_0609d0(0xf, 3);
    f_0dd7f0(d_1c0004, 0x1b, 0x13a3);
  }
}
//@ f_08fd50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Ereignishaken (ret) für das Feld 0x386.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Variablen verwendet.
 === Ende Beschreibung === */
void f_08fd50(void)
{
}
//@ f_08fd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Auslösen von Feld 0x3e9 (d_1bdb5c == 0) das Bild 0x290001 (Index 3) mit dem
 *   Text 0x290000c4 an, startet den Kampf Nr. 0x51 und vergibt nach einem Sieg (s == 0) die Spielpunkte 0x1f
 *   (f_091f70(0x1f)) samt Setzen von d_1bdb5c = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb5c speichert dauerhaft, dass der Kampf 0x51 gewonnen wurde.
 === Ende Beschreibung === */
void f_08fd60(int p1)
{
  SO o(d_1c349c, d_1c3870, d_1c3498);
  void *q;
  short s;
  if (((signed char)d_1bdb5c == 0) ? 1 : 0) {
    o.p[1] = f_038c40(d_1c0004);
    q = (void *)f_0606a0(0x290001, 3);
    ((int (*)(int,...))f_0bfa20)(CH, q, 0, 0x290000c4, 0);
    if (q) delete (char *)((int)(((RivaRasterImage*)((int)q))->f_0fad20( 0)));
    s = VC3(p1, 0x51, 0);
    if (s == 0) {
      f_091f70(0x1f);
      *(signed char *)&d_1bdb5c = 1;
    }
  }
}

//@ f_08fe20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Ereignishaken (ret) für das Feld 0x3ea.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Variablen verwendet.
 === Ende Beschreibung === */
void f_08fe20(void)
{
}

//@ f_08fe30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet aus der euklidischen Entfernung der Heldengruppe (f_0de840, f_0de880) zum Zentrum
 *   (-0x262, 0xf0) des Bienenstocks/Enddungeons eine entfernungsabhängige Lautstärke (1 * 0xfff bis 8 * 0xfff)
 *   für Hintergrundgeräusche.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Lautstärkewert (0xfff..0x7ff8) als
 *   short zurück.
 * - Wichtige Variablen: Je näher die Gruppe dem Zentrum kommt (n kleiner), desto höher fällt die Stufe u (1..8)
 *   aus.
 === Ende Beschreibung === */
short f_08fe30(void)
{
  int x, y, n;
  short u;
  unsigned short v;
  { int t_ = (int)(d_1c0004); x = (f_0de840(t_) >> 16) + 0x262; }
  { int t_ = (int)(d_1c0004); y = (f_0de880(t_) >> 16) - 0xf0; }
  int sum = x * x + y * y;
  sum = (sum & 0) ? 0 : sum; // haelt sum im Register edx wie im Original
  n = (int)sqrt((double)(sum + 1));
  if (n > 0xabe) n = 0xabe;
  u = 8 - (n * 8) / 0xabe;
  v = u;
  if (v < 1) u = 1;
  else if (v > 8) u = 8;
  return u * 0xfff;
}
//@ f_08fed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im laufenden Dungeon-Zyklus mit ansteigender Wahrscheinlichkeit (d_1a2880), ob das
 *   Kartenobjekt 0x1f41 im Zustand 1 steht, und spielt in diesem Fall die beiden unheimlichen
 *   Hintergrundgeräusche 0x290024 und 0x290025 mit entfernungsabhängiger Lautstärke (f_08fe30) sowie die Meldung
 *   0x29000020 ab.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Schwellenwert d_1a2880 steigt bei jedem Aufruf um 2 an und wird nach dem Auslösen
 *   des Geräuschs wieder auf 0 zurückgesetzt.
 === Ende Beschreibung === */
void f_08fed0(void)
{
  extern int sound_word;
  #pragma aux sound_word "d_1a9820"
  short roll;
  int state;
  unsigned short u;
  if (d_1a2880 <= 1) goto done;
  roll = f_1457e0(100);
  if (roll > d_1a2880) goto done;
  state = f_060760(0x1f41);
  if (state != 1) goto done;
  u = f_08fe30();
  { int sound = sound_word;
    f_147323((int)&d_1c2edc, 0x290024, u, 0x8000, sound, 0, 1); }
  f_0bf730(CH, 0x29000020);
  { int sound = sound_word;
    f_147323((int)&d_1c2edc, 0x290025, u, 0x8000, sound, 0, 1); }
  d_1a2880 = 0;
done:
  d_1a2880 = d_1a2880 + 2;
}
//@ f_08ff80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet im Schrittzyklus des zweiten Final-Dungeons vorgemerkte Folgeereignisse: Bei
 *   gesetztem d_1c107c schaltet sie auf den Feldern 0x6c bzw. 0x3ea die Durchgänge 0x1f41..0x1f44 frei
 *   (f_060740, f_0607e0), bei gesetztem d_1c1078 startet sie die Endsequenz f_08de20, und bei gesetztem d_1bdb28
 *   (aus f_08d430) spielt sie die Ankunftsmeldung 0x2900000a, die Animation 0x290004 und den Sturzschaden
 *   f_08f1c0 ab.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Zeiger d_1c107c, d_1c1078 und d_1bdb28 übergeben den auslösenden Helden aus
 *   vorangegangenen Aktionen oder Kartenwechseln.
 === Ende Beschreibung === */
int f_060740(int, int);
int f_039a80(int, int);
void f_08ff80()
{
  if (d_1c107c != 0) {
    SO m(d_1c349c, d_1c3870, d_1c3498);
    unsigned short u;
    int *pp;
    u = f_0dd480(d_1c0004);
    pp = m.p;
    pp[1] = d_1c107c;
    switch (u) {
    case 0x6c:
      f_0bf730(CH, 0x29000003);
      f_060740(0x1f41, 0);
      f_0607e0(0x1f41, 1);
      f_0607e0(0x1f42, 1);
      d_1bc940 = 1;
      break;
    case 0x3ea:
      f_0bf730(CH, 0x29000003);
      f_060740(0x1f42, 0);
      f_0607e0(0x1f43, 1);
      f_0607e0(0x1f44, 1);
      d_1bc940 = 1;
      d_1bdb44 = 1;
      break;
    }
    d_1c107c = 0;
  }
  if (d_1c1078 != 0) {
    d_1bc940 = 1;
    f_08de20(d_1c1078);
    d_1c1078 = 0;
  }
  if (d_1bdb28 != 0) {
    SO m2(d_1c349c, d_1c3870, d_1c3498);
    int *pp2 = m2.p;
    pp2[1] = d_1bdb28;
    f_0bf730(CH, 0x2900000a);
    f_060800(0x290004, 0, 0);
    f_039a80(d_1c0004, (int)f_08f1c0);
    d_1bdb28 = 0;
  }
}
//@ f_090120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt, solange das Ereignis d_1bdb44 noch nicht erledigt ist (d_1bdb44 == 0), die beiden
 *   Geräuscheffekte 0x290024 und 0x290025 in voller Lautstärke (0x7fff) zusammen mit der Meldung 0x29000020 ab.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Gesteuert wird die Bedingung über das Flag d_1bdb44.
 === Ende Beschreibung === */
void f_090120(void)
{
  int v;
  if (((d_1bdb44 == 0) ? 1 : 0)) {
    f_147323((int)&d_1c2edc, 0x290024, 0x7fff, 0x8000, (v = *(int *)&d_1a9820), 0, 1);
    f_0bf730(CH, 0x29000020);
    f_147323((int)&d_1c2edc, 0x290025, 0x7fff, 0x8000, (v = *(int *)&d_1a9820), 0, 1);
  }
}
//@ f_090190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die erste der neun möglichen Multiple-Choice-Fragen (0x2900005b) des großen
 *   Prüfungsrätsels (f_08fa70) und gibt 1 zurück, wenn der Spieler die richtige Antwortkombination (Antwort 2,
 *   danach Antwort 2 -> 0x29000064) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 bei richtiger Lösung bzw. 0 bei falscher
 *   Antwort zurück.
 * - Wichtige Variablen: Die Dialogauswahl erfolgt über f_0bf820 am Textkontext d_1c2c64.
 === Ende Beschreibung === */
int f_090190(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x2900005b, 3, 0x2900005c, 0x2900005d, 0x2900005e); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    f_0bf730(CH, 0x2900005f);
    break;
  case 2:
    do { u = f_0bf820(CH, 0x29000060, 2, 0x29000061, 0x29000062); } while (u == -1);
    switch ((unsigned short)u) {
    case 1:
      f_0bf730(CH, 0x29000063);
      break;
    case 2:
      r = 1;
      f_0bf730(CH, 0x29000064);
      break;
    }
    break;
  case 3:
    f_0bf730(CH, 0x29000065);
    break;
  }
  return r;
}

//@ f_090280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die zweite Rätselfrage (0x29000066) mit zweistufiger Antwortauswahl und gibt 1 zurück,
 *   wenn der Spieler zuerst Antwort 1 und danach Antwort 2 (0x2900006d) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Alle Frage- und Antworttexte stammen aus der Textgruppe 0x29000066..0x29000072.
 === Ende Beschreibung === */
int f_090280(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x29000066, 2, 0x29000067, 0x29000068); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x29000069, 2, 0x2900006a, 0x2900006b); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x2900006c); break;
    case 2: r = 1; f_0bf730(CH, 0x2900006d); break;
    }
    break;
  case 2:
    do { u = f_0bf820(CH, 0x2900006e, 2, 0x2900006f, 0x29000070); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x29000071); break;
    case 2: f_0bf730(CH, 0x29000072); break;
    }
    break;
  }
  return r;
}
//@ f_090390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die dritte Rätselfrage (0x29000073) und gibt 1 zurück, wenn der Spieler über Antwort 2
 *   entweder direkt Option 1 (0x2900007a) oder im Unterzweig 2 die Option 1 (0x2900007e) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x29000073..0x2900007f.
 === Ende Beschreibung === */
int f_090390(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x29000073, 2, 0x29000074, 0x29000075); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    f_0bf730(CH, 0x29000076);
    break;
  case 2:
    do { u = f_0bf820(CH, 0x29000077, 2, 0x29000078, 0x29000079); } while (u == -1);
    switch ((unsigned short)u) {
    case 1:
      r = 1;
      f_0bf730(CH, 0x2900007a);
      break;
    case 2:
      do { u = f_0bf820(CH, 0x2900007b, 2, 0x2900007c, 0x2900007d); } while (u == -1);
      switch ((unsigned short)u) {
      case 1:
        r = 1;
        f_0bf730(CH, 0x2900007e);
        break;
      case 2:
        f_0bf730(CH, 0x2900007f);
        break;
      }
      break;
    }
    break;
  }
  return r;
}
//@ f_0904a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die vierte Rätselfrage (0x29000080) und gibt 1 zurück, wenn der Spieler zuerst Antwort
 *   2 und in der Nachfrage Antwort 1 (0x29000088) auswählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x29000080..0x2900008a.
 === Ende Beschreibung === */
int f_0904a0(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x29000080, 3, 0x29000081, 0x29000082, 0x29000083); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    f_0bf730(CH, 0x29000084);
    break;
  case 2:
    do { u = f_0bf820(CH, 0x29000085, 2, 0x29000086, 0x29000087); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: r = 1; f_0bf730(CH, 0x29000088); break;
    case 2: f_0bf730(CH, 0x29000089); break;
    }
    break;
  case 3:
    f_0bf730(CH, 0x2900008a);
    break;
  }
  return r;
}
//@ f_090590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die fünfte Rätselfrage (0x2900008b) und gibt 1 zurück, wenn der Spieler entweder den
 *   Pfad 1 -> 1 oder den Pfad 3 -> 2 (0x29000092) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x2900008b..0x29000096.
 === Ende Beschreibung === */
int f_090590(void)
{
  int r = 0;
  short u;
  do { u = f_0bf820(CH, 0x2900008b, 3, 0x2900008c, 0x2900008d, 0x2900008e); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x2900008f, 2, 0x29000090, 0x29000091); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: r = 1; f_0bf730(CH, 0x29000092); break;
    case 2: f_0bf730(CH, 0x29000093); break;
    }
    break;
  case 2:
    f_0bf730(CH, 0x29000093);
    break;
  case 3:
    do { u = f_0bf820(CH, 0x29000094, 2, 0x29000095, 0x29000096); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x29000093); break;
    case 2: r = 1; f_0bf730(CH, 0x29000092); break;
    }
    break;
  }
  return r;
}
//@ f_090690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die sechste Rätselfrage (0x29000097) und gibt 1 zurück, wenn der Spieler zuerst Antwort
 *   1 und anschließend Antwort 2 (0x2900009e) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x29000097..0x2900009f.
 === Ende Beschreibung === */
int f_090690(void)
{
  int r = 0;
  short u;
  do { u = f_0bf820(CH, 0x29000097, 2, 0x29000098, 0x29000099); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x2900009a, 2, 0x2900009b, 0x2900009c); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x2900009d); f_0bf730(CH, 0x2900009f); break;
    case 2: r = 1; f_0bf730(CH, 0x2900009e); break;
    }
    break;
  case 2: f_0bf730(CH, 0x2900009f); break;
  }
  return r;
}
//@ f_090750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die siebte Rätselfrage (0x290000a0) und gibt 1 zurück, wenn der Spieler zuerst Antwort
 *   2 und danach Antwort 1 (0x290000ab) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x290000a0..0x290000ab.
 === Ende Beschreibung === */
int f_090750(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x290000a0, 2, 0x290000a1, 0x290000a2); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x290000a3, 2, 0x290000a4, 0x290000a5); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x290000a6); break;
    case 2: f_0bf730(CH, 0x290000a7); break;
    }
    break;
  case 2:
    do { u = f_0bf820(CH, 0x290000a8, 2, 0x290000a9, 0x290000aa); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x290000ab); r = 1; break;
    case 2: f_0bf730(CH, 0x290000a7); break;
    }
    break;
  }
  return r;
}
//@ f_090850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die achte Rätselfrage (0x290000ac) und gibt 1 zurück, wenn der Spieler zuerst Antwort 1
 *   und danach Antwort 1 (0x290000b2) wählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x290000ac..0x290000b3.
 === Ende Beschreibung === */
int f_090850(void)
{
  int r = 0;
  short u;
  do { u = f_0bf820(CH, 0x290000ac, 2, 0x290000ad, 0x290000ae); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x290000af, 2, 0x290000b0, 0x290000b1); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: r = 1; f_0bf730(CH, 0x290000b2); break;
    case 2: f_0bf730(CH, 0x290000b3); break;
    }
    break;
  case 2: f_0bf730(CH, 0x290000b3); break;
  }
  return r;
}
//@ f_090900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die neunte Rätselfrage (0x290000b4) und gibt 1 zurück, wenn der Spieler zuerst Antwort
 *   2 und danach Antwort 1 (0x290000c0) auswählt, sonst 0.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt 1 (richtig) oder 0 (falsch) zurück.
 * - Wichtige Variablen: Nutzt die Textkennungen 0x290000b4..0x290000c2.
 === Ende Beschreibung === */
int f_090900(void)
{
  int r = 0;
  short u = -1;
  do { u = f_0bf820(CH, 0x290000b4, 3, 0x290000b5, 0x290000b6, 0x290000b7); } while (u == -1);
  switch ((unsigned short)u) {
  case 1:
    do { u = f_0bf820(CH, 0x290000b8, 2, 0x290000b9, 0x290000ba); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x290000bb); break;
    case 2: f_0bf730(CH, 0x290000bc); break;
    }
    break;
  case 2:
    do { u = f_0bf820(CH, 0x290000bd, 2, 0x290000be, 0x290000bf); } while (u == -1);
    switch ((unsigned short)u) {
    case 1: f_0bf730(CH, 0x290000c0); r = 1; break;
    case 2: f_0bf730(CH, 0x290000c1); break;
    }
    break;
  case 3: f_0bf730(CH, 0x290000c2); break;
  }
  return r;
}
//@ f_090a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Überleitungstext 0x2900005a zwischen zwei Teilfragen des Prüfungsrätsels aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt das globale Textfenster d_1c2c64.
 === Ende Beschreibung === */
void f_090a40(void)
{
  f_0bf730(CH, 0x2900005a);
}
//@ f_090a60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Betreten des Ereignisfelds 0x44d (d_1bdb7c == 0) die Meldung 0x290000c5 an
 *   und setzt d_1bdb7c = 1.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb7c verhindert eine wiederholte Ausgabe.
 === Ende Beschreibung === */
void f_090a60(void)
{
  if (EQ(d_1bdb7c, 0)) {
    d_1bdb7c = 1;
    f_0bf730(CH, 0x290000c5);
  }
}
//@ f_090a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt das Ereignisfeld 0x44e im Allerheiligsten des Enddungeons: Sie zeigt je nach
 *   Endstatus (d_1bdb84) die Meldung 0x290000c6 oder 0x290000c7 an und startet, sobald die Vorbedingung d_1bdb80
 *   == 1 erfüllt ist, den finalen Entscheidungskampf Nr. 1 (VC3(object, 1, 0)), vergibt nach dem Sieg die
 *   Spielpunkte 0x21 (f_091f70(0x21)), trägt den Tagebucheintrag 0x803004a ein und setzt das Siegesflag d_1bdb84
 *   = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb84 = 1 markiert den endgültigen Sieg im Endkampf des Spiels.
 === Ende Beschreibung === */
void f_090a90(int p1)
{
  int f_0f2720_1(int);
  #pragma aux f_0f2720_1 "f_0f2720" parm [eax] modify exact [eax]
  SO o(d_1c349c, d_1c3870, d_1c3498);
  o.p[1] = f_038c40(d_1c0004);
  if (EQ(d_1bdb84, 1)) f_0bf730(CH, 0x290000c7);
  else f_0bf730(CH, 0x290000c6);
  int object = p1;
  if (EQ(d_1bdb84, 0) && EQ(d_1bdb80, 1)) {
    f_0f2720_1(7);
    if (VC3(object, 1, 0) == 0) {
      ((int(*)(int))f_0f2720)(0xd);
      d_1bdb84 = 1;
      f_091f70(0x21);
      f_057220((int)&d_1c2c00, 0x803004a, 0);
    }
  }
}
//@ f_090b70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt am Ereignisfeld 0x4b1 die Beschreibungsmeldung 0x290000c8 aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt das globale Textfenster d_1c2c64.
 === Ende Beschreibung === */
void f_090b70(void)
{
  f_0bf730(CH, 0x290000c8);
}

#undef CH
#undef EQ
#undef EQB
#undef NE
#undef VC1
#undef VC3
#undef WAIT
#undef d_1a2880
#undef d_1a2884
#undef d_1a28c8
#undef d_1a28ce
#undef d_1a28da
#undef d_1a9820
#undef d_1bc940
#undef d_1bdb24
#undef d_1bdb28
#undef d_1bdb2c
#undef d_1bdb30
#undef d_1bdb34
#undef d_1bdb38
#undef d_1bdb3c
#undef d_1bdb40
#undef d_1bdb44
#undef d_1bdb48
#undef d_1bdb4c
#undef d_1bdb50
#undef d_1bdb54
#undef d_1bdb58
#undef d_1bdb5c
#undef d_1bdb60
#undef d_1bdb64
#undef d_1bdb68
#undef d_1bdb6c
#undef d_1bdb70
#undef d_1bdb74
#undef d_1bdb7c
#undef d_1bdb80
#undef d_1bdb84
#undef d_1bfaec
#undef d_1c0004
#undef d_1c1078
#undef d_1c107c
#undef d_1c21a4
#undef d_1c27a8
#undef d_1c2c00

#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_032820
#undef f_033530
#undef f_036300
#undef f_038be0
#undef f_038c40
#undef f_038d70
#undef f_039320
#undef f_039660
#undef f_0397d0
#undef f_0398c0
#undef f_039a80
#undef f_039ac0
#undef f_039b00
#undef f_042380
#undef f_042a60
#undef f_043120
#undef f_043d40
#undef f_043d50
#undef f_044300
#undef f_044900
#undef f_044c90
#undef f_0453e0
#undef f_057220
#undef f_060230
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060800
#undef f_0609d0
#undef f_060a70
#undef f_069630
#undef f_069730
#undef f_0697c0
#undef f_08de20
#undef f_08f1c0
#undef f_091370
#undef f_091770
#undef f_091f70

#undef f_0bde40
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf820
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4a60
#undef f_0d4c80
#undef f_0d5040
#undef f_0d54f0
#undef f_0db9a0
#undef f_0dc020
#undef f_0dcb60
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd480
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de840
#undef f_0de880
#undef f_0f2720

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_113340
#undef f_113500
#undef f_125400
#undef f_1254a0
#undef f_145760
#undef f_1457e0
#undef f_147323
#undef f_149360
#undef f_149a14
#undef SO
#undef T14
#undef EQBF

// ===== Teil final2_t3 =====
#define d_1a28ce d_1a28ce_t3
#define d_1a28da d_1a28da_t3
#define d_1a9820 d_1a9820_t3
#define d_1bdb34 d_1bdb34_t3
#define d_1bdb38 d_1bdb38_t3
#define d_1bdb3c d_1bdb3c_t3
#define d_1bdb64 d_1bdb64_t3
#define d_1bdb68 d_1bdb68_t3
#define d_1bdb6c d_1bdb6c_t3
#define d_1bdb70 d_1bdb70_t3
#define d_1bdb80 d_1bdb80_t3
#define d_1bdb84 d_1bdb84_t3
#define d_1c0004 d_1c0004_t3
#define d_1c21a4 d_1c21a4_t3
#define d_1c27a8 d_1c27a8_t3
#define d_1c2c00 d_1c2c00_t3

#define d_1c2c64 d_1c2c64_t3
#define d_1c2edc d_1c2edc_t3
#define d_1c3498 d_1c3498_t3
#define d_1c349c d_1c349c_t3
#define d_1c3870 d_1c3870_t3
#define f_032820 f_032820_t3
#define f_033530 f_033530_t3
#define f_036300 f_036300_t3
#define f_038c40 f_038c40_t3
#define f_038d70 f_038d70_t3
#define f_039660 f_039660_t3
#define f_0398c0 f_0398c0_t3
#define f_039a80 f_039a80_t3
#define f_039ac0 f_039ac0_t3
#define f_042380 f_042380_t3
#define f_042a60 f_042a60_t3
#define f_043120 f_043120_t3
#define f_043d40 f_043d40_t3
#define f_043d50 f_043d50_t3
#define f_044900 f_044900_t3
#define f_044c90 f_044c90_t3
#define f_0453e0 f_0453e0_t3
#define f_057220 f_057220_t3
#define f_060230 f_060230_t3
#define f_0606a0 f_0606a0_t3
#define f_060800 f_060800_t3
#define f_060a70 f_060a70_t3
#define f_069630 f_069630_t3
#define f_069730 f_069730_t3
#define f_0697c0 f_0697c0_t3
#define f_091f70 f_091f70_t3

#define f_0bde40 f_0bde40_t3
#define f_0bf6f0 f_0bf6f0_t3
#define f_0bf730 f_0bf730_t3
#define f_0bf820 f_0bf820_t3
#define f_0bfa20 f_0bfa20_t3
#define f_0d4a60 f_0d4a60_t3
#define f_0d4c80 f_0d4c80_t3
#define f_0d5040 f_0d5040_t3
#define f_0db9a0 f_0db9a0_t3
#define f_0dc020 f_0dc020_t3
#define f_0dcb60 f_0dcb60_t3
#define f_0dcbb0 f_0dcbb0_t3
#define f_0dd750 f_0dd750_t3
#define f_0f2720 f_0f2720_t3

#define f_125400 f_125400_t3
#define f_1254a0 f_1254a0_t3
#define f_1457e0 f_1457e0_t3
#define f_149360 f_149360_t3
#define f_149a14 f_149a14_t3
#define SO SO_t3
#define T14 T14_t3
#define EQBF EQBF_t3
// P3 19/21 gleich (suche.py 28.10.2026, Basis final2_t3_P1.CPP)
// final2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x090B90-0x091B50 (Teil t3)




struct Obj { int f0; char *p[13]; short s38; Obj(void *a, void *b, void *c); ~Obj(); };   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
typedef short (*VF1)(int);
typedef short (*VF2)(int, int);
typedef short (*VF3)(int, int, int);
typedef short (*VF4)(int, int, int, int);
typedef unsigned short (*VF4U)(int, int, int, int);
#define VF(T, p) ((T)(**(int **)((p) + 8)))
short f_0db9a0(int p1);
#pragma aux f_0db9a0_t3 "f_0db9a0"
int f_038c40(int p1);
#pragma aux f_038c40_t3 "f_038c40"
int f_0bf730(int p1, int p2);
#pragma aux f_0bf730_t3 "f_0bf730"
int f_0dcb60(int p1, int p2);
#pragma aux f_0dcb60_t3 "f_0dcb60"
short f_091f70(int p1);
#pragma aux f_091f70_t3 "f_091f70"
int f_057220(int p1, int p2, int p3);
#pragma aux f_057220_t3 "f_057220"
int f_0f2720(int p1);
#pragma aux f_0f2720_t3 "f_0f2720"
int f_069730(int p1, int p2);
int f_069630(int p1, int p2);
#pragma aux f_069630_t3 "f_069630"
int f_060230(int p1);
#pragma aux f_060230_t3 "f_060230"
int f_0d4a60(int p1);
#pragma aux f_0d4a60_t3 "f_0d4a60"
short f_044900(int p1, int p2, int p3);
#pragma aux f_044900_t3 "f_044900"
short f_0d4c80(int p1);
#pragma aux f_0d4c80_t3 "f_0d4c80"
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
#pragma aux f_0d5040_t3 "f_0d5040"
signed char f_043120(int p1);
#pragma aux f_043120_t3 "f_043120"
int f_0dcbb0(int p1, int p2);
#pragma aux f_0dcbb0_t3 "f_0dcbb0"
unsigned short f_0bf6f0(int p1, int p2);
#pragma aux f_0bf6f0_t3 "f_0bf6f0"
short f_0398c0(int p1, int p2, int p3);
#pragma aux f_0398c0_t3 "f_0398c0"
int f_039a80(int p1, int p2);
#pragma aux f_039a80_t3 "f_039a80"
int f_060800(int p1, int p2, int p3);
#pragma aux f_060800_t3 "f_060800"
int f_1457e0(int p1);
#pragma aux f_1457e0_t3 "f_1457e0"
int f_0453e0(int p1, int p2, int p3);
#pragma aux f_0453e0_t3 "f_0453e0"
int f_038c40(int p1);
short f_042380(int p1);
#pragma aux f_042380_t3 "f_042380"
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
int f_0dd750(int p1, int p2);
#pragma aux f_0dd750_t3 "f_0dd750"
int f_039660(int p1, int p2);
#pragma aux f_039660_t3 "f_039660"
int f_149a14(int p1, int p2);
#pragma aux f_149a14_t3 "f_149a14"
int f_0606a0(int p1, int p2);
#pragma aux f_0606a0_t3 "f_0606a0"
int f_0bde40(int p1);
#pragma aux f_0bde40_t3 "f_0bde40"
short f_0bfa20(int,...);
#pragma aux f_0bfa20_t3 "f_0bfa20"

#pragma aux f_0fad20_t3 "f_0fad20"
short f_044c90(int p1, int p2, int p3);
#pragma aux f_044c90_t3 "f_044c90"
int f_039ac0(int p1, int p2);
#pragma aux f_039ac0_t3 "f_039ac0"

#pragma aux f_0a78f0_t3 "f_0a78f0"
short f_149360(int p1, int p2);
#pragma aux f_149360_t3 "f_149360"
short f_042a60(int p1, int p2);
int f_033530(int p1, int p2);
#pragma aux f_033530_t3 "f_033530"
int f_043d40(int p1);
#pragma aux f_043d40_t3 "f_043d40"
int f_043d50(int p1, int p2);
#pragma aux f_043d50_t3 "f_043d50"
int f_0697c0(int p1, int p2, int p3);
#pragma aux f_0697c0_t3 "f_0697c0"
int f_038d70(int p1, int p2);
#pragma aux f_038d70_t3 "f_038d70"
short f_032820(int p1, int p2, int p3);
#pragma aux f_032820_t3 "f_032820"
int f_036300(int p1, int p2, int p3);
#pragma aux f_036300_t3 "f_036300"
short f_0dc020(int p1, int p2);
#pragma aux f_0dc020_t3 "f_0dc020"
int f_060a70();
#pragma aux f_060a70_t3 "f_060a70"
short f_0bf820();
short f_0bf820(int,...);
int f_125400(int,int,int,int);
#pragma aux f_125400_t3 "f_125400"
int f_1254a0(int,int);
#pragma aux f_1254a0_t3 "f_1254a0"
short f_042a60(int);
extern signed char d_1bdb80, d_1bdb84, d_1bdb34, d_1bdb38, d_1bdb3c, d_1bdb68, d_1bdb6c, d_1bdb70, d_1bdb64;
#pragma aux d_1bdb34_t3 "d_1bdb34"
#pragma aux d_1bdb38_t3 "d_1bdb38"
#pragma aux d_1bdb3c_t3 "d_1bdb3c"
#pragma aux d_1bdb64_t3 "d_1bdb64"
#pragma aux d_1bdb68_t3 "d_1bdb68"
#pragma aux d_1bdb6c_t3 "d_1bdb6c"
#pragma aux d_1bdb70_t3 "d_1bdb70"
#pragma aux d_1bdb80_t3 "d_1bdb80"
#pragma aux d_1bdb84_t3 "d_1bdb84"
extern int d_1c0004, d_1c27a8;
#pragma aux d_1c0004_t3 "d_1c0004"
#pragma aux d_1c27a8_t3 "d_1c27a8"

extern short d_1a9820;
#pragma aux d_1a9820_t3 "d_1a9820"
extern short d_1c21a4;
#pragma aux d_1c21a4_t3 "d_1c21a4"
extern short d_1a28ce[];
#pragma aux d_1a28ce_t3 "d_1a28ce"
extern char d_1a28da[], d_1c2c64[], d_1c2c00[], d_1c2edc[], d_1c3498[], d_1c349c[], d_1c3870[];
#pragma aux d_1a28da_t3 "d_1a28da"
#pragma aux d_1c2c00_t3 "d_1c2c00"
#pragma aux d_1c2c64_t3 "d_1c2c64"
#pragma aux d_1c2edc_t3 "d_1c2edc"
#pragma aux d_1c3498_t3 "d_1c3498"
#pragma aux d_1c349c_t3 "d_1c349c"
#pragma aux d_1c3870_t3 "d_1c3870"
#define EQI(x,v) (((x)==(v))?1:0)
#define OBJ0(o) (*(int *)((o).p[0] + 4))
#define MSG(m) f_0bf730((int)d_1c2c64, m)

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_090b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst am Ereignisfeld 0x4b2 (sofern d_1bdb80 == 0) die erste Phase des Endkampfes (Kampf Nr.
 *   0x81) aus, zeigt zuvor je nach Gruppengröße (f_0db9a0 == 1) die Meldung 0x290000c9 oder 0x290000ca an und
 *   vergibt nach dem Sieg 100 Abenteuerpunkte (f_0dcb60), die Spielpunkte 0x20 (f_091f70(0x20)), den
 *   Tagebucheintrag 0x8030049 sowie das Flag d_1bdb80 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb80 = 1 schaltet den anschließenden Endkampf Nr. 1 in f_090a90 bzw.
 *   f_090c60 frei.
 === Ende Beschreibung === */
void f_090b90(int p1)
{
    if (EQB(d_1bdb80, 0)) {
        if (f_0db9a0(d_1c0004) == 1) {
            Obj obj(d_1c349c, d_1c3870, d_1c3498);
            OBJ0(obj) = f_038c40(d_1c0004);
            MSG(0x290000c9);
        } else {
            MSG(0x290000ca);
        }
        short s = VF(VF3, p1)(p1, 0x81, 0);
        if (s == 0) {
            f_0dcb60(d_1c0004, 100);
            f_091f70(0x20);
            f_057220((int)d_1c2c00, 0x8030049, 0);
            d_1bdb80 = 1;
        }
    }
}

//@ f_090c60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet am Ereignisfeld 0x515, sobald die erste Endkampfphase gewonnen ist (d_1bdb80 == 1 und
 *   d_1bdb84 == 0), den finalen Kampf Nr. 1, vergibt bei einem Sieg die Spielpunkte 0x21 (f_091f70(0x21)), trägt
 *   den Tagebucheintrag 0x803004a ein und setzt d_1bdb84 = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Vor und nach dem Kampf schaltet f_0f2720(7) bzw. f_0f2720(0xd) die zugehörigen
 *   Umgebungseffekte um.
 === Ende Beschreibung === */
void f_090c60(int p1)
{
    if (EQI(d_1bdb84, 0) && EQI(d_1bdb80, 1)) {
        f_0f2720(7);
        int t_99 = VF(VF3, p1)(p1, 1, 0);
        if (t_99 == 0) {
            f_0f2720(0xd);
            d_1bdb84 = 1;
            f_091f70(0x21);
            f_057220((int)d_1c2c00, 0x803004a, 0);
        }
    }
}

//@ f_090ce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Passt beim Initialisieren des zweiten Final-Dungeons die Gegneranzahl in der Begegnung 0x81
 *   (f_069730) an die tatsächliche Anzahl der Gruppenmitglieder (f_0db9a0) an (f_069630) und ruft anschließend
 *   die Basismethode f_060230 auf.
 * - Eingaben und Rückgabe: Die Methode erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Dadurch skaliert der Vor-Endkampf 0x81 dynamisch mit der Größe der Heldengruppe.
 === Ende Beschreibung === */
void f_090ce0(int p1)
{
    int q = f_069730(p1 + 2, 0x81);
    short s = f_0db9a0(d_1c0004);
    f_069630(q, s);
    f_060230(p1);
}

//@ f_090d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen lebenden Helden (p1), ob ihm eine um 3 Punkte erleichterte Probe auf die
 *   Eigenschaft 0 (*Mut*, f_044900(p1, 0, -3)) misslingt, und gibt bei Fehlschlag 1 zurück.
 * - Eingaben und Rückgabe: Die Prüfroutine erhält den Heldenzeiger p1 und gibt 1 bei verfehlter Probe zurück,
 *   sonst 0.
 * - Wichtige Variablen: Wird über f_0398c0 für alle Gruppenmitglieder in f_090de0 aufgerufen.
 === Ende Beschreibung === */
int f_090d20(int p1)
{
    int r = 0;
    if (f_0d4a60(p1)) {
        if (f_044900(p1, 0, -3) <= 0) r = 1;
    }
    return r;
}

//@ f_090d50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Belegt einen lebenden Helden (p1) nach dem Durchqueren des Hindernisses in f_090de0 für die
 *   Dauer 0xa8c mit temporären Abzügen von -5 auf Körperkraft (4), Attacke und Parade (f_0d5040) und vergibt 10
 *   Abenteuerpunkte an die Gruppe (f_0dcbb0).
 * - Eingaben und Rückgabe: Die Rückruffunktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_043120(p1) wird das aktuell geführte Kampftalent des Helden für den AT/PA-Malus
 *   bestimmt.
 === Ende Beschreibung === */
void f_090d50(int p1)
{
    if (f_0d4a60(p1)) {
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, 4, -5, 0);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -5, 2);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -5, 3);
        f_0dcbb0(d_1c0004, 10);
    }
}

//@ f_090de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an den Hindernisfeldern 0x67/0x72 (0x29000024), ob die Gruppe das Hindernis
 *   überwinden will; scheitert mindestens ein Held an der Mutprobe f_090d20, weicht die Gruppe zurück
 *   (0x29000025, f_060800), andernfalls gelingt der Durchbruch (0x29000026), d_1bdb34 wird auf 1 gesetzt und
 *   alle Helden erhalten die Erschöpfungsmali aus f_090d50.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 sowie die Rückzugs-Animationskennung
 *   p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb34 merkt vor, dass dieses Hindernis bereits überwunden wurde.
 === Ende Beschreibung === */
void f_090de0(int p1, int p2)
{
    Obj obj(d_1c349c, d_1c3870, d_1c3498);
    if (EQI(d_1bdb34, 0)) {
        if (((int (*)(int, int))f_0bf6f0)((int)d_1c2c64, 0x29000024) == 1) {
            if (f_0398c0(d_1c0004, (int)f_090d20, (int)&d_1c27a8) > 0) {
                OBJ0(obj) = d_1c27a8;
                MSG(0x29000025);
                f_060800(p2, 0, 0);
            } else {
                MSG(0x29000026);
                d_1bdb34 = 1;
                f_039a80(d_1c0004, (int)f_090d50);
            }
        } else {
            f_060800(p2, 0, 0);
        }
    }
}

//@ f_090eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen lebenden Helden (p1), ob ihm eine um 3 Punkte erschwerte Probe auf die
 *   negative Eigenschaft 0x0b (*Raumangst* / *Ekel*, f_044900(p1, 0xb, 3)) gelingt (der Held also der Angst
 *   nachgibt), und gibt in diesem Fall 1 zurück.
 * - Eingaben und Rückgabe: Die Prüfroutine erhält den Heldenzeiger p1 und gibt 1 zurück, wenn der Held vor dem
 *   Hindernis zurückschreckt, sonst 0.
 * - Wichtige Variablen: Wird über f_0398c0 in f_090fa0 aufgerufen.
 === Ende Beschreibung === */
int f_090eb0(int p1)
{
    int r = 0;
    if (f_0d4a60(p1)) {
        if (f_044900(p1, 0xb, 3) > 0) r = 1;
    }
    return r;
}

//@ f_090ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Belegt einen lebenden Helden (p1) nach dem Durchwaten des Hindernisses in f_090fa0 für die
 *   Dauer 0xa8c mit temporären Abzügen von -3 auf Körperkraft, Attacke und Parade (f_0d5040) und erhöht mit 10 %
 *   Wahrscheinlichkeit (f_1457e0(100) <= 10) dessen negativen Eigenschaftswert 0x0b permanent um 1 Punkt
 *   (f_0453e0).
 * - Eingaben und Rückgabe: Die Rückruffunktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die temporären Abzüge klingen nach 0xa8c Zeiteinheiten automatisch wieder ab.
 === Ende Beschreibung === */
void f_090ef0(int p1)
{
    if (f_0d4a60(p1) == 1) {
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, 4, -3, 0);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -3, 2);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -3, 3);
        short t_188 = f_1457e0(100);
        if (t_188 <= 10) f_0453e0(p1, 0xb, 1);
    }
}

//@ f_090fa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an den Hindernisfeldern 0x68/0x73 (0x29000027), prüft alle Helden über
 *   f_090eb0 und versetzt die Gruppe bei bestandener Überwindung unter Abspielen eines geschlechtsspezifischen
 *   Stöhngeräuschs (0x290026 bzw. 0x290027), Vergabe von 10 Abenteuerpunkten und Anwendung der Abzüge aus
 *   f_090ef0 auf das Zielfeld p3 (f_0dd750).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1, die Rückzugs-Animationskennung p2
 *   sowie die Zielkoordinate p3 (unsigned short) entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb38 wird nach erfolgreichem Durchqueren auf 1 gesetzt.
 === Ende Beschreibung === */
void f_090fa0(int p1, int p2, unsigned short p3)
{
    Obj m(d_1c349c, d_1c3870, d_1c3498);
    if (EQI(d_1bdb38, 0)) {
        if (((int (*)(int, int))f_0bf6f0)((int)d_1c2c64, 0x29000027) == 1) {
            if (f_0398c0(d_1c0004, (int)f_090eb0, (int)&d_1c27a8) > 0) {
                OBJ0(m) = d_1c27a8;
                MSG(0x29000028);
                f_060800(p2, 0, 0);
            } else {
                int c = (unsigned char)((signed char)f_042380(f_038c40(d_1c0004)) == 1);
                { int t_ = *(int *)&d_1a9820; f_147323((int)d_1c2edc, c + 0x290026, 0x7fff, 0x8000, t_, 0, 1); }
                MSG(0x29000029);
                d_1bdb38 = 1;
                f_039a80(d_1c0004, (int)f_090ef0);
                f_0dcbb0(d_1c0004, 10);
                f_0dd750(d_1c0004, p3);
            }
        } else {
            f_060800(p2, 0, 0);
        }
    }
}
//@ f_0910f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen lebenden Helden (p1), ob seine Probe auf die negative Eigenschaft 8
 *   (*Höhenangst* / *Totenangst*, f_044900(p1, 8, 3)) anspricht, und gibt in diesem Fall 1 zurück.
 * - Eingaben und Rückgabe: Die Prüfroutine erhält den Heldenzeiger p1 und gibt 1 zurück, wenn der Held
 *   blockiert, sonst 0.
 * - Wichtige Variablen: Wird über f_0398c0 in f_0911e0 für die gesamte Gruppe getestet.
 === Ende Beschreibung === */
int f_0910f0(int p1)
{
    int r = 0;
    if (f_0d4a60(p1)) {
        if (f_044900(p1, 8, 3) > 0) r = 1;
    }
    return r;
}

//@ f_091130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Belegt einen lebenden Helden (p1) analog zu f_090ef0 für die Dauer 0xa8c mit Abzügen von -3
 *   auf Körperkraft, Attacke und Parade (f_0d5040) und erhöht mit 10 % Wahrscheinlichkeit den negativen
 *   Eigenschaftswert 0x0b um 1 Punkt.
 * - Eingaben und Rückgabe: Die Rückruffunktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Wird in f_091280 über f_039a80 auf alle Gruppenmitglieder angewendet.
 === Ende Beschreibung === */
void f_091130(int p1)
{
    if (f_0d4a60(p1) == 1) {
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, 4, -3, 0);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -3, 2);
        f_0d5040(p1, f_0d4c80(p1), 0xa8c, f_043120(p1), -3, 3);
        short t_241 = f_1457e0(100);
        if (t_241 <= 10) f_0453e0(p1, 0xb, 1);
    }
}

//@ f_0911e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an den Feldern 0x69/0x74 (0x2900002a) und prüft über f_0910f0, ob ein Held
 *   vor dem Hindernis zurückweicht (0x2900002b, f_060800(p2, 0, 0)); nur wenn alle Helden standhalten, darf die
 *   Gruppe weiterziehen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 sowie die Rückzugs-Animationskennung
 *   p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Solange d_1bdb3c == 0 ist, wird die Angstprobe bei jedem Versuch erneut abgefragt.
 === Ende Beschreibung === */
void f_0911e0(int p1, int p2)
{
    Obj obj(d_1c349c, d_1c3870, d_1c3498);
    if (EQI(d_1bdb3c, 0)) {
        if (((int (*)(int, int))f_0bf6f0)((int)d_1c2c64, 0x2900002a) == 1) {
            if (f_0398c0(d_1c0004, (int)f_0910f0, (int)&d_1c27a8) > 0) {
                OBJ0(obj) = d_1c27a8;
                MSG(0x2900002b);
                f_060800(p2, 0, 0);
            }
        } else {
            f_060800(p2, 0, 0);
        }
    }
}

//@ f_091280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt am Feld 0x6e die Überwindung des Hindernisses aus f_0911e0 ab (d_1bdb3c == 0), spielt
 *   das geschlechtsspezifische Geräusch (0x290026/0x290027) und die Meldung 0x29000032 ab, wendet die
 *   Erschöpfungsmali aus f_091130 auf alle Helden an, vergibt 10 Abenteuerpunkte und schaltet den Kartenschalter
 *   0x75 um (f_149a14(0x75, 1)).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb3c wird auf 1 gesetzt, damit die Stelle danach frei passierbar bleibt.
 === Ende Beschreibung === */
void f_091280(void)
{
    Obj obj(d_1c349c, d_1c3870, d_1c3498);
    if (EQI(d_1bdb3c, 0)) {
        int q = f_039660(d_1c0004, 8);
        int c = (unsigned char)((signed char)f_042380(q) == 1);
        OBJ0(obj) = q;
        { int t_ = *(int *)&d_1a9820; f_147323((int)d_1c2edc, c + 0x290026, 0x7fff, 0x8000, t_, 0, 1); }
        MSG(0x29000032);
        d_1bdb3c = 1;
        f_039a80(d_1c0004, (int)f_091130);
        f_0dcbb0(d_1c0004, 10);
        f_149a14(0x75, 1);
    }
}

//@ f_091370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt an den Wachfeldern 0x1f5..0x1f8 (solange d_1bdb68 == 0 und d_1bdb6c == 0) das Bild
 *   0x290001 (Index 1) mit drei Handlungsoptionen (0x2900003f..0x29000042) an: Option 1 startet den
 *   Schleichversuch (d_1bdb6c = 1), Option 2 löst sofort den Kampf Nr. 0x4f aus (und setzt bei Sieg d_1bdb68 =
 *   1), und Option 3 zieht die Gruppe zurück (f_060800(p2, 0, 0)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 sowie die Rückzugs-Animationskennung
 *   p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: d_1bdb68 speichert, ob die Wache 0x4f bereits besiegt wurde, und d_1bdb6c zählt die
 *   Schritte beim Vorbeischleichen.
 === Ende Beschreibung === */
void f_091370(int p1, int p2)
{
    if (EQI(d_1bdb68, 0)) {
        int q;
        short s;
        if (!EQI(d_1bdb6c, 0)) return;
        q = f_0606a0(0x290001, 1);
        f_0bde40((int)d_1c2c64);
        s = f_0bfa20((int)d_1c2c64, q, 0, 0x2900003f, 3, 0x29000040, 0x29000041, 0x29000042);
        switch (s) {
        case 1:
            d_1bdb6c = 1;
            break;
        case 2:
            if (VF(VF3, p1)(p1, 0x4f, 0) == 0) {
                d_1bdb68 = 1;
                d_1bdb6c = 0;
            }
            break;
        case -1:
        case 3:
            f_060800(p2, 0, 0);
            break;
        }
        if (q) operator delete((void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))));
        p2 = 0;
    }
}

//@ f_091460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen lebenden Helden (p1), ob ihm beim Vorbeischleichen in f_0914a0 eine Probe auf
 *   das Talent 0x0d (*Schleichen*, f_044c90) mit dem vom Schrittzähler d_1bdb6c - 2 abhängigen Zuschlag
 *   misslingt.
 * - Eingaben und Rückgabe: Die Prüfroutine erhält den Heldenzeiger p1 und gibt 1 bei verfehlter Schleichprobe
 *   zurück, sonst 0.
 * - Wichtige Variablen: Mit jedem weiteren Schritt (d_1bdb6c) steigt die Erschwernis der Schleichprobe an.
 === Ende Beschreibung === */
int f_091460(int p1)
{
    int r = 0;
    if (f_0d4a60(p1)) {
        short t = (signed char)(d_1bdb6c - 2);
        if (f_044c90(p1, 0xd, (signed char)t) <= 0) r = 1;
    }
    return r;
}

//@ f_0914a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Überwacht am Feld 0x1f9 das Vorbeischleichen an der Wache 0x4f: Beim allerersten Betreten
 *   (d_1bdb70 == 0) erscheint der Warnhinweis 0x29000044, danach wird bei jedem Schritt d_1bdb6c erhöht und über
 *   f_091460 geprüft, ob ein Held entdeckt wird (0x29000043) und dadurch den Kampf 0x4f auslöst.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Gewinnt die Gruppe den ausgelösten Kampf 0x4f, wird d_1bdb68 = 1 gesetzt und d_1bdb6c
 *   auf 0 zurückgestellt.
 === Ende Beschreibung === */
void f_0914a0(int p1)
{
    if (EQI(d_1bdb70, 0)) {
        d_1bdb70 = 1;
        MSG(0x29000044);
    } else if (EQI(d_1bdb68, 0)) {
        int q;
        d_1bdb6c = d_1bdb6c + 1;
        q = f_039ac0(d_1c0004, (int)f_091460);
        if (q != 0) {
            Obj obj(d_1c349c, d_1c3870, d_1c3498);
            OBJ0(obj) = q;
            MSG(0x29000043);
            if (VF(VF3, p1)(p1, 0x4f, 0) == 0) {
                d_1bdb68 = 1;
                d_1bdb6c = 0;
            }
        }
    }
}

//@ f_091580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein Gegenstand mit der Objektkennung p2 entweder als unzerstörbarer Questgegenstand
 *   markiert ist (f_0a78f0() != 0) oder in der Ausnahmeliste d_1a28da steht (f_149360 != -1), sodass er von der
 *   Säure-/Schleimgrube nicht zerfressen wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt einen ungenutzten Parameter p1 sowie die Gegenstands-ID p2
 *   entgegen und gibt 1 zurück, wenn der Gegenstand geschützt ist, sonst 0.
 * - Wichtige Variablen: Die Tabelle d_1a28da listet sämtliche säurefesten Gegenstands-IDs auf.
 === Ende Beschreibung === */
int f_091580(int p1, short p2)
{
    int r = 0;
    if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a78f0() != 0) r = 1;
    else if (f_149360(p2, (int)d_1a28da) != -1) r = 1;
    return r;
}

//@ f_0915c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle 31 Ausrüstungs- und Rucksackplätze (0..30) eines Helden (p2) und zerstört
 *   sämtliche Gegenstände (f_033530), die weder magisch/questgeschützt (f_0a78f0) noch in der Ausnahmeliste
 *   d_1a28da enthalten sind, spielt bei mindestens einem zerstörten Gegenstand das Zischgeräusch 0x290028 und
 *   die Meldung 0x2900004f ab (sonst 0x29000050).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kontextzeiger p1 sowie den Heldenzeiger p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Über f_042a60(p2, i) wird die Gegenstands-ID jedes Inventarslots 0..30 abgefragt.
 === Ende Beschreibung === */
void f_0915c0(int p1, int p2)
{
    short i;
    int fl = 0;
    for (i = 0; i < 0x1f; i++) {
        short s = f_042a60(p2, i);
        if (s > 0) {
            if (!f_091580(p1, s)) {
                int old = fl;
                f_033530(p2, i);
                if (old == 0) fl = 1;
            }
        }
    }
    {
        Obj obj(d_1c349c, d_1c3870, d_1c3498);
        OBJ0(obj) = p2;
        if (fl == 1) {
            int snd = *(int *)&d_1a9820;
            f_147323((int)d_1c2edc, 0x290028, 0x7fff, 0x8000, snd, 0, 1);
            MSG(0x2900004f);
        } else {
            MSG(0x29000050);
        }
    }
}

//@ f_0916b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wendet auf einen Helden (p2) die Ausrüstungszerstörung f_0915c0 an und gewährt ihm zusätzlich,
 *   sofern er diesen Bonus noch nicht erhalten hat (f_043d40(p2) == 0), die Meldung 0x29000051 sowie eine
 *   permanente Erhöhung der Eigenschaft 2 (*Charisma* / *Gewandtheit*, f_0453e0(p2, 2, 1)) samt Setzen des
 *   Schutzflags f_043d50(p2, 1).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Kontextzeiger p1 und den Heldenzeiger p2 entgegen und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Heldenflag f_043d40/f_043d50 verhindert, dass derselbe Held den Eigenschaftsbonus
 *   mehrfach erhält.
 === Ende Beschreibung === */
void f_0916b0(int p1, int p2)
{
    Obj obj(d_1c349c, d_1c3870, d_1c3498);
    OBJ0(obj) = p2;
    f_0915c0(p1, p2);
    if (f_043d40(p2) == 0) {
        MSG(0x29000051);
        f_043d50(p2, 1);
        f_0453e0(p2, 2, 1);
    }
}

//@ f_091730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Deaktiviert in einer Schleife über die sechs Einträge der Tabelle d_1a28ce die zugehörigen
 *   Gegner- oder Ereignisgruppen (f_0697c0(p1 + 2, d_1a28ce[k], 0)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1a28ce enthält die 6 Gruppen-Kennungen der Säure-/Wachbegegnungen.
 === Ende Beschreibung === */
void f_091730(int p1)
{
    short i = 0;
    do {
        int k = i;
        i = i + 1;
        f_0697c0(p1 + 2, d_1a28ce[k], 0);
    } while (i < (short)6);
}

struct Frame { char data[120]; Frame(const char *a, const char *b, const char *c) { f_125400((int)this, (int)a, (int)b, (int)c); } ~Frame(); };   // ~Frame = f_1254a0 extern (sonst COMDAT $dt:Frame, gibt es im Original nicht)
//@ f_091770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert an den Feldern 0x25a/0x25b das Eintauchen eines Gegenstands (Option 1) oder eines
 *   ganzen Helden (Option 2) in das Säure-/Verwandlungsbecken (0x29000045): Beim Testen eines einzelnen
 *   Gegenstands zerfällt ein ungeschütztes Stück unter Zischen (0x290028) und kann den Kampf 0x50 auslösen;
 *   steigt ein Held selbst hinein, wird seine ungeschützte Ausrüstung über f_0915c0 aufgelöst, er erhält den
 *   Bonus (f_0453e0) und muss bei d_1bdb64 == 0 allein den Kampf aus d_1a28ce[index] bestehen (Tagebucheintrag
 *   0x8030047).
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 sowie die drei
 *   Bewegungs-/Animationskennungen p2, p3 und p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb64 merkt vor, ob der zugehörige Becken-Kampf bereits gewonnen wurde.
 === Ende Beschreibung === */
void f_091770(int p1, int p2, int p3, int p4)
{
    Frame frame(d_1c349c, d_1c3870, d_1c3498);
    switch (f_0bf820((int)d_1c2c64, 0x29000045, 3,
                     0x29000046, 0x29000047, 0x29000048)) {
    case 1: {
        int stream = f_038d70(d_1c0004, 0x29000049);
        OBJ0((*(Obj *)&frame)) = stream;
        if (stream == 0) break;
        short status = f_032820(stream, 0x2900004a, 1);
        if ((int)status != -1) {
          short index = f_042a60(stream, status);
          {
            if (f_091580(p1, index) == 1) {
                    OBJ0((*(Obj *)&frame)) = stream;
                    *(int *)(((Obj *)&frame)->p[2] + 4) = (*(int **)&d_1c2c40)[index];
                    *(short *)(((Obj *)&frame)->p[7] + 2) = 1;
                    MSG(0x2900004b);
                    break;
            }
          }
          if (f_036300(stream, status, 1) == 1) {
                    int format;
                    f_147323((int)d_1c2edc, 0x290028, 0x7fff, 0x8000,
                             (format = *(int *)&d_1a9820), 0, 1);
                    OBJ0((*(Obj *)&frame)) = stream;
                    *(int *)(((Obj *)&frame)->p[2] + 4) = (*(int **)&d_1c2c40)[index];
                    *(short *)(((Obj *)&frame)->p[7] + 2) = 1;
                    MSG(0x2900004c);
                    if (EQ(d_1bdb64, 0)) {
                        MSG(0x2900004d);
                        if (VF(VF3, p1)(p1, 0x50, 0) == 0) {
                            d_1bdb64 = 1;
                        }
                    }
          }
        }
        break;
    }
    case 2: {
        int stream = f_038d70(d_1c0004, 0x2900004e);
        if (stream == 0) break;
        f_060800(p2, 0, 0);
        {
            f_125400((int)&(*(Obj *)(frame.data + 60)),
                     (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
            OBJ0((*(Obj *)(frame.data + 60))) = stream;
            f_0915c0(p1, stream);
            if (f_043d40(stream) == 0) {
                    MSG(0x29000051);
                    f_043d50(stream, 1);
                    f_0453e0(stream, 2, 1);
            }
            f_1254a0((int)&(*(Obj *)(frame.data + 60)), 0);
        }
        if (EQI(d_1bdb64, 0)) {
            short index = f_0dc020(d_1c0004, stream);
            OBJ0((*(Obj *)&frame)) = stream;
            MSG(0x29000052);
            short selection = ((short (*)(int, int, int))
                (**(int **)(p1 + 8)))(p1, d_1a28ce[index], 0);
            switch (selection) {
            case 0: {
                f_060a70();
                short i = 0;
                do {
                    short entry = i;
                    i = i + 1;
                    f_0697c0(p1 + 2, d_1a28ce[entry], 0);
                } while (i < (short)6);
                f_060800((*&p3), 0, 0);
                f_057220((int)d_1c2c00, 0x8030047, 0);
                d_1bdb64 = 1;
                break;
            }
            case 1:
            case 2:
            case 3: {
                f_060a70();
                short saved = d_1c21a4;
                d_1c21a4 = 0;
                f_060800(p4, 0, 0);
                if (saved != (short)4 && (selection == 2 || selection == 1))
                    MSG(0x29000053);
                d_1c21a4 = saved;
                break;
            }
            default:
                break;
            }
        } else {
            f_060800(p3, 0, 0);
        }
        break;
    }
    case -1:
    case 0:
    case 3:
    default:
        break;
    }
}

#undef EQ
#undef EQB
#undef EQI
#undef MSG
#undef OBJ0
#undef VF
#undef d_1a28ce
#undef d_1a28da
#undef d_1a9820
#undef d_1bdb34
#undef d_1bdb38
#undef d_1bdb3c
#undef d_1bdb64
#undef d_1bdb68
#undef d_1bdb6c
#undef d_1bdb70
#undef d_1bdb80
#undef d_1bdb84
#undef d_1c0004
#undef d_1c21a4
#undef d_1c27a8
#undef d_1c2c00

#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_032820
#undef f_033530
#undef f_036300
#undef f_038c40
#undef f_038d70
#undef f_039660
#undef f_0398c0
#undef f_039a80
#undef f_039ac0
#undef f_042380
#undef f_042a60
#undef f_043120
#undef f_043d40
#undef f_043d50
#undef f_044900
#undef f_044c90
#undef f_0453e0
#undef f_057220
#undef f_060230
#undef f_0606a0
#undef f_060800
#undef f_060a70
#undef f_069630
#undef f_069730
#undef f_0697c0
#undef f_091f70

#undef f_0bde40
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf820
#undef f_0bfa20
#undef f_0d4a60
#undef f_0d4c80
#undef f_0d5040
#undef f_0db9a0
#undef f_0dc020
#undef f_0dcb60
#undef f_0dcbb0
#undef f_0dd750
#undef f_0f2720

#undef f_125400
#undef f_1254a0
#undef f_1457e0
#undef f_149360
#undef f_149a14
#undef SO
#undef T14
#undef EQBF

