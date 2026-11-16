/* === Beschreibung (Katalog) ===
 * Einheit tavern_neu (0x11F400 - 0x11F550)
 *
 * Überblick
 * Die Einheit tavern_neu enthält die Zufallsereignis-Prüfung Tavern::f_11f400 für Tavernen und Wirtshäuser in
 * Riva, die beim Besuch anhand einer Wahrscheinlichkeitstabelle (chance[1..10][0..2]) ein Tavernenereignis
 * auswürfelt.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 11f400-11f550 aus Quelle/cpp/TAVERN.CPP; erster Entwurf, Einbau separat prüfen.
// tavern.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 2 Probe 2.7
// Code 0x11F400-0x11F550, Daten 0x1A7ED8-0x1A7F38 (Dateiname + Tabelle ab 0x1A7EF6), wpp386 -4r -oneatx -zp1 -s (Watcom C/C++ 10.6)
// Namen f_/d_<Adresse> sind Platzhalter bis Phase 6.

extern const char d_1a7ed8[];
#define tavern_file d_1a7ed8

static const short chance[11][3] = {                     // 0x1A7EF6  [Wurf W10][Typ - 10], Zeile 0 unbenutzt
    {   0,   0,   0 },
    {  70,   0,  25 },
    {   0,   0, 100 },
    {  30,   0,  60 },
    {  50,  20,  25 },
    {  20,  60,  15 },
    {  30,  70,   0 },
    {  30,  40,  25 },
    {  50,   0,  40 },
    {   0, 100,   0 },
    {   0,   0, 100 }
};

short f_1457e0(short n);                                 // Zufallszahl 1..n
struct Game;
extern Game *d_1c0004;                                   // globales Spielobjekt
void *f_039040(Game *g);

int f_0d6690(int n);
extern signed char d_1c00c4, d_1c01b8, d_1c00bc, d_1bfac4;
struct Msg { void f_0bf730(long code); };
extern Msg d_1c2c64;                                     // Objekt bei 0x1C2C64

inline int f_c4()  { return d_1c00c4 == 1; }            // R16
inline int f_b8()  { return d_1c01b8 == 0; }
inline int f_bc()  { return d_1c00bc == 1; }
inline int f_ac4() { return d_1bfac4 == 1; }

struct Tavern {
    unsigned short type;                                 // +0x00  10..12
    char  pad[0x5e];
    short level;                                         // +0x60
    short pad2;
    short state;                                         // +0x64
    void  f_11f400();                                    // 0x11F400
};

//@ f_11f400
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft beim Aufenthalt in einer Taverne (sofern this->state == 0 und ein Wurf
 *   f_1457e0(this->level) >= 50 gelingt), welches der zehn möglichen Tavernenereignisse (r = 1..10) gemäß der
 *   nach Tavernentyp (this->type - 10, also Typ 10..12) gewichteten Wahrscheinlichkeitstabelle chance[r][type -
 *   10] eintritt; wird Ereignis 10 gezogen, prüft die Funktion zusätzlich mehrere Ausschlussbedingungen
 *   (Gruppenbegleiter-Typ c == 1 oder 6, Questflags d_1c00c4, d_1c01b8, d_1c00bc, d_1bfac4 sowie
 *   f_0d6690(2..4)), gibt bei Zulässigkeit die Meldung 0x1b000008 aus und speichert die Ereignisnummer r in
 *   this->state.
 * - Eingaben: this (Zeiger auf die Tavern-Instanz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->type (+0x00): Tavernenkategorie (10, 11 oder 12 für Spalte 0..2 in chance).
 *   - this->level (+0x60): Ereignisschwelle bzw. Würfelobergrenze der Taverne.
 *   - this->state (+0x64): Aktuell ausgelöste Ereignisnummer (0 = kein Ereignis aktiv, 1..10 = Ereignisnummer).
 *   - chance[11][3] (0x1A7EF6): Prozenttabelle der Eintrittswahrscheinlichkeiten je W10-Wurf (1..10) und
 *     Tavernentyp (10..12).
 === Ende Beschreibung === */
void Tavern::f_11f400()
{
    short r;
    int ok;
    if (state == 0 && f_1457e0(level) >= 50) {
        short v;
        do {
            v = chance[r = f_1457e0(10)][type - 10];
        } while (f_1457e0(100) > v);
        ok = 1;
        if (r == 10) {
            short c = 0;
            if (f_039040(d_1c0004)) c = f_042400((struct hero *)(f_039040(d_1c0004)));
            int d, b, a;
            a = f_0d6690(2);
            b = f_0d6690(3);
            d = f_0d6690(4);
            if ((f_c4() && f_b8()) || c == 6 || c == 1 || f_bc() || b || a || d || f_ac4()) ok = 0;
        }
        if (ok == 1) {
            d_1c2c64.f_0bf730(0x1b000008L);
            state = r;
        }
    }
}
