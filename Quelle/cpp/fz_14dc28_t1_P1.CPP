/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t1 (0x14DC28 - 0x14EEAC)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil der 3D-Geometrie-, Kollisions- und Bodenhöhen-Engine für die frei
 * begehbaren 3D-Dungeons und Innenräume. Sie berechnet im 16.16-Festkommaformat den Kollisionsradius der
 * Heldengruppe, Schnittpunkte und Höhenwerte auf geneigten Bodenpolygonen (Treppen, Rampen, Plattformen),
 * aufgeweitete 2D-Kollisionsumrisse (Minkowski-Summe um den Spielerradius) sowie Punkt-in-Polygon-Tests für
 * Wände und Bodenflächen.
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -fp5
// P3 4/11 gleich (suche.py 30.10.2026, Basis fz_14dc28_t1_P1.CPP)
#pragma aux f_14dc28 "*";
#pragma aux f_14dc6c "*";
#pragma aux f_14dd20 "*";
#pragma aux f_14def4 "*";
#pragma aux f_14e1f0 "*";
#pragma aux f_14e288 "*";
#pragma aux f_14e4a4 "*";
#pragma aux f_14e520 "*";
#pragma aux f_14e5c8 "*";
#pragma aux f_14ea94 "*";
#pragma aux f_14ec24 "*";
// P3 0/1 gleich (suche.py 25.10.2026, Basis fz_14dc28_t1_P1.CPP)
// CC wcc386
// P1 2/11 gleich
// fz_14dc28_t1.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x14DC28-0x14EEAC
#include <string.h>
#include <stdlib.h>
void *mark(const char *file, int line);                  // 0x014B10
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define W(p,o) (*(short *)((char *)(p)+(o)))
#define U16(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define U8(p,o) (*(unsigned char *)((char *)(p)+(o)))
/* Gewoehnliches C: 64-Bit-Produkt und Division als zwei unsigned-Woerter. */
static unsigned nquot(unsigned hi,unsigned lo,unsigned d)
{
 unsigned rem=0,q=0,carry,bit;int i;
 for(i=63;i>=0;i--) {
  bit=i>=32 ? ((hi>>(i-32))&1) : ((lo>>i)&1);
  carry=rem>>31;rem=(rem<<1)|bit;
  if(carry || rem>=d){rem-=d;if(i<32)q|=1U<<i;}
 }
 return q;
}
static void nproduct(unsigned a,unsigned b,unsigned *hi,unsigned *lo)
{
 unsigned a0=a&65535,a1=a>>16,b0=b&65535,b1=b>>16;
 unsigned t=a0*b0,k=t>>16,w0=t&65535,w1,w2;
 t=a1*b0+k;w1=t&65535;w2=t>>16;
 t=a0*b1+w1;k=t>>16;
 *hi=a1*b1+w2+k;*lo=(t<<16)+w0;
}
static int fmul(int a,int b)
{
 unsigned h,l;nproduct((unsigned)a,(unsigned)b,&h,&l);
 if(a<0)h-=(unsigned)b;if(b<0)h-=(unsigned)a;
 return (int)((l>>16)|(h<<16));
}
static int fdiv(int a,int b)
{
 unsigned ua=a<0 ? 0U-(unsigned)a : (unsigned)a;
 unsigned ub=b<0 ? 0U-(unsigned)b : (unsigned)b;
 unsigned q=nquot(ua>>16,ua<<16,ub);
 return (a<0)!=(b<0) ? (int)(0U-q) : (int)q;
}
static int muldiv(int a,int b,int c)
{
 unsigned ua=a<0?0U-(unsigned)a:(unsigned)a,ub=b<0?0U-(unsigned)b:(unsigned)b;
 unsigned uc=c<0?0U-(unsigned)c:(unsigned)c,h,l,q;
 nproduct(ua,ub,&h,&l);q=nquot(h,l,uc);
 return ((a<0)!=(b<0))!=(c<0)?(int)(0U-q):(int)q;
}
int f_145547(const char *a, const char *b, int n);
int f_16b930(void *p1);
int f_16cc44(void *p1, unsigned short p2);
int f_16cf6a(void *p1, void *p2, void *p3);
int f_16cff5(void *p1, void *p2, void *p3);
#pragma aux f_16cf6a parm [eax edx ebx] modify exact [eax edx]
#pragma aux f_16cff5 parm [eax edx ebx] modify exact [eax edx]
int f_163bf8(int p1, int p2, char *p3, void *p4);
int f_16d33f(int p1, int p2, int p3, int p4);
int f_16d3b7(int p1, int p2, int p3, int p4);
int f_16d3d0(int p1);
int f_14eeac(char *p1, int p2, int p3, int p4, int p5, int p6, void *p7, int p8);
int f_14dd20(int p1, int p2, char *p3, char *p4, int *p5);
int f_14ea94(char *p1, unsigned p2, int p3, int p4);
int f_14e520(int *p1, int *p2, int *p3, int *p4, int *p5);
extern unsigned char d_1a993d;
extern signed char d_1a996c;
extern int d_1a9afc;
extern unsigned short d_1cdc1e;
extern int d_1cd23c;
extern int d_1cd244;
extern int d_1cdb3c;
extern unsigned char d_1a98e3, d_1a98e4, d_1a98e5;
extern int d_1a9ac4, d_1a9ae4, d_1c6b9c, d_1c6b94, d_1a9abc, d_1cd214;
extern int d_1c6b4c;
extern unsigned char d_1a9937[];
extern int d_1a99e0;
extern short d_1a9964;
extern int d_1a9ac0, d_1c6b50;
extern char *d_1c6b48;
extern int d_1c6b70;
extern unsigned d_1c6b98;
extern int d_1c6b78, d_1c6b7c;
extern int *d_1c6b44;
extern int d_1c6b64, d_1c6b68, d_1c6b60, d_1c6b6c;
extern int d_1a9a10;
extern int d_1a9b20, d_1a9a74;
extern const char d_1b8db0[];

