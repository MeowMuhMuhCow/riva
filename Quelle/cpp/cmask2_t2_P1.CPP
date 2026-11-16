/* === Beschreibung (Katalog) ===
 * Einheit cmask2_t2 (0x04cbc0 - 0x04d730)
 *
 * Überblick
 * Die Einheit cmask2_t2 bildet den zweiten Teil der Darstellung des Charakterblatts (cmask2): Sie zeichnet die
 * Kampfwerte-Seite (alle sieben Nahkampftalente mit AT/PA, die aktuellen Waffen-Kampfwerte sowie Schuss- und
 * Wurfwaffen), die beiden Zauber-Übersichtsseiten (alle 12 Zauberschulen/-gebiete mit ihren Sprüchen), die 31
 * Inventar- und Ausrüstungsplätze samt Stapelzahlen und "Zerbrochen"-Symbol sowie die 15 am Körper getragenen
 * Gegenstände auf der Silhouetten-Grafik.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 3/6 gleich (suche.py 25.10.2026, Basis cmask2_t2_P1.CPP)
// cmask2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04B770-0x04D730
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036ee0(int p1, int p2);                           // reg eax edx stapel 0
int f_03aa20(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
signed char f_03ad80(int p1, int p2);
int f_03d790(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0

                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0



                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_0437b0(int p1, int p2);                           // reg eax edx stapel 0
int f_043a10(int p1, int p2);                           // reg eax edx stapel 0
int f_045300(int p1);                                   // reg eax stapel 0
short f_045610(int p1);
short f_045660(int p1);
short f_0456e0(int p1, int p2);
short f_045710(int p1, int p2);
int f_046bc0(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_04b0d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_04b3a0(int p1);                                   // reg eax stapel 0
int f_04e340(int p1);                                   // reg eax stapel 0
int f_04ed90(int p1);                                   // reg eax stapel 0
int f_04ee60(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_098fe0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_09a040(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)

                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4ad0(int p1);                                   // reg eax stapel 0
int f_0d4b00(int p1);                                   // reg eax stapel 0
int f_0e4d80(int p1);                                   // reg eax stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
short f_0e95d0(int p1, int p2, int p3, int p4);
int f_0e9660(int p1, int p2, int p3, int p4);
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
short f_149360(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a0f46[];
extern short d_1a0f50[];
extern short d_1a0f52[];
extern int d_1a12e4;                    // 0x1A12E4
extern int d_1a12e8;                    // 0x1A12E8
extern int d_1a12ea;                    // 0x1A12EA
extern int d_1a130c;                    // 0x1A130C
extern int d_1a1310;                    // 0x1A1310
extern int d_1a1314;                    // 0x1A1314
extern int d_1a1316;                    // 0x1A1316
extern int d_1a1318;                    // 0x1A1318
extern int d_1a131c;                    // 0x1A131C
extern int d_1a131e;                    // 0x1A131E
struct T48e { short a, b, c; }; struct T48 { T48e e[8]; };
extern T48 d_1a1320;
struct T24 { T48e e[4]; };
extern T24 d_1a1350;
extern int d_1a13b4;                    // 0x1A13B4
extern int d_1a3204;                    // 0x1A3204
extern int d_1a3205;                    // 0x1A3205
extern int d_1a3210;                    // 0x1A3210
extern int d_1a34e0;                    // 0x1A34E0
extern signed char d_1a6ba0[];
extern signed char d_1a6ba1[];
extern signed char d_1a7734[];
extern signed char d_1a7735[];
extern signed char d_1a7744[];
extern signed char d_1a7745[];
extern char d_1bc8a0;                   // 0x1BC8A0
extern unsigned short d_1bc930;
extern int d_1bfaf0;                    // 0x1BFAF0
extern int d_1c2198;                    // 0x1C2198
extern int d_1c21b4;                    // 0x1C21B4
extern char d_1c27a8[][50];
extern int d_1c27da;                    // 0x1C27DA
extern int d_1c280c;                    // 0x1C280C
extern int d_1c283e;                    // 0x1C283E
extern unsigned d_1c29c4[7];
extern int d_1c2be0;                    // 0x1C2BE0
extern short d_1c2c40;                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3068;                    // 0x1C3068
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (13), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int f_04b770(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0e9690(int p1, int p2);
int f_148518(int p1, int p2, int p3);
void f_04ef70();

struct S {
 char a0[7]; char f07[4]; int f0b; char p1[0x1d-0x0f]; short f1d; char p2[1]; short f20; short f22;
 char p3[0xea-0x24]; int fea; char p4[0xf2-0xee]; int ff2; int ff6; int ffa; int ffe;
 char p5[0x112-0x102]; int f112; char p6[0x11e-0x116]; int f11e;
};
#define B1C38B0 ((int)&d_1c38b0)


//@ f_04cbc0  groesse 512 B, 135 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die rechte Textspalte der Kampfwerte-Seite (Seite 2) des Charakterblatts: Sie
 *   berechnet den Fernkampf-Basiswert (KL + FF + KK) / 4, formatiert für alle sieben Nahkampf-Waffengattungen (0
 *   bis 6) die Attacke- und Paradewerte (f_0456e0 / f_045710) und gibt diese zusammen mit dem AT/PA-Basiswert
 *   (f_042890), den aktuellen Waffenkampfwerten (f_045610 / f_045660) sowie den Gesamtwerten für Schusswaffen
 *   (Talent 7) und Wurfwaffen (Talent 8) über den Textblock 0x304001c aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Speichert die sieben formatierten Waffenzeilen in d_1c27a8 bzw. d_1c29c4 und gibt sie
 *   über d_1c38b0 aus.
 === Ende Beschreibung === */
