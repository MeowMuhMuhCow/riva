/* === Beschreibung (Katalog) ===
 * Einheit gz_03b8d0 (0x03b8d0 - 0x03cd00)
 *
 * Überblick
 * Diese Einheit implementiert die drei medizinischen Heilkunde-Talente Heilkunde Wunden (f_03b8d0), Heilkunde
 * Krankheiten (f_03bc00, f_03c000, f_03c210) und Heilkunde Gift (f_03bc50), das Talent Schätzen samt
 * Preisformatierung (f_03c530, f_03c630), das Magier-Spezialmenü für Meditation, Zauberbuch und Stabzauber
 * (f_03c860) sowie die Verfügbarkeitsprüfung für Zauberschulen (f_03cc60).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 3/9 gleich (suche.py 30.10.2026, Basis gz_03b8d0_P1.CPP)
// B2 Arm B (blind neu): f_03bc50 59/23, f_03c860 3/2 (bester gemessener Stand V008)
// P1 1/9 gleich
// gz_03b8d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03B8D0-0x03CD00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
struct Msg { int h; int *a; int x; int *b; int *c; short *d; int *g; int z1; short *e; int pad[6]; Msg(int *a, int *b, int *c); ~Msg(); };
struct PL2 { int h; int *a; int x; int *b; int *c; short *d; int *g; int z1; short *e; int pad[6]; };
#define MSG_X PL2 pl; f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
#define END_X f_1254a0(&pl);
#define MSG_Y PL2 pl; f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
#define END_Y f_1254a0(&pl);
#define MSG_W Msg pl(&d_1c349c, &d_1c3870, &d_1c3498);
#define END_W 
short f_032820(int p1, int p2, int p3);
int f_036300(int p1, int p2, int p3);
int f_038e90(int p1, int p2);
int f_03d4b0(int p1, int p2, int p3);
int f_040730(int p1, int p2);
int f_040980(int p1, int p2);
int f_040da0(int p1);
int f_040e00(int p1);











int f_043370(int p1, int p2);
int f_0437b0(int p1, int p2);
int f_0437e0(int p1, int p2, int p3);
int f_043a10(int p1, int p2);
int f_043a40(int p1, int p2, int p3);
int f_044230(int p1, int p2);
int f_0442b0(int p1, int p2);
int f_044300(int p1, int p2);
int f_044890(int p1, int p2);
short f_044940(int p1, int p2, int p3, int p4, int p5);
short f_044c90(int p1, int p2, int p3);


int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
short f_0bf7b0(void *p1, int p2, int p3, int p4, int p5, int p6);
unsigned short f_0bf820();
short f_0d4aa0(int p1, int p2);
int f_0d4ad0(int p1);
int f_0d4b00(int p1);
int f_0dc020(int p1, int p2);
int f_0e93f0(void *p1, void *p2, int p3);
void f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1);
int f_125e50(void *p1, int p2);
int f_125e50(void *p1, int p2, int p3);
int f_133fe0(void *p1, void *p2);
short f_1457e0(int p1);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
extern signed char d_1a0da8[];
extern signed char d_1a0dc8[];
extern signed char d_1a7244[];
extern signed char d_1a7245[];
extern signed char d_1a7247[];
extern signed char d_1a7248[];
extern signed char d_1a7249[];
extern signed char d_1a7275[];
extern signed char d_1a7734[];
extern signed char d_1a7735[];
extern char d_1a9670;
extern int d_1a9820;
extern short d_1bd90c;
extern int d_1c0004;

extern int d_1c27a8;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
short f_03c210(int p1, int p2, short p3, short p4);

int f_0bf820(void *p1, ...);
short f_0bf7b0s(void *p1, int p2, int p3, int p4, short p5, int p6);
signed char f_042350s(int p1);
int f_044300s(int p1, short p2);
int f_0442b0s(int p1, short p2);
int f_044230s(int p1, short p2);
int f_040730s(int p1, short p2);
int f_0432e0c(int p1, signed char p2);

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
static inline short h1() { return 1; }
static inline short h2() { return 0; }
static inline int h3() { return d_1a9820; }
static inline unsigned short h4() { return 0x8000; }
static inline unsigned short h5() { return 0x7fff; }
static inline short h60(int x) { return f_042960((struct hero *)(x)); }
static inline signed char f_03b690_inl(int p1, int p2)
{
    return *(signed char *)(p1 + p2 + 0x11a);
}

//@ f_03b8d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt das Talent Heilkunde Wunden (0x2e) durch, mit dem der Heiler p1 einen aus
 *   der Gruppe ausgewählten verletzten Kameraden p behandelt. Nach Prüfung der Sperrzeit (p + 0x9d) werden zwei
 *   Talentproben abgelegt: Gelingen beide, heilt der Patient bis zu Talentwert Lebenspunkte; gelingt nur die
 *   erste, verschlimmert sich die Wunde um 1 bis 3 Schadenspunkte; misslingt schon die erste Probe mit einem
 *   Würfelwurf <= 7, infiziert sich der Patient mit Wundfieber (f_040980(p, 1)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heiler p1 und den Probenmodifikator p2 (short) und gibt die
 *   geheilten Lebenspunkte (> 0), 0 (bei Fehlbehandlung) oder -3 (bei Abbruch der Patientenauswahl) zurück.
 * - Wichtige Variablen: Das Feld *(int *)(p + 0x9d) setzt eine Behandlungs-Sperrzeit von 0x1fa40 (129600
 *   Zeiteinheiten = 1 Tag) für den Patienten p.
 === Ende Beschreibung === */
