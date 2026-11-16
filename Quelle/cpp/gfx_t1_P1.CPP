/* === Beschreibung (Katalog) ===
 * Einheit gfx_t1 (097700-098a90)
 *
 * Überblick
 * Diese Einheit bildet trotz ihres Dateinamens den hinteren Teil des Charaktergenerators (GEN.CPP, Fortsetzung
 * von gen2 und gen3). Sie enthält den Geschlechtsumschalter, das Zurücksetzen der Steigerungsversuche, die
 * Würfel- und Menülogik zum Steigern von Talenten und Zaubern während der Generierung sowie die Auswahl des
 * Heldentypus anhand der ausgewürfelten Eigenschaften.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMOUS.H"
// P3 3/6 gleich (suche.py 25.10.2026, Basis gfx_t1_P1.CPP)
// ERGAENZUNG: f_0978a0 (192 B, verdeckt zwischen f_097700 und f_097960) selbst definiert
// gfx_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x097700-0x098A90
#include <string.h>




struct B13 { char c[13]; };



int f_043af0(int p1, int p2);
int f_040e90(int p1);
int f_05e320(int p1, int p2, int p3);
int f_0938a0(char *p1);
int f_0e9510(int p1, int p2, int p3, int p4);
short f_0e95d0(int p1, int p2, int p3, int p4);

short f_036ee0(int p1, int p2);
short f_036ed0(int p1);
int f_0bf730(int p1, int p2);
int f_0bf820(int, ...);


short f_145760(int p1, int p2);

int f_094330(char *p1);
int f_094f40(char *p1);
short f_0945c0(char *p1);


int f_097600(char *p1, int p2, int p3, int p4);
short f_043ac0(int p1, int p2);
signed char f_043ac0(int p1, unsigned p2);
int f_0453e0(int p1, int p2, int p3);
int f_043ae0(int p1, int p2);
int f_098d90(char *p1, int p2, int p3);
void f_097960(char *p1, short p2);
extern int d_1bc88c;
extern signed char *d_1bc8a0;
extern signed char *d_1bc89c;
int f_043bd0(int p1, int p2);
extern char d_1c2c64[];
extern volatile short d_1c2198; // haelt den Speicherzugriff auf d_1c2198 wie im Original
extern int d_1a34e0;
extern int d_1c29c4[];
extern B13 d_1bdbc4;
extern signed char d_1a3204[];
extern signed char d_1a3205[];
extern signed char d_1a3210[];
extern char d_1c38b0[];
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_097700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet im Charaktergenerator das Geschlecht des aktuellen Helden zwischen männlich und
 *   weiblich um. Die Funktion aktualisiert die geschlechtsabhängigen Grenzen der Porträtauswahl, zeichnet das
 *   Geschlechtssymbol oben rechts (X = 306, Y = 3) neu und gibt auf den Grundwertseiten (p1[7] < 5) das erste
 *   passende Heldenporträt samt der zweizeiligen Typusbezeichnung aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generator-Zustandsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(p1 + 0xdf) verweist auf den bearbeiteten Helden, p1[0] enthält den für
 *   die Porträtauswahl gekappten Typusindex, p1 + 1..6 speichern den aktuellen, minimalen und maximalen
 *   Porträtindex aus d_1a3204, d_1a3205 und d_1a3210, und p1 + 0xf7 bzw. p1 + 0xfb sind die Rasterbilder für das
 *   männliche und weibliche Geschlechtssymbol.
 === Ende Beschreibung === */
void f_097700(char *p1)
{
  f_043af0(*(int *)(p1 + 0xdf), (signed char)(f_042380((struct hero *)(*(int *)(p1 + 0xdf))) ^ 1));
  RivaMouseGuard mg;
  if (f_042350((struct hero *)(*(int *)(p1 + 0xdf)))) {
    short v;
    if (f_042380((struct hero *)(*(int *)(p1 + 0xdf)))) {
      *(short *)(p1 + 3) = *(short *)(p1 + 1) = (short)d_1a3210[(signed char)p1[0]];
      v = (short)d_1a3205[(signed char)p1[0]];
    } else {
      *(short *)(p1 + 3) = *(short *)(p1 + 1) = (short)d_1a3204[(signed char)p1[0]];
      v = (short)d_1a3210[(signed char)p1[0]];
    }
    *(short *)(p1 + 5) = v - 1;
    f_042330((struct hero *)(*(int *)(p1 + 0xdf)), *(short *)(p1 + 1));
    f_0938a0(p1);
  }
  if (f_042380((struct hero *)(*(int *)(p1 + 0xdf)))) ((RivaRasterImage*)(*(int *)(p1 + 0xfb)))->f_0fade0((void *)( d_1a34e0), 0x132, 3);
  else ((RivaRasterImage*)(*(int *)(p1 + 0xf7)))->f_0fade0((void *)( d_1a34e0), 0x132, 3);
  if ((signed char)p1[7] < 5 && f_042350((struct hero *)(*(int *)(p1 + 0xdf)))) {
    short s;
    ((RivaRasterImage*)(*(int *)(p1 + 0x117)))->f_0fade0((void *)( d_1a34e0), 8, 8);
    f_05e320((int)d_1c38b0, 0xff, -1);
    s = f_0e95d0((int)d_1c38b0, f_040e90(*(int *)(p1 + 0xdf)), 8, 0x78);
    f_0e9510((int)d_1c38b0, f_040e90(*(int *)(p1 + 0xdf)), s, 0xb8);
  }
}
//@ f_0978a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt sämtliche Steigerungszähler, Eigenschaftszuordnungen und Porträtindizes des
 *   Charaktergenerators auf ihren Ausgangszustand zurück und initialisiert den Helden über f_043bd0 neu. Dabei
 *   werden auch die globalen Tabellen der bisherigen Talent- und Zaubersteigerungsversuche (d_1bc8a0 und
 *   d_1bc89c) vollständig gelöscht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generator-Zustandsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Felder *(int *)(p1 + 8) und *(int *)(p1 + 0xc) speichern temporäre
 *   Eigenschaftsmodifikatoren, p1[0x14..0x21] enthalten die vierzehn ausgewürfelten Eigenschaftswerte, d_1bc8a0
 *   umfasst 86 Einträge zu je zwei Bytes für Talentversuche und d_1bc89c umfasst 52 Einträge zu je zwei Bytes
 *   für Zauberversuche.
 === Ende Beschreibung === */
void f_0978a0(char *p1)
{
  short i;
  *(int *)(p1 + 8) = *(int *)(p1 + 0xc) = 0;
  *(short *)(p1 + 1) = 0;
  *(short *)(p1 + 3) = *(short *)(p1 + 5) = *(short *)(p1 + 1);
  *p1 = (char)*(short *)(p1 + 3);
  f_042330((struct hero *)(*(int *)(p1 + 0xdf)), *(short *)(p1 + 1));
  for (i = 0; i < 14; i++) p1[0x14 + i] = 0;
  for (i = 0; i < 0x56; i++) { signed char *t = d_1bc8a0 + i * 2; t[0] = t[1] = 0; }
  for (i = 0; i < 0x34; i++) { signed char *t = d_1bc89c + i * 2; t[0] = t[1] = 0; }
  f_043bd0(*(int *)(p1 + 0xdf), 1);
}
//@ f_097960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt bei der Charaktergenerierung oder beim Stufenaufstieg einen einzelnen Steigerungsversuch
 *   für das Talent p2 durch. Die Funktion prüft zunächst, ob die Höchstzahl erfolgreicher Steigerungen
 *   (f_036ee0) oder drei Fehlversuche in Folge erreicht sind, zieht einen freien Talentversuch ab (f_043310) und
 *   würfelt je nach aktuellem Talentwert mit 2W6 (bis Talentwert 10) oder 3W6 (ab Talentwert 11) gegen den
 *   bisherigen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generatorzeiger p1 sowie die Talentnummer p2 (short) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Array d_1bc8a0 speichert pro Talent die Anzahl der Fehlversuche (failures)
 *   und Erfolge (gains) auf dieser Stufe, und d_1bc88c sperrt während des Dialogs rekursive Eingaben.
 === Ende Beschreibung === */
