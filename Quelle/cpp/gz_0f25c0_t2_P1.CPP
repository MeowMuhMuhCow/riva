/* === Beschreibung (Katalog) ===
 * Einheit gz_0f25c0_t2
 *
 * Diese Einheit bildet den zweiten Teil des Options- und Konfigurationssystems (gz_0f25c0, Teil 2) und enthält
 * sämtliche Callback- und Einstellungsfunktionen für Musik- und Effektlautstärke, CD-Audio, Textgeschwindigkeit,
 * 3D-Sichtweite, Automap-Optionen, Boden-/Decken-Texturen und Kampftempo.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 25/26 gleich (suche.py 28.10.2026, Basis gz_0f25c0_t2_P1.CPP)
// gz_0f25c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F25C0-0x0F5110
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041000();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_060230();                                         // reg - stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0ce650();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcdf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0ef8d0();                                         // reg - stapel 0
int f_0ef8f0();                                         // reg - stapel 0
int f_0ef910();                                         // reg - stapel 0
int f_0ef930();                                         // reg - stapel 0
int f_0ef950();                                         // reg - stapel 0
int f_0ef970();                                         // reg - stapel 0
int f_0ef990();                                         // reg - stapel 0
int f_0ef9b0();                                         // reg - stapel 0
int f_0ef9e0();                                         // reg - stapel 0
int f_0efa10();                                         // reg - stapel 0
int f_0efa30();                                         // reg - stapel 0
int f_0efa50();                                         // reg - stapel 0
int f_0efaa0();                                         // reg - stapel 0
int f_0efb10();                                         // reg - stapel 0
int f_0efb30();                                         // reg - stapel 0
int f_0efb50();                                         // reg - stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern signed char d_1bc7a8;                    // 0x1BC7A8
extern signed char d_1bed80;                    // 0x1BED80
extern signed char d_1bed9c;                    // 0x1BED9C
extern signed char d_1bee00;                    // 0x1BEE00
extern int d_1bf230;                    // 0x1BF230
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c0028;                    // 0x1C0028
extern signed char d_1c00c4;                    // 0x1C00C4
extern signed char d_1c0178;                    // 0x1C0178
extern int d_1c0179;                    // 0x1C0179
extern signed char d_1c017c;                    // 0x1C017C
extern int d_1c017d;                    // 0x1C017D
extern signed char d_1c0180;                    // 0x1C0180
extern int d_1c0181;                    // 0x1C0181
extern signed char d_1c0184;                    // 0x1C0184
extern int d_1c0185;                    // 0x1C0185
extern signed char d_1c0188;                    // 0x1C0188
extern int d_1c0189;                    // 0x1C0189
extern signed char d_1c018c;                    // 0x1C018C
extern int d_1c018d;                    // 0x1C018D
extern signed char d_1c0190;                    // 0x1C0190
extern int d_1c0191;                    // 0x1C0191
extern signed char d_1c0194;                    // 0x1C0194
extern int d_1c0195;                    // 0x1C0195
extern signed char d_1c0198;                    // 0x1C0198
extern int d_1c0199;                    // 0x1C0199
extern signed char d_1c019c;                    // 0x1C019C
extern int d_1c019d;                    // 0x1C019D
extern signed char d_1c01a0;                    // 0x1C01A0
extern int d_1c01a1;                    // 0x1C01A1
extern signed char d_1c01a4;                    // 0x1C01A4
extern int d_1c01a5;                    // 0x1C01A5
extern signed char d_1c01a8;                    // 0x1C01A8
extern int d_1c01a9;                    // 0x1C01A9
extern signed char d_1c01ac;                    // 0x1C01AC
extern int d_1c01ad;                    // 0x1C01AD
extern signed char d_1c01b0;                    // 0x1C01B0
extern int d_1c01b1;                    // 0x1C01B1
extern signed char d_1c01b4;                    // 0x1C01B4
extern int d_1c01b5;                    // 0x1C01B5
extern signed char d_1c01b8;                    // 0x1C01B8
extern int d_1c01b9;                    // 0x1C01B9
extern int d_1c01bc;                    // 0x1C01BC
extern int d_1c01bd;                    // 0x1C01BD
extern signed char d_1c01c0;                    // 0x1C01C0
extern int d_1c01c1;                    // 0x1C01C1
extern int d_1c01c4;                    // 0x1C01C4
extern int d_1c01c5;                    // 0x1C01C5
extern signed char d_1c01c8;                    // 0x1C01C8
extern int d_1c01c9;                    // 0x1C01C9
extern int d_1c01cc;                    // 0x1C01CC
extern int d_1c01cd;                    // 0x1C01CD
extern signed char d_1c01d0;                    // 0x1C01D0
extern int d_1c01d1;                    // 0x1C01D1
extern signed char d_1c01d4;                    // 0x1C01D4
extern int d_1c01d5;                    // 0x1C01D5
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern volatile short d_1c2198; // haelt die 16-Bit-Speicherzugriffe in f_0f4040 wie im Original
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0

typedef RivaTextContextData OB;
#define A(x) ((int)&(x))
typedef short (*VF)(int, int, int);
short f_060760(int p1);
short f_044c90(int p1, int p2, int p3);
short f_0bf820(int p1, ...);
short f_0cda50();
short f_0de7f0(int p1);
short f_0dc020(int p1, int p2);
short f_0dcc10(int p1);
short f_0db9a0(int p1);
short f_0de820(int p1);
short f_1457e0(int p1);

int f_0f5110(int p1);
int f_060740(int p1, int p2);
int f_1254a0(int p1, int p2);
int f_0bde40(int p1);
void f_0d5ff0(short p1);
int f_0bf680(int p1, int p2);
void f_0f2720(int p1);
void f_0f4e00(int p1, int p2);
#pragma aux f_147323 modify [esp];
#define EQ(x,v) (((x)==(v))?1:0)
#define GT(x,v) (((x)>(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0f3920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion baut das Untermenü für die Ton-, Grafik- und Spieleinstellungen auf und verknüpft die
 *   Regler und Umschaltknöpfe mit den jeweiligen Konfigurationsvariablen.
 * - Eingaben: Die Funktion erhält den Zeiger auf das übergeordnete Dialogfenster (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Schließen des Einstellungsmenüs zurück.
 === Ende Beschreibung === */
