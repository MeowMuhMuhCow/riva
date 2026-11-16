/* === Beschreibung (Katalog) ===
 * Einheit sewerag3 (0f6ea0 - 0fa9b0)
 *
 * Überblick
 *
 * Die Einheit sewerag3 implementiert das umfangreiche 3D-Dungeon-Modul für den dritten Bereich der Kanalisation
 * unter Riva (das Reich des Rattenfängers und der Wasserratten/Goblins). Da die Rekonstruktionsdatei
 * sewerag3_P1.CPP als zusammenhängende Moduldatei (0x0F6EA0-0x0FABE0) aufgebaut ist, umfasst sie neben den
 * eigentlichen Dungeon-Routinen (sewerag3_t1 bis sewerag3_t4) auch den Abschlussblock von gz_0f5250_t2 (f_0f6ea0
 * bis f_0f6f80) sowie den Anfangsblock von gz_0fa9b0 (f_0fa9b0 bis f_0faba0). Inhaltlich deckt das Modul
 * sämtliche 3D-Interaktionen dieses Kanalisationsabschnitts ab: die große Karten-Ereignisverteilung (f_0f72e0,
 * f_0f81d0), die Rattenfänger-Flötenmelodie und deren magische Wirkung auf die Heldengruppe (f_0f8300, f_0f9950,
 * f_0f9a00), das Einsperren und Ausrauben der Helden im Rattenfänger-Käfig (f_0f9d40, f_0f9e10, f_0fa4e0,
 * f_0fa570, f_0fa840), Schleusentore, Seilwinden und überflutete Schächte (f_0f8cb0, f_0f8dc0, f_0f9100,
 * f_0f9790) sowie das Rosten ungeschützter Metallwaffen und Rüstungen im Kanalwasser (f_0fa9b0, f_0faa10).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// OPT -4r -onetx -zp1 -s
// sewerag3 (Schatten ueber Riva) - GANZES Linkermodul 0x0F6EA0-0x0FABE0 inkl. COMDAT-Schwanz (bau_modul.py von Forscher 840, Modul sewerag3 + Nacharbeit fix_sewerag3.py: Claude 831, 30.10.2026)
// Erzeugt mit comdat/840/bau_modul.py aus: gz_0f5250_t2(p3), sewerag3_t1(p3), sewerag3_t2(p3), sewerag3_t3(p3), sewerag3_t4(p3), gz_0fa9b0(p3)
#include <string.h>
#include <math.h>
struct B05ff60 { char pad[8]; B05ff60(int k); virtual ~B05ff60(); };   // Basis: ctor f_05ff60, dtor f_060030
// ===== Teil gz_0f5250_t2 (p3, 0f6400-0f6fb0) =====
#define d_1a9820 d_1a9820_k0
#define d_1c0004 d_1c0004_k0
#define d_1c0220 d_1c0220_k0
#define d_1c0224 d_1c0224_k0
#define d_1c0228 d_1c0228_k0
#define d_1c022c d_1c022c_k0
#define d_1c0230 d_1c0230_k0
#define d_1c0234 d_1c0234_k0
#define d_1c0238 d_1c0238_k0
#define d_1c023c d_1c023c_k0
#define d_1c0240 d_1c0240_k0
#define d_1c0244 d_1c0244_k0
#define d_1c0248 d_1c0248_k0
#define d_1c024c d_1c024c_k0
#define d_1c0250 d_1c0250_k0
#define d_1c0254 d_1c0254_k0
#define d_1c0258 d_1c0258_k0
#define d_1c025c d_1c025c_k0
#define d_1c0260 d_1c0260_k0
#define d_1c0264 d_1c0264_k0
#define d_1c0268 d_1c0268_k0
#define d_1c026c d_1c026c_k0
#define d_1c0270 d_1c0270_k0
#define d_1c0274 d_1c0274_k0
#define d_1c0278 d_1c0278_k0
#define d_1c027c d_1c027c_k0
#define d_1c0280 d_1c0280_k0
#define d_1c0284 d_1c0284_k0
#define d_1c0288 d_1c0288_k0
#define d_1c028c d_1c028c_k0
#define d_1c0290 d_1c0290_k0
#define d_1c2c44 d_1c2c44_k0
#define d_1c2c64 d_1c2c64_k0
#define d_1c2edc d_1c2edc_k0
#define d_1c3498 d_1c3498_k0
#define d_1c349c d_1c349c_k0
#define d_1c3870 d_1c3870_k0
#define f_038c40 f_038c40_k0
#define f_039040 f_039040_k0
#define f_039660 f_039660_k0
#define f_039a80 f_039a80_k0
#define f_039c50 f_039c50_k0
#define f_041030 f_041030_k0
#define f_041530 f_041530_k0
#define f_041920 f_041920_k0
#define f_042400 f_042400_k0
#define f_0425f0 f_0425f0_k0
#define f_042960 f_042960_k0
#define f_043e20 f_043e20_k0
#define f_044300 f_044300_k0
#define f_044850 f_044850_k0
#define f_044c90 f_044c90_k0
#define f_060030 f_060030_k0
#define f_060740 f_060740_k0
#define f_0607e0 f_0607e0_k0
#define f_0bf6f0 f_0bf6f0_k0
#define f_0bf730 f_0bf730_k0
#define f_0d54f0 f_0d54f0_k0
#define f_0db9a0 f_0db9a0_k0
#define f_0dc020 f_0dc020_k0
#define f_0dd100 f_0dd100_k0
#define f_0dd750 f_0dd750_k0
#define f_0dd7f0 f_0dd7f0_k0
#define f_0de7f0 f_0de7f0_k0
#define f_0de820 f_0de820_k0
#define f_0de9d0 f_0de9d0_k0
#define f_0de9f0 f_0de9f0_k0
#define f_125400 f_125400_k0
#define f_1254a0 f_1254a0_k0
#define f_125ed0 f_125ed0_k0
#define f_145234 f_145234_k0
#define f_145254 f_145254_k0
#define OB OB_k0
// P3 12/13 gleich (suche.py 26.10.2026, Basis gz_0f5250_t2_P1.CPP)
// gz_0f5250_t2 (0F6400-0F6FB0) - Pass 1 Helfer B
int f_039040(int p1);
int f_039660(int p1, int p2);
int f_039a80(int p1, int p2);
signed char f_042400(hero *p);
unsigned char f_0425f0(hero *p);
short f_042960(hero *p);
int f_043e20(int p1, int p2);
int f_044300(int p1, int p2);
int f_044890(int p1, int p2);
int f_060030(int p1, int p2);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dd7f0(int p1, int p2, int p3);
short f_0de820(int p1);
int f_0de9d0(int p1, int p2);
int f_0de9f0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_145234(int p1, int p2);
int f_145254(void);
typedef RivaTextContextData OB;
struct T { char a; short b; };
extern int d_1c0004;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c3498;
extern signed char d_1c020c;
extern signed char d_1bdd0c;
extern char d_1c0214;
extern char d_1bb6c4[];
extern int *d_1c212c;
extern short d_1c212a;
extern T d_1c0220;
extern T d_1c0224;
extern T d_1c0228;
extern T d_1c022c;
extern T d_1c0230;
extern T d_1c0234;
extern T d_1c0238;
extern T d_1c023c;
extern T d_1c0240;
extern T d_1c0244;
extern T d_1c0248;
extern T d_1c024c;
extern T d_1c0250;
extern T d_1c0254;
extern T d_1c0258;
extern T d_1c025c;
extern T d_1c0260;
extern T d_1c0264;
extern T d_1c0268;
extern T d_1c026c;
extern T d_1c0270;
extern T d_1c0274;
extern T d_1c0278;
extern T d_1c027c;
extern T d_1c0280;
extern T d_1c0284;
extern T d_1c0288;
extern T d_1c028c;
extern T d_1c0290;
#define P(k) f_0bf730((int)&d_1c2c64, k)
#define EQI(x,v) (((x)==(v))?1:0)
 #define EN(D,V) D.a = 0; D.b = V; d_1c212c[d_1c212a++] = (int)&D;
void f_0f6ea0(int p1);
void f_0f6ee0(int p1);
int f_038c40(int p1);
int f_038d70(int p1, int p2);
int f_040a00(int p1, int p2, int p3);
int f_041030(int p1, ...);
int f_041530();
int f_041920(int p1);
int f_044850(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
short f_0bf820(int p1, ...);
short f_0d4cd0(int p1, int p2);
int f_0db9d0(int p1, int p2, int p3);
int f_0dc020(int p1, int p2);
int f_0dcd30(int p1, int p2, int p3);
int f_0dd100(int p1, int p2);
int f_0dd750(int p1, int p2);
short f_0de7f0(int p1);
int f_039c50(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern signed char d_1c01fc;
extern short d_1c219c;
extern int d_1c2c44;
extern int d_1c2edc;
extern int d_1a9820;
// (anderes Modul)  f_0f6400
// (Funktion f_0f6400 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_0f6500
// (Funktion f_0f6500 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_0f6550
struct OBC { int a; int b; int x1; int x2; int c; int rest[10]; OBC(int,int,int); ~OBC(); };
// (Funktion f_0f6550 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_0f6920
// (Funktion f_0f6920 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_0f6940
// (Funktion f_0f6940 gehoert zu einem anderen Modul, hier weggelassen)
struct Reg6980 { short count; T **list; };
extern Reg6980 reg6980;
#pragma aux reg6980 "d_1c212a"
inline signed char zero6980(){signed char c=0;return c;}
inline void add6980(T &o,Reg6980 &r,short id){o.a=0;o.b=id;r.list[r.count]=&o;r.count++;}
// (anderes Modul)  f_0f6980
struct RR700V3_0f69808;
struct OR700V3_0f69808 { signed char flag; short number; char pad; OR700V3_0f69808 *init(RR700V3_0f69808 &r,short id,signed char f); };
struct RR700V3_0f69808 { short count; OR700V3_0f69808 **list; void append(OR700V3_0f69808 *o) {list[count]=o;count++;} };
inline OR700V3_0f69808 *OR700V3_0f69808::init(RR700V3_0f69808 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0f69808 regR700V3_0f69808;
#pragma aux regR700V3_0f69808 "d_1c212a"
extern OR700V3_0f69808 obR700V3_0f6980_1c0220;
#pragma aux obR700V3_0f6980_1c0220 "d_1c0220"
extern OR700V3_0f69808 obR700V3_0f6980_1c0224;
#pragma aux obR700V3_0f6980_1c0224 "d_1c0224"
extern OR700V3_0f69808 obR700V3_0f6980_1c0228;
#pragma aux obR700V3_0f6980_1c0228 "d_1c0228"
extern OR700V3_0f69808 obR700V3_0f6980_1c022c;
#pragma aux obR700V3_0f6980_1c022c "d_1c022c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0230;
#pragma aux obR700V3_0f6980_1c0230 "d_1c0230"
extern OR700V3_0f69808 obR700V3_0f6980_1c0234;
#pragma aux obR700V3_0f6980_1c0234 "d_1c0234"
extern OR700V3_0f69808 obR700V3_0f6980_1c0238;
#pragma aux obR700V3_0f6980_1c0238 "d_1c0238"
extern OR700V3_0f69808 obR700V3_0f6980_1c023c;
#pragma aux obR700V3_0f6980_1c023c "d_1c023c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0240;
#pragma aux obR700V3_0f6980_1c0240 "d_1c0240"
extern OR700V3_0f69808 obR700V3_0f6980_1c0244;
#pragma aux obR700V3_0f6980_1c0244 "d_1c0244"
extern OR700V3_0f69808 obR700V3_0f6980_1c0248;
#pragma aux obR700V3_0f6980_1c0248 "d_1c0248"
extern OR700V3_0f69808 obR700V3_0f6980_1c024c;
#pragma aux obR700V3_0f6980_1c024c "d_1c024c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0250;
#pragma aux obR700V3_0f6980_1c0250 "d_1c0250"
extern OR700V3_0f69808 obR700V3_0f6980_1c0254;
#pragma aux obR700V3_0f6980_1c0254 "d_1c0254"
extern OR700V3_0f69808 obR700V3_0f6980_1c0258;
#pragma aux obR700V3_0f6980_1c0258 "d_1c0258"
extern OR700V3_0f69808 obR700V3_0f6980_1c025c;
#pragma aux obR700V3_0f6980_1c025c "d_1c025c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0260;
#pragma aux obR700V3_0f6980_1c0260 "d_1c0260"
extern OR700V3_0f69808 obR700V3_0f6980_1c0264;
#pragma aux obR700V3_0f6980_1c0264 "d_1c0264"
extern OR700V3_0f69808 obR700V3_0f6980_1c0268;
#pragma aux obR700V3_0f6980_1c0268 "d_1c0268"
extern OR700V3_0f69808 obR700V3_0f6980_1c026c;
#pragma aux obR700V3_0f6980_1c026c "d_1c026c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0270;
#pragma aux obR700V3_0f6980_1c0270 "d_1c0270"
extern OR700V3_0f69808 obR700V3_0f6980_1c0274;
#pragma aux obR700V3_0f6980_1c0274 "d_1c0274"
extern OR700V3_0f69808 obR700V3_0f6980_1c0278;
#pragma aux obR700V3_0f6980_1c0278 "d_1c0278"
extern OR700V3_0f69808 obR700V3_0f6980_1c027c;
#pragma aux obR700V3_0f6980_1c027c "d_1c027c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0280;
#pragma aux obR700V3_0f6980_1c0280 "d_1c0280"
extern OR700V3_0f69808 obR700V3_0f6980_1c0284;
#pragma aux obR700V3_0f6980_1c0284 "d_1c0284"
extern OR700V3_0f69808 obR700V3_0f6980_1c0288;
#pragma aux obR700V3_0f6980_1c0288 "d_1c0288"
extern OR700V3_0f69808 obR700V3_0f6980_1c028c;
#pragma aux obR700V3_0f6980_1c028c "d_1c028c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0290;
#pragma aux obR700V3_0f6980_1c0290 "d_1c0290"
// (Funktion f_0f6980 gehoert zu einem anderen Modul, hier weggelassen)


//@ f_0f6ea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft im zweiten Kanalisationsabschnitt (sewerag2 / gz_0f5250_t2), ob das Ereignisfeld
 *   0x22 bereits ausgelöst wurde (d_1c031d), zeigt andernfalls einen Hinweistext (0x2600001e) an und setzt das
 *   Statusflag auf 1.
 * - Eingaben: Die Funktion erhält den this-Zeiger des Dungeon-Handlers als Parameter p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f6ea0(int p1)
{
    if (((signed char)(f_0425f0((struct hero *)(p1)))) == 0) {
        if (f_042400((struct hero *)(p1)) == 0) {
            f_044300(p1, (short)(((short (*)(int))f_042960)(p1) - 4));
        }
    }
}
//@ f_0f6ee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert die Kennung 0x16 (22) des zweiten Kanalisations-Dungeons zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt den konstanten Wert 0x16 zurück.
 === Ende Beschreibung === */
void f_0f6ee0(int p1)
{
    f_044890(p1, 5);
}
//@ f_0f6ef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet im zweiten Kanalisationsabschnitt den Kampf mit der Gegnergruppe 0xc (0x1f4b).
 * - Eingaben: Die Funktion erhält den this-Zeiger des Dungeon-Handlers als Parameter p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Kampfstarts (f_05fa00) zurück.
 === Ende Beschreibung === */
void f_0f6ef0(int p1)
{
    f_043e20(p1, 1);
    f_044300(p1, (short)(((int)(f_042960((struct hero *)(p1)))) - 4));
    f_043e20(p1, 0);
}
//@ f_0f6f20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion liefert konstant den Wert 1 zurück, um anzuzeigen, dass das Kanalisationsmodul
 *   aktiv ist.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
void f_0f6f20(int p1)
{
    f_039a80(p1, (int)f_0f6ea0);
}
//@ f_0f6f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft anhand des Gruppen-Flags 100, ob die Kanalisation von der Stadtkarte aus über
 *   Eingang 1 oder Eingang 2 betreten wurde, und kehrt in die entsprechende Stadtansicht (0x11 mit Kennung
 *   0x1b59 oder 0x1b5a) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Ortswechsels (f_05fa00) zurück.
 === Ende Beschreibung === */
void f_0f6f30(int p1)
{
    f_039a80(p1, (int)f_0f6ee0);
    f_0de9d0(d_1c0004, 0);
    f_0de9f0(d_1c0004, 0);
}
//@ f_0f6f60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode initialisiert die Zustandsfelder einer 9-Byte-Hilfsstruktur des Kanalisationsmoduls mit
 *   Nullen.
 * - Eingaben: Die Funktion erhält den Zeiger p auf die zu löschende Struktur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0f6f60(int p1)
{
    int r;
    r = 0;
    if (f_0de820(p1) == 3) r = 1;
    return r;
}
//@ f_0f6f80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim Verlassen des zweiten Kanalisationsabschnitts den globalen Animations- oder
 *   Textpuffer d_1c02fc frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger als Parameter p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
int f_0f6f80(int p1)
{
    int r;
    short s;
    s = f_0de820(p1);
    r = 0;
    if (s == 3) {
        if (f_0db9a0(p1) == 0) r = 1;
    }
    return r;
}

#undef EN
#undef EQI
#undef OB
#undef P
#undef d_1a9820
#undef d_1c0004
#undef d_1c0220
#undef d_1c0224
#undef d_1c0228
#undef d_1c022c
#undef d_1c0230
#undef d_1c0234
#undef d_1c0238
#undef d_1c023c
#undef d_1c0240
#undef d_1c0244
#undef d_1c0248
#undef d_1c024c
#undef d_1c0250
#undef d_1c0254
#undef d_1c0258
#undef d_1c025c
#undef d_1c0260
#undef d_1c0264
#undef d_1c0268
#undef d_1c026c
#undef d_1c0270
#undef d_1c0274
#undef d_1c0278
#undef d_1c027c
#undef d_1c0280
#undef d_1c0284
#undef d_1c0288
#undef d_1c028c
#undef d_1c0290
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_038c40
#undef f_039040
#undef f_039660
#undef f_039a80
#undef f_039c50
#undef f_041030
#undef f_041530
#undef f_041920
#undef f_042400
#undef f_0425f0
#undef f_042960
#undef f_043e20
#undef f_044300
#undef f_044850
#undef f_044c90
#undef f_060030
#undef f_060740
#undef f_0607e0
#undef f_0bf6f0
#undef f_0bf730
#undef f_0d54f0
#undef f_0db9a0
#undef f_0dc020
#undef f_0dd100
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de7f0
#undef f_0de820
#undef f_0de9d0
#undef f_0de9f0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_145234
#undef f_145254

