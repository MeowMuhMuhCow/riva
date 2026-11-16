/* === Beschreibung (Katalog) ===
 * Einheit gz_0dc9a0_tc (0dcc10 - 0de600)
 *
 * Überblick
 * Die Einheit gz_0dc9a0_tc bildet den umfangreichen Hauptteil des Gruppenverwaltungs-Moduls (party2.cpp /
 * gz_0dc9a0.cpp). Sie verwaltet das Aufnehmen und Entlassen von Gruppenmitgliedern, das Speichern und Laden des
 * "PART"-Blocks im Spielstand, die Übergabe und Zerstörung von Gegenständen, Gebiets- und Positionswechsel der
 * Gruppe in der 3D-Welt sowie Sammelproben (Eigenschafts-, Talent- und Zauberprüfungen) über die gesamte
 * Heldengruppe.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 44/49 gleich (suche.py 29.10.2026, Basis gz_0dc9a0_tc_P1.CPP)
// OPT -4r -oneatx -zp1 -s
int f_0dd440(int);
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
extern volatile short d_1c219c;
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c40;                    // 0x1C2C40
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
void f_0dc9a0(int p1);
//@ f_0dcc10  groesse 48 B, 17 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 den ersten freien Gruppenplatz (0..6).
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den Index des ersten freien Platzes (0..6) oder -1 zurück, wenn alle Plätze belegt sind.
 === Ende Beschreibung === */
int f_0dcc10(int p1)
{
    int iVar1;
    for (iVar1 = 0; (short)iVar1 <= 6; iVar1 = iVar1 + 1) {
        int iVar2 = ((int *)p1)[(short)iVar1];
        if (iVar2 == 0) return iVar1;
    }
    return -1;
}
//@ f_0dcc40  groesse 240 B, 82 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Nimmt einen Helden (p2) auf dem Platz p3 in die Teilgruppe p1 auf, verschiebt einen bereits
 *   vorhandenen NPC-Begleiter (f_039040) gegebenenfalls auf den neuen Platz, erhöht die Mitgliederzahl (+0x1c),
 *   legt das Geld eines regulären Helden in die Gruppenkasse (f_0db820) und aktualisiert die
 *   Kampf-/Gruppenreihenfolge (f_0b0f40, f_041000).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der aufzunehmende Held (p2) sowie der
 *   Zielplatzindex (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcc40(int p1, int p2, int p3)
{
    short i;
    int p2_00, a;
    struct { int next; int index; volatile int result; } slot;
    slot.index = p3;
    i = 0;
    a = (int)&d_1bfdbc;
    for (; (i < 6) && (a != p1); i = i + 1, a = a + 0x61) {
    }
    *(char *)(p1 + 0x1c) += 1;
    p2_00 = f_039040(p1);
    int next = slot.index;
    next = next + 1;
    slot.next = next;
    if (p2_00 != 0) {
        slot.result = ((int (*)(int, int))f_0dc020)(p1, p2_00);
        int index = (short)slot.index;
        int nextArg = (short)slot.next;
        ((int *)p1)[index] = p2_00;
        f_042450((struct hero *)(p2_00), nextArg);
        f_042450((struct hero *)(p2), (int)(short)((short)slot.result + 1));
        f_042440((struct hero *)(p2), (int)i);
        ((int *)p1)[(short)slot.result] = p2;
        f_0451f0(p2_00, -1);
    } else {
        f_042450((struct hero *)(p2), (int)(short)next);
        f_042440((struct hero *)(p2), (int)i);
        ((int *)p1)[(short)slot.index] = p2;
    }
    f_0451f0(p2, -1);
    if (!((char)(f_042400((struct hero *)(p2))))) {
        f_0db820(p1, ((int)(f_042410((struct hero *)(p2)))));
        f_0b0f40(p2);
    }
    d_1c0028 = f_041000();
}
//@ f_0dcd30  groesse 192 B, 54 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Entfernt das Gruppenmitglied auf Platz p2 mit dem Entlassungsgrund p3 aus der Gruppe p1, zahlt ihm
 *   seinen Pro-Kopf-Geldanteil (f_0db900) aus, rückt die verbleibenden Plätze über f_0dc9a0 auf und löst das
 *   Spielende (f_0d64a0) aus, falls nur noch ein einziger handlungsfähiger Held übrig ist und es sich dabei um
 *   den Hund/Begleiter (d_1bc8f0 + 0x239a) handelt.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), der Gruppenplatzindex (p2) sowie der
 *   Status-/Entlassungscode (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcd30(int p1, short p2, short p3)
{
    int p1_00, p2_00, iVar2, iVar3;
    short sVar1;
    p2_00 = f_0db900(p1);
    p1_00 = ((int *)p1)[(short)p2];
    *(char *)(p1 + 0x1c) = *(char *)(p1 + 0x1c) - 1;
    f_042440((struct hero *)(p1_00), 0);
    f_042450((struct hero *)(p1_00), 0);
    f_042420((struct hero *)(p1_00), p2_00);
    f_040e60(p1_00, (int)(signed char)p3);
    ((int *)p1)[(short)p2] = 0;
    f_0db8b0(p1, p2_00);
    f_0dc9a0(p1);
    sVar1 = f_0dbfe0(p1);
    iVar3 = d_1bc8f0 + 0x239a;
    if (sVar1 == 1) {
        iVar2 = f_0dbfb0(p1, iVar3);
        if (iVar2 != 0) {
            iVar3 = f_0d49b0(iVar3);
            if (iVar3 != 0) {
                f_0d64a0();
            }
        }
    }
    d_1c0028 = f_041000();
    d_1c219c = 1;
}
//@ f_0dcdf0  groesse 96 B, 28 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Löst das Gruppenmitglied auf Platz p2 bei einem Teilgruppenwechsel aus der Gruppe p1 heraus,
 *   schreibt ihm seinen Pro-Kopf-Anteil aus der Gruppenkasse (f_0db900) gut und rückt die übrigen Gruppenplätze
 *   über f_0dc9a0 auf.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Gruppenplatzindex (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dcdf0(int p1, int p2)
{
    int p1_00, p2_00;
    p2_00 = f_0db900(p1);
    p1_00 = ((int *)p1)[(short)p2];
    *(char *)(p1 + 0x1c) = *(char *)(p1 + 0x1c) - 1;
    f_042440((struct hero *)(p1_00), 0);
    f_042450((struct hero *)(p1_00), 0);
    f_042420((struct hero *)(p1_00), p2_00);
    ((int *)p1)[(short)p2] = 0;
    f_0db8b0(p1, p2_00);
    f_0dc9a0(p1);
}
//@ f_0dce50  groesse 176 B, 15 Bef, reg eax edx, stapel ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt bei allen Mitgliedern der Gruppe p1 über f_045170(hero, p2) denselben Gruppenstatuswert p2.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der zu setzende Statuswert (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dce50(int p1, short p2)
{
    int p1_00;
    short sVar1;
    for (sVar1 = 0; sVar1 <= 6; sVar1 = sVar1 + 1) {
        p1_00 = ((int *)p1)[sVar1];
        if (p1_00 != 0) {
            f_045170(p1_00, (int)(short)p2);
        }
    }
}
//@ f_0dce80  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ruft für jedes Mitglied der Gruppe p1 die Aktualisierungsroutine f_033ce0 auf.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dce80(int p1)
{
    int p1_00;
    short sVar1;
    for (sVar1 = 0; sVar1 <= 6; sVar1 = sVar1 + 1) {
        p1_00 = ((int *)p1)[sVar1];
        if (p1_00 != 0) {
            f_033ce0(p1_00);
        }
    }
}
//@ f_0dceb0  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Übergibt dem ersten lebenden Mitglied der Gruppe p1, das den Gegenstand aufnehmen kann, über
 *   f_0349b0 eine Anzahl von p3 Exemplaren des Gegenstands p2.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Gegenstandskennung (p2) sowie die
 *   Stückzahl (p3).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dceb0(int p1, int p2, int p3)
{
    int p1_00;
    short sVar2, sVar3;
    sVar2 = 0;
    for (sVar3 = 0; (sVar3 <= 6 && (sVar2 == 0)); sVar3 = sVar3 + 1) {
        p1_00 = ((int *)p1)[sVar3];
        if (p1_00 != 0 && !((char)(f_042470((struct hero *)(p1_00))))) {
            sVar2 = f_0349b0(p1_00, p2, (int)(short)p3);
        }
    }
}
//@ f_0dcf00  groesse 512 B, 121 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Verteilt p3 Exemplare des Gegenstands p2 auf die Inventare der Gruppe p1 (bei Proviantpaketen p2 ==
 *   0x2d zunächst gleichmäßig reihum über f_038c20, danach auf alle freien Plätze über f_0366e0) und bietet dem
 *   Spieler bei vollem Inventar in einer Schleife an, überzählige Gegenstände wegzuwerfen (f_036300), bis alles
 *   verstaut ist oder der Spieler abbricht.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Gegenstandskennung (p2) sowie die zu
 *   übergebende Stückzahl (p3).
 * - Rückgabewert: Gibt die tatsächlich von der Gruppe aufgenommene Stückzahl zurück.
 === Ende Beschreibung === */
int f_0dcf00(int p1, int p2, int p3)
{
    char obj[60];
    int result = 0;
    int innerDone;
    int j, i = 0;

    short limit;
    short done;
    int item;
    int file;
    short choice;
    f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    done = result; int re0=d_1c2c40; d_1c2c40=re0; // haelt die Registerzuteilung wie im Original
    do {
        if ((short)p2 == 0x2d) {
            signed char sr=*(signed char *)&d_1c349c; *(signed char *)&d_1c349c=sr; // haelt die Registerzuteilung wie im Original
            if ((short)p3 > 1 && *(signed char *)((*&p1) + 0x1c) > 1) {
            int rt = *(int *)&d_1c2c40; int re1=d_1c349c; d_1c349c=re1; // haelt die Registerzuteilung wie im Original
            short product = p3 * 3;
            i=0; innerDone=i; *(int *)&d_1c2c40=rt; limit=product; // haelt die Registerzuteilung wie im Original
            do {
                int next = i + 1;
                i = next;
                if ((short)next < (short)limit && (short)p3 > 0) {
                    int it = f_038c20(p1);
                    int amount = f_0366e0(it, (int)(short)p2, 0, 1);
                    if ((short)amount > 0) {
                        p3 = p3 - amount;
                        result = result + amount;
                    }
                } else {
                    innerDone = 1; innerDone = 1; innerDone = 1; innerDone = 1; /* haelt die Registerzuteilung wie im Original */ i = (i & 0) ? 0 : i;
                }
            } while (!(short)innerDone);
        }

        }

        result = (result & 0) ? 0 : result; // haelt die Registerzuteilung wie im Original
        item = (item & 0) ? 0 : item; // haelt die Registerzuteilung wie im Original
        for (j = 0; (short)j <= 6; j = j + 1) {
            item = ((int *)p1)[(short)j];
            if (item != 0) {
                while ((short)p3 > 0) {
                    int amount = f_0366e0(item, (int)(short)p2, 0, (int)(short)p3);
                    if ((short)amount <= 0) break;
                    p3 = p3 - amount;
                    result = result + amount;
                }
            }
        }
        if ((short)p3 > 0) {
            int table = d_1c2c40;
            int val = *(int *)((short)p2 * 4 + table); val=(val&0)?0:val; // haelt die Registerzuteilung wie im Original
            *(int *)(((*(int *)(obj + 12) & 0) ? 0 : *(int *)(obj + 12)) + 4) = val;
            *(short *)(*(int *)(obj + 0x20) + 2) = (short)p3;
            if (f_0bf6f0((int)&d_1c2c64, 0x200000fb) == 1) {
                file = f_038d70(p1, 0x200000fc);
                if (file != 0) {
                    choice = f_032820(file, 0x20000103, 0);
                    if (choice != -1) f_036300(file, (int)choice, -1);
                }
            } else {
                done = 1;
            }
        } else {
            done = 1;
        }
    } while (done == 0);
    f_1254a0((int)obj, 0);
    return result;
}
//@ f_0dd0a0  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob sich in der Gruppe p1 ein handlungsfähiger Zauberkundiger (f_042a10 != 0 && f_0d49b0 !=
 *   0) befindet, dem die Zauberprobe f_03d3d0(hero, p2, p3) auf den Zauber p2 mit Erschwernis p3 gelingt.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Zauberkennung (p2) sowie der
 *   Probenmodifikator (p3).
 * - Rückgabewert: Gibt 1 zurück, sobald einem Gruppenmitglied der Zauber gelingt, sonst 0.
 === Ende Beschreibung === */
