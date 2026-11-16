/* === Beschreibung (Katalog) ===
 * Einheit mine1_t4 (Adresse 0x0c5490 - 0x0c5d80)
 *
 * Diese Einheit bildet den vierten und abschließenden Teil des 3D-Dungeon-Moduls für die erste Ebene der
 * Zwergenmine (p:\riva\source\cpp\mine1.cpp). Sie enthält die Ereignisse rund um den Aufzug bzw. Übergang in die
 * tiefere Minenebene (mine2, Kennung 0x13a3) sowie die gemeinsam genutzten Hilfsroutinen zum Durchsuchen der
 * Zwergenspinde (f_0c5b70) und zum Rasten in den Zwergenbetten (f_0c5ac0, f_0c5b20).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 12/12 gleich (suche.py 29.10.2026, Basis mine1_t4_P1.CPP)
// mine1_t4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C5490-0x0C5D80
#include <string.h>
#include "RIVAMEM.H"



inline int EQ(int a, int b) { return a == b; }
#define EQI(x,v) (((x)==(v))?1:0)
struct SO { char a[4]; int *p4; char b[4]; int *pc; char c[4]; short *p14; char d[8]; short *p20; char e[24]; };
struct TE { int id; unsigned short k; short n; };
struct VT { short (*fn)(int, int, int); };
struct Obj { char pad[8]; VT *vt; };
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039660(int p1, int p2);
int f_0396f0(int p1, int p2);
short f_0398c0(int p1, int (*p2)(int), void *p3);
int f_039c50(int p1, int p2);
int f_03af20(int p1, int p2, int p3);




int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
int f_044890(int p1, int p2);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_0697c0(int p1, int p2, int p3);
int f_0bbf00(char *p1);
int f_0bf6f0(char *p1, int p2);
int f_0bf730(char *p1, int p2);
short f_0db820(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcf00(int p1, int p2, int p3);
int f_0dd7f0(int p1, int p2, int p3);
int f_0e93f0(char *p1, char *p2, int p3);
int f_125400(void *p1, char *p2, char *p3, char *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(char *p1, int p2);
int f_125f70(char *p1, int p2, void *p3);
int f_133fe0(char *p1, char *p2);
int f_134840(void *p1, int p2, int p3, int p4, int p5, int p6);
int f_135040(void *p1);
int f_1348d0(void *p1, int p2);
int f_145760(int p1, int p2);
int f_1457e0(int p1);
int f_147323(char *p1, int p2, int p3, int p4, int p5, int p6, int p7);
extern TE d_1a5600[];
extern int d_1a9820;
extern signed char d_1bd6c8;
extern short d_1bd922;
extern char d_1bf230[];
extern char d_1bf250;
extern signed char d_1bf268;
extern char d_1bf274;
extern signed char d_1bf28c;
extern signed char d_1bf2a0;
extern int d_1bf2ac;
extern int d_1c0004;
extern char d_1c21b4[];
extern char d_1c2c44[];

extern char d_1c2c64[];
extern char d_1c2edc[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
void f_0c5830(int p1);
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0c5490
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein einmaliges Prüfungsereignis (0x6a9, Flag d_1bf2a0), bei dem der Held mit
 *   dem höchsten Wert in Eigenschaft 0x0c (12) eine um 4 Punkte erleichterte Probe (f_044900(r, 0xc, -4))
 *   ablegt: Bei Erfolg sinkt dieser Wert um 1 (f_03af20), und der Durchgang 0x1f41 (f_0607e0) wird freigegeben.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5490()
{
    SO o;
    int r;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    r = f_039660(d_1c0004, 0xc);
    o.p4[1] = r;
    if (EQB(d_1bf2a0, 0)) {
        f_0bf730(d_1c2c64, 0x35000083);
        if (f_044900(r, 0xc, -4) > 0) {
            f_0bf730(d_1c2c64, 0x35000084);
            if (f_0db9a0(d_1c0004) > 1) {
                o.p4[2] = f_039c50(d_1c0004, r);
                f_0bf730(d_1c2c64, 0x35000085);
            }
            f_03af20(r, 0xc, -1);
            d_1bf2a0 = 1;
            f_060740(0x6a9, 1);
            f_0607e0(0x1f41, 1);
            f_125ed0(d_1c2c44, 10);
            f_1254a0(&o, 0);
            return;
        }
        r = 0x35000086;
    } else {
        r = 0x35000087;
    }
    f_0bf730(d_1c2c64, r);
    f_1254a0(&o, 0);
}
//@ f_0c55d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt das Ereignis am Schacht oder Förderkorb (0x709) ab: Beim ersten Betreten
 *   (d_1bf28c == 0) stürzt der ungeschickteste Held (f_0396f0(d_1c0004, 0)) unter einem Geräusch (0x350033)
 *   beinahe ab, erleidet 2W6+5 bzw. 3W6+5 Schadenspunkte (f_044850) und schaltet die Felder 0x1f44 bis 0x1f46
 *   frei; anschließend fragt die Funktion den Spieler, ob die Gruppe den Abstieg bzw. Aufzug benutzen will
 *   (0x350002, f_0c5830).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#pragma aux f_147323 modify [esp];
void f_0c55d0(int p1)
{
    int a = 0;
    short s = 0;
    SO o;
    int b = 0;
    short c;
    int k;
    int m;
    int snd;
    a = f_038c40(d_1c0004);
    s = f_0db9a0(d_1c0004);
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    if (EQB(d_1bf28c, 0)) {
        k = f_039320(d_1c0004, 0x33);
        b = f_0396f0(d_1c0004, 0);
        f_039660(d_1c0004, 0xc);
        c = ((f_0423c0((struct hero *)(b)) <= 5) ? 1 : 0) + 2;
        o.p4[1] = k;
        f_0bf730(d_1c2c64, 0x35000088);
        o.p4[1] = b;
        f_0bf730(d_1c2c64, 0x35000089);
        snd = d_1a9820;
        f_147323(d_1c2edc, 0x350033, 0x7fff, 0x8000, snd, 0, 1);
        f_0bf730(d_1c2c64, 0x3500008a);
        f_044850(b, c, 5);
        f_060740(0x70b, 1);
        f_0607e0(0x1f44, 1);
        f_0607e0(0x1f45, 1);
        f_0607e0(0x1f46, 1);
        f_0bbf00(d_1bf230);
    }
    o.p4[1] = a;
    if (EQB(d_1bf28c, 0)) {
        d_1bf28c = 1;
        if (s == 1) m = 0x3500008b;
        else m = 0x3500008c;
    } else {
        if (s == 1) m = 0x3500008d;
        else m = 0x3500008e;
    }
    f_0e93f0(d_1c38b0, d_1c21b4, m);
    if (f_0bf6f0(d_1c2c64, f_133fe0(d_1c3498, d_1c21b4)) == 1) {
        if (s != 1) f_0bf730(d_1c2c64, 0x3500008f);
        f_060800(0x350002, 0, 0);
        if (EQB(d_1bf268, 0)) {
            f_0c5830(p1);
            d_1bf268 = 1;
        }
    }
    f_1254a0(&o, 0);
}
//@ f_0c5800
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler (0x35000092), ob er die Vorrichtung betätigen möchte, und löst bei
 *   Zustimmung die Kartenaktion 0x350004 (f_060800) aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5800()
{
    if (f_0bf6f0(d_1c2c64, 0x35000092) == 1) f_060800(0x350004, 0, 0);
}
//@ f_0c5830
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion leitet nach einer Kampf- oder Ereignisprüfung (vt->fn(p1, 0x38, 0)) den Ebenenwechsel
 *   von der ersten in die zweite Ebene der Zwergenmine (0x13a3 über f_0dd7f0) ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5830(int p1)
{
    SO o;
    int v;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    v = f_038c40(d_1c0004);
    o.p4[1] = v;
    if (f_0db9a0(d_1c0004) > 1) f_0bf730(d_1c2c64, 0x35000090);
    else f_0bf730(d_1c2c64, 0x35000091);
    d_1bd922 = ((EQ(d_1bd6c8, 1) != 0) ? 1 : 0) + 2;
    if (((Obj *)p1)->vt->fn(p1, 0x38, 0) == 1) f_0dd7f0(d_1c0004, 0x10, 0x13a3);
    f_1254a0(&o, 0);
}
//@ f_0c58f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler (0x35000093), ob die Gruppe in den nächsten Minenbereich
 *   hinabsteigen möchte, und wechselt bei Zustimmung zur Ebene 0x13a3 (f_0dd7f0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c58f0()
{
    if (f_0bf6f0(d_1c2c64, 0x35000093) == 1) f_0dd7f0(d_1c0004, 0x10, 0x13a3);
}
//@ f_0c5920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Text 0x35000014 aus, schaltet das Hindernis 0x37 über die virtuelle
 *   Dungeon-Methode und f_0697c0 frei und markiert das Ereignis 0x191 als erledigt (d_1bf250 = 1, d_1bf274 = 0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5920(int p1)
{
    f_0bf730(d_1c2c64, 0x35000014);
    ((Obj *)p1)->vt->fn(p1, 0x37, 0);
    f_0697c0(p1 + 2, 0x37, 0);
    f_060740(0x191, 0);
    d_1bf250 = 1;
    d_1bf274 = 0;
}
//@ f_0c5980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird beim gewaltsamen oder mechanischen Öffnen einer bestimmten Tür/Truhe aus
 *   gz_0b9940 (f_0ba0b0) aufgerufen und gibt mit dem Namen des Gruppenanführers die Meldung 0x3500002f aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5980()
{
    SO o;
    int v;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    v = f_038c40(d_1c0004);
    o.p4[1] = v;
    f_0bf730(d_1c2c64, 0x3500002f);
    f_1254a0(&o, 0);
}
//@ f_0c59d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion öffnet für die übergebene Gegenstandskennung p1 das
 *   Gegenstands-Informationsfenster (f_134840, f_135040, f_1348d0).
 * - Eingaben: Die Funktion nimmt die Gegenstandskennung p1 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c59d0(int p1)
{
    char l[32];
    f_134840(l, 0, 0, 0, (short)p1, 0);
    f_135040(l);
    f_1348d0(l, 0);
}
int f_0bf820(char *p1, ...);
void f_0c5b70(int p1, int p2);
int f_0c5ac0(int p1);
//@ f_0c5a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese allgemeine Quartier-Menüfunktion fragt den Spieler (0x35000065), ob die Gruppe den Spind mit
 *   der Bitmaske p2 durchsuchen (f_0c5b70), 5 Stunden in den Zwergenbetten rasten (f_0c5b20) oder weitergehen
 *   möchte.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt sowie die Spind-Bitmaske p2
 *   entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5a20(int p1, int p2)
{
    char buf[28];
    char *q;
    switch ((short)f_0bf820(d_1c2c64, 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068)) {
    case -1:
        break;
    case 1:
        f_0c5b70(p1, p2);
        return;
    case 2:
        f_0bf730(d_1c2c64, 0x3500006e);
        ;
        ((int (*)(char *, int))f_125f70)(d_1c2c44, 5);
        q = buf;
        if (f_0398c0(d_1c0004, f_0c5ac0, q) > 0) f_0bf730(d_1c2c64, 0x3500006f);
        break;
    case 3:
        break;
    }
}
//@ f_0c5ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Callback-Funktion wird beim 5-stündigen Rasten in den kurzen Zwergenbetten für jeden lebenden
 *   und handlungsfähigen Helden p1 aufgerufen: Ist der Held ein Zwerg (f_042350 == 6), erholt er sich um 5
 *   Punkte (f_044890(p1, 5)) und die Funktion gibt 0 zurück; alle größeren Rassen (!= 6) finden in den kurzen
 *   Betten keinen Platz (f_044890(p1, 2)) und liefern 1 zurück, sodass anschließend die Beschwerdemeldung
 *   0x3500006f erscheint. *(Hinweis: Für tote oder bewusstlose Helden bleibt die lokale Rückgabevariable r
 *   uninitialisiert, siehe FEHLERLISTE_RIVA_GEM2.md.)*
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 für Nicht-Zwerge und 0 für Zwerge zurück (bzw. einen uninitialisierten
 *   Wert bei nicht handlungsfähigen Helden).
 === Ende Beschreibung === */
