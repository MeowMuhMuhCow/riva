/* === Beschreibung (Katalog) ===
 * Einheit import (0a2810-0a3a80)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des Helden-Importmoduls (IMPORT.CPP), mit dem Heldengruppen aus
 * Spielständen von *DSA 1: Die Schicksalsklinge* und *DSA 2: Sternenschweif* (einschließlich
 * Amiga-/Big-Endian-Spielständen) nach *Schatten über Riva* übernommen werden. Sie enthält die
 * Dateikopf-Erkennung (f_0a2810), die Nachbearbeitung und Bonusberechnung für übernommene Ausrüstung (f_0a2e30),
 * das Rückrechnen aktiver temporärer Attributsmodifikatoren (f_0a3430, f_0a34d0), die
 * Porträt-Prüfsummenzuordnung (f_0a3570) sowie die Byte- und Bit-Konvertierungsfunktionen für Amiga-Spielstände
 * (f_0a3830 bis f_0a38d0).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 11/13 gleich (suche.py 30.10.2026, Basis import_P1.CPP)
// import.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A2810-0x0A3A80
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, const char *p2, int p3);
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0335d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0

                           // reg eax edx stapel 0

                   // reg eax edx ebx stapel 0
char f_043ac0(int p1, int p2);
int f_0449d0(int p1, int p2);                           // reg eax edx stapel 0
int f_044b60(int p1);                                   // reg eax stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0455b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_05a910(int p1, int p2);                           // reg eax edx stapel 0
int f_0a3c30(int p1, int p2, short p3);
int f_0a4690(int p1, int p2, short p3);
int f_0a5230(int p1, int p2);                           // reg eax edx stapel 0
int f_0a5240(int p1, int p2);                           // reg eax edx stapel 0




                                   // reg eax stapel 0
                                   // reg eax stapel 0
short f_0d4aa0(int p1, int p2);
int f_0d5290(int p1, int p2);                           // reg eax edx stapel 0
int f_148180(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bc88c;                    // 0x1BC88C
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
                    // 0x1C2098
extern int d_1c2c40;                    // 0x1C2C40
extern const char d_1a3c78[];           // Text 0x1A3C78
extern const char d_1a9680[];           // Text 0x1A9680
// --- eigene Funktionen (10), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

// --- Zusatz-Deklarationen ---
int f_059d50(int p1);
int f_059d50(int p1, int p2);

int f_014710(int p);



int f_144e8b(int fd, void *buf, int n);
unsigned f_1452bc(int fd);
int f_144bf0(const char *a, const char *b);
int f_145547(const char *a, const char *b, int n);
int f_1455a4(int fd);
short f_148170(short v);
int f_145279(int fd, int off, int wh);
extern const char d_1b7d40[];
struct T652 { char b[0x652]; };
extern char d_1c27a8[];
extern char d_1c27aa[];
extern signed char d_1c002c;
extern short d_1be1a0;
extern short *d_1be1a4;
extern short d_1a3cb0[];
extern short d_1a3cc0[];
extern char d_1a47ac[];
#define TB(x) (*(int *)(d_1c2c40 + (x) * 4))
#define LOADOBJ(L, q) q = (int)new (mark(d_1a3c78, L)) T652; if (q) q = f_059d50(q); f_05a910(q, ((int)(((RivaFileManager*)(&d_1c2098))->f_144850( 0x90000)))); d_1c0004 = (int)&d_1bfdbc + d_1c002c * 0x61; if (q) operator delete((void *)f_059d50(q, 0));

//@ f_0a2810
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft den Dateikopf einer geöffneten Spielstandsdatei p2, erkennt anhand der Kennung (d_1a9680
 *   bzw. d_1b7d40), des Versionsbytes (version = 1..3) und des Typs (type = 1, 2, 99), aus welchem Teil der
 *   Nordlandtrilogie und von welchem System (ls = 1 für Amiga/Big-Endian) der Spielstand stammt, lädt die
 *   Standard-Gruppendaten 0x90000 vor und verzweigt in den passenden Helden-Importer (f_0a4690, f_0a3c30,
 *   f_0a5240 oder f_0a5230).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (int *, in dessen *p1 ein temporärer Heldenpuffer
 *   von 0x5ef Bytes angelegt wird) sowie das Dateihandle p2 (short) und gibt den Statuscode des jeweiligen
 *   Importers (1 bei Erfolg, 0 oder -1 bei Fehler) zurück (int).
 * - Wichtige Variablen: Das Flag ls kennzeichnet fremde Byte-Ordnung (Amiga), hdr speichert den Datei-Offset des
 *   Heldenblocks und p1 + 1 (0x320 Bytes) puffert die 100 Einträge umfassende Tabelle temporärer Effekte für
 *   f_0a3430/f_0a34d0.
 === Ende Beschreibung === */