struct O { char x[16]; unsigned *a; short *b; char y[0x3c-0x18]; };
void f_04cbc0(S *p)
{
 O o; int q; short i; int off;
 f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
 f_05e830(B1C38B0, 0x118, 0);
 f_05e830(B1C38B0, 300, 1);
 q = (f_042a40((struct hero *)(p->f0b), 1) + f_042a40((struct hero *)(p->f0b), 4) + f_042a40((struct hero *)(p->f0b), 6)) / 4;
 for (i = 0; i < 7; i++) {
  char *text = d_1c27a8[i]; o.a[1] = i + 0x2000005cU; o.b[1] = f_0456e0(p->f0b, i); o.b[2] = f_045710(p->f0b, i); f_0e93f0(B1C38B0, (int)text, 0x304001b); d_1c29c4[i] = f_133fe0((int)&d_1c3498, (int)text);
 }
 d_1c3498 = (d_1c3498 & 0) ? 0 : d_1c3498; // Haelt die Registerfolge nach der Schleife
 o.b[1] = f_042890((struct hero *)(p->f0b));
 o.a[1] = d_1c29c4[0];
 o.a[2] = d_1c29c4[1];
 o.a[3] = d_1c29c4[2];
 o.a[4] = d_1c29c4[3];
 o.a[5] = d_1c29c4[4];
 o.a[6] = d_1c29c4[5];
 o.a[7] = d_1c29c4[6];
 o.b[2] = f_045610(p->f0b);
 o.b[3] = f_045660(p->f0b);
 o.a[8] = 0x20000063;
 o.b[4] = (short)q + (short)f_03ad80(p->f0b, 7);
 o.a[9] = 0x20000064;
 o.b[5] = q + f_03ad80(p->f0b, 8);
 f_0e9510(B1C38B0, 0x304001c, 0xd7, 0x32);
 f_1254a0((int)&o, 0);
}

//@ f_04cdc0  groesse 16 B, 1 Bef, reg -, stapel ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet als kurzer Wrapper direkt auf die Hilfsfunktion f_04ef70 weiter.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Greift selbst auf keine Variablen zu.
 === Ende Beschreibung === */
void f_04cdc0()
{
 f_04ef70();
}

