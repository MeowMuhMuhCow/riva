/* === Beschreibung (Katalog) ===
 * Einheit gz_0b1130g (0x0B1130 - 0x0B2180)
 *
 * Steuerung der animierten Ladesequenz (loadseq.smk) über einen Timer-Callback sowie zentrale Stadt-, Handlungs-
 * und Dialogereignisse in Riva (u. a. Heilung schwerverletzter Helden, Zufallsbegegnungen und Kapitelübergänge).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 8/13 gleich (suche.py 25.10.2026, Basis gz_0b1130_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 6 gleich (vorher 6), Rest 1078 (vorher 1085)
// gz_0b1130.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B1130-0x0B2180
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                             // reg eax edx stapel 0
int f_03eca0(int p1);                                   // reg eax stapel 0
int f_0422b0(int p1);                                   // reg eax stapel 0
signed char f_042380(int p1);
signed char f_042400(int p1);
int f_042960(int p1);                                   // reg eax stapel 0
int f_044890(int p1, int p2);                           // reg eax edx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0b0fc0(int p1, int p2);                           // reg eax edx stapel 0
int f_0b1090(int p1);                                   // reg eax stapel 0
unsigned short f_0b8a10(int p1);
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20(int,int,int,int,int);
#pragma aux f_0bfa20 parm caller [];                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4880(int p1);
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);
int f_0d5ff0(int p1);
int f_0d64a0();                       // nicht in clobber.tsv
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_0de7f0(int p1);
short f_0de820(int p1);
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_0ea740();                                         // reg - stapel 0
int f_0f6920(int);

int f_10b890(int p1);                                   // reg eax stapel 0
int f_11e910(int,int,int,int,int,int,int,int);
int f_11f320(int p1);                                   // reg eax stapel 0
int f_11f400(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3,int p4);
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147b97(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147c02(int p1, int p2);                           // reg eax edx stapel 0
int f_149e2e(const char *p1, int p2);
int f_14a1d0(int p1, int p2);
int f_14b100(int p1);
int f_14b3d0(int p1);
int f_14d040(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern signed char d_1a9670;
extern int d_1bd6c0;                    // 0x1BD6C0
extern signed char d_1bdcf4;
extern signed char d_1bdcf8;
extern signed char d_1bdcfc;
extern signed char d_1bdd00;
extern int d_1bdd04;                    // 0x1BDD04
extern signed char d_1bdd08;
extern signed char d_1bdd0c;
extern signed char d_1bed68;
extern signed char d_1bed8c;
extern signed char d_1bedb8;
extern signed char d_1bee1c;
extern signed char d_1bf1ac;                    // 0x1BF1AC
extern int d_1bfdbc;                    // 0x1BFDBC
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c00ac;
extern signed char d_1c00e0;
extern signed char d_1c01dc;
extern signed char d_1c01e0;
extern signed char d_1c01e4;
extern signed char d_1c01e8;
extern signed char d_1c01ec;
extern signed char d_1c01f0;
extern signed char d_1c01f4;
extern signed char d_1c0214;
extern signed char d_1c0284;
extern int d_1c0290;                    // 0x1C0290
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1b8208[];           // Text 0x1B8208
// --- eigene Funktionen (13), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

// --- Pass-1-Zusatz (Helfer H) ---
struct S { unsigned a; char *b; int c; int d; short e; };
struct O { int a; int *f4; int c[2]; int *f10; int r[10]; };
extern struct S d_1bed38;
struct ObjB { signed char a; short b; };
struct RegB { short count; ObjB **list; };
extern ObjB d_1bed50;
extern ObjB d_1bed54;
extern ObjB d_1bed58;
extern short d_1bed5c;
extern RegB d_1c212a;
extern unsigned d_1c3914;
extern int d_1c2e68;
extern const char d_1c2a74[];
#define A(x) ((int)&(x))
#define I32(p,o) (*(int *)((char *)(p) + (o)))
inline int EQ(int a, int b) { return a == b; }
inline int GT(int a, int b) { return a > b; }
#pragma aux f_11e910 parm caller [] modify exact [eax ecx edx];
#pragma aux f_149e2e parm caller [] modify [eax ecx edx];
#pragma aux f_14a1d0 parm routine [] modify exact [eax ebx ecx edx];
#pragma aux f_14b3d0 parm routine [] modify exact [eax ebx ecx edx edi];
#pragma aux f_14b100 parm routine [] modify exact [eax ebx ecx edx];

#define EQ(x,v) (((x)==(v))?1:0)
void f_0b1140(S *);
//@ f_0b1130
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion dient als parameterloser Timer-Callback für die Ladesequenz und ruft die
 *   Einzelbild-Weiterschaltung f_0b1140 mit der globalen Ladesequenz-Struktur (d_1bed38) auf.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b1130(void)
{
    void f_0b1140(S *);
    f_0b1140(&d_1bed38);
}

//@ f_0b1140
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt im Timerbetrieb jeweils das nächste Einzelbild des Smacker-Ladevideos (p->b) auf den
 *   Bildschirm aus, übernimmt etwaige Palettenwechsel (f_14d040) und beendet die Sequenz bei einem Abbruch durch
 *   das Dialogsystem (f_0e3360(&d_1c2c64)). (Hinweis: In gz_0b1130g_P1.CPP ist f_0b1140 doppelt markiert und
 *   steht mit versetztem Rumpfende bereits unter f_0b1286 im Katalog.)
 * - Eingaben: Übergeben wird ein Zeiger auf die Ladesequenz-Steuerstruktur (p, normalerweise &d_1bed38).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: p->b (Smacker-Player), p->d (Aktiv-Status), d_1c2c64 (Dialogsystem).
 === Ende Beschreibung === */
