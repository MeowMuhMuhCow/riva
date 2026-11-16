/* === Beschreibung (Katalog) ===
 * Einheit fz_144f88 (0x144F88 - 0x144FBF)
 *
 * Überblick
 * Diese kleine Laufzeit-Hilfseinheit enthält zwei Fehlerbehandlungsroutinen der C/C++-Laufzeitbibliothek
 * (insbesondere für einen reinen virtuellen Funktionsaufruf bzw. eine fehlgeschlagene Laufzeitprüfung), die
 * jeweils eine Fehlermeldung ausgeben und vor Mehrfachaufrufen geschützt sind.
 === Ende Beschreibung === */
// OPT -3r -oneax -zp1 -s
// P3 1/2 gleich (suche.py 24.10.2026, Basis fz_144f88_P1.CPP)
// fz_144f88.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x144F88-0x144FBF
int f_16657c(const char *p1, int p2);
extern unsigned short d_1a9dc4;
extern const char d_1b8904[];
extern const char d_1b8930[];
#pragma aux f_144f88 "*";
#pragma aux f_144f9a "*";
//@ f_144f88
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt im Fehlerfall eine feste Laufzeit-Fehlermeldung (d_1b8904, z. B. bei einem
 *   unzulässigen Aufruf einer rein virtuellen Funktion) über die Ausgaberoutine f_16657c aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Rückgabewert von f_16657c.
 * - Wichtige Variablen:
 *   - d_1b8904: Zeiger auf die auszugebende Fehlermeldungszeichenkette.
 === Ende Beschreibung === */
void f_144f88(void)
{
    f_16657c(d_1b8904, 1);
}
//@ f_144f9a
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Behandelt einen kritischen Laufzeitfehler, indem beim ersten Auftreten (d_1a9dc4 == 0) das
 *   Schutzflag d_1a9dc4 auf 1 gesetzt, eine Aufräumroutine (f_154bc0) aufgerufen und anschließend die
 *   Fehlermeldung d_1b8930 über f_16657c ausgegeben wird. Dadurch wird eine Endlosschleife bei rekursiven
 *   Fehlern verhindert.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Rückgabewert von f_16657c (bzw. unbestimmt, falls bereits zuvor ausgelöst).
 * - Wichtige Variablen:
 *   - d_1a9dc4: Statisches Schutzflag, das sicherstellt, dass die Fehlerbehandlung nur einmal durchlaufen wird.
 *   - d_1b8930: Zeiger auf die Fehlermeldungszeichenkette.
 === Ende Beschreibung === */
void f_144f9a(void)
{
    if (d_1a9dc4 == (unsigned short)0) {
        d_1a9dc4 = (unsigned short)1;
        f_16657c(d_1b8930, 1);
    }
}
