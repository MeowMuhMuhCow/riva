/* === Beschreibung (Katalog) ===
 * Einheit lang_nor (0x0ADDE0 - 0x0AE730)
 *
 * Diese Einheit implementiert das Sprachmodul für Norwegisch (p:\riva\source\cpp\lang_nor.cpp) mit
 * Deklinations-, Artikel- und Pronomenlogik der mehrsprachigen Text-Engine.
 === Ende Beschreibung === */
// P3 3/8 gleich (suche.py 24.10.2026, Basis lang_nor_P1.CPP)
// lang_nor.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ADDE0-0x0AE730
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4f94;                    // 0x1A4F94
extern int d_1a4f98;                    // 0x1A4F98
extern int d_1a4f9c;                    // 0x1A4F9C
extern int d_1a4fa0;                    // 0x1A4FA0
extern int d_1a4fa4;                    // 0x1A4FA4
extern int d_1a4fa8;                    // 0x1A4FA8
extern int d_1a4fb0;                    // 0x1A4FB0
extern int d_1a4fb4;                    // 0x1A4FB4
extern int d_1a4fb8;                    // 0x1A4FB8
extern int d_1a4fc0;                    // 0x1A4FC0
extern int d_1a4fc8;                    // 0x1A4FC8
extern int d_1be7d4;                    // 0x1BE7D4
extern int d_1be7d8;                    // 0x1BE7D8
extern int d_1be7dc;                    // 0x1BE7DC
extern int d_1be7e0;                    // 0x1BE7E0
extern int d_1be7e4;                    // 0x1BE7E4
extern int d_1be7e8;                    // 0x1BE7E8
extern int d_1be7ec;                    // 0x1BE7EC
extern int d_1be7f0;                    // 0x1BE7F0
extern int d_1be7f4;                    // 0x1BE7F4
extern int d_1be7f8;                    // 0x1BE7F8
extern int d_1be7fc;                    // 0x1BE7FC
extern int d_1be800;                    // 0x1BE800
extern int d_1be804;                    // 0x1BE804
extern int d_1be808;                    // 0x1BE808
extern int d_1be80c;                    // 0x1BE80C
extern int d_1be810;                    // 0x1BE810
extern int d_1be814;                    // 0x1BE814
extern int d_1be818;                    // 0x1BE818
extern int d_1be81c;                    // 0x1BE81C
extern int d_1be820;                    // 0x1BE820
extern int d_1be824;                    // 0x1BE824
extern int d_1be828;                    // 0x1BE828
extern int d_1be82c;                    // 0x1BE82C
extern int d_1be830;                    // 0x1BE830
extern int d_1be834;                    // 0x1BE834
extern int d_1be838;                    // 0x1BE838
extern int d_1be83c;                    // 0x1BE83C
extern int d_1be840;                    // 0x1BE840
extern int d_1be844;                    // 0x1BE844
extern int d_1be848;                    // 0x1BE848
extern int d_1be84c;                    // 0x1BE84C
extern int d_1be850;                    // 0x1BE850
extern int d_1be854;                    // 0x1BE854
extern const char d_1a4f74[];           // Text 0x1A4F74
// --- eigene Funktionen (8), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1a4fac;
extern int d_1a4fc4;
extern int d_1a4fcc;
extern const char d_1b7f78[], d_1b7f7a[], d_1b7f7d[], d_1b7f7f[], d_1b7f82[], d_1b7f85[], d_1b7f89[], d_1b7f8c[];
extern const char d_1b7f90[], d_1b7f94[], d_1b7f98[], d_1b7f9a[], d_1b7f9d[], d_1b7f9f[], d_1b7fa2[];
extern unsigned char d_1bbfdc[];
void *f_145300(void *p, int c, unsigned n);              // memset
int f_15ea70(int c);
int f_15ea62(int c);
struct F4 { unsigned char g:2; unsigned char n:2; unsigned char r:4; };
struct F6 { unsigned char a:2; unsigned char k:3; unsigned char b:3; };
struct F3 { unsigned char lo; unsigned char c:3; unsigned char r:5; };
#define G4(v) (((struct F4 *)&(v))->g)
#define N4(v) (((struct F4 *)&(v))->n)
#define K6(v) (((struct F6 *)&(v))->k)
#define APP(s) strcat(buf, s)
#define EE (last == 'e' || last == 'E')
//@ f_0adde0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1be7d4 bis d_1be854) für die norwegischen
 *   Possessivpronomen ("hans", "hennes", "dets", "deres"), Personalpronomen ("han", "hun", "det", "ham",
 *   "henne", "de", "dem") und Artikel (d_1a4f94, d_1a4f98).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0adde0(void)
{
  d_1be7d4 = d_1a4fc0;
  d_1be7d8 = d_1a4fc4;
  d_1be7dc = d_1a4fc8;
  d_1be7e0 = d_1a4fc0;
  d_1be7e4 = d_1a4fc4;
  d_1be7e8 = d_1a4fc8;
  d_1be7ec = d_1a4fc0;
  d_1be7f0 = d_1a4fc4;
  d_1be7f4 = d_1a4fc8;
  d_1be810 = d_1a4f9c;
  d_1be814 = d_1a4fa0;
  d_1be818 = d_1a4fa4;
  d_1be81c = d_1a4fa8;
  d_1be7f8 = d_1a4fcc;
  d_1be820 = d_1a4fac;
  d_1be7fc = d_1a4fcc;
  d_1be824 = d_1a4fb0;
  d_1be800 = d_1a4fcc;
  d_1be828 = d_1a4fb4;
  d_1be82c = d_1a4fb4;
  d_1be830 = d_1a4fb4;
  d_1be804 = d_1a4fcc;
  d_1be834 = d_1a4fb8;
  d_1be838 = d_1a4fb8;
  d_1be83c = d_1a4fb8;
  d_1be808 = d_1a4fcc;
  d_1be840 = d_1a4f94;
  d_1be844 = d_1a4f94;
  d_1be848 = d_1a4f94;
  d_1be80c = d_1a4fcc;
  d_1be84c = d_1a4f98;
  d_1be850 = d_1a4f98;
  d_1be854 = d_1a4f98;
}
//@ f_0adf10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt für ein norwegisches Substantiv (p2) einen neu allokierten Ausgabepuffer und bildet
 *   je nach Artikelmodus (p3), Numerus und Genus (p4) die Form mit angehängtem bestimmten Artikel ("-en", "-et",
 *   "-ene", "-ne"), vorangestelltem unbestimmten Artikel ("en ", "et ") oder Pluralendung ("-er"). Wie im
 *   dänischen Modul fehlen jedoch das break nach case 2 sowie die Zuweisung des toupper-Rückgabewerts (f_15ea62,
 *   siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Substantiv (p2), das Modus- und
 *   Kasus-Wort (p3), das Numerus- und Genus-Byte (p4) sowie ein ungenutzter Parameter (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der gebildeten
 *   Wortform zurück.
 === Ende Beschreibung === */
char *f_0adf10(int p1, char *p2, unsigned short p3, unsigned char p4, int p5)
{
  char *buf;
  short n;
  char last;
  n = strlen(p2) + 10;
  buf = new (mark(d_1a4f74, 0x66)) char[n];
  f_145300(buf, 0, n);
  last = p2[strlen(p2) - 1];
  switch (((struct F3 *)&p3)->c) {
  case 2:
    if (N4(p4) == 0) {
      APP(p2);
      switch (G4(p4)) {
      case 0: case 1:
        if (EE) APP(d_1b7f78); else APP(d_1b7f7a);
        break;
      case 2:
        if (EE) APP(d_1b7f7d); else APP(d_1b7f7f);
        break;
      }
    }
    if (N4(p4) == 1) {
      APP(p2);
      switch (G4(p4)) {
      case 0: case 1:
        if (EE) APP(d_1b7f82); else APP(d_1b7f85);
        break;
      case 2:
        if (EE) APP(d_1b7f89); else APP(d_1b7f8c);
        break;
      }
    }
  case 1:
    if (N4(p4) == 0) {
      switch (G4(p4)) {
      case 0: case 1:
        APP(d_1b7f90);
        break;
      case 2:
        APP(d_1b7f94);
        break;
      }
      APP(p2);
    }
    if (N4(p4) == 1) {
      APP(p2);
      switch (G4(p4)) {
      case 0: case 1:
        if (EE) APP(d_1b7f98); else APP(d_1b7f9a);
        break;
      case 2:
        if (EE) APP(d_1b7f9d);
        break;
      }
    }
    break;
  case 0:
    APP(p2);
    break;
  case 4:
    if (G4(p4) == 0) APP(d_1b7f9f);
    if (G4(p4) == 2) APP(d_1b7fa2);
    break;
  }
  if (d_1bbfdc[(unsigned char)(last + 1)] & 0x40) {
    short j, i;
    j = strlen(buf);
    for (i = 0; i < 3; i++) f_15ea62((signed char)buf[j--]);
  }
  return buf;
}
//@ f_0ae440
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und kopiert das passende norwegische
 *   Personalpronomen ("han", "hun", "det", "ham", "henne", "de", "dem") anhand von Kasus (p2), Numerus und Genus
 *   (p3) aus der Tabelle d_1be810 hinein (wobei die Zeilenberechnung p3.b23 * 2 + p2.f3 bei höheren Kasuswerten
 *   über die 4-zeilige Tabelle hinausliest, siehe Fehlerliste).
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), das Kasus-Bitfeld (p2) und das Numerus-
 *   und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Personalpronomen zurück.
 === Ende Beschreibung === */
struct BF4Nor { unsigned char b01:2, b23:2, b47:4; };
struct BF3WNor { unsigned char a01:2, f3:3, d57:3; unsigned char e:3, g:5; };
char *f_0ae440(int p1, BF3WNor p2, BF4Nor p3)
{
    char *buf = new (mark(d_1a4f74, 0x109)) char[10];
    f_145300(buf, 0, 10);
    strcat(buf, ((char *(*)[3])&d_1be810)[p3.b23 * 2 + p2.f3][p3.b01]);
    return buf;
}
//@ f_0ae4f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden bestimmten Artikel aus der norwegischen Tabelle d_1be840 anhand von
 *   Kasus (p3), Numerus und Genus (p4) an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), das Kasus-Bitfeld
 *   (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ae4f0(int p1, char *p2, BF3WNor p3, BF4Nor p4)
{
    strcat(p2, ((char *(*)[3])&d_1be840)[p3.f3 + p4.b23 * 4][p4.b01]);
}
//@ f_0ae560
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden unbestimmten Artikel aus der norwegischen Tabelle d_1be84c anhand von
 *   Kasus (p3), Numerus und Genus (p4) an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Zielpuffer (p2), das Kasus-Bitfeld
 *   (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ae560(int p1, char *p2, BF3WNor p3, BF4Nor p4)
{
    strcat(p2, ((char *(*)[3])&d_1be84c)[p3.f3 + p4.b23 * 4][p4.b01]);
}
//@ f_0ae5d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob ein übergebenes Wort (p2) maskulin ist (p1.g == 0) und auf die Buchstabenfolge
 *   "-en" endet.
 * - Eingaben: Übergeben werden das Numerus- und Genus-Bitfeld (p1) und die zu prüfende Zeichenkette (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Wort maskulin ist und auf "en" endet, und sonst 0.
 === Ende Beschreibung === */
int f_0ae5d0(struct F4 p1, signed char *p2)
{
    int r = 0;
    if (p2 != 0 && *p2 != 0) {
        char c1 = f_15ea70(p2[strlen((char *)p2) - 1]);
        char c2 = f_15ea70(p2[strlen((char *)p2) - 2]);
        if (p1.g == 0 && c1 == 'n' && c2 == 'e') r = 1;
    }
    return r;
}
//@ f_0ae640
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als leere Platzhaltermethode der norwegischen Sprachklasse für die separate
 *   Substantivbeugung.
 * - Eingaben: Übergeben werden sechs ungenutzte Parameter der virtuellen Methodensignatur.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ae640(int p1, int p2, int p3, int p4, int p5, int p6)
{
}
//@ f_0ae650
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 10-Byte-Puffer auf dem Heap und trägt darin das passende norwegische
 *   Possessivpronomen ("hans", "hennes", "dets" oder "deres") anhand von Artikelmodus (p2), Bezugswort-Genus
 *   (p3), Kasus (p4) und Besitzer-Numerus/Genus (p5) aus den Tabellen d_1be7d4 bis d_1be804 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das Sprachmodul (this), der Artikelmodus (p2), das
 *   Bezugswort-Genus (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem Possessivpronomen
 *   zurück.
 === Ende Beschreibung === */
char *f_0ae650(int p1, short p2, short p3, int p4, unsigned char p5)
{
    char *buf = new (mark(d_1a4f74, 0x161)) char[10];
    char *(*t)[3];
    unsigned char g, i2, i3;
    f_145300(buf, 0, 10);
    if (p2 == 0) {
        i2 = p5; i2 <<= 4; i2 >>= 6;
        if (i2 == 1) {
            t = (char *(*)[3])&d_1be7f8;
        } else {
            g = p5;
            g &= 3;
            switch (g) {
            case 0: t = (char *(*)[3])&d_1be7d4; break;
            case 1: t = (char *(*)[3])&d_1be7e0; break;
            case 2: t = (char *(*)[3])&d_1be7ec; break;
            }
        }
    } else {
        t = (char *(*)[3])&d_1be804;
    }
    i3 = p4; i3 <<= 3; i3 >>= 5;
    strcat(buf, t[i3][p3]);
    return buf;
}
