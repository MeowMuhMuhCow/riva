/* === Beschreibung (Katalog) ===
 * Einheit gz_0b9940 (Adresse 0x0b9940 - 0x0bac50)
 *
 * Diese Einheit umfasst vier eng miteinander verbundene Funktionsgruppen: erstens die
 * Watcom-Memberpointer-Trampolinfunktionen (f_0b9950 bis f_0ba060), über die das Gebäudesystem (location) die
 * Einrichtungs- und Eintritts-Methoden sämtlicher Stadthäuser in Riva aufruft; zweitens das vollständige System
 * zum Öffnen verschlossener Türen und Truhen in 3D-Dungeons (f_0ba070 bis f_0bab40, mit Gewalt/Brecheisen,
 * Dietrichen oder dem Zauber *Foramen Foraminor*); und drittens die Basismethoden des LXT-Textdatei-Lesers
 * (f_0bab50 bis f_0bac30).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 103/107 gleich (suche.py 30.10.2026, Basis gz_0b9940_P1.CPP)
// gz_0b9940.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B9940-0x0BAC50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_02cb00();                                         // reg - stapel 0
int f_02d440();                                         // reg - stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0390a0(int p1);                                   // reg eax stapel 0
int f_03d3d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0c5980();                                         // reg - stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de170(int p1, int p2);                           // reg eax edx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1bf1b8;                    // 0x1BF1B8
extern int d_1bf1bc;                    // 0x1BF1BC
extern int d_1bf1c0;                    // 0x1BF1C0
extern int d_1bf1c4;                    // 0x1BF1C4
extern int d_1bf1c8;                    // 0x1BF1C8
extern int d_1bf1cc;                    // 0x1BF1CC
extern int d_1bf1d0;                    // 0x1BF1D0
extern int d_1bf1d4;                    // 0x1BF1D4
extern int d_1bf1d8;                    // 0x1BF1D8
extern int d_1bf1dc;                    // 0x1BF1DC
extern int d_1bf1e0;                    // 0x1BF1E0
extern int d_1bf1e4;                    // 0x1BF1E4
extern int d_1bf1e8;                    // 0x1BF1E8
extern int d_1bf1ec;                    // 0x1BF1EC
extern int d_1bf1f0;                    // 0x1BF1F0
extern int d_1bf1f4;                    // 0x1BF1F4
extern int d_1bf1f8;                    // 0x1BF1F8
extern int d_1bf1fc;                    // 0x1BF1FC
extern int d_1bf200;                    // 0x1BF200
extern int d_1bf204;                    // 0x1BF204
extern int d_1bf208;                    // 0x1BF208
extern int d_1bf20c;                    // 0x1BF20C
extern int d_1bf210;                    // 0x1BF210
extern int d_1bf214;                    // 0x1BF214
extern int d_1bf218;                    // 0x1BF218
extern int d_1bf21c;                    // 0x1BF21C
extern int d_1bf220;                    // 0x1BF220
extern int d_1bf224;                    // 0x1BF224
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0c4c;                    // 0x1C0C4C
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (107), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1c3498;
extern char d_1bb278[];
#define A(x) ((int)&(x))
short f_0bf820(int, ...);
int f_1254a0(void *p1, int p2);
int f_125400(void *p1, int p2, int p3, int p4);
int f_144fbf(int, ...);
int f_1452bc(int);
int f_15eaf3(int);
int f_144e8b(int, int, int);
int f_15ebd6(int);
int f_145259(int);
#define SEL2 1
struct V3 { int a, b, c; };
struct T { short s0, s2, s4, s6, s8, s10; };
struct Loc { signed char *c; T *t; int o; V3 v1; V3 v2; short s24; };
struct Obj { int a; int *p4; int c; int *pc; int pad1[4]; short *p20; int pad2[6]; };
typedef int (*FP2)(void *);
typedef FP2 (*FP1)(void *);
short f_0ba300(Loc *p, short p2);
int f_0ba530(Loc *p);
int f_0ba640(Loc *p);
short f_0ba9c0(Loc *p);
int f_0ba3e0(Loc *p);
void f_0ba490(Loc *p);
void f_0ba4c0(Loc *p);
int f_0ba4e0(Loc *p);
int f_0ba840(Loc *p);
short f_0ba8c0(Loc *p);
unsigned short f_0ba920(Loc *p, short n);

void f_0b15f0(void);
void f_0b18f0(void);
void f_0b1920(void);
void f_0b2180(void);
void f_0b2510(void);
void f_0b2640(void);
void f_0b3a90(void);
void f_0b3c00(void);
void f_0b4680(void);
void f_0b49b0(void);
void f_0b4a10(void);
void f_0b4af0(void);
void f_0b4bc0(void);
void f_0b4d00(void);
void f_0b4d90(void);
void f_0b4e10(void);
void f_0b4eb0(void);
void f_0b4fc0(void);
void f_0b5060(void);
void f_0b5180(void);
void f_0b51f0(void);
void f_0b55e0(void);
void f_0b5820(void);
void f_0b58f0(void);
void f_0b5bc0(void);
void f_0b5be0(void);
void f_0b5c00(void);
void f_0b5dc0(void);
void f_0b5ed0(void);
void f_0b5ee0(void);
void f_0b6080(void);
void f_0b6140(void);
void f_0b6240(void);
void f_0b6530(void);
void f_0b6560(void);
void f_0b66c0(void);
void f_0b6810(void);
void f_0b6980(void);
void f_0b6b40(void);
void f_0b6d10(void);
void f_0b6d40(void);
void f_0b6d70(void);
void f_0b6da0(void);
void f_0b6dc0(void);
void f_0b6de0(void);
void f_0b6e50(void);
void f_0b6ed0(void);
void f_0b6f30(void);
void f_0b6f80(void);
void f_0b6fd0(void);
void f_0b7100(void);
void f_0b7150(void);
void f_0b71d0(void);
void f_0b7230(void);
void f_0b7310(void);
void f_0b7440(void);
void f_0b75e0(void);
void f_0b7660(void);
void f_0b7710(void);
void f_0b77d0(void);
void f_0b78f0(void);
void f_0b7a10(void);
void f_0b7af0(void);
void f_0b7b70(void);
void f_0b7cc0(void);
void f_0b7d50(void);
void *f_0bab40(void);
void *f_0bab30(void);
void *f_0bab20(void);
void *f_0bab10(void);
void *f_0bab00(void);
void *f_0baaf0(void);
void *f_0baae0(void);
//@ f_0b9940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion trägt die 16-Bit-Kennung a2 bei Offset +0x4e eines Location-Gebäudeobjekts p ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt sowie die 16-Bit-Kennung a2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0b9940(char *p) { return *(int *)(p + 0x54); }
//@ f_0b9950
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void f_0b9950(char *p, int v) { *(int *)(p + 0x54) = v; }
//@ f_0b9960
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b2640 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b2640 zurück.
 === Ende Beschreibung === */
