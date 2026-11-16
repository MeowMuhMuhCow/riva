/* === Beschreibung (Katalog) ===
 * Einheit loaders (0x0B06D0 - 0x0B0AF0)
 *
 * Dateiverwaltungs- und Laderoutinen für Heldendatensätze (0x5ef Bytes je Held) zwischen den Spielstands- und
 * Arbeitsverzeichnissen (p:\riva\source\cpp\loaders.cpp).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 3/5 gleich (suche.py 25.10.2026, Basis loaders_P1.CPP)
// language.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B0530-0x0B06D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
void *f_014540(int size, const char *file, int line);

int f_0ed8f0(const char *a, int b, ...);





int f_14d0d7(const char *p1);
int f_14d0d7(const char *p1, int p2);
int f_149336(const char *p1);
#pragma aux f_149336 parm [eax] modify exact [eax];
int f_144fbf(const char *p, int fl, ...);
int f_144e8b(int fd, void *buf, int n);
int f_144cb6(int fd, void *buf, int n);
int f_145259(int fd);
int f_144bf0(int a, int b);
int f_14572e(char *buf, const char *fmt, ...);
extern const char d_1a51b4[];
extern char d_1b81f4[], d_1b81fa[], d_1b8200[], d_1c1190[];
extern char *d_1a9674, *d_1a9678;
int f_0b0a00(int p1, short *p2, int p3);
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0b06d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion kopiert eine Datei blockweise in Stücken zu je 20.000 Bytes von einem
 *   Quellpfad in einen Zielpfad und meldet bei fehlender Quelldatei einen Dateifehler (0x29a0012) an die
 *   Fehlerbehandlung (f_0ed8f0).
 * - Eingaben: Als Parameter werden der Dateipfad der Quelldatei (p1) sowie der Dateipfad der neu anzulegenden
 *   Zieldatei (p2) übergeben.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Datei erfolgreich kopiert wurde, und 0, falls sich die
 *   Quelldatei nicht öffnen ließ.
 === Ende Beschreibung === */
int f_0b06d0(char *p1, char *p2)
{
    struct S { int r; } s;
    struct S *v = &s;
    char *a = p1;
    char *b = p2;
    char *buf = (char *)f_014540(20000 | (v->r = 0), d_1a51b4, 0x30);
    short fd = f_144fbf(a, 0);
    if (fd == -1) f_0ed8f0(d_1c1190, 0x29a0012, a);
    if (fd != -1) {
        short out = f_14d0d7(b, 0);
        unsigned short n;
        for (;;) {
            n = f_144e8b(fd, buf, 20000);
            if (n == 0 || n == 0xffff) break;
            f_144cb6(out, buf, n & 0xffff);
        }
        f_145259(out);
        s.r = 1;
    }
    f_145259(fd);
    delete buf;
    return s.r;
}
//@ f_0b0790
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion lädt einen einzelnen, 0x5ef (1.519) Bytes großen Heldendatensatz anhand
 *   seines Index aus einer Heldendatei über den globalen Dateimanager (d_1c2098) in den bereitgestellten
 *   Zielpuffer.
 * - Eingaben: Übergeben werden der nullbasierte Datensatzindex des Helden (p1), die Ressourcenkennung der
 *   Heldendatei (p2) sowie ein Zeiger auf den 0x5ef Bytes großen Zielpuffer (p3).
 * - Rückgabewert: Die Funktion gibt die Anzahl der gelesenen Bytes (0x5ef bei Erfolg) oder 0 zurück, wenn die
 *   Datei nicht geöffnet werden konnte.
 === Ende Beschreibung === */
