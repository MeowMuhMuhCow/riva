/* === Beschreibung (Katalog) ===
 * Einheit fi_large_t1 (0789b0 - 079e80)
 *
 * Überblick
 * Der erste Teil von fi_large (*Fight Large Monsters*) implementiert die spezielle Kampfgrafik, KI-Entscheidung
 * und Angriffsabwicklung für übergroße Endgegner (insbesondere den Riesendrachen/Wurm 'R' und die
 * Wurmkönigin/Großwesen 'S' und 'T'), die mehrere Felder belegen und Flächenangriffe, Fernangriffe sowie
 * Spezialzauber gegen mehrere Helden gleichzeitig einsetzen können.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 9/14 gleich (suche.py 26.10.2026, Basis fi_large_t1_P1.CPP)
// fi_large.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0789B0-0x07A470
#include <string.h>
typedef char FC;
#include "RIVAMEM.H"

int f_014540(int p1, int p2, int p3);
int f_02ffa0(int p1);
int f_038be0(int p1);
int f_038c80(int p1);
int f_0391b0(int p1, int p2);
signed char f_043450(int p1);
int f_043460(int p1, int p2);
signed char f_043dc0(int p1);
int f_044300(int p1, int p2);
int f_069460();
int f_069be0(int p1);
int f_06a6a0(int p1, int p2);
int f_06a6c0(int p1, int p2);
int f_06a6e0(int p1, int p2, int p3);
int f_06c930(int p1, int p2, int p3, int p4, int p5);
int f_06d580(int p1, int p2, int p3);
int f_06daa0(int p1, int p2, int p3);
int f_06ed10(int p1, int p2, int p3);
int f_06efc0(int p1, int p2, int p3);
int f_06f5c0(int p1, int p2, int p3);
int f_06f690(int p1, int p2, int p3);
int f_071e90(int p1, int p2, int p3);
int f_0728f0(int p1);
int f_072940(int p1);
int f_0729c0(int p1);
int f_0735b0(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0757f0(int p1);
int f_0758b0(int p1);
int f_075f10(int p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0765a0(int p1);
int f_07b540(int p1);
int f_07bd30(int p1, int p2, int p3);
#pragma aux f_07beb0 parm [eax edx] modify exact [eax edx];
int f_07beb0(int p1, int p2);
int f_07ea60(int p1, int p2);
int f_07eba0(int p1, int p2, int p3);
unsigned char f_07ec10(int p1, int p2);
int f_09c780(int p1);
int f_09c800(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_09c990(int p1);
int f_0bf730(int p1, int p2);
unsigned char f_0cf930(int p1);
short f_0cfa10(int p1);
int f_0cfc50(int p1);
int f_0cfc60(int p1, int p2);
int f_0cfc70(int p1);
int f_0cfcb0(int p1, int p2);
signed char f_0cfce0(int p1);
int f_0cfcf0(int p1, int p2);
int f_0cfd10(int p1, int p2);
int f_0cfd30(int p1, int p2);
unsigned char f_0cfd70(int p1);
int f_0cfd90(int p1, int p2);
int f_0cfdd0(int p1, int p2);
signed char f_0d0160(int p1);
int f_0d04e0(int p1);
int f_0d0710(int p1);
int f_0d08a0(int p1);
int f_0d08e0(int p1, int p2);
int f_0d0a60(int p1, int p2);
short f_0d0bb0(int p1, int p2, int p3);
int f_0d10c0(int p1, int p2);
FC f_0d11e0(int p1);
int f_0d4a10(int p1);
unsigned char f_0d54c0(int p1);
short f_0de4d0(int p1);
int f_0e9300(int p1, int p2, int p3);
int f_133fe0(int p1, int p2);
int f_1457e0(int p1);
extern short d_1a1d84[];
extern short d_1a1d98[];
extern short d_1a1e44[];
extern short d_1a1e80[];
extern short d_1a1e9a[];
extern int d_1bc8f0;
extern signed char d_1bd90c;
extern char d_1bd918;
extern signed char d_1bd928;
extern unsigned char *d_1bd984;
extern int d_1bda60;
extern int d_1bda64;
extern short d_1bda74;
extern int d_1bda78[7];
extern int d_1bda94[7];
extern int d_1bda98;
extern int d_1bda9c;
extern int d_1bdaa0;
extern int d_1bdaa4;
extern int d_1bdaa8;
extern int d_1bdaac;
extern int d_1c0004;
extern int d_1c0424;
extern char d_1c21b4[];
extern int d_1c2c64;
extern int d_1c2d1c;
extern int d_1c3498;
extern int d_1c38b0;
extern const char d_1a1d64[];
typedef unsigned char u8;
typedef signed char s8;
struct Obj { Obj *f_06a6e0(int a, int b); };
#define CT ((int)&d_1c2d1c)
void f_078f60(int p1, int p2);
void f_0791f0(int p1, int p2, int p3);
void f_079670(int p1, int p2, int p3);
void f_0799c0(int p1, int p2);

//@ f_0789b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt für einen übergroßen Endgegner h (f_0d06c0(h) != 0) das Animations- und Renderobjekt Y
 *   auf der Koordinate (x, y) mit höchster Priorität (0xff) in der Renderliste g + 0x39 an.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger g, den Monsterzeiger h sowie die Rasterkoordinaten x und y
 *   (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Trägt das erzeugte Objekt Y in g + 0x211 ein und verknüpft die Renderlisten-ID über
 *   f_0cfc60 mit dem Monster.
 === Ende Beschreibung === */
