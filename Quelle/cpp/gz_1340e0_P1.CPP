/* === Beschreibung (Katalog) ===
 * Einheit gz_1340e0 (0x1340E0 - 0x135040)
 *
 * Überblick
 * Diese Einheit enthält zwei logisch getrennte Bereiche: Im vorderen Teil (f_1340e0 bis f_134380) implementiert
 * sie eine generische dynamische Array- bzw. Listenklasse mit benutzerdefinierten Vergleichs- und
 * Kopierfunktionen. Ab f_1343c0 bildet sie den Auftakt des großen Gegenstandsbenutzungs-Moduls (use.cpp), das
 * die 39 Methoden-Handler für das Benutzen und Kombinieren von Inventargegenständen registriert und die
 * allgemeinen Prüfungen (Bewusstsein, Magiebegabung, Ladungen, Kombinierbarkeit zweier Gegenstände) durchführt.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 15/20 gleich (suche.py 26.10.2026, Basis gz_1340e0_P1.CPP)
// gz_1340e0 (0x1340E0-0x135040), Optionen -4r -oneatx -zp1 -s
// gz_1340e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1340E0-0x135040
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_03d820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf820();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_10cba0(int, int);
int f_10cbc0(int, int);
short f_10ce80(int, short, short);
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
void f_134050(void *);
int f_138330(int p1, int p2);                           // reg eax edx stapel 0
short f_13bb70(int p1, int p2, int p3);                   // reg edx ebx stapel 0
short f_149360(int, int);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a47ea[];                    // 0x1A47EA
extern char d_1a4854[];                    // 0x1A4854
extern char d_1a489a[];                    // 0x1A489A
extern int d_1c0420;                    // 0x1C0420
extern volatile char d_1c042a;          // 0x1C042A: verhindert das Vorziehen von xor ebx,ebx ueber f_030850 in f_134f90
extern char d_1c0e7c;                    // 0x1C0E7C
extern short d_1c0e7d;                    // 0x1C0E7D
extern char d_1c0e80;                    // 0x1C0E80
extern short d_1c0e81;                    // 0x1C0E81
extern char d_1c0e84;                    // 0x1C0E84
extern short d_1c0e85;                    // 0x1C0E85
extern char d_1c0e88;                    // 0x1C0E88
extern short d_1c0e89;                    // 0x1C0E89
extern int d_1c0e8c;                    // 0x1C0E8C
extern int d_1c0e90;                    // 0x1C0E90
extern int d_1c0e94;                    // 0x1C0E94
extern int d_1c0e98;                    // 0x1C0E98
extern int d_1c0e9c;                    // 0x1C0E9C
extern int d_1c0ea0;                    // 0x1C0EA0
extern int d_1c0ea4;                    // 0x1C0EA4
extern int d_1c0ea8;                    // 0x1C0EA8
extern int d_1c0eac;                    // 0x1C0EAC
extern int d_1c0eb0;                    // 0x1C0EB0
extern int d_1c0eb4;                    // 0x1C0EB4
extern int d_1c0eb8;                    // 0x1C0EB8
extern int d_1c0ebc;                    // 0x1C0EBC
extern int d_1c0ec0;                    // 0x1C0EC0
extern int d_1c0ec4;                    // 0x1C0EC4
extern int d_1c0ec8;                    // 0x1C0EC8
extern int d_1c0ecc;                    // 0x1C0ECC
extern int d_1c0ed0;                    // 0x1C0ED0
extern int d_1c0ed4;                    // 0x1C0ED4
extern int d_1c0ed8;                    // 0x1C0ED8
extern int d_1c0edc;                    // 0x1C0EDC
extern int d_1c0ee0;                    // 0x1C0EE0
extern int d_1c0ee4;                    // 0x1C0EE4
extern int d_1c0ee8;                    // 0x1C0EE8
extern int d_1c0eec;                    // 0x1C0EEC
extern int d_1c0ef0;                    // 0x1C0EF0
extern int d_1c0ef4;                    // 0x1C0EF4
extern int d_1c0ef8;                    // 0x1C0EF8
extern int d_1c0efc;                    // 0x1C0EFC
extern int d_1c0f00;                    // 0x1C0F00
extern int d_1c0f04;                    // 0x1C0F04
extern int d_1c0f08;                    // 0x1C0F08
extern int d_1c0f0c;                    // 0x1C0F0C
extern int d_1c0f10;                    // 0x1C0F10
extern int d_1c0f14;                    // 0x1C0F14
extern int d_1c0f18;                    // 0x1C0F18
extern int d_1c0f1c;                    // 0x1C0F1C
extern int d_1c0f20;                    // 0x1C0F20
extern int d_1c0f24;                    // 0x1C0F24
extern int d_1c0f28;                    // 0x1C0F28
extern int d_1c0f2c;                    // 0x1C0F2C
extern int d_1c0f30;                    // 0x1C0F30
extern int d_1c0f34;                    // 0x1C0F34
extern int d_1c0f38;                    // 0x1C0F38
extern int d_1c0f3c;                    // 0x1C0F3C
extern int d_1c0f40;                    // 0x1C0F40
extern int d_1c0f44;                    // 0x1C0F44
extern int d_1c0f48;                    // 0x1C0F48
extern int d_1c0f4c;                    // 0x1C0F4C
extern int d_1c0f50;                    // 0x1C0F50
extern int d_1c0f54;                    // 0x1C0F54
extern int d_1c0f58;                    // 0x1C0F58
extern int d_1c0f5c;                    // 0x1C0F5C
extern int d_1c0f60;                    // 0x1C0F60
extern int d_1c0f64;                    // 0x1C0F64
extern int d_1c0f68;                    // 0x1C0F68
extern int d_1c0f6c;                    // 0x1C0F6C
extern int d_1c0f70;                    // 0x1C0F70
extern int d_1c0f74;                    // 0x1C0F74
extern int d_1c0f78;                    // 0x1C0F78
extern int d_1c0f7c;                    // 0x1C0F7C
extern int d_1c0f80;                    // 0x1C0F80
extern int d_1c0f84;                    // 0x1C0F84
extern int d_1c0f88;                    // 0x1C0F88
extern int d_1c0f8c;                    // 0x1C0F8C
extern int d_1c0f90;                    // 0x1C0F90
extern int d_1c0f94;                    // 0x1C0F94
extern int d_1c0f98;                    // 0x1C0F98
extern int d_1c0f9c;                    // 0x1C0F9C
extern int d_1c0fa0;                    // 0x1C0FA0
extern int d_1c0fa4;                    // 0x1C0FA4
extern int d_1c0fa8;                    // 0x1C0FA8
extern int d_1c0fac;                    // 0x1C0FAC
extern int d_1c0fb0;                    // 0x1C0FB0
extern int d_1c0fb4;                    // 0x1C0FB4
extern int d_1c0fb8;                    // 0x1C0FB8
extern int d_1c0fbc;                    // 0x1C0FBC
extern int d_1c0fc0;                    // 0x1C0FC0
extern int d_1c0fc4;                    // 0x1C0FC4
extern int d_1c0fc8;                    // 0x1C0FC8
extern int d_1c0fcc;                    // 0x1C0FCC
extern int d_1c0fd0;                    // 0x1C0FD0
extern int d_1c0fd4;                    // 0x1C0FD4
extern int d_1c0fd8;                    // 0x1C0FD8
extern int d_1c0fdc;                    // 0x1C0FDC
extern int d_1c0fe0;                    // 0x1C0FE0
extern int d_1c0fe4;                    // 0x1C0FE4
extern int d_1c0fe8;                    // 0x1C0FE8
extern int d_1c0fec;                    // 0x1C0FEC
extern int d_1c0ff0;                    // 0x1C0FF0
extern int d_1c0ff4;                    // 0x1C0FF4
extern int d_1c0ff8;                    // 0x1C0FF8
extern int d_1c0ffc;                    // 0x1C0FFC
extern int d_1c1000;                    // 0x1C1000
extern int d_1c1004;                    // 0x1C1004
extern int d_1c1008;                    // 0x1C1008
extern int d_1c100c;                    // 0x1C100C
extern int d_1c1010;                    // 0x1C1010
extern int d_1c1014;                    // 0x1C1014
extern int d_1c1018;                    // 0x1C1018
extern int d_1c101c;                    // 0x1C101C
extern int d_1c1020;                    // 0x1C1020
extern int d_1c1024;                    // 0x1C1024
extern int d_1c1028;                    // 0x1C1028
extern int d_1c102c;                    // 0x1C102C
extern int d_1c1030;                    // 0x1C1030
extern int d_1c1034;                    // 0x1C1034
extern int d_1c1038;                    // 0x1C1038
extern int d_1c103c;                    // 0x1C103C
extern int d_1c1040;                    // 0x1C1040
extern int d_1c1044;                    // 0x1C1044
extern int d_1c1048;                    // 0x1C1048
extern int d_1c104c;                    // 0x1C104C
extern int d_1c1050;                    // 0x1C1050
extern int d_1c1054;                    // 0x1C1054
extern int d_1c1058;                    // 0x1C1058
extern int d_1c105c;                    // 0x1C105C
extern int d_1c1060;                    // 0x1C1060
extern int d_1c1064;                    // 0x1C1064
extern int d_1c1068;                    // 0x1C1068
extern  short d_1c212a;                    // 0x1C212A
extern void **  d_1c212c;                    // 0x1C212C
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1c3498[];                    // 0x1C3498
extern const char d_1c349c[];                    // 0x1C349C
extern const char d_1c3870[];                    // 0x1C3870
typedef int (*FN)(int);
typedef FN (*FN2)(int);
struct U { unsigned short e; unsigned short n; short s4; unsigned short w; unsigned short c; short (*cmp)(char *, int); void (*cpy)(char *, int); char *data; };
struct E { FN2 f; int off; int x; };
struct G { int e; FN2 f; int off; int x; int h; int a14; short s18; short s1a; short s1c; short s1e; };
struct SO { int a; int *p4; int x8; int *pc; int *p10; char c14[12]; short *p20; char d[24]; SO(const char*,const char*,const char*); ~SO(); };
int f_10cba0(int, int, int);
int f_10ce80(int, int);
#define TT(i) ((*(int **)&d_1c2c40)[i])
void f_13bb50(void);
void f_13bb30(void);
void f_13bb10(void);
void f_13baf0(void);
void f_13bad0(void);
void f_13bab0(void);
void f_13ba90(void);
void f_13ba70(void);
void f_13ba50(void);
void f_13b9b0(void);
void f_13b990(void);
void f_13b8f0(void);
void f_13b840(void);
void f_13b7b0(void);
void f_13b180(void);
void f_13aea0(void);
void f_13ae40(void);
void f_13adb0(void);
void f_13ad00(void);
void f_13acf0(void);
void f_13abb0(void);
void f_13aa40(void);
void f_13a030(void);
void f_139f80(void);
void f_139f70(void);
void f_139e00(void);
void f_139da0(void);
void f_139020(void);
void f_138fe0(void);
void f_138e90(void);
void f_138c90(void);
void f_135920(void);
void f_135870(void);
void f_135600(void);
void f_135590(void);
void f_1354d0(void);
void f_135040(void);
void f_135010(void);
void f_134f90(void);
//@ f_1340e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert als Konstruktor eine dynamische Listenstruktur (p) mit der angegebenen
 *   Elementgröße (w) sowie je einem Funktionszeiger zum Vergleichen (c) und Kopieren (cp) von Elementen.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p), die Elementbreite in Bytes (w), die Vergleichsfunktion (c)
 *   und die Kopierfunktion (cp).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Setzt die Felder für den letzten Fehlercode (e), die aktuelle Elementanzahl (n), die
 *   Kapazität (s4), den Lesezeiger (c) und den Datenpuffer (data) auf 0.
 === Ende Beschreibung === */