//@ f_0b11d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion startet oder reaktiviert die Anzeige der Ladesequenz: Ist die Sequenz aktiv
 *   (p->d == 1), blendet sie den Mauszeiger aus, gibt das erste Bild über f_0b1140 aus und registriert f_0b1130
 *   als periodischen Timer (f_147b97); andernfalls stellt sie den normalen Mauszeiger und die Standardpalette
 *   wieder her.
 * - Eingaben: Übergeben wird ein Zeiger auf die Ladesequenz-Steuerstruktur (p).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b11d0(struct S *p)
{
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    if (p->d == 1) {
        f_0d2710();
        f_0b1140(p);
        p->e = f_147b97(A(d_1c2edc), 0x78, (int)f_0b1130);
        return;
    }
    f_0d2f90(5, 1);
    f_149e2e(d_1c2a74, 0xff);
    f_0d26e0();
}

//@ f_0b1250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion pausiert eine laufende Ladesequenz, indem sie den registrierten Timer (p->e)
 *   bei der Timerverwaltung (d_1c2edc) abmeldet (f_147c02), den Mauszeiger ausblendet und den Bildschirmpuffer
 *   (d_1a34e0) aktualisiert.
 * - Eingaben: Übergeben wird ein Zeiger auf die Ladesequenz-Steuerstruktur (p).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b1250(struct S *p)
{
    if (p->d == 1 && (p->e != 0))
        f_147c02(A(d_1c2edc), p->e);
    f_09a140(0, 0x19);
    f_0d2710();
    f_09a0d0(d_1a34e0);
}

//@ f_0b1286
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion (deren Rumpfende im Originalcode bei 0x0b1286 hinter f_0b1250 liegt) gibt im
 *   Timerbetrieb jeweils das nächste Einzelbild des Smacker-Ladevideos (p->b) auf den Bildschirm aus, übernimmt
 *   etwaige Palettenwechsel (f_14d040) und beendet die Sequenz automatisch, sobald das Popup-/Dialogsystem
 *   (f_0e3360(&d_1c2c64)) einen Abbruch meldet.
 * - Eingaben: Übergeben wird ein Zeiger auf die Ladesequenz-Steuerstruktur (p, normalerweise &d_1bed38).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
// Astra1028 FINAL c47: 0B1286 ist das versetzte Rumpfende von f_0b1140.
// Die Definitionsfolge ist gezielt freigegeben; Maschinenfolge und Adressen bleiben original.
void paletteU1028(void *);
#pragma aux paletteU1028 "f_14d040" parm caller [] modify [eax ecx edx];
//@ f_0b1140
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt im Timerbetrieb jeweils das nächste Einzelbild des Smacker-Ladevideos (p->b) auf den
 *   Bildschirm aus, übernimmt etwaige Palettenwechsel (f_14d040) und beendet die Sequenz bei einem Abbruch durch
 *   das Dialogsystem (f_0e3360(&d_1c2c64)). (Hinweis: In gz_0b1130g_P1.CPP ist f_0b1140 doppelt markiert und
 *   steht mit versetztem Rumpfende bereits unter f_0b1286 im Katalog.)
 * - Eingaben: Übergeben wird ein Zeiger auf die Ladesequenz-Steuerstruktur (p, normalerweise &d_1bed38).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: p->b (Smacker-Player), p->d (Aktiv-Status), d_1c2c64 (Dialogsystem).
 === Ende Beschreibung === */
