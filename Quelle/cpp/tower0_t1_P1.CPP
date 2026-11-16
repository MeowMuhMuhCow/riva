/* === Beschreibung (Katalog) ===
 * Einheit tower0_t1 (0x1275b0 - 0x128a20)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil des Magierturms (tower0.cpp, Dungeon-ID 0x12, untere Etagen des
 * Turms des Magiers). Sie enthält den zentralen Ereignis-Verteiler (f_1275b0), Raumaktionen, Kämpfe sowie das
 * umfangreiche mehrstufige Rätsel- und Dialoggespräch (f_128460) am Eingang bzw. Wächter des Magierturms.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 13/18 gleich (suche.py 25.10.2026, Basis tower0_t1_P1.CPP)
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 4 gleich (vorher 4), Rest 1081 (vorher 1083)
// tower0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1275B0-0x1295C0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038cb0(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039960(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060990(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de480(int p1, int p2);                           // reg eax edx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149a14(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a9820;                    // 0x1A9820
extern short d_1bd922;                    // 0x1BD922
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c0ca0;                    // 0x1C0CA0
extern volatile signed char d_1c0ca4;   // 0x1C0CA4 - verhindert Tail-Merging beim Setzen des Flags in f_127fa0
extern signed char d_1c0ca8;                    // 0x1C0CA8
extern signed char d_1c0cac;                    // 0x1C0CAC
extern int d_1c0cb0;                    // 0x1C0CB0
extern int d_1c0cb4;                    // 0x1C0CB4
extern volatile signed char d_1c0cb8;   // 0x1C0CB8 - verhindert Register-Konstanten-Wiederverwendung von 1 in f_1275b0
extern signed char d_1c0cbc;                    // 0x1C0CBC
extern signed char d_1c0cc0;                    // 0x1C0CC0
extern signed char d_1c0cc8;                    // 0x1C0CC8
extern signed char d_1c0ccc;                    // 0x1C0CCC
extern signed char d_1c0cd0;                    // 0x1C0CD0
extern signed char d_1c0cd4;                    // 0x1C0CD4
extern signed char d_1c0cd8;                    // 0x1C0CD8
extern signed char d_1c0cdc;                    // 0x1C0CDC
extern int d_1c0ce0;                    // 0x1C0CE0
extern int d_1c0ce4;                    // 0x1C0CE4
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c21b8;                    // 0x1C21B8
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a8c58[];           // Text 0x1A8C58

int f_1254a0(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
short f_0bf820();
short f_0bf820(int p1, ...);
 
int f_060740(int p1, int p2);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_0bf680(int p1);
int f_129750();
extern int d_1c3498;
#define EQ(x,v) (((x)==(v))?1:0)
struct OB { int a; int b; char pad[52]; };
#define A64 ((int)&d_1c2c64)
#define OBI(o) f_125400((int)&(o),(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498)
#define OBD(o) f_1254a0((int)&(o),0)
#define OBS(o,v) (*(int *)((o).b + 4) = (v))
typedef short (*VF1)(int);
typedef short (*VF2)(int,int);
typedef short (*VF3)(int,int,int);
#define VF(T,p) ((T)(**(int **)((p)+8)))
struct Dlg14 { char b[0x14]; Dlg14(int a) { f_112df0((int)this, a, 1, 0); } };
void f_127cc0(void);
void f_127e00(void);
void f_127ee0(int p1);
void f_127fa0(int p1);
void f_128460(short p1);
void f_128a20(void);
void f_1291a0(void);
void f_129500(void);
static inline int flaggleich783(signed char wert, const signed char &flag)
{
    return flag == wert;
}
//@ f_1275b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Handler der ersten Magierturm-Ebene (tower0), der sämtliche Raumereignisse, Tür-
 *   und Hebelinteraktionen, Beutecontainer, Kämpfe und Ebenenübergänge anhand des Ereigniscodes ereignis
 *   ausführt.
 * - Eingaben: Die Funktion erhält im Parameter objekt den this-Zeiger des Dungeon-Objekts und in ereignis den
 *   ausgelösten Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis behandelt wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_1275b0(int objekt, unsigned short ereignis)
{
    int bearbeitet = 1;
    int dialog;
    int antwort;
    OB rahmen[5];
    switch (ereignis) {
    case 0x65: ((void (*)(int))f_127cc0)(objekt); return bearbeitet;
    case 0x66: ((void (*)(int))f_127e00)(objekt); return bearbeitet;
    case 0x67: f_127ee0(objekt); return bearbeitet;
    case 0x68: f_127fa0(objekt); return bearbeitet;
    case 0x69: f_0bf730(A64, 0x27000013); return bearbeitet;
    case 0x6b: return bearbeitet;
    case 0x6c:
        if (f_0bf6f0(A64, 0x27000014) == 1) f_0dd750(d_1c0004, 0x139a);
        return bearbeitet;
    case 0x6d: ((void (*)(int))f_128460)(objekt); return bearbeitet;
    case 0xc9: ((void (*)(int))f_128a20)(objekt); return bearbeitet;
    case 0xca:
        if (!flaggleich783(0, d_1c0cd0)) break;
        if (f_0bf6f0(A64, 0x27000036) != 1) break;
        dialog = f_0606a0(0x270001, 2);
        ((int (*)(int,int,int,int,int,...))f_0bfa20)(A64, dialog, 0, 0x27000037, 0);
        f_125ed0((int)&d_1c2c44, 10);
        f_0bf730(A64, 0x27000038);
        d_1c0cd0 = 1;
        f_091f70(0x28);
        f_057220((int)&d_1c2c00, 0x8030028, 0);
        if (dialog) operator delete((void *)((int)(((RivaRasterImage*)(dialog))->f_0fad20( 0))));
        return bearbeitet;
    case 0xcb:
        if (!EQ(d_1c0cd8, 0)) break;
        OBI(rahmen[1]);
        OBS(rahmen[1], f_039320(d_1c0004, 0x1d));
        f_0bf730(A64, 0x27000039);
        f_149a14(0xcb, bearbeitet);
        f_091f70(0x29);
        d_1c0cd8 = 1;
        OBD(rahmen[1]);
        return bearbeitet;
    case 0x12d:
        if (EQ(d_1c0cb8, 0)) {
            f_0bf730(A64, 0x2700003a);
            f_125ed0((int)&d_1c2c44, 15);
            d_1c0cb8 = 1;
        }
        {
            int speicher = (int)operator new(0x14, mark(d_1a8c58, 0x4c5));
            dialog = speicher ? f_112df0(speicher, 0x29, 1, 0) : speicher;
        }
        antwort = f_1131b0(dialog);
        if (antwort) f_112ec0(dialog);
        else f_0bf730(A64, 0x2700003b);
        if (dialog) operator delete((void *)f_112e70(dialog, 0));
        return bearbeitet;
    case 0x191:
        OBI(rahmen[2]);
        OBS(rahmen[2], f_038c40(d_1c0004));
        if ((*(unsigned short *)(objekt + 12))++ < 4) {
            f_0bf730(A64, 0x2700003c);
            f_044850(f_038c40(d_1c0004), 1, 5);
        }
        OBD(rahmen[2]);
        return bearbeitet;
    case 0x192:
        OBI(rahmen[0]);
        if (EQ(d_1c0cbc, 0)) {
            OBS(rahmen[0], f_038c40(d_1c0004));
            f_0bf730(A64, 0x2700003d);
            f_091f70(0x2a);
            f_040780(f_038c40(d_1c0004), 5);
            d_1c0cbc = 1;
        }
        OBD(rahmen[0]);
        return bearbeitet;
    case 0x193:
        OBI(rahmen[3]);
        if (EQ(d_1c0cc0, 0)) {
            OBS(rahmen[3], f_039320(d_1c0004, 0x32));
            f_0bf730(A64, 0x2700003e);
            if ((int)VF(VF3, objekt)(objekt, 0x9a, 0) == 0) d_1c0cc0 = 1;
        }
        OBD(rahmen[3]);
        return bearbeitet;
    case 0x194: ((void (*)(int))f_1291a0)(objekt); return bearbeitet;
    case 0x195: ((void (*)(int))f_129500)(objekt); return bearbeitet;
    case 0x1f5: ((void (*)(int))f_129750)(objekt); return bearbeitet;
    case 0x259:
        OBI(rahmen[4]);
        OBS(rahmen[4], f_039320(d_1c0004, 0x27));
        f_060990(15, 3);
        f_0bf730(A64, 0x27000060);
        OBD(rahmen[4]);
        return bearbeitet;
    case 0x25a:
        f_0bf730(A64, 0x27000061);
        d_1c0cd4 = 1;
        f_0dd7f0(d_1c0004, 4, 0x146b);
        return bearbeitet;
    case 0x2bd:
        if (!EQ(d_1c0ca0, 1) || !EQ(d_1c0cc8, 0)) break;
        f_0bf730(A64, 0x27000062);
        d_1bd922 = 12;
        VF(VF3, objekt)(objekt, 0x99, 0);
        f_0697c0(objekt + 2, 0x99, 0);
        d_1c0cc8 = 1;
        return bearbeitet;
    case 0x321: f_0bf730(A64, 0x27000063); return bearbeitet;
    default: bearbeitet = 0; break;
    case 0x6a: f_0bf730(A64, 0x27000013); return bearbeitet;
    }
    return bearbeitet;
}
//@ f_127cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Bietet dem Spieler am Turmeingang bzw. einer Vorrichtung (0x27000003) drei Optionen an, mit denen
 *   entweder ein Mechanismus (0x1f41, d_1c0ca0) umgeschaltet oder der Magierturm in Richtung Karte 4 (0x139a)
 *   verlassen werden kann.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_127cc0(void)
{
    struct OB ob;
    short v;
    if (EQ(d_1c0ca0, 0)) v = f_0bf820(A64, 0x27000003, 3, 0x27000004, 0x27000005, 0x27000006);
    else v = f_0bf820(A64, 0x27000003, 3, 0x27000007, 0x27000005, 0x27000006);
    switch ((unsigned short)v) {
        case 1:
            if (EQ(d_1c0ca0, 0)) {
                f_060740(0x1f41, 1);
                d_1c0ca0 = 1;
                return;
            }
            if (EQ(d_1c0cc8, 0)) {
                OBI(ob);
                OBS(ob, f_039320(d_1c0004, 0x1e));
                f_0bf730(A64, 0x27000008);
                OBD(ob);
            }
            f_060740(0x1f41, 1);
            d_1c0ca0 = 0;
            return;
        case 2:
            f_0dd7f0(d_1c0004, 4, 0x139a);
    }
}
//@ f_127e00
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft beim Betreten eines Korridors einmalig (d_1c0cdc), ob der Gruppenanführer eine erschwerte
 *   Sinnesschärfe-/Gefahreninstinkt-Probe (Talent 5, Zuschlag 5) besteht, und gibt bei Erfolg eine Warnmeldung
 *   (0x27000009) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_127e00(void)
{
    short s;
    if (((EQ(d_1c0ca4, 0) && EQ(d_1c0ca0, 0)) || (EQ(d_1c0cc8, 0) && EQ(d_1c0ca0, 1))) && EQ(d_1c0cdc, 0)) {
        s = f_044900(f_038c40(d_1c0004), 5, 5);
        if (s >= 0) {
            struct OB ob;
            OBI(ob);
            OBS(ob, f_038c40(d_1c0004));
            f_0bf730(A64, 0x27000009);
            d_1c0cdc = 1;
            OBD(ob);
        }
    }
}
//@ f_127ee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt an einer Tür oder Schwelle (0x2700000a), ob die Gruppe sie passieren möchte, fügt beim ersten
 *   Mal (d_1c0ccc == 0) einem Helden leichten Schaden zu (0x2700000b) und startet den Kampf 5.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_127ee0(int p1)
{
    short s;
    int iVar2;
    iVar2 = f_0bf6f0(A64, 0x2700000a);
    if (iVar2 == 1) {
        if (EQ(d_1c0ccc, 0)) {
            struct OB ob;
            int q;
            OBI(ob);
            q = f_038ba0(d_1c0004);
            OBS(ob, q);
            f_0bf730(A64, 0x2700000b);
            f_044850(q, 2, 5);
            s = VF(VF3, p1)(p1, 5, 0);
            if (s == 0) d_1c0ccc = 1;
            OBD(ob);
        } else {
            f_0bf730(A64, 0x2700000c);
        }
    }
}
//@ f_127fa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt einen bewachten Raum (d_1c0ca4), spielt einen Soundeffekt (0x270008) ab, prüft je nach
 *   Stellung des Mechanismus d_1c0ca0 eine Talentprobe (0x1e, Zuschlag 12) und startet anschließend entweder den
 *   schweren Kampf 4 (6 Gegner) oder den leichteren Kampf 3 (3 Gegner) inklusive Vergabe von Abenteuerpunkten
 *   (0x8030026).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_127fa0(int p1)
{
#pragma aux f_147323 modify [esp];
    short s;
    int iVar2, u;
    struct OB ob;
    OBI(ob);
    if (EQ(d_1c0ca4, 0)) {
        int t_ = *(int *)&d_1a9820;
        f_147323((int)&d_1c2edc, 0x270008, 0x7fff, 0x8000, t_, 0, 1);
        iVar2 = f_0bf6f0(A64, 0x2700000d);
        if (iVar2 == 1) {
            if (EQ(d_1c0ca0, 0)) {
                u = f_039320(d_1c0004, 0x1e);
                OBS(ob, u);
                s = f_044c90(u, 0x1e, 0xc);
                if (s <= 0 || f_0bf6f0(A64, 0x2700000e) == 1) {
                    f_0bf730(A64, 0x2700000f);
                    d_1bd922 = 6;
                    s = VF(VF3, p1)(p1, 4, 0);
                    if (s == 0) {
                        f_060a70();
                        u = f_039660(d_1c0004, 4);
                        OBS(ob, u);
                        f_0bf730(A64, 0x27000010);
                        f_057220((int)&d_1c2c00, 0x8030026, 0);
                        f_091f70(0x27);
                    }
                    d_1c0ca4 = 1;
                }
            } else {
                f_0bf730(A64, 0x27000011);
                d_1bd922 = 3;
                s = VF(VF3, p1)(p1, 3, 0);
                if (s == 0) {
                    f_057220((int)&d_1c2c00, 0x8030026, 0);
                    f_091f70(0x27);
                }
                d_1c0ca4 = 1;
            }
        }
    } else {
        f_0bf730(A64, 0x27000012);
    }
    OBD(ob);
}
//@ f_128180
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raummeldung 0x27000013 aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128180(void)
{
    f_0bf730(A64, 0x27000013);
}
//@ f_1281a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die Raummeldung 0x27000013 aus und liefert den Rückgabewert des Textaufrufs zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0bf730 zurück.
 === Ende Beschreibung === */
