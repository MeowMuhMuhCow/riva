/* === Beschreibung (Katalog) ===
 * Einheit gfx_t2a (098a90-099820)
 *
 * Überblick
 * Diese Einheit enthält im ersten Teil den Abschluss des Charaktergenerators (Speichern eines generierten Helden
 * auf Festplatte sowie das Porträtauswahlfenster) und im zweiten Teil die Grundfunktionen des Grafik- und
 * Animations-Caches (Image1050 / Cache1050), der komprimierte Einzelbildsequenzen aus den Spielearchiven im
 * EMS-/XMS- oder konventionellen Speicher verwaltet.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 14/17 gleich (suche.py 30.10.2026, Basis gfx_t2a_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// #pragma inline_depth(0)
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
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
                                         // reg - stapel 0
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
extern volatile int d_1bf514; // haelt das Schreiben auf d_1bf514 wie im Original                    // 0x1BF514
                    // 0x1C2098
extern int d_1c2198;                    // 0x1C2198
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c29f0;                    // 0x1C29F0
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a34c4[];           // Text 0x1A34C4
extern const char d_1a9680[];           // Text 0x1A9680


// #pragma inline_depth(0)
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
short f_0990b0(int p1, short p2, short p3);
void f_099560(int p1);
int f_099910(int p1);
//@ f_098a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im Charaktergenerator, ob der Held bereits einen Typus und einen Namen besitzt, warnt
 *   gegebenenfalls vor noch offenen Talent- oder Zaubersteigerungen (mit Option auf automatische Verteilung über
 *   f_094c70) und speichert den fertigen Helden nach Bestätigung in den Charakterarchiven 0x90001 und 0x90002.
 *   Falls sich ein gleichnamiger Held bereits in der aktiven Gruppe (d_1bc8f0) befindet, wird dessen Datensatz
 *   direkt aktualisiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generatorzeiger p1 und gibt 1 zurück, wenn der Held
 *   erfolgreich gespeichert wurde, andernfalls 0 (unsigned short).
 * - Wichtige Variablen: Das Feld I(p1 + 0xdf) zeigt auf den Heldenpuffer, I(p1 + 0x24) vermerkt, dass der Held
 *   gespeichert wurde, d_1c21b4 puffert den Heldennamen für die Archivsuche (f_0b0a00) und d_1bc8f0 ist das
 *   Gruppenarray der sechs Heldenplätze zu je 0x5ef Bytes.
 === Ende Beschreibung === */
#include <string.h>
#pragma intrinsic(strcpy)
int f_0937e0(int p1);
int f_094c70(int p1);







