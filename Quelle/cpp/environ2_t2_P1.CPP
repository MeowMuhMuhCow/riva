/* === Beschreibung (Katalog) ===
 * Einheit environ2_t2 (0x067030 - 0x068110)
 *
 * Überblick
 * Die Einheit environ2_t2 bildet die zweite Hälfte von environ2.cpp. Sie enthält weitere Versteck- und
 * Kletterauflösungen (f_067030, f_067f10), die zeitabhängige Entdeckungslogik für versteckte Raumobjekte
 * (f_0671a0-f_0676c0), eine große Interaktions- und Seil-/Werkzeug-Sequenz (f_0677b0, f_068000, f_068060) sowie
 * einen verzweigten Belohnungsdialog (f_067bf0).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 8/17 gleich (suche.py 24.10.2026, Basis environ2_t2_P1.CPP)
// environ2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x067030-0x068110
#include <string.h>
#define A(x) ((int)&(x))
#define ISZ(x) (int)((x) == 0)
#define LC(i) (i) < 10
#define LV(x) (x) < (short)10
typedef RivaTextContextData Msg;
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
struct T9 { char b[9]; ~T9(); };                           // dtor 0x0FAD20
struct T14 { char b[0x14]; T14(int a, int b, int c); ~T14(); int f_112ec0(); int f_113640(); int f_1131b0(); int f_113340(int a, int b, int c); };
struct T13e { char b[0x13e]; T13e(int a, int b, int c); ~T13e(); };
struct VT { void (*f0)(int, int, int); };
struct Obj { char pad[8]; VT *v; };
typedef short LT;
int f_036300(int p1, int p2, int p3);
int f_039320(int p1, int p2);
int f_039660(int p1, int p2);
int f_039a80(int p1, int p2);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);


int f_0603b0(int p1);
T9 *f_0606a0(int p1, int p2);
int f_060a70();
int f_069770(int p1, short p2);
int f_0bde40(int p1);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820();
int f_0bf980();
short f_0bfa20();
short f_0d4aa0(int p1, int p2);
short f_0d54f0(int p1, int p2);
int f_0dcbb0(int p1, int p2);
int f_0dd100(int p1, int p2);
int f_0de810(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_126410(int p1);
short f_1457e0(int p1);
short f_145850(int p1, int p2, int p3);
void f_068000(int p1);
extern signed char d_1bd738;
extern signed char d_1bd740;
extern signed char d_1bd748;
extern signed char d_1bd74c;
extern short d_1bd750;
extern short d_1a1a24;
extern short d_1a1a26;
extern int d_1bd91c;
extern int d_1c0004;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a1a04[];

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_067030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei d_1bd738 == 0 für den besten Sinnenschärfe-Helden die Proben auf Talent 0x33 (+1)
 *   und Sinnenschärfe (0x1d, +3). Bei Erfolg wird d_1bd738 = 1 gesetzt und Frage 0x36000084 gestellt; greift der
 *   Spieler zu (1), erhält die Gruppe das Beutepaket Nr. 10 (f_112df0/f_112ec0), während der beste Kletterer
 *   (Talent 10) 3W6 - Rüstungsschutz (mindestens 2) Lebenspunkte Schaden (f_044300) mit Meldung 0x36000087
 *   erleidet.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd738 merkt sich, ob dieses Versteck bereits entdeckt wurde.
 === Ende Beschreibung === */
static inline int eqz_067030(int a) { return a == 0; }
void *f_112df0(void *p1, int p2, int p3, int p4);
void f_112ec0(void *p1);
void *f_112e70(void *p1, int p2);

