/* === Beschreibung (Katalog) ===
 * Einheit use_t3 (0x1374F0 - 0x1386A0)
 *
 * Überblick
 * Diese Einheit bildet den dritten Teil von use.cpp und implementiert die Anzeige von Briefen, Dokumenten und
 * alchemistischen Rezepten auf dem Pergament-Bildschirm sowie die Funktion zum Ausdrucken dieser Texte auf einem
 * am PC angeschlossenen Drucker.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 1/3 gleich (suche.py 25.10.2026, Basis use_t3_P1.CPP)
// use.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x135040-0x13AA40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
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
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
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
int f_10ce80();                       // nicht in clobber.tsv
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a68f4;                    // 0x1A68F4
extern short d_1a92d0;                  // 0x1A92D0
extern short d_1a92f4;                  // 0x1A92F4
extern short d_1a9316;                  // 0x1A9316
extern int d_1a933c;                    // 0x1A933C
extern int d_1a934a;                    // 0x1A934A
extern int d_1a935a;                    // 0x1A935A
extern int d_1a936c;                    // 0x1A936C
extern int d_1a9370;                    // 0x1A9370
extern int d_1a9374;                    // 0x1A9374
extern int d_1a9820;                    // 0x1A9820
extern int d_1bd90c;                    // 0x1BD90C
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0420;                    // 0x1C0420
extern int d_1c042a;                    // 0x1C042A
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c0e80;                    // 0x1C0E80
extern int d_1c106c;                    // 0x1C106C
extern int d_1c106d;                    // 0x1C106D
extern int d_1c1070;                    // 0x1C1070
extern int d_1c1071;                    // 0x1C1071
extern int d_1c1074;                    // 0x1C1074
extern int d_1c1075;                    // 0x1C1075
extern int d_1c212a;                    // 0x1C212A
extern int d_1c212c;                    // 0x1C212C
extern int d_1c2198;                    // 0x1C2198
extern int d_1c259c;                    // 0x1C259C
extern short d_1c25fe;                  // 0x1C25FE
extern int d_1c2600;                    // 0x1C2600
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3068;                    // 0x1C3068
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a8e28[];           // Text 0x1A8E28
// --- eigene Funktionen (104), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern char d_1c3498[], d_1c21b4[], d_1c23a8[], d_1c38b0[], d_1c2c64[], d_1c2c44[], d_1c27a8[], d_1baac0[];
extern short d_1bf4bc;
extern short d_1bf4be;
extern char d_1c0e7c;
extern signed char d_1c0e84, d_1bfaf0;
extern int d_1c0e88;
void __cdecl f_099ef0(void *p, int v, int n);
void __cdecl f_149eb4(void *p, int v, int n);
void *f_147c84(void *p, int n, void *t);
short f_0bf6f0(int p1, int p2);
int f_0e8a30(int p1);
void f_135200(int p1, unsigned short p2, int p3);
void f_137ad0(int p1, unsigned short p2);
#define I(o) (*(int *)(p1 + (o)))
#define TAB(i) (*(int *)((*(int*)&d_1c2c40) + (i) * 4))
#define MSG(n) f_0bf730((int)d_1c2c64, n)
#define GE(x,v) (((x) >= (v)) ? 1 : 0)
#define T1(m) f_0e93f0((int)d_1c38b0, (int)d_1c21b4, m)
#define T2(m) f_0e9300((int)d_1c38b0, (int)d_1c21b4, m)
//@ f_1374f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt den Inhalt eines Briefes oder Dokuments (p2 aus d_1a9316) seitenweise auf dem
 *   grafischen Pergament-Hintergrund (f_135200) an: Einen Sonderfall bilden die *Liebesbriefe* (0x1c9), bei
 *   denen der Spieler gefragt wird (0x1e01000f), ob er sie lesen möchte, woraufhin 2 Stunden Spielzeit vergehen
 *   (f_125f70) und beim ersten Lesen (d_1c0e7c == 0) eine dauerhafte Änderung eines Charakterwerts
 *   (f_03af20(..., 0x14, 1)) erfolgt; bei den mehrteiligen *Rätsel-* und *Hinweis-Dokumenten* (0x1d9 und 0x1da)
 *   wird der Text dynamisch je nach Fortschrittsstufe d_1c0e84 (0 bis 4) zusammengesetzt. Nach dem Lesen eines
 *   Pergament-Dokuments wird dem Spieler bei aktivierter Druckfunktion (d_1bfaf0 != -1) angeboten (0x1e0100cc),
 *   das Schriftstück über f_137ad0 auszudrucken.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie die Gegenstandskennung des Dokuments (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: buf sichert die 256-Farben-Bildschirmpalette (768 Bytes), s1 und s2 sichern die
 *   Mauszeiger-Einstellungen (d_1bf4bc, d_1bf4be), d_1c0e7c vermerkt das erstmalige Lesen der Liebesbriefe und
 *   flag steuert, ob anschließend die Druckabfrage erscheint.
 === Ende Beschreibung === */
