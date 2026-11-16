/* === Beschreibung (Katalog) ===
 * Einheit ship2 (1036f0 - 107200)
 *
 * Überblick
 *
 * Die Einheit ship2 bildet das vollständige 3D-Dungeon-Modul für den zweiten Bereich des
 * Unterwasser-Schiffswracks (Kennung 0x2b). Da die Rekonstruktionsdatei ship2_P1.CPP als zusammenhängendes Modul
 * (0x102E40-0x1072C0) vorliegt, enthält sie neben den Haupt-Ereignisverteilern (f_1036f0, f_104980) und
 * sämtlichen Raum-, Luken-, Kampf- und Schatz-Interaktionen (f_104760 bis f_1071a0) auch den Anfangsblock aus
 * gz_102e00 (f_102e40 bis f_1036b0) sowie den Abschlussblock aus gz_107200 (f_107200 bis f_107280).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// ship2 (Schatten ueber Riva) - GANZES Linkermodul 0x102E40-0x1072C0 inkl. COMDAT-Schwanz (Forscher 840, 30.10.2026)
// Erzeugt mit comdat/840/bau_modul.py aus: gz_102e00(p3), ship2_t1(p3), ship2_t2(p3), ship2_t3(p3), gz_107200(p3)
#include <string.h>
#include <math.h>
struct B0fb5f0 { char pad[8]; B0fb5f0(int k); virtual ~B0fb5f0(); };   // Basis: ctor f_0fb5f0, dtor f_0fb630
// ===== Teil gz_102e00 (p3, 102e00-1036d8) =====
#define d_1c030c d_1c030c_k0
#define d_1c0310 d_1c0310_k0
#define d_1c031c d_1c031c_k0
#define d_1c0324 d_1c0324_k0
#define d_1c0328 d_1c0328_k0
#define d_1c032c d_1c032c_k0
#define d_1c0330 d_1c0330_k0
#define d_1c0334 d_1c0334_k0
#define d_1c0338 d_1c0338_k0
#define d_1c033c d_1c033c_k0
#define d_1c0340 d_1c0340_k0
#define d_1c0344 d_1c0344_k0
#define d_1c0348 d_1c0348_k0
#define d_1c034c d_1c034c_k0
#define d_1c0350 d_1c0350_k0
#define d_1c0354 d_1c0354_k0
#define d_1c0358 d_1c0358_k0
#define d_1c035c d_1c035c_k0
#define d_1c0360 d_1c0360_k0
#define d_1c0368 d_1c0368_k0
#define d_1c036c d_1c036c_k0
#define d_1c0394 d_1c0394_k0
#define d_1c0398 d_1c0398_k0
#define d_1c039c d_1c039c_k0
#define d_1c212a d_1c212a_k0
#define d_1c212c d_1c212c_k0
#define d_1c21b4 d_1c21b4_k0
#define d_1c27a8 d_1c27a8_k0
#define d_1c299c d_1c299c_k0
#define d_1c2c64 d_1c2c64_k0
#define d_1c3498 d_1c3498_k0
#define d_1c38b0 d_1c38b0_k0
#define f_060a70 f_060a70_k0
#define f_0bf730 f_0bf730_k0
#define f_0bfea0 f_0bfea0_k0
#define f_0e93f0 f_0e93f0_k0
#define f_0fb5f0 f_0fb5f0_k0
#define f_0fb630 f_0fb630_k0
#define f_0fbc60 f_0fbc60_k0
#define f_104980 f_104980_k0
#define f_133fe0 f_133fe0_k0
#define f_145234 f_145234_k0
#define f_145254 f_145254_k0
#define f_1454d0 f_1454d0_k0
#define VF VF_k0
// P3 6/8 gleich (suche.py 24.10.2026, Basis gz_102e00_P1.CPP)
// gz_102e00.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x102E00-0x1036F0
#define EQ(x,v) (((x)==(v))?1:0)
typedef short (*VS3)(int,int,int);
typedef int (*VF3)(int,int,int);
int f_145234(int p1, int p2);
void f_145254(void);
int f_0fb630(int p1, int p2);
int f_0fb5f0(int p1, int p2);
int f_0fefe0(int p1);
#pragma aux f_0fefe0 modify exact [eax]
int f_0fdc30(int p1);
#pragma aux f_0fdc30 modify exact [eax]
int f_0fb740(int p1);
int f_104980(int p1);
int f_060a70(void);
int f_0bf730(int p1, int p2);
int f_0fbc60(int p1);
int f_0e93f0(int p1, int p2, int p3);
int f_1454d0(int p1);
int f_0bfea0(int p1, int p2, int p3);
int f_133fe0(int p1, int p2);

int f_0d4a60(int p1);
extern char d_1bb77c[];
extern char d_1bb7d4[];
extern signed char d_1c030c;
extern unsigned char d_1c0310;
extern char **d_1c212c;
extern short d_1c212a;
#define REG(a,b,id,v) a = v; b = id; d_1c212c[d_1c212a] = (char *)&a; d_1c212a++;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c299c[];
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c38b0;
extern char d_1c031c;
extern short d_1c031d;
extern char d_1c0320;
extern short d_1c0321;
extern char d_1c0324;
extern short d_1c0325;
extern char d_1c0328;
extern short d_1c0329;
extern char d_1c032c;
extern short d_1c032d;
extern char d_1c0330;
extern short d_1c0331;
extern char d_1c0334;
extern short d_1c0335;
extern char d_1c0338;
extern short d_1c0339;
extern char d_1c033c;
extern short d_1c033d;
extern char d_1c0340;
extern short d_1c0341;
extern char d_1c0344;
extern short d_1c0345;
extern char d_1c0348;
extern short d_1c0349;
extern char d_1c034c;
extern short d_1c034d;
extern char d_1c0350;
extern short d_1c0351;
extern char d_1c0354;
extern short d_1c0355;
extern char d_1c0358;
extern short d_1c0359;
extern char d_1c035c;
extern short d_1c035d;
extern char d_1c0360;
extern short d_1c0361;
extern char d_1c0364;
extern short d_1c0365;
extern char d_1c0368;
extern short d_1c0369;
extern char d_1c036c;
extern short d_1c036d;
extern char d_1c0370;
extern short d_1c0371;
extern char d_1c0374;
extern short d_1c0375;
extern char d_1c0378;
extern short d_1c0379;
extern char d_1c037c;
extern short d_1c037d;
extern char d_1c0380;
extern short d_1c0381;
extern char d_1c0384;
extern short d_1c0385;
extern char d_1c0388;
extern short d_1c0389;
extern char d_1c038c;
extern short d_1c038d;
extern char d_1c0390;
extern short d_1c0391;
extern signed char d_1c0394;
extern short d_1c0395;
extern char d_1c0398;
extern short d_1c0399;
extern char d_1c039c;
extern short d_1c039d;

// (anderes Modul)  f_102e00
// (Funktion f_102e00 gehoert zu einem anderen Modul, hier weggelassen)
//@ f_102e40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sieben Funktionen umfassen die Tür- und Wandsynchronisation (f_102e40), den Konstruktor
 *   (f_103430), den Destruktor (f_1034b0), die 3D-Szeneninitialisierung (f_1034d0), die Schritt-/Zeitereignisse
 *   (f_103530), das Abschalten der Spezialeffekte (f_103670) sowie den COMDAT-Destruktor-Wrapper (f_1036b0) des
 *   ship2-Dungeons (siehe auch gz_102e00.md).
 * - Eingaben: Die Methoden erhalten jeweils den this-Zeiger p1 (sowie bei Bedarf Ereignis- oder
 *   Destruktor-Parameter p2, p3).
 * - Rückgabewert: Die Konstruktoren und Destruktoren geben p1 zurück, die 3D-Callbacks 0, und f_102e40 hat
 *   keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct R102e40 { signed char flag; short id; };
struct T102e40 { short count; R102e40 **items; };
#define FIRST102E40(D,K,V) { R102e40 *p = (R102e40 *)&D; p->flag = V; p->id = K; ((T102e40 *)&d_1c212a)->items[((T102e40 *)&d_1c212a)->count] = p; }
#define NEXT102E40(D,K,V) { T102e40 *t = (T102e40 *)&d_1c212a; R102e40 *p = (R102e40 *)&D; p->flag = V; p->id = K; ++t->count; t->items[t->count] = p; }
#define LAST102E40(D,K,V) { NEXT102E40(D,K,V); ++d_1c212a; }
struct RR700V3_102e408;
struct OR700V3_102e408 { signed char flag; short number; char pad; OR700V3_102e408 *init(RR700V3_102e408 &r,short id,signed char f); };
struct RR700V3_102e408 { short count; OR700V3_102e408 **list; void append(OR700V3_102e408 *o) {list[count]=o;count++;} };
inline OR700V3_102e408 *OR700V3_102e408::init(RR700V3_102e408 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_102e408 regR700V3_102e408;
#pragma aux regR700V3_102e408 "d_1c212a"
extern OR700V3_102e408 obR700V3_102e40_1c031c;
#pragma aux obR700V3_102e40_1c031c "d_1c031c"
extern OR700V3_102e408 obR700V3_102e40_1c0320;
#pragma aux obR700V3_102e40_1c0320 "d_1c0320"
extern OR700V3_102e408 obR700V3_102e40_1c0324;
#pragma aux obR700V3_102e40_1c0324 "d_1c0324"
extern OR700V3_102e408 obR700V3_102e40_1c0328;
#pragma aux obR700V3_102e40_1c0328 "d_1c0328"
extern OR700V3_102e408 obR700V3_102e40_1c032c;
#pragma aux obR700V3_102e40_1c032c "d_1c032c"
extern OR700V3_102e408 obR700V3_102e40_1c0330;
#pragma aux obR700V3_102e40_1c0330 "d_1c0330"
extern OR700V3_102e408 obR700V3_102e40_1c0334;
#pragma aux obR700V3_102e40_1c0334 "d_1c0334"
extern OR700V3_102e408 obR700V3_102e40_1c0338;
#pragma aux obR700V3_102e40_1c0338 "d_1c0338"
extern OR700V3_102e408 obR700V3_102e40_1c033c;
#pragma aux obR700V3_102e40_1c033c "d_1c033c"
extern OR700V3_102e408 obR700V3_102e40_1c0340;
#pragma aux obR700V3_102e40_1c0340 "d_1c0340"
extern OR700V3_102e408 obR700V3_102e40_1c0344;
#pragma aux obR700V3_102e40_1c0344 "d_1c0344"
extern OR700V3_102e408 obR700V3_102e40_1c0348;
#pragma aux obR700V3_102e40_1c0348 "d_1c0348"
extern OR700V3_102e408 obR700V3_102e40_1c034c;
#pragma aux obR700V3_102e40_1c034c "d_1c034c"
extern OR700V3_102e408 obR700V3_102e40_1c0350;
#pragma aux obR700V3_102e40_1c0350 "d_1c0350"
extern OR700V3_102e408 obR700V3_102e40_1c0354;
#pragma aux obR700V3_102e40_1c0354 "d_1c0354"
extern OR700V3_102e408 obR700V3_102e40_1c0358;
#pragma aux obR700V3_102e40_1c0358 "d_1c0358"
extern OR700V3_102e408 obR700V3_102e40_1c035c;
#pragma aux obR700V3_102e40_1c035c "d_1c035c"
extern OR700V3_102e408 obR700V3_102e40_1c0360;
#pragma aux obR700V3_102e40_1c0360 "d_1c0360"
extern OR700V3_102e408 obR700V3_102e40_1c0364;
#pragma aux obR700V3_102e40_1c0364 "d_1c0364"
extern OR700V3_102e408 obR700V3_102e40_1c0368;
#pragma aux obR700V3_102e40_1c0368 "d_1c0368"
extern OR700V3_102e408 obR700V3_102e40_1c036c;
#pragma aux obR700V3_102e40_1c036c "d_1c036c"
extern OR700V3_102e408 obR700V3_102e40_1c0370;
#pragma aux obR700V3_102e40_1c0370 "d_1c0370"
extern OR700V3_102e408 obR700V3_102e40_1c0374;
#pragma aux obR700V3_102e40_1c0374 "d_1c0374"
extern OR700V3_102e408 obR700V3_102e40_1c0378;
#pragma aux obR700V3_102e40_1c0378 "d_1c0378"
extern OR700V3_102e408 obR700V3_102e40_1c037c;
#pragma aux obR700V3_102e40_1c037c "d_1c037c"
extern OR700V3_102e408 obR700V3_102e40_1c0380;
#pragma aux obR700V3_102e40_1c0380 "d_1c0380"
extern OR700V3_102e408 obR700V3_102e40_1c0384;
#pragma aux obR700V3_102e40_1c0384 "d_1c0384"
extern OR700V3_102e408 obR700V3_102e40_1c0388;
#pragma aux obR700V3_102e40_1c0388 "d_1c0388"
extern OR700V3_102e408 obR700V3_102e40_1c038c;
#pragma aux obR700V3_102e40_1c038c "d_1c038c"
extern OR700V3_102e408 obR700V3_102e40_1c0390;
#pragma aux obR700V3_102e40_1c0390 "d_1c0390"
extern OR700V3_102e408 obR700V3_102e40_1c0394;
#pragma aux obR700V3_102e40_1c0394 "d_1c0394"
extern OR700V3_102e408 obR700V3_102e40_1c0398;
#pragma aux obR700V3_102e40_1c0398 "d_1c0398"
extern OR700V3_102e408 obR700V3_102e40_1c039c;
#pragma aux obR700V3_102e40_1c039c "d_1c039c"
void f_102e40(void) {
obR700V3_102e40_1c031c.init(regR700V3_102e408,0x16e,0);
obR700V3_102e40_1c0320.init(regR700V3_102e408,0x16f,0);
obR700V3_102e40_1c0324.init(regR700V3_102e408,0x170,0);
obR700V3_102e40_1c0328.init(regR700V3_102e408,0x171,0);
obR700V3_102e40_1c032c.init(regR700V3_102e408,0x172,0);
obR700V3_102e40_1c0330.init(regR700V3_102e408,0x173,0);
obR700V3_102e40_1c0334.init(regR700V3_102e408,0x174,0);
obR700V3_102e40_1c0338.init(regR700V3_102e408,0x175,0);
obR700V3_102e40_1c033c.init(regR700V3_102e408,0x176,0);
obR700V3_102e40_1c0340.init(regR700V3_102e408,0x177,0);
obR700V3_102e40_1c0344.init(regR700V3_102e408,0x178,0);
obR700V3_102e40_1c0348.init(regR700V3_102e408,0x179,0);
obR700V3_102e40_1c034c.init(regR700V3_102e408,0x17a,0);
obR700V3_102e40_1c0350.init(regR700V3_102e408,0x17b,0);
obR700V3_102e40_1c0354.init(regR700V3_102e408,0x17c,0);
obR700V3_102e40_1c0358.init(regR700V3_102e408,0x17d,0);
obR700V3_102e40_1c035c.init(regR700V3_102e408,0x17e,0);
obR700V3_102e40_1c0360.init(regR700V3_102e408,0x17f,0);
obR700V3_102e40_1c0364.init(regR700V3_102e408,0x183,21);
obR700V3_102e40_1c0368.init(regR700V3_102e408,0x184,0);
obR700V3_102e40_1c036c.init(regR700V3_102e408,0x185,0);
obR700V3_102e40_1c0370.init(regR700V3_102e408,0x187,0);
obR700V3_102e40_1c0374.init(regR700V3_102e408,0x188,0);
obR700V3_102e40_1c0378.init(regR700V3_102e408,0x189,0);
obR700V3_102e40_1c037c.init(regR700V3_102e408,0x18a,0);
obR700V3_102e40_1c0380.init(regR700V3_102e408,0x18b,0);
obR700V3_102e40_1c0384.init(regR700V3_102e408,0x18c,0);
obR700V3_102e40_1c0388.init(regR700V3_102e408,0x18d,0);
obR700V3_102e40_1c038c.init(regR700V3_102e408,0x18e,0);
obR700V3_102e40_1c0390.init(regR700V3_102e408,0x18f,0);
obR700V3_102e40_1c0394.init(regR700V3_102e408,0x254,0);
obR700V3_102e40_1c0398.init(regR700V3_102e408,0x255,0);
obR700V3_102e40_1c039c.init(regR700V3_102e408,0x256,0);
}

#undef FIRST102E40
#undef NEXT102E40
#undef LAST102E40
//@ f_103430
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft bei einem Schritt-/Bewegungsereignis über f_0fefe0(p1) == 1 und f_0fdc30(p1)
 *   den Zähler d_1c0310 im Zustand d_1c0394 == 2: Läuft --d_1c0310 auf 0, wechselt d_1c0394 auf 3. Ist d_1c0394
 *   == 3 und die Feldkennung s == 0x15, wird die Begegnungsfunktion f_104980(p1) ausgelöst, andernfalls
 *   f_0fb740(p1).
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger des Dungeon-Objekts). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0394 und d_1c0310.
 * - Besonderheiten: Schrittzähler-Trigger für die zeitverzögerte Begegnung in f_104980.
 === Ende Beschreibung === */
