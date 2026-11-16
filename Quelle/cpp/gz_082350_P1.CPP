/* === Beschreibung (Katalog) ===
 * Einheit gz_082350 (082350 - 083680)
 *
 * Überblick
 * Die Einheit gz_082350 implementiert die vom Spieler im Kampfaktionsmenü auswählbaren Heldenbefehle: das
 * Einleiten der Bewegung (f_082350), das Auswählen eines Nah- oder Fernkampfziels (f_082460), das
 * Abbrechen/Abwarten der Runde (f_0828d0), das Auswählen eines Kampfzaubers samt Zielprüfung (f_082920), das
 * Benutzen oder Werfen des Gegenstands in der linken Hand (f_082d30) sowie das Wechseln des Gegenstands in der
 * linken (f_083060) oder der Waffe in der rechten Hand (f_0832b0).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 2/7 gleich (suche.py 25.10.2026, Basis gz_082350_P1.CPP)
// P2h 2/7 gleich
// gz_082350.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x082350-0x083680
#include <string.h>
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
short f_030d80(int p1);                                 // reg eax stapel 0
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_03cd00(int p1, int p2);                          // reg eax edx stapel 0
                                  // reg eax stapel 0
                           // reg eax edx stapel 0
                                  // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                  // reg eax stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                         // reg eax edx stapel 0
                                   // reg eax stapel 0
                         // reg eax edx stapel 0
                         // reg eax edx stapel 0
                           // reg eax edx stapel 0
                         // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_0433c0(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0433d0(int p1);                                  // reg eax stapel 0
signed char f_043410(int p1);                                  // reg eax stapel 0
int f_043420(int p1, int p2);                           // reg eax edx stapel 0
int f_043430(int p1, int p2);                           // reg eax stapel 0
int f_043c20(int p1, int p2);                           // reg eax edx stapel 0
int f_043c40(int p1, int p2);                           // reg eax edx stapel 0
signed char f_043e10(int p1);                                  // reg eax stapel 0
short f_044900(int p1, int p2, int p3);                 // reg eax edx ebx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_06ed10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_071e20(int p1, int p2, int p3, int p4);         // reg eax edx ebx ecx stapel 0
int f_072a00(int p1);                                   // reg eax stapel 0
unsigned char f_0738a0(int p1, short *p2, short *p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
void f_07dee0(int p1, int p2, short *p3, short *p4);    // reg eax edx ebx ecx stapel 0
short f_086a00(int p1, int p2, int p3);                 // reg eax edx ebx stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                 // reg eax edx ebx stapel 0
                                  // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf730(void *p1, int p2);                         // reg eax edx stapel 0
extern "C" short f_0bf820(void *, ...);                 // Menue, Varargs
short f_0c0020(void *p1, int p2);                       // reg eax edx stapel 0
char f_0cff80(int p1);                                  // reg eax stapel 0
short f_0d4c80(int p1);                                 // reg eax
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
signed char f_0d54c0(int p1);                                  // reg eax stapel 0
int f_0e9300(void *p1, char *p2, int p3);               // reg eax edx ebx stapel 0
short f_10cae0(int p1, int p2);                         // reg eax edx stapel 0
int f_133fe0(void *p1, char *p2);                       // reg eax edx stapel 0
short f_149360(int p1, const void *p2);
extern "C" int f_14572e(char *, const char *, ...);     // sprintf
extern char d_1a489a[];
extern char d_1a7270[];
extern char d_1a7277[];
extern char d_1b6f6c[];
extern char d_1b6f6f[];
extern char d_1b6f71[];
extern int d_1bc8f0;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern int d_1c29c4[];

extern char d_1c2c64[];
extern int d_1c2ed4;
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
struct E73 { char b[0x73]; };
struct E5EF { char b[0x5ef]; };
#define EN(i) ((int)(*(E73 **)&d_1c2ed4 + (i)))
#define EN2(i) ((int)((i) + *(E73 **)&d_1c2ed4))
#define ENa(i) ((int)*(E73 **)&d_1c2ed4 + (i) * 0x73)
#define ENb(i) ((i) * 0x73 + (int)*(E73 **)&d_1c2ed4)
#define EM(i) ((int)(*(E5EF **)&d_1bc8f0 + (i)))
#define SH(x) ((short)(x))
#define B(p,o) (*(unsigned char *)((p)+(o)))
#define SB(p,o) (*(signed char *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define OBJ_BEGIN RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498)
struct MObj : RivaTextContext { short tab[16]; MObj(void *a, void *b, void *c) : RivaTextContext(a, b, c) {} };
#define MOBJ_BEGIN MObj obj(d_1c349c, d_1c3870, d_1c3498)
#define MSG(n) f_0bf730(d_1c2c64, n)
#define ITEM(k) ((*(int **)&d_1c2c40)[k])
#define ITEM2(k) (*(int *)((k) * 4 + (int)(*(int **)&d_1c2c40)))
#define MENU(m, n) f_0bf820(d_1c2c64, m, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7], d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15])

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_082350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet die Bewegungsaktion eines Helden (p2): Ist der Held gefesselt oder festgehalten
 *   (f_042600), legt er zunächst eine Körperkraft- bzw. Gewandtheitsprobe (f_044900) ab, um sich zu befreien;
 *   ist er frei und besitzt noch Aktionspunkte (f_043410 > 0), wird die interaktive Zielfeldauswahl f_07dee0
 *   aufgerufen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie die
 *   Koordinatenzeiger p3 (X) und p4 (Y) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_042600 und f_042610 wird der Fesselungsstatus des Helden abgefragt bzw. gelöst.
 === Ende Beschreibung === */