void *f_0b9960(void) { return (void *)f_0b2640; }
//@ f_0b9970
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b2510 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b2510 zurück.
 === Ende Beschreibung === */
void *f_0b9970(void) { return (void *)f_0b2510; }
//@ f_0b9980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b2180 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b2180 zurück.
 === Ende Beschreibung === */
void *f_0b9980(void) { return (void *)f_0b2180; }
//@ f_0b9990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b1920 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b1920 zurück.
 === Ende Beschreibung === */
void *f_0b9990(void) { return (void *)f_0b1920; }
//@ f_0b99a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b18f0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b18f0 zurück.
 === Ende Beschreibung === */
void *f_0b99a0(void) { return (void *)f_0b18f0; }
//@ f_0b99b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b15f0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b15f0 zurück.
 === Ende Beschreibung === */
void *f_0b99b0(void) { return (void *)f_0b15f0; }
//@ f_0b99c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7d50 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7d50 zurück.
 === Ende Beschreibung === */
void *f_0b99c0(void) { return (void *)f_0b7d50; }
//@ f_0b99d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7cc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7cc0 zurück.
 === Ende Beschreibung === */
void *f_0b99d0(void) { return (void *)f_0b7cc0; }
//@ f_0b99e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void *f_0b99e0(void) { return (void *)((char *)f_0b3a90 + 0x170); }
//@ f_0b99f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b3c00 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b3c00 zurück.
 === Ende Beschreibung === */
void *f_0b99f0(void) { return (void *)f_0b3c00; }
//@ f_0b9a00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7b70 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7b70 zurück.
 === Ende Beschreibung === */
void *f_0b9a00(void) { return (void *)f_0b7b70; }
//@ f_0b9a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7af0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7af0 zurück.
 === Ende Beschreibung === */
void *f_0b9a10(void) { return (void *)f_0b7af0; }
//@ f_0b9a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7a10 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7a10 zurück.
 === Ende Beschreibung === */
void *f_0b9a20(void) { return (void *)f_0b7a10; }
//@ f_0b9a30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b78f0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b78f0 zurück.
 === Ende Beschreibung === */
void *f_0b9a30(void) { return (void *)f_0b78f0; }
//@ f_0b9a40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b77d0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b77d0 zurück.
 === Ende Beschreibung === */
void *f_0b9a40(void) { return (void *)f_0b77d0; }
//@ f_0b9a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7710 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7710 zurück.
 === Ende Beschreibung === */
void *f_0b9a50(void) { return (void *)f_0b7710; }
//@ f_0b9a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7660 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7660 zurück.
 === Ende Beschreibung === */
void *f_0b9a60(void) { return (void *)f_0b7660; }
//@ f_0b9a70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b75e0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b75e0 zurück.
 === Ende Beschreibung === */
void *f_0b9a70(void) { return (void *)f_0b75e0; }
//@ f_0b9a80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7440 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7440 zurück.
 === Ende Beschreibung === */
void *f_0b9a80(void) { return (void *)f_0b7440; }
//@ f_0b9a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7310 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7310 zurück.
 === Ende Beschreibung === */
void *f_0b9a90(void) { return (void *)f_0b7310; }
//@ f_0b9aa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7230 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7230 zurück.
 === Ende Beschreibung === */
void *f_0b9aa0(void) { return (void *)f_0b7230; }
//@ f_0b9ab0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b71d0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b71d0 zurück.
 === Ende Beschreibung === */
void *f_0b9ab0(void) { return (void *)f_0b71d0; }
//@ f_0b9ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7150 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7150 zurück.
 === Ende Beschreibung === */
void *f_0b9ac0(void) { return (void *)f_0b7150; }
//@ f_0b9ad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b7100 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b7100 zurück.
 === Ende Beschreibung === */
void *f_0b9ad0(void) { return (void *)f_0b7100; }
//@ f_0b9ae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6fd0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6fd0 zurück.
 === Ende Beschreibung === */
void *f_0b9ae0(void) { return (void *)f_0b6fd0; }
//@ f_0b9af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6f80 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6f80 zurück.
 === Ende Beschreibung === */
void *f_0b9af0(void) { return (void *)f_0b6f80; }
//@ f_0b9b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6f30 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6f30 zurück.
 === Ende Beschreibung === */
void *f_0b9b00(void) { return (void *)f_0b6f30; }
//@ f_0b9b10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6ed0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6ed0 zurück.
 === Ende Beschreibung === */