int f_1281a0(void)
{
    return f_0bf730(A64, 0x27000013);
}

//@ f_1281c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalter-Funktion für das Ereignis 0x6b in tower0.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1281c0(void)
{
}

//@ f_1281d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt den Spieler (0x27000014), ob er den Bereich verlassen bzw. teleportieren möchte, und setzt die
 *   Gruppe bei Bestätigung auf die Position 0x139a innerhalb der Ebene.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1281d0(void)
{
    int iVar1;
    iVar1 = f_0bf6f0(A64, 0x27000014);
    if (iVar1 == 1) f_0dd750(d_1c0004, 0x139a);
}
//@ f_128200
/* === Beschreibung (Katalog) ===
 * - Zweck: Zeigt das Porträtbild 0x270001 (Index 0) an und lässt den Spieler im Dialog 0x27000016 zwingend eine
 *   von drei Antwortoptionen (0x27000017 bis 0x27000019) auswählen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 bis 3) zurück.
 === Ende Beschreibung === */
short f_128200(void)
{
    int __cdecl f_0bfa20(int, int, int, int, int, int, int, int);
    short u = -1;
    int p1;
    p1 = f_0606a0(0x270001, 0);
    do {
        u = f_0bfa20(A64, p1, 0, 0x27000016, 3,
                     0x27000017, 0x27000018, 0x27000019);
    } while ((short)u == -1);
    if (p1 != 0) operator delete((void *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0))));
    return u;
}
//@ f_128260
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x2700001b zwei Antwortmöglichkeiten (0x2700001c, 0x2700001d) zur
 *   Auswahl, bis eine gültige Wahl getroffen wurde.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 oder 2) zurück.
 === Ende Beschreibung === */
