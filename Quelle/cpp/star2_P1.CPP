/* === Beschreibung (Katalog) ===
 * Einheit star2 (0x118a50 - 0x11a930)
 *
 * Überblick
 * Diese Einheit implementiert die zweite Ebene des Bienenstocks (star2.cpp, Dungeon-ID 8). Sie richtet beim
 * Betreten der Ebene die Wabentore und Hindernisse ein, verteilt sämtliche Raumereignisse und steuert die Kämpfe
 * gegen die Wächter-Schwärme, das Aufbrechen verklebter Durchgänge sowie spezielle Rätsel- und Beutekammern.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// star2 (Schatten ueber Riva) - GANZES Linkermodul 0x118A50-0x11A930 inkl. COMDAT-Schwanz (Forscher 840, 30.10.2026)
// Erzeugt mit comdat/840/bau_modul.py aus: star2_t1(p3), star2_t2(p3), gz_11a880(p3)
#include <string.h>
#include <math.h>
struct B115630 { char pad[8]; B115630(int k); virtual ~B115630(); };   // Basis: ctor f_115630, dtor f_115640
// --- COMDAT-Schwanz (hinter dem $dt)
inline int f_11a920(void)
{
    return 0;
}

// ===== Teil star2_t1 (p3, 118a50-11a020) =====
#define d_1a7c40 d_1a7c40_k0
#define d_1c0004 d_1c0004_k0
#define d_1c09c4 d_1c09c4_k0
#define d_1c09cc d_1c09cc_k0
#define d_1c09e8 d_1c09e8_k0
#define d_1c0a00 d_1c0a00_k0
#define d_1c0a04 d_1c0a04_k0
#define d_1c212a d_1c212a_k0
#define d_1c212c d_1c212c_k0
#define d_1c2c00 d_1c2c00_k0
#define d_1c2c64 d_1c2c64_k0
#define d_1c3498 d_1c3498_k0
#define d_1c349c d_1c349c_k0
#define d_1c3870 d_1c3870_k0
#define f_0104b0 f_0104b0_k0
#define f_010590 f_010590_k0
#define f_038c40 f_038c40_k0
#define f_039040 f_039040_k0
#define f_039580 f_039580_k0
#define f_042a60 f_042a60_k0
#define f_057220 f_057220_k0
#define f_0606a0 f_0606a0_k0
#define f_060740 f_060740_k0
#define f_060770 f_060770_k0
#define f_060800 f_060800_k0
#define f_060a70 f_060a70_k0
#define f_091f70 f_091f70_k0
#define f_0bf680 f_0bf680_k0
#define f_0bf6c0 f_0bf6c0_k0
#define f_0bf6f0 f_0bf6f0_k0
#define f_0bf730 f_0bf730_k0
#define f_0bf980 f_0bf980_k0
#define f_0bfa20 f_0bfa20_k0
#define f_0d4aa0 f_0d4aa0_k0
#define f_0db9a0 f_0db9a0_k0
#define f_0dcbb0 f_0dcbb0_k0
#define f_0dd750 f_0dd750_k0

#define f_1142c0 f_1142c0_k0
#define f_114340 f_114340_k0
#define f_1155d0 f_1155d0_k0
#define f_115630 f_115630_k0
#define f_11a020 f_11a020_k0
#define f_11a320 f_11a320_k0
#define f_11a6e0 f_11a6e0_k0
#define f_11a620 f_11a620_k0
#define f_11a600 f_11a600_k0
#define f_11a5e0 f_11a5e0_k0
#define f_11a650 f_11a650_k0
#define f_11a5c0 f_11a5c0_k0
#define f_125400 f_125400_k0
#define f_1254a0 f_1254a0_k0
#define OB OB_k0
// P3 29/30 gleich (suche.py 29.10.2026, Basis star2_t1_P1.CPP)
// star2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x118A50-0x11A880
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039580(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf980();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_1142c0(int p1, int p2);                           // reg edx stapel 0
int f_114340(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_1155d0(int p1, int p2);                           // reg edx stapel 0
int f_115620();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a7c40[];           // Text 0x1A7C40
// --- eigene Funktionen (42), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
short f_0366e0(int p1, int p2, int p3, int p4);
int f_060740(int p1, int p2);
int f_112e70(int p1, int p2);
int f_115630(int p1, int p2);
int f_112df0(int p1, int p2, int p3, int p4);
void f_11a020(int p1);
void f_11a320(int p1);
void f_11a6e0(int p1, int p2);
void f_11a620(void); void f_11a600(void); void f_11a5e0(void); void f_11a650(void); void f_11a5c0(void); void f_11a500(void);
void f_118a50(void); void f_118e50(void); void f_118e60(int p1); void f_118e80(int p1);
int f_118eb0(int p1, unsigned short p2);
void f_119810(void); void f_119840(void); void f_1198c0(void); void f_1199a0(void); void f_1199d0(void); void f_1199f0(void);
void f_119aa0(void); void f_119ac0(void); void f_119af0(int p1); void f_119b00(int p1); void f_119b10(void); void f_119b30(void);
void f_119ba0(void); void f_119bc0(void); void f_119ca0(void); void f_119d50(int p1); void f_119d60(int p1); void f_119d70(void);
void f_119d90(void); void f_119e20(void); void f_119eb0(void); void f_119f00(void); int f_119f80(void); void f_119fe0(void);
struct OB { int a, b, c; char pad[48]; };
extern int d_1bb98c; extern int d_1c0a08; extern int d_1c0004; extern int d_1c2c64; extern int d_1c2c00;
extern int d_1c349c; extern int d_1c3870; extern int d_1c3498;
extern int *d_1c212c; extern short d_1c212a;
#define P ((int)&d_1c2c64)
#define EQM(x,v) (((x)==(v))?1:0)
#define OBJ(o) f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498)
#define NEWC(var, line, id) int t_ = (int)operator new(0x14, mark(d_1a7c40, line)); int var = (t_ != 0) ? f_112df0(t_, id, 0, 0) : t_;
extern signed char d_1c09c4; extern short d_1c09c5;
extern signed char d_1c09c8; extern short d_1c09c9;
extern signed char d_1c09cc; extern short d_1c09cd;
extern signed char d_1c09d0; extern short d_1c09d1;
extern signed char d_1c09d4; extern short d_1c09d5;
extern signed char d_1c09d8; extern short d_1c09d9;
extern signed char d_1c09dc; extern short d_1c09dd;
extern signed char d_1c09e0; extern short d_1c09e1;
extern signed char d_1c09e4; extern short d_1c09e5;
extern signed char d_1c09e8; extern short d_1c09e9;
extern signed char d_1c09ec; extern short d_1c09ed;
extern signed char d_1c09f0; extern short d_1c09f1;
extern signed char d_1c09f4; extern short d_1c09f5;
extern signed char d_1c09f8; extern short d_1c09f9;
extern signed char d_1c09fc; extern short d_1c09fd;
extern signed char d_1c0a00; extern short d_1c0a01;
extern signed char d_1c0a04; extern short d_1c0a05;
typedef void (*StarCallback493)(void);
extern StarCallback493 d_1a7caa;
extern int d_1a7cae;
extern int d_1a7cb2;
extern int d_1a7cb6;
extern int d_1a7cba;
extern int d_1a7cbe;
extern StarCallback493 d_1a7ccc;
extern int d_1a7cd0;
extern int d_1a7cd4;
extern StarCallback493 d_1a7cd8;
extern int d_1a7cdc;
extern int d_1a7ce0;
extern StarCallback493 d_1a7cee;
extern int d_1a7cf2;
extern int d_1a7cf6;
extern int d_1a7cfa;
extern int d_1a7cfe;
extern int d_1a7d02;
extern StarCallback493 d_1a7d10;
extern int d_1a7d14;
extern int d_1a7d18;
extern int d_1a7d1c;
extern int d_1a7d20;
extern int d_1a7d24;
extern StarCallback493 d_1a7d32;
extern int d_1a7d36;
extern int d_1a7d3a;
extern int d_1a7d3e;
extern int d_1a7d42;
extern int d_1a7d46;
extern int d_1a7d54;
extern int d_1a7d58;
extern int d_1a7d5c;
extern int d_1a7d60;
extern int d_1a7d64;
extern int d_1a7d68;
//@ f_118a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Initialisiert beim Betreten der zweiten Bienenstock-Ebene alle Raum-, Tür- und Hinderniszustände auf
 *   der 3D-Karte anhand der gespeicherten Fortschrittsflags.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
// Watcom 10.6: ein nichtvirtueller Methodenzeiger belegt 12 Bytes;
// Original: zwei Zeigergruppen aus Adresse und zwei Null-DWORDs.
struct StarMember492 { void f_11a500(); void f_11a5c0(); void f_11a650(); void f_11a5e0(); void f_11a600(); void f_11a620(); };
typedef void (StarMember492::*StarMethod492)();
struct StarCallbackInit493 { StarMethod492 primary,secondary; void init(StarMethod492 p,StarMethod492 q) {primary=p; secondary=q;} };
typedef char StarMethodSize492[(sizeof(StarMethod492)==12 && sizeof(StarCallbackInit493)==24)?1:-1];
extern StarCallbackInit493 callback493_0;
#pragma aux callback493_0 "d_1a7caa"
extern StarCallbackInit493 callback493_1;
#pragma aux callback493_1 "d_1a7ccc"
extern StarCallbackInit493 callback493_2;
#pragma aux callback493_2 "d_1a7cee"
extern StarCallbackInit493 callback493_3;
#pragma aux callback493_3 "d_1a7d10"
extern StarCallbackInit493 callback493_4;
#pragma aux callback493_4 "d_1a7d32"
extern StarCallbackInit493 callback493_5;
#pragma aux callback493_5 "d_1a7d54"
struct R118a50 { char v; short id; };
inline void put118a50(R118a50 *p, short k, short v, short &n, int * &t)
{ p->id = k; p->v = v; t[n] = (int)p; n++; }
inline void first118a50(R118a50 *p, short k, signed char v, short &n, int * &t)
{ p->v = v; p->id = k; t[n] = (int)p; n++; }
struct RK700_118a50;
struct OK700_118a50 {signed char flag;short number;char pad;OK700_118a50 *init(RK700_118a50&r,short id,signed char f);};
struct RK700_118a50 {short count;OK700_118a50**list;void append(OK700_118a50*o){list[count]=o;count++;}};
inline OK700_118a50*OK700_118a50::init(RK700_118a50&r,short id,signed char f){flag=f;number=id;r.append(this);return this;}
extern RK700_118a50 regK700_118a50;
#pragma aux regK700_118a50 "d_1c212a"
extern OK700_118a50 obK700_118a50_1c09c4;
#pragma aux obK700_118a50_1c09c4 "d_1c09c4"
extern OK700_118a50 obK700_118a50_1c09c8;
#pragma aux obK700_118a50_1c09c8 "d_1c09c8"
extern OK700_118a50 obK700_118a50_1c09cc;
#pragma aux obK700_118a50_1c09cc "d_1c09cc"
extern OK700_118a50 obK700_118a50_1c09d0;
#pragma aux obK700_118a50_1c09d0 "d_1c09d0"
extern OK700_118a50 obK700_118a50_1c09d4;
#pragma aux obK700_118a50_1c09d4 "d_1c09d4"
extern OK700_118a50 obK700_118a50_1c09d8;
#pragma aux obK700_118a50_1c09d8 "d_1c09d8"
extern OK700_118a50 obK700_118a50_1c09dc;
#pragma aux obK700_118a50_1c09dc "d_1c09dc"
extern OK700_118a50 obK700_118a50_1c09e0;
#pragma aux obK700_118a50_1c09e0 "d_1c09e0"
extern OK700_118a50 obK700_118a50_1c09e4;
#pragma aux obK700_118a50_1c09e4 "d_1c09e4"
extern OK700_118a50 obK700_118a50_1c09e8;
#pragma aux obK700_118a50_1c09e8 "d_1c09e8"
extern OK700_118a50 obK700_118a50_1c09ec;
#pragma aux obK700_118a50_1c09ec "d_1c09ec"
extern OK700_118a50 obK700_118a50_1c09f0;
#pragma aux obK700_118a50_1c09f0 "d_1c09f0"
extern OK700_118a50 obK700_118a50_1c09f4;
#pragma aux obK700_118a50_1c09f4 "d_1c09f4"
extern OK700_118a50 obK700_118a50_1c09f8;
#pragma aux obK700_118a50_1c09f8 "d_1c09f8"
extern OK700_118a50 obK700_118a50_1c09fc;
#pragma aux obK700_118a50_1c09fc "d_1c09fc"
extern OK700_118a50 obK700_118a50_1c0a00;
#pragma aux obK700_118a50_1c0a00 "d_1c0a00"
extern OK700_118a50 obK700_118a50_1c0a04;
#pragma aux obK700_118a50_1c0a04 "d_1c0a04"
void f_118a50(void){
obK700_118a50_1c09c4.init(regK700_118a50,0xfb,0);
obK700_118a50_1c09c8.init(regK700_118a50,0xfc,0);
obK700_118a50_1c09cc.init(regK700_118a50,0xfd,0);
obK700_118a50_1c09d0.init(regK700_118a50,0xfe,0);
obK700_118a50_1c09d4.init(regK700_118a50,0xff,0);
obK700_118a50_1c09d8.init(regK700_118a50,0x100,0);
obK700_118a50_1c09dc.init(regK700_118a50,0x101,0);
obK700_118a50_1c09e0.init(regK700_118a50,0x102,0);
obK700_118a50_1c09e4.init(regK700_118a50,0x103,0);
obK700_118a50_1c09e8.init(regK700_118a50,0x104,0);
obK700_118a50_1c09ec.init(regK700_118a50,0x105,0);
obK700_118a50_1c09f0.init(regK700_118a50,0x106,0);
obK700_118a50_1c09f4.init(regK700_118a50,0x107,0);
obK700_118a50_1c09f8.init(regK700_118a50,0x108,0);
obK700_118a50_1c09fc.init(regK700_118a50,0x109,0);
obK700_118a50_1c0a00.init(regK700_118a50,0x10a,0);
obK700_118a50_1c0a04.init(regK700_118a50,0x10b,0);
    callback493_0.primary=&StarMember492::f_11a500;
    callback493_0.secondary=0;
    callback493_1.primary=&StarMember492::f_11a5c0;
    callback493_1.secondary=&StarMember492::f_11a650;
    callback493_2.primary=&StarMember492::f_11a5e0;
    callback493_2.secondary=0;
    callback493_3.primary=&StarMember492::f_11a600;
    callback493_3.secondary=0;
    callback493_4.primary=&StarMember492::f_11a620;
    callback493_4.secondary=0;
    callback493_5.primary=0;
    callback493_5.secondary=0;
    (void)f_11a920;   // erzeugt die COMDATs des Schwanzes (ohne Verweis im EXE)
}
//@ f_118e50
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt das globale Auslöseflag d_1c0a08 = 1, damit beim unmittelbaren Betreten der zweiten
 *   Bienenstock-Ebene (f_118e80) die Eingangssequenz f_11a320 abgespielt wird.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0a08 (Flag für die Eingangssequenz von star2).
 === Ende Beschreibung === */
