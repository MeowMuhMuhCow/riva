/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t5a (0x1524D0 - 0x1539E4)
 *
 * Überblick
 * Diese Einheit bildet den fünften Teil der 3D-Engine und verantwortet die Geometrie-Vorverarbeitung für das
 * Rendern einer 3D-Szene: die Transformation von Eckpunkten und Normalen in den Kameraraum (f_1524d0), die
 * 2D-Perspektivprojektion (f_152654), die Tiefensortierung und Verdeckungsreihenfolge sichtbarer 3D-Objekte
 * (f_152740, f_1528f8), das Aufbereiten von Lichtquellen und Fackel-Flackereffekten (f_152e64, f_153128) sowie
 * das Frustum- und Sektor-Culling aller Szenenobjekte (f_1535e8).
 === Ende Beschreibung === */
// P3 2/10 gleich (suche.py 30.10.2026, Basis fz_14dc28_t5a_P1.CPP)
// OPT -5r -oneatx -zp1 -s -fp5
// (MooMoo 05.11.2026: -5r statt Standard -4r, Groessen stimmen; f_152be4/f_1535e8 je +7 bewusst in Kauf, nachjustieren)
// CC wcc386
// fz_14dc28_t5 (Schatten ueber Riva) - Pass 1, Code 0x1524D0-0x153AC8
#include <string.h>
#include <stdlib.h>
#pragma aux f_16cf6a parm [eax edx ebx] modify exact [eax edx];
#pragma aux f_16cff5 parm [eax edx ebx] modify exact [eax edx];
int f_149470();                       // nicht in clobber.tsv
int f_149524(int p1);                                   // reg eax stapel 0
int f_149a88();                                         // reg - stapel 0
int f_149b9c(int p1, int p2);                           // reg eax edx stapel 0
int f_160320(int p1);                                   // reg eax stapel 0
int f_161328();                                         // reg - stapel 0
int f_161e84(int p1);                                   // reg eax stapel 0
int f_1629a8();                                         // reg - stapel 0
int f_162db8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_163050(int p1);                                   // reg eax stapel 0
int f_1630ac();                                         // reg - stapel 0
int f_163428(int p1, int p2);                           // reg eax edx stapel 0
int f_163484(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_163bf8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16b60c(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16b930(int p1);                                   // reg eax stapel 0
int f_16cbdc(int p1, int p2);                           // reg eax edx stapel 0
int f_16cc44(int p1, int p2);                           // reg eax edx stapel 0
int f_16ccac(int p1, int p2);                           // reg eax edx stapel 0
int f_16cd74(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_16cf6a(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16cff5(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16d295(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16d33f(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3b7(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3d0();                       // nicht in clobber.tsv
int f_16d4d8(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d7e7(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d8ad(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16e93c(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int __cdecl f_16ebd8(int, ...);                         // Stapelargumente, caller-clean
int f_16ecb4(int p1);                                   // reg eax stapel 0
int f_16ecba(int p1);                                   // reg eax stapel 0
int f_16f693(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16fb53(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_16fb72(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_1702b8(int p1);                                   // reg eax stapel 0
int f_171000(int p1, int p2);                           // reg eax edx stapel 0
int f_171994(int p1, int p2);                           // reg eax edx stapel 0
int f_172028(int p1, int p2);                           // reg eax edx stapel 0
int f_172148(int p1, int p2);                           // reg eax edx stapel 0
int f_172278();                                         // reg - stapel 0
int f_172628(int p1);                                   // reg eax stapel 0
int f_17464c(int p1);                                   // reg eax stapel 0
int f_1750b6();                       // nicht in clobber.tsv
int f_1750bc(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_176f10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1782e8(int p1);                                   // reg eax stapel 0
int f_152020(int p1);
int f_152310(int p1);
int f_16fc19(void);
char f_16d2c9(int p1);
unsigned char f_165de2(void);
#pragma aux f_16fc19 modify exact [eax edx ecx];
struct REC { int w[46]; };
struct V3 { int x; int y; int z; };
extern int d_1a9a00, d_1a99fc, d_1a9a04, d_1a9a3c, d_1a9a48, d_1a99e4, d_1a9a38, d_1a9a6c, d_1a9aa0, d_1a9aa4;
extern char d_1cdc2a;
extern char *d_1cd314, *d_1cd224, *d_1cd324, *d_1cd204, *d_1cd220, *d_1cd210;
extern unsigned char *d_1cdc14;
extern struct REC *d_1cd1b0;
extern struct REC d_1c6bc0;
extern int d_1c6bd4;
extern short d_1c6bca;
extern short d_1c6bcc;
extern char d_1a9935, d_1a9936, d_1a9937;
extern int d_1a9b08, d_1a9b54;
extern int d_1a9a0c;
extern short d_1cdc26, d_1cdc28;
extern char d_1c8ff8[], d_1c7168[], d_1c7230[];
extern short d_1a9a1c[];
extern unsigned d_1cdb3c;
extern int d_1a99f4, d_1cd308, d_1cd30c, d_1cd310, d_1a99b0, d_1a9978, d_1a9ab0;
extern unsigned short d_1a9b24;
extern char *d_1cd1e0, *d_1cd1e8;
extern char d_1a9b5c[];
extern char d_1cc788[];
extern char d_1c76f8[];
extern unsigned char d_1c76f9[];
extern char d_1c7734[];
extern int d_1a9b44, d_1a9b48, d_1a99ac, d_1a9adc, d_1a9a98;
extern short d_1a9a90;
extern int d_1c6c3c, d_1c6c40, d_1c6bd0, d_1c6be8, d_1c6bec, d_1c6bf0, d_1c6bf4, d_1c6bf8, d_1c6bfc;
extern short d_1c6bc4, d_1c6c00, d_1c6c02, d_1c6c04, d_1c6c06, d_1c6c08, d_1c6c0a, d_1c6c0e, d_1c6c12, d_1c6c14, d_1c6c16, d_1c6c18, d_1c6c1a, d_1c6c1c, d_1c6c1e, d_1c6c20;
extern int d_1c6c44;
#define I(p,o) (*(int *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define S16(p,o) (*(short *)((char *)(p) + (o)))
#define U8(p,o) (*(unsigned char *)((char *)(p) + (o)))
int FMUL(int a, int b);
#pragma aux FMUL = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify [edx] value [eax];
int MULDIV(int a, int b, int c);
#pragma aux MULDIV = "imul edx" "idiv ebx" parm [eax] [edx] [ebx] modify exact [eax edx] value [eax];
#define ABSX(x) ((((x) ^ ((x) >> 31)) - ((x) >> 31)))

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_1524d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Transformiert für ein sichtbares 3D-Objekt p sämtliche Modell-Eckpunkte (t + 0x38, Anzahl
 *   U16(t, 4)) über f_16cf6a und sämtliche Flächen-/Vertexnormalen (t + 0x3c, Anzahl U16(t, 6)) über f_16cff5
 *   mit der Objekt-Kameramatrix (p + 0x84) in die globalen Transformationspuffer d_1cd314 und d_1cd324 und setzt
 *   das Statusbit 0x10 in U8(p, 0x10). Reicht die Pufferkapazität (d_1a9a3c bzw. d_1a9a48) nicht aus, wird das
 *   Überlaufflag d_1cdc2a = 1 gesetzt.
 * - Eingaben: p (Zeiger auf den Render-Objektdatensatz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a99fc, d_1a9a04 (belegte Einträge im globalen Vertex- bzw. Normalenpuffer).
 === Ende Beschreibung === */
#pragma aux f_1524d0 "*";
// BLIND: f_1524d0 hier komplett neu aus dem Original-Assembler schreiben (orig.sh fz_14dc28_t5a f_1524d0).
int f_16cf6a_b(int p1, int p2, int p3);
#pragma aux f_16cf6a_b "f_16cf6a" parm [eax edx ebx] modify exact [eax edx ebx];
int f_16cff5_b(int p1, int p2, int p3);
#pragma aux f_16cff5_b "f_16cff5" parm [eax edx ebx] modify exact [eax edx ebx];
struct P2 { int a; int b; };
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
void f_1524d0(char *p)
{
    char *t;
    char *s;
    char *q;
    int n;

    if ((U8(p,0x10) & 0x10) != 0) return;
    U16(p,6) = d_1a99fc;
    U16(p,8) = d_1a9a04;
    t = (char *)I(p,0x80);
    d_1a99fc += U16(t,4);
    d_1a9a04 += U16(t,6);
    if (d_1a99fc >= d_1a9a3c || d_1a9a04 >= d_1a9a48) {
        d_1a99fc -= U16(t,4);
        d_1a9a04 -= U16(t,6);
        d_1cdc2a = 1;
        return;
    }
    q = d_1cd314 + U16(p,6) * 12;
    I(p,0x1c) = (int)q;
    s = (char *)I(t,0x38);
    s = (char *)(((int)s & 0) ? 0 : (int)s);
    I(p,0x24) = (int)(d_1cd224 + U16(p,6) * 8);
    for (n = U16(t,4) + 1; --n; ) {
        f_16cf6a_b((int)q, (int)s, (int)(p + 0x84));
        q += 12;
        s += 12;
    }
    q = d_1cd324 + U16(p,8) * 12;
    I(p,0x20) = (int)q;
    s = (char *)I(t,0x3c);
    s = (char *)(((int)s & 0) ? 0 : (int)s);
    for (n = U16(t,6) + 1; --n; ) {
        f_16cff5_b((int)q, (int)s, (int)(p + 0x84));
        q += 12;
        s += 12;
    }
    U8(p,0x10) |= 0x10;
}


//@ f_152654
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt für alle in den Kameraraum transformierten Eckpunkte eines 3D-Objekts p die
 *   perspektivische Projektion auf 2D-Bildschirmkoordinaten (p + 0x24) durch. Liegt das Objekt teilweise am Rand
 *   des Sichtkegels (*p != 0 || m == 1), wird jeder Vertex einzeln mit f_16d2c9 geclippt und bei Sichtbarkeit
 *   mittels MULDIV(d_1a9aa0, X, Z) und MULDIV(d_1a9aa4, Y, Z) projiziert; liegt es vollständig im Sichtkegel,
 *   projiziert die schnelle Stapelroutine f_16d295 alle Punkte in einem Durchgang.
 * - Eingaben: p (Zeiger auf den Render-Objektdatensatz), m (Projektionsmodus: 1 = Einzelprüfung erzwingen).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc14 (Puffer für die pro Vertex gespeicherten Clipping-Codes).
 === Ende Beschreibung === */
#pragma aux f_152654 "*";
void f_152654(char *p, int m)
{
    int n; int i; int acc = m; char *c; signed char r = m; char *q;
    if ((U8(p,0x10) & 0x20) == 0) {
        n = U16(I(p,0x80),4);
        q = (char *)(d_1cdc14 + U16(p,6));
        if (*p != 0 || m == 1) {
            int *e;
            acc = 0;
            i = 0;
            e = (int *)I(p,0x24);
            c = (char *)I(p,0x1c);
            if (n > 0) {
                do {
                    r = f_16d2c9((int)c);
                    acc = r | acc;
                    *q = r;
                    if (*q == 0) {
                        e[0] = MULDIV(d_1a9aa0, I(c,0), I(c,8));
                        e[1] = MULDIV(d_1a9aa4, I(c,4), I(c,8));
                    }
                    q = q + 1;
                    i++;
                    c += 12;
                    e = e + 2;
                } while (i < n);
            }
            if (acc == 0) *p = 0;
        } else {
            f_16d295(I(p,0x24), I(p,0x1c), n);
            memset(q, 0, n);
        }
        U8(p,0x10) |= 0x20;
    }
}

//@ f_152740
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt das aktuell vorbereitete sichtbare 3D-Objekt (d_1c6bc0) anhand seines
 *   Tiefenschlüssels d_1c6bd4 per binärer Suche sortiert in die Renderliste d_1cd204 (bis zu d_1a9a38 Einträge,
 *   aktueller Zähler d_1a99e4) ein und verknüpft etwaige zugehörige Unterflächen in d_1cd220 mit dem neuen
 *   Eintrag.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cd204 (sortiertes Tiefen-Zeiger-Array), d_1a99e4 (Anzahl sichtbarer Objekte in der
 *   Liste).
 === Ende Beschreibung === */
#pragma aux f_152740 "*";
void f_152740(void)
{
    struct REC *q; int lo; int hi; int mid; int *t; unsigned short cnt; char *ptr; char *x; unsigned n; int length;
    if (d_1a99e4 < d_1a9a38) {
        hi = d_1a99e4++ * 8;
        I(d_1cd204, hi) = 0x7fffffff;
        q = d_1cd1b0++;
    } else {
        q = (struct REC *)I(d_1cd204, d_1a9a38 * 8 - 4);
        if (d_1c6bd4 >= q->w[5]) return;
    }
    lo = 0;
    hi = d_1a99e4 - 1;
    for (;;) {
        if (hi - lo < 2) {
            if (d_1c6bd4 > I(d_1cd204, lo * 8)) lo = hi;
            break;
        }
        mid = (lo + hi) >> 1;
        if (d_1c6bd4 <= I(d_1cd204, mid * 8)) hi = mid; else lo = mid;
    }
    { struct REC *copy = q; q = copy; } /* haelt die Registerzuteilung wie im Original */
    t = (int *)(d_1cd204 + lo * 8);
    length = d_1a99e4;
    length -= lo;
    lo = length - 1;
    memmove(t + 2, t, lo * 8);
    t[1] = (int)q;
    t[0] = d_1c6bd4;
    *q = d_1c6bc0;
    if (U16(&d_1c6bc0,12) > 0) {
        n = (unsigned short)d_1c6bca;
        ptr = d_1cd220 + n * 4;
        n = (unsigned short)d_1c6bcc + 1;
        goto ref_test;
        do {
            x = (char *)I(ptr,0);
            ptr += 4;
            I(x,0x44) = (int)q;
        ref_test:;
        } while (--n);
    }
}

//@ f_152870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt sicher, dass für ein sichtbares 3D-Objekt p alle drei Geometrie-Vorstufen -
 *   Kameratransformation (f_1524d0, Bit 0x10), Perspektivprojektion (f_152654, Bit 0x20) und
 *   Polygon-/Flächenaufbereitung (f_1702b8, Bit 0x40) - ausgeführt wurden, markiert das Objekt mit Bit 2 in
 *   U8(p, 0x11) und misst über f_16fc19 die dafür verbrauchte Zeit in d_1a9a6c.
 * - Eingaben: p (Zeiger auf den Render-Objektdatensatz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9a6c (Profiler-Zeitzähler).
 === Ende Beschreibung === */
#pragma aux f_152870 "*";
void f_152870(char *p)
{
    unsigned char fl;
    d_1a9a6c -= f_16fc19();
    if ((U8(p,0x10) & 0x10) == 0) f_1524d0(p);
    if ((U8(p,0x10) & 0x20) == 0) f_152654(p, 2);
    if ((U8(p,0x10) & 0x40) == 0) f_1702b8((int)p);
    U8(p,0x11) |= 2;
    d_1a9a6c += f_16fc19();
}

//@ f_1528cc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet alle in der sortierten Renderliste d_1cd204 (0..d_1a99e4 - 1) eingetragenen
 *   sichtbaren 3D-Objekte nacheinander durch Aufruf des Polygon-Renderers f_171000(1, i).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a99e4 (Anzahl der zu zeichnenden Objekte).
 === Ende Beschreibung === */
#pragma aux f_1528cc "*";
void f_1528cc(void)
{
    int i;
    for (i = 0; i < d_1a99e4; i++) {
        f_171000(1, i);
    }
}

//@ f_1528f8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verfeinert die Tiefensortierung der sichtbaren 3D-Objekte in d_1cd204 nach dem
 *   Painter-Algorithmus: Überlappen sich zwei Objekte im Tiefenbereich und im 2D-Bildschirmrechteck (f_171994)
 *   und liegt das hintere Objekt geometrisch vor dem vorderen (f_172148), werden ihre Listenplätze getauscht.
 *   Zyklische Verdeckungen werden über die Historienfelder lst, X, Y erkannt und durch schrittweises Verkleinern
 *   des Toleranzfaktors d_1a9b08 aufgelöst.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: lst, X, Y (Protokollarrys zur Erkennung zyklischer Überdeckungen), d_1a9b08
 *   (Toleranzschwelle).
 === Ende Beschreibung === */
#pragma aux f_1528f8 "*";
void f_1528f8(void)
{
    struct P5 { int a, b; };
    unsigned short Y[100], lst[100], X[100];
    struct { struct P5 tmp; struct P5 *tp; int i; struct P5 *qs; int nx; int again; } l;   // haelt die Registerzuteilung wie im Original
    struct P5 *q;
    int j, s, k;
    unsigned short cnt;
    char *e, *o;
    unsigned short sv;
    d_1a9937 = 0;   // Folge 37/35/36 gibt die Store-Folge 35/36/37 des Originals
    d_1a9935 = 0;
    d_1a9936 = 0;
    d_1a9b08 = 0x10000;
    for (l.i = 0, l.tp = (struct P5 *)d_1cd204; l.i < d_1a99e4; l.i++, l.tp++) {
        e = (char *)l.tp->b;
        if (!(U8(e,0x10) & 1)) continue;
        if (!(U8(e,0x11) & 2)) f_152870(e);
        cnt = 1;
        lst[0] = U16(e,4);
        X[0] = 0xffff;
        Y[0] = 0xffff;
        l.nx = l.i + 1;
        l.qs = l.tp + 1;
        do {
            l.again = 1;
            e = (char *)l.tp->b;
            for (j = l.nx, q = l.qs; j < d_1a99e4; j++, q++) {
                o = (char *)q->b;
                if (!(U8(o,0x10) & 1)) continue;
                if (I(o,0x14) > I(e,0x18)) continue;
                if (!f_171994((int)(o+0x40), (int)(e+0x40))) continue;
                if (!(U8(o,0x11) & 2)) f_152870(o);
                if (!f_172148((int)o, (int)e)) continue;
                if (cnt < 100) {
                    k = cnt;
                    X[k] = d_1cdc28;
                    Y[k] = d_1cdc26;
                    sv = U16(o,4);
                    lst[k] = sv;
                    for (s = k - 1; s >= 0; s--) {
                        if (sv == lst[s]) {
                            d_1a9b54 = cnt - s + 1;
                            memcpy(d_1c8ff8, lst + s, d_1a9b54 * 2);
                            memcpy(d_1c7168, X + s, d_1a9b54 * 2);
                            memcpy(d_1c7230, Y + s, d_1a9b54 * 2);
                            break;
                        }
                    }
                    if (s >= 0) {
                        if (d_1a9b08 > 0xd999) {
                            cnt = 0;
                            d_1a9b08 -= 0x3d7;
                            d_1a9b54 = 0;
                        } else {
                            d_1a9a0c++;
                            break;
                        }
                    }
                    cnt++;
                }
                l.tmp = *l.tp;
                *l.tp = *q;
                *q = l.tmp;
                l.again = 0;
                break;
            }
        } while (l.again == 0);
    }
    d_1a9b08 = 0x10000;
}

/* Im alten Bereich 1528f8 fehlender Ausgabehelfer. */
extern char d_1b8e54[], d_1b8e58[], d_1b8e64[], d_1b8e78[], d_1b8e8c[], d_1b8ea0[];
extern char d_1b8eb4[], d_1b8eb8[], d_1b8ec8[], d_1b8ed8[], d_1b8f18[], d_1b8f28[], d_1b8f38[];
extern double d_1b8f94;
int f_15e469(int, int);
int f_15e836(int);
int __cdecl f_17228c(int, const char *, ...);
#pragma aux f_15e469 modify exact [eax edx ebx];
#pragma aux f_17228c modify exact [eax];
//@ f_152be4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Exportiert zu Diagnose-/Entwicklungszwecken die komplette Geometrie eines 3D-Mesh-Objekts
 *   p (Anzahl und Koordinaten aller Eckpunkte, Normalen, Texturkoordinaten u, v sowie alle Dreiecksflächen) als
 *   formatierte Textdatei über f_15e469, f_17228c (fprintf) und f_15e836 (fclose).
 * - Eingaben: p (Zeiger auf die Mesh-Struktur).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: fp (geöffnetes Dateihandle), vt (Vertex-Iterator), fc (Flächen-Iterator).
 === Ende Beschreibung === */
#pragma aux f_152be4 "*";
// BLIND: f_152be4 hier komplett neu aus dem Original-Assembler schreiben (orig.sh fz_14dc28_t5a f_152be4).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
struct Vtx40 {
    unsigned short i0;
    unsigned short i1;
    int u;
    int v;
};
struct Face44 {
    unsigned char b0;
    unsigned char b1;
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
    char pad8[10];
    unsigned short w12;
    unsigned short w14;
    unsigned short w16;
    char pad18[12];
    unsigned short w24;
    char pad26[10];
};
struct Mesh {
    char pad0[4];
    unsigned short w4;
    unsigned short w6;
    unsigned short n40;
    unsigned short n44;
    char padC[44];
    struct V3 *v38;
    struct V3 *v3c;
    struct Vtx40 *v40;
    struct Face44 *v44;
};
void f_152be4(struct Mesh *p)
{
    int fp;
    int i;
    struct Vtx40 *vt;
    struct Face44 *fc;
    struct V3 *v1;
    struct V3 *v2;

    fp = f_15e469((int)d_1b8e58, (int)d_1b8e54);
    if (fp != 0) {
        f_17228c(fp, d_1b8e64, p->n40);
        f_17228c(fp, d_1b8e78, p->n44);
        f_17228c(fp, d_1b8e8c, p->w4);
        f_17228c(fp, d_1b8ea0, p->w6);
        f_17228c(fp, d_1b8eb4);
        f_17228c(fp, d_1b8eb8);
        f_17228c(fp, d_1b8ec8);
        for (i = 0, vt = p->v40; i < p->n40; i++, vt++) {
            unsigned x0 = vt->i0;
            unsigned x1 = vt->i1;
            v1 = p->v38;
            v1 += x0;
            v2 = p->v3c;
            v2 += x1;
            { struct V3 *rt = v2; v2 = rt; }
            { struct V3 *rt = v2; v2 = rt; }
            f_17228c(fp, d_1b8ed8,
                v1->x * d_1b8f94,
                v1->y * d_1b8f94,
                v1->z * d_1b8f94,
                v2->x * d_1b8f94,
                v2->y * d_1b8f94,
                v2->z * d_1b8f94,
                vt->u * d_1b8f94,
                vt->v * d_1b8f94);
        }
        f_17228c(fp, d_1b8eb4);
        f_17228c(fp, d_1b8f18);
        f_17228c(fp, d_1b8f28);
        for (i = 0, fc = p->v44; p->n44 > i; i++, fc++) {
            { struct Vtx40 *rt = vt; vt = rt; } /* haelt die Registerzuteilung wie im Original */
            f_17228c(fp, d_1b8f38,
                fc->b1,
                fc->w24,
                fc->b0,
                p->v40[fc->v0].i0,
                p->v40[fc->v1].i0,
                p->v40[fc->v2].i0,
                fc->w12,
                fc->w14,
                fc->w16,
                p->v40[fc->v0].u * d_1b8f94,
                p->v40[fc->v0].v * d_1b8f94,
                p->v40[fc->v1].u * d_1b8f94,
                p->v40[fc->v1].v * d_1b8f94,
                p->v40[fc->v2].u * d_1b8f94,
                p->v40[fc->v2].v * d_1b8f94);
        }
        f_17228c(fp, d_1b8eb4);
        f_15e836(fp);
    }
}


//@ f_152e64
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft alle dynamischen und statischen Lichtquellen der Szene (d_1cd1e0, Anzahl d_1a99b0)
 *   auf Aktivität, Sektorzugehörigkeit (nm) und Reichweite (d_1a9b24) um die Kameraposition, transformiert ihre
 *   Positionen (f_16cf6a) und Richtungen (f_16cff5) in den Kameraraum, berechnet bei Fackel-/Feuerlichtern ('F')
 *   das zeitabhängige Flackern des Lichtradius und verkettet alle sichtbaren Lichtquellen in der Liste d_1cd1e8
 *   (Anzahl d_1a99f4).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cd1e8 (Kopfzeiger der verketteten Liste aktiver Lichtquellen), d_1a99f4 (Anzahl
 *   sichtbarer Lichter).
 === Ende Beschreibung === */
#pragma aux f_152e64 "*";
void f_152e64(void)
{
    struct Rec58 {
        unsigned char *p;
        unsigned char on, mode, typ, vis, id;
        char pad9;
        unsigned short w;
        char padC[12];
        int rad;
        char pad1C[8];
        struct V3 pos;
        struct V3 ang;
        struct V3 m3c;
        int x48;
        int cur;
        unsigned short f50;
        char pad52[2];
        struct Rec58 *next;
    };
    struct V3 vec;
    int xmax;
    struct Rec58 *tail;
    unsigned u;
    int xmin;
    int zmin;
    int zmax;
    int nmf;
    char *nm;
    struct Rec58 *r;
    char *pc;
    int i, range, rad, v;

    { unsigned short rt = d_1a9b24; d_1a9b24 = rt; } /* haelt die Registerzuteilung wie im Original */
    { unsigned short rt = d_1cdc26; d_1cdc26 = rt; } /* haelt die Registerzuteilung wie im Original */
    if ((*(int *)d_1a9a1c & 0x40000) && d_1cdb3c < 100) {
        nmf = 1;
        nm = d_1c76f8 + (d_1cdb3c << 6);
        { char *rt = nm; nm = rt; } /* haelt die Registerzuteilung wie im Original */
        { char *rt = nm; nm = rt; } /* haelt die Registerzuteilung wie im Original */
        { char *rt = nm; nm = rt; } /* haelt die Registerzuteilung wie im Original */
        { char *rt = nm; nm = rt; } /* haelt die Registerzuteilung wie im Original */
    } else {
        nmf = 0;
    }

    d_1a99f4 = 0;
    d_1cd1e8 = 0;
    tail = (struct Rec58 *)d_1cd1e0;
    r = tail;
    if (r != 0) {
        range = *(int *)&d_1a9b24;
        xmin = d_1cd308 - range;
        { int rt = xmin; xmin = rt; } /* haelt die Registerzuteilung wie im Original */
        xmax = d_1cd308 + range;
        zmin = d_1cd310 - range;
        zmax = d_1cd310 + range;
        for (i = 0; i < d_1a99b0; ++i, ++r) {
            { int rt = xmin; xmin = rt; } /* haelt die Registerzuteilung wie im Original */
            if (r->on != 0) {
                r->vis = 0;
                if (r->w > 0 && (i < 3 || (*(int *)d_1a9a1c & 0x2000000) == 0)) {
                    if (nmf == 0 || i < 3) {
                        goto L_selected_152e64;
                    }
                    pc = nm;
                    while (*pc != 0) {
                        if (*pc == r->id) goto L_selected_152e64;
                        ++pc;
                    }
                    continue;
L_selected_152e64:
                        if (r->mode == 2) {
                            vec.x = d_1cd308 + r->pos.x;
                            vec.y = d_1cd30c + r->pos.y;
                            vec.z = d_1cd310 + r->pos.z;
                        } else {
                            vec = r->pos;
                        }

                        if (r->typ == 1 || r->typ == 3) {
                            rad = r->rad;
                            if (vec.x + rad >= xmin && vec.x - rad <= xmax &&
                                vec.z + rad >= zmin && vec.z - rad <= zmax) {
                                f_16cf6a((int)&r->m3c, (int)&vec, (int)d_1cc788);
                                if (r->p != 0 && r->p[2] == 'F' && r->typ == 1) {
                                    v = d_1a9978;
                                    r->x48 += d_1a9ab0 * v;
                                    v = r->x48;
                                    u = (v >> 20) & 7;
                                    ((unsigned short *)&r->x48)[1] &= 0xf;
                                    if (u != r->cur) {
                                        r->cur = u;
                                        r->w = r->f50 + *(short *)(d_1a9b5c + (u & 7) * 4) + (((unsigned short)f_165de2() & 3) - 2);
                                    }
                                }
                            } else {
                                continue;
                            }
                        }

                        if (r->typ == 2 || r->typ == 3)
                            f_16cff5((int)&r->x48, (int)&r->ang, (int)d_1cc788);
                        ++d_1a99f4;
                        r->vis = 1;
                        if (d_1cd1e8 == 0) d_1cd1e8 = (char *)r;
                        else tail->next = r;
                        tail = r;
                }
            }
        }
        tail->next = 0;
    }
}

extern int d_1cdb44, d_1cdb48, d_1cdb4c, d_1cdb50, d_1cdb58, d_1cdb5c, d_1cdb60, d_1cdb68, d_1cdb6c, d_1cdb74;
extern short d_1ccf60[8];
extern int d_1a997c;
int __cdecl f_16fb53_2(int, int);
#pragma aux f_16fb53_2 "f_16fb53" parm caller [] modify exact [eax];
int __cdecl f_16fb72_2(int, int);
#pragma aux f_16fb72_2 "f_16fb72" parm caller [] modify exact [eax];
int f_16f693_5(int, int, int, int, int);
#pragma aux f_16f693_5 "f_16f693" parm caller [eax] [edx] [ebx] [ecx];
int f_16d2c9_full(int);
#pragma aux f_16d2c9_full "f_16d2c9";
int fxmul831(int a, int b);
#pragma aux fxmul831 = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] value [eax] modify exact [eax edx];
int f_16ecba_nm(int);
#pragma aux f_16ecba_nm "f_16ecba" parm [eax] modify exact [eax] nomemory;
//@ f_153128
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Debug-Visualisierung für die Lichtquellen der 3D-Szene (d_1cd1e0): Zeichnet sowohl in
 *   einem 2D-Übersichtsfenster als auch direkt in der 3D-Perspektivansicht Markierungskreuze und
 *   Richtungsvektoren für alle Lichtquellen ab Index 3.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: w.old44..w.old68 (gesicherte Viewport-Grenzen), scale (Darstellungsmaßstab).
 === Ende Beschreibung === */
#pragma aux f_153128 "*";
void f_153128(void)
{
    struct Work {
        int out[3], in[3], shade, idx, xslot;
        int old6c, old50, old48, old68, old4c, old44;
        int scale, z;
    } w;
    int x, y, h, c1, scale;
    int i;
    char *p;
    w.old44 = d_1cdb44;
    w.old48 = d_1cdb48;
    w.old4c = d_1cdb4c;
    w.old50 = d_1cdb50;
    w.old6c = d_1cdb6c;
    w.old68 = d_1cdb68;
    d_1cdb4c = -80;
    d_1cdb6c = 80;
    d_1cdb50 = -70;
    d_1ccf60[0] = (short)d_1cdb4c;
    d_1ccf60[1] = (short)d_1cdb50;
    d_1ccf60[2] = (short)d_1cdb6c;
    d_1ccf60[3] = (short)d_1cdb50;
    d_1cdb68 = 70;
    d_1ccf60[4] = (short)d_1cdb6c;
    d_1ccf60[5] = (short)d_1cdb68;
    d_1ccf60[6] = (short)d_1cdb4c;
    d_1ccf60[7] = (short)d_1cdb68;
    c1 = f_16ecb4(0);
    d_1cdb44 = 235;
    d_1cdb48 = 74;
    f_16f693_5(c1, -80, 80, -70, 4);
    scale = 0x8000 / d_1a997c;
    w.scale = scale;
    p = d_1cd1e0;
    if (p != 0) {
        p += 0x108;
        for (i = 3; i < d_1a99b0; ++i) {
                int two;
                if (p[4]) w.shade = p[7] ? d_1cdb60 : d_1cdb58;
                else w.shade = d_1cdb5c;
                x = fxmul831(scale, I(p,0x3c)) >> 16;
                y = fxmul831(w.scale, I(p,0x44)) >> 16;
                y = (y & 0) ? 0 : y; /* haelt die Registerzuteilung wie im Original */
                y = (y & 0) ? 0 : y; /* haelt die Registerzuteilung wie im Original */
                c1 = fxmul831(scale, I(p,0x48)) >> 16;
                h = I(p,0x50);
                w.z = c1;
                h = fxmul831(scale, h) >> 16;
                two = 2;
                d_1ccf60[0] = (short)(x + two);
                d_1ccf60[1] = (short)(y + two);
                d_1ccf60[2] = (short)(x - two);
                d_1ccf60[3] = d_1ccf60[1];
                d_1ccf60[4] = d_1ccf60[2];
                d_1ccf60[5] = (short)(y - two);
                d_1ccf60[7] = (short)(y - two);
                d_1ccf60[6] = d_1ccf60[0];
                f_163428(4, w.shade);
                if (p[6] == 2 || p[6] == 3) {
                    int sum;
                    f_16ecba(d_1cdb74);
                    f_16fb53_2(x, y);
                    sum = h;
                    sum += y;
                    f_16fb72_2(x + w.z, sum);
                }
                p += 0x58;
        }
    }
    h = d_1cdb74;
    f_16ecba(h);
    f_16fb53_2(-2, -2);
    f_16fb72_2(2, 2);
    f_16fb53_2(-2, 2);
    f_16fb72_2(2, -2);
    d_1ccf60[0] = (short)d_1cdb4c;
    d_1ccf60[1] = (short)d_1cdb50;
    d_1ccf60[2] = (short)d_1cdb6c;
    d_1ccf60[3] = (short)d_1cdb50;
    d_1ccf60[4] = (short)d_1cdb6c;
    d_1ccf60[5] = (short)d_1cdb68;
    d_1ccf60[6] = (short)d_1cdb4c;
    d_1ccf60[7] = (short)d_1cdb68;
    f_163428(4, h);
    d_1cdb44 = w.old44;
    d_1cdb48 = w.old48;
    d_1cdb4c = w.old4c;
    d_1cdb50 = w.old50;
    d_1cdb6c = w.old6c;
    d_1cdb68 = w.old68;
    { int sy;
    p = d_1cd1e0;
    if (p != 0) {
        {
        f_16ecba_nm(d_1cdb74);
        p += 0x108;
        {
            for (w.idx = 3; w.idx < d_1a99b0; ++w.idx, p += 0x58) {
            if (p[4] && p[7] && !f_16d2c9_full((int)(p + 0x3c))) {
                int rawx = MULDIV(d_1a9aa0, I(p,0x3c), I(p,0x44));
                int rawy = MULDIV(d_1a9aa4, I(p,0x40), I(p,0x44));
                {
                int s = (rawx + 0x8000) >> 16;
                int sxm2;
                int syp2;
                w.xslot = s;
                sy = (rawy + 0x8000) >> 16;
                s = sy - 2;
                sxm2 = w.xslot - 2;
                sxm2 = (sxm2 & 0) ? 0 : sxm2; /* haelt die Registerzuteilung wie im Original */
                sxm2 = (sxm2 & 0) ? 0 : sxm2; /* haelt die Registerzuteilung wie im Original */
                syp2 = sy + 2;
                f_16fb53_2(sxm2, s);
                {
                int sxp2 = w.xslot + 2;
                sxp2 = (sxp2 & 0) ? 0 : sxp2; /* haelt die Registerzuteilung wie im Original */
                f_16fb72_2(sxp2, syp2);
                f_16fb53_2(sxm2, syp2);
                f_16fb72_2(sxp2, s);
                }
                f_16fb53_2(w.xslot, sy);
                }
                *(struct V3 *)w.in = *(struct V3 *)(p + 0x24); w.in[1] = 0;
                f_16cf6a((int)w.out, (int)w.in, (int)d_1cc788);
                if (!f_16d2c9_full((int)w.out)) {
                    int rx2, ry2;
                    f_16fb53_2(w.xslot, sy);
                    rx2 = MULDIV(d_1a9aa0, w.out[0], w.out[2]);
                    ry2 = MULDIV(d_1a9aa4, w.out[1], w.out[2]);
                    w.xslot = (rx2 + 0x8000) >> 16;
                    sy = (ry2 + 0x8000) >> 16;
                    f_16fb72_2(w.xslot, sy);
                }
            }
            }
        }
        }
    }
    }
}

//@ f_1535e8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt die Sichtbarkeitsprüfung (Sektor-/Portal-Culling und Frustum-Culling) über die
 *   3D-Objekte der Szene (d_1cd210 bzw. die Sichtbarkeitsliste der aktuellen Zelle d_1cdb3c in d_1c76f8) durch.
 *   Für jedes im Sichtkegel liegende Objekt baut sie die Objekt-Kameramatrix d_1c6c44 auf, prüft die
 *   Bounding-Box über f_152020 (und nahe der Kamera über f_152870 / f_152310) und trägt das sichtbare Objekt
 *   über f_152740 in die Renderliste ein.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c6bc0: Arbeitsstruktur für das aktuell geprüfte sichtbare 3D-Objekt.
 *   - d_1a9b44, d_1a9b48: Zähler für sichtbare bzw. teilweise geclippte Objekte im aktuellen Frame.
 === Ende Beschreibung === */
#pragma aux f_1535e8 "*";
#pragma aux f_152310 modify exact [eax];
#pragma aux f_172628 modify exact [eax];
struct SubObj1535e8 {
    char pad0[0x14];
    char b14;
    char b15;
    char pad16[2];
    struct SubObj1535e8 *p18;
};
struct Obj48 {
    char b0;
    char pad1[7];
    short w08;
    unsigned short w0a;
    int i0c;
    int i10;
    int i14;
    struct SubObj1535e8 *p18;
    struct V3 v1c;
    char *p28;
    struct Obj48 *next;
};
struct B8_1535e8 {
    short x0, x1, y0, y1;
};
struct Rec1c6bc0 {
    unsigned char b0;
    char pad1;
    unsigned short w02;
    short w04;
    short w06;
    short w08;
    short w0a;
    short w0c;
    short w0e;
    int i10;
    char pad14[20];
    int i28;
    int i2c;
    int i30;
    int i34;
    int i38;
    int i3c;
    struct B8_1535e8 c00;
    short c08;
    struct B8_1535e8 c0a;
    short c12;
    short c14;
    short c16;
    short c18;
    short c1a;
    short c1c;
    short c1e;
    short c20;
    char pad62[26];
    int c3c;
    int c40;
    int c44[12];
};
#define R6 ((*(struct Rec1c6bc0 *)&d_1c6bc0))
void f_1535e8(void)
{
    struct {
        struct Obj48 dummy;
        int mat[12];
        struct V3 v;
        int i;
        struct Obj48 *p;
        int all;
        int flag;
        char *mesh;
    } s; // haelt die Registerzuteilung wie im Original
    unsigned char *cp;
    struct SubObj1535e8 *sub;

    d_1a9b44 = 0;
    d_1a9b48 = 0;
    s.flag = 1;
    if ((*(int *)d_1a9a1c & 0x40000) && d_1cdb3c < 100) {
        s.all = 0;
    } else {
        s.all = 1;
    }
    if (s.all) {
        s.i = -1;
        s.p = (struct Obj48 *)d_1cd210 - 1;
    } else {
        char *cell = d_1c76f8 + (d_1cdb3c << 6);
        cp = (unsigned char *)(cell + 1);
        s.dummy.next = (struct Obj48 *)I(cell, 0x3c);
        s.p = &s.dummy;
    }
    for (;;) {
        if (s.all) {
            if (++s.i >= d_1a99ac) break;
            s.p++;
        } else {
            s.p = s.p->next;
            if (s.p == 0) {
                while (*cp != 0) {
                    s.p = *(struct Obj48 **)(d_1c7734 + ((unsigned)*cp << 6));
                    cp++;
                    if (s.p != 0) break;
                }
                if (s.p == 0) break;
            }
            s.i = s.p - (struct Obj48 *)d_1cd210;
        }
        if (s.p->b0 == 0) continue;
        if (s.p->w0a & 0x880) continue;
        s.mesh = s.p->p28;
        if (s.mesh == 0) continue;
        f_16b930((int)s.mat);
        if (s.p->i10 != 0) {
            s.mat[10] += s.p->i10;
        }
        if (s.p->w0a & 2) {
            if (!f_163bf8(d_1cd308, d_1cd310, (int)s.p, (int)s.mat)) continue;
        }
        f_16b60c((int)&d_1c6c44, (int)s.mat, (int)d_1cc788);
        f_16cf6a((int)&s.v, (int)&s.p->v1c, (int)&d_1c6c44);
        if (-s.p->i14 - d_1a9adc > s.v.z || s.v.z > s.p->i14) continue;
        if (abs(s.v.x) - s.p->i14 > fxmul831(*(int *)&d_1a9a90, s.v.z - s.p->i14)) continue;
        if (abs(s.v.y) - s.p->i14 > fxmul831(d_1a9a98, s.v.z - s.p->i14)) continue;
        if (s.p->p18 != 0) {
            sub = s.p->p18;
            if (sub->p18 != 0) {
                sub = sub->p18;
                if (sub->b14 != 0) {
                    sub->b15 = 0;
                }
            }
        }
        d_1c6c40 = (int)s.mesh;
        *(char *)&d_1c6bc0 = 0;
        d_1c6c3c = (int)s.p;
        S16(&d_1c6bc0, 2) = s.p->w0a;
        d_1c6bd0 = 0;
        d_1c6bc4 = (short)s.i;
        d_1c6bcc = 0;
        if (f_152020((int)&d_1c6bc0)) continue;
        if (U8(&d_1c6bc0, 0) & 0x10) {
            int s_00, s_fc, s_04;
            s_00 = d_1a9a00;
            s_fc = d_1a99fc;
            s_04 = d_1a9a04;
            f_152870((char *)&d_1c6bc0);
            if (!f_152310((int)&d_1c6bc0)) {
                d_1a9a00 = s_00;
                d_1a99fc = s_fc;
                d_1a9a04 = s_04;
                continue;
            }
        }
        R6.c08 = 4;
        *(unsigned char *)&R6.i10 |= 1;
        R6.c0a = R6.c00;
        R6.c12 = R6.c00.x0;
        R6.c14 = R6.c00.y0;
        R6.c16 = R6.c00.x1;
        R6.c18 = R6.c00.y0;
        R6.c1a = R6.c00.x1;
        R6.c1c = R6.c00.y1;
        R6.c1e = R6.c00.x0;
        R6.c20 = R6.c00.y1;
        d_1a9b44++;
        if (s.flag && s.p->w08 == 0 && s.p->i10 == 0 && !(s.p->w0a & 0x1002)) {
            if (f_172628((int)s.p)) {
                s.flag = 0;
            }
        }
        d_1c6be8 = I(s.mesh, 0x20);
        d_1c6bf0 = I(s.mesh, 0x24);
        d_1c6bf8 = I(s.mesh, 0x28);
        d_1c6bec = I(s.mesh, 0x2c);
        d_1c6bf4 = I(s.mesh, 0x30);
        d_1c6bfc = I(s.mesh, 0x34);
        if (*(char *)&d_1c6bc0 != 0) {
            d_1a9b48++;
        }
        f_152740();
    }
}
