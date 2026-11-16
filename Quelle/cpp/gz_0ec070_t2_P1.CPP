/* === Beschreibung (Katalog) ===
 * Einheit gz_0ec070_t2
 *
 * Diese Einheit bildet den zweiten Teil der Schauplatz- und Ereignissteuerung aus gz_0ec070 und enthält weitere
 * Hilfs- und Interaktionsroutinen sowie die Lade-/Speicher-Anbindung für die lokalen Zustandsflags dieses
 * Spielabschnitts.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 6/7 gleich (suche.py 23.10.2026, Basis gz_0ec070_t2_P1.CPP)
// gz_0ec070.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0EC070-0x0ED980
#include <string.h>
#define DEC(x) (--(x))
#define INC(x) (++(x))
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_033530(int p1, int p2);                           // reg eax edx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_03eca0(int p1);                                   // reg eax stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0

                                   // reg eax stapel 0
                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
                                   // reg eax stapel 0
int f_0b9890(int p1);                                   // reg eax stapel 0
int f_0bac50(int p1, int p2);                           // reg eax edx stapel 0
int f_0bad80(int p1, int p2);                           // reg eax edx stapel 0
int f_0badf0(int p1, int p2);                           // reg eax stapel 0
int f_0baf80(int p1, int p2);                           // reg eax edx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bde40();                       // nicht in clobber.tsv
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bfa20();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0d6690(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dbda0(int p1);                                   // reg eax stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
                           // reg eax stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_11e6d0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
short f_1457e0(int p1);
int f_15f3d4(int p1, void *p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb620;                    // 0x1BB620
extern signed char d_1bca84;
extern int d_1bdaf8;                    // 0x1BDAF8
extern signed char d_1bed58;
extern int d_1bed6c;                    // 0x1BED6C
extern signed char d_1bed70;
extern signed char d_1bed7c;
extern signed char d_1bedb0;
extern signed char d_1bedf8;
extern signed char d_1bedfc;
extern signed char d_1bee00;
extern signed char d_1bee14;
extern int d_1bee1c;                    // 0x1BEE1C
extern signed char d_1bee20;
extern signed char d_1bee24;
extern signed char d_1bee28;
extern int d_1bf1ac;                    // 0x1BF1AC
extern int d_1bf230;                    // 0x1BF230
extern signed char d_1bfab8;
extern int d_1bfaec;                    // 0x1BFAEC
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c009c;
extern int d_1c00a0;                    // 0x1C00A0
extern int d_1c00a4;                    // 0x1C00A4
extern int d_1c00b0;                    // 0x1C00B0
extern int d_1c00bc;                    // 0x1C00BC
extern int d_1c00c0;                    // 0x1C00C0
extern signed char d_1c00cc;
extern signed char d_1c00d0;
extern int d_1c00d4;                    // 0x1C00D4
extern signed char d_1c00e0;
extern signed char d_1c00e4;
extern int d_1c01dc;                    // 0x1C01DC
extern signed char d_1c03b8;
extern int d_1c0c80;                    // 0x1C0C80
extern volatile int d_1c0c84; // haelt die Schreibfolge in f_0ed520 wie im Original
extern int d_1c0c88;                    // 0x1C0C88
extern int d_1c0ca4;                    // 0x1C0CA4
extern int d_1c0d64;                    // 0x1C0D64
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c3498;
extern int d_1bb634;
int f_14d0e4(int, ...);
int f_148534(int);
int f_145234(int p1, int p2);
int f_145254(int p1);
#include <stdarg.h>
#define GT(x,v) (((x)>(v))?1:0)
#define LT(x,v) (((x)<(v))?1:0)
#define EQ(x,v) (((x)==(v))?1:0)
#define EQI(x,v) (((x)==(v))?1:0)
typedef RivaTextContextData OB;

//@ f_0ed520
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verarbeitet eine weitere interaktive Raum- oder Objektaktion im Schauplatz, gibt
 *   beschreibende Texte aus, prüft Heldenattribute oder Gegenstände und verändert den lokalen Gebietsstatus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der ausgeführten Interaktion zurück.
 === Ende Beschreibung === */