void *f_0b9b10(void) { return (void *)f_0b6ed0; }
//@ f_0b9b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6e50 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6e50 zurück.
 === Ende Beschreibung === */
void *f_0b9b20(void) { return (void *)f_0b6e50; }
//@ f_0b9b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6de0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6de0 zurück.
 === Ende Beschreibung === */
void *f_0b9b30(void) { return (void *)f_0b6de0; }
//@ f_0b9b40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6dc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6dc0 zurück.
 === Ende Beschreibung === */
void *f_0b9b40(void) { return (void *)f_0b6dc0; }
//@ f_0b9b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6da0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6da0 zurück.
 === Ende Beschreibung === */
void *f_0b9b50(void) { return (void *)f_0b6da0; }
//@ f_0b9b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6d70 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6d70 zurück.
 === Ende Beschreibung === */
void *f_0b9b60(void) { return (void *)f_0b6d70; }
//@ f_0b9b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6d40 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6d40 zurück.
 === Ende Beschreibung === */
void *f_0b9b70(void) { return (void *)f_0b6d40; }
//@ f_0b9b80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6d10 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6d10 zurück.
 === Ende Beschreibung === */
void *f_0b9b80(void) { return (void *)f_0b6d10; }
//@ f_0b9b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6b40 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6b40 zurück.
 === Ende Beschreibung === */
void *f_0b9b90(void) { return (void *)f_0b6b40; }
//@ f_0b9ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6980 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6980 zurück.
 === Ende Beschreibung === */
void *f_0b9ba0(void) { return (void *)f_0b6980; }
//@ f_0b9bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6810 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6810 zurück.
 === Ende Beschreibung === */
void *f_0b9bb0(void) { return (void *)f_0b6810; }
//@ f_0b9bc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b66c0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b66c0 zurück.
 === Ende Beschreibung === */
void *f_0b9bc0(void) { return (void *)f_0b66c0; }
//@ f_0b9bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6560 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6560 zurück.
 === Ende Beschreibung === */
void *f_0b9bd0(void) { return (void *)f_0b6560; }
//@ f_0b9be0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6530 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6530 zurück.
 === Ende Beschreibung === */
void *f_0b9be0(void) { return (void *)f_0b6530; }
//@ f_0b9bf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6240 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6240 zurück.
 === Ende Beschreibung === */
void *f_0b9bf0(void) { return (void *)f_0b6240; }
//@ f_0b9c00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6140 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6140 zurück.
 === Ende Beschreibung === */
void *f_0b9c00(void) { return (void *)f_0b6140; }
//@ f_0b9c10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b6080 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b6080 zurück.
 === Ende Beschreibung === */
void *f_0b9c10(void) { return (void *)f_0b6080; }
//@ f_0b9c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5ee0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5ee0 zurück.
 === Ende Beschreibung === */
