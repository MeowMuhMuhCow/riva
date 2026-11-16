/* === Beschreibung (Katalog) ===
 * Einheit fz_15689d_t4 (0x15C9B0 - 0x15DB68)
 *
 * Überblick
 * Diese Einheit umfasst im ersten Teil (f_15c9b0 bis f_15d480) die Paletten-, RLE-Entpack- und
 * RLE-Speicherroutinen für 256-Farben-PCX-Grafiken (z. B. für Screenshots oder Hilfebilder) und im zweiten Teil
 * (f_15d4d0 bis f_15dadc) die Navigations-, Trefferprüfungs- und Rechteck-Abfragefunktionen für interaktive
 * Hyperlinks (Elementtyp 5/6) innerhalb des Hypertext-Anzeigesystems.
 === Ende Beschreibung === */
// P3 14/21 gleich (suche.py 30.10.2026, Basis fz_15689d_t4_P1.CPP)
// OPT -4r -oneatx -oe=0 -zp1 -s
// P3 11/21 gleich (suche.py 27.10.2026, Basis fz_15689d_t4_P1.CPP)
// fz_15689d_t4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x15C9B0-0x15DB68
#include <string.h>
#pragma inline_depth(0)
#define ST short
#define SH(x) (x)
#include "RIVAMEM.H"



int f_1664d0(const char *msg, const char *file, int line);
char *f_147c84(char *p1, int p2, char *p3);
struct Pt { int a; int b; };
struct R32 { int t; Pt p; short w; short h; Pt q; int c; int d; };
struct Vec { int base; int f4; int f8; int f12; };
void f_15c170(Vec *v);
void f_15c1a0(Vec *v);
short f_15cbb0(int p1, char *p2);
void f_15cf90(int p1, short p2, short p3);
int f_15d040(int p1, char *p2);
int f_15d1d0(int p1, unsigned char *p2, ST p3, ST p4, ST p5);
unsigned f_15d4e8(Vec *v);
int f_15d584(int *r);
Pt f_15da8c(int p1);
extern const char d_1a9c04[];
extern const char d_1b9564[];
extern const char d_1b957e[];
extern const char d_1b958a[];
extern char d_1baac0[];
extern int d_1cdf98;
extern int d_1cdf9c;
extern Vec *d_1cddbc;
typedef int (*VF1)(int);
typedef int (*VF3)(int, int, int);
#define PAIR(a, b, src) a = src; b = a;
#define OBJ(p) (*(int *)((p) + 0x3f7))
#define VC(p, off) (*(int *)(*(int *)(OBJ(p) + 0x14) + (off)))
#define CNT(v) (((v)->f8 - (v)->f4) / 32)
#define ENS1(v, i, u) u = (i) * 0x20 + (v)->base; if ((unsigned)(v)->f8 <= u) { (v)->f8 = u + 0x20; f_15c170(v); }
#define ENS2(v, i, u) u = (i) * 0x20 + (v)->base; if ((unsigned)(v)->f8 <= u) { u += 0x20; (v)->f8 = u; if ((unsigned)(v)->f12 <= u) f_15c1a0(v); }
#define PUT(p1, buf, v) *(char *)(*(short *)((p1) + 0x38d) + (p1) + 0x38f) = (v); if (++(*(short *)((p1) + 0x38d)) == 100) { ((VF3)VC(p1, 0x24))(OBJ(p1), buf, 100); *(short *)((p1) + 0x38d) = 0; }
//@ f_15c9b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die 256-Farben-VGA-Palette am Ende einer PCX-Version-5-Datei (*(char *)(p1 + 1) ==
 *   5) ein, indem der Dateizeiger auf 769 Bytes vor Dateiende (0xFFFFFCFF, Modus SEEK_END) positioniert, das
 *   Kennbyte 12 (0x0C) geprüft, der 0x300-Byte-RGB-Block nach p1 + 0x80 gelesen und jeder 8-Bit-Farbwert durch 4
 *   auf 6-Bit-VGA-Bereich (0..63) heruntergeteilt wird.
 * - Eingaben: Zeiger p1 auf das PCX-Objekt.
 * - Rückgabewert: int - 1 wenn eine gültige 256-Farben-Palette gefunden und skaliert wurde, sonst 0.
 * - Wichtige Variablen:
 *   - *(signed char *)(p1 + 0x380): Eingelesenes Paletten-Kennbyte (muss 12 sein).
 === Ende Beschreibung === */
