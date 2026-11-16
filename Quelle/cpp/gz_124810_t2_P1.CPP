/* === Beschreibung (Katalog) ===
 * Einheit gz_124810_t2 (0x124970 - 0x125400)
 *
 * Überblick
 * Diese Einheit bildet den abschließenden Teil von temple.cpp und enthält die Hilfsfunktionen für das Gebet um
 * ein göttliches Wunder, das Betreten des hinteren Tempelbereichs, das Verlassen eines Tempels in die jeweilige
 * Stadtkarte sowie die Einzelroutinen für die einmaligen Quest-Hinweise der sechs Tempel bei Mitführen des
 * Gegenstands 0x1a2.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// Astra650: Teil aus gz_124810, Originalbereich 124970 bis 125400 (exklusiv).
// gz_124810.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x124810-0x125400
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
int f_054050(int p1, int p2);                           // reg eax edx stapel 0
int f_054060(int p1);                                   // reg eax stapel 0
int f_054110(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0ea400();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
#pragma aux f_147323 modify [esp];
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern short d_1bee30;                    // 0x1BEE30
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c0001;                    // 0x1C0001
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c00a8;                    // 0x1C00A8
extern signed char d_1c0c30;                    // 0x1C0C30
extern signed char d_1c0c34;                    // 0x1C0C34
extern signed char d_1c0c38;                    // 0x1C0C38
extern signed char d_1c0c3c;                    // 0x1C0C3C
extern signed char d_1c0c40;                    // 0x1C0C40
extern signed char d_1c0c44;                    // 0x1C0C44
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870

#define EQ(x,v) (((x)==(v))?1:0)
typedef RivaTextContextData OB;
void f_124fa0(void);
void f_125060(void);
void f_125120(void);
void f_1251e0(void);
void f_1252a0(void);
void f_125350(void);
// --- eigene Funktionen ---

//@ f_124970
/* === Beschreibung (Katalog) ===
 * - Zweck: Ruft am zugeordneten Gottheits-Objekt (*(int *)(p1 + 0x62)) die Gebets- und Wunderfunktion (f_054060)
 *   auf.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tempel-Objekt.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_054060 zurück.
 === Ende Beschreibung === */
int f_124970(int p1) { return f_054060(*(int *)(p1 + 0x62)); }

