/* === Beschreibung (Katalog) ===
 * Einheit star1_t2 (0x116f90 - 0x1182a0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von star1.cpp und implementiert weitere Raumereignisse, Fallen, Kämpfe
 * gegen Wächter-Insekten, Beutefunde und Säure-/Sekret-Hindernisse auf der ersten Ebene des Bienenstocks.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 21/24 gleich (suche.py 25.10.2026, Basis star1_t2_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 4 gleich (vorher 4), Rest 741 (vorher 759)
// star1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x115D80-0x118A10
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a7c30;                    // 0x1A7C30
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0930;                    // 0x1C0930
extern int d_1c093c;                    // 0x1C093C
extern int d_1c0940;                    // 0x1C0940
extern int d_1c0944;                    // 0x1C0944
extern int d_1c0948;                    // 0x1C0948
extern int d_1c094c;                    // 0x1C094C
extern int d_1c0950;                    // 0x1C0950
extern int d_1c09ac;                    // 0x1C09AC
extern int d_1c09bc;                    // 0x1C09BC
extern int d_1c09c0;                    // 0x1C09C0
extern int d_1c09c4;                    // 0x1C09C4
extern int d_1c09c8;                    // 0x1C09C8
extern int d_1c219c;                    // 0x1C219C
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (39), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

typedef signed char FLG;
extern FLG d_1c0954;
extern FLG d_1c0958;
extern FLG d_1c095c;
extern FLG d_1c0960;
extern volatile FLG d_1c0964; // haelt die Registerfolge in f_117650 und f_117c60 wie im Original
extern FLG d_1c0968;
extern FLG d_1c096c;
extern FLG d_1c0970;
extern FLG d_1c0974;
extern FLG d_1c0978;
extern FLG d_1c097c;
extern FLG d_1c0980;
extern FLG d_1c0984;
extern FLG d_1c0988;
extern FLG d_1c098c;
extern FLG d_1c0990;
extern FLG d_1c0994;
extern FLG d_1c0998;
extern FLG d_1c099c;
extern FLG d_1c09a0;
extern FLG d_1c09a8;
extern FLG d_1c09b0;
extern FLG d_1c09b4;
extern FLG d_1c09b8;
extern FLG d_1c09e8;
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
extern const char d_1a7c0c[];
extern short d_1a7c2a[];
struct S13E { char b[0x13e]; };
#define CH ((int)&d_1c2c64)
#define DB ((int)&d_1c38b0)
#define DS1 ((int)&d_1c21b4)
#define VC(p, n) ((void (*)(int, int))**(int **)((p) + 8))((p), (n))
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039580(int p1, int p2, int p3);
int f_039660(int p1, int p2);
int f_0396f0(int p1, int p2);
int f_039ac0(int p1, int p2);
int f_039b70(int p1, int p2, int p3);




int f_043e20(int p1, int p2);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
int f_0453e0(int p1, int p2, int p3);
int f_0603b0(int p1);
int f_0606a0(int p1, int p2);
int f_060740(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_0697c0(int p1, int p2, int p3);
int f_0bde40(int p1);
int f_0bf680(int p1, int p2);
int f_0bf6c0(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820();
int f_0bf980(int, ...);
short f_0bfa20();
int f_0d4a60(int p1);
short f_0d4aa0(int p1, int p2);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0db820(int p1, int p2);
short f_0db9a0(int p1);
int f_0e9300(int p1, int p2, int p3);
int f_0e93f0(int p1, int p2, int p3);

int f_1155d0(int p1, int p2);
int f_118460(int p1);
int f_118580(int p1);
int f_1186f0(int p1);
int f_133fe0(int p1, int p2);
short f_1457e0(int p1);

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_116f90
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Begegnung mit einer Gruppe von Wächter-Insekten (d_1c0940, d_1c0944) an den Durchgängen
 *   0x1f48/0x1f4b und ruft bei einem Angriff der Helden die Kampfroutine f_1150b0 auf.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_116f90(int p1)
{
    if (EQ(d_1c0954, 0)) {
        f_060800(0x2e000d, 0, 0);
        f_118460(p1);
        f_060800(0x2e000f, 0, 0);
        return;
    }
    if (EQ(d_1c0958, 1) && EQ(d_1c095c, 0)) {
        f_060800(0x2e000d, 0, 0);
        f_118580(p1);
        f_060800(0x2e000f, 0, 0);
        return;
    }
    if (EQ(d_1c09e8, 1) && EQ(d_1c0960, 0) && EQ(d_1c09b0, 0)) {
        f_060800(0x2e000d, 0, 0);
        f_1186f0(p1);
        f_060800(0x2e000f, 0, 0);
    }
}
//@ f_117080
/* === Beschreibung (Katalog) ===
 * - Zweck: Verarbeitet die Untersuchung der Larven-/Gefangenenkammer am Ereignis 0x1f5: Abhängig von den
 *   Fortschrittsflags d_1c0954, d_1c0958, d_1c095c, d_1c09e8, d_1c0960 und d_1c09b0 sowie den Begleitern a
 *   (f_1155d0) und b (f_039580) setzt die Funktion die passenden Dialogtexte (0x2e000066..0x2e000071) zusammen
 *   und ruft im Kampffall abschließend f_116f90(p1) auf.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: a, b (beteiligte Helden), d_1c0968, d_1c096c, d_1c0970 (Dialog-Fortschrittsflags).
 === Ende Beschreibung === */
