/* === Beschreibung (Katalog) ===
 * Einheit boron1 (0x022030 - 0x0222D0)
 *
 * Überblick
 * Die Einheit boron1 enthält die Schritt- und Ereignissteuerung für die Begegnung in den Katakomben bzw. auf dem
 * Boron-Acker (Boron::f_022030). Sie steuert die Dialoge, Grafikfenster, Sprach-/Soundausgaben und
 * Zustandsübergänge über die zugehörigen Orts-Merkflags.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 0/1 gleich (suche.py 24.10.2026, Basis boron1_P1.CPP)
// I9: aus boron1_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// boron1.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x22030-0x222D0. Boron-Schritt: Frage-/Warte-Zustaende ueber Merkflags, Dialog-Objekt, Meldungen.
extern const char boron1_file[];   // Inhalt in der Basis (Fable 30.10.: nicht hier definieren)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Msg { void f_0bf730(long code); };
extern Msg d_1c2c64;
struct Msg2 { void f_057220(long code); };
extern Msg2 d_1c2c00;
struct Snd { void f_147323(long a, int b, int c, int d, int e, int f); };
void f_147323(Snd *s, long a, int b, int c, int d, int e, int f);
#pragma aux f_147323 modify [esp];
extern Snd d_1c2edc;
struct Game { int f_039660(int n); };
extern Game *d_1c0004;
extern int d_1a9820;
extern signed char d_1bc790, d_1bc794, d_1bc78c, d_1bc798, d_1bc76c, d_1bc788;
extern char d_1bfaec;
extern short d_1bd922;
extern char d_1c349c[], d_1c3870[], d_1c3498[];


struct Graph {                                           // 0x14 Bytes, Konstruktor 0x112DF0, Destruktor 0x112E70
    char b[0x14];
    Graph(int a, int b_, int c);
    ~Graph();
    int  f_1131b0();
    void f_112ec0();
};
void f_0dcbb0(Game *g, int a, int b);
void f_091f70(int a);
void f_060740(int a, int b);
void *f_069730(void *p, int n);
void f_069630(void *p, int n);
struct Boron;
struct VT { short (*fn)(Boron *self, int a, int b); };
struct Boron {
    char p0[8];
    VT *vt;
    void f_0600f0(long code);
    void f_022030();
};

//@ f_022030
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den zustandsabhängigen Handlungsschritt im Boron-Abschnitt aus: Zeigt je nach
 *   Fortschrittsflags (d_1bc790, d_1bc78c, d_1bc798, d_1bc76c) Textmeldungen über d_1c2c64 an, öffnet das
 *   Grafik-/Animationsfenster 0x1f (Graph(0x1f, 0, 0)), spielt die Sprach-/Klangausgabe 0x240003 sowie den
 *   Soundeffekt 0x1f42 ab, schaltet das Dungeon-Objekt 0x1d um und löst nach Abschluss der Interaktion den
 *   Ortswechsel (f_0dcbb0(..., 0x14, 0)) sowie die Folgeereignisse (f_091f70(0xe), d_1c2c00.f_057220(0x8030004))
 *   aus.
 * - Eingaben:
 *   - this (Impliziter Zeiger auf das Boron-Orts-/Dungeon-Steuerobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bc790, d_1bc794, d_1bc78c, d_1bc798, d_1bc76c, d_1bc788 (Orts- und Dialog-Merkflags für den Ablauf der
 *     Boron-Szene).
 *   - d_1bfaec (Zustandsflag zur Auswahl zwischen den Textmeldungen 0x24000028 und 0x24000029 sowie zur
 *     Berechnung von d_1bd922).
 *   - g (Dynamisch erzeugtes Grafik-/Animationsfenster Graph(0x1f, 0, 0)).
 *   - c (RivaTextContext mit dem Helden an Gruppenposition 6 als Textsubjekt).
 === Ende Beschreibung === */
void Boron::f_022030()
{
    if ((d_1bc790 == 1) != 0) {
        if ((d_1bc794 == 0) != 0) {
            d_1bc794 = 1;
            d_1c2c64.f_0bf730(0x24000027L);
        }
        Graph *g = new (mark(boron1_file, 0x40b)) Graph(0x1f, 0, 0);
        if (g->f_1131b0() != 0) g->f_112ec0();
        delete g;
    }
    if (((d_1bc790 == 0) != 0) && ((d_1bc78c == 1) != 0)) {
        if ((d_1bc798 == 0) != 0) {
            RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
            c.tables.p[1] = d_1c0004->f_039660(6);
            signed char b1 = d_1bfaec;
            if (b1 == 0) d_1c2c64.f_0bf730(0x24000028L); else d_1c2c64.f_0bf730(0x24000029L);
            int snd_arg = d_1a9820;
            f_147323(&d_1c2edc, 0x240003L, 0x7fff, 0x8000, snd_arg, 0, 1);
            f_060740(0x1f42, 1);
            d_1bc798 = 1;
            f_069630(f_069730((char *)this + 2, 0x1d), 3);
        }
        if (((d_1bc798 == 1) != 0) && ((d_1bc790 == 0) != 0)) {
            signed char b2 = d_1bfaec;
            d_1bd922 = (b2 != 0) + 2;
            if (vt->fn(this, 0x1d, 0) == 0) {
                Game *game = d_1c0004;
                f_0dcbb0(game, 0x14, (*(volatile signed char *)&d_1bc790 = 1, 0));
                f_091f70(0xe);
                d_1c2c00.f_057220(0x8030004L);
            }
        }
    }
    if (((d_1bc76c == 1) != 0) && ((d_1bc790 == 0) != 0) && ((d_1bc78c == 0) != 0)) {
        f_0600f0(0x150009L);
        d_1bc788 = 1;
    } else if ((d_1bc76c == 0) != 0)
        d_1c2c64.f_0bf730(0x2400002aL);
}