//@ f_14dc28
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den horizontalen Kollisionsradius (d_1a9afc) des Spielers bzw. der Kamera in der
 *   3D-Szene und begrenzt ihn auf den zulässigen Festkommabereich [0x8000, 0xC0000] (entspricht 0.5 bis 12.0
 *   Längeneinheiten). Ist die 3D-Engine noch nicht initialisiert (d_1a993d == 0), bricht sie mit dem Fehlercode
 *   0xf002 ab.
 * - Eingaben: p1 (gewünschter Kollisionsradius im 16.16-Festkommaformat).
 * - Rückgabewert: Status-/Fehlercode (0xf012 nach dem Setzen, 0xf002 wenn nicht initialisiert).
 * - Wichtige Variablen:
 *   - d_1a9afc: Aktueller 3D-Kollisionsradius.
 *   - d_1a996c: Globales Fehlerstatuswort der 3D-Engine.
 === Ende Beschreibung === */
extern int g_1a996c;
#pragma aux g_1a996c "d_1a996c";
#pragma aux f_14dc28 "f_14dc28"
int f_14dc28(int p1)
{
    int value;
    if (d_1a993d == 0) {
        g_1a996c = 0xf002;
        return 0xf002;
    }
    value = p1;
    if (p1 < 0x8000) value = 0x8000;
    if (value > 0xc0000) value = 0xc0000;
    d_1a9afc = value;
    g_1a996c = 0xf012;
    return 0xf012;
}

//@ f_14dc6c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft per kurzem Sicht-/Interaktionsstrahl (Länge -0x320000 in Blickrichtung d_1cdc1e
 *   ausgehend von der Spielerposition d_1cd23c, d_1cd244), ob der Spieler frontal vor dem 3D-Kollisionspolygon
 *   p1 steht und dieses innerhalb der Tast-/Aktionsreichweite schneidet (f_14eeac).
 * - Eingaben: p1 (Zeiger auf einen vorbereiteten 56-Byte-Kollisionsdatensatz).
 * - Rückgabewert: 1, wenn der Strahl das Polygon trifft (r > 0), sonst 0.
 * - Wichtige Variablen: vi, vo (Strahlvektor vor und nach Rotation um den Blickwinkel d_1cdc1e), m60
 *   (Rotationsmatrix).
 === Ende Beschreibung === */
int f_14dc6c(char *p1)
{
    int vi[3]; int vo[3]; char m60[48]; char d8[120];
    int r;
    if (p1 == 0 || I(p1,0x34) == 0) return 0;
    vi[0] = 0;
    vi[1] = 0;
    vi[2] = 0xffce0000;
    f_16b930(m60);
    f_16cc44(m60, d_1cdc1e);
    f_16cff5(vo, vi, m60);
    r = f_14eeac(p1, 2, d_1cd23c, d_1cd244, vo[0], vo[2], d8, 2);
    return r > 0;
}

//@ f_14dd20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet für eine gegebene horizontale Position (p1, p2) (X, Z) die exakte vertikale
 *   Bodenhöhe (*p5) auf einem geneigten 3D-Polygon p4 des Szenenobjekts p3. Dazu schneidet sie die horizontale
 *   Linie bei Z = p2 mit den Polygonkanten, bestimmt die linke und rechte Schnittkante (minx, maxx) samt deren
 *   Höhen (minz, maxz) und interpoliert die Höhe linear an der Koordinate X = p1.
 * - Eingaben:
 *   - p1, p2: Horizontale X- und Z-Koordinate des Testpunkts (16.16-Festkomma).
 *   - p3: Zeiger auf die Szenenobjekt-Instanz (mit Basishöhe in +0x10 und Mesh-Zeiger in +0x28).
 *   - p4: Zeiger auf die Polygon-/Flächendefinition.
 *   - p5: Ausgabezeiger für die berechnete vertikale Höhe (Y).
 * - Rückgabewert: 1, wenn mindestens zwei Kantenschnitte gefunden wurden und die Höhe bestimmt werden konnte,
 *   sonst 0.
 * - Wichtige Variablen: minx, maxx, minz, maxz (Spannweite und Höhenwerte des Polygons auf Höhe p2).
 === Ende Beschreibung === */