void f_117080(int p1)
{
    struct Raw650 {int f0;char *p[13];short end;}; Raw650 ob; Raw650 *f_125400(Raw650 *,const char *,const char *,const char *); void f_1254a0(Raw650 *,int); f_125400(&ob,d_1c349c,d_1c3870,d_1c3498);
    int a = f_1155d0(p1, 1);
    int b = f_039580(d_1c0004, 1, 1);
    if (EQ(d_1c0954, 1) && EQ(d_1c0958, 0)) {
        f_0e93f0(DB, DS1, 0x2e000066);
        if (EQ(d_1c0968, 0))
            f_0e9300(DB, DS1, 0x2e000067);
        else if (EQ(d_1c09a8, 1))
            f_0e9300(DB, DS1, 0x2e000068);
        d_1c0968 = 1;
        if (a != 0 && b != 0) {
            *(int *)(ob.p[0] + 4) = a;
            *(int *)(ob.p[0] + 8) = b;
            f_0e9300(DB, DS1, 0x2e000069);
        }
        f_0bf730(CH, f_133fe0((int)d_1c3498, DS1));
        goto finish650;
    }
    if (EQ(d_1c095c, 1) && EQ(d_1c09e8, 0)) {
        f_0e93f0(DB, DS1, 0x2e000066);
        if (a != 0 && b != 0 && EQ(d_1c096c, 0)) {
            *(int *)(ob.p[0] + 4) = a;
            *(int *)(ob.p[0] + 8) = b;
            f_0bf730(CH, 0x2e00006a);
            f_0bf730(CH, 0x2e00006b);
            d_1c096c = 1;
            goto finish650;
        }
        f_0e93f0(DB, DS1, 0x2e000066);
        f_0e9300(DB, DS1, 0x2e00006c);
        f_0bf730(CH, f_133fe0((int)d_1c3498, DS1));
        goto finish650;
    }
    if (EQ(d_1c0960, 1) || (EQ(d_1c09e8, 1) && EQ(d_1c09b0, 1))) {
        f_0e93f0(DB, DS1, 0x2e000066);
        if (a != 0 && b != 0 && EQ(d_1c0970, 0)) {
            *(int *)(ob.p[0] + 4) = a;
            *(int *)(ob.p[0] + 8) = b;
            f_0e9300(DB, DS1, 0x2e00006d);
            if (f_0db9a0(d_1c0004) > 1)
                f_0e9300(DB, DS1, 0x2e00006e);
            else
                f_0e9300(DB, DS1, 0x2e00006f);
            d_1c0970 = 1;
        }
        f_0bf730(CH, f_133fe0((int)d_1c3498, DS1));
        goto finish650;
    }
    if (EQ(d_1c09e8, 1) && EQ(d_1c0960, 0) && EQ(d_1c09b0, 0) && a == 0) {
        f_0bf730(CH, 0x2e000070);
        goto finish650;
    }
    f_0bf730(CH, 0x2e000071);
    f_116f90(p1);
finish650:
    f_1254a0(&ob,0);
}
//@ f_117420
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raum- bzw. Hinweisbeschreibung 0x2e000072 über f_0bf730 aus (Ereignis 0x1f6).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_117420()
{
    f_0bf730(CH, 0x2e000072);
}
//@ f_117440
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raum- bzw. Hinweisbeschreibung 0x2e000073 über f_0bf730 aus (Ereignis 0x1f7).
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_117440()
{
    f_0bf730(CH, 0x2e000073);
}
//@ f_117460
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die sechs Waben-/Kammerfelder 0x3e8..0x3ed: Solange d_1c0954 == 0 ist, wird nach Meldung
 *   0x2e000074 das Bild 2 (0x2e0001) mit der Auswahlfrage 0x2e000075 eingeblendet, bei Option 2 der Text
 *   0x2e00007a angezeigt und d_1c0974 = 1 gesetzt, anschließend die Aktion f_060800(p2, 0, 0) ausgeführt und
 *   f_116f90(p1) aufgerufen.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt), p2 (aus dem Ereigniscode berechnete Aktionskennung).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: r (Spielerauswahl im Dialog 0x2e000075), d_1c0974 (Statusflag).
 === Ende Beschreibung === */
