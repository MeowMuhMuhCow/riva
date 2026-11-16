/* === Beschreibung (Katalog) ===
 * Einheit speech (10b6a0 - 10c300)
 *
 * Überblick
 *
 * Die Einheit speech steuert die Sprachausgabe und die vertonten Erzähler- und Dialogfenster (CD-Sprachdateien /
 * .WAV- bzw. .VOC-Streams zusammen mit Porträt-Animationen und Untertiteln).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 4/6 gleich (suche.py 29.10.2026, Basis speech_P1.CPP)
// speech.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10B6A0-0x10C300
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_013de0(int p1);                                   // reg eax stapel 0
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e490(int p1, int p2);                           // reg eax edx stapel 0
int f_05e610(int p1, int p2);                           // reg eax stapel 0
int f_05e840(int p1, int p2);                           // reg eax edx stapel 0
int f_05e850(int p1);                                   // reg eax stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_099ea0();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0bdd50();                       // nicht in clobber.tsv
int f_0bdde0(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d4880();                                         // reg - stapel 0
int f_0f00f0(int p1);                                   // reg eax stapel 0
int f_0f1560(int p1);                                   // reg eax stapel 0
int f_11e760(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_11e910(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_146d36(int p1);                                   // reg eax stapel 0
int f_149d20();                                         // reg - stapel 0
int f_149e2e(int p1, int p2);                           // reg - stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_149f90();                       // nicht in clobber.tsv
int f_14a0b0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_14a1d0(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_14a940();                       // nicht in clobber.tsv
int f_14b100();                       // nicht in clobber.tsv
int f_14b3d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14b7b0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14bb40(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg - stapel 12
int f_14d040();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a6c30;                    // 0x1A6C30
extern int d_1a6c9c;                    // 0x1A6C9C
extern int d_1a6d14;                    // 0x1A6D14
extern int d_1a6d80;                    // 0x1A6D80
extern int d_1a6df8;                    // 0x1A6DF8
extern int d_1a6e10;                    // 0x1A6E10
extern int d_1a6e28;                    // 0x1A6E28
extern int d_1a6e40;                    // 0x1A6E40
extern int d_1a6e58;                    // 0x1A6E58
extern int d_1a6e70;                    // 0x1A6E70
extern int d_1a6e88;                    // 0x1A6E88
extern int d_1a6ea0;                    // 0x1A6EA0
extern int d_1a6eb8;                    // 0x1A6EB8
extern int d_1a6f48;                    // 0x1A6F48
extern int d_1a6fa8;                    // 0x1A6FA8
extern int d_1a7008;                    // 0x1A7008
extern int d_1a7020;                    // 0x1A7020
extern int d_1a7080;                    // 0x1A7080
extern int d_1a70c8;                    // 0x1A70C8
extern int d_1a7110;                    // 0x1A7110
extern int d_1a7158;                    // 0x1A7158
extern int d_1a717c;                    // 0x1A717C
extern int d_1a71a0;                    // 0x1A71A0
extern int d_1a71b8;                    // 0x1A71B8
extern int d_1a71fc;                    // 0x1A71FC
extern int d_1bc760;                    // 0x1BC760
extern signed char d_1bfae0;                    // 0x1BFAE0
extern int d_1c0004;                    // 0x1C0004
extern int d_1c03bc;                    // 0x1C03BC
extern int d_1c0974;                    // 0x1C0974
extern int d_1c09c0;                    // 0x1C09C0
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c0c94;                    // 0x1C0C94
extern int d_1c11b8;                    // 0x1C11B8
extern int d_1c2198;                    // 0x1C2198
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1a6c10[];           // Text 0x1A6C10
extern const char d_1a71e8[];           // Text 0x1A71E8
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


extern char *d_1a34e0;
extern short d_1bd762;
extern int d_1c38b0;
int f_05e320(int p1, int p2, int p3);
int f_05e320(int p1, int p2, int p3, int p4);
int f_0e9510(int p1, int p2, int p3);
void *f_145300(void *p, int c, unsigned n);
void f_068f40(int p1);
#pragma aux f_068f40 parm [edx] modify exact [eax];

#include <string.h>
#include <stdio.h>
#include <bios.h>

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
extern unsigned char d_1a6ed0;
extern unsigned char d_1a6f0c;
extern unsigned char d_1a7038;
extern signed char d_1a96a4;
extern unsigned char d_1b8358;
extern unsigned char d_1b835c;
int C013670_3(int,int,int);
#pragma aux C013670_3 "f_013670" modify exact [eax ebx edx];
int C013de0_1(int);
#pragma aux C013de0_1 "f_013de0" modify exact [eax];
int C014540_3(int,int,int);
#pragma aux C014540_3 "f_014540" modify exact [eax ebx edx];
int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C01cef0_1(int);
#pragma aux C01cef0_1 "f_01cef0";
int C038c40_1(int);
#pragma aux C038c40_1 "f_038c40" modify exact [eax];
int C039ac0_2(int,int);
#pragma aux C039ac0_2 "f_039ac0" modify exact [eax edx];
int C042380_1(int);
#pragma aux C042380_1 "f_042380" modify exact [eax];
int C043cd0_1(int);
#pragma aux C043cd0_1 "f_043cd0";
int C05e2a0_5(int,int,int,int,int);
#pragma aux C05e2a0_5 "f_05e2a0" modify exact [eax edx];
int C05e2d0_5(int,int,int,int,int);
#pragma aux C05e2d0_5 "f_05e2d0" modify exact [edx];
int C05e320_3(int,int,int);
#pragma aux C05e320_3 "f_05e320";
int C05e360_3(int,int,int);
#pragma aux C05e360_3 "f_05e360" modify exact [eax];
int C05e490_2(int,int);
#pragma aux C05e490_2 "f_05e490" modify exact [eax edx];
int C05e840_2(int,int);
#pragma aux C05e840_2 "f_05e840";
int C05e850_1(int);
#pragma aux C05e850_1 "f_05e850" modify exact [eax];
int C060a10_1(int);
#pragma aux C060a10_1 "f_060a10" modify exact [eax];
int C07a120_0();
#pragma aux C07a120_0 "f_07a120";
int C099ea0_0();
#pragma aux C099ea0_0 "f_099ea0" modify exact [eax];
int __cdecl C099ef0_3(int,int,int);
#pragma aux C099ef0_3 "f_099ef0" modify exact [eax ecx edx];
int C09a0d0_1(int);
#pragma aux C09a0d0_1 "f_09a0d0" modify exact [eax];
int C09a140_2(int,int);
#pragma aux C09a140_2 "f_09a140" modify exact [eax edi edx esi];
int C09ac80_3(int,int,int);
#pragma aux C09ac80_3 "f_09ac80" modify exact [eax ebx edx];
int C09ade0_3(int,int,int);
#pragma aux C09ade0_3 "f_09ade0" modify exact [eax ebx edx];
int C09aed0_1(int);
#pragma aux C09aed0_1 "f_09aed0" modify exact [eax];
int C0bdd50_4(int,int,int,int);
#pragma aux C0bdd50_4 "f_0bdd50";
int C0bdde0_4(int,int,int,int);
#pragma aux C0bdde0_4 "f_0bdde0" modify exact [eax ebx ecx edx];
int C0ce7c0_1(int);
#pragma aux C0ce7c0_1 "f_0ce7c0";
int C0ce7e0_1(int);
#pragma aux C0ce7e0_1 "f_0ce7e0" modify exact [edx];
int C0d26e0_0();
#pragma aux C0d26e0_0 "f_0d26e0" modify exact [eax];
int C0d2710_0();
#pragma aux C0d2710_0 "f_0d2710" modify exact [eax];
int C0d3780_0();
#pragma aux C0d3780_0 "f_0d3780" modify exact [eax];
int C0d37b0_0();
#pragma aux C0d37b0_0 "f_0d37b0" modify exact [eax];
int C0d3f25_2(int,int);
#pragma aux C0d3f25_2 "f_0d3f25" modify exact [eax edx];
int C0d4070_1(int);
#pragma aux C0d4070_1 "f_0d4070" modify exact [eax];
int C0d40b6_1(int);
#pragma aux C0d40b6_1 "f_0d40b6" modify exact [eax];
int C0d4880_0();
#pragma aux C0d4880_0 "f_0d4880";
int C0e93f0_3(int,int,int);
#pragma aux C0e93f0_3 "f_0e93f0" modify exact [eax ebx edx];
int C0e9660_4(int,int,int,int);
#pragma aux C0e9660_4 "f_0e9660" modify exact [eax ebx ecx edx];
int C0e9680_2(int,int);
#pragma aux C0e9680_2 "f_0e9680";
int C0f00f0_1(int);
#pragma aux C0f00f0_1 "f_0f00f0";
int C0f1560_1(int);
#pragma aux C0f1560_1 "f_0f1560";
int C10b6a0_1(int);
#pragma aux C10b6a0_1 "f_10b6a0" modify exact [eax];
int C10bc50_2(int,int);
#pragma aux C10bc50_2 "f_10bc50" modify exact [eax edx];
int C10bd70_3(int,int,int);
#pragma aux C10bd70_3 "f_10bd70" modify exact [eax ebx edx];
int __pascal C11e760_2(int,int);
#pragma aux C11e760_2 "f_11e760" modify exact [eax ebx ecx edx];
int __cdecl C11e910_8(int,int,int,int,int,int,int,int);
#pragma aux C11e910_8 "f_11e910" modify exact [eax ecx edx];
int C146d36_1(int);
#pragma aux C146d36_1 "f_146d36" modify exact [eax];
int C147c84_2(int,int);
#pragma aux C147c84_2 "f_147c84" modify exact [eax ebx edx];
int C149d20_0();
#pragma aux C149d20_0 "f_149d20" modify exact [eax];
int __cdecl C149e2e_2(int,int);
#pragma aux C149e2e_2 "f_149e2e" modify exact [eax edi edx esi];
int __cdecl C149eb4_3(int,int,int);
#pragma aux C149eb4_3 "f_149eb4" modify exact [eax ecx edi edx esi];
int __pascal C149f90_1(int);
#pragma aux C149f90_1 "f_149f90";
int C14a0b0_0();
#pragma aux C14a0b0_0 "f_14a0b0" modify exact [eax ebx ecx edx];
int __pascal C14a1d0_2(int,int);
#pragma aux C14a1d0_2 "f_14a1d0" modify exact [eax ebx ecx edx];
int __pascal C14a940_7(int,int,int,int,int,int,int);
#pragma aux C14a940_7 "f_14a940";
int __pascal C14b100_1(int);
#pragma aux C14b100_1 "f_14b100";
int __pascal C14b3d0_1(int);
#pragma aux C14b3d0_1 "f_14b3d0" modify exact [eax ebx ecx edi edx];
int __pascal C14b7b0_1(int);
#pragma aux C14b7b0_1 "f_14b7b0" modify exact [eax ebx ecx edx];
int __pascal C14bb40_3(int,int,int);
#pragma aux C14bb40_3 "f_14bb40" modify exact [eax ebx ecx edx];
int __cdecl C14d040_1(int);
#pragma aux C14d040_1 "f_14d040";
//@ f_043cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese extern definierte Funktion ist im Kopfbereich vorwärtsdeklariert und dient dem Abfragen von
 *   Gruppen- oder Charakterdaten.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
unsigned f_043cd0(int p1)
{
    return (unsigned)(*(int *)(p1 + 0xbc) << 8) >> 0x1f;
}
//@ f_10b6a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert den Sprachausgabe-Controller, lädt die zugehörige Zuordnungstabelle
 *   für Sprachsamples und richtet die Puffer für Ton- und Untertitelwiedergabe ein.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie Initialisierungsparameter (p2, p3).
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_10b6a0(int sequence)
{
 int lock_release491(int,int);
 #pragma aux lock_release491 "f_0ce7e0" modify exact [edx];
 struct Format491 {char text[20];};
 struct Buffers1079 {Format491 format;int b,a;} buffers;
 short lock;
 struct Loop1079 {int row,index,result;} state;
 int obj,kind,next=0;
 int a,b;
 short i;
 unsigned char flags;
 C0ce7c0_1((int)&lock);
 buffers.format=*(const Format491 *)NA(d_1a71e8);
 a=buffers.a=NNEW(256,d_1a6c10,0x189);
 b=buffers.b=NNEW(256,d_1a6c10,0x18a);
 sprintf((char *)a,buffers.format.text,NA(d_1a96a4),NA(d_1b8358));
 sprintf((char *)b,buffers.format.text,NA(d_1a96a4),NA(d_1b835c));
 int raw=NOBJ(0x82,d_1a6c10,0x18f);
 obj=raw?C013670_3(raw,a,b):raw;
 for(i=0;NI(state.row=sequence+(state.index=(int)i)*12,0);i++) {
   kind=NI(obj,0);
   ((int (*)(int,int,int))NI(kind,0x14))(obj,NI(state.row,0),512);
   flags=0;
   if(NI(state.row,8)==1) {
     kind=(kind&0)?0:kind;next=state.index;kind=NI(state.row,8);next+=kind; /* haelt kind/edi lebendig und verhindert CSE mit dem Bedingungs-Load */ next=sequence+next*12;
     if(!NI(next,0)&&!NI(next,8))flags=2;
   } else {
     if(!state.index)flags=1;
     if(!NI(sequence,((int)i+1)*12))flags|=2;
   }
   state.result=C10bd70_3(C013de0_1(obj),NI(sequence,i*12+4),flags);
   ((int (*)(int))NI(NI(obj,0),0x28))(obj);
 }
 if(obj)((int (*)(int,int))NI(NI(obj,0),0))(obj,2);
 C014710_1(buffers.a);
 C014710_1(buffers.b);
 lock_release491((int)&lock,0);
 return state.result;
}
//@ f_10b830
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor stoppt eine laufende Sprachausgabe, gibt die geladenen Audio- und Tabellenpuffer
 *   frei und baut das Sprachausgabe-Objekt ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