struct SkillAttempt1011 {
  signed char failures, gains;
  void improve() { failures = 0; gains++; }
  void fail() { failures++; }
};
static inline SkillAttempt1011 &attempt1011(short skill)
{
  return ((SkillAttempt1011 *)d_1bc8a0)[skill];
}
void f_097960(char *p1, short p2)
{
  short maximum, roll;
  d_1bc88c = 1;
  maximum = f_036ee0(p2, *(int *)(p1 + 0xdf));
  if (attempt1011(p2).gains >= maximum) {
    f_0bf730((int)d_1c2c64, 0xe140032);
  } else if (attempt1011(p2).failures == 3) {
    f_0bf730((int)d_1c2c64, 0xe140029);
  } else {
    f_043310((struct hero *)(*(int *)(p1 + 0xdf)), -1);
    if (f_0430f0((struct hero *)(*(int *)(p1 + 0xdf)), p2) >= 11)
      roll = f_145760(3, 0x12);
    else
      roll = f_145760(2, 0xc);
    if (roll > f_0430f0((struct hero *)(*(int *)(p1 + 0xdf)), p2)) {
      f_0bf730((int)d_1c2c64, 0xe14002a);
      f_043110((struct hero *)(*(int *)(p1 + 0xdf)), p2, 1);
      attempt1011(p2).improve();
      f_094330(p1);
    } else {
      f_0bf730((int)d_1c2c64, 0xe14002b);
      attempt1011(p2).fail();
      f_094330(p1);
    }
  }
  d_1bc88c = 0;
}
#pragma inline_depth(0)
//@ f_097ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet auf den Talentseiten des Charaktergenerators (p1[7] von 5 bis 10) das mehrstufige
 *   Auswahlmenü zum Steigern eines Talents der jeweiligen Talentgruppe. Solange der Held noch freie
 *   Talentsteigerungen (f_0432f0) besitzt und der Spieler das Menü nicht abbricht, ruft die Schleife für das
 *   gewählte Talent f_097960 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generator-Zustandsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Byte p1[7] gibt die aktuell aufgeschlagene Seite des Charakterbogens an (5 bis 10
 *   für die verschiedenen Talentkategorien), menu speichert die gewählte Untergruppe und item den ausgewählten
 *   Talentindex.
 === Ende Beschreibung === */
