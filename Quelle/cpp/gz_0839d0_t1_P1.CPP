/* === Beschreibung (Katalog) ===
 * Einheit gz_0839d0_t1 (0839d0 - 084dd0)
 *
 * Überblick
 * Die Einheit gz_0839d0_t1 umfasst acht Funktionen für Gegenstandsaktionen, Aktionsvalidierung und
 * KI-Hilfsroutinen im Rundenkampf: das Übergeben oder Tauschen von Gegenständen zwischen zwei benachbarten
 * Helden (f_0839d0), das Fallenlassen eines Rucksackgegenstands (f_083dc0), die Vorabprüfung einer geplanten
 * Heldenaktion unmittelbar vor ihrer Ausführung (f_083f80, f_084410), das automatische Ziehen einer
 * Nahkampfwaffe durch die KI (f_0845b0) sowie die Zielbewertung und Zielsuche auf dem Kampfraster (f_084890,
 * f_084a60, f_084b40).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 4/8 gleich (suche.py 29.10.2026, Basis gz_0839d0_t1_P1.CPP)
// P2h 1/8 gleich
// gz_0839d0_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0839D0-0x084DD0
#include <string.h>
struct Obj { int f0; char *p[13]; short s38; Obj(void *a, void *b, void *c); ~Obj(); };   // Ctor f_125400, Dtor f_1254a0
struct MObj : Obj { short tab[17]; MObj(void *a, void *b, void *c) : Obj(a, b, c) {} };
int f_030810(int p1);                                   // reg eax stapel 0
int f_030890(int p1);                                   // reg eax stapel 0
signed char f_030960(int p1);                           // reg eax stapel 0
short f_030d80(int p1);                                 // reg eax stapel 0
short f_032670(int p1, int p2);                         // reg eax edx stapel 0
short f_032820(int p1, int p2, int p3);                 // reg eax edx ebx stapel 0
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0352c0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
char f_042470(int p1);                                  // reg eax stapel 0
signed char f_0424e0(int p1);                                  // reg eax stapel 0
char f_042600(int p1);                                  // reg eax stapel 0
char f_042640(int p1);                                  // reg eax stapel 0
int f_042790(int p1);                                   // reg eax stapel 0
int f_0427e0(int p1);                                   // reg eax stapel 0
int f_042800(int p1, int p2);                           // reg eax edx stapel 0
short f_042810(int p1);                           // reg eax stapel 0
signed char f_0428d0(int p1);                           // reg eax stapel 0
short f_042960(int p1);                                 // reg eax stapel 0
short f_042970(int p1);                                 // reg eax stapel 0
short f_0429a0(int p1);                                 // reg eax stapel 0
short f_042a10(int p1);                                 // reg eax stapel 0
short f_042a60(int p1, int p2);                         // reg eax edx stapel 0
short f_042ac0(int p1, int p2);                         // reg eax edx stapel 0
int f_042bb0(int p1, int p2);                           // reg eax edx stapel 0
int f_043230(int p1);                                   // reg eax stapel 0
unsigned char f_0432b0(int p1);                         // reg eax stapel 0
int f_0432c0(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0433d0(int p1);                           // reg eax stapel 0
signed char f_043410(int p1);                           // reg eax stapel 0
int f_043420(int p1, int p2);                           // reg eax edx stapel 0
int f_043430(int p1, int p2);                           // reg eax stapel 0
unsigned char f_043470(int p1);                         // reg eax stapel 0
char f_043490(int p1);                                  // reg eax stapel 0
short f_043c10(int p1);                                 // reg eax stapel 0
short f_043c30(int p1);                                 // reg eax stapel 0
int f_043ce0(int p1);                                   // reg eax stapel 0
int f_043dc0(int p1);                                   // reg eax stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_069460();                                         // reg - stapel 0
short f_071e20(int p1, int p2, int p3, int p4);         // reg eax edx ebx ecx stapel 0
int f_071e50(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_071e90(int p1, short *p2, short *p3);             // reg eax edx ebx stapel 0
int f_071f20(int p1, int p2);                           // reg eax edx stapel 0
int f_0729c0(int p1);                                   // reg eax stapel 0
int f_072a00(int p1);                                   // reg eax stapel 0
int f_072b70(int p1);                                   // reg eax stapel 0
int f_073800(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
unsigned char f_0738a0(int p1, short *p2, short *p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0757f0(int p1);                                   // reg eax stapel 0
int f_07b1d0();                                         // reg - stapel 0
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
int f_0cf9f0(int p1);                                   // reg eax stapel 0
short f_0cfa10(int p1);                                 // reg eax stapel 0
short f_0cfa50(int p1);                                 // reg eax stapel 0
signed char f_0cfc10(int p1);                           // reg eax stapel 0
signed char f_0cfcc0(int p1);                           // reg eax stapel 0
int f_0cfd70(int p1);                                   // reg eax stapel 0
int f_0cfe30(int p1);                                   // reg eax stapel 0
char f_0cffb0(int p1);                                  // reg eax stapel 0
int f_0d0440(int p1);                                   // reg eax stapel 0
int f_0d11e0(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
signed char f_0d54c0(int p1);                           // reg eax stapel 0
int f_133fe0(void *p1, char *p2);                       // reg eax edx stapel 0
int f_146dfa(void *p1, int p2);                         // reg eax edx stapel 0
short f_149360(int p1, const void *p2);
short f_084410(int p1, int p2);
int f_084890(int p1, short p2, short p3);
short f_084a60(unsigned char *p1, short p2);
extern char d_1a280c[];
extern char d_1a7277[];
extern signed char d_1a7278[];
struct S5EF { char b[0x5ef]; };
extern struct S5EF *d_1bc8f0;
extern char d_1bd928;
extern int d_1bd984;
extern short d_1bda6c;
extern short d_1bda6e;
extern char d_1c21b4[];
extern int d_1c29c4[];

extern char d_1c2c64[];
struct S73 { char b[0x73]; };
extern struct S73 *d_1c2ed4;
extern char d_1c2edc[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
#define B(p,o) (*(unsigned char *)((p)+(o)))
#define SB(p,o) (*(signed char *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define OBJ_BEGIN Obj obj(d_1c349c, d_1c3870, d_1c3498)
#define MOBJ_BEGIN MObj obj(d_1c349c, d_1c3870, d_1c3498)
#define MSG(n) f_0bf730(d_1c2c64, n)
#define ITEM(k) ((*(int **)&d_1c2c40)[k])
#define ITEM2(k) (*(int *)((k) * 4 + (int)(*(int **)&d_1c2c40)))
#define D5(o) ((int)((char *)d_1bc8f0 + (o)))
#define Q73(i) ((int)((i) * 0x73 + (char *)d_1c2ed4))
#define R73(i) ((int)((char *)d_1c2ed4 + (i) * 0x73))
#define Q5EF(i) ((int)((i) * 0x5ef + (char *)d_1bc8f0))
#define MENU(m, n) f_0bf820(d_1c2c64, m, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7], d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15])

#define MSGX(m) msg = (m)
#define MSGE MSG(msg)
//@ f_0839d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermöglicht einem Helden (p2, ab 3 AP), im Kampf einen Gegenstand an einen auf einem
 *   Nachbarfeld stehenden Gruppenkameraden zu übergeben oder mit ihm zu tauschen (f_0352c0), und zieht dafür
 *   beiden beteiligten Helden jeweils 3 Aktionspunkte ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den aktiven Helden p2 sowie dessen
 *   Koordinaten p3 (X) und p4 (Y) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_032820 wählen beide Helden im Dialog den zu tauschenden Inventarslot aus (oder es
 *   wird automatisch ein freier Rucksackslot f_032670 bestimmt).
 === Ende Beschreibung === */
