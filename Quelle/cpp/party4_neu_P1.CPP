/* === Beschreibung (Katalog) ===
 * Einheit party4_neu (0x0DE600 - 0x0DEA00)
 *
 * Überblick
 * Die Einheit party4_neu enthält die Textformatierungsfunktion f_0de600, die eine durch Kommas und "und"
 * verbundene Aufzählung aller aktiven Gruppenmitglieder erzeugt, sowie 39 kleine Zugriffsfunktionen (Getter und
 * Setter) der zentralen Game-Struktur (f_0de790 bis f_0de9f0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0de600-0de790 aus Quelle/cpp/PARTY4.CPP; erster Entwurf, Einbau separat prüfen.
// party4.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xDE600-0xDE790. Baut einen Text aus Teilstuecken zusammen.
#include <string.h>
extern const char d_1a6344[];
#define party4_file d_1a6344
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
struct Obj { int x; };
extern Obj *d_1c0004;
extern char d_1c38b0[];
short f_0de7f0(Obj *o);
int f_038c80(Obj *o);
int f_0391b0(Obj *o, int x);

void f_0e93f0(char *a, char *b, long code);

//@ f_0de600
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchläuft die Ringliste der aktiven Gruppenmitglieder (f_038c80 / f_0391b0) und hängt
 *   deren Rufnamen (f_0422b0) an den Zielpuffer buf an, wobei zwischen aufeinanderfolgenden Namen jeweils ein
 *   Komma (0x20000193, ", ") und vor dem letzten Namen das Bindewort "und" mit Leerzeichen (0x200001b5 +
 *   0x20000195 + 0x200001b5) eingefügt wird.
 * - Eingaben: unused (ungenutzter erster Parameter), buf (Zielpuffer für die zusammengesetzte Namensliste).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Verbleibende Anzahl der Gruppenmitglieder (f_0de7f0(d_1c0004)).
 *   - x: Laufender Zeiger auf das aktuelle Gruppenmitglied.
 *   - tmp: Temporärer 32-Byte-Puffer zum Laden der Trennzeichen-Textbausteine über f_0e93f0.
 === Ende Beschreibung === */
void f_0de600(int unused, char *buf)
{
    int n = f_0de7f0(d_1c0004);
    int x = f_038c80(d_1c0004);
    char *tmp = new (mark(party4_file, 0x1eb)) char[0x20];
    *buf = 0;
    do {
        n = n - 1;
        if (f_038c80(d_1c0004) != x) {
            if (n == 0) {
                f_0e93f0(d_1c38b0, tmp, 0x200001b5L);
                strcat(buf, tmp);
                f_0e93f0(d_1c38b0, tmp, 0x20000195L);
                strcat(buf, tmp);
                f_0e93f0(d_1c38b0, tmp, 0x200001b5L);
                strcat(buf, tmp);
            } else {
                f_0e93f0(d_1c38b0, tmp, 0x20000193L);
                strcat(buf, tmp);
            }
        }
        strcat(buf, f_0422b0((struct hero *)(x)));
        x = f_0391b0(d_1c0004, x);
    } while (x != f_038c80(d_1c0004));
    delete tmp;
}

// Astra700: 39 bislang nicht registrierte Game-Zugriffe aus G0DE790.CPP.
// gz_0de790.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xDE790-0xDEA70. Feldzugriffe (Getter/Setter) der Game-Struktur und ein Konstruktor-artiger Initialisierer.
#pragma pack(1)
struct Game {
    int a[7]; signed char b1c; int l1d; short s21, s23, s25, s27, s29, s2b; int i2d, i31, i35, i39; short s3d, s3f; int i41, i45; signed char c49, c4a;
    void f_0de790(short k, int v); void f_0de7a0(signed char v); void f_0de7b0(int v);
    int f_0de7c0(); int f_0de7d0(short k); int f_0de7e0(); short f_0de7f0();
    short f_0de800(); void f_0de810(short v); short f_0de820(); void f_0de830(short v);
    int f_0de840(); void f_0de850(int v); int f_0de860(); void f_0de870(int v);
    int f_0de880(); void f_0de890(int v); int f_0de8a0(); void f_0de8b0(int v);
    short f_0de8c0(); void f_0de8d0(short v); short f_0de8e0(); void f_0de8f0(short v);
    short f_0de900(); void f_0de910(short v); short f_0de920(); void f_0de930(short v);
    void f_0de940(short v); short f_0de950(); void f_0de960(int v); int f_0de970();
    int f_0de980(); void f_0de990(int v); short f_0de9a0(); void f_0de9b0(short v);
    int f_0de9c0(); void f_0de9d0(signed char v); short f_0de9e0(); void f_0de9f0(signed char v);
};
//@ f_0de790
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt den 32-Bit-Wert v (typischerweise einen Heldenzeiger) an den Slot-Index k des
 *   Heldenarrays this->a[0..6] der Game-Struktur.
 * - Eingaben: this (Game *), k (Slot-Index 0..6), v (zu speichernder 32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->a[k].
 === Ende Beschreibung === */
void Game::f_0de790(short k, int v) { a[k] = v; }
//@ f_0de7a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Anzahl der aktiven Gruppenmitglieder this->b1c (+0x1C) auf v.
 * - Eingaben: this (Game *), v (neue Gruppengröße).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->b1c.
 === Ende Beschreibung === */
void Game::f_0de7a0(signed char v) { b1c = v; }
//@ f_0de7b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 32-Bit-Feld this->l1d (+0x1D, vermutlich den Zeiger auf den aktuellen
 *   Gruppenanführer oder das ausgewählte Gruppenmitglied) auf v.
 * - Eingaben: this (Game *), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->l1d.
 === Ende Beschreibung === */