struct MsgC { int h; OB *q[14]; MsgC(int a, int b, int c) { f_125400((int)this, a, b, c); } ~MsgC() { f_1254a0((int)this, 0); } };
void f_0f3920(void)
{
    if (EQB(d_1c0178, 1) && f_060760(0x1f41) == 1) {
        int t = f_039320(d_1c0004, 0x33);
        if (f_044c90(t, 0x33, 0x14) > 0) {
            MsgC m(A(d_1c349c), A(d_1c3870), A(d_1c3498));
            m.q[0]->addresses.objects = t;
            m.q[0]->addresses.second_objects = f_039320(d_1c0004, 0x30);
            f_0bf730(A(d_1c2c64), 0x25000001);
            f_0bf730(A(d_1c2c64), 0x25000002);
            {
                int snd = d_1a9820;
                f_147323(A(d_1c2edc), 0x25001e, 0x7fff, 0x8000, snd, 0, 1);
            }
            {
                int snd = d_1a9820;
                f_147323(A(d_1c2edc), 0x25001f, 0x7fff, 0x8000, snd, 0, 1);
            }
            f_060740(0x1f41, 1);
            f_0607e0(0x1f41, 1);
        }
    }
}
//@ f_0f3a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert die Beschriftung und den Zustand eines Optionsschalters im
 *   Einstellungsfenster.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Steuerelement (p1) sowie den neuen Zustandswert (p2).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Schaltflächenaktualisierung zurück.
 === Ende Beschreibung === */
