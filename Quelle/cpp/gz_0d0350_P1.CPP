/* === Beschreibung (Katalog) ===
 * Einheit gz_0d0350
 *
 * Diese Einheit setzt die Monster-Methoden fort und enthält die Namensbeugung, Grafik- und Typabfragen für
 * Monsterklassen, die Schadens-, Treffer-, Parade- und Zauberprobenberechnung für Monster im Kampf (f_0d07e0 bis
 * f_0d1390) sowie den Konstruktor des Mosaik-Rätselobjekts (f_0d13b0, f_0d1430).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 53/56 gleich (suche.py 26.10.2026, Basis gz_0d0350_P1.CPP)
// gz_0d0350.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D0350-0x0D1440
#include <string.h>
extern "C" unsigned long _lrotr(unsigned long, unsigned int);
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);          // reg eax edx ebx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_040980(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_043e40(int p1, int p2);                           // reg eax edx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
char f_0729c0(int p1);                                   // reg eax stapel 0
int f_07ea60(int p1, int p2);                           // reg eax edx stapel 0
int f_07eb00(int p1, int p2);                           // reg eax edx stapel 0
int f_0bd360(int p1);                                   // reg eax stapel 0
int f_0bf730(int p1, int p2, int p_h);                           // reg eax edx stapel 0
unsigned char f_0cf930(int p1);                                   // reg eax stapel 0
signed char f_0cf950(int p1);                                   // reg eax stapel 0
int f_0cf9b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0cfb30(int p1);                                   // reg eax stapel 0
short f_0cfb50(int p1);                                   // reg eax stapel 0
int f_0cfb70(int p1);                                   // reg eax stapel 0
char f_0cfc10(int p1);                                   // reg eax stapel 0
char f_0cfc50(int p1);                                   // reg eax stapel 0
char f_0cfd70(int p1);                                   // reg eax stapel 0
char f_0cfda0(int p1);                                   // reg eax stapel 0
char f_0cfdc0(int p1);                                   // reg eax stapel 0
int f_0cfdd0(int p1, int p2);                           // reg eax edx stapel 0
char f_0cfdf0(int p1);                                   // reg eax stapel 0
char f_0cfe30(int p1);                                   // reg eax stapel 0
char f_0cfe60(int p1);                                   // reg eax stapel 0
char f_0cfec0(int p1);                                   // reg eax stapel 0
char f_0cfef0(int p1);                                   // reg eax stapel 0
int f_0cff90(int p1, int p2);                           // reg eax edx stapel 0
int f_0cffc0(int p1, int p2);                           // reg eax edx stapel 0
char f_0cffe0(int p1);                                   // reg eax stapel 0
short f_0d00e0(int p1);                                   // reg eax stapel 0
int f_0d00f0(int p1, int p2);                           // reg eax edx stapel 0
short f_0d0100(int p1);                                   // reg eax stapel 0
short f_0d0120(int p1);                                   // reg eax stapel 0
int f_0d0130(int p1, int p2);                           // reg eax edx stapel 0
short f_0d0140(int p1);                                   // reg eax stapel 0
short f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
char f_0d54c0(int p1);                                   // reg eax stapel 0
short f_0de4d0(int p1);                                   // reg eax stapel 0
short f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_1493c0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a27b0;                    // 0x1A27B0
extern int d_1a27d0;                    // 0x1A27D0
extern int d_1a2804;                    // 0x1A2804
struct S5EF { char b[0x5ef]; };
extern struct S5EF *d_1bc8f0;                    // 0x1BC8F0
extern short d_1bd920;                    // 0x1BD920
extern char d_1bd928;                    // 0x1BD928
extern int d_1bd934;                    // 0x1BD934
extern char *d_1bd940;                  // 0x1BD940
extern unsigned short d_1bfaec;                    // 0x1BFAEC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c040c;                    // 0x1C040C
extern int d_1c11e4;                    // 0x1C11E4
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
struct S73 { char b[0x73]; };
extern struct S73 *d_1c2ed4;                    // 0x1C2ED4
// --- versteckte Funktionen / Daten ---
short f_0ce980(int p1, int p2);
signed char f_0cfd00(int p1);
short f_0cfa50(int p1);
int f_0ce9d0(void *p1, int p2);
int f_0ceb00(void *p1, int p2);
int f_0ce9e0(void *p1, int p2);
int f_0e93f0(void *p1, const char *p2, int p3);
signed char f_0cfd40(int p1);
char f_0cfa70(int p1);

extern signed char d_1c11d0;
extern int d_1c040e;
extern char d_1c38b0[];
extern const char d_1c21b4[];
struct E { char a0, a1, a2; signed char b3, b4, b5; char b6; char pad[5]; };
extern struct E d_1a57e8[];
signed char f_0d11e0(int p1);
inline int EQ(int a, int b) { return a == b; }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0d0350
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode extrahiert aus der mit Punkten ('.') getrennten Namenszeichenkette bei Offset +0x49 der
 *   Monsterstruktur p1 den Artikel/Vorspann sowie die passende Singular- oder Plural- bzw. Kasusendung (p3 > 1
 *   für Plural, p4 == 3 für Akkusativ/Dativ) und setzt den fertigen Monsternamen in p2 zusammen.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur, der Ausgabepuffer p2, die Anzahl p3 (1 für
 *   Singular, > 1 für Plural) sowie der grammatische Fall p4.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0350(int p1, char *p2, short p3, int p4)
{
    signed char *s = (signed char *)(p1 + 0x49);
    int c;
    signed char b;
    char *d = p2;
    char * m;
    do {
        b = *s++;
        d++;
        c = b;
        d[-1] = b;
    } while (c != 0 && (char)b != '.');
    if (p3 > 1) {
        do {
            b = *s++;
            c = b;
        } while (c != 0 && (char)b != '.');
    }
    d--;
    m = d;
    do {
        b = *s++;
        d++;
        c = b;
        d[-1] = b;
    } while (c && (char)b != '.');
    if ((c = (short)p4) == 3 && (c = p3) <= 1) {
        do {
            b = *s++;
            c = b;
        } while (c != 0 && (char)b != '.');
        c = *s;
        if (c) {
            d = m;
            do {
                b = *s++;
                d++;
                c = b;
                d[-1] = b;
            } while (c != 0 && (char)b != '.');
        }
    }
    d--;
    *d = 0;
}
//@ f_0d03f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode gibt die Adresse des Namensfeldes bei Offset +0x49 der Monsterstruktur p1 zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zeiger p1 + 0x49 auf die Namenszeichenkette.
 === Ende Beschreibung === */
