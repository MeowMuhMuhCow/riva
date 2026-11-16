/* === Beschreibung (Katalog) ===
 * Einheit import_error (0x1664D0 - 0x16658E)
 *
 * Überblick
 * Die Einheit import_error enthält den kritischen Assertions- und Programmabbruch-Handler f_1664d0 der
 * 3D-/Laufzeit-Engine, der bei einem fatalen Laufzeitfehler die Farbpalette für Textlesbarkeit setzt, die
 * Fehlerursache samt Quelldatei und Zeilennummer ausgibt, auf das Drücken der Escape-Taste wartet und das
 * Programm beendet.
 === Ende Beschreibung === */
// CC wcc386
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

int f_148534(int);
#pragma aux f_148534 "*";
short f_149d50();
#pragma aux f_149d50 "*";
int __cdecl f_149e2e(char *, int);
#pragma aux f_149e2e "*" parm caller [] modify [eax ecx edx];
int f_14d0e4();
#pragma aux f_14d0e4 "*" parm caller [] modify [eax ecx edx];
void f_1664d0(const char *, const char *, int);
#pragma aux f_1664d0 "*";

// Herkunft: Analyse/ghidra/fz_165e20.c; Datenfluss/Typen am Original prüfen.
extern const char d_1b9cf4[];
extern const char d_1b9d05[];
extern const char d_1b9d08[];
extern const char d_1b9d0e[];
extern const char d_1b9d20[];
//@ f_1664d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Palettenfarbe 0 auf Schwarz (0, 0, 0) und die Palettenfarbe 7 auf Weiß (-1, -1,
 *   -1) über f_149e2e, gibt die Fehlermeldung p1 (oder einen Standardtext d_1b9d05, falls p1 == NULL), den
 *   Quelldateinamen p2 und die Zeilennummer p3 sowie den Hinweis auf die Escape-Taste (d_1b9d20) über f_14d0e4
 *   auf dem Bildschirm aus, wartet in einer Schleife auf den Tastencode 0x11b (Escape, f_149d50()) und beendet
 *   das Spiel anschließend über f_148534(5) mit Rückgabecode 5.
 * - Eingaben: p1 (Fehlertext oder verletzte Assertionsbedingung), p2 (Name der Quelldatei), p3 (Zeilennummer in
 *   der Quelldatei).
 * - Rückgabewert: Keiner (kehrt nicht zurück, beendet das Programm mit Code 5).
 * - Wichtige Variablen:
 *   - zero[4], minus[4]: RGB-Tripel für Schwarz (0, 0, 0) und Weiß (255, 255, 255).
 *   - key: Von f_149d50() gelesener Tastencode (0x11b = Escape).
 === Ende Beschreibung === */
void f_1664d0(const char *p1, const char *p2, int p3)
{
  char minus[4];
  char zero[4];
  int key;
  zero[0] = 0;
  zero[1] = 0;
  zero[2] = 0;
  minus[0] = -1;
  minus[1] = -1;
  minus[2] = -1;
  f_149e2e(zero, 0);
  f_149e2e(minus, 7);
  f_14d0e4(d_1b9cf4);
  if (p1 == 0) f_14d0e4(d_1b9d05);
  else f_14d0e4(d_1b9d08, p1);
  f_14d0e4(d_1b9d0e, p2, p3);
  f_14d0e4(d_1b9d20);
  do { key = f_149d50(); } while (key != 0x11b);
  f_148534(5);
}
