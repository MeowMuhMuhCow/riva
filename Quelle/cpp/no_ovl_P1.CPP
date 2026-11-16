/* === Beschreibung (Katalog) ===
 * Einheit no_ovl
 *
 * Diese Einheit gehört zu no_ovl.cpp (dauerhaft im Speicher gehaltene Kernroutinen ohne Overlay-Nachladen) und
 * verwaltet den Bildschirmschoner-Aufruf, Handlungsfähigkeits- und Inventarabfragen für Helden, das System für
 * temporäre Eigenschafts-/Zustandsmodifikatoren (20 Slots je Held ab Offset +0x55b), die Aktualisierung der
 * Lebens-/Astralleisten in der Statusleiste sowie die zentrale Funktionstasten- und Hotkey-Verarbeitung
 * f_0d5780.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 19/22 gleich (suche.py 26.10.2026, Basis no_ovl_P1.CPP)
// no_ovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D48A0-0x0D5B50
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_01e0c0();                                         // reg - stapel 0
int f_01e630(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_01e860(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_041b60();                                         // reg - stapel 0
int f_041d90(int p1);                                   // reg eax stapel 0











signed char f_0435c0(int p1, int p2);
signed char f_043820(int p1, int p2);
int f_0449d0(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04a890(int p1);                                   // reg eax stapel 0
int f_04ad40(int p1, int p2);                           // reg eax stapel 0
int f_04e350();                                         // reg - stapel 0
int f_04f3f0(int p1, int p2);                           // reg eax edx stapel 0
int f_059d50(int p1);
int f_059d50(int p1, int p2);
int f_05b860(int p1, int p2);
int f_068f40();                                         // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0bba10(int p1);
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0cdad0();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d37e0();                                         // reg - stapel 0
int f_0d3800();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d78a0(int p1);
int f_0d78b0(int p1, int p2);                           // reg - stapel 0
int f_0d8520(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
short f_0de7f0(int p1);
short f_0de800(int p1);
int f_0e3360(int p1);                                   // reg eax stapel 0
int f_0f01b0(int p1);                                   // reg eax stapel 0
int f_0f12f0(int p1);
int f_1265c0(int p1, int p2);
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13e240();                                         // reg - stapel 0
int f_149d20();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1a966a;
extern int d_1bc760;                    // 0x1BC760
struct H0d54c0 { char b[0x5ef]; };
extern struct H0d54c0 *d_1bc8f0;                    // 0x1BC8F0
#define d_1bc8f0 ((int)d_1bc8f0)
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1bfa78;                    // 0x1BFA78
extern unsigned short d_1bfb04;
extern int d_1bfb34;                    // 0x1BFB34
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0170;                    // 0x1C0170
extern int d_1c0174;                    // 0x1C0174
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile short d_1c2198;
extern short d_1c21a2;
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern const char d_1a5a3c[];           // Text 0x1A5A3C
signed char f_043df0(int p1);
void f_0d56c0(int p, short idx);
void f_148450(int p1, short p2, int p3, int p4, int p5);
extern short d_1a5544[];
#define VA(e) (*(volatile signed char *)&(e)->a)
#define VV(e) (*(volatile signed char *)&(e)->v)
void f_145300(int *p1, int p2, int p3);
extern int d_1a5a5c;
extern int d_1bf230;
#define W(p,o) (*(int *)((p)+(o)))
#define H(p,o) (*(short *)((p)+(o)))
#define SB(p,o) (*(signed char *)((p)+(o)))
#define UB(p,o) (*(unsigned char *)((p)+(o)))
struct E { int t; signed char ty; signed char a; signed char v; };
struct T652 { char b[0x652]; };
struct T128 { char b[0x128]; };
struct T11f { char b[0x11f]; };
void f_0d48a0(int p);
int f_0d49b0(int p);
int f_0d4a10(int p);
int f_0d4a60(int p);
int f_0d4aa0(int p, short k);
int f_0d4ad0(int p);
int f_0d4b00(int p);
int f_0d4b30(int p);
int f_0d4b60(int p);
void f_0d4b90(int p, short a, int c);
short f_0d4c80(int p);
signed char f_0d4cd0(unsigned char p, signed char k);
void f_0d4d80(int p, int n);
void f_0d5040(int p, short idx, int t, signed char a, signed char v, unsigned char ty);
void f_0d5290(int p, signed char ty);
unsigned char f_0d54c0(int p);
short f_0d54f0(int p, int k);
void f_0d5550(int p);
void f_0d5630(void);
void f_0d5780(void);
void f_0d5a90(void);

//@ f_0d48a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktiviert bei Inaktivität den Bildschirmschoner (f_0f01b0 im 3D-Modus bzw. f_0f12f0
 *   unter vorherigem Sichern des Bildschirms in "saversav.$$$"), sofern die Bildschirmschoner-Flags
 *   (d_1c0170/d_1bfb04 oder d_1c0174) gesetzt sind, und stellt danach den ursprünglichen Zustand wieder her.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Bildschirmschoner-Kontextstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d48a0(int p)
{
    int old;
    volatile int fl;
    unsigned char b;
    if (((d_1c0170 != 0 && (b = (unsigned char)d_1bfb04)) || d_1c0174 != 0) && W(p, 4) == 0) {
        old = d_1c2a80;
        if (f_0d3860() == 1) {
            int k = 1;
            f_0d2710();
            fl = k;
        } else fl = 0;
        if (d_1bc760 != 0) f_01cef0(d_1bc760);
        W(p, 4) = 1;
        d_1c0c4c++;
        d_1c2a80 = 0;
        if (f_13e240()) {
            f_0f01b0(p);
        } else {
            f_09ac80(d_1a34e0, d_1a5a5c, 0);
            f_0f12f0(p);
            f_09ade0(d_1a34e0, d_1a5a5c, 0);
            f_09aed0(d_1a5a5c);
        }
        *(int *)(p + 4) = 0;
        d_1c0c4c--;
        d_1c2a80 = old;
        f_149d20();
        f_0d3870();
        if (fl == 1) f_0d26e0();
    }
}

//@ f_0d49b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt nach strengsten Kriterien, ob der Held p vollständig handlungsfähig ist
 *   (existiert f_042350, nicht abwesend/flüchtig f_0424d0, nicht tot f_042470, nicht bewusstlos f_0424e0, nicht
 *   versteinert f_0425f0, nicht in Panik f_0425a0 und nicht verzaubert/beherrscht f_042640).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Held uneingeschränkt handlungsfähig ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d49b0(int p)
{
    if (!((char)(f_042350((struct hero *)(p)))) || ((char)(f_0424d0((struct hero *)(p)))) || ((char)(f_042470((struct hero *)(p)))) || ((char)(f_0424e0((struct hero *)(p)))) || ((char)(f_0425f0((struct hero *)(p)))) || ((char)(f_0425a0((struct hero *)(p)))) || ((char)(f_042640((struct hero *)(p))))) return 0;
    return 1;
}

//@ f_0d4a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion ermittelt, ob der Held p lebt und ansprechbar ist (existiert f_042350, nicht tot
 *   f_042470, nicht bewusstlos f_0424e0, nicht versteinert f_0425f0 und nicht in Panik f_0425a0).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn keine dieser Einschränkungen vorliegt, andernfalls 0.
 === Ende Beschreibung === */
