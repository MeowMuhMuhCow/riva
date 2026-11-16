/* === Beschreibung (Katalog) ===
 * Einheit fz_14d0d7 (0x14D0D7 - 0x14D0E4)
 *
 * Überblick
 * Diese kleine Laufzeit-Einheit enthält einen einzeiligen Wrapper (f_14d0d7) zum Öffnen einer Datei oder eines
 * Streams über die C-Laufzeitfunktion f_144fbf mit dem festen Moduscode 0x62 ('b').
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s
// P1 1/1 gleich
// CC wcc386
int f_144fbf(const char *a, int b, ...);
//@ f_14d0d7
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet bzw. initialisiert einen Dateistream über die interne Laufzeitfunktion f_144fbf(a,
 *   0x62, b).
 * - Eingaben:
 *   - a: Erster Parameter (Dateiname oder Stream-Deskriptor).
 *   - b: Zweiter Parameter (Zugriffsmodus/Kontext).
 * - Rückgabewert: Rückgabewert von f_144fbf.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
#pragma aux f_14d0d7 "*";
int f_14d0d7(const char *a, int b)
{
    return f_144fbf(a, 0x62, b);
}