short f_128260(void)
{
    unsigned short r;
    struct OB ob;
    OBI(ob);
    OBS(ob, f_038c40(d_1c0004));
    do {
        r = f_0bf820(A64, 0x2700001b, 2, 0x2700001c, 0x2700001d);
    } while ((short)r == -1);
    OBD(ob);
    return r;
}
//@ f_1282d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x2700001e vier Antwortmöglichkeiten (0x2700001f bis 0x27000022) zur
 *   Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 bis 4) zurück.
 === Ende Beschreibung === */
short f_1282d0(void)
{
    short p2;
    do {
        f_0bf6c0(A64, 5);
        p2 = f_0bf820(A64, 0x2700001e, 4, 0x2700001f, 0x27000020, 0x27000021, 0x27000022);
        f_0bf680(A64);
    } while ((int)p2 == -1);
    return p2;
}
//@ f_128320
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x27000023 zwei Antwortmöglichkeiten (0x27000024, 0x27000025) zur
 *   Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 oder 2) zurück.
 === Ende Beschreibung === */
short f_128320(void)
{
    short s = -1;
    do { s = f_0bf820(A64, 0x27000023, 2, 0x27000024, 0x27000025); } while ((short)s == -1);
    return s;
}
//@ f_128350
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x27000026 zwei Antwortmöglichkeiten (0x2700001c, 0x2700001d) zur
 *   Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 oder 2) zurück.
 === Ende Beschreibung === */
