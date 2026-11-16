/* === Beschreibung (Katalog) ===
 * Einheit gz_0f5250_t2
 *
 * Diese Einheit bildet den zweiten Teil der Kanalisations-Ereignissteuerung (gz_0f5250, Teil 2) und enthält
 * weitere Spezialszenen, Rätsel- und Beuteinteraktionen sowie die zeit- und schrittabhängige Aktualisierung
 * dieses Kanalabschnitts.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 12/13 gleich (suche.py 26.10.2026, Basis gz_0f5250_t2_P1.CPP)
// gz_0f5250_t2 (0F6400-0F6FB0) - Pass 1 Helfer B
#include <string.h>
int f_039040(int p1);
int f_039660(int p1, int p2);
int f_039a80(int p1, int p2);
signed char f_042400(int p1);
signed char f_0425f0(int p1);
int f_042960(int p1);
int f_043e20(int p1, int p2);
int f_044300(int p1, int p2);
int f_044890(int p1, int p2);
int f_060030(int p1, int p2);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dd7f0(int p1, int p2, int p3);
short f_0de820(int p1);
int f_0de9d0(int p1, int p2);
int f_0de9f0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_145234(int p1, int p2);
int f_145254(void);
typedef RivaTextContextData OB;
struct T { char a; short b; };
extern int d_1c0004;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c3498;
extern signed char d_1c020c;
extern signed char d_1bdd0c;
extern char d_1c0214;
extern char d_1bb6c4[];
extern int *d_1c212c;
extern short d_1c212a;
extern T d_1c0220;
extern T d_1c0224;
extern T d_1c0228;
extern T d_1c022c;
extern T d_1c0230;
extern T d_1c0234;
extern T d_1c0238;
extern T d_1c023c;
extern T d_1c0240;
extern T d_1c0244;
extern T d_1c0248;
extern T d_1c024c;
extern T d_1c0250;
extern T d_1c0254;
extern T d_1c0258;
extern T d_1c025c;
extern T d_1c0260;
extern T d_1c0264;
extern T d_1c0268;
extern T d_1c026c;
extern T d_1c0270;
extern T d_1c0274;
extern T d_1c0278;
extern T d_1c027c;
extern T d_1c0280;
extern T d_1c0284;
extern T d_1c0288;
extern T d_1c028c;
extern T d_1c0290;
#define P(k) f_0bf730((int)&d_1c2c64, k)
#define EQI(x,v) (((x)==(v))?1:0)
void f_0f6ea0(int p1);
void f_0f6ee0(int p1);
int f_038c40(int p1);
int f_038d70(int p1, int p2);
int f_040a00(int p1, int p2, int p3);
int f_041030(int p1, ...);
int f_041530();
int f_041920(int p1);
int f_044850(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
short f_0bf820(int p1, ...);
short f_0d4cd0(int p1, int p2);
int f_0db9d0(int p1, int p2, int p3);
int f_0dc020(int p1, int p2);
int f_0dcd30(int p1, int p2, int p3);
int f_0dd100(int p1, int p2);
int f_0dd750(int p1, int p2);
short f_0de7f0(int p1);
int f_039c50(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern signed char d_1c01fc;
extern volatile short d_1c219c; // haelt das Schreiben in f_0f6550 wie im Original
extern int d_1c2c44;
extern int d_1c2edc;
extern int d_1a9820;
//@ f_0f6400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine Untersuchungsszene an einem besonderen Fundort in der Kanalisation, fragt
 *   ab, welcher Held zugreift, und vergibt bei Erfolg Beutegegenstände oder Abenteuerpunkte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Status nach Abschluss der Szene zurück.
 === Ende Beschreibung === */
void f_0f6400(void)
{
    OB ob;
    int m;
    f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    if (EQI(d_1c020c, 0)) {
        *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 7);
        P(0x250000ad);
        d_1c020c = 1;
    }
    if (EQI(d_1bdd0c, 1) || (f_039040(d_1c0004) != 0 && f_042400(f_039040(d_1c0004)) == 6))
    {
        if (f_0bf6f0((int)&d_1c2c64, 0x250000ae) == 1) {
            if (f_0db9a0(d_1c0004) < 3) {
                P(0x250000af);
            } else {
                d_1c0214 = 0;
                f_0dd7f0(d_1c0004, 3, 0x1391);
            }
        }
    }
    else
        P(0x250000b0);
    f_1254a0((int)&ob, 0);
}
//@ f_0f6500
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert den Zustand eines Gittertors oder Durchgangs im 3D-Kartenmodell der
 *   Kanalisation und spielt das zugehörige Öffnungs- oder Schließgeräusch ab.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Kartenaktualisierung zurück.
 === Ende Beschreibung === */