void *f_0b9c20(void) { return (void *)f_0b5ee0; }
//@ f_0b9c30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void *f_0b9c30(void) { return (char *)f_0b5bc0 + 0x310; }
//@ f_0b9c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void *f_0b9c40(void)
{
    return (char *)f_0b5c00 + 0x2d0;
}
//@ f_0b9c50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void *f_0b9c50(void) { return (char *)f_0b5dc0 + 0x110; }
//@ f_0b9c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion die
 *   zugehörige Zielmethode (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes
 *   initialisieren kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void *f_0b9c60(void) { return (char *)f_0b5ee0 - 16; }
//@ f_0b9c70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5ed0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5ed0 zurück.
 === Ende Beschreibung === */
void *f_0b9c70(void) { return (void *)f_0b5ed0; }
//@ f_0b9c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5dc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5dc0 zurück.
 === Ende Beschreibung === */
void *f_0b9c80(void) { return (void *)f_0b5dc0; }
//@ f_0b9c90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5c00 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5c00 zurück.
 === Ende Beschreibung === */
void *f_0b9c90(void) { return (void *)f_0b5c00; }
//@ f_0b9ca0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5be0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5be0 zurück.
 === Ende Beschreibung === */
void *f_0b9ca0(void) { return (void *)f_0b5be0; }
//@ f_0b9cb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5bc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5bc0 zurück.
 === Ende Beschreibung === */
void *f_0b9cb0(void) { return (void *)f_0b5bc0; }
//@ f_0b9cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b58f0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b58f0 zurück.
 === Ende Beschreibung === */
void *f_0b9cc0(void) { return (void *)f_0b58f0; }
//@ f_0b9cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b3a90 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b3a90 zurück.
 === Ende Beschreibung === */
void *f_0b9cd0(void) { return (void *)f_0b3a90; }
//@ f_0b9ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5820 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5820 zurück.
 === Ende Beschreibung === */
void *f_0b9ce0(void) { return (void *)f_0b5820; }
//@ f_0b9cf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b55e0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b55e0 zurück.
 === Ende Beschreibung === */
void *f_0b9cf0(void) { return (void *)f_0b55e0; }
//@ f_0b9d00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b51f0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b51f0 zurück.
 === Ende Beschreibung === */
void *f_0b9d00(void) { return (void *)f_0b51f0; }
//@ f_0b9d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5180 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5180 zurück.
 === Ende Beschreibung === */
void *f_0b9d10(void) { return (void *)f_0b5180; }
//@ f_0b9d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b5060 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b5060 zurück.
 === Ende Beschreibung === */
void *f_0b9d20(void) { return (void *)f_0b5060; }
//@ f_0b9d30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4fc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4fc0 zurück.
 === Ende Beschreibung === */
void *f_0b9d30(void) { return (void *)f_0b4fc0; }
//@ f_0b9d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4eb0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4eb0 zurück.
 === Ende Beschreibung === */
void *f_0b9d40(void) { return (void *)f_0b4eb0; }
//@ f_0b9d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4e10 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4e10 zurück.
 === Ende Beschreibung === */
void *f_0b9d50(void) { return (void *)f_0b4e10; }
//@ f_0b9d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4d90 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4d90 zurück.
 === Ende Beschreibung === */
void *f_0b9d60(void) { return (void *)f_0b4d90; }
//@ f_0b9d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4d00 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4d00 zurück.
 === Ende Beschreibung === */
void *f_0b9d70(void) { return (void *)f_0b4d00; }
//@ f_0b9d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4bc0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4bc0 zurück.
 === Ende Beschreibung === */
void *f_0b9d80(void) { return (void *)f_0b4bc0; }
//@ f_0b9d90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4af0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4af0 zurück.
 === Ende Beschreibung === */
void *f_0b9d90(void) { return (void *)f_0b4af0; }
//@ f_0b9da0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4a10 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4a10 zurück.
 === Ende Beschreibung === */
void *f_0b9da0(void) { return (void *)f_0b4a10; }
//@ f_0b9db0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b49b0 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b49b0 zurück.
 === Ende Beschreibung === */
void *f_0b9db0(void) { return (void *)f_0b49b0; }
//@ f_0b9dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Einrichtungsfunktion
 *   f_0b4680 (aus gz_0b3300_t1) zurück, damit f_0b8a40 die Metadaten des jeweiligen Stadtgebäudes initialisieren
 *   kann.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b4680 zurück.
 === Ende Beschreibung === */
void *f_0b9dc0(void) { return (void *)f_0b4680; }
//@ f_0b9dd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
void f_0b9dd0(void)
{
  d_1bf1bc = 0; d_1bf1c0 = 0; d_1bf1c4 = 0; d_1bf1c8 = (int)f_0bab40;
  d_1bf1cc = 0; d_1bf1d0 = 0; d_1bf1d4 = 0; d_1bf1d8 = 0; d_1bf1dc = 0;
  d_1bf1e0 = (int)f_0bab30; d_1bf1e4 = 0; d_1bf1e8 = 0; d_1bf1ec = (int)f_0bab20;
  d_1bf1f0 = 0; d_1bf1f4 = 0; d_1bf1f8 = (int)f_0bab10; d_1bf1fc = 0; d_1bf200 = 0;
  d_1bf204 = (int)f_0bab00; d_1bf208 = 0; d_1bf20c = 0; d_1bf210 = (int)f_0baaf0;
  d_1bf214 = 0; d_1bf218 = 0; d_1bf21c = (int)f_0baae0; d_1bf220 = 0; d_1bf224 = 0;
}
//@ f_0b9eb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
int f_0b9eb0(void) { return 1; }
//@ f_0b9ec0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
int f_0b9ec0(Loc *p)
{
  Obj o;
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  o.p4[1] = p->o;
  f_0bf730(A(d_1c2c64), 0x606000e);
  short sc = f_145850(3, 6, 4);
  f_044300(p->o, sc);
  f_1254a0(&o, 0);
  return 0;
}
//@ f_0b9f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
int f_0b9f30(void) { f_02d440(); return 0; }
//@ f_0b9f40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
int f_0b9f40(Loc *p)
{
  Obj o; int v;
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  o.p4[1] = p->o;
  v = 0;
  switch ((unsigned short)p->s24) { case 1: v = 0x6060011; break; case 2: v = 0x6060010; break; case 3: v = 0x606000f; break; }
  if (v != 0) {
    f_0bf730(A(d_1c2c64), v);
    f_040900(p->o, 1);
    short sc = f_1457e0(6);
    f_044850(p->o, sc, 1);
  }
  f_1254a0(&o, 0);
  return 0;
}
//@ f_0b9ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Gebäude-Eintritts- und
 *   Ereignisfunktion die zugehörige Zielmethode (aus gz_0b5dc0_t1a-t1c) zurück, die beim Betreten des jeweiligen
 *   Stadthauses ausgeführt wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf die zugehörige Zielmethode zurück.
 === Ende Beschreibung === */
int f_0b9ff0(Loc *p)
{
  Obj o; int v;
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  o.p4[1] = p->o;
  v = 0;
  switch ((unsigned short)p->s24) { case 1: v = 0x6060014; break; case 2: v = 0x6060013; break; case 3: v = 0x6060012; break; }
  if (v != 0) {
    f_0bf730(A(d_1c2c64), v);
    f_040900(p->o, 2);
    short sc = f_1457e0(6);
    f_044850(p->o, sc, 1);
  }
  f_1254a0(&o, 0);
  return 0;
}
//@ f_0ba0a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignis-Callback-Funktion löst die Dungeon-Aktion f_02cb00 aus und meldet den Vorgang als
 *   abgeschlossen (1).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0ba0a0(void) { f_02cb00(); return 1; }
//@ f_0ba0b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Callback-Funktion prüft nach dem Öffnen eines Schlosses, ob die Öffnung nicht durch den Zauber
 *   *Foramen Foraminor* (p->s24 != 3) erfolgte, und löst in diesem Fall über f_0c5980 eine mechanische Falle
 *   oder Sonderreaktion aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Schloss-Interaktionsstruktur Loc entgegen.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
int f_0ba0b0(Loc *p) { if ((short)p->s24 != 3) f_0c5980(); return 0; }
//@ f_0ba0d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Schloss-Interaktionsobjekt (Loc), speichert die
 *   Schwierigkeitswerte c und die Schloss-Konfiguration t, ermittelt den Gruppenanführer (f_038c40), lädt die
 *   beiden Memberfunktionszeiger v1 und v2 aus den Tabellen d_1bf1bc bzw. d_1bf1d4 und schaltet den Dialogmodus
 *   5 (f_0bf6c0) ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt, das Array der Proben-Zuschläge c sowie den
 *   Konfigurationszeiger t entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p zurück.
 === Ende Beschreibung === */
Loc *f_0ba0d0(Loc *p, signed char *c, T *t)
{
  p->c = c;
  p->t = t;
  p->o = f_038c40(d_1c0004);
  V3 *d1 = &p->v1;
  V3 *s1 = &((V3 *)&d_1bf1bc)[p->t->s0];
  d1->a = s1->a;
  d1->b = s1->b;
  d1->c = s1->c;
  V3 *d2 = &p->v2;
  V3 *s2 = &((V3 *)&d_1bf1d4)[p->t->s2];
  d2->a = s2->a;
  d2->b = s2->b;
  d2->c = s2->c;
  p->s24 = 0;
  f_0bf6c0(A(d_1c2c64), 5);
  return p;
}
//@ f_0ba160
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor beendet die Schloss-Interaktion und stellt über f_0bf680 den vorherigen
 *   Dialogzustand wieder her.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt sowie ein ungenutztes zweites Argument x
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p zurück.
 === Ende Beschreibung === */
Loc *f_0ba160(Loc *p, int x) { f_0bf680(A(d_1c2c64)); return p; }


//@ f_0ba180
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hauptfunktion steuert den gesamten Vorgang zum Öffnen einer verschlossenen Tür oder Truhe: Sie
 *   prüft zunächst einen etwaigen Spezial-Handler (v1), kontrolliert dann, ob die Gruppe den passenden Schlüssel
 *   oder Gegenstand besitzt (f_0ba300), und bietet andernfalls das Auswahlmenü (f_0ba3e0: Gewalt, Dietriche oder
 *   Zauber) an; bei Erfolg werden Meldung (f_0ba490) und Abenteuerpunkte (f_0ba4c0) vergeben, bei Misserfolg der
 *   Fehlschlag-Handler (v2) aufgerufen.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Schloss-Interaktionsobjekt Loc entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss geöffnet wurde, oder 0, wenn es verschlossen
 *   bleibt.
 === Ende Beschreibung === */
int f_0ba180(Loc *p)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  int r = 0;
  V3 *v;
  d_1c0c4c = d_1c0c4c + 1;
  if (p->v1.a) {
    v = &p->v1;
    p = (Loc *)((char *)p + v->b);
    goto indirect;
  }
  { int p2 = p->t->s4;
    if (p2 != 0 || (p2 = p->t->s6) != 0) r = ((int (*)(Loc *, int))f_0ba300)(p, p2);
  }
  if (r == 0) r = f_0ba3e0(p);
  if (r == 1) { f_0ba490(p); f_0ba4c0(p); }
  else {
    int has_v2 = p->t->s2;
    r = 0;
    if (has_v2 == 0) {
      if (d_1bf1b8 == 0) f_0bf730(A(d_1c2c64), 0x606000d);
    } else {
      v = &p->v2;
      r += v->b;
      p = (Loc *)((char *)p + r);
      goto indirect;
    }
  }
  goto done;
indirect:
  { FP2 f = ((FP1)v->a)(p); r = f(p); }
done:
  d_1c0c4c--;
  return r;
}
//@ f_0ba300
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob die Heldengruppe den für das Schloss erforderlichen Schlüssel oder
 *   Spezialgegenstand (p->t->s4 im Gruppeninventar f_0de170 bzw. p->t->s6 über f_0d54f0) mitführt. Ist der
 *   Gegenstand vorhanden, wird das Schließgeräusch (0x6000c) abgespielt und die Erfolgsmeldung 0x6060001 (Tür
 *   mit passendem Schlüssel geöffnet) ausgegeben.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt sowie die Gegenstandskennung p2 des benötigten
 *   Schlüssels entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der passende Schlüssel vorhanden war und das Schloss geöffnet
 *   hat, andernfalls 0.
 === Ende Beschreibung === */
