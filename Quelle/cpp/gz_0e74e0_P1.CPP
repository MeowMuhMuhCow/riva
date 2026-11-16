/* === Beschreibung (Katalog) ===
 * Einheit gz_0e74e0
 *
 * Diese Einheit bildet den zweiten Teil von printer.cpp (0x0E74E0-0x0E8810) und stellt die Hilfsfunktionen für
 * den Charakterbogen-Ausdruck bereit: die zeilenweise Ausgabe in eine Datei oder auf den Drucker, das
 * Aufbereiten der Gegenstands- und Kampfwerte eines einzelnen Inventarplatzes, das paarweise Formatieren der
 * Inventarzeilen sowie den Ausdruck des zweiten Bogens mit allen Zaubersprüchen eines magiebegabten Helden.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 3/4 gleich (suche.py 26.10.2026, Basis gz_0e74e0_P1.CPP)
// gz_0e74e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E74E0-0x0E8810
#include <string.h>
#pragma intrinsic(strlen, strcpy)
int f_069460();

void f_0a7840(RivaItemDefinition *item,char *dst,short n);





int f_0bf820(void *, ...);
int f_0ce280(int p1);
int f_0ce2b0(char *p1);
int f_133fe0(int p1, int p2);
int f_144cb6(int p1, const char *p2, int p3);
int f_14572e(char *, const char *, ...);
void *f_145300(void *p1, int p2, int p3);
char *f_148143(char *p1, const char *p2, int p3);
extern signed char d_1a441c[];
extern signed char d_1a441d[];
extern signed char d_1a47ac[];
extern char d_1b82d8[];
extern char d_1b82f0[];
extern char d_1b82f2[];
extern char d_1b82f4[];
extern char d_1b82f6[];
extern char d_1b82f8[];
extern char d_1b82fa[];
extern char d_1b82fc[];
extern char d_1b82fe[];
extern char d_1b8300[];
extern char d_1b8302[];
extern char d_1b8304[];
extern char d_1b8306[];
extern char d_1b8308[];
extern char d_1bfaf0;
extern int d_1c0098;
extern int *d_1c008c;

extern char d_1c2c64[];
extern char d_1c27a8[];
extern int d_1c3498;
#define T(i) ((char *)d_1c008c[i])
#define S(v) (*(short *)&(v))
#define FL ((signed char)d_1bfaf0)
#pragma inline_depth(0)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0e74e0
/* === Beschreibung (Katalog) ===
 * Schreibt eine einzelne Textzeile (p2) gefolgt von einem Zeilenumbruch (\r\n) je nach globalem Druckmodus
 * (d_1bfaf0) entweder in die geöffnete Ausgabedatei (d_1c0098 über f_144cb6) oder Zeichen für Zeichen an die
 * Druckerschnittstelle (f_0ce2b0 und f_0ce280).
 * - Eingaben: Übergeben werden ein ungenutzter Kontext- bzw. Heldenzeiger p1 sowie die auszugebende Zeichenkette
 *   p2.
 * - Rückgabewert: Sie gibt im Dateimodus 1 bei erfolgreichem Schreiben (sonst 0) bzw. im Druckermodus den Status
 *   des letzten Druckzeichens (f_0ce280(10)) zurück.
 === Ende Beschreibung === */
int f_0e74e0(int p1, char *p2)
{
  int r = 0;
  signed char fl = d_1bfaf0;
  if (fl == 0) {
    int t_61 = f_144cb6(d_1c0098, p2, strlen(p2));
    if (t_61 != 0) {
      r = 1;
      f_144cb6(d_1c0098, d_1b82d8, strlen(d_1b82d8));
    }
  } else {
    f_0ce2b0(p2);
    f_069460();
    f_0ce280(0xd);
    r = f_0ce280(10);
  }
  return r;
}
//@ f_0e7560
/* === Beschreibung (Katalog) ===
 * Ermittelt für den Inventarplatz p2 (0..30) eines Helden (p1) sämtliche für den Charakterbogen-Ausdruck
 * relevanten Gegenstandsdaten: die Gegenstandskennung (*p3), die Stückzahl (*p4), das Gesamtgewicht (*p5), bei
 * Rüstungen den Rüstungsschutz aus d_1a47ac (*p6, sonst -1), bei Nahkampfwaffen den Attacke- und
 * Parade-Modifikator aus d_1a441c/d_1a441d (*p7 und *p8, sonst -1) sowie den formatierten Gegenstandsnamen in
 * d_1c27a8.
 * - Eingaben: Übergeben werden der Heldenzeiger p1, der Inventarslot p2 sowie sechs Ausgabezeiger für
 *   Gegenstands-ID (p3), Anzahl (p4), Gewicht (p5), Rüstungsschutz (p6), AT-Modifikator (p7) und PA-Modifikator
 *   (p8).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den formatierten Gegenstandsnamen im globalen Puffer
 *   d_1c27a8 zurück oder 0, falls der Inventarplatz leer ist.
 === Ende Beschreibung === */