int f_14dd20(int p1, int p2, char *p3, char *p4, int *p5)
{
    int owner = I(p3, 0x28);
    int base = I(p3, 0x10);
    int indices = I(owner, 0x40);
    int maxz;
    int points = I(owner, 0x38);
    unsigned short *cursor = (unsigned short *)(p4 + 2);
    unsigned n = U8(p4, 1);
    int remaining;
    int minz;
    int maxx, hits, minx;
    int *source;

    source = (int *)(points + U16(indices + cursor[n - 1] * 12, 0) * 12);
    minx = 0x7fffffff;
    maxx = (int)0x80000000;
    remaining = n + 1;
    hits = 0;
    goto loop_test;
loop_body:
    {
        int *prev = source;
        unsigned vertex, point;
        int t, x, y, z, dz, rel;
        vertex = *cursor++;
        point = U16(indices + vertex * 12, 0);
        source = (int *)(points + point * 12);
        dz = source[2] - prev[2];
        rel = p2 - prev[2];
        if (abs(dz) > abs(rel >> 15)) {
            t = fxdiv831(rel, dz);
            if (abs(t) <= 0x30000) {
                x = prev[0] + fxmul831(t, source[0] - prev[0]);
                y = prev[1] + fxmul831(t, source[1] - prev[1]);
                z = base + y;
                if (x < minx) { minx = x; minz = z; }
                if (x > maxx) { maxx = x; maxz = z; }
                hits++;
            }
        }
    }
loop_test:
    if (--remaining) goto loop_body;
    if (hits < 2) return 0;
    {
        int rel = p1 - minx;
        int dx = maxx - minx;
        int r;
        if (abs(dx) > abs(rel >> 15)) {
            int t = fxdiv831(rel, dx);
            r = minz + fxmul831(t, maxz - minz);
        } else {
            r = fxmul831(0x8000, minz + maxz);
        }
        *p5 = r;
    }
    return 1;
}


//@ f_14def4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wertet bei der Höhen- und Bodenprüfung eines Bewegungsschritts an der Position (p1, p2,
 *   p3) ein einzelnes Boden-/Deckenpolygon p4 (Kollisionsdatensatz p5, Objekt p6, Raumkennung p7) aus. Liegt die
 *   ermittelte Polygonhöhe hit unterhalb der Kopfhöhe des Spielers, aktualisiert sie die höchste begehbare
 *   Bodenhöhe (d_1a9abc), die Bodennormale (d_1c6b4c) und die aktuelle Raum-/Sektorkennung (d_1cdb3c); liegt sie
 *   darüber, aktualisiert sie die niedrigste Deckenhöhe (d_1a9ac0) und Deckennormale (d_1c6b50).
 * - Eingaben: p1 (X), p2 (aktuelle Höhe Y), p3 (Z), p4 (Polygon), p5 (56-Byte-Kollisionsdatensatz), p6
 *   (Szenenobjekt), p7 (Sektor-/Raum-ID).
 * - Rückgabewert: 1, wenn das Polygon an (p1, p3) getroffen wurde, sonst 0.
 * - Wichtige Variablen:
 *   - hit: Durch f_14dd20 berechnete Höhe des Polygons an (p1, p3).
 *   - d_1a9abc, d_1a9ac0: Höchster gefundener Bodenwert unter dem Spieler bzw. niedrigster Deckenwert über dem
 *     Spieler.
 *   - d_1cdb3c: Ermittelte Sektor-/Raumnummer am Standpunkt.
 === Ende Beschreibung === */
