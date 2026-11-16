/* === Beschreibung (Katalog) ===
 * Einheit gz_0839d0_t2 (084dd0 - 085640)
 *
 * Überblick
 * Die Einheit gz_0839d0_t2 enthält drei Funktionen für die Kampf-KI computergesteuerter Helden (Automatik-Modus
 * und NPC-Begleiter): die Fernkampf-Zielsuche und -Positionierung (f_084dd0), die Bestimmung der Zielkategorie
 * eines Heldenzaubers (f_084f90) sowie die Prüfung, ob ein geplanter Kampfzauber gegen das anvisierte Ziel
 * sinnvoll ist (f_085050).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 2/3 gleich (suche.py 26.10.2026, Basis gz_0839d0_t2_P1.CPP)
// P2h 1/3 gleich
// gz_0839d0_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x084DD0-0x085640
#include <string.h>
#include "RIVACTX.H"   // Ctor f_125400, Dtor f_1254a0
struct MObj : RivaTextContext { short tab[17]; MObj(void *a, void *b, void *c) : RivaTextContext(a, b, c) {} };
int f_030810(int p1);                                   // reg eax stapel 0
int f_030890(int p1);                                   // reg eax stapel 0
signed char f_030960(int p1);                           // reg eax stapel 0
short f_030d80(int p1);                                 // reg eax stapel 0
short f_032670(int p1, int p2);                         // reg eax edx stapel 0
short f_032820(int p1, int p2, int p3);                 // reg eax edx ebx stapel 0
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0352c0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                  // reg eax stapel 0
                                  // reg eax stapel 0
                                  // reg eax stapel 0
                                  // reg eax stapel 0
                                  // reg eax stapel 0
                                  // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax stapel 0
                           // reg eax stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                         // reg eax edx stapel 0
                         // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                  // reg eax stapel 0
                         // reg eax stapel 0
                           // reg eax edx stapel 0
signed char f_0433d0(int p1);                           // reg eax stapel 0
signed char f_043410(int p1);                           // reg eax stapel 0
int f_043420(int p1, int p2);                           // reg eax edx stapel 0
int f_043430(int p1, int p2);                           // reg eax stapel 0
unsigned char f_043470(int p1);                         // reg eax stapel 0
char f_043490(int p1);                                  // reg eax stapel 0
short f_043c10(int p1);                                 // reg eax stapel 0
short f_043c30(int p1);                                 // reg eax stapel 0
int f_043ce0(int p1);                                   // reg eax stapel 0
signed char f_043dc0(int p1);                                  // reg eax stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_069460();                                         // reg - stapel 0
short f_071e20(int p1, int p2, int p3, int p4);         // reg eax edx ebx ecx stapel 0
int f_071e50(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_071e90(int p1, short *p2, short *p3);             // reg eax edx ebx stapel 0
int f_071f20(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0729c0(int p1);                                  // reg eax stapel 0
int f_072a00(int p1);                                   // reg eax stapel 0
int f_072b70(int p1);                                   // reg eax stapel 0
int f_073800(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
unsigned char f_0738a0(int p1, short *p2, short *p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
unsigned char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0757f0(int p1);                                   // reg eax stapel 0
short f_07b1d0(int p1);                                        // reg - stapel 0
int f_07d6a0(int p1, int p2);                           // reg eax edx stapel 0
int f_07ea60(int p1, int p2);                           // reg eax edx stapel 0
short f_086a00(int p1, int p2, int p3);                 // reg eax edx ebx stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                 // reg eax edx ebx stapel 0
                           // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf730(void *p1, int p2);                         // reg eax edx stapel 0
extern "C" short f_0bf820(void *, ...);
short f_0c0020(void *p1, int p2);                       // reg eax edx stapel 0
short f_0cf9f0(int p1);                                  // reg eax stapel 0
short f_0cfa10(int p1);                                 // reg eax stapel 0
short f_0cfa50(int p1);                                 // reg eax stapel 0
signed char f_0cfc10(int p1);                           // reg eax stapel 0
signed char f_0cfcc0(int p1);                           // reg eax stapel 0
char f_0cfd70(int p1);                                  // reg eax stapel 0
char f_0cfe30(int p1);                                  // reg eax stapel 0
char f_0cffb0(int p1);                                  // reg eax stapel 0
int f_0d0440(int p1);                                   // reg eax stapel 0
signed char f_0d11e0(int p1);                                  // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
signed char f_0d54c0(int p1);                           // reg eax stapel 0
int f_133fe0(void *p1, char *p2);                       // reg eax edx stapel 0
int f_146dfa(void *p1, int p2);                         // reg eax edx stapel 0
short f_149360(int p1, const void *p2);
int f_084410(int p1, int p2);
int f_084890(int p1, short p2, short p3);
int f_084a60(unsigned char *p1, int p2);
extern char d_1a280c[];
extern char d_1a7277[];
extern signed char d_1a7278[];
extern int d_1bc8f0;
extern char d_1bd928;
extern char (*d_1bd984)[0x19];
extern short d_1bda6c;
extern short d_1bda6e;
extern char d_1c21b4[];
extern int d_1c29c4[];

extern char d_1c2c64[];
extern int d_1c2ed4;
extern char d_1c2edc[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
#define B(p,o) (*(unsigned char *)((p)+(o)))
#define SB(p,o) (*(signed char *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define OBJ_BEGIN RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498)
#define MOBJ_BEGIN MObj obj(d_1c349c, d_1c3870, d_1c3498)
#define MSG(n) f_0bf730(d_1c2c64, n)
#define ITEM(k) ((*(int **)&d_1c2c40)[k])
#define ITEM2(k) (*(int *)((k) * 4 + (int)(*(int **)&d_1c2c40)))
#define MENU(m, n) f_0bf820(d_1c2c64, m, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7], d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15])

unsigned char f_084b40(int p1, int p2, int p3, int p4, int p5, int p6);
extern short d_1bd920;
struct T14 { char c0, c1, c2, c3, c4, c5, c6; signed char c7; signed char c8; char rest[5]; };
extern signed char d_1a7270[];
//@ f_084dd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Fernkampf-Zielsuche eines computergesteuerten Helden (p2): Sie sucht über f_084b40
 *   ein Ziel mit freier Schusslinie (oder meldet res = 2, falls ein Gegner bereits auf Nahkampfdistanz < 2
 *   herangerückt ist, damit der Held die Waffe wechselt) und bewegt den Helden bei versperrter Sichtlinie
 *   schrittweise in eine bessere Schussposition (f_074b40, f_07d6a0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2, den Gesinnungsmodus p3
 *   sowie die Startkoordinaten p4 (X) und p5 (Y) und gibt 1 bei erfasstem Fernkampfziel, 2 bei erzwungenem
 *   Nahkampfwechsel oder 0 ohne Ziel zurück.
 * - Wichtige Variablen: Über f_0432c0 wird die Rasterkennung des gefundenen Ziels im Helden gespeichert.
 === Ende Beschreibung === */
