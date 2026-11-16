/* === Beschreibung (Katalog) ===
 * Einheit gz_03f060_t1 (0x03f060 - 0x03f240)
 *
 * Überblick
 * Dieser erste Teil der Einheit gz_03f060 implementiert die Anzeige der Hersteller-/Publisher-Logos und
 * Intro-Sequenzen beim Spielstart (f_03f060 für ein einzelnes PCX-Logo mit Begleitmusik, f_03f170 für die
 * gesamte Intro-Abfolge aus Videos und Standbildern) sowie einen Konstruktor für ein
 * SVGA-Bildschirm-Deskriptorobjekt (f_03f210).
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
//@ f_03f060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion lädt eine PCX-Grafikdatei name von der CD/Festplatte, spielt dazu eine
 *   Musikdatei (d_1b6497) ab, kopiert die Bilddaten und die 256-Farben-Palette in den Bildschirmpuffer
 *   (320x200), wartet kurz (250 Zeiteinheiten) und gibt die Ressourcen wieder frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildnamen name (const char *) in EAX und den Zeiger auf ein
 *   Bild-Hilfsobjekt img in ESI; sie gibt keinen Wert zurück.
 * - Wichtige Variablen: Der lokale Puffer pcx[164] repräsentiert das PCX-Ladeobjekt (f_1459b0 Konstruktor,
 *   f_1459d0 Destruktor); d_1c21b4 nimmt den formatierten Dateipfad auf.
 === Ende Beschreibung === */
// Original liest das Bildobjekt in ESI; direkte Aufrufer behalten diesen Kontext bei.
void f_03f060(const char *name,int img);
#pragma aux f_03f060 parm [eax] [esi];
void f_03f060(const char *name,int img)
{
 char pcx[164];C1459b0_1((int)pcx);C149d20_0();
 Cfmt494((char *)NA(d_1c21b4),(const char *)NA(d_1b648c),NA(d_1a96a4),name);
 C059d60_3(NA(d_1c21b4),NA(d_1b6497));ND32(d_1a965c)=NA(d_1b6497);
 if(C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,512)==1) {
  C1449a0_1(NA((*(unsigned char*)&d_1c2098)));C145a00_3((int)pcx,0);
  C0fad50_4(img,320,200,C145b70_1((int)pcx));C09a0d0_1(ND32(d_1a34e0));
  C099ef0_3(C145b40_1((int)pcx),0,256);
  C0fade0_4(img,ND32(d_1a34e0),0,0);C0fadc0_1(img);C0d4730_1(250);
  C09a0d0_1(ND32(d_1a34e0));C149336_1(NA(d_1b6497));
 }
 C149d20_0();C1459d0_2((int)pcx,0);
}

void paint494(const char *, int);
#pragma aux paint494 "W?f_03f060$n(pnxai)v" parm [eax] [esi] modify exact [eax];
struct Flags494 { static signed char first() { return ND8(d_1bfb10); } static unsigned second() { union { unsigned full; unsigned char byte; } v; v.full=0; v.byte=NB(&d_1c1110,0); return v.full; } };
//@ f_03f170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion spielt die dreiteilige Intro-Sequenz beim Start von *Schatten über Riva* ab: Je
 *   nach Konfigurationsflags (d_1bfb10 == 1 && d_1c1110 == 1, vermutlich hohe/niedrige Videoauflösung oder
 *   deutsche/englische Version) werden im Wechsel drei Filmsequenzen (f_03ede0) und vier Standbilder (f_03f060)
 *   abgespielt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und keinen Rückgabewert.
 * - Wichtige Variablen: Die Stringkonstanten d_1b649f bis d_1b64db (Zweig 1) bzw. d_1b64e8 bis d_1b6524 (Zweig
 *   2) enthalten die Dateinamen der Intro-Videos und -Bilder.
 === Ende Beschreibung === */
void f_03f170();
#pragma aux f_03f170 modify exact [eax ebp edi];
void sound492(const char*);
#pragma aux sound492 "f_03ede0" modify exact [eax];
void picture492(const char*);
#pragma aux picture492 "f_03f060" modify exact [eax ebp edi];
void start492();
#pragma aux start492 "f_0d2710" modify exact [eax];
void finish492();
#pragma aux finish492 "f_0d26e0" modify exact [eax];
void present492();
#pragma aux present492 "f_09a400" modify exact [eax];
void f_03f170() {
 const char *last;
 start492();
 signed char first=(signed char)d_1bfb10;
 if((int)first==1 && (int)d_1c1110==1)
 {
  sound492((const char*)&d_1b649f);picture492((const char*)&d_1b64ac);
  sound492((const char*)&d_1b64b8);picture492((const char*)&d_1b64c4);
  sound492((const char*)&d_1b64d0);last=(const char*)&d_1b64db;
 } else {
  sound492((const char*)&d_1b64e8);picture492((const char*)&d_1b64f5);
  sound492((const char*)&d_1b6501);picture492((const char*)&d_1b650d);
  sound492((const char*)&d_1b6519);last=(const char*)&d_1b6524;
 }
 picture492(last);
 finish492();present492();
}
//@ f_03f210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dieser Konstruktor initialisiert ein 14 Byte großes Bildschirm-Deskriptorobjekt p1 für den
 *   hochauflösenden Grafikmodus (Typ 2, Videospeicher 0xA0000, Methodentabelle d_1bacc4) mit der Breite p2 und
 *   der Höhe p3.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1, die Breite p2 und die Höhe p3 und gibt p1
 *   zurück.
 * - Wichtige Variablen: Offset +0 ist der Modustyp (2), +2 die Breite, +4 die Höhe, +6 die VGA-Basisadresse
 *   0xA0000 und +10 der Zeiger auf die virtuelle Methodentabelle d_1bacc4.
 === Ende Beschreibung === */
int f_03f210(int p1, int p2, int p3)
{
  *(short *)p1 = 2;
  *(int *)(p1 + 6) = 0xA0000;
  *(int *)(p1 + 10) = (int)&d_1bacdc;
  *(short *)(p1 + 2) = (short)p2;
  *(short *)(p1 + 4) = (short)p3;
  *(int *)(p1 + 10) = (int)&d_1bacc4;
  return p1;
}