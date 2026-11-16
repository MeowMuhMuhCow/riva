/* === Beschreibung (Katalog) ===
 * Einheit mo_spell
 *
 * Diese Einheit gehört zu mo_spell.cpp und implementiert die Ausführung von Monster-Zaubersprüchen im
 * Rundenkampf, einschließlich der Berechnung der Astralpunktekosten, der Schadensanwendung auf Helden oder
 * andere Monster sowie des zentralen Spruch-Dispatchers f_0ceb00.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 6/7 gleich (suche.py 26.10.2026, Basis mo_spell_P1.CPP)
// mo_spell.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CE980-0x0CED30
#include <string.h>
typedef void (*FP)(void *);
typedef FP (*FP2)(void *);
struct S;
typedef void (S::*MPF)();
struct S { short w; MPF mp; int f0e; int f12; int f16; };
struct E { signed char v; char pad[7]; int y; };
signed char f_0cfd40(int p1);
int f_0d08a0(int p1);
int f_0d0910(int p1);
int f_0d0960(int p1, int p2, int p3);
int f_0d0a20(int p1, int p2);
int f_044300(int p1, int p2);
int f_09c800(int p1, int p2, int p3, int p4, int p5, int p6, int p7);

signed char f_0cfdc0(int p1);
short f_045660(int p1);
signed char f_0d1250(int p1);

signed char f_0cf950(int p1);
signed char f_145760(int p1, int p2);

int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
int f_0e93f0(int p1, int p2, int p3);
int f_145300(int p1, int p2, int p3);
extern struct E d_1a57e8[];
extern MPF d_1bf378[];
extern char d_1bd918;
extern char d_1c21b4;
extern int d_1c2d1c;
extern int d_1c38b0;
extern int d_1c0424;
extern int d_1bd914;
extern short d_1bd910;
extern int d_1c040e;
extern int d_1c0412;
extern unsigned short d_1a9820;

extern int d_1c2edc;
extern int d_1c0420;
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0ce980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt die Astralpunktekosten des Monster-Zauberspruchs a anhand der Spruchtabelle
 *   d_1a57e8, wobei im Falle eines misslungenen Zaubers (b != 0) halbe Kosten (bzw. bei variablen Kosten -1 ein
 *   Zufallswert von 5 bis 10 über f_145760(5, 10)) berechnet werden.
 * - Eingaben: Übergeben werden der Monster-Zauberspruch-Index a sowie das Fehlschlag-Flag b (0 für volle Kosten,
 *   != 0 für reduzierte Fehlschlagkosten).
 * - Rückgabewert: Zurückgegeben werden die berechneten Astralpunktekosten des Zaubers.
 === Ende Beschreibung === */
short f_0ce980(short a, int b)
{
    short b_ = b;
    signed char value = d_1a57e8[a].v;
    if (b_ != (short)0) {
        if (value == -1)
            return f_145760(5, 10);
        value = value / 2;
    }
    return value;
}
//@ f_0ce9d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor bzw. Initialisierer setzt in der Monster-Zauberkontextstruktur p das Ergebnisfeld
 *   p->w auf -1 und speichert den Zeiger auf den Zaubernden in p->f0e.
 * - Eingaben: Übergeben werden der Zeiger p auf die Zauberkontextstruktur sowie die Adresse value des zaubernden
 *   Kampfteilnehmers.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce9d0(struct S *p, int value)
{
    p->w = -1;
    p->f0e = value;
}
//@ f_0ce9e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist eine leere Platzhalter- oder Destruktorfunktion für die Monster-Zauberkontextstruktur ohne
 *   ausführbare Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce9e0()
{
}
//@ f_0ce9f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wendet n Punkte Zauberschaden auf das Ziel des Monster-Zaubers p an, zieht die
 *   Lebenspunkte je nach Zieltyp (f_0cfd40(p->f0e) == 2 für einen Helden p->f16 über f_044300, sonst für ein
 *   Monster p->f12 über f_0d0960) ab, spielt die Trefferanimation über f_09c800 ab und setzt beim Tod des Ziels
 *   das Flag d_1bd918 = 1.
 * - Eingaben: Übergeben werden der Zeiger p auf die Zauberkontextstruktur sowie die Schadenshöhe n.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce9f0(struct S *p, short n)
{
    if (n > 0) {
        if (f_0cfd40(p->f0e) == 2) {
            f_044300(p->f16, n);
            f_09c800((int)&d_1c2d1c, 0xb, n, 1, p->f0e, 2, p->f16);
            if (((signed char)(f_042470((struct hero *)(p->f16))))) d_1bd918 = 1;
        } else {
            f_0d0960(p->f12, n, 1);
            f_09c800((int)&d_1c2d1c, 0x17, n, 1, p->f0e, 1, p->f12);
            if (f_0cfdc0(p->f12)) d_1bd918 = 1;
        }
    }
}
//@ f_0ceaa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt abhängig vom Zieltyp (f_0cfd40(p->f0e) == 2 für Helden, sonst Monster) den
 *   Rüstungsschutz- oder Magieresistenzwert des Ziels (f_045660(p->f16) bzw. f_0d1250(p->f12)) zurück.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Zauberkontextstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der abgefragte Wert des anvisierten Helden oder Monsters.
 === Ende Beschreibung === */
