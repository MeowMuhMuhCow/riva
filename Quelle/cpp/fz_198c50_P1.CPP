/* === Beschreibung (Katalog) ===
 * Einheit fz_198c50 (0x198c50 - 0x198c95)
 *
 * Überblick
 * Diese Einheit enthält die BRender-Material-Vorbereitungsfunktion (BrMaterialUpdate / f_198c50), die die
 * internen Vorbereitungs-Flags eines 3D-Materials anhand seiner Beleuchtungs- und Texturattribute aktualisiert.
 === Ende Beschreibung === */
// P3 14/21 gleich (suche.py 30.10.2026, Basis fz_197510_P1.CPP)
// OPT -5r -oneatx -zp1 -s
// P1 0/21 gleich
// CC wcc386
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma intrinsic(sqrt)
#define W16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define S16(p,o) (*(short *)((char *)(p) + (o)))
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define U32(p,o) (*(unsigned *)((char *)(p) + (o)))
#define B8(p,o) (*(unsigned char *)((char *)(p) + (o)))
struct BF { unsigned short b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1,b8:1,b9:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1; };
#define FLG(p,bit,m) (W16(p,0x1c) & (m))
struct te { struct te *next; short first; short last; char other; char pad[3]; };
typedef int (*CMP)(int *, int *);
long IFixedMul(long a, long b);
#pragma aux IFixedMul = "imul ebx" "shrd eax,edx,16" parm nomemory [eax] [ebx] modify nomemory [edx];
long IFixedDiv(long a, long b);
#pragma aux IFixedDiv = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm nomemory [edx] [ebx] modify nomemory [eax];
long IFixedSqr3(long a, long b, long c);
#pragma aux IFixedSqr3 = "imul eax" "xchg ebx,eax" "mov ecx,edx" "imul eax" "add ebx,eax" "adc ecx,edx" "mov eax,esi" "imul eax" "add eax,ebx" "adc edx,ecx" "shrd eax,edx,16" parm nomemory [eax] [ebx] [esi] modify nomemory [ebx ecx edx];
long Mac15(short a, long b, short c, long d, short e, long f);
#pragma aux Mac15 = "cwde" "imul edx" "shrd eax,edx,15" "xchg ecx,eax" "cwde" "imul ebx" "shrd eax,edx,15" "add ecx,eax" "mov eax,esi" "cwde" "imul edi" "shrd eax,edx,15" "add eax,ecx" parm nomemory [eax] [edx] [ecx] [ebx] [esi] [edi] modify nomemory [ecx];
int f_188404(int p1, int p2, int p3);
int f_18850c(int p1);
int f_199410(int p1);
void f_199484(int p1);
int f_16d3d0(int p1);
void f_197390(char *, ...);
void f_1994e0(void *base, int n, int size, CMP cmp);
int f_16d4fc(int, ...);
extern float d_1ba8d4;
extern float d_1ba8d8;
extern const char d_1ba8dc[];
extern int d_1b52a4;
extern char *d_1d4d34;
extern struct te **d_1d4d38;
extern struct te *d_1d4d3c;
extern void (*d_1d4990)(int, unsigned short);
extern void (*d_1d4994)(int, unsigned short);
#pragma aux f_188404 "*";
#pragma aux f_18850c "*";
#pragma aux f_199410 "*";
#pragma aux f_199484 "*";
#pragma aux f_16d3d0 "*";
#pragma aux f_16d4fc "*";
#pragma aux f_197390 "*";
#pragma aux f_1994e0 "*";
#pragma aux f_197510 "*";
#pragma aux f_1975a0 "*";
#pragma aux f_1975c8 "*";
#pragma aux f_19761c "*";
#pragma aux f_197708 "*";
#pragma aux f_1977a4 "*";
#pragma aux f_1979c0 "*";
#pragma aux f_197a40 "*";
#pragma aux f_197ac0 "*";
#pragma aux f_197c88 "*";
#pragma aux f_197e18 "*";
#pragma aux f_197e98 "*";
#pragma aux f_197fb8 "*";
#pragma aux f_19803c "*";
#pragma aux f_198574 "*";
#pragma aux f_1987fc "*";
#pragma aux f_1988bc "*";
#pragma aux f_198978 "*";
#pragma aux f_1989e4 "*";
#pragma aux f_198a48 "*";
#pragma aux f_198c50 "*";
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_198c50
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198c50
 * - Aufgabe im Spiel: Aktualisiert das Vorbereitungs-Statusbyte (+0x44) einer BRender-Materialstruktur (p1):
 *   Zuerst werden die unteren beiden Bits gelöscht (&= 0xfc), danach wird je nach gesetztem Flag an Offset +0x14
 *   (Bit 4, z. B. Gouraud-/Smooth-Shading) oder vorhandenem colour_map-Texturzeiger an Offset +0x34 entweder Bit
 *   2 (interpolierte/texturierte Darstellung) oder Bit 1 (einfache Darstellung) gesetzt. Abschließend ruft die
 *   Funktion - falls registriert - den globalen Material-Update-Callback d_1d4994 auf.
 * - Eingaben: Zeiger auf die Materialstruktur (p1) und Update-Modus-Bitmaske (p2).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Materialfelder an Offset +0x14 (Material-Flags), +0x34 (Textur-/Colour-Map-Zeiger) und +0x44 (vorbereitete
 *     Rendering-Flags).
 *   - Globaler Callback-Zeiger d_1d4994.
 === Ende Beschreibung === */
void f_198c50(int p1, unsigned short p2)
{
    B8(p1, 0x44) &= 0xfc;
    if (B8(p1, 0x14) & 4) B8(p1, 0x44) |= 2;
    else B8(p1, 0x44) |= 1;
    if (I32(p1, 0x34) != 0) B8(p1, 0x44) |= 2;
    if (d_1d4994) d_1d4994(p1, p2);
}