int f_14def4(int p1, int p2, int p3, char *p4, char *p5, char *p6, int p7)
{
    int r;
    int hit;
    int special;
    int nearer;
    int farther;
    int valid;
    int offset;
    p2 = (p2 & 0) ? 0 : p2; // Ternär-Anker bindet Stack-Slot und Registerwahl für p2
    p3 = (p3 & 0) ? 0 : p3; // Ternär-Anker hält Lebensdauer und Registerbindung von p3
    r = f_14ea94(p5, 1, p1, p3);
    if (r == 0) return r;
    r = f_14dd20(p1, p3, p6, p4, &hit);
    if (r == 0) return r;
    valid = p7 > 0 && p7 < 99;
    if (valid) {
        special = f_14ea94(p5, 2, p1, p3);
        if (d_1cdb3c == 0 || (special && d_1a98e3 == 0)) {
            d_1cdb3c = p7;
            if (special) d_1a98e3 = 1;
        }
    }
    if (hit < p2 - (d_1a9ac4 - d_1a9ae4)) {
        if (valid) {
            if (special && d_1a98e3 == 0) {
                d_1cdb3c = p7;
                d_1c6b9c = hit;
                d_1a98e3 = 1;
            } else if (hit > d_1c6b9c && (special || d_1a98e3 == 0)) {
                d_1cdb3c = p7;
                d_1c6b9c = hit;
                if (special) d_1a98e3 = 1;
            }
        }
        farther = d_1c6b94 + d_1a9afc < hit;
        nearer = hit > d_1c6b94;
        if ((special == 0 && ((d_1a98e4 == 0 && nearer != 0) ||
                              (d_1a98e4 != 0 && farther != 0))) ||
            (special != 0 && ((d_1a98e4 != 0 && nearer != 0) ||
                              (d_1a98e4 == 0 && farther != 0)))) {
            unsigned index = U16(p4, 0x24);
            int owner = I(p6, 0x28);
            offset = index * 4;
            offset -= index;
            offset <<= 2;
            index = I(owner, 0x3c) + offset;
            d_1c6b4c = index;
            d_1a98e4 = (char)special;
            d_1c6b94 = hit;
        }
        if (hit > d_1a9abc) {
            d_1a9abc = hit;
            d_1cd214 = (int)p6;
            d_1a99e0 = 1 + d_1a99e0;
            d_1a9937[1] = 1;
            d_1a9964 = W(p5, 8);
            return 1;
        }
    } else if (hit < d_1a9ac0) {
        d_1a9937[2] = 1;
        d_1a9ac0 = hit;
        d_1a99e0 = d_1a99e0 + 1;
        if (special || d_1a98e5 == 0) {
            unsigned index = U16(p4, 0x24);
            int owner = I(p6, 0x28);
            offset = index * 4;
            offset -= index;
            offset <<= 2;
            index = I(owner, 0x3c) + offset;
            d_1c6b50 = index;
            d_1a98e5 = (char)special;
        }
        d_1cd214 = (int)p6;
        d_1a9964 = W(p5, 8);
    }
    return 1;
}

//@ f_14e1f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Klassifiziert ein 3D-Polygon p1 anhand des ersten Buchstabens seines
 *   Material-/Gruppennamens (*(char )I(p1, 0x28)) in Kollisions- und Oberflächentypen (z. B. 'L' -> 0x01
 *   Boden/Land, 'H' -> 0x05, 'T' -> 0x08 Treppe/Trigger, 'Y' -> 0x0a, 'S' -> 0x18, 'V' -> 0x1a, 'N' -> 0x40,
 *   'X'/'U' -> 0x02 bzw. 0x20 Wand/Hindernis, sonst 0x80 ignoriert).
 * - Eingaben: p1 (Zeiger auf die Polygonstruktur).
 * - Rückgabewert: Bitmaske der Kollisionsklasse (0x01 bis 0x80).
 * - Wichtige Variablen: q (Zeiger auf den Namensstring des Polygons/Materials).
 === Ende Beschreibung === */
int f_14e1f0(char *p1)
{
    char **q = (char **)I(p1,0x28);
    if (q != 0 && *q != 0) {
        switch (**q) {
        case 0x4c: return 1;
        case 0x48: return 5;
        case 0x54: return 8;
        case 0x59: return 10;
        case 0x53: return 0x18;
        case 0x56: return 0x1a;
        case 0x4e: return 0x40;
        case 0x58:
            return (f_145547(*q, d_1b8db0, 2) == 0) ? 2 : 0x20;
        case 0x55: return 2;
        case 0x5a: break;
        }
    }
    return 0x80;
}

//@ f_14e288
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Übernimmt ein 3D-Polygon p1 eines Objekts p2 in den aktiven Kollisionspuffer (d_1c6b48 /
 *   Vertexliste d_1c6b44), sofern dessen 2D-Bounding-Box (minX..maxX, minY..maxY) das aktuelle Suchrechteck
 *   (d_1c6b68..d_1c6b64, d_1c6b6c..d_1c6b60) schneidet. Bei beweglichen/gedrehten Objekten (d_1c6b98 & 0x20)
 *   werden die Eckpunkte zuvor über f_163bf8 und f_16cf6a in Weltkoordinaten transformiert.
 * - Eingaben: p1 (Polygon), p2 (Szenenobjekt).
 * - Rückgabewert: 1, wenn das Polygon im Suchbereich liegt und in d_1c6b48 eingetragen wurde, sonst 0.
 * - Wichtige Variablen: d_1c6b48 (aktueller 56-Byte-Kollisionseintrag), d_1c6b44 (Schreibzeiger im Vertex-Pool).
 === Ende Beschreibung === */
