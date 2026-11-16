/* === Beschreibung (Katalog) ===
 * Einheit boron2_t2 (0x00023b80 - 0x00024890)
 *
 * Überblick
 *
 * Die Einheit boron2_t2 enthält den zweiten Teil der Dungeon-Logik für die Katakomben unter dem Boronanger
 * (BORON2.CPP). Sie behandelt weitere Gruftkammern, Fallen, Geheimtüren, Beuteverstecke sowie die zahlreichen
 * kurzen Ereignismeldungen und Statusabfragen des Gewölbes.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 24/25 gleich (suche.py 23.10.2026, Basis boron2_t2_P1.CPP)
// boron2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x023B80-0x024890
#include <string.h>
struct Msg { void f_0bf730(long code); int f_0bf6f0(long code); int f_0bfa20(...); };
extern Msg d_1c2c64;


extern char d_1c349c[], d_1c3870[], d_1c3498[], d_1c2c44[], d_1c2c00[], d_1c2edc[];
struct T1 { char b[12]; T1(int a); ~T1(); void f_046de0(); };
struct T5 { char b[12]; T5(int a, int c); ~T5(); void f_05f280(int a); };
struct T3 { char b[0x20]; T3(int a, int b, int c, int d, int e, int f); ~T3(); void f_138330(int a); };
struct Part { ~Part(); };
Part *f_0606a0(int a, int b);
int f_0dcf00(int p1, int p2, int p3);
int f_0db9a0(int p1);
int f_039320(int p1, int p2);
int f_038c40(int p1);
int f_038ba0(int p1);
int f_038cb0(int p1);
int f_044850(int p1, int p2, int p3);
int f_044300(int p1, int p2);

int f_044c90(int p1, int p2, int p3);
void f_060740(unsigned short a, int b);
void f_0607e0(int a, signed char b);
void f_0603b0(short n);
void f_060360(short n);
void f_060a70();
void f_054ca0(int a, int b);
void f_091f70(int a);
void f_0dcbb0(int a, int b);
void f_057220(void *p, int a, int b);
void f_125ed0(void *p, int v);
void f_147323(void *p, int a, int b, int c, int d, int e, int f);
extern const char d_1a05b4[];
extern unsigned short d_1a9820;
extern int d_1c0004;
extern signed char d_1bc788, d_1bc78c, d_1bc7b8, d_1bc7bc, d_1bc7c0, d_1bc7c4, d_1bc7c8, d_1bc7cc, d_1bc7d0, d_1bc7d4, d_1bc7d8, d_1bc7dc, d_1bc7e0, d_1bc7e4, d_1bc7e8, d_1bc7ec, d_1c0e88;
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
typedef short (*FNX)(int, int, int);
#define VC(p,a) ((**(FNX **)((p) + 8))((p), (a), 0))
//@ f_023b80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Untersuchung einer Grabkammer in den Katakomben, verlangt eine Talent- oder
 *   Eigenschaftsprobe des vorangehenden Helden und belohnt die Gruppe bei Erfolg mit einem Fund oder schaltet
 *   einen Durchgang frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Katakomben-Textpuffer d_1bc814, der Gruppenanführer d_1c0004 und
 *   die Fortschrittsflags im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_023b80()
{
    if (EQ(d_1bc7b8, 0)) {
        if (d_1c2c64.f_0bf6f0(0x24000053) == 1) {
            short s = f_0dcf00(d_1c0004, 0x170, 1);
            if (0 < s) {
                d_1bc7b8 = 1;
                T3 *p = new (mark(d_1a05b4, 0x350)) T3(0, -1, -1, -1, -1, 1);
                p->f_138330(0x170);
                delete p;
                d_1c0e88 = 1;
                f_060a70();
            }
        }
    }
    if (EQB(d_1c0e88, 1) && EQ(d_1bc7bc, 0)) {
        if (d_1c2c64.f_0bf6f0(0x24000054) == 1) {
            f_125ed0(d_1c2c44, 0x1e);
            RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
            c.tables.p[1] = f_039320(d_1c0004, 0x20);
            d_1c2c64.f_0bf730(0x24000055);
            short s = f_0db9a0(d_1c0004);
            if (1 < s) {
                c.tables.p[2] = f_038c40(d_1c0004);
                while (c.tables.p[2] == c.tables.p[1]) c.tables.p[2] = f_038ba0(d_1c0004);
                d_1c2c64.f_0bf730(0x24000056);
            }
            d_1bc7bc = 1;
            f_0dcf00(d_1c0004, 0x171, 1);
        }
    }
}
//@ f_023d50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt die Heldengruppe einen verdächtigen Sarkophag oder Mechanismus in den Katakomben öffnen,
 *   wobei je nach Entscheidung und Probenausgang Schaden durch eine Falle droht, ein Kampf gegen Untote startet
 *   oder Beute geborgen wird.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814, der aktive Held d_1c0004, Schadens- beziehungsweise
 *   Kampffunktionen sowie das zugehörige Kammerflag.
 === Ende Beschreibung === */
