/* === Beschreibung (Katalog) ===
 * Einheit spell3_t1 (0x10fb00 - 0x110690)
 *
 * Überblick
 * Diese Einheit implementiert Zaubersprüche aus dem Bereich der Kampf-, Beschwörungs- und Heilmagie (Teil 1 von
 * spell3.cpp), darunter den *Krähenruf* (0x1b), das Beschwören von *Heptagon* / *Gehörnter Dämon* bzw.
 * Kampfbegleitern (0x10, 0x16), den Heilzauber *Balsam Salabunde* / *Hexenspeichel* (0x22) sowie den
 * Ruhe-/Heilschlafzauber *Ruhe Körper, ruhe Geist* (0x25).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// OPT -4r -oneatx -zp1 -s
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
//@ f_10fb00
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Krähenruf* (0x1b) im taktischen Kampf, prüft zunächst, ob der Kampf unter
 *   freiem Himmel stattfindet, und lässt andernfalls einen Krähenschwarm über das Ziel herfallen, der dort
 *   wiederholt Schaden anrichtet.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10fb00(int p1)
{
  int ok = 1; short sVar2; struct OB ob;
  OBCTOR;
  sVar2 = d_1c0428;
  W(p1,0) = 5;
  if (sVar2 == (short)2) {
    sVar2 = f_03d3d0(P(p1,0x12), 0x1d, CH(p1,4));
    if ((int)sVar2 > 0) {
      if (EQ(*(signed char*)&d_1c0908, 0)) {
      int target = P(p1,0x12);
      P(P((int)&ob,4),4) = target;
      M(0x1700000f);
      sVar2 = f_0366e0(P(p1,0x12), 0x196, 1, 1);
      if (sVar2 == 1) *(signed char*)&d_1c0908 = 1;
      else { sVar2 = f_0dcf00(d_1c0004, 0x196, 1); if (sVar2 == 1) *(signed char*)&d_1c0908 = 1; }
      }
    } else {
      W(p1,2) = 5; W(p1,0) = -2;
    }
  } else ok = 0;
  if (!ok) { f_0e93f0(D38B0, D21B4, 0x170000a7); W(p1,0) = -4; }
  OBDTOR;
}

//@ f_10fc00
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt für den Zaubernden P(p1, 0x12) eine Zauber-Statusmeldung (0x170000a8) über f_0e93f0 in den
 *   Meldungspuffer d_1c21b4 aus (Hilfs-/Folgeroutine zu Tier- und Beschwörungszaubern).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: ob (lokaler Textkontext OB), P(p1, 0x12) (Zaubernder).
 === Ende Beschreibung === */
void f_10fc00(int p1)
{
  struct OB ob;
  OBCTOR;
  SB(0, P(p1,0x12));
  f_0e93f0(D38B0, D21B4, 0x170000a8);
  OBDTOR;
}

//@ f_10fc50
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für einen Helden p1 anhand der -1-terminierten Gegenstandsliste d_1a7876 über f_0d4aa0, ob
 *   dieser mindestens einen der gesuchten Gegenstände im Inventar trägt (Hilfsprädikat für f_0398c0 in
 *   f_10fc90).
 * - Eingaben: p1 (Zeiger auf den Helden).
 * - Rückgabewert: 1, wenn mindestens ein Gegenstand aus d_1a7876 im Inventar gefunden wurde, sonst 0.
 * - Wichtige Variablen: sVar2 (Index in d_1a7876), uVar3 (Trefferflag).
 === Ende Beschreibung === */
int f_10fc50(int p1)
{
  short sVar1; short sVar2; int uVar3;
  uVar3 = 0; sVar2 = 0;
  for (; d_1a7876[sVar2] != -1; sVar2++) {
    sVar1 = f_0d4aa0(p1, (int)d_1a7876[sVar2]);
    if (sVar1 != -1) uVar3 = 1;
  }
  return uVar3;
}