short f_03b8d0(int p1, short p2)
{
#pragma aux f_147323 modify [esp];
    short r = 1;
    Msg pl(&d_1c349c, &d_1c3870, &d_1c3498);
    int p;
    int msg;
    short k;

    d_1a9670 = f_0dc020(d_1c0004, p1);
    p = f_038e90(d_1c0004, 0x205000c);
    if (p != 0) {
        if (!((char)(f_0424e0((struct hero *)(p))))) {
            if (f_0429f0((struct hero *)(p)) != 0) {
                if (f_042960((struct hero *)(p)) >= f_042970((struct hero *)(p))) {
                    pl.a[1] = p;
                    f_0bf730(&d_1c2c64, 0x2050009);
                } else if (*(int *)(p + 0x9d) > 0) {
                    pl.a[1] = p;
                    f_0bf730(&d_1c2c64, 0x205000f);
                } else {
                    *(int *)(p + 0x9d) = 0x1fa40;
                    if (f_044c90(p1, 0x2e, (signed char)(p2 - 5)) > 0) {
                        if (f_044c90(p1, 0x2e, (signed char)(p2 - 5)) > 0) {
                            r = (f_03b690_inl(p1, 0x2e) > 1) ? f_03b690_inl(p1, 0x2e) : 1;
                            if (r > f_042970((struct hero *)(p)) - f_042960((struct hero *)(p)))
                                r = f_042970((struct hero *)(p)) - f_042960((struct hero *)(p));
                            if (r == 0)
                                r = 1;
                            r = (r & 0) ? (short)0 : r; // Haelt r im selben Registerweb ueber den Aufruf
                            f_044890(p, r);
                            pl.a[1] = p1;
                            pl.a[2] = p;
                            pl.d[1] = r;
                            { short u0_ = r; r = u0_; } { short u1_ = r; r = u1_; } { short u2_ = r; r = u2_; } // Erhoeht das Nutzwertgewicht von r fuer die Registervergabe
                            pl.c[1] = (r > 1) ? 0x20000105 : 0x20000194;
                            msg = 0x2050011;
                            f_147323(&d_1c2edc, 0x20006, h5(), h4(), h3(), h2(), h1());
                        } else {
                            k = 3;
                            if (f_042960((struct hero *)(p)) <= k)
                                k = f_042960((struct hero *)(p)) - 1;
                            f_044300(p, k);
                            pl.a[1] = p;
                            pl.d[1] = k;
                            pl.c[1] = (k > 1) ? 0x20000105 : 0x20000194;
                            msg = 0x2050010;
                            r = 0;
                            *(int *)(p + 0xa1) = 0x1fa40;
                        }
                        f_0bf730(&d_1c2c64, msg);
                    } else {
                        if (f_1457e0(20) <= 7) {
                            pl.a[1] = p1;
                            pl.a[2] = p;
                            msg = 0x205000b;
                            f_040980(p, 1);
                        } else {
                            pl.a[1] = p1;
                            pl.a[2] = p;
                            msg = 0x205000a;
                        }
                        f_0bf730(&d_1c2c64, msg);
                    }
                }
            } else {
                pl.a[1] = p;
                f_0bf730(&d_1c2c64, 0x17000032);
            }
        } else {
            pl.a[1] = p;
            f_0bf730(&d_1c2c64, 0x170000eb);
        }
    } else {
        r = -3;
    }
    return r;
}