#pragma aux f_0423c0 modify exact [eax ecx];
void f_067030(void)
{
    Msg o;
    int p;
    void *q;
    short s;
    if (eqz_067030(d_1bd738)) {
        p = f_039320(d_1c0004, 0x1d);
        if (f_044c90(p, 0x33, 1) > 0) {
            if (f_044c90(p, 0x1d, 3) > 0) {
                d_1bd738 = 1;
                f_125400((int)&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
                o.tables.p[1] = p;
                if (f_0bf6f0(A(d_1c2c64), 0x36000084) == 1) {
                    p = f_039320(d_1c0004, 10);
                    o.tables.p[2] = p;
                    f_0bf730(A(d_1c2c64), 0x36000086);
                    {
                        int t = (int)operator new(0x14, mark(d_1a1a04, 0x62a));
                        q = t ? f_112df0((void *)t, 10, 0, 1) : (void *)t;
                    }
                    f_112ec0(q);
                    if (q) operator delete(f_112e70(q, 0));
                    f_060a70();
                    f_0bf730(A(d_1c2c64), 0x36000087);
                    s = f_145850(3, 6, 0) - f_0423c0((struct hero *)(p));
                    if (s < 2) s = 2;
                    f_044300(p, s);
                }
                f_1254a0((int)&o, 0);
            }
        }
    }
}

//@ f_0671a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht im 10-Elemente-Array ab p1 + 0x0c nach der Objekt-ID p2: Ist p2 noch nicht vorhanden,
 *   trägt die Funktion p2 in den ersten freien Slot (-1) ein und gibt 1 zurück; stand p2 bereits im Array, gibt
 *   sie 0 zurück.
 * - Eingaben und Rückgabe: Eingaben sind der Gebietszeiger p1 (eax) und die Objekt-ID p2 (edx, short);
 *   Rückgabewert ist 1 bei Neueintrag, sonst 0.
 * - Wichtige Variablen: Das Array *(short *)(p1 + 0x0c + 2*i) speichert bis zu zehn bereits ausgelöste
 *   Raumobjekte.
 === Ende Beschreibung === */
int f_0671a0(int p1, short p2) {
    LT i; int r = 0; int q;
    for (i = 0; (unsigned)i < 10u; i++) {
        q = (short)i * 2 + p1;
        if (*(short *)(q + 0xc) == -1) {
            *(short *)(q + 0xc) = p2;
            r = 1;
            break;
        }
        if ((short)p2 == *(short *)(q + 0xc)) {
            r = 0;
            break;
        }
    }
    return r;
}

//@ f_0671f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft mit einer tageszeitabhängigen Wahrscheinlichkeit (10 % tagsüber, 15 % nachts/frühmorgens
 *   laut Spielzeituhr d_1c2c44), ob das Raumobjekt p2 sichtbar ist (f_069770(p1 + 2, p2) == 1) und über f_0671a0
 *   neu eingetragen wird; in diesem Fall setzt die Funktion d_1bd91c = 1 und ruft die erste virtuelle Methode
 *   v->f0(p1, p2, 0) auf.
 * - Eingaben und Rückgabe: Eingaben sind der Gebietszeiger p1 (eax) und die Objekt-ID p2 (edx, short); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: d_1c2c44 liefert die aktuelle Tageszeit, d_1bd91c signalisiert eine Änderung im Raum.
 === Ende Beschreibung === */
void f_0671f0(int p1, short p2) {
    short n; int r;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (unsigned short)p2) == 1) {
            r = f_0671a0(p1, p2);
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
}

//@ f_0672b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7a aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7a an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_0672b0(int p1) {
#if 1
    f_0671f0(p1, 0x7a);
