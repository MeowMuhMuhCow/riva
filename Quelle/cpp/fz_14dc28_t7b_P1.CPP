/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t7b (0x155854 - 0x156370)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von fz_14dc28_t7 und enthält den Ringpuffer für vergangene
 * Spielerpositionen (f_155854 bis f_1559e0, z. B. zum Zurücksetzen nach Kollisionen oder Fallen), die
 * Warteschlange für 3D-Bewegungs- und Drehkommandos (f_155ab0 bis f_155c64), die Kameramatrix- und
 * Winkelberechnungen (f_155c94 bis f_155f70) sowie die zentrale Bewegungs-Ausführungsfunktion f_1560ac inklusive
 * Kopfwackeln (Head-Bobbing) beim Gehen.
 === Ende Beschreibung === */
// P3 13/25 gleich (suche.py 30.10.2026, Basis fz_14dc28_t7_P1.CPP)
// OPT -5r -oneatx -zp1 -s -fp5
// P1 9/25 gleich
// CC wcc386
// fz_14dc28_t7 (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x154E78-0x156370
struct V3 { int x, y, z; };
struct Pose { int x, y, z, w; unsigned short a, b, c, pad; };
struct M { int m[9]; struct V3 t; };
struct Ev { unsigned char t; char p1[3]; int v; };
struct Cam { struct V3 pos; int c; unsigned short a, b, cc; };
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define HI(x) (((unsigned short *)&(x))[1])
int FM(int a, int b);
#pragma aux FM = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify exact [eax edx] value [eax];
int FDIV(int a, int b);
#pragma aux FDIV = "mov edx,eax" "sar edx,16" "shl eax,16" "idiv ebx" parm [eax] [ebx] modify exact [eax edx] value [eax];
int MD(int a, int b, int c);
#pragma aux MD = "imul edx" "idiv ebx" parm [eax] [edx] [ebx] modify exact [eax edx] value [eax];
int MD2(int a, int b, int c);
#pragma aux MD2 = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] modify exact [eax edx] value [eax];
int FMB(int a, int b);
#pragma aux FMB = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int RCP(int a);
#include <stdlib.h>
#pragma intrinsic(abs)
#define ABS(x) abs(x)
extern unsigned char d_1a9b88, d_1a9b89, d_1a9b8a, d_1a9947, d_1a9948, d_1a9942, d_1a9943, d_1a9945, d_1a993a, d_1a993d, d_1a994f;
extern volatile unsigned char d_1a9933;
extern unsigned char d_1a9b8b;
extern int d_1a996c, d_1a99f0, d_1a9b8c, d_1a9b34, d_1a9b40, d_1a9b2c, d_1a9b38, d_1a9b3c, d_1a9b30, d_1a9ab8, d_1a9ac4, d_1a9ae0, d_1a9ab0, d_1a9a14, d_1a9a18;
extern unsigned short d_1a9b04, d_1a9b06;
extern int *d_1cdc40; extern char *d_1cdc30;
extern unsigned d_1cdc48, d_1cdc50, d_1cdb18;
extern int d_1cdb3c, d_1cdb20;
extern struct Pose d_1c90c0, d_1c6c78[10];
extern struct Pose *d_1cd1f8;
extern struct V3 d_1cd23c, d_1cd308, d_1cd294, d_1cd328;
extern struct M d_1cd270;
extern int d_1cd248, d_1cd2a4, d_1cc788, d_1cdda0;
extern unsigned short d_1cdc20, d_1cdc1e, d_1cdc1c, d_1cdc1a;
extern struct Ev d_1cdca0[32];
extern int d_1cdc34, d_1cdc38, d_1cdc3c, d_1cdc9c, d_1cdc98, d_1cdc94, d_1cdc74, d_1cdc70, d_1cdc6c, d_1cdc60, d_1cdc5c, d_1cdc58, d_1cdc54, d_1cdc68, d_1cdc64, d_1cdc80, d_1cdc8c, d_1cdc88, d_1cdc7c, d_1cdc90, d_1cdc84;
extern unsigned char d_1cdc79, d_1cdc78;
extern double d_1b9464;
unsigned f_16fc19(void);
void f_153ac8(void);
void f_1508fc(void);
void f_154ba0(int p1);
void f_155f70(struct Cam *p);
void f_155854(void);
void f_155934(void);
void f_155ab0(unsigned short a, int b);
void f_155c94(int a, int b);
void f_155d74(int p);
void f_155e08(int p);
void f_16b930(struct M *m);
void f_16cbdc(struct M *m, unsigned v);
void f_16cc44(struct M *m, unsigned v);
void f_16ccac(struct M *m, unsigned v);
void f_16cd74(struct M *m, int x, int y, int z);
void f_16cff5(struct V3 *o, struct V3 *v, struct M *m);
int f_16d33f(int a, int b, int c, int d);
int f_16d3d0(int a);
int f_16d4d8(int a, int b);
int f_16d4fc(int a, int b, int c);
int f_16d7e7(int a);
short f_16d8ad(short a, short b);
void f_176f10(int *a, int *b, int *c);
#pragma aux f_16cff5 parm [eax] [edx] [ebx] modify exact [eax edx];
#pragma aux f_16d4d8 parm caller [] modify exact [eax];
#pragma aux f_16d4fc parm caller [] modify exact [eax];
#pragma aux f_16d7e7 parm caller [] modify exact [eax];
#pragma aux f_16d8ad parm caller [];
#pragma aux f_154e78 "*";
#pragma aux f_154eb8 "*";
#pragma aux f_154f00 "*";
#pragma aux f_154f08 "*";
#pragma aux f_155268 "*";
#pragma aux f_155298 "*";
#pragma aux f_155854 "*";
#pragma aux f_155900 "*";
#pragma aux f_155928 "*";
#pragma aux f_155934 "*";
#pragma aux f_155968 "*";
#pragma aux f_1559e0 "*";
#pragma aux f_155ab0 "*";
#pragma aux f_155b20 "*";
#pragma aux f_155b80 "*";
#pragma aux f_155bc8 "*";
#pragma aux f_155bfc "*";
#pragma aux f_155c30 "*";
#pragma aux f_155c64 "*";
#pragma aux f_155c94 "*";
#pragma aux f_155d74 "*";
#pragma aux f_155e08 "*";
#pragma aux f_155ebc "*";
#pragma aux f_155f70 "*";
#pragma aux f_1560ac "*";

