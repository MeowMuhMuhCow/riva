/* === Beschreibung (Katalog) ===
 * Einheit fi_quic2 (085640 - 085cd0)
 *
 * Überblick
 * Die Einheit fi_quic2 (Fight Quick/Auto Cast) enthält die KI-Zauberauswahl f_085640, mit der ein
 * computergesteuerter Held im Automatik-Kampf einen geeigneten Kampfzauber samt Ziel auswählt und sich bei
 * Bedarf in Zauberreichweite bewegt.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P1 0/1 gleich
// fi_quic2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x085640-0x085CD0
#include <string.h>
#include "RIVAMEM.H"



int f_030850(int p1, int p2);                           // reg eax edx stapel 0
                                  // reg eax stapel 0
                   // reg eax edx stapel 0
                         // reg eax stapel 0
                           // reg eax edx stapel 0
#pragma aux f_0432c0 parm [eax edx] modify exact [eax edx]
signed char f_043410(int p1);                           // reg eax stapel 0
int f_043420(int p1, int p2);                           // reg eax edx stapel 0
int f_043c20(int p1, int p2);                           // reg eax edx stapel 0
int f_043c40(int p1, int p2);                           // reg eax edx stapel 0
int f_069460();                                         // reg - stapel 0
int f_071e90(int p1, short *p2, short *p3);             // reg eax edx ebx stapel 0
unsigned char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_07d6a0(int p1, int p2);                           // reg eax edx stapel 0
unsigned char f_084b40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
short f_084f90(int p1, int p2, int p3, int p4);         // reg edx ebx ecx stapel 0
int f_085050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
#pragma aux f_085050 parm [eax edx ebx] modify exact [eax ebx edx]
signed char f_0d54c0(int p1);                           // reg eax stapel 0
short f_145760(int p1, int p2);                         // reg eax edx stapel 0
#pragma aux f_145760 parm [eax edx] modify exact [eax edx ecx]
int f_146dfa(void *p1, int p2);                         // reg eax edx stapel 0
extern signed char d_1a21b4[];
extern signed char d_1a7278[];
extern char d_1bd928;
extern short d_1bda6c;
extern short d_1bda6e;
extern char d_1c2edc[];
#define BUSY() if (d_1bd928) { f_069460(); f_146dfa(d_1c2edc, 1); }

//@ f_085640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt für einen computergesteuerten magiebegabten Helden (p2) aus der Liste d_1a21b4 der 20
 *   Kampfzauber zufällig einen Spruch aus, den der Held auf mindestens -4 beherrscht (f_0430f0 > -5), bestimmt
 *   über f_084f90 den benötigten Zieltyp, sucht über f_084b40 ein passendes Ziel (und lässt den Helden bei
 *   Berührungszaubern oder versperrter Sichtlinie über f_074b40 und f_07d6a0 zunächst näher heranziehen) und
 *   prüft abschließend über f_085050, ob der Zauber gegen dieses Ziel sinnvoll ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Heldenzeiger p2, das Verzauberungsflag
 *   p3 sowie die aktuellen Heldenkoordinaten p4 (X) und p5 (Y) und gibt die ausgewählte Zauber-ID als char (oder
 *   -1, falls kein Zauber möglich war) zurück.
 * - Wichtige Variablen: Das Array d_1a21b4[20] enthält die 20 von der Helden-KI genutzten Kampfzauber-IDs, und
 *   d_1a7278[v_2c * 14] unterscheidet Berührungszauber (0) von Fernzaubern (!= 0).
 === Ende Beschreibung === */