void f_103430(int p1)
{
    if (f_0fefe0(p1) == 1) {
        short s = f_0fdc30(p1);
        if (EQ(d_1c0394, 2) && (--d_1c0310 ? (unsigned char)0 : (unsigned char)1))
            d_1c0394 = 3;
        if (EQ(d_1c0394, 3) && s == 0x15) {
            f_104980(p1);
            return;
        }
        f_0fb740(p1);
    }
}
struct X1034b0 : B0fb5f0 { X1034b0(); virtual ~X1034b0(){ } };   // inline-virtueller Destruktor -> COMDAT $dt:X1034b0 = f_107280
//@ f_1034b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Konstruktor der abgeleiteten Dungeon-Klasse X1034b0 für ship2: Ruft den
 *   Basiskonstruktor f_0fb5f0(this, 0x18) auf und setzt die virtuelle Methodentabelle (deren inline-virtueller
 *   Destruktor am Modulende als COMDAT f_107280 emittiert wird).
 * - Eingaben / Rückgabe: this-Zeiger (X1034b0 *). Gibt this zurück.
 * - Wichtige Variablen & Daten: Kennung 0x18.
 * - Besonderheiten: Erzeugt zusammen mit der Klassendefinition das COMDAT-Fragment f_107280.
 === Ende Beschreibung === */
X1034b0::X1034b0() : B0fb5f0(0x18) { }   // Konstruktor, setzt vtable; erzeugt $dt:X1034b0 als COMDAT am Modulende (= f_107280)
//@ f_1034d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ruft die virtuelle Methode an Offset +0 der Vtable *(p1 + 8) mit den Parametern (p1,
 *   0x65, 2) auf. Bei Rückgabe 0 werden f_060a70(), die Textausgabe 0x2f000074 (f_0bf730) und f_0fbc60(p1)
 *   ausgeführt; bei Rückgabe 1 werden d_1c0398 = 1 und d_1c030c = 3 gesetzt.
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Schreibt d_1c0398 und d_1c030c, nutzt d_1c2c64.
 * - Besonderheiten: Entspricht dem Makro-Pfad GO65 in f_104980.
 === Ende Beschreibung === */
void f_1034d0(int p1)
{
    short s = ((VS3)**(int **)(p1 + 8))(p1, 0x65, 2);
    if (s == 0) {
        f_060a70();
        f_0bf730((int)&d_1c2c64, 0x2f000074);
        f_0fbc60(p1);
        return;
    }
    if (s == 1) {
        d_1c0398 = 1;
        d_1c030c = 3;
    }
}
//@ f_103530
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Führt eine zweistufige Texteingabe-/Rätselprüfung durch: Lädt den erwarteten
 *   Lösungstext p3 (f_0e93f0, f_1454d0), baut aus p4 und p2 den ersten Fragetext (d_1c21b4, d_1c27a8, f_133fe0)
 *   zusammen und liest über f_0bfea0 die Spielereingabe in d_1c299c. Stimmt sie nicht mit buf überein (strcmp),
 *   wird mit p5 und p2 ein zweiter Versuch angeboten.
 * - Eingaben / Rückgabe: p1 (int, ungenutzter Kontext), p2 (int, Zusatztext-ID), p3 (int, Lösungstext-ID), p4
 *   (int, 1. Fragetext-ID), p5 (int, 2. Fragetext-ID). Gibt 1 bei richtiger Antwort zurück, sonst 0.
 * - Wichtige Variablen & Daten: Nutzt d_1c38b0, d_1c21b4, d_1c27a8, d_1c299c, d_1c3498 und d_1c2c64.
 * - Besonderheiten: Wird aus f_105dc0 für die Passwort-/Rätselfragen aufgerufen.
 === Ende Beschreibung === */
int f_103530(int p1, int p2, int p3, int p4, int p5)
{
    char buf[52];
    int r;
    f_0e93f0((int)&d_1c38b0, (int)d_1c21b4, p4);
    f_0e93f0((int)&d_1c38b0, (int)d_1c27a8, p2);
    strcat(d_1c21b4, d_1c27a8); r = f_133fe0((int)&d_1c3498, (int)d_1c21b4);
    f_0e93f0((int)&d_1c38b0, (int)buf, p3);
    f_1454d0((int)buf);
    f_0bfea0((int)&d_1c2c64, (short)strlen(buf), r);
    if (strcmp(buf, d_1c299c) == 0)
        return 1;
    f_0e93f0((int)&d_1c38b0, (int)d_1c21b4, p5);
    strcat(d_1c21b4, d_1c27a8); r = f_133fe0((int)&d_1c3498, (int)d_1c21b4);
    f_0bfea0((int)&d_1c2c64, (short)strlen(buf), r);
    if (strcmp(buf, d_1c299c) == 0)
        return 1;
    return 0;
}
//@ f_103670
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt optional (falls p2 > 0) die Textmeldung p2 über f_0bf730 aus, ruft anschließend
 *   die virtuelle Methode (p1, 0x66, p3) sowie f_060a70() auf und setzt bei Rückgabe 0 das Flag d_1c0394 = 1.
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger), p2 (unsigned, Text-ID oder 0), p3 (short, Modusparameter). Gibt
 *   das short-Ergebnis des virtuellen Aufrufs zurück.
 * - Wichtige Variablen & Daten: Schreibt d_1c0394, nutzt d_1c2c64.
 * - Besonderheiten: Entspricht dem Hilfsablauf GO66 aus f_104980.
 === Ende Beschreibung === */
short f_103670(int p1, unsigned p2, short p3)
{
    short r;
    if (p2 > 0)
        f_0bf730((int)&d_1c2c64, p2);
    r = ((VF3)**(int **)(p1 + 8))(p1, 0x66, (short)p3);
    f_060a70();
    if ((short)r == 0)
        d_1c0394 = 1;
    return r;
}
//@ f_1036b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft für den übergebenen Helden p1, ob sowohl f_042380(p1) == 1 als auch
 *   f_0d4a60(p1) != 0 erfüllt sind.
 * - Eingaben / Rückgabe: p1 (int, Heldenzeiger). Gibt 1 zurück, wenn beide Bedingungen zutreffen, sonst 0.
 * - Wichtige Variablen & Daten: Keine globalen Variablen.
 * - Besonderheiten: Wird als Filter-Callback an f_039ac0 in f_104980 übergeben.
 === Ende Beschreibung === */
int f_1036b0(int p1)
{
    int r = 0;
    if (f_042380((struct hero *)(p1)) == 1) {
        if (f_0d4a60(p1))
            r = 1;
    }
    return r;
}

#undef EQ
#undef FIRST102E40
#undef LAST102E40
#undef NEXT102E40
#undef REG
#undef VF
#undef d_1c030c
#undef d_1c0310
#undef d_1c031c
#undef d_1c0324
#undef d_1c0328
#undef d_1c032c
#undef d_1c0330
#undef d_1c0334
#undef d_1c0338
#undef d_1c033c
#undef d_1c0340
#undef d_1c0344
#undef d_1c0348
#undef d_1c034c
#undef d_1c0350
#undef d_1c0354
#undef d_1c0358
#undef d_1c035c
#undef d_1c0360
#undef d_1c0368
#undef d_1c036c
#undef d_1c0394
#undef d_1c0398
#undef d_1c039c
#undef d_1c212a
#undef d_1c212c
#undef d_1c21b4
#undef d_1c27a8
#undef d_1c299c
#undef d_1c2c64
#undef d_1c3498
#undef d_1c38b0
#undef f_060a70
#undef f_0bf730
#undef f_0bfea0
#undef f_0e93f0
#undef f_0fb5f0
#undef f_0fb630
#undef f_0fbc60
#undef f_104980
#undef f_133fe0
#undef f_145234
#undef f_145254
#undef f_1454d0

// ===== Teil ship2_t1 (p3, 1036d8-105860) =====
#define d_1a6884 d_1a6884_k1
#define d_1bf230 d_1bf230_k1
#define d_1c0004 d_1c0004_k1
#define d_1c02a0 d_1c02a0_k1
#define d_1c030c d_1c030c_k1
#define d_1c0310 d_1c0310_k1
#define d_1c031c d_1c031c_k1
#define d_1c0324 d_1c0324_k1
#define d_1c0328 d_1c0328_k1
#define d_1c032c d_1c032c_k1
#define d_1c0330 d_1c0330_k1
#define d_1c0334 d_1c0334_k1
#define d_1c0338 d_1c0338_k1
#define d_1c033c d_1c033c_k1
#define d_1c0340 d_1c0340_k1
#define d_1c0344 d_1c0344_k1
#define d_1c0348 d_1c0348_k1
#define d_1c034c d_1c034c_k1
#define d_1c0350 d_1c0350_k1
#define d_1c0354 d_1c0354_k1
#define d_1c0358 d_1c0358_k1
#define d_1c035c d_1c035c_k1
#define d_1c0360 d_1c0360_k1
#define d_1c0368 d_1c0368_k1
#define d_1c036c d_1c036c_k1
#define d_1c0394 d_1c0394_k1
#define d_1c0398 d_1c0398_k1
#define d_1c039c d_1c039c_k1
#define d_1c21b4 d_1c21b4_k1
#define d_1c27a8 d_1c27a8_k1
#define d_1c299c d_1c299c_k1
#define d_1c2c44 d_1c2c44_k1
#define d_1c2c64 d_1c2c64_k1
#define d_1c3498 d_1c3498_k1
#define d_1c349c d_1c349c_k1
#define d_1c3870 d_1c3870_k1
#define d_1c38b0 d_1c38b0_k1
#define f_038c40 f_038c40_k1
#define f_039320 f_039320_k1
#define f_039420 f_039420_k1
#define f_039660 f_039660_k1
#define f_039ac0 f_039ac0_k1
#define f_044c90 f_044c90_k1
#define f_046d10 f_046d10_k1
#define f_046d90 f_046d90_k1
#define f_046de0 f_046de0_k1
#define f_046ec0 f_046ec0_k1
#define f_05fa00 f_05fa00_k1
#define f_0606a0 f_0606a0_k1
#define f_060770 f_060770_k1
#define f_060a70 f_060a70_k1
#define f_091f70 f_091f70_k1
#define f_0bbf00 f_0bbf00_k1
#define f_0bde40 f_0bde40_k1
#define f_0bf680 f_0bf680_k1
#define f_0bf6c0 f_0bf6c0_k1
#define f_0bf6f0 f_0bf6f0_k1
#define f_0bf730 f_0bf730_k1
#define f_0bf7b0 f_0bf7b0_k1
#define f_0bf820 f_0bf820_k1
#define f_0bfa20 f_0bfa20_k1
#define f_0bfea0 f_0bfea0_k1
#define f_0c0020 f_0c0020_k1
#define f_0d54f0 f_0d54f0_k1
#define f_0d5ff0 f_0d5ff0_k1
#define f_0db820 f_0db820_k1
#define f_0db8b0 f_0db8b0_k1
#define f_0db940 f_0db940_k1
#define f_0dbb20 f_0dbb20_k1
#define f_0dc3c0 f_0dc3c0_k1
#define f_0dcae0 f_0dcae0_k1
#define f_0dcbb0 f_0dcbb0_k1
#define f_0dcf00 f_0dcf00_k1
#define f_0dd410 f_0dd410_k1
#define f_0dd750 f_0dd750_k1
#define f_0dd7f0 f_0dd7f0_k1
#define f_0e93f0 f_0e93f0_k1

