/* === Beschreibung (Katalog) ===
 * Einheit gz_056cc0 (056cc0 - 056d90)
 *
 * Überblick
 * Diese kleine Einheit initialisiert die Datenstrukturen des Tagebuch-Systems (diary) und registriert das
 * Tagebuch-Statusblockfeld in der globalen Savegame-Verwaltung.
 === Ende Beschreibung === */
// P1 3/4 gleich
// gz_056cc0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x056CC0-0x056D90
#include <string.h>
#include "RIVAMEM.H"



void *f_145300(void *p, int v, unsigned n);
extern char d_1bcac8;                    // 0x1BCAC8
extern short d_1bcac9;                   // 0x1BCAC9
extern volatile short d_1c212a;          // 0x1C212A
extern char **d_1c212c;                  // 0x1C212C
struct S {
    short a;
    short b;
    int c;
    int d;
    char pad1[4];
    char e;
    signed char f;
    char g[0x15];
    char h;
    char pad2[8];
    int i;
    char pad3[4];
    int j;
    int k;
};
//@ f_056cc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert das globale Tagebuch-Statusfeld (d_1bcac8) und trägt es in die Liste der beim
 *   Spielstand-Speichern zu sichernden Datenblöcke (d_1c212c) ein.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Flag d_1bcac8 (Neueintrag-Markierung) wird auf 0 und d_1bcac9 auf 0x19 gesetzt und
 *   in d_1c212c[d_1c212a++] registriert.
 === Ende Beschreibung === */
void f_056cc0(void)
{
    d_1bcac8 = 0;
    d_1bcac9 = 0x19;
    d_1c212c[d_1c212a] = &d_1bcac8;
    ++d_1c212a;
}
//@ f_056d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert und initialisiert ein Tagebuch-Verwaltungsobjekt (struct D / S) mit leeren Seiten-
 *   und Textzeigern.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Tagebuch-Objekt s und gibt s zurück.
 * - Wichtige Variablen: Die Seitenfelder a (n) und b (cur), der Textzeiger c (text), der Suchbegriffspuffer g
 *   (name[0x15]) sowie die Tabellenzeiger werden auf ihre Ausgangswerte (0 bzw. 0xff für h) gesetzt.
 === Ende Beschreibung === */
S *f_056d00(S *s)
{
    signed char c;
    s->f = 0;
    c = s->f;
    s->d = 0;
    s->k = 0;
    s->i = 0;
    s->j = 1;
    s->e = c;
    s->a = c;
    s->b = c;
    s->c = s->d;
    s->h = 0xff;
    memset(s->g, 0, 0x15);
    return s;
}
//@ f_056d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Destruktor bzw. Platzhalter für das Tagebuch-Verwaltungsobjekt.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter (void) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Daten verändert.
 === Ende Beschreibung === */
void f_056d60(void)
{
}
//@ f_056d70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Seiten- und Suchfilterfelder eines bestehenden Tagebuch-Objekts wieder in den
 *   Ausgangszustand zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Tagebuch-Objekt s entgegen und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Die Felder a (Gesamtseitenzahl), b (aktuelle Seite), e und f (Suchkategorie) werden auf
 *   0 und h auf 0xff gesetzt.
 === Ende Beschreibung === */
void f_056d70(S *s)
{
    s->f = 0;
    s->h = 0xff;
    s->b = s->a = (signed char)(s->e = s->f);
}