#else
    int p2 = 0x7a; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_067380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7b aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7b an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_067380(int p1) {
#if 1
    f_0671f0(p1, 0x7b);
#else
    int p2 = 0x7b; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_067450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7c aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7c an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_067450(int p1) {
#if 1
    f_0671f0(p1, 0x7c);
#else
    int p2 = 0x7c; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_067520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7d aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7d an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_067520(int p1) {
#if 1
    f_0671f0(p1, 0x7d);
#else
    int p2 = 0x7d; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_0675f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7e aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7e an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_0675f0(int p1) {
#if 1
    f_0671f0(p1, 0x7e);
#else
    int p2 = 0x7e; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_0676c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zeitabhängige Entdeckungsprüfung (f_0671f0) für das Raumobjekt 0x7f aus.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: Reicht 0x7f an die Entdeckungslogik weiter.
 === Ende Beschreibung === */
void f_0676c0(int p1) {
#if 1
    f_0671f0(p1, 0x7f);
#else
    int p2 = 0x7f; short n; int r; LT i; int q;
    n = 10;
    if (f_126410(A(d_1c2c44)) <= 0x93a8 || f_126410(A(d_1c2c44)) > 0x190c8) n += 5;
    if (f_1457e0(100) <= n) {
        if (f_069770(p1 + 2, (short)p2) == 1) {
            r = 0;
            for (i = 0; LC(i); i++) {
                q = (short)i * 2 + p1;
                if (*(short *)(q + 0xc) == -1) {
                    *(short *)(q + 0xc) = p2;
                    r = 1;
                    break;
                }
                if ((short)p2 == *(short *)(q + 0xc)) {
                    r = 0;
                    break;
                }
            }
            if (r == 1) {
                d_1bd91c = r;
                ((Obj *)p1)->v->f0(p1, (short)p2, 0);
            }
        }
    }
#endif
}

//@ f_0677b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet bei d_1bd74c == 0 mit 80 % Wahrscheinlichkeit (f_1457e0(100) < 80) eine mehrstufige
 *   Zustandsmaschine (st = 0..7) mit Grafik 0x360001 (Bild 3) und Auswahlmenü 0x36000093: Versucht die Gruppe
 *   Option 3, prüft die Funktion, ob Seile/Kletterhilfen (0x17, 0x5b, 0x5c, 0x142) im Inventar vorhanden sind,
 *   verlangt bei deren Einsatz eine Probe auf Eigenschaft 0xd (+5) und verbraucht bei Misslingen Gegenstände
 *   über f_0dd100 bzw. f_068000 oder löst über v->f0(p1, 0x80, 0) das Raumobjekt 0x80 aus; abschließend wird
 *   d_1bd74c = 14 gesetzt.
 * - Eingaben und Rückgabe: Eingabe ist der Gebietszeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: st steuert den Dialogzustand (0..7), d_1bd74c speichert den Abschlusswert 14.
 === Ende Beschreibung === */
void f_0677b0(int p1)
{
    short f_0bf820(int, ...);
    short f_0bfa20(int, ...);
    
    int st;
    T9 *o;
    int p;
    if (EQ(d_1bd74c, 0) && (int)f_1457e0(100) < 0x50) {
        st = 0;
        do {
            switch (st) {
            case 0:
                o = f_0606a0(0x360001, 3);
                f_0bde40(A(d_1c2c64));
                switch ((unsigned short)f_0bfa20(A(d_1c2c64), (int)o, 0, 0x36000093, 3,
                                                0x36000094, 0x36000095, 0x36000096)) {
                case 1:
                    f_0bf730(A(d_1c2c64), 0x36000097);
                    st = 6;
                    break;
                case 2:
                    f_0bf730(A(d_1c2c64), 0x36000098);
                    st = 6;
                    break;
                case 3:
                    st = 1;
                    break;
                }
                if (o) operator delete((void *)((int)(((RivaRasterImage*)((int)o))->f_0fad20( 0))));
                break;
            case 1:
                if ((int)f_0d54f0(d_1c0004, 0x17) != -1 ||
                    (int)f_0d54f0(d_1c0004, 0x5b) != -1 ||
                    (int)f_0d54f0(d_1c0004, 0x5c) != -1 ||
                    (int)f_0d54f0(d_1c0004, 0x142) != -1) st = 2;
                else st = 3;
                break;
            case 2:
                switch ((unsigned short)f_0bf820(A(d_1c2c64), 0x36000099, 2, 0x3600009a, 0x3600009b)) {
                case 1:
                    p = f_039660(d_1c0004, 0xd);
                    if ((int)f_044900(p, 0xd, 5) > 0) {
                        CX(m);
                        m.tables.p[1] = p;
                        f_0bf730(A(d_1c2c64), 0x3600009c);
                        st = 6;
                        CXEND(m);
                    } else {
                        if ((int)f_0d54f0(d_1c0004, 0x142) != -1) {
                            f_0dd100(d_1c0004, 0x142);
                        } else {
                            d_1bd750 = 0;
                            d_1a1a24 = 0x5c;
                            d_1a1a26 = 2;
                            f_039a80(d_1c0004, (int)f_068000);
                            d_1a1a24 = 0x17;
                            d_1a1a26 = 1;
                            f_039a80(d_1c0004, (int)f_068000);
                            d_1a1a24 = 0x5b;
                            d_1a1a26 = 1;
                            f_039a80(d_1c0004, (int)f_068000);
                        }
                        f_0bf730(A(d_1c2c64), 0x3600009d);
                        st = 7;
                    }
                    break;
                case 2:
                    st = 6;
                    break;
                }
                break;
            case 3:
                if (f_0bf6f0(A(d_1c2c64), 0x3600009e) == 1) {
                    f_0bf730(A(d_1c2c64), 0x3600009f);
                    st = 7;
                } else st = 6;
                break;
            case 4: case 5: break;
            case 6:
                d_1bd91c = 1;
                ((Obj *)p1)->v->f0(p1, 0x80, 0);
                st = 7;
                break;
            }
        } while (st != 7);
        d_1bd74c = 14;
    }
}

//@ f_067ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versetzt die Gruppe über f_0de810(d_1c0004, 99) auf den Zielpunkt 99.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c0004.
 === Ende Beschreibung === */
void f_067ac0() {
    f_0de810(d_1c0004, 99);
}

//@ f_067ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versetzt die Gruppe über f_0de810(d_1c0004, 0x62) auf den Zielpunkt 0x62.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c0004.
 === Ende Beschreibung === */
void f_067ae0() {
    f_0de810(d_1c0004, 0x62);
}

//@ f_067b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für den besten Helden im Talent 0x33, ob ihm sowohl eine Probe auf 0x33 (+10) als auch
 *   auf Sinnenschärfe (0x1d, +8) gelingt. Bei Erfolg gibt die Funktion Text 0x36000065 aus, zieht beim ersten
 *   Mal (d_1bd748 == 0) mit Text 0x36000066 8 Punkte von Wert 5 (f_044850) ab (später Text 0x36000067) und
 *   liefert 1 zurück.
 * - Eingaben und Rückgabe: Keine Parameter; Rückgabewert ist 1 (short in ax) bei erfolgreicher Entdeckung, sonst
 *   0.
 * - Wichtige Variablen: d_1bd748 merkt sich, ob der Punktabzug beim ersten Entdecken bereits erfolgt ist.
 === Ende Beschreibung === */
short f_067b00() {
    int p; int r = 0;
    p = f_039320(d_1c0004, 0x33);
    if (f_044c90(p, 0x33, 10) > 0) {
        if (f_044c90(p, 0x1d, 8) > 0) {
            CX(m);
            m.tables.p[1] = p;
            f_0bf730(A(d_1c2c64), 0x36000065);
            r = 1;
            if (ISZ(d_1bd748)) {
                f_0bf730(A(d_1c2c64), 0x36000066);
                d_1bd748 = 1;
                f_044850(p, 8, 5);
            } else {
                f_0bf730(A(d_1c2c64), 0x36000067);
            }
            CXEND(m);
        }
    }
    return r;
}

//@ f_067bf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen mehrstufigen Verhandlungs- oder Belohnungsdialog mit Bild 0x360001 (Index 0) und
 *   0x2c0005 durch: Je nach den Antworten des Spielers in den Dialogen 0x36000071..0x3600007d werden
 *   unterschiedliche Gegenstände (0x9b, 0x128, 0x94, 0x186) in ein Beute-Inventar o (T14, Paket 8) eingefügt und
 *   ein Geldbetrag v (0, 20, 40, 50 oder 30) über f_0dcbb0 ausgezahlt, bevor das Beutefenster geöffnet wird.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: o ist das Beutepaket-Objekt (T14), t9 das Dialogporträt und v die ausgezahlte Geldsumme.
 === Ende Beschreibung === */
int f_0bf980(int p1, ...);
short f_0bfa20(int p1, ...);
void f_067bf0() {
    T14 *o = new (mark(d_1a1a04, 0x7ea)) T14(8, 0, 1);
    T9 *t9 = f_0606a0(0x360001, 0);
    short r;
    short v;
    short k;
    o->f_113640();
    f_125ed0(A(d_1c2c44), 0x1e);
    do {
        r = f_0bf6f0(A(d_1c2c64), 0x36000071);
    } while ((int)r == -1);
    if (r == (short)1) {
        T13e *w = new (mark(d_1a1a04, 0x806)) T13e(0x2c0005, 0, 0);
        f_0bf980(A(d_1c2c64), (int)w, 0, 0x36000072, 0);
        delete w;
        f_125ed0(A(d_1c2c44), 0x1e);
        do {
            k = f_0bfa20(A(d_1c2c64), (int)t9, 0, 0x36000073, 2, 0x36000074, 0x36000075);
        } while (k == -1);
        if (k == 1) {
            do {
                k = f_0bfa20(A(d_1c2c64), (int)t9, 0, 0x36000076, 2, 0x200001a8, 0x200001a9);
            } while (k == -1);
            if (k == 1) {
                do {
                    k = f_0bfa20(A(d_1c2c64), (int)t9, 0, 0x36000077, 2, 0x36000078, 0x36000079);
                } while (k == -1);
                if (k == 1) {
                    f_0bf730(A(d_1c2c64), 0x3600007a);
                    o->f_113340(0x9b, 2, 0);
                    o->f_113340(0x128, 1, 0);
                    o->f_113340(0x94, 2, 0);
                    o->f_113340(0x186, 1, 0);
                    v = 0;
                } else {
                    f_0bf730(A(d_1c2c64), 0x3600007b);
                    o->f_113340(0x9b, 2, 0);
                    o->f_113340(0x128, 1, 0);
                    o->f_113340(0x94, 2, 0);
                    v = 0x14;
                }
            } else {
                f_0bf730(A(d_1c2c64), 0x3600007c);
                o->f_113340(0x128, 1, 0);
                o->f_113340(0x94, 1, 0);
                v = 0x28;
            }
        } else {
            do {
                k = f_0bfa20(A(d_1c2c64), (int)t9, 0, 0x3600007d, 2, 0x3600007e, 0x3600007f);
            } while (k == -1);
            if (k == 1) {
                f_0bf730(A(d_1c2c64), 0x36000080);
                v = 0x32;
            } else {
                f_0bf730(A(d_1c2c64), 0x36000081);
                o->f_113340(0x186, 1, 0);
                v = 0x1e;
            }
        }
        f_0dcbb0(d_1c0004, v);
        if (o->f_1131b0() == 1)
            o->f_112ec0();
    }
    delete o;
    delete t9;
}
//@ f_067f10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wertet den Ausgang (p3) des Kletterversuchs eines Helden p2 aus f_066e50 aus: Bei Erfolg (p3
 *   == 1) und mindestens 12 aktuellen Lebenspunkten (s >= 12) überwindet der Held das Hindernis mit 7 LE Schaden
 *   (0x3600008f/0x36000090), setzt d_1bd740 = 1 und schaltet f_0603b0(11) frei; hat er weniger als 12 LE, stürzt
 *   er auf 0 LE ab (0x3600008e). Bei Misserfolg (p3 == 0) kann er sich mit s >= 10 und einer Klettern-Probe
 *   (Talent 10, +0) mit 5 LE Schaden retten (0x36000091), andernfalls verliert er sämtliche Lebenspunkte s
 *   (0x36000092).
 * - Eingaben und Rückgabe: Eingaben sind der Gebietszeiger p1 (eax, unbenutzt), der Heldenzeiger p2 (edx) und
 *   das Flag p3 (ebx, 1 = erste Probe bestanden); kein Rückgabewert (void).
 * - Wichtige Variablen: s enthält die aktuellen Lebenspunkte des Helden (f_042960), d_1bd740 markiert den
 *   Erfolg.
 === Ende Beschreibung === */
void f_067f10(int p1, int p2, int p3) {
    short s; int v;
    CX(m);
    m.tables.p[2] = p2;
    s = f_042960((struct hero *)(p2));
#if 0
    if (p3 == 1) {
        v = s;
        if (v < 12) {
            f_0bf730(A(d_1c2c64), 0x3600008e);
            goto l1;
        }
        f_0bf730(A(d_1c2c64), 0x3600008f);
        f_044300(p2, 7);
        f_0bf730(A(d_1c2c64), 0x36000090);
        d_1bd740 = 1;
        f_0603b0(11);
        goto fin;
    } else {
        if (s >= 10) {
            if (f_044c90(p2, 10, 0) > 0) {
                f_0bf730(A(d_1c2c64), 0x36000091);
                v = 5;
                goto l1;
            }
        }
        f_0bf730(A(d_1c2c64), 0x36000092);
        v = s;
    }
l1:
    f_044300(p2, v);
fin:
#else
    if (p3 == 1) {
        v = s;
        if (v < 12) {
            f_0bf730(A(d_1c2c64), 0x3600008e);
            f_044300(p2, v);
        } else {
            f_0bf730(A(d_1c2c64), 0x3600008f);
            f_044300(p2, 7);
            f_0bf730(A(d_1c2c64), 0x36000090);
            d_1bd740 = 1;
            f_0603b0(11);
        }
    } else {
        if (s >= 10 && f_044c90(p2, 10, 0) > 0) {
            f_0bf730(A(d_1c2c64), 0x36000091);
            f_044300(p2, 5);
        } else {
            f_0bf730(A(d_1c2c64), 0x36000092);
            f_044300(p2, s);
        }
    }
#endif
    CXEND(m);
}

//@ f_068000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Helden-Callback zum Einsammeln von Seilen/Klettergegenständen aus dem Inventar eines Helden
 *   p1: Sucht wiederholt nach dem Gegenstand d_1a1a24 (f_0d4aa0), entfernt jeweils ein Exemplar (f_036300) und
 *   erhöht den Zähler d_1bd750 um den Wert d_1a1a26, bis d_1bd750 >= 10 erreicht ist oder der Held keinen
 *   passenden Gegenstand mehr besitzt.
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd750 summiert den Seil-/Längenwert, d_1a1a24 ist die gesuchte Gegenstands-ID und
 *   d_1a1a26 deren Wertbeitrag.
 === Ende Beschreibung === */
void f_068000(int p1) {
    short s = 0x2a;
    if (LV(d_1bd750)) {
        do {
            if (s == -1) return;
            s = f_0d4aa0(p1, d_1a1a24);
            if (s != -1) {
                f_036300(p1, s, 1);
                d_1bd750 += d_1a1a26;
            }
        } while (LV(d_1bd750));
    }
}

//@ f_068060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht der Gruppe die für eine Kletterstelle benötigten Seile ab: Besitzt die Gruppe den
 *   Gegenstand 0x142, wird dieser direkt über f_0dd100 entfernt; andernfalls sammelt die Funktion über f_039a80
 *   und f_068000 nacheinander Gegenstände der Typen 0x5c (Wert 2), 0x17 (Wert 1) und 0x5b (Wert 1) ein, bis ein
 *   Gesamtwert von 10 erreicht ist.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Setzt d_1bd750, d_1a1a24 und d_1a1a26 für die Sammel-Callbacks.
 === Ende Beschreibung === */
void f_068060() {
    if (f_0d54f0(d_1c0004, 0x142) != -1) {
        f_0dd100(d_1c0004, 0x142);
    } else {
        d_1bd750 = 0;
        d_1a1a24 = 0x5c;
        d_1a1a26 = 2;
        f_039a80(d_1c0004, (int)f_068000);
        d_1a1a24 = 0x17;
        d_1a1a26 = 1;
        f_039a80(d_1c0004, (int)f_068000);
        d_1a1a24 = 0x5b;
        d_1a1a26 = 1;
        f_039a80(d_1c0004, (int)f_068000);
    }
}