//@ f_155854
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert die aktuelle Spielerpose d_1c90c0 im 10-elementigen Positions-Ringpuffer
 *   d_1c6c78 (Schreibzeiger d_1cd1f8), sobald die Manhattan-Distanz (|dx| + |dy| + |dz|) zum zuletzt
 *   gespeicherten Standpunkt den Schwellwert d_1a9b8c überschreitet. Beim ersten Aufruf (d_1a9945 != 0) wird der
 *   gesamte Ringpuffer über f_155934 mit der aktuellen Pose vorbelegt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c6c78[10] (Ringpuffer der letzten 10 Posen), d_1cd1f8 (aktueller Ringpufferzeiger),
 *   d_1a9b8c (Mindestabstand für neuen Eintrag).
 === Ende Beschreibung === */
void f_155854(void)
{
    int s;
    struct Pose *p;

    if (d_1a9945 != 0) {
        (*(void (*)(void))f_155934)();
        d_1a9945 = 0;
    } else {
        p = d_1cd1f8;
        s = ABS((d_1c90c0.x >> 2) - (p->x >> 2)) + ABS((d_1c90c0.y >> 2) - (p->y >> 2)) + ABS((d_1c90c0.z >> 2) - (p->z >> 2));
        if (s > (d_1a9b8c >> 2)) {
            p++;
            d_1cd1f8 = p;
            if (p >= d_1c6c78 + 10) d_1cd1f8 = d_1c6c78;
            *d_1cd1f8 = d_1c90c0;
        }
    }
}

