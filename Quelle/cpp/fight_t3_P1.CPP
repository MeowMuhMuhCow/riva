/* === Beschreibung (Katalog) ===
 * Einheit fight_t3 (08a020 - 08b500)
 *
 * Überblick
 * Die Einheit fight_t3 komplettiert die Kampfabwicklung im Rundenkampf: Sie enthält den Fernkampfangriff
 * (f_08a020) und den Zauberangriff (f_08a160) eines Monsters gegen einen Helden, das Einsetzen oder Werfen eines
 * Gegenstands durch einen Helden auf einen Helden (f_08a370) oder ein Monster (f_08a740), das Zusammenstellen
 * des Spähtextes über noch in Reserve wartende Gegner (f_08ab50), die Suche nach einem freien Nachbarfeld für
 * wiederauferstehende Gegner (f_08ae00) sowie die Hauptschleife für den gesamten Kampfrorunden-Zug eines Helden
 * (f_08af80).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 4/7 gleich (suche.py 24.10.2026, Basis fight_t3_P1.CPP)
// FA 4/7 gleich
// fight_t3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08A020-0x08B500
#include <string.h>
int f_030810(int p1);
int f_030890(int p1);
signed char f_030960(int p1);
int f_030e20(int p1, int p2);





signed char f_0433d0(int p1);
char f_043450(int p1);
char f_043470(int p1);
int f_0434a0(int p1, int p2);
int f_069460();
int f_069a00(int p1, int p2);
int f_06ed10(int p1, int p2, int p3);
int f_071e50(int p1, int p2, int p3, int p4);
int f_071e90(int p1, short *p2, short *p3);
short f_071fe0(int p1, int p2);
int f_0722a0(int p1, int p2);
int f_072910(int p1);
char f_0729c0(int p1);
int f_0757f0(int p1);
int f_0758b0(int p1);
int f_075f10(int p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0765a0(int p1);
int f_07e930(int p1);
int f_07ea60(int p1, int p2);
int f_07eb00(int p1, int p2);
int f_07eba0(int p1, int p2, int p3);
char f_07ec10(int p1, int p2);
int f_086bf0(int p1, int p2, int p3);
int f_087270(int p1, int p2, int p3);
int f_0873f0(int p1, int p2, int p3);
int f_09c780(void *p1);
int f_09c990(void *p1);
char f_0cf910(int p1);
char f_0cfc50(int p1);
signed char f_0cfc70(int p1);
int f_0cfc80(int p1, int p2);
char f_0cfdc0(int p1);
int f_0cfe00(int p1, int p2);
signed char f_0d01a0(int p1);
int f_0d06c0(int p1);
char f_0d54c0(int p1);
int f_033c50(int p1, int p2, int p3);
short f_030080(int p1, int p2, int p3);
short f_035110(int p1);



signed char f_043490(int p1);
int f_044300(int p1, int p2);
short f_045610(int p1);
short f_0456e0(int p1, int p2);
int f_069be0(int p1);
int f_06d4a0(int p1, int p2, int p3);
int f_06ed80(int p1, int p2, int p3);
int f_06f5c0(int p1, int p2, int p3);
int f_06f850(int p1, int p2, int p3, int p4);
int f_07bd30(int p1, int p2, int p3);
short f_0845b0(int p1, int p2);
int f_09c800(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09c890(void *p1, int p2, int p3, int p4, int p5);
int f_09c910(void *p1, int p2, int p3);
short f_0d0bb0(int p1, int p2, int p3);
int f_0d0960(int p1, int p2, int p3);
signed char f_0d11e0(int p1);
signed char f_0d1250(int p1);
char f_0cff50(int p1);
char f_0cff80(int p1);
short f_0de4d0(int p1);
short f_145760(int p1, int p2);
short f_1457e0(int p1);
extern signed char d_1bfaec;
short f_030d80(int p1);
short f_086a00(int p1, int p2, short p3);
int f_06bdd0(int p1, int p2, int p3);
extern int d_1c0004;
int f_03d4b0(int p1, int p2, int p3);

int f_043430(int p1, int p2);
int f_06c380(int p1, int p2, int p3);
int f_06df80(int p1, int p2, int p3, int p4, int p5);
int f_06e9e0(int p1, int p2, int p3, int p4, short *p5, int p6, int p7);
int f_0727e0(int p1);
int f_0773b0(int p1);
int f_07b220(int p1);
int f_07b2d0();
int f_0bf730(void *p1, int p2);
int f_133fe0(const char *p1, int p2);

void f_145300(int p1, int p2, int p3);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern char d_1a727a[];
extern int d_1a9820;
extern char d_1bfae0;
extern int d_1c040e, d_1c0412, d_1c0424;
extern char  d_1c21b4[], d_1c2c64[], d_1c2edc[];
extern const char d_1c3498[], d_1c349c[], d_1c3870[];
static inline void SND(int msg) { int s = d_1a9820; f_147323(d_1c2edc, msg, 0x7fff, 0x8000, s, 0, 1); }
extern char d_1a2734[], d_1a2736[];
extern int d_1bc8f0;
extern short d_1bd90c;
extern char d_1bd918, d_1bd919;
extern char d_1bd928;
extern unsigned char *d_1bd984;
extern int d_1bda64;
extern char *d_1c2ed4;
extern char d_1c2d1c[];

int f_0d0910(int p1);
int f_06f690(int p1, int p2, int p3);
short f_072440(int p1, int p2);
short f_0bd360(int p1);
signed char f_0cf950(int p1);
signed char f_0cfd00(int p1);
short f_0d00e0(int p1);
int f_0d00f0(int p1, short p2);
short f_0d0100(int p1);
short f_0d0120(int p1);
int f_0d0130(int p1, short p2);
short f_0d0140(int p1);
int f_0d10c0(int p1, int p2);
int f_06d580(int p1, int p2, int p3);
int f_06daa0(int p1, int p2, int p3);
extern char d_1a57f0[];
signed char f_0cfd40(int p1);
short f_045660(int p1);
short f_045710(int p1, int p2);

signed char f_043dc0(int p1);
int f_0d49b0(int p1);

char f_0d00c0(int p1);
int f_040a00(int p1, int p2, int p3);
int f_06efc0(int p1, int p2, int p3, int p4);
int f_0d08a0(int p1);
short f_072110(int p1, int p2);
signed char f_0cfce0(int p1);

short f_0d0df0(int p1, int p2);





int f_036300(int p1, int p2, int p3);
int f_03d790(int p1, int p2);
int f_044230(int p1, int p2);
int f_06d050(int p1, int p2, int p3);
int f_06d0d0(int p1, int p2, int p3, int p4);
int f_06bd70(int p1, int p2, int p3);

struct TAB { short t[20][2]; };
extern const struct TAB d_1a249a;
struct A20 { signed char v[20]; };
struct A8 { signed char v[4][2]; };
extern const struct A8 d_1a2838;
extern struct A20 d_1bdab8, d_1bdacc;
extern short d_1bd924;
extern char d_1c27a8[], d_1c38b0[];
char f_0d00a0(int p1);
int f_02ff70(int p1);
int f_043400(int p1, int p2);
int f_0d4a60(int p1);



char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);
int f_07d6a0(int p1, int p2);




short f_07fe00(int p1, int p2, int p3, int p4);
void f_087780(int p1, int p2);
int f_0d0680(int p1);
int f_0cfdd0(int p1, int p2);
short f_0cf9f0(int p1);
int f_0cfa20(int p1, int p2);
short f_0cfa30(int p1);
int f_0cfa60(int p1, int p2);
int f_0d0760(int p1);
int f_0d1320(int p1);
signed char f_043410(int p1);
extern int d_1bda60;
extern short d_1bd920;
extern char d_1a2738, d_1a273a;
int f_08ae00(short p1, short p2, short p3, short p4, short *p5, short *p6);
int f_0e93f0(void *p1, void *p2, int p3);
int f_0e9300(void *p1, void *p2, int p3);
int f_0cf970(int p1, int p2);
short f_0cfa50(int p1);
int f_0d0a20(int p1, int p2);
int f_06c930(int p1, int p2, int p3, int p4, int p5);

//@ f_08a160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Monsterzauber eines Monsters (p2) gegen einen Helden (p3) aus: Sie berechnet die
 *   Zauberwirkung über f_0d10c0, spielt die Zauberanimation des Monsters (f_06daa0), den Soundeffekt aus
 *   d_1a57f0 und die Trefferanimation am Helden (f_06c930, mit Blitzeffekt f_07b2d0 bei Spruch 7) ab und gibt
 *   den Kampftext samt etwaiger Todesmeldung (f_07bd30) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das zaubernde Monster p2 sowie den
 *   Zielhelden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1c0412 gibt an, ob am getroffenen Helden eine Spruchanimation abgespielt
 *   werden soll.
 === Ende Beschreibung === */