short f_0ba300(Loc *p, short p2)
{
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  short result = 0;
  short r = -1;
  if ((short)p2 == p->t->s4) r = f_0de170(d_1c0004, p->t->s4);
  else if ((short)p2 == p->t->s6) r = f_0d54f0(d_1c0004, p->t->s6);
  if (r != -1) {
    Obj o;
    f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
    { int t_ = d_1a9820; f_147323(A(d_1c2edc), 0x6000c, 0x7fff, 0x8000, t_, 0, 1); }
    o.p4[1] = p->o;
    int *tab = (int *)*(int *)&d_1c2c40;
    ((int *)o.pc)[1] = tab[(int)p2];
    o.p20[1] = 1;
    f_0bf730(A(d_1c2c64), 0x6060001);
    result = 1;
    f_1254a0(&o, 0);
  }
  return result;
}

//@ f_0ba3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt vor einer verschlossenen Tür oder Truhe das Auswahlmenü (0x6060002) mit den drei
 *   Optionen an: mit Gewalt aufbrechen (f_0ba530), mit Dietrichen knacken (f_0ba640) oder mit Magie öffnen
 *   (f_0ba9c0). Gelingt eine der drei Methoden, wird das Öffnungsgeräusch (0x60007) abgespielt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss durch die gewählte Aktion geöffnet wurde, oder 0
 *   bei Misserfolg bzw. Abbruch.
 === Ende Beschreibung === */
