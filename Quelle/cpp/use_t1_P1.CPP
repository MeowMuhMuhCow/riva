/* === Beschreibung (Katalog) ===
 * Einheit use_t1 (0x135040 - 0x136210)
 *
 * Überblick
 * Diese Einheit bildet den ersten Hauptteil des Gegenstandsbenutzungs-Moduls (use.cpp). Sie implementiert das
 * Lesen von Briefen, Dokumenten und magischen Büchern (einschließlich der Pergamentrollen-Darstellung am
 * Bildschirm), das Verbrennen ketzerischer oder gefährlicher Gegenstände mit einer brennenden Fackel, das
 * Auftragen von Waffengiften und alchemistischen Pasten auf die geführte Waffe sowie das Abschreiben von
 * Rezepten und Schriftstücken in ein Rezept- oder Notizbuch mit Schreibzeug.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 8/13 gleich (suche.py 26.10.2026, Basis use_t1_P1.CPP)
// use.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x135040-0x13AA40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0458b0(int p1);                                   // reg eax stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068960();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_08ab50();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a080(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce710(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10cba0(int p1, int p2);                           // reg eax edx stapel 0
int f_10cbc0(int p1, int p2);                           // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a68f4;                    // 0x1A68F4
extern int d_1a933c;                    // 0x1A933C
extern int d_1a934a;                    // 0x1A934A
extern int d_1a9820;                    // 0x1A9820
extern int d_1bf4bc;                    // 0x1BF4BC
extern int d_1bf4be;                    // 0x1BF4BE
extern int d_1c0e7c;                    // 0x1C0E7C
extern int d_1c0e84;                    // 0x1C0E84
extern int d_1c0e88;                    // 0x1C0E88
extern int d_1c106c;                    // 0x1C106C
extern int d_1c106d;                    // 0x1C106D
extern int d_1c1070;                    // 0x1C1070
extern int d_1c1071;                    // 0x1C1071
extern int d_1c1074;                    // 0x1C1074
extern int d_1c1075;                    // 0x1C1075
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c23a8;                    // 0x1C23A8
extern int d_1c259c;                    // 0x1C259C
extern short d_1c25fe;                  // 0x1C25FE
extern int d_1c2600;                    // 0x1C2600
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1a8e28[];           // Text 0x1A8E28
// --- eigene Funktionen (104), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#include <bios.h>
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
struct B9 { char c[9]; };
struct A22 { int a[5]; short s; };
extern char d_1c2c64[], d_1c349c[], d_1c3870[], d_1c3498[], d_1c21b4[], d_1c3068[], d_1c38b0[], d_1a9316[], d_1a935a[], d_1a92d0[];
extern short d_1a92f4[];
extern struct A22 d_1a9374;

extern int d_1a936c, d_1a9370, d_1c0004, d_1a34e0, d_1c0c4c, d_1c2a80, d_1c0420;
extern short d_1bd90c;
extern short d_1c2198;
extern char d_1c042a;
extern signed char d_1c0e80;
short f_149360(int p1, int p2);




short f_032820(int p1, int p2, int p3);
short f_03d860(int p1, int p2, int p3);
short f_145760(int p1, int p2);
int f_10ce80(int p1, int p2, int p3);
int f_1459d0(int p1, int p2);
extern "C" unsigned short f_0bf820(void *, ...);
void f_1374f0(int p1, int p2);
short f_1364f0(int p1, int p2);
short f_136720(int p1, int p2);
short f_1365d0(int p1, int p2);
#define S(o) (*(short *)(p1 + (o)))
#define I(o) (*(int *)(p1 + (o)))
#define P(k,o) (*(int *)(o_.slots[k] + (o)))
#define PS(k,o) (*(short *)(o_.slots[k] + (o)))
#define TAB(i) ((*(int **)&d_1c2c40)[i])
#define MSG(n) f_0bf730((int)d_1c2c64, n)
#define NEWOBJ RivaTextContext o_(d_1c349c, d_1c3870, d_1c3498)
//@ f_135040
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt als dritter Gegenstands-Handler (Index 3 in d_1c0e8c) das Lesen von Schriftstücken
 *   und Büchern (*(short *)(p1 + 0x1a)): Handelt es sich um eines der 18 losen Dokumente oder Briefe aus der
 *   Liste d_1a9316, wird die Pergament-Leseansicht f_1374f0 aufgerufen; handelt es sich hingegen um eines der
 *   acht magischen Bücher aus d_1a935a (0x1bd *Dämonenbuch* bis 0x1c4 *Codex Dimensionis*), wird der zugehörige
 *   Buchtext (0x1e0100a5 bis 0x1e0100ac) mit dem Namen des lesenden Helden ausgegeben.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: first (second, action) enthält die Gegenstandskennung aus p1 + 0x1a; object ist der
 *   lokale Textkontext für den Namen des lesenden Helden (*(int *)(p1 + 0x10)).
 === Ende Beschreibung === */
