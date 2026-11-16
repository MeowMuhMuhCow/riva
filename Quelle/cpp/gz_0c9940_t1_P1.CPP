/* === Beschreibung (Katalog) ===
 * Einheit gz_0c9940_t1
 *
 * Diese Einheit implementiert den ersten Teil der Dungeon-Logik für die dritte Ebene der Zwergenmine (0x11,
 * Text-Overlay 0x35), einschließlich der Registrierung der Spielstand-Statusvariablen, der
 * Konstruktor-/Destruktor-Methoden des Dungeon-Handlers, des zentralen Aktions-Dispatchers f_0c9f00 sowie der
 * ersten Einsturz- und Fallenereignisse.
 === Ende Beschreibung === */
// P3 13/15 gleich (suche.py 29.10.2026, Basis gz_0c9940_t1_P1.CPP)
// OPT -4r -oneatx -zp1 -s -ou
// P3 11/15 gleich (suche.py 26.10.2026, Basis gz_0c9940_t1_P1.CPP)
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 6 gleich (vorher 6), Rest 1334 (vorher 1335)
// gz_0c9940_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C9940-0x0CAB30
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
#pragma aux f_05ff60 parm [eax] [edx] [ebx] modify exact [eax];
#pragma aux f_0f2720 parm [eax] [edx] [ebx] [ecx] modify exact [eax];
#define EQI(x,v) (((x)==(v))?1:0)
inline int EQ(int a,int b){return a==b;}
inline int EQC(signed char a, signed char b){return a==b;}
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
typedef short (*VF)(int,int,int);
struct LB { int a; int *p; int c; int d; int *q; };
int f_145234(int p1, int p2);
int f_145254();
int f_1454d0(int p1);
void f_014710(void *p);
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039420(int p1, int p2);
int f_039660(int p1, int p2);
int f_0396f0(int p1, int p2);
int f_039a80(int p1, int p2);
signed char f_042380(int p1);
signed char f_0423c0(int p1);
short f_042960(int p1);
short f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_044300(int p1, int p2);
int f_057220(int p1, int p2, int p3);
int f_05fa00(int p1, int p2);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_091f70(int p1);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0d4a60(int p1);
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcbb0(int p1, int p2);
short f_0dcf00(int p1, int p2, int p3);
int f_0dd750(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
int f_0e93f0(int p1, int p2, int p3);
int f_0f2720(int p1, int p2, int p3, int p4);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1); int f_1254a0(int p1, int);
short f_145850(int p1, int p2, int p3);
short f_1457e0(int p1);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
void f_0ca7c0(int p1);
void f_0ca820(int p1);
void f_0cab30(int p1);
void f_0cae50(int p1);
void f_0cb0a0(int p1);
int f_0cb410(int p1, int p2, int p3);
void f_0cb7d0(int p1);
void f_0cbb40(int p1, int p2);
void f_0cbda0(int p1, int p2);
void f_0cc010(int p1, int p2, int p3);
void f_0cc7a0(int p1, int p2);
void f_0cd000(int p1, int p2);
extern short d_1a9820;
extern char d_1bb380[]; extern char d_1bb3dc[];
extern signed char d_1bf2f8; extern short d_1bf2f9;
extern signed char d_1bf2fc; extern short d_1bf2fd;
extern signed char d_1bf300; extern short d_1bf301;
extern signed char d_1bf304; extern short d_1bf305;
extern signed char d_1bf308; extern short d_1bf309;
extern signed char d_1bf30c; extern short d_1bf30d;
extern signed char d_1bf310; extern short d_1bf311;
extern signed char d_1bf314; extern short d_1bf315;
extern signed char d_1bf318; extern short d_1bf319;
extern signed char d_1bf31c; extern short d_1bf31d;
extern signed char d_1bf320; extern short d_1bf321;
extern signed char d_1bf324; extern short d_1bf325;
extern signed char d_1bf328; extern short d_1bf329;
extern signed char d_1bf32c; extern short d_1bf32d;
extern signed char d_1bf330; extern short d_1bf331;
extern signed char d_1bf334; extern short d_1bf335;
extern signed char d_1bf338; extern short d_1bf339;
extern signed char d_1bf33c; extern short d_1bf33d;
extern signed char d_1bf340; extern short d_1bf341;
extern signed char d_1bf344; extern short d_1bf345;
extern signed char d_1bf348; extern short d_1bf349;
extern signed char d_1bf34c; extern short d_1bf34d;
extern char d_1bf350; extern short d_1bf351;
extern char d_1bf354; extern short d_1bf355;
extern short d_1bf358; extern short d_1bf35a;
extern short d_1bf35c; extern short d_1bf35e;
extern int d_1bf360;
extern int d_1c0004;
extern short d_1c212a; extern int *d_1c212c;
extern short d_1c2132; extern int *d_1c2134;
extern char d_1c2c00[]; extern char d_1c2c64[]; extern char d_1c2edc[];
extern char d_1c3498[]; extern char d_1c349c[]; extern char d_1c3870[]; extern char d_1c38b0[];
extern char d_1bb3c8[];
//@ f_0c9940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der löschende Destruktor einer Dungeon-Hilfsklasse (d_1bb380), der das Basisobjekt
 *   über f_060030(p1, 1) abbaut und abhängig von den Flags in p2 den Objektspeicher freigibt.
 * - Eingaben: Übergeben werden der this-Zeiger p1 sowie das Destruktor-Steuerflag p2 (& 2 für Einzelfreigabe, &
 *   4 für Array-Abbau).
 * - Rückgabewert: Zurückgegeben wird die Adresse des abgebauten Objekts p1.
 === Ende Beschreibung === */
