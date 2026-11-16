/* === Beschreibung (Katalog) ===
 * Einheit spell5 (0x112340 - 0x112590)
 *
 * Überblick
 * Die Einheit spell5 implementiert den Meditations-/Astralenergie-Umwandlungszauber (0x4a, *Unitatio* / Astral-
 * oder Ausdauer-Meditation außerhalb des Kampfes, f_112340), bei dem der Spieler einen Zahlenwert wählt und der
 * Zaubernde über eine längere Zeitspanne Punkte regeneriert bzw. umwandelt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/1 gleich (suche.py 25.10.2026, Basis spell5_P1.CPP)
// I9: aus spell5_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// spell5.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x112340-0x112590. Zauber: Kosten/Wirkung eines Zaubers pruefen.
// REST: 7 Befehle abweichend (cwde statt Neuladen von w, lea edx vor mov edi,eax, xor edx vor/nach Speichern von 0xfffe im -2-Pfad)
struct Ent : hero {  short f_03d3d0(int a, int b); };
struct Game { short f_0de7f0(); short f_0de820(); void f_0dc3c0(int a, int b, int c, int d); };
extern Game *d_1c0004;
struct Msg { short f_0bf7b0(int a, long code, int b, int c, int d); };
extern Msg d_1c2c64;
struct Q { void f_0e93f0(char *p, long code); };
extern Q d_1c38b0;
extern char d_1c21b4;
short f_149360(int a,short*);
int f_0de7f0(Game *g);
extern char d_1c349c[], d_1c3870[], d_1c3498[];
struct Ids4 { short v[4]; };
extern const Ids4 d_1a7a4e;



struct Rq { short a; short b; char c; char pad[13]; Ent *e; };
//@ f_112340
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den Zauberspruch 0x4a für den Zaubernden p->e aus: Prüft zunächst anhand der Liste
 *   d_1a7a4e, ob das aktuelle Gebiet (d_1c0004->f_0de820()) für diesen Zauber gesperrt ist (Meldung 0x17000115),
 *   und ob die aktuelle Astralenergie (f_0429a0) mindestens den Mindestwert (w * 7) / 2 (abhängig vom
 *   Gruppenfaktor w = f_0de7f0()) erreicht (sonst Meldung 0x17000083). Ist beides erfüllt, berechnet die
 *   Funktion das Maximum pct, fragt den Spieler über den Zahleneingabedialog d_1c2c64.f_0bf7b0(..., 0x170000c5,
 *   ...) nach der gewünschten Menge q und würfelt die Zauberprobe p->e->f_03d3d0(0x4a, p->c): Bei Erfolg
 *   vergehen q * 90 Zeiteinheiten (f_0dc3c0), p->a erhält die vollen Kosten w * ((q / 5) * 7) / 2 und der
 *   Erfolgtext 0x170000c6 wird formatiert; bei Misslingen wird p->a = -2 und p->b auf die halben Kosten gesetzt.
 * - Eingaben:
 *   - p (Zeiger auf die Zauber-Anforderungsstruktur Rq mit dem zaubernden Helden p->e, der Probenerschwernis
 *     p->c und den Ausgabefeldern p->a, p->b).
 * - Rückgabewert: Keiner (void, schreibt Ergebnis und Astralenergiekosten nach p->a und p->b).
 * - Wichtige Variablen:
 *   - w (Skalierungsfaktor aus d_1c0004->f_0de7f0()).
 *   - pct (Maximal auswählbarer Punktwert 1..pct für den Zahlendialog).
 *   - q (Vom Spieler gewählter Punktwert, mindestens 5).
 *   - ids (Liste der vier gesperrten Gebietskennungen d_1a7a4e).
 === Ende Beschreibung === */
void f_112340(Rq *p)
{
  {
    short q;
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    Ids4 ids = d_1a7a4e;
    short w = d_1c0004->f_0de7f0();
    q = (w * 7) / 2;
    short k = f_149360(d_1c0004->f_0de820(),ids.v);
    short sel = 1;
    if (k != -1) {
        c.tables.p[1] = (long)p->e;
        d_1c38b0.f_0e93f0(&d_1c21b4, 0x17000115);
    } else if (::f_0429a0((hero *)(p->e)) < q) {
        c.tables.p[1] = (long)p->e;
        d_1c38b0.f_0e93f0(&d_1c21b4, 0x17000083);
    } else {
        short pct = (::f_0429a0((hero *)(p->e)) * 10) / (w * 7);
        if (pct >= 100) sel = 3;
        else if (pct >= 10) sel = 2;
        c.tables.tail.short_numbers[1] = pct;
        q = d_1c2c64.f_0bf7b0(sel, 0x170000c5, 0, pct, 0);
        d_1c21b4 = 0;
        if (q > 0) {
            if (p->e->f_03d3d0(0x4a, (signed char)p->c) > 0) {
                if (q < 5) q = 5;
d_1c0004->f_0dc3c0(q * 90, 0, 1, 0x10);
                p->a = (short)w * ((q / 5) * 7) / 2;
                c.tables.tail.short_numbers[1] = q;
                d_1c38b0.f_0e93f0(&d_1c21b4, 0x170000c6);
                return;
            }
            if (q < 5) q = 5;
            p->a = -2;
            ((volatile Rq *)p)->b = w * ((q / 5) * 7) / 4;
            return;
        }
    }
    ((volatile Rq *)p)->a = -4;
  }
}
