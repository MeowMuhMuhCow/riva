/* === Beschreibung (Katalog) ===
 * Einheit environ2_t1 (0x065e40 - 0x067030)
 *
 * Überblick
 * Die Einheit environ2_t1 enthält den ersten Teil von environ2.cpp und implementiert die konkreten Raum-,
 * Kletter-, Schwimm-, Fallen- und Beute-Ereignisse, die vom Gebiets-Dispatcher f_0648c0 (gz_0640f0_t1) oder über
 * Funktionszeiger aufgerufen werden.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 23/29 gleich (suche.py 25.10.2026, Basis environ2_t1_P1.CPP)
// environ2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x065E40-0x067030
#include <string.h>
inline int EQ(int a, int b) { return a == b; }
#define NOT(x) EQ(x, 0)
#define YES(x) ((x)!=0)
typedef RivaTextContextData Fr;
int f_0104b0(void *p1, int p2, int p3, int p4);
void *f_010590(void *p1, int p2);
int f_038c40(int p1);
int f_038d70(int p1, int p2);
int f_039040(int p1);
int f_039320(int p1, int p2);
int f_039660(int p1, int p2);
int f_039a10(int p1, int p2, int p3);
int f_041030(...);
int f_041530(void);
int f_041920(int p1);

int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_057220(int *p1, int p2, int p3);
int f_060230(int p1);
int f_0603b0(int p1);
int f_0606a0(int p1, int p2);
int f_0600f0(int p1, int p2);
int f_060740(int p1, int p2);
short f_060760(int p1);
int f_0607e0(int p1, int p2);
int f_060a70(void);
signed char f_067b00(void);
int f_067bf0(int p1);
int f_067f10(int p1, int p2, int p3);
int f_0697c0(int p1, int p2, int p3);
int f_091f70(int p1);
int f_0b9280(void);
int f_0bde40(int *p1);
int f_0bf680(int *p1);
int f_0bf6c0(int *p1, int p2);
unsigned f_0bf6f0(int *p1, int p2);
int f_0bf730(int *p1, int p2);
short f_0bf820(int *p1, ...);
int f_0bf980(int *p1, ...);
int f_0bfa20(int *p1, ...);
int f_0d4a60(int p1);
int f_0d64a0(void);
int f_0dd7f0(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
short f_0de7f0(int p1);
int f_0de810(int p1, int p2);

void *f_112df0(void *p1, int p2, int p3, int p4);
void f_112ec0(void *p1);
void *f_112e70(void *p1, int p2);
int f_125400(void *p1, int *p2, int *p3, int *p4);
int f_1254a0(void *p1, int p2);
short f_145850(int p1, int p2, int p3);
int f_147323(int *p1, int p2, int p3, int p4, int p5, int p6, int p7);
// kein pragma
extern int d_1a9820;
extern short d_1bd6f0;
extern signed char d_1bcaa0;
extern signed char d_1bd704;
extern signed char d_1bd708;
extern signed char d_1bd70c;
extern signed char d_1bd710;
extern signed char d_1bd714;
extern signed char d_1bd718;
extern signed char d_1bd720;
extern signed char d_1bd71c;
extern signed char d_1bd724;
extern signed char d_1bd6f8;
extern signed char d_1bd728;
extern signed char d_1bd72c;
extern signed char d_1bd730;
extern signed char d_1bd734;
extern signed char d_1bd73c;
extern signed char d_1bd740;
extern signed char d_1bed6c;
extern signed char d_1bfa9c;
extern int d_1c0004;
extern signed char d_1c01f8;
extern signed char d_1c0dac;
extern signed char d_1c0e84;
extern int d_1c2c00;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a1a04[];
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_065e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Untersucht eine besondere Raumstelle abhängig von den Questflags d_1c0dac und d_1bed6c: Ist
 *   d_1c0dac == 0 und d_1bed6c == 1, wird nach Rückfrage 0x3600003f das Bild 0x2c0003 mit Text 0x36000040
 *   gezeigt und der Ortswechsel f_0dd7f0(d_1c0004, 4, 0x13f5) ausgeführt; ist d_1bed6c != 1, äußert der beste
 *   Held im Talent 0x1a den Text 0x36000041, und bei d_1c0dac != 0 erscheint 0x36000042.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Die globalen Bytes d_1c0dac und d_1bed6c steuern den aktuellen Questzustand der Stelle.
 === Ende Beschreibung === */