int f_0c9940(int p1, int p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb380);
    f_145254();
    return p1;
  }
  r = f_060030(p1, 1);
  if (p2 & 2) f_014710((void *)r);
  return r;
}
int f_0c9980(void)
{
  return 1;
}
//@ f_0c9990
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Hilfs- oder Platzhaltermethode gibt konstant den Wert 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert stets 0 zurück.
 === Ende Beschreibung === */
int f_0c9990(void)
{
  return 0;
}
inline int codex_bar9990(void) { return d_1bb380[0] ? 0 : 0; }
static int (*codex_keep9990)(void) = codex_bar9990;
//@ f_0c99a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Hilfs- oder Platzhaltermethode gibt ebenfalls konstant den Wert 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert stets 0 zurück.
 === Ende Beschreibung === */
int f_0c99a0(void)
{
  return 0;
}
//@ f_0c99b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt die in der Maske p2 angegebenen Bits in dem über p1 adressierten Statusbyte
 *   mittels bitweisem ODER (*p1 |= p2).
 * - Eingaben: Übergeben werden der Zeiger p1 auf das zu verändernde Statusbyte sowie die Bitmaske p2.
 * - Rückgabewert: Zurückgegeben wird der aktualisierte Bytewert *p1.
 === Ende Beschreibung === */
unsigned char f_0c99b0(unsigned char *p1, int p2)
{
  *p1 |= (unsigned char)p2; return *p1;
}
//@ f_0c99c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft, welche Bits der Maske p2 in dem über p1 adressierten Statusbyte gesetzt
 *   sind (*p1 & p2).
 * - Eingaben: Übergeben werden der Zeiger p1 auf das Statusbyte sowie die zu prüfende Bitmaske p2.
 * - Rückgabewert: Zurückgegeben wird das Ergebnis der bitweisen UND-Verknüpfung.
 === Ende Beschreibung === */
unsigned char f_0c99c0(unsigned char *p1, int p2)
{
  return *p1 & (unsigned char)p2;
}
//@ f_0c99d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion setzt die 24 Byte-Statusvariablen (d_1bf2f8 bis d_1bf354, IDs 0x1d1
 *   bis 0x1e6, 0x265, 0x267) sowie die beiden Wort-Bitmasken (d_1bf358 und d_1bf35c, IDs 7 und 8) der dritten
 *   Zwergenminen-Ebene auf 0 zurück und trägt sie in die globalen Spielstand-Serialisierungslisten (d_1c212a,
 *   d_1c2132) ein.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
