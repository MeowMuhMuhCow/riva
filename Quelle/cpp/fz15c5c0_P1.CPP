/* === Beschreibung (Katalog) ===
 * Einheit fz15c5c0 (0x15C5C0 - 0x15C5C8)
 *
 * Überblick
 * Diese winzige Einheit enthält den 2D-Punkt-Konstruktor (f_15c5c0) zum Beschreiben eines Zwei-Integer-Paares.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAVECT.H"
// OPT -5r -ox -zp1 -s
// P3 44/75 gleich (suche.py 26.10.2026, Basis fz_15689d_t3_P1.CPP)
// P2 Koepfe Stufe Misch (0 Ueberladungen) (Fable K): 23 gleich (vorher 23), Rest 702 (vorher 708)
// fz_15689d.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x15689D-0x15DC00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014ad0();                                         // reg - stapel 0
int f_014af0(int p1);
int __cdecl f_099ef0(void *p1, int p2, int p3);
int f_09dae0();                                         // reg - stapel 0
int f_09db10(int p1, int p2);                           // reg eax edx stapel 0
int f_09db60(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09db70(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09db80(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_09dbe0(int p1, int p2, int p3, int p4);           // reg eax edx ecx stapel 0
int f_09dbf0();                                         // reg - stapel 0
int f_09dc00(int p1);                                   // reg eax stapel 0
int f_09dc50(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_09e100(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_09e140(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_09e1b0();                                         // reg - stapel 0
int f_09e220(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_09e3f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_14d5c9(int p1);                                   // reg eax stapel 0
int f_1664d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a9b94;                    // 0x1A9B94
extern int d_1a9b96;                    // 0x1A9B96
extern int d_1a9b98;                    // 0x1A9B98
extern int d_1a9b9a;                    // 0x1A9B9A
extern int d_1a9b9c;                    // 0x1A9B9C
extern int d_1a9ba0;                    // 0x1A9BA0
extern int d_1a9ba4;                    // 0x1A9BA4
extern int d_1a9bb8;                    // 0x1A9BB8
extern int d_1a9bbc;                    // 0x1A9BBC
extern int d_1a9bc0;                    // 0x1A9BC0
extern int d_1a9bc4;                    // 0x1A9BC4
extern int d_1a9bc5;                    // 0x1A9BC5
extern int d_1a9bc6;                    // 0x1A9BC6
extern int d_1a9bc7;                    // 0x1A9BC7
extern int d_1a9bcc;                    // 0x1A9BCC
extern int d_1a9bd0;                    // 0x1A9BD0
extern int d_1a9bd4;                    // 0x1A9BD4
extern int d_1a9bd8;                    // 0x1A9BD8
extern int d_1aeba8;                    // 0x1AEBA8
extern int d_1b94dc;                    // 0x1B94DC
extern int d_1b952c;                    // 0x1B952C
extern int d_1b9531;                    // 0x1B9531
extern int d_1baac0;                    // 0x1BAAC0
extern unsigned char d_1bbfdc[];
extern int d_1bc0e0;                    // 0x1BC0E0
extern int d_1bc0e2;                    // 0x1BC0E2
extern int d_1bc0e4;                    // 0x1BC0E4
extern int d_1bc0e6;                    // 0x1BC0E6
extern int d_1bc0e8;                    // 0x1BC0E8
extern int d_1bc0ea;                    // 0x1BC0EA
extern int d_1bc0ec;                    // 0x1BC0EC
extern int d_1bc0ee;                    // 0x1BC0EE
extern int d_1bc0f0;                    // 0x1BC0F0
extern int d_1bde24;                    // 0x1BDE24
extern int d_1bde28;                    // 0x1BDE28
extern int d_1bde2c;                    // 0x1BDE2C
extern int d_1bde30;                    // 0x1BDE30
                    // 0x1C2098
extern int d_1cddb0;                    // 0x1CDDB0
extern int d_1cddb4;                    // 0x1CDDB4
extern int d_1cddb8;                    // 0x1CDDB8
extern int d_1cddbc;                    // 0x1CDDBC
extern int d_1cddc0;                    // 0x1CDDC0
extern int d_1cddc4;                    // 0x1CDDC4
extern int d_1cddc8;                    // 0x1CDDC8
extern int d_1cddcc;                    // 0x1CDDCC
extern int d_1cddce;                    // 0x1CDDCE
extern int d_1cddd0;                    // 0x1CDDD0
extern int d_1cddd2;                    // 0x1CDDD2
extern int d_1cddd4;                    // 0x1CDDD4
extern int d_1cddd6;                    // 0x1CDDD6
extern int d_1cddd8;                    // 0x1CDDD8
extern int d_1cddda;                    // 0x1CDDDA
extern int d_1cdddc;                    // 0x1CDDDC
extern int d_1cddde;                    // 0x1CDDDE
extern int d_1cdde4;                    // 0x1CDDE4
extern int d_1cdde6;                    // 0x1CDDE6
extern int d_1cdde8;                    // 0x1CDDE8
extern int d_1cddec;                    // 0x1CDDEC
extern int d_1cddf0;                    // 0x1CDDF0
extern int d_1cddf4;                    // 0x1CDDF4
extern int d_1cddf8;                    // 0x1CDDF8
extern int d_1cddfc;                    // 0x1CDDFC
extern int d_1cdf8c;                    // 0x1CDF8C
extern int d_1cdf90;                    // 0x1CDF90
extern int d_1cdf94;                    // 0x1CDF94
extern int d_1cdf96;                    // 0x1CDF96
extern int d_1cdf98;                    // 0x1CDF98
extern int d_1cdf9c;                    // 0x1CDF9C
extern const char d_1a9c04[];           // Text 0x1A9C04
extern const char d_1b94de[];           // Text 0x1B94DE
extern const char d_1b94e7[];           // Text 0x1B94E7
extern const char d_1b94f3[];           // Text 0x1B94F3
extern const char d_1b94f9[];           // Text 0x1B94F9
extern const char d_1b94ff[];           // Text 0x1B94FF
extern const char d_1b9508[];           // Text 0x1B9508
extern const char d_1b950f[];           // Text 0x1B950F
extern const char d_1b9516[];           // Text 0x1B9516
extern const char d_1b951c[];           // Text 0x1B951C
extern const char d_1b9522[];           // Text 0x1B9522
extern const char d_1b9536[];           // Text 0x1B9536
extern const char d_1b953d[];           // Text 0x1B953D
extern const char d_1b9545[];           // Text 0x1B9545
extern const char d_1b954c[];           // Text 0x1B954C
extern const char d_1b9556[];           // Text 0x1B9556
extern const char d_1b955d[];           // Text 0x1B955D
extern const char d_1b957e[];           // Text 0x1B957E
extern const char d_1b958a[];           // Text 0x1B958A
#pragma inline_depth(0)
struct RivaFileStream;


#define FI(p,o) (*(int *)((char *)(p) + (o)))
#define FS(p,o) (*(short *)((char *)(p) + (o)))
#define DV(p) ((RivaFileStream *)FI(p, 0x3f7))
int f_145234(int p1, int p2);
int f_145254(int p1);
int f_15ea53(int p1, int p2, int p3);
int f_147c84(int p1, int p2, int p3);
void f_15b9b0(RivaIntVector *p, int n);
void f_15b990(RivaIntVector *p, int n);
void f_15ba50(RivaIntVector *p, int *d, int *s, int n);
void f_15bad0(RivaVectorVector *p);
void f_15bcf0(RivaVectorVector *p, int n);
RivaVectorVector *f_15bc00(RivaVectorVector *p, int fl);
void f_15bcd0(RivaVectorVector *p, int n);
void f_15bdd0(RivaVectorVector *p, RivaIntVector *d, RivaIntVector *s, int n);
RivaIntVector *f_15bec0(RivaIntVector *p, RivaIntVector *q);
void f_15be60(RivaIntVector *p);
void f_15c080(RivaIntVector *p, int n);
RivaIntVector *f_15bfa0(RivaIntVector *p, int fl);
void f_15c060(RivaIntVector *p, int n);
void f_15c120(RivaIntVector *p, int *d, int *s, int n);
void f_15c1a0(RivaRecordVector *p);
void f_15c410(RivaRecordVector *p, int n);
void f_15c3f0(RivaRecordVector *p, int n);
void f_15c4b0(RivaRecordVector *p, RivaRecord32 *d, RivaRecord32 *s, int n);
int f_15c9b0(int p);
int f_15cb30(int p, int p2);
//@ f_15b770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verkleinert die Kapazität eines RivaIntVector p auf max(16, p->th * 2) Elemente, sobald
 *   der Füllstand unter die untere Schwelle gefallen ist.
 * - Eingaben: Zeiger p auf den RivaIntVector.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Neue Zielkapazität (mindestens 16).
 === Ende Beschreibung === */
void f_15b770(RivaIntVector *p)
;
//@ f_15b790
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Vergrößert die Kapazität eines RivaIntVector p über f_15b9b0 auf das 1,5-Fache ((3 * d) /
 *   2) der aktuellen Elementanzahl d.
 * - Eingaben: Zeiger p auf den RivaIntVector.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d: Aktuelle Elementanzahl p->c - p->b.
 === Ende Beschreibung === */
void f_15b790(RivaIntVector *p) ;
//@ f_15b7d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die aktuelle Anzahl der im RivaIntVector p gespeicherten 4-Byte-Elemente (p->c -
 *   p->b) zurück.
 * - Eingaben: Zeiger p auf den RivaIntVector.
 * - Rückgabewert: int - Anzahl der Elemente.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15b7d0(RivaIntVector *p)
;
RivaIntVector *f_15b8d0(RivaIntVector *p, int fl);
RivaIntVector *f_15b7f0(RivaIntVector *p, RivaIntVector *q)
;
int f_15b860(RivaIntVector *p, int i) ;
//@ f_15b8a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert den RivaIntVector p, gibt dessen Speicherblock frei und initialisiert ihn neu mit
 *   einer Startkapazität von 16 Elementen.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15b8a0(RivaIntVector *p)
;
//@ f_15b8d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor für RivaIntVector: Gibt den internen Datenpuffer p->a über f_145254 frei und
 *   setzt den Zeiger auf 0.
 * - Eingaben: Vektorzeiger p und Destruktor-Flag fl.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15b8d0(RivaIntVector *p, int fl)
