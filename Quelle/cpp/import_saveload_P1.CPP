/* === Beschreibung (Katalog) ===
 * Einheit import_saveload (0x15FFA0 - 0x160C90)
 *
 * Überblick
 * Die Einheit import_saveload gehört zur 3D-Dungeon-Engine und verantwortet das Serialisieren (f_15fffc) und
 * Deserialisieren (f_160320) des gesamten veränderlichen 3D-Szenenzustands (veränderte 3D-Objekte,
 * 240-Byte-Zonenbereichstabelle d_1c6c78 und 3D-Sprite-Zustände) sowie das Laden, Skalieren und Kacheln von
 * 3D-Wand- und Objekttexturen (f_160790).
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -fp5
#pragma aux f_160790 "f_160790";
// CC wcc386
#include "R_FIX.H"
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
extern unsigned char d_1a9933[];
extern unsigned char d_1a993d[];
extern unsigned char d_1a9940[];
extern unsigned char d_1a996a[];
extern unsigned char d_1a9970[];
extern unsigned char d_1a9984[];
extern unsigned char d_1a9988[];
extern unsigned char d_1a99ac[];
extern unsigned char d_1a99f0[];
extern unsigned char d_1a9a1c[];
extern unsigned char d_1a9ae0[];
extern unsigned char d_1a9aec[];
extern unsigned char d_1a9af0[];
extern unsigned char d_1a9afc[];
extern unsigned char d_1a9b18[];
extern unsigned char d_1a9b34[];
extern unsigned char d_1a9b40[];
extern unsigned char d_1c6c78[];
extern unsigned char d_1c90c0[];
extern unsigned char d_1cd088[];
extern unsigned char d_1cd1f8[];
extern unsigned char d_1cd210[];
extern unsigned char d_1cdc22[];
extern unsigned char d_1cdc24[];
#pragma aux f_144bf0 "*";
int f_148143();
#pragma aux f_148143 "*";
int f_155f70();
#pragma aux f_155f70 "*";
#pragma aux f_156370 "*";
undefined4 f_15ffa0();
#pragma aux f_15ffa0 "*";
undefined4 f_15fffc();
#pragma aux f_15fffc "*";
undefined4 f_160320();
#pragma aux f_160320 "*";
int f_164880();
#pragma aux f_164880 "*";
#pragma aux f_165de2 "*";

// Astra630: Rümpfe ohne Ghidra-Funktion, direkt aus belege/ORIGINAL.lst.
// Dies ist eine Sammlung zum Verteilen in die passenden neuen Einheiten.
#include <string.h>
#include <i86.h>
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NUW(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern int d_1a996c,d_1a9a34;
extern unsigned char d_1cd1e0[];
extern char d_1b9678[],d_1b967c[],d_1b9688[],d_1b9adc[];
void *f_15e469(const char *,const char *);
int f_1452bc(int);
void *f_156370(int,const char *,const char *,int);
void f_1563a8(void *);
int f_15e65b(void *,int,int,void *);
void f_15e836(void *);
void f_163050(const char *);
int f_177910(const char *,int *,int *);
int __cdecl f_16d4fc(int,int,int);
int __cdecl f_16d818(unsigned short);
int f_165de2(void);
extern char d_1cd0b0[],d_1b9670[];
extern char *d_1cd200;
extern int d_1a9a4c,d_1cdb8c,d_1cdb84,d_1cdb80,d_1cdb7c;
extern unsigned char d_1a994a;
char *f_177e30(const char *);
char *f_1781c8(unsigned char,int,int,int,int);
void f_1782e8(void *);
int f_144bf0(const char *,const char *);
void f_162c64(int,int,int,int,char *,char *);
void f_162cc0(int,int,int,int,char *,char *);
void f_162d28(int,int,int,int,char *,char *);


char *f_160790(const char *name);
extern char d_1b9664[],d_1b9658[];
// Herkunft: Analyse/ghidra/fz_15ffa0.c; Datenfluss/Typen am Original prüfen.
//@ f_15ffa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft anhand von vier Kriterien (used an +6 != 0, value an +16 != 0, Bits 0x360 in flags
 *   an +10 gesetzt oder state an +0 == 0), ob ein 3D-Szenenobjekt p1 gegenüber seinem Ausgangszustand verändert
 *   wurde und deshalb in das 3D-Speicherabbild aufgenommen werden muss.
 * - Eingaben: p1 (Zeiger auf eine 48-Byte-Object-Struktur der 3D-Szene).
 * - Rückgabewert: 1, wenn das 3D-Objekt verändert wurde und gespeichert werden muss, sonst 0.
 * - Wichtige Variablen:
 *   - *(short *)(p1 + 6) (used), *(int *)(p1 + 16) (value), *(ushort *)(p1 + 10) (flags), p1[0] (state).
 === Ende Beschreibung === */