int f_043e20(int p1, int p2);
#pragma aux f_098a90 parm [eax] modify exact [];
unsigned short f_098a90(int p1)
{
  int f_042240_ebx(int, int);
  #pragma aux f_042240_ebx "f_042240" parm [eax] [edx] modify [ebx]
  short i;
  signed char buf;
  short ok;
  short r;
  short old;
  int q;
  unsigned char c;
  c = ((char)(f_042350((struct hero *)(I(p1+0xdf)))));
  ok = 0;
  r = 0;
  if (!c) {
    f_0bf730((int)&d_1c2c64, 0xe140015);
    f_098730(p1);
    c = ((char)(f_042350((struct hero *)(I(p1+0xdf)))));
    if (!c)
      return c;
  }
  if (!*f_0422b0((struct hero *)(I(p1+0xdf)))) {
    f_0bf730((int)&d_1c2c64, 0xe14002c);
    f_0937e0(p1);
    if (!*f_0422b0((struct hero *)(I(p1+0xdf))))
      return 0;
  }
  if (f_0bf6f0((int)&d_1c2c64, 0xe140001) == 1) {
    if ((((char)(f_0432f0((struct hero *)(I(p1+0xdf))))) > 0 && f_042a10((struct hero *)(I(p1+0xdf)))) || ((char)(f_043340((struct hero *)(I(p1+0xdf))))) > 0) {
      old = f_0c0020((int)&d_1c2c64, 5);
      r = f_0bf820((int)&d_1c2c64, 0xe140043, 3, 0xe140046, 0xe140047, 0xe140048);
      f_0c0020((int)&d_1c2c64, old);
      if (r == -1 || r == 3) {
        r = 1;
      } else {
        if (r == 1)
          f_094c70(p1);
        r = 0;
      }
    }
    if (!r) {
      f_0421f0((char *)(I(p1+0xdf)),(char *)( (int)d_1a9680));
      f_042220((struct hero *)(I(p1+0xdf)), d_1c2a50);
      f_042230((struct hero *)(I(p1+0xdf)), d_1a9693);
      f_042240_ebx(I(p1+0xdf), d_1a9692);
      f_042250((struct hero *)(I(p1+0xdf)), d_1a9694);
      ok = 1;
      f_0429e0((struct hero *)(I(p1+0xdf)), 1);
      if (f_0b0a00((int)strcpy(d_1c21b4, f_042320((struct hero *)(I(p1+0xdf)))), (int)&buf, 0x90001)) {
        if (f_0bf6f0((int)&d_1c2c64, 0xe140036) == 0)
          ok = 0;
      }
      if (ok) {
        f_043e20(I(p1+0xdf), 0);
        f_0d2f90(5, 1);
        f_0b0e20(I(p1+0xdf), 0x90001);
        if (f_0b0a00((int)d_1c21b4, (int)&buf, 0x90002))
          f_0b0e20(I(p1+0xdf), 0x90002);
        i = 0;
        q = d_1bc8f0;
        for (; (short)i < 6; i++, q += 0x5ef) {
          if (((char)(f_042350((struct hero *)(q))))) {
            int t_249 = f_144bf0(f_042320((struct hero *)(I(p1+0xdf))), f_042320((struct hero *)(q)));
            if (t_249 == 0)
              *(RECB*)q = *(RECB*)I(p1+0xdf);
          }
        }
        f_0d2e70();
        I(p1+0x24) = 1;
        f_043e20(I(p1+0xdf), 1);
      }
    }
  }
  return ok;
}
//@ f_098d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das Heldenporträt mit dem Index p3 aus dem Bildarchiv 0xe0011 sowie die zugehörige
 *   32-Farben-Palette (0x60 Bytes) aus dem Palettenarchiv 0xe0012, aktiviert die Palette über f_099ef0 und
 *   zeichnet das Porträt an die Position (8, 8) in den Zielpuffer p2.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generatorzeiger p1, den Zielbildpuffer p2 sowie den
 *   Porträtindex p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld I(p1 + 0x10) zeigt auf den Palettenpuffer des Generators, I(p1 + 0x117) ist das
 *   RivaRasterImage-Objekt des Porträts und d_1c2098 ist der globale Dateimanager.
 === Ende Beschreibung === */
void f_098d90(int p1, int p2, int p3)
{
  short p5;
  int b;
  p5 = p3;
  ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0xe0012, 0x200);
  ((RivaFileManager*)((int)&d_1c2098))->f_144ab0( p5 * 0x60, 0);
  ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( I(p1+0x10)), 0x60)));
  ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
  f_04feb0((int)&d_1c2be0, 0xe0011, ((int)(((RivaRasterImage*)(I(p1+0x117)))->f_0fb0b0())), 0, p5, 3, p1+0x22, p1+0x22, 0x140);
  b = 0;
  if (p2 == d_1a34e0) {
    if (f_0d3860() == 1) {
      b = 1;
      f_0d2710();
    }
  }
  f_099ef0(I(p1+0x10), 0, 0x20);
  ((RivaRasterImage*)(I(p1+0x117)))->f_0fade0((void *)( p2), 8, 8);
  if (b == 1) f_0d26e0();
}
//@ f_098e60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt für das Porträtauswahlfenster p2 aufeinanderfolgende Heldenporträts ab dem Startindex p3
 *   aus dem Archiv 0xe0015, versieht jedes Porträt mit einem dreidimensionalen Rahmen (f_1481a0) und kopiert es
 *   auf 28 x 28 Pixel beschnitten in den Bildschirmpuffer d_1a34e0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dialogzeiger p1, die Anzahl der darzustellenden Porträts p2
 *   (short) sowie den ersten Porträtindex p3 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokalen Puffer buf1 (28 x 28 Pixel) und buf2 (32 x 32 Pixel) dienen als temporäre
 *   RivaRasterImage-Objekte zum Beschneiden der geladenen Porträts.
 === Ende Beschreibung === */