// ===== Teil sewerag3_t1 (p3, 0f6fb0-0f81d0) =====
#define d_1a6790 d_1a6790_k1
#define d_1a67b0 d_1a67b0_k1
#define d_1a67b4 d_1a67b4_k1
#define d_1a67b6 d_1a67b6_k1
#define d_1a67b8 d_1a67b8_k1
#define d_1a67ba d_1a67ba_k1
#define d_1a67bc d_1a67bc_k1
#define d_1a67c0 d_1a67c0_k1
#define d_1a67c2 d_1a67c2_k1
#define d_1a67c4 d_1a67c4_k1
#define d_1a67c6 d_1a67c6_k1
#define d_1a67c8 d_1a67c8_k1
#define d_1a67cc d_1a67cc_k1
#define d_1a67ce d_1a67ce_k1
#define d_1a67d0 d_1a67d0_k1
#define d_1a67d2 d_1a67d2_k1
#define d_1a9820 d_1a9820_k1
#define d_1bc8cc d_1bc8cc_k1
#define d_1bdcf8 d_1bdcf8_k1
#define d_1bf230 d_1bf230_k1
#define d_1bfdbc d_1bfdbc_k1
#define d_1c0004 d_1c0004_k1
#define d_1c0028 d_1c0028_k1
#define d_1c0218 d_1c0218_k1
#define d_1c021c d_1c021c_k1
#define d_1c0220 d_1c0220_k1
#define d_1c0224 d_1c0224_k1
#define d_1c0228 d_1c0228_k1
#define d_1c022c d_1c022c_k1
#define d_1c0230 d_1c0230_k1
#define d_1c0234 d_1c0234_k1
#define d_1c0238 d_1c0238_k1
#define d_1c023c d_1c023c_k1
#define d_1c0240 d_1c0240_k1
#define d_1c0244 d_1c0244_k1
#define d_1c0248 d_1c0248_k1
#define d_1c024c d_1c024c_k1
#define d_1c0250 d_1c0250_k1
#define d_1c0254 d_1c0254_k1
#define d_1c0258 d_1c0258_k1
#define d_1c025c d_1c025c_k1
#define d_1c0260 d_1c0260_k1
#define d_1c0264 d_1c0264_k1
#define d_1c0268 d_1c0268_k1
#define d_1c026c d_1c026c_k1
#define d_1c0270 d_1c0270_k1
#define d_1c0274 d_1c0274_k1
#define d_1c0278 d_1c0278_k1
#define d_1c027c d_1c027c_k1
#define d_1c0280 d_1c0280_k1
#define d_1c0284 d_1c0284_k1
#define d_1c0288 d_1c0288_k1
#define d_1c028c d_1c028c_k1
#define d_1c0290 d_1c0290_k1
#define d_1c21a4 d_1c21a4_k1
#define d_1c23a8 d_1c23a8_k1
#define d_1c27a4 d_1c27a4_k1
#define d_1c27a8 d_1c27a8_k1
#define d_1c280c d_1c280c_k1
#define d_1c2c00 d_1c2c00_k1
#define d_1c2c44 d_1c2c44_k1
#define d_1c2c64 d_1c2c64_k1
#define d_1c2edc d_1c2edc_k1
#define d_1c3498 d_1c3498_k1
#define d_1c349c d_1c349c_k1
#define d_1c3870 d_1c3870_k1
#define f_0104b0 f_0104b0_k1
#define f_010590 f_010590_k1
#define f_0366e0 f_0366e0_k1
#define f_038ba0 f_038ba0_k1
#define f_038c40 f_038c40_k1
#define f_038c80 f_038c80_k1
#define f_039040 f_039040_k1
#define f_039320 f_039320_k1
#define f_039420 f_039420_k1
#define f_039660 f_039660_k1
#define f_0396f0 f_0396f0_k1
#define f_0397d0 f_0397d0_k1
#define f_039a10 f_039a10_k1
#define f_039a80 f_039a80_k1
#define f_039ac0 f_039ac0_k1
#define f_039b00 f_039b00_k1
#define f_039b70 f_039b70_k1
#define f_039c50 f_039c50_k1
#define f_039c90 f_039c90_k1
#define f_041000 f_041000_k1
#define f_041030 f_041030_k1
#define f_041530 f_041530_k1
#define f_041920 f_041920_k1
#define f_0422b0 f_0422b0_k1
#define f_042350 f_042350_k1
#define f_042380 f_042380_k1
#define f_042400 f_042400_k1
#define f_042470 f_042470_k1
#define f_0424e0 f_0424e0_k1
#define f_0425f0 f_0425f0_k1
#define f_042960 f_042960_k1
#define f_042a60 f_042a60_k1
#define f_043d10 f_043d10_k1
#define f_043e20 f_043e20_k1
#define f_044300 f_044300_k1
#define f_044850 f_044850_k1
#define f_044900 f_044900_k1
#define f_044c90 f_044c90_k1
#define f_046d10 f_046d10_k1
#define f_046d90 f_046d90_k1
#define f_046de0 f_046de0_k1
#define f_046eb0 f_046eb0_k1
#define f_0471b0 f_0471b0_k1
#define f_0477a0 f_0477a0_k1
#define f_057220 f_057220_k1
#define f_05f190 f_05f190_k1
#define f_05f220 f_05f220_k1
#define f_05f470 f_05f470_k1
#define f_05f480 f_05f480_k1
#define f_05f800 f_05f800_k1
#define f_05fa00 f_05fa00_k1
#define f_05ff60 f_05ff60_k1
#define f_060240 f_060240_k1
#define f_060360 f_060360_k1
#define f_0603b0 f_0603b0_k1
#define f_0606a0 f_0606a0_k1
#define f_060740 f_060740_k1
#define f_060760 f_060760_k1
#define f_0607e0 f_0607e0_k1
#define f_060800 f_060800_k1
#define f_060a70 f_060a70_k1
#define f_091f70 f_091f70_k1
#define f_0bbf00 f_0bbf00_k1
#define f_0bf6f0 f_0bf6f0_k1
#define f_0bf730 f_0bf730_k1
#define f_0bf980 f_0bf980_k1
#define f_0bfa20 f_0bfa20_k1
#define f_0d4800 f_0d4800_k1
#define f_0d4a60 f_0d4a60_k1
#define f_0d4aa0 f_0d4aa0_k1
#define f_0d54f0 f_0d54f0_k1
#define f_0d64a0 f_0d64a0_k1
#define f_0db9a0 f_0db9a0_k1
#define f_0dbad0 f_0dbad0_k1
#define f_0dc020 f_0dc020_k1
#define f_0dc050 f_0dc050_k1
#define f_0dcae0 f_0dcae0_k1
#define f_0dcbb0 f_0dcbb0_k1
#define f_0dcc10 f_0dcc10_k1
#define f_0dcc40 f_0dcc40_k1
#define f_0dcdf0 f_0dcdf0_k1
#define f_0dcf00 f_0dcf00_k1
#define f_0dd100 f_0dd100_k1
#define f_0dd1d0 f_0dd1d0_k1
#define f_0dd4f0 f_0dd4f0_k1
#define f_0dd750 f_0dd750_k1
#define f_0dd7f0 f_0dd7f0_k1
#define f_0de020 f_0de020_k1
#define f_0de0d0 f_0de0d0_k1
#define f_0de210 f_0de210_k1
#define f_0de7c0 f_0de7c0_k1
#define f_0de7d0 f_0de7d0_k1
#define f_0de7f0 f_0de7f0_k1
#define f_0de810 f_0de810_k1
#define f_0de820 f_0de820_k1
#define f_0de9d0 f_0de9d0_k1
#define f_0de9e0 f_0de9e0_k1
#define f_0de9f0 f_0de9f0_k1
#define f_0f81d0 f_0f81d0_k1
#define f_0f8300 f_0f8300_k1
#define f_0f86e0 f_0f86e0_k1
#define f_0f8cb0 f_0f8cb0_k1
#define f_0f8dc0 f_0f8dc0_k1
#define f_0f8f90 f_0f8f90_k1
#define f_0f9240 f_0f9240_k1
#define f_0f93a0 f_0f93a0_k1
#define f_0f94b0 f_0f94b0_k1
#define f_0f9790 f_0f9790_k1
#define f_0f9a00 f_0f9a00_k1
#define f_0f9e10 f_0f9e10_k1
#define f_0fa280 f_0fa280_k1
#define f_0fa570 f_0fa570_k1
#define f_0faa10 f_0faa10_k1

#define f_112df0 f_112df0_k1
#define f_112e70 f_112e70_k1
#define f_112ec0 f_112ec0_k1
#define f_1131b0 f_1131b0_k1
#define f_113240 f_113240_k1
#define f_113340 f_113340_k1
#define f_113640 f_113640_k1
#define f_1223c0 f_1223c0_k1
#define f_125400 f_125400_k1
#define f_1254a0 f_1254a0_k1
#define f_125ed0 f_125ed0_k1
#define f_133fe0 f_133fe0_k1
#define f_147323 f_147323_k1
#define OB OB_k1
// P3 9/10 gleich (suche.py 29.10.2026, Basis sewerag3_t1_P1.CPP)
// sewerag3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F6FB0-0x0FA9B0
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_039c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041030();                                         // reg - stapel 0
int f_041530();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
char * f_0422b0(hero *p);                                   // reg eax stapel 0
signed char f_042350(hero *p);                                   // reg eax stapel 0
signed char f_042380(hero *p);                                   // reg eax stapel 0
unsigned char f_042470(hero *p);                                   // reg eax stapel 0
unsigned char f_0424e0(hero *p);                                   // reg eax stapel 0
unsigned char f_0425f0(hero *p);                                   // reg eax stapel 0
short f_042960(hero *p);                                   // reg eax stapel 0
int f_043d10(int p1);                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046eb0(int p1);                                   // reg eax stapel 0
int f_0471b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0477a0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f800(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060240();                                         // reg - stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf980();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0dbad0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd4f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de020(int p1, int p2);                           // reg eax edx stapel 0
int f_0de0d0(int p1);                                   // reg eax stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9e0(int p1);                                   // reg eax stapel 0
int f_0de9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0faa10(int p1, int p2);                           // reg edx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113240(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a67b0;                    // 0x1A67B0
extern int d_1a67b4;                    // 0x1A67B4
extern int d_1a67b6;                    // 0x1A67B6
extern int d_1a67b8;                    // 0x1A67B8
extern int d_1a67ba;                    // 0x1A67BA
extern int d_1a67bc;                    // 0x1A67BC
extern int d_1a67c0;                    // 0x1A67C0
extern int d_1a67c2;                    // 0x1A67C2
extern int d_1a67c4;                    // 0x1A67C4
extern int d_1a67c6;                    // 0x1A67C6
extern int d_1a67c8;                    // 0x1A67C8
extern int d_1a67cc;                    // 0x1A67CC
extern int d_1a67ce;                    // 0x1A67CE
extern int d_1a67d0;                    // 0x1A67D0
extern int d_1a67d2;                    // 0x1A67D2
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc8cc;                    // 0x1BC8CC
extern int d_1bdcf8;                    // 0x1BDCF8
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c0218;                    // 0x1C0218
extern int d_1c021c;                    // 0x1C021C
extern signed char d_1c0220;                    // 0x1C0220
extern int d_1c0224;                    // 0x1C0224
extern int d_1c0228;                    // 0x1C0228
extern int d_1c022c;                    // 0x1C022C
extern int d_1c0230;                    // 0x1C0230
extern signed char d_1c0234;                    // 0x1C0234
extern int d_1c0238;                    // 0x1C0238
extern int d_1c023c;                    // 0x1C023C
extern int d_1c0240;                    // 0x1C0240
extern int d_1c0244;                    // 0x1C0244
extern int d_1c0248;                    // 0x1C0248
extern signed char d_1c024c;                    // 0x1C024C
extern signed char d_1c0250;                    // 0x1C0250
extern signed char d_1c0254;                    // 0x1C0254
extern signed char d_1c0258;                    // 0x1C0258
extern signed char d_1c025c;                    // 0x1C025C
extern signed char d_1c0260;                    // 0x1C0260
extern signed char d_1c0264;                    // 0x1C0264
extern signed char d_1c0268;                    // 0x1C0268
extern signed char d_1c026c;                    // 0x1C026C
extern signed char d_1c0270;                    // 0x1C0270
extern signed char d_1c0274;                    // 0x1C0274
extern signed char d_1c0278;                    // 0x1C0278
extern signed char d_1c027c;                    // 0x1C027C
extern signed char d_1c0280;                    // 0x1C0280
extern int d_1c0284;                    // 0x1C0284
extern int d_1c0288;                    // 0x1C0288
extern int d_1c028c;                    // 0x1C028C
extern signed char d_1c0290;                    // 0x1C0290
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c27a4;                    // 0x1C27A4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c280c;                    // 0x1C280C
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a6790[];           // Text 0x1A6790

// --- Uebersteuerte/ergaenzte Prototypen und Typen (Einheit sewerag3_t1) ---
#define CT signed char
signed char f_042400(hero *p);
short f_042a60(hero *p, int i_input);
short f_0d4aa0(int p1, int p2);
int f_0d4a60(int p1);
int f_05ff60(int p1, int p2);
int f_1254a0(int p1, int p2);
void *f_112e70(int p1, int p2);
void *f_046d90(int p1, int p2);
int f_060740(int p1, int p2);
short f_060760(int p1);
int f_0607e0(int p1, int p2);
int f_060800(int p1, int p2, int p3);
short f_0de820(int p1);
short f_0db9a0(int p1);
void f_0f9a00(int p1);
void f_0f9e10(int p1, int p2, int p3);
void f_0f8300(int p1);
void f_0f86e0(int p1);
void f_0f81d0(int p1);
void f_0f8cb0(int p1);
void f_0f8dc0(int p1);
void f_0f8f90(int p1);
void f_0f9790(int p1);
void f_0f9240(int p1);
void f_0f93a0(int p1);
int f_0f94b0(int p1);
void f_0fa280(int p1, int p2);
void f_0fa570(int p1);
extern int d_1bb71c;
typedef RivaTextContextData OB;
struct SQ { signed char *p; unsigned short a; unsigned short b; unsigned short c; short d; };
#define Z ((signed char)0)
#define EQM(x,v) (((x)==(v))?1:0)
static inline int EQC(signed char a, signed char b) { return a == b; }
#define C64 ((int)&d_1c2c64)
#define MSG(n) f_0bf730(C64, n)
#define KK(n) f_147323((int)&d_1c2edc, n, 0x7fff, 0x8000, d_1a9820, 0, 1)
#define CTOR(o) f_125400((int)&(o), (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498)
#define DTOR(o) f_1254a0((int)&(o), 0)
#define OB4(o) (*(int *)((o).addresses.objects + 4))
#define OB8(o) (*(int *)((o).addresses.objects + 8))

//@ f_0f6fb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das 3D-Dungeon-Objekt für den dritten Kanalisationsabschnitt
 *   (sewerag3, Kennung 0x15), trägt die virtuelle Methodentabelle d_19dfdc ein, lädt die zugehörige
 *   .LXT-Textdatei in d_1c0324 und richtet beim erstmaligen Betreten (d_1c0357 == 0) sämtliche 50 Tür-, Gitter-,
 *   Wasserstands- und Ereigniszustände (d_1c0328 bis d_1c0359) ein.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den Konstruktor-Steuerparameter p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_0f6fb0(void)
{
  int q, t;
  { int t_ = (int)operator new(0x14, mark(d_1a6790, 0xb6)); t = (t_ != 0) ? f_112df0(t_, 0x26, 0, 0) : t_; }
  q = t;
  f_113640(q);
  if (q) operator delete(f_112e70(q, 0));
  { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xba)); t = (t_ != 0) ? f_046d10(t_, 8) : t_; }
  q = t;
  f_0477a0(q);
  if (q) operator delete(f_046d90(q, 0));
  { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xbe)); t = (t_ != 0) ? f_046d10(t_, 9) : t_; }
  q = t;
  f_0477a0(q);
  if (q) operator delete(f_046d90(q, 0));
  { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xc2)); t = (t_ != 0) ? f_046d10(t_, 10) : t_; }
  q = t;
  f_0477a0(q);
  if (q) operator delete(f_046d90(q, 0));
  { int t_ = (int)operator new(0x14, mark(d_1a6790, 0xc6)); t = (t_ != 0) ? f_112df0(t_, 0x28, 0, 0) : t_; }
  q = t;
  f_113240(q, 0x171, 10000);
  if (q) operator delete(f_112e70(q, 0));
}

//@ f_0f7120
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Filter-Prädikat prüft für einen Inventargegenstand p1, ob es sich um eine angelegte,
 *   metallische und nicht magisch vor Rost geschützte Waffe (Gegenstandstyp 1, Untertyp < 7, Materialflags ohne
 *   Rostschutz 0x10/0x20, Zustand < 4) handelt, die durch das Untertauchen im Kanalwasser rosten oder brechen
 *   kann.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf den zu prüfenden Inventargegenstand.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Waffe vom Rost betroffen ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0f7120(int p1)
{
  int r = 0;
  if (f_043d10(p1) != 0) {
    if (f_0d4a60(p1) != 0) {
      if (((CT)(f_042400((struct hero *)(p1)))) == 0) r = 1;
    }
  }
  return r;
}

//@ f_0f7160
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Filter-Prädikat prüft für einen Inventargegenstand p1, ob es sich um ein angelegtes
 *   Rüstungsteil (Gegenstandstyp 2, Zustand < 4) handelt, das beim Durchschwimmen überfluteter Kanäle Schaden
 *   nimmt.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf den Inventargegenstand.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Rüstungsteil betroffen ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0f7160(int p1)
{
  int r = 0;
  if (f_0d4a60(p1)) r = 1;
  return r;
}

//@ f_0f7180
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion durchsucht die Heldengruppe nach einem bestimmten Gegenstand p1 (etwa der Flöte
 *   oder einem Schlüssel) und entfernt bei gesetztem Flag p2 das erste gefundene Exemplar aus dem Inventar des
 *   betreffenden Helden.
 * - Eingaben: Die Funktion erhält die Gegenstands-ID p1 sowie das Lösch-Flag p2.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den Helden zurück, der den Gegenstand trägt, oder 0, falls
 *   kein Held ihn besitzt.
 === Ende Beschreibung === */
int f_0f7180(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1 && ((CT)(f_042400((struct hero *)(p1)))) == 0) {
    if (f_042a60((struct hero *)(p1), 2) == 0x18c || f_042a60((struct hero *)(p1), 0xb) == 0x18c) r = 1;
  }
  return r;
}

//@ f_0f71e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle Helden der Gruppe nach dem Gegenstand p1 und gibt den
 *   Gegenstandszeiger aus dem Inventar des ersten passenden Helden zurück.
 * - Eingaben: Die Funktion erhält die gesuchte Gegenstands-ID p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf das Gegenstandsobjekt im Inventar oder 0 zurück.
 === Ende Beschreibung === */
int f_0f71e0(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (((CT)(f_042400((struct hero *)(p1)))) == 0) {
      if (f_0d4aa0(p1, 0x18c) != -1) r = 1;
    }
  }
  return r;
}

//@ f_0f7220
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob irgendein Held der Gruppe den Gegenstand p1 ausgerüstet oder im Gepäck hat,
 *   und liefert den Zeiger auf diesen Helden zurück.
 * - Eingaben: Die Funktion erhält die Gegenstands-ID p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den gefundenen Helden oder 0 zurück.
 === Ende Beschreibung === */
int f_0f7220(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (((CT)(f_042400((struct hero *)(p1)))) == 0) {
      if (f_0d4aa0(p1, 399) != -1) r = 1;
    }
  }
  return r;
}

struct X0f7260 : B05ff60 { X0f7260(); virtual ~X0f7260(){ } };   // inline-virtueller Destruktor -> COMDAT $dt:X0f7260 = f_0faba0
//@ f_0f7260
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt beim Verlassen des dritten Kanalisationsabschnitts den geladenen
 *   .LXT-Textpuffer d_1c0324 wieder frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
