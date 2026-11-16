/* === Beschreibung (Katalog) ===
 * Einheit ship3_t1 (107380 - 1087c0)
 *
 * Überblick
 *
 * Die Einheit ship3_t1 bildet den ersten Teil des 3D-Dungeon-Moduls ship3 (Kennung 0x2c, dritter Bereich des
 * Schiffswracks). Sie enthält den großen Karten-Ereignisverteiler (f_107380) sowie die Raum-, Tür- und
 * Kampffunktionen dieses Schiffsabschnitts (f_107f30 bis f_108790).
 === Ende Beschreibung === */
// Astra782: Teil t1 endet vor f_1087c0; die 12 nachfolgenden Definitionen gehoeren zu ship3_t2.
// ship3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x107380-0x1087C0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_0424f0(int p1, int p2);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_047650(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbb50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0fb660(int p1, int p2);                           // reg edx stapel 0
int f_0fca60(int p1);                                   // reg eax stapel 0
int f_108d10(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
extern short d_1c2c40;                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1a68a4[];           // Text 0x1A68A4
// --- eigene Funktionen (20), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern signed char d_1c037c, d_1c0380, d_1c0390, d_1c03a0, d_1c03a4, d_1c03a8, d_1c0364;
extern volatile signed char d_1c0370; // haelt das Speicherschreiben ueber Lokalvariable in f_107380 wie im Original
extern signed char d_1c0428;
extern short d_1a6834[];
int f_0bf820(int p1, ...);
signed char f_0dd410(int p1, int p2);
int f_042a60(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
short f_0d54f0(int p1, int p2);
short f_1457e0(int p1);
struct Obj { int f0; char *p[13]; short s38; Obj(const char *, const char *, const char *); ~Obj(); };
struct S14 { int a[5]; };
struct S0c { int a[3]; };
#define MBOX ((int)&d_1c2c64)
#define EQI(x,v) (((x)==(v))?1:0)
#define GTI(x,v) (((x)>(v))?1:0)
#define NEWA(LINE,K) { S14 *o = new (mark(d_1a68a4, LINE)) S14; o = o ? (S14 *)f_112df0((int)o, K, 0, 0) : o; f_112ec0((int)o); if (o) operator delete((void *)f_112e70((int)o, 0)); }
#define NEWC(LINE,K) { S0c *o = new (mark(d_1a68a4, LINE)) S0c; o = o ? (S0c *)f_046d10((int)o, K) : o; f_046de0((int)o); if (o) operator delete((void *)f_046d90((int)o, 0)); }
#define NEWD(LINE,K) { S0c *o = new (mark(d_1a68a4, LINE)) S0c; o = o ? (S0c *)f_046d10((int)o, K) : o; f_047650((int)o, 0); f_046de0((int)o); if (o) operator delete((void *)f_046d90((int)o, 0)); }
#define EQF(x,v) EQI(x,v)
#define NEF(x,v) (((x)!=(v))?1:0)
#define RET return r
void f_108190(void);
void f_1083c0(void);
void f_1087c0(void);

//@ f_107380
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Verteilerfunktion verarbeitet sämtliche Karten- und Interaktionsereignisse (0x00 bis
 *   0x32) im Schiffsabschnitt ship3, darunter das Aufbrechen von Türen, das Durchsuchen von Frachtkisten, Kämpfe
 *   und Übergänge zu anderen Schiffsteilen.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Aktionszeiger p3.
 * - Rückgabewert: Die Funktion gibt den Statuscode der ausgeführten Interaktion zurück.
 === Ende Beschreibung === */
int f_107380(int p1, unsigned short p2)
{
    int r = 0;
    struct Raw {int v;char *p[13];int end;};
    Raw *f_125400(Raw*,const char*,const char*,const char*);int f_1254a0(Raw*,int);
    struct F{Raw inner,outer;}frame;
    struct E{static int eq(int a,int b){return b == a?1:0;} static int eqc(signed char a,int b){signed char aa=a;return b==aa?1:0;} static int eq0(signed char a){int b=d_1c037c;return eq(a,b);}};
    if ((short)p2 != 0) {
        r = 1;
        switch (p2) {
        case 0xc9: case 0x2bd:
            f_0bf730(MBOX, 0x2f000127); break;
        case 0xca: { int q=(int)mark(d_1a68a4,0x1cd); q=(int)operator new(20,(void*)q); int t=q; if(t)q=f_112df0(t,0x61,q^t,0); f_112ec0(q);if(q)operator delete((void*)f_112e70(q,0)); } break;
        case 0xcb: { int q=(int)mark(d_1a68a4,0x1df); q=(int)operator new(20,(void*)q); int t=q; if(t)q=f_112df0(t,0x62,q^t,0); f_112ec0(q);if(q)operator delete((void*)f_112e70(q,0)); } break;
        case 0x12d: f_0bf730(MBOX, 0x2f000128); break;
        case 0x12e: { int q=(int)mark(d_1a68a4,0x1ff); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x42);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x12f: { int q; q=(int)operator new(q,mark((q=12,d_1a68a4),0x211)); if(q)q=f_046d10(q,0x43);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x130: { int q=(int)mark(d_1a68a4,0x223); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x44);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x131: f_0bf730(MBOX, 0x2f000129); f_125ed0((int)&d_1c2c44, 2); break;
        case 0x191: ((void(*)(int))f_108190)(p1); break;
        case 0x192: ((void(*)(int))f_1083c0)(p1); break;
        case 0x193: f_0bf730(MBOX, 0x2f00013c); break;
        case 0x194: { int t,q; t=(int)operator new(q,mark((q=20,d_1a68a4),0x309)); q=t; if(t)q=f_112df0(t,0x65,q^t,0); f_112ec0(q);if(q)operator delete((void*)f_112e70(q,0)); } break;
        case 0x195: f_0bf730(MBOX, 0x2f00013d); break;
        case 0x196: if (E::eq0((signed char)p1^(signed char)p1) && f_0dd410(d_1c0004, 1) == 5) { f_0bf730(MBOX, 0x2f00013e); d_1c037c = 1; }
            f_05fa00(0x31, 0x1f42); break;
        case 0x1f5:
            if(E::eqc(3,d_1c03a8)) f_0bf730(MBOX,0x2f00013f);
            else if(E::eq((signed char)2,d_1c03a8)) f_0bf730(MBOX,0x2f000140);
            else f_0bf730(MBOX,0x2f000141);
            break;
        case 0x1f6: { int q; q=(int)operator new(q,mark((q=12,d_1a68a4),0x356)); if(q)q=f_046d10(q,0x45);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x1f7: { int q; q=(int)operator new(q,mark((q=12,d_1a68a4),0x368)); if(q)q=f_046d10(q,0x46);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x1f8:
            f_0bf6c0(MBOX, 5); f_0bf730(MBOX, 0x2f000142); f_0bf680(MBOX); break;
        case 0x1f9: case 0x1f46:
            ((void(*)(int))f_1087c0)(p1); break;
        case 0x259: { int q=(int)mark(d_1a68a4,0x3f6); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x47); f_047650(q,0); f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x25a: { int q=(int)mark(d_1a68a4,0x40a); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x48);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x25b: { int q; q=(int)operator new(q,mark((q=12,d_1a68a4),0x41c)); if(q)q=f_046d10(q,0x49); f_047650(q,0); f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x25c: { int q=(int)mark(d_1a68a4,0x430); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x4a); f_047650(q,0); f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x25d: { int q=(int)mark(d_1a68a4,0x449); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x4b);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x2be: f_0bf730(MBOX, 0x2f000153); break;
        case 0x2bf: f_0bf730(MBOX, 0x2f000154); break;
        case 0x2c0: { int q; q=(int)operator new(q,mark(d_1a68a4,(q=12,0x483))); if(q)q=f_046d10(q,0x4c);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x2c1: f_0bf730(MBOX, 0x2f000155); break;
        case 0x2c2: { int q=(int)mark(d_1a68a4,0x4a3); q=(int)operator new(12,(void*)q); if(q)q=f_046d10(q,0x4d);  f_046de0(q);if(q)operator delete((void*)f_046d90(q,0)); } break;
        case 0x2c3: case 0x1f41:
            f_108d10(p1); break;
        case 0x2c4: {
            int saved = p1;
            int menuCount;
            p1 = f_0bf820(MBOX, 0x2f000167, menuCount=3, 0x2f000168, 0x2f000169, 0x2f00016a);
            switch((unsigned short)p1) {case 1:{signed char z=0;d_1c0370=z;}f_0fca60(saved);break;
            case 2:f_0bf730(MBOX,0x2f00016b);f_0bf730(MBOX,0x2f000163);f_0bf730(MBOX,0x2f000164);f_0de210(d_1c0004);break;} break; }
        case 0x321:
            if (f_0bf6f0(MBOX, 0x2f00016c) == 1) { f_0dd7f0(d_1c0004, 0x18, 0x146b); break; }
            break;
        case 0x322: break;
        case 0x328: {
            f_125400(&frame.outer,d_1c349c,d_1c3870,d_1c3498);
            *(int *)(frame.outer.p[0] + 4) = f_038c40(d_1c0004);
            {
                f_125400(&frame.inner,d_1c349c,d_1c3870,d_1c3498);
                f_038c40(d_1c0004);
                f_060800(0x2f000b, 0, 0);
                f_0dbb50(d_1c0004, 1, 6);
                f_1254a0(&frame.inner,0);
            }
            f_0bf730(MBOX, 0x2f000174);
            f_0dbb50(d_1c0004, 1, 6);
            f_0bbf00((int)&d_1bf230);
            f_1254a0(&frame.outer,0);
            break; }
        case 0x1f42:
            if (E::eq(d_1c037c,(signed char)0) && f_0dd410(d_1c0004, 1) == 5) { f_0bf730(MBOX, 0x2f00013e); *(volatile signed char *)&d_1c037c = 1; } // erzwingt direktes Byte-Immediate-Schreiben wie im Original
            f_05fa00(0x31, 0x1f42); break;
        case 0x1f43: f_05fa00(0x32, 0x1f43); break;
        case 0x1f44: f_05fa00(0x33, 0x1f44); break;
        case 0x1f45: f_05fa00(0x34, 0x1f45); break;
        case 0x1f47: f_05fa00(0x36, 0x1f47); break;
        case 0x1b59: case 0x1b5a: case 0x1b5b: case 0x1b5c: case 0x1b5d: case 0x1b5e: case 0x1b5f:
            f_0fb660(p1, (short)p2); r=0; break;
        default:
            r=0; break;
        }
    }
    return r;
}

//@ f_107f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode initialisiert die 3D-Ansicht von ship3, schaltet die Unterwasser- und Lichteffekte
 *   (f_120bd0, f_123080) ein und synchronisiert die Türen über f_108cc0.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_107f30(void)
{
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    f_038c40(d_1c0004);
    f_060800(0x2f000b, 0, 0);
    f_0dbb50(d_1c0004, 1, 6);
}

//@ f_107f90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode verarbeitet die automatischen Schritt- und Zeitereignisse in ship3.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Ereigniscode p2 sowie einen Statuszeiger p3.
 * - Rückgabewert: Die Funktion gibt 0 zurück.
 === Ende Beschreibung === */
void f_107f90(void) { f_0bf730(MBOX, 0x2f000127); }

//@ f_107fb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sieben Methoden geben beim erstmaligen Betreten bestimmter Schiffsräume atmosphärische
 *   Beschreibungen aus, schalten Raumflags (d_1c0418 bis d_1c041e) um oder starten Kämpfe (0x1f41).
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void) bzw. geben das Ergebnis von f_05fa00 zurück.
 === Ende Beschreibung === */
void f_107fb0(void) NEWA(0x1cd, 0x61)

//@ f_108000
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert ein 20-Byte-Truhen-/Behälterobjekt (f_112df0) mit Kennung 0x62
 *   (Quellzeile 0x1df), führt dessen Interaktion über f_112ec0 aus und gibt das Objekt über f_112e70 wieder
 *   frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 als Dateimarkierung für new.
 * - Besonderheiten: Zweiter Teil der Sammelgruppe ab f_107fb0.
 === Ende Beschreibung === */
void f_108000(void) NEWA(0x1df, 0x62)

//@ f_108050
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt den Raum- bzw. Untersuchungstext 0x2f000128 über f_0bf730 im Dialogkontext
 *   d_1c2c64 aus.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (MBOX).
 * - Besonderheiten: Kurzer Text-Trigger in ship3.
 === Ende Beschreibung === */
void f_108050(void) { f_0bf730(MBOX, 0x2f000128); }

//@ f_108070
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x42 (Quellzeile
 *   0x1ff), führt die Übergabe über f_046de0 aus und baut das Objekt mit f_046d90 wieder ab.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEWC).
 === Ende Beschreibung === */
void f_108070(void) NEWC(0x1ff, 0x42)

//@ f_1080c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x43 (Quellzeile
 *   0x211), führt f_046de0 aus und gibt den Speicher wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEWC).
 === Ende Beschreibung === */
void f_1080c0(void) NEWC(0x211, 0x43)

//@ f_108110
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x44 (Quellzeile
 *   0x223), führt f_046de0 aus und gibt den Speicher wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEWC).
 === Ende Beschreibung === */
void f_108110(void) NEWC(0x223, 0x44)

//@ f_108160
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt die Textmeldung 0x2f000129 über f_0bf730 aus und ruft anschließend
 *   f_125ed0(&d_1c2c44, 2) zur Aktualisierung des Dungeon-/Kartenstatus auf.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 und d_1c2c44.
 * - Besonderheiten: Kombiniert Textausgabe und Statusänderung.
 === Ende Beschreibung === */
void f_108160(void) { f_0bf730(MBOX, 0x2f000129); f_125ed0((int)&d_1c2c44, 2); }

//@ f_108190
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese beiden umfangreichen Methoden steuern das Durchsuchen von Kapitäns- und Frachträumen (d_1c041f,
 *   d_1c0420) in ship3, prüfen auf Fallen oder Schlösser und übergeben gefundene Schätze und Questgegenstände an
 *   die Gruppe.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen haben keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_108190(void)
{
    struct Eq650 { static int eq(const signed char &a,int b){return a==b?1:0;} };
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    int v = f_038c40(d_1c0004);
    *(int *)(o.p[0] + 4) = v;
    unsigned short u;
    if (Eq650::eq(d_1c0390,0)) {
        d_1c0390=1;
        u=f_0bf820(MBOX,0x2f00012a,3,0x2f00012d,0x2f00012c,0x2f00012e);
    } else {
        u=f_0bf820(MBOX,0x2f00012b,3,0x2f00012d,0x2f00012c,0x2f00012e);
    }
    switch(u) {
    case 1:
        f_0bf730(MBOX,0x2f000133);
        break;
    case 2:
        {
            short s=f_0d54f0(d_1c0004,0x23);
            if(s!=-1) {
                s=f_044c90(v,0x30,0xf);
                if(s>0) { f_0bf730(MBOX,0x2f00012f); return; }
                if(EQF(d_1c03a0,0)) {
                    d_1c03a0=1;
                    f_0bf730(MBOX,0x2f000130);
                    f_0424f0(v,1);
                    *(volatile signed char *)&d_1c0364=3; // erzwingt direktes Byte-Immediate-Schreiben wie im Original
                    return;
                }
                f_0bf730(MBOX,0x2f000131);
                s=f_1457e0(100);
                if(s<0x32)f_040900(v,5);
                f_0dd100(d_1c0004,0x23);
                return;
            } else {
                f_0bf730(MBOX,0x2f000132);
                return;
            }
        }
    case 3:
        {
            int q=f_038e10(d_1c0004,0x2f000134);
            if(q) {
                *(short *)&d_1c0428=3;
                f_03d4b0(q,1,0);
                f_0bbf00((int)&d_1bf230);
            }
            return;
        }
    }
}

//@ f_1083c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Steuert eine mehrstufige Interaktion (Zustand d_1c03a4): Beim ersten Mal (0) wird
 *   ein Held mit Talent 0x30 ermittelt (f_039320), Text 0x2f000136 ausgegeben und d_1c03a4 = 1 gesetzt. In
 *   Zustand 1 wählt der Spieler einen Helden (f_038e90) und einen Gegenstand (f_032820, f_042a60), der gegen die
 *   Liste d_1a6834 geprüft wird; bei Gegenstand 0x3c wechselt der Zustand auf 2 (0x2f00013b), bei anderen
 *   gültigen Gegenständen wird dieser verbraucht (f_036300, 0x2f00013a). Im Zustand 2 wird der Behälter 100
 *   (0x64, f_112df0) geöffnet.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c03a4, nutzt d_1c0004, d_1a6834[] und d_1c2c40.
 * - Besonderheiten: Kombiniert Gegenstandseinsatz mit anschließender Behälteröffnung (NEWA(0x2e8, 100)).
 === Ende Beschreibung === */
void f_1083c0(void)
{
    Obj o(d_1c349c, d_1c3870, d_1c3498);
    int found = 0;
    if (EQF(d_1c03a4, 0)) {
        d_1c03a4 = 1;
        int v = f_039320(d_1c0004, 0x30);
        *(int *)(o.p[0] + 4) = v;
        f_0bf730(MBOX, 0x2f000136);
    }
    if (EQF(d_1c03a4, 1)) {
        int i = f_038e90(d_1c0004, 0x2f000137);
        if (i != 0) {
            *(int *)(o.p[0] + 4) = i;
            short u = f_032820(i, 0x2f000138, 1);
            if (u != -1) {
                short s = f_042a60(i, u);
                if (s != -1) {
                    short k;
                    for (k = 0; d_1a6834[k] != -1 && !found; k++) {
                        if (s == d_1a6834[k]) found = 1;
                    }
                    *(int *)(o.p[2] + 4) = (*(int **)&d_1c2c40)[s];
                    *(short *)(o.p[7] + 2) = 1;
                    if (!found) {
                        f_0bf730(MBOX, 0x2f000139);
                    } else {
                        if (s == 0x3c) {
                            d_1c03a4 = 2;
                            f_0bf730(MBOX, 0x2f00013b);
                        } else {
                            f_0bf730(MBOX, 0x2f00013a);
                            f_036300(i, u, 1);
                        }
                    }
                }
            }
        }
    }
    if (EQF(d_1c03a4, 2)) NEWA(0x2e8, 100)
}
//@ f_1085a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese acht Methoden verwalten weitere Kämpfe (0x1f42, 0x1f43), Raumtexte und Truhenuntersuchungen
 *   (d_1c0421 bis d_1c0425) im mittleren Bereich von ship3.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Kampffunktionen geben das Ergebnis von f_05fa00 zurück; die übrigen Funktionen haben
 *   keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_1085a0(void) { f_0bf730(MBOX, 0x2f00013c); }

//@ f_1085c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Instanziiert ein 20-Byte-Truhen-/Behälterobjekt (f_112df0) mit Kennung 0x65
 *   (Quellzeile 0x309), führt f_112ec0 aus und gibt das Objekt über f_112e70 wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Behälter-Wrapper (NEWA).
 === Ende Beschreibung === */
void f_1085c0(void) NEWA(0x309, 0x65)

//@ f_108610
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Zeigt die Raummeldung 0x2f00013d über f_0bf730 im Textkontext d_1c2c64 an.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (MBOX).
 * - Besonderheiten: Kurze Textausgabe-Routine.
 === Ende Beschreibung === */
void f_108610(void) { f_0bf730(MBOX, 0x2f00013d); }

//@ f_108630
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Prüft vor Kampfbeginn, ob das Flag d_1c037c noch 0 ist und f_0dd410(d_1c0004, 1) ==
 *   5 gilt; falls ja, wird Hinweis 0x2f00013e ausgegeben und d_1c037c = 1 gesetzt. Anschließend startet die
 *   Funktion den Kampf 0x31 (0x1f42) über f_05fa00.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest und schreibt d_1c037c, nutzt d_1c0004 und d_1c2c64.
 * - Besonderheiten: Entspricht der Ereignisbehandlung case 0x1f42 aus f_107380.
 === Ende Beschreibung === */
void f_108630(void)
{
    if (EQF(d_1c037c, 0)) {
        if (f_0dd410(d_1c0004, 1) == 5) { f_0bf730(MBOX, 0x2f00013e); d_1c037c = 1; }
    }
    f_05fa00(0x31, 0x1f42);
}

//@ f_108690
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Gibt abhängig vom Statusflag d_1c03a8 einen von drei Beschreibungstexten über
 *   f_0bf730 aus (0x2f00013f bei 3, 0x2f000140 bei 2, sonst 0x2f000141).
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Liest d_1c03a8, nutzt d_1c2c64.
 * - Besonderheiten: Zustandsabhängige Raumbeschreibung passend zur Begegnung in f_1087c0.
 === Ende Beschreibung === */
void f_108690(void)
{
    if (EQF(d_1c03a8, 3)) f_0bf730(MBOX, 0x2f00013f);
    else if (EQF(d_1c03a8, 2)) f_0bf730(MBOX, 0x2f000140);
    else f_0bf730(MBOX, 0x2f000141);
}

//@ f_1086f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x45 (Quellzeile
 *   0x356), führt f_046de0 aus und gibt das Objekt wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEWC).
 === Ende Beschreibung === */