void f_118e50(void)
{
    d_1c0a08 = 1;
}
struct X118e60 : B115630 { X118e60(); virtual ~X118e60(){ } };   // inline-virtueller Destruktor -> COMDAT $dt:X118e60 = f_11a880
//@ f_118e60
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Verteiler der zweiten Bienenstock-Ebene (star2), der anhand des Ereigniscodes (p2)
 *   die zugehörigen Raumaktionen, Kämpfe, Beutecontainer oder Ebenenübergänge aufruft.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis behandelt wurde, andernfalls 0.
 === Ende Beschreibung === */
X118e60::X118e60() : B115630(8) { }   // Konstruktor, setzt vtable; erzeugt $dt:X118e60 als COMDAT am Modulende (= f_11a880)
//@ f_118e80
/* === Beschreibung (Katalog) ===
 * - Zweck: Eintrittsmethode der zweiten Bienenstock-Ebene (star2): Sie führt zuerst die Basisinitialisierung
 *   f_115620() aus und startet bei gesetztem Flag d_1c0a08 == 1 einmalig die Eingangssequenz f_11a320(p1)
 *   (d_1c0a08 = 0).
 * - Eingaben: p1 (this-Zeiger des Dungeon-Objekts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0a08 (Eingangsflag).
 === Ende Beschreibung === */