undefined4 f_15ffa0(char *p1)
{
  if (*(short *)(p1 + 6) != 0) {
    return 1;
  }
  if (*(int *)(p1 + 0x10) != 0) {
    return 1;
  }
  if ((*(ushort *)(p1 + 10) & 0x360) != 0) {
    return 1;
  }
  if (*p1 == '\0') {
    return 1;
  }
  return 0;
}

// Herkunft: Analyse/ghidra/fz_15ffa0.c; Datenfluss/Typen am Original prüfen.
#pragma aux f_15ffd8 "*";
//@ f_15ffd8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt ein 3D-Szenenobjekt p beim Laden eines Spielstands auf seinen unveränderten
 *   Grundzustand zurück (used = 0, value = 0, Bits 0x360 in flags gelöscht, state = 1).
 * - Eingaben: p (Zeiger auf eine 48-Byte-Object-Struktur der 3D-Szene).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p[0], *(short *)(p + 6), *(ushort *)(p + 10), *(int *)(p + 16).
 === Ende Beschreibung === */
void f_15ffd8(char *p)
{
 *(short *)(p+6)=0;
 *(int *)(p+16)=0;
 *(unsigned short *)(p+10)&=~0x360;
 p[0]=1;
}

//@ f_15fffc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erstellt ein zusammenhängendes Speicherabbild des aktuellen 3D-Dungeons: Zählt alle
 *   veränderten Szenenobjekte (f_15ffa0), reserviert einen Puffer head für den Header (Versionskennung
 *   0x350e34c0, Kameraposition, Licht-/Umgebungswerte), die active gespeicherten SavedObject-Einträge (je 28
 *   Bytes), die 240 Bytes große Bereichstabelle d_1c6c78 sowie 3 SavedSprite-Einträge und gibt Zeiger und Größe
 *   über *p1 und *p2 zurück.
 * - Eingaben: p1 (Ausgabezeiger für die Adresse des erzeugten Speicherabbilds), p2 (Ausgabezeiger für die Größe
 *   des Speicherabbilds in Bytes).
 * - Rückgabewert: 0 bei Erfolg, oder ein Fehlercode (0xf001 = Speichermangel, 0xf002 / 0xf00c = Engine nicht
 *   bereit, 0xf005 = ungültige Parameter; wird zugleich in d_1a996c abgelegt).
 * - Wichtige Variablen:
 *   - d_1cd210, d_1a99ac: Zeiger auf das Array der 3D-Szenenobjekte und deren Gesamtanzahl.
 *   - d_1c6c78, d_1cd1f8: 240-Byte-Zonentabelle (10 Bereiche zu je 24 Bytes) und aktueller Bereichszeiger.
 *   - d_1cd1e0: Zeiger auf das Array der 3D-Sprites.
 === Ende Beschreibung === */
