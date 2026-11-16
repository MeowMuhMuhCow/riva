/* === Beschreibung (Katalog) ===
 * Einheit fi_mo_op (07cb00 - 07d080)
 *
 * Überblick
 * Die Einheit fi_mo_op (Fight Monster Options) enthält die zentrale KI-Entscheidungsschleife f_07cb00, mit der
 * ein computergesteuertes Monster im Rundenkampf seinen gesamten Zug plant und ausführt.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P1 0/1 gleich (nicht versucht)
// fi_mo_op.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07CB00-0x07D080
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
                                 // reg eax stapel 0
                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
int f_071e90(int p1, short *p2, short *p3);            // reg eax edx ebx stapel 0
int f_072910(int p1);                                   // reg eax stapel 0
char f_0729c0(int p1);                                   // reg eax stapel 0
unsigned char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0757f0(int p1);                                   // reg eax stapel 0
int f_0757f0(int p1, int p2);                           // reg eax stapel 0
int f_07b5e0(int p1, int p2);                           // reg eax edx stapel 0
int f_07b5e0(int p1, unsigned char p2);                 // reg eax edx stapel 0
int f_07c1a0(int p1, int p2, int p3, int p4, int p5, int p6);// reg edx ebx ecx stapel 8
signed char f_07c2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
short f_07c900(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_07d080(int p1, int p2);                           // reg eax edx stapel 0
int f_07eba0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0cfa10(int p1);                                   // reg eax stapel 0
short f_0cfa50(int p1);                                   // reg eax stapel 0
signed char f_0cfbd0(int p1);                                   // reg eax stapel 0
int f_0cfbe0(int p1, int p2);                           // reg eax edx stapel 0
signed char f_0cfc30(int p1);                                   // reg eax stapel 0
unsigned char f_0cfc50(int p1);                                   // reg eax stapel 0
signed char f_0cfc70(int p1);                                   // reg eax stapel 0
signed char f_0cfce0(int p1);                                   // reg eax stapel 0
int f_0cfcf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0cfd10(int p1, int p2);                           // reg eax edx stapel 0
unsigned char f_0cfd20(int p1);                                   // reg eax stapel 0
int f_0cfd30(int p1, int p2);                           // reg eax edx stapel 0
char f_0cfdc0(void *p1);                                 // reg eax stapel 0
int f_0cfdc0(int p1);                                   // reg eax stapel 0
char f_0cfec0(int p1);                                   // reg eax stapel 0
char f_0cff80(int p1);                                   // reg eax stapel 0
char f_0cffb0(int p1);                                   // reg eax stapel 0
int f_0cffc0(int p1, int p2);                           // reg eax edx stapel 0
short f_0d00e0(int p1);                                   // reg eax stapel 0
short f_0d0120(int p1);                                   // reg eax stapel 0
signed char f_0d0160(int p1);                                   // reg eax stapel 0
int f_0d0170(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4880(int p1);                                   // reg eax stapel 0
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
struct Offs16 { short a[4][2]; };
extern struct Offs16 d_1a1f5c;          // 0x1A1F5C
extern int d_1a1f60;                    // 0x1A1F60
extern int d_1a1f64;                    // 0x1A1F64
extern char *d_1bc8f0;                  // 0x1BC8F0
extern short d_1bd920;                  // 0x1BD920
extern char d_1bd928;                   // 0x1BD928
extern unsigned char *d_1bd984;         // 0x1BD984
extern char *d_1c2ed4;                  // 0x1C2ED4
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c2e68;                    // 0x1C2E68
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_0757f0_save(int,int);
//@ f_07cb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette Zug-KI für ein einzelnes Monster (npc) an Position (x, y) aus: Sie
 *   markiert das aktive Monster auf dem Schlachtfeld, prüft bei niedrigem Lebenspunktestand (LE <=
 *   Fluchtschwelle), ob das Monster die Flucht ergreift, versucht anschließend nacheinander einen Monsterzauber
 *   (f_07c2a0), einen Fernkampfangriff (f_07c900) oder einen Nahkampfangriff auf ein benachbartes Feld
 *   (f_07c1a0) und bewegt das Monster andernfalls über die Wegfindung (f_074b40, f_07d080) auf den nächsten
 *   Gegner bzw. zum Fluchtrand zu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger self auf die Hauptkampfstruktur, den Monsterzeiger npc
 *   sowie dessen aktuelle Rasterkoordinaten x und y und gibt den beschlossenen Aktionscode des Monsters
 *   (f_0cfce0(npc), z. B. 2 = Nahkampf, 4 = Zauber, 0x10 = Fernkampf, 0xd = Zug beendet) als short zurück.
 * - Wichtige Variablen: Die Struktur offs (d_1a1f5c) enthält die vier orthogonalen Nachbarfeld-Vektoren für die
 *   NahkampfprÜfung, d_1bd920 kennzeichnet Spezialkämpfe (in denen bei 5 oder 8 keine Flucht erlaubt ist), und
 *   d_1bd984 ist das 24 x 25-Kampfraster.
 === Ende Beschreibung === */
