/* === Beschreibung (Katalog) ===
 * Einheit ch_spell (0x03cd00 - 0x03d3d0)
 *
 * Überblick
 * Diese Einheit enthält mit f_03cd00 das zweistufige Zauberspruch-Auswahlmenü des Spiels, das sowohl beim
 * Aussprechen eines Zaubers im Kampf oder Abenteuer als auch beim Steigern von Zaubern während des
 * Stufenaufstiegs zum Einsatz kommt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 26.10.2026, Basis ch_spell_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 0 gleich (vorher 0), Rest 493 (vorher 495)
// ch_spell.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03CD00-0x03D3D0
#include <string.h>
#define BUF(x) (((char *)&v12)[x])
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int sprintf(char *buf, const char *fmt, ...);
typedef RivaTextContextData PL;
short f_036ee0(int p1, int p2);
int f_03cc60(int p1, short p2);



#pragma aux f_09a040 parm [eax edx] modify exact [eax]
#pragma aux f_09a080 parm [eax edx] modify exact [eax]
int f_09a040(int p1);
int f_09a080(int p1);
int f_0bf730(void *p1, int p2);
int f_0bf820(void*,int,short,...);
struct B12 { int a; int b; int c; };
struct B10 { int a; int b; short c; };
int f_0e9300(void *p1, void *p2, int p3);
int f_0e93f0(void *p1, void *p2, int p3);
void f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int);
int f_133fe0(void *p1, void *p2);
extern "C" int f_14572e(char *p1, const char *p2, ...);
extern struct B12 d_1a0c50;
extern struct B10 d_1a0c5c;
extern signed char d_1a7275[];
extern signed char d_1a7734[];
extern signed char d_1a7735[];
extern char *d_1bc8a0;
extern short d_1bd90c;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern int d_1c29c4[];
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
//@ f_03cd00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion öffnet für einen magiebegabten Helden p1 zunächst das Auswahlmenü der zwölf
 *   Zaubergebiete (Antimagie bis Verwandlung, Text-IDs 0x200000ee..0x200000f9) und zeigt anschließend die
 *   Zaubersprüche des gewählten Gebiets mit ihren aktuellen Zauberwerten an. Im Anwendungsmodus (p2 == 0 bzw. 2)
 *   blendet sie Gebiete und Zauber, die der Held nicht beherrscht (< -5) oder die im aktuellen Kampf-/Reisemodus
 *   (d_1bd90c) nicht einsetzbar sind, ausgegraut dar und weist unzulässige Auswahlen mit einer entsprechenden
 *   Meldung (0x20000166..0x2000016a) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Menümodus p2 (1 =
 *   Stufenaufstiegsmodus mit farbiger Steigerungsmarkierung, 0/2 = Zauber auswählen mit Wertanzeige, 3 = Zauber
 *   auswählen ohne Wertanzeige) und gibt den ausgewählten Zauberindex (1..85), -1 oder -2 (bei Abbruch) zurück.
 * - Wichtige Variablen: Die Tabellen d_1a7734 und d_1a7735 definieren Startindex und Umfang der zwölf
 *   Zaubergebiete; d_1bc8a0 liefert im Stufenaufstiegsmodus die bereits erfolgten Steigerungen und Fehlversuche
 *   je Spruch, während d_1a7275 die Einsetzbarkeit inner- und außerhalb des Kampfes vorgibt.
 === Ende Beschreibung === */
