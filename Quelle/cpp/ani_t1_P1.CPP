/* === Beschreibung (Katalog) ===
 * Einheit ani_t1
 *
 * Diese Einheit implementiert den Abspiel- und Verwaltungszweig der Ortsanimationen (ani.cpp, Teil 1,
 * Adressbereich 0x01bf80-0x01d160, Klasse Ani mit 0xcf Bytes). Sie bildet das direkte Gegenstück zu seg004.c in
 * *Schicksalsklinge* (init_ani, timer_isr, clear_ani, disable_ani, init_ani_busy_loop, clear_ani_pal,
 * set_ani_pal), kapselt die dort noch globalen g_ani_*-Variablen jedoch in einem C++-Objekt (d_1bc760) und
 * erweitert das System um Mehrzustands-Animationen (bis zu 10 Zustände je Bereich), eine explizite
 * Zeichenrangfolge (w8b), Haltemarken in den Animationsphasen sowie einen Speichersparweg, der Einzelbilder bei
 * knappem RAM direkt während des Zeichnens aus dem Archiv nachlädt.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 18/26 gleich (suche.py 30.10.2026, Basis ani_t1_P1.CPP)
// F4 Stand (Basis p3 ANI_T1_P1.CPP)
// ani.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01BF80-0x01E0C0
#include <string.h>
#pragma pack(1)
extern int d_1a04d4;
extern int d_1a34e0;
extern int d_1baac0;
extern volatile int d_1bc75c;
extern int d_1bc764;
extern volatile short d_1bf4f0;
extern volatile short d_1bf4f2;

extern int d_1c2edc;
extern const char d_1a04b8[];
int f_0d3860();
int f_0d2710();
int f_0d26e0();
int f_069460();
int f_099ea0();
int __cdecl f_099ef0(void *buf, int z, int n);
void *f_014540(int size, const char *file, int line);
void *f_014710(void *p);
void *f_147c84(void *p, int n, void *tab);
void *f_145300(void *p, int c, unsigned n);




int f_147c02(int *o, int h);
int f_147b97(int *o, unsigned short rate, int (*cb)());
int f_01bf70();
int f_146dfa(int *o, int k);
struct St {
  char d[616];
  St();
  void f_147ef0(void *buf, void *src, int n);
};
struct Slot { unsigned char a, b; short c; };
struct Frame { Slot v[10]; };
struct Entry {
  char h0[4]; unsigned char b4; short s5; unsigned char b7, b8; short s9;
  unsigned char fl[10]; unsigned char b15; void *tx[25]; short cnt[10]; Frame *fr;
};
struct Ani {
  char h0[8]; short s08; char h0a[4]; unsigned char b0e; signed char n; Entry *ents; void *p14;
  unsigned char b18; char h19; void *p1a; char b1e; char h1f; signed char sc20[10]; char h2a[11];
  short s35, s37, s39, s3b, s3d, s3f; long l41; long l45; void *l49; short s4d;
  short w4f[10], w63[10], w77[10], w8b[10]; RivaRasterImage *p9f[10]; long lc7; long lcb;
  Ani *f_01c000();
  Ani *f_01c080(int kp2);
  void f_01c090(short mode, signed char b);
  void f_01c120(short mode);
  void f_01c300(short a, short b, RivaRasterImage *g);
  void f_01c530(Entry *e, short k);
  int f_01c730(Entry *e, short k, int p4, short p5);
  void f_01c840();
  void f_01cae0(int p2, short mode);
  void f_01cb00(int p2, short mode, signed char b);
  void f_01cc30();
  void f_01cc90();
  void f_01ce30();
  void f_01ceb0(void *buf);
  void f_01ced0(short x, short y);
  void f_01cee0(short v);
  void f_01cef0();
  void f_01cf00();
  void f_01cf10();
  void f_01cf30(short mode);
  void f_01cf60(short mode, signed char c);
  int f_01cf90(int sz);
  void f_01d160(int p2);
  void x_pal();
  void x_buf(void *buf);
  void x_reset();
  void x_free();
};
inline void Ani::x_pal() {
  short c = s37;
  char *a = new (mark(d_1a04b8, 0x2c2)) char[c * 3];
  a = (char *)f_147c84(a, c, &d_1baac0);
  f_145300(a, 0, 4);
  f_099ea0();
  f_099ef0(a, 0, s37);
  delete a;
}
inline void Ani::x_buf(void *buf) {
  f_099ea0();
  f_099ef0(buf, 0, s37);
}
inline void Ani::x_reset() {
  s39 = 0x10; s3b = 2; s3f = 0; s4d = 0; s3d = 0; lc7 = 1; l41 = -1;
  for (short k = 0; k < 10; k++) p9f[k] = 0;
}

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_01bf80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ist derzeit ein Animations-Timer aktiv (d_1a04d4 != -1), meldet die Funktion diesen über
 *   f_147c02 bei der globalen Timer-Verwaltung d_1c2edc ab und setzt die gespeicherte Timer-Kennung d_1a04d4 auf
 *   -1 zurück (Gegenstück zu seg004.c:reset_timer in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: d_1a04d4 speichert das Handle des aktiven Animations-Timers (-1 = keiner), und d_1c2edc
 *   ist das globale HMI-Timer-Verwaltungsobjekt.
 === Ende Beschreibung === */