int f_0d4a10(int p)
{
    if (!((char)(f_042350((struct hero *)(p)))) || ((char)(f_042470((struct hero *)(p)))) || ((char)(f_0424e0((struct hero *)(p)))) || ((char)(f_0425f0((struct hero *)(p)))) || ((char)(f_0425a0((struct hero *)(p))))) return 0;
    return 1;
}

//@ f_0d4a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese im gesamten Spiel häufig genutzte Standard-Prüffunktion stellt fest, ob der Held p
 *   grundsätzlich aktionsfähig ist (existiert f_042350, nicht tot f_042470, nicht bewusstlos f_0424e0 und nicht
 *   versteinert f_0425f0).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Held lebt und bei Bewusstsein ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d4a60(int p)
{
    if (!((char)(f_042350((struct hero *)(p)))) || ((char)(f_042470((struct hero *)(p)))) || ((char)(f_0424e0((struct hero *)(p)))) || ((char)(f_0425f0((struct hero *)(p))))) return 0;
    return 1;
}

//@ f_0d4aa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht die 31 Inventarplätze (0 bis 0x1e, je 0x1b Bytes ab Offset +0x1a8) des
 *   Helden p nach dem ersten Vorkommen des Gegenstandstyps k.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur sowie die gesuchte Gegenstands-ID k.
 * - Rückgabewert: Zurückgegeben wird der Slot-Index (0 bis 30) des gefundenen Gegenstands oder -1, falls der
 *   Held ihn nicht besitzt.
 === Ende Beschreibung === */
