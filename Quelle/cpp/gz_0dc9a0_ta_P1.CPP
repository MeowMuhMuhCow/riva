/* === Beschreibung (Katalog) ===
 * Einheit gz_0dc9a0_ta (0dc9a0 - 0dcb60)
 *
 * Überblick
 * Die Einheit gz_0dc9a0_ta bildet den ersten Abschnitt des großen Gruppenverwaltungs-Moduls (party2.cpp /
 * gz_0dc9a0.cpp, 0x0dc9a0-0x0de600). Sie enthält Funktionen zum Aufrücken von Gruppenplätzen, zum Markieren von
 * Helden, die einen bestimmten Gegenstand ausrüsten können, sowie zum Entleeren von Wasserschläuchen.
 === Ende Beschreibung === */
#include "R_FIX.H"
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
//@ f_0dc9a0  groesse 144 B, 49 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schließt Lücken in den ersten 6 Heldenplätzen einer Gruppe (p1), indem nachfolgende
 *   Gruppenmitglieder bei einem leeren Platz (((int *)p1)[k] == 0) um einen Slot nach links verschoben werden.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dc9a0(int p1)
{
    int i;
    int j, v, m, k;
    for (i = 0; (k = (short)i) < 6; i++) {
        if (((int *)p1)[k] == 0) {
#if FIX_R077
            int any = 0;
            for (j = i + 1; (short)j <= 6; j++) {
                v = ((int *)p1)[(short)j];
                if (v != 0) { f_0451f0(v, -1); any = 1; }
            }
            m = (short)i;
            memmove((int *)p1 + m, (int *)p1 + (m + 1), (6 - m) * 4);
            ((int *)p1)[6] = 0;
            if (any) i--;
#else
            for (j = i + 1; (short)j <= 6; j++) {
                v = ((int *)p1)[(short)j];
                if (v != 0) f_0451f0(v, -1);
            }
            m = (short)i;
            memcpy((int *)p1 + m, (int *)p1 + (m + 1), (6 - m) * 4);
            ((int *)p1)[6] = 0;
#endif
        }
    }
}
//@ f_0dca30  groesse 176 B, 57 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft für alle Mitglieder der Gruppe p1, wer den Gegenstand p2 laut f_045960 benutzen bzw. anlegen
 *   darf, setzt die entsprechenden Markierungsflags in d_1c0e60[0..6] (bzw. d_1c0e78 für den NPC-Slot) und
 *   aktualisiert die Hervorhebung in der Heldenleiste über f_0bc3a0.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn mindestens ein Gruppenmitglied den Gegenstand verwenden kann, sonst 0.
 === Ende Beschreibung === */
int f_0dca30(int p1, int p2)
{
    int found = 0;
    short i;
    int k, j, e;
    for (i = 0; (k = i) < 7; i++) d_1c0e60[k] = 0;
    for (k = 0; (j = (short)k) <= 6; k++) {
        e = ((int *)p1)[j];
        if (e == 0) continue;
        if (((char)(f_042400((struct hero *)(e))))) {
            if (f_045960(e, (short)p2) != 0) { found = 1; d_1c0e78 = 1; }
        } else {
            if (f_045960(e, (short)p2) != 0) { found = 1; d_1c0e60[j] = 1; }
        }
    }
    f_0bc3a0((int)&d_1bf230);
    return found;
}
//@ f_0dcae0  groesse 128 B, 48 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Löscht bei allen Mitgliedern der Gruppe p1 den Durst (f_042930(actor, 0)) und setzt bei sämtlichen
 *   im Inventar mitgeführten Gegenständen mit der ID 0x1e (Trinkflasche/Wasserschlauch) die Füllstands- und
 *   Statuswerte (f_042d60, f_042dd0) zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Gruppen-Objekt (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn mindestens ein Gegenstand 0x1e im Gruppeninventar gefunden wurde, sonst 0.
 === Ende Beschreibung === */
int f_0dcae0(int p1)
{
    int result = 0;
    short i = 0;
    int actor;
    short j;
    for (; i <= 6; i++) {
        actor = ((int *)p1)[i];
        if (actor != 0) {
            ((int)(f_042930((struct hero *)(actor), 0)));
            for (j = 0; j < 0x1f; j++) {
                if (f_042a60((struct hero *)(actor), j) == 0x1e) {
                    f_042d60((struct hero *)(actor), j, 0);
                    f_042dd0((struct hero *)(actor), j, 0);
                    result = 1;
                }
            }
        }
    }
    return result;
}
