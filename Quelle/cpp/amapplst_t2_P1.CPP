/* === Beschreibung (Katalog) ===
 * Einheit amapplst_t2
 *
 * Diese kleinste Einheit (0x01bf70-0x01bf80) liegt unmittelbar vor ani_t1 und enthält den Timer-Rückruf, der den
 * Zeitzähler für die Ortsanimationen hochzählt.
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
extern volatile int d_1bc75c;   // BSS 0x1BC75C-0x1BC760; volatile erzeugt direktes inc auf dem Speicherort statt lea+mov
//@ f_01bf70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion wird als periodischer Timer-Rückruf (angemeldet in ani_t1 über f_01bfb0 beim
 *   Timer-Objekt d_1c2edc) aufgerufen, erhöht den globalen Animations-Tickzähler d_1bc75c um 1 und gibt dessen
 *   vorherigen Wert zurück.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den alten Zählerstand von d_1bc75c (int)
 *   zurück.
 * - Wichtige Variablen: Die globale Variable d_1bc75c (volatile int) zählt die seit dem letzten
 *   Animationsschritt (Ani::f_01c840) verstrichenen Zeiteinheiten.
 === Ende Beschreibung === */
int f_01bf70()
{
    return d_1bc75c++;
}