int f_0ba3e0(Loc *p)
{
  int r = 0;
  d_1bf1b8 = 0;
  switch ((unsigned short)f_0bf820(A(d_1c2c64), 0x6060002, 3, 0x6060003, 0x6060004, 0x6060005)) {
    case 1: r = f_0ba530(p); break;
    case 2: r = f_0ba640(p); break;
    case 3: r = ((int (*)(Loc *))f_0ba9c0)(p); break;
    default: d_1bf1b8 = 1; break;
  }
  if (r != 0) { int *q = &d_1a9820; int t_ = *q; f_147323(A(d_1c2edc), 0x60007, 0x7fff, 0x8000, t_, 0, 1); }
  return r;
}
//@ f_0ba490
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt nach dem erfolgreichen Öffnen eines Schlosses eine schlossspezifische
 *   Zusatzmeldung (p->t->s8 + 0x6060015) aus, sofern im Feld s8 ein Offset hinterlegt ist.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ba490(Loc *p)
{
  int n = p->t->s8;
  if (n) f_0bf730(A(d_1c2c64), *(volatile short *)&p->t->s8 + 0x6060015);
}
//@ f_0ba4c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion schreibt dem öffnenden Helden (p->o) nach dem erfolgreichen Überwinden eines
 *   Schlosses die in p->t->s10 hinterlegten Abenteuerpunkte (f_040780) gut.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ba4c0(Loc *p)
{
  int p2 = p->t->s10;
  if (p2 != 0) f_040780(p->o, p2);
}
//@ f_0ba4e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das Scheitern eines Öffnungsversuchs: Ist kein spezieller Fehlschlag-Handler
 *   (p->t->s2 == 0) eingetragen und wurde nicht abgebrochen (d_1bf1b8 == 0), gibt sie die Standardmeldung
 *   0x606000d aus, andernfalls ruft sie den Memberfunktionszeiger p->v2 auf.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 0 oder den Rückgabewert des aufgerufenen Fehlschlag-Handlers v2 zurück.
 === Ende Beschreibung === */
int f_0ba4e0(Loc *p)
{
  int r = 0;
  if (p->t->s2 == 0) {
    if (d_1bf1b8 == 0) f_0bf730(A(d_1c2c64), 0x606000d);
  } else {
    V3 *v = &p->v2;
    void *q = (char *)p + v->b;
    FP2 f = ((FP1)v->a)(q);
    r = f(q);
  }
  return r;
}
//@ f_0ba840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion führt einen einzelnen Versuch aus, ein Schloss mit Dietrichen über eine
 *   Schlösser-Talentprobe (0x30, Erschwernis p->c[1]) zu knacken, spielt das Dietrich-Geräusch (0x60008) ab und
 *   lässt 5 Minuten Spielzeit (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Schlösser-Probe gelungen ist (und die Erschwernis kleiner
 *   als 99 war), andernfalls 0.
 === Ende Beschreibung === */
int f_0ba840(Loc *p)
{
  int f_147323u(int, int, int, int, int, int, int);
#pragma aux f_147323u "f_147323" modify [esp];
  short sc = p->c[1];
  int r = 0;
  { int t_ = (int)(d_1a9820); f_147323u(A(d_1c2edc), 0x60008, 0x7fff, 0x8000, t_, 0, 1); }
  if (sc < 99) {
    short s = f_044c90(p->o, 0x30, (signed char)sc);
    if (s >= 0) r = 1;
  }
  f_125ed0(A(d_1c2c44), 5);
  return r;
}
//@ f_0ba8c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler nach einem misslungenen Dietrich-Versuch über ein
 *   Zahlen-Eingabefenster (0x6060009, Bereich 0 bis 10), wie viele weitere Male der Held versuchen soll, das
 *   Schloss zu knacken.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt die vom Spieler gewählte Anzahl weiterer Versuche (0 bis 10) zurück.
 === Ende Beschreibung === */
short f_0ba8c0(Loc *p)
{
  Obj o;
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  o.p4[1] = p->o;
  short r = f_0bf7b0(A(d_1c2c64), 2, 0x6060009, 0, 10, 3);
  if ((short)r < 0) r = 0;
  f_1254a0(&o, 0);
  return r;
}
//@ f_0ba920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt bis zu n aufeinanderfolgende Schlösser-Talentproben (0x30, Erschwernis p->c[1])
 *   zum Knacken eines Schlosses aus, wobei je Versuch 2 Minuten Spielzeit (f_125ed0) vergehen und die Schleife
 *   sofort endet, sobald ein Versuch gelingt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt sowie die gewünschte Versuchsanzahl n entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss innerhalb der n Versuche geknackt wurde,
 *   andernfalls 0.
 === Ende Beschreibung === */
unsigned short f_0ba920(Loc *p, short n)
{
  int f_147323u(int, int, int, int, int, int, int);
#pragma aux f_147323u "f_147323" modify [esp];
  int r = 0;
  short sc = p->c[1];
  int i = 0;
  if (n > 0) {
    int snd = d_1a9820;
    f_147323u(A(d_1c2edc), 0x60008, 0x7fff, 0x8000, snd, r, 1);
  }
  while ((short)i < n && r == 0) {
    if (sc < 99) {
      short s = f_044c90(p->o, 0x30, (signed char)sc);
      if (s >= 0) r = 1;
    }
    f_125ed0(A(d_1c2c44), 2);
    i++;
  }
  return r;
}

//@ f_0ba530
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt den Versuch ab, ein Schloss oder eine Tür mit Gewalt aufzubrechen (s24 = 1):
 *   Sie spielt einen geschlechtsabhängigen Kampfschrei (0x2000d/0x2000e) ab, gewährt bei vorhandenem Brecheisen
 *   (0x1a über f_0d54f0) eine Erleichterung von 2 Punkten auf den Zuschlag *p->c und würfelt eine
 *   Körperkraftprobe (6, f_044900) für den Anführer p->o.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss gewaltsam aufgebrochen wurde, oder 0 bei einem
 *   Fehlschlag (oder wenn das Schloss mit *p->c == 99 unaufbrechbar ist).
 === Ende Beschreibung === */
int f_0ba530(Loc *p)
{
  int f_147323u(int, int, int, int, int, int, int);
#pragma aux f_147323u "f_147323" modify [esp];
  Obj o;
  int r = 0;
  short s = *p->c;
  int c1 = (unsigned char)((signed char)((int)(f_042380((struct hero *)(p->o)))) == 1);
  { int t_ = d_1a9820; f_147323u(A(d_1c2edc), c1 + 0x2000d, 0x7fff, 0x8000, t_, 0, 1); }
  if (s != 99) {
    short t = f_0d54f0(d_1c0004, 0x1a);
    if (t != -1) s = s - 2;
    short v = f_044900(p->o, 6, s);
    if (v > 0) {
      { int t_ = d_1a9820; f_147323(A(d_1c2edc), 0x60007, 0x7fff, 0x8000, t_, 0, 1); }
      r = 1;
    } else if (p->v2.a == 0) {
      f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
      o.p4[1] = (p->o & 0) ? 0 : p->o; // haelt die Registerzuteilung wie im Original
      f_0bf730(A(d_1c2c64), 0x606000a);
      f_1254a0(&o, 0);
    }
    p->s24 = 1;
  }
  return r;
}
//@ f_0ba640
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Knacken eines Schlosses mit Dietrichen (s24 = 2): Sie prüft zunächst, ob
 *   die Gruppe Dietriche oder Haarnadeln besitzt (0x23 über f_0d54f0), führt den ersten Öffnungsversuch (0x30)
 *   durch und erlaubt dem Spieler bei Misserfolg in einer Schleife (0x6060009), bis zu 10 Folgeversuche am Stück
 *   durchzuführen.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss geknackt wurde, oder 0, wenn kein Werkzeug
 *   vorhanden war oder alle Versuche scheiterten.
 === Ende Beschreibung === */
int f_0ba640(Loc *p)
{
  struct Ctx {
    Obj o;
    Ctx() { f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498)); }
    ~Ctx() { f_1254a0(&o, 0); }
  };
  int f_147323u(int, int, int, int, int, int, int);