short f_084dd0(int p1, int p2, short p3, short p4, short p5)
{
    short fertig = 0;
    short res;
    short ax, ay;
    res = 0;
    do {
        if (f_043410(p2) <= 0) break;
        if (d_1bd928) {
            f_069460();
            f_146dfa(d_1c2edc, 1);
        }
        f_0432c0((struct hero *)(p2), 0xff);
        if (f_043410(p2) >= 3) {
            f_0432c0((struct hero *)(p2), 0xff);
            unsigned char k1 = f_084b40(p1, p4, p5, p3, 99, 0);
            if (k1) f_0432c0((struct hero *)(p2), k1);
        }
        if (((unsigned char)(f_0432b0((struct hero *)(p2)))) != 0xff) {
            f_071e90(((unsigned char)(f_0432b0((struct hero *)(p2)))), &ax, &ay);
            if (f_071e20(ax, ay, p4, p5) < 2) res = 2;
            else res = 1;
            fertig = 1;
        } else if (!((char)(f_042600((struct hero *)(p2))))) {
            int k;
            if (!p3) k = f_074b40(p1, p2, p4, p5, 0xd, 2);
            else k = f_074b40(p1, p2, p4, p5, 0xc, 2);
            if (k != 0) {
                f_07d6a0(p1, p2);
                if (f_043410(p2) < 3) {
                    f_043420(p2, 0);
                    fertig = 1;
                } else {
                    f_0432c0((struct hero *)(p2), (unsigned char)k);
                    fertig = res = 1;
                }
            } else {
                f_043420(p2, 0);
                f_0432c0((struct hero *)(p2), 0xff);
            }
        } else {
            f_043420(p2, 0);
            f_0432c0((struct hero *)(p2), 0xff);
        }
    } while (!fertig);
    return res;
}
//@ f_084f90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt anhand der Zaubertabelle d_1a7270 für den Heldenzauber p3 und die Gesinnung des
 *   Zaubernden (p4), welche Art von Ziel (0 = Gegner, 1 = Verbündeter/Monster, 2 = Zaubernder selbst, 3 =
 *   befreundeter Held, 4 = bewusstloser Held) für diesen Spruch gesucht werden muss.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2, die Zauber-ID p3 sowie
 *   das Verzauberungsflag p4 und gibt den Zielsuchmodus (0..4 oder -1, falls ungeeignet) zurück.
 * - Wichtige Variablen: Hat der Held die Kampftaktik "zurückhaltend/Fernkampf" (f_042790 == 2), werden reine
 *   Berührungs-Schadenszauber (e[8] == 0) mit -1 ausgeschlossen.
 === Ende Beschreibung === */