int f_15c9b0(int p1)
{
    int r = 0;
    short i;
    int q;
    if (*(signed char *)(p1 + 1) == 5) {
        if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x200) > 0) {
            ((VF3)VC(p1, 0x40))(OBJ(p1), 0xfffffcff, 2);
            ((VF3)VC(p1, 0x20))(OBJ(p1), p1 + 0x380, 1);
            if (*(signed char *)(p1 + 0x380) == 12) {
                ((VF3)VC(p1, 0x20))(OBJ(p1), p1 + 0x80, 0x300);
                ((VF1)VC(p1, 0x28))(OBJ(p1));
                for (i = 0; i < 0x100; i++) {
                    q = p1 + i * 3;
                    *(char *)(q + 0x80) /= 4;
                    *(char *)(q + 0x81) /= 4;
                    *(char *)(q + 0x82) /= 4;
                }
                r = 1;
                goto done;
            }
            ((VF1)VC(p1, 0x28))(OBJ(p1));
        }
    }
done:
    return r;
}
//@ f_15cae0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest das nächste Byte aus dem 100-Byte-Lesepuffer (p1 + 0x38F) des PCX-Objekts und füllt
 *   den Puffer automatisch über das Stream-Gerät nach, sobald der Leseindex (p1 + 0x38D) den Wert 99 erreicht.
 * - Eingaben: Zeiger p1 auf das PCX-Objekt.
 * - Rückgabewert: char - das nächste gelesene Datenbyte.
 * - Wichtige Variablen:
 *   - *(short *)(p1 + 0x38d): Aktueller Index (0..99) innerhalb des 100-Byte-Zwischenpuffers p1 + 0x38f.
 === Ende Beschreibung === */
char f_15cae0(int p1)
{
    short t = (*(short *)(p1 + 0x38d))++;
    if (t == 99) {
        ((VF3)VC(p1, 0x20))(OBJ(p1), p1 + 0x38f, 100);
        *(short *)(p1 + 0x38d) = 0;
    }
    return *(char *)(p1 + 0x38f + *(short *)(p1 + 0x38d));
}
//@ f_15cb30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die im PCX-Objekt p1 hinterlegte Datei, berechnet aus der Gesamtdateigröße
 *   abzüglich 0x381 (128 Bytes Header + 769 Bytes Palette) die Länge des komprimierten Bilddatenblocks (p1 +
 *   0x389), springt an Datei-Offset 0x80 und entpackt das Bild über f_15cbb0 in den Zielpuffer p2.
 * - Eingaben: PCX-Objekt p1 und optionaler Zielpuffer p2 (0 = automatisch reservieren).
 * - Rückgabewert: int - 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen:
 *   - *(int *)(p1 + 0x389): Anzahl der komprimierten Datenbytes zwischen Header und Palette.
 === Ende Beschreibung === */
int f_15cb30(int p1, char *p2)
{
    int r = 0;
    int n;
    if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x200) > 0) {
        n = ((VF1)VC(p1, 0x30))(OBJ(p1));
        *(int *)(p1 + 0x389) = n - 0x381;
        ((VF3)VC(p1, 0x40))(OBJ(p1), 0x80, 0);
        f_15cbb0(p1, p2);
        ((VF1)VC(p1, 0x28))(OBJ(p1));
        r = 1;
    }
    return r;
}
//@ f_15cbb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entpackt die RLE-komprimierten 8-Bit-Pixeldaten (1 Farbebene, 8 Bits pro Pixel) eines
 *   PCX-Bildes zeilenweise über einen Zwischenpuffer tmp der Länge bytes_per_line (*(short *)(p1 + 0x42)) in den
 *   Zielbildpuffer p2: Bytes mit gesetzten oberen zwei Bits ((c & 0xC0) == 0xC0) geben eine Lauflänge cnt = c &
 *   0x3F für das nachfolgende Farbbyte lit an.
 * - Eingaben: PCX-Objekt p1 und Zielpuffer p2 (wird bei p2 == 0 mit w * h Bytes neu angelegt).
 * - Rückgabewert: short - 1 bei erfolgreichem Entpacken, 0 bei Speicherfehler oder nicht unterstütztem
 *   Farbmodus.
 * - Wichtige Variablen:
 *   - w, h: Bildbreite und Bildhöhe aus dem PCX-Header.
 *   - tmp: Zeilenpuffer der Länge bytes_per_line (+0x42).
 *   - o: Aktuelle Schreibposition innerhalb der laufenden Bildzeile tmp.
 === Ende Beschreibung === */
// Blind-Neubau DeepSeek 2628 (04.11.2026) aus dem Original-ASM.
#define GETB(p, b, dst) do { \
    short t_ = (*(short *)((p) + 0x38d))++; \
    if (t_ == 99) { \
        ((VF3)VC(p, 0x20))(OBJ(p), (int)(b), 100); \
        *(short *)((p) + 0x38d) = 0; \
    } \
    (dst) = ((char *)((p) + 0x38f))[*(short *)((p) + 0x38d)]; \
} while (0)