int f_0d4aa0(int p, short k)
{
    int i;
    for (i = 0; (short)i < 0x1f; i++)
        if (k == H(p, (short)i * 0x1b + 0x1a8)) return i;
    return -1;
}

//@ f_0d4ad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für den Helden p die sieben Krankheitsarten (1 bis 7) über f_043820 und sucht
 *   die erste Krankheit im ausgebrochenen Zustand (== -1).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Nummer der Krankheit (1 bis 7) oder 0, falls keine Krankheit aktiv ist.
 === Ende Beschreibung === */
int f_0d4ad0(int p)
{
    int i;
    for (i = 1; (short)i <= 7; i++)
        if (f_043820(p, (short)i) == -1) return i;
    return 0;
}

//@ f_0d4b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für den Helden p die neun Giftarten (1 bis 9) über f_0435c0 und sucht die erste
 *   aktive Vergiftung (== -1).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Nummer des Gifts (1 bis 9) oder 0, falls keine Vergiftung aktiv ist.
 === Ende Beschreibung === */
int f_0d4b00(int p)
{
    int i;
    for (i = 1; (short)i <= 9; i++)
        if (f_0435c0(p, (short)i) == -1) return i;
    return 0;
}

//@ f_0d4b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für den Helden p die sieben Krankheitsarten (1 bis 7) über f_043820 darauf, ob
 *   sich eine Krankheit im Heilungs-/Abklingstadium (== 1) befindet.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Nummer der abklingenden Krankheit (1 bis 7) oder 0.
 === Ende Beschreibung === */
int f_0d4b30(int p)
{
    int i;
    for (i = 1; (short)i <= 7; i++)
        if (f_043820(p, (short)i) == 1) return i;
    return 0;
}

//@ f_0d4b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für den Helden p die neun Giftarten (1 bis 9) über f_0435c0 darauf, ob sich eine
 *   Vergiftung im Abklingstadium (== 1) befindet.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird die Nummer des abklingenden Gifts (1 bis 9) oder 0.
 === Ende Beschreibung === */
int f_0d4b60(int p)
{
    int i;
    for (i = 1; (short)i <= 9; i++)
        if (f_0435c0(p, (short)i) == 1) return i;
    return 0;
}

//@ f_0d4b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion vergleicht die aktuellen und maximalen Lebens- (f_042960/f_042970) und Astralpunkte
 *   (f_0429a0/f_0429b0) des Helden p mit den zuletzt gezeichneten Zwischenwerten bei Offset +0x553 bis +0x559
 *   und zeichnet die Statusbalken am Gruppenplatz a bei Änderungen über f_01e630 neu.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur, der Anzeigeplatz a sowie das
 *   Darstellungsflag c.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d4b90(int p, short a, int c)
{
    short s2;
    if (((char)(f_042470((struct hero *)(p))))) s2 = 0;
    else s2 = f_0429a0((struct hero *)(p));
    if (f_042960((struct hero *)(p)) != H(p, 0x555) || f_042970((struct hero *)(p)) != H(p, 0x553)) {
        f_01e630((int)&d_1c2bcc, 0, a, f_042960((struct hero *)(p)), f_042970((struct hero *)(p)), 0, c);
        H(p, 0x553) = f_042970((struct hero *)(p));
        H(p, 0x555) = f_042960((struct hero *)(p));
    }
    if (s2 != H(p, 0x559) || f_0429b0((struct hero *)(p)) != H(p, 0x557)) {
        f_01e630((int)&d_1c2bcc, 1, a, s2, f_0429b0((struct hero *)(p)), 0, c);
        H(p, 0x557) = f_0429b0((struct hero *)(p));
        H(p, 0x559) = s2;
    }
}

//@ f_0d4c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sucht in der Tabelle der 20 temporären Effekt-Slots (je 7 Bytes ab Offset +0x55b) des
 *   Helden p nach einem freien Eintrag (Restdauer == 0) und gibt bei vollem Array den ersten Slot (0) durch
 *   sofortiges Ablaufenlassen (f_0d4d80(p, 1)) frei.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der Index (0 bis 19) des freien Effekt-Slots.
 === Ende Beschreibung === */
