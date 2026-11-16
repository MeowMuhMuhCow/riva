/* === Beschreibung (Katalog) ===
 * Einheit: gz_0132a0
 *
 * Adressbereich: 0x0132a0-0x0137e0
 * Spielsystem: Zwei Bereiche:
 * 1. Alchimie-Durchführung (f_0132a0-f_013580): Zutatenprüfung, Zutatenverbrauch mit Leergut-Rückgabe und
 *   Brauprobe (Schwesterfunktionen hero_has_ingredients, do_alchemy, hero_use_ingredients in Sternenschweif
 *   OVL074.CPP).
 * 2. ALF-Archivverwaltung (f_013670-f_013770): Konstruktor, Destruktor und Wiederöffnen der Archivklasse AlfDisk
 *   für .ALF-Spieldatenarchive.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAITEX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 5/6 gleich (suche.py 26.10.2026, Basis gz_0132a0_P1.CPP)
// P1 0/6 GLEICH (fdiff), 013670/013710/013770 = 0 Befehle (nur Fixup-Maske), Rest: 0132A0 REG, 0133B0 REG/FOLGE (res), 013580 REG (e/f)
// gz_0132a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0132A0-0x0137E0
#include <string.h>
struct Msg { void f_0bf730(long code); void f_0bf6c0(int k); int f_0bf820(long code, ...); void f_0bf680(); };
extern Msg d_1c2c64;


struct Ent { short a; short l[10]; short b; short c; signed char e; unsigned char d; };   // 28 Byte
extern Ent d_1a68f4[];

extern char d_1c21b4[];
extern char d_1c349c[], d_1c3870[], d_1c3498[], d_1c1190[], d_1ba9d0[], d_1ba9e4[];
extern int d_1c0004;
int f_0d4aa0(int obj, int k);
void f_036300(int obj, int a, int b);
void f_0366e0(int obj, int a, int b, int c);
int f_039660(int a, int b);



void f_0434d0(int obj, int a);
void f_044230(int obj, int a);
short f_044c90(int obj, int a, int b);
void f_0a7840(RivaItemDefinition *item,char *dst,short n);
short f_0dc020(int a, int b);
void f_0dcd30(int a, int b, int c);
int f_133fe0(char *a, char *b);
void f_0ed8f0(void *obj, long code, const char *s, ...);
int f_144fbf(const char *name, int mode, ...);            // open
int f_144e8b(int h, void *buf, unsigned n);               // read
int f_145259(int h);                                      // close
void *f_145234(void *p, void *d);
void f_145254();
struct AD { void *vp; char *name; long magic; char hdr[0x2c]; int fd; short c3c; short c3e; short s40; short *p42; char pad[0x38]; short *p7e; };
void f_013580(int p1, int p2);
void f_0137e0(AD *p, int p2);

//@ f_0132a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft vor dem Brauen, ob der Held sämtliche Zutaten des gewählten Alchimie-Rezepts im
 *   Gepäck trägt (hero_has_ingredients). Dazu wird jede Zutat der Rezeptliste probeweise einzeln aus dem
 *   Inventar entfernt (f_036300), damit mehrfach benötigte gleiche Zutaten korrekt gezählt werden, und
 *   anschließend werden alle probeweise entnommenen Zutaten wieder zurückgegeben (f_0366e0). Fehlt eine Zutat,
 *   gibt die Funktion selbst die Fehlermeldung 0x7000008 mit dem Namen der fehlenden Zutat aus.
 * - Eingaben / Rückgabe: Zeiger auf den Helden (p1) und Rezeptindex (p2, 0..16); gibt 0 zurück, wenn alle
 *   Zutaten vorhanden sind, und 1, wenn mindestens eine Zutat fehlt.
 * - Wichtige Variablen & Daten:
 *   - d_1a68f4[p2].l[0..9]: Zutatenliste des Rezepts (Ende bei -1).
 *   - bad: Gegenstands-ID der ersten fehlenden Zutat für die Fehlermeldung 0x7000008.
 === Ende Beschreibung === */
int f_0132a0(int p1, int p2)
{
    int t61_11;
    int ok = 1;
    short i = 0;
    Ent *e = &d_1a68f4[(short)p2];
    short bad = 0;
    while ((t61_11 = e->l[i]) != -1 && ok == 1) {
        short r = 0;
        r = f_0d4aa0(p1, e->l[i]);
        if ((short)r == -1) {
            bad = e->l[i];
            ok = 0;
        } else {
            f_036300(p1, (short)r, 1);
        }
        i = i + 1;
    }
    i--;
    if (!ok) i--;
    while (i >= 0) {
        f_0366e0(p1, e->l[i--], 1, 1);
    }
    if (bad != 0) {
        void f_125400(void *, void *, void *, void *);
        void f_1254a0(void *, int);
        RivaTextContextData x;
        f_125400(&x, d_1c349c, d_1c3870, d_1c3498);
        x.tables.tail.items[1] = d_1c2c40[bad];
        x.tables.tail.item_counts[1] = 1;
        d_1c2c64.f_0bf730(0x7000008);
        f_1254a0(&x, 0);
    }
    return !ok;
}