void f_0f3a50(void)
{
    if (EQ(d_1bed9c, 0)) {
        if (f_0bf6f0(A(d_1c2c64), 0x25000003) == 1) {
            d_1bed9c = 1;
            if (f_0bf820(A(d_1c2c64), 0x25000004, 2, 0x25000005, 0x25000006) == 2)
                f_0dd7f0(d_1c0004, 0, 0x16a8);
        }
    } else {
        if (f_0bf6f0(A(d_1c2c64), 0x25000007) == 1)
            f_0dd7f0(d_1c0004, 0, 0x16a8);
    }
}
//@ f_0f3ad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet eine boolesche Grafik- oder Spieloption um und speichert den neuen Zustand in
 *   der globalen Konfiguration.
 * - Eingaben: Die Funktionnimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Schalterwert zurück.
 === Ende Beschreibung === */
void f_0f3ad0(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x25000008) == 1) f_0dd7f0(d_1c0004, 0, 0x1c2);
}
//@ f_0f3b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Anzeige von Boden- und Deckentexturen im 3D-Modus ein oder aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den aktualisierten Statuswert zurück.
 === Ende Beschreibung === */
void f_0f3b00(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x25000008) == 1) f_0dd7f0(d_1c0004, 0, 0x1cc);
}
//@ f_0f3b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Beleuchtungs- oder Schattierungseffekte (Shading/Fading) der 3D-Ansicht
 *   um.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Statuswert zurück.
 === Ende Beschreibung === */
void f_0f3b30(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x25000008) == 1) f_0dd7f0(d_1c0004, 0, 0x1d6);
}
//@ f_0f3b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wechselt den Bewegungsmodus im 3D-Dungeon beziehungsweise in der Stadtkulisse zwischen
 *   flüssigem Gleiten und stufenweisem Schrittbetrieb.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Moduswert zurück.
 === Ende Beschreibung === */
void f_0f3b60(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x25000008) == 1) f_0dd7f0(d_1c0004, 0, 0x1e0);
}
//@ f_0f3b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion passt die Detailstufe oder Sichtweite des 3D-Renderers zyklisch an und informiert die
 *   3D-Engine über die Änderung.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der 3D-Parameteraktualisierung zurück.
 === Ende Beschreibung === */
void f_0f3b90(void)
{
    OB ob;
    short s;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    s = f_0bf820(A(d_1c2c64), 0x25000009, 2, 0x2500000a, 0x2500000b);
    if (s == (short)1) {
        if (EQ(d_1c00c4, 1) && GT(d_1bee00, 0)) {
            *(int *)(ob.addresses.objects + 4) = f_038c40(d_1c0004);
            f_0bf730(A(d_1c2c64), 0x2500000c);
        } else {
            f_0dd7f0(d_1c0004, 0, 0x15e0);
        }
    }
    f_1254a0(A(ob), 0);
}
//@ f_0f3c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion regelt die Lautstärke der digitalen Soundeffekte um eine Stufe weiter und spielt zur
 *   Kontrolle einen kurzen Testton ab.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt die neu eingestellte Effektlautstärke zurück.
 === Ende Beschreibung === */
void f_0f3c40(void)
{
    OB ob;
    signed char t;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (EQ(d_1c00c4, 1) && EQ(d_1c01b8, 0) && (t = d_1c01d4 & 2) == 0) {
        *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x33);
        f_0bf730(A(d_1c2c64), 0x2500000d);
        f_057220(A(d_1c2c00), 0x8030012, 0);
        d_1c01d4 |= 2;
    }
    f_1254a0(A(ob), 0);
}
//@ f_0f3ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die digitalen Soundeffekte komplett ein oder stumm.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Stummschaltungsstatus zurück.
 === Ende Beschreibung === */
void f_0f3ce0(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x25000008) == 1) f_0dd7f0(d_1c0004, 0, 0x1ea);
}
//@ f_0f3d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert die Lautstärke der Hintergrundmusik (MIDI oder CD-Audio) und überträgt den
 *   neuen Wert sofort an den Musiktreiber.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt die neue Musiklautstärke zurück.
 === Ende Beschreibung === */
