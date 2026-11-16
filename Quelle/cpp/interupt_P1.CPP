/* === Beschreibung (Katalog) ===
 * Einheit interupt (0x0A7610 - 0x0A77F0)
 *
 * Diese Einheit enthält die zentrale periodische Hintergrund- und Interrupt-Routine für Benutzeroberfläche,
 * Spielstand- und Statussynchronisation, Leerlauferkennung (Bildschirmschoner-Zähler) und Mauszeiger-Steuerung
 * (aus p:\riva\source\cpp\intface.cpp).
 === Ende Beschreibung === */
// P3 1/1 gleich (suche.py 25.10.2026, Basis interupt_P1.CPP)
// interupt.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A7610-0x0A77F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
void f_0d26e0();                                         // reg - stapel 0
int f_0ddd60(int p1);                                   // reg eax stapel 0
int f_0ddf50(int p1);                                   // reg eax stapel 0
int f_0ddfc0(int p1);                                   // reg eax stapel 0
int f_0de840(int p1);                                   // reg eax stapel 0
int f_0de850(int p1, int p2);                           // reg eax edx stapel 0
int f_0de860(int p1);                                   // reg eax stapel 0
int f_0de870(int p1, int p2);                           // reg eax edx stapel 0
int f_0de880(int p1);                                   // reg eax stapel 0
int f_0de890(int p1, int p2);                           // reg eax edx stapel 0
short f_0de8c0(int p1);                                   // reg eax stapel 0
short f_0de920(int p1);                                   // reg eax stapel 0
int f_0de930(int p1, short p2);                           // reg eax edx stapel 0
int f_0de940(int p1, short p2);                           // reg eax edx stapel 0
char f_0de970(int p1);                                   // reg eax stapel 0
int f_15164c();                                         // reg - stapel 0
int f_153ac8();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a3e84;                    // 0x1A3E84
extern int d_1a3e88;                    // 0x1A3E88
extern int d_1a3e8c;                    // 0x1A3E8C
extern int d_1a80c4;                    // 0x1A80C4
extern short d_1a89a8;                    // 0x1A89A8
extern char d_1a9942;                    // 0x1A9942
extern char d_1a9949;                    // 0x1A9949
extern short d_1a9960;                    // 0x1A9960
extern short d_1a9962;                    // 0x1A9962
extern int d_1a99a0;                    // 0x1A99A0
extern int d_1a99a4;                    // 0x1A99A4
extern int d_1a99a8;                    // 0x1A99A8
extern unsigned char d_1a9a1c;                    // 0x1A9A1C
extern short d_1be24c;                    // 0x1BE24C
extern short d_1be250;                    // 0x1BE250
extern int d_1c0004;                    // 0x1C0004
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c4;                    // 0x1C90C4
extern int d_1c90c8;                    // 0x1C90C8
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_0a7610  groesse 480 B, 212 Bef, reg ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die zyklische Status- und Interrupt-Pflege der globalen Spielsteuerung (d_1c0004)
 *   durch: Sie synchronisiert bei anstehenden Anforderungen den aktuellen Zustand und die drei Statuswerte
 *   (d_1c90c0, d_1c90c4, d_1c90c8), setzt die Basisauflösungsparameter (Breite 320 Pixel in d_1a99a0), überwacht
 *   im Modus 0xf018 bei gesetztem Flag (d_1a9a1c & 0x40) unveränderte Positions- und Blickwerte über mehr als 20
 *   Ticks (d_1be24c) zur Auslösung einer Leerlauf-Aktion (f_0ddd60), blendet bei Bedarf den Mauszeiger wieder
 *   ein (f_0d26e0) und schließt offene Sperren (f_0ddf50).
 * - Eingaben: Die Funktion nimmt keine direkten Parameter entgegen, sondern arbeitet auf dem globalen
 *   Steuerkontext d_1c0004 sowie den globalen Status- und Zählerfeldern.
 * - Rückgabewert: Die Funktion gibt den Erfolgs- bzw. Synchronisationsstatus (1 oder das Ergebnis von f_15164c)
 *   zurück; ist jedoch beim Eintritt kein Statuswechsel in f_0de920(d_1c0004) aktiv, gibt sie versehentlich
 *   einen uninitialisierten Registerwert (ebx) zurück (siehe Fehlerliste).
 === Ende Beschreibung === */

inline int NE(int a, int b) { return a != b; }

int f_0a7610(void)
{
    int r;
    int c, b, a, a2, b2, c2;
    short s;
    if (f_0de920(d_1c0004)) {
        f_0ddfc0(d_1c0004);
        d_1a9942 = 1;
        r = 1;
        if (f_0de920(d_1c0004) == 2) {
            d_1a9960 = d_1a80c4;
            r = f_15164c();
            if (r) {
                f_0de850(d_1c0004, d_1c90c0);
                f_0de870(d_1c0004, d_1c90c4);
                f_0de890(d_1c0004, d_1c90c8);
            }
        }
        f_0de930(d_1c0004, NE(r, 0) - 1);
    }
    d_1a9949 = f_0de970(d_1c0004);
    d_1a99a0 = 0x140;
    d_1a99a4 = 0;
    d_1a99a8 = 0;
    if (f_153ac8() == 0xf018) {
        if (d_1a9a1c & 0x40) {
            a = f_0de840(d_1c0004);
            b = f_0de860(d_1c0004);
            c = f_0de880(d_1c0004);
            s = f_0de8c0(d_1c0004);
            if (a == d_1a3e84 && b == d_1a3e88 && c == d_1a3e8c && s != d_1be250) {
                *((int *)&d_1be24c) = *((int *)&d_1be24c) + 1;
                if ((unsigned)*((int *)&d_1be24c) > 0x14) f_0ddd60(d_1c0004);
            } else {
                d_1a3e84 = a;
                d_1a3e8c = c;
                d_1a3e88 = b;
                d_1be250 = s;
            }
        }
    } else {
        *((int *)&d_1be24c) = 0;
    }
    if (d_1a89a8 == 0) {
        f_0d26e0();
        d_1a89a8 = 1;
    }
    f_0de940(d_1c0004, d_1a9962);
    if (d_1a9942) {
        f_0ddf50(d_1c0004);
        d_1a9942 = 0;
    }
    return r;
}