//@ f_0133b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt das eigentliche Brauen eines Tranks aus (do_alchemy): verbraucht die Zutaten über
 *   f_013580, zieht die benötigte Astralenergie ab (f_044230), löscht die Brau-Statusfelder am Helden und
 *   würfelt eine Talentprobe auf Alchimie (0x20) mit dem Probenzuschlag des Rezepts (f_044c90). Bei Erfolg
 *   erhält der Held den fertigen Trank ins Inventar (f_0366e0) samt Erfolgsmeldung 0x20000030 (bzw. beim
 *   Scherzrezept 0x153 verlässt der goldgierigste Held die Gruppe mit Meldung 0x200001a4); bei Misslingen erhält
 *   der Held die erste Zutat zurück und es erscheint die Misserfolgsmeldung 0x20000031.
 * - Eingaben / Rückgabe: Zeiger auf den brauenden Helden (obj), Rezeptindex (k) und Abbruchflag (p3, im Spiel
 *   immer 0; bei != 0 wird ein Erfolg unterdrückt); gibt 1 bei gelungenem Trank, 0 bei Fehlschlag zurück.
 * - Wichtige Variablen & Daten:
 *   - d_1a68f4[k]: Rezepteintrag (b = Ergebnisgegenstand, c = AE-Kosten, e = Probenzuschlag, l[0] = erste
 *     Zutat).
 *   - d_1c0004: Aktive Heldengruppe (für die Suche nach dem Helden mit höchster Goldgier, Eigenschaft 10, bei
 *     Rezept 0x153).
 * - Besonderheiten / Originalfehler: Beim Scherzrezept 0x153 ("Geldscheißer") wird der betroffene Held über
 *   f_0dcd30 ohne Prüfung der verbleibenden Gruppengröße aus der Gruppe entfernt. Besteht die aktuelle
 *   (Teil-)Gruppe nur aus diesem einen Helden, bleibt eine leere Gruppe zurück, die das Spiel unspielbar macht
 *   (gleicher Fehler wie Nr. 363 in Sternenschweif).
 === Ende Beschreibung === */
int f_0133b0(int obj, short k, short p3)
{
    Ent *e = d_1a68f4 + (short)(k & 0xffff); // Haelt die Registerfolge (edx/eax beim Tabellenzugriff im else-Zweig) wie im Original
    int r = 0;
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    f_013580(obj, (short)(k & 0xffff)); // Haelt die Registerfolge wie im Original
    f_044230(obj, e->c);
    f_042530((struct hero *)(obj), 0);
    f_0434d0(obj, 0);
    f_042840((struct hero *)(obj), 0);
    f_042860((struct hero *)(obj), 0);
    if (f_044c90(obj, 0x20, e->e) > 0 && (int)p3 == 0) {
        if (e->b == 0x153) {
            int t = f_039660(d_1c0004, 10);
            c.tables.p[1] = obj;
            c.tables.p[2] = t;
            obj = 0x200001a4;
#if FIX_R025   /* R025: Beim Scherzrezept 0x153 letzten Helden einer 1-Personen-Gruppe nicht entfernen */
            { short f_0db9a0(int p1); if (f_0db9a0(d_1c0004) > 1) f_0dcd30(d_1c0004, f_0dc020(d_1c0004, t), -1); }
#else
            f_0dcd30(d_1c0004, f_0dc020(d_1c0004, t), -1);
#endif
        } else {
            f_0366e0(obj, e->b, 1, 1);
            f_0a7840(d_1c2c40[e->b], d_1c21b4, 1);
            c.tables.p[1] = obj;
            c.tables.tail.numbers[1] = f_133fe0(d_1c3498, d_1c21b4);
            obj = 0x20000030;
        }
        d_1c2c64.f_0bf730(obj);
        r = 1;
    } else {
        f_0366e0(obj, e->l[0], 1, 1);
        {
            RivaItemDefinition **tab = d_1c2c40;
            { RivaItemDefinition *t_ = tab[e->b]; f_0a7840(t_, d_1c21b4, 1); }
        }
        c.tables.p[1] = obj;
        c.tables.tail.numbers[1] = f_133fe0(d_1c3498, d_1c21b4);
        d_1c2c64.f_0bf730(0x20000031);
    }
    return r;
}
//@ f_013580
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entfernt beim Braubeginn alle Zutaten des Rezepts p2 aus dem Heldeninventar
 *   (hero_use_ingredients). Für flüssige Zutaten in Flaschen (0x5b Wein, 0x5c Schnaps, 0x39, 0x29 Öl) gibt die
 *   Funktion eine leere Glasflasche (0x1f) bzw. bei Öl eine leere Bronzeflasche (0x2a) ins Inventar zurück,
 *   sobald bereits eine Flasche für den fertigen Trank verbraucht wurde (oder das Rezept 0x170 keinen eigenen
 *   Flaschenbehälter benötigt).
 * - Eingaben / Rückgabe: Zeiger auf den Helden (p1) und Rezeptindex (p2); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - f: Flaschenmerker (0 = erste freiwerdende Flasche wird für das Brauergebnis selbst verbraucht; 1 = jede
 *     weitere Flüssigkeitszutat hinterlässt eine leere Flasche 0x1f/0x2a im Gepäck; bei Rezeptgegenstand 0x170
 *     von Beginn an 1).
 === Ende Beschreibung === */
