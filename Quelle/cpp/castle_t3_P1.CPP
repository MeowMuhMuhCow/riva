/* === Beschreibung (Katalog) ===
 * Einheit castle_t3 (0x0002c7c0 - 0x0002d9c0)
 *
 * Überblick
 *
 * Die Einheit castle_t3 bildet den dritten und letzten Teil der Dungeon- und Ereignislogik für die Festung /
 * Burg von Riva (CASTLE.CPP). Sie umfasst Tempel-/Frevler-Szenen, Schaltermechanismen, Krankheits- oder
 * Verletzungsfallen, das Bergen von Questgegenständen, zufällige Patrouillen-Begegnungen anhand der Tabelle
 * d_1a06a8 sowie animierte Tür- und Wachposten-Sequenzen.
 === Ende Beschreibung === */
#include "R_FIX.H"
// P3 27/36 gleich (suche.py 26.10.2026, Basis castle_t3_P1.CPP)
#define EQI(x,v) (((x)==(v))?1:0)
#define EQI0(x) (((x)==0)?1:0)
// P1 9/35 gleich
// castle.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02C7C0-0x02D9C0
#include <string.h>
#include "RIVAMEM.H"



extern const char d_1a06f0[];           // Text 0x1A06F0
struct Tb { short id; short a; short b; short c; short d; };
extern Tb d_1a06a8[];
extern signed char d_1bc820, d_1bc824, d_1bc828, d_1bc82c, d_1bc830, d_1bc858, d_1bc85c;
extern unsigned short d_1bc848;
extern signed char d_1bc864, d_1bc868, d_1bc86c, d_1bc874, d_1bc878, d_1bc87c, d_1bc888;
extern signed char d_1bc860;
extern short d_1bc880, d_1bd922;
extern int d_1bd91c, d_1c0004;
extern short d_1a9820;
extern int d_1c2c64, d_1c2c44, d_1c2c00, d_1c2edc, d_1c349c, d_1c3870;
#define EQ(c, v) ((c) == (v))
#define M64 ((int)&d_1c2c64)
#define M44 ((int)&d_1c2c44)
#define M00 ((int)&d_1c2c00)
#define MDC ((int)&d_1c2edc)
struct Q { char b[4]; ~Q(); };                                   // dtor 0x0FAD20
Q *f_0606a0(int a, int b);
struct Pk {
    char b[12];
    Pk(int a, int b2); ~Pk();                                    // 0x05F190 / 0x05F220
    int f_05f580(); void f_05f480(); void f_05f4f0(int a); void f_05f280(int a);
    void f_05f470(); void f_05f6e0(int a); void f_05f5a0(int a);
};
struct Zt { int a; int *p; char rest[52]; Zt(int *x, int *y, int z); ~Zt(); };   // 0x125400 / 0x1254A0
struct VS { short (*fn)(int, int, int); };
struct VI { int (*fn)(int, int, int); };
struct OS { char b[8]; VS *v; };
struct OI { char b[8]; VI *v; };
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
short f_0398c0(int p1, void (*cb)(), int *out);
int f_040900(int p1, int p2);
int f_044300(int p1, int p2);
int f_054ca0(int p1, int p2);
int f_057220(int p1, int p2, int p3);
int f_060360(int p1);
int f_0603b0(int p1);
int f_060740(int p1, int p2);
int f_060770(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_060a70();
int f_069770(int p1, int p2);
int f_091f70(int p1);
int f_0bde40(int p1);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0bfa20(int a, Q *q, int b, int id, int n, ...);
int f_0db820(int p1, int p2);
int f_0db8b0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcbb0(int p1, int p2);
int f_0dcf00(int p1, int p2, int p3);
int f_0dd750(int p1, int p2);
int f_0de7e0(int p1);
short f_0d54f0(int p1, int p2);
short f_10b890(int p1);
int f_125ed0(int p1, int p2);
short f_145760(int p1, int p2);
short f_1457e0(int p1);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_147323_frame(int, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp];
void f_02dda0();
void f_02d6e0();

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_02c7c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt bei d_1bc830 == 0 das Porträt 0x330001 (Index 3) mit der Entscheidungsfrage 0x3300004f
 *   an. Wählt der Spieler Option 1 (0x33000050), erscheint Text 0x33000052, das Flag d_1bc830 wird auf 1 gesetzt
 *   und der Gunst-/Rufwert über f_054ca0(1, -500) stark gesenkt; bei Option 2 oder Abbruch wird die
 *   Animationssequenz 0x330008 am Objekt 0x1f47 abgespielt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet den Einmal-Merker d_1bc830, das Textsystem d_1c2c64 und das Szene-Objekt Pk(0,
 *   0x1f47).
 === Ende Beschreibung === */
void f_02c7c0()
{
    if (EQI(d_1bc830, 0)) {
        short r;
        Q *q = f_0606a0(0x330001, 3);
        f_0bde40(M64);
        r = f_0bfa20(M64, q, 0, 0x3300004f, 2, 0x33000050, 0x33000051);
        delete q;
        switch (r) {
        case 1:
            f_0bf730(M64, 0x33000052);
            {
                signed char one = 1;
                d_1bc830 = one;
            }
            f_054ca0(1, -500);
            return;
        case 2:
        case -1:
            {
                Pk *p = new (mark(d_1a06f0, 0x955)) Pk(0, 0x1f47);
                if (EQI0(p->f_05f580())) p->f_05f480();
                f_060800(0x330008, 1, 0);
                p->f_05f4f0(0);
                delete p;
            }
            return;
        default:
            break;
        }
    }
}
//@ f_02c8f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Textmeldung 0x33000053 genau dann aus, wenn das Ereignisflag d_1bc874 bereits auf 1
 *   steht.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft das Statusbyte d_1bc874.
 === Ende Beschreibung === */
void f_02c8f0()
{
    if (EQI(d_1bc874, 1)) f_0bf730(M64, 0x33000053);
}

//@ f_02c920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft f_0603b0(0x13) auf, um die zugehörige Aktion in der Burg auszuführen.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_0603b0.
 === Ende Beschreibung === */
void f_02c920()
{
    f_0603b0(0x13);
}

//@ f_02c930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Betreten (d_1bc874 == 0) das Porträt 0x330001 (Index 4) mit der Textmeldung
 *   0x33000054 an und setzt anschließend d_1bc874 = 1.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Setzt das Statusbyte d_1bc874 = 1.
 === Ende Beschreibung === */
void f_02c930()
{
    if (EQI(d_1bc874, 0)) {
        Q *q = f_0606a0(0x330001, 4);
        f_0bfa20(M64, q, 0, 0x33000054, 0);
        delete q;
        d_1bc874 = 1;
    }
}

//@ f_02c990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung im Spiel.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02c990(void)
{
}

//@ f_02c9a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt der Gruppe, sofern d_1bc86c == 1 ist, einen Mechanismus in der Burg zu betätigen
 *   (0x33000055 bzw. 0x33000056), spielt das Geräusch 0x330010 sowie die Animation 0x33000a ab und schaltet die
 *   beiden Objekte 0x1f66 und 0x1f67 um. *(Hinweis: Hier liegt ein Originalfehler vor, da im else-Zweig beim
 *   Zurückschalten versehentlich erneut d_1bc82c = 1 statt d_1bc82c = 0 geschrieben wird.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet die Flags d_1bc86c und d_1bc82c sowie den Sound-Manager d_1c2edc.
 === Ende Beschreibung === */
void f_02c9a0()
{
    int bVar1 = 0;
    int iVar2;
    int snd;
    if (EQI(d_1bc86c, 1)) {
        if (EQI(d_1bc82c, 0)) {
            iVar2 = f_0bf6f0(M64, 0x33000055);
            if (iVar2 == 1) {
                f_147323(MDC, 0x330010, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
                f_060800(0x33000a, 0, 0);
                f_060740(0x1f67, 1);
                f_060770(0x1f66, 0);
                f_0607e0(0x1f67, 1);
                f_0607e0(0x1f66, 1);
                d_1bc82c = 1;
                goto L2cae5;
            }
        } else {
            iVar2 = f_0bf6f0(M64, 0x33000056);
            if (iVar2 == 1) {
                f_147323(MDC, 0x330010, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
                f_060800(0x33000a, 0, 0);
                f_060770(0x1f66, 0);
                f_060740(0x1f67, 1);
                f_0607e0(0x1f67, 0);
                f_0607e0(0x1f66, 0);
#if FIX_R056
                d_1bc82c = 0;
#else
                d_1bc82c = 1;
#endif
                goto L2cae5;
            }
        }
    }
    bVar1 = 1;
L2cae5:
    if (bVar1 == 1) f_060360(0xe);
}
//@ f_02cb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Meldung 0x33000057 aus, ermittelt über f_0398c0 alle handlungsfähigen Helden der
 *   Gruppe und würfelt für die ersten bis zu drei Gruppenmitglieder jeweils eine 50-%-Chance (f_1457e0(100) <
 *   50), bei der das betroffene Mitglied über f_040900(held, 1) verletzt oder krank wird.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt das Heldenfilter-Callback f_02dda0 und die Gruppenliste d_1c0004.
 === Ende Beschreibung === */
void f_02cb00()
{
    int arr[7];
    f_0bf730(M64, 0x33000057);
    short sVar1 = f_0398c0(d_1c0004, f_02dda0, arr);
    short sVar3;
    for (sVar3 = 0; sVar3 < sVar1; sVar3++) {
        if (3 <= sVar3) break;
        short sVar2 = f_1457e0(100);
        if (sVar2 < 0x32) f_040900(arr[sVar3], 1);
    }
}

//@ f_02cb70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt f_060360(0x0f) aus und prüft bei d_1bc878 == 0, ob die Gruppe den wichtigen Gegenstand
 *   0x187 bei sich trägt (f_0d54f0). Ist er vorhanden, werden d_1bc878 = 1, der Questfortschritt 0x1a (f_091f70)
 *   und der Tagebucheintrag 0x803000a gesetzt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft und setzt d_1bc878 und aktualisiert das Tagebuch d_1c2c00.
 === Ende Beschreibung === */
void f_02cb70()
{
    f_060360(0xf);
    if (EQI(d_1bc878, 0)) {
        short sVar1 = f_0d54f0(d_1c0004, 0x187);
        if (sVar1 != -1) {
            d_1bc878 = 1;
            f_091f70(0x1a);
            f_057220(M00, 0x803000a, 0);
        }
    }
}

//@ f_02cbd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Aktion.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02cbd0(void)
{
}

//@ f_02cbe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft über f_069770(p1 + 2, 0x1c), ob die Aktion 0x1c am übergebenen Burg-Objekt zulässig ist,
 *   und ruft sie gegebenenfalls über dessen virtuelle Methodentabelle auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt die virtuelle Tabelle am Offset +0x08 von p1.
 === Ende Beschreibung === */
void f_02cbe0(int p1)
{
    int iVar1 = f_069770(p1 + 2, 0x1c);
    if (iVar1 != 0) ((OI *)p1)->v->fn(p1, 0x1c, 0);
}

//@ f_02cc10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler über 0x33000059, ob ein Bereich durchsucht werden soll; bei Bestätigung
 *   erscheint die Meldung 0x3300005a und die Spieluhr rückt um 15 Minuten (0x0f) vor.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und die Spieluhr d_1c2c44.
 === Ende Beschreibung === */
void f_02cc10()
{
    int iVar1 = f_0bf6f0(M64, 0x33000059);
    if (iVar1 == 1) {
        f_0bf730(M64, 0x3300005a);
        f_125ed0(M44, 0xf);
    }
}

//@ f_02cc50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt beim ersten Mal (d_1bc828 == 0) über 0x3300005b, ob gesucht werden soll. Bei Bestätigung
 *   findet der Gruppenanführer nach 15 Minuten Suchzeit (0x3300005c) den Gegenstand 0x188 (f_0dcf00) und
 *   d_1bc828 wird auf 1 gesetzt; später erscheint nur noch 0x3300005d.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet das Einmal-Flag d_1bc828, die Spieluhr d_1c2c44 und d_1c0004.
 === Ende Beschreibung === */
void f_02cc50()
{
    extern int d_1c3498;
    if (EQI(d_1bc828, 0)) {
        int iVar1 = f_0bf6f0(M64, 0x3300005b);
        if (iVar1 == 1) {
            Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
            int uVar2 = f_038c40(d_1c0004);
            z.p[1] = uVar2;
            f_0bf730(M64, 0x3300005c);
            f_125ed0(M44, 0xf);
            f_0dcf00(d_1c0004, 0x188, 1);
            d_1bc828 = 1;
            return;
        }
    } else {
        f_0bf730(M64, 0x3300005d);
    }
}

//@ f_02cd10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Gruppenanführer in den Textkontext ein und gibt die Meldung 0x3300005e aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02cd10()
{
    extern int d_1c3498;
    Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
    z.p[1] = f_038c40(d_1c0004);
    f_0bf730(M64, 0x3300005e);
}

//@ f_02cd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02cd60(void)
{
}

//@ f_02cd70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt im Dialogfenster den Text 0x3300005f an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64.
 === Ende Beschreibung === */
void f_02cd70()
{
    f_0bf730(M64, 0x3300005f);
}

//@ f_02cd90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02cd90(void)
{
}

//@ f_02cda0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt den Gruppenanführer beim ersten Auslösen (d_1bc824 == 0) unter Anzeige von 0x33000060
 *   und 15 Minuten Zeitverbrauch den Gegenstand 0xcf finden und setzt d_1bc824 = 1; bei weiteren Besuchen wird
 *   0x33000061 ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert d_1bc824, die Spieluhr d_1c2c44 und das Gruppeninventar über f_0dcf00.
 === Ende Beschreibung === */
void f_02cda0()
{
    extern int d_1c3498;
    if (EQI(d_1bc824, 0)) {
        Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
        z.p[1] = f_038c40(d_1c0004);
        f_0bf730(M64, 0x33000060);
        f_125ed0(M44, 0xf);
        f_0dcf00(d_1c0004, 0xcf, 1);
        d_1bc824 = 1;
    } else {
        f_0bf730(M64, 0x33000061);
    }
}

//@ f_02ce40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Meldung 0x33000063 aus, falls sowohl d_1bc868 als auch d_1bc860 bereits gesetzt sind,
 *   andernfalls die Meldung 0x33000062.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest die Statusbytes d_1bc868 und d_1bc860.
 === Ende Beschreibung === */
void f_02ce40(void)
{
  if (EQB(d_1bc868, 0) || EQB(d_1bc860, 0))
    f_0bf730(M64, 0x33000062);
  else
    f_0bf730(M64, 0x33000063);
}

//@ f_02ce80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt im Textfenster die Beschreibung 0x33000064 an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_02ce80()
{
    f_0bf730(M64, 0x33000064);
}

//@ f_02cea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft f_0603b0(0x14) auf.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_0603b0.
 === Ende Beschreibung === */
void f_02cea0()
{
    f_0603b0(0x14);
}

//@ f_02ceb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird ausgelöst, wenn d_1bc868 == 1, d_1bc864 == 1 und d_1bc86c == 0 gelten. Je nach Rückgabe
 *   von f_10b890(2) erhält die Gruppe entweder 10 Abenteuerpunkte (f_0dcbb0) oder die Meldung 0x2002000f samt
 *   Zustandsänderung am Objekt Pk(0x10, 0x1f4c). Anschließend werden d_1bc86c = 1, der Tagebucheintrag 0x8030007
 *   und der Queststatus 0x19 gesetzt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert d_1bc86c, das Tagebuch d_1c2c00 und den Questfortschritt über f_091f70.
 === Ende Beschreibung === */
void f_02ceb0()
{
    if (EQI(d_1bc868, 1) && EQI(d_1bc864, 1) && EQI(d_1bc86c, 0)) {
        short sVar1 = f_10b890(2);
        if (sVar1 == 1) {
            f_0dcbb0(d_1c0004, 10);
        } else {
            f_0bf730(M64, 0x2002000f);
            f_0dd750(d_1c0004, 0x165f);
            Pk *p1 = new (mark(d_1a06f0, 0xb55)) Pk(0x10, 0x1f4c);
            p1->f_05f470();
            delete p1;
        }
        d_1bc86c = 1;
        f_057220(M00, 0x8030007, 0);
        f_091f70(0x19);
    }
}

void f_02cfb0(void) {}
//@ f_02cfc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft f_060360(0x10) auf, um das zugehörige Element in der Burg umzuschalten.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_060360.
 === Ende Beschreibung === */
void f_02cfc0()
{
    f_060360(0x10);
}

//@ f_02cfd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt den Gruppenanführer in den Textkontext ein und zeigt die Meldung 0x33000065 an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02cfd0()
{
    extern int d_1c3498;
    Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
    z.p[1] = f_038c40(d_1c0004);
    f_0bf730(M64, 0x33000065);
}

//@ f_02d020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02d020(void)
{
}

//@ f_02d030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt f_060360(0x11) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_060360.
 === Ende Beschreibung === */
void f_02d030()
{
    f_060360(0x11);
}

//@ f_02d040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt bei d_1bc820 == 0 das Porträt 0x330001 (Index 5) mit dem Text 0x33000066 an, startet die
 *   virtuelle Aktion 0x11 am Objekt p1 und setzt bei Erfolg (sVar1 == 0) das Flag d_1bc820 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft und setzt den Merker d_1bc820.
 === Ende Beschreibung === */
void f_02d040(int p1)
{
    if (EQI(d_1bc820, 0)) {
        Q *p1_00 = f_0606a0(0x330001, 5);
        f_0bfa20(M64, p1_00, 0, 0x33000066, 0);
        delete p1_00;
        short sVar1 = ((OS *)p1)->v->fn(p1, 0x11, 0);
        if (sVar1 == 0) d_1bc820 = 1;
    }
}

//@ f_02d0c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft über f_069770(p1 + 2, 0x12), ob die Aktion 0x12 bereit ist, und führt sie über die
 *   virtuelle Methodentabelle von p1 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger p1 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt die virtuelle Methodentabelle von p1.
 === Ende Beschreibung === */
void f_02d0c0(int p1)
{
    int iVar1 = f_069770(p1 + 2, 0x12);
    if (iVar1 != 0) ((OI *)p1)->v->fn(p1, 0x12, 0);
}

//@ f_02d0f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02d0f0(void)
{
}

//@ f_02d100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft über f_069770(p1 + 2, 0x10), ob die Aktion 0x10 ausführbar ist, und gibt das Ergebnis
 *   des virtuellen Methodenaufrufs zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt den Statuscode der Aktion zurück.
 * - Wichtige Variablen: Greift auf p1 + 2 und die virtuelle Tabelle bei p1 + 8 zu.
 === Ende Beschreibung === */
int f_02d100(int p1)
{
    int iVar1 = f_069770(p1 + 2, 0x10);
    if (iVar1 != 0) iVar1 = ((OI *)p1)->v->fn(p1, 0x10, 0);
    return iVar1;
}

//@ f_02d130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02d130(void)
{
}

//@ f_02d140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler über 0x33000067, ob eine Aktion ausgeführt werden soll. Bei Bestätigung
 *   ertönt das Geräusch 0x330012, es erscheint Text 0x33000068 und in einer Schleife wird die virtuelle Aktion
 *   0x1a mit d_1bd91c = 1 wiederholt (unter Ausgabe von 0x33000069), bis sie einen Wert ungleich null
 *   zurückgibt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt das Ergebnis der Aktion zurück.
 * - Wichtige Variablen: Setzt vor jedem Versuch d_1bd91c = 1 und nutzt d_1c2edc für den Soundeffekt.
 === Ende Beschreibung === */
int f_02d140(int p1)
{
    int iVar2 = f_0bf6f0(M64, 0x33000067);
    if (iVar2 == 1) {
        int iVar3;
        f_147323(MDC, 0x330012, 0x7fff, 0x8000, (iVar3 = *(int *)&d_1a9820), 0, 1);
        f_0bf730(M64, 0x33000068);
        for (;;) {
            d_1bd91c = 1;
            short sVar1 = ((OS *)p1)->v->fn(p1, 0x1a, 0);
            iVar2 = (int)sVar1;
            if (iVar2 != 0) break;
            f_0bf730(M64, 0x33000069);
        }
    }
    return iVar2;
}

//@ f_02d1c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt beim ersten Auslösen (d_1bc864 == 0) den Status über f_10b890(3), markiert d_1bc864 = 1,
 *   meldet den Questfortschritt 0x18, lässt 15 Minuten Spielzeit vergehen und trägt die beiden Notizen 0x8030008
 *   sowie 0x8030009 in das Tagebuch ein.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert d_1bc864, die Spieluhr d_1c2c44 und das Tagebuch d_1c2c00.
 === Ende Beschreibung === */
void f_02d1c0()
{
    if (EQI(d_1bc864, 0)) {
        f_10b890(3);
        d_1bc864 = 1;
        f_091f70(0x18);
        f_125ed0(M44, 0xf);
        f_057220(M00, 0x8030008, 0);
        f_057220(M00, 0x8030009, 0);
    }
}

//@ f_02d230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht die übergebene Begegnungskennung p2 in der 7-teiligen Burg-Begegnungstabelle d_1a06a8.
 *   Abhängig davon, ob d_1bc848 bereits gesetzt ist, wird die erste oder zweite Wahrscheinlichkeitsspalte (a/c
 *   bzw. b/d) gewählt und mit einem Prozentwurf f_1457e0(100) verglichen; fällt der Wurf klein genug aus, wird
 *   der Kampf mit der Parameterkennung uVar5 in d_1bd922 ausgelöst. *(Hinweis: Wird p2 nicht in d_1a06a8
 *   gefunden, bleibt idx = -1 und die Funktion liest ungeprüft d_1a06a8[-1].)*
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Objektzeiger p1 und die Begegnungs-ID p2 und gibt das
 *   Kampfergebnis oder -1 zurück.
 * - Wichtige Variablen: Liest die 7 Einträge der Tabelle d_1a06a8, das Flag d_1bc848 und setzt d_1bd922 sowie
 *   d_1bd91c.
 === Ende Beschreibung === */
short f_02d230(int p1, short p2)
{
    short local_14 = -1;
    short idx = -1;
    short i;
    for (i = 0; (unsigned)i < 7; i++) {
        int id = d_1a06a8[i].id;
        if (id == (int)p2) { id = (id & 0) ? 0 : id; idx = i; break; } // Haelt Registerzuteilung im Suchschleifen-Abbruch
    }
#if FIX_R056
    if (idx != -1) {
#else
    {
#endif
        { int hold = d_1bd91c; d_1bd91c = hold; } // Haelt Konfliktgraph vor Tabellen-Feldzugriff
        short sVar1;
        short idraw = d_1a06a8[idx].id;
        int flag = *(signed char *)&d_1bc848;
        sVar1 = idraw;
        short sVar4;
        short uVar5;
        if (EQI(flag, 0)) {
            sVar4 = d_1a06a8[idx].a;
            uVar5 = d_1a06a8[idx].c;
        } else {
            { short hold2 = d_1bd922; d_1bd922 = hold2; } // Haelt Registerwahl im zweiten Zweig
            sVar4 = d_1a06a8[idx].b;
            uVar5 = d_1a06a8[idx].d;
        }
        short sVar3 = f_1457e0(100);
        sVar3 = (sVar3 & 0) ? 0 : sVar3; // Haelt Zufallswert in ax fuer direkten Vergleich cmp ax,dx
        if (sVar3 <= sVar4) {
            d_1bd922 = uVar5;
            d_1bd91c = 1;
            local_14 = ((OS *)p1)->v->fn(p1, (int)sVar1, 0);
        }
    }
    return local_14;
}

//@ f_02d310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über den Zahlenregler f_0bf7b0 (0x3300004c) ab, wie viele Dukaten (maximal Gruppengeld /
 *   10, gekappt auf 999) eingezahlt werden sollen, zieht den Betrag in Silbertalern (iVar2 * 10) vom
 *   Gruppenvermögen ab, erhöht d_1bc880 und rechnet den Betrag über f_054ca0(1, iVar2) an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert d_1bc880 und das Gruppenvermögen von d_1c0004.
 === Ende Beschreibung === */
void f_02d310()
{
    int iVar2 = f_0de7e0(d_1c0004);
    short sVar1 = (short)(iVar2 / 10);
    if (999 < sVar1) sVar1 = 999;
    sVar1 = f_0bf7b0(M64, 3, 0x3300004c, 0, (int)sVar1, 0);
    iVar2 = (int)sVar1;
    if (0 < iVar2) {
        d_1bc880 = d_1bc880 + sVar1;
        f_0db8b0(d_1c0004, iVar2 * 10);
        f_054ca0(1, iVar2);
    }
}

//@ f_02d390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt dem Spieler über den Zahlenregler 0x3300004d, bis zu d_1bc880 (maximal 999)
 *   hinterlegte Dukaten wieder aus dem Depot zu nehmen, schreibt iVar2 * 10 dem Gruppenvermögen gut und zieht
 *   den Betrag über f_054ca0(1, -iVar2) wieder vom Gunstzähler ab.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Vermindert d_1bc880 und erhöht das Goldkonto der Gruppe über f_0db820.
 === Ende Beschreibung === */
void f_02d390(int p1)
{
    short sVar1 = (short)d_1bc880;
    short sVar2 = sVar1;
    if (999 < sVar1) sVar2 = 999;
    short sVar3 = f_0bf7b0(M64, 3, 0x3300004d, 0, (short)sVar2, 0);
    int iVar2 = (int)sVar3;
    if (0 < iVar2) {
        d_1bc880 = d_1bc880 - sVar3;
        f_0db820(d_1c0004, iVar2 * 10);
        f_054ca0(1, -iVar2);
    }
}

//@ f_02d410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sammelt alle handlungsfähigen Gruppenmitglieder über f_0398c0(d_1c0004, f_02dda0, arr) und
 *   gibt den Zeiger auf den hintersten Helden der Marschreihenfolge zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt den Heldenzeiger des letzten
 *   handlungsfähigen Gruppenmitglieds zurück.
 * - Wichtige Variablen: Nutzt die Filterfunktion f_02dda0 und d_1c0004.
 === Ende Beschreibung === */
int f_02d410()
{
    int arr[7];
    short sVar1 = f_0398c0(d_1c0004, f_02dda0, arr);
    return arr[sVar1 - 1];
}

//@ f_02d440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist die Falle noch aktiv (d_1bc858 == 0), wird das Fallengeräusch 0x330011 abgespielt, der
 *   letzte handlungsfähige Held der Gruppe ermittelt, mit dessen Namen die Meldung 0x33000058 ausgegeben und ihm
 *   über f_044300(p1, 10) ein Schaden von 10 Lebenspunkten zugefügt; ist die Falle bereits entschärft (d_1bc858
 *   != 0), erscheint nur 0x606000d.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft das Fallenflag d_1bc858 und schädigt den Schlussmann der Gruppe.
 === Ende Beschreibung === */
void f_02d440()
{
    extern int d_1c3498;
    if (EQI(d_1bc858, 0)) {
        int snd = *(int *)&d_1a9820;
        f_147323_frame(MDC, 0x330011, 0x7fff, 0x8000, snd, 0, 1);
        Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
        int arr[7];
        short sVar1 = f_0398c0(d_1c0004, f_02dda0, arr);
        int p1 = arr[sVar1 - 1];
        z.p[1] = p1;
        f_0bf730(M64, 0x33000058);
        f_044300(p1, 10);
        return;
    }
    f_0bf730(M64, 0x606000d);
}

//@ f_02d500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft am Objekt Pk(0, p2), ob der Durchgang noch geschlossen ist, spielt das Geräusch 0x33000e
 *   mit einem zufälligen Spruch (0x33000003+0..4 bei Gruppe, 0x33000008+0..1 bei Einzelheld) ab und fragt über
 *   0x3300000a, ob eingegriffen werden soll. Bei Bestätigung wird das Objekt geöffnet und der Kampf 0x0b (mit
 *   d_1bc888) gestartet.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Objektzeiger p1 und die Objektkennung p2 entgegen und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1bc888, d_1bd91c, d_1bd922 und den Sound-Manager d_1c2edc.
 === Ende Beschreibung === */
void f_02d500(int p1, short p2)
{
    Pk *pk = new (mark(d_1a06f0, 0xd64)) Pk(0, p2);
    if (EQI(pk->f_05f580(), 0) == 1) {
        {
            extern int d_1c3498;
            Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
            short n = f_0db9a0(d_1c0004);
            int id = 0;
            if (n > 1) {
                int r = f_145760(0, 4);
                int value = f_039320(d_1c0004, 0x33);
                z.p[1] = value;
                id = r + 0x33000003;
            } else {
                int r = f_145760(0, 1);
                int value = f_038c40(d_1c0004);
                z.p[1] = value;
                id = r + 0x33000008;
            }
            int snd;
            f_147323_frame(MDC, 0x33000e, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
            f_0bf730(M64, id);
        }
        if (f_0bf6f0(M64, 0x3300000a) == 1) {
            pk->f_05f6e0(0);
            int state = d_1bc888;
            int obj = p1;
            if (EQI(state, 0)) {
                d_1bd91c = 1;
                f_0bf730(M64, 0x3300001f);
                d_1bd922 = 5;
                if (((OS *)obj)->v->fn(obj, 0xb, 0) == 0) d_1bc888 = 1;
            } else {
                d_1bd91c = 1;
                f_0bf730(M64, 0x33000020);
                ((OI *)obj)->v->fn(obj, 0xb, 0);
            }
            f_060a70();
            pk->f_05f5a0(0);
        }
    } else pk->f_05f280(0);
    delete pk;
}

//@ f_02d6e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt das Geräusch 0x33000e ab und gibt abhängig davon, ob mehrere Helden oder nur ein
 *   einzelner Held unterwegs sind, einen zufällig ausgewählten Ausruf (0x33000003..0x33000007 bzw.
 *   0x33000008..0x33000009) im Textfenster aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt den Zufallsgenerator f_145760, d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02d6e0()
{
    extern int d_1c3498;
    Zt z(&d_1c349c, &d_1c3870, (int)&d_1c3498);
    short n = f_0db9a0(d_1c0004);
    int id;
    if (n > 1) {
        id = f_145760(0, 4) + 0x33000003;
        z.p[1] = f_039320(d_1c0004, 0x33);
    } else {
        id = f_145760(0, 1) + 0x33000008;
        z.p[1] = f_038c40(d_1c0004);
    }
    int snd;
    f_147323_frame(MDC, 0x33000e, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
    f_0bf730(M64, id);
}

//@ f_02d7a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet oder betätigt das Objekt Pk(p2, p3); sind dabei bereits d_1bc864 == 1 und d_1bc868 == 1
 *   erfüllt, ertönt zusätzlich der Soundeffekt 0x33000f und es wird die Meldung 0x3300000b angezeigt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kontextzeiger p1 sowie die Parameter p2 und p3 und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Prüft die beiden Fortschrittsflags d_1bc864 und d_1bc868.
 === Ende Beschreibung === */
void f_02d7a0(int p1, short p2, short p3)
{
    Pk *pk = new (mark(d_1a06f0, 0xdbd)) Pk((short)p2, (short)p3);
    if (EQI(pk->f_05f580(), 0) == 1 && EQI(d_1bc864, 1) && EQI(d_1bc868, 1)) {
        int snd;
        f_147323(MDC, 0x33000f, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
        f_0bf730(M64, 0x3300000b);
    }
    pk->f_05f280(0);
    delete pk;
}

//@ f_02d860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Betätigt das Objekt Pk(0x12, 0x1f4f) und schaltet, sofern d_1bc858 == 0 und d_1bc85c == 0
 *   sind, über f_060740(0x6e, 1) das Kartenelement 0x6e um, wobei d_1bc85c = 1 gesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet die Statusflags d_1bc858 und d_1bc85c.
 === Ende Beschreibung === */
void f_02d860()
{
    Pk *pk = new (mark(d_1a06f0, 0xde6)) Pk(0x12, 0x1f4f);
    pk->f_05f280(0);
    if (EQI(d_1bc858, 0)) {
        if (EQI(pk->f_05f580(), 0) && EQI(d_1bc85c, 0)) {
            f_060740(0x6e, 1);
            d_1bc85c = 1;
        }
    }
    delete pk;
}

//@ f_02d900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Betätigt das Objekt Pk(0, 0x1f57); ist es aktiv und die Begegnung 0x0e verfügbar (f_069770),
 *   wird beim ersten Mal (d_1bc87c == 0) die Meldung 0x33000030 ausgegeben und anschließend die virtuelle Aktion
 *   0x0e gestartet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Prüft und setzt das Einmal-Flag d_1bc87c.
 === Ende Beschreibung === */
void f_02d900(int p1)
{
    Pk *pk = new (mark(d_1a06f0, 0xe0a)) Pk(0, 0x1f57);
    pk->f_05f280(0);
    if (pk->f_05f580() != 0) {
        if (f_069770(p1 + 2, 0xe) != 0) {
            if (EQB(d_1bc87c, 0)) {
                d_1bc87c = 1;
                f_0bf730(M64, 0x33000030);
            }
            short sVar1 = ((OS *)p1)->v->fn(p1, 0xe, 0);
            if (sVar1 != 0) pk->f_05f5a0(1);
        }
    }
    delete pk;
}