//@ f_10fc90
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft die Umgebungs- und Gruppenbedingungen für einen Orts-/Reisezauber: Abhängig vom aktuellen
 *   Gebietstyp (f_0de820), einem aktiven Begleiter/Bootsstatus (f_0de800), verbotenen Gegenständen in der Gruppe
 *   (f_0398c0 mit f_10fc50) sowie der Kartenkennung d_1c2a80 gibt die Funktion passende Ablehnungsmeldungen
 *   (0x17000001, 0x17000112..0x17000114) aus oder setzt bei Erfolg d_1c0904 = 1 und berechnet die Astralkosten
 *   (20 + d_1c042a).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0904 (Freigabeflag für den Zauber), W(p1, 0) (Astralkosten bzw. Fehlercode -4 / -2).
 === Ende Beschreibung === */
void f_10fc90(int p1)
{
  short sVar1; short sVar2;
  sVar1 = f_0de820(d_1c0004);
  d_1c0904 = 0;
  sVar2 = f_0de800(d_1c0004);
  if (sVar2 != -1) { M(0x17000114); W(p1,0) = -4; return; }
  {
    if ((int)sVar1 == 7 || (int)sVar1 == 8 || (int)sVar1 == 9) { M(0x17000001); W(p1,0) = -4; }
    else if (sVar1 == 3 || sVar1 == 0x17 || sVar1 == 0x18 || sVar1 == 0x19) { M(0x17000113); W(p1,0) = -4; }
    else {
      sVar1 = f_0398c0(d_1c0004, (int)f_10fc50, D24D4);
      if (sVar1 > 0) {
        struct OB ob;
        W(p1,0) = -4;
        OBCTOR;
        SB(0, P(p1,0x12));
        M(0x17000112);
        OBDTOR;
      } else {
#if FIX_R047   /* R047: Bei unzulaessiger Karte d_1c2a80 mit -4 (Abbruch) statt 0 (Fehlschlag) beenden */
        if (d_1c2a80 != 0 && d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001) { M(0x17000114); W(p1,0) = -4; return; }
#else
        if (d_1c2a80 != 0 && d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001) { M(0x17000114); W(p1,0) = 0; return; }
#endif
        d_1c0904 = 1;
      }
    }
    if (EQB(d_1c0904, 1)) {
      W(p1,0) = 0x14;
      W(p1,0) = W(p1,0) + (signed char)d_1c042a;
      sVar1 = f_0429a0((struct hero *)(P(p1,0x12)));
      if (sVar1 < W(p1,0)) { W(p1,0) = -2; d_1c0904 = 0; }
    }
  }
}

static inline void AddExtra493(short &cost, const short &extra) {cost += extra;}
static inline void Bind493(int context, int target) { *(int *)(context+4)=target; }
//@ f_10fe10
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Astralraub* / *Magischer Raub* (0x20), bei dem der Zaubernde P(p1, 0x12)
 *   über einen Zahlendialog (0x170000a9) festlegt, wie viele Punkte auf das Ziel P(p1, 0x16) übertragen bzw.
 *   angewendet werden, nach gelungener Zauberprobe (f_03d3d0 mit 0x20) die Astralkosten ((iVar3 / 5) * 3 + 5 +
 *   d_1c042a) setzt und einen zeitlich befristeten Effekt-Timer (f_0d5040, Typ 0x0c) startet.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: sVar1 / iVar3 (gewählte Stärke), W(p1, 0) (Astralkosten), W(p1, 2) (halbe Kosten bei
 *   Misslingen).
 === Ende Beschreibung === */