void f_01bf80()
{
    if (d_1a04d4 != -1) {
        f_147c02(&d_1c2edc, d_1a04d4);
        d_1a04d4 = -1;
    }
}

//@ f_01bfb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion meldet einen eventuell bereits laufenden Animations-Timer über f_01bf80 ab, hängt
 *   anschließend die Tick-Funktion f_01bf70 (amapplst_t2) mit dem Taktteiler rate bei d_1c2edc ein und merkt die
 *   neue Timer-Kennung in d_1a04d4 (Gegenstück zu seg004.c:save_and_set_timer in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Funktion erhält die Taktrate rate (int, als unsigned short übergeben) und hat
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden d_1a04d4, d_1c2edc und die Rückruffunktion f_01bf70.
 === Ende Beschreibung === */
void f_01bfb0(int rate)
{
    if (d_1a04d4 != -1) {
        f_01bf80();
    }
    d_1a04d4 = f_147b97(&d_1c2edc, (unsigned short)rate, f_01bf70);
}

//@ f_01c000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor versetzt ein neu angelegtes Ani-Objekt (0xcf Bytes) in seinen Grundzustand: er
 *   setzt den Zeichenmodus s35 = 2, die Palettenfarbzahl s37 = 160 (0xa0), die Bereichsanzahl n = 0, die
 *   Bildschirmposition auf (16, 2), alle Laufschalter auf 0, den Puffermodus auf lc7 = 1 (Vollpuffer), die
 *   geladene ANI-Nummer auf l41 = -1 und löscht die 10 Bereichs-Bildobjektzeiger p9f[0..9].
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this (Ani *) und gibt this zurück.
 * - Wichtige Variablen: Initialisiert werden insbesondere s35 (+0x35), s37 (+0x37), s39/s3b (+0x39/+0x3b,
 *   Position X/Y), s3d (+0x3d, Laufschalter), l41 (+0x41, geladene ANI-ID) und p9f[0..9] (+0x9f).
 === Ende Beschreibung === */
Ani *Ani::f_01c000()
{
    s35 = 2; s37 = 0xa0; n = 0; l49 = 0; s39 = 0x10; s3b = 2; s3f = 0; s4d = 0; s3d = 0;
    lc7 = 1; l41 = -1;
    Ani *q = this; for (short k = 0; k < 10; k++) q->p9f[k] = 0;
    return this;
}

//@ f_01c080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor gibt über f_01cf10 sämtliche zur geladenen Animation gehörenden Speicherblöcke,
 *   Tabellen und Bildobjekte frei.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) sowie das ungenutzte Watcom-Destruktorflag
 *   kp2 (int) und gibt this zurück.
 * - Wichtige Variablen: Bereinigt wird das gesamte Ani-Objekt über f_01cf10.
 === Ende Beschreibung === */
Ani *Ani::f_01c080(int kp2)
{
    f_01cf10();
    return this;
}

//@ f_01c090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Für jeden Animationsbereich i (0 .. n - 1) kopiert die Funktion die Bereichsflags fl[b] und
 *   die Wechselkette fr[j].v[b] des gewünschten Zustands b in den aktiven Arbeitsplatz 0, prüft ob mindestens
 *   ein Bereich das Flag-Bit 1 (& 2) für den Zeichenrang-Betrieb (b1e) setzt, und startet die Animation
 *   anschließend über f_01c120(mode).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), den Startmodus mode (short) sowie die
 *   Zustandsnummer b (signed char, 0..9) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Bereichstabelle ents (+0x10), die Wechselzahlen sc20[0..9] (+0x20)
 *   und das Rangbetrieb-Flag b1e (+0x1e).
 === Ende Beschreibung === */
void Ani::f_01c090(short mode, signed char b)
{
    short i, j;
    b1e = 0;
    for (i = 0; i < n; ++i) {
        ents[i].fl[0] = ents[i].fl[b];
        for (j = 0; j < sc20[i]; ++j) {
            ((long *)ents[i].fr[j].v)[0] = ((long *)ents[i].fr[j].v)[b];
        }
        if (ents[i].fl[0] & 2) b1e = 1;
    }
    f_01c120(mode);
}

//@ f_01c120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sofern eine Animation geladen ist (l41 != -1), setzt die Funktion je nach mode (Gegenstück zu
 *   seg004.c:init_ani in *Schicksalsklinge*) die Bereichs-Laufzustände (w4f, w63, w77, w8b) zurück, blendet bei
 *   mode < 3 zuerst eine schwarze Palette ein, zeichnet das Hauptbild p14 an die Position (s39, s3b) in den
 *   Bildschirmpuffer d_1a34e0, aktiviert bei mode < 3 die ANI-Palette p1a, baut bei aktivem Rangbetrieb (b1e !=
 *   0) die Zeichenreihenfolge w8b aus den oberen 4 Bits von ents[k].fl[0] auf, schaltet die Animation ein (s3d =
 *   1, außer bei den reinen Zeichenmodi 1 und 4) und setzt den Tickzähler d_1bc75c auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und den Modus mode (short: mode & 0x7f =
 *   0/3 zeichnen und starten, 1/4 nur zeichnen, 2/5 nur starten; Werte < 3 schalten die Palette, Werte >= 3
 *   lassen die Palette unverändert) und hat keinen Rückgabewert.
 * - Wichtige Variablen: w4f[10] (+0x4f) hält die Restdauern, w63[10] (+0x63) die aktuellen Wechselindizes,
 *   w77[10] (+0x77) die Laufrichtungen (+1/-1), w8b[10] (+0x8b) die Zeichenrangfolge und s3d (+0x3d) das
 *   Aktiv-Flag.
 === Ende Beschreibung === */
void Ani::f_01c120(short mode)
{
    void *mark_local(const char *, int);
#pragma aux mark_local "f_014b10" parm [eax] [edx] value [eax] modify exact [eax edx edi]
    void *f_147c84_local(void*, int, void*);
#pragma aux f_147c84_local "f_147c84" parm [eax] [edx] [ebx] value [eax] modify exact [eax edx ebx ecx]
    RivaRasterImage g(s08, b0e, p14);
    volatile int local_1c;
    if (l41 != 0xffffffff) {
        if ((mode & 0x7f) != 2 && (mode & 0x7f) != 5) {
            for (short k = 0; k < 10; k++) {
                w4f[k] = 0; w77[k] = 1; w63[k] = -1; w8b[k] = -1;
            }
            if (mode < 3) {
                short c = s37; void *m = mark_local(d_1a04b8, 0x2c2); unsigned c2 = (short)c;
                char *a = new (m) char[c * 3];
                Ani *self = this;
                a = (char *)f_147c84_local(a, c2, &d_1baac0);
                a = a ? a : (char *)0;
                f_145300(a, 0, 4);
                f_099ea0();
                f_099ef0(a, 0, self->s37);
                delete a;
            }
            if (f_0d3860() == 1) {
                f_0d2710();
                local_1c = 1;
            } else {
                local_1c = 0;
            }
            s3f = 1;
            g.f_0fae30((void *)(d_1a34e0), s39, s3b, s35);
            if (mode < 3) x_buf(p1a);
            s3f = 0;
            if (local_1c == 1) f_0d26e0();
        }
        if (b1e) {
            short c = n;
            short k = 0;
            while (k < c) {
                unsigned char ix = ents[k].fl[0];
                ix >>= 4;
                w8b[ix] = k;
                k++;
            }
        }
        if ((mode & 0x7f) != 1 && (mode & 0x7f) != 4) s3d = 1;
    }
    d_1bc75c = 0;
}

//@ f_01c2f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion besitzt einen leeren Rumpf und führt keinerlei Aktion aus.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_01c2f0(void)
{
}

//@ f_01c300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird die Animation im Speichersparweg betrieben (lc7 == 0), öffnet diese Funktion die
 *   ANI-Datei l41 im Archiv d_1c2098, liest den ANI-Kopf ab Dateiversatz lcb und lädt das Einzelbild b des
 *   Bereichs a in das übergebene Grafikobjekt g (bei PP20-gepackten Daten b18 != 0 wird der gesamte Bilderblock
 *   des Bereichs entpackt und das Einzelbild b herauskopiert).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), den Bereichsindex a (short), den
 *   0-basierten Bildindex b (short) sowie das Ziel-Bildobjekt g (Img *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden l41 (+0x41, Archiv-ID), lcb (+0xcb, Dateiversatz), b18 (+0x18,
 *   Kompressionsflag), ents[a] und das Archivobjekt d_1c2098.
 === Ende Beschreibung === */
void Ani::f_01c300(short a, short b, RivaRasterImage *g)
{
    St st;
    int n1;
    int n2;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( l41, 0x200);
    ((RivaFileManager*)(&d_1c2098))->f_144ab0( lcb, 0);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &n1), 4)));
    ((RivaFileManager*)(&d_1c2098))->f_144ab0( lcb, 0);
    char *hdr = (char *)f_014540(n1, d_1a04b8, 0xf2);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( hdr), n1)));
    Entry *e = ents + a;
    {
        int off = *(int *)(hdr + *(int *)(hdr + 0xc + a * 4) + 0xc);
        if (b18) {
            ((RivaFileManager*)(&d_1c2098))->f_144ab0( lcb + off, 0);
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &n2), 4)));
            char *u = (char *)f_014540(n2, d_1a04b8, 0xfe);
            ((RivaFileManager*)(&d_1c2098))->f_144ab0( -4, 1);
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( u), n2)));
            int sz = e->s9 * e->b8;
            char *buf = (char *)f_014540(e->b15 * sz, d_1a04b8, 0x105);
            st.f_147ef0(buf, u, n2);
            memcpy(g->f_0fb0b0(), buf + b * sz, sz);
            delete u; delete buf;
        } else {
            int sz2 = e->s9 * e->b8;
            off += b * sz2;
            ((RivaFileManager*)(&d_1c2098))->f_144ab0( lcb + off, 0);
            ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( g->f_0fb0b0()), sz2)));
        }
    }
    delete hdr;
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
}

