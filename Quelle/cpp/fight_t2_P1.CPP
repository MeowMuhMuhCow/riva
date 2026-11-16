/* === Beschreibung (Katalog) ===
 * Einheit fight_t2 (088a50 - 08a020)
 *
 * Überblick
 * Die Einheit fight_t2 implementiert die Ausführung der Kampfaktionen eines Monsters (f_0892a0) sowie die
 * Kampfabläufe Monster gegen Monster (Nahkampf f_088a50, Fernkampf f_088f20, Zauber f_0890a0) und den
 * Nahkampfangriff eines Monsters gegen einen Helden (f_089990).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 4/5 gleich (suche.py 28.10.2026, Basis fight_t2_P1.CPP)
// P2h 1/5 gleich
// fight_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x088A50-0x08A020
#include <string.h>
int f_030810(int p1);
int f_030890(int p1);
signed char f_030960(int p1);
int f_030e20(int p1, int p2);





signed char f_0433d0(int p1);
signed char f_043450(int p1);
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
void f_089990(int p1, int p2, int p3);
void f_08a020(int p1, int p2, int p3);
void f_08a160(int p1, int p2, int p3);
void f_088a50(int p1, int p2, int p3, short p4);
void f_088f20(int p1, int p2, int p3);
void f_0890a0(int p1, int p2, int p3);

//@ f_088a50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Nahkampfangriff eines Monsters (p2) gegen ein anderes Monster (p3, z. B. wenn
 *   eines der beiden verzaubert ist) durch: Sie würfelt Attacke, Parade sowie kritische Treffer und Patzer aus,
 *   berechnet den Schaden über f_0d0bb0, zieht die Lebenspunkte ab (f_0d0960) und spielt die Angriffs-, Parade-
 *   und ggf. Sterbeanimationen (f_06f690, f_06f850, f_06d4a0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das angreifende Monster p2, das
 *   verteidigende Monster p3 sowie das Flankenflag p4 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durch eine falsch verschachtelte Klammerung beim Attacke-Patzer (s5 = f_145760(2, 0xc))
 *   ist der Zweig s5 >= 9 && s5 <= 11 (Selbstverletzung des Angreifers) unerreichbar (siehe Fehlerliste).
 === Ende Beschreibung === */
void f_088a50(int p1, int p2, int p3, short p4)
{
    short s5 = 0;
    short flag = 0;
    short s6;
    int wait;
    short c2;
    short c3, r;
    int u;
    if (d_1bd928) f_069460();
    c2 = f_0d11e0(p3);
    c3 = f_0d1250(p3);
    s5 = f_0d11e0(p2);
    if (f_0d01a0(f_0d0910(p2)) == 1) s5 += 2;
    if (d_1bd928) s5 += 2;
    s6 = f_1457e0(0x14);
    if (s6 == 0x14 && f_1457e0(0x14) > s5 - 9) {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x49), s5, 0, s6, -1);
#endif
        f_09c890(d_1c2d1c, 3, 0, 1, p2);
        s5 = f_145760(2, 0xc);
        if (s5 >= 3 && s5 <= 8) {
            *(char *)(p1 + 0x1ef) = 1;
            if (f_1457e0(0x14) <= c2) {
                r = f_0d0bb0(p3, p2, 1);
                if (r > 0) {
                    f_09c800(d_1c2d1c, 0x17, r, 1, p3, 1, p2);
                    f_0d0960(p2, r, 2);
                    if (f_0cfdc0(p2)) *(char *)(p1 + 0x1f0) = 1;
                }
            } else if (s5 >= 9 && s5 <= 11) {
                s5 = f_1457e0(6);
                f_09c890(d_1c2d1c, 0xf, s5, 1, p2);
                f_0d0960(p2, s5, 2);
                if (f_0cfdc0(p2)) *(char *)(p1 + 0x1f0) = 1;
            }
        }
    } else {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x49), s5, 0, s6, (s6 <= s5) ? 1 : 0);