void f_098e60(int p1, short p2, short p3)
{
  union View1155 { int full; short word; unsigned short uword; unsigned char bytes[4]; };
  char buf2[12];
  char buf1[12];
  int out;
  short i;
  short x;
  short y;
  ((int)(((RivaRasterImage*)((int)buf1))->f_0fac80( 0x1c, 0x1c)));
  ((int)(((RivaRasterImage*)((int)buf2))->f_0fac80( 0x20, 0x20)));
  View1155 left1155;
  left1155.full = S(p1+0x16);
  View1155 height1155;
  height1155.full = S(p1+0x2a);
  int view_left1155_2_0 = left1155.uword; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  int view_height1155_1_1 = height1155.bytes[1]; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  int view_left1155_1_0 = left1155.bytes[0]; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  int view_left1155_1_1 = left1155.bytes[1]; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  int p3_low1155 = (unsigned char)p3; // haelt die Byte-Sicht von p3 wie im Original
  int view_height1155_1_0 = height1155.bytes[0]; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  int view_height1155_2_0 = height1155.uword; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  View1155 raw_y1155;
  raw_y1155.full = left1155.full + ((height1155.full - 0x1c) >> 1);
  int view_raw_y1155_1_1 = raw_y1155.bytes[1]; // haelt die Register- und Stapelzuteilung der Unteransichten wie im Original
  y = raw_y1155.word;
  for (i = 0; i < (short)p2; i++) {
    x = (i & 0) ? (short)0 : (short)(S(p1+0x14) + ((S(p1+0x26) - p2 * 0x1e) >> 1) + i * 0x1e); // haelt die Registerzuteilung in der Schleife wie im Original
    f_04feb0((int)&d_1c2be0, 0xe0015, ((int)(((RivaRasterImage*)((int)buf2))->f_0fb0b0())), 0,
              (short)(p3 + i), 0, (int)&out, (int)&out, 0x140);
    f_1481a0((int)&d_1bdbd4, d_1a34e0, (short)x, y, 0x1e, 0x1e, -3);
    ((RivaRasterImage*)((int)buf2))->f_0fb0c0((RivaRasterImage *)( (int)buf1));
    ((RivaRasterImage*)((int)buf1))->f_0fade0((void *)( d_1a34e0), (short)(x + 1), (short)(y + 1));
  }
  f_149d20();
  ((int)(((RivaRasterImage*)((int)buf2))->f_0fad20( 0)));
  ((int)(((RivaRasterImage*)((int)buf1))->f_0fad20( 0)));
}
//@ f_098ff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Fenstergröße für die Porträtauswahl anhand der Porträtanzahl p2, öffnet das
 *   Dialogfenster, zeichnet die Porträtreihe über f_098e60, führt die interaktive Auswahl über f_0990b0 aus und
 *   schließt das Fenster anschließend wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dialogzeiger p1, die Anzahl der Porträts p2 sowie den
 *   Startindex p3 (short) und gibt den ausgewählten Porträtindex oder -1 bei Abbruch zurück (short).
 * - Wichtige Variablen: Die Strukturfelder S(p1 + 0x14), S(p1 + 0x16), S(p1 + 0x26) und S(p1 + 0x2a) speichern
 *   die Position und Abmessungen des Dialogfensters.
 === Ende Beschreibung === */
