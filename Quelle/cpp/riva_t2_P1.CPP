/* === Beschreibung (Katalog) ===
 * Einheit riva_t2
 *
 * Diese Einheit bildet den zweiten Teil der zentralen Spielinitialisierung (riva, Teil 2) und verwaltet das
 * Speichern und Wiederherstellen des globalen Spielzustands in Spielständen sowie die Systeminformations- und
 * Versionsausgabe auf der DOS-Konsole.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/3 gleich (suche.py 25.10.2026, Basis riva_t2_P1.CPP)
// riva.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0EA400-0x0EC070
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0391f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_03eca0(int p1);                                   // reg eax stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044c90(int p1, int p2, int p3);
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
short f_08c920(int p1, int p2);
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0b38e0();                                         // reg - stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_0bf820(int, ...);
int f_0bfa20(int, ...);
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dbff0(int p1);                                   // reg eax stapel 0
short f_0dc050(int p1, int p2, int p3);
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd6d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de600(int p1, int p2);                           // reg edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
short f_0de800(int p1);
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0

int f_10b890(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1216f0(int p1);
int f_121fd0();                                         // reg - stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
short f_126410(int p1);                                   // reg eax stapel 0
int f_1264f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_126840(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_01046a;                    // 0x01046A
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1bcaa0;                    // 0x1BCAA0
extern int d_1bed70;                    // 0x1BED70
extern int d_1bed7c;                    // 0x1BED7C
extern int d_1bedb8;                    // 0x1BEDB8
extern int d_1bee00;                    // 0x1BEE00
extern int d_1bee0c;                    // 0x1BEE0C
extern signed char d_1bee10;
extern signed char d_1bee14;
extern int d_1bee18;                    // 0x1BEE18
extern unsigned char d_1bfb1c;
extern int d_1c0004;                    // 0x1C0004
extern int d_1c00a8;                    // 0x1C00A8
extern int d_1c00ac;                    // 0x1C00AC
extern signed char d_1c00b4;
extern signed char d_1c00b8;
extern int d_1c00c4;                    // 0x1C00C4
extern int d_1c00c8;                    // 0x1C00C8
extern signed char d_1c00d8;
extern signed char d_1c00dc;
extern int d_1c00e4;                    // 0x1C00E4
extern volatile int d_1c0c94; // haelt die Lade-/Schreibfolge in f_0eba10 wie im Original
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a663c[];           // Text 0x1A663C
void f_0ea240(void);
void f_0ea250(void);
void f_0eba10(int p1);
struct O { int a; int *f4; int c[2]; int *f10; int r[10]; };
#define A(x) ((int)&(x))
#define EQ(x,v) (((x)==(v))?1:0)
#define LTX(x,v) (((x)<(v))?1:0)
#define DELP(x) operator delete((void *)(x));

//@ f_0eb820
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest oder schreibt den allgemeinen Kopf- und Weltzustand eines Spielstands
 *   (Gruppenposition, Tageszeit, aktive Quests, globale Ereignisflags, Automap-Markierungen und Musikstatus)
 *   über das Spielstands-Dateisystem und ruft die Lade- und Speicherroutinen der einzelnen Subsysteme auf.
 * - Eingaben: Die Funktion erhält das Dateihandle beziehungsweise den Zeiger auf den geöffneten
 *   Spielvals-Datenstrom (p1) sowie ein Richtungsflag (p2, 0 zum Laden, 1 zum Speichern).
 * - Rückgabewert: Die Funktion gibt 0 zurück, wenn der Lese- oder Schreibvorgang fehlerfrei abgeschlossen wurde,
 *   oder einen Fehlercode ungleich null bei einem Dateifehler.
 === Ende Beschreibung === */