int f_084f90(int p1, int p2, short p3, short p4)
{
    int r;
    signed char *e;
    r = -1;
    if (d_1bd928) {
        f_069460();
        f_146dfa(d_1c2edc, 1);
    }
    e = d_1a7270 + p3 * 0xe;
    if (!p4) {
        if (e[7] == 2) {
            if (p3 == 5) r = 4;
            else r = 3;
        } else if (e[7] == 1 || e[7] == 3) {
            if (((signed char)(f_042790((struct hero *)(p2)))) == 2 && e[8] == 0) r = -1;
            else r = 0;
        } else r = 2;
    } else {
        if (e[7] == 3) r = 1;
        else if (e[7] == 0) r = 2;
    }
    return r;
}
//@ f_085050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen computergesteuerten Helden (p2), ob der ausgewählte Kampfzauber p3 auf das
 *   aktuelle Ziel überhaupt sinnvoll angewendet werden kann (verhindert z. B. *Horriphobus*, *Paralys*, *Balsam*
 *   oder *Blitz dich find* auf bereits verzauberte, fliehende, unverletzte oder zu schwache Ziele).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den zaubernden Helden p2 sowie die Zauber-ID
 *   p3 und gibt 1 zurück, wenn sich der Zauber lohnt, sonst 0.
 * - Wichtige Variablen: Je nach Zielart (f_030960(p2)) wird das Ziel über f_030890 als Monster (a) oder über
 *   f_030810 als Held (b) geprüft.
 === Ende Beschreibung === */
#define P1 (*&p1)
int f_085050(int p1, int p2, short p3)
{
    short kind;
    int a, b;
    short x, y;
    short r;
    signed char c;
    if (d_1bd928) {
        f_069460();
        f_146dfa(d_1c2edc, 1);
    }
    c = f_030960(p2);
    r = 1;
    if (c == 1 || c == 4) {
        kind = 1;
        a = f_030890(p2);
    } else if (c == 5 || c == 2) {
        kind = 2;
        b = f_030810(p2);
    } else {
        return 0;
    }
    if (p3 == 0x31) {
        if (kind == 1) {
            if (f_0cfd70(a) || f_0cffb0(a) || f_0cfe30(a)) r = 0;
        } else {
            if (((char)(f_043230((struct hero *)(b)))) || ((char)(f_042640((struct hero *)(b)))) || ((char)(f_0424e0((struct hero *)(b))))) r = 0;
        }
    } else if (p3 == 0xc) {
        if (kind == 1) {
            if (f_0d0440(a) || f_0cfe30(a) || f_0cfc10(a) || f_0cffb0(a) || f_0cfa10(a) < f_0cf9f0(a) / 3) {
                r = 0;
            } else {
                r = 0;
                f_071e90((unsigned char)(f_0729c0(a) + 10), &x, &y);
                if (f_071f20((short)(x - 1), y) || !d_1bd984[y][x - 1]) r = 1;
                if (f_071f20((short)(x + 1), y) || !d_1bd984[y][x + 1]) r = 1;
                if (f_071f20(x, (short)(y - 1)) || !d_1bd984[y - 1][x]) r = 1;
                if (f_071f20(x, (short)(y + 1)) || !d_1bd984[y + 1][x]) r = 1;
            }
        } else {
            if (((char)(f_042640((struct hero *)(b)))) || ((char)(f_0424e0((struct hero *)(b))))) r = 0;
        }
    } else if (p3 == 0x48) {
        if (kind == 1) {
            if (f_0cfe30(a) || f_0cffb0(a)) r = 0;
        } else {
            if (((char)(f_0424e0((struct hero *)(b)))) || ((char)(f_042640((struct hero *)(b))))) r = 0;
        }
    } else if (p3 == 0x21) {
        r = 0;
        if (kind == 1) {
            if (f_0cfa10(a) <= f_0cf9f0(a) / 2 || f_0cfa10(a) < 10) r = 1;
        } else {
            if (f_042960((struct hero *)(b)) <= f_042970((struct hero *)(b)) / 2 || f_042960((struct hero *)(b)) < 10) r = 1;
        }
    } else if (p3 == 8) {
        if (f_0d0440(a) || f_0cfe30(a) || f_0cffb0(a) || f_0cfa10(a) < f_0cf9f0(a) / 3) r = 0;
    } else if (p3 == 0x36) {
        if (f_0cffb0(a) || f_0cfe30(a) || f_0d11e0(a) <= 6) r = 0;
    } else if (p3 == 0x34) {
        if (f_0cffb0(a) || f_0cfa10(a) < f_0cf9f0(a) / 5) {
            if (d_1bd920 != 5) r = 0;
        }
    } else if (p3 == 0x35) {
        if (f_0cffb0(a)) r = 0;
    } else if (p3 == 0x1b) {
        if (((char)(f_0427e0((struct hero *)(b)))) || ((char)(f_042640((struct hero *)(b)))) || f_07b1d0(P1) < 4 || ((char)(f_0424e0((struct hero *)(b))))) r = 0;
    } else if (p3 == 0x2e) {
        if (f_043dc0(b) >= 1 || ((char)(f_042640((struct hero *)(b)))) || f_07b1d0(P1) < 4 || ((char)(f_0424e0((struct hero *)(b))))) r = 0;
    } else if (p3 == 0x38) {
        if (f_043ce0(b) || ((char)(f_042640((struct hero *)(b)))) || f_07b1d0(P1) < 4 || ((char)(f_0424e0((struct hero *)(b))))) r = 0;
    } else if (p3 == 5) {
        if (!((char)(f_0424e0((struct hero *)(b))))) r = 0;
    }
    return r;
}