void f_082350(int p1, int p2, short *p3, short *p4)
{
    int msg;
    OBJ_BEGIN;
    if (((char)(f_042600((struct hero *)(p2))))) {
        if (f_044900(p2, 0, 2) > 0) {
            f_042610((struct hero *)(p2), 0);
            I(obj.slots[0], 4) = p2;
            MSG(0x101009d);
        } else if (SB(((char *)(f_0429c0((struct hero *)(p2), 0))), 1) > 4) {
            short v = f_0d4c80(p2);
            f_0d5040(p2, v, 0x93a8, 0, -2, 0);
        }
    }
    if (!((char)(f_042600((struct hero *)(p2))))) {
        f_042800((struct hero *)(p2), 1);
        if (f_043410(p2) > 0) {
            f_07dee0(p1, p2, p3, p4);
            f_042570((struct hero *)(p2), 0);
        } else {
            I(obj.slots[0], 4) = p2;
            MSG(0x1010012);
        }
    } else {
        I(obj.slots[0], 4) = p2;
        MSG(0x1010008);
    }
}
//@ f_082460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Zielauswahl für einen Waffenangriff des Helden (p2) durch (ab 3 AP): Je nachdem, ob
 *   der Held eine Nahkampfwaffe (f_030d80 == -1) oder eine geladene Fernkampfwaffe (f_086a00) trägt, lässt sie
 *   den Spieler ein Ziel in Reichweite 1 bzw. 99 anklicken (f_0738a0), prüft auf ungültige Ziele (leeres Feld,
 *   eigener Held, bereits tote oder versteinerte Figuren, zu geringer Mindestabstand <= 1 bei Schusswaffen) und
 *   trägt bei Erfolg den Angriffsbefehl (2 = Nahkampf, 0x10 = Fernkampf) samt Ziel und 3 AP Abzug im Helden ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie dessen
 *   Standkoordinaten p3 (X) und p4 (Y) und gibt 1 bei erfolgreich vorgemerktem Angriff zurück, sonst 0.
 * - Wichtige Variablen: Das Feld W(p1, 0x19b) übernimmt den gewählten Kampfstil des Helden (f_043e10:
 *   vorsichtig, normal oder aggressiv) und passt den Attacke-/Parade-Modifikator (f_043160) entsprechend an.
 === Ende Beschreibung === */
