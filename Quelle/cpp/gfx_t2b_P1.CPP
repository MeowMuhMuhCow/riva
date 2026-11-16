/* === Beschreibung (Katalog) ===
 * Einheit gfx_t2b (099820-099910)
 *
 * Überblick
 * Diese kleine Einheit enthält drei Verwaltungsfunktionen für den 25-teiligen Grafik-Cache (Cache1050), mit
 * denen sämtliche Einträge geleert, ein bestimmter Slot unter automatischer Verdrängung neu geladen oder ein
 * einzelner Slot gezielt freigegeben werden kann.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// P3 16/29 gleich (suche.py 25.10.2026, Basis gfx_t2_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 10 gleich (vorher 10), Rest 750 (vorher 752)
// gfx.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x097700-0x09AF30
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_014a60();                                         // reg - stapel 0
int f_036ed0(int p1);                                   // reg eax stapel 0
int f_036ee0(int p1, int p2);                           // reg eax edx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_043ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_043ae0(int p1, int p2);                           // reg eax edx stapel 0
int f_043af0(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fd00();                                         // reg - stapel 0
int f_05fd70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fe40(int p1);                                   // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_0937e0(int p1);                                   // reg eax stapel 0
int f_0938a0(int p1);                                   // reg eax stapel 0
int f_094330(int p1);                                   // reg eax stapel 0
int f_0945c0(int p1);                                   // reg eax stapel 0
int f_094c70(int p1);                                   // reg eax stapel 0
int f_094f40(int p1);                                   // reg eax stapel 0
int f_097600(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0b0a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0b0e20(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3580(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3970(int p1, int p2);                           // reg eax edx stapel 0
int f_0e39e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3ba0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0e4650(int p1);                                   // reg eax stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
           // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149cf0();                       // nicht in clobber.tsv
int f_149d20();                                         // reg - stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_15689d(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_0e0011;                    // 0x0E0011
extern int d_0e0012;                    // 0x0E0012
extern int d_0e0015;                    // 0x0E0015
extern int d_1a3204;                    // 0x1A3204
extern int d_1a3205;                    // 0x1A3205
extern int d_1a3210;                    // 0x1A3210
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a34e4;                    // 0x1A34E4
extern int d_1a965c;                    // 0x1A965C
extern int d_1a9b9c;                    // 0x1A9B9C
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1baf74;                    // 0x1BAF74
extern int d_1baf88;                    // 0x1BAF88
extern int d_1bc88c;                    // 0x1BC88C
extern int d_1bc8a0;                    // 0x1BC8A0
extern int d_1bc8f0;                    // 0x1BC8F0
extern int d_1bdbc4;                    // 0x1BDBC4
extern int d_1bdbc8;                    // 0x1BDBC8
extern int d_1bdbcc;                    // 0x1BDBCC
extern int d_1bdbd0;                    // 0x1BDBD0
extern int d_1bdbd4;                    // 0x1BDBD4
extern int d_1bdbd6;                    // 0x1BDBD6
extern int d_1bdbd8;                    // 0x1BDBD8
extern int d_1bdbda;                    // 0x1BDBDA
extern int d_1bdbdc;                    // 0x1BDBDC
extern int d_1bdbe4;                    // 0x1BDBE4
extern int d_1bdbe8;                    // 0x1BDBE8
extern int d_1bdbec;                    // 0x1BDBEC
extern int d_1bdcec;                    // 0x1BDCEC
extern int d_1bdcf0;                    // 0x1BDCF0
extern int d_1bf514;                    // 0x1BF514
                    // 0x1C2098
extern int d_1c2198;                    // 0x1C2198
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c29f0;                    // 0x1C29F0
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a34c4[];           // Text 0x1A34C4
extern const char d_1a9680[];           // Text 0x1A9680


#pragma inline_depth(0)
#define I(a) (*(int*)(a))
#define S(a) (*(short*)(a))
#define W(a) (*(unsigned short*)(a))
#define B(a) (*(unsigned char*)(a))
#define R(i,k) d_1a64fc[(i)*5+(k)]
#define VSL(o,k) (*(int*)(*(int*)((o)+0x14)+(k)))
typedef int (*FN1)(int);
typedef int (*FN3)(int,int,int);
struct RECB { char x[0x5ef]; };
struct KEY { unsigned a:8; unsigned b:8; unsigned c:16; };
int f_0995c0(int p1, struct KEY k);
int f_099a20(int p1, struct KEY k);
#define GT0(e) ((e) > 0)
#define SV(x) ((short)(x))
#define LI int
#define KA k.a
#define KB k.b
#define KINIT
extern short d_1a64fc[];
extern short d_1a6506, d_1a6508, d_1a650a, d_1a650c, d_1a650e;
extern short d_1bd760, d_1bd766;
extern unsigned short d_1bf4f0;
extern unsigned short d_1bd762;
extern signed char d_1c2a50, d_1a9692, d_1a9693, d_1a9694;
extern char d_1c21b4[];





short f_0c0020(int p1, int p2);
short f_0bf820(int, ...);
int f_099ef0(int, int, int);
#pragma aux f_099ef0 parm caller [] modify [eax ecx edx];
int f_144bf0(char *p1, char *p2);
int f_147c84(int p1, int p2, int p3);
int f_156870(int p1, int p2, int p3);
int f_098730(int p1);
int f_0e4370(int p1);
int f_0990b0(int p1, int p2, int p3);
void f_099560(int p1);
int f_099910(int p1);
//@ f_099820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft alle 25 Slots des Grafik-Caches p1 und gibt jeden belegten Eintrag (I(iVar1 + 8) !=
 *   0) über f_099560 frei, wobei auch dessen Alterungspriorität auf 0 zurückgesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Basisadresse p1 des Grafik-Caches und gibt nach Abschluss der
 *   Schleife den Endindex 25 (0x19) zurück (int).
 * - Wichtige Variablen: Jeder der 25 Einträge hat eine Schrittweite von 0x27 (39) Bytes; I(iVar1 + 8) ist der
 *   Zeiger auf die geladenen Pixeldaten und B(iVar1 + 0x26) das Alterungsbyte des jeweiligen Slots.
 === Ende Beschreibung === */
