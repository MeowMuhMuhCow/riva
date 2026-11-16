/* === Beschreibung (Katalog) ===
 * Einheit mask (Adresse 0x0bbaf0 - 0x0bd2e0)
 *
 * Diese Einheit stammt aus der Originaldatei p:\riva\source\cpp\mask.cpp und verwaltet die grafische
 * Haupt-Benutzeroberfläche (Spielmaske) von *Schatten über Riva*. Sie lädt den Bildschirmrahmen um das
 * 3D-/2D-Sichtfenster, zeichnet die untere Leiste mit den bis zu sieben Heldenporträts, Lebens- und
 * Astralenergiebalken sowie abgekürzten Heldennamen, gibt einzeilige Statusmeldungen aus und führt weiche
 * Bildüberblendungen innerhalb des Sichtfensters durch.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 9/17 gleich (suche.py 26.10.2026, Basis mask_P1.CPP)
// mask.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BBAF0-0x0BD2E0
#include <string.h>
extern const char d_1a5380[];
int f_01ced0(int p1, int p2, int p3);
int f_01cef0(int p1);
int f_039040(int p1);


int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_050580(int p1, int p2, int p3, int p4, int p5);
int f_05dec0(int p1);
int f_05ded0(int p1, int p2);
int f_05e1d0(int p1, int p2, int p3);
int f_05e200(int p1);
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);
int f_05e320(int p1, int p2, int p3);
int f_05e340(int p1);
int f_05e440(int p1, int p2);
int f_060a80(int p1);
int f_09a0d0(int p1);
int f_09a120(int p1, int p2);
int f_09a140(int p1, int p2);
int f_09a4c0(int p1, int p2);



int f_0dc650(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
short f_0de7f0(int p1);
short f_0de800(int p1);
short f_0de820(int p1);
int f_0e9550(int p1, int p2);
int f_0e9660(int p1, int p2, int p3, int p4);
short f_0e9670(int p1, int p2, int p3, int p4);









int f_126840(int p1, int p2);
char *f_147c84(char *p1, int p2, char *p3);
int f_1459b0(int p1);
int f_1459d0(int p1, int p2);
int f_145a40(int p1, int p2, int p3);
int f_145b40(int p1);
extern int d_1a34e0;
extern short d_1a5544[];
extern int d_1bc760;
extern char *d_1bf510;
extern int d_1bf514;
extern short d_1bfb1c;
extern int d_1c0004;
extern int d_1c0c94;
extern char d_1c0e60[];
extern volatile signed char d_1c219a;
extern int d_1c2a80;
extern char d_1bf234[];
extern char d_1baac0[], d_1bfdbc[], d_1c21b4[], d_1c2a58[], d_1c2a64[], d_1c2be0[], d_1c2c44[], d_1c3068[], d_1c38b0[], d_1b8224[], d_1a539c[], d_1a54c0[];
void f_0bbaf0(int p1);
void f_0bbd50(int p1, int p2, int p3);
void f_0bbe10(int p1, char *p2, signed char *p3);
void f_0bbe40(int p1, int p2);
void f_0bbf00(int p1);
void f_0bd170(int p1, int p2, int p3);
void f_0bd210(int p1, int p2);

#define NEWO(o, sz, ln, ctor) { int n_ = (int)operator new(sz, mark(d_1a5380, ln)); o = n_; if (n_) o = ctor; }
static inline int NEF(int a, int b) { return a != b; }
static inline int MKF() { int r = 1; if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && d_1bfb1c == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) r = 0; return r; }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0bbaf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Spielmaske je nach aktuellem Spielmodus ein oder aus: Ist die
 *   Standardmaske aktiv (0x40000 oder 0x40001), lädt sie die zugehörige Rahmen-Grafik und Farbpalette (f_145a40)
 *   in den oberen Palettenbereich (+0x1e0, 96 Farben) und blendet das Bild ein; im Vollbildmodus blendet sie den
 *   Bildschirm stattdessen aus (f_09a0d0) und setzt die Maskenkennung d_1c2a80 auf 0.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 des Masken-Managers entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bbaf0(int p1)
{
    short s = f_0de800(d_1c0004);
    f_0de820(d_1c0004);
    if (s != -1) f_09a140(0, 0x19);
    RivaMouseGuard mg;
    int r = 0;
    if (f_0de800(d_1c0004) != -1 || f_060a80(f_0de820(d_1c0004))) r = 1;
    d_1c2a80 = (r != 1) + 0x40000;
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        char *p = (char *)operator new[](0x300, mark(d_1a5380, 0xf3));
        p = f_147c84(p, 0x100, d_1baac0);
        p = p ? p : 0;
        memset(p, 0, 0x300);
        {
            int q2 = d_1a34e0;
            int q3 = (int)p;
            int oo;
            int n_ = (int)operator new(0xa3, mark(d_1a5380, 0x125));
            if (n_) oo = f_1459b0(n_); else oo = n_;
            int rr = 0;
            if (f_0de800(d_1c0004) != -1 || f_060a80(f_0de820(d_1c0004))) rr = 1;
            d_1c2a80 = (rr != 1) + 0x40000;
            f_145a40(oo, d_1c2a80, q2);
            if (q3) memcpy((char *)q3 + 0x1e0, (char *)f_145b40(oo) + 0x1e0, 0x120);
            if (oo) operator delete((void *)f_1459d0(oo, 0));
        }
        if (s != -1) f_09a120((int)p, 0x19);
        operator delete(p);
        *(char * volatile *)&d_1bf510 = d_1a539c;
        if (d_1bc760) f_01ced0(d_1bc760, 0x10, 2);
    } else {
        f_09a0d0(d_1a34e0);
        d_1c2a80 = ok;
        // haelt die Registerzuteilung wie im Original
        *(unsigned*)&d_1c2a80=0u;
        d_1bf510 = d_1a54c0;
    }
    // haelt die Registerzuteilung wie im Original
    d_1bf514=0;
    *(unsigned*)&d_1bf514=0; d_1bf514=0;
    *(unsigned*)&d_1bf514=0; d_1bf514=0;
    *(unsigned*)&d_1bf514=0; d_1bf514=0;
}
//@ f_0bbd50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion lädt das Hauptmasken-Hintergrundbild (0x40000 oder 0x40001) über ein temporäres
 *   Bildlader-Objekt (f_1459b0/f_145a40) in den Ziel-Bildschirmpuffer p2 und kopiert bei übergebenem
 *   Palettenzeiger p3 die oberen 96 Farbeinträge (0x120 Bytes ab Offset 0x1e0).
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1, den Ziel-Bildschirmpuffer p2 sowie einen optionalen
 *   Palettenpuffer-Zeiger p3 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bbd50(int p1, int p2, int p3)
{
    int n_ = (int)operator new(0xa3, mark(d_1a5380, 0x125));
    int o = n_ ? f_1459b0(n_) : n_;
    int r = 0;
    if (f_0de800(d_1c0004) != -1 || f_060a80(f_0de820(d_1c0004))) r = 1;
    d_1c2a80 = (r != 1) + 0x40000;
    f_145a40(o, d_1c2a80, p2);
    if (p3) memcpy((char *)p3 + 0x1e0, (char *)f_145b40(o) + 0x1e0, 0x120);
    if (o) operator delete((void *)f_1459d0(o, 0));
}
//@ f_0bbe10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion kopiert den Vornamen eines Helden (maximal 7 Zeichen bis zum ersten Leerzeichen '
 *   ') aus dem Quellstring p3 in den Zielpuffer p2 und schließt ihn mit einem Nullbyte ab, damit der Name unter
 *   das kleine Heldenporträt in der Statusleiste passt.
 * - Eingaben: Die Funktion nimmt den ungenutzten this-Zeiger p1, den Zielpuffer p2 sowie den vollständigen
 *   Heldennamen p3 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bbe10(int p1, char *p2, signed char *p3)
{
    short i;
    for (i = 0; i < 7; i++, *p2++ = *p3++) {
        if (*p3 == ' ') { *p2 = 0; break; }
    }
    *p2 = 0;
}
inline void riva_0bbe10_alt(int p1, char *p2, signed char *p3)
{
    for (short i = 0; i < 7 && *p3 != ' '; i++) {
        *p2++ = *p3++;
    }
    *p2 = 0;
}

//@ f_0bbe40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt das Hintergrund-Teilbild für einen einzelnen Heldenplatz aus der Ressource
 *   0x40004 (Teilbild 0) und kopiert es für alle sieben möglichen Gruppenplätze an die horizontalen
 *   X-Koordinaten aus der Tabelle d_1a5544 (3, 46, 89, 132, 175, 218, 261) in den Streifenpuffer p2.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 sowie den Ziel-Bitmap-Puffer p2 für die Porträtleiste
 *   entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bbe40(int p1, int p2)
{
    short a = 0, b = 0;
    int typ = 0x40004;
    f_050580((int)d_1c2be0, typ, 0, (int)&a, (int)&b);
    int n = (int)operator new(9, mark(d_1a5380, 0x173));
    int o = n ? ((int)(((RivaRasterImage*)(n))->f_0fac80( (short)a, (short)b))) : n;
    f_04fef0((int)d_1c2be0, typ, ((int)(((RivaRasterImage*)(o))->f_0fb0b0())), 0, 0, 0, 0x140);
    short i;
    for (i = 0; i <= 6; i++) ((RivaRasterImage*)(o))->f_0fade0((void *)( ((int)(((RivaRasterImage*)(p2))->f_0fb0b0()))), (short)(d_1a5544[i] - 1), 0);
    if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
}
//@ f_0bbf00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet die komplette Porträtleiste am unteren Bildschirmrand (ab Y-Koordinate 0x9c =
 *   156, Höhe 0x2c = 44 Pixel) neu, indem sie zunächst die leeren Sockel (f_0bbe40) aufbaut und anschließend
 *   über f_0dc650 die Porträts und Energiebalken aller aktiven Gruppenmitglieder in den Puffer rendert.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bbf00(int p1)
{
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        int n_ = (int)operator new(9, mark(d_1a5380, 0x195));
        int o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac80( 0x140, 0x2c))) : n_;
        RivaMouseGuard mg;
        *(short *)&d_1c219a = 0;
        ((RivaRasterImage*)(o))->f_0fafb0((void *)( d_1a34e0), 0, 0x9c);
        f_0bbe40(p1, o);
        int q = (int)d_1bfdbc;
        short s = f_0dc650(d_1c0004, 0, o);
        register short i;
        for (i = 0; i < 6; i++, q += 0x61) {
            if (q != d_1c0004 && f_0de7f0(q)) s = f_0dc650(q, s, o);
        }
        ((RivaRasterImage*)(o))->f_0fade0((void *)( d_1a34e0), 0, 0x9c);
        if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    }
}
//@ f_0bc060
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion baut die gesamte Spielmaske auf dem Bildschirm auf: Falls sie noch nicht geladen ist,
 *   ruft sie f_0bbaf0 auf, aktualisiert die Uhrzeit-/Kompassanzeige (f_126840), löscht die Status-Textzeile bei
 *   Y-Koordinate 0x8e (142) und zeichnet die Heldenporträtleiste (f_0bbf00) sowie die Heldennamen.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc060(int p1)
{
    if (d_1bc760) f_01cef0(d_1bc760);
    if (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001) f_0bbaf0(p1);
    signed char fl1;
    int ok1 = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl1 = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok1 = 0;
    if (ok1) {
        d_1c0c94 = 1;
        f_126840((int)d_1c2c44, 1);
        int t = d_1a34e0;
        signed char fl2;
        int ok2 = 1;
        if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl2 = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok2 = 0;
        if (ok2) {
            int o[3];
            ((int)(((RivaRasterImage*)((int)o))->f_0fac80( 0x133, 8)));
            short c = (f_0de820(d_1c0004) > 0) ? 0xcd : 0xcd;
            ((RivaRasterImage*)((int)o))->f_0fb150( c);
            {
                RivaMouseGuard mg;
                ((RivaRasterImage*)((int)o))->f_0fade0((void *)( t), 5, 0x8e);
            }
            ((int)(((RivaRasterImage*)((int)o))->f_0fad20( 0)));
        }
        f_0bbf00(p1);
    }
}
//@ f_0bc1e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löscht das einzeilige Status-Textfeld zwischen Sichtfenster und Porträtleiste (ab
 *   Koordinate X = 5, Y = 0x8e, Breite 0x133 = 307, Höhe 8 Pixel), indem sie ein einfarbiges Rechteck mit dem
 *   Farbwert 0xcd in den Zielpuffer p2 zeichnet.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 sowie den Ziel-Bildschirmpuffer p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc1e0(int p1, int p2)
{
    int ok = 1;
    signed char fl;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        int o[3];
        ((int)(((RivaRasterImage*)((int)o))->f_0fac80( 0x133, 8)));
        short c = (int)f_0de820(d_1c0004) ? 0xcd : 0xcd;
        ((RivaRasterImage*)((int)o))->f_0fb150( c);
        {
            RivaMouseGuard mg;
            ((RivaRasterImage*)((int)o))->f_0fade0((void *)( p2), 5, 0x8e);
        }
        ((int)(((RivaRasterImage*)((int)o))->f_0fad20( 0)));
    }
}
//@ f_0bc2c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schwärzt bzw. leert das 3D-/2D-Sichtfenster (X = 16, Y = 2, Größe 0xd0 x 0x87 = 208 x
 *   135 Pixel) innerhalb der aktiven Spielmaske oder blendet im Vollbildmodus den gesamten Bildschirm aus
 *   (f_09a0d0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc2c0(void)
{
    signed char flag;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (flag = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        RivaMouseGuard mg;
        int o[3];
        ((int)(((RivaRasterImage*)((int)o))->f_0fac80( 0xd0, 0x87)));
        ((RivaRasterImage*)((int)o))->f_0fb120();
        ((RivaRasterImage*)((int)o))->f_0fae30((void *)( d_1a34e0), 0x10, 2, 2);
        ((int)(((RivaRasterImage*)((int)o))->f_0fad20( 0)));
    } else {
        f_09a0d0(d_1a34e0);
    }
}
//@ f_0bc3a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet die Namensschilder unter allen sieben Plätzen der Heldenporträtleiste (ab
 *   Y-Koordinate 0xbd = 189) neu, kürzt die Namen der anwesenden Helden und NPC-Begleiter auf maximal 7 Zeichen
 *   bis zum ersten Leerzeichen und gibt sie zentriert in der jeweiligen Statusfarbe (0xfc bei aktivem Flag in
 *   d_1c0e60, sonst 0xd8) aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc3a0(void)
{
    int c42;
    short x, y, n, i, j, k;
    int o1, o0, sv;
    signed char fl;
    int ok = 1;
    char *src, *dst;
    int p;
    short r;

    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        short *pn = &n; // haelt die Variable im Stapel wie im Original
        int typ = 0x40004;
        n = f_0de7f0(d_1c0004);
        x = 0;
        y = 0;
        sv = f_05dec0((int)d_1c3068);
        RivaMouseGuard mg;
        f_050580((int)d_1c2be0, typ, 1, (int)&x, (int)&y);
        {
            int n0 = (int)operator new(9, mark(d_1a5380, 0x212));
            o0 = n0 ? ((int)(((RivaRasterImage*)(n0))->f_0fac80( (short)x, (short)y))) : n0;
        }
        f_04fef0((int)d_1c2be0, typ, ((int)(((RivaRasterImage*)(o0))->f_0fb0b0())), 0, 1, 0, 0x140);
        {
            int n1 = (int)operator new(9, mark(d_1a5380, 0x222));
            o1 = n1 ? ((int)(((RivaRasterImage*)(n1))->f_0fac80( 0x140, (short)y))) : n1;
        }
        f_05ded0((int)d_1c3068, ((int)(((RivaRasterImage*)(o1))->f_0fb0b0())));
        for (i = 0; i < 7; i++)
            ((RivaRasterImage*)(o0))->f_0fae30((void *)( ((int)(((RivaRasterImage*)(o1))->f_0fb0b0()))), (short)(d_1a5544[i] - 1), 0, 1);
        f_04fef0((int)d_1c2be0, typ, ((int)(((RivaRasterImage*)(o0))->f_0fb0b0())), 0, 3, 0, 0x140);
        for (i = 0; i < n; i++) {
            p = f_0de7d0(d_1c0004, i);
            c42 = f_042400((struct hero *)(p));
            j = i;
            if (c42) j = 6;
            if (p == 0) continue;
            if (((int *)d_1c0e60)[j] != 0)
                ((RivaRasterImage*)(o0))->f_0fae30((void *)( ((int)(((RivaRasterImage*)(o1))->f_0fb0b0()))), (short)(d_1a5544[j] - 1), 0, 1);
            src = (char *)((int)(f_0422b0((struct hero *)(p))));
            dst = d_1c21b4;
            k = 0;
            goto copy_test;
        copy_loop:
            ++k;
            ++dst;
            { char c = *src++; *(dst - 1) = c; }
        copy_test:
            if (k < 7 && ((signed char)*src != ' ' || (*dst = 0, 0)))
                goto copy_loop;
            *dst = 0;
            f_05e320((int)d_1c38b0, (short)(((int *)d_1c0e60)[j] ? 0xfc : 0xd8), -1);
            r = f_0e9670((int)d_1c38b0, (int)d_1c21b4, d_1a5544[j], 0x2b);
            f_0e9660((int)d_1c38b0, (int)d_1c21b4, r, 1);
            f_05e340((int)d_1c38b0);
        }
        ((RivaRasterImage*)(o1))->f_0fae30((void *)( d_1a34e0), 0, 0xbd, 1);
        f_05ded0((int)d_1c3068, sv);
        if (o1) operator delete((void *)((int)(((RivaRasterImage*)(o1))->f_0fad20( 0))));
        if (o0) operator delete((void *)((int)(((RivaRasterImage*)(o0))->f_0fad20( 0))));
    }
}


//@ f_0bc6c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion hebt das Namensschild eines einzelnen Helden oder des NPC-Begleiters (Platz p2 == 6)
 *   am unteren Bildschirmrand mit dem speziellen Rahmen-Teilbild 4 aus Ressource 0x40004 und der Textfarbe p3
 *   hervor.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1, den Gruppenplatz-Index p2 (0 bis 6) sowie die gewünschte
 *   Schriftfarbe p3 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc6c0(int p1, short p2, short p3)
{
    short width, height;
    int ok = 1;
    signed char flag;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 &&
         (flag = (signed char)d_1bfb1c) == 1) ||
        (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001))
        ok = 0;
    if (ok) {
        int type = 0x40004;
        width = 0;
        height = 0;
        RivaMouseGuard guard;
        if ((short)p2 == 6) {
            char *src = (char *)((int)(f_0422b0((struct hero *)(f_039040(d_1c0004)))));
            char *dst = d_1c21b4;
            short i = 0;
            goto name_test_6;
        name_copy_6:
            ++i;
            ++dst;
            { char c = *src++; *(dst - 1) = c; }
        name_test_6:
            if (i < 7 && ((signed char)*src != ' ' || (*dst = 0, 0)))
                goto name_copy_6;
            *dst = 0;
        } else {
            char *src = (char *)((int)(f_0422b0((struct hero *)(f_0de7d0(d_1c0004, (short)p2)))));
            char *dst = d_1c21b4;
            short i = 0;
            goto name_test_other;
        name_copy_other:
            ++i;
            ++dst;
            { char c = *src++; *(dst - 1) = c; }
        name_test_other:
            if (i < 7 && ((signed char)*src != ' ' || (*dst = 0, 0)))
                goto name_copy_other;
            *dst = 0;
        }
        f_050580((int)d_1c2be0, type, 4, (int)&width, (int)&height);
        int raw = (int)operator new(9, mark(d_1a5380, 0x277));
        int object = raw ? ((int)(((RivaRasterImage*)(raw))->f_0fac80( (short)width, (short)height))) : raw;
        f_04fef0((int)d_1c2be0, type, ((int)(((RivaRasterImage*)(object))->f_0fb0b0())), 0, 4, 0, 0x140);
        int index = (short)p2;
        f_05e320((int)d_1c38b0, (short)p3, -1);
        ((RivaRasterImage*)(object))->f_0fae30((void *)( (p1 = d_1a34e0)), (short)(d_1a5544[index] - 1), 0xbd, 1);
        short result = f_0e9670((int)d_1c38b0, (int)d_1c21b4,
                                d_1a5544[index], 0x2b);
        f_0e9660((int)d_1c38b0, (int)d_1c21b4, result, 0xbe);
        f_05e340((int)d_1c38b0);
        if (object) operator delete((void *)((int)(((RivaRasterImage*)(object))->f_0fad20( 0))));
    }
}
//@ f_0bc8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt das Namensschild eines einzelnen Helden oder des NPC-Begleiters (Platz p2)
 *   wieder auf die normale Darstellung (Teilbild 1 aus Ressource 0x40004, Standard-Schriftfarbe 0xd8) zurück.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 sowie den Gruppenplatz-Index p2 (0 bis 6) entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bc8d0(int p1, short p2)
{
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        int type = 0x40004;
        short A = 0, B = 0;
        RivaMouseGuard mg;
        if ((short)p2 == 6) {
            char *src = (char *)((int)(f_0422b0((struct hero *)(f_039040(d_1c0004)))));
            char *dst = d_1c21b4;
            short i = 0;
            goto test1;
        loop1:
            { i++; dst++; char c = *src++; *(dst - 1) = c; }
        test1:
            if (i < 7 && ((signed char)*src != ' ' || (*dst = 0, 0))) goto loop1;
            *dst = 0;
        } else {
            char *src = (char *)((int)(f_0422b0((struct hero *)(f_0de7d0(d_1c0004, (short)p2)))));
            char *dst = d_1c21b4;
            short i = 0;
            goto test2;
        loop2:
            { i++; dst++; char c = *src++; *(dst - 1) = c; }
        test2:
            if (i < 7 && ((signed char)*src != ' ' || (*dst = 0, 0))) goto loop2;
            *dst = 0;
        }
        f_050580((int)d_1c2be0, type, 1, (int)&A, (int)&B);
        int n = (int)operator new(9, mark(d_1a5380, 0x2ac));
        int o = n ? ((int)(((RivaRasterImage*)(n))->f_0fac80( (short)A, (short)B))) : n;
        f_04fef0((int)d_1c2be0, type, ((int)(((RivaRasterImage*)(o))->f_0fb0b0())), 0, 1, 0, 0x140);
        f_05e320((int)d_1c38b0, 0xd8, -1);
        ((RivaRasterImage*)(o))->f_0fae30((void *)( d_1a34e0), (short)(d_1a5544[(short)p2] - 1), 0xbd, 1);
        short r = f_0e9670((int)d_1c38b0, (int)d_1c21b4, d_1a5544[(short)p2], 0x2b);
        f_0e9660((int)d_1c38b0, (int)d_1c21b4, r, 0xbe);
        f_05e340((int)d_1c38b0);
        if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    }
}
//@ f_0bcae0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine einzeilige Statusmeldung p2 in der Textzeile unterhalb des Sichtfensters (X
 *   = 6, Y = 0x8e, Breite 307 Pixel) in der Schriftfarbe p3 auf dem Zielpuffer p4 aus, nachdem sie den
 *   Textbereich zuvor mit der Hintergrundfarbe 0xcd gelöscht hat.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1, den Zeiger auf den Meldungstext p2, die Schriftfarbe p3
 *   sowie den Ziel-Bildschirmpuffer p4 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0e9650(int p1, int p2);
int f_05dec0(char *p1);
struct SOB {
    char b[12];
    SOB(short a, short c) { ((int)(((RivaRasterImage*)((int)this))->f_0fac80( a, c))); }
    ~SOB() { ((int)(((RivaRasterImage*)((int)this))->f_0fad20( 0))); }
};
static inline int MKS()
{
    int r = 1;
    signed char fl;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) r = 0;
    return r;
}
void f_0bcae0(int p1, int p2, short p3, int p4)
{
    short MaskGet680(int);
    // Conservative bound: original getter only writes AX; bounds below intentionally wider.
    #pragma aux MaskGet680 "f_0de800" modify exact [eax edx ebx ecx];
    int sv;
    short x18, a, b, d, c, x28, x34, x2c;
    if (MKS()) {
        sv = f_05dec0((int)d_1c3068);
        int s4;
        RivaMouseGuard g1;
        f_05ded0((int)d_1c3068, p4);
        short v = (f_0de820(d_1c0004) > 0) ? 0xcd : 0xcd;
        f_05e320((int)d_1c38b0, p3, v);
        f_05e2a0((int)d_1c38b0, (int)&a, (int)&b, (int)&c, (int)&d);
        f_05e2d0((int)d_1c38b0, 6, 0x133, 0x8e, -1);
        s4 = p4; // haelt die Stapelplatz-Reihenfolge wie im Original
        int ok2 = 1;
        signed char fl2;
        if ((f_0de820(d_1c0004) != -1 && MaskGet680(d_1c0004) == -1 && (fl2 = d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok2 = 0;
        ok2 = (ok2 & 0) ? 0 : ok2; // haelt die Registerzuteilung wie im Original
        if (ok2) {
            SOB o(0x133, 8);
            {
                short w = (f_0de820(d_1c0004) > 0) ? 0xcd : 0xcd;
                ((RivaRasterImage*)((int)&o))->f_0fb150( w);
            }
            RivaMouseGuard g2;
            ((RivaRasterImage*)((int)&o))->f_0fade0((void *)( s4), 5, 0x8e);
        }
        f_0e9550((int)d_1c38b0, p2);
        f_0e9650((int)d_1c38b0, (int)d_1b8224);
        f_05e2a0((int)d_1c38b0, (int)&x18, (int)&x34, (int)&x28, (int)&x2c);
        short r = f_05e200((int)d_1c38b0);
        f_05e1d0((int)d_1c38b0, (short)x18, (short)r);
        f_05e340((int)d_1c38b0);
        f_05e2d0((int)d_1c38b0, (short)a, (short)b, (short)c, (short)d);
        f_05ded0((int)d_1c3068, sv);
    }
}
//@ f_0bcd30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet auf dem Heldenporträt am Gruppenplatz p2 ein Treffer- oder
 *   Aktions-Overlay-Symbol (d_1c2a58 bei p3 == 0, sonst d_1c2a64) bei Y-Koordinate 0x9d (157) ein und setzt den
 *   Anzeigedauer-Countdown d_1bf234[p2] auf 10 Ticks.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1, den Gruppenplatz-Index p2 (0 bis 6) sowie die
 *   Symbolvariante p3 (0 oder != 0) entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bcd30(int p1, int p2, short p3)
{
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (ok) {
        if (d_1c2a80 == 0x40000 || d_1c2a80 == 0x40001) {
            char *pp = (p3 == (short)0) ? d_1c2a58 : d_1c2a64;
            RivaMouseGuard mg;
            ((RivaRasterImage*)((int)pp))->f_0fae30((void *)( d_1a34e0), d_1a5544[(short)p2], 0x9d, 1);
            d_1bf234[(short)p2] = 10;
        }
    }
}
//@ f_0bce10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet ein neues Szenenbild aus dem Puffer p2 (208 x 135 Pixel) samt dem dekorativen
 *   Sichtfenster-Innenrahmen (0x40005) zunächst in eine temporäre 64.000-Byte-Bildschirmkopie und blendet diese
 *   dann weich über f_09a4c0 auf den sichtbaren VGA-Bildschirm über.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 sowie den Zeiger p2 auf die 208 x 135 Pixel große
 *   Szenengrafik entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bce10(int p1, int p2)
{
    // haelt die Stapelplatz-Reihenfolge wie im Original
    { int gv = d_1c2a80; d_1c2a80 = gv; }
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (!ok) return;
    char *p3 = (char *)operator new[](64000, mark(d_1a5380, 0x302));
    RivaMouseGuard mg;
    char *drawbuf = (char*)memcpy(p3, (void *)d_1a34e0, 64000);
    f_0bd170(p1, p2, (int)p3);
    int b = 0;
    int n_ = (int)operator new(9, mark(d_1a5380, 0x36a));
    int o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac80( 0xd0, 0x87))) : n_;
    int s;
    ok = 0;
    ok = o;
    s = f_0de800(d_1c0004);
    b = 0;
    if (s == -1) {
        s = f_0de820(d_1c0004);
        if (f_060a80((int)s) != 0) b = 1;
    } else {
        b = 1;
    }
    if (b == 1) f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(ok))->f_0fb0b0())), 0, b, 0, 0x140); else f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(ok))->f_0fb0b0())), 0, 0, 0, 0x140);
    ((RivaRasterImage*)(o))->f_0fae30((void *)( (int)drawbuf), 0x10, 2, 1);
    if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    f_09a4c0((int)p3, 1);
    operator delete(p3);
}
//@ f_0bcfc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt wie f_0bce10 eine weiche Überblendung des Sichtfensters (208 x 135 Pixel) über
 *   einen temporären 64.000-Byte-Bildschirmpuffer durch, verwendet dabei jedoch ein neu erzeugtes leeres
 *   Sichtfenster-Rechteck (p2 = 0 an f_0bd170) mit überlagertem Innenrahmen (0x40005).
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bcfc0(int p1)
{
    signed char fl;
    int ok = 1;
    if ((f_0de820(d_1c0004) != -1 && f_0de800(d_1c0004) == -1 && (fl = (signed char)d_1bfb1c) == 1) || (d_1c2a80 != 0x40000 && d_1c2a80 != 0x40001)) ok = 0;
    if (!ok) return;
    {
    char *p3 = (char *)operator new[](64000, mark(d_1a5380, 0x324));
    RivaMouseGuard mg;
    memcpy(p3, (void *)d_1a34e0, 64000);
    char *p4 = p3;
    f_0bd170(p1, 0, (int)p3);
    int b = 0;
    int n_ = (int)operator new(9, mark(d_1a5380, 0x36a));
    int o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac80( 0xd0, 0x87))) : n_;
    int s;
    ok = 0;
    ok = o;
    s = f_0de800(d_1c0004);
    b = 0;
    if (s == -1) {
        s = f_0de820(d_1c0004);
        if (f_060a80((int)s) != 0) b = 1;
    } else {
        b = 1;
    }
    if (b == 1) f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(ok))->f_0fb0b0())), 0, b, 0, 0x140); else f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(ok))->f_0fb0b0())), 0, 0, 0, 0x140);
    ((RivaRasterImage*)(o))->f_0fae30((void *)( (int)p4), 0x10, 2, 1);
    if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    f_09a4c0((int)p3, 1);
    operator delete(p3);
    }
}
//@ f_0bd170
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion kopiert einen 208 x 135 Pixel großen Bildausschnitt aus p2 (oder ein leeres
 *   Bitmap-Objekt, falls p2 == 0 ist) an die Sichtfenster-Position (X = 16, Y = 2) des Ziel-Bildschirmpuffers
 *   p3.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1, den Quell-Pixelpuffer p2 sowie den Ziel-Bildschirmpuffer
 *   p3 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd170(int p1, int p2, int p3)
{
    int o;
    if (p2) {
        int n_ = (int)operator new(9, mark(d_1a5380, 0x34b));
        o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac10( 0xd0, 0x87,(void *)( p2)))) : n_;
    } else {
        int n_ = (int)operator new(9, mark(d_1a5380, 0x34f));
        o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac80( 0xd0, 0x87))) : n_;
    }
    ((RivaRasterImage*)(o))->f_0fade0((void *)( p3), 0x10, 2);
    if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
}
//@ f_0bd210
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion lädt den ornamentalen Sichtfenster-Innenrahmen aus der Ressource 0x40005
 *   (Teilbild 1 in Innenräumen/Sondergebieten, sonst Teilbild 0) und legt ihn transparent (f_0fae30) über das
 *   Sichtfenster (X = 16, Y = 2) im Zielpuffer p2.
 * - Eingaben: Die Funktion nimmt den Masken-Manager p1 sowie den Ziel-Bildschirmpuffer p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd210(int p1, int p2)
{
    int b;
    int n_ = (int)operator new(9, mark(d_1a5380, 0x36a));
    int o = n_ ? ((int)(((RivaRasterImage*)(n_))->f_0fac80( 0xd0, 0x87))) : n_;
    int s;
    int q = 0;
    q = o;
    s = f_0de800(d_1c0004);
    b = 0;
    if (s == -1) {
        s = f_0de820(d_1c0004);
        if (f_060a80((int)s) != 0) b = 1;
    } else {
        b = 1;
    }
    if (b == 1) f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(q))->f_0fb0b0())), 0, b, 0, 0x140); else f_04fef0((int)d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(q))->f_0fb0b0())), 0, 0, 0, 0x140);
    ((RivaRasterImage*)(o))->f_0fae30((void *)( p2), 0x10, 2, 1);
    if (o) operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
}