void f_0f3d10(void)
{
    short s;
    int p1;
    int p2;
    for (;;) {
        s = f_0cda50();
        if (s == -1) break;
        p1 = (int)&d_1bfdbc + s * 0x61;
        while (f_0de7f0(p1)) {
            p2 = f_038c80(p1);
            s = f_0dc020(p1, p2);
            f_0dcdf0(p1, (int)s);
            s = f_0dcc10(d_1c0004);
            f_0dcc40(d_1c0004, p2, (int)s);
        }
        d_1c0028 = f_041000();
    }
}
//@ f_0f3d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet den Unterdialog für die Audio-Konfiguration, zeigt die aktuellen Lautstärke-
 *   und Musikquellen-Einstellungen an und verarbeitet die Klicks auf die Regler.
 * - Eingaben: Die Funktion erhält den Zeiger auf das übergeordnete Dialogfenster (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Verlassen des Audiodialogs zurück.
 === Ende Beschreibung === */
void f_0f3d80(int p1)
{
    OB ob;
    short n;
    short r;
    short k;
    short r2;
    int u;
    int v;
    int p2;
    int t;
    int q;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    n = f_0db9a0(d_1c0004);
    if (EQB(d_1c017c, 0) && EQ(d_1c01c8, 1)) {
        if (f_0bf6f0(A(d_1c2c64), 0x2500000f) == 1) {
            u = f_039320(d_1c0004, 0x30);
            v = f_0396f0(d_1c0004, 7);
            d_1c017c = 1;
            f_060740(0x1f43, 1);
            f_0607e0(0x1f43, 1);
            *(int *)(ob.addresses.objects + 4) = u;
            if ((n > 1)) f_0bf730(A(d_1c2c64), 0x25000010); else f_0bf730(A(d_1c2c64), 0x25000011);
            r = (*(VF *)*(int *)(p1 + 8))(p1, 0x2e, 0);
            f_060a70();
            if (r == 0) {
                *(int *)(ob.addresses.objects + 4) = u;
                *(int *)(ob.addresses.objects + 8) = v;
                f_0bf730(A(d_1c2c64), 0x25000012);
                if ((n > 1)) f_0bf730(A(d_1c2c64), 0x25000013); else f_0bf730(A(d_1c2c64), 0x25000014);
            }
            if (r != 2) {
                f_0bf730(A(d_1c2c64), 0x25000015);
                f_060800(0x25000e, 0, (int)f_0f3d10);
                f_0dd7f0(d_1c0004, 0, 0x1c2);
                t = d_1c0004;
                for (k = 0; k < 6; k++) {
                    q = (int)&d_1bfdbc + k * 0x61;
                    if (f_0de7c0(q) != 0 && q != d_1c0004) {
                        r2 = f_0de820(q);
                        if (r2 == 1) {
                            f_041920(q);
                            f_1223c0();
                            f_0bbf00(A(d_1bf230));
                            f_0bf730(A(d_1c2c64), 0x25000016);
                            f_0de210(q);
                        }
                    }
                }
                if (t != d_1c0004) f_041920(t);
            }
        }
    } else {
        if (f_0bf6f0(A(d_1c2c64), 0x2500000f) == 1) f_0bf730(A(d_1c2c64), 0x2500000e);
    }
    f_1254a0(A(ob), 0);
}
//@ f_0f3fc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Hintergrundmusik komplett ein oder aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Musikstatus zurück.
 === Ende Beschreibung === */
void f_0f3fc0(void)
{
    if (EQ(d_1c0180, 0)) {
        d_1c0180 = 1;
        f_0bf730(A(d_1c2c64), 0x25000017);
    }
}
//@ f_0f3ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wechselt die Musikquelle zwischen CD-Audio-Spuren und synthetischer MIDI-/FM-Musik um.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt die gewählte Musikquelle zurück.
 === Ende Beschreibung === */
void f_0f3ff0(int p1)
{
    short s;
    if (f_0d49b0(p1) != 0) {
        s = f_1457e0(4);
        f_044850(p1, (int)(short)(s + 4), 5);
        f_040a00(p1, 2, 5);
    }
}
static inline int h_get0f(int n){int r=f_0606a0(0x250001,n);return r;}
static inline void previous670(int box,int event,int zero1,int zero2){int f_0bfa20(int,...);int f_0bf680(int);f_0bf680(box);f_060800(event,zero1,zero2);}
struct FinalDialog { static inline void run(int handle) { int f_0bfa20(int,...); f_0bbf00(A(d_1bf230)); d_1c2198=0; f_0bfa20(A(d_1c2c64),handle,0,0x25000026,0); f_0dcbb0(d_1c0004,10); } };
struct After1a {static inline void run(int e,int a,int c){f_060800(e,a,c);} };
//@ f_0f4040
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet das Untermenü für die 3D-Grafikoptionen (Texturen, Sichtweite, Lichteffekte,
 *   Schritt-/Drehgeschwindigkeit) und wendet Änderungen unmittelbar auf die 3D-Ansicht an.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Dialogfenster (p1).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der Dialogschleife zurück.
 === Ende Beschreibung === */
void f_0f4040(int slot)
{
    int f_0bfa20(int,...);
    int f_0bbf00(int,int);
    int f_0bf680(int);
    OB ob;
    int a9=0,a0=0,a1,a8,a7,a10,a11;
    int t,q;
    short r2;
    int c;
    if (EQB(d_1c01c8, 0)) {
        if (f_039040(d_1c0004) != 0) {
            c = (signed char)((char)(f_042400((struct hero *)(f_039040(d_1c0004)))));
            if (c == (signed char)4) {
                f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
                a0 = h_get0f(0);
                { signed char rt1315_1 = d_1c01c8; d_1c01c8 = rt1315_1; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                a1 = h_get0f(1);
                a7 = h_get0f(7);
                a8 = h_get0f(8);
                { signed char rt1315_4 = d_1c01c8; d_1c01c8 = rt1315_4; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                a9 = h_get0f(9);
                a10 = h_get0f(10);
                a11 = h_get0f(0xb);
                f_0bf6c0(A(d_1c2c64), 5);
                f_0bf730(A(d_1c2c64), 0x25000018);
                f_060740(0x1f44, 1);
                { int rt1315_9 = d_1c0004; d_1c0004 = rt1315_9; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_0607e0(0x1f44, 1);
                d_1c01c8 = 1;
                f_0d64a0();
                f_0bf730(A(d_1c2c64), 0x25000019);
                f_0bbf00(A(d_1bf230));
                d_1c2198 = 0;
                { int rt1315_11 = d_1c0004; d_1c0004 = rt1315_11; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_060800(0x250010, 0, 0);
                f_0bfa20(A(d_1c2c64), a0, 0, 0x2500001a, 0);
                f_0bf730(A(d_1c2c64), 0x2500001b);
                f_0bf6c0(A(d_1c2c64), 6);
                f_0bde40(A(d_1c2c64));
                f_0bfa20(A(d_1c2c64),a1,0,0x2500001c,0);
                previous670(A(d_1c2c64),0x250012,0,0);
                f_039a80(d_1c0004, (int)f_0f3ff0);
                { int rt1315_14 = d_1c0004; d_1c0004 = rt1315_14; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_0d5ff0(4);
                f_0bbf00(A(d_1bf230));
                f_0bf730(A(d_1c2c64), 0x2500001d);
                { signed char rt1315_15 = d_1c01c8; d_1c01c8 = rt1315_15; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_060800(0x250014, 0, 0);
                f_0bf730(A(d_1c2c64), 0x2500001e);
                { int rt1315_16 = d_1c0004; d_1c0004 = rt1315_16; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_060800(0x250016, 0, 0);
                *(int *)(ob.addresses.objects + 4) = f_0396f0(d_1c0004, 1);
                f_0bf730(A(d_1c2c64), 0x2500001f);
                { int rt1315_17 = d_1c0004; d_1c0004 = rt1315_17; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_060800(0x250018, 0, 0);
                f_0bf730(A(d_1c2c64), 0x25000020);
                After1a::run(0x25001a,0,0); // haelt die Blockgrenze vor dem Aufruf wie im Original
                f_0bde40(A(d_1c2c64));
                f_0bfa20(A(d_1c2c64),a7,0,0x25000021,0);
                { int rt1315_20 = d_1c0004; d_1c0004 = rt1315_20; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_0bfa20(A(d_1c2c64),a8,0,0x25000022,0);
                f_0bde40(A(d_1c2c64));
                f_0bfa20(A(d_1c2c64),a9,0,0x25000023,0);
                { int rt1315_21 = d_1c0004; d_1c0004 = rt1315_21; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_0bfa20(A(d_1c2c64),a10,0,0x25000024,0);
                f_0bf730(A(d_1c2c64), 0x25000025);
                f_0d64a0();
                FinalDialog::run(a11);
                f_091f70(0x12);
                { signed char rt1315_24 = d_1c01c8; d_1c01c8 = rt1315_24; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_060800(0x25001c, 1, 0);
                f_0dd7f0(d_1c0004, 0, 0x1c2);
                f_057220(A(d_1c2c00), 0x8030086, 0);
                f_0bf680(A(d_1c2c64));
                t = d_1c0004;
                for(slot=0;(short)slot<6;++slot){
                    q=(int)&d_1bfdbc+(short)slot*0x61;
                    if(!f_0de7c0(q))continue;
                    if(q==d_1c0004)continue;
                    r2=f_0de820(q);
                    if(r2!=1)continue;
                    f_041920(q);f_1223c0();f_0bbf00(A(d_1bf230));
                    { int rt1315_33 = d_1c0004; d_1c0004 = rt1315_33; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                    f_0bf730(A(d_1c2c64),0x25000016);f_0de210(q);
                }
                if (d_1c0004 != t) f_041920(t);
                if (a11 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a11))->f_0fad20( 0))));
                if (a10 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a10))->f_0fad20( 0))));
                if (a9 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a9))->f_0fad20( 0))));
                if (a8 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a8))->f_0fad20( 0))));
                if (a7 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a7))->f_0fad20( 0))));
                if (a1 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a1))->f_0fad20( 0))));
                if (a0 != 0) operator delete((void *)((int)(((RivaRasterImage*)(a0))->f_0fad20( 0))));
                { int rt1315_30 = d_1c0004; d_1c0004 = rt1315_30; } // haelt die Block- und Registerfolge in f_0f4040 wie im Original
                f_1254a0(A(ob), 0);
                return;
            }
        }
        f_0bf730(A(d_1c2c64), 0x25000028);
    }
}
//@ f_0f4520
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Kampfanimationen oder detaillierten Kampfmeldungen ein oder aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Schalterzustand zurück.
 === Ende Beschreibung === */