short f_098ff0(int p1, int p2, short p3)
{
    volatile int locked; // haelt den Stapelplatz fuer locked wie im Original
    short old_size, dimension;
    short r;
    S(p1 + 0x1c) = 1;
    old_size = S(p1 + 0x12);
    S(p1 + 0x12) = (short)((short)p2 * 30 / 32);
    if (S(p1 + 0x12) > 8) S(p1 + 0x12) = 8;
    f_05e2a0((int)&d_1c38b0, p1 + 0x3a, p1 + 0x3c, p1 + 0x3e, p1 + 0x40);
    S(p1 + 0x28) = 4;
    dimension = S(p1 + 0x28) * 8 + 30;
    S(p1 + 0x2a) = dimension;
    S(p1 + 0x16) = f_0e39e0(p1, dimension);
    dimension = (S(p1 + 0x12) + 2) * 32;
    S(p1 + 0x26) = dimension;
    S(p1 + 0x14) = f_0e3970(p1, dimension);
    if (f_0d3860() == 1) { f_0d2710(); locked = 1; }
    else locked = 0;
    f_0e3580(p1, S(p1 + 0x28));
    f_098e60(p1, (short)p2, p3);
    if (locked == 1) f_0d26e0();
    r = f_0990b0(p1, (short)p2, p3);
    S(p1 + 0x12) = old_size;
    f_0e4650(p1);
    S(p1 + 0x1c) = 0;
    return r;
}

//@ f_098fe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet den Aufruf zur Porträtauswahl unverändert an die Hauptfunktion f_098ff0 weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dialogzeiger p1, die Porträtanzahl p2 (short) sowie den
 *   Startindex p3 (short) und gibt den gewählten Porträtindex zurück (short).
 * - Wichtige Variablen: Es werden ausschließlich die übergebenen Parameter an f_098ff0 durchgereicht.
 === Ende Beschreibung === */
short f_098fe0(int p1, short p2, short p3)
{
  return f_098ff0(p1, p2, p3);
}

//@ f_098ff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Fenstergröße für die Porträtauswahl anhand der Porträtanzahl p2, öffnet das
 *   Dialogfenster, zeichnet die Porträtreihe über f_098e60, führt die interaktive Auswahl über f_0990b0 aus und
 *   schließt das Fenster anschließend wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dialogzeiger p1, die Anzahl der Porträts p2 sowie den
 *   Startindex p3 (short) und gibt den ausgewählten Porträtindex oder -1 bei Abbruch zurück (short).
 * - Wichtige Variablen: Die Strukturfelder S(p1 + 0x14), S(p1 + 0x16), S(p1 + 0x26) und S(p1 + 0x2a) speichern
 *   die Position und Abmessungen des Dialogfensters.
 === Ende Beschreibung === */
//@ f_0990b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Eingabeschleife des Porträtauswahlfensters aus, in der der Spieler mit den
 *   Pfeiltasten oder der Maus zwischen den angezeigten Porträts wechseln, das Fenster verschieben und mit
 *   Eingabetaste oder Mausklick ein Porträt bestätigen kann. Das jeweils aktive Porträt wird durch einen
 *   hervorgehobenen Rahmen (-4 statt -3) markiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dialogzeiger p1, die Anzahl der Porträts p2 (short) sowie den
 *   Basisindex p3 (short) und gibt den gewählten Porträtindex (p3 + sel) oder -1 bei Abbruch zurück (short).
 * - Wichtige Variablen: Das globale Klickbereichs-Array d_1a64fc speichert die Mausrechtecke der einzelnen
 *   Porträts, sel und old_sel verwalten die aktuelle Auswahl und d_1bd766 enthält den letzten Tastencode.
 === Ende Beschreibung === */
#pragma inline_depth(255)
struct R_990b0 { short x1, y1, x2, y2, id; };

