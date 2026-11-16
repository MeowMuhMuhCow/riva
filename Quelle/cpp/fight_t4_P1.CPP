/* === Beschreibung (Katalog) ===
 * Einheit fight_t4 (08b500 - 08ba30)
 *
 * Überblick
 * Der vierte Teil der Hauptkampfeinheit (fight_t4) enthält die Funktion f_08b500, die innerhalb einer Kampfrunde
 * den Einzelzug des nächsten an der Reihe befindlichen Monsters auswählt, dessen zeitlich begrenzte Zustände
 * (Schlaf, Panik, Versteinerung, Blendung, Verzauberung) mit einer von der Rundendauer abhängigen
 * Wahrscheinlichkeit abklingen lässt, die Monster-KI (f_0855f0) aufruft und Sonderfälle wie das
 * Wiederauferstehen untoter oder regenerierender Gegner im Kampf Nr. 7 abwickelt.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 0/1 gleich (suche.py 25.10.2026, Basis fight_t4_P1.CPP)
// P2h 0/1 gleich
// fight_t4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08B500-0x08BA30
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
static inline void SND(int msg) { f_147323(d_1c2edc, msg, 0x7fff, 0x8000, d_1a9820, 0, 1); }
extern char d_1a2734[], d_1a2736[];
extern int d_1bc8f0;
extern short d_1bd90c;
extern char d_1bd918, d_1bd919;
extern signed char d_1bd928;
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

extern const char d_1a249a[];
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
extern unsigned short d_1bd920;
extern char d_1a2738, d_1a273a;
int f_08ae00(short p1, short p2, short p3, short p4, short *p5, short *p6);
int f_07b660();
int f_0cfcb0(int p1, int p2);
char f_0cfdf0(int p1);
char f_0cfe30(int p1);
int f_0cfe40(int p1, int p2);
char f_0cfef0(int p1);
int f_0cff00(int p1, int p2);
int f_0cff60(int p1, int p2);
char f_0cffe0(int p1);
int f_0cfff0(int p1, int p2);
char f_0cfec0(int p1);
int f_0cfed0(int p1, int p2);
int f_072940(int p1);
char f_0cfd70(int p1);
int f_0cff90(int p1, int p2);
short f_07cb00(int p1, int p2, int p3, int p4);
void f_0892a0(int p1, int p2);
int f_0cfd90(int p1, int p2);
int f_078ec0(int p1, int p2);
int f_0e93f0(void *p1, void *p2, int p3);
int f_0e9300(void *p1, void *p2, int p3);
int f_0cf970(int p1, int p2);
short f_0cfa50(int p1);
int f_0d0a20(int p1, int p2);
int f_06c930(int p1, int p2, int p3, int p4, int p5);


//@ f_08b500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt über f_07b660 das nächste handlungsfähige Monster der laufenden Kampfrunde aus, würfelt
 *   zu Zugbeginn das vorzeitige Abklingen negativer Kampfeffekte (Schlaf, Flucht, Versteinerung, Blindheit,
 *   *Bannbaladin*, *Horriphobus*) aus, übergibt das Monster an die Aktionssteuerung (f_0855f0) und lässt im
 *   Spezialkampf d_1bd920 == 7 bestimmte untote Kreaturen (f_0d0680 != 0) nach ihrem Tod auf einem freien
 *   Nachbarfeld (f_08ae00) mit voller Lebens- und Astralenergie wiederauferstehen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Hauptkampfstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das Feld *(short *)(p1 + 0x1ec) speichert den aktuellen Kamprundenzähler, der die
 *   Prozentchance (a, b, c, gedeckelt auf 50 %) für das Abschütteln von Lähmungs- und Angstzuständen mit jeder
 *   Runde erhöht.
 === Ende Beschreibung === */