void f_118e80(int p1)
{
    f_115620();
    if (d_1c0a08 == 1) {
        d_1c0a08 = 0;
        f_11a320(p1);
    }
}
//@ f_118eb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Verteiler der zweiten Bienenstock-Ebene (star2, Dungeon-ID 8), der anhand des
 *   Ereigniscodes p2 (0x65..0x6b, 0xc9..0xcf, 0x12d..0x137, 0x191..0x193) die zugehörigen Raummeldungen,
 *   Beutecontainer (0x4a..0x4c), Seil-/Kletterstellen (f_11a6e0) und Ebenenübergänge auslöst.
 * - Eingaben: p1 (this-Zeiger des Dungeon-Objekts), p2 (ausgelöster Ereigniscode unsigned short).
 * - Rückgabewert: 1, wenn der Ereigniscode behandelt wurde, sonst 0 (int).
 * - Wichtige Variablen: result (Behandlungsstatus), st (Array aus 9 lokalen Textkontexten OB), who, item
 *   (ausgewählter Held bzw. Beutecontainer).
 === Ende Beschreibung === */
inline int eq118eb0(const signed char &x, signed char y) { return x == y; }
int f_118eb0(int p1, unsigned short p2)
{
    int result = 1;
    struct { OB o[9]; } st;
    int who, found, item, t;
#define PUT118(n,v) (*(int *)(st.o[n].b + 4) = (v))
#define BEGIN118(n) OBJ(st.o[n])
#define END118(n) f_1254a0((int)&st.o[n], 0)
    switch (p2) {
    case 0x65: if (f_0bf6f0(P,0x2e0000f8) == 1) f_0dd7f0(d_1c0004,7,0x13f5); break;
    case 0x66:
        if (eq118eb0(d_1c09ec,0)) { d_1c09ec=1; BEGIN118(5); PUT118(5,f_038be0(d_1c0004)); f_0bf730(P,0x2e0000f9); END118(5); }
        else f_0bf730(P,0x2e0000fa);
        break;
    case 0x67: ((void (*)(int))f_1198c0)(p1); break;
    case 0x68: if (eq118eb0(d_1c09c8,1)) f_0bf730(P,0x2e0000fd); break;
    case 0x69: f_0bf730(P,0x2e0000fe); break;
    case 0x6a:
        if (eq118eb0(d_1c09f0,0)) {
            d_1c09f0=1; BEGIN118(3); who=f_039320(d_1c0004,0x33); PUT118(3,who);
            f_0bf730(P,0x2e0000ff);
            if ((int)f_0366e0(who,0xe,2,1) != 1) f_0dcf00(d_1c0004,0xe,1);
            END118(3);
        }
        break;
    case 0x6b: f_0bf730(P,0x2e000100); break;
    case 0xc9: if(eq118eb0(d_1c09fc,0)){ d_1c09fc=1; f_0bf730(P,0x2e000101); } break;
    case 0xca: f_11a6e0(p1,0xca); break;
    case 0xcb: f_11a6e0(p1,0xcb); break;
    case 0xcc: f_0bf730(P,0x2e00010a); break;
    case 0xcd:
        if(eq118eb0(d_1c09f8,0)){ d_1c09f8=1; BEGIN118(6); PUT118(6,f_039320(d_1c0004,0x12)); f_0bf730(P,0x2e00010b); END118(6); }
        break;
    case 0xce: f_0bf730(P,0x2e00010c); break;
    case 0xcf: ((void (*)(int))f_119bc0)(p1); break;
    case 0x12d:
        found=1; who=f_039580(d_1c0004,1,1);
        if (!who) { who=f_038c40(d_1c0004); found=0; }
        BEGIN118(4); PUT118(4,who); f_0bf730(P,0x2e00010e); f_0bf730(P,0x2e00010f);
        if(found==1) { *(int *)(st.o[4].b+8)=f_039040(d_1c0004); f_0bf730(P,0x2e000110); }
        else f_0bf730(P,0x2e000111);
        END118(4); break;
    case 0x12e: f_11a6e0(p1,0x12e); break;
    case 0x12f: f_11a6e0(p1,0x12f); break;
    case 0x130: f_0bf730(P,0x2e000112); break;
    case 0x131:
        if (eq118eb0(d_1c09d4,0)) { d_1c09d4=1; BEGIN118(1); PUT118(1,f_038be0(d_1c0004)); f_0bf730(P,0x2e000113); f_0bf730(P,0x2e000114); { int rt906=d_1c0004; d_1c0004=rt906; } /* codeloser Roundtrip steuert die Registervergabe vor f_1254a0 */ END118(1); }
        else f_0bf730(P,0x2e000115);
        break;
    case 0x132:
        if (eq118eb0(d_1c09d8,0)) { d_1c09d8=1; BEGIN118(7); PUT118(7,f_0396f0(d_1c0004,0)); f_0bf730(P,0x2e000116); f_0bf730(P,0x2e000117); END118(7); }
        else f_0bf730(P,0x2e000118);
        break;
    case 0x133: BEGIN118(0); PUT118(0,f_0396f0(d_1c0004,0)); f_0bf730(P,0x2e000119); END118(0); break;
    case 0x134:
        if(eq118eb0(d_1c09dc,0)){ d_1c09dc=1; f_0bf730(P,0x2e00011a); }
        t=(int)operator new(0x14,mark(d_1a7c40,0x2d6)); item=t ? f_112df0(t,0x4c,0,0) : t;
        f_112ec0(item); if(item) operator delete((void*)f_112e70(item,0)); break;
    case 0x135: BEGIN118(8); PUT118(8,f_0396f0(d_1c0004,0)); f_0bf730(P,0x2e00011b); END118(8); break;
    case 0x136: break;
    case 0x137:
        if(eq118eb0(d_1c09f4,0)){ d_1c09f4=1; f_0bf730(P,0x2e00011c); }
        else f_0bf730(P,0x2e00011d);
        break;
    case 0x191: f_11a020(p1); break;
    case 0x192: f_11a6e0(p1,0x192); break;
    case 0x193:
        if(eq118eb0(d_1c09e8,0)){
            d_1c09e8=1; BEGIN118(2); PUT118(2,f_038c40(d_1c0004)); f_0bf730(P,0x2e000122); f_0bf730(P,0x2e000123);
            f_0dcbb0(d_1c0004,100); f_091f70(0x32); f_057220((int)&d_1c2c00,0x803003b,0); END118(2);
        } else f_0bf730(P,0x2e000124);
        break;
    default: result=0; break;
    }
 done118:
    return result;
#undef PUT118
#undef BEGIN118
#undef END118
}
//@ f_119810
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt am Aufstieg 0x65 über f_0bf6f0 (0x2e0000f8), ob die Gruppe in die erste Ebene des Bienenstocks
 *   zurückkehren will, und versetzt sie bei Bestätigung nach Dungeon 7, Position 0x13f5 (f_0dd7f0).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119810(void)
{
    if (f_0bf6f0(P, 0x2e0000f8) == 1) f_0dd7f0(d_1c0004, 7, 0x13f5);
}
//@ f_119840
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignispunkt 0x66 beim ersten Betreten (d_1c09ec == 0) für einen zufälligen Begleiter
 *   (f_038be0) die Meldung 0x2e0000f9 (d_1c09ec = 1) und bei späteren Besuchen die Meldung 0x2e0000fa aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09ec (Besuchsflag).
 === Ende Beschreibung === */