X0f7260::X0f7260() : B05ff60(3) { }   // Konstruktor, setzt vtable; erzeugt $dt:X0f7260 als COMDAT am Modulende (= f_0faba0)
//@ f_0f7280
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode initialisiert die 3D-Geometrie und die speziellen Paletten- und Wassereffekte
 *   (f_120bd0, f_122cd0, f_123080) des dritten Kanalisationsabschnitts, startet den Hintergrundklang und
 *   aktualisiert die beweglichen Gitter, Schleusen und Fallen (f_0fa1c0, f_0fa280).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_0f7280(void)
{
  int v;
  f_060240();
  if (EQM(d_1c0220, 0)) {
    f_147323((int)&d_1c2edc, 0x250023, 0x7fff, 0x8000, (v = d_1a9820), 0, 1);
    MSG(0x250000b1);
    d_1c0220 = 1;
  }
}

int f_0f94a0(int p);
//@ f_0f72e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Ereignis-Verteilerfunktion verarbeitet sämtliche ortsgebundenen Aktionen und Auslöser
 *   (0x00 bis 0x41) im dritten Kanalisationsabschnitt, darunter Gittertore, Schleusenräder, verrostete
 *   Mechanismen, Kämpfe gegen Ratten und Goblins, das Rattenfänger-Versteck, den Käfig sowie Übergänge in
 *   Nachbarbereiche.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktions- oder
 *   Richtungszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Statuscode der ausgelösten Interaktion zurück.
 === Ende Beschreibung === */
int f_0f72e0(int p1, unsigned short p2)
{
  int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  OB objs[10];
  int r;
  *(int *)&r = 1; // KRUECKE Adressnahme haelt Ergebnisslot ohne volatile-Planerkanten
  struct SQ *e;
  int a, b, k;
  short s;

  switch (p2) {
  case 0x65:
    { signed char zero = 0;
    if (EQM((int)d_1c0290, zero)) {
      f_125ed0((int)&d_1c2c44, 5);
      MSG(0x250000b2);
    } else if (f_0bf6f0(C64, 0x250000b3) == 1) {
      f_0dd7f0(d_1c0004, 2, 0x18b7);
    }
    break; }

  case 0x67:
    f_0f8300(p1);
    break;

  case 0x68:
    { int item = 0x1f4b;
    s = f_060760((unsigned short)item);
    if (d_1c0218 == 0 && s == 1) {
      CTOR(objs[2]);
      a = f_0397d0(d_1c0004, 0x1a);
      if (a == 0) a = f_038ba0(d_1c0004);
      OB4(objs[2]) = a;
      MSG(0x250000ba);
      d_1c0218 = 1;
      DTOR(objs[2]);
    }
    break; }

  case 0x69:
    f_0f86e0(p1);
    break;

  case 0x6b:
    { signed char zero = 0;
    int cond = EQM((int)d_1c0234, zero);
    e = (struct SQ *)&d_1a67b0;
    e = (struct SQ *)((char *)e + 0x18);
    if (cond) {
      f_060740(e->a, 1);
      f_147323_frame((int)&d_1c2edc, 0x25001e, 0x7fff, 0x8000, (k = d_1a9820), 0, 1);
      f_060740(e->b, 1);
      f_147323((int)&d_1c2edc, 0x250024, 0x7fff, 0x8000, (k = d_1a9820), 0, 1);
      f_0607e0(e->c, 1);
      *e->p = 1;
    } else {
      f_060740(e->a, 1);
      f_147323((int)&d_1c2edc, 0x25001e, 0x7fff, 0x8000, (k = d_1a9820), 0, 1);
      f_060740(e->b, 1);
      f_147323((int)&d_1c2edc, 0x250025, 0x7fff, 0x8000, (k = d_1a9820), 0, 1);
      f_0607e0(e->c, 0);
      *e->p = 0;
      f_0fa280(p1, e->d);
    }
    break; }

  case 0x6c:
    { int item = 0x1f4d;
    s = f_060760((unsigned short)item);
    if (d_1c0218 == 0 && s == 1) {
      CTOR(objs[8]);
      a = f_0397d0(d_1c0004, 0x1a);
      if (a == 0) {
        { int rt80 = d_1a9820; d_1a9820 = rt80; } // KRUECKE berechneter Sortierhebel
      { int same = d_1c0218; d_1c0218 = same; } // KRUECKE Sortierposition 80
        a = f_038ba0(d_1c0004);
      }
      OB4(objs[8]) = a;
      MSG(0x250000ba);
      d_1c0218 = 1;
      DTOR(objs[8]);
    }
    break; }

  case 0xc9:
    f_0f8cb0(p1);
    break;
  case 0xca:
    f_0f8dc0(p1);
    break;

  case 0x12e:
    { signed char zero = 0;
    if (EQM((int)d_1c0280, zero)) {
      f_147323((int)&d_1c2edc, 0x250026, 0x7fff, 0x8000, (k = d_1a9820), 0, 1);
      { int saved_group = d_1c0218; d_1c0218 = saved_group; } // KRUECKE Sortiergleichstand, codeloser Global-Roundtrip
      s = f_0db9a0(d_1c0004);
      if (1 < s) {
        CTOR(objs[5]);
        a = f_0396f0(d_1c0004, 0);
        b = f_039c50(d_1c0004, a);
        OB4(objs[5]) = a;
        OB8(objs[5]) = b;
        MSG(0x250000cc);
        d_1c0280 = 1;
        DTOR(objs[5]);
      }
    }
    break; }

  case 0x12f:
    f_0f8f90(p1);
    break;

  case 0x131:
    if (f_0bf6f0(C64, 0x250000d0) == 1)
      f_0dd7f0(d_1c0004, 6, 5000);
    break;

  case 0x191:
  case 0x194:
  case 0x195:
    { signed char zero = 0;
    if (EQM((int)d_1c0254, zero)) {
      MSG(0x250000d1);
      { int rt137 = d_1c0218; d_1c0218 = rt137; } // KRUECKE berechneter Sortierhebel
      f_0dcae0(d_1c0004);
      d_1c0254 = 1;
    }
    break; }

  case 0x1f5:
    { { int rt141 = d_1c0218; d_1c0218 = rt141; } // KRUECKE berechneter Sortierhebel
      signed char zero = 0;
    if (EQM((int)d_1c024c, zero)) {
      MSG(0x250000d2);
      d_1c024c = 1;
    }
    f_0603b0(0x26);
    break; }

  case 0x1f6:
    f_0f9240(p1);
    break;
  case 0x259:
    f_0f93a0(p1);
    break;

  case 0x25a:
    { { int rt152 = d_1c0218; d_1c0218 = rt152; } // KRUECKE berechneter Sortierhebel
      signed char zero = 0;
    if (EQM((int)d_1c0258, zero)) {
      MSG(0x250000d9);
    } else {
      CTOR(objs[3]);
      a = f_039c90(d_1c0004, (int)f_0f94b0, (int)f_0f94a0);
      OB4(objs[3]) = a;
      MSG(0x250000da);
      { int rt148 = d_1c0218; d_1c0218 = rt148; } // KRUECKE berechneter Sortierhebel
      DTOR(objs[3]);
    }
    break; }

  case 0x25b:
    { signed char zero = 0;
    if (EQM((int)d_1c0260, zero)) {
      CTOR(objs[1]);
      a = f_039420(d_1c0004, 0x26);
      b = f_039320(d_1c0004, 0x26);
      OB4(objs[1]) = a;
      OB8(objs[1]) = b;
      MSG(0x250000db);
      if (b != a) MSG(0x250000dc);
      d_1c0260 = 1;
      DTOR(objs[1]);
    }
    break; }

  case 0x2bd:
    { signed char zero = 0;
    if (EQM((int)d_1c0264, zero)) {
      MSG(0x250000dd);
      d_1c0264 = 1;
    }
    break; }

  case 0x2be:
    {
    { int same = d_1c0218; d_1c0218 = same; } // KRUECKE Sortierposition 182
    signed char one = 1;
    if (EQM((int)d_1c0258, one) && EQM((int)d_1c025c, 0)) {
      CTOR(objs[4]);
      a = f_039660(d_1c0004, 7);
      OB4(objs[4]) = a;
      MSG(0x250000de);
      s = f_0db9a0(d_1c0004);
      if (1 < s) MSG(0x250000df);
      d_1c025c = 1;
      DTOR(objs[4]);
    }
    break; }

  case 0x2bf:
    {
    { int same = d_1c0218; d_1c0218 = same; } // KRUECKE Sortierposition 187
    signed char zero = 0;
    if (EQM((int)d_1c026c, zero)) {
      MSG(0x250000e0);
      d_1c026c = 1;
    }
    f_0603b0(0x28);
    break; }

  case 0x321:
    { signed char zero = 0;
    if (EQM((int)d_1c0270, zero)) {
      CTOR(objs[9]);
      a = f_038c40(d_1c0004);
      OB4(objs[9]) = a;
      MSG(0x250000e1);
      MSG(0x250000e2);
      d_1c0270 = 1;
      DTOR(objs[9]);
    }
    break; }

  case 0x385:
    f_0f9790(p1);
    break;
  case 0x386:
    f_060360(9);
    break;
  case 0x387:
    MSG(0x250000e5);
    break;

  case 0x3f3:
    { int rt241 = d_1c0218; d_1c0218 = rt241; } // KRUECKE berechneter Sortierhebel
      f_0f9e10(p1, 0x14b4, 0x1518);
    break;
  case 0x3f4:
    f_0f9e10(p1, 0x14b4, 0x1462);
    break;
  case 0x3fd:
    f_0f9e10(p1, 0x15e0, 0x164d);
    break;
  case 0x3fe:
    f_0f9e10(p1, 0x15e0, 0x1597);
    break;
  case 0x409:
    f_0f9e10(p1, 0x170c, 0x16c3);
    break;
  case 0x408:
    f_0f9e10(p1, 0x170c, 0x1779);
    break;
  case 0x3ec:
    f_0f9a00(p1);
    break;

  case 0x3ed:
    { signed char zero = 0;
    if (EQM((int)d_1c0278, zero)) {
      CTOR(objs[0]);
      a = f_038c40(d_1c0004);
      OB4(objs[0]) = a;
      if (EQM((int)d_1c0274, 1)) MSG(0x250000f0);
      MSG(0x250000f1);
      d_1c0278 = 1;
      DTOR(objs[0]);
    }
    break; }

  case 0x3ef:
    { signed char zero = 0;
    if (EQM((int)d_1c0268, zero)) {
      MSG(0x250000dd);
      d_1c0268 = 1;
    }
    break; }

  case 0x3f0:
    { signed char zero = 0;
    if (EQM((int)d_1c0250, zero)) {
      CTOR(objs[6]);
      a = f_038c40(d_1c0004);
      OB4(objs[6]) = a;
      MSG(0x250000f3);
      d_1c0250 = 1;
      DTOR(objs[6]);
    }
    break; }

  case 0x1b60:
  case 0x1f48:
    f_05fa00(0x1a, 0x1f48);
    break;
  case 0x1b61:
  case 0x1f49:
    f_05fa00(0x1b, 0x1f49);
    break;
  case 0x1b5f:
  case 0x1f47:
    f_05fa00(0x1c, 0x1f47);
    break;
  case 0x1b59:
  case 0x1f41:
    f_05fa00(0x1f, 0x1f41);
    break;
  case 0x1b5a:
  case 0x1f42:
    f_05fa00(0x21, 0x1f42);
    break;
  case 0x1b5c:
  case 0x1f44:
    f_05fa00(0x22, 0x1f44);
    break;
  case 0x1b5d:
  case 0x1f45:
    f_05fa00(0x24, 0x1f45);
    break;
  case 0x1b5e:
  case 0x1f46:
    f_05fa00(0x1d, 0x1f46);
    break;
  case 0x1b5b:
  case 0x1f43:
    f_05fa00(0x23, 0x1f43);
    break;

  case 0x3ee:
    { { int rt222 = d_1c0218; d_1c0218 = rt222; } // KRUECKE berechneter Sortierhebel
      signed char zero = 0;
    if (EQM((int)d_1c027c, zero)) {
      MSG(0x250000f2);
      d_1c027c = 1;
    }
    break; }

  case 0x12d:
  case 0x44d:
    break;

  case 0x130:
    if (f_060760(0x1f4f) == 1) {
      MSG(0x250000cf);
      f_060740(0x1f4f, 1);
      f_0607e0(0x1f4f, 1);
      f_0607e0(0x1f50, 1);
    }
    f_060800(0x25000a, 0, 0);
    f_060740(0x1f4f, 1);
    f_0607e0(0x1f4f, 0);
    f_0607e0(0x1f50, 0);
    break;

  case 0x6a:
    { int item = 0x1f4c;
    s = f_060760((unsigned short)item);
    if (d_1c0218 == 0 && s == 1) {
      CTOR(objs[7]);
      a = f_0397d0(d_1c0004, 0x1a);
      if (a == 0) a = f_038ba0(d_1c0004);
      OB4(objs[7]) = a;
      MSG(0x250000ba);
      d_1c0218 = 1;
      DTOR(objs[7]);
    }
    break; }

  case 0x66:
    f_0f81d0(p1);
    break;

  default:
    r = 0;
    break;
  }

  if (f_0de820(d_1c0004) == 3)
    f_0fa570(p1);
  return r;
}

//@ f_0f8160
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die automatischen Schritt- und betretungsabhängigen Auslöser (0x00 bis
 *   0x05) im dritten Kanalisationsabschnitt, insbesondere die Flötenmelodie des Rattenfängers (f_0f8300) und
 *   Kämpfe an bestimmten Gangkreuzungen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Auslöserindex p2 sowie einen Ergebniszeiger p3.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_0f8160(void)
{
  if (EQM(d_1c0290, 0)) {
    f_125ed0((int)&d_1c2c44, 5);
    MSG(0x250000b2);
    return;
  }
  if (f_0bf6f0(C64, 0x250000b3) == 1) f_0dd7f0(d_1c0004, 2, 0x18b7);
}

#undef C64
#undef CT
#undef CTOR
#undef DTOR
#undef EQM
#undef KK
#undef MSG
#undef OB
#undef OB4
#undef OB8
#undef Z
#undef d_1a6790
#undef d_1a67b0
#undef d_1a67b4
#undef d_1a67b6
#undef d_1a67b8
#undef d_1a67ba
#undef d_1a67bc
#undef d_1a67c0
#undef d_1a67c2
#undef d_1a67c4
#undef d_1a67c6
#undef d_1a67c8
#undef d_1a67cc
#undef d_1a67ce
#undef d_1a67d0
#undef d_1a67d2
#undef d_1a9820
#undef d_1bc8cc
#undef d_1bdcf8
#undef d_1bf230
#undef d_1bfdbc
#undef d_1c0004
#undef d_1c0028
#undef d_1c0218
#undef d_1c021c
#undef d_1c0220
#undef d_1c0224
#undef d_1c0228
#undef d_1c022c
#undef d_1c0230
#undef d_1c0234
#undef d_1c0238
#undef d_1c023c
#undef d_1c0240
#undef d_1c0244
#undef d_1c0248
#undef d_1c024c
#undef d_1c0250
#undef d_1c0254
#undef d_1c0258
#undef d_1c025c
#undef d_1c0260
#undef d_1c0264
#undef d_1c0268
#undef d_1c026c
#undef d_1c0270
#undef d_1c0274
#undef d_1c0278
#undef d_1c027c
#undef d_1c0280
#undef d_1c0284
#undef d_1c0288
#undef d_1c028c
#undef d_1c0290
#undef d_1c21a4
#undef d_1c23a8
#undef d_1c27a4
#undef d_1c27a8
#undef d_1c280c
#undef d_1c2c00
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_0366e0
#undef f_038ba0
#undef f_038c40
#undef f_038c80
#undef f_039040
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0396f0
#undef f_0397d0
#undef f_039a10
#undef f_039a80
#undef f_039ac0
#undef f_039b00
#undef f_039b70
#undef f_039c50
#undef f_039c90
#undef f_041000
#undef f_041030
#undef f_041530
#undef f_041920
#undef f_0422b0
#undef f_042350
#undef f_042380
#undef f_042400
#undef f_042470
#undef f_0424e0
#undef f_0425f0
#undef f_042960
#undef f_042a60
#undef f_043d10
#undef f_043e20
#undef f_044300
#undef f_044850
#undef f_044900
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046eb0
#undef f_0471b0
#undef f_0477a0
#undef f_057220
#undef f_05f190
#undef f_05f220
#undef f_05f470
#undef f_05f480
#undef f_05f800
#undef f_05fa00
#undef f_05ff60
#undef f_060240
#undef f_060360
#undef f_0603b0
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060800
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4800
#undef f_0d4a60
#undef f_0d4aa0
#undef f_0d54f0
#undef f_0d64a0
#undef f_0db9a0
#undef f_0dbad0
#undef f_0dc020
#undef f_0dc050
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcc10
#undef f_0dcc40
#undef f_0dcdf0
#undef f_0dcf00
#undef f_0dd100
#undef f_0dd1d0
#undef f_0dd4f0
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de020
#undef f_0de0d0
#undef f_0de210
#undef f_0de7c0
#undef f_0de7d0
#undef f_0de7f0
#undef f_0de810
#undef f_0de820
#undef f_0de9d0
#undef f_0de9e0
#undef f_0de9f0
#undef f_0f81d0
#undef f_0f8300
#undef f_0f86e0
#undef f_0f8cb0
#undef f_0f8dc0
#undef f_0f8f90
#undef f_0f9240
#undef f_0f93a0
#undef f_0f94b0
#undef f_0f9790
#undef f_0f9a00
#undef f_0f9e10
#undef f_0fa280
#undef f_0fa570
#undef f_0faa10

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_113240
#undef f_113340
#undef f_113640
#undef f_1223c0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0
#undef f_147323