#define f_0fb660 f_0fb660_k1
#define f_0fbc60 f_0fbc60_k1
#define f_0fbe10 f_0fbe10_k1
#define f_0fbee0 f_0fbee0_k1
#define f_0fca60 f_0fca60_k1
#define f_0fdbd0 f_0fdbd0_k1
#define f_103530 f_103530_k1
#define f_1036b0 f_1036b0_k1
#define f_105860 f_105860_k1
#define f_105cd0 f_105cd0_k1
#define f_105dc0 f_105dc0_k1
#define f_106300 f_106300_k1
#define f_106440 f_106440_k1
#define f_1065f0 f_1065f0_k1
#define f_106e30 f_106e30_k1
#define f_106ef0 f_106ef0_k1
#define f_112df0 f_112df0_k1
#define f_112e70 f_112e70_k1
#define f_112ec0 f_112ec0_k1
#define f_125400 f_125400_k1
#define f_1254a0 f_1254a0_k1
#define f_125ed0 f_125ed0_k1
#define f_133fe0 f_133fe0_k1
#define f_1454d0 f_1454d0_k1
#define f_1457e0 f_1457e0_k1
#define OB OB_k1
#define S0C S0C_k1
#define S14 S14_k1
#define VF VF_k1
// P3 6/8 gleich (suche.py 29.10.2026, Basis ship2_t1_P1.CPP)
// ship2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1036F0-0x107200
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046ec0(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0d5ff0();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbb20(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc3c0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd410(int p1, int p2);                           // reg edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_0fbe10(int p1);                                   // reg eax stapel 0
int f_0fbee0(int p1, int p2);                           // reg eax edx stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_0fdbd0();                                         // reg - stapel 0
int f_103530(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0328;                    // 0x1C0328
extern int d_1c032c;                    // 0x1C032C
extern int d_1c0330;                    // 0x1C0330
extern int d_1c0338;                    // 0x1C0338
extern int d_1c033c;                    // 0x1C033C
extern int d_1c0340;                    // 0x1C0340
extern int d_1c0344;                    // 0x1C0344
extern int d_1c0354;                    // 0x1C0354
extern int d_1c0358;                    // 0x1C0358
extern int d_1c0360;                    // 0x1C0360
extern int d_1c0368;                    // 0x1C0368
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a6884[];           // Text 0x1A6884

unsigned short f_0bfa20(int p1, int p2, ...);
short f_0bf820(...);
short f_044c90(int p1, int p2, int p3);
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
short f_1457e0(int p1);
short f_0d54f0(int p1, int p2);
short f_0db940(int p1);
int f_0fbc60(int p1);
int f_0bde40(int p1);
int f_1254a0(int p1, int p2);
int f_112e70(int p1, int p2);
int f_046d90(int p1, int p2);
void f_104980(int p1);
int f_0bf680(int p1, int p2);
int f_105860(int p1);
int f_105dc0(int p1);
int f_105cd0(int p1);
int f_106300(int p1);
int f_106440(int p1);
int f_106e30(int p1);
int f_106ef0(int p1);
int f_1065f0(int p1);
void f_1036b0(void);
extern signed char d_1c02a0, d_1c030c, d_1c0310, d_1c031c, d_1c0324, d_1c0334, d_1c0348, d_1c034c, d_1c0350, d_1c035c, d_1c036c, d_1c0394, d_1c0398, d_1c039c;
typedef RivaTextContextData OB;
struct S14 {int a[5];};
struct S0C {int a[3];};
typedef short (*VF)(int,int,int);
#define VCALL(p,a,b) ((**(VF**)((p)+8))((p),(a),(b)))
#define D2C64 ((int)&d_1c2c64)
#define D2C44 ((int)&d_1c2c44)
#define D349C ((int)&d_1c349c)
#define D3870 ((int)&d_1c3870)
#define D3498 ((int)&d_1c3498)
#define FL(x,v) (((x)==(v))?1:0)
#define CT14(q,t,CD) q = (t != 0) ? f_112df0(t, CD, 0, 0) : t;
#define NEW14(LN,CD) { int q; int t_ = (int)new (mark(d_1a6884, LN)) S14; CT14(q,t_,CD) f_112ec0(q); if (q) operator delete((void*)f_112e70(q, 0)); }
#define NEW0C(LN,CD) { int q = (int)new (mark(d_1a6884, LN)) S0C; if (q) q = f_046d10(q, CD); f_046de0(q); if (q) operator delete((void*)f_046d90(q, 0)); }
#define M(x) f_0bf730(D2C64, x)
#define OBCTOR f_125400((int)&ob, D349C, D3870, D3498)
#define OBDTOR f_1254a0((int)&ob, 0)
#define SETB(v) *(int*)(ob.addresses.objects+4) = (v)

//@ f_1036f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese große Verteilerfunktion verarbeitet die primären Kartenereignisse (0x00 bis 0x46) im
 *   Schiffswrack ship2, darunter das Öffnen verklemmter Schotten, das Untersuchen überfluteter Kabinen, Kämpfe
 *   gegen Unterwassergegner und den Übergang zwischen den Wrackteilen (f_105cd0).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktionszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der ausgelösten Interaktion zurück.
 === Ende Beschreibung === */
void *largeCtor493(void*,int,int,int);
#pragma aux largeCtor493 "f_112df0" parm [eax] [edx] [ebx] [ecx] value [eax] modify exact [eax ebx edx]
struct LargeShip493 {char data[0x14]; __pragma("largeCtor493") LargeShip493(int,int,int);};
void *smallCtor493(void*,int);
#pragma aux smallCtor493 "f_046d10" parm [eax] [edx] value [eax] modify exact [eax edx]
struct SmallShip493 {char data[0xc]; __pragma("smallCtor493") SmallShip493(int);};
// Astra1066: eigenstaendiger Neuaufbau aus den Originalpfaden.
int f_1036f0(int p1, short p2)
{
    int f_0bf680(int);
    struct Frame1066 { OB room259, room65, room1f8, room12d, room25a, roomd2; } frame;
    struct Flag1066 {
        static inline int equal(const signed char &value, signed char expected) {
            return value == expected;
        }
    };
    int handled = 0;
    if (p2 != 0) {
        handled = 1;
        switch (p2) {
        case 0x270a:
            f_0fca60(p1);
            break;
        case 0x2709:
            d_1c02a0 = 2;
            break;
        case 0x65: {
            int actor = p1;
            f_125400((int)&frame.room65, D349C, D3870, D3498);
            *(int *)(frame.room65.addresses.objects + 4) = f_038c40(d_1c0004);
            if (f_0bf6f0(D2C64, 0x2f000066) == handled) {
                if (f_0bf6f0(D2C64, 0x2f000067) == handled) {
                    f_0bf730(D2C64, 0x2f000068);
                    short parameter = 0;
                    int self = actor;
                    if (VCALL(self, 0x65, parameter) != 2) {
                        f_060a70();
                        f_0bf730(D2C64, 0x2f000069);
                        f_0fbc60(actor);
                    }
                }
            }
            f_1254a0((int)&frame.room65, 0);
            break;
        }
        case 0x66: { int object = (int)mark(d_1a6884, 0x2c6); object = (int)operator new(20,(void*)object);
            int memory = object;
            if (memory) object = (int)largeCtor493((void*)memory, 0x5c, 0, 0);
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); } break;
        case 0x67: { int object = (int)mark(d_1a6884, 0x2d8); object = (int)operator new(20,(void*)object);
            int memory = object;
            if (memory) object = (int)largeCtor493((void*)memory, 0x5d, 0, 0);
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); } break;
        case 0x68: { unsigned size = 20;
            void *tag = mark(d_1a6884, 0x2ea);
            int object = (int)operator new(size,tag);
            if (object) object = (int)largeCtor493((void*)object, 0x5e, 0, 0);
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); } break;
        case 0x69: { int object = (int)mark(d_1a6884, 0x2fc); object = (int)operator new(20,(void*)object);
            int memory = object;
            if (memory) object = (int)largeCtor493((void*)memory, 0x5f, 0, 0);
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); } break;
        case 0xc9:
            if (f_0bf6f0(D2C64, 0x2f0000bb) == handled)
                f_0dd7f0(d_1c0004, 0x17, 0x1407);
            break;
        case 0xca: f_105860(p1); break;
        case 0xcb:
        case 0xcc: f_0bf730(D2C64, 0x2f0000c2);
            { int roundtrip3_1066=d_1c0004; d_1c0004=roundtrip3_1066; } // haelt die Symbol- und Registerfolge in f_1036f0 wie im Original
            break;
        case 0xcd: break;
        case 0xce:
            if (f_0bf6f0(D2C64, 0x2f0000c3) == handled) {
                unsigned short choice = f_1457e0(5);
                choice -= 1;
                switch (choice) {
                case 0: f_0bf730(D2C64, 0x2f0000c4); break;
                case 1: f_0bf730(D2C64, 0x2f0000c5); break;
                case 2: f_0bf730(D2C64, 0x2f0000c6); break;
                case 3: f_0bf730(D2C64, 0x2f0000c7); break;
                case 4: {
                    int accepted = f_0bf6f0(D2C64, 0x2f0000c8);
                    if (accepted == handled) {
                        int width;
                        short answer = f_0bf7b0(D2C64, 2, 0x2f0000c9, 0,
                                               width = 80, accepted ^ handled);
                        f_0dcf00(d_1c0004, 0x1c, answer);
                    }
                    break;
                }
                }
            }
            f_125ed0(D2C44, 3);
            break;
        case 0xcf: f_0bf730(D2C64, 0x2f0000ca); break;
        case 0xd0: f_0bf730(D2C64, 0x2f0000cb); break;
        case 0xd1: f_0bf730(D2C64, 0x2f0000cc); break;
        case 0xd2: {
            f_125400((int)&frame.roomd2, D349C, D3870, D3498);
            *(int *)(frame.roomd2.addresses.objects + 4) = f_039660(d_1c0004, 12);
            f_0bf730(D2C64, 0x2f0000cd);
            { int roundtrip1066=d_1c0004; d_1c0004=roundtrip1066; } // haelt die Symbol- und Registerfolge in f_1036f0 wie im Original
            if (Flag1066::equal(d_1c0324, 0)) {
                d_1c0324 = 1;
                f_0bf730(D2C64, 0x2f0000ce);
                f_125ed0(D2C44, 2);
            } else {
                f_0bf730(D2C64, 0x2f0000cf);
                f_125ed0(D2C44, handled);
            }
            f_1254a0((int)&frame.roomd2, 0);
            break;
        }
        case 0xd4:
            if (Flag1066::equal(d_1c039c, 0)) {
                f_0bf730(D2C64, 0x2f0000d3);
                d_1c039c = 1;
            }
            break;
        case 0xd5: f_105dc0(p1);
            { int roundtrip4_1066=d_1c0004; d_1c0004=roundtrip4_1066; } // haelt die Symbol- und Registerfolge in f_1036f0 wie im Original
            break;
        case 0x12d: {
            f_125400((int)&frame.room12d, D349C, D3870, D3498);
            *(int *)(frame.room12d.addresses.objects + 4) = f_039320(d_1c0004, 0x25);
            f_0bf730(D2C64, 0x2f0000ec);
            f_1254a0((int)&frame.room12d, 0);
            break;
        }
        case 0x12e: f_0bf730(D2C64, 0x2f0000ed); break;
        case 0x12f: f_0bf730(D2C64, 0x2f0000ee); break;
        case 0x130: { int object = (int)mark(d_1a6884, 0x899); object = (int)operator new(12,(void*)object);
            if (object) object = (int)smallCtor493((void*)object, 0x3a);
            f_046de0(object);
            if (object) operator delete((void*)f_046d90(object, 0)); } break;
        case 0x131: { int object = (int)mark(d_1a6884, 0x8ab); object = (int)operator new(12,(void*)object);
            if (object) object = (int)smallCtor493((void*)object, 0x3b);
            f_046de0(object);
            if (object) operator delete((void*)f_046d90(object, 0)); } break;
        case 0x132: { int object = 12; void *tag = mark(d_1a6884, 0x8bd); object = (int)operator new(object,tag);
            if (object) object = (int)smallCtor493((void*)object, 0x3c);
            f_046de0(object);
            if (object) operator delete((void*)f_046d90(object, 0)); } break;
        case 0x133: { int object = (int)mark(d_1a6884, 0x8cf); object = (int)operator new(12,(void*)object);
            if (object) object = (int)smallCtor493((void*)object, 0x3d);
            f_046de0(object);
            if (object) operator delete((void*)f_046d90(object, 0)); } break;
        case 0x134: f_106300(p1); break;
        case 0x191:
            if (Flag1066::equal(d_1c0334, 0)) {
                d_1c0334 = 1;
                f_0bf730(D2C64, 0x2f0000f0);
            } else {
                f_0bf730(D2C64, 0x2f0000f1);
            }
            { int memory = (int)operator new(20, mark(d_1a6884, 0x90e));
            int object = memory ? (int)largeCtor493((void*)memory, 0x56, 0, 0) : memory;
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); }
            break;
        case 0x192: f_106440(p1); break;
        case 0x193: f_0bf730(D2C64, 0x2f0000f5); break;
        case 0x194: f_0bf730(D2C64, 0x2f0000f6); break;
        case 0x195: { int object = (int)mark(d_1a6884, 0x95f); object = (int)operator new(12,(void*)object);
            if (object) object = (int)smallCtor493((void*)object, 0x3f);
            f_046de0(object);
            if (object) operator delete((void*)f_046d90(object, 0)); } break;
        case 0x1f5:
            if (Flag1066::equal(d_1c0348, 0)) {
                d_1c0348 = 1;
                f_0bf730(D2C64, 0x2f000114);
            }
            { int memory = (int)operator new(20, mark(d_1a6884, 0xa8a));
            int object = memory ? (int)largeCtor493((void*)memory, 0x58, 0, 0) : memory;
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); }
            break;
        case 0x1f6:
            if (Flag1066::equal(d_1c034c, 0)) {
                d_1c034c = 1;
                f_0bf730(D2C64, 0x2f000115);
            }
            { int memory = (int)operator new(20, mark(d_1a6884, 0xaa3));
            int object = memory ? (int)largeCtor493((void*)memory, 0x59, 0, 0) : memory;
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); }
            break;
        case 0x1f7:
            if (Flag1066::equal(d_1c0350, 0)) {
                d_1c0350 = 1;
                f_0bf730(D2C64, 0x2f000116);
            }
            { int memory = (int)operator new(20, mark(d_1a6884, 0xabc));
            int object = memory ? (int)largeCtor493((void*)memory, 0x5a, 0, 0) : memory;
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); }
            break;
        case 0x1f8: {
            f_125400((int)&frame.room1f8, D349C, D3870, D3498);
            if (f_0d54f0(d_1c0004, 0x1e) >= 0)
                *(int *)(frame.room1f8.addresses.numbers + 4) = 0x2f000118;
            else
                *(int *)(frame.room1f8.addresses.numbers + 4) = 0x20000194;
            f_0bf730(D2C64, 0x2f000117);
            f_0dcae0(d_1c0004);
            f_1254a0((int)&frame.room1f8, 0);
            break;
        }
        case 0x1f9: f_106e30(p1); break;
        case 0x1fa: f_106ef0(p1); break;
        case 0x259: {
            f_125400((int)&frame.room259, D349C, D3870, D3498);
            *(int *)(frame.room259.addresses.objects + 4) = f_039660(d_1c0004, 12);
            if (Flag1066::equal(d_1c035c, 0)) {
                f_0bf6c0(D2C64, 5);
                if (f_0bf6f0(D2C64, 0x2f00011b) == handled) {
                    f_0bf730(D2C64, 0x2f00011c);
                    d_1c035c = 1;
                    d_1c036c = 3;
                }
                f_0bf680(D2C64);
            } else {
                f_0bf730(D2C64, 0x2f00011d);
            }
            f_1254a0((int)&frame.room259, 0);
            break;
        }
        case 0x25a: {
            f_125400((int)&frame.room25a, D349C, D3870, D3498);
            f_0bf6c0(D2C64, 5);
            if (Flag1066::equal(d_1c035c, 0)) {
                *(int *)(frame.room25a.addresses.numbers + 4) = 0x2f00011f;
                if (f_0bf6f0(D2C64, 0x2f00011e) == handled) {
                    f_0bf730(D2C64, 0x2f00011c);
                    d_1c035c = 1;
                    d_1c036c = 3;
                }
            } else {
                *(int *)(frame.room25a.addresses.numbers + 4) = 0x2f000120;
                f_0bf730(D2C64, 0x2f00011e);
            }
            f_0bf680(D2C64);
            f_1254a0((int)&frame.room25a, 0);
            break;
        }
        case 0x25b: break;
        case 0x25c: f_0bf730(D2C64, 0x2f000121); break;
        case 0x25d: f_0bf730(D2C64, 0x2f000122); break;
        case 0x25e: f_0bf730(D2C64, 0x2f000123); break;
        case 0x25f:
            f_0bf730(D2C64, 0x2f000124);
            { int object = (int)mark(d_1a6884, 0xbaa); object = (int)operator new(20,(void*)object);
            int memory = object;
            if (memory) object = (int)largeCtor493((void*)memory, 0x5b, 0, 0);
            f_112ec0(object);
            if (object) operator delete((void*)f_112e70(object, 0)); }
            break;
        case 0x2bd:
            if (f_0bf6f0(D2C64, 0x2f000125) == handled)
                f_0dd7f0(d_1c0004, 0x17, 0x139a);
            break;
        case 0x2be:
            { int roundtrip2_1066=d_1c0004; d_1c0004=roundtrip2_1066; } // haelt die Symbol- und Registerfolge in f_1036f0 wie im Original
            if (f_0bf6f0(D2C64, 0x2f000126) == handled)
                f_0dd7f0(d_1c0004, 0x19, 5000);
            break;
        case 0x2bf: f_0bf730(D2C64, 0x2f0000c2); break;
        case 0x1b59: case 0x1b5a: case 0x1b5b: case 0x1b5c: {}
        case 0x1b5d: case 0x1b5e: case 0x1b5f:
            f_0fb660(p1, p2);
            break;
        case 0x1f41: f_104980(p1); break;
        case 0x1f42: f_105cd0(p1); break;
        case 0x1f43: f_05fa00(0x2c, 0x1f43); break;
        case 0x1f44: f_05fa00(0x2d, 0x1f44); break;
        case 0x1f45: f_05fa00(0x2f, 0x1f45); break;
        case 0x1f46: f_05fa00(0x2e, 0x1f46); break;
        case 0x1f47: f_1065f0(p1); break;
        default: handled = 0; break;
        }
    }
    return handled;
}