//@ f_03bc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Einstiegsfunktion für das Talent Heilkunde Krankheiten lässt den Spieler einen Patienten
 *   p aus der Hauptgruppe auswählen und ruft anschließend die eigentliche Krankheitsbehandlung f_03c210 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heiler p1 und den Probenmodifikator p2 (short) und gibt 1
 *   nach durchgeführter Behandlung oder -3 bei Abbruch der Auswahl zurück.
 * - Wichtige Variablen: d_1a9670 speichert den Gruppenindex des Heilers, damit die Auswahlfunktion f_038e90
 *   weiß, wer die Behandlung durchführt.
 === Ende Beschreibung === */
int f_03bc00(int p1, short p2)
{
    int p;
    d_1a9670 = f_0dc020(d_1c0004, p1);
    p = f_038e90(d_1c0004, 0x205000c);
    if (p == 0) {
        return -3;
    }
    f_03c210(p1, p, p2, 0);
    return 1;
}
//@ f_03bc50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt das Talent Heilkunde Gift (0x2c) durch. Der Heiler p1 versucht zunächst
 *   mit einer ersten Talentprobe zu erkennen, an welchem Gift (v = f_0d4b00(p)) der gewählte Patient p leidet,
 *   neutralisiert bei einer zweiten Probe (modifiziert um die Giftstärke d_1a0dc8[v * 2]) das Gift über
 *   f_040e00(q) und kann danach auf Wunsch in einer dritten Probe bereits erlittenen Giftschaden an den
 *   Lebenspunkten wiederherstellen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heiler p1 und den Probenmodifikator p2 (short) und gibt einen
 *   positiven Wert bei Erfolg, 0 bei misslungener Nachbehandlung oder -3 bei Abbruch zurück.
 * - Wichtige Variablen: Die Behandlung verbraucht 0x708 (1800) Zeiteinheiten (f_125e50) und setzt beim Patienten
 *   eine Sperrzeit *(int *)(p + 0x9d) = 0x5460 (21600 Einheiten = 4 Stunden).
 === Ende Beschreibung === */