short f_0d4c80(int p)
{
    short i;
    for (i = 0; (short)i < 0x14; i++)
        if (W(p, (short)i * 7 + 0x55b) == 0) break;
    if ((short)i == 0x14) {
        *(volatile int *)(p + 0x55b) = 1;
        f_0d4d80(p, 1);
        i = 0;
    }
    return i;
}

//@ f_0d4cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht die 20 temporären Effekt-Slots des Helden p (Offset +0x55f + i * 7) nach
 *   einem Eintrag mit dem Effekttyp k.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur sowie der gesuchte Effekttyp k.
 * - Rückgabewert: Zurückgegeben wird der Slot-Index (0 bis 19) oder -1, falls kein Effekt dieses Typs vorliegt.
 === Ende Beschreibung === */
signed char f_0d4cd0(int p, signed char k)
{
    volatile signed char key = k;
    int kk = key;
    short i;
    {
        int pp = p;
        for (i = 0; i < 0x14; i++)
            if (SB(pp, 0x55f + i * 7) == kk) break;
        if (i == 0x14) i = -1;
    }
    return i;
}

//@ f_0d4d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verringert bei jedem der 20 aktiven temporären Effekt-Slots (Offset +0x55b) des Helden
 *   p die Restdauer e->t um n Zeiteinheiten und macht beim Ablaufen (e->t <= 0) die jeweilige Eigenschafts-,
 *   Talent-, Attacke-, Parade-, Rüstungs- oder Zustandsbit-Änderung (ty = 0 bis 27) wieder rückgängig.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur sowie die verstrichene Zeitspanne n.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
