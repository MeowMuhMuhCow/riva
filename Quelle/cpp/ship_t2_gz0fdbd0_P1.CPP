/* === Beschreibung (Katalog) ===
 * Einheit ship_t2_gz0fdbd0 (0fca60 - 0fee00)
 *
 * Überblick
 *
 * Die Einheit ship_t2_gz0fdbd0 vereinigt den zweiten Teil des Orkschiff-Moduls (ship_t2, 0x0FCA60-0x0FDBD0) und
 * den ersten Teil der darauffolgenden Einheit gz_0fdbd0 (0x0FDBD0-0x0FEE00). Sie steuert die dramatischen
 * Höhepunkte an Bord des Schiffs - insbesondere das Einschlagen des Schiffsrumpfs bzw. die Flutung und Flucht
 * vom sinkenden Schiff (f_0fca60, f_0fce00, f_0fcee0), weitere Kabinen-, Kombüsen- und Frachtraum-Interaktionen
 * (f_0fd350 bis f_0fda80), den Konstruktor und Destruktor des Schiffs-Dungeons (f_0fdbd0, f_0fdc30, f_0fdc80)
 * sowie die Haupt-Ereignisverteiler (f_0fdf00, f_0fe5c0).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 22/25 gleich (suche.py 29.10.2026, Basis ship_t2_gz0fdbd0_P1.CPP)
// ship.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0FB660-0x0FDBD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0391f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042380(int p1);                                   // reg eax stapel 0
int f_042400(int p1);                                   // reg eax stapel 0
int f_042960(int p1);                                   // reg eax stapel 0
int f_042a60(int p1, int p2);                           // reg eax edx stapel 0
int f_042ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_043170(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044890(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05f5a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bc060(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0db940(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbda0(int p1);                                   // reg eax stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd440(int p1);                                   // reg eax stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de1c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
                           // reg eax stapel 0
int f_0fdd10(int p1, int p2, int p3);                   // reg eax ebx stapel 0 (SICHERT)
// (Zusammenfuehrung: Deklaration im gz_0fdbd0-Teil) int f_0fdf00(int p1);                                   // reg eax stapel 0
// (Zusammenfuehrung: Deklaration im gz_0fdbd0-Teil) int f_0fe5c0(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
// (Zusammenfuehrung: Deklaration im gz_0fdbd0-Teil) int f_0feb40();                       // nicht in clobber.tsv
int f_0fee00(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0294;                    // 0x1C0294
// (Zusammenfuehrung: Deklaration im gz_0fdbd0-Teil) extern int d_1c0364;                    // 0x1C0364
extern int d_1c0368;                    // 0x1C0368
extern int d_1c036c;                    // 0x1C036C
extern int d_1c0378;                    // 0x1C0378
extern short d_1c2a80;                    // 0x1C2A80
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a67f4[];           // Text 0x1A67F4
int f_1254a0(int p1, int p2);
int f_0bf980(int p1, ...);
short f_0bfa20(int p1, ...);   // Zusammenfuehrung: Typ aus gz_0fdbd0-Teil, Rueckgabe hier unbenutzt
int f_0bde40(int p1);
int f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
signed char f_043a80(int p1);
signed char f_03ad80(int p1, int p2);
signed char f_042470(int p1);
signed char f_0425f0(int p1);
signed char f_0424e0(int p1);
signed char f_0dd410(int p1, int p2);
signed char f_0423c0(int p1);
extern short d_1a6810[];
extern short d_1a6818[];
extern short d_1a6820[];
extern short d_1a6834[];
extern signed char d_1c0360;
extern signed char d_1c0370;
extern signed char d_1c0374;
extern signed char d_1c035c;
extern signed char d_1c038c;
extern int d_1c21a4;
#define A(x) ((int)&(x))
#define EQM(x,v) (((x)==(v))?1:0)
#define EQI(x,v) (((x)==(v))?1:0)
typedef RivaTextContextData OB;
struct Big { char b[0x13e]; };
struct Small { char b[0x14]; };
void f_0fbc60(int p1);
void f_0fce00(int p1, short p2);
void f_0fcee0(int p1);
void f_0fd350(int p1);
void f_0fd540(int p1);
int f_0fd610(int p1, int p2);
int f_0fd7c0(int p1);
void f_0fd7d0(int p1);
int f_0fd900(int p1);
int f_0fd980(int p1);
int f_0fda80(int p1);
//@ f_0fca60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert die Sabotage- und Fluchtsequenz im Schiffsrumpf (d_1c0377): Die Helden können
 *   mit einer schweren Waffe oder Axt (0x66, 0x16a) ein Leck in die Bordwand schlagen, woraufhin Wasser
 *   einbricht, eine Schwimmprobe für alle Gruppenmitglieder (Talent 0x0c mit 1W6 Wasserschaden bei Misserfolg)
 *   durchgeführt wird und das Schiff versinkt.
 *   - Hinweis (Originalfehler): Genau wie in der aufgerufenen/inlined Hilfsfunktion f_0fbd80 wird die
 *     Würfel-Obergrenze n = 6 innerhalb der Schleife über die Helden mit dem jeweiligen Schadenswurf n =
 *     f_1457e0(n) überschrieben, sodass nachfolgende Helden immer weniger Schaden erleiden.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Schiffs-Dungeon-Objekts.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fca60(int p1)
{
    OB ob;
    struct Big *q;
    short v3c, v40, v44;
    short n, cnt, s;
    int it;
    f_125400((int)&ob, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    *(int *)(p1 + 0xd) = 0;
    f_0bf730(A(d_1c2c64), 0x2f010029);
    f_0fd7d0(p1);
    if ((short)f_0de7f0(d_1c0004) > 0) {
        if (EQI(d_1c0370, 2)) {
            f_0bf730(A(d_1c2c64), 0x2f010038);
            v44 = 8;
            n = 6;
            it = f_038c40(d_1c0004);
            do {
                if (it && f_0d4a60(it)) {
                    s = f_044c90(it, 0xe, (signed char)v44);
                    if (s <= 0 && n > 0) {
                        n = f_1457e0(n);
                        f_044850(it, n, 5);
                    }
                }
                it = f_0391b0(d_1c0004, it);
            } while (it != f_038c40(d_1c0004));
            q = new (mark(d_1a67f4, 0x43c)) Big;
            q = q ? (struct Big *)f_0104b0((int)q, 0x2c000e, 0, 0) : q;
            f_0bf6c0(A(d_1c2c64), 6);
            f_0bf980(A(d_1c2c64), (int)q, 0, 0x2f010039, 0);
            f_0bf680(A(d_1c2c64));
            if (q) operator delete((void *)f_010590((int)q, 0));
            v3c = f_0fd900(p1);
            n = 0;
            cnt = 0;
            it = f_038c40(d_1c0004);
            do {
                if (it && f_0d4a60(it)) {
                    s = f_044c90(it, 0xe, (signed char)v3c);
                    if (s > 0) cnt++;
                    else if (n > 0) {
                        n = f_1457e0(n);
                        f_044850(it, n, 5);
                    }
                }
                it = f_0391b0(d_1c0004, it);
            } while (it != f_038c40(d_1c0004));
            if (cnt == 0) {
                f_0bf730(A(d_1c2c64), 0x2f01003a);
                f_0de210(d_1c0004);
                *(short *)&d_1c21a4 = 10;
                goto ende;
            }
            f_0fce00(p1, cnt);
            f_1254a0((int)&ob, 0);
            return;
        } else {
            q = new (mark(d_1a67f4, 0x454)) Big;
            q = q ? (struct Big *)f_0104b0((int)q, 0x2c000e, 0, 0) : q;
            f_0bf6c0(A(d_1c2c64), 6);
            f_0bf980(A(d_1c2c64), (int)q, 0, 0x2f010034, 0);
            f_0bf680(A(d_1c2c64));
            if (q) operator delete((void *)f_010590((int)q, 0));
            v40 = f_0fd900(p1);
            n = 0;
            cnt = 0;
            it = f_038c40(d_1c0004);
            do {
                if (it && f_0d4a60(it)) {
                    s = f_044c90(it, 0xe, (signed char)v40);
                    if (s > 0) cnt++;
                    else if (n > 0) {
                        n = f_1457e0(n);
                        f_044850(it, n, 5);
                    }
                }
                it = f_0391b0(d_1c0004, it);
            } while (it != f_038c40(d_1c0004));
            if (cnt == 0) {
                *(int *)(ob.addresses.objects + 4) = f_039420(d_1c0004, 0xe);
                f_0bf730(A(d_1c2c64), 0x2f010035);
                f_0de210(d_1c0004);
                *(volatile short *)&d_1c21a4 = 10; // verhindert Tail-Merging mit dem else-Zweig vor ende
                f_1254a0((int)&ob, 0);
                return;
            }
            f_0fce00(p1, cnt);
            f_1254a0((int)&ob, 0);
            return;
        }
    } else {
        *(short *)&d_1c21a4 = 10;
    }
ende:
    f_1254a0((int)&ob, 0);
}
//@ f_0fce00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft und behandelt ein weiteres interaktives Objekt im Frachtraum (d_1c0378) und gibt
 *   die zugehörigen Textmeldungen (0x2800003c, 0x2800003d) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fce00(int p1, short p2)
{
    OB ob;
    int h;
    f_125400((int)&ob, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    *(int *)(ob.addresses.objects + 8) = f_039320(d_1c0004, 0xe);
    h = f_0606a0(0x2f0002, 0xf);
    f_0bf6c0(A(d_1c2c64), 6);
    if ((short)p2 == 1) {
        f_0bde40(A(d_1c2c64));
        f_0bfa20(A(d_1c2c64), h, 0, 0x2f010037, 0);
    } else {
        *(int *)(ob.addresses.objects + 4) = f_039420(d_1c0004, 0xe);
        f_0bde40(A(d_1c2c64));
        f_0bfa20(A(d_1c2c64), h, 0, 0x2f010036, 0);
    }
    f_0bf680(A(d_1c2c64));
    if (h) operator delete((void *)((int)(((RivaRasterImage*)(h))->f_0fad20( 0))));
    f_0fcee0(p1);
    f_1254a0((int)&ob, 0);
}
//@ f_0fcee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Methode steuert die Interaktionen in der Kombüse bzw. Vorratskammer des Schiffs
 *   (d_1c0379 bis d_1c037c), wo die Helden das Essen der Mannschaft vergiften oder manipulieren, Vorräte
 *   einstecken und mit dem Schiffskoch interagieren können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fcee0(int p1)
{
    OB ob;
    short wert;
    int flag;
    int person;
    int dialog;
    f_125400((int)&ob, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    wert = f_0db940(d_1c0004);
    flag = 0;
    person = f_039320(d_1c0004, 14);
    *(int *)(ob.addresses.objects + 4) = person;
    Big *neu = new (mark(d_1a67f4, 0x4ab)) Big;
    dialog = neu ? f_0104b0((int)neu, 0x2c000f, 0, 0) : (int)neu;
    if (wert == 1) {
        f_0bf6c0(A(d_1c2c64), 6);
        f_0bf980(A(d_1c2c64), dialog, 0, 0x2f01003b, 0);
        f_0bf680(A(d_1c2c64));
        f_0bf730(A(d_1c2c64), 0x2f01003c);
        f_0de210(d_1c0004);
        *(short *)&d_1c21a4 = 10;
    }
    if (wert > 1) {
        f_0bf6c0(A(d_1c2c64), 6);
        f_0bf980(A(d_1c2c64), dialog, 0, 0x2f01003d, 0);
        f_0bf680(A(d_1c2c64));
        f_044850(person, 4, 5);
        f_0bbf00(A(d_1bf230));
        *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 5);
        f_0bf730(A(d_1c2c64), 0x2f01003e);
        person = f_038c40(d_1c0004);
        do {
            if (EQM(d_1c0360, 2)) {
                wert = f_1457e0(5) - 2;
                if (wert <= 0) wert = 1;
            } else {
                wert = f_1457e0(7);
            }
            signed char wind = d_1c038c;
            wert = wert + 2 * wind;
            if ((short)f_042960(person) > 5) flag = 1;
            f_044850(person, wert, 5);
            person = f_0391b0(d_1c0004, person);
        } while (person != f_038c40(d_1c0004));
        if (flag == 1) f_0bbf00(A(d_1bf230));
        {
            int next = f_039420(d_1c0004, 0x32);
            *(volatile int *)(ob.addresses.objects + 4) = next; // haelt Speicherzugriff vor Registerkopie person = next wie im Original
            person = next;
        }
        if (EQM(d_1c0360, 1)) {
            if ((short)f_1457e0(100) <= 80) {
                f_0bf730(A(d_1c2c64), 0x2f010042);
                wert = f_1457e0(6);
                wert += f_0423c0(person);
                if (wert > 0) {
                    f_044300(person, wert);
                    f_0bbf00(A(d_1bf230));
                }
            } else {
                d_1c0360 = 0;
            }
        }
        if (EQM(d_1c0360, 0)) {
            if ((short)f_044c90(person, 0x32, 8) > 0) {
                f_0bf730(A(d_1c2c64), 0x2f01003f);
                wert = f_145850(2, 6, 0);
                wert -= f_0423c0(person);
                if (wert > 0) {
                    f_044300(person, wert);
                    f_0bbf00(A(d_1bf230));
                }
            } else {
                f_0bf730(A(d_1c2c64), 0x2f010040);
                f_0bf730(A(d_1c2c64), 0x2f010041);
                wert = f_145850(3, 6, 0);
                wert -= f_0423c0(person);
                if (wert > 0) {
                    f_044300(person, wert);
                    f_0bbf00(A(d_1bf230));
                }
            }
        }
        if (EQM(d_1c0360, 0) && (short)f_042960(person) >= 1) {
            f_043e20(person, 1);
            f_0d5040(person, (short)f_0d4c80(person), 0x1fa40, 4, -2, 0);
            f_0d5040(person, (short)f_0d4c80(person), 0x3f480, 4, -1, 0);
            f_0d5040(person, (short)f_0d4c80(person), 0x5eec0, 4, -2, 0);
            f_043e20(person, 0);
        }
        if ((short)f_0db940(d_1c0004) > 0) {
            if (EQM(d_1c035c, 0) && EQM(d_1c0374, 0)) {
                f_0bf6c0(A(d_1c2c64), 6);
                f_0bf730(A(d_1c2c64), 0x2f010043);
                f_0bf680(A(d_1c2c64));
                f_0fbc60(p1);
            } else f_0fd350(p1);
        }
    }
    if (dialog) operator delete((void *)f_010590(dialog, 0));
    f_1254a0((int)&ob, 0);
}
//@ f_0fd350
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet das Durchsuchen einer Kiste oder Waffenkammer (d_1c037d) an Bord und übergibt
 *   den Helden die darin gelagerten Beutestücke.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fd350(int p1)
{
    OB ob;
    int h, iv;
    signed char c;
    struct Big *nb;
    f_125400((int)&ob, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x1d);
    nb = new (mark(d_1a67f4, 0x552)) Big;
    h = nb ? f_0104b0((int)nb, 0x2c0010, 0, 0) : (int)nb;
    f_0bf6c0(A(d_1c2c64), 6);
    f_0bf980(A(d_1c2c64), h, 0, 0x2f010044, 0);
    f_0dbda0(d_1c0004);
    f_125f70(A(d_1c2c44), 4);
    f_0dbda0(d_1c0004);
    f_0bf730(A(d_1c2c64), 0x2f010045);
    iv = f_0fd980(p1);
    if (iv == 1) {
        f_0bf730(A(d_1c2c64), 0x2f010046);
        f_0db9d0(d_1c0004, 2, 0x19);
    }
    iv = f_0fda80(p1);
    if (iv == 1) f_0bf730(A(d_1c2c64), 0x2f010047);
    while (f_126410(A(d_1c2c44)) < 0x1d010) f_125f70(A(d_1c2c44), 1);
    c = f_0dd410(d_1c0004, 1);
    if (c == 5) f_0bf730(A(d_1c2c64), 0x2f010049);
    else f_0bf730(A(d_1c2c64), 0x2f010048);
    f_057220(A(d_1c2c00), 0x8030025, 0);
    f_0d64a0();
    f_091f70(10);
    f_0dd7f0(d_1c0004, 0, 0x15fb);
    f_0bf680(A(d_1c2c64));
    if (h) operator delete((void *)f_010590(h, 0));
    f_1254a0((int)&ob, 0);
}
//@ f_0fd510
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim Betreten oder Untersuchen eines bestimmten Schiffsbereichs die Meldung
 *   0x28000051 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fd510(int p1)
{
    short k;
    for (k = 0; k <= 0x1e; k++) f_033530(p1, k);
}
//@ f_0fd540
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Untersuchen einer weiteren Koje oder Nische (d_1c037f), in der die Helden
 *   nützliche Gegenstände (0x16b) finden können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fd540(int p1)
{
    short k, s;
    int base, old, h, t;
    struct Small *q;
    for (k = 0; k < 6; k++) {
        s = f_0de7f0((int)&d_1bfdbc + k * 0x61);
        if (s == 0) break;
    }
    old = d_1c0004;
    base = (int)&d_1bfdbc + k * 0x61;
    f_0dcc40(base, p1, 0);
    d_1c0004 = base;
    t = (int)new (mark(d_1a67f4, 0x5d5)) Small;
    h = (t != 0) ? f_112df0(t, 0x60, 0, 0) : t;
    f_113640(h);
    f_112ec0(h);
    if (h) operator delete((void *)f_112e70(h, 0));
    d_1c0004 = old;
    f_0dcdf0(base, 0);
}
//@ f_0fd610
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode behandelt das Öffnen und Durchsuchen eines Schranks oder einer Truhe (d_1c0380)
 *   einschließlich einer Fallen- oder Schlossprüfung.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct MsgX { int h; int *q[14]; MsgX(void*, void*, void*); ~MsgX(); };

int f_0fd610(int p1, int p2)
{
    int getT906(int);
    #pragma aux getT906 "f_043170" parm [eax] value [eax] modify exact [eax];
    signed char getA906(int,short);
    #pragma aux getA906 "f_043a80" parm [eax] [edx] value [al] modify exact [eax edx];
    MsgX m((void*)&d_1c349c, (void*)&d_1c3870, (void*)&d_1c3498);
    int r, c, ab;
    m.q[0][1] = p1;
    int t = getT906(p1);
    signed char a = getA906(p1,6);
    ab = a * 100 / 2;
    c = f_03ad80(p1, 0xe);
    int c4 = 4 * c;
    c4 += c;
    c4 += c4;
    short v = (short)(c4 + ab);
    r = 0;
    if (v <= 200) v = 200;
    if (v < (short)t) {
        if (f_042470(p1) == 1) {
            switch ((unsigned short)p2) {
            case 0:
                f_0bf730(A(d_1c2c64), 0x2f01002f);
                break;
            case 1:
                f_0bf730(A(d_1c2c64), 0x2f010030);
                break;
            case 2:
                if (f_0bf6f0(A(d_1c2c64), 0x2f010031) == 1) {
                    int k;
                    int lp = p1;
                    for (k = 0; (short)k <= 0x1e; k++) {
                        f_033530(lp, (short)k);
                        d_1c2a80 = (d_1c2a80 & 0) ? (short)0 : d_1c2a80; // haelt t auf [esp+0x3c] statt ecx wie im Original
                    }
                } else {
                    r = 1;
                    f_0bf730(A(d_1c2c64), 0x2f010032);
                }
                break;
            }
        } else {
            switch ((unsigned short)p2) {
            case 0:
                f_0bf730(A(d_1c2c64), 0x2f01002b);
                break;
            case 1:
                f_0bf730(A(d_1c2c64), 0x2f01002c);
                break;
            case 2:
                f_0bf730(A(d_1c2c64), 0x2f01002d);
                break;
            case 3:
                r = 1;
                f_0bf730(A(d_1c2c64), 0x2f01002e);
                break;
            }
        }
        if (r == (short)0) f_0fd540(p1);
    }
    return r;
}
//@ f_0fd7c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kleine Zugriffsmethode setzt das Statusflag d_1c0371 auf 1.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fd7c0(int p1)
{
    int r = 0;
    if (p1 != 0) r = 1;
    return r;
}
//@ f_0fd7d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert das Klettern über eine Schiffsleiter oder Luke (d_1c0381) zwischen den Decks
 *   und prüft, ob Wachen in der Nähe alarmiert werden.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct MsgC { int h; char *q[14]; MsgC(int,int,int); ~MsgC(); };
extern int d_1c2c64;
void f_0fd7d0(int p1)
{
    short i;
    short k;
    short n;
    int buf[7];
    for (i = 0; (short)i <= 3; i++) {
        n = f_0398c0(d_1c0004, (int)f_0fd7c0, (int)buf);
        for (k = 0; (short)k < (short)n; k++) {
            int s;
            int ok=0;
            int w;
            s = buf[(short)k];
            MsgC m(A(d_1c349c), A(d_1c3870), A(d_1c3498));

            ((int*)m.q[0])[1] = s;
            if (f_0425f0(s) == 1) {
                f_0bf730(A(d_1c2c64), 0x2f01002a);
                f_044890(s, 5);
            }
            if (f_0424e0(s) == 1) {
                f_0bf730(A(d_1c2c64), 0x2f010033);
                ok = 1;
            }
            if (!ok) ok = f_0fd610(s, (short)i);
            if (ok == 1) {
                w = f_0dc020(d_1c0004, s);
                f_0dcd30(d_1c0004, (short)w, -1);
                *(int *)&d_1c2a80 = 0;
                f_0bc060(A(d_1bf230));
            }
        }
    }
    { short rt = d_1c2a80; d_1c2a80 = rt; } // haelt die Stapelplatz-Sortierung der lokalen Variablen wie im Original
}
//@ f_0fd900
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim Untersuchen eines Schiffsobjekts (d_1c0382) einen Beschreibungstext
 *   (0x2800005f) aus und aktualisiert den Objektstatus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fd900(int p1)
{
    if (EQM(d_1c0370, 0)) {
        if (!EQM(d_1c0374, 0)) return 6;
    } else {
        if (EQM(d_1c0370, 1)) {
            if (EQM(d_1c0374, 0)) return 7;
            return 3;
        }
        if (EQM(d_1c0374, 0)) return 0xe;
    }
    return 10;
}
//@ f_0fd980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die Interaktion mit einem Geschütz, Ankerspill oder Steuerrad (d_1c0383) an
 *   Bord des Schiffs.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fd980(int p1)
{
    int cur, fl, ret;
    short s1, s3, s2, k;
    cur = f_038c40(d_1c0004);
    ret = 0;
    do {
        s1 = f_042a60(cur, 5);
        k = 0;
        s2 = f_042a60(cur, 10);
        fl = 0;
        s3 = f_042a60(cur, 9);
        while (d_1a6810[k] != -1 && fl == 0 && s1 > 0) {
            if (s1 == d_1a6810[k]) {
                fl = 1;
                ret = fl;
            } else {
                k = k + 1;
            }
        }
        s1 = 0;
        while (d_1a6820[s1] != -1 && fl == 0 && (s2 > 0 || s3 > 0)) {
            if (s2 == d_1a6820[s1] || s3 == d_1a6820[s1]) {
                fl = 1;
                ret = fl;
            } else {
                s1 = s1 + 1;
            }
        }
        { int t_ = d_1c0004; cur = f_0391b0(t_, cur); }
    } while (cur != f_038c40(d_1c0004));
    return ret;
}
//@ f_0fda80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lässt die Helden einen weiteren Lagerplatz (d_1c0384) durchsuchen und händigt gefundene
 *   Gegenstände (0x169, 0x16a) aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0fda80(int p1)
{
    int r = 0;
    int c;
    short i, w, v;
    short k;
    int found;
    c = f_038c40(d_1c0004);
    do {
        if (c) {
            for (i = 0; (short)i < 30; i++) {
                v = f_042a60(c, (short)i);
                if (v > 0) {
                    w = f_042ac0(c, (short)i);
                    found = 0;
                    for (k = 0; d_1a6834[(short)k] != -1 && !found; k++) {
                        if (v == d_1a6834[(short)k]) {
                            short x = ((short)f_1457e0(0x29) + 0x31) * w / 100;
                            found = 1;
                            f_036300(c, (short)i, x);
                            r = found;
                        }
                    }
                    for (k = 0; d_1a6818[(short)k] != -1 && !found; k++) {
                        if (v == d_1a6818[(short)k]) {
                            int t = (short)f_1457e0(0x33);
                            t += 0x31;
                            short y = t * w / 100;
                            f_036300(c, (short)i, y);
                            found = 1;
                        }
                    }
                }
            }
        }
        c = f_0391b0(d_1c0004, c);
    } while (c != f_038c40(d_1c0004));
    return r;
}

// ===== gz_0fdbd0_t1 (gleiches Originalmodul: f_0fe9d0/f_0feb40 springen in den Epilog 0FD4F5 von f_0fd350)
#include <string.h>

typedef signed char FL;
typedef unsigned short KT;
typedef short (*FPS)(int,int,int);
typedef int (*FPI)(int,int,int);
#define VCS(p,a,b) ((*(FPS *)(*(int *)((p)+8)))((p),(a),(b)))
#define VCI(p,a,b) ((*(FPI *)(*(int *)((p)+8)))((p),(a),(b)))
#define EQI(x,v) (((x)==(v))?1:0)
#define KSW(x,k) switch (x) { case 0x17: k = 10; break; case 0x18: k = 0x14; break; case 0x19: k = 0x1e; break; }
#define BOX ((int)&d_1c2c64)
// OB: identisch im ship_t2-Teil
int f_039040(int p1);
int f_039660(int p1, int p2);
int f_0396f0(int p1, int p2);
int f_060a70(void);
int f_0606a0(int p1, int p2);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0bf820(int p1, ...);
short f_0bfa20(int p1, ...);
int f_0d5ff0(int p1);
int f_0dd440(int p1);
int f_0de820(int p1);

int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
extern int d_1c0004;
extern FL d_1c02a0;
extern FL d_1c02b0;
extern FL d_1c02b4;
extern FL d_1c02b8;
extern signed char d_1c02bc;
extern signed char d_1c02e8;
extern FL d_1c0300;
extern FL d_1c031c;
extern FL d_1c0340;
extern FL d_1c0364;
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0fdbd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das 3D-Dungeon-Objekt ship (Kennung 0x29), trägt die virtuelle
 *   Methodentabelle d_19e10c ein, lädt die .LXT-Textdatei nach d_1c0368 und ruft die Zustandsinitialisierung
 *   f_0fb660 auf.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie das Konstruktor-Flag p2.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_0fdbd0(void)
{
  OB ob;
  f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  d_1c02a0 = 1;
  f_0d5ff0(5);
  *(int *)(ob.addresses.objects + 4) = f_039040(d_1c0004);
  f_0bf730(BOX, 0x2f000025);
  f_1254a0((int)&ob, 0);
}
//@ f_0fdc30
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser COMDAT-Destruktor-Wrapper baut das ship-Dungeon-Objekt ab und gibt bei gesetztem Bit 2 in p2
 *   den Speicher über operator delete frei.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0fdc30(void)
{
  int k;
  unsigned short x = f_0de820(d_1c0004);
  KSW(x, k)
  return k + f_0dd440(d_1c0004);
}
//@ f_0fdc80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt beim Verlassen des Orkschiffs den geladenen .LXT-Textpuffer d_1c0368 wieder
 *   frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
void f_0fdc80(void)
{
  if (EQI(d_1c02e8, 0)) {
    d_1c02b4 = 1;
  } else {
    d_1c02bc = 1;
  }
}
//@ f_0fdcb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode initialisiert die 3D-Darstellung des Schiffs, spielt die Hintergrundatmosphäre ab und
 *   synchronisiert über f_0fb740 alle Türen und Luken mit dem gespeicherten Spielstand.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_0fdcb0(int p1, int p2, int p3)
{
  short s;
  s = VCS(p1, (short)p2, 0);
  if (s == 0) {
    f_060a70();
    d_1c0300 = 1;
    f_0bf730(BOX, p3);
    return;
  }
  d_1c0364 = 2;
}
//@ f_0fdcf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wird beim Beenden der 3D-Ansicht des Schiffs aufgerufen und schaltet laufende
 *   Spezialeffekte (f_120ce0) ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_0fdcf0(void)
{
  f_0bf730(BOX, 0x2f000175);
}
//@ f_0fdd10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft zeit- und schrittabhängige Ereignisse an Bord des Schiffs, etwa das Auftauchen
 *   von Patrouillen oder das Fortschreiten eines Alarms (d_1c036d, d_1c036e).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereignistyp p2 sowie einen Statuszeiger p3.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_0fdd10(int p1)
{
  short s;
  short x;
  unsigned short k;
  short choice;
  short result;
  int result2;

  s = f_0de820(d_1c0004);
  if (s == 0x18) f_0bf730(BOX, 0x2f000176);
  if (s == 0x17) {

  x = f_0de820(d_1c0004);
  switch (x) {
    case 0x17: k = 10; break;
    case 0x18: k = 20; break;
    case 0x19: k = 30; break;
  }
  k += f_0dd440(d_1c0004);

  switch (k) {
    case 15: case 16: case 17:
      choice = f_0bf820(BOX, 0x2f000177, 2, 0x2f000178, 0x2f000179);
      if (choice == 1) {
        f_0bf730(BOX, 0x2f00017a);
        result = VCS(p1, 0x33, 2);
        if (result == 0) {
          f_060a70();
          d_1c0364 = 4;
          f_0bf730(BOX, 0x2f00017b);
          return;
        }
        if (result == 1) {
          d_1c0364 = 2;
          return;
        }
      } else {
        f_0bf730(BOX, 0x2f00017c);
      }
      return;

    case 14:
      do {
        choice = f_0bf820(BOX, 0x2f00017d, 2, 0x2f00017e, 0x2f00017f);
      } while (choice == -1);
      if (choice == 1) {
        f_0bf730(BOX, 0x2f000180);
        result2 = VCI(p1, 0x33, 2);
        if (result2 == 0) {
          f_060a70();
          d_1c0364 = 4;
          f_0bf730(BOX, 0x2f00017b);
          return;
        }
        if (result2 == 1) {
          d_1c0364 = 2;
          return;
        }
      } else {
        f_0bf730(BOX, 0x2f000181);
      }
      return;

    case 11: case 12: case 13:
      f_0bf730(BOX, 0x2f000182);
      return;
  }
  }
}
struct Stores660 { static void success(FL v){d_1c0300=v;} static void failure(FL v){d_1c0364=v;} };
//@ f_0fdf00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese große Verteilerfunktion verarbeitet die primären Kartenereignisse (0x00 bis 0x2f) auf dem
 *   Orkschiff, darunter sämtliche Kabinentüren, Leitern zwischen Ober- und Unterdeck, Kämpfe gegen die
 *   Schiffsbesatzung sowie die Interaktionsobjekte aus ship_t1 und ship_t2.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktionszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der ausgeführten Interaktion zurück.
 === Ende Beschreibung === */
