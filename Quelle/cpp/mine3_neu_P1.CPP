/* === Beschreibung (Katalog) ===
 * Einheit mine3_neu (0x0CCF00 - 0x0CD000)
 *
 * Überblick
 * Die Einheit mine3_neu enthält eine Ereignisfunktion für die dritte Ebene der Zwergenmine, die anhand einer
 * festen Prioritätsliste einen Helden und dessen geführte Waffe bestimmt und eine erschwerte
 * Eigenschafts-/Talentprobe mit möglichem Verletzungsschaden ausführt.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0ccf00-0cd000 aus Quelle/cpp/MINE3.CPP; erster Entwurf, Einbau separat prüfen.
// mine3.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x0CCF00-0x0CD000. Mine, Ebene 3: erste vorhandene Figur aus einer Liste suchen, Ereignis vorbereiten.
struct Ent : hero {
    
    short f_044900(int a, int b);
    void  f_044300(int k);
};
struct Game { Ent *f_039230(int id); Ent *f_038be0(); };
extern Game *d_1c0004;
struct Msg { void f_0bf730(long code); };
extern Msg d_1c2c64;

extern char d_1c349c[], d_1c3870[], d_1c3498[];
struct Ids { short v[6]; };
extern const Ids d_1a577a;                               // {1,4,6,3,5,2}, liegt bei mine2



//@ f_0ccf00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht anhand der sechsteiligen Positionsliste d_1a577a ({1, 4, 6, 3, 5, 2}) den ersten
 *   besetzten Heldenplatz (f_039230), liest dessen ausgerüsteten Gegenstand in Slot 3 (Waffenhand, f_042a60(e,
 *   3)) aus - oder weicht auf den Gruppenanführer (f_038be0) aus -, gibt mit diesem Helden und seiner Waffe den
 *   Ereignistext 0x35000194 aus und legt eine um -8 erschwerte Probe Nr. 13 (f_044900(13, -8)) ab; misslingt die
 *   Probe (Rückgabewert > 0), erscheint der Misserfolgstext 0x35000195 und der Held erleidet 2 Schadenspunkte
 *   (f_044300(2)).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - ids: Lokale Kopie der Prioritätsliste d_1a577a ({1, 4, 6, 3, 5, 2}).
 *   - e: Ausgewählter Held (Ent *).
 *   - sel: Gegenstands-ID in Ausrüstungsslot 3 des ausgewählten Helden.
 *   - c: Lokaler RivaTextContext für den Heldennamen (p[1]) und den Waffennamen (items[1]).
 === Ende Beschreibung === */
void f_0ccf00()
{
    short sel = 0;
    Ent *e = 0;
    Ids ids = d_1a577a;
    short i;
    for (i = 0; i < sizeof ids.v / sizeof ids.v[0]; i++) {
        e = d_1c0004->f_039230(ids.v[i]);
        if (e) {
            sel = ::f_042a60((hero *)(e), 3);
            break;
        }
    }
    if (!e) {
        e = d_1c0004->f_038be0();
        sel = 0;
    }
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    c.tables.p[1] = (long)e;
    ((int *)c.tables.tail.items)[1] = (*(long **)&d_1c2c40)[(short)sel];
    c.tables.tail.item_counts[1] = 1;
    d_1c2c64.f_0bf730(0x35000194);
    if (e->f_044900(13, -8) > 0) {
        d_1c2c64.f_0bf730(0x35000195);
        e->f_044300(2);
    }
}