short f_15cbb0(int p1, char *p2)
{
    short o;
    short h;
    char *tmp;
    char c;
    int result = 1;
    short w;
    unsigned char cnt;
    char lit;
    int k;
    short j;
    (void)*(volatile char *)&w; (void)*(volatile char *)&h; // haelt die Registerzuteilung wie im Original
    w = (short)(*(short *)(p1 + 8) - *(short *)(p1 + 4) + 1);
    h = (short)(*(short *)(p1 + 0xa) - *(short *)(p1 + 6) + 1);

    { char * u_ = tmp; tmp = u_; } // haelt die Registerzuteilung wie im Original
    *(int *)(p1 + 0x381) = 0;
    if (p2 == 0) {
        p2 = new (mark(d_1a9c04, 0x131)) char[w * h];
        if (p2 == 0)
            result = 0;
        else
            *(int *)(p1 + 0x3f3) = 1;
    }
    if (result == 1) {
        *(int *)(p1 + 0x381) = (int)p2;
        *(short *)(p1 + 0x38d) = 99;
        if (*(signed char *)(p1 + 0x41) == 1 && *(signed char *)(p1 + 3) == 8) {
            tmp = new (mark(d_1a9c04, 0x147)) char[*(short *)(p1 + 0x42)];
    { int u_ = result; result = u_; } // haelt die Registerzuteilung wie im Original
            o = 0;
            for (k = 0; k < *(int *)(p1 + 0x389); k++) {
                if (*(char *)(p1 + 2)) {
                    int q = p1;
                    GETB(q, p1 + 0x38f, c);
                    if ((c & 0xc0) == 0xc0) {
                        cnt = c & 0x3f;
                        int q2 = p1;
                        GETB(q2, p1 + 0x38f, lit);
                        k++;
                        { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } { char * u_ = p2; p2 = u_; } // haelt die Registerzuteilung wie im Original
                        for (j = 0; j < cnt; j++)
                            tmp[o++] = lit;
                    } else {
                        tmp[o++] = c;
                    }
                } else {
                    int q = p1;
                    GETB(q, p1 + 0x38f, lit);
                    tmp[o++] = lit;
                }
                if (o > *(short *)(p1 + 0x42))
                    f_1664d0(d_1b9564, d_1a9c04, 0x167);
                if (o == *(short *)(p1 + 0x42)) {
                    memcpy(p2, tmp, w);
                    p2 += w;
                    o = 0;
                }
    { char * u_ = tmp; tmp = u_; } // haelt die Registerzuteilung wie im Original
    { char * u_ = p2; p2 = u_; } // haelt die Registerzuteilung wie im Original
            }
    { char * u_ = p2; p2 = u_; } // haelt die Registerzuteilung wie im Original
    { int u_ = p1; p1 = u_; } // haelt die Registerzuteilung wie im Original
            delete tmp;
        } else {
            result = 0;
        }
    }
    { char * u_ = tmp; tmp = u_; } // haelt die Registerzuteilung wie im Original
    { char * u_ = p2; p2 = u_; } // haelt die Registerzuteilung wie im Original
    return result;
}

//@ f_15ce90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert ein 256-Farben-Bild der Größe p3 * p4 mit der Palette p5 und den Pixeldaten p6
 *   als vollständige PCX-Datei unter dem Namen p2, indem der Header initialisiert (f_15cf90) und geschrieben,
 *   die Bilddaten RLE-komprimiert angehängt (f_15d1d0) und zuletzt die Palette über f_15d040 ausgeschrieben
 *   werden.
 * - Eingaben: PCX-Objekt p1, Zieldateiname p2, Breite p3, Höhe p4, 256-Farben-Palette p5 und Pixelpuffer p6.
 * - Rückgabewert: int - 1 wenn alle drei Dateiteile erfolgreich geschrieben wurden, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