void f_097ac0(char *p1)
{
  short item;
  short menu;
  register int count;
  for (;;) {
    if (!((char)(f_0432f0((struct hero *)(*(int *)(p1 + 0xdf)))))) {
      f_0bf730((int)d_1c2c64, 0xe140024);
      return;
    }
    switch (p1[7]) {
    case 5:
      menu = f_0bf820((int)d_1c2c64, 0xe14002d, 3, 0x200000ee, 0x200000f3, 0x200000ef);
      if (menu != -1) {
        switch (menu) {
        case 1:
          count = 5;
          item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x20000098, 0x20000099, 0x2000009a, 0x2000009b, 0x2000009c) - 1;
          if (item != -2) f_097960(p1, item + 1);
          break;
        case 2:
          count = 5;
          item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000b8, 0x200000b9, 0x200000ba, 0x200000bb, 0x200000bc) - 1;
          if (item != -2) f_097960(p1, item + 33);
          break;
        case 3:
          count = 6;
          item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x2000009d, 0x2000009e, 0x2000009f, 0x200000a0, 0x200000a1, 0x200000a2) - 1;
          if (item != -2) f_097960(p1, item + 6);
          break;
        }
      }
      break;
    case 6:
      menu = f_0bf820((int)d_1c2c64, 0xe14002d, 3, 0x200000ef, 0x200000f0, 0x200000f1);
      if (menu != -1) {
        switch (menu) {
        case 1: count = 6; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000a3, 0x200000a4, 0x200000a5, 0x200000a6, 0x200000a7, 0x200000a8) - 1; if (item != -2) f_097960(p1, item + 12); break;
        case 2: count = 6; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000a9, 0x200000aa, 0x200000ab, 0x200000ac, 0x200000ad, 0x200000ae) - 1; if (item != -2) f_097960(p1, item + 18); break;
        case 3: count = 3; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000af, 0x200000b0, 0x200000b1) - 1; if (item != -2) f_097960(p1, item + 24); break;
        }
      }
      break;
    case 7:
      menu = f_0bf820((int)d_1c2c64, 0xe14002d, 3, 0x200000f2, 0x200000f4, 0x200000f5);
      if (menu != -1) {
        switch (menu) {
        case 1: count = 6; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000b2, 0x200000b3, 0x200000b4, 0x200000b5, 0x200000b6, 0x200000b7) - 1; if (item != -2) f_097960(p1, item + 27); break;
        case 2: count = 7; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000bd, 0x200000be, 0x200000bf, 0x200000c0, 0x200000c1, 0x200000c2, 0x200000c3) - 1; if (item != -2) f_097960(p1, item + 38); break;
        case 3: count = 2; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000c4, 0x200000c5) - 1; if (item != -2) f_097960(p1, item + 45); break;
        }
      }
      break;
    case 8:
      menu = f_0bf820((int)d_1c2c64, 0xe14002d, 3, 0x200000f5, 0x200000f6, 0x200000f7);
      if (menu != -1) {
        switch (menu) {
        case 1: count = 2; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000c6, 0x200000c7) - 1; if (item != -2) f_097960(p1, item + 47); break;
        case 2: count = 9; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000c8, 0x200000c9, 0x200000ca, 0x200000cb, 0x200000cc, 0x200000cd, 0x200000ce, 0x200000cf, 0x200000d0) - 1; if (item != -2) f_097960(p1, item + 49); break;
        case 3: count = 2; item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000d1, 0x200000d2) - 1; if (item != -2) f_097960(p1, item + 58); break;
        }
      }
      break;
    case 9:
      count = 16;
      item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000d3, 0x200000d4, 0x200000d5, 0x200000d6, 0x200000d7, 0x200000d8, 0x200000d9, 0x200000da, 0x200000db, 0x200000dc, 0x200000dd, 0x200000de, 0x200000df, 0x200000e0, 0x200000e1, 0x200000e2) - 1;
      if (item != -2) f_097960(p1, item + 60); else menu = -1;
      break;
    case 10:
      count = 10;
      item = f_0bf820((int)d_1c2c64, 0xe14002e, count, 0x200000e3, 0x200000e4, 0x200000e5, 0x200000e6, 0x200000e7, 0x200000e8, 0x200000e9, 0x200000ea, 0x200000eb, 0x200000ec) - 1;
      if (item != -2) f_097960(p1, item + 76); else menu = -1;
      break;
    }
    if (menu != -1) continue;
    return;
  }
}
#pragma inline_depth(3)
//@ f_098240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet auf den Zauberseiten des Charaktergenerators (p1[7] von 1 bis 3) das Auswahlmenü zum
 *   Steigern eines Zauberspruchs oder zum Umwandeln zwischen Astralenergie- und Zaubersteigerungen. Solange der
 *   Held noch freie Zaubersteigerungen (f_043340) besitzt, wird für den gewählten Spruch die Steigerungsfunktion
 *   f_097600 mit dem Höchstwert aus f_036ed0 aufgerufen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generator-Zustandsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Byte p1[7] bezeichnet die aktive Zauberseite (1 bis 3), choice berechnet den
 *   globalen Zauberindex (0 bis 51) und d_1c2c64 ist der globale Dialogmanager.
 === Ende Beschreibung === */