//@ f_01c530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion prüft zunächst, ob sich der Mauszeiger (d_1bf4f0, d_1bf4f2) innerhalb des um 16
 *   Pixel erweiterten Rechtecks des Bereichs e befindet, und blendet ihn in diesem Fall vorübergehend aus;
 *   danach holt sie das zum aktuellen Wechsel w63[k] gehörende Einzelbild (v[0].a - 1) entweder über f_01c300
 *   aus der Datei (Sparweg lc7 == 0) oder aus der Bildzeigertabelle e->tx[] (lc7 != 0) und zeichnet es an (s39 +
 *   e->s5, s3b + e->b7) in den Bildschirmpuffer d_1a34e0 (mit Zeichenmodus 3, falls e->fl[0] & 2, sonst s35).
 *   Gegenstück zum Zeichenteil von seg004.c:timer_isr in *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), den Bereichszeiger e (Entry *) und den
 *   Bereichsindex k (short) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden s39/s3b (Animationsursprung), lc7 (+0xc7, Puffermodus), p9f[k] (+0x9f,
 *   Bereichs-Bildobjekt) und die Mauskoordinaten d_1bf4f0/d_1bf4f2.
 === Ende Beschreibung === */
void Ani::f_01c530(Entry *e, short k)
{
    signed char fl = 0;
    short x0 = s39 + e->s5 - 0x10;
    short x1 = e->s9 + x0 + 0x20;
    short y0 = e->b7 + s3b - 0x10;
    short y1 = e->b8 + y0 + 0x20;
    if (d_1bf4f0 >= x0 && d_1bf4f0 <= x1 && d_1bf4f2 >= y0 && d_1bf4f2 <= y1) {
        if (f_0d3860() == 1) { f_0d2710(); fl = 1; }
    }
    if (!lc7) {
        RivaRasterImage *g = new (mark(d_1a04b8, 0x13a)) RivaRasterImage(e->s9, e->b8);
        f_01c300(k, e->fr[w63[k]].v[0].a - 1, g);
        int m = (e->fl[0] & 2) ? 3 : s35;
        g->f_0fae30((void *)(d_1a34e0), (short)(s39 + e->s5), (short)(e->b7 + s3b), (short)m);
        delete g;
    } else {
        p9f[k]->f_0fb060((void *)(*(void **)((char *)e + 0x12 + e->fr[w63[k]].v[0].a * 4)));
        int m = (e->fl[0] & 2) ? 3 : s35;
        p9f[k]->f_0fae30((void *)(d_1a34e0), (short)(s39 + e->s5), (short)(e->b7 + s3b), (short)m);
    }
    if (fl == 1) f_0d26e0();
}

//@ f_01c730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion prüft zunächst, ob eine vom Aufrufer gewünschte Haltemarke erreicht wurde (s4d >
 *   0 && s4d == Slot.b, hält dann die Animation mit s3d = 0, s4d = 0 an), schaltet den Wechselindex w63[k] um
 *   die Richtung w77[k] weiter, kehrt am Ende der Wechselliste bei pendelnden Bereichen (e->fl[0] & 1, cyclic)
 *   die Richtung auf -1 um bzw. springt sonst auf 0 zurück, beendet bei s4d == -1 das Einmal-Abspielen und lädt
 *   die neue Bilddauer Slot.c + p5 in w4f[k]. Gegenstück zur Indexfortschaltung in seg004.c:timer_isr aus
 *   *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), den Bereich e (Entry *), den Bereichsindex
 *   k (short), das Flag p4 (int, im Rangbetrieb 1, im Normalbetrieb 0) sowie den Zeitüberhang p5 (short); sie
 *   gibt 0 zurück, wenn ein Einmal-Durchlauf (s4d == -1) beendet wurde, sonst 1.
 * - Wichtige Variablen: Geändert werden w63[k] (Wechselindex), w77[k] (Richtung), w4f[k] (Restdauer), s4d
 *   (+0x4d, Haltewunsch) und s3d (+0x3d, Laufschalter).
 === Ende Beschreibung === */
int Ani::f_01c730(Entry *e, short k, int p4, short p5)
{
    if (s4d > 0 && s4d == e->fr[w63[k]].v[0].b) { s3d = 0; s4d = 0; }
    if (w4f[k] <= 0 && p4 == 0) w63[k] += w77[k];
    if (w63[k] == e->cnt[0]) {
        if (e->fl[0] & 1) { w77[k] = -1; w63[k] -= 1; }
        else w63[k] = 0;
        if (s4d == -1) { s3d = 0; s4d = 0; return 0; }
    }
    if (w63[k] == (short)0 && (e->fl[0] & 1)) w77[k] = 1;
    w4f[k] = e->fr[w63[k]].v[0].c;
    w4f[k] += p5;
    return 1;
}

//@ f_01c840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Läuft die Ortsanimation (s3d == 1), liest die Funktion die seit dem letzten Aufruf
 *   aufgelaufenen Ticks aus d_1bc75c und setzt d_1bc75c = 0, zieht die verstrichene Zeit von den Restdauern
 *   w4f[i] aller aktiven Bereiche ab und schaltet abgelaufene Bereiche (oder alle Bereiche bei gesetztem
 *   Sofortschalter d_1bc764) über f_01c730 weiter. Im Normalbetrieb (b1e == 0) wird jeder weitergeschaltete
 *   Bereich sofort einzeln über f_01c530 gezeichnet; im Rangbetrieb (b1e != 0) wird bei mindestens einem Wechsel
 *   zuerst das Hauptbild p14 und danach alle aktiven Bereiche in der Rangfolge w8b[0..cnt-1] neu gezeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden der Tickzähler d_1bc75c, der Sofortschalter d_1bc764, das Rangflag b1e
 *   (+0x1e), die Restdauern w4f[10] und die Rangtabelle w8b[10]. Hinweis (Originalfehler): In beiden Zweigen
 *   (b1e != 0 und b1e == 0) lautet die Zeitabzugsrechnung if (w4f[i] <= m) m = w4f[i]; w4f[i] -= m; if (w4f[i] <
 *   0) d = w4f[i];. Durch das vorherige Begrenzen von m auf w4f[i] wird erstens w4f[i] bei der Subtraktion
 *   niemals negativ (der Zeitüberhang d für f_01c730 bleibt tot auf 0), und zweitens wird die schleifenweite
 *   Variable m für alle nachfolgenden Bereiche i + 1 .. cnt - 1 desselben Taktschritts verkleinert bzw. auf 0
 *   gesetzt!
 === Ende Beschreibung === */
void Ani::f_01c840()
{
    unsigned m = d_1bc75c;
#define FLAG (*(volatile short *)&d_1bc764)
    if (s3d == 1) {
        d_1bc75c = 0;
        short cnt = n;
        if (cnt == (short)0 && s4d != 0) { s3d = 0; s4d = 0; }
        short i, d;
        if (b1e) {
            int any = 0;
            for (i = 0; i < cnt; i++) {
                f_146dfa(&d_1c2edc, 1);
                Entry *e = &ents[i];
                if (!e->cnt[0] || (e->fl[0] & 4)) continue;
                d = 0;
                if (FLAG == 0) {
                    if (w4f[i] <= m) m = w4f[i];
                    w4f[i] -= m;
                    if (w4f[i] < 0) d = w4f[i];
                }
                if (FLAG || w4f[i] <= 0) {
                    any = 1;
                    if (!f_01c730(e, i, 1, d)) break;
                }
            }
            if (any) {
                RivaRasterImage g(s08, b0e, p14);
                g.f_0fae30((void *)(d_1a34e0), s39, s3b, s35);
                for (i = 0; i < cnt; i++) {
                    f_146dfa(&d_1c2edc, 1);
                    short q = w8b[i];
                    Entry *e = &ents[q];
                    if (e->cnt[0] && !(e->fl[0] & 4)) f_01c530(e, q);
                }
            }
        } else {
            for (i = 0; i < cnt; i++) {
                f_146dfa(&d_1c2edc, 1);
                Entry *e = &ents[i];
                if (!e->cnt[0] || (e->fl[0] & 4)) continue;
                d = 0;
                if (FLAG == 0) {
                    if (w4f[i] <= m) m = w4f[i];
                    w4f[i] -= m;
                    if (w4f[i] < 0) d = w4f[i];
                    d = (d & 0) ? (short)0 : d; // Haelt d im Register eax (cwde vor push eax) wie im Original
                }
                if (FLAG || w4f[i] <= 0) {
                    if (!f_01c730(e, i, 0, d)) break;
                    f_01c530(e, i);
                }
            }
        }
    }
    FLAG = 0;
#undef FLAG
}

//@ f_01cae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion lädt die Ortsanimation mit der Archiv-ID p2 über f_01d160 (ani_t2) und startet
 *   sie anschließend über f_01c120(mode).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), die ANI-Archivnummer p2 (int) und den
 *   Startmodus mode (short) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Delegiert an f_01d160 und f_01c120.
 === Ende Beschreibung === */