void f_065e40(void)
{
    if (NOT(d_1c0dac)) {
        if (EQ(d_1bed6c, 1)) {
            if (f_0bf6f0(&d_1c2c64, 0x3600003f) == 1) {
                int t = (int)operator new(0x13e, mark(d_1a1a04, 0x1fa));
                int q;
                q = t ? f_0104b0((void *)t, 0x2c0003, 0, 0) : t;
                f_0bf6c0(&d_1c2c64, 6);
                f_0bf980(&d_1c2c64, q, 0, 0x36000040, 0);
                f_0bf680(&d_1c2c64);
                if (q) {
                    void *r = f_010590((void *)q, 0);
                    operator delete(r);
                }
                f_0dd7f0(d_1c0004, 4, 0x13f5);
            }
        } else {
            Fr o;
            int s;
            f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
            s = f_039320(d_1c0004, 0x1a);
            o.tables.p[1] = s;
            f_0bf730(&d_1c2c64, 0x36000041);
            f_1254a0(&o, 0);
        }
    } else {
        f_0bf730(&d_1c2c64, 0x36000042);
    }
}
//@ f_065f80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt den besten Helden im Talent Sinnenschärfe (0x1d) beim ersten Mal (d_1bd6f8 == 0) eine
 *   Sinnenschärfe-Probe +7 (f_044c90(s, 0x1d, 7)) ablegen, speichert den Ausgang in d_1bd6f8 (1 = Erfolg, 2 =
 *   Misserfolg) und gibt danach dauerhaft den entsprechenden Text 0x36000043 oder 0x36000044 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd6f8 merkt sich das einmal ausgewürfelte Probenergebnis.
 === Ende Beschreibung === */
void f_065f80(void)
{
    Fr o;
    int s;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    s = f_039320(d_1c0004, 0x1d);
    if (NOT(d_1bd6f8)) {
        if (f_044c90(s, 0x1d, 7) > 0) d_1bd6f8 = 1; else d_1bd6f8 = 2;
    }
    o.tables.p[1] = s;
    if (EQ(d_1bd6f8, 1)) f_0bf730(&d_1c2c64, 0x36000043); else f_0bf730(&d_1c2c64, 0x36000044);
    f_1254a0(&o, 0);
}
//@ f_066030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft den besten Helden im Talent Sinnenschärfe (0x1d) mit Aufschlag +7 und gibt bei Erfolg
 *   die Meldung 0x36000045, bei Misserfolg 0x36000046 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Die lokale Variable s hält den Zeiger auf den geprüften Helden.
 === Ende Beschreibung === */
void f_066030(void)
{
    Fr o;
    int s;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    s = f_039320(d_1c0004, 0x1d);
    o.tables.p[1] = s;
    if (f_044c90(s, 0x1d, 7) > 0) f_0bf730(&d_1c2c64, 0x36000045); else f_0bf730(&d_1c2c64, 0x36000046);
    f_1254a0(&o, 0);
}
//@ f_0660a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt dieselbe Sinnenschärfe-Probe +7 wie f_066030 durch, gibt jedoch mit vertauschten
 *   Text-IDs bei Erfolg 0x36000046 und bei Misserfolg 0x36000045 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: s bezeichnet den besten Helden im Talent 0x1d.
 === Ende Beschreibung === */
void f_0660a0(void)
{
    Fr o;
    int s;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    s = f_039320(d_1c0004, 0x1d);
    o.tables.p[1] = s;
    if (f_044c90(s, 0x1d, 7) > 0) f_0bf730(&d_1c2c64, 0x36000046); else f_0bf730(&d_1c2c64, 0x36000045);
    f_1254a0(&o, 0);
}
//@ f_066110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bestimmt den besten Helden im Talent Sinnenschärfe (0x1d) und gibt mit dessen Namen den
 *   Beobachtungstext 0x36000047 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Der Textkontext o bindet den Helden in o.tables.p[1] ein.
 === Ende Beschreibung === */