void f_117460(int p1, int p2)
{
    if (EQ(d_1c0954, 0)) {
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        int t = f_039660(d_1c0004, 0);
        *(int *)(ob.slots[0] + 4) = t;
        f_0bf730(CH, 0x2e000074);
        int o = f_0606a0(0x2e0001, 2);
        f_0bde40(CH);
        short r = ((short (__cdecl *)(int, int, int, int, int, int, int))f_0bfa20)(CH, o, 0, 0x2e000075, 2, 0x2e000076, 0x2e000077);
        if (o != 0) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
        if (r == 2) {
            f_0bf6c0(CH, 5);
            f_0bf730(CH, 0x2e00007a);
            ((int (*)(int))f_0bf680)(CH);
            d_1c0974 = 1;
        }
        f_0bf730(CH, 0x2e000078);
        f_060800(p2, 0, 0);
        f_0bf730(CH, 0x2e000079);
        f_116f90(p1);
    }
}
//@ f_117590
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Ereignis 0x1f9 die Meldung 0x2e00007b aus, sofern d_1c09e8 == 1 und d_1c0960 == 0 gilt und
 *   über f_1155d0(p1, 1) ein passender Begleiter a gefunden wurde.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: a (gefundener Held).
 === Ende Beschreibung === */
void f_117590(int p1)
{
    int a = f_1155d0(p1, 1);
    if (EQ(d_1c09e8, 1) && EQ(d_1c0960, 0) && a != 0) {
        f_0bf730(CH, 0x2e00007b);
    }
}
//@ f_1175e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten von Ereignis 0x259 (d_1c0978 == 0) die Meldung 0x2e00007c aus und setzt
 *   d_1c0978 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0978 (Besuchsflag).
 === Ende Beschreibung === */
void f_1175e0()
{
    if (EQ(d_1c0978, 0)) {
        f_0bf730(CH, 0x2e00007c);
        d_1c0978 = 1;
    }
}
//@ f_117610
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Ereignis 0x25a anhand des Zählers d_1c09b8 beim ersten Mal (0) die Meldung 0x2e00007d und
 *   beim zweiten Mal (1) die Meldung 0x2e00007c aus und erhöht d_1c09b8 jeweils um 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09b8 (Zustandszähler 0..2).
 === Ende Beschreibung === */
void f_117610()
{
    switch (d_1c09b8) {
    case 0:
        f_0bf730(CH, 0x2e00007d);
        ++d_1c09b8;
        return;
    case 1:
        f_0bf730(CH, 0x2e00007c);
        ++d_1c09b8;
        return;
    }
}
//@ f_117650
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines besonderen Raumes (d_1c09cc) einen mehrteiligen Dialog zwischen bis
 *   zu drei verschiedenen Helden (0x2e00007f oder 0x2e000080) aus und löst ein akustisches bzw. visuelles
 *   Ereignis (0x11) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 * - Bekannte Originalfehler: Bei der Prüfung, ob drei gültige und voneinander verschiedene Helden a, b und c für
 *   den Dialogtext 0x2e00007f gefunden wurden, steht im Originalcode die doppelt identische Abfrage if (a != 0
 *   && a != 0 && b != 0 && b != c) (0x1176da-0x1176e6: zwei unmittelbare je 0x117705 nacheinander nach test ecx,
 *   ecx). Offenbar sollte anstelle des zweiten a != 0 geprüft werden, dass a != c oder a != b gilt, damit
 *   derselbe Held nicht doppelt im selben Dialog auftritt.
 === Ende Beschreibung === */