void f_119840(void)
{
    struct OB ob;
    if (EQM(d_1c09ec, 0)) {
        d_1c09ec = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_038be0(d_1c0004);
        f_0bf730(P, 0x2e0000f9);
        f_1254a0((int)&ob, 0);
    } else {
        f_0bf730(P, 0x2e0000fa);
    }
}
//@ f_1198c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet am Ereignis 0x67 den Beutecontainer 0x4a (f_112df0): Beim ersten Mal (d_1c09d0 == 0) wird
 *   zuvor mit einem per Eigenschaft 10 ausgewählten Helden (f_039660) die Entdeckungsmeldung 0x2e0000fb
 *   angezeigt; ist der Container bereits leer (f_1131b0(p1) == 0), erscheint 0x2e0000fc, andernfalls das
 *   Beutefenster f_112ec0(p1).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p1 (Beutecontainer 0x4a), d_1c09d0 (Einmal-Flag).
 === Ende Beschreibung === */
void f_1198c0(void)
{
    NEWC(p1, 0x12e, 0x4a)
    if (EQM(d_1c09d0, 0)) {
        struct OB ob;
        d_1c09d0 = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_039660(d_1c0004, 10);
        f_0bf730(P, 0x2e0000fb);
        f_1254a0((int)&ob, 0);
    }
    if (f_1131b0(p1) == 0) f_0bf730(P, 0x2e0000fc);
    else f_112ec0(p1);
    if (p1 != 0) operator delete((void *)f_112e70(p1, 0));
}
//@ f_1199a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x68 bei gesetztem Flag d_1c09c8 == 1 die Raummeldung 0x2e0000fd über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09c8 (Bedingungsflag).
 === Ende Beschreibung === */
void f_1199a0(void)
{
    if (EQM(d_1c09c8, 1)) f_0bf730(P, 0x2e0000fd);
}
//@ f_1199d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x69 die Raummeldung 0x2e0000fe über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_1199d0(void)
{
    f_0bf730(P, 0x2e0000fe);
}
//@ f_1199f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst beim ersten Betreten von Ereignis 0x6a (d_1c09f0 == 0) einen einmaligen Gegenstandsfund aus: Ein
 *   über Talent 0x33 (f_039320, Sinnesschärfe) ermittelter Held u findet ein Exemplar des Gegenstands 0x0e
 *   (0x2e0000ff), das über f_0366e0 (ersatzweise f_0dcf00) ins Inventar gelegt wird.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09f0 (Fundflag), u (findender Held).
 === Ende Beschreibung === */
void f_1199f0(void)
{
    if (EQM(d_1c09f0, 0)) {
        struct OB ob;
        int u;
        d_1c09f0 = 1;
        OBJ(ob);
        u = f_039320(d_1c0004, 0x33);
        *(int *)(ob.b + 4) = u;
        f_0bf730(P, 0x2e0000ff);
        if (f_0366e0(u, 0xe, 2, 1) != 1) f_0dcf00(d_1c0004, 0xe, 1);
        f_1254a0((int)&ob, 0);
    }
}
//@ f_119aa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x6b die Raummeldung 0x2e000100 über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119aa0(void)
{
    f_0bf730(P, 0x2e000100);
}
//@ f_119ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten von Ereignis 0xc9 (d_1c09fc == 0) die Meldung 0x2e000101 aus und setzt
 *   d_1c09fc = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09fc (Einmal-Flag).
 === Ende Beschreibung === */
void f_119ac0(void)
{
    if (EQM(d_1c09fc, 0)) {
        d_1c09fc = 1;
        f_0bf730(P, 0x2e000101);
    }
}
//@ f_119af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Leitet das Ereignis 0xca an die Hilfsmittel-/Kletterroutine f_11a6e0(p1, 0xca) weiter.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119af0(int p1)
{
    f_11a6e0(p1, 0xca);
}
//@ f_119b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Leitet das Ereignis 0xcb an die Hilfsmittel-/Kletterroutine f_11a6e0(p1, 0xcb) weiter.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119b00(int p1)
{
    f_11a6e0(p1, 0xcb);
}
//@ f_119b10
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0xcc die Raummeldung 0x2e00010a über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119b10(void)
{
    f_0bf730(P, 0x2e00010a);
}
//@ f_119b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten von Ereignis 0xcd (d_1c09f8 == 0) für einen über Talent 0x12 (f_039320)
 *   ausgewählten Helden die Meldung 0x2e00010b aus und setzt d_1c09f8 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09f8 (Einmal-Flag).
 === Ende Beschreibung === */
void f_119b30(void)
{
    if (EQM(d_1c09f8, 0)) {
        struct OB ob;
        d_1c09f8 = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_039320(d_1c0004, 0x12);
        f_0bf730(P, 0x2e00010b);
        f_1254a0((int)&ob, 0);
    }
}
//@ f_119ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einem Schacht (0x2e00009e), ob die Gruppe hinabklettern möchte, und wechselt bei Bestätigung
 *   zur Position 0x2e000a.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_119ba0(void)
{
    f_0bf730(P, 0x2e00010c);
}
//@ f_119bc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das Ereignis 0xcf: Beim ersten Mal (d_1c09e4 == 0) wird für einen über Eigenschaft 6
 *   (f_039660) bestimmten Helden die Meldung 0x2e00010d ausgegeben und der Durchgang 0x1f43 über
 *   f_060740(0x1f43, 1) freigegeben; anschließend wird der Beutecontainer 0x4b (f_112df0) geöffnet, sofern er
 *   noch Gegenstände enthält (f_1131b0(p1) == 1).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09e4 (Öffnungsflag), p1 (Beutecontainer 0x4b).
 === Ende Beschreibung === */