typedef struct { int v[3]; } E12;
typedef struct { int v[4]; } E16;
int f_14e288(unsigned short *p1, char *p2)
{
    int mat[12];
    int vec[3];
    int n, mode, i;
    int *node, *arrB, *arrA, *dst;
    unsigned short *q;
    char *rec;
    int idx;
    int *src;

    if (d_1c6b48 == 0 || p1 == 0 || p2 == 0) return 0;
    if (d_1c6b70 >= 0x7cc) return 0;
    node = (int *)I(p2,0x28);
    n = U8(p1,1);
    arrA = (int *)node[0x38/4];
    arrB = (int *)node[0x40/4];
    mode = d_1c6b98 & 0x20;
    q = p1 + 1;
    if (mode) {
        f_16b930(mat);
        f_163bf8(d_1c6b78, d_1c6b7c, p2, mat);
    }
    {
    int minY, maxX, minX, maxY;

    minX = minY = 0x7fffffff;
    maxX = maxY = 0x80000000;
    dst = d_1c6b44;
    i = n + 1;
    goto loop_test;
loop_body:
    {
        unsigned char *a;
        unsigned i2;
        int *b;
        a = (unsigned char *)arrB + U16(q,0) * 12;
        i2 = U16(a,0);
        b = (int *)((char *)arrA + i2 * 12);
        q++;
        if (mode) {
            f_16cf6a(vec, b, mat);
            dst[0] = vec[0];
            dst[1] = vec[2];
        } else {
            dst[0] = b[0];
            dst[1] = b[2];
        }
        if (dst[0] < minX) minX = dst[0];
        if (dst[0] > maxX) maxX = dst[0];
        if (dst[1] < minY) minY = dst[1];
        if (dst[1] > maxY) maxY = dst[1];
        dst += 4;
    }
loop_test:
    if (--i != 0) goto loop_body;
    if (minX > d_1c6b64) return 0;
    if (maxX < d_1c6b68) return 0;
    if (minY > d_1c6b60) return 0;
    if (maxY < d_1c6b6c) return 0;
    rec = d_1c6b48;
    W(rec,4) = 0;
    W(rec,2) = n;
    I(rec,0x28) = (int)d_1c6b44;
    I(rec,0x2c) = (int)d_1c6b44;
    I(rec,0x30) = (int)d_1c6b44;
    W(rec,6) = 0;
    idx = U16(p1,0x24);
    src = (int *)((char *)I(node,0x3c) + idx * 12);
    *(E12 *)(rec + 0x1c) = *(E12 *)src;
    I(rec,0xc) = d_1c6b98;
    I(rec,0x10) = 0;
    I(rec,0x14) = 0;
    I(rec,0x18) = d_1a9afc;
    *(E16 *)dst = *(E16 *)d_1c6b44;
    return 1;
    }
}


//@ f_14e4a4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet nach dem Befüllen eines Kollisionsdatensatzes (d_1c6b48) die Schreibzeiger im
 *   Kollisionspuffer (d_1c6b48 += 0x38, d_1c6b44 += a * 4) auf den nächsten freien Slot weiter, solange die
 *   Maximalzahl von 150 Polygonen (d_1a9a10 < 0x96) und 2000 Eckpunkten (d_1c6b70 < 2000) nicht überschritten
 *   wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 1, wenn noch Platz für weitere Kollisionspolygone vorhanden ist, sonst 0.
 * - Wichtige Variablen: d_1a9a10 (Anzahl gesammelter Kollisionspolygone), d_1c6b70 (Anzahl belegter Eckpunkte im
 *   Pool).
 === Ende Beschreibung === */
int f_14e4a4(void)
{
    int a, b, r;
    if (d_1a9a10 < 0x96) {
        a = (U16(d_1c6b48,2) + 1) + (U16(d_1c6b48,4) + 1) + (U16(d_1c6b48,6) + 1);
        b = d_1c6b70 + a;
        if (b < 2000) {
            d_1c6b44+=a*4;
            d_1c6b48+=0x38;
            r=1;
            d_1c6b70=b;
            d_1a9a10+=r;
        } else r=0;
    } else r=0;
    return r;
}

//@ f_14e520
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet den 2D-Schnittpunkt p5 zweier unendlicher Geraden, die durch Aufpunkt p1 mit
 *   Richtungsvektor p2 sowie Aufpunkt p3 mit Richtungsvektor p4 gegeben sind. Wird für das Verschneiden
 *   verschobener Polygonkanten in f_14e5c8 verwendet.
 * - Eingaben: p1, p2 (erste Gerade: Punkt und Richtung), p3, p4 (zweite Gerade: Punkt und Richtung), p5
 *   (Ausgabe-2D-Punkt).
 * - Rückgabewert: 1, wenn die Geraden nicht parallel sind und ein Schnittpunkt berechnet wurde, sonst 0.
 * - Wichtige Variablen: num, den (Zähler und Nenner des 2D-Kreuzprodukts f_16d3b7), t (Schnittparameter).
 === Ende Beschreibung === */
