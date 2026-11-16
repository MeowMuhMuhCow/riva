/* === Beschreibung (Katalog) ===
 * Einheit am01b3b0
 *
 * Diese kleine Einheit enthält den ersten Teil von amapplst.cpp (Adresse 0x01b3b0): das Löschen einer
 * Kartennotiz anhand ihrer Kartenkoordinaten, womit sie unmittelbar die Notizverwaltung aus gz_01a9b0 ergänzt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// P3 14/18 gleich (suche.py 25.10.2026, Basis amapplst_P1.CPP)
// amapplst.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01B3B0-0x01BF70
#include <string.h>
struct Dim { char pad[8]; short n; };
struct Ent { unsigned short a, b; char pad[8]; };
struct Lst { long x0; Dim *d; Ent *e; short s; };
struct Rec { signed char c; signed char a; signed char b; long pos; };
struct Hdr { long a; short b; short c; };
int f_01ae60(Lst *p1, int p2);

extern RivaFileManager d_1c2098;
extern long *d_1a04b0;
extern const char *d_1a04b4;
extern const char *d_1a965c;
extern const char d_1a0490[];
void f_01b420();
int f_01b4d0(Rec *p1);
int f_01b5a0(Rec *p1);
void f_01b610(Rec *p1);
void f_01b650(Rec *p1);
void f_01b680(Rec *p1);
void f_01b6a0(Rec *p1);
void f_01b6c0(Rec *p1);
#define WRITEREC(p) f_01b6c0(p)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_01b3b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion rundet die übergebenen Kartenpixel-Koordinaten (p2, p3) auf das 8x8-Pixel-Raster
 *   ab (& 0xfff8), sucht in der Eintragstabelle p1->e (0 .. p1->d->n - 1) nach einer Notiz an dieser Position
 *   und löscht sie bei einem Treffer (found >= 0) über f_01ae60(p1, found) (gz_01a9b0) aus Tabelle und
 *   Notizdatei; der Iterator p1->s wird anschließend auf -1 zurückgesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf die Kartennotiz-Verwaltung p1 (Lst *), die
 *   X-Koordinate p2 (unsigned short) und die Y-Koordinate p3 (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: p1->d->n (+0x08 im Kopfsatz) enthält die Anzahl der gespeicherten Notizen, p1->e (+0x08
 *   im Verwaltungsobjekt) zeigt auf das Array der 12-Byte-Notizeinträge und p1->s (+0x0c) ist der aktuelle
 *   Iteratorzähler.
 === Ende Beschreibung === */
void f_01b3b0(Lst *p1, unsigned short p2, short p3)
{
    Lst * q_ = p1;
    short found = -1;
    short i;
    // KRUECKE: Deklarationsfolge b/a, Maskenfolge a/b; Tie a vor b.
    short b;
    short a;
    a = p2 & 0xfff8;
    b = p3 & ~7;
    for (i = 0; i < q_->d->n; i++) {
        Ent *e = &q_->e[i];
        if (a == (short)e->a && (short)b == (short)e->b) { found = i; break; }
    }
    if (found >= 0) { f_01ae60(p1, found); p1->s = -1; }
}