struct Y { char b[0xf4]; Y(void *a, int f); ~Y(); };

void f_0789b0(char *g, char *h, short x, short y)
{
    Y *p;
    signed char n;
    unsigned char v;
    p = new (mark(d_1a1d64, 0x43)) Y((void *)(g + 0x45), 1);
    n = *(signed char *)(g + 0x291);
    ++*(signed char *)(g + 0x291);
    *(int *)(g + n * 4 + 0x211) = (int)p;
    *(int *)(g + 0x27) = (int)p;
    *(char *)(g + 0x1f) = x;
    *(char *)(g + 0x18) = x;
    *(char *)(g + 0x20) = y;
    *(char *)(g + 0x19) = y;
    unsigned row = y * 25;
    // Haelt die Registerwahl fuer y und row wie im Original.
    y = (short)((y & 0) ? (short)0 : y);
    v = *(d_1bd984 + row + x);
    *(char *)(g + 0x26) = v;
    *(char *)(g + 0x25) = 0xff;
    *(char *)(g + 0x24) = 1;
    *(int *)(g + 0x1a) = f_0728f0((int)h);
    *(int *)(g + 0x2b) = 0;
    *(char *)(g + 0x22) = 0xff;
    *(char *)(g + 0x23) = 1;
    f_0cfc60((int)h, f_07ec10((int)(g + 0x39), -1));
}

//@ f_078a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Passt in speziellen Großgegner-Kämpfen anhand der Kampfnummer *(p + 0x1ea) die
 *   Zeichenkoordinaten (*x, *y) bzw. Animationsflags (f_06a6a0) eines Renderknotens n an.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p, den Renderknoten n sowie die Koordinatenzeiger x und y
 *   (short *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Wertet *(unsigned short *)(p + 0x1ea) für die Fälle 0, 1 und 2 aus.
 === Ende Beschreibung === */
void f_078a90(int p, int n, short *x, short *y)
{
    unsigned short v = *(unsigned short *)(p + 0x1ea);
    switch (v) {
    case 0:
        *x = v;
        *y = v;
        break;
    case 1:
        f_06a6a0(*(int *)(n + 0x0f), 1);
        break;
    case 2:
        return;
    }
}

//@ f_078ab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt in der aktuellen Implementierung konstant 0 zurück (Hookschnittstelle für Spezialeffekte
 *   bei Großgegnern während f_0765a0).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Renderknoten p2 und gibt immer 0 (int) zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_078ab0(int p1, int p2)
{
    return 0;
}

//@ f_078ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Modifiziert die prozentuale Treffer- bzw. Zielwahrscheinlichkeit p3 eines Großgegner-Angriffs
 *   auf einen Helden p2 abhängig von Gruppengeschwindigkeit (f_0de4d0), Körperhaltung/Status des Helden
 *   (f_043450, f_042560) und Deckungs-/Schutzstatus (f_043dc0 halbiert bzw. drittelt die Chance).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Heldenzeiger p2 sowie den Basisprozentwert p3
 *   (short) und gibt den angepassten Prozentwert (short) zurück.
 * - Wichtige Variablen: Nutzt die Heldenstatus-Abfragen f_043450, f_042560 und f_043dc0.
 === Ende Beschreibung === */
short f_078ac0(int p1, int p2, short p3)
{
    short t_152 = f_0de4d0(d_1c0004);
    if (t_152 == (short)-5) p3 = p3 - 2;
    if (f_043450(p2) == 1) p3 = p3 + 2;
    if (((signed char)(f_042560((struct hero *)(p2)))) == 1) p3 = p3 - 3;
    if (f_043dc0(p2) == 1) { short sVar6 = p3; sVar6 /= (short)2; p3 = sVar6; }
    if (f_043dc0(p2) == 2) { short sVar6 = p3; sVar6 /= (short)3; p3 = sVar6; }
    return p3;
}

//@ f_078b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft entlang einer durch -1 abgeschlossenen Liste von Trefferzonen-Koordinaten p2, ob sich
 *   auf einem dieser Felder ein lebender Held befindet, würfelt mit der über f_078ac0 modifizierten
 *   Wahrscheinlichkeit p6 aus, ob der Großgegner p3 diesen Helden angreift, und setzt bei Erfolg das Ziel
 *   (f_0cfd30) sowie die gewählte Aktionskennung *p4 = p5.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, die Koordinatenliste p2 (short *), den Monsterzeiger p3,
 *   den Ausgabezeiger p4 für die Aktion, den Aktionscode p5 sowie die Basis-Trefferchance p6 und gibt 1 bei
 *   Zielerfassung oder 0 zurück.
 * - Wichtige Variablen: Liest die Figurenkennungen aus d_1bd984 und löst Heldenindizes 1..10 über d_1bc8f0 auf.
 === Ende Beschreibung === */
short f_078b40(int p1, short *p2, int p3, short *p4, int p5, int p6)
{
    short status = 0;
    short i;
    for (i = 0; !status; i++) {
        short *e = p2 + i * 2;
        // Haelt die Registerwahl fuer i und unit wie im Original.
        i = (i & 0) ? (short)0 : i;
        if (e[0] == -1) break;
        u8 v = ((u8 (*)[0x19])d_1bd984)[e[1]][e[0]];
        if (v > 0 && v <= 10) {
            int unit = d_1bc8f0 + (v - 1) * 0x5ef;
            unit = (unit & 0) ? 0 : unit;
            unit = (unit & 0) ? 0 : unit;
            if (f_0d4a10(unit)) {
                if ((short)f_1457e0(100) < f_078ac0(p1, unit, (short)p6)) {
                    f_0cfd30(p3, v);
                    *p4 = p5;
                    status = 1;
                }
            }
        }
    }
    return status;
}

//@ f_078c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entscheidet für einen Großgegner p2 (Grafiktyp 'R', 'S' oder 'T'), welche Kampfaktion er in
 *   dieser Runde ausführt: Flucht bei niedriger Lebensenergie (f_0cfa10 <= f_0d0160), Nahkampf-/Flächenschlag
 *   (result = 2, geprüft über f_078b40 auf den Trefferzonen d_1a1d84, d_1a1d98 bzw. d_1a1e44), Fern-/Atemangriff
 *   (result = 0x10 bei 'R') oder Spezialzauber (result = 4 bei 'S' und 'T').
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p2 und gibt den gewählten
 *   Aktionscode (short, Standard 13 = Abwarten) zurück.
 * - Wichtige Variablen: Verwendet die koordinierten Schlagbereich-Tabellen d_1a1d84 ('R'), d_1a1d98 ('S') und
 *   d_1a1e44 ('T').
 === Ende Beschreibung === */
short f_078c90(int p1, int p2)
{
    short result = 13;
    short status = 0;
    if (*(s8 *)(p1 + 0x293) != (s8)-1) {
        f_07eba0(p1 + 0x39, *(u8 *)(p1 + 0x293), 0);
        *(u8 *)(p1 + 0x293) = 0xff;
    }
    if (f_0cfa10(p2) <= f_0d0160(p2)) {
        f_0cfdd0(p2, 1);
    } else {
        f_0cfd30(p2, 0xff);
        f_0cfcf0(p2, 0xd);
        if (!(u8)((unsigned short)(f_042400((struct hero *)(f_02ffa0(d_1c0004)))))) {
            switch (f_0cf930(p2)) {
            case 'R':
                if (status == (short)0)
                    status = f_078b40(p1, d_1a1d84, p2, &result, 2, (short)((signed char)f_0d11e0(p2) + 0x46));
                if (status == (short)0 && (short)f_1457e0(100) < (signed char)f_0d11e0(p2) + 0x37) {
                    f_0d08e0(p2, f_038be0(d_1c0004));
                    result = 0x10;
                }
                break;
            case 'S':
                if (status == (short)0)
                    status = f_078b40(p1, d_1a1d98, p2, &result, 2, (short)((signed char)f_0d11e0(p2) + 0x1e));
                if (status == (short)0 && (short)f_1457e0(100) < (signed char)f_0d11e0(p2) + 0x37) {
                    f_0d08e0(p2, f_038be0(d_1c0004));
                    result = 4;
                }
                break;
            case 'T':
                if (status == (short)0)
                    status = f_078b40(p1, d_1a1e44, p2, &result, 2, (short)((signed char)f_0d11e0(p2) + 0x1e));
                if (status == (short)0 && (short)f_1457e0(100) < (signed char)f_0d11e0(p2) + 0x37) {
                    f_0d08e0(p2, f_038be0(d_1c0004));
                    result = 4;
                }
                break;
            }
        }
    }
    f_0cfcf0(p2, (s8)result);
    return result;
}