#define DD ((int)&d_1c2c64)
#define NEWC(V,ln,ctor) { int t_ = (int)operator new(0x13e, mark(d_1a67f4, ln)); V = (t_ != 0) ? f_0104b0(t_, ctor, 0, 0) : t_; }
#define ENDC(V,K) f_0bf6c0(DD, 6); f_0bf980(DD, V, 0, K, 0); f_0bf680(DD); if (V != 0) operator delete((void *)f_010590(V, 0));
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int p2);
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);
short f_0bf820(int, ...);
short f_0bf980(int, ...);
short f_0de1c0(int p1, int p2, int p3);
void f_0fca60(int p1);
extern int d_0001d4;
extern int d_0001d5;
extern int d_0001d6;
extern const char d_1a67f4[];
struct SO { int a; int *p; char pad[0x34]; };
int f_0fbe10(int p1);
void f_0c99d0(void);
void f_0fc0d0(int p1, int p2, int p3);
void f_0fc5a0(int p1, int p2);
#define RIVA_LIST1 (*(int * *)&d_1c212c)
#define RIVA_IDX1 (d_1c212a)
#define RIVA_LIST2 (*(int * *)&d_1c2134)
#define RIVA_IDX2 (d_1c2132)
#define REGISTER1(E,N) { *(signed char *)(E) = 0; *(short *)((char *)(E) + 1) = (N); RIVA_LIST1[RIVA_IDX1 = RIVA_IDX1 + 1] = (int)(E); }
#define REGISTER2(E,N) { (E)[0] = 0; (E)[1] = (N); RIVA_LIST2[RIVA_IDX2 = RIVA_IDX2 + 1] = (int)(E); }
struct RF700_0c99d0B;
struct OF700_0c99d0B { signed char flag; short number; char pad; OF700_0c99d0B *init(RF700_0c99d0B &r,short id,signed char f); };
struct RF700_0c99d0B {short count; OF700_0c99d0B **list; void append(OF700_0c99d0B *o) {list[count]=o;count++;}};
inline OF700_0c99d0B *OF700_0c99d0B::init(RF700_0c99d0B &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RF700_0c99d0B regF700_0c99d0B;
#pragma aux regF700_0c99d0B "d_1c212a"
extern OF700_0c99d0B obF700_0c99d0_1bf2f8;
#pragma aux obF700_0c99d0_1bf2f8 "d_1bf2f8"
extern OF700_0c99d0B obF700_0c99d0_1bf2fc;
#pragma aux obF700_0c99d0_1bf2fc "d_1bf2fc"
extern OF700_0c99d0B obF700_0c99d0_1bf300;
#pragma aux obF700_0c99d0_1bf300 "d_1bf300"
extern OF700_0c99d0B obF700_0c99d0_1bf304;
#pragma aux obF700_0c99d0_1bf304 "d_1bf304"
extern OF700_0c99d0B obF700_0c99d0_1bf308;
#pragma aux obF700_0c99d0_1bf308 "d_1bf308"
extern OF700_0c99d0B obF700_0c99d0_1bf30c;
#pragma aux obF700_0c99d0_1bf30c "d_1bf30c"
extern OF700_0c99d0B obF700_0c99d0_1bf310;
#pragma aux obF700_0c99d0_1bf310 "d_1bf310"
extern OF700_0c99d0B obF700_0c99d0_1bf314;
#pragma aux obF700_0c99d0_1bf314 "d_1bf314"
extern OF700_0c99d0B obF700_0c99d0_1bf318;
#pragma aux obF700_0c99d0_1bf318 "d_1bf318"
extern OF700_0c99d0B obF700_0c99d0_1bf31c;
#pragma aux obF700_0c99d0_1bf31c "d_1bf31c"
extern OF700_0c99d0B obF700_0c99d0_1bf320;
#pragma aux obF700_0c99d0_1bf320 "d_1bf320"
extern OF700_0c99d0B obF700_0c99d0_1bf324;
#pragma aux obF700_0c99d0_1bf324 "d_1bf324"
extern OF700_0c99d0B obF700_0c99d0_1bf328;
#pragma aux obF700_0c99d0_1bf328 "d_1bf328"
extern OF700_0c99d0B obF700_0c99d0_1bf32c;
#pragma aux obF700_0c99d0_1bf32c "d_1bf32c"
extern OF700_0c99d0B obF700_0c99d0_1bf330;
#pragma aux obF700_0c99d0_1bf330 "d_1bf330"
extern OF700_0c99d0B obF700_0c99d0_1bf334;
#pragma aux obF700_0c99d0_1bf334 "d_1bf334"
extern OF700_0c99d0B obF700_0c99d0_1bf338;
#pragma aux obF700_0c99d0_1bf338 "d_1bf338"
extern OF700_0c99d0B obF700_0c99d0_1bf33c;
#pragma aux obF700_0c99d0_1bf33c "d_1bf33c"
extern OF700_0c99d0B obF700_0c99d0_1bf340;
#pragma aux obF700_0c99d0_1bf340 "d_1bf340"
extern OF700_0c99d0B obF700_0c99d0_1bf344;
#pragma aux obF700_0c99d0_1bf344 "d_1bf344"
extern OF700_0c99d0B obF700_0c99d0_1bf348;
#pragma aux obF700_0c99d0_1bf348 "d_1bf348"
extern OF700_0c99d0B obF700_0c99d0_1bf34c;
#pragma aux obF700_0c99d0_1bf34c "d_1bf34c"
extern OF700_0c99d0B obF700_0c99d0_1bf350;
#pragma aux obF700_0c99d0_1bf350 "d_1bf350"
extern OF700_0c99d0B obF700_0c99d0_1bf354;
#pragma aux obF700_0c99d0_1bf354 "d_1bf354"
struct RF700_0c99d0W;
struct OF700_0c99d0W { short flag; short number;  OF700_0c99d0W *init(RF700_0c99d0W &r,short id,short f); };
struct RF700_0c99d0W {short count; OF700_0c99d0W **list; void append(OF700_0c99d0W *o) {list[count]=o;count++;}};
inline OF700_0c99d0W *OF700_0c99d0W::init(RF700_0c99d0W &r,short id,short f) {flag=f;number=id;r.append(this);return this;}
extern RF700_0c99d0W regF700_0c99d0W;
#pragma aux regF700_0c99d0W "d_1c2132"
extern OF700_0c99d0W obF700_0c99d0_1bf358;
#pragma aux obF700_0c99d0_1bf358 "d_1bf358"
extern OF700_0c99d0W obF700_0c99d0_1bf35c;
#pragma aux obF700_0c99d0_1bf35c "d_1bf35c"
void f_0c99d0(void) {
obF700_0c99d0_1bf2f8.init(regF700_0c99d0B,0x1d1,0);
obF700_0c99d0_1bf2fc.init(regF700_0c99d0B,0x1d2,0);
obF700_0c99d0_1bf300.init(regF700_0c99d0B,0x1d3,0);
obF700_0c99d0_1bf304.init(regF700_0c99d0B,0x1d4,0);
obF700_0c99d0_1bf308.init(regF700_0c99d0B,0x1d5,0);
obF700_0c99d0_1bf30c.init(regF700_0c99d0B,0x1d6,0);
obF700_0c99d0_1bf310.init(regF700_0c99d0B,0x1d7,0);
obF700_0c99d0_1bf314.init(regF700_0c99d0B,0x1d8,0);
obF700_0c99d0_1bf318.init(regF700_0c99d0B,0x1d9,0);
obF700_0c99d0_1bf31c.init(regF700_0c99d0B,0x1da,0);
obF700_0c99d0_1bf320.init(regF700_0c99d0B,0x1db,0);
obF700_0c99d0_1bf324.init(regF700_0c99d0B,0x1dc,0);
obF700_0c99d0_1bf328.init(regF700_0c99d0B,0x1dd,0);
obF700_0c99d0_1bf32c.init(regF700_0c99d0B,0x1de,0);
obF700_0c99d0_1bf330.init(regF700_0c99d0B,0x1df,0);
obF700_0c99d0_1bf334.init(regF700_0c99d0B,0x1e0,0);
obF700_0c99d0_1bf338.init(regF700_0c99d0B,0x1e1,0);
obF700_0c99d0_1bf33c.init(regF700_0c99d0B,0x1e2,0);
obF700_0c99d0_1bf340.init(regF700_0c99d0B,0x1e3,0);
obF700_0c99d0_1bf344.init(regF700_0c99d0B,0x1e4,0);
obF700_0c99d0_1bf348.init(regF700_0c99d0B,0x1e5,0);
obF700_0c99d0_1bf34c.init(regF700_0c99d0B,0x1e6,0);
obF700_0c99d0_1bf350.init(regF700_0c99d0B,0x265,0);
obF700_0c99d0_1bf354.init(regF700_0c99d0B,0x267,0);
obF700_0c99d0_1bf358.init(regF700_0c99d0W,0x7,0);
obF700_0c99d0_1bf35c.init(regF700_0c99d0W,0x8,0);
}

#undef REGISTER1
#undef REGISTER2

//@ f_0c9e60
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Dungeon-Handler-Objekt für die dritte Ebene der Zwergenmine
 *   (0x11), trägt die virtuelle Methodentabelle d_1bb3dc ein, lädt das Lösungswort des Buchstabenrätsels
 *   (0x35000179) in den Objektspeicher ab Offset +0xc, wandelt es über f_1454d0 in Großbuchstaben um und
 *   speichert dessen Adresse in d_1bf360.
 * - Eingaben: Als Parameter wird der this-Zeiger p1 des zu initialisierenden Dungeon-Objekts übergeben.
 * - Rückgabewert: Zurückgegeben wird der initialisierte Objektzeiger p1.
 === Ende Beschreibung === */
int f_0c9e60(int p1)
{
  int p2;
  int iVar1;
  iVar1 = f_05ff60(p1, 0x11);
  I(iVar1, 8) = (int)d_1bb3dc;
  p2 = iVar1 + 0xc;
  W(iVar1, 0x20) = 0;
  f_0e93f0((int)d_1c38b0, p2, 0x35000179);
  f_1454d0(p2);
  d_1bf360 = p2;
  return iVar1;
}
//@ f_0c9eb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser löschende Destruktor baut das Dungeon-Handler-Objekt der dritten Zwergenminen-Ebene (d_1bb3dc)
 *   ab, setzt den globalen Zeiger d_1bf360 auf 0 zurück, ruft den Basisdestruktor f_060030(p1, 1) auf und gibt
 *   bei gesetztem Bit 2 in p2 den Speicher frei.
 * - Eingaben: Übergeben werden der this-Zeiger p1 sowie das Destruktor-Steuerflag p2.
 * - Rückgabewert: Zurückgegeben wird die Adresse des abgebauten Objekts p1.
 === Ende Beschreibung === */
int f_0c9eb0(int p1, unsigned p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb3c8);
    f_145254();
    return p1;
  }
  d_1bf360 = 0;
  I(p1, 8) = (int)d_1bb3dc;
  r = f_060030(p1, 1);
  if (p2 & 2) f_014710((void *)r);
  return r;
}
//@ f_0c9f00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der zentrale Aktions- und Ereignis-Dispatcher der dritten Zwergenminen-Ebene, der
 *   abhängig vom ausgelösten Ereigniscode p2 auf Fallen (0x65-0x6b), Teleporter, Brücken-/Wasserhindernisse
 *   (f_0cc010), das Buchstaben-/Passworträtsel (0x82-0x8a, f_0cd000, f_0cb410) sowie Endkämpfe (0x191, 0x192)
 *   verzweigt.
 * - Eingaben: Übergeben werden der this-Zeiger p1 des Dungeon-Handlers sowie der Ereignis- oder Objektcode p2.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis behandelt wurde, oder 0 bei einem unbekannten
 *   Ereigniscode.
 === Ende Beschreibung === */
