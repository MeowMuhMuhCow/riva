/* === Beschreibung (Katalog) ===
 * Einheit mosaic
 *
 * Diese Einheit gehört zu mosaic.cpp (sowie am Ende zum Beginn von mouse.cpp) und implementiert das interaktive
 * 9x5-Mosaik-Legespiel (45 Kacheln 0x2d, Grafikarchiv 0x300000/0x300001), einschließlich Grafikaufbau,
 * Kacheltausch, Siegesanimation und der ersten Maus-Interrupt-Routinen (f_0d2670 bis f_0d2920).
 === Ende Beschreibung === */
// P3 17/20 gleich (suche.py 26.10.2026, Basis mosaic_P1.CPP)
// mosaic.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D1440-0x0D2A40
#include <string.h>
#include <bios.h>
#pragma inline_depth(0)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710


struct R { short a, b, c, d; };
struct Spr { char b[9]; Spr(int w, int h); ~Spr(); };
struct M {
    Spr *a0; Spr *a[45]; Spr *b[2]; char *c0; char *c4;
    short sc8, sca, scc, sce, sd0, sd2, sd4, sd6, sd8;
    int da; short sde;
};
typedef short PT;
int f_0ce7c0(int o);
void f_0ce7e0(void *o, int z);
void f_09ac80(int a, int b, int c);
void f_09a140(int a, int b);
int f_09a0d0(int a);
int f_09a120(int a, int b);
int f_09a7d0(int s, int x, int y, int w, int h, int pw, int t);
void f_09ade0(int a, int b, int c);
int f_09aed0(int a);
void __cdecl f_099ef0(void *p, int v, int n);
void __cdecl f_149eb4(void *p, int v, int n);
int f_04feb0(void *s, int sel, int v, int z, int i, int z2, void *b1, void *b2, int w);
int f_050770(void *s, int v, void *p, int n);
void *f_147c84(void *p, int n, void *t);
void f_14d17f(void *p);
#pragma aux f_14d17f modify [ebx ecx edx];
void f_147323(void *p, int a, int b, int c, int d, int e, int f);
#pragma aux f_147323 modify [esp];
int f_1481a0(void *o, int s, int x, int y, int w, int h, int m);
int f_01a820(void *o, int a, int b, int c, int d);
int f_068f40();
int f_069460();
int f_0d2a40();
int f_0d2b70();
int f_0d2f90(int a, int b);
void f_0d3150();
void f_0d31c0();
int f_0d3770();
int f_0d3780();
int f_0d3790();
int f_0d37b0();
int f_0d37c0();
int f_0d3860();
R *f_0d38b0(void *b);
void f_0d38d0(R *r);
int f_0d3950(int a, int b, int c, int d);
int f_0d4800(int a);
int f_0d4880(void *p);
Spr *f_0fac80(void *o, int w, int h);
int f_0fb0b0(Spr *s);
int f_0fb120(Spr *s);
int f_0fae30(Spr *s, int surf, int a, int b, int f);
int f_0fb3a0(Spr *d, Spr *s, int x, int y, int f);
extern int d_1a34e0, d_1a59c4, d_1a9820, d_1bf4a8, d_1bf4cc, d_1bf4d0, d_1bf4d4, d_1bf4dc, d_1bf4e4, d_1bf4e8;
extern int d_1bf498, d_1bf508, d_1bf520, d_1bf524, d_1bf4c8, d_1c0c4c;
extern volatile int d_1c0c94;
extern  unsigned int d_1bf4c0, d_1c3914;
extern short d_1a59c8, d_1a59ca, d_1bf438[], d_1a5962[], d_1bd760, d_1bd766, d_1bf49e, d_1bf4ae, d_1bf4bc, d_1bf4be;
extern volatile short d_1bf4ac;
extern short d_1bf4fa;
extern volatile short d_1bf51c;
extern int d_1bf4f8;
extern short d_1bf4f2, d_1bf95a, d_1bf95c, d_1bf95e;
extern int d_1bf4f0;
extern unsigned short d_1bd762, d_1bf528, d_1bf52a, d_1bf52c, d_1bf52e;
extern short d_1bf494, d_1bf4a0;
extern short d_1bf4a2;
extern signed char d_1bf4ed, d_1bf4ef;
extern char d_1bf4ec;
extern char d_1baac0[], d_1bdbd4[], d_1c2be0[], d_1c2e68[], d_1c2edc[], d_1a59bc[], d_1bf530[], d_1bf53c[];
extern void *d_1bdbe4;
extern const char d_1a5934[];
extern const char d_1a5954[];
void f_0d16a0(M *p);
void f_0d18a0(M *p, PT e);
void f_0d1a90(M *p);
void f_0d1b60(M *p);
void f_0d1cd0(M *p);
void f_0d1eb0(M *p);
void f_0d2050(M *p);
void f_0d2130(M *p, short a, short b, int fl);
int f_0d2440(M *p);
void f_0d26e0();
void f_0d2710();
void f_0d2740();
void f_0d28f0();

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0d1440
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hauptfunktion führt das Mosaik-Rätsel durch: Sie sichert den aktuellen Bildschirminhalt in der
 *   temporären Datei "MOS_SAVE.SCR", lädt die 45 Mosaiksteine und Paletten (f_0d1b60, f_0d1cd0), startet die
 *   interaktive Eingabeschleife f_0d2440, spielt bei erfolgreichem Lösen (r == 0) die Zusammensetz-Animation
 *   f_0d16a0 ab und stellt danach Bildschirm, Palette und Mauseinstellungen wieder her.
 * - Eingaben: Als Parameter wird der this-Zeiger p auf die Mosaik-Verwaltungsstruktur (M) übergeben.
 * - Rückgabewert: Zurückgegeben wird 0, wenn das Mosaik vollständig gelöst wurde, oder 1 bei vorzeitigem Abbruch
 *   bzw. Überschreiten der Zuganzahl.
 === Ende Beschreibung === */