// Blind-Neubau DeepSeek 2508 (04.11.2026) aus dem Original-ASM.
// eax=this, edx=Modus, ebx=Breite(int), ecx=Hoehe(int), [esp+4]=Palette, [esp+8]=Pixeldaten.
int f_15ce90(int p1, int p2, short p3, short p4, char *p5, unsigned char *p6)
{
    int r = 0;
    int res;
    int ok;
    *(int *)(p1 + 0x385) = p2;
    f_15cf90(p1, p3, p4);
    ok = 0;
    if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x262) > 0) {
        ((VF3)VC(p1, 0x24))(OBJ(p1), p1, 0x80);
        ok = 1;
        ((VF1)VC(p1, 0x28))(OBJ(p1));
    }
    if (ok == 1) {
        res = 0;
        if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x202) > 0) {
            ((VF3)VC(p1, 0x40))(OBJ(p1), 0, 2);
            f_15d1d0(p1, p6, 1, p3, p4);
            ((VF1)VC(p1, 0x28))(OBJ(p1));
            res = 1;
        }
        if (res == 1) {
            if (f_15d040(p1, p5) == 1)
                r = 1;
        }
    }
    return r;
}

//@ f_15cf90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt den 128-Byte-PCX-Header in p1 für ein 8-Bit-RLE-Bild der Breite p2 und Höhe p3 aus
 *   (Hersteller 10, Version 5, RLE-Codierung 1, 8 Bits pro Pixel, 1 Ebene und auf gerade Bytezahl aufgerundete
 *   Zeilenbreite bytes_per_line an +0x42).
 * - Eingaben: PCX-Objekt p1, Bildbreite p2 und Bildhöhe p3.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Auf eine gerade Zahl aufgerundete Zeilenbreite *(short *)(p1 + 0x42).
 === Ende Beschreibung === */
void f_15cf90(int p1, short p2, short p3)
{
    int n;
    *(char *)p1 = 10;
    *(char *)(p1 + 1) = 5;
    *(char *)(p1 + 2) = 1;
    *(char *)(p1 + 3) = 8;
    *(short *)(p1 + 4) = 0;
    *(short *)(p1 + 6) = 0;
    *(char *)(p1 + 0x41) = 1;
    *(short *)(p1 + 0xc) = p2;
    *(short *)(p1 + 8) = p2 - 1;
    *(short *)(p1 + 10) = p3 - 1;
    *(short *)(p1 + 0xe) = p3;
    n = p2;
    if (n % 2)
        ++n;
    *(short *)(p1 + 0x44) = 0;
    *(short *)(p1 + 0x42) = n;
}
//@ f_15cff0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erstellt beziehungsweise öffnet die Zieldatei (p1 + 0x385) im Schreibmodus (0x262) und
 *   schreibt den 0x80-Byte-PCX-Header aus p1 an den Dateianfang.
 * - Eingaben: PCX-Objekt p1.
 * - Rückgabewert: int - 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15cff0(int p1)
{
    int r = 0;
    if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x262) > 0) {
        ((VF3)VC(p1, 0x24))(OBJ(p1), p1, 0x80);
        ((VF1)VC(p1, 0x28))(OBJ(p1));
        r = 1;
    }
    return r;
}
//@ f_15d040
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Skaliert eine 6-Bit-VGA-Palette p2 (256 * 3 Bytes) durch Linksshift um 2 (<< 2) auf volle
 *   8-Bit-PCX-Farbwerte hoch und hängt das Kennbyte 0x0C samt den 0x300 Palettenbytes an das Ende der PCX-Datei
 *   (p1 + 0x385) an.
 * - Eingaben: PCX-Objekt p1 und Quellpalette p2.
 * - Rückgabewert: int - 1 bei erfolgreichem Schreiben, sonst 0.
 * - Wichtige Variablen:
 *   - c: Paletten-Markierungsbyte 0x0C (12).
 *   - pal: Temporärer 0x300-Byte-Puffer mit den hochskalierten 8-Bit-RGB-Werten.
 === Ende Beschreibung === */