// ===== Teil sewerag3_t2 (p3, 0f81d0-0f93a0) =====
#define d_1a6790 d_1a6790_k2
#define d_1a67b0 d_1a67b0_k2
#define d_1a9820 d_1a9820_k2
#define d_1bc8cc d_1bc8cc_k2
#define d_1bdcf8 d_1bdcf8_k2
#define d_1bf230 d_1bf230_k2
#define d_1bfdbc d_1bfdbc_k2
#define d_1c0004 d_1c0004_k2
#define d_1c0028 d_1c0028_k2
#define d_1c0218 d_1c0218_k2
#define d_1c021c d_1c021c_k2
#define d_1c0220 d_1c0220_k2
#define d_1c0224 d_1c0224_k2
#define d_1c0228 d_1c0228_k2
#define d_1c022c d_1c022c_k2
#define d_1c0230 d_1c0230_k2
#define d_1c0234 d_1c0234_k2
#define d_1c0238 d_1c0238_k2
#define d_1c023c d_1c023c_k2
#define d_1c0240 d_1c0240_k2
#define d_1c0244 d_1c0244_k2
#define d_1c0248 d_1c0248_k2
#define d_1c024c d_1c024c_k2
#define d_1c0250 d_1c0250_k2
#define d_1c0254 d_1c0254_k2
#define d_1c0258 d_1c0258_k2
#define d_1c025c d_1c025c_k2
#define d_1c0260 d_1c0260_k2
#define d_1c0264 d_1c0264_k2
#define d_1c0268 d_1c0268_k2
#define d_1c026c d_1c026c_k2
#define d_1c0270 d_1c0270_k2
#define d_1c0274 d_1c0274_k2
#define d_1c0278 d_1c0278_k2
#define d_1c027c d_1c027c_k2
#define d_1c0280 d_1c0280_k2
#define d_1c0284 d_1c0284_k2
#define d_1c0288 d_1c0288_k2
#define d_1c028c d_1c028c_k2
#define d_1c0290 d_1c0290_k2
#define d_1c21a4 d_1c21a4_k2
#define d_1c23a8 d_1c23a8_k2
#define d_1c27a4 d_1c27a4_k2
#define d_1c27a8 d_1c27a8_k2
#define d_1c280c d_1c280c_k2
#define d_1c2c00 d_1c2c00_k2
#define d_1c2c44 d_1c2c44_k2
#define d_1c2c64 d_1c2c64_k2
#define d_1c2edc d_1c2edc_k2
#define d_1c3498 d_1c3498_k2
#define d_1c349c d_1c349c_k2
#define d_1c3870 d_1c3870_k2
#define f_0104b0 f_0104b0_k2
#define f_010590 f_010590_k2
#define f_0366e0 f_0366e0_k2
#define f_038ba0 f_038ba0_k2
#define f_038c40 f_038c40_k2
#define f_038c80 f_038c80_k2
#define f_039040 f_039040_k2
#define f_039320 f_039320_k2
#define f_039420 f_039420_k2
#define f_039660 f_039660_k2
#define f_0396f0 f_0396f0_k2
#define f_0397d0 f_0397d0_k2
#define f_039a10 f_039a10_k2
#define f_039a80 f_039a80_k2
#define f_039ac0 f_039ac0_k2
#define f_039b00 f_039b00_k2
#define f_039b70 f_039b70_k2
#define f_039c50 f_039c50_k2
#define f_039c90 f_039c90_k2
#define f_041000 f_041000_k2
#define f_041030 f_041030_k2
#define f_041530 f_041530_k2
#define f_041920 f_041920_k2
#define f_0422b0 f_0422b0_k2
#define f_042350 f_042350_k2
#define f_042380 f_042380_k2
#define f_042400 f_042400_k2
#define f_042470 f_042470_k2
#define f_0424e0 f_0424e0_k2
#define f_0425f0 f_0425f0_k2
#define f_042960 f_042960_k2
#define f_042a60 f_042a60_k2
#define f_043d10 f_043d10_k2
#define f_043e20 f_043e20_k2
#define f_044300 f_044300_k2
#define f_044850 f_044850_k2
#define f_044900 f_044900_k2
#define f_044c90 f_044c90_k2
#define f_046d10 f_046d10_k2
#define f_046d90 f_046d90_k2
#define f_046de0 f_046de0_k2
#define f_046eb0 f_046eb0_k2
#define f_0471b0 f_0471b0_k2
#define f_0477a0 f_0477a0_k2
#define f_057220 f_057220_k2
#define f_05f190 f_05f190_k2
#define f_05f220 f_05f220_k2
#define f_05f470 f_05f470_k2
#define f_05f480 f_05f480_k2
#define f_05f800 f_05f800_k2
#define f_05fa00 f_05fa00_k2
#define f_05ff60 f_05ff60_k2
#define f_060240 f_060240_k2
#define f_060360 f_060360_k2
#define f_0603b0 f_0603b0_k2
#define f_0606a0 f_0606a0_k2
#define f_060740 f_060740_k2
#define f_060760 f_060760_k2
#define f_0607e0 f_0607e0_k2
#define f_060800 f_060800_k2
#define f_060a70 f_060a70_k2
#define f_091f70 f_091f70_k2
#define f_0bbf00 f_0bbf00_k2
#define f_0bf6f0 f_0bf6f0_k2
#define f_0bf730 f_0bf730_k2
#define f_0bf980 f_0bf980_k2
#define f_0bfa20 f_0bfa20_k2
#define f_0d4800 f_0d4800_k2
#define f_0d4aa0 f_0d4aa0_k2
#define f_0d54f0 f_0d54f0_k2
#define f_0d64a0 f_0d64a0_k2
#define f_0db9a0 f_0db9a0_k2
#define f_0dbad0 f_0dbad0_k2
#define f_0dc020 f_0dc020_k2
#define f_0dc050 f_0dc050_k2
#define f_0dcae0 f_0dcae0_k2
#define f_0dcbb0 f_0dcbb0_k2
#define f_0dcc10 f_0dcc10_k2
#define f_0dcc40 f_0dcc40_k2
#define f_0dcdf0 f_0dcdf0_k2
#define f_0dcf00 f_0dcf00_k2
#define f_0dd100 f_0dd100_k2
#define f_0dd1d0 f_0dd1d0_k2
#define f_0dd4f0 f_0dd4f0_k2
#define f_0dd750 f_0dd750_k2
#define f_0dd7f0 f_0dd7f0_k2
#define f_0de020 f_0de020_k2
#define f_0de0d0 f_0de0d0_k2
#define f_0de210 f_0de210_k2
#define f_0de7c0 f_0de7c0_k2
#define f_0de7d0 f_0de7d0_k2
#define f_0de7f0 f_0de7f0_k2
#define f_0de810 f_0de810_k2
#define f_0de820 f_0de820_k2
#define f_0de9d0 f_0de9d0_k2
#define f_0de9e0 f_0de9e0_k2
#define f_0de9f0 f_0de9f0_k2
#define f_0f2720 f_0f2720_k2
#define f_0f9dc0 f_0f9dc0_k2
#define f_0fa280 f_0fa280_k2
#define f_0fa340 f_0fa340_k2
#define f_0faa10 f_0faa10_k2

#define f_112df0 f_112df0_k2
#define f_112e70 f_112e70_k2
#define f_112ec0 f_112ec0_k2
#define f_1131b0 f_1131b0_k2
#define f_113240 f_113240_k2
#define f_113340 f_113340_k2
#define f_113640 f_113640_k2
#define f_1223c0 f_1223c0_k2
#define f_125400 f_125400_k2
#define f_1254a0 f_1254a0_k2
#define f_125ed0 f_125ed0_k2
#define f_133fe0 f_133fe0_k2
#define OB OB_k2
// P3 12/16 gleich (suche.py 25.10.2026, Basis sewerag3_t2_P1.CPP)
// OPT-aus-Teil (gilt nicht fuer das Modul) -4r -onetx -zp1 -s
// P1 8/16 gleich
// sewerag3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F6FB0-0x0FA9B0
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_039c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041530();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
char * f_0422b0(hero *p);                                   // reg eax stapel 0
signed char f_042350(hero *p);                                   // reg eax stapel 0
unsigned char f_042470(hero *p);                                   // reg eax stapel 0
unsigned char f_0424e0(hero *p);                                   // reg eax stapel 0
unsigned char f_0425f0(hero *p);                                   // reg eax stapel 0
short f_042960(hero *p);                                   // reg eax stapel 0
short f_042a60(hero *p, int i_input);                           // reg eax edx stapel 0
int f_043d10(int p1);                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046eb0(int p1);                                   // reg eax stapel 0
int f_0471b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0477a0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f800(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_060240();                                         // reg - stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf980();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0dbad0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd4f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de020(int p1, int p2);                           // reg eax edx stapel 0
int f_0de0d0(int p1);                                   // reg eax stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0faa10(int p1, int p2);                           // reg edx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113240(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc8cc;                    // 0x1BC8CC
extern int d_1bdcf8;                    // 0x1BDCF8
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c0218;                    // 0x1C0218
extern int d_1c021c;                    // 0x1C021C
extern int d_1c0220;                    // 0x1C0220
extern int d_1c0250;                    // 0x1C0250
extern int d_1c0258;                    // 0x1C0258
extern int d_1c025c;                    // 0x1C025C
extern int d_1c0260;                    // 0x1C0260
extern int d_1c0264;                    // 0x1C0264
extern int d_1c0268;                    // 0x1C0268
extern int d_1c026c;                    // 0x1C026C
extern int d_1c0270;                    // 0x1C0270
extern int d_1c0274;                    // 0x1C0274
extern int d_1c0278;                    // 0x1C0278
extern int d_1c027c;                    // 0x1C027C
extern int d_1c0284;                    // 0x1C0284
extern int d_1c0288;                    // 0x1C0288
extern int d_1c0290;                    // 0x1C0290
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c27a4;                    // 0x1C27A4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c280c;                    // 0x1C280C
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern short d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a6790[];           // Text 0x1A6790
// --- Einheit sewerag3_t2: 0f81d0 .. 0f93a0 ---
extern char d_1c2edc[];
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
#define EQI(x,v) (((x)==(v))?1:0)
#define C64 ((int)&d_1c2c64)
#define C00 ((int)&d_1c2c00)
#define C44 ((int)&d_1c2c44)
#define OBA ((int)&ob)
#define SND(id) f_147323((int)d_1c2edc, id, 0x7fff, 0x8000, d_1a9820, 0, 1)
#define DELP(x) operator delete((void *)(x));
typedef RivaTextContextData OB;
struct E {char *p; unsigned short a, b, c; short d;};
typedef int (*FP3)(int, int, int);
extern signed char d_1c0224, d_1c0228, d_1c022c, d_1c0230, d_1c0234, d_1c0238, d_1c023c, d_1c0240, d_1c0244, d_1c0248, d_1c024c, d_1c0254, d_1c0280, d_1c028c;
extern struct E d_1a67b0[3];
signed char f_042380(hero *p);
signed char f_042400(hero *p);
int f_0f2720(int p1, int p2, int p3, int p4);
void f_1254a0(int p1, int p2);
int f_041030(int, ...);
int f_0bfa20(int, ...);
short f_060760(int p1);
int f_060740(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
int f_0db9a0(int p1);
short f_0de820(int p1);
short f_0de9e0(int p1);
int f_0fa280(int p1, int p2);
void f_0f9dc0(void);
void f_0fa340(void);
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0f81d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert die periodischen Hintergrundereignisse im dritten Kanalisationsabschnitt: Sie
 *   lässt die Fackel oder Laterne im Käfig herunterbrennen (d_1c034c), heilt oder verändert Zustände
 *   eingesperrter Helden und löst bei Annäherung an das Rattenfänger-Quartier die hypnotische Flötenmusik
 *   (f_0f9950) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 und einen Statuszeiger p3.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
extern int f_038c40(int p1);
extern int f_039320(int p1, int p2);
void f_0f81d0(void)
{
  OB ob;
  int r;
  short s;
  int c;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  s = f_060760(0x1f4a);
  if (s == 1) {
    r = 0;
    if (EQI(d_1c0224, 1)) {
      int t = f_038c40(d_1c0004);
      *(int *)(ob.addresses.objects + 4) = t;
      f_0bf730(C64, 0x250000b4);
      r = 1;
    } else {
      if (EQI(d_1c0228, 1)) {
        c = f_039320(d_1c0004, 0x33);
        if (f_044c90(c, 0x33, 0x19) > 0) {
          *(int *)(ob.addresses.objects + 4) = c;
          f_0bf730(C64, 0x250000b5);
          r = 1;
        }
      }
    }
    if (r == 1) {
      f_060740(0x1f4a, 1);
      f_0607e0(0x1f4a, 1);
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001f, 0x7fff, 0x8000, snd, 0, 1); }
    }
  }
  f_1254a0(OBA, 0);
}
//@ f_0f8300
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion inszeniert die Begegnung mit dem Rattenfänger von Riva: Sie prüft, ob sich die Helden
 *   die Ohren mit Wachs (0x120) verstopft haben, lässt ungeschützte Helden dem Flötenspiel verfallen, führt den
 *   Dialog mit dem Rattenfänger (0x2500001b ff.) und startet je nach Ausgang entweder den Kampf oder die
 *   Gefangennahme.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f8300(int p1)
{
  OB ob;
  int iv, pv, q;
  short k;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  short t_219 = f_0db9a0(d_1c0004);
  if (t_219 > 1) {
    if (EQI(d_1c022c, 0)) {
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
      f_060740(0x67, 1);
      f_0d4800(0x1e);
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
      f_060740(0x67, 1);
      int t_232 = f_0bf6f0(C64, 0x250000b6);
      if (t_232 == 1) {
        iv = f_039a10(d_1c0004, 0x250000b7, (int)f_0f9dc0);
        if (iv != 0) {
          pv = f_041030(1, iv);
          f_0bbf00((int)&d_1bf230);
          f_0de9f0(pv, 1);
          *(int *)(ob.addresses.objects + 4) = iv;
          f_060740((unsigned)d_1a67b0[0].a, 1);
          { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
          f_060740((unsigned)d_1a67b0[0].b, 1);
          { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x250024, 0x7fff, 0x8000, snd, 0, 1); }
          f_0607e0((unsigned)d_1a67b0[0].c, 1);
          *(volatile char *)d_1a67b0[0].p = 1;
          f_1254a0(OBA, 0);
          return;
        }
      }
    } else {
      iv = 0;
      for (k = 0; k < 6; k++) {
            q = (int)&d_1bfdbc + k * 0x61;
            if (q != d_1c0004) {
              int t_256 = f_0de7c0(q);
              if (t_256 == 1) {
                if (f_0de820(q) == 3) {
                  if (f_0de9e0(q) == 1) {
                    iv = q;
                  }
                }
              }
            }
      }
      f_0de9f0(iv, 0);
      f_041530();
      f_0bbf00((int)&d_1bf230);
      f_060740((unsigned)d_1a67b0[0].a, 1);
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
      f_060740((unsigned)d_1a67b0[0].b, 1);
      { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x250025, 0x7fff, 0x8000, snd, 0, 1); }
      f_0607e0((unsigned)d_1a67b0[0].c, 0);
      *d_1a67b0[0].p = 0;
      f_0fa280(p1, d_1a67b0[0].d);
      f_1254a0(OBA, 0);
      return;
    }
  } else {
    { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
    f_060740(0x67, 1);
    f_0d4800(0x1e);
    { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, snd, 0, 1); }
    f_060740(0x67, 1);
    f_0bf730(C64, 0x250000b9);
  }
  f_1254a0(OBA, 0);
}
//@ f_0f8650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wickelt ein versperrtes Gitter oder Hindernis ab, das beim ersten Betreten den Text
 *   0x25000037 ausgibt und anschließend über eine Schleusen- oder Hebelprobe (f_0f9100) geöffnet werden kann.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt 0 bei Erfolg oder 3 bei Abbruch zurück.
 === Ende Beschreibung === */