void f_1340e0(U *p, short w, short (*c)(char *, int), void (*cp)(char *, int))
{
  p->e = 0; p->n = 0; p->s4 = 0; p->c = 0; p->data = 0;
  p->w = w; p->cmp = c; p->cpy = cp;
}
//@ f_134110
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt als Destruktor den dynamisch reservierten Datenpuffer (p->data) der Liste frei und
 *   setzt alle Zähler- und Zeigerfelder auf 0 zurück.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p) sowie ein ungenutzter Destruktor-Parameter.
 * - Rückgabewert: Gibt den Zeiger auf die Listenstruktur (p) zurück.
 * - Wichtige Variablen: Prüft p->data vor dem Aufruf von delete.
 === Ende Beschreibung === */
U *f_134110(U *p, int)
{
  U *r = p;
  p->e = 0;
  if (p->data) { delete p->data; r->data = 0; }
  r->n = 0; r->s4 = 0; r->c = 0; r->data = 0;
  return p;
}
//@ f_134150
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert den zuletzt aufgetretenen Fehlercode (p->e) der Listenstruktur zurück.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p).
 * - Rückgabewert: Gibt den 16-Bit-Fehlercode (p->e) zurück (0 bedeutet fehlerfrei).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_134150(U *p)
{
  return p->e;
}
//@ f_134160
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt den Fehlerstatus der Liste zurück und gibt die Anzahl der aktuell gespeicherten
 *   Elemente (p->n) zurück.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p).
 * - Rückgabewert: Gibt die Elementanzahl (p->n) zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_134160(U *p)
{
  p->e = 0;
  return p->n;
}
//@ f_134170
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Startet die sequentielle Iteration über die Liste, indem der interne Leseindex (p->c) auf 1
 *   gesetzt und ein Zeiger auf das erste Element (p->data) zurückgegeben wird.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p).
 * - Rückgabewert: Gibt einen Zeiger auf das erste Element oder 0 zurück, wenn die Liste leer ist (p->n == 0).
 * - Wichtige Variablen: Setzt p->e = 0 und p->c = 1.
 === Ende Beschreibung === */
