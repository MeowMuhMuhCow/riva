/* === Beschreibung (Katalog) ===
 * Einheit table (0x11eae0 - 0x11ed00)
 *
 * Überblick
 * Diese Einheit implementiert Hilfsfunktionen zum Lesen von Tabellendateien (table.cpp), die im Dateikopf eine
 * 12-Byte-Kennung, ein 4-Byte-Formatkürzel (ARR für feste Array-Tabellen oder LST für indizierte Listen) und
 * eine 16-Bit-Größenangabe besitzen.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 1/2 gleich (suche.py 24.10.2026, Basis table_P1.CPP)
// table.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11EAE0-0x11ED00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a7eb8[];           // Text 0x1A7EB8
extern const char d_1b8368[];
extern const char d_1b836c[];

int f_144bf0(const char *a, const char *b);

//@ f_11eae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet eine Tabellendatei im Lesezugriff, überspringt den 16-Byte-Vorspann (12-Byte-Name und
 *   4-Byte-Typkennung) und liest das 16-Bit-Größenfeld aus dem Dateikopf aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tabellen-Hilfsobjekts und in p2 die
 *   Datei-ID der Tabellendatei.
 * - Rückgabewert: Die Funktion gibt das aus dem Dateikopf gelesene Größenwort zurück (wobei die oberen 16 Bits
 *   von local uninitialisiert bleiben und vom Aufrufer als short ausgewertet werden).
 === Ende Beschreibung === */
int f_11eae0(int p1, int p2)
{
    int local;
    char *a;
    char *b;
    a = new (mark(d_1a7eb8, 0x5b)) char[12];
    b = new (mark(d_1a7eb8, 0x5c)) char[4];
    if (p2 == 0x220009 || p2 == 0x220011 || p2 == 0x22000a)
        ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( p2, 0x200);
    else
        ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( p2 | 0x40000000, 0x200);
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)a), 0xc)));
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)b), 4)));
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)&local), 2)));
    ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
    delete b;
    delete a;
    return local;
}

//@ f_11ebc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Positioniert den Dateizeiger innerhalb einer bereits geöffneten Tabellendatei auf den Datensatz mit
 *   dem Index p2 und der Satzlänge p3, wobei sowohl direkt indizierte Array-Tabellen (ARR) als auch mit Kennung
 *   versehene Listentabellen (LST) unterstützt werden.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tabellen-Hilfsobjekts, in p2 den gesuchten
 *   Datensatzindex und in p3 die Bytegröße eines einzelnen Datensatzes.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der gesuchte Datensatz gefunden und angesteuert wurde, oder
 *   0, falls der Index in einer LST-Tabelle nicht existiert.
 === Ende Beschreibung === */
int f_11ebc0(int p1, int p2, int p3)
{
    int r;
    char *a;
    char *b;
    short size;
    short ack;
    short i;
    short pp = p2;
    r = 1;
    a = new (mark(d_1a7eb8, 0x80)) char[12];
    b = new (mark(d_1a7eb8, 0x81)) char[4];
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)a), 0xc)));
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)b), 4)));
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)&size), 2)));
    size += 0x10;
    if (f_144bf0(b, d_1b8368) == 0) {
        ((RivaFileManager*)((int)&d_1c2098))->f_144ab0( pp * p3, 1);
    } else if (f_144bf0(b, d_1b836c) == 0) {
        int g = (int)&d_1c2098;
        i = 0;
        ack = 0;
        do {
            ((int)(((RivaFileManager*)(g))->f_144920((void *)( (int)&ack), 2)));
            if (ack != (short)p2)
                i = ((RivaFileManager*)(g))->f_144ab0( p3, 1);
        } while (ack != (short)p2 && i < size);
        if (ack != (short)p2)
            r = 0;
    }
    delete b;
    delete a;
    return r;
}