void f_0839d0(int p1, int p2, short p3, short p4)
{
    short cnt2;
    int ok = 1;
    short x;
    short slot2;
    short y;
    int other;
    int tmp_p;
    short tmp_s;
    OBJ_BEGIN;
    short it2;
    short target;
    short slot1;
    int flag = 0;
    short w1, w2;
    short old_it1, old_cnt1, old_it2, old_cnt2;
    short it1, cnt1;

    if (f_043410(p2) >= 3) {
        x = p3;
        y = p4;
        target = f_0738a0(p1, &x, &y, 1, 1, 0, 3);
        if (target == 0xff) {
            ok = 0;
        } else if (target == 0xfe || target == 0 || target >= (short)10) {
            MSG(0x101001d);
            ok = 0;
        } else if (target == (unsigned char)f_0d54c0(p2) + 1) {
            I(obj.p[0], 4) = p2;
            MSG(0x10100a2);
            ok = 0;
        }
        if (ok) {
            other = (int)&d_1bc8f0[target - 1];
            slot1 = 12;
            slot2 = 12;
            I(obj.p[0], 4) = p2;
            slot1 = f_032820(p2, 0x101009b, 0);
            if (slot1 == -1) {
                flag = 1;
                w1 = f_032670(p2, 0);
                if (w1 == -1) {
                    I(obj.p[0], 4) = p2;
                    MSG(0x101009c);
                    ok = 0;
                } else {
                    slot1 = w1;
                }
            }
            if (ok == 1) {
                I(obj.p[0], 4) = other;
                slot2 = f_032820(other, 0x101009b, 0);
                if (slot2 == -1) {
                    if (flag == 1) {
                        ok = 0;
                    } else {
                        w2 = f_032670(other, 0);
                        if (w2 == -1) {
                            I(obj.p[0], 4) = other;
                            MSG(0x101009c);
                            ok = 0;
                        } else {
                            slot2 = w2;
                        }
                    }
                }
            }
            if (ok) {
                if (f_042a60(p2, slot1) != 0 || f_042a60(other, slot2) != 0) {
                    if (f_042a60(p2, slot1) == 0) {
                        tmp_p = p2;
                        p2 = other;
                        other = tmp_p;
                        tmp_s = slot2;
                        slot2 = slot1;
                        slot1 = tmp_s;
                    }
                    old_it1 = f_042a60(p2, slot1);
                    old_cnt1 = f_042ac0(p2, slot1);
                    old_it2 = f_042a60(other, slot2);
                    old_cnt2 = f_042ac0(other, slot2);
                    f_0352c0(other, p2, slot1, slot2);
                    it1 = f_042a60(p2, slot1);
                    cnt1 = f_042ac0(p2, slot1);
                    it2 = f_042a60(other, slot2);
                    cnt2 = f_042ac0(other, slot2);
                    f_043430(p2, -3);
                    f_043430(other, -3);
                    if (it1 == 0) {
                        I(obj.p[0], 4) = other;
                        I(obj.p[2], 4) = (*(int **)&d_1c2c40)[it2];
                        W(obj.p[7], 2) = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[it2]))->f_0a7950() ? cnt2 : 1;
                        MSG(0x101009a);
                    } else if (it2 == 0) {
                        I(obj.p[0], 4) = p2;
                        I(obj.p[2], 4) = (*(int **)&d_1c2c40)[it1];
                        W(obj.p[7], 2) = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[it1]))->f_0a7950() ? cnt1 : 1;
                        MSG(0x101009a);
                    } else {
                        I(obj.p[0], 4) = p2;
                        I(obj.p[0], 8) = other;
                        I(obj.p[2], 4) = (*(int **)&d_1c2c40)[it1];
                        W(obj.p[7], 2) = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[it1]))->f_0a7950() ? cnt1 : 1;
                        I(obj.p[2], 8) = (*(int **)&d_1c2c40)[it2];
                        W(obj.p[7], 4) = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[it2]))->f_0a7950() ? cnt2 : 1;
                        MSG(0x101007a);
                    }
                } else {
                    I(obj.p[0], 4) = p2;
                    I(obj.p[0], 8) = other;
                    MSG(0x1010099);
                }
            }
        }
    } else {
        I(obj.p[0], 4) = p2;
        MSG(0x1010012);
    }
}