void f_119bc0(void)
{
    if (EQM(d_1c09e4, 0)) {
        struct OB ob;
        d_1c09e4 = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_039660(d_1c0004, 6);
        f_0bf730(P, 0x2e00010d);
        f_060740(0x1f43, 1);
        f_1254a0((int)&ob, 0);
    }
    NEWC(p1, 0x223, 0x4b)
    if (f_1131b0(p1) == 1) f_112ec0(p1);
    if (p1 != 0) operator delete((void *)f_112e70(p1, 0));
}
//@ f_119ca0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x12d für einen über f_039580(..., 1, 1) (ersatzweise den Anführer f_038c40)
 *   ausgewählten Helden die Meldungen 0x2e00010e und 0x2e00010f sowie abhängig davon, ob ein zweiter Held
 *   (f_039040) beteiligt ist, 0x2e000110 oder 0x2e000111 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (erster Held), k (Flag für vorhandenen Begleiter).
 === Ende Beschreibung === */
void f_119ca0(void)
{
    struct OB ob;
    int s, k, p2;
    k = 1;
    s = f_039580(d_1c0004, 1, 1);
    if (s == 0) {
        s = f_038c40(d_1c0004);
        k = 0;
    }
    OBJ(ob);
    *(int *)(ob.b + 4) = s;
    f_0bf730(P, 0x2e00010e);
    f_0bf730(P, 0x2e00010f);
    if (k == 1) {
        *(int *)(ob.b + 8) = f_039040(d_1c0004);
        f_0bf730(P, 0x2e000110);
    } else {
        f_0bf730(P, 0x2e000111);
    }
    f_1254a0((int)&ob, 0);
}
//@ f_119d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Leitet das Ereignis 0x12e an die Hilfsmittel-/Kletterroutine f_11a6e0(p1, 0x12e) weiter.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119d50(int p1)
{
    f_11a6e0(p1, 0x12e);
}
//@ f_119d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Leitet das Ereignis 0x12f an die Hilfsmittel-/Kletterroutine f_11a6e0(p1, 0x12f) weiter.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119d60(int p1)
{
    f_11a6e0(p1, 0x12f);
}
//@ f_119d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x130 die Raummeldung 0x2e000112 über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119d70(void)
{
    f_0bf730(P, 0x2e000112);
}
//@ f_119d90
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x131 beim ersten Betreten (d_1c09d4 == 0) für einen Begleiter (f_038be0) die beiden
 *   Meldungen 0x2e000113 und 0x2e000114 (d_1c09d4 = 1) und bei späteren Besuchen 0x2e000115 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09d4 (Besuchsflag).
 === Ende Beschreibung === */
void f_119d90(void)
{
    struct OB ob;
    if (EQM(d_1c09d4, 0)) {
        d_1c09d4 = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_038be0(d_1c0004);
        f_0bf730(P, 0x2e000113);
        f_0bf730(P, 0x2e000114);
        f_1254a0((int)&ob, 0);
    } else {
        f_0bf730(P, 0x2e000115);
    }
}
//@ f_119e20
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x132 beim ersten Betreten (d_1c09d8 == 0) für den über f_0396f0(..., 0)
 *   ausgewählten Helden die Meldungen 0x2e000116 und 0x2e000117 (d_1c09d8 = 1) und bei späteren Besuchen
 *   0x2e000118 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09d8 (Besuchsflag).
 === Ende Beschreibung === */
void f_119e20(void)
{
    struct OB ob;
    if (EQM(d_1c09d8, 0)) {
        d_1c09d8 = 1;
        OBJ(ob);
        *(int *)(ob.b + 4) = f_0396f0(d_1c0004, 0);
        f_0bf730(P, 0x2e000116);
        f_0bf730(P, 0x2e000117);
        f_1254a0((int)&ob, 0);
    } else {
        f_0bf730(P, 0x2e000118);
    }
}
//@ f_119eb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x133 für den über f_0396f0(..., 0) bestimmten Helden die Meldung 0x2e000119 über
 *   f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119eb0(void)
{
    struct OB ob;
    OBJ(ob);
    *(int *)(ob.b + 4) = f_0396f0(d_1c0004, 0);
    f_0bf730(P, 0x2e000119);
    f_1254a0((int)&ob, 0);
}
//@ f_119f00
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x134 beim ersten Betreten (d_1c09dc == 0) die Meldung 0x2e00011a aus (d_1c09dc = 1)
 *   und öffnet anschließend den Beutecontainer 0x4c (f_112df0, f_112ec0).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09dc (Einmal-Flag), p1 (Beutecontainer 0x4c).
 === Ende Beschreibung === */
void f_119f00(void)
{
    if (EQM(d_1c09dc, 0)) {
        d_1c09dc = 1;
        f_0bf730(P, 0x2e00011a);
    }
    NEWC(p1, 0x2d6, 0x4c)
    f_112ec0(p1);
    if (p1 != 0) operator delete((void *)f_112e70(p1, 0));
}
//@ f_119f80
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x135 für den über f_0396f0(..., 0) bestimmten Helden die Meldung 0x2e00011b aus und
 *   gibt das Ergebnis des Textkontext-Abbaus (f_1254a0) zurück.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Rückgabewert von f_1254a0 (int).
 === Ende Beschreibung === */
int f_119f80(void)
{
    struct OB ob;
    OBJ(ob);
    *(int *)(ob.b + 4) = f_0396f0(d_1c0004, 0);
    f_0bf730(P, 0x2e00011b);
    return f_1254a0((int)&ob, 0);
}

//@ f_119fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalterfunktion für den Ereigniscode 0x136 ohne eigene Wirkung.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_119fd0(void)
{
}

//@ f_119fe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt am Ereignis 0x137 beim ersten Betreten (d_1c09f4 == 0) die Meldung 0x2e00011c (d_1c09f4 = 1) und
 *   bei jedem weiteren Betreten 0x2e00011d aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09f4 (Besuchsflag).
 === Ende Beschreibung === */
void f_119fe0(void)
{
    int r = EQM(d_1c09f4, 0);
    if (r) {
        d_1c09f4 = 1;
        f_0bf730(P, 0x2e00011c);
    } else {
        f_0bf730(P, 0x2e00011d);
    }
}

#undef BEGIN118
#undef END118
#undef EQM
#undef NEWC
#undef OB
#undef OBJ
#undef P
#undef PUT118
#undef d_1a7c40
#undef d_1c0004
#undef d_1c09c4
#undef d_1c09cc
#undef d_1c09e8
#undef d_1c0a00
#undef d_1c0a04
#undef d_1c212a
#undef d_1c212c
#undef d_1c2c00
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_038c40
#undef f_039040
#undef f_039580
#undef f_042a60
#undef f_057220
#undef f_0606a0
#undef f_060740
#undef f_060770
#undef f_060800
#undef f_060a70
#undef f_091f70
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4aa0
#undef f_0db9a0
#undef f_0dcbb0
#undef f_0dd750