int f_0d1440(M *p)
{
    R sa;
    int l28;
    R sb;
    char buf[8];
    int l18;
    int l1c;
    volatile unsigned fl1; // haelt die Stapelplatz-Reihenfolge wie im Original
    volatile unsigned fl2; // haelt die Stapelplatz-Reihenfolge wie im Original
    short l2c;
    short obj;
    short l34;
    short l38;
    int a;
    int r;
    (void)&sa; // sa adressgenommen: f_0ce7c0 darf sa aendern -> Nullstores bleiben hinter dem Aufruf (Opus 1284)
    f_0ce7c0((int)&obj);
    sa.a = 0;
    sa.b = 0;
    sa.c = 0;
    l34 = (l34 & 0) ? 0 : l34; // haelt die Registerzuteilung wie im Original
    sa.d = 0;
    l1c = d_1c0c94;
    l38 = d_1bf51c;
    l28 = d_1bf524;
    l18 = d_1bf520;
    d_1bf51c = 0;
    l2c = d_1bf4bc;
    l34 = d_1bf4be;
    f_0d2f90(0, 1);
    sa = *f_0d38b0(buf);
    f_0d3950(0, 0, 0x13f, 199);
    f_0d4880(d_1c2e68);
    d_1c0c94 = 0;
    d_1c0c4c++;
    f_0d1b60(p);
    a = f_0d3860();
    if (a == 1) { f_0d2710(); fl1 = 1; } else fl1 = 0;
    f_09ac80(d_1a34e0, (int)d_1a5954, 0);
    f_09a140((int)p->c4, 0x19);
    f_09a0d0(d_1a34e0);
    f_099ef0(p->c0, 0, 0x100);
    f_149eb4(d_1bdbe4, 0, 0x100);
    f_0d1cd0(p);
    if (fl1 == 1) f_0d26e0();
    r = f_0d2440(p);
    if (r == 0) f_0d16a0(p);
    a = f_0d3860();
    if (a == 1) { f_0d2710(); fl2 = 1; } else fl2 = 0;
    f_09a140(0, 0x19);
    f_09a0d0(d_1a34e0);
    f_09ade0(d_1a34e0, (int)d_1a5954, 0);
    f_09aed0((int)d_1a5954);
    f_09a120((int)p->c4, 0x19);
    if (fl2 == 1) f_0d26e0();
    f_0d1a90(p);
    d_1c0c94 = l1c;
    d_1c0c4c--;
    f_0d2f90(l2c, 1);
    (*(volatile short *)&d_1bf4be) = l34;
    sb.a = sa.a;
    sb.b = sa.b;
    sb.c = sa.c;
    sb.d = sa.d;
    f_0d38d0(&sb);
    d_1bf51c = l38;
    d_1bf524 = l28;
    l18 = (l18 & 0) ? 0 : l18; // haelt die Registerzuteilung wie im Original
    (*(volatile int *)&d_1bf520) = l18;
    f_0ce7e0(&obj, 0);
    return r;
}

