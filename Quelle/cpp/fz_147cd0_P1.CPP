/* === Beschreibung (Katalog) ===
 * Einheit fz_147cd0 (0x147CD0 - 0x148143)
 *
 * Überblick
 * Diese Einheit implementiert die C++-Wrapper-Klasse P (powerpak.cpp) rund um die in Assembler geschriebenen
 * LZW-/PowerPack-Kompressions- und Dekompressionsroutinen (f_169a29, f_169a33, f_169c34, f_169c3a, f_169c99).
 * Sie wird im gesamten Spiel verwendet, um gepackte Spielstände, AIF-Grafiken (Typ 3) und Archivressourcen
 * wahlweise zwischen Speicherpuffern oder direkt über Dateiobjekte (RivaFile) zu komprimieren und zu entpacken.
 === Ende Beschreibung === */
// P3 19/20 gleich (suche.py 25.10.2026, Basis fz_147cd0_P1.CPP)
// fz_147cd0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x147CD0-0x148143
#include <string.h>
#include "RIVAMEM.H"



int f_1664d0(const char *msg, const char *file, int line);
int f_169a29(int p1, int p2);
int f_169a33(int p1, int p2, int p3);
int f_169c34(int p1, int p2);
int f_169c3a(int p1);
int f_169c99(void *p);
extern const char d_1a9838[];
extern const char d_1b8ac8[];
extern const char d_1b8aed[];
extern const char d_1b8afa[];

struct P {
    short mode;
    short kind;
    int f4;
    int f8;
    short t[12];
    int f24;
    char pad28[4];
    short s2c;
    char pad2e[0x3c - 0x2e];
    int f3c;
    int f40;
    int f44;
    char *f48;
    int f4c;
    char *f50;
    int f54;
    short s58;
    char pad5a[0x260 - 0x5a];
    short s260;
    int f262;
    void f_147f10();
};
int f_147f60(P *p, int m);

//@ f_147cd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des PowerPack-Komprimier-/Entpack-Objekts P. Er trägt die virtuelle
 *   Methodentabelle (d_1a991c) ein und initialisiert alle internen Puffer-, Dateizeiger- und Statusfelder auf 0
 *   sowie die Standard-Blockgröße (I(0x28)) auf 0x800 (2048 Bytes).
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Gibt p zurück.
 * - Wichtige Variablen: I(0x28) (Chunk-Größe 0x800 für gepuffertes Nachlesen/Schreiben), B(0x04)
 *   (Initialisierungsflag).
 === Ende Beschreibung === */
void f_147cd0(P *p)
{
    p->mode = 5;
    p->kind = 3;
    p->f4 = 0;
    p->f8 = 0;
    p->f262 = 0;
    p->s260 = 0;
}
//@ f_147d00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Kompressionsmodus p->mode (Wörterbuchgröße 0..4) im PowerPack-Objekt p und löst
 *   bei einem ungültigen Wert außerhalb von 0..4 einen Laufzeitfehler (f_1664d0) aus.
 * - Eingaben: p (Zeiger auf das P-Objekt), m (Modus 0..4).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->mode.
 === Ende Beschreibung === */
void f_147d00(P *p, short m)
{
    if (m < 0 || m > 4) f_1664d0(d_1b8ac8, d_1a9838, 0x1d);
    p->mode = m;
}
//@ f_147d30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den aktuell eingestellten Kompressionsmodus p->mode des PowerPack-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Der 16-Bit-Moduswert p->mode (short).
 * - Wichtige Variablen: p->mode.
 === Ende Beschreibung === */