;
RivaIntVector *f_15b8f0(RivaIntVector *p)
;
//@ f_15b910
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopierkonstruktor für RivaIntVector: Legt p mit derselben Kapazität und denselben
 *   Elementen wie q an.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15b910(RivaIntVector *p, RivaIntVector *q)
;
//@ f_15b980
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor für RivaIntVector mit frei wählbarer Startkapazität n.
 * - Eingaben: Vektorzeiger p und gewünschte Kapazität n.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15b980(RivaIntVector *p, int n)
;
//@ f_15b990
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Zeiger a, b, c des RivaIntVector p auf 0 und reserviert über f_15b9b0 Speicher
 *   für n Elemente.
 * - Eingaben: Vektorzeiger p und Elementanzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15b990(RivaIntVector *p, int n)
;
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_15b9b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reserviert einen neuen Puffer für n 4-Byte-Elemente im RivaIntVector p, kopiert vorhandene
 *   Elemente aus dem alten Puffer hinüber, gibt den alten Puffer frei und berechnet die neue Schrumpfschwelle
 *   (th = n / 3, th4 = th * 4).
 * - Eingaben: Vektorzeiger p und neue Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - cnt: Bisherige Elementanzahl p->c - p->b.
 *   - np: Neu allozierter Speicherblock der Größe n * 4.
 === Ende Beschreibung === */
void f_15b9b0(RivaIntVector *p, int n)
;
//@ f_15ba50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert n 32-Bit-Integer-Werte von s nach d.
 * - Eingaben: Vektor p (ungenutzt), Zielzeiger d, Quellzeiger s und Anzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15ba50(RivaIntVector *p, int *d, int *s, int n)
