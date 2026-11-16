/* === Beschreibung (Katalog) ===
 * Einheit lang_dan (0x0ABF50 - 0x0ACAC0)
 *
 * Diese Einheit implementiert das Sprachmodul für Dänisch (p:\riva\source\cpp\lang_dan.cpp) mit Deklinations-,
 * Artikel- und Pronomenlogik der mehrsprachigen Text-Engine.
 === Ende Beschreibung === */
// P3 5/8 gleich (suche.py 24.10.2026, Basis lang_dan_P1.CPP)
// lang_dan.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ABF50-0x0ACAC0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4e30;                    // 0x1A4E30
extern int d_1a4e34;                    // 0x1A4E34
extern int d_1a4e38;                    // 0x1A4E38
extern int d_1a4e3c;                    // 0x1A4E3C
extern int d_1a4e40;                    // 0x1A4E40
extern int d_1a4e44;                    // 0x1A4E44
extern int d_1a4e48;                    // 0x1A4E48
extern int d_1a4e4c;                    // 0x1A4E4C
extern int d_1a4e54;                    // 0x1A4E54
extern int d_1a4e58;                    // 0x1A4E58
extern int d_1a4e5c;                    // 0x1A4E5C
extern int d_1a4e60;                    // 0x1A4E60
extern int d_1a4e64;                    // 0x1A4E64
extern int d_1a4e6c;                    // 0x1A4E6C
extern int d_1a4e70;                    // 0x1A4E70
extern int d_1be410;                    // 0x1BE410
extern int d_1be414;                    // 0x1BE414
extern int d_1be418;                    // 0x1BE418
extern int d_1be41c;                    // 0x1BE41C
extern int d_1be420;                    // 0x1BE420
extern int d_1be424;                    // 0x1BE424
extern int d_1be428;                    // 0x1BE428
extern int d_1be42c;                    // 0x1BE42C
extern int d_1be430;                    // 0x1BE430
extern int d_1be434;                    // 0x1BE434
extern int d_1be438;                    // 0x1BE438
extern int d_1be43c;                    // 0x1BE43C
extern int d_1be440;                    // 0x1BE440
extern int d_1be444;                    // 0x1BE444
extern int d_1be448;                    // 0x1BE448
extern int d_1be44c;                    // 0x1BE44C
extern int d_1be450;                    // 0x1BE450
extern int d_1be454;                    // 0x1BE454
extern int d_1be458;                    // 0x1BE458
extern int d_1be45c;                    // 0x1BE45C
extern int d_1be460;                    // 0x1BE460
extern int d_1be464;                    // 0x1BE464
extern int d_1be468;                    // 0x1BE468
extern int d_1be46c;                    // 0x1BE46C
extern int d_1be470;                    // 0x1BE470
extern int d_1be474;                    // 0x1BE474
extern int d_1be478;                    // 0x1BE478
extern int d_1be47c;                    // 0x1BE47C
extern int d_1be480;                    // 0x1BE480
extern int d_1be484;                    // 0x1BE484
extern int d_1be488;                    // 0x1BE488
extern int d_1be48c;                    // 0x1BE48C
extern int d_1be490;                    // 0x1BE490
extern int d_1be494;                    // 0x1BE494
extern int d_1be498;                    // 0x1BE498
extern int d_1be49c;                    // 0x1BE49C
extern int d_1be4a0;                    // 0x1BE4A0
extern int d_1be4a4;                    // 0x1BE4A4
extern int d_1be4a8;                    // 0x1BE4A8
extern int d_1be4ac;                    // 0x1BE4AC
extern int d_1be4b0;                    // 0x1BE4B0
extern int d_1be4b4;                    // 0x1BE4B4
extern int d_1be4b8;                    // 0x1BE4B8
extern int d_1be4bc;                    // 0x1BE4BC
extern int d_1be4c0;                    // 0x1BE4C0
extern int d_1be4c4;                    // 0x1BE4C4
extern int d_1be4c8;                    // 0x1BE4C8
extern int d_1be4cc;                    // 0x1BE4CC
extern int d_1be4d0;                    // 0x1BE4D0
extern int d_1be4d4;                    // 0x1BE4D4
extern int d_1be4d8;                    // 0x1BE4D8
extern int d_1be4dc;                    // 0x1BE4DC
extern int d_1be4e0;                    // 0x1BE4E0
extern int d_1be4e4;                    // 0x1BE4E4
extern int d_1be4e8;                    // 0x1BE4E8
extern int d_1be4ec;                    // 0x1BE4EC
extern int d_1be4f0;                    // 0x1BE4F0
extern const char d_1a4e10[];           // Text 0x1A4E10
#include <ctype.h>
extern int d_1a4e50;
extern int d_1a4e68;
extern int d_1a4e74;
extern unsigned char d_1bbfdc[];
extern const char d_1b7dcc[];
extern const char d_1b7dce[];
extern const char d_1b7dd1[];
extern const char d_1b7dd3[];
extern const char d_1b7dd6[];
extern const char d_1b7dd9[];
extern const char d_1b7ddd[];
extern const char d_1b7de0[];
extern const char d_1b7de4[];
extern const char d_1b7de8[];
extern const char d_1b7dec[];
extern const char d_1b7dee[];
extern const char d_1b7df1[];
extern const char d_1b7df3[];
extern const char d_1b7df6[];
int f_15ea62(int);
struct BF4 { unsigned char b01:2, b23:2, b47:4; };
struct BF3 { unsigned char a01:2, f3:3, d57:3; };
struct BF3W { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
#define T4 struct BF4
#define T3 struct BF3
#define T3W struct BF3W
#define B01(c) ((c).b01)
#define B23(c) ((c).b23)
#define P34(c) ((c).f3)
#define P3H(c) ((c).e)
#define ISV(c) ((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u'||(c)=='A'||(c)=='E'||(c)=='I'||(c)=='O'||(c)=='U')
#define DBL if (!ISV(c1) && ISV(c2)) { t[0] = c1; strcat(buf, t); }
#define EE(a,b) if (c1 == 'e' || c1 == 'E') strcat(buf, a); else strcat(buf, b);
//@ f_0abf50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1be410 bis d_1be4f0) für die dänischen
 *   Possessivpronomen ("hans", "hendes", "dets", "dens", "deres"), Personalpronomen ("han", "hun", "det", "den",
 *   "ham", "hende", "de", "dem") und unbestimmten Artikel ("et", "en").
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0abf50(void)
{
    d_1be410 = d_1a4e64;
    d_1be414 = d_1a4e68;
    d_1be418 = d_1a4e6c;
    d_1be41c = d_1a4e70;
    d_1be420 = d_1a4e64;
    d_1be424 = d_1a4e68;
    d_1be428 = d_1a4e6c;
    d_1be440 = d_1a4e74;
    d_1be42c = d_1a4e70;
    d_1be444 = d_1a4e74;
    d_1be430 = d_1a4e64;
    d_1be448 = d_1a4e74;
    d_1be434 = d_1a4e68;
    d_1be44c = d_1a4e74;
    d_1be438 = d_1a4e6c;
    d_1be450 = d_1a4e74;
    d_1be43c = d_1a4e70;
    d_1be454 = d_1a4e74;
    d_1be460 = d_1a4e3c;
    d_1be458 = d_1a4e74;
    d_1be464 = d_1a4e40;
    d_1be45c = d_1a4e74;
    d_1be468 = d_1a4e44;
    d_1be4a0 = d_1a4e5c;
    d_1be46c = d_1a4e48;
    d_1be4a4 = d_1a4e5c;
    d_1be470 = d_1a4e3c;
    d_1be4a8 = d_1a4e5c;
    d_1be474 = d_1a4e40;
    d_1be4ac = d_1a4e5c;
    d_1be478 = d_1a4e44;
    d_1be4b0 = d_1a4e5c;
    d_1be47c = d_1a4e48;
    d_1be4b4 = d_1a4e5c;
    d_1be480 = d_1a4e4c;
    d_1be4b8 = d_1a4e5c;
    d_1be484 = d_1a4e50;
    d_1be4bc = d_1a4e5c;
    d_1be488 = d_1a4e54;
    d_1be4c0 = d_1a4e60;
    d_1be48c = d_1a4e58;
    d_1be4c4 = d_1a4e60;
    d_1be490 = d_1a4e4c;
    d_1be4c8 = d_1a4e60;
    d_1be494 = d_1a4e50;
    d_1be4cc = d_1a4e60;
    d_1be498 = d_1a4e54;
    d_1be4d0 = d_1a4e60;
    d_1be49c = d_1a4e58;
    d_1be4d4 = d_1a4e60;
    d_1be4e0 = d_1a4e30;
    d_1be4e4 = d_1a4e30;
    d_1be4e8 = d_1a4e30;
    d_1be4d8 = d_1a4e60;
    d_1be4ec = d_1a4e34;
    d_1be4dc = d_1a4e60;
    d_1be4f0 = d_1a4e38;
}
//@ f_0ac150
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt für ein dänisches Substantiv (p2) einen neu allokierten Ausgabepuffer und bildet je
 *   nach Artikelmodus (p3), Numerus und Genus (p4) die Form mit angehängtem bestimmten Artikel ("-en", "-et",
 *   "-ene", "-ne" samt Konsonantenverdopplung), vorangestelltem unbestimmten Artikel ("en ", "et ") oder
 *   Pluralendung ("-er"). Wegen eines fehlenden break nach case 2 und eines wirkungslosen toupper-Aufrufs
 *   (f_15ea62) am Ende enthält die Funktion jedoch zwei Originalfehler (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Substantiv (p2), die Grammatik- und
 *   Artikelmodus-Bitfelder (p3, p4) sowie ein ungenutzter Zusatzparameter (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der gebildeten
 *   Wortform zurück.
 === Ende Beschreibung === */
char *f_0ac150(int p1, char *p2, T3W p3, T4 p4, int p5)
{
    short n = strlen(p2) + 10;
    char *buf = new (mark(d_1a4e10, 0x68)) char[n];
    memset(buf, 0, n);
    char c1 = p2[strlen(p2) - 1];
    char c2 = p2[strlen(p2) - 2];
    char t[2];
    t[1] = 0;
    switch (P3H(p3)) {
    case 2:
        DBL
        if (B23(p4) == 0) {
            strcat(buf, p2);
            switch (B01(p4)) {
            case 0:
            case 1:
                EE(d_1b7dcc, d_1b7dce)
                break;
            case 2:
                EE(d_1b7dd1, d_1b7dd3)
                break;
            }
        }
        if (B23(p4) == 1) {
            strcat(buf, p2);
            switch (B01(p4)) {
            case 0:
            case 1:
                EE(d_1b7dd6, d_1b7dd9)
                break;
            case 2:
                EE(d_1b7ddd, d_1b7de0)
                break;
            }
        }
    case 1:
        DBL
        if (B23(p4) == 0) {
            switch (B01(p4)) {
            case 0:
            case 1:
                strcat(buf, d_1b7de4);
                break;
            case 2:
                strcat(buf, d_1b7de8);
                break;
            }
            strcat(buf, p2);
        }
        if (B23(p4) == 1) {
            strcat(buf, p2);
            switch (B01(p4)) {
            case 0:
            case 1:
                EE(d_1b7dec, d_1b7dee)
                break;
            case 2:
                if (c1 == 'e' || c1 == 'E') strcat(buf, d_1b7df1);
                break;
            }
        }
        break;
    case 0:
        strcat(buf, p2);
        break;
    case 4:
        if (B01(p4) == 0) strcat(buf, d_1b7df3);
        if (B01(p4) == 2) strcat(buf, d_1b7df6);
        break;
    }
    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) {
        short k, i;
        k = strlen(buf);
        for (i = 0; i < 3; i++) {
            f_15ea62((signed char)buf[k--]);
        }
    }
    return buf;
}
//@ f_0ac800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und kopiert das passende dänische Personalpronomen
 *   (z. B. "han", "hun", "det", "den", "ham", "hende", "de", "dem") anhand von Kasus (p2), Numerus und Genus
 *   (p3) aus der Tabelle d_1be460 hinein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Kasus-Bitfeld (p2) sowie das Numerus-
 *   und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Personalpronomen zurück.
 === Ende Beschreibung === */
char *f_0ac800(int p1, T3W p2, T4 p3)
{
    char *buf = new (mark(d_1a4e10, 0x138)) char[10];
    memset(buf, 0, 10);
    strcat(buf, ((char *(*)[4])&d_1be460)[B23(p3) * 4 + P34(p2)][B01(p3)]);
    return buf;
}
//@ f_0ac8a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden bestimmten Artikel der dänischen Tabelle d_1be4e0 anhand von Kasus (p3),
 *   Numerus und Genus (p4) an den übergebenen Ausgabepuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), das Kasus-Bitfeld
 *   (p3) und das Numerus- und Genus-Byte (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ac8a0(int p1, char *p2, T3 p3, unsigned char p4)
{
    unsigned char x = p4;
    x <<= 4;
    x >>= 6;
    strcat(p2, ((char *(*)[3])&d_1be4e0)[P34(p3) + x * 4][p4 & 3]);
}
//@ f_0ac910
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden unbestimmten Artikel ("et" oder "en") aus der Tabelle d_1be4ec anhand
 *   von Kasus (p3), Numerus und Genus (p4) an den übergebenen Ausgabepuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), das Kasus-Bitfeld
 *   (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ac910(int p1, char *p2, T3W p3, T4 p4)
{
    strcat(p2, ((char *(*)[2])&d_1be4ec)[P34(p3) + B23(p4) * 4][B01(p4)]);
}
//@ f_0ac970
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob ein übergebenes Wort (p2) maskulin ist (p1.b01 == 0) und auf die Buchstabenfolge
 *   "-en" endet (Hilfsprüfung für schwache Deklination).
 * - Eingaben: Übergeben werden das Numerus- und Genus-Bitfeld (p1) und die zu prüfende Zeichenkette (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Wort maskulin ist und auf "en" endet, und sonst 0.
 === Ende Beschreibung === */
int f_0ac970(T4 p1, signed char *p2)
{
    int r = 0;
    if (p2 != 0 && *p2 != 0) {
        char c1 = tolower(p2[strlen((char *)p2) - 1]);
        char c2 = tolower(p2[strlen((char *)p2) - 2]);
        if (B01(p1) == 0 && c1 == 'n' && c2 == 'e') r = 1;
    }
    return r;
}
//@ f_0ac9e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als leere Platzhaltermethode der dänischen Sprachklasse für die separate
 *   Substantivbeugung, da im Dänischen Artikel und Endungen bereits in f_0ac150 zusammengefügt werden.
 * - Eingaben: Übergeben werden sechs ungenutzte Parameter der virtuellen Methodensignatur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ac9e0(int a, int b, int c, int d, int e, int f)
{
}
//@ f_0ac9f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende dänische
 *   Possessivpronomen ("hans", "hendes", "dets", "dens" oder "deres") anhand von Artikelmodus (p2), Objekt-Genus
 *   (p3), Kasus (p4) und Besitzer-Numerus/Genus (p5) aus den Tabellen d_1be410 bis d_1be450 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Artikelmodus (p2), das
 *   Bezugswort-Genus (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Possessivpronomen
 *   zurück.
 === Ende Beschreibung === */
char *f_0ac9f0(int p1, short p2, volatile short p3, unsigned char p4, volatile unsigned char p5)
{
    char *buf = new (mark(d_1a4e10, 400)) char[10];
    char *(*t)[4];
    unsigned char g, i2, i3;
    memset(buf, 0, 10);
    if (p2 == 0) {
        i2 = p5;
        i2 <<= 4;
        i2 >>= 6;
        if (i2 == 1) {
            t = (char *(*)[4])&d_1be440;
        } else {
            g = p5;
            g &= 3;
            switch (g) {
            case 0:
                t = (char *(*)[4])&d_1be410;
                break;
            case 1:
                t = (char *(*)[4])&d_1be420;
                break;
            case 2:
                t = (char *(*)[4])&d_1be430;
                break;
            }
        }
    } else {
        t = (char *(*)[4])&d_1be450;
    }
    i3 = p4;
    i3 <<= 3;
    i3 >>= 5;
    strcat(buf, t[i3][p3]);
    return buf;
}
