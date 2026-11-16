/* === Beschreibung (Katalog) ===
 * Einheit fi_opt2 (0x083680 - 0x0839D0)
 *
 * Überblick
 * Die Einheit fi_opt2 stellt die Daten für das Kampf-Schnellinformationsfenster (Quickinfo) eines Helden
 * zusammen (Fi::f_083680) und bringt dieses zur Anzeige.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// I9: aus fi_opt2_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// fi_opt2.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x083680-0x0839D0. Fuellt das Kampf-Quickinfo (zwei Zahlenfelder und Anzeigeobjekte) fuer eine Figur.
#include <stdio.h>
void *operator new(unsigned size, void *tag);            // 0x014AB0
struct Msg { void f_0bf730(long code); }; extern Msg d_1c2c64;
struct Ta { int pad; int f4; };
struct Tb { int pad; int f4, f8, fc, f10, f14; };
struct Tc { short pad; short s2, s4, s6, s8, sa, sc; };
struct Td { short pad; short s2; };
struct Big { Big(char *a, char *b, char *c); ~Big(); char p0[4]; Ta *p4; char p8[4]; Ta *pc; Tb *p10; Tc *p14; char p18[8]; Td *p20; char p24[0x18]; };
struct Thing { char x; };
struct Unit : hero {
    short f_035110(); short f_0350b0(); short f_0456e0(int a);
    short f_045610(); short f_045660();  
       
    int f_040e90();   short f_0d4b00(); 
    
};
short f_045710(Unit *u, int a);
extern char d_1c349c[], d_1c3870[], d_1c3498[], d_1c27a8[], d_1c27da[];
extern signed char d_1a441c[];


void f_145920(short a, short b, short c, short *lo, short *hi);
unsigned char f_09a040(int color);
int f_133fe0(char *a, char *b);

struct Fmt11 { char c[11]; };
extern Fmt11 d_1a2188;   // "%c%-d%c/%d" - Initialisierungsbild liegt im Original, nicht hier anlegen
struct Fi {
    void f_083680(Unit *u);
};

//@ f_083680
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Berechnet für die Kampfeinheit bzw. den Helden u die aktuellen Kampfwerte (Attacke x, Parade
 *   y sowie die minimale und maximale Trefferpunkt-Spanne lo..hi für waffenlosen Kampf, Fernkampfwaffe oder
 *   Nahkampfwaffe inklusive Körperkraft-Zuschlag), formatiert die aktuelle und maximale Lebensenergie
 *   (f_042960/f_042970) sowie Astralenergie (f_0429a0/f_0429b0) farbig hervorgehoben in die Textpuffer d_1c27a8
 *   und d_1c27da, trägt sämtliche Werte (Name, Stufe, Rüstungsschutz, Waffe, LE/AE-Strings und Statusmeldungen)
 *   in den Textkontext Big ein und öffnet das Kampf-Quickinfo-Fenster über d_1c2c64.f_0bf730(0x1010001).
 * - Eingaben:
 *   - this (Impliziter Zeiger auf das Kampfsteuerungs-Objekt Fi).
 *   - u (Zeiger auf die anzuzeigende Helden-/Kampfeinheit Unit).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - x, y (Effektiver Attacke- und Paradewert des Helden, nach unten auf 0 begrenzt).
 *   - lo, hi (Minimale und maximale Schadenspunkte der geführten Waffe bzw. 1..6 im waffenlosen Kampf).
 *   - p (Zeiger auf den 10-Byte-Waffentabelleneintrag in d_1a441c für die ausgerüstete Waffe in Slot 3).
 *   - d_1c27a8, d_1c27da (Formatierte Zeichenketten "aktuell/maximal" für Lebens- und Astralenergie).
 *   - b (Textkontext-Struktur Big zur Übergabe der Felder an das Dialogsystem).
 === Ende Beschreibung === */
void Fi::f_083680(Unit *u)
{
    short hi, lo;
    Fmt11 fmt = d_1a2188;
    Big b(d_1c349c, d_1c3870, d_1c3498);
    signed char *p;
    short y, x;
    short a, v;

    if (u->f_035110() == -1) {
        if (u->f_0350b0() == -1) {
            x = u->f_0456e0(0);
            y = f_045710(u, 0);
            lo = 1;
            hi = 6;
        } else {
            x = u->f_045610();
            y = u->f_045660();
            p = d_1a441c + ((signed char)(((RivaItemDefinition*)((*(Thing ***)&d_1c2c40)[::f_042a60((hero *)(u), 3)]))->f_0a78a0())) * 10;
            f_145920(p[0], 6, p[1], &lo, &hi);
        }
    } else {
        x = u->f_045610();
        y = u->f_045660();
        p = d_1a441c + ((signed char)(((RivaItemDefinition*)((*(Thing ***)&d_1c2c40)[::f_042a60((hero *)(u), 3)]))->f_0a78a0())) * 10;
        f_145920(p[0], 6, p[1], &lo, &hi);
        short delta = ::f_042a40((hero *)(u), 6) - p[2];
        if (delta > 0) {
            lo += delta;
            hi += delta;
        }
    }

    if (x < 0) x = 0;
    if (y < 0) y = 0;

    a = ::f_042960((hero *)(u));
    v = ::f_042970((hero *)(u));
    sprintf(d_1c27a8, fmt.c, ((short)a != (short)v ? f_09a040(0xfd) : f_09a040(0xff)),
            (int)(short)a, f_09a040(0xff), (int)(short)v);

    a = ::f_0429a0((hero *)(u));
    v = ::f_0429b0((hero *)(u));
    sprintf(d_1c27da, fmt.c, ((short)a != (short)v ? f_09a040(0xfd) : f_09a040(0xff)),
            (int)(short)a, f_09a040(0xff), (int)(short)v);

    b.p4->f4 = (int)u;
    b.p10->f4 = u->f_040e90();
    b.p14->s2 = ::f_0428d0((hero *)(u));
    b.p14->s4 = x;
    b.p14->s6 = y;
    b.p14->s8 = ::f_0423f0((hero *)(u));
    b.pc->f4 = (int)(*(Thing ***)&d_1c2c40)[::f_042a60((hero *)(u), 3)];
    b.p20->s2 = 1;
    b.p14->sa = lo;
    b.p14->sc = hi;
    b.p10->f8 = f_133fe0(d_1c3498, d_1c27a8);
    b.p10->fc = f_133fe0(d_1c3498, d_1c27da);
    b.p10->f10 = u->f_0d4b00() ? 0x1010025 : 0x20000194;
    b.p10->f14 = ((signed char)::f_0425a0((hero *)(u))) == 1 ? 0x101003d : 0x20000194;
    d_1c2c64.f_0bf730(0x1010001);
}