int f_0d03f0(int p1)
{
    return p1 + 0x49;
}
//@ f_0d0400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lädt das zum Monstertyp f_0cf930(p1) - 0x14 gehörende Monsterbild aus dem Grafikarchiv
 *   0x10005 (d_1c2be0) über f_04feb0 in den Zielpuffer p2.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Zielpuffer p2 für die Bilddaten.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0400(int p1, int p2)
{
    char loc[4];
    f_04feb0((int)&d_1c2be0, 0x10005, p2, 0, (short)(f_0cf930(p1) - 0x14), 0, (int)loc, (int)loc, 0x140);
}
//@ f_0d0440
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt anhand des Typbytes *(char *)(p1 + 1), ob das Monster zu den Typen 0x19
 *   oder 0x3f gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Typ 0x19 oder 0x3f, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0440(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x19 || c == 0x3f) return 1;
    return 0;
}
//@ f_0d0460
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x1b (*(char *)(p1 + 1) == 0x1b) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0460(int p1)
{
    return *(char *)(p1 + 1) == 0x1b;
}
//@ f_0d0480
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x1f (*(char *)(p1 + 1) == 0x1f) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0480(int p1)
{
    return *(char *)(p1 + 1) == 0x1f;
}
//@ f_0d04a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x28 (*(char *)(p1 + 1) == 0x28, giftiges bzw.
 *   krankheitsübertragendes Wesen) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d04a0(int p1)
{
    return *(char *)(p1 + 1) == 0x28;
}
//@ f_0d04c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x15 (*(char *)(p1 + 1) == 0x15) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d04c0(int p1)
{
    return *(char *)(p1 + 1) == 0x15;
}
//@ f_0d04e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den Typen 0x17, 0x29 oder 0x54 gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei einem dieser drei Typen, andernfalls 0.
 === Ende Beschreibung === */
int f_0d04e0(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x17 || c == 0x29 || c == 0x54) return 1;
    return 0;
}
//@ f_0d0500
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den Typen 0x24 oder 0x18 gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Typ 0x24 oder 0x18, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0500(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x24 || c == 0x18) return 1;
    return 0;
}
//@ f_0d0520
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den Typen 0x25, 0x35, 0x36 oder 0x23 gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei einem dieser vier Typen, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0520(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x25 || c == 0x35 || c == 0x36 || c == 0x23) return 1;
    return 0;
}
//@ f_0d0550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x2a (*(char *)(p1 + 1) == 0x2a) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0550(int p1)
{
    return *(char *)(p1 + 1) == 0x2a;
}
//@ f_0d0570
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x29 (*(char *)(p1 + 1) == 0x29) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0570(int p1)
{
    return *(char *)(p1 + 1) == 0x29;
}
//@ f_0d0590
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x1c (*(char *)(p1 + 1) == 0x1c) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0590(int p1)
{
    return *(char *)(p1 + 1) == 0x1c;
}
//@ f_0d05b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x42 (*(char *)(p1 + 1) == 0x42) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d05b0(int p1)
{
    return *(char *)(p1 + 1) == 0x42;
}
//@ f_0d05d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x1d (*(char *)(p1 + 1) == 0x1d) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d05d0(int p1)
{
    return *(char *)(p1 + 1) == 0x1d;
}
//@ f_0d05f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x46 (*(char *)(p1 + 1) == 0x46) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d05f0(int p1)
{
    return *(char *)(p1 + 1) == 0x46;
}
//@ f_0d0610
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster gleichzeitig den Typ 0x33 (p1[1] == 0x33) und die
 *   Unterkennung 0x7a (p1[0] == 0x7a) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn beide Bedingungen erfüllt sind, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0610(char *p1)
{
    if (p1[1] == 0x33 && p1[0] == 0x7a) return 1;
    return 0;
}
//@ f_0d0640
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den Typen 0x22 oder 0x33 gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Typ 0x22 oder 0x33, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0640(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x22 || c == 0x33) return 1;
    return 0;
}
//@ f_0d0660
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x2b (*(char *)(p1 + 1) == 0x2b,
 *   Elementar-/Feuerwesen) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0660(int p1)
{
    return *(char *)(p1 + 1) == 0x2b;
}
//@ f_0d0680
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x48 (*(char *)(p1 + 1) == 0x48) besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0680(int p1)
{
    return *(char *)(p1 + 1) == 0x48;
}
//@ f_0d06a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den Typen 0x2b oder 0x48 gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Typ 0x2b oder 0x48, andernfalls 0.
 === Ende Beschreibung === */