int f_0dd0a0(int p1, short p2, short p3)
{
    int p1_00;
    short sVar3;
    for (sVar3 = 0; sVar3 <= 6; sVar3 = sVar3 + 1) {
        p1_00 = ((int *)p1)[sVar3];
        if (p1_00 != 0 && f_042a10((struct hero *)(p1_00)) != 0 && f_0d49b0(p1_00) != 0 && 0 < f_03d3d0(p1_00, (int)(short)p2, (int)(signed char)p3)) {
            return 1;
        }
    }
    return 0;
}
//@ f_0dd100  groesse 208 B, 23 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 nach einem Helden, der den Gegenstand p2 besitzt (f_0d54f0), und entfernt
 *   genau ein Exemplar dieses Gegenstands über f_036300(hero, slot, 1) aus dessen Inventar.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die zu entfernende
 *   Gegenstandskennung (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dd100(int p1, int p2)
{
    short sVar1;
    int p1_00;
    sVar1 = f_0d54f0(p1, (int)(short)p2);
    if (sVar1 != -1) {
        p1_00 = f_0de7d0(p1, (int)sVar1);
        if (p1_00 != 0) {
            sVar1 = f_0d4aa0(p1_00, (int)(short)p2);
            if (sVar1 != -1) {
                f_036300(p1_00, (int)sVar1, 1);
            }
        }
    }
}
//@ f_0dd150  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Soll p2 zufällig ausgewählte Gegenstände aus dem Besitz der Gruppe p1 über f_033530 zerstören bzw.
 *   unbrauchbar machen. (Hinweis: Da der Heldenindex cVar1 = -1 im Originalcode nur einmal vor der äußeren
 *   for-Schleife statt in jedem Schleifendurchlauf zurückgesetzt wird, wird ab dem zweiten Durchlauf n >= 1 kein
 *   neuer Zufallsgegenstand mehr gezogen, sondern derselbe Gegenstand beim selben Helden erneut gesucht.)
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Anzahl der zu zerstörenden
 *   Gegenstände (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dd150(int p1, short p2)
{
    signed char cVar1;
    short sVar2, unaff_SI;
    short n;
    int p1_00;
    cVar1 = -1;
    for (n = 0; n < p2; n++) {
        while (cVar1 < 0) {
            unaff_SI = f_1457e0((short)(d_1be258 - 1));
            cVar1 = f_0d54f0(p1, (int)unaff_SI);
        }
        p1_00 = f_0de7d0(p1, (int)cVar1);
        sVar2 = f_0d4aa0(p1_00, (int)unaff_SI);
        f_033530(p1_00, (int)sVar2);
    }
}
//@ f_0dd1d0  groesse 80 B, 27 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 nach einem Helden, der den Gegenstand p2 besitzt, und wendet auf diesen
 *   Inventarplatz die Gegenstandsaktion f_035180 an.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn der Gegenstand gefunden und bearbeitet wurde, sonst 0.
 === Ende Beschreibung === */
int f_0dd1d0(int p1, int p2)
{
    short sVar1;
    int p1_00;
    sVar1 = f_0d54f0(p1, (int)(short)p2);
    if (sVar1 != -1) {
        p1_00 = f_0de7d0(p1, (int)sVar1);
        if (p1_00 != 0) {
            sVar1 = f_0d4aa0(p1_00, (int)(short)p2);
            if (sVar1 != -1) {
                f_035180(p1_00, (int)sVar1);
                return 1;
            }
        }
    }
    return 0;
}
//@ f_0dd220  groesse 208 B, 67 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Speichert die 0x61 Bytes große Struktur der Teilgruppe p1 mit der Blockkennung "PART" (d_1b82bc) in
 *   die Spielstandsdatei (d_1c2140), wobei die 7 Heldenzeiger vorübergehend in portable Helden-Indizes ((ptr -
 *   d_1bc8f0) / 0x5ef + 4) umgerechnet werden.
 * - Eingaben: Übergeben wird der Zeiger auf das zu speichernde Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0dd220(int p1)
{
    int tmp[7];
    short local_1c;
    short sVar2; int *q;
    memcpy(tmp, (void *)p1, 0x1c);
    for (sVar2 = 0; sVar2 <= (unsigned short)6; sVar2 = sVar2 + 1) {
        int t527_12;
        q = (int *)p1 + sVar2;
        if ((t527_12 = *q) != 0) {
            *q = (*q - d_1bc8f0) / 0x5ef + 4;
        }
    }
    local_1c = 0x61;
    f_144cb6((int)d_1c2140, (int)&d_1b82bc, 4);
    f_144cb6((int)d_1c2140, (int)&local_1c, 2);
    f_144cb6((int)d_1c2140, p1, (unsigned short)local_1c);
    memcpy((void *)p1, tmp, 0x1c);
    return 1;
}
//@ f_0dd2f0  groesse 176 B, 48 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest einen "PART"-Datenblock (0x54524150) aus der Spielstandsdatei (d_1c2140) in das
 *   Gruppen-Objekt p1 ein und rechnet die gespeicherten Helden-Indizes wieder in echte Speicherzeiger (idx *
 *   0x5ef + d_1bc8f0 - 0x17bc) um.
 * - Eingaben: Übergeben wird der Zeiger auf das zu ladende Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn die "PART"-Kennung gültig war, sonst 0.
 === Ende Beschreibung === */
int f_0dd2f0(int p1)
{
    int t566_16;
    int local_14;
    short local_10;
    int *piVar3;
    f_144e8b((int)d_1c2140, (int)&local_14, 4);
    if (local_14 == 0x54524150) {
        f_144e8b((int)d_1c2140, (int)&local_10, 2);
        f_144e8b((int)d_1c2140, p1, (unsigned short)local_10);
        for (local_10 = 0; (unsigned short)local_10 <= 6; local_10++) {
            piVar3 = (int *)(p1 + (unsigned short)local_10 * 4);
            if ((t566_16 = *piVar3) != 0) {
                int prod = t566_16 * 0x5ef; int g = *(volatile int *)&d_1bc8f0; *piVar3 = prod + g - 0x17bc;
            }
        }
        return 1;
    }
    return 0;
}
//@ f_0dd3a0  groesse 112 B, 45 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 nach dem ersten aktiven Helden (f_0d4a60), dessen Typus/Klassenkennung
 *   (f_042350) im Bereich [p2, p3] liegt (wobei p3 == 0 als p3 = p2 behandelt wird).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Untergrenze (p2) sowie die Obergrenze
 *   (p3) des gesuchten Heldentypus.
 * - Rückgabewert: Gibt den Zeiger auf den gefundenen Helden oder 0 zurück.
 === Ende Beschreibung === */
int f_0dd3a0(int p1, int p2, int p3)
{
    int p1_00;
    signed char cVar1;
    short sVar3;
    if ((short)p3 == 0) {
        p3 = p2;
    }
    for (sVar3 = 0; sVar3 <= 6; sVar3 = sVar3 + 1) {
        p1_00 = ((int *)p1)[sVar3];
        if (p1_00 != 0) {
            cVar1 = f_042350((struct hero *)(p1_00));
            if ((int)cVar1 >= (int)(short)p2) {
                cVar1 = f_042350((struct hero *)(p1_00));
                if ((int)cVar1 <= (int)(short)p3) {
                    if (f_0d4a60(p1_00) != 0) {
                        return p1_00;
                    }
                }
            }
        }
    }
    return 0;
}
//@ f_0dd410  groesse 48 B, 18 Bef, reg edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob die Gruppe p1 einen NPC-Begleiter (f_039040) mitführt, der (bei p2 != 0) aktiv (f_0d4a60
 *   == 1) ist, und gibt dessen NPC-Kennung (f_042400) zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie ein Flag, ob der NPC aktiv sein muss
 *   (p2).
 * - Rückgabewert: Gibt die NPC-Kennung (f_042400) oder 0 zurück.
 === Ende Beschreibung === */
char f_0dd410(int p1, int p2)
{
    char uVar1;
    int p1_00;
    p1_00 = f_039040(p1);
    uVar1 = 0;
    if (p1_00 != 0) {
        if ((f_0d4a60(p1_00) == 1) || (p2 == 0)) {
            uVar1 = ((char)(f_042400((struct hero *)(p1_00))));
        }
    }
    return uVar1;
}
//@ f_0dd480  groesse 32 B, 10 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Löst an der aktuellen X/Z-Kartenposition der Gruppe p1 (f_0de840, f_0de880) die 3D-Kartenabfrage
 *   f_1511ec aus.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dd480(int p1)
{
    int p2, p1_00;
    p2 = f_0de880(p1);
    p1_00 = f_0de840(p1);
    f_1511ec(p1_00, p2);
}
//@ f_0dd4a0  groesse 80 B, 28 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft über f_1497d8, ob das Kartenfeld an der aktuellen X/Z-Position der Gruppe p1 die
 *   Orts-/Ereigniskennung p2 trägt.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die zu vergleichende Kennung (p2).
 * - Rückgabewert: Gibt 1 bei Übereinstimmung zurück, sonst 0.
 === Ende Beschreibung === */
int f_0dd4a0(int p1, int p2)
{
    int p3, p2_00, iVar1, local_14, r;
    short sVar2;
    local_14 = 0;
    p3 = f_0de880(p1);
    r = 0;
    p2_00 = f_0de840(p1);
    sVar2 = 0;
    iVar1 = f_1497d8((int)&local_14, p2_00, p3);
    if (iVar1 == 0) {
        sVar2 = (short)local_14;
    }
    if (sVar2 == (short)p2) r = 1;
    return r;
}
//@ f_0dd4f0  groesse 48 B, 16 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft über f_1511ec, ob das Boden-/Terrainfeld an der aktuellen X/Z-Position der Gruppe p1 den
 *   Typwert p2 besitzt.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der zu prüfende Feldwert (p2).
 * - Rückgabewert: Gibt 1 bei Übereinstimmung zurück, sonst 0.
 === Ende Beschreibung === */
int f_0dd4f0(int p1, int p2)
{
    short sVar1;
    int p2_00, p1_00, r = 0;
    p2_00 = f_0de880(p1);
    p1_00 = f_0de840(p1);
    sVar1 = f_1511ec(p1_00, p2_00);
    if (sVar1 == (short)p2) r = 1;
    return r;
}
//@ f_0dd520  groesse 288 B, 91 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bewegt die Gruppe p1 auf der 3D-Karte auf die Zielkoordinaten (p2, p3), sofern das Ziel begehbar
 *   ist (f_15164c() != 0), und führt dabei eine 15-stufige Kamera-Abblend-, Positionswechsel- und
 *   Aufblend-Animation (f_155bc8, f_1223c0) aus.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die neue X- (p2) und Z-Koordinate
 *   (p3).
 * - Rückgabewert: Gibt 1 zurück, wenn die Bewegung möglich war und ausgeführt wurde, sonst 0.
 === Ende Beschreibung === */
int f_0dd520(int p1, int p2, int p3)
{
    short k, s;
    int r;
    char tmp[22];
    memcpy(tmp, (void *)&d_1c90c0, 22);
    d_1a9960 = *(short *)&d_1a80c4;
    r = 0;
    d_1c90c8 = p3;
    d_1c90c0 = p2;
    if (f_15164c() != 0) {
        int step = 3;
        k = 0;
        s = 0;
        d_1a9960 = *(short *)&d_1a80c4;
        goto t1;
        do {
            f_155bc8(k * *(int *)&d_1a80c8);
            f_1223c0();
            s++;
        t1:
            k = (short)(k + 3);
        } while (s < 0xf);
        f_0de930(p1, 2);
        f_0de850(p1, p2);
        f_0de890(p1, p3);
        f_1223c0();
        f_0de930(p1, 0);
        s = 0;
        goto t2;
        do {
            k = (short)(k - step);
            f_155bc8(k * *(int *)&d_1a80c8);
            f_1223c0();
            s++;
        t2:;
        } while (s < 0xf);
        r = 1;
    } else memcpy((void *)&d_1c90c0, tmp, 22);
    return r;
}
//@ f_0dd640  groesse 144 B, 23 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt über f_149728 die 3D-Weltkoordinaten des Kartenpunkts p2 und versetzt die Gruppe p1
 *   mittels der Überblend-Animation f_0dd520 dorthin.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Kartenpunkt-Kennung (p2).
 * - Rückgabewert: Gibt 1 bei erfolgreichem Positionswechsel zurück, sonst 0.
 === Ende Beschreibung === */
int f_0dd640(int p1, int p2)
{
    int iVar1, uVar2, a, b, c;
    uVar2 = 0;
    iVar1 = f_149728((unsigned short)p2, (int)&a, (int)&b, (int)&c);
    if (iVar1 == 0) {
        uVar2 = f_0dd520(p1, a, c);
    }
    return uVar2;
}
//@ f_0dd680  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt die Gruppe p1 unmittelbar (ohne Überblendung) auf die X/Z-Koordinaten (p2, p3) und den
 *   Blickwinkel p4 und markiert bei der aktiven Hauptgruppe (p1 == d_1c0004) eine Positionsaktualisierung
 *   (f_0de930(p1, 1)).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die X- (p2) und Z-Koordinate (p3) sowie
 *   der Blickwinkel (p4).
 * - Rückgabewert: Gibt konstant 1 zurück.
 === Ende Beschreibung === */
int f_0dd680(int p1, int p2, int p3, int p4)
{
    d_1c90c0 = p2;
    d_1c90c8 = p3;
    f_0de850(p1, p2);
    f_0de890(p1, p3);
    f_0de8d0(p1, (unsigned short)p4);
    if (p1 == d_1c0004) {
        f_0de930(p1, 1);
    }
    return 1;
}
//@ f_0dd6d0  groesse 128 B, 38 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schlägt über f_149728 die 3D-Koordinaten des Kartenpunkts p2 nach und setzt die Gruppe p1 mit dem
 *   Blickwinkel p3 direkt auf diese Position.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Kartenpunkt-Kennung (p2) sowie der
 *   Blickwinkel (p3).
 * - Rückgabewert: Gibt 1 zurück, wenn der Kartenpunkt gefunden wurde, sonst 0.
 === Ende Beschreibung === */
int f_0dd6d0(int p1, int p2, int p3)
{
    int iVar1, uVar2, a, b, c;
    uVar2 = 0;
    iVar1 = f_149728((unsigned short)p2, (int)&a, (int)&b, (int)&c);
    if (!iVar1) {
        int uVar6;
        uVar6 = c;
        d_1c90c0 = a;
        f_0de850(p1, ((*(unsigned int *)&d_1c90c8) = (unsigned int)uVar6, a));
        f_0de890(p1, uVar6);
        f_0de8d0(p1, (unsigned short)p3);
        if (p1 == d_1c0004) {
            f_0de930(p1, 1);
        }
        uVar2 = 1;
    }
    return uVar2;
}
//@ f_0dd750  groesse 160 B, 47 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt die Gruppe p1 auf den Kartenpunkt p2 (f_149728) und berechnet den neuen Blickwinkel aus den
 *   unteren zwei Dezimalstellen der Punktkennung ((p2 % 100) * 0x71c).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die kombinierte Kartenpunkt- und
 *   Richtungskennung (p2).
 * - Rückgabewert: Gibt 1 bei Erfolg oder 0 zurück.
 === Ende Beschreibung === */
int f_0dd750(int p1, int p2)
{
    struct M { static short k(int r) { return r * 0x71c; } };
    int iVar1, uVar2, a, b, c, c1;
    short local_18;
    unsigned short s = (unsigned short)p2;
    local_18 = M::k((int)s % 100);
    uVar2 = 0;
    iVar1 = f_149728((int)s, (int)&a, (int)&b, (int)&c);
    if (iVar1 == 0) {
        c1 = c;
        d_1c90c0 = a;
        d_1c90c8 = c1;
        f_0de850(p1, a);
        f_0de890(p1, c1);
        f_0de8d0(p1, (unsigned short)local_18);
        if (p1 == d_1c0004) {
            f_0de930(p1, 1);
        }
        uVar2 = 1;
    }
    return uVar2;
}
struct Dispatcher660 { int f_057220(int,int); void enable660(signed char &flag) { flag|=1; f_057220(0x8030084,0); } };
//@ f_0dd7f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt einen Gebiets- oder Ebenenwechsel der Gruppe p1 in das Zielgebiet p2 zum Startpunkt p3 durch:
 *   liegt p2 bereits im aktuell geladenen Gebiet, wird die Position direkt über f_149728 umgesetzt; andernfalls
 *   werden Sonderfälle für mitgeführte Quest-NPCs (f_039040, Modi 1..6) abgefragt und anschließend Zielgebiet
 *   (f_0de830) und Startpunkt (f_0de9b0) eingetragen.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Zielgebiets-ID (p2) sowie die
 *   Startpunkt-Kennung (p3).
 * - Rückgabewert: Gibt 1 zurück, wenn der Gebietswechsel durchgeführt wurde, oder 0, wenn der Spieler ihn wegen
 *   eines Begleiters abgebrochen hat.
 === Ende Beschreibung === */
int f_0dd7f0(int p1, short p2, short p3)
{
    struct Message660 {
        int table;
        int *arg;
        char rest[52];
        Message660() { f_125400((int)this, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498); }
        ~Message660() { f_1254a0((int)this, 0); }
        static short direction(int n) { return n*0x71c; }
        static void announce(int owner,int msg,int value) {
            signed char flags=*(signed char *)&d_1c01d4;
            flags|=1;
            *(signed char *)&d_1c01d4=flags;
            f_057220(owner,msg,value);
        }
    };
    int final_z;
    int result=1;
    Message660 outer;
    int x,z,y;
    short heading;
    if (f_0de820(p1)==p2 && d_1bd6c0 && *d_1bd6c0==p2) {
        heading=Message660::direction((int)(unsigned short)p3%100);
        result=0;
        if (f_149728((unsigned short)p3,(int)&x,(int)&y,(int)&z)==0) {
            final_z=z;
            int *q = &d_1c90c0; *q = x; // haelt die Registerzuteilung wie im Original
            d_1c90c8=final_z;
            f_0de850(p1,x);
            f_0de890(p1,final_z);
            f_0de8d0(p1,(unsigned short)heading);
            if(p1==d_1c0004) f_0de930(d_1c0004,1);
            result=1;
        }
    } else {
        f_0de820(d_1c0004);
        int allowed=1;
        if(f_039040(d_1c0004)!=0) {
            Message660 inner;
            int member=f_039040(d_1c0004);
            short mode=(signed char)((char)(f_042400((struct hero *)(f_039040(d_1c0004)))));
            if(mode==2) {
                inner.arg[1]=f_038c40(d_1c0004);
                allowed=0;
                if ((signed char)((char)(f_042470((struct hero *)(member))))==1) {
                    if(f_0bf6f0((int)&d_1c2c64,0x360000a8)==1) {
                        f_0bf730((int)&d_1c2c64,0x360000a9);
                        allowed=1;
                    }
                } else if ((signed char)((char)(f_0425f0((struct hero *)(member))))==1) {
                    if(f_0bf6f0((int)&d_1c2c64,0x360000aa)==1) {
                        f_0bf730((int)&d_1c2c64,0x360000ab);
                        allowed=1;
                    }
                } else {
                    if(f_0bf6f0((int)&d_1c2c64,0x360000ac)==1) {
                        f_0bf730((int)&d_1c2c64,0x360000ad);
                        allowed=1;
                    }
                }
                if(allowed==1) f_0d64a0();
            } else if(mode==4) {
                f_0d64a0();
                signed char bit=(*(signed char *)&d_1c01d4)&1;
                if((int)bit==0) ((Dispatcher660 *)&d_1c2c00)->enable660(*(signed char *)&d_1c01d4);
                *(signed char *)&d_1c01cc=1;
            } else if(mode==1 || mode==3) {
                if(EQ(*(signed char *)&d_1c00c4,1) && EQB(*(signed char *)&d_1c01b8,0)) {
                    if(p2==1 || p2==2) {
                        inner.arg[2]=f_039040(d_1c0004);
                        if((mode==3 && EQ(*(signed char *)&d_1bfac4,1)) ||
                           (mode==1 && EQ(*(signed char *)&d_1bfabc,1))) {
                            f_0d64a0();
                        } else if(f_0bf6f0((int)&d_1c2c64,0x2201001e)==1) {
                            f_0d64a0();
                        } else allowed=0;
                    }
                } else {
                    int pending=f_0d6690(2);
                    if(f_0de820(d_1c0004)==0 && p2==5 && (EQB(*(signed char *)&d_1bfab8,0) || pending)) {
                        if(f_0bf6f0((int)&d_1c2c64,0x2201001e)==1) f_0d64a0();
                        else allowed=0;
                    }
                }
            } else if(mode==6 && EQ(*(signed char *)&d_1c0214,1)) {
                if(((short (*)(int,...))f_0bf820)((int)&d_1c2c64,0x2500004a,2,0x2500004b,0x2500004c)!=1) {
                    f_0bf730((int)&d_1c2c64,0x2500004d);
                    f_0d64a0();
                    *(signed char *)&d_1c0214=2;
                } else allowed=0;
            }
            if(EQ(*(signed char *)&d_1c01cc,1) && p2==1 &&
               EQ(*(signed char *)&d_1c00c4,1) && EQB(*(signed char *)&d_1c01c8,0)) *(signed char *)&d_1c01cc=2;
        }
        if(allowed==1) {
            f_0de830(p1,p2);
            f_0de9b0(p1,p3);
        } else result=0;
    }
    return result;
}

struct ContextDC493Pos { int a, b, c, d; unsigned short e, f, g; };
extern int dc493_d_1bfdbc;
#pragma aux dc493_d_1bfdbc "d_1bfdbc"
extern int dc493_d_1c0004;
#pragma aux dc493_d_1c0004 "d_1c0004"
extern short dc493_d_1c219c;
#pragma aux dc493_d_1c219c "d_1c219c"
extern int dc493_d_1c2c64;
#pragma aux dc493_d_1c2c64 "d_1c2c64"
extern ContextDC493Pos dc493_d_1c90c0;
#pragma aux dc493_d_1c90c0 "d_1c90c0"
extern unsigned short dc493_d_1a9960;
#pragma aux dc493_d_1a9960 "d_1a9960"
extern const char dc493_d_1c349c[];
#pragma aux dc493_d_1c349c "d_1c349c"
extern const char dc493_d_1c3870[];
#pragma aux dc493_d_1c3870 "d_1c3870"
extern const char dc493_d_1c3498[];
#pragma aux dc493_d_1c3498 "d_1c3498"
#pragma intrinsic(memcpy)
struct ContextDC493 { public:
// gz_0dc9a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DDC70-0x0DE600 (t2)

struct Ctx { int a; int *p; char z[0x34]; };
static int f_155968(int p1);
static int f_1559e0();
static int f_15164c();
static int f_0de7c0(int p1);
static int f_0de840(int p1);
static int f_0de850(int p1, int p2);
static int f_0de860(int p1);
static int f_0de870(int p1, int p2);
static int f_0de880(int p1);
static int f_0de890(int p1, int p2);
static int f_0de8a0(int p1);
static int f_0de8b0(int p1, int p2);
static int f_0de8c0(int p1);
static int f_0de8d0(int p1, int p2);
static int f_0de8e0(int p1);
static int f_0de8f0(int p1, int p2);
static int f_0de900(int p1);
static int f_0de910(int p1, int p2);
static int f_0de930(int p1, int p2);
static int f_038c80(int p1);
static int f_045820(int p1, int p2);
static int f_0391b0(int p1, int p2);
static short f_0dc020(int p1, int p2);
static short f_044c90(int p1, int p2, int p3);

static int f_044300(int p1, int p2);
static int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
static int f_1254a0(void *p1, int p2);
static int f_0d4a60(int p1);
static signed char f_044900(int p1, int p2, int p3);
static signed char f_0d4aa0(int p1, int p2);
static int f_033530(int p1, int p2);
static int f_040a00(int p1, int p2, int p3);
static int f_0bf730(int p1, int p2);

static short f_035260(int p1, int p2);
static short f_0459e0(int p1);
static short f_0458b0(int p1);


static int f_0326d0(int p1, int p2);
static int f_043fd0(int p1, int p2);
static int f_043ff0(int p1, int p2);

#define CH(i) ((int)((char *)&dc493_d_1bfdbc + (i) * 0x61))
static void f_0ddc70(int p1, unsigned short p2);
static int f_0ddcf0(int p1);
static int f_0ddd60(int p1);
static int f_0ddeb0(int p1);
static void f_0ddf50(int p1);
static void f_0ddfc0(int p1);
static short f_0de020(int (*p1)(int), int *p2);
static short f_0de070(int (*p1)(int, int), int *p2, int p3);
static int f_0de0d0(int (*p1)(int));
static short f_0de120(int *p1);
static int f_0de170(int p1, int p2);
static int f_0de1c0(int *p1, short p2, short p3);
static void f_0de210(int *p1);
static char f_0de250(int *p1, int p2, int p3, int p4, int p5, short p6, int p7, int p8);
static char f_0de350(int *p1, int p2, short p3, int p4, int p5, short p6);
static char f_0de410(int *p1, int p2, short p3, short p4);
static short f_0de480(int *p1, int p2);
static short f_0de4d0(int *p1);
static short f_0de510(int *p1);
static short f_0de540(int *p1);
static int f_0de570(int *p1, int p2);
static void f_0de5a0(int *p1, signed char p2);
static void f_0de5d0(int *p1, signed char p2);
};
//@ f_0ddcf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt einen Schritt der 3D-Bewegungsberechnung (f_1559e0) aus und übernimmt anschließend die neuen
 *   Kamera-/Spielerkoordinaten und Winkel aus d_1c90c0 in das Gruppen-Objekt p1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den Statuswert der 3D-Bewegungsfunktion f_1559e0 zurück.
 === Ende Beschreibung === */
int ContextDC493::f_0ddcf0(int p1)
{
  int r = f_1559e0();
  f_0de850(p1, dc493_d_1c90c0.a);
  f_0de870(p1, dc493_d_1c90c0.b);
  f_0de890(p1, dc493_d_1c90c0.c);
  f_0de8d0(p1, dc493_d_1c90c0.f);
  f_0de8f0(p1, dc493_d_1c90c0.e);
  f_0de910(p1, dc493_d_1c90c0.g);
  return r;
}
//@ f_0ddd60
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft über die 3D-Kollisionsabfrage f_15164c, ob die aktuelle Position der Gruppe p1 blockiert ist
 *   (f_15164c() == 0), und sucht in diesem Fall mit schrittweise wachsendem Suchradius (k * 10 für k = 1..30)
 *   nach einer freien Nachbarposition, auf die die Gruppe versetzt wird.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn die Position frei war oder eine freie Ausweichposition gefunden wurde,
 *   sonst 0.
 === Ende Beschreibung === */
int ContextDC493::f_0ddd60(int p1)
{
  int r = 1;
  ContextDC493Pos s1;
  short s2 = 0;
  memcpy(&s1, &dc493_d_1c90c0, 22);
  s2 = dc493_d_1a9960;
  int ok = 0;
  dc493_d_1a9960 = 0;
  dc493_d_1c90c0.a = f_0de840(p1);
  
  dc493_d_1c90c0.c = f_0de880(p1);
  if (f_15164c() == 0) ok = 1;
  memcpy(&dc493_d_1c90c0, &s1, 22);
  dc493_d_1a9960 = (unsigned short)s2;
  if (ok) {
    ContextDC493Pos s3;
    short s4;
    memcpy(&s3, &dc493_d_1c90c0, 22);
    s4 = dc493_d_1a9960;
    short k;
    r = 0;
    for (k = 1; k <= 0x1e && r == 0; k++) {
      dc493_d_1a9960 = k * 10;
      if (f_15164c() != 0) {
        f_0de850(p1, dc493_d_1c90c0.a);
        f_0de870(p1, dc493_d_1c90c0.b);
        f_0de890(p1, dc493_d_1c90c0.c);
        f_0de930(p1, 1);
        r = 1;
      }
    }
    memcpy(&dc493_d_1c90c0, &s3, 22);
    dc493_d_1a9960 = (unsigned short)s4;
  }
  return r;
}
//@ f_0ddeb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft ohne Positionsänderung über f_15164c, ob die aktuelle X/Z-Position der Gruppe p1 in der
 *   3D-Welt blockiert/unbegehbar ist.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn die Position blockiert ist (f_15164c() == 0), sonst 0.
 === Ende Beschreibung === */
int ContextDC493::f_0ddeb0(int p1)
{
  ContextDC493Pos s1;
  short s2;
  memcpy(&s1, &dc493_d_1c90c0, 22);
  s2 = dc493_d_1a9960;
  int ok = 0;
  dc493_d_1a9960 = 0;
  dc493_d_1c90c0.a = f_0de840(p1);
  
  dc493_d_1c90c0.c = f_0de880(p1);
  if (f_15164c() == 0) ok = 1;
  memcpy(&dc493_d_1c90c0, &s1, 22);
  dc493_d_1a9960 = (unsigned short)s2;
  return ok;
}
//@ f_0ddf50
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Überträgt sämtliche 3D-Positions- und Winkelwerte aus der globalen Kamerastruktur d_1c90c0 in die
 *   Felder des Gruppen-Objekts p1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0ddf50(int p1)
{
  f_0de850(p1, dc493_d_1c90c0.a);
  f_0de870(p1, dc493_d_1c90c0.b);
  f_0de890(p1, dc493_d_1c90c0.c);
  f_0de8b0(p1, dc493_d_1c90c0.d);
  f_0de8d0(p1, dc493_d_1c90c0.f);
  f_0de8f0(p1, dc493_d_1c90c0.e);
  f_0de910(p1, dc493_d_1c90c0.g);
}
//@ f_0ddfc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Lädt die im Gruppen-Objekt p1 gespeicherten 3D-Koordinaten und Blickwinkel in die globale
 *   3D-Kamerastruktur d_1c90c0.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0ddfc0(int p1)
{
  dc493_d_1c90c0.a = f_0de840(p1);
  dc493_d_1c90c0.b = f_0de860(p1);
  dc493_d_1c90c0.c = f_0de880(p1);
  dc493_d_1c90c0.d = f_0de8a0(p1);
  dc493_d_1c90c0.f = f_0de8c0(p1);
  dc493_d_1c90c0.e = f_0de8e0(p1);
  dc493_d_1c90c0.g = f_0de900(p1);
}
//@ f_0de020
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Durchläuft alle 6 Teilgruppen (d_1bfdbc), ruft für jede nicht-leere Teilgruppe die
 *   Prüf-Callback-Funktion p1(group) auf und sammelt alle passenden Teilgruppenzeiger im Ausgabe-Array p2.
 * - Eingaben: Übergeben werden der Funktionszeiger auf das Gruppen-Prädikat (p1) sowie das Ziel-Array für
 *   gefundene Gruppenzeiger (p2).
 * - Rückgabewert: Gibt die Anzahl der gefundenen Teilgruppen zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de020(int (*p1)(int), int *p2)
{
  short n = 0;
  short i;
  for (i = 0; i < 6; i++) {
    int c = CH(i);
    int t_170 = f_0de7c0(c);
    if (t_170 != (short)0) {
      if (p1(c) == 1) p2[(short)n++] = c;
    }
  }
  return n;
}
//@ f_0de070
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Durchläuft alle 6 Teilgruppen (d_1bfdbc), ruft für jede nicht-leere Teilgruppe die zweistellige
 *   Prüf-Callback-Funktion p1(group, p3) auf und trägt alle passenden Teilgruppenzeiger in p2 ein.
 * - Eingaben: Übergeben werden der Funktionszeiger (p1), das Ziel-Array (p2) sowie das Zusatzargument (p3).
 * - Rückgabewert: Gibt die Anzahl der gefundenen Teilgruppen zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de070(int (*p1)(int, int), int *p2, int p3)
{
  short n = 0;
  short i;
  for (i = 0; i < 6; i++) {
    int c = CH(i);
    int t_170 = f_0de7c0(c);
    if (t_170 != (short)0) {
      if (p1(c, p3) == 1) p2[(short)n++] = c;
    }
  }
  return n;
}
//@ f_0dd440  groesse 64 B, 21 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt über f_1497d8 die Orts-/Ereigniskennung des Kartenfelds an der aktuellen X/Z-Position der
 *   Gruppe p1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die gefundene Feldkernung oder 0 zurück.
 === Ende Beschreibung === */
int f_0dd440(int p1)
{
    int uVar1, p2, local_10, r;
    local_10 = 0;
    uVar1 = f_0de880(p1);
    p2 = f_0de840(p1);
    r = 0;
    if (f_1497d8((int)&local_10, p2, uVar1) == 0) {
        r = local_10;
    }
    return r;
}
//@ f_0ddc70
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt den 3D-Bewegungsbefehl f_155968(p2) aus, übernimmt die resultierenden Koordinaten und Winkel
 *   aus d_1c90c0 in das Gruppen-Objekt p1 und markiert bei der aktiven Hauptgruppe eine Positionsaktualisierung
 *   (f_0de930(p1, 1)).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der Bewegungscode (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0ddc70(int p1, unsigned short p2)
{
  f_155968(p2);
  f_0de850(p1, dc493_d_1c90c0.a);
  f_0de870(p1, dc493_d_1c90c0.b);
  f_0de890(p1, dc493_d_1c90c0.c);
  f_0de8d0(p1, dc493_d_1c90c0.f);
  f_0de8f0(p1, dc493_d_1c90c0.e);
  f_0de910(p1, dc493_d_1c90c0.g);
  if (p1 == dc493_d_1c0004) f_0de930(p1, 1);
}
//@ f_0de0d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht unter den 6 Teilgruppen (d_1bfdbc) die erste nicht-leere Teilgruppe, für die die
 *   Prüf-Callback-Funktion p1(group) den Wert 1 liefert.
 * - Eingaben: Übergeben wird der Funktionszeiger auf das Gruppen-Prädikat (p1).
 * - Rückgabewert: Gibt den Zeiger auf die erste gefundene Teilgruppe oder 0 zurück.
 === Ende Beschreibung === */
int ContextDC493::f_0de0d0(int (*p1)(int))
{
  int r = 0;
  short i;
  for (i = 0; i < 6 && r == 0; i++) {
    int c = CH(i);
    if (f_0de7c0(c) != 0) {
      if (p1(c) == 1) r = c;
    }
  }
  return r;
}
//@ f_0de120
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Berechnet die noch freie Gesamt-Tragkraft (in Unzen) aller Mitglieder der Gruppe p1 als Summe der
 *   Differenzen zwischen maximaler Tragkraft (KK * 100) und aktueller Traglast (f_043170).
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die verbleibende freie Tragkraft der gesamten Gruppe zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de120(int *p1)
{
  short r = 0;
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) {
      short n = ((int)(f_043170((struct hero *)(c))));
      short m = f_042a40((struct hero *)(c), 6);
      m *= 100;
      if (n >= m) continue;
      r += m - n;
    }
  }
  return r;
}
//@ f_0de170
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Durchsucht die Mitglieder der Gruppe p1 in der Gruppenreihenfolge (f_038c80 / f_0391b0) nach dem
 *   ersten Helden, für den f_045820(hero, p2) nicht -1 ergibt, und liefert dessen Gruppenplatz-Index zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie das Prüfkriterium (p2).
 * - Rückgabewert: Gibt den Gruppenplatz-Index (0..6) des gefundenen Helden oder -1 zurück.
 === Ende Beschreibung === */
