/* === Beschreibung (Katalog) ===
 * Einheit gz_05fbf0_t2 (0x05FF60 - 0x060360)
 *
 * Überblick
 * Die Einheit gz_05fbf0_t2 bildet den zweiten Teil von gz_05fbf0 (ab der Modulgrenze 0x05ff60) und implementiert
 * die Basisklasse für begehbare 3D-Dungeons und Innenräume (Archivgruppe 0x2d0001): Konstruktor/Destruktor,
 * Laden und Speichern des Dungeon-Zustands, das Öffnen, Knacken und Einschlagen von Türen (f_060100, f_060190),
 * Gebietsnamen-Abfragen sowie die Zuordnung von Aktionsicons.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 25/27 gleich (suche.py 25.10.2026, Basis gz_05fbf0_P1.CPP)
// I9: aus gz_05fbf0_REST.CPP uebernommen (Stufe-2-Stand), Marken 25 neu
// gz_05fbf0.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x05FBF0-0x060360. DPMI-Aufrufe (DOS-Speicherblock), Tuer-Objekt mit Vtabelle, kleine Stubs.
// ACHTUNG: zwei OBJ - Modulgrenze bei 0x05FF60 (Nullfuellung davor, R13). Teil A 05FBF0-05FF60, Teil B 05FF60-060360.
// STAND: Rest 060100 (17 Bef.), 060190 (36), 060320 (11), 05FF60 (3), Tail-jmp-Marken 0600F0/060230/0602C0 (je 1, vermutlich nur Maske).
#include <i86.h>
#include <string.h>
struct Game; struct Door;
int f_051870(const char *s, int z);
short *f_0696b0(short *p);
int f_0696c0(short *p);
void f_0698b0(short *p, long a, int b);
void f_069970(short *p, long a, int b);
void *f_069730(short *p, int idx);
int f_069640(void *s);
int f_0695b0(void *s);
void f_069650(void *s, int v);
void f_069630(void *s, int v);
void f_069670(void *s, int v);
int f_08c920(int a, int b);
short f_1457e0(short n);
void f_11f920(int k, int b, int c);
void f_056a50(int a);
int f_0de7c0(Game *g);
short f_0de820(Game *g);
short f_0de9a0(Game *g);
void f_0dd750(Game *g, unsigned short v);
void f_0de9b0(Game *g, int v);
int f_0de880(Game *g);
int f_0de840(Game *g);
void f_019800(void *p, int a, int b, int c);
void f_019b30(void *p, short *q);
void f_01a490(void *p);
void f_01a470(void *p);
struct Q { void f_0e93f0(char *p, long code); };
struct Msg { void f_0bf730(long code); };


void *f_038c40(Game *g);
extern struct RMs { unsigned edi, esi, ebp, r0, ebx, edx, ecx, eax; unsigned short fl, es, ds, fs, gs, ip, sp, ss; } d_1bd68c;
extern short *d_1bd6c0;
extern struct S3 { char a; short b; } d_1bd6c8;
extern signed char d_1bd90e;
extern int d_1bd91c;
extern signed char d_1c01cc;
extern short d_1c2198;
extern short d_1c212a;
extern Game *d_1c0004;
extern Game d_1bfdbc[6];
extern char d_1c2a84[];
extern char d_1c27a8[];
extern Q d_1c38b0;
extern Msg d_1c2c64;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern void *d_1badd0[];
struct Game { char b[0x61]; };
struct Door { short id; char b[6]; void (**vt)(); };

//@ f_05ff60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor des Dungeon-/Innenraum-Steuerobjekts für den Dungeon mit der Kennung code:
 *   Initialisiert das eingebettete Basisobjekt (f_0696b0), trägt die virtuelle Methodentabelle d_1badd0 und den
 *   globalen Zeiger d_1bd6c0 ein, lädt die Dungeon-Zustandsdaten aus dem Archivbereich 0x2d0001 (f_0698b0),
 *   aktualisiert für alle sechs Gruppenplätze (d_1bfdbc[0..5]) im selben Dungeon gespeicherte Positionswerte und
 *   initialisiert die Automap (d_1c2a84) über f_019800 und f_019b30.
 * - Eingaben:
 *   - self (Zeiger auf das zu konstruierende Dungeon-Objekt).
 *   - code (Dungeon-Kennung).
 * - Rückgabewert: short * - Zeiger auf das initialisierte Dungeon-Objekt self.
 * - Wichtige Variablen:
 *   - d_1bd6c0 (Globaler Zeiger auf das aktuell aktive Dungeon-Steuerobjekt).
 *   - d_1bfdbc (Array der bis zu sechs Teilgruppen-Strukturen).
 *   - d_1c2a84 (Globales Automap-Steuerobjekt).
 === Ende Beschreibung === */
