/* === Beschreibung (Katalog) ===
 * Einheit mine1_t23 (Adresse 0x0c2f40 - 0x0c5490)
 *
 * Diese Einheit fasst den zweiten und dritten Teil des 3D-Dungeon-Moduls für die erste Ebene der Zwergenmine
 * (p:\riva\source\cpp\mine1.cpp) zusammen. Sie implementiert die Raum- und Objektinteraktionen in den Stollen,
 * Werkstätten und Schlafquartieren der Zwerge, darunter Einsturz- und Fallenereignisse, das Erbeuten von
 * Werkzeugen und Erzen sowie die Suche und Rast in den elf Zwergenspinden.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra650: mine1_t2+t3, Originalkontext mit gemeinsamem Epilog, 28.10.2026.
// P3 27/29 gleich (suche.py 24.10.2026, Basis mine1_t3_P1.CPP)
// mine1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C0E30-0x0C5D80
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
short f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_043ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044890(int p1, int p2);                           // reg eax edx stapel 0
short f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045170(int p1, int p2);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_047120(int p1);                                   // reg eax stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820(int p1, ...);
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
short f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_134840(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_1348d0();                                         // reg - stapel 0
int f_135040(int p1);                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a5600;                    // 0x1A5600
extern int d_1a5604;                    // 0x1A5604
extern int d_1a5606;                    // 0x1A5606
extern int d_1a5680;                    // 0x1A5680
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd6c8;                    // 0x1BD6C8
extern int d_1bd91c;                    // 0x1BD91C
extern short d_1bd922;
extern int d_1bf230;                    // 0x1BF230
extern int d_1bf24c;                    // 0x1BF24C
extern int d_1bf250;                    // 0x1BF250
extern int d_1bf254;                    // 0x1BF254
extern int d_1bf258;                    // 0x1BF258
extern int d_1bf25c;                    // 0x1BF25C
extern signed char d_1bf260;
extern signed char d_1bf264;
extern int d_1bf268;                    // 0x1BF268
extern int d_1bf26c;                    // 0x1BF26C
extern int d_1bf270;                    // 0x1BF270
extern int d_1bf274;                    // 0x1BF274
extern int d_1bf278;                    // 0x1BF278
extern int d_1bf27c;                    // 0x1BF27C
extern signed char d_1bf280;
extern signed char d_1bf284;
extern signed char d_1bf288;
extern int d_1bf28c;                    // 0x1BF28C
extern int d_1bf294;                    // 0x1BF294
extern int d_1bf298;                    // 0x1BF298
extern signed char d_1bf29c;
extern int d_1bf2a0;                    // 0x1BF2A0
extern int d_1bf2a4;                    // 0x1BF2A4
extern int d_1bf2a8;                    // 0x1BF2A8
extern int d_1bf2ac;                    // 0x1BF2AC
extern int d_1bf34c;                    // 0x1BF34C
extern int d_1c0004;                    // 0x1C0004
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a5660[];           // Text 0x1A5660
// --- eigene Funktionen (66), in dieser Reihenfolge definieren, je eine Zeile 
extern short mine2_d_1a9820;
#pragma aux mine2_d_1a9820 "d_1a9820"
extern char mine2_d_1a5680[];
#pragma aux mine2_d_1a5680 "d_1a5680"
extern const char mine2_d_1a5660[];
#pragma aux mine2_d_1a5660 "d_1a5660"
extern signed char mine2_d_1bf250, mine2_d_1bf254, mine2_d_1bf258, mine2_d_1bf25c, mine2_d_1bf274, mine2_d_1bf278, mine2_d_1bf294, mine2_d_1bf298;
#pragma aux mine2_d_1bf250 "d_1bf250"
#pragma aux mine2_d_1bf254 "d_1bf254"
#pragma aux mine2_d_1bf258 "d_1bf258"
#pragma aux mine2_d_1bf25c "d_1bf25c"
#pragma aux mine2_d_1bf274 "d_1bf274"
#pragma aux mine2_d_1bf278 "d_1bf278"
#pragma aux mine2_d_1bf294 "d_1bf294"
#pragma aux mine2_d_1bf298 "d_1bf298"
extern volatile signed char mine2_d_1bf27c;
#pragma aux mine2_d_1bf27c "d_1bf27c"
extern signed char mine2_d_1bf2a4;
#pragma aux mine2_d_1bf2a4 "d_1bf2a4"
extern int mine2_d_1c0004;
#pragma aux mine2_d_1c0004 "d_1c0004"
extern int mine2_d_1c21b4[];
#pragma aux mine2_d_1c21b4 "d_1c21b4"
extern char mine2_d_1c2c44[];
#pragma aux mine2_d_1c2c44 "d_1c2c44"
extern char mine2_d_1c2c64[];
#pragma aux mine2_d_1c2c64 "d_1c2c64"
extern char mine2_d_1c2edc[];
#pragma aux mine2_d_1c2edc "d_1c2edc"
extern const char mine2_d_1c3498[];
#pragma aux mine2_d_1c3498 "d_1c3498"
extern const char mine2_d_1c349c[];
#pragma aux mine2_d_1c349c "d_1c349c"
extern const char mine2_d_1c3870[];
#pragma aux mine2_d_1c3870 "d_1c3870"
struct ContextMine2 {public:
// P3 23/26 gleich (suche.py 25.10.2026, Basis mine1_t2_P1.CPP)
// mine1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C2F40-0x0C42C0
#define EQI(x,v) (((x)==(v))?1:0)
struct E10 { int a; short b; int f; };
struct T60 { struct E10 e[6]; };
struct Dlg14 { char b[0x14]; };
struct Dlg0c { char b[0xc]; Dlg0c(int); };
struct W;
struct VT { void (*f0)(struct W *, int); };
struct W { short s0; char b2[6]; struct VT *vt; };
static int f_0c2f00(int);
static int f_038be0(int p1);
static int f_038c40(int p1);
static int f_038d70(int p1, int p2);
static int f_039320(int p1, int p2);
static int f_039660(int p1, int p2);
static int f_0396f0(int p1, int p2);
static int f_0397d0(int p1, int p2);
static int f_0398c0(int p1, int (*p2)(int), int *p3);
static int f_039ac0(int p1, int (*p2)(int));
static int f_044090(int p1, int p2, int p3);
static int f_044850(int p1, int p2, int p3);
static short f_044900(int p1, int p2, int p3);
static short f_044c90(int p1, int p2, int p3);
static int f_045170(int p1, int p2);
static int f_043e20(int p1, int p2);
static short f_043a80(int p1, int p2);
static signed char f_043ac0(int p1, int p2);
static void *f_046d10(void *p1, int p2);
static int f_046d90(void *p1, int p2);
static int f_046de0(void *p1);
static int f_047120(void *p1);
static int f_054ca0(int p1, int p2);
static int f_0607e0(int p1, int p2);
static int f_060740(int p1, int p2);
static int f_060800(int p1, int p2, int p3);
static int f_0697c0(void *p1, int p2, int p3);
static int f_0bf6f0(const char *p1, int p2);
static int f_0bf730(const char *p1, int p2);
static short f_0bf820(const char *p1, ...);
static int f_0d4a60(int p1);
static short f_0d4c80(int p1);
static int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
static int f_0db820(int p1, int p2);
static int f_0dbeb0(int p1);
static int f_0db9d0(int p1, int p2, int p3);
static short f_0dcf00(int p1, int p2, int p3);
static int f_0dd100(int p1, int p2);
static void *f_112df0(void *p1, int p2, int p3, int p4);
static void *f_112e70(void *p1, int p2);
static int f_112ec0(void *p1);
static int f_1131b0(void *p1);
static int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
static int f_1254a0(void *p1, int p2);
static int f_125ed0(const char *p1, int p2);
static int f_125f70(const char *p1, int p2);
static int f_134840(void *p1, int p2, int p3, int p4, int p5, int p6);
static int f_1348d0(void *p1, int p2);
static int f_135040(void *p1);
static short f_145760(int p1, int p2);
static short f_1457e0(int p1);
static int f_147323(const char *p1, int p2, int p3, int p4, int p5, int p6, int p7);
struct SO { int a; int *p; int c[2]; int *q; char pad[40]; SO() { f_125400(this, mine2_d_1c349c, mine2_d_1c3870, mine2_d_1c3498); } ~SO() { f_1254a0(this, 0); } };
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
static void f_0c2f40(struct W *p);
static void f_0c3110(struct W *p);
static void f_0c31f0(struct W *p);
static void f_0c32c0(void);
static int f_0c3350(int p);
static int f_0c3390(int p);
static void f_0c3470(void);
static void f_0c36a0(void);
static void f_0c36c0(void);
static void f_0c3730(void);
static void f_0c3750(void);
static void f_0c3810(void);
static void f_0c3840(void);
static void f_0c38d0(void);
static void f_0c39a0(void);
static void f_0c39c0(void);
static void f_0c3a30(void);
static void f_0c3a60(void);
static void f_0c3ac0(void);
static void f_0c3b20(void);
static int f_0c3d70(int p);
static void f_0c3db0(void);
static void f_0c3f20(void);
static void f_0c3fc0(void);
static void f_0c4080(void);
static void f_0c4270(void);
};

//@ f_0c2f40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt ein Hindernis oder eine gefährliche Stelle in der Mine (0x191, Flag
 *   d_1bf250): Je nach Zustand von d_1bf274 entscheidet der Spieler über ein Auswahlmenü (0x35000010), ob die
 *   Stelle sofort überwunden und in der 3D-Karte freigeschaltet wird (0x37, f_0697c0), oder ein durch f_0c2f00
 *   ausgewählter Held löst das Ereignis direkt aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c2f40(struct W *p)
{
    int r = 0;
    SO o;
    if (EQI(mine2_d_1bf250, 0)) {
        if (!(!EQI(mine2_d_1bf274, 0))) {
            switch ((short)f_0bf820(mine2_d_1c2c64, 0x35000010, 2, 0x35000011, 0x35000012)) {
            case 1:
                o.p[1] = f_039660(mine2_d_1c0004, 0xb);
                f_0bf730(mine2_d_1c2c64, 0x35000013);
                f_0bf730(mine2_d_1c2c64, 0x35000014);
                ((void (*)(struct W *, int, int))p->vt->f0)(p, 0x37, 0);
                f_0697c0((char *)p + 2, 0x37, 0);
                f_060740(0x191, 0);
                mine2_d_1bf250 = 1;
                mine2_d_1bf274 = 0;
                goto fertig1306;
            case 2:
            case -1:
                *(signed char *)&d_1bf274 = 1;
                goto fertig1306;
            default:
                goto fertig1306;
            }
        } else {
            r = f_039ac0(mine2_d_1c0004, f_0c2f00);
            if (r != 0) {
                o.p[1] = r;
                f_0bf730(mine2_d_1c2c64, 0x35000015);
                f_0bf730(mine2_d_1c2c64, 0x35000014);
                ((void (*)(struct W *, int, int))p->vt->f0)(p, 0x37, 0);
                f_0697c0((char *)p + 2, 0x37, 0);
                f_060740(0x191, 0);
                mine2_d_1bf250 = 1;
                mine2_d_1bf274 = 0;
            }
        }
    }
fertig1306:
    ;
}
//@ f_0c3110
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Betreten des Nachbarfelds (0x192), ob das Ereignis d_1bf274 == 1 vorgemerkt
 *   und d_1bf250 == 0 noch offen ist, sucht über f_0c2f00 einen betroffenen Helden und schaltet den Durchgang
 *   0x37 (f_0697c0, f_060740) frei.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3110(struct W *p)
{
    int r;
    if (EQI(mine2_d_1bf274, 1) && EQI(mine2_d_1bf250, 0)) {
        r = f_039ac0(mine2_d_1c0004, f_0c2f00);
        if (r != 0) {
            SO o;
            o.p[1] = r;
            f_0bf730(mine2_d_1c2c64, 0x35000015);
            f_0bf730(mine2_d_1c2c64, 0x35000014);
            ((void (*)(struct W *, int, int))p->vt->f0)(p, 0x37, 0);
            f_0697c0((char *)p + 2, 0x37, 0);
            f_060740(0x191, 0);
            mine2_d_1bf250 = 1;
            mine2_d_1bf274 = 0;
        }
    }
}
//@ f_0c31f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst auf dem Feld 0x193 bei aktivem d_1bf274 == 1 und offenem d_1bf250 == 0 dasselbe
 *   Durchgangsereignis (0x37) mit dem Gruppenanführer (f_038c40) als Hauptperson aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c31f0(struct W *p)
{
    if (EQB(mine2_d_1bf250, 0) && EQI(mine2_d_1bf274, 1)) {
        SO o;
        o.p[1] = f_038c40(mine2_d_1c0004);
        f_0bf730(mine2_d_1c2c64, 0x35000015);
        f_0bf730(mine2_d_1c2c64, 0x35000014);
        ((void (*)(struct W *, int, int))p->vt->f0)(p, 0x37, 0);
        f_0697c0((char *)p + 2, 0x37, 0);
        f_060740(0x191, 0);
        mine2_d_1bf250 = 1;
        mine2_d_1bf274 = 0;
    }
}
//@ f_0c32c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler (0x35000016), ob ein ausgewählter Held (0x35000017) eine
 *   anstrengende Aktion oder Substanzaufnahme ausführen soll, die 5 Minuten dauert (f_125ed0) und dem Helden für
 *   0x3f480 Ticks (48 Spielstunden) einen Bonus/Malus über f_044090 verleiht.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c32c0(void)
{
    int r;
    if (f_0bf6f0(mine2_d_1c2c64, 0x35000016) == 1) {
        r = f_038d70(mine2_d_1c0004, 0x35000017);
        if (r != 0) {
            SO o;
            o.p[1] = r;
            f_0bf730(mine2_d_1c2c64, 0x35000018);
            f_125ed0(mine2_d_1c2c44, 5);
            f_044090(r, 0x3f480, 2);
        }
    }
}
//@ f_0c3350
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Helden-Prädikat prüft, ob ein handlungsfähiger Held (f_0d4a60) eine um 8 Punkte erschwerte
 *   Klugheitsprobe (Attribut 1, f_044900) besteht.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Probe gelingt, andernfalls 0.
 === Ende Beschreibung === */