char *f_134170(U *p)
{
  p->e = 0;
  p->c = 1;
  if (p->n == 0) return 0;
  return p->data;
}
//@ f_134190
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Liefert bei der Iteration über die Liste das jeweils nächste Element am aktuellen Leseindex
 *   (p->c) und erhöht diesen anschließend um 1.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p).
 * - Rückgabewert: Gibt einen Zeiger auf das aktuelle Element (p->data + p->c * p->w) oder 0 zurück, wenn das
 *   Listenende erreicht ist (p->c >= p->n).
 * - Wichtige Variablen: b enthält den Byte-Offset des Elements (p->c * p->w), i den inkrementierten Leseindex.
 === Ende Beschreibung === */
char *f_134190(U *p)
{
  int r;
  int b;
  unsigned short i;
  p->e = 0;
  if (p->c >= p->n) {
    r = 0;
  } else {
    b = (unsigned short)p->c;
    b *= p->w;
    i = p->c;
    ++i;
    r = (int)p->data;
    p->c = i;
    r += b;
  }
  return (char *)r;
}
//@ f_1341d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Greift wahlfrei auf das Listenelement mit dem Index i zu und setzt den internen Lesezeiger
 *   (p->c) auf das darauffolgende Element (i + 1).
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p) sowie der gewünschte Elementindex (i).
 * - Rückgabewert: Gibt einen Zeiger auf das Element i oder 0 zurück, wenn i >= p->n außerhalb des gültigen
 *   Bereichs liegt.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