short f_128350(void)
{
    short s = -1;
    do { s = f_0bf820(A64, 0x27000026, 2, 0x2700001c, 0x2700001d); } while ((short)s == -1);
    return s;
}

//@ f_128380
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x27000027 drei Antwortmöglichkeiten (0x27000028 bis 0x2700002a) zur
 *   Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 bis 3) zurück.
 === Ende Beschreibung === */
short f_128380(void)
{
    short s = -1;
    do { s = f_0bf820(A64, 0x27000027, 3, 0x27000028, 0x27000029, 0x2700002a); } while ((short)s == -1);
    return s;
}
//@ f_1283b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x2700002b drei Antwortmöglichkeiten (0x2700001f, 0x27000020,
 *   0x27000022) zur Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 bis 3) zurück.
 === Ende Beschreibung === */
short f_1283b0(void)
{
    short s = -1;
    do { s = f_0bf820(A64, 0x2700002b, 3, 0x2700001f, 0x27000020, 0x27000022); } while ((short)s == -1);
    return s;
}

//@ f_1283e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Stellt dem Spieler im Dialog 0x2700002c zwei Antwortmöglichkeiten (0x27000024, 0x27000025) zur
 *   Auswahl.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die gewählte Antwortnummer (1 oder 2) zurück.
 === Ende Beschreibung === */