//@ f_04cdd0  groesse 544 B, 126 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die erste Zauber-Übersichtsseite (Seite 4) des Charakterblatts: Sie gibt die acht
 *   Überschriften der ersten acht Zaubergebiete (0x200000ee bis 0x200000f5: Antimagie, Beherrschung,
 *   Dämonologie, Elemente, Bewegung, Heilung, Hellsicht, Illusion) zentriert in ihren Spalten aus und listet
 *   darunter in einer Schleife über die Bereichstabellen d_1a7734/d_1a7735 und d_1a1320 alle zugehörigen
 *   Zaubersprüche samt Fertigkeitswert über f_04b770 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Spaltenkoordinaten d_1a1320 sowie die Start- und Längentabellen d_1a7734 und
 *   d_1a7735.
 === Ende Beschreibung === */
void f_04cdd0(S *p)
{
 T48 loc; short i; short j;
 loc = d_1a1320;
 f_05e320(B1C38B0, 0xf9, -1);
 i = f_0e95d0(B1C38B0, 0x200000ee, 5, 100);
 f_0e9510(B1C38B0, 0x200000ee, i, 40);
 i = f_0e95d0(B1C38B0, 0x200000f0, 110, 100);
 f_0e9510(B1C38B0, 0x200000f0, i, 40);
 i = f_0e95d0(B1C38B0, 0x200000f3, 215, 100);
 f_0e9510(B1C38B0, 0x200000f3, i, 40);
 i = f_0e95d0(B1C38B0, 0x200000ef, 5, 100);
 f_0e9510(B1C38B0, 0x200000ef, i, 97);
 i = f_0e95d0(B1C38B0, 0x200000f2, 110, 100);
 f_0e9510(B1C38B0, 0x200000f2, i, 97);
 i = f_0e95d0(B1C38B0, 0x200000f4, 215, 100);
 f_0e9510(B1C38B0, 0x200000f4, i, 97);
 i = f_0e95d0(B1C38B0, 0x200000f1, 110, 100);
 f_0e9510(B1C38B0, 0x200000f1, i, 159);
 i = f_0e95d0(B1C38B0, 0x200000f5, 215, 100);
 f_0e9510(B1C38B0, 0x200000f5, i, 159);
 f_05e320(B1C38B0, 0xff, -1);
 for (i = 0; i < 8; i++) {
  for (j = d_1a7734[i * 2]; j < d_1a7735[i * 2] + d_1a7734[i * 2]; j++) {
   f_04b770((int)p, j, d_1a7734[i * 2], loc.e[i].a, loc.e[i].b, loc.e[i].c);
  }
 }
}

//@ f_04cff0  groesse 352 B, 86 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die zweite Zauber-Übersichtsseite (Seite 5) des Charakterblatts: Sie gibt die vier
 *   Überschriften der verbleibenden Zaubergebiete (0x200000f6 bis 0x200000f9: Kampf, Verständigung, Verwandlung,
 *   Veränderung) aus und listet darunter anhand der Tabellen d_1a7744/d_1a7745 und d_1a1350 alle zugehörigen
 *   Zaubersprüche über f_04b770 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Spaltenkoordinaten d_1a1350 sowie die Start- und Längentabellen d_1a7744 und
 *   d_1a7745.
 === Ende Beschreibung === */
void f_04cff0(S *p)
{
 T24 loc; short i; short j; int n;
 loc = d_1a1350;
 f_05e320(B1C38B0, 0xf9, -1);
 i = f_0e95d0(B1C38B0, 0x200000f6, 5, 100);
 f_0e9510(B1C38B0, 0x200000f6, i, 40);
 i = f_0e95d0(B1C38B0, 0x200000f7, 5, 100);
 f_0e9510(B1C38B0, 0x200000f7, i, 120);
 i = f_0e95d0(B1C38B0, 0x200000f8, 110, 100);
 f_0e9510(B1C38B0, 0x200000f8, i, 40);
 i = f_0e95d0(B1C38B0, 0x200000f9, 215, 100);
 f_0e9510(B1C38B0, 0x200000f9, i, 40);
 f_05e320(B1C38B0, 0xff, -1);
 for (i = 0; i < 4; i++) {
  for (j = d_1a7744[i * 2]; j < ((n = d_1a7745[i * 2]), d_1a7744[i * 2] + n); j++) {
   f_04b770((int)p, j, d_1a7744[i * 2], loc.e[i].a, loc.e[i].b, loc.e[i].c);
  }
 }
}