short f_0f6500(void)
{
    short r;
    short s;
    s = f_0d54f0(d_1c0004, 0x167);
    r = -1;
    if (s != -1) {
        r = 0x167;
    } else {
        s = f_0d54f0(d_1c0004, 0x79);
        if (s != -1) r = 0x79;
    }
    return r;
}
//@ f_0f6550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt eine mehrteilige Begegnung oder Falle in einer Kanalkammer ab, prüft Schutz-
 *   und Attributwerte der Helden und teilt bei einem Fehlschlag Schaden oder Krankheits-/Giftzustände aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Ergebniswert der Begegnung zurück.
 === Ende Beschreibung === */
struct OBC { int a; int b; int x1; int x2; int c; int rest[10]; OBC(int,int,int); ~OBC(); };
void f_0f6550(int p1, unsigned short p2)
{
    int snd; // haelt die lokale Symbolreihenfolge vor ob fuer die Registervergabe wie im Original
    OBC ob((int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498);
    short C = -1;
    int o, g, v2, v1 = 0;
    signed char cc;
    if (EQI(d_1c01fc, 0)) {
        if (f_0bf820((int)&d_1c2c64, 0x2500008f, 2, 0x25000090, 0x25000091) == (short)1) {
            if (f_0db9a0(d_1c0004) > 1) {
                short r = C;
                short s = f_0d54f0(d_1c0004, 0x167);
                if (s != -1) r = 0x167;
                else {
                    s = f_0d54f0(d_1c0004, 0x79);
                    if (s != -1) r = 0x79;
                }
                C = r;
                o = f_038d70(d_1c0004, 0x25000092);
                if (C != -1 && o != 0) {
                    *(int *)(ob.b + 4) = o;
                    if (f_0bf6f0((int)&d_1c2c64, 0x25000093) != 1) C = -1;
                }
            } else {
                o = f_038c40(d_1c0004);
            }
            if (o != 0) {
                int g0 = 0;
                cc = 0xc;
                g = d_1c0004;
                g0 = g;
                int t_179 = f_0de7f0(g);
                if (t_179 > 1) {
                    g = f_041030(1, o);
                    f_041920(g);
                }
                if (C != -1) {
                    if (C == 0x167) cc -= 5; else cc -= 2;
                }
                v1 = v2 = (f_0d4cd0(o, 0x10) != -1);
                f_147323((int)&d_1c2edc, 0x250021, 0x7fff, 0x8000, (snd = d_1a9820), 0, 1);
                if (f_044c90(o, 0xe, cc) > 0 || v1 == 1) {
                    *(int *)(ob.b + 4) = o;
                    if (v2 == 1) P(0x25000094); else P(0x25000095);
                    f_040a00(o, 2, 4);
                    if (C != -1) {
                        *(int *)(ob.b + 8) = f_038c40(g0);
                        P(0x25000096);
                        P(0x25000097);
                        f_041530();
                        f_0db9d0(d_1c0004, 2, 2);
                        d_1c01fc = 1;
                        f_0dd100(d_1c0004, C);
                        f_0dd750(d_1c0004, p2);
                    } else {
                        f_0dd750(g, p2);
                    }
                } else {
                    *(int *)(ob.b + 4) = o;
                    P(0x25000098);
                    f_044850(o, (short)f_042960(o), 4);
                    if (C != -1) {
                        f_041530();
                        if (f_0de7f0(d_1c0004) > 1) {
                            *(int *)(ob.b + 8) = f_039c50(d_1c0004, o);
                            P(0x25000099);
                            P(0x2500009a);
                            return;
                        }
                    } else {
                        if (g != g0) {
                            f_125ed0((int)&d_1c2c44, 10);
                            P(0x2500009b);
                        }
                        v1 = f_0dc020(d_1c0004, o);
                        f_0dcd30(g, (short)v1, -1);
                        if (g != g0) {
                            f_041920(g0);
                            goto done_f6550;
                        }
                        d_1c219c = 1;
                        return;
                    }
                }
            }
        }
    } else {
        if (f_0bf6f0((int)&d_1c2c64, 0x2500009c) == 1) {
            f_0dd750(d_1c0004, p2);
            f_0db9d0(d_1c0004, 2, 2);
        }
    }
done_f6550:
    return;
}
//@ f_0f6920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt ein lokales Ereignis- oder Begegnungsflag des Kanalisationsabschnitts auf aktiv.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den gesetzten Statuswert zurück.
 === Ende Beschreibung === */
void f_0f6920(void)
{
    f_060740(0x1f43, 0);
    f_0607e0(0x1f43, 1);
}
//@ f_0f6940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft eine Bedingung für einen geheimen Durchgang oder ein Folgeereignis in der
 *   Kanalisation und schaltet das entsprechende Objekt im Level frei.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Freischaltung zurück.
 === Ende Beschreibung === */
int f_0f6940(int p1, int p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bb6c4);
        f_145254();
        return p1;
    }
    r = f_060030(p1, 1);
    if (p2 & 2) operator delete((void *)r);
    return r;
}
//@ f_0f6980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt eine abschließende Interaktion an einem Ausstieg, Schacht oder Sammelpunkt des
 *   ersten Kanalisationsabschnitts durch, gibt den zugehörigen Ereignistext aus und aktualisiert die
 *   Gruppenposition.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Statuscode der abgeschlossenen Aktion zurück.
 === Ende Beschreibung === */