static inline int durfe10(int n) { n*=3; return ((n+n)<<4)-(n+n); }
void f_10fe10(int p1)
{
  short sVar1; short sVar2; int iVar3; struct OB ob;
  OBCTOR;
  iVar3 = f_043c80(P(p1,0x16));
  if (iVar3 == 0) {
    sVar1 = f_0429a0((struct hero *)(P(p1,0x12)));
    sVar1 = (sVar1 / 3) * 5;
    Bind493(ob.b[0], P(p1,0x12));
    *(short *)(ob.b[4]+2) = sVar1;
    iVar3 = (int)sVar1;
    sVar1 = f_0bf7b0(D2C64, (int)(short)((iVar3 < 10) ? 1 : (iVar3 >= 100) + 2), 0x170000a9, 0, iVar3, 0);
    d_1c21b4 = 0;
    iVar3 = (int)sVar1;
    if (0 < iVar3) {
      sVar2 = f_03d3d0(P(p1,0x12), 0x20, CH(p1,4));
      if (0 < sVar2) {
        W(p1,0) = (int)(iVar3 / 5) * 3 + 5;
        AddExtra493(W(p1,0), (short)*(signed char *)&d_1c042a);
        sVar2 = f_0d4c80(P(p1,0x16));
        f_0d5040(P(p1,0x16), (int)(short)(sVar2 & 0xffff), durfe10(iVar3), 0, 1, 0xc); // haelt die Registerfolge (edx/eax im else-Zweig) wie im Original
        Bind493(ob.b[0], P(p1,0x16));
        *(short*)(ob.b[4]+2) = sVar1;
        f_0e93f0(D38B0, D21B4, 0x170000bd);
        OBDTOR; return;
      }
      W(p1,0) = -2;
      *(volatile short *)(p1+2) = (short)(((iVar3 / 2) * 3 + 5) / 2); // haelt das Speicherschreiben vor dem Destruktor wie im Original
      OBDTOR; return;
    }
  } else {
    SB(0, P(p1,0x16));
    f_0e93f0(D38B0, D21B4, 0x170000bc);
  }
  *(volatile short *)p1 = -4; // haelt das Speicherschreiben vor dem Destruktor wie im Original
  OBDTOR;
}

//@ f_10ffe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Heilzauber *Balsam Salabunde* (0x21), der prüft, ob das Ziel P(p1, 0x16) überhaupt
 *   heilbar (f_042470) und verletzt (f_042970 != f_042960) ist, die zu heilenden Lebenspunkte entweder
 *   automatisch (bei NPCs/Automatik) oder per Zahlendialog (0x17000023, mindestens 7 AE) bestimmt, auf die
 *   fehlenden Lebenspunkte und die vorhandene Astralenergie deckelt und bei gelungener Probe (f_03d3d0 mit 0x21)
 *   die Heilung über f_044890 durchführt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: amount (zu heilende Lebenspunkte), hi / lo (maximale und aktuelle LE des Ziels), W(p1,
 *   0) (Astralkosten).
 === Ende Beschreibung === */