int f_0d06a0(int p1)
{
    char c = *(char *)(p1 + 1);
    if (c == 0x2b || c == 0x48) return 1;
    return 0;
}
//@ f_0d06c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster zu den großen Spezialtypen 0x52 ('R'), 0x53 ('S') oder
 *   0x54 ('T') gehört.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei einem dieser drei Typen, andernfalls 0.
 === Ende Beschreibung === */
int f_0d06c0(int p1)
{
    unsigned c = *(unsigned char *)(p1 + 1);
    if (c == 0x52 || c == 0x53 || c == 0x54) return 1;
    return 0;
}
//@ f_0d06f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x52 ('R') besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d06f0(int p1)
{
    return *(char *)(p1 + 1) == 0x52;
}
// f_0d06e0 (0x0D06E0) steht absichtlich HIER: Watcom legt eine "return 0"-Funktion auf das gleiche Ende der
// vorletzten passenden Funktion davor (hier f_0d06c0) - Adresse im EXE stimmt (Blind831, 30.10.)
int f_0d06e0(void)
{
    return 0;
}
//@ f_0d0710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob das Monster den Typ 0x53 ('S') besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0710(int p1)
{
    return *(char *)(p1 + 1) == 0x53;
}
//@ f_0d0730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion testet anhand der Tabelle d_1a27b0, ob das Monster p1 als humanoider bzw.
 *   bestimmter Kampftyp gilt (*(char *)(p1 + 1) < 0x14 oder in d_1a27b0 enthalten).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Zugehörigkeit zur Gruppe, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0730(int p1)
{
    if (f_1493c0(*(signed char *)(p1 + 1), (int)&d_1a27b0) == -1 && *(char *)(p1 + 1) >= 0x14) return 0;
    return 1;
}
//@ f_0d0760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion stellt fest, ob im Spezialkampf d_1bd920 == 3 oder 4 der übergebene Zeiger p1 auf
 *   den ersten Eintrag des Monster-Arrays d_1c2ed4 zeigt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn es sich um den Hauptgegner im Spezialkampf handelt, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0760(int p1)
{
    if ((d_1bd920 == 3 || d_1bd920 == 4) && p1 == (int)d_1c2ed4) return 1;
    return 0;
}
//@ f_0d0790
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion schlägt in der Tabelle d_1a2804 nach, ob der Monstertyp *(signed char *)(p1 + 1)
 *   darin verzeichnet ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Monstertyp in d_1a2804 enthalten ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0790(int p1)
{
    return f_1493c0(*(signed char *)(p1 + 1), (int)&d_1a2804) != -1;
}
//@ f_0d07b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion schlägt in der Tabelle d_1a27d0 nach, ob der Monstertyp *(signed char *)(p1 + 1)
 *   darin verzeichnet ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Monstertyp in d_1a27d0 enthalten ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d07b0(int p1)
{
    return f_1493c0(*(signed char *)(p1 + 1), (int)&d_1a27d0) != -1;
}
//@ f_0d07d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion gibt zurück, ob das Monster p1 laut f_0cfdc0(p1) tot bzw. kampfunfähig ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Monster tot ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d07d0(int p1)
{
    signed char c = f_0cfdc0(p1);
    return c != (signed char)0;
}
//@ f_0d07e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dekodiert eines der vier Schadenswürfel-Wörter der Monsterstruktur p1 (p2 = 0: +0x26,
 *   1: +0x28, 2: +0x40, 3: +0x44, kodiert als Anzahl << 12 | Würfeltyp << 8 | Bonus) und berechnet daraus den
 *   minimal möglichen Schaden (*p3) sowie den maximal möglichen Schaden (*p4).
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur, der Index p2 des Angriffs (0 bis 3) sowie
 *   die Ausgabezeiger p3 (Minimum) und p4 (Maximum).
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d07e0(int p1, int p2, short *p3, short *p4)
{
#pragma intrinsic(_lrotr)
    short cnt;
    int t;
    short saved;
    int step;
    short i;
    signed char lb;
    union { int full; short word; } value;
    value.full = p2;
    if (!value.word) value.word = *(short *)(p1 + 0x26);
    else if (value.word == 1) value.word = *(short *)(p1 + 0x28);
    else if (value.word == 2) value.word = *(short *)(p1 + 0x40);
    else value.word = *(short *)(p1 + 0x44);
    saved = value.word;
    cnt = (short)_lrotr(value.word & 0xf000, 12);
    value.word &= 0xf00;
    t = (short)_lrotr(value.word, 8);
    if (t == 1) step = 6;
    else if (t == 2) step = 0x14;
    else step = (t != 3) + 3;
    lb = (signed char)saved;
    *p4 = 0;
    *p3 = *p4;
    i = 0;
    if (cnt > (short)0) {
        do {
            *p3 = *p3 + 1;
            *p4 = *p4 + step;
            i++;
        } while (i < cnt);
    }
    *p3 = *p3 + lb;
    *p4 = *p4 + lb;
}
//@ f_0d08a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst die Zielkennung bei Offset +0x34 der Monsterstruktur p1 in einen Zeiger auf den
 *   anvisierten Helden im Helden-Array d_1bc8f0 (Index = Zielkennung - 1) auf.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die anvisierte Heldenstruktur oder 0, falls kein Ziel (0xff)
 *   gesetzt ist.
 === Ende Beschreibung === */