short f_082460(int p1, int p2, short p3, short p4)
{
    struct Address { static int at(int idx) { int off=idx*0x73; int base=d_1c2ed4; base+=off; base=(base&0)?0:base; return base; } }; // haelt die Registerfolge (eax/edx) bei der Gegner-Tabellenadresse
    int message;
    short ret = 0;
    unsigned char sel;
    short y;
    short x;
    short r;
    OBJ_BEGIN;
    if (f_043410(p2) >= 3) {
        x = p3;
        p3 = x; // haelt die Stapelplatzfolge von p3/p4 und x/y
        y = p4;
        sel = 0xff;
        r = f_030d80(p2);
        { short round_r=r; r=round_r; } // haelt r im gleichen Register wie im Original
        if (r == -1) {
            sel = f_0738a0(p1, &x, &y, 1, 1, 0, 3);
        } else if (f_086a00(p1, p2, 1)) {
            sel = f_0738a0(p1, &x, &y, 99, 2, 0, 3);
        }
        if (sel == (unsigned char)0xff) goto done;
            if (sel == 0 || sel >= 0x32) {
                MSG(0x101001d);
            } else if (sel == (unsigned char)f_0d54c0(p2) + 1) {
                MSG(0x1010004);
            } else if ((sel >= 10 && sel < 0x1e && f_0cff80(Address::at(sel - 10))) ||
                       (sel >= 0x1e && f_0cff80(EN2(sel - 0x1e)))) {
                short k = sel < 0x1e ? 10 : 0x1e;
                I(obj.slots[1],4)=EN(sel-k);
                W(obj.slots[6], 2) = 1;
                MSG(0x1010053);
                f_042800((struct hero *)(p2), 0xd);
                f_0432c0((struct hero *)(p2), 0xff);
            } else if ((sel < 10 && ((char)(f_042470((struct hero *)(EM(sel - 1)))))) ||
                       (sel >= 10 && sel < 0x1e && f_072a00(Address::at(sel - 10)) == 0) ||
                       (sel >= 0x1e && f_072a00(EN2(sel - 0x1e)) == 0)) {
                MSG(0x101001e);
                f_042800((struct hero *)(p2), 0xd);
                f_0432c0((struct hero *)(p2), 0xff);
            } else if (r != -1 &&
                       (f_071e20(p3, p4, x, y) < 2 ||
                        (f_071e20(p3, p4, x, y) == 2 && p3 != x && p4 != y))) {
                message=(((signed char)(((RivaItemDefinition*)(ITEM(f_042a60((struct hero *)(p2),3))))->f_0a78b0()))!=7)+0x1010051;
                message=(message&0)?((short)p2+(short)p1):message; // haelt die Lebensdauer von p1/p2 und verhindert Direktfaltung von message
                I(obj.slots[3],4)=message;
                MSG(0x1010033);
                f_042800((struct hero *)(p2), 0xd);
                f_0432c0((struct hero *)(p2), 0xff);
            } else {
                f_043160((struct hero *)(p2), 0);
                if (r == -1) {
                    W(p1, 0x19b) = f_043e10(p2);
                    f_043160((struct hero *)(p2), (signed char)(W(p1, 0x19b) == 1 ? 2 : W(p1, 0x19b) == 0 ? 0 : -2));
                    f_0432c0((struct hero *)(p2), sel);
                    f_043c20(p2, x);
                    f_043c40(p2, y);
                    f_043430(p2, -3);
                    f_042800((struct hero *)(p2), 2);
                    ret = 1;
                } else {
                    f_0432c0((struct hero *)(p2), sel);
                    f_043c20(p2, x);
                    f_043c40(p2, y);
                    f_043430(p2, -3);
                    f_042800((struct hero *)(p2), (signed char)(r > 0 ? 0x10 : 2));
                    ret = 1;
                }
            }
    } else {
        I(obj.slots[0], 4) = p2;
        MSG(0x1010012);
    }
done:
    return ret;
}
//@ f_0828d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beendet den Zug des aktiven Helden (p2) vorzeitig, setzt seine verbleibenden Aktionspunkte auf
 *   0 und vermerkt bei mindestens 3 verbliebenen Aktionspunkten die Aktion 3 (Sichern/Abwarten mit Paradebonus),
 *   andernfalls 0xd (Zugende).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt immer 1
 *   zurück.
 * - Wichtige Variablen: Über f_043420(p2, 0) werden die restlichen Aktionspunkte der laufenden Runde verbraucht.
 === Ende Beschreibung === */