//@ f_155900
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Schrittdistanz-Schwelle d_1a9b8c (begrenzt auf 2..1000, umgerechnet ins
 *   16.16-Festkommaformat) für das Aufzeichnen von Rücksetzpositionen im Ringpuffer d_1c6c78.
 * - Eingaben: v (Schwellwert in Längeneinheiten als unsigned short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9b8c.
 === Ende Beschreibung === */
void f_155900(unsigned short v)
{
    if (v < 2) v = 2;
    else if (v > 1000) v = 1000;
    d_1a9b8c = v << 16;
}

//@ f_155928
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die aktuell eingestellte Schrittdistanz-Schwelle (d_1a9b8c >> 16) des
 *   Positions-Ringpuffers zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Schwellwert als ganze Zahl (int).
 * - Wichtige Variablen: d_1a9b8c.
 === Ende Beschreibung === */
int f_155928(void)
{
    return d_1a9b8c >> 16;
}

//@ f_155934
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt alle 10 Einträge des Positions-Ringpuffers d_1c6c78 mit der aktuellen Kamerapose
 *   d_1c90c0 und setzt den Ringpufferzeiger d_1cd1f8 auf das erste Element zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c6c78, d_1cd1f8.
 === Ende Beschreibung === */
void f_155934(void)
{
    struct Pose *p;
    int i;

    i = 0;
    p = d_1c6c78;
    do {
        i++;
        *p = d_1c90c0;
        p++;
    } while (i < 10);
    d_1cd1f8 = d_1c6c78;
}

//@ f_155968
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Spieler-/Kamerapose d_1c90c0 um n Schritte (1..10) im Ringpuffer d_1c6c78 zurück
 *   und markiert die Kamera über d_1a9942 = 1 zur Neuaktualisierung.
 * - Eingaben: n (Anzahl der Schritte zurück im Ringpuffer, 1..10).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn die 3D-Engine nicht initialisiert ist.
 * - Wichtige Variablen: d_1c90c0, d_1cd1f8.
 === Ende Beschreibung === */
int f_155968(unsigned n)
{
    int r, status;
    struct Pose *p;

    if (d_1a993d == 0) {
        status = 0xf002;
        r = status;
    } else {
        if ((unsigned short)n == 0) {
            r = 0;
        } else {
            if ((unsigned short)n >= 10) n = 10;
            p = (struct Pose *)((char *)d_1cd1f8 - ((n & 0xffff) - 1) * 24);
            if (p < d_1c6c78) p += 10;
            r = 0;
            d_1c90c0 = *p;
            *(volatile unsigned char *)&d_1a9942 = 1;
        }
        status = 0;
    }
    d_1a996c = status;
    return r;
}

//@ f_1559e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht im 10-elementigen Positions-Ringpuffer d_1c6c78 denjenigen gespeicherten Standpunkt,
 *   der die größte Manhattan-Distanz zur aktuellen Position d_1c90c0 aufweist, und setzt die Spielerpose
 *   d_1c90c0 auf diesen am weitesten entfernten sicheren Punkt zurück.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 1-basierter Rückschritt-Index (1..10) des gewählten Eintrags.
 * - Wichtige Variablen: best (größte gefundene Distanz), bp (Zeiger auf die beste Pose).
 === Ende Beschreibung === */
short f_1559e0(void)
{
    struct Pose *p, *bp;
    int i, bi, best, d, sz, sx, sy;

    sx = d_1c90c0.x >> 2;
    sy = d_1c90c0.y >> 2;
    sz = d_1c90c0.z >> 2;
    best = -0x3e80000;
    bi = 0;
    i = 1;
    p = d_1cd1f8;
    do {
        d = ABS(sx - (p->x >> 2)) + ABS(sy - (p->y >> 2)) + ABS(sz - (p->z >> 2));
        if (d > best) {
            bi = i;
            best = d;
            bp = p;
        }
        p--;
        if (p < d_1c6c78) p = d_1c6c78 + 9;
        i++;
    } while (i <= 10);
    if (bi != 0) {
        d_1a9942 = 1;
        d_1c90c0 = *bp;
    }
    return bi;
}

//@ f_155ab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt ein Bewegungs- oder Drehkommando vom Typ a mit der Stärke b in die bis zu 32 Einträge
 *   fassende Bewegungswarteschlange d_1cdca0 (Zähler d_1a99f0) ein. Hat das letzte Kommando in der Warteschlange
 *   bereits denselben Typ a, werden die Werte b einfach aufaddiert.
 * - Eingaben: a (Kommandotyp: 1 = vor/zurück, 2 = seitwärts, 3 = Blick neigen, 4 = drehen, 5 = Sonderkommando),
 *   b (Schrittweite/Winkeländerung).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdca0 (Kommando-Array), d_1a99f0 (Anzahl wartender Kommandos), d_1a9933
 *   (Update-Anforderungsflag).
 === Ende Beschreibung === */
void f_155ab0(unsigned short a, int b)
{
    struct Ev *e;
    if (d_1a99f0 == 0) {
        d_1a99f0 = 1;
        d_1cdca0[0].v = b;
        d_1cdca0[0].t = a;
    } else {
        e = &d_1cdca0[d_1a99f0 - 1];
        if (e->t == (unsigned short)a) {
            e->v += b;
            d_1a9933 = 1;
            return;
        }
        if (d_1a99f0 < 32) {
            e++;
            e->t = a;
            d_1a99f0++;
            e->v = b;
        }
    }
    d_1a9933 = 1;
}

//@ f_155b20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reiht einen Vorwärts- oder Rückwärts-Bewegungsschritt der Länge p (Kommandotyp 1) in die
 *   Bewegungswarteschlange ein und zählt bei kollisionsfreiem Gang (d_1a993a == 0) die Phasenwinkel d_1a9b34 und
 *   d_1a9b40 für das Kopfwackeln (Head-Bobbing) weiter.
 * - Eingaben: p (Schrittweite vorwärts/rückwärts).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a9b34, d_1a9b40 (Gangphasen-Zähler).
 === Ende Beschreibung === */
int f_155b20(int p)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    f_155ab0(1, p);
    if (d_1a993a == 0) {
        d_1a9b34 += p; d_1a9b40 += p;
    }
    d_1a996c = 0;
    return 0;
}