int f_15d040(int p1, char *p2)
{
    int r = 0;
    short c = 0xc;
    char *pal;
    short i;
    int q;
    if (p2 == 0) {
        f_1664d0(d_1b957e, d_1a9c04, 0x1d6);
    }
    char *tmp = f_147c84(new (mark(d_1a9c04, 0x1d8)) char[0x300], 0x100, d_1baac0);
    pal = tmp ? tmp : 0;
    for (i = 0; i < 0x100; i++) {
        q = i * 3;
        *(char *)(q + pal) = *(char *)(q + p2) << 2;
        *(char *)(q + 1 + pal) = *(char *)(q + 1 + p2) << 2;
        *(char *)(q + 2 + pal) = *(char *)(q + 2 + p2) << 2;
    }
    if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x202) > 0) {
        ((VF3)VC(p1, 0x40))(OBJ(p1), 0, 2);
        ((VF3)VC(p1, 0x24))(OBJ(p1), (int)&c, 1);
        ((VF3)VC(p1, 0x24))(OBJ(p1), (int)pal, 0x300);
        ((VF1)VC(p1, 0x28))(OBJ(p1));
        r = 1;
    }
    delete pal;
    return r;
}
//@ f_15d150
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die PCX-Zieldatei (p1 + 0x385) zum Anhängen, komprimiert das im Puffer p4
 *   übergebene Bild der Größe p2 * p3 über f_15d1d0 und schreibt die RLE-Daten an das Dateiende.
 * - Eingaben: PCX-Objekt p1, Breite p2, Höhe p3 und Quellpixelpuffer p4.
 * - Rückgabewert: int - 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15d150(int p1, ST p2, ST p3, unsigned char *p4)
{
    int r = 0;
    if (((VF3)VC(p1, 0x14))(OBJ(p1), *(int *)(p1 + 0x385), 0x202) > 0) {
        ((VF3)VC(p1, 0x40))(OBJ(p1), 0, 2);
        f_15d1d0(p1, p4, 1, SH(p2), SH(p3));
        ((VF1)VC(p1, 0x28))(OBJ(p1));
        r = 1;
    }
    return r;
}
//@ f_15d1d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Komprimiert ein unkomprimiertes 8-Bit-Bild p2 der Breite p4 und Höhe p5 nach dem
 *   PCX-RLE-Verfahren (Läufe gleicher Pixel > 1 bis maximal 63 oder Einzelpixelwerte >= 0xC0 werden als
 *   Zweibyte-Folge (0xC0 + cnt, c) codiert) und schreibt die Daten bei p3 != 0 gepuffert über den
 *   100-Byte-Schreibpuffer p1 + 0x38F in den Ausgabestrom.
 * - Eingaben: PCX-Objekt p1, Quellpixel p2, Schreibflag p3 (1 = wirklich schreiben, 0 = nur Größe zählen),
 *   Bildbreite p4 und Bildhöhe p5.
 * - Rückgabewert: int - Gesamtzahl n der erzeugten RLE-Bytes.
 * - Wichtige Variablen:
 *   - cnt: Aktuelle Lauflänge identischer Nachbarpixel innerhalb derselben Bildzeile (1..63).
 *   - n: Laufender Bytezähler der komprimierten Ausgabe.
 === Ende Beschreibung === */
// Blind-Neubau DeepSeek 2833 (05.11.2026) aus dem Original-ASM; GLEICH seit DeepSeek 3019 (05.11.2026):
// char-Temp zz im RLE-Zweig (Hilfsform) verschiebt die Stapel-Namensliste, damit p3=0x10 / y=0x14 wie im Original.
// eax=p1(this), edx=p2, bx=p3(Flag), cx=p4(Breite), [esp+4]=p5(Hoehe).
// RLE: Lauf >1 oder Byte >=0xc0 -> (0xc0+Lauf, Byte), sonst Einzelbyte.
int f_15d1d0(int p1, unsigned char *p2, ST p3, ST p4, ST p5)
{
    int n = 0;
    short y;
    short x;
    unsigned char c;
    unsigned char cnt;

    *(short *)(p1 + 0x38d) = 0;
    for (y = 0; y < p5; y++) {
        for (x = 0; x < p4; ) {
            c = *((signed char *)p2);
            cnt = 1;
            do {
                if (((signed char *)p2)[cnt] != c) break;
                if (cnt >= 0x3f) break;
                if (x + cnt >= p4) break;
                cnt++;
            } while (1);
            if (cnt > 1 || c >= 0xc0) {
                if (p3) {
                    char zz = cnt + 0xc0; /* haelt die Registerzuteilung wie im Original */
                    PUT(p1, (int)(p1 + 0x38f), zz);
                    PUT(p1, (int)(p1 + 0x38f), c);
                }
                p2 += cnt;
                n += 2;
                x += cnt;
            } else {
                if (p3) {
                    char v = *((signed char *)p2);
                    PUT(p1, (int)(p1 + 0x38f), v);
                }
                p2++;
                n++;
                x++;
            }
        }
        if (p4 != *(short *)(p1 + 0x42) && p4 != *(short *)(p1 + 0x42) - 1) {
            f_1664d0(d_1b958a, d_1a9c04, 0x243);
        }
        if (p4 < *(short *)(p1 + 0x42)) {
            PUT(p1, (int)(p1 + 0x38f), 0);
        }
    }
    if (p3) {
        ((VF3)VC(p1, 0x24))(OBJ(p1), p1 + 0x38f, (int)*(short *)(p1 + 0x38d));
    }
    return n;
}
//@ f_15d480
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt ein einzelnes Byte p2 in den 100-Byte-Ausgabepuffer (p1 + 0x38F) des PCX-Objekts
 *   und leert den Puffer über das Stream-Gerät in die Datei, sobald 100 Bytes erreicht sind.
 * - Eingaben: PCX-Objekt p1 und Ausgabebyte p2.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - *(short *)(p1 + 0x38d): Aktueller Füllstand des 100-Byte-Schreibpuffers.
 === Ende Beschreibung === */