void f_0f8650(void)
{
  OB ob;
  int r;
  short s;
  s = f_060760(0x1f4b);
  if (d_1c0218 == 0 && s == 1) {
    f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    r = f_0397d0(d_1c0004, 0x1a);
    if (r == 0) r = f_038ba0(d_1c0004);
    *(int *)(ob.addresses.objects + 4) = r;
    f_0bf730(C64, 0x250000ba);
    d_1c0218 = 1;
    f_1254a0(OBA, 0);
  }
}
//@ f_0f86e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Interaktionsroutine verwaltet einen mehrstufigen Untersuchungs- und
 *   Plünderungsplatz im Kanal (Zustand d_1c0334), an dem die Helden Leichen oder Nischen durchsuchen, Münzen und
 *   Beutestücke (0x1b, 0xaa, 0x168) bergen und bei Unvorsichtigkeit Rattenbisse oder Krankheiten erleiden
 *   können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f86e0(int p1)
{
  int f_060740_three(int, int, int);
  #pragma aux f_060740_three "f_060740" parm [eax] [edx] [ebx] modify exact [eax edx]
  OB ob;
  int t;
  struct E *e;
  int c;
  int p01, q, u1, u4;
  short k;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  c = EQI(d_1c0230, 0);
  e = d_1a67b0;
  e++;
  if (c) {
    f_060740((unsigned)e->a, 1);
    int s1 = d_1a9820;
    f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, s1, 0, 1);
    f_060740((unsigned)e->b, 1);
    int s2 = d_1a9820;
    f_147323((int)d_1c2edc, 0x250024, 0x7fff, 0x8000, s2, 0, 1);
    f_0607e0((unsigned)e->c, 1);
    *e->p = 1;
    if (EQI(d_1c0224, 0) && EQI(d_1c0228, 0) && EQI(d_1c022c, 1)) {
      p01 = 0;
      for (k = 0; k < 6; k++) {
        q = (int)&d_1bfdbc + k * 0x61;
        if (q != d_1c0004) {
          if (f_0de7c0(q) == 1) {
            if (f_0de820(q) == 3) {
              if (f_0de9e0(q) == 1) {
                p01 = q;
              }
            }
          }
        }
      }
      u4 = f_039320(d_1c0004, 0x33);
      t = f_038c40(d_1c0004);
      u1 = f_038c40(p01);
      f_060740((unsigned)d_1a67b0[0].a, 1);
      f_060740((unsigned)d_1a67b0[0].b, 1);
      f_0607e0((unsigned)d_1a67b0[0].c, 0);
      *d_1a67b0[0].p = 0;
      f_0fa280(p1, d_1a67b0[0].d);
      d_1c0228 = 1;
      *(int *)(ob.addresses.objects + 4) = u1;
      *(int *)(ob.addresses.objects + 8) = u4;
      f_0bf730(C64, 0x250000bc);
      f_060800(0x250002, 1, 0);
      f_0bf730(C64, 0x250000bd);
      f_125ed0(C44, 5);
      *(int *)(ob.addresses.objects + 0xc) = t;
      f_0bf730(C64, 0x250000be);
      f_060740_three(0x1f4b, 1, u4 = 0);
      d_1c0224 = 1;
      f_060800(0x250004, 1, u4);
      f_0de9f0(p01, 0);
      f_041530();
      f_0bbf00((int)&d_1bf230);
      *(int *)(ob.addresses.objects + 4) = u1;
      *(int *)(ob.addresses.objects + 8) = t;
      f_0bf730(C64, 0x250000bf);
      f_060740(0x1f4b, 1);
      if (f_042380((struct hero *)(u1)) == 0)
        f_0bf730(C64, 0x250000c0);
      else
        f_0bf730(C64, 0x250000c1);
      f_0bf730(C64, 0x250000c2);
      f_1254a0(OBA, 0);
      return;
    }
  } else {
    f_060740((unsigned)e->a, 1);
    int s3 = d_1a9820;
    f_147323((int)d_1c2edc, 0x25001e, 0x7fff, 0x8000, s3, 0, 1);
    f_060740((unsigned)e->b, 1);
    int s4 = d_1a9820;
    f_147323((int)d_1c2edc, 0x250025, 0x7fff, 0x8000, s4, 0, 1);
    f_0607e0((unsigned)e->c, 0);
    *e->p = 0;
    f_0fa280(p1, e->d);
  }
  f_1254a0(OBA, 0);
}
//@ f_0f8a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft und betätigt das gekoppelte Gittertor-Paar d_1c0336/d_1c0337 (Wandobjekt 0x3206)
 *   und aktualisiert die 3D-Kollisionsdaten des Durchgangs.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f8a60(void)
{
  OB ob;
  int r;
  short s;
  s = f_060760(0x1f4c);
  if (d_1c0218 == 0 && s == 1) {
    f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    r = f_0397d0(d_1c0004, 0x1a);
    if (r == 0) r = f_038ba0(d_1c0004);
    *(int *)(ob.addresses.objects + 4) = r;
    f_0bf730(C64, 0x250000ba);
    d_1c0218 = 1;
    f_1254a0(OBA, 0);
  }
}
//@ f_0f8af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Öffnen eines durch einen Hebel oder Schlüssel gesicherten Gittertors
 *   (d_1c0335, d_1c0338, Wandobjekt 0x2204) einschließlich der zugehörigen Textmeldungen (0x25000049 bis
 *   0x2500004c).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_147323u(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323u "f_147323";
void f_0f8af0(int p1)
{
  struct E *e;
  int c = EQI(d_1c0234, 0);
  e = d_1a67b0;
  e += 2;
  if (c) {
    int s1, s2;
    f_060740(e->a, 1);
    s1 = d_1a9820;
    f_147323u(d_1c2edc, 0x25001e, 0x7fff, 0x8000, s1, 0, 1);
    f_060740(e->b, 1);
    s2 = d_1a9820;
    f_147323u(d_1c2edc, 0x250024, 0x7fff, 0x8000, s2, 0, 1);
    f_0607e0(e->c, 1);
    *e->p = 1;
  } else {
    int s3, s4;
    f_060740(e->a, 1);
    s3 = d_1a9820;
    f_147323u(d_1c2edc, 0x25001e, 0x7fff, 0x8000, s3, 0, 1);
    f_060740(e->b, 1);
    s4 = d_1a9820;
    f_147323u(d_1c2edc, 0x250025, 0x7fff, 0x8000, s4, 0, 1);
    f_0607e0(e->c, 0);
    *e->p = 0;
    f_0fa280(p1, e->d);
  }
}
//@ f_0f8c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet das zweite gekoppelte Gittertor-Paar (d_1c0339/d_1c033a, Wandobjekt 0x1d06)
 *   und schaltet dessen Durchgangszustand in der 3D-Karte um.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f8c20(void)
{
  OB ob;
  int r;
  short s;
  s = f_060760(0x1f4d);
  if (d_1c0218 == 0 && s == 1) {
    f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    r = f_0397d0(d_1c0004, 0x1a);
    if (r == 0) r = f_038ba0(d_1c0004);
    *(int *)(ob.addresses.objects + 4) = r;
    f_0bf730(C64, 0x250000ba);
    d_1c0218 = 1;
    f_1254a0(OBA, 0);
  }
}
//@ f_0f8cb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die Interaktion mit einem unter Wasser liegenden Abfluss- oder Hebelschacht
 *   (d_1c033b), in den ein Held hineingreifen kann, um einen Mechanismus zu lösen (d_1c0335 = 1), wobei ihm bei
 *   einer misslungenen Geschicklichkeitsprobe eine Wasserschlange oder Schnappschildkröte (1W6 Schaden) in die
 *   Hand beißt.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f8cb0(void)
{
  OB ob;
  int p1, u2, u3, u4, u5;
  if (EQI(d_1c0238, 0)) {
    p1 = f_0de0d0((int)f_0fa340);
    if (p1 != 0) {
      f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      u2 = f_0de7d0(p1, 0);
      u3 = ((int)(f_0422b0((struct hero *)(u2))));
      u3 = f_133fe0((int)&d_1c3498, u3);
      if (f_042380((struct hero *)(u2)) == 0) {
        u2 = 0x250000c3;
        u5 = 0x250000c5;
      } else {
        u2 = 0x250000c4;
        u5 = 0x250000c6;
      }
      u4 = f_038c40(d_1c0004);
      *(int *)(ob.addresses.objects + 4) = u4;
      *(int *)(ob.addresses.numbers + 4) = u3;
      *(int *)(ob.addresses.numbers + 8) = u2;
      *(int *)(ob.addresses.numbers + 0xc) = u5;
      f_0bf730(C64, 0x250000c7);
      d_1c0238 = 1;
      f_1254a0(OBA, 0);
      return;
    }
    if (EQI(d_1c028c, 0)) {
      d_1c028c = 1;
      f_0bf730(C64, 0x250000c8);
    }
  }
}
//@ f_0f8dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Tauchen oder Durchwaten einer überfluteten Kanalpassage (d_1c033e): Sie
 *   prüft die Schwimmfähigkeit des Anführers, zieht bei Misserfolg Lebenspunkte ab, ruft die Rost-Routine
 *   (f_0fa9b0) für ungeschützte Waffen und Rüstungen auf und versetzt die Gruppe auf die andere Seite des
 *   Wasserbeckens.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Zielkoordinate p2 sowie die Blickrichtung p3.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe auf dem Ausgangsfeld bleibt, oder 0 nach
 *   erfolgreichem Durchtauchen.
 === Ende Beschreibung === */
void f_0f8dc0(void)
{
    OB ob;
    int image=f_0606a0(0x250001,6);
    if (EQI(d_1c023c,0)) {
        if (EQI(d_1c0240,0)) {
            f_125400(OBA,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498);
            int person=f_039320(d_1c0004,0x30);
            *(int *)(ob.addresses.objects+4)=person;
            f_0bfa20(C64,image,0,0x250000c9,0);
            d_1c023c=1;
            f_1254a0(OBA,0);
        } else f_0bf730(C64,0x250000c8);
    } else if (EQB(d_1c0240,0)) {
        f_0bfa20(C64,image,0,0x250000ca,0);
        f_125ed0(C44,5);
    } else f_0bf730(C64,0x250000cb);
    if (image) operator delete((void *)((int)(((RivaRasterImage*)(image))->f_0fad20(0))));
}
//@ f_0f8ec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert die Dungeon-Kennung 0x15 (21) für den dritten Kanalisationsabschnitt
 *   zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 0x15 zurück.
 === Ende Beschreibung === */
void f_0f8ec0(void)
{
}

//@ f_0f8ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lässt die Gruppe an einer Nische oder Truhe (d_1c033f) nach Beute suchen, übergibt beim
 *   ersten Mal einen Trank oder Gegenstand (0x9e) und löst bei einer weiteren Untersuchung einen Hinterhalt
 *   (0x1f49) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f8ed0(void)
{
  OB ob;
  int p2, u;
  if (EQI(d_1c0280, 0)) {
    { int snd = d_1a9820; f_147323((int)d_1c2edc, 0x250026, 0x7fff, 0x8000, snd, 0, 1); }
    if ((short)f_0db9a0(d_1c0004) > 1) {
      f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      p2 = f_0396f0(d_1c0004, 0);
      u = f_039c50(d_1c0004, p2);
      *(int *)(ob.addresses.objects + 4) = p2;
      p2 = *(volatile int *)&ob.addresses.objects;
      *(int *)(p2 + 8) = u;
      f_0bf730(C64, 0x250000cc);
      d_1c0280 = 1;
      f_1254a0(OBA, 0);
    }
  }
}
//@ f_0f8f90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode behandelt das Aufbrechen oder Aufschließen einer schweren Tür (d_1c0340, Wandobjekt
 *   0x1105) mithilfe eines Schlüssels (0x68), Dietrichs oder Brecheisens (0x44, 0x11d).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0f2720(int p1);
int f_057220(int p1, int p2, int p3);
void f_0f8f90(int p1)
{
  if (EQI(d_1c0244, 0)) {
    if (EQI(d_1c0248, 0)) {
      f_0bf730(C64, 0x250000cd);
      d_1c0248 = 1;
    }
    if (f_0bf6f0(C64, 0x250000ce) == 1) {
      short k;
      short m;
      f_060800(0x250006, 0, 0);
      f_0f2720(9);
      k = (*(FP3 **)(p1 + 8))[0](p1, 0, 0);
      m = k;
      f_060a70();
      if (k == 0) {
        f_0f2720(0xb);
        f_057220(C00, 0x8030046, 0);
        d_1c0244 = 1;
        f_091f70(0x15);
      }
      if (m == 0 || m == 3) {
        f_060800(0x250008, 0, 0);
        f_060740(0x1f4f, 1);
        f_0607e0(0x1f4f, 1);
        f_0607e0(0x1f50, 1);
      }
    }
  } else {
    if (f_060760(0x1f4f) == 2) {
      if (d_1c021c == 0) {
        f_0bf730(C64, 0x250000cf);
        d_1c021c = 1;
      }
      f_060740(0x1f4f, 1);
      f_0607e0(0x1f4f, 0);
      f_0607e0(0x1f50, 0);
    }
    f_060800(0x25000c, 0, 0);
    f_060740(0x1f4f, 1);
    f_0607e0(0x1f4f, 1);
    f_0607e0(0x1f50, 1);
  }
}
//@ f_0f9100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion führt eine Kraftprobe (KK + 3) für den Anführer durch, um ein klemmendes
 *   Schleusenrad oder Gitter anzuheben, und zieht bei einem Fehlschlag 1W3 Lebenspunkte durch Zerrung oder
 *   Abrutschen ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Kraftprobe misslingt, oder 0 bei Erfolg.
 === Ende Beschreibung === */
void f_0f9100(void)
{
  if (f_060760(0x1f4f) == 1) {
    f_0bf730(C64, 0x250000cf);
    f_060740(0x1f4f, 1);
    f_0607e0(0x1f4f, 1);
    f_0607e0(0x1f50, 1);
  }
  f_060800(0x25000a, 0, 0);
  f_060740(0x1f4f, 1);
  f_0607e0(0x1f4f, 0);
  f_0607e0(0x1f50, 0);
}
//@ f_0f9190
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet den Kampf gegen die Kanal-Gegnergruppe 1 (0x1f41).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis des Kampfstarts (f_05fa00) zurück.
 === Ende Beschreibung === */
void f_0f9190(void)
{
  if (f_0bf6f0(C64, 0x250000d0) == 1) {
    f_0dd7f0(d_1c0004, 6, 5000);
  }
}
//@ f_0f91c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim ersten Betreten eines bestimmten Kanalabschnitts (d_1c0341) einen
 *   atmosphärischen Beschreibungstext (0x2500005e) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f91c0(void)
{
  if (EQI(d_1c0254, 0)) {
    f_0bf730(C64, 0x250000d1);
    f_0dcae0(d_1c0004);
    d_1c0254 = 1;
  }
}
//@ f_0f9200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim ersten Betreten eines weiteren Kanalabschnitts (d_1c0342) die zugehörige
 *   Textmeldung (0x2500005f) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9200(void)
{
  if (EQI(d_1c024c, 0)) {
    f_0bf730(C64, 0x250000d2);
    d_1c024c = 1;
  }
  f_0603b0(0x26);
}
//@ f_0f9240
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet einen Fundort (d_1c0343), an dem die Helden Gegenstände (0x131, 0x132)
 *   entdecken können, sofern sie eine Sinnesschärfe-Probe bestehen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9240(void)
{
  OB ob;
  int p1, u, a, b, c;
  void *t;
  t = operator new(0xc, mark(d_1a6790, 0x514)); p1 = t ? f_046d10((int)t, 8) : 0;
  f_046de0(p1);
  if (EQI(d_1c0240, 0)) {
    if (f_046eb0(p1) != 0) {
      if (f_039040(d_1c0004) != 0) {
        u = f_039040(d_1c0004);
        if (f_042400((struct hero *)(u)) == 6) {
          f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
          u = f_039040(d_1c0004);
          a = f_039b00(d_1c0004, u, 0x32);
          b = f_039b00(d_1c0004, u, 0x33);
          c = f_039b70(d_1c0004, u, 0xc);
          *(int *)(ob.addresses.objects + 4) = a;
          f_060a70();
          f_0bf730(C64, 0x250000d3);
          *(int *)(ob.addresses.objects + 4) = b;
          f_0bf730(C64, 0x250000d4);
          *(int *)(ob.addresses.objects + 4) = c;
          f_0bf730(C64, 0x250000d5);
          f_0d64a0();
          d_1c0240 = 1;
          f_1254a0(OBA, 0);
        }
      }
    }
  }
  if (p1 != 0) DELP(f_046d90(p1, 0))
}

#undef C00
#undef C44
#undef C64
#undef DELP
#undef EQ
#undef EQB
#undef EQI
#undef OB
#undef OBA
#undef SND
#undef d_1a6790
#undef d_1a67b0
#undef d_1a9820
#undef d_1bc8cc
#undef d_1bdcf8
#undef d_1bf230
#undef d_1bfdbc
#undef d_1c0004
#undef d_1c0028
#undef d_1c0218
#undef d_1c021c
#undef d_1c0220
#undef d_1c0224
#undef d_1c0228
#undef d_1c022c
#undef d_1c0230
#undef d_1c0234
#undef d_1c0238
#undef d_1c023c
#undef d_1c0240
#undef d_1c0244
#undef d_1c0248
#undef d_1c024c
#undef d_1c0250
#undef d_1c0254
#undef d_1c0258
#undef d_1c025c
#undef d_1c0260
#undef d_1c0264
#undef d_1c0268
#undef d_1c026c
#undef d_1c0270
#undef d_1c0274
#undef d_1c0278
#undef d_1c027c
#undef d_1c0280
#undef d_1c0284
#undef d_1c0288
#undef d_1c028c
#undef d_1c0290
#undef d_1c21a4
#undef d_1c23a8
#undef d_1c27a4
#undef d_1c27a8
#undef d_1c280c
#undef d_1c2c00
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_0366e0
#undef f_038ba0
#undef f_038c40
#undef f_038c80
#undef f_039040
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0396f0
#undef f_0397d0
#undef f_039a10
#undef f_039a80
#undef f_039ac0
#undef f_039b00
#undef f_039b70
#undef f_039c50
#undef f_039c90
#undef f_041000
#undef f_041030
#undef f_041530
#undef f_041920
#undef f_0422b0
#undef f_042350
#undef f_042380
#undef f_042400
#undef f_042470
#undef f_0424e0
#undef f_0425f0
#undef f_042960
#undef f_042a60
#undef f_043d10
#undef f_043e20
#undef f_044300
#undef f_044850
#undef f_044900
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046eb0
#undef f_0471b0
#undef f_0477a0
#undef f_057220
#undef f_05f190
#undef f_05f220
#undef f_05f470
#undef f_05f480
#undef f_05f800
#undef f_05fa00
#undef f_05ff60
#undef f_060240
#undef f_060360
#undef f_0603b0
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060800
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4800
#undef f_0d4aa0
#undef f_0d54f0
#undef f_0d64a0
#undef f_0db9a0
#undef f_0dbad0
#undef f_0dc020
#undef f_0dc050
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcc10
#undef f_0dcc40
#undef f_0dcdf0
#undef f_0dcf00
#undef f_0dd100
#undef f_0dd1d0
#undef f_0dd4f0
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de020
#undef f_0de0d0
#undef f_0de210
#undef f_0de7c0
#undef f_0de7d0
#undef f_0de7f0
#undef f_0de810
#undef f_0de820
#undef f_0de9d0
#undef f_0de9e0
#undef f_0de9f0
#undef f_0f2720
#undef f_0f9dc0
#undef f_0fa280
#undef f_0fa340
#undef f_0faa10

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_113240
#undef f_113340
#undef f_113640
#undef f_1223c0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0

// ===== Teil sewerag3_t3 (p3, 0f93a0-0fa570) =====
#define d_1a6790 d_1a6790_k3
#define d_1a67b0 d_1a67b0_k3
#define d_1a9820 d_1a9820_k3
#define d_1bc8cc d_1bc8cc_k3
#define d_1bf230 d_1bf230_k3
#define d_1bfdbc d_1bfdbc_k3
#define d_1c0004 d_1c0004_k3
#define d_1c0218 d_1c0218_k3
#define d_1c0250 d_1c0250_k3
#define d_1c0258 d_1c0258_k3
#define d_1c025c d_1c025c_k3
#define d_1c0260 d_1c0260_k3
#define d_1c0264 d_1c0264_k3
#define d_1c0268 d_1c0268_k3
#define d_1c026c d_1c026c_k3
#define d_1c0270 d_1c0270_k3
#define d_1c0274 d_1c0274_k3
#define d_1c0278 d_1c0278_k3
#define d_1c027c d_1c027c_k3
#define d_1c0284 d_1c0284_k3
#define d_1c0288 d_1c0288_k3
#define d_1c23a8 d_1c23a8_k3
#define d_1c2c64 d_1c2c64_k3
#define d_1c2edc d_1c2edc_k3
#define d_1c3498 d_1c3498_k3
#define d_1c349c d_1c349c_k3
#define d_1c3870 d_1c3870_k3
#define f_0366e0 f_0366e0_k3
#define f_038ba0 f_038ba0_k3
#define f_038c40 f_038c40_k3
#define f_039320 f_039320_k3
#define f_039420 f_039420_k3
#define f_039660 f_039660_k3
#define f_0397d0 f_0397d0_k3
#define f_039a10 f_039a10_k3
#define f_039a80 f_039a80_k3
#define f_039ac0 f_039ac0_k3
#define f_039c90 f_039c90_k3
#define f_041030 f_041030_k3
#define f_041920 f_041920_k3
#define f_042400 f_042400_k3
#define f_0425f0 f_0425f0_k3
#define f_042960 f_042960_k3
#define f_043e20 f_043e20_k3
#define f_044300 f_044300_k3
#define f_044850 f_044850_k3
#define f_044900 f_044900_k3
#define f_046d10 f_046d10_k3
#define f_046d90 f_046d90_k3
#define f_046eb0 f_046eb0_k3
#define f_0471b0 f_0471b0_k3
#define f_05f190 f_05f190_k3
#define f_05f220 f_05f220_k3
#define f_05f470 f_05f470_k3
#define f_05f480 f_05f480_k3
#define f_05f800 f_05f800_k3
#define f_060360 f_060360_k3
#define f_0603b0 f_0603b0_k3
#define f_060740 f_060740_k3
#define f_060760 f_060760_k3
#define f_0607e0 f_0607e0_k3
#define f_060a70 f_060a70_k3
#define f_0bbf00 f_0bbf00_k3
#define f_0bf730 f_0bf730_k3
#define f_0d4a60 f_0d4a60_k3
#define f_0d54f0 f_0d54f0_k3
#define f_0db9a0 f_0db9a0_k3
#define f_0dbad0 f_0dbad0_k3
#define f_0dc050 f_0dc050_k3
#define f_0dcbb0 f_0dcbb0_k3
#define f_0dcf00 f_0dcf00_k3
#define f_0dd1d0 f_0dd1d0_k3
#define f_0dd4f0 f_0dd4f0_k3
#define f_0dd750 f_0dd750_k3
#define f_0de0d0 f_0de0d0_k3
#define f_0de210 f_0de210_k3
#define f_0de7c0 f_0de7c0_k3
#define f_0de7d0 f_0de7d0_k3
#define f_0de7f0 f_0de7f0_k3
#define f_0de810 f_0de810_k3
#define f_0de820 f_0de820_k3
#define f_0de9d0 f_0de9d0_k3
#define f_0de9e0 f_0de9e0_k3
#define f_0de9f0 f_0de9f0_k3
#define f_0f6ea0 f_0f6ea0_k3
#define f_0f7120 f_0f7120_k3
#define f_0f7180 f_0f7180_k3
#define f_0f71e0 f_0f71e0_k3
#define f_0f7220 f_0f7220_k3
#define f_0fa570 f_0fa570_k3
#define f_0fa840 f_0fa840_k3
#define f_0faa10 f_0faa10_k3
#define f_112df0 f_112df0_k3
#define f_112e70 f_112e70_k3
#define f_112ec0 f_112ec0_k3
#define f_1131b0 f_1131b0_k3
#define f_1223c0 f_1223c0_k3
#define f_125400 f_125400_k3
#define f_1254a0 f_1254a0_k3
// P3 31/36 gleich (suche.py 26.10.2026, Basis sewerag3_t3_P1.CPP)
// OPT-aus-Teil (gilt nicht fuer das Modul) -4r -onetx -zp1 -s
// P1 26/36 gleich (V031: G1 W0 V1 H0 D1)
// sewerag3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F93A0-0x0FA570
#define EQI(x,v) (((x)==(v))?1:0)
#define ARG1X d_1c2edc
#define SETF(x) (x) = 1;