int f_0828d0(int p1, int p2)
{
    int r = 1;
    f_043420(p2, 0);
    f_0432c0((struct hero *)(p2), 0xff);
    if (f_043410(p2) >= 3) f_042800((struct hero *)(p2), 3); else f_042800((struct hero *)(p2), 0xd);
    return r;
}
//@ f_082920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für einen magiebegabten Helden (p2, ab 5 AP) das Zauberauswahlmenü (f_03cd00), schlägt
 *   in der Zaubertabelle d_1a7270 Zielart (e[7]) und Reichweite (e[8]) des gewählten Spruchs nach, lässt den
 *   Spieler bei zielgerichteten Zaubern das Ziel auf dem Kampffeld auswählen (f_0738a0), prüft Zieltyp und
 *   Mindest-Astralpunkte (f_10cae0) und trägt bei Erfolg die Zauberaktion 4 im Helden ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie dessen Position p3
 *   (X) und p4 (Y) und gibt 1 zurück, wenn ein Zauber samt gültigem Ziel vorbereitet wurde, sonst 0.
 * - Wichtige Variablen: Die Zaubertabelle d_1a7270 (Eintragsgröße 14 Bytes) definiert in Byte 7 die erlaubte
 *   Zielkategorie (0 = Selbstzauber, 1 = Monster, 2 = Held, 3 = Figur, 4 = freies Feld/Wand) und in Byte 8 das
 *   Fernzauber-Flag.
 === Ende Beschreibung === */