#define VT(e) (*(volatile int *)&(e)->t)
void f_0d4d80(int p, int n)
{
    struct E *e;
    short i;
    if (d_1c0c4c == 0) {
        e = (struct E *)(p + 0x55b);
        for (i = 0; i < 20; i++, e++) {
            if (VT(e) != 0) {
                VT(e) -= n;
                if (VT(e) <= 0) {
                    VT(e) = 0;
                    switch ((unsigned char)e->ty) {
                    case 0:
                        f_045430(p, (short)e->a, (signed char)(-e->v));
                        break;
                    case 1:
                        f_03af20(p, (short)e->a, (signed char)(-e->v));
                        break;
                    case 2:
                        SB(p + e->a, 0x7a) -= e->v;
                        break;
                    case 3:
                        SB(p + VA(e), 0x81) -= VV(e);
                        break;
                    case 5:
                        f_0449d0(p, (signed char)(-e->v));
                        break;
                    case 4:
                        SB(p + e->a, 0x14f) -= e->v;
                        break;
                    case 6:
                        SB(p, 0x90) -= e->v;
                        break;
                    case 7:
                        SB(p, 0xb2) -= e->v;
                        break;
                    case 8:
                        SB(p, 0xaa) -= e->v;
                        break;
                    case 9:
                        SB(p, 0x42) -= e->v;
                        break;
                    case 10:
                        SB(p, 0xab) -= e->v;
                        break;
                    case 11:
                        SB(p, 0xac) -= e->v;
                        break;
                    case 12:
                        UB(p, 0xbd) &= 0xfd;
                        break;
                    case 13:
                        UB(p, 0xbd) &= 0xef;
                        break;
                    case 14:
                        UB(p, 0xbd) &= 0x7f;
                        break;
                    case 15:
                        UB(p, 0xbe) &= 0xfe;
                        break;
                    case 16:
                        UB(p, 0xbe) &= 0xfd;
                        break;
                    case 17:
                        UB(p, 0xbe) &= 0xf7;
                        break;
                    case 19:
                        UB(p, 0xbe) &= 0xdf;
                        break;
                    case 18:
                        UB(p, 0xbe) &= 0xef;
                        break;
                    case 20:
                        UB(p, 0xbf) &= 0xfe;
                        break;
                    case 21:
                        UB(p, 0xbe) &= 0xbf;
                        f_045430(p, 2, (signed char)(-e->v));
                        break;
                    case 22:
                        SB(p, 0x503) -= VV(e);
                        SB(p, 0x504) -= VV(e);
                        break;
                    case 23:
                        UB(p, 0xbf) &= 0xfb;
                        break;
                    case 24:
                        UB(p, 0xbf) &= 0xf7;
                        break;
                    case 25:
                        UB(p, 0xbf) &= 0xef;
                        break;
                    case 26:
                        f_0449d0(p, (signed char)(-e->v));
                        UB(p, 0xbf) &= 0xbf;
                        break;
                    case 27:
                        f_0449d0(p, (signed char)(-e->v));
                        UB(p, 0xbf) &= 0x7f;
                        break;
                    }
                    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) d_1c2198 = 1;
                }
            }
        }
    }
}
//@ f_0d5040
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion trägt in den Slot idx der temporären Effekt-Tabelle (p + 0x55b + idx * 7) des Helden p
 *   einen neuen zeitlich befristeten Effekt der Dauer t, des Typs ty (0 bis 27), des Zielattributs/-talents a
 *   und der Stärke v ein und wendet die Erhöhung bzw. das Zustandsbit sofort auf den Helden an.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur, der Slot-Index idx, die Wirkungsdauer t, der
 *   Unterindex a, der Änderungsbetrag v sowie der Effekttyp ty.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5040(int p, short idx, int t, signed char a, signed char v, unsigned char ty)
{
    struct E *e;
    e = (struct E *)(p + 0x55b + idx * 7);
    e->v = v;
    e->t = t;
    e->ty = ty;
    e->a = a;
    switch (ty) {
        case 0:
            f_045430(p, (short)VA(e), VV(e));
            break;
        case 1:
            f_03af20(p, a, v);
            break;
        case 2:
            SB(p, a + 0x7a) += v;
            break;
        case 3:
            SB(p, a + 0x81) += v;
            break;
        case 5:
            f_0449d0(p, VV(e));
            break;
        case 4:
            SB(p, a + 0x14f) += v;
            break;
        case 6:
            SB(p, 0x90) += v;
            break;
        case 7:
            SB(p, 0xb2) += v;
            break;
        case 8:
            SB(p, 0xaa) += v;
            break;
        case 9:
            SB(p, 0x42) += v;
            break;
        case 10:
            SB(p, 0xab) += v;
            break;
        case 11:
            SB(p, 0xac) += v;
            break;
        case 12:
            UB(p, 0xbd) |= 0x2;
            break;
        case 13:
            UB(p, 0xbd) |= 0x10;
            break;
        case 17:
            UB(p, 0xbe) |= 0x8;
            break;
        case 14:
            UB(p, 0xbd) |= 0x80;
            break;
        case 15:
            UB(p, 0xbe) |= 0x1;
            break;
        case 16:
            UB(p, 0xbe) |= 0x2;
            break;
        case 19:
            UB(p, 0xbe) |= 0x20;
            break;
        case 18:
            UB(p, 0xbe) |= 0x10;
            break;
        case 20:
            UB(p, 0xbf) |= 0x1;
            break;
        case 21:
            UB(p, 0xbe) |= 0x40;
            f_045430(p, 2, VV(e));
            break;
        case 22:
            SB(p, 0x503) += v;
            SB(p, 0x504) += v;
            break;
        case 23:
            UB(p, 0xbf) |= 0x4;
            break;
        case 24:
            UB(p, 0xbf) |= 0x8;
            break;
        case 25:
            UB(p, 0xbf) |= 0x10;
            break;
        case 26:
            f_0449d0(p, VV(e));
            UB(p, 0xbf) |= 0x40;
            break;
        case 27:
            f_0449d0(p, VV(e));
            UB(p, 0xbf) |= 0x80;
            break;
    }
}

