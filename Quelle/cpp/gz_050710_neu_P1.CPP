/* === Beschreibung (Katalog) ===
 * Einheit gz_050710_neu (0x050710 - 0x050860)
 *
 * Überblick
 * Die Einheit gz_050710_neu enthält drei Methoden einer Grafik- oder Animations-Ressourcenklasse (Cut), die
 * Kopfdaten (Einzelbildanzahl, Bildabmessungen) sowie die am Dateiende gespeicherte 768-Byte-VGA-Farbpalette aus
 * einer Archivdatei über den RivaFileManager (d_1c2098) auslesen.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 050710-050860 aus Quelle/cpp/G050710.CPP; erster Entwurf, Einbau separat prüfen.
// P1 3/3 gleich
// gz_050710.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x050710-0x050860
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
struct Cut {
    char pad[0x19];
    int f19;
    int f_050710(unsigned p2);
    void f_050770(unsigned p2, char *p3, int p4);
    int f_0507e0(unsigned p2, char *p3, char *p4);
};
//@ f_050710
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2 (setzt bei gesetztem Flag this->f19 == 1 das höchste Bit
 *   0x80000000 der Ressourcen-ID), überliest das erste Kennbyte und liest die darauffolgende 16-Bit-Anzahl der
 *   Datensätze oder Einzelbilder aus dem Dateikopf.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID der Archivdatei).
 * - Rückgabewert: Ausgelesene 16-Bit-Anzahl (r) aus dem Dateikopf (in den oberen 16 Bits von r uninitialisiert,
 *   vom Aufrufer als short verwendet).
 * - Wichtige Variablen:
 *   - this->f19 (+0x19): Steuerflag, das bei Wert 1 die Ressourcen-ID mit 0x80000000 verodert.
 *   - d_1c2098: Globale Instanz des RivaFileManager.
 === Ende Beschreibung === */
//@ f_050710
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2 (setzt bei gesetztem Flag this->f19 == 1 das höchste Bit
 *   0x80000000 der Ressourcen-ID), überliest das erste Kennbyte und liest die darauffolgende 16-Bit-Anzahl der
 *   Datensätze oder Einzelbilder aus dem Dateikopf.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID der Archivdatei).
 * - Rückgabewert: Ausgelesene 16-Bit-Anzahl (r) aus dem Dateikopf (in den oberen 16 Bits von r uninitialisiert,
 *   vom Aufrufer als short verwendet).
 * - Wichtige Variablen:
 *   - this->f19 (+0x19): Steuerflag, das bei Wert 1 die Ressourcen-ID mit 0x80000000 verodert.
 *   - d_1c2098: Globale Instanz des RivaFileManager.
 === Ende Beschreibung === */
int Cut::f_050710(unsigned p2)
{
    int r; char c;
    if (f19 == 1 && p2 != 0) p2 |= 0x80000000;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p2, 0x200);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &c), 1)));
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &r), 2)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    return r;
}
//@ f_050770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2, ermittelt deren Dateigröße (f_144a00), springt 0x300 (768)
 *   Bytes vor das Dateiende und liest von dort p4 RGB-Farbeinträge (p4 * 3 Bytes) der VGA-Palette in den
 *   Zielpuffer p3.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID), p3 (Zielpuffer für die
 *   Palettendaten), p4 (Anzahl der zu lesenden Farben zu je 3 Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Gesamtgröße der geöffneten Archivdatei in Bytes (n - 0x300 ist der Offset der 256-Farben-Palette am
 *     Dateiende).
 === Ende Beschreibung === */
//@ f_050770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2, ermittelt deren Dateigröße (f_144a00), springt 0x300 (768)
 *   Bytes vor das Dateiende und liest von dort p4 RGB-Farbeinträge (p4 * 3 Bytes) der VGA-Palette in den
 *   Zielpuffer p3.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID), p3 (Zielpuffer für die
 *   Palettendaten), p4 (Anzahl der zu lesenden Farben zu je 3 Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Gesamtgröße der geöffneten Archivdatei in Bytes (n - 0x300 ist der Offset der 256-Farben-Palette am
 *     Dateiende).
 === Ende Beschreibung === */
void Cut::f_050770(unsigned p2, char *p3, int p4)
{
    int n;
    if (f19 == 1 && p2 != 0) p2 |= 0x80000000;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p2, 0x200);
    n = ((int)(((RivaFileManager*)(&d_1c2098))->f_144a00()));
    ((RivaFileManager*)(&d_1c2098))->f_144ab0( n - 0x300, 0);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p3), (short)p4 * 3)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
}
//@ f_0507e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2, überliest das erste Byte und liest nacheinander die
 *   16-Bit-Einzelbildanzahl (r) sowie zwei 16-Bit-Kopfwerte (Breite in p3 und Höhe in p4) aus dem Dateikopf.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID), p3 (Ausgabezeiger für den ersten
 *   16-Bit-Wert, vermutlich Breite), p4 (Ausgabezeiger für den zweiten 16-Bit-Wert, vermutlich Höhe).
 * - Rückgabewert: Ausgelesene 16-Bit-Einzelbildanzahl (r).
 * - Wichtige Variablen:
 *   - r: Lokal ausgelesene Bildanzahl an Dateioffset +1.
 === Ende Beschreibung === */
//@ f_0507e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource p2, überliest das erste Byte und liest nacheinander die
 *   16-Bit-Einzelbildanzahl (r) sowie zwei 16-Bit-Kopfwerte (Breite in p3 und Höhe in p4) aus dem Dateikopf.
 * - Eingaben: this (Zeiger auf die Cut-Instanz), p2 (32-Bit-Ressourcen-ID), p3 (Ausgabezeiger für den ersten
 *   16-Bit-Wert, vermutlich Breite), p4 (Ausgabezeiger für den zweiten 16-Bit-Wert, vermutlich Höhe).
 * - Rückgabewert: Ausgelesene 16-Bit-Einzelbildanzahl (r).
 * - Wichtige Variablen:
 *   - r: Lokal ausgelesene Bildanzahl an Dateioffset +1.
 === Ende Beschreibung === */
int Cut::f_0507e0(unsigned p2, char *p3, char *p4)
{
    int r;
    if (f19 == 1 && p2 != 0) p2 |= 0x80000000;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p2, 0x200);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &r), 1)));
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &r), 2)));
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p3), 2)));
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p4), 2)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    return r;
}