void f_135040(int p1)
{
    int found = 0;
    short first = *(short *)(p1 + 0x1a);
    if (first > 0 && f_149360(first, (int)d_1a9316) != -1)
        found = 1;
    if (found) {
        f_1374f0(p1, *(short *)(p1 + 0x1a));
    } else {
        short second = *(short *)(p1 + 0x1a);
        if (second > 0 && f_149360(second, (int)d_1a935a) != -1)
            found = 1;
        if (!found)
            return;
        short action = *(short *)(p1 + 0x1a);
        RivaTextContext object(d_1c349c, d_1c3870, d_1c3498);
        int *destination = *(int * volatile *)&object.slots[0]; // erzwingt Laden von object.slots[0] vor *(p1 + 0x10)
        destination[1] = *(int *)(p1 + 0x10);
        switch (action) {
        case 0x1bd: f_0bf730((int)d_1c2c64, 0x1e0100a5); break;
        case 0x1be: f_0bf730((int)d_1c2c64, 0x1e0100a6); return;
        case 0x1bf: f_0bf730((int)d_1c2c64, 0x1e0100a7); return;
        case 0x1c0: f_0bf730((int)d_1c2c64, 0x1e0100a8); return;
        case 0x1c1: f_0bf730((int)d_1c2c64, 0x1e0100a9); return;
        case 0x1c2: f_0bf730((int)d_1c2c64, 0x1e0100aa); return;
        case 0x1c3: f_0bf730((int)d_1c2c64, 0x1e0100ab); return;
        case 0x1c4: f_0bf730((int)d_1c2c64, 0x1e0100ac); return;
        }
    }
}
//@ f_135200
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt einen Dokument- oder Rezepttext (p1) auf einem grafischen Pergament-Hintergrund
 *   (0x1e0002, 320x200 Pixel) dar, blendet das Bild bei gesetztem Bit 1 in p2 weich ein, wartet auf einen
 *   Mausklick oder Tastendruck des Spielers und blendet die Ansicht bei gesetztem Bit 2 in p2 wieder aus.
 * - Eingaben: Die anzuzeigende Textkennung (p1), ein Bitfeld für das Ein- und Ausblenden (p2: Bit 0 =
 *   Einblenden, Bit 1 = Ausblenden) sowie ein Layout- bzw. Zeilenabstandsparameter (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q ist das temporäre Grafik-Oberflächenobjekt (320x200), L.buf der geladene Bildpuffer
 *   für 0x1e0002, und L.sa bis L.se sichern die vorherigen Textfenster- und Farbeinstellungen des globalen
 *   Textrenderers d_1c38b0.
 === Ende Beschreibung === */
void f_135200(int p1, unsigned short p2, int p3)
{
  void f_05e360_ecx(int, int, int, int);
#pragma aux f_05e360_ecx "f_05e360" parm [ecx] [eax] [edx] [ebx] modify exact [eax]
  struct {
    char buf[160];
    char gap[4];
    int mg;
    short sa, sa2;
    short sx, sx2;
    short sb, sb2;
    unsigned short p2s, p2b;
    int p3s;
    short se, se2;
    short sc, sc2;
    short sd, sd2;
  } L;
  L.p2s = p2;
  L.p3s = p3;
  int t = (int)new (mark(d_1a8e28, 0x313)) B9;
  int q = t ? ((int)(((RivaRasterImage*)(t))->f_0fac80( 0x140, 200))) : t;
  int u = f_05dec0((int)d_1c3068);
  f_1459b0((int)L.buf);
  d_1c0c4c = d_1c0c4c + 1;
  int h = ((int)(((RivaRasterImage*)(q))->f_0fb0b0()));
  d_1c2a80 = 0x1e0002;
  f_145a10((int)L.buf, 0x1e0002, h);
  f_05ded0((int)d_1c3068, ((int)(((RivaRasterImage*)(q))->f_0fb0b0())));
  f_05e2a0((int)d_1c38b0, (int)&L.sa, (int)&L.sb, (int)&L.sc, (int)&L.sd);
  f_05e360_ecx(0x28, (int)d_1c38b0, (int)&L.sx, (int)&L.se);
  f_05e2d0((int)d_1c38b0, 0x3c, 200, 0x28, (short)L.p3s);
  f_05e320((int)d_1c38b0, 0xfe, -1);
  if (((unsigned short)L.p2s & 1) == 1) f_09a140(0, 0x19);
  int r = f_0d3860();
  if (r == 1) { f_0d2710(); L.mg = 1; } else L.mg = 0;
  f_0e9550((int)d_1c38b0, p1);
  ((RivaRasterImage*)(q))->f_0fade0((void *)( d_1a34e0), 0, 0);
  if (L.mg == 1) f_0d26e0();
  if ((unsigned char)L.p2s & 1) f_09a120(f_145b40((int)L.buf), 0x19);
  while (f_0d3780() == 0) {
    if (f_0d37b0() != 0) break;
    short t_206 = _bios_keybrd(_KEYBRD_READY);
    if (t_206 != (short)0) break;
    f_069460();
  }
  while (f_0d3790() == 0 || f_0d37b0() != 0) f_069460();
  while (_bios_keybrd(_KEYBRD_READY)) _bios_keybrd(_KEYBRD_READ);
  if (*(volatile unsigned char *)&L.p2s & 2) { // Adressnahme/volatile haelt Befehlsplanung am Funktionseingang wie im Original
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    d_1c2198 = 1;
  }
  f_05ded0((int)d_1c3068, u);
  if (q) delete (char *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0)));
  f_05e2d0((int)d_1c38b0, L.sa, L.sb, L.sc, L.sd);
  f_05e320((int)d_1c38b0, L.sx, L.se);
  d_1c0c4c = d_1c0c4c - 1;
  f_1459d0((int)L.buf, 0);
}
//@ f_1354d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den vierten Gegenstands-Handler (Index 4 in d_1c0e8c) für einen nur in bestimmten
 *   Situationen (d_1bd90c != 0) benutzbaren Gegenstand aus: Er öffnet eine Charakteransicht mit der Effekt- bzw.
 *   Zauberaktion 0x3e (f_10ce80), zieht eine Ladung des Gegenstands ab (f_042b20), gibt die erzeugte
 *   Ergebnismeldung aus und zeigt andernfalls (d_1bd90c == 0) den Ablehnungstext 0x1e01006b.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: so ist das lokale Aktionsobjekt (32 Bytes) für f_10cba0/f_10ce80; d_1bd90c gibt an, ob
 *   die Umgebungsbedingung für den Einsatz erfüllt ist.
 === Ende Beschreibung === */