//@ f_083dc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für den aktiven Helden (p2, ab 1 AP) ein Menü seiner belegten Rucksackslots (15..30)
 *   und lässt den ausgewählten Gegenstand für 1 Aktionspunkt auf den Boden fallen (f_036300).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Array obj.tab[1..16] speichert die Rucksackslot-Indizes der im Menü aufgelisteten
 *   Gegenstände.
 === Ende Beschreibung === */
void f_083dc0(int p1, int p2)
{
    int msg;
    short n, i, it, sel, sv;
    int k;
    struct LocalObj { Obj base; short tab[17]; LocalObj(void *a, void *b, void *c) : base(a, b, c) {} };
    LocalObj obj(d_1c349c, d_1c3870, d_1c3498);
    if (f_043410(p2) >= 1) {
        n = 0;
        for (i = 0xf; i < 0x1f; i++) {
            it = f_042a60(p2, i);
            if (it != (short)0) {
                k = n;
                obj.tab[k + 1] = i;
                f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[it]),(char *)( d_1c21b4 + k * 0x28), 1);
                d_1c29c4[k] = f_133fe0(d_1c3498, d_1c21b4 + k * 0x28);
                n++;
            }
        }
        if ((short)n == (short)0) {
            I(obj.base.p[0], 4) = p2;
            MSG(0x101003b);
        } else {
            I(obj.base.p[0], 4) = p2;
            sv = f_0c0020(d_1c2c64, 6);
            sel = MENU(0x101002a, n);
            f_0c0020(d_1c2c64, sv);
            if (sel != (int)-1) {
                if (f_036300(p2, obj.tab[sel], -1)) f_043430(p2, -1);
            }
        }
    } else {
        I(obj.base.p[0], 4) = p2;
        MSG(0x1010012);
    }
}
//@ f_083f80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft unmittelbar vor dem Ausführen einer vorgemerkten Heldenaktion (Nahkampf 2, Zauber 4 oder
 *   Fernkampf 0x10), ob das anvisierte Ziel zwischenzeitlich gestorben oder versteinert ist, ob Sichtlinie und
 *   Waffenreichweite noch stimmen (f_084410), ob noch passende Munition vorhanden ist (f_086a00) und ob die
 *   restlichen Aktionspunkte des Helden noch ausreichen, und bricht die Aktion bei einem Konflikt mit einer
 *   entsprechenden Kampfmeldung ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt 1 zurück,
 *   wenn die Aktion ausgeführt werden darf, sonst 0.
 * - Wichtige Variablen: Im Spezialkampf d_1a280c wird bei Ziel 10 vorab eine Sonderplatzierung im Kampfraster
 *   vorgenommen.
 === Ende Beschreibung === */
