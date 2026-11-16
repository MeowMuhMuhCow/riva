/* === Beschreibung (Katalog) ===
 * Einheit fz_15689d_t5 (0x15DB68 - 0x15DC00)
 *
 * Überblick
 * Diese kleine Einheit bildet den Abschluss des Hypertext-Moduls und enthält die Suchfunktion (f_15db68) zum
 * Auffinden eines benannten Sprungziels (<A NAME="...">) innerhalb des aktuell gesetzten Dokuments.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 26.10.2026, Basis fz_15689d_t5_P1.CPP)
// fz_15689d.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x15689D-0x15DC00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014ad0();                                         // reg - stapel 0
int f_014af0();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
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
extern int d_1bbfdc;                    // 0x1BBFDC
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
// --- eigene Funktionen (132), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct V { unsigned data; int x; unsigned end; unsigned cap; };
struct S8 { int a; const char *name; };
extern V *d_1cddbc;
int f_15c170(V *p);
int f_15d4e8(V *p);
int f_14d717(const char *a, const char *b);
//@ f_15db68
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht alle Hyperlink-Startelemente (Typ 5) im globalen Dokumentvektor d_1cddbc über
 *   f_15d4e8 und vergleicht deren Ankernamen (name an Offset +0x14) ohne Berücksichtigung der
 *   Groß-/Kleinschreibung (f_14d717) mit dem gesuchten Namen p1.
 * - Eingaben: Gesuchter Ankername p1 als Zeichenkette.
 * - Rückgabewert: int - Elementindex i des gefundenen Ankers im Layoutvektor oder -1, wenn kein passender Anker
 *   existiert.
 * - Wichtige Variablen:
 *   - d_1cdf9c: Wird zu Beginn auf 0 gesetzt, um die Suche am Dokumentanfang zu starten.
 *   - frame.result: Kopie des Zeigerpaares (href, name) aus dem jeweils untersuchten Link-Element.
 === Ende Beschreibung === */
struct CopyFrame670 {S8 temporary,result;const char *query;CopyFrame670(const char*key):query(key){} };
int f_15db68(const char *p1)
{
  int i;
  CopyFrame670 frame(p1);
  d_1cdf9c = 0;
  i = f_15d4e8(d_1cddbc);
  if(i!=-1){const char*s=frame.query;do {
    V *v = d_1cddbc;
    unsigned u = i * 0x20;
    int k = i;
    { unsigned base = v->data; u += base; }
    unsigned e = v->end;
    if (u >= e) { v->end = u + 0x20; f_15c170(v); }
    unsigned offset=k*0x20;unsigned d2=v->data;frame.temporary=*(S8*)(offset+d2+0x10);frame.result=frame.temporary;
    if (f_14d717(frame.result.name, s) == 0) return i;
    i = f_15d4e8(d_1cddbc);
  }while(i!=-1);}
  return -1;
}
