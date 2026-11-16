/* === Beschreibung (Katalog) ===
 * Einheit fz_17b3c0 (0x17b3c0 - 0x17b500)
 *
 * Überblick
 * Diese Einheit enthält die Basisinitialisierung und das Herunterfahren des globalen BRender-Laufzeitsystems
 * (BrBegin / BrEnd bzw. die zugehörige Ressourcen-, Speicher- und Diagnose-Initialisierung) sowie drei
 * Hilfsfunktionen zum Austauschen der globalen Handler-Zeiger für Diagnose, Dateisystem und Speicherverwaltung.
 === Ende Beschreibung === */
// OPT -5r -onetx -zp1 -s -fp5
// CC wcc386
// fz_17b3c0.c (Schatten ueber Riva, Attic 1996) - abgetrennt aus fz_17a940 (08.11. Claude I15): Code 0x17B3C0-0x17B500; Original hat Linker-Nullen 0x17B3B5-0x17B3BF = Modulgrenze
#include <string.h>
int f_14d5c9(int p1);
int f_187bdc(int p1);
int f_188404(int p1, int p2, int p3);
int f_18850c(int p1);
int f_18eebb(void);
int f_18f228(int p1);
int f_15e469(char *p1, const char *p2);
char f_1794a7(int p1);
int f_145318(char *p1, const char *p2);
int f_15e836(int p1);
int f_14572e(char *p1, const char *p2, ...);
#pragma aux f_14d5c9 "*";
#pragma aux f_187bdc "*";
#pragma aux f_188404 "*";
#pragma aux f_18850c "*";
#pragma aux f_18eebb "*";
#pragma aux f_18f228 "*";
#pragma aux f_15e469 "*";
#pragma aux f_1794a7 "*";
#pragma aux f_145318 "*";
#pragma aux f_15e836 "*";
#pragma aux f_17b140 "*";
#pragma aux f_17b260 "*";
#pragma aux f_17b3c0 "*";
#pragma aux f_17b4b8 "*";
#pragma aux f_17b4d0 "*";
#pragma aux f_17b4e0 "*";
#pragma aux f_17b4f0 "*";
extern int d_1af3c0;
extern int d_1b4524;
extern int d_1b4954;
extern int d_1b498c;
extern int d_1b49a0;
extern unsigned char d_1b4e08;
extern char d_1ba070[];
extern char d_1ba078[];
extern char d_1b9ff0[];
extern char d_1ba080[];
extern char d_1ba0a8[];
extern char d_1c76f8[];
extern char d_1ccf88[];
extern int d_1a996c;
extern char *d_1cdb90;
extern char d_1cd0b0[];
extern int d_1d452c;
extern int d_1d4540;
extern int d_1d4554;
extern int d_1d4568;
extern int d_1d457c;
extern int d_1d45d8;
extern int d_1d45e8;
extern int d_1d49a0;
extern int d_1d49a4;
extern int d_1d49a8;
extern int d_1d49ac;
extern int d_1d49b0;
extern int d_1d49b4;
extern int d_1d49b8;
extern int d_1af288[];
extern int d_1b4d1c[];
extern int d_1b4dc4[];
struct S116 { int a[29]; };

extern char d_1b9fe8[], d_1b9ff4[], d_1b9ff8[], d_1ba000[], d_1ba008[];
extern int d_1a9a4c, d_1a9a54, d_1a9a58;
extern int d_1a9a50;
int strcmp494(const char *,const char *);
#pragma aux strcmp494 "f_144bf0" modify exact [eax];
#pragma aux f_1794a7 modify exact [eax];
#pragma aux f_145318 modify exact [eax edx];
#pragma aux f_17a940 "*";
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_17b3c0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b3c0
 * - Aufgabe im Spiel: Initialisiert den globalen BRender-Systemzustand: Sie setzt die Standard-Handler für
 *   Diagnose (d_1d49a8), Dateisystem (d_1d49a0) und Speicherallokator (d_1d49a4), registriert fünf interne
 *   Ressourcenlisten (d_1d452c bis d_1d457c), legt die Wurzelressource (d_1d49b0) an, registriert alle 26
 *   internen BRender-Ressourcenklassen in einer Schleife über d_1af288 und kopiert die
 *   Standard-Systemkonfiguration (d_1b4d1c) in einen neu allozierten Zustandsblock (d_1d49b4).
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Handler-Zeiger d_1d49a8 (Diagnose), d_1d49a0 (Dateisystem) und d_1d49a4 (Speicher): Werden mit den
 *     statischen Standardstrukturen (d_1b4954, d_1b498c, d_1b49a0) vorbelegt.
 *   - Globale Wurzelressource d_1d49b0 und Systemzustandsblock d_1d49b4: Halten die zentrale
 *     Ressourcen-Hierarchie der 3D-Engine.
 *   - Globales Tabellen-Array d_1af288: Enthält 26 Einträge zu je 12 Bytes für die BRender-Ressourcenklassen,
 *     die über f_18f228 registriert werden.
 === Ende Beschreibung === */