short *f_05ff60(short *self, signed char code)
{
    self = f_0696b0(self + 1) - 1;
    *self = code;
    d_1bd6c0 = self;
    *(void ***)(self + 4) = d_1badd0;
    f_0698b0(self + 1, 0x2d0001, code);
    short *p = self;
    short i;
    int codex_index;
    for (i = 0; (codex_index = i) < 6; i++) {
        codex_index *= 0x61;
        Game *g = (Game *)(codex_index + (unsigned)d_1bfdbc);
        if (f_0de7c0(g) == 1) {
            if (f_0de820(g) == *p) {
                if (f_0de9a0(g) != -1) {
                    unsigned short u = f_0de9a0(g);
                    f_0dd750(g, u);
                    f_0de9b0(g, -1);
                }
            }
        }
    }
    f_019800(d_1c2a84, *(signed char *)p, f_0de840(d_1c0004), f_0de880(d_1c0004));
    f_019b30(d_1c2a84, p + 1);
    return p;
}

//@ f_060030
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor des Dungeon-Steuerobjekts: Schließt bzw. sichert die Automap
 *   (f_01a490(d_1c2a84)), setzt den globalen Dungeon-Zeiger d_1bd6c0 auf 0 und baut das eingebettete Basisobjekt
 *   über f_0696c0 ab.
 * - Eingaben:
 *   - p (Zeiger auf das Dungeon-Objekt).
 *   - z (Destruktor-Flags).
 * - Rückgabewert: int - Rückgabewert des Basisdestruktors (verschoben auf den Objektanfang).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_060030(short *p, int z)
{
    *(void ***)(p + 4) = d_1badd0;
    f_01a490(d_1c2a84);
    d_1bd6c0 = 0;
    return f_0696c0(p + 1) - 2;
}