void f_066110(void)
{
    Fr o;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    o.tables.p[1] = f_039320(d_1c0004, 0x1d);
    f_0bf730(&d_1c2c64, 0x36000047);
    f_1254a0(&o, 0);
}
//@ f_066170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Raummeldung 0x36000048 über die Dialogsteuerung d_1c2c64 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_066170(void)
{
    f_0bf730(&d_1c2c64, 0x36000048);
}
//@ f_066190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Raummeldung 0x36000049 über die Dialogsteuerung d_1c2c64 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_066190(void)
{
    f_0bf730(&d_1c2c64, 0x36000049);
}
//@ f_0661b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet beim Initialisieren des Gebiets (p1) die Kartenmarkierung 0x95 über f_0697c0 abhängig
 *   vom Flag d_1bd708 ein oder aus und ruft anschließend die Basismethode f_060230(p1) auf.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Byte d_1bd708 steuert den Zustand des Kartenobjekts 0x95.
 === Ende Beschreibung === */
void f_0661b0(int p1)
{
    int t = d_1bd708 == 1;
    if (t) f_0697c0(p1 + 2, 0x95, 0); else f_0697c0(p1 + 2, 0x95, 1);
    f_060230(p1);
}
//@ f_0661f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Filter-Callback für die Heldenauswahl in f_066220: Prüft, ob der Held p1 handlungsfähig ist
 *   (f_0d4a60) und keinen Sonder-/NSC-Typ (f_042400(p1) == 0) besitzt.
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); zurückgegeben wird 1 bei Eignung, sonst 0.
 * - Wichtige Variablen: Die lokale Variable r speichert das Prüfergebnis.
 === Ende Beschreibung === */
int f_0661f0(int p1)
{
    int r = 0;
    if (f_0d4a60(p1)) {
        if (f_042400((struct hero *)(p1)) == 0) r = 1;
    }
    return r;
}
//@ f_066220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert das Durchtauchen oder Durchqueren eines Hindernisses durch einen einzelnen Helden: Ist
 *   d_1bd708 == 1, erscheint nur Text 0x3600004a; andernfalls fragt die Funktion (beim ersten Mal ausführlich
 *   mit 0x3600004c..0x3600004e, danach kurz mit 0x3600004b), lässt über f_039a10 und Filter f_0661f0 einen
 *   Helden auswählen, spaltet diesen bei mehrköpfiger Gruppe temporär als Einzelgruppe ab (f_041030/f_041920),
 *   versetzt ihn an Zielpunkt 0x71 (f_0de810) und führt dort f_0b9280 aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd704 merkt sich, ob die ausführliche Erklärung bereits gezeigt wurde, d_1bd708 ob
 *   die Aktion erledigt ist, und q hält den ausgewählten Helden.
 === Ende Beschreibung === */