int ContextDC493::f_0de170(int p1, int p2)
{
  int c = f_038c80(p1);
  int r = -1;
  do {
    if (f_045820(c, (short)p2) != -1) { r = f_0dc020(p1, c); break; }
    c = f_0391b0(p1, c);
  } while (c != f_038c80(p1));
  return r;
}
//@ f_0de1c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Würfelt für alle Mitglieder der Gruppe p1 eine Talentprobe auf das Talent p2 mit dem Modifikator p3
 *   (f_044c90) und zählt, wie viele Helden die Probe verpatzen (< 0).
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1), die Talentkennung (p2) sowie der
 *   Probenmodifikator (p3).
 * - Rückgabewert: Gibt die Anzahl der misslungenen Talentproben zurück.
 === Ende Beschreibung === */
int ContextDC493::f_0de1c0(int *p1, short p2, short p3)
{
  int n = 0;
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) {
      if (f_044c90(c, (short)p2, (signed char)p3) < 0) n++;
    }
  }
  return n;
}
//@ f_0de210
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Tötet sämtliche Mitglieder der Gruppe p1, indem jedem Helden Schaden in Höhe seiner aktuellen
 *   Lebenspunkte (f_042960) über f_044300 zugefügt wird, und setzt das Gruppen-Aktualisierungsflag d_1c219c = 1.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0de210(int *p1)
{
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) f_044300(c, f_042960((struct hero *)(c)));
  }
  dc493_d_1c219c = 1;
}
//@ f_0de250
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt für jedes aktive Mitglied der Gruppe p1 eine Eigenschaftsprobe auf p2 mit Aufschlag p3
 *   (f_044900) durch: gibt bei Erfolg den Text p4 aus, bei Misserfolg den Text p5, zieht bei p6 <= 0
 *   Lebenspunkte (-p6) ab bzw. zerstört bei p6 > 0 den Schutzgegenstand p6 (f_033530) und wendet zusätzlich den
 *   Statuseffekt f_040a00(c, p7, p8) an.
 * - Eingaben: Übergeben werden der Gruppenzeiger (p1), die Eigenschaft (p2), die Erschwernis (p3), die
 *   Erfolgs-Text-ID (p4), die Misserfolgs-Text-ID (p5), der Schadens- bzw. Gegenstandswert (p6) sowie die
 *   Effektparameter (p7, p8).
 * - Rückgabewert: Gibt die Anzahl der Helden zurück, denen die Eigenschaftsprobe misslungen ist.
 === Ende Beschreibung === */