//@ f_04d150  groesse 896 B, 240 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet alle sichtbaren Inventarslots (0 bis 30, wobei die Körperslots 0 bis 14 nur bei
 *   d_1bc930 == 1 gezeichnet werden) des Helden p->f0b auf den Bildschirm: Für belegte Slots wird das
 *   Gegenstands-Icon aus dem Archiv 0x50002 geladen, bei stapelbaren Gegenständen (f_0a7950) die Stückzahl
 *   rechts unten eingeblendet und bei zerbrochenen Gegenständen (f_042bb0 == 1) das "Zerbrochen"-Overlay (Icon
 *   1000) darübergelegt; leere Slots werden mit der Hintergrundfarbe gefüllt, und abschließend wird der
 *   Auswahlrahmen über f_04b0d0 gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Liest die Slot-Koordinaten aus d_1a0f50/d_1a0f52, die Gegenstandsdefinitionen aus
 *   d_1c2c40 und zeichnet auf den Bildschirm d_1a34e0.
 === Ende Beschreibung === */
void f_04d150(S *p)
{
 struct Guard {
  int on;
  Guard() { if (f_0d3860() == 1) { f_0d2710(); on = 1; } else on = 0; }
  ~Guard() { if (on == 1) f_0d26e0(); }
 } mg;
 int saved, frame, p7;
 short i;
 saved = ((int)(((RivaRasterImage*)(p->ff2))->f_0fb0b0()));
 ((RivaRasterImage*)(p->f112))->f_0fade0((void *)( d_1a34e0), 0, 0xc0);
 frame = f_05dec0((int)&d_1c3068);
 f_05ded0((int)&d_1c3068, d_1a34e0);
 p7 = (int)p + 7;
 for (i = 0; i <= 30; i++) {
  signed char mode;
  if ((i < 15 && ((mode = d_1bc930), mode) == 1) || i >= 15) {
  if (f_042a60((struct hero *)(p->f0b), i)) {
   if (f_149360(i, (int)d_1a0f46) != -1)
    ((RivaRasterImage*)(p->f112))->f_0fade0((void *)( d_1a34e0), 0, 0xc0);
   f_04feb0((int)&d_1c2be0, 0x50002, saved, 0,
    ((RivaItemDefinition*)((*(int **)&d_1c2c40)[f_042a60((struct hero *)(p->f0b), i)]))->f_0a7800(), 0, p7, p7, 0x140);
   ((RivaRasterImage*)(p->ff2))->f_0fade0((void *)( d_1a34e0),
    (short)(d_1a0f50[i * 2] + 1), (short)(d_1a0f52[i * 2] + 1));
   if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[f_042a60((struct hero *)(p->f0b), i)]))->f_0a7950()) {
    f_05e320(B1C38B0, 0xff, 0);
    f_148518(f_042ac0((struct hero *)(p->f0b), i), (int)&d_1c21b4, 10);
    f_0e9660(B1C38B0, (int)&d_1c21b4,
     (short)(d_1a0f50[i * 2] + 15 - f_0e9690(B1C38B0, (int)&d_1c21b4)),
     (short)(d_1a0f52[i * 2] + 8));
    f_05e320(B1C38B0, 0xff, -1);
   }
   if (f_042bb0((struct hero *)(p->f0b), i) == 1) {
    f_04feb0((int)&d_1c2be0, 0x50002, saved, 0, 1000, 0, p7, p7, 0x140);
    ((RivaRasterImage*)(p->ff2))->f_0fae30((void *)( d_1a34e0),
     (short)(d_1a0f50[i * 2] + 1), (short)(d_1a0f52[i * 2] + 1), 1);
   }
   if (f_149360(i, (int)d_1a0f46) != -1)
    ((RivaRasterImage*)(p->f112))->f_0fafb0((void *)( d_1a34e0), 0, 0xc0);
   f_04b0d0((int)p, d_1a34e0, i, 0);
  } else {
   if (f_149360(i, (int)d_1a0f46) != -1)
    ((RivaRasterImage*)(p->f112))->f_0fade0((void *)( d_1a34e0), 0, 0xc0);
   ((RivaRasterImage*)(p->ff2))->f_0fb150( (short)(i == 7 ? 0 : 0x98));
   ((RivaRasterImage*)(p->ff2))->f_0fade0((void *)( d_1a34e0),
    (short)(d_1a0f50[i * 2] + 1), (short)(d_1a0f52[i * 2] + 1));
   if (f_149360(i, (int)d_1a0f46) != -1)
    ((RivaRasterImage*)(p->f112))->f_0fafb0((void *)( d_1a34e0), 0, 0xc0);
   f_04b0d0((int)p, d_1a34e0, i, 0);
  }
  }
 }
 f_05ded0((int)&d_1c3068, frame);
}