char *f_1341d0(U *p, unsigned short i)
{
  p->c = i + 1;
  p->e = 0;
  if (p->n <= i) return 0;
  return p->data + i * p->w;
}
//@ f_134200
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht linear in der Liste (p) nach einem Element, für das die hinterlegte Vergleichsfunktion
 *   (p->cmp) mit dem Suchwert (v) den Wert 0 (Gleichheit) liefert.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p) sowie der Suchwert bzw. Vergleichszeiger (v).
 * - Rückgabewert: Gibt den 0-basierten Index (i) des gefundenen Elements oder 0xffff zurück, wenn kein passendes
 *   Element existiert.
 * - Wichtige Variablen: Die Schleifenvariable i durchläuft alle p->n Einträge; r ist mit 0xffff vorbelegt.
 === Ende Beschreibung === */
unsigned short f_134200(U *p, int v)
{
  unsigned short i, r;
  p->e = 0;
  r = 0xffff;
  i = 0;
  for (; i < p->n; i++) {
    if (p->cmp(i * p->w + p->data, v) == 0) {
      r = i; break;
    }
  }
  return r;
}
//@ f_134250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fügt ein neues Element (v) ohne Duplikatsprüfung am Ende der Liste (p) an, nachdem bei
 *   Bedarf über f_134050 der Speicherpuffer vergrößert wurde.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p) sowie der einzufügende Wert bzw. Quellzeiger (v).
 * - Rückgabewert: Gibt den Index des neu angefügten Elements (p->n vor dem Inkrement) oder im Fehlerfall 0xffff
 *   zurück.
 * - Wichtige Variablen: Bei Erreichen der Obergrenze 0xff00 wird der Fehlercode p->e = 0x409 (Überlauf) gesetzt.
 === Ende Beschreibung === */
unsigned short f_134250(U *p, int v)
{
  unsigned short r;
  p->e = 0;
  r = 0xffff;
  if (p->n == 0xff00) { p->e = 0x409; return r; }
  f_134050(p);
  if (p->e == 0) {
    p->cpy(p->n * p->w + p->data, v);
    r = p->n;
    p->n = r + 1;
  }
  return r;
}

static inline unsigned short search1342b0(U *p, int v)
{
  unsigned short i, r;
  p->e = 0;
  r = 0xffff;
  i = 0;
  for (; i < p->n; i++) {
    if (p->cmp(i * p->w + p->data, v) == 0) {
      return i;
    }
  }
  return r;
}
//@ f_1342b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fügt ein neues Element (v) nur dann am Ende der Liste (p) ein, wenn noch kein gleicher
 *   Eintrag in der Liste vorhanden ist; existiert bereits ein solches Element, wird das Einfügen mit dem
 *   Fehlercode 0x404 (Duplikat) abgelehnt.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p) sowie der einzufügende Wert bzw. Quellzeiger (v).
 * - Rückgabewert: Gibt den Index des neu eingefügten Elements oder im Fehler- bzw. Duplikatsfall 0xffff zurück.
 * - Wichtige Variablen: found speichert das Ergebnis der Vorabsuche (0xffff, wenn noch nicht vorhanden); p->e
 *   erhält 0x404 bei Duplikat oder 0x409 bei Listenüberlauf.
 === Ende Beschreibung === */