short f_03bc50(int p1, short p2)
{
#pragma aux f_147323 modify [esp];
    short s;
    short v;
    short k;
    int p;
    int q;
    int msg;
    short r;
    r = 1;
    Msg pl(&d_1c349c, &d_1c3870, &d_1c3498);
    d_1a9670 = f_0dc020(d_1c0004, p1);
    { int t_ = (int)(d_1c0004); p = f_038e90(t_, 0x205000c); }
    q = p;
    if (p != 0) {
        if (!((char)(f_0424e0((struct hero *)(p))))) {
            if (f_0429f0((struct hero *)(p)) != 0) {
                v = f_0d4b00(p);
                if (!v) {
                    pl.a[1] = p;
                    f_0bf730(&d_1c2c64, 0x205000d);
                } else if (*(int *)(p + 0x9d) > 0) {
                    pl.a[1] = p;
                    f_0bf730(&d_1c2c64, 0x205000f);
                } else {
                    *(int *)(p + 0x9d) = 0x5460;
                    if (f_0437b0(p, v) != 0 || f_044c90(p1, 0x2c, (signed char)p2) > 0) {
                        f_125e50(&d_1c2c44, 0x708);
                        f_0437e0(q, v, 1);
                        if (f_044c90(p1, 0x2c, (signed char)(d_1a0dc8[v * 2] + p2 - 5)) > 0) {
                            pl.a[1] = p1;
                            pl.a[2] = q;
                            f_0bf730(&d_1c2c64, 0x2050003);
                            f_040e00(q);
                            if (f_042960((struct hero *)(q)) < f_042970((struct hero *)(q))) {
                                pl.a[1] = p1;
                                pl.a[2] = q;
                                if (f_0bf6f0(&d_1c2c64, 0x2050004) == 1) {
                                    do {
                                        s = f_0bf7b0s(&d_1c2c64, 2, 0x17000082, 1, f_042970((struct hero *)(q)) - f_042960((struct hero *)(q)), 1);
                                    } while (s < 0);
                                    short t = f_044c90(p1, 0x2c, (signed char)(s + p2 - 5));
                                    r = t;
                                    if ((short)t > 0) {
                                        if (s > f_042970((struct hero *)(q)) - f_042960((struct hero *)(q))) s = f_042970((struct hero *)(q)) - f_042960((struct hero *)(q));
                                        if (s == 0) s = 1;
                                        pl.a[1] = p1;
                                        pl.a[2] = q;
                                        pl.d[1] = s;
                                        pl.c[1] = (s > 1) ? 0x20000105 : 0x20000194;
                                        msg = 0x2050011;
                                        f_044890(q, s);
                                        f_147323(&d_1c2edc, 0x20006, h5(), h4(), h3(), h2(), h1());
                                    } else {
                                        k = 3;
                                        if (h60(q) <= (short)k) {
                                            k = h60(q);
                                            k -= 1;
                                        }
                                        f_044300(q, (short)k);
                                        pl.a[1] = q;
                                        pl.d[1] = k;
                                        pl.c[1] = (short)k > 1 ? 0x20000164 : 0x20000194;
                                        msg = 0x2050010;
                                        { signed char j; r = j ^ j; } // Erzwingt Nullung von r ueber Register statt Konstante
                                        r = 0;
                                    }
                                    f_0bf730(&d_1c2c64, msg);
                                }
                            }
                        } else {
                            pl.a[1] = p1;
                            pl.a[2] = q;
                            f_0bf730(&d_1c2c64, 0x2050002);
                        }
                    } else {
                        pl.a[1] = p1;
                        pl.a[2] = p;
                        f_0bf730(&d_1c2c64, 0x205000e);
                    }
                }
            } else {
                pl.a[1] = p;
                f_0bf730(&d_1c2c64, 0x17000032);
            }
        } else {
            pl.a[1] = p;
            f_0bf730(&d_1c2c64, 0x170000eb);
        }
    } else {
        r = -3;
    }
    return r;
}
//@ f_03c000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft bei der Behandlung einer Krankheit p2 (1..7), ob der Heiler p1 die
 *   für diese spezifische Krankheit benötigten Heilkräuter im Inventar besitzt. Für Krankheit 1 und 3 werden
 *   keine Kräuter benötigt (99), für Krankheit 5 (Schlachtenfieber/Paralyse) müssen sowohl Kraut 0x82
 *   (Joruga/Donf) als auch 0x3f (Gulmond/Wirselkraut) vorhanden sein (999), und für die übrigen Krankheiten wird
 *   eine Prioritätsliste passender Kräuter abgefragt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heiler p1 und die Krankheits-ID p2 (short) und gibt die
 *   Gegenstands-ID des zu verbrauchenden Krauts, 99 (kein Kraut nötig), 999 (Kräuterpaar 0x82 + 0x3f) oder 0
 *   (benötigtes Kraut fehlt) zurück.
 * - Wichtige Variablen: Die Inventarsuche erfolgt über f_0d4aa0(p1, item_id).
 === Ende Beschreibung === */
