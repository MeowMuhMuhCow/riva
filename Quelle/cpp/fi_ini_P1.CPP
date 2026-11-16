/* === Beschreibung (Katalog) ===
 * Einheit fi_ini (077400 - 0789b0)
 *
 * Überblick
 * Die Einheit fi_ini (*Fight Init*) verantwortet das vollständige Laden und Initialisieren eines Kampfes: das
 * Einlesen der Kampf- und Hindernisdaten (f_077540), das Anlegen der Monster- (f_077760, f_077e20, f_077fd0) und
 * Helden-Kampfobjekte (f_078170), den Aufbau des Kollisions- und Sichtrasters (f_078430, f_078550, f_078790)
 * sowie die zentrale Eingabeabfrage im Kampf (f_077400).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
#include "R_FIX.H"
// P3 6/10 gleich (suche.py 30.10.2026, Basis fi_ini_P1.CPP)
// fi_ini.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x077400-0x0789A0
#include <string.h>
#pragma aux f_07a9e0 parm [eax edx] modify exact [eax]
#pragma aux f_07aa10 parm [eax edx] modify exact [eax]
#define PB(o) (*(unsigned char *)(g + (o)))
#define SB(o) (*(signed char *)(g + (o)))
#define PS(o) (*(short *)(g + (o)))
#define PI(o) (*(int *)(g + (o)))
struct B14 { char b[14]; };
struct R69 { char b[69]; };
struct X9 { char b[9]; X9(int w, int h); ~X9(); };
struct Y { char b[0xf4]; Y(void *a, int f); ~Y(); };
struct S3c { int w0; int *p; char rest[0x34]; };
struct Q3a { unsigned char b0, b1; signed char b2, b3; short w[7]; short w12, w14, w16; unsigned char b18; signed char b19, b1a, b1b; short w1c, w1e; signed char b20, b21, b22, b23, b24, b25; short w26, w28, w2a, w2c; signed char b2e, b2f; char pad[10]; };
extern B14 d_1a1d34;
extern char d_1a1d20[];
extern R69 d_1a2218[];
extern int d_1a2510[];
extern char d_1a2734[];
extern char d_1a2736[];
extern char d_1a5530[];
extern short d_1a2744;
extern short d_1a2746;
extern short d_1bd75a;
extern short d_1bd90c;
extern short d_1bd920;
extern short d_1bd922;
extern short d_1bd924;
extern short d_1bd928;
extern X9 **d_1bd92c;
extern char *d_1bd930;
extern short d_1bd938;
extern short d_1bd940;
extern signed char *d_1bd944;
extern char *d_1bd984;
extern char d_1bdaec[];
extern int d_1bf510;
extern int d_1bf514;
extern unsigned char d_1bfaec;
extern int *d_1c0004;
extern volatile int d_1c0c94;
extern signed char d_1c0d88;

extern volatile short d_1c2198;
extern char d_1c21b4[];
extern char d_1c2be0[];
extern char d_1c2c64[];
extern char *d_1c2ed4;
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern const char d_1a1d44[];
extern const char d_1b6f5c[];
int f_068f40();
int f_0d5a90();
short f_149360(int a, void *b);

int f_0d49b0(int p);

short f_0c0020(void *o, int a);
char *f_014540(int size, const char *file, int line);

short f_050710(void *o, unsigned a);
int f_07a600(char *g);
int f_07a8a0(char *g);
int f_07a7e0(char *g);
int f_0709d0(char *g);
short f_07b740(char *g);
short f_07b790(char *g);
void f_077400(char *g);
void f_077540(char *g);
void f_077760(char *g, short idx, unsigned char b, unsigned char c);
void f_077e20(char *g, char *h, short x, short y);
void f_077fd0(char *g);
void f_078170(char *g);
void f_078430(char *g);
void f_078550(char *g);
void f_078790(char *g);
int f_0bd360(int a);
int f_0cf920(char *o, int v);
int f_0cf940(char *o, int v);
int f_0cf960(char *o, int v);
int f_0cf9a0(char *o, int v);
int f_0cf9d0(char *o, int i, int v);
int f_0cf9f0(char *o);
int f_0cfa00(char *o, int v);
int f_0cfa20(char *o, int v);
int f_0cfa30(char *o);
int f_0cfa40(char *o, int v);
int f_0cfa60(char *o, int v);
int f_0cfa80(char *o, int v);
int f_0cfaa0(char *o, int v);
int f_0cfac0(char *o, int v);
int f_0cfad0(char *o, int v);
int f_0cfb00(char *o, int v);
int f_0cfb40(char *o, int v);
int f_0cfb60(char *o, int v);
int f_0cfbc0(char *o, int v);
int f_0cfc20(char *o, int v);
int f_0cfc40(char *o, int v);
unsigned char f_0cfc50(char *o);
int f_0cfc60(char *o, int v);
signed char f_0cfc70(char *o);
int f_0cfc80(char *o, int v);
int f_0cfcd0(char *o, int v);
int f_0cfdd0(char *o, int v);
int f_0d0090(char *o, int v);
unsigned char f_0d00a0(char *o);
int f_0d00b0(char *o, int v);
int f_0d00d0(char *o, int v);
int f_0d00f0(char *o, int v);
int f_0d0110(char *o, int v);
int f_0d0130(char *o, int v);
int f_0d0150(char *o, int v);
int f_0d0170(char *o, int v);
int f_0d0190(char *o, int v);
void f_0d0230(char *o, const char *name);
int f_0d0260(char *o, int v);
int f_0d0680(char *o);
int f_0d06c0(char *o);
int f_0d0760(char *o);
int f_0de7d0(void *l, int q);
int f_0d4a60(int p);

signed char f_045610(int p);
signed char f_045660(int p);

int f_0789b0(char *g, char *h, int x, int y);
int f_072910(char *h);
int f_0728f0(char *h);
int f_06a6e0(void *p, void *a, int f);
unsigned char f_07ec10(char *p, int a);
int f_07eba0(char *p, int a, int b);
int f_07b370(char *g, int x, int y, int t, int c);
int f_06f5c0(char *g, char *o, char *q);
int f_06ed10(char *g, int s, char *q);
int f_071e50(char *g, int x, int y, int c);
int f_07aa40(int v);
int f_07a9e0(int v);
int f_07aa10(int v);
void *f_038c80(void *l);
int f_0391b0(void *l, int s);
unsigned char f_043470(int s);
int f_043480(int s, int v);

int f_0bf730(void *o, int v);
int f_0434a0(int s, int v);

int f_030e20(int s, int v);

signed char f_043490(int s);
unsigned char f_0d54c0(int s);
int f_0727e0(int s);
int f_0435c0(int s, int v);

int f_125400(void *o, void *a, void *b, void *c);
int f_1254a0(void *o, int v);
int f_04feb0(void *a, int b, int c, int d, int e, int f, void *g, void *h, int i);

//@ f_077400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Pollt im Kampf die Benutzer- und Timer-Events (f_068f40, f_0d5a90) und wertet gedrückte
 *   Schnellwahltasten (d_1bd75a) gegen die Tastentabelle d_1a1d34 aus, um Optionsflags in g + 0x3d7..0x3dd
 *   umzuschalten (mit Sonderprüfung auf aktive Magiekundige in der Gruppe).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sichert und setzt während des Aufrufs von f_068f40 den Callback-Zeiger d_1bf514 auf
 *   d_1a1d20 und verarbeitet d_1bd75a.
 === Ende Beschreibung === */