unsigned short f_1342b0(U *p, int v)
{
  struct Query182 { static inline unsigned short find(U *p, int v) {
    unsigned short i, r;
    p->e = 0; r = 0xffff; i = 0;
    for (; i < p->n; i++) {
      if (p->cmp(i * p->w + p->data, v) == 0) { r = i; break; }
    }
    return r;
  }};
  unsigned short found = 0;
  unsigned short r;
  p->e = 0;
  found = Query182::find(p, v);
  if (found == 0xffff) {
    r = 0xffff;
    U *dst = p;
    p->e = 0;
    if (p->n == 0xff00) {
      p->e = 0x409;
    } else {
      f_134050(p);
      if (p->e == 0) {
        dst->cpy(p->w * p->n + p->data, v);
        r = p->n;
        p->n = r + 1;
      }
    }
  } else {
    r = 0xffff;
    p->e = 0x404;
  }
  return r;
}
//@ f_134380
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leert die Liste (p) vollständig, gibt ihren Datenpuffer (p->data) frei und setzt alle Zähler
 *   sowie Fehlerflags auf 0 zurück.
 * - Eingaben: Ein Zeiger auf die Listenstruktur (p).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_134380(U *p)
{
  p->e = 0;
  if (p->data) { delete p->data; p->data = 0; }
  p->n = 0; p->s4 = 0; p->c = 0; p->data = 0;
}
//@ f_1343c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert beim Programmstart das Modul zur Gegenstandsbenutzung (use.cpp), indem vier
 *   persistente Statusflags (d_1c0e7c bis d_1c0e88 mit den Kennungen 0xf1, 0xee, 0x20b und 0x37) für den
 *   Speicherstand registriert und die 39 Methodenzeiger (f_134f90 bis f_13bb50) für alle benutzbaren
 *   Gegenstandskategorien in die globale Sprungtabelle d_1c0e8c eingetragen werden.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Die Tabelle d_1c0e8c (table134492) umfasst 40 Einträge zu je 12 Bytes
 *   (C++-Memberfunktionszeiger) für die Aktionshandler der Gegenstandsbenutzung.
 === Ende Beschreibung === */
#pragma aux f_1343c0 modify [eax]
struct Reg134;
struct Obj134 { signed char a; short b; char c; Obj134 *init(Reg134 &r,short id,signed char f);Obj134 * initLast(Reg134 &r,short id,signed char f); };
struct Reg134 { short count; Obj134 **list; void append(Obj134 *o){list[count]=o;count++;} };
inline Obj134 *Obj134::init(Reg134 &r,short id,signed char f){a=f;b=id;r.append(this);return this;}
inline Obj134 * Obj134::initLast(Reg134 &r,short id,signed char f){a=f;b=id;r.list[r.count]=this;++r.count;return this;}
extern Obj134 ob134_7c, ob134_80, ob134_84, ob134_88;
extern Reg134 reg134;
#pragma aux ob134_7c "d_1c0e7c"
#pragma aux ob134_80 "d_1c0e80"
#pragma aux ob134_84 "d_1c0e84"
#pragma aux ob134_88 "d_1c0e88"
#pragma aux reg134 "d_1c212a"
inline signed char zero134() { signed char c=0; return c; }
inline void add134(Obj134 &o, Reg134 &r, short id) { o.a=zero134(); o.b=id; r.list[r.count]=&o; r.count++; }
struct Handler134492 { void f_134f90();void f_135010();void f_135040();void f_1354d0();void f_135590();void f_135600();void f_135870();void f_135920();void f_138c90();void f_138e90();void f_138fe0();void f_139020();void f_139da0();void f_139e00();void f_139f70();void f_139f80();void f_13a030();void f_13aa40();void f_13abb0();void f_13acf0();void f_13ad00();void f_13adb0();void f_13ae40();void f_13aea0();void f_13b180();void f_13b7b0();void f_13b840();void f_13b8f0();void f_13b990();void f_13b9b0();void f_13ba50();void f_13ba70();void f_13ba90();void f_13bab0();void f_13bad0();void f_13baf0();void f_13bb10();void f_13bb30();void f_13bb50(); };
typedef void (Handler134492::*Method134492)();
typedef char Method134Size492[(sizeof(Method134492)==12)?1:-1];
extern Method134492 table134492[40];
#pragma aux table134492 "d_1c0e8c"
void f_1343c0(void)
{
  ob134_7c.init(reg134,0xf1,0);
  ob134_80.init(reg134,0xee,0);
  ob134_84.init(reg134,0x20b,0);
  ob134_88.initLast(reg134,0x37,0);
  table134492[0]=0;
  table134492[1]=&Handler134492::f_134f90;
  table134492[2]=&Handler134492::f_135010;
  table134492[3]=&Handler134492::f_135040;
  table134492[4]=&Handler134492::f_1354d0;
  table134492[5]=&Handler134492::f_135590;
  table134492[6]=&Handler134492::f_135600;
  table134492[7]=&Handler134492::f_135870;
  table134492[8]=&Handler134492::f_135920;
  table134492[9]=&Handler134492::f_138c90;
  table134492[10]=&Handler134492::f_138e90;
  table134492[11]=&Handler134492::f_138fe0;
  table134492[12]=&Handler134492::f_139020;
  table134492[13]=&Handler134492::f_139da0;
  table134492[14]=&Handler134492::f_139e00;
  table134492[15]=&Handler134492::f_139f70;
  table134492[16]=&Handler134492::f_139f80;
  table134492[17]=&Handler134492::f_13a030;
  table134492[18]=&Handler134492::f_13aa40;
  table134492[19]=&Handler134492::f_13abb0;
  table134492[20]=&Handler134492::f_13acf0;
  table134492[21]=&Handler134492::f_13ad00;
  table134492[22]=&Handler134492::f_13adb0;
  table134492[23]=&Handler134492::f_13ae40;
  table134492[24]=&Handler134492::f_13aea0;
  table134492[25]=&Handler134492::f_13b180;
  table134492[26]=&Handler134492::f_13b7b0;
  table134492[27]=&Handler134492::f_13b840;
  table134492[28]=&Handler134492::f_13b8f0;
  table134492[29]=&Handler134492::f_13b990;
  table134492[30]=&Handler134492::f_13b9b0;
  table134492[31]=&Handler134492::f_13ba50;
  table134492[32]=&Handler134492::f_13ba70;
  table134492[33]=&Handler134492::f_13ba90;
  table134492[34]=&Handler134492::f_13bab0;
  table134492[35]=&Handler134492::f_13bad0;
  table134492[36]=&Handler134492::f_13baf0;
  table134492[37]=&Handler134492::f_13bb10;
  table134492[38]=&Handler134492::f_13bb30;
  table134492[39]=&Handler134492::f_13bb50;
}
//@ f_134840
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert eine Benutzungskontext-Struktur (p) für das einfache Benutzen eines einzelnen
 *   Gegenstands (s1a in Inventarslot s18) durch einen Helden (h), wobei die Felder für einen zweiten Gegenstand
 *   (s1c, s1e) auf -1 gesetzt werden.
 * - Eingaben: Ein Zeiger auf die Kontextstruktur (p), der handelnde Held (h), ein Zusatzzeiger (a14), der
 *   Inventarslot (s18), die Gegenstandskennung (s1a) sowie ein Flag für Textmeldungen (e).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Speichert alle übergebenen Werte direkt in den Feldern der Struktur G (p).
 === Ende Beschreibung === */