void f_0fdf00(int p1)
{
  struct Act660 { static void run(int self, int code, int msg) {
    short result=VCS(self,code,0);
    if (result == 0) {
      f_060a70(); Stores660::success(1); f_0bf730(BOX,msg); return;
    }
    Stores660::failure(2);
  } };
  struct Mark660 { static void run() {
    if (EQI(d_1c02e8,0)) d_1c02b4=1;
    else d_1c02bc=1;
  } };
  OB ob;
  unsigned short x,k;
  short choice;
  int p;
  f_125400((int)&ob,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498);
  x=f_0de820(d_1c0004);
  switch(x) { case 0x17:k=10;break; case 0x18:k=20;break; case 0x19:k=30;break; }
  k+=f_0dd440(d_1c0004);
  f_0bf6c0(BOX,5);
  switch(k) {
  case 21: case 22: case 23: case 34: case 37:
    Mark660::run(); break;
  case 32: case 33: case 35: case 36:
    f_0bf730(BOX,0x2f000183); Mark660::run(); break;
  case 38:
    p=f_0606a0(0x2f0002,0x14);
    choice=f_0bfa20(BOX,p,0,0x2f000184,2,0x2f000185,0x2f000186);
    if(choice==2) Act660::run(p1,0x6d,0x2f000188);
    else { f_0bf730(BOX,0x2f000187);d_1c0364=2; }
    if(p) operator delete((void*)((int)(((RivaRasterImage*)(p))->f_0fad20(0))));
    break;
  case 27:
    p=f_0606a0(0x2f0002,0x15);
    choice=f_0bfa20(BOX,p,0,0x2f000189,2,0x2f000185,0x2f000186);
    if(choice==2) Act660::run(p1,0x69,0x2f00018a);
    else { f_0bf730(BOX,0x2f000187);d_1c0364=2; }
    if(p) operator delete((void*)((int)(((RivaRasterImage*)(p))->f_0fad20(0))));
    break;
  case 24: case 25: case 26:
    do { choice=f_0bf820(BOX,0x2f00018b,2,0x2f00018c,0x2f00018d); } while(choice==-1);
    if(choice==1) Act660::run(p1,0x69,0x2f00018a);
    else {f_0bf730(BOX,0x2f00018e);Mark660::run();}
    break;
  case 15: case 16: case 17:
    do { choice=f_0bf820(BOX,0x2f00018b,2,0x2f00018c,0x2f00018d); } while(choice==-1);
    if(choice==1) Act660::run(p1,0x34,0x2f00018a);
    else {
      if(EQI(d_1c02e8,0)) {d_1c02b4=1; f_0bf730(BOX,0x2f000191);}
      else {
        choice=f_0bf820(BOX,0x2f00018f,2,0x2f00018c,0x2f00018d);
        if(choice==1) Act660::run(p1,0x34,0x2f00018a);
        else {f_0bf730(BOX,0x2f000190);d_1c0364=2;}
      }
    }
    break;
  case 12:
    do { choice=f_0bf820(BOX,0x2f000192,2,0x2f00018c,0x2f00018d); } while(choice==-1);
    if(choice==1) Act660::run(p1,0x32,0x2f000193);
    else {
      if(EQI(d_1c02e8,0)) {d_1c02b4=1; f_0bf730(BOX,0x2f000194);}
      else {
        choice=f_0bf820(BOX,0x2f000195,2,0x2f000196,0x2f00018d);
        if(choice==1) Act660::run(p1,0x32,0x2f000194);
        else {f_0bf730(BOX,0x2f000197);d_1c0364=2;}
      }
    }
    break;
  case 14:
    choice=f_0bf820(BOX,0x2f000189,2,0x2f000185,0x2f000186);
    if(choice==2) Act660::run(p1,0x32,0x2f00018a);
    else {f_0bf730(BOX,0x2f000187);d_1c0364=2;}
    break;
  case 13:
    choice=f_0bf820(BOX,0x2f000198,2,0x2f000185,0x2f000186);
    if(choice==2) Act660::run(p1,0x31,0x2f000193);
    else {f_0bf730(BOX,0x2f000199);d_1c0364=2;}
    break;
  case 11:
    if(EQI(d_1c02e8,1)) {
      *(int*)(ob.addresses.objects+4)=f_039660(d_1c0004,13);
      f_0bf730(BOX,0x2f00019a);
      Act660::run(p1,0x2f,0x2f000193);
    }
    break;
  }
  f_0bf680(BOX);
  f_1254a0((int)&ob,0);
}
//@ f_0fe5c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zweite große Verteilerfunktion verarbeitet die übrigen Karten- und Objektereignisse (0x30 bis
 *   0x53) auf dem Orkschiff, insbesondere verschlossene Luken, Beutekisten, Geheimfächer und Deckübergänge.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktionszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der Interaktion zurück.
 === Ende Beschreibung === */
