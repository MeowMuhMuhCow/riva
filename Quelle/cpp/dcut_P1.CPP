/* === Beschreibung (Katalog) ===
 * Einheit dcut (04fe30 - 050710)
 *
 * Überblick
 * Diese Einheit (dcut.cpp) implementiert den Grafik- und Sprite-Entpacker (struct Cut) für mehrteilige Bild- und
 * Icon-Archive (wie das Gegenstands-Icon-Archiv 0x50002 oder Animationsframes). Sie unterstützt unkomprimierte,
 * LZW-/Wörterbuch-gepackte sowie lauflängenkodierte (RLE, Kennbyte 0x7f) Teilbilder einschließlich horizontaler
 * Spiegelung und liest bei Bedarf auch nur die Bildabmessungen eines Einzelbildes aus.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 5/7 gleich (suche.py 26.10.2026, Basis dcut_P1.CPP)
// dcut.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04FE30-0x050710
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a1400[];           // Text 0x1A1400
char *f_014540(int size, const char *file, int line);




void f_147cd0(void *buf);
void f_147ef0(void *buf, char *dst, char *src, int n);
int f_148180(int v);

struct Cut {
    char *f0;
    char *f4;
    char *f8;
    short fc;
    short fe;
    signed char f10;
    unsigned short *f11;
    unsigned short *f15;
    int f19;
    Cut *f_04fe30(int p2);
    Cut *f_04fe60(int p_unused1);
    void f_04fe80(char *p2, char *p3, short p4, char p5, unsigned short *p6, unsigned short *p7, short p8);
    int f_04feb0(unsigned p2, char *p3, char *p4, short p5, char p6, unsigned short *p7, unsigned short *p8, short p9);
    int f_04fef0(unsigned p2, char *p3, char *p4, short p5, char p6, short p7);
    int f_04ff40(unsigned p2);
    void f_050580(unsigned p2, int p3, unsigned short *p4, unsigned short *p5);
};
//@ f_04fe30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Grafik-Entpacker-Objekt (Cut), speichert das Archiv-Flag und reserviert einen
 *   100-Byte-Zeilenpuffer.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie das Archiv-Flag p2 und gibt this
 *   zurück.
 * - Wichtige Variablen: Das Feld f19 merkt sich p2 (bei 1 wird später das höchste Bit 0x80000000 der
 *   Ressourcen-ID gesetzt), und f0 verweist auf den über f_014540 reservierten Hilfspuffer.
 === Ende Beschreibung === */
Cut *Cut::f_04fe30(int p2)
{
    f19 = p2;
    f0 = f_014540(100, d_1a1400, 0x1f);
    return this;
}
//@ f_04fe60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut das Grafik-Entpacker-Objekt ab und gibt dessen internen Zeilenpuffer f0 wieder frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt this sowie ein ungenutztes Flag entgegen und gibt this zurück.
 * - Wichtige Variablen: Sofern f0 != 0 ist, wird der Speicher mit operator delete freigegeben.
 === Ende Beschreibung === */
Cut *Cut::f_04fe60(int p_unused1)
{
    if (f0 != 0) operator delete(f0);
    return this;
}
//@ f_04fe80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt Zielpuffer, Arbeitspuffer, Bildindex, Entpackmodus, Rückgabezeiger für Breite/Höhe sowie
 *   die Zeilenbreite (Stride) in das Entpacker-Objekt ein, ohne das Entpacken sofort zu starten.
 * - Eingaben und Rückgabe: Die Funktion erhält this, den Zielpuffer p2, den Quell-/Arbeitspuffer p3, den
 *   Frame-Index p4, den Modus p5, die Ausgabeparameter p6 (Breite) und p7 (Höhe) sowie die Ziel-Zeilenbreite p8
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Parameter werden in den Feldern f4, f8, fc, f10, f11, f15 und fe abgelegt.
 === Ende Beschreibung === */
void Cut::f_04fe80(char *p2, char *p3, short p4, char p5, unsigned short *p6, unsigned short *p7, short p8)
{
    f4 = p2;
    f8 = p3;
    fc = p4;
    f10 = p5;
    f11 = p6;
    f15 = p7;
    fe = p8;
}
//@ f_04feb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konfiguriert das Entpacker-Objekt mit allen Ziel- und Modusparametern und entpackt
 *   anschließend sofort das gewünschte Teilbild aus der Archivressource p2, wobei Breite und Höhe in *p7 und *p8
 *   zurückgeschrieben werden.
 * - Eingaben und Rückgabe: Die Funktion erhält this, die Ressourcen-ID p2, Zielpuffer p3, Arbeitspuffer p4,
 *   Bildindex p5, Modus p6, Breitenzeiger p7, Höhenzeiger p8 und Zeilenbreite p9 und gibt als int die entpackte
 *   Bytegröße zurück.
 * - Wichtige Variablen: Nach dem Setzen der Objektfelder ruft die Funktion unmittelbar die Haupt-Entpackroutine
 *   f_04ff40(p2) auf.
 === Ende Beschreibung === */