#undef f_1142c0
#undef f_114340
#undef f_1155d0
#undef f_115630
#undef f_11a020
#undef f_11a320
#undef f_11a6e0
#undef f_11a620
#undef f_11a600
#undef f_11a5e0
#undef f_11a650
#undef f_11a5c0
#undef f_125400
#undef f_1254a0

// ===== Teil star2_t2 (p3, 11a020-11a880) =====
#define d_1a7c40 d_1a7c40_k1
#define d_1c0004 d_1c0004_k1
#define d_1c09c4 d_1c09c4_k1
#define d_1c09cc d_1c09cc_k1
#define d_1c09e8 d_1c09e8_k1
#define d_1c0a00 d_1c0a00_k1
#define d_1c0a04 d_1c0a04_k1
#define d_1c2c00 d_1c2c00_k1
#define d_1c2c64 d_1c2c64_k1
#define d_1c3498 d_1c3498_k1
#define d_1c349c d_1c349c_k1
#define d_1c3870 d_1c3870_k1
#define f_0104b0 f_0104b0_k1
#define f_010590 f_010590_k1
#define f_038c40 f_038c40_k1
#define f_039040 f_039040_k1
#define f_039580 f_039580_k1
#define f_042a60 f_042a60_k1
#define f_057220 f_057220_k1
#define f_0606a0 f_0606a0_k1
#define f_060740 f_060740_k1
#define f_060770 f_060770_k1
#define f_060800 f_060800_k1
#define f_060a70 f_060a70_k1
#define f_091f70 f_091f70_k1
#define f_0bf680 f_0bf680_k1
#define f_0bf6c0 f_0bf6c0_k1
#define f_0bf6f0 f_0bf6f0_k1
#define f_0bf730 f_0bf730_k1
#define f_0bf980 f_0bf980_k1
#define f_0bfa20 f_0bfa20_k1
#define f_0d4aa0 f_0d4aa0_k1
#define f_0db9a0 f_0db9a0_k1
#define f_0dcbb0 f_0dcbb0_k1
#define f_0dd750 f_0dd750_k1

#define f_1142c0 f_1142c0_k1
#define f_114340 f_114340_k1
#define f_1155d0 f_1155d0_k1
#define f_125400 f_125400_k1
#define f_1254a0 f_1254a0_k1
#define OB OB_k1
// P3 11/13 gleich (suche.py 25.10.2026, Basis star2_t2_P1.CPP)
// star2_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11A020-0x11A880




