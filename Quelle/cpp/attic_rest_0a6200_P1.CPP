/* === Beschreibung (Katalog) ===
 * Einheit attic_rest_0a6200 (0x0A6200 - 0x0A6280)
 *
 * Überblick
 * Die Einheit attic_rest_0a6200 enthält den Konstruktor f_0a6200 eines Texteingabefeld- und Cursor-Objekts
 * (input.c), das die Zeichenbreite des Unterstrich-Cursors '_' aus der aktuellen Schriftart ermittelt und einen
 * Hintergrund-Sicherungspuffer für die eingegebenen Zeichen anlegt.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
// P3 0/1 gleich (suche.py 29.10.2026, Basis attic_rest_0a6200_P1.CPP)
// CC wpp386
// OPT -4r -oneatx -zp1 -s
// Astra630: ERSTENTWURF. Kein GLEICH-Nachweis. Ghidra-Datenfluss und 64-Bit-C müssen für Watcom 10.6 nachgearbeitet werden.

typedef unsigned char byte;
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined3;
typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef int int3;
typedef int bool;
typedef int code();
#define true 1
#define false 0
#define CONCAT11(a,b) (((ushort)(byte)(a)<<8)|(byte)(b))
#define CONCAT12(a,b) (((uint)(byte)(a)<<16)|(ushort)(b))
#define CONCAT13(a,b) (((uint)(byte)(a)<<24)|((uint)(b)&0xffffff))
#define CONCAT21(a,b) (((uint)(ushort)(a)<<8)|(byte)(b))
#define CONCAT22(a,b) (((uint)(ushort)(a)<<16)|(ushort)(b))
#define CONCAT31(a,b) (((uint)(a)<<8)|(byte)(b))
#define CONCAT44(a,b) (((ulonglong)(uint)(a)<<32)|(uint)(b))
#define SUB41(a,b) ((byte)((uint)(a)>>((b)*8)))
#define SUB42(a,b) ((ushort)((uint)(a)>>((b)*8)))
#define SUB84(a,b) ((uint)((ulonglong)(a)>>((b)*8)))
#define CARRY1(a,b) ((unsigned)(byte)(a)+(byte)(b)>255)
#define CARRY2(a,b) ((unsigned)(ushort)(a)+(ushort)(b)>65535)
#define CARRY4(a,b) ((uint)(a)+(uint)(b)<(uint)(a))
#define SCARRY4(a,b) ((((uint)(~((a)^(b))))&((uint)((a)+(b))^(uint)(a)))>>31)
#define SBORROW4(a,b) ((((uint)((a)^(b)))&((uint)((a)-(b))^(uint)(a)))>>31)
#define ABS(a) ((a)<0?-(a):(a))
#define ZEXT14(a) ((uint)(byte)(a))
#define ZEXT24(a) ((uint)(ushort)(a))
#define ZEXT48(a) ((ulonglong)(uint)(a))
#define SEXT14(a) ((int)(signed char)(a))
#define SEXT24(a) ((int)(short)(a))
#define SEXT48(a) ((longlong)(int)(a))
extern unsigned char d_1a3e40[];
extern unsigned char d_1c3078[];
int f_014540(int,int,int);
int f_045db0(int,int);
int f_0a6200(int p1,undefined4 p2);
int f_0fabf0(int);


// Herkunft: Analyse/ghidra/input.c; Datenfluss/Typen am Original prüfen.
//@ f_0a6200
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert das eingebettete RivaRasterImage-Objekt ab Offset +0x1e der
 *   Eingabefeld-Struktur p1, speichert die maximale Zeichenanzahl p2 an Offset +0x08, fragt die Pixelbreite des
 *   Unterstrichzeichens '_' (0x5f) im aktuellen Font d_1c3078 über f_045db0 ab, reserviert einen
 *   Hintergrundpuffer für Zeichenbreite * 8 * max_Zeichen Bytes an Offset +0x12 und richtet das
 *   Cursor-Rasterbild auf die Größe Zeichenbreite x 8 Pixel ein.
 * - Eingaben: p1 (Zeiger auf die zu initialisierende Eingabefeld-Struktur), p2 (maximale Anzahl der eingebbaren
 *   Zeichen; wird bei 0 für die Puffergröße auf 1 angehoben).
 * - Rückgabewert: Zeiger auf die initialisierte Eingabefeld-Struktur p1.
 * - Wichtige Variablen:
 *   - *(short *)(p1 + 6): Pixelbreite des Unterstrich-Cursors '_' (0x5f) im Font d_1c3078.
 *   - *(short *)(p1 + 8): Maximale Zeichenanzahl des Eingabefelds.
 *   - *(int *)(p1 + 0x12): Zeiger auf den reservierten Hintergrund-Sicherungspuffer (Breite * 8 * p2 Bytes).
 *   - p1 + 0x1e: Eingebettetes RivaRasterImage für den Textcursor.
 === Ende Beschreibung === */
int f_0a6200(int p1,undefined4 p2)
{
  p1 = f_0fabf0(p1 + 0x1e) - 0x1e;
  *(short *)(p1 + 8) = (short)p2;
  *(short *)(p1 + 0xe) = 0;
  *(short *)(p1 + 6) = (unsigned char)f_045db0((int)d_1c3078,0x5f);
  if (*(short *)(p1 + 8) == 0) p2 = 1;
  *(int *)(p1 + 0x12) = f_014540(*(short *)(p1 + 6) * 8 * (short)p2,(int)d_1a3e40,0x32);
  ((RivaRasterImage*)(p1 + 0x1e))->f_0fad50(*(short *)(p1 + 6),8,(void *)(0));
  return p1;
}
