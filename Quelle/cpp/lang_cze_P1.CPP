/* === Beschreibung (Katalog) ===
 * Einheit lang_cze (0x0AB910 - 0x0ABF10)
 *
 * Diese Einheit implementiert das Sprachmodul für Tschechisch (p:\riva\source\cpp\lang_cze.cpp) mit
 * Deklinations-, Artikel- und Pronomentabellen zur automatischen Textgrammatik-Ersetzung (Rest- bzw.
 * Platzhaltermodul der mehrsprachigen Text-Engine).
 === Ende Beschreibung === */
// P3 6/7 gleich (suche.py 23.10.2026, Basis lang_cze_P1.CPP)
// lang_cze.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AB910-0x0ABF10
#include <string.h>
#include "RIVAMEM.H"
#include "R_FIX.H"



extern const char d_1a4d88[];
extern char *d_1a4da8;
extern char *d_1a4db0;
extern char *d_1a4db4;
extern char *d_1a4dbc;
extern char *d_1a4dc0;
extern char *d_1a4dc8;
extern char *d_1a4dcc;
extern char *d_1a4dd0;
extern char *d_1a4dd4;
extern char *d_1a4de0;
extern char *d_1a4de4;
extern char *d_1a4dec;
extern char *d_1a4df4;
extern char *d_1a4df8;
extern char *d_1a4e00;
extern char *d_1a4e04;
extern char *d_1a4e08;
extern char *d_1a4e0c;
extern char *d_1be284;
extern char *d_1be288;
extern char *d_1be28c;
extern char *d_1be290;
extern char *d_1be294;
extern char *d_1be298;
extern char *d_1be29c;
extern char *d_1be2a0;
extern char *d_1be2a4;
extern char *d_1be2a8;
extern char *d_1be2ac;
extern char *d_1be2b0;
extern char *d_1be2b4;
extern char *d_1be2b8;
extern char *d_1be2bc;
extern char *d_1be2c0;
extern char *d_1be2c4;
extern char *d_1be2c8;
extern char *d_1be2cc;
extern char *d_1be2d0;
extern char *d_1be2d4;
extern char *d_1be2d8;
extern char *d_1be2dc;
extern char *d_1be2e0;
extern char *d_1be2e4;
extern char *d_1be2e8;
extern char *d_1be2ec;
extern char *d_1be2f0;
extern char *d_1be2f4;
extern char *d_1be2f8;
extern char *d_1be2fc;
extern char *d_1be300;
extern char *d_1be304;
extern char *d_1be308;
extern char *d_1be30c;
extern char *d_1be310;
extern char *d_1be314;
extern char *d_1be318;
extern char *d_1be31c;
extern char *d_1be320;
extern char *d_1be324;
extern char *d_1be328;
extern char *d_1be32c;
extern char *d_1be330;
extern char *d_1be334;
extern char *d_1be338;
extern char *d_1be33c;
extern char *d_1be340;
extern char *d_1be344;
extern char *d_1be348;
extern char *d_1be34c;
extern char *d_1be350;
extern char *d_1be354;
extern char *d_1be358;
extern char *d_1be35c;
extern char *d_1be360;
extern char *d_1be364;
extern char *d_1be368;
extern char *d_1be36c;
extern char *d_1be370;
extern char *d_1be374;
extern char *d_1be378;
extern char *d_1be37c;
extern char *d_1be380;
extern char *d_1be384;
extern char *d_1be388;
extern char *d_1be38c;
extern char *d_1be390;
extern char *d_1be394;
extern char *d_1be398;
extern char *d_1be39c;
extern char *d_1be3a0;
extern char *d_1be3a4;
extern char *d_1be3a8;
extern char *d_1be3ac;
extern char *d_1be3b0;
extern char *d_1be3b4;
extern char *d_1be3b8;
extern char *d_1be3bc;
extern char *d_1be3c0;
extern char *d_1be3c4;
extern char *d_1be3c8;
extern char *d_1be3cc;
extern char *d_1be3d0;
extern char *d_1be3d4;
extern char *d_1be3d8;
extern char *d_1be3dc;
extern char *d_1be3e0;
extern char *d_1be3e4;
extern char *d_1be3e8;
extern char *d_1be3ec;
extern char *d_1be3f0;
extern char *d_1be3f4;
extern char *d_1be3f8;
extern char *d_1be3fc;
extern char *d_1be400;
extern char *d_1be404;
extern char *d_1be408;
extern char *d_1be40c;
extern char *d_1be3e0;
#define BF(t,x,a,b) unsigned char t = (x); t <<= a; t >>= b;
#define TT (char *(*)[3])
//@ f_0ab910
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1be284 bis d_1be40c) für die tschechischen
 *   Personal- und Possessivpronomen (wie "on", "ona", "oni", "jeho", "jeji", "jejich", "jich", "jim", "nich",
 *   "jimi") nach Kasus, Numerus und Genus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ab910(void)
{
  d_1be294 = d_1a4dc8;
  d_1be2a0 = d_1a4dc8;
  d_1be2ac = d_1a4dc8;
  d_1be2c0 = d_1a4de4;
  d_1be2c4 = d_1a4dc8;
  d_1be2c8 = d_1a4de4;
  d_1be2e4 = d_1a4de4;
  d_1be2e8 = d_1a4de4;
  d_1be2ec = d_1a4de4;
  d_1be314 = d_1a4e00;
  d_1be31c = d_1a4e00;
  d_1be320 = d_1a4e0c;
  d_1be324 = d_1a4e0c;
  d_1be328 = d_1a4e0c;
  d_1be32c = d_1a4e0c;
  d_1be330 = d_1a4e0c;
  d_1be334 = d_1a4e0c;
  d_1be338 = d_1a4e0c;
  d_1be33c = d_1a4e0c;
  d_1be340 = d_1a4e0c;
  d_1be344 = d_1a4e00;
  d_1be34c = d_1a4e00;
  d_1be350 = d_1a4e0c;
  d_1be354 = d_1a4e0c;
  d_1be358 = d_1a4e0c;
  d_1be35c = d_1a4e0c;
  d_1be360 = d_1a4e0c;
  d_1be364 = d_1a4e0c;
  d_1be368 = d_1a4e0c;
  d_1be36c = d_1a4e0c;
  d_1be370 = d_1a4e0c;
  d_1be374 = d_1a4e00;
  d_1be284 = d_1a4da8;
  d_1be37c = d_1a4e00;
  d_1be288 = d_1a4db0;
  d_1be380 = d_1a4e0c;
  d_1be28c = d_1a4da8;
  d_1be384 = d_1a4e0c;
  d_1be290 = d_1a4dbc;
  d_1be298 = d_1a4dbc;
  d_1be388 = d_1a4e0c;
  d_1be29c = d_1a4dd4;
  d_1be2a4 = d_1a4dd4;
  d_1be38c = d_1a4e0c;
  d_1be2a8 = d_1a4dc0;
  d_1be2b0 = d_1a4dc0;
  d_1be390 = d_1a4e0c;
  d_1be2b4 = d_1a4de0;
  d_1be394 = d_1a4e0c;
  d_1be2b8 = d_1a4dcc;
  d_1be398 = d_1a4e0c;
  d_1be2bc = d_1a4de0;
  d_1be39c = d_1a4e0c;
  d_1be2cc = d_1a4db4;
  d_1be2d0 = d_1a4db4;
  d_1be2d4 = d_1a4db4;
  d_1be3a0 = d_1a4e0c;
  d_1be2d8 = d_1a4dd0;
  d_1be2dc = d_1a4dd0;
  d_1be2e0 = d_1a4dd0;
  d_1be2f0 = d_1a4dec;
  d_1be3a4 = d_1a4e08;
  d_1be2f4 = d_1a4dec;
  d_1be2f8 = d_1a4dec;
  d_1be3a8 = d_1a4e08;
  d_1be2fc = d_1a4df4;
  d_1be300 = d_1a4df4;
  d_1be304 = d_1a4df4;
  d_1be3ac = d_1a4e08;
  d_1be308 = d_1a4df8;
  d_1be30c = d_1a4df8;
  d_1be310 = d_1a4df8;
  d_1be3b0 = d_1a4e0c;
  d_1be318 = d_1a4e04;
  d_1be348 = d_1a4e04;
  d_1be378 = d_1a4e04;
  d_1be3b4 = d_1a4e0c;
  d_1be3b8 = d_1a4e0c;
  d_1be3bc = d_1a4e0c;
  d_1be3c0 = d_1a4e0c;
  d_1be3c4 = d_1a4e0c;
  d_1be3c8 = d_1a4e0c;
  d_1be3cc = d_1a4e0c;
  d_1be3d0 = d_1a4e0c;
  d_1be3d4 = d_1a4e0c;
  d_1be3d8 = d_1a4e0c;
  d_1be3dc = d_1a4e0c;
  d_1be3e0 = d_1a4e08;
  d_1be3e4 = d_1a4e08;
  d_1be3e8 = d_1a4e08;
  d_1be3ec = d_1a4e0c;
  d_1be3f0 = d_1a4e0c;
  d_1be3f4 = d_1a4e0c;
  d_1be3f8 = d_1a4e0c;
  d_1be3fc = d_1a4e0c;
  d_1be400 = d_1a4e0c;
  d_1be404 = d_1a4e0c;
  d_1be408 = d_1a4e0c;
  d_1be40c = d_1a4e0c;
}
//@ f_0abbc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Reserviert für eine zu deklinierende Zeichenkette (p2) einen um 10 Byte vergrößerten, mit
 *   Nullbytes initialisierten Ausgabepuffer auf dem Heap; im tschechischen Modul erfolgt über die Reservierung
 *   hinaus noch keine Befüllung durch diese Funktion.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), die Ausgangszeichenkette (p2) sowie drei
 *   Grammatikparameter (Kasus, Numerus/Artikelmodus, Flags).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den neu reservierten, leeren Zeichenpuffer zurück.
 === Ende Beschreibung === */