void f_15d480(int p1, int p2)
{
    *(char *)(*(short *)(p1 + 0x38d) + p1 + 0x38f) = (char)p2;
    if (++(*(short *)(p1 + 0x38d)) == 100) {
        ((VF3)VC(p1, 0x24))(OBJ(p1), p1 + 0x38f, 100);
        *(short *)(p1 + 0x38d) = 0;
    }
}
//@ f_15d4d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Elementindex des im Hypertext-Dokument aktiv hervorgehobenen Hyperlinks
 *   (d_1cdf98) auf p1.
 * - Eingaben: Elementindex p1 des Links im Layoutvektor.
 * - Rückgabewert: int - gibt immer 1 zurück.
 * - Wichtige Variablen:
 *   - d_1cdf98: Globaler Index des aktuell ausgewählten Hyperlinks (-1 = keiner).
 === Ende Beschreibung === */
int f_15d4d0(int p1)
{
    d_1cdf98 = p1;
    return 1;
}
//@ f_15d4dc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hebt jede Hyperlink-Hervorhebung im aktuellen Dokument auf, indem d_1cdf98 auf -1 gesetzt
 *   wird.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cdf98: Wird auf -1 zurückgesetzt.
 === Ende Beschreibung === */
void f_15d4dc(void)
{
    d_1cdf98 = -1;
}
//@ f_15d4e8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht den Layoutvektor v ab dem globalen Suchindex d_1cdf9c nach dem nächsten
 *   Hyperlink-Startelement (Typ 5) und gibt dessen Index zurück, während d_1cdf9c für den Folgeaufruf um 1
 *   weitergerückt wird.
 * - Eingaben: Zeiger v auf den Layoutelement-Vektor.
 * - Rückgabewert: unsigned - Index des gefundenen Link-Startelements oder 0xFFFFFFFF (-1), wenn kein weiterer
 *   Link folgt.
 * - Wichtige Variablen:
 *   - d_1cdf9c: Statischer Suchzeiger für die schrittweise Iteration über alle Links eines Dokuments.
 === Ende Beschreibung === */
struct E32b { int w[8]; };
#pragma inline_depth(3)
inline struct E32b at15d4(Vec *v, int i) { int address = v->base; address += i * 32; return *(struct E32b *)address; }
inline int cnt15d4(Vec *v) { return (v->f8 - v->f4) / 32; }
unsigned f_15d4e8(Vec *v)
{
    struct E32b b;
    int saved_index = d_1cdf9c;
    d_1cdf9c = saved_index; // haelt die Registerzuteilung wie im Original
    while (d_1cdf9c < cnt15d4(v)) {
        b = at15d4(v, d_1cdf9c);
        if (b.w[0] == 5) break;
        d_1cdf9c++;
    }
    if (d_1cdf9c >= cnt15d4(v)) return 0xffffffff;
    return d_1cdf9c++;
}
#pragma inline_depth(0)

int f_15d574(Vec *v)
{
    d_1cdf9c = 0;
    return f_15d4e8(v);
}
//@ f_15d584
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht im globalen Dokumentvektor d_1cddbc ab der aktuellen Suchposition d_1cdf9c den
 *   nächsten anklickbaren Hyperlink (mit href != 0), dessen sämtliche zugehörigen Text- und Bildelemente (bis
 *   zum Link-Ende Typ 6) vollständig innerhalb des sichtbaren Fensterrechtecks r liegen (z. B. für
 *   Tastaturnavigation zwischen sichtbaren Links).
 * - Eingaben: Zeiger r auf ein 4-Int-Sichtrechteck (links, oben, rechts, unten).
 * - Rückgabewert: int - Elementindex des nächsten vollständig sichtbaren Hyperlinks oder -1.
 * - Wichtige Variablen:
 *   - found: Index des aktuell geprüften Link-Startelements (Typ 5).
 *   - active: Flag (1), das auf 0 fällt, falls der Link kein Sprungziel hat (pointCopy.a == 0) oder eines seiner
 *     Elemente außerhalb von r ragt.
 === Ende Beschreibung === */
