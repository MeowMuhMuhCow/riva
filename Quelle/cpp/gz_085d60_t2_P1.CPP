/* === Beschreibung (Katalog) ===
 * Einheit gz_085d60_t2 (087270 - 087780)
 *
 * Überblick
 * Die Einheit gz_085d60_t2 enthält zwei Funktionen für Kampfaktionen eines Helden (p2), die sich gegen einen
 * anderen Helden (p3) richten: den Fernkampfschuss (f_087270) sowie das Wirken eines Zauberspruchs (f_0873f0)
 * samt zugehörigen Kampfanimationen, Soundeffekten und Ergebnismeldungen.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 1/2 gleich (suche.py 25.10.2026, Basis gz_085d60_t2_P1.CPP)
// gz_085d60_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x087270-0x087780
#include <string.h>
short f_030080(int p1, int p2, int p3);
short f_030d80(int p1);
int f_03d4b0(int p1, int p2, int p3);



signed char f_0433d0(int p1);
int f_043430(int p1, int p2);
char f_043470(int p1);
signed char f_043490(int p1);
int f_044300(int p1, int p2);
int f_069460();
int f_069a00(int p1, int p2);
int f_069be0(int p1);
int f_06bd70(int p1, int p2, int p3);
int f_06bdd0(int p1, int p2, int p3);
int f_06c380(int p1, int p2, int p3);
int f_06c930(int p1, int p2, int p3, int p4, int p5);
int f_06e9e0(int p1, int p2, int p3, int p4, short *p5, int p6, int p7);
int f_06ed10(int p1, int p2, int p3);
short f_0722a0(int p1, int p2);
int f_0727e0(int p1);
int f_0757f0(int p1);
int f_0773b0(int p1);
int f_07b220(int p1);
int f_07b2d0();
int f_07bd30(int p1, int p2, int p3);
int f_07ea60(int p1, int p2);
int f_09c800(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09c890(void *p1, int p2, int p3, int p4, int p5);
int f_0bf730(void *p1, int p2);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(const char *p1, int p2);

void f_145300(int p1, int p2, int p3);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern char d_1a727a[];
extern unsigned short d_1a9820;
extern char d_1bd918;
extern char d_1bd928;
extern char d_1bfae0;
extern int d_1c0004;
extern int d_1c040e;
extern int d_1c0412;
extern int d_1c0424;
extern char  d_1c21b4[], d_1c2c64[], d_1c2d1c[], d_1c2edc[];
extern const char d_1c3498[], d_1c349c[], d_1c3870[];
static inline void SND(int msg) { f_147323(d_1c2edc, msg, 0x7fff, 0x8000, d_1a9820, 0, 1); }
short f_086a00(int p1, int p2, short p3);

//@ f_087270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Fernkampfangriff eines Helden (p2) auf einen anderen Helden (p3) aus: Sie prüft
 *   die Schussbereitschaft (f_086a00), berechnet Treffer und Schadenspunkte über f_030080, zieht den Schaden
 *   beim getroffenen Helden ab (f_044300), spielt die Schuss- und gegebenenfalls Sterbeanimation (f_06bdd0,
 *   f_06bd70) ab und verbraucht anschließend das Geschoss (f_086a00 mit Modus 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den schießenden Helden p2 sowie den
 *   anvisierten Helden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bd918 vermerkt, ob das getroffene Ziel durch den Schuss kampfunfähig wurde
 *   und seine Sterbeanimation abgespielt werden muss.
 === Ende Beschreibung === */
void f_087270(int p1, int p2, int p3)
{
    short s;
    if (f_030d80(p2) != -1) {
        if (f_086a00(p1, p2, 1)) {
            s = f_030080(p2, p3, 1);
            if (s > 0) {
                f_09c800(d_1c2d1c, 0x18, s, 2, p2, 2, p3);
                f_044300(p3, s);
                if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
            } else f_09c890(d_1c2d1c, 0x15, 0, 2, p3);
            if (!d_1bd928) {
                *(int *)(p1 + 0x289) = f_06bdd0(p1, p2, p1 + 0x45);
                *(char *)(p1 + 0x292) = 0;
                for (;;) {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                    if (f_069be0(*(int *)(p1 + 0x289)) != 0) break;
                }
                if (d_1bd918) {
                    *(char *)(p1 + 0x292) = 0;
                    *(int *)(p1 + 0x289) = f_06bd70(p1, p3, p1 + 0x45);
                    for (;;) {
                        f_069460();
                        if (*(char *)(p1 + 0x292)) break;
                        if (f_069be0(*(int *)(p1 + 0x289)) != 0) break;
                    }
                }
                f_086a00(p1, p2, 0);
                f_06ed10(p1, p2, p1 + 0x45);
                f_06ed10(p1, p3, p1 + 0x45);
                f_0757f0(p1);
                f_07bd30(p1, p2, p3);
            } else {
                f_086a00(p1, p2, 0);
                f_069460();
            }
        }
    }
}