void f_023d50()
{
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    int u;
    if (EQ(d_1bc7c4, 0)) {
        u = f_038c40(d_1c0004);
        d_1bc7c4 = 1;
        c.tables.p[1] = u;
        d_1c2c64.f_0bf730(0x24000057);
        f_044850(u, 3, 5);
        d_1c2c64.f_0bf730(0x24000058);
        f_044850(u, 5, 5);
        short s = f_0db9a0(d_1c0004);
        if (1 < s) {
            c.tables.p[2] = f_038cb0(d_1c0004);
            d_1c2c64.f_0bf730(0x24000059);
            f_044850(u, 7, 5);
        } else {
            d_1c2c64.f_0bf730(0x2400005a);
            f_044300(u, (short)(((int)(f_042960((struct hero *)(u)))) - 4));
        }
    }
    if (EQ(d_1bc7c0, 0) && (short)f_0db9a0(d_1c0004) > 1) {
        if (d_1c2c64.f_0bf6f0(0x2400005b) == 1) {
            u = f_039320(d_1c0004, 0x27);
            c.tables.p[1] = u;
            d_1c2c64.f_0bf730(0x2400005c);
            f_060740(0x1fa4, 1);
            f_060740(0x1fa5, 1);
            f_060740(0x1fa6, 1);
            f_060740(0x1fa7, 1);
            f_060740(0x1fa8, 1);
            f_0607e0(0x1f48, 1);
            d_1bc7c0 = 1;
        }
    } else if (EQ(d_1bc7c0, 1)) {
        c.tables.p[1] = f_038c40(d_1c0004);
        d_1c2c64.f_0bf730(0x2400005d);
        d_1bc7c0 = 2;
    }
}
//@ f_023f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt der Gruppe beim Betreten eines Abschnitts der Katakomben einen Hinweistext an und setzt
 *   den zugehörigen Einmal-Merker.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und ein Statusbyte im Block d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_023f70(int p1)
{
    if (EQB(d_1bc7c8, 0)) {
        d_1c2c64.f_0bf730(0x2400005e);
        short s = VC(p1, 0x52);
        if (s == 0) d_1bc7c8 = 1;
    }
}
//@ f_023fc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an einer Vorrichtung in den Katakomben, ob diese betätigt werden soll, und
 *   schaltet daraufhin eine Tür oder einen Geheimgang im Dungeon um.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert werden der Tür-/Wandstatus im 3D-Dungeon sowie ein Statusflag im Bereich
 *   d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_023fc0(int p1)
{
    if (EQ(d_1bc7d8, 0)) {
        if (d_1c2c64.f_0bf6f0(0x2400005f) == 1) {
            RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
            c.tables.p[1] = f_038ba0(d_1c0004);
            d_1c2c64.f_0bf730(0x24000060);
            d_1bc7d8 = 1;
        }
    }
    if (EQ(d_1bc7d8, 1)) {
        short s = VC(p1, 0x53);
        if (s == 0) d_1bc7d8 = 2;
    }
}
//@ f_024070
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine Entdeckungsmeldung in der Gruft aus und übergibt beim ersten Untersuchen einen
 *   Gegenstand an das Gruppeninventar.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814, die Gegenstandsübergabe f_051360 und ein Einmal-Flag.
 === Ende Beschreibung === */
void f_024070(int p1)
{
    if (EQB(d_1bc7dc, 0)) {
        d_1c2c64.f_0bf730(0x24000061);
        d_1bc7dc = 1;
    }
    if (EQB(d_1bc7dc, 1)) {
        short s = VC(p1, 0x54);
        if (s == 0) d_1bc7dc = 2;
    }
}
//@ f_0240e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt eine weitere Fundstelle in den Katakomben, zeigt den Beschreibungstext an und
 *   markiert die Stelle als untersucht.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Textpuffer d_1bc814 und die Dungeon-Flags ab d_1bc7b8.
 === Ende Beschreibung === */