#define OA(i) ((*(int **)&d_1c2c40)[(i)])
#define OB(i) (*(int *)((i) * 4 + (int)(*(int **)&d_1c2c40)))
char *f_0e7560(int p1, short p2, short *p3, short *p4, short *p5, short *p6, short *p7, short *p8)
{
  *p3 = *(short *)(p1 + p2 * 27 + 0x1a8);
  if (*p3 != 0) {
    *p4 = *(short *)(p1 + p2 * 27 + 0x1aa);
    if ((*p4 == 0 && *p3 != (short)0) || ((RivaItemDefinition*)(OA(*p3)))->f_0a7950() == 0) *p4 = 1;
    *p5 = ((int)(((RivaItemDefinition*)(OA(*p3)))->f_0a7810())) * *p4;
    int *objs = (*(int **)&d_1c2c40);
    if (((RivaItemDefinition*)(objs[*p3]))->f_0a79b0() != 0) {
      *p6 = d_1a47ac[((signed char)(((RivaItemDefinition*)(OA(*p3)))->f_0a78a0())) * 2];
    } else {
      *p6 = -1;
    }
    if (((RivaItemDefinition*)(OA(*p3)))->f_0a7990() && (((RivaItemDefinition*)(OA(*p3)))->f_0a7950() == 0 || (signed char)((signed char)(((RivaItemDefinition*)(OA(*p3)))->f_0a78b0())) == 8)) {
      *p7 = d_1a441c[((signed char)(((RivaItemDefinition*)(OA(*p3)))->f_0a78a0())) * 10];
      *p8 = d_1a441d[((signed char)(((RivaItemDefinition*)(OA(*p3)))->f_0a78a0())) * 10];
    } else {
      *p8 = -1;
      *p7 = *p8;
    }
    f_0a7840((RivaItemDefinition *)(*(int **)&d_1c2c40)[*p3], d_1c27a8, *p4);
    return d_1c27a8;
  }
  return 0;
}

