/* === Beschreibung (Katalog) ===
 * Einheit gz_04fce0 (04fce0 - 04fe30)
 *
 * Überblick
 * Diese Einheit implementiert eine kompakte 2-Bit-pro-Zelle-Bitfeldklasse (struct B), in der jedes Byte vier
 * 2-Bit-Einträge (0 bis 3) einer zweidimensionalen Karte (Breite w in Bytes, Höhe h in Zeilen) speichert - wie
 * sie für Sichtbarkeits- oder Automap-Masken verwendet wird.
 === Ende Beschreibung === */
// P3 4/6 gleich (suche.py 25.10.2026, Basis gz_04fce0_P1.CPP)
// gz_04fce0.cpp (Schatten ueber Riva) - Pass 1, Code 0x04FCE0-0x04FE30
#include <string.h>
#include "RIVAMEM.H"




void f_145300(void *p, int v, unsigned n);
struct B { char pad0[2]; unsigned short h; unsigned short w; unsigned char *d; };

//@ f_04fce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Datenpuffer p->d des 2-Bit-Kartenobjekts frei und liefert das Objekt zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p (struct B *) sowie ein ungenutztes Flag p_unused1
 *   und gibt p zurück.
 * - Wichtige Variablen: Freigegeben wird das dynamische Byte-Array p->d.
 === Ende Beschreibung === */
B *f_04fce0(B *p, int p_unused1)
{
    delete p->d;
    return p;
}

//@ f_04fcf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Füllt das gesamte 2-Bit-Kartenfeld mit einem einheitlichen 2-Bit-Wert v (0 bis 3), indem der
 *   Wert viermal in ein Byte gepackt und über den gesamten Puffer w * h geschrieben wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt das Kartenobjekt p sowie den 2-Bit-Füllwert v entgegen und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die Gesamtgröße in Bytes berechnet sich aus p->w * p->h, und f_145300 (memset) füllt
 *   p->d mit dem wiederholten Musterbyte.
 === Ende Beschreibung === */
void f_04fcf0(B *p, int v)
{
    unsigned n = p->w;
    n *= p->h;
    int fill = v;
    fill = fill * 4 | v;
    fill = fill * 4 | v;
    fill = fill * 4 | v;
    f_145300(p->d, fill, n);
}

//@ f_04fd30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den direkten Zeiger auf den Rohdatenpuffer p->d des 2-Bit-Kartenobjekts zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Kartenobjekt p und gibt p->d als unsigned char * zurück.
 * - Wichtige Variablen: Das Feld p->d an Offset +6 verweist auf den Bytepuffer.
 === Ende Beschreibung === */
unsigned char *f_04fd30(B *p)
{
    return p->d;
}

//@ f_04fd40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Größe des Rohdatenpuffers des 2-Bit-Kartenobjekts in Bytes.
 * - Eingaben und Rückgabe: Die Funktion nimmt das Kartenobjekt p entgegen und gibt das Produkt p->w * p->h als
 *   int zurück.
 * - Wichtige Variablen: Die Felder p->h (+2) und p->w (+4) speichern Höhe und Bytebreite.
 === Ende Beschreibung === */
int f_04fd40(B *p)
{
    return p->w * p->h;
}

//@ f_04fd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den 2-Bit-Zustandswert (0 bis 3) der Kartenposition (x, y) aus dem gepackten
 *   Kartenpuffer aus.
 * - Eingaben und Rückgabe: Die Funktion erhält das Kartenobjekt p sowie die Koordinaten x und y (unsigned short)
 *   und gibt den 2-Bit-Wert als int (0..3) zurück.
 * - Wichtige Variablen: Zugegriffen wird auf das Byte p->d[x / 4 + p->w * y], das um (x % 4) * 2 Bits nach
 *   rechts geschoben und mit 3 maskiert wird.
 === Ende Beschreibung === */
int f_04fd60(B *p, unsigned short x, unsigned short y)
{
    unsigned char value = p->d[x / 4 + p->w * y];
    value >>= (x % 4) * 2;
    value &= 3;
    return value;
}

//@ f_04fdb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen neuen 2-Bit-Zustandswert v (0 bis 3) an die Kartenposition (x, y) in den
 *   gepackten Kartenpuffer, ohne die übrigen drei Nachbarzellen desselben Bytes zu verändern.
 * - Eingaben und Rückgabe: Die Funktion erhält das Kartenobjekt p, die Koordinaten x und y sowie den neuen
 *   2-Bit-Wert v und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Zielbyte p->d[x / 4 + p->w * y] wird zuerst mit der invertierten 2-Bit-Maske ~(3 <<
 *   ((x % 4) * 2)) gelöscht und anschließend mit v << ((x % 4) * 2) verodert.
 === Ende Beschreibung === */
void f_04fdb0(B *p, unsigned short x, unsigned short y, int v)
{
    unsigned char mask = 3;
    mask <<= (x % 4) * 2;
    v <<= (x % 4) * 2;
    mask ^= 0xff;
    p->d[x / 4 + p->w * y] &= mask;
    p->d[x / 4 + y * p->w] |= v;
}