char ContextDC493::f_0de250(int *p1, int p2, int p3, int p4, int p5, short p6, int p7, int p8)
{
  Ctx x;
  signed char i;
  volatile signed char n;
  f_125400(&x, dc493_d_1c349c, dc493_d_1c3870, dc493_d_1c3498);
  n = 0;
  for (i = 0; i <= 6; ++i) {
    int c = p1[i];
    if (c != 0) {
      if (f_0d4a60(c) != 0) {
        if (f_044900(c, (short)p2, (short)p3) <= 0) {
          x.p[1] = c;
          f_0bf730((int)&dc493_d_1c2c64, p5);
          if (p6 <= 0) {
            p6 = -p6;
            f_044300(c, p6);
          } else {
            signed char q = f_0d4aa0(c, p6);
            if (q >= 0) f_033530(c, q);
          }
          f_040a00(c, (short)p7, (short)p8);
          ++n;
        } else {
          x.p[1] = c;
          f_0bf730((int)&dc493_d_1c2c64, p4);
        }
      }
    }
  }
  f_1254a0(&x, 0);
  return n;
}
//@ f_0de350
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt für jedes aktive Mitglied der Gruppe p1 eine Eigenschaftsprobe auf p2 mit Aufschlag p3
 *   (f_044900) durch, zeigt je nach Ausgang die Textmeldung p4 (Erfolg) oder p5 (Misserfolg) an und fügt bei
 *   Misserfolg p6 Schadenspunkte (f_044300) zu.
 * - Eingaben: Übergeben werden der Gruppenzeiger (p1), die Eigenschaft (p2), die Erschwernis (p3), die
 *   Erfolgs-Text-ID (p4), die Misserfolgs-Text-ID (p5) sowie der Schadenswert (p6).
 * - Rückgabewert: Gibt die Anzahl der Helden zurück, denen die Probe misslungen ist.
 === Ende Beschreibung === */
