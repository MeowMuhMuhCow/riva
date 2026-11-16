/* === Beschreibung (Katalog) ===
 * Einheit attic_rest_051850 (0x051850 - 0x051870)
 *
 * Überblick
 * Die Einheit attic_rest_051850 enthält eine kurze Hilfsfunktion zur Synchronisation und Aktualisierung eines
 * untergeordneten UI- oder Steuerelement-Objekts (p1[1]) anhand eines 16-Bit-Werts aus dem zugehörigen
 * Datenobjekt (*p1).
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

int f_026600(int, int);
int f_0268c0(int);
void f_051850(int *p1);

// Herkunft: Analyse/ghidra/gz_051850.c; Datenfluss/Typen am Original prüfen.
//@ f_051850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 16-Bit-Wert an Offset +0x02 des in p1[0] referenzierten Datenobjekts aus,
 *   übergibt ihn über f_026600 an das in p1[1] gespeicherte Steuerelement-Objekt und stößt anschließend dessen
 *   Neuzeichnung oder Aktualisierung über f_0268c0 an.
 * - Eingaben: p1 (Zeiger auf eine Struktur mit einem Datenzeiger an p1[0] und einem Steuerelement-Zeiger an
 *   p1[1]).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - *(short *)(*p1 + 2): Aus dem Datenobjekt p1[0] übernommener 16-Bit-Zustandswert.
 *   - p1[1]: Zeiger auf das aktualisierte Unterobjekt.
 === Ende Beschreibung === */
void f_051850(int *p1)
{
  f_026600(p1[1],(int)*(short *)(*p1 + 2));
  f_0268c0(p1[1]);
  return;
}