int f_0d08a0(int p1)
{
    if (*(char *)(p1 + 0x34) == 0xff) return 0;
    return (int)&d_1bc8f0[*(char *)(p1 + 0x34) - 1];
}
//@ f_0d08e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode trägt den Helden p2 über dessen Gruppenindex (f_0d54c0(p2) + 1) als aktuelles Ziel bei
 *   Offset +0x34 der Monsterstruktur p1 ein und markiert den Helden als angegriffen (f_043e40(p2, 1)), oder
 *   löscht das Ziel bei p2 == 0 (0xff).
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Zeiger p2 auf die
 *   Ziel-Heldenstruktur (oder 0).
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d08e0(int p1, int p2)
{
    if (p2 != 0) {
        *(char *)(p1 + 0x34) = f_0d54c0(p2) + 1;
        f_043e40(p2, 1);
        return;
    }
    *(char *)(p1 + 0x34) = 0xff;
}
//@ f_0d0910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode löst die Zielkennung bei Offset +0x34 der Monsterstruktur p1 in einen Zeiger auf das
 *   anvisierte Monster im Monster-Array d_1c2ed4 (Index = Zielkennung - 10) auf.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die Ziel-Monsterstruktur oder 0 bei 0xff.
 === Ende Beschreibung === */
int f_0d0910(int p1)
{
    if (*(char *)(p1 + 0x34) == 0xff) return 0;
    return (int)&d_1c2ed4[*(char *)(p1 + 0x34) - 10];
}
//@ f_0d0940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode trägt das Monster p2 über dessen Array-Index (f_0729c0(p2) + 10) als aktuelles Ziel bei
 *   Offset +0x34 der Monsterstruktur p1 ein oder setzt das Feld bei p2 == 0 auf 0xff.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Zeiger p2 auf das Zielmonster
 *   (oder 0).
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0940(int p1, int p2)
{
    if (p2 != 0) {
        *(char *)(p1 + 0x34) = f_0729c0(p2) + 10;
        return;
    }
    *(char *)(p1 + 0x34) = 0xff;
}
//@ f_0d0960
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode zieht dem Monster p1 unter Berücksichtigung von Kampfsonderregeln (d_1bd920 == 5,
 *   Schadensverdopplung d_1bd928, nichttödlicher Modus p3 == 2) insgesamt p2 Lebenspunkte bei Offset +0x1b ab
 *   und markiert das Monster beim Erreichen von <= 0 Lebenspunkten über f_0cfdd0(p1, 1) als tot.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur, der Schadenswert p2 sowie der
 *   Schadensmodus p3.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0960(int p1, short p2, short p3)
{
    if ((int)p2 < 0) p2 = 0;
    if (d_1bd920 == 5) {
        int kind = (unsigned char)*(char *)(p1 + 1);
        int matched = kind == 0x22 || kind == 0x33;
        if (matched == 1) {
            p2 = p2 - 5;
            if (p2 <= 0) p2 = 1;
            signed char flag = *(signed char *)&d_1bfaec;
            if (flag == 0) p2 = p2 + 5;
        }
    }
    if (d_1bd928) p2 = p2 * 2;
    if (p3 == 2 && p2 >= *(short *)(p1 + 0x1b)) p2 = *(short *)(p1 + 0x1b) - 1;
    *(short *)(p1 + 0x1b) -= p2;
    if (*(short *)(p1 + 0x1b) <= 0) {
        f_0cfdd0(p1, 1);
        f_0cffc0(p1, 0);
        *(short *)(p1 + 0x1b) = 0;
    }
    if (p3 == (short)0) f_0cff90(p1, 0);
}
//@ f_0d0a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode zieht einem lebenden Monster p1 p2 Astralpunkte bei Offset +0x1f ab (außer im
 *   Spezialkampf d_1bd920 == 5, wo Zauber keine Astralpunkte kosten) und begrenzt den Vorrat nach unten auf 0.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die abzuziehenden Astralpunkte p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0a20(int p1, short p2)
{
    if (!(f_0cfdc0(p1))) {
        if (d_1bd920 == 5) p2 = 0;
        if ((*(short *)(p1 + 0x1f) -= p2) < 0) *(short *)(p1 + 0x1f) = 0;
    }
}
//@ f_0d0a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode heilt ein lebendes Monster p1 um p2 Lebenspunkte bei Offset +0x1b, begrenzt auf das
 *   Maximum bei Offset +0x19.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die Heilmenge p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0a60(int p1, short p2)
{
    if (!f_0cfdc0(p1)) {
        *(short *)(p1 + 0x1b) = *(short *)(p1 + 0x1b) + p2;
        if (*(short *)(p1 + 0x1b) > *(short *)(p1 + 0x19))
            *(short *)(p1 + 0x1b) = *(short *)(p1 + 0x19);
    }
}