int f_0a2810(int *p1, short p2)
{
    int b2[0x10a];
    int b1[0x109];
    int hdr;
    short ls = 0;
    short saved2;
    short saved1;
    unsigned char flag;
    unsigned char type;
    unsigned char version;
    char tag;
    int pos;
    int sum;
    short i;
    int r;
    unsigned len;

    *p1 = f_014540(0x5ef, d_1a3c78, 0x7b);
    len = f_1452bc(p2);
    if (len < 0x6da && len < 0x6ca) {
        r = 0;
    } else {
        f_144e8b(p2, d_1c27a8, 12);
        if (!f_144bf0(d_1c27a8, d_1a9680)) {
            f_144e8b(p2, &tag, 1);
            if (tag == 'V') {
                f_144e8b(p2, d_1c27a8, (ls = 1, 5));
                f_144e8b(p2, &flag, 1);
                f_144e8b(p2, &version, 1);
                f_144e8b(p2, &type, 1);
                f_144e8b(p2, &tag, 1);
                f_144e8b(p2, &hdr, 4);
                pos = f_1455a4(p2);
                f_145279(p2, 0x155d, 0);
                saved1 = p2;
                f_144e8b(p2, b1, 0x424);
                sum = 0x1981;
                for (i = 0; i < 0x109; i++)
                    sum += (b1[i] = f_148180(b1[i]));
                f_145279(saved1, pos, 0);
                hdr = sum;
            } else {
                f_144e8b(p2, &type, 1);
                f_144e8b(p2, &version, 1);
                f_144e8b(p2, &flag, 1);
                f_144e8b(p2, &hdr, 4);
            }
        } else {
            if (f_145547(d_1c27aa, d_1b7d40, 8) == 0) {
                f_144e8b(p2, d_1c27a8, (ls = 1, 6));
                f_144e8b(p2, &flag, 1);
                f_144e8b(p2, &version, 1);
                f_144e8b(p2, &type, 1);
                f_144e8b(p2, &tag, 1);
                f_144e8b(p2, &hdr, 4);
                pos = f_1455a4(p2);
                f_145279(p2, 0x162f, 0);
                saved2 = p2;
                f_144e8b(p2, b2, 0x428);
                sum = 0x1a57;
                int j = 0;
                for (i = 0; (j = i) < 0x10a; i++)
                    sum += (b2[j] = f_148180(b2[j]));
                f_145279(saved2, pos, 0);
                hdr = sum;
            } else {
                f_145279(p2, 0, 0);
                type = 99;
                version = 1;
                f_144e8b(p2, &hdr, 4);
            }
        }
        switch (type) {
        case 1:
        case 99:
            p1[0xc9] = 1;
            f_145279(p2, ls ? 0xfb : 0xf8, 1);
            f_144e8b(p2, p1 + 1, 0x320);
            f_145279(p2, hdr, 0);
            switch (version) {
            case 1: {
                int q;
                int raw;
                q = (raw = (int)new (mark(d_1a3c78, 0xca)) T652) ? f_059d50(raw) : raw;
                f_05a910(q, ((int)(((RivaFileManager*)(&d_1c2098))->f_144850( 0x90000))));
                signed char zone = d_1c002c;
                d_1c0004 = (int)&d_1bfdbc + zone * 0x61;
                if (q) operator delete((void *)f_059d50(q, 0));
                r = f_0a4690((int)p1, p2, ls);
                break;
            }
            case 2:
            case 3: {
                int q;
                int raw;
                q = (raw = (int)new (mark(d_1a3c78, 0xe4)) T652) ? f_059d50(raw) : raw;
                f_05a910(q, ((int)(((RivaFileManager*)(&d_1c2098))->f_144850( 0x90000))));
                signed char zone = d_1c002c;
                d_1c0004 = (int)&d_1bfdbc + zone * 0x61;
                if (q) operator delete((void *)f_059d50(q, 0));
                r = f_0a3c30((int)p1, p2, ls);
                break;
            }
            default:
                r = 0;
            }
            break;
        case 2:
            switch (version) {
            case 1: {
                int q;
                int raw;
                q = (raw = (int)new (mark(d_1a3c78, 0x106)) T652) ? f_059d50(raw) : raw;
                f_05a910(q, ((int)(((RivaFileManager*)(&d_1c2098))->f_144850( 0x90000))));
                signed char zone = d_1c002c;
                d_1c0004 = (int)&d_1bfdbc + zone * 0x61;
                if (q) operator delete((void *)f_059d50(q, 0));
                r = f_0a5240((int)p1, p2);
                break;
            }
            case 2:
            case 3: {
                int q;
                int raw;
                q = (raw = (int)new (mark(d_1a3c78, 0x120)) T652) ? f_059d50(raw) : raw;
                f_05a910(q, ((int)(((RivaFileManager*)(&d_1c2098))->f_144850( 0x90000))));
                signed char zone = d_1c002c;
                d_1c0004 = (int)&d_1bfdbc + zone * 0x61;
                if (q) operator delete((void *)f_059d50(q, 0));
                r = f_0a5230((int)p1, p2);
                break;
            }
            default:
                r = 0;
            }
            break;
        default:
            r = 0;
        }
    }
    *p1 = f_014710(*p1);
    return r;
}

