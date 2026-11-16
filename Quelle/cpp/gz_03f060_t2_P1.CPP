/* === Beschreibung (Katalog) ===
 * Einheit gz_03f060_t2 (0x03f240 - 0x03f2a0)
 *
 * Überblick
 * Dieser zweite Teil der Einheit gz_03f060 enthält zwei weitere kleine Konstruktoren für
 * Bildschirm-Deskriptorobjekte (f_03f240, f_03f270) sowie einen einfachen Byte-Getter (f_03f290).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P1 3/4 gleich (f_03f210 nur Fuellbytes: Original Nullen statt Nop, Modulgrenze)
// gz_03f060.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x03F060-0x03F2A0
#include <string.h>
extern int d_0a0000;
extern int d_1bacdc;
extern int d_1bacc4;
extern int d_1bacd0;

#include <string.h>
#include <stdio.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))
extern unsigned char d_1a34e0;
extern unsigned char d_1a965c;
extern unsigned char d_1a96a4;
extern unsigned char d_1b648c;
extern unsigned char d_1b6497;
extern unsigned char d_1b649f;
extern unsigned char d_1b64ac;
extern unsigned char d_1b64b8;
extern unsigned char d_1b64c4;
extern unsigned char d_1b64d0;
extern unsigned char d_1b64db;
extern unsigned char d_1b64e8;
extern unsigned char d_1b64f5;
extern unsigned char d_1b6501;
extern unsigned char d_1b650d;
extern unsigned char d_1b6519;
extern unsigned char d_1b6524;
extern unsigned char d_1bfb10;
extern unsigned char d_1c1110;

extern unsigned char d_1c21b4;
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C03ede0_1(int);
#pragma aux C03ede0_1 "f_03ede0" modify exact [eax];
void C059d60_3(int,int);
#pragma aux C059d60_3 "f_059d60" modify exact [eax edx];
void C099ef0_3(int,int,int);
#pragma aux C099ef0_3 "f_099ef0" parm caller [] modify exact [eax ecx edx];
int C09a0d0_1(int);
#pragma aux C09a0d0_1 "f_09a0d0" modify exact [eax];
void C09a400_0();
#pragma aux C09a400_0 "f_09a400" modify exact [eax];
void C0d26e0_0();
#pragma aux C0d26e0_0 "f_0d26e0" modify exact [eax];
void C0d2710_0();
#pragma aux C0d2710_0 "f_0d2710" modify exact [eax];
int C0d4730_1(int);
#pragma aux C0d4730_1 "f_0d4730" modify exact [eax];
void C0fad50_4(int,short,short,int);
#pragma aux C0fad50_4 "f_0fad50" modify exact [eax ebx ecx edx];
void C0fadc0_1(int);
#pragma aux C0fadc0_1 "f_0fadc0" modify exact [eax];
void C0fade0_4(int,int,short,short);
#pragma aux C0fade0_4 "f_0fade0" modify exact [eax ebx ecx edx];
int C1448b0_3(int,int,int);
#pragma aux C1448b0_3 "f_1448b0" modify exact [eax ebx edx];
void C1449a0_1(int);
#pragma aux C1449a0_1 "f_1449a0" modify exact [eax];
void C1459b0_1(int);
#pragma aux C1459b0_1 "f_1459b0";
int C1459d0_2(int,int);
#pragma aux C1459d0_2 "f_1459d0" modify exact [eax];
void C145a00_3(int,int);
#pragma aux C145a00_3 "f_145a00" modify exact [eax edx];
int C145b40_1(int);
#pragma aux C145b40_1 "f_145b40" modify exact [eax];
int C145b70_1(int);
#pragma aux C145b70_1 "f_145b70" modify exact [eax];
int C149336_1(int);
#pragma aux C149336_1 "f_149336" modify exact [eax];
int C149d20_0();
#pragma aux C149d20_0 "f_149d20" modify exact [eax];
int Cfmt494(char *, const char *, ...);
#pragma aux Cfmt494 "f_14572e" parm caller [] modify exact [eax];
#pragma aux f_03f060 parm [eax] [esi];
#pragma aux paint494 "W?f_03f060$n(pnxai)v" parm [eax] [esi] modify exact [eax];
#pragma aux f_03f170 modify exact [eax ebp edi];
#pragma aux sound492 "f_03ede0" modify exact [eax];
#pragma aux picture492 "f_03f060" modify exact [eax ebp edi];
#pragma aux start492 "f_0d2710" modify exact [eax];
#pragma aux finish492 "f_0d26e0" modify exact [eax];
#pragma aux present492 "f_09a400" modify exact [eax];
//@ f_03f240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion initialisiert ein Bildschirm-Deskriptorobjekt p1 für den
 *   Standard-VGA-Grafikmodus (Typ 1, Videospeicher 0xA0000, Methodentabelle d_1bacd0) mit der Breite p2 und der
 *   Höhe p3.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1, die Breite p2 und die Höhe p3 und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Im Gegensatz zu f_03f210 wird hier der Modus 1 und die 320x200-Methodentabelle d_1bacd0
 *   eingetragen.
 === Ende Beschreibung === */
void f_03f240(int p1, int p2, int p3)
{
  *(short *)p1 = 1;
  *(int *)(p1 + 6) = 0xA0000;
  *(int *)(p1 + 10) = (int)&d_1bacdc;
  *(short *)(p1 + 2) = (short)p2;
  *(short *)(p1 + 4) = (short)p3;
  *(int *)(p1 + 10) = (int)&d_1bacd0;
}
//@ f_03f270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dieser Basiskonstruktor initialisiert ein Bildschirm-Deskriptorobjekt p1 mit einem frei
 *   wählbaren Modustyp p2, der Breite p3, der Höhe p4, dem Bildspeicherzeiger p5 und der Basis-Methodentabelle
 *   d_1bacdc.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1, den Typ p2, die Breite p3, die Höhe p4 und
 *   die Pufferadresse p5 und gibt p1 zurück.
 * - Wichtige Variablen: Die Basistabelle d_1bacdc wird in abgeleiteten Konstruktoren (Scr0, Scr1 in chapter)
 *   anschließend durch d_1bacd0 bzw. d_1bacc4 überschrieben.
 === Ende Beschreibung === */
int f_03f270(int p1, int p2, int p3, int p4, int p5)
{
  *(int *)(p1 + 10) = (int)&d_1bacdc;
  *(short *)p1 = (short)p2;
  *(short *)(p1 + 2) = (short)p3;
  *(short *)(p1 + 4) = (short)p4;
  *(int *)(p1 + 6) = p5;
  return p1;
}
//@ f_03f290
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese kleine Hilfsfunktion liest das erste Byte der übergebenen Struktur p1 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (char *) und gibt *p1 zurück.
 * - Wichtige Variablen: Keine weiteren Variablen.
 === Ende Beschreibung === */
char f_03f290(char *p1)
{
  return *p1;
}