//@ f_104760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet das Öffnen einer verschlossenen oder aufgequollenen Schiffstür an den
 *   Koordinaten (p2, p3) mithilfe eines Schlüssels (p4) oder durch Aufbrechen und aktualisiert das Zustandsflag
 *   *p5.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Koordinaten p2 und p3, die Schlüssel-ID p4 sowie den
 *   Zeiger p5 auf das Türflag.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_104760(int p1)
{
  { OB ob; OBCTOR; SETB(f_038c40(d_1c0004));
    if (f_0bf6f0(D2C64, 0x2f000066) == 1 && f_0bf6f0(D2C64, 0x2f000067) == 1) {
      M(0x2f000068);
      if (VCALL(p1, 0x65, 0) != 2) { f_060a70(); M(0x2f000069); f_0fbc60(p1); }
    }
    OBDTOR; }
}

//@ f_104810
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese vier Hilfsmethoden prüfen und schalten gekoppelte Luken, Durchgänge und Ebenenwechsel innerhalb
 *   von ship2 um.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1 (bzw. Koordinatenparameter).
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void) bzw. geben den Statuscode zurück.
 === Ende Beschreibung === */
void f_104810(void)
{
  NEW14(0x2c6, 0x5c)
}

//@ f_104860
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x5d (f_112df0, Zeile 0x2d8), führt dessen
 *   Interaktion über f_112ec0 aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x67 in f_1036f0.
 === Ende Beschreibung === */
void f_104860(void)
{
  NEW14(0x2d8, 0x5d)
}

//@ f_1048b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x5e (f_112df0, Zeile 0x2ea), führt f_112ec0
 *   aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x68 in f_1036f0.
 === Ende Beschreibung === */
void f_1048b0(void)
{
  NEW14(0x2ea, 0x5e)
}

//@ f_104900
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert das 20-Byte-Behälterobjekt 0x5f (f_112df0, Zeile 0x2fc), führt f_112ec0
 *   aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x69 in f_1036f0.
 === Ende Beschreibung === */
void f_104900(void)
{
  NEW14(0x2fc, 0x5f)
}

//@ f_104980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zweite große Verteilerfunktion verarbeitet die weiteren Karten- und Raumereignisse in ship2 und
 *   verzweigt in die Detailroutinen für Frachträume, Kojen und Kämpfe.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktionszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der Interaktion zurück.
 === Ende Beschreibung === */
void f_104980(int p1)
{
  struct EqByte { static inline int run(const signed char &x,int y) { return x==y; } };
  struct PutByte { static inline void run(signed char &x,signed char y) { x=y; } };
  struct PutFirstPair { static inline void run(signed char &a,signed char &b) { signed char one=1, three=3; a=one; b=three; } };
  struct PutPair { static inline void run(signed char x,signed char y,signed char &a,signed char &b) { a=x; b=y; } };
  struct PutInt { static inline void run(signed char &a,int x) { a=x; } };
  struct CloseScene { static inline void run(OB &x) { f_1254a0((int)&x,0); } };
  OB ob;
  short answer, option, selection;
  unsigned short firstAnswer;
  int value, owner;
#define FIN { OBDTOR; return; }
#define GO65 { option=VCALL(p1,0x65,2); if(option==0){f_060a70();M(0x2f000074);f_0fbc60(p1);} else if(option==1){d_1c0398=1;d_1c030c=3;} FIN }
#define GO66(n) { option=VCALL(p1,0x66,n);f_060a70();if(option==0)d_1c0394=1;FIN }
  OBCTOR;
  if(EqByte::run(d_1c0398,1)){M(0x2f00006a);f_0fbc60(p1);goto scene_done;}
  switch((unsigned char)d_1c0394){
  case 1:case 2:f_05fa00(0x2a,0x1f41);FIN
  case 3:M(0x2f00006b);GO66(0)
  case 0:
    if(EqByte::run(d_1c031c,0)){
      d_1c031c=1;int item=f_0606a0(0x2f0002,5);
      SETB(f_038c40(d_1c0004));f_0bde40(D2C64);
      firstAnswer=f_0bfa20(D2C64,item,0,0x2f00006c,4,0x2f00006e,0x2f00006f,0x2f000070,0x2f000071);
      if(item)operator delete((void*)((int)(((RivaRasterImage*)(item))->f_0fad20(0))));
    }else{
      int item=f_0606a0(0x2f0002,5);f_0bde40(D2C64);
      firstAnswer=f_0bfa20(D2C64,item,0,0x2f00006d,4,0x2f00006e,0x2f00006f,0x2f000070,0x2f000071);
      if(item)operator delete((void*)((int)(((RivaRasterImage*)(item))->f_0fad20(0))));
    }
    switch(firstAnswer){
    case 1:
      if(f_0bf6f0(D2C64,0x2f000072)==1){
        M(0x2f000073);
        option=VCALL(p1,0x65,2);
        if(option==0){f_060a70();M(0x2f000074);f_0fbc60(p1);}
        else if(option==1){PutFirstPair::run(d_1c0398,d_1c030c);}
        FIN
      }
      break;
    case 2:
      do{selection=f_0bf820(D2C64,0x2f000075,5,0x2f000076,0x2f000077,0x2f000078,0x2f000079,0x2f00007a);}while(selection==-1);
      switch((unsigned short)selection){
      case 1:GO65
      case 2:
        value=f_0fbe10(p1);
        if(value==1)M(0x2f00007c);else M(0x2f00007b);
        M(0x2f00007d);owner=f_039320(d_1c0004,0x2b);SETB(owner);
        option=f_044c90(owner,0x2b,(int)(signed char)(((signed char)value+1)*12));
        if(option>=1){
          do{answer=f_0bf820(D2C64,0x2f00007e,3,0x2f000080,0x2f000081,0x2f000083);}while(answer==-1);
          if(answer==3)answer=4;
        }else{
          do{answer=f_0bf820(D2C64,0x2f00007f,3,0x2f000080,0x2f000081,0x2f000082);}while(answer==-1);
        }
        switch((unsigned short)answer){
        case 1:
          if(option>=1)M(0x2f000084);
          else{
            answer=f_0bf820(D2C64,0x2f000085,3,0x2f000086,0x2f000087,0x2f000088);
            switch((unsigned short)answer){
            case 1:f_0db8b0(d_1c0004,1000);break;
            case 2:M(0x2f00008a);option=VCALL(p1,0x66,0);f_060a70();if(option==0)d_1c0394=1;break;
            default:M(0x2f00008b);option=VCALL(p1,0x66,0);f_060a70();if(option==0)d_1c0394=1;break;
            }
          }
          break;
        case 2:case 3:case 4:
          option=VCALL(p1,0x66,0);f_060a70();
          if(option==0)d_1c0394=1;
          if(option==0)f_0db820(d_1c0004,600);
          break;
        }
        f_125ed0(D2C44,10);FIN
      case 3:
        answer=f_0bf820(D2C64,0x2f00008c,5,0x2f00008d,0x2f00008e,0x2f00008f,0x2f000090,0x2f000091);
        switch((unsigned short)(short)(answer & 0xffff)){ // haelt die 16-Bit-Zwischenerweiterung und Registerfolge wie im Original
        case 1:GO65
        case 2:
          do{answer=f_0bf820(D2C64,0x2f000092,2,0x2f000093,0x2f000094);}while(answer==-1);
          switch((unsigned short)answer){
          case 1:
            do{answer=f_0bf820(D2C64,0x2f000095,2,0x2f000096,0x2f000097);}while(answer==-1);
            switch((unsigned short)answer){
            case 1:GO65
            case 2:PutByte::run(d_1c0310,3);*(volatile signed char*)&d_1c0394=2;FIN // haelt die Schreibreihenfolge vor dem Destruktor wie im Original
            }
            break;
          case 2:
            answer=f_0bf820(D2C64,0x2f000098,3,0x2f000099,0x2f00009a,0x2f00009b);
            switch((unsigned short)answer){
            case 2:GO65
            case 3:M(0x2f00009c);GO66(0)
            }
            break;
          }
          break;
        case 3:
          do{answer=f_0bf820(D2C64,0x2f00009d,2,0x2f00009e,0x2f00009f);}while(answer==-1);
          switch((unsigned short)answer){
          case 1:
            answer=f_0bf820(D2C64,0x2f0000a0,2,0x2f0000a1,0x2f0000a2);
            switch((unsigned short)answer){
            case 1:GO66(0)
            case 2:PutByte::run(d_1c0310,3);PutByte::run(d_1c0394,2);FIN
            }
            break;
          case 2:M(0x2f0000a3);GO66(0)
          }
          break;
        case 4:M(0x2f00009c);GO66(0)
        default:f_060770(0x6a,0);FIN
        }
        break;
      case 4:
        do{answer=f_0bf820(D2C64,0x2f0000a4,2,0x2f00009e,0x2f00009f);}while(answer==-1);
        switch((unsigned short)answer){
        case 1:
          answer=f_0bf820(D2C64,0x2f0000a5,2,0x2f0000a1,0x2f0000a2);
          switch((unsigned short)answer){
          case 1:GO66(0)
          case 2:PutPair::run(3,2,d_1c0310,d_1c0394);FIN
          default:FIN
          }
          break;
        case 2:M(0x2f0000a3);GO66(0)
        }
        break;
      case 5:
        do{answer=f_0bf820(D2C64,0x2f0000a6,2,0x2f0000a7,0x2f0000a8);}while(answer==-1);
        switch((unsigned short)answer){
        case 1:GO66(0)
        case 2:*(volatile signed char*)&d_1c030c=2;FIN // haelt die Schreibreihenfolge vor dem Destruktor wie im Original
        }
        break;
      }
      break;
    case 3:
      value=f_039ac0(d_1c0004,(int)(void*)f_1036b0);
      if(value){selection=3;SETB(value);}else selection=2;
      answer=f_0bf820(D2C64,0x2f0000ab,selection,0x2f0000ac,0x2f0000ad,0x2f0000ae);
      switch((unsigned short)answer){
      case 1:
        answer=f_0bf820(D2C64,0x2f0000af,3,0x2f0000b0,0x2f0000b1,0x2f0000b2);
        switch((unsigned short)answer){
        case 1:M(0x2f0000b3);GO66(2)
        case 2:M(0x2f0000b4);SETB(f_039660(d_1c0004,0xd));M(0x2f0000b5);GO66(0)
        default:if(f_0bf6f0(D2C64,0x2f0000b6)==1){M(0x2f0000b7);GO66(0)}break;
        }
        break;
      case 2:
        SETB(f_039660(d_1c0004,0));selection=f_0db940(d_1c0004);
        if(selection>1){M(0x2f0000b8);GO66(0)}else{M(0x2f0000b9);GO66(0)}
      case 3:
        M(0x2f0000ba);option=VCALL(p1,0x66,2);f_060a70();
        if(option==0)d_1c0394=1;
        f_091f70(9);goto scene_done;
      }
      break;
    }
    break;
  }
scene_done:
  OBDTOR;
#undef GO66
#undef GO65
#undef FIN
}
//@ f_105830
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zehn Methoden steuern Kämpfe (0x1f41 ff.), einmalige Raumbeschreibungen und das Durchsuchen von
 *   Truhen und Überresten in den oberen Wrackräumen von ship2.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Kampffunktionen geben das Ergebnis von f_05fa00 zurück; die übrigen Routinen haben keinen
 *   Rückgabewert (void).
 === Ende Beschreibung === */
void f_105830(void)
{
  if (f_0bf6f0(D2C64, 0x2f0000bb) == 1) f_0dd7f0(d_1c0004, 0x17, 0x1407);
}