void f_08a160(int p1, int p2, int p3)
{
    short k;
    d_1c21b4[0] = 0;
    d_1c0424 = 1;
    k = f_0cfd00(p2);
    f_0d10c0(p2, 0);
    strcpy(*(char **)(p1 + 0xc), d_1c21b4);
    if (!d_1bd928) {
        if (d_1c040e == 0) {
            *(int *)(p1 + 0x289) = f_06daa0(p1, p2, p1 + 0x45);
            *(char *)(p1 + 0x292) = 0;
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            int sound;
            if ((sound = ((RivaFileManager*)(((char*)&d_1c2098)))->f_144870( *(int *)(d_1a57f0 + k * 12))) != 0) SND(*(int *)(d_1a57f0 + k * 12));
            else { int s; f_147323(d_1c2edc, 0xc002d, 0x7fff, 0x8000, (s = d_1a9820), sound, 1); }
            if (d_1c0412 != 0) {
                *(int *)(p1 + 0x289) = f_06c930(p1, p3, p1 + 0x45, k, 1);
                *(char *)(p1 + 0x292) = 0;
                if (k == 7) f_07b2d0();
                do {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            }
            f_06f5c0(p1, p2, p1 + 0x45);
            f_06ed10(p1, p3, p1 + 0x45);
            f_0757f0(p1);
        }
        if (f_0773b0(d_1c0004) != 0) f_07b220(f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
        else f_0bf730(d_1c2c64, f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
        f_07bd30(p1, p3, 0);
    } else f_069460();
}

//@ f_08a370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt das Benutzen oder Werfen des Gegenstands in der linken Hand (Slot 12) eines Helden (p2)
 *   auf einen Helden (p3) aus: Bei Wurfelexieren und Brandflaschen (0xee, 0xef, 0x3b, 0x8d, 0x8f) würfelt sie
 *   den Lebens- bzw. Astralpunkteschaden aus und verbraucht den Gegenstand (f_036300), bei normalen Tränken und
 *   Heilmitteln ruft sie die allgemeine Gegenstandswirkung f_03d790 auf und spielt anschließend die Trank- oder
 *   Wurfanimation (f_06d050 bzw. f_06d0d0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den handelnden Helden p2 sowie den
 *   Zielhelden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable kind unterscheidet das Trinken eines Elixiers (1) vom Werfen eines
 *   Wurfgeschosses (2).
 === Ende Beschreibung === */
void f_08a370(int p1, int p2, int p3)
{
    int msg = 0;
    short w, kind, v = 0;
    int u;
    w = f_042a60((struct hero *)(p2), 0xc);
    if (((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + w * 4)))->f_0a7910() != 0) kind = 1;
    else if (((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + w * 4)))->f_0a7970() == 0 || f_042ac0((struct hero *)(p2), 0xc) == 0) kind = 0;
    else kind = 2;
    if (w == 0xee) {
        if (!d_1bd928) msg = 0x1010026;
        v = f_145760(5, 10);
        f_044300(p3, v);
        f_09c890(d_1c2d1c, 0x11, v, 2, p3);
        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0xef) {
        if (!d_1bd928) msg = 0x101004c;
        v = f_145760(10, 0x19);
        f_044300(p3, v);
        f_09c890(d_1c2d1c, 0x11, v, 2, p3);
        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x3b) {
        if (!d_1bd928) msg = 0x101004d;
        v = f_145760(1, 0x14);
        f_044300(p3, v);
        f_09c890(d_1c2d1c, 0x11, v, 2, p3);
        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x8d) {
        if (!d_1bd928) msg = 0x101004e;
        v = f_145760(10, 0x28);
        f_044300(p3, v);
        f_09c890(d_1c2d1c, 0x11, v, 2, p3);
        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x8f) {
        if (!d_1bd928) msg = 0x101004f;
        if (f_0429a0((struct hero *)(p3))) {
            v = f_145760(10, 0x14);
            f_044230(p3, v);
            f_09c890(d_1c2d1c, 0x12, v, 2, p3);
        }
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else {
        f_03d790(p2, 0xc);
        msg = 0;
    }
    if (kind > 0) {
        if (!d_1bd928) {
            if (kind == 1) *(int *)(p1 + 0x289) = f_06d050(p1, p2, p1 + 0x45);
            else *(int *)(p1 + 0x289) = f_06d0d0(p1, p2, p1 + 0x45, v);
            *(char *)(p1 + 0x292) = 0;
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            if (d_1bd918) {
                *(int *)(p1 + 0x289) = f_06bd70(p1, p3, p1 + 0x45);
                *(char *)(p1 + 0x292) = 0;
                do {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            }
            f_06ed10(p1, p2, p1 + 0x45);
            f_06ed10(p1, p3, p1 + 0x45);
            f_0757f0(p1);
            f_07bd30(p1, p3, 0);
        } else f_069460();
    }
    if (msg != 0) f_0bf730(d_1c2c64, msg);
}

//@ f_08a740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt das Werfen oder Anwenden des Gegenstands in der linken Hand (Slot 12) eines Helden (p2)
 *   gegen ein Monster (p3) aus: Bei den Wurfflaschen und Wurfelexieren (0xee = 5..10 SP, 0xef = 10..25 SP, 0x3b
 *   = 1..20 SP plus Rüstungsmalus -2, 0x8d = 10..40 SP, 0x8f = 10..20 ASP-Entzug) wendet sie den Schaden direkt
 *   auf das Monster an (f_0d0960, f_0d0a20), verbraucht das Projektil (f_036300) und spielt die Wurf- und ggf.
 *   Sterbeanimation (f_06d0d0, f_06d4a0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den werfenden Helden p2 sowie den
 *   Monsterzeiger p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei speziellen unkörperlichen oder geschützten Monstern (f_0d06c0(p3) != 0) wird der
 *   Animationscode v für f_06d0d0 auf 0 gesetzt.
 === Ende Beschreibung === */
void f_08a740(int p1, int p2, int p3)
{
    short w = 0;
    int msg = 0;
    short kind, v = 0;
    int u;
    w = f_042a60((struct hero *)(p2), 0xc);
    if (((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + w * 4)))->f_0a7910() != 0) kind = 1;
    else if (((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + w * 4)))->f_0a7970() == 0 || f_042ac0((struct hero *)(p2), 0xc) == 0) kind = 0;
    else kind = 2;
    if (w == 0xee) {
        if (!d_1bd928) msg = 0x1010026;
        v = f_145760(5, 10);
        f_0d0960(p3, v, 0);
        f_09c890(d_1c2d1c, 0x13, v, 1, p3);
        if (f_0cfdc0(p3)) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0xef) {
        if (!d_1bd928) msg = 0x101004c;
        v = f_145760(10, 0x19);
        f_0d0960(p3, v, 0);
        f_09c890(d_1c2d1c, 0x13, v, 1, p3);
        if (f_0cfdc0(p3)) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x3b) {
        if (!d_1bd928) msg = 0x101004d;
        v = f_145760(1, 0x14);
        f_0d0960(p3, v, 0);
        f_0cf970(p3, -2);
        f_09c890(d_1c2d1c, 0x13, v, 1, p3);
        if (f_0cfdc0(p3)) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x8d) {
        if (!d_1bd928) msg = 0x101004e;
        v = f_145760(10, 0x28);
        f_0d0960(p3, v, 0);
        f_09c890(d_1c2d1c, 0x13, v, 1, p3);
        if (f_0cfdc0(p3)) d_1bd918 = 1;
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else if (w == 0x8f) {
        if (!d_1bd928) msg = 0x101004f;
        if (f_0cfa50(p3) > 0) {
            v = f_145760(10, 0x14);
            f_0d0a20(p3, v);
            f_09c890(d_1c2d1c, 0x14, v, 1, p3);
        }
        f_036300(p2, 0xc, 1);
        kind = 2;
        v = w;
    } else {
        f_03d790(p2, 0xc);
        msg = 0;
    }
    if (kind > 0) {
        if (!d_1bd928) {
            if (kind == 1) *(int *)(p1 + 0x289) = f_06d050(p1, p2, p1 + 0x45);
            else {
                if (f_0d06c0(p3) != 0) v = 0;
                *(int *)(p1 + 0x289) = f_06d0d0(p1, p2, p1 + 0x45, v);
            }
            *(char *)(p1 + 0x292) = 0;
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            if (d_1bd918) {
                *(int *)(p1 + 0x289) = f_06d4a0(p1, p3, p1 + 0x45);
                *(char *)(p1 + 0x292) = 0;
                do {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            }
            f_06ed10(p1, p2, p1 + 0x45);
            f_06f5c0(p1, p3, p1 + 0x45);
            f_0757f0(p1);
        } else f_069460();
    }
    if (msg != 0) f_0bf730(d_1c2c64, msg);
}

//@ f_08ab50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erstellt für das Kampfoptionsmenü einen Überblickstext in d_1c21b4, der alle noch in Reserve
 *   wartenden Verstärkungsmonster (f_0d00a0 != 0 und !f_0cfdc0) aufzählt (oder meldet, dass keine weiteren
 *   Gegner in Reserve lauern).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das lokale Array tab[20][2] soll gleichartige Monster zusammenfassen; da die innere
 *   Schleife jedoch den laufenden Slot-Index i (if (i == tab[j][0])) statt des Monstertyps vergleicht, wird
 *   jedes wartende Monster einzeln gezählt (siehe Fehlerliste).
 === Ende Beschreibung === */
void f_08ab50(void)
{
    struct TAB tb = d_1a249a;
    short count = 0;
    struct RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    short i, j, found;
#define KK i   /* Original nutzt die Schleifenvariable i wieder (kein eigenes k) */
    int n;
#define tab tb.t
    for (i = 0; i < d_1bd924; i++) {
        char *m = d_1c2ed4 + i * 0x73;
        if (f_0d00a0((int)m) && !f_0cfdc0((int)m)) {
            found = 0;
            for (j = 0; j <= count; j++) {
                if (i == tab[j][0]) {
                    found = 1;
                    tab[j][1]++;
                    break;
                }
            }
            if (!found) {
                tab[count][0] = i;
                tab[count][1] = 1;
                count++;
            }
        }
    }
    if (count) {
        f_0e93f0(d_1c38b0, d_1c21b4, 0x1010042);
        for (KK = 0; KK < (n = count) - 1; KK++) {
            *(int *)(*(int *)(o.tables.c) + 4) = (int)(d_1c2ed4 + tab[KK][0] * 0x73);
            *(short *)(*(int *)(o.tables.c + 0x14) + 2) = tab[KK][1];
            *(short *)(*(int *)(o.tables.c + 0xc) + 2) = tab[KK][1];
            f_0e93f0(d_1c38b0, d_1c27a8, 0x1010044);
            strcat(d_1c21b4, d_1c27a8);
            if (KK < n - 2) f_0e9300(d_1c38b0, d_1c21b4, 0x1010045);
        }
        if (n > 1) f_0e9300(d_1c38b0, d_1c21b4, 0x1010046);
        *(int *)(*(int *)(o.tables.c) + 4) = (int)(d_1c2ed4 + tab[count - 1][0] * 0x73);
        *(short *)(*(int *)(o.tables.c + 0x14) + 2) = tab[count - 1][1];
        *(short *)(*(int *)(o.tables.c + 0xc) + 2) = tab[count - 1][1];
        f_0e93f0(d_1c38b0, d_1c27a8, 0x1010044);
        strcat(d_1c21b4, d_1c27a8);
        f_0e9300(d_1c38b0, d_1c21b4, 0x20000196);
    } else {
        f_0e93f0(d_1c38b0, d_1c21b4, 0x1010043);
    }
#undef tab
#undef KK
}

//@ f_08ae00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht auf dem 24 x 24-Kampfraster bis zu 19 freie Felder, deren vier orthogonale Nachbarfelder
 *   keinen Kachelwert im Bereich p3..p4 aufweisen, wählt eines davon zufällig aus und schreibt dessen
 *   Koordinaten nach *p5 und *p6.
 * - Eingaben und Rückgabe: Die Funktion erhält die auszuschließende Startposition p1 (X) und p2 (Y), den
 *   verbotenen Nachbarkachel-Bereich p3..p4 sowie die Ausgabezeiger p5 und p6 und gibt 1 bei Erfolg zurück,
 *   sonst 0.
 * - Wichtige Variablen: Beim Prüfen der vier Nachbarfelder (d_1a2838) an den Rändern i == 0 und i == 23 fehlt
 *   eine Bereichsprüfung, sodass die Funktion vor bzw. hinter das Kampfraster d_1bd984 liest (siehe
 *   Fehlerliste).
 === Ende Beschreibung === */
#define MP(x,y) (*(d_1bd984 + (y)*25 + (x)))
int f_08ae00(short p1, short p2, short p3, short p4, short *p5, short *p6)
{
    struct A8 dirs = d_1a2838;
    struct A20 r1 = d_1bdab8;
    struct A20 r2 = d_1bdacc;
    int result = 0;
    signed char count = 0;
    signed char i, j, d;
    int found;
    unsigned char v;

    for (i = 0; i < 24; i++) {
        if (count >= 19) break;
        for (j = 0; j < 24; j++) {
            if (count >= 19) break;
            if (j == p1 && i == p2) continue;
            unsigned char *q = d_1bd984 + i * 25;
            { unsigned char *z = q; q = z; } // haelt den Zeilenzeiger q im Register edx wie im Original
            if (q[j]) continue;
            found = 1;
            for (d = 0; d < 4; d++) {
                unsigned char *row = (unsigned char *)((int)d_1bd984 + (i + dirs.v[d][1]) * 25);
                v = row[j + dirs.v[d][0]];
                if (v >= p3 && v <= p4) { found = 0; break; }
            }
            if (found != 1) continue;
            r1.v[count] = j;
            r2.v[count] = i;
            count++;
        }
    }
    if (count > 0) {
        unsigned char idx = f_1457e0(count) - 1;
        *p5 = r1.v[idx];
        *p6 = r2.v[idx];
        result = 1;
    }
    return result;
}

//@ f_08af80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert den kompletten Zug des aktuell an der Reihe befindlichen Helden (h) im Rundenkampf:
 *   Sie prüft zunächst ein automatisches Aufstehen nach einem Sturz (f_0424d0), zählt Lähmungs-/Aussetzrunden
 *   herunter (f_043230, f_043250), ruft für handlungsfähige Helden in einer Schleife die Aktionsauswahl f_07fe00
 *   und die Aktionsausführung f_087780 auf und aktualisiert danach getötete Gegner im Kampfraster
 *   (einschließlich der sofortigen Wiederbelebung untoter Spezialgegner im Kampf d_1bd920 == 7 über f_08ae00).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Hauptkampfstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Bei einem getöteten Monster (f_0cfdc0(m)) setzt die Funktion dessen
 *   Darstellungspriorität in OList auf 5 (Leiche am Boden) oder blendet es bei sich auflösenden Kreaturen
 *   (f_0d0760 / f_0d1320) vollständig aus.
 === Ende Beschreibung === */
void f_08af80(int p1)
{
    short l20, x38, x28, x2c, x30, x24;
    x38 = 0; l20 = 0;
    x30 = 0; x2c = 0; x28 = 0; x24 = 0;
    int o39, m, ob, done;
    char *pv;
    int h;
    short kind;
#define o39 o39
#define o39SET o39 = p1 + 0x39;
    if (d_1bd928) f_069460();
    h = f_02ff70(d_1c0004);
    f_043400(h, -1);
    if (((char)(f_0424d0((struct hero *)(h)))) && !((char)(f_042470((struct hero *)(h)))) && f_1457e0(100) < 0x4b) {
        f_030e20(h, 0);
        if (!d_1bd928) {
            f_07ea60(p1 + 0x39, f_043470(h));
            f_06ed10(p1, h, p1 + 0x45);
        }
    }
    if (f_071e90((char)(f_0d54c0(h) + 1), &x28, &x24) != 0 && f_043410(h) > 0) {
        if (f_0d4a60(h) != 0 && !((char)(f_042640((struct hero *)(h)))) && !((char)(f_0424d0((struct hero *)(h))))) {
            if (f_043230((struct hero *)(h))) f_043240((struct hero *)(h), (signed char)(f_043230((struct hero *)(h)) - 1));
            else {
                if (f_043250((struct hero *)(h))) f_043260((struct hero *)(h), (signed char)(f_043250((struct hero *)(h)) - 1));
                o39 = p1 + 0x39;
                do {
                    if (d_1bd928) f_069460();
                    d_1bda60 = 1;
                    done = 1;
                    *(int *)(p1 + 0x201) = h;
                    f_071e90((char)(f_0d54c0(h) + 1), &x28, &x24);
                    kind = f_07fe00(p1, h, x28, x24);
                    if (kind == 2 || kind == 4 || kind == 5 || kind == 0x10) {
                        f_087780(p1, h);
                        if (kind == 4 && d_1c040e == 1 && !((char)(f_042750((struct hero *)(h))))) done = 0;
                        else if (f_030960(h) == 1 || f_030960(h) == 4) {
                            m = f_030890(h);
                            if (d_1bd920 == 7 && f_0d0680(m) != 0 && f_0cfdc0(m)) {
                                short ax, ay;
                                int t_581 = f_0729c0(m);
                                if (t_581 == 0) d_1bd90c = 0;
                                else {
                                    pv = (char *)f_07ea60(o39, f_0cfc50(m));
                                    f_071e90((char)(f_0729c0(m) + 10), &x38, &l20);
                                    if (f_08ae00(x38, l20, 0x32, 0x37, &ax, &ay) != 0) {
                                        f_0cfdd0(m, 0);
                                        f_0cfa20(m, f_0cf9f0(m));
                                        f_0cfa60(m, f_0cfa30(m));
                                        f_071e50(p1, x38, l20, pv[0xe]);
                                        f_071e50(p1, ax, ay, (char)(f_0729c0(m) + 10));
                                        pv[0] = ax;
                                        pv[1] = ay;
                                        pv[0x20] = 1;
                                        if (!d_1bd928) f_06f5c0(p1, m, p1 + 0x45);
                                    }
                                }
                            }
                            if (f_0cfdc0(m)) {
                                if (f_071e90((char)(f_0729c0(m) + 10), &x38, &l20) == 1) {
                                    char *pq;
                                    f_0cfc80(m, 1);
                                    ob = f_07ea60(o39, f_0cfc50(m));
                                    *(char *)(ob + 10) = 5;
                                    *(char *)(ob + 0x20) = 1;
                                    pq = 0;
                                    if (f_072910(m) != 0) {
                                        if (f_071e90((char)(f_0729c0(m) + 0x1e), &x30, &x2c) != 0) {
                                            pq = (char *)f_07eb00(o39, (char)(*(char *)(ob + 0xd) + 0x14));
                                            f_071e50(p1, x30, x2c, pq[0xe]);
                                            if (x38 == x30 && l20 == x2c) f_071e50(p1, x38, l20 + ((signed char)l20 & 0), (char)(f_0729c0(m) + 10));
                                            pq[0] = x38 + d_1a2738;
                                            pq[1] = l20 + d_1a273a;
                                            pq[10] = 5;
                                            pq[0x20] = 1;
                                        }
                                    }
                                    if (f_0d0760(m) != 0 || f_0d1320(m) != 0) {
                                        f_071e50(p1, x38, l20, *(unsigned char *)(ob + 0xe));
                                        *(char *)(ob + 0x1f) = 1;
                                        if (pq != 0) pq[0x1f] = 1;
                                    }
                                    f_07e930(o39);
                                }
                            }
                        }
                    }
                    *(int *)(p1 + 0x201) = 0;
                    d_1bda60 = 1;
                } while (done == 0);
            }
        } else {
            if (((char)(f_042640((struct hero *)(h))))) {
                if (d_1bd928) f_069460();
                if (f_0d4a60(h) != 0 && !((char)(f_042600((struct hero *)(h))))) {
                    if (f_074b40(p1, h, x28, x24, 7, 1)) f_07d6a0(p1, h);
                } else f_042650((struct hero *)(h), 0);
            }
        }
    }
    if (d_1bd928) f_069460();
}
//@ f_08a020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Fernkampfangriff eines Monsters (p2) gegen einen Helden (p3) aus: Sie berechnet
 *   Treffer und Schadenspunkte über f_0d0df0, zieht den erlittenen Schaden beim Helden ab (f_044300) und spielt
 *   die Schuss- sowie ggf. die Sterbeanimation (f_06d580, f_06bd70) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das schießende Monster p2 sowie den
 *   beschossenen Helden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bd918 vermerkt, ob der getroffene Held durch den Schuss kampfunfähig wurde.
 === Ende Beschreibung === */
void f_08a020(int p1, int p2, int p3)
{
    short d;
    d = f_0d0df0(p2, p3);
    if (d > 0) {
        f_09c800(d_1c2d1c, 0xb, d, 1, p2, 2, p3);
        f_044300(p3, d);
        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
    } else f_09c890(d_1c2d1c, 0x15, 0, 2, p3);
    if (!d_1bd928) {
        *(int *)(p1 + 0x289) = f_06d580(p1, p2, p1 + 0x45);
        *(char *)(p1 + 0x292) = 0;
        do {
            f_069460();
            if (*(char *)(p1 + 0x292)) break;
        } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
        if (d_1bd918) {
            *(int *)(p1 + 0x289) = f_06bd70(p1, p3, p1 + 0x45);
            *(char *)(p1 + 0x292) = 0;
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
        }
        f_06f5c0(p1, p2, p1 + 0x45);
        f_06ed10(p1, p3, p1 + 0x45);
        f_0757f0(p1);
        f_07bd30(p1, p3, 0);
    } else f_069460();
}