undefined4 f_15fffc(undefined4 *p1,int *p2)
{
  struct V3 { int x,y,z; };
  struct Block24 { int x[6]; };
  struct Header {
    char text[30]; short game,active,count;
    int version,a,b,c;
    struct Block24 state;
    int objects,areas,sprites;
    short mode,pad5a;
    int v5c,v60,v64,v68,v6c;
    short v70,v72,v74,v76,area,pad7a;
    int zero1,zero2,zero3;
  };
  struct Object {
    char state,pad1; short id;
    short pad4,used,pad8,flags,count,pade;
    int value; char pad14[20]; char **name; int pad2c;
  };
  struct SavedObject {
    char tag,name[11],state,padd;
    short used,id,flags,count,pad16;
    int value;
  };
  struct Sprite {
    int pad0; char a,b,c,pad7; short pad8,d;
    int padc,e,pad14,f,pad1c,pad20;
    struct V3 v24,v30,v3c,v48;
    int pad54;
  };
  struct SavedSprite {
    char a,b,c,pad3; short d,pad6;
    int e,f; struct V3 pos,dir;
  };
  struct Header *head;
  struct Object *obj;
  struct SavedObject *out;
  int size;
  struct Sprite *sp;
  struct SavedSprite *dest;
  int i;
  int active;
  struct Header *saved;

  if (!d_1a993d[0]) { d_1a996c=0xf002; return 0xf002; }
  if (!d_1a9940[0]) { d_1a996c=0xf00c; return 0xf00c; }
  if (!p1 || !p2) { d_1a996c=0xf005; return 0xf005; }
  obj=*(struct Object **)d_1cd210;
  active=0;
  for(i=0;i<*(int *)d_1a99ac;i++,obj++) {
    if(f_15ffa0((char *)obj)) active++;
  }
  size=sizeof(struct Header)+active*sizeof(struct SavedObject)+240+3*sizeof(struct SavedSprite);
  head=(struct Header *)f_156370(size,d_1b9664,d_1b9658,10);
  if (!head) { d_1a996c=0xf001; return 0xf001; }
  saved=head;
  out=(struct SavedObject *)(head+1);
  strcpy(head->text,(char *)d_1cd088);
  head->game=*(short *)d_1a996a;
  head->version=0x350e34c0;
  head->a=*(int *)d_1a9aec;
  head->b=*(int *)d_1a9af0;
  head->c=*(int *)d_1a9b18;
  head->active=active;
  head->count=*(int *)d_1a99ac;
  head->state=*(struct Block24 *)d_1c90c0;
  head->mode=*(short *)d_1a9970;
  head->objects=(char *)out-(char *)head;
  head->v5c=*(int *)d_1a9a1c;
  head->v60=*(int *)d_1a9afc;
  head->v64=*(int *)d_1a9ae0;
  head->v68=*(int *)d_1a9b34;
  head->v6c=*(int *)d_1a9b40;
  head->v70=*(short *)d_1a9984;
  head->v72=*(short *)d_1a9988;
  head->v74=*(short *)d_1cdc22;
  head->v76=*(short *)d_1cdc24;
  head->area=(*(char **)d_1cd1f8-(char *)d_1c6c78)/24;
  head->zero1=0;
  head->zero2=0;
  head->zero3=0;
  obj=*(struct Object **)d_1cd210;
  for(i=0;i<*(int *)d_1a99ac;i++,obj++) {
    if (f_15ffa0((char *)obj)) {
      f_148143(out->name,(undefined4)*obj->name,10);
      out->name[10]=0;
      out->state=obj->state;
      out->used=obj->used;
      out->count=obj->count;
      out->flags=obj->flags;
      out->id=obj->id;
      out->value=obj->value;
      out++;
    }
  }
  saved->areas=(char *)out-(char *)saved;
  memcpy(out,d_1c6c78,240);
  dest=(struct SavedSprite *)((char *)out+240);
  sp=*(struct Sprite **)d_1cd1e0;
  saved->sprites=(char *)dest-(char *)saved;
  for(i=0;i<3;i++,dest++,sp++) {
    dest->a=sp->a;
    dest->b=sp->b;
    dest->c=sp->c;
    dest->d=sp->d;
    dest->e=sp->e;
    dest->f=sp->f;
    if (sp->b==2) { dest->pos=sp->v3c; dest->dir=sp->v48; }
    else { dest->pos=sp->v24; dest->dir=sp->v30; }
  }
  *p1=(undefined4)saved;
  d_1a996c=0;
  *p2=size;
  return 0;
}

