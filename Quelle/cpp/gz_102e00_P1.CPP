/* === Beschreibung (Katalog) ===
 * Einheit gz_102e00 (102e00 - 1036f0)
 *
 * Überblick
 *
 * Die Einheit gz_102e00 bildet den Übergangsblock zwischen den Schiffs-Dungeons ship1 (Kennung 0x2a) und ship2
 * (Kennung 0x2b). Sie enthält den Abschluss von ship1 (f_102e00) sowie den Konstruktor, die
 * Wand-/Tür-Synchronisation, den Destruktor und die Basis-Methoden des nächsten Schiffs-Dungeons ship2 (f_102e40
 * bis f_1036b0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/8 gleich (suche.py 24.10.2026, Basis gz_102e00_P1.CPP)
// gz_102e00.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x102E00-0x1036F0
#include <string.h>
#include "RIVAMEM.H"



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

//@ f_102e00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode schließt eine Rauminteraktion am Ende von ship1 ab, gibt einen Beschreibungstext
 *   (0x2e00009b) aus und setzt das zugehörige Zustandsflag.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_102e00(int p1, unsigned p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bb77c);
        f_145254();
        return p1;
    }
    r = f_0fb630(p1, 1);
    if (p2 & 2) operator delete((void *)r);
    return r;
}