/* === Beschreibung (Katalog) ===
 * Einheit gz_012a00 (0x012a00 - 0x012dd0)
 *
 * Überblick
 * Diese Einheit enthält die Prüf-, Auswahl- und Dialogfunktionen für das Kräuter- und Trankbrauen
 * (Alchemie-Rezepte über die 17-elementige Rezepttabelle d_1a68f4). Sie prüft das Vorhandensein des
 * Alchemiekastens (0x2f) und des Rezeptbuchs (0xbf) bzw. einzelner Rezepte im Heldeninventar, baut das
 * Auswahlmenü der bekannten Rezepte auf und kontrolliert Talentwert, Braudauer und Sicherheitsabfrage.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAITEX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 5/6 gleich (suche.py 25.10.2026, Basis gz_012a00_P1.CPP)
// I9: aus G012A00_REST.CPP uebernommen (Stufe-2-Stand), Marken 6 neu
// STAND 22.10.2026 Helfer D: nicht GLEICH. Rest 12 Bef.: f_012a30 Stapelplatz s/n vertauscht (s=[esp+40], n=[esp+44] im Original), f_012b40 push movsx eax statt edx
// gz_012a00.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x012A00-0x012DD0. Pruefungen/Meldungen zu Tabelle d_1a68f4 (Eintraege je 28 Byte): Auswahl, Mindestwert, Zeitablauf.
struct Msg { void f_0bf730(long code); void f_0bf6c0(int k); int f_0bf820(long code, ...); void f_0bf680(); };
extern Msg d_1c2c64;


struct Ent { short a; char p1[20]; short b; short c; char p2; unsigned char d; };   // 28 Byte
extern Ent d_1a68f4[];
struct Clk { char pad[0x58]; int (**vt)(Clk *); };
extern Clk *d_1bf1ac;

extern char d_1c21b4[][50];
extern int d_1c29c4[];
extern char d_1c349c[], d_1c3870[], d_1c3498[];
short f_0d4aa0(int obj, int k);
short f_03d860(int obj, int a, int b);
void f_0a7840(RivaItemDefinition *item,char *dst,short n);
int f_133fe0(char *a, char *b);


//@ f_012a00
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012a00
 * - Aufgabe im Spiel: Prüft über die Inventarsuche f_0d4aa0, ob der ausgewählte Held (p1) das für die Alchemie
 *   benötigte Arbeitsgerät (Gegenstand 0x2f, Alchemieset) im Gepäck trägt. Fehlt der Gegenstand, gibt das Spiel
 *   die Fehlermeldung 0x7000001 aus und verweigert den Vorgang.
 * - Eingaben: Zeiger bzw. Adresse des handelnden Helden (p1).
 * - Rückgabewert: 1, wenn der Gegenstand 0x2f vorhanden ist, sonst 0.
 * - Wichtige Variablen:
 *   - Globales Meldungsobjekt d_1c2c64: Zeigt bei fehlendem Gerät den Text 0x7000001 an.
 === Ende Beschreibung === */
int f_012a00(int p1)
{
    int ok = 1;
    if (f_0d4aa0(p1, 0x2f) == -1) { d_1c2c64.f_0bf730(0x7000001); ok = 0; }
    return ok;
}

//@ f_012a30
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012a30
 * - Aufgabe im Spiel: Ermittelt alle Alchemierezepte aus den 17 Einträgen der Rezepttabelle d_1a68f4, die der
 *   Held (p1) entweder als Einzelrezept (d_1a68f4[i].a) im Inventar trägt oder die bereits als gelerntes Bit
 *   (f_03d860) in seinem Rezeptbuch (0xbf, Slot s) eingetragen sind. Für jedes verfügbare Rezept wird der
 *   Gegenstandsname des Zieltranks (d_1a68f4[i].b) in den Textpuffer d_1c21b4[k] formatiert, in d_1c29c4[k]
 *   registriert und der Rezeptindex in p2[k] vermerkt; kennt der Held kein einziges Rezept, erscheint die
 *   Meldung 0x7000002.
 * - Eingaben: Zeiger auf den Helden (p1) und Ausgabearray (p2) für die gefundenen Rezeptindizes (0..16).
 * - Rückgabewert: Die Anzahl (n) der verfügbaren Rezepte.
 * - Wichtige Variablen:
 *   - Globale Rezepttabelle d_1a68f4 (17 Einträge zu je 28 Bytes): Enthält je Rezept die Rezept-Item-ID (a), die
 *     Ergebnis-Item-ID (b), den Mindest-Alchemiewert (c) und die Braudauer in Stunden (d).
 *   - Globale Menütextpuffer d_1c21b4 und Textzeiger-Array d_1c29c4.
 *   - Lokaler Inventarslot des Rezeptbuchs (s) und Trefferzähler (n).
 === Ende Beschreibung === */
short f_012a30(int p1, char *p2)
{
    short s = f_0d4aa0(p1, 0xbf);
    short n = 0;
    for (short i = 0; i < 17; i++) {
        short r = f_0d4aa0(p1, d_1a68f4[i].a);
        if (r == -1) {
            if (s == -1) continue;
            if (!f_03d860(p1, s, i)) continue;
        }
        short k = n;
                f_0a7840((RivaItemDefinition *)(*(int *)((*(char **)&d_1c2c40) + d_1a68f4[i].b * 4)),(char *)( d_1c21b4[k]), 1);
        int u = f_133fe0(d_1c3498, d_1c21b4[k]);
        n = n + 1;
        d_1c29c4[k] = u;
        p2[k] = (char)i;
    }
    if ((short)n == 0) {
        RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
        c.tables.p[1] = p1;
        d_1c2c64.f_0bf730(0x7000002);
    }
    return n;
}