#define EQI(x,v) (((x)==(v))?1:0)
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_038c40(int p1);
int f_039040(int p1);
int f_039580(int p1, int p2, int p3);
int f_042a60(int p1, int p2);
int f_057220(int p1, int p2, int p3);
int f_0606a0(int p1, int p2);
int f_060740(int p1, int p2);
int f_060770(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_060a70();
int f_091f70(int p1);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf6f0(int p1, int p2, int p3);
#define BF2(a,b) f_0bf6f0(a, b)
int f_0bf730(int p1, int p2);
int f_0bf980(int p1, ...);
int f_0bfa20(int p1, ...);
short f_0d4aa0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcbb0(int p1, int p2);
int f_0dd750(int p1, int p2);

int f_1142c0(int p1, int p2);
int f_114340(int p1, int p2, int p3);
int f_1155d0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
struct OB { int a; int b; int x1; int x2; int c; int rest[10]; };
typedef int (*FPI3)(int, int, int);
typedef FPI3 (*FPG)(int);
typedef void (*FPV)(int);
typedef FPV (*FPGV)(int);
typedef short (*FPS3)(int, int, int);
struct Ent { short id; int a; short k; short m; FPGV fa; int oa; int u; FPG fb; int ob; int v; };
extern struct Ent d_1a7ca0[];
extern unsigned short d_1a7c5e[];
extern signed char d_1c0a00, d_1c0a04, d_1bfaec, d_1c09cc, d_1c09c4, d_1c09e8;
extern int d_1c0004, d_1c2c64, d_1c2c00, d_1c349c, d_1c3870, d_1c3498;

extern const char d_1a7c40[];
struct T13e { char c[0x13e]; };
#define P64 ((int)&d_1c2c64)
#define MKOB(o) f_125400((int)&(o), (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498)
int f_11a6e0(int p1, short p2);
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_11a020
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das Ereignis 0x191 (d_1c0a00, d_1c0a04): Beim ersten Betreten (d_1c0a00 == 0) werden die
 *   Animation 0x2c0013 mit Text 0x2e00011e sowie das Bild 0x0c (0x2e0001) mit Text 0x2e00011f abgespielt; ist
 *   d_1c0a04 == 0 und liefert die virtuelle Dungeon-Prüfung für 0x97 den Wert 0, wird die Meldung 0x2e000121
 *   ausgegeben, d_1c0a04 = 1 gesetzt und die Gruppe auf Position 0x13fe (f_0dd750) versetzt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0a00, d_1c0a04 (Fortschrittsflags), v (Animations- bzw. Bildobjekt).
 === Ende Beschreibung === */
void f_11a020(int p1)
{
    short s;
    int v, t_;
    f_0bf6c0(P64, 5);
    if (EQI(d_1c0a00, 0)) {
        d_1c0a00 = 1;
        t_ = (int)new (mark(d_1a7c40, 0x321)) T13e;
        v = (t_ != 0) ? f_0104b0(t_, 0x2c0013, 0, 0) : t_;
        f_0bf980(P64, v, 0, 0x2e00011e, 0);
        if (v != 0) operator delete((void *)f_010590(v, 0));
        v = f_0606a0(0x2e0001, 0xc);
        f_0bfa20(P64, v, 0, 0x2e00011f, 0);
        if (v != 0) operator delete((void *)((int)(((RivaRasterImage*)(v))->f_0fad20( 0))));
    }
    if (EQI(d_1c0a04, 0)) {
        if (EQI(d_1bfaec, 0)) {
            if (f_1155d0(p1, 1) != 0) f_0bf730(P64, 0x2e000120);
        }
        s = (*(*(FPS3 **)(p1 + 8)))(p1, 0x97, 0);
        if (s == 0) {
            f_060a70();
            f_0bf730(P64, 0x2e000121);
            d_1c0a04 = 1;
            f_0dd750(d_1c0004, 0x13fe);
        }
    }
    f_0bf680(P64);
}
//@ f_11a180
/* === Beschreibung (Katalog) ===
 * - Zweck: Leitet das Ereignis 0x192 an die Hilfsmittel-/Kletterroutine f_11a6e0(p1, 0x192) weiter.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_11a180(int p1)
{
    f_11a6e0(p1, 0x192);
}
//@ f_11a190
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Entdeckung am Ereignis 0x193 (d_1c09e8): Beim ersten Betreten (d_1c09e8 == 0) werden
 *   für den Anführer die Meldungen 0x2e000122 und 0x2e000123 ausgegeben, der Gruppe 100 AP (f_0dcbb0) verliehen,
 *   Sound/Ereignis 0x32 (f_091f70) abgespielt und der Tagebucheintrag 0x803003b (f_057220) angelegt; später
 *   erscheint 0x2e000124.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09e8 (Einmal-Flag).
 === Ende Beschreibung === */
void f_11a190(void)
{
    struct OB ob;
    if (EQI(d_1c09e8, 0)) {
        d_1c09e8 = 1;
        MKOB(ob);
        *(int *)(ob.b + 4) = f_038c40(d_1c0004);
        f_0bf730(P64, 0x2e000122);
        f_0bf730(P64, 0x2e000123);
        f_0dcbb0(d_1c0004, 100);
        f_091f70(0x32);
        f_057220((int)&d_1c2c00, 0x803003b, 0);
        f_1254a0((int)&ob, 0);
        return;
    }
    f_0bf730(P64, 0x2e000124);
}
//@ f_11a250
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft anhand der -1-terminierten Gegenstandsliste d_1a7c5e, ob der Held p4 entweder automatisch (p3
 *   == -2, p2 == 1, Suche über f_0d4aa0) oder in einem gezielt übergebenen Inventarslot p3 >= 0 (f_042a60) ein
 *   geeignetes Werkzeug zum Befreien aus der Harz-/Wabenfalle besitzt, und schreibt den gefundenen Slot nach *p5
 *   sowie die Gegenstands-ID nach *p6.
 * - Eingaben: p1 (Dungeon-Zeiger), p2 (Modusflag), p3 (Inventarslot oder -2 für Gesamtsuche), p4 (Heldenzeiger),
 *   p5 (Ausgabezeiger für Slot), p6 (Ausgabezeiger für Gegenstands-ID).
 * - Rückgabewert: 1, wenn ein passender Gegenstand aus d_1a7c5e gefunden wurde, sonst 0 (int).
 * - Wichtige Variablen: k (Index in d_1a7c5e), r (Trefferflag).
 === Ende Beschreibung === */
int f_11a250(int p1, unsigned short p2, int p3, int p4, short *p5, short *p6)
{
    int r;
    short k;
    short s;
    r = 0;
    k = 0;
    if ((short)(*&p3) == (short)-2) {
        if ((short)p2 == (short)1) {
            while (((short *)d_1a7c5e)[k] != -1 && r == 0) {
                s = f_0d4aa0(p4, ((short *)d_1a7c5e)[k]);
                *p5 = s;
                *(unsigned short *)p5 = (unsigned short)s; // neutraler 16-Bit-Rueckstore haelt p5 in der Registervergabe priorisiert
                if (*p5 >= 0) {
                    r = 1;
                    *p6 = ((short *)d_1a7c5e)[k];
                } else {
                    k++;
                }
            }
        }
    } else if (0 <= (short)p3) {
        int n;
        n = f_042a60(p4, (short)p3);
        while (((short *)d_1a7c5e)[k] != -1 && r == (short)0 && 0 < (short)n) {
            if ((short)n == ((short *)d_1a7c5e)[k]) {
                *p5 = (unsigned short)p3;
                r = 1;
                *p6 = (short)n;
            } else {
                k++;
            }
        }
    }
    { signed char rt906 = d_1c09cc; d_1c09cc = rt906; } // codeloser Roundtrip haelt die Registerreihenfolge in f_11a250
    return r;
}
//@ f_11a320
/* === Beschreibung (Katalog) ===
 * - Zweck: Spielt beim Hinabsteigen in die zweite Bienenstock-Ebene (d_1c09cc == 0, gerufen aus f_118e80) die
 *   Landungsszene ab: Das Bild 0x0f aus 0x2e0001 wird mit Text 0x2e0000f0 angezeigt; besitzt der Anführer m laut
 *   f_11a250 eine geeignete Waffe/Werkzeug (r == 1), wird der Durchgang 0x1f41 über f_060740 geöffnet und
 *   0x2e0000f1..0x2e0000f3 ausgegeben, andernfalls folgen die Meldungen 0x2e0000f4..0x2e0000f7 (d_1c09cc = 2).
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09cc (Status der Eingangssequenz), w (Bildobjekt), a, b (Slot und Gegenstands-ID aus
 *   f_11a250).
 === Ende Beschreibung === */


void f_11a320(int p1)
{
    struct OB ob;
    short a, b, n;
    int w, m, r;
    f_0bf6c0(P64, 5);
    if (EQI(d_1c09cc, 1)) {
        f_0bf730(P64, 0x2e0000ee);
    } else if (EQI(d_1c09cc, 0)) {
        MKOB(ob);
        d_1c09cc = 2;
        w = f_0606a0(0x2e0001, 0xf);
        m = f_038c40(d_1c0004); *(int *)(ob.b + 4) = m;
        if (EQB(d_1c09c4, 1)) {
            *(int *)(ob.c + 0x10) = 0x2e0000ef;
        } else {
            *(int *)(ob.c + 0x10) = 0x20000194;
        }
        f_0bfa20(P64, w, 0, 0x2e0000f0, 0);
        r = f_11a250(p1, 1, -2, m, &a, &b);
        if (r == 1) {
            int t = (short)b * 4;
            int bs = ((int)d_1c2c40);
            int v = *(int *)(t + bs);
            *(int *)(ob.x2 + 4) = v;
            *(short *)(ob.rest[3] + 2) = 1;
            f_060740(0x1f41, 1);
            f_0bfa20(P64, w, 0, 0x2e0000f1, 0);
            { int t_ = (int)(d_1c0004); n = f_0db9a0(t_); }
            if (n > 1) f_0bf730(P64, 0x2e0000f2);
            else f_0bf730(P64, 0x2e0000f3);
        } else {
            f_0bf730(P64, 0x2e0000f4);
            n = f_0db9a0(d_1c0004);
            if (n > 1) f_0bf730(P64, 0x2e0000f5);
            else f_0bf730(P64, 0x2e0000f6);
        }
        f_0bf730(P64, 0x2e0000f7);
        if (w != 0) operator delete((void *)((int)(((RivaRasterImage*)(w))->f_0fad20( 0))));
        f_1254a0((int)&ob, 0);
    }
    f_0bf680(P64);
}
//@ f_11a500
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten einen kurzen Dialog zwischen einem Begleitholden und dem Anführer
 *   (0x2e0000aa / 0x2e0000ab) aus und setzt das Flag d_1c09f8.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11a500(void)
{
    struct OB ob;
    int s, k, p2;
    k = 1;
    f_060800(0x2e0019, 0, 0);
    s = f_039580(d_1c0004, 1, 1);
    if (s == 0) {
        s = f_038c40(d_1c0004);
        k = 0;
    }
    MKOB(ob);
    *(int *)(ob.b + 4) = s;
    f_0bf730(P64, 0x2e00010e);
    f_0bf730(P64, 0x2e00010f);
    if (k == 1) {
        *(int *)(ob.b + 8) = f_039040(d_1c0004);
        f_0bf730(P64, 0x2e000110);
    } else {
        f_0bf730(P64, 0x2e000111);
    }
    f_1254a0((int)&ob, 0);
}
//@ f_11a5c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft die versperrte Stelle 0x1f53 und ruft bei Bedarf f_114410 auf.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11a5c0(int p1)
{
    f_060800(0x2e001d, 0, 0);
    f_11a020(p1);
}
//@ f_11a5e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Callback-Methode (callback493_2), die über f_060800(0x2e001f, 0, 0) die Karten-/Szenenaktion 0x2e001f
 *   auslöst.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_11a5e0(void)
{
    f_060800(0x2e001f, 0, 0);
}
//@ f_11a600
/* === Beschreibung (Katalog) ===
 * - Zweck: Callback-Methode (callback493_3), die über f_060800(0x2e001b, 0, 0) die Karten-/Szenenaktion 0x2e001b
 *   auslöst.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_11a600(void)
{
    f_060800(0x2e001b, 0, 0);
}
//@ f_11a620
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft die versperrte Stelle 0x1f59 und ruft bei Bedarf f_114410 auf.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11a620(void)
{
    f_0bf730(P64, 0x2e000109);
    f_0dd750(d_1c0004, 0x13ec);
}
//@ f_11a650
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den Übergang an einer Kletterstelle (0x2e0000ac / 0x2e0000ad) zur Position 0x2e000e.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
int f_11a650(int p1, int p2, int p3)
{
    struct OB ob;
    MKOB(ob);
    *(int *)(ob.b + 4) = p3;
    *(int *)(ob.c + 4) = p2;
    int r = 0;
    if ((p1 = f_0bf6f0(P64, 0x2e000103)) == 1) r = p1;
    f_1254a0((int)&ob, 0);
    return r;
}
//@ f_11a6b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einem Schacht (0x2e0000af), ob die Gruppe in die dritte Ebene des Bienenstocks hinabsteigen
 *   möchte, und führt bei Bestätigung den Wechsel nach Ebene 9 (0x1453) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
short f_11a6b0(short p1)
{
    short i;
    for (i = 0; i < 5u && p1 != d_1a7ca0[i].id; i++) ;
    return i;
}
//@ f_11a6e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Interaktion mit einer besonderen Vorrichtung oder Öffnung im Bienenstock (d_1c0a00,
 *   d_1c0a04), in die der Spieler einen Gegenstand aus dem Inventar (insbesondere 0x1ad oder 0x1af) einsetzen
 *   kann, um eine Reaktion oder Verwandlung auszulösen.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein passender Gegenstand erfolgreich eingesetzt wurde,
 *   andernfalls 0.
 === Ende Beschreibung === */
int f_11a6e0(int p1, short p2)
{
    struct QB { FPG fn; int off; };
    struct QA { FPGV fn; int off; };
    OB ob;
    int value, object, returned;
    FPI3 call;
    unsigned accepted;
    Ent *entry;

    MKOB(ob);
    returned = 0;
    entry = &d_1a7ca0[f_11a6b0(p2)];
    value = 0;
    p2 = f_1142c0(p1, (int)&value);
    *(int *)(ob.b + 4) = value;
    *(int *)(ob.c + 4) = entry->a;
    if (p2 != -1) {
        if (BF2(P64, 0x2e000102) == 1) {
            if (p2 == entry->k) {
                f_060770((unsigned short)entry->m, 0);
                if (entry->fb != 0) {
                    struct QB *qb = (struct QB *)&entry->fb;
                    object = qb->off + p1;
                    call = qb->fn(object);
                    accepted = call(object, entry->a, value);
                } else {
                    accepted = BF2(P64, 0x2e000103) == 1;
                }
                if (accepted != 0) {
                    f_114340(p1, p2, 0x105);
                    f_0bf730(P64, 0x2e000104);
                    struct QA *qa = (struct QA *)&entry->fa;
                    object = p1 + qa->off;
                    call = (FPI3)qa->fn(object);
                    ((FPV)call)(object);
                    returned = 1;
                } else {
                    f_0bf730(P64, 0x2e000105);
                }
                f_060770((unsigned short)entry->m, 0);
                f_1254a0((int)&ob, 0);
                return returned;
            }
            f_0bf730(P64, 0x2e000106);
        }
    } else {
        f_0bf730(P64, 0x2e000107);
    }
    f_1254a0((int)&ob, 0);
    return returned;
}

#undef BF2
#undef EQB
#undef EQI
#undef MKOB
#undef OB
#undef P64
#undef d_1a7c40
#undef d_1c0004
#undef d_1c09c4
#undef d_1c09cc
#undef d_1c09e8
#undef d_1c0a00
#undef d_1c0a04
#undef d_1c2c00
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_038c40
#undef f_039040
#undef f_039580
#undef f_042a60
#undef f_057220
#undef f_0606a0
#undef f_060740
#undef f_060770
#undef f_060800
#undef f_060a70
#undef f_091f70
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4aa0
#undef f_0db9a0
#undef f_0dcbb0
#undef f_0dd750

#undef f_1142c0
#undef f_114340
#undef f_1155d0
#undef f_125400
#undef f_1254a0

// ===== Teil gz_11a880 (p3, 11a880-11aaa0) =====
#define d_1c212a d_1c212a_k2
#define d_1c212c d_1c212c_k2
#define f_115630 f_115630_k2
#define f_11a500 f_11a500_k2
#define f_11a5c0 f_11a5c0_k2
#define f_11a5e0 f_11a5e0_k2
#define f_11a600 f_11a600_k2
#define f_11a620 f_11a620_k2
#define f_11a650 f_11a650_k2
// P1 9/10 gleich
// gz_11a880.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11A880-0x11AAA0




int f_115630(int p1, int p2);
int f_115640(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
void f_11a500(void);
void f_11a5c0(int p1);
void f_11a5e0(void);
void f_11a600(void);
void f_11a620(void);
int f_11a650(int p1, int p2, int p3);
struct E3 { signed char b; short id; };
extern struct E3 d_1c0a0c, d_1c0a10, d_1c0a14, d_1c0a18, d_1c0a1c, d_1c0a20, d_1c0a24;
extern int d_1c212c;
extern short d_1c212a;
extern int d_1bb978, d_1bb9d0;
#define STB(v,k) (v).b = 0; (v).id = (k);
#define STI(v,k) (v).id = (k); (v).b = 0;
#define TAB(v) *(int *)(d_1c212c + d_1c212a * 4) = (int)&(v); d_1c212a++;
// f_11a880 = $dt:X118e60 (COMDAT aus virtual ~X118e60(){ }), steht hinter dem normalen Code
// f_11a620: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a600: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a5e0: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a650: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a5c0: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a500: entsteht als $Wmp-Thunk (Methodenzeiger), freie Definition entfaellt
// f_11a920: COMDAT-Schwanz (inline, Dateianfang)
// (anderes Modul)  f_11a930
extern short d_1c212a;
struct ObjB { signed char a; short b; };
struct RegB { short count; ObjB **list; };
extern ObjB d_o0c, d_o10, d_o14, d_o18, d_o1c, d_o20, d_o24;
extern RegB d_r;
#pragma aux d_o0c "d_1c0a0c"
#pragma aux d_o10 "d_1c0a10"
#pragma aux d_o14 "d_1c0a14"
#pragma aux d_o18 "d_1c0a18"
#pragma aux d_o1c "d_1c0a1c"
#pragma aux d_o20 "d_1c0a20"
#pragma aux d_o24 "d_1c0a24"
#pragma aux d_r "d_1c212a"
inline signed char z_11a930()
{
    signed char c = 0;
    return c;
}
inline void add_11a930(ObjB &o, RegB &r, short id)
{
    o.a = z_11a930();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
// (Funktion f_11a930 gehoert zu einem anderen Modul, hier weggelassen)

// (anderes Modul)  f_11aa80
// (Funktion f_11aa80 gehoert zu einem anderen Modul, hier weggelassen)

#undef STB
#undef STI
#undef TAB
#undef d_1c212a
#undef d_1c212c
#undef f_115630
#undef f_11a500
#undef f_11a5c0
#undef f_11a5e0
#undef f_11a600
#undef f_11a620
#undef f_11a650