void Game::f_0de7b0(int v) { l1d = v; }
//@ f_0de7c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob mindestens ein Mitglied in der Gruppe vorhanden ist (this->b1c != 0).
 * - Eingaben: this (Game *).
 * - Rückgabewert: 1, wenn b1c != 0, sonst 0.
 * - Wichtige Variablen: this->b1c.
 === Ende Beschreibung === */
int Game::f_0de7c0() { return b1c != 0; }
//@ f_0de7d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 32-Bit-Eintrag (Heldenzeiger) am Slot-Index k aus dem Array this->a[0..6] der
 *   Game-Struktur aus.
 * - Eingaben: this (Game *), k (Slot-Index 0..6).
 * - Rückgabewert: 32-Bit-Eintrag this->a[k] (int).
 * - Wichtige Variablen: this->a[k].
 === Ende Beschreibung === */
int Game::f_0de7d0(short k) { return a[k]; }
//@ f_0de7e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den 32-Bit-Wert this->l1d (+0x1D) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->l1d (int).
 * - Wichtige Variablen: this->l1d.
 === Ende Beschreibung === */
int Game::f_0de7e0() { return l1d; }
//@ f_0de7f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die aktuelle Gruppengröße this->b1c (+0x1C) als short zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Gruppengröße this->b1c (short).
 * - Wichtige Variablen: this->b1c.
 === Ende Beschreibung === */
short Game::f_0de7f0() { return b1c; }
//@ f_0de800
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Nummer des aktuell betretenen 2D-Gebäudes oder Ortes this->s23 (+0x23, -1 wenn im
 *   Freien oder im Dungeon) zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Aktuelle Ortsnummer this->s23 (short).
 * - Wichtige Variablen: this->s23.
 === Ende Beschreibung === */