void f_077400(char *g)
{
    B14 buf = d_1a1d34;
    // Haelt die Sicherung von d_1bf514 ueber den Aufruf im Stapel wie im Original.
    int t = *(volatile int *)&d_1bf514;
    d_1bf514 = (int)d_1a1d20;
    f_068f40();
    d_1bf514 = t;
    f_0d5a90();
    if (d_1bd75a) {
        short s = f_149360(d_1bd75a, &buf);
        if (!*(unsigned char *)&d_1bd928) {
            int *tb = d_1c0004;
            int f1 = 0;
            short i1;
            int p1;
            for (i1 = 0; i1 <= 6; i1++) {
                p1 = tb[i1];
                if (!p1) continue;
                int c1 = (signed char)((unsigned char)(f_042400((struct hero *)(p1))));
                if (c1) continue;
                if (f_0d49b0(p1) != 1) continue;
                if (f_042750((struct hero *)(p1)) != 1) continue;
                f1 = 1;
                break;
            }
            if (f1 && (int)s == -1) PB(0x3dd) = 1;
            else if (s != -1) PB(s + 0x3d7) = 1;
            else {
                int f2 = 0;
                short i2;
                int p2;
                tb = d_1c0004;
                for (i2 = 0; i2 <= 6; i2++) {
                    p2 = tb[i2];
                    if (!p2) continue;
                    int c2 = (signed char)((unsigned char)(f_042400((struct hero *)(p2))));
                    if (c2) continue;
                    if (f_0d49b0(p2) != 1) continue;
                    if (f_042750((struct hero *)(p2)) != 1) continue;
                    f2 = 1;
                    break;
                }
                if (f2) PB(0x3dd) = 1;
            }
        } else {
            PB(0x3dd) = 1;
        }
        d_1bd75a = 0;
    }
}
//@ f_077540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Haupt-Initialisierungsroutine zu Beginn eines Kampfes: Lädt die Monster-Aktionsdaten
 *   (0x80010004), die Hindernis-Metadaten (0x260001 nach d_1bd944) und die Kampfdefinition (f_07a600 für feste
 *   Kämpfe <= 0xa5 bzw. d_1a2218 und f_0709d0 für dynamische Kämpfe), baut Hindernisse, Hintergrundbild, Monster
 *   und Helden auf dem Kampffeld auf (f_078430, f_07a7e0, f_078790, f_078550, f_077fd0, f_078170) und ermittelt
 *   die Startwerte der Kampfübersicht (f_07b740, f_07b790).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Allokiert den Kartenpuffer *(g + 0x1073) (0x26d Bytes) und den Aktionsdatenpuffer *(g +
 *   0x1fd).
 === Ende Beschreibung === */