//@ f_0a2e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereinigt und aktualisiert die Ausrüstung, Eigenschaftsboni, Magieresistenz und
 *   Rüstungsschutzwerte eines frisch importierten Helden p2: Gegenstände an Körperplätzen (0..14), die der Held
 *   laut f_045960 nicht tragen darf, werden in den Rucksack (15..30) verschoben oder abgelegt; spezielle
 *   Artefakte (wie Krötenhaut, Gürtel der Stärke, Stirnreif, Ringe und Amulette) werden an ihre Zielplätze
 *   gelegt und ihre permanenten Eigenschafts- und MR-Boni angerechnet; schließlich wird der gesamte
 *   Rüstungsschutz (sum) aus den getragenen Rüstungsteilen neu summiert (f_0423d0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Kontext p1 sowie den Zeiger p2 auf den importierten
 *   Helden und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Beim Verschieben von Gegenständen aus den Händen (3, 12) wird für den Gegenstand 0xd9
 *   (ein Kopfgegenstand, der wenige Zeilen später in Slot 0 abgefragt wird) versehentlich Zielslot 8 statt 0
 *   verwendet und der Test für 0xd7 doppelt ausgeführt (siehe Fehlerliste).
 === Ende Beschreibung === */
void f_0a2e30(int p1, int p2)
{
    signed char sum = 0;
    short i=0; /* haelt die Registerzuteilung wie im Original */
    short j;
    short found;
    short kind;
    short left;
    short right;
    short item;
    int *table;
    d_1bc88c = 1;
    for (i = 0; i < 15; ++i) {
        item = f_042a60((struct hero *)(p2), i);
        table = (int *)d_1c2c40;
        kind = ((short)(((RivaItemDefinition*)(table[item]))->f_0a78e0()));
        if (f_045960(p2, item) == 0) {
            found = -1;
            for (j = 15; j <= 30; ++j) {
                if (!f_042a60((struct hero *)(p2), j)) {
                    if (found == -1)
                        found = j;
                }
                else {
                    int offset = 4 * (short)f_042a60((struct hero *)(p2), j);
                    table = (int *)d_1c2c40;
                    if (((short)(((RivaItemDefinition*)(*(int *)(offset + (int)table)))->f_0a78e0())) == kind) {
                        if (f_045960(p2, f_042a60((struct hero *)(p2), j)) != 0) {
                            found = -2;
                            f_032ab0(p2, i, j);
                            break;
                        }
                    }
                }
            }
            if (found == -1)
                f_036300(p2, i, 1);
            else if (found >= 15)
                f_032ab0(p2, i, found);
        }
    }
    left = f_042a60((struct hero *)(p2), 3);
    right = f_042a60((struct hero *)(p2), 12);
    if (left == 0xb7 && !f_042a60((struct hero *)(p2), 7)) f_032ab0(p2, 3, 7);
    if (right == 0xb7 && !f_042a60((struct hero *)(p2), 7)) f_032ab0(p2, 12, 7);
    if (left == 0xc4 && !f_042a60((struct hero *)(p2), 0)) f_032ab0(p2, 3, 0);
    if (right == 0xc4 && !f_042a60((struct hero *)(p2), 0)) f_032ab0(p2, 12, 0);
    if (left == 0xb6 && !f_042a60((struct hero *)(p2), 7)) f_032ab0(p2, 3, 7);
    if (right == 0xb6 && !f_042a60((struct hero *)(p2), 7)) f_032ab0(p2, 12, 7);
    if (left == 0xd7 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 3, 8);
    if (right == 0xd7 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 12, 8);
#if FIX_R015
    if (left == 0xd9 && !f_042a60((struct hero *)(p2), 0)) f_032ab0(p2, 3, 0);
    if (right == 0xd9 && !f_042a60((struct hero *)(p2), 0)) f_032ab0(p2, 12, 0);
#else
    if (left == 0xd9 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 3, 8);
    if (right == 0xd9 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 12, 8);
    if (left == 0xd7 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 3, 8);
    if (right == 0xd7 && !f_042a60((struct hero *)(p2), 8)) f_032ab0(p2, 12, 8);
#endif
    if (((char)(f_0423b0((struct hero *)(p2))))) f_0449d0(p2, (signed char)-((char)(f_0423b0((struct hero *)(p2)))));
    for (j = 0; j <= 13; ++j)
        f_0455b0(p2, j, (signed char)f_043ac0(p2, j));
    if (f_042a60((struct hero *)(p2), 7) == 0xb7) f_045430(p2, 6, 5);
    if (f_042a60((struct hero *)(p2), 0) == 0xc4) f_045430(p2, 2, -1);
    if (f_042a60((struct hero *)(p2), 0) == 0xd9) f_0449d0(p2, 2);
    if (f_042a60((struct hero *)(p2), 4) == 0xa5 || f_042a60((struct hero *)(p2), 13) == 0xa5) f_0449d0(p2, 2);
    if (f_042a60((struct hero *)(p2), 7) == 0xb6) f_045430(p2, 11, -4);
    if (f_042a60((struct hero *)(p2), 8) == 0xd7) f_045430(p2, 11, -2);
    if (f_042a60((struct hero *)(p2), 2) == 0x143 || f_042a60((struct hero *)(p2), 11) == 0x143) f_045430(p2, 8, -3);
    if (f_042a60((struct hero *)(p2), 2) == 0x144 || f_042a60((struct hero *)(p2), 11) == 0x144) f_045430(p2, 2, 5);
    if (f_0d4aa0(p2, 0xa3) != -1) f_0449d0(p2, 5);
    if (f_042a60((struct hero *)(p2), 4) == 0x1ab || f_042a60((struct hero *)(p2), 13) == 0x1ab) f_045430(p2, 3, 4);
    f_0449d0(p2, 0);
    f_044b60(p2);
    for (j = 0; j < 30; ++j) {
        if (f_042a60((struct hero *)(p2), j) == 0xd5)
            f_042e40((struct hero *)(p2), j, 1);
    }
    for (i = 0; i < 15; ++i) {
        item = f_042a60((struct hero *)(p2), i);
        table = (int *)d_1c2c40;
        // haelt die Stapelplatz-Reihenfolge wie im Original
        { int slot905 = (d_1c2c40 & 0) ? 0 : d_1c2c40; d_1c2c40 = slot905; }
        if (((RivaItemDefinition*)(table[item]))->f_0a79b0()) {
            if (i != 3 && i != 12 || (signed char)((char)(((RivaItemDefinition*)((table = (int *)d_1c2c40)[item]))->f_0a78b0())) == 9) {
                sum += d_1a47ac[2 * (signed char)((char)(((RivaItemDefinition*)(TB(item)))->f_0a78a0()))];
                ((char)(((RivaItemDefinition*)(TB(item)))->f_0a78a0()));
            }
        }
    }
    f_0423d0((struct hero *)(p2), sum);
    d_1bc88c = 0;
}

//@ f_0a3430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Macht bei einem aus *Sternenschweif* (Version 2/3) importierten Helden p2 alle noch im
 *   Spielstand aktiven temporären Eigenschaftsveränderungen (aus den 100 Timer-Einträgen zu je 8 Bytes ab p1 +
 *   4) rückgängig, damit temporäre Zauber- oder Elixierboni beim Import nicht dauerhaft erhalten bleiben, und
 *   löscht die Statusbits in *(int *)(p2 + 0xaa).
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1, den Rohdatenpuffer des Helden p2 sowie
 *   das Endian-Flag p3 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei p3 != 0 und noch nicht konvertierter Tabelle (*(int *)(p1 + 0x324) != 0) werden die
 *   100 Einträge zunächst über f_148180 und f_148170 bytegedreht; *(unsigned char *)(p2 + 0x7b) ist die
 *   Helden-ID im alten Spielstand.
 === Ende Beschreibung === */
void f_0a3430(int p1, int p2, short p3)
{
    short i;
    short j;
    unsigned char c;
    if (p3 && *(int *)(p1 + 0x324) != 0) {
        for (i = 0; i < 0x64; i++) {
            int e = p1 + i * 8;
            *(int *)(e + 4) = f_148180(*(int *)(e + 4));
            *(short *)(e + 8) = f_148170(*(short *)(e + 8));
        }
    }
    *(int *)(p1 + 0x324) = 0;
    for (j = 0; j < 0x64; j++) {
        char *e = (char *)(p1 + 4 + j * 8);
        if (*(int *)e != 0) {
            c = e[6];
            if (c && c == *(unsigned char *)(p2 + 0x7b)) {
                *(unsigned char *)(p2 + *(unsigned short *)(e + 4)) -= e[7];
            }
        }
    }
    *(int *)(p2 + 0xaa) &= 0x6fff;
}

//@ f_0a34d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Macht analog zu f_0a3430 bei einem älteren Spielstandsformat (Version 1, Helden-ID an Offset
 *   0x6b und Statusflags an Offset 0x9a) alle noch laufenden temporären Attributsboni aus der
 *   100-Einträge-Tabelle p1 + 4 rückgängig.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1, den Rohdatenpuffer p2 sowie das
 *   Endian-Flag p3 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Zuordnung zum Helden erfolgt hier über *(unsigned char *)(p2 + 0x6b) und die
 *   Statusbereinigung auf *(int *)(p2 + 0x9a) &= 0x6fff.
 === Ende Beschreibung === */