;
//@ f_15ba70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt sicher, dass ein 28-Byte-Elementvektor (RivaVectorVector, z. B. für Tabellenzeilen)
 *   p mindestens bis zum Index i reicht, und vergrößert den Puffer bei Bedarf über f_15bad0.
 * - Eingaben: Vektorzeiger p und Index i.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15ba70(RivaVectorVector *p, int i)
;
//@ f_15baa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob der 28-Byte-Elementvektor p voll ist (p->c >= p->d), und vergrößert ihn
 *   gegebenenfalls über f_15bad0.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15baa0(RivaVectorVector *p)
;
//@ f_15bab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verkleinert die Kapazität eines RivaVectorVector p auf max(16, p->th * 2) Elemente.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bab0(RivaVectorVector *p)
;
//@ f_15bad0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Vergrößert die Kapazität eines RivaVectorVector p über f_15bcf0 auf das 1,5-Fache der
 *   aktuellen Elementanzahl.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bad0(RivaVectorVector *p)
;
//@ f_15bb10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopier-Zuweisungsoperator für RivaVectorVector: Gibt den bisherigen Inhalt von p frei und
 *   kopiert alle Untervektoren aus q über f_15bdd0.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15bb10(RivaVectorVector *p, RivaVectorVector *q)
;
//@ f_15bb80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gewährt Indexzugriff (operator[]) auf das i-te 28-Byte-Element im RivaVectorVector p und
 *   erweitert bei Bedarf Füllstand und Kapazität.
 * - Eingaben: Vektorzeiger p und Index i.
 * - Rückgabewert: int - Adresse des i-ten Untervektors p->a + i.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15bb80(RivaVectorVector *p, int i)
;
//@ f_15bbd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert einen RivaVectorVector p, ruft für alle enthaltenen Untervektoren den Destruktor
 *   (f_145234 mit d_1bc0f0) auf, gibt das Array frei und initialisiert es neu mit Kapazität 16.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bbd0(RivaVectorVector *p)
;
//@ f_15bc00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor für RivaVectorVector: Baut alle im Array p->a enthaltenen Untervektoren über
 *   f_145234 ab und gibt den Speicherblock über f_145254 frei.
 * - Eingaben: Vektorzeiger p und Destruktor-Flag fl.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15bc00(RivaVectorVector *p, int fl)
;
//@ f_15bc30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Standardkonstruktor für RivaVectorVector mit Startkapazität 16.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15bc30(RivaVectorVector *p)
;
//@ f_15bc50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopierkonstruktor für RivaVectorVector: Erstellt p als tiefe Kopie von q.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15bc50(RivaVectorVector *p, RivaVectorVector *q)
;
//@ f_15bcc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor für RivaVectorVector mit Startkapazität n.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15bcc0(RivaVectorVector *p, int n)
;
//@ f_15bcd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Zeiger eines RivaVectorVector p auf 0 und reserviert über f_15bcf0 Platz für n
 *   Untervektoren.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bcd0(RivaVectorVector *p, int n)
;
//@ f_15bcf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Kapazität eines RivaVectorVector p auf n 28-Byte-Untervektoren, konstruiert das
 *   neue Array über die Watcom-Laufzeitfunktion f_15ea53 (__vec_new), kopiert bestehende Untervektoren über
 *   f_15bdd0 und zerstört das alte Array über f_145234.
 * - Eingaben: Vektorzeiger p und neue Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - cnt: Bisherige Anzahl belegter Untervektoren.
 *   - np: Neu angelegtes Array von n Untervektoren.
 === Ende Beschreibung === */
void f_15bcf0(RivaVectorVector *p, int n)
;
//@ f_15bdd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert n Untervektoren (RivaIntVector zu je 28 Bytes) elementweise über f_15bec0 von s
 *   nach d.
 * - Eingaben: Container p, Zielarray d, Quellarray s und Elementanzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bdd0(RivaVectorVector *p, RivaIntVector *d, RivaIntVector *s, int n)
;
void f_15be00(RivaIntVector *p, int i)
;
//@ f_15be30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft den 4-Byte-Zeigervektor p auf Erreichen der Kapazitätsgrenze (p->c >= p->d) und
 *   vergrößert ihn bei Bedarf über f_15be60.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15be30(RivaIntVector *p)