#endif
        if (s6 > s5) {
            f_09c910(d_1c2d1c, 5, 0);
        } else {
            if (!f_0d01a0(f_0d0910(p2))) {
                s6 = f_1457e0(0x14);
                if (s6 == 0x14 && f_1457e0(0x14) > c3 - 7) {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x49), c3, 0, s6, -1);
#endif
                    flag = 1;
                    f_09c890(d_1c2d1c, 4, 0, 1, p3);
                    s6 = f_145760(2, 0xc);
                    if (s6 >= 3 && s6 <= 8) {
                        *(char *)(p1 + 0x1ee) = 1;
                        if (f_1457e0(0x14) <= s5) {
                            r = f_0d0bb0(p2, p3, 1);
                            if (r > 0) {
                                f_09c800(d_1c2d1c, 0x17, r, 1, p2, 1, p3);
                                f_0d0960(p3, r, 1);
                                if (f_0cfdc0(p3)) d_1bd918 = 1;
                            }
                        }
                    } else if (s6 >= 9 && s6 <= 11) {
                        s5 = f_1457e0(6);
                        f_09c890(d_1c2d1c, 0x10, s5, 1, p3);
                        f_0d0960(p3, s5, 1);
                        if (f_0cfdc0(p3)) d_1bd918 = 1;
                    }
                } else {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x49), c3, 0, s6, (s6 <= c3) ? 1 : 0);
#endif
                    if (s6 > c3) flag = 1;
                    else f_09c890(d_1c2d1c, 0xc, 0, 1, p3);
                }
            } else flag = 1;
            if (flag) {
                r = f_0d0bb0(p2, p3, 1);
                if (r > 0) {
                    f_09c800(d_1c2d1c, 0x17, r, 1, p2, 1, p3);
                    f_0d0960(p3, r, 1);
                    if (f_0cfdc0(p3)) d_1bd918 = 1;
                } else f_09c890(d_1c2d1c, 0x16, 0, 1, p3);
            }
        }
    }
    if (!d_1bd928) {
        wait = 0;
        u = f_06f690(p1, p2, p1 + 0x45);
        *(int *)(p1 + 0x289) = u;
        if (!p4) *(int *)(p1 + 0x28d) = f_06f850(p1, p3, p1 + 0x45, f_072440(p1, p2));
        else if (d_1bd918) wait = 1;
        else *(int *)(p1 + 0x28d) = u;
        *(char *)(p1 + 0x292) = 0;
        for (;;) {
            f_069460();
            if (wait) {
                if (f_069be0(*(int *)(p1 + 0x289)) == 1) {
                    u = f_06d4a0(p1, p3, p1 + 0x45);
                    wait = 0;
                    *(int *)(p1 + 0x28d) = u;
                }
            }
            if (*(char *)(p1 + 0x292)) break;
            if (f_069be0(*(int *)(p1 + 0x289)) != 0 && f_069be0(*(int *)(p1 + 0x28d)) != 0) break;
        }
        f_06f5c0(p1, p2, p1 + 0x45);
        f_06f5c0(p1, p3, p1 + 0x45);
        f_0757f0(p1);
    } else f_069460();
}