#undef CT14
#undef D2C44
#undef D2C64
#undef D3498
#undef D349C
#undef D3870
#undef FIN
#undef FL
#undef GO65
#undef GO66
#undef M
#undef NEW0C
#undef NEW14
#undef OB
#undef OBCTOR
#undef OBDTOR
#undef S0C
#undef S14
#undef SETB
#undef VCALL
#undef VF
#undef d_1a6884
#undef d_1bf230
#undef d_1c0004
#undef d_1c02a0
#undef d_1c030c
#undef d_1c0310
#undef d_1c031c
#undef d_1c0324
#undef d_1c0328
#undef d_1c032c
#undef d_1c0330
#undef d_1c0334
#undef d_1c0338
#undef d_1c033c
#undef d_1c0340
#undef d_1c0344
#undef d_1c0348
#undef d_1c034c
#undef d_1c0350
#undef d_1c0354
#undef d_1c0358
#undef d_1c035c
#undef d_1c0360
#undef d_1c0368
#undef d_1c036c
#undef d_1c0394
#undef d_1c0398
#undef d_1c039c
#undef d_1c21b4
#undef d_1c27a8
#undef d_1c299c
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef d_1c38b0
#undef f_038c40
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_039ac0
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046ec0
#undef f_05fa00
#undef f_0606a0
#undef f_060770
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bde40
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf7b0
#undef f_0bf820
#undef f_0bfa20
#undef f_0bfea0
#undef f_0c0020
#undef f_0d54f0
#undef f_0d5ff0
#undef f_0db820
#undef f_0db8b0
#undef f_0db940
#undef f_0dbb20
#undef f_0dc3c0
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd410
#undef f_0dd750
#undef f_0dd7f0
#undef f_0e93f0

#undef f_0fb660
#undef f_0fbc60
#undef f_0fbe10
#undef f_0fbee0
#undef f_0fca60
#undef f_0fdbd0
#undef f_103530
#undef f_1036b0
#undef f_105860
#undef f_105cd0
#undef f_105dc0
#undef f_106300
#undef f_106440
#undef f_1065f0
#undef f_106e30
#undef f_106ef0
#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0
#undef f_1454d0
#undef f_1457e0
#undef ob

// ===== Teil ship2_t2 (p3, 105860-106e30) =====
#define d_1a6884 d_1a6884_k2
#define d_1bf230 d_1bf230_k2
#define d_1c0004 d_1c0004_k2
#define d_1c02a0 d_1c02a0_k2
#define d_1c030c d_1c030c_k2
#define d_1c0310 d_1c0310_k2
#define d_1c031c d_1c031c_k2
#define d_1c0324 d_1c0324_k2
#define d_1c0328 d_1c0328_k2
#define d_1c032c d_1c032c_k2
#define d_1c0330 d_1c0330_k2
#define d_1c0334 d_1c0334_k2
#define d_1c0338 d_1c0338_k2
#define d_1c033c d_1c033c_k2
#define d_1c0340 d_1c0340_k2
#define d_1c0344 d_1c0344_k2
#define d_1c0348 d_1c0348_k2
#define d_1c034c d_1c034c_k2
#define d_1c0350 d_1c0350_k2
#define d_1c0354 d_1c0354_k2
#define d_1c0358 d_1c0358_k2
#define d_1c035c d_1c035c_k2
#define d_1c0360 d_1c0360_k2
#define d_1c0368 d_1c0368_k2
#define d_1c036c d_1c036c_k2
#define d_1c0394 d_1c0394_k2
#define d_1c0398 d_1c0398_k2
#define d_1c039c d_1c039c_k2
#define d_1c21b4 d_1c21b4_k2
#define d_1c27a8 d_1c27a8_k2
#define d_1c299c d_1c299c_k2
#define d_1c2c44 d_1c2c44_k2
#define d_1c2c64 d_1c2c64_k2
#define d_1c3498 d_1c3498_k2
#define d_1c349c d_1c349c_k2
#define d_1c3870 d_1c3870_k2
#define d_1c38b0 d_1c38b0_k2
#define f_038c40 f_038c40_k2
#define f_039320 f_039320_k2
#define f_039420 f_039420_k2
#define f_039660 f_039660_k2
#define f_039ac0 f_039ac0_k2
#define f_044c90 f_044c90_k2
#define f_046d10 f_046d10_k2
#define f_046d90 f_046d90_k2
#define f_046de0 f_046de0_k2
#define f_046ec0 f_046ec0_k2
#define f_05fa00 f_05fa00_k2
#define f_0606a0 f_0606a0_k2
#define f_060770 f_060770_k2
#define f_060a70 f_060a70_k2
#define f_091f70 f_091f70_k2
#define f_0bbf00 f_0bbf00_k2
#define f_0bde40 f_0bde40_k2
#define f_0bf680 f_0bf680_k2
#define f_0bf6c0 f_0bf6c0_k2
#define f_0bf6f0 f_0bf6f0_k2
#define f_0bf730 f_0bf730_k2
#define f_0bf7b0 f_0bf7b0_k2
#define f_0bf820 f_0bf820_k2
#define f_0bfa20 f_0bfa20_k2
#define f_0bfea0 f_0bfea0_k2
#define f_0c0020 f_0c0020_k2
#define f_0d54f0 f_0d54f0_k2
#define f_0d5ff0 f_0d5ff0_k2
#define f_0db820 f_0db820_k2
#define f_0db8b0 f_0db8b0_k2
#define f_0db940 f_0db940_k2
#define f_0dbb20 f_0dbb20_k2
#define f_0dc3c0 f_0dc3c0_k2
#define f_0dcae0 f_0dcae0_k2
#define f_0dcbb0 f_0dcbb0_k2
#define f_0dcf00 f_0dcf00_k2
#define f_0dd410 f_0dd410_k2
#define f_0dd750 f_0dd750_k2
#define f_0dd7f0 f_0dd7f0_k2
#define f_0e93f0 f_0e93f0_k2

#define f_0fb660 f_0fb660_k2
#define f_0fbc60 f_0fbc60_k2
#define f_0fbe10 f_0fbe10_k2
#define f_0fbee0 f_0fbee0_k2
#define f_0fca60 f_0fca60_k2
#define f_0fdbd0 f_0fdbd0_k2
#define f_103530 f_103530_k2
#define f_112df0 f_112df0_k2
#define f_112e70 f_112e70_k2
#define f_112ec0 f_112ec0_k2
#define f_125400 f_125400_k2
#define f_1254a0 f_1254a0_k2
#define f_125ed0 f_125ed0_k2
#define f_133fe0 f_133fe0_k2
#define f_1454d0 f_1454d0_k2
#define f_1457e0 f_1457e0_k2
#define OB OB_k2
// P3 26/28 gleich (suche.py 25.10.2026, Basis ship2_t2_P1.CPP)
// ship2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1036F0-0x107200
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046ec0(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db940(int p1);                                   // reg eax stapel 0
int f_0dbb20(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc3c0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_0fbe10();                                         // reg - stapel 0
int f_0fbee0(int p1, int p2);                           // reg eax edx stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_103530(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c02a0;
extern int d_1c030c;                    // 0x1C030C
extern int d_1c0310;                    // 0x1C0310
extern int d_1c031c;                    // 0x1C031C
extern signed char d_1c0324;
extern signed char d_1c0328;
extern signed char d_1c032c;
extern signed char d_1c0330;
extern signed char d_1c0334;
extern signed char d_1c0338;
extern signed char d_1c033c;
extern signed char d_1c0340;
extern signed char d_1c0344;
extern signed char d_1c0348;
extern signed char d_1c034c;
extern signed char d_1c0350;
extern int d_1c0354;                    // 0x1C0354
extern int d_1c0358;                    // 0x1C0358
extern int d_1c035c;                    // 0x1C035C
extern signed char d_1c0360;
extern signed char d_1c0368;
extern int d_1c036c;                    // 0x1C036C
extern int d_1c0394;                    // 0x1C0394
extern int d_1c0398;                    // 0x1C0398
extern signed char d_1c039c;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c299c[];
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a6884[];           // Text 0x1A6884
// --- eigene Funktionen (43), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_0bf820(int, ...);
int f_0bfa20(int, ...);
int f_1254a0(int, int);
int f_0fdbd0(int);
int f_0fbc60(int);
int f_0d5ff0(int);
signed char f_0dd410(int, int);
#define DB ((int)&d_1c2c64)
#define EQM(x,v) (((x)==(v))?1:0)
typedef RivaTextContextData OB;
#define CTOR(o) f_125400((int)&(o), (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498)
#define DTOR(o) f_1254a0((int)&(o), 0)
typedef int (*FP3)(int, int, int);

//@ f_105860
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Stellt im Dialogmodus 5 die Frage 0x2f0000bc (f_0bf6f0). Stimmt der Spieler zu, wird
 *   beim ersten Mal (d_1c0328 == 0, setzt d_1c0328 = 1) eine 4-teilige Bildsequenz (f_0606a0 Bilder 6..9 mit
 *   Texten 0x2f0000bd..0x2f0000c0 über f_0bfa20), sonst Bild 9 mit Text 0x2f0000c1 gezeigt; danach folgt das
 *   4-Wege-Auswahlmenü 0x2f010001 (f_0bf820), das bei Wahl 1..3 f_0fbee0(p1, r) aufruft.
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0328, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Aufgerufen bei Ereignis 0xca in f_1036f0.
 === Ende Beschreibung === */
void f_105860(int p1)
{
    OB o;
    int t;
    short r;
    CTOR(o);
    *(int *)(o.addresses.objects + 4) = f_038c40(d_1c0004);
    f_0bf6c0(DB, 5);
    if (f_0bf6f0(DB, 0x2f0000bc) == 1) {
        if (EQM(d_1c0328, 0)) {
            d_1c0328 = 1;
            t = f_0606a0(0x2f0002, 6);
            f_0bfa20(DB, t, 0, 0x2f0000bd, 0);
            if (t != 0) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
            t = f_0606a0(0x2f0002, 7);
            f_0bfa20(DB, t, 0, 0x2f0000be, 0);
            if (t != 0) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
            t = f_0606a0(0x2f0002, 8);
            f_0bfa20(DB, t, 0, 0x2f0000bf, 0);
            if (t) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
            t = f_0606a0(0x2f0002, 9);
            f_0bfa20(DB, t, 0, 0x2f0000c0, 0);
            if (t) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
        } else {
            t = f_0606a0(0x2f0002, 9);
            f_0bfa20(DB, t, 0, 0x2f0000c1, 0);
            if (t) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
        }
        r = f_0bf820(DB, 0x2f010001, 4, 0x2f010002, 0x2f010003, 0x2f010004, 0x2f010005);
        if (r != -1 && r != 4)
            f_0fbee0(p1, r);
    }
    f_0bf680(DB);
    DTOR(o);
}

//@ f_105a50
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Leere Platzhalter- bzw. No-Op-Funktion in ship2.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Keine.
 * - Besonderheiten: Besteht im Original nur aus ret.
 === Ende Beschreibung === */
void f_105a50(void)
{
}

//@ f_105a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f0000c2 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0xcb / 0xcc in f_1036f0.
 === Ende Beschreibung === */
void f_105a60(void)
{
    f_0bf730(DB, 0x2f0000c2);
}

//@ f_105a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Leere Platzhalter- bzw. No-Op-Funktion in ship2.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Keine.
 * - Besonderheiten: Entspricht case 0xcd in f_1036f0.
 === Ende Beschreibung === */
void f_105a80(void)
{
}
//@ f_105aa0  (versteckt)
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Fragt über f_0bf6f0 mit Text 0x2f0000c3 nach; bei Zustimmung (1) wird per
 *   Zufallswurf f_1457e0(5) - 1 einer von fünf Fällen gewählt: Fälle 0..3 zeigen die Texte
 *   0x2f0000c4..0x2f0000c7, Fall 4 fragt 0x2f0000c8 ab, liest über f_0bf7b0 (0x2f0000c9) eine Anzahl bis 0x50
 *   ein und übergibt entsprechend viele Exemplare von Gegenstand 0x1c (f_0dcf00). Abschließend wird
 *   f_125ed0(&d_1c2c44, 3) aufgerufen.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004, d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Entspricht case 0xce in f_1036f0.
 === Ende Beschreibung === */
void f_105aa0(void)
{
    short v;
    unsigned short k;
    if (f_0bf6f0(DB, 0x2f0000c3) == 1) {
        switch ((unsigned short)(f_1457e0(5) - 1)) {
        case 0: f_0bf730(DB, 0x2f0000c4); break;
        case 1: f_0bf730(DB, 0x2f0000c5); break;
        case 2: f_0bf730(DB, 0x2f0000c6); break;
        case 3: f_0bf730(DB, 0x2f0000c7); break;
        case 4:
            if (f_0bf6f0(DB, 0x2f0000c8) == 1) {
                v = f_0bf7b0(DB, 2, 0x2f0000c9, 0, 0x50, 0);
                f_0dcf00(d_1c0004, 0x1c, v);
            }
            break;
        }
    }
    f_125ed0((int)&d_1c2c44, 3);
}

//@ f_105bd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000ca über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0xcf in f_1036f0.
 === Ende Beschreibung === */
void f_105bd0(void)
{
    f_0bf730(DB, 0x2f0000ca);
}

//@ f_105bf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000cb über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0xd0 in f_1036f0.
 === Ende Beschreibung === */
void f_105bf0(void)
{
    f_0bf730(DB, 0x2f0000cb);
}

//@ f_105c10
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000cc über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0xd1 in f_1036f0.
 === Ende Beschreibung === */
void f_105c10(void)
{
    f_0bf730(DB, 0x2f0000cc);
}

//@ f_105c30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ermittelt einen Helden über f_039660(d_1c0004, 0xc), gibt Text 0x2f0000cd aus und
 *   zeigt beim ersten Mal (d_1c0324 == 0, setzt d_1c0324 = 1) den Folgetext 0x2f0000ce mit Status-Update
 *   f_125ed0(&d_1c2c44, 2) bzw. bei Wiederholung 0x2f0000cf mit Status-Update 1 an.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0324, nutzt d_1c0004, d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Entspricht case 0xd2 in f_1036f0.
 === Ende Beschreibung === */
void f_105c30(void)
{
    OB ob;
    int k;
    CTOR(ob);
    *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 0xc);
    f_0bf730(DB, 0x2f0000cd);
    if (EQM(d_1c0324, 0)) {
        d_1c0324 = 1;
        f_0bf730(DB, 0x2f0000ce);
        k = 2;
    } else {
        f_0bf730(DB, 0x2f0000cf);
        k = 1;
    }
    f_125ed0((int)&d_1c2c44, k);
    DTOR(ob);
}

//@ f_105cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Öffnen eines versperrten Durchgangs (Ereignis 0x3f, Zustand d_1c0360) zum
 *   nächsten Wrackabschnitt (0x2b, Startpunkt 0x1f42): Ist der Durchgang bereits frei (d_1c0360 == 2), wechselt
 *   die Gruppe sofort hinüber; andernfalls wird eine Auswahlbox (0x2f0000d0 beim ersten Mal bzw. 0x2f0000d1 bei
 *   Wiederholung) angezeigt und geprüft, ob die Helden den benötigten Gegenstand 0x68 einsetzen, woraufhin
 *   d_1c0360 = 2 gesetzt und die Sperre (0x14bd) geöffnet wird.
 *   - Hinweis (Originalfehler): Während in RIVADEMO.EXE (0fe9f0) noch korrekt geprüft wurde, ob d_1c0360 == 0
 *     ist, um zwischen Erstbesuch (0x2f0000d0 samt Setzen von d_1c0360 = 1) und Folgebesuch (0x2f0000d1) zu
 *     unterscheiden, testet der Code in RIVA.EXE nach dem neu eingefügten if (d_1c0360 == 2)-Check versehentlich
 *     eine nicht initialisierte lokale 16-Bit-Variable u (105cfe: movsx eax, dx; test eax, eax; jne 0x105d39).
 *     Da edx beim Aufruf aus f_1036f0 (mov eax, ebx; call 0x105cd0) nicht gesetzt wird, hängt die Wahl des
 *     Dialogtextes vom zufälligen Restwert im Register dx ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_105cd0(int p1)
{
    short r;
    short s2;
    short u;
    if (EQM(d_1c0360, 2)) {
        f_05fa00(0x2b, 0x1f42);
        return;
    }
    if (u == 0) {
        d_1c0360 = 1;
        f_0bf6c0(DB, 5);
        r = f_0bf6f0(DB, 0x2f0000d0);
        f_0bf680(DB);
    } else {
        r = f_0bf6f0(DB, 0x2f0000d1);
    }
    if (r == (short)1) {
        s2 = (short)(**(FP3 **)(p1 + 8))(p1, 0x68, 2);
        if (s2 == 0) {
            d_1c0360 = 2;
            f_0dd750(d_1c0004, 0x14bd);
        }
    }
}

//@ f_105d90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese neunundzwanzig Methoden verwalten die übrigen Kabinen, Frachträume, Kämpfe und Schatzfunde in
 *   ship2, darunter die große Kapitänskajüten-Untersuchung (f_105dc0, f_1065f0), mehrere Beutekisten (f_106c30
 *   bis f_107070) sowie Kämpfe gegen Meeresbewohner (f_107140 bis f_107180).
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Kampffunktionen geben das Ergebnis von f_05fa00 zurück; die Untersuchungsfunktionen haben
 *   keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_105d90(void)
{
    if (EQM(d_1c039c, 0)) {
        f_0bf730(DB, 0x2f0000d3);
        d_1c039c = 1;
    }
}

//@ f_105dc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Führt bei d_1c032c == 0 (d_1c032c = 1) eine mehrstufige Rätsel- und Dialogszene mit
 *   Bild f_0606a0(0x2f0002, 0x12) durch: Wählt der Spieler im Menü 0x2f0000d6 Option 1, erleidet die Gruppe
 *   Abzüge (f_0dc3c0, f_0dbb20, f_0bbf00); bei Option 2 werden nacheinander zwei Rätsel über f_103530 und eine
 *   dritte Texteingabe (0x2f0000e8, f_0bfea0) geprüft, die bei Erfolg Belohnungen (0x92, 0x128 über f_0dcf00),
 *   Abenteuerpunkte (f_0dcbb0), Soundeffekte (f_091f70) und d_1c0368 = 6 freischalten.
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c032c und d_1c0368, nutzt d_1c0004, d_1c2c64, d_1c299c,
 *   d_1c21b4, d_1c27a8.
 * - Besonderheiten: Große dreistufige Rätselsequenz (aufgerufen bei case 0xd5 in f_1036f0).
 === Ende Beschreibung === */
void f_105dc0(int p1)
{
    OB ob;
    char buf[52];
    char *lp;
    int sv;
    int p;
    int k;
    int fl;
    short s;
    if (EQM(d_1c032c, 0)) {
        lp = d_1c299c;
        CTOR(ob);
        d_1c032c = 1;
        *(int *)(ob.addresses.numbers + 4) = 0x2f0000da;
        p = f_0606a0(0x2f0002, 0x12);
        sv = f_0c0020(DB, 6);
        f_0bfa20(DB, p, 0, 0x2f0000d4, 0);
        f_0bfa20(DB, p, 0, 0x2f0000d5, 0);
        do {
            s = f_0bfa20(DB, p, 0, 0x2f0000d6, 2, 0x2f0000d7, 0x2f0000d8);
        } while (s == -1);
        if (s == 1) {
            f_0c0020(DB, (short)sv);
            f_0bf730(DB, 0x2f0000d9);
            f_0dc3c0(d_1c0004, 0x2a30, 6, -4, 0);
            f_0dc3c0(d_1c0004, 0x2a30, 2, -3, 0);
            f_0dbb20(d_1c0004, 1);
            f_0bbf00((int)&d_1bf230);
        } else {
            if (f_103530(p1, 0x2f0000db, 0x2f0000dd, 0x2f0000dc, 0x2f0000de) == 0) {
                k = 0x2f0000df;
            } else {
                f_091f70(6);
                f_0bfa20(DB, p, 0, 0x2f0000e0, 0);
                f_0dcf00(d_1c0004, 0x92, 1);
                f_0dcbb0(d_1c0004, 5);
                if (f_103530(p1, 0x2f0000e1, 0x2f0000e3, 0x2f0000e2, 0x2f0000e4) == 0) {
                    k = 0x2f0000e5;
                } else {
                    f_091f70(7);
                    f_0bfa20(DB, p, 0, 0x2f0000e6, 0);
                    f_0dcf00(d_1c0004, 0x128, 1);
                    f_0dcbb0(d_1c0004, 10);
                    f_0e93f0((int)&d_1c38b0, (int)buf, 0x2f0000e8);
                    f_1454d0((int)buf);
                    f_0bfea0(DB, (short)strlen(buf), 0x2f0000e7);
                    if (strcmp(buf, lp) == 0) {
                        f_091f70(8);
                        f_0e93f0((int)&d_1c38b0, (int)d_1c21b4, 0x2f0000eb);
                        f_0dcbb0(d_1c0004, 0xf);
                        d_1c0368 = 6;
                        fl = 1;
                    } else {
                        f_0e93f0((int)&d_1c38b0, (int)d_1c21b4, 0x2f0000e9);
                        fl = 0;
                    }
                    if (fl == 0) {
                        f_0e93f0((int)&d_1c38b0, (int)d_1c27a8, 0x2f0000ea);
                        strcat(d_1c21b4, d_1c27a8);
                    }
                    k = f_133fe0((int)&d_1c3498, (int)d_1c21b4);
                }
            }
            f_0bf730(DB, k);
        }
        f_0c0020(DB, (short)sv);
        if (p) operator delete((void *)((int)(((RivaRasterImage*)(p))->f_0fad20( 0))));
        DTOR(ob);
    }
}

//@ f_106120
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ermittelt einen Helden mit Talent 0x25 (f_039320), trägt ihn in den lokalen
 *   Textkontext ein und gibt die Meldung 0x2f0000ec über f_0bf730 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Entspricht case 0x12d in f_1036f0.
 === Ende Beschreibung === */
void f_106120(void)
{
    OB ob;
    CTOR(ob);
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x25);
    f_0bf730(DB, 0x2f0000ec);
    DTOR(ob);
}

