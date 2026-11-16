/* === Beschreibung (Katalog) ===
 * Einheit attic_rest_10b680 (0x10B680 - 0x10B6A0)
 *
 * Überblick
 * Die Einheit attic_rest_10b680 enthält eine kleine Grafik-Hilfsfunktion f_10b680, die einen Streifen am unteren
 * Rand des 320 x 200-Bildschirmpuffers d_1a34e0 schwarz löscht.
 === Ende Beschreibung === */
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
extern unsigned char d_1a34e0[];
void f_10b680(void);
int f_145300(int, int, int);

// Herkunft: Analyse/ghidra/gz_10b680.c; Datenfluss/Typen am Original prüfen.
//@ f_10b680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt im globalen Bildschirmpuffer *(int *)&d_1a34e0 ab dem Offset +0xe38a (58250,
 *   entsprechend Zeile 182, Spalte 10 bei 320 Pixeln Zeilenbreite) genau 0xc80 (3200 Bytes, also 10
 *   Bildschirmzeilen zu je 320 Pixeln) über f_145300 (memset) mit dem Farbwert 0.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a34e0: Globaler Zeiger auf den Haupt-Bildschirmpuffer (320 x 200 Pixel).
 === Ende Beschreibung === */
void f_10b680(void)
{
                    /* WARNING: Subroutine does not return */
  f_145300((*(int *)((unsigned char *)&d_1a34e0)) + 0xe38a,0,0xc80);
}