void f_0b1140(S *p)
{
    int state=p->d;
    if(state==1) {
        if(f_0e3360(A(d_1c2c64))==state) {
            p=(S *)state;
            if(d_1bed38.d==1 && d_1bed38.e != 0)
                f_147c02(A(d_1c2edc),d_1bed38.e);
            f_09a140(0,25);
            f_0d2710();
            f_09a0d0(d_1a34e0);
            f_0b1090(A(d_1bed38));
            if((int)p==1) {
                f_09a400();
                f_0d2f90(0,(int)p);
                f_0d26e0();
            }
            return;
        }
        if(f_0d3860()==state) f_0d2710();
        if(*(unsigned *)&d_1c3914>=p->a) {
            int keep=state; // haelt die Registerzuteilung wie im Original
            p->a=*(volatile unsigned *)&d_1c3914+1+(unsigned)(keep-state);
            f_14b3d0((int)p->b);
            if(I32(p->b,0x68)) paletteU1028(p->b+0x6c);
            while(f_14a1d0(1,(int)p->b)) {
                char *q=p->b;
                f_11e910(p->c,
                    I32(q,0x374),I32(q,0x378),I32(q,0x37c),I32(q,0x380),160,
                    I32(q,0x374)+80,I32(q,0x378)+50);
            }
            f_14b100((int)p->b);
            f_0d4880(A(d_1c2e68));
        }
    }
}

//@ f_0b1340
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion öffnet die Smacker-Videodatei "loadseq.smk" (d_1b8208) über f_0b0fc0 in der
 *   globalen Struktur d_1bed38 und startet bei erfolgreichem Öffnen (d_1bed38.d == 1) die zeitgesteuerte
 *   Wiedergabe der Ladesequenz über f_0b1140 und den Timer f_147b97.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b1340(void)
{
    f_0b0fc0(A(d_1bed38), (int)d_1b8208);
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    if (d_1bed38.d == 1) {
        f_0d2710();
        f_0b1140(&d_1bed38);
        d_1bed38.e = f_147b97(A(d_1c2edc), 0x78, (int)f_0b1130);
        return;
    }
    f_0d2f90(5, 1);
    f_149e2e(d_1c2a74, 0xff);
    f_0d26e0();
}

//@ f_0b13d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion beendet die Wiedergabe der globalen Ladesequenz (d_1bed38), meldet den Timer
 *   ab (f_147c02), gibt die Smacker-Ressourcen über f_0b1090 frei und stellt bei x == 1 die Spielpalette
 *   (f_09a400) sowie den Mauszeiger (f_0d26e0) wieder her.
 * - Eingaben: Übergeben wird ein Steuerflag (x), das angibt, ob Palette und Mauszeiger anschließend reaktiviert
 *   werden sollen (1 = ja).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b13d0(int x)
{
    if (d_1bed38.d == 1 && (d_1bed38.e != 0))
        f_147c02(A(d_1c2edc), d_1bed38.e);
    f_09a140(0, 0x19);
    f_0d2710();
    f_09a0d0(d_1a34e0);
    f_0b1090(A(d_1bed38));
    if (x == 1) {
        f_09a400();
        f_0d2f90(0, x);
        f_0d26e0();
    }
}

//@ f_0b1440
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion registriert die drei globalen Ereignis-/Zustandsflags d_1bed50 (Kennung
 *   0x0b), d_1bed54 (Kennung 0x26) und d_1bed58 (Kennung 0x8d) mit dem Startwert 0 in der globalen
 *   Spielstands-Variablentabelle (d_1c212a).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
inline signed char z_0b1440()
{
    signed char c = 0;
    return c;
}

inline void add_0b1440(ObjB &o, RegB &r, short id)
{
    o.a = z_0b1440();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}

void f_0b1440(void)
{
    add_0b1440(d_1bed50, d_1c212a, 0xb);
    add_0b1440(d_1bed54, d_1c212a, 0x26);
    add_0b1440(d_1bed58, d_1c212a, 0x8d);
}

