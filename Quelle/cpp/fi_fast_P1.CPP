/* === Beschreibung (Katalog) ===
 * Einheit fi_fast (0x072610 - 0x0727E0)
 *
 * Überblick
 * Die Einheit fi_fast implementiert eine schnelle Erreichbarkeitsprüfung (Breitensuche / Flood-Fill) auf dem
 * 24x24-Kampfgitter (f_072610), mit der geprüft wird, ob von einem Startfeld (x, y) aus innerhalb von höchstens
 * 50 Schritten ein als Zielfeld (0xcb) markiertes Kampffeld erreichbar ist.
 === Ende Beschreibung === */
// I9: aus fi_fast.VT uebernommen (Stufe-2-Stand), Marken 1 neu
// fi_fast.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 3
// Code 0x072610-0x0727E0. Kampf: Breitensuche ab (x,y) im 24x24-Gitter (Zeilenlänge 25), bis ein Zielfeld (0xCB) erreicht ist.
#include <string.h>
extern const char d_1a1c58[];
#define fi_fast_file d_1a1c58
void *f_014540(long size, const char *file, int line);   // Speicher mit Herkunft
void operator delete(void *p);                           // 0x014710
struct Dir { short dx, dy; };
struct Dirs1064 { Dir d[4]; };
extern const Dirs1064 d_1a1c78;
extern unsigned char (*d_1bd984)[25];
//@ f_072610
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt auf dem 24x24-Kampfgitter d_1bd984 (Zeilenbreite 25 Bytes) ausgehend von (x, y) eine
 *   schrittweise Breitensuche in den vier Hauptrichtungen d_1a1c78 über maximal 50 Schritte aus: Freie Felder
 *   (terrain == 0) werden mit der aktuellen Schrittzahl step markiert, blockierte Felder (0xfe oder >= 50) mit
 *   0xcc gesperrt, und beim Auftreffen auf ein Zielfeld (terrain == 0xcb) bricht die Suche sofort erfolgreich
 *   mit found = 1 ab.
 * - Eingaben:
 *   - who (Unbenutzter Zeiger auf die Kampfeinheit).
 *   - x (Start-Spalte 0..23 auf dem Kampfgitter).
 *   - y (Start-Zeile 0..23 auf dem Kampfgitter).
 * - Rückgabewert: int - 1, wenn ein mit 0xcb markiertes Zielfeld über freie Felder erreichbar ist, sonst 0.
 * - Wichtige Variablen:
 *   - buf (Dynamisch angelegtes 24x25-Byte-Distanzgitter, vorab mit 0xff initialisiert).
 *   - d_1bd984 (Globales 24x25-Kampffeldgitter mit Terrain- und Belegungskennungen).
 *   - step (Aktuelle Wellenfront-Distanz 1..50).
 *   - changed (Flag, ob im aktuellen Schritt mindestens ein neues freies Feld erreicht wurde).
 *   - found (Erfolgsflag 1 bei Erreichen von 0xcb).
 === Ende Beschreibung === */
int f_072610(void *who, short x, short y)
{
    short step = 0;
    short changed = 0;
    int found = 0;
    short row;
    short col;
    short ny;
    short d;
    char value;
    char terrain;
    short nx;
    Dirs1064 dirs1064 = d_1a1c78;
    unsigned char (*buf)[25] = (unsigned char (*)[25])f_014540(600, fi_fast_file, 457);

    changed = 1;
    memset(buf, 0xff, 600);
    buf[y][x] = 0;
    while (found == 0 && changed != (short)0 && step < 50) {
        changed = 0;
        step++;
        for (row = 0; row < (short)24; row++) {
            if (found != 0)
                break;
            for (col = 0; col < 24 && found == 0; col++) {
                if (buf[row][col] == (unsigned char)(step-1)) {
                    for (d = 0; d < 4; d++) {
                        ny = row + dirs1064.d[d].dy;
                        nx = col + dirs1064.d[d].dx;
                        if (ny < (short)24 && ny >= 0 && nx < 24 && nx >= 0) {
                            value = buf[ny][nx];
                            terrain = d_1bd984[ny][nx];
                            if (value == (char)0xff) {
                                if ((unsigned char)terrain == 0) {
                                    buf[ny][nx] = (unsigned char)step;
                                    changed = 1;
                                } else if (terrain == (char)0xfe) {
                                    buf[ny][nx] = 0xcc;
                                } else if (terrain == (char)0xcb) {
                                    found = 1;
                                    break;
                                } else if ((unsigned char)terrain >= 50) {
                                    buf[ny][nx] = 0xcc;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    delete buf;
    return found;
}