void f_10ffe0(int p1)
{
  int f_044890(int, int);
  short amount;
  struct OB ob;
  OBCTOR;
  if (((signed char)(f_042470((struct hero *)(P(p1,0x16)))))) {
    W(p1,0) = -4;
    f_0e93f0(D38B0, D21B4, 0x1700009c);
    amount = -99;
  } else if (f_042750((struct hero *)(P(p1,0x12))) ||
             (f_042400((struct hero *)(P(p1,0x12))) && d_1bd90c != (short)0)) {
    W(p1,0) = 0;
    int hi = f_042970((struct hero *)(P(p1,0x16)));
    int lo = f_042960((struct hero *)(P(p1,0x16)));
    amount = (hi - lo) / 2;
  } else {
    W(p1,0) = -4;
    ((int *)P((int)&ob,4))[1] = P(p1,0x12);
    ((int *)P((int)&ob,4))[2] = P(p1,0x16);
    amount = f_0bf7b0(D2C64, 2, 0x17000023, 1,
                      (int)f_0429a0((struct hero *)(P(p1,0x12))), 0);
    d_1c21b4 = 0;
  }
  if ((int)amount > 0) {
    if ((int)amount < 7) W(p1,0) = 7;
    else {
      int hi = f_042970((struct hero *)(P(p1,0x16)));
      int lo = f_042960((struct hero *)(P(p1,0x16)));
      if ((int)amount > hi - lo) {
        short h = f_042970((struct hero *)(P(p1,0x16)));
        short l = f_042960((struct hero *)(P(p1,0x16)));
        short difference = h - l;
        amount = (amount & 0) ? 0 : amount; // haelt die Registerfolge fuer difference und amount wie im Original
        amount = difference;
        W(p1,0) = difference;
      } else W(p1,0) = amount;
    }
    W(p1,0) += *(signed char *)&d_1c042a;
    short hi = f_042970((struct hero *)(P(p1,0x16)));
    short lo = f_042960((struct hero *)(P(p1,0x16)));
    if (hi == lo) goto L_bd;
    if (f_0429a0((struct hero *)(P(p1,0x12))) < W(p1,0)) {
      amount = f_0429a0((struct hero *)(P(p1,0x12)));
      W(p1,0) = amount;
    }
    if ((int)f_03d3d0(P(p1,0x12), 0x21, CH(p1,4)) > 0) {
      f_044890(P(p1,0x16), (int)amount);
      { int value = P(p1,0x16); ((int *)P((int)&ob,4))[1] = value; }
      f_0e93f0(D38B0, D21B4, 0x1700009e);
    } else {
      short half = W(p1,0) / 2;
      W(p1,0) = -2;
      W(p1,2) = half;
    }
  } else {
    if ((int)amount == -99) goto L_e0;
    short hi, lo;
    hi = f_042970((struct hero *)(P(p1,0x16)));
    lo = f_042960((struct hero *)(P(p1,0x16)));
    if (hi != lo) goto L_e0;
L_bd:
    W(p1,0) = -4;
    ((int *)P((int)&ob,4))[1] = P(p1,0x16);
    f_0e93f0(D38B0, D21B4, 0x1700009d);
  }
L_e0:
  OBDTOR;
}

//@ f_110200
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Heilzauber *Hexenspeichel* (0x22), der wahlweise Wundpunkte eines verletzten
 *   Gruppenmitglieds heilt (kostenpflichtig mit 2 Astralpunkten pro Lebenspunkt) oder eine bestehende Vergiftung
 *   neutralisiert.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 * - Bekannte Originalfehler: Bei der Lebenspunkte-Heilung wird am Anfang W(p1, 0) (die Astralenergiekosten an
 *   Offset +0) mit -4 (Abbruchcode) vorinitialisiert (0x11021f). Nachdem der Spieler im Zahlen-Eingabedialog die
 *   zu heilenden Lebenspunkte (amount) eingegeben hat, prüft das Programm im else-Zweig if (f_0429a0(caster) <
 *   W(p1, 0)) (0x1102a1-0x1102ac), bevor W(p1, 0) = amount * 2 bei 0x1102bb berechnet wird. Da W(p1, 0) zum
 *   Zeitpunkt des Vergleichs noch -4 ist, ist die Bedingung aktuelle_AE < -4 niemals erfüllt und die Deckelung
 *   auf die vorhandene Astralenergie toter Code.
 === Ende Beschreibung === */
