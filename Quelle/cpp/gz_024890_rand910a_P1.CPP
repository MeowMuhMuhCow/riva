/* === Beschreibung (Katalog) ===
 * Einheit gz_024890_rand910a (0x00024890 - 0x000248d0)
 *
 * Überblick
 *
 * Die Randeinheit gz_024890_rand910a enthält die Registrierungsfunktion für die persistenten
 * Spielstand-Variablen der Katakomben unter dem Boronanger (BORON2) sowie die Vorwärtsdeklarationen der
 * angrenzenden Randeinheit gz_024890_rand910b.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 6/7 gleich (suche.py 24.10.2026, Basis gz_024890_P1.CPP)
// gz_024890.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x024890-0x024A90
#include <string.h>
struct Msg { void f_0bf730(long code); int f_0bf820(long code, ...); };
extern Msg d_1c2c64;


extern char d_1c349c[], d_1c3870[], d_1c3498[], d_1c2c44[];
extern char d_1bab80[], d_1babc4[], d_1babd8[];
extern int d_1c0004;
void *f_145234(void *p, void *d);
void f_145254();
int f_060030(int p1, int p2);
int f_0b9060(int p1);
int f_10a260(int p1, int p2);
int f_10a270(int p1, int p2);
void f_10a2c0(int p1);
int f_0db8b0(int p1, int p2);
int f_0dbfe0(int p1);
int f_0dbe20(int p1, int p2, int p3);
int f_0de5a0(int p1, int p2);
int f_0de5d0(int p1, int p2);
int f_0de7e0(int p1);
void f_125f70(void *p, int v);
void f_024980(int p1);
//@ f_024890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Meldet alle 22 speicherbaren Ereignis- und Fortschrittsflags der Katakomben (BORON2) in der
 *   globalen Spielstand-Verwaltung an, damit geöffnete Sarkophage, entschärfte Fallen und besiegte Gegner beim
 *   Speichern erhalten bleiben.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: In einer Schleife über 0x16 (22) Einträge ab d_1bc7b8 werden die Flag-Adressen und ihre
 *   eindeutigen Kennungen in das globale Spielstand-Array d_1c212a eingetragen und der Zähler d_1c392a erhöht.
 === Ende Beschreibung === */
int f_024890(int p1, unsigned p2)
{
    if (p2 & 4) {
        f_145234((void *)p1, d_1bab80);
        f_145254();
        return p1;
    }
    int u = f_060030(p1, 1);
    if (p2 & 2) delete (char *)u;
    return u;
}
//@ f_0248d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft beim Programmstart die Registrierungsfunktion f_024890 auf; in dieser Teileinheit liegt
 *   nur die Kopfdeklaration vor.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine eigenen Variablen in dieser Teileinheit.
 === Ende Beschreibung === */
int f_0248d0(int p1, int p2)
;
//@ f_0248e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Richtet eine kleine 12-Byte-Verwaltungsstruktur für den nachfolgenden Cache-Manager ein; hier
 *   nur als Deklaration geführt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger und Startwerte und gibt den Zeiger zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910b.
 === Ende Beschreibung === */
int f_0248e0(int p1, unsigned p2)
;
//@ f_024920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein Statusfeld der Verwaltungsstruktur zurück; hier nur als Deklaration vorhanden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger und gibt einen Statuswert zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910b.
 === Ende Beschreibung === */
void f_024920()
;
//@ f_024930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest ein weiteres Feld der Verwaltungsstruktur aus; hier nur deklariert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger und liefert einen Ganzzahlwert zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910b.
 === Ende Beschreibung === */
void f_024930(int p1)
;
//@ f_024940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Felder der kleinen Verwaltungsstruktur zurück; hier nur als Deklaration enthalten.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger und gibt keinen Wert zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910b.
 === Ende Beschreibung === */
int f_024940(int p1, short p2)
;
//@ f_024980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht oder aktualisiert die Einträge der Verwaltungsstruktur; hier nur als
 *   Vorwärtsdeklaration geführt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger sowie Suchparameter und gibt das Ergebnis
 *   zurück.
 * - Wichtige Variablen: Siehe gz_024890_rand910b.
 === Ende Beschreibung === */
void f_024980(int p1)
;
