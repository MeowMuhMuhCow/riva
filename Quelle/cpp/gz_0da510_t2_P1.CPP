/* === Beschreibung (Katalog) ===
 * Einheit gz_0da510_t2 (0da910 - 0dade0)
 *
 * Überblick
 * Die Einheit gz_0da510_t2 bildet den ersten Teil der Quelldatei panel.cpp (deren zweite Hälfte in
 * panel_gz0db7b0 liegt). Sie verwaltet die seitliche Symbol- und Aktionsschaltflächenleiste (Panel, global
 * d_1bfdb8) in Gebäuden, Läden und im Beutepool, einschließlich Aktivieren/Deaktivieren einzelner
 * Aktionssymbole, Zeichnen der Leiste und Auswerten von Maus- und Tastatureingaben.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 5/9 gleich (suche.py 29.10.2026, Basis gz_0da510_t2_P1.CPP)
// P2 Koepfe Stufe Misch (0 Ueberladungen) (Fable K): 7 gleich (vorher 6), Rest 394 (vorher 398)
// gz_0da510.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DA910-0x0DADE0 (Teil 2, Claude801 29.10.)
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene ---
struct VB;
int f_013710(char *p, int fl);
int f_013da0(char *p);
int f_013db0ext(VB *p);
#define SEL(A, B) if (*(int *)(p + 0x86) == 1) return A; return B;
#define PT int
#define SX(x) (short)(x)
#define IT short
#define IX(x) (x)
#define STO(p) short dd = ft.d; *(short *)(p + 0xa6) = 1; *(int *)(p + 0xa8) = 0; *(short *)(p + 0xa4) = dd;
#pragma aux f_0db020 modify [edx];
int f_014020(char *p, int e, int x);
int f_014020(char *p, int e);
int f_0141d0(char *p);
int f_0141e0(char *p);
int f_014210(char *p);
int f_014240(char *p);
int f_014280(char *p);
int f_0142a0(char *p, int a, int b);
int f_014300(char *p);
int f_0143c0(char *p, char *q, int x);
int f_0a20a0(int a, int b, int c);
int f_0a2450(int a);
int f_0d26e0();
int f_0d2710();
int f_0d37b0();
int f_0d3860();
int f_0d5b50(int a);
int f_0db020(int a);
int f_0db2f0(char *p);
int f_0db3d0(char *p);
int f_0db4a0(char *p, int a, int b, int c);
int f_0dade0(char *p);

int f_149cf0(int a);
int f_145234(int *p, int *q);
int f_1492b4(char *n, int a, void *b);
int f_1492ed(void *b);
int f_144e8b(int h);
int f_144e8b(int h, int e, int c);
int f_1455a4(int h);
int f_145279(int h, int a, int b);
int f_145259(int h);
int f_145300(char *p, int a, int b);
int f_144fbf(char *n, int m, ...);
void f_014710x(int p);
#define MS(a) memset(a, 0, 8)
#define LKB(v) int v = 0; if (f_0d3860() == 1) { v = 1; f_0d2710(); }
#define LKE(v) if (v == 1) f_0d26e0();
// --- Daten ---
extern short d_1a34e0;
extern int d_1bb4a4;
extern int d_1bb4b8[];
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1be17c;
extern short d_1c2198;
struct VB {
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(int a, int b); virtual int v6(); virtual int v7(int a); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15();
    virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21();
    virtual int v22(); virtual short v23();
};
struct FT { char r[21]; char at; short t; short d; int size; char name[13]; };
struct S28 { int a[7]; };
struct E { short id; short v; int on; int x; };

#pragma inline_depth(0)
#define EQ(x,v) (((x)==(v))?1:0)
#pragma inline_depth(3)
//@ f_0da910
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Konstruiert ein Aktionsleisten-Objekt (Panel), speichert die vier Archiv-Ressourcenkennungen
 *   (a2..a5), die Anzahl der Schaltflächenplätze (a6) sowie den Vorauswahl-Index (a7) und initialisiert die
 *   Grafik- und Tabellenpuffer über f_0dade0.
 * - Eingaben: Übergeben werden der Speicherbereich des Panel-Objekts (p), vier Ressourcenkennungen (a2..a5), die
 *   Anzahl der Schaltflächen (a6) sowie der Startindex (a7).
 * - Rückgabewert: Gibt den Zeiger auf das initialisierte Panel-Objekt (p) zurück.
 === Ende Beschreibung === */
