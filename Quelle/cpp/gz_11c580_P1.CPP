/* === Beschreibung (Katalog) ===
 * Einheit gz_11c580 (0x11c760 - 0x11caf0)
 *
 * Überblick
 * Diese Einheit implementiert die Klasse StockCon (stockcon.cpp), die mehrere Gegenstandsbestände (Stock) in
 * einer gemeinsamen indizierten Archivdatei im Arbeitsverzeichnis verwaltet, einzelne Bestände bei Bedarf in den
 * Speicher lädt und veränderte Bestände unter dynamischer Anpassung der nachfolgenden Dateioffsets wieder
 * zurückschreibt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 10/11 gleich (suche.py 25.10.2026, Basis gz_11c580_P1.CPP)
// gz_11c580.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11C760-0x11C7C0 (I13 30.10.: 11C580-11C75F stehen in stock_neu = STOCK.CPP, Fable REST9)
#include <string.h>
int f_11c7c0(int p1);




struct N { char *data; N *prev; N *next; };
struct L { short count; N *head; N *tail; };
struct R { int a; void *b; int c; int d; };
//@ f_11c760
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor eines StockCon-Containers, der die Datei-ID speichert, die Anzahl der enthaltenen
 *   Bestände (n) aus dem Dateikopf liest und über f_11c7c0 die Offset-/Längentabelle aufbaut.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des StockCon-Objekts und in p2 die Datei-ID
 *   der Bestandsdatei.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
R *f_11c760(R *p1, int p2)
{
  p1->a = 0;
  p1->d = p2;
  ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( p2 | 0x40000000, 0x200);
  ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)&p1->c), 4)));
  ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
  f_11c7c0((int)p1);
  return p1;
}
//@ f_11c7b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor eines StockCon-Containers, der das im Speicher gehaltene Index-Array (index) freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des StockCon-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
R *f_11c7b0(R *p1, int p2)
{
  operator delete(p1->b);
  return p1;
}

// ===== Teil 2: stockcon (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// P3 1/3 gleich (suche.py 25.10.2026, Basis stockcon_P1.CPP)
// I9: aus STOCKCON.CPP uebernommen (Stufe-2-Stand), Marken 3 neu
// stockcon.cpp (0x11C760-0x11CAF0): Best?nde in einer Datei
// #include <string.h>
extern const char stockcon_file[] = "p:\\riva\\source\\cpp\\stockcon.cpp";   // 0x1A7DF8




struct Info { char b[27]; };
struct Item {
    short id;
    short amount;
    Info  info;
    Item();                                              // 0x0E0620 (08.11. Claude I15: Original-Konstruktor liegt als COMDAT bei 0xE0620, nicht in stockcon; Rumpf: id=0, amount=0, info genullt)
};
struct Node;
struct Stock {
    short count; Node *head; Node *tail; short pad; int locked;
    Stock(Item *tab, int x);                             // 0x11C0F0
    ~Stock();                                            // 0x11C120
    short f_11c320();
    void  f_11c2e0(Item *out);
};

 /* zusammengelegt: extern File (*(File *)&d_1c2098); */