void f_1354d0(int p1)
{
  char so[32];
  if (d_1bd90c != (short)0) {
    f_042740((struct hero *)(I(0x10)), 99);
    f_030850(I(0x10), I(0x10));
    f_10cba0((int)so, I(0x10));
    d_1c0420 = 1;
    d_1c042a = 0xff;
    f_10ce80((int)so, 0x3e, 0);
    f_042b20((struct hero *)(I(0x10)), S(0x18), -1);
    f_042740((struct hero *)(I(0x10)), 0);
    f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, (int)d_1c21b4));
    f_10cbc0((int)so, 0);
    return;
  }
  MSG(0x1e01006b);
}
//@ f_135590
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den fünften Gegenstands-Handler (Index 5 in d_1c0e8c) aus, der für den handelnden
 *   Helden (I(0x10)) die Effekt- bzw. Zauberaktion 0x52 (f_10ce80) auslöst und anschließend die Ladungszahl des
 *   benutzten Gegenstands in Slot S(0x18) um 1 verringert.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: so ist der lokale Puffer für das Aktionsobjekt (f_10cba0/f_10cbc0).
 === Ende Beschreibung === */
void f_135590(int p1)
{
  char so[32];
  f_042740((struct hero *)(I(0x10)), 99);
  d_1c0420 = 1;
  d_1c042a = 0xff;
  f_10cba0((int)so, I(0x10));
  f_10ce80((int)so, 0x52, 0);
  f_042740((struct hero *)(I(0x10)), 0);
  f_042b20((struct hero *)(I(0x10)), S(0x18), -1);
  f_10cbc0((int)so, 0);
}
//@ f_135600
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als sechster Gegenstands-Handler (Index 6 in d_1c0e8c) das Verbrennen eines
 *   Gegenstands mit einer brennenden Fackel (0x16): Wurde die Fackel einzeln benutzt (S(0x1e) == -1), wählt der
 *   Spieler zunächst den zu verbrennenden Gegenstand aus dem Inventar aus (0x1e01009d). Beim Verbrennen des
 *   *Dämonenbuchs* (0x1bd) wird ein Tagebucheintrag (4) angelegt; beim Verbrennen der verbotenen Magierbücher
 *   *Buch des Zurbaran* (0x1be), *Borbarads Testament* (0x1bf), *Daimonikum* (0x1c0) und *Die Wege ohne Namen*
 *   (0x1c1) erhält die Gruppe Abenteuerpunkte (je nach d_1c0e80 bis zu 9 AP für *Borbarads Testament* bzw. 2 AP
 *   für die übrigen); *Trilogie der Kontrolle* (0x1c2), *Arcanum* (0x1c3) und *Codex Dimensionis* (0x1c4)
 *   verbrennen mit einem Kommentar (0x1e01001b), und der Versuch, *Hylailer Feuer* (0xef) anzuzünden, verursacht
 *   eine Explosion mit 10 bis 25 Schadenspunkten (0x1e0100a0).
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: S(0x1e) und S(0x1c) bezeichnen Kennung und Slot des zu verbrennenden Gegenstands, score
 *   die vergebenen Abenteuerpunkte und result den Explosionsschaden bei *Hylailer Feuer*.
 === Ende Beschreibung === */