//@ f_0d16a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion spielt nach dem Lösen des Mosaiks eine achtstufige Animation ab, in der die Abstände
 *   zwischen den 45 Kacheln (9 x 5) schrittweise zusammenrücken, bis ein fugenloses Gesamtbild entsteht, und
 *   wartet anschließend auf einen Mausklick oder Tastendruck.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d16a0(register M *p)
{
    short i, j, x, y, dx, dy, c;
    int a, fl;
    short r; // r hinter fl: Id 11 stellt die Stapelfolge j/r und p/-i wie im Original
    int g, h;
    (void)&fl; // haelt die Variable im Stapel wie im Original
    g = d_1a34e0; d_1a34e0 = g; // haelt die Registerzuteilung wie im Original
    for (i = 0; i < 8; i++) {
        f_0fb120(p->a0);
        for (j = 0; j < 0x2d; j++) {
            c = j % 9;
            r = j / 9;
            x = c * 0x1a + 2;
            y = r * 0x24 + 2;
            dx = (4 - c) * 2;
            dy = (2 - r) * 2;
            if (dx < 0 && dx < -i)
                x -= i + 1;
            else if (dx > 0 && dx > i)
                x += i + 1;
            else
                x += dx;
            if (dy < 0 && dy < -i)
                y -= i + 1;
            else if (dy > 0 && dy > i)
                y += i + 1;
            else
                y += dy;
            f_0fb3a0(p->a0, p->a[j], x, y, 1);
        }
        g = d_1a34e0; d_1a34e0 = g; // haelt die Registerzuteilung wie im Original
        a = f_0d3860();
        if (a == 1) { f_0d2710(); fl = 1; } else fl = 0;
        h = d_1a34e0;
        f_0fae30(p->a0, h, 0x20, 8, 0);
        if (fl == 1) f_0d26e0();
    }
    while (!f_0d3780() && !f_0d37b0() && !_bios_keybrd(_KEYBRD_READY)) f_069460();
    while (!f_0d3790() || !f_0d37c0()) f_069460();
    while (_bios_keybrd(_KEYBRD_READY)) _bios_keybrd(_KEYBRD_READ);
}


//@ f_0d18a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion bewegt die Auswahlmarkierung im 9x5-Mosaikgitter (p->sd6 Spalte 0..8, p->sd4 Zeile
 *   0..4) abhängig vom Richtungscode e (1 = rechts, 2 = links, 3 = hoch, 4 = runter, 5 = Berechnung aus der
 *   aktuellen Mausposition) und setzt das Neuzeichnen-Flag p->da = 1.
 * - Eingaben: Übergeben werden der Zeiger p auf die Mosaik-Struktur sowie der Bewegungsbefehl e.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d18a0(M *p, PT e)
{
    short x, y;
    p->sce = p->sd6;
    p->scc = p->sd4;
    switch (--e) {
    case 0:
        if (p->sd6 >= 8) { p->sd6 = 0; goto done; }
        ++*(volatile short *)&p->sd6;
        p->da = 1;
        return;
        break;
    case 1:
        if (p->sd6 <= 0) p->sd6 = 8;
        else --p->sd6;
        p->da = 1;
        return;
    case 2:
        if (p->sd4 <= 0) p->sd4 = 4;
        else --p->sd4;
        p->da = 1;
        return;
    case 3:
        if (p->sd4 >= 4) p->sd4 = 0;
        else ++p->sd4;
        p->da = 1;
        return;
    case 4:
        if (f_0d3780()) {
            x = d_1bf4f8 - 0x21;
            y = *(volatile short *)&d_1bf4fa - 9;
            d_1bd762 = 0x1c0d;
            while (f_0d3780()) ;
        } else {
            x = d_1bf4f0 - 0x21;
            y = *(volatile short *)&d_1bf4f2 - 9;
        }
        p->sd6 = x / 0x1a;
        p->sd4 = y / 0x24;
        if (p->sd6 < 0) p->sd6 = 0;
        if (p->sd6 > 8) p->sd6 = 8;
        if (p->sd4 < 0) p->sd4 = 0;
        if (p->sd4 > 4) p->sd4 = 4;
    }
done:
    p->da = 1;
}