short f_083f80(int p1, int p2)
{
    short res = 1;
    OBJ_BEGIN;
    short bx, ay, by, ax, cy, cx;
    signed char c;
    if (((signed char)f_042810(p2) == 4 || (signed char)f_042810(p2) == 2 || (signed char)f_042810(p2) == 0x10) && f_030960(p2) != 5) {
        if (f_149360(W(p1, 0x1ea), d_1a280c) != -1 && f_0432b0(p2) == 10 && f_071e90(10, &ax, &ay)) {
            f_071e50(p1, ax, ay, 0xfd);
            f_071e50(p1, f_043c10(p2), f_043c30(p2), 10);
        }
        if (((f_030960(p2) == 1 || f_030960(p2) == 4) && !f_072a00(f_030890(p2))) ||
            (f_030960(p2) == 2 && f_042470(f_030810(p2)))) {
            MSG(0x101001e);
            f_042800(p2, 0xd);
            f_0432c0(p2, 0xff);
            res = 0;
        } else if (((f_030960(p2) == 1 || f_030960(p2) == 4) && f_0cffb0(f_030890(p2))) ||
                   (f_030960(p2) == 2 && f_042640(f_030810(p2)))) {
            if (f_030960(p2) == 1 || f_030960(p2) == 4) {
                I(obj.p[1], 4) = f_030890(p2);
                W(obj.p[6], 2) = 1;
                MSG(0x101005e);
            } else {
                I(obj.p[0], 4) = f_030810(p2);
                MSG(0x101005d);
            }
            f_042800(p2, 0xd);
            f_0432c0(p2, 0xff);
            res = 0;
        } else {
            if (((signed char)f_042810(p2) == 4 || (signed char)f_042810(p2) == 0x10) && !((int (*)(int, int))f_084410)(p1, p2)) {
                f_042800(p2, 0xd);
                f_0432c0(p2, 0xff);
                res = 0;
            } else if ((signed char)f_042810(p2) == 0x10 && !f_086a00(p1, p2, 1)) {
                unsigned short it = f_042a60(p2, 3);
                switch (it) {
                case 9: case 0x13: case 0x100: case 0x13d:
                    I(obj.p[0], 4) = p2;
                    MSG(0x1010009);
                    break;
                case 0xc: case 0x101:
                    I(obj.p[0], 4) = p2;
                    MSG(0x101000a);
                    break;
                }
                f_042800(p2, 0xd);
                f_0432c0(p2, 0xff);
                res = 0;
            } else if ((signed char)f_042810(p2) == 2) {
                c = f_0d54c0(p2);
                f_071e90(f_0432b0(p2), &bx, &by);
                f_071e90((unsigned char)(c + 1), &cx, &cy);
                if (f_071e20(cx, cy, bx, by) > 1) {
                    MSG(0x1010028);
                    f_042800(p2, 0xd);
                    f_0432c0(p2, 0xff);
                    res = 0;
                }
            }
        }
        if (res && (((signed char)f_042810(p2) == 4 && f_043410(p2) < 5) ||
                    (((signed char)f_042810(p2) == 0x10 || (signed char)f_042810(p2) == 2) && f_043410(p2) < 3))) {
            f_042800(p2, 0xd);
            f_0432c0(p2, 0xff);
            I(obj.p[0], 4) = p2;
            MSG(0x1010012);
            res = 0;
        }
    } else if ((signed char)f_042810(p2) == 0xd || (signed char)f_042810(p2) == 3) {
        I(obj.p[0], 4) = p2;
        MSG(0x101005f);
        f_042800(p2, 3);
        f_043420(p2, 0);
        f_0432c0(p2, 0xff);
    } else if ((signed char)f_042810(p2) == 1 || (signed char)f_042810(p2) == 5) {
        res = 0;
    }
    return res;
}
//@ f_084410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Überprüft für einen Fernkampfangriff oder Fernzauber des Helden (p2), ob zwischen seiner
 *   Position (cx, cy) und dem Ziel (bx, by) eine freie Sichtlinie besteht (f_073800) und ob beim Bogenschießen
 *   (0x10) der Mindestabstand zu direkt benachbarten Gegnern eingehalten wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt 1 bei
 *   freier Schussbahn zurück, sonst 0.
 * - Wichtige Variablen: Bei blockierter Sichtlinie gibt die Funktion die Meldung 0x1010028 aus, bei
 *   unterschrittenem Mindestabstand 0x1010033.
 === Ende Beschreibung === */