//@ f_0b14e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Filterfunktion prüft für einen Helden (p), ob er handlungsfähig ist (f_0d4a60) und das
 *   Geschlechtsflag 1 (f_042380, weiblich) besitzt.
 * - Eingaben: Übergeben wird ein Zeiger auf die zu prüfende Heldenstruktur (p).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held aktiv und weiblich ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0b14e0(int p)
{
    int r = 0;
    if (f_0d4a60(p) != 0) {
        if (f_042380(p) == 1)
            r = 1;
    }
    return r;
}

//@ f_0b1510
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion durchläuft alle Mitglieder einer Teilgruppe (p) und heilt jeden Helden,
 *   dessen aktuelle Lebensenergie (f_042960) auf 5 oder weniger Punkte gefallen ist, über f_044890 wieder auf
 *   genau 5 Lebenspunkte hoch.
 * - Eingaben: Übergeben wird ein Zeiger auf die Gruppenstruktur (p).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b1510(int p)
{
    int q = f_038c80(p);
    do {
        if (q != 0) {
            short s = f_042960(q);
            if (s <= 5)
                f_044890(q, (short)(5 - s));
            q = f_0391b0(p, q);
        }
    } while (q != f_038c80(p));
}

//@ f_0b1560
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion durchläuft alle sechs möglichen Teilgruppen im globalen Gruppen-Array
 *   (d_1bfdbc, Schrittweite 0x61), überspringt die in d_1a9670 ausgeschlossene Gruppe und heilt in jeder
 *   belegten Gruppe alle dem Tode nahen Helden auf mindestens 5 Lebenspunkte hoch.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b1560(void)
{
    short i;
    int p, q;
    for (i = 0, p = A(d_1bfdbc); i < 6; i++, p = A(d_1bfdbc) + i * 0x61) {
        if (i != d_1a9670 && f_0de7f0(p) > 0) {
            int c = p;
            q = f_038c80(c);
            do {
                if (q != 0) {
                    short s = f_042960(q);
                    if (s <= 5)
                        f_044890(q, (short)(5 - s));
                    q = f_0391b0(c, q);
                }
            } while (q != f_038c80(c));
        }
    }
}

//@ f_0b15f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft bei Orts- und Stundenwechseln (d_1bf1ac) globale Handlungsbedingungen:
 *   Am Ortstyp 0x0b löst sie je nach Questflags (d_1bedb8, d_1bee1c, d_1bed68) Spezialereignisse oder einen
 *   Bestätigungsdialog (0x2200002f) aus, und bei aktivem Stundenflag (d_1bed50.a == 1) am Ortstyp 0x0a würfelt
 *   sie zur vollen Stunde mit 10 % Wahrscheinlichkeit eine atmosphärische Zufallsbegegnung (Texte 0x22000025 bis
 *   0x2200002e) aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (arbeitet auf den globalen Orts-, Zeit- und
 *   Questvariablen).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein spezieller Ortswechsel (d_1bed5c = 6) ausgelöst wurde,
 *   und sonst 0.
 === Ende Beschreibung === */
struct MsgC { int h; int *q[14]; MsgC(void*,void*,void*); ~MsgC(); };