int ContextMine2::f_0c3350(int p)
{
    int r = 0;
    if (f_0d4a60(p) != 0) {
        if (f_044900(p, 1, 8) > 0) r = 1;
    }
    return r;
}
//@ f_0c3390
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Callback-Funktion prüft für einen Helden p, ob ihm eine um 7 Punkte erschwerte Probe auf das
 *   Talent 0x12 (18) misslingt und seine getragene Rüstung/Belastung am Körperteil 6 mindestens drei Viertel des
 *   Maximalwerts erreicht (c1 >= (c2 * 3) / 4): In diesem Fall ertönt ein Geräusch (0x350030), der Held erleidet
 *   1W6+5 Schadenspunkte (f_044850) und erhält einen temporären Körperkraft-Abzug (-1 für 0x5460 Ticks).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held Schaden erlitten hat, andernfalls 0.
 === Ende Beschreibung === */
int ContextMine2::f_0c3390(int p)
{
    int r = 0;
    if (f_0d4a60(p) != 0) {
        if (f_044c90(p, 0x12, 7) <= 0) {
            short c1 = (signed char)f_043a80(p, 6);
            signed char c2 = f_043ac0(p, 6);
            if (c1 >= (short)((c2 * 3) / 4)) {
                int snd = *(int *)&mine2_d_1a9820;
                f_147323(mine2_d_1c2edc, 0x350030, 0x7fff, 0x8000, snd, 0, 1);
                f_043e20(p, 1);
                f_044850(p, 1, 5);
                f_0d5040(p, f_0d4c80(p), 0x5460, 6, -1, 0);
                r = 1;
                f_043e20(p, 0);
            }
        }
    }
    return r;
}
//@ f_0c3470
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein mehrstufiges Ereignis in einem Minenschacht (d_1bf254): Beim ersten
 *   Schritt (0) versucht der stärkste Held (Attribut 6), einen Mechanismus oder Felsbrocken zu bewegen, erleidet
 *   dabei Schaden (5W6+5) und temporäre Attributsabzüge und legt das Feld 0x1f47 frei; beim zweiten Schritt (1)
 *   kann ein kluger Held (f_0c3350) den Gegenstand 0x1a6 (422) bergen, während ungeschickte Helden über f_0c3390
 *   verletzt werden.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3470(void)
{
    short s;
    int r, u;
    SO o;
    if (EQI(mine2_d_1bf254, 0)) {
        if (f_0bf6f0(mine2_d_1c2c64, 0x35000019) == 1) {
            u = f_039660(mine2_d_1c0004, 6);
            o.p[1] = u;
            f_0bf730(mine2_d_1c2c64, 0x3500001a);
            f_0d5040(u, f_0d4c80(u), 0x2a30, 2, -1, 0);
            f_0d5040(u, f_0d4c80(u), 0x3f480, 6, -2, 0);
            f_044850(u, 5, 5);
            f_0bf730(mine2_d_1c2c64, 0x3500001b);
            f_054ca0(0xb, 400);
            f_054ca0(5, 400);
            f_0607e0(0x1f47, 1);
            f_060740(0x1f47, 1);
            mine2_d_1bf254 = 1;
        }
    }
    if (EQ(mine2_d_1bf254, 2)) {
        f_0bf730(mine2_d_1c2c64, 0x35000020);
    }
    if (EQ(mine2_d_1bf254, 1)) {
        r = f_039ac0(mine2_d_1c0004, f_0c3350);
        f_0bf730(mine2_d_1c2c64, 0x3500001c);
        if (r != 0) {
            o.p[1] = r;
            o.p[2] = f_0396f0(mine2_d_1c0004, 0xc);
            o.p[3] = f_039320(mine2_d_1c0004, 0xf);
            f_0bf730(mine2_d_1c2c64, 0x3500001d);
            s = f_0dcf00(mine2_d_1c0004, 0x1a6, 1);
            if (s == 1) {
                mine2_d_1bf254 = 2;
            }
        } else {
            o.p[1] = f_038c40(mine2_d_1c0004);
            f_0bf730(mine2_d_1c2c64, 0x3500001e);
        }
        s = f_0398c0(mine2_d_1c0004, f_0c3390, mine2_d_1c21b4);
        if (s > 0) {
            f_0bf730(mine2_d_1c2c64, 0x3500001f);
        }
    }
}
//@ f_0c36a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000021 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c36a0(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000021);
}
//@ f_0c36c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion wählt den Helden mit dem höchsten Wert in Eigenschaft 0x0d (f_039660), gibt
 *   die Texte 0x35000022 und 0x35000023 aus und lässt eine Stunde Spielzeit (f_125f70) vergehen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c36c0(void)
{
    SO o;
    o.p[1] = f_039660(mine2_d_1c0004, 0xd);
    f_0bf730(mine2_d_1c2c64, 0x35000022);
    f_0bf730(mine2_d_1c2c64, 0x35000023);
    f_125f70(mine2_d_1c2c44, 1);
}
//@ f_0c3730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000022 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3730(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000022);
}
//@ f_0c3750
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den Text 0x35000022 aus und öffnet anschließend den Beutebehälter 0x16 (22,
 *   f_112df0/f_112ec0), wobei ein Held mit hohem Talent 0x1d (f_039320) den Fund mit der Meldung 0x35000024
 *   kommentiert.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3750(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000022);
    Dlg14 *p = new (mark(mine2_d_1a5660, 0x448)) Dlg14;
    p = p ? (Dlg14 *)f_112df0(p, 0x16, 0, 0) : p;
    Dlg14 *q = p;
    if (f_1131b0(p) == 1) {
        SO o;
        o.p[1] = f_039320(mine2_d_1c0004, 0x1d);
        f_0bf730(mine2_d_1c2c64, 0x35000024);
        f_112ec0(p);
    }
    if (q != 0) {
        operator delete(f_112e70(q, 0));
    }
}
//@ f_0c3810
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt die beiden Beschreibungstexte 0x35000025 und 0x35000026 aus und lässt 10
 *   Minuten Spielzeit (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3810(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000025);
    f_0bf730(mine2_d_1c2c64, 0x35000026);
    f_125ed0(mine2_d_1c2c44, 10);
}
//@ f_0c3840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft und öffnet den Beutebehälter 0x17 (23, f_112df0): Sind noch Gegenstände darin
 *   vorhanden (f_1131b0 == 1), wird der Text 0x35000027 angezeigt und das Beutefenster geöffnet (f_112ec0),
 *   andernfalls erscheint die Leermeldung 0x35000025.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3840(void)
{
    struct Dlg14 *q;
    q = (struct Dlg14 *)operator new(0x14, mark(mine2_d_1a5660, 0x484));
    q = q ? (struct Dlg14 *)f_112df0(q, 0x17, 0, 0) : q;
    if (f_1131b0(q) == 1) {
        f_0bf730(mine2_d_1c2c64, 0x35000027);
        f_112ec0(q);
    } else {
        f_0bf730(mine2_d_1c2c64, 0x35000025);
    }
    if (q != 0) delete (char *)f_112e70(q, 0);
    f_125ed0(mine2_d_1c2c44, 5);
}
//@ f_0c38d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den stärksten Helden (Attribut 6) eine Fundstelle durchsuchen (0x35000028): Beim
 *   ersten Mal (d_1bf278 == 0) ertönt ein Münzgeräusch (0x350031) und die Gruppe findet 0x22 (34) Heller
 *   (f_0db820), bei späteren Besuchen wird nur noch auf die bereits geleerte Stelle (0x20000194) verwiesen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c38d0(void)
{
    int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
    SO o;
    o.p[1] = f_039660(mine2_d_1c0004, 6);
    if (EQI(mine2_d_1bf278, 1)) {
        o.q[1] = 0x20000194;
    } else {
        o.q[1] = 0x35000029;
        int snd = *(int *)&mine2_d_1a9820;
        f_147323_frame((int)mine2_d_1c2edc, 0x350031, 0x7fff, 0x8000, snd, 0, 1);
        f_0db820(mine2_d_1c0004, 0x22);
        mine2_d_1bf278 = 1;
    }
    f_0bf730(mine2_d_1c2c64, 0x35000028);
    f_125ed0(mine2_d_1c2c44, 10);
}
//@ f_0c39a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500002a aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c39a0(void)
{
    f_0bf730(mine2_d_1c2c64, 0x3500002a);
}
//@ f_0c39c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler (0x3500002b), ob die Gruppe einen Hebel oder Stützmechanismus
 *   betätigen will: Bei Zustimmung ertönt ein Einsturzgeräusch (0x350032), der Text 0x3500002c erscheint und
 *   alle Gruppenmitglieder erleiden schweren Steinschlag-Schaden (f_0dbeb0, f_0db9d0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c39c0(void)
{
    int r;
    if (f_0bf6f0(mine2_d_1c2c64, 0x3500002b) == 1) {
        f_147323(mine2_d_1c2edc, 0x350032, 0x7fff, 0x8000, (r=*(int*)&mine2_d_1a9820), 0, 1);
        f_0bf730(mine2_d_1c2c64, 0x3500002c);
        f_0dbeb0(mine2_d_1c0004);
        f_0db9d0(mine2_d_1c0004, 2, 5);
    }
}
//@ f_0c3a30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500002d aus und lässt 5 Minuten Spielzeit
 *   (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3a30(void)
{
    f_0bf730(mine2_d_1c2c64, 0x3500002d);
    f_125ed0(mine2_d_1c2c44, 5);
}
//@ f_0c3a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt den Helden mit dem niedrigsten Wert in Eigenschaft 0x0d (f_0396f0) und gibt
 *   mit dessen Namen die Meldung 0x3500002e aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3a60(void)
{
    SO o;
    o.p[1] = f_0396f0(mine2_d_1c0004, 0xd);
    f_0bf730(mine2_d_1c2c64, 0x3500002e);
}
//@ f_0c3ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet die verschlossene Truhe bzw. das Schloss-Objekt mit der Kennung 0x0b (11,
 *   f_046d10/f_046de0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3ac0(void)
{
    int p1 = (int)new (mark(mine2_d_1a5660, 0x524)) Dlg0c(0xb);
    if (f_047120((void *)p1) != 0) f_046de0((void *)p1);
    if (p1 != 0) delete (char *)f_046d90((void *)p1, 0);
}
//@ f_0c3b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet einen blockierten Durchgang oder Mechanismus (0x1f41, Zustand d_1bf27c):
 *   Zunächst muss der Gruppenanführer die Vorrichtung über eine Sinnenschärfe-Probe (0x33, +7) entdecken
 *   (d_1bf27c = 1); anschließend kann ein Held, der das passende Werkzeug bzw. Ersatzteil 0x19c (412) besitzt
 *   (f_0397d0), mit einer Mechanik-/Schlösser-Probe (0x30, +4) die Vorrichtung reparieren, wodurch das Hindernis
 *   auf der Karte entfernt (f_060800, f_0607e0) und das Bauteil verbraucht wird (f_0dd100).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3b20(void)
{
    short s;
    int r;
    SO o;
    int state = mine2_d_1bf27c;
    int msg = 0;
    if (EQI(state, 0)) {
        f_0bf730(mine2_d_1c2c64, 0x35000030);
        s = f_044c90(f_038c40(mine2_d_1c0004), 0x33, 7);
        if (s > 0) {
            mine2_d_1bf27c = 1;
            o.p[1] = f_038c40(mine2_d_1c0004);
            msg = 0x35000031;
        }
    }
    if (EQ(mine2_d_1bf27c, 1)) {
        if (msg == 0) msg = 0x35000032;
        switch ((unsigned short)f_0bf820(mine2_d_1c2c64, msg, 3, 0x35000033, 0x35000034, 0x35000035)) {
        case 1:
            f_0bf730(mine2_d_1c2c64, 0x35000036);
            break;
        case 2:
            r = f_0397d0(mine2_d_1c0004, 0x19c);
            if (r != 0) {
                o.p[1] = r;
                s = f_044c90(r, 0x30, 4);
                if (s > 0) {
                    f_0bf730(mine2_d_1c2c64, 0x35000037);
                    f_060800(0x350006, 1, 0);
                    f_060740(0x1f41, 1);
                    f_0607e0(0x1f42, 1);
                    f_0607e0(0x1f43, 1);
                    f_0dd100(mine2_d_1c0004, 0x19c);
                    mine2_d_1bf27c = 2;
                    return;
                }
                f_0bf730(mine2_d_1c2c64, 0x35000038);
                return;
            }
            o.p[1] = f_039660(mine2_d_1c0004, 1);
            f_0bf730(mine2_d_1c2c64, 0x35000039);
            return;
        case 3:
            o.p[1] = f_039660(mine2_d_1c0004, 6);
            f_0bf730(mine2_d_1c2c64, 0x3500003a);
            f_125ed0(mine2_d_1c2c44, 10);
            return;
        }
    }
}
//@ f_0c3d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Helden-Prädikat prüft, ob ein handlungsfähiger Held (f_0d4a60) eine um 5 Punkte erschwerte
 *   Zechen-Probe (Talent 0x26, f_044c90) besteht.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Probe gelingt, andernfalls 0.
 === Ende Beschreibung === */
int ContextMine2::f_0c3d70(int p)
{
    int r = 0;
    if (f_0d4a60(p) != 0) {
        if (f_044c90(p, 0x26, 5) > 0) r = 1;
    }
    return r;
}
//@ f_0c3db0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein Trinkgelage am Zwergen-Bierfass (0x3500003b): Beim ersten Mal (d_1bf25c ==
 *   0) trinken alle Helden, die die Zechen-Probe f_0c3d70 bestehen (oder mindestens ein zufälliger Held
 *   f_038be0), kräftig mit, erhalten zufällige Trinksprüche und Trunkenheitsstufen aus der 6-teiligen Tabelle
 *   d_1a5680 (f_045170), und es vergehen 4 Stunden Spielzeit (f_125f70).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3db0(void)
{
    short n;
    short k;
    short idx;
    int *e;
    if (f_0bf6f0(mine2_d_1c2c64, 0x3500003b) == 1) {
        if (EQI(mine2_d_1bf25c, 0)) {
            int *a = mine2_d_1c21b4;
            SO o;
            n = f_0398c0(mine2_d_1c0004, f_0c3d70, a);
            if (n == 0) {
                n = 1;
                mine2_d_1c21b4[0] = f_038be0(mine2_d_1c0004);
            }
            if (n > 0) {
                T60 t = *(T60 *)mine2_d_1a5680;
                for (k = 0; k < n; k++) {
                    do {
                        idx = f_145760(0, 5);
                    } while (t.e[idx].f == 1);
                    e = a + (short)k;
                    t.e[idx].f = 1;
                    o.p[1] = *e;
                    o.q[1] = t.e[idx].a;
                    f_0bf730(mine2_d_1c2c64, 0x3500003c);
                    f_045170(*e, t.e[idx].b);
                }
                mine2_d_1bf25c = 1;
                f_125f70(mine2_d_1c2c44, 4);
            }
        } else {
            f_0bf730(mine2_d_1c2c64, 0x35000043);
            f_125f70(mine2_d_1c2c44, 1);
        }
    }
}
//@ f_0c3f20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die Beschreibung 0x35000044 aus und lässt die Gruppe beim ersten Besuch (d_1bf258
 *   == 0) durch den besten Schätzen-/Handel-Helden (0x16) einen Münzschatz im Wert von 0x1b1c (6940 Hellern = 69
 *   Dukaten, 4 Silbertalern) finden (f_0db820).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3f20(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000044);
    if (EQI(mine2_d_1bf258, 0)) {
        mine2_d_1bf258 = 1;
        SO o;
        o.p[1] = f_039320(mine2_d_1c0004, 0x16);
        f_0bf730(mine2_d_1c2c64, 0x35000045);
        f_0db820(mine2_d_1c0004, 0x1b1c);
        f_125ed0(mine2_d_1c2c44, 10);
    }
}
//@ f_0c3fc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt die Gruppe beim ersten Besuch (d_1bf294 == 0) den Gegenstand 0x1d2 (466) finden
 *   (0x35000046), legt ihn ins Gruppeninventar (f_0dcf00) und zeigt seine Gegenstandsbeschreibung über
 *   f_134840/f_135040 an.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c3fc0(void)
{
    char arr[32];
    int u;
    if (EQI(mine2_d_1bf294, 0)) {
        u = f_039320(mine2_d_1c0004, 0x26);
        SO o;
        
        o.p[1] = u;
        f_0bf730(mine2_d_1c2c64, 0x35000046);
        if (f_0dcf00(mine2_d_1c0004, 0x1d2, 1) > 0) {
            f_134840(arr, 0, 0, 0, 0x1d2, 0);
            f_135040(arr);
            f_1348d0(arr, 0);
            mine2_d_1bf294 = 1;
        }
    }
}
//@ f_0c4080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet eine reiche Erzadern- oder Edelstein-Fundstelle (d_1bf298), an der die
 *   Gruppe nach einer ersten Gefahrenprobe (0x0f, +7) bis zu fünfmal (d_1bf2a4 von 0 bis 4) je 30 Minuten lang
 *   schürfen kann (0x35000049): Mit sinkender Erfolgswahrscheinlichkeit (90 - k * 20 %) gewinnt die Gruppe
 *   nacheinander die Fundstücke 0x1d3 bis 0x1d7 (467 bis 471), bis die Ader erschöpft ist oder einstürzt
 *   (d_1bf298 = 2).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c4080(void)
{
    int u;
    SO o;
    char arr[32];
    if (EQI(mine2_d_1bf298, 0)) {
        u = f_038c40(mine2_d_1c0004);
        o.p[1] = u;
        f_0bf730(mine2_d_1c2c64, 0x35000047);
        if (f_044c90(u, 0xf, 7) <= 0) {
            f_0bf730(mine2_d_1c2c64, 0x35000048);
            f_054ca0(0xb, -500);
            f_054ca0(5, -1000);
            f_125ed0(mine2_d_1c2c44, 10);
        }
        mine2_d_1bf298 = 1;
    }
    if (EQI(mine2_d_1bf298, 1)) {
        signed char c0 = mine2_d_1bf2a4;
        short k = c0;
        int go = 1;
        for (; k < (short)5; k++) {
                short v = k + 0x1d3;
                if (go != 1) break;
                {
                    int kk = k;
                    go = 0;
                    if (f_0bf6f0(mine2_d_1c2c64, (kk != 0) + 0x35000049) == 1) {
                        int t=kk*0x14;mine2_d_1bf2a4++;t=0x5a-t;
                        if (f_1457e0(0x64) < t) {
                            f_125ed0(mine2_d_1c2c44, 0x1e);
                            f_0bf730(mine2_d_1c2c64, 0x3500004b);
                            f_0dcf00(mine2_d_1c0004, (int)v, 1);
                            f_134840(arr, 0, 0, 0, (int)v, 0);
                            f_135040(arr);
                            go = 1;
                            f_1348d0(arr, 0);
                        } else {
                            mine2_d_1bf298 = 2;
                        }
                    }
                }
        }
    }
    if (EQI(mine2_d_1bf298, 2)) {
        f_0bf730(mine2_d_1c2c64, 0x3500004d);
    }
}
//@ f_0c4270
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt die vierteilige Textsequenz 0x35000050 bis 0x35000053 aus und lässt 6
 *   Stunden Spielzeit (f_125f70) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextMine2::f_0c4270(void)
{
    f_0bf730(mine2_d_1c2c64, 0x35000050);
    f_0bf730(mine2_d_1c2c64, 0x35000051);
    f_0bf730(mine2_d_1c2c64, 0x35000052);
    f_0bf730(mine2_d_1c2c64, 0x35000053);
    f_125f70(mine2_d_1c2c44, 6);
}