int f_0c5ac0(int p1)
{
    int r;
    if (f_042350((struct hero *)(p1))) {
        if (!((char)(f_042470((struct hero *)(p1))))) {
            if (!((char)(f_0424e0((struct hero *)(p1))))) {
                if (f_042350((struct hero *)(p1)) == 6) {
                    f_044890(p1, 5);
                    r = 0;
                } else {
                    r = 1;
                    f_044890(p1, 2);
                }
            }
        }
    }
    return r;
}
//@ f_0c5b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion führt die 5-stündige Rast in einem Zwergenquartier durch (0x3500006e, f_125f70),
 *   prüft alle Helden über f_0c5ac0 und gibt die Meldung 0x3500006f aus, sobald mindestens ein Nicht-Zwerg in
 *   der Gruppe ist.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5b20()
{
    char buf[28];
    char *q;
    f_0bf730(d_1c2c64, 0x3500006e);
    ((int (*)(char *, int))f_125f70)(d_1c2c44, 5);
    q = buf;
    if (f_0398c0(d_1c0004, f_0c5ac0, q) > 0) f_0bf730(d_1c2c64, 0x3500006f);
}
//@ f_0c5b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht den durch die Bitmaske p2 bezeichneten Zwergenspind in der Tabelle
 *   d_1a5600: Zunächst muss der Gruppenanführer eine erschwerte Probe auf Talent 10 (+8, z. B. Verstecken/Suchen
 *   oder Schlösser/Fallen) bestehen, andernfalls verletzt er sich an einer Schnappfalle um 1W4 Schadenspunkte
 *   (0x3500006d, f_044300). Bei Erfolg findet die Gruppe je nach Spindtyp k entweder einen bestimmten Gegenstand
 *   (k == 0, d_1a5600[i].n), 2 bis 4 Silbertaler (k == 1, 200-400 Heller) oder einen leeren Spind (k == 2), und
 *   das entsprechende Bit in d_1bf2ac wird als geplündert markiert.
 * - Eingaben: Die Funktion nimmt den ungenutzten Dungeon-Zeiger p1 sowie die Spind-Bitmaske p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c5b70(int p1, int p2)
{
    short i = 0;
    SO o;
    unsigned short k;
    short mask;
    for (; d_1a5600[i].id != p2; i++) { }
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    o.p4[1] = f_038c40(d_1c0004);
    if (f_044c90(f_038c40(d_1c0004), 10, 8) <= 0) {
        o.p4[1] = f_038c40(d_1c0004);
        f_0bf730(d_1c2c64, 0x3500006d);
        f_044300(f_038c40(d_1c0004), (short)f_1457e0(4));
    } else {
        k = d_1a5600[i].k;
        mask = *(unsigned short *)&d_1bf2ac & p2;
        switch ((unsigned short)(k & 0xffff)) {
        case 2:
            f_0bf730(d_1c2c64, 0x3500006c);
            f_1254a0(&o, 0);
            return;
        case 0:
            if (mask) {
                f_0bf730(d_1c2c64, 0x3500006a);
            } else {
                o.p20[1] = 1;
                o.pc[1] = (*(int **)&d_1c2c40)[d_1a5600[i].n];
                f_0bf730(d_1c2c64, 0x35000069);
                f_0dcf00(d_1c0004, d_1a5600[i].n, 1);
                *(short *)&d_1bf2ac |= (short)p2;
            }
            f_1254a0(&o, 0);
            return;
        case 1:
            if (mask) {
                f_0bf730(d_1c2c64, 0x3500006c);
            } else {
                short s = f_145760(2, 4);
                o.p14[1] = s;
                f_0bf730(d_1c2c64, 0x3500006b);
                f_0db820(d_1c0004, (short)s * 100);
                *(short *)&d_1bf2ac |= (short)p2;
            }
            f_1254a0(&o, 0);
            return;
        }
    }
    f_1254a0(&o, 0);
}