void f_066220(void)
{
    int e;
    Fr z[2];
    int q;
    f_125400(&z[0], &d_1c349c, &d_1c3870, &d_1c3498);
    z[0].tables.p[1] = f_039660(d_1c0004, 5);
    if (EQ(d_1bd708, 1)) {
        f_0bf730(&d_1c2c64, 0x3600004a);
    } else {
        short sv;
        if (NOT(d_1bd704)) {
            f_0bf730(&d_1c2c64, 0x3600004c);
            f_0bf730(&d_1c2c64, 0x3600004d);
            sv = f_0bf6f0(&d_1c2c64, 0x3600004e);
            d_1bd704 = 1;
        } else {
            sv = f_0bf6f0(&d_1c2c64, 0x3600004b);
        }
        if (sv == (short)1) {
            q = f_039a10(d_1c0004, 0x3600004f, (int)f_0661f0);
            if (q) {
                f_125400(&z[1], &d_1c349c, &d_1c3870, &d_1c3498);
                z[1].tables.p[1] = q;
                if (NOT(d_1bd70c)) f_0bf730(&d_1c2c64, 0x36000050);
                if (f_0de7f0(d_1c0004) == 1) {
                    f_0de810(d_1c0004, 0x71);
                    f_0b9280();
                } else {
                    e = f_041030(1, q);
                    int fl = f_0de7f0(d_1c0004) != 0;
                    f_041920(e);
                    f_0de810(e, 0x71);
                    f_0b9280();
                    if (fl) f_041530();
                }
                f_1254a0(&z[1], 0);
            }
        }
    }
    f_1254a0(&z[0], 0);
}
//@ f_0663d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Beschreibungstext 0x36000059 im Dialogfenster aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_0663d0(void)
{
    f_0bf730(&d_1c2c64, 0x36000059);
}
//@ f_0663f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für alle aktiven Helden der Gruppe (0..6) eine erleichterte Klettern-Probe (Talent 10,
 *   Modifikator -5). Misslingt mindestens einem Helden die Probe, wird der zuletzt geprüfte gescheiterte Held q
 *   in den Text 0x3600005a eingesetzt und erhält 2 Lebenspunkte Schaden (f_044300(q, 2)). *(Hinweis: Siehe
 *   Fehlerliste - durch das Überschreiben von q in der Schleife erhält nur der letzte gescheiterte Held
 *   Schaden.)*
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: q speichert den zuletzt bei der Probe gescheiterten Helden.
 === Ende Beschreibung === */
void f_0663f0(void)
{
    Fr o;
    int q = 0;
    int p;
    short i;
    for (i = 0; i < 7; i++) {
        p = f_0de7d0(d_1c0004, i);
        if (p) {
            if (f_0d4a60(p)) {
                if (f_044c90(p, 10, -5) <= 0) q = p;
            }
        }
    }
    if (q) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        o.tables.p[1] = q;
        f_0bf730(&d_1c2c64, 0x3600005a);
        f_044300(q, 2);
        f_1254a0(&o, 0);
    }
}
//@ f_066490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das globale Flag d_1bcaa0 == 1, d_1bd710 == 0 und die Questbedingung
 *   f_060760(0x1f41) == 1 erfüllt sind, gibt dann mit dem besten Helden im Talent 0x33 die Meldung 0x3600005b
 *   aus, setzt d_1bd710 = 1 und schaltet die Questflags 0x1f41 und 0x1f42 über f_060740/f_0607e0 weiter.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd710 verhindert ein mehrfaches Auslösen dieses Hinweises.
 === Ende Beschreibung === */
void f_066490(void)
{
    Fr o;
    if (EQ(d_1bcaa0, 1) && NOT(d_1bd710)) {
        if (f_060760(0x1f41) == 1) {
            f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
            o.tables.p[1] = f_039320(d_1c0004, 0x33);
            f_0bf730(&d_1c2c64, 0x3600005b);
            d_1bd710 = 1;
            f_060740(0x1f41, 1);
            f_0607e0(0x1f41, 1);
            f_0607e0(0x1f42, 1);
            f_1254a0(&o, 0);
        }
    }
}
//@ f_066560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten (d_1bd714 == 0) mit dem Namen des Gruppenanführers den Text
 *   0x3600005c aus und setzt d_1bd714 = 1.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd714 ist das zugehörige Einmal-Flag.
 === Ende Beschreibung === */
void f_066560(void)
{
    Fr o;
    int u;
    if (EQ(d_1bd714, 0)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        u = f_038c40(d_1c0004);
        o.tables.p[1] = u;
        f_0bf730(&d_1c2c64, 0x3600005c);
        d_1bd714 = 1;
        f_1254a0(&o, 0);
    }
}
//@ f_0665d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Operation (entspricht dem leeren case 0x1fa in f_0648c0).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0665d0(void)
{
}
//@ f_0665e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die Entscheidungsfrage 0x3600005d und löst bei Zustimmung den Orts-/Kartenwechsel
 *   f_0dd7f0(d_1c0004, 15, 0x13a3) aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64 und d_1c0004.
 === Ende Beschreibung === */