short f_0ceaa0(struct S *p)
{
    if (f_0cfd40(p->f0e) == 2) return f_045660(p->f16);
    return f_0d1250(p->f12);
}
//@ f_0cead0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion fragt abhängig vom Zieltyp (f_0cfd40(p->f0e) == 2 für Helden, sonst Monster) die
 *   aktuelle Lebensenergie bzw. Eigenschaft des Ziels (f_0423f0(p->f16) bzw. f_0cf950(p->f12)) ab.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Zauberkontextstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der abgefragte Wert des Ziels.
 === Ende Beschreibung === */
short f_0cead0(struct S *p)
{
    if (f_0cfd40(p->f0e) == 2) return f_0423f0((struct hero *)(p->f16));
    return f_0cf950(p->f12);
}
//@ f_0ceb00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Funktion führt den Monster-Zauberspruch n für den Kontext p aus, indem sie das
 *   Zielobjekt (p->f16 oder p->f12) bestimmt, die zugehörige Spruchmethode aus der Tabelle d_1bf378[n] aufruft,
 *   den passenden Zaubersound (d_1a57e8[n].y oder Standard 0x170004) abspielt und abhängig vom Ergebniscode p->w
 *   die vollen, halben oder individuell berechneten Astralpunkte über f_0d0a20 vom Zaubernden abzieht.
 * - Eingaben: Übergeben werden der Zeiger p auf die Monster-Zauberkontextstruktur sowie die Zauberspruch-Nummer
 *   n.
 * - Rückgabewert: Zurückgegeben wird 1 bei erfolgreichem Zauber, 0 bei kostenfreiem Abbruch (p->w == -4) oder -1
 *   bei einem Fehlschlag (p->w == 0 oder -2).
 === Ende Beschreibung === */
short f_0ceb00(struct S *p, short n)
{
    short t;
    signed char c;
    int v;
    short ret = 1;
    d_1c21b4 = 0;
    c = d_1a57e8[n].v; t = c;
    if (f_0cfd40(p->f0e) == 2) p->f16 = f_0d08a0(p->f0e);
    else p->f12 = f_0d0910(p->f0e);
    p->mp = d_1bf378[n];
    (p->*(p->mp))();
    if (p->w != 0 && p->w != -4 && d_1c0424 == 0 && d_1a57e8[n].y != 0 && (d_1bd914 == 0 || d_1bd910 == 1)) {
        if (((RivaFileManager*)((int)&d_1c2098))->f_144870( d_1a57e8[n].y) != 0)
            f_147323((int)&d_1c2edc, d_1a57e8[n].y, 0x7fff, 0x8000, (v = *(int *)&d_1a9820), 0, 1);
        else
            f_147323((int)&d_1c2edc, 0x170004, 0x7fff, 0x8000, (v = *(int *)&d_1a9820), 0, 1);
    }
    if (p->w == 0) {
        ret = -1;
        d_1c040e = 1;
    } else if (p->w == -2) {
        signed char c = d_1a57e8[n].v;
        signed char v;
        if (c == -1) v = f_145760(5, 10);
        else v = c / 2;
        f_0d0a20(p->f0e, v);
        f_0e93f0((int)&d_1c38b0, (int)&d_1c21b4, 0x170000ef);
        ret = -1;
    } else if (p->w == -4) {
        ret = 0;
        d_1c040e = 1;
    } else if (p->w == -1) {
        f_0d0a20(p->f0e, t);
        d_1c0412 = 1;
    } else {
        f_0d0a20(p->f0e, p->w);
        d_1c0412 = 1;
    }
    f_145300((int)&d_1c0420, 0, 0xb);
    return ret;
}