//@ f_0d5290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion beendet vorzeitig alle aktiven temporären Effekte des Typs ty in den 20 Effekt-Slots
 *   des Helden p, setzt deren Restdauer e->t auf 0 und nimmt ihre Auswirkungen auf Eigenschaften, Kampfwert oder
 *   Zustandsbits zurück.
 * - Eingaben: Übergeben werden der Zeiger p auf die Heldenstruktur sowie der aufzuhebende Effekttyp ty.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5290(int p, signed char ty)
{
    struct E *e;
    short i;
    int s;
    unsigned char c;
    e = (struct E *)(p + 0x55b);
    for (i = 0; i < 20; i++, e++) {
        if (e->t != 0 && (int)e->ty == (int)*(volatile signed char *)&ty) {
            e->t = 0;
            c = *(volatile unsigned char *)&e->ty;
            switch (c) {
                case 0: f_045430(p, (short)e->a, (signed char)-e->v); break;
                case 1: f_03af20(p, (short)e->a, (signed char)-e->v); break;
                case 2: SB(p, e->a + 0x7a) -= e->v; break;
                case 3: SB(p, e->a + 0x81) -= e->v; break;
                case 5: f_0449d0(p, (signed char)-e->v); break;
                case 4: SB(p, e->a + 0x14f) -= e->v; break;
                case 6: SB(p, 0x90) -= e->v; break;
                case 7: SB(p, 0xb2) -= e->v; break;
                case 8: SB(p, 0xaa) -= e->v; break;
                case 9: SB(p, 0x42) -= e->v; break;
                case 10: SB(p, 0xab) -= e->v; break;
                case 11: SB(p, 0xac) -= e->v; break;
                case 12: UB(p, 0xbd) &= 0xfd; break;
                case 13: UB(p, 0xbd) &= 0xef; break;
                case 17: UB(p, 0xbe) &= 0xf7; break;
                case 14: UB(p, 0xbd) &= 0x7f; break;
                case 15: UB(p, 0xbe) &= 0xfe; break;
                case 16: UB(p, 0xbe) &= 0xfd; break;
                case 19: UB(p, 0xbe) &= 0xdf; break;
                case 18: UB(p, 0xbe) &= 0xef; break;
                case 20: UB(p, 0xbf) &= 0xfe; break;
                case 21:
                    UB(p, 0xbe) &= 0xbf;
                    f_045430(p, 2, (signed char)-e->v);
                    break;
                case 22:
                    SB(p, 0x503) -= VV(e);
                    SB(p, 0x504) -= VV(e);
                    break;
                case 23: UB(p, 0xbf) &= 0xfb; break;
                case 24: UB(p, 0xbf) &= 0xf7; break;
                case 25: UB(p, 0xbf) &= 0xef; break;
                case 26: UB(p, 0xbf) &= 0xbf; break;
                case 27: UB(p, 0xbf) &= 0x7f; break;
            }
            if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) d_1c2198 = 1;
        }
    }
    d_1a34e0 = (d_1a34e0 & 0) ? 0 : d_1a34e0; d_1bc760 = (d_1bc760 & 0) ? 0 : d_1bc760; d_1bfa78 = (d_1bfa78 & 0) ? 0 : d_1bfa78; d_1bfb34 = (d_1bfb34 & 0) ? 0 : d_1bfb34; // haelt die Registerzuteilung wie im Original
}
//@ f_0d54c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion ermittelt den Array-Index (0 bis 6) des Heldenzeigers h innerhalb des globalen
 *   Helden-Arrays d_1bc8f0 (Elementgröße 0x5ef Bytes).
 * - Eingaben: Als Parameter wird der Zeiger h auf eine Heldenstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird der nullbasierte Index i des Helden in d_1bc8f0.
 === Ende Beschreibung === */
#undef d_1bc8f0
unsigned char f_0d54c0(int h)
{
    unsigned char i = 0;
    struct H0d54c0 *p = d_1bc8f0;
    while ((struct H0d54c0 *)h != p) {
        p = d_1bc8f0 + ++i;
    }
    return i;
}
#define d_1bc8f0 ((int)d_1bc8f0)

//@ f_0d54f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle sieben Gruppenmitglieder der Gruppe p und deren jeweils 31
 *   Inventarplätze nach dem Gegenstandstyp k und gibt den Gruppenplatz des ersten Helden zurück, der den
 *   Gegenstand trägt.
 * - Eingaben: Übergeben werden der Zeiger p auf die Gruppenstruktur sowie die gesuchte Gegenstands-ID k.
 * - Rückgabewert: Zurückgegeben wird der Gruppenindex (0 bis 6) des Besitzers oder -1, falls niemand in der
 *   Gruppe den Gegenstand besitzt.
 === Ende Beschreibung === */
short f_0d54f0(int p, int k)
{
    short k_ = (*&k);
    short i;
    short j;
    int q;
    for (i = 0; (short)i <= 6; i++) {
        q = W(p, (short)i * 4);
        if (q != 0) {
            for (j = 0; j < 0x1f; j++)
                if (H(q, j * 0x1b + 0x1a8) != k_) continue;
                else goto found;
            j = -1;
found:
            if (j >= 0) return i;
        }
    }
    return -1;
}

