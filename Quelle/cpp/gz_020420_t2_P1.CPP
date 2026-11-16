/* === Beschreibung (Katalog) ===
 * Einheit gz_020420_t2 (0x000216b0 - 0x000222d0)
 *
 * Überblick
 *
 * Die Einheit gz_020420_t2 setzt die Ereignislogik des Boronangers fort. Sie umfasst weitere Grab- und
 * Gruftuntersuchungen, magische Analysen mit *Odem Arcanum* und *Analüs Arcanstruktur* sowie das Registrieren
 * der speicherbaren Friedhofs-Variablen im Spielstandsystem.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 4/6 gleich (suche.py 26.10.2026, Basis gz_020420_t2_P1.CPP)
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 1 gleich (vorher 1), Rest 254 (vorher 259)
// gz_020420.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x020420-0x022030
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_022030(int p1);                                   // reg eax stapel 0
int f_0222d0(int p1);                                   // reg eax stapel 0
int f_0224b0();                                         // reg - stapel 0
short f_0227d0();                                         // reg - stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039830(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
short f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_0600f0(int p1, int p2);                           // reg edx stapel 0
int f_060100(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060230();                                         // reg - stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf820();                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
int f_11c320(int p1);                                   // reg eax stapel 0
int f_11c620(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1); int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_1483f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_148450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1a9820;                    // 0x1A9820
extern int d_1bab08;                    // 0x1BAB08
extern signed char d_1bc76c;                    // 0x1BC76C
extern int d_1bc76d;                    // 0x1BC76D
extern int d_1bc770;                    // 0x1BC770
extern int d_1bc771;                    // 0x1BC771
extern signed char d_1bc774;                    // 0x1BC774
extern int d_1bc775;                    // 0x1BC775
extern signed char d_1bc778;                    // 0x1BC778
extern int d_1bc779;                    // 0x1BC779
extern signed char d_1bc77c;                    // 0x1BC77C
extern int d_1bc77d;                    // 0x1BC77D
extern int d_1bc780;                    // 0x1BC780
extern int d_1bc781;                    // 0x1BC781
extern signed char d_1bc784;                    // 0x1BC784
extern int d_1bc785;                    // 0x1BC785
extern int d_1bc788;                    // 0x1BC788
extern int d_1bc789;                    // 0x1BC789
extern int d_1bc78c;                    // 0x1BC78C
extern int d_1bc78d;                    // 0x1BC78D
extern int d_1bc790;                    // 0x1BC790
extern int d_1bc791;                    // 0x1BC791
extern int d_1bc794;                    // 0x1BC794
extern int d_1bc795;                    // 0x1BC795
extern int d_1bc798;                    // 0x1BC798
extern int d_1bc799;                    // 0x1BC799
extern int d_1bc79c;                    // 0x1BC79C
extern int d_1bc79d;                    // 0x1BC79D
extern int d_1bc7a0;                    // 0x1BC7A0
extern int d_1bc7a1;                    // 0x1BC7A1
extern int d_1bc7a4;                    // 0x1BC7A4
extern int d_1bc7a5;                    // 0x1BC7A5
extern int d_1bc7a8;                    // 0x1BC7A8
extern int d_1bc7a9;                    // 0x1BC7A9
extern int d_1bc7ac;                    // 0x1BC7AC
extern int d_1bc7ad;                    // 0x1BC7AD
extern int d_1bc7b0;                    // 0x1BC7B0
extern int d_1bc7b1;                    // 0x1BC7B1
extern int d_1bc7b4;                    // 0x1BC7B4
extern int d_1bc7b5;                    // 0x1BC7B5
extern int d_1bc7b8;                    // 0x1BC7B8
extern int d_1bc7b9;                    // 0x1BC7B9
extern int d_1bc7bc;                    // 0x1BC7BC
extern int d_1bc7bd;                    // 0x1BC7BD
extern int d_1bc7c0;                    // 0x1BC7C0
extern int d_1bc7c1;                    // 0x1BC7C1
extern int d_1bc7c4;                    // 0x1BC7C4
extern int d_1bc7c5;                    // 0x1BC7C5
extern int d_1bc7c8;                    // 0x1BC7C8
extern int d_1bc7c9;                    // 0x1BC7C9
extern int d_1bc7cc;                    // 0x1BC7CC
extern int d_1bc7cd;                    // 0x1BC7CD
extern int d_1bc7d0;                    // 0x1BC7D0
extern int d_1bc7d1;                    // 0x1BC7D1
extern int d_1bc7d4;                    // 0x1BC7D4
extern int d_1bc7d5;                    // 0x1BC7D5
extern int d_1bc7d8;                    // 0x1BC7D8
extern int d_1bc7d9;                    // 0x1BC7D9
extern int d_1bc7dc;                    // 0x1BC7DC
extern int d_1bc7dd;                    // 0x1BC7DD
extern int d_1bc7e0;                    // 0x1BC7E0
extern int d_1bc7e1;                    // 0x1BC7E1
extern int d_1bc7e4;                    // 0x1BC7E4
extern int d_1bc7e5;                    // 0x1BC7E5
extern int d_1bc7e8;                    // 0x1BC7E8
extern int d_1bc7e9;                    // 0x1BC7E9
extern int d_1bc7ec;                    // 0x1BC7EC
extern int d_1bc7ed;                    // 0x1BC7ED
extern int d_1bc7f0;                    // 0x1BC7F0
extern int d_1bc7f1;                    // 0x1BC7F1
extern int d_1bc7f4;                    // 0x1BC7F4
extern int d_1bc7f5;                    // 0x1BC7F5
extern signed char d_1bc7f8;                    // 0x1BC7F8
extern int d_1bc7f9;                    // 0x1BC7F9
extern signed char d_1bc7fc;                    // 0x1BC7FC
extern int d_1bc7fd;                    // 0x1BC7FD
extern int d_1bc800;                    // 0x1BC800
extern int d_1bc801;                    // 0x1BC801
extern int d_1bc804;                    // 0x1BC804
extern int d_1bc808;                    // 0x1BC808
extern int d_1bc80c;                    // 0x1BC80C
extern int d_1bc810;                    // 0x1BC810
extern int d_1bd70c;                    // 0x1BD70C
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c213a;                    // 0x1C213A
extern int d_1c213c;                    // 0x1C213C
extern int d_1c21b4;                    // 0x1C21B4
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3068;                    // 0x1C3068
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0

#define EQ(x,v) (((x)==(v))?1:0)
static inline int NE(int x, int v) { return x != v; }
typedef RivaTextContextData Msg;
#define A(x) ((int)&(x))

//@ f_0216b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt die Gruppe ein weiteres Grabmal auf dem Boronanger untersuchen, stellt eine Auswahlfrage
 *   im Textfenster und übergibt beim Durchsuchen gefundene Gegenstände oder Hinweise an die Helden.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Friedhofs-Textpuffer d_1bc79c, der Gruppenanführer d_1c0004 sowie
 *   ein Einmal-Merker im Block d_1bc74c-d_1bc798, damit das Grab nicht mehrfach geplündert werden kann.
 === Ende Beschreibung === */