int fxdiv831(int a, int b);
#pragma aux fxdiv831 = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm [edx] [ebx] value [eax] modify exact [eax edx]
int fxmul831(int a, int b);
#pragma aux fxmul831 = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] value [eax] modify exact [eax edx]
int f_14e520(int *p1, int *p2, int *p3, int *p4, int *p5)
{
    int c0 = p3[0] - p1[0];
    int c1 = p3[1] - p1[1];
    int num = f_16d3b7(c0, p4[1], c1, p4[0]);
    int den = f_16d3b7(p2[0], p4[1], p4[0], p2[1]);
    if (abs(den) > abs(num >> 15)) {
        int t = fxdiv831(num, den);
        p5[0] = p1[0] + fxmul831(t, p2[0]);
        p5[1] = p1[1] + fxmul831(t, p2[1]);
        return 1;
    }
    return 0;
}

//@ f_14e5c8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt zum aktuellen Kollisionspolygon (d_1c6b48) einen nach außen bzw. innen um den
 *   Kollisionsabstand dist verschobenen 2D-Umriss. Bei p1 == 1 werden die Kanten um den Spielerradius (d_1a9afc
 *   bzw. d_1a9b20) entlang ihrer nach außen zeigenden Normalen (nx, ny) für die Zylinder-Kollision nach außen
 *   versetzt (+0x2c); bei p1 != 1 wird ein leicht verkleinerter Innenumriss (+0x30) durch Geradenschnitt
 *   (f_14e520) benachbarter verschobener Kanten konstruiert.
 * - Eingaben: p1 (1 = aufgeweiteter Außenumriss in +0x2c, 3 = verschobener Innen-/Schnittrand in +0x30).
 * - Rückgabewert: 1 bei Erfolg (out_cnt >= 3), sonst 0.
 * - Wichtige Variablen: cx, cy (Schwerpunkt des Polygons zur Orientierung der Normalen), nx, ny (normierter
 *   2D-Kanten-Normalenvektor), dist (Versatzabstand).
 === Ende Beschreibung === */
int fxdiv831_b(int a, int b);
#pragma aux fxdiv831_b = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm [edx] [ebx] value [eax] modify exact [eax ebx edx]
struct V2_14e5c8 { int x, y; };
struct V4_14e5c8 { int x, y, z, w; };
struct LOC_14e5c8 {
    struct V2_14e5c8 d_cur;
    struct V2_14e5c8 p_prev;
    struct V2_14e5c8 d_prev;
    struct V2_14e5c8 p_cur;
};
int f_14e5c8(int p1)
{
    struct LOC_14e5c8 s;
    struct V4_14e5c8 *v_last;
    int n;
    int i;
    int cx;
    int cy;
    int ry;
    int rx;
    int out_cnt = 0;
    int dist;
    struct V4_14e5c8 *v;
    struct V4_14e5c8 *out;
    int weight;
    int len;
    int nx, ny;

    if (d_1c6b48 == 0) return 0;
    n = U16(d_1c6b48, 2);
    if (n < 1) return 0;
    {
        int n3;
        n3 = n << 2;
        n3 -= n;
        if (2000 - (n3 + 1) <= d_1c6b70) return 0;
    }
    if (p1 == 1) {
        if ((I(d_1c6b48, 0xc) & 0xa) == 8)
            dist = d_1a9b20;
        else
            dist = d_1a9afc;
        I(d_1c6b48, 0x18) = dist;
    } else {
        dist = 0xcccc - d_1a9afc;
    }
    weight = d_1a9a74 / n;
    v = (struct V4_14e5c8 *)I(d_1c6b48, 0x28);
    cx = fxmul831(weight, v->x);
    cy = fxmul831(weight, (v++)->y);
    for (i = 1; i < n; i++, v++) {
        cx += fxmul831(weight, v->x);
        cy += fxmul831(weight, v->y);
    }
    I(d_1c6b48, 0x10) = cx;
    I(d_1c6b48, 0x14) = cy;
    v = (struct V4_14e5c8 *)I(d_1c6b48, 0x28);
    out = (struct V4_14e5c8 *)(n << 4);
    out = (struct V4_14e5c8 *)((int)out + 0x10);
    out = (struct V4_14e5c8 *)((int)out + (int)v);
    out_cnt = 0;
    if (p1 == 1) {
        if (U16(d_1c6b48, 4) != 0) return 0;
        if (U16(d_1c6b48, 6) > 0)
            out += U16(d_1c6b48, 6) + 1;
        I(d_1c6b48, 0x2c) = (int)out;
    } else {
        if (U16(d_1c6b48, 6) != 0) return 0;
        if (U16(d_1c6b48, 4) > 0)
            out += U16(d_1c6b48, 4) + 1;
        I(d_1c6b48, 0x30) = (int)out;
    }
    v_last = &v[n - 1];
    rx = v_last->x - cx;
    ry = v_last->y - cy;
    rx >>= 5;
    ry >>= 5;
    weight = v->x;
    weight -= v_last->x;
    s.d_cur.x = weight;
    s.d_cur.y = (v->y - v_last->y) >> 5;
    s.d_cur.x >>= 5;
    weight = s.d_cur.x;
    len = f_16d3d0(f_16d33f(weight, weight, s.d_cur.y, s.d_cur.y));
    if (len > 0) {
        ny = fxdiv831_b(s.d_cur.x, len);
        nx = -fxdiv831_b(s.d_cur.y, len);
        if (f_16d33f(rx, nx, ry, ny) < -0x28f) {
            nx = -nx;
            ny = -ny;
        }
    } else {
        nx = 0;
        ny = 0;
    }
    s.p_cur.x = v_last->x + fxmul831(dist, nx);
    s.p_cur.y = v_last->y + fxmul831(dist, ny);
    for (i = 0; i < n; i++, v++) {
        s.p_prev = s.p_cur;
        s.d_prev = s.d_cur;
        rx = (rx & 0) ? 0 : rx; // Ternär-Anker hält Register- und Stack-Slot-Zuordnung von rx in der Schleife
        ry = (ry & 0) ? 0 : ry; // Ternär-Anker hält Register- und Stack-Slot-Zuordnung von ry in der Schleife
        rx = v[0].x - cx;
        ry = v[0].y - cy;
        rx >>= 5;
        ry >>= 5;
        weight = v[1].x;
        weight -= v[0].x;
        s.d_cur.x = weight;
        s.d_cur.y = (v[1].y - v[0].y) >> 5;
        s.d_cur.x >>= 5;
        weight = s.d_cur.x;
        len = f_16d3d0(f_16d33f(weight, weight, s.d_cur.y, s.d_cur.y));
        if (len >= 0x147) {
            ny = (ny & 0) ? 0 : ny; // Ternär-Anker steuert Registervergabe für ny vor fxdiv831_b
            nx = (nx & 0) ? 0 : nx; // Ternär-Anker steuert Registervergabe für nx vor fxdiv831_b
            ny = fxdiv831_b(s.d_cur.x, len);
            nx = -fxdiv831_b(s.d_cur.y, len);
            if (f_16d33f(rx, nx, ry, ny) < -0x28f) {
                nx = -nx;
                ny = -ny;
            }
            s.p_cur.x = v[0].x + fxmul831(dist, nx);
            s.p_cur.y = v[0].y + fxmul831(dist, ny);
            if (p1 == 1) {
                out[0].x = s.p_cur.x;
                out[0].y = s.p_cur.y;
                out[0].z = nx;
                out[0].w = ny;
                out[1].x = v[1].x + fxmul831(dist, nx);
                out[1].y = v[1].y + fxmul831(dist, ny);
                out[1].z = nx;
                out[1].w = ny;
                out += 2;
                out_cnt += 2;
            } else {
                if (f_14e520((int *)&s.p_prev, (int *)&s.d_prev, (int *)&s.p_cur, (int *)&s.d_cur, (int *)out)) {
                    out->z = nx;
                    out->w = ny;
                    out++;
                    out_cnt++;
                }
            }
        }
    }
    if (out_cnt < 3) return 0;
    if (p1 == 1) {
        *out = *(struct V4_14e5c8 *)I(d_1c6b48, 0x2c);
        W(d_1c6b48, 4) = out_cnt;
    } else {
        *out = *(struct V4_14e5c8 *)I(d_1c6b48, 0x30);
        W(d_1c6b48, 6) = out_cnt;
    }
    out_cnt = (out_cnt & 0) ? 0 : out_cnt; // Ternär-Anker hält out_cnt im erwarteten Register bis zum Funktionsende
    return 1;
}








