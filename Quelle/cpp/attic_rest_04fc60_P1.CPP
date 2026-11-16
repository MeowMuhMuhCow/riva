/* === Beschreibung (Katalog) ===
 * Einheit attic_rest_04fc60 (0x04FC60 - 0x04FCE0)
 *
 * Überblick
 * Die Einheit attic_rest_04fc60 enthält den Konstruktor einer zweidimensionalen 2-Bit-Matrix (dbitmatr), die
 * vier 2-Bit-Zellen pro Byte speichert (beispielsweise für Sichtbarkeits-, Erkundungs- oder
 * Begehbarkeitsmarkierungen auf Karten).
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
extern unsigned char d_1a13e0[];
int f_014ac0(int, int);
int f_014b10(const char *, int);
ushort *f_04fc60(ushort *p1,undefined4 p2,undefined4 p3,uint p4);
int f_145300(int, int, int);

// Herkunft: Analyse/ghidra/dbitmatr.c; Datenfluss/Typen am Original prüfen.
//@ f_04fc60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert eine 2-Bit-Matrix-Struktur (p1) mit der Breite p2 und der Höhe p3, berechnet
 *   die Zeilenbreite in Bytes als (Breite + 3) / 4, reserviert den Matrixspeicher (Höhe * Zeilenbreite Bytes)
 *   über den Spiel-Allocator (f_014ac0) und füllt alle Zellen per memset (f_145300) mit dem vierfach in ein Byte
 *   gepackten 2-Bit-Startwert p4.
 * - Eingaben: p1 (Zeiger auf die 10-Byte-Matrixstruktur), p2 (Breite in Zellen), p3 (Höhe in Zellen), p4
 *   (2-Bit-Anfangswert 0..3 für jede Zelle).
 * - Rückgabewert: Zeiger auf die initialisierte Matrixstruktur p1.
 * - Wichtige Variablen:
 *   - p1[0] (+0x00), p1[1] (+0x02), p1[2] (+0x04): Breite, Höhe und Zeilenstride in Bytes ((p2 + 3) / 4).
 *   - *(int *)(p1 + 3) (+0x06): Zeiger auf den reservierten Bytepuffer der Größe p3 * p1[2].
 *   - fill: Durch Bitverschiebung (((p4 * 4 | p4) * 4 | p4) * 4 | p4) auf alle vier 2-Bit-Paare eines Bytes
 *     replizierter Füllwert.
 === Ende Beschreibung === */
ushort *f_04fc60(ushort *p1,undefined4 p2,undefined4 p3,uint p4)
{
  *p1 = (ushort)p2;
  p1[1] = (ushort)p3;
  p1[2] = (ushort)(((int)(ushort)p2 + 3) / 4);
  int size = (uint)(ushort)p3 * (uint)p1[2];
  int data = f_014ac0(size, f_014b10((const char *)d_1a13e0, 0x58));
  int fill = ((p4 * 4 | p4) * 4 | p4) * 4 | p4;
  *(int *)(p1 + 3) = data;
  f_145300(data, fill, size);
  return p1;
}