void f_135600(int p1)
{
  NEWOBJ;
  register int message;
  short result = 0;
  struct ChoicePair { int a[2]; } choices;

  int g = d_1c0004; d_1c0004 = g;  // verschiebt interne Temp-Nummerierung fuer Registerwahl wie im Original
  int sel = S(0x1e);
  if (sel == -1) {
    S(0x1c) = f_032820(I(0x10), 0x1e01009d, 1);
    sel = S(0x1c);
    S(0x1e) = sel != -1 ? f_042a60((struct hero *)(I(0x10)), sel) : 0;
  } else if (sel == 0x16) {
    short old = S(0x1a);
    S(0x1a) = 0x16;
    S(0x1e) = old;
    S(0x1c) = S(0x18);
  }
  sel = (sel & 0) ? 0 : sel;  // haelt Lebensdauer von sel ueber die Verzweigung fuer Registerwahl wie im Original

  if (S(0x1c) == -1) return;
  if (!S(0x1e)) return;

  switch ((unsigned short)S(0x1e)) {
  case 0x1bd:
    f_091f70(4);
    f_068960();
    P(2, 4) = TAB(S(0x1e));
    PS(7, 2) = 1;
    message = 0x1e01009f;
    f_036300(I(0x10), S(0x1c), 1);
    break;

  case 0x1c2:
  case 0x1c3:
  case 0x1c4:
    P(0, 4) = I(0x10);
    P(0, 8) = f_038ba0(d_1c0004);
    message = 0x1e01001b;
    f_036300(I(0x10), S(0x1c), 1);
    break;

  case 0x1be:
  case 0x1bf:
  case 0x1c0:
  case 0x1c1: {
    short score;
    int low = d_1c0e80 < 3;
    if (low) {
      if (S(0x1e) == 0x1bf) score = 9;
      else score = 2;
    } else {
      if (S(0x1e) == 0x1bf) score = 5;
      else score = 0;
    }
    P(0, 4) = I(0x10);
    choices = *(ChoicePair *)&d_1a936c;
    register int index = f_145760(0, 1);
    message = *(&choices.a[0] + index);
    if (score > 0) f_0dcbb0(d_1c0004, score);
    f_036300(I(0x10), S(0x1c), 1);
    break;
  }

  case 0xef:
    result = f_145760(10, 0x19);
    f_036300(I(0x10), S(0x1c), 1);
    P(0, 4) = I(0x10);
    message = 0x1e0100a0;
    break;

  default:
    P(2, 4) = TAB(S(0x1e));
    PS(7, 2) = 1;
    message = 0x1e01009e;
    break;
  }

  MSG(message);
  if (result != 0) f_044300(I(0x10), result);
}
//@ f_135870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den siebten Gegenstands-Handler (Index 7 in d_1c0e8c) aus, der bei erfüllter
 *   Umgebungsbedingung (d_1bd90c != 0) die Effektaktion 0x35 (f_10ce80) für den Helden auslöst, eine Ladung
 *   abzieht und den Ergebnistext anzeigt, oder andernfalls die Meldung 0x1e01006b ausgibt.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: so ist das lokale Aktionsobjekt; d_1bd90c prüft die Zulässigkeit des Einsatzes.
 === Ende Beschreibung === */
void f_135870(int p1)
{
  char so[32];
  if (d_1bd90c != (short)0) {
    f_042740((struct hero *)(I(0x10)), 99);
    d_1c0420 = 1;
    d_1c042a = 0xff;
    f_10cba0((int)so, I(0x10));
    f_10ce80((int)so, 0x35, 0);
    f_042740((struct hero *)(I(0x10)), 0);
    f_042b20((struct hero *)(I(0x10)), S(0x18), -1);
    f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, (int)d_1c21b4));
    f_10cbc0((int)so, 0);
  } else {
    MSG(0x1e01006b);
  }
}
//@ f_135920
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert als achter Gegenstands-Handler (Index 8 in d_1c0e8c) das Bestreichen der in
 *   der rechten Hand (Slot 3) geführten Waffe mit einem Waffengift oder alchemistischen Mittel (0x37
 *   *Shurinknollengift*, 0x38 *Araxgift*, 0x39 *Angstgift*, 0x3a *Schlafgift*, 0x8e *Kukris*, 0x90
 *   *Krötenschemelgift*, 0xa6 *Expurgicum* oder 0xa8 *Vomicum*): Geprüft wird zunächst, ob der Held überhaupt
 *   eine zulässige Waffe (nicht in der Ausschlussliste d_1a9374 und als Waffe markiert f_0a7990) trägt; bei
 *   Erfolg wird die Giftkennung (1-11) und die Anzahl der vergifteten Treffer (5 bei Einzelwaffen bzw. bis zu 10
 *   Geschosse bei stapelbaren Wurfwaffen) auf die Waffe übertragen und das Giftfläschchen durch eine leere
 *   *Glasflasche* (0x1f) oder *Bronzeflasche* (0x2a) ersetzt.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: k (a0) ist die Waffe in Slot 3, st.n der interne Gifttyp, st.v die Zahl der vergifteten
 *   Schläge/Würfe und arg die Kennung der zurückbleibenden leeren Flasche (0x1f oder 0x2a).
 === Ende Beschreibung === */
