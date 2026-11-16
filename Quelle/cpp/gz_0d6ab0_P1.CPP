/* === Beschreibung (Katalog) ===
 * Einheit gz_0d6ab0
 *
 * Diese Einheit bildet den zweiten Teil von numinput.cpp und implementiert den Destruktor, die Wertberechnung,
 * die Koordinaten-Getter/Setter, die Zeichenroutinen sowie die interaktive Eingabeschleife (f_0d6e10) des
 * grafischen Zahleneingabefeldes (NI).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 4/9 gleich (suche.py 24.10.2026, Basis gz_0d6ab0_P1.CPP)
// gz_0d6ab0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D6AB0-0x0D7430
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_045db0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_05ebd0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
short f_0c0030(int p1, int p2);                           // reg eax edx stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
void f_0d4800(int p1);                                   // reg eax stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
int f_149d20();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1bd766;                    // 0x1BD766
extern short d_1bd90c;                    // 0x1BD90C
extern int d_1bf4e8;                    // 0x1BF4E8
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3078;                    // 0x1C3078
extern int d_1c38b0;                    // 0x1C38B0

// ---- Struktur aus Offsets (zp1) ----
struct NI {
    short active;      // +0
    short x;           // +2
    short y;           // +4
    short step;        // +6
    short ndig;        // +8
    short r0;          // +A
    short sel;         // +C
    signed char dig[5];// +E
    short vmax;        // +13
    short vmin;        // +15
    int i0, i1, i2, i3, i4, i5, i6;   // +17 .. +2F
    int flag;          // +33
};
short f_0c0030_dummy;
#define LKB(v) int v = 0; if (f_0d3860() == 1) { v = 1; f_0d2710(); }
#define LKE(v) if (v == 1) f_0d26e0();
struct IMG { ~IMG(); };

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0d6ab0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt die sieben im Zahleneingabe-Objekt p (i0 bis i6, Offsets +0x17 bis +0x2f)
 *   gespeicherten Grafik-Sprites wieder frei.
 * - Eingaben: Übergeben werden der this-Zeiger p des Zahleneingabe-Objekts sowie ein ungenutzter
 *   Destruktor-Parameter p2.
 * - Rückgabewert: Zurückgegeben wird der Zeiger p auf das abgebaute Zahleneingabe-Objekt.
 === Ende Beschreibung === */
NI *f_0d6ab0(NI *p, int p2)
{
    delete (IMG *)p->i0;
    delete (IMG *)p->i1;
    delete (IMG *)p->i2;
    delete (IMG *)p->i3;
    delete (IMG *)p->i4;
    delete (IMG *)p->i5;
    delete (IMG *)p->i6;
    return p;
}

//@ f_0d6b40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode berechnet aus den p->ndig einzelnen Dezimalziffern im Array p->dig (Offset +0x0e) durch
 *   Multiplikation mit Zehnerpotenzen den dargestellten Zahlenwert.
 * - Eingaben: Als Parameter wird der this-Zeiger p des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Zurückgegeben wird der aus den Ziffern zusammengesetzte ganzzahlige Wert.
 === Ende Beschreibung === */
int f_0d6b40(NI *p)
{
    int sum = 0;
    short mul = 1;
    short i;
    for (i = p->ndig - 1; i >= 0; i = i - 1) {
        sum = sum + p->dig[i] * mul;
        mul = mul * 10;
    }
    return sum;
}

//@ f_0d6b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode gibt die X-Bildschirmkoordinate (p->x, Offset +2) des Zahleneingabefeldes
 *   zurück.
 * - Eingaben: Als Parameter wird der this-Zeiger p des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Zurückgegeben wird die X-Koordinate als 16-Bit-Ganzzahl.
 === Ende Beschreibung === */
short f_0d6b90(NI *p) { return p->x; }
//@ f_0d6ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Getter-Methode gibt die Y-Bildschirmkoordinate (p->y, Offset +4) des Zahleneingabefeldes
 *   zurück.
 * - Eingaben: Als Parameter wird der this-Zeiger p des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Zurückgegeben wird die Y-Koordinate als 16-Bit-Ganzzahl.
 === Ende Beschreibung === */