int f_15d584(int *r)
{
    Vec *list;
    Vec *cur;
    int found;
    int index;
    int active;
    int offset;
    int pointIndex;
    int pointBase;
    unsigned end;
    struct {R32 second,secondCopy,first,firstCopy;} copies;
    Pt pointCopy;
    Pt point;
    R32 *record;

    list = d_1cddbc;
    found = f_15d4e8(list);
    if (found == -1) return found;
    do {
        active = 1;
        index = found;
        pointIndex = found;
        cur = d_1cddbc;
        end=found*32;{int base=cur->base;end+=base;}
        if (end >= (unsigned)cur->f8) {
            cur->f8 = end + 32;
            f_15c170(cur);
        }
        pointBase = cur->base;
        pointIndex <<= 5;
        point = *(Pt *)(pointIndex + pointBase + 16);
        pointCopy = point;
        if (pointCopy.a == 0) active = 0;
        offset = index * 32;
        while (index < (list->f8 - list->f4) / 32) {
            copies.first = *(R32 *)(list->base + offset);
            copies.firstCopy = copies.first;
            if (copies.firstCopy.t != 6) goto process1334;
            break;
        process1334:
            copies.second = *(R32 *)(list->base + offset);
            copies.secondCopy = copies.second;
            record = &copies.secondCopy;
            int right, bottom;
            int kind = 0;
            kind = record->t;
            if (kind == 1 || kind == 4 || kind == 5) {
                if (record->p.a < r[0]) goto reject1038;
                right = *(int *)((char *)record + 10) >> 16;
                right += record->p.a;
                if (right >= r[2]) goto reject1038;
                if (record->p.b < r[1]) goto reject1038;
                bottom = *(int *)((char *)record + 12) >> 16;
                bottom += record->p.b;
                if (bottom < r[3]) goto next1038;
            reject1038:
                active = 0;
            }
        next1038:
            ++index;
            offset += 32;
        }
        if (active) return found;
        found = f_15d4e8(list);
    } while (found != -1);
    return found;
}

//@ f_15d744
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Suchindex d_1cdf9c auf 0 zurück und sucht über f_15d584(r) den ersten im
 *   Rechteck r vollständig sichtbaren, anklickbaren Hyperlink.
 * - Eingaben: Zeiger r auf das 4-Int-Sichtrechteck.
 * - Rückgabewert: int - Elementindex des ersten sichtbaren Links oder -1.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_15d744(int *r)
{
    d_1cdf9c = 0;
    return f_15d584(r);
}
//@ f_15d754
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft für einen Mausklick an der Dokumentkoordinate (r[0], r[1]), ob diese Position (mit 4
 *   Pixeln horizontaler Toleranz) ein Text- oder Bildelement (Typ 1 oder 4) eines aktiven Hyperlinks (href != 0)
 *   im globalen Layoutvektor d_1cddbc trifft, und gibt den Index des getroffenen Link-Startelements zurück.
 * - Eingaben: Zeiger r auf die 2D-Punktkoordinate (x, y) im Dokumentenraum.
 * - Rückgabewert: int - Elementindex des angeklickten Hyperlinks oder -1 bei keinem Treffer.
 * - Wichtige Variablen:
 *   - found: Index des Link-Startelements (Typ 5), dessen Inhalt bis zum nächsten Link-Endelement (Typ 6) auf
 *     Treffer geprüft wird.
 === Ende Beschreibung === */
int f_15d754(int *r)
{
    Vec *list;
    Vec *cur;
    int found;
    int index;
    int active;
    int offset;
    int pointIndex;
    int pointBase;
    unsigned end;
    struct {R32 firstCopy,first,secondCopy,second;} copies;
    Pt point;
    Pt pointCopy;
    R32 *record;

    list = d_1cddbc;
    d_1cdf9c = 0;
    found = f_15d4e8(list);
    if (found == -1) return found;
    do {
        active = 1;
        index = found;
        pointIndex = found;
        cur = d_1cddbc;
        end=found*32;{int base=cur->base;end+=base;}
        if (end >= (unsigned)cur->f8) {
            cur->f8 = end + 32;
            f_15c170(cur);
        }
        pointBase = cur->base;
        pointIndex <<= 5;
        point = *(Pt *)(pointIndex + pointBase + 16);
        pointCopy = point;
        if (pointCopy.a == 0) active = 0;
        offset = index * 32;
        while (index < (list->f8 - list->f4) / 32) {
            copies.first = *(R32 *)(list->base + offset);
            copies.firstCopy = copies.first;
            if (copies.firstCopy.t == 6) break;
            copies.second = *(R32 *)(list->base + offset);
            copies.secondCopy = copies.second;
            record = &copies.secondCopy;
            if (active && (copies.secondCopy.t == 1 || copies.secondCopy.t == 4) &&
                record->p.a - 4 <= r[0] &&
                record->p.a + (*(int *)((char *)record + 10) >> 16) + 4 >= r[0] &&
                record->p.b <= r[1] &&
                record->p.b + (*(int *)((char *)record + 12) >> 16) >= r[1])
                return found;
            ++index;
            offset += 32;
        }
        found = f_15d4e8(list);
    } while (found != -1);
    return found;
}
//@ f_15d90c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet das umschließende Rechteck (left, top, right, bottom) aller Text- und
 *   Bildelemente (Typ 1 und 4), die zu dem bei Index p2 beginnenden Hyperlink gehören (bis zum abschließenden
 *   Typ-6-Element).
 * - Eingaben: Startindex p2 des Hyperlinks im Vektor d_1cddbc.
 * - Rückgabewert: Rectangle670 - Struktur mit den vier Grenzen (left, top, right, bottom) des Links.
 * - Wichtige Variablen:
 *   - frame: Sammelstruktur mit den laufend aktualisierten Minimal- und Maximalkoordinaten.
 === Ende Beschreibung === */