//@ f_060060
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt den gespeicherten Objekt- und Türzustand des aktuellen Dungeons (*p) aus dem
 *   Archivbereich 0x2d0001 über f_0698b0 neu ein.
 * - Eingaben:
 *   - p (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_060060(short *p)
{
    f_0698b0(p + 1, 0x2d0001, *p);
}

//@ f_060080
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Speichert die aktuellen Automap-Daten (f_01a470(d_1c2a84)) sowie den Objekt- und Türzustand
 *   des aktuellen Dungeons (*p) über f_069970 in den Bereich 0x2d0001.
 * - Eingaben:
 *   - p (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_060080(short *p)
{
    f_01a470(d_1c2a84);
    f_069970(p + 1, 0x2d0001, *p);
}

//@ f_0600a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leere virtuelle Platzhalter-Methode (void) in der Methodentabelle des Dungeon-Basisobjekts.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0600a0() {}

//@ f_0600b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Berechnet aus der Dungeon-Kennung *p die zugehörige Text-/Ressourcenkennung *p + 0x2d000001.
 * - Eingaben:
 *   - p (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: int - Die Ressourcenkennung *p + 0x2d000001.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0600b0(short *p)
{
    return *p + 0x2d000001;
}

//@ f_0600c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt den Namen bzw. Beschreibungstext des aktuellen Dungeons (*p + 0x2d000001) über
 *   d_1c38b0.f_0e93f0 in den globalen Textpuffer d_1c27a8 und gibt diesen zurück.
 * - Eingaben:
 *   - p (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: char * - Zeiger auf den geladenen Dungeon-Namen in d_1c27a8.
 * - Wichtige Variablen:
 *   - d_1c27a8 (Globaler Zeichenkettenpuffer für den Ortsnamen).
 === Ende Beschreibung === */
char *f_0600c0(short *p)
{
    d_1c38b0.f_0e93f0(d_1c27a8, *p + 0x2d000001);
    return d_1c27a8;
}

//@ f_0600f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leitet die Ereignis-/Aktionskennung b an die zentrale Ereignisverarbeitung f_056a50(b)
 *   weiter.
 * - Eingaben:
 *   - a (Unbenutzter this-Zeiger).
 *   - b (Ereignis- oder Aktionscode).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0600f0(int a, int b)
{
    f_056a50(b);
}

//@ f_060100
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Öffnen bzw. Untersuchen einer Tür oder eines Durchgangs mit dem Objektindex a
 *   im Dungeon self: Prüft über f_069640, ob das Objekt aktiv ist, ruft den Tür-/Schlossdialog f_08c920(a, b)
 *   auf, setzt das Aktualisierungsflag d_1c2198 = 1 und aktualisiert bei einem regulären Aufruf (d_1bd91c == 0)
 *   den Türstatus über f_069650 bzw. f_069630 anhand von d_1bd90e.
 * - Eingaben:
 *   - self (Zeiger auf das Door-/Dungeon-Objekt).
 *   - a (Index des Tür-/Dungeon-Objekts).
 *   - b (Modus- oder Schwierigkeitsparameter für f_08c920).
 * - Rückgabewert: short - Ergebnis von f_08c920 (0 wenn geschlossen geblieben, != 0 wenn geöffnet).
 * - Wichtige Variablen:
 *   - p (Zeiger auf den Dungeon-Objekteintrag a).
 *   - t (Zwischenspeicher für das Direktaufruf-Flag d_1bd91c).
 *   - s (Neuer Türstatus aus d_1bd90e).
 === Ende Beschreibung === */
short f_060100(Door *self, short a, short b)
{
    short rs;
    short res = 0;
    int t = d_1bd91c;
    void *p = f_069730((short *)self + 1, a);
    void *q = p;
    if (f_069640(p)) {
        res = f_08c920(a, b);
        rs = res;
        *(volatile short *)&d_1c2198 = 1;
        {
            short s = d_1bd90e;
            if (t == 0) {
                if (f_0695b0(p)) {
                    if ((short)(s & 0xffff) == 0 || rs == 0) f_069650(q, 0);
                    else f_069630(p, s);
                }
            }
        }
    }
    return res;
}

typedef int (*VF3)(Door *, int, int);
//@ f_060190
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft und würfelt für das Tür-/Dungeon-Objekt a mit einer prozentualen Wahrscheinlichkeit b
 *   (0..100), ob die Tür unverschlossen bzw. passierbar ist: Ruft zunächst bei aktivem Objekt mit gesetztem
 *   d_1bd91c = 1 die virtuelle Prüfmethode vt[0] auf; liefert diese nicht 1, wird mit f_1457e0(100) gewürfelt
 *   und bei b >= Wurf der Zustand über f_069650/f_069670 auf 1 (offen/aktiv), andernfalls auf 0 gesetzt.
 * - Eingaben:
 *   - self (Zeiger auf das Door-/Dungeon-Objekt).
 *   - a (Index des Tür-/Dungeon-Objekts).
 *   - b (Schwellenwert 0..100 für den Prozentwurf).
 * - Rückgabewert: short - Rückgabewert von vt[0] bzw. -1.
 * - Wichtige Variablen:
 *   - p (Zeiger auf den Dungeon-Objekteintrag a).
 *   - r (Zufallswurf 1..100 aus f_1457e0(100)).
 === Ende Beschreibung === */
short f_060190(Door *self, short a, short b)
{
    short res = -1;
    int fl = 0;
    void *p = f_069730((short *)self + 1, a);
    if (f_069640(p)) {
        d_1bd91c = 1;
        res = ((VF3)self->vt[0])(self, a, 0);
        if ((short)res == 1) goto skip;
    }
    fl = 1;
skip:
    if (fl == 1) {
        short r = f_1457e0(100);
        if (b >= r) { f_069650(p, 1); f_069670(p, 1); }
        else { f_069650(p, 0); f_069670(p, 0); }
    }
    return res;
}

//@ f_060230
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst über f_11f920(3, b, c) eine Kollisions- oder Schrittaktion vom Typ 3 im 3D-Dungeon aus.
 * - Eingaben:
 *   - a (Unbenutzter this-Zeiger).
 *   - b, c (Koordinaten- oder Objektparameter für f_11f920).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_060230(int a, int b, int c)
{
    f_11f920(3, b, c);
}

//@ f_060240
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt beim erstmaligen Auslösen der Zustandsvariable d_1c01cc == 1 nacheinander die beiden
 *   Textmeldungen 0x250000ff und 0x25000100 mit dem aktuellen Anführer (f_038c40(d_1c0004)) als Textsubjekt aus
 *   und schaltet d_1c01cc auf 2 weiter.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - c (RivaTextContext für die Textformatierung).
 *   - d_1c01cc (Zustandsflag zur einmaligen Ausgabe der beiden Meldungen).
 === Ende Beschreibung === */
void f_060240()
{
    RivaTextContext c(d_1c349c, d_1c3870, d_1c3498);
    c.tables.objects[1] = f_038c40(d_1c0004);
    if ((d_1c01cc == 1) != 0) {
        d_1c01cc = 2;
        d_1c2c64.f_0bf730(0x250000ff);
        d_1c2c64.f_0bf730(0x25000100);
    }
}

//@ f_0602c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst über f_11f920(4, b, c) eine Kollisions- oder Schrittaktion vom Typ 4 im 3D-Dungeon aus.
 * - Eingaben:
 *   - a (Unbenutzter this-Zeiger).
 *   - b, c (Koordinaten- oder Objektparameter für f_11f920).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0602c0(int a, int b, int c)
{
    f_11f920(4, b, c);
}

//@ f_0602d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob ein angefragter Aktions- bzw. Befehlscode b im Dungeon unterstützt wird, und lässt
 *   die Codes 0x29 und 0x2b (Dungeon-Sonderaktionen) zu.
 * - Eingaben:
 *   - a (Unbenutzter this-Zeiger).
 *   - b (Angefragter Aktionscode).
 * - Rückgabewert: int - b, wenn b == 0x29 oder b == 0x2b, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0602d0(int a, int b)
{
    int r = 0;
    if ((short)b == 0x29 || (short)b == 0x2b) r = b;
    return r;
}

typedef void (*VF1)(Door *);
//@ f_0602f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die im Dungeon gewählte Sonderaktion x aus, indem bei x == 0x29 die virtuelle Methode
 *   vt[2] und bei x == 0x2b die virtuelle Methode vt[3] des Dungeon-Objekts self aufgerufen wird.
 * - Eingaben:
 *   - self (Zeiger auf das Dungeon-Objekt).
 *   - x (Aktionscode 0x29 oder 0x2b).
 * - Rückgabewert: int - 1, wenn die Aktion behandelt wurde, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0602f0(Door *self, unsigned short x)
{
    int r = 1;
    switch (x) {
    case 0x29: ((VF1)self->vt[2])(self); break;
    case 0x2b: ((VF1)self->vt[3])(self); break;
    default: r = 0;
    }
    return r;
}

extern S3 **d_1c212c;
//@ f_060320
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Trägt das Aktionsicon 0x223 (Typ 0) über die Struktur d_1bd6c8 in die globale
 *   Aktionsicon-Leiste d_1c212c an der Position d_1c212a ein und erhöht den Iconzähler d_1c212a um 1.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd6c8 (Statischer 3-Byte-Eintrag für das Icon 0x223).
 *   - d_1c212c, d_1c212a (Globales Zeigerarray und Anzahl der aktuell eingeblendeten Aktionsicons).
 === Ende Beschreibung === */
void f_060320()
{
    d_1bd6c8.a = 0;
    d_1bd6c8.b = 0x223;
    d_1c212c[d_1c212a] = &d_1bd6c8;
    (*(volatile short *)&d_1c212a) = d_1c212a + 1;
}