//@ f_106180
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000ed über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x12e in f_1036f0.
 === Ende Beschreibung === */
void f_106180(void)
{
    f_0bf730(DB, 0x2f0000ed);
}

//@ f_1061a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000ee über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x12f in f_1036f0.
 === Ende Beschreibung === */
void f_1061a0(void)
{
    f_0bf730(DB, 0x2f0000ee);
}

//@ f_1061c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x3a (f_046d10, Zeile 0x899), führt f_046de0 aus und
 *   gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x130 in f_1036f0.
 === Ende Beschreibung === */
void f_1061c0(void)
{
    int p1;
    int t;
    t = (int)operator new(0xc, mark(d_1a6884, 0x899)); p1 = (t != 0) ? f_046d10(t, 0x3a) : t;
    f_046de0(p1);
    if (p1) operator delete((void *)f_046d90(p1, 0));
}

//@ f_106210
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x3b (f_046d10, Zeile 0x8ab), führt f_046de0 aus und
 *   gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x131 in f_1036f0.
 === Ende Beschreibung === */
void f_106210(void)
{
    int p1;
    int t;
    t = (int)operator new(0xc, mark(d_1a6884, 0x8ab)); p1 = (t != 0) ? f_046d10(t, 0x3b) : t;
    f_046de0(p1);
    if (p1) operator delete((void *)f_046d90(p1, 0));
}

//@ f_106260
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x3c (f_046d10, Zeile 0x8bd), führt f_046de0 aus und
 *   gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x132 in f_1036f0.
 === Ende Beschreibung === */
void f_106260(void)
{
    int p1;
    int t;
    t = (int)operator new(0xc, mark(d_1a6884, 0x8bd)); p1 = (t != 0) ? f_046d10(t, 0x3c) : t;
    f_046de0(p1);
    if (p1) operator delete((void *)f_046d90(p1, 0));
}

//@ f_1062b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x3d (f_046d10, Zeile 0x8cf), führt f_046de0 aus und
 *   gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x133 in f_1036f0.
 === Ende Beschreibung === */
void f_1062b0(void)
{
    int p1;
    int t;
    t = (int)operator new(0xc, mark(d_1a6884, 0x8cf)); p1 = (t != 0) ? f_046d10(t, 0x3d) : t;
    f_046de0(p1);
    if (p1) operator delete((void *)f_046d90(p1, 0));
}

//@ f_106300
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet das 12-Byte-Beuteobjekt 0x3e (f_046d10, Zeile 0x8e4). Ist Inhalt vorhanden
 *   (f_046ec0 == 1), wird beim ersten Mal (d_1c0330 == 0, setzt d_1c0330 = 1) ein Held über f_039320(d_1c0004,
 *   0x20) bestimmt und Text 0x2f0000ef ausgegeben, bevor f_046de0 ausgeführt wird.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0330, nutzt d_1c0004, d_1c2c64 und d_1a6884.
 * - Besonderheiten: Aufgerufen bei case 0x134 in f_1036f0.
 === Ende Beschreibung === */
void f_106300(void)
{
    OB ob;
    int p1;
    int t;
    CTOR(ob);
    p1 = (int)operator new(0xc, mark(d_1a6884, 0x8e4));
    p1 = p1 ? f_046d10(p1, 0x3e) : 0;
    if (f_046ec0(p1) == 1) {
        if (EQM(d_1c0330, 0)) {
            d_1c0330 = 1;
            *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x20);
            f_0bf730(DB, 0x2f0000ef);
        }
        f_046de0(p1);
    }
    if (p1) operator delete((void *)f_046d90(p1, 0));
    DTOR(ob);
}

//@ f_1063c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c0334 == 0, setzt d_1c0334 = 1) den Text 0x2f0000f0,
 *   sonst 0x2f0000f1 aus und öffnet anschließend das 20-Byte-Behälterobjekt 0x56 (f_112df0, Zeile 0x90e).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0334, nutzt d_1c2c64 und d_1a6884.
 * - Besonderheiten: Entspricht case 0x191 in f_1036f0.
 === Ende Beschreibung === */
void f_1063c0(void)
{
    int p1;
    int t;
    int k;
    if (EQM(d_1c0334, 0)) {
        k = 0x2f0000f0;
        d_1c0334 = 1;
    } else {
        k = 0x2f0000f1;
    }
    f_0bf730(DB, k);
    t = (int)operator new(0x14, mark(d_1a6884, 0x90e)); p1 = (t != 0) ? f_112df0(t, 0x56, 0, 0) : t;
    f_112ec0(p1);
    if (p1) operator delete((void *)f_112e70(p1, 0));
}

//@ f_106440
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Zeigt beim ersten Aufruf (d_1c0338 == 0, setzt d_1c0338 = 1) im Dialogmodus 5 mit
 *   zwei Helden (f_039660(..., 0xc) und f_039320(..., 0x1d)) die Texte 0x2f0000f2 und 0x2f0000f3, bei
 *   Folgebesuchen 0x2f0000f4 an und öffnet danach das 20-Byte-Behälterobjekt 0x57 (f_112df0, Zeile 0x931).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0338, nutzt d_1c0004, d_1c2c64 und d_1a6884.
 * - Besonderheiten: Aufgerufen bei case 0x192 in f_1036f0.
 === Ende Beschreibung === */
void f_106440(void)
{
    OB ob;
    int p1;
    int t;
    CTOR(ob);
    if (EQM(d_1c0338, 0)) {
        d_1c0338 = 1;
        *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 0xc);
        *(int *)(ob.addresses.objects + 8) = f_039320(d_1c0004, 0x1d);
        f_0bf6c0(DB, 5);
        f_0bf730(DB, 0x2f0000f2);
        f_0bf730(DB, 0x2f0000f3);
        f_0bf680(DB);
    } else {
        f_0bf730(DB, 0x2f0000f4);
    }
    t = (int)operator new(0x14, mark(d_1a6884, 0x931)); p1 = (t != 0) ? f_112df0(t, 0x57, 0, 0) : t;
    f_112ec0(p1);
    if (p1) operator delete((void *)f_112e70(p1, 0));
    DTOR(ob);
}

//@ f_106550
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000f5 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x193 in f_1036f0.
 === Ende Beschreibung === */
void f_106550(void)
{
    f_0bf730(DB, 0x2f0000f5);
}

//@ f_106570
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f0000f6 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x194 in f_1036f0.
 === Ende Beschreibung === */
void f_106570(void)
{
    f_0bf730(DB, 0x2f0000f6);
}

//@ f_106590
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt das 12-Byte-Beuteobjekt 0x3f (f_046d10, Zeile 0x95f), führt f_046de0 aus und
 *   gibt das Objekt über f_046d90 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a6884 für mark.
 * - Besonderheiten: Entspricht case 0x195 in f_1036f0.
 === Ende Beschreibung === */
void f_106590(void)
{
    int p1;
    int t;
    t = (int)operator new(0xc, mark(d_1a6884, 0x95f)); p1 = (t != 0) ? f_046d10(t, 0x3f) : t;
    f_046de0(p1);
    if (p1) operator delete((void *)f_046d90(p1, 0));
}

//@ f_1065f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Startet zunächst den Kampf 0x30 (0x1f47) über f_05fa00 und führt danach - sofern
 *   d_1c0340 == 0 ist - einen zustandsgesteuerten Dialogautomaten (st = 1, 6, 8, 9, 0x10, 0x1b) mit Porträtbild
 *   f_0606a0(0x2f0002, 0x13) aus, in dem der Spieler Fragen stellen (0x2f0000f7..0x2f000113), Gegenstand 0x5a
 *   (21 Stück über f_0dcf00, Flag d_1c0344 = 1) erhalten oder Aktionen wie f_0fdbd0(p1), f_0fbc60(p1) und
 *   f_0d5ff0(5) (d_1c02a0 = 1) auslösen kann.
 * - Eingaben / Rückgabe: p1 (int, this-Zeiger). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c02a0, d_1c033c, d_1c0340, d_1c0344, nutzt d_1c0004 und
 *   d_1c2c64.
 * - Besonderheiten: Aufgerufen bei case 0x1f47 in f_1036f0.
 === Ende Beschreibung === */