void f_134840(G *p, int h, int a14, short s18, short s1a, int e)
{
  p->s1c = -1;
  p->s1e = -1;
  p->h = h;
  p->a14 = a14;
  p->s18 = s18;
  p->s1a = s1a;
  p->e = e;
}
//@ f_134870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert eine Benutzungskontext-Struktur (p) für das Kombinieren zweier Gegenstände
 *   (s1a in Slot s18 und s1e in Slot s1c) durch einen Helden (h); falls derselbe Gegenstand im selben Slot mit
 *   sich selbst kombiniert wurde oder kein zweiter Gegenstand angegeben ist (s1e == 0), wird die Kombination auf
 *   eine Einzelbenutzung (s1c = -1, s1e = 0) zurückgesetzt.
 * - Eingaben: Ein Zeiger auf die Kontextstruktur (p), der handelnde Held (h), Slot und Kennung des ersten
 *   Gegenstands (s18, s1a), Slot und Kennung des zweiten Gegenstands (s1c, s1e) sowie das Meldungsflag (e).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft auf Gleichheit von s18 == s1c und s1a == s1e.
 === Ende Beschreibung === */
void f_134870(G *p, int h, short s18, short s1a, short s1c, short s1e, int e)
{
  p->a14 = 0;
  p->h = h;
  p->s18 = s18;
  p->s1c = s1c;
  p->s1e = s1e;
  p->e = e;
  p->s1a = s1a;
  if (((p->s18 == p->s1c) && (*(volatile short *)&p->s1a == *(volatile short *)&p->s1e)) || (p->s1e == 0)) { // erzwingt das erneute Laden von p->s1a und p->s1e aus dem Speicher wie im Original
    p->s1c = -1;
    p->s1e = 0;
  }
}
//@ f_1348d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leerer Destruktor der Benutzungskontext-Struktur (G).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine Variablen.
 === Ende Beschreibung === */
void f_1348d0(void)
{
}
//@ f_1348e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ersetzt nach dem Benutzen eines Gegenstands im Inventar des Helden (p->h) ein Exemplar aus
 *   dem bisherigen Slot (a) durch einen neuen Folgegegenstand (b, z. B. eine leere Flasche nach dem Trinken
 *   eines Elixiers).
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p), der Inventarslot des verbrauchten Gegenstands (a) sowie
 *   die Kennung des neuen Gegenstands (b).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt f_036300 zum Entfernen einer Einheit aus Slot a und f_036a10 zum Einfügen des
 *   Gegenstands b.
 === Ende Beschreibung === */
void f_1348e0(G *p, short a, short b)
{
  f_036300(p->h, a, 1);
  f_036a10(p->h, b, 1, a, 0);
}
//@ f_134910
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Einzelbenutzung eines Gegenstands (p->s1a in Slot p->s18) durch den Helden p->h
 *   aus: Geprüft wird zunächst, ob überhaupt ein Gegenstand gewählt wurde (0x1e0100bf), ob der Held
 *   handlungsfähig ist (f_0d49b0 - bei Bewusstlosigkeit oder Tod darf allenfalls ein Heiltrank oder Kraut von
 *   einem Kameraden verabreicht werden f_03d820), ob der Gegenstand überhaupt benutzbar ist (f_0a7970), ob die
 *   Klassen- und Magievoraussetzungen erfüllt sind (f_045960, Meldung 0x20000106), ob ein Ess-/Trinkgegenstand
 *   verzehrt oder anderweitig untersucht werden soll (f_0bf820) und ob noch Ladungen vorhanden sind (f_042ac0,
 *   Meldung 0x1e010050), bevor schließlich über die Tabelle d_1a47ea und d_1c0e8c der spezifische
 *   Gegenstandshandler aufgerufen wird.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: m ist der lokale Textkontext für Fehlermeldungen; TT(p->s1a) liefert den
 *   Gegenstandsdatensatz aus d_1c2c40, und ruf ermittelt über die Aktionsnummer f_0a78a0 den zugehörigen Handler
 *   in d_1c0e8c.
 === Ende Beschreibung === */
