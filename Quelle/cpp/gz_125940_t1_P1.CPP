/* === Beschreibung (Katalog) ===
 * Einheit gz_125940_t1 (0x125940 - 0x125dc0)
 *
 * Überblick
 * Diese Einheit implementiert grammatikalische Textformatierungs-Methoden des Textplatzhalter-Systems
 * (textstub.cpp), die den Namen oder das Pronomen eines Helden (f_125940), eines Gegenstands (f_125a30) oder
 * eines Monsters (f_125c20) im geforderten Kasus, Numerus und Artikelmodus formatieren und im Textkontext
 * ablegen.
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 2/10 gleich (suche.py 26.10.2026, Basis gz_125940_P1.CPP)
// gz_125940.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x125940-0x1261B0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0463e0(int p1);                                   // reg eax stapel 0
int f_069460();                                         // reg - stapel 0
char * f_0a7890(RivaItemDefinition *item);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
signed char f_0d0180(int p1);                                   // reg eax stapel 0
int f_0d03f0(int p1);                                   // reg eax stapel 0
int f_1261b0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0c64;                    // 0x1C0C64
extern int d_1c0c94;                    // 0x1C0C94
extern int d_1c2c60;                    // 0x1C2C60
// --- eigene Funktionen (10), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_125940  groesse 240 B, 83 Bef, reg eax edx ebx ecx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für einen Helden (p2) je nach Modus (p3.m == 0: Personal-/Possessivpronomen, 1: Artikel,
 *   2: Name mit Deklination) den passenden Textbaustein unter Berücksichtigung des Geschlechts (f_042380) und
 *   speichert das Ergebnis in den Feldern +0x24 und +0x28 des Textplatzhalter-Eintrags p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf den Helden sowie in p3 und p4 die Bitfelder für Darstellungsmodus, Kasus und grammatikalische Attribute.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_125a30  groesse 496 B, 168 Bef, reg eax edx ebx ecx, stapel 4
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für eine Gegenstandsdefinition (p2) und eine gegebene Stückzahl (p3) je nach Modus (p4.m
 *   == 0: Pronomen, 1: Artikel, 2: deklinierter Gegenstandsname imSingular oder Plural) die passende
 *   Zeichenkette und speichert sie in den Feldern +0x24 und +0x28 von p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf die Gegenstandsdefinition (RivaItemDefinition), in p3 die Stückzahl sowie in p4 und p5 die
 *   Grammatik-Bitfelder.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_125c20  groesse 560 B, 123 Bef, reg eax edx ebx ecx, stapel 4
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für einen Gegnertyp (p2) und eine Anzahl (p3) je nach Modus (p4.m == 0: Pronomen, 1:
 *   Artikel, 2: deklinierter Monstername im Singular oder Plural) die passende Zeichenkette unter
 *   Berücksichtigung des grammatischen Geschlechts (f_0d0180) und speichert sie in p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf die Monsterdaten, in p3 die Anzahl sowie in p4 und p5 die Grammatik-Bitfelder.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_125dc0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit im Zeit-Objekt p1 schrittweise bis zur angegebenen Tageszeit p2 (in Ticks, bei
 *   kleinerem Zielwert bis zum nächsten Tag mit 0x1fa40 = 129600 Ticks pro Tag) vor und führt in jedem Schritt
 *   die Einzel-Tick-Aktualisierung (f_1261b0) sowie die Hintergrund-Ereignisprüfung (f_069460) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts (d_1c2c44) und in p2 die
 *   Ziel-Tageszeit in Ticks.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_125e50  groesse 128 B, 37 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um genau p2 einzelne Zeitticks vor und aktualisiert nach dem Durchlauf die
 *   Bildschirmanzeige (f_0463e0).
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   vorzuspulenden Ticks.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
//@ f_125ed0  groesse 160 B, 45 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 Spielminuten (jeweils 90 Ticks pro Minute, also p2 * 90 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Minuten.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der anschließenden Anzeigeaktualisierung (f_0463e0) zurück.
 === Ende Beschreibung === */