void f_1065f0(int p1)
{
    OB ob;
    int p;
    short st;
    short r;
    short s;
    signed char c;
    CTOR(ob);
    f_05fa00(0x30, 0x1f47);
    if (EQM(d_1c0340, 0)) {
        p = f_0606a0(0x2f0002, 0x13);
        if (EQM(d_1c02a0, 2)) st = 1; else st = 0x1b;
        while (st != -1) {
            switch ((unsigned short)st) {
            case 1:
                if (EQM(d_1c033c, 0) && EQM(d_1c02a0, 2))
                    r = f_0bfa20(DB, p, 0, 0x2f0000f7, 4, 0x2f0000f8, 0x2f0000f9, 0x2f0000fa, 0x2f0000fb);
                switch ((unsigned short)r) {
                case 2: st = 8; break;
                case 3: set_st9: st = 9; break;
                case 4: st = 0x10; break;
                default: set_st6: st = 6; break;
                }
                break;
            case 6:
                if (EQM(d_1c02a0, 2)) {
                    r = f_0bf820(DB, 0x2f0000fc, 4, 0x2f0000f8, 0x2f0000f9, 0x2f0000fa, 0x2f0000fb);
                } else {
                    r = f_0bf820(DB, 0x2f0000fc, 2, 0x2f0000f8, 0x2f0000fa);
                    if (r == 2) r = 3;
                }
                d_1c033c = 1;
                switch ((unsigned short)r) {
                case 2: st = 8; break;
                case 3: st = 9; break;
                case 4: st = 0x10; break;
                default:
                    f_0bf730(DB, 0x2f0000fd);
                    f_0fbc60(p1);
                    st = -1;
                    break;
                }
                break;
            case 8:
                f_0fdbd0(p1);
                *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 6);
                r = f_0bf820(DB, 0x2f0000fe, 2, 0x2f0000f8, 0x2f0000fa);
                if (r == (short)2) {
                    goto set_st9;
                } else {
                    d_1c033c = 1;
                    st = 6;
                }
                break;
            case 9:
                if (EQM(d_1c0340, 0)) {
                    r = f_0bf820(DB, 0x2f0000ff, 3, 0x2f000100, 0x2f000101, 0x2f000102);
                    d_1c0340 = 1;
                } else {
                    r = f_0bf820(DB, 0x2f000110, 3, 0x2f000100, 0x2f000101, 0x2f000102);
                }
                switch ((unsigned short)r) {
                case 1: f_0bf730(DB, 0x2f000103); break;
                case 2: f_0bf730(DB, 0x2f000104); break;
                case 3: f_0bf730(DB, 0x2f000105); st = -1; break;
                }
                break;
            case 0x10:
                if (EQM(d_1c0340, 0)) {
                    do {
                        r = f_0bf820(DB, 0x2f000106, 4, 0x2f000107, 0x2f000108, 0x2f000109, 0x2f00010a);
                    } while (r == -1);
                    d_1c0340 = 1;
                } else if (EQM(d_1c0344, 0)) {
                    do {
                        r = f_0bf820(DB, 0x2f000110, 4, 0x2f000107, 0x2f000108, 0x2f000109, 0x2f00010a);
                    } while (r == -1);
                } else {
                    do {
                        s = f_0bf820(DB, 0x2f000110, 4, 0x2f000108, 0x2f000109, 0x2f00010a);
                    } while (s == -1);
                    r = s + 1;
                }
                switch ((unsigned short)(r - 1)) {
                case 0:
                    if (f_0bf6f0(DB, 0x2f00010b) != 1) break;
                    f_0dcf00(d_1c0004, 0x5a, 0x15);
                    d_1c0344 = 1;
                    break;
                case 1:
                    f_0bf730(DB, 0x2f00010c);
                    break;
                case 2:
                    if (EQM(d_1c0344, 1)) {
                        f_0bf730(DB, 0x2f00010e);
                        break;
                    }
                    if (f_0bf6f0(DB, 0x2f00010f) != 1) break;
                    f_0d5ff0(5);
                    d_1c02a0 = 1;
                    st = 9;
                    break;
                case 3:
                    f_0bf730(DB, 0x2f00010d);
                    st = -1;
                    break;
                }
                break;
            case 0x1b:
                c = f_0dd410(d_1c0004, 1);
                *(int *)(ob.addresses.numbers + 4) = (c != 5) + 0x2f000111;
                r = f_0bf820(DB, 0x2f000113, 2, 0x2f0000f8, 0x2f0000fa);
                if (r == (short)2) goto set_st9; else goto set_st6;
                break;
            }
        }
        if (p) operator delete((void *)((int)(((RivaRasterImage*)(p))->f_0fad20( 0))));
    }
    DTOR(ob);
}

//@ f_106c30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c0348 == 0, setzt d_1c0348 = 1) den Text 0x2f000114 aus
 *   und öffnet anschließend das 20-Byte-Behälterobjekt 0x58 (f_112df0, Zeile 0xa8a).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0348, nutzt d_1c2c64 und d_1a6884.
 * - Besonderheiten: Entspricht case 0x1f5 in f_1036f0.
 === Ende Beschreibung === */
void f_106c30(void)
{
    int p1;
    int t;
    if (EQM(d_1c0348, 0)) {
        d_1c0348 = 1;
        f_0bf730(DB, 0x2f000114);
    }
    t = (int)operator new(0x14, mark(d_1a6884, 0xa8a)); p1 = (t != 0) ? f_112df0(t, 0x58, 0, 0) : t;
    f_112ec0(p1);
    if (p1) operator delete((void *)f_112e70(p1, 0));
}

//@ f_106cb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c034c == 0, setzt d_1c034c = 1) den Text 0x2f000115 aus
 *   und öffnet anschließend das 20-Byte-Behälterobjekt 0x59 (f_112df0, Zeile 0xaa3).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c034c, nutzt d_1c2c64 und d_1a6884.
 * - Besonderheiten: Entspricht case 0x1f6 in f_1036f0.
 === Ende Beschreibung === */
void f_106cb0(void)
{
    int p1;
    int t;
    if (EQM(d_1c034c, 0)) {
        d_1c034c = 1;
        f_0bf730(DB, 0x2f000115);
    }
    t = (int)operator new(0x14, mark(d_1a6884, 0xaa3)); p1 = (t != 0) ? f_112df0(t, 0x59, 0, 0) : t;
    f_112ec0(p1);
    if (p1) operator delete((void *)f_112e70(p1, 0));
}

//@ f_106d30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt beim ersten Aufruf (d_1c0350 == 0, setzt d_1c0350 = 1) den Text 0x2f000116 aus
 *   und öffnet anschließend das 20-Byte-Behälterobjekt 0x5a (f_112df0, Zeile 0xabc).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0350, nutzt d_1c2c64 und d_1a6884.
 * - Besonderheiten: Entspricht case 0x1f7 in f_1036f0.
 === Ende Beschreibung === */
void f_106d30(void)
{
    int p1;
    int t;
    if (EQM(d_1c0350, 0)) {
        d_1c0350 = 1;
        f_0bf730(DB, 0x2f000116);
    }
    t = (int)operator new(0x14, mark(d_1a6884, 0xabc)); p1 = (t != 0) ? f_112df0(t, 0x5a, 0, 0) : t;
    f_112ec0(p1);
    if (p1) operator delete((void *)f_112e70(p1, 0));
}

//@ f_106db0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft über f_0d54f0(d_1c0004, 0x1e), ob die Gruppe Gegenstand 0x1e besitzt, setzt
 *   abhängig davon den Textbaustein 0x2f000118 (>= 0) oder 0x20000194 in den lokalen Kontext ein, gibt die
 *   Meldung 0x2f000117 über f_0bf730 aus und ruft f_0dcae0(d_1c0004) auf.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Entspricht case 0x1f8 in f_1036f0.
 === Ende Beschreibung === */
void f_106db0(void)
{
    OB ob;
    short s;
    CTOR(ob);
    s = f_0d54f0(d_1c0004, 0x1e);
    if (s >= 0)
        *(int *)(ob.addresses.numbers + 4) = 0x2f000118;
    else
        *(int *)(ob.addresses.numbers + 4) = 0x20000194;
    f_0bf730(DB, 0x2f000117);
    f_0dcae0(d_1c0004);
    DTOR(ob);
}

#undef CTOR
#undef DB
#undef DTOR
#undef EQM
#undef OB
#undef d_1a6884
#undef d_1bf230
#undef d_1c0004
#undef d_1c02a0
#undef d_1c030c
#undef d_1c0310
#undef d_1c031c
#undef d_1c0324
#undef d_1c0328
#undef d_1c032c
#undef d_1c0330
#undef d_1c0334
#undef d_1c0338
#undef d_1c033c
#undef d_1c0340
#undef d_1c0344
#undef d_1c0348
#undef d_1c034c
#undef d_1c0350
#undef d_1c0354
#undef d_1c0358
#undef d_1c035c
#undef d_1c0360
#undef d_1c0368
#undef d_1c036c
#undef d_1c0394
#undef d_1c0398
#undef d_1c039c
#undef d_1c21b4
#undef d_1c27a8
#undef d_1c299c
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef d_1c38b0
#undef f_038c40
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_039ac0
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046ec0
#undef f_05fa00
#undef f_0606a0
#undef f_060770
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bde40
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf7b0
#undef f_0bf820
#undef f_0bfa20
#undef f_0bfea0
#undef f_0c0020
#undef f_0d54f0
#undef f_0d5ff0
#undef f_0db820
#undef f_0db8b0
#undef f_0db940
#undef f_0dbb20
#undef f_0dc3c0
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd410
#undef f_0dd750
#undef f_0dd7f0
#undef f_0e93f0

#undef f_0fb660
#undef f_0fbc60
#undef f_0fbe10
#undef f_0fbee0
#undef f_0fca60
#undef f_0fdbd0
#undef f_103530
#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0
#undef f_1454d0
#undef f_1457e0

// ===== Teil ship2_t3 (p3, 106e30-107200) =====
#define d_1a6884 d_1a6884_k3
#define d_1bf230 d_1bf230_k3
#define d_1c0004 d_1c0004_k3
#define d_1c02a0 d_1c02a0_k3
#define d_1c030c d_1c030c_k3
#define d_1c0310 d_1c0310_k3
#define d_1c031c d_1c031c_k3
#define d_1c0324 d_1c0324_k3
#define d_1c0328 d_1c0328_k3
#define d_1c032c d_1c032c_k3
#define d_1c0330 d_1c0330_k3
#define d_1c0334 d_1c0334_k3
#define d_1c0338 d_1c0338_k3
#define d_1c033c d_1c033c_k3
#define d_1c0340 d_1c0340_k3
#define d_1c0344 d_1c0344_k3
#define d_1c0348 d_1c0348_k3
#define d_1c034c d_1c034c_k3
#define d_1c0350 d_1c0350_k3
#define d_1c0354 d_1c0354_k3
#define d_1c0358 d_1c0358_k3
#define d_1c035c d_1c035c_k3
#define d_1c0360 d_1c0360_k3
#define d_1c0368 d_1c0368_k3
#define d_1c036c d_1c036c_k3
#define d_1c0394 d_1c0394_k3
#define d_1c0398 d_1c0398_k3
#define d_1c039c d_1c039c_k3
#define d_1c21b4 d_1c21b4_k3
#define d_1c27a8 d_1c27a8_k3
#define d_1c299c d_1c299c_k3
#define d_1c2c44 d_1c2c44_k3
#define d_1c2c64 d_1c2c64_k3
#define d_1c3498 d_1c3498_k3
#define d_1c349c d_1c349c_k3
#define d_1c3870 d_1c3870_k3
#define d_1c38b0 d_1c38b0_k3
#define f_038c40 f_038c40_k3
#define f_039320 f_039320_k3
#define f_039420 f_039420_k3
#define f_039660 f_039660_k3
#define f_039ac0 f_039ac0_k3
#define f_044c90 f_044c90_k3
#define f_046d10 f_046d10_k3
#define f_046d90 f_046d90_k3
#define f_046de0 f_046de0_k3
#define f_046ec0 f_046ec0_k3
#define f_05fa00 f_05fa00_k3
#define f_0606a0 f_0606a0_k3
#define f_060770 f_060770_k3
#define f_060a70 f_060a70_k3
#define f_091f70 f_091f70_k3
#define f_0bbf00 f_0bbf00_k3
#define f_0bde40 f_0bde40_k3
#define f_0bf680 f_0bf680_k3
#define f_0bf6c0 f_0bf6c0_k3
#define f_0bf6f0 f_0bf6f0_k3
#define f_0bf730 f_0bf730_k3
#define f_0bf7b0 f_0bf7b0_k3
#define f_0bf820 f_0bf820_k3
#define f_0bfa20 f_0bfa20_k3
#define f_0bfea0 f_0bfea0_k3
#define f_0c0020 f_0c0020_k3
#define f_0d54f0 f_0d54f0_k3
#define f_0d5ff0 f_0d5ff0_k3
#define f_0db820 f_0db820_k3
#define f_0db8b0 f_0db8b0_k3
#define f_0db940 f_0db940_k3
#define f_0dbb20 f_0dbb20_k3
#define f_0dc3c0 f_0dc3c0_k3
#define f_0dcae0 f_0dcae0_k3
#define f_0dcbb0 f_0dcbb0_k3
#define f_0dcf00 f_0dcf00_k3
#define f_0dd410 f_0dd410_k3
#define f_0dd750 f_0dd750_k3
#define f_0dd7f0 f_0dd7f0_k3
#define f_0e93f0 f_0e93f0_k3