void f_077540(char *g)
{
    int fl = 0;
    int sz;
    char *buf;
    short cc;
    short k;
    R69 rec;
    PS(0x19f) = f_0c0020(d_1c2c64, 3);
    PI(0x1073) = (int)f_014540(0x26d, d_1a1d44, 0x46);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x80010004, 0x200);
    sz = ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144a00()));
    buf = f_014540(sz, d_1a1d44, 0x49);
    PI(0x1fd) = (int)buf;
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( buf), sz)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    cc = f_050710(d_1c2be0, 0x260000);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x260001, 0x200);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( d_1bd944), (cc + 1) * 0x1a)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448d0( 0x1000f,(void *)( *(int *)&d_1bd940));
    int t_270 = PS(0x1ea);
    if (t_270 <= 0xa5) {
        f_07a600(g);
        f_07a8a0(g);
    } else {
        rec = d_1a2218[t_270 - 0xa6];
        PS(0xee7) = *(int *)(rec.b + 1);
        fl = 1;
        f_07a8a0(g);
    }
    if (d_1bd922 > 0) memset(g + 0xee9 + d_1bd922 * 15, 0, (0x14 - d_1bd922) * 15);
    d_1c2198 = 1;
    (*(volatile short *)&d_1bd90c) = d_1c2198;
    d_1c0c94 = 0;
    PS(0x1ec) = PS(0x1a9) = d_1c0c94;
    d_1bf510 = (int)d_1a5530;
    for (k = 0; k < (short)0x1e; k++) PS(0x1ab + k * 2) = 0;
    f_078430(g);
    f_07a7e0(g);
    f_078790(g);
    f_078550(g);
    if (fl == 1) f_0709d0(g);
    f_077fd0(g);
    PS(0x145) = f_07b740(g);
    PS(0x147) = f_07b790(g);
    f_078170(g);
}
//@ f_077760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den Monster-Stammdatensatz b (0x3a Bytes) aus dem Archiv 0x80010003, würfelt die
 *   zufallsabhängigen Werte (Eigenschaften, LE, AE, Rüstungsschutz) über f_0bd360 aus und initialisiert den
 *   Kampfeintrag d_1c2ed4 + idx * 0x73. Enthält außerdem Spezialanpassungen für Endgegner (f_0d0760), den
 *   Spiegelkampf gegen eigene Doppelgänger (d_1bd920 == 2, kopiert Werte der Gruppenhelden), Spezialkampf
 *   d_1bd920 == 7 und halbierte Astralenergie bei d_1bd920 == 5.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g, den Monster-Slot idx (0..19), die Monster-Stammnummer b
 *   (unsigned char) sowie die Start-Rundenverzögerung c (unsigned char) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Füllt die 0x73 Byte große Monsterstruktur in d_1c2ed4 und berücksichtigt den
 *   Schwierigkeitsgrad d_1bfaec.
 === Ende Beschreibung === */