int f_099820(int p1)
{
  int iVar2, iVar1;
  LI s;
  s = 0;
  goto test;
next:
  s++;
test:
  if (SV(s) >= 0x19) return SV(s);
  iVar2 = SV(s) * 0x27;
  iVar1 = p1 + iVar2;
  if (I(iVar1+8) != 0) {
    f_099560(p1 + 4 + iVar2);
    B(iVar1+0x26) = 0;
  }
  goto next;
}
//@ f_099860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die durch den Schlüssel k bezeichnete Grafikressource in den Cache-Slot p3. Reicht der
 *   freie Speicher beim Aufruf von f_0995c0 nicht aus, verdrängt die Schleife über f_099910 fortlaufend den
 *   jeweils ältesten Cache-Eintrag, bis das Laden gelingt.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1, den Ressourcenschlüssel k (struct KEY)
 *   sowie den Zielslot p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable e bezeichnet die Adresse des Image1050-Eintrags (p1 + 4 + slot * 39), und
 *   owner (I(p1)) ist der zugehörige Archiv-Verwalter.
 === Ende Beschreibung === */
void f_099860(int p1, struct KEY k, int p3)
{
  int slot = 0;
  slot = p3;
  int base = p1 + 4;
  int e;
  int owner;
  for (;;) {
    e = (short)slot * 39;
    unsigned kb = *(unsigned *)&k;
    e += base;
    owner = I(p1);
    I(e+4) = 0;
    I(e+8) = 0;
    S(e+0x20) = 0;
    S(e+0xc) = 0;
    I(e+0xe) = 0;
    I(e+0x12) = 0;
    S(e+0x16) = 0;
    I(e+0x18) = 0;
    I(e+0x1c) = 0;
    I(e) = owner;
    if (f_0995c0(e, *(struct KEY *)&kb)) break;
    f_099910(p1);
  }
}
//@ f_0998e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den einzelnen Cache-Slot mit dem Index p2 über f_099560 frei und setzt dessen
 *   Alterungspriorität auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 sowie den Slot-Index p2 und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Der Offset des Eintrags berechnet sich als (short)p2 * 0x27.
 === Ende Beschreibung === */
void f_0998e0(int p1, int p2)
{
  f_099560(p1 + 4 + (short)p2 * 0x27);
  B((short)p2 * 0x27 + 0x26 + p1) = 0;
}