#pragma aux f_147323u "f_147323" modify [esp];
  int f_0d54f0i(int, int);
#pragma aux f_0d54f0i "f_0d54f0";
  short sc = 0;
  short cnt = 1;
  Ctx o;
  int r = 0;
  if ((short)f_0d54f0i(d_1c0004, 0x23) != -1) {
    sc = p->c[1];
    int snd = d_1a9820;
    f_147323u(A(d_1c2edc), 0x60008, 0x7fff, 0x8000, snd, r, 1);
    if (sc < 99) {
      if ((short)f_044c90(p->o, 0x30, (signed char)sc) >= 0) r = 1;
    }
    f_125ed0(A(d_1c2c44), 5);
    if (p->v2.a == 0) {
      while (!r && (short)cnt > 0) {
        int val;
        {
          Ctx o2;
          o2.o.p4[1] = p->o;
          val = f_0bf7b0(A(d_1c2c64), 2, 0x6060009, 0, 10, 3);
          if ((short)val < 0) val = 0;
        }
        cnt = val;
        if ((short)cnt > 0) {
          struct Again {
            static int run(Loc *q, short n) {
              int f_147323u(int, int, int, int, int, int, int);
              int r = 0;
              short i = 0;
              short sc2 = q->c[1];
              if (n > 0) {
                int snd2 = d_1a9820;
                f_147323u(A(d_1c2edc), 0x60008, 0x7fff, 0x8000, snd2, r, 1);
              }
              while (i < n && !r) {
                if (sc2 < 99) {
                  if ((short)f_044c90(q->o, 0x30, (signed char)sc2) >= 0) r = 1;
                }
                f_125ed0(A(d_1c2c44), 2);
                i++;
              }
              return r;
            }
          };
          r = Again::run(p, cnt);
          d_1a9820 = (d_1a9820 & 0) ? 0 : d_1a9820; // haelt die Ladereihenfolge wie im Original
          d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt die Ladereihenfolge wie im Original
        }
      }
    }
    p->s24 = 2;
  } else {
    f_0bf730(A(d_1c2c64), 0x6060006);
  }
  { int keep = d_1c0004; d_1c0004 = keep; } // haelt die Registerzuteilung wie im Original
  { int keep = d_1a9820; d_1a9820 = keep; } // haelt die Registerzuteilung wie im Original
  return r;
}
//@ f_0ba9c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermöglicht das magische Öffnen eines Schlosses mit dem Zauber *Foramen Foraminor*
 *   (0x1c, s24 = 3): Sie prüft, ob ein Zauberkundiger in der Gruppe ist (f_0390a0), lässt ihn auswählen
 *   (0x6060008), kontrolliert, ob er mindestens 5 Astralpunkte besitzt (f_0429a0), legt eine Zauberprobe mit dem
 *   Zuschlag p->c[2] ab (f_03d3d0) und zieht anschließend 5 Astralpunkte (f_044230) ab.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Loc-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der *Foramen*-Zauber gelang, oder 0 bei Fehlschlag bzw.
 *   Abbruch.
 === Ende Beschreibung === */