void *f_046d10(void *p1, int p2);
void *f_05f190(void *p1, int p2, int p3);
void *f_112df0(void *p1, int p2, int p3, int p4);
struct Dlg0c { char b[0xc]; Dlg0c(int a) { f_046d10(this, a); } };
struct D05 { char b[0xc]; D05(int a, int c) { f_05f190(this, a, c); } };
struct Dlg14 { char b[0x14]; Dlg14(int a, int c, int d) { f_112df0(this, a, c, d); } };
struct TE { char *p; unsigned short a; unsigned short b; unsigned short c; short d; };
int f_0366e0(int p1, int p2, int p3, int p4);
int f_038ba0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039420(int p1, int p2);
int f_039660(int p1, int p2);
int f_0397d0(int p1, int p2);
int f_039a10(int p1, int p2, int (*p3)(int));
int f_039a80(int p1, void (*p2)(void));
int f_039ac0(int p1, int (*p2)(int));
int f_039c90(int p1, short (*p2)(int), int (*p3)(int));
int f_041030(int p1, ...);
int f_041920(int p1);
signed char f_042400(hero *p);
short f_042960(hero *p);
unsigned char f_0425f0(hero *p);
int f_043e20(int p1, int p2);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
void *f_046d90(void *p1, int p2);
int f_046eb0(void *p1);
int f_0471b0(void *p1, int p2, int p3);
void *f_05f220(void *p1, int p2);
int f_05f470(void *p1);
int f_05f480(void *p1);
int f_05f800(void *p1, void *p2);
int f_060360(int p1);
int f_0603b0(int p1);
int f_060740(int p1, int p2);
short f_060760(int p1);
int f_0607e0(int p1, int p2);
int f_060a70(void);
int f_0bbf00(char *p1);
int f_0bf730(char *p1, int p2);
int f_0d4a60(int p1);

short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dbad0(int p1, int p2, int p3);
short f_0dc050(int p1, int p2, int p3);
int f_0dcbb0(int p1, int p2);
int f_0dcf00(int p1, int p2, int p3);
int f_0dd1d0(int p1, int p2);
int f_0dd4f0(int p1, int p2);
int f_0dd750(int p1, int p2);
int f_0de0d0(int (*p1)(int));
int f_0de210(int p1);
int f_0de7c0(int p1);
int f_0de7d0(int p1, int p2);
short f_0de7f0(int p1);
int f_0de810(int p1, int p2);
short f_0de820(int p1);
int f_0de9d0(int p1, int p2);
short f_0de9e0(int p1);
int f_0de9f0(int p1, int p2);
int f_0faa10(int p1, int p2);
void f_0fa840(int p1);
void f_0fa570(int p1);
void f_0fa3b0(int p1);
void f_0fa280(int p1, int p2);
void f_0f9e10(int p1, unsigned short p2, unsigned short p3);
int f_0f7120(int p1);
int f_0f7180(int p1);
int f_0f71e0(int p1);
int f_0f7220(int p1);
void f_0f6ea0(void);
void *f_112e70(void *p1, int p2);
int f_112ec0(void *p1);
int f_1131b0(void *p1);
int f_1223c0(void);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_147323x(const char *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern int d_1a9820;
extern const char d_1a6790[];
extern struct TE d_1a67b0[];
extern char d_1bf230[];
extern char d_1bfdbc[];
extern int d_1bc8cc;
extern int d_1c0004;
extern int d_1c0218;
extern signed char d_1c0250, d_1c0258, d_1c025c, d_1c0260, d_1c0264, d_1c026c, d_1c0270, d_1c0274, d_1c0278, d_1c027c, d_1c0268, d_1c0284, d_1c0288;
extern int d_1c23a8[];
extern char d_1c2c64[];
extern char d_1c2edc[];
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];
struct SO { int a; int *p; int c[2]; int *q; char pad[40]; };
#define SO_CT(o) f_125400(&(o), d_1c349c, d_1c3870, d_1c3498);
#define SO_DT(o) f_1254a0(&(o), 0);
//@ f_0f93a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode untersucht einen verschlammten Überrest im Kanal (d_1c0345) und lässt die Helden nach
 *   Bestehen einer Probe einen versteckten Gegenstand (0x95) bergen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f93a0(void)
{
    void *t, *p;
    if (EQI(d_1c0258, 0)) {
        SO o; SO_CT(o)
        o.p[1] = f_039320(d_1c0004, 0x26);
        o.p[2] = f_039660(d_1c0004, 0xd);
        f_0bf730(d_1c2c64, 0x250000d6);
        f_0bf730(d_1c2c64, 0x250000d7);
        f_0bf730(d_1c2c64, 0x250000d8);
        SETF(d_1c0258)
      SO_DT(o)
}
    t = operator new(0x14, mark(d_1a6790, 0x55a));
    p = t != 0 ? f_112df0(t, 0x27, 0, 0) : t;
    if (f_1131b0(p) != 0) {
        f_112ec0(p);
    }
    if (p != 0) {
        operator delete(f_112e70(p, 0));
    }
}
//@ f_0f94a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kleine Hilfsfunktion setzt das Statusflag d_1c032c auf 0 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0f94a0(int p)
{
    return f_0d4a60(p);
}
//@ f_0f94b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kleine Hilfsfunktion prüft, ob die beiden Statusflags d_1c032b und d_1c032c gleichzeitig
 *   gesetzt sind.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn beide Flags ungleich 0 sind, andernfalls 0.
 === Ende Beschreibung === */
short f_0f94b0(int p)
{
    short r;
    r = 10000;
    if (f_0d4a60(p)) r = 10000 - ((int)(f_042960((struct hero *)(p))));
    return r;
}
//@ f_0f94d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt eine einmalige Beschreibung (d_1c0346, Text 0x25000068) aus und entfernt
 *   anschließend den betreffenden Auslöser aus der 3D-Karte.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f94d0(void)
{
    if (EQI(d_1c0258, 0)) {
        f_0bf730(d_1c2c64, 0x250000d9);
    } else {
        SO o; SO_CT(o)
        o.p[1] = f_039c90(d_1c0004, f_0f94b0, f_0f94a0);
        f_0bf730(d_1c2c64, 0x250000da);
      SO_DT(o)
}
}
//@ f_0f9550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lässt die Gruppe an einer Wandnische (d_1c0347) einen Gegenstand oder Hinweis finden
 *   und aktualisiert die 3D-Wanddarstellung (0x2708).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9550(void)
{
    int a, b;
    if (EQI(d_1c0260, 0)) {
        SO o; SO_CT(o)
        a = f_039420(d_1c0004, 0x26);
        b = f_039320(d_1c0004, 0x26);
        o.p[1] = a;
        o.p[2] = b;
        f_0bf730(d_1c2c64, 0x250000db);
        if (b != a) {
            f_0bf730(d_1c2c64, 0x250000dc);
        }
        SETF(d_1c0260)
      SO_DT(o)
}
}
//@ f_0f95f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet den Kampf gegen die Gegnergruppe 3 (0x1f43).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void f_0f95f0(void)
{
    if (EQI(d_1c0264, 0)) {
        f_0bf730(d_1c2c64, 0x250000dd);
        d_1c0264 = 1;
    }
}
//@ f_0f9620
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft und steuert einen versteckten Schalter oder Durchgang (d_1c0349, Wand 0x230b) und
 *   öffnet bei Erfolg die Geheimwand.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9620(void)
{
    if (EQI(d_1c0258, 1) && EQI(d_1c025c, 0)) {
        SO o; SO_CT(o)
        o.p[1] = f_039660(d_1c0004, 7);
        f_0bf730(d_1c2c64, 0x250000de);
        if (f_0db9a0(d_1c0004) > 1) {
            f_0bf730(d_1c2c64, 0x250000df);
        }
        SETF(d_1c025c)
      SO_DT(o)
}
}
//@ f_0f96d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode zeigt beim ersten Betreten (d_1c034a) die Textmeldung 0x25000072 an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f96d0(void)
{
    if (EQI(d_1c026c, 0)) {
        f_0bf730(d_1c2c64, 0x250000e0);
        d_1c026c = 1;
    }
    f_0603b0(0x28);
}
//@ f_0f9710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft eine Fallgrube oder morsche Brücke (d_1c034b), lässt Helden bei misslungener
 *   Gewandtheitsprobe abstürzen und fügt ihnen Sturzschaden zu.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9710(void)
{
    if (EQI(d_1c0270, 0)) {
        SO o; SO_CT(o)
        o.p[1] = f_038c40(d_1c0004);
        f_0bf730(d_1c2c64, 0x250000e1);
        f_0bf730(d_1c2c64, 0x250000e2);
        SETF(d_1c0270)
      SO_DT(o)
}
}
//@ f_0f9790
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Drehen eines Schleusenrads (d_1c034d), mit dem der Wasserstand in einem
 *   angrenzenden Kanalbecken gesenkt oder gehoben wird, und passt die 3D-Kartenflags entsprechend an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9790(void)
{
    int a, p;
    short s;
    if (EQI(d_1c0274, 0)) {
        SO o; SO_CT(o)
        a = f_039320(d_1c0004, 0x27);
        p = f_039660(d_1c0004, 10);
        f_044900(p, 10, 0);
        o.p[1] = a;
        o.p[2] = p;
        f_0bf730(d_1c2c64, 0x250000e3);
        s = f_044900(p, 10, 0);
        if (s > 0) {
            f_0bf730(d_1c2c64, 0x250000e4);
            f_044850(p, 1, 5);
        }
        SETF(d_1c0274)
      SO_DT(o)
}
}
//@ f_0f9860
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode setzt das Statusflag d_1c0359 auf 1, sobald die Gruppe einen bestimmten Bereich des
 *   dritten Kanalisationsabschnitts erreicht.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9860(void)
{
    f_060360(9);
}
//@ f_0f9870
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sieben kurzen Methoden starten jeweils einen vordefinierten Kanalkampf gegen unterschiedliche
 *   Ratten- oder Goblingruppen (0x1f45 bis 0x1f4d) über f_05fa00.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Jede Funktion gibt den Rückgabewert des Kampfaufrufs f_05fa00 zurück.
 === Ende Beschreibung === */
void f_0f9870(void)
{
    f_0bf730(d_1c2c64, 0x250000e5);
}
//@ f_0f9890
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der ersten Nord-Süd-Schleuse
 *   (0x14b4) die Interaktions- und Durchtauchroutine f_0f9e10 mit der Zielposition 0x1518 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x14b4 (Ausgangsfeld) und 0x1518 (Zielfeld) an f_0f9e10.
 === Ende Beschreibung === */
void f_0f9890(int p1)
{
    f_0f9e10(p1, 0x14b4, 0x1518);
}
//@ f_0f98b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der ersten Schleuse (0x14b4) in
 *   Gegenrichtung die Durchtauchroutine f_0f9e10 mit der Zielposition 0x1462 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x14b4 und 0x1462 an f_0f9e10.
 === Ende Beschreibung === */
void f_0f98b0(int p1)
{
    f_0f9e10(p1, 0x14b4, 0x1462);
}
//@ f_0f98d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der mittleren überfluteten Passage
 *   (0x15e0) die Durchtauchroutine f_0f9e10 mit der Zielposition 0x164d aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x15e0 und 0x164d an f_0f9e10.
 === Ende Beschreibung === */
void f_0f98d0(int p1)
{
    f_0f9e10(p1, 0x15e0, 0x164d);
}
//@ f_0f98f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der mittleren überfluteten Passage
 *   (0x15e0) in Gegenrichtung die Durchtauchroutine f_0f9e10 mit der Zielposition 0x1597 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x15e0 und 0x1597 an f_0f9e10.
 === Ende Beschreibung === */
void f_0f98f0(int p1)
{
    f_0f9e10(p1, 0x15e0, 0x1597);
}
//@ f_0f9910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der dritten überfluteten Passage
 *   (0x170c) die Durchtauchroutine f_0f9e10 mit der Zielposition 0x16c3 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x170c und 0x16c3 an f_0f9e10.
 === Ende Beschreibung === */
void f_0f9910(int p1)
{
    f_0f9e10(p1, 0x170c, 0x16c3);
}
//@ f_0f9930
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst im dritten Kanalisationsabschnitt (sewerag3) an der dritten überfluteten Passage
 *   (0x170c) in Gegenrichtung die Durchtauchroutine f_0f9e10 mit der Zielposition 0x1779 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Dungeon-Handlers.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Übergibt die Kartenkoordinaten 0x170c und 0x1779 an f_0f9e10.
 === Ende Beschreibung === */
void f_0f9930(int p1)
{
    f_0f9e10(p1, 0x170c, 0x1779);
}
//@ f_0f9950
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion spielt den Lockruf der Rattenfänger-Flöte ab und zwingt die Heldengruppe in der
 *   3D-Ansicht Schritt für Schritt in Richtung des Rattenfängers (f_0f9a00), sofern die Helden ihre Ohren nicht
 *   mit Wachs verschlossen haben.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den Richtungs- oder Schrittparameter p2.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe magisch angezogen wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0f9950(void)
{
    int p, r;
    short s;
    p = f_039ac0(d_1c0004, f_0f7180);
    if (p == 0) {
        p = f_039ac0(d_1c0004, f_0f71e0);
    }
    if (p == 0) {
        p = f_038c40(d_1c0004);
    }
    f_0dd1d0(d_1c0004, 399);
    s = f_0366e0(p, 399, 2, 1);
    if (s == 0) {
        f_0dcf00(d_1c0004, 399, 1);
        p = f_039ac0(d_1c0004, f_0f7220);
    }
    r = f_041030(1, p);
    f_0bbf00(d_1bf230);
    f_041920(r);
    return r;
}
//@ f_0f9a00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für jedes Gruppenmitglied, ob es Ohrenwachs (0x120) benutzt hat oder eine
 *   Magieresistenz-/Selbstbeherrschungsprobe besteht, um dem Flötenspiel des Rattenfängers zu widerstehen, und
 *   führt das Dialog- und Kampfergebnis herbei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe dem Zauber widersteht, oder 0, wenn sie
 *   überwältigt wird.
 === Ende Beschreibung === */
void f_0f9a00(int p1)
{
    SO o; SO_CT(o)
    int r0, r, v, pb, pc, flag;
    short s, k;
    struct Dlg0c *q;
    r0 = f_0397d0(d_1c0004, 0x18b);
    s = f_0dc050(d_1c0004, 0x18d, -1);
    flag = s != -1;
    if (r0 != 0 && !flag) {
        o.p[1] = r0;
        f_0bf730(d_1c2c64, 0x250000ea);
    } else {
        f_060360(10);
        {
            int t = (int)operator new(0xc, mark(d_1a6790, 0x705));
            q = (Dlg0c *)(t ? f_046d10((void *)t, 10) : (void *)t);
        }
        if (f_046eb0(q) == 1) {
            f_060a70();
            f_0471b0(q, 0x18d, 1);
            f_0471b0(q, 0x18e, 1);
            f_0fa840(p1);
            s = f_0d54f0(d_1c0004, 0x18f);
            pc = p1;
            v = f_041030(1, f_0de7d0(d_1c0004, (int)s));
            pb = f_038c40(v);
            f_041920(v);
            p1 = d_1c0004;
            for (k = 0; k < 6; k++) {
                r = (int)d_1bfdbc + k * 0x61;
                if (f_0de7c0(r) != 0 && r != p1) {
                    if (f_0db9a0(r)) {
                        f_041920(r);
                        f_060a70();
                        f_0faa10(pc, r);
                    }
                }
            }
            f_041920(p1);
            o.p[1] = pb;
            if (f_0f7120(pb) == 0) {
                f_0bf730(d_1c2c64, 0x250000ed);
                f_043e20(pb, 1);
                f_044300(pb, (short)(((int)(f_042960((struct hero *)(pb)))) - 4));
                f_043e20(pb, 0);
            } else {
                f_0bf730(d_1c2c64, 0x250000ee);
                f_0bf730(d_1c2c64, 0x250000ef);
                if (f_0f71e0(pb) == 1) {
                    f_0dd750(v, 0x17dd);
                    f_0de810(v, 0x70);
                } else {
                    f_0de9d0(v, 1);
                }
            }
        }
        if (q != 0) {
            operator delete(f_046d90(q, 0));
        }
    }
  SO_DT(o)
}
//@ f_0f9c50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lässt die Helden im Wohnbereich des Rattenfängers eine Truhe oder einen Tisch
 *   (d_1c0350) durchsuchen und händigt die dort gelagerten Gegenstände aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9c50(void)
{
    if (EQI(d_1c0278, 0)) {
        SO o; SO_CT(o)
        o.p[1] = f_038c40(d_1c0004);
        if (EQI(d_1c0274, 1)) {
            f_0bf730(d_1c2c64, 0x250000f0);
        }
        f_0bf730(d_1c2c64, 0x250000f1);
        SETF(d_1c0278)
      SO_DT(o)
}
}
//@ f_0f9ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim Betreten eines bestimmten Raumes den Hinweis 0x25000090 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9ce0(void)
{
    if (EQI(d_1c027c, 0)) {
        f_0bf730(d_1c2c64, 0x250000f2);
        d_1c027c = 1;
    }
}
//@ f_0f9d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim Untersuchen einer Stelle im Rattenfänger-Versteck den Text 0x25000091 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9d10(void)
{
    if (EQI(d_1c0268, 0)) {
        f_0bf730(d_1c2c64, 0x250000dd);
        d_1c0268 = 1;
    }
}
//@ f_0f9d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft im Käfig des Rattenfängers, ob die Helden das Gitter (0x0c0b) von innen öffnen
 *   oder die Stäbe auseinanderbiegen können (d_1c0351), um aus der Gefangenschaft zu entkommen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9d40(void)
{
    if (EQI(d_1c0250, 0)) {
        SO o; SO_CT(o)
        o.p[1] = f_038c40(d_1c0004);
        f_0bf730(d_1c2c64, 0x250000f3);
        SETF(d_1c0250)
      SO_DT(o)
}
}
//@ f_0f9db0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt das Käfig-Ausbruchsflag d_1c0351 auf 1.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9db0(void)
{
}
//@ f_0f9dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt im Rattenfänger-Versteck die Textmeldung 0x2500009b aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0f9dc0(int p)
{
    if (f_0d4a60(p) != 0) {
        if (f_042400((struct hero *)(p)) == 0) {
            return 1;
        }
    }
    return 0;
}
//@ f_0f9df0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wechselt vom dritten in den zweiten Kanalisationsabschnitt (0x16, Startpunkt 0x1b5c).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void f_0f9df0(void)
{
    f_039a10(d_1c0004, 0x250000b7, f_0f9dc0);
}
//@ f_0f9e10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet die Kiste oder den Sack (d_1c0352), in dem der Rattenfänger die
 *   beschlagnahmte Ausrüstung der gefangenen Helden verstaut hat, und gibt den Helden ihr gesamtes Gepäck und
 *   ihr Gold über f_0fa840 zurück.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9e10(int p1, unsigned short p2, unsigned short p3)
{
    extern int sndalias_f9e10;
#pragma aux sndalias_f9e10 "d_1a9820"
    int q, t, m;
    SO o; SO_CT(o)
    if (EQI(d_1c0288, 0)) {
        q = f_041030(1, f_038c40(d_1c0004));
        t = f_038c40(q);
        o.p[1] = t;
        f_0bbf00(d_1bf230);
        {
            int snd;
            f_147323((int)ARG1X, 0x250027, 0x7fff, 0x8000, (snd = sndalias_f9e10), 0, 1);
        }
        if (q != d_1c0004 && f_0db9a0(d_1c0004) > 0) m = 0x250000e6; else m = 0x250000e7;
        f_0bf730(d_1c2c64, m);
        if (f_0f71e0(t) == 1) {
            f_0bf730(d_1c2c64, 0x250000e8);
            f_0dd750(q, p3);
            f_041920(q);
        } else {
            f_0bf730(d_1c2c64, 0x250000e9);
            f_0dd750(q, p2);
            f_0de9d0(q, 1);
            f_039a80(q, f_0f6ea0);
        }
    }
  SO_DT(o)
}
//@ f_0f9f50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode untersucht einen Haufen Unrat oder ein Versteck (d_1c0353), in dem die Helden nützliche
 *   Gegenstände (0x11d Brecheisen, 0x120 Wachs) für den Ausbruch oder den Kampf gegen den Rattenfänger finden
 *   können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0f9f50(int p1)
{
    extern int sndalias;
#pragma aux sndalias "d_1a9820"
    if (EQI(d_1c0284, 1)) {
        f_060740(0x1f4e, 1);
        f_0607e0(0x1f4e, 1);
        d_1c0284 = 2;
    }
    if (d_1bc8cc) {
        SO m; SO_CT(m)
        int snd;
        m.p[1] = d_1bc8cc;
        f_060740(d_1a67b0[0].a, 1);
        snd = sndalias;
        f_147323((int)ARG1X, 0x25001e, 0x7fff, 0x8000, snd, 0, 1);
        f_060740(d_1a67b0[0].b, 1);
        snd = sndalias;
        f_147323((int)ARG1X, 0x250025, 0x7fff, 0x8000, snd, 0, 1);
        f_0607e0(d_1a67b0[0].c, 0);
        *d_1a67b0[0].p = 0;
        f_0fa280(p1, d_1a67b0[0].d);
        f_0de9f0(d_1c0004, 0);
        d_1bc8cc = 0;
      SO_DT(m)
}
    if (EQI(d_1c0288, 1)) {
        f_0fa3b0(p1);
        d_1c0288 = 2;
    }
    f_0fa570(p1);
}
//@ f_0fa0b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft einen Durchgang (d_1c0354) und gibt je nach Status eine Meldung (0x250000a9) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fa0b0(void)
{
    int r, p;
    short k;
    r = 0;
    for (k = 0; k < 6; k++) {
        p = (int)d_1bfdbc + k * 0x61;
        if (p != d_1c0004) {
            if (f_0de7c0(p) == 1) {
                if (f_0de820(p) == 3) {
                    if (f_0de9e0(p) == 1) {
                        r = p;
                    }
                }
            }
        }
    }
    return r;
}
//@ f_0fa110
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die Interaktion mit einem weiteren Gitter oder Mechanismus (d_1c0355) im
 *   Rattenfänger-Bereich.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa110(int p1, short p2, int p3)
{
    extern int sndalias_fa110;
#pragma aux sndalias_fa110 "d_1a9820"
    int i;
    int snd;
    struct TE *e;
    i = (short)p2; i--; e = &d_1a67b0[i];
    f_060740(e->a, 1);
    if (p3 != 0) {
        f_147323x(ARG1X, 0x25001e, 0x7fff, 0x8000, (snd = sndalias_fa110), 0, 1);
    }
    f_060740(e->b, 1);
    if (p3 != 0) {
        f_147323x(ARG1X, 0x250024, 0x7fff, 0x8000, (snd = sndalias_fa110), 0, 1);
    }
    f_0607e0(e->c, 1);
    e->p[0] = 1;
}
//@ f_0fa1c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion synchronisiert beim Laden oder Betreten des dritten Kanalisationsabschnitts
 *   sämtliche beweglichen Wände, Gittertore und Durchgänge in der 3D-Kartenstruktur mit den gespeicherten
 *   Zustandsflags (d_1c0335 bis d_1c0355).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