//@ f_124980
/* === Beschreibung (Katalog) ===
 * - Zweck: Wechselt über die Schaltfläche 6 in den zum jeweiligen Tempel (*p1 == 6, 0x16-0x1a) gehörenden
 *   speziellen Kartenabschnitt auf Karte 2.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tempel-Objekt.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_124980(unsigned short *p1)
{
    short a = -1;
    short b = -1;
    switch ((unsigned short)*p1) {
    case 6: b = 5000; a = 2; break;
    case 0x16: b = 0x13fe; a = 2; break;
    case 0x17: b = 0x152a; a = 2; break;
    case 0x18: b = 0x157c; a = 2; break;
    case 0x19: b = 0x14cf; a = 2; break;
    case 0x1a: b = 0x1462; a = 2; break;
    }
    if (a != -1 && b != -1) f_0dd7f0(d_1c0004, a, b);
    return 1;
}

//@ f_124a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das Verlassen eines Tempels (*p1 == 6, 0x16-0x1a), führt im Tempel 0x19 falls noch nicht
 *   geschehen (d_1c00a8 == 0) zuvor die Geweihten-Begegnung aus und setzt die Heldengruppe anschließend vor den
 *   jeweiligen Tempeleingang auf der Stadtkarte (a = 0).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tempel-Objekt.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_124a20(unsigned short *p1)
{
    short a;
    short b;
    int r = 1;
    a = -1;
    b = a;
    switch ((unsigned short)*p1) {
    case 6: b = 0x13ec; a = 0; break;
    case 0x16: b = 0x1585; a = 0; break;
    case 0x17: b = 0x1533; a = 0; break;
    case 0x18: b = 0x14bd; a = 0; break;
    case 0x19: {
        struct Frame { OB ob16, ob19, ob6, ob17, ob1a, ob18; } frame;
        if (EQ(d_1c00a8, 0)) {
            unsigned short *q = p1;
            if (q[0] == 0x19 && EQ(d_1c00a8, 0)) {
                f_0ea400();
                f_09a400();
            }
            switch (q[0]) {
            case 6: {
                if (EQ(d_1c0c30, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob6, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob6.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x22000021);
                        f_0bf730((int)&d_1c2c64, 0x22000022);
                        f_0bf730((int)&d_1c2c64, 0x22000023);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c30 = 1;
                        f_1254a0((int)&frame.ob6, 0);
                    }
                }
                break;
            }
            case 0x16: {
                if (EQ(d_1c0c34, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob16, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob16.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x2200005d);
                        f_0bf730((int)&d_1c2c64, 0x2200005e);
                        f_0bf730((int)&d_1c2c64, 0x2200005f);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c34 = 1;
                        f_1254a0((int)&frame.ob16, 0);
                    }
                }
                break;
            }
            case 0x17: {
                if (EQ(d_1c0c38, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob17, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob17.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x22000060);
                        f_0bf730((int)&d_1c2c64, 0x22000061);
                        f_0bf730((int)&d_1c2c64, 0x22000062);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c38 = 1;
                        f_1254a0((int)&frame.ob17, 0);
                    }
                }
                break;
            }
            case 0x18: {
                if (EQ(d_1c0c3c, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob18, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob18.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x22000063);
                        f_0bf730((int)&d_1c2c64, 0x22000064);
                        f_0bf730((int)&d_1c2c64, 0x22000065);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c3c = 1;
                        f_1254a0((int)&frame.ob18, 0);
                    }
                }
                break;
            }
            case 0x1a: {
                if (EQ(d_1c0c44, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob1a, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob1a.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x22000068);
                        f_0bf730((int)&d_1c2c64, 0x22000069);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c44 = 1;
                        f_1254a0((int)&frame.ob1a, 0);
                    }
                }
                break;
            }
            case 0x19: {
                if (EQ(d_1c0c40, 0)) {
                    short s = f_0d54f0(d_1c0004, 0x1a2);
                    if (s != -1) {
                        f_125400((int)&frame.ob19, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                        *(int *)(frame.ob19.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                        f_0bf730((int)&d_1c2c64, 0x22000066);
                        f_0bf730((int)&d_1c2c64, 0x22000067);
                        f_0daaf0(d_1bfdb8, 6);
                        d_1c0c40 = 1;
                        f_1254a0((int)&frame.ob19, 0);
                    }
                }
                break;
            }
            }
            f_056a50(q[0x13] + 0x150007);
        }
        b = 0x13a3; a = 0; break;
    }
    case 0x1a: b = 0x146b; a = 0; break;
    }
    if (a != -1 && b != -1) f_0dd7f0(d_1c0004, a, b);
    return r;
}

//@ f_124fa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 6 einmalig (d_1c0c30) die dreiteilige Hinweismeldung (0x22000021 bis 0x22000023) zum
 *   Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124fa0(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c30, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x22000021);
            f_0bf730((int)&d_1c2c64, 0x22000022);
            f_0bf730((int)&d_1c2c64, 0x22000023);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c30 = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}

//@ f_125060
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 0x16 einmalig (d_1c0c34) die dreiteilige Hinweismeldung (0x2200005d bis 0x2200005f)
 *   zum Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125060(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c34, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x2200005d);
            f_0bf730((int)&d_1c2c64, 0x2200005e);
            f_0bf730((int)&d_1c2c64, 0x2200005f);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c34 = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}

//@ f_125120
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 0x17 einmalig (d_1c0c38) die dreiteilige Hinweismeldung (0x22000060 bis 0x22000062)
 *   zum Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125120(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c38, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x22000060);
            f_0bf730((int)&d_1c2c64, 0x22000061);
            f_0bf730((int)&d_1c2c64, 0x22000062);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c38 = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}

//@ f_1251e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 0x18 einmalig (d_1c0c3c) die dreiteilige Hinweismeldung (0x22000063 bis 0x22000065)
 *   zum Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1251e0(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c3c, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x22000063);
            f_0bf730((int)&d_1c2c64, 0x22000064);
            f_0bf730((int)&d_1c2c64, 0x22000065);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c3c = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}

//@ f_1252a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 0x19 einmalig (d_1c0c40) die zweiteilige Hinweismeldung (0x22000066, 0x22000067) zum
 *   Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1252a0(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c40, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x22000066);
            f_0bf730((int)&d_1c2c64, 0x22000067);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c40 = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}

//@ f_125350
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt im Tempel 0x1a einmalig (d_1c0c44) die zweiteilige Hinweismeldung (0x22000068, 0x22000069) zum
 *   Gegenstand 0x1a2 aus und schaltet die Schaltfläche 6 frei.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125350(void)
{
    OB ob;
    int s;
    if (EQ(d_1c0c44, 0)) {
        s = f_0d54f0(d_1c0004, 0x1a2);
        if (s != -1) {
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
            f_0bf730((int)&d_1c2c64, 0x22000068);
            f_0bf730((int)&d_1c2c64, 0x22000069);
            f_0daaf0(d_1bfdb8, 6);
            d_1c0c44 = 1;
            f_1254a0((int)&ob, 0);
        }
    }
}