void f_077760(char *g, short idx, unsigned char b, unsigned char c)
{
    struct Flags660 { static signed char a(){ return (signed char)d_1bfaec; } static signed char b(){ return d_1c0d88; } };
    Q3a q;
    int p;
    char *o;
    short i;
    unsigned short t;
    // Haelt b als Speicher-Lokale wie im Original.
    (void)&b;
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x80010003, 0x200);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( b * 0x3a, 0);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( &q), 0x3a)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    o = d_1c2ed4 + idx * 0x73;
    memset(o, 0, 0x73);
    f_0d0260(o, b);
    f_0cf920(o, q.b0);
    f_0cf940(o, q.b1);
    f_0cf9a0(o, q.b3);
    f_0cf960(o, q.b2);
    for (i = 0; i < 7; i++) f_0cf9d0(o, i, (signed char)f_0bd360(q.w[i]));
    f_0cfa00(o, (short)f_0bd360(q.w12));
    f_0cfa20(o, (short)f_0cf9f0(o));
    f_0cfa40(o, (short)f_0bd360(q.w14));
    f_0cfa60(o, (short)f_0cfa30(o));
    f_0cfa80(o, (signed char)f_0bd360(q.w16));
    f_0cfaa0(o, q.b18);
    f_0cfac0(o, q.b19);
    f_0cfad0(o, q.b1a);
    f_0cfb00(o, q.b1b);
    f_0cfb40(o, q.w1c);
    f_0cfb60(o, q.w1e);
    f_0cfbc0(o, q.b20);
    f_0cfc20(o, q.b21);
    f_0cfc40(o, q.b22);
    f_0cfdd0(o, 0);
    f_0cfc60(o, 0xff);
    f_0cfcd0(o, q.b23);
    f_0d0090(o, q.b24);
    f_0d00d0(o, q.b25);
    f_0d00b0(o, (signed char)c);
    f_0cfc80(o, *(signed char *)(g + idx * 15 + 0xeec));
    f_0d00f0(o, q.w26);
    f_0d0110(o, q.w28);
    f_0d0130(o, q.w2a);
    f_0d0150(o, q.w2c);
    f_0d0170(o, q.b2e);
    f_0d0190(o, q.b2f);
    if (f_0d0760(o)) {
        f_0cfa80(o, 0xf);
        f_0cfaa0(o, (unsigned char)(q.b18 + 5));
        f_0cfad0(o, (signed char)(q.b1a + 2));
        f_0cfcd0(o, 8);
        f_0d0170(o, 0);
        if (d_1bd920 == 4) {
            f_0cfc40(o, 0xd);
            f_0cfa40(o, 0xc8);
            f_0cfa60(o, (short)f_0cfa30(o));
        }
        return;
    }
    if (d_1bd920 == 2) {
        short qd;
        // Haelt qd im Stapel, damit t EBX behaelt wie im Original.
        (void)&qd;
        p = f_0de7d0((void *)d_1c0004, qd = idx / 3);
        if (f_0d4a60(p)) {
            if (f_042350((struct hero *)(p)) == 7 || f_042350((struct hero *)(p)) == 8 || f_042350((struct hero *)(p)) == 9) t = 0;
            else t = 1;
            strcpy(d_1c21b4, f_0422b0((struct hero *)(p)));
            strcat(d_1c21b4, d_1b6f5c);
            f_0d0230(o, d_1c21b4);
            f_0cf920(o, (unsigned char)(qd + 1));
            f_0cf940(o, ((unsigned char)(f_042360((struct hero *)(p)))));
            f_0cf9a0(o, (signed char)t);
            f_0cf960(o, f_0423f0((struct hero *)(p)));
            for (i = 0; i < 7; i++) f_0cf9d0(o, i, f_042a40((struct hero *)(p), i));
            f_0cfa00(o, f_042970((struct hero *)(p)));
            f_0cfa20(o, f_042970((struct hero *)(p)));
            if (Flags660::a() == 0) f_0cfa20(o, (short)(f_042970((struct hero *)(p)) / 2));
            f_0cfa40(o, f_0429b0((struct hero *)(p)));
            f_0cfa60(o, f_0429b0((struct hero *)(p)));
            f_0cfa80(o, f_0423a0((struct hero *)(p)));
#if FIX_R030   /* R030: Im Spiegelkampf (d_1bd920 == 2) den AT-Wert der Doppelgaenger auf max. 18 begrenzen */
            {
                unsigned char at = (unsigned char)(((unsigned char)(f_0428d0((struct hero *)(p)))) * 2);
                if (at > 18) at = 18;
                f_0cfaa0(o, at);
            }
#else
            f_0cfaa0(o, (unsigned char)(((unsigned char)(f_0428d0((struct hero *)(p)))) * 2));
#endif
            f_0cfac0(o, 1);
            f_0cfad0(o, f_045610(p));
            f_0cfb00(o, f_045660(p));
            f_0cfb40(o, 0x1106);
            f_0cfb60(o, 0x2102);
            f_0cfbc0(o, 8);
            f_0cfc20(o, 0);
            f_0cfc40(o, (signed char)(f_042a10((struct hero *)(p)) ? 0xe : -1));
            f_0cfdd0(o, 0);
            f_0cfc60(o, 0xff);
            f_0cfcd0(o, (signed char)((unsigned char)(f_0428d0((struct hero *)(p)))));
            f_0d0090(o, 4);
            f_0d00d0(o, 0);
            f_0d00f0(o, 0);
            f_0d0110(o, 0);
            f_0d0130(o, 0);
            f_0d0150(o, 0);
            f_0d0170(o, 0);
            f_0d0190(o, f_042380((struct hero *)(p)));
        } else {
            f_0cfdd0(o, 1);
            f_0d00b0(o, 0x63);
        }
        {
            *(short *)(g + idx * 15 + 0xeee) = 0;
            for (short j = 0; j < (short)4; j++) {
                *(short *)(g + idx * 15 + j * 2 + 0xef0) = 0;
            }
        }
        return;
    }
    if (d_1bd920 == 7 && f_0d0680(o)) {
        if (idx == 0) f_0cfbc0(o, 0);
        else f_0cfbc0(o, 2);
        return;
    }
    if (d_1bd920 == 5) {
        if (Flags660::b() == 1) {
            f_0cfa40(o, (short)((short)f_0bd360(q.w14) / 2));
            f_0cfa60(o, (short)f_0cfa30(o));
        }
    } else if (PS(0x1ea) == 0x95) {
        f_0d0170(o, 0);
    }
}
//@ f_077e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt für ein Monster h auf der Startkoordinate (x, y) das zugehörige Kampf-Animations- und
 *   Darstellungs-Objekt Y, trägt es in die Renderliste g + 0x39 ein und legt bei zweifeldrigen Großgegnern
 *   (f_072910(h)) zusätzlich ein zweites Listenelement für das hintere Körpersegment an. Übergroße Endgegner
 *   (f_0d06c0(h)) werden stattdessen an f_0789b0 delegiert.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g, den Monsterzeiger h sowie die Rasterkoordinaten x und y
 *   (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwaltet die Zeigerliste g + 0x211 (Zähler g + 0x291) und berechnet die Position des
 *   zweiten Segments über d_1a2734/d_1a2736.
 === Ende Beschreibung === */
void f_077e20(char *g, char *h, short x, short y)
{
    Y *p;
    if (f_0d06c0(h)) {
        f_0789b0(g, h, x, y);
        return;
    }
    p = new (mark(d_1a1d44, 0x157)) Y(g + 0x45, 1);
    PI(0x27) = PI(0x211 + SB(0x291)++ * 4) = (int)p;
    PB(0x1f) = x;
    PB(0x18) = PB(0x1f);
    PB(0x20) = y;
    PB(0x19) = PB(0x20);
    PB(0x26) = *(d_1bd984 + y * 25 + x);
    if (f_072910(h)) {
        PB(0x25) = ++PB(0x35a);
    } else {
        PB(0x25) = 0xff;
    }
    PB(0x24) = 1;
    PI(0x1a) = f_0728f0(h);
    PI(0x2b) = 0;
    PB(0x22) = 0x63;
    PB(0x23) = (unsigned char)(f_0d00a0(h) ? 0 : 1);
    f_0cfc60(h, f_07ec10(g + 0x39, -1));
    if (f_072910(h)) {
        PB(0x1f) = x + d_1a2734[f_0cfc70(h) * 4];
        PB(0x18) = PB(0x1f);
        PB(0x20) = y + d_1a2736[f_0cfc70(h) * 4];
        PB(0x19) = PB(0x20);
        PB(0x26) = *(d_1bd984 + SB(0x19) * 25 + SB(0x18));
        PB(0x24) = 1;
        PI(0x27) = 0;
        PB(0x22) = 0xa;
        PB(0x25) = PB(0x35a) + 0x14;
        f_07ec10(g + 0x39, -1);
    }
}

//@ f_077fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert alle bis zu 20 im aktuellen Kampf definierten Gegner (g + 0xee9 + i * 15), indem
 *   für jeden vorhandenen Eintrag f_077760 (Werte laden), f_077e20 (Sprite-Objekt anlegen), f_07b370 (Rasterfeld
 *   belegen, falls sofort anwesend) und f_06f5c0 (Grundanimation starten) aufgerufen werden.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Zählt in d_1bd924 die Gesamtzahl der im Kampf beteiligten Gegner.
 === Ende Beschreibung === */
void f_077fd0(char *g)
{
    char *o;
    char *q = 0;
    short y1 = 0;
    unsigned char t;
    char *r;
    short x1 = 0;
    short i;
    for (i = 0; (short)i < (short)0x14; i++) {
        o = d_1c2ed4 + i * 0x73;
        if (f_0cfc50(o) != (unsigned char)0xff) {
            f_07eba0(g + 0x39, f_0cfc50(o), 0);
            f_0cfc60(o, 0xff);
        }
        r = (char *)1; f_0cfdd0(o, (int)r);
    }
    d_1bd924 = 0;
    for (i = 0; (short)i < (short)0x14; i++) {
        r = g + i * 15;
        if (*(char *)(r + 0xee9) != (char)0) {
            unsigned char b;
            f_077760(g, i, (b = *(unsigned char *)(r + 0xee9)), *(unsigned char *)(r + 0xeed));
            d_1bd924++;
        }
    }
    i = 0;
    if (d_1bd924 > (short)0) {
        t = i + 10;
        q = g + 0x45;
        do {
            o = d_1c2ed4 + i * 0x73;
            r = g + i * 15;
            x1 = *(signed char *)(r + 0xeea);
            y1 = *(signed char *)(r + 0xeeb);
            f_077e20(g, o, *(signed char *)(r + 0xeea), *(signed char *)(r + 0xeeb));
            if (*(char *)(r + 0xeed) == (char)0)
                f_07b370(g, x1, y1, t, *(signed char *)(r + 0xeec));
            f_06f5c0(g, o, q);
            t++;
            i++;
        } while ((short)i < d_1bd924);
    }
}
//@ f_078170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Platziert zu Kampfbeginn alle Helden und Begleiter der aktuellen Gruppe d_1c0004 auf ihren
 *   Startfeldern (g + 0x1015 bzw. g + 0x102d für Begleiter), legt ihre Animations- und Renderobjekte an, zieht
 *   bei markierten Fernkämpfern automatisch die Schusswaffe (f_030e20) und gibt eine Meldung (0x10100a6) aus,
 *   falls ein Begleiter vor Kampfbeginn flieht.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verknüpft jeden Helden über f_043480(s, n) mit seinem Renderlisten-Index n und startet
 *   die Grundanimation über f_06ed10.
 === Ende Beschreibung === */
#pragma aux f_042800 modify [ebx];
void f_078170(char *g)
{
    S3c o;
    short k;
    short b;
    short a;
    int s;
    int start;
    int f;
    unsigned char n;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    s = (int)f_038c80(d_1c0004);
    start = s;
    do {
        if (f_043470(s) != (unsigned char)0xff) f_043480(s, 0xff);
        s = f_0391b0(d_1c0004, s);
    } while (s != start);
    k = -1;
    do {
        f = 1;
        k++;
        if (!f_042a10((struct hero *)(s))) f_042760((struct hero *)(s), 2);
        f_042800((struct hero *)(s), 0xd);
        f_0432c0((struct hero *)(s), 0xff);
        if (((unsigned char)(f_042400((struct hero *)(s))))) {
            if ((signed char)((unsigned char)(f_042400((struct hero *)(s)))) == 4) {
                o.p[1] = s;
                f_0bf730(d_1c2c64, 0x10100a6);
                f = 0;
            }
            if (f == 1) {
                a = SB(0x102d);
                b = SB(0x102e);
                f_0434a0(s, SB(0x102f));
                if (PB(0x1030)) {
                    if (!f_042470((struct hero *)(s))) f_030e20(s, f);
                }
                f_042740((struct hero *)(s), 1);
            }
        } else {
            a = SB((short)k * 4 + 0x1015);
            b = SB((short)k * 4 + 0x1016);
            f_0434a0(s, SB((short)k * 4 + 0x1017));
            if (PB((short)k * 4 + 0x1018)) {
                if (!f_042470((struct hero *)(s))) f_030e20(s, 1);
            }
        }
        if (f == 1) {
            Y *p;
            f_07b370(g, a, b, (unsigned char)(f_0d54c0(s) + 1), (signed char)f_043490(s));
            p = new (mark(d_1a1d44, 0x210)) Y(g + 0x45, 1);
            PI(0x211 + SB(0x291)++ * 4) = (int)p;
            PI(0x27) = (int)p;
            PB(0x1f) = a;
            PB(0x18) = a;
            PB(0x20) = b;
            PB(0x19) = b;
            PB(0x24) = 2;
            PI(0x1a) = f_0727e0(s);
            PI(0x2b) = 0;
            PB(0x26) = 0;
            PB(0x22) = 0x63;
            PB(0x23) = 1;
            PB(0x25) = 0xff;
            n = f_07ec10(g + 0x39, -1);
            f_043480(s, n);
            f_06ed10(g, s, g + 0x45);
            if ((signed char)f_0435c0(s, 3) == -1) f_042650((struct hero *)(s), 1);
        }
        s = f_0391b0(d_1c0004, s);
    } while (s != start);
    f_1254a0(&o, 0);
}
//@ f_078430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht das Kampfraster d_1bd984 (600 Bytes) und trägt aus der geladenen Kampfkarte *(g +
 *   0x1073) alle Rand-/Spezialfelder (>= 0xfd) sowie alle statischen mehrfeldrigen Großhindernisse (f_07aa40(v)
 *   != 0, samt ihren bis zu 10 relativen Sperrfeldern aus d_1bd944) als unpassierbar (0xfe) in d_1bd984 ein.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Liest die 24 x 24-Kartendaten ab Offset +0x15 in *(g + 0x1073) und die
 *   Mehrkachel-Offsets aus d_1bd944.
 === Ende Beschreibung === */