void f_117650(int p1)
{
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
    if (EQ(d_1c0964, 0)) {
        int a = f_1155d0(p1, 1);
        int b = f_039580(d_1c0004, 0, 1);
        int c = f_039b70(d_1c0004, a, 0xc);
        d_1c0964 = 1;
        *(int *)(ob.slots[0] + 4) = c;
        f_0bf730(CH, 0x2e00007e);
        if (a != 0 && a != 0 && b != 0 && b != c) { // doppelte Pruefung wie im Originalcode
            *(int *)(ob.slots[0] + 8) = a;
            *(int *)(ob.slots[0] + 0xc) = b;
            f_0bf730(CH, 0x2e00007f);
        }
        int o = f_0606a0(0x2e0001, 8);
        ((short (*)(int, ...))f_0bfa20)(CH, o, 0, 0x2e000080, 0);
        ((short (*)(int, ...))f_0bfa20)(CH, o, 0, 0x2e000081, 0);
        if (o != 0) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
        short s = f_1457e0(6);
        f_044300(c, (short)(s + 4));
    } else {
        f_0bf730(CH, 0x2e000082);
    }
}
//@ f_1177b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Ereignis 0x2bd die Raummeldung 0x2e000083 über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_1177b0()
{
    f_0bf730(CH, 0x2e000083);
}
//@ f_1177d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den einmaligen Geldfund am Ereignis 0x2be (d_1c0980 == 0): Ein Held (f_039660(..., 10))
 *   entdeckt den Fund, Bild 9 aus 0x2e0001 wird mit Text 0x2e000084 angezeigt und der Gruppe werden 300 Heller
 *   (f_0db820(..., 300)) gutgeschrieben.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0980 (Einmal-Flag), o (Bildobjekt).
 === Ende Beschreibung === */
void f_1177d0()
{
    if (EQ(d_1c0980, 0)) {
        d_1c0980 = 1;
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        int t = f_039660(d_1c0004, 10);
        *(int *)(ob.slots[0] + 4) = t;
        int o = f_0606a0(0x2e0001, 9);
        f_0bde40(CH);
        ((short (*)(int, ...))f_0bfa20)(CH, o, 0, 0x2e000084, 0);
        if (o != 0) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
        f_0db820(d_1c0004, 300);
    }
}
//@ f_117890
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Auslösen von Ereignis 0x2bf (d_1c09b4 == 0) mit drei ausgewählten Helden die Meldung
 *   0x2e000085 aus und löst anschließend die Kartenaktion f_0603b0(0x69) aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09b4 (Einmal-Flag).
 === Ende Beschreibung === */
void f_117890()
{
    if (EQ(d_1c09b4, 0)) {
        d_1c09b4 = 1;
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        int t = f_038c40(d_1c0004);
        *(int *)(ob.slots[0] + 4) = t;
        t = f_039660(d_1c0004, 1);
        *(int *)(ob.slots[0] + 8) = t;
        t = f_039320(d_1c0004, 0x33);
        *(int *)(ob.slots[0] + 0xc) = t;
        f_0bf730(CH, 0x2e000085);
    }
    f_0603b0(0x69);
}
//@ f_117930
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Gift-/Säurefalle am Ereignis 0x2c0 (d_1c0984): Beim ersten Betreten (d_1c0984 == 0)
 *   erleidet der über f_039660(..., 10) ermittelte Held p 1W6+2 bzw. 1W8+2 Schadenspunkte (f_044300) sowie zwei
 *   langanhaltende Eigenschaftsabzüge auf Eigenschaft 4 (-3 für 0x1fa40 Ticks und -2 für 0x3f480 Ticks über
 *   f_0d5040) und den Statuseffekt f_0453e0(p, 0x0c, -1); bei späteren Besuchen erscheint 0x2e00008b.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0984 (Auslöseflag), p (getroffener Held), a (Gruppenanführer), v (Würfelseiten 6
 *   oder 8).
 === Ende Beschreibung === */
