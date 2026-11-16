/* === Beschreibung (Katalog) ===
 * Einheit: ace_t3
 *
 * Adressbereich: 0x012870-0x012a00
 * Spielsystem: Optionen & Zustandsvariablen - Abschluss des Byte-Register-Template-Codes in ace.cpp; wird im
 * Spiel genutzt, um das Optionsregister d_1bfad4 über den Dateistrom d_1c2098 auf Platte zu speichern.
 === Ende Beschreibung === */
// P3 2/4 gleich (suche.py 24.10.2026, Basis ace_t3_P1.CPP)
// P1 1/4 GLEICH, Rest: 012870 REG/STAPEL (b in ebp, edi-Temp), 0129C0 REG (ebx statt edx), 0129D0 Bytes
// ace.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0104B0-0x012A00
#include <string.h>
#include "RIVAMEM.H"



// --- Typen/Daten (angepasst) ---
struct Itm { char a; short b; char ga() { return a; } short gb() { return b; } };
struct Lst { short cap; short n; Itm **arr; };
struct Strm { char pad[0x14]; int (**vt)(Strm *, void *, int); };
extern const char d_1a0134[];
void *f_014540(int p1, const char *p2, int p3);

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_012870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt alle Einträge eines 8-Bit-Byte-Registers ohne Längenfeld über die virtuelle
 *   Schreibmethode vt[9] in ein Strom-Objekt (2 Bytes Anzahl, n Bytes Werte, n * 2 Bytes Kennnummern); wird in
 *   options_t1 (f_0d7be0) und options_t2 (Fall 0x25) aufgerufen, um die 21 Spieloptionen aus d_1bfad4 über
 *   d_1c2098 in die Optionsdatei zu sichern.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1, im Spiel d_1bfad4) und Zeiger auf das Strom-Objekt
 *   (p2, d_1c2098); gibt 1 bei Erfolg (auch bei leerem Register), 0 bei Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Temporärer Byte-Puffer a für die Optionswerte und short-Puffer b für die
 *   Kennnummern.
 === Ende Beschreibung === */
int f_012870(Lst *p1, Strm *p2)
{
    int r = 0;
    short *b;
    char *a;
    short i;
    if (p2->vt[9](p2, &p1->n, 2) == 2) {
        if (p1->n != 0) {
            a = new (mark(d_1a0134, 0x115)) char[p1->n];
            b = new (mark(d_1a0134, 0x116)) short[p1->n];
            for (i = 0; i < p1->n; i++) {
                a[i] = p1->arr[i]->ga();
                b[i] = p1->arr[i]->gb();
            }
            if (p2->vt[9](p2, a, p1->n * sizeof(char)) == p1->n * sizeof(char)) {
                if (p2->vt[9](p2, b, p1->n * 2) == p1->n * 2)
                    r = 1;
            }
            delete a;
            delete b;
        } else {
            r = 1;
        }
    }
    return r;
}
//@ f_0129a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hängt einen Byte-Variableneintrag hinten an ein Byte-Register an und erhöht die
 *   Eintragsanzahl n um 1 (eigene, nicht mit f_011da0/f_0123a0 zusammengelegte Template-Instanz).
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1) und Zeiger auf den 3-Byte-Eintrag (p2); keine
 *   Rückgabe.
 * - Wichtige Variablen & Daten: Schreibt p1->arr[p1->n] = p2 und erhöht p1->n ohne Prüfung gegen p1->cap.
 === Ende Beschreibung === */
void f_0129a0(Lst *p1, Itm *p2)
{
    p1->arr[p1->n] = p2;
    p1->n++;
}

//@ f_0129c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor eines Byte-Registers: gibt das Zeigerfeld arr frei, ohne die Variableneinträge
 *   selbst zu löschen.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (this) und ungenutzter Destruktorschalter; gibt this
 *   zurück.
 * - Wichtige Variablen & Daten: Gibt p1->arr frei.
 === Ende Beschreibung === */
Lst *f_0129c0(Lst *p1, int p_unused1)
{
    delete p1->arr;
    return p1;
}

//@ f_0129d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor eines Byte-Registers: setzt die Anzahl n auf 0, speichert die Kapazität cap
 *   und reserviert über f_014540 ein Zeigerfeld für cap * 4 Bytes (entspricht der Inline-Initialisierung des
 *   Optionsregisters d_1bfad4 mit Kapazität 25 in options_t1 f_0d7430).
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (this) und Kapazität (p2); gibt this zurück.
 * - Wichtige Variablen & Daten: Felder n, cap und arr des Registers.
 === Ende Beschreibung === */
Lst *f_0129d0(Lst *p1, int p2)
{
    p1->n = 0;
    p1->cap = (short)p2;
    p1->arr = (Itm **)f_014540((short)p2 * 4, d_1a0134, 0xd3);
    return p1;
}
