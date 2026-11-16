/* === Beschreibung (Katalog) ===
 * Einheit lang_fin (0x0ACB00 - 0x0ADD30)
 *
 * Diese Einheit enthält das Sprachmodul für Finnisch (p:\riva\source\cpp\lang_fin.cpp, f_0acb00 bis f_0ace90)
 * sowie den Hauptteil des Sprachmoduls für Deutsch (p:\riva\source\cpp\LANG_GER.CPP, f_0acea0 bis f_0adc50).
 === Ende Beschreibung === */
// P3 14/16 gleich (suche.py 26.10.2026, Basis lang_fin_P1.CPP)
// lang_fin.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ACB00-0x0ADD30
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4e98;                    // 0x1A4E98
extern int d_1a4e9c;                    // 0x1A4E9C
extern int d_1a4ea0;                    // 0x1A4EA0
extern int d_1a4ea4;                    // 0x1A4EA4
extern int d_1a4ea8;                    // 0x1A4EA8
extern int d_1a4eac;                    // 0x1A4EAC
extern int d_1a4eb0;                    // 0x1A4EB0
extern int d_1a4eb4;                    // 0x1A4EB4
extern int d_1a4eb8;                    // 0x1A4EB8
extern int d_1a4ebc;                    // 0x1A4EBC
extern int d_1a4ee8;                    // 0x1A4EE8
extern int d_1a4eec;                    // 0x1A4EEC
extern int d_1a4ef0;                    // 0x1A4EF0
extern int d_1a4ef4;                    // 0x1A4EF4
extern int d_1a4ef8;                    // 0x1A4EF8
extern int d_1a4efc;                    // 0x1A4EFC
extern int d_1a4f00;                    // 0x1A4F00
extern int d_1a4f04;                    // 0x1A4F04
extern int d_1a4f14;                    // 0x1A4F14
extern int d_1a4f1c;                    // 0x1A4F1C
extern int d_1a4f20;                    // 0x1A4F20
extern int d_1a4f24;                    // 0x1A4F24
extern int d_1a4f28;                    // 0x1A4F28
extern int d_1a4f2c;                    // 0x1A4F2C
extern int d_1a4f30;                    // 0x1A4F30
extern int d_1a4f34;                    // 0x1A4F34
extern int d_1a4f38;                    // 0x1A4F38
extern int d_1a4f40;                    // 0x1A4F40
extern int d_1a4f44;                    // 0x1A4F44
extern int d_1a4f48;                    // 0x1A4F48
extern int d_1a4f50;                    // 0x1A4F50
extern char d_1b7ea0[];                    // 0x1B7EA0
extern char d_1b7ea2[];                    // 0x1B7EA2
extern char d_1b7ea4[];                    // 0x1B7EA4
extern char d_1b7ea6[];                    // 0x1B7EA6
extern char d_1b7ea8[];                    // 0x1B7EA8
extern char d_1b7eab[];                    // 0x1B7EAB
extern char d_1b7eae[];                    // 0x1B7EAE
extern char d_1b7eb0[];                    // 0x1B7EB0
extern char d_1b7eb2[];                    // 0x1B7EB2
extern char d_1b7eb4[];                    // 0x1B7EB4
extern char d_1b7eb6[];                    // 0x1B7EB6
extern char d_1b7eb9[];                    // 0x1B7EB9
extern char d_1b7ebc[];                    // 0x1B7EBC
extern char d_1b7ebe[];                    // 0x1B7EBE
extern unsigned char d_1bbfdc[];                    // 0x1BBFDC
extern int d_1be4f4;                    // 0x1BE4F4
extern int d_1be4f8;                    // 0x1BE4F8
extern int d_1be4fc;                    // 0x1BE4FC
extern int d_1be500;                    // 0x1BE500
extern int d_1be504;                    // 0x1BE504
extern int d_1be508;                    // 0x1BE508
extern int d_1be50c;                    // 0x1BE50C
extern int d_1be510;                    // 0x1BE510
extern int d_1be514;                    // 0x1BE514
extern int d_1be518;                    // 0x1BE518
extern int d_1be51c;                    // 0x1BE51C
extern int d_1be520;                    // 0x1BE520
extern int d_1be524;                    // 0x1BE524
extern int d_1be528;                    // 0x1BE528
extern int d_1be52c;                    // 0x1BE52C
extern int d_1be530;                    // 0x1BE530
extern int d_1be534;                    // 0x1BE534
extern int d_1be538;                    // 0x1BE538
extern int d_1be53c;                    // 0x1BE53C
extern int d_1be540;                    // 0x1BE540
extern int d_1be544;                    // 0x1BE544
extern int d_1be548;                    // 0x1BE548
extern int d_1be54c;                    // 0x1BE54C
extern int d_1be550;                    // 0x1BE550
extern int d_1be554;                    // 0x1BE554
extern int d_1be558;                    // 0x1BE558
extern int d_1be55c;                    // 0x1BE55C
extern int d_1be560;                    // 0x1BE560
extern int d_1be564;                    // 0x1BE564
extern int d_1be568;                    // 0x1BE568
extern int d_1be56c;                    // 0x1BE56C
extern int d_1be570;                    // 0x1BE570
extern int d_1be574;                    // 0x1BE574
extern int d_1be578;                    // 0x1BE578
extern int d_1be57c;                    // 0x1BE57C
extern int d_1be580;                    // 0x1BE580
extern int d_1be584;                    // 0x1BE584
extern int d_1be588;                    // 0x1BE588
extern int d_1be58c;                    // 0x1BE58C
extern int d_1be590;                    // 0x1BE590
extern int d_1be594;                    // 0x1BE594
extern int d_1be598;                    // 0x1BE598
extern int d_1be59c;                    // 0x1BE59C
extern int d_1be5a0;                    // 0x1BE5A0
extern int d_1be5a4;                    // 0x1BE5A4
extern int d_1be5a8;                    // 0x1BE5A8
extern int d_1be5ac;                    // 0x1BE5AC
extern int d_1be5b0;                    // 0x1BE5B0
extern int d_1be5b4;                    // 0x1BE5B4
extern int d_1be5b8;                    // 0x1BE5B8
extern int d_1be5bc;                    // 0x1BE5BC
extern int d_1be5c0;                    // 0x1BE5C0
extern int d_1be5c4;                    // 0x1BE5C4
extern int d_1be5c8;                    // 0x1BE5C8
extern int d_1be5cc;                    // 0x1BE5CC
extern int d_1be5d0;                    // 0x1BE5D0
extern int d_1be5d4;                    // 0x1BE5D4
extern int d_1be5d8;                    // 0x1BE5D8
extern int d_1be5dc;                    // 0x1BE5DC
extern int d_1be5e0;                    // 0x1BE5E0
extern int d_1be5e4;                    // 0x1BE5E4
extern int d_1be5e8;                    // 0x1BE5E8
extern int d_1be5ec;                    // 0x1BE5EC
extern int d_1be5f0;                    // 0x1BE5F0
extern int d_1be5f4;                    // 0x1BE5F4
extern int d_1be5f8;                    // 0x1BE5F8
extern int d_1be5fc;                    // 0x1BE5FC
extern int d_1be600;                    // 0x1BE600
extern int d_1be604;                    // 0x1BE604
extern int d_1be608;                    // 0x1BE608
extern int d_1be60c;                    // 0x1BE60C
extern int d_1be610;                    // 0x1BE610
extern int d_1be614;                    // 0x1BE614
extern int d_1be618;                    // 0x1BE618
extern int d_1be61c;                    // 0x1BE61C
extern int d_1be620;                    // 0x1BE620
extern int d_1be624;                    // 0x1BE624
extern int d_1be628;                    // 0x1BE628
extern int d_1be62c;                    // 0x1BE62C
extern int d_1be630;                    // 0x1BE630
extern int d_1be634;                    // 0x1BE634
extern int d_1be638;                    // 0x1BE638
extern int d_1be63c;                    // 0x1BE63C
extern int d_1be640;                    // 0x1BE640
extern int d_1be644;                    // 0x1BE644
extern int d_1be648;                    // 0x1BE648
extern int d_1be64c;                    // 0x1BE64C
extern int d_1be650;                    // 0x1BE650
extern int d_1be654;                    // 0x1BE654
extern int d_1be658;                    // 0x1BE658
extern int d_1be65c;                    // 0x1BE65C
extern int d_1be660;                    // 0x1BE660
extern int d_1be664;                    // 0x1BE664
extern int d_1be668;                    // 0x1BE668
extern int d_1be66c;                    // 0x1BE66C
extern int d_1be670;                    // 0x1BE670
extern int d_1be674;                    // 0x1BE674
extern int d_1be678;                    // 0x1BE678
extern int d_1be67c;                    // 0x1BE67C
extern int d_1be680;                    // 0x1BE680
extern int d_1be684;                    // 0x1BE684
extern int d_1be688;                    // 0x1BE688
extern int d_1be68c;                    // 0x1BE68C
extern int d_1be690;                    // 0x1BE690
extern int d_1be694;                    // 0x1BE694
extern int d_1be698;                    // 0x1BE698
extern int d_1be69c;                    // 0x1BE69C
extern int d_1be6a0;                    // 0x1BE6A0
extern int d_1be6a4;                    // 0x1BE6A4
extern int d_1be6a8;                    // 0x1BE6A8
extern int d_1be6ac;                    // 0x1BE6AC
extern int d_1be6b0;                    // 0x1BE6B0
extern int d_1be6b4;                    // 0x1BE6B4
extern int d_1be6b8;                    // 0x1BE6B8
extern int d_1be6bc;                    // 0x1BE6BC
extern int d_1be6c0;                    // 0x1BE6C0
extern int d_1be6c4;                    // 0x1BE6C4
extern int d_1be6c8;                    // 0x1BE6C8
extern int d_1be6cc;                    // 0x1BE6CC
extern int d_1be6d0;                    // 0x1BE6D0
extern int d_1be6d4;                    // 0x1BE6D4
extern int d_1be6d8;                    // 0x1BE6D8
extern int d_1be6dc;                    // 0x1BE6DC
extern int d_1be6e0;                    // 0x1BE6E0
extern int d_1be6e4;                    // 0x1BE6E4
extern int d_1be6e8;                    // 0x1BE6E8
extern int d_1be6ec;                    // 0x1BE6EC
extern int d_1be6f0;                    // 0x1BE6F0
extern int d_1be6f4;                    // 0x1BE6F4
extern int d_1be6f8;                    // 0x1BE6F8
extern int d_1be6fc;                    // 0x1BE6FC
extern int d_1be700;                    // 0x1BE700
extern int d_1be704;                    // 0x1BE704
extern int d_1be708;                    // 0x1BE708
extern int d_1be70c;                    // 0x1BE70C
extern int d_1be710;                    // 0x1BE710
extern int d_1be714;                    // 0x1BE714
extern int d_1be718;                    // 0x1BE718
extern int d_1be71c;                    // 0x1BE71C
extern int d_1be720;                    // 0x1BE720
extern int d_1be724;                    // 0x1BE724
extern int d_1be728;                    // 0x1BE728
extern int d_1be72c;                    // 0x1BE72C
extern int d_1be730;                    // 0x1BE730
extern int d_1be734;                    // 0x1BE734
extern int d_1be738;                    // 0x1BE738
extern int d_1be73c;                    // 0x1BE73C
extern int d_1be740;                    // 0x1BE740
extern int d_1be744;                    // 0x1BE744
extern int d_1be748;                    // 0x1BE748
extern int d_1be74c;                    // 0x1BE74C
extern int d_1be750;                    // 0x1BE750
extern int d_1be754;                    // 0x1BE754
extern int d_1be758;                    // 0x1BE758
extern int d_1be75c;                    // 0x1BE75C
extern int d_1be760;                    // 0x1BE760
extern int d_1be764;                    // 0x1BE764
extern int d_1be768;                    // 0x1BE768
extern int d_1be76c;                    // 0x1BE76C
extern int d_1be770;                    // 0x1BE770
extern int d_1be774;                    // 0x1BE774
extern int d_1be778;                    // 0x1BE778
extern int d_1be77c;                    // 0x1BE77C
extern int d_1be780;                    // 0x1BE780
extern int d_1be784;                    // 0x1BE784
extern int d_1be788;                    // 0x1BE788
extern int d_1be78c;                    // 0x1BE78C
extern int d_1be790;                    // 0x1BE790
extern int d_1be794;                    // 0x1BE794
extern int d_1be798;                    // 0x1BE798
extern int d_1be79c;                    // 0x1BE79C
extern struct S50 d_1be7a0;                    // 0x1BE7A0
extern const char d_1a4e78[];           // Text 0x1A4E78
extern const char d_1a4ec8[];           // Text 0x1A4EC8
extern const char d_1b7e50[];           // Text 0x1B7E50
extern int d_1a4ec0;
extern int d_1a4f08;
extern int d_1a4f0c;
extern int d_1a4f10;
extern int d_1a4f18;
extern int d_1a4f3c;
extern int d_1a4f4c;
extern int d_1a4f54;
extern int d_1a4f58;
extern int d_1a4f5c;
extern int d_1a4f60;
extern int d_1a4f64;
extern int d_1a4f68;
extern int d_1a4f6c;
extern int d_1a4f70;
extern char d_1b7e9c[];
extern char d_1b7e9e[];
extern unsigned char d_1bbfdc[];
struct S50 { char c[50]; };
extern struct S50 d_1be7a0;
int f_15ea70(int);
char *f_14d50b(char *, const char *);
void *f_145300(void *p, int c, unsigned n);
#define B3S(t,x) t = (x); t <<= 3; t >>= 5
#define B2S(t,x) t = (x); t <<= 4; t >>= 6
struct O;
struct VT { int s0; void (*m1)(struct O *, char *, int, unsigned char); void (*m2)(struct O *, char *, int, unsigned char); void (*m3)(struct O *, char *, char *, int, int, int); };
struct O { char c; struct VT *vt; };
typedef char *T43[4][3];
//@ f_0acb00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1be4f4 bis d_1be58c) für die finnischen
 *   Personal- und Possessivpronomen ("hän", "se", "häntä", "sitä", "he", "heitä", "hänen", "heidän", "hän
 *   tuntee", "he tuntevat").
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0acb00(void)
{
    d_1be4f4 = d_1a4eb4;
    d_1be4f8 = d_1a4eb4;
    d_1be4fc = d_1a4ebc;
    d_1be500 = d_1a4eb4;
    d_1be504 = d_1a4eb4;
    d_1be508 = d_1a4ebc;
    d_1be50c = d_1a4eb4;
    d_1be510 = d_1a4eb4;
    d_1be514 = d_1a4ebc;
    d_1be518 = d_1a4eb4;
    d_1be51c = d_1a4eb4;
    d_1be520 = d_1a4ebc;
    d_1be534 = d_1a4eb0;
    d_1be53c = d_1a4eb0;
    d_1be540 = d_1a4eb0;
    d_1be544 = d_1a4eb0;
    d_1be548 = d_1a4eb0;
    d_1be54c = d_1a4eb0;
    d_1be550 = d_1a4eb0;
    d_1be524 = d_1a4eb8;
    d_1be528 = d_1a4eb8;
    d_1be558 = d_1a4eb0;
    d_1be52c = d_1a4ec0;
    d_1be56c = d_1a4eb0;
    d_1be530 = d_1a4e98;
    d_1be570 = d_1a4eb0;
    d_1be538 = d_1a4e9c;
    d_1be574 = d_1a4eb0;
    d_1be554 = d_1a4ea0;
    d_1be578 = d_1a4eb0;
    d_1be55c = d_1a4ea4;
    d_1be57c = d_1a4eb0;
    d_1be560 = d_1a4ea8;
    d_1be564 = d_1a4ea8;
    d_1be568 = d_1a4ea8;
    d_1be580 = d_1a4eb0;
    d_1be584 = d_1a4eac;
    d_1be588 = d_1a4eac;
    d_1be58c = d_1a4eac;
}

//@ f_0acc20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als leere Platzhalterfunktion des finnischen Sprachmoduls für das Anfügen von
 *   Artikeln, da das Finnische keine Artikel besitzt.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0acc20(void)
{
}

//@ f_0acc30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Allokiert für ein finnisches Substantiv (s) einen um 10 Byte vergrößerten Ausgabepuffer und
 *   ruft im unbestimmten bzw. artikellosen Modus (w.e == 0) die virtuelle Wortbeugungsmethode (m3 bei Offset
 *   +0x0c) auf; in allen anderen Modi (w.e != 0) bleibt der Puffer leer (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das finnische Sprachmodul (this), das Substantiv (s), die
 *   Grammatik-Bitfelder (w, a) sowie ein Zusatzparameter (b).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer zurück.
 === Ende Beschreibung === */
struct FinBits3W0 { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
char *f_0acc30(struct O *o, char *s, struct FinBits3W0 w, unsigned char a, int b)
{
    short n = strlen(s) + 10;
    char *buf = new (mark(d_1a4e78, 0xcf)) char[n];
    f_145300(buf, 0, n);
    switch (w.e) {
    case 0:
        o->vt->m3(o, buf, s, w.f3, (*&a), b);
        break;
    }
    return buf;
}
//@ f_0accd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert im finnischen Sprachmodul das übergebene Substantiv (src) unverändert per strcat an
 *   das Ende des Zielpuffers (dst).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (dst), das Quellwort (src)
 *   sowie drei ungenutzte Grammatikparameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0accd0(int p1, char *dst, char *src, int p4, int p5, int p6)
{
    strcat(dst, src);
}
//@ f_0acd00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende finnische
 *   Possessivpronomen ("hänen" oder "heidän") anhand von Artikelmodus (p2), Kasus (p4) und
 *   Besitzer-Numerus/Genus (p5) aus den Tabellen d_1be4f4 bis d_1be524 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Modusflag (p2), ein ungenutztes
 *   Objekt-Genus (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Possessivpronomen
 *   zurück.
 === Ende Beschreibung === */
char *f_0acd00(int p1, short p2, int p3, unsigned char p4, unsigned char p5)
{
    char *buf = new (mark(d_1a4e78, 0x166)) char[10];
    char **t;
    unsigned char g, i2, i3;
    buf[0] = 0;
    if (p2 == 0) {
        B2S(i2, p5);
        if (i2 == 1) {
            t = (char **)&d_1be518;
        } else {
            g = p5;
            g &= 3;
            switch (g) {
            case 0: t = (char **)&d_1be4f4; break;
            case 1: t = (char **)&d_1be500; break;
            case 2: t = (char **)&d_1be50c; break;
            }
        }
    } else {
        t = (char **)&d_1be524;
    }
    B3S(i3, p4);
    strcat(buf, t[i3]);
    return buf;
}
//@ f_0acdc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende finnische
 *   Personalpronomen ("hän", "se", "häntä", "sitä", "he", "heitä") anhand von Kasus (p2), Numerus und Genus (p3)
 *   aus der Tabelle d_1be530 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Kasus-Bitfeld (p2) und das Numerus-
 *   und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Personalpronomen zurück.
 === Ende Beschreibung === */
struct BF4 { unsigned char b01:2, b23:2, b47:4; };
struct BF3W { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
#define T4 struct BF4
#define T3W struct BF3W
#define B01(c) ((c).b01)
#define B23(c) ((c).b23)
#define P34(c) ((c).f3)
char *f_0acdc0(int p1, T3W p2, T4 p3)
{
    char *buf = new (mark(d_1a4e78, 0x1a3)) char[10];
    *buf = 0;
    strcat(buf, ((char *(*)[3])&d_1be530)[P34(p2) + B23(p3) * 4][B01(p3)]);
    return buf;
}

//@ f_0ace60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wählt im finnischen Sprachmodul aus einem mit Punkten getrennten Vorlagenstring (p4) je nach
 *   Anzahl (p5 <= 1 für Singular-Modus 1, p5 > 1 für Plural-Modus 2) den passenden Teilstring über f_0b0460 aus
 *   und schreibt ihn nach p2.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), ein ungenutzter
 *   Zweitpuffer (p3), der Vorlagenstring (p4), die Anzahl (p5) sowie zwei ungenutzte Parameter (p6, p7).
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0b0460 zurück.
 === Ende Beschreibung === */
int f_0ace60(int p1, int p2, int p3, int p4, short p5, int p6, int p7)
{
    if (p5 <= 1) return f_0b0460(p2, p4, 1);
    else return f_0b0460(p2, p4, 2);
}
//@ f_0ace90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den englischen Namen des finnischen Sprachmoduls ("Finnish" bei d_1b7e50) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Finnish" zurück.
 === Ende Beschreibung === */
char *f_0ace90(void)
{
    return (char *)d_1b7e50;
}

//@ f_0acea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen deutschen Grammatiktabellen (d_1be590 bis d_1be79c) für
 *   Possessivpronomen ("sein", "seine", "seines", "seiner", "seinem", "seinen", "ihr", "ihre", "ihres", "ihrer",
 *   "ihrem", "ihren"), Personalpronomen ("er", "sie", "es", "ihm", "ihr", "ihn", "euch"), bestimmte Artikel
 *   ("der", "die", "das", "des", "dem", "den") und unbestimmte Artikel ("ein", "eine", "eines", "einer",
 *   "einem", "einen").
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0acea0(void)
{
  int r_edx, r_ebx, r_ecx, r_edi, r_esi, r_ebp, r_eax;
  r_edx = d_1a4f1c;
  r_ebx = d_1a4f50;
  r_ecx = d_1a4f4c;
  r_esi = d_1a4eec;
  r_edi = d_1a4f24;
  r_ebp = d_1a4f60;
  r_eax = d_1a4f44;
  *(volatile int *)&d_1be590 = r_eax;
  r_eax = d_1a4f48;
  d_1be594 = r_eax;
  r_eax = d_1a4f44;
  d_1be598 = r_eax;
  r_eax = d_1a4f58;
  d_1be59c = r_eax;
  r_eax = d_1a4f5c;
  d_1be5a0 = r_eax;
  r_eax = d_1a4f58;
  d_1be5a4 = r_eax;
  r_eax = d_1a4f64;
  d_1be5a8 = r_eax;
  r_eax = d_1a4f68;
  d_1be5ac = r_eax;
  r_eax = d_1a4f64;
  d_1be5b0 = r_eax;
  r_eax = d_1a4f6c;
  d_1be5b4 = r_eax;
  r_eax = d_1a4f70;
  d_1be5b8 = r_eax;
  r_eax = d_1a4f6c;
  d_1be5bc = r_eax;
  r_eax = d_1a4f54;
  d_1be5d0 = r_eax;
  d_1be5dc = r_eax;
  r_eax = d_1a4f44;
  d_1be5c0 = r_ecx;
  d_1be5f0 = r_eax;
  r_eax = d_1a4f48;
  d_1be5c4 = r_ebx;
  d_1be5f4 = r_eax;
  r_eax = d_1a4f44;
  d_1be5c8 = r_ecx;
  d_1be5f8 = r_eax;
  r_eax = d_1a4f58;
  d_1be5cc = r_ebp;
  d_1be5fc = r_eax;
  r_eax = d_1a4f5c;
  d_1be5d4 = r_ebp;
  d_1be600 = r_eax;
  r_eax = d_1a4f58;
  d_1be5d8 = r_ebp;
  d_1be604 = r_eax;
  r_eax = d_1a4f64;
  d_1be5e0 = r_ebp;
  d_1be608 = r_eax;
  r_eax = d_1a4f68;
  d_1be5e4 = r_ecx;
  d_1be60c = r_eax;
  r_eax = d_1a4f64;
  d_1be5e8 = r_ebx;
  d_1be610 = r_eax;
  r_eax = d_1a4f44;
  d_1be5ec = r_ecx;
  d_1be614 = r_eax;
  r_eax = d_1a4f48;
  d_1be620 = r_ecx;
  d_1be618 = r_eax;
  r_eax = d_1a4f44;
  d_1be624 = r_ebx;
  d_1be61c = r_eax;
  r_eax = d_1a4f54;
  d_1be628 = r_ecx;
  d_1be630 = r_eax;
  r_eax = d_1a4f6c;
  d_1be62c = r_ebp;
  d_1be638 = r_eax;
  r_eax = d_1a4f70;
  d_1be634 = r_ebp;
  d_1be63c = r_eax;
  r_eax = d_1a4f6c;
  d_1be644 = r_ecx;
  d_1be640 = r_eax;
  r_eax = d_1a4f54;
  d_1be648 = r_ebx;
  d_1be65c = r_eax;
  d_1be660 = r_eax;
  d_1be664 = r_eax;
  r_eax = d_1a4f70;
  d_1be64c = r_ecx;
  d_1be668 = r_eax;
  d_1be66c = r_eax;
  d_1be670 = r_eax;
  r_eax = d_1a4f20;
  d_1be650 = r_ebx;
  d_1be680 = r_eax;
  r_eax = d_1a4f28;
  d_1be654 = r_ebx;
  d_1be688 = r_eax;
  r_eax = d_1a4f3c;
  d_1be658 = r_ebx;
  d_1be68c = r_eax;
  r_eax = d_1a4f40;
  d_1be674 = r_ebx;
  d_1be690 = r_eax;
  r_eax = d_1a4f3c;
  d_1be678 = r_ebx;
  d_1be694 = r_eax;
  r_eax = d_1a4f2c;
  d_1be67c = r_ebx;
  d_1be698 = r_eax;
  r_eax = d_1a4f30;
  d_1be684 = r_edi;
  d_1be69c = r_eax;
  r_eax = d_1a4f2c;
  d_1be6a8 = r_edi;
  d_1be6a0 = r_eax;
  r_eax = d_1a4f38;
  d_1be6b0 = r_edi;
  d_1be6a4 = r_eax;
  r_eax = d_1a4f28;
  d_1be6b4 = r_edi;
  d_1be6ac = r_eax;
  r_eax = d_1a4f30;
  *(volatile int *)&d_1be6b8 = r_edi;
  d_1be6bc = r_eax;
  d_1be6c0 = r_eax;
  d_1be6c4 = r_eax;
  r_eax = d_1a4f34;
  d_1be6c8 = r_eax;
  d_1be6cc = r_eax;
  d_1be6d0 = r_eax;
  r_eax = d_1a4ee8;
  d_1be6e0 = r_eax;
  r_eax = d_1a4ef0;
  d_1be6d4 = r_edi;
  d_1be6e8 = r_eax;
  r_eax = d_1a4ef4;
  d_1be6d8 = r_edi;
  d_1be6ec = r_eax;
  r_eax = d_1a4ee8;
  d_1be6dc = r_edi;
  d_1be6f0 = r_eax;
  r_eax = d_1a4ef4;
  d_1be6e4 = r_esi;
  d_1be6f4 = r_eax;
  r_eax = d_1a4efc;
  d_1be708 = r_esi;
  d_1be6f8 = r_eax;
  r_eax = d_1a4ee8;
  d_1be710 = r_esi;
  d_1be6fc = r_eax;
  r_eax = d_1a4efc;
  *(volatile int *)&d_1be714 = r_esi;
  d_1be700 = r_eax;
  r_eax = d_1a4ef8;
  d_1be718 = r_esi;
  d_1be704 = r_eax;
  r_eax = d_1a4ef0;
  d_1be734 = r_esi;
  d_1be70c = r_eax;
  r_eax = d_1a4ee8;
  d_1be738 = r_esi;
  d_1be71c = r_eax;
  d_1be720 = r_eax;
  d_1be724 = r_eax;
  r_eax = d_1a4ef8;
  d_1be73c = r_esi;
  d_1be728 = r_eax;
  d_1be72c = r_eax;
  d_1be730 = r_eax;
  r_eax = d_1a4f00;
  d_1be770 = r_edx;
  d_1be740 = r_eax;
  r_eax = d_1a4f04;
  d_1be774 = r_edx;
  d_1be744 = r_eax;
  r_eax = d_1a4f00;
  d_1be778 = r_edx;
  d_1be748 = r_eax;
  r_eax = d_1a4f08;
  d_1be77c = r_edx;
  d_1be74c = r_eax;
  r_eax = d_1a4f0c;
  d_1be780 = r_edx;
  d_1be750 = r_eax;
  r_eax = d_1a4f08;
  d_1be784 = r_edx;
  d_1be754 = r_eax;
  r_eax = d_1a4f18;
  d_1be788 = r_edx;
  d_1be758 = r_eax;
  r_eax = d_1a4f0c;
  d_1be78c = r_edx;
  d_1be75c = r_eax;
  r_eax = d_1a4f18;
  d_1be790 = r_edx;
  d_1be760 = r_eax;
  r_eax = d_1a4f10;
  d_1be794 = r_edx;
  d_1be764 = r_eax;
  r_eax = d_1a4f14;
  d_1be798 = r_edx;
  d_1be768 = r_eax;
  r_eax = d_1a4f00;
  d_1be79c = r_edx;
  d_1be76c = r_eax;
}

//@ f_0ad300
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bildet für ein deutsches Substantiv (s) in einem neu allokierten Puffer die vollständige
 *   Nominalphrase je nach Modus (w.e): bestimmter Artikel + Leerzeichen + gebeugtes Substantiv (case 2),
 *   unbestimmter Artikel + Leerzeichen + gebeugtes Substantiv (case 1), nur gebeugtes Substantiv (case 0), nur
 *   bestimmter Artikel (case 3) oder nur unbestimmter Artikel (case 4).
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (o), das Substantiv (s), das Modus- und
 *   Kasus-Bitfeld (w), das Numerus- und Genus-Bitfeld (a) sowie ein Kontextwort (b).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der fertigen
 *   deutschen Nominalphrase zurück.
 === Ende Beschreibung === */
struct FinBits4 { unsigned char b01:2, b23:2, b47:4; };
struct FinBits3W { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
typedef void (*FinFS)(struct O *, char *, struct FinBits3W, struct FinBits4);
typedef void (*FinFT)(struct O *, char *, char *, unsigned char, struct FinBits4, int);
char *f_0ad300(struct O *o, char *s, struct FinBits3W w, struct FinBits4 a, int b)
{
    short n = strlen(s) + 10;
    char *buf = new (mark(d_1a4ec8, 0x94)) char[n];
    memset(buf, 0, n);
    switch (w.e) {
    case 2:
        (*(FinFS *)((char *)o->vt + 4))(o, buf, w, a);
        if (*buf) strcat(buf, d_1b7e9c);
        (*(FinFT *)((char *)o->vt + 0xc))(o, buf, s, w.f3, a, b);
        break;
    case 1:
        (*(FinFS *)((char *)o->vt + 8))(o, buf, w, a);
        if (*buf) strcat(buf, d_1b7e9e);
        (*(FinFT *)((char *)o->vt + 0xc))(o, buf, s, w.f3, a, b);
        break;
    case 0:
        (*(FinFT *)((char *)o->vt + 0xc))(o, buf, s, w.f3, a, b);
        break;
    case 3:
        (*(FinFS *)((char *)o->vt + 4))(o, buf, w, a);
        break;
    case 4:
        (*(FinFS *)((char *)o->vt + 8))(o, buf, w, a);
        break;
    }
    return buf;
}
//@ f_0ad4d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und kopiert das passende deutsche Personalpronomen
 *   ("er", "sie", "es", "ihm", "ihr", "ihn", "seiner", "ihrer", "euch") anhand von Kasus (p2), Numerus und Genus
 *   (p3) aus der Tabelle d_1be680 hinein.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (this), das Kasus-Bitfeld (p2) und das
 *   Numerus- und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem deutschen
 *   Personalpronomen zurück.
 === Ende Beschreibung === */
struct BF4Fin { unsigned char b01:2, b23:2, b47:4; };
struct BF3WFin { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
char *f_0ad4d0(int p1, BF3WFin p2, BF4Fin p3)
{
    char *buf = new (mark(d_1a4ec8, 0xd1)) char[10];
    f_145300(buf, 0, 10);
    strcat(buf, ((char *(*)[3])&d_1be680)[p3.b23 * 4 + p2.f3][p3.b01]);
    return buf;
}
//@ f_0ad580
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden deutschen bestimmten Artikel ("der", "die", "das", "des", "dem", "den")
 *   anhand von Kasus (p3), Numerus und Genus (p4) aus der Tabelle d_1be6e0 an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (this), der Zielpuffer (p2), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ad580(int p1, char *p2, T3W p3, T4 p4)
{
    strcat(p2, ((char *(*)[3])&d_1be6e0)[P34(p3) + B23(p4) * 4][B01(p4)]);
}
//@ f_0ad5f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden deutschen unbestimmten Artikel ("ein", "eine", "eines", "einer",
 *   "einem", "einen") anhand von Kasus (p3), Numerus und Genus (p4) aus der Tabelle d_1be740 an den Zielpuffer
 *   (dst) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (this), der Zielpuffer (dst), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ad5f0(int p1, char *dst, BF3WFin p3, BF4Fin p4)
{
    strcat(dst, ((char *(*)[3])&d_1be740)[p3.f3 + p4.b23 * 4][p4.b01]);
}
//@ f_0ad660
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft im deutschen Sprachmodul, ob ein Wort (s) maskulin ist ((p1 & 3) == 0) und auf "-en"
 *   endet, um schwache maskuline Substantive bei der Deklination zu erkennen.
 * - Eingaben: Übergeben werden das Genus- und Numerus-Byte (p1) und die zu prüfende Zeichenkette (s).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Wort maskulin ist und auf "en" endet, und sonst 0.
 === Ende Beschreibung === */
int f_0ad660(unsigned char p1, char *s)
{
    int r = 0;
    if (s != 0 && *(signed char *)s != 0) {
        char c1 = f_15ea70((signed char)s[strlen(s) - 1]);
        char c2 = f_15ea70((signed char)s[strlen(s) - 2]);
        unsigned char g = p1;
        g &= 3;
        if (g == 0 && c1 == 'n' && c2 == 'e') r = 1;
    }
    return r;
}
//@ f_0ad6e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Beugt ein deutsches Substantiv (word) nach Kasus (mode) sowie Numerus und Genus (flags): Sie
 *   trennt zunächst einen etwaigen Klammerzusatz am Wortende (z. B. "(2H)") ab, hängt im Genitiv Singular (mode
 *   == 1) je nach Auslaut und Genus "-s", "-es", "-n" oder "-en" bzw. im Dativ Plural (mode == 2) "-n" an (in
 *   Groß- oder Kleinschreibung passend zum Wortende) und setzt Stamm und Klammerzusatz im Zielpuffer (out)
 *   wieder zusammen.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (this), der Ausgabepuffer (out), das
 *   Substantiv (word), der Kasus (mode: 0 = Nominativ, 1 = Genitiv, 2 = Dativ, 3 = Akkusativ), die Genus- und
 *   Numerus-Flags (flags) sowie ein Begleitwort (other).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ad6e0(int p1, char *out, char *word, short mode, struct FinBits4 flags, char *other)
{
    char buf[100];
    struct S50 buf2 = d_1be7a0;
    char *q;
    char c1, c2, c3, lc1;
    // haelt die Stapelplatz-Reihenfolge wie im Original
    char lc3, lc2;
    strcpy(buf, word);
    c1 = word[strlen(word) - 1];
    if (c1 == ')') {
        word = f_14d50b(word, d_1b7ea0);
        q = f_14d50b(buf, d_1b7ea2);
        if (word != 0 && q != 0) {
            char *p = word - 1;
            q--;
            while (*p == ' ') {
                p--;
                q--;
            }
            q++;
            strcpy(buf2.c, p + 1);
            *q = 0;
        }
    }
    c1 = buf[strlen(buf) - 1];
    c2 = buf[strlen(buf) - 2];
    c3 = buf[strlen(buf) - 3];
    lc1 = f_15ea70((signed char)c1);
    (*&lc2) = f_15ea70((signed char)c2);
    (*&lc3) = f_15ea70((signed char)c3);
    switch (mode) {
    case 0:
        break;
    case 1:
        if (flags.b23 == 0) {
            if (flags.b01 == 1) {
                if (other == 0 || *(signed char *)other == 0) {
                    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) strcat(buf, d_1b7ea4);
                    else strcat(buf, d_1b7ea6);
                }
            } else {
                if (flags.b01 != 2) {
                    unsigned char fp1 = *(unsigned char *)&flags;
                    int r = 0;
                    if (other != 0 && *(signed char *)other != 0) {
                        // haelt die Registerzuteilung wie im Original
                        word = (char *)f_15ea70((signed char)other[strlen(other) - 1]);
                        char fc2 = f_15ea70((signed char)other[strlen(other) - 2]);
                        unsigned char g = fp1;
                        g &= 3;
                        if (g == 0 && (char)(int)word == 'n' && fc2 == 'e') r = 1;
                    }
                    if (r || lc1 == 'k') goto else_branch;
                }
                if (lc1 == 's' || lc1 == 'x' || lc1 == 'z' || (lc1 == 't' && (*&lc2) == 's') || (lc1 == 'h' && (*&lc2) == 'c' && (*&lc3) == 's') || (strlen(buf) <= 4 && lc1 != 'r')) {
                    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) strcat(buf, d_1b7ea8);
                    else strcat(buf, d_1b7eab);
                } else {
                    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) strcat(buf, d_1b7eae);
                    else strcat(buf, d_1b7eb0);
                }
                break;
            else_branch:
                if (lc1 == 'e') {
                    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) strcat(buf, d_1b7eb2);
                    else strcat(buf, d_1b7eb4);
                } else {
                    if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) strcat(buf, d_1b7eb6);
                    else strcat(buf, d_1b7eb9);
                }
            }
        }
        break;
    case 2:
        if (flags.b23 == 1) {
            if (d_1bbfdc[(unsigned char)(c1 + 1)] & 0x40) {
                if (c1 != 'N' && c1 != 'S') strcat(buf, d_1b7ebc);
            } else {
                if (c1 != 'n' && c1 != 's') strcat(buf, d_1b7ebe);
            }
        }
        break;
    case 3:
        break;
    }
    strcat(out, buf);
    strcat(out, buf2.c);
}