//@ f_0d1a90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion gibt alle für das Mosaik-Rätsel reservierten 45 Kachel-Sprites (p->a), die 2
 *   Hilfs-Sprites (p->b), das Hintergrund-Sprite (p->a0) sowie die beiden Palettenpuffer (p->c0, p->c4) wieder
 *   frei.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1a90(M *p)
{
    short i;
    for (i = 0; i < 0x2d; i++) delete p->a[i];
    for (i = 0; i < 2; i++) delete p->b[i];
    delete p->a0;
    delete p->c4;
    p->c4 = 0;
    delete p->c0;
    p->c0 = 0;
}

//@ f_0d1b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion setzt die Kachelbelegung d_1bf438 (45 Einträge) auf die
 *   Startpermutation d_1a5962 zurück, wobei kurzzeitig die Mosaik-Ressourcen über f_0d1b60 und f_0d1a90 angelegt
 *   und wieder freigegeben werden.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1b20(M *p)
{
    short i;
    f_0d1b60(p);
    for (i = 0; i < 0x2d; i++) d_1bf438[i] = d_1a5962[i];
    f_0d1a90(p);
}

//@ f_0d1b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert die beiden Palettenpuffer (p->c0, p->c4), lädt die Mosaik-Palette aus dem
 *   Archiv 0x300000 und erzeugt das Haupt-Sprite (236 x 184 Pixel) sowie die 45 Kachel-Sprites (24 x 34 Pixel).
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1b60(M *p)
{
    short i;
    Spr *t;
    Spr *s0;
    char *c;
    c = (char *)f_147c84(new (mark(d_1a5934, 498)) char[0x300], 0x100, d_1baac0);
    p->c0 = c ? c : 0;
    c = (char *)f_147c84(new (mark(d_1a5934, 499)) char[0x300], 0x100, d_1baac0);
    p->c4 = c ? c : 0;
    f_050770(d_1c2be0, 0x300000, p->c0, 0x100);
    f_149eb4(p->c4, 0, 0x100);
    s0 = new (mark(d_1a5934, 507)) Spr(0xec, 0xb8);
    p->a0 = s0;
    f_0fb120(s0);
    for (i = 0; i < 0x2d; i++) {
        t = new (mark(d_1a5934, 525)) Spr(0x18, 0x22);
        p->a[i] = t;
        f_0fb120(t);
    }
    for (i = 0; i < 2; i++) {
        t = new (mark(d_1a5934, 530)) Spr(0x18, 0x22);
        p->b[i] = t;
        f_0fb120(t);
    }
}
//@ f_0d1cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt zu Beginn des Mosaik-Spiels kurz das geordnete Originalbild (0x300000) für 90
 *   Zeitticks (f_0d4800(0x5a)) an und vertauscht anschließend sichtbar Schritt für Schritt die 45 Kacheln über
 *   f_0d2130 gemäß der aktuellen Mischbelegung d_1bf438.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1cd0(M *p)
{
    short s[45];
    struct { int fl; char b[4]; } v;
    short j, k, i;
    int a;
    a = f_0d3860();
    if (a == 1) { f_0d2710(); v.fl = 1; } else v.fl = 0;
    for (i = 0; i < 0x2d; i++) {
        s[i] = i;
        f_04feb0(d_1c2be0, 0x300000, f_0fb0b0(p->a[0]), 0, i, 0, v.b, v.b, 0x140);
        { short a0_ = (i % 9) * 0x1a + 2; short a1_ = (i / 9) * 0x24 + 2; f_0fb3a0(p->a0, p->a[0], a0_, a1_, 1); }
    }
    f_0fae30(p->a0, d_1a34e0, 0x20, 8, 1);
    f_0d4800(0x5a);
    for (i = 0; i < 0x2d; i++) {
        if (i == d_1bf438[i]) f_04feb0(d_1c2be0, 0x300000, f_0fb0b0(p->a[i]), 0, i, 0, v.b, v.b, 0x140);
        else f_04feb0(d_1c2be0, 0x300001, f_0fb0b0(p->a[i]), 0, i, 0, v.b, v.b, 0x140);
    }
    for (j = 0; j < 0x2d; j++) {
        k = 0;
        while (d_1bf438[j] != s[k]) k++;
        f_0d2130(p, d_1bf438[j], s[k], 0);
        {
            short t = d_1bf438[j];
            d_1bf438[j] = s[k];
            s[k] = t;
        }
        f_0fae30(p->a0, d_1a34e0, 0x20, 8, 1);
    }
    if (v.fl == 1) f_0d26e0();
}