//@ f_0d5550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert die Statusleisten-Anzeige: Im Kampfmodus (d_1c2a80 == 0x30000) ruft sie
 *   f_01e860(p) auf, andernfalls zeichnet sie für alle belegten Heldenplätze die Lebens- und Astralbalken
 *   (f_0d4b90) neu und schwärzt unbesetzte Plätze über f_0d56c0.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Statusleisten-/UI-Struktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5550(int p)
{
    int a[7];
    short i, j;
    int q;
    if (!f_0e3360((int)&d_1c2c64) && W(p, 4) != 0) {
        if (d_1c2a80 == 0x30000) f_01e860(p);
        else if (f_0bba10((int)&d_1bf230)) {
            f_145300(a, 1, 7);
            q = d_1bc8f0;
            for (i = 0; i <= 6; i++, q += 0x5ef) {
                if (((char)(f_042350((struct hero *)(q))))) {
                    f_0d4b90(q, f_043df0(q), 0);
                    a[f_043df0(q)] = 0;
                }
            }
            for (j = 0; j <= 6; j++)
                if (a[j]) f_0d56c0((int)&d_1c2bcc, j);
        }
    }
}

//@ f_0d5630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert unbedingt (ohne Vorprüfung der UI-Sperrflags) die Lebens- und
 *   Astralleisten aller sieben Heldenplätze über f_0d4b90 und löscht die Balken leerer Plätze über f_0d56c0.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5630(void)
{
    int a[7];
    short i, j;
    int q;
    f_145300(a, 1, 7);
    q = d_1bc8f0;
    for (i = 0; i <= 6; i++, q += 0x5ef) {
        if (((char)(f_042350((struct hero *)(q))))) {
            f_0d4b90(q, f_043df0(q), 0);
            a[f_043df0(q)] = 0;
        }
    }
    for (j = 0; j <= 6; j++)
        if (a[j]) f_0d56c0((int)&d_1c2bcc, j);
}

//@ f_0d56c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löscht die beiden vertikalen Lebens- und Astralenergie-Balken eines unbesetzten
 *   Gruppenplatzes idx (x = d_1a5544[idx]) durch Übermalen mit schwarzen Linien (f_148450) und markiert den
 *   Platz in UB(p, idx + 0xc) = 1 als geleert.
 * - Eingaben: Übergeben werden der Zeiger p auf die Statusleisten-Struktur sowie der Spaltenindex idx (0 bis 6).
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d56c0(int p, short idx)
{
    short i, x;
    volatile int fl;
    if (!UB(p, idx + 0xc)) {
        x = d_1a5544[idx];
        if (f_0d3860() == 1) {
            f_0d2710();
            fl = 1;
        } else fl = 0;
        for (i = 0; i < 3; i++) {
            f_148450(d_1a34e0, x + 0x22 + i, 0x9e, 0x1e, 0);
            f_148450(d_1a34e0, x + 0x26 + i, 0x9e, 0x1e, 0);
        }
        UB(p, idx + 0xc) = 1;
        if (fl == 1) f_0d26e0();
    }
}

//@ f_0d5780
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Eingabeverarbeitungsfunktion wertet in der Hauptschleife die Funktionstasten,
 *   Buchstaben-Hotkeys und Porträtklicks (0xf1 bis 0xf7) aus: Gruppentrennung/-zusammenführung (f_041b60),
 *   Rasten/Lager (f_04e350), Uhrzeit/Datum ausgeben (0xe3, f_1265c0), Zaubern/Gegenstand/Tagebuch (f_0cdad0),
 *   Automap öffnen (f_05b860), Charakterbogen bei Doppelklick auf ein Porträt öffnen (f_04f3f0) oder
 *   Gruppenanführer wechseln (f_041d90).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen, sondern liest d_1bd762 und d_1bd766.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