char *f_0da910(char *p, int a2, int a3, int a4, int a5, short a6, short a7)
{
    *(int *)p = a2;
    *(int *)(p + 4) = a3;
    *(int *)(p + 8) = a4;
    *(int *)(p + 0xc) = a5;
    *(short *)(p + 0x20) = 0;
    *(int *)(p + 0x22) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1c) = 0;
    *(int *)(p + 0x36) = 0;
    *(short *)(p + 0x12) = a6;
    *(short *)(p + 0x10) = a7;
    *(int *)(p + 0x3a) = 0;
    MS(p + 0x26);
    MS(p + 0x2e);
    f_0dade0(p);
    return p;
}
//@ f_0da990
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Baut ein Aktionsleisten-Objekt (Panel) beim Zerstören über die Aufräumroutine f_0db020 wieder ab.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p) sowie ein ungenutztes Destruktor-Flag (kp2).
 * - Rückgabewert: Gibt den Zeiger auf das Panel-Objekt (p) zurück.
 === Ende Beschreibung === */
int f_0da990(int p, int kp2)
{
    f_0db020(p);
    return p;
}
//@ f_0da9a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Baut die Liste der aktuell sichtbaren Schaltflächen des Panels (*(c + 0x32)) aus den
 *   freigeschalteten Einträgen (s->id != -1 && s->on == 1) der Gesamttabelle (*(c + 0x2a)) neu auf, legt für
 *   jeden belegten und freien Platz ein Klick-Icon-Objekt (f_0a20a0) in *(c + 0x36) an und speichert den Code
 *   der letzten Schaltfläche (cnt + 0x80) in *(short *)(c + 0x20).
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (c).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0da9a0(char *c)
{
    f_0db2f0(c);
    short cnt = 0;
    unsigned f = 0;
    if ((f = *(unsigned *)(c + 0x26)) > 0) *(unsigned *)(c + 0x2e) = f; else *(unsigned *)(c + 0x2e) = 0x20000194;
    short i = 0;
    for (; i < *(short *)(c + 0x12); i++) {
            f = (f & 0) ? 0 : f; // haelt die Registerzuteilung wie im Original
            E *sb = (E *)*(int *)(c + 0x2a);
            E *s = (cnt & 0) ? 0 : sb + i; // haelt die Registerzuteilung wie im Original
            int k2 = (int)cnt * 12;
            f = *(unsigned *)(c + 0x32);
            E *d = (E *)((char *)f + k2);
            if (s->id != -1 && s->on == 1) {
                d->id = s->id;
                short v = s->v;
                d->on = 1;
                d->v = v;
                cnt = cnt + 1;
                d->x = s->x;
            }
    }
    i = 0;
    if (cnt > (short)0) {
        do {
            int k = i;
            E *src = (E *)*(int *)(c + 0x32);
            E *item = src + k;
            int u = f_0a20a0(d_1be17c, *(int *)c, item->v);
            i = i + 1;
            int *dst = (int *)*(int *)(c + 0x36);
            dst[k] = u;
        } while (i < cnt);
    }
    i = cnt;
    if (cnt < *(short *)(c + 0x12)) {
        do {
            int u = f_0a20a0(d_1be17c, *(int *)c, 0);
            int k = i;
            int *dst = (int *)*(int *)(c + 0x36);
            dst[k] = u;
            i = i + 1;
        } while (i < *(short *)(c + 0x12));
    }
    short res = cnt + 0x80;
    *(short *)(c + 0x20) = res;
}
//@ f_0daa90
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schaltet in der Aktionsleiste c die Schaltfläche mit der Aktionskennung id aus (e->on = 0), baut
 *   die sichtbare Schaltflächenreihe bei einer Änderung über f_0da9a0 neu auf und fordert über d_1c2198 = 1 ein
 *   Neuzeichnen des Bildschirms an.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (c) sowie die Aktionskennung der auszublendenden
 *   Schaltfläche (id).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0daa90(char *c, PT id)
{
    short i = 0;
    int found = 0;
    for (i = 0; i < *(short *)(c + 0x12); i++) {
        E *base = (E *)*(int *)(c + 0x2a);
        E *e = base + i;
        if (e->id == SX(id) && e->on == 1) {
            found = e->on;
            e->on = 0;
            break;
        }
    }
    if (found == 1) {
        f_0da9a0(c);
        d_1c2198 = 1;
    }
}
//@ f_0daaf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schaltet in der Aktionsleiste c die Schaltfläche mit der Aktionskennung id ein (e->on = 1), baut
 *   die sichtbare Schaltflächenreihe bei einer Änderung über f_0da9a0 neu auf und setzt das Neuzeichnen-Flag
 *   d_1c2198 = 1.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (c) sowie die Aktionskennung der einzublendenden
 *   Schaltfläche (id).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0daaf0(char *c, PT id)
{
    short i = 0;
    int found = 0;
    for (i = 0; i < *(short *)(c + 0x12); i++) {
        E *base = (E *)*(int *)(c + 0x2a);
        E *e = base + i;
        if (e->id == SX(id) && e->on == 0) {
            e->on = 1;
            found = 1;
            break;
        }
    }
    if (found == 1) {
        f_0da9a0(c);
        d_1c2198 = 1;
    }
}
//@ f_0dab50
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft, ob die Schaltfläche mit der Aktionskennung id in der Aktionsleiste c vorhanden, aber derzeit
 *   deaktiviert (e->on == 0) ist.
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (c) sowie die zu prüfende Aktionskennung (id).
 * - Rückgabewert: Gibt 1 zurück, wenn der Eintrag vorhanden und ausgeschaltet ist, sonst 0.
 === Ende Beschreibung === */