unsigned f_10b830(int self)
{
 return C043cd0_1(self);
}

//@ f_10b890
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Funktion spielt einen vertonten Textabschnitt ab: Sie ermittelt zur Textkennung p2 die
 *   passende Audiodatei auf der CD bzw. im Archiv, startet den Sprachstream, blendet synchron den Untertiteltext
 *   im Dialogfenster ein und wartet auf das Ende der Sprachausgabe oder einen Abbruch durch den Spieler.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Text-/Sprach-ID p2 sowie Darstellungs- und
 *   Steuerparameter (p3, p4).
 * - Rückgabewert: Die Funktion gibt den Abschlussstatus der Sprachausgabe zurück.
 === Ende Beschreibung === */
int f_10b890(int which)
{
 extern char d_1baac0[];
 void construct650(void *,int,const void *);
 #pragma aux construct650 "f_147c84" parm [eax] [edx] [ebx] modify exact [eax ebx edx]
 signed char gender650(int);
 #pragma aux gender650 "f_042380" parm [eax] modify exact [eax]
 void reset650(int);
 #pragma aux reset650 "f_0d4880" parm [eax]
 void screenflag650(int);
 #pragma aux screenflag650 "f_0f00f0" parm [eax] modify exact []
 unsigned char palette[768];
 int saved,result;
 short old;
 construct650(palette,256,d_1baac0);
 saved=*(volatile int *)&d_1c0c94; // volatile erzwingt das Vorziehen des Ladens vor C060a10_1
 C060a10_1(500000);
 result=0;
 if(ND32(d_1bc760)) C01cef0_1(ND32(d_1bc760));
 C09ac80_3(ND32(d_1a34e0),0,0);
 C149eb4_3((int)palette,0,256);
 ND32(d_1c0c4c)++;
 ND32(d_1c2a80)=0;
 ND32(d_1c0c94)=0;
 C0f1560_1(NA(d_1c2e68));
 C0d2710_0();
 old=(short)C0d40b6_1(NA(d_1c2e78));
 C0d4070_1(NA(d_1c2e78));
 switch(which) {
 case 1:
  if((int)gender650(C038c40_1(ND32(d_1c0004)))==0) C10b6a0_1(NA(d_1a6ed0));
  else C10b6a0_1(NA(d_1a6f0c));
  break;
 case 2:
  result=2;
  if((int)gender650(C038c40_1(ND32(d_1c0004)))==0) {
   C10b6a0_1(NA(d_1a6f48));
   if((short)C10bc50_2(0x2002000c,0x2002000d)==0) {
    result=1;C10b6a0_1(NA(d_1a7008));
   }
  }else{
   C10b6a0_1(NA(d_1a6fa8));
   if((short)C10bc50_2(0x2002000c,0x2002000d)==0) {
    result=1;C10b6a0_1(NA(d_1a7020));
   }
  }
  break;
 case 3:C10b6a0_1(NA(d_1a7038));break;
 case 4:{
  signed char lang650=ND8(d_1c0974);
  if((int)lang650==1) {
   if((int)gender650(C039ac0_2(ND32(d_1c0004),(int)&f_10b830))==0)
    C10b6a0_1(NA(d_1a6c9c));
   else C10b6a0_1(NA(d_1a6d80));
  }else{
   if((int)gender650(C039ac0_2(ND32(d_1c0004),(int)&f_10b830))==0)
    C10b6a0_1(NA(d_1a6c30));
   else C10b6a0_1(NA(d_1a6d14));
  }
  break;
 }
 case 5:
  switch((unsigned short)ND16(d_1c09c0)) {
  case 0:C10b6a0_1(NA(d_1a6df8));break;
  case 1:C10b6a0_1(NA(d_1a6e28));break;
  case 2:C10b6a0_1(NA(d_1a6e40));break;
  case 3:C10b6a0_1(NA(d_1a6e10));break;
  }
  break;
 case 6:
  if((int)ND16(d_1c09c0)==2)C10b6a0_1(NA(d_1a6eb8));
  else C10b6a0_1(NA(d_1a6e58));
  break;
 case 7:
  C10b6a0_1(NA(d_1a6e70));
  if((short)C10bc50_2(0x2e00005f,0x2e000060)==0) {
   result=1;C10b6a0_1(NA(d_1a6e88));
  }else result=2;
  break;
 case 8:C10b6a0_1(NA(d_1a6ea0));break;
 case 9:C10b6a0_1(NA(d_1a7080));break;
 case 11:
  if((int)gender650(C038c40_1(ND32(d_1c0004)))==0) C10b6a0_1(NA(d_1a70c8));
  else C10b6a0_1(NA(d_1a7110));
  break;
 case 12:C10b6a0_1(NA(d_1a7158));break;
 case 13:C10b6a0_1(NA(d_1a717c));break;
 case 14:C10b6a0_1(NA(d_1a71a0));break;
 case 15:C10b6a0_1(NA(d_1a71b8));break;
 }
 C0d3f25_2(NA(d_1c2e78),old);
 C09ade0_3(ND32(d_1a34e0),0,0);
 C09aed0_1(0);
 C0d26e0_0();
 C099ef0_3((int)palette,0,256);
 ND32(d_1c0c94)=saved;
 reset650(NA(d_1c2e68));
 screenflag650(NA(d_1c2e68));
 ND16(d_1c2198)=1;
 ND32(d_1c0c4c)--;
 return result;
}