struct MsgC { int h; int *q[14]; MsgC(void*,void*,void*); ~MsgC(); void name(int v) { q[2][1] = v; ((short *)q[7])[1] = 1; } void name2(int v) { q[2][2] = v; ((short *)q[7])[2] = 1; } };
extern signed char d_1a47ea[];
#define SHOW(k) f_0bf730((int)&d_1c2c64, (k))
#define BF820(a,b,c,d,e) ((int (*)(int, ...))f_0bf820)(a,b,c,d,e)
struct GC { char g; };
typedef void (GC::*GM)();
inline void ruf(G *p, int x) {
    int j = (signed char)((char)(((RivaItemDefinition*)(x))->f_0a78a0()));
    int k = d_1a47ea[j * 3];
    GM &mf = *(GM *)&p->f;
    mf = *(GM *)((E *)&d_1c0e8c + k);
    (((GC *)p)->*mf)();
}
#define TAIL(X) { ruf(p, X); }
void f_134910(G *p)
{
  int text;
  MsgC m((void *)d_1c349c, (void *)d_1c3870, (void *)d_1c3498);
  if (!p->s1a) {
    if (p->e) SHOW(0x1e0100bf);
  } else if (f_0d49b0(p->h) != 0) {
    if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7970() == 0) {
      if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7930() != 0) {
        f_03d820(p->h, p->h, p->s18);
      } else {
        if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7ad0() != 0) {
          m.name(TT(p->s1a));
          text = 0x1e01004e;
        } else {
          m.name(TT(p->s1a));
          { int z = p->e; p->e = z; } // KRUECKE: Listenplatz
          { int z = p->e; p->e = z; } // KRUECKE: Listenplatz
          text = 0x1e01004f;
        }
        if (p->e) SHOW(text);
      }
    } else if (!f_045960(p->h, p->s1a)) {
      if (p->e) {
        { int z = p->e; p->e = z; } // KRUECKE: Listenplatz
        m.q[0][1] = p->h;
        m.q[2][1] = TT(p->s1a);
        ((short *)m.q[7])[1] = 1;
        m.q[3][1] = f_040e90(p->h);
        SHOW(0x20000106);
      }
    } else if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7910() != 0 && f_149360(p->s1a, (int)d_1a489a) == -1) {
      short r = f_149360(p->s1a, (int)d_1a4854);
      if (r == -1 || (r = ((short (*)(int, ...))f_0bf820)((int)&d_1c2c64, 0x1e0100b8, 2, 0x1e0100b5, 0x1e0100b7)) == 1) {
        f_03d820(p->h, p->h, p->s18);
      } else if (r != -1) {
        TAIL(TT(p->s1a));
      }
    } else if (f_042ac0((struct hero *)(p->h), p->s18) <= 0) {
      if (p->e) {
        m.q[2][1] = TT(p->s1a);
        ((short *)m.q[7])[1] = 1;
        SHOW(0x1e010050);
      }
    } else {
      TAIL(TT(p->s1a));
    }
  } else if (((char)(f_0424d0((struct hero *)(p->h)))) || ((char)(f_0425f0((struct hero *)(p->h))))) {
    int b = 0;
    if (((char)(f_042350((struct hero *)(p->h))))) {
      if (!((char)(f_042470((struct hero *)(p->h)))) && !((char)(f_0424e0((struct hero *)(p->h)))) && !((char)(f_0425a0((struct hero *)(p->h))))) {
        if (!((RivaItemDefinition*)(TT(p->s1a)))->f_0a7970()) {
          if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7930()) b = 1;
        } else if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7910() && f_149360(p->s1a, (int)d_1a489a) == -1) {
          b = 1;
        }
      }
    }
    if (b) {
      f_03d820(p->h, p->h, p->s18);
    } else if (p->e) {
      m.q[0][1] = p->h;
      SHOW(0x1e0100c0);
    }
  } else {
    if (p->e) {
      m.q[0][1] = p->h;
      SHOW(0x1e0100a1);
    }
  }
}