void f_0216b0()
{
    if (EQ(d_1bc76c, 1) && EQ(d_1bc77c, 0)) {
        Msg m;
        if (EQ(d_1bc774, 0)) {
            f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
            f_125ed0(A(d_1c2c44), 0xf);
            d_1bc774 = 1;
            m.tables.p[1] = f_039320(d_1c0004, 0x33);
            f_0bf730(A(d_1c2c64), 0x24000009);
            f_1254a0((int)&m, 0);
        } else {
            f_125ed0(A(d_1c2c44), 5);
            f_0bf730(A(d_1c2c64), 0x2400000a);
        }
    } else {
        Msg m;
        int a, b, p;
        if (EQ(d_1bc7f8, 0) == 0) return;
        d_1bc7f8 = 1;
        int candidate = f_0dd3a0(d_1c0004, 6, 0);
        int compare_a;
        if (!candidate) candidate = f_039320(d_1c0004, 0x25);
        compare_a = a = candidate;
        b = 0;
        p = f_038c80(d_1c0004);
        do {
            if (f_0d4a60(p) == 1 && f_042350((struct hero *)(p)) != 6 && p != compare_a) b = p;
            if (b == 0) p = f_0391b0(d_1c0004, p);
        } while (b == 0 && p != f_038c80(d_1c0004));
        f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
        m.tables.p[1] = a;
        m.tables.p[2] = b;
        f_0bf730(A(d_1c2c64), 0x2400000b);
        if (b != 0) f_0bf730(A(d_1c2c64), 0x2400000c);
        f_1254a0((int)&m, 0);
    }
}

//@ f_021870
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Untersuchung eines weiteren Ortes auf dem Friedhof, führt eine Sinnesschärfe-
 *   oder Talentprobe durch und gibt je nach Ausgang den passenden Entdeckungstext aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft werden der aktive Held d_1c0004 über die Talentprobe f_03d220 und der Textpuffer
 *   d_1bc79c.
 === Ende Beschreibung === */