void f_1086f0(void) NEWC(0x356, 0x45)

//@ f_108740
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Erzeugt ein 12-Byte-Schatz-/Beuteobjekt (f_046d10) mit Kennung 0x46 (Quellzeile
 *   0x368), führt f_046de0 aus und gibt das Objekt wieder frei.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1a68a4 für mark.
 * - Besonderheiten: Standard-Fundstellen-Wrapper (NEWC).
 === Ende Beschreibung === */
void f_108740(void) NEWC(0x368, 0x46)

//@ f_108790
/* === Beschreibung (Katalog) ===
 * - Aufgabe/Zweck im Spiel: Setzt den Dialogmodus in d_1c2c64 über f_0bf6c0 auf 5, gibt den Text 0x2f000142 mit
 *   f_0bf730 aus und stellt den Standardmodus über f_0bf680 wieder her.
 * - Eingaben / Rückgabe: Keine Parameter (void). Kein Rückgabewert (void).
 * - Wichtige Variablen & Daten: Nutzt d_1c2c64 (MBOX).
 * - Besonderheiten: Gekapselte Textausgabe mit speziellem Rahmen-/Darstellungsmodus 5.
 === Ende Beschreibung === */
void f_108790(void) { f_0bf6c0(MBOX, 5); f_0bf730(MBOX, 0x2f000142); f_0bf680(MBOX); }