//@ f_0d0a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode regeneriert bei einem lebenden Monster p1 p2 Astralpunkte bei Offset +0x1f, begrenzt
 *   auf das Maximum bei Offset +0x1d.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie die hinzuzufügenden Astralpunkte p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d0a90(int p1, short p2)
{
    if (!f_0cfdc0(p1)) {
        *(short *)(p1 + 0x1f) = *(short *)(p1 + 0x1f) + p2;
        if (*(short *)(p1 + 0x1f) > *(short *)(p1 + 0x1d))
            *(short *)(p1 + 0x1f) = *(short *)(p1 + 0x1d);
    }
}
//@ f_0d0ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt zu einer Kampffeld-Figurenkennung p1 über das Kampfraster d_1bd934
 *   (f_07ea60/f_07eb00) den zugehörigen Eintrag im Monster-Array d_1c2ed4.
 * - Eingaben: Als Parameter wird die Figuren- oder Feldkennung p1 übergeben.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die gefundene Monsterstruktur in d_1c2ed4 oder 0, falls kein
 *   passendes Monster existiert.
 === Ende Beschreibung === */
short f_0d0ac0(signed char p1)
{
    unsigned char *p;
    char want;
    short i;
    p = (unsigned char *)f_07ea60(d_1bd934, (unsigned char)p1);
    if (p[0xd] > 0x14 && (signed char)p[0xd] != (signed char)0xff) {
        p = (unsigned char *)f_07eb00(d_1bd934, (unsigned char)(p[0xd] - 0x14));
        want = p[9];
    } else {
        want = p[9];
    }
    i = 0;
    do {
        int q = (int)&d_1c2ed4[i];
        if (f_0cfc50(q) == want) return q;
        i++;
    } while (i < (short)0x14);
    return 0;
}
//@ f_0d0b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion liefert anhand des Monstertyps *(unsigned char *)(p1 + 1) den Gift-Typcode für
 *   Fernkampftreffer (2 bei Typ 0x1d, 1 bei Typ 0x46, sonst 0).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Gift-Typcode (0, 1 oder 2).
 === Ende Beschreibung === */
int f_0d0b30(int p1)
{
    int p = p1;
    p1 ^= p;
    unsigned c = *(unsigned char *)(p + 1);
    int r = p1;
    if (EQ(c, 0x1d)) return 2;
    if (EQ(*(unsigned char *)(p + 1), 0x46)) r = 1;
    return r;
}
//@ f_0d0b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft bei einem Monster vom Typ 0x28 eine 10-%-Chance (f_1457e0(100) < 10) auf
 *   Krankheitsübertragung und gibt im Erfolgsfall den Krankheitscode 5 zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 5 bei ausgelöster Infektion, andernfalls 0.
 === Ende Beschreibung === */
int f_0d0b70(int p1)
{
    int r = 0;
    if (EQ(*(char *)(p1 + 1), 0x28)) {
        if (f_1457e0(100) < 10) r = 5;
    }
    return r;
}
//@ f_0d0bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet den Nahkampfschaden eines Monsters p1 gegen ein Ziel p2 (p3 == 0 für einen
 *   Helden, sonst Monster), würfelt den Waffenschaden (f_0cfb30 bzw. zu 50 % f_0cfb50) über f_0bd360 aus,
 *   berücksichtigt Rüstungsschutz, Feuerschutz (0x2b), Spezialrüstungen (0xc5, Schutzamulett 0xb6 mit 5 %
 *   Zerstörungschance 0x2000016e), Waffenimmunität (f_0cfc10) sowie den Schadensbonus f_0cfb70 und löst bei
 *   einem Treffer gegen einen Helden gegebenenfalls eine Krankheit (f_0d0b70 -> f_040980) aus.
 * - Eingaben: Übergeben werden der Zeiger p1 auf das angreifende Monster, der Zeiger p2 auf das Ziel (Held oder
 *   Monster) sowie das Zieltyp-Flag p3 (0 = Held, != 0 = Monster).
 * - Rückgabewert: Zurückgegeben wird der berechnete Netto-Schadenswert r.
 === Ende Beschreibung === */