// Herkunft: Analyse/ghidra/fz_15ffa0.c; Datenfluss/Typen am Original pruefen.
//@ f_160320
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest ein zuvor mit f_15fffc erzeugtes 3D-Szenen-Speicherabbild p1 wieder ein, prüft die
 *   Versionskennung (unterstützt acht historische Formatversionen von 0x75bcd15 bis 0x350e34c0) und den
 *   Szenennamen (d_1cd088), übernimmt die globalen Kamera-, Licht- und Bereichsparameter, gleicht alle
 *   Szenenobjekte über ID und Namen mit den gespeicherten SavedObject-Einträgen ab (nicht gespeicherte Objekte
 *   werden per f_15ffd8 zurückgesetzt) und restauriert die 240-Byte-Zonentabelle d_1c6c78 sowie die 3
 *   Sprite-Zustände.
 * - Eingaben: p1 (Zeiger auf den Puffer des geladenen 3D-Szenen-Speicherabbilds).
 * - Rückgabewert: 0 bei Erfolg, sonst ein Fehlercode (0xf002, 0xf005, 0xf00c, 0xf00e = falscher Szenenname,
 *   0xf00f = inkompatible Version).
 * - Wichtige Variablen:
 *   - head->version: Versionsstempel des geladenen 3D-Abbilds (steuert die Abwärtskompatibilität für ältere
 *     Felder).
 *   - d_1a996c: Globale Fehlerstatusvariable der 3D-Engine.
 === Ende Beschreibung === */
undefined4 f_160320(int p1)
{
  struct V3 { int x,y,z; };
  struct Block24 { int x[6]; };
  struct Header {
    char text[30]; short game,active,count;
    int version,a,b,c;
    struct Block24 state;
    int objects,areas,sprites;
    short mode,pad5a;
    int v5c,v60,v64,v68,v6c;
    short v70,v72,v74,v76,area,pad7a;
    int zero1,zero2,zero3;
  };
  struct Object {
    char state,pad1; short id;
    short pad4,used,pad8,flags,count,pade;
    int value; char pad14[20]; char **name; int pad2c;
  };
  struct SavedObject {
    char tag,name[11],state,padd;
    short used,id,flags,count,pad16;
    int value;
  };
  struct Sprite {
    int pad0; char a,b,c,pad7; short pad8,d;
    int padc,e,pad14,f,pad1c,pad20;
    struct V3 v24,v30,v3c,v48;
    int pad54;
  };
  struct SavedSprite {
    char a,b,c,pad3; short d,pad6;
    int e,f; struct V3 pos,dir;
  };
  struct Header *head;
  char *areas, *objects;
  struct SavedSprite *sprites;
  struct SavedObject *so;
  struct Object *obj;
  struct Sprite *sp;
  int count, i, j, missing;

  if (!d_1a993d[0]) { d_1a996c=0xf002; return 0xf002; }
  if (!d_1a9940[0]) { d_1a996c=0xf00c; return 0xf00c; }
  if (!p1) { d_1a996c=0xf005; return 0xf005; }
  head=(struct Header *)p1;
  if (head->version!=0x75bcd15 && head->version!=0xdfb38d2 && head->version!=0x149aa435 &&
      head->version!=0x1b3a0c14 && head->version!=0x21d950cb && head->version!=0x287735f2 &&
      head->version!=0x2f075f79 && head->version!=0x350e34c0) {
    d_1a996c=0xf00f; return 0xf00f;
  }
  if (f_144bf0(head->text,(char *)d_1cd088)) {
    d_1a996c=0xf00e; return 0xf00e;
  }
  if ((unsigned)head->version<0x149aa435) {
    *(struct Block24 *)d_1c90c0=head->state;
    f_155f70(d_1c90c0);
    d_1a9933[0]=1; NI(d_1a99f0,0)=0; d_1a996c=0xf00f;
    return 0xf00f;
  }
  areas=(char *)(head->areas+p1);
  sprites=(struct SavedSprite *)(head->sprites+p1);
  objects=(char *)(head->objects+p1);
  NW(d_1a996a,0)=head->game;
  NI(d_1a9aec,0)=head->a;
  NI(d_1a9af0,0)=head->b;
  NI(d_1a9b18,0)=head->c;
  *(struct Block24 *)d_1c90c0=head->state;
  NI(d_1a9970,0)=(unsigned short)head->mode;
  if ((unsigned)head->version>=0x1b3a0c14) {
    NI(d_1a9a1c,0)=head->v5c;
    NI(d_1a9afc,0)=head->v60;
  }
  if ((unsigned)head->version>=0x21d950cb) NI(d_1a9ae0,0)=head->v64;
  if ((unsigned)head->version>=0x287735f2) {
    NI(d_1a9b34,0)=head->v68;
    NI(d_1a9b40,0)=head->v6c;
  }
  if ((unsigned)head->version>=0x2f075f79) f_164880(head->v70,head->v72,head->v74,head->v76);
  if ((unsigned)head->version>=0x350e34c0)
    NI(d_1cd1f8,0)=(int)(d_1c6c78+24*((unsigned short)head->area%10));
  obj=*(struct Object **)d_1cd210;
  count=(unsigned short)head->active;
  so=(struct SavedObject *)objects;
  for(i=0;i<count;i++,so++) so->tag=0;
  for(j=0;j<NI(d_1a99ac,0);j++,obj++) {
    missing=1;
    so=(struct SavedObject *)objects;
    for(i=0;i<count;so++) {
      if (so->tag==0) {
        i++;
        if (so->id==obj->id && obj->name && !f_144bf0(so->name,*obj->name)) {
          obj->state=so->state;
          obj->flags=so->flags;
          obj->value=so->value;
          obj->used=so->used;
          count--;
          obj->count=so->count;
          missing=0;
          so->tag=1;
          break;
        }
      }
    }
    if (missing) f_15ffd8((char *)obj);
  }
  if (areas) memcpy(d_1c6c78,areas,240);
  if (sprites && *(struct Sprite **)d_1cd1e0) {
    sp=*(struct Sprite **)d_1cd1e0;
    i=0;
    while(i<3) {
      sp->a=sprites->a;
      sp->b=sprites->b;
      sp->c=sprites->c;
      sp->d=sprites->d;
      sp->e=sprites->e;
      sp->f=sprites->f;
      if (sp->b==2) {
        sp->v3c=sprites->pos;
        if ((unsigned)head->version>=0x21d950cb || sp->c!=1 || sp->pad0==0) sp->v48=sprites->dir;
        else {
          sp->v48.x=f_165de2()&3;
          sp->v48.y=0;
          sp->v48.z=(unsigned short)sp->d;
        }
      } else {
        sp->v24=sprites->pos;
        sp->v30=sprites->dir;
      }
      i++; sp++; sprites++;
    }
  }
  f_155f70(d_1c90c0);
  d_1a9933[0]=1;
  NI(d_1a99f0,0)=0;
  d_1a996c=0;
  return 0;
}