struct RR700V3_0f69808;
struct OR700V3_0f69808 { signed char flag; short number; char pad; OR700V3_0f69808 *init(RR700V3_0f69808 &r,short id,signed char f); };
struct RR700V3_0f69808 { short count; OR700V3_0f69808 **list; void append(OR700V3_0f69808 *o) {list[count]=o;count++;} };
inline OR700V3_0f69808 *OR700V3_0f69808::init(RR700V3_0f69808 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0f69808 regR700V3_0f69808;
#pragma aux regR700V3_0f69808 "d_1c212a"
extern OR700V3_0f69808 obR700V3_0f6980_1c0220;
#pragma aux obR700V3_0f6980_1c0220 "d_1c0220"
extern OR700V3_0f69808 obR700V3_0f6980_1c0224;
#pragma aux obR700V3_0f6980_1c0224 "d_1c0224"
extern OR700V3_0f69808 obR700V3_0f6980_1c0228;
#pragma aux obR700V3_0f6980_1c0228 "d_1c0228"
extern OR700V3_0f69808 obR700V3_0f6980_1c022c;
#pragma aux obR700V3_0f6980_1c022c "d_1c022c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0230;
#pragma aux obR700V3_0f6980_1c0230 "d_1c0230"
extern OR700V3_0f69808 obR700V3_0f6980_1c0234;
#pragma aux obR700V3_0f6980_1c0234 "d_1c0234"
extern OR700V3_0f69808 obR700V3_0f6980_1c0238;
#pragma aux obR700V3_0f6980_1c0238 "d_1c0238"
extern OR700V3_0f69808 obR700V3_0f6980_1c023c;
#pragma aux obR700V3_0f6980_1c023c "d_1c023c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0240;
#pragma aux obR700V3_0f6980_1c0240 "d_1c0240"
extern OR700V3_0f69808 obR700V3_0f6980_1c0244;
#pragma aux obR700V3_0f6980_1c0244 "d_1c0244"
extern OR700V3_0f69808 obR700V3_0f6980_1c0248;
#pragma aux obR700V3_0f6980_1c0248 "d_1c0248"
extern OR700V3_0f69808 obR700V3_0f6980_1c024c;
#pragma aux obR700V3_0f6980_1c024c "d_1c024c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0250;
#pragma aux obR700V3_0f6980_1c0250 "d_1c0250"
extern OR700V3_0f69808 obR700V3_0f6980_1c0254;
#pragma aux obR700V3_0f6980_1c0254 "d_1c0254"
extern OR700V3_0f69808 obR700V3_0f6980_1c0258;
#pragma aux obR700V3_0f6980_1c0258 "d_1c0258"
extern OR700V3_0f69808 obR700V3_0f6980_1c025c;
#pragma aux obR700V3_0f6980_1c025c "d_1c025c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0260;
#pragma aux obR700V3_0f6980_1c0260 "d_1c0260"
extern OR700V3_0f69808 obR700V3_0f6980_1c0264;
#pragma aux obR700V3_0f6980_1c0264 "d_1c0264"
extern OR700V3_0f69808 obR700V3_0f6980_1c0268;
#pragma aux obR700V3_0f6980_1c0268 "d_1c0268"
extern OR700V3_0f69808 obR700V3_0f6980_1c026c;
#pragma aux obR700V3_0f6980_1c026c "d_1c026c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0270;
#pragma aux obR700V3_0f6980_1c0270 "d_1c0270"
extern OR700V3_0f69808 obR700V3_0f6980_1c0274;
#pragma aux obR700V3_0f6980_1c0274 "d_1c0274"
extern OR700V3_0f69808 obR700V3_0f6980_1c0278;
#pragma aux obR700V3_0f6980_1c0278 "d_1c0278"
extern OR700V3_0f69808 obR700V3_0f6980_1c027c;
#pragma aux obR700V3_0f6980_1c027c "d_1c027c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0280;
#pragma aux obR700V3_0f6980_1c0280 "d_1c0280"
extern OR700V3_0f69808 obR700V3_0f6980_1c0284;
#pragma aux obR700V3_0f6980_1c0284 "d_1c0284"
extern OR700V3_0f69808 obR700V3_0f6980_1c0288;
#pragma aux obR700V3_0f6980_1c0288 "d_1c0288"
extern OR700V3_0f69808 obR700V3_0f6980_1c028c;
#pragma aux obR700V3_0f6980_1c028c "d_1c028c"
extern OR700V3_0f69808 obR700V3_0f6980_1c0290;
#pragma aux obR700V3_0f6980_1c0290 "d_1c0290"
void f_0f6980(void) {
obR700V3_0f6980_1c0220.init(regR700V3_0f69808,0x6f,0);
obR700V3_0f6980_1c0224.init(regR700V3_0f69808,0x70,0);
obR700V3_0f6980_1c0228.init(regR700V3_0f69808,0x71,0);
obR700V3_0f6980_1c022c.init(regR700V3_0f69808,0x72,0);
obR700V3_0f6980_1c0230.init(regR700V3_0f69808,0x73,0);
obR700V3_0f6980_1c0234.init(regR700V3_0f69808,0x74,0);
obR700V3_0f6980_1c0238.init(regR700V3_0f69808,0x75,0);
obR700V3_0f6980_1c023c.init(regR700V3_0f69808,0x76,0);
obR700V3_0f6980_1c0240.init(regR700V3_0f69808,0x77,0);
obR700V3_0f6980_1c0244.init(regR700V3_0f69808,0x78,0);
obR700V3_0f6980_1c0248.init(regR700V3_0f69808,0x79,0);
obR700V3_0f6980_1c024c.init(regR700V3_0f69808,0x7b,0);
obR700V3_0f6980_1c0250.init(regR700V3_0f69808,0x86,0);
obR700V3_0f6980_1c0254.init(regR700V3_0f69808,0x7a,0);
obR700V3_0f6980_1c0258.init(regR700V3_0f69808,0x7c,0);
obR700V3_0f6980_1c025c.init(regR700V3_0f69808,0x7d,0);
obR700V3_0f6980_1c0260.init(regR700V3_0f69808,0x7e,0);
obR700V3_0f6980_1c0264.init(regR700V3_0f69808,0x7f,0);
obR700V3_0f6980_1c0268.init(regR700V3_0f69808,0x80,0);
obR700V3_0f6980_1c026c.init(regR700V3_0f69808,0x81,0);
obR700V3_0f6980_1c0270.init(regR700V3_0f69808,0x82,0);
obR700V3_0f6980_1c0274.init(regR700V3_0f69808,0x83,0);
obR700V3_0f6980_1c0278.init(regR700V3_0f69808,0x84,0);
obR700V3_0f6980_1c027c.init(regR700V3_0f69808,0x85,0);
obR700V3_0f6980_1c0280.init(regR700V3_0f69808,0x88,0);
obR700V3_0f6980_1c0284.init(regR700V3_0f69808,0x228,0);
obR700V3_0f6980_1c0288.init(regR700V3_0f69808,0x23d,0);
obR700V3_0f6980_1c028c.init(regR700V3_0f69808,0x24c,0);
obR700V3_0f6980_1c0290.init(regR700V3_0f69808,0x26a,0);
}
