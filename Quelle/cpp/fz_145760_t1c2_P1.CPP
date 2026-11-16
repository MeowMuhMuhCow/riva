/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t1c2 (0x145970 - 0x1461F4)
 *
 * Überblick
 * Diese Einheit implementiert das Grafik-Lademodul für Attic-Bilddateien im .AIF-Format (aifload.cpp, Klasse
 * RivaAifImage). AIF-Dateien enthalten 256-Farben-Grafiken, Icons, Hintergründe und optionale
 * 6-Bit-VGA-Farbpaletten und unterstützen vier verschiedene Speicher- bzw. Kompressionsverfahren:
 * - Typ 0: Unkomprimierte Rohpixel (f_145e40).
 * - Typ 1: Einfache Lauflängenkodierung mit Bit 7 als Wiederholungsflag (f_145ee0).
 * - Typ 2: PackBits-ähnliche Lauflängenkodierung mit Literal- und Wiederholungsläufen (f_146030).
 * - Typ 3: LZW-/PowerPack-Kompression über das powerpak-Modul (f_146170).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "RIVAAIF.H"
// P3 17/26 gleich (suche.py 28.10.2026, Basis fz_145760_t1c_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// Astra650: Teilungsvorschlag, vor Einbau mit Astra491/Claude abgleichen.
// P3 8/41 gleich (suche.py 26.10.2026, Basis fz_145760_t1_P1.CPP)
// HINWEIS: nur f_1461f4..f_146900 sind im Original unoptimiert (-od, ebp-Rahmen); f_145760..f_146170 (dice/aifload) sind optimiert (-4r -oneatx -zp1 -s)
// fz_145760_t1 (Schatten ueber Riva) - Pass 1 Einheit 145760-146920
#include <string.h>
#include <stdlib.h>
#pragma inline_depth(0)
int f_1664d0(const char *a, const char *b, int c);
int f_014540(int sz, const char *file, int line);
int f_099ef0(int, ...);
int f_145547(const char *a, const char *b, int n);
void f_145300(void *p, int v, int n);
void *f_147c84(void *p, int n, int d);
int f_147cd0(int p1);
int f_147ef0(int p1, int p2, char *p3, int p4);
int f_1680f5(int a, int b);
int f_1687c9(int a, int b);
short f_167f75(int a, void *b);
int f_146d86(int a, int b);
extern int d_1a97dc; extern int d_1c3914; extern int d_1a9824; extern short d_1c3918; extern int d_1c391c;
extern int d_1a9698; extern int d_1baac0; 
extern const char d_1b8970[]; extern const char d_1b8979[]; extern const char d_1b8982[]; extern const char d_1b898c[];
extern const char d_1a97e0[]; extern const char d_1a97f4[]; extern const char d_1a980c[]; extern const char d_1b8996[];
struct RivaFileStream;
struct X266 { char d[0x266]; };
struct RGB3 { unsigned char r,g,b; RGB3(); };
int f_145c20(RivaAifImage *p); int f_145c80(RivaAifImage *p); int f_145d60(RivaAifImage *p, int p3); int f_145e30(RivaAifImage *p, char *dst);
void f_145ee0(RivaAifImage *p, char *dst); void f_146030(RivaAifImage *p, char *dst); void f_146170(RivaAifImage *p, char *dst);
short f_145a60(RivaAifImage *p, int name, int p3, char *buf, char fl);
char f_145df0(RivaAifImage *p);
#define ABS(x) abs(x)
#define ROLL(r,e) { short _e = (e); int _t; if (_e <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f); _t = (int)_lrotl(_lrotl(d_1a97dc ^ d_1c3914, 2) + d_1c3914 ^ d_1a97dc, 3); d_1a97dc = ABS(_t) + 1; r = ABS(_t) % _e + 1; }
//@ f_145970
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Standardkonstruktor eines RivaAifImage-Objekts, der die virtuelle Methodentabelle
 *   (d_1a97f4) einträgt, den Basiskonstruktor (f_12e1d0) für den Dateizugriff aufruft und alle Header- und
 *   Statusfelder (Kennung, Abmessungen, Farbtiefe, Palettenflags, Kompressionsart) auf 0 bzw. -1 initialisiert.
 * - Eingaben: p1 (Zeiger auf das RivaAifImage-Objekt).
 * - Rückgabewert: Gibt den initialisierten Objektzeiger p1 zurück.
 * - Wichtige Variablen:
 *   - hdr_id (+0x28), w (+0x2e), h (+0x30), pal_flag (+0x37), comp (+0x38): Felder des 20-Byte-AIF-Headers im
 *     Objekt.
 === Ende Beschreibung === */