#define RA ((R_990b0 *)d_1a64fc)
short f_0990b0(int p1, short p2, short p3)
{
    short idx;
    short y;
    short sel;
    short old_sel;
    int done;
    short r;
    int fl;
    short i;
    short x1;
    short x2;
    f_0d3870();
    f_0d5b50(0);
    sel = 0;
    old_sel = -1;
    done = 0;
    fl = 1;
    do {
        if (fl) {
            fl = 0;
            idx = 0;
            RA[idx].x1 = S(p1 + 0x14);
            RA[idx].x2 = S(p1 + 0x14) + S(p1 + 0x26);
            RA[idx].y1 = S(p1 + 0x16);
            RA[idx++].y2 = S(p1 + 0x16) + 0xf;
            y = S(p1 + 0x16) + ((S(p1 + 0x2a) - 0x1c) >> 1);
            for (i = 0; i < p2; i++) {
                x1 = S(p1 + 0x14) + ((S(p1 + 0x26) - p2 * 0x1e) >> 1) + i * 0x1e;
                x2 = x1 + 0x1d;
                RA[idx].x1 = x1;
                RA[idx].x2 = x2;
                RA[idx].y1 = y;
                RA[idx].y2 = RA[idx].y1 + 0x1e;
                idx++;
            }
            RA[idx].x1 = 0;
            RA[idx].x2 = 0xc7;
            RA[idx].y1 = 0;
            RA[idx].y2 = 0x13f;
        }
        if (f_0d3810()) {
            i = p2;
            while (*(volatile short *)&d_1bf4f0 /* haelt das erneute Lesen von d_1bf4f0 in der Schleife wie im Original */ < (int)RA[i].x1 && i > 0) {
                i--;
            }
            sel = i - 1;
            if (sel < 0)
                sel = 0;
        }
        if (d_1bd766 == 0x4d00) {
            sel++;
            if (sel == p2)
                sel = 0;
        } else if (d_1bd766 == 0x4b00) {
            sel--;
            if (sel == -1)
                sel = p2 - 1;
        }
        if (sel != old_sel) {
            RivaMouseGuard mg1;
            if (old_sel != -1) {
                f_1481a0((int)&d_1bdbd4, d_1a34e0, RA[old_sel + 1].x1, RA[old_sel + 1].y1, 0x1e, 0x1e, -3);
            }
            f_1481a0((int)&d_1bdbd4, d_1a34e0, RA[sel + 1].x1, RA[sel + 1].y1, 0x1e, 0x1e, -4);
            old_sel = sel;
        }
        if (d_1bd766 == 1 || d_1bd760 != (short)0) {
            if (!f_0d3790() || d_1bd760 != (short)0) {
                f_0e3ba0(p1, S(p1 + 0x14), S(p1 + 0x16), S(p1 + 0x26), S(p1 + 0x2a));
                if (S(p1 + 0x18) != S(p1 + 0x14) || S(p1 + 0x1a) != S(p1 + 0x16)) {
                    {
                        RivaMouseGuard mg2;
                        f_0e3430(p1);
                        S(p1 + 0x14) = S(p1 + 0x18);
                        S(p1 + 0x16) = S(p1 + 0x1a);
                        f_0e3580(p1, S(p1 + 0x28));
                        f_098e60(p1, p2, p3);
                        old_sel = -1;
                        fl = 1;
                    }
                }
            }
            f_0d3870();
        }
        if (d_1bd766 == 0x1c0d || f_0d3780()) {
            r = p3 + sel;
            done = 1;
        }
        if (d_1bd762 == 0x4900 || d_1bd762 == 0x5100 || f_0d37b0() || d_1bd766 == 0x11b) {
            done = 1;
            r = -1;
        }
        *(int *)&d_1bf514 = (int)d_1a64fc;
        f_0e4370(p1);
        *(int *)&d_1bf514 = 0;
    } while (!done);
    f_0d5b50(0);
    RA[1].x1 = 0;
    RA[1].x2 = 0xc7;
    RA[1].y1 = 0;
    RA[1].y2 = 0x13f;
    RA[1].id = 2;
    return r;
}
#undef RA
// #pragma inline_depth(0)