void f_110200(int p1)
{
  int f_044890(int, int);
  union Raw906 { int full; short word; struct { unsigned char lo,hi; } byte; } raw;
  int rawCall906(int,int,int,int,int,int);
  #pragma aux rawCall906 "f_0bf7b0";
  short amount;
  int n;
  struct OB ob;
  OBCTOR;
  W(p1,0) = -4;
  SB(0, P(p1,0x12));
  *(int*)(ob.b[0]+8) = P(p1,0x16);
  raw.full = rawCall906(D2C64, 2, 0x17000023, 0,
                     (int)f_0429a0((struct hero *)(P(p1,0x12))), 0);
  amount=raw.word; raw.byte.hi=0;
  *(signed char *)&d_1c21b4=(signed char)raw.byte.hi;
  n=(int)amount;
  if (0 < n) {
    if (n * 2 > (int)f_042970((struct hero *)(P(p1,0x16))) - (int)f_042960((struct hero *)(P(p1,0x16)))) {
      amount = f_042970((struct hero *)(P(p1,0x16))) - f_042960((struct hero *)(P(p1,0x16)));
#if FIX_R042   /* R042: Hexenspeichel vergleicht vorhandene AE mit amount * 2 statt mit W(p1,0) == -4 */
    } else if (f_0429a0((struct hero *)(P(p1,0x12))) < amount * 2) {
#else
    } else if (f_0429a0((struct hero *)(P(p1,0x12))) < W(p1,0)) {
#endif
      W(p1,0) = f_0429a0((struct hero *)(P(p1,0x12)));
      goto L_after;
    }
    W(p1,0) = amount * 2;
L_after:
    short max906=f_042970((struct hero *)(P(p1,0x16)));
    {int rt906=P(p1,0x12);P(p1,0x12)=rt906;} // haelt die Register- und Stapelplatzfolge wie im Original
    if (max906 == f_042960((struct hero *)(P(p1,0x16)))) {
      W(p1,0) = -4;
      SB(0, P(p1,0x16));
      f_0e93f0(D38B0, D21B4, 0x1700009d);
    } else if ((int)f_03d3d0(P(p1,0x12), 0x22, CH(p1,4)) > 0) {
      f_044890(P(p1,0x16), (int)(short)(W(p1,0) / 2));
      SB(0, P(p1,0x16));
      f_0e93f0(D38B0, D21B4, 0x1700009e);
      OBDTOR; return;
    } else {
      short half = W(p1,0) / 2;
      W(p1,0) = -2;
      W(p1,2) = half;
    }
  }
  OBDTOR;
}

//@ f_110380
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Entgiftungszauber *Klarum Purum Kräutersud* (0x23), der alle 10 möglichen
 *   Giftplätze (0..9) des Ziels P(p1, 0x16) über f_0435c0 abfragt, die Giftstufenkosten aus d_1a0dc8 in W(p1, 0)
 *   aufsummiert und bei ausreichender Astralenergie sämtliche Vergiftungen in einer Schleife über f_040e00 /
 *   f_0d4b00 heilt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: ok (Flag, ob eine Vergiftung vorliegt), sum (Astralkosten der jeweiligen Giftart aus
 *   d_1a0dc8).
 === Ende Beschreibung === */
void f_110380(int p1)
{
  int ok; short sVar4; short sum; short half; int p2; int u; struct OB ob;
  OBCTOR;
  ok = 0;
  u = P(p1,0x16);
  SB(0, u);
  for (sVar4 = 0; (p2 = (int)sVar4) <= 9; sVar4++) {
    if (f_0435c0(P(p1,0x16), p2) == -1) {
      short s2 = d_1a0dc8[p2]; sum = (s2 & 0) ? 0 : s2; // haelt die Registerfolge (edx/eax bei SB(0, u)) wie im Original
      ok = 1;
      W(p1,0) = W(p1,0) + sum;
    }
  }
  if (!ok) {
    f_0e93f0(D38B0, D21B4, 0x17000025);
    W(p1,0) = -4;
  } else {
    W(p1,0) = W(p1,0) + *(signed char *)&d_1c042a;
    if (f_0429a0((struct hero *)(P(p1,0x12))) < W(p1,0)) { half = W(p1,0) / 2; *(short *)p1 = -2; *(volatile short *)(p1 + 2) = half; OBDTOR; return; } // haelt das Speicherschreiben vor dem Destruktor wie im Original
    do {
      f_040e00(P(p1,0x16));
    } while (f_0d4b00(P(p1,0x16)) != (short)0);
    f_0e93f0(D38B0, D21B4, 0x17000026);
  }
  OBDTOR;
}