//@ f_078ec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert den kompletten Rundenablauf eines übergroßen Endgegners p2: Prüft Handlungsfähigkeit
 *   (f_072940), dekrementiert eventuelle Betäubungs-/Verzögerungszähler (f_0cfd70), ermittelt über f_078c90 die
 *   Rundenaktion und führt diese bei Angriff oder Zauber (2, 4, 0x10) über f_078f60 aus.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p2 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Setzt für die Anzeige des aktiven Gegnerporträts oben links *(p1 + 0x205) = p2 und
 *   d_1bda60 = 1.
 === Ende Beschreibung === */
void f_078ec0(int p1, int p2)
{
    short sVar2;
    if (d_1bd928) f_069460();
    f_0cfcb0(p2, -1);
    if (f_072940(p2)) {
        if (f_0cfd70(p2)) {
            f_0cfd90(p2, -1);
        } else {
            d_1bda60 = 1;
            *(int *)(p1 + 0x205) = p2;
            sVar2 = f_078c90(p1, p2);
            if (sVar2 == 2 || sVar2 == 4 || sVar2 == 0x10) {
                if (d_1bd928) f_069460();
                f_078f60(p1, p2);
            }
            *(int *)(p1 + 0x205) = 0;
        }
    }
    if (d_1bd928) f_069460();
}

//@ f_078f60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verzweigt für den Großgegner p2 je nach gewählter Aktionskennung f_0cfce0(p2) in den
 *   Nahkampf-/Flächenangriff (f_0791f0 bei 2), den Fern-/Feueratemangriff (f_079670 bei 0x10) oder den
 *   Spezialzauber (f_0799c0 bei 4) und räumt anschließend die Zielmarkierungen und Infoboxen wieder auf.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p2 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Prüft das Kampf-Aktivflag d_1bd90c und das Ziel f_0d08a0(p2).
 === Ende Beschreibung === */
void f_078f60(int p1, int p2)
{
    typedef signed char (*Get8)(int);
    int p1_00;
    if (*(short *)&d_1bd90c) {
        if (d_1bd928) f_069460();
        f_09c780(CT);
        *(char *)(p1 + 0x1ee) = *(char *)(p1 + 0x1ef) =
            *(char *)(p1 + 0x1f0) = d_1bd918 = 0;
        p1_00 = f_0d08a0(p2);
        if (!((Get8)f_042470)(p1_00)) {
            if (f_042350((struct hero *)(p1_00))) {
                if (f_0cfce0(p2) == 2) {
                    f_0791f0(p1, p2, p1_00);
                } else {
                    if (f_0cfce0(p2) == 0x10) {
                        f_079670(p1, p2, p1_00);
                    } else {
                        if (f_0cfce0(p2) == 4) {
                            f_0799c0(p1, p2);
                        }
                    }
                }
                f_09c990(CT);
                do {
                if (*(u8 *)(p1 + 0x294) != (unsigned char)0xff) {
                    f_07eba0(p1 + 0x39, *(u8 *)(p1 + 0x294), 0);
                    *(u8 *)(p1 + 0x294) = 0xff;
                }
                } while (0);
                *(int *)(p1 + 0x20d) = 0;
                *(int *)(p1 + 0x209) = 0;
                d_1bda64 = 1;
                f_0758b0(p1);
                f_0762e0(0, 0x91, 100, 199);
                f_0765a0(p1);
                f_075f10(p1);
            }
        }
    }
}

//@ f_079090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Koordinatenpaar (p1, p2) in der mit -1 terminierten Koordinatenliste p3
 *   (Schlagbereich eines Großgegners) enthalten ist.
 * - Eingaben und Rückgabe: Empfängt die Spalte p1, die Zeile p2 (short) sowie das Koordinatenarray p3 (short *)
 *   und gibt 1 bei Treffer oder 0 zurück.
 * - Wichtige Variablen: Durchläuft p3 paarweise (e[0], e[1]) bis e[0] == -1.
 === Ende Beschreibung === */
int f_079090(short p1, short p2, short *p3)
{
    int r;
    short i = 0;
    r = 0;
    for (;;) {
        short *e = p3 + i * 2;
        if (*e == -1) break;
        if (p1 == e[0] && p2 == e[1]) { r = 1; break; }
        i = i + 1;
    }
    return r;
}