void f_098240(char *p1)
{
  short menu;
  short choice;
  short item;
  signed char mode;
  for (;;) {
    if (!((char)(f_043340((struct hero *)(*(int *)(p1 + 0xdf)))))) {
      f_0bf730((int)d_1c2c64, 0xe140024);
      return;
    }
    mode = p1[7];
    switch (mode) {
    case 1: {
      menu = f_0bf820((int)d_1c2c64, 0xe140023, 2, 0x20000090, 0x20000091);
      if (menu != -1) {
        choice = menu;
        switch (choice) {
        case 1:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 9, 0x2000005c, 0x2000005d, 0x2000005e, 0x2000005f, 0x20000060, 0x20000061, 0x20000062, 0x20000063, 0x20000064) - 1;
          if (item != -2) f_097600(p1, item, f_036ed0(item), 0xe140026);
          break;
        case 2:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 10, 0x20000065, 0x20000066, 0x20000067, 0x20000068, 0x20000069, 0x2000006a, 0x2000006b, 0x2000006c, 0x2000006d, 0x2000006e) - 1;
          if (item != -2) { choice = item + 9; f_097600(p1, choice, f_036ed0(choice), 0xe140027); }
          break;
        }
      }
    } break;
    case 2: {
      menu = f_0bf820((int)d_1c2c64, 0xe140023, 2, 0x20000092, 0x20000093);
      if (menu != -1) {
        choice = menu;
        switch (choice) {
        case 1:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 7, 0x2000006f, 0x20000070, 0x20000071, 0x20000072, 0x20000073, 0x20000074, 0x20000075) - 1;
          if (item != -2) { choice = item + 19; f_097600(p1, choice, f_036ed0(choice), 0xe140027); }
          break;
        case 2:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 9, 0x2000007c, 0x2000007d, 0x2000007e, 0x2000007f, 0x20000080, 0x20000081, 0x20000082, 0x20000083, 0x20000084) - 1;
          if (item != -2) { choice = item + 32; f_097600(p1, choice, f_036ed0(choice), 0xe140028); }
          break;
        }
      }
    } break;
    case 3: {
      menu = f_0bf820((int)d_1c2c64, 0xe140023, 3, 0x20000094, 0x20000095, 0x20000096);
      if (menu != -1) {
        choice = menu;
        switch (choice) {
        case 1:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 9, 0x20000085, 0x20000086, 0x20000087, 0x20000088, 0x20000089, 0x2000008a, 0x2000008b, 0x2000008c, 0x2000008d) - 1;
          if (item != -2) { choice = item + 41; f_097600(p1, choice, f_036ed0(choice), 0xe140027); }
          break;
        case 2:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 6, 0x20000076, 0x20000077, 0x20000078, 0x20000079, 0x2000007a, 0x2000007b) - 1;
          if (item != -2) { choice = item + 26; f_097600(p1, choice, f_036ed0(choice), 0xe140027); }
          break;
        case 3:
          item = f_0bf820((int)d_1c2c64, 0xe140025, 2, 0x2000008e, 0x2000008f) - 1;
          if (item != -2) { choice = item + 50; f_097600(p1, choice, f_036ed0(choice), 0xe140026); }
          break;
        }
      }
    } break;
    }
    if (menu == -1) return;
  }
}
//@ f_098730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für alle zwölf Heldentypen, ob die aktuellen Eigenschaftswerte des Helden die jeweiligen
 *   Mindest- und Höchstanforderungen erfüllen, und bietet die zulässigen Typen in einem Auswahlmenü an. Wählt
 *   der Spieler einen neuen Typus aus, setzt die Funktion den Typus (f_043ae0), lädt das zugehörige Startporträt
 *   (f_098d90), initialisiert die Grundwerte (f_094f40) und zeichnet den Charakterbogen neu (f_094330).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generator-Zustandsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle unter *(int *)(p1 + 0x28) enthält pro Heldentypus (i = 1..12) sechs
 *   Voraussetzungspaare aus Eigenschafts-ID und Grenzwert (wobei Bit 0x80 eine Höchstgrenze für schlechte
 *   Eigenschaften kennzeichnet), d_1c29c4 nimmt die Text-IDs der wählbaren Typen auf und buf speichert die
 *   zugehörigen Typusnummern.
 === Ende Beschreibung === */