char ContextDC493::f_0de350(int *p1, int p2, short p3, int p4, int p5, short p6)
{
  Ctx x;
  signed char n, i;
  f_125400(&x, dc493_d_1c349c, dc493_d_1c3870, dc493_d_1c3498);
  n = 0;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) {
      if (f_0d4a60(c) != 0) {
        if (f_044900(c, (short)p2, (short)p3) <= 0) {
          x.p[1] = c;
          f_0bf730((int)&dc493_d_1c2c64, p5);
          f_044300(c, (short)p6);
          n++;
        } else {
          x.p[1] = c;
          f_0bf730((int)&dc493_d_1c2c64, p4);
        }
      }
    }
  }
  f_1254a0(&x, 0);
  return n;
}
//@ f_0de410
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt für jedes aktive Mitglied der Gruppe p1 still (ohne Textausgabe) eine Eigenschaftsprobe auf
 *   p2 mit Aufschlag p3 (f_044900) durch und zieht bei Misserfolg p4 Lebenspunkte (f_044300) ab.
 * - Eingaben: Übergeben werden der Gruppenzeiger (p1), die Eigenschaft (p2), die Erschwernis (p3) sowie der
 *   Schadenswert (p4).
 * - Rückgabewert: Gibt die Anzahl der Helden zurück, denen die Probe misslungen ist.
 === Ende Beschreibung === */