//@ f_088f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Fernkampfangriff eines Monsters (p2) gegen ein anderes Monster (p3) aus: Sie
 *   reduziert den Geschossvorrat des Schützen (f_0d00f0 bzw. f_0d0130), würfelt den Trefferschaden abzüglich
 *   Rüstungsschutz (f_0bd360 - f_0cf950) aus, zieht den Schaden über f_0d0960 ab und spielt die Schuss- und ggf.
 *   Sterbeanimation (f_06d580, f_06d4a0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das schießende Monster p2 sowie das
 *   Zielmonster p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0d00e0 und f_0d0120 werden die verbleibenden Schuss- bzw. Wurfgeschosse des
 *   Monsters abgefragt.
 === Ende Beschreibung === */
void f_088f20(int p1, int p2, int p3)
{
    short kind, v, d;
    if (f_0d00e0(p2) > 0) {
        kind = 4;
        f_0d00f0(p2, f_0d00e0(p2) - 1);
    } else {
        kind = 5;
        f_0d0130(p2, f_0d0120(p2) - 1);
    }
    if (kind == 4) v = f_0d0100(p2); else v = f_0d0140(p2);
    d = f_0bd360(v) - f_0cf950(p3);
    if (d > 0) {
        f_09c800(d_1c2d1c, 0x17, d, 1, p2, 1, p3);
        f_0d0960(p3, d, 1);
        if (f_0cfdc0(p3)) d_1bd918 = 1;
    } else f_09c890(d_1c2d1c, 0x16, 0, 1, p3);
    if (!d_1bd928) {
        *(int *)(p1 + 0x289) = f_06d580(p1, p2, p1 + 0x45);
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
        f_06f5c0(p1, p2, p1 + 0x45);
        f_0757f0(p1);
    } else f_069460();
}

//@ f_0890a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Monsterzauber eines Monsters (p2) gegen ein anderes Monster (p3) aus: Sie
 *   berechnet die Zauberwirkung über f_0d10c0, spielt die Zauberanimation des Monsters (f_06daa0), den
 *   zugehörigen Soundeffekt aus d_1a57f0 sowie die Trefferanimation am Zielmonster (f_06df80, mit Blitzeffekt
 *   f_07b2d0 bei Spruch 7) ab und gibt die Kampfmeldung aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das zaubernde Monster p2 sowie das
 *   Zielmonster p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle d_1a57f0 (Eintragsgröße 12 Bytes) liefert die Sound-Ressourcenkennung zum
 *   jeweiligen Monsterzauber k.
 === Ende Beschreibung === */
void f_0890a0(int p1, int p2, int p3)
{
    short k;
    int r;
    d_1c21b4[0] = 0;
    k = f_0cfd00(p2);
    d_1c0424 = 1;
    f_0d10c0(p2, 0);
    strcpy(*(char **)(p1 + 0xc), d_1c21b4);
    if (!d_1bd928) {
        if (!d_1c040e) {
            r = f_06daa0(p1, p2, p1 + 0x45);
            *(char *)(p1 + 0x292) = 0;
            *(int *)(p1 + 0x289) = r;
            do {
                f_069460();
                if (*(char *)(p1 + 0x292)) break;
            } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            int sound;
            if ((sound = ((RivaFileManager*)(((char*)&d_1c2098)))->f_144870( *(int *)(d_1a57f0 + k * 12))) != 0) {
                int s = d_1a9820;
                f_147323(d_1c2edc, *(int *)(d_1a57f0 + k * 12), 0x7fff, 0x8000, s, 0, 1);
            } else {
                int s;
                f_147323(d_1c2edc, 0xc002d, 0x7fff, 0x8000, (s = d_1a9820), sound, 1);
            }
            if (d_1c0412) {
                r = f_06df80(p1, p3, p1 + 0x45, k, 1);
                *(char *)(p1 + 0x292) = 0;
                *(int *)(p1 + 0x289) = r;
                if (k == 7) f_07b2d0();
                do {
                    f_069460();
                    if (*(char *)(p1 + 0x292)) break;
                } while (f_069be0(*(int *)(p1 + 0x289)) == 0);
            }
            {
                int b = p1 + 0x45;
                f_06f5c0(p1, p2, b);
                f_06f5c0(p1, p3, b);
            }
            f_0757f0(p1);
        }
        if (f_0773b0(d_1c0004)) {
            f_07b220(f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
        } else {
            f_0bf730(d_1c2c64, f_133fe0(d_1c3498, *(int *)(p1 + 0xc)));
        }
    } else f_069460();
}
//@ f_0892a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentrale Ausführungsfunktion für die Kampfaktion eines Monsters (p2): Sie richtet Angreifer
 *   und Ziel (Held obj oder Monster m, einschließlich Drehung zweifeldriger Großmonster) zueinander aus, blendet
 *   die Zielmarkierung unter dem Opfer ein und verzweigt je nach gewähltem Aktionscode (f_0cfce0(p2): 2 =
 *   Nahkampf, 0x10 = Fernkampf, 4 = Zauber) in die passende Kampfabwicklungsfunktion für Helden- oder
 *   Monsterziele.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den handelnden Monsterzeiger p2 und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag isobj gibt an, ob das Ziel ein Held (1) oder ein Monster (0) ist, und flag
 *   vermerkt, ob sich ein zweifeldriges Zielmonster wegen blockierter Nachbarkacheln nicht zum Angreifer drehen
 *   konnte.
 === Ende Beschreibung === */
void f_0892a0(int p1, int p2)
{
    int m;
    short ya;
    char *pv;
    int ob;
    short xa;
    short ya2;
    int obj;
    short t;
    short s;
    short dx2;
    short xa2;
    short flag = 0;
    short sx;
    short sy;
    short dy;
    signed char isobj;
    if (!d_1bd90c) return;
    if (d_1bd928) f_069460();
    f_09c780(d_1c2d1c);
    *(char *)(p1 + 0x1ee) = *(char *)(p1 + 0x1ef) = *(char *)(p1 + 0x1f0) = d_1bd918 = 0;
    if (f_0cfd40(p2) == 2) {
        obj = f_0d08a0(p2);
        if (((char)(f_042470((struct hero *)(obj)))) || !((char)(f_042350((struct hero *)(obj))))) return;
        if (d_1bd928 && !f_043450(obj)) {
            f_0434a0(obj, (signed char)f_072110(p1, p2));
        }
        isobj = 1;
    } else {
        m = f_0d0910(p2);
        if (f_0cfdc0(m) || !f_0cf910(m)) return;
        isobj = 0;
        if (f_072910(m) != 0 && !flag && !f_0d01a0(m) && f_0cfce0(p2) == 2) {
            f_071e90((unsigned char)(f_0729c0(m) + 10), &xa, &ya);
            s = f_072110(p1, p2);
            if (f_0cfc70(m) != s) {
                sx = xa + *(short *)(d_1a2734 + s * 4);
                sy = ya + *(short *)(d_1a2736 + s * 4);
                t = *((unsigned char *)((int)sx + (int)(d_1bd984 + sy * 0x19)));
                if (t >= (short)0x32
                    || (t < (short)10 && t >= (short)1 && !((char)(f_042470((struct hero *)(d_1bc8f0 + (t - 1) * 0x5ef)))))
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
        if (!flag && !f_0d01a0(m) && f_0cfce0(p2) == 2 && d_1bd928) {
            f_0cfc80(m, (signed char)f_072110(p1, p2));
        }
    }
    s = f_072440(p1, p2);
    if (f_072910(p2) != 0) {
        if (s != f_0cfc70(p2)) {
            f_071e90((unsigned char)(f_0729c0(p2) + 10), &xa2, &ya2);
            sx = xa2 + *(short *)(d_1a2734 + s * 4);
            sy = ya2 + *(short *)(d_1a2736 + s * 4);
            t = *(d_1bd984 + sy * 0x19 + sx);
            dx2 = xa2 + *(short *)(d_1a2734 + f_0cfc70(p2) * 4);
            dy = ya2 + *(short *)(d_1a2736 + f_0cfc70(p2) * 4);
            ob = f_07ea60(p1 + 0x39, (unsigned char)f_0cfc50(p2));
            pv = (char *)f_07eb00(p1 + 0x39, (unsigned char)(*(char *)(ob + 0xd) + 0x14));
            f_071e50(p1, dx2, dy, (unsigned char)pv[0xe]);
            f_071e50(p1, sx, sy, (unsigned char)(f_0729c0(p2) + 0x1e));
            pv[0xe] = t;
            pv[0] = sx;
            pv[1] = sy;
            pv[0x20] = 1;
            *(char *)(ob + 0x20) = 1;
            f_07e930(p1 + 0x39);
        }
    }
    if (d_1bd928) f_0cfc80(p2, (signed char)s);
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
        f_0757f0(p1);
        *(int *)(p1 + 0x20d) = 0;
        *(int *)(p1 + 0x209) = 0;
    }
    if (f_0cfce0(p2) == 2) {
        if (isobj) f_089990(p1, p2, obj); else f_088a50(p1, p2, m, flag);
    } else if (f_0cfce0(p2) == 0x10) {
        if (isobj) f_08a020(p1, p2, obj); else f_088f20(p1, p2, m);
    } else if (f_0cfce0(p2) == 4) {
        if (isobj) f_08a160(p1, p2, obj); else f_0890a0(p1, p2, m);
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

//@ f_089990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen Nahkampfangriff eines Monsters (p2) gegen einen Helden (p3) aus: Sie ermittelt
 *   Attacke- und Paradewerte (unter Berücksichtigung von Schutzzaubern wie *Duplicatus* f_043dc0 oder
 *   *Chamaelioni* f_042560), würfelt Attacke, Parade, kritische Treffer und Patzer (einschließlich Waffenbruch
 *   des Helden, Passierschlag und Selbstverletzung) aus, zieht den Schaden ab (f_044300 bzw. f_0d0960), prüft
 *   auf Krankheits-/Giftübertragung (f_0d00c0, f_040a00) und spielt die Kampfanimationen ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, das angreifende Monster p2 sowie den
 *   verteidigenden Helden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei hohem Rundenzähler (*(short *)(p1 + 0x1ec) > 20) erhöht die Funktion die W20-Würfe
 *   auf bis zu 20, um extrem lange Kämpfe durch häufigere Patzer schneller zu entscheiden.
 === Ende Beschreibung === */
void f_089990(int p1, int p2, int p3)
{
    short s3;
    short s24, s20;
    short flag = 0;
    short s14;
    short s4;
    short r;
    short t;
    if (d_1bd928) f_069460();
    if (f_035110(p3) == -1) {
        s14 = f_0456e0(p3, 0);
        s3 = f_045710(p3, 0);
    } else {
        s14 = f_045610(p3);
        s3 = f_045660(p3);
    }
    if (f_042810((struct hero *)(p3)) == 3) s3 += 3;
    if (f_0de4d0(d_1c0004) == (short)-5) { s14 -= 4; s3 -= 4; }
    s4 = f_0d11e0(p2);
    if (f_043450(f_0d08a0(p2)) == 1) s4 += 2;
    if (((signed char)(f_042560((struct hero *)(p3)))) == 1) s4 -= 5;
    if (f_043dc0(p3) == 1) s4 /= (short)2;
    if (f_043dc0(p3) == 2) s4 /= (short)3;
    if (d_1bd928) s4 += 2;
    s24 = f_1457e0(0x14);
    if (*(short *)(p1 + 0x1ec) > 0x14) {
        s24 += 5;
        if (s24 > 0x14) s24 = 0x14;
    }
    if (s24 == 0x14 && f_1457e0(0x14) > s4 - 9) {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x49), s4, 0, s24, -1);
#endif
        if (f_0d49b0(p3) != 0) {
            f_09c890(d_1c2d1c, 3, 0, 1, p2);
            t = f_145760(2, 0xb);
            if (*(short *)(p1 + 0x1ec) > 0x14) {
                t += *(short *)(p1 + 0x1ec) / 2;
                if (t > 0xb) t = 0xb;
            }
            if (t >= 3 && t <= 8) {
                *(char *)(p1 + 0x1ef) = 1;
                if (f_1457e0(0x14) <= s14) {
                    r = f_030080(p3, p2, 0);
                    if (r > 0) {
                        f_09c800(d_1c2d1c, 8, r, 2, p3, 1, p2);
                        f_0d0960(p2, r, 2);
                        if (f_0cfdc0(p2)) *(char *)(p1 + 0x1f0) = 1;
                    }
                }
            } else if (t >= 9) {
                r = f_1457e0(6);
                f_09c890(d_1c2d1c, 0xf, r, 1, p2);
                f_0d0960(p2, r, 2);
                if (f_0cfdc0(p2)) *(char *)(p1 + 0x1f0) = 1;
            }
        }
    } else {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x49), s4, 0, s24, (s24 <= s4) ? 1 : 0);
#endif
        if (s24 > s4) {
            f_09c910(d_1c2d1c, 5, 0);
        } else {
            if (!f_043450(f_0d08a0(p2)) && f_0d49b0(p3) != 0) {
                s20 = f_1457e0(0x14);
                if (*(short *)(p1 + 0x1ec) > 0x14) {
                    s20 += *(short *)(p1 + 0x1ec) / 2;
                    if (s20 > 0x14) s20 = 0x14;
                }
                if (s20 == 0x14 && f_1457e0(0x14) > s3 - 7) {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x22), s3, 0, s20, -1);
#endif
                    flag = 1;
                    f_09c890(d_1c2d1c, 2, 0, 2, p3);
                    t = f_145760(2, 0xc);
                    if (t >= 3 && t <= 8) {
                        *(char *)(p1 + 0x1ee) = 1;
                        if (f_1457e0(0x14) <= s4) {
                            r = f_0d0bb0(p2, p3, 0);
                            if (r > 0) {
                                f_09c800(d_1c2d1c, 0xb, r, 1, p2, 2, p3);
                                f_044300(p3, r);
                                if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                                else if (f_0d00c0(p2)) f_040a00(p3, 7, 1);
                            }
                        }
                    } else if (t >= 9 && t <= 11) {
                        r = f_1457e0(6);
                        f_09c890(d_1c2d1c, 0xe, r, 2, p3);
                        f_044300(p3, r);
                        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                    }
                } else {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x22), s3, 0, s20, (s20 <= s3) ? 1 : 0);
#endif
                    if (s3 < s20) flag = 1;
                    else {
                        f_09c890(d_1c2d1c, 9, 0, 2, p3);
                        if (s20 == s24) {
                            if (f_042d00((struct hero *)(p3), 3) != 0) {
                                if (f_042be0((struct hero *)(p3), 3) > 3) {
                                    if (f_1457e0(0xc) + f_042be0((struct hero *)(p3), 3) > 0x14) {
                                        if (f_033c50(p3, 3, 1) != 0) f_09c890(d_1c2d1c, 6, 0, 2, p3);
                                    } else f_042ca0((struct hero *)(p3), 3);
                                } else f_042ca0((struct hero *)(p3), 3);
                            }
                        }
                    }
                }
            } else flag = 1;
            if (flag) {
                r = f_0d0bb0(p2, p3, 0);
                if (r > 0) {
                    f_09c800(d_1c2d1c, 0xb, r, 1, p2, 2, p3);
                    f_044300(p3, r);
                    if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                    else if (f_0d00c0(p2)) f_040a00(p3, 7, 1);
                } else f_09c890(d_1c2d1c, 0x15, 0, 2, p3);
            }
        }
    }
    if (!d_1bd928) {
        *(int *)(p1 + 0x289) = f_06f690(p1, p2, p1 + 0x45);
        *(int *)(p1 + 0x28d) = f_06efc0(p1, p3, p1 + 0x45, f_072440(p1, p2));
        *(char *)(p1 + 0x292) = 0;
        for (;;) {
            f_069460();
            if (*(char *)(p1 + 0x292)) break;
            if (f_069be0(*(int *)(p1 + 0x289)) != 0 && f_069be0(*(int *)(p1 + 0x28d)) != 0) break;
        }
        f_06f5c0(p1, p2, p1 + 0x45);
        f_06ed10(p1, p3, p1 + 0x45);
        f_0757f0(p1);
        f_07bd30(p1, p3, 0);
    } else f_069460();
}