//@ f_10bc50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sucht in der Sprach-Zuordnungstabelle nach dem Eintrag für die Textkennung p2 und
 *   ermittelt den Dateinamen bzw. Archiv-Offset des zugehörigen Sprachsamples.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die gesuchte Text-ID p2.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den gefundenen Tabelleneintrag oder 0 zurück.
 === Ende Beschreibung === */
short f_10bc50(int p1, int p2)
{
    void colors650(int,int,int);
    #pragma aux colors650 "f_05e320" parm [eax] [edx] [ebx] modify exact [eax]
    int line650(int,int,int,int);
    #pragma aux line650 "f_0e9510" parm [eax] [edx] [ebx] [ecx]

    struct Color650 {static unsigned char get(short side,int desired){if((int)side==desired)return 255;return 205;}};
    short y, x;
    int redraw;
    short side;
    unsigned char col;

    redraw = 1;
    f_05e360((int)&d_1c38b0, (int)&y, (int)&x);
    f_145300(d_1a34e0 + 0xe38a, 0, 0xc80);
    side = 0;
    do {
        f_068f40(0);
        if ((unsigned short)d_1bd762 == 0x4800 || (unsigned short)d_1bd762 == 0x5000) {
            redraw = 1;
            side = side ^ 1;
        }
        if (redraw == 1) {
            colors650((int)&d_1c38b0,Color650::get(side,0),0);
            line650((int)&d_1c38b0, p1, 10, 0xb6);
            colors650((int)&d_1c38b0,Color650::get(side,1),0);
            line650((int)&d_1c38b0, p2, 10, 0xc0);
            redraw = 0;
        }
    } while ((unsigned short)d_1bd762 != 0x1c0d);
    f_145300(d_1a34e0 + 0xe38a, 0, 0xc80);
    colors650((int)&d_1c38b0, (int)y, (int)x);
    return side;
}
//@ f_10bd70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese umfangreiche Funktion steuert mehrteilige vertonte Dialog- und Erzählsequenzen mit
 *   Sprecherporträts, Lippen- bzw. Porträtanimation und automatischem Weiterblättern zwischen den einzelnen
 *   Sprachabschnitten.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Sequenz- und Textparameter (p2, p3, p4).
 * - Rückgabewert: Die Funktion gibt den Ergebniscode der Dialogsequenz zurück.
 === Ende Beschreibung === */