;
//@ f_15be40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verkleinert die Kapazität des 4-Byte-Zeigervektors p auf max(16, p->th * 2) Elemente.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15be40(RivaIntVector *p)
;
//@ f_15be60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Vergrößert die Kapazität des 4-Byte-Zeigervektors p über f_15c080 auf das 1,5-Fache der
 *   aktuellen Elementanzahl.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15be60(RivaIntVector *p)
;
//@ f_15bea0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert die Anzahl der im 4-Byte-Zeigervektor p gespeicherten Elemente (p->c - p->b).
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: int - Elementanzahl.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15bea0(RivaIntVector *p)
;
//@ f_15bec0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopier-Zuweisungsoperator für den 4-Byte-Zeigervektor: Gibt den alten Puffer von p frei
 *   und kopiert alle Elemente aus q über f_15c120.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15bec0(RivaIntVector *p, RivaIntVector *q)
;
int *f_15bf30(RivaIntVector *p, int i)
;
//@ f_15bf70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert den 4-Byte-Zeigervektor p und initialisiert ihn neu mit einer Kapazität von 16
 *   Elementen.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15bf70(RivaIntVector *p)
;
//@ f_15bfa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor für den 4-Byte-Zeigervektor p: Gibt den Puffer p->a über f_145254 frei.
 * - Eingaben: Vektorzeiger p und Destruktor-Flag fl.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15bfa0(RivaIntVector *p, int fl)
;
RivaIntVector *f_15bfc0(RivaIntVector *p) ;
//@ f_15bfe0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopierkonstruktor für den 4-Byte-Zeigervektor p aus der Vorlage q.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15bfe0(RivaIntVector *p, RivaIntVector *q)
;
//@ f_15c050
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor für den 4-Byte-Zeigervektor p mit Startkapazität n.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15c050(RivaIntVector *p, int n)
;
//@ f_15c060
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Zeiger des 4-Byte-Zeigervektors p auf 0 und reserviert über f_15c080 Speicher
 *   für n Elemente.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c060(RivaIntVector *p, int n)
;
//@ f_15c080
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Pufferkapazität des 4-Byte-Zeigervektors p auf n Elemente, kopiert die
 *   bisherigen Einträge über f_15c120 in den neuen Speicherblock und gibt den alten Block frei.
 * - Eingaben: Vektorzeiger p und neue Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c080(RivaIntVector *p, int n)
;
//@ f_15c120
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert n 4-Byte-Einträge von s nach d.
 * - Eingaben: Vektor p (ungenutzt), Ziel d, Quelle s und Anzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c120(RivaIntVector *p, int *d, int *s, int n)
;
//@ f_15c140
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt sicher, dass ein 32-Byte-Datensatzvektor (RivaRecordVector für
 *   RivaLayoutItem-Elemente) p mindestens bis zum Index i reicht, und vergrößert ihn bei Bedarf über f_15c1a0.
 * - Eingaben: Vektorzeiger p und Elementindex i.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c140(RivaRecordVector *p, int i)
;
//@ f_15c170
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob der 32-Byte-Datensatzvektor p seine Kapazitätsgrenze (p->c >= p->d) erreicht
 *   hat, und vergrößert ihn gegebenenfalls über f_15c1a0.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c170(RivaRecordVector *p)
;
//@ f_15c180
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verkleinert die Kapazität eines RivaRecordVector p auf max(16, p->th * 2) Elemente.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c180(RivaRecordVector *p)
;
//@ f_15c1a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Vergrößert die Kapazität eines RivaRecordVector p über f_15c410 auf das 1,5-Fache der
 *   aktuellen Elementanzahl.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c1a0(RivaRecordVector *p)
