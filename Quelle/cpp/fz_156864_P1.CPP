/* === Beschreibung (Katalog) ===
 * Einheit fz_156864 (0x156864 - 0x156870)
 *
 * Überblick
 * Diese kleine C-Einheit enthält zwei kurze Weiterleitungsfunktionen (f_156864 und f_156869), die ohne eigene
 * Parameter direkt in die Laufzeit- beziehungsweise Grafik-Hilfsfunktionen f_1785e2 und f_178767 verzweigen.
 === Ende Beschreibung === */
// OPT -5r -oneax -zp1 -s
// P1 2/2 gleich
// CC wcc386
// fz_156864.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x156864-0x156870
void f_1785e2(void);
void f_178767(void);
#pragma aux f_156864 "*";
#pragma aux f_156869 "*";
#pragma aux f_1785e2 "*";
#pragma aux f_178767 "*";
//@ f_156864
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft unmittelbar die nachgelagerte Laufzeit- oder Treiberroutine f_1785e2 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_156864(void)
{
    f_1785e2();
}
//@ f_156869
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft unmittelbar die nachgelagerte Laufzeit- oder Treiberroutine f_178767 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_156869(void)
{
    f_178767();
}