//@ f_125f70  groesse 576 B, 37 Bef, reg eax edx, stapel ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 Spielstunden (jeweils 5.400 Ticks pro Stunde, also p2 * 5400 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Stunden.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 als signed char zurück.
 === Ende Beschreibung === */
//@ f_126000  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle Spieltage (jeweils 0x1fa40 = 129.600 Ticks pro Tag) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Tage.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */
//@ f_126090  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle Monate zu je 30 Tagen (p2 * 3.888.000 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Monate.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */
//@ f_126120  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Spult die Spielzeit um p2 volle aventurische Jahre zu je 365 Tagen (p2 * 47.304.000 Ticks) vor.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Zeit-Objekts und in p2 die Anzahl der
 *   Jahre.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert von f_0463e0 zurück.
 === Ende Beschreibung === */

struct B8 { unsigned char a:2, b:2, c:4; };
struct BC { unsigned char a:2, b:1, c:5; };
struct B16 { unsigned char m:2, x:6; unsigned char h:3, y:5; };
struct M2 { unsigned char m:2; };
typedef int (*VA)(int,int,unsigned char);
typedef int (*VB)(int,int,int,unsigned short,unsigned char);
typedef int (*VB2)(int,int,int,int,unsigned char);
typedef int (*VB3)(int,int,int,int,int,unsigned short,unsigned char);
typedef int (*VC0)(int,int,int,unsigned char,int);
typedef int (*VD0)(int,int,int,int,int);
#define VT(o,off) (*(int*)(*(int*)((o)+1)+(off)))

typedef int (*VAs)(int,struct B16,struct B8);
typedef int (*VBs)(int,int,int,struct B16,struct B8);
typedef int (*VCs)(int,int,struct B16,struct B8,int);
typedef int (*VB2s)(int,int,int,int,struct B8);
typedef int (*VB3s)(int,int,int,int,int,struct B16,struct B8);
//@ f_125940
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für einen Helden (p2) je nach Modus (p3.m == 0: Personal-/Possessivpronomen, 1: Artikel,
 *   2: Name mit Deklination) den passenden Textbaustein unter Berücksichtigung des Geschlechts (f_042380) und
 *   speichert das Ergebnis in den Feldern +0x24 und +0x28 des Textplatzhalter-Eintrags p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf den Helden sowie in p3 und p4 die Bitfelder für Darstellungsmodus, Kasus und grammatikalische Attribute.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125940(int p1, int p2, struct B16 p3, struct B8 p4)
{
  int o, e, vt, r;
  signed char t;
  switch (p3.m) {
  case 0:
    t = f_042380((struct hero *)(p2));
    p4.a = t;
    p4.b = 0;
    o = *(int *)(p1 + 0x30);
    r = ((VAs)VT(o, 0x14))(o, p3, p4);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 1:
    o = *(int *)(p1 + 0x30);
    vt = *(int *)(o + 1);
    r = ((VBs)*(int *)(vt + 0x10))(o, 0, (int)f_042380((struct hero *)(p2)), p3, p4);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 2:
    e = ((int)(f_0422b0((struct hero *)(p2))));
    t = f_042380((struct hero *)(p2));
    p4.a = t;
    p4.b = 0;
    o = *(int *)(p1 + 0x30);
    r = ((VCs)VT(o, 0))(o, e, p3, p4, 0);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  }
}

