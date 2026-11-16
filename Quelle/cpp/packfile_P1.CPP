/* === Beschreibung (Katalog) ===
 * Einheit packfile (0d9d20 - 0da250)
 *
 * Überblick
 * Die Einheit packfile stammt aus der Quelldatei packfile.cpp und implementiert das Lauflängen-Kompressions- und
 * Dekompressionsverfahren (RLE mit Escape-Byte 0x7f) für gepackte Spieldateien mit der 8-Byte-Kennung "RIVAPACK"
 * (d_1a6260), wie es unter anderem beim Packen und Entpacken von Spielständen und Auslagerungsdateien verwendet
 * wird.
 === Ende Beschreibung === */
// P3 0/3 gleich (suche.py 30.10.2026, Basis packfile_P1.CPP)
// packfile.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D9D20-0x0DA250
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_014a60();                                         // reg - stapel 0
int f_0da250(int p1, int p2, int p3, int p4, int p5, int p6);// reg edx ebx ecx stapel 8

// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a6240[];           // Text 0x1A6240
extern const char d_1a6260[];           // Text 0x1A6260
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int __cdecl f_144fbf(int path, int flags);
int f_144cb6(int h, const void *b, unsigned n);
int f_144e8b(int h, void *b, int n);
int f_145259(int h);
int f_1452bc(int h);
int f_145547(const void *a, const void *b, int n);
int f_14d0d7(int a, int b);
int f_0d9ea0(int p1, unsigned char *p2, unsigned char *p3, short p4, short p5, short p6);

//@ f_0d9d20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Komprimiert eine Quelldatei (p2) in eine Zieldatei (p3), indem sie den 13-Byte-Kopfsatz
 *   ("RIVAPACK", 4-Byte-Originallänge, 1-Byte-Verfahrenskennung 1) schreibt und den Dateiinhalt blockweise (zu
 *   je 0x2800 Bytes) über den RLE-Packer f_0d9ea0 ausgibt.
 * - Eingaben: Übergeben werden der Zeiger auf das Packfile-Objekt (p1), der Dateipfad der unkomprimierten
 *   Quelldatei (p2) sowie der Dateipfad der komprimierten Zieldatei (p3).
 * - Rückgabewert: Gibt die geschriebene Gesamtgröße der gepackten Datei in Bytes oder -1 bei einem
 *   Lese-/Schreibfehler zurück.
 === Ende Beschreibung === */
short f_0d9d20(int p1, int p2, int p3)
{
    short outraw; short inraw; int ok; int total; int inh; unsigned len; char one;
    unsigned char *a;
    unsigned char *b;
    int r, n;
    int outh;
    len = 0; total = 0; ok = 0; one = 1;
    inraw = f_144fbf(p2, 0x200);
    inh = inraw;
    if (inh != -1) {
        outraw = f_14d0d7(p3, 0);
        if (outraw != -1) {
            a = (unsigned char *)f_014540(0x2800, (int)d_1a6240, 0x44);
            b = (unsigned char *)f_014540(0x2800, (int)d_1a6240, 0x45);
            len = f_1452bc(inh);
            f_144cb6((short)outraw, d_1a6260, 8);
            f_144cb6((short)outraw, &len, 4);
            f_144cb6((short)outraw, &one, 1);
            total = 0xd;
            while (len > 0) {
                n = f_144e8b((short)inraw, a, 0x2800);
                len -= n;
                switch (one) {
                case 1: r = f_0d9ea0(p1, a, b, (short)n, (short)outraw, 0x2800); break;
                default: r = f_0d9ea0(p1, a, b, (short)n, (short)outraw, 0x2800);
                }
                if (r == -1) {
                    total = -1;
                    break;
                }
                total += r;
            }
            delete a;
            delete b;
            outh = outraw;
            if (f_1452bc(outh) == total) ok = 1;
            f_145259((short)outraw);
        }
        f_145259((short)inraw);
    }
    if (ok == 0) total = -1;
    return total;
}
//@ f_0d9ea0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Komprimiert einen Datenblock der Länge p4 aus dem Eingabepuffer p2 per Lauflängenkodierung
 *   (Wiederholungen ab 3 gleichen Bytes sowie literale 0x7f-Bytes werden als 3-Byte-Folge 0x7f, anzahl, wert bis
 *   maximal 126 Bytes kodiert) über den Ausgabepuffer p3 in die geöffnete Zieldatei p5.
 * - Eingaben: Übergeben werden der Zeiger auf das Packfile-Objekt (p1), der Eingabepuffer (p2), der
 *   Ausgabepuffer (p3), die Eingabelänge (p4), das Dateihandle der Zieldatei (p5) sowie die Größe des
 *   Ausgabepuffers (p6).
 * - Rückgabewert: Gibt die Anzahl der komprimiert in die Zieldatei geschriebenen Bytes oder -1 bei einem
 *   Schreibfehler zurück.
 === Ende Beschreibung === */