void f_021870()
{
    Msg m2, m1;
    if (EQ(d_1bc778, 1) || (EQ(d_1bc7fc, 1) && EQ(d_1bc76c, 0))) {
        f_125ed0(A(d_1c2c44), 10);
        f_0bf730(A(d_1c2c64), 0x2400000d);
    } else {
        if (EQ(d_1bc7fc, 0)) {
            f_125ed0(A(d_1c2c44), 10);
            d_1bc7fc = 1;
            if (f_0db9a0(d_1c0004) > 1) {
                int a, b;
                f_125400((int)&m1, A(d_1c349c), A(d_1c3870), A(d_1c3498));
                a = f_039320(d_1c0004, 0x1d);
                b = f_039b00(d_1c0004, a, 0x33);
                m1.tables.p[1] = a;
                m1.tables.p[2] = b;
                f_0bf730(A(d_1c2c64), 0x2400000e);
                f_1254a0((int)&m1, 0);
            }
            f_0bf730(A(d_1c2c64), 0x2400000f);
        }
        if (EQ(d_1bc76c, 1) && EQ(d_1bc77c, 0) && EQ(d_1bc778, 0)) {
            f_125400((int)&m2, A(d_1c349c), A(d_1c3870), A(d_1c3498));
            f_125ed0(A(d_1c2c44), 0x1e);
            d_1bc778 = 1;
            m2.tables.p[3] = f_039320(d_1c0004, 0x33);
            f_0bf730(A(d_1c2c64), 0x24000010);
            f_1254a0((int)&m2, 0);
        }
    }
}

//@ f_021a30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst den Ortswechsel von der Oberfläche des Boronangers hinab in das Dungeon unter dem
 *   Friedhof (BORON2) aus und setzt die Startkoordinaten sowie die Blickrichtung der Gruppe im Gewölbe.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden die globalen Orts- und Dungeon-Koordinaten der Heldengruppe.
 === Ende Beschreibung === */
int f_021a30(int p1)
{
    f_040370(A(d_1c21b4), p1);
    return f_133fe0(A(d_1c3498), A(d_1c21b4));
}

int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]

//@ f_021a70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beschreibt ein unheimliches Grab auf dem Boronanger und lässt die Spieler entscheiden, ob sie
 *   es öffnen oder näher untersuchen wollen, was je nach Zustand zu einer Entdeckung oder einer Gefahr führt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden die Friedhofs-Flags im Bereich d_1bc74c-d_1bc798 und die Dialogtexte
 *   aus d_1bc79c.
 === Ende Beschreibung === */
void f_021a70()
{
    short aux_0bf820(int p1, int, int, int, int, int, int);
#pragma aux aux_0bf820 "f_0bf820" parm caller [ecx] value [eax] modify exact [eax edx esp]
    struct M901 : Msg {
        void begin() { f_125400((int)this,A(d_1c349c),A(d_1c3870),A(d_1c3498)); }
        void end() { f_1254a0((int)this,0); }
        void number(int x) { tables.p[1]=x; }
        void string(int x) { tables.tail.numbers[1]=x; }
    } m;
    struct Wallet901 {
        static int get() {return d_1bc804;}
        static void set(int v) {d_1bc804=v;}
        static void pay(int v) {f_0db8b0(d_1c0004,v);}
        static int format(int v) {return f_021a30(v);}
    };
    short n;
    m.begin();
    int r = 0, neu, p2; short gain;
    p2 = Wallet901::get();
    neu=p2; n = ((short (*)(int,...))f_0bf820)( A(d_1c2c64), 0x24000011, 3, 0x24000012, 0x24000013, 0x24000014);
    switch ((unsigned short)(n + 1)) {
    case 2:
        gain = f_0227d0();
        if (gain > 0) {
            { int snd = *(int*)&d_1a9820;
              f_147323_frame(A(d_1c2edc), 0x240001, 0x7fff, 0x8000, snd, r, 1); }
            f_0bf730(A(d_1c2c64), 0x24000017);
            Wallet901::pay(gain*10);
            neu += gain * 10; r = gain;
        } else {
            r = -3;
        }
        break;
    case 3:
        r = -0x32;
        if (p2 > 0) {
            { int snd = *(int*)&d_1a9820;
              f_147323_frame(A(d_1c2edc), 0x240002, 0x7fff, 0x8000, snd, 0, 1); }
            m.number(f_039660(d_1c0004, 7));
            m.string(Wallet901::format(p2));
            f_0bf730(A(d_1c2c64), 0x24000018);
            r = -0x32 - p2 / 10;
            f_0db820(d_1c0004, p2);
            neu = 0;
        } else {
            f_0bf730(A(d_1c2c64), 0x24000019);
        }
        break;
    case 0:
    case 4:
        r = -2;
        break;
    default:
        break;
    }
    Wallet901::set(neu);
    f_054ca0(5, r);
    m.end();
}

//@ f_021c30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert ein weiteres Interaktionsfeld auf dem Boronanger, gibt nach einer Spielerentscheidung
 *   zusätzliche Hintergrundinformationen aus und vermerkt die Entdeckung im Spielstand.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc79c für die Texte sowie die Fortschrittsflags des Boronangers.
 === Ende Beschreibung === */