short f_03cd00(int p1, short p2)
{
    PL pl;
    struct B12 v12;
    struct B10 v10;
    int ok;
    short i, r;
    short k;
    signed char flag;
    r = -2;
    v12 = d_1a0c50;
    v10 = d_1a0c5c;
    f_09a040(0xff);
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    if (p2 == (short)0) p2 = 2;
    if (f_042a10((struct hero *)(p1)) == 0) {
        f_0bf730(&d_1c2c64, 0x20000161);
    } else {
        do {
            short w;
            ok = 1;
            if (p2 == 1) {
                f_0e93f0(&d_1c38b0, d_1c27a8, 0x20000162);
                if ((unsigned char)((char)(f_0432f0((struct hero *)(p1)))) > 1) {
                    f_0e9300(&d_1c38b0, d_1c27a8, 0x20000164);
                }
                pl.tables.tail.numbers[1] = ((unsigned char)((char)(f_0432f0((struct hero *)(p1)))) > 1) ? 0x20000114 : 0x20000113;
                pl.tables.tail.numbers[2] = f_133fe0(&d_1c3498, d_1c27a8);
                pl.tables.tail.short_numbers[1] = (unsigned char)((char)(f_0432f0((struct hero *)(p1))));
                w = f_0bf820(&d_1c2c64, 0x20000165, 12,
                             0x200000ee, 0x200000ef, 0x200000f0, 0x200000f1,
                             0x200000f2, 0x200000f3, 0x200000f4, 0x200000f5,
                             0x200000f6, 0x200000f7, 0x200000f8, 0x200000f9) - 1;
            } else {
                for (i = 0; i < 12; i++) {
                    char *row = &d_1c21b4[(i + 1) * 0x32];
                    BUF(i) = f_03cc60(p1, i);
                    pl.tables.tail.numbers[1] = (unsigned int)i + 0x200000eeU;
                    f_0e93f0(&d_1c38b0, row, BUF(i) ? f_09a080(0xff) : f_09a080(0xe7));
                    d_1c29c4[i] = f_133fe0(&d_1c3498, row);
                }
                w = f_0bf820(&d_1c2c64, 0x20000115, 12,
                             d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3],
                             d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
                             d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11]) - 1;
            }

            if (w != -2) {
                if (!BUF(w)) {
                    pl.tables.p[1] = p1;
                    f_0bf730(&d_1c2c64, 0x20000166);
                    ok = 0;
                    r = -2;
                } else {
                    short base;
                    short idx;
                    base = d_1a7734[w * 2];
                    idx = base;
                    for (k = 0; k < d_1a7735[w * 2]; k++, idx++) {
                        char *row = d_1c21b4 + k * 0x32;
                        if (p2 == 1) {
                            flag = f_09a040(0xff);
                            if (f_036ee0(idx, p1) >
                                    (signed char)d_1bc8a0[(base + k) * 2 + 1] &&
                                (signed char)d_1bc8a0[(base + k) * 2] != 3)
                                goto check_status1313;
                            flag = f_09a040(0xfd);
                            goto status_done1313;
check_status1313:
                            if ((signed char)d_1bc8a0[(base + k) * 2 + 1] != 0)
                                flag = f_09a040(0xfc);
status_done1313:
                            f_0e93f0(&d_1c38b0, d_1c27a8, base + 0x20000097 + k);
                            f_14572e(row, (const char *)&v10, d_1c27a8, flag,
                                     f_0430f0((struct hero *)(p1), idx), (unsigned char)f_09a040(0xff));
                        } else if (((d_1bd90c != (short)0 && d_1a7275[(base + k) * 0xe] != -1) ||
                                    (d_1bd90c == (short)0 && d_1a7275[(base + k) * 0xe] != 1)) &&
                                   f_0430f0((struct hero *)(p1), idx) >= -5) {
                            goto resource_good1324;
resource_before1324:
                            pl.tables.tail.numbers[1] = base + 0x20000097 + k;
                            goto resource_after1324;
resource_good1324:
                            if (p2 == 2) {
                                pl.tables.tail.numbers[1] = base + 0x20000097 + k;
                                pl.tables.tail.short_numbers[1] = f_0430f0((struct hero *)(p1), idx);
                                f_0e93f0(&d_1c38b0, row, 0x20000009);
                            } else {
                                pl.tables.tail.numbers[1] = base + 0x20000097 + k;
                                f_0e93f0(&d_1c38b0, row, 0x20000008);
                            }
                        } else {
                            if (p2 == 2) {
                                goto resource_before1324;
resource_after1324:
                                pl.tables.tail.short_numbers[1] = f_0430f0((struct hero *)(p1), idx);
                                f_0e93f0(&d_1c38b0, row, 0x2000000b);
                            } else {
                                pl.tables.tail.numbers[1] = base + 0x20000097 + k;
                                f_0e93f0(&d_1c38b0, row, 0x2000000a);
                            }
                        }
                        d_1c29c4[k] = f_133fe0(&d_1c3498, row);
                    }
                    int choice = f_0bf820(&d_1c2c64, 0x20000169, (short)d_1a7735[w * 2],
                                 d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3],
                                 d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
                                 d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11],
                                 d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15]);
                    r = choice;
                    if ((short)choice != -1) {
                        if (f_0430f0((struct hero *)(p1), (short)(choice + base - 1)) < -5 && p2 != 1) {
                            pl.tables.p[1] = p1;
                            f_0bf730(&d_1c2c64, 0x2000016a);
                            ok = 0;
                            r = -1;
                        } else {
                            r += base - 1;
                        }
                    } else {
                        ok = 0;
                    }
                }

                if (r > 0) {
                    // Neutrale Globalkopie haelt die Registervergabe wie im Original
                    d_1c3498=(d_1c3498 & 0)?0:d_1c3498; d_1c349c=(d_1c349c & 0)?0:d_1c349c;
                    if (d_1bd90c != (short)0 || d_1a7275[r * 0xe] != 1 || p2 == 1) goto check_second1313;
                    {
                        f_0bf730(&d_1c2c64, 0x20000167);
                        ok = 0;
                        r = -2;
                        goto final_checks_done;
                    }
check_second1313:
                    if (d_1bd90c == (short)0 || d_1a7275[r * 0xe] != -1 || p2 == 1) goto final_checks_done;
                    {
                        f_0bf730(&d_1c2c64, 0x20000168);
                        ok = 0;
                        r = -2;
                        goto final_checks_done;
                    }
                }
            } else {
                r = -2;
            }
final_checks_done:
            ;
        } while (ok == 0);
    }
    f_1254a0(&pl, 0);
    return r;
}