static inline int IS12(const signed char &x, signed char v) { return x == v; }
static inline int IS12_1(int a, signed char v) { return a == v; } // haelt die Registerzuteilung wie im Original
int f_147323_local(int, int, int, int, int, int, int);
#pragma aux f_147323_local "f_147323" modify [esp];
int f_0f2720_single(int);
#pragma aux f_0f2720_single "f_0f2720" parm [eax] modify exact [eax];
int f_0c9f00(int p1, int p2)
{
  int result = 1;
  struct Local60 { int a; int *p; int pad[13]; } loc;
  switch ((unsigned short)p2) {
  case 100:
    if (f_0bf6f0((int)d_1c2c64, 0x35000124) == result) {
      { int t_ = (int)*(void **)&d_1c0004; f_0dd7f0(t_, 0x10, 0x13f8); } // haelt die Registerzuteilung wie im Original
      return result;
    }
    break;
  case 0x65:
    if (IS12(d_1bf2f8, 0)) f_0cbb40(p1, 0);
    if (EQ(d_1bf2f8, 1)) {
      f_0dd750(d_1c0004, 0x14bd);
      return result;
    }
    break;
  case 0x67:
    f_0cab30(p1);
    return result;
  case 0x68:
    f_0cbda0(p1, 2);
    return result;
  case 0x69: {
    if (IS12(d_1bf308, 2)) {
      f_0cc010(p1, 0x15fb, 0x1267);
      return result;
    }
    f_0cc010(p1, 0x16c3, 0x1267);
    return result;
  }
  case 0x6a:
    f_0cc7a0(p1, 0x350028);
    return result;
  case 0x6b:
    f_0cae50(p1);
    return result;
  case 0x1f44:
    f_0cb0a0(p1);
    return result;
  case 0x6d: {
    if (IS12_1(d_1bf308, 2)) { // haelt die Registerzuteilung wie im Original
      f_0cc010(p1, 0x164d, 0x1267);
      return result;
    }
    f_0cc010(p1, 0x1585, 0x1267);
    return result;
  }
  case 0x6e:
    f_0cc7a0(p1, 0x35002a);
    return result;
  case 0x6f:
    if (IS12(d_1bf2f8, 0)) f_0cbb40(p1, 1);
    if (EQ(d_1bf2f8, 1)) {
      f_0dd750(d_1c0004, 0x146b);
      return result;
    }
    break;
  case 0x71:
    f_0dd750(d_1c0004, 0x13f5);
    return result;
  case 0x72:
    f_0dd750(d_1c0004, 0x1533);
    return result;
  case 0x1b5d:
  case 0x1f45:
    f_05fa00(0x17, 0x1f45);
    return result;
  case 0x1b5f:
  case 0x1f47:
    f_05fa00(0x19, 0x1f47);
    return result;
  case 0x1f4a: {
    signed char flag = *(signed char *)&d_1bf350; // haelt die Registerzuteilung wie im Original
    flag &= 1;
    if (flag == (signed char)0) f_0cb410(p1, 0x1f4a, 0);
    return result;
  }
  case 0x1f4d:
    if (f_0cb410(p1, 0x1f4d, 2) == 1) {
      if (EQ(d_1bf318, 0)) {
        int large = 0x8000;
        f_147323_local((int)d_1c2edc, 0x35003e, 0x7fff, large, *(volatile int *)((char *)&d_1a9820 + (large - 0x8000)), 0, 1);
        f_0bf730((int)d_1c2c64, 0x35000196);
        f_0dcbb0(d_1c0004, 0x3c);
        *(char *)&d_1bf318 = 1; // haelt die Registerzuteilung wie im Original
        f_091f70(3);
        return result;
      }
      int large = 0x8000;
      f_147323_local((int)d_1c2edc, 0x35003f, 0x7fff, large, *(volatile int *)((char *)&d_1a9820 + (large - 0x8000)), 0, 1);
      f_0bf730((int)d_1c2c64, 0x35000197);
    }
    return result;
  case 0x1f49: {
    signed char flag = *(signed char *)&d_1bf350; // haelt die Registerzuteilung wie im Original
    flag &= 2;
    if (flag == (signed char)0) f_0cb410(p1, 0x1f49, 0);
    return result;
  }
  case 0xcd:
    f_0cb410(p1, 0x1f4a, 1);
    return result;
  case 0xce:
    f_0cb410(p1, 0x1f49, 1);
    return result;
  case 0x12d: {
    signed char zero = 0;
    int state = d_1bf348;
    int need = zero;
    if (EQ(state, need)) *(char *)&d_1bf348 = 1; // haelt die Registerzuteilung wie im Original
    f_05fa00(0, 0x1f4b);
    f_060800(0x35002e, 0, 0);
    f_05fa00(0, 0x1f4b);
    return result;
  }
  case 0x12e:
    f_0cb7d0(p1);
    return result;
  case 0x191: {
    int actor = p1;
    if (EQ(d_1bf348, 1)) {
      int speed = 2;
      f_0f2720_single(10);
      if ((short)((VF *)I(actor, 8))[0](actor, speed, 0) == 0) {
        d_1bf348 = 2;
        f_0f2720_single(0xc);
        f_091f70(5);
        f_057220((int)d_1c2c00, 0x803003f, 0);
        return result;
      }
    }
    return result;
  }
  case 0x192: {
    int actor = p1;
    if (EQ(d_1bf348, 2)) {
      f_0bf730((int)d_1c2c64, 0x3500019c);
      if (((VF *)I(actor, 8))[0](actor, 0x3c, 0) == 0) {
        d_1bf348 = 3;
        f_0f2720_single(5);
        f_057220((int)d_1c2c00, 0x8030040, 0);
        return result;
      }
    }
    return result;
  }
  case 0x1f48:
    if (EQ(d_1bf34c, 0)) {
      int t_393 = f_0bf6f0((int)d_1c2c64, 0x3500019d);
      if (t_393 == 1) {
        if ((short)f_0dcf00(d_1c0004, 0x1bd, 1) == result) {
          *(char *)&d_1bf34c = 1; // haelt die Registerzuteilung wie im Original
          f_060740(0x1f48, 1);
          f_0607e0(0x1f48, 1);
          return result;
        }
      }
    } else {
      f_0bf730((int)d_1c2c64, 0x3500019e);
    }
    return result;
  case 0x194: {
    if (f_0d54f0(d_1c0004, 0x1bd) != -1) {
      f_0bf730((int)d_1c2c64, 0x35000198);
      return result;
    }
    signed char one = 1;
    int state = d_1bf34c;
    int need = one;
    if (!EQ(state, need)) {
      f_125400((int)&loc, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
      loc.p[1] = f_0396f0(d_1c0004, 7);
      f_0bf730((int)d_1c2c64, 0x35000199);
      f_1254a0((int)&loc, 0);
    }
    return result;
  }
  case 0x82: case 0x83: case 0x84: case 0x85: case 0x86:
  case 0x87: case 0x88: case 0x89: case 0x8a:
    f_0cd000(p1, (short)(p2 - 0x82));
    return result;
  case 0x1b5e:
  case 0x1f46:
    f_05fa00(0x18, 0x1f46);
    return result;
  case 0x70:
    f_0cbda0(p1, 3);
    return result;
  case 0x66:
    f_0ca820(p1);
    return result;
  case 0x73:
    f_0cc010(p1, 0x1585, 0x1267);
    return result;
  case 0x74:
    f_0cc010(p1, 0x16c3, 0x1267);
    return result;
  case 0xd0:
    return result;
  default:
    result = 0;
    break;
  }
  return result;
}
//@ f_0ca720
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion führt für den Helden p1 eine Attributsprobe auf die Eigenschaft p2 mit dem
 *   Modifikator p3 (f_044900) durch und wandelt das Ergebnis in einen Wahrheitswert (1 bei Erfolg, 0 bei
 *   Fehlschlag) um.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur, der Attributsindex p2 sowie der
 *   Proben-Modifikator p3.
 * - Rückgabewert: Zurückgegeben wird 1 bei bestandener Probe (> 0), andernfalls 0.
 === Ende Beschreibung === */
int f_0ca720(int p1, int p2, int p3)
{
  int r;
  r = 0;
  if (f_044900(p1, (short)p2, (short)p3) > 0) r = 1;
  return r;
}
//@ f_0ca740
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler am Ausgang der dritten Ebene (0x35000124), ob die Gruppe den Bereich
 *   verlassen möchte, und wechselt bei Bestätigung zurück in die zweite Ebene der Zwergenmine (0x10,
 *   Zielposition 0x13f8).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ca740(void)
{
  int iVar1;
  iVar1 = f_0bf6f0((int)d_1c2c64, 0x35000124);
  if (iVar1 == 1) f_0dd7f0(d_1c0004, 0x10, 0x13f8);
}
//@ f_0ca770
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löst beim ersten Betreten (d_1bf2f8 == 0) die Deckenfalle f_0cbb40(p1, 0) aus und
 *   versetzt die Gruppe nach deren Auslösung (d_1bf2f8 == 1) auf das Feld 0x14bd.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf den Dungeon-Handler übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ca770(int p1)
{
  if (EQI(d_1bf2f8, 0)) f_0cbb40(p1, 0);
  if (EQI(d_1bf2f8, 1)) f_0dd750(d_1c0004, 0x14bd);
}
//@ f_0ca7c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Schadens-Callback-Funktion fügt einem handlungsfähigen Helden p1 bei einem Steinschlag oder
 *   einer Falle (2W6+4 - Rüstungsschutz) + 1W6 Schadenspunkte über f_044300 zu.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ca7c0(int p1)
{
  short sVar2;
  int iVar4;
  iVar4 = f_0d4a60(p1);
  if (iVar4 != 0) {
    sVar2 = f_145850(2, 6, 4);
    sVar2 = sVar2 - f_0423c0(p1);
    if (sVar2 < 0) sVar2 = 0;
    sVar2 += f_1457e0(6);
    f_044300(p1, sVar2);
  }
}
//@ f_0ca820
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt beim ersten Betreten (d_1bf2fc == 0) eine gefährliche Steinschlag- oder
 *   Einsturzfalle ab, die einen einzelnen Helden sofort erschlägt (0x3500013c), während bei einer Gruppe eine
 *   stark erschwerte Sinnesschärfe-Probe (0x33, +18) des Anführers sowie eine Gewandtheits-/Attributsprobe (1)
 *   des besten Gefahreninstinkt-Helden (0x32) entscheiden, ob nur ein einzelner Held oder die gesamte Gruppe
 *   durch f_0ca7c0 verletzt wird.
 * - Eingaben: Als Parameter wird ein ungenutzter Kontextwert unused übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ca820(int unused)
{
  short f_044c90_c(int, int, signed char);
#pragma aux f_044c90_c "f_044c90" parm [eax] [edx] [ebx] modify exact [eax edx ebx]
  struct Obj { int a; int *p; int c, d; int *q; int pad[10]; } obj;
  int hero, first, other, candidate, yes, hit;
  short value;
  if (EQI(d_1bf2fc, 0)) {
    first = hero = f_038c40(d_1c0004);
    other = f_039320(d_1c0004, 0x32);
    f_125400((int)&obj, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
    value = f_0db9a0(d_1c0004);
    if (value == 1) {
      int snd;
      f_147323((int)d_1c2edc, 0x35003b, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
      obj.p[1] = hero;
      f_0bf730((int)d_1c2c64, 0x3500013c);
      f_044850(hero, f_042960(hero), 4);
      f_0bf730((int)d_1c2c64, 0x3500012f);
    } else {
      yes = 0;
      value = f_044c90_c(hero, 0x33, (signed char)(value = 0x12));
      if (value > 1) yes = 1;
      if (yes == 1) {
        obj.p[1] = first;
        obj.p[2] = other;
        f_0bf730((int)d_1c2c64, 0x35000130);
        obj.p[1] = other;
        f_0bf730((int)d_1c2c64, 0x35000131);
        hit = 0;
        value = f_044900(other, yes, -3);
        if (value > 0) hit = yes;
        if (hit == 0) {
          int snd;
          f_147323((int)d_1c2edc, 0x35003b, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
          obj.p[1] = other;
          f_0bf730((int)d_1c2c64, 0x35000132);
          f_0ca7c0(other);
          obj.p[1] = other;
          if (f_042960(other) >= 5) {
            f_0bf730((int)d_1c2c64, 0x35000133);
          } else if (f_042960(other) > 0) {
            int zero = 0;
            do {
              candidate = f_039660(d_1c0004, zero);
            } while (candidate == other);
            obj.p[2] = candidate;
            obj.q[1] = f_042380(other) != 0 ? 0x35000135 : 0x35000134;
            f_0bf730((int)d_1c2c64, 0x35000136);
          } else {
            obj.p[2] = f_039420(d_1c0004, 0xf);
            f_0bf730((int)d_1c2c64, 0x35000137);
          }
        } else {
          int snd;
          f_147323((int)d_1c2edc, 0x35003b, 0x7fff, 0x8000, (snd = *(int *)&d_1a9820), 0, 1);
          obj.p[1] = other;
          f_0bf730((int)d_1c2c64, 0x35000138);
          if (f_044900(other, 1, 4) > 0) {
            f_0bf730((int)d_1c2c64, 0x35000139);
          } else {
            f_0bf730((int)d_1c2c64, 0x3500013a);
            f_0ca7c0(other);
            if (f_042960(other) < 5) {
              obj.p[1] = f_038be0(d_1c0004);
            }
            f_0bf730((int)d_1c2c64, 0x3500013b);
          }
        }
      } else {
        obj.p[1] = other;
        f_0bf730((int)d_1c2c64, 0x3500013c);
        f_039a80(d_1c0004, (int)f_0ca7c0);
        if (f_0db9a0(d_1c0004) <= 1) goto finish;
        obj.p[1] = f_039320(d_1c0004, 0x32);
        f_0bf730((int)d_1c2c64, 0x3500013d);
      }
    }
finish:
    d_1bf2fc = 1;
    f_1254a0((int)&obj, 0);
  }
}