struct MsgC5780 { int h; MsgC5780() { f_0ce7c0((int)this); } ~MsgC5780() { f_0ce7e0((int)this, 0); } };
int f_133fe0(int p1);
int f_1265c0_x(int, int);
#pragma aux f_1265c0_x "f_1265c0" parm [edx] [eax] modify exact [eax ebx ecx edx];
void f_0d5780(void)
{
    short n, m;
    short k;
    int c;
    f_068f40();
    f_0d5a90();
    if (d_1bd762 == 0x3c00 || d_1bd762 == 0x180f) {
        f_041b60();
        d_1bd766 = 0;
    } else if (d_1bd762 == 0x4200 || d_1bd762 == 0x1205) {
        short z = 0;
        f_04e350();
        d_1bd766 = z;
    } else if (d_1bd762 == 0x3e00 || d_1bd762 == 0x1414) {
        d_1bd766 = 0xe3;
    } else if (d_1bd762 == 0x3f00 || d_1bd762 == 0x240a) {
        d_1bd766 = 0xe1;
    } else if (d_1bd762 == 0x4400 || d_1bd762 == 0x1709) {
        d_1bd766 = 0xe2;
    } else if (d_1bd762 == 0x4300 || d_1bd762 == 0x1117) {
        d_1bd766 = 0xe4;
    }
    if (d_1bd766 == 0xfd || d_1bd766 == 0xe1 || d_1bd766 == 0xe2 || d_1bd762 == 0x1e01 || d_1bd766 == 0xe4)
        f_0cdad0();
    if (d_1bd762 == 0x4100 || d_1bd762 == 0x2004) {
        switch (f_0de800(d_1c0004)) {
        case 0x16:
        case 0x17:
        case 0x18:
        case -1:
        case 0x19:
        case 6:
        case 0x1a:
            {
                int t = (int)operator new(0x652, mark(d_1a5a3c, 0x3bc));
                int q = t ? f_059d50(t) : t;
                f_05b860(q, 0);
                if (q) operator delete((void *)f_059d50(q, 0));
            }
            break;
        }
    }
    if (d_1bd766 >= 0xf1 && d_1bd766 <= 0xf7) {
        n = f_0de7f0(d_1c0004);
        m = n;
        c = 0;
        if (f_039040(d_1c0004)) m--;
        k = d_1bd766 - 0xf1;
        if (k == 6) c = f_039040(d_1c0004);
        else if (k < m) c = f_0de7d0(d_1c0004, k);
        if (f_0bba10((int)&d_1bf230) == 1) {
            if (f_0d3800()) {
                if (c) {
                    f_0d37e0();
                    f_09a140(0, 0x19);
                    if (d_1bc760) f_01e0c0();
                    {
                        MsgC5780 mc;
                        int t = (int)operator new(0x128, mark(d_1a5a3c, 0x3fa));
                        int q = t ? f_04a890(t) : t;
                        d_1bd766 = 0;
                        f_04f3f0(q, c);
                        if (q) operator delete((void *)f_04ad40(q, 0));
                    }
                    f_09a140(0, 0x19);
                    f_09a0d0(d_1a34e0);
                }
            } else if (d_1a966a) {
                if (c) {
                    short z = 0;
                    f_041d90((short)(d_1bd766 - 0xf1));
                    d_1bd766 = z;
                }
            }
        }
    }
    if (d_1bd766 == 0xe3) {
        f_1265c0_x((int)&d_1c21b4, (int)&d_1c2c44);
        f_0bf730((int)&d_1c2c64, f_133fe0((int)&d_1c3498));
    }
}
//@ f_0d5a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet bei Druck auf die Options-Taste (0x3d00 / F3, 0x1f13 / 'S' oder Aktionscode
 *   0xe0) das Spieloptions- und Speicher-/Lademenü (f_0d78a0, f_0d8520) und setzt danach d_1bfa78 = 1.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d5a90(void)
{
    int buf[1];
    int p;
    int q;
    d_1bfa78 = 0;
    if (d_1c21a2 == (short)0 && (((d_1bd762 == 0x3d00 || d_1bd762 == 0x1f13) && d_1bfb34 == 0) || d_1bd766 == 0xe0)) {
        f_0ce7c0((int)buf);
        if (d_1bc760 != 0) f_01e0c0();
        q = (int)new (mark(d_1a5a3c, 0x43c)) T11f;
        p = q ? f_0d78a0(q) : q;
        f_0d8520(p);
        if ((int)p != 0) operator delete((void *)f_0d78b0(p, 0));
        d_1bfa78 = 1;
        f_0ce7e0((int)buf, 0);
    }
}