static inline int h_1374eq(const signed char &c,int n){return c==n;}
static inline void h_1374text9(char*a,char*b){
    b[0] = 0;
    a[0] = 0;
    f_0e93f0((int)d_1c38b0,(int)a,0x1e010024);
    if (GE(d_1c0e84, 1) && (f_0e9300((int)d_1c38b0,(int)a,0x1e010025), GE(d_1c0e84, 2)) && (f_0e93f0((int)d_1c38b0, (int)b, 0x1e010026), GE(d_1c0e84, 3)))
      f_0e9300((int)d_1c38b0, (int)b, 0x1e010027);
    if (*(signed char*)b != 0) {
      int m=f_133fe0((int)d_1c3498,(int)a);f_135200(m,1,0);
      m=f_133fe0((int)d_1c3498,(int)b);f_135200(m,2,0);
    }else if (1) {
      int m = f_133fe0((int)d_1c3498, (int)a);
      f_135200(m, 3, 0);

    }}
static inline void h_1374texta(char*a,char*b){
    a[0] = 0;
    f_0e93f0((int)d_1c38b0,(int)a,0x1e010028);
    if (GE(d_1c0e84, 1) && (f_0e9300((int)d_1c38b0,(int)a,0x1e010029), GE(d_1c0e84, 2)) && (f_0e9300((int)d_1c38b0,(int)a,0x1e01002a), GE(d_1c0e84, 3)) && (f_0e9300((int)d_1c38b0,(int)a,0x1e01002b), GE(d_1c0e84, 4)))
      f_0e9300((int)d_1c38b0,(int)a,0x1e01002c);
    {
      int m = f_133fe0((int)d_1c3498, (int)a);
      f_135200(m, 3, 0);
    }}