int f_0b15f0(void)
{
    int result = 0;
    if (f_0b8a10(*(int *)&d_1bf1ac) == 0xb) {
        if (EQ(d_1c00ac, 0) && EQ(d_1bedb8, 1)) {
            f_0ea740();
        } else if (EQ(d_1bed8c, 0) && EQ(d_1bee1c, 1) && GT(d_1c00e0, 0)) {
            d_1bed5c = 6;
            result = 1;
        } else if (EQ(d_1bed68, 1)) {
            if (f_0bf6f0(A(d_1c2c64), 0x2200002f) == 1)
                d_1bed68 = 2;
            else
                d_1bed68 = 0;
        }
    }
    if (EQ(d_1bed50.a, 1)) {
        int event = *(int *)&d_1bf1ac;
        f_11f320(event);
        f_11f400(event);
        d_1bed50.a = 0;
        int event_type = f_0b8a10(*(int *)&d_1bf1ac);
        if (event_type == 0xa) {
            if (f_126410(A(d_1c2c44)) % 0x1518 == 0) {
                if (EQ(d_1bed58.a, 0)) {
                    if ((short)f_1457e0(0x64) <= 10) {
                        MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
                        f_0bf730(A(d_1c2c64), 0x22000025);
                        d_1bed58.a = 0x30;
                        int choice = f_1457e0(3);
                        switch ((unsigned short)choice) {
                        case 1: {
                            int b = f_039ac0(d_1c0004, (int)f_0b14e0);
                            f_0bf730(A(d_1c2c64), 0x22000026);
                            if (b) {
                                m.q[3][1] = f_133fe0(A(d_1c3498), f_0422b0(b));
                                m.q[3][2] = m.q[3][1];
                            } else {
                                m.q[3][1] = 0x22000027;
                                m.q[3][2] = 0x22000028;
                            }
                            f_0bf730(A(d_1c2c64), 0x22000029);
                            f_0bf730(A(d_1c2c64), 0x2200002a);
                            break;
                        }
                        case 2:
                            f_0bf730(A(d_1c2c64), 0x2200002b);
                            f_0bf730(A(d_1c2c64), 0x2200002c);
                            break;
                        case 3:
                            m.q[0][1] = f_038c40(d_1c0004);
                            f_0bf730(A(d_1c2c64), 0x2200002d);
                            f_0bf730(A(d_1c2c64), 0x2200002e);
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}
//@ f_0b18f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion prüft, ob der Gruppe derzeit ein Nichtspielercharakter (NPC-Begleiter,
 *   abgefragt über f_039040(d_1c0004)) angeschlossen ist, dessen Typkennung (f_042400) den Wert 1 hat.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der gesuchte NPC-Begleiter in der Gruppe ist, und sonst 0.
 === Ende Beschreibung === */
int f_0b18f0(void)
{
    int r = 0;
    if (f_039040(d_1c0004) != 0) {
        if (f_042400(f_039040(d_1c0004)) == 1)
            r = 1;
    }
    return r;
}

//@ f_0b1920
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion steuert die mehrstufigen Handlungsdialoge und Questfortschritte an einem
 *   wichtigen Schlüsselort (Textbereich 0x25000050 bis 0x25000071, mit zwei Gesprächspartner-Porträts aus
 *   0x250001): Je nach aktuellem Kapitel- und Queststatus (d_1c0214, d_1c01dc, d_1bdcf8, d_1c01e4, d_1bdd00,
 *   d_1c01e8, d_1c01ec, d_1c01f0) führt sie Gespräche, heilt die Gruppe, schaltet Kartenmarkierungen (f_056a40),
 *   vergibt Tagebucheinträge (f_057220), zieht Questgegenstände (0x163 und 0x1b4) ein und startet
 *   Übergangssequenzen.
 * - Eingaben: Übergeben wird ein Zeiger auf das aktuelle Orts-/Gebäudeobjekt (p).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Begegnung zum sofortigen Verlassen des Ortes führt
 *   (d_1c0214 == 2), und sonst 0.
 === Ende Beschreibung === */
static inline int eq680(const signed char &a,int b){return a==b;}
static inline int gt680(const signed char &a,int b){return a>b;}
static inline void heal680(int hero){int member=f_038c80(hero);do{if(member){short life=f_042960(member);if(life<=5)f_044890(member,(short)(5-life));member=f_0391b0(hero,member);}}while(member!=f_038c80(hero));}
#define TALK680(R,N) f_0bfa20(A(d_1c2c64),(R),0,0x25000000+(N),0)
#define SLOT680(V) (dialog.f4[1]=(V))
int f_0b1920(int p){
int result=0;O dialog;int a,b,event,hero;short i;
a=f_0606a0(0x250001,4);b=f_0606a0(0x250001,5);f_125400(A(dialog),A(d_1c349c),A(d_1c3870),A(d_1c3498));
f_0bf6c0(A(d_1c2c64),6);((void(*)(int))(*(int**)(p+0x58))[1])(p);
if(eq680(d_1c0214,2)){f_0bf730(A(d_1c2c64),0x25000050);f_0d5ff0(6);result=1;d_1c0214=1;}
else{
 if(eq680(d_1c01dc,1)){
  TALK680(a,0x51);SLOT680(f_038c40(d_1c0004));TALK680(a,0x52);TALK680(a,0x53);
  SLOT680(f_039320(d_1c0004,0x18));TALK680(b,0x54);TALK680(b,0x55);
  d_1c01dc=0;f_091f70(0x13);f_0d5ff0(6);f_057220(A(d_1c2c00),0x8030031,0);d_1c0214=1;
  if(d_1bd6c0&&f_0de820(d_1c0004)==2)f_0f6920(d_1bd6c0);
 }else{
  if(gt680(d_1bdcf8,1)&&eq680(d_1c01e0,0)){for(i=0,hero=A(d_1bfdbc);i<6;++i,hero=A(d_1bfdbc)+i*0x61){if(i!=d_1a9670&&f_0de7f0(hero)>0)heal680(hero);}TALK680(a,0x56);d_1c01e0=1;}
  if(eq680(d_1bdcf8,1)){TALK680(b,0x57);d_1bdcf8=0;d_1c01e4=1;*(signed char*)&d_1c0290=1;f_056930();f_056a40(8);f_056a40(7);f_056950();}
 }
 if(eq680(d_1c01e4,1)){
  if(f_039040(d_1c0004)&&f_042400(f_039040(d_1c0004))==6)TALK680(b,0x58);
  f_0d64a0();TALK680(a,0x59);event=f_0dd3a0(d_1c0004,9,0);
  if(event){SLOT680(event);f_0bf730(A(d_1c2c64),0x2500005a);}
  TALK680(a,0x5b);TALK680(a,0x5c);f_057220(A(d_1c2c00),0x8030032,0);d_1c01e4=0;d_1bdd00='I';d_1bed54.a=1;
 }else{
  if(gt680(d_1bdd00,1)){if(eq680(d_1bed54.a,0)){TALK680(a,0x5d);d_1bed54.a=1;}}
  else if(eq680(d_1bdd00,1)){d_1bdd08=1;if(eq680(d_1c0284,0))d_1c0284=1;d_1bdd00=0;}
  if(eq680(d_1bdd08,1)&&eq680(d_1bdd0c,0)){
   TALK680(a,0x5e);TALK680(b,0x5f);SLOT680(f_038c40(d_1c0004));TALK680(b,0x60);
   SLOT680(f_039660(d_1c0004,13));TALK680(b,0x61);f_057220(A(d_1c2c00),0x8030033,0);d_1bdd0c=1;
  }
 }
 if(eq680(d_1c01e8,1)){
  SLOT680(f_038c40(d_1c0004));f_0bf730(A(d_1c2c64),0x25000062);f_03eca0(3);
  f_0bf730(A(d_1c2c64),0x25000063);f_0bf730(A(d_1c2c64),0x25000064);f_10b890(15);
  f_0bf730(A(d_1c2c64),0x25000065);f_0bf730(A(d_1c2c64),0x25000066);f_0bf730(A(d_1c2c64),0x25000067);d_1bdcfc=25;d_1c01e8=0;
 }
 if(eq680(d_1bdcfc,1)){*(signed char*)&d_1bdd04=1;d_1bdcfc=0;f_056930();f_056a40(11);f_056950();}
 if(eq680(d_1c01ec,1)){
  f_0bf730(A(d_1c2c64),0x25000068);f_0bf730(A(d_1c2c64),0x25000069);SLOT680(f_038c40(d_1c0004));f_0bf730(A(d_1c2c64),0x2500006a);d_1c01ec=0;d_1c01f0=1;
 }
 if(gt680(d_1bdcf4,1)){if(eq680(d_1bed54.a,0)){f_0bf730(A(d_1c2c64),0x2500006b);d_1bed54.a=1;}}
 else if(eq680(d_1bdcf4,1)&&eq680(d_1c01f4,0)){
  SLOT680(f_038c40(d_1c0004));dialog.f4[2]=f_039660(d_1c0004,13);
  f_0bf730(A(d_1c2c64),0x2500006c);f_0bf730(A(d_1c2c64),0x2500006d);f_0bf730(A(d_1c2c64),0x2500006e);f_0bf730(A(d_1c2c64),0x2500006f);d_1c01f4=1;
 }
 if(eq680(d_1c01f0,1)&&f_0d54f0(d_1c0004,0x163)!=-1&&f_0d54f0(d_1c0004,0x1b4)!=-1){
  SLOT680(f_038c40(d_1c0004));f_0bf730(A(d_1c2c64),0x25000070);f_0bf730(A(d_1c2c64),0x25000071);d_1c01f0=0;d_1bdcf4='I';f_0dd1d0(d_1c0004,0x163);f_0dd1d0(d_1c0004,0x1b4);
 }
}
f_0bf680(A(d_1c2c64));if(a)delete(char*)((int)(((RivaRasterImage*)(a))->f_0fad20(0)));if(b)delete(char*)((int)(((RivaRasterImage*)(b))->f_0fad20(0)));
f_1254a0(A(dialog),0);
return result;
}
#undef TALK680
#undef SLOT680