void f_0a34d0(int p1, int p2, short p3)
{
    short i;
    short j;
    unsigned char c;
    if (p3 && *(int *)(p1 + 0x324) != 0) {
        for (i = 0; i < 0x64; i++) {
            int e = p1 + i * 8;
            *(int *)(e + 4) = f_148180(*(int *)(e + 4));
            *(short *)(e + 8) = f_148170(*(short *)(e + 8));
        }
    }
    *(int *)(p1 + 0x324) = 0;
    for (j = 0; j < 0x64; j++) {
        char *e = (char *)(p1 + 4 + j * 8);
        if (*(int *)e != 0) {
            c = e[6];
            if (c) {
                if (c == *(unsigned char *)(p2 + 0x6b)) {
                    *(unsigned char *)(p2 + *(unsigned short *)(e + 4)) -= e[7];
                }
            }
        }
    }
    *(int *)(p2 + 0x9a) &= 0x6fff;
}

//@ f_0a3570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt für einen importierten Helden anhand der Byte-Prüfsumme seines im Spielstand
 *   eingebetteten Porträtbildes (data, 0x300 Bytes bei Amiga small != 0, sonst 0x400 Bytes) und der
 *   Vergleichstabelle 0x100000 den passenden Porträtindex in *Schatten über Riva*. Wird keine übereinstimmende
 *   Prüfsumme gefunden, erhält der Held das Standardporträt seines Typus (kind) und Geschlechts (alternate).
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter unused, den Porträt-Rohdatenzeiger
 *   data (signed char *), das Geschlechtsflag alternate (signed char), den Heldentypus kind (signed char) sowie
 *   das Formatflag small (short) und gibt den Riva-Porträtindex zurück (short).
 * - Wichtige Variablen: Die Arrays d_1a3c98 und d_1a3ca4 grenzen die Prüfsummenbereiche pro Heldentypus und
 *   Geschlecht ein, während d_1a3204 und d_1a3210 die Basis-Porträtindizes liefern.
 === Ende Beschreibung === */