int f_0dab50(char *c, PT id)
{
    int r;
    short i = 0;
    E *base;
    r = 0;
    for (i = 0; i < *(short *)(c + 0x12); i++) {
        base = (E *)*(int *)(c + 0x2a);
        E *e = base + i;
        if (e->id == SX(id) && !e->on) { r = 1; break; }
    }
    return r;
}
//@ f_0daba0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet sämtliche Schaltflächenplätze (*(short *)(p + 0x12)) der Aktionsleiste in den
 *   Zielbildpuffer p2: belegte Plätze werden samt Aktions-Icon über f_0db4a0 gerendert, leere Plätze erhalten
 *   ihren ungedrückten Hintergrund aus *(p + 0x3a).
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p) sowie die Adresse des Zielbildpuffers (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct Frame969 { int outer; int mode; int inner; };
static inline void draw_panel941(int col, char *p, short idx, Frame969 &frame)
{
    int offset;
    short *pos;
    struct MG941 {
        static void begin(Frame969 &f, int m) { int state = f_0d3860(); f.mode = m; if (state == 1) { f_0d2710(); f.inner = 1; } else f.inner = 0; }
        static void end(Frame969 &f) { if (f.inner == 1) f_0d26e0(); }
    } mg;
    extern signed char d_1a9449;
    signed char hold;
    signed char early;
    mg.begin(frame, col);
    offset = (idx & 0) ? 0 : (int)idx * 4; // haelt die Registerzuteilung wie im Original
    pos = (short *)((char *)*(short **)(p + 0x3e) + offset);
    ((RivaRasterImage*)(*(int *)(*(int *)(p + 0x3a) + (hold = d_1a9449, d_1a9449 = hold, (int)idx * 8))))->f_0fade0((void *)( frame.mode), pos[0], pos[1]);
    mg.end(frame);
    early = d_1a9449; d_1a9449 = early; // haelt die Registerzuteilung wie im Original
}
void f_0daba0(char *p, int p2)
{
    Frame969 frame;
    short i = 0;
    if (f_0d3860() == 1) { f_0d2710(); frame.outer = 1; }
    else frame.outer = 0;
    for (i = 0; i < *(short *)(p + 0x12); i++) {
        void **items = *(void ***)(p + 0x36);
        if (((short (*)(void *))f_0a2450)(items[i]) > 0) {
            ((void (*)(char *, short, int, int))f_0db4a0)(p, i, 0, p2);
        } else {
            draw_panel941(p2, p, i, frame);
        }
    }
    if (frame.outer == 1) f_0d26e0();
}
//@ f_0dac90
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Übersetzt einen Schaltflächen-Hot-Spot-Code id (0x81..0x89) über das zugehörige Icon-Objekt
 *   (f_0a2450) in die tatsächliche Aktionskennung der angeklickten Panel-Schaltfläche. (Hinweis: Liegt id
 *   außerhalb des Bereichs 0x81..0x89, wird die lokale Variable r im Originalcode nicht initialisiert.)
 * - Eingaben: Übergeben werden der Zeiger auf das Panel-Objekt (p) sowie der Hot-Spot-Code (id).
 * - Rückgabewert: Gibt die zugehörige Aktionskennung als 16-Bit-Wert zurück.
 === Ende Beschreibung === */
short f_0dac90(char *p, short id)
{
    short r;
    if (SX(id) >= 0x81 && SX(id) <= 0x89) {
        short ix = SX(id) - 0x81;
        r = ((short (*)(void *))f_0a2450)((*(void ***)(p + 0x36))[ix]);
    }
    return r;
}
//@ f_0dacc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Wertet Tastatur- und Mauseingaben für die Aktionsleiste p aus: öffnet bei Rechtsklick oder Bild-Auf
 *   (0x4900) das Text-Auswahlmenü der Panel-Aktionen (f_0db3d0), liefert bei Escape (0x11b) den Verlassen-Code
 *   *(short *)(p + 0x20) und führt bei Klick auf einen der Plätze 0x81..0x89 die Eindrück-Animation (f_0db6b0)
 *   aus, bevor die Aktionskennung zurückgegeben wird.
 * - Eingaben: Übergeben wird der Zeiger auf das Panel-Objekt (p).
 * - Rückgabewert: Gibt die ausgelöste Aktionskennung oder 0 zurück, falls keine Panel-Aktion gewählt wurde.
 === Ende Beschreibung === */
static inline short i_0db370(char *p)
{
    short r = 0;
    switch (d_1bd762) {
    case 0x4900:
        r = 0xa1;
        *(int *)(p + 0x22) = 1;
        break;
    case 0x11b:
        r = *(short *)(p + 0x20);
        *(int *)(p + 0x22) = 1;
        break;
    }
    return r;
}
static inline void i_0db6b0(char *p, short idx)
{
    f_0db4a0(p, idx, 1, *(int *)&d_1a34e0);
    f_149cf0(0x32);
    if (*(int *)(p + 0x22) == 1) f_149cf0(0xc8);
    f_0d5b50(1);
    f_0db4a0(p, idx, 0, *(int *)&d_1a34e0);
}
short f_0dacc0(char *p)
{
    union { short s; int d; } r;
    short t = i_0db370(p);
    r.s = (short)t;
    if (t == 0) *(volatile short *)&r.s = d_1bd766;
    if (f_0d37b0()) r.s = 0xa1;
    if (r.s == (short)0xa1) r.s = (short)f_0db3d0(p);
    {
        int rv = r.s;
        if (rv >= 0x81 && rv <= 0x89) {
            short i = r.d - 0x81;
            i_0db6b0(p, i);
            int *table = (int *)*(int *)(p + 0x36);
            int value = table[i];
            r.s = (short)f_0a2450(value);
        }
    }
    return (short)r.d;
}