short f_084410(int p1, int p2)
{
    short res;
    short cx, cy, by, bx;
    signed char c;
    short k;
    OBJ_BEGIN;
    res = 1;
    if (d_1bd928) f_069460();
    c = f_0d54c0(p2);
    f_071e90(f_0432b0(p2), &bx, &by);
    f_071e90((unsigned char)(c + 1), &cx, &cy);
    k = 99;
    if ((signed char)f_042810(p2) == 4) {
        if (d_1a7278[f_0433d0(p2) * 0xe] == 0) k = 1;
    }
    if (f_073800(p1, cx, cy, bx, by, k) == 0) {
        MSG(0x1010028);
        res = 0;
    } else {
        short sight = f_071e20(cx, cy, bx, by);
        if ((sight == 1 || (sight == 2 && cx != bx && cy != by)) && (signed char)f_042810(p2) == 0x10) {
            f_030d80(p2);
            int value = (((signed char)(((RivaItemDefinition*)(ITEM(f_042a60(p2, 3))))->f_0a78b0())) != 7) + 0x1010051;
            I(obj.p[3], 4) = value;
            res = 0;
            MSG(0x1010033);
        }
    }
    int result = res;
    return result;
}
//@ f_0845b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt einen computergesteuerten Helden (p2) automatisch auf eine unzerbrochene Nahkampfwaffe
 *   aus dem Rucksack (Slots 15..30) oder der linken Hand (Slot 12) wechseln (oder eine unbrauchbare
 *   Fernkampfwaffe wegstecken) und zieht dafür 2 Aktionspunkte ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt 1 zurück,
 *   wenn eine Nahkampfwaffe angelegt wurde, 2, wenn die bisherige Waffe weggesteckt wurde, oder 0, wenn kein
 *   Wechsel möglich war.
 * - Wichtige Variablen: Bei Zweihandwaffen (Typ == 6) versucht die Funktion zuvor, einen in der linken Hand
 *   (Slot 12) gehaltenen Gegenstand in einen freien Rucksackslot (f_032670) zu räumen.
 === Ende Beschreibung === */