#define ZWORD1(p,o) (u1.full=0,u1.word=NUW(p,o),(int)u1.full)
#define ZWORD2(p,o) (u2.full=0,u2.word=NUW(p,o),(int)u2.full)
#define ZBYTE1(p,o) (u1.full=0,u1.byte=NB(p,o),(int)u1.full)
//@ f_160790
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt eine 3D-Texturdatei (d_1cd0b0 + name + d_1b9670) über f_177e30, prüft anhand der
 *   Animations-/Texturset-Tabelle d_1cd200 (d_1a9a4c Einträge), ob die Textur aus mehreren Einzelbildern (count
 *   = source->w / set->w) besteht, halbiert bei aktivem Textur-Verkleinerungsflag d_1a994a die Abmessungen
 *   schrittweise, bis Breite und Höhe maximal 128 Pixel betragen (shrink), reserviert den Zieltexturplatz über
 *   f_1781c8 und kopiert bzw. skaliert alle Einzelbilder über f_162c64 (1:1), f_162cc0 (1:2) oder f_162d28
 *   (1:4). *(Hinweis: Enthält mehrere Original-Programmierfehler bei d->h = d->w = w sowie im default-Zweig für
 *   shrink >= 3; siehe Fehlerliste).*
 * - Eingaben: name (Name der zu ladenden Textur ohne Pfad und Erweiterung).
 * - Rückgabewert: Zeiger auf die fertig eingerichtete 3D-Texturstruktur dest (char *).
 * - Wichtige Variablen:
 *   - d_1cd200, d_1a9a4c: Tabelle der mehrteiligen Textur-Sets (Set) und deren Anzahl.
 *   - d_1a994a: Flag zur automatischen Halbierung großer Texturen (> 128 Pixel).
 *   - d_1cdb8c, d_1cdb84, d_1cdb80, d_1cdb7c: Textur-Kachelcursor für 64x64-, 128x128- und 256x256-Texturseiten.
 === Ende Beschreibung === */