short f_0d6ba0(NI *p) { return p->y; }
//@ f_0d6bb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die X-Bildschirmkoordinate (p->x, Offset +2) des Zahleneingabefeldes auf
 *   den Wert v.
 * - Eingaben: Übergeben werden der this-Zeiger p sowie die neue X-Koordinate v.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d6bb0(NI *p, short v) { p->x = v; }
//@ f_0d6bc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Setter-Methode setzt die Y-Bildschirmkoordinate (p->y, Offset +4) des Zahleneingabefeldes auf
 *   den Wert v.
 * - Eingaben: Übergeben werden der this-Zeiger p sowie die neue Y-Koordinate v.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d6bc0(NI *p, short v) { p->y = v; }

//@ f_0d6bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zeichenmethode gibt für jede der p->ndig Ziffernstellen das obere Pfeil-Sprite (p->i3), das
 *   mittlere Ziffernfeld-Sprite (p->i0) und das untere Pfeil-Sprite (p->i4) sowie rechts daneben die
 *   OK-Schaltfläche (p->i1) auf dem Bildschirm d_1a34e0 aus.
 * - Eingaben: Als Parameter wird der this-Zeiger p des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d6bd0(NI *p)
{
    volatile int lk;
    short i;
    if (f_0d3860() == 1) { int one = 1; f_0d2710(); lk = one; } else lk = 0;
    for (i = 0; i < p->ndig; i++) {
        ((RivaRasterImage*)(p->i3))->f_0fae30((void *)( d_1a34e0), (short)(p->x - 4 + p->step * i), (short)(p->y - 12), 1);
        ((RivaRasterImage*)(p->i0))->f_0fade0((void *)( d_1a34e0), (short)(p->x - 4 + p->step * i), (short)(p->y - 4));
        ((RivaRasterImage*)(p->i4))->f_0fae30((void *)( d_1a34e0), (short)(p->x - 4 + p->step * i), (short)(p->y + 13), 1);
    }
    ((RivaRasterImage*)(p->i1))->f_0fade0((void *)( d_1a34e0), (short)(p->x - 4 + p->step * i + 16), (short)(p->y - 4));
    if (lk == 1) f_0d26e0();
}

//@ f_0d6ce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zeichenmethode gibt die aktuellen ASCII-Ziffern (p->dig[i] + '0') zentriert in ihren jeweiligen
 *   Ziffernkästchen aus und hebt dabei die aktuell ausgewählte Ziffernstelle p->sel farblich hervor (0xfd).
 * - Eingaben: Als Parameter wird der this-Zeiger p des Zahleneingabe-Objekts übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d6ce0(NI *p)
{
    short i;
    signed char c;
    unsigned char w;
    short x = p->x;
    volatile int lk;
    if (f_0d3860() == 1) { f_0d2710(); lk = 1; } else lk = 0;
    for (i = 0; i < p->ndig; i++, x += p->step) {
        if (i == p->sel || p->flag) {
            ((RivaRasterImage*)(p->i0))->f_0fade0((void *)( d_1a34e0), (short)(p->x - 4 + p->step * i), (short)(p->y - 4));
            if (i == p->sel)
                f_05e320((int)&d_1c38b0, 0xfd, -1);
        }
        c = p->dig[i] + 0x30;
        w = (unsigned char)f_045db0((int)&d_1c3078, (unsigned char)c);
        f_05ebd0((int)&d_1c38b0, c,
                 (short)((5 - w) / 2 + x),
                 p->y);
        if (i == p->sel)
            f_05e340((int)&d_1c38b0);
    }
    p->flag = 0;
    LKE(lk)
}
//@ f_0d6e10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode stellt das Zahleneingabefeld an der Position (px, py) dar und führt dessen interaktive
 *   Eingabeschleife aus: Sie verarbeitet Zifferntasten ('0'-'9'), Pfeiltasten bzw. Klicks auf die Auf-/Ab-Pfeile
 *   (Ziffer inkrementieren/derementieren mit Übertrag von 9 auf 0), Links-/Rechts-Navigation zwischen den
 *   Stellen, Abbruch per Escape/Rechtsklick (-1) sowie Bestätigung per Enter/OK-Klick, wobei Werte außerhalb von
 *   [p->vmin, p->vmax] automatisch auf den Grenzwert korrigiert und neu angezeigt werden.
 * - Eingaben: Übergeben werden der this-Zeiger p des Zahleneingabe-Objekts sowie die Bildschirmkoordinaten px
 *   und py.
 * - Rückgabewert: Zurückgegeben wird der bestätigte Zahlenwert im Bereich [vmin, vmax] oder -1 bei Abbruch durch
 *   den Spieler.
 === Ende Beschreibung === */