short f_082920(int p1, int p2, short p3, short p4)
{
    signed char j; // Kopierrest-Lokale, haelt die Register- und Stapelplatzfolge
    short res;
    char *e;
    int ok;
    int msg;
    short k = 0;
    unsigned char sel = 0;
    OBJ_BEGIN;
    res = 0;
    if (f_042a10((struct hero *)(p2)) == 0) {
        msg = 0x1010038;
        MSG(msg);
    } else if (f_043410(p2) >= 5) {
        f_042800((struct hero *)(p2), 0xd);
        f_0432c0((struct hero *)(p2), 0xff);
        f_0433c0(p2, f_03cd00(p2, 0));
        if (f_0433d0(p2) > 0) {
            e = d_1a7270 + f_0433d0(p2) * 0xe;
            if (SB(e, 7) != 0) {
                short y, x;
                x = p3;
                y = p4;
                k = 1;
                if (SB(e, 8) > 0) k = 99;
                sel = f_0738a0(p1, &x, &y, k, 1, 1, 5);
                ok = 1;
                if (sel == (unsigned char)0xff) ok = 0;
                else if (sel >= 0x32) {
                    if (f_0433d0(p2) == 4 && sel == 0x9a) {
                        f_042800((struct hero *)(p2), 4);
                        f_0432c0((struct hero *)(p2), 0);
                        f_043c20(p2, x);
                        res = 1;
                        f_043c40(p2, y);
                    } else { MSG(0x101001d); ok = 0; }
                } else if (sel == 0) {
                    if (SB(e, 7) != 4) { MSG(0x1010005); ok = 0; }
                } else if (sel < 10 && SB(e, 7) != 2 && SB(e, 7) != 3) { MSG(0x1010006); ok = 0; }
                else if (!(sel < 10 || sel >= 0x32 || SB(e, 7) == 1 || SB(e, 7) == 3)) { MSG(0x1010007); ok = 0; }
                { short z = res; res = z; } // haelt die Stapelplatzsortierung fuer p4 und y
                { short z = res; res = z; } // haelt die Stapelplatzsortierung fuer p4 und y
                if (res == 0 && ok) {
                    if ((f_0433d0(p2) != 0x28 && sel >= 10 && sel < 0x1e && f_0cff80(EN(sel - 10))) || (sel >= 0x1e && sel < 0x32 && f_0cff80(EN(sel - 0x1e)))) {
                        if (sel < 0x1e) k = 10; else k = 0x1e;
                        I(obj.slots[1], 4) = EN(sel - k);
                        W(obj.slots[6], 2) = 1;
                        MSG(0x1010053);
                    } else if ((sel >= 1 && sel < 10 && ((char)(f_042470((struct hero *)(EM(sel - 1)))))) || (sel >= 10 && sel < 0x1e && f_0433d0(p2) != 0x17 && f_072a00(EN(sel - 10)) == 0) || (sel >= 0x1e && sel < 0x32 && f_0433d0(p2) != 0x17 && f_072a00(EN(sel - 0x1e)) == 0)) {
                        MSG(0x101001e);
                    } else {
                        f_042800((struct hero *)(p2), 4);
                        f_0432c0((struct hero *)(p2), sel);
                        f_043c20(p2, x);
                        res = 1;
                        f_043c40(p2, y);
                    }
                }
            } else {
                f_042800((struct hero *)(p2), 4);
                f_0432c0((struct hero *)(p2), 0);
                f_043c20(p2, p3);
                res = 1;
                f_043c40(p2, p4);
            }
        }
        if (f_0433d0(p2) > 0 && f_042810((struct hero *)(p2)) == 4) {
            if (f_10cae0(f_0433d0(p2), 1) > f_0429a0((struct hero *)(p2))) {
                MSG(0x101003a);
                res = j ^ j; // bindet j fuer die Registerfolge und setzt res auf 0
                f_042800((struct hero *)(p2), 0xd);
            }
        }
    } else {
        msg = 0x1010012;
        I(obj.slots[0], 4) = p2;
        MSG(msg);
    }
    return res;
}
//@ f_082d30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt den Helden (p2, ab 3 AP) den Gegenstand in seiner linken Hand (Slot 12) im Kampf
 *   einsetzen: Handelt es sich um ein Wurfgeschoss oder Wurfelexier aus der Liste d_1a489a (z. B. Hylailer Feuer
 *   oder Stinktöpfchen), wählt der Spieler über f_0738a0 ein Ziel auf dem Schlachtfeld aus; handelt es sich um
 *   einen benutzbaren Trank oder Gegenstand (f_0a7970 / f_0a7930), wird der Held selbst als Ziel eingetragen und
 *   die Aktion 5 (Gegenstand benutzen) für 3 AP vorgemerkt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2 sowie dessen Koordinaten
 *   p3 (X) und p4 (Y) und gibt 1 bei erfolgreicher Vorbereitung zurück, sonst 0.
 * - Wichtige Variablen: Die Liste d_1a489a enthält die Gegenstands-IDs aller im Kampf werfbaren Projektile und
 *   Flaschen.
 === Ende Beschreibung === */