//@ f_14ea94
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft in der Horizontalebene, ob der 2D-Punkt (p3, p4) innerhalb des Kollisionspolygons p1
 *   liegt. Je nach Modus p2 wird der aufgeweitete Umriss (p2 == 1, inklusive Abstands-Kreisprüfung um die
 *   Original-Eckpunkte für abgerundete Ecken), das Originalpolygon (p2 == 2) oder der innere Umriss (p2 == 3)
 *   getestet.
 * - Eingaben: p1 (Kollisionsdatensatz), p2 (Umriss-Auswahl 1, 2 oder 3), p3 (X-Koordinate), p4
 *   (Z-/Y-Koordinate).
 * - Rückgabewert: 1, wenn der Punkt im gewählten Umriss (bzw. Eckkreis bei p2 == 1) liegt, sonst 0.
 * - Wichtige Variablen: min, max (horizontale Schnittgrenzen auf Höhe p4).
 === Ende Beschreibung === */
// 64-Bit-Muldiv als Festkomma-Helfer in Originalform (wie fxmul831/fxdiv831 oben);
// Watcom 10.6 kennt keinen 64-Bit-Typ, das Original hat hier inline "imul ebx"/"idiv ecx".
int mdv(int a, int b, int c);
#pragma aux mdv = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] value [eax] modify exact [eax edx]
struct PVertex { int x, y, z, w; };

