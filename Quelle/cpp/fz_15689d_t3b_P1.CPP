/* === Beschreibung (Katalog) ===
 * Einheit fz_15689d_t3b (0x15C640 - 0x15C9B0)
 *
 * Überblick
 * Diese Einheit implementiert die Basisklasse und die Kopfdaten-/Laderoutinen für Bilder im PCX-Format (0x80
 * Bytes PCX-Header + 0x300 Bytes 256-Farben-Palette + Bildpufferzeiger). Sie öffnet Bilddateien über ein
 * virtuelles Stream-Gerät (RivaStreamDevice an Offset +0x3F7), prüft die PCX-Kennung (10), fragt Bildabmessungen
 * ab und steuert das vollständige Einlesen von Header, Palette und RLE-Pixeldaten.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAVECT.H"
// OPT -4r -oneatx -zp1 -s
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
//@ f_15c640
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor einer PCX-Bildinstanz p mit explizit übergebenem Stream-Gerät p2:
 *   Initialisiert das 16-Einträge-Basispalettenarray (+0x10) und das 256-Einträge-Hauptpalettenarray (+0x80)
 *   über f_147c84, setzt den Pixelpufferzeiger (+0x381, relativ +0x373 ab +0x0E) auf 0 und speichert das
 *   Stream-Gerät p2 an Offset +0x3F7.
 * - Eingaben: Zeiger p auf das PCX-Objekt und Zeiger p2 auf das RivaStreamDevice.
 * - Rückgabewert: int - gibt den initialisierten Objektzeiger p zurück.
 * - Wichtige Variablen:
 *   - FI(r, 0x377) (entspricht Offset +0x3F7 vom Objektanfang): Zeiger auf das verwendete
 *     Ein-/Ausgabe-Stream-Gerät.
 === Ende Beschreibung === */
int f_15c640(int p, int p2)
{
    struct Prefix { char bytes[0x80]; };
    struct Part { char byte; };
    struct Whole : Prefix, Part {};
    int r = f_147c84(p + 0x10, 0x10, (int)&d_1baac0);
    r = f_147c84(r + 0x70, 0x100, (int)&d_1baac0);
    FI(r, 0x373) = 0;
    FI(r, 0x377) = p2;
    return (int)(Whole *)(Part *)r;
}
//@ f_15c680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Standardkonstruktor einer PCX-Bildinstanz p: Initialisiert die eingebetteten
 *   Palettenarrays und trägt das globale Standard-Dateisystemgerät &d_1c2098 als Stream-Gerät an Offset +0x3F7
 *   ein.
 * - Eingaben: Zeiger p auf das PCX-Objekt.
 * - Rückgabewert: int - gibt den initialisierten Objektzeiger p zurück.
 * - Wichtige Variablen:
 *   - d_1c2098: Globales Standard-Stream-Gerät für Dateioperationen.
 === Ende Beschreibung === */
int f_15c680(int p)
{
    struct Prefix { char bytes[0x80]; };
    struct Part { char byte; };
    struct Whole : Prefix, Part {};
    int r = f_147c84(p + 0x10, 0x10, (int)&d_1baac0);
    r = f_147c84(r + 0x70, 0x100, (int)&d_1baac0);
    FI(r, 0x377) = (int)&d_1c2098;
    FI(r, 0x373) = 0;
    return (int)(Whole *)(Part *)r;
}
//@ f_15c6d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor einer PCX-Bildinstanz p: Gibt den an Offset +0x381 gespeicherten Pixelpuffer
 *   frei, sofern er vorhanden ist und vom Objekt selbst angelegt wurde (FI(p, 0x3F3) == 1).
 * - Eingaben: Zeiger p auf das PCX-Objekt und Destruktor-Flag kp2.
 * - Rückgabewert: int - gibt p zurück.
 * - Wichtige Variablen:
 *   - FI(p, 0x381): Zeiger auf die entpackten Pixeldaten.
 *   - FI(p, 0x3F3): Eigentümer-Flag (1 = Puffer wurde intern per new reserviert).
 === Ende Beschreibung === */
int f_15c6d0(int p, int kp2)
{
  if (FI(p, 0x381) && FI(p, 0x3f3) == 1) delete (char *)FI(p, 0x381);
  return p;
}
//@ f_15c700
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt eine komplette PCX-Datei mit dem Namen/Handle p2 in einen neu reservierten Puffer
 *   (zero = 0), indem der 0x80-Byte-PCX-Header über das Stream-Gerät eingelesen, die 256-Farben-Palette über
 *   f_15c9b0 geladen und die RLE-komprimierten Bilddaten über f_15cb30 entpackt werden.
 * - Eingaben: PCX-Objekt p und Dateiname/Kennung p2.
 * - Rückgabewert: int - 1 bei erfolgreichem Laden von Header, Palette und Bilddaten, sonst 0.
 * - Wichtige Variablen:
 *   - FI(p, 0x385): Gespeicherter Dateiname oder Ressourcen-Identifier der PCX-Datei.
 === Ende Beschreibung === */
int f_15c700(int p, int p2)
{
  int q = p;
  int zero = 0;
  int done[1];
  int ok = 0;
  done[0] = 0;
  FI(p, 0x385) = p2;
  if (DV(p)->vt->r14(DV(p), FI(p, 0x385), 0x200) > 0) {
    DV(p)->vt->r20(DV(p), (void *)p, 0x80);
    DV(p)->vt->close(DV(p));
    done[0] = 1;
  }
  if (done[0] && f_15c9b0(q) && f_15cb30(q, zero)) ok = 1;
  return ok;
}
//@ f_15c790
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt eine komplette PCX-Datei mit dem Namen/Handle p2 direkt in den vom Aufrufer
 *   bereitgestellten Zielbildpuffer p3 (oder legt bei p3 == 0 einen eigenen an).
 * - Eingaben: PCX-Objekt p, Dateiname/Kennung p2 und Zielpufferzeiger p3.
 * - Rückgabewert: int - 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen:
 *   - done, ok: Statusflags für das erfolgreiche Lesen des Headers und des Gesamtbildes.
 === Ende Beschreibung === */