//@ f_0d1eb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zeichenfunktion aktualisiert die farbigen Auswahlrahmen (f_1481a0) um die aktuell fokussierte
 *   Kachel (p->sd2, p->sd0) und eine bereits zum Tausch ausgewählte erste Kachel (p->sca, p->sc8) auf dem
 *   Bildschirm.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d1eb0(M *p)
{
    volatile int c;
    int a;
    a = f_0d3860();
    if (a == 1) { f_0d2710(); c = 1; } else c = 0;
    if (p->sd8 == 0) {
        p->sd0 = p->sd4;
        p->sd2 = p->sd6;
    } else {
        p->sc8 = p->sd4;
        p->sca = p->sd6;
    }
    f_1481a0(d_1bdbd4, d_1a34e0, (short)(p->sce * 0x1a + 0x21), (short)(p->scc * 0x24 + 9), 0x1a, 0x24, 1);
    if (p->sd8 == 2) {
        { int t_ = (int)(d_1a34e0); f_1481a0(d_1bdbd4, t_, (short)(p->sd2 * 0x1a + 0x21), (short)(p->sd0 * 0x24 + 9), 0x1a, 0x24, 1); }
        short t = p->sd4;
        p->sd8 = 0;
        p->sd0 = t;
        p->sd2 = p->sd6;
    }
    f_1481a0(d_1bdbd4, d_1a34e0, (short)(p->sd2 * 0x1a + 0x21), (short)(p->sd0 * 0x24 + 9), 0x1a, 0x24, -3);
    if (p->sd8 == 1)
        { int t_ = (int)(d_1a34e0); f_1481a0(d_1bdbd4, t_, (short)(p->sca * 0x1a + 0x21), (short)(p->sc8 * 0x24 + 9), 0x1a, 0x24, -7); }
    if (c == (short)1) f_0d26e0();
}

//@ f_0d2050
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion vertauscht die beiden vom Spieler ausgewählten Mosaikkacheln an den Gitterindizes y =
 *   p->sc8 * 9 + p->sca und x = p->sd0 * 9 + p->sd2 sowohl grafisch (f_0d2130) als auch im Belegungsarray
 *   d_1bf438.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2050(M *p)
{
    int c;
    short y, x;
    if (f_0d3860() == 1) {
        f_0d2710();
        c = 1;
    } else {
        c = 0;
    }
    p->sd8 = 2;
    p->da = 1;
    y = p->sc8 * 9 + p->sca;
    x = p->sd0 * 9 + p->sd2;
    f_0d2130(p, y, x, 1);
    {
        p = (M*)(unsigned short)d_1bf438[y];
        d_1bf438[y] = d_1bf438[x];
        d_1bf438[x] = (short)(unsigned)p;
    }
    if (c == 1) f_0d26e0();
}

//@ f_0d2100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Prüffunktion kontrolliert alle 45 Plätze des Arrays d_1bf438 darauf, ob jede Kachel i an ihrer
 *   korrekten Zielposition (d_1bf438[i] == i) liegt.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 0, wenn das Mosaik vollständig gelöst ist, oder 1, sobald mindestens eine
 *   Kachel noch falsch liegt.
 === Ende Beschreibung === */
int f_0d2100()
{
    int r = 0;
    short i;
    for (i = 0; i < 0x2d && r == 0; i++) {
        if (i != d_1bf438[i]) r = 1;
    }
    return r;
}

