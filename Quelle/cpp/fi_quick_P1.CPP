/* === Beschreibung (Katalog) ===
 * Einheit fi_quick (0x085CD0 - 0x085D60)
 *
 * Überblick
 * Die Einheit fi_quick enthält eine schnelle Nachbarschaftsprüfung auf dem 24x24-Kampfgitter (f_085cd0), die
 * feststellt, ob alle orthogonal angrenzenden Nachbarfelder eines Kampffeldes (x, y) belegt bzw. blockiert sind.
 === Ende Beschreibung === */
// P3 1/1 gleich (suche.py 25.10.2026, Basis fi_quick_P1.CPP)
// I9: aus fi_quick.VT uebernommen (Stufe-2-Stand), Marken 1 neu
// fi_quick.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle
// Code 0x085CD0-0x085D60. Kampf: Ist um (x,y) ein Nachbarfeld frei? Gitter 24x24, Zeilenl?nge 25.
struct Dir { short dx, dy; };
struct Dir4 { Dir d[4]; };
extern Dir4 d_1a21e8;   // Initialisierungsbild {{-1,0},{0,1},{1,0},{0,-1}} liegt im Original
extern char (*d_1bd984)[25];
//@ f_085cd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft auf dem 24x24-Kampfgitter d_1bd984 die vier orthogonalen Nachbarfelder (d_1a21e8:
 *   links, unten, rechts, oben) der Koordinate (x, y). Sobald eines der innerhalb des Gitters liegenden
 *   Nachbarfelder frei ist (d_1bd984[ny][nx] == 0), bricht die Schleife ab und liefert 0; nur wenn kein einziges
 *   Nachbarfeld frei ist, wird 1 zurückgegeben.
 * - Eingaben:
 *   - x (Spaltenkoordinate 0..23 auf dem Kampfgitter).
 *   - y (Zeilenkoordinate 0..23 auf dem Kampfgitter).
 * - Rückgabewert: int - 0, wenn mindestens ein direktes Nachbarfeld frei (0) ist; 1, wenn alle gültigen
 *   Nachbarfelder belegt oder unpassierbar sind.
 * - Wichtige Variablen:
 *   - dir (Kopie der vier Richtungsvektoren {{-1,0}, {0,1}, {1,0}, {0,-1}} aus d_1a21e8).
 *   - nx, ny (Koordinaten des geprüften Nachbarfeldes).
 *   - ok (Ergebnisflag: 1 = kein freies Nachbarfeld, 0 = freies Nachbarfeld gefunden).
 === Ende Beschreibung === */
int f_085cd0(short x, short y)
{
    short i;
    int ok = 1;
    Dir4 dir = d_1a21e8;
    for (i = 0; i < 4; i++) {
        short ny = y + dir.d[i].dy;
        short nx = x + dir.d[i].dx;
        if (ny < (short)24 && ny >= 0 && nx < (unsigned short)24 && nx >= 0) {
            char c = d_1bd984[ny][nx];
            if (c == (signed char)0) {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}