//@ f_xxxxxx davor ---

void f_0c5b70(int p1, int p2);
void f_0c5ac0(void);
#define A(x) ((int)&(x))
#define EQI(x,v) (((x)==(v))?1:0)
#define EQK(x,v) EQI(x,v)
#define GEI(x,v) (((x)>=(v))?1:0)
#define LTI(x,v) (((x)<(v))?1:0)
inline int GE(int a,int b){return a>=b;}
inline int LT(int a,int b){return a<b;}
struct OA { int a; int *p; int r[13]; };
typedef short (*VF)(int, int, int);
//@ f_0c42c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein mehrstufiges Rast- oder Gelage-Ereignis (d_1bf280 von 0 bis 4), bei dem
 *   die Gruppe beim ersten und zweiten Besuch entscheiden kann (0x3500004f / 0x35000054), ob sie 6 Stunden lang
 *   verweilt (0x35000050-0x35000053), und bei späteren Besuchen (d_1bf280 zwischen 2 und 3) den Kommentar
 *   0x35000055 erhält.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c42c0(void)
{
  struct OA obj;
  f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
  if (GEI(d_1bf280, 2) && LTI(d_1bf280, 4)) {
    d_1bf280 = d_1bf280 + 1;
    obj.p[1] = f_0396f0(d_1c0004, 0x26);
    f_0bf730(A(d_1c2c64), 0x35000055);
  }
  if (EQK(d_1bf280, 1)) {
    if (f_0bf6f0(A(d_1c2c64), 0x35000054) == 1) {
      f_0bf730(A(d_1c2c64), 0x35000050);
      f_0bf730(A(d_1c2c64), 0x35000051);
      f_0bf730(A(d_1c2c64), 0x35000052);
      f_0bf730(A(d_1c2c64), 0x35000053);
      f_125f70(A(d_1c2c44), 6);
      d_1bf280 = 2;
    }
  }
  if (EQK(d_1bf280, 0)) {
    d_1bf280 = 1;
    f_0bf730(A(d_1c2c64), 0x3500004e);
    f_125ed0(A(d_1c2c44), 0x1e);
    if (f_0bf6f0(A(d_1c2c64), 0x3500004f) == 1) {
      f_0bf730(A(d_1c2c64), 0x35000050);
      f_0bf730(A(d_1c2c64), 0x35000051);
      f_0bf730(A(d_1c2c64), 0x35000052);
      f_0bf730(A(d_1c2c64), 0x35000053);
      f_125f70(A(d_1c2c44), 6);
      d_1bf280 = 2;
    }
  }
  f_1254a0(A(obj), 0);
}
//@ f_0c4470
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt beim ersten Betreten (d_1bf284 == 0) mit dem wahrnehmungsstärksten Helden (0x33)
 *   die Entdeckungsmeldung 0x35000056 und bei späteren Besuchen den Kurztext 0x35000057 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4470(void)
{
  struct OA obj;
  if (EQK(d_1bf284, 0)) {
    f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    obj.p[1] = f_039320(d_1c0004, 0x33);
    f_0bf730(A(d_1c2c64), 0x35000056);
    d_1bf284 = 1;
    f_1254a0(A(obj), 0);
  } else {
    f_0bf730(A(d_1c2c64), 0x35000057);
  }
}
//@ f_0c44f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000058 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c44f0(void)
{
  f_0bf730(A(d_1c2c64), 0x35000058);
}
//@ f_0c4510
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000059 aus und lässt 10 Minuten Spielzeit
 *   (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4510(void)
{
  f_0bf730(A(d_1c2c64), 0x35000059);
  f_125ed0(A(d_1c2c44), 10);
}
//@ f_0c4540
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500005a aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4540(void)
{
  f_0bf730(A(d_1c2c64), 0x3500005a);
}
//@ f_0c4560
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet eine mit einer Falle gesicherte Geheimkammer oder Schatzkiste (d_1bf260):
 *   Zuerst muss der Gruppenanführer die Vorrichtung mit einer Sinnenschärfe-Probe (0x33, +10) entdecken
 *   (d_1bf260 = 1); danach erfordert das Entschärfen eine schwere Schlösser-Probe (0x30, +12) und eine
 *   Geschicklichkeitsprobe (Attribut 3), bei deren Scheitern der Held Schaden und mit 20 % bzw. 40 % Chance eine
 *   Vergiftung (f_040900(p1, 5)) erleidet, bevor sich der Beutebehälter 0x18 (24, f_0603b0) öffnet.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4560(void)
{
  struct Eq650 {static int eq(const signed char &a,int v){return a==v?1:0;}};
  struct OA obj;
  int p1;
  int flag;
  int t;
  short s;
  f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
  p1 = f_038c40(d_1c0004); obj.p[1] = p1;
  flag = 0;
  if (Eq650::eq(d_1bf260, 0)) {
    f_0bf730(A(d_1c2c64), 0x3500005b);
    if (f_044c90(p1, 0x33, 10) > 0) {
      f_0bf730(A(d_1c2c64), 0x3500005c);
      flag = 1;
      d_1bf260 = 1;
    }
  } else if (EQK(d_1bf260, 1)) {
    flag = 1;
    f_0bf730(A(d_1c2c64), 0x3500005d);
  }
  if (flag == 1) {
    if (f_044c90(p1, 0x30, 12) <= 0) {
      f_0bf730(A(d_1c2c64), 0x3500005e);
      f_044850(p1, 1, 5);
    } else {
      s = f_044900(p1, 3, 0);
      f_0bf730(A(d_1c2c64), 0x3500005f);
      f_0bf730(A(d_1c2c64), 0x35000060);
      if (s >= 8) {
        f_0bf730(A(d_1c2c64), 0x35000061);
        d_1bf260 = 2;
      } else {
        if (s >= 2) {
          f_044850(p1, f_1457e0(6), 2);
          if (f_1457e0(100) < 0x14) f_040900(p1, 5);
          f_0bf730(A(d_1c2c64), 0x35000062);
          d_1bf260 = 2;
        } else {
          f_044850(p1, f_1457e0(10), 2);
          if (f_1457e0(100) < 0x28) f_040900(p1, 5);
          f_0bf730(A(d_1c2c64), 0x35000063);
          d_1bf260 = 3;
        }
      }
      f_125ed0(A(d_1c2c44), 10);
    }
  }
  if (EQK(d_1bf260, 2)) f_0603b0(0x18);
  if (EQK(d_1bf260, 3)) f_0bf730(A(d_1c2c64), 0x35000064);
  f_1254a0(A(obj), 0);
}
//@ f_0c47c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet das Auswahlmenü für das erste Zwergenquartier (Spind-Bitmaske 0): Der Spieler
 *   kann den Spind durchsuchen (f_0c5b70(p1, 0)), 5 Stunden in den Zwergenbetten rasten (wobei Nicht-Zwerge
 *   wegen der kurzen Betten über f_0c5ac0 Rückenschmerzen/Schaden erleiden) oder den Raum verlassen.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c47c0(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4870
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 1 (0x0001).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4870(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 1);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000070 für ein leeres oder unbenutztes Quartier
 *   aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4910(void)
{
  f_0bf730(A(d_1c2c64), 0x35000070);
}
//@ f_0c4940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 2 (0x0002).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4940(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 2);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4a00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 4 (0x0004).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4a00(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 4);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4ab0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt ebenfalls den Beschreibungstext 0x35000070 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4ab0(void)
{
  f_0bf730(A(d_1c2c64), 0x35000070);
}
//@ f_0c4ae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt die einmalige Begegnung in einem bewachten Zwergenquartier (0x579, Flag
 *   d_1bf264) ab: Der Spieler hat drei Handlungsoptionen (0x35000072 bis 0x35000074), die entweder friedlich den
 *   Raum 0x350008 öffnen oder in die Kampfvarianten 7 bzw. 8 (d_1bd922, virtueller Aufruf 0x79) münden.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4ae0(int p1)
{
  struct OA obj;
  int u;
  if (EQI(d_1bf264, 0)) {
    switch ((short)f_0bf820(A(d_1c2c64), 0x35000071, 3, 0x35000072, 0x35000073, 0x35000074)) {
    case -1:
    case 1:
      f_060800(0x350008, 1, 0);
      break;
    case 2:
    f_0bf730(A(d_1c2c64), 0x35000075);
    d_1bd91c = 1;
    d_1bf288 = 1;
    d_1bd922 = 7;
    if ((*(VF *)*(int *)(p1 + 8))(p1, 0x79, 0) == 0) {
      f_060a70();
      u = f_039320(d_1c0004, 0x28);
      f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
      f_060800(0x35000a, 1, 0);
      signed char &flag650=d_1bf288;flag650=2;
      f_0bf730((obj.p[1] = u, A(d_1c2c64)), 0x35000077);
      if (f_044c90(u, 0x28, 5) > 0)
        f_0bf730(A(d_1c2c64), 0x35000078);
      else
        f_0bf730(A(d_1c2c64), 0x35000079);
      f_1254a0(A(obj), 0);
    }
    d_1bf264 = 1;
    f_0697c0(p1 + 2, 0x79, 0);
      break;
    case 3:
      f_0bf730(A(d_1c2c64), 0x35000076);
      d_1bd91c = 1;
      d_1bd922 = 8;
      (*(VF *)*(int *)(p1 + 8))(p1, 0x79, 0);
      d_1bf264 = 1;
      f_0697c0(p1 + 2, 0x79, 0);
      break;
    case 0:
      return;
    default:
      return;
    }
  }
}
//@ f_0c4cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 8 (0x0008).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4cc0(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 8);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x10 (16).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4d80(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x10);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4e40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Zwergenquartier mit der Bitmaske 0x20 (32): Wurde im Nachbarraum zuvor der
 *   Kampf d_1bf288 == 2 ausgelöst, erscheint die Meldung 0x3500007a, andernfalls steht das gewohnte
 *   Quartier-Menü (Spind durchsuchen oder 5 Stunden rasten) zur Verfügung.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4e40(int p1)
{
  char buf[28];
  char *q;
  if (EQK(d_1bf288, 2)) {
    f_0bf730(A(d_1c2c64), 0x3500007a);
    return;
  }
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x20);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4f20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x40 (64).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4f20(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x40);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c4fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500007b aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4fd0(void)
{
  f_0bf730(A(d_1c2c64), 0x3500007b);
}
//@ f_0c4ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler beim ersten Besuch (d_1bf29c == 0), ob er den entdeckten Gegenstand
 *   (0x3500007c) mitnehmen möchte, und übergibt bei Zustimmung den Gegenstand 0x4d (77) an das Gruppeninventar
 *   (f_0dcf00).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c4ff0(void)
{
  if (EQK(d_1bf29c, 0)) {
    if (f_0bf6f0(A(d_1c2c64), 0x3500007c) == 1) {
      if (f_0dcf00(d_1c0004, 0x4d, 1) == 1) d_1bf29c = 1;
    }
  }
}
//@ f_0c5060
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x80 (128).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5060(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x80);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c5120
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x100 (256).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5120(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x100);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c51d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500007d aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c51d0(void)
{
  f_0bf730(A(d_1c2c64), 0x3500007d);
}
//@ f_0c5200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x200 (512).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5200(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x200);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c52c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Auswahlmenü (Spind durchsuchen, 5 Stunden rasten oder weitergehen) für das
 *   Zwergenquartier mit der Bitmaske 0x400 (1024).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c52c0(int p1)
{
  char buf[28];
  char *q;
  switch ((short)f_0bf820(A(d_1c2c64), 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
  case -1:
    break;
  case 1:
    f_0c5b70(p1, 0x400);
    break;
  case 2:
    f_0bf730(A(d_1c2c64), 0x3500006e);
    ;
    f_125f70(A(d_1c2c44), 5);
    q = buf;
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)q) > 0) f_0bf730(A(d_1c2c64), 0x3500006f);
    break;
  case 3:
    break;
  }
}
//@ f_0c5370
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500007e aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5370(void)
{
  f_0bf730(A(d_1c2c64), 0x3500007e);
}
//@ f_0c5390
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x3500007f aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5390(void)
{
  f_0bf730(A(d_1c2c64), 0x3500007f);
}
//@ f_0c53b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion setzt den Namen des Gruppenanführers (f_038c40) in den Textkontext ein und
 *   gibt die Meldung 0x35000080 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c53b0(void)
{
  struct OA obj;
  f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
  obj.p[1] = f_038c40(d_1c0004);
  f_0bf730(A(d_1c2c64), 0x35000080);
  f_1254a0(A(obj), 0);
}
//@ f_0c5400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt für den Gruppenanführer (f_038c40) die Meldung 0x35000081 aus, belegt ihn
 *   über f_044090 für 0x3f480 Ticks (48 Stunden) mit dem Effekt 5 und lässt 10 Minuten Spielzeit (f_125ed0)
 *   verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5400(void)
{
  struct OA obj;
  int p1;
  p1 = f_038c40(d_1c0004);
  f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
  obj.p[1] = p1;
  f_0bf730(A(d_1c2c64), 0x35000081);
  f_044090(p1, 0x3f480, 5);
  f_125ed0(A(d_1c2c44), 10);
  f_1254a0(A(obj), 0);
}
//@ f_0c5470
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000082 aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5470(void)
{
  f_0bf730(A(d_1c2c64), 0x35000082);
}