void f_17b3c0(void)
{
    int p;
    int q;
    int e;
    int *r;
    unsigned char *cp;

    d_1d49a8 = d_1b4954;
    d_1d49a0 = d_1b498c;
    d_1d49a4 = d_1b49a0;
    d_1b4524 = f_18eebb() & 0xffff;
    d_1d49ac = 0;
    f_187bdc((int)&d_1d452c);
    f_187bdc((int)&d_1d4540);
    f_187bdc((int)&d_1d4554);
    f_187bdc((int)&d_1d4568);
    f_187bdc((int)&d_1d457c);
    d_1d45d8 = (int)d_1af288;
    d_1d45e8 = (int)(d_1af288 + 3);
    d_1d49b0 = f_188404(0, 0, 0x16);
    p = (int)d_1af288;
    e = p + 0x138;
    do {
        f_18f228(p);
        p += 0xc;
    } while (p != e);
    r = (int *)f_188404(d_1d49b0, 0x74, 7);
    d_1d49b4 = (int)r;
    *(struct S116 *)r = *(struct S116 *)d_1b4d1c;
    *((unsigned char *)r + 0x68) |= 4;
    d_1d49b8 = (int)d_1b4dc4;
    d_1b4e08 |= 4;
}
//@ f_17b4b8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b4b8
 * - Aufgabe im Spiel: Gibt beim Beenden des 3D-Subsystems die gesamte BRender-Wurzelressource (d_1d49b0) samt
 *   aller darunter hängenden Kind-Ressourcen über f_18850c frei und setzt den Wurzelzeiger auf 0 zurück.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Wurzelressource d_1d49b0: Wird freigegeben und genullt.
 === Ende Beschreibung === */
void f_17b4b8(void)
{
    f_18850c(d_1d49b0);
    d_1d49b0 = 0;
}
//@ f_17b4d0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b4d0
 * - Aufgabe im Spiel: Ersetzt den globalen BRender-Diagnose-/Fehlerbehandlungs-Zeiger (d_1d49a8) durch einen
 *   neuen Handler und gibt den zuvor eingetragenen Zeiger zurück.
 * - Eingaben: Der Zeiger auf die neue Diagnose-Handler-Struktur.
 * - Rückgabewert: Der bisherige Diagnose-Handler-Zeiger (d_1d49a8).
 * - Wichtige Variablen:
 *   - Globaler Diagnose-Zeiger d_1d49a8: Speichert die aktive Fehler- und Warnungs-Callback-Struktur.
 === Ende Beschreibung === */
int f_17b4d0(int p)
{
    int o;
    o = d_1d49a8;
    d_1d49a8 = p;
    return o;
}
//@ f_17b4e0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b4e0
 * - Aufgabe im Spiel: Ersetzt den globalen BRender-Dateisystem-Handler (d_1d49a0) durch einen neuen Handler und
 *   gibt den vorherigen Zeiger zurück.
 * - Eingaben: Der Zeiger auf die neue Dateisystem-Handler-Struktur.
 * - Rückgabewert: Der bisherige Dateisystem-Handler-Zeiger (d_1d49a0).
 * - Wichtige Variablen:
 *   - Globaler Dateisystem-Zeiger d_1d49a0: Bestimmt die Funktionen zum Öffnen, Lesen und Schließen von
 *     BRender-Dateien.
 === Ende Beschreibung === */
int f_17b4e0(int p)
{
    int o;
    o = d_1d49a0;
    d_1d49a0 = p;
    return o;
}
//@ f_17b4f0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x17b4f0
 * - Aufgabe im Spiel: Ersetzt den globalen BRender-Speicherallokator-Handler (d_1d49a4) durch einen neuen
 *   Handler und gibt den vorherigen Zeiger zurück.
 * - Eingaben: Der Zeiger auf die neue Speicherallokator-Struktur.
 * - Rückgabewert: Der bisherige Speicherallokator-Zeiger (d_1d49a4).
 * - Wichtige Variablen:
 *   - Globaler Allokator-Zeiger d_1d49a4: Bestimmt die Callback-Funktionen für Speicheranforderung und Freigabe
 *     innerhalb von BRender.
 === Ende Beschreibung === */
int f_17b4f0(int p)
{
    int o;
    o = d_1d49a4;
    d_1d49a4 = p;
    return o;
}
