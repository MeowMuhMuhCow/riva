/* === Beschreibung (Katalog) ===
 * Einheit loc_entr_neu (0x0B5C00 - 0x0B5DC0)
 *
 * Überblick
 * Die Einheit loc_entr_neu enthält die Ereignislogik f_0b5c00 für einen besonderen Ortseingang, bei dem die
 * Heldengruppe einen bestimmten Gegenstand (0x33) besitzen und eine Talentprobe (0x1a) bestehen muss, bevor der
 * zugehörige Ereignisgraph (0x66) ausgeführt wird.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0b5c00-0b5dc0 aus Quelle/cpp/LOC_ENTR.CPP; erster Entwurf, Einbau separat prüfen.
// loc_entr.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 3
// Code 0x0B5C00-0x0B5DC0. Ortseingang: Gegenstand 0x33 prÃ¼fen, Frage stellen, Weg merken, Zufallsprobe.
extern const char d_1a5254[];
#define loc_entr_file d_1a5254
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Ent { short f_044c90(int id, int n); };
struct Game { Ent *f_039320(int id); short f_0d54f0(int id); long f_0de7d0(int k); };
extern Game *d_1c0004;
struct Msg { void f_0bf730(long code); int f_0bf6f0(long code); };
extern Msg d_1c2c64;
extern signed char d_1bedc0, d_1bedbc, d_1bedc4;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
short f_1457e0(int n);                                   // Zufall


struct Graph {                                           // 0x14 Bytes, Konstruktor 0x112DF0, Destruktor 0x112E70
    char b[0x14];
    Graph(int a, int b_, int c);
    ~Graph();
    int  f_1131b0();
    void f_112ec0();
};
//@ f_0b5c00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft beim Betreten eines Ortes in zwei Stufen den Fortschritt (d_1bedbc und d_1bedc0):
 *   Zuerst wird getestet, ob ein Gruppenmitglied den Gegenstand 0x33 trägt (f_039320) und eine Probe darauf
 *   (f_044c90(0x33, 10)) schafft (Meldung 0x22010013, d_1bedbc = 1); danach wird der Spieler per
 *   Entscheidungsfrage 0x22010014 gefragt und eine Gruppenprobe auf Talent 0x1a (f_0d54f0) abgelegt (Erfolgstext
 *   0x22010015, d_1bedc0 = 1, sonst Misserfolgstext 0x22010016). Ist der Zugang freigeschaltet (d_1bedc0 == 1),
 *   startet die Funktion den Dialog-/Ereignisgraphen 0x66 (Graph(0x66, 0, 0)) oder gibt - sobald der Graph
 *   beendet bzw. mit 25 % Wahrscheinlichkeit (f_1457e0(100) <= 25) das Flag d_1bedc4 = 1 gesetzt wurde - den
 *   Abschlusstext 0x22010017 aus.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 1.
 * - Wichtige Variablen:
 *   - d_1bedbc, d_1bedc0, d_1bedc4: Persistente Fortschrittsflags für die Entdeckung, Öffnung und Erschöpfung
 *     des Ortseingangs.
 *   - c: Lokaler RivaTextContext, in dessen Platzhaltern p[1] und p[2] die beteiligten Helden für die
 *     Textausgabe eingetragen werden.
 *   - g: Instanz des Ereignisgraphen 0x66.
 === Ende Beschreibung === */
int f_0b5c00()
{
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    if ((d_1bedc0 == 0) != 0) {
        if ((d_1bedbc == 0) != 0) {
            Ent *e = d_1c0004->f_039320(0x33);
            if (e->f_044c90(0x33, 10) > 0) {
                c.tables.p[1] = (long)e;
                d_1c2c64.f_0bf730(0x22010013);
                d_1bedbc = 1;
            }
        }
        if ((d_1bedbc == 1) != 0) {
            if (d_1c2c64.f_0bf6f0(0x22010014) == 1) {
                short k = d_1c0004->f_0d54f0(0x1a);
                if (k != -1) {
                    c.tables.p[2] = d_1c0004->f_0de7d0(k);
                    d_1c2c64.f_0bf730(0x22010015);
                    d_1bedc0 = 1;
                } else d_1c2c64.f_0bf730(0x22010016);
            }
        }
    }
    if ((d_1bedc0 == 1) != 0) {
        if ((d_1bedc4 == 1) != 0) d_1c2c64.f_0bf730(0x22010017);
        else {
            Graph *g = new (mark(loc_entr_file, 1248)) Graph(0x66, 0, 0);
            g->f_112ec0();
            if (!g->f_1131b0() || f_1457e0(100) <= 25) d_1bedc4 = 1;
            delete g;
        }
    }
    return 1;
}