void f_0240e0(int p1)
{
    if (EQB(d_1bc7d0, 0)) {
        d_1c2c64.f_0bf730(0x24000062);
        d_1bc7d0 = 1;
    }
    if (EQB(d_1bc7d0, 1)) {
        short s = VC(p1, 0x55);
        if (s == 0) d_1bc7d0 = 2;
    }
}
//@ f_024150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten eines Gruftabschnitts eine kurze Beobachtung im Dialogfenster aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Zugegriffen wird auf d_1bc814 und ein Einmal-Flag des Katakomben-Dungeons.
 === Ende Beschreibung === */
void f_024150(int p1)
{
    if (EQB(d_1bc7cc, 0)) {
        d_1c2c64.f_0bf730(0x24000063);
        short s = VC(p1, 0x56);
        if (s == 0) d_1bc7cc = 1;
    }
}
//@ f_0241a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt der Gruppe an einem Hindernis in den Katakomben eine Entscheidungsfrage und führt bei
 *   Bestätigung eine Probe oder Zustandsänderung durch.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden der Gruppenanführer d_1c0004, der Textpuffer d_1bc814 und die
 *   Statusmerker der Gruft.
 === Ende Beschreibung === */
void f_0241a0()
{
    if (EQ(d_1bc78c, 0)) {
        if (d_1c2c64.f_0bf6f0(0x24000064) == 1) {
            if (EQ(d_1bc788, 1)) {
                RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
                c.tables.p[1] = f_038c40(d_1c0004);
                Part *o = f_0606a0(0x2b0000, 8);
                d_1c2c64.f_0bf730(0x24000065);
                d_1c2c64.f_0bfa20(o, 0, 0x24000066, 0);
                f_0dcbb0(d_1c0004, 10);
                f_091f70(0xd);
                f_057220(d_1c2c00, 0x8030003, 0);
                d_1bc78c = 1;
                delete o;
            } else {
                d_1c2c64.f_0bf730(0x24000067);
            }
        }
    }
}
//@ f_0242c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt eine Entdeckung in den Katakomben an und aktualisiert den Fortschrittsmerker des
 *   entsprechenden Raums.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und ein Statusbyte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_0242c0(int p1)
{
    if (EQB(d_1bc7d4, 0)) {
        d_1c2c64.f_0bf730(0x24000068);
        d_1bc7d4 = 1;
    }
    if (EQB(d_1bc7d4, 1)) {
        short s = VC(p1, 0x57);
        if (s == 0) d_1bc7d4 = 2;
    }
}
//@ f_024330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt das Umlegen eines Schalters oder das Öffnen eines geheimen Durchgangs in den
 *   Katakomben und informiert den Spieler über das Geräusch der sich bewegenden Steinwand.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert werden die Kartendaten des Dungeons sowie ein Flag im Bereich
 *   d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_024330(int p1)
{
    if (EQB(d_1bc7e0, 0)) {
        RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
        c.tables.p[1] = f_038c40(d_1c0004);
        d_1c2c64.f_0bf730(0x24000069);
        d_1bc7e0 = 1;
    }
    if (EQ(d_1bc7e0, 1)) {
        short s = VC(p1, 0x58);
        if (s == 0) d_1bc7e0 = 2;
    }
}
//@ f_0243d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Betreten eines Ereignisfeldes einen kurzen Beschreibungstext aus d_1bc814 aus und
 *   vermerkt die Auslösung.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und ein Einmal-Merker der Katakomben.
 === Ende Beschreibung === */
void f_0243d0()
{
    T1 *p = new (mark(d_1a05b4, 0x52a)) T1(4);
    p->f_046de0();
    delete p;
}
//@ f_024420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt einen weiteren Hinweistext in den Katakomben an und sperrt das Feld gegen wiederholte
 *   Anzeige.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und ein Statusbyte im Katakomben-Block.
 === Ende Beschreibung === */
void f_024420()
{
    T1 *p = new (mark(d_1a05b4, 0x54b)) T1(5);
    p->f_046de0();
    delete p;
}
//@ f_024470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt an einer Stelle der Gruft eine einmalige Textmeldung aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und das zugehörige Einmal-Flag.
 === Ende Beschreibung === */
void f_024470()
{
    T1 *p = new (mark(d_1a05b4, 0x56b)) T1(6);
    p->f_046de0();
    delete p;
}
//@ f_0244c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen Wert eines Katakomben-Statusflags aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt den Flagwert zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_0244c0()
{
    f_0603b0(0x20);
}
//@ f_0244d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft am Ausgang der Katakomben, ob die Gruppe das Gewölbe verlassen möchte, und versetzt die
 *   Helden wieder an die Oberfläche des Boronangers zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden die Ortskennung und die Startposition der Heldengruppe auf dem
 *   Friedhof.
 === Ende Beschreibung === */