void Ani::f_01cae0(int p2, short mode)
{
    f_01d160(p2);
    f_01c120(mode);
}

//@ f_01cb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion lädt die Ortsanimation p2 über f_01d160 und startet sie anschließend im gewählten
 *   Zustand b über f_01c090(mode, b).
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), die ANI-Archivnummer p2 (int), den
 *   Startmodus mode (short) und den Zustandsindex b (signed char, 0..9) und liefert keinen Rückgabewert.
 * - Wichtige Variablen: Delegiert an f_01d160 und f_01c090.
 === Ende Beschreibung === */
void Ani::f_01cb00(int p2, short mode, signed char b)
{
    f_01d160(p2);
    f_01c090(mode, b);
}

//@ f_01cb1b
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion hält die Animation an (s3d = 0), gibt für alle n Bereiche die Bildobjekte p9f[i]
 *   und die Wechseltabellen ents[i].fr frei, gibt die Bereichstabelle ents, den Datenpuffer l49 sowie im
 *   Speichersparweg (lc7 == 0) auch den separat reservierten Palettenpuffer p1a frei und setzt alle Grundwerte
 *   des Ani-Objekts (l41 = -1) zurück. (Technischer Hinweis: Im Quelltext steht der Funktionsrumpf von
 *   Ani::f_01cf10 unter der Marke //@ f_01cb1b, während die Marke //@ f_01cf10 weiter unten als Einsprungmarke
 *   dient.)
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Freigegeben werden p9f[0..n-1], ents[0..n-1].fr, ents, l49 und p1a; zurückgesetzt werden
 *   s39..l41.
 === Ende Beschreibung === */
void Ani::f_01cf10()
{
    s35 = 2;
    s3d = 0;
    for (short i = 0; i < n; i++) {
        if (p9f[i] != 0) {
            delete p9f[i];
            p9f[i] = 0;
        }
        if (ents != 0 && ents[i].fr != 0)
            ents[i].fr = (Frame *)f_014710(ents[i].fr);
    }
    if (ents != 0)
        ents = (Entry *)f_014710(ents);
    if (l49 != 0) {
        l49 = f_014710(l49);
        if (lc7 != 0)
            p1a = 0;
        else
            p1a = f_014710(p1a);
    } else if (p1a != 0) {
        p1a = f_014710(p1a);
    }
    s39 = 0x10;
    s3b = 2;
    s3f = 0;
    s4d = 0;
    s3d = 0;
    lc7 = 1;
    Ani *q = this;
    l41 = -1;
    for (short j = 0; j < 10; j++)
        q->p9f[j] = 0;
}

//@ f_01cc30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt Bildschirmlage (16, 2), Laufschalter (s3d = 0), Kopierflag (s3f = 0),
 *   Haltewunsch (s4d = 0), Puffermodus (lc7 = 1), ANI-Nummer (l41 = -1) sowie die 10 Zeiger p9f[0..9] auf ihre
 *   Grundwerte zurück, ohne bestehenden Speicher freizugeben.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Zurückgesetzt werden s39, s3b, s3f, s4d, s3d, lc7, l41 und p9f[0..9].
 === Ende Beschreibung === */
void Ani::f_01cc30()
{
    s39 = 0x10; s3b = 2; s3f = 0; s4d = 0; s3d = 0; lc7 = 1; l41 = -1;
    for (short k = 0; k < 10; k++) p9f[k] = 0;
}

//@ f_01cc90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt die Hauptbildmaße (s08, b0e) und die Zeiger p14/p1a auf 0, löscht in allen
 *   n Bereichen die Lage- und Größenfelder, sämtliche Zustandsflags fl[0..9], alle Wechsel-Einträge
 *   fr[k].v[0..9] sowie die 25 Bildzeiger tx[0..24], gibt eventuell vorhandene Bereichs-Bildobjekte p9f[i] frei
 *   und setzt den Tickzähler d_1bc75c = 0. Gegenstück zu seg004.c:clear_ani in *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Bereinigt werden ents[0..n-1], p9f[0..n-1] und d_1bc75c.
 === Ende Beschreibung === */
void Ani::f_01cc90()
{
    s08 = 0;
    b0e = 0;
    p14 = 0;
    p1a = 0;
    for (short i = 0; i < n; i++) {
        ents[i].s5 = 0;
        ents[i].b7 = 0;
        ents[i].s9 = 0;
        ents[i].b8 = 0;
        ents[i].b15 = 0;
        ents[i].b4 = 0;
        for (short j = 0; j < 10; j++) {
            ents[i].fl[j] &= 0xfe;
            ents[i].fl[j] &= 0xfd;
            ents[i].fl[j] &= 0xfb;
            ents[i].fl[j] &= 0xf7;
            ents[i].fl[j] &= 0x0f;
            for (short k = 0; k < ents[i].cnt[j]; k++) {
                ents[i].fr[k].v[j].a = 0;
                ents[i].fr[k].v[j].c = 0;
                ents[i].fr[k].v[j].b = 0;
            }
        }
        // Codeloser Byte-Roundtrip haelt die Register- und Stapelsortierung der Schleifenvariablen wie im Original
        unsigned char *gp1055 = (unsigned char *)&d_1bc764;
        unsigned char rt1055 = *gp1055;
        *gp1055 = rt1055;
        for (short m = 0; m < 25; m++) ents[i].tx[m] = 0;
        if (p9f[i] != 0) {
            delete p9f[i];
            p9f[i] = 0;
        }
    }
    d_1bc75c = 0;
}

