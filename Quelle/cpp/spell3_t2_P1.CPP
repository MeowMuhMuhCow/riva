/* === Beschreibung (Katalog) ===
 * Einheit spell3_t2 (0x110690 - 0x110d90)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil des Moduls spell3.cpp und implementiert den Tierheilzauber *Tiere
 * besprechen* (0x26), die eigenschaftssteigernden Zauber (0x2e bis 0x35, wie *Axxeleratus*,
 * *Attributo*-Varianten) sowie den Verwandlungszauber *Visibili Vanitar* (0x53).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// OPT -4r -onetx -zp1 -s
// P3 9/16 gleich (suche.py 28.10.2026, Basis spell3_P1.CPP)
// spell3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10F910-0x110D90
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0366e0(int p1, int p2, int p3, int p4);
short f_0398c0(int p1, int p2, int p3);
short f_03d3d0(int p1, int p2, int p3);
int f_040e00(int p1);                                   // reg eax stapel 0









                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
signed char f_0435c0(int p1, int p2);
int f_043c80(int p1);                                   // reg eax stapel 0
int f_043f00(int p1);                                   // reg eax stapel 0
int f_044890(int p1, int p2, int p3, int p4);
int f_08ab50(int p1);
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
signed char f_0cf950(int p1);
short f_0cf9f0(int p1);
short f_0cfa10(int p1);
short f_0cfa30(int p1);
short f_0cfa50(int p1);
signed char f_0cfa70(int p1);
unsigned char f_0cfab0(int p1);
signed char f_0cfcc0(int p1);
int f_0d07e0(int p1, int p2, int p3, int p4);
signed char f_0d11e0(int p1);
signed char f_0d1250(int p1);
short f_0d4aa0(int p1, int p2);
short f_0d4b00(int p1);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0dcf00(int p1, int p2, int p3);
short f_0de800(int p1);
short f_0de820(int p1);
int f_0e93f0(int p1, int p2, int p3);
int f_10d5e0(int p1, int p2);                           // reg eax edx stapel 0
int f_10d640(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
short f_149360(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a7a0c;                    // 0x1A7A0C
extern int d_1bd6c0;                    // 0x1BD6C0
extern short d_1bd90c;                    // 0x1BD90C
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0420;                    // 0x1C0420
extern int d_1c0424;                    // 0x1C0424
extern signed char d_1c21b4;                    // 0x1C21B4
extern int d_1c24d4;                    // 0x1C24D4
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c2a80;                    // 0x1C2A80
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a7858[];           // Text 0x1A7858
// --- eigene Funktionen (16), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern short d_1a0dc8[]; extern short d_1a7876[]; extern short d_1a7884[]; extern short d_1a7886[]; extern int d_1a7888[];
extern short d_1c042a; extern signed char d_1c0904;
extern int d_1c0908;
extern unsigned short d_1c0428;
extern int d_1c349c, d_1c3870, d_1c38b0, d_1c3498, d_1c27a8;
extern const char d_1a7858[];
struct OB {int a; int b[13]; short s38;};
struct S14 {int a[5];};
typedef short (*VF)(int,int);
#define VC(p,off,a) ((*(VF*)(*(int*)((p)+8)+(off)))((p),(a)))
#define P(p,o) (*(int*)((p)+(o)))
#define W(p,o) (*(short*)((p)+(o)))
#define CH(p,o) ((int)*(signed char*)((p)+(o)))
#define D2C64 ((int)&d_1c2c64)
#define D21B4 ((int)&d_1c21b4)
#define D24D4 ((int)&d_1c24d4)
#define D27A8 ((int)&d_1c27a8)
#define D38B0 ((int)&d_1c38b0)
#define D3498 ((int)&d_1c3498)
#define M(x) f_0bf730(D2C64, x)
#define E93(a,b,c) f_0e93f0(D38B0, a, c)
#define OBC(o) f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, D3498)
#define OBD(o) f_1254a0((int)&o, 0)
#define OBCTOR OBC(ob)
#define OBDTOR OBD(ob)
#define SB(k,v) *(int*)(ob.b[k]+4) = (v)
#define SBO(o,k,v) *(int*)(o.b[k]+4) = (v)
#define SBI(o,k,off) (o.b[k]+(off))

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_110690
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Tiere besprechen* (0x26), der ähnlich wie *Balsam Salabunde* Lebenspunkte
 *   heilt, jedoch ausschließlich auf tierische Begleiter angewendet werden kann und bei menschlichen Zielen mit
 *   einer Fehlermeldung abbricht.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_110690(int p1)
{
  OB ob2, ob1;
  OBC(ob1);
  switch ((unsigned short)d_1c0428) {
  case 1:
    if ((int)f_03d3d0(P(p1,0x12), 0x27, CH(p1,4)) > 0) {
      SBO(ob1, 0, P(p1,0x12));
      M(0x1700000c);
    } else {
      W(p1,2) = 5;
      W(p1,0) = -2;
    }
    break;
  case 3:
    if ((int)f_03d3d0(P(p1,0x12), 0x27, CH(p1,4)) > 0) {
      SBO(ob1, 0, P(p1,0x12));
      int current = W(p1,0);
      if ((int)f_0429a0((struct hero *)(P(p1,0x12))) > current + 0x3c)
        M(0x17000008);
      else M(0x17000007);
    } else {
      W(p1,2) = 5;
      W(p1,0) = -2;
    }
    break;
  default: {
    OBC(ob2);
    int found = 0;
    short selection = f_032820(P(p1,0x12), 0x20000103, 1);
    if ((int)selection != -1) {
      short item = f_042a60((struct hero *)(P(p1,0x12)), (int)selection);
      if (item != (short)0) {
        short power;
        if (d_1c0420 == 0) power = f_03d3d0(P(p1,0x12), 0x27, CH(p1,4));
        else power = 99;
        if ((int)power < 0) {
          f_0e93f0(D38B0, D27A8, 0x17000045);
          W(p1,0) = -2;
        } else {
          f_0e93f0(D38B0, D27A8, 0x17000042);
          if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7a90() != 0)
            f_0e93f0(D38B0, D27A8, 0x1700008d);
          short i = 0;
          while ((int)d_1a7884[(int)i * 4] != -1) {
            if (item == d_1a7884[(int)i * 4]) {
              found = 1;
              if (power >= d_1a7886[(int)i * 4]) {
                int selected = (int)selection;
                f_0e93f0(D38B0, D27A8, d_1a7888[(int)i * 2]);
                f_042f20((struct hero *)(P(p1,0x12)), selected, 1);
                f_042eb0((struct hero *)(P(p1,0x12)), selected, 1);
              } else {
                f_0e93f0(D38B0, D27A8, 0x17000045);
              }
              break;
            }
            ++i;
          }
          SBO(ob2, 0, P(p1,0x12));
          int text = f_133fe0(D3498, D27A8);
          SBO(ob2, 3, text);
          int matched = found;
          f_0e93f0(D38B0, D21B4, 0x17000043);
          if (!matched && power != (short)0) {
            int selected = (int)selection;
            f_042f20((struct hero *)(P(p1,0x12)), selected, 1);
            f_042eb0((struct hero *)(P(p1,0x12)), selected, 1);
          }
        }
      } else {
        W(p1,0) = -4;
        d_1c21b4 = 0;
      }
    } else {
      W(p1,0) = -4;
      d_1c21b4 = 0;
    }
    OBD(ob2);
    break;
  }
  }
  OBD(ob1);
}

//@ f_110980
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Hellsichtzauber *Exposami* / *Eigenschaften* für ein gegnerisches Kampfwesen P(p1,
 *   0x1a): Die Funktion liest Stufe, Lebenspunkte, Astralenergie, Rüstungsschutz, MR, Angriffs-/Paradewerte und
 *   Schadenswürfel des Ziels über die Zugriffsfunktionen f_0cf950..f_0d1250 sowie f_0d07e0 aus, trägt sie in die
 *   Textplatzhalter ob.b[3..6] ein und gibt das Analysefenster (0x17000029) über f_0e93f0 aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt mit Zielwesen P(p1, 0x1a)).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: ob (Textkontext OB mit den Zahlenfeldern ob.b[4] und ob.b[5]), xa, xb (Schadensbereich
 *   aus f_0d07e0).
 === Ende Beschreibung === */
