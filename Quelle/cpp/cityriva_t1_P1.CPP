/* === Beschreibung (Katalog) ===
 * Einheit cityriva_t1 (0x0480a0 - 0x049c30)
 *
 * Überblick
 * Die Einheit cityriva_t1 implementiert den Haupt-Aktionsverteiler der Stadt Riva: Sie regelt den Einstieg in
 * die Kanalisation von Riva (nur tagsüber zwischen 12:00 und 30:00 Uhr interner Tageszeit möglich), verknüpft
 * die virtuelle Methodentabelle des Stadt-Objekts und ordnet in einer großen switch-Verzweigung (f_048130)
 * sämtliche Gebäude-, Markt-, Tempel-, Kanalisations- und Tavernen-Kennungen der Stadtkarte ihren jeweiligen
 * Handlerfunktionen zu.
 === Ende Beschreibung === */
// P3 2/3 gleich (suche.py 26.10.2026, Basis cityriva_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 2182 (vorher 2188)
// cityriva.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0480A0-0x049C30
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int *f_05ff60(int p1, int p2);
int f_0b3560(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0ea560();                                         // reg - stapel 0
int f_0eab60();                                         // reg - stapel 0
int f_0eabb0();                                         // reg - stapel 0
int f_0eac00();                                         // reg - stapel 0
int f_0eadd0();                                         // reg - stapel 0
int f_0eafa0();                                         // reg - stapel 0
int f_0eba10(int p1);
int f_0ec150();                                         // reg - stapel 0
int f_0ec7b0();                                         // reg - stapel 0
int f_0ecc70();                                         // reg - stapel 0
int f_0ecdd0();                                         // reg - stapel 0
int f_0ed040();                                         // reg - stapel 0
int f_0ed1c0();                                         // reg - stapel 0
int f_11e240();                                         // reg - stapel 0
int f_11e500(...);                                      // variable Stapelargumente
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int);
int f_126410(void *p1);
int f_1457e0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a0f20[];
extern char d_1bc91c;
extern char d_1bc920;
extern char d_1bcaa0;
extern char d_1bed7c;
extern char d_1bed80;
extern char d_1bedb8;
extern signed char d_1bedfc;
extern char d_1bee18;
extern char d_1bee1c;
extern int d_1c0004;                    // 0x1C0004
extern char d_1c00a0;
extern char d_1c00a4;
extern char d_1c00a8;
extern char d_1c00b0;
extern char d_1c00b4;
extern char d_1c00bc;
extern char d_1c00c0;
extern char d_1c00c4;
extern char d_1c00c8;
extern char d_1c00d0;
extern char d_1c00d4;
extern char d_1c0178;
extern char d_1c01c8;
extern char d_1c0ca4;
extern char d_1c0d64;
extern char d_1c2c44[];
extern char d_1c2c64[];
extern char d_1c349c[];
extern char d_1c3870[];
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1bad58[];
struct S1 { int a; char *b; };