#define A64 ((int)&d_1c2c64)
void f_0665e0(void)
{
    if (f_0bf6f0(&d_1c2c64, 0x3600005d) == 1) f_0dd7f0(d_1c0004, 15, 0x13a3);
}

//@ f_066610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Operation (entspricht dem leeren case 0x259 in f_0648c0).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_066610(void)
{
}

//@ f_066620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei noch nicht gesetztem Flag d_1bd718, ob dem Gruppenanführer sowohl eine Probe auf
 *   Talent 0x33 (+4) als auch auf Sinnenschärfe (0x1d, +4) gelingt; bei Erfolg wird d_1bd718 = 1 gesetzt, die
 *   Meldung 0x3600005e ausgegeben und über f_0603b0(2) ein Ereignis freigeschaltet.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd718 merkt sich die erfolgreiche Entdeckung.
 === Ende Beschreibung === */
void f_066620(void)
{
    Fr o;
    int p;
    if (NOT(d_1bd718)) {
        p = f_038c40(d_1c0004);
        if (f_044c90(p, 0x33, 4) > 0) {
            if (f_044c90(p, 0x1d, 4) > 0) {
                d_1bd718 = 1;
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                o.tables.p[1] = p;
                f_0bf730(&d_1c2c64, 0x3600005e);
                f_0603b0(2);
                f_1254a0(&o, 0);
            }
        }
    }
}
//@ f_0666d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei d_1bd720 == 0 für den besten Helden im Talent Sinnenschärfe (0x1d), ob ihm die
 *   Proben auf Talent 0x33 (+4) und Sinnenschärfe (0x1d, +8) gelingen; bei Erfolg setzt die Funktion d_1bd720 =
 *   1, zeigt Text 0x3600005f an und ruft f_0603b0(3) auf.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd720 speichert den Entdeckungsstatus.
 === Ende Beschreibung === */
void f_0666d0(void)
{
    Fr o;
    int p;
    if (NOT(d_1bd720)) {
        p = f_039320(d_1c0004, 0x1d);
        if (f_044c90(p, 0x33, 4) > 0) {
            if (f_044c90(p, 0x1d, 8) > 0) {
                d_1bd720 = 1;
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                o.tables.p[1] = p;
                f_0bf730(&d_1c2c64, 0x3600005f);
                f_0603b0(3);
                f_1254a0(&o, 0);
            }
        }
    }
}
//@ f_066780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei d_1bd71c == 0 für den besten Sinnenschärfe-Helden zwei schwere Proben auf Talent
 *   0x33 (+12) und Sinnenschärfe (0x1d, +12). Gelingen beide, wird d_1bd71c = 1 gesetzt, die Texte 0x36000060
 *   und 0x36000061 ausgegeben, ein Beutepaket Nr. 4 über f_112df0/f_112ec0 übergeben, f_060a70() aufgerufen,
 *   Text 0x36000062 angezeigt und dem Helden 1W6 Punkte vom Attribut/Wert 5 (f_044850) abgezogen.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd71c verhindert ein mehrfaches Bergen des Fundes.
 === Ende Beschreibung === */
void f_066780(void)
{
    Fr o;
    int p;
    int p2;
    void *q;
    if (NOT(d_1bd71c)) {
        p = f_039320(d_1c0004, 0x1d);
        p2 = p;
        if (f_044c90(p, 0x33, 0xc) > 0) {
            if (f_044c90(p, 0x1d, 0xc) > 0) {
                d_1bd71c = 1;
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                o.tables.p[1] = p;
                f_0bf730(&d_1c2c64, 0x36000060);
                f_0bf730(&d_1c2c64, 0x36000061);
                {
                    int t = (int)operator new(0x14, mark(d_1a1a04, 0x432));
                    q = t ? f_112df0((void *)t, 4, 0, 1) : (void *)t;
                }
                f_112ec0(q);
                if (q) operator delete(f_112e70(q, 0));
                f_060a70();
                f_0bf730(&d_1c2c64, 0x36000062);
                f_044850(p2, f_145850(1, 6, 0), 5);
                f_1254a0(&o, 0);
            }
        }
    }
}
//@ f_0668c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt bei d_1bd724 == 0 den besten Helden a in Sinnenschärfe (0x1d) und den besten Helden
 *   b in Talent 0x33. Gelingen b die Probe auf 0x33 (+2) und a die Probe auf 0x1d (+5), setzt die Funktion
 *   d_1bd724 = 1, gibt je nachdem, ob a und b verschiedene Helden sind, den Text 0x36000063 oder 0x36000064 aus
 *   und ruft f_0603b0(5) auf.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd724 speichert, ob die Kombination bereits ausgelöst wurde.
 === Ende Beschreibung === */