short f_03c000(int p1, short p2)
{
    short s;
    int r;
    r = 0;
    switch (p2) {
    case 1:
    case 3:
        { r = 99; return r; }
    case 2:
        s = f_0d4aa0(p1, 0x7b);
        if (s != -1) { r = 0x7b; return r; }
        s = f_0d4aa0(p1, 0x3d);
        if (s != -1) { r = 0x3d; return r; }
        s = f_0d4aa0(p1, 0x10b);
        if ((short)(s & 0xffff) != -1) { r = 0x10b; return r; }
        s = f_0d4aa0(p1, 0x3c);
        if (s != -1) { r = 0x3c; return r; }
        s = f_0d4aa0(p1, 0x135);
        if (s != -1) { r = 0x135; return r; }
        s = f_0d4aa0(p1, 0x40);
        if ((int)(short)(s & 0xffff) != (short)-1) { r = 0x40; return r; }
        s = f_0d4aa0(p1, 0x7c);
        if (s != -1) { r = 0x7c; return r; }
        s = f_0d4aa0(p1, 0x81);
        if (s != -1) { r = 0x81; return r; }
        s = f_0d4aa0(p1, 0x7d);
        if (s != -1) { r = 0x7d; return r; }
        s = f_0d4aa0(p1, 0x9c);
        if (s != -1) { r = 0x9c; return r; }
        s = f_0d4aa0(p1, 0x82);
        if ((short)(s & 0xffff) != -1) { r = 0x82; return r; }
        break;
    case 4:
        s = f_0d4aa0(p1, 0x7c);
        if (s != -1) { r = 0x7c; return r; }
        break;
    case 5:
        s = f_0d4aa0(p1, 0x82);
        if (s != -1 && (s = f_0d4aa0(p1, 0x3f)) != -1) { r = 999; return r; }
        break;
    case 6:
        s = f_0d4aa0(p1, 0x3d);
        if (s != -1) { r = 0x3d; return r; }
        s = f_0d4aa0(p1, 0x10b);
        if (s != -1) { r = 0x10b; return r; }
        break;
    case 7:
        s = f_0d4aa0(p1, 0x82);
        if (s != -1) r = 0x82;
    }
    return r;
}
//@ f_03c210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt die eigentliche Behandlung einer Krankheit am Patienten p2 durch den
 *   Heiler p1 aus (Talent 0x2d). Nach der Diagnoseprobe, an welcher Krankheit (v = f_0d4ad0(p2)) der Patient
 *   leidet, prüft sie über f_03c000 das Vorhandensein der nötigen Heilkräuter, würfelt eine um die
 *   Krankheitsschwere d_1a0da8[v * 2] erschwerte Heilprobe aus, leitet bei Erfolg über f_040da0(p2) die Genesung
 *   ein, heilt Lebenspunkte und verbraucht die eingesetzten Kräuter aus dem Inventar des Heilers.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heiler p1, den Patienten p2, den Probenmodifikator p3 (short)
 *   und ein Diagnose-Vorwissen-Flag p4 (short) und gibt 1 bei erfolgreicher Heilung oder 0 bzw. <= 0 bei
 *   Fehlschlag zurück.
 * - Wichtige Variablen: Die Krankheiten 1 und 3 gelten als auf diesem Weg unheilbar (Meldung 0x2050013); die
 *   Untersuchung kostet 0x1c2 (450) Zeiteinheiten.
 === Ende Beschreibung === */
short f_03c210(int p1, int p2, short p3, short p4)
{
#pragma aux f_147323 modify exact [eax esp];
    short r;
    int msg;
    short skill;
    short v;
    int sound;
    r = 0;
    {
    MSG_W
    if (((char)(f_0424e0((struct hero *)(p2))))) goto L_eb;
    if (f_0429f0((struct hero *)(p2)) != 1) goto L_32;
    v = f_0d4ad0(p2);
    if (!v) {
        pl.a[1] = p2;
        pl.a[2] = p1;
        msg = 0x2050007;
        goto send;
    }
    if (*(int *)(p2 + 0x9d) > 0) {
        pl.a[1] = p2;
        msg = 0x205000f;
        goto send;
    }
    f_125e50(&d_1c2c44, 0x1c2);
    if (!p4 && f_043a10(p2, v) == 0
        && f_044c90(p1, 0x2d, (signed char)(p3 - 5)) <= 0) goto L_6;
    f_043a40(p2, v, 1);
    pl.a[1] = p2;
    f_0bf730(&d_1c2c64, 0x2050012);
    if (v == 1 || v == 3) {
        pl.a[1] = p2;
        msg = 0x2050013;
        goto send;
    }
    skill = f_03c000(p1, v);
    if (skill == 0) {
        pl.a[1] = p1;
        msg = 0x2050001;
        goto send;
    }
    *(int *)(p2 + 0x9d) = 0x5460;
    r = f_044c90(p1, 0x2d, (signed char)(d_1a0da8[v * 2] + p3 - 5));
    if (r > 0) {
        if (r > f_042970((struct hero *)(p2)) - f_042960((struct hero *)(p2)))
            r = f_042970((struct hero *)(p2)) - f_042960((struct hero *)(p2));
        f_044890(p2, r);
        if (r == 0) r = 1;
        pl.a[1] = p1;
        pl.a[2] = p2;
        pl.d[1] = r;
        pl.c[1] = r > 1 ? 0x20000105 : 0x20000194;
        msg = 0x2050005;
        f_040da0(p2);
        sound = d_1a9820;
        f_147323(&d_1c2edc, 0x20006, 0x7fff, 0x8000, sound, 0, 1);
        if (skill == 0x3e7) {
            f_036300(p1, f_0d4aa0(p1, 0x82), 1);
            f_036300(p1, f_0d4aa0(p1, 0x3f), 1);
        } else {
            f_036300(p1, f_0d4aa0(p1, skill), 1);
        }
        r = 1;
    } else {
        short k;
        k = 3;
        if (f_042960((struct hero *)(p2)) <= k) k = f_042960((struct hero *)(p2)) - 1;
        f_044300(p2, k);
        pl.a[1] = p2;
        pl.d[1] = k;
        pl.c[1] = k > 1 ? 0x20000164 : 0x20000194;
        msg = 0x2050010;
    }
    goto send;
L_6:
    pl.a[1] = p1;
    pl.a[2] = p2;
    msg = 0x2050006;
    goto send;
send:
    f_0bf730(&d_1c2c64, msg);
    goto done;
L_32:
    pl.a[1] = p2;
    f_0bf730(&d_1c2c64, 0x17000032);
    goto done;
L_eb:
    pl.a[1] = p2;
    f_0bf730(&d_1c2c64, 0x170000eb);
done:
    ;
    }
    return r;
}