//@ f_155b80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reiht einen Seitwärtsschritt (Strafe links/rechts) der Weite p (Kommandotyp 2) in die
 *   Bewegungswarteschlange ein und aktualisiert den Gangphasen-Zähler d_1a9b34.
 * - Eingaben: p (seitliche Schrittweite).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a9b34.
 === Ende Beschreibung === */
int f_155b80(int p)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    f_155ab0(2, p);
    if (d_1a993a == 0) d_1a9b34 = d_1a9b34 + p;
    d_1a996c = 0;
    return 0;
}

//@ f_155bc8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reiht eine horizontale Drehung (Gieren / Yaw) um p (Kommandotyp 4) in die
 *   Bewegungswarteschlange ein.
 * - Eingaben: p (Drehwinkeländerung).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a996c.
 === Ende Beschreibung === */
int f_155bc8(int p)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    f_155ab0(4, p);
    d_1a996c = 0;
    return 0;
}

//@ f_155bfc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reiht eine vertikale Blickneigung (Nicken / Pitch, nach oben oder unten schauen) um p
 *   (Kommandotyp 3) in die Bewegungswarteschlange ein.
 * - Eingaben: p (Neigungswinkeländerung).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a996c.
 === Ende Beschreibung === */
int f_155bfc(int p)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    f_155ab0(3, p);
    d_1a996c = 0;
    return 0;
}

//@ f_155c30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reiht ein Bewegungskommando vom Typ 5 mit Parameter p in die Bewegungswarteschlange ein.
 * - Eingaben: p (Kommandowert).
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a996c.
 === Ende Beschreibung === */
int f_155c30(int p)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    f_155ab0(5, p);
    d_1a996c = 0;
    return 0;
}

//@ f_155c64
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert die Bewegungswarteschlange (d_1a99f0 = 0).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a99f0.
 === Ende Beschreibung === */
int f_155c64(void)
{
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    d_1a99f0 = 0;
    d_1a996c = 0;
    return 0;
}