void f_0f4520(void)
{
    if (EQ(d_1c0184, 0)) {
        d_1c0184 = 1;
        f_0bf730(A(d_1c2c64), 0x25000029);
    }
}
//@ f_0f4550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert die Anzeigedauer von Textmeldungen und Kampftexten in festen Stufen.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neu gesetzten Geschwindigkeitswert zurück.
 === Ende Beschreibung === */
void f_0f4550(void)
{
    if (f_060760(0x1f45) == 2) {
        if (f_0bf6f0(A(d_1c2c64), 0x2500002a) == 1) {
            f_0dd7f0(d_1c0004, 2, 0x15f2);
            if (EQ(d_1c017c, 0)) {
                d_1c017c = 1;
                d_1c0180 = 1;
                f_060740(0x1f43, 1);
                f_0607e0(0x1f43, 1);
            }
        }
    }
}
//@ f_0f45d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stellt die Verzögerung im rundenbasierten Kampfsystem (Kampftempo) um eine Stufe
 *   weiter.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Verzögerungswert zurück.
 === Ende Beschreibung === */
void f_0f45d0(void)
{
    if (EQ(d_1c0188, 1) && EQ(d_1bed80, 0) && EQ(d_1c01d0, 0)) {
        f_0bf730(A(d_1c2c64), 0x2500002b);
        d_1c01d0 = 1;
    }
}
//@ f_0f4630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet das Untermenü für allgemeine Spieleinstellungen (Kampftempo,
 *   Textgeschwindigkeit, Automap-Verhalten, Bildschirmschoner-Verzögerung) und verarbeitet die Benutzereingaben.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Dialogfenster (p1).
 * - Rückgabewert: Die Funktion gibt den Status nach dem Schließen des Untermenüs zurück.
 === Ende Beschreibung === */