short f_0845b0(int p1, int p2)
{
    short res, i, it, w;
    int ok;
    int n;
    res = 0;
    f_146dfa(d_1c2edc, 1);
    for (i = 0xf; i < 0x1f; i++) {
        it = f_042a60(p2, i);
        if (((RivaItemDefinition*)(ITEM2(it)))->f_0a7990() && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 7 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 8 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 5 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 0 && f_045960(p2, it) && f_042bb0(p2, i) == 0) {
            ok = 1;
            if (((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) == 6) {
                if ((int)f_042a60(p2, 0xc)) {
                    w = f_032670(p2, 0);
                    if (w == -1) ok = 0;
                    else f_032ab0(p2, 0xc, w);
                }
            }
            if (ok == 1) {
                f_032ab0(p2, 3, i);
                res = 1;
                break;
            }
        }
    }
    if (res == (short)0) {
        if ((int)f_042a60(p2, 3)) {
            w = f_032670(p2, 0);
            if (w != -1) {
                f_032ab0(p2, 3, w);
                res = 2;
            }
        }
        if (res == (short)0) {
            if ((int)f_042a60(p2, 3) || (int)f_042a60(p2, 0xc)) {
                it = f_042a60(p2, 0xc);
                if (((RivaItemDefinition*)(ITEM2(it)))->f_0a7990() && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 7 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 8 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 5 && ((signed char)(((RivaItemDefinition*)(ITEM2(it)))->f_0a78b0())) != 0 && f_042bb0(p2, 0xc) == 0) {
                    f_032ab0(p2, 3, 0xc);
                    res = 1;
                } else if (it == 0) {
                    f_032ab0(p2, 3, 0xc);
                    res = 2;
                }
            }
        }
    }
    f_146dfa(d_1c2edc, 1);
    n = f_07ea60(p1 + 0x39, f_043470(p2));
    B(n, 6) = f_043490(p2);
    if ((int)res) f_043430(p2, -2);
    f_0757f0(p1);
    return res;
}
//@ f_084890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Kampfraster-Kennung p3 zum gewünschten KI-Zielsuchmodus p2 passt (0 = lebendes
 *   Monster, 1 = lebender Held oder verzaubertes Monster, 3 = lebender Held, 4 = bewusstloser, aber noch
 *   lebender Held, 5 = freies Kampffeld 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Zielsuchmodus p2 sowie den Kachelwert p3
 *   aus dem Kampfraster und gibt 1 bei Übereinstimmung zurück, sonst 0.
 * - Wichtige Variablen: Das Array d_1bc8f0 enthält die Heldenstrukturen (1..9), während d_1c2ed4 die
 *   Monsterstrukturen (10..29 bzw. Hinterteile 30..49) verwaltet.
 === Ende Beschreibung === */
int f_084890(int p1, short p2, short p3)
{
    int o;
    int r = 0;
    if (!p2) {
        if ((p3 >= (short)10 && p3 < (short)0x1e && f_072a00(Q73(p3 - 10))) || (p3 >= (short)0x1e && p3 < (short)0x32 && f_072a00(Q73(p3 - 0x1e)))) r = 1;
    } else if ((int)p2 == 1) {
        if ((p3 >= (short)1 && p3 < (short)10 && f_0d4a60(Q5EF(p3 - p2))) || (p3 >= (short)10 && p3 < (short)0x1e && f_072b70(R73(p3 - 10))) || (p3 >= (short)0x1e && p3 < (short)0x32 && f_072b70(Q73(p3 - 0x1e)))) r = 1;
    } else if ((int)p2 == 3) {
        if (p3 >= (short)1 && p3 < (short)10 && f_0d4a60(Q5EF(p3 - 1))) r = 1;
    } else if ((int)p2 == 4) {
        if (p3 >= (short)1 && p3 < (short)10) {
            if (f_0424e0(D5((p3 - 1) * 0x5ef)) && !f_042470(D5((p3 - 1) * 0x5ef))) r = 1;
        }
    } else if ((int)p2 == 5) {
        if ((int)p3 == 0) r = 1;
    }
    return r;
}
//@ f_084a60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewertet eine Liste von p2 gefundenen Zielkandidaten (p1[0..p2-1]) anhand ihrer Stufen-,
 *   Magie-, Lebenspunkte- und Astralpunktewerte und wählt den gefährlichsten bzw. lohnendsten Gegner aus.
 * - Eingaben und Rückgabe: Die Funktion erhält das Array p1 der Rasterkennungen sowie deren Anzahl p2 und gibt
 *   den Array-Index bi des bestbewerteten Ziels als short zurück.
 * - Wichtige Variablen: Die Bewertungsformel gewichtet die Stufe (f_0428d0 bzw. f_0cfcc0) mal Magiebegabung plus
 *   aktuelle Lebens- und Astralpunkte.
 === Ende Beschreibung === */
short f_084a60(unsigned char *p1, short p2)
{
    short best, v, bi, i;
    int o;
    unsigned char k;
    best = -1;
    bi = 0;
    i = 0;
    if (p2 > (short)0) {
        do {
            f_146dfa(d_1c2edc, 1);
            k = *((unsigned char *)((int)p1 + i));
            if (k == 0) v = 100;
            else if (k < 10) {
                o = (int)&d_1bc8f0[k - 1];
                v = f_0428d0(o) * 10 * (f_042a10(o) + 1) + f_042960(o) + f_0429a0(o);
            } else {
                o = (int)&d_1c2ed4[k - 10];
                v = f_0cfcc0(o) * 10 * (f_0cfc10(o) + 1) + f_0cfa10(o) + f_0cfa50(o);
            }
            if (v > best) { best = v; bi = i; }
            i++;
        } while (i < p2);
    }
    // haelt die Registerzuteilung (edi/Stapel) der Schleife wie im Original
    d_1bd984 = (d_1bd984 & 0) ? 0 : d_1bd984;
    d_1c29c4[0] = (d_1c29c4[0] & 0) ? 0 : d_1c29c4[0];
    d_1c29c4[1] = (d_1c29c4[1] & 0) ? 0 : d_1c29c4[1];
    return bi;
}
//@ f_084b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht das Kampfraster im Umkreis p5 um die Position (p2, p3) nach allen Zielen des Typs
 *   p4 (f_084890) mit freier Sichtlinie (f_073800), wählt über f_084a60 das beste Ziel aus und speichert dessen
 *   Koordinaten in d_1bda6c und d_1bda6e.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, die Suchzentrum-Koordinaten p2 (X) und p3
 *   (Y), den Zielsuchmodus p4, die maximale Reichweite p5 sowie das Nahdistanz-Flag p6 (0 = angrenzende Felder
 *   für Fernkampf ausschließen) und gibt die Rasterkennung des besten Ziels (oder 0xff bei einem freien Zielfeld
 *   bzw. 0 ohne Treffer) zurück.
 * - Wichtige Variablen: Die lokalen Arrays xs[28], ys[28] und ks[28] sammeln die bis zu 28 gültigen
 *   Kandidatenfelder im Suchfenster.
 === Ende Beschreibung === */
unsigned char f_084b40(int p1, int p2, int p3, int p4, int p5, int p6)
{
    short ys[28];
    short n;
    short xs[28];
    unsigned char ks[28];
    short a = p2;
    short b = p3;
    short c = p4;
    short y1;
    short x0;
    short ys0;
    short x;
    short x1;
    short y;
    unsigned char k;
    p2 = p3 = p4 = 0; // trennt die Registerparameter von den 16-Bit-Kopien a/b/c
    n = 0;
    x0 = a - p5;
    ys0 = b - p5;
    x1 = a + p5;
    y1 = b + p5;
    if (x0 < 0) x0 = 0;
    if (ys0 < 0) ys0 = 0;
    if (x1 > 0x17) x1 = 0x17;
    if (y1 > 0x17) y1 = 0x17;
    for (y = ys0; y <= y1; y++) {
        x1=(x1&0)?(short)0:x1; c=(c&0)?(short)0:c; // haelt die Stapelplatz-Reihenfolge von x1 und c wie im Original
        if (d_1bd928) {
            f_069460();
            f_146dfa(d_1c2edc, 1);
        }
        for (x = x0; x <= x1; x++) {
            f_146dfa(d_1c2edc, 1);
            int off=(y&0)?0:y*25; k=*(unsigned char *)(d_1bd984+off+x); // erzwingt die Berechnung des Zeilenoffsets in edx vor dem Byte-Laden
            if (k >= 0 && k < 0x32 && (x != a || y != b)) {
                short d = f_071e20(a, b, x, y);
                if (d == 2 && p6 == 0 && x != a && y != b) d = p5 + 1;
                if (d <= (short)p5 && f_084890(p1, c, k) && f_073800(p1, a, b, x, y, 99)) {
                    xs[n] = x;
                    ys[n] = y;
                    ks[n++] = k;
                }
            }
        }
    }
    if (!n) return 0;
    k = f_084a60(ks, n);
    b = (b & 0) ? 0 : (short)(b & 0xffff); // haelt b ueber den Aufruf lebendig fuer die Stapelplatz-Zuteilung
    d_1bda6c=xs[k];
    { short *qh2 = &d_1bda6c; (*qh2) = xs[k]; } // erzwingt die Ladereihenfolge ys[k] vor xs[k] und die Stapelplatz-Reihenfolge
    d_1bda6e = ys[k];
    return ks[k] == 0 ? 0xff : ks[k];
}