//@ f_0e7720
/* === Beschreibung (Katalog) ===
 * Gibt die zweite Seite des Charakterbogens für einen magiebegabten Helden (p1) über f_0e74e0 aus: Nach den
 * Kopfdaten des Helden werden sämtliche 85 Zaubersprüche (f_0430f0) geordnet nach ihren Zaubergebieten
 * (Antimagie, Beherrschung, Dämonologie, Elemente, Bewegung, Heilung, Hellsicht, Illusion, Kampf, Verständigung,
 * Verwandlung und Transmutation) zweispaltig formatiert und am Ende mit einem Seitenvorschub (0x0c) oder einer
 * Dateifußzeile abgeschlossen.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Heldenstruktur p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e7720(int p1)
{
  signed char fl = FL;
  if (fl > 0) {
    f_0bf820(d_1c2c64, f_133fe0((int)&d_1c3498, d_1c008c[0]), 1, f_133fe0((int)&d_1c3498, d_1c008c[0x6d]));
  }
  f_0e74e0(p1, T(0x36));
  f_0e74e0(p1, d_1b82f0);
  f_14572e(d_1c27a8, T(4), ((int)(f_0422b0((struct hero *)(p1)))), T((((char)(f_042380((struct hero *)(p1)))) ? 0x8f : 0x83) + (signed char)((char)(f_042350((struct hero *)(p1))))), !((char)(f_042380((struct hero *)(p1)))) ? T(0x74) : T(0x75));
  f_0e74e0(p1, d_1c27a8);
  f_0e74e0(p1, d_1b82f2);
  f_0e74e0(p1, d_1b82f4);
  f_0e74e0(p1, T(0x37));
  f_0e74e0(p1, d_1b82f6);
  f_14572e(d_1c27a8, T(0x38), f_0430f0((struct hero *)(p1), 1), f_0430f0((struct hero *)(p1), 33));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x39), f_0430f0((struct hero *)(p1), 2), f_0430f0((struct hero *)(p1), 34));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x3a), f_0430f0((struct hero *)(p1), 3), f_0430f0((struct hero *)(p1), 35));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x3b), f_0430f0((struct hero *)(p1), 4), f_0430f0((struct hero *)(p1), 36));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x3c), f_0430f0((struct hero *)(p1), 5), f_0430f0((struct hero *)(p1), 37));
  f_0e74e0(p1, d_1c27a8);
  f_0e74e0(p1, d_1b82f8);
  f_0e74e0(p1, T(0x3d));
  f_0e74e0(p1, d_1b82fa);
  f_14572e(d_1c27a8, T(0x3e), f_0430f0((struct hero *)(p1), 18), f_0430f0((struct hero *)(p1), 27));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x3f), f_0430f0((struct hero *)(p1), 19), f_0430f0((struct hero *)(p1), 28));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x40), f_0430f0((struct hero *)(p1), 20), f_0430f0((struct hero *)(p1), 29));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x41), f_0430f0((struct hero *)(p1), 21), f_0430f0((struct hero *)(p1), 30));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x42), f_0430f0((struct hero *)(p1), 22), f_0430f0((struct hero *)(p1), 31));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x43), f_0430f0((struct hero *)(p1), 23), f_0430f0((struct hero *)(p1), 32));
  f_0e74e0(p1, d_1c27a8);
  f_0e74e0(p1, d_1b82fc);
  f_0e74e0(p1, T(0x44));
  f_0e74e0(p1, d_1b82fe);
  f_14572e(d_1c27a8, T(0x45), f_0430f0((struct hero *)(p1), 76), f_0430f0((struct hero *)(p1), 45));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x46), f_0430f0((struct hero *)(p1), 77), f_0430f0((struct hero *)(p1), 46));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x47), f_0430f0((struct hero *)(p1), 78), f_0430f0((struct hero *)(p1), 47));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x48), f_0430f0((struct hero *)(p1), 79), f_0430f0((struct hero *)(p1), 48));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x49), f_0430f0((struct hero *)(p1), 82));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x4a), f_0430f0((struct hero *)(p1), 80));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x4b), f_0430f0((struct hero *)(p1), 83));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x4c), f_0430f0((struct hero *)(p1), 84), f_0430f0((struct hero *)(p1), 24));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x4d), f_0430f0((struct hero *)(p1), 85), f_0430f0((struct hero *)(p1), 25));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x4e), f_0430f0((struct hero *)(p1), 81), f_0430f0((struct hero *)(p1), 26));
  f_0e74e0(p1, d_1c27a8);
  f_0e74e0(p1, d_1b8300);
  f_0e74e0(p1, T(0x4f));
  f_0e74e0(p1, d_1b8302);
  f_14572e(d_1c27a8, T(0x50), f_0430f0((struct hero *)(p1), 6), f_0430f0((struct hero *)(p1), 60));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x51), f_0430f0((struct hero *)(p1), 7), f_0430f0((struct hero *)(p1), 61));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x52), f_0430f0((struct hero *)(p1), 8), f_0430f0((struct hero *)(p1), 62));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x53), f_0430f0((struct hero *)(p1), 9), f_0430f0((struct hero *)(p1), 70));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x54), f_0430f0((struct hero *)(p1), 10), f_0430f0((struct hero *)(p1), 69));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x55), f_0430f0((struct hero *)(p1), 11), f_0430f0((struct hero *)(p1), 63));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x56), f_0430f0((struct hero *)(p1), 12), f_0430f0((struct hero *)(p1), 65));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x57), f_0430f0((struct hero *)(p1), 13), f_0430f0((struct hero *)(p1), 66));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x58), f_0430f0((struct hero *)(p1), 14), f_0430f0((struct hero *)(p1), 67));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x59), f_0430f0((struct hero *)(p1), 15), f_0430f0((struct hero *)(p1), 68));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5a), f_0430f0((struct hero *)(p1), 16), f_0430f0((struct hero *)(p1), 64));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5b), f_0430f0((struct hero *)(p1), 17), f_0430f0((struct hero *)(p1), 74));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5c), f_0430f0((struct hero *)(p1), 72));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5d), f_0430f0((struct hero *)(p1), 73));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5e), f_0430f0((struct hero *)(p1), 75));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x5f), f_0430f0((struct hero *)(p1), 49), f_0430f0((struct hero *)(p1), 71));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x60), f_0430f0((struct hero *)(p1), 50));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x61), f_0430f0((struct hero *)(p1), 51));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x62), f_0430f0((struct hero *)(p1), 52));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x63), f_0430f0((struct hero *)(p1), 53), f_0430f0((struct hero *)(p1), 38));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x64), f_0430f0((struct hero *)(p1), 54), f_0430f0((struct hero *)(p1), 39));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x65), f_0430f0((struct hero *)(p1), 55), f_0430f0((struct hero *)(p1), 40));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x66), f_0430f0((struct hero *)(p1), 56), f_0430f0((struct hero *)(p1), 41));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x67), f_0430f0((struct hero *)(p1), 57), f_0430f0((struct hero *)(p1), 42));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x68), f_0430f0((struct hero *)(p1), 43));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x69), f_0430f0((struct hero *)(p1), 44));
  f_0e74e0(p1, d_1c27a8);
  f_0e74e0(p1, d_1b8304);
  f_14572e(d_1c27a8, T(0x6a), f_0430f0((struct hero *)(p1), 58));
  f_0e74e0(p1, d_1c27a8);
  f_14572e(d_1c27a8, T(0x6b), f_0430f0((struct hero *)(p1), 59));
  f_0e74e0(p1, d_1c27a8);
  signed char fl2 = FL;
  if (fl2 == 0) {
    f_0e74e0(p1, d_1b8306);
    f_0e74e0(p1, T(0x6f));
    f_0e74e0(p1, d_1b8308);
  } else {
    f_0ce280(0xc);
  }
}
//@ f_0e8580
/* === Beschreibung (Katalog) ===
 * Liest über f_0e7560 die Daten zweier nebeneinander darzustellender Inventarplätze (p2 und p3) eines Helden
 * (p1) aus, kürzt deren Namen auf maximal 14 Zeichen (f_148143), formatiert Rüstungsschutz sowie
 * Waffen-AT/PA-Modifikatoren und gibt beide Inventarplätze gemeinsam in einer zweispaltigen Tabellenzeile über
 * f_0e74e0 aus.
 * - Eingaben: Übergeben werden der Heldenzeiger p1 sowie die Indizes der beiden Inventarplätze p2 (linke Spalte)
 *   und p3 (rechte Spalte).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8580(int p1, short p2, short p3)
{
  char a[40], b[40], c[20], d[20];
  char s1[12], s2[12], s3[8], s4[8];
  int fmt;
  short n7b, n8b, n4b, n5b, n6a, n3a;
  short n7a, n8a, n4a, n5a, n6b, n3b;
  strcpy(a, f_0e7560(p1, p2, (short *)&n3a, (short *)&n4a, (short *)&n5a, (short *)&n6a, (short *)&n7a, (short *)&n8a));
  strcpy(b, f_0e7560(p1, p3, (short *)&n3b, (short *)&n4b, (short *)&n5b, (short *)&n6b, (short *)&n7b, (short *)&n8b));
  fmt = !S(n3a) && !S(n3b) ? d_1c008c[0x30]
      : !S(n3a) ? d_1c008c[0x2e]
      : !S(n3b) ? d_1c008c[0x2f]
      : d_1c008c[0x2c];
  if (!S(n3a) && S(n3b)) {
    n3a = n3b;
    n4a = n4b;
    n5a = n5b;
    n6a = n6b;
    n7a = n7b;
    n8a = n8b;
    strcpy(a, b);
  }
  f_14572e(s1, S(n7a) != -1 ? T(0x32) : T(0x33), (int)S(n7a), (int)S(n8a));
  f_14572e(s2, S(n7b) != -1 ? T(0x32) : T(0x33), (int)S(n7b), (int)S(n8b));
  f_14572e(s3, S(n6a) != -1 ? T(0x34) : T(0x35), (int)S(n6a));
  f_14572e(s4, S(n6b) != -1 ? T(0x34) : T(0x35), (int)S(n6b));
  f_145300(c, 0, 20);
  f_145300(d, 0, 20);
  f_148143(c, a, 14);
  f_148143(d, b, 14);
  f_14572e(d_1c27a8, (char *)fmt, (int)S(n4a), c, (int)S(n5a), s3, s1, (int)S(n4b), d, (int)S(n5b), s4, s2);
  f_0e74e0(p1, d_1c27a8);
}