void f_0eb820(void)
{
    struct O o;
    int p1;
    int r;
    short sv, s;
    unsigned char active;

    f_125400(A(o), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    p1 = f_0606a0(0x120001, 9);
    f_0bf6c0(A(d_1c2c64), 6);
    s = f_0dc050(d_1c0004, 0x1a2, -2);
    if (s != -1) {
        o.f10[1] = 0x12000045;
        f_0bfa20(A(d_1c2c64), p1, 0, 0x12000047, 0);
        f_056a50(0x150011);
        if (EQ(d_1c00d8, 0)) {
            f_039a80(d_1c0004, (int)f_0ea250);
            f_091f70(0x3c);
            d_1c00d8 = 1;
        }
    } else {
        o.f10[1] = 0x12000046;
        f_0bfa20(A(d_1c2c64), p1, 0, 0x12000047, 0);
        f_056a50(0x15003f);
        if (EQ(d_1c00d8, 0)) {
            f_039a80(d_1c0004, (int)f_0ea240);
            f_091f70(0x3c);
            d_1c00d8 = 1;
        }
    }
    sv = f_0de800(d_1c0004);
    f_0de810(d_1c0004, -1);
    active = d_1bfb1c;
    if (active)
        f_121fd0();
    f_060a70();
    f_0de810(d_1c0004, (int)sv);
    r = f_0bf6f0(A(d_1c2c64), 0x12000048);
    if (r == 1) {
        d_1c00b4 = 1;
        f_060800(0x120004, 1, 0);
        f_0eba10(0x82a);
    } else if (EQ(d_1c00b4, 0)) {
        f_057220(A(d_1c2c00), 0x8030016, 0);
        d_1c00b4 = 1;
    }
    f_0bf680(A(d_1c2c64));
    if (p1) DELP(((int)(((RivaRasterImage*)(p1))->f_0fad20( 0))))
    f_1254a0(A(o), 0);
}

//@ f_0eba10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt auf dem DOS-Textbildschirm eine detaillierte Übersicht über den freien
 *   konventionellen und erweiterten Arbeitsspeicher (DPMI/XMS), den aktuellen Speicherpool-Verbrauch, die
 *   geladenen Sound- und Grafiktreiber sowie die CD-ROM-Konfiguration aus (unter anderem beim Start mit dem
 *   Schalter /i).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der abschließenden Bildschirmausgabe zurück.
 === Ende Beschreibung === */
void f_0eba10(int p1)
{
    int wide730(int);
#pragma aux wide730 "f_126410" parm [eax] value [eax] modify exact [eax]
    struct Select730 {
      static int pick(short skill,unsigned short &difficulty) {
        difficulty=0xffff;
        int chosen=0;
        int member=f_038c40(d_1c0004);
        short lowest=99;
        short value=0;
        do {
          value=f_044c90(member,skill,(signed char)difficulty);
          if(value<=0 && value<lowest) {chosen=member;lowest=value;}
          member=f_0391b0(d_1c0004,member);
        } while(member!=f_038c40(d_1c0004));
        return chosen;
      }
    };
    struct Frame730 {int actor2,actor1; unsigned short penalty2,pad2,penalty1,pad1;} fr;
    struct O o;
    int iVar3, iVar9, uVar7, t;

    f_125400(A(o), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    fr.actor1=f_039320(d_1c0004,0x33);
    iVar9=Select730::pick(0xd,fr.penalty1);
    fr.actor2 = f_039320(d_1c0004, 0x16);
    o.f4[1] = fr.actor1;
    o.f4[2] = iVar9;
    o.f4[3] = fr.actor2;
    iVar3 = 0;
    if (f_0bf6f0(A(d_1c2c64), 0x12000049) == 1) {
        uVar7 = d_1c0c94;
        if (EQ((signed char)d_1bfb1c, 0))
            d_1c0c94 = 1;
        do {
            iVar3 = wide730(A(d_1c2c44));
            if (iVar3 >= 0x2a30) {
                f_125f70(A(d_1c2c44), 2);
                f_1216f0(f_126840(A(d_1c2c44), 0));
                iVar3 = f_0bf6f0(A(d_1c2c64), 0x1200004a);
            } else {
                iVar3 = 0;
            }
        } while (iVar3 == 1);
        f_1216f0(f_126840(A(d_1c2c44), 0));
        d_1c0c94 = uVar7;
        if (wide730(A(d_1c2c44)) <= 0x2a30 && f_0bf6f0(A(d_1c2c64), 0x1200004b) == 1) {
            iVar3 = 1;
            f_0bf730(A(d_1c2c64), 0x1200004c);
            switch ((unsigned short)p1) { case 0x82a: f_060800(0x120006, 1, 0); break; case 0x82b: f_060800(0x120008, 1, 0); break; case 0x82c: f_060800(0x12000a, 1, 0); break; }
            if (iVar9 != 0) {
                f_0bf730(A(d_1c2c64),0x1200004d);
                iVar9=Select730::pick(0x11,fr.penalty2);
                if (iVar9 != 0) {
                    f_125ed0(A(d_1c2c44), 10);
                    iVar3 = 0;
                    f_0bf730(A(d_1c2c64), 0x1200004e);
                } else {
                    t = f_044c90(fr.actor1, 0x33, -1);
                    if (t < 0) {
                        f_125ed0(A(d_1c2c44), 10);
                        iVar3 = 0;
                        f_0bf730(A(d_1c2c64), 0x1200004e);
                    } else {
                        f_125ed0(A(d_1c2c44), 5);
                        f_0bf730(A(d_1c2c64), 0x1200004f);
                    }
                }
            }
            if (iVar3 == 1) {
                f_060800(0x12000c, 1, 0);
                t = f_044c90(fr.actor2, 0x16, 0);
                if (t < (short)0) {
                    f_0bf730(A(d_1c2c64), 0x12000050);
                    iVar3 = 0;
                    f_125ed0(A(d_1c2c44), 5);
                } else {
                    f_060800(0x12000e, 1, 0);
                    f_0bf730(A(d_1c2c64), 0x12000051);
                    d_1bee14 = 1;
                    f_039a80(d_1c0004, (int)f_0ea240);
                    f_091f70(0x3d);
                    f_057220(A(d_1c2c00), 0x8030018, 0);
                }
            }
        }
        if (iVar3 == 0)
            d_1c00b4 = 2;
        else
            d_1c00b4 = 3;
    }
    if (iVar3 == 0 && EQ(d_1c00dc, 0)) {
        f_057220(A(d_1c2c00), 0x8030017, 0);
        d_1c00dc = 1;
    }
    f_1254a0(A(o), 0);
}

//@ f_0ebde0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob genügend freier Arbeitsspeicher für den Spielbetrieb vorhanden ist, gibt bei
 *   Speichermangel oder angeforderter Diagnose eine formatierte Systemmeldung aus und wartet gegebenenfalls auf
 *   einen Tastendruck des Benutzers.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Speicherprüfung bestanden wurde, oder 0, wenn der
 *   verfügbare Speicher nicht ausreicht.
 === Ende Beschreibung === */
int f_0bfa20_bx(int, ...);
#pragma aux f_0bfa20_bx "f_0bfa20" modify [ebx];
void f_0ebde0(void)
{
    struct O o;
    int u4, p1, bv, pn;
    unsigned short uv;

    f_125400(A(o), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    u4 = f_038c40(d_1c0004);
    p1 = f_0606a0(0x120001, 10);
    o.f4[1] = u4;
    f_0bf6c0(A(d_1c2c64), 6);
    bv = 0;
    if (EQ(d_1c00b8, 1)) {
        if (f_08c920(0x8b, 0) == 0)
            d_1c00b8 = 0;
        bv = 1;
    } else if (LTX(d_1bee14, 5)) {
        uv = f_0bf820(A(d_1c2c64), 0x12000053, 3, 0x12000054, 0x12000055, 0x12000056);
        switch (uv) {
        case 1:
            f_0bf730(A(d_1c2c64), 0x12000057);
            break;
        case 2:
            f_0b38e0();
            break;
        case 3:
            f_0bf730(A(d_1c2c64), 0x12000058);
            f_044850(u4, 2, 5);
            if (f_08c920(0x8a, 0) == 0) {
                d_1c00b8 = 0;
                d_1bee10 = 1;
            } else {
                d_1c00b8 = 1;
            }
            bv = 1;
            break;
        }
    } else {
        f_0bfa20_bx(A(d_1c2c64), p1, 0, 0x12000059, 0);
        d_1bee10 = 1;
        d_1c00b8 = 0;
    }
    if (EQ(d_1bee10, 1)) {
        if (f_0d4a60(u4) == 0)
            o.f4[1] = f_038c40(d_1c0004);
        if (bv == 1) {
            f_09a400();
            f_0bf730(A(d_1c2c64), 0x12000052);
        } else {
            f_0bf730(A(d_1c2c64), 0x12000052);
            f_091f70(0x3e);
        }
        {
            int nt = (int)operator new(0x14, mark(d_1a663c, 0x57b));
            pn = nt ? f_112df0(nt, 0x46, 0, 1) : nt;
        }
        f_113640(pn);
        f_113340(pn, 0x16b, 1, 0);
        f_112ec0(pn);
        if (pn) DELP(f_112e70(pn, 0))
        f_057220(A(d_1c2c00), 0x8030019, 0);
    }
    f_0bf680(A(d_1c2c64));
    if (p1) DELP(((int)(((RivaRasterImage*)(p1))->f_0fad20( 0))))
    f_1254a0(A(o), 0);
}