extern signed char d_1a3c98[],d_1a3ca4[],d_1a3204[],d_1a3210[];
short f_0a3570(int unused,signed char *data,signed char alternate,signed char kind,short small)
{
    int checksum=0;
    short found=0;
    short result=0;
    short length=small ? 0x300:0x400;
    struct First { signed char v[12]; };
    struct Second { signed char v[11]; };
    First first=*(First*)d_1a3c98;
    Second second=*(Second*)d_1a3ca4;
    if(kind>10) kind=10;
    int *table=(int*)f_014540(0x100,d_1a3c78,0x289);
    short i;
    short offset;
    for(i=0;i<length;i++) checksum+=*data++;
    ((RivaFileManager*)((unsigned long)&d_1c2098))->f_1448b0(0x100000,0x200);
    ((RivaFileManager*)(&d_1c2098))->f_144920((void *)(table),0x100);
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    if(!alternate) {
        offset=0;
        for(i=first.v[kind];i<second.v[kind];i++,offset++) {
            if(checksum==table[i]) {
                found=1; result=d_1a3204[kind]+offset; break;
            }
        }
    } else {
        offset=0;
        for(i=second.v[kind];i<first.v[kind+1];i++,offset++) {
            if(checksum==table[i]) {
                found=1; result=d_1a3210[kind]+offset; break;
            }
        }
    }
    if(!found) result=alternate ? d_1a3210[kind]:d_1a3204[kind];
    table=(int*)f_014710((int)table);
    return result;
}

