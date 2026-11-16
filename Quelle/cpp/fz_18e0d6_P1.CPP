/* === Beschreibung (Katalog) ===
 * Einheit fz_18e0d6 (0x18e0d6 - 0x18e0e6)
 *
 * Überblick
 * Diese Einheit enthält die Standard-C-Laufzeitfunktion fflush (f_18e0d6) der Watcom-Laufzeitbibliothek, die
 * wahlweise einen einzelnen gepufferten Ausgabestrom oder bei Übergabe von NULL alle offenen Ausgabeströme
 * leert.
 === Ende Beschreibung === */
// P1 0/1 gleich (1 ASM)
// f_18e0d6 ASM
//@ f_18e0d6
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e0d6
 * - Aufgabe im Spiel: Prüft, ob ein konkreter Dateistrom-Zeiger (p1 != 0) übergeben wurde; in diesem Fall wird
 *   der Puffer dieses einen Stroms über f_179338 geschrieben. Wird hingegen 0 (NULL) übergeben, leert die
 *   Funktion über f_15f307 sämtliche offenen Ausgabeströme des Programms und gibt 0 zurück.
 * - Eingaben: Der Zeiger auf die Dateistrom-Struktur (p1) oder 0 für alle offenen Ströme.
 * - Rückgabewert: Der Rückgabewert von f_179338(p1) bzw. 0, wenn p1 == 0 war.
 * - Wichtige Variablen: Keine lokalen oder globalen Variablen außerhalb des Parameters p1.
 === Ende Beschreibung === */
extern int f_179338(int);
extern void f_15f307(void);
#pragma aux f_179338 "*";
#pragma aux f_15f307 "*";
int f_18e0d6(int p1)
{
    if (p1)
        return f_179338(p1);
    f_15f307();
    return 0;
}