//@ f_0d2130
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet die beiden Kacheln an den Positionen a und b neu (mit heller Grafik 0x300000,
 *   wenn eine Kachel auf ihrem richtigen Platz landet, sonst 0x300001), spielt bei fl == 1 und korrekter
 *   Zielposition einen Aufblendeffekt (f_09a7d0) ab und kopiert das Mosaik auf den Bildschirm.
 * - Eingaben: Übergeben werden der Zeiger p auf die Mosaik-Struktur, die beiden Kachelpositionen a und b sowie
 *   das Effekt-Flag fl.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2130(M *p, short a, short b, int fl)
{
    char buf[4];
    short ub;
    short y;
    short ua;
    short x;
    ua = d_1bf438[a];
    ub = d_1bf438[b];
    if (b == ua)
        f_04feb0(d_1c2be0, 0x300000, f_0fb0b0(p->a[ua]), 0, ua, 0, buf, buf, 0x140);
    else
        f_04feb0(d_1c2be0, 0x300001, f_0fb0b0(p->a[ua]), 0, ua, 0, buf, buf, 0x140);
    if (ub == a)
        f_04feb0(d_1c2be0, 0x300000, f_0fb0b0(p->a[ub]), 0, ub, 0, buf, buf, 0x140);
    else
        f_04feb0(d_1c2be0, 0x300001, f_0fb0b0(p->a[ub]), 0, ub, 0, buf, buf, 0x140);
    x = (b % 9) * 0x1a + 2;
    y = (b / 9) * 0x24 + 2;
    if (b == ua && (*&fl) == 1) {
        short y2 = y + 8;
        short x2 = x + 0x20;
        short n = 0, t = 0;
        x2 |= x2 & 0;
        for (; n < 6; n++, t += 6)
            f_09a7d0(d_1a34e0, x2, y2, 0x18, 0x22, 0x140, t);
    b = (b & 0) ? 0 : b; // haelt die Registerzuteilung wie im Original
    }
    f_0fb3a0(p->a0, p->a[ua], x, y, 1);
    f_0fae30(p->a0, d_1a34e0, 0x20, 8, 1);
    x = (a % 9) * 0x1a + 2;
    y = (a / 9) * 0x24 + 2;
    if (ub == a && (*&fl) == 1) {
        short y2 = y + 8;
        short x2 = x + 0x20;
        short n = 0, t = 0;
        x2 |= x2 & 0;
        for (; n < 6; n++, t += 6)
            f_09a7d0(d_1a34e0, x2, y2, 0x18, 0x22, 0x140, t);
    }
    p = (M *)(((int)p & 0) ? 0 : (int)p); // haelt die Registerzuteilung wie im Original
    f_0fb3a0(p->a0, p->a[ub], x, y, 1);
    f_0fae30(p->a0, d_1a34e0, 0x20, 8, 1);
}

//@ f_0d23c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Wartefunktion blockiert, bis der Spieler eine Maustaste drückt und wieder loslässt oder eine
 *   Taste auf der Tastatur betätigt, und leert anschließend den BIOS-Tastaturpuffer.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d23c0()
{
    while (!f_0d3780() && !f_0d37b0() && !_bios_keybrd(_KEYBRD_READY)) f_069460();
    while (!f_0d3790() || !f_0d37c0()) f_069460();
    while (_bios_keybrd(_KEYBRD_READY)) _bios_keybrd(_KEYBRD_READ);
}

//@ f_0d2440
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt die Haupt-Eingabeschleife des Mosaik-Rätsels aus, verarbeitet Pfeiltasten,
 *   Mausbewegungen, Enter/Mausklick (Auswählen und Tauschen zweier Steine mit Sound 0x270018) sowie Escape
 *   (0x11b) und beendet die Schleife, sobald alle Steine richtig liegen (r == 0) oder das Zuglimit p->sde
 *   erreicht ist.
 * - Eingaben: Als Parameter wird der Zeiger p auf die Mosaik-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 0 bei gelöstem Mosaik oder 1 bei Abbruch bzw. Zugüberschreitung.
 === Ende Beschreibung === */