static inline int wertK(NI *p)
{
    int sum = 0;
    short i;
    short mul = 1;
    for (i = p->ndig - 1; i >= 0; i = i - 1) {
        sum = sum + mul * p->dig[i];
        mul = mul * 10;
    }
    return sum;
}
static inline int wertE(NI *p){ int sum=0; short i; short mul=1; for(i=p->ndig-1;i>=0;i--){int d=p->dig[i]; int f=mul; sum += f*d; mul*=10;}return sum;}
static inline int wertH(NI *pH)
{
    int sum = 0;
    short mul = 1;
    short i;
    for (i = pH->ndig - 1; i >= 0; i = i - 1) {
        sum = sum + mul * pH->dig[i];
        mul = mul * 10;
    }
    return sum;
}
static inline int wertZ(NI *pE)
{
    int sum = 0;
    short i;
    short mul = 1;
    for (i = pE->ndig - 1; i >= 0; i = i - 1) {
        sum = sum + pE->dig[i] * mul;
        mul = mul * 10;
    }
    return sum;
}
static inline int wertR(NI *p)
{
    int sum = 0;
    short i;
    short mul = 1;
    i = p->ndig - 1;
    NI *q = p;
    for (; i >= 0; i = i - 1) {
        sum += q->dig[i] * mul;
        mul *= 10;
    }
    return sum;
}
static inline int wE2(NI *p){ int sum=0; short mul=1; short i; for(i=p->ndig-1;i>=0;i=i-1){ sum = sum + p->dig[i] * mul; mul = mul * 10; } return sum; }
short f_0d6e10(NI *p, short px, short py)
{
    volatile int lk2, lk0, lk1, lk3, lk4;
    NI *qE, *qH, *qq; // this-Kopien der drei Summenbloecke (Enter/Hoch/Runter); Zuweisung im Ziffernzweig haelt sie im Speicher
    short mul;
    short val;
    short result;
    short key;
    int sum;
    short i;

    p->active = 1;
    p->x = px;
    p->y = py;
    result = 0;
    { if (f_0d3860() == 1) { f_0d2710(); lk0 = 1; } else lk0 = 0;
    f_0d6bd0(p);
    f_0d6ce0(p);
    if (lk0 == 1) f_0d26e0(); }
    if (d_1bd90c == (short)0)
    f_0d4800(7);
w:
    f_0d3870();
    { int r; do { while (f_0d3780()); } while ((r = f_0d37b0()) != 0); d_1bf4e8 = 0; }
    f_149d20();
    key = 0;
    while (key != 13) {
        key = f_0c0030((int)&d_1c2c64, (int)p);
        if (!key) key = 13;
        if (key == 13) {
            { if (f_0d3860() == 1) { f_0d2710(); lk1 = 1; } else lk1 = 0;
            ((RivaRasterImage*)(p->i2))->f_0fade0((void *)( d_1a34e0), (short)(p->x - 4 + p->ndig * p->step + 16), (short)(p->y - 4));
            if (lk1 == 1) f_0d26e0(); }
            { short m_ = 1; int s_ = 0; short i_; qE = p; for (i_ = p->ndig - 1; i_ >= 0; i_ = i_ - 1) { s_ = s_ + qE->dig[i_] * m_; m_ = m_ * 10; } sum = s_; }
            if (sum <= p->vmax && sum >= p->vmin) {
                result = sum;
            } else {
                { int u = sum; sum = u; } // haelt die Registerzuteilung wie im Original
                if (sum < p->vmin) {
                    val = p->vmin; key = 0;
                } else {
                    val = p->vmax; key = 0;
                }
            }
            f_0d4800(5);
            { if (f_0d3860() == 1) { f_0d2710(); lk2 = 1; } else lk2 = 0;
            ((RivaRasterImage*)(p->i1))->f_0fade0((void *)( d_1a34e0), (short)(p->x - 4 + p->ndig * p->step + 16), (short)(p->y - 4));
            if (lk2 == 1) f_0d26e0(); }
            if (!key) {
                mul = 1;
                if (!val) {
                    for (i = 0; i < p->ndig; i++) p->dig[i] = 0;
                } else {
                    for (i = 0; i < p->ndig - 1; i++) mul *= 10;
                    for (i = 0; i < p->ndig; i++) {
                        if (i != p->ndig - 1) {
                            p->dig[i] = val / mul;
                            val %= mul;
                            mul /= 10;
                        } else {
                            p->dig[i] = val;
                        }
                    }
                }
                p->flag = 1;
                f_0d6ce0(p);
            }
        } else if (key == 27 || f_0d37b0()) {
            d_1bd766 = 0;
            result = -1;
            break;
        } else if (d_1bd766 == 0x4800) {
            { if (f_0d3860() == 1) { f_0d2710(); lk3 = 1; } else lk3 = 0;
            ((RivaRasterImage*)(p->i5))->f_0fae30((void *)( d_1a34e0), (short)(p->sel * p->step + (p->x - 4)), (short)(p->y - 12), 1);
            if (lk3 == 1) f_0d26e0(); }
            p->dig[p->sel]++;
            if (p->dig[p->sel] == 10) p->dig[p->sel] = 0;
            { int s_ = 0; short i_; short m_ = 1; qH = p; for (i_ = p->ndig - 1; i_ >= 0; i_ = i_ - 1) { s_ = s_ + qH->dig[i_] * m_; m_ = m_ * 10; } sum = s_; } sum -= sum; p = (NI *)((int)p + sum); // haelt die Registerzuteilung wie im Original
            f_0d4800(5);
            { if (f_0d3860() == 1) { f_0d2710(); lk4 = 1; } else lk4 = 0;
            ((RivaRasterImage*)(p->i3))->f_0fae30((void *)( d_1a34e0), (short)(p->x - 4 + p->sel * p->step), (short)(p->y - 12), 1);
            if (lk4 == 1) f_0d26e0(); }
            f_0d6ce0(p);
        } else if (d_1bd766 == 0x5000) {
            { volatile int lk5; if (f_0d3860() == 1) { f_0d2710(); lk5 = 1; } else lk5 = 0;
            ((RivaRasterImage*)(p->i6))->f_0fae30((void *)( d_1a34e0), (short)(p->x - 4 + p->sel * p->step), (short)(p->y + 13), 1);
            if (lk5 == 1) f_0d26e0(); }
            p->dig[p->sel]--;
            if (p->dig[p->sel] == -1) p->dig[p->sel] = 9;
            { short mu=1; int su=0; short ix; qq=p; ix=p->ndig-1; for(;ix>=0;ix--){su+=qq->dig[ix]*mu; mu*=10;} sum=su; } sum -= sum; p = (NI *)((int)p + sum); // haelt die Registerzuteilung wie im Original
            f_0d4800(5);
            { volatile int lk6;
            { if (f_0d3860() == 1) { f_0d2710(); lk6 = 1; } else lk6 = 0;
            ((RivaRasterImage*)(p->i4))->f_0fae30((void *)( d_1a34e0), (short)(p->x - 4 + p->sel * p->step), (short)(p->y + 13), 1);
            if (lk6 == 1) f_0d26e0(); } }
            f_0d6ce0(p);
        } else if (d_1bd766 == 0x4d00) {
            p->sel++;
            if (p->sel == p->ndig) p->sel = 0;
            f_0d6ce0(p);
        } else if (d_1bd766 == 0x4b00) {
            p->sel--;
            if (p->sel == -1) p->sel = p->ndig - 1;
            f_0d6ce0(p);
        } else if (key >= 0x30 && key <= 0x39) {
            { int s = p->sel; { int u = s; s = u; } p->dig[s] = key - 0x30; } // haelt die Registerzuteilung wie im Original
            qq = qH = qE = p; sum = f_0d6b40(p); sum -= sum; p = (NI *)((int)p + sum); // haelt die Registerzuteilung wie im Original
            f_0d6ce0(p);
            p->sel++;
            if (p->sel == p->ndig) p->sel = 0;
            f_0d6ce0(p);
        }
    }
    do { while (f_0d3780()); } while (f_0d37b0());
    p->active = 0;
    return result;
}