int f_0b0790(int p1, unsigned p2, int p3)
{
    int r;
    if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p2 | 0x40000000, 0x200) == 1) {
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( (short)p1 * 0x5ef, 0);
        r = ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( (void *)p3), 0x5ef)));
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    } else r = 0;
    return r;
}
//@ f_0b0800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion löscht einen einzelnen Heldendatensatz am angegebenen Index aus einer
 *   Heldendatei im ..\TEMP\-Verzeichnis, indem sie die Datei zunächst nach t.$$$ kopiert, alle übrigen
 *   Datensätze (0x5ef Bytes) ohne den zu löschenden Index zurückschreibt, die temporäre Datei entfernt und bei
 *   der Haupt-Heldendatei (0x90001) die aktualisierte Datei zusätzlich in das ..\GAMES\-Verzeichnis überträgt.
 * - Eingaben: Übergeben werden die Ressourcenkennung der Heldendatei (p1, z. B. 0x90001 oder 0x90002) und der
 *   Index des zu entfernenden Heldendatensatzes (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0800(int p1, short p2)
{
    char *a = (char *)f_014540(100, d_1a51b4, 0x89);
    char *b = (char *)f_014540(100, d_1a51b4, 0x8a);
    char *c = (char *)f_014540(0x5ef, d_1a51b4, 0x8b);
    short in, out, i, done, n;
    f_14572e(a, d_1a9674, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p1))));
    strcpy(b, d_1b81f4);
    f_0b06d0(a, b);
    f_149336(a);
    out = f_14d0d7(a, 0x180);
    in = f_144fbf(d_1b81fa, 2);
    i = 0;
    done = 0;
    do {
        n = f_144e8b(in, c, 0x5ef);
        if (n != 0x5ef) done = 1;
        else if (i != p2) f_144cb6(out, c, 0x5ef);
        i++;
    } while (!done);
    f_145259(in);
    f_145259(out);
    f_149336(d_1b8200);
    if (p1 == 0x90001) {
        f_14572e(a, d_1a9674, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p1))));
        f_14572e(b, d_1a9678, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p1))));
        f_0b06d0(a, b);
    }
    delete c;
    delete a;
    delete b;
}
//@ f_0b09b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion entfernt einen Helden anhand seines internen Dateinamens sowohl aus der
 *   temporären Gruppen-/Heldendatei (0x90002) als auch aus der allgemeinen Helden-Stammdatei (0x90001), sofern
 *   dort jeweils ein passender Datensatz über f_0b0a00 gefunden wird.
 * - Eingaben: Als Parameter wird ein Zeiger auf den zu suchenden internen Heldendateinamen (p1) übergeben.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b09b0(int p1)
{
    short s[2];
    if (f_0b0a00(p1, s, 0x90002)) f_0b0800(0x90002, s[0]);
    if (f_0b0a00(p1, s, 0x90001)) f_0b0800(0x90001, s[0]);
}
//@ f_0b0a00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion durchsucht eine Heldendatei (p3) sequenziell in 0x5ef-Byte-Schritten nach
 *   einem Helden, dessen interner Dateiname (Offset +0x12, abgefragt über f_042320) mit dem gesuchten Namen
 *   übereinstimmt, und speichert den gefundenen Datensatzindex im Ausgabeparameter (p2, bzw. -1 bei erfolgloser
 *   Suche).
 * - Eingaben: Übergeben werden der gesuchte Heldendateiname (p1), ein Zeiger auf ein short-Feld zur Aufnahme des
 *   gefundenen Datensatzindex (p2) sowie die Ressourcenkennung der zu durchsuchenden Heldendatei (p3).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held in der Datei gefunden wurde, und 0, falls kein
 *   passender Eintrag existiert (*p2 == -1).
 === Ende Beschreibung === */
int f_0b0a00(int p1, short *p2, int p3)
{
    char *buf = (char *)f_014540(0x5ef, d_1a51b4, 0xeb);
    int done = 0;
    unsigned m = p3 | 0x40000000;
    short idx, r;
    *p2 = 0;
    do {
        idx = *p2;
        if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( m, 0x200) == 1) {
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( idx * 0x5ef, 0);
            r = ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( buf), 0x5ef)));
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
        } else r = 0;
        if (r != 0x5ef) { done = 1; *p2 = -1; }
        if (!done) {
            if (f_144bf0(p1, ((int)(f_042320((struct hero *)(buf))))) == 0) done = 1;
            else (*p2)++;
        }
    } while (!done);
    delete buf;
    return *p2 != -1;
}