short f_07cb00(int self, int npc, short x, short y)
{
    short ok;
    short old_y;
    short done = 0;
    short count;
    short dir;
    short mode;
    short tile;
    struct Offs16 offs = d_1a1f5c;
    signed char c;
    int res;

    f_0d4880((int)&d_1c2e68);
    f_0cfcf0(npc, 0xd);
    f_0cfd30(npc, 0xff);
    while (!done && f_0cfbd0(npc) > 0) {
        if (d_1bd928) {
            f_069460();
            f_146dfa((int)&d_1c2edc, 1);
        }
        if (*(char *)(self + 0x293) != (char)0xff) {
            f_07eba0(self + 0x39, *(unsigned char *)(self + 0x293), 0);
            *(char *)(self + 0x293) = 0xff;
        }
        f_07b5e0(self, (int)f_0cfc50(npc));
        f_0757f0(self);
        f_0cfd30(npc, 0xff);
        f_0cfcf0(npc, 0xd);
        if (f_0cfa10(npc) <= f_0d0160(npc)) {
            f_0cffc0(npc, 1);
        }
        if (d_1bd920 == 5 || *(short *)(self + 0x1ea) == 0x95 || d_1bd920 == 8) {
            f_0cffc0(npc, 0);
        }
        if (!f_0cffb0(npc)) {
            mode = 1;
            if (f_0cff80(npc)) {
                mode = 0;
            }
            if (f_0cfc30(npc) != -1 && f_0cfa50(npc) >= 5) {
                c = -1;
                c = f_07c2a0(self, npc, mode, x, y);
                if (c != -1) {
                    f_0cfcf0(npc, 4);
                    f_0cfbe0(npc, 0);
                    f_0cfd10(npc, c);
                    return f_0cfce0(npc);
                } else {
                    f_0cfcf0(npc, 0xd);
                    f_0cfd10(npc, -1);
                    f_0cfd30(npc, 0xff);
                }
            }
            if ((f_0d00e0(npc) > 0 || f_0d0120(npc) > 0) && f_07c900(self, npc, mode, x, y)) {
                f_0cfcf0(npc, 0x10);
                f_0cfbe0(npc, 0);
                return f_0cfce0(npc);
            }
            f_0cfd30(npc, 0xff);
            dir = f_0cfc70(npc);
            count = 0;
            while (f_0cfd20(npc) == 0xff && count < 4) {
                f_146dfa((int)&d_1c2edc, 1);
                if (f_07c1a0(self, x, y, offs.a[dir][0], offs.a[dir][1], mode)) {
                    ok = 1;
                    if (f_072910(npc)) {
                        tile = *(d_1bd984 + (y - offs.a[dir][1]) * 0x19 + (x - offs.a[dir][0]));
                        if (tile && tile != (unsigned char)f_0729c0(npc) + 0x1e) {
                            if (tile >= 0xcc
                                || tile >= (short)0x32
                                || tile >= (short)0x1e
                                || (tile >= (short)1 && tile < (short)10 && !f_042470((struct hero *)(d_1bc8f0 + (tile - 1) * 0x5ef)))
                                || (tile >= (short)10 && tile < (short)0x1e && !f_0cfdc0(d_1c2ed4 + (tile - 10) * 0x73))) {
                                ok = 0;
                            }
                        }
                    }
                    if (ok) {
                        f_0cfd30(npc, *(d_1bd984 + (y + offs.a[dir][1]) * 0x19 + (x + offs.a[dir][0])));
                    }
                }
                count++;
                dir++;
                if (dir == 4) {
                    dir = 0;
                }
            }
        }
        if (f_0cfd20(npc) != 0xff) {
            f_0cfcf0(npc, 2);
            f_0cfbe0(npc, 0);
            done = 1;
        } else {
            short old_x;
            if (f_0cfbd0(npc) > 0 && f_071e90((unsigned char)(f_0729c0(npc) + 10), &x, &y)) {
                if (!f_0cfec0(npc)) {
                    if (f_0cffb0(npc)) {
                        res = f_074b40(self, npc, x, y, 3, 1);
                        if (!res) {
                            if (f_0cfa10(npc) <= f_0d0160(npc)) {
                                f_0d0170(npc, 0);
                            }
                            f_0cffc0(npc, 0);
                        }
                    } else if (f_0cff80(npc)) {
                        res = f_074b40(self, npc, x, y, 1, 1);
                    } else {
                        res = f_074b40(self, npc, x, y, 0, 1);
                    }
                    if (res) {
                        old_x = x;
                        old_y = y;
                        f_07d080(self, npc);
                        f_071e90((unsigned char)(f_0729c0(npc) + 10), &x, &y);
                        if (old_x == x && old_y == y) {
                            f_0cfbe0(npc, 0);
                        }
                        if (f_0cfbd0(npc) < 3) {
                            f_0cfbe0(npc, 0);
                        }
                    } else {
                        f_0cfbe0(npc, 0);
                    }
                } else {
                    f_0cfbe0(npc, 0);
                }
                f_0cfcf0(npc, 0xd);
            }
        }
        if (d_1bd928) {
            f_069460();
        }
    }
    return f_0cfce0(npc);
}