//@ f_01ce30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion legt einen temporären Palettenpuffer für s37 Farben an, füllt ihn aus d_1baac0
 *   mit Schwarz, wartet auf den vertikalen Bildrücklauf (f_099ea0), überträgt die Schwarzpalette über f_099ef0
 *   in die Grafikkarte und gibt den Puffer wieder frei. Gegenstück zu seg004.c:clear_ani_pal in
 *   *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Farbzahl s37 (+0x37) und die Schwarzpaletten-Vorlage d_1baac0.
 === Ende Beschreibung === */
void Ani::f_01ce30()
{
    void *mark_local(const char *, int);
    #pragma aux mark_local "f_014b10" parm [eax] [edx] value [eax] modify exact [eax edx edi]
    char *a;
    short c = s37;
    void *m = mark_local(d_1a04b8, 0x2c2);
    unsigned c2 = (short)c;
    a = new (m) char[c * 3];
    a = (char *)f_147c84(a, c2, &d_1baac0);
    a = a ? a : (char *)0; // Entspricht der Nullpruefung bei __vec_new_ (new RGB[c]) im Original
    f_145300(a, 0, 4);
    f_099ea0();
    f_099ef0(a, 0, s37);
    delete a;
}

//@ f_01ceb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion wartet auf den vertikalen Bildrücklauf (f_099ea0) und setzt anschließend s37
 *   Farben ab Farbindex 0 aus dem übergebenen Puffer buf über f_099ef0. Gegenstück zu seg004.c:set_ani_pal in
 *   *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) sowie den Palettenpuffer buf (void *, 3
 *   Bytes je Farbe) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt wird die Palettenfarbzahl s37 (+0x37).
 === Ende Beschreibung === */
void Ani::f_01ceb0(void *buf)
{
    x_buf(buf);
}

//@ f_01ced0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion speichert die übergebenen Bildschirmkoordinaten (x, y) in den Feldern s39 und s3b
 *   des Ani-Objekts.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) sowie die Koordinaten x und y (short) und
 *   hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt werden s39 (+0x39) und s3b (+0x3b).
 === Ende Beschreibung === */
void Ani::f_01ced0(short x, short y)
{
    s39 = x; s3b = y;
}

//@ f_01cee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt das Feld s37 (Anzahl der von der Animation geschalteten Palettenfarben,
 *   Standardwert 160) auf den übergebenen Wert v.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und die Farbzahl v (short) und liefert
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt wird s37 (+0x37).
 === Ende Beschreibung === */
void Ani::f_01cee0(short v)
{
    s37 = v;
}

//@ f_01cef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schaltet das Abspielen der Animation ab (s3d = 0) und setzt den Zeichenmodus s35
 *   auf den Standardwert 2 zurück. Gegenstück zu seg004.c:disable_ani in *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert werden s3d (+0x3d) und s35 (+0x35).
 === Ende Beschreibung === */
void Ani::f_01cef0()
{
    s35 = 2; s3d = 0;
}

//@ f_01cf00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Zeichenmodus s35 auf 2 zurück und gibt die geladene Animation
 *   anschließend über f_01cf10 vollständig frei.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geändert wird s35, aufgerufen wird f_01cf10.
 === Ende Beschreibung === */
void Ani::f_01cf00()
{
    s35 = 2;
    f_01cf10();
}

//@ f_01cf10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zweite Markerzeile zu Ani::f_01cf10; der Funktionsrumpf (Anhalten der Animation und Freigabe
 *   aller Bereichs-Bildobjekte p9f[i], Wechseltabellen ents[i].fr, ents, l49 und p1a) sowie die vollständige
 *   Beschreibung stehen in dieser Einheit bereits unter f_01cb1b.
 * - Eingaben und Rückgabe: Die Methode erhält das Ani-Objekt (this) und hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Siehe f_01cb1b.
 === Ende Beschreibung === */

//@ f_01cf30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Haltewunsch s4d = -1, startet die Animation über f_01c120(mode) und
 *   ruft in einer Warteschleife f_069460() auf, bis der erste Bereich einmal komplett durchgelaufen ist und
 *   f_01c730 das Feld s4d wieder auf 0 zurücksetzt. Gegenstück zu seg004.c:init_ani_busy_loop in
 *   *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) und den Startmodus mode (short) und hat
 *   keinen Rückgabewert.
 * - Wichtige Variablen: Gesteuert und überwacht wird das Haltewunsch-Feld s4d (+0x4d).
 === Ende Beschreibung === */
