/* === Beschreibung (Katalog) ===
 * Einheit fz_149cf0 (0x149CF0 - 0x149CF5)
 *
 * Überblick
 * Diese winzige Einheit enthält lediglich eine kurze Weiterleitungsfunktion (f_149cf0) auf die
 * Laufzeit-Wartefunktion f_16aafb (delay).
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s
// P1 1/1 gleich
// CC wcc386
void f_16aafb(int a);
//@ f_149cf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Pausiert die Programmausführung für die in ms angegebene Zeitspanne durch Weiterleitung an
 *   die Laufzeitfunktion f_16aafb.
 * - Eingaben: ms (Wartezeit als unsigned int).
 * - Rückgabewert: Rückgabewert von f_16aafb.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
#pragma aux f_149cf0 "*";
void f_149cf0(int a)
{
    f_16aafb(a);
}
