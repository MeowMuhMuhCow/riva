/* === Beschreibung (Katalog) ===
 * Einheit gz_131a70_t2 (0x131BB0 - 0x131F30)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil des Übergangsmoduls vor tower4.cpp und enthält die globale Registrierung
 * der Speicherstand-Statusflags für die vierte Ebene des Magierturms, eine Prüfroutine für das
 * Drei-Zellen-Rätsel sowie den Konstruktor des Ebenen-Objekts für die vierte Turmebene.
 === Ende Beschreibung === */
// P1 6/7 gleich
// gz_131a70.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x131A70-0x131F30
#include <string.h>
#include "RIVAMEM.H"



void f_014710(void *p);
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
extern void f_131a10(void);
int f_039660(int p1, int p2);
short f_0398c0(int p1, int p2, int p3);
int f_039b00(int p1, int p2, int p3);
int f_0390a0(int p1);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0de7c0(int p1);
int f_145234(int p1, int p2);
int f_145254();
extern char d_1bbbc4[];
extern char d_1bbc1c[];
extern char d_1bfdbc[];
extern int d_1c0004;
extern signed char d_1c0d98;
extern short d_1c0d99;
extern signed char d_1c0d9c;
extern short d_1c0d9d;
extern signed char d_1c0da0;
extern short d_1c0da1;
extern signed char d_1c0da4;
extern short d_1c0da5;
extern signed char d_1c0da8;
extern short d_1c0da9;
extern signed char d_1c0dac;
extern short d_1c0dad;
extern signed char d_1c0db0;
extern short d_1c0db1;
extern signed char d_1c0db4;
extern short d_1c0db5;
extern signed char d_1c0db8;
extern short d_1c0db9;
extern signed char d_1c0dbc;
extern short d_1c0dbd;
extern signed char d_1c0dc0;
extern short d_1c0dc1;
extern signed char d_1c0dc4;
extern short d_1c0dc5;
extern signed char d_1c0dc8;
extern short d_1c0dc9;
extern signed char d_1c0dcc;
extern short d_1c0dcd;
extern signed char d_1c0dd0;
extern short d_1c0dd1;
extern short d_1c212a;
extern char **d_1c212c;
extern char d_1c2538[];
extern char d_1c2c64[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c3498[];
#define I(p, o) (*(int *)((int)(p) + (o)))
#define EQI(x,v) (((x)==(v))?1:0)
#define EQ2(x) EQI(x,1)

//@ f_131bb0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Registriert beim Spielstart die 15 persistenten Statusflags der vierten Magierturmebene
 *   (d_1c0d98 bis d_1c0dd0, mit den Kennungen 0xe1 bis 0xe8 sowie 0x232 bis 0x238) in der globalen
 *   Speicherstand-Tabelle (d_1c212a/d_1c212c) und setzt ihre Anfangswerte auf 0.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Die globalen Flag-Strukturen (d_1c0d98 bis d_1c0dd0) speichern unter anderem den Zustand
 *   der drei magischen Gefängniszellen (d_1c0da0, d_1c0da4, d_1c0da8), den Zähler für den
 *   "Achtkantinbus"-Schlüssel (d_1c0d98) sowie den Endkampf-Status (d_1c0dac, d_1c0db0, d_1c0dd0).
 === Ende Beschreibung === */
struct R131bb0 { char v; short id; };
inline void put131bb0(R131bb0 *p, short *n, int * &t, short k, char v)
{ p->v = v; p->id = k; t[++*n] = (int)p; }
inline void first131bb0(R131bb0 *p, short *n, int * &t, short k, char v)
{ p->v = v; p->id = k; t[*n] = (int)p; }
struct RR700V3_131bb08;
struct OR700V3_131bb08 { signed char flag; short number; char pad; OR700V3_131bb08 *init(RR700V3_131bb08 &r,short id,signed char f); };
struct RR700V3_131bb08 { short count; OR700V3_131bb08 **list; void append(OR700V3_131bb08 *o) {list[count]=o;count++;} };
inline OR700V3_131bb08 *OR700V3_131bb08::init(RR700V3_131bb08 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_131bb08 regR700V3_131bb08;
#pragma aux regR700V3_131bb08 "d_1c212a"
extern OR700V3_131bb08 obR700V3_131bb0_1c0d98;
#pragma aux obR700V3_131bb0_1c0d98 "d_1c0d98"
extern OR700V3_131bb08 obR700V3_131bb0_1c0d9c;
#pragma aux obR700V3_131bb0_1c0d9c "d_1c0d9c"
extern OR700V3_131bb08 obR700V3_131bb0_1c0da0;
#pragma aux obR700V3_131bb0_1c0da0 "d_1c0da0"
extern OR700V3_131bb08 obR700V3_131bb0_1c0da4;
#pragma aux obR700V3_131bb0_1c0da4 "d_1c0da4"
extern OR700V3_131bb08 obR700V3_131bb0_1c0da8;
#pragma aux obR700V3_131bb0_1c0da8 "d_1c0da8"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dac;
#pragma aux obR700V3_131bb0_1c0dac "d_1c0dac"
extern OR700V3_131bb08 obR700V3_131bb0_1c0db0;
#pragma aux obR700V3_131bb0_1c0db0 "d_1c0db0"
extern OR700V3_131bb08 obR700V3_131bb0_1c0db4;
#pragma aux obR700V3_131bb0_1c0db4 "d_1c0db4"
extern OR700V3_131bb08 obR700V3_131bb0_1c0db8;
#pragma aux obR700V3_131bb0_1c0db8 "d_1c0db8"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dbc;
#pragma aux obR700V3_131bb0_1c0dbc "d_1c0dbc"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dc0;
#pragma aux obR700V3_131bb0_1c0dc0 "d_1c0dc0"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dc4;
#pragma aux obR700V3_131bb0_1c0dc4 "d_1c0dc4"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dc8;
#pragma aux obR700V3_131bb0_1c0dc8 "d_1c0dc8"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dcc;
#pragma aux obR700V3_131bb0_1c0dcc "d_1c0dcc"
extern OR700V3_131bb08 obR700V3_131bb0_1c0dd0;
#pragma aux obR700V3_131bb0_1c0dd0 "d_1c0dd0"
void f_131bb0(void) {
obR700V3_131bb0_1c0d98.init(regR700V3_131bb08,0xe1,0);
obR700V3_131bb0_1c0d9c.init(regR700V3_131bb08,0xe2,0);
obR700V3_131bb0_1c0da0.init(regR700V3_131bb08,0xe3,0);
obR700V3_131bb0_1c0da4.init(regR700V3_131bb08,0xe4,0);
obR700V3_131bb0_1c0da8.init(regR700V3_131bb08,0xe5,0);
obR700V3_131bb0_1c0dac.init(regR700V3_131bb08,0xe6,0);
obR700V3_131bb0_1c0db0.init(regR700V3_131bb08,0xe7,0);
obR700V3_131bb0_1c0db4.init(regR700V3_131bb08,0xe8,0);
obR700V3_131bb0_1c0db8.init(regR700V3_131bb08,0x232,0);
obR700V3_131bb0_1c0dbc.init(regR700V3_131bb08,0x233,0);
obR700V3_131bb0_1c0dc0.init(regR700V3_131bb08,0x234,0);
obR700V3_131bb0_1c0dc4.init(regR700V3_131bb08,0x235,0);
obR700V3_131bb0_1c0dc8.init(regR700V3_131bb08,0x236,0);
obR700V3_131bb0_1c0dcc.init(regR700V3_131bb08,0x237,0);
obR700V3_131bb0_1c0dd0.init(regR700V3_131bb08,0x238,0);
}

//@ f_131e90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft im Drei-Zellen-Rätsel der vierten Turmebene, ob das zugehörige Kampfereignis noch
 *   nicht ausgelöst wurde (d_1c0dd0 == 0) und gleichzeitig mindestens zwei der drei Zellen-Statusflags
 *   (d_1c0da0, d_1c0da4, d_1c0da8) auf 1 stehen.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt 1 zurück, wenn d_1c0dd0 == 0 ist und mindestens zwei der drei Zellenflags aktiv sind,
 *   sonst 0.
 * - Wichtige Variablen: Der lokale Zähler n summiert die aktiven Flags unter d_1c0da0, d_1c0da4 und d_1c0da8.
 === Ende Beschreibung === */
int f_131e90(void)
{
    int r = 0;
    short n;
    if (EQI(d_1c0dd0, 0)) {
        n = 0;
        if (EQ2(d_1c0da0)) n = 1;
        if (EQ2(d_1c0da4)) n++;
        if (EQ2(d_1c0da8)) n++;
        if (n >= 2) r = 1;
    }
    return r;
}
//@ f_131f10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert als Konstruktor das Ebenen-Objekt (p1) für die vierte Ebene des Magierturms
 *   (Ebene 0x16), indem der Basisklassen-Konstruktor (f_05ff60) aufgerufen und die virtuelle Methodentabelle der
 *   vierten Turmebene (d_1bbc1c) eingetragen wird.
 * - Eingaben: Ein Zeiger auf das zu initialisierende Ebenen-Objekt (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: r speichert den vom Basisklassen-Konstruktor initialisierten Objektzeiger, dessen
 *   Vtable-Zeiger bei Offset +8 auf d_1bbc1c gesetzt wird.
 === Ende Beschreibung === */
void f_131f10(int p1)
{
    int r = f_05ff60(p1, 0x16);
    I(r, 8) = (int)d_1bbc1c;
}
