/* === Beschreibung (Katalog) ===
 * Einheit gz_113770 (0x113770 - 0x11395c)
 *
 * Überblick
 * Diese Einheit bildet den Abschluss des Moduls spoil.cpp und enthält die Laderoutine für den Spielstandsblock
 * SPOL sowie die Aufräumfunktion für die globale Beutedatei-Verwaltung.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 3/4 gleich (suche.py 25.10.2026, Basis gz_113770_P1.CPP)
// gz_113770.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x113770-0x113970
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_039040(int p1);




int f_041920(int p1);

int f_044300(int p1, int p2);
int f_0bbf00(int p1);
int f_0d4a60(int p1);


int f_0dd7f0(int p1, int p2, int p3);
int f_0de0d0(int p1);
int f_0de810(int p1, int p2);
int f_0de9c0(int p1);
int f_0de9d0(int p1, int p2);

int f_0de9f0(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern char d_1bf230[];
extern int d_1c0004;                    // 0x1C0004
extern char d_1c0028;
extern short d_1c0928;
extern short d_1c0929;
extern short d_1c092c;
extern short d_1c092d;
extern signed char d_1c0960;
extern unsigned char d_1c212a;
extern int d_1c212c;                    // 0x1C212C
extern short d_1c21a4;
#define I(p,o) (*(int *)((p)+(o)))
#define EQI(x,v) (((x)==(v))?1:0)
short f_0db9a0(int p1);
short f_0de9e0(int p1);
short f_0d54f0(int p1, int p2);
char f_041000(void);

int f_041900(void);
int f_0418f0(void);
int f_0418e0(void);

//@ f_113770
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest beim Laden eines Spielstands den Block SPOL (0x4c4f5053) ein und stellt die Statusflags sowie
 *   die noch nicht geplünderten Geldbeträge aller Beutecontainer wieder her.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Block SPOL erfolgreich gelesen wurde, andernfalls 0.
 === Ende Beschreibung === */
void f_113770(void)
{
    struct Obj { signed char a; short b; };
    struct Reg { short count; Obj **list; };
    Obj &a = *(Obj *)&d_1c0928;
    Obj &b = *(Obj *)&d_1c092c;
    Reg &r = *(Reg *)&d_1c212a;
    signed char c = 0;
    a.a = c;
    a.b = 0x239;
    int i = r.count;
    ((Obj ** &)d_1c212c)[i] = &a;
    struct Helper {
        void add(Obj &o, Reg &q, short id) {
            signed char z = 0;
            o.a = z;
            o.b = id;
            q.count++;
            ((Obj ** &)q.list)[q.count] = &o;
            q.count++;
        }
    } h;
    h.add(b, r, 0x23a);
}

//@ f_1137e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für ein übergebenes Gruppenmitglied p1, ob das Statusflag f_0de9c0(p1) ungleich 0 ist und der
 *   Zustandswert f_0de9e0(p1) gleich 2 ist (Suchprädikat für f_0de0d0 in f_113810).
 * - Eingaben: p1 (Zeiger auf einen Helden).
 * - Rückgabewert: 1, wenn beide Bedingungen erfüllt sind, sonst 0.
 * - Wichtige Variablen: iv (Rückgabe von f_0de9c0), s (Rückgabe von f_0de9e0).
 === Ende Beschreibung === */
int f_1137e0(int p1)
{
    int iv;
    int r;
    short s;
    iv = f_0de9c0(p1);
    r = 0;
    if (iv != 0) {
        s = f_0de9e0(p1);
        if (s == 2) {
            r = 1;
        }
    }
    return r;
}

//@ f_113810
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft den Gruppenstatus (f_0db9a0) und sucht über f_0de0d0(f_1137e0) nach einem Gruppenmitglied mit
 *   Status 2; besitzt dieses bei gesetztem Flag d_1c0960 == 1 den Gegenstand 0x1b4 (f_0d54f0), werden seine
 *   Statuswerte zurückgesetzt (f_0de9f0, f_0de9d0), die Szene über f_041920, f_0dd7f0(..., 2, 0x16ba) und
 *   f_0de810(..., 0x66) umgeschaltet, andernfalls wird der Fehler-/Statuscode d_1c21a4 auf 2 bzw. 9 gesetzt.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Immer 1 (int).
 * - Wichtige Variablen: iv (gefundener Held), d_1c21a4 (Ergebnis-/Abbruchcode).
 === Ende Beschreibung === */
int f_113810(void)
{
    int iv, t, r;
    r = 1;
    if (f_0db9a0(d_1c0004) == 0 || (f_0db9a0(d_1c0004) == r && f_039040(d_1c0004) != 0 && f_0d4a60(f_039040(d_1c0004)) != 0)) {
        iv = f_0de0d0((int)f_1137e0);
        if (iv != 0) {
            if (EQI(d_1c0960, 1) && f_0d54f0(iv, 0x1b4) != -1) {
                f_0de9f0(iv, 0);
                f_0de9d0(iv, 0);
                t = f_041900();
                f_0418f0();
                f_041920(iv);
                if (t == 0) {
                    f_0418e0();
                }
                d_1c0028 = f_041000();
                f_0dd7f0(iv, 2, 0x16ba);
                f_0de810(iv, 0x66);
            } else {
                d_1c21a4 = 2;
            }
        } else {
            d_1c21a4 = 9;
        }
    }
    return r;
}

//@ f_113920
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchläuft ein Array p3 von p2 Heldenzeigern, liest für jeden Helden über f_042960 dessen aktuelle
 *   Lebenspunkte aus, übergibt sie an f_044300 und aktualisiert nach jedem Schritt die
 *   Eingabe-/Ereignisverarbeitung über f_0bbf00(d_1bf230).
 * - Eingaben: p1 (ungenutzter Kontextparameter), p2 (Anzahl der Einträge short), p3 (Basisadresse des
 *   Heldenzeiger-Arrays).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: i (Schleifenzähler 0..p2-1), sv (Lebenspunkte des jeweiligen Helden).
 === Ende Beschreibung === */
void f_113920(int p1, short p2, int p3)
{
    short i, sv;
    i = 0;
    for (; i < p2; ) {
        sv = f_042960((struct hero *)(I(p3 + i * 4, 0)));
        f_044300(I(p3 + i * 4, 0), (int)sv);
        i = i + 1;
        f_0bbf00((int)d_1bf230);
    }
}
