/* === Beschreibung (Katalog) ===
 * Einheit: alchemy
 *
 * Adressbereich: 0x012dd0-0x0132a0
 * Spielsystem: Talente & Inventar (Alchimie) - Auswahl und Vorbereitung eines alchimistischen Rezepts zum
 * Tränkebrauen (Schwesterfunktion plan_alchemy in Sternenschweif OVL090.CPP und Schicksalsklinge seg104.c).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAITEX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "R_FIX.H"
// P3 0/1 gleich (suche.py 24.10.2026, Basis alchemy_P1.CPP)
// P1 0/1 GLEICH, Rest: f_012dd0 Struktur 14 (n=0 wird vor den Aufruf gezogen; Ctx-/n-Stapelplaetze) [F1 23.10.]
// alchemy.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x012DD0-0x0132A0
#include <string.h>
struct Msg { void f_0bf730(long code); void f_0bf6c0(int k); int f_0bf820(long code, ...); void f_0bf680(); };
extern Msg d_1c2c64;


struct Ent { short a; char p1[20]; short b; short c; char p2; unsigned char d; };   // 28 Byte
extern Ent d_1a68f4[];
struct Clk { char pad[0x58]; int (**vt)(Clk *); };
extern Clk *d_1bf1ac;

extern char d_1c21b4[][50];
extern int d_1c29c4[];
extern char d_1c349c[], d_1c3870[], d_1c3498[];
int f_0d4aa0(int obj, int k);
short f_03d860(int obj, int a, int b);
void f_0a7840(RivaItemDefinition *item,char *dst,short n);
int f_133fe0(char *a, char *b);



extern const char d_1a0150[];
int f_0133b0(int p1, int p2, int p3);
int f_0132a0(int p1, int p2);
int f_043370(int p1, int p2);
void f_125e50(char *p, int v);
extern char d_1c2c44[];

//@ f_012dd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt die Anwendung des Talents Alchimie für einen Helden aus (plan_alchemy). Prüft
 *   zunächst, ob der Held ein Alchimieset (Gegenstand 0x2f) besitzt, stellt alle unter den 17 Rezepten
 *   (d_1a68f4) zur Auswahl, die der Held entweder als Einzelrezept im Gepäck trägt oder im Rezeptbuch
 *   (Gegenstand 0xbf) eingetragen hat, prüft für das gewählte Rezept die Zutaten (f_0132a0), die benötigte
 *   Astralenergie (f_0429a0) sowie bei einer Braudauer über 8 Stunden die verfügbare Zeit samt
 *   Sicherheitsrückfrage, rückt schließlich die Spielzeit um die Braudauer vor (f_125e50), setzt den Tagestimer
 *   am Helden (+0xa1 = 0x1fa40) und startet den eigentlichen Brauvorgang (f_0133b0).
 * - Eingaben / Rückgabe: Eingabe ist der Zeiger auf den brauenden Helden (p1); gibt 0 bei Abbruch oder fehlenden
 *   Voraussetzungen zurück, sonst das Brauergebnis aus f_0133b0 (1 = Trank gelungen, 0 = misslungen).
 * - Wichtige Variablen & Daten:
 *   - d_1a68f4[17]: Rezepttabelle mit 17 Einträgen zu je 28 Bytes (+0x00 Rezeptgegenstand-ID, +0x02 bis zu 10
 *     Zutaten-IDs mit -1 als Ende, +0x16 Ergebnisgegenstand-ID, +0x18 AE-Kosten, +0x1a Probenzuschlag, +0x1b
 *     Dauer in Stunden).
 *   - work.tab: Dynamisches 17-Byte-Zuordnungsfeld von Menüzeilenindex auf Rezeptindex 0..16 (behebt den
 *     Pufferüberlauf sel[13] bei 14 Rezepten aus Sternenschweif).
 *   - d_1c21b4, d_1c29c4, d_1c2c64: Textpuffer, Menüzeilenzeiger und globales Dialogobjekt für Meldungen
 *     (0x7000001 kein Set, 0x7000002 keine Rezepte, 0x7000003 Auswahl, 0x7000004 zu lang, 0x7000005 Rückfrage,
 *     0x20000163 zu wenig AE).
 *   - d_1bf1ac: Uhr-/Zeitgeberobjekt, dessen virtuelle Methode vt[4] die verbleibende Zeit liefert.
 * - Besonderheiten / Originalfehler:
 *   1. Nach dem Rezeptauswahldialog (sel = d_1c2c64.f_0bf820(...)) wird if (sel >= 0) statt if (sel > 0) geprüft
 *     und anschließend work.tab[sel - 1] gelesen; bei Rückgabe 0 würde 1 Byte vor dem Puffer (work.tab[-1])
 *     gelesen.
 *   2. Bei Rezepten mit mehr als 8 Stunden Dauer teilt die Zeitprüfung die Braudauer durch 24 (d_1a68f4[k].d /
 *     24, also *Tage*), vergleicht sie aber mit t / 5400 + 1 (wobei 5400 Ticks einer *Stunde* entsprechen).
 *     Durch diesen Einheitenfehler (Tage gegen Stunden) schlägt die Zeitbegrenzung praktisch nie an.
 === Ende Beschreibung === */
