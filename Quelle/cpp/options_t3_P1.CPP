/* === Beschreibung (Katalog) ===
 * Einheit options_t3 (0d99d0 - 0d9cb0)
 *
 * Überblick
 * Die Einheit options_t3 bildet den dritten und letzten Teil des ursprünglichen Moduls options.cpp. Sie enthält
 * die Zeichenroutine für anklickbare Schaltflächen sowie die Funktionen zum Sichern und Zeichnen des farbigen
 * Auswahlrahmens um das aktuell fokussierte Optionsfeld.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 2/3 gleich (suche.py 25.10.2026, Basis options_t3_P1.CPP)
// options.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D7430-0x0D9CB0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_012700(int p1, int p2);                           // reg eax edx stapel 0
int f_012870(int p1, int p2);                           // reg eax edx stapel 0
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_02de20(int p1, int p2);                           // reg eax edx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_050580();                       // nicht in clobber.tsv
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0bd350(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bf8e0();                                         // reg - stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3530(int p1);                                   // reg eax stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d4248(int p1, int p2);                           // reg eax edx stapel 0
int f_0d451f(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4880();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0de800(int p1);                                   // reg eax stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0f0130(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10a8b0(int p1);                                   // reg eax stapel 0
int f_10a940(int p1);                                   // reg eax stapel 0
int f_10a980(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_10aad0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_10ac80(int p1);                                   // reg eax stapel 0
int f_10ae20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
           // reg eax stapel 0
                   // reg eax ebx stapel 0
                                   // reg eax stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a20(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_146ae4(int p1, int p2);                           // reg eax edx stapel 0
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_147688(int p1, int p2);                           // reg eax edx stapel 0
int f_147746(int p1, int p2);                           // reg eax edx stapel 0
int f_147aad(int p1);                                   // reg eax stapel 0
int f_147b97(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147c02(int p1, int p2);                           // reg eax edx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a5ac0;                    // 0x1A5AC0
extern int d_1a5ac8;                    // 0x1A5AC8
extern int d_1a5af4;                    // 0x1A5AF4
extern int d_1a5af6;                    // 0x1A5AF6
extern signed char d_1a5af8;
extern short d_1a5afa;
extern int d_1a5afc;                    // 0x1A5AFC
extern int d_1a5b00;                    // 0x1A5B00
extern char d_1a5b6f;                   // 0x1A5B6F (oeffentliche Marke; Tabelle beginnt 3 Bytes dahinter bei 0x1A5B72)
extern short d_1a5b78;                  // 0x1A5B78
extern short d_1a5b88;                  // 0x1A5B88
extern short d_1a5b8a;                  // 0x1A5B8A
extern int d_1a5b8c;                    // 0x1A5B8C
extern int d_1a5b8d;                    // 0x1A5B8D
extern int d_1a5b8e;                    // 0x1A5B8E
extern int d_1a5b96;                    // 0x1A5B96
extern int d_1a6218;                    // 0x1A6218
extern int d_1a621c;                    // 0x1A621C
extern int d_1a965c;                    // 0x1A965C
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd766;                    // 0x1BD766
extern int d_1bd90c;                    // 0x1BD90C
extern int d_1bd910;                    // 0x1BD910
extern int d_1bdbd4;                    // 0x1BDBD4
extern int d_1bf4bc;                    // 0x1BF4BC
extern int d_1bf4be;                    // 0x1BF4BE
extern int d_1bf4ef;                    // 0x1BF4EF
extern int d_1bf500;                    // 0x1BF500
extern int d_1bf510;                    // 0x1BF510
extern int d_1bf514;                    // 0x1BF514
extern volatile short d_1bf51c;
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1bfac8;                    // 0x1BFAC8
extern int d_1bfaca;                    // 0x1BFACA
extern short d_1bfacc;
extern int d_1bfad0;                    // 0x1BFAD0
extern int d_1bfad4;                    // 0x1BFAD4
extern int d_1bfad6;                    // 0x1BFAD6
extern int d_1bfad8;                    // 0x1BFAD8
extern int d_1bfadc;                    // 0x1BFADC
extern int d_1bfadd;                    // 0x1BFADD
extern int d_1bfae0;                    // 0x1BFAE0
extern int d_1bfae1;                    // 0x1BFAE1
extern int d_1bfae4;                    // 0x1BFAE4
extern int d_1bfae5;                    // 0x1BFAE5
extern int d_1bfae8;                    // 0x1BFAE8
extern int d_1bfae9;                    // 0x1BFAE9
extern int d_1bfaec;                    // 0x1BFAEC
extern int d_1bfaed;                    // 0x1BFAED
extern int d_1bfaf0;                    // 0x1BFAF0
extern int d_1bfaf1;                    // 0x1BFAF1
extern int d_1bfaf4;                    // 0x1BFAF4
extern int d_1bfaf5;                    // 0x1BFAF5
extern int d_1bfaf8;                    // 0x1BFAF8
extern int d_1bfaf9;                    // 0x1BFAF9
extern int d_1bfafc;                    // 0x1BFAFC
extern int d_1bfafd;                    // 0x1BFAFD
extern int d_1bfb00;                    // 0x1BFB00
extern int d_1bfb01;                    // 0x1BFB01
extern int d_1bfb04;                    // 0x1BFB04
extern int d_1bfb05;                    // 0x1BFB05
extern int d_1bfb08;                    // 0x1BFB08
extern int d_1bfb09;                    // 0x1BFB09
extern int d_1bfb0c;                    // 0x1BFB0C
extern int d_1bfb0d;                    // 0x1BFB0D
extern int d_1bfb10;                    // 0x1BFB10
extern int d_1bfb11;                    // 0x1BFB11
extern int d_1bfb14;                    // 0x1BFB14
extern int d_1bfb15;                    // 0x1BFB15
extern int d_1bfb18;                    // 0x1BFB18
extern int d_1bfb19;                    // 0x1BFB19
extern int d_1bfb1c;                    // 0x1BFB1C
extern int d_1bfb1d;                    // 0x1BFB1D
extern int d_1bfb20;                    // 0x1BFB20
extern int d_1bfb21;                    // 0x1BFB21
extern int d_1bfb24;                    // 0x1BFB24
extern int d_1bfb25;                    // 0x1BFB25
extern int d_1bfb28;                    // 0x1BFB28
extern int d_1bfb29;                    // 0x1BFB29
extern int d_1bfb2c;                    // 0x1BFB2C
extern int d_1bfb2d;                    // 0x1BFB2D
extern int d_1bfb34;                    // 0x1BFB34
extern short d_1bfb38;                  // 0x1BFB38
extern short d_1bfb3e;
extern short d_1bfb40;
extern short d_1bfb4c;
extern short d_1bfb4e;                  // 0x1BFB4E
extern short d_1bfb54;
extern int d_1bfb64;                    // 0x1BFB64
extern int d_1bfb66;                    // 0x1BFB66
extern int d_1bfb68;                    // 0x1BFB68
extern int d_1bfb6a;                    // 0x1BFB6A
extern int d_1bfb6c;                    // 0x1BFB6C
extern int d_1bfda8;                    // 0x1BFDA8
extern int d_1bfdac;                    // 0x1BFDAC
extern int d_1bfdb0;                    // 0x1BFDB0
extern int d_1bfdb4;                    // 0x1BFDB4
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0c4c;                    // 0x1C0C4C
                    // 0x1C2098
extern int d_1c2198;                    // 0x1C2198
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern int d_1c3908;                    // 0x1C3908
extern const char d_1a5acc[];           // Text 0x1A5ACC
extern const char d_1b8284[];           // Text 0x1B8284
extern const char d_1b8291[];           // Text 0x1B8291
// --- eigene Funktionen (26), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_0d9250(int p1, short *p2, short p3);

//@ f_0d99d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet eine Schaltfläche des Optionsmenüs (bei p4 == 0 zunächst im eingedrückten Zustand samt
 *   Beschriftung und Klickgeräusch 7, anschließend im normalen ungedrückten Zustand) auf den Bildschirm.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1), der Zeiger auf den
 *   Optionsfeld-Eintrag (p2), der Feldindex (p3) sowie ein Flag zum Überspringen der Druck-Animation (p4).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d99d0(int p1, short *p2, short p3, int p4)
{
    volatile int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; }
    if (p4 == 0) {
        ((RivaRasterImage*)(*(int *)(p1 + 0xb7 + ((signed char *)p2)[4] * 4)))->f_0fae30((void *)( d_1a34e0), p2[0], p2[1], 1);
        f_0d9250(p1, p2, p3);
        f_0d4800(7);
    }
    ((RivaRasterImage*)(*(int *)(p1 + 0xa3 + ((signed char *)p2)[4] * 4)))->f_0fae30((void *)( d_1a34e0), p2[0], p2[1], 1);
    f_0d9250(p1, p2, p3);
    if (fl == 1) f_0d26e0();
}
//@ f_0d9a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Stellt den unter dem bisherigen Auswahlrahmen gesicherten Bildschirmhintergrund (*(p1 + 0x111)) an
 *   der Position des zuletzt markierten Optionsfelds (d_1a5afa) wieder her und gibt den Hintergrundpuffer frei.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9a80(int p1)
{
    volatile int fl;
    short *e;
    d_1bf51c = 0;
    if (*(int *)(p1 + 0x111) != 0) {
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; }
        e = (short *)((char *)&d_1a5b88 + d_1a5afa * 0x2b);
        ((RivaRasterImage*)(*(int *)(p1 + 0x111)))->f_0fade0((void *)( d_1a34e0), e[0], e[1]);
        { int q = *(int *)(p1 + 0x111); if (q) delete (char *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))); }
        *(int *)(p1 + 0x111) = 0;
        if (fl == 1) f_0d26e0();
    }
    d_1bf51c = 1;
}
//@ f_0d9b20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Versetzt den Auswahlrahmen im Optionsmenü auf das neu fokussierte Optionsfeld (d_1bfacc): stellt
 *   den alten Hintergrund an d_1a5afa wieder her, bestimmt Breite und Höhe des neuen Steuerelements, sichert
 *   dessen Bildschirmbereich in *(p1 + 0x111) und zeichnet mit f_1481a0 ein farbiges Auswahlrechteck (d_1a5af8).
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d9b20(int p1)
{
    volatile int fl;
    short *e;
    short s2, s1;
    int o;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; }
    d_1bf51c = 0;
    if (*(int *)(p1 + 0x111) != 0) {
        short *a = (short *)((char *)&d_1a5b88 + d_1a5afa * 0x2b);
        ((RivaRasterImage*)(*(int *)(p1 + 0x111)))->f_0fade0((void *)( d_1a34e0), a[0], a[1]);
        { int q = *(int *)(p1 + 0x111); if (q) delete (char *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0))); }
    }
    e = (short *)((char *)&d_1a5b88 + *(volatile short *)&d_1bfacc * 0x2b);
    {
    int k = ((signed char *)e)[4];
    if (k < 3) {
        s1 = *(short *)((char *)&d_1bfb38 + k * 2);
        s2 = *(short *)((char *)&d_1bfb4e + k * 2);
    } else if (k == 3) {
        s1 = d_1bfb3e + d_1bfb4c + d_1bfb40 + 2;
        s2 = d_1bfb54;
    } else {
        s1 = *(short *)(&d_1a5b6f + 3 + k * 2);
        s2 = *(short *)((char *)&d_1a5b78 + k * 2);
    }
    }
    o = (int)operator new(9, mark(d_1a5acc, 0x571));
    { int t = o ? ((int)(((RivaRasterImage*)(o))->f_0fac80( s1, s2))) : o; *(int *)(p1 + 0x111) = t; }
    ((RivaRasterImage*)(*(int *)(p1 + 0x111)))->f_0fafb0((void *)( d_1a34e0), e[0], e[1]);
    f_1481a0((int)&d_1bdbd4, d_1a34e0, e[0], e[1], s1, s2, d_1a5af8);
    d_1a5afa = d_1bfacc;
    d_1bf51c = 1;
    if (fl == 1) f_0d26e0();
}
