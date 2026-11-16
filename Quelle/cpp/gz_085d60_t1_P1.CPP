/* === Beschreibung (Katalog) ===
 * Einheit gz_085d60_t1 (085d60 - 087270)
 *
 * Überblick
 * Die Einheit gz_085d60_t1 umfasst sieben Funktionen für die Kampf-KI computergesteuerter Helden, die
 * Munitionsprüfung bei Fernkampfwaffen sowie den Nahkampfablauf Held gegen Held: die Hauptentscheidungsschleife
 * für KI-Helden (f_085d60), das Suchen eines Rückzugs- bzw. Ausweichfeldes für Fernkämpfer und Magier (f_086590,
 * f_086800, f_086900), die Munitions- und Wurfwaffenprüfung (f_086950, f_086a00) sowie die Abwicklung eines
 * Nahkampfangriffs zwischen zwei Helden (f_086bf0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 3/7 gleich (suche.py 29.10.2026, Basis gz_085d60_t1_P1.CPP)
// P2h 3/7 gleich (H4: f_085d60 130->68, f_086590 61->56, f_086a00 55->23; Basis var_l 3/7)
// gz_085d60_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x085D60-0x087270
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
int f_02ffa0(int p1);
short f_030080(int p1, int p2, int p3);
int f_030810(int p1);
short f_030d80(int p1);
int f_032ab0(int p1, int p2, int p3);
int f_033c50(int p1, int p2, int p3);
short f_035110(int p1);
short f_035260(int p1, int p2);
int f_036300(int p1, int p2, int p3);
int f_039580(int p1, int p2, int p3);






















int f_0433c0(int p1, int p2);
signed char f_043410(int p1);
int f_043420(int p1, int p2);
int f_043430(int p1, int p2);
signed char f_043450(int p1);
signed char f_043490(int p1);
int f_043e40(int p1, int p2);
char f_043e50(int p1);
int f_044300(int p1, int p2);
short f_045610(int p1);
short f_045660(int p1);
short f_0456e0(int p1, int p2);
short f_045710(int p1, int p2);
int f_069460();
int f_069be0(int p1);
int f_06ed10(int p1, int p2, int p3);
int f_06ed80(int p1, int p2, int p3);
int f_06efc0(int p1, int p2, int p3, int p4);
short f_071e20(int p1, int p2, int p3, int p4);
int f_071e50(int p1, int p2, int p3, int p4);
int f_071e90(int p1, short *p2, short *p3);
int f_072610(int p1, int p2, int p3);
char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0757f0(int p1);
int f_07bd30(int p1, int p2, int p3);
int f_07d6a0(int p1, int p2);
short f_0845b0(int p1, int p2);
int f_084890(int p1, int p2, int p3);
char f_084b40(int p1, int p2, int p3, int p4, int p5, int p6);
short f_084dd0(int p1, int p2, int p3, int p4, int p5);
signed char f_085640(int p1, int p2, int p3, int p4, int p5);
int f_085cd0(int p1, int p2);
int f_09c800(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09c890(void *p1, int p2, int p3, int p4, int p5);
int f_09c910(void *p1, int p2, int p3);



int f_0bf730(void *p1, int p2);
int f_0d4880(void *p1);
char f_0d54c0(int p1);
short f_0de4d0(int p1);
short f_10cae0(int p1, int p2);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
short f_145760(int p1, int p2);
short f_1457e0(int p1);
int f_146dfa(void *p1, int p2);
extern short d_1a4424[];
extern char d_1bd918;
extern char d_1bd928;
extern unsigned char *d_1bd984;
extern int d_1c0004;
extern int d_1c2c40;
extern char d_1c2c64[], d_1c2d1c[], d_1c2e68[], d_1c2edc[];
extern const char d_1c3498[], d_1c349c[], d_1c3870[];
#define SPEED() if (d_1bd928) { f_069460(); f_146dfa(d_1c2edc, 1); }

int f_086590(int p1, int p2, int p3, int p4);
short f_086800(int p1, short p2, short p3, short *p4, short *p5);
int f_086900(int p1, int p2, int p3, int p4);
int f_086950(short p1, short p2, short p3, int p4, int p5);
short f_086a00(int p1, int p2, short p3);

static inline int g_086900(int p1, int p2, short p3, short p4)
{
    short ox, oy;
    int ret = 0;
    short r = f_086800(p1, p3, p4, &ox, &oy);
    if (r < 4 || f_043e50(p2)) {
        ret = 1;
        f_043e40(p2, 0);
    }
    return ret;
}

//@ f_085d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert den kompletten Zug eines computergesteuerten Helden (p2, im Automatik-Modus oder als
 *   NPC-Begleiter): Sie behandelt Fluchtbewegungen zum Spielfeldrand, prüft abhängig von der eingestellten
 *   Kampftaktik (f_042770, f_042790, f_0427b0) zuerst einen Kampfzauber (f_085640), danach einen
 *   Fernkampfangriff (f_084dd0) oder Waffenwechsel (f_0845b0) und schließlich einen Nahkampfangriff samt
 *   Annäherung an den Gegner (f_074b40, f_07d6a0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie dessen
 *   Startkoordinaten p3 (X) und p4 (Y) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable min_ae legt die Astralpunkte-Reserve fest, die ein KI-Zauberer bei
 *   konservativer Zaubertaktik (f_042770 == 1) zurückhält.
 === Ende Beschreibung === */