void f_135920(int p1)
{
  NEWOBJ;
  A22 t = d_1a9374;
  struct { int flag; int n; short v; } st;
  st.v = 5;
  st.flag = 0;
  short k = f_042a60((struct hero *)(I(0x10)), 3);
  short arg = k;
  int msg; int a0;

  if (!k) goto fehler;
  a0 = k; if (f_149360(a0, (int)&t) != -1) goto fehler; a0 = (a0 & 0) ? 0 : a0;  // teilt das k-Web am Aufruf; der Offset wird dadurch vor dem zweiten Teil vergeben und nimmt EDX
  if (((RivaItemDefinition*)(TAB(a0)))->f_0a7990() == 0) goto fehler;
  if (((RivaItemDefinition*)(TAB(a0)))->f_0a7950() != 0) {
    short m = 0;
    switch (S(0x1a)) {
    case 0xa8: st.n = 11; break;
    case 0xa6: st.n = 10; break;
    case 0x37: st.n = 1; break;
    case 0x38: st.n = 2; break;
    case 0x3a: st.n = 4; break;
    case 0x8e: st.n = 8; break;
    case 0x90: st.n = 6; break;
    case 0x39: st.n = 3; break;
    }
    if (f_042fd0((struct hero *)(I(0x10)), 3) == (short)st.n)
      m = ((signed char)(f_043030((struct hero *)(I(0x10)), 3)));
    m += 0xa;
    st.v = m;
    if (f_042ac0((struct hero *)(I(0x10)), 3) < m)
      st.v = f_042ac0((struct hero *)(I(0x10)), 3);
    if (st.v > 1) st.flag = 1;
  }
  switch (S(0x1a)) {
  case 0xa8:
    f_043000((struct hero *)(I(0x10)), 3, 11);
    arg = 0x2a;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0xa6:
    f_043000((struct hero *)(I(0x10)), 3, 10);
    arg = 0x2a;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x37:
    f_043000((struct hero *)(I(0x10)), 3, 1);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x38:
    f_043000((struct hero *)(I(0x10)), 3, 2);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x3a:
    f_043000((struct hero *)(I(0x10)), 3, 4);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x8e:
    f_043000((struct hero *)(I(0x10)), 3, 8);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x90:
    f_043000((struct hero *)(I(0x10)), 3, 6);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  case 0x39:
    f_043000((struct hero *)(I(0x10)), 3, 3);
    arg = 0x1f;
    f_043060((struct hero *)(I(0x10)), 3, (signed char)st.v);
    break;
  }
  f_036300(I(0x10), S(0x18), 1);
  f_036a10(I(0x10), arg, 1, S(0x18), 0);
  P(2, 4) = TAB(f_042a60((struct hero *)(I(0x10)), 3));
  PS(7, 2) = 1;
  if (st.flag) {
    PS(7, 2) = 2;
    msg = 0x1e0100bc;
  } else {
    msg = 0x1e010069;
  }
  MSG(msg);
  return;
fehler:
  // volatile-Basis erzwingt Basis-vor-Wert-Reihenfolge wie im Original
  { int *q = *(int * volatile *)&o_.slots[0]; q[1] = I(0x10); }
  msg = 0x1e01006a;
  MSG(msg);
}
//@ f_135d40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Vertauscht in der Benutzungskontext-Struktur (p1) den ersten Gegenstand (Slot S(0x18),
 *   Kennung S(0x1a)) mit dem zweiten Gegenstand (Slot S(0x1c), Kennung S(0x1e)), um Kombinationsabfragen
 *   unabhängig von der Reihenfolge der Auswahl zu normieren.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: a und b sichern kurzzeitig Kennung und Slot des ersten Gegenstands.
 === Ende Beschreibung === */
void f_135d40(int p1)
{
  short a = S(0x1a), b = S(0x18);
  S(0x1a) = S(0x1e);
  S(0x18) = S(0x1c);
  S(0x1e) = a;
  S(0x1c) = b;
}
//@ f_135d70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob die beiden im Kontext (p1) kombinierten Gegenstände den beiden gesuchten Kennungen
 *   p2 und p3 entsprechen; falls sie in umgekehrter Reihenfolge vorliegen (S(0x1a) == p3 und S(0x1e) == p2),
 *   werden sie automatisch über f_135d40 getauscht, sodass danach S(0x1a) == p2 und S(0x1e) == p3 garantiert
 *   ist.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p1) sowie die beiden erwarteten
 *   Gegenstandskennungen (p2, p3).
 * - Rückgabewert: Gibt 1 zurück, wenn die beiden Gegenstände (in beliebiger Reihenfolge) p2 und p3 sind, sonst
 *   0.
 * - Wichtige Variablen: r speichert das Ergebnis des Paarvergleichs.
 === Ende Beschreibung === */