int f_0d2440(M *p)
{
    int r = 1;
    int done = 0;
    short cnt = 0;
    short px;
    short py;
    short k;
    px = d_1bf4f0;
    py = d_1bf4f2;
    f_0d3770();
    d_1bd766 = 0;
    d_1bd762 = 0;
    d_1bd760 = 0;
    do {
        f_068f40();
        if (d_1bd762 == 0x4d00) f_0d18a0(p, 1);
        if (d_1bd762 == 0x4b00) f_0d18a0(p, 2);
        if (d_1bd762 == 0x4800) f_0d18a0(p, 3);
        if (d_1bd762 == 0x5000) f_0d18a0(p, 4);
        if (p->da == 1) {
            f_0d1eb0(p);
            p->da = 0;
        }
        if (*(volatile short *)&d_1bf4f0 != px || *(volatile short *)&d_1bf4f2 != py) {
            f_0d18a0(p, 5);
            px = d_1bf4f0;
            py = d_1bf4f2;
        }
        if (f_0d3780()) {
            f_0d18a0(p, 5);
            while (f_0d3780()) ;
        }
        if (d_1bd762 == 0x1c0d) {
            if (p->sd8 == 0) {
                short old = p->sd0;
                p->sd8 = 1;
                p->da = 1;
                p->sc8 = old;
                p->sca = p->sd2;
            } else {
                { int t_ = (int)(d_1a9820); f_147323(d_1c2edc, 0x270018, 0x7fff, 0x8000, t_, 0, 1); }
                cnt++;
                f_0d2050(p);
                r = 0;
                for (k = 0; k < 0x2d && r == 0; k++) {
                    if (k != d_1bf438[k]) r = 1;
                }
                if (r == 0) done = 1;
            }
        }
        if (d_1bd762 == 0x11b) {
            if (p->sd8 == 0) {
                cnt = p->sde;
            } else {
                p->sd8 = 2;
                p->da = 1;
            }
        }
        if (cnt >= p->sde) done = 1;
    } while (!done);
    return r;
}

//@ f_0d2670
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion (Beginn von mouse.cpp) richtet das Standard-Mausbegrenzungsrechteck
 *   (0, 0, 319, 199) (d_1bf528) sowie die beiden 16 x 16 Pixel großen Sprites für den Mauszeiger (d_1bf530) und
 *   den geretteten Bildschirmhintergrund (d_1bf53c) ein.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2670()
{
    f_14d17f(d_1a59bc);
    f_01a820(&d_1bf528, 0, 0, 0x13f, 199);
    f_0fac80(d_1bf530, 0x10, 0x10);
    d_1a59c4 = 1;
    f_0fac80(d_1bf53c, 0x10, 0x10);
    d_1a59c4 = 2;
}

void f_0d2670_halt()
{
    d_1a59c4 = 3;
}

//@ f_0d26d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist eine leere Platzhalterfunktion im Mausmodul ohne ausführbare Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d26d0()
{
}

//@ f_0d26e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet den Mauszeiger über f_0d31c0 wieder auf dem Bildschirm ein und setzt das
 *   Sichtbarkeitsflag d_1bf508 = 1, sofern die Maus aktiv (d_1bf4ef == 0) und aktuell ausgeblendet (d_1bf508 ==
 *   0) ist.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d26e0()
{
    if (d_1bf4ef == 0 && d_1bf508 == 0) {
        f_0d31c0();
        d_1bf508 = 1;
    }
}

//@ f_0d2710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion blendet den Mauszeiger vor Zeichenoperationen über f_0d3150 aus und setzt d_1bf508 =
 *   0, sofern die Maus aktiv (d_1bf4ef == 0) und aktuell sichtbar (d_1bf508 == 1) ist.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2710()
{
    if (d_1bf4ef == 0 && d_1bf508 == 1) {
        f_0d3150();
        d_1bf508 = 0;
    }
}

