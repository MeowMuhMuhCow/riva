/* === Beschreibung (Katalog) ===
 * Einheit gz_124810_t1 (0x124810 - 0x124970)
 *
 * Überblick
 * Diese Einheit implementiert den Spenden-Dialog in den Tempeln von Riva (temple.cpp), über den die Heldengruppe
 * Geld in die Tempelkasse spenden kann, um das Wohlwollen der jeweiligen Gottheit zu erhöhen.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 28.10.2026, Basis gz_124810_t1_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra650: Teil aus gz_124810, Originalbereich 124810 bis 124970 (exklusiv).
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
int f_147323(int p1,int p2,unsigned short p3,unsigned short p4,int p5,short p6,unsigned short p7);// reg eax edx ebx ecx stapel 12
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

//@ f_124810
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet im Tempel den Zahlen-Eingabedialog für eine Geldspende (in Silberstücken, begrenzt durch das
 *   Gruppenvermögen geteilt durch 10 bzw. maximal 9999), zieht den gespendeten Betrag in Hellern (amount * 10)
 *   vom Gruppenvermögen ab, schreibt die Spende dem Gottheits-Konto (f_054050) gut, spielt das Münzgeräusch
 *   (0x1c0001) ab und gibt eine Dankesmeldung (0x1c000009) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tempel-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124810(int p1)
{
    register int amount;
    if (!(amount = f_0de7e0(d_1c0004))) {
        f_0bf730((int)&d_1c2c64, 0x20000010);
    } else {
        register int limit = amount / 10;
        int upper = limit;
        int snd491;
        OB ob;
        f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        if (limit > 9999) limit = 9999;
        if (upper > 100) upper = 100;
        f_040370((int)&d_1c27a8, amount);
        *(int *)(ob.addresses.numbers + 4) = f_054110(*(int *)(p1 + 0x62));
        *(int *)(ob.addresses.numbers + 8) = f_133fe0((int)&d_1c3498, (int)&d_1c27a8);
        amount = (short)f_0bf7b0((int)&d_1c2c64, 4, 0x1c000008, 0, (short)limit, (short)upper);
        if (amount > 0) {
            f_054050(*(int *)(p1 + 0x62), amount);
            f_0db8b0(d_1c0004, amount * 10);
            snd491=d_1a9820;
            f_147323((int)&d_1c2edc, 0x1c0001, 0x7fff, 0x8000, snd491, 0, 1);
            int diff491=(*(unsigned short *)(p1+0x2a) != d_1bee30);
            *(int *)(ob.addresses.numbers+4)=0x1c00000a+diff491;
            f_0bf730((int)&d_1c2c64, 0x1c000009);
        }
        f_1254a0((int)&ob, 0);
    }
}