void f_0668c0(void)
{
    Fr o;
    int a;
    int b;
    if (NOT(d_1bd724)) {
        a = f_039320(d_1c0004, 0x1d);
        { int t_ = (int)(d_1c0004); b = f_039320(t_, 0x33); }
        if (f_044c90(b, 0x33, 2) > 0) {
            if (f_044c90(a, 0x1d, 5) > 0) {
                d_1bd724 = 1;
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                o.tables.p[1] = b;
                o.tables.p[2] = a;
                if (b != a) f_0bf730(&d_1c2c64, 0x36000063);
                else f_0bf730(&d_1c2c64, 0x36000064);
                f_0603b0(5);
                f_1254a0(&o, 0);
            }
        }
    }
}
//@ f_066990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft bei d_1bd728 == 0 die gemeinsame Prüfroutine f_067b00 (environ2_t2) auf und aktiviert bei
 *   Erfolg (1) das Flag d_1bd728 = 1 sowie den Trigger f_0603b0(6).
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd728 markiert den Abschluss dieses Raumtriggers.
 === Ende Beschreibung === */
void f_066990(int p1)
{
    if (NOT(d_1bd728)) {
        if (((int (*)(int))f_067b00)(p1) == 1) {
            d_1bd728 = 1;
            f_0603b0(6);
        }
    }
}

//@ f_0669d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Operation (entspricht case 0x25f in f_0648c0).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0669d0(void)
{
}

//@ f_0669e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft bei d_1bd72c == 0 ebenfalls f_067b00 auf und setzt bei Erfolg (1) das Flag d_1bd72c = 1
 *   sowie den Trigger f_0603b0(7).
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd72c markiert den zweiten gekoppelten Raumtrigger.
 === Ende Beschreibung === */
void f_0669e0(int p1)
{
    if (NOT(d_1bd72c)) {
        if (((int (*)(int))f_067b00)(p1) == 1) {
            d_1bd72c = 1;
            f_0603b0(7);
        }
    }
}
//@ f_066a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten (d_1bd730 == 0) mit dem besten Helden im Talent 0x1f die Meldung
 *   0x36000068 aus und setzt d_1bd730 = 1.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd730 ist das Einmal-Flag dieser Meldung.
 === Ende Beschreibung === */
void f_066a20(void)
{
    Fr o;
    if (NOT(d_1bd730)) {
        d_1bd730 = 1;
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        o.tables.p[1] = f_039320(d_1c0004, 0x1f);
        f_0bf730(&d_1c2c64, 0x36000068);
        f_1254a0(&o, 0);
    }
}
//@ f_066a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim ersten Mal (d_1bfa9c == 0) das Bild 0x360001 (Index 0), zeigt es zusammen mit dem
 *   Text 0x36000069 über f_0bfa20 an, schaltet über f_0600f0(p1, 0x15000c) eine Gebietsfunktion frei und setzt
 *   d_1bfa9c = 1.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bfa9c verhindert die wiederholte Anzeige der Grafikszene.
 === Ende Beschreibung === */
void f_066a90(int p1)
{
    int q;
    if (NOT(d_1bfa9c)) {
        q = f_0606a0(0x360001, 0);
        f_0bfa20(&d_1c2c64, q, 0, 0x36000069, 0);
        if (q) operator delete(((void *)(((RivaRasterImage*)(q))->f_0fad20( 0))));
        f_0600f0(p1, 0x15000c);
        d_1bfa9c = 1;
    }
}
//@ f_066b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versetzt die Gruppe über f_0de810(d_1c0004, 0x65) auf den Zielpunkt 0x65.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c0004.
 === Ende Beschreibung === */