//@ f_0994a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die feste Bildschirmbreite von 320 Pixeln (0x140) zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt den konstanten Wert 0x140 zurück
 *   (int).
 * - Wichtige Variablen: Die Funktion verwendet keine lokalen oder globalen Variablen.
 === Ende Beschreibung === */
int f_0994a0()
{
  return 0x140;
}
//@ f_0994b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert einen einzelnen Bildsequenz-Eintrag (Image1050) im Grafik-Cache, indem alle
 *   Zeiger, Speicherhandles und Bildzähler auf 0 gesetzt werden.
 * - Eingaben und Rückgabe: Die Funktion erhält die Adresse p1 des Bildsequenz-Eintrags und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Felder I(p1 + 4) und I(p1 + 8) speichern die Zeiger auf die Pixeldaten und die
 *   Einzelbild-Offsettabelle, während S(p1 + 0xc) und S(p1 + 0x16) die zugehörigen Speicherblock-Handles halten.
 === Ende Beschreibung === */
static int a;
void f_0994b0(int p1)
{
  I(p1) = 0;
  I(p1+4) = 0;
  I(p1+8) = 0;
  S(p1+0x20) = 0;
  S(p1+0xc) = 0;
  I(p1+0xe) = 0;
  I(p1+0x12) = 0;
  S(p1+0x16) = 0;
  I(p1+0x18) = 0;
  I(p1+0x1c) = 0;
}

//@ f_099500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung:wirkt als Destruktor eines Bildsequenz-Eintrags, indem die Funktion die belegten Speicherblöcke
 *   über f_099560 freigibt und den Objektzeiger zurückliefert.
 * - Eingaben und Rückgabe: Die Funktion erhält die Adresse p1 des Eintrags sowie ein ungenutztes Flag kp2 und
 *   gibt p1 zurück (int).
 * - Wichtige Variablen: Die Freigabe erfolgt vollständig über f_099560.
 === Ende Beschreibung === */
int f_099500(int p1, int kp2)
{
  f_099560(p1);
  return p1;
}
//@ f_099510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert einen Bildsequenz-Eintrag mit dem übergebenen Archiv-Verwalter p3 und lädt
 *   unmittelbar die durch den Schlüssel k bezeichnete Bildsequenz über f_0995c0 in den Speicher.
 * - Eingaben und Rückgabe: Die Funktion erhält die Eintragsadresse p1, den 32-Bit-Ressourcenschlüssel k (struct
 *   KEY) sowie den Archivzeiger p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld I(p1) speichert den Verweis auf das Archiv-Objekt p3.
 === Ende Beschreibung === */
void f_099510(int p1, struct KEY k, int p3)
{
  I(p1+4) = 0;
  I(p1+8) = 0;
  S(p1+0x20) = 0;
  S(p1+0xc) = 0;
  I(p1+0xe) = 0;
  I(p1+0x12) = 0;
  S(p1+0x16) = 0;
  I(p1+0x18) = 0;
  I(p1+0x1c) = 0;
  I(p1) = p3;
  f_0995c0(p1, k);
}
//@ f_099560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die beiden über den internen Speichermanager (f_05fe40) reservierten Speicherblöcke für
 *   die Pixeldaten (W(p1 + 0xc)) und das Einzelbild-Zeigerarray (W(p1 + 0x16)) eines Bildsequenz-Eintrags frei
 *   und setzt alle zugehörigen Felder auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Adresse p1 des Bildsequenz-Eintrags und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die 16-Bit-Handles W(p1 + 0xc) und W(p1 + 0x16) identifizieren die beiden im
 *   Cache-Speicher angelegten Blöcke.
 === Ende Beschreibung === */