void f_021c30()
{
    Msg m;
    int p2, r, mode, old;
    short s;
    short count;
    r = 0;
    p2 = 0;
    mode = 3;
    old = d_1bc80c;
    r = old;
    if (old == 0) {
        s = ((short (*)(int, ...))f_0bf820)(A(d_1c2c64), 0x2400001a, 2, 0x2400001b, 0x2400001d);
        switch (s) {
        case 1: mode = 0; break;
        case 2: mode = 2; break;
        case -1: mode = 2; break;
        }
    } else {
        s = ((short (*)(int, ...))f_0bf820)(A(d_1c2c64), 0x2400001a, 3, 0x2400001b, 0x2400001c, 0x2400001d);
        switch (s) {
        case -1: mode = 2; break;
        case 0: break;
        case 1: mode = 0; break;
        case 2: mode = 1; break;
        case 3: mode = 2; break;
        }
    }
    switch (mode) {
    case 0:
        count = f_0227d0();
        if (count > 0) {
            int snd = *(int*)&d_1a9820;
            f_147323_frame(A(d_1c2edc), 0x240001, 0x7fff, 0x8000, snd, 0, 1);
            f_0db8b0(d_1c0004, count * 10);
            r += count * 10;
            p2 = count;
        } else {
            p2 = -1;
        }
        break;
    case 1:
        f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));
        { int snd = *(int*)&d_1a9820;
        f_147323_frame(A(d_1c2edc), 0x240002, 0x7fff, 0x8000, snd, 0, 1); }
        m.tables.tail.numbers[1] = f_021a30(r);
        f_0bf730(A(d_1c2c64), 0x2400001e);
        p2 = (r / 10 + 0x32) * -1;
        f_0db820(d_1c0004, r);
        r = 0;
        f_1254a0((int)&m, 0);
        break;
    case 2:
        p2 = -1;
        break;
    }
    d_1bc80c = r;
    f_054ca0(5, p2);
}

//@ f_021e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermöglicht einem magiekundigen Helden auf dem Boronanger, einen verdächtigen Ort mittels *Odem
 *   Arcanum* (0x28) oder *Analüs Arcanstruktur* (0x27) auf arkane Spuren zu untersuchen, zieht nach der
 *   Zauberprobe die Astralpunkte über f_044230 ab und enthält am Ende der Einheit die Registrierung der
 *   speicherbaren Friedhofs-Flags im globalen Spielstand-Array.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft werden die Zauberfähigkeit über f_039830, die Zauberprobe über f_03d3d0(held,
 *   zauber, 0) und der Astralpunktabzug über f_044230; die persistenten Ortsflags ab d_1bc74c werden in die
 *   globale Speichertabelle d_1c212a eingetragen.
 === Ende Beschreibung === */
void f_021e10()
{
    Msg m;
    int a, b, c;

    a = f_0397d0(d_1c0004, 0x23);
    b = f_0397d0(d_1c0004, 0x1a);
    c = f_039830(d_1c0004, 0x1c);
    f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498));

    if (f_0bf6f0(A(d_1c2c64), 0x2400001f) == 1) {
        if (a == 0 && b == 0 && c == 0) {
            f_0bf730(A(d_1c2c64), 0x24000020);
        } else {
            if (a != 0) {
                f_125ed0(A(d_1c2c44), 0x14);
                m.tables.p[1] = a;
                f_0bf730(A(d_1c2c64), 0x24000021);
            }
            if (b != 0) {
                m.tables.p[1] = b;
                int snd = *(int *)&d_1a9820;
                f_147323_frame(A(d_1c2edc), 0x240007, 0x7fff, 0x8000, snd, 0, 1);
                f_0bf730(A(d_1c2c64), 0x24000022);
            }
            if (c != 0) {
                f_125ed0(A(d_1c2c44), 0xf);
                m.tables.p[1] = c;
                f_0bf730(A(d_1c2c64), 0x24000023);
                f_044230(c, 5);
                f_0bf730(A(d_1c2c64), 0x24000024);
                f_0bbf00(A(d_1bf230));
            }
        }
    }

    if (EQ(d_1bc784, 0)) {
        a = f_039320(d_1c0004, 0x33);
        if (f_044c90(a, 0x33, 10) > 0) {
            d_1bc784 = 1;
            f_125ed0(A(d_1c2c44), 10);
            m.tables.p[1] = a;
            f_0bf730(A(d_1c2c64), 0x24000025);
            if (f_0db9a0(d_1c0004) > 1) {
                a = f_039320(d_1c0004, 0x27);
                if (f_044c90(a, 0x27, 0xc) > 0) {
                    m.tables.p[1] = a;
                    f_0bf730(A(d_1c2c64), 0x24000026);
                }
            }
        }
    }
    f_1254a0((int)&m, 0);
}