void f_078430(char *g)
{
    short a;
    short b;
    unsigned char v;
    short n;
    unsigned char w;
    signed char *r;
    char *map;
    memset(d_1bd984, 0, 600);
    for (a = 0; a < (short)0x18; a++) {
        for (b = 0; b < (int)0x18; b++) {
            map = *(char **)(g + 0x1073);
            v = *(unsigned char *)(map + a * 0x19 + b + 0x15);
            if (v >= (unsigned char)0xfd) {
                f_071e50(g, b, a, v);
                continue;
            }
            if (!f_07aa40((unsigned char)v)) continue;
            v -= 0x32;
            w = v;
            r = d_1bd944 + (w - 0x64) * 0x1a + 6;
            n = 0;
            while (n < (short)10) {
                if (r[n * 2] != -99)
                    f_071e50(g, (short)(r[n * 2] + b), (short)(r[n * 2 + 1] + a), 0xfe);
                n++;
            }
            f_071e50(g, b, a, 0xfe);
        }
    }
}
static inline short scrw078550() { return 0x140; }
//@ f_078550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt und platziert alle einfeldrigen Hindernis- und Dekorationsobjekte (0x32 <= v < 0xc8, für
 *   die f_07aa40(v) == 0 gilt) als eigenständige Tiefensortier-Sprites in der Renderliste g + 0x39 und trägt
 *   ihre Kennungen (sowie Sonderwerte 0xcc, 0xcd, 0xfe) in das Kampfraster d_1bd984 ein.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Cached geladene Hindernis-Bitmaps im Array d_1bd92c und speichert die erzeugten
 *   Renderlisten-IDs in d_1bd930 (Zähler d_1bd938).
 === Ende Beschreibung === */