void f_0f4630(void)
{
    OB ob;
    short n;
    int p2;
    if (EQ(d_1c0188, 0) && EQ(d_1bed80, 0)) {
        if (f_126410(A(d_1c2c44)) < 0x1d010 && f_126410(A(d_1c2c44)) > 0x5460) return;
        f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
        *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x33);
        n = f_0db9a0(d_1c0004);
        if ((n > 1)) f_0bf730(A(d_1c2c64), 0x2500002c); else f_0bf730(A(d_1c2c64), 0x2500002d);
        f_0bf730(A(d_1c2c64), 0x2500002e);
        f_125ed0(A(d_1c2c44), 0x1e);
        f_0bf730(A(d_1c2c64), 0x2500002f);
        f_125ed0(A(d_1c2c44), 10);
        f_0bf730(A(d_1c2c64), 0x25000030);
        f_125ed0(A(d_1c2c44), 10);
        f_0bf730(A(d_1c2c64), 0x25000031);
        d_1c0188 = 1;
        f_1254a0(A(ob), 0);
    }
}
//@ f_0f4760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ändert das Zeitintervall bis zum Einschalten des Bildschirmschoners (d_1c019c) oder
 *   schaltet den Bildschirmschoner aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt das neu eingestellte Zeitintervall zurück.
 === Ende Beschreibung === */