//@ f_110490
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Krankheitsheilungs- bzw. Regenerationszauber (0x24), der prüft, ob auf dem Ziel
 *   P(p1, 0x16) bereits ein entsprechender Effekt aktiv ist (f_043f00), und andernfalls über f_0d5040 einen
 *   Langzeit-Heileffekt (Dauer 0x1fa40, Typ 0x18) einträgt sowie die Erfolgsmeldung 0x17000041 ausgibt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p1_00 (Zielheld P(p1, 0x16)), sVar1 (freier Timer-Slot aus f_0d4c80).
 === Ende Beschreibung === */
void f_110490(int p1)
{
  int p1_00; short sVar1; int iVar2; struct OB ob;
  OBCTOR;
  p1_00 = P(p1,0x16);
  SB(0, p1_00);
  iVar2 = f_043f00(p1_00);
  if (iVar2 == 0) {
    sVar1 = f_0d4c80(P(p1,0x16));
    f_0d5040(P(p1,0x16), (int)sVar1, 0x1fa40, 0, 1, 0x18);
    f_0e93f0(D38B0, D21B4, 0x17000041);
  } else {
    f_0e93f0(D38B0, D21B4, 0x17000110);
    W(p1,0) = -2;
  }
  OBDTOR;
}

//@ f_110520
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert die Astralenergie-Abfrage und Zauberprobe für den Zauber *Ruhe Körper, ruhe Geist*
 *   (0x25): Sofern der Zauber im aktuellen Kontext zulässig ist (d_1c0428 != 0), fragt die Funktion die
 *   einzusetzenden Punkte über f_0bf7b0 (0x17000027) ab und würfelt die Zauberprobe f_03d3d0(..., 0x25, ...).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: sVar1 (gewählter Einsatz), sVar2 (Probenergebnis).
 === Ende Beschreibung === */
void f_110520(int p1)
{
  short sVar1 = 0; short sVar2; struct OB ob;
  OBCTOR;
  int value = P(p1,0x12);
  SB(0, value);
  if ((short)d_1c0428 == (short)0) {
    f_0e93f0(D38B0, D21B4, 0x170000d2);
    W(p1,0) = -4;
  } else {
    W(p1,0) = -4;
    sVar1 = f_0bf7b0(D2C64, 2, 0x17000027, 0, (int)f_0429a0((struct hero *)(P(p1,0x12))), 0);
    d_1c21b4 = 0;
    if (0 < sVar1) {
      sVar2 = f_03d3d0(P(p1,0x12), 0x25, CH(p1,4));
      if (0 < sVar2) {
        W(p1,0) = sVar1;
        f_0e93f0(D38B0, D21B4, 0x170000d3);
        OBDTOR; return;
      }
      W(p1,0) = -2;
      W(p1,2) = sVar1 / 2;
    }
  }
  OBDTOR;
}

//@ f_110620
/* === Beschreibung (Katalog) ===
 * - Zweck: Trägt für den Zaubernden P(p1, 0x12) einen temporären Eigenschafts- oder Regenerationseffekt (Dauer
 *   0x21c, Wert 7, Typ 1) über f_0d5040 ein und gibt die Meldung 0x17000028 aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p1_00 (Zaubernder P(p1, 0x12)), sVar1 (Timer-Slot).
 === Ende Beschreibung === */
void f_110620(int p1)
{
  int p1_00; short sVar1; struct OB ob;
  OBCTOR;
  p1_00 = P(p1,0x12);
  SB(0, p1_00);
  sVar1 = f_0d4c80(p1_00);
  f_0d5040(P(p1,0x12), (int)sVar1, 0x21c, 0x33, 7, 1);
  f_0e93f0(D38B0, D21B4, 0x17000028);
  OBDTOR;
}