//@ f_155c94
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verschiebt die Zielposition der Kamera (d_1cd294 in der Kameramatrix d_1cd270) relativ zur
 *   aktuellen horizontalen Blickrichtung (d_1cdc1e, d_1cdc1c) um a Einheiten vorwärts/rückwärts und b Einheiten
 *   seitwärts.
 * - Eingaben: a (Vorwärtsversatz), b (Seitwärtsversatz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cd270 (Kameratransformationsmatrix), d_1cd294 (Translationsvektor der Kamera).
 === Ende Beschreibung === */
void f_155c94(int a, int b)
{
    struct V3 out, vec, sv;
    struct M n;
    sv = d_1cd294;
    f_16b930(&d_1cd270);
    f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
    f_16cc44(&d_1cd270, d_1cdc1e);
    f_16ccac(&d_1cd270, d_1cdc1c);
    d_1cd294 = sv;
    f_16b930(&n);
    f_16cc44(&n, d_1cdc1e);
    f_16ccac(&n, d_1cdc1c);
    vec.x = -b;
    vec.y = 0;
    vec.z = -a;
    f_16cff5(&out, &vec, &n);
    f_16cd74(&d_1cd270, out.x, out.y, out.z);
}

//@ f_155d74
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert den horizontalen Blickwinkel (Yaw d_1cdc1e) um den aus p umgerechneten
 *   16-Bit-Winkel (p * 0x10000 / 360.0) und baut die 3x3-Rotationsmatrix der Kamera (d_1cd270) neu auf.
 * - Eingaben: p (Drehwinkel im 16.16-Gradformat).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc1e (Gierwinkel), d_1cd270 (Kameramatrix).
 === Ende Beschreibung === */
void f_155d74(int p)
{
    struct V3 sv;

    d_1cdc1e = d_1cdc1e + (short)MD2(p, 0x10000, 0x1680000); sv = d_1cd294;
    f_16b930(&d_1cd270);
    f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
    f_16cc44(&d_1cd270, d_1cdc1e);
    f_16ccac(&d_1cd270, d_1cdc1c);
    d_1cd294 = sv;
}

//@ f_155e08
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert den vertikalen Blickwinkel (Pitch d_1cdc20) um p, begrenzt ihn auf den zulässigen
 *   Neigungsbereich (<= 0x3552 nach oben bzw. >= 0xca9e nach unten) und berechnet die Kamerarotationsmatrix
 *   d_1cd270 neu.
 * - Eingaben: p (Neigungsänderung im 16.16-Gradformat).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc20 (Nickwinkel), d_1cdc1a (Hangneigungs-Offset vom Untergrund).
 === Ende Beschreibung === */
void f_155e08(int p)
{
    struct V3 sv;
    unsigned short t;

    t = (short)MD2(p, 0x10000, 0x1680000) + d_1cdc20;
    if ((t <= 0x3552 || t >= 0xca9e || p <= 0) && (t >= 0xca9e || t <= 0x3552 || p >= 0)) {
        sv = d_1cd294;
        d_1cdc20 = t;
        f_16b930(&d_1cd270);
        f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
        f_16cc44(&d_1cd270, d_1cdc1e);
        f_16ccac(&d_1cd270, d_1cdc1c);
        d_1cd294 = sv;
    }
}

//@ f_155ebc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert den seitlichen Rollwinkel (Roll d_1cdc1c) der Kamera um p innerhalb der Grenzen <=
 *   0x2aa8 bzw. >= 0xd548 und aktualisiert die Kamerarotationsmatrix d_1cd270.
 * - Eingaben: p (Rollwinkeländerung).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc1c (Rollwinkel).
 === Ende Beschreibung === */
void f_155ebc(int p)
{
    struct V3 sv;
    unsigned short t;

    t = (short)MD2(p, 0x10000, 0x1680000) + d_1cdc1c;
    if ((t <= 0x2aa8 || t >= 0xd548 || p <= 0) && (t >= 0xd548 || t <= 0x2aa8 || p >= 0)) {
        sv = d_1cd294;
        d_1cdc1c = t;
        f_16b930(&d_1cd270);
        f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
        f_16cc44(&d_1cd270, d_1cdc1e);
        f_16ccac(&d_1cd270, d_1cdc1c);
        d_1cd294 = sv;
    }
}

//@ f_155f70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Kamera direkt auf die in der Struktur p übergebene 3D-Position (pos), Augenhöhe
 *   (c) und Orientierung (a, b, cc), begrenzt die effektive Kamerahöhe d_1a9ae0 auf [0x10000, 0x960000] und baut
 *   die Kameramatrix d_1cd270 neu auf.
 * - Eingaben: p (Zeiger auf eine struct Cam-Kameradefinition).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cd308, d_1cd23c, d_1cd294 (Kamerapositionen), d_1a9ac4 (Augenhöhe).
 === Ende Beschreibung === */
void f_155f70(struct Cam *p)
{
    d_1cd308.x = p->pos.x;
    d_1cd308.y = p->pos.y;
    d_1cd308.z = p->pos.z;
    (d_1cdc20) = p->a;
    d_1cdc1e = p->b;
    d_1cdc1c = p->cc;
    d_1a9ac4 = p->c;
    d_1a9ae0 = d_1a9ac4 + d_1a9ab8;
    if (d_1a9ae0 < 0x10000) d_1a9ae0 = 0x10000;
    else if (d_1a9ae0 > 0x960000) d_1a9ae0 = 0x960000;
    d_1cd23c = d_1cd308;
    d_1a9a14 = -1;
    d_1a9a18 = -1;
    d_1cd328.x = d_1cd308.x - d_1cd23c.x;
    d_1cd328.y = d_1cd308.y - d_1cd23c.y;
    d_1cd328.z = d_1cd308.z - d_1cd23c.z;
    f_16b930(&d_1cd270);
    f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
    f_16cc44(&d_1cd270, d_1cdc1e);
    f_16ccac(&d_1cd270, d_1cdc1c);
    d_1cd294 = d_1cd308;
}

//@ f_1560ac
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Arbeitet alle in der Warteschlange d_1cdca0 aufgelaufenen Bewegungs- und Drehkommandos ab,
 *   überlagert die vertikale und seitliche Sinus-Schwingung (f_16d7e7) für das Kopfwackeln beim Gehen (d_1a9ab8,
 *   d_1cdda0), führt die 3D-Kollisions- und Höhenprüfung (f_1508fc) durch, invertiert die Kameramatrix über
 *   f_176f10 zu d_1cc788, zeichnet bei aktivem Rekorder einen Keyframe (f_154ba0) auf, aktualisiert den
 *   Rücksetz-Ringpuffer (f_155854) und prüft, ob die Gruppe ein neues Kartengitterfeld (d_1a9a14, d_1a9a18)
 *   betreten hat (d_1a9943 = 1).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen:
 *   - d_1a9ab8, d_1cdda0: Vertikale und horizontale Schritt-Schwingung (Head-Bobbing).
 *   - d_1cc788: Invertierte Welt-zu-Kamera-Matrix für das anschließende Rendern.
 *   - d_1a9943: Flag "Spieler hat in diesem Schritt eine ganzzahlige Gittergrenze überschritten".
 === Ende Beschreibung === */
extern unsigned char d_1a9933_nv;
#pragma aux d_1a9933_nv "d_1a9933_";
#define CHK(v) { int q = (v); if (q > 0) { if (q < 0x1999) q = 0x1999; else if (q > 0x50000) q = 0x50000; } else { if (q > -0x1999) q = -0x1999; else if (q < -0x50000) q = -0x50000; } }
int f_1560ac(void)
{
    struct Ev *e;
    int i, z, x;

    d_1a9b04 = FM(d_1a9b2c, d_1a9b34);
    { int m = d_1a9b3c;
    d_1a9b06 = FM(d_1a9b38, d_1a9b40);
    d_1cdda0 = FMB(f_16d7e7(d_1a9b06), m); }
    d_1a9ab8 = FMB(f_16d7e7(d_1a9b04), d_1a9b30);
    d_1a9ae0 = d_1a9ac4 + d_1a9ab8;
    if (d_1a994f) f_155d74(0);
    e = d_1cdca0;
    i = 0;
    while (i < d_1a99f0) {
        switch (e->t) {
        case 1: CHK(e->v); f_155c94(e->v, d_1cdda0); break;
        case 2: CHK(e->v); f_155c94(0, e->v); break;
        case 3: f_155e08(e->v); break;
        case 4: f_155d74(e->v); break;
        }
        i++; e++;
    }
    d_1cd308 = d_1cd294;
    d_1a99f0 = 0;
    d_1cd328.x = d_1cd308.x - d_1cd23c.x;
    d_1cd328.y = d_1cd308.y - d_1cd23c.y;
    d_1cd328.z = d_1cd308.z - d_1cd23c.z;
    if (!d_1a9948) {
        f_1508fc();
        f_16b930(&d_1cd270);
        f_16cbdc(&d_1cd270, (unsigned short)(d_1cdc20 + d_1cdc1a));
        f_16cc44(&d_1cd270, d_1cdc1e);
        d_1cd294 = d_1cd308;
    }
    d_1cd23c = d_1cd308;
    f_176f10(&d_1cc788, &d_1cd2a4, &d_1cd248);
    if (!d_1a9948) {
        d_1c90c0.x = d_1cd308.x;
        d_1c90c0.y = d_1cd308.y;
        d_1c90c0.z = d_1cd308.z;
        d_1c90c0.a = d_1cdc20;
        d_1c90c0.b = d_1cdc1e;
        d_1c90c0.c = d_1cdc1c;
        if (d_1a9947) f_154ba0(0);
        f_155854();
        x = d_1cd308.x >> 16;
        z = d_1cd308.z >> 16;
        if (x != d_1a9a14 || z != d_1a9a18) {
            d_1a9943 = 1;
            d_1a9a18 = z;
            d_1a9a14 = x;
        } else {
            d_1a9943 = 0;
        }
    }

    d_1a9933_nv = 0;
    d_1a9942 = 1;
    return 0;
}