struct Entry { long off; long len; };
struct StockCon {
    Stock *stock;                                        // +0x00
    Entry *index;                                        // +0x04
    long   n;                                            // +0x08
    long   fileid;                                       // +0x0C
    StockCon(long id);
    ~StockCon();
    void f_11c7c0();
    void f_11c8a0(short k);
    void f_11c980(short k);
};
// StockCon::StockCon und ~StockCon stehen als f_11c760/f_11c7b0 in Teil 1 (zusammengelegt 08.11., sonst doppelt)
/*
StockCon::StockCon(long id)
{
    stock = 0;
    fileid = id;
    (*(File *)&d_1c2098).f_1448b0(id | 0x40000000, 0x200);
    (*(File *)&d_1c2098).f_144920(&n, 4);
    (*(File *)&d_1c2098).f_1449a0();
    f_11c7c0();
}
StockCon::~StockCon()
{
    delete index;
}
*/
//@ f_11c7c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Allokiert das Index-Array für n Bestände, liest die aufeinanderfolgenden Startoffsets aus dem
 *   Dateikopf der Bestandsdatei ein und berechnet daraus Startoffset (off) und Bytegröße (len) jedes einzelnen
 *   Bestands.
 * - Eingaben: Die Funktion erhält implizit den this-Zeiger des StockCon-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void StockCon::f_11c7c0()
{
    short i = 0;
    unsigned long a = 0, b = 0;
    
    index = new (mark(stockcon_file, 73)) Entry[n];
    (*(RivaFileManager *)&d_1c2098).f_1448b0(fileid | 0x40000000, 0x200);
    (*(RivaFileManager *)&d_1c2098).f_144ab0(4, 0);
    (*(RivaFileManager *)&d_1c2098).f_144920(&a, 4);
    (*(RivaFileManager *)&d_1c2098).f_144920(&b, 4);
    while (i < n) {
        index[i].off = a;
        index[i].len = b - a;
        a = b;
        i++;
        (*(RivaFileManager *)&d_1c2098).f_144920(&b, 4);
    }
    (*(RivaFileManager *)&d_1c2098).f_1449a0();
}
//@ f_11c8a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Lädt den Bestand mit dem Index k (jeweils 31 Bytes pro Gegenstandseintrag) aus der Bestandsdatei und
 *   erzeugt daraus ein neues Stock-Objekt im Speicher.
 * - Eingaben: Die Funktion erhält implizit den this-Zeiger des StockCon-Objekts sowie im Parameter k den Index
 *   des zu ladenden Bestands.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void StockCon::f_11c8a0(short k)
{
    long off = index[k].off;
    unsigned long len = index[k].len;
    short cnt = len / 31;
    Item *tab = new (mark(stockcon_file, 105)) Item[cnt + 1];
    (*(RivaFileManager *)&d_1c2098).f_1448b0(fileid | 0x40000000, 0x200);
    (*(RivaFileManager *)&d_1c2098).f_144ab0(off, 0);
    (*(RivaFileManager *)&d_1c2098).f_144920(tab, len);
    (*(RivaFileManager *)&d_1c2098).f_1449a0();
    stock = new (mark(stockcon_file, 113)) Stock(tab, 0);
    delete tab;
}
//@ f_11c980
/* === Beschreibung (Katalog) ===
 * - Zweck: Schreibt den aktuell im Speicher bearbeiteten Bestand auf den Platz k in der Bestandsdatei zurück,
 *   vergrößert oder verkleinert bei geänderter Gegenstandsanzahl den Dateibereich vor Ort, aktualisiert alle
 *   nachfolgenden Offsets im Dateikopf und gibt das Stock-Objekt frei.
 * - Eingaben: Die Funktion erhält implizit den this-Zeiger des StockCon-Objekts sowie im Parameter k den Index
 *   des zurückzuschreibenden Bestands.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void StockCon::f_11c980(short k)
{
    int cnt = stock->f_11c320();
    unsigned long size = (unsigned long)cnt * 31;
    long diff = size - index[k].len;
    long off = index[k].off;
    Item *buf = 0;
    if (cnt > 0) {
        buf = new (mark(stockcon_file, 136)) Item[cnt];
        stock->f_11c2e0(buf);
    }
    delete stock;
    stock = 0;
    (*(RivaFileManager *)&d_1c2098).f_1448b0(fileid | 0x40000000, 0x202);
    if (diff > 0) (*(RivaFileManager *)&d_1c2098).f_144b70(off, 0, diff);
    else if (diff < 0) (*(RivaFileManager *)&d_1c2098).f_144bb0(off, -diff);
    if (buf) {
        (*(RivaFileManager *)&d_1c2098).f_144ab0(off, 0);
        (*(RivaFileManager *)&d_1c2098).f_144960(buf, size);
    }
    if (diff != 0 && k < n - 1) {
        (*(RivaFileManager *)&d_1c2098).f_144ab0(k * 4 + 8, 0);
        do {
            k++;
            index[k].off += diff;
            (*(RivaFileManager *)&d_1c2098).f_144960(&index[k].off, 4);
        } while (k < n - 1);
    }
    (*(RivaFileManager *)&d_1c2098).f_1449a0();
    if (buf) delete buf;
}