//@ f_03c530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Formatierungsfunktion rundet einen geschätzten Preis p5 (in Hellern) auf glatte Dukaten
 *   (u1), Silberlinge (u2) oder Heller (p5) und erzeugt daraus einen natürlich klingenden Schätztext (z. B.
 *   "etwa X Dukaten", "rund Y Silberlinge" oder "ungefähr Z Heller") im Zielpuffer p1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Ziel-Textpuffer p1, die drei Format-Text-IDs p2 (Dukaten), p3
 *   (Silberlinge) und p4 (Heller) sowie den Betrag p5 in Hellern; sie hat keinen Rückgabewert.
 * - Wichtige Variablen: Werte von 1 Dukat bzw. 1 Silberling werden auf "9 Silberlinge" bzw. "9 Heller" und 1
 *   Heller auf "2 Heller" umgebogen, damit immer die Pluralform der Münzeinheit verwendet werden kann.
 === Ende Beschreibung === */
void f_03c530(void *p1, int p2, int p3, int p4, unsigned p5)
{
    int f_1254a0(void *, int);
    unsigned short u2;
    int u1;
    MSG_X
    d_1c38b0 = (d_1c38b0 & 0) ? 0 : d_1c38b0; // Haelt die Registerreihenfolge bei Gleichstand
    u1 = p5 / 100;
    p5 %= 100;
    u2 = p5 / 10;
    p5 %= 10;
    if (p5 > 5) {
        u2++;
        p5 = 0;
    }
    if (u2 > 5) {
        u1++;
        u2 = 0;
    }
    if (u1 == 1) {
        u2 = 9;
        u1 = 0;
    } else if (u2 == 1) {
        p5 = 9;
        u2 = 0;
    } else if (p5 == 1) {
        p5 = 2;
    }
    if (u1 != 0) {
        pl.g[1] = u1;
        f_0e93f0(&d_1c38b0, p1, p2);
    } else if (u2) {
        pl.d[1] = u2;
        f_0e93f0(&d_1c38b0, p1, p3);
    } else {
        pl.d[1] = p5;
        f_0e93f0(&d_1c38b0, p1, p4);
    }
    f_1254a0(&pl, 0);
}
//@ f_03c630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion führt das Talent Schätzen (0x19) für einen Gegenstand aus dem Inventar des
 *   Helden p1 durch. Sie berechnet den wahren Grundwert des Gegenstands (Händlerfaktor * Basispreis / 2) und
 *   verfälscht ihn je nach Qualität der Talentprobe (f_044c90(p1, 0x19, p2)) um ±2 % bis ±20 % bei gelungener
 *   Probe bzw. um bis zu ±80 % bei misslungener Probe, bevor der Schätzpreis über f_03c530 ausgegeben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Probenmodifikator p2 (short) und eine
 *   Gegenstands-ID p3 (-1 = Gegenstand erst über f_032820 im Inventar auswählen lassen) und gibt 1 zurück.
 * - Wichtige Variablen: Ein kritischer Fehlschlag (s1 == -99) gibt überhaupt keinen Preis aus, sondern zeigt die
 *   Meldung 0x17000087 ("keine Ahnung").
 === Ende Beschreibung === */