int f_135d70(int p1, int p2, short p3)
{
  int r = 0;
  if ((short)p2 == S(0x1a) && p3 == S(0x1e)) {
    r = 1;
  } else if ((short)p2 == S(0x1e)) {
    if (p3 == S(0x1a)) {
      f_135d40(p1);
      r = 1;
    }
  }
  return r;
}
//@ f_135dc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Überträgt ein alchemistisches Rezept aus dem Inventarslot p4 mithilfe von *Schreibzeug*
 *   (Slot p3) in ein Buch in Slot p2: Handelt es sich bei dem Buch noch um ein leeres Standard-*Buch* (0x1d),
 *   wird es zunächst in ein *Rezeptbuch* (0xbf) umgewandelt; ist das Rezept (a aus d_1a92d0) noch nicht im
 *   Rezeptbuch vermerkt (f_03d860 == 0), wird es eingetragen (f_03d8b0), eine Ladung Schreibzeug verbraucht
 *   (f_042b20) und der Spieler gefragt (0x1e010094), ob er das nun abgeschriebene Originalrezept wegwerfen
 *   möchte.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Buch-Slot (p2), der Schreibzeug-Slot (p3) und der
 *   Rezept-Slot (p4).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: a ist der Index des Rezepts in d_1a92d0 (und der zugehörigen Trank-Tabelle d_1a92f4), ty
 *   die bisherige Buchkennung in Slot p2.
 === Ende Beschreibung === */
void f_135dc0(int p1, short p2, short p3, short p4)
{
  NEWOBJ;
  short a;
  a = f_042a60((struct hero *)(I(0x10)), p4);
  a = f_149360(a, (int)d_1a92d0);
  short ty = f_042a60((struct hero *)(I(0x10)), p2);
  if (ty == 0x1d) {
    f_036300(I(0x10), p2, 1);
    f_036a10(I(0x10), 0xbf, 1, p2, 0);
  }
  if (f_03d860(I(0x10), p2, a) == 1) {
    MSG(0x1e01008d);
  } else {
    f_03d8b0(I(0x10), p2, a, 1);
    f_042b20((struct hero *)(I(0x10)), p3, -1);
    int *base = (*(int **)&d_1c2c40);
    int ix = d_1a92f4[a];
    P(2, 4) = base[ix];
    PS(7, 2) = 1;
    int rr = f_0bf6f0((int)d_1c2c64, 0x1e010094);
    if (rr == 1) f_036300(I(0x10), p4, 1);
  }
}
//@ f_135ef0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Überträgt ein Schriftstück oder einen Brief aus dem Inventarslot p3 mithilfe von
 *   *Schreibzeug* (Slot p4) in ein *Notizbuch* (0x1dc, bzw. wandelt ein leeres *Buch* 0x1d in Slot p2 in ein
 *   *Notizbuch* 0x1dc um): Bestimmte nicht abschreibbare Dokumente (0x163, 0x16b, 0x1d9, 0x1da, 0x1c9, 0x1c5,
 *   0x1c7, 0x1ca) werden mit passenden Begründungen (0x1e010099-0x1e01009b) abgelehnt; alle übrigen Dokumente
 *   aus d_1a9316 werden eingetragen, verbrauchen eine Ladung Schreibzeug und können auf Wunsch (0x1e010095)
 *   anschließend aus dem Inventar entfernt werden.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Buch-Slot (p2), der Dokument-Slot (p3) und der
 *   Schreibzeug-Slot (p4).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: k ist die Gegenstandskennung des Dokuments in Slot p3, m dessen Index in der
 *   Dokumententabelle d_1a9316.
 === Ende Beschreibung === */