struct MovieState10bd70 {
    int header;
    unsigned width, height, frames;
    char pad10[0x68 - 0x10];
    int paletteChanged;
    char palette[768];
    char pad36c[8];
    int left, top, rectWidth, rectHeight;
};
struct Lines20 { char *p[20]; };
struct Frames20 { short f[20]; };
int f_10bd70(int name, int text, unsigned char flags)
{
    int setfont(int, int);
    #pragma aux setfont "f_05e840" modify exact [eax ecx edx]
    int setcolors(int, int, int);
    #pragma aux setcolors "f_05e320" modify exact [eax]
    Lines20 lines;
    Frames20 frames;
    int result;
    unsigned char rgb[3];
    result = 0, rgb[0] = 0xff, rgb[1] = 0xff, lines = *(const Lines20 *)&d_1c03bc;
    rgb[2] = 0xff;
    signed char line_count;
    frames = *(const Frames20 *)&d_1a71fc;
    int mem = text - text; // Nullinitialisierung ueber Parameterdifferenz haelt Registerbelegung
    line_count = 0;
    int palette;
    int saved_font;
    short w_a8, step, w_ac, col_fg, w_a0, col_bg;
    signed char cur_line;
    int text_buf;
    unsigned frame;
    MovieState10bd70 *movie;
    char *buffer;
    int timer10bd70();
    #pragma aux timer10bd70 "f_149d20" modify exact [eax ebx];

    timer10bd70();
    text_buf = 0;
    saved_font = C05e850_1(NA(d_1c38b0));
    setfont(NA(d_1c38b0), 0);
    f_05e2a0(NA(d_1c38b0), (int)&w_a0, (int)&w_ac, (int)&w_a0, (int)&w_a8);
    f_05e2d0(NA(d_1c38b0), -1, 300, -1, 1);
    palette = 0;
    f_05e360(NA(d_1c38b0), (int)&col_fg, (int)&col_bg);
    setcolors(NA(d_1c38b0), 255, -1);
    if (text) {
        text_buf = C0bdd50_4(NA(d_1c11b8), 0x2000, NA(d_1a6c10), 0x307);
        C0e93f0_3(NA(d_1c38b0), text_buf, text);
        signed char *p = (signed char *)C05e490_2(NA(d_1c38b0), text_buf);
        line_count = 1;
        C0e9680_2(NA(d_1c38b0), (int)p);
        lines.p[0] = (char *)p;
        short len = strlen((char *)p);
        while (len > 0) {
            if (*p == 13 || *p == 64) {
                *p++ = 0;
                len--;
                if (*p == 10) {
                    p++;
                    len--;
                }
                lines.p[line_count++] = (char *)p;
            } else {
                p++;
                len--;
            }
        }
    }
    if (flags & 1) {
        C09a140_2(0, 25);
        C09a0d0_1((int)d_1a34e0);
    }
    C149e2e_2((int)rgb, 255);
    if (C146d36_1(NA(d_1c2edc)) == 1) {
        signed char flag_ae0 = d_1bfae0;
        if (flag_ae0 == 1) {
            mem = 0xfe400;
        }
    }
    C14a0b0_0();
    movie = (MovieState10bd70 *)C14bb40_3(name, mem + 0x1000, -1);
    if (!movie) goto done;
    buffer = (char *)C014540_3(movie->width * movie->height, NA(d_1a6c10), 0x339);
    if (!buffer) goto done;
    if ((unsigned char)C11e760_2(movie->width, movie->height)) {
        if (text) {
            step = movie->frames / line_count;
            for (signed char i = 0; i < line_count; i++) {
                frames.f[i] = i * step;
            }
        }
        cur_line = 0;
        C14a940_7((int)movie, 0, 0, movie->width, movie->height, (int)buffer, 0);
        for (frame = 0; frame < movie->frames; frame++) {
            text_buf |= text_buf & 0; palette |= palette & 0; // haelt text_buf und palette im Schleifenkopf lebendig
            C14b3d0_1((int)movie);
            while (C14a1d0_2((int)movie, 0)) {
                result |= result & 0; palette |= palette & 0; // haelt result und palette in der inneren Schleife lebendig
                cur_line = (cur_line & 0) ? (signed char)0 : cur_line; // verhindert Spill/Reload-Verschiebung von cur_line
                if (movie->paletteChanged && !palette) {
                    C099ea0_0();
                    C14d040_1((int)movie->palette);
                    C149e2e_2((int)rgb, 255);
                    palette = 1;
                }
                C11e910_8((int)buffer, movie->left, movie->top, movie->rectWidth, movie->rectHeight, movie->width, movie->left, movie->top);
            }
            text_buf |= text_buf & 0; // verhindert vorzeitiges Spillen von text_buf nach der inneren Schleife
            palette = 0;
            if (frame != movie->frames) {
                C14b100_1((int)movie);
            }
            if (text && frames.f[cur_line] == frame) {
                int line_offset = cur_line * 4;
                line_offset |= line_offset & 0; // haelt line_offset als Registerwert fuer den Arrayzugriff
                if (*(char **)((char *)&lines + line_offset)) {
                f_145300(d_1a34e0 + 0xe38a, 0, 0xc80);
                C149e2e_2((int)rgb, 255);
                C0e9660_4(NA(d_1c38b0), (int)*(char **)((char *)&lines + line_offset), 10, 0xb6);
                cur_line++;
                }
            }
            do {
                if (C0d3780_0() == 1 || C0d37b0_0() == 1) {
                    while (C0d3780_0() == 1 || C0d37b0_0() == 1) {}
                    result = 1;
                    goto close_movie;
                }
                if (_bios_keybrd(_KEYBRD_READY)) {
                    d_1bd762 = _bios_keybrd(_KEYBRD_READ);
                    if ((unsigned short)d_1bd762 == 0x11b) {
                        result = 1;
                        goto close_movie;
                    }
                }
            } while (C149f90_1((int)movie));
        }
    }
close_movie:
    C14b7b0_1((int)movie);
    f_145300(d_1a34e0 + 0xe38a, 0, 0xc80);
    if (buffer) C014710_1((int)buffer);
done:
    if (flags & 2) {
        C09a140_2(0, 25);
    }
    if (text_buf) {
        C0bdde0_4(NA(d_1c11b8), text_buf, NA(d_1a6c10), 0x3a9);
    }
    setfont(NA(d_1c38b0), saved_font);
    f_05e2d0(NA(d_1c38b0), w_a0, w_ac, w_a0, w_a8);
    setcolors(NA(d_1c38b0), col_fg, col_bg);
    return result;
}
