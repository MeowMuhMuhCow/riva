/* === Beschreibung (Katalog) ===
 * Einheit gz_071bd0 (071bd0 - 072610)
 *
 * Überblick
 * Diese Einheit umfasst die Berechnung und Verteilung der Abenteuerpunkte nach einem gewonnenen Kampf (f_071bd0)
 * sowie grundlegende Geometrie-, Raster- und Blickrichtungsfunktionen für das 24 x 24-Kampffeld (f_071e20 bis
 * f_072440).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/11 gleich (suche.py 26.10.2026, Basis gz_071bd0_P1.CPP)
// gz_071bd0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x071BD0-0x072610
#include <string.h>
#include <stdlib.h>
#include "RIVAMEM.H"

struct X { char pad[0x73]; };
typedef signed char G;
#define FE (-2)
extern char d_1bfaec;
unsigned char f_0cf910(X *p);
unsigned char f_0cfa90(X *p);
signed char f_0cfcc0(X *p);
char f_0d0040(X *p);
char f_0cff80(X *p);
int f_038c80(int p);
int f_0391b0(int p, int q);


void f_040780(int p, int q);

signed char f_043490(X *p);
short f_043c10(X *p);
short f_043c30(X *p);
signed char f_0cfc70(X *p);
char f_0cfd20(X *p);
short f_0d01c0(X *p);
short f_0d01e0(X *p);
X *f_0d0910(X *p);
char f_0d54c0(X *p);
int f_069460();
extern char d_1bd928;
extern G *d_1bd984;
extern X *d_1c2ed4;
extern char d_1c12a0[];
extern int d_1c0004;
//@ f_071bd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet nach einem gewonnenen Kampf die gesamten Abenteuerpunkte (AP) für alle besiegten
 *   Gegner in d_1c2ed4, markiert erstmalig besiegte Gegnertypen in der Erstbegegnungstabelle d_1c12a0 und
 *   verteilt die AP gleichmäßig (aufgerundet auf ein Vielfaches der Teilnehmerzahl) über f_040780 an alle
 *   lebenden, nicht geflohenen Helden der Gruppe. Wurde ein Monster bereits in einem früheren Kampf besiegt
 *   (d_1c12a0[typ] != 0), gibt es auf höherem Schwierigkeitsgrad oder ab Monsterstufe 10 nur noch ein Zehntel
 *   (mindestens 1 AP) seines Grundwerts.
 * - Eingaben und Rückgabe: Empfängt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1c2ed4 enthält die bis zu 20 Gegner des Kampfes, d_1c12a0 speichert als
 *   Byte-Array je Monster-ID, ob dieser Gegnertyp schon einmal besiegt wurde, und d_1bfaec ist der
 *   Schwierigkeitsgrad.
 === Ende Beschreibung === */
void f_071bd0()
{
    signed char b[40];
    short j; short i;
    int tot;
    short k;
    int cnt;
    int r;
    short v;
    X *p;
    X *q;
    memset(b, 0, 0x28);
    tot = 0;
    for (i = 0; i < (short)20; i = (short)i + 1) {
        p = d_1c2ed4;
        p += (short)i;
        if (f_0cf910(p)) {
            f_0cf910(p);
            if (f_0d0040(p) && f_0cff80(p)) {
                tot++;
            } else {
                j = 0;
                for (k = 0; (short)k < (short)20; k++) {
                    if (f_0cf910(p) == b[(short)k * 2]) {
                        j = 1;
                        b[(short)k * 2 + 1]++;
                        break;
                    }
                }
                short scan = j;
                if (!(short)scan) {
                    scan = (scan & 0) ? 0 : scan; // Haelt scan als eigenes Web fuer die Registervergabe
                    while (b[(short)scan * 2]) scan = scan + 1;
                    b[(short)scan * 2] = f_0cf910(p);
                    b[(short)scan * 2 + 1] = 1;
                }
                signed char db = d_1bfaec;
                if (db == 0 && f_0cfcc0(p) < 10) {
                add_total:
                    tot += f_0cfa90(p);
                } else {
                    if (!d_1c12a0[f_0cf910(p)]) goto add_total;
                    v = f_0cfa90(p) / 10;
                    tot += (!(short)v) ? 1 : (short)v;
                }
            }
        }
    }
    for (short m = 0; m < (short)20; m++) {
        q = d_1c2ed4; q += (short)m;
        if (f_0cf910(q)) d_1c12a0[f_0cf910(q)] = 1;
    }
    r = f_038c80(d_1c0004);
    cnt = 0;
    do {
        if (!((char)(f_042470((struct hero *)(r)))) && !((char)(f_042640((struct hero *)(r))))) cnt++;
        r = f_0391b0(d_1c0004, r);
    } while (r != f_038c80(d_1c0004));
    if ((short)cnt) {
        if (tot < (short)cnt) tot = (short)cnt;
        else while (tot % (short)cnt) tot++;
        r = f_038c80(d_1c0004);
        do {
            if (!((char)(f_042470((struct hero *)(r)))) && !((char)(f_042640((struct hero *)(r))))) f_040780(r, (short)(tot / (short)cnt));
            r = f_0391b0(d_1c0004, r);
        } while (r != f_038c80(d_1c0004));
    }
}
//@ f_071e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Manhattan-Distanz (|a - c| + |b - d|) zwischen zwei Feldern (a, b) und (c, d)
 *   auf dem Kampfraster.
 * - Eingaben und Rückgabe: Empfängt die Koordinaten a, b, c und d (short) und gibt die Summe der absoluten
 *   Koordinatendifferenzen (int) zurück.
 * - Wichtige Variablen: Verwendet ausschließlich die übergebenen Registerparameter.
 === Ende Beschreibung === */
int f_071e20(short a, short b, short c, short d)
{
    return abs(a - c) + abs(b - d);
}
//@ f_071e50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Feldwert v (z. B. Helden-ID, Gegner-ID, Hindernis 0xfe oder Leere 0) an die
 *   Koordinate (x, y) in das globale Kampfraster d_1bd984, sofern y im Bereich 0..23 (0x18) und x im Bereich
 *   0..24 (0x19) liegt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, die Spalte x, die Zeile y sowie den zu schreibenden
 *   Bytewert v und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Greift direkt auf d_1bd984 + y * 25 + x zu.
 === Ende Beschreibung === */
void f_071e50(int p1, int x, int y, int v)
{
    int ix, iy;
    if ((short)y >= 0 && (short)y < (short)0x18 && (short)x >= 0 && (short)x < (short)0x19) *(d_1bd984 + (short)y * 0x19 + (short)x) = v;
}
//@ f_071e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht auf dem 24 x 24-Kampfraster d_1bd984 nach dem ersten Feld, das die Kennung c (z. B.
 *   held_idx + 1 oder monster_idx + 10) enthält, und schreibt dessen Spalte und Zeile in *px und *py.
 * - Eingaben und Rückgabe: Empfängt die gesuchte Kennung c (unsigned char) sowie die Ausgabezeiger px und py
 *   (short *) und gibt 1 bei Fund oder 0 bei Nichtfund zurück.
 * - Wichtige Variablen: Ruft während der Suche bei gesetztem Echtzeit-/Animationsflag d_1bd928 regelmäßig
 *   f_069460 auf, damit Kampfanimationen flüssig weiterlaufen.
 === Ende Beschreibung === */
int f_071e90(G c, short *px, short *py)
{
    for (*px = 0; *px < 0x18; (*px)++) {
        if (d_1bd928) f_069460();
        for (*py = 0; *py < (short)0x18; (*py)++) {
            G *row = d_1bd984 + (short)*py * 0x19;
            if (row[*px] == c) return 1;
        }
    }
    return 0;
}
//@ f_071f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Kampfrasterkoordinate (x, y) außerhalb des gültigen 24 x 24-Spielfelds (0..23)
 *   liegt oder durch ein unpassierbares Hindernis (0xfe) blockiert ist.
 * - Eingaben und Rückgabe: Empfängt die Koordinaten x und y (int) und gibt 1 zurück, wenn das Feld blockiert
 *   oder außerhalb des Rasters ist, sonst 0.
 * - Wichtige Variablen: Liest den Rastereintrag *(d_1bd984 + y * 25 + x) und vergleicht ihn mit 0xfe.
 === Ende Beschreibung === */
int f_071f20(int x, int y)
{
    int ix, iy;
    ix = (short)x; iy = y;
    if (ix > 0x17 || ix < 0 || (short)iy > 0x17 || (short)iy < 0 || *(d_1bd984 + (short)iy * 0x19 + ix) == (G)FE) return 1;
    return 0;
}
//@ f_071f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Drehrichtung und Schrittzahl zwischen einer aktuellen Blickrichtung a (0..3) und
 *   einer Zielblickrichtung b (0..3) für Animationsdrehungen im Kampf.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 sowie Startrichtung a und Zielrichtung b (short) und gibt
 *   1 (90 Grad im Uhrzeigersinn), 2 (180-Grad-Wende) oder -1 (90 Grad gegen den Uhrzeigersinn) zurück.
 * - Wichtige Variablen: Arbeitet rein arithmetisch modulo 4 auf den Richtungsindizes 0..3.
 === Ende Beschreibung === */
int f_071f70(int p1, short a, short b)
{
    int r = 1;
    a = a + r;
    if (a == 4) a = 0;
    if (a != b) {
        a++;
        r = 2;
        if (a == 4) a = 0;
        if (a != b) r = -1;
    }
    return r;
}
//@ f_071fb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt zu einer Blickrichtung s (0..3) die entgegengesetzte Blickrichtung ((s + 2) % 4) zurück,
 *   etwa um das hintere Feld eines zweifeldrigen Gegners oder die Blickrichtung eines getroffenen Opfers zu
 *   bestimmen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und die Richtung s (short) und gibt die Gegenrichtung
 *   (0->2, 1->3, 2->0, 3->1) als int zurück.
 * - Wichtige Variablen: Keine externen Variablen.
 === Ende Beschreibung === */
int f_071fb0(int p1, short s)
{
    if (s == 0) return 2;
    if (s == 1) return 3;
    return s != 2;
}
//@ f_071fe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt für einen Helden p im Nahkampf die Blickrichtung (0..3) zu seinem aktuell
 *   anvisierten Ziel (f_0432b0), wenn beide auf derselben Zeile oder Spalte stehen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Heldenzeiger p und gibt die berechnete
 *   Blickrichtung (0..3) als short zurück.
 * - Wichtige Variablen: Sucht die Rasterposition des Ziels und des Helden (f_0d54c0(p) + 1) in d_1bd984 und
 *   behält bei identischer Position die bisherige Richtung f_043490(p) bei.
 === Ende Beschreibung === */
short f_071fe0(int p1,X *p){
struct Coordinates491{static int first(G c,short &px,short &py){
    for (px=0;px<0x18;(px)++) {
        if(d_1bd928)f_069460();
        for (py=0;py<(short)0x18;(py)++) {
            // Erzwingt erneutes Laden von d_1bd984 aus dem Speicher je Schleifendurchlauf
            int offset491=(short)py*0x19;G *base491=*(G * volatile*)&d_1bd984;G *row=base491+offset491;
            if(row[px]==c)return 1;
        }
    }
    return 0;
}
static int find(G c,short &px,short &py){
    for (px=0;px<0x18;(px)++) {
        if(d_1bd928)f_069460();
        for (py=0;py<(short)0x18;(py)++) {
            G *row=d_1bd984+(short)py*0x19;
            if(row[px]==c)return 1;
        }
    }
    return 0;
}};
short y2,x1,x2,y1;
if(d_1bd928)f_069460();
Coordinates491::first(((char)(f_0432b0((struct hero *)(p)))),x1,y1);
Coordinates491::find((G)(f_0d54c0(p)+1),x2,y2);
if(x2==x1){
 if(y1==y2)return f_043490(p);
 return y1<y2?3:1;
}
return x1<x2?0:2;
}
//@ f_072110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt analog zu f_071fe0 für ein Monster p die Blickrichtung (0..3) zu seinem aktuellen
 *   Angriffsziel (f_0cfd20(p)).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p und gibt die Blickrichtung (0..3)
 *   als short zurück.
 * - Wichtige Variablen: Bestimmt den Monsterindex idx im Array d_1c2ed4 und sucht im Raster d_1bd984 nach idx +
 *   10 sowie nach der Zielkennung f_0cfd20(p).
 === Ende Beschreibung === */