void f_099560(int p1)
{
  if (W(p1+0xc) != 0) {
    f_05fe40(W(p1+0xc));
    W(p1+0xc) = 0;
    I(p1+0xe) = 0;
    I(p1+0x12) = 0;
    I(p1+4) = 0;
  }
  if (W(p1+0x16) != 0) {
    f_05fe40(W(p1+0x16));
    W(p1+0x16) = 0;
    I(p1+0x18) = 0;
    I(p1+0x1c) = 0;
    I(p1+8) = 0;
  }
}
//@ f_0995c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet im zugehörigen Archiv den Eintrag mit dem Schlüssel k, liest den 26-Byte-Kopfsatz aus,
 *   reserviert bei ausreichendem freiem Speicher (f_05fd00) die Puffer für die Daten und die Einzelbild-Zeiger,
 *   liest den gesamten Datenstrom ein und baut anhand der Nullbytes (unter Überspringen von
 *   4-Byte-Escape-Sequenzen ab 0x1b) das Zeigerarray auf die einzelnen Teilbilder auf.
 * - Eingaben und Rückgabe: Die Funktion erhält die Eintragsadresse p1 sowie den Ressourcenschlüssel k (struct
 *   KEY) und gibt 1 bei Erfolg oder 0 bei Speichermangel zurück (int).
 * - Wichtige Variablen: Das Feld S(p1 + 0x20) speichert die aus dem Header gelesene Anzahl der Teilbilder, I(p1
 *   + 4) zeigt auf den geladenen Datenpuffer und I(p1 + 8) zeigt auf das Array der Teilbild-Startadressen.
 === Ende Beschreibung === */