void f_117930()
{
    char c;
    short s;
    int a;
    int p;
    int v;
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
    if (EQ(d_1c0984, 0)) {
        d_1c0984 = 1;
        f_0bf730(CH, 0x2e000086);
        a = f_038c40(d_1c0004);
        p = f_039660(d_1c0004, 10);
        *(int *)(ob.slots[0] + 4) = p;
        s = f_0db9a0(d_1c0004);
        if (!(s < 2 || a == p)) {
            *(int *)(ob.slots[0] + 8) = a;
            f_0bf730(CH, 0x2e000087);
            f_0bf730(CH, 0x2e000088);
            v = 6;
        } else {
            f_0bf730(CH, 0x2e000089);
            v = 8;
        }
        s = f_1457e0(v);
        f_044300(p, (short)(s + 2));
        c = ((char)(f_042470((struct hero *)(p))));
        if (!c) {
            f_043e20(p, 1);
            f_0d5040(p, f_0d4c80(p), 0x1fa40, 4, -3, 0);
            f_0d5040(p, f_0d4c80(p), 0x3f480, 4, -2, 0);
            f_043e20(p, 0);
            a = f_0d4a60(p);
            if (a != 0) {
                f_0bf730(CH, 0x2e00008a);
            }
            f_0453e0(p, 0xc, -1);
            return;
        }
    } else {
        f_0bf730(CH, 0x2e00008b);
    }
}
//@ f_117ad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prädikatsfunktion für f_039ac0, die prüft, ob der Held p1 anwesend (f_0d4a60(p1) != 0) und weiblich
 *   (f_042380(p1) == 1) ist.
 * - Eingaben: p1 (Zeiger auf den Helden).
 * - Rückgabewert: 1 bei einem anwesenden weiblichen Gruppenmitglied, sonst 0.
 === Ende Beschreibung === */
int f_117ad0(int p1)
{
    int r = 0;
    if (f_0d4a60(p1) != 0) {
        if (f_042380((struct hero *)(p1)) == 1) r = 1;
    }
    return r;
}
//@ f_117b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten von Ereignis 0x2c1 (d_1c0988 == 0) für einen über f_039ac0(..., f_117ad0)
 *   (ersatzweise f_0396f0(..., 6)) ausgewählten Helden die Meldung 0x2e00008c aus und setzt d_1c0988 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0988 (Einmal-Flag), a (ausgewählter Held).
 === Ende Beschreibung === */
void f_117b00()
{
    if (EQ(d_1c0988, 0)) {
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        int a = f_039ac0(d_1c0004, (int)f_117ad0);
        if (a == 0) {
            a = f_0396f0(d_1c0004, 6);
        }
        *(int *)(ob.slots[0] + 4) = a;
        f_0bf730(CH, 0x2e00008c);
        d_1c0988 = 1;
    }
}
//@ f_117b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Blendet beim ersten Betreten von Ereignis 0x2c2 (d_1c098c == 0) das Bild 10 aus 0x2e0001 mit der
 *   Meldung 0x2e00008d ein und setzt d_1c098c = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c098c (Einmal-Flag), o (Bildobjekt).
 === Ende Beschreibung === */
void f_117b90()
{
    if (EQ(d_1c098c, 0)) {
        int o = f_0606a0(0x2e0001, 10);
        f_0bf6c0(CH, 5);
        f_0bde40(CH);
        ((short (*)(int, ...))f_0bfa20)(CH, o, 0, 0x2e00008d, 0);
        ((int (*)(int))f_0bf680)(CH);
        if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
        d_1c098c = 1;
    }
}
//@ f_117c10
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten von Ereignis 0x2c3 (d_1c0990 == 0) die Meldung 0x2e00008e aus und setzt
 *   d_1c0990 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0990 (Einmal-Flag).
 === Ende Beschreibung === */
void f_117c10()
{
    if (EQ(d_1c0990, 0)) {
        d_1c0990 = 1;
        f_0bf730(CH, 0x2e00008e);
    }
}
#pragma inline_depth(0)
//@ f_117c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert das Aufbrechen der verklebten Wabenwand am Durchgang 0x1f42 (d_1c097c): Ist der Durchgang
 *   noch verschlossen (d_1c097c == 0), bietet das Auswahlmenü f_0bf820 drei Optionen (0x2e000092..0x2e000094);
 *   bei den aktiven Optionen 2 (mit Körperkraftprobe f_044900(p, 5, 5) und 1W6+2 Ausdauer-/Schadensabzug bei
 *   Misslingen) und 3 wird d_1c097c = 1 gesetzt, 20 Heller/Einheiten (f_0db820) vergeben und der Durchgang
 *   0x1f42/0x1f44 über f_060740 geöffnet.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c097c (Öffnungsflag), p (handelnder Anführer), s (Spielerauswahl).
 === Ende Beschreibung === */