int Cut::f_04feb0(unsigned p2, char *p3, char *p4, short p5, char p6, unsigned short *p7, unsigned short *p8, short p9)
{
    f4 = p3;
    f8 = p4;
    fc = p5;
    f10 = p6;
    f11 = p7;
    f15 = p8;
    fe = p9;
    return f_04ff40(p2);
}
//@ f_04fef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bequeme Überladung von f_04feb0 zum sofortigen Entpacken eines Teilbildes aus der Ressource
 *   p2, wenn der Aufrufer die Bildbreite und Bildhöhe nicht als Rückgabewerte benötigt.
 * - Eingaben und Rückgabe: Die Funktion nimmt this, die Ressourcen-ID p2, Zielpuffer p3, Arbeitspuffer p4,
 *   Bildindex p5, Modus p6 und Zeilenbreite p7 entgegen und gibt als int die entpackte Größe zurück.
 * - Wichtige Variablen: Die Zeiger f11 und f15 werden auf eine lokale Dummy-Variable loc umgebogen, bevor
 *   f_04ff40(p2) aufgerufen wird.
 === Ende Beschreibung === */
int Cut::f_04fef0(unsigned p2, char *p3, char *p4, short p5, char p6, short p7)
{
    int loc;
    f4 = p3;
    f8 = p4;
    fc = p5;
    f10 = p6;
    f11 = (unsigned short *)&loc;
    f15 = (unsigned short *)&loc;
    fe = p7;
    return f_04ff40(p2);
}
//@ f_04ff40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die Grafikressource p2, liest den Kopftyp (type 0 bis 5) und die Offset-/Größentabelle
 *   der enthaltenen Teilbilder, positioniert auf das gewünschte Teilbild fc und entpackt dessen Pixeldaten je
 *   nach Modus f10 (direktes Lesen, Wörterbuch-Dekompression über f_147ef0 oder RLE-Dekompression mit
 *   0x7f-Lauflängen und optionaler Spiegelung bei f10 == 4 oder 5) in den Zielpuffer f4.
 * - Eingaben und Rückgabe: Die Funktion erhält this und die Ressourcen-ID p2 und gibt als int die Anzahl der
 *   geschriebenen bzw. entpackten Bytes zurück.
 * - Wichtige Variablen: Das Feld fc wird auf [0, count - 1] begrenzt, type & 0x7f unterscheidet feste vs.
 *   individuelle Bildgrößen und Rohdaten vs. komprimierte Blöcke, und am Ende werden width und height in *f11
 *   und *f15 abgelegt.
 === Ende Beschreibung === */