void f_078550(char *g)
{
    unsigned char v;
    short H;
    short j;
    short vv;
    short W;
    short i;
    int e;
    X9 *p;
    int fl;
    for (i = 0; i < 0x18; i++) {
        for (j = 0; j < (short)0x18; j++) {
            v = *(unsigned char *)(PI(0x1073) + j * 0x19 + i + 0x15);
            if (v >= 0x32 && v < 0xc8 && !f_07aa40(v)) {
                fl = 0;
                if (v >= 0x96) fl = 1;
                v -= 0x32;
                if (d_1bd92c[v]) {
                    p = d_1bd92c[v];
                    ((RivaRasterImage*)(p))->f_0fb210((short *)( &H),(short *)( &W));
                } else {
                    e = fl == 1 ? 0x260000 : d_1a2510[*(signed char *)(PI(0x1073) + 0x14) * 3];
                    vv = fl == 1 ? v - 0x64 : v;
                    f_04feb0(d_1c2be0, e, PI(0), 0, vv, 0, &H, &W, scrw078550());
                    p = d_1bd92c[v] = new (mark(d_1a1d44, 0x28f)) X9(H, W);
                    ((RivaRasterImage*)(p))->f_0fb090((void *)( PI(0)));
                }
                PB(0x1e) = v;
                PB(0x18) = i;
                PB(0x19) = j;
                PB(0x1f) = f_07a9e0(v);
                PB(0x20) = f_07aa10(v);
                PB(0x24) = 0;
                PI(0x27) = 0;
                PI(0x2b) = (int)p;
                PB(0x22) = 0x32;
                PB(0x23) = 1;
                PB(0x25) = 0xff;
                d_1bd930[d_1bd938++] = f_07ec10(g + 0x39, -1);
                f_07b370(g, i, j, (unsigned char)(v + 0x32), 0);
            } else if (v == (unsigned char)0xcc || v == (unsigned char)0xcd || v == (unsigned char)0xfe) {
                f_071e50(g, i, j, v);
            }
        }
    }
}
short dx491(unsigned char);
#pragma aux dx491 "f_07a9e0" parm [eax] value [ax] modify exact [eax]
short dy491(unsigned char);
#pragma aux dy491 "f_07aa10" parm [eax] value [ax] modify exact [eax]
static inline unsigned char tile491(char *map,short row,short col){char *base=map+row*25;return (unsigned char)base[col+21];}
//@ f_078790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet alle statischen mehrfeldrigen Hintergrund-Hindernisse (f_07aa40(v) != 0) direkt in
 *   das gespeicherte Kampfhintergrundbild d_1bdaec, damit sie nicht in jedem Frame einzeln als bewegliche
 *   Sprites neu sortiert werden müssen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Lädt die Grafiken aus dem Archiv 0x260000, positioniert sie mit den Pixel-Offsets
 *   f_07a9e0/f_07aa10 und sichert das Ergebnis in d_1bdaec.
 === Ende Beschreibung === */