void f_0fe5c0(int p1)
{
  unsigned short x, k;
  short s;
  if ((EQI(d_1c0300, 0) && EQI(d_1c02b0, 1) && EQI(d_1c02b4, 1)) ||
      (EQI(d_1c0300, 0) && EQI(d_1c02bc, 0))) {
    x = f_0de820(d_1c0004);
    switch (x) { case 0x17: k = 10; break; case 0x18: k = 20; break; case 0x19: k = 30; break; }
    k += f_0dd440(d_1c0004);
    switch (k) {
    case 21: case 22: case 23: case 24: case 25: case 26:
    case 32: case 33: case 34: case 35: case 36: case 37:
      if (EQI(d_1c02e8, 1)) d_1c0364 = 2;
      else d_1c0364 = 4;
      break;
    case 38:
      if (EQI(d_1c02bc, 1)) f_0bf730(BOX, 0x2f00019b);
      else f_0bf730(BOX, 0x2f00019c);
      if (VCS(p1, 0x6d, 0) == 0) { f_060a70(); d_1c0300 = 1; f_0bf730(BOX, 0x2f000188); }
      else d_1c0364 = 2;
      break;
    case 27:
      if (EQI(d_1c02bc, 1)) f_0bf730(BOX, 0x2f00019b);
      else f_0bf730(BOX, 0x2f00019c);
      if (VCS(p1, 0x69, 0) == 0) { f_060a70(); d_1c0300 = 1; f_0bf730(BOX, 0x2f00018a); }
      else d_1c0364 = 2;
      break;
    case 14:
      if (EQI(d_1c02bc, 1)) f_0bf730(BOX, 0x2f00019d);
      else f_0bf730(BOX, 0x2f00019e);
      if (VCS(p1, 0x34, 0) == 0) { f_060a70(); d_1c0300 = 1; f_0bf730(BOX, 0x2f00018a); }
      else d_1c0364 = 2;
      break;
    case 15: case 16: case 17:
      if (EQI(d_1c02bc, 1)) s = f_0bf820(BOX, 0x2f00019f, 2, 0x2f00018c, 0x2f00018d);
      else s = f_0bf820(BOX, 0x2f0001a0, 2, 0x2f00018c, 0x2f00018d);
      if (s == 1) {
        if (VCS(p1, 0x34, 0) == 0) { f_060a70(); d_1c0300 = 1; f_0bf730(BOX, 0x2f00018a); }
        else d_1c0364 = 2;
      } else { f_0bf730(BOX, 0x2f0001a1); d_1c0364 = 2; }
      break;
    case 12:
      if (EQI(d_1c02bc, 0)) {
        s = f_0bf820(BOX, 0x2f0001a2, 2, 0x2f00018c, 0x2f00018d);
        if (s == 1) {
          if (VCS(p1, 0x32, 0) == 0) { f_060a70(); d_1c0300 = 1; f_0bf730(BOX, 0x2f000193); }
          else d_1c0364 = 2;
        } else { f_0bf730(BOX, 0x2f00019f); d_1c0364 = 2; }
      }
      break;
    case 11: case 13:
      break;
    default:
      if (EQI(d_1c02e8, 1)) d_1c0364 = 2;
      else d_1c0364 = 4;
      break;
    }
  } else d_1c02b8 = 1;
}
//@ f_0fe990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt beim ersten Betreten eines Deckabschnitts (d_1c0385) die Beschreibung 0x28000001
 *   aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fe990(void)
{
}
//@ f_0fe9d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert eine Begegnung mit Wachen an Deck (d_1c0386), bei der die Helden entweder ein
 *   Passwort/Tarnung nutzen oder in einen Kampf verwickelt werden.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fe9d0(void)
{
  OB ob;
  unsigned short x,k;
  f_125400((int)&ob,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498);
  x=f_0de820(d_1c0004);
  switch(x) { case 0x17:k=10;break; case 0x18:k=20;break; case 0x19:k=30;break; }
  k+=f_0dd440(d_1c0004);
  switch(k) {
  case 22:
    *(int*)(ob.addresses.objects+4)=f_0396f0(d_1c0004,0);
    f_0bf730(BOX,0x2f0001a3);
    f_0bf730(BOX,0x2f0001a4);
    break;
  case 14:
    *(int*)(ob.addresses.objects+4)=f_0396f0(d_1c0004,0);
    f_0bf730(BOX,0x2f0001a5);
    break;
  case 15: case 16: case 17:
    f_0bf730(BOX,0x2f0001a6);
    break;
  case 11: case 12: case 13:
    f_0bf730(BOX,0x2f0001a7);
    break;
  }
  f_1254a0((int)&ob,0);
}
//@ f_0feb10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode startet einen Kampf gegen eine Gruppe Schiffs-Orks (0x1f42).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void f_0feb10(void)
{
  f_0de820(d_1c0004);
}
//@ f_0feb40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verwaltet die Interaktion mit dem Beiboot oder Ruderboot (d_1c0387), mit dem die Helden
 *   das Orkschiff verlassen oder nach der Sabotage ans Ufer fliehen können.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0feb40(void)
{
  OB ob;
  short s;
  unsigned short x,k;
  f_125400((int)&ob,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498);
  s = f_0de820(d_1c0004);
  if ((int)s == 0x18) {
    if (EQI(d_1c0340, 0)) {
      x = f_0de820(d_1c0004);
      switch(x) { case 0x17:k=10;break; case 0x18:k=20;break; case 0x19:k=30;break; }
      k += f_0dd440(d_1c0004);
      switch (k) {
      case 0x15: case 0x18: case 0x1b: break;
      case 0x19:
      case 0x1a:
        *(int *)(ob.addresses.objects + 4) = f_039660(d_1c0004, 5);
        f_0bf730(BOX, 0x2f0001a8);
        f_0bf730(BOX, 0x2f0001a9);
        break;
      case 0x17:
        if (EQ(d_1c031c, 3)) f_0bf730(BOX, 0x2f0001ab);
        else f_0bf730(BOX, 0x2f0001aa);
        break;
      case 0x16:
        s = f_0bf820(BOX, 0x2f0001ac, 2, 0x2f0001ad, 0x2f0001ae);
        if ((int)s == 2) {
          f_0bf730(BOX, 0x2f0001b4);
          d_1c0340 = 1;
          break;
        }
        if (EQ(d_1c031c, 3))
          s = f_0bf820(BOX, 0x2f0001b0, 2, 0x2f0001b1, 0x2f0001b2);
        else
          s = f_0bf820(BOX, 0x2f0001af, 2, 0x2f0001b1, 0x2f0001b2);
        if (s == 1) {
          f_0bf730(BOX, 0x2f0001b4);
          d_1c0340 = 1;
          break;
        }
        f_0bf730(BOX, 0x2f0001b3);
        break;
      }
    }
  }
  f_1254a0((int)&ob,0);
}
//@ f_0fed80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft einen Ausguck oder ein Bullauge (d_1c0388) und gibt je nach Schiffszustand den
 *   passenden Beschreibungstext aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0fed80(void)
{
  short s;
  unsigned short x;
  short k;
  s = f_0de820(d_1c0004);
  if (s == 0x19) {
    x = f_0de820(d_1c0004);
    KSW(x, k)
    k += f_0dd440(d_1c0004);
    if (k != 0x26 && k != 0x21) {
      f_0bf730(BOX, 0x2f0001c4);
    }
  }
}