int f_14ea94(char *p1, unsigned p2, int p3, int p4)
{
    struct PVertex *v;
    int n, i, min, max, value;
    int m, j, r;

    if (p1 == 0) return 0;
    switch (p2) {
    case 1:
        n = U16(p1, 4);
        v = (struct PVertex *)I(p1, 0x2c);
        break;
    case 3:
        n = U16(p1, 6);
        v = (struct PVertex *)I(p1, 0x30);
        break;
    case 2:
    default:
        n = U16(p1, 2);
        v = (struct PVertex *)I(p1, 0x28);
        break;
    }
    min = 0x7fffffff;
    max = (int)0x80000000;
    for (i = 0; i < n; i++, v++) {
        if (((v[0].y <= p4 && p4 <= v[1].y) || (v[1].y <= p4 && p4 <= v[0].y)) && v[0].y != v[1].y) {
            value = v[0].x + mdv(p4 - v[0].y, v[1].x - v[0].x, v[1].y - v[0].y);
            if (value < min) min = value;
            if (value > max) max = value;
        }
    }
    if (min <= p3 && p3 <= max) return 1;
    if (p2 != 1) return 0;
    m = U16(p1, 2);
    v = (struct PVertex *)I(p1, 0x28);
    r = fxmul831(I(p1, 0x18), I(p1, 0x18));
    for (j = 0; j < m; j++, v++) {
        int dx = abs(v[0].x - p3);
        int dy = abs(v[0].y - p4);
        if (dx <= I(p1, 0x18) && dy <= I(p1, 0x18) && f_16d33f(dx, dx, dy, dy) < r)
            return 1;
    }
    return 0;
}



//@ f_14ec24
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hilfsfunktion für die abgerundete Ecken-Kollision (f_14eeac): Prüft, ob ein auf dem
 *   Kollisionskreis um die Polygonecke p4 liegender Schnittpunkt (p1, p2) tatsächlich in dem zwischen den beiden
 *   angrenzenden Kanten-Normalen (p5 und p6) aufgespannten Außenkeil der Ecke liegt.
 * - Eingaben: p1, p2 (Testpunkt X, Y), p3 (quadrierter Radius), p4 (Eckpunkt), p5, p6 (verschobene
 *   Nachbarkanten), p7 (Kollisionsdatensatz mit Schwerpunkt in p7[4..5]).
 * - Rückgabewert: 1, wenn der Punkt im gültigen Ecksektor liegt, sonst 0.
 * - Wichtige Variablen: L.q (viereckiges Sektorpolygon um die Ecke), L.xs (sortierte Scanline-Schnittpunkte auf
 *   Höhe p2).
 === Ende Beschreibung === */
// BLIND-Neubau aus Original-ASM (DeepSeek 2682)
int md2682(int a, int b, int c);
#pragma aux md2682 = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] value [eax] modify [edx];
typedef struct { int x, y, z, w; } QV2682;
struct LOC2682 { int xs[20]; QV2682 q[5]; };
int f_14ec24(int p1, int p2, int p3, QV2682 *p4, QV2682 *p5, QV2682 *p6, int *p7)
{
    struct LOC2682 L;
    QV2682 *v;
    int *xp;
    int x,y,len,n,step,j,pass,t,hit,lim;
    int edge;
       
    y=p6->y; y-=p5->y; y>>=2;
    x=p5->x; x-=p6->x; x>>=2;
    len=f_16d3b7(y,y,-x,x);
    if (len<=0) return 1;
    lim=p3*2;
    while(len<lim) {len<<=2; x+=x; y+=y;}
    if(f_16d3b7(y,p4->x-p7[4],-x,p4->y-p7[5])<0) {y=-y; x=-x;}
    v=L.q;
    v[0].x=p4->x;
    v[0].y=p4->y;
    v[1].x=p4->x+2*(p5->x-v[0].x);
    v[1].y=p4->y+2*(p5->y-v[0].y);
    v[2].x=p4->x+y;
    v[2].y=p4->y+x;
    { int delta=p6->x-v[0].x; delta+=delta; v[3].x=p4->x+delta; }
    { int delta=p6->y-v[0].y; delta+=delta; v[3].y=p4->y+delta; }
    v[4]=v[0];
    n=0; xp=L.xs; edge=n;
    do {
        if((v->y<p2 && v[1].y>p2) || (v[1].y<p2 && v->y>p2)) {
            if(v->y!=v[1].y && n<20) {
                int den,dx,rel; dx=v[1].y-v->y; den=dx; dx=v[1].x; dx-=v->x; rel=p2; rel-=v->y;
                dx=md2682(rel,dx,den); den=v->x; dx+=den; *xp++=dx;
                ++n;
            }
        }
        step=edge; ++step; ++v; edge=step;
    } while(step<4);
    if(n==0) return 0;
    for(pass=n;pass>0;--pass) {
        xp=L.xs+1;
        for(j=1;j<pass;j++,xp++) {
            if(xp[-1]>xp[0]) {t=xp[0]; xp[0]=xp[-1]; xp[-1]=t;}
        }
    }
    j=1; xp=L.xs;
    if(j<n) {
        do {
            if(xp[0]<p1 && xp[1]>p1 && (j&1)) return 1;
            ++j; ++xp;
        } while(j<n);
    }
    return 0;
}