void f_0ed520(void)
{
    int r;
    if (d_1bf1ac != 0)
        ((void (*)(int, int))(*(int *)(*(int *)(d_1bf1ac + 0x58) + 0x14)))(d_1bf1ac, 1);
    if (GT(d_1bed58, 0)) DEC(d_1bed58);
    if (GT(d_1c03b8, 0)) DEC(d_1c03b8);
    if (GT(d_1bedb0, 0)) DEC(d_1bedb0);
    if (GT(d_1bee00, 0)) DEC(d_1bee00);
    if (GT(d_1bedfc, 1)) DEC(d_1bedfc);
    if (GT(d_1c00cc, 0)) DEC(d_1c00cc);
    if (GT(d_1c00d0, 0)) DEC(d_1c00d0);
    if (GT(d_1c00e0, 0)) DEC(d_1c00e0);
    if (GT(d_1c00e4, 1)) DEC(d_1c00e4);
    if (GT(d_1bee14, 0) && LT(d_1bee14, 10)) INC(d_1bee14);
    if (GT(d_1bedf8, 0)) DEC(d_1bedf8);
    if (GT(d_1bee20, 0)) DEC(d_1bee20);
    if (GT(d_1bee24, 0)) DEC(d_1bee24);
    if (GT(d_1bee28, 0)) DEC(d_1bee28);
    if (d_1c0c80 == 1) {
        f_0b9890(1);
        d_1c0c80 = 0;
    }
    if (d_1c0c84 == 1) {
        d_1bca84 = 0;
        d_1c0c84 = 0;
        if (EQ(d_1bed7c, 1)) d_1bed70 = 1;
    }
    if (d_1c0c88 == 1) {
        f_0b9890(2);
        r = f_1457e0(100) <= 0x32;
        d_1bca84 = r;
        d_1c0c88 = 0;
    }
}
//@ f_0ed740
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt ein lokales Zustandsflag des Schauplatzes zurück oder initialisiert die
 *   Gebietsvariablen beim erstmaligen Betreten.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den gesetzten Statuswert zurück.
 === Ende Beschreibung === */
void f_0ed740(void)
{
    if (GT(d_1c009c, 0)) DEC(d_1c009c);
}
//@ f_0ed760
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft vor einem Gebietswechsel oder einer Rast, ob bestimmte Ereignisbedingungen im
 *   Schauplatz erfüllt sind, und löst gegebenenfalls eine zeitgesteuerte Zwischenszene aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder 0 je nach ausgelöster Aktion zurück.
 === Ende Beschreibung === */
int f_0ed760(void)
{
    OB ob;
    int s, e, v, r, ok;
    ok = 1;
    f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    s = f_039040(d_1c0004);
    e = f_0d6690(2);
    if ((s != 0 && EQI(d_1bfab8, 0)) || e != 0) {
        v = 0;
        if (s != 0 && (f_042400((struct hero *)(s)) == 3 || f_042400((struct hero *)(s)) == 1)) {
            if (f_0d4a60(s) == 0) {
                v = 0x360000a5;
                *(int *)(ob.addresses.objects + 4) = s;
            } else {
                if (f_042400((struct hero *)(s)) == 3)
                    v = 0x360000a7;
                else if (f_042400((struct hero *)(s)) == 1)
                    v = 0x360000a6;
            }
            if (v != 0) {
                OB o2;
                f_125400((int)&o2, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(o2.addresses.objects + 4) = s;
                r = f_0bf6f0((int)&d_1c2c64, v);
                if (r == 1)
                    f_0d64a0();
                else
                    ok = 0;
                f_1254a0((int)&o2, 0);
            }
        }
    }
    f_1254a0((int)&ob, 0);
    return ok;
}
//@ f_0ed890
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als leerer Platzhalter-Callback für Ereignisse dieses Schauplatzes, bei denen
 *   keine zusätzliche Aktion erforderlich ist.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert keinen definierten Rückgabewert.
 === Ende Beschreibung === */
int f_0ed890(int p1, int p2)
{
    int r = f_0bac50(p1, p2);
    *(int *)(r + 0xc) = (int)&d_1bb634;
    return r;
}
//@ f_0ed8a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion räumt beim Verlassen des Schauplatzes die lokal geladenen Ressourcen und Textpuffer
 *   wieder auf und setzt temporäre Szenenzeiger zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Aufräumoperation zurück.
 === Ende Beschreibung === */
int f_0ed8a0(int p, unsigned f)
{
    if (f & 4) {
        f_145254(f_145234(p, (int)&d_1bb620));
        return p;
    }
    *(int *)(p + 0xc) = (int)&d_1bb634;
    f_0badf0(p, 0);
    p = f_0bad80(p, 0);
    if (f & 2)
        operator delete((void *)p);
    return p;
}
//@ f_0ed8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die lokalen Zustandsvariablen und Flags des Schauplatzes gz_0ec070 beim
 *   Start eines neuen Spiels auf ihre Standardwerte.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_0ed8f0(int a, int b, ...)
{
    va_list ap;
    va_start(ap, b);
    f_11e6d0(3);
    f_14d0e4(f_0baf80(a, 0x29a0002));
    f_15f3d4(f_0baf80(a, b), ap);
    va_end(ap);
    f_148534(0x2a);
}
//@ f_0ed950
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest oder schreibt den lokalen Zustandblock des Schauplatzes gz_0ec070 beim Laden
 *   beziehungsweise Speichern eines Spielstands.
 * - Eingaben: Die Funktion erhält den Spielstands-Datenstrom (p1) sowie das Richtungsflag (p2, 0 für Laden, 1
 *   für Speichern).
 * - Rückgabewert: Die Funktion gibt 0 bei Erfolg oder einen Fehlercode ungleich null bei einem Dateifehler
 *   zurück.
 === Ende Beschreibung === */
void f_0ed950(int a, int b, ...)
{
    va_list ap;
    va_start(ap, b);
    f_15f3d4(f_0baf80(a, b), ap);
    va_end(ap);
}