static inline TE *first493(short index) {int i=(int)index-1; TE *result=&d_1a67b0[i]; f_060740(result->a,1); return result;}
void f_0fa1c0(int p1, short p2, int p3)
{
    extern int sndalias_fa1c0;
#pragma aux sndalias_fa1c0 "d_1a9820"
    int p3_ = p3;
    int i;
    struct TE *e;
    e=first493(p2);
    if (p3_ != 0) {
        int snd;
        snd = sndalias_fa1c0;
        f_147323((int)ARG1X, 0x25001e, 0x7fff, 0x8000, snd, 0, 1);
    }
    f_060740(e->b, 1);
    if (p3 != 0) {
        int snd;
        snd = sndalias_fa1c0;
        f_147323((int)ARG1X, 0x250025, 0x7fff, 0x8000, snd, 0, 1);
    }
    f_0607e0(e->c, 0);
    e->p[0] = 0;
    f_0fa280((*&p1), e->d);
}
//@ f_0fa280
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert die Sichtbarkeits- und Kollisionsflags der Wasserflächen und
 *   Schleusentore in der 3D-Ansicht anhand des aktuellen Flutungszustands (d_1c034d).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa280(int p1, int p2)
{
    struct Dlg0c *q;
    short n, k;
    int p0, u;
    int *tab;
    tab = d_1c23a8;
    q = (struct Dlg0c *)operator new(0xc, mark(d_1a6790, 0x969));
    q = q != 0 ? (struct Dlg0c *)f_05f190(q, 0, (short)p2) : q;
    k = 0;
    n = f_05f800(q, tab);
    p0 = d_1c0004;
    if (n > (short)0) {
        do {
            u = tab[k];
            f_041920(u);
            f_1223c0();
            f_0bbf00(d_1bf230);
            f_0bf730(d_1c2c64, 0x250000bb);
            k = k + 1;
            f_0de210(u);
        } while (k < n);
    }
    if (p0 != d_1c0004) {
        f_041920(p0);
    }
    if (q != 0) {
        operator delete(f_05f220(q, 0));
    }
}
//@ f_0fa340
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft einen speziellen Übergangspunkt im Kanal und gibt einen Hinweistext (0x250000b3)
 *   aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fa340(int p1)
{
    int r;
    r = 0;
    if (p1 != d_1c0004) {
        if (f_0de820(p1) == 3) {
            if (f_0de7f0(p1) == 1) {
                if (((signed char)(f_0425f0((struct hero *)(f_0de7d0(p1, 0))))) == 1) {
                    if (f_0dd4f0(p1, 0xc9) == 1) {
                        r = 1;
                    }
                }
            }
        }
    }
    return r;
}
//@ f_0fa3a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kleine Hilfsfunktion setzt das Statusflag d_1c0358 auf 1.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa3a0(void)
{
    f_0de0d0(f_0fa340);
}
//@ f_0fa3b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode behandelt das Klettern über einen Schacht oder eine Leiter im Kanal (d_1c0356)
 *   einschließlich Seilprüfung und Kletterprobe.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
extern void f_0f939ax(void);
#pragma aux f_0f939ax aborts;
void f_0fa3b0(int p1)
{
    short i;
    int z;
    void *q;
    {
        int t = (int)operator new(0xc, mark(d_1a6790, 0x9dc));
        q = t ? f_05f190((void *)t, 0x22, 0x1f44) : (void *)t;
    }
    f_05f470(q);
    f_05f480(q);
    if (q) {
        operator delete(f_05f220(q, 0));
    }
    f_060740(0x3f3, 1);
    f_060740(0x3fd, 1);
    f_060740(0x407, 1);
    f_060740(0x3f8, 1);
    f_060740(0x3fa, 1);
    f_060740(0x3f9, 1);
    i = 0;
    z = 0;
    for (; i < 6; i++) {
        int e = (int)d_1bfdbc + i * 0x61;
        if (f_0de7c0(e) && f_0de7f0(e) && f_0de820(e) == 3) {
            f_0de9d0(e, z);
            if (f_0db9a0(e) == 0) {
                f_0dbad0(e, 5, 10);
            }
            f_0dcbb0(e, 0x19);
        }
    }
    f_0f939ax();
}
//@ f_0fa4e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion versetzt die überwältigte Heldengruppe in den Käfig des Rattenfängers, nimmt ihr über
 *   f_0fa570 sämtliche Gegenstände und Dukaten ab und speichert die Beute im Versteck-Container.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa4e0(int p1, unsigned short p2)
{
    short s;
    int r;
    s = f_060760(p2);
    if (d_1c0218 == 0 && s == 1) {
        SO o; SO_CT(o)
        r = f_0397d0(d_1c0004, 0x1a);
        if (r == 0) {
            r = f_038ba0(d_1c0004);
        }
        o.p[1] = r;
        f_0bf730(d_1c2c64, 0x250000ba);
        d_1c0218 = 1;
      SO_DT(o)
}
}

#undef ARG1X
#undef EQI
#undef SETF
#undef d_1a6790
#undef d_1a67b0
#undef d_1a9820
#undef d_1bc8cc
#undef d_1bf230
#undef d_1bfdbc
#undef d_1c0004
#undef d_1c0218
#undef d_1c0250
#undef d_1c0258
#undef d_1c025c
#undef d_1c0260
#undef d_1c0264
#undef d_1c0268
#undef d_1c026c
#undef d_1c0270
#undef d_1c0274
#undef d_1c0278
#undef d_1c027c
#undef d_1c0284
#undef d_1c0288
#undef d_1c23a8
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0366e0
#undef f_038ba0
#undef f_038c40
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0397d0
#undef f_039a10
#undef f_039a80
#undef f_039ac0
#undef f_039c90
#undef f_041030
#undef f_041920
#undef f_042400
#undef f_0425f0
#undef f_042960
#undef f_043e20
#undef f_044300
#undef f_044850
#undef f_044900
#undef f_046d10
#undef f_046d90
#undef f_046eb0
#undef f_0471b0
#undef f_05f190
#undef f_05f220
#undef f_05f470
#undef f_05f480
#undef f_05f800
#undef f_060360
#undef f_0603b0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060a70
#undef f_0bbf00
#undef f_0bf730
#undef f_0d4a60
#undef f_0d54f0
#undef f_0db9a0
#undef f_0dbad0
#undef f_0dc050
#undef f_0dcbb0
#undef f_0dcf00
#undef f_0dd1d0
#undef f_0dd4f0
#undef f_0dd750
#undef f_0de0d0
#undef f_0de210
#undef f_0de7c0
#undef f_0de7d0
#undef f_0de7f0
#undef f_0de810
#undef f_0de820
#undef f_0de9d0
#undef f_0de9e0
#undef f_0de9f0
#undef f_0f6ea0
#undef f_0f7120
#undef f_0f7180
#undef f_0f71e0
#undef f_0f7220
#undef f_0fa570
#undef f_0fa840
#undef f_0faa10
#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_1223c0
#undef f_125400
#undef f_1254a0

// ===== Teil sewerag3_t4 (p3, 0fa570-0fa9b0) =====
#define d_1a6790 d_1a6790_k4
#define d_1a67b0 d_1a67b0_k4
#define d_1a67b4 d_1a67b4_k4
#define d_1a67b6 d_1a67b6_k4
#define d_1a67b8 d_1a67b8_k4
#define d_1a67ba d_1a67ba_k4
#define d_1a67bc d_1a67bc_k4
#define d_1a67c0 d_1a67c0_k4
#define d_1a67c2 d_1a67c2_k4
#define d_1a67c4 d_1a67c4_k4
#define d_1a67c6 d_1a67c6_k4
#define d_1a67c8 d_1a67c8_k4
#define d_1a67cc d_1a67cc_k4
#define d_1a67ce d_1a67ce_k4
#define d_1a67d0 d_1a67d0_k4
#define d_1a67d2 d_1a67d2_k4
#define d_1a9820 d_1a9820_k4
#define d_1bc8cc d_1bc8cc_k4
#define d_1bdcf8 d_1bdcf8_k4
#define d_1bf230 d_1bf230_k4
#define d_1bfdbc d_1bfdbc_k4
#define d_1c0004 d_1c0004_k4
#define d_1c0028 d_1c0028_k4
#define d_1c0218 d_1c0218_k4
#define d_1c021c d_1c021c_k4
#define d_1c0220 d_1c0220_k4
#define d_1c0224 d_1c0224_k4
#define d_1c0228 d_1c0228_k4
#define d_1c022c d_1c022c_k4
#define d_1c0230 d_1c0230_k4
#define d_1c0234 d_1c0234_k4
#define d_1c0238 d_1c0238_k4
#define d_1c023c d_1c023c_k4
#define d_1c0240 d_1c0240_k4
#define d_1c0244 d_1c0244_k4
#define d_1c0248 d_1c0248_k4
#define d_1c024c d_1c024c_k4
#define d_1c0250 d_1c0250_k4
#define d_1c0254 d_1c0254_k4
#define d_1c0258 d_1c0258_k4
#define d_1c025c d_1c025c_k4
#define d_1c0260 d_1c0260_k4
#define d_1c0264 d_1c0264_k4
#define d_1c0268 d_1c0268_k4
#define d_1c026c d_1c026c_k4
#define d_1c0270 d_1c0270_k4
#define d_1c0274 d_1c0274_k4
#define d_1c0278 d_1c0278_k4
#define d_1c027c d_1c027c_k4
#define d_1c0280 d_1c0280_k4
#define d_1c0284 d_1c0284_k4
#define d_1c0288 d_1c0288_k4
#define d_1c028c d_1c028c_k4
#define d_1c0290 d_1c0290_k4
#define d_1c21a4 d_1c21a4_k4
#define d_1c23a8 d_1c23a8_k4
#define d_1c27a4 d_1c27a4_k4
#define d_1c27a8 d_1c27a8_k4
#define d_1c280c d_1c280c_k4
#define d_1c2c00 d_1c2c00_k4
#define d_1c2c44 d_1c2c44_k4
#define d_1c2c64 d_1c2c64_k4
#define d_1c2edc d_1c2edc_k4
#define d_1c3498 d_1c3498_k4
#define d_1c349c d_1c349c_k4
#define d_1c3870 d_1c3870_k4
#define f_0104b0 f_0104b0_k4
#define f_010590 f_010590_k4
#define f_0366e0 f_0366e0_k4
#define f_038ba0 f_038ba0_k4
#define f_038c40 f_038c40_k4
#define f_038c80 f_038c80_k4
#define f_039040 f_039040_k4
#define f_039320 f_039320_k4
#define f_039420 f_039420_k4
#define f_039660 f_039660_k4
#define f_0396f0 f_0396f0_k4
#define f_0397d0 f_0397d0_k4
#define f_039a10 f_039a10_k4
#define f_039a80 f_039a80_k4
#define f_039ac0 f_039ac0_k4
#define f_039b00 f_039b00_k4
#define f_039b70 f_039b70_k4
#define f_039c50 f_039c50_k4
#define f_039c90 f_039c90_k4
#define f_041000 f_041000_k4
#define f_041030 f_041030_k4
#define f_041530 f_041530_k4
#define f_041920 f_041920_k4
#define f_0422b0 f_0422b0_k4
#define f_042350 f_042350_k4
#define f_042380 f_042380_k4
#define f_042400 f_042400_k4
#define f_042470 f_042470_k4
#define f_0424e0 f_0424e0_k4
#define f_0425f0 f_0425f0_k4
#define f_042960 f_042960_k4
#define f_042a60 f_042a60_k4
#define f_043d10 f_043d10_k4
#define f_043e20 f_043e20_k4
#define f_044300 f_044300_k4
#define f_044850 f_044850_k4
#define f_044900 f_044900_k4
#define f_044c90 f_044c90_k4
#define f_046d10 f_046d10_k4
#define f_046d90 f_046d90_k4
#define f_046de0 f_046de0_k4
#define f_046eb0 f_046eb0_k4
#define f_0471b0 f_0471b0_k4
#define f_0477a0 f_0477a0_k4
#define f_057220 f_057220_k4
#define f_05f190 f_05f190_k4
#define f_05f220 f_05f220_k4
#define f_05f470 f_05f470_k4
#define f_05f480 f_05f480_k4
#define f_05f800 f_05f800_k4
#define f_05fa00 f_05fa00_k4
#define f_05ff60 f_05ff60_k4
#define f_060240 f_060240_k4
#define f_060360 f_060360_k4
#define f_0603b0 f_0603b0_k4
#define f_0606a0 f_0606a0_k4
#define f_060740 f_060740_k4
#define f_060760 f_060760_k4
#define f_0607e0 f_0607e0_k4
#define f_060800 f_060800_k4
#define f_060a70 f_060a70_k4
#define f_091f70 f_091f70_k4
#define f_0bbf00 f_0bbf00_k4
#define f_0bf6f0 f_0bf6f0_k4
#define f_0bf730 f_0bf730_k4
#define f_0bf980 f_0bf980_k4
#define f_0bfa20 f_0bfa20_k4
#define f_0d4800 f_0d4800_k4
#define f_0d4aa0 f_0d4aa0_k4
#define f_0d54f0 f_0d54f0_k4
#define f_0d64a0 f_0d64a0_k4
#define f_0db9a0 f_0db9a0_k4
#define f_0dbad0 f_0dbad0_k4
#define f_0dc020 f_0dc020_k4
#define f_0dc050 f_0dc050_k4
#define f_0dcae0 f_0dcae0_k4
#define f_0dcbb0 f_0dcbb0_k4
#define f_0dcc10 f_0dcc10_k4
#define f_0dcc40 f_0dcc40_k4
#define f_0dcdf0 f_0dcdf0_k4
#define f_0dcf00 f_0dcf00_k4
#define f_0dd100 f_0dd100_k4
#define f_0dd1d0 f_0dd1d0_k4
#define f_0dd4f0 f_0dd4f0_k4
#define f_0dd750 f_0dd750_k4
#define f_0dd7f0 f_0dd7f0_k4
#define f_0de020 f_0de020_k4
#define f_0de0d0 f_0de0d0_k4
#define f_0de210 f_0de210_k4
#define f_0de7c0 f_0de7c0_k4
#define f_0de7d0 f_0de7d0_k4
#define f_0de7f0 f_0de7f0_k4
#define f_0de810 f_0de810_k4
#define f_0de820 f_0de820_k4
#define f_0de9d0 f_0de9d0_k4
#define f_0de9e0 f_0de9e0_k4
#define f_0de9f0 f_0de9f0_k4
#define f_0f2720 f_0f2720_k4
#define f_0f6ee0 f_0f6ee0_k4
#define f_0f6f60 f_0f6f60_k4
#define f_0f6f80 f_0f6f80_k4
#define f_0f7180 f_0f7180_k4
#define f_0f71e0 f_0f71e0_k4
#define f_0faa10 f_0faa10_k4