extern const char d_1a97f4[];           // Text 0x1A9874
#define I(p,o) (*(int *)((p)+(o)))
#define ERR(s,l) f_1664d0(s, d_1a97f4, l)
RivaAifImage *f_145970(RivaAifImage *p, RivaFileStream *f)
{
  if (f == 0) ERR(d_1b898c, 0x1b);
  p->c26 = 0;
  p->f = f;
  p->c27 = p->c28 = p->c26;
  return p;
}

//@ f_1459b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Überladener Standardkonstruktor von RivaAifImage, der als Dateisystem-Stream den globalen
 *   Standard-Dateimanager (&d_1c2098) in p->f einträgt und die Puffer-/Besitzflags c26, c27 und c28 auf 0 setzt.
 * - Eingaben: p (Zeiger auf das RivaAifImage-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->f (Dateistream-Zeiger), p->c26 (Virtuell-/Archiv-Flag), p->c27
 *   (Palettenpuffer-Besitzflag), p->c28 (Pixelpuffer-Besitzflag).
 === Ende Beschreibung === */
void f_1459b0(RivaAifImage *p)
{ p->f = (RivaFileStream *)&d_1c2098; p->c27 = p->c28 = p->c26 = 0; }
//@ f_1459d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor von RivaAifImage, der bei gesetztem Besitzflag p->c27 den intern angelegten
 *   Palettenpuffer p->buf und bei gesetztem Besitzflag p->c28 den intern angelegten Pixelpuffer p->out über
 *   delete freigibt.
 * - Eingaben: p (RivaAifImage *), fl (Destruktor-Flags).
 * - Rückgabewert: Gibt den Objektzeiger p zurück.
 * - Wichtige Variablen: p->c27, p->buf (Palette), p->c28, p->out (Entpackte Bilddaten).
 === Ende Beschreibung === */
RivaAifImage *f_1459d0(RivaAifImage *p, int fl)
{ if (p->c27) delete p->buf; if (p->c28) delete p->out; return p; }
//@ f_145a00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kurzform zum Laden einer AIF-Grafik anhand der Ressourcen-ID n ohne vorgegebene Zielpuffer
 *   und mit fl = 0 (f_145a60(p, n, 0, 0, 0)).
 * - Eingaben: p (RivaAifImage *), n (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_145a00(RivaAifImage *p, int n)
{
    ((void (*)(RivaAifImage *, int, int, char *, int))f_145a60)(p, n, 0, 0, 0);
}
//@ f_145a10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt die AIF-Grafik n in den vorgegebenen Pixel-Zielpuffer p3 bei intern verwaltetem
 *   Palettenpuffer und fl = 0 (f_145a60(p, n, p3, 0, 0)).
 * - Eingaben: p (RivaAifImage *), n (Ressourcen-ID), p3 (Zielpuffer für die Bildpixel).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_145a10(RivaAifImage *p, int n, int p3)
{
    ((void (*)(RivaAifImage *, int, int, char *, int))f_145a60)(p, n, p3, 0, 0);
}
//@ f_145a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Überladener Konstruktor von RivaAifImage, der die AIF-Datei anhand eines Dateinamens (p2)
 *   über die virtuelle Methode s3 (f_145c00) öffnet und den Header prüft.
 * - Eingaben: p1 (Objektzeiger), p2 (Dateiname als const char *).
 * - Rückgabewert: Gibt p1 zurück.
 * - Wichtige Variablen: Identisch mit f_145970.
 === Ende Beschreibung === */
void f_145a20(RivaAifImage *p, int n, int p3, char *b)
{
    ((void (*)(RivaAifImage *, int, int, char *, int))f_145a60)(p, n, p3, b, 0);
}
//@ f_145a30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt die AIF-Grafik n mit gesetztem Virtuell-/Archiv-Flag fl = 1 und automatisch
 *   angelegten Puffern (f_145a60(p, n, 0, 0, 1)).
 * - Eingaben: p (RivaAifImage *), n (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_145a30(RivaAifImage *p, int n)
{
    ((int (*)(RivaAifImage *, int, int, char *, int))f_145a60)(p, n, 0, 0, 1);
}
//@ f_145a40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt die AIF-Grafik n mit gesetztem Flag fl = 1 in den vorgegebenen Pixel-Zielpuffer p3
 *   (f_145a60(p, n, p3, 0, 1)).
 * - Eingaben: p (RivaAifImage *), n (Ressourcen-ID), p3 (Pixel-Zielpuffer).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_145a40(RivaAifImage *p, int n, int p3)
{
    f_145a60(p, n, p3, 0, 1);
}
//@ f_145a50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt die AIF-Grafik n mit gesetztem Flag fl = 1 in den Pixel-Zielpuffer p3 und den
 *   Palettenpuffer b (f_145a60(p, n, p3, b, 1)).
 * - Eingaben: p (RivaAifImage *), n (Ressourcen-ID), p3 (Pixel-Zielpuffer), b (Palettenpuffer).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen.
 === Ende Beschreibung === */
void f_145a50(RivaAifImage *p, int n, int p3, char *b)
{
    f_145a60(p, n, p3, b, 1);
}
//@ f_145a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zentrale Laderoutine von RivaAifImage: Sie speichert die Ressourcen-ID name und das Flag
 *   fl (p->c26), übernimmt oder ersetzt einen extern übergebenen Palettenpuffer buf, liest über f_145c20 den
 *   30-Byte-AIF-Header, reserviert bei p->buf == 0 ein RGB3-Array für p->n Farben (p->c27 = 1), liest über
 *   f_145c80 die Palette und entpackt schließlich über f_145d60(p, p3) die Pixeldaten.
 * - Eingaben: p (RivaAifImage *), name (Ressourcen-ID), p3 (Zielpuffer für Bilddaten oder 0), buf (Zielpuffer
 *   für Palette oder 0), fl (Bit-31-Steuerflag für den Dateimanager).
 * - Rückgabewert: 1 (short), wenn Header, Palette und Bilddaten erfolgreich geladen wurden, sonst 0.
 * - Wichtige Variablen: result (Erfolgsstatus), p->n (Farbanzahl der Palette), p->buf (Palettenpuffer), p->c27
 *   (Besitzflag für p->buf).
 === Ende Beschreibung === */
short f_145a60(RivaAifImage *p, int name, int p3, char *buf, char fl)
{
 p->name = name;
 int result = 0;
 if (p->c27 == 0) {
  p->buf = buf;
 } else if (buf != 0) {
  delete p->buf;
  p->c27 = 0;
  p->buf = buf;
 }
 p->c26 = fl;
 p->c28 = 0;
 if (f_145c20(p)) {
  if (p->buf == 0) {
   p->buf = (char *)new (mark(d_1a97f4, 0x78)) RGB3[p->n];
   p->c27 = 1;
  }
  if (f_145c80(p)) {
   if (f_145d60(p, p3)) result = 1;
  }
 }
 return result;
}
//@ f_145b10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Überträgt die geladene AIF-Farbpalette p->buf (ab Startfarbe p->c mit p->n Einträgen) über
 *   f_099ef0 in die aktive VGA-Farbpalette, sofern im Header das Paletten-Flag p->f5 == 0 (Palette vorhanden)
 *   steht.
 * - Eingaben: p (RivaAifImage *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->f5 (0 = Bild besitzt eigene Palette), p->buf (Palettendaten), p->c (erster
 *   Farbindex), p->n (Anzahl der Farben).
 === Ende Beschreibung === */
void f_145b10(RivaAifImage *p)
{
    void palette_494(void *, int, int);
    #pragma aux palette_494 "f_099ef0" parm caller [] modify exact [eax ecx edx]
    if (p->f5 == 0)
        palette_494(p->buf, p->c, p->n);
}
//@ f_145b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert das Format-/Tiefe-Byte +0x32 des AIF-Headers oder -1 bei ungültigem Zustand.
 * - Eingaben: p1 (Zeiger auf RivaAifImage).
 * - Rückgabewert: Wert von Feld +0x32 oder -1.
 * - Wichtige Variablen: f32 (+0x32).
 === Ende Beschreibung === */
char *f_145b40(RivaAifImage *p)
{
    return p->buf;
}
//@ f_145b50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Bildbreite p->w und die Bildhöhe p->h des geladenen AIF-Bildes in die beiden
 *   16-Bit-Ausgabezeiger *w und *h aus.
 * - Eingaben: p (RivaAifImage *), w (Ausgabezeiger für Breite), h (Ausgabezeiger für Höhe).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->w, p->h.
 === Ende Beschreibung === */
void f_145b50(RivaAifImage *p, short *w, short *h)
{
    *w = p->w;
    *h = p->h;
}
//@ f_145b70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Zeiger p->out auf den Puffer mit den entpackten Pixeldaten des AIF-Bildes zurück.
 * - Eingaben: p (RivaAifImage *).
 * - Rückgabewert: Zeiger auf den Pixelpuffer (char *).
 * - Wichtige Variablen: p->out.
 === Ende Beschreibung === */
char *f_145b70(RivaAifImage *p)
{
    return p->out;
}
//@ f_145b80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert die Kompressionsmethode der AIF-Grafik (+0x38: 0 = roh, 1 = RLE1, 2 =
 *   RLE2/PackBits, 3 = PowerPack/LZW) oder -1 im Fehlerfall.
 * - Eingaben: p1 (Zeiger auf RivaAifImage).
 * - Rückgabewert: Kompressionscode (0-3) oder -1.
 * - Wichtige Variablen: comp (+0x38).
 === Ende Beschreibung === */
void f_145b80(RivaAifImage *p, int name, short *w, short *h)
{ int old = p->name; p->name = name; f_145c20(p); *w = p->w; *h = p->h; p->name = old; } // echte Zustandssicherung von p->name waehrend des Header-Lesens im Originalcode
//@ f_145bb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob es sich bei der Ressource name um eine gültige AIF-Grafikdatei handelt, indem
 *   die ersten 30 Bytes (0x1e) über den Dateistream p->f eingelesen und die ersten 3 Bytes per strncmp
 *   (f_145547) mit der Kennung "AIF" (d_1b8996) verglichen werden.
 * - Eingaben: p (RivaAifImage *), name (Ressourcen-ID).
 * - Rückgabewert: 1, wenn die Datei geöffnet werden konnte und mit "AIF" beginnt, sonst 0.
 * - Wichtige Variablen: result (Prüfergebnis), d_1b8996 (Signaturstring "AIF").
 === Ende Beschreibung === */
int f_145bb0(RivaAifImage *p, int name)
{
    int result = 0;
    if (p->c26)
        name |= 0x80000000;
    if (p->f->vt->m14(p->f, name, 0x200) > 0) {
        p->f->vt->m20(p->f, p, 0x1e);
        p->f->vt->m28(p->f);
        if (f_145547(d_1b8996, (char *)p, 3) == 0)
            result = 1;
    }
    return result;
}
//@ f_145c20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die in p->name angegebene Ressource im Lesemodus (0x200) über die virtuelle
 *   Stream-Methode m14 (wobei bei p->c26 != 0 zuvor Bit 31 in p->name gesetzt wird), liest den 30 Byte (0x1e)
 *   großen AIF-Header direkt in den Beginn der RivaAifImage-Struktur p (m20) und schließt die Datei wieder
 *   (m28).
 * - Eingaben: p (RivaAifImage *).
 * - Rückgabewert: 1 bei erfolgreichem Einlesen des Headers, sonst 0.
 * - Wichtige Variablen: r (Rückgabestatus), p->name (Ressourcen-ID).
 === Ende Beschreibung === */
typedef int (*VF1)(int);
typedef int (*VF3)(int, int, int);
#define OBJ(p) (*(int *)((p) + 0x3f7))
#define VC(p, off) (*(int *)(*(int *)(OBJ(p) + 0x14) + (off)))
int f_145c20(RivaAifImage *p)
{
    int r = 0;
    if (p->c26)
        ((unsigned char *)&p->name)[3] |= 0x80;
    if (p->f->vt->m14(p->f, p->name, 0x200) > 0) {
        p->f->vt->m20(p->f, p, 0x1e);
        p->f->vt->m28(p->f);
        r = 1;
    }
    return r;
}

//@ f_145c80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die in der AIF-Datei gespeicherte Farbpalette (ab Dateioffset 20) in das
 *   Paletten-Zielarray p2 ein und rechnet dabei die RGB-Komponenten durch Rechtsverschiebung um 2 Bits (>> 2)
 *   von 8-Bit-Werten (0..255) auf das 6-Bit-VGA-DAC-Format (0..63) um. Es werden die im Header als gültig
 *   markierten Palettenbereiche (pal_start1..pal_cnt1 sowie optional ein zweiter Bereich pal_start2..pal_cnt2)
 *   eingelesen.
 * - Eingaben: p1 (Zeiger auf RivaAifImage), p2 (Zielpuffer für die 768-Byte-VGA-Palette).
 * - Rückgabewert: 1 bei Erfolg, 0 wenn das Bild keine Palette besitzt oder ein Lesefehler auftritt.
 * - Wichtige Variablen:
 *   - rgb: 3-Byte-Puffer auf dem Stack für jeweils einen RGB-Farbeintrag.
 *   - pal_start1 (+0x33), pal_cnt1 (+0x34), pal_start2 (+0x35), pal_cnt2 (+0x36): Startindizes und Längen der
 *     beiden Teilpaletten im AIF-Header.
 === Ende Beschreibung === */
int f_145c80(RivaAifImage *p)
{
    int result = 0;
    if (p->f5 == 0) {
        if (p->c26)
            p->name |= 0x80000000;
        if (p->f->vt->m14(p->f, p->name, 0x200) > 0) {
            p->f->vt->m40(p->f, -(p->n * 3), 2);
            p->f->vt->m20(p->f, p->buf, p->n * 3);
            p->f->vt->m28(p->f);
            result = 1;
        }
        if (result == 1) {
            short i = 0;
            while (i < p->n) {
                p->buf[i * 3] = p->buf[i * 3] & 0x3f;
                p->buf[i * 3 + 1] = p->buf[i * 3 + 1] & 0x3f;
                p->buf[i * 3 + 2] = p->buf[i * 3 + 2] & 0x3f;
                ++i;
            }
        }
    }
    return result;
}

//@ f_145d60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die AIF-Ressource p->name, bestimmt aus der Gesamtdateigröße (m30) abzüglich 30
 *   Byte Header (0x1e) und Palettengröße (p->n * 3) die komprimierte Datenlänge p->len, positioniert den
 *   Lesezeiger auf Offset 0x1e (m40), ruft den Entpacker-Dispatcher f_145e30(p, (char *)dst) auf und schließt
 *   die Datei (m28).
 * - Eingaben: p (RivaAifImage *), dst (Zielpufferadresse als int oder 0 für Neuallokation).
 * - Rückgabewert: 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: len (Gesamtdateilänge), p->len (Länge des Bilddatenstroms).
 === Ende Beschreibung === */
int f_145d60(RivaAifImage *p, int dst) {
 int result=0;
 if(p->c26) ((unsigned char*)&p->name)[3] |= 0x80;
 if(p->f->vt->m14(p->f,p->name,0x200)>0) {
  int len=p->f->vt->m30(p->f);
  p->len=len-0x1e-p->n*3;
  p->f->vt->m40(p->f,0x1e,0);
  f_145e30(p,(char*)dst);
  result=1;
  p->f->vt->m28(p->f);
 }
 return result;
}
//@ f_145df0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gepufferte Einzelbyte-Lesefunktion für die RLE-Entpacker: Sie erhöht den Pufferindex
 *   p->idx, lädt beim Erreichen von 99 die nächsten 100 Bytes aus dem Stream p->f in den Zwischenpuffer p->b100
 *   nach und liefert das aktuelle Byte p->b100[p->idx] zurück.
 * - Eingaben: p (RivaAifImage *).
 * - Rückgabewert: Das nächste gelesene Datenbyte (char).
 * - Wichtige Variablen: p->idx (Leseindex 0..99), p->b100 (100-Byte-Lesepuffer im Objekt).
 === Ende Beschreibung === */
char f_145df0(RivaAifImage *p)
{
 if (p->idx++ == 99) { p->f->vt->m20(p->f, p->b100, 100); p->idx = 0; }
 return p->b100[p->idx];
}
#define RD(v) v = f_145df0(p);
//@ f_145e30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entpacker-Dispatcher für die Bilddaten einer geöffneten AIF-Datei: Falls kein Zielpuffer
 *   dst übergeben wurde (dst == 0), reserviert die Funktion einen neuen Puffer der Größe p->w * p->h (p->c28 =
 *   1), setzt den Lesepufferindex p->idx = 99 zurück und verzweigt anhand des Kompressionstyps p->type auf
 *   direktes Blocklesen (type == 0, m20), Lauflängenkodierung 1 (type == 1, f_145ee0), PackBits-RLE (type == 2,
 *   f_146030) oder LZW/PowerPack (type == 3, f_146170).
 * - Eingaben: p (RivaAifImage *), dst (Zielpuffer oder 0).
 * - Rückgabewert: 1 bei Erfolg, 0 wenn die Speicherreservierung fehlschlägt.
 * - Wichtige Variablen: kind (p->type, Kompressionsverfahren 0..3), p->out (Zeiger auf den Ausgabepuffer).
 === Ende Beschreibung === */
int f_145e30(RivaAifImage *p, char *dst)
{
    p->out = 0;
    if (dst == 0) {
        void *tag = mark(d_1a97f4, 0x12c);
        dst = (char *)operator new[]((unsigned)(p->w * p->h), tag);
        if (!dst) return 0;
        p->c28 = 1;
    }
    p->idx = 99;
    int kind = p->type;
    p->out = dst;
    if (kind == 0)
        p->f->vt->m20(p->f, dst, p->len);
    else if (kind == 1)
        f_145ee0(p, dst);
    else if (kind == 2)
        f_146030(p, dst);
    else if (kind == 3)
        f_146170(p, dst);
    return 1;
}
//@ f_145ec0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest bei unkomprimierten AIF-Grafiken (type == 0) den gesamten Rohpixelblock der Länge
 *   p->len in einem Stück über die virtuelle Stream-Methode m20 in den Zielpuffer d.
 * - Eingaben: p (RivaAifImage *), d (Zielpuffer void *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->len (Anzahl der zu lesenden Bytes).
 === Ende Beschreibung === */
void f_145ec0(RivaAifImage *p, void *d)
{
    p->f->vt->m20(p->f, d, p->len);
}
//@ f_145ee0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dekodiert eine nach Verfahren 1 lauflängenkodierte AIF-Grafik zeilenweise (h Zeilen zu je
 *   w Pixeln) in den Puffer p2. Ist in einem Steuerbyte Bit 7 (0x80) gesetzt, geben die unteren 7 Bits (b &
 *   0x7f) die Wiederholungsanzahl des nachfolgenden Farbbytes an; andernfalls ist das Byte selbst ein einzelner
 *   Pixelwert.
 * - Eingaben: p1 (AIF-Objekt), p2 (Zielpuffer).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Speicher- oder Lesefehlern.
 * - Wichtige Variablen:
 *   - buf: Temporärer Lesepuffer für den komprimierten Datenstrom.
 *   - b: Aktuelles Steuer- oder Pixelbyte.
 *   - val: Zu wiederholender Farbwert bei RLE-Läufen (memset / f_145300).
 === Ende Beschreibung === */
void f_145ee0(RivaAifImage *p, char *dst)
{
 short x, y;
 unsigned char n, c;
 y = 0;
 while (y < p->h) {
  for (x = 0; x < p->w; ) {
   RivaAifImage *q = p;
   if (p->idx++ == 99) {
    p->f->vt->m20(p->f, p->b100, 100);
    p->idx = 0;
   }
   c = q->b100[q->idx];
   if (c == 0x7f) {
    unsigned char v;
    short k;
    RivaAifImage *q2 = p;
    if (p->idx++ == 99) {
     p->f->vt->m20(p->f, p->b100, 100);
     p->idx = 0;
    }
    n = q2->b100[q2->idx];
    RivaAifImage *q3 = p;
    if (p->idx++ == 99) {
     p->f->vt->m20(p->f, p->b100, 100);
     p->idx = 0;
    }
    v = q3->b100[q3->idx];
    for (k = 0; k < n; k++)
     *(dst + x + k) = v;
    x += n;
   } else {
    dst[x] = c;
    x++;
   }
  }
  ++y;
  dst += p->w;
 }
}
//@ f_146030
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dekodiert eine nach Verfahren 2 (PackBits-Variante) komprimierte AIF-Grafik zeilenweise in
 *   den Zielpuffer p2. Ist im Steuerbyte Bit 7 (0x80) gesetzt, wird das folgende Farbbyte (b & 0x7f)-mal
 *   wiederholt (memset); ist Bit 7 nicht gesetzt, folgen b unkomprimierte Literal-Pixel (memcpy / f_1452f0).
 * - Eingaben: p1 (AIF-Objekt), p2 (Zielpuffer).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehlern.
 * - Wichtige Variablen: buf (Eingabepuffer), b (Steuerbyte), cnt (b & 0x7f).
 === Ende Beschreibung === */
void f_146030(RivaAifImage *p, char *dst)
{
 for (int i = 0; i < p->len; i++) {
  unsigned char repeat_n, literal_n, c;
  {
  RivaAifImage *q = p;
  if (p->idx++ == 99) {
   p->f->vt->m20(p->f, p->b100, 100);
   p->idx = 0;
  }
  c = q->b100[q->idx];
  if (c & 0x80) {
   repeat_n = 1 - c;
   unsigned char value;
   RivaAifImage *q2 = p;
   if (p->idx++ == 99) {
    p->f->vt->m20(p->f, p->b100, 100);
    p->idx = 0;
   }
   value = q2->b100[q2->idx];
   i++;
   do {
    *dst++ = value;
   } while (--repeat_n > 0);
  } else {
   literal_n = c + 1;
   do {
    RivaAifImage *q3 = p;
    if (p->idx++ == 99) {
     p->f->vt->m20(p->f, p->b100, 100);
     p->idx = 0;
    }
    *dst++ = q3->b100[q3->idx];
    i++;
   } while (--literal_n > 0);
  }
  }
 }
}
//@ f_146170
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dekodiert eine nach Verfahren 3 (PowerPack / LZW) komprimierte AIF-Grafik in den
 *   Zielpuffer p2. Sie positioniert den Dateizeiger hinter Header und Palette und übergibt das Dateiobjekt an
 *   den PowerPack-Entpacker (f_147cd0, f_147f95, f_147cf5).
 * - Eingaben: p1 (AIF-Objekt), p2 (Zielpuffer).
 * - Rückgabewert: 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: pp (lokale Instanz des PowerPack-Entpackers P auf dem Stack).
 === Ende Beschreibung === */
void f_146170(RivaAifImage *p, char *dst)
{
 X266 *x;
 p->tmp = new (mark(d_1a97f4, 0x1a0)) char[p->len];
 p->f->vt->m20(p->f, p->tmp, p->len);
 int allocation = (int)operator new(0x266, mark(d_1a97f4, 0x1a3));
 x = allocation ? (X266 *)f_147cd0(allocation) : (X266 *)allocation;
 f_147ef0((int)x, (int)dst, p->tmp, p->len);
 delete x; delete p->tmp;
}
#define MD 0x200
struct REC { int a; char z0[8]; unsigned len; char z1[0xc]; int r1c; char z2[0xc]; int r2c; char z3[4]; int r34; int r38; int r3c; int r40; int r44; int r48; char z4[0x10]; void *r5c; void *r60; char z5[0x8c]; };
struct HM { int a; unsigned short s4; int b; int c; int d; int e; short idx; int pos; short s1c; unsigned short s1e; short s20; int i22; unsigned short mode; int x; RivaFileStream *f; char *buf[2]; REC rec[2]; short off; };
struct CB { char z[0x28]; unsigned short w; };
void f_146552(HM *p); void f_1466cd(HM *p); void f_146864(HM *p, int *q); void f_1468dc(HM *p); void __cdecl f_146809(CB *a); void __cdecl f_146839(CB *a);
