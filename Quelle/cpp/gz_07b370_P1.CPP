/* === Beschreibung (Katalog) ===
 * Einheit gz_07b370 (07b370 - 07cb00)
 *
 * Überblick
 * Die Einheit gz_07b370 umfasst 15 Funktionen für das Kampfraster, die Kampfleiste und die gegnerische Zauber-
 * und Fernkampf-KI: das Setzen von Figuren und mehrfeldrigen Hindernissen im Kampfraster (f_07b370, f_07b580),
 * das Positionieren der Feldmarkierung (f_07b5e0), das Aktualisieren der Helden- und Gegner-Statusbalken am
 * rechten Kampfbildschirmrand (f_07b740, f_07b790, f_07b7e0), die Kampfunfähigkeitsmeldung nach Treffern
 * (f_07bd30) sowie die KI-Zielprüfung und -Auswahl für Monsterzauber und Monsterfernkampf (f_07be00, f_07beb0,
 * f_07c1a0, f_07c2a0, f_07c900).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra700: Originalreihenfolge; ein Restbefehl weniger, kein schlechterer Nachbar.
// P3 10/15 gleich (suche.py 25.10.2026, Basis gz_07b370_P1.CPP)
// P2h 9/15 gleich
// gz_07b370.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07B370-0x07CB00
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
#pragma pack(1)
struct Dir { short x, y; };
struct R26 { short a, b, c; signed char pt[10][2]; };
struct E12 { char a; signed char b; char rest[10]; };
struct Node { int a; int b; };
struct Ob3c { int a; Node *q; char rest[0x34]; };
int f_069460();
int f_0773b0(int p1);
int f_072910(int p1);
/* KRUECKE: gemessene Registerwirkung (f_072910 sichert edx per push/pop; f_0cf930 schreibt nur al;
   f_149410 sichert ebx/ecx/esi/edi) - nur damit haelt Watcom p5 in cl ueber den Call wie im Original. */
#pragma aux f_072910 parm [eax] modify exact [eax];
int f_072a00(int p1);
int f_072b70(int p1);
int f_071e50(int p1, int p2, int p3, int p4);

int f_07b220(int p1);
int f_07eb30(int p1, int p2, void *p3, void *p4);
unsigned char f_07ec10(int p1, int p2);
int f_0bf730(void *p1, int p2);
char f_0cf910(int p1);
short f_0cfa10(int p1);
short f_0cfa50(int p1);
char f_0cfc90(int p1);
int f_0d4a60(int p1);
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
short f_1457e0(int p1);
int f_146dfa(void *p1, int p2);
extern Dir d_1a2734[];
extern E12 d_1a57e8[];
extern char *d_1bc8f0;
#define d_1bc8f0p ((char *)d_1bc8f0)
extern short d_1bd924;
extern char d_1bd928;
extern R26 *d_1bd944;
extern R26 *d_1bd948;
extern char *d_1bd984;
extern short d_1bda74;
extern int d_1bda78[7];
extern int d_1bda94[7];
extern int d_1c0004;
extern int d_1c2c64;
extern char *d_1c2ed4;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
void f_01e630(void *p1, short p2, short p3, short p4, short p5, short p6, int p7);
int f_038c80(int p1);
int f_0391b0(int p1, int p2);









short f_044e30(int p1);
int f_045080(int p1, int p2);

int f_0d49b0(int p1);