int f_15c790(int p, int p2, int p3)
{
  int ok = 0, done;
  FI(p, 0x385) = p2;
  done = 0;
  if (DV(p)->vt->r14(DV(p), FI(p, 0x385), 0x200) > 0) {
    DV(p)->vt->r20(DV(p), (void *)p, 0x80);
    done = 1;
    DV(p)->vt->close(DV(p));
  }
  if (done && f_15c9b0(p) && f_15cb30(p, p3)) ok = 1;
  return ok;
}
//@ f_15c820
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Aktiviert die im PCX-Objekt p ab Offset +0x80 gespeicherte 256-Farben-Palette als
 *   Hardware-/Bildschirm-Palette über f_099ef0, sofern das Paletten-Kennbyte an Offset +0x380 den gültigen
 *   PCX-Wert 12 (0x0C) besitzt.
 * - Eingaben: Zeiger p auf das PCX-Objekt.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - *(signed char *)(p + 0x380): PCX-Palettenmarkierungsbyte (12 = 256-Farben-VGA-Palette vorhanden).
 === Ende Beschreibung === */
void f_15c820(int p)
{
    if (*(signed char *)(p + 0x380) == 12) f_099ef0((void *)(p + 0x80), 0, 0x100);
}
//@ f_15c850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Zeiger auf die 256-Farben-Palette (p + 0x80) des PCX-Objekts p zurück.
 * - Eingaben: Zeiger p auf das PCX-Objekt.
 * - Rückgabewert: int - Adresse der eingebetteten Palette (p + 0x80).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c850(int p)
{
    return p + 0x80;
}
//@ f_15c860
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Zeiger auf den entpackten Pixeldatenpuffer (FI(p, 0x381)) des PCX-Objekts p
 *   zurück.
 * - Eingaben: Zeiger p auf das PCX-Objekt.
 * - Rückgabewert: int - Zeiger auf die Bildpixel.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c860(int p)
{
    return FI(p, 0x381);
}
//@ f_15c870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet aus den bereits geladenen PCX-Headerfeldern (xMin an +4, yMin an +6, xMax an +8,
 *   yMax an +10) die Bildbreite und Bildhöhe und schreibt sie nach *a und *b.
 * - Eingaben: PCX-Objekt p, Rückgabezeiger a (Breite) und Rückgabezeiger b (Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15c870(int p, short *a, short *b)
{
    *a = (FS(p, 8) - FS(p, 4)) + 1;
    *b = (FS(p, 10) - FS(p, 6)) + 1;
}
//@ f_15c890
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest nur den 0x80-Byte-Header einer PCX-Datei p2 ein, berechnet daraus die Bildbreite
 *   (*p3) und Bildhöhe (*p4) und stellt anschließend den zuvor an +0x385 gespeicherten Dateinamen u wieder her.
 * - Eingaben: PCX-Objekt p, abzufragender Dateiname p2 sowie Ausgabezeiger p3 (Breite) und p4 (Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - u: Zwischengespeicherter alter Dateikennwert aus FI(p, 0x385).
 === Ende Beschreibung === */
void f_15c890(int p, int p2, short *p3, short *p4)
{
  int u = FI(p, 0x385);
  int r;
  short w;
  FI(p, 0x385) = p2;
  r = DV(p)->vt->r14(DV(p), p2, 0x200);
  if (0 < r) {
    DV(p)->vt->r20(DV(p), (void *)p, 0x80);
    DV(p)->vt->close(DV(p));
  }
  w = FS(p, 8) - FS(p, 4);
  *p3 = ++w;
  w = FS(p, 10) - FS(p, 6);
  *(short *)p4 = ++w;
  FI(p, 0x385) = u;
}
//@ f_15c910
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob es sich bei der Datei p2 um eine gültige PCX-Datei handelt, indem die ersten
 *   0x80 Bytes eingelesen werden und das Hersteller-Kennbyte (*p) auf den ZSoft-PCX-Wert 10 (0x0A) getestet
 *   wird.
 * - Eingaben: PCX-Objekt p und Dateiname/Kennung p2.
 * - Rückgabewert: int - 1 wenn die Datei existiert und mit Byte 10 beginnt, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c910(char *p, int p2)
{
    unsigned char t424_8;
  int r, ok = 0;
  r = DV(p)->vt->r14(DV(p), p2, 0x200);
  if (0 < r) {
    DV(p)->vt->r20(DV(p), (void *)p, 0x80);
    DV(p)->vt->close(DV(p));
    if ((signed char)*p == 10) ok = 1;
  }
  return ok;
}
//@ f_15c960
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 0x80-Byte-PCX-Header der aktuell an Offset +0x385 eingetragenen Datei über das
 *   Stream-Gerät in den Beginn der Struktur p1 ein.
 * - Eingaben: Zeiger p1 auf das PCX-Objekt.
 * - Rückgabewert: int - 1 bei erfolgreichem Lesen, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15c960(int p1)
{
    int r = 0;
    if (DV(p1)->vt->r14(DV(p1), FI(p1, 0x385), 0x200) > 0) {
        DV(p1)->vt->r20(DV(p1), (void *)p1, 0x80);
        DV(p1)->vt->close(DV(p1));
        r = 1;
    }
    return r;
}