void f_0f4760(void)
{
    OB ob;
    int u;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (EQ(d_1c0188, 1)) {
        if (EQ(d_1c018c, 0)) {
            if (f_0bf6f0(A(d_1c2c64), 0x25000032) == 1) {
                u = f_039320(d_1c0004, 0x30);
                d_1c018c = 1;
                f_125ed0(A(d_1c2c44), 5);
                *(int *)(ob.addresses.objects + 4) = u;
                f_0bf730(A(d_1c2c64), 0x25000033);
            }
        }
        if (EQ(d_1c018c, 1)) {
            if (f_060760(0x1f46) == 1) {
                f_060740(0x1f46, 1);
                f_0607e0(0x1f46, 1);
                d_1c01c0 = 0xc;
            }
        }
    }
    f_1254a0(A(ob), 0);
}
//@ f_0f4850
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stuft die Wartezeit oder Schrittweite einer Option (d_1c019c) in Zehnerschritten
 *   zwischen 100, 10, 1 und 0 herunter.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Wert von d_1c019c zurück.
 === Ende Beschreibung === */
void f_0f4850(int p1)
{
    if (EQ(d_1c0190, 0)) {
        if (EQ(d_1c0194, 1)) {
            if (EQ(d_1c0198, 0)) {
                f_0bf730(A(d_1c2c64), 0x25000034);
            } else {
                d_1c0198 = 0;
            }
            if ((*(VF *)*(int *)(p1 + 8))(p1, 0x91, 0) == 0) {
                d_1c0190 = 1;
                d_1c0194 = 0;
                f_09a400();
            } else {
                d_1c0198 = 1;
            }
        }
        if (EQ(d_1c0194, 0) && EQ(d_1c01a0, 1)) {
            if (EQ(d_1c019c, 0)) d_1c019c = 100;
            else if (EQ(d_1c019c, 1)) d_1c019c = 1;
            else if (EQ(d_1c019c, 10)) d_1c019c = 1;
            else d_1c019c -= 10;
            signed char value = d_1c019c;
            if (f_1457e0(value) == 1) d_1c0194 = 1;
        }
    }
    if (EQ(d_1c0190, 1)) f_0de810(d_1c0004, 0x3a);
}
//@ f_0f49b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet eine Zusatzoption für automatische Proben oder Hinweise im Spielverlauf um.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den neuen Optionswert zurück.
 === Ende Beschreibung === */
void f_0f49b0(int p1)
{
    if (EQ(d_1c01a4, 0)) {
        f_0bf730(A(d_1c2c64), 0x25000035);
        d_1c01a4 = 1;
    }
    if (f_0f5110(p1) == 1) d_1c01a0 = 1;
}
//@ f_0f4a00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion formatiert einen numerischen Einstellungs- oder Prozentwert als Zeichenkette und
 *   aktualisiert das zugehörige Textfeld im Optionsdialog.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Dialogelement (p1) sowie den darzustellenden Zahlenwert
 *   (p2).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Textfeldaktualisierung zurück.
 === Ende Beschreibung === */