void f_066b00(void)
{
    f_0de810(d_1c0004, 0x65);
}
//@ f_066b20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft nach Abschluss des Musik-/Signalrätsels (d_1c0e84), ob der Begleit-NSC (f_039040, Typ 2)
 *   anwesend und handlungsfähig ist: Bei d_1c0e84 < 2 oder fehlendem NSC erscheint 0x3600006a, bei d_1c0e84 == 2
 *   der Hinweis 0x3600006b, und bei höherer Stufe (>= 3) werden die Texte 0x3600006c/0x3600006d ausgegeben,
 *   Tagebuch-/Queststatus 0x26 (f_091f70), d_1bd6f0 = 1 und 0x8030030 (f_057220) gesetzt, der NSC entfernt
 *   (f_0d64a0) und nach Auswahl 0x3600006e gegebenenfalls der Dialog f_067bf0 gestartet.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1c0e84 ist die Rätselstufe und d_1bd6f0 das Abschlussflag.
 === Ende Beschreibung === */
struct MsgC {
    int h;
    int *q[14];
    MsgC(int *a, int *b, int *c);
    ~MsgC();
};
void f_066b20(int p1)
{
    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
    int r = 0;
    int o = f_039040(d_1c0004);
    if (o != 0 && f_042400((struct hero *)(o)) == 2 && f_0d4a60(o) != 0) r = o;
    if (r == 0) {
        f_0bf730(&d_1c2c64, 0x3600006a);
    } else if (((d_1c0e84 < 2) ? 1 : 0) != 0) {
        f_0bf730(&d_1c2c64, 0x3600006a);
    } else if (EQB(d_1c0e84, 2)) {
        m.q[0][1] = r;
        f_0bf730(&d_1c2c64, 0x3600006b);
    } else {
        short k;
        m.q[0][1] = f_039320(d_1c0004, 0x33);
        f_0bf730(&d_1c2c64, 0x3600006c);
        f_091f70(0x26);
        f_0bf730(&d_1c2c64, 0x3600006d);
        r = 0;
        *(char *)&d_1bd6f0 = 1;
        f_057220(&d_1c2c00, 0x8030030, r);
        f_0d64a0();
        do {
            k = f_0bf820(&d_1c2c64, 0x3600006e, 2, 0x3600006f, 0x36000070);
        } while (k == -1);
        if (k != 1) f_067bf0(p1);
    }
}
//@ f_066c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt bei gesetztem Flag d_1c01f8 == 1 mit dem Namen des Gruppenanführers über 0x36000082 nach
 *   und führt bei Bestätigung den Ortsübergang f_0dd7f0(d_1c0004, 2, 0x1715) aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1c01f8 gibt an, ob dieser Übergang freigeschaltet ist.
 === Ende Beschreibung === */
void f_066c90(void)
{
    Fr o;
    if (EQ(d_1c01f8, 1)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        o.tables.p[1] = f_038c40(d_1c0004);
        if (f_0bf6f0(&d_1c2c64, 0x36000082) == 1) f_0dd7f0(d_1c0004, 2, 0x1715);
        f_1254a0(&o, 0);
    }
}
//@ f_066d10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Beschreibungstext 0x36000083 im Dialogfenster aus.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_066d10(void)
{
    f_0bf730(&d_1c2c64, 0x36000083);
}
//@ f_066d30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei d_1bd734 == 0, ob dem besten Sinnenschärfe-Helden die Proben auf Talent 0x33 (+0)
 *   und Sinnenschärfe (0x1d, +3) gelingen; bei Erfolg wird d_1bd734 = 1 gesetzt und mit Frage 0x36000084
 *   angeboten, den Fund zu bergen (Text 0x36000085 und Übergabe des Beutepakets Nr. 9 über f_112df0/f_112ec0).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd734 markiert, dass das Versteck bereits entdeckt wurde.
 === Ende Beschreibung === */
