/* === Beschreibung (Katalog) ===
 * Einheit gz_0dc9a0_tb (0dcb60 - 0dcc10)
 *
 * Überblick
 * Die Einheit gz_0dc9a0_tb bildet den zweiten Abschnitt des Gruppenverwaltungs-Moduls (0x0dc9a0-0x0de600) und
 * enthält die drei Funktionen zur Vergabe und zum Abzug von Abenteuerpunkten (AP) für eine Heldengruppe.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// P3 25/32 gleich (suche.py 26.10.2026, Basis gz_0dc9a0_t1_P1.CPP)
// gz_0dc9a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DC9A0-0x0DE600
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0326d0(int p1, int p2);                           // reg eax edx stapel 0
short f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_033ce0(int p1);                                   // reg eax stapel 0
int f_0349b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_035260(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038c20(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
short f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_0407e0(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040e60(int p1, int p2);                           // reg eax edx stapel 0
int f_041000();                                         // reg - stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_043fd0(int p1, int p2);                           // reg eax stapel 0
int f_043ff0(int p1, int p2);                           // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045170(int p1, int p2);                           // reg eax edx stapel 0
int f_0451f0(int p1, int p2);
int f_045820(int p1, int p2);                           // reg eax edx stapel 0
int f_0458b0(int p1);                                   // reg eax stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_0459e0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0b0f40(int p1);                                   // reg eax stapel 0
int f_0bc3a0(int p1);
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf820();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0d6690(int p1);                                   // reg eax stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db900(int p1);                                   // reg eax stapel 0
short f_0dbfe0(int p1);                                   // reg eax stapel 0
int f_0dbfb0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dbff0(int p1);                                   // reg eax stapel 0
short f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
short f_0de820(int p1);                                   // reg eax stapel 0
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de850(int p1, int p2);                           // reg eax edx stapel 0
int f_0de860(int p1);                                   // reg eax stapel 0
int f_0de870(int p1, int p2);                           // reg eax edx stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0de890(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8a0(int p1);                                   // reg eax stapel 0
int f_0de8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8c0(int p1);                                   // reg eax stapel 0
int f_0de8d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8e0(int p1);                                   // reg eax stapel 0
int f_0de8f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de900(int p1);                                   // reg eax stapel 0
int f_0de910(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_0de9b0(int p1, int p2);                           // reg eax edx stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
short f_1457e0(int p1);                                   // reg eax stapel 0
int f_149728(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_1497d8(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_1511ec(int p1, int p2);                           // reg eax edx stapel 0
int f_15164c();                                         // reg - stapel 0
int f_155968(int p1);                                   // reg eax stapel 0
int f_1559e0();                                         // reg - stapel 0
int f_155bc8(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a80c4;
extern short d_1a9960;
extern int d_1b82bc;                    // 0x1B82BC
extern int d_1bc8f0;                    // 0x1BC8F0
extern short *d_1bd6c0;
extern short d_1be258;
extern char d_1bfab8;
extern char d_1bfabc;
extern char d_1bfac4;
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern char d_1c0028;
extern char d_1c00c4;
extern char d_1c01b8;
extern char d_1c01c8;
extern char d_1c01cc;
extern int d_1c01d4;                    // 0x1C01D4
extern char d_1c0214;
extern int d_1c0e60[];
extern int d_1c0e78;                    // 0x1C0E78
extern short d_1c2140;
extern short d_1c219c;
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c4;                    // 0x1C90C4
extern int d_1c90c8;                    // 0x1C90C8
extern int d_1c90cc;                    // 0x1C90CC
extern int d_1c90d0;                    // 0x1C90D0
extern int d_1c90d2;                    // 0x1C90D2
extern int d_1c90d4;                    // 0x1C90D4
// --- eigene Funktionen (54), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern short d_1a80c8;
extern int d_1c3498;
extern int d_1bf230;
int f_144cb6(int h, int buf, int n);
int f_144e8b(int h, int buf, int n);

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0dcb60  groesse 80 B, 32 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Teilt eine Gesamtsumme von p2 Abenteuerpunkten gleichmäßig durch die Anzahl der lebenden
 *   Gruppenmitglieder (f_0dbff0(p1)) und schreibt jedem Mitglied der Gruppe p1 seinen Anteil über f_040780 gut.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die zu verteilende Gesamtsumme an
 *   Abenteuerpunkten (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcb60(int p1, short p2)
{
    int p1_00;
    int sVar1;
    if (p2 < 0) goto ende;
    p2 /= f_0dbff0(p1);
    for (sVar1 = 0; (short)sVar1 <= 6; sVar1++) {
        p1_00 = ((int *)p1)[(short)sVar1];
        if (p1_00 != 0) {
            f_040780(p1_00, (int)p2);
        }
    }
ende:
    return;
}
//@ f_0dcbb0  groesse 96 B, 18 Bef, reg eax edx, stapel ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schreibt jedem Mitglied der Gruppe p1 (sofern p2 >= 0 ist) jeweils den vollen Betrag von p2
 *   Abenteuerpunkten über f_040780 gut.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Abenteuerpunktzahl pro Held
 *   (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcbb0(int p1, int p2)
{
    int p1_00;
    short sVar1;
    if ((short)p2 >= 0) {
        for (sVar1 = 0; sVar1 <= 6; sVar1 = sVar1 + 1) {
            p1_00 = ((int *)p1)[sVar1];
            if (p1_00 != 0) {
                f_040780(p1_00, (int)(short)p2);
            }
        }
    }
}
//@ f_0dcbe0  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zieht jedem Mitglied der Gruppe p1 (sofern p2 >= 0 ist) jeweils p2 Abenteuerpunkte über f_0407e0
 *   ab.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die abzuziehende Abenteuerpunktzahl
 *   (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcbe0(int p1, int p2)
{
    int p1_00;
    short sVar1;
    if ((short)p2 >= 0) {
        for (sVar1 = 0; sVar1 <= 6; sVar1 = sVar1 + 1) {
            p1_00 = ((int *)p1)[sVar1];
            if (p1_00 != 0) {
                f_0407e0(p1_00, (int)(short)p2);
            }
        }
    }
}
