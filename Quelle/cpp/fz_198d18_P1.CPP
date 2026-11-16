/* === Beschreibung (Katalog) ===
 * Einheit fz_198d18 (0x198d18 - 0x198d23)
 *
 * Überblick
 * Diese kleine Einheit enthält zwei kurze Hilfsfunktionen (f_198d18 und f_198d1e) zum Abfragen einer globalen
 * Statusvariable (d_1a9e64) und zum Weiterleiten eines Aufrufs an f_1995b9.
 === Ende Beschreibung === */
// OPT -5r -oneax -zp1 -s -nt=_TEXT3
// P1 2/2 gleich
// CC wcc386
extern int d_1a9e64;
void f_1995b9(void);
#pragma aux f_198d18 "*";
#pragma aux f_198d1e "*";
#pragma aux f_1995b9 "*";
//@ f_198d18
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198d18
 * - Aufgabe im Spiel: Gibt den aktuellen Wert der globalen 32-Bit-Statusvariable d_1a9e64 zurück.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Der Wert von d_1a9e64.
 * - Wichtige Variablen:
 *   - Globale Variable d_1a9e64.
 === Ende Beschreibung === */
int f_198d18(void)
{
    return d_1a9e64;
}
//@ f_198d1e
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x198d1e
 * - Aufgabe im Spiel: Leitet den Aufruf direkt an die Funktion f_1995b9 weiter.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_198d1e(void)
{
    f_1995b9();
}