void f_0f4a00(void)
{
    OB ob;
    int u, w, v;
    if (EQ(d_1c01a8, 0)) {
        u = f_039320(d_1c0004, 0x33);
        { int t_ = (int)(d_1c0004); v = f_039660(t_, 0xc); }
        w = f_039660(d_1c0004, 5);
        if (f_044c90(u, 0x33, 0x10) > 0) {
            f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
            *(int *)(ob.addresses.objects + 4) = u;
            *(int *)(ob.addresses.objects + 8) = v;
            *(int *)(ob.addresses.objects + 0xc) = w;
            f_0bf730(A(d_1c2c64), 0x25000036);
            f_060740(0x1f47, 1);
            f_0607e0(0x1f47, 1);
            f_125ed0(A(d_1c2c44), 10);
            f_0bf730(A(d_1c2c64), 0x25000037);
            f_0bf730(A(d_1c2c64), 0x25000038);
            if (EQ(d_1bc7a8, 1)) f_0bf730(A(d_1c2c64), 0x25000039);
            d_1c01a8 = 1;
            f_1254a0(A(ob), 0);
        }
    }
}
//@ f_0f4b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest die gespeicherten Benutzereinstellungen beim Programmstart aus der
 *   Konfigurationsdatei ein und überträgt sie in die globalen Optionsvariablen.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei Erfolg oder 0 beim Verwenden der Standardwerte zurück.
 === Ende Beschreibung === */
void f_0f4b30(void)
{
    if (EQ(d_1c01ac, 1) && EQ(d_1c0178, 0)) {
        f_0f2720(1);
        d_1c0178 = 1;
        f_091f70(0x10);
        f_056930();
        f_056a30(9);
        f_056950();
        f_019fd0(A(d_1c2a84), 1, f_0de840(d_1c0004), f_0de880(d_1c0004), 0x2500003a);
        f_057220(A(d_1c2c00), 0x8030010, 0);
    }
}
//@ f_0f4bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion speichert die aktuell gewählten Grafik-, Ton- und Spieloptionen dauerhaft in der
 *   Konfigurationsdatei auf der Festplatte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Schreiben oder 0 bei einem Dateifehler zurück.
 === Ende Beschreibung === */
void f_0f4bd0(int p1, int p2)
{
    if (EQ(d_1c01ac, 1) && EQ(d_1c0178, 0)) {
        f_0f4b30();
    } else if (EQ(d_1c01b0, 1) && EQ(d_1c01b8, 0)) {
        f_0f4e00(p1, (short)p2);
    }
}
//@ f_0f4ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt sämtliche Grafik-, Ton- und Spieloptionen auf die ab Werk vorgesehenen
 *   Standardwerte zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den zuletzt gesetzten Standardwert zurück.
 === Ende Beschreibung === */
void f_0f4ce0(void)
{
    OB ob;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (EQ(d_1c01ac, 0)) {
        f_0f2720(0);
        *(int *)(ob.addresses.objects + 4) = f_038c40(d_1c0004);
        f_0bf730(A(d_1c2c64), 0x2500003b);
        d_1c01ac = 1;
        f_091f70(0xf);
        f_056930();
        f_056a30(8);
        f_056950();
        f_057220(A(d_1c2c00), 0x803000f, 0);
    }
    f_1254a0(A(ob), 0);
}
//@ f_0f4d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wendet die geladenen oder geänderten Konfigurationswerte gesammelt auf die aktiven
 *   Subsysteme (Soundtreiber, 3D-Renderer, Timer) an.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt das Ergebnis der letzten Subsystemaktualisierung zurück.
 === Ende Beschreibung === */
void f_0f4d80(void)
{
    OB ob;
    f_125400(A(ob), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (EQ(d_1c01b0, 1) && EQ(d_1c01b4, 0)) {
        *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x33);
        f_0bf730(A(d_1c2c64), 0x2500003c);
        d_1c01b4 = 1;
    }
    f_1254a0(A(ob), 0);
}