typedef struct { unsigned char id; unsigned char fl; } GE98;
void f_098730(char *p1)
{
  B13 buf = d_1bdbc4;
  signed char cur;
  short j;
  short i;
  short flag;
  signed char cnt;
  signed char v;
  short k;
  short s;
  int base;
  d_1bc88c = 1;
  if (f_043ac0(*(int *)(p1 + 0xdf), (unsigned)0)) {
    cur = f_042350((struct hero *)(*(int *)(p1 + 0xdf)));
    if (*(int *)(p1 + 8)) f_0453e0(*(int *)(p1 + 0xdf), 0, -1);
    if (*(int *)(p1 + 0xc)) f_0453e0(*(int *)(p1 + 0xdf), 2, -1);
    cnt = 0;
    for (i = 1; i <= 12; i++) {
      flag = 0;
      for (j = 0; j < (short)6; j++) {
        int b = *(int *)(p1 + 0x28);
        int row = b + i * 12;
        int jj = j * 2;
        GE98 *e = (GE98 *)(row + jj);
        if (e->fl) {
          unsigned id = e->id;
          v = f_043ac0(*(int *)(p1 + 0xdf), id);
          if (((GE98 *)(*(int *)(p1 + 0x28) + i * 12 + j * 2))->fl & 0x80) {
            if (v > (((GE98 *)(*(int *)(p1 + 0x28) + i * 12 + j * 2))->fl & 0x7f)) flag = 1;
          } else {
            if (v < ((GE98 *)(*(int *)(p1 + 0x28) + i * 12 + j * 2))->fl) flag = 1;
          }
        }
      }
      if (!flag) {
        if (f_042380((struct hero *)(*(int *)(p1 + 0xdf)))) base = 0x2000004f;
        else base = 0x20000042;
        d_1c29c4[cnt] = i + base;
        buf.c[cnt++] = (char)i;
      }
    }
    if (!cnt) {
      if (!f_0945c0(p1)) f_0bf730((int)d_1c2c64, 0xe140040);
      else f_0bf730((int)d_1c2c64, 0xe140010);
    } else {
      k = f_0bf820((int)d_1c2c64, 0xe14000f, cnt,
         d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3],
         d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
         d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11]);
      if (k != -1 && (signed char)buf.c[k - 1] != cur) {
        f_043ae0(*(int *)(p1 + 0xdf), (signed char)buf.c[k - 1]);
        f_098d90(p1, d_1a34e0, f_042350((struct hero *)(*(int *)(p1 + 0xdf))));
        p1[0] = f_042350((struct hero *)(*(int *)(p1 + 0xdf))) > 10 ? 10 : f_042350((struct hero *)(*(int *)(p1 + 0xdf)));
        if (f_042380((struct hero *)(*(int *)(p1 + 0xdf)))) {
          *(short *)(p1 + 3) = *(short *)(p1 + 1) = (short)d_1a3210[(signed char)p1[0]];
          s = (short)d_1a3205[(signed char)p1[0]];
        } else {
          *(short *)(p1 + 3) = *(short *)(p1 + 1) = (short)d_1a3204[(signed char)p1[0]];
          s = (short)d_1a3210[(signed char)p1[0]];
        }
        *(short *)(p1 + 5) = s - 1;
        f_042330((struct hero *)(*(int *)(p1 + 0xdf)), *(short *)(p1 + 1));
        *(int *)(p1 + 8) = *(int *)(p1 + 0xc) = 0;
        f_094f40(p1);
        d_1c2198 = 1;
        f_094330(p1);
      } else {
        if (*(int *)(p1 + 8)) f_0453e0(*(int *)(p1 + 0xdf), 0, 1);
        if (*(int *)(p1 + 0xc)) f_0453e0(*(int *)(p1 + 0xdf), 2, 1);
      }
    }
  } else {
    f_0bf730((int)d_1c2c64, 0xe14003a);
  }
  d_1bc88c = 0;
}