#define NEI(x,v) (((x)!=(v))?1:0)
inline int IS193F(int x) { int r = 0; if (x == 0x19 || x == 0x3f) r = 1; return r; }
int f_036300_saved(int p1, int p2, int p3);
#pragma aux f_036300_saved "f_036300" parm [eax] [edx] [ebx] value [eax] modify exact [eax edx]
int f_0d0b70(int p1);
short f_0d0bb0(int p1, int p2, short p3)
{
    short a;
    short r;
    int m;
    a = f_0cfb30(p1);
    if ((short)f_0cfb50(p1) != (short)0 && f_1457e0(100) < 50) a = f_0cfb50(p1);
    a = f_0bd360((short)a);
    r = a;
    if (p3 == (short)0) {
        m = p2;
        if (!EQ(*(char *)(p1 + 1), 0x2b)) {
            r -= f_0423f0((struct hero *)(m));
        } else {
            if (f_0d4aa0(m, 0x11e) != -1) r /= (short)2;
            if (((char)(f_043270((struct hero *)(m))))) r /= (short)2;
        }
        if (f_042a60((struct hero *)(m), 10) == 0xc5) {
            if (EQ(*(char *)(p1 + 1), 0x1f) || IS193F(*(unsigned char *)(p1 + 1)))
                r -= 3;
        }
        {
            short w = 0;
            w = f_0d4aa0(m, 0xb6);
            if (w != -1) {
                if (EQ(*(char *)(p1 + 1), 0x1f) || IS193F(*(unsigned char *)(p1 + 1))) {
                    int q = f_1457e0(100);
                    r = 0;
                    if (q < 5) {
                        f_036300_saved(m, w, 1);
                        f_0bf730((int)&d_1c2c64, 0x2000016e, 1);
                    }
                }
            }
        }
        r += f_0cfb70(p1);
        if (((char)(f_0424e0((struct hero *)(m))))) r = 0;
        if (d_1c11e4 && NEI(f_1493c0(*(signed char *)(p1 + 1), (int)&d_1a2804), -1))
            r /= (short)2;
    } else {
        r += f_0cfb70(p1);
        r -= f_0cf950(p2);
        if (f_0cfe30(p2)) r = 0;
        if (f_0cfc10(p2) && !f_0cfc10(p1)) r = 0;
    }
    if (f_0cfda0(p1)) r /= (short)2;
    if (r > 0 && p3 == 0) {
        short v = f_0d0b70(p1);
        { int t_504 = (int)(v); if (t_504) f_040980(m, t_504); }
    }
    return r;
}
//@ f_0d0df0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt einen Fernkampfangriff des Monsters p1 auf den Helden p2 ab, reduziert den
 *   Munitionsvorrat (f_0d00e0 bzw. f_0d0120), würfelt Treffer- und Ausweichproben (1W20 <= Attacke und 1W20 >
 *   (MU+GE+KK)/4), berechnet den Schaden abzüglich Rüstungsschutz (f_0423f0) und vergiftet den Helden bei einem
 *   Treffer durch Monstertyp 0x1d oder 0x46 über f_040900.
 * - Eingaben: Übergeben werden der Zeiger p1 auf das schießende Monster sowie der Zeiger p2 auf den beschossenen
 *   Helden.
 * - Rückgabewert: Zurückgegeben wird der erzielte Fernkampfschaden r (0 bei Fehlschuss oder erfolgreichem
 *   Ausweichen).
 === Ende Beschreibung === */
short f_0d0df0(int p1, int p2)
{
    short r;
    if (f_0d00e0(p1) > 0) {
        f_0d00f0(p1, (short)(f_0d00e0(p1) - 1));
        r = 4;
    } else {
        f_0d0130(p1, (short)(f_0d0120(p1) - 1));
        r = 5;
    }
#if FIX_BUGS >= 1
    short w_at = f_1457e0(0x14);
    short ziel_at = f_0d11e0(p1);
    PLOG_KAMPF('F', (const char *)(p1 + 0x49), ziel_at, 0, w_at, (w_at <= ziel_at) ? 1 : 0);
    if (w_at <= ziel_at) {
        int sum = f_042a40((struct hero *)(p2), 0) + f_042a40((struct hero *)(p2), 5) + f_042a40((struct hero *)(p2), 4);
        short w_pa = f_1457e0(0x14);
        short ziel_pa = (short)(sum / 4);
        PLOG_KAMPF('P', (const char *)(p2 + 0x22), ziel_pa, 0, w_pa, (w_pa <= ziel_pa) ? 1 : 0);
        if (w_pa <= ziel_pa) {
            r = 0;
        } else {
            if ((r == 4)) r = f_0bd360(f_0d0100(p1)); else r = f_0bd360(f_0d0140(p1));
            r -= (short)f_0423f0((struct hero *)(p2));
            if (((char)(f_0424e0((struct hero *)(p2))))) r = 0;
        }
    } else {
        r = 0;
    }
#else
    if (f_1457e0(0x14) <= f_0d11e0(p1)) {
        int sum = f_042a40((struct hero *)(p2), 0) + f_042a40((struct hero *)(p2), 5) + f_042a40((struct hero *)(p2), 4);
        if ((short)f_1457e0(0x14) <= (short)(sum / 4)) {
            r = 0;
        } else {
            if ((r == 4)) r = f_0bd360(f_0d0100(p1)); else r = f_0bd360(f_0d0140(p1));
            r -= (short)f_0423f0((struct hero *)(p2));
            if (((char)(f_0424e0((struct hero *)(p2))))) r = 0;
        }
    } else {
        r = 0;
    }
#endif
    if (r > 0) {
        int p = p1;
        short v = 0;
        if (EQ(*(char *)(p + 1), 0x1d)) v = 2;
        else if (EQ(*(char *)(p + 1), 0x46)) v = 1;
        { int t_526 = (int)(v); if (t_526) f_040900(p2, t_526); }
    }
    return r;
}
//@ f_0d0f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion würfelt für ein Monster p1 eine 3W20-Talent-/Eigenschaftsprobe (f_145850(3, 20, p5))
 *   auf die drei Eigenschaften p2, p3 und p4 (f_0cf9b0) mit dem Modifikator p5.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur, die drei Eigenschaftsindizes p2, p3, p4
 *   sowie der Proben-Modifikator p5.
 * - Rückgabewert: Zurückgegeben wird die Differenz aus Eigenschaftssumme und Würfelergebnis plus 1 (> 0 bedeutet
 *   Erfolg).
 === Ende Beschreibung === */