#define f_0fb660 f_0fb660_k3
#define f_0fbc60 f_0fbc60_k3
#define f_0fbe10 f_0fbe10_k3
#define f_0fbee0 f_0fbee0_k3
#define f_0fca60 f_0fca60_k3
#define f_0fdbd0 f_0fdbd0_k3
#define f_103530 f_103530_k3
#define f_1036b0 f_1036b0_k3
#define f_104980 f_104980_k3
#define f_105860 f_105860_k3
#define f_105cd0 f_105cd0_k3
#define f_105dc0 f_105dc0_k3
#define f_106300 f_106300_k3
#define f_106440 f_106440_k3
#define f_1065f0 f_1065f0_k3
#define f_112df0 f_112df0_k3
#define f_112e70 f_112e70_k3
#define f_112ec0 f_112ec0_k3
#define f_125400 f_125400_k3
#define f_1254a0 f_1254a0_k3
#define f_125ed0 f_125ed0_k3
#define f_133fe0 f_133fe0_k3
#define f_1454d0 f_1454d0_k3
#define f_1457e0 f_1457e0_k3
#define OB OB_k3
#define S0C S0C_k3
#define S14 S14_k3
#define VF VF_k3
// P1 7/8 gleich
// ship2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1036F0-0x107200
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046ec0(int p1);                                   // reg eax stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0d5ff0();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbb20(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc3c0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd410(int p1, int p2);                           // reg edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_0fbe10();                                         // reg - stapel 0
int f_0fbee0(int p1, int p2);                           // reg eax edx stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_0fdbd0();                                         // reg - stapel 0
int f_103530(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0328;                    // 0x1C0328
extern int d_1c032c;                    // 0x1C032C
extern int d_1c0330;                    // 0x1C0330
extern int d_1c0338;                    // 0x1C0338
extern int d_1c033c;                    // 0x1C033C
extern int d_1c0340;                    // 0x1C0340
extern int d_1c0344;                    // 0x1C0344
                    // 0x1C0354
                    // 0x1C0358
extern int d_1c0360;                    // 0x1C0360
extern int d_1c0368;                    // 0x1C0368
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a6884[];           // Text 0x1A6884

unsigned short f_0bfa20(void);
short f_0bf820(void);
short f_044c90(int p1, int p2, int p3);
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
short f_1457e0(int p1);
short f_0d54f0(int p1, int p2);
short f_0db940(int p1);
int f_0fbc60(int p1);
int f_0bde40(int p1);
int f_1254a0(int p1, int p2);
int f_112e70(int p1, int p2);
int f_046d90(int p1, int p2);
void f_104980(int p1);
int f_0bf680(int p1);
int f_105860(int p1);
int f_105dc0(int p1);
int f_105cd0(int p1);
int f_106300(void);
int f_106440(void);
int f_1065f0(int p1);
void f_1036b0(void);
extern signed char d_1c02a0, d_1c030c, d_1c0310, d_1c031c, d_1c0324, d_1c0334, d_1c0348, d_1c034c, d_1c0354, d_1c0358, d_1c0350, d_1c035c, d_1c036c, d_1c0394, d_1c0398, d_1c039c;
typedef RivaTextContextData OB;
struct S14 {int a[5];};
struct S0C {int a[3];};
typedef short (*VF)(int,int,int);
#define VCALL(p,a,b) ((**(VF**)((p)+8))((p),(a),(b)))
#define D2C64 ((int)&d_1c2c64)
#define D2C44 ((int)&d_1c2c44)
#define D349C ((int)&d_1c349c)
#define D3870 ((int)&d_1c3870)
#define D3498 ((int)&d_1c3498)
#define FL(x,v) (((x)==(v))?1:0)
#define CT14(q,t,CD) q = (t != 0) ? f_112df0(t, CD, 0, 0) : t;
#define NEW14(LN,CD) { int q; int t_ = (int)new (mark(d_1a6884, LN)) S14; CT14(q,t_,CD) f_112ec0(q); if (q) operator delete((void*)f_112e70(q, 0)); }
#define NEW0C(LN,CD) { int q; int t_ = (int)new (mark(d_1a6884, LN)) S0C; q = (t_ != 0) ? f_046d10(t_, CD) : t_; f_046de0(q); if (q) operator delete((void*)f_046d90(q, 0)); }
#define M(x) f_0bf730(D2C64, x)
#define OBCTOR f_125400((int)&ob, D349C, D3870, D3498)
#define OBDTOR f_1254a0((int)&ob, 0)
#define SETB(v) *(int*)(ob.addresses.objects+4) = (v)

//@ f_106e30
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet das 12-Byte-Beuteobjekt 0x40 (f_046d10, Zeile 0xae9). Ist Inhalt vorhanden
 *   (f_046ec0 == 1), wird beim ersten Mal (d_1c0354 == 0, setzt d_1c0354 = 1) ein Held über f_039320(d_1c0004,
 *   0x12) bestimmt und Text 0x2f000119 ausgegeben, bevor f_046de0 ausgeführt wird.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0354, nutzt d_1c0004, d_1c2c64 und d_1a6884.
 * - Besonderheiten: Aufgerufen bei case 0x1f9 in f_1036f0.
 === Ende Beschreibung === */
void f_106e30(void)
{ OB ob; int q; int t_; OBCTOR;
  t_ = (int)new (mark(d_1a6884, 0xae9)) S0C;
  q = (t_ != 0) ? f_046d10(t_, 0x40) : t_;
  if (f_046ec0(q) == 1) {
    if (FL(d_1c0354, 0)) { d_1c0354 = 1; SETB(f_039320(d_1c0004, 0x12)); M(0x2f000119); }
    f_046de0(q);
  }
  if (q) operator delete((void*)f_046d90(q, 0));
  OBDTOR; }
//@ f_106ef0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Öffnet das 12-Byte-Beuteobjekt 0x41 (f_046d10, Zeile 0xb09). Ist Inhalt vorhanden
 *   (f_046ec0 == 1), wird beim ersten Mal (d_1c0358 == 0, setzt d_1c0358 = 1) ein Held über f_039420(d_1c0004,
 *   0xf) bestimmt und Text 0x2f00011a ausgegeben, bevor f_046de0 ausgeführt wird.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c0358, nutzt d_1c0004, d_1c2c64 und d_1a6884.
 * - Besonderheiten: Aufgerufen bei case 0x1fa in f_1036f0.
 === Ende Beschreibung === */
void f_106ef0(void)
{ OB ob; int q; int t_; OBCTOR;
  t_ = (int)new (mark(d_1a6884, 0xb09)) S0C;
  q = (t_ != 0) ? f_046d10(t_, 0x41) : t_;
  if (f_046ec0(q) == 1) {
    if (FL(d_1c0358, 0)) { d_1c0358 = 1; SETB(f_039420(d_1c0004, 0xf)); M(0x2f00011a); }
    f_046de0(q);
  }
  if (q) operator delete((void*)f_046d90(q, 0));
  OBDTOR; }
//@ f_106fb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Ermittelt einen Helden über f_039660(d_1c0004, 0xc) und fragt bei d_1c035c == 0 im
 *   Dialogmodus 5 mit Text 0x2f00011b (f_0bf6f0) nach; bei Zustimmung (1) wird Text 0x2f00011c ausgegeben sowie
 *   d_1c035c = 1 und d_1c036c = 3 gesetzt (bei d_1c035c != 0 erscheint 0x2f00011d).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c035c und d_1c036c, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Entspricht case 0x259 in f_1036f0.
 === Ende Beschreibung === */
void f_106fb0(void)
{ OB ob; OBCTOR; SETB(f_039660(d_1c0004, 0xc));
  if (FL(d_1c035c, 0)) {
    f_0bf6c0(D2C64, 5);
    if (f_0bf6f0(D2C64, 0x2f00011b) == 1) { M(0x2f00011c); d_1c035c = 1; d_1c036c = 3; }
    f_0bf680(D2C64);
  } else { M(0x2f00011d); }
  OBDTOR; }
//@ f_107070
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Schaltet in den Dialogmodus 5 und prüft d_1c035c: Ist es 0, wird Textbaustein
 *   0x2f00011f gesetzt und Frage 0x2f00011e (f_0bf6f0) gestellt, die bei Zustimmung Text 0x2f00011c zeigt sowie
 *   d_1c035c = 1 und d_1c036c = 3 setzt; andernfalls wird Textbaustein 0x2f000120 mit Meldung 0x2f00011e
 *   ausgegeben.
 * - Eingaben / Rückgabe: Keine Parameter (void). Gibt das Ergebnis des Kontext-Abbaus (f_1254a0) zurück.
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c035c und d_1c036c, nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x25a in f_1036f0.
 === Ende Beschreibung === */
int f_107070(void)
{ OB ob; OBCTOR; f_0bf6c0(D2C64, 5);
  if (FL(d_1c035c, 0)) {
    *(int*)(ob.addresses.numbers+4) = 0x2f00011f;
    if (f_0bf6f0(D2C64, 0x2f00011e) == 1) { M(0x2f00011c); d_1c035c = 1; d_1c036c = 3; }
  } else {
    *(int*)(ob.addresses.numbers+4) = 0x2f000120;
    M(0x2f00011e);
  }
  f_0bf680(D2C64);
  return OBDTOR; }

//@ f_107130
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Leere Platzhalter- bzw. No-Op-Funktion in ship2.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Keine.
 * - Besonderheiten: Entspricht case 0x25b in f_1036f0.
 === Ende Beschreibung === */
void f_107130(void)
{
}

//@ f_107140
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f000121 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x25c in f_1036f0.
 === Ende Beschreibung === */
void f_107140(void) { M(0x2f000121); }
//@ f_107160
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f000122 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x25d in f_1036f0.
 === Ende Beschreibung === */
void f_107160(void) { M(0x2f000122); }
//@ f_107180
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Beschreibungstext 0x2f000123 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x25e in f_1036f0.
 === Ende Beschreibung === */
void f_107180(void) { M(0x2f000123); }
//@ f_1071a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt zunächst den Text 0x2f000124 über f_0bf730 aus und öffnet anschließend das
 *   20-Byte-Behälterobjekt 0x5b (f_112df0, Zeile 0xbaa).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 und d_1a6884.
 * - Besonderheiten: Entspricht case 0x25f in f_1036f0.
 === Ende Beschreibung === */
void f_1071a0(void)
{ M(0x2f000124);
  NEW14(0xbaa, 0x5b)
}

#undef CT14
#undef D2C44
#undef D2C64
#undef D3498
#undef D349C
#undef D3870
#undef FL
#undef M
#undef NEW0C
#undef NEW14
#undef OB
#undef OBCTOR
#undef OBDTOR
#undef S0C
#undef S14
#undef SETB
#undef VCALL
#undef VF
#undef d_1a6884
#undef d_1bf230
#undef d_1c0004
#undef d_1c02a0
#undef d_1c030c
#undef d_1c0310
#undef d_1c031c
#undef d_1c0324
#undef d_1c0328
#undef d_1c032c
#undef d_1c0330
#undef d_1c0334
#undef d_1c0338
#undef d_1c033c
#undef d_1c0340
#undef d_1c0344
#undef d_1c0348
#undef d_1c034c
#undef d_1c0350
#undef d_1c0354
#undef d_1c0358
#undef d_1c035c
#undef d_1c0360
#undef d_1c0368
#undef d_1c036c
#undef d_1c0394
#undef d_1c0398
#undef d_1c039c
#undef d_1c21b4
#undef d_1c27a8
#undef d_1c299c
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef d_1c38b0
#undef f_038c40
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_039ac0
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046ec0
#undef f_05fa00
#undef f_0606a0
#undef f_060770
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bde40
#undef f_0bf680
#undef f_0bf6c0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf7b0
#undef f_0bf820
#undef f_0bfa20
#undef f_0bfea0
#undef f_0c0020
#undef f_0d54f0
#undef f_0d5ff0
#undef f_0db820
#undef f_0db8b0
#undef f_0db940
#undef f_0dbb20
#undef f_0dc3c0
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd410
#undef f_0dd750
#undef f_0dd7f0
#undef f_0e93f0

#undef f_0fb660
#undef f_0fbc60
#undef f_0fbe10
#undef f_0fbee0
#undef f_0fca60
#undef f_0fdbd0
#undef f_103530
#undef f_1036b0
#undef f_104980
#undef f_105860
#undef f_105cd0
#undef f_105dc0
#undef f_106300
#undef f_106440
#undef f_1065f0
#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0
#undef f_1454d0
#undef f_1457e0

// ===== Teil gz_107200 (p3, 107200-107380) =====
#define d_1c0004 d_1c0004_k4
#define d_1c212a d_1c212a_k4
#define d_1c212c d_1c212c_k4
#define d_1c2c64 d_1c2c64_k4
#define f_0bf6f0 f_0bf6f0_k4
#define f_0bf730 f_0bf730_k4
#define f_0dd7f0 f_0dd7f0_k4
#define f_0fb5f0 f_0fb5f0_k4
#define f_0fb630 f_0fb630_k4
#define f_145234 f_145234_k4
#define f_145254 f_145254_k4
#define OB OB_k4
// P3 5/6 gleich (suche.py 25.10.2026, Basis gz_107200_P1.CPP)
// gz_107200.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x107200-0x107380
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0fb5f0(int p1, int p2);
int f_0fb630(int p1, int p2);                           // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c64;                    // 0x1C2C64
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1bb7c0[];
extern int f_145234(int p1, int p2);
extern int f_145254();
extern int d_1bb818[];
extern char d_1c03a0;
extern short d_1c03a1;
extern char d_1c03a4;
extern short d_1c03a5;
extern short d_1c03a8;
extern short d_1c03a9;
extern short d_1c212a;
extern int *d_1c212c;
//@ f_107200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese vier Abschlussfunktionen am Ende des Moduls starten zwei Kämpfe bzw. Ortswechsel (f_107200,
 *   f_107230), liefern die Dungeon-Kennung 0x2b zurück (f_107260) und löschen eine 9-Byte-Zustandsstruktur
 *   (f_107280).
 * - Eingaben: Die Funktionen erhalten den this-Zeiger bzw. Strukturzeiger p1 (oder void bei f_107260).
 * - Rückgabewert: f_107260 gibt 0x2b zurück; f_107280 hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_107200(void)
{
    if (f_0bf6f0((int)&d_1c2c64, 0x2f000125) == 1) f_0dd7f0(d_1c0004, 0x17, 0x139a);
}
//@ f_107230
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Stellt über f_0bf6f0 die Entscheidungsfrage 0x2f000126 und führt bei Zustimmung (1)
 *   einen Orts-/Gebietswechsel nach 0x19 (Position 5000) über f_0dd7f0 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Entspricht case 0x2be in f_1036f0 (und steht auch in gz_107200.md).
 === Ende Beschreibung === */
void f_107230(void)
{
    if (f_0bf6f0((int)&d_1c2c64, 0x2f000126) == 1) f_0dd7f0(d_1c0004, 0x19, 5000);
}
//@ f_107260
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Hinweistext 0x2f0000c2 über f_0bf730 im Dialogkontext d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64.
 * - Besonderheiten: Entspricht case 0x2bf in f_1036f0 (und steht auch in gz_107200.md).
 === Ende Beschreibung === */
void f_107260(void)
{
    f_0bf730((int)&d_1c2c64, 0x2f0000c2);
}
// f_107280 = $dt:X1034b0 (COMDAT aus virtual ~X1034b0(){ }), steht hinter dem normalen Code
struct Obj107 { signed char a; short b; };
struct Reg107 { short count; Obj107 **list; };
extern Obj107 ob0, ob1, ob2; extern Reg107 registry107;
#pragma aux ob0 "d_1c03a0"
#pragma aux ob1 "d_1c03a4"
#pragma aux ob2 "d_1c03a8"
#pragma aux registry107 "d_1c212a"
inline signed char z107() { signed char c=0; return c; }
inline void add107(Obj107 &o,Reg107 &r,short id) { o.a=z107();o.b=id;r.list[r.count]=&o;r.count++; }
// (anderes Modul)  f_1072c0
// (Funktion f_1072c0 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_107360
// (Funktion f_107360 gehoert zu einem anderen Modul, hier weggelassen)

#undef OB
#undef d_1c0004
#undef d_1c212a
#undef d_1c212c
#undef d_1c2c64
#undef f_0bf6f0
#undef f_0bf730
#undef f_0dd7f0
#undef f_0fb5f0
#undef f_0fb630
#undef f_145234
#undef f_145254