void f_0244d0()
{
    int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
    if (EQ(d_1bc7e4, 0)) {
        RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
        int p = f_039320(d_1c0004, 0x27);
        short sv = f_044c90(p, 0x33, 5);
        int ok = (0 < sv);
        c.tables.p[1] = f_038c40(d_1c0004);
        d_1c2c64.f_0bf730(0x2400006a);
        c.tables.p[2] = p;
        if (ok == 1) {
            d_1c2c64.f_0bf730(0x2400006b);
            f_0603b0(0x21);
            f_060a70();
        }
        int snd = *(int *)&d_1a9820;
        f_147323_frame((int)d_1c2edc, 0x240009, 0x7fff, 0x8000, snd, 0, 1);
        d_1c2c64.f_0bf730(0x2400006c);
        f_060740(0x1f4b, 1);
        d_1bc7e4 = 1;
        f_054ca0(5, 100);
    }
}
//@ f_0245f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den Zustand eines weiteren Fortschrittsflags der Katakomben.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt das Statusbyte als Ganzzahl zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_0245f0()
{
    f_060360(7);
}
//@ f_024600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt ein Fortschrittsflag in den Katakomben und führt eine kurze Folgeaktualisierung aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Beschrieben wird ein Statusbyte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_024600()
{
    if (EQ(d_1bc7e8, 0)) {
        d_1c2c64.f_0bf730(0x2400006d);
        d_1bc7e8 = 1;
    }
}
//@ f_024630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst an einem Ereignispunkt der Gruft eine kurze Aktion oder Textanzeige aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und die Ortsflags der Katakomben.
 === Ende Beschreibung === */
void f_024630()
{
    if (EQ(d_1bc7ec, 0)) {
        d_1c2c64.f_0bf730(0x2400006e);
        d_1bc7ec = 1;
    }
}
//@ f_024660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim erstmaligen Betreten eines Gruftfeldes den zugehörigen Beschreibungstext an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und ein Einmal-Flag im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_024660()
{
    T5 *p = new (mark(d_1a05b4, 0x610)) T5(4, 0x1f41);
    p->f_05f280(0);
    delete p;
}
//@ f_0246b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine weitere einmalige Textmeldung in den Katakomben aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und das zugehörige Einmal-Flag.
 === Ende Beschreibung === */
void f_0246b0()
{
    T5 *p = new (mark(d_1a05b4, 0x62e)) T5(3, 0x1f42);
    p->f_05f280(0);
    delete p;
}
//@ f_024700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Präsentiert beim Betreten eines weiteren Gruftabschnitts einen Beschreibungstext und setzt das
 *   Besuchsflag.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und ein Statusbyte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_024700()
{
    T5 *p = new (mark(d_1a05b4, 0x64c)) T5(2, 0x1f43);
    p->f_05f280(0);
    delete p;
}
//@ f_024750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt eine einmalige Textmeldung an einem Ereignispunkt der Katakomben an.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und das entsprechende Ortsflag.
 === Ende Beschreibung === */
void f_024750()
{
    T5 *p = new (mark(d_1a05b4, 0x66a)) T5(1, 0x1f44);
    p->f_05f280(0);
    delete p;
}
//@ f_0247a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten eines weiteren Feldes in den Katakomben einen Hinweistext aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und ein Einmal-Merker der Gruft.
 === Ende Beschreibung === */
void f_0247a0()
{
    T5 *p = new (mark(d_1a05b4, 0x688)) T5(7, 0x1f45);
    p->f_05f280(0);
    delete p;
}
//@ f_0247f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt an einem weiteren Punkt der Katakomben eine Beschreibung im Dialogfenster an und
 *   speichert den Besuch.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und ein Statusbyte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_0247f0()
{
    T5 *p = new (mark(d_1a05b4, 0x6a6)) T5(5, 0x1f46);
    p->f_05f280(0);
    delete p;
}
//@ f_024840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die letzte der gestaffelten Raum- und Gangmeldungen in den Katakomben aus und setzt das
 *   zugehörige Einmal-Flag.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden d_1bc814 und das letzte Statusbyte des Katakomben-Blocks vor d_1bc814.
 === Ende Beschreibung === */
void f_024840()
{
    T5 *p = new (mark(d_1a05b4, 0x6c4)) T5(6, 0x1f47);
    p->f_05f280(0);
    delete p;
}