void f_078790(char *g)
{
    short sb;
    short sa;
    short c;
    short y;
    short x;
    short v;
    short a;
    short b;
    X9 *p;
    char *buf = f_014540(0x2710, d_1a1d44, 0x2be);
    // Haelt die Zeiger-Lebensdauer von g und d_1bd92c wie im Original.
    g = ((int)g & 0) ? (char *)0 : g;
    memcpy(*(char **)g, *(char **)d_1bdaec, 0xfa00);
    for (a = 0; a < (short)0x18; a++) {
        for (b = 0; b < 0x18; b++) {
            char *map = *(char **)(g + 0x1073);
            v=tile491(map,a,b);
            if (f_07aa40((unsigned char)v)) {
                v -= 0x32;
                if (d_1bd92c[v]) {
                    p = d_1bd92c[v];
                    ((RivaRasterImage*)(p))->f_0fb210((short *)( &sa),(short *)( &sb));
                } else {
                    f_04feb0(d_1c2be0, 0x260000, (int)buf, 0, (short)(v - 0x64), 0, &sa, &sb, 0x140);
                    d_1bd92c[v] = new (mark(d_1a1d44, 0x2d4)) X9(sa, sb);
                    p = d_1bd92c[v];
                    ((RivaRasterImage*)(p))->f_0fb090((void *)( (int)buf));
                }
                x = d_1a2744 - sa / 2 + (b + a) * 10;
                y = d_1a2746 - sb + (b-a)*5;
                x += dx491((unsigned char)v);
                y += dy491((unsigned char)v);
                ((RivaRasterImage*)(p))->f_0fae30((void *)( PI(0)), x, y, 1);
                { X9 **r_draw = d_1bd92c; d_1bd92c = r_draw; }
            }
        }
        { X9 **r_outer = d_1bd92c; d_1bd92c = r_outer; }
    }
    memcpy(*(char **)d_1bdaec, *(char **)g, 0xfa00);
    delete buf;
}

//@ f_0789a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion (ret), die keine Operationen ausführt.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0789a0()
{
}