//@ f_0a3700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft für die 20 Attributs-/Statusindizes 0 bis 0x13 des importierten Helden p2 die
 *   Neuberechnungs- bzw. Rücksetzfunktion f_0d5290 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Zeiger p1 sowie den Heldenzeiger p2 und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die Schleifenvariable c durchläuft die Indizes 0 bis 19 (0x13).
 === Ende Beschreibung === */
void f_0a3700(int p1, int p2)
{
    signed char c;
    for (c = 0; c <= 0x13; c++) {
        f_0d5290(p2, c);
    }
}

//@ f_0a3730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entfernt beim Charakterimport einen nicht übernehmbaren Gegenstand aus dem Inventarplatz p2
 *   des Helden p1, zieht dessen Gewicht vom Gesamtgewicht *(short *)(p1 + 0x4ed) ab, verringert die
 *   Gegenstandsanzahl *(char *)(p1 + 0x32) um 1, nimmt bei Körperplätzen (p2 < 15) eventuelle Ausrüstungsboni
 *   über f_0335d0 zurück und löscht den 27-Byte-Inventarslot (0x1b Bytes).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 sowie den Inventarslot p2 (short, 0..30) und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(short *)(p1 + 0x1a8 + p2 * 0x1b) enthält die Gegenstands-ID und +0x1aa die
 *   Stückzahl bei stapelbaren Gegenständen (f_0a7950).
 === Ende Beschreibung === */