short f_082d30(int p1, int p2, short p3, short p4)
{
    short it; short k;
    unsigned char sel;
    int msg;
    short ret = 0;
    short x;
    int t_310;
    short y;
    short s;
    int ok;
    it = f_042a60((struct hero *)(p2), 0xc);
    { int *z = (p2 & 0) ? (int*)0 : (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = z; } // haelt d_1c2c40-Verwendung fuer die Registerfolge vor Ctor
    OBJ_BEGIN;
    { int *z = (p2 & 0) ? (int*)((short)p2 + (short)ok) : (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = z; } // haelt d_1c2c40-Verwendung fuer die Registerfolge nach Ctor
    ok = 1;
    t_310 = f_043410(p2);
    if (t_310 >= 3) {
        if (it == (short)0) {
            MSG(0x1010047);
        } else if (f_149360(it, d_1a489a) != -1) {
            x = p3;
            y = p4;
            sel = f_0738a0(p1, &x, &y, 99, 2, 0, 3);
            s = sel;
            if (s == 0xff) ok = 0;
            else if (s == 0xfe) { MSG(0x101001d); ok = 0; }
            else if (s == 0) { MSG(0x101004b); ok = 0; }
            if (ok) {
            if ((s >= SH(10) && s < SH(0x1e) && f_0cff80(EN(s - 10))) || (s >= SH(0x1e) && f_0cff80(EN(s - 0x1e)))) {
                k = s < SH(0x1e) ? (short)10 : (short)0x1e;
                int rhs = k;
                I(obj.slots[1], 4) = EN(s - rhs);
                W(obj.slots[6], 2) = 1;
                MSG(0x1010053);
            } else if ((s >= SH(1) && s < SH(10) && ((char)(f_042470((struct hero *)(EM(s - 1)))))) || (s >= SH(10) && s < SH(0x1e) && f_072a00(EN(s - 10)) == 0) || (s >= SH(0x1e) && f_072a00(EN(s - 0x1e)) == 0)) {
                MSG(0x101001e);
            } else {
                f_042800((struct hero *)(p2), 5);
                f_0432c0((struct hero *)(p2), (unsigned char)s);
                f_043c20(p2, x);
                f_043c40(p2, y);
                f_043430(p2, -3);
                ret = 1;
            }
            }
        } else {
            if (!((RivaItemDefinition*)(ITEM(it)))->f_0a7970() && ((RivaItemDefinition*)(ITEM(it)))->f_0a7930() == 0) {
                if (((RivaItemDefinition*)(ITEM(it)))->f_0a7ad0()) {
                    I(obj.slots[2], 4) = ITEM(it);
                    W(obj.slots[7], 2) = 1;
                    MSG(0x101005b);
                } else {
                    I(obj.slots[2], 4) = ITEM(it);
                    W(obj.slots[7], 2) = 1;
                    MSG(0x101005c);
                }
            } else {
                f_030850(p2, p2);
                f_042800((struct hero *)(p2), 5);
                f_043430(p2, -3);
                ret = 1;
            }
        }
    } else {
        I(obj.slots[0], 4) = p2;
        MSG(0x1010012);
    }
    return ret;
}

//@ f_083060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für den Helden (p2, ab 2 AP) ein Auswahlmenü aller im Rucksack (Slots 15..30)
 *   mitgeführten Gegenstände (plus einer Leerslot-Option zum Wegstecken) und tauscht nach Auswahl des Spielers
 *   den Gegenstand in der linken Hand (Slot 12) für 2 Aktionspunkte über f_032ab0 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das lokale Array tab[16] ordnet die Menüzeilen den tatsächlichen Inventarslots 15..30
 *   zu.
 === Ende Beschreibung === */
void f_083060(int p1, int p2)
{
    int first;
    short n, i, it;
    int k;
    int msg;
    short sel, sv;
    first = 1;
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    short tab[16];
    if (f_043410(p2) >= 2) {
        n = 0;
        for (i = 0xf; i < 0x1f; i++) {
            it = f_042a60((struct hero *)(p2), i);
            if (it || first != 0) {
                if (!it) first = 0;
                k = n;
                tab[k] = i;
                f_0a7840((RivaItemDefinition *)(ITEM(it)),(char *)( d_1c21b4 + k * 0x28), 1);
                d_1c29c4[k] = f_133fe0(d_1c3498, d_1c21b4 + k * 0x28);
                n++;
            }
        }
        if (!n) {
            I(obj.slots[0], 4) = p2;
            MSG(0x101003b);
        } else {
            it = f_042a60((struct hero *)(p2), 0xc);
            if (!it) {
                I(obj.slots[0], 4) = p2;
                msg = 0x1010030;
            } else {
                I(obj.slots[0], 4) = p2;
                I(obj.slots[2], 4) = ITEM(it);
                W(obj.slots[7], 2) = (((RivaItemDefinition*)(ITEM2(it)))->f_0a7950() && f_042ac0((struct hero *)(p2), 0xc) > 1) ? f_042ac0((struct hero *)(p2), 0xc) : 1;
                msg = 0x1010020;
            }
            sv = f_0c0020(d_1c2c64, 6);
            sel = MENU(msg, n);
            f_0c0020(d_1c2c64, sv);
            if (sel != -1) {
                if (f_032ab0(p2, 0xc, tab[sel - 1]) == 1) f_043430(p2, -2);
            }
        }
    } else {
        I(obj.slots[0], 4) = p2;
        MSG(0x1010012);
    }
}
//@ f_0832b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet für den Helden (p2, ab 2 AP) das Waffenwechsel-Menü mit allen im Rucksack (Slots
 *   15..30) vorhandenen, vom Helden führbaren Waffen (mit Zusatzhinweisen bei zerbrochenen oder vergifteten
 *   Waffen sowie einer Option für den waffenlosen Kampf), tauscht nach Auswahl den Waffenslot 3 für 2 AP über
 *   f_032ab0 aus und aktualisiert bei einem Wechsel zwischen Nah- und Fernkampfwaffe die Kampffigur-Grafik
 *   (f_06ed10).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie den Heldenzeiger p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Über f_042bb0 und f_042fd0 werden zerbrochene bzw. vergiftete Waffen im Auswahlmenü mit
 *   den Textzusätzen 0x101003c und 0x1010048 gekennzeichnet.
 === Ende Beschreibung === */
void f_0832b0(int p1, int p2)
{
    int first;
    short n, i, it;
    short k;
    char *buf;
    int msg;
    int sel, sv, before;
    first = 1;
    struct LocalObj { RivaTextContext ob; short tab[16]; LocalObj() : ob(d_1c349c, d_1c3870, d_1c3498) {} } obj;
    if (!f_042a60((struct hero *)(p2), 3)) first = 0;
    if (f_043410(p2) >= 2) {
        n = 0;
        for (i = 0xf; i < 0x1f; i++) {
            it = f_042a60((struct hero *)(p2), i);
            if (((RivaItemDefinition*)(ITEM(it)))->f_0a7990() == 0) goto L379;
            if (f_045960(p2, it) == 0) goto L379;
            if (((signed char)(((RivaItemDefinition*)(ITEM(it)))->f_0a78b0())) == 0) goto L379;
            goto L385;
L379:
            if (!it && first != 0) goto L385;
            continue;
L385:
            if (!it) first = 0;
            k = n;
            obj.tab[k] = i;
            buf = d_1c21b4 + k * 0x28;
            f_0a7840((RivaItemDefinition *)(ITEM(it)),(char *)( d_1c27a8), 1);
            f_14572e(buf, d_1b6f6c, d_1c27a8);
            d_1c29c4[k] = f_133fe0(d_1c3498, buf);
            if (f_042bb0((struct hero *)(p2), i)) {
                strcat(buf, d_1b6f6f);
                f_0e9300(d_1c38b0, buf, 0x101003c);
            }
            if (f_042fd0((struct hero *)(p2), i)) {
                strcat(buf, d_1b6f71);
                f_0e9300(d_1c38b0, buf, 0x1010048);
            }
            n++;
        }
        if (!n) {
            I(obj.ob.slots[0], 4) = p2;
            MSG(0x1010002);
        } else {
            I(obj.ob.slots[0], 4) = p2;
            it = f_042a60((struct hero *)(p2), 3);
            int *table = (*(int **)&d_1c2c40);
            before = table[it];
            I(obj.ob.slots[2], 4) = before;
            W(obj.ob.slots[7], 2) = 1;
            if (f_042bb0((struct hero *)(p2), 3)) msg = 0x101003c;
            else {
                msg = f_042a60((struct hero *)(p2), 3);
                if (msg) msg = 0x10100a1;
                else msg = (f_042960((struct hero *)(p2)) != f_042970((struct hero *)(p2))) + 0x10100a3;
            }
            I(obj.ob.slots[3], 4) = msg;
            sv = ((int (*)(void *, int))f_0c0020)(d_1c2c64, 6);
            sel = ((int (*)(void *, ...))f_0bf820)(d_1c2c64, 0x1010003, n, d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7], d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15]);
            f_0c0020(d_1c2c64, (short)sv);
            if ((short)sel != -1) {
                int oldPosition = ((int (*)(int))f_030d80)(p2);
                if (f_032ab0(p2, 3, obj.tab[(short)sel - 1]) == 1) {
                    f_043430(p2, -2);
                    if ((short)oldPosition != (short)f_030d80(p2)) f_06ed10(p1, p2, p1 + 0x45);
                }
            }
        }
    } else {
        I(obj.ob.slots[0], 4) = p2;
        MSG(0x1010012);
    }
}