;
//@ f_15c1e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob der 32-Byte-Datensatzvektor p leer ist (p->c == p->b).
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: int - 1 wenn leer, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c1e0(RivaRecordVector *p)
;
//@ f_15c200
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Anzahl der im RivaRecordVector p enthaltenen 32-Byte-Datensätze zurück.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: int - Elementanzahl.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c200(RivaRecordVector *p)
;
RivaRecordVector *f_15c330(RivaRecordVector *p, int fl);
RivaRecordVector *f_15c220(RivaRecordVector *p, RivaRecordVector *q)
;
RivaRecord32 f_15c290(RivaRecordVector *p, int i)
;
RivaRecord32 *f_15c2c0(RivaRecordVector *p, int i)
;
//@ f_15c300
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert den RivaRecordVector p, gibt dessen Speicherblock frei und initialisiert ihn neu mit
 *   einer Startkapazität von 16 Elementen.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c300(RivaRecordVector *p)
;
//@ f_15c330
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor für RivaRecordVector: Gibt den internen Puffer p->a über f_145254 frei.
 * - Eingaben: Vektorzeiger p und Destruktor-Flag fl.
 * - Rückgabewert: RivaRecordVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaRecordVector *f_15c330(RivaRecordVector *p, int fl)
;
RivaRecordVector *f_15c350(RivaRecordVector *p)
;
//@ f_15c370
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopierkonstruktor für RivaRecordVector aus der Vorlage q.
 * - Eingaben: Zielvektor p und Quellvektor q.
 * - Rückgabewert: RivaRecordVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaRecordVector *f_15c370(RivaRecordVector *p, RivaRecordVector *q)
;
//@ f_15c3e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor für RivaRecordVector mit Startkapazität n.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: RivaRecordVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaRecordVector *f_15c3e0(RivaRecordVector *p, int n)
;
//@ f_15c3f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Zeiger des RivaRecordVector p auf 0 und reserviert über f_15c410 Speicher für n
 *   32-Byte-Elemente.
 * - Eingaben: Vektorzeiger p und Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c3f0(RivaRecordVector *p, int n)
;
//@ f_15c410
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Pufferkapazität eines RivaRecordVector p auf n 32-Byte-Datensätze, kopiert die
 *   vorhandenen Einträge über f_15c4b0 in den neuen Puffer und gibt den alten frei.
 * - Eingaben: Vektorzeiger p und neue Kapazität n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - np: Neu reservierter Speicherblock der Größe n * 32 Bytes.
 === Ende Beschreibung === */
void f_15c410(RivaRecordVector *p, int n)
;
//@ f_15c4b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert n 32-Byte-Datensätze (RivaRecord32) elementweise von s nach d.
 * - Eingaben: Vektor p (ungenutzt), Zielzeiger d, Quellzeiger s und Anzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c4b0(RivaRecordVector *p, RivaRecord32 *d, RivaRecord32 *s, int n)
;
//@ f_15c4e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert einen RivaIntVector p über f_15b990(p, 16) mit der Standardkapazität 16.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15c4e0(RivaIntVector *p)
;
//@ f_15c500
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zweiter Konstruktor-Wrapper, der einen RivaIntVector p über f_15b990(p, 16) mit der
 *   Standardkapazität 16 initialisiert.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15c500(RivaIntVector *p)
;
//@ f_15c520
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert einen RivaVectorVector p über f_15bcd0(p, 16) mit der Standardkapazität 16.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: RivaVectorVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaVectorVector *f_15c520(RivaVectorVector *p)
;
//@ f_15c540
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert einen 4-Byte-Zeigervektor (RivaIntVector) p über f_15c060(p, 16) mit der
 *   Standardkapazität 16.
 * - Eingaben: Vektorzeiger p.
 * - Rückgabewert: RivaIntVector * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
RivaIntVector *f_15c540(RivaIntVector *p)
;
//@ f_15c560
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert die Konstante 0xFFFFFF (Standard-Obergrenze für unbegrenzte Höhen-/Breitenabfragen
 *   in f_158128 und f_1581c8).
 * - Eingaben: Keine.
 * - Rückgabewert: int - gibt immer 0xFFFFFF (16777215) zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c560(void)
;
int f_15c570(void)
;
//@ f_15c5c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert zwei 32-Bit-Koordinaten oder Werte (a und b) in die ersten beiden Felder der
 *   Zielstruktur p.
 * - Eingaben: Zielzeiger p sowie die beiden Werte a und b.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c5c0(int *p, int a, int b)
{
    p[0] = a;
    p[1] = b;
}