int f_012dd0(int p1)
{
    typedef RivaTextContextData RawCtx;
    RawCtx contexts[4]; short s, n;
    struct Scalars902 { char *tab; int res; int hero; char *q; int dd; } work;
    work.hero=p1;
    if ((unsigned)work.hero >= 0u) work.hero=p1; // Haelt den Parameterstore vor mark wie im Original
    p1=0;
    void f_125400(void *, void *, void *, void *);
    void f_1254a0(void *, int);
    work.tab = (char *)new (mark(d_1a0150, 199)) char[0x11];
    work.res = 0;
    int ok = 1;
    if ((short)f_0d4aa0(work.hero, 0x2f) == -1) { d_1c2c64.f_0bf730(0x7000001); ok = 0; }
    if (ok == 1) {
        int pl = work.hero;
        work.q = work.tab;

        
        s = f_0d4aa0(pl, 0xbf);
        n = 0;
        for (short i=0; i < 17; i++) {
            short r = f_0d4aa0(pl, d_1a68f4[i].a);
            if (r == -1) {
                if ((short)s == -1) continue;
                if (!f_03d860(pl, (short)s, i)) continue;
            }
            short k = n;
            int b = d_1a68f4[i].b;
            f_0a7840(d_1c2c40[b], d_1c21b4[k], 1);
            int u = f_133fe0(d_1c3498, d_1c21b4[k]);
            u=(u&0)?0:u; d_1c29c4[k] = u; // Haelt die Registerwahl (edx fuer b bei [eax+edx*4]) wie im Original
            work.q[k] = (char)i; n = n + 1;
        }
        if ((short)n == 0) {
            f_125400(&contexts[0], d_1c349c, d_1c3870, d_1c3498);
            contexts[0].tables.p[1] = pl;
            d_1c2c64.f_0bf730(0x7000002); f_1254a0(&contexts[0], 0);
        }
        if ((short)n > 0) {
            d_1c2c64.f_0bf6c0(7);
            short sel = d_1c2c64.f_0bf820(0x7000003, (short)n,
                d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
                d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15],
                d_1c29c4[16], d_1c29c4[17], d_1c29c4[18], d_1c29c4[19]);
            d_1c2c64.f_0bf680();
#if FIX_R025   /* R025: Unterlauf work.tab[-1] bei sel <= 0 verhindern */
            if (sel > 0) {
#else
            if (sel >= 0) {
#endif
                short k = (signed char)work.tab[sel - 1];
                if (f_0132a0(work.hero, (signed char)work.tab[sel - 1]) == 0) {
                    int ok2 = 1;
                    if (d_1a68f4[k].c > f_0429a0((struct hero *)(work.hero))) {
                        f_125400(&contexts[1], d_1c349c, d_1c3870, d_1c3498);
                        contexts[1].tables.p[1] = work.hero;
                        d_1c2c64.f_0bf730(0x20000163); f_1254a0(&contexts[1], 0);
                        ok2 = 0;
                    }
                    if (ok2 == 1) {
                        
                        if (d_1a68f4[k].d > 8) {
                            int t = (*d_1bf1ac->vt[4])(d_1bf1ac);
                            int q2 = t / 5400 + ok2;
#if FIX_R025   /* R025: Braudauer in Stunden direkt mit verbleibenden Stunden q2 vergleichen (statt / 24) */
                            if (d_1a68f4[k].d > q2) {
#else
                            if (d_1a68f4[k].d / 24 > q2) {
#endif
                                f_125400(&contexts[2], d_1c349c, d_1c3870, d_1c3498);
                                int duration = d_1a68f4[k].d;
                                short *rec = contexts[2].tables.tail.short_numbers;
                                rec[1] = duration;
                                d_1c2c64.f_0bf730(0x7000004); f_1254a0(&contexts[2], 0);
                                ok2 = 0;
                            }
                        }
                        if (ok2 == 1) {
                            int ok3; d_1a68f4[k].d=d_1a68f4[k].d; work.dd=d_1a68f4[k].d; ok3=1;
                            if (work.dd > 8) {
                                f_125400(&contexts[3], d_1c349c, d_1c3870, d_1c3498);
                                d_1c2c64.f_0bf6c0(7);
                                contexts[3].tables.tail.short_numbers[1] = work.dd;
                                short r3 = d_1c2c64.f_0bf820(0x7000005, 2, 0x7000006, 0x7000007);
                                if (r3 != ok3) ok3 = 0;
                                d_1c2c64.f_0bf680(); f_1254a0(&contexts[3], 0);
                            }
                            if (ok3 == 1) {
                                f_125e50(d_1c2c44, d_1a68f4[k].d * 5400);
                                f_043370(work.hero, 0x1fa40);
                                work.res = f_0133b0(work.hero, k, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    delete work.tab;
    return work.res;
}