// Argon 855: Demo ruft hier einen Helfer (0x130f80) auf; als inline-Funktion mit int-Rueckgabe entsteht cwde + mov esi,eax wie im Original
inline int lookup_135ef0(short k) { return f_149360(k, (int)d_1a9316); }
void f_135ef0(int p1, short p2, short p3, short p4)
{
  unsigned short k;
  short m;
  k = f_042a60((struct hero *)(I(0x10)), (short)p3);
  NEWOBJ;
  P(0, 4) = I(0x10);
  switch (k) {
    case 0x163: case 0x16b: case 0x1d9: case 0x1da:
      MSG(0x1e010099);
      break;
    case 0x1c9:
      MSG(0x1e01009a);
      break;
    case 0x1c5: case 0x1c7: case 0x1ca:
      MSG(0x1e01009b);
      break;
    default:
      m = lookup_135ef0((short)k);
      if ((short)f_042a60((struct hero *)(I(0x10)), (short)p2) == 0x1d) {
        f_036300(I(0x10), (short)p2, 1);
        f_036a10(I(0x10), 0x1dc, 1, (short)p2, 0);
      }
      if (f_03d860(I(0x10), (short)p2, (short)m) == 1) {
        MSG(0x1e01008d);
        // Berechnete Names-Sortierung ergibt p2,p4,k,p3; int-Zwischenwerte verschwinden im Code vollstaendig.
        p2 = (p2 & 0) ? 0 : p2;
        p4 = (p4 & 0) ? 0 : p4;
        p4 = (p4 & 0) ? 0 : p4;
        p4 = (p4 & 0) ? 0 : p4;
        p4 = (p4 & 0) ? 0 : p4;
        return;
      }
      f_03d8b0(I(0x10), (short)p2, (short)m, 1);
      f_042b20((struct hero *)(I(0x10)), (short)p4, -1);
      P(2, 4) = TAB((short)k);
      PS(7, 2) = 1;
      int t_492 = f_0bf6f0((int)d_1c2c64, 0x1e010095);
      if (t_492 == 1) {
        f_036300(I(0x10), (short)p3, 1);
        return;
      }
      break;
  }
}
//@ f_1360f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler beim Beschreiben eines noch leeren *Buches* (0x1d) über ein Auswahlmenü
 *   (0x1e010087), ob er das Buch als *Rezeptbuch* (0xbf, Auswahl 1) oder als *Notizbuch* (0x1dc, Auswahl 2)
 *   anlegen möchte.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt die gewählte Buchkennung (0xbf oder 0x1dc) bzw. bei Abbruch -1 zurück.
 * - Wichtige Variablen: v ist der vom Auswahldialog f_0bf820 gelieferte Menüpunkt (1 oder 2).
 === Ende Beschreibung === */
int f_1360f0(void)
{
  extern unsigned short f_0bf820(int, ...);
  short v = f_0bf820((int)d_1c2c64, 0x1e010087, 2, 0x1e010085, 0x1e010086);
  int r = -1;
  switch (v) {
  case 1: r = 0xbf; break;
  case 2: r = 0x1dc; break;
  }
  return r;
}
//@ f_136140
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Kombination von *Schreibzeug* (Slot p2) mit einem leeren *Buch* (0x1d in Slot
 *   p3), indem der Spieler zunächst zwischen *Rezeptbuch* (0xbf) und *Notizbuch* (0x1dc) wählt und danach ein
 *   passendes Rezept (f_136720 -> f_135dc0) oder Dokument (f_1365d0 -> f_135ef0) aus dem Heldeninventar zum
 *   Einschreiben ausgesucht wird.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) sowie der Buch-Slot (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: r enthält die gewählte Zielbuch-Kennung (0xbf oder 0x1dc), a den geprüften
 *   Schreibzeug-Slot und b den gewählten Rezept- bzw. Dokument-Slot.
 === Ende Beschreibung === */
void f_136140(int p1, short p2, short p3)
{
  short v = f_0bf820((int)d_1c2c64, 0x1e010087, 2, 0x1e010085, 0x1e010086);
  int r = -1;
  switch (v) {
  case 1: r = 0xbf; break;
  case 2: r = 0x1dc; break;
  }
  switch ((unsigned short)r) {
    case 0xbf: {
      short a = f_1364f0(p1, (short)p2);
      if (a != -1) {
        short b = f_136720(p1, (short)p3);
        if (b != -1) { f_135dc0(p1, (short)p3, a, b); return; }
      }
      break;
    }
    case 0x1dc: {
      short a = f_1364f0(p1, (short)p2);
      if (a != -1) {
        short b = f_1365d0(p1, (short)p3);
        if (b != -1) { f_135ef0(p1, (short)p3, b, a); return; }
      }
      break;
    }
  }
}