//@ f_0790e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein Zielzeiger p2 bereits in den ersten p3 Einträgen des Zielarrays p1 (d_1bda78)
 *   gespeichert ist, um Mehrfachtreffer auf denselben Helden in einer Flächenattacke zu vermeiden.
 * - Eingaben und Rückgabe: Empfängt das Zeigerarray p1 (int *), den gesuchten Zeiger p2 (int) und die Arraylänge
 *   p3 (short) und gibt 1 bei Fund oder 0 zurück.
 * - Wichtige Variablen: Keine externen Variablen.
 === Ende Beschreibung === */
int f_0790e0(int *p1, int p2, short p3)
{
    int r = 0;
    short i = 0;
    for (i = 0; i < p3; i++) {
        if (p2 == p1[i]) { r = 1; break; }
    }
    return r;
}

//@ f_079110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hebt einen von einem Großgegner getroffenen oder anvisierten Helden p2 kurzzeitig visuell
 *   hervor, indem dessen Porträt unten links eingeblendet (*(p1 + 0x209) = p2, d_1bda64 = 1) und ein
 *   Fadenkreuz-Sprite auf seiner Rasterposition (a, b) gezeichnet wird (f_0757f0).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Heldenzeiger p2 (int) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Sucht die Heldenposition über f_071e90 und verwaltet das Zielmarkierungs-Sprite *(p1 +
 *   0x294).
 === Ende Beschreibung === */
void f_079110(int p1, int p2)
{
    short b;
    short a;
    u8 c;
    *(int *)(p1 + 0x20d) = 0;
    *(int *)(p1 + 0x209) = 0;
    d_1bda64 = 1;
    if (*(s8 *)(p1 + 0x294) != (signed char)-1) {
        f_07eba0(p1 + 0x39, *(u8 *)(p1 + 0x294), 0);
        *(u8 *)(p1 + 0x294) = 0xff;
    }
    c = f_0d54c0(p2);
    f_071e90((u8)(c + 1), (int)&a, (int)&b);
    *(char *)(p1 + 0x1e) = 0;
    *(int *)(p1 + 0x209) = p2;
    *(char *)(p1 + 0x18) = a;
    char value = b;
    *(char *)(p1 + 0x1f) = 0;
    *(char *)(p1 + 0x20) = 6;
    *(char *)(p1 + 0x24) = 0;
    *(int *)(p1 + 0x27) = 0;
    *(char *)(p1 + 0x22) = 2;
    *(char *)(p1 + 0x23) = 1;
    *(char *)(p1 + 0x19) = value;
    *(int *)(p1 + 0x2b) = *(int *)(p1 + 0x1f1);
    *(u8 *)(p1 + 0x25) = 0xff;
    *(u8 *)(p1 + 0x294) = f_07ec10(p1 + 0x39, -1);
    f_0757f0(p1);
    *(int *)(p1 + 0x20d) = 0;
    *(int *)(p1 + 0x209) = 0;
}

inline int fi_find_2940(short a, short b, short *q)
{
    short pb;
    short pa;
    short *p3;
    pa=a;
    pb=b;
    p3=q;
    int r;
    short i = 0;
    r = 0;
    for (;;) {
        short *e = p3 + i * 2;
        if (*e == -1) break;
        if (pa == e[0] && pb == e[1]) { r = 1; break; }
        i = i + 1;
    }
    return r;
}