short f_072110(int p1,X*p){
struct Coordinates491{static int find(G c,short &px,short &py){
 for(px=0;px<0x18;px++){
  if(d_1bd928)f_069460();
  for(py=0;py<(short)0x18;py++){
   G *row=d_1bd984+(short)py*0x19;
   if(row[px]==c)return 1;
  }
 }
 return 0;
}};
short x2,x1,y2,y1;
if(d_1bd928)f_069460();
Coordinates491::find(f_0cfd20(p),x1,y1);
unsigned char idx=0;X*q=p;X*candidate=d_1c2ed4;
// Haelt d_1c2ed4 in der Registerfolge beim Verlassen der Suchschleife
for(;idx<0x14;++idx,candidate=d_1c2ed4+idx){if(q==candidate){d_1c2ed4=((int)d_1c2ed4&0)?0:d_1c2ed4;goto index_found491;}}idx=0;index_found491:;
Coordinates491::find((G)(idx+10),x2,y2);
if(x2==x1){if(y1==y2)return f_0cfc70(p);if(y1<y2)return 3;return 1;}if(x1<x2)return 0;return 2;
}
//@ f_0722a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für einen Helden p bei beliebiger (auch diagonaler oder entfernter) Lage des Ziels
 *   (oder Zielpunkts f_043c10/f_043c30, z. B. bei Fernkampf oder Zaubern) anhand der Quadranten- und
 *   Achsendifferenzen die passende Blickrichtung (0..3).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Heldenzeiger p und gibt die Blickrichtung (0..3)
 *   als short zurück.
 * - Wichtige Variablen: Vergleicht die Summen und Differenzen der Rasterkoordinaten (i1, j1) des Ziels und (i2,
 *   j2) des Helden.
 === Ende Beschreibung === */
short f_0722a0(int p1,X*p){
struct Coordinates491{static int find(G c,short &px,short &py){for(px=0;px<0x18;px++){if(d_1bd928)f_069460();for(py=0;py<(short)0x18;py++){G *row=d_1bd984+(short)py*0x19;if(row[px]==c)return 1;}}return 0;}};
short j1,i1,j2,i2;G c;short r;
if(d_1bd928)f_069460();
if(((char)(f_0432b0((struct hero *)(p))))){Coordinates491::find(((char)(f_0432b0((struct hero *)(p)))),i1,j1);}else{i1=f_043c10(p);j1=f_043c30(p);}
c=((int)p&0)?0:f_0d54c0(p);c++;Coordinates491::find(c,i2,j2); // Haelt p ueber den Aufruf hinweg im Register
    if (i2 == i1 && j2 == j1) {
        r = f_043490(p);
    } else {
        int a,e,b,d; a=i1; b=j1; e=i2; d=j2;
        if (a + b <= e + d) {
            if (j1 >= j2 || e - a > d - b) return 2;
            return 1;
        }
        if (i1 <= i2 || b - d > a - e) return 3;
        r = 0;
    }
    return r;
}
//@ f_072440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet analog zu f_0722a0 für ein Monster p bei Fernkampf- oder Zauberangriffen die
 *   passende Blickrichtung (0..3) zum Zielobjekt oder zur Zielkoordinate (f_0d01c0/f_0d01e0).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p und gibt die Blickrichtung (0..3)
 *   als short zurück.
 * - Wichtige Variablen: Nutzt f_0d0910(p) zur Unterscheidung zwischen Koordinatenziel und Figuren-Zielkennung
 *   f_0cfd20(p).
 === Ende Beschreibung === */
short f_072440(int p1, X *p)
{
    struct Coordinates921 {
        static unsigned char object_index(X *searched) {
            unsigned char idx=0;
            X *candidate=d_1c2ed4;
            for (;idx<0x14;++idx,candidate=d_1c2ed4+idx) {
                if (searched==candidate) return idx;
            }
            return 0;
        }
        static int find(G c, short &x, short &y) {
            for (x=0; x<0x18; x++) {
                if (d_1bd928) f_069460();
                for (y=0; y<(short)0x18; y++) {
                    G *row=d_1bd984+(short)y*0x19;
                    if (row[x]==c) return 1;
                }
            }
            return 0;
        }
    };
    short i2, j1, i1, j2;
    short r;
    if (d_1bd928) f_069460();
    X *q=f_0d0910(p);
    if (q==p) {
        i1=f_0d01c0(q)&0xff;
        j1=f_0d01e0(p)&0xff;
    } else {
        Coordinates921::find(f_0cfd20(p),i1,j1);
    }
    unsigned char idx=Coordinates921::object_index(p);
    Coordinates921::find((G)(idx+10),i2,j2);
    if (i2==i1 && j2==j1) {
        r=f_0cfc70(p);
    } else {
        int a,d,e,b;
        a=i1; b=j1; e=i2; d=j2;
        if (a+b<=e+d) {
            if (j1>=j2 || e-a>d-b) return 2;
            return 1;
        }
        if (i1<=i2 || b-d>a-e) return 3;
        r=0;
    }
    return r;
}
