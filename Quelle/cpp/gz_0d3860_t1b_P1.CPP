/* === Beschreibung (Katalog) ===
 * Einheit gz_0d3860_t1b (0x0D39E0 - 0x0D3A30)
 *
 * Überblick
 * Die Einheit gz_0d3860_t1b enthält zwei elementare Hilfsfunktionen für 8-Byte-Rechteckstrukturen (Rect): den
 * Kopieroperator (f_0d39e0) und die Nullinitialisierung (f_0d3a10).
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra650: Original 0d3860 bis 0d3a30 exklusiv.
// I9: aus gz_0d3860_REST.CPP uebernommen (Stufe-2-Stand), Marken 5 neu
// gz_0d3860.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xD3860-0xD39DA (Einheit A). Maus-Zustand, Punkt/Rechteck-Kopien.
struct S8 { int a, b; };
struct Pt { unsigned short a, b, c, d; Pt(unsigned short, unsigned short, unsigned short, unsigned short); Pt &operator=(const Pt &); };
struct Rect { unsigned short a, b, c, d; Rect(const Rect &); Rect &operator=(const Rect &); };
extern int d_1bf508;
extern short d_1bd756, d_1bd758, d_1bd75c, d_1bd75e, d_1bd760, d_1bd762, d_1bd766;
extern Pt d_1bf528;
extern signed char d_1bf4ef; extern short d_1bf4a2, d_1bf49e, d_1bf500; extern int d_1bf4a8, d_1bf54c, d_1bf548;
void f_0d2b70();
void f_0d39d0(S8 *, const S8 *);
#pragma aux f_0d39d0 "f_0d39d0"
Rect *f_0d39e0(Rect *, const Rect *);
#pragma aux f_0d39e0 "f_0d39e0"
#pragma aux f_0d38d0 "f_0d38d0"
//@ f_0d39e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert die vier 16-Bit-Koordinatenfelder (a, b, c, d) eines Rechtecks q in das Zielrechteck
 *   p und gibt p zurück.
 * - Eingaben:
 *   - p (Zielzeiger auf Rect).
 *   - q (Quellzeiger auf Rect).
 * - Rückgabewert: Rect * - Der Zielzeiger p.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
Rect *f_0d39e0(Rect *p, const Rect *q)
{
    p->a = q->a;
    p->b = q->b;
    p->c = q->c;
    p->d = q->d;
    return p;
}
//@ f_0d3a10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert alle vier 16-Bit-Koordinatenfelder (a, b, c, d) des Rechtecks p mit 0.
 * - Eingaben:
 *   - p (Zeiger auf die zu leerende Rect-Struktur).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0d3a10(Rect *p)
{
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
}