char ContextDC493::f_0de410(int *p1, int p2, short p3, short p4)
{
  signed char n = 0;
  signed char i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) {
      if (f_0d4a60(c) != 0) {
        if (f_044900(c, (short)p2, (short)p3) <= 0) {
          f_044300(c, (short)p4);
          n++;
        }
      }
    }
  }
  return n;
}
//@ f_0de480
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zählt über die gesamte Gruppe p1, wie viele Exemplare bzw. Ladungen des Gegenstands p2 vorhanden
 *   sind (f_035260), und erhöht den Zähler bei Abfrage von Dietrichen (p2 == 0x79) zusätzlich für jeden Helden
 *   mit Magie-/Schlossknacken-Stufe f_0432d0 >= 3.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt die ermittelte Gesamtanzahl zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de480(int *p1, int p2)
{
  short sum=0;
  short i=0;
  for (; (int)i<=6; ++i) {
    int object=p1[i];
    if (object) {
      if ((int)(short)p2==0x79) {
        int level=f_0432d0((struct hero *)(object));
        if (level>=3) ++sum;
      }
      sum+=f_035260(object,(short)p2);
    }
  }
  return sum;
}
//@ f_0de4d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Summiert den Modifikatorwert f_0459e0 über alle Mitglieder der Gruppe p1 auf (bricht bei einem
 *   Einzelwert von -5 sofort mit -5 ab) und begrenzt das Gesamtergebnis nach oben auf 5.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den summierten und auf [-5..5] begrenzten Gruppenwert zurück.
 === Ende Beschreibung === */