//@ f_0873f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Zauberspruch eines Helden (p2) auf einen Helden (p3, z. B. Heil-, Stärkungs- oder
 *   Beherrschungszauber) aus: Sie berechnet die Zauberprobe und Spruchwirkung über f_03d4b0, dreht den
 *   Zaubernden in Richtung des Ziels (f_06e9e0), spielt Sprachausgabe, Zauberanimation (f_06c380),
 *   Spruch-Soundeffekt und Zielanimation (f_06c930, einschließlich Blitzeffekt f_07b2d0 bei *Fulminictus*) ab
 *   und zeigt abschließend den Ergebnistext an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den zaubernden Helden p2 sowie den
 *   Zielhelden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Flag d_1c040e zeigt an, ob der Zauber bereits vor dem Aussprechen
 *   gescheitert ist, während d_1c0412 steuert, ob am Ziel eine Trefferanimation eingeblendet wird.
 === Ende Beschreibung === */
void f_0873f0(int p1, int p2, int p3)
{
    struct RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    short w4;
    short k;
    d_1c0424 = 1;
    k = f_0433d0(p2);
    f_03d4b0(p2, 0, 0);
    if (d_1c040e == 0) f_043430(p2, -5);
    strcpy(*(char **)(p1 + 0xc), d_1c21b4);
    if (((char)(f_042750((struct hero *)(p2)))) && !d_1bd928) {
        o.tables.p[1] = p2;
        *(int *)(*(int *)(o.tables.c + 8) + 4) = f_0433d0(p2) + 0x20000097;
        f_07b220(0x1010031);
    }
    if (!d_1bd928) {
    if (d_1c040e == 0) {
        short c, s3;
        w4 = 0;
        c = f_043490(p2);
        s3 = f_0722a0(p1, p2);
        if (c != s3) {
            int ob;
            f_145300(p1 + 0x45, 0, 0xa4);
            *(int *)(p1 + 0x45) = f_0727e0(p2);
            f_06e9e0(p1, p2, c, s3, &w4, p1 + 0x45, 0);
            ob = f_07ea60(p1 + 0x39, f_043470(p2));
            *(char *)(p1 + w4 * 4 + 0x51) = 0xff;
            f_069a00(*(int *)(ob + 0xf), p1 + 0x45);
            do { f_069460(); } while (f_069be0(*(int *)(ob + 0xf)) == 0);
        }
        {
        char fl = d_1bfae0;
        if (fl && f_0773b0(d_1c0004) == 0) {
            int msg;
            msg = (f_042380((struct hero *)(p2)) == 0) ? k + 0xcffff : k + 0xd0054;
            f_147323(d_1c2edc, msg, 0x7fff, 0x8000, *(int *)&d_1a9820, 0, 1);
        }
        }
        *(int *)(p1 + 0x289) = f_06c380(p1, p2, p1 + 0x45);
        *(char *)(p1 + 0x292) = 0;
        do {
            f_069460();
            if (*(char *)(p1 + 0x292)) break;
        } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
        int t_489 = ((RivaFileManager*)(((char*)&d_1c2098)))->f_144870( *(int *)(d_1a727a + k * 14));
        if (t_489 != 0) { int s = *(int *)&d_1a9820; f_147323(d_1c2edc, *(int *)(d_1a727a + k * 14), 0x7fff, 0x8000, s, 0, 1); }
        else { int s; f_147323(d_1c2edc, 0xc0032, 0x7fff, 0x8000, (s = *(int *)&d_1a9820), t_489, 1); }
        if (d_1c0412 != 0) {
            *(int *)(p1 + 0x289) = f_06c930(p1, p3, p1 + 0x45, k, 2);
            *(char *)(p1 + 0x292) = 0;
            if (k == 0x31) f_07b2d0();
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
        }
        f_06ed10(p1, p2, p1 + 0x45);
        f_06ed10(p1, p3, p1 + 0x45);
        f_0757f0(p1);
    }
    if (f_0773b0(d_1c0004) != 0) f_07b220(f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
    else f_0bf730(d_1c2c64, f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
    f_07bd30(p1, p2, p3);
    } else f_069460();
}