void f_0a3730(int p1, short p2)
{
    short p3 = p2;
    int o = p3 * 0x1b;
    int off;
    int q = p1 + o;
    short s = *(short *)(q + 0x1a8);
    int o2;
    if (!s) return;
    off = s * 4;
    if (((RivaItemDefinition*)(*(int *)(d_1c2c40 + off)))->f_0a7950()) {
        *(char *)(p1 + 0x32) = *(char *)(p1 + 0x32) - 1;
        *(short *)(p1 + 0x4ed) = *(short *)(p1 + 0x4ed) - ((RivaItemDefinition*)(*(int *)(d_1c2c40 + off)))->f_0a7810() * *(short *)(q + 0x1aa);
        memset((char *)(p1 + 0x1a8) + o, 0, 0x1b);
    } else {
        if (p3 < 0xf) f_0335d0(p1, s, p3);
        o2 = p2 * 0x1b;
        --*(char *)(p1 + 0x32);
        memset((char *)(p1 + 0x1a8) + o2, 0, 0x1b);
        *(short *)(p1 + 0x4ed) -= ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7810();
    }
}

//@ f_0a3830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entfernt ein auf dem Amiga (68000-Strukturausrichtung auf gerade Adressen) eingefügtes
 *   Füllbyte an der Position p1, indem der nachfolgende Rest des Heldenpuffers (p2 - p3 - 1 Bytes) per memmove
 *   um ein Byte nach vorn geschoben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Zieladresse p1 (char *), die Puffergröße p2 (int) sowie den
 *   aktuellen Strukturoffset p3 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Diese Funktion dient der Anpassung von 68k-gepackten Spielstandsstrukturen an das
 *   1-Byte-gepackte PC-Layout (-zp1).
 === Ende Beschreibung === */
void f_0a3830(char *p1, int p2, int p3)
{
    memmove(p1, p1 + 1, p2 - p3 - 1);
}

//@ f_0a3840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vertauscht die beiden Bytes eines 16-Bit-Wertes an der Adresse p1 zwischen Big-Endian- und
 *   Little-Endian-Darstellung.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (char *) auf ein 16-Bit-Wort und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Bytes p1[0] und p1[1] werden über t getauscht.
 === Ende Beschreibung === */
void f_0a3840(char *p1)
{
    char t = p1[0];
    p1[0] = p1[1];
    p1[1] = t;
}

//@ f_0a3850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kehrt die Reihenfolge der vier Bytes eines 32-Bit-Wertes an der Adresse p1 zwischen
 *   Big-Endian- und Little-Endian-Darstellung um.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (char *) auf ein 32-Bit-Wort und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Es werden p1[0] mit p1[3] sowie p1[1] mit p1[2] vertauscht.
 === Ende Beschreibung === */