//@ f_125a30
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für eine Gegenstandsdefinition (p2) und eine gegebene Stückzahl (p3) je nach Modus (p4.m
 *   == 0: Pronomen, 1: Artikel, 2: deklinierter Gegenstandsname imSingular oder Plural) die passende
 *   Zeichenkette und speichert sie in den Feldern +0x24 und +0x28 von p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf die Gegenstandsdefinition (RivaItemDefinition), in p3 die Stückzahl sowie in p4 und p5 die
 *   Grammatik-Bitfelder.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125a30(int p1, int p2, short p3, struct B16 p4, struct B8 p5)
{
  int o, vt, r;
  short u;
  char buf[52];
  switch (p4.m) {
  case 0:
    u = (p3 > 1 || ((RivaItemDefinition*)(p2))->f_0a7ad0() == 1) ? 1 : 0;
    p5.a = ((signed char)(((RivaItemDefinition*)(p2))->f_0a78c0()));
    p5.b = u;
    o = *(int *)(p1 + 0x30);
    r = ((VAs)VT(o, 0x14))(o, p4, p5);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 1:
    u = (p3 > 1 || ((RivaItemDefinition*)(p2))->f_0a7ad0() == 1) ? 1 : 0;
    o = *(int *)(p1 + 0x30);
    vt = *(int *)(o + 1);
    r = ((VBs)*(int *)(vt + 0x10))(o, (int)u, (int)((signed char)(((RivaItemDefinition*)(p2))->f_0a78c0())), p4, p5);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 2:
    {
    int o2;
    u = (p3 > 1 || ((RivaItemDefinition*)(p2))->f_0a7ad0() == 1) ? 1 : 0;
    if (((RivaItemDefinition*)(p2))->f_0a7ac0() == 1 && p4.h == 1) p4.h = 0;
    o2 = *(int *)(p1 + 0x30);
    vt = *(int *)(o2 + 1);
    ((VB3s)*(int *)(vt + 0x18))(o2, (int)buf, 0, ((int)(f_0a7890((RivaItemDefinition *)(p2)))), (int)p3, p4, p5);
    p5.a = ((signed char)(((RivaItemDefinition*)(p2))->f_0a78c0()));
    p5.b = u;
    o = *(int *)(p1 + 0x30);
    r = ((VCs)VT(o, 0))(o, (int)buf, p4, p5, 0);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
    }
  }
}

//@ f_125c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Formatiert für einen Gegnertyp (p2) und eine Anzahl (p3) je nach Modus (p4.m == 0: Pronomen, 1:
 *   Artikel, 2: deklinierter Monstername im Singular oder Plural) die passende Zeichenkette unter
 *   Berücksichtigung des grammatischen Geschlechts (f_0d0180) und speichert sie in p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den Textplatzhalter-Eintrag, in p2 den Zeiger
 *   auf die Monsterdaten, in p3 die Anzahl sowie in p4 und p5 die Grammatik-Bitfelder.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_125c20(int p1, int p2, short p3, struct B16 p4, struct B8 p5)
{
  int o, vt, r;
  signed char c;
  short fl;
  char l4c[52];
  char l80[52];

  fl = p3 > 1 ? 1 : 0;
  switch (p4.m) {
  case 0:
    c = f_0d0180(p2);
    p5.a = c;
    p5.b = fl;
    o = *(int *)(p1 + 0x30);
    r = ((VAs)VT(o, 0x14))(o, p4, p5);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 1:
    o = *(int *)(p1 + 0x30);
    vt = *(int *)(o + 1);
    r = ((VBs)*(int *)(vt + 0x10))(o, (int)fl,
                                   (int)f_0d0180(p2), p4, p5);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  case 2:
    o = *(int *)(p1 + 0x30);
    vt = *(int *)(o + 1);
    ((VB3s)*(int *)(vt + 0x18))(o, (int)l80, (int)l4c,
                                  f_0d03f0(p2), (int)p3,
                                  p4, p5);
    c = f_0d0180(p2);
    p5.a = c;
    p5.b = fl;
    r = ((VCs)VT(*(int *)(p1 + 0x30), 0))(
        *(int *)(p1 + 0x30), (int)l80, p4, p5, (int)l4c);
    *(int *)(p1 + 0x24) = r;
    *(int *)(p1 + 0x28) = r;
    break;
  }
}