//@ f_0480a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Versuch, über einen Einstieg (p1, 0 bis 3) in die Unterwelt/Kanalisation von Riva
 *   (0x1a) hinabzusteigen, ob die aktuelle Tageszeit (f_126410(d_1c2c44)) im erlaubten Zeitfenster zwischen
 *   0xa8c0 und 0x1a5e0 liegt; außerhalb dieser Zeit wird die Ablehnungsmeldung 0x23000001 ausgegeben, innerhalb
 *   des Fensters wird nach Bestätigung der Sicherheitsabfrage 0x23000002 die Heldengruppe an die Zielposition
 *   d_1a0f20[p1] im Dungeon 0x1a versetzt (f_0dd7f0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Index des Einstiegspunkts (p1) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Prüft die Tageszeit über d_1c2c44 und liest die Zielkoordinaten aus d_1a0f20.
 === Ende Beschreibung === */
void f_0480a0(short p1)
{
  if (f_126410(d_1c2c44) < 0xa8c0 || f_126410(d_1c2c44) > 0x1a5e0) {
    f_0bf730(d_1c2c64, 0x23000001);
    return;
  }
  if (f_0bf6f0(d_1c2c64, 0x23000002) == 1)
    f_0dd7f0(d_1c0004, 0x1a, d_1a0f20[p1]);
}

//@ f_048110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert als Konstruktor das Stadt-Riva-Steuerobjekt (p1), indem zuerst der
 *   Basiskonstruktor f_05ff60 aufgerufen und anschließend die virtuelle Methodentabelle d_1bad58 eingetragen
 *   wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Setzt den Vtable-Zeiger r[2] = (int)d_1bad58.
 === Ende Beschreibung === */
void f_048110(int p1)
{
  int *r = f_05ff60(p1, 0);
  r[2] = (int)d_1bad58;
}

//@ f_048130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet als zentraler Ereignis-Dispatcher der Stadtkarte Riva die ausgelöste Orts- oder
 *   Gebäudekennung p2: Kennungen von 0x0a bis 0x3f1 öffnen über f_0de810 Händler, Marktstände, Tempel, Heiler,
 *   Gilden und Stadtgebäude, wechseln in die Kanalisation (0x46-0x49 -> Karte 0x1a) bzw. das Umland (0x140 ->
 *   Karte 0x0d) oder lösen spezielle Stadtereignisse (0x1c2-0x1ea über f_0b3560) aus; Kennungen ab 0x7d1 bis
 *   0x82c steuern die Tavernen, Herbergen und Quest-Treffpunkte der Stadt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Stadt-Objekt (p1) sowie die Ereigniskennung
 *   (p2) und gibt 1 zurück, wenn die Kennung verarbeitet wurde, andernfalls 0.
 * - Wichtige Variablen: Nutzt die aktive Gruppe d_1c0004, die Uhrzeit d_1c2c44 sowie sämtliche Riva-Questflags
 *   (d_1bc91c bis d_1c0d64).
 === Ende Beschreibung === */
int f_048130(int p1, short p2)
{
  int result = 1;
  int decision;
  struct { int a; char *b; char rest[0x34]; } loc;
  struct E { static int eq(int a, int b) { return b == a ? 1 : 0; } };
  switch ((unsigned short)p2) {
  case 0xa:
    f_0de810(d_1c0004,1);
    break;
  case 0x1e:
    f_0de810(d_1c0004,3);
    break;
  case 0x32:
    f_0de810(d_1c0004,5);
    break;
  case 0x3c:
    f_0de810(d_1c0004,6);
    break;
  case 0x46: case 0x47: case 0x48: case 0x49:
    {
    short index = p2;
    int t = f_126410(d_1c2c44);
    index -= 0x46;
    if (t < 0xa8c0 || f_126410(d_1c2c44) > 0x1a5e0) {
      f_0bf730(d_1c2c64, 0x23000001);
      break;
    }
    if (f_0bf6f0(d_1c2c64, 0x23000002) != 1) {
      break;
    }
    f_0dd7f0(d_1c0004, 0x1a, d_1a0f20[(short)index]);
    break;
    }
  case 0x5a:
    f_0de810(d_1c0004,9);
    break;
  case 0x64:
    f_0de810(d_1c0004,10);
    break;
  case 0x6e:
    f_0de810(d_1c0004,0xb);
    break;
  case 0x78:
    f_0de810(d_1c0004,0xc);
    break;
  case 0x82:
    f_0de810(d_1c0004,0xd);
    break;
  case 0x8c:
    f_0de810(d_1c0004,0xe);
    break;
  case 0x96:
    f_0de810(d_1c0004,0xf);
    break;
  case 0xa0:
    f_0de810(d_1c0004,0x10);
    break;
  case 0xaa:
    f_0de810(d_1c0004,0x11);
    break;
  case 0xb4:
    f_0de810(d_1c0004,0x12);
    break;
  case 0xbe:
    f_0de810(d_1c0004,0x13);
    break;
  case 0xc8:
    f_0de810(d_1c0004,0x14);
    break;
  case 0xd2:
    f_0de810(d_1c0004,0x15);
    break;
  case 0xdc:
    f_0de810(d_1c0004,0x16);
    break;
  case 0xe6:
    f_0de810(d_1c0004,0x17);
    break;
  case 0xf0:
    f_0de810(d_1c0004,0x18);
    break;
  case 0xfa:
    f_0de810(d_1c0004,0x19);
    break;
  case 0x104:
    f_0de810(d_1c0004,0x1a);
    break;
  case 0x10e:
    f_0de810(d_1c0004,0x1b);
    break;
  case 0x118:
    f_0de810(d_1c0004,0x1c);
    break;
  case 0x122:
    f_0de810(d_1c0004,0x1d);
    break;
  case 0x12c:
    f_0de810(d_1c0004,0x1e);
    break;
  case 0x136:
    f_0de810(d_1c0004,0x1f);
    break;
  case 0x140:
    if (f_0bf6f0(d_1c2c64, 0x1600005f) != 1) {
      break;
    }
    f_0dd7f0(d_1c0004, 0xd, 0x139a);
    break;
  case 0x14a:
    f_0de810(d_1c0004,0x21);
    break;
  case 0x154:
    f_0de810(d_1c0004,0x22);
    break;
  case 0x15e:
    f_0de810(d_1c0004,0x23);
    break;
  case 0x168:
    f_0de810(d_1c0004,0x24);
    break;
  case 0x172:
    f_0de810(d_1c0004,0x25);
    break;
  case 0x17c:
    f_0de810(d_1c0004,0x26);
    break;
  case 0x186:
    f_0de810(d_1c0004,0x27);
    break;
  case 0x190:
    f_0de810(d_1c0004,0x28);
    break;
  case 0x19a:
    f_0de810(d_1c0004,0x29);
    break;
  case 0x1a4:
  case 0x1a5: case 0x1a6: case 0x1a7: case 0x1a8:
  case 0x1a9: case 0x1aa: case 0x1ab: case 0x1ac: case 0x1ad:
    f_0de810(d_1c0004,0x2a);
    break;
  case 0x1ae:
    f_0de810(d_1c0004,0x2b);
    break;
  case 0x1b8:
    f_0de810(d_1c0004,0x2c);
    break;
  case 0x1c2:
    f_0b3560(1,0x13ff);
    break;
  case 0x1cc:
    f_0b3560(1,0x1462);
    break;
  case 0x1d6:
    f_0b3560(1,0x14c3);
    break;
  case 0x1e0:
    f_0b3560(1,0x1521);
    break;
  case 0x1ea:
    f_0b3560(1,0x15fe);
    break;
  case 0x1f4:
    f_0de810(d_1c0004,0x32);
    break;
  case 0x1fe:
    f_0de810(d_1c0004,0x33);
    break;
  case 0x208:
    f_0de810(d_1c0004,0x34);
    break;
  case 0x212:
    f_0de810(d_1c0004,0x35);
    break;
  case 0x21c:
    f_0de810(d_1c0004,0x36);
    break;
  case 0x226:
    f_0de810(d_1c0004,0x37);
    break;
  case 0x230:
    f_0de810(d_1c0004,0x38);
    break;
  case 0x23a:
    f_0de810(d_1c0004,0x39);
    break;
  case 0x244:
    f_0de810(d_1c0004,0x3a);
    break;
  case 0x24e:
    f_0de810(d_1c0004,0x3b);
    break;
  case 0x258:
    f_0de810(d_1c0004,0x3c);
    break;
  case 0x262:
    f_0de810(d_1c0004,0x3d);
    break;
  case 0x26c:
    f_0de810(d_1c0004,0x3e);
    break;
  case 0x276:
    f_0de810(d_1c0004,0x3f);
    break;
  case 0x280:
    f_0de810(d_1c0004,0x40);
    break;
  case 0x28a:
    f_0de810(d_1c0004,0x41);
    break;
  case 0x294:
    f_0de810(d_1c0004,0x42);
    break;
  case 0x29e:
  case 0x29f: case 0x2a0: case 0x2a1: case 0x2a2:
  case 0x2a3: case 0x2a4: case 0x2a5: case 0x2a6: case 0x2a7:
    f_0de810(d_1c0004,0x43);
    break;
  case 0x2a8:
  case 0x2a9: case 0x2aa: case 0x2ab: case 0x2ac:
  case 0x2ad: case 0x2ae: case 0x2af: case 0x2b0: case 0x2b1:
    f_0de810(d_1c0004,0x44);
    break;
  case 0x2b2:
  case 0x2b3: case 0x2b4: case 0x2b5: case 0x2b6:
  case 0x2b7: case 0x2b8: case 0x2b9: case 0x2ba: case 0x2bb:
    f_0de810(d_1c0004,0x45);
    break;
  case 0x2bc:
    f_0de810(d_1c0004,0x46);
    break;
  case 0x2c6:
    f_0de810(d_1c0004,0x47);
    break;
  case 0x2d0:
    f_0de810(d_1c0004,0x48);
    break;
  case 0x2da:
    f_0de810(d_1c0004,0x49);
    break;
  case 0x2e4:
    f_0de810(d_1c0004,0x4a);
    break;
  case 0x2ee:
    f_0de810(d_1c0004,0x4b);
    break;
  case 0x2f8:
    f_0de810(d_1c0004,0x4c);
    break;
  case 0x302:
    f_0de810(d_1c0004,0x4d);
    break;
  case 0x30c:
    f_0de810(d_1c0004,0x4e);
    break;
  case 0x316:
    f_0de810(d_1c0004,0x4f);
    break;
  case 0x320:
    f_0de810(d_1c0004,0x50);
    break;
  case 0x32a:
    f_0de810(d_1c0004,0x51);
    break;
  case 0x334:
    f_0de810(d_1c0004,0x52);
    break;
  case 0x33e:
    f_0de810(d_1c0004,0x53);
    break;
  case 0x348:
    f_0de810(d_1c0004,0x54);
    break;
  case 0x352:
    f_0de810(d_1c0004,0x55);
    break;
  case 0x35c:
    f_0de810(d_1c0004,0x56);
    break;
  case 0x366:
    f_0de810(d_1c0004,0x57);
    break;
  case 0x370:
    f_0de810(d_1c0004,0x58);
    break;
  case 0x37a:
    f_0de810(d_1c0004,0x59);
    break;
  case 0x384:
    f_0de810(d_1c0004,0x5a);
    break;
  case 0x38e:
    f_0de810(d_1c0004,0x5b);
    break;
  case 0x398:
    f_0de810(d_1c0004,0x5c);
    break;
  case 0x3a2:
    f_0de810(d_1c0004,0x5d);
    break;
  case 0x3ac:
    f_0de810(d_1c0004,0x5e);
    break;
  case 0x3b6:
    f_0de810(d_1c0004,0x5f);
    break;
  case 0x3c0:
    f_0de810(d_1c0004,0x60);
    break;
  case 0x3ca:
    f_0de810(d_1c0004,0x61);
    break;
  case 0x3d4:
    f_0de810(d_1c0004,0x62);
    break;
  case 0x3de:
    f_0de810(d_1c0004,99);
    break;
  case 0x3e9:
    f_0de810(d_1c0004,100);
    break;
  case 0x3ea:
    f_0de810(d_1c0004,0x69);
    break;
  case 0x3eb:
    f_0de810(d_1c0004,0x6a);
    break;
  case 0x3ec:
    f_0de810(d_1c0004,0x6b);
    break;
  case 0x3ed:
    f_0de810(d_1c0004,0x6c);
    break;
  case 0x3ee:
    f_0de810(d_1c0004,0x6d);
    break;
  case 0x3ef:
    f_0de810(d_1c0004,0x6e);
    break;
  case 0x3e8:
  case 0x3f0:
  case 0x3f1:
    f_0de810(d_1c0004,0x6f);
    break;
  case 0x7d1:
  {
    signed char mark = 1;
    if (((unsigned char)(((int)(signed char)d_1c00a8) == (int)mark)) && ((unsigned char)(((signed char)d_1bedb8) == 0))) { f_0ea560(); break; }
    if (((unsigned char)(((signed char)d_1c00c4) == 0)) && ((unsigned char)(((signed char)d_1c0178) == 1))) { f_0eab60(); break; }
    if (((unsigned char)(((signed char)d_1bcaa0) == 0))) { f_0eac00(); break; }
    if (((unsigned char)(((signed char)d_1bcaa0) == 1)) && ((unsigned char)(((signed char)d_1c01c8) == 1)) && ((unsigned char)(((signed char)d_1c00c8) == 0))) { f_0eadd0(); break; }
    if (((unsigned char)(((signed char)d_1c00c8) == 1)) && ((unsigned char)(((signed char)d_1bed7c) == 0))) { f_0eafa0(); break; }
    if (((unsigned char)(((signed char)d_1bedfc) < 30)) && ((unsigned char)(((signed char)d_1bedfc) > 0)) && ((unsigned char)(((signed char)d_1bc91c) == 0))) {
      f_11e240(); d_1bc91c = 1; break;
    }
    if (((unsigned char)(((signed char)d_1c00a0) == 1)) && ((unsigned char)(((signed char)d_1c00bc) == 0)) && ((unsigned char)(((signed char)d_1c00d4) == 1))) { f_0ed040(); break; }
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) { f_0ed1c0(); break; }
    break;
  }
  case 0x7d2:
  {
    signed char mark = 0;
    if (((unsigned char)(((int)(signed char)d_1c00c4) == (int)mark)) && ((unsigned char)(((signed char)d_1c0178) == 1))) { f_0eabb0(); break; }
    if (((unsigned char)(((signed char)d_1bcaa0) == 0))) { f_0eac00(); break; }
    if (((unsigned char)(((signed char)d_1bed80) == 1)) && ((unsigned char)(((signed char)d_1c00a4) == 1)) && ((unsigned char)(((signed char)d_1bee1c) == 0))) { f_0ecc70(); break; }
    if (((unsigned char)(((signed char)d_1bedfc) < 30)) && ((unsigned char)(((signed char)d_1bedfc) > 0)) && ((unsigned char)(((signed char)d_1bc91c) == 0))) {
      f_11e240(); d_1bc91c = 1; break;
    }
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) { f_0ed1c0(); break; }
    break;
  }
  case 0x7d3:
  {
    signed char mark = 0;
    if (((unsigned char)(((int)(signed char)d_1c00c4) == (int)mark)) && ((unsigned char)(((signed char)d_1c0178) == 1))) { f_0eab60(); break; }
    if (((unsigned char)(((signed char)d_1bcaa0) == 0))) { f_0eac00(); break; }
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(2, 0x10, 0x12);
    break;
  }
  case 0x7d4: case 0x7d5:
  {
    signed char mark = 1;
    if (((unsigned char)(((int)(signed char)d_1bcaa0) == (int)mark)) && ((unsigned char)(((signed char)d_1c01c8) == 1)) && ((unsigned char)(((signed char)d_1c00c8) == 0))) { f_0eadd0(); break; }
    if (((unsigned char)(((signed char)d_1bed80) == 1)) && ((unsigned char)(((signed char)d_1c00a4) == 1)) && ((unsigned char)(((signed char)d_1bee1c) == 0))) { f_0ecc70(); break; }
    if (((unsigned char)(((signed char)d_1bedfc) < 30)) && ((unsigned char)(((signed char)d_1bedfc) > 0)) && ((unsigned char)(((signed char)d_1bc91c) == 0))) {
      f_11e240(); d_1bc91c = 1; break;
    }
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(1, 1);
    break;
  }
  case 0x7d7:
    f_1457e0(100);
  {
    signed char mark = 0;
    if (((unsigned char)(((int)(signed char)d_1bc920) == (int)mark))) {
      f_125400(&loc, d_1c349c, d_1c3870, d_1c349c - 4);
      *(int *)(loc.b + 4) = f_038c40(d_1c0004);
      f_0bf730(d_1c2c64, 0x1600005e);
      d_1bc920 = 1;
      f_1254a0(&loc, 0);
    }
    if (((unsigned char)(((signed char)d_1bee18) == 1)) && ((unsigned char)(((signed char)d_1c00c0) == 0))) { f_0ec150(); break; }
    if (((unsigned char)(((signed char)d_1bee1c) == 1)) && ((unsigned char)(((signed char)d_1c00a0) == 0)) && ((unsigned char)(((signed char)d_1c00d0) == 0))) { f_0ecdd0(); break; }
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(1, 1);
    break;
  }
  case 0x7d8:
  {
    signed char mark = (signed char)p2 ^ (signed char)p2;
    if (((unsigned char)(((int)(signed char)d_1c00b0) == (int)mark)) && (((unsigned char)(((signed char)d_1c0d64) == 1)) || ((unsigned char)(((signed char)d_1c0ca4) != 0)))) { f_0ec7b0(); break; }
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) { f_0ed1c0(); break; }
    break;
  }
  case 0x7d9:
  {
    signed char mark = (signed char)p2 ^ (signed char)p2;
    if (((unsigned char)(((int)(signed char)d_1bcaa0) == (int)mark))) { f_0eac00(); break; }
    break;
  }
  case 0x7da: case 0x7db: case 0x7dc: case 0x7dd: case 0x7de: case 0x7df: case 0x7e0:
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0)
      f_11e500(8, 1, 4, 5, 6, 7, 8, 9, 11);
    break;
  case 0x7e4: case 0x7e5: case 0x7e6:
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(4, 12, 13, 14, 15);
    break;
  case 0x7ee: case 0x7ef: case 0x7f0: case 0x7f1:
    decision = 0;
    if (((unsigned char)(((signed char)d_1bed80) == 1)) && ((unsigned char)(((signed char)d_1c00a4) == 1)) && ((unsigned char)(((signed char)d_1bee1c) == 0))) f_0ecc70();
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(2, 0x10, 0x12);
    break;
  case 0x7f8: case 0x7f9: case 0x7fa: case 0x7fb:
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(3, 0x11, 0x13, 0x14);
    break;
  case 0x802:
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0) f_11e500(1, 10);
    break;
  case 0x80c: case 0x80d: case 0x80e: case 0x80f: case 0x810:
  case 0x811: case 0x812: case 0x813: case 0x814: case 0x815:
  case 0x816: case 0x817: case 0x818: case 0x819: case 0x81a:
  case 0x821: case 0x822: case 0x823:
    decision = 0;
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) decision = f_0ed1c0();
    if (decision == 0)
      f_11e500(9, 2, 3, 4, 5, 6, 7, 8, 9, 11);
    break;
  case 0x81b: case 0x81c: case 0x81d: case 0x81e: case 0x81f: case 0x820:
    if (((unsigned char)(((signed char)d_1c00bc) == 1))) f_0ed1c0();
    break;
  case 0x82a: case 0x82b: case 0x82c:
    if (((unsigned char)(((signed char)d_1c00b4) == 1)) && ((unsigned char)(((signed char)d_1bed80) == 0)) && ((unsigned char)(((signed char)d_1bedfc) == 0)))
      f_0eba10((short)p2);
    break;
  default:
    result = 0;
    break;
  }
  return result;
}