void Ani::f_01cf30(short mode)
{
    s4d = -1;
    f_01c120(mode);
    while (s4d != (short)0) f_069460();
}

//@ f_01cf60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion trägt die gewünschte Haltemarke c (> 0) in s4d ein, startet die Animation über
 *   f_01c120(mode) und wartet in einer Schleife (f_069460()), bis f_01c730 auf einen Bildwechsel trifft, dessen
 *   Markenbyte Slot.b == c ist, und s4d auf 0 löscht.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this), den Startmodus mode (short) sowie die
 *   Haltemarke c (signed char) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt wird das Haltewunsch-Feld s4d (+0x4d).
 === Ende Beschreibung === */
void Ani::f_01cf60(short mode, signed char c)
{
    s4d = c;
    f_01c120(mode);
    while (s4d) f_069460();
}

//@ f_01cf90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liest ab der aktuellen Dateiposition im geöffneten Archiveintrag den sz Bytes
 *   großen ANI-Kopf und berechnet den gesamten Speicherbedarf der entpackten Animation (Kopf + 6 Bytes
 *   Palettenvorspann + Hauptbild Breite x Höhe + für jeden Bereich Breite x Höhe x Bildanzahl + 3 x Farbzahl für
 *   die Palette, wobei 0xff für 256 Farben steht). Handelt es sich um das alte Dateiformat ohne Riva-Kennung
 *   (l45 != 0), legt die Funktion dabei zugleich die Bereichstabelle ents an und trägt die Wechselzahlen sc20[i]
 *   ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Ani-Objekt (this) sowie die Kopfgröße sz (int) und gibt die
 *   berechnete Gesamtgröße in Bytes (int) zurück.
 * - Wichtige Variablen: Genutzt werden das Formatflag l45 (+0x45), die Bereichszahl n (+0x0f), die
 *   Bereichstabelle ents (+0x10), das Array sc20[10] (+0x20) und das Archivobjekt d_1c2098.
 === Ende Beschreibung === */
int Ani::f_01cf90(int sz)
{
    union U_pos { int full; unsigned char byte[4]; unsigned short word[2]; }; U_pos pos; pos.full = ((RivaFileManager*)(&d_1c2098))->f_144ab0( 0, 1);
    int view_pos = pos.byte[0]; // Initialisierte Unteransicht haelt die Stapelsortierung von pos wie im Original
    char *hdr = (char *)f_014540(sz, d_1a04b8, 0x35c);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( hdr), sz)));
    union U_off { int full; unsigned char byte[4]; unsigned short word[2]; }; U_off off; off.full = *(int *)hdr;
    int view_off = off.byte[0]; // Initialisierte Unteransicht haelt die Stapelsortierung von off wie im Original
    unsigned short step = *(unsigned short *)(hdr + 8);
    unsigned char last = (unsigned char)hdr[10];
    off.full += 6;
    unsigned char count = (unsigned char)hdr[11];
    if (l45) {
        short alloc_count = count;
        if (!alloc_count) alloc_count = 1;
        n = count;
        ents = (Entry *)f_014540(alloc_count * 0x92, d_1a04b8, 0x371);
    }
    off.full += last * (unsigned short)(step);
    for (short i = 0; i < count; i++) {
        union U_entry_offset { int full; unsigned char byte[4]; unsigned short word[2]; }; U_entry_offset entry_offset; entry_offset.full = *(int *)(hdr + 0xc + (int)i * 4);
    int view_entry_offset = entry_offset.word[0]; // Initialisierte Unteransicht haelt die Stapelsortierung von entry_offset wie im Original
        entry_offset.full += (int)hdr;
        char *entry = (char *)entry_offset.full;
        union { unsigned short w; struct { unsigned char lo, hi; } byte; } pair;
        pair.byte.hi = (unsigned char)entry[7];
        unsigned short bytes = *(unsigned short *)(entry + 8);
        pair.byte.lo = (unsigned char)entry[11];
        if (l45) {
            ents[i].cnt[0] = *(short *)(entry + (unsigned)pair.byte.lo * 4 + 0xc);
            sc20[i] = (signed char)ents[i].cnt[0];
        }
        off.full += pair.byte.hi * bytes * pair.byte.lo;
    }
    ((RivaFileManager*)(&d_1c2098))->f_144ab0( *(int *)(hdr + 4) + 6 + pos.full - 2, 0);
    char tmp; ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &tmp), 1)));
    short extra;
    if ((unsigned char)tmp == 0xff) extra = 0x100;
    else extra = (unsigned char)tmp;
    off.full += (short)(extra) * 3;
    delete hdr;
    return off.full;
}