void f_08b500(int p1)
{
    short b, c, a;
    // Deklarationsreihenfolge fuer die Stapelplatz-Zuteilung wie im Original
    short x20, ay, x2c, x1c, x28, x38, ax, x30;
    int m, mm;
    int ob;
    char *pv, *pq;
    short kind;
    x28 = 0; x30 = 0; x1c = 0; x2c = 0; x38 = 0; x20 = 0;
    
    m = f_07b660();
    if (f_0d06c0(m) != 0) f_078ec0(p1, m);
    else {
        if (d_1bd928) f_069460();
        f_0cfcb0(m, -1);
        if (f_071e90((char)(f_0729c0(m) + 10), &x38, &x20) != 0) {
            a = *(short *)(p1 + 0x1ec) + 2;
            if (a > 0x32) a = 0x32;
            b = *(short *)(p1 + 0x1ec) + 5;
            if (b > 0x32) b = 0x32;
            c = *(short *)(p1 + 0x1ec) + 8;
            if (c > 0x32) c = 0x32;
            if (d_1bd928) f_069460();
            if (f_0cfdf0(m) && !f_0cfdc0(m) && f_1457e0(100) < c) f_0cfe00(m, 0);
            if (f_0cfe30(m) && f_1457e0(100) <= a) f_0cfe40(m, 0);
            if (f_0cfef0(m) && f_1457e0(100) <= a) f_0cff00(m, 0);
            if (f_0cff50(m) && f_1457e0(100) <= a) f_0cff60(m, 0);
            if (f_0cffe0(m) && f_1457e0(100) <= b) f_0cfff0(m, 0);
            if (f_0cfec0(m) && f_1457e0(100) <= b) f_0cfed0(m, 0);
            if (f_072940(m) != 0) {
                if (f_0cfd70(m)) f_0cfd90(m, -1);
                else {
                    *(int *)(p1 + 0x205) = m;
                    d_1bda60 = 1;
                    if (f_0cff80(m) && f_1457e0(100) <= a) f_0cff90(m, 0);
                    kind = f_07cb00(p1, m, x38, x20);
                    if (kind == 2 || kind == 4 || kind == 5 || kind == 0x10) {
                        if (d_1bd928) f_069460();
                        f_0892a0(p1, m);
                        if (f_0cfd40(m) == 1 || f_0cfd40(m) == 4) {
                            mm = f_0d0910(m);
                            if ((short)d_1bd920 == 7 && f_0d0680(mm) != 0 && f_0cfdc0(mm)) {
                                if (f_0729c0(mm) == 0) d_1bd90c = 0;
                                else {
                                    pv = (char *)f_07ea60(p1 + 0x39, f_0cfc50(mm));
                                    f_071e90((char)(f_0729c0(mm) + 10), &x28, &x30);
                                    if (f_08ae00(x28, x30, 0x32, 0x37, &ax, &ay) != 0) {
                                        f_0cfdd0(mm, 0);
                                        f_0cfa20(mm, f_0cf9f0(mm));
                                        f_0cfa60(mm, f_0cfa30(mm));
                                        f_071e50(p1, x28, x30, pv[0xe]);
                                        f_071e50(p1, ax, ay, (char)(f_0729c0(mm) + 10));
                                        pv[0] = ax;
                                        pv[1] = ay;
                                        pv[0x20] = 1;
                                        if (!d_1bd928) f_06f5c0(p1, mm, p1 + 0x45);
                                    }
                                }
                            }
                            if (f_0cfdc0(mm)) {
                                f_071e90((char)(f_0729c0(mm) + 10), &x28, &x30);
                                f_0cfc80(mm, 1);
                                ob = f_07ea60(p1 + 0x39, f_0cfc50(mm));
                                *(char *)(ob + 10) = 5;
                                *(char *)(ob + 0x20) = 1;
                                pq = 0;
                                if (f_072910(mm) != 0) {
                                    if (f_071e90((char)(f_0729c0(mm) + 0x1e), &x1c, &x2c) != 0) {
                                        pq = (char *)f_07eb00(p1 + 0x39, (char)(*(char *)(ob + 0xd) + 0x14));
                                        f_071e50(p1, x1c, x2c, pq[0xe]);
                                        if (x28 == x1c && x30 == x2c) f_071e50(p1, x28, x30, (char)(f_0729c0(mm) + 10));
                                        pq[0] = x28 + d_1a2738;
                                        pq[1] = x30 + d_1a273a;
                                        pq[10] = 5;
                                        pq[0x20] = 1;
                                    }
                                }
                                if (f_0d0760(mm) == 1 || f_0d1320(mm) != 0) {
                                    f_071e50(p1, x28, x30, *(unsigned char *)(ob + 0xe));
                                    *(char *)(ob + 0x1f) = 1;
                                    if (pq != 0) pq[0x1f] = 1;
                                }
                                f_07e930(p1 + 0x39);
                            }
                        }
                    }
                    *(int *)(p1 + 0x205) = 0;
                }
            }
        }
        d_1bda60=(d_1bda60&0)?0:d_1bda60; // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
        if (d_1bd928) f_069460();
    }
}