extern int d_du1;
//@ f_04d4d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Körper-Ausrüstungsansicht (98x164 Pixel an Position 85, 34) samt allen 15 am
 *   Körper getragenen Gegenständen (Slots 0 bis 14), ihren Stückzahlen und eventuellen "Zerbrochen"-Markierungen
 *   in den Hintergrundpuffer p->f11e und sichert den fertigen Ausschnitt anschließend in das Teilbild p->ff6
 *   (als Vorbereitung für die Auf-/Zuroll-Animation der Pergamentrolle in gz_04d730).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (p) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Nutzt das Körper-Teilbild p->ff6, das Icon-Bild p->ff2 und den Hintergrundpuffer
 *   p->f11e.
 === Ende Beschreibung === */
#define TAB04(k) ((*(int **)&d_1c2c40)[k])
void f_04d4d0(S *p)
{
 int h, a, b; short i;
 f_04feb0((int)&d_1c2be0, 0x3000b, ((int)(((RivaRasterImage*)(p->ff6))->f_0fb0b0())), 0, 0, 0, (int)p->f07, (int)p->f07, 0x140);
 b = (int)p->f07;
 ((RivaRasterImage*)(p->ff6))->f_0fae30((void *)( p->f11e), 0x55, 0x22, 0);
 a = (int)p->f07;
 h = ((int)(((RivaRasterImage*)(p->ff2))->f_0fb0b0()));
 for (i = 0; i < 15; i++) {
  if (f_042a60((struct hero *)(p->f0b), i) != (short)0) {
   f_04feb0((int)&d_1c2be0, 0x50002, h, 0, (int)((RivaItemDefinition*)(TAB04(f_042a60((struct hero *)(p->f0b), i))))->f_0a7800(), 0, a, a, 0x140);
   ((RivaRasterImage*)(p->ff2))->f_0fb1a0( 0, -2);
   ((RivaRasterImage*)(p->ff2))->f_0fade0((void *)( p->f11e), (short)(d_1a0f50[i * 2] + 1), (short)(d_1a0f52[i * 2] + 1));
   if (((RivaItemDefinition*)(TAB04(f_042a60((struct hero *)(p->f0b), i))))->f_0a7950()) {
    f_05e320(B1C38B0, 0xff, 0xfe);
    f_148518(f_042ac0((struct hero *)(p->f0b), i), (int)&d_1c21b4, 10);
    f_0e9660(B1C38B0, (int)&d_1c21b4,
             (short)(d_1a0f50[i * 2] + 15 - f_0e9690(B1C38B0, (int)&d_1c21b4)),
             (short)(d_1a0f52[i * 2] + 8));
    f_05e320(B1C38B0, 0xff, -1);
   }
   if (f_042bb0((struct hero *)(p->f0b), i) == 1) {
    f_04feb0((int)&d_1c2be0, 0x50002, h, 0, 1000, 0, b, b, 0x140);
    ((RivaRasterImage*)(p->ff2))->f_0fae30((void *)( p->f11e), (short)(d_1a0f50[i * 2] + 1), (short)(d_1a0f52[i * 2] + 1), 1);
   }
  }
  f_04b0d0((int)p, p->f11e, i, 0);
 }
 ((RivaRasterImage*)(p->ff6))->f_0fafb0((void *)( p->f11e), 0x55, 0x22);
 if (d_du1 & 0) d_du1 = 0; // Haelt die Registerfolge am Funktionsende
}