int f_0d9ea0(int p1, unsigned char *p2, unsigned char *p3, short p4, short p5, short p6)
{
    short index;
    unsigned char *out = p3;
    short count = 0;
    short total = 0;
    unsigned char value;
    unsigned char run;
    int written;

    index = 0;
    while ((short)index < p4) {
            value = *p2;
            run = 1;
            ++index;
            while (value != 0x7f && p2[run] == value && run < 0x7e && (short)index < p4) {
                ++run;
                ++index;
            }

            if (run > 2 || value == 0x7f) {
                p3[0] = 0x7f;
                p3[1] = run;
                p3[2] = value;
                p3 += 3;
                count += 3;
                p2 += run;
            } else if (run == 2) {
                p3[0] = value;
                p2 += run;
                p3[1] = value;
                p3 += run;
                count += 2;
            } else {
                *p3 = value;
                ++p2;
                ++count;
                ++p3;
            }

            if (count >= p6 - 3) {
                written = f_144cb6(p5, out, count);
                if ((short)written != count) return -1;
                total += count;
                p3 = out;
                count = 0;
            }
    }

    if (count > 0) {
        if ((short)f_144cb6(p5, out, count) != count) return -1;
        total += count;
    }
    return (short)total;
}
//@ f_0d9fe0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet eine "RIVAPACK"-komprimierte Datei (p2), prüft die 8-Byte-Signatur und die gespeicherte
 *   Originallänge, liest die gepackten Blöcke unter Berücksichtigung von Blockgrenzen mitten in
 *   3-Byte-RLE-Sequenzen (0x7f, anzahl, wert) ein und entpackt sie über f_0da250 in die Zieldatei (p3).
 * - Eingaben: Übergeben werden der Zeiger auf das Packfile-Objekt (p1), der Dateipfad der gepackten Quelldatei
 *   (p2) sowie der Dateipfad der entpackten Zieldatei (p3).
 * - Rückgabewert: Gibt die entpackte Gesamtgröße in Bytes zurück, sofern sie exakt der im Header vermerkten
 *   Originallänge entspricht, andernfalls -1.
 === Ende Beschreibung === */
#define PB(i) (*(unsigned char *)(i))
int f_0d9fe0(int p1, int p2, int p3)
{
    short outh;
    int n;
    unsigned len;
    char one;
    unsigned rest;
    unsigned char *b;
    unsigned char *a;
    short inh;
    unsigned char hdr[8];
    int total;
    int r;
    int ok;
    short bufsize;
    int k;

    total = 0; bufsize = 0x2800; ok = 0;
    inh = f_144fbf(p2, 0x200);
    if (inh != -1) {
        rest = f_1452bc(inh);
        f_144e8b(inh, hdr, 8);
        rest -= 8;
        if (f_145547(hdr, d_1a6260, 8) == 0) {
            f_144e8b(inh, &len, 4);
            f_144e8b(inh, &one, 1);
            outh = f_14d0d7(p3, 0);
            rest -= 5;
            if (outh != -1) {
                if (rest > 0x2800 && (unsigned)f_014a60() > rest * 2 + 200) bufsize = rest + 100;
                a = (unsigned char *)f_014540(bufsize + 10, (int)d_1a6240, 0x104);
                b = (unsigned char *)f_014540(bufsize, (int)d_1a6240, 0x105);
                while (rest > 0) {
                    n = f_144e8b(inh, a, bufsize);
                    rest -= n;
                    if (a[n-2] == 0x7f && a[n-3] != 0x7f) {
                        if (a[n-4] != 0x7f || a[n-3] != 1 || a[n-5] == 1 || a[n-6] == 0x7f) {
                            f_144e8b(inh, a + n, 1);
                            rest--; n++;
                        }
                    }
                    if (a[n-1] == 0x7f) {
                        if (a[n-3] != 0x7f || a[n-2] != 1 || a[n-5] == 0x7f) {
                            short s = 2;
                            if (a[n - 2] == 0x7f) s = 1;
                            k = s;
                            f_144e8b(inh, a + n, k);
                            rest -= k; n += k;
                        }
                    }
                    switch (one) {
                    case 1: r = f_0da250(p1, (int)a, (int)b, (short)n, outh, bufsize); break;
                    default: r = f_0da250(p1, (int)a, (int)b, (short)n, outh, bufsize);
                    }
                    if (r == -1) { total = r; break; }
                    total += r;
                }
                delete b;
                delete a;
                if (total == len) ok = 1;
                f_145259(outh);
            }
        } else {
            total = -1;
        }
        f_145259(inh);
    }
    if (ok == 0) total = -1;
    return total;
}