short f_03c630(int p1, short p2, int p3)
{
    short r = 1;
    {
    union Gegenstand { int id; short wort; } item;
    short s1;
    int i5;
    int i4;
    int t;
    MSG_W
    item.id = p3;
    if (item.wort == -1) {
        s1 = f_032820(p1, 0x17000085, 1);
        if (s1 != -1) item.id = f_042a60((struct hero *)(p1), s1);
        else item.id = 0;
    } else {
        s1 = 0;
    }
    if (s1 == -1 || item.wort == 0) goto done;
    i5 = d_1c2c40[item.wort]->f_0a7820();
    i4 = d_1c2c40[item.wort]->f_0a7830() * i5;
    i4 /= 2;
    s1 = f_044c90(p1, 0x19, (signed char)p2);
    if (s1 >= 0) {
        s1 = 10 - s1;
        if (s1 < 1) s1 = 1;
        i4 *= 100;

        { int a = d_1a9820; d_1a9820 = a;
          int b = d_1c27a8; d_1c27a8 = b;
          int c = d_1c3498; d_1c3498 = c; } // Steuert die globale Registervergabe
        i5 = (i4 / 100) * (2 * s1);
        if (f_1457e0(100) > 50) i5 = -i5;
        i4 += i5;
        i4 /= 100;
        if (i4 == 0) i4 = 1;
        f_03c530(&d_1c27a8, 0x20000005, 0x20000006, 0x20000007, i4);
    } else if (s1 == -99) {
        pl.a[1] = p1;
        t = 0x17000087;
        goto send;
    } else {
        s1 = 14 - s1;
        if (s1 > 40) s1 = 40;
        i4 *= 100;
        i5 = (i4 / 100) * (2 * s1);
        if (f_1457e0(100) > 50) i5 = -i5;
        i4 += i5;
        i4 /= 100;
        f_03c530(&d_1c27a8, 0x20000005, 0x20000006, 0x20000007, i4);
    }
    pl.a[1] = p1;
    pl.b[1] = (int)d_1c2c40[item.wort];
    pl.e[1] = 1;
    pl.c[1] = f_133fe0(&d_1c3498, &d_1c27a8);
    t = 0x17000086;
send:
    f_0bf730(&d_1c2c64, t);
done:
    END_W
    ;
    }
    r = (r & 0) ? (short)0 : r; // Haelt r nach der Msg-Lebensdauer im Rueckgaberegister
    return r;
}
//@ f_03c860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion öffnet für magiebegabte Helden das Magie-Sondermenü (0x20000156) mit den
 *   Optionen "Meditation / Thonnys-Umwandlung" (Option 1: Lebensenergie in Astralenergie umwandeln, für
 *   Nicht-Magier nur mit einer Thonnysblüte 0x83), "Zauberbuch / Rezeptbuch studieren" (Option 2: Aufruf von
 *   f_03d4b0) und - exklusiv für Magier (Klasse 9) - "Stabzauber versuchen" (Option 3: nächsthöheren Stabzauber
 *   1..4 unter Einsatz permanenter Astralenergie auf den Magierstab legen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 0 (keine Rastaktion/Abbruch), 1
 *   (Stabzauber versucht) oder 2 (Meditation durchgeführt) zurück.
 * - Wichtige Variablen: Die Tabellen d_1a7244, d_1a7245, d_1a7247, d_1a7248 und d_1a7249 enthalten die drei
 *   Prüfattribute, den Probenmodifikator, die benötigten Astralpunkte und den permanenten AE-Verlust für die
 *   vier Stabzauberstufen (f_0432d0(p1)).
 === Ende Beschreibung === */
short f_03c860(int p1)
{
    short r = 0;
    short a;
    short k;
    short t;
    short w;
    Msg pl(&d_1c349c, &d_1c3870, &d_1c3498);
    t = 2;
    if (f_042350s(p1) == 9) t = 3;
    w = f_0bf820(&d_1c2c64, 0x20000156, t, 0x20000157, 0x20000159, 0x20000158);
    if (w != -1) {
        switch ((unsigned short)w) {
        case 1:
            if (f_0429b0((struct hero *)(p1)) == f_0429a0((struct hero *)(p1))) {
                pl.a[1] = p1;
                f_0bf730(&d_1c2c64, 0x200001a2);
                return 0;
            }
            if (f_042350s(p1) != 9) {
                a = f_0d4aa0(p1, 0x83);
                if (a == -1) {
                    f_0bf730(&d_1c2c64, 0x2000015a);
                    return 0;
                }
            } else {
                a = -1;
            }
            k = f_0bf7b0s(&d_1c2c64, 2, 0x2000015b, 0, f_0429b0((struct hero *)(p1)) - f_0429a0((struct hero *)(p1)), 0);
            if (k == -1) break;
            r = 2;
            if (a != -1) f_036300(p1, a, 1);
            f_044230s(p1, 1);
            if (f_044940(p1, 0, 2, 6, 0) > 0) {
                if (f_042960((struct hero *)(p1)) <= k + 8) k = f_042960((struct hero *)(p1)) - 8;
                f_044300s(p1, k + 3);
                f_0442b0s(p1, k);
            } else {
                pl.a[1] = p1;
                f_0bf730(&d_1c2c64, 0x2000015c);
            }
            break;
        case 2:
            f_03d4b0(p1, 1, 0);
            break;
        case 3:
            if (f_0432d0((struct hero *)(p1)) == 4) {
                f_0bf730(&d_1c2c64, 0x2000015e);
            } else if (f_0429a0((struct hero *)(p1)) >= d_1a7248[f_0432d0((struct hero *)(p1)) * 6]) {
                r = 1;
                if (f_044940(p1, d_1a7244[f_0432d0((struct hero *)(p1)) * 6], d_1a7245[f_0432d0((struct hero *)(p1)) * 6], d_1a7245[f_0432d0((struct hero *)(p1)) * 6], d_1a7247[f_0432d0((struct hero *)(p1)) * 6]) > 0) {
                    pl.d[1] = f_0432d0((struct hero *)(p1)) + 1;
                    f_0bf730(&d_1c2c64, 0x2000015f);
                    f_044230s(p1, d_1a7248[f_0432d0((struct hero *)(p1)) * 6]);
                    f_040730s(p1, -d_1a7249[f_0432d0((struct hero *)(p1)) * 6]);
                    f_0432e0c(p1, f_0432d0((struct hero *)(p1)) + 1);
                    f_043370(p1, 0xfd20);
                    f_125e50(&d_1c2c44, 0x6978);
                } else {
                    f_0bf730(&d_1c2c64, 0x20000160);
                    f_044230s(p1, d_1a7248[f_0432d0((struct hero *)(p1)) * 6] / 2);
                    f_125e50(&d_1c2c44, 0x2a30);
                }
            } else {
                pl.a[1] = p1;
                f_0bf730(&d_1c2c64, 0x20000163);
            }
            break;
        }
    }
    return r;
}
//@ f_03cc60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion prüft, ob ein magiebegabter Held p1 in der Zauberschule/-kategorie p2 (0..11)
 *   mindestens einen erlernten Zauberspruch (Wert >= -5) besitzt, der im aktuellen Modus (Kampf d_1bd90c != 0
 *   vs. Abenteuer d_1bd90c == 0) überhaupt anwendbar ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Index der Zauberschule p2 (0..11) und
 *   gibt 1 zurück, falls mindestens ein zauberbarer Spruch in dieser Kategorie vorhanden ist, sonst 0.
 * - Wichtige Variablen: d_1a7734[p2 * 2] und d_1a7735[p2 * 2] geben den ersten Zauberindex und die Anzahl der
 *   Sprüche der Zauberschule p2 an; d_1a7275[zauber * 14] kennzeichnet reine Kampfzauber (1) bzw. reine
 *   Nicht-Kampfzauber (-1).
 === Ende Beschreibung === */
int f_03cc60(int p1, short p2)
{
    short first = d_1a7734[(int)p2 * 2], slot, offset;
    char item;
    offset = 0;
    slot = first;
    for (; (int)offset < (int)d_1a7735[(int)p2 * 2]; ++offset) {
        item = f_0430f0((struct hero *)(p1), (int)slot);
        if ((signed char)(signed char)(item & 0xff) >= -5 &&
            ((d_1bd90c &&
              d_1a7275[(first + offset) * 14] != -1) ||
             (!*(volatile short *)&d_1bd90c &&
              d_1a7275[(first + offset) * 14] != 1)))
            return 1;
        ++slot;
    }
    return 0;
}