//@ f_012b40
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012b40
 * - Aufgabe im Spiel: Öffnet das Auswahlmenü (0x7000003) mit den zuvor von f_012a30 in d_1c29c4[0..19]
 *   eingetragenen Tranknamen und lässt den Spieler auswählen, welches Rezept gebraut werden soll.
 * - Eingaben: Die Anzahl (p1) der im Menü anzuzeigenden Rezepteinträge.
 * - Rückgabewert: Der vom Spieler gewählte Menüindex (r).
 * - Wichtige Variablen:
 *   - Globales Textzeiger-Array d_1c29c4 und Dialogmanager d_1c2c64.
 === Ende Beschreibung === */
int f_012b40(int p1)
{
    d_1c29c4[0] = (d_1c29c4[0] & 0) ? 0 : d_1c29c4[0]; // haelt die Registerzuteilung wie im Original
    d_1c29c4[1] = (d_1c29c4[1] & 0) ? 0 : d_1c29c4[1]; // haelt die Registerzuteilung wie im Original
    d_1c29c4[0] = (d_1c29c4[0] & 0) ? 0 : d_1c29c4[0]; // haelt die Registerzuteilung wie im Original
    d_1c2c64.f_0bf6c0(7);
    int r = d_1c2c64.f_0bf820(0x7000003, (short)p1,
        d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
        d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11], d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15],
        d_1c29c4[16], d_1c29c4[17], d_1c29c4[18], d_1c29c4[19]);
    d_1c2c64.f_0bf680();
    return r;
}

//@ f_012c10
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012c10
 * - Aufgabe im Spiel: Prüft, ob der relevante Talent- bzw. Eigenschaftswert (f_0429a0) des Helden (p1)
 *   mindestens den für das gewählte Rezept p2 geforderten Mindestwert d_1a68f4[p2].c erreicht. Ist der Wert zu
 *   niedrig, gibt das Spiel unter Nennung des Heldennamens die Meldung 0x20000163 aus.
 * - Eingaben: Zeiger auf den Helden (p1) und Rezeptindex (p2).
 * - Rückgabewert: 1, wenn die Voraussetzung erfüllt ist, sonst 0.
 * - Wichtige Variablen:
 *   - Rezeptfeld d_1a68f4[p2].c (geforderter Mindestwert) und lokaler Textkontext (x).
 === Ende Beschreibung === */
int f_012c10(int p1, short p2)
{
    int ok = 1;
    if (f_0429a0((struct hero *)(p1)) < d_1a68f4[p2].c) {
        RivaTextContext x(d_1c349c, d_1c3870, d_1c3498);
        x.tables.p[1] = p1;
        d_1c2c64.f_0bf730(0x20000163);
        ok = 0;
    }
    return ok;
}

//@ f_012c90
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012c90
 * - Aufgabe im Spiel: Prüft bei zeitaufwendigen Rezepten (d_1a68f4[p1].d > 8 Stunden), ob die verbleibende Rast-
 *   bzw. Spielzeit (t aus der Uhr d_1bf1ac, umgerechnet in Tage q = t / 5400 + 1) für die benötigten Brautage
 *   (d_1a68f4[p1].d / 24) ausreicht. Dauert das Rezept länger als verfügbar, wird die Meldung 0x7000004 mit der
 *   Stundenzahl ausgegeben.
 * - Eingaben: Der Index des gewählten Rezepts (p1).
 * - Rückgabewert: 1, wenn genügend Zeit vorhanden ist, sonst 0.
 * - Wichtige Variablen:
 *   - Rezeptfeld d_1a68f4[p1].d (Braudauer in Stunden) und globale Spieluhr d_1bf1ac.
 === Ende Beschreibung === */
int f_012c90(short p1)
{
    int ok = 1;
    if (d_1a68f4[p1].d > 8) {
        int t = (*d_1bf1ac->vt[4])(d_1bf1ac);
        int q = t / 5400 + 1;
        if (d_1a68f4[p1].d / 24 > q) {
            RivaTextContext x(d_1c349c, d_1c3870, d_1c3498);
            x.tables.tail.short_numbers[1] = d_1a68f4[p1].d;
            d_1c2c64.f_0bf730(0x7000004);
            ok = 0;
        }
    }
    return ok;
}

//@ f_012d40
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x012d40
 * - Aufgabe im Spiel: Fragt den Spieler bei einer Braudauer von mehr als 8 Stunden (p1 > 8) über den
 *   Ja/Nein-Auswahldialog 0x7000005 (Antworten 0x7000006 und 0x7000007), ob er tatsächlich die angegebene Anzahl
 *   Stunden (p1) für den Vorgang aufwenden möchte.
 * - Eingaben: Die benötigte Dauer (p1) in Stunden.
 * - Rückgabewert: 1, wenn die Dauer höchstens 8 Stunden beträgt oder der Spieler zustimmt, sonst 0.
 * - Wichtige Variablen:
 *   - Lokaler Textkontext (x), in dessen Zahlenplatzhalter short_numbers[1] die Stundenzahl p1 eingetragen wird.
 === Ende Beschreibung === */
int f_012d40(int p1)
{
    int ok = 1;
    if (p1 > 8) {
        RivaTextContext x(d_1c349c, d_1c3870, d_1c3498);
        d_1c2c64.f_0bf6c0(7);
        x.tables.tail.short_numbers[1] = p1;
        short r = d_1c2c64.f_0bf820(0x7000005, 2, 0x7000006, 0x7000007);
        if (r != ok) ok = 0;
        d_1c2c64.f_0bf680();
    }
    return ok;
}