int f_0995c0(int p1, struct KEY k)
{
  short tmp;
  short buf[13];
  int r;
  int len;
  int key = k.b | (k.a << 16);
  r = 1;
  if (((FN3)VSL(I(p1),0x14))(I(p1), key, 0x200) == 1) {
    ((FN3)VSL(I(p1),0x20))(I(p1), (int)buf, 0x1a);
    S(p1+0x20) = *(int*)((char*)buf + 8);
    len = ((FN1)VSL(I(p1),0x30))(I(p1)) - 0x1a;
    if ((unsigned)f_05fd00() < (unsigned)(len + S(p1+0x20) * 4 + 0xc800)) {
      ((FN1)VSL(I(p1),0x28))(I(p1));
      r = 0;
    } else {
      int off;
      f_05fd70((unsigned short)len, p1 + 0xc, (int)&tmp);
      I(p1+4) = I(p1+0x12);
      f_05fd70((unsigned short)(W(p1+0x20) << 2), p1 + 0x16, (int)&tmp);
      I(p1+8) = I(p1+0x1c);
      ((FN3)VSL(I(p1),0x40))(I(p1), 0x1a, 0);
      off = 0;
      for (; len > 0; ) {
        int n = ((FN3)VSL(I(p1),0x20))(I(p1), I(p1+4) + off, len);
        len -= n;
        off += n;
      }
      ((FN1)VSL(I(p1),0x28))(I(p1));
      {
        int *q = (int*)I(p1+8);
        signed char *ptr = (signed char*)I(p1+4);
        unsigned short i;
        unsigned short cnt = W(p1+0x20);
        *q++ = (int)ptr;
        i = 1;
        if (i < cnt) {
          do {
            if (*ptr == 0x1b) ptr += 4;
            if (!*ptr) {
              *q++ = (int)(ptr + 1);
              i++;
            }
            ptr++;
          } while (i < cnt);
        }
      }
    }
  }
  return r;
}
//@ f_099700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft einen geladenen Animations- oder Textdatenpuffer p3 und trägt die Startadressen von
 *   p4 aufeinanderfolgenden, durch Nullbytes getrennten Einträgen (wobei 0x1b-Steuersequenzen von 4 Bytes
 *   übersprungen werden) in das Zeigerarray p2 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1, das Ziel-Zeigerarray p2, den Datenpuffer p3
 *   sowie die Eintragsanzahl p4 (unsigned short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zeiger piVar2 läuft durch das Ausgabearray p2, während uVar1 die bereits gefundenen
 *   Teilblöcke zählt.
 === Ende Beschreibung === */
void f_099700(int p1, int *p2, char *p3, unsigned short p4)
{
  unsigned short uVar1;
  int *piVar2;
  uVar1 = 1;
  *p2 = (int)p3;
  piVar2 = p2 + 1;
  while (uVar1 < p4) {
    if ((signed char)*p3 == 0x1b) p3 = p3 + 4;
    if (!*p3) {
      *piVar2++ = (int)(p3 + 1);
      uVar1 = uVar1 + 1;
    }
    p3 = p3 + 1;
  }
}
//@ f_099740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt aus dem Zeigerarray I(p1 + 8) eines geladenen Bildsequenz-Eintrags die Startadresse des
 *   Teilbildes zurück, dessen Index im oberen 16-Bit-Wort von p2 (p2 >> 16) übergeben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Eintragsadresse p1 sowie den gepackten Teilbildindex p2
 *   (unsigned) und gibt die Speicheradresse des Teilbildes zurück (int).
 * - Wichtige Variablen: Das Feld I(p1 + 8) verweist auf die beim Laden erzeugte Tabelle der Teilbildadressen.
 === Ende Beschreibung === */
int f_099740(int p1, unsigned p2)
{
  return I(I(p1+8) + (p2 >> 0x10) * 4);
}
//@ f_099750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert einen Grafik-Cache (Cache1050) mit 25 Einträgen zu je 39 Bytes (0x27), indem die
 *   Array-Konstruktor-Hilfsfunktion f_147c84 aufgerufen, der Archivzeiger p2 eingetragen und die
 *   Alterungs-Prioritäten (B(base + s * 0x27 + 0x26)) aller 25 Slots auf 0 gesetzt werden.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 sowie den Archivzeiger p2 und gibt die
 *   initialisierte Cache-Adresse (als short gekürzt in AX/EAX) zurück.
 * - Wichtige Variablen: Das Array ab p1 + 4 umfasst 25 Record1050-Einträge der Größe 0x27 Bytes mit der
 *   Alterungspriorität an Offset 0x26.
 === Ende Beschreibung === */
short f_099750(int p1, int p2)
{
  short s;
  int base;
  p1 = f_147c84(p1+4, 0x19, (int)&d_1baf74) - 4;
  base = p1;
  I(p1) = p2;
  for (s = 0; s < 0x19; s++) {
    B(s * 0x27 + 0x26 + base) = 0;
  }
  return p1;
}
//@ f_0997a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt in allen 25 Einträgen eines Grafik-Caches die Alterungs-Priorität an Offset 0x26 auf 0
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Schleifenvariable s durchläuft alle 25 Cache-Slots (0 bis 0x18).
 === Ende Beschreibung === */
void f_0997a0(int p1)
{
  short s;
  for (s = 0; s < 0x19; s++) {
    B(s * 0x27 + 0x26 + p1) = 0;
  }
}
//@ f_0997d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des 25-teiligen Grafik-Caches, gibt für jeden belegten Slot (I(iVar2 + 8)
 *   != 0) die reservierten Speicherblöcke über f_099560 frei und zerstört anschließend das Array der 25 Einträge
 *   über f_156870.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 sowie einen ungenutzten Parameter p2_unused
 *   und gibt die Basisadresse p1 zurück (int).
 * - Wichtige Variablen: Die Struktur d_1baf74 beschreibt den Elementtyp für den Watcom-Array-Destruktor
 *   f_156870.
 === Ende Beschreibung === */
int f_0997d0(int p1, int p2_unused)
{
  int iVar1, iVar2;
  int q;
  int p2 = p1;
  LI s = 0;
  q = p1 + 4;
  for (; SV(s) < 0x19; s++) {
    iVar1 = SV(s) * 0x27;
    iVar2 = p2 + iVar1;
    if (I(iVar2+8) != 0) {
      f_099560(q + iVar1);
      B(iVar2+0x26) = 0;
    }
  }
  iVar2 = f_156870(p1+4, 0x19, (int)&d_1baf74);
  return iVar2 - 4;
}