char *f_160790(const char *name)
{
  struct Tex {
    int pad0; char *data; char pad8[8];
    short scale; unsigned char tag, flags; int pad14;
    unsigned short w, h, hw, hh;
  };
  struct Set { char name[26]; unsigned short n, w, h; int *list; };
  char path[256];
  struct Box { struct Tex *source; int pad; } box; /* KRUECKE */
  struct Tex *dest;
  struct Set *set;
  int *cursor;
  char *src, *dst;
  int count, w, h, step, ow, i;
  char *shrink; /* KRUECKE */
  char found;
  struct Tex *d;

  strcpy(path,d_1cd0b0);
  strcat(path,name);
  strcat(path,d_1b9670);
  box.source=(struct Tex *)f_177e30(path);
  if (!box.source) return (char *)box.source;
  count=1;
  set=(struct Set *)d_1cd200;
  found=0;
  for(i=0;i<d_1a9a4c;i++,set++) {
    if (f_144bf0(set->name,name)==0) {
      count=box.source->w/set->w;
      if (set->n<count) count=set->n;
      if (set->n>count) set->n=count;
      found=1;
      break;
    }
  }
  if (found) { ow=w=set->w; name=(const char *)(h=set->h); /* KRUECKE: Parameter ab hier als Hoehe */ }
  else { ow=w=box.source->w; name=(const char *)(h=box.source->h); /* KRUECKE */ }
  shrink=0;
  if (d_1a994a) {
    while (128<w || 128<h) {
      shrink++;
      w>>=1;
      h>>=1;
    }
  }
  if (w<=64 && h<=64) { step=64; cursor=&d_1cdb8c; }
  else if (w<=128 && h<=128) { step=128; cursor=&d_1cdb84; }
  else if (w<=256 && h<=256) { step=256; cursor=&d_1cdb80; }
  else { step=256; cursor=&d_1cdb7c; }
  dest=(struct Tex *)f_1781c8(box.source->tag,w,h,*cursor,0);
  if (!dest) return (char *)box.source;
  for(i=0;i<count;i++) {
    if (found) { int loc=*cursor; set->list[i]=loc; }
    if (*(unsigned char *)cursor+step>=256) *cursor+=(step<<8)-256+step;
    else *cursor+=step;
  }
  d=dest;
#if FIX_R008   /* R008: Texturhoehe d->h auf h statt w setzen */
  d->w=w;
  d->h=h;
#else
  d->h=d->w=w;
#endif
  d->hw=w>>1;
  d->scale=256;
  d->hh=h>>1;
  if (found) d->flags|=0x80; else d->flags&=0x7f;
  src=box.source->data;
  for(i=0;i<count;i++) {
    dst=found ? (char *)set->list[i] : dest->data;
    switch ((int)shrink) {
    case 0: f_162c64(ow,(int)name,box.source->scale,dest->scale,src,dst); break;
    case 1: f_162cc0(ow,(int)name,box.source->scale,dest->scale,src,dst); break;
    case 2: f_162d28(ow,(int)name,box.source->scale,dest->scale,src,dst); break;
    default:
#if FIX_R008   /* R008: shrink fuer Folgeframes erhalten und Abmessungen je Halbierungsschritt mitfuehren */
      {
        int sh=(int)shrink, cw=ow, ch=(int)name;
        for (;sh>1;sh--,cw>>=1,ch>>=1) {
          f_162cc0(cw,ch,box.source->scale,box.source->scale,src,src);
        }
        f_162cc0(cw,ch,box.source->scale,dest->scale,src,dst);
      }
#else
      for (;(int)shrink>0;shrink--) {
        f_162cc0(ow,(int)name,box.source->scale,box.source->scale,src,src);
      }
      f_162cc0(ow,(int)name,box.source->scale,dest->scale,src,dst);
#endif
      break;
    }
    if (found) src+=ow;
  }
  f_1782e8(box.source);
  return (char *)dest;
}