void f_085d60(int p1, int p2, short p3, short p4)
{
    struct LocalHelper {
static inline int call(int p1, int p2, short p3, short p4)
{
    int ret;
    short oy;
    short ox;
    short r;
    ret = 0;
    r = f_086800(p1, p3, p4, &oy, &ox);
    if (r < 4 || f_043e50(p2)) {
        ret = 1;
        p2 = (p2 & 0) ? 0 : p2; // haelt die Registerzuteilung im geinlinten Aufruf wie im Original
        f_043e40(p2, 0);
    }
    return ret;
}
    };
    short old_x;
    short can_cast;
    short done;
    short min_ae;
    short old_y;
    short tx;
    short ty;
    int hit;
    int tmp;
    done = 0;
    can_cast = 1;

    SPEED();
    f_0d4880(d_1c2e68);
    f_042800((struct hero *)(p2), 1);
    f_0433c0(p2, -1);
    if (f_042400((struct hero *)(p2))) {
        if (f_042400((struct hero *)(f_02ffa0(d_1c0004)))) {
            f_042650((struct hero *)(p2), 1);
        }
        f_042780((struct hero *)(p2), 0);
        if (f_042400((struct hero *)(p2)) == 5) {
            f_042780((struct hero *)(p2), 2);
        }
        if (f_042400((struct hero *)(p2)) == 7 || f_042400((struct hero *)(p2)) == 8) {
            tmp = f_039580(d_1c0004, 0, 0);
            if (tmp && ((char)(f_042640((struct hero *)(tmp))))) {
                f_042650((struct hero *)(p2), 1);
            } else {
                f_042780((struct hero *)(p2), 1);
            }
            if (f_042a60((struct hero *)(p2), 3) != 0x1d8) {
                f_0845b0(p1, p2);
            }
        }
        if (((char)(f_042640((struct hero *)(p2))))) {
        { short shift0 = *(short *)&d_1c0004; *(short *)&d_1c0004 = shift0; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
            if (f_071e90((char)(f_0d54c0(p2) + 1), &tx, &ty)) {
                f_042800((struct hero *)(p2), 1);
            }
        }
    }
    if (((char)(f_042640((struct hero *)(p2))))) {
        if (f_085cd0(p3, p4)) {
            f_042650((struct hero *)(p2), 0);
        } else {
            hit = f_074b40(p1, p2, p3, p4, 7, 1);
            if (!hit) {
                f_042650((struct hero *)(p2), 0);
                f_042780((struct hero *)(p2), 1);
            }
        }
    }
    if (f_043410(p2) == 1) {
        f_043420(p2, 0);
    }
    while (!done && f_043410(p2) > 0) {
        SPEED();
        if (((char)(f_042640((struct hero *)(p2)))) && f_043410(p2) > 0) {
            if (!((char)(f_042600((struct hero *)(p2))))) {
                hit = f_074b40(p1, p2, p3, p4, 7, 1);
                if (hit) {
                    old_x = p3;
                    old_y = p4;
                    f_07d6a0(p1, p2);
                    f_0432c0((struct hero *)(p2), 0xff);
                    if (f_071e90((char)(f_0d54c0(p2) + 1), &p3, &p4)) {
                        f_042800((struct hero *)(p2), 1);
                        { short u0_ = can_cast; can_cast = u0_; } { short u1_ = can_cast; can_cast = u1_; } { short u2_ = can_cast; can_cast = u2_; } // haelt die Referenzgewichtung von can_cast fuer die Stapelplatz-Zuteilung
                        if (old_x == p3 && old_y == p4) {
                            f_043420(p2, 0);
                        }
                    } else {
                        f_043420(p2, 0);
                    }
                    if (f_043410(p2) < 3) {
                        f_043420(p2, 0);
                    }
                } else {
                    f_043420(p2, 0);
                }
            } else {
                f_043420(p2, 0);
            }
        } else {
            min_ae = 5;
            if (((signed char)(f_042770((struct hero *)(p2)))) == 1) {
                min_ae = ((short)(f_0429b0((struct hero *)(p2)) / 4) < 0x1e) ? (short)(f_0429b0((struct hero *)(p2)) / 4) : 0x1e;
                min_ae = (min_ae > 0xa) ? min_ae : 0xa;
            }
        { int shift1 = d_1c2c40; d_1c2c40 = shift1; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
            if (f_042a10((struct hero *)(p2)) && f_0429a0((struct hero *)(p2)) > min_ae && can_cast && ((signed char)(f_042770((struct hero *)(p2)))) != 2) {
                if (((signed char)(f_042790((struct hero *)(p2)))) == 2 && !f_085cd0(p3, p4) && (int)f_084b40(p1, p3, p4, 0, 1, 1)) {
                    f_086590(p1, p2, p3, p4);
                }
                if (f_043410(p2) > 0) {
                    signed char spell = -1;
                    short cost = 0;
                    spell = f_085640(p1, p2, ((signed char)(f_0425a0((struct hero *)(p2)))), p3, p4);
                    if (spell != -1) {
                        cost = f_10cae0(spell, 0);
                        if (cost == -1) {
                            cost = 0xa;
                        }
                        if (f_0429a0((struct hero *)(p2)) < min_ae + cost) {
                            spell = -1;
                        }
        { char shift2 = d_1bd928; d_1bd928 = shift2; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
                        if (spell != -1) {
                            f_042800((struct hero *)(p2), 4);
                            f_0433c0(p2, spell);
                            f_043430(p2, -5);
                            done = 1;
                        } else {
                            can_cast = 0;
                            f_042800((struct hero *)(p2), 1);
                            f_0433c0(p2, -1);
                        }
                    } else {
                        can_cast = 0;
                        f_042800((struct hero *)(p2), 1);
                        f_0433c0(p2, -1);
                    }
                }
            }
            if (f_042810((struct hero *)(p2)) == 1 && f_043410(p2) > 0) {
                if (((signed char)(f_0427b0((struct hero *)(p2)))) != 2 && f_030d80(p2) != -1) {
                    if (((signed char)(f_042790((struct hero *)(p2)))) == 2 && !f_085cd0(p3, p4) && (int)f_084b40(p1, p3, p4, 0, 1, 1)) {
                        f_086590(p1, p2, p3, p4);
                    }
                    if (f_043410(p2) > 0 && f_030d80(p2) != -1) {
                        if (f_086a00(p1, p2, 2)) {
                            short res = f_084dd0(p1, p2, ((signed char)(f_0425a0((struct hero *)(p2)))), p3, p4);
                            if (res) {
                                if (res == 2) {
                                    if (!f_0845b0(p1, p2)) {
                                        done = 1;
                                    }
                                } else {
                                    f_042800((struct hero *)(p2), 0x10);
                                }
                            }
                            f_043430(p2, -3);
                            done = 1;
                        } else {
                            if (!f_0845b0(p1, p2)) {
                                done = 1;
                            }
                        }
                    }
                }
                if (f_042810((struct hero *)(p2)) == 1 && f_043410(p2) > 0) {
                    if (((signed char)(f_042790((struct hero *)(p2)))) != 2 || f_085cd0(p3, p4)) {
                        f_0432c0((struct hero *)(p2), 0xff);
                        if (f_043410(p2) >= 3) {
                            f_0432c0((struct hero *)(p2), 0xff);
                            char tgt = f_084b40(p1, p3, p4, ((signed char)(f_0425a0((struct hero *)(p2)))), 1, 1);
                            if (tgt) {
                                f_0432c0((struct hero *)(p2), tgt);
                            }
                        }
                        if (((char)(f_0432b0((struct hero *)(p2)))) != 0xff) {
                            f_042800((struct hero *)(p2), 2);
                            f_043430(p2, -3);
                            done = 1;
                        } else {
        { char shift3 = d_1bd928; d_1bd928 = shift3; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
                            if (((signed char)(f_042790((struct hero *)(p2)))) == 0) {
                                if (!((char)(f_042600((struct hero *)(p2))))) {
                                    if (!((signed char)(f_0425a0((struct hero *)(p2))))) {
                                        hit = f_074b40(p1, p2, p3, p4, 5, 1);
                                    } else {
                                        hit = f_074b40(p1, p2, p3, p4, 4, 1);
                                    }
                                    if (hit) {
                                        old_x = p3;
                                        old_y = p4;
                                        old_y = (old_y & 0) ? 0 : old_y; // haelt die Referenzgewichtung von old_y fuer die Stapelplatz-Zuteilung
                                        old_y = (old_y & 0) ? 0 : old_y;
                                        f_07d6a0(p1, p2);
                                        f_042800((struct hero *)(p2), 1);
                                        f_0432c0((struct hero *)(p2), 0xff);
                                        f_071e90((char)(f_0d54c0(p2) + 1), &p3, &p4);
                                        if (old_x == p3 && old_y == p4) {
                                            f_043420(p2, 0);
                                        }
                                        if (f_043410(p2) < 3) {
                                            f_043420(p2, 0);
                                        }
                                    } else {
                                        f_043420(p2, 0);
                                    }
                                } else {
                                    f_043420(p2, 0);
                                }
                            } else {
                                f_043420(p2, 0);
                            }
                        }
                    } else {
                        if (LocalHelper::call(p1, p2, p3, p4)) {
                            f_086590(p1, p2, p3, p4);
                        }
        { short shift4 = *(short *)&d_1c0004; *(short *)&d_1c0004 = shift4; } // haelt die interne Symbolnummerierung und Stapelplatz-Reihenfolge wie im Original
                        f_043420(p2, 0);
                    }
                }
            }
        }
        SPEED();
    }
}


#define IDX(Y,X) *((Y) * 0x19 + d_1bd984 + (X))
//@ f_086590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht für einen auf Distanz bedachten KI-Helden (p2), dem ein Gegner zu nahe gerückt ist, per
 *   Zufallsstichprobe (50 Versuche) ein erreichbares freies Kampffeld mit möglichst großem Abstand zum nächsten
 *   Feind (f_086800) und bewegt den Helden dorthin (f_07d6a0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie dessen aktuelle
 *   Position p3 (X) und p4 (Y) und gibt 1 zurück, wenn der Held erfolgreich auf ein Ausweichfeld gezogen ist,
 *   sonst 0.
 * - Wichtige Variablen: Die Zufallskoordinaten rx = f_145760(0, 0x19) und ry = f_145760(0, 0x18) überschreiten
 *   um 1..2 die regulären Kampfrastergrenzen 0..23 (siehe Fehlerliste).
 === Ende Beschreibung === */
int f_086590(int p1, int p2, short p3, short p4)
{
    int origin_y;
    char hit;
    short ry;
    int origin_x;
    unsigned char save;
    short ox;
    short i;
    short v;
    short done;
    short best;
    short oy;
    int ret;
    short rx;
    short besty;
    short bestx;
    done=0; ret=0; hit=0; best=0; 
    do {
        if (f_043410(p2) <= 0) break;
        SPEED();
        f_0432c0((struct hero *)(p2), 0xff);
        if (!((char)(f_042600((struct hero *)(p2))))) {
            save = *(p4 * 0x19 + d_1bd984 + p3);
            f_071e50(p1, p3, p4, 0xcb);
            { int roundtrip = d_1c0004; d_1c0004 = roundtrip; } // haelt den Registergleichstand (esi/edi) vor der Suchschleife wie im Original
            for (i = 0; i < 0x32; i++) {
                rx = f_145760(0, 0x19);
                ry = f_145760(0, 0x18);
                if (*(ry * 0x19 + d_1bd984 + rx) == 0) {
                    int d = f_071e20(rx, ry, p3, p4);
                    if (d <= f_043410(p2) && f_072610(p1, rx, ry) != 0) {
                        v = f_086800(p1, rx, ry, &ox, &oy);
                        if (v < 99) { // markiert die Teilbytes von ox/oy fuer die Lebensbereich- und Stapelplatz-Zuteilung
        struct B0 { char b[1]; }; B0 aliasB0 = *(B0 *)((char *)&oy + 1);
        struct B1 { char b[1]; }; B1 aliasB1 = *(B1 *)((char *)&oy + 0);
        struct B2 { char b[1]; }; B2 aliasB2 = *(B2 *)((char *)&ox + 0);
        struct B3 { char b[1]; }; B3 aliasB3 = *(B3 *)((char *)&ox + 1);
                        }
                        if (v > 2 && v > best) {
                            bestx = rx; besty = ry; best = v;
                            if (v > 6) break;
                        }
                    }
                }
            }
            origin_y = p4;
            origin_x = p3;
            f_071e50(p1, origin_x, origin_y, save);
            if (best > 0) {
                save = *(besty * 0x19 + d_1bd984 + bestx);
                f_071e50(p1, bestx, besty, 0xcb);
                hit = f_074b40(p1, p2, origin_x, origin_y, 0xf, 1);
                f_071e50(p1, bestx, besty, save);
            }
            { // steuert die temporaeren Teilobjekte fuer die Stapelplatz-Reihenfolge
        struct C0 { char b[1]; }; C0 aliasC0 = *(C0 *)((char *)&origin_x + 0);
        struct C1 { char b[2]; }; C1 aliasC1 = *(C1 *)((char *)&origin_y + 0);
        struct C2 { char b[2]; }; C2 aliasC2 = *(C2 *)((char *)&origin_x + 0);
        struct C3 { char b[3]; }; C3 aliasC3 = *(C3 *)((char *)&origin_y + 1);
        struct C4 { char b[1]; }; C4 aliasC4 = *(C4 *)((char *)&origin_y + 0);
        struct C5 { char b[2]; }; C5 aliasC5 = *(C5 *)((char *)&origin_y + 2);
        struct C6 { char b[1]; }; C6 aliasC6 = *(C6 *)((char *)&origin_y + 2);
        struct C7 { char b[2]; }; C7 aliasC7 = *(C7 *)((char *)&origin_y + 1);
        struct C8 { char b[3]; }; C8 aliasC8 = *(C8 *)((char *)&origin_x + 1);
        struct C9 { char b[3]; }; C9 aliasC9 = *(C9 *)((char *)&origin_y + 0);
        struct C10 { char b[1]; }; C10 aliasC10 = *(C10 *)((char *)&origin_y + 1);
        struct C11 { char b[1]; }; C11 aliasC11 = *(C11 *)((char *)&origin_x + 2);
        struct C12 { char b[1]; }; C12 aliasC12 = *(C12 *)((char *)&origin_y + 3);
        struct C13 { char b[2]; }; C13 aliasC13 = *(C13 *)((char *)&origin_x + 2);
        struct C14 { char b[2]; }; C14 aliasC14 = *(C14 *)((char *)&origin_x + 1);
        struct C15 { char b[1]; }; C15 aliasC15 = *(C15 *)((char *)&origin_x + 3);
        struct C16 { char b[3]; }; C16 aliasC16 = *(C16 *)((char *)&origin_x + 0);
        struct C17 { char b[1]; }; C17 aliasC17 = *(C17 *)((char *)&origin_x + 1);
            }
            if (hit) {
                f_07d6a0(p1, p2);
                f_043420(p2, 0);
                ret = 1;
                done = 1;
            } else {
                f_043420(p2, 0);
                f_0432c0((struct hero *)(p2), 0xff);
            }
        } else {
            f_043420(p2, 0);
            f_0432c0((struct hero *)(p2), 0xff);
        }
    } while (!done);
    { // steuert die temporaeren Teilobjekte von ret fuer die Stapelplatz-Reihenfolge
        struct A0 { char b[1]; }; A0 aliasA0 = *(A0 *)((char *)&ret + 2);
        struct A1 { char b[2]; }; A1 aliasA1 = *(A1 *)((char *)&ret + 1);
        struct A2 { char b[1]; }; A2 aliasA2 = *(A2 *)((char *)&ret + 1);
        struct A3 { char b[3]; }; A3 aliasA3 = *(A3 *)((char *)&ret + 1);
        struct A4 { char b[2]; }; A4 aliasA4 = *(A4 *)((char *)&ret + 2);
        struct A5 { char b[3]; }; A5 aliasA5 = *(A5 *)((char *)&ret + 0);
        struct A6 { char b[1]; }; A6 aliasA6 = *(A6 *)((char *)&ret + 3);
        struct A7 { char b[1]; }; A7 aliasA7 = *(A7 *)((char *)&ret + 0);
        struct A8 { char b[2]; }; A8 aliasA8 = *(A8 *)((char *)&ret + 0);
    }
    return ret;
}

//@ f_086800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt den kürzesten Feldabstand (f_071e20) von der Position (p2, p3) zum nächstgelegenen
 *   lebenden Monster im gesamten Kampfraster und gibt dessen Koordinaten über *p4 und *p5 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, die Prüfkoordinaten p2 (X) und p3 (Y) sowie
 *   die Ausgabezeiger p4 und p5 und gibt die minimale Distanz best (oder 99, falls kein Gegner gefunden wurde)
 *   als short zurück.
 * - Wichtige Variablen: Die Doppelschleife prüft alle 24 x 25 Einträge des Kampfrasters d_1bd984 über
 *   f_084890(p1, 0, ...).
 === Ende Beschreibung === */
short f_086800(int p1, short p2, short p3, short *p4, short *p5)
{
    short d = 0;
    short best = 99;
    short y;
    short x;
    for (y = 0; y < (short)0x18; y++) {
        f_146dfa(d_1c2edc, 1);
        for (x = 0; x < (short)0x19; x++) {
            if (f_084890(p1, 0, *(d_1bd984 + y * 0x19 + x)) != 0) {
                d = f_071e20(p2, p3, x, y);
                if (d <= best && (d < best || x == p2 || y == p3)) {
                    *p4 = x;
                    best = d;
                    *p5 = y;
                }
            }
        }
    }
    return best;
}

//@ f_086900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen KI-Helden (p2) an Position (p3, p4), ob sich ein feindliches Monster in
 *   weniger als 4 Feldern Abstand befindet (f_086800 < 4) oder das Ausweichflag f_043e50(p2) gesetzt ist, und
 *   löscht dieses Flag anschließend.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie die Koordinaten p3
 *   (X) und p4 (Y) und gibt 1 zurück, wenn sich ein Gegner in bedrohlicher Nähe befindet, sonst 0.
 * - Wichtige Variablen: Über f_043e40(p2, 0) wird das temporäre Rückzugsflag des Helden zurückgesetzt.
 === Ende Beschreibung === */
int f_086900(int p1, int p2, int p3, int p4)
{
    short oy, ox;
    int ret = 0;
    short r = f_086800(p1, p3, p4, &ox, &oy);
    if (r < 4 || f_043e50(p2)) {
        ret = 1;
        f_043e40(p2, 0);
    }
    return ret;
}

//@ f_086950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für eine Schusswaffe, ob der in der linken Hand getragene Munitionstyp p2 zum
 *   geforderten Munitionstyp p3 passt (und bei sparsamer KI-Einstellung noch mehr als 5 Geschosse übrig sind),
 *   gibt bei fehlender Munition die Fehlermeldung p5 aus oder zieht im Verbrauchsmodus (p1 == 0) genau ein
 *   Geschoss aus Slot 12 ab (f_036300).
 * - Eingaben und Rückgabe: Die Funktion erhält den Prüfmodus p1 (0 = Geschoss abziehen, 1 = mit Fehlermeldung
 *   prüfen, 2 = still für KI prüfen), die getragene Item-ID p2, die benötigte Munitions-ID p3, den Heldenzeiger
 *   p4 sowie die Meldungs-ID p5 und gibt 1 bei vorhandener Munition zurück, sonst 0.
 * - Wichtige Variablen: Bei Armbrustbolzen (0xd) akzeptiert der Aufrufer f_086a00 zuvor auch spezielle Bolzen
 *   (0x1a3).
 === Ende Beschreibung === */
int f_086950(short p1, short p2, short p3, int p4, int p5)
{
    int r = 0;
    struct RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    if (p2 != p3) {
        if (p1 != 2) {
            o.tables.p[1] = p4;
            f_0bf730(d_1c2c64, p5);
        }
    } else {
        if (((signed char)(f_0427b0((struct hero *)(p4)))) == 1 && f_035260(p4, p2) <= 5) goto end;
        if (!p1) f_036300(p4, 0xc, 1);
        r = 1;
    }
end:
    return r;
}

struct QU { char pad[0x1a9]; short n; short a[1]; };
//@ f_086a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die vom Helden (p2) in der rechten Hand (Slot 3) geführte Fernkampf- oder Wurfwaffe
 *   einsatzbereit ist, und zieht im Schussmodus (p3 == 0) entweder die geworfene Waffe selbst (und rückt eine
 *   identische Zweitwaffe aus der linken Hand Slot 12 nach) bzw. einen Pfeil/Bolzen über f_086950 ab und merkt
 *   verschossene Wurfwaffen zum späteren Wiedereinsammeln in p1 + 0x1a9 vor.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie den Prüfmodus p3
 *   (0 = Munition verbrauchen, 1 = mit Meldung prüfen, 2 = stille KI-Prüfung) und gibt 1 bei Schussbereitschaft
 *   zurück, sonst 0.
 * - Wichtige Variablen: Das Array q->a ab p1 + 0x1ab (mit Zähler q->n bei +0x1a9) speichert bis zu 30 im Kampf
 *   verschossene Wurfwaffen, damit sie nach dem Sieg wieder in die Beute aufgenommen werden.
 === Ende Beschreibung === */
#define OBJ (*(int *)(d_1c2c40 + (short)w * 4))
short f_086a00(int p1, int p2, short p3)
{
    short s;
    short r = 0;
    struct RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
    short w;
    if (d_1bd928) f_069460();
    w = f_042a60((struct hero *)(p2), 3);
    s = f_042a60((struct hero *)(p2), 0xc);
    if (((RivaItemDefinition*)(OBJ))->f_0a7990() != 0) {
        if (((signed char)(((RivaItemDefinition*)(OBJ))->f_0a78b0())) == 8 || ((signed char)(((RivaItemDefinition*)(OBJ))->f_0a78b0())) == 5) {
            if (!p3) {
                QU *q = (QU *)p1;
                if (q->n < (short)0x1e) q->a[q->n++] = w;
                f_036300(p2, 3, 1);
                if (s == (short)w) f_032ab0(p2, 3, 0xc);
            }
            r = 1;
        } else if (((signed char)(((RivaItemDefinition*)(OBJ))->f_0a78b0())) == 0) {
            if (p3 != 2) {
                o.tables.p[1] = p2;
                f_0bf730(d_1c2c64, 0x1010058);
            }
        } else {
            int msg;
            // haelt die Registerzuteilung (dx/eax) im Munitionszweig wie im Original
            d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004;
            d_1c2c40 = (d_1c2c40 & 0) ? 0 : d_1c2c40;
            short t = d_1a4424[((signed char)(((RivaItemDefinition*)(OBJ))->f_0a78a0())) * 5];
            msg = (t == 10) ? 0x1010009 : (t == 0xd) ? 0x101000a : (t == 0x184) ? 0x101000b : (t == 0x17e) ? 0x101009e : 0x101009f;
            if (t == 0xd && s == 0x1a3) t = 0x1a3;
            r = f_086950(p3, s, t, p2, msg);
        }
    }
    return r;
}

//@ f_086bf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen kompletten Nahkampfangriff eines Helden (p2) gegen einen anderen Helden (p3, etwa
 *   wenn einer der beiden verzaubert ist) durch: Sie würfelt Attacke, Parade sowie kritische Treffer und Patzer
 *   (einschließlich Waffenbruch, Sturz, Passierschlag und Selbstverletzung) aus, zieht den erlittenen Schaden ab
 *   (f_044300) und spielt anschließend die Schlag- und Paradeanimationen (f_06ed80, f_06efc0) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den angreifenden Helden p2 sowie den
 *   verteidigenden Helden p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Puffer d_1c2d1c sammelt die akustischen und visuellen Kampfeffekte des
 *   Schlagabtauschs, während p1 + 0x1ee..0x1f0 und d_1bd918 Spezialanimationen für Sturz und Tod steuern.
 === Ende Beschreibung === */
void f_086bf0(int p1, int p2, int p3)
{
    short s4, flag = 0, s1c, s20, s14, s3, sd;
    if (d_1bd928) f_069460();
    s20 = f_035110(p2);
    s3 = f_035110(p3);
    if (s20 == -1) {
        if (((char)(f_042750((struct hero *)(p2))))) {
            f_0845b0(p1, p2);
            s20 = f_035110(p2);
            if (s20 != -1) goto L60;
        }
        s14 = f_0456e0(p2, 0);
    } else {
L60:
        s14 = f_045610(p2);
    }
    if (s3 == -1) s1c = f_0456e0(p3, 0); else s1c = f_045610(p3);
    sd = f_0de4d0(d_1c0004);
    if (sd == (short)-5) { s14 -= 4; s1c -= 4; }
    if (f_043450(f_030810(p2)) == 1) { s14 += 2;
        s1c = (s1c & 0) ? (short)0 : s1c; // haelt die Referenzgewichtung von s1c und s20 fuer die Stapelplatz-Reihenfolge
        s20 = (s20 & 0) ? (short)0 : s20;
    }
    s14 += 4;
    s4 = f_1457e0(0x14);
    if (s4 == 0x14 && f_1457e0(0x14) > s14 - 9) {
#if FIX_BUGS >= 1
        PLOG_KAMPF('A', (const char *)(p2 + 0x22), s14, 0, s4, -1);
#endif
        short s2c = 0;
        f_09c890(d_1c2d1c, 1, 0, 2, p2);
        s3 = f_145760(2, 0xc);
        if (s3 == 2 && s20 != -1 && f_042d00((struct hero *)(p2), 3) != 0) {
            if (f_033c50(p2, 3, 1) != 0) f_09c890(d_1c2d1c, 6, 0, 2, p2);
        } else if (s3 >= 3 && s3 <= 8) {
            *(char *)(p1 + 0x1ef) = 1;
            if (f_1457e0(0x14) <= s1c) s2c = f_030080(p3, p2, 1);
            if (p1) s2c = (s2c & 0) ? (short)0 : s2c; // haelt die Stapelplatz-Zuteilung von s2c wie im Original
            if (p1) s2c = (s2c & 0) ? (short)0 : s2c;
            if (p1) s2c = (s2c & 0) ? (short)0 : s2c;
            if (s2c > 0) {
                f_09c800(d_1c2d1c, 0x18, s2c, 2, p3, 2, p2);
                f_044300(p2, s2c);
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
        PLOG_KAMPF('A', (const char *)(p2 + 0x22), s14, 0, s4, (s4 <= s14) ? 1 : 0);
#endif
        if (s4 > s14) {
            f_09c910(d_1c2d1c, 5, 0);
        } else {
            if (!f_043450(f_030810(p2))) {
                if (s3 == -1) s3 = f_045710(p3, 0); else s3 = f_045660(p3);
                if (f_042810((struct hero *)(p3)) == 3) s3 += 3;
                sd = f_0de4d0(d_1c0004);
                if (sd == (short)-5) s3 -= 4;
                if (s3 < 0) s3 = 0;
                s1c = f_1457e0(0x14);
                if (s1c == 0x14 && f_1457e0(0x14) > s3 - 7) {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x22), s3, 0, s1c, -1);
#endif
                    flag = 1;
                    f_09c890(d_1c2d1c, 2, 0, 2, p2);
                    s3 = f_145760(2, 0xc);
                    if (s3 >= 3 && s3 <= 8) {
                        *(char *)(p1 + 0x1ee) = 1;
                        if (f_1457e0(0x14) <= s14) {
                            s3 = f_030080(p2, p3, 1);
                            if (s3 > 0) {
                                f_09c800(d_1c2d1c, 0x18, s3, 2, p2, 2, p3);
                                f_044300(p3, s3);
                                if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                            }
                        }
                    } else if (s3 >= 9 && s3 <= 11) {
                        s3 = f_1457e0(6);
                        f_09c890(d_1c2d1c, 0xe, s3, 2, p3);
                        f_044300(p3, s3);
                        if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                    }
                } else {
#if FIX_BUGS >= 1
                    PLOG_KAMPF('P', (const char *)(p3 + 0x22), s3, 0, s1c, (s1c <= s3) ? 1 : 0);
#endif
                    if (s3 < s1c) flag = 1;
                    else {
                        f_09c890(d_1c2d1c, 9, 0, 2, p3);
                        if (s1c == s4) {
                            if (f_042be0((struct hero *)(p2), 3) > 3) {
                                if (f_1457e0(0xc) + f_042be0((struct hero *)(p2), 3) > 0x14) {
                                    if (f_033c50(p2, 3, 1) != 0) f_09c890(d_1c2d1c, 6, 0, 2, p2);
                                } else f_042ca0((struct hero *)(p2), 3);
                            } else f_042ca0((struct hero *)(p2), 3);
                            int t_486 = f_042be0((struct hero *)(p3), 3);
                            if (t_486 > 3) {
                                if (f_1457e0(0xc) + f_042be0((struct hero *)(p3), 3) > 0x14) {
                                    if (f_033c50(p3, 3, 1) != 0) f_09c890(d_1c2d1c, 6, 0, 2, p3);
                                } else f_042ca0((struct hero *)(p3), 3);
                            } else f_042ca0((struct hero *)(p3), 3);
                        }
                    }
                }
                flag = (flag & 0) ? (short)0 : flag; // haelt flag auf dem Stapel statt im Register ueber die Zweige
            } else flag = 1;
            if (flag) {
                s3 = f_030080(p2, p3, 1);
                if (s3 > 0) {
                    f_09c800(d_1c2d1c, 0x18, s3, 2, p2, 2, p3);
                    f_044300(p3, s3);
                    if (((char)(f_042470((struct hero *)(p3))))) d_1bd918 = 1;
                } else f_09c890(d_1c2d1c, 0x15, 0, 2, p3);
            }
        }
    }
    if (!d_1bd928) {
    *(int *)(p1 + 0x289) = f_06ed80(p1, p2, p1 + 0x45);
    {
        int v = f_06efc0(p1, p3, p1 + 0x45, f_043490(p2));
        *(char *)(p1 + 0x292) = 0;
        *(int *)(p1 + 0x28d) = v;
    }
    for (;;) {
        f_069460();
        if (*(char *)(p1 + 0x292)) break;
        if (f_069be0(*(int *)(p1 + 0x289)) != 0 && f_069be0(*(int *)(p1 + 0x28d)) != 0) break;
    }
    f_06ed10(p1, p2, p1 + 0x45);
    f_06ed10(p1, p3, p1 + 0x45);
    f_0757f0(p1);
    f_07bd30(p1, p2, p3);
    } else f_069460();
}