void f_0a3850(char *p1)
{
    char t = p1[0];
    p1[0] = p1[3];
    p1[3] = t;
    t = p1[1];
    p1[1] = p1[2];
    p1[2] = t;
}

//@ f_0a3870
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kehrt die Reihenfolge aller 16 Bits eines 16-Bit-Bitfeldes *p1 um (Bit-Spiegelung für
 *   Amiga-Bitfelder).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned short *) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Schleife schiebt 16-mal das niederwertigste Bit von v in das Ergebnis r.
 === Ende Beschreibung === */
void f_0a3870(unsigned short *p1)
{
    unsigned short v = *p1; unsigned short r = 0; short i;
    for (i = 0; i < 0x10; i++) {
        r = r * 2;
        if (v & 1) r = r + 1;
        v >>= 1;
    }
    *p1 = r;
}

//@ f_0a38a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kehrt die Reihenfolge aller 32 Bits eines 32-Bit-Bitfeldes *p1 um.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned int *) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Schleife spiegelt alle 32 Bits von *p1 für die Konvertierung von Status-Bitfeldern.
 === Ende Beschreibung === */
void f_0a38a0(unsigned int *p1)
{
    unsigned int v = *p1; unsigned int r = 0; short i;
    for (i = 0; i < 0x20; i++) {
        r = r * 2;
        if (v & 1) r = r + 1;
        v = v >> 1;
    }
    *p1 = r;
}

//@ f_0a38d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konvertiert einen kompletten Helden-Rohdatensatz p1 der Größe p2 aus dem Amiga-Format der
 *   Version 1 in das PC-Format, indem die 68000-Füllbytes an 0x7b, 0x9a und in den 23 Inventarslots (0x186 + i *
 *   14 + 6) über f_0a3830 entfernt und anschließend sämtliche 16-Bit-Wörter (d_1a3cb0), 32-Bit-Wörter (d_1a3cc0)
 *   und Bitfelder (0x9a sowie die Slot-Flags) gedreht werden.
 * - Eingaben und Rückgabe: Die Funktion erhält die Pufferadresse p1 sowie die Datensatzgröße p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Offsetlisten d_1a3cb0 und d_1a3cc0 (jeweils mit -1 abgeschlossen) verzeichnen alle
 *   16-Bit- und 32-Bit-Felder des Heldendatensatzes.
 === Ende Beschreibung === */
void f_0a38d0(int p1, int p2)
{
    f_0a3830((char *)(p1 + 0x7b), p2, 0x7b);
    f_0a3830((char *)(p1 + 0x9a), p2, 0x9a);
    for (d_1be1a0 = 0; d_1be1a0 < 0x17; d_1be1a0++) {
        f_0a3830((char *)((p1 + 0x186) + d_1be1a0 * 0xe + 6), p2,
                 (p1 + 0x186) + d_1be1a0 * 0xe + 6 - p1);
        f_0a3830((char *)((p1 + 0x186) + d_1be1a0 * 0xe + 6), p2,
                 (p1 + 0x186) + d_1be1a0 * 0xe + 6 - p1);
    }
    for (d_1be1a4 = d_1a3cb0; *d_1be1a4 != -1; d_1be1a4++)
        f_0a3840((char *)(p1 + *d_1be1a4));
    for (d_1be1a4 = d_1a3cc0; *d_1be1a4 != -1; d_1be1a4++)
        f_0a3850((char *)(p1 + *d_1be1a4));
    f_0a38a0((unsigned int *)(p1 + 0x9a));
    for (d_1be1a0 = 0; d_1be1a0 < 0x17; d_1be1a0++) {
        f_0a3840((char *)(d_1be1a0 * 0xe + (p1 + 0x186) - p1 + p1));
        f_0a3840((char *)(d_1be1a0 * 0xe + (p1 + 0x186) - p1 + p1 + 2));
        f_0a3870((unsigned short *)(d_1be1a0 * 0xe + (p1 + 0x186) + 4));
    }
}