// Blind831 30.10.: Rueckgabe short, Vergleiche mit (short)-Konstanten -> cmp ax/cmp bx; f_0de540 springt in diesen Schluss
short ContextDC493::f_0de4d0(int *p1)
{
  short n = 0;
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) {
      short v = f_0459e0(c);
      if (v == (short)-5) { n = v; break; }
      n += v;
    }
  }
  if (n > (short)5) n = 5;
  return n;
}
//@ f_0de510
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht in der Gruppe p1 das erste Mitglied, für das die Prüfung f_0458b0(c) einen Wert >= 0 liefert.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt den Gruppenplatz-Index (0..6) des gefundenen Helden oder -1 zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de510(int *p1)
{
  short i;
  for (i = 0; i <= 6; i++) {
    int c;
    c = p1[i];
    if (c != 0) {
      if (f_0458b0(c) >= 0) return i;
    }
  }
  return -1;
}
//@ f_0de540
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Summiert das aktuell getragene Gesamtgewicht (f_043170) aller Mitglieder der Gruppe p1 auf.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt die gesamte aktuelle Traglast der Gruppe zurück.
 === Ende Beschreibung === */
short ContextDC493::f_0de540(int *p1)
{
  short n = 0;
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) n += ((int)(f_043170((struct hero *)(c))));
  }
  return n;
}
//@ f_0de570
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Summiert für alle Mitglieder der Gruppe p1 die Anzahl der freien Inventarplätze bzw. passenden
 *   Gegenstandsslots (f_0326d0(c, p2)) auf.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie das Filterkriterium (p2).
 * - Rückgabewert: Gibt die Gesamtzahl der gefundenen Plätze über die ganze Gruppe zurück.
 === Ende Beschreibung === */
int ContextDC493::f_0de570(int *p1, int p2)
{
  int n = 0;
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) n += f_0326d0(c, p2);
  }
  return n;
}
//@ f_0de5a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ruft für jedes Mitglied der Gruppe p1 die Statusfunktion f_043fd0(c, p2) auf.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der 8-Bit-Parameter (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0de5a0(int *p1, signed char p2)
{
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) f_043fd0(c, p2);
  }
}
//@ f_0de5d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ruft für jedes Mitglied der Gruppe p1 die Statusfunktion f_043ff0(c, p2) auf.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie der 8-Bit-Parameter (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void ContextDC493::f_0de5d0(int *p1, signed char p2)
{
  short i;
  for (i = 0; i <= 6; i++) {
    int c = p1[i];
    if (c != 0) f_043ff0(c, p2);
  }
}