void f_066d30(void)
{
    Fr o;
    int s;
    void *d;
    if (NOT(d_1bd734)) {
        s = f_039320(d_1c0004, 0x1d);
        if (f_044c90(s, 0x33, 0) > 0) {
            if (f_044c90(s, 0x1d, 3) > 0) {
                d_1bd734 = 1;
                f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
                o.tables.p[1] = s;
                if (f_0bf6f0(&d_1c2c64, 0x36000084) == 1) {
                    o.tables.p[2] = f_039320(d_1c0004, 10);
                    f_0bf730(&d_1c2c64, 0x36000085);
                    {
                        int t = (int)operator new(0x14, mark(d_1a1a04, 0x57c));
                        d = t ? f_112df0((void *)t, 9, 0, 1) : (void *)t;
                    }
                    f_112ec0(d);
                    if (d) operator delete(f_112e70(d, 0));
                }
                f_1254a0(&o, 0);
            }
        }
    }
}
//@ f_066e50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert ein Kletter- oder Hindernisereignis (solange d_1bd740 == 0): Wurde das Hindernis noch
 *   nicht entdeckt (d_1bd73c == 0), muss der beste Held in Talent 0x33 erst Proben auf 0x33 (+15) und 0x1d (+12)
 *   schaffen, bevor Frage 0x36000088 gestellt wird (andernfalls direkt Frage 0x36000089). Wählt der Spieler
 *   danach über f_038d70 (0x3600008a) einen Helden r aus, wird Sound 0x36000a und Grafik 0x360001 (Bild 2) mit
 *   Text 0x3600008c bzw. 0x3600008d gezeigt, eine Klettern-Probe (Talent 10, +20 beim ersten Mal bzw. +10
 *   danach) abgelegt und das Ergebnis an f_067f10 übergeben.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd73c speichert, ob die Stelle bereits entdeckt wurde, und d_1bd740, ob das Hindernis
 *   endgültig überwunden ist.
 === Ende Beschreibung === */
#pragma aux f_147323 modify [esp];
int f_0bfa20_bx(int *p1, ...);
#pragma aux f_0bfa20_bx "f_0bfa20" modify [ebx];
void f_066e50(int p1)
{
    Fr o;
    int r;
    int e;
    int q;
    int q2;
    int c;
    int sv;
    int h;
    int gate;
    if (NOT(d_1bd740)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        gate = d_1bd73c;
        e = 3;
        if (NOT(gate)) {
            h = f_039320(d_1c0004, 0x33);
            if (f_044c90(h, 0x33, 0xf) > 0) {
                if (f_044c90(h, 0x1d, 0xc) > 0) {
                    d_1bd73c = 1;
                    o.tables.p[1] = h;
                    if (f_0bf6f0(&d_1c2c64, 0x36000088) == 1) e = 0;
                }
            }
        } else {
            if (f_0bf6f0(&d_1c2c64, 0x36000089) == 1) e = 1;
        }
        if (e == 0 || e == 1) {
            r = f_038d70(d_1c0004, 0x3600008a);
            if (r) {
                q = f_0606a0(0x360001, 2);
                q2 = q;
                o.tables.p[2] = r;
                { int snd = d_1a9820; f_147323(&d_1c2edc, 0x36000a, 0x7fff, 0x8000, snd, 0, 1); }
                if (e == 0) {
                    f_0bf730(&d_1c2c64, 0x3600008b);
                    f_0bde40(&d_1c2c64);
                    c = 0x14;
                    f_0bfa20_bx(&d_1c2c64, q2, e, 0x3600008c, e);
                } else {
                    f_0bde40(&d_1c2c64);
                    c = 10;
                    f_0bfa20_bx(&d_1c2c64, q2, 0, 0x3600008d, 0);
                }
                {
                    unsigned char bv = f_044c90(r, 10, (signed char)c) > 0;
                    sv = bv;
                }
                if (q) operator delete(((void *)(((RivaRasterImage*)(q))->f_0fad20( 0))));
                f_067f10(p1, r, sv);
            }
        }
        f_1254a0(&o, 0);
    }
}