//@ f_0d2740
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wertet die in der Bitmaske d_1bf95a aufgelaufenen Mausereignisse aus (Bit 1: Bewegung
 *   mit Clamping auf das Begrenzungsrechteck d_1bf528, Bit 2/4: linke Taste gedrückt/losgelassen inklusive
 *   Doppelklick-Erkennung über den Systemtimer d_1c3914, Bit 8/0x10: rechte Taste gedrückt/losgelassen) und
 *   stößt bei Bedarf das Neuzeichnen des Mauszeigers (f_0d2a40) an.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2740()
{
    if (*(unsigned char *)&d_1bf95a & 2) {
        d_1bf4d4 = 1;
        *(int *)&d_1bf4e8 = 1;
        *(int *)&d_1bf4cc = 1;
        *(short *)&d_1bf4f8 = *(short *)&d_1bf4f0;
        d_1bf4fa = d_1bf4f2;
        if (d_1bf4c0 + 6 >= d_1c3914 && d_1bf4c8 != 0) {
            d_1bf4d0 = 1;
            *(int *)&d_1bf4c8 = 0;
        } else {
            *(volatile unsigned int *)&d_1bf4c0 = *(volatile unsigned int *)&d_1c3914;
            *(volatile int *)&d_1bf4c8 = 1;
            d_1bf4d0 = 0;
        }
        d_1bf4ec = 1;
    }
    if (*(unsigned char *)&d_1bf95a & 4) {
        *(volatile int *)&d_1bf4d4 = 0;
        *(volatile int *)&d_1bf4cc = 1;
        d_1bf4ec = 1;
    }
    if (*(unsigned char *)&d_1bf95a & 8) {
        d_1bf4e4 = 1;
        d_1bf4dc = 1;
        *(volatile short *)&d_1bf4f8 = d_1bf4f0;
        *(volatile short *)&d_1bf4fa = d_1bf4f2;
        d_1bf4ec = 1;
    }
    if (*(unsigned char *)&d_1bf95a & 0x10) {
        d_1bf4e4 = 0;
        d_1bf4ec = 1;
    }
    if (*(unsigned char *)&d_1bf95a & 1) {
        *(volatile short *)&d_1bf4f0 = d_1bf95c;
        d_1bf4f2 = d_1bf95e;
        if (*(volatile short *)&d_1bf4f0 > (unsigned short)((R *)&d_1bf528)->c) *(volatile short *)&d_1bf4f0 = ((R *)&d_1bf528)->c;
        if (*(volatile short *)&d_1bf4f0 < (int)d_1bf528) *(volatile short *)&d_1bf4f0 = d_1bf528;
        if (d_1bf4f2 < (unsigned short)((R *)&d_1bf528)->b) *(volatile short *)&d_1bf4f2 = ((R *)&d_1bf528)->b;
        if (d_1bf4f2 > (unsigned short)((R *)&d_1bf528)->d) d_1bf4f2 = ((R *)&d_1bf528)->d;
        d_1bf4ec = 1;
        d_1bf4ae = 1;
    }
    if (d_1bf4ed == 0) f_0d2a40();
}

//@ f_0d28f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schützt den Aufruf der Mausereignis-Verarbeitung f_0d2740 durch das
 *   Reentranz-Sperrflag d_1bf4ac vor verschachtelten Interrupt-Aufrufen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d28f0()
{
    if (d_1bf4ac == 0) {
        d_1bf4ac = 1;
        f_0d2740();
        d_1bf4ac = 0;
    }
}

//@ f_0d2920
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese periodisch über einen 100-Hz-Timer aufgerufene Abfragefunktion liest über den Maustreiber
 *   (d_1bf49e = 3, f_0d2b70) die aktuelle Mausposition und den Tastenstatus aus, ermittelt Änderungen gegenüber
 *   dem letzten Stand in d_1bf95a und leitet diese über f_0d28f0 weiter.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2920()
{
    if (d_1bf498 == 0) {
        d_1bf498 = 1;
        d_1bf49e = 3;
        f_0d2b70();
        d_1bf95a = 0;
        if (d_1a59c8 != d_1bf4a2 || d_1a59ca != d_1bf4a8) {
            d_1a59c8 = d_1bf4a2;
            d_1bf95c = d_1bf4a2;
            d_1a59ca = d_1bf4a8;
            d_1bf95e = d_1bf4a8;
            d_1bf95a |= 1;
        }
        if (d_1bf494 != d_1bf4a0) {
            if ((d_1bf494 & 1) != (d_1bf4a0 & 1)) {
                if ((d_1bf4a0 & 1) == 1) d_1bf95a |= 2;
                else d_1bf95a |= 4;
            }
            if ((d_1bf494 & 2) != (d_1bf4a0 & 2)) {
                if (d_1bf4a0 & 2) d_1bf95a |= 8;
                else d_1bf95a |= 0x10;
            }
            d_1bf494 = d_1bf4a0;
        }
        if (d_1bf95a != 0) f_0d28f0();
        d_1bf498 = 0;
    }
}