void f_110980(int p1)
{
  struct OB ob; int xa; int xb;
  OBCTOR;
  f_0d07e0(P(p1,0x1a), 0, (int)&xb, (int)&xa);
  SB(1, P(p1,0x1a));
  W(ob.b[6],2) = 1;
  W(ob.b[4],2) = f_0cfcc0(P(p1,0x1a));
  W(ob.b[4],4) = f_0d11e0(P(p1,0x1a));
  W(ob.b[4],6) = f_0d1250(P(p1,0x1a));
  W(ob.b[4],8) = f_0cf950(P(p1,0x1a));
  W(ob.b[4],0xa) = f_0cfa70(P(p1,0x1a));
  W(ob.b[4],0xc) = (signed char)f_0cfab0(P(p1,0x1a));
  W(ob.b[4],0xe) = xb;
  W(ob.b[4],0x10) = xa;
  P(ob.b[5],4) = f_0cfa10(P(p1,0x1a));
  P(ob.b[5],8) = f_0cf9f0(P(p1,0x1a));
  P(ob.b[5],0xc) = f_0cfa50(P(p1,0x1a));
  P(ob.b[5],0x10) = f_0cfa30(P(p1,0x1a));
  P(ob.b[3],4) = ((signed char)f_0cfab0(P(p1,0x1a)) > 1) ? 0x1700002a : 0x1700002b;
  f_0e93f0(D38B0, D21B4, 0x17000029);
  OBDTOR;
}
//@ f_110ae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert den Hellsichtzauber *Odem Arcanum* / *Penetrizzel* (0x29): Im Dungeon-/Automap-Modus
 *   (d_1bd90c != 0) wird direkt f_08ab50(d_1bd914) aufgerufen; andernfalls wird bei gültigem Szenenobjekt
 *   d_1bd6c0 und freiem Gruppenstatus (f_0de800 == -1) der Zaubereffekt 0x29 für den Zaubernden P(p1, 0x12) über
 *   f_10d5e0 und f_10d640 sowie die virtuelle Szenenmethode +0x2c ausgelöst.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd6c0 (aktives Szenen-/Interaktionsobjekt), d_1c0424 (Flag für ausgelösten
 *   Szeneneffekt).
 === Ende Beschreibung === */