int Cut::f_04ff40(unsigned p2)
{
    signed char fill;
    signed char value;
    signed char run;
    signed char flag;
    unsigned short height;
    short row;
    short column;
    unsigned short width;
    short count;
    signed char type;
    short repeat;
    char *out;
    char *line;
    char *source;
    int result;
    int length;
    int offset;
    struct LocalObject { char value[0x268]; LocalObject() {} } storage;


    if (f19 == 1 && p2 != 0) p2 |= 0x80000000;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p2, 0x200);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &type), 1)));
    flag = type & 0x80;
    type &= 0x7f;
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &count), 2)));

    short size = type == 0 ? 4 :
           type == 1 ? count * 4 :
           (type == 2 || type == 4) ? count * 4 + 4 :
           count * 8;

    unsigned short *table = (unsigned short *)f_014540((unsigned)size, d_1a1400, 0x89);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( table), size)));

    if (fc < 0) fc = 0;
    if (fc > count - 1) fc = count - 1;
    offset = size + 3;
    switch ((unsigned char)type) {
    case 0:
        width = table[0];
        height = table[1];
        length = width * height;
        offset += fc * length;
        break;
    case 1:
        for (row = 0; row < fc; row++) {
            width = table[row * 2];
            height = table[row * 2 + 1];
            offset += width * height;
        }
        width = table[fc * 2];
        height = table[fc * 2 + 1];
        length = width * height;
        break;
    case 2:
    case 4:
        width = table[0];
        height = table[1];
        for (row = 0; row < fc; row++) offset += *(int *)(table + row * 2 + 2);
        length = *(int *)(table + fc * 2 + 2);
        break;
    case 3:
    case 5:
        width = table[0];
        height = table[1];
        for (row = 0; row < fc; row++) offset += *(int *)(table + row * 4 + 2);
        width = table[fc * 4];
        height = table[fc * 4 + 1];
        length = *(int *)(table + row * 4 + 2);
        break;
    }

    ((RivaFileManager*)(&d_1c2098))->f_144ab0( offset, 0);
    operator delete(table);

    if (!f10) {
        if (flag) {
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &result), 4)));
            ((RivaFileManager*)(&d_1c2098))->f_144ab0( result - 8, 1);
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &result), 4)));
            result = f_148180(result) >> 8;
        } else result = width * height;

        if (type != 0 && type != 1) {
            f_147cd0(storage.value);
            source = f8 == 0 ? f_014540(length, d_1a1400, 0xdb) : f8;
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( source), length)));
            f_147ef0(storage.value, f4, source, length);
            if (f8 == 0) operator delete(source);
        } else {
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( f4), length)));
        }
    } else if (2 <= f10 && f10 <= 5) {
        source = f8 == 0 ? f_014540(length, d_1a1400, 0xee) : f8;
        char *saved = source;
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( source), length)));
        line = f4;
        row = 0;
        for (; row < height; row++) {
            if (f10 == 4 || f10 == 5) out = f0;
            else out = line;
            column = 0;
            while (column < width) {
                value = *source++;
                if (value == 0x7f) {
                    run = *source++;
                    fill = *source++;
                    for (repeat = 0; repeat < run; repeat++) *(out + column + repeat) = fill;
                    column += run;
                } else {
                    *(out + column) = value;
                    column++;
                }
            }
            if (f10 == 4 || f10 == 5) {
                out += width - 1;
                for (repeat = 0; repeat < width; repeat++) *line++ = *out--;
            }
            if (f10 == 2) line += fe;
            else if (f10 == 4) line += fe - width;
            else if (f10 == 3) line += width;
        }
        if (f8 == 0) operator delete(source = saved);
    } else {
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( f4), length)));
        result = length;
    }

    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    *f11 = width;
    *f15 = height;
    return result;
}

//@ f_050580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest für das Teilbild p3 innerhalb der Grafikressource p2 ausschließlich dessen Breite und
 *   Höhe aus dem Archivkopf aus, ohne die Pixeldaten selbst zu laden oder zu entpacken.
 * - Eingaben und Rückgabe: Die Funktion erhält this, die Ressourcen-ID p2, den Teilbildindex p3 sowie die
 *   Ausgabeparameter p4 (Breite) und p5 (Höhe) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Je nach Archivtyp (type 0..5) werden Breite x und Höhe y aus dem ersten Tabelleneintrag
 *   oder aus dem zum Index fc = p3 gehörenden Tabelleneintrag gelesen und in *p4 und *p5 gespeichert.
 === Ende Beschreibung === */
void Cut::f_050580(unsigned p2, int p3, unsigned short *p4, unsigned short *p5)
{
    signed char type;
    short count;
    short y, x;
    short i;
    char *data;
    short size;

    if (f19 == 1 && p2 != 0) p2 |= 0x80000000;
    p2 = (p2 & 0) ? 0 : p2; // Haelt die Parameterkopie in eigenem Register
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( p2, 0x200);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &type), 1)));
    type &= 0x7f;
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &count), 2)));
    size = type == 0 ? 4 :
           type == 1 ? count * 4 :
           (type == 2 || type == 4) ? count * 4 + 4 : count * 8;
    data = f_014540((unsigned)size, d_1a1400, 0x15e);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( data), size)));
    fc = p3;
    switch ((unsigned char)type) {
    case 0:
        x = *(unsigned short *)data;
        y = *(unsigned short *)(data + 2);
        break;
    case 1:
        for (i = 0; i < fc; i++) { data = (char *)(((int)data & 0) ? 0 : (int)data); } // Haelt die Schleifenstruktur fuer data
        size = (size & 0) ? (short)0 : size; // Haelt die Lebensdauer von size
        x = *(unsigned short *)(data + fc * 4);
        y = *(unsigned short *)(data + fc * 4 + 2);
        break;
    case 2:
    case 4:
        x = *(unsigned short *)data;
        y = *(unsigned short *)(data + 2);
        break;
    case 3:
    case 5:
        x = *(unsigned short *)(data + fc * 8);
        y = *(unsigned short *)(data + fc * 8 + 2);
        break;
    }
    operator delete(data);
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    *p4 = x;
    *p5 = y;
}