short f_1283e0(void)
{
    short s = -1;
    do { s = f_0bf820(A64, 0x2700002c, 2, 0x27000024, 0x27000025); } while ((short)s == -1);
    return s;
}
//@ f_128460
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert als Zustandsautomat (st == 0 bis 15) die Begegnung und das Verhör mit dem Wächter im
 *   Magierturm (d_1c0ca8, d_1c0cac), das je nach gewählten Antworten friedlich endet oder in den Kampf 10 (mit
 *   anschließender Vergabe von Abenteuerpunkten 0x8030027 und Versetzung nach 0x13ec) mündet.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Dungeon-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_128460(int p1)
{
  short __cdecl f_0bf820(void*,int,...);
  short f_0bfa20_x(void*,int,int,int,int,int,int,int);
#pragma aux f_0bfa20_x "f_0bfa20" parm caller [] value [eax] modify exact [eax ebx edx];
  int image;
  short s; unsigned short u;
  void *ctx;
  unsigned st=15;
  if(EQ(d_1c0ca8,0)&&EQ(d_1c0cac,0)) st=0;
  else if(EQ(d_1c0ca8,0)&&EQ(d_1c0cac,1)) {st=4;f_0bf730(A64,0x2700002d);}
  else if(f_0bf6f0(A64,0x27000015)==1) f_0dd750(d_1c0004,0x13ec);
  while(st!=15) {
    ctx=(void*)A64;
    switch(st) {
    case 0:
      image=f_0606a0(0x270001,0);
      do { u=s=f_0bfa20_x(ctx,image,0,0x27000016,3,0x27000017,0x27000018,0x27000019); } while((int)s==-1);
      if(image) operator delete((void*)((int)(((RivaRasterImage*)(image))->f_0fad20(0))));
      switch(u) {case 1:st=1;break;case 2:st=2;break;case 3:st=5;break;} break;
    case 1:
      f_0bf730(A64,0x2700001a); d_1c0cac=1; st=15; break;
    case 2: {
      OB ob; OBI(ob); OBS(ob,f_038c40(d_1c0004));
      do { s=f_0bf820(ctx,0x2700001b,2,0x2700001c,0x2700001d); } while((int)s==-1);
      u=s; OBD(ob);
      switch(u) {case 1:st=3;break;case 2:st=4;break;} break;
    }
    case 3: case 7: case 11: st=1; break;
    case 4:
      if((int)VF(VF3,p1)(p1,10,0)==0) {
        d_1c0ca8=1; d_1c0cac=0; f_091f70(0x2f);
        f_057220((int)&d_1c2c00,0x8030027,0); f_0dd750(d_1c0004,0x13ec);
      }
      st=15; break;
    case 5:
      do {
        f_0bf6c0(A64,5);
        s=f_0bf820(ctx,0x2700001e,4,0x2700001f,0x27000020,0x27000021,0x27000022);
        f_0bf680(A64);
      } while((int)s==-1);
      --s;
      switch((unsigned short)s) {case 0:st=6;break;case 1:st=9;break;case 2:st=10;break;case 3:st=14;break;} break;
    case 6:
      do {s=f_0bf820(ctx,0x27000023,2,0x27000024,0x27000025);} while((int)s==-1);
      switch((unsigned short)s) {case 1:st=7;break;case 2:st=8;break;} break;
    case 8: case 13: st=2; break;
    case 9:
      do {s=f_0bf820(ctx,0x27000026,2,0x2700001c,0x2700001d);} while((int)s==-1);
      switch((unsigned short)s) {case 1:st=3;break;case 2:st=4;break;} break;
    case 10:
      do {s=f_0bf820(ctx,0x27000027,3,0x27000028,0x27000029,0x2700002a);} while((int)s==-1);
      switch((unsigned short)s) {case 1:st=11;break;case 2:st=12;break;case 3:st=13;break;} break;
    case 12:
      do {s=f_0bf820(ctx,0x2700002b,3,0x2700001f,0x27000020,0x27000022);} while((int)s==-1);
      switch((unsigned short)s) {case 1:st=6;break;case 2:st=9;break;case 3:st=14;break;} break;
    case 14:
      do {s=f_0bf820(ctx,0x2700002c,2,0x27000024,0x27000025);} while((int)s==-1);
      switch((unsigned short)s) {case 1:st=7;break;case 2:st=8;break;} break;
    }
  }
}