#pragma inline_depth(3)
struct Rectangle670 {int left,top,right,bottom;Rectangle670(const int &l,const int &t,const int &r,const int &b):left(l),top(t),right(r),bottom(b){}};
struct BoundsFrame670 {R32 c,d,a,b;int left,top,right,bottom;};
Rectangle670 f_15d90c(int p2)
{
BoundsFrame670 frame;Vec*list=d_1cddbc;
    int index;int offset;
    frame.left = 0xffff;
    frame.top = 0xffff;
    frame.right = 0xffff0001;
    frame.bottom = 0xffff0001;
    index = p2;
    offset = p2;
    offset <<= 5;
    while ((list->f8 - list->f4) / 32 > index) {
        frame.a = *(R32 *)(list->base + offset);
        frame.b = frame.a;
        if (frame.b.t == 6) break;
        frame.c = *(R32 *)(list->base + offset);
        frame.d = frame.c;
        R32*item=&frame.d;int kind=item->t;
        if(kind==1||kind==4) {
            if (item->p.a < frame.left) frame.left = item->p.a;
            if (frame.right < item->p.a + (*(int *)((char *)item+10)>>16)) frame.right = item->p.a + (*(int *)((char *)item+10)>>16);
            if (item->p.b < frame.top) frame.top = item->p.b;
            if (frame.bottom < item->p.b + (*(int *)((char *)item+12)>>16)) frame.bottom = item->p.b + (*(int *)((char *)item+12)>>16);
        }
        index++;
        offset += 0x20;
    }

    return Rectangle670(frame.left,frame.top,frame.right,frame.bottom);
}
//@ f_15da8c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest aus dem Hyperlink-Element an Index p1 im Vektor d_1cddbc das an Offset +0x10
 *   gespeicherte Zeigerpaar (href, name) aus und gibt es als 8-Byte-Struktur Pt zurück.
 * - Eingaben: Elementindex p1 im Layoutvektor d_1cddbc.
 * - Rückgabewert: Pt - Paar aus Sprungziel-Zeiger (a = href) und Ankernamen-Zeiger (b = name).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
Pt f_15da8c(int p1)
{
    Vec *v = d_1cddbc;
    int n = p1;
    int b;
    unsigned u;

    b = v->base;
    u = b + (n << 5);
    if ((unsigned)u >= *(unsigned *)((char *)v + 8)) {
        u += 0x20;
        v->f8 = u;
        if ((unsigned)v->f12 <= u) f_15c1a0(v);
    }
    return *(Pt *)((n << 5) + (v->base + 0x10));
}
//@ f_15dadc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die (x, y)-Dokumentkoordinate (Felder +0x04 und +0x08) des Layoutelements an Index p2
 *   im globalen Vektor d_1cddbc zurück (z. B. um zu einem benannten Anker zu scrollen).
 * - Eingaben: Elementindex p2 im Layoutvektor.
 * - Rückgabewert: PointResult670 - Struktur mit der X- und Y-Position des Elements.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
struct PointResult670 {int a,b;PointResult670(int x,int y):a(x),b(y){}};
struct Elem670 { int f0, f4, f8, fc, f10, f14, f18, f1c; };
struct Feld670 {
    Elem670 *d; Elem670 *b; Elem670 *e; Elem670 *c;
    Elem670 &at(int i) { Elem670 *p = d + i; if (p >= e) { e = p + 1; if (e >= c) f_15c1a0((Vec *)this); } return d[i]; }
};
PointResult670 f_15dadc(int p2)
{
    return PointResult670(((Feld670 *)d_1cddbc)->at(p2).f4, ((Feld670 *)d_1cddbc)->at(p2).f8);
}