/* === Beschreibung (Katalog) ===
 * Einheit fight_t1 (087780 - 088a50)
 *
 * Überblick
 * Die Einheit fight_t1 steuert die Ausführung sämtlicher Kampfaktionen eines Helden (f_087780) sowie die drei
 * Kampfabläufe eines Helden gegen ein feindliches Monster: den Nahkampfangriff (f_087ea0), den Fernkampfangriff
 * (f_088510) und den Zauberangriff (f_0886c0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 2/4 gleich (suche.py 29.10.2026, Basis fight_t1_P1.CPP)
// P2h 1/4 gleich
// fight_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x087780-0x088A50
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
int f_08a370(int p1, int p2, int p3);
int f_08a740(int p1, int p2, int p3);
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
extern short d_1a9820;
extern char d_1bfae0;
extern int d_1c040e, d_1c0412, d_1c0424;
extern char  d_1c21b4[], d_1c2c64[], d_1c2edc[];
extern const char d_1c3498[], d_1c349c[], d_1c3870[];
static inline void SND(int msg) { f_147323(d_1c2edc, msg, 0x7fff, 0x8000, d_1a9820, 0, 1); }
extern char d_1a2734[], d_1a2736[];
extern char *d_1bc8f0;
extern short d_1bd90c;
extern char d_1bd918, d_1bd919;
extern char d_1bd928;
extern unsigned char *d_1bd984;
extern int d_1bda64;
extern char * d_1c2ed4;
extern char d_1c2d1c[];
void f_087ea0(int p1, int p2, int p3, signed char p4);
void f_088510(int p1, int p2, int p3);
void f_0886c0(int p1, int p2, int p3);

//@ f_087780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentrale Ausführungsfunktion für die Aktion eines Helden (p2) im Rundenkampf: Sie richtet den
 *   Helden und sein Ziel (Monster m oder Held obj, einschließlich Drehung zweifeldriger Großgegner) zueinander
 *   aus, blendet die grüne Zielmarkierung (p1 + 0x1f1) unter dem Ziel ein, verzweigt je nach gewähltem
 *   Aktionscode (2 = Nahkampf, 0x10 = Fernkampf, 4 = Zauber, 5 = Gegenstand benutzen) in die jeweilige
 *   Unterfunktion für Held- oder Monsterziele und räumt anschließend Kampfsounds und Anzeigefelder wieder auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den handelnden Helden p2 und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag isobj unterscheidet, ob das Ziel ein Held (1) oder ein Monster (0) ist, und
 *   flag markiert Angriffe auf das Hinterteil eines zweifeldrigen Monsters oder Situationen, in denen sich ein
 *   Großgegner wegen Platzmangels nicht zum Angreifer umdrehen kann.
 === Ende Beschreibung === */
void f_087780(int p1, int p2)
{
    // Deklarationsreihenfolge fuer die Stapelplatz-Zuteilung wie im Original
    int m;
    int ob;
    short s;
    short flag;
    short sx;
    short dx2;
    short dy;
    char *pv;
    int obj;
    short isobj;
    short xa;
    short ya;
    short t;
    short sy;

    isobj = 0;
    flag = 0;
    if (!d_1bd90c) return;
    if (d_1bd928) f_069460();
    f_09c780(d_1c2d1c);
    *(char *)(p1 + 0x1ee) = *(char *)(p1 + 0x1ef) = d_1bd919 = *(char *)(p1 + 0x1f0) = d_1bd918 = 0;
    if (f_030960(p2) == 1 || f_030960(p2) == 4) {
        if (f_030960(p2) == 4) flag = 1;
        m = f_030890(p2);
        f_0cfe00(m, 0);
        if (!f_0cf910(m) || !f_071e90((unsigned char)((char)(f_0432b0((struct hero *)(p2)))), &xa, &ya) || (f_0cfdc0(m) && (f_042810((struct hero *)(p2)) != 4 || f_0433d0(p2) != 0x17))) return;
        if (f_072910(m) != 0 && !flag && !f_0d01a0(m) && f_042810((struct hero *)(p2)) == 2) {
            s = f_071fe0(p1, p2);
            if (f_0cfc70(m) != s) {
                f_071e90((unsigned char)(f_0729c0(m) + 10), &xa, &ya);
                sx = xa + *(short *)(d_1a2734 + s * 4);
                sy = ya + *(short *)(d_1a2736 + s * 4);
                t = *(sx + (d_1bd984 + sy * 0x19));
                if (t >= (short)0x32
                    || (t < (short)10 && t >= (short)1 && !((char)(f_042470((struct hero *)((int)(d_1bc8f0 + (t - 1) * 0x5ef))))))
                    || (t >= (short)10 && t < (short)0x1e && !f_0cfdc0((int)(d_1c2ed4 + (t - 10) * 0x73)))
                    || (t >= (short)0x1e && t < (short)0x32 && !f_0cfdc0((int)(d_1c2ed4 + (t - 0x1e) * 0x73)))) {
                    flag = 1;
                } else {
                    dx2 = xa + *(short *)(d_1a2734 + f_0cfc70(m) * 4);
                    dy = ya + *(short *)(d_1a2736 + f_0cfc70(m) * 4);
                    ob = f_07ea60(p1 + 0x39, (unsigned char)f_0cfc50(m));
                    pv = (char *)f_07eb00(p1 + 0x39, (unsigned char)(*(char *)(ob + 0xd) + 0x14));
                    f_071e50(p1, dx2, dy, (unsigned char)pv[0xe]);
                    f_071e50(p1, sx, sy, (unsigned char)(f_0729c0(m) + 0x1e));
                    pv[0xe] = t;
                    pv[0] = sx;
                    pv[1] = sy;
                    pv[0x20] = 1;
                    *(char *)(ob + 0x20) = 1;
                    f_07e930(p1 + 0x39);
                }
            }
        }
        if (!flag && !f_0d01a0(m) && f_042810((struct hero *)(p2)) == 2 && d_1bd928) {
            f_0cfc80(m, (signed char)f_071fe0(p1, p2));
        }
    } else if (f_030960(p2) == 2) {
        obj = f_030810(p2);
        if (((char)(f_042470((struct hero *)(obj)))) || !f_071e90((unsigned char)((char)(f_0432b0((struct hero *)(p2)))), &xa, &ya) || !((char)(f_042350((struct hero *)(obj))))) return;
        if (((char)(f_0424d0((struct hero *)(obj))))) {
            f_030e20(obj, 0);
            if (!d_1bd928) {
                ob = f_07ea60(p1 + 0x39, (unsigned char)f_043470(obj));
                f_06ed10(p1, obj, p1 + 0x45);
                f_069a00(*(int *)(ob + 0xf), p1 + 0x45);
            }
        }
        if (d_1bd928 && !f_043450(obj)) {
            f_0434a0(obj, (signed char)f_071fe0(p1, p2));
        }
        isobj = 1;
    } else if (f_030960(p2) == 5) {
        obj = p2;
        isobj = 1;
    }
    if (d_1bd928) {
        f_0434a0(p2, (signed char)f_0722a0(p1, p2));
    }
    if (!d_1bd928) {
        *(int *)(p1 + 0x20d) = 0;
        *(int *)(p1 + 0x209) = 0;
        d_1bda64 = 1;
        if (*(char *)(p1 + 0x294) != (char)0xff) {
            f_07eba0(p1 + 0x39, *(unsigned char *)(p1 + 0x294), 0);
            *(char *)(p1 + 0x294) = 0xff;
        }
        if (isobj) {
            f_071e90((unsigned char)(f_0d54c0(obj) + 1), &xa, &ya);
            *(int *)(p1 + 0x209) = obj;
        } else {
            f_071e90((unsigned char)(f_0729c0(m) + 10), &xa, &ya);
            *(int *)(p1 + 0x20d) = m;
        }
        if (isobj || (!isobj && !f_0d06c0(m))) {
            *(char *)(p1 + 0x1e) = 0;
            *(char *)(p1 + 0x18) = xa;
            *(char *)(p1 + 0x19) = ya;
            *(char *)(p1 + 0x1f) = 0;
            *(char *)(p1 + 0x20) = 6;
            *(char *)(p1 + 0x24) = 0;
            *(int *)(p1 + 0x27) = 0;
            *(int *)(p1 + 0x2b) = *(int *)(p1 + 0x1f1);
            *(char *)(p1 + 0x22) = 2;
            *(char *)(p1 + 0x23) = 1;
            *(char *)(p1 + 0x25) = 0xff;
            *(char *)(p1 + 0x294) = f_07ec10(p1 + 0x39, -1);
        }
        f_0757f0(p1);
        *(int *)(p1 + 0x20d) = 0;
        *(int *)(p1 + 0x209) = 0;
    }
    if (f_042810((struct hero *)(p2)) == 2) {
        if (isobj) f_086bf0(p1, p2, obj);
        else f_087ea0(p1, p2, m, flag);
    } else if (f_042810((struct hero *)(p2)) == 0x10) {
        if (isobj) f_087270(p1, p2, obj);
        else f_088510(p1, p2, m);
    } else if (f_042810((struct hero *)(p2)) == 4) {
        if (isobj) f_0873f0(p1, p2, obj);
        else f_0886c0(p1, p2, m);
    } else if (f_042810((struct hero *)(p2)) == 5) {
        if (isobj) f_08a370(p1, p2, obj);
        else f_08a740(p1, p2, m);
    }
    f_09c990(d_1c2d1c);
    if (!d_1bd928) {
        if (*(char *)(p1 + 0x294) != (char)0xff) {
            f_07eba0(p1 + 0x39, *(unsigned char *)(p1 + 0x294), 0);
            *(char *)(p1 + 0x294) = 0xff;
        }
        *(int *)(p1 + 0x20d) = 0;
        *(int *)(p1 + 0x209) = 0;
        d_1bda64 = 1;
        f_0758b0(p1);
        f_0762e0(0, 0x91, 100, 199);
        f_0765a0(p1);
        f_075f10(p1);
    }
}



//@ f_087ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Nahkampfangriff eines Helden (p2) gegen ein Monster (p3) aus: Sie ermittelt den
 *   Attackewert des Helden (und zieht bei unbewaffneten KI-Helden über f_0845b0 ggf. eine Waffe), würfelt
 *   Attacke, Parade sowie kritische Treffer und Patzer für beide Seiten aus, berechnet den Waffenschaden
 *   (f_030080), zieht die Lebenspunkte beim getroffenen Monster (f_0d0960) bzw. bei einem Passierschlag beim
 *   Helden (f_044300) ab und spielt die Kampfanimationen (f_06ed80, f_06f850, f_06d4a0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den angreifenden Helden p2, den
 *   verteidigenden Monsterzeiger p3 sowie das Flanken-/Hinterteil-Flag p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Greift der Held das Hinterteil eines Großmonsters an oder kann sich das Monster nicht
 *   drehen (p4 != 0), entfällt dessen Paradewurf sowie ein etwaiger Passierschlag gegen den Helden.
 === Ende Beschreibung === */
void f_087ea0(int p1, int p2, int p3, signed char p4)
{
    short sv, sd, r;
    short s4;
    char extraA; // haelt die interne Symbolnummerierung der Lokalen wie im Original
    struct Frame493 {short s20,s5,s18,s14;} f;
    int u, wait;
    int t = 0;
    short flag = 0;
    if (d_1bd928) f_069460();
    f.s18 = f_035110(p2);
    if (f.s18 == -1) {
        if (((char)(f_042750((struct hero *)(p2))))) {
            f_0845b0(p1, p2);
            f.s18 = f_035110(p2);
            if (f.s18 != -1) goto L06;
        }
        f.s20 = f_0456e0(p2, 0);
    } else {
L06:
        f.s20 = f_045610(p2);
    }
    sd = f_0de4d0(d_1c0004);
    if (sd == (short)-5) f.s20 -= 4;
    if (f_0d01a0(f_030890(p2)) == 1 || p4) f.s20 += 2;
    f.s20 += 4;
    if (d_1bd928) f.s20 += 2;
    s4 = f_1457e0(0x14);
    if (s4 == 0x14 && f_1457e0(0x14) > f.s20 - 9) {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x22), f.s20, 0, s4, -1);
#endif
        short s3 = 0;
        f.s14 = 0;
        f_09c890(d_1c2d1c, 1, 0, 2, p2);
        s3 = f_145760(2, 0xc);
        if (s3 == 2 && f.s18 != -1) {
            if (f_033c50(p2, 3, 1) != 0) f_09c910(d_1c2d1c, 6, 0);
        } else if (s3 >= 3 && s3 <= 8 && !p4) {
            *(char *)(p1 + 0x1ef) = 1;
            if (f_1457e0(0x14) <= f_0d11e0(p3)) f.s14 = f_0d0bb0(p3, p2, 0);
            if (f.s14 > 0) {
                f_09c800(d_1c2d1c, 0xb, f.s14, 1, p3, 2, p2);
                f_044300(p2, f.s14);
            }
            if (((char)(f_042470((struct hero *)(p2))))) *(char *)(p1 + 0x1f0) = 1;
        } else if (s3 >= 9 && s3 <= 11) {
            s3 = f_1457e0(6);
            f_09c890(d_1c2d1c, 0xd, s3, 2, p2);
            f_044300(p2, s3);
            if (((char)(f_042470((struct hero *)(p2))))) *(char *)(p1 + 0x1f0) = 1;
        }
    } else {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x22), f.s20, 0, s4, (s4 > f.s20) ? 0 : (s4 < *(short *)(p1 + 0x1ec) / 2 + 2) ? 2 : 1);
#endif
        if (s4 > f.s20) {
            f_09c910(d_1c2d1c, 5, 0);
        } else {
            if (!f_0d01a0(f_030890(p2)) && !p4) {
                sv = f_0d1250(p3);
                { signed char q = d_1bfaec; if (q == 0) sv /= (short)2; }
                if (f_0cff50(p3) || f_0cff80(p3)) sv = 0;
                f.s5 = f_1457e0(0x14);
                if (f.s5 == 0x14 && f_1457e0(0x14) > ((sv & 0) ? (short)0 : sv) - 7 /* haelt sv ueber den Aufruf im passenden Register */) {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x49), sv, 0, f.s5, -1);
#endif
                    flag = 1;
                    f_09c890(d_1c2d1c, 4, 0, 1, p3);
                    sv = f_145760(2, 0xc);
                    if (sv >= 3 && sv <= 8) {
                        *(char *)(p1 + 0x1ee) = 1;
                        if (f_1457e0(0x14) <= f.s20) {
                            sv = f_030080(p2, p3, 0);
                            if (sv > 0) {
                                f_09c800(d_1c2d1c, 8, sv, 2, p2, 1, p3);
                                f_0d0960(p3, sv, 0);
                                { int extraB = d_1c0004; d_1c0004 = extraB; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
                                if (f_0cfdc0(p3)) d_1bd918 = 1;
                            }
                        }
                    } else if (sv >= 9 && sv <= 11) {
                        sv = f_1457e0(6);
                        f_09c890(d_1c2d1c, 0x10, sv, 1, p3);
                        f_0d0960(p3, sv, 1);
                        if (f_0cfdc0(p3)) d_1bd918 = 1;
                    }
                } else {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x49), sv, 0, f.s5, (f.s5 <= sv) ? 1 : 0);
#endif
                    if (sv < f.s5) flag = 1;
                    else {
                        f_09c890(d_1c2d1c, 0xc, 0, 1, p3);
                        if (f.s5 == s4) {
                            if (f_042be0((struct hero *)(p2), 3) > 3) {
                                t = f_1457e0(0xc);
                                if (f_042be0((struct hero *)(p2), 3) + t > 0x14) {
                                    if (f_033c50(p2, 3, 1) != 0) f_09c890(d_1c2d1c, 6, 0, 2, p2);
                                } else f_042ca0((struct hero *)(p2), 3);
                            } else f_042ca0((struct hero *)(p2), 3);
                        }
                    }
                }
            } else flag = 1;
            if (flag) {
                if (s4 < *(short *)(p1 + 0x1ec) / 2 + 2) r = f_030080(p2, p3, 2);
                else r = f_030080(p2, p3, 0);
                if (r > 0) {
                    f_09c800(d_1c2d1c, 8, r, 2, p2, 1, p3);
                    f_0d0960(p3, r, 0);
                    if (f_0cfdc0(p3)) d_1bd918 = 1;
                } else f_09c890(d_1c2d1c, 0x16, 0, 1, p3);
            }
        }
    }
    if (!d_1bd928) {
        wait = 0;
        u = f_06ed80(p1, p2, p1 + 0x45);
        *(int *)(p1 + 0x289) = u;
        if (!p4) *(int *)(p1 + 0x28d) = f_06f850(p1, p3, p1 + 0x45, f_043490(p2));
        else if (d_1bd918) wait = 1;
        else *(int *)(p1 + 0x28d) = u;
        *(char *)(p1 + 0x292) = 0;
        for (;;) {
            f_069460();
            if (wait) {
                if (f_069be0(*(int *)(p1 + 0x289)) == 1) {
                    wait = 0;
                    *(int *)(p1 + 0x28d) = f_06d4a0(p1, p3, p1 + 0x45);
                }
            }
            f.s14 = (f.s14 & 0) ? (short)0 : f.s14; // haelt die Referenzgewichtung von f.s14 wie im Original
            if (*(char *)(p1 + 0x292)) break;
            if (f_069be0(*(int *)(p1 + 0x289)) != 0) {
                { int extraC = d_1c0004; d_1c0004 = extraC; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
                if (f_069be0(*(int *)(p1 + 0x28d)) != 0) break;
            }
        }
        f_06ed10(p1, p2, p1 + 0x45);
        f_06f5c0(p1, p3, p1 + 0x45);
        f_0757f0(p1);
        f_07bd30(p1, p2, 0);
    } else f_069460();
    extraA = d_1bd918; d_1bd918 = extraA; // haelt extraA am Funktionsende fuer die Symboltabelle aktiv
}

