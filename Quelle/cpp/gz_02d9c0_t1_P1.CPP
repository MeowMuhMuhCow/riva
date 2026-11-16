/* === Beschreibung (Katalog) ===
 * Einheit gz_02d9c0_t1 (0x0002d9c0 - 0x0002ddc0)
 *
 * Überblick
 *
 * Die Einheit gz_02d9c0_t1 enthält den letzten logischen Teil der Burg- und Stadt-Ereignissteuerung rund um die
 * Wachablösung, Verhaftung bzw. Eskorte und das Verlassen gesperrter Bereiche, wenn die Gruppe ohne gültige
 * Erlaubnis oder Verkleidung (0x29a) zu bestimmten Uhrzeiten in der Burg angetroffen wird.
 === Ende Beschreibung === */
// P3 15/18 gleich (suche.py 24.10.2026, Basis gz_02d9c0_P1.CPP)
// gz_02d9c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02D9C0-0x02DEE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_041920(int p1);                                   // reg eax stapel 0
int f_060030(int p1, int p2);                           // reg eax edx stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(void *p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dd440(int p1);                                   // reg eax stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de600(int p1, void *p2);                           // reg edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_125400(void *p1, void *p2, void *p3);
int f_125400(void *p1, void *p2, void *p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(void *p1);                                   // reg eax stapel 0
int f_126410(void *p1);                                   // reg eax stapel 0
int f_133fe0(void *p1, void *p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9820;                    // 0x1A9820
extern int d_1babf4;                    // 0x1BABF4
extern int d_1bac38;
extern int d_1bac4c;
int lib_dtorarst(int p1, void *p2, int p3);                    // 0x1BAC38
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bfdbc;
#define EL(i) ((int)&d_1bfdbc + (i) * 0x61)
extern int d_1c0004;                    // 0x1C0004
extern int d_1c21a4;                    // 0x1C21A4
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
// --- eigene Funktionen (18), in dieser Reihenfolge definieren, je eine Zeile //@ f_02d9c0
void f_02d9c0()
{
    int t = f_126410(&d_1c2c44);
    unsigned short u = t / 0x1518;
    if ((unsigned short)f_0dd440(d_1c0004) != 0x29a) {
        switch (u) {
        case 6: f_0bf730(&d_1c2c64, 0x3300006a); return;
        case 7: f_0bf730(&d_1c2c64, 0x3300006b); return;
        case 8: f_0bf730(&d_1c2c64, 0x3300006c); return;
        }
    }
}
//@ f_02da50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt während der Tagesstunden (0xa8c0 bis 0x190c8, also 08:00 bis 19:00 Uhr) die Schritte der
 *   Gruppe im Feld p1 + 0x0c hoch. Überschreitet der Zähler 3 Schritte und besitzt die Gruppe (oder eines der
 *   bis zu sechs Gruppenlager d_1bfdbc) nicht die Berechtigung 0x29a, wird in einer Schleife die Begegnung
 *   f_08c920(0x98, 0) (Stadtwache/Burgwache) erzwungen, bis diese mit Status 2 endet; außerhalb der Tageszeit
 *   wird der Schrittzähler auf 0 zurückgesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Orts-Objekt p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Inkrementiert den Schrittzähler *(short *)(p1 + 0x0c), prüft die sechs
 *   Teilgruppen-Einträge ab d_1bfdbc (Größe 0x61) und setzt d_1bd91c = 1.
 === Ende Beschreibung === */
void f_02da50(int p1)
{
    int r = 0;
    short k = 0;
    int q;
    if (f_126410(&d_1c2c44) > 0xa8c0 && f_126410(&d_1c2c44) < 0x190c8) {
        k = ++*(short *)(p1 + 0xc);
        if (k > 3) {
            if ((unsigned short)f_0dd440(d_1c0004) != 0x29a) {
                do { d_1bd91c = 1; r = f_08c920(0x98, 0); f_09a400(); } while ((short)r != 2);
            }
            for (k = 0; k < 6 && (short)d_1c21a4 == 0; k++) {
                q = EL(k);
                if (f_0de7c0(q) != 0) {
                    r = f_0de820(q);
                    if ((short)r == 6) {
                        r = f_0db9a0(q);
                        if ((short)r > 0) {
                            if ((unsigned short)f_0dd440(q) != 0x29a) {
                                f_041920(q);
                                do { d_1bd91c = 1; r = f_08c920(0x98, 0); f_09a400(); } while ((short)r != 2);
                            }
                        }
                    }
                }
            }
        }
    } else {
        *(short *)(p1 + 0xc) = 0;
    }
}

//@ f_02db80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft in einer Schleife so lange die Begegnungsfunktion f_08c920(0x98, 0) und die
 *   Bildschirmaktualisierung f_09a400() auf, bis der Kampf oder die Festnahme mit dem Rückgabewert 2
 *   abgeschlossen ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt den Endstatus 2 als short
 *   zurück.
 * - Wichtige Variablen: Setzt vor jedem Aufruf das Kampfflag d_1bd91c = 1.
 === Ende Beschreibung === */
short f_02db80()
{
    short r;
    do { d_1bd91c = 1; r = f_08c920(0x98, 0); f_09a400(); } while (r != 2);
    return r;
}
//@ f_02dbb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft sowohl für die aktive Gruppe (d_1c0004) als auch für alle sechs Gruppen-Slots ab
 *   d_1bfdbc, die sich im Ortsbereich 6 (Burg) befinden, ob der Status 0x29a vorliegt, wechselt bei Verstoß auf
 *   die jeweilige Teilgruppe (f_041920) und erzwingt die Wachbegegnung 0x98.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Durchläuft die sechs Gruppenstrukturen EL(0..5) ab d_1bfdbc unter Beachtung des
 *   Abbruchflags d_1c21a4.
 === Ende Beschreibung === */
void f_02dbb0()
{
    int s = f_0dd440(d_1c0004);
    if ((unsigned short)s != 0x29a) {
        do { d_1bd91c = 1; s = f_08c920(0x98, 0); f_09a400(); } while ((short)s != 2);
    }
    short s2 = 0;
    for (; s2 < 6 && (short)d_1c21a4 == 0; s2 = s2 + 1) {
        int q = EL(s2);
        if (f_0de7c0(q) != 0) {
            int r = f_0de820(q);
            if ((short)r == 6) {
                r = f_0db9a0(q);
                if ((short)r > 0) {
                    if ((unsigned short)f_0dd440(q) != 0x29a) {
                        f_041920(q);
                        do { d_1bd91c = 1; r = f_08c920(0x98, 0); f_09a400(); } while ((short)r != 2);
                    }
                }
            }
        }
    }
}

//@ f_02dc90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle sechs Gruppen-Slots ab d_1bfdbc nach Helden oder Teilgruppen, die sich ohne
 *   den Status 0x29a im Bereich 6 aufhalten, gibt mit deren Namen die Meldung 0x3300006e aus und versetzt sie
 *   über f_0de210(p) aus dem gesperrten Bereich hinaus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest die sechs Gruppen-Einträge ab d_1bfdbc, ermittelt deren Namen über f_0de600 in
 *   d_1c21b4 und nutzt d_1c2c64 für die Textausgabe.
 === Ende Beschreibung === */
struct Q { char b[16]; int *i; char rest[40]; };
void f_02dc90()
{
    int f_1254a0(void *, int);
    short s;
    Q q;
    for (short k = 0; k < 6; k = k + 1) {
        int p = EL(k);
        if (f_0de7c0(p) != 0) {
            s = f_0de820(p);
            if (s == 6) {
                s = f_0db9a0(p);
                if (0 < s) {
                    if ((unsigned short)f_0dd440(p) != 0x29a) {
                        f_125400(&q, &d_1c349c, &d_1c3870, (int)&d_1c3498);
                        f_0de600(p, &d_1c21b4);
                        q.i[1] = f_133fe0(&d_1c3498, &d_1c21b4);
                        f_0bf730(&d_1c2c64, 0x3300006e);
                        f_0de210(p);
                        f_1254a0(&q, 0);
                    }
                }
            }
        }
    }
}

//@ f_02dd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut das Orts-Verwaltungsobjekt der Burg von Riva wieder ab und gibt je nach übergebenen
 *   Destruktor-Flags (p2 & 2) den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2 und gibt den
 *   Zeiger auf das abgebaute Objekt zurück.
 * - Wichtige Variablen: Nutzt den Basisklassen-Destruktor f_060030(p1, 1) und den Ausnahmerahmen d_1babf4.
 === Ende Beschreibung === */
int f_02dd60(int p1, unsigned p2)
{
    int f_145234(int p1, int p2);
    void f_145254();
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)&d_1babf4);
        f_145254();
        return p1;
    }
    r = f_060030(p1, 1);
    if (p2 & 2) operator delete((void *)r);
    return r;
}

//@ f_02dda0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dient als kurzes Prädikat für Gruppenabfragen (f_0398c0) und prüft, ob ein Held lebendig und
 *   handlungsfähig (f_0d4a60(p1) == 1) ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Heldenzeiger p1 entgegen und gibt 1 zurück, wenn der Held
 *   einsatzbereit ist, sonst 0.
 * - Wichtige Variablen: Delegiert direkt an f_0d4a60.
 === Ende Beschreibung === */
int f_02dda0(int p1)
{
    return f_0d4a60(p1) == 1;
}

