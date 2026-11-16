/* === Beschreibung (Katalog) ===
 * Einheit gz_02df20_t1 (0x0002dee0 - 0x0002e080)
 *
 * Überblick
 *
 * Die Einheit gz_02df20_t1 enthält Berechnungs- und Ausführungsfunktionen für Herbergen und Tavernen
 * (Zimmerpreise, Verpflegungskosten sowie die Regeneration von Lebens- und Astralenergie beim Übernachten je
 * nach Zimmerqualität und Gruppengröße).
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// P3 6/14 gleich (suche.py 26.10.2026, Basis gz_02df20_P1.CPP)
// gz_02df20.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02DF20-0x02E56F
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05fee0(int p1);                                   // reg eax stapel 0
int f_05fef0(int p1);                                   // reg eax stapel 0
short f_0dbfe0(int p1);                                   // reg eax stapel 0
int f_0dbe20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_125ed0(void *p1, int p2);                           // reg eax edx stapel 0
int f_125f70(void *p1, int p2);                           // reg eax edx stapel 0
int f_149cf0(int p_h = 0x3e8);                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c44;                    // 0x1C2C44
// --- eigene Funktionen (14), in dieser Reihenfolge definieren, je eine Zeile 
#define I4(p, o) (*(int *)((p) + (o)))
#define H1(p) (*(int *)((p) + 0x1e))
#define U1(a) (*(unsigned char *)(a))
#define U2(a) (*(unsigned short *)(a))
#define S2(a) (*(short *)(a))
int f_11ea00(int p1, int p2, int p3, int p4, int p5);
extern const char d_1a0710[];
//@ f_02dee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt ein kurzes 1-Byte-Hilfsobjekt an, ruft damit die Funktion f_11ea00 mit der
 *   Ressourcenkennung 0x22000d und den Daten aus p1 sowie p1 + 0x2e auf und gibt das Hilfsobjekt sofort wieder
 *   frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Übergibt *p1 und p1 + 0x2e an f_11ea00.
 === Ende Beschreibung === */
void f_02dee0(short *p1)
{
  void *o = operator new(1, mark(d_1a0710, 0x32));
  f_11ea00((int)o, 0x22000d, (int)*p1, (int)(p1 + 0x2e), 4);
  operator delete(o);
}
//@ f_02df20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhaltermethode ohne Wirkung im Spiel.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02df20() { }
//@ f_02df30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert konstant den Statuswert 1 zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt 1 zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
int f_02df30() { return 1; }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_02df40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Kosten einer Übernachtung für die gesamte Heldengruppe (f_0dbfe0(d_1c0004)
 *   Mitglieder) abhängig von der Qualitätsstufe der Herberge (p1 + 0x5c) und dem prozentualen Preisaufschlag (p1
 *   + 0x5e) in Heller, wobei mindestens 1 Heller zurückgegeben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Herbergsdaten und gibt den berechneten
 *   Übernachtungspreis als Ganzzahl zurück.
 * - Wichtige Variablen: Liest die Gruppengröße über f_0dbfe0(d_1c0004), die Herbergsgüte bei p1 + 0x5c und den
 *   Preismodifikator bei p1 + 0x5e.
 === Ende Beschreibung === */
int f_02df40(int p1)
{
    int v = f_0dbfe0(d_1c0004) * (6 - S2(p1 + 0x5c) / 4);
    v = (S2(p1 + 0x5e) * v / 100 + v) * 10;
    if (v <= 0) v = 1;
    return v;
}
//@ f_02dfa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt den Preis für eine Runde Essen oder Getränke anhand der Gruppengröße plus eins (s +
 *   1) und des prozentualen Aufschlags der Taverne (p1 + 0x5e), mindestens jedoch 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Herbergszeiger p1 entgegen und gibt den berechneten Preis
 *   zurück.
 * - Wichtige Variablen: Verwendet f_0dbfe0(d_1c0004) und das Feld *(short *)(p1 + 0x5e).
 === Ende Beschreibung === */
int f_02dfa0(int p1)
{
    short s = f_0dbfe0(d_1c0004);
    int v = s + 1;
    v += (S2(p1 + 0x5e) * (s + 1)) / 100;
    if (v <= 0) v = 1;
    return v;
}
//@ f_02dfe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet aus dem Qualitätswert 0x15 - *(short *)(p1 + 0x5c) (mindestens 1) den
 *   Regenerationsfaktor s, heilt die Gruppe über f_0dbe20(d_1c0004, s * 20, s * 30) und stellt die Tageszeit
 *   über f_125f70(&d_1c2c44, 1) auf den nächsten Morgen vor.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest *(short *)(p1 + 0x5c) und aktualisiert die Heldenwerte von d_1c0004 sowie die
 *   Spieluhr d_1c2c44.
 === Ende Beschreibung === */
void f_02dfe0(int p1)
{
    short s = 0x15 - S2(p1 + 0x5c);
    if (s <= 0) s = 1;
    f_0dbe20(d_1c0004, (short)(s * 0x14), (short)(s * 0x1e));
    f_125f70(&d_1c2c44, 1);
}
//@ f_02e030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gewährt der Gruppe anhand von s = max(1, 0x15 - *(short *)(p1 + 0x5c)) eine kleinere Erholung
 *   über f_0dbe20(d_1c0004, 1, s * 30) und lässt die Spieluhr über f_125ed0(&d_1c2c44, 0x1e) um 30 Minuten
 *   voranschreiten.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Herbergszeiger p1 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Liest *(short *)(p1 + 0x5c) und verändert die Gruppenwerte sowie die Uhrzeit d_1c2c44.
 === Ende Beschreibung === */
void f_02e030(int p1)
{
    short s = 0x15 - S2(p1 + 0x5c);
    if (s <= 0) s = 1;
    f_0dbe20(d_1c0004, 1, (short)(s * 0x1e));
    f_125ed0(&d_1c2c44, 0x1e);
}