//@ f_088510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Fernkampfangriff eines Helden (p2) gegen ein Monster (p3) aus: Sie prüft die
 *   Munition (f_086a00), berechnet Treffer und Schaden über f_030080, zieht die Schadenspunkte beim Monster ab
 *   (f_0d0960), spielt die Schuss-, Treffer- und ggf. Sterbeanimation (f_06bdd0, f_06f850, f_06d4a0) ab und
 *   zieht schließlich das verschossene Projektil ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den schießenden Helden p2 sowie den
 *   anvisierten Monsterzeiger p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bd918 hält fest, ob das Monster durch den Treffer getötet wurde
 *   (f_0cfdc0(p3)).
 === Ende Beschreibung === */
void f_088510(int p1, int p2, int p3)
{
    short s;
    if (f_030d80(p2) != -1) {
        if (f_086a00(p1, p2, 1)) {
            s = f_030080(p2, p3, 0);
            if (s > 0) {
                f_09c800(d_1c2d1c, 8, s, 2, p2, 1, p3);
                f_0d0960(p3, s, 0);
                if (f_0cfdc0(p3)) d_1bd918 = 1;
            } else f_09c890(d_1c2d1c, 0x16, 0, 1, p3);
            if (!d_1bd928) {
                *(int *)(p1 + 0x289) = f_06bdd0(p1, p2, p1 + 0x45);
                *(char *)(p1 + 0x292) = 0;
                do {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
                *(char *)(p1 + 0x292) = 0;
                if (f_0d06c0(p3) != 0) {
                    *(int *)(p1 + 0x289) = f_06f850(p1, p3, p1 + 0x45, f_043490(p2));
                    do {
                        f_069460();
                        if (*(char *)(p1 + 0x292)) break;
                    } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
                }
                if (d_1bd918) {
                    *(char *)(p1 + 0x292) = 0;
                    *(int *)(p1 + 0x289) = f_06d4a0(p1, p3, p1 + 0x45);
                    do {
                        f_069460();
                        if (*(char *)(p1 + 0x292)) break;
                    } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
                }
                f_086a00(p1, p2, 0);
                f_06ed10(p1, p2, p1 + 0x45);
                f_0757f0(p1);
                f_07bd30(p1, p2, 0);
            } else {
                f_069460();
                f_086a00(p1, p2, 0);
            }
        }
    }
}

//@ f_0886c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Zauberspruch eines Helden (p2) gegen ein Monster (p3) aus: Sie wertet die
 *   Zauberprobe und Spruchwirkung über f_03d4b0 aus, dreht den Zaubernden in Richtung des Ziels (f_06e9e0),
 *   spielt Sprachausgabe, Zauberanimation (f_06c380), Soundeffekt und Zielanimation am Monster (f_06df80, mit
 *   Blitzeffekt f_07b2d0 bei *Fulminictus*) ab und zeigt die Ergebnismeldung an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den zaubernden Helden p2 sowie den
 *   Monsterzeiger p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Puffer d_1c21b4 enthält den von f_03d4b0 erzeugten Kampfmeldungstext, der nach
 *   *(char )(p1 + 0xc) kopiert und am Ende ausgegeben wird.
 === Ende Beschreibung === */
void f_0886c0(int p1, int p2, int p3)
{
    struct RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    short k;
    d_1c0424 = 1;
    k = f_0433d0(p2);
    f_03d4b0(p2, 0, 0);
    if (d_1c040e == 0) f_043430(p2, -5);
    strcpy(*(char **)(p1 + 0xc), d_1c21b4);
    if (((char)(f_042750((struct hero *)(p2)))) && !d_1bd928) {
        o.tables.p[1] = p2;
        int n = f_0433d0(p2);
        n += 0x20000097;
        *(int *)(*(int *)(o.tables.c + 8) + 4) = n;
        f_07b220(0x1010031);
    }
    if (!d_1bd928) {
    if (d_1c040e == 0) {
        short c, s3;
        short w4 = 0;
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
            *(int *)(p1 + 0x289) = f_06df80(p1, p3, p1 + 0x45, k, 2);
            *(char *)(p1 + 0x292) = 0;
            if (k == 0x31) f_07b2d0();
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            f_06f5c0(p1, p3, p1 + 0x45);
        }
        f_06ed10(p1, p2, p1 + 0x45);
        f_0757f0(p1);
    }
    if (f_0773b0(d_1c0004) != 0) f_07b220(f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
    else f_0bf730(d_1c2c64, f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
    f_07bd30(p1, p2, 0);
    } else f_069460();
}