char f_085640(int p1, int p2, short p3, short p4, short p5)
{
    signed char v_2c = -1;
    short v_14;
    short v_1c;
    short v_18;
    short v_ecx;
    short v_10;
    short v_20;
    int v_ebp;
    int v_04;

    v_20 = -2;
    v_10 = 0;
    v_ebp = 1;
    f_0432c0((struct hero *)(p2), 0xff);
    while (v_ebp && f_043410(p2) > 0 && v_10 < 5) {
        v_ebp = 0;
        v_10++;
        v_18 = 0;
        f_146dfa(d_1c2edc, 1);
        while (!v_18 && f_043410(p2) > 0) {
            BUSY();
            v_14 = 0;
            do {
                BUSY();
                v_2c = d_1a21b4[f_145760(0, 19)];
                v_ecx = 0;
                if (f_0430f0((struct hero *)(p2), v_2c) > -5) {
                    v_ecx = 1;
                    if (v_2c == v_20) {
                        v_ecx = 0;
                    } else {
                        v_20 = v_2c;
                        break;
                    }
                }
                v_14++;
            } while (v_14 < 5);
            f_0432c0((struct hero *)(p2), 0xff);
            if (v_ecx) {
                v_1c = f_084f90(p1, p2, v_2c, p3);
                if (v_1c != -1) {
                    int v_08;
                    if (v_1c == 2) {
                        f_030850(p2, p2);
                        if (f_085050(p1, p2, v_2c)) {
                            f_043c20(p2, p4);
                            f_043c40(p2, p5);
                            d_1bda6c = p4;
                            d_1bda6e = p5;
                            return v_2c;
                        } else {
                            v_ebp = 1;
                            f_0432c0((struct hero *)(p2), 0xff);
                            v_18 = 1;
                        }
                    } else if (d_1a7278[v_2c * 14] == 0) {
                        v_04 = 0;
                        while (f_043410(p2) > 0 && !v_18) {
                            if (d_1bd928)
                                f_069460();
                            if (!v_04) {
                                f_0432c0((struct hero *)(p2), 0xff);
                                unsigned char c1 = f_084b40(p1, p4, p5, v_1c, 1, 1);
                                if (c1)
                                    f_0432c0((struct hero *)(p2), c1);
                            }
                            if (((unsigned char)(f_0432b0((struct hero *)(p2)))) != 0xff) {
                                if (f_043410(p2) >= 5) {
                                    if (f_085050(p1, p2, v_2c)) {
                                        return v_2c;
                                    } else {
                                        v_ebp = 1;
                                        f_0432c0((struct hero *)(p2), 0xff);
                                    }
                                } else {
                                    f_043420(p2, 0);
                                    f_0432c0((struct hero *)(p2), 0xff);
                                }
                                v_18 = 1;
                            } else {
                                if (!((char)(f_042600((struct hero *)(p2))))) {
                                    if (v_1c == 0)
                                        v_08 = f_074b40(p1, p2, p4, p5, 5, 1);
                                    else if (v_1c == 3)
                                        v_08 = f_074b40(p1, p2, p4, p5, 6, 1);
                                    else if (v_1c == 4)
                                        v_08 = f_074b40(p1, p2, p4, p5, 8, 1);
                                    else
                                        v_08 = f_074b40(p1, p2, p4, p5, 4, 1);
                                    if (v_08) {
                                        if (d_1bd928)
                                            f_069460();
                                        f_0432c0((struct hero *)(p2), (unsigned char)v_08);
                                        if (f_085050(p1, p2, v_2c)) {
                                            f_07d6a0(p1, p2);
                                            f_071e90((unsigned char)(f_0d54c0(p2) + 1), &p4, &p5);
                                            v_04 = 1;
                                            if (f_043410(p2) < 5) {
                                                f_0432c0((struct hero *)(p2), 0xff);
                                                f_043420(p2, 0);
                                                v_04 = 0;
                                                v_18 = 1;
                                            }
                                        } else {
                                            v_ebp = 1;
                                            v_18 = 1;
                                            f_0432c0((struct hero *)(p2), 0xff);
                                        }
                                    } else {
                                        f_0432c0((struct hero *)(p2), 0xff);
                                        v_ebp = 1;
                                        v_18 = 1;
                                    }
                                } else {
                                    f_043420(p2, 0);
                                    f_0432c0((struct hero *)(p2), 0xff);
                                }
                            }
                        }
                    } else {
                        v_04 = 0;
                        while (!v_18 && f_043410(p2) > 0) {
                            if (d_1bd928)
                                f_069460();
                            if (!v_04) {
                                f_0432c0((struct hero *)(p2), 0xff);
                                unsigned char c2 = f_084b40(p1, p4, p5, v_1c, 99, 1);
                                if (c2)
                                    f_0432c0((struct hero *)(p2), c2);
                            }
                            if (((unsigned char)(f_0432b0((struct hero *)(p2)))) != 0xff) {
                                if (f_043410(p2) >= 5) {
                                    if (f_085050(p1, p2, v_2c)) {
                                        return v_2c;
                                    } else {
                                        v_ebp = 1;
                                        f_0432c0((struct hero *)(p2), 0xff);
                                    }
                                } else {
                                    f_043420(p2, 0);
                                    f_0432c0((struct hero *)(p2), 0xff);
                                }
                                v_18 = 1;
                            } else {
                                if (!((char)(f_042600((struct hero *)(p2))))) {
                                    if (v_1c == 0)
                                        v_08 = f_074b40(p1, p2, p4, p5, 13, 1);
                                    else if (v_1c == 3)
                                        v_08 = f_074b40(p1, p2, p4, p5, 14, 1);
                                    else
                                        v_08 = f_074b40(p1, p2, p4, p5, 12, 1);
                                    if (v_08) {
                                        if (d_1bd928)
                                            f_069460();
                                        f_0432c0((struct hero *)(p2), (unsigned char)v_08);
                                        if (f_085050(p1, p2, v_2c)) {
                                            f_07d6a0(p1, p2);
                                            f_071e90((unsigned char)(f_0d54c0(p2) + 1), &p4, &p5);
                                            v_04 = 1;
                                            if (f_043410(p2) < 5) {
                                                f_043420(p2, 0);
                                                v_18 = 1;
                                                f_0432c0((struct hero *)(p2), 0xff);
                                                v_04 = 0;
                                            }
                                        } else {
                                            v_ebp = 1;
                                            v_18 = 1;
                                            f_0432c0((struct hero *)(p2), 0xff);
                                        }
                                    } else {
                                        f_0432c0((struct hero *)(p2), 0xff);
                                        v_ebp = 1;
                                        v_18 = 1;
                                    }
                                } else {
                                    f_043420(p2, 0);
                                    f_0432c0((struct hero *)(p2), 0xff);
                                    v_18 = 1;
                                }
                            }
                        }
                    }
                }
            } else {
                v_18 = 1;
            }
        }
    }
    return -1;
}