short f_147d30(P *p) { return p->mode; }
//@ f_147d40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt den 32-Bit-Wert v in das Status-/Größenfeld p->f4 des PowerPack-Objekts p ein.
 * - Eingaben: p (Zeiger auf das P-Objekt), v (zu speichernder Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->f4.
 === Ende Beschreibung === */
void f_147d40(P *p, int v) { p->f4 = v; }
//@ f_147d50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 32-Bit-Wert p->f4 aus dem PowerPack-Objekt p aus.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Der gespeicherte Wert p->f4 (int).
 * - Wichtige Variablen: p->f4.
 === Ende Beschreibung === */
int f_147d50(P *p) { return p->f4; }
//@ f_147d60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die zuletzt ermittelte oder erzeugte Datenlänge p->f8 des PowerPack-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Der 32-Bit-Wert p->f8 (int).
 * - Wichtige Variablen: p->f8.
 === Ende Beschreibung === */
int f_147d60(P *p) { return p->f8; }
//@ f_147d70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Längenfeld p->f8 im PowerPack-Objekt p auf den Wert v.
 * - Eingaben: p (Zeiger auf das P-Objekt), v (neuer Längenwert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->f8.
 === Ende Beschreibung === */
void f_147d70(P *p, int v) { p->f8 = v; }
//@ f_147d80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Speicher- bzw. Pufferart p->kind (0..3) des PowerPack-Objekts p auf (short)v.
 * - Eingaben: p (Zeiger auf das P-Objekt), v (gewünschte Pufferart).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->kind.
 === Ende Beschreibung === */
void f_147d80(P *p, int v) { p->kind = (short)v; }
//@ f_147d90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die eingestellte Pufferart p->kind des PowerPack-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Der 16-Bit-Wert p->kind (short).
 * - Wichtige Variablen: p->kind.
 === Ende Beschreibung === */
short f_147d90(P *p) { return p->kind; }
//@ f_147da0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Fehler-/Statusflag p->s260 des PowerPack-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Der 16-Bit-Statuswert p->s260 (short).
 * - Wichtige Variablen: p->s260.
 === Ende Beschreibung === */
short f_147da0(P *p) { return p->s260; }
//@ f_147db0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert einen Callback- oder Kontextwert v im Feld p->f262 des PowerPack-Objekts p.
 * - Eingaben: p (Zeiger auf das P-Objekt), v (32-Bit-Wert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->f262.
 === Ende Beschreibung === */
void f_147db0(P *p, int v) { p->f262 = v; }
//@ f_147dc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft die Assembler-Routine f_169a29(p2, p3) zur Ermittlung von Header-Informationen eines
 *   gepackten Blocks auf.
 * - Eingaben: p1 (this-Zeiger, ungenutzt), p2 (erster Parameter für f_169a29), p3 (zweiter Parameter).
 * - Rückgabewert: Rückgabewert von f_169a29.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_147dc0(int p1, int p2, int p3) { return f_169a29(p2, p3); }
//@ f_147dd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft die Assembler-Routine f_169c34(p2, p3) zur Initialisierung bzw. Abfrage eines
 *   Kompressionsblocks auf.
 * - Eingaben: p1 (this-Zeiger, ungenutzt), p2 (erster Parameter für f_169c34), p3 (zweiter Parameter).
 * - Rückgabewert: Rückgabewert von f_169c34.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_147dd0(int p1, int p2, int p3) { return f_169c34(p2, p3); }
//@ f_147de0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert die Startadresse des eingebetteten 596-Byte-Arbeitskontexts ((char *)p + 0x0c)
 *   innerhalb des PowerPack-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das P-Objekt).
 * - Rückgabewert: Zeiger auf (char *)p + 0x0c.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
char *f_147de0(P *p) { return (char *)p + 0xc; }
//@ f_147df0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bereitet den Arbeitskontext (char *)p + 0x0c für das Komprimieren eines Speicherblocks
 *   (data der Länge len) vor, reserviert über f_147f60 die LZW-Tabellenpuffer (bei p->kind == 3 mit
 *   automatischem Rückfall von Stufe 0 über 1 auf 2), führt die Kompression über f_169c99 aus und gibt die
 *   Arbeitspuffer anschließend über f_147f10 wieder frei.
 * - Eingaben: p (Zeiger auf das P-Objekt), data (Quellpufferadresse), len (Eingabelänge in Bytes).
 * - Rückgabewert: Größe der komprimierten Daten in Bytes (p->f8) oder 0 bei Speichermangel (p->s260 = 1).
 * - Wichtige Variablen: ok (Erfolgsflag der Pufferreservierung), p->f3c (Startadresse), p->f40 (Länge), p->f44
 *   (Endadresse).
 === Ende Beschreibung === */
int f_147df0(P *p, int data, int len)
{
    int ok = 0;

    if (data == 0) f_1664d0(d_1b8aed, d_1a9838, 0x74);
    if (len == 0) f_1664d0(d_1b8afa, d_1a9838, 0x75);

    memset((char *)p + 0xc, 0, 0x254);
    p->f24 = p->f262;

    if (*(volatile short *)&p->kind == 3) { // verhindert CSE-Wiederverwendung von p->kind im else-Zweig
        if (f_147f60(p, 0)) {
            ok = 1;
        } else if (f_147f60(p, 1)) {
            ok = 1;
        } else if (f_147f60(p, 2)) {
            ok = 1;
        }
    } else {
        P *target = p;
        if (f_147f60(target, p->kind)) ok = 1;
    }

    if (ok == 1) {
        p->f3c = data;
        p->f40 = len;
        p->f44 = data + len;
        len = f_169c99((char *)p + 0xc);
        p->f_147f10();
    } else {
        len = 0;
        p->s260 = 1;
    }

    p->f8 = len;
    return len;
}
//@ f_147ef0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entpackt einen mit PowerPack komprimierten Speicherblock (p3, Gesamtlänge p4) in den
 *   Zielpuffer p2, indem die Assembler-Entpackroutine f_169a33(p3 + p4, p2, p3 + 4) aufgerufen wird.
 * - Eingaben: p1 (this-Zeiger), p2 (Zielpuffer), p3 (komprimierter Quellpuffer), p4 (komprimierte Größe in
 *   Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_147ef0(int p1, int p2, int p3, int p4)
{
    f_169a33(p3 + p4, p2, p3 + 4);
}
//@ f_147f00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leitet als Wrapper direkt auf die Assembler-Hilfsfunktion f_169c3a(p3) weiter.
 * - Eingaben: p1 (this-Zeiger), p2 (ungenutzt), p3 (Parameter für f_169c3a).
 * - Rückgabewert: Rückgabewert von f_169c3a(p3).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_147f00(int p1, int p2, int p3) { return f_169c3a(p3); }
//@ f_147f10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die beiden dynamisch allozierten LZW-Arbeitspuffer p->f50 und p->f48 des
 *   PowerPack-Objekts wieder frei und setzt ihre Zeiger auf 0.
 * - Eingaben: this (Zeiger auf das P-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: f50, f48.
 === Ende Beschreibung === */
void P::f_147f10() { if (f50) { delete f50; f50 = 0; } if (f48) { delete f48; f48 = 0; } }
//@ f_147f60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet abhängig vom eingestellten Modus p->mode (0..4) die Bitbreiten (9..13 Bit) und
 *   Tabellengrößen (1 << a bis 1 << c) im Array p->t und reserviert die beiden LZW-Arbeitspuffer p->f48 (sz1
 *   Bytes) und p->f50 (0x30000 bzw. 0x400 Bytes je nach Speichermodus m).
 * - Eingaben: p (Zeiger auf das P-Objekt), m (Speicher-/Tabellenmodus 0, 1 oder 2).
 * - Rückgabewert: 1, wenn beide Arbeitspuffer erfolgreich reserviert wurden, sonst 0.
 * - Wichtige Variablen: a, b, c, d (Bitbreiten), w (1 << c), sz1 und sz2 (Größen der beiden Arbeitspuffer).
 === Ende Beschreibung === */
int f_147f60(P *p, int m) {
    short a = 9, b = 10, c = 11, d = 11;
    int r;
    switch (p->mode) {
    case 0:
        b = d = c = 9;
        break;
    case 1:
        d = c = 10;
        break;
    case 3:
        c = 12;
        d = 12;
        break;
    case 4:
        c = 13;
        d = 12;
        break;
    case 2:
        break;
    }
    short *q = p->t;
    *q++ = a;
    *q++ = b;
    *q++ = d;
    *q++ = c;
    *q++ = (short)(1 << a);
    *q++ = (short)(1 << b);
    *q++ = (short)(1 << d);
    short w = (short)(1 << c);
    *q++ = w;
    *q++ = 0;
    *q++ = 1;
    *q++ = 2;
    int sz1, sz2;
    sz2 = 0x30000;
    *q++ = 3;
    p->s2c = w;
    p->s58 = m;
    sz1 = (unsigned short)w * 8;
    if (m == 2) sz1 = (unsigned short)w * 4;
    if (m != 0) sz2 = 0x400;
    p->f4c = sz1 / 4;
    p->f54 = sz2 / 4;
    p->f48 = new (mark(d_1a9838, 0xf9)) char[sz1];
    p->f50 = new (mark(d_1a9838, 0xfa)) char[sz2];
    if (!p->f48 || !p->f50) {
        p->f_147f10();
        r = 0;
    } else {
        r = 1;
    }
    return r;
}
//@ f_148130
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt den Eingabebereich (a, Länge b, Ende a + b) in die Felder f3c, f40 und f44 des
 *   bereits initialisierten PowerPack-Objekts p ein und startet unmittelbar den Assembler-Lauf f_169c99((char
 *   *)p + 0x0c).
 * - Eingaben: p (Zeiger auf das P-Objekt), a (Pufferadresse), b (Datenlänge).
 * - Rückgabewert: Rückgabewert von f_169c99.
 * - Wichtige Variablen: p->f3c, p->f40, p->f44.
 === Ende Beschreibung === */
int f_148130(P *p, int a, int b)
{
    p->f3c = a;
    p->f40 = b;
    p->f44 = a + b;
    return f_169c99((char *)p + 0xc);
}