short Game::f_0de800() { return s23; }
//@ f_0de810
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Nummer des aktuellen 2D-Gebäudes oder Ortes this->s23 (+0x23) auf v.
 * - Eingaben: this (Game *), v (Ortsnummer oder -1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s23.
 === Ende Beschreibung === */
void Game::f_0de810(short v) { s23 = v; }
//@ f_0de820
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Nummer des aktuellen 3D-Dungeons this->s25 (+0x25, -1 wenn außerhalb eines
 *   Dungeons) zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Aktuelle Dungeon-Nummer this->s25 (short).
 * - Wichtige Variablen: this->s25.
 === Ende Beschreibung === */
short Game::f_0de820() { return s25; }
//@ f_0de830
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Nummer des aktuellen 3D-Dungeons this->s25 (+0x25) auf v.
 * - Eingaben: this (Game *), v (Dungeon-Nummer oder -1).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s25.
 === Ende Beschreibung === */
void Game::f_0de830(short v) { s25 = v; }
//@ f_0de840
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die X-Koordinate (bzw. erste Positionskoordinate) this->i2d (+0x2D) der Heldengruppe
 *   zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i2d (int).
 * - Wichtige Variablen: this->i2d.
 === Ende Beschreibung === */
int Game::f_0de840() { return i2d; }
//@ f_0de850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Koordinate this->i2d (+0x2D) der Heldengruppe auf v.
 * - Eingaben: this (Game *), v (neuer Koordinatenwert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i2d.
 === Ende Beschreibung === */
void Game::f_0de850(int v) { i2d = v; }
//@ f_0de860
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Y-Koordinate (bzw. zweite Positionskoordinate) this->i31 (+0x31) der Heldengruppe
 *   zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i31 (int).
 * - Wichtige Variablen: this->i31.
 === Ende Beschreibung === */
int Game::f_0de860() { return i31; }
//@ f_0de870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Koordinate this->i31 (+0x31) der Heldengruppe auf v.
 * - Eingaben: this (Game *), v (neuer Koordinatenwert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i31.
 === Ende Beschreibung === */
void Game::f_0de870(int v) { i31 = v; }
//@ f_0de880
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 32-Bit-Positions-/Richtungsfeld this->i35 (+0x35) der Heldengruppe zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i35 (int).
 * - Wichtige Variablen: this->i35.
 === Ende Beschreibung === */
int Game::f_0de880() { return i35; }
//@ f_0de890
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 32-Bit-Feld this->i35 (+0x35) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i35.
 === Ende Beschreibung === */
void Game::f_0de890(int v) { i35 = v; }
//@ f_0de8a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 32-Bit-Feld this->i39 (+0x39) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i39 (int).
 * - Wichtige Variablen: this->i39.
 === Ende Beschreibung === */
int Game::f_0de8a0() { return i39; }
//@ f_0de8b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 32-Bit-Feld this->i39 (+0x39) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i39.
 === Ende Beschreibung === */
void Game::f_0de8b0(int v) { i39 = v; }
//@ f_0de8c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld this->s27 (+0x27) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s27 (short).
 * - Wichtige Variablen: this->s27.
 === Ende Beschreibung === */
short Game::f_0de8c0() { return s27; }
//@ f_0de8d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Feld this->s27 (+0x27) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s27.
 === Ende Beschreibung === */
void Game::f_0de8d0(short v) { s27 = v; }
//@ f_0de8e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld this->s29 (+0x29) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s29 (short).
 * - Wichtige Variablen: this->s29.
 === Ende Beschreibung === */
short Game::f_0de8e0() { return s29; }
//@ f_0de8f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Feld this->s29 (+0x29) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s29.
 === Ende Beschreibung === */
void Game::f_0de8f0(short v) { s29 = v; }
//@ f_0de900
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld this->s2b (+0x2B) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s2b (short).
 * - Wichtige Variablen: this->s2b.
 === Ende Beschreibung === */
short Game::f_0de900() { return s2b; }
//@ f_0de910
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Feld this->s2b (+0x2B) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s2b.
 === Ende Beschreibung === */
void Game::f_0de910(short v) { s2b = v; }
//@ f_0de920
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld this->s3d (+0x3D) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s3d (short).
 * - Wichtige Variablen: this->s3d.
 === Ende Beschreibung === */
short Game::f_0de920() { return s3d; }
//@ f_0de930
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Feld this->s3d (+0x3D) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s3d.
 === Ende Beschreibung === */
void Game::f_0de930(short v) { s3d = v; }
//@ f_0de940
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Zonen-/Kollisionsfeld this->s3f (+0x3F) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s3f.
 === Ende Beschreibung === */
void Game::f_0de940(short v) { s3f = v; }
//@ f_0de950
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Zonen-/Kollisionsfeld this->s3f (+0x3F) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s3f (short).
 * - Wichtige Variablen: this->s3f.
 === Ende Beschreibung === */
short Game::f_0de950() { return s3f; }
//@ f_0de960
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 32-Bit-Feld this->i41 (+0x41) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i41.
 === Ende Beschreibung === */
void Game::f_0de960(int v) { i41 = v; }
//@ f_0de970
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 32-Bit-Feld this->i41 (+0x41) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i41 (int).
 * - Wichtige Variablen: this->i41.
 === Ende Beschreibung === */
int Game::f_0de970() { return i41; }
//@ f_0de980
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 32-Bit-Feld this->i45 (+0x45, Gruppenvermögen in Heller) der Game-Struktur
 *   zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->i45 (int).
 * - Wichtige Variablen: this->i45.
 === Ende Beschreibung === */
int Game::f_0de980() { return i45; }
//@ f_0de990
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 32-Bit-Feld this->i45 (+0x45, Gruppenvermögen in Heller) der Game-Struktur auf
 *   v.
 * - Eingaben: this (Game *), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->i45.
 === Ende Beschreibung === */
void Game::f_0de990(int v) { i45 = v; }
//@ f_0de9a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld this->s21 (+0x21) der Game-Struktur zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->s21 (short).
 * - Wichtige Variablen: this->s21.
 === Ende Beschreibung === */
short Game::f_0de9a0() { return s21; }
//@ f_0de9b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das 16-Bit-Feld this->s21 (+0x21) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (16-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->s21.
 === Ende Beschreibung === */
void Game::f_0de9b0(short v) { s21 = v; }
//@ f_0de9c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das vorzeichenbehaftete Bytefeld this->c49 (+0x49) der Game-Struktur als int zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->c49 (int).
 * - Wichtige Variablen: this->c49.
 === Ende Beschreibung === */
int Game::f_0de9c0() { return c49; }
//@ f_0de9d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Bytefeld this->c49 (+0x49) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (signed char).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->c49.
 === Ende Beschreibung === */
void Game::f_0de9d0(signed char v) { c49 = v; }
//@ f_0de9e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das vorzeichenbehaftete Bytefeld this->c4a (+0x4A) der Game-Struktur als short
 *   zurück.
 * - Eingaben: this (Game *).
 * - Rückgabewert: Wert von this->c4a (short).
 * - Wichtige Variablen: this->c4a.
 === Ende Beschreibung === */
short Game::f_0de9e0() { return c4a; }
//@ f_0de9f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Bytefeld this->c4a (+0x4A) der Game-Struktur auf v.
 * - Eingaben: this (Game *), v (signed char).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: this->c4a.
 === Ende Beschreibung === */
void Game::f_0de9f0(signed char v) { c4a = v; }