short f_0d0f30(int p1, short p2, short p3, short p4, signed char p5)
{
    int t;
    t = f_145850(3, 0x14, p5);
    p2 = *(signed char *)(f_0cf9b0(p1, p2) + 1);
    p2 = (short)(p2 + *(signed char *)(f_0cf9b0(p1, p3) + 1));
    return (short)(p2 + *(signed char *)(f_0cf9b0(p1, p4) + 1) - t + 1);
}
//@ f_0d0f90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt für das Monster p1 die Zauberprobe für den Monster-Zauberspruch p2 (1 bis 16)
 *   mit dem Modifikator p3 durch, addiert bei magieresistenzabhängigen Sprüchen (e->b6 != 0) die Magieresistenz
 *   des Ziels (f_0cfa70 bzw. f_0423a0) zum Schwierigkeitsgrad und würfelt gegen die drei Sprucheigenschaften
 *   e->b3, e->b4, e->b5 aus d_1a57e8.
 * - Eingaben: Übergeben werden der Zeiger p1 auf das zaubernde Monster, die Spruch-ID p2 sowie der
 *   Basis-Modifikator p3.
 * - Rückgabewert: Zurückgegeben wird das Probenergebnis (> 0 bei Erfolg, <= 0 bei Fehlschlag, -1 bei globaler
 *   Magieblockade d_1c11d0).
 === Ende Beschreibung === */
short f_0d0f90(int p1, short p2, signed char p3)
{
    struct Actor905 {
        short stat(short id) { return *(signed char *)(f_0cf9b0((int)this,id)+1); }
    };
    struct Value905 { static int i(short x) {return x;} };
    struct E *e;
    short r = 0;
    short t;
    // haelt den Speichervergleich wie im Original
    if (*(volatile int *)&d_1c11d0) {
        r = -1;
    } else {
        e = &d_1a57e8[p2];
        if (e->b6) {
            if (f_0cfd40(p1) == 1) p3 += f_0cfa70(f_0d0910(p1));
            else p3 += ((char)(f_0423a0((struct hero *)(f_0d08a0(p1)))));
        }
{ S73 *q905=d_1c2ed4; d_1c2ed4=q905; } // haelt die Stapelplatz-Reihenfolge wie im Original
        if (Value905::i(p2) >= 1 && p2 <= (short)0x10) {
            short a,b,c,x;
            c=e->b5; b=e->b4; a=e->b3;
            t=f_145850(3,0x14,p3);
            Actor905 *actor=(Actor905*)p1;
            x=actor->stat(a);
            x+=actor->stat(b);
            r=x+actor->stat(c)-t+1;
        }
    }
    return r;
}
//@ f_0d10c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert den gesamten Zaubervorgang eines Monsters p1 im Kampf: Sie liest den gewählten
 *   Zauber f_0cfd00(p1), prüft den Astralpunktevorrat (f_0ce980), legt die Zauberprobe f_0d0f90 ab, zieht bei
 *   Misslingen halbe Astralpunktekosten ab (0x170000ef) und ruft bei Gelingen den Spruch-Dispatcher f_0ceb00
 *   auf.
 * - Eingaben: Übergeben werden der Zeiger p1 auf das zaubernde Monster sowie der Proben-Modifikator p2.
 * - Rückgabewert: Zurückgegeben wird 1 bei erfolgreichem Zauber, 0 bei keinem/abgebrochenem Zauber oder -1 bei
 *   Fehlschlag bzw. Astralpunktemangel.
 === Ende Beschreibung === */
short f_0d10c0(int p1, short p2)
{
    char obj[28];
    short s;
    short r;
    int n;
    short v;
    signed char c;
    memset(&d_1c040c, 0, 0x14);
    c = f_0cfd00(p1);
    s = c;
    r = 0;
    if (c > 0) {
        n = ((int (*)(int, int))f_0ce980)(s, 0);
        if ((short)n > f_0cfa50(p1)) {
            r = -1;
            d_1c040e = 1;
        }
        if (r != -1) {
            if (f_0d0f90(p1, s, (signed char)p2) <= 0) {
                n = ((int (*)(int, int))f_0ce980)(s, 1);
                int q = p1;
                if (!f_0cfdc0(p1)) {
                    if (d_1bd920 == 5) n = 0;
                    if ((*(short *)(q + 0x1f) -= n) < 0) *(short *)(q + 0x1f) = 0;
                }
                f_0e93f0(d_1c38b0, d_1c21b4, 0x170000ef);
            } else {
                f_0ce9d0(obj, p1);
                r = f_0ceb00(obj, s);
                f_0ce9e0(obj, 0);
            }
        }
    }
    return r;
}
//@ f_0d11c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion ermittelt anhand des ersten Fernkampfwaffen-Worts f_0d0100(p1), ob das Monster
 *   die erste (4) oder mangels erster Waffe die zweite Fernkampfwaffe (5) verwendet.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 4, wenn f_0d0100(p1) > 0 ist, andernfalls 5.
 === Ende Beschreibung === */
short f_0d11c0(int p1)
{
    short v = f_0d0100(p1);
    unsigned short t = (v <= 0);
    return t + 4;
}
//@ f_0d11e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet den effektiven Attackewert des Monsters p1 unter Berücksichtigung des
 *   Schwierigkeitsgrads (f_0de4d0 == -5 gibt -4), temporärer Abzüge (f_0cfd70, f_0cfec0, f_0cffe0) sowie
 *   kampfunfähig machender Zustände (f_0cfe30, f_0cfe60, f_0cfef0 setzen den Wert auf 0).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der effektive Attackewert als vorzeichenbehaftetes Byte.
 === Ende Beschreibung === */