//@ f_0adc50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende deutsche
 *   Possessivpronomen ("sein", "seine", "ihr", "ihre", "seines", "seinem", "seinen" usw.) anhand von
 *   Artikelmodus (p2), Bezugswort-Genus (p3), Kasus (p4) und Besitzer-Numerus/Genus (p5) aus den Tabellen
 *   d_1be590 bis d_1be650 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das deutsche Sprachmodul (this), das Modusflag (p2), das
 *   Bezugswort-Genus (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem deutschen
 *   Possessivpronomen zurück.
 === Ende Beschreibung === */
char *f_0adc50(int p1, short p2, short p3, int p4, unsigned char p5)
{
    char *buf = new (mark(d_1a4ec8, 0x1d5)) char[10];
    char *(*t)[3];
    unsigned char g, i2, i3;
    f_145300(buf, 0, 10);
    if (p2 == 0) {
        B2S(i2, p5);
        if (i2 == 1) {
            t = (char *(*)[3])&d_1be620;
        } else {
            g = p5;
            g &= 3;
            switch (g) {
            case 0: t = (char *(*)[3])&d_1be590; break;
            case 1: t = (char *(*)[3])&d_1be5c0; break;
            case 2: t = (char *(*)[3])&d_1be5f0; break;
            }
        }
    } else {
        t = (char *(*)[3])&d_1be650;
    }
    B3S(i3, p4);
    strcat(buf, t[i3][p3]);
    return buf;
}