void f_013580(int p1, int p2)
{
    int f;
    short *e = (short *)&d_1a68f4[(short)p2];
    short i = 0;
    f = 0;
    if (e[0] == 0x170) f = 1;
    while (e[1 + i] != -1) {
        short r = f_0d4aa0(p1, e[i + 1]);
        f_036300(p1, r, 1);
        if (e[i + 1] == 0x1f || e[i + 1] == 0x2a) f = 1;
        if (e[i + 1] == 0x5b || e[i + 1] == 0x5c || e[i + 1] == 0x39 || e[i + 1] == 0x29) {
            if (f) {
                f_0366e0(p1, (short)(e[i + 1] == 0x29 ? 0x2a : 0x1f), 1, 1);
            } else {
                f = 1;
            }
        }
        i = i + 1;
    }
}

//@ f_013670
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor der Archivverwaltung AlfDisk: initialisiert die Objektfelder, öffnet die
 *   angegebene .ALF-Archivdatei (z. B. "rivahelp.alf"), liest den 0x30 Bytes großen Dateikopf, prüft die
 *   Dateikennung "ALF " (0x20464c41, sonst Abbruchfehler 0x29a000e) und lädt anschließend über f_0137e0 die
 *   zugehörige .MOD-Modulliste.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (p), Dateiname des .ALF-Archivs (n) und Dateiname der
 *   .MOD-Datei (p3); gibt den Objektzeiger p zurück.
 * - Wichtige Variablen & Daten:
 *   - AlfDisk-Objekt (0x82 Bytes): Virtuelle Methodentabelle (+0), Archivdateiname (+4), 48-Byte-Archivkopf ab
 *     +8 (magic = "ALF "), Dateihandle fd (+0x38), gepufferter Datei-/Modulindex c3c/c3e (-1), Modulanzahl s40,
 *     Modulzuordnungstabelle p42 und Modul-Indexpuffer p7e.
 === Ende Beschreibung === */
AD *f_013670(AD *p, char *n, int p3)
{
    AD *q = p;
    *(char **)&p->vp = d_1ba9e4;
    p->c3c = -1;
    p->c3e = -1;
    p->p7e = 0;
    p->name = n;
    p->s40 = 0;
    p->p42 = 0;
    int ok = 0;
    p->fd = f_144fbf(p->name, 0x200, 0x180);
    if (p->fd > 0) {
        f_144e8b(p->fd, &p->magic, 0x30);
        if (p->magic == 0x20464c41) ok = 1;
    }
    if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, q->name);
    f_0137e0(p, p3);
    return p;
}

//@ f_013710
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor der Archivverwaltung AlfDisk: gibt den Modul-Indexpuffer p7e sowie die
 *   Modulzuordnungstabelle p42 frei, schließt bei geöffnetem Dateihandle (fd > -1) die .ALF-Archivdatei und gibt
 *   je nach Watcom-Destruktorschalter (fl) das Objekt oder Objektfeld frei.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (p) und Watcom-Destruktorflags (fl: Bit 2 = Objekt
 *   freigeben, Bit 4 = Array-Destruktor); gibt p zurück.
 * - Wichtige Variablen & Daten: Felder p7e, p42 und fd des AlfDisk-Objekts.
 === Ende Beschreibung === */
AD *f_013710(AD *p, unsigned fl)
{
    if (fl & 4) {
        f_145234(p, d_1ba9d0);
        f_145254();
        return p;
    }
    *(char **)&p->vp = d_1ba9e4;
    if (p->p7e) delete p->p7e;
    delete p->p42;
    if (p->fd > -1) f_145259(p->fd);
    if (fl & 2) delete p;
    return p;
}

//@ f_013770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die .ALF-Archivdatei eines bestehenden AlfDisk-Objekts erneut, liest den
 *   0x30-Byte-Kopf und prüft die Kennung "ALF " (sonst Fehler 0x29a000e), ohne die .MOD-Modulliste neu
 *   aufzubauen (gedacht zum Wiederöffnen nach vorübergehendem Schließen der Archivdatei).
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (p); keine Rückgabe.
 * - Wichtige Variablen & Daten: Felder name, fd und magic (0x20464c41) des AlfDisk-Objekts.
 === Ende Beschreibung === */
void f_013770(AD *p)
{
    int ok = 0;
    p->fd = f_144fbf(p->name, 0x200, 0x180);
    if (p->fd > 0) {
        f_144e8b(p->fd, &p->magic, 0x30);
        if (p->magic == 0x20464c41) ok = 1;
    }
    if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, p->name);
}