//@ f_134d50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert das Kombinieren zweier Inventargegenstände (p->s1a und p->s1e) durch den Helden
 *   p->h: Sind beide Slots identisch (p->s18 == p->s1c), wird auf die Einzelbenutzung f_134910 verzweigt.
 *   Andernfalls sucht f_13bb70 nach einer gültigen Kombinationsregel und ruft bei einem Treffer (r != -1) den
 *   entsprechenden Handler aus d_1c0e8c auf; gibt es keine gültige Kombination (r == -1), wird eine passende
 *   Ablehnungsmeldung (0x1e01004e, 0x1e01004f oder 0x1e01009c) ausgegeben.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: r speichert den von f_13bb70 ermittelten Index in der Handler-Tabelle d_1c0e8c; m
 *   verwaltet die Platzhalter für die Gegenstandsnamen in den Fehlermeldungen. *(Hinweis: Im zweiten else
 *   if-Zweig bei unbrauchbarem zweiten Gegenstand p->s1e steckt ein Original-Kopierfehler von Attic, der
 *   fälschlich den Namen des ersten Gegenstands p->s1a in die Fehlermeldung einsetzt - siehe Fehlerliste).*
 === Ende Beschreibung === */
void f_134d50(G *p)
{
  struct { FN cb; } slot;
  int text;
  MsgC m((void *)d_1c349c, (void *)d_1c3870, (void *)d_1c3498);
  if (p->s18 == p->s1c) {
    f_134910(p);
  } else if (f_0d49b0(p->h) != 0) {
    short r = f_13bb70((int)p, p->s1a, p->s1e);
    if (r != -1) {
      E *e = (E *)&d_1c0e8c + r;
      p = (G *)((char *)p + e->off);
      slot.cb = e->f((int)p);
      slot.cb((int)p);
    } else if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7970() == 0) {
      if (((RivaItemDefinition*)(TT(p->s1a)))->f_0a7ad0()) { m.q[2][1] = TT(p->s1a); ((short *)m.q[7])[1] = 1; text = 0x1e01004e; }
      else { m.name(TT(p->s1a)); text = 0x1e01004f; }
      if (p->e) SHOW(text);
    } else if (((RivaItemDefinition*)(TT(p->s1e)))->f_0a7970() == 0) {
      { int z = p->e; p->e = z; } // KRUECKE: Listenplatz
      int *tt = (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = tt; // KRUECKE: Umlauf hebt tt
      if (((RivaItemDefinition*)(tt[p->s1e]))->f_0a7ad0()) { m.q[2][1] = TT(p->s1a); ((short *)m.q[7])[1] = 1; text = 0x1e01004e; }
      else { m.name(TT(p->s1a)); text = 0x1e01004f; }
      if (p->e) SHOW(text);
    } else if (p->e) {
      { int z = p->e; p->e = z; } { int z = p->h; p->h = z; } { int z = p->a14; p->a14 = z; } // KRUECKE: Listenplaetze
      m.name(TT(p->s1a));
      m.name2(TT(p->s1e));
      SHOW(0x1e01009c);
    }
  } else if (((char)(f_0424d0((struct hero *)(p->h)))) || ((char)(f_0425f0((struct hero *)(p->h))))) {
    if (p->e) { int h = p->h; m.q[0][1] = h; SHOW(0x1e0100c0); }
  } else {
    if (p->e) { int h = p->h; m.q[0][1] = h; SHOW(0x1e0100a1); }
  }
  { int z = (int)(*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = (int *)z; } // KRUECKE: Listenplatz
}


//@ f_134f90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert den ersten Gegenstands-Handler (Index 1 in d_1c0e8c), der beim Benutzen eines
 *   speziellen Gegenstands eine Charakter- bzw. Animationsansicht (f_030850 und Sound/Grafik 0x3d über f_10ce80)
 *   für den Helden p->h aufruft und anschließend die Ladungszahl des Gegenstands in Slot p->s18 um 1 verringert
 *   (f_042b20).
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: buf dient als lokaler Puffer für das Hilfsobjekt (f_10cba0 / f_10cbc0); vorübergehend
 *   wird der Heldenstatus 0x63 (f_042740) sowie d_1c0420 = 1 gesetzt.
 === Ende Beschreibung === */
void f_134f90(G *p)
{
  int f_10cba0_keep(int,int,int);
#pragma aux f_10cba0_keep "f_10cba0" modify exact [eax edx]
  char buf[0x20];
  f_042740((struct hero *)(p->h), 0x63);
  f_030850(p->h, p->h);
  d_1c0420 = 1;
  d_1c042a = -1;
  f_10cba0_keep((int)buf, p->h, 0);
  f_10ce80((int)buf, 0x3d, 0);
  f_042b20((struct hero *)(p->h), p->s18, -1);
  f_042740((struct hero *)(p->h), 0);
  f_10cbc0((int)buf, 0);
}
//@ f_135010
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Implementiert den zweiten Gegenstands-Handler (Index 2 in d_1c0e8c), der die Benutzung des
 *   Gegenstands p->s1a an die Spezialroutine f_138330 weiterleitet.
 * - Eingaben: Ein Zeiger auf die Benutzungskontext-Struktur (p).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_135010(G *p)
{
  f_138330((int)p, p->s1a);
}
