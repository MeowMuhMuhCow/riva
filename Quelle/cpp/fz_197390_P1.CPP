/* === Beschreibung (Katalog) ===
 * Einheit fz_197390 (0x197390 - 0x19749b)
 *
 * Überblick
 * Diese Einheit implementiert die drei zentralen BRender-Diagnose- und Fehlerbehandlungsfunktionen (BrFailure,
 * BrWarning, BrFatal), die formatierte Fehlermeldungen in einen globalen Textpuffer (d_1d4cb4) schreiben und
 * anschließend den aktiven Diagnose-Callback (d_1d49a8) aufrufen.
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -nt=_TEXT3
// P1 3/3 gleich
// CC wcc386
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
struct diag { char *id; void (*warning)(char *); void (*failure)(char *); };
extern struct diag *d_1d49a8;
extern char d_1d4cb4[];
extern const char d_1b525b[];
extern const char d_1b5263[];
extern const char d_1ba8c4[];
#pragma aux f_197390 "*";
#pragma aux f_1973ec "*";
#pragma aux f_197448 "*";
//@ f_197390
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197390
 * - Aufgabe im Spiel: Formatiert eine tödliche Laufzeit-Fehlermeldung (BrFailure): Sie kopiert das 7 Zeichen
 *   lange Präfix d_1b525b in den globalen Puffer d_1d4cb4, hängt die mit vsprintf formatierte Meldung an
 *   (d_1d4cb4 + 7) und ruft damit die failure-Methode des aktiven Diagnose-Handlers (d_1d49a8->failure) auf.
 * - Eingaben: Format-String (s) und variable Argumentliste (...).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globaler Meldungspuffer d_1d4cb4, Präfix-String d_1b525b und Diagnose-Handler-Zeiger d_1d49a8.
 === Ende Beschreibung === */
void f_197390(char *s, ...)
{
    va_list args;
    strcpy(d_1d4cb4, d_1b525b);
    va_start(args, s);
    vsprintf(d_1d4cb4 + 7, s, args);
    va_end(args);
    d_1d49a8->failure(d_1d4cb4);
}
//@ f_1973ec
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x1973ec
 * - Aufgabe im Spiel: Formatiert eine nicht-tödliche Warnmeldung (BrWarning): Sie schreibt das 9 Zeichen lange
 *   Präfix d_1b5263 in den globalen Puffer d_1d4cb4, formatiert den Meldungstext samt variablen Argumenten per
 *   vsprintf dahinter (d_1d4cb4 + 9) und übergibt den Puffer an die warning-Methode des Diagnose-Handlers
 *   (d_1d49a8->warning).
 * - Eingaben: Format-String (s) und variable Argumentliste (...).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globaler Meldungspuffer d_1d4cb4, Warnungs-Präfix d_1b5263 und Diagnose-Handler-Zeiger d_1d49a8.
 === Ende Beschreibung === */
void f_1973ec(char *s, ...)
{
    va_list args;
    strcpy(d_1d4cb4, d_1b5263);
    va_start(args, s);
    vsprintf(d_1d4cb4 + 9, s, args);
    va_end(args);
    d_1d49a8->warning(d_1d4cb4);
}
//@ f_197448
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x197448
 * - Aufgabe im Spiel: Formatiert einen internen Assertions- oder Quellcode-Abbruchfehler (BrFatal) unter Angabe
 *   von Quelldateiname (name) und Zeilennummer (line): Zuerst wird über sprintf der Ortskopf mit dem Format
 *   d_1ba8c4 nach d_1d4cb4 geschrieben, danach die eigentliche Fehlermeldung per vsprintf angehängt und
 *   schließlich d_1d49a8->failure(d_1d4cb4) aufgerufen.
 * - Eingaben: Quelldateiname (name), Zeilennummer (line), Format-String (s) und variable Argumente (...).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globaler Meldungspuffer d_1d4cb4, Ortsformat-String d_1ba8c4 und Diagnose-Handler-Zeiger d_1d49a8.
 === Ende Beschreibung === */
void f_197448(char *name, int line, char *s, ...)
{
    va_list args;
    int n;
    n = sprintf(d_1d4cb4, d_1ba8c4, name, line);
    va_start(args, s);
    vsprintf(d_1d4cb4 + n, s, args);
    va_end(args);
    d_1d49a8->failure(d_1d4cb4);
}