struct Palette943 { unsigned char red, green, blue; Palette943(); };
void f_1374f0(int p1, int p2)
{
  char *buf;
  int flag;
  short s2,s1;
  flag=1;
  buf = (char *)new (mark(d_1a8e28, 0x994)) Palette943[256];
  s1 = *(volatile short *)&d_1bf4bc; // volatile erzwingt die Ladereihenfolge von d_1bf4bc vor d_1bf4be
  s2 = d_1bf4be;
  f_0d2f90(0, 1);
  f_149eb4(buf, 0, 0x100);
  switch ((unsigned short)p2) {
  case 0x163:
    f_135200(0x1e01003c, 1, 1);
    f_135200(0x1e01003d, 0, 0);
    f_135200(0x1e01003e, 0, 0);
    f_135200(0x1e01003f, 2, 0);
    break;
  case 0x1c9:
    if (((int(*)(int,int))f_0bf6f0)((int)d_1c2c64, 0x1e01000f) == 1) {
      f_125f70((int)d_1c2c44, 2);
      MSG(0x1e010010);
      if (h_1374eq((signed char&)d_1c0e7c,0)) {
        d_1c0e7c = 1;
        MSG(0x1e010011);
        f_03af20(I(0x10), 0x14, 1);
      }
    }
    flag=0;
    break;
  case 0x16b: f_135200(0x1e0100d1, 3, 0); break;
  case 0x172: f_135200(0x1e010002, 3, 0); break;
  case 0x1b1:
    f_135200(0x1e010015, 1, 0);
    f_135200(0x1e010016, 2, 0);
    break;
  case 0x1b2:
    f_135200(0x1e010017, 1, 0);
    f_135200(0x1e010018, 2, 0);
    break;
  case 0x1c5: f_135200(0x1e01000e, 3, 0); break;
  case 0x1ca: f_135200(0x1e010012, 3, 0); break;
  case 0x1c7: f_135200(0x1e010013, 3, 0); break;
  case 0x1d2:
    f_135200(0x1e010040, 1, 0);
    f_135200(0x1e010041, 2, 0);
    break;
  case 0x1d3: f_135200(0x1e010042, 3, 0); break;
  case 0x1d5: f_135200(0x1e010044, 3, 0); break;
  case 0x1d6: f_135200(0x1e010045, 3, 0); break;
  case 0x1d7: f_135200(0x1e010046, 3, 0); break;
  case 0x1d9:h_1374text9(d_1c21b4,d_1c23a8);break;
  case 0x1da:h_1374texta(d_1c21b4,d_1c23a8);break;
  case 0x13e: f_135200(0x1e010014, 3, 1); break;
  case 0x1d4: f_135200(0x1e010043, 3, 0); break;
  default:
    MSG(0x1e010068);
    flag = 0;
  }
  f_0d2f90((short)s1, 1);
  *(volatile short *)&d_1bf4be = s2; // volatile verhindert das Vorziehen oder Eliminieren des Stores nach d_1bf4be
  f_099ef0(buf, 0, 0x100);
  delete buf;
  if (flag == 1) {
  signed char byteflag = d_1bfaf0;
  if (byteflag != -1 && f_0bf6f0((int)d_1c2c64, 0x1e0100cc) == 1)
    ((void(*)(int,int))f_137ad0)(p1, (int)(short)p2);
  }
}
//@ f_137ad0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt den vollständigen Text eines Briefes, Dokuments oder alchemistischen Rezepts (p2) im
 *   globalen Textpuffer d_1c21b4 zusammen, liest den zugehörigen Gegenstandsnamen nach d_1c27a8 aus und übergibt
 *   beides an die Druckroutine f_0e8a30, um das Schriftstück auf Papier auszudrucken.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie die Gegenstandskennung des zu druckenden Dokuments
 *   oder Rezepts (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Bei 0x1d9 (*Rätsel-Dokument*) werden zwei temporäre 500-Byte-Puffer (a, b) reserviert,
 *   um die je nach d_1c0e84 freigeschalteten Textabschnitte zusammenzufügen.
 === Ende Beschreibung === */
void f_137ad0(int p1, unsigned short p2)
{
  switch ((unsigned short)p2) {
  case 0x163:
    T1(0x1e01003c); T2(0x1e0100d0); T2(0x1e01003d); T2(0x1e0100d0);
    T2(0x1e01003e); T2(0x1e0100d0); T2(0x1e01003f);
    break;
  case 0x16b: T1(0x1e0100d1); break;
  case 0x172: T1(0x1e010002); break;
  case 0x1b1: T1(0x1e010015); T2(0x1e0100d0); T2(0x1e010016); break;
  case 0x1b2: T1(0x1e010017); T2(0x1e0100d0); T2(0x1e010018); break;
  case 0x1c5: T1(0x1e01000e); break;
  case 0x1ca: T1(0x1e010012); break;
  case 0x1c7: T1(0x1e010013); break;
  case 0xa7: T1(0x1e010052); break;
  case 0xa9: T1(0x1e010053); break;
  case 0xca: T1(0x1e010054); break;
  case 0xcb: T1(0x1e010055); break;
  case 0xcc: T1(0x1e010056); T2(0x1e010057); break;
  case 0xce: T1(0x1e01005c); T2(0x1e01005d); break;
  case 0xba: T1(0x1e01005e); break;
  case 0xf0: T1(0x1e01005f); T2(0x1e010060); break;
  case 0xf3: T1(0x1e010062); T2(0x1e010063); break;
  case 0xf4: T1(0x1e010064); break;
  case 0xf1: T1(0x1e010065); break;
  case 0x152: T1(0x1e010066); T2(0x1e010067); break;
  case 0x170: T1(0x1e010001); break;
  case 0x197: T1(0x1e010059); T2(0x1e01005a); break;
  case 0x1b3: T1(0x1e01005b); break;
  case 0x1d2: T1(0x1e010040); T2(0x1e010041); break;
  case 0x1d3: T1(0x1e010042); break;
  case 0x1d5: T1(0x1e010044); break;
  case 0x1d6: T1(0x1e010045); break;
  case 0x1d7: T1(0x1e010046); break;
  case 0x1d9: {
    char *a = new (mark(d_1a8e28, 0xaf0)) char[0x1f4];
    char *b = new (mark(d_1a8e28, 0xaf1)) char[0x1f4];
    *a=(*b=0);
    f_0e93f0((int)d_1c38b0, (int)a, 0x1e010024);
    if (GE(d_1c0e84, 1) && (f_0e9300((int)d_1c38b0, (int)a, 0x1e010025), GE(d_1c0e84, 2)) && (f_0e93f0((int)d_1c38b0, (int)b, 0x1e010026), GE(d_1c0e84, 3)))
      f_0e9300((int)d_1c38b0, (int)b, 0x1e010027);
    strcpy(d_1c21b4, a);
    if (*(signed char*)b != 0) {
      T2(0x1e0100d0);
      strcat(d_1c21b4, b);
    }
    delete a;
    delete b;
    break; }
  case 0x1da:
    d_1c21b4[0] = 0;
    T1(0x1e010028);
    if (GE(d_1c0e84, 1) && (T2(0x1e010029), GE(d_1c0e84, 2)) && (T2(0x1e01002a), GE(d_1c0e84, 3)) && (T2(0x1e01002b), GE(d_1c0e84, 4)))
      T2(0x1e01002c);
    break;
  case 0x13e: T1(0x1e010014); break;
  case 0x1d4: T1(0x1e010043); break;
  case 0xf2: T1(0x1e010061); break;
  case 0xcd: T1(0x1e010058); break;
  }
  f_0a7840((RivaItemDefinition *)((*(int**)&d_1c2c40)[(short)p2]),(char *)( (int)d_1c27a8), 1);
  f_0e8a30((short)p2);
}
//@ f_138330
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt eines der 17 alchemistischen Rezepte (p2: 0xa7 *Rezept für Expurgicum* bis 0x1b3
 *   *Rezept für Anti-MU-Elixier*) auf einer oder zwei Seiten über die Pergament-Ansicht f_135200 an, setzt beim
 *   Lesen des *Rezepts für Anti-Hypnotikum* (0x170) das globale Bekanntheitsflag d_1c0e88 = 1 und bietet danach
 *   bei eingeschalteter Druckoption (d_1bfaf0 != -1) das Ausdrucken über f_137ad0 an.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (arg) sowie die Gegenstandskennung des Rezepts (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: buf sichert die aktuelle Farbpalette (768 Bytes) vor der Pergament-Darstellung und
 *   stellt sie danach über f_099ef0 wieder her; opcode hält die 16-Bit-Rezeptkennung.
 === Ende Beschreibung === */
void f_138330(int arg, int p2)
{
  int p1=0;p1=arg;
  unsigned short opcode = (unsigned short)p2;
  struct Empty { Empty() {} };
  char *buf;
  buf = (char *)f_147c84(new (mark(d_1a8e28, 0xb54)) char[0x300], 0x100, d_1baac0);
  buf = buf ? buf : 0;
  f_149eb4(buf, 0, 0x100);
  switch (opcode) {
  case 0xa7: f_135200(0x1e010052, 3, 0); break;
  case 0xa9: f_135200(0x1e010053, 3, 0); break;
  case 0xca: f_135200(0x1e010054, 3, 0); break;
  case 0xcb: f_135200(0x1e010055, 3, 0); break;
  case 0xcc: f_135200(0x1e010056, 1, 0); f_135200(0x1e010057, 2, 0); break;
  case 0xcd: f_135200(0x1e010058, 3, 0); break;
  case 0xce: f_135200(0x1e01005c, 1, 0); f_135200(0x1e01005d, 2, 0); break;
  case 0xba: f_135200(0x1e01005e, 3, 0); break;
  case 0xf0: f_135200(0x1e01005f, 1, 0); f_135200(0x1e010060, 2, 0); break;
  case 0xf2: f_135200(0x1e010061, 3, 0); break;
  case 0xf4: f_135200(0x1e010064, 3, 0); break;
  case 0xf1: f_135200(0x1e010065, 3, 0); break;
  case 0x152: f_135200(0x1e010066, 1, 0); f_135200(0x1e010067, 2, 0); break;
  case 0x170: *(unsigned char*)&d_1c0e88 = 1; f_135200(0x1e010001, 3, 0); break;
  case 0x197: f_135200(0x1e010059, 1, 0); f_135200(0x1e01005a, 2, 0); break;
  case 0x1b3: f_135200(0x1e01005b, 3, 0); break;
  case 0xf3: f_135200(0x1e010062, 1, 0); f_135200(0x1e010063, 2, 0); break;
  }
  f_099ef0(buf, 0, 0x100);
  delete buf;
  signed char flag=d_1bfaf0;
  if ((int)flag != -1 && f_0bf6f0((int)d_1c2c64, 0x1e0100cc) == 1)
    ((void(*)(int,int))f_137ad0)(p1, (int)(short)opcode);
}