short f_0ba9c0(Loc *p)
{
  int f_147323u(int, int, int, int, int, int, int);
#pragma aux f_147323u "f_147323" modify [esp];
  Obj o;
  int r = 0;
  int i = f_0390a0(d_1c0004);
  if (i == 0) { f_0bf730(A(d_1c2c64), 0x6060007); return r; }
  short s = p->c[2];
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  i = f_038e10(d_1c0004, 0x6060008);
  p->o = i;
  if (i != 0) {
    int c1 = (unsigned char)((signed char)((int)(f_042380((struct hero *)(i)))) != 0);
    { int t_ = d_1a9820; f_147323u(A(d_1c2edc), c1 + 0x6000a, 0x7fff, 0x8000, t_, r, 1); }
    short sv = ((int)(f_0429a0((struct hero *)(p->o))));
    if ((int)(short)(sv) >= (short)5 && s < 99 && (sv = f_03d3d0(p->o, 0x1c, (signed char)s)) > 0) r = 1;
    else {
      if (p->v2.a == 0) {
        o.p4[1] = (p->o & 0) ? 0 : p->o; // haelt die Registerzuteilung wie im Original
        f_0bf730(A(d_1c2c64), 0x606000c);
      }
    }
    f_044230(p->o, 5);
    p->s24 = 3;
  }
  f_1254a0(&o, 0);
  return r;
}

//@ f_0baae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0ba0b0 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0ba0b0 zurück.
 === Ende Beschreibung === */
void *f_0baae0(void) { return (void *)f_0ba0b0; }
//@ f_0baaf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0ba0a0 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0ba0a0 zurück.
 === Ende Beschreibung === */
void *f_0baaf0(void) { return (void *)f_0ba0a0; }
//@ f_0bab00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0b9ff0 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b9ff0 zurück.
 === Ende Beschreibung === */
void *f_0bab00(void) { return (void *)f_0b9ff0; }
//@ f_0bab10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0b9f40 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b9f40 zurück.
 === Ende Beschreibung === */
void *f_0bab10(void) { return (void *)f_0b9f40; }
//@ f_0bab20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0b9f30 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b9f30 zurück.
 === Ende Beschreibung === */
void *f_0bab20(void) { return (void *)f_0b9f30; }
//@ f_0bab30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0b9ec0 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b9ec0 zurück.
 === Ende Beschreibung === */
void *f_0bab30(void) { return (void *)f_0b9ec0; }
//@ f_0bab40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Watcom-Memberpointer-Trampolinfunktion liefert die Adresse der Schloss-Ereignisfunktion
 *   f_0b9eb0 zurück, die vor oder nach dem Öffnen eines speziellen Dungeon-Schlosses aufgerufen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_0b9eb0 zurück.
 === Ende Beschreibung === */
void *f_0bab40(void) { return (void *)f_0b9eb0; }
//@ f_0bab50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Dateilade-Hilfsfunktion öffnet eine Datei p2 über das Archiv-/Dateisystem (f_144fbf), ermittelt
 *   ihre Bytegröße (f_1452bc), reserviert einen passenden Heap-Puffer (malloc, f_15eaf3) und liest den gesamten
 *   Dateiinhalt in Blöcken zu 32 KB (0x8000) ein.
 * - Eingaben: Die Funktion nimmt den ungenutzten this-Zeiger p1 sowie die Dateikennung bzw. den Dateinamen p2
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den frisch geladenen Dateipuffer im Heap oder 0 bei einem
 *   Lesefehler zurück.
 === Ende Beschreibung === */
int f_0bab50(int p1, int p2)
{
  int buf = 0, h, len, off, n;
  if (p2 != 0) {
    h = f_144fbf(p2, 0);
    if (h != -1) {
      len = f_1452bc(h);
      if (len > 0) {
        buf = f_15eaf3(len);
        if (buf != 0) {
          off = 0;
          if (len > 0) {
            do {
              n = f_144e8b(h, buf + off, 0x8000);
              if (n <= 0) { f_15ebd6(buf); buf = 0; break; }
              off += n;
            } while (off < len);
          }
        }
      }
      f_145259(h);
    }
  }
  return buf;
}
//@ f_0babc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion gibt sowohl das Zeiger-Array p[1] (tab) als auch den Rohdatenpuffer p[0] (hdr)
 *   eines LXT-Textleserobjekts über free (f_15ebd6) frei und setzt beide Zeiger auf 0.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LXT-Leserobjekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0babc0(int *p)
{
  if (p[1] != 0) { f_15ebd6(p[1]); p[1] = 0; }
  if (*p != 0) { f_15ebd6(*p); *p = 0; }
}
//@ f_0bac00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion gibt den Zeiger auf den geladenen Dateikopf (*p) eines LXT-Textleserobjekts
 *   zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LXT-Leserobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt den 32-Bit-Zeiger *p (hdr) zurück.
 === Ende Beschreibung === */
int f_0bac00(int *p) { return *p; }
//@ f_0bac10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest die 16-Bit-Anzahl der enthaltenen Textzeilen aus dem LXT-Dateikopf bei
 *   Offset +8 (*(short *)(*p + 8)), sofern eine Datei geladen ist.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LXT-Leserobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt die Anzahl der Textzeilen in der geladenen LXT-Datei oder 0 zurück.
 === Ende Beschreibung === */
short f_0bac10(int *p)
{
  short r = 0;
  if (*p != 0) r = *(short *)(*p + 8);
  return r;
}
//@ f_0bac30
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Basiskonstruktor initialisiert ein leeres LXT-Textleserobjekt, indem er den Dateikopf-Zeiger
 *   p[0] und den Tabellenzeiger p[1] auf 0 setzt und die virtuelle Methodentabelle d_1bb278 in p[2] einträgt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das zu initialisierende LXT-Leserobjekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bac30(int *p)
{
  p[2] = (int)d_1bb278;
  p[1] = 0;
  *p = 0;
}