#define f_112df0 f_112df0_k4
#define f_112e70 f_112e70_k4
#define f_112ec0 f_112ec0_k4
#define f_1131b0 f_1131b0_k4
#define f_113240 f_113240_k4
#define f_113340 f_113340_k4
#define f_113640 f_113640_k4
#define f_1223c0 f_1223c0_k4
#define f_125400 f_125400_k4
#define f_1254a0 f_1254a0_k4
#define f_125ed0 f_125ed0_k4
#define f_133fe0 f_133fe0_k4
#define f_147323 f_147323_k4
#define OB OB_k4
// P3 1/2 gleich (suche.py 25.10.2026, Basis sewerag3_t4_P1.CPP)
// sewerag3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F6FB0-0x0FA9B0
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_039c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041030();                                         // reg - stapel 0
int f_041530();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
char * f_0422b0(hero *p);                                   // reg eax stapel 0
signed char f_042350(hero *p);                                   // reg eax stapel 0
signed char f_042380(hero *p);                                   // reg eax stapel 0
signed char f_042400(hero *p);                                   // reg eax stapel 0
unsigned char f_042470(hero *p);                                   // reg eax stapel 0
unsigned char f_0424e0(hero *p);                                   // reg eax stapel 0
unsigned char f_0425f0(hero *p);                                   // reg eax stapel 0
short f_042960(hero *p);                                   // reg eax stapel 0
short f_042a60(hero *p, int i_input);                           // reg eax edx stapel 0
int f_043d10(int p1);                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_046eb0(int p1);                                   // reg eax stapel 0
int f_0471b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0477a0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f480(int p1);                                   // reg eax stapel 0
int f_05f800(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_060240();                                         // reg - stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dbad0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dc050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd4f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de0d0(int p1);                                   // reg eax stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de9d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9e0(int p1);                                   // reg eax stapel 0
int f_0de9f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0f2720();                       // nicht in clobber.tsv
int f_0faa10(int p1, int p2);                           // reg edx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113240(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a67b0;                    // 0x1A67B0
extern int d_1a67b4;                    // 0x1A67B4
extern int d_1a67b6;                    // 0x1A67B6
extern int d_1a67b8;                    // 0x1A67B8
extern int d_1a67ba;                    // 0x1A67BA
extern int d_1a67bc;                    // 0x1A67BC
extern int d_1a67c0;                    // 0x1A67C0
extern int d_1a67c2;                    // 0x1A67C2
extern int d_1a67c4;                    // 0x1A67C4
extern int d_1a67c6;                    // 0x1A67C6
extern int d_1a67c8;                    // 0x1A67C8
extern int d_1a67cc;                    // 0x1A67CC
extern int d_1a67ce;                    // 0x1A67CE
extern int d_1a67d0;                    // 0x1A67D0
extern int d_1a67d2;                    // 0x1A67D2
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc8cc;                    // 0x1BC8CC
extern signed char d_1bdcf8;                    // 0x1BDCF8
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c0028;                    // 0x1C0028
extern int d_1c0218;                    // 0x1C0218
extern int d_1c021c;                    // 0x1C021C
extern int d_1c0220;                    // 0x1C0220
extern int d_1c0224;                    // 0x1C0224
extern signed char d_1c0228;                    // 0x1C0228
extern int d_1c022c;                    // 0x1C022C
extern int d_1c0230;                    // 0x1C0230
extern int d_1c0234;                    // 0x1C0234
extern int d_1c0238;                    // 0x1C0238
extern signed char d_1c023c;                    // 0x1C023C
extern signed char d_1c0240;                    // 0x1C0240
extern int d_1c0244;                    // 0x1C0244
extern int d_1c0248;                    // 0x1C0248
extern signed char d_1c024c;                    // 0x1C024C
extern signed char d_1c0250;                    // 0x1C0250
extern int d_1c0254;                    // 0x1C0254
extern signed char d_1c0258;                    // 0x1C0258
extern signed char d_1c025c;                    // 0x1C025C
extern int d_1c0260;                    // 0x1C0260
extern int d_1c0264;                    // 0x1C0264
extern int d_1c0268;                    // 0x1C0268
extern int d_1c026c;                    // 0x1C026C
extern int d_1c0270;                    // 0x1C0270
extern signed char d_1c0274;                    // 0x1C0274
extern signed char d_1c0278;                    // 0x1C0278
extern int d_1c027c;                    // 0x1C027C
extern int d_1c0280;                    // 0x1C0280
extern int d_1c0284;                    // 0x1C0284
extern int d_1c0288;                    // 0x1C0288
extern int d_1c028c;                    // 0x1C028C
extern int d_1c0290;                    // 0x1C0290
extern short d_1c21a4;                    // 0x1C21A4
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a6790[];           // Text 0x1A6790
// --- eigene Funktionen (64), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1c27a8[];
extern int d_1c27a4[];
extern int d_1c280c[];
int f_0de020(int p1, int p2);
short f_0de7f0(int p1);
short f_0dc020(int p1, int p2);
short f_0dcc10(int p1);
short f_0366e0(int p1, int p2, int p3, int p4);
short f_0dcf00(int p1, int p2, int p3);
int f_0bf980(void *, ...);
void f_0f6f80(void);
void f_0f6f60(void);
void f_0f6ee0(void);
void f_0f7180(void);
void f_0f71e0(void);

//@ f_0fa570
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchläuft bei der Gefangennahme durch den Rattenfänger alle sechs Heldenslots sowie
 *   deren Inventarplätze, legt getragene Ausrüstung ab, überträgt alle Gegenstände in ein temporäres Beutearray
 *   (d_1c035c) und zieht das gesamte Gruppengold (d_1c035a) ein.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa570(void)
{
    int u, p1, p2, q;
    int *a = d_1c27a8;
    int count;
    if (d_1c21a4 == 0) {
        count = f_0de020((int)f_0f6f80, (int)a);
        if ((short)count == (short)f_0de020((int)f_0f6f60, (int)d_1c280c)) {
            int i;
            for (int n = count - 1; (i = (short)n) >= 0; --n) {
                if (i <= 0) continue;
                u = a[i];
                p1 = a[i - 1];
                while (f_0de7f0(u)) {
                    short s;
                    p2 = f_038c80(u);
                    s = f_0dc020(u, p2);
                    f_0dcdf0(u, (int)s);
                    s = f_0dcc10(p1);
                    f_0dcc40(p1, p2, (int)s);
                }
                d_1c0028 = f_041000();
            }
            u = a[0];
            f_039a80(u, (int)f_0f6ee0);
            f_0de9d0(d_1c0004, 0);
            f_0de9f0(d_1c0004, 0);
            f_041920(u);
            f_0dd7f0(u, 2, 0x16ba);
            f_0de810(u, 0x66);
            f_0dd1d0(u, 399);
            f_0dd1d0(u, 0x18d);
            f_0d64a0();
            f_0dcbb0(u, 0x19);
            d_1bdcf8 = 0x31;
            d_1c0228 = 1;
            d_1c023c = 0;
            d_1c0240 = 1;
            d_1c024c = 1;
            d_1c0258 = 1;
            d_1c025c = 1;
            d_1c0274 = 1;
            d_1c0278 = 1;
            d_1c0250 = 1;
            { int t_ = (int)operator new(0x14, mark(d_1a6790, 0xb6)); q = (t_ != 0) ? f_112df0(t_, 0x26, 0, 0) : t_; }
            f_113640(q);
            if (q) operator delete((void *)f_112e70(q, 0));
            { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xba)); q = (t_ != 0) ? f_046d10(t_, 8) : t_; }
            f_0477a0(q);
            if (q) operator delete((void *)f_046d90(q, 0));
            { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xbe)); q = (t_ != 0) ? f_046d10(t_, 9) : t_; }
            f_0477a0(q);
            if (q) operator delete((void *)f_046d90(q, 0));
            { int t_ = (int)operator new(0xc, mark(d_1a6790, 0xc2)); q = (t_ != 0) ? f_046d10(t_, 10) : t_; }
            f_0477a0(q);
            if (q) operator delete((void *)f_046d90(q, 0));
            { int t_ = (int)operator new(0x14, mark(d_1a6790, 0xc6)); q = (t_ != 0) ? f_112df0(t_, 0x28, 0, 0) : t_; }
            f_113240(q, 0x171, 10000);
            if (q) operator delete((void *)f_112e70(q, 0));
        }
    }
}
//@ f_0fa840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den Helden nach dem Ausbruch aus dem Käfig beim Öffnen der Beutekiste alle zuvor
 *   vom Rattenfänger abgenommenen Gegenstände (d_1c035c) sowie das gespeicherte Gold (d_1c035a) wieder zurück.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa840(void)
{
    int p1, o;
    p1 = (int)operator new(0x13e, mark(d_1a6790, 0xa9f));
    p1 = p1 ? f_0104b0(p1, 0x2c0009, 0, 0) : p1;
    f_0bf980(&d_1c2c64, p1, 0, 0x250000eb, 0);
    f_0dd100(d_1c0004, 0x18d);
    f_0dd100(d_1c0004, 0x18e);
    o = f_039ac0(d_1c0004, (int)f_0f7180);
    if (o != 0) {
        if (f_0366e0(o, 399, 2, 1) == 1) goto L989;
    }
    o = f_039ac0(d_1c0004, (int)f_0f71e0);
    if (o != 0) {
        if (f_0366e0(o, 399, 2, 1) == 1) goto L989;
    }
    if (f_0dcf00(d_1c0004, 399, 1) != 1) {
        o = (int)operator new(0x14, mark(d_1a6790, 0xabf));
        o = o ? f_112df0(o, 0, 0, 0) : o;
        f_113640(o);
        f_113340(o, 399, 1, 0);
        f_112ec0(o);
        if (o != 0) operator delete((void *)f_112e70(o, 0));
        f_060a70();
    }
L989:
    if (p1 != 0) operator delete((void *)f_010590(p1, 0));
}

#undef OB
#undef d_1a6790
#undef d_1a67b0
#undef d_1a67b4
#undef d_1a67b6
#undef d_1a67b8
#undef d_1a67ba
#undef d_1a67bc
#undef d_1a67c0
#undef d_1a67c2
#undef d_1a67c4
#undef d_1a67c6
#undef d_1a67c8
#undef d_1a67cc
#undef d_1a67ce
#undef d_1a67d0
#undef d_1a67d2
#undef d_1a9820
#undef d_1bc8cc
#undef d_1bdcf8
#undef d_1bf230
#undef d_1bfdbc
#undef d_1c0004
#undef d_1c0028
#undef d_1c0218
#undef d_1c021c
#undef d_1c0220
#undef d_1c0224
#undef d_1c0228
#undef d_1c022c
#undef d_1c0230
#undef d_1c0234
#undef d_1c0238
#undef d_1c023c
#undef d_1c0240
#undef d_1c0244
#undef d_1c0248
#undef d_1c024c
#undef d_1c0250
#undef d_1c0254
#undef d_1c0258
#undef d_1c025c
#undef d_1c0260
#undef d_1c0264
#undef d_1c0268
#undef d_1c026c
#undef d_1c0270
#undef d_1c0274
#undef d_1c0278
#undef d_1c027c
#undef d_1c0280
#undef d_1c0284
#undef d_1c0288
#undef d_1c028c
#undef d_1c0290
#undef d_1c21a4
#undef d_1c23a8
#undef d_1c27a4
#undef d_1c27a8
#undef d_1c280c
#undef d_1c2c00
#undef d_1c2c44
#undef d_1c2c64
#undef d_1c2edc
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_0104b0
#undef f_010590
#undef f_0366e0
#undef f_038ba0
#undef f_038c40
#undef f_038c80
#undef f_039040
#undef f_039320
#undef f_039420
#undef f_039660
#undef f_0396f0
#undef f_0397d0
#undef f_039a10
#undef f_039a80
#undef f_039ac0
#undef f_039b00
#undef f_039b70
#undef f_039c50
#undef f_039c90
#undef f_041000
#undef f_041030
#undef f_041530
#undef f_041920
#undef f_0422b0
#undef f_042350
#undef f_042380
#undef f_042400
#undef f_042470
#undef f_0424e0
#undef f_0425f0
#undef f_042960
#undef f_042a60
#undef f_043d10
#undef f_043e20
#undef f_044300
#undef f_044850
#undef f_044900
#undef f_044c90
#undef f_046d10
#undef f_046d90
#undef f_046de0
#undef f_046eb0
#undef f_0471b0
#undef f_0477a0
#undef f_057220
#undef f_05f190
#undef f_05f220
#undef f_05f470
#undef f_05f480
#undef f_05f800
#undef f_05fa00
#undef f_05ff60
#undef f_060240
#undef f_060360
#undef f_0603b0
#undef f_0606a0
#undef f_060740
#undef f_060760
#undef f_0607e0
#undef f_060800
#undef f_060a70
#undef f_091f70
#undef f_0bbf00
#undef f_0bf6f0
#undef f_0bf730
#undef f_0bf980
#undef f_0bfa20
#undef f_0d4800
#undef f_0d4aa0
#undef f_0d54f0
#undef f_0d64a0
#undef f_0db9a0
#undef f_0dbad0
#undef f_0dc020
#undef f_0dc050
#undef f_0dcae0
#undef f_0dcbb0
#undef f_0dcc10
#undef f_0dcc40
#undef f_0dcdf0
#undef f_0dcf00
#undef f_0dd100
#undef f_0dd1d0
#undef f_0dd4f0
#undef f_0dd750
#undef f_0dd7f0
#undef f_0de020
#undef f_0de0d0
#undef f_0de210
#undef f_0de7c0
#undef f_0de7d0
#undef f_0de7f0
#undef f_0de810
#undef f_0de820
#undef f_0de9d0
#undef f_0de9e0
#undef f_0de9f0
#undef f_0f2720
#undef f_0f6ee0
#undef f_0f6f60
#undef f_0f6f80
#undef f_0f7180
#undef f_0f71e0
#undef f_0faa10

#undef f_112df0
#undef f_112e70
#undef f_112ec0
#undef f_1131b0
#undef f_113240
#undef f_113340
#undef f_113640
#undef f_1223c0
#undef f_125400
#undef f_1254a0
#undef f_125ed0
#undef f_133fe0
#undef f_147323

// ===== Teil gz_0fa9b0 (p3, 0fa9b0-0fac10) =====
#define d_1bfdbc d_1bfdbc_k5
#define d_1c0004 d_1c0004_k5
#define d_1c2c64 d_1c2c64_k5
#define d_1c3498 d_1c3498_k5
#define d_1c349c d_1c349c_k5
#define d_1c3870 d_1c3870_k5
#define f_041030 f_041030_k5
#define f_041920 f_041920_k5
#define f_042960 f_042960_k5
#define f_043e20 f_043e20_k5
#define f_044300 f_044300_k5
#define f_05fa00 f_05fa00_k5
#define f_060030 f_060030_k5
#define f_060a70 f_060a70_k5
#define f_0bf730 f_0bf730_k5
#define f_0d54f0 f_0d54f0_k5
#define f_0db9a0 f_0db9a0_k5
#define f_0de7c0 f_0de7c0_k5
#define f_0de7d0 f_0de7d0_k5
#define f_0f7120 f_0f7120_k5
#define f_0f7160 f_0f7160_k5
#define f_125400 f_125400_k5
#define f_1254a0 f_1254a0_k5
#define f_145234 f_145234_k5
#define f_145254 f_145254_k5
#define OB OB_k5
// P3 6/7 gleich (suche.py 24.10.2026, Basis gz_0fa9b0_P1.CPP)
// gz_0fa9b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FA9B0-0x0FAC10
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
short f_042960(hero *p);                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb708;                    // 0x1BB708
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (6), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern unsigned short d_1c21b4[];
extern int d_1c3498;
short f_0398c0(int p1, int p2, int p3);
short f_0db9a0(int p1);
short f_0d54f0(int p1, int p2);
int f_041030(int, ...);
int f_1254a0(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
void f_0f7120(void);
void f_0f7160(void);
void f_0faa10(int p1, int p2);
typedef RivaTextContextData OB;
struct Q { short a; short b; char c; int d; };

//@ f_0fa9b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchläuft beim Durchtauchen eines überfluteten Kanalgangs alle aktiven Helden der
 *   Gruppe (außer dem bereits geprüften Anführer d_1c0004) und wendet über f_0faa10 Wasserschäden (Rost) auf
 *   deren ungeschützte Metallwaffen und Rüstungen an.
 * - Eingaben: Die Funktion erhält den Kontextzeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fa9b0(int p1)
{
    int p0 = d_1c0004;
    int q;
    short k;
    for (k = 0; k < 6; k++) {
        q = (int)&d_1bfdbc + k * 0x61;
        if (f_0de7c0(q) != 0 && q != p0) {
            if (f_0db9a0(q)) {
                f_041920(q);
                f_060a70();
                f_0faa10(p1, q);
            }
        }
    }
    f_041920(p0);
}
//@ f_0faa10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt für einen einzelnen Helden p2 mithilfe der Filter f_0f7120 und f_0f7160 alle
 *   ungeschützten Metallwaffen und Rüstungsteile, gibt beim ersten betroffenen Stück eine Rost-Meldung
 *   (0x250000ec bzw. 0x250000ed) aus und verschlechtert den Erhaltungszustand bzw. Rüstungs-/Bruchfaktor der
 *   Gegenstände um 4 Punkte.
 * - Eingaben: Die Funktion erhält den Kontextzeiger p1 sowie den Heldenzeiger p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct MsgC { int h; int q[14]; MsgC(int a, int b, int c); ~MsgC(); };
void f_0faa10(int p1, int p2)
{
    MsgC m((int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    int *tab = (int *)d_1c21b4;
    short n;
    short k;
    int w;
    n = f_0398c0(p2, (int)f_0f7120, (int)tab);
    if (n > 0) {
        for (k = n - 1; k >= 0; k--) {
            int *pp = (int *)((int)d_1c21b4 + k * 4);
            w = *pp;
            if (k == n - 1) {
                *(int *)(m.q[0] + 4) = w;
                f_0bf730((int)&d_1c2c64, 0x250000ec);
            }
            f_043e20(w, 1);
            f_044300(w, (short)(((int)(f_042960((struct hero *)(w)))) - 4));
            f_043e20(w, 0);
            f_040780(w, 10);
        }
    }
    n = f_0398c0(p2, (int)f_0f7160, (int)tab);
    if (n > 0) {
        for (k = 0; k < n; k++) {
            w = tab[k];
            if (k == 0) {
                *(int *)(m.q[0] + 4) = w;
                f_0bf730((int)&d_1c2c64, 0x250000ed);
            }
            f_043e20(w, 1);
            f_044300(w, (short)(((int)(f_042960((struct hero *)(w)))) - 4));
            f_043e20(w, 0);
        }
    }
}
//@ f_0fab50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sucht im Inventar des Gruppenführers nach dem Gegenstand 399 (0x18f, vermutlich
 *   die magische Flöte des Rattenfängers) und übergibt ihn an die Aktionsfunktion f_041030.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fab50(void)
{
    short s = f_0d54f0(d_1c0004, 399); f_041030(1, f_0de7d0(d_1c0004, s));
}
//@ f_0fab80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet den Übergang zurück in den ersten Kanalisationsabschnitt (0x22, Startpunkt
 *   0x1f44).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fab80(void)
{
    f_05fa00(0x22, 0x1f44);
}
// f_0faba0 = $dt:X0f7260 (COMDAT aus virtual ~X0f7260(){ }), steht hinter dem normalen Code
// (anderes Modul)  f_0fabe0
// (Funktion f_0fabe0 gehoert zu einem anderen Modul, hier weggelassen)
// (anderes Modul)  f_0fabf0
// (Funktion f_0fabf0 gehoert zu einem anderen Modul, hier weggelassen)

#undef OB
#undef d_1bfdbc
#undef d_1c0004
#undef d_1c2c64
#undef d_1c3498
#undef d_1c349c
#undef d_1c3870
#undef f_041030
#undef f_041920
#undef f_042960
#undef f_043e20
#undef f_044300
#undef f_05fa00
#undef f_060030
#undef f_060a70
#undef f_0bf730
#undef f_0d54f0
#undef f_0db9a0
#undef f_0de7c0
#undef f_0de7d0
#undef f_0f7120
#undef f_0f7160
#undef f_125400
#undef f_1254a0
#undef f_145234
#undef f_145254