signed char f_0d11e0(int p1)
{
    short s;
    signed char c = *(signed char *)(p1 + 0x24);
    s = f_0de4d0(d_1c0004);
    if (s == (short)-5) c = c - 4;
    if (f_0cfd70(p1)) c = c - 6;
    if (f_0cfec0(p1)) c = c - 2;
    else if (f_0cffe0(p1)) c = c - 5;
    if (!f_0cfe30(p1) && !f_0cfe60(p1) && !f_0cfef0(p1)) return c;
    return 0;
}
//@ f_0d1250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet den effektiven Paradewert des Monsters p1 aus dem Basiswert bei Offset +0x25
 *   abzüglich Schwierigkeitsgrad- und Zustandsmodifikatoren (wobei Lähmung, Versteinerung oder Schlaf den
 *   Paradewert auf 0 setzen).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der effektive Paradewert (mindestens 0).
 === Ende Beschreibung === */
signed char f_0d1250(int p1)
{
    short s;
    signed char c = *(signed char *)(p1 + 0x25);
    s = f_0de4d0(d_1c0004);
    if (s == (short)-5) c = c - 4;
    if (f_0cfd70(p1)) c = c - 6;
    if (f_0cfec0(p1)) c = c - 2;
    else if (f_0cffe0(p1)) c = c - 5;
    if (f_0cfe30(p1) || f_0cfe60(p1) || f_0cfef0(p1) || f_0cfdf0(p1)) c = 0;
    if (c < 0) c = 0;
    return c;
}
//@ f_0d12e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt anhand der Animations-/Grafiktabelle d_1bd940, ob für ein getötetes
 *   Monster p1 (f_0cfdc0) eine Todesanimation bzw. Leichendarstellung (== 1) verfügbar ist.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Monster normal dargestellt werden kann, oder 0, wenn die
 *   Spezialbedingung nicht erfüllt ist.
 === Ende Beschreibung === */
int f_0d12e0(int p1)
{
    short ix;
    char c;
    unsigned char b;
    int r;
    b = f_0cf930(p1);
    r = 1;
    ix = b - 0x14;
    ix = ix * 4;
    c = f_0cfdc0(p1);
    if (c && *(short *)(d_1bd940 + 4 + (short)ix * 0x1a) != (short)1) r = 0;
    return r;
}
//@ f_0d1320
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt in der Tabelle d_1bd940, ob der Eintrag für den Monstertyp f_0cf930(p1)
 *   - 0x14 den Wert 3 besitzt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Monsterstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung mit 3, andernfalls 0.
 === Ende Beschreibung === */
int f_0d1320(int p1)
{
    int r = 0;
    short ix = f_0cf930(p1) - 0x14;
    ix *= 4;
    if (*(short *)(d_1bd940 + 4 + ix * 0x1a) == (short)3) r = 1;
    return r;
}
//@ f_0d1360
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion überschreibt für die großen Spezialmonster 'R' (0x52), 'S' (0x53) und 'T' (0x54) einen
 *   Animations- oder Phasenwert p2 mit festen Werten (2 für 'R', 8 für 'S' und 'T').
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Monsterstruktur sowie der Standardwert p2.
 * - Rückgabewert: Zurückgegeben wird der angepasste Wert (2, 8 oder unverändert p2).
 === Ende Beschreibung === */
int f_0d1360(int p1, int p2)
{
    switch (f_0cf930(p1)) {
    case 'R': return 2;
    case 'S': return 8;
    case 'T': return 8;
    }
    return p2;
}
int f_0d1390(int p1, int p2)
{
    switch (f_0cf930(p1)) {
    case 'R': return 12;
    case 'T': return 13;
    case 'S': return 17;
    }
    return p2;
}
//@ f_0d13b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert die Verwaltungsstruktur p1 für das Mosaik-Schieberätsel
 *   (mosaic.cpp), setzt alle Koordinaten-, Auswahl- und Statusfelder ab Offset +200 (+0xc8) auf 0, aktiviert das
 *   Neuzeichnen-Flag bei +0xda (= 1) und speichert die maximale Zuganzahl p2 bei Offset +0xde.
 * - Eingaben: Übergeben werden der this-Zeiger p1 der Mosaik-Struktur sowie das Zuglimit p2.
 * - Rückgabewert: Zurückgegeben wird der initialisierte Objektzeiger p1.
 === Ende Beschreibung === */
int f_0d13b0(int p1, short p2)
{
    *(short *)(p1 + 200) = 0;
    *(short *)(p1 + 0xca) = 0;
    *(short *)(p1 + 0xcc) = 0;
    *(short *)(p1 + 0xce) = 0;
    *(short *)(p1 + 0xd0) = 0;
    *(short *)(p1 + 0xd2) = 0;
    *(short *)(p1 + 0xd4) = 0;
    *(short *)(p1 + 0xd6) = 0;
    *(short *)(p1 + 0xd8) = 0;
    *(int *)(p1 + 0xda) = 1;
    *(int *)(p1 + 0xc4) = 0;
    *(short *)(p1 + 0xde) = p2;
    *(int *)(p1 + 0xc0) = *(int *)(p1 + 0xc4);
    return p1;
}
//@ f_0d1430
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist der leere Destruktor der Mosaik-Rätselstruktur ohne ausführbare Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1430(void)
{
}