void f_117c60()
{
    int p;
    short s;
    signed char c;
    int t;
    if (EQB(d_1c097c, 0)) {
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        p = f_038c40(d_1c0004);
        f_0e93f0(DB, DS1, 0x2e00008f);
        if (EQ(d_1c0964, 1) && f_0db9a0(d_1c0004) > 1) {
            t = f_039660(d_1c0004, 12);
            *(int *)(ob.slots[0] + 4) = t;
            t = f_039320(d_1c0004, 50);
            *(int *)(ob.slots[0] + 8) = t;
            while (*(int *)(ob.slots[0] + 4) == *(int *)(ob.slots[0] + 8))
                *(int *)(ob.slots[0] + 8) = f_038be0(d_1c0004);
            f_0e9300(DB, DS1, 0x2e000090);
        } else {
            f_0e9300(DB, DS1, 0x2e000091);
        }
        s = ((short (*)(...))f_0bf820)((int)&d_1c2c64,
            f_133fe0((int)d_1c3498, DS1), 3,
            0x2e000092, 0x2e000093, 0x2e000094);
        switch ((short)(s + 1)) {
        case 0:
        case 1:
        case 4:
            break;
        case 2:
            *(int *)(ob.slots[0] + 4) = p;
            f_0bf730(CH, 0x2e000095);
            if (f_044900(p, 5, 5) > 0) {
                f_0bf730(CH, 0x2e000096);
            } else {
                f_0bf730(CH, 0x2e000097);
                s = f_1457e0(6);
                f_044850(p, (short)(s + 2), 1);
            }
            c = ((char)(f_0425f0((struct hero *)(p))));
            if (c == 0) f_0bf730(CH, 0x2e000098);
            d_1c097c = 1;
            f_0db820(d_1c0004, 20);
            break;
        case 3:
            *(int *)(ob.slots[0] + 4) = p;
            f_0bf730(CH, 0x2e000099);
            d_1c097c = 1;
            f_0db820(d_1c0004, 20);
            break;
        }
        if (EQ(d_1c097c, 1)) {
            f_060740(0x1f42, 1);
            f_060740(0x1f44, 1);
        }
    } else {
        f_0bf730(CH, 0x2e00009a);
    }
}
#pragma inline_depth(3)
//@ f_117ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Untersuchung und das Aufbrechen der Wabenkammern 0x3a/0x3b am Ereignis 0x2c5 (sofern
 *   d_1c09a0 == 0 und d_1c0954 == 1): Nach den Rückfragen 0x2e00009b..0x2e00009e werden je nach Entscheidung die
 *   virtuellen Dungeon-Methoden für Objekt 0x3a oder 0x3b aufgerufen und die Kartenobjekte über f_0697c0
 *   aktualisiert.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09a0 (Besuchsflag), r (Antwort bzw. Begleiterzeiger).
 === Ende Beschreibung === */
void f_117ed0(int p1)
{
    if (EQ(d_1c09a0, 0) && EQ(d_1c0954, 1)) {
        short s;
        int t;
        int r;
        d_1c09a0 = 1;
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        s = f_0db9a0(d_1c0004);
        if (s > 1) {
            *(int *)(ob.slots[0] + 4) = f_039320(d_1c0004, 0x33);
            f_0e93f0(DB, DS1, 0x2e00009b);
        } else {
            *(int *)(ob.slots[0] + 4) = f_038c40(d_1c0004);
            f_0e93f0(DB, DS1, 0x2e00009c);
        }
        f_0e9300(DB, DS1, 0x2e00009d);
        t = f_133fe0((int)d_1c3498, DS1);
        r = f_0bf6f0(CH, t);
        if (r == 1) {
            ((void (*)(int, int, int))**(int **)(p1 + 8))(p1, 0x3a, 0);
        } else {
            r = f_0bf6f0(CH, 0x2e00009e);
            if (r == 1) {
                ((void (*)(int, int, int))**(int **)(p1 + 8))(p1, 0x3a, 0);
            } else {
                r = f_1155d0(p1, 1);
                if (r != 0) {
                    *(int *)(ob.slots[0] + 4) = r;
                    f_0bf730(CH, 0x2e00009f);
                    ((void (*)(int, int, int))**(int **)(p1 + 8))(p1, 0x3b, 0);
                } else {
                    f_0bf730(CH, 0x2e0000a0);
                }
            }
        }
        f_0697c0(p1 + 2, 0x3a, 0);
        f_0697c0(p1 + 2, 0x3b, 0);
    }
}
//@ f_118060
/* === Beschreibung (Katalog) ===
 * - Zweck: Spielt beim ersten Betreten von Ereignis 0x2c6 (d_1c0998 == 0) die Animation 0x2c0012 (f_0104b0)
 *   zusammen mit dem Text 0x2e0000a1 über f_0bf980 ab und setzt d_1c0998 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0998 (Einmal-Flag), o (Animations-Objekt S13E).
 === Ende Beschreibung === */