//@ f_0791f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt den Nahkampf- bzw. Flächenangriff eines Großgegners weapon aus: Bei Flächengroßgegnern
 *   (f_0d0710 oder f_0d04e0) werden alle Helden auf den Schlagfeldern d_1a1d98 bzw. d_1a1e44 mit abnehmender
 *   Trefferchance geprüft, Schaden über f_0d0bb0 und f_044300 zugefügt, Kampfmeldungen (f_09c800) eingereiht und
 *   die Schlag- und Trefferanimationen (f_06f690, f_06efc0) für alle getroffenen Helden synchron abgespielt; bei
 *   einfachen Großgegnern wird das Einzelziel victim angegriffen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger self, den Monsterzeiger weapon sowie den Zielhelden victim
 *   (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sammelt alle getroffenen Helden im Array d_1bda78 (Anzahl d_1bda74) und deren
 *   Treffer-Animationshandles in d_1bda94[0..6].
 === Ende Beschreibung === */
void f_0791f0(int self, int weapon, int victim)
{
    typedef unsigned char (*Get8)(int);
    typedef int (*Effect)(int,int,int,int);
    short y,x;
    short index1,index2,index3;
    short damage;
    int found;
    int target;
    short *pattern;
    target=0; found=-1;
    if(f_0d0710(weapon) || f_0d04e0(weapon)) {
        pattern=d_1a1e44;
        if(f_0d0710(weapon)) pattern=d_1a1d98;
        f_07b540(self);
        target=f_038c80(d_1c0004);
        do {
            f_071e90((unsigned char)(f_0d54c0(target)+1),(int)&x,(int)&y);
            found=fi_find_2940(x,y,pattern);
            if(found && f_0d4a10(target)) {
                if((short)f_1457e0(100)<(signed char)f_0d11e0(weapon)+80-d_1bda74*20) {
                    d_1bda78[d_1bda74]=target;
                    f_0d08e0(weapon,target);
                    damage=f_0d0bb0(weapon,target,0);
                    if(damage>0) {
                        f_044300(target,damage);
                        f_09c800(CT,0xb,damage,1,weapon,2,target);
                    }
                    f_079110(self,d_1bda78[d_1bda74]);
                    ++d_1bda74;
                }
            }
            target=f_0391b0(d_1c0004,target);
            // Haelt die globale Ladefolge in der Schleife wie im Original.
            d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004;
        } while(target!=f_038c80(d_1c0004));
        if(d_1bda74>0) {
            *(int*)(self+0x289)=f_06f690(self,weapon,self+0x45);
            for(index1=0;index1<d_1bda74;index1++) {
                d_1bd918=0;
                if(((Get8)f_042470)(d_1bda78[index1])) d_1bd918=1;
                f_043460(d_1bda78[index1],0);
                int effect=((Effect)f_06efc0)(self,d_1bda78[index1],self+0x45,(signed char)f_0cfc70(weapon));
                d_1bda94[index1]=effect;
                f_06a6c0(effect,1);
            }
            // Haelt die Ladefolge von d_1bda94[0] wie im Original.
            for(index2=d_1bda74;index2<7;index2++) { d_1bda94[0] = (d_1bda94[0] & 0) ? 0 : d_1bda94[0]; int v=d_1bda94[0]; d_1bda94[index2]=v; }
            *(char*)(self+0x292)=0;
            do { f_069460(); }
            while(!*(char*)(self+0x292) &&
                (!f_069be0(*(int*)(self+0x289)) ||
                 !f_069be0(d_1bda94[0]) || !f_069be0(d_1bda98) ||
                 !f_069be0(d_1bda9c) || !f_069be0(d_1bdaa0) ||
                 !f_069be0(d_1bdaa4) || !f_069be0(d_1bdaa8) || !f_069be0(d_1bdaac)));
        }
        f_06f5c0(self,weapon,self+0x45);
        for(index3=0;index3<d_1bda74;index3++) f_06ed10(self,d_1bda78[index3],self+0x45);
        f_0757f0(self);
    } else {
        f_079110(self,victim);
        damage=f_0d0bb0(weapon,victim,0);
        if(damage>0) {
            f_044300(victim,damage);
            f_09c800(CT,0xb,damage,1,weapon,2,victim);
            if(((Get8)f_042470)(victim)) d_1bd918=1;
        }
        *(int*)(self+0x289)=f_06f690(self,weapon,self+0x45);
        f_043460(victim,0);
        int effect=((Effect)f_06efc0)(self,victim,self+0x45,(signed char)f_0cfc70(weapon));
        *(char*)(self+0x292)=0;
        *(int*)(self+0x28d)=effect;
        do { f_069460(); }
        while(!*(char*)(self+0x292) && (!f_069be0(*(int*)(self+0x289)) || !f_069be0(*(int*)(self+0x28d))));
        f_06f5c0(self,weapon,self+0x45);
        f_06ed10(self,victim,self+0x45);
        f_0757f0(self);
        f_07bd30(self,victim,0);
    }
}

//@ f_079670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt den Fern- bzw. Atemangriff eines Großgegners p2 aus: Beim Riesendrachen ('R') kann der
 *   Angriff alle lebenden Helden der Gruppe mit einer Wahrscheinlichkeit von f_0d11e0(p2) + 30 Prozent
 *   gleichzeitig treffen (inklusive Drachenatem-Animation f_06d580 und synchronen Trefferanimationen f_06efc0),
 *   während andere Großgegner ein einzelnes Ziel p3 beschießen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, den Monsterzeiger p2 sowie das Einzelziel p3 (int) und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt d_1bda78 und d_1bda94 für die synchrone Mehrfachtreffer-Darstellung.
 === Ende Beschreibung === */
void f_079670(int p1, int p2, int p3)
{
    short sVar2, sVar6;
    int iVar3, iVar4, uVar5;
    typedef unsigned char (*Get8)(int);
    typedef int (*Effect)(int, int, int, int);
    if (f_0cf930(p2) == 'R') {
        f_07b540(p1);
        iVar3 = f_038c80(d_1c0004);
        do {
            if (f_0d4a10(iVar3)) {
                int cc = (signed char)f_0d11e0(p2);
                if ((short)f_1457e0(100) < cc + 30) {
                    d_1bda78[d_1bda74] = iVar3;
                    f_0d08e0(p2, iVar3);
                    iVar4 = f_0d0bb0(p2, iVar3, 0);
                    if (iVar4 > 0) {
                        f_044300(iVar3, iVar4);
                        f_09c800(CT, 0xb, iVar4, 1, p2, 2, iVar3);
                    }
                    f_079110(p1, d_1bda78[d_1bda74]);
                    d_1bda74++;
                }
            }
            iVar3 = f_0391b0(d_1c0004, iVar3);
        } while (iVar3 != f_038c80(d_1c0004));
        if (d_1bda74 > 0) {
            uVar5 = f_06d580(p1, p2, p1 + 0x45);
            *(char *)(p1 + 0x292) = 0;
            *(int *)(p1 + 0x289) = uVar5;
            do { f_069460(); }
            while (!*(char *)(p1 + 0x292) && !f_069be0(*(int *)(p1 + 0x289)));
            for (sVar6 = 0; sVar6 < d_1bda74; sVar6++) {
                d_1bd918 = 0;
                if (((Get8)f_042470)(d_1bda78[sVar6])) d_1bd918 = 1;
                f_043460(d_1bda78[sVar6], 0);
                int kind = (signed char)f_0cfc70(p2);
                uVar5 = ((Effect)f_06efc0)(p1, d_1bda78[sVar6], p1 + 0x45, kind);
                d_1bda94[sVar6] = uVar5;
                f_06a6c0(uVar5, 1);
            }
            for (sVar2 = d_1bda74; sVar2 < 7; sVar2++) {
                int value = d_1bda94[0];
                d_1bda94[(short)sVar2] = value;
            }
            *(char *)(p1 + 0x292) = 0;
            do { f_069460(); }
            while (!*(char *)(p1 + 0x292) &&
                   (!f_069be0(d_1bda94[0]) || !f_069be0(d_1bda98) ||
                    !f_069be0(d_1bda9c) || !f_069be0(d_1bdaa0) ||
                    !f_069be0(d_1bdaa4) || !f_069be0(d_1bdaa8) ||
                    !f_069be0(d_1bdaac)));
        }
        f_06f5c0(p1, p2, p1 + 0x45);
        for (sVar2 = 0; sVar2 < d_1bda74; sVar2++)
            f_06ed10(p1, d_1bda78[sVar2], p1 + 0x45);
        f_0757f0(p1);
    } else {
        iVar3 = f_0d0bb0(p2, p3, 0);
        if (iVar3 > 0) {
            f_044300(p3, iVar3);
            f_09c800(CT, 0xb, iVar3, 1, p2, 2, p3);
            if (((Get8)f_042470)(p3)) d_1bd918 = 1;
        }
        f_079110(p1, p3);
        uVar5 = f_06d580(p1, p2, p1 + 0x45);
        *(char *)(p1 + 0x292) = 0;
        *(int *)(p1 + 0x289) = uVar5;
        do { f_069460(); }
        while (!*(char *)(p1 + 0x292) && !f_069be0(*(int *)(p1 + 0x289)));
        f_06f5c0(p1, p2, p1 + 0x45);
        f_06ed10(p1, p3, p1 + 0x45);
    }
}

//@ f_0799c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt den Spezialzauberangriff eines Großgegners p2 ('S' oder 'T') aus: Sucht in bis zu 10
 *   Versuchen zufällige Helden in Sichtlinie (f_0735b0), wählt aus der Zauberliste d_1a1e80 ('S') bzw. d_1a1e9a
 *   ('T') einen passenden Zauber (f_07beb0), wirkt ihn über f_0d10c0, spielt die Zauber- und Opferanimationen
 *   (f_06daa0, f_06c930) ab und gibt eventuelle Spruchmeldungen über f_0bf730 aus.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Monsterzeiger p2 (sowie einen ungenutzten dritten
 *   Parameter p3) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Liest die 13-elementigen Zaubertabellen d_1a1e80 und d_1a1e9a und puffert erzeugte
 *   Meldungstexte in str[0..6].
 === Ende Beschreibung === */
void f_0799c0(int p1, int p2, int p3)
{
    typedef unsigned char (*Get8)(int);
    typedef short (*Rand16)(int);
    typedef short (*Action16)(int, short);
    u8 c;
    short j;
    short arr[7];
    short count;
    short max_targets;
    short x1;
    short val;
    short idx;
    short x2;
    short y2;
    short i;
    short y1;
    int done;
    short *pattern;
    int target;
    short tries;
    char *str[7];

    done = 0;
    tries = 0;
    // Haelt die fruehe Namenssortierung und Stapelbelegung wie im Original.
    tries = 0; tries = 0; tries = 0;
    c = f_0cf930(p2);
    switch (c) {
    case 'S':
        pattern = d_1a1e80;
        count = 13;
        max_targets = 1;
        break;
    case 'T':
        pattern = d_1a1e9a;
        count = 13;
        max_targets = 1;
        break;
    }
    f_07b540(p1);
    for (i = 0; i < 7; i++) {
        arr[i] = 0;
        str[i] = 0;
    }
    f_071e90((u8)(f_0729c0(p2) + 10), (int)&x1, (int)&y1);
    while (tries < 10 && d_1bda74 < max_targets) {
        target = f_038be0(d_1c0004);
        target = (target & 0) ? 0 : target;
        if (!f_0790e0(d_1bda78, target, 7)) {
            f_071e90((u8)(f_0d54c0(target) + 1), (int)&x2, (int)&y2);
            if (f_0735b0(p1, x2, y2, (int)&x1, (int)&y1, 99)) {
                f_0d08e0(p2, target);
                j = 0;
                while ((void *)done == 0 && j < 10) {
                    short *count_ptr = &count;
                    idx = ((Rand16)f_1457e0)(*count_ptr) - 1;
                    val = pattern[idx];
                    f_0cfd10(p2, (s8)val);
                    if (f_07beb0(p2, val) == 1) {
                        d_1c21b4[0] = 0;
                        d_1bda78[d_1bda74] = target;
                        f_0d08e0(p2, target);
                        d_1c0424 = 1;
                        arr[d_1bda74] = ((Action16)f_0d10c0)(p2, 0);
                        done = *(s8 *)d_1c21b4;
                        if (done) {
                            str[d_1bda74] = (char *)f_014540(200, (int)d_1a1d64, 0x381);
                            strcpy(str[d_1bda74], d_1c21b4);
                        }
                        f_079110(p1, d_1bda78[d_1bda74]);
                        d_1bda74++;
                        done = 1;
                    } else {
                        j++;
                    }
                }
            } else {
                f_0cfd30(p2, 0xff);
            }
        }
        tries++;
    }
    if (d_1bda74 > 0) {
        *(int *)(p1 + 0x289) = f_06daa0(p1, p2, p1 + 0x45);
        *(char *)(p1 + 0x292) = 0;
        do {
            f_069460();
        } while (!*(char *)(p1 + 0x292) && !f_069be0(*(int *)(p1 + 0x289)));
        for (i = 0; i < d_1bda74; i++) {
            if (arr[i]) {
                d_1bd918 = 0;
                if (((Get8)f_042470)(d_1bda78[i])) d_1bd918 = 1;
                d_1bda94[i] = f_06c930(p1, d_1bda78[i], p1 + 0x45, val, 1);
            } else {
                d_1bda94[i] = f_06ed10(p1, d_1bda78[i], p1 + 0x45);
            }
        }
        for (i = d_1bda74; i < 7; i++) {
            d_1bda94[i] = d_1bda94[0];
        }
        do {
            f_069460();
        } while (!f_069be0(d_1bda94[0]) || !f_069be0(d_1bda98) ||
                 !f_069be0(d_1bda9c) || !f_069be0(d_1bdaa0) ||
                 !f_069be0(d_1bdaa4) || !f_069be0(d_1bdaa8) ||
                 !f_069be0(d_1bdaac));
    }
    f_06f5c0(p1, p2, p1 + 0x45);
    for (i = 0; i < d_1bda74;) {
        int cleanup_index = i++;
        int cleanup_target = d_1bda78[cleanup_index];
        d_1bda78[cleanup_index] = cleanup_target;
        f_06ed10(p1, cleanup_target, p1 + 0x45);
    }
    f_0757f0(p1);
    int format = (p1 & 0) ? 0 : (int)&d_1c3498;
    for (i = 0; i < d_1bda74; i++) {
        if (str[i]) {
            f_0bf730(format - (int)&d_1c3498 + (int)&d_1c2c64, f_133fe0(format, (int)str[i]));
            delete str[i];
        }
    }
}
