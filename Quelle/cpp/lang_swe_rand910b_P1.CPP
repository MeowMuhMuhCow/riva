/* === Beschreibung (Katalog) ===
 * Einheit lang_swe_rand910b (0x0AFAB0 - 0x0B0410)
 *
 * Diese Einheit bildet den zweiten Teil der kombinierten Spracheinheit: Sie enthält das englische Sprachmodul
 * (p:\riva\source\cpp\LANG_US.CPP, f_0afab0 bis f_0b0210) sowie Vorwärtsdeklarationen des vorangehenden
 * schwedischen Sprachmoduls (f_0af220 bis f_0afaa0).
 === Ende Beschreibung === */
// P3 14/16 gleich (suche.py 30.10.2026, Basis lang_swe_P1.CPP)
// lang_swe.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AF220-0x0B0410
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0b0460(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a50f0;                    // 0x1A50F0
extern int d_1a50f4;                    // 0x1A50F4
extern int d_1a50f8;                    // 0x1A50F8
extern int d_1a5100;                    // 0x1A5100
extern int d_1a5104;                    // 0x1A5104
extern int d_1a5110;                    // 0x1A5110
extern int d_1a5114;                    // 0x1A5114
extern int d_1a5118;                    // 0x1A5118
extern int d_1a511c;                    // 0x1A511C
extern int d_1a514c;                    // 0x1A514C
extern int d_1a5150;                    // 0x1A5150
extern int d_1a5154;                    // 0x1A5154
extern int d_1a5158;                    // 0x1A5158
extern int d_1a515c;                    // 0x1A515C
extern int d_1a5160;                    // 0x1A5160
extern int d_1a5164;                    // 0x1A5164
extern int d_1a5168;                    // 0x1A5168
extern int d_1a516c;                    // 0x1A516C
extern int d_1a5170;                    // 0x1A5170
extern int d_1a5174;                    // 0x1A5174
extern int d_1a517c;                    // 0x1A517C
extern int d_1a5184;                    // 0x1A5184
extern int d_1a5188;                    // 0x1A5188
extern int d_1a518c;                    // 0x1A518C
extern int d_1bead4;                    // 0x1BEAD4
extern int d_1bead8;                    // 0x1BEAD8
/* KRUECKE: Feldsicht richtet die zyklisch vertauschten Registerrollen. */
struct Cell900_d_1beadc { int value; };
extern Cell900_d_1beadc d_1beadc;
#define d_1beadc d_1beadc.value
                    // 0x1BEADC
extern int d_1beae0;                    // 0x1BEAE0
extern int d_1beae4;                    // 0x1BEAE4
extern int d_1beae8;                    // 0x1BEAE8
extern int d_1beaec;                    // 0x1BEAEC
extern int d_1beaf0;                    // 0x1BEAF0
extern int d_1beaf4;                    // 0x1BEAF4
extern int d_1beaf8;                    // 0x1BEAF8
extern int d_1beafc;                    // 0x1BEAFC
extern int d_1beb00;                    // 0x1BEB00
extern int d_1beb04;                    // 0x1BEB04
extern int d_1beb08;                    // 0x1BEB08
extern int d_1beb0c;                    // 0x1BEB0C
extern int d_1beb10;                    // 0x1BEB10
extern int d_1beb14;                    // 0x1BEB14
/* KRUECKE: Feldsicht richtet die zyklisch vertauschten Registerrollen. */
struct Cell900_d_1beb18 { int value; };
extern Cell900_d_1beb18 d_1beb18;
#define d_1beb18 d_1beb18.value
                    // 0x1BEB18
extern int d_1beb1c;                    // 0x1BEB1C
extern int d_1beb20;                    // 0x1BEB20
extern int d_1beb24;                    // 0x1BEB24
extern int d_1beb28;                    // 0x1BEB28
extern int d_1beb2c;                    // 0x1BEB2C
extern int d_1beb30;                    // 0x1BEB30
extern int d_1beb34;                    // 0x1BEB34
extern int d_1beb38;                    // 0x1BEB38
extern int d_1beb3c;                    // 0x1BEB3C
extern int d_1beb40;                    // 0x1BEB40
extern int d_1beb44;                    // 0x1BEB44
extern int d_1beb48;                    // 0x1BEB48
extern int d_1beb4c;                    // 0x1BEB4C
extern int d_1beb50;                    // 0x1BEB50
extern int d_1beb54;                    // 0x1BEB54
extern int d_1beb58;                    // 0x1BEB58
extern int d_1beb5c;                    // 0x1BEB5C
extern int d_1beb60;                    // 0x1BEB60
extern int d_1beb64;                    // 0x1BEB64
extern int d_1beb68;                    // 0x1BEB68
extern int d_1beb6c;                    // 0x1BEB6C
extern int d_1beb70;                    // 0x1BEB70
extern int d_1beb74;                    // 0x1BEB74
extern int d_1beb78;                    // 0x1BEB78
extern int d_1beb7c;                    // 0x1BEB7C
extern int d_1beb80;                    // 0x1BEB80
extern int d_1beb84;                    // 0x1BEB84
/* KRUECKE: Feldsicht entfernt einen Nulleintrag fuer die Registersortierung. */
struct Cell900_d_1beb88 { int value; };
extern Cell900_d_1beb88 d_1beb88;
#define d_1beb88 d_1beb88.value
                    // 0x1BEB88
extern int d_1beb8c;                    // 0x1BEB8C
extern int d_1beb90;                    // 0x1BEB90
extern int d_1beb94;                    // 0x1BEB94
extern int d_1beb98;                    // 0x1BEB98
extern int d_1beb9c;                    // 0x1BEB9C
extern int d_1beba0;                    // 0x1BEBA0
extern int d_1beba4;                    // 0x1BEBA4
extern int d_1beba8;                    // 0x1BEBA8
extern int d_1bebac;                    // 0x1BEBAC
extern int d_1bebb0;                    // 0x1BEBB0
extern int d_1bebb4;                    // 0x1BEBB4
extern int d_1bebb8;                    // 0x1BEBB8
extern int d_1bebbc;                    // 0x1BEBBC
extern int d_1bebc0;                    // 0x1BEBC0
extern int d_1bebc4;                    // 0x1BEBC4
extern int d_1bebc8;                    // 0x1BEBC8
extern int d_1bebcc;                    // 0x1BEBCC
extern int d_1bebd0;                    // 0x1BEBD0
extern int d_1bebd4;                    // 0x1BEBD4
extern int d_1bebd8;                    // 0x1BEBD8
extern int d_1bebdc;                    // 0x1BEBDC
extern int d_1bebe0;                    // 0x1BEBE0
extern int d_1bebe4;                    // 0x1BEBE4
extern int d_1bebe8;                    // 0x1BEBE8
extern int d_1bebec;                    // 0x1BEBEC
extern int d_1bebf0;                    // 0x1BEBF0
extern int d_1bebf4;                    // 0x1BEBF4
extern int d_1bebf8;                    // 0x1BEBF8
extern int d_1bebfc;                    // 0x1BEBFC
extern int d_1bec00;                    // 0x1BEC00
extern int d_1bec04;                    // 0x1BEC04
extern int d_1bec08;                    // 0x1BEC08
extern int d_1bec0c;                    // 0x1BEC0C
extern int d_1bec10;                    // 0x1BEC10
extern int d_1bec14;                    // 0x1BEC14
extern int d_1bec18;                    // 0x1BEC18
/* KRUECKE: Feldsicht entfernt einen Nulleintrag fuer die Registersortierung. */
struct Cell900_d_1bec1c { int value; };
extern Cell900_d_1bec1c d_1bec1c;
#define d_1bec1c d_1bec1c.value
                    // 0x1BEC1C
extern int d_1bec20;                    // 0x1BEC20
extern int d_1bec24;                    // 0x1BEC24
extern int d_1bec28;                    // 0x1BEC28
extern int d_1bec2c;                    // 0x1BEC2C
extern int d_1bec30;                    // 0x1BEC30
extern int d_1bec34;                    // 0x1BEC34
extern int d_1bec38;                    // 0x1BEC38
extern int d_1bec3c;                    // 0x1BEC3C
extern int d_1bec40;                    // 0x1BEC40
extern int d_1bec44;                    // 0x1BEC44
extern int d_1bec48;                    // 0x1BEC48
extern int d_1bec4c;                    // 0x1BEC4C
extern int d_1bec50;                    // 0x1BEC50
extern int d_1bec54;                    // 0x1BEC54
extern int d_1bec58;                    // 0x1BEC58
extern int d_1bec5c;                    // 0x1BEC5C
extern int d_1bec60;                    // 0x1BEC60
extern int d_1bec64;                    // 0x1BEC64
extern int d_1bec68;                    // 0x1BEC68
extern int d_1bec6c;                    // 0x1BEC6C
extern int d_1bec70;                    // 0x1BEC70
extern int d_1bec74;                    // 0x1BEC74
extern int d_1bec78;                    // 0x1BEC78
/* KRUECKE: Feldsicht entfernt einen Nulleintrag fuer die Registersortierung. */
struct Cell900_d_1bec7c { int value; };
extern Cell900_d_1bec7c d_1bec7c;
#define d_1bec7c d_1bec7c.value
                    // 0x1BEC7C
extern int d_1bec80;                    // 0x1BEC80
extern int d_1bec84;                    // 0x1BEC84
extern int d_1bec88;                    // 0x1BEC88
extern int d_1bec8c;                    // 0x1BEC8C
extern int d_1bec90;                    // 0x1BEC90
extern int d_1bec94;                    // 0x1BEC94
extern int d_1bec98;                    // 0x1BEC98
extern int d_1bec9c;                    // 0x1BEC9C
extern int d_1beca0;                    // 0x1BECA0
extern int d_1beca4;                    // 0x1BECA4
extern int d_1beca8;                    // 0x1BECA8
extern int d_1becac;                    // 0x1BECAC
extern int d_1becb0;                    // 0x1BECB0
extern int d_1becb4;                    // 0x1BECB4
extern int d_1becb8;                    // 0x1BECB8
extern int d_1becbc;                    // 0x1BECBC
extern int d_1becc0;                    // 0x1BECC0
extern int d_1becc4;                    // 0x1BECC4
extern int d_1becc8;                    // 0x1BECC8
extern int d_1beccc;                    // 0x1BECCC
extern int d_1becd0;                    // 0x1BECD0
extern int d_1becd4;                    // 0x1BECD4
extern int d_1becd8;                    // 0x1BECD8
extern int d_1becdc;                    // 0x1BECDC
extern int d_1bece0;                    // 0x1BECE0
extern int d_1bece4;                    // 0x1BECE4
extern int d_1bece8;                    // 0x1BECE8
extern int d_1becec;                    // 0x1BECEC
extern int d_1becf0;                    // 0x1BECF0
extern int d_1becf4;                    // 0x1BECF4
extern int d_1becf8;                    // 0x1BECF8
extern int d_1becfc;                    // 0x1BECFC
extern int d_1bed00;                    // 0x1BED00
extern int d_1bed04;                    // 0x1BED04
extern int d_1bed08;                    // 0x1BED08
extern int d_1bed0c;                    // 0x1BED0C
extern int d_1bed10;                    // 0x1BED10
extern int d_1bed14;                    // 0x1BED14
extern int d_1bed18;                    // 0x1BED18
extern int d_1bed1c;                    // 0x1BED1C
extern int d_1bed20;                    // 0x1BED20
extern int d_1bed24;                    // 0x1BED24
extern int d_1bed28;                    // 0x1BED28
extern int d_1bed2c;                    // 0x1BED2C
extern int d_1bed30;                    // 0x1BED30
extern int d_1bed34;                    // 0x1BED34
extern const char d_1a50d0[];           // Text 0x1A50D0
extern const char d_1a512c[];           // Text 0x1A512C
extern const char d_1b8152[];           // Text 0x1B8152
extern int d_1a5108;
extern int d_1a510c;
extern int d_1a5120;
extern int d_1a5124;
extern int d_1a5178;
extern int d_1a5190;
extern const char d_1b8120[];
extern const char d_1b8122[];
extern const char d_1b8125[];
extern const char d_1b8127[];
extern const char d_1b812a[];
extern const char d_1b812c[];
extern const char d_1b8132[];
extern const char d_1b8137[];
extern const char d_1b813b[];
extern const char d_1b813e[];
extern const char d_1b8142[];
extern const char d_1b8147[];
extern const char d_1b8149[];
extern const char d_1b814b[];
extern const char d_1b814e[];
extern const char d_1b8198[];
extern const char d_1b819a[];
extern const char d_1b819c[];
extern const char d_1b819e[];
extern const char d_1b81a0[];
extern const char d_1b81a2[];
extern unsigned char d_1bbfdc[];
#include <ctype.h>
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
#define CB01(c) (((struct BF4 *)&(c))->b01)
#define CB23(c) (((struct BF4 *)&(c))->b23)
#define CP34(c) (((struct BF3 *)&(c))->f3)
#define ISV(c) ((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u'||(c)=='A'||(c)=='E'||(c)=='I'||(c)=='O'||(c)=='U')
struct OBJ { char c; char *vt; };
typedef void (*FS)(struct OBJ *, char *, T3W, T4);
typedef void (*FT)(struct OBJ *, char *, char *, unsigned char, T4, int);
//@ f_0af220
/* === Beschreibung (Katalog) ===
 * - f_0af220: Diese Funktion initialisiert die globalen schwedischen Artikel- und Pronomentabellen
 *   (lang_swe.cpp).
 * - f_0af390: Diese Funktion bildet eine schwedische Nominalphrase mit angehängtem oder vorangestelltem Artikel.
 * - f_0af8b0: Diese Funktion dient als Platzhalter für den bestimmten Artikel im schwedischen Modul und ruft
 *   strcat mit einem Nullzeiger auf.
 * - f_0af8e0: Diese Funktion dient als Platzhalter für den unbestimmten Artikel im schwedischen Modul und ruft
 *   strcat mit einem Nullzeiger auf.
 * - f_0af910: Diese Funktion ist eine leere Platzhaltermethode für die schwedische Substantivbeugung.
 * - f_0af920: Diese Funktion erzeugt einen String mit dem passenden schwedischen Possessivpronomen.
 * - f_0af9d0: Diese Funktion erzeugt einen String mit dem passenden schwedischen Personalpronomen.
 * - f_0afa70: Diese Funktion löst Punkt-Vorlagenstrings im schwedischen Sprachmodul über f_0b0460 auf.
 * - f_0afaa0: Diese Funktion gibt den Sprachnamen "Schwedisch" zurück.
 === Ende Beschreibung === */
void f_0af220(void)
;
//@ f_0af390
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt für ein schwedisches Substantiv (p2) einen neu allokierten Ausgabepuffer und bildet
 *   je nach Artikelmodus (p3), Numerus und Genus (p4) die Form mit angehängtem bestimmten Artikel ("-en", "-et",
 *   "-arna", "-arnas", "-ens"), vorangestelltem unbestimmten Artikel ("en ", "ett ") sowie Genitiv-s. Im
 *   artikellosen Modus (case 0) wurde jedoch vergessen, das Substantiv p2 selbst in den Puffer zu kopieren, und
 *   der abschließende toupper-Aufruf (f_15ea62) verwirft seinen Rückgabewert (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das schwedische Sprachmodul (p1), das Substantiv (p2), das Modus-
 *   und Kasus-Bitfeld (p3), das Numerus- und Genus-Bitfeld (p4) sowie ein ungenutzter Parameter (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der gebildeten
 *   Wortform zurück.
 === Ende Beschreibung === */
char *f_0af390(int p1, char *p2, T3W p3, T4 p4, int p5)
;
//@ f_0af8b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sollte einen bestimmten Artikel an den Zielpuffer (p2) anfügen, ruft im schwedischen Modul
 *   jedoch fehlerhaft strcat(p2, (char *)0) mit einem Nullzeiger auf (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (p1), der Zielpuffer (p2) sowie zwei
 *   Grammatikparameter (p3, p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0af8b0(int p1, char *p2, int p3, int p4)
;
//@ f_0af8e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sollte einen unbestimmten Artikel an den Zielpuffer (p2) anfügen, ruft im schwedischen Modul
 *   jedoch ebenfalls fehlerhaft strcat(p2, (char *)0) mit einem Nullzeiger auf (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (p1), der Zielpuffer (p2) sowie zwei
 *   Grammatikparameter (p3, p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0af8e0(int p1, char *p2, int p3, int p4)
;
//@ f_0af910
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als leere Platzhaltermethode des schwedischen Sprachmoduls für die separate
 *   Substantivbeugung.
 * - Eingaben: Übergeben werden sechs ungenutzte Parameter der virtuellen Methodensignatur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0af910(int a, int b, int c, int d, int e, int f)
;
//@ f_0af920
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende schwedische
 *   Possessivpronomen ("hans", "hennes" oder "deras") anhand von Artikelmodus (p2), Bezugswort-Genus (p3) und
 *   Besitzer-Numerus/Genus (p5) aus den Tabellen d_1bead4 bis d_1beb04 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das schwedische Sprachmodul (p1), der Artikelmodus (p2), das
 *   Bezugswort-Genus (p3), ein ungenutztes Kasus-Byte (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem schwedischen
 *   Possessivpronomen zurück.
 === Ende Beschreibung === */
char *f_0af920(int p1, short p2, short p3, unsigned char p4, unsigned char p5)
;
//@ f_0af9d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und kopiert das passende schwedische
 *   Personalpronomen ("han", "hon", "honom", "henne", "de", "dem") anhand von Kasus (p2), Numerus und Genus (p3)
 *   aus der Tabelle d_1beb10 hinein.
 * - Eingaben: Übergeben werden ein Zeiger auf das schwedische Sprachmodul (p1), das Kasus-Bitfeld (p2) und das
 *   Numerus- und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem schwedischen
 *   Personalpronomen zurück.
 === Ende Beschreibung === */
char *f_0af9d0(int p1, T3W p2, T4 p3)
;
//@ f_0afa70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wendet im schwedischen Sprachmodul die Platzhalter-Ersetzungsfunktion (f_0b0460) auf den
 *   ersten Textpuffer (p2, Modus 1) und - sofern vorhanden - auf den zweiten Textpuffer (p3, Modus 2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das schwedische Sprachmodul (p1), zwei Textpuffer-Zeiger (p2, p3),
 *   der Vorlagenstring (p4) sowie drei ungenutzte Parameter (p5-p7).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0afa70(int p1, int p2, int p3, int p4, int p5, int p6, int p7)
;
//@ f_0afaa0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den deutschen Namen der Sprache des schwedischen Sprachmoduls ("Schwedisch" bei
 *   d_1b8152, in dieser Teileinheit vorwärtsdeklariert und in lang_swe_rand910a definiert) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf die konstante Zeichenkette "Schwedisch" (char *) zurück.
 * - Wichtige Variablen: d_1b8152 ("Schwedisch").
 === Ende Beschreibung === */
char *f_0afaa0(void)
;
//@ f_0afab0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1beb88 bis d_1bed34) für die englischen
 *   Possessivpronomen ("his", "her", "its", "their"), bestimmten Artikel ("the"), unbestimmten Artikel ("a" im
 *   Singular, Leerstring im Plural) und Personalpronomen ("he", "she", "it", "his", "her", "its", "him", "they",
 *   "their", "them").
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0afab0(void)
{
    d_1beb88 = d_1a5184;
    d_1beb90 = d_1a518c;
    d_1beb94 = d_1a5184;
    d_1beb9c = d_1a518c;
    d_1beba0 = d_1a5184;
    d_1beba8 = d_1a518c;
    d_1bebac = d_1a5184;
    d_1bebb4 = d_1a518c;
    d_1bebb8 = d_1a5184;
    d_1bebc0 = d_1a518c;
    d_1bebc4 = d_1a5184;
    d_1bebcc = d_1a518c;
    d_1bebd0 = d_1a5184;
    d_1bebd8 = d_1a518c;
    d_1bebdc = d_1a5184;
    d_1bebe4 = d_1a518c;
    d_1bebe8 = d_1a5190;
    d_1bebec = d_1a5190;
    d_1bebf0 = d_1a5190;
    d_1bebf4 = d_1a5190;
    d_1bebf8 = d_1a5190;
    d_1bebfc = d_1a5190;
    d_1bec00 = d_1a5190;
    d_1bec04 = d_1a5190;
    d_1bec08 = d_1a5190;
    d_1bec0c = d_1a5190;
    d_1bec10 = d_1a5190;
    d_1bec14 = d_1a5190;
    d_1bec18 = d_1a514c;
    d_1bec1c = d_1a514c;
    d_1bec20 = d_1a514c;
    d_1bec24 = d_1a514c;
    d_1bec28 = d_1a514c;
    d_1bec2c = d_1a514c;
    d_1bec30 = d_1a514c;
    d_1bec34 = d_1a514c;
    d_1bec38 = d_1a514c;
    d_1bec3c = d_1a514c;
    d_1bec40 = d_1a514c;
    d_1bec44 = d_1a514c;
    d_1bec48 = d_1a514c;
    d_1bec4c = d_1a514c;
    d_1bec50 = d_1a514c;
    d_1bec54 = d_1a514c;
    d_1bec58 = d_1a514c;
    d_1bec5c = d_1a514c;
    d_1bec60 = d_1a514c;
    d_1bec64 = d_1a514c;
    d_1bec68 = d_1a514c;
    d_1bec6c = d_1a514c;
    d_1bec70 = d_1a514c;
    d_1beb8c = d_1a5188;
    d_1beb98 = d_1a5188;
    d_1beba4 = d_1a5188;
    d_1bebb0 = d_1a5188;
    d_1bebbc = d_1a5188;
    d_1bebc8 = d_1a5188;
    d_1bebd4 = d_1a5188;
    d_1bebe0 = d_1a5188;
    d_1bec74 = d_1a514c;
    d_1bec78 = d_1a5150;
    d_1bec7c = d_1a5150;
    d_1bec80 = d_1a5150;
    d_1bec84 = d_1a5150;
    d_1bec88 = d_1a5150;
    d_1bec8c = d_1a5150;
    d_1bec90 = d_1a5150;
    d_1bec94 = d_1a5150;
    d_1bec98 = d_1a5150;
    d_1bec9c = d_1a5150;
    d_1beca0 = d_1a5150;
    d_1beca4 = d_1a5150;
    d_1beca8 = d_1a5154;
    d_1becac = d_1a5154;
    d_1becb0 = d_1a5154;
    d_1becb4 = d_1a5154;
    d_1becb8 = d_1a5154;
    d_1becbc = d_1a5154;
    d_1becc0 = d_1a5154;
    d_1becc4 = d_1a5154;
    d_1becc8 = d_1a5154;
    d_1beccc = d_1a5154;
    d_1becd0 = d_1a5154;
    d_1becd4 = d_1a5154;
    d_1becd8 = d_1a5158;
    d_1becdc = d_1a515c;
    d_1bece0 = d_1a5160;
    d_1bece4 = d_1a5164;
    d_1bece8 = d_1a5168;
    d_1becec = d_1a516c;
    d_1becf0 = d_1a5170;
    d_1becf4 = d_1a5168;
    d_1becf8 = d_1a5160;
    d_1becfc = d_1a5170;
    d_1bed00 = d_1a5168;
    d_1bed04 = d_1a5160;
    d_1bed08 = d_1a5174;
    d_1bed0c = d_1a5174;
    d_1bed10 = d_1a5174;
    d_1bed14 = d_1a5178;
    d_1bed18 = d_1a5178;
    d_1bed1c = d_1a5178;
    d_1bed20 = d_1a517c;
    d_1bed24 = d_1a517c;
    d_1bed28 = d_1a517c;
    d_1bed2c = d_1a517c;
    d_1bed30 = d_1a517c;
    d_1bed34 = d_1a517c;
}
//@ f_0afda0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den englischen bestimmten Artikel ("the") anhand von Kasus (p3), Numerus und Genus
 *   (p4) aus der Tabelle d_1bec18 an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), der Zielpuffer (p2), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0afda0(int p1, char *p2, T3W p3, T4 p4)
{
    strcat(p2, ((char *(*)[3])&d_1bec18)[P34(p3) + B23(p4) * 4][B01(p4)]);
}
//@ f_0afe10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den englischen unbestimmten Artikel ("a" im Singular bzw. Leerstring im Plural) anhand
 *   von Kasus (p3), Numerus und Genus (p4) aus der Tabelle d_1bec78 an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), der Zielpuffer (p2), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0afe10(int p1, char *p2, T3W p3, T4 p4)
{
    strcat(p2, ((char *(*)[3])&d_1bec78)[P34(p3) + B23(p4) * 4][B01(p4)]);
}
//@ f_0afe80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und kopiert das passende englische
 *   Personalpronomen ("he", "she", "it", "his", "her", "its", "him", "they", "their", "them") anhand von Kasus
 *   (p2), Numerus und Genus (p3) aus der Tabelle d_1becd8 hinein.
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), das Kasus-Bitfeld (p2) und das
 *   Numerus- und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem englischen
 *   Personalpronomen zurück.
 === Ende Beschreibung === */
char *f_0afe80(int p1, T3W p2, T4 p3)
{
    char *buf = new (mark(d_1a512c, 0x83)) char[10];
    memset(buf, 0, 10);
    strcat(buf, ((char *(*)[3])&d_1becd8)[B23(p3) * 4 + P34(p2)][B01(p3)]);
    return buf;
}
//@ f_0aff30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende englische
 *   Possessivpronomen ("his", "her", "its" oder "their") anhand von Artikelmodus (p2), Besitzer-Genus/Numerus
 *   (p3, p5) und Kasus (p4) aus den Tabellen d_1beb88 bis d_1bebe8 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), der Artikelmodus (p2), der
 *   Genus-Index (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem englischen
 *   Possessivpronomen zurück.
 === Ende Beschreibung === */
char *f_0aff30(int p1, short p2, short p3, unsigned char p4, unsigned char p5)
{
    int *base;
    unsigned char i3;
    char *buf = new (mark(d_1a512c, 0xa0)) char[10];
    memset(buf, 0, 10);
    if (p2 == 0) {
        if (CB23(p5) == 1) {
            base = &d_1bebb8;
        } else {
            base = &d_1beb88;
        }
    } else {
        base = &d_1bebe8;
    }
    i3 = p4; i3 <<= 3; i3 >>= 5;
    strcat(buf, ((char *(*)[3])base)[i3][p3]);
    return buf;
}
//@ f_0b0000
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bildet für ein englisches Substantiv (p2) in einem neu allokierten Puffer die vollständige
 *   Nominalphrase je nach Modus (p3 oberes Byte): bestimmter Artikel "the " + Substantiv (case 2), unbestimmter
 *   Artikel "a " bzw. vor Vokalen (A, E, I, O, U) automatisch "an " + Substantiv (case 1), nur Substantiv (case
 *   0), nur bestimmter Artikel (case 3) oder nur unbestimmter Artikel (case 4).
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), das Substantiv (p2), das Modus-
 *   und Kasus-Bitfeld (p3), das Numerus- und Genus-Bitfeld (p4) sowie ein Zusatzparameter (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der englischen
 *   Nominalphrase zurück.
 === Ende Beschreibung === */
char *f_0b0000(struct OBJ *p1, signed char *p2, T3W p3, T4 p4, int p5)
{
    short n = strlen((char *)p2) + 10;
    char *buf = new (mark(d_1a512c, 0xcc)) char[n];
    memset(buf, 0, n);
    switch (P3H(p3)) {
    case 2:
        (*(FS *)(p1->vt + 4))(p1, buf, p3, p4);
        if (*buf) strcat(buf, d_1b8198);
        (*(FT *)(p1->vt + 0xc))(p1, buf, (char *)p2, P34(p3), p4, p5);
        break;
    case 1:
        (*(FS *)(p1->vt + 8))(p1, buf, p3, p4);
        if (*buf) {
            char t = f_15ea62(*p2);
            if (t == 'A' || t == 'E' || t == 'I' || t == 'O' || t == 'U') strcat(buf, d_1b819a);
            strcat(buf, d_1b819c);
        }
        (*(FT *)(p1->vt + 0xc))(p1, buf, (char *)p2, P34(p3), p4, p5);
        break;
    case 0:
        (*(FT *)(p1->vt + 0xc))(p1, buf, (char *)p2, P34(p3), p4, p5);
        break;
    case 3:
        (*(FS *)(p1->vt + 4))(p1, buf, p3, p4);
        break;
    case 4:
        (*(FS *)(p1->vt + 8))(p1, buf, p3, p4);
        break;
    }
    return buf;
}
//@ f_0b0210
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Beugt ein englisches Substantiv (p3) nach Kasus (p4): Sie trennt zunächst einen etwaigen
 *   Klammerzusatz am Wortende (z. B. "(2H)") ab, hängt im Genitiv (p4 == 1) ein Apostroph '\'' (d_1b819e) sowie
 *   - falls das Wort nicht bereits auf 's' oder 'S' endet - ein 's' bzw. 'S' an und setzt Wortstamm und
 *   Klammerzusatz im Ausgabepuffer (p2) wieder zusammen.
 * - Eingaben: Übergeben werden ein Zeiger auf das englische Sprachmodul (p1), der Ausgabepuffer (p2), das
 *   Substantiv (p3), der Kasus (p4) sowie zwei ungenutzte Parameter (p5, p6).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0210(int p1, char *p2, char *p3, unsigned short p4, int p5, int p6)
{
    char *buf = new (mark(d_1a512c, 0x118)) char[0x64];
    char *buf2 = new (mark(d_1a512c, 0x119)) char[0x32];
    *buf = 0;
    *buf2 = *buf;
    strcpy(buf, p3);
    if (buf[strlen(buf) - 1] == ')') {
        char *q = buf + strlen(buf);
        while (*q != '(' && q >= buf) q--;
        if (*q == '(') strcpy(buf2, q - 1);
        do {
            q--;
        } while (*q == ' ');
        q[1] = 0;
    }
    char last = buf[strlen(buf) - 1];
    switch (p4) {
    case 1:
        strcat(buf, d_1b819e);
        if (d_1bbfdc[(unsigned char)(last + 1)] & 0x40) {
            if (last != 'S') strcat(buf, d_1b81a0);
        } else {
            if (last != 's') strcat(buf, d_1b81a2);
        }
        break;
    case 2:
        break;
    }
    strcat(p2, buf);
    strcat(p2, buf2);
    delete buf;
    delete buf2;
}