char *f_0abbc0(int p1, const char *p2, int p3, int p4, int p5)
{
  short n = strlen(p2) + 10;
  char *p = new (mark(d_1a4d88, 0xe8)) char[n];
  memset(p, 0, n);
  return p;
}
//@ f_0abc00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sollte einen bestimmten Artikel vor oder an den Zielpuffer (p2) anfügen, ruft im
 *   tschechischen Modul jedoch fehlerhaft strcat(p2, (char *)0) mit einem Nullzeiger auf (siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Ziel-Zeichenpuffer (p2) sowie zwei
 *   Grammatikparameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0abc00(int p1, char *p2, int p3, int p4)
{
#if FIX_R092   /* R092: Nullzeiger-Uebergabe an strcat im tschechischen Sprachmodul vermeiden */
  (void)p1; (void)p2; (void)p3; (void)p4;
#else
  strcat(p2, (char *)0);
#endif
}
//@ f_0abc30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sollte einen unbestimmten Artikel bzw. ein Zahlwort an den Zielpuffer (p2) anfügen, ruft im
 *   tschechischen Modul jedoch ebenfalls fehlerhaft strcat(p2, (char *)0) mit einem Nullzeiger auf (siehe
 *   Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Ziel-Zeichenpuffer (p2) sowie zwei
 *   Grammatikparameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0abc30(int p1, char *p2, int p3, int p4)
{
#if FIX_R092   /* R092: Nullzeiger-Uebergabe an strcat im tschechischen Sprachmodul vermeiden */
  (void)p1; (void)p2; (void)p3; (void)p4;
#else
  strcat(p2, (char *)0);
#endif
}
//@ f_0abc60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Trennt bei einem Substantiv oder Namen (p3) einen eventuell in Klammern am Ende stehenden
 *   Zusatz (z. B. "(2R)") temporär ab, führt im tschechischen Rumpfmodul keine Endungsbeugung durch und fügt
 *   Wortstamm sowie Klammerzusatz wieder an den Ausgabepuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Ausgabepuffer (p2), die
 *   Eingabezeichenkette (p3) sowie drei Grammatikparameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0abc60(int p1, char *p2, char *p3, int p4, int p5, int p6)
{
  char *b1 = new (mark(d_1a4d88, 0x139)) char[100];
  char *b2 = new (mark(d_1a4d88, 0x13a)) char[50];
  char *q;
  *b1 = 0;
  *b2 = *b1;
  strcpy(b1, p3);
  if (b1[strlen(b1) - 1] == ')') {
    q = b1 + strlen(b1);
    while (*q != '(' && q >= b1) q--;
    if (*q == '(') strcpy(b2, q - 1);
    do { q--; } while (*q == ' ');
    q[1] = 0;
  }
  strcat(p2, b1);
  strcat(p2, b2);
  delete b1;
  delete b2;
}
//@ f_0abda0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende tschechische
 *   Possessivpronomen (z. B. "jeho", "jeji", "jejich") anhand von Besitzer-Numerus/Genus (p5), Objekt-Genus
 *   (p4), Kasus (p3) und Artikelmodus (p2) aus den Tabellen d_1be314 bis d_1be3e0 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Modusflag (p2), der Kasus (p3), die
 *   Wort-Flags des Bezugsworts (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den neu allokierten String mit dem Possessivpronomen zurück.
 === Ende Beschreibung === */
char *f_0abda0(int p1, short p2, short p3, int p4, unsigned char p5)
{
  char *p = new (mark(d_1a4d88, 0x183)) char[10];
  char *(*t)[3];
  *p = 0;
  if (p2 == 0) {
    BF(a, p5, 4, 6)
    if (a == 1) t = TT &d_1be3a4;
    else switch ((unsigned char)(p5 & 3)) {
      case 0: t = TT &d_1be314; break;
      case 1: t = TT &d_1be344; break;
      case 2: t = TT &d_1be374; break;
    }
  } else t = TT &d_1be3e0;
  BF(u, p4, 3, 5)
  strcat(p, t[u][p3]);
  return p;
}
//@ f_0abe70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende tschechische
 *   Personalpronomen (z. B. "on", "ona", "oni", "ho", "ji", "mu", "jim") anhand von Kasus, Numerus und Genus
 *   (p2, p3) aus der Tabelle d_1be284 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), die Wort- und Genus-Flags (p2) sowie die
 *   Kasus- und Numerus-Flags (p3).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den neu allokierten String mit dem Personalpronomen zurück.
 === Ende Beschreibung === */
char *f_0abe70(int p1, int p2, short p3)
{
  char *p = new (mark(d_1a4d88, 0x1c0)) char[10];
  *p = 0;
  BF(a, p3, 4, 6)
  unsigned i = a * 6;
  BF(b, p2, 3, 5)
  strcat(p, ((char *(*)[3])&d_1be284)[b + i][(unsigned char)p3 & 3]);
  return p;
}
