/* === Beschreibung (Katalog) ===
 * Einheit fz_199410 (0x199410 - 0x1994e5)
 *
 * Überblick
 * Diese Einheit verwaltet den globalen temporären Arbeitsspeicher (Scratchpad-Allocator: BrScratchAllocate,
 * BrScratchFree, BrScratchFlush, BrScratchInquire) sowie den qsort-Wrapper (BrQsort / f_1994e0) der
 * BRender-Engine, der unter anderem bei der 3D-Mesh-Vorbereitung (fz_197510) intensiv genutzt wird.
 === Ende Beschreibung === */
// P1 4/4 gleich
// CC wcc386
void f_197390(char *, ...);
int f_188404(int p1, int p2, int p3);
void f_18850c(int p1);
int f_1885c8(int p1);
extern int d_1d49b0;
extern int d_1d49e4;
extern unsigned d_1d49e8;
extern int d_1d49ec;
extern int d_1d49f0;
extern const char d_1ba960[];
extern const char d_1ba97c[];
#pragma aux f_199410 "*";
#pragma aux f_199484 "*";
#pragma aux f_199490 "*";
#pragma aux f_1994cc "*";
typedef int (*CMP494)(const void *, const void *);
void f_14d7dc(void *, unsigned, unsigned, CMP494);
#pragma aux f_14d7dc "*";
#pragma aux f_1994e0 "*";
//@ f_199410
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x199410
 * - Aufgabe im Spiel: Stellt den globalen BRender-Scratchpad-Puffer (d_1d49e4) mit mindestens size Bytes bereit
 *   (BrScratchAllocate). Ist das Scratchpad bereits als belegt markiert (d_1d49f0 != 0), bricht die Funktion mit
 *   einer Fehlermeldung (f_197390, Text d_1ba960) ab; reicht der bisherige Puffer (d_1d49e8) nicht aus, wird er
 *   freigegeben (f_18850c) und in der neuen Größe neu alloziert (f_188404).
 * - Eingaben: Die angeforderte Puffergröße size in Bytes.
 * - Rückgabewert: Der Zeiger (d_1d49e4) auf den bereitgestellten Scratchpad-Speicherblock.
 * - Wichtige Variablen:
 *   - Globale Scratchpad-Variablen: Pufferzeiger d_1d49e4, tatsächliche Blockgröße d_1d49e8, zuletzt
 *     angeforderte Größe d_1d49ec und Belegungs-Flag d_1d49f0.
 === Ende Beschreibung === */
int f_199410(unsigned size)
{
    if (d_1d49f0) f_197390((char *)d_1ba960);
    d_1d49ec = size;
    if (size > d_1d49e8) {
        if (d_1d49e4) f_18850c(d_1d49e4);
        d_1d49e4 = f_188404(d_1d49b0, size, 1);
        d_1d49e8 = f_1885c8(d_1d49e4);
    }
    d_1d49f0 = 1;
    return d_1d49e4;
}
//@ f_199484
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x199484
 * - Aufgabe im Spiel: Gibt das globale Scratchpad nach der Benutzung wieder zur erneuten Verwendung frei
 *   (BrScratchFree), indem das Belegungs-Flag d_1d49f0 auf 0 zurückgesetzt wird (der Speicherblock selbst bleibt
 *   für spätere Anforderungen gecacht).
 * - Eingaben: Der Zeiger auf den Scratchpad-Block (p, wird intern nicht benötigt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globales Belegungs-Flag d_1d49f0.
 === Ende Beschreibung === */
void f_199484(int p)
{
    d_1d49f0 = 0;
}
//@ f_199490
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x199490
 * - Aufgabe im Spiel: Gibt den gecachten Scratchpad-Speicherblock (d_1d49e4) vollständig an den
 *   Ressourcen-Allokator zurück (BrScratchFlush) und setzt Zeiger und Größe (d_1d49e8) auf 0. Ist das Scratchpad
 *   zum Zeitpunkt des Aufrufs noch in Benutzung (d_1d49f0 != 0), wird zuvor ein tödlicher Fehler (f_197390, Text
 *   d_1ba97c) ausgelöst.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Scratchpad-Variablen d_1d49f0, d_1d49e4 und d_1d49e8.
 === Ende Beschreibung === */
void f_199490(void)
{
    if (d_1d49f0) f_197390((char *)d_1ba97c);
    if (d_1d49e4) f_18850c(d_1d49e4);
    d_1d49e4 = 0;
    d_1d49e8 = 0;
}
//@ f_1994cc
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1994cc
 * - Aufgabe im Spiel: Gibt die aktuell alloziierte Größe (d_1d49e8) des globalen Scratchpad-Puffers in Bytes
 *   zurück (BrScratchInquire).
 * - Eingaben: Keine (void).
 * - Rückgabewert: Die Puffergröße d_1d49e8 in Bytes.
 * - Wichtige Variablen:
 *   - Globale Größenangabe d_1d49e8.
 === Ende Beschreibung === */
int f_1994cc(void)
{
    return d_1d49e8;
}

//@ f_1994e0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1994e0
 * - Aufgabe im Spiel: Sortiert ein Array (base) mit count Elementen der Größe size mithilfe der
 *   Vergleichsfunktion cmp, indem direkt die C-Bibliotheksfunktion qsort (f_14d7dc) aufgerufen wird (BrQsort).
 * - Eingaben: Basiszeiger des Arrays (base), Elementanzahl (count), Elementgröße in Bytes (size) und Zeiger auf
 *   die Vergleichsfunktion (cmp).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1994e0(void *base, unsigned count, unsigned size, CMP494 cmp)
{
    f_14d7dc(base, count, size, cmp);
}
