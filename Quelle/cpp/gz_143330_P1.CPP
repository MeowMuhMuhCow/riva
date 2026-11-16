/* === Beschreibung (Katalog) ===
 * Einheit gz_143330 (0x143330 - 0x143513)
 *
 * Überblick
 *
 * Die Einheit gz_143330 enthält den abschließenden Methodensatz des erweiterten Dialogsystems (xdialog.cpp),
 * über den die Callback-Routinen einzelner Stadt-, Dungeon- und Questdialoge während eines laufenden Gesprächs
 * das Verhalten des Gesprächspartners beeinflussen können (Ungeduld verändern, Gespräch sofort oder nach
 * Verabschiedung abbrechen, Themenliste zur Aktualisierung vormerken, zusätzlichen Text einschieben oder
 * Phasenwechsel steuern).
 === Ende Beschreibung === */
// P3 5/9 gleich (suche.py 24.10.2026, Basis gz_143330_P1.CPP)
// gz_143330.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x143330-0x143520
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9650(int p1, int p2);                           // reg eax stapel 0 (Original ruft 0E9650, nicht 05E440 - Fable 30.10.)
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1b8708;                    // 0x1B8708
extern int d_1b870c;                    // 0x1B870C
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (9), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#define AD(x) ((int)&(x))
#define W8(p,o) (*(unsigned char *)((char *)(p) + (o)))
#define W16(p,o) (*(short *)((char *)(p) + (o)))
#define W32(p,o) (*(int *)((char *)(p) + (o)))

//@ f_143330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den aktuellen Ungeduldszähler des Gesprächspartners (((short *)W32(p1,
 *   0x21))[W16(p1, 0x1F)]) um den Differenzwert p2 (positiv bei verärgernden Aussagen, negativ bei
 *   beschwichtigenden Aussagen).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Änderungswert p2 (int).
 * - Rückgabewert: Der neue Stand des Ungeduldszählers (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_143330(int p1, int p2)
{
    return ((short *)W32(p1, 0x21))[W16(p1, 0x1f)] += p2;
}

//@ f_143350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert die Geduldsschwelle (W16(p1, 0xA7)) des aktuellen Gesprächspartners um den Wert p2.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Änderungswert p2 (int).
 * - Rückgabewert: Die neue Geduldsschwelle W16(p1, 0xA7) (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_143350(int p1, int p2)
{
    return W16(p1, 0xa7) += p2;
}

//@ f_143370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Ungeduldszähler des aktuellen Gesprächspartners direkt auf dessen Geduldsschwelle
 *   W16(p1, 0xA7), sodass das Gespräch nach dem aktuellen Thema (noch mit Verabschiedungstext) beendet wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - index, base: NSC-Index W16(p1, 0x1F) und Basisadresse des Ungedulds-Arrays W32(p1, 0x21).
 === Ende Beschreibung === */
void f_143370(int p1)
{
    int index = W16(p1, 0x1f);
    int offset = index << 1;
    short *base = (short *)W32(p1, 0x21);
    *(short *)((char *)base + offset) = W16(p1, 0xa7);
}

//@ f_143390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bricht das laufende Gespräch sofort und ohne weiteren Abschiedssatz ab (z. B. wenn aus dem
 *   Dialog heraus unmittelbar ein Kampf oder Ortswechsel ausgelöst wird), indem der Ungeduldszähler auf das
 *   Limit W16(p1, 0xA7) gesetzt und zusätzlich das Sofortabbruch-Flag W32(p1, 0xA3) = 1 aktiviert wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - W32(p1, 0xA3): Flag zur Unterdrückung des regulären Abschiedstextes in f_142e90.
 === Ende Beschreibung === */
void f_143390(int p1)
{
    int index = W16(p1, 0x1f);
    int offset = index << 1;
    short *base = (short *)W32(p1, 0x21);
    *(short *)((char *)base + offset) = W16(p1, 0xa7);
    W32(p1, 0xa3) = 1;
}

//@ f_1433c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Markiert die rechte Themenauswahlliste als veraltet (W32(p1, 0x5D) = 0), sodass sie beim
 *   nächsten Neuzeichnen über f_141420 komplett neu aus den freigeschalteten Stichworten aufgebaut wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1433c0(int p1)
{
    W32(p1, 0x5d) = 0;
}

//@ f_1433d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt einen beliebigen Textbaustein anhand seiner Ressourcenkennung p3 über f_0e93f0, versieht
 *   ihn bei Sprechermodus p2 == 1 (NSC, Farbe 0xF9) oder p2 == 2 (Held, Farbe 0xFF) mit Anführungszeichen <...>
 *   (bzw. lässt ihn bei p2 == 3 in Farbe 0xF0 ohne Klammern) und gibt ihn samt nachfolgendem Trennzeichen
 *   (d_1b870c) im Dialog-Textfenster aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, Darstellungsmodus p2 (short, 1-3) und Textressourcen-Kennung p3
 *   (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - q: Schreibzeiger in den Textpuffer W32(p1, 0xAF).
 === Ende Beschreibung === */
void f_1433d0(int p1, short p2, int p3)
{
    short mode = 0;
    char *s;
    char *q;
    int owner;
    f_0e93f0(AD(d_1c38b0), AD(d_1c21b4), p3);
    owner = p1;
    s = (char *)&d_1c21b4;
    q = (char *)W32(p1, 0xaf);
    mode = p2;
    if (mode == 1 || mode == 2) {
        *q = '<';
        q++;
    }
    strcpy(q, s);
    if (mode == 1 || mode == 2) {
        strcat((char *)W32(owner, 0xaf), (char *)&d_1b8708);
    }
    switch ((unsigned short)mode) {
    case 1:
        f_05e320(AD(d_1c38b0), 0xf9, -1);
        break;
    case 2:
        f_05e320(AD(d_1c38b0), 0xff, -1);
        break;
    case 3:
        f_05e320(AD(d_1c38b0), 0xf0, -1);
        break;
    }
    f_0e9650(AD(d_1c38b0), W32(p1, 0xaf));
    f_0e9650(AD(d_1c38b0), AD(d_1b870c));
}

//@ f_1434f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Phasen-Steuercode W16(p1, 0xA9) = 1, wodurch das aktuell besprochene Thema nach
 *   Abschluss des Skripts in derselben Gesprächsphase bleibt (statt automatisch in die nächste Phase
 *   weiterzuschalten).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1434f0(int p1)
{
    W16(p1, 0xa9) = 1;
}

//@ f_143500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Phasen-Steuercode W16(p1, 0xA9) = 2, wodurch die Gesprächsphase des aktuellen Themas
 *   nach Abschluss des Skripts wieder auf 0 (Anfangsphase) zurückgesetzt wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_143500(int p1)
{
    W16(p1, 0xa9) = 2;
}

//@ f_143510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Standard-Platzhalterfunktion (Default-Callback für Dialoge ohne eigene Sonderbedingungen), die
 *   immer 0 zurückgibt.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_143510()
{
    return 0;
}