void f_110ae0(int p1)
{
  extern int d_1bd914;
  unsigned char bVar1; short sVar2;
  if (d_1bd90c != (short)0) { f_08ab50(d_1bd914); return; }
  sVar2 = f_0de800(d_1c0004);
  if (sVar2 == -1 && d_1bd6c0 != 0) {
    sVar2 = VC(d_1bd6c0, 0x28, 0x29);
    if (sVar2 != 0) {
      bVar1 = ((unsigned char)(f_042380((struct hero *)(P(p1,0x12)))));
      f_10d5e0(0x29, bVar1);
      f_10d640(0x29);
      VC(d_1bd6c0, 0x2c, 0x29);
      d_1c0424 = 1;
    }
  }
}

//@ f_110b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Gegenstands-Analysezauber *Odem Arcanum* (0x28): Abhängig vom Kontext d_1c0428
 *   lässt die Funktion den Spieler einen Gegenstand im Inventar des Zaubernden P(p1, 0x12) auswählen (f_032820),
 *   prüft über f_042e10 und f_149360, ob der Gegenstand magisch ist, markiert ihn als untersucht (f_042f20) und
 *   gibt den entsprechenden Befund (0x1700008e, 0x1700005f, 0x17000097 oder 0x17000060) im Textpuffer d_1c21b4
 *   aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: slot / raw (gewählter Inventarplatz), item (Gegenstands-ID), ob1, ob2 (Textkontexte).
 === Ende Beschreibung === */
void f_110b70(int p1)
{
    struct Kontext {
        OB ob;
        Kontext() { OBC(ob); }
        ~Kontext() { OBD(ob); }
    };
    Kontext ob1;
    switch (d_1c0428) {
    case 1: SBO(ob1.ob,0,P(p1,0x12)); M(0x1700000d); goto fertig;
    case 3: SBO(ob1.ob,0,P(p1,0x12)); M(0x17000009); goto fertig;
    default:
    {
        Kontext ob2;
        int money=d_1a7a0c;
        short raw=f_032820(P(p1,0x12),0x20000103,1);
        int slot=raw;
        if (slot!=-1) {
            short item=f_042a60((struct hero *)(P(p1,0x12)),slot);
            if (item!=(short)0) {
                if (f_042e10((struct hero *)(P(p1,0x12)),slot)) {
                    if ((int)f_149360(item,(int)&money)!=-1) {
                        f_0e93f0(D38B0,D21B4,0x1700008e);
                    } else {
                        SBO(ob2.ob,2,(*(int **)&d_1c2c40)[item]);
                        *(short *)(ob2.ob.b[7]+2)=1;
                        f_0e93f0(D38B0,D21B4,0x1700005f);
                    }
                    f_042f20((struct hero *)(P(p1,0x12)),(short)(*&raw),1);
                } else {
                    slot = (slot & 0) ? 0 : slot; // haelt die Registerfolge in f_110b70 wie im Original
                    if ((int)f_042ac0((struct hero *)(P(p1,0x12)),slot)>1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7950() || ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7ad0()) {
                        SBO(ob2.ob,2,(*(int **)&d_1c2c40)[item]);
                        *(short *)(ob2.ob.b[7]+2)=2;
                        f_0e93f0(D38B0,D21B4,0x17000097);
                    } else {
                        SBO(ob2.ob,2,(*(int **)&d_1c2c40)[item]);
                        *(short *)(ob2.ob.b[7]+2)=1;
                        f_0e93f0(D38B0,D21B4,0x17000060);
                    }
                }
            } else { W(p1,0)=-4; d_1c21b4=0; }
        } else { W(p1,0)=-4; d_1c21b4=0; }
    }
    }
fertig:;
    d_1c0420 = (d_1c0420 & 0) ? 0 : d_1c0420; // haelt die globale Symbol- und Registerfolge in spell3 wie im Original
    d_1c0424 = (d_1c0424 & 0) ? 0 : d_1c0424; // haelt die globale Symbol- und Registerfolge in spell3 wie im Original
}