int f_1481a0(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_1483f0(int p1, int p2, int p3, int p4, int p5);
int f_148450(int p1, int p2, int p3, int p4, int p5);
extern int d_1a34e0;
extern int d_1bdbd4;
extern int d_1c2bcc;

signed char f_0cfbd0(int p1);
int f_0cfd30(int p1, int p2);
signed char f_0cfd20(int p1);
unsigned char f_084b40(int p1, int p2, int p3, int p4, int p5, int p6);
int f_071e90(int p1, short *p2, short *p3);
short f_071e20(int p1, int p2, int p3, int p4);
char f_0cfec0(int p1);
char f_074b40(int p1, int p2, int p3, int p4, int p5, int p6);
int f_07d080(int p1, int p2);
char f_0729c0(int p1);
int f_0cfbe0(int p1, int p2);
int f_0cfcf0(int p1, int p2);
signed char f_0cfd40(int p1);
int f_0d0910(int p1);
int f_0d08a0(int p1);
char f_0cfd70(int p1);
char f_0cffb0(int p1);
char f_0cfe30(int p1);
char f_0cfef0(int p1);
char f_0d0010(int p1);




short f_0cf9f0(int p1);
signed char f_0cfab0(int p1);
short f_149360(int p1, const char *p2);
short f_0de820(int p1);
extern short d_1a250a;
extern const char d_1a2814[];
extern const char d_1a2834[];
#define MAP(x,y) (*(d_1bd984 + (y) * 0x19 + (x)))
inline unsigned char getmap(int x, int y) { return *(d_1bd984 + y * 0x19 + x); }

//@ f_07b370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt ein Kampffeldobjekt, ein ein- oder zweifeldriges Monster oder ein mehrfeldriges
 *   Hindernis (p4 >= 0x32) an der Position (p2, p3) mit Blickrichtung p5 in das Kampfraster d_1bd984 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, die Koordinaten p2 (X) und p3 (Y), die
 *   Objektkennung p4 sowie die Blickrichtung p5 und gibt 1 bei erfolgreicher Platzierung zurück (bzw. 0, wenn
 *   das zweite Feld eines Großmonsters blockiert ist).
 * - Wichtige Variablen: Die Zeiger d_1bd948 und d_1bd944 verweisen auf die 10-Punkte-Formtabellen für Standard-
 *   und Spezialhindernisse, und d_1bd984 ist das 24 x 25-Kampfraster (wobei für das Hinterteil eines
 *   Großmonsters das Nachbarfeld vor der Bereichsprüfung gelesen wird; siehe Fehlerliste).
 === Ende Beschreibung === */
#define M2 ((char (*)[0x19])d_1bd984)
// BLIND: f_07b370 hier komplett neu aus dem Original-Assembler schreiben (orig.sh gz_07b370 f_07b370).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
int f_07b370(int p1, short p2, short p3, unsigned char p4, signed char p5)
{
    short i;
    signed char *pt;
    unsigned char k;

    if (p4 >= 0x32) {
        k = p4 - 0x32;
        i = 0;   /* Anweisung statt Deklarationsinit: verhindert Loop-Inversion */
        if (k >= 0x64) pt = d_1bd944[k - 0x64].pt[0];
        else pt = d_1bd948[k].pt[0];
        while (i < (short)10) {
            if (pt[i * 2] != -99)
                f_071e50(p1, (short)(p2 + pt[i * 2]), (short)(p3 + pt[i * 2 + 1]), p4);
            i++;
        }
    } else if (p4 >= 10) {
        if (f_072910((int)(d_1c2ed4 + (p4 - 10) * 0x73))) {
            if (((unsigned char)M2[p3 + d_1a2734[p5].y][p2 + d_1a2734[p5].x] == 0 ||
                 M2[p3 + d_1a2734[p5].y][p2 + d_1a2734[p5].x] == (char)0xfe) &&
                p3 + d_1a2734[p5].y >= 0 && p3 + d_1a2734[p5].y <= 0x17 &&
                p2 + d_1a2734[p5].x >= 0 && p2 + d_1a2734[p5].x <= 0x17)
                f_071e50(p1, (short)(p2 + d_1a2734[p5].x), (short)(p3 + d_1a2734[p5].y), (unsigned char)(p4 + 0x14));
            else return 0;
        }
    }
    if ((unsigned char)M2[p3][p2] == 0 || M2[p3][p2] == (char)0xfe || M2[p3][p2] == (char)0xfd)
        f_071e50(p1, p2, p3, p4);
    return 1;
}


//@ f_07b540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zähler d_1bda74 sowie die beiden 7-teiligen Kampfzustandstabellen d_1bda78 und
 *   d_1bda94 vollständig auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bda74 und die Arrays d_1bda78[7] sowie d_1bda94[7] verwalten temporäre
 *   Kampfeinträge für die bis zu sieben Gruppenmitglieder.
 === Ende Beschreibung === */
void f_07b540()
{
    short i;
    d_1bda74 = 0;
    for (i = 0; i < 7; i++) {
        d_1bda78[i] = 0;
        d_1bda94[i] = 0;
    }
}

//@ f_07b580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für ein Hindernis-Objekt mit dem relativen Index k, ob dessen Höhen- bzw.
 *   Durchlässigkeitsklasse (c) den Wert 0 oder 2 besitzt und somit Sichtlinie oder Geschosse durchlässt.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Kampfkontext p1 sowie den Hindernisindex k entgegen und gibt 1
 *   zurück, wenn das Hindernis überblickt bzw. überschossen werden kann, sonst 0.
 * - Wichtige Variablen: Für k < 100 wird in der Hindernistabelle d_1bd948[k] nachgeschlagen, für k >= 100 in
 *   d_1bd944[k - 100].
 === Ende Beschreibung === */
int f_07b580(int p1, short k)
{
    int r;
    r = 0;
    if (k >= (short)100) {
        if (d_1bd944[k - 100].c == (short)2 || d_1bd944[k - 100].c == (short)0) r = 1;
    } else {
        if (d_1bd948[k].c == (short)2 || d_1bd948[k].c == (short)0) r = 1;
    }
    return r;
}

//@ f_07b5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die aktuellen Rasterkoordinaten des Darstellungs-Knotens k und setzt das rote
 *   Auswahl- bzw. Markierungsfeld (p + 0x1f5) in der Darstellungsliste OList genau unter diese Kampffigur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf die Hauptkampfstruktur sowie die Knoten-ID k und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Byte p[0x293] speichert die Knoten-ID der neu eingefügten Bodenmarkierung, damit sie
 *   beim nächsten Figurenwechsel wieder entfernt werden kann.
 === Ende Beschreibung === */
void f_07b5e0(char *p, unsigned char k)
{
    char b;
    char a;
    f_07eb30((int)p + 0x39, k, &a, &b);
    p[0x1e] = 0;
    p[0x18] = a;
    p[0x19] = b;
    p[0x1f] = 0;
    p[0x20] = 6;
    p[0x24] = 0;
    *(int *)(p + 0x27) = 0;
    p[0x22] = 1;
    p[0x23] = 1;
    *(int *)(p + 0x2b) = *(int *)(p + 0x1f5);
    p[0x25] = 0xff;
    p[0x293] = f_07ec10((int)p + 0x39, -1);
}

//@ f_07b660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt per Zufall eines der derzeit lebenden und am Kampf teilnehmenden Monster aus d_1c2ed4
 *   aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den Zeiger auf die ausgewählte
 *   Monsterstruktur zurück.
 * - Wichtige Variablen: Die Variable d_1bd924 begrenzt den Zufallsbereich auf die tatsächlich im Kampf
 *   vorhandenen Monsterslots.
 === Ende Beschreibung === */
char *f_07b660()
{
    char *q;
    short n;
    do {
        n = f_1457e0(d_1bd924) - 1;
        q = d_1c2ed4 + n * 0x73;
        if (d_1bd928) f_069460();
    } while (!f_0cf910((int)q) || !f_0cfc90((int)q));
    return q;
}

//@ f_07b6b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für die diagonale Schritt- oder Schusslinien-Interpolation das Seitenverhältnis
 *   zwischen den beiden Achsenabständen p4 und p5 und schaltet das Richtungsflag *p2 um.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kontext p1, den Zeiger auf das Richtungsflag p2, den
 *   Ausgabezeiger p3 für das Schrittverhältnis sowie die beiden Achsenwerte p4 und p5 und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: In *p3 wird das ganzzahlige Verhältnis p4 / p5 bzw. p5 / p4 (oder 1, falls der kleinere
 *   Wert überwiegt) abgelegt.
 === Ende Beschreibung === */
void f_07b6b0(int p1, signed char *p2, short *p3, short p4, short p5)
{
    if (!(*p2 ^= 1)) {
        if (p4 <= p5) {
            *p3 = 1;
        } else {
            if (!p4) *p2 = 1;
            else if (p5) *p3 = p4 / p5;
            else *p3 = p4;
        }
    }
    if (*p2 == 1) {
        if (!p5) {
            *p2 = 0;
            *p3 = 1;
        } else if (p5 <= p4) {
            *p3 = 1;
        } else {
            if (p4) *p3 = p5 / p4;
            else *p3 = p5;
        }
    }
}

inline short h_07b740()
{
    short sum;
    short i;
    char *q;
    sum = 0;
    for (i = 0; i < (short)0x14; i++) {
        q = (char *)((int)d_1c2ed4 + i * 0x73);
        if (f_072a00((int)q)) sum += f_0cfa10((int)q);
    }
    return sum;
}
inline short h_07b790()
{
    short sum;
    short i;
    char *q;
    sum = 0;
    for (i = 0; i < (short)0x14; i++) {
        q = (char *)((int)d_1c2ed4 + i * 0x73);
        if (f_072a00((int)q)) sum += f_0cfa50((int)q);
    }
    return sum;
}
//@ f_07b740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Summiert die aktuellen Lebenspunkte (f_0cfa10) aller noch kampffähigen Monster (f_072a00 != 0)
 *   auf dem Schlachtfeld.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt die Summe der gegnerischen
 *   Lebenspunkte als short zurück.
 * - Wichtige Variablen: Die Schleife durchläuft alle 20 Monster-Slots in d_1c2ed4.
 === Ende Beschreibung === */
short f_07b740()
{
    return h_07b740();
}

//@ f_07b790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Summiert die aktuellen Astralpunkte (f_0cfa50) aller noch kampffähigen Monster (f_072a00 != 0)
 *   auf dem Schlachtfeld.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt die Summe der gegnerischen
 *   Astralpunkte als short zurück.
 * - Wichtige Variablen: Die Schleife durchläuft alle 20 Monster-Slots in d_1c2ed4.
 === Ende Beschreibung === */
short f_07b790()
{
    return h_07b790();
}

//@ f_07b7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die vertikale Statusleiste am rechten Kampfbildschirmrand: Sie zeichnet für jeden
 *   Helden der Gruppe bei Änderungen das Mini-Porträt, das Status-Overlay-Icon (tot, fliehend, bewusstlos oder
 *   unbewaffnet) sowie die LE- und AE-Balken neu und aktualisiert darunter den gemeinsamen LE-/AE-Summenbalken
 *   aller Gegner.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf die Hauptkampfstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Felder p + 0x151, p + 0x15f und p + 0x17b cachen die zuletzt gezeichneten LE-, AE-
 *   und Icon-Werte jedes Helden, während p + 0x145..0x14f die Maximal- und Ist-Summen der gegnerischen Lebens-
 *   und Astralenergie speichern.
 === Ende Beschreibung === */
void f_07b7e0(char *p)
{
    struct Sum {
static inline short h_07b740()
{
    short sum;
    short i;
    char *q;
    sum = 0;
    for (i = 0; i < (short)0x14; i++) {
        { char *saved = d_1c2ed4; d_1c2ed4 = saved; } // KRUECKE: identischer Roundtrip
q = (char *)((int)d_1c2ed4 + i * 0x73);
        if (f_072a00((int)q)) sum += f_0cfa10((int)q);
    }
    return sum;
}
static inline short h_07b790()
{
    short sum;
    short i;
    char *q;
    sum = 0;
    for (i = 0; i < (short)0x14; i++) {
        { char *saved = d_1c2ed4; d_1c2ed4 = saved; } // KRUECKE: identischer Roundtrip
q = (char *)((int)d_1c2ed4 + i * 0x73);
        if (f_072a00((int)q)) sum += f_0cfa50((int)q);
    }
    return sum;
}
    };
    short i;
    int cur;
    int w;
    short h6 = 1; // KRUECKE: toter Startwert, echte Definition folgt vor jedem Lesen
    int q = 0;
    short ypos = 0;
    short v = 0;
    q = f_038c80(d_1c0004);
    i = 0;
    do {
        v = f_044e30(q);
        if (v != *(short *)(p + i * 2 + 0x16d)) {
            *(short *)(p + i * 2 + 0x16d) = v;
            f_045080(q, *(int *)(p + 0x13d));
            ((RivaRasterImage*)(*(int *)(p + 0x13d)))->f_0fb0c0((RivaRasterImage *)( *(int *)(p + i * 4 + 0x105)));
        }
        cur = 0;
        if (f_0d49b0(q) == 0 && !((char)(f_042470((struct hero *)(q))))) {
            if (((char)(f_042640((struct hero *)(q))))) cur = *(int *)(p + 0x129);
            else cur = *(int *)(p + 0x125);
        } else {
            if (((char)(f_042470((struct hero *)(q))))) cur = *(int *)(p + 0x121);
            else if (((char)(f_043230((struct hero *)(q))))) cur = *(int *)(p + 0x125);
            else {
                int s = f_042a60((struct hero *)(q), 3);
                if (s == 0 || ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7990() == 0 || f_042bb0((struct hero *)(q), 3) != 0) cur = *(int *)(p + 0x12d);
            }
        }
        ypos = i * 0x1c + 0x3f;
        h6 = 6;
        if (cur != *(int *)(p + i * 4 + 0x17b) || f_042960((struct hero *)(q)) != *(short *)(p + i * 2 + 0x151) || f_0429a0((struct hero *)(q)) != *(short *)(p + i * 2 + 0x15f)) {
            ((RivaRasterImage*)(*(int *)(p + i * 4 + 0xe9)))->f_0fade0((void *)( *(int *)p), 0, 0);
            ((RivaRasterImage*)(*(int *)(p + i * 4 + 0x105)))->f_0fade0((void *)( *(int *)p), 1, 0x14);
            f_01e630(&d_1c2bcc, 0, i, f_042960((struct hero *)(q)), f_042970((struct hero *)(q)), 2, *(int *)p);
            *(short *)(p + i * 2 + 0x151) = f_042960((struct hero *)(q));
            f_01e630(&d_1c2bcc, 1, i, ((char)(f_042470((struct hero *)(q)))) ? 0 : f_0429a0((struct hero *)(q)), f_0429b0((struct hero *)(q)), 2, *(int *)p);
            *(short *)(p + i * 2 + 0x15f) = f_0429a0((struct hero *)(q));
            if (cur) ((RivaRasterImage*)(cur))->f_0fade0((void *)( *(int *)p), 1, 1);
            f_1481a0(&d_1bdbd4, *(int *)p, 0, 0x13, 0x12, 0x12, -0x33);
            if (cur != *(int *)(p + i * 4 + 0x17b) && cur) f_1481a0(&d_1bdbd4, *(int *)p, 0, 0, 0x12, 0x12, -0x33);
            ((RivaRasterImage*)(*(int *)(p + 0x135)))->f_0fafb0((void *)( *(int *)p), 0, 0);
            ((RivaRasterImage*)(*(int *)(p + 0x135)))->f_0fade0((void *)( d_1a34e0), ypos, h6);
            *(int *)(p + i * 4 + 0x17b) = cur;
        }
        q = f_0391b0(d_1c0004, q);
        i++;
        if (f_042400((struct hero *)(q)) == 4) {
            q = f_0391b0(d_1c0004, q);
            i++;
        }
    } while (q != f_038c80(d_1c0004));
    i = Sum::h_07b740();
    v = Sum::h_07b790();
    if (*(short *)(p + 0x14d) != *(short *)(p + 0x145) || *(short *)(p + 0x14f) != *(short *)(p + 0x147) || i != *(short *)(p + 0x149) || v != *(short *)(p + 0x14b)) {
        *(short *)(p + 0x149) = i;
        *(short *)(p + 0x14b) = v;
        *(short *)(p + 0x14d) = *(short *)(p + 0x145);
        *(short *)(p + 0x14f) = *(short *)(p + 0x147);
        ((RivaRasterImage*)(*(int *)(p + 0x131)))->f_0fade0((void *)( *(int *)p), 0, 0);
        if (i) {
            w = i * 200;
            w /= *(short *)(p + 0x145);
            if (w < 1) w = 1;
            else if (w > 200) w = 200;
            for (i = 0; i < 6; i++) f_1483f0(*(int *)p, 0, i, (short)w, -4);
            f_148450(*(int *)p, (short)w, 0, 6, -0x2a);
        }
        if (v) {
            w = v * 200;
            w /= *(short *)(p + 0x147);
            if (w < 1) w = 1;
            else if (w > 200) w = 200;
            h6 = 0;
            i = 9;
            for (; h6 < 6; h6++) {
                f_1483f0(*(int *)p, 0, i, (short)w, -3);
                i++;
            }
            f_148450(*(int *)p, (short)w, 9, 6, -0x45);
        }
        ((RivaRasterImage*)(*(int *)(p + 0x139)))->f_0fafb0((void *)( *(int *)p), 0, 0);
        ((RivaRasterImage*)(*(int *)(p + 0x139)))->f_0fade0((void *)( d_1a34e0), 0x3c, 0xa0);
    }
}

//@ f_07bd30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft nach einem Angriff oder Zauber, ob das getroffene Ziel p2 (und gegebenenfalls ein
 *   zweites Ziel p3) kampfunfähig oder getötet wurde (f_042470), und gibt die entsprechende Kampfmeldung als
 *   Textzeile (0x101004a) oder Dialogbox (0x1010049) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie die Heldenzeiger p2 und p3 (0, falls
 *   kein zweites Ziel vorliegt) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0773b0(d_1c0004) wird abgefragt, ob Kampfmeldungen in der unteren Statuszeile
 *   oder als Popup-Fenster angezeigt werden.
 === Ende Beschreibung === */
void f_07bd30(int p1, int p2, int p3)
{
    Ob3c o;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    if (f_0773b0(d_1c0004)) {
        if (((char)(f_042470((struct hero *)(p2))))) {
            o.q->b = p2;
            f_07b220(0x101004a);
        }
        if (p3 && ((char)(f_042470((struct hero *)(p3))))) {
            o.q->b = p3;
            f_07b220(0x101004a);
        }
    } else {
        if (((char)(f_042470((struct hero *)(p2))))) {
            o.q->b = p2;
            f_0bf730(&d_1c2c64, 0x1010049);
        }
        if (p3 && ((char)(f_042470((struct hero *)(p3))))) {
            o.q->b = p3;
            f_0bf730(&d_1c2c64, 0x1010049);
        }
    }
    f_1254a0(&o, 0);
}

//@ f_07be00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt für einen Monsterzauber mit dem Tabellenindex p2 aus d_1a57e8 dessen Zielkategorie
 *   (e->b) unter Berücksichtigung der Gesinnung des Zaubernden (p3: normaler Gegner oder verzauberter
 *   Verbündeter) in den internen Zielsuchmodus (0..5).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Kampfkontext p1, den Monsterzauber-Index p2 sowie den
 *   Gesinnungsmodus p3 entgegen und gibt den Zielsuchcode (oder -1, falls unzulässig) zurück.
 * - Wichtige Variablen: Die Tabelle d_1a57e8 beschreibt die Eigenschaften der im Kampf verfügbaren
 *   Monsterzauber.
 === Ende Beschreibung === */
int f_07be00(int p1, short p2, short p3)
{
    int r;
    E12 *e;
    r = -1;
    if (d_1bd928) {
        f_069460();
        f_146dfa(&d_1c2edc, 1);
    }
    e = &d_1a57e8[p2];
    if (p3) {
        if (e->b == 3) r = 1;
        else if (e->b == 1) r = 0;
        else if (e->b == 2) r = 3;
        else if (e->b == 4) r = 5;
        else r = 2;
    } else {
        if (e->b == 3) r = 0;
        else if (e->b == 0) r = 2;
    }
    return r;
}

//@ f_07beb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für ein zauberndes Monster (p1), ob sich der geplante Monsterzauber p2 gegen das aktuell
 *   ausgewählte Ziel überhaupt lohnt (damit z. B. kein Lähmungs-, Flucht- oder Heilzauber auf ein bereits
 *   versteinertes, fliehendes oder kaum verletztes Ziel verschwendet wird).
 * - Eingaben und Rückgabe: Die Funktion erhält den Monsterzeiger p1 sowie die Monsterzauber-Kennung p2 und gibt
 *   1 zurück, wenn der Zauber sinnvoll einsetzbar ist, sonst 0.
 * - Wichtige Variablen: Je nach Zieltyp (f_0cfd40(p1)) wird das Ziel über f_0d0910 als Monster (o1) oder über
 *   f_0d08a0 als Held (o2) ausgewertet.
 === Ende Beschreibung === */
int f_07beb0(int p1, short p2)
{
    short r;
    short kind;
    int o1, o2;
    signed char c;
    r = 1;
    if (d_1bd928) {
        f_069460();
        f_146dfa(&d_1c2edc, 1);
    }
    c = f_0cfd40(p1);
    if (c == 1 || c == 5) {
        kind = 1;
        o1 = f_0d0910(p1);
    } else if (c == 2) {
        kind = 2;
        o2 = f_0d08a0(p1);
    } else {
        return 0;
    }
    if (p2 == 7) {
        if (kind == 1) {
            if (f_0cfd70(o1) || f_0cffb0(o1)) r = 0;
        } else {
            if (((char)(f_043230((struct hero *)(o2)))) || ((char)(f_042640((struct hero *)(o2))))) r = 0;
        }
    } else if (p2 == 4) {
        if (kind == 1) {
            if (f_0cffb0(o1)) r = 0;
        } else {
            if (f_149360(d_1a250a, d_1a2814) != -1 || f_149360(f_0de820(d_1c0004), d_1a2834) != -1 || ((char)(f_042640((struct hero *)(o2)))) || ((char)(f_0424e0((struct hero *)(o2)))) || ((char)(f_042600((struct hero *)(o2))))) r = 0;
        }
    } else if (p2 == 0xe) {
        if (kind == 1) {
            if (f_0cfe30(o1) || f_0cffb0(o1)) r = 0;
        } else {
            if (((char)(f_0424e0((struct hero *)(o2)))) || ((char)(f_042640((struct hero *)(o2))))) r = 0;
        }
    } else if (p2 == 6) {
        int a, b;
        if (kind == 1) {
            a = f_0cf9f0(o1);
            b = f_0cfa10(o1);
            if (b >= a - 5) r = 0;
        } else {
            a = f_042970((struct hero *)(o2));
            if (f_042960((struct hero *)(o2)) >= a - 5) r = 0;
        }
    } else if (p2 == 5) {
        if (f_0cfab0(o1) > 3) r = 0;
    } else if (p2 == 0xc) {
        if (f_0d0010(o1)) r = 0;
    } else if (p2 == 1) {
        if (!(f_0cfe30(o1) || f_0cfef0(o1))) r = 0;
    } else if (p2 == 3) {
        if (((char)(f_0425a0((struct hero *)(o2)))) || ((char)(f_042640((struct hero *)(o2))))) r = 0;
    } else if (p2 == 2) {
        if (((char)(f_042680((struct hero *)(o2)))) || ((char)(f_042640((struct hero *)(o2))))) r = 0;
    }
    return r;
}

//@ f_07c1a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für ein Monster an Position (p2, p3), ob auf dem Nachbarfeld (p2 + p4, p3 + p5) ein
 *   angreifbarer Gegner steht (im Normalmodus p6 == 1 ein Held oder ein verzaubertes Monster, bei einem
 *   verzauberten Monster p6 == 0 ein feindliches Monster).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, die Standkoordinaten p2 und p3, den
 *   Richtungsversatz p4 und p5 sowie den Gesinnungsmodus p6 und gibt 1 bei einem gültigen Angriffsziel zurück,
 *   sonst 0.
 * - Wichtige Variablen: Über MAP(p2 + p4, p3 + p5) wird die Figurenkennung auf dem Nachbarfeld aus d_1bd984
 *   ausgelesen.
 === Ende Beschreibung === */
struct Big { char x[0x5ef]; };
int f_07c1a0(int p1, short p2, short p3, short p4, short p5, short p6)
{
    int r;
    unsigned char b;
    r = 0;
    if (d_1bd928) {
        f_069460();
        f_146dfa(&d_1c2edc, 1);
    }
    b = MAP(p2 + p4, p5 + p3);
    int mode = p6;
    if (mode == 1) {
        if (b >= 1 && b < 10 && f_0d4a60((int)(d_1bc8f0 + (b - 1) * 0x5ef))) r = 1;
        else if (b >= 10 && b < 0x1e && f_072b70((int)(d_1c2ed4 + (b - 10) * 0x73))) r = 1;
    } else if (p6 == (short)0) {
        if (b >= 10 && b < 0x1e && f_072a00((int)(d_1c2ed4 + (b - 10) * 0x73))) r = 1;
    }
    return (short)r;
}

//@ f_07c2a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Zauber-KI eines Monsters (q): Sie wählt aus dessen bis zu fünf verfügbaren Zaubern
 *   in d_1a58a8 zufällig einen passenden Spruch aus, sucht ein gültiges Ziel in Reichweite (oder bewegt das
 *   Monster bei Berührungs- und Sichtlinienzaubern über f_074b40 und f_07d080 zunächst in Schussposition) und
 *   gibt den gewählten Zauberindex zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Monsterzeiger q, den Gesinnungsmodus
 *   mode sowie die aktuellen Monsterkoordinaten x und y und gibt den gewählten Monsterzauber-Index (oder -1,
 *   falls kein Zauber möglich war) zurück.
 * - Wichtige Variablen: Die Tabelle d_1a58a8 enthält je Zauberklasse bis zu 5 Spruchindizes, und d_1bda6c sowie
 *   d_1bda6e speichern die Zielkoordinaten des ausgewählten Opfers.
 === Ende Beschreibung === */
signed char f_0cfc30(int p1);
short f_145760(int p1, int p2);
void f_0d0940(int p1, int p2);
void f_0d01d0(int p1, int p2);
void f_0d01f0(int p1, int p2);
extern signed char d_1a58a8[];
extern short d_1bda6c, d_1bda6e;

// BLIND: f_07c2a0 hier komplett neu aus dem Original-Assembler schreiben (orig.sh gz_07b370 f_07c2a0).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
static inline short upperA8(short value) { --value; return value; }
int f_07c2a0(int p1, int q, short mode, short x, short y)
{
    short v_28;
    short v_20;
    short i;
    short v_ecx;
    short v_24;
    short v_18;
    short v_08;
    int v_ebp;
    int v_04;
    short v_0c;
    unsigned char c1;
    unsigned char c;

    v_18 = -2;
    v_28 = 0;
    v_ebp = 1;
    while (v_ebp && f_0cfbd0(q) > 0 && v_28 < 5) {
        v_ebp = 0;
        v_04 = 0;
        v_28++;
        if (d_1bd928) {
            f_069460();
            f_146dfa(&d_1c2edc, 1);
        }
        i = 0;
        v_20 = 0;
        v_24 = 0;
        while (i < 5) {
            if (d_1a58a8[f_0cfc30(q) * 5 + i++] == -1)
                break;
            v_24++;
        }
        while (!v_20 && f_0cfbd0(q) > 0) {
            if (d_1bd928) {
                f_069460();
                f_146dfa(&d_1c2edc, 1);
            }
            i = 0;
            do {
                f_146dfa(&d_1c2edc, 1);
                v_0c = d_1a58a8[f_0cfc30(q) * 5 + f_145760(0, upperA8(v_24))];
                v_ecx = 1;
                if (v_0c == v_18) {
                    v_ecx = 0;
                } else {
                    v_18 = v_0c;
                    break;
                }
                i++;
            } while (i < 5);
            f_0cfd30(q, 0xff);
            if (v_ecx) {
                v_08 = f_07be00(p1, v_0c, mode);
                if (v_08 > 0) {
                    if (v_08 == 2) {
                        f_0d0940(q, q);
                        if (f_07beb0(q, v_0c)) {
                            f_0d01d0(q, (unsigned char)x);
                            f_0d01f0(q, (unsigned char)y);
                            d_1bda6c = x;
                            d_1bda6e = y;
                            return v_0c;
                        } else {
                            v_ebp = 1;
                            f_0cfd30(q, 0xff);
                            v_20 = 1;
                        }
                    } else if (!d_1a57e8[v_0c].rest[0]) {
                        while (f_0cfbd0(q) && !v_20) {
                            f_146dfa(&d_1c2edc, 1);
                            if (!v_04) {
                                f_0cfd30(q, 0xff);
                                c1 = f_084b40(p1, x, y, v_08, 1, 1);
                                if (c1) {
                                    if (c1 == 0xff && v_08 == 5) {
                                        f_0d0940(q, q);
                                        f_0d01d0(q, (unsigned char)d_1bda6c);
                                        f_0d01f0(q, (unsigned char)d_1bda6e);
                                    } else if (c1 != 0xff) {
                                        f_0cfd30(q, c1);
                                    }
                                }
                            }
                            if ((unsigned char)f_0cfd20(q) != 0xff) {
                                if (f_07beb0(q, v_0c)) {
                                    return v_0c;
                                } else {
                                    v_ebp = 1;
                                    f_0cfd30(q, 0xff);
                                    v_20 = 1;
                                }
                            } else {
                                if (f_0cfbd0(q) > 0 && v_08 != 5) {
                                    if (!f_0cfec0(q)) {
                                        if (v_08 == 0)
                                            c = f_074b40(p1, q, x, y, 1, 1);
                                        else if (v_08 == 3)
                                            c = f_074b40(p1, q, x, y, 2, 1);
                                        else
                                            c = f_074b40(p1, q, x, y, 0, 1);
                                        if (c) {
                                            f_0cfd30(q, c);
                                            if (f_07beb0(q, v_0c)) {
                                                f_07d080(p1, q);
                                                f_071e90((unsigned char)(f_0729c0(q) + 10), &x, &y);
                                                v_04 = 1;
                                                if (f_0cfbd0(q) < 5) {
                                                    f_0cfbe0(q, 0);
                                                    f_0cfd30(q, 0xff);
                                                }
                                            } else {
                                                v_ebp = 1;
                                                f_0cfd30(q, 0xff);
                                                v_20 = 1;
                                            }
                                        } else {
                                            v_20 = 1;
                                            v_ebp = 1;
                                            f_0cfd30(q, 0xff);
                                        }
                                    } else {
                                        f_0cfbe0(q, 0);
                                        f_0cfd30(q, 0xff);
                                    }
                                }
                            }
                        }
                    } else {
                        while (!v_20 && f_0cfbd0(q) > 0) {
                            f_146dfa(&d_1c2edc, 1);
                            if (d_1bd928)
                                f_069460();
                            if (!v_04) {
                                f_0cfd30(q, 0xff);
                                c1 = f_084b40(p1, x, y, v_08, 99, 1);
                                if (c1)
                                    f_0cfd30(q, c1);
                            }
                            if ((unsigned char)f_0cfd20(q) != 0xff) {
                                if (f_07beb0(q, v_0c)) {
                                    return v_0c;
                                } else {
                                    f_0cfd30(q, 0xff);
                                    v_ebp = 1;
                                    v_20 = 1;
                                }
                            } else {
                                if (f_0cfbd0(q) > 0) {
                                    if (!f_0cfec0(q)) {
                                        if (v_08 == 0)
                                            c = f_074b40(p1, q, x, y, 10, 1);
                                        else if (v_08 == 3)
                                            c = f_074b40(p1, q, x, y, 11, 1);
                                        else
                                            c = f_074b40(p1, q, x, y, 9, 1);
                                        if (c) {
                                            f_0cfd30(q, c);
                                            if (f_07beb0(q, v_0c)) {
                                                f_07d080(p1, q);
                                                f_071e90((unsigned char)(f_0729c0(q) + 10), &x, &y);
                                                v_04 = 1;
                                                int energy_left = f_0cfbd0(q);
                                                if (energy_left < 5) {
                                                    f_0cfbe0(q, 0);
                                                    f_0cfd30(q, 0xff);
                                                    v_04 = 0;
                                                    v_20 = 1;
                                                }
                                            } else {
                                                v_ebp = 1;
                                                f_0cfd30(q, 0xff);
                                                v_20 = 1;
                                            }
                                        } else {
                                            v_20 = 1;
                                            v_ebp = 1;
                                            f_0cfd30(q, 0xff);
                                        }
                                    } else {
                                        f_0cfbe0(q, 0);
                                        f_0cfd30(q, 0xff);
                                        v_20 = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                v_20 = 1;
            }
        }
    }
    return -1;
}


//@ f_07c900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Fernkampf-KI eines Monsters (q): Sie sucht über f_084b40 ein beschießbares Ziel
 *   mit freier Schusslinie (Mindestabstand 2 Felder) und lässt das Monster bei versperrter Sichtlinie
 *   schrittweise in eine günstigere Schussposition ziehen (f_074b40, f_07d080).
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, den Monsterzeiger q, den Gesinnungsmodus p3
 *   sowie die Startkoordinaten p4 (X) und p5 (Y) und gibt 1 zurück, wenn ein gültiges Fernkampfziel in
 *   Schussdistanz erfasst wurde, sonst 0.
 * - Wichtige Variablen: Hat das Monster am Ende kein gültiges Fernkampfziel gefunden (res == 0), setzt die
 *   Funktion das Ziel auf 0xff und die Monsteraktion auf 0xd (Abwarten) zurück.
 === Ende Beschreibung === */
#define PZ !p3
short f_07c900(int p1, int q, short p3, short p4, short p5)
{
    short res;
    short done;
    short a, b;
    unsigned char v;
    int c;
    res = done = 0;
    for (;;) {
        if (f_0cfbd0(q) <= 0) goto finish;
        if (d_1bd928) {
            f_069460();
            f_146dfa(&d_1c2edc, 1);
        }
loop:
        if (done || f_0cfbd0(q) <= 0) {
            if (done) goto finish;
            continue;
        }
        {
            if (d_1bd928) {
                f_069460();
                f_146dfa(&d_1c2edc, 1);
            }
            f_0cfd30(q, 0xff);
            if (f_0cfbd0(q) >= 3) {
                f_0cfd30(q, 0xff);
                v = f_084b40(p1, p4, p5, p3, 99, 0);
                if (v) f_0cfd30(q, v);
            }
            if ((unsigned char)f_0cfd20(q) != 0xff) {
                f_071e90((unsigned char)f_0cfd20(q), &a, &b);
                if (f_071e20(a, b, p4, p5) >= 2) res = 1; else res = 0;
                done = 1;

            } else {
                if (f_0cfbd0(q) <= 0) goto loop;
                if (!f_0cfec0(q)) {
                    if (PZ) c = f_074b40(p1, q, p4, p5, 10, 2);
                    else c = f_074b40(p1, q, p4, p5, 9, 2);
                    if (c != 0) {
                        f_07d080(p1, q);
                        f_071e90((unsigned char)(f_0729c0(q) + 10), &p4, &p5);
                        if (f_0cfbd0(q) >= 3) goto loop;
                    }
                }
                f_0cfbe0(q, 0);
            }
        }
        goto loop;
    }
finish:
    if (res == 0) {
        f_0cfd30(q, 0xff);
        f_0cfcf0(q, 0xd);
    }
    return res;
}