void f_118060()
{
    if (EQ(d_1c0998, 0)) {
        d_1c0998 = 1;
        int o = (int)new (mark(d_1a7c0c, 0x6a0)) S13E;
        o = o ? f_0104b0(o, 0x2c0012, 0, 0) : o;
        f_0bf980(CH, o, 0, 0x2e0000a1, 0);
        if (o != 0) operator delete((void *)f_010590(o, 0));
    }
}
//@ f_1180e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeigt beim ersten Betreten von Ereignis 0x2c7 (d_1c099c == 0), sofern ein Begleiter a über
 *   f_1155d0(p1, 1) verfügbar ist, das Bild 0x0b aus 0x2e0001 mit der Dialogmeldung 0x2e0000a2 zwischen a und
 *   dem Anführer an und setzt d_1c099c = 1.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c099c (Einmal-Flag), a (Begleiter), o (Bildobjekt).
 === Ende Beschreibung === */
void f_1180e0(int p1)
{
    if (EQ(d_1c099c, 0)) {
        int a = f_1155d0(p1, 1);
        if (a != 0) {
            RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
            *(int *)(ob.slots[0] + 4) = a;
            *(int *)(ob.slots[0] + 8) = f_038c40(d_1c0004);
            int o = f_0606a0(0x2e0001, 0xb);
            ((short (*)(int, ...))f_0bfa20)(CH, o, 0, 0x2e0000a2, 0);
            if (o != 0) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
            d_1c099c = 1;
        }
    }
}
//@ f_118190
/* === Beschreibung (Katalog) ===
 * - Zweck: Spielt beim Ereignis 0x2c8 (sofern d_1c0994 == 0 und d_1c0958 == 1) die Animation 0x2c0011 (f_0104b0)
 *   mit der Meldung 0x2e0000a3 über f_0bf980 ab und setzt d_1c0994 = 1.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0994 (Einmal-Flag), p1 (Animations-Objekt).
 === Ende Beschreibung === */
void f_118190()
{
    int p1;
    int t;
    if (EQ(d_1c0994, 0) && EQ(d_1c0958, 1)) {
        t = (int)operator new(0x13e, mark(d_1a7c0c, 0x6de)); p1 = (t != 0) ? f_0104b0(t, 0x2c0011, 0, 0) : t;
        f_0bf980(CH, p1, 0, 0x2e0000a3, 0);
        if (p1) operator delete((void *)f_010590(p1, 0));
        d_1c0994 = 1;
    }
}
//@ f_118230
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Ereignis 0x2c9 die Meldung 0x2e0000a4 über f_0bf730 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_118230()
{
    f_0bf730(CH, 0x2e0000a4);
}
//@ f_118250
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für einen Helden p1, ob dieser anwesend und bei Bewusstsein ist (f_0d4a60 == 1, f_042400 == 0)
 *   und mindestens einen Gegenstand aus der -1-terminierten Liste d_1a7c2a im Inventar trägt (f_0d4aa0).
 * - Eingaben: p1 (Zeiger auf den Helden).
 * - Rückgabewert: 1, wenn der Held einsatzfähig ist und einen passenden Gegenstand besitzt, sonst 0.
 * - Wichtige Variablen: i (Index in d_1a7c2a), r (Trefferflag).
 === Ende Beschreibung === */
int f_118250(int p1)
{
    int r = 0;
    if (f_0d4a60(p1) == 1) {
        if (f_042400((struct hero *)(p1)) == 0) {
            short i = 0;
            for (; d_1a7c2a[i] != -1; i++) {
                short s = f_0d4aa0(p1, (int)d_1a7c2a[i]);
                if (s != -1) { r = 1; break; }
            }
        }
    }
    return r;
}
