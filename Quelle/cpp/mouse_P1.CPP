/* === Beschreibung (Katalog) ===
 * Einheit mouse
 *
 * Diese Einheit gehört zu mouse.cpp und implementiert die gesamte Mausverwaltung des Spiels über den
 * DOS-Interrupt 0x33, das Laden und Wechseln von Mauszeiger-Grafiken (0x40003), das Sichern und Wiederherstellen
 * des Bildschirmhintergrunds unter dem Cursor sowie Rechteck-Kollisionstests und Tastenabfragen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 22/30 gleich (suche.py 26.10.2026, Basis mouse_P1.CPP)
// mouse.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D2B10-0x0D3860
#include <string.h>
#include <i86.h>
#pragma inline_depth(0)
union Regs {
    struct { unsigned eax, ebx, ecx, edx, esi, edi, cflag; } e;
    struct { unsigned short ax, ax_, bx, bx_, cx, cx_, dx, dx_, si, si_, di, di_, cflag, cflag_; } x;
};
void *f_014710(void *p);
int f_05fc00(int p1, void *p2, void *p3, void *p4);
int f_099f70(int p1, int p2, int p3, int p4);
int f_099fa0(char *p1);
int f_099ff0(char *p1);
short f_0bf570();
int f_0d3a10(char *p1);




short f_13f8c0();
short f_13f8d0();
int f_147c02(char *p1, int p2);
int f_15ec70(char *p1);
int f_15eca0(char *p1, int p2);
int f_15f130(char *p1, char *p2, char *p3, int p4, int p5, int *p6, int *p7, int p8);
void *f_014540(int p1, const char *p2, int p3);
short f_01a810();
short f_01a7e0();
void f_0d2f90(short p1, short p2);

void f_149caa(void *p1);
int f_145702(int p1, void *p2, void *p3, void *p4);
void f_0d2b70();
void f_0d2d20();
void f_0d32f0();
void f_0d3150();
void f_0d31c0();
void f_0d35b0(short p1, short p2, short *p3);
void f_0d3680(short p1, short p2, char *p3);
void f_0d3570(short *p1);
int f_0d3750();
int f_0d34b0(int p1, int p2, int p3, int p4);
int f_0d3390(int p1, short p2, short p3, short p4);
short f_0d3530(short *p1);
extern char *d_1a34e0;
extern char d_1a59d4[];
extern int d_1a59cc;
extern volatile short d_1a59d0;
extern int d_1a59f4;
extern short d_1bf49e;
extern short d_1bf4a0;
extern short d_1bf4a2;
extern short d_1bf4a4;
extern int d_1bf4a8;
extern volatile short d_1bf4ae;
extern short d_1bf4b0[];
extern short d_1bf4b4;
extern signed char d_1bf4b6;
extern unsigned short d_1bf4b8;
extern short d_1bf4ba;
extern volatile short d_1bf4bc;
extern short d_1bf4be;
extern volatile int d_1bf4cc;
extern int d_1bf4c8;
extern volatile int d_1bf4d0;
extern int d_1bf4d4;
extern int d_1bf4d8;
extern volatile int d_1bf4dc;
extern int d_1bf4e0;
extern int d_1bf4e4;
extern volatile char d_1bf4ec;
extern short d_1bf4ed;
extern char d_1bf4ee;
extern signed char d_1bf4ef;
extern unsigned short d_1bf4f0;
extern short d_1bf4f2;
extern volatile short d_1bf4f4;
extern short d_1bf4f6;
extern short d_1bf4f8;
extern short d_1bf4fa;
extern short d_1bf4fc;
extern short d_1bf4fe;
extern volatile short d_1bf500;
extern short d_1bf502;
extern int d_1bf508;
extern char *d_1bf50c;
extern int d_1bf518;
extern short d_1bf51c;
extern short *d_1bf520;
extern int (*d_1bf524)(int);
extern short d_1bf52c;
extern short d_1bf52e;
extern char d_1bf530[];
extern char d_1bf53c[];
extern int d_1bf548;
extern short d_1bf54c;
extern short d_1c0b8a;
extern char d_1c2edc[];
extern RivaFileManager d_1c2098;
extern char *d_1cdb78;
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0d2b10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion schaltet das Maussystem beim Programmende ab, setzt den Maustreiber über
 *   f_0d2d20 zurück, entfernt den Maus-Timer d_1a59f4 (f_147c02) und gibt den Speicherpuffer d_1bf50c für die
 *   Mauszeiger-Grafiken frei.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2b10()
{
    if (d_1bf4ef == 0) {
        f_0d2d20();
        *(volatile signed char *)&d_1bf4ef = 1;
        if (d_1a59f4 != -1) {
            f_147c02(d_1c2edc, d_1a59f4);
            d_1a59f4 = -1;
        }
        if (d_1bf50c) d_1bf50c = (char *)f_014710(d_1bf50c);
    }
}
//@ f_0d2b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Treiber-Schnittstelle ruft den DOS-Mausinterrupt 0x33 (f_05fc00 bei Funktion 0, sonst
 *   f_145702) mit den in den globalen Variablen d_1bf49e (AX), d_1bf4a0 (BX), d_1bf4a2 (CX), d_1bf4a4 (ES/DI)
 *   und d_1bf4a8 (EDX/SI) hinterlegten Registerwerten auf und speichert die Rückgaberegister wieder dort ab.
 * - Eingaben: Diese Funktion nimmt keine direkten Parameter entgegen, sondern nutzt den globalen Registerblock
 *   ab d_1bf49e.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
union SRegs { struct { unsigned short es, cs, ss, ds, fs, gs; } x; unsigned e0; };
void f_0d2b70()
{
    Regs in, out;
    SRegs sr;
    if (d_1bf49e >= 0) {
        in.x.ax = d_1bf49e;
        in.x.bx = d_1bf4a0;
        in.x.cx = d_1bf4a2;
        f_149caa(&sr);
        switch (d_1bf49e) {
        case 9:
        case 0xc:
        case 0x14:
        case 0x16:
        case 0x17:
            in.e.edx = d_1bf4a8;
            sr.x.es = d_1bf4a4;
            break;
        case 0x10:
            in.x.cx = d_1bf4a0;
            in.x.dx = d_1bf4a2;
            in.x.si = d_1bf4a8;
            in.x.di = d_1bf4a4;
            break;
        default:
            in.e.edx = d_1bf4a8;
            break;
        }
        if (d_1bf49e == 0)
            f_05fc00(0x33, &in, &out, &sr);
        else
            f_145702(0x33, &in, &out, &sr);
        d_1bf4a0 = (d_1bf49e == 0x14) ? sr.e0 : out.e.ebx;
        d_1bf49e = out.e.eax;
        d_1bf4a2 = out.e.ecx;
        d_1bf4a4 = 0;
        d_1bf4a8 = out.e.edx;
    }
}
//@ f_0d2cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion registriert über Funktion 0x0c des Mausinterrupts 0x33 (f_0d2b70) eine
 *   benutzerdefinierte Far-Interrupt-Routine handler für die Ereignismaske mask und setzt das Flag d_1bf4ee = 1.
 * - Eingaben: Übergeben werden die Ereignis-Bitmaske mask sowie der Far-Funktionszeiger handler.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2cd0(short mask, void (__far *handler)(void)) {
 if(d_1bf4ef!=1){
  d_1bf49e=12;
  d_1bf4a2=mask;
  d_1bf4a8=FP_OFF(handler);
  d_1bf4a4=FP_SEG((void __far*)handler);
  f_0d2b70();d_1bf4ee=1;
 }
}
//@ f_0d2d20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den Maustreiber über Funktion 0 des Interrupts 0x33 (d_1bf49e = 0, f_0d2b70) in
 *   den Grundzustand zurück und löscht d_1bf4ee.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2d20()
{
    if (d_1bf4ef != 1) {
        d_1bf49e = 0;
        f_0d2b70();
        d_1bf4ee = 0;
    }
}
//@ f_0d2d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die internen Mausstatusvariablen (Startposition (240, 100), Tastenflags
 *   auf 0), lädt die Cursor-Datendatei 0x40003 aus dem Archiv d_1c2098 in den Puffer d_1bf50c und stellt über
 *   f_0d2f90 den Standard-Mauszeiger (0) ein.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2d50()
{
    d_1bf4ee = 0;
    d_1bf4ec = *(volatile char *)&d_1bf4ee;
    *(volatile char *)&d_1bf4ed = d_1bf4ec;
    d_1bf502 = 0;
    d_1bf4e0 = 0;
    d_1bf4d0 = *(volatile int *)&d_1bf4e0;
    d_1bf4d8 = d_1bf4d0;
    d_1bf4c8 = *(volatile int *)&d_1bf4d8;
    d_1bf4e4 = *(volatile int *)&d_1bf4c8;
    d_1bf4d4 = *(volatile int *)&d_1bf4e4;
    d_1bf4dc = *(volatile int *)&d_1bf4d4;
    d_1bf4cc = d_1bf4dc;
    d_1bf4f6 = 1;
    d_1bf4f4 = *(volatile short *)&d_1bf4f6;
    *(volatile short *)&d_1bf51c = 0;
    d_1bf500 = -1;
    *(volatile short *)&d_1bf4f0 = 240;
    *(volatile short *)&d_1bf4f2 = 100;
    short h = f_01a810();
    d_1c2098.f_1448b0(0x40003, h);
    int n = d_1c2098.f_144a00();
    d_1bf50c = (char *)f_014540((short)n, d_1a59d4, 0x22d);
    d_1c2098.f_144920(d_1bf50c, (short)(n | 0x10000));
    d_1c2098.f_1449a0();
    f_0d2f90(0, f_01a7e0());
}
//@ f_0d2e70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wechselt zum zuletzt verwendeten Mauszeiger (d_1bf4be) zurück, entpackt dessen Grafik
 *   aus d_1bf50c in das Cursor-Sprite d_1bf530 (f_15f130), tauscht d_1bf4bc und d_1bf4be aus und zeichnet den
 *   Cursor über f_0d32f0 neu.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2e70()
{
    char obj[28]; int l14; int l10;
    short v;
    f_15ec70(obj);
    if (d_1bf4ef == 0) {
        v = d_1bf4be;
        if (v >= 0) {
            d_1bf4be = d_1bf4bc;
            d_1bf4bc = v;
            f_15f130(obj, ((RivaRasterImage*)(d_1bf530))->f_0fb0b0(), d_1bf50c, v, 0, &l10, &l14, f_0bf570());
            d_1bf4b4 = l10;
            d_1bf4b8 = *(volatile short *)&d_1bf4b4;
            *(short *)&d_1bf4b6 = l14;
            *(volatile short *)&d_1bf4ba = *(volatile short *)&d_1bf4b6;
            d_1bf4f6 = 1;
            d_1bf4f4 = *(volatile short *)&d_1bf4f6;
            d_1bf4ec = 1;
            f_0d32f0();
        }
    }
    f_15eca0(obj, 0);
}
//@ f_0d2f40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die Mausposition sowohl im DOS-Maustreiber (Funktion 4 von Interrupt 0x33) als
 *   auch in den Spielvariablen d_1bf4f0/d_1bf4f2 auf die Koordinaten (p1, p2) und aktualisiert die Darstellung
 *   über f_0d32f0.
 * - Eingaben: Übergeben werden die neue X-Koordinate p1 und die neue Y-Koordinate p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2f40(short p1, short p2)
{
    if (d_1bf4ef != 1) {
        d_1bf49e = 4;
        d_1bf4a2 = p1;
        d_1bf4a8 = p2;
        f_0d2b70();
        d_1bf4f0 = p1;
        *(volatile short *)&d_1bf4f2 = p2;
        d_1bf4ec = 1;
        f_0d32f0();
    }
}
//@ f_0d2f90
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt das Mauszeiger-Symbol mit dem Index p1 aus dem Cursor-Archivpuffer d_1bf50c in
 *   das Sprite d_1bf530, sichert den bisherigen Cursor-Index in d_1bf4be und zeichnet den Mauszeiger bei p2 == 1
 *   sofort über f_0d32f0 neu.
 * - Eingaben: Übergeben werden die neue Cursor-Kennung p1 (z. B. 0 für Pfeil, 5 für Sanduhr) sowie das
 *   Sofort-Neuzeichnen-Flag p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d2f90(short p1, short p2)
{
    char obj[28]; int l14; int l10;
    f_15ec70(obj);
    if (d_1bf4ef == 0) {
        *(volatile signed char *)&d_1bf4ed = 1;
        d_1bf4be = d_1bf4bc;
        d_1bf4bc = p1;
        d_1c0b8a = p1;
        f_15f130(obj, ((RivaRasterImage*)(d_1bf530))->f_0fb0b0(), d_1bf50c, p1, 0, &l10, &l14, f_0bf570());
        d_1bf4b4 = l10;
        d_1bf4b8 = *(volatile short *)&d_1bf4b4;
        *(short *)&d_1bf4b6 = l14;
        *(volatile short *)&d_1bf4ba = *(volatile short *)&d_1bf4b6;
        *(volatile short *)&d_1bf4f6 = 1;
        d_1bf4f4 = d_1bf4f6;
        *(signed char *)&d_1bf4ed = 0;
        d_1bf4ec = 1;
        if (p2 == 1) {
            p2 = 0;
            d_1bf518 = 1;
            f_0d32f0();
            d_1bf518 = p2;
        }
    }
    f_15eca0(obj, 0);
}
//@ f_0d3080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt ein frei übergebenes Rohbild p1 der Größe p2 x p3 Pixel mit dem Hotspot (p4, p5)
 *   als aktuellen benutzerdefinierten Mauszeiger (d_1bf4bc = -1) in das Cursor-Sprite d_1bf530 ein und zeichnet
 *   ihn bei p6 == 1 sofort neu.
 * - Eingaben: Übergeben werden der Bilddatenpuffer p1, die Breite p2, die Höhe p3, der Hotspot-Offset p4 (X) und
 *   p5 (Y) sowie das Neuzeichnen-Flag p6.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d3080(char *p1, short p2, short p3, int p4, int p5, short p6)
{
    if (d_1bf4ef == 0) {
        *(char *)&d_1bf4ed = 1;
        (*(volatile short *)&d_1bf4be) = d_1bf4bc;
        *(short *)&d_1bf4bc = -1;
        memcpy(((RivaRasterImage*)(d_1bf530))->f_0fb0b0(), p1, p2 * p3);
        d_1bf4b4 = p2;
        d_1bf4b8 = *(volatile short *)&d_1bf4b4;
        *(short *)&d_1bf4b6 = p3;
        d_1bf4ba = *(volatile short *)&d_1bf4b6;
        d_1bf4f4 = p4;
        *(volatile short *)&d_1bf4f6 = p5;
        *(char *)&d_1bf4ed = 0;
        d_1bf4ec = 1;
        if (p6 == 1) {
            p6 = 0;
            d_1bf518 = 1;
            f_0d32f0();
            d_1bf518 = p6;
        }
    }
}
//@ f_0d3150
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dekrementiert den Sichtbarkeitszähler d_1bf500 und stellt beim Übergang von 0 auf -1
 *   den unter dem Mauszeiger gesicherten Bildschirmbereich über f_0d3570 wieder her, sodass der Cursor
 *   unsichtbar wird.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d3150()
{
    char st[8];
    f_0d3a10(st);
    if (!*(char *)&d_1bf4ed) {
        if (!*(short *)&d_1bf500) {
            *(volatile char *)&d_1bf4ed = 1;
            f_099ff0(st);
            f_099f70(0, 0, 0x13f, 199);
            f_0d3570(d_1bf4b0);
            f_099fa0(st);
            *(char *)&d_1bf4ed = 0;
        }
        d_1bf500--;
    }
}
//@ f_0d31c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion inkrementiert den Sichtbarkeitszähler d_1bf500 und sichert beim Erreichen von 0 den
 *   Bildschirmhintergrund an der aktuellen (auf den Bildschirmbereich begrenzten) Mausposition über f_0d35b0,
 *   bevor sie das Cursor-Sprite über f_0d3680 darüberzeichnet.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d31c0()
{
    char st[8];
    short x;
    short y;
    short limy;
    short limx;
    f_0d3a10(st);
    if (*(volatile signed char *)&d_1bf4ef != 1 && *(char *)&d_1bf4ed == (char)0) {
        d_1bf500++;
        if (!d_1bf500) {
            *(char *)&d_1bf4ed = 1;
            x = d_1bf4f0;
            y = d_1bf4f2;
            limx = d_1bf52c;
            limy = d_1bf52e;
            --limx;
            --limy;
            if ((int)x < (int)d_1bf4f4)
                x = d_1bf4f4;
            if (x > limx)
                x = limx;
            if ((int)y < (int)d_1bf4f6)
                y = d_1bf4f6;
            if (y > limy)
                y = limy;
            f_099ff0(st);
            f_099f70(0, 0, 0x13f, 199);
            f_0d35b0((short)(x - d_1bf4f4), (short)(y - d_1bf4f6), d_1bf4b0);
            d_1bf4fc = x;
            d_1bf4fe = y;
            f_0d3680(x - d_1bf4f4, y - *(volatile short *)&d_1bf4f6, (char *)d_1bf4b0);
            f_099fa0(st);
            *(volatile char *)&d_1bf4ed = 0;
        }
    }
d_1a59f4 = (d_1a59f4 & 0) ? 0 : d_1a59f4; // haelt die Ladereihenfolge wie im Original
d_1bf4a8 = (d_1bf4a8 & 0) ? 0 : d_1bf4a8; // haelt die Ladereihenfolge wie im Original
}
//@ f_0d32f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion synchronisiert bei Bedarf die Mauskoordinaten mit dem DOS-Treiber (d_1bf4ae), führt
 *   die Bereichsüberwachung f_0d3750 aus und aktualisiert bei Bewegung (d_1bf4ec) oder erzwungenem Update
 *   (d_1bf518 == 1) das Cursorbild auf dem Bildschirm (f_0d3150, f_0d31c0).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d32f0()
{
    if (d_1bf4ef != 1) {
        if (*(short *)&d_1bf4ae != (short)0) {
            short zero = 0;
            d_1bf4ae = zero;
            *(volatile short *)&d_1bf49e = 4;
            d_1bf4a2 = d_1bf4f0;
            d_1bf4a8 = d_1bf4f2;
            f_0d2b70();
        }
        if (d_1bf51c == 1)
            f_0d3750();
        if ((d_1bf4ec || d_1bf518 == 1) && d_1bf548 == 0) {
            if (d_1bf508 == 1) {
                f_0d3150();
                f_0d31c0();
            }
            d_1bf4ec = 0;
        }
    }
}
//@ f_0d3390
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob sich die aktuelle Mausposition (d_1bf4f0, d_1bf4f2) innerhalb des durch (p1,
 *   p2) (links oben) und (p3, p4) (rechts unten) definierten Rechtecks befindet.
 * - Eingaben: Übergeben werden die linke Grenze p1, die obere Grenze p2, die rechte Grenze p3 und die untere
 *   Grenze p4.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Mauszeiger im Rechteck liegt, andernfalls 0.
 === Ende Beschreibung === */
int f_0d3390(int p1, int p2, int p3, int p4)
{
    short mx = 0;
    short my = d_1bf4f2;
    mx = d_1bf4f0;
    if (mx >= (short)p1 && mx <= (short)p3 && my >= (short)p2 && my <= (short)p4)
        return 1;
    return 0;
}
//@ f_0d33d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob die aktuelle Mausposition (d_1bf4f0, d_1bf4f2) innerhalb des durch das
 *   4-Wort-Array p1 ([x1, y1, x2, y2]) beschriebenen Rechtecks liegt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf ein Array aus vier 16-Bit-Rechteckkoordinaten übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Mauszeiger im Rechteck liegt, andernfalls 0.
 === Ende Beschreibung === */
int f_0d33d0(unsigned short *p1)
{
    int mx = 0;
    mx = d_1bf4f0;
    short my = *(volatile short *)&d_1bf4f2;
    my = (short)(my & 0xffff); // R7
    d_1bf4f0 = (d_1bf4f0 & 0) ? 0 : d_1bf4f0; // haelt die Ladereihenfolge wie im Original
    if ((short)mx >= p1[0] && (short)mx <= p1[2] && (int)my >= p1[1] && (short)my <= p1[3])
        return 1;
    return 0;
}
//@ f_0d3420
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob das gesamte sichtbare Rechteck des Mauszeiger-Sprites (unter
 *   Berücksichtigung von Hotspot d_1bf4f4/d_1bf4f6 und Cursorgröße d_1bf4b8/d_1bf4ba) das Bildschirmrechteck
 *   (p1, p2, p3, p4) überlappt (genutzt, um den Cursor nur dann auszublenden, wenn im Zielbereich gezeichnet
 *   wird).
 * - Eingaben: Übergeben werden die vier Grenzen p1 (links), p2 (oben), p3 (rechts) und p4 (unten) des
 *   Zeichenbereichs.
 * - Rückgabewert: Zurückgegeben wird 1 bei einer Überlappung mit dem Mauszeiger, andernfalls 0.
 === Ende Beschreibung === */
int f_0d3420(unsigned short p1, short p2, short p3, unsigned short p4)
{
    p2 = (short)(p2 & 0xffff);
    short mx = *(volatile unsigned short *)&d_1bf4f0;
    mx = (short)(mx & 0xffff);
    int mxi;
    short raw = *(volatile short *)&d_1bf4f2;
    raw=(raw&0)?(short)0:raw; // haelt die Registerzuteilung wie im Original
    short my = raw;
    int width = *(short *)&d_1bf4b8;
    mxi = mx;
    mxi = (mxi & 0) ? 0 : mxi; // haelt die Registerzuteilung wie im Original
    mxi = (mxi & 0) ? 0 : mxi;
    if ((short)p1 <= width + mxi - d_1bf4f4) {
        int height = *(volatile short *)&d_1bf4ba;
        int myi = *(volatile short *)&my;
        int s2 = myi + height - d_1bf4f6;
            s2 = (s2 & 0) ? 0 : s2; // haelt die Registerzuteilung wie im Original
        if (s2 >= p2) {
            int xleft = mxi - d_1bf4f4;
            int edge3 = (xleft & 0) ? 0 : p3; // haelt die Registerzuteilung wie im Original
            if (xleft <= edge3 && myi - *(volatile short *)&d_1bf4f6 <= (short)p4)
                return 1;
        }
    }
    return 0;
}
//@ f_0d34b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob die Koordinaten des letzten Mausklicks (d_1bf4f8, d_1bf4fa) innerhalb des
 *   Rechtecks (p1, p2, p3, p4) liegen.
 * - Eingaben: Übergeben werden die vier Rechteckgrenzen p1 (links), p2 (oben), p3 (rechts) und p4 (unten).
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Klickpunkt im Rechteck liegt, andernfalls 0.
 === Ende Beschreibung === */
int f_0d34b0(int p1, int p2, int p3, int p4)
{
    short mx = 0;
    short my = d_1bf4fa;
    mx = d_1bf4f8;
    if (mx >= (short)p1 && mx <= (short)p3 && my >= (short)p2 && my <= (short)p4)
        return 1;
    return 0;
}
//@ f_0d34f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht eine mit -1 terminierte Liste von Schaltflächen-Rechtecken p1 (je 5
 *   short-Werte: x1, y1, x2, y2, id) anhand der letzten Klickposition (f_0d34b0) und gibt die Kennung des
 *   getroffenen Eintrags zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf das Array der Hotspot-Definitionen übergeben.
 * - Rückgabewert: Zurückgegeben wird die ID p1[4] des angeklickten Bereichs oder 0, falls kein Bereich getroffen
 *   wurde.
 === Ende Beschreibung === */
short f_0d34f0(short *p1)
{
    while (*p1 != -1) {
        if (f_0d34b0(p1[0], p1[1], p1[2], p1[3]))
            return p1[4];
        p1 += 5;
    }
    return 0;
}
//@ f_0d3530
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht eine mit -1 terminierte Liste von Schaltflächen-Rechtecken p1 (je 5
 *   short-Werte) anhand der aktuellen Mauszeigerposition (f_0d3390) und gibt die Kennung des überfahrenen
 *   Bereichs zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf das Array der Hotspot-Definitionen übergeben.
 * - Rückgabewert: Zurückgegeben wird die ID p1[4] des Bereichs unter dem Mauszeiger oder 0, falls keiner
 *   getroffen wurde.
 === Ende Beschreibung === */
short f_0d3530(short *p1)
{
    while ((int)*p1 != -1) {
        if (f_0d3390(p1[0], p1[1], p1[2], p1[3]))
            return p1[4];
        p1 += 5;
    }
    return 0;
}
//@ f_0d3570
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert den im Hintergrund-Sprite d_1bf53c gesicherten Bildausschnitt an die in p1
 *   ([x, y, w, h]) gespeicherten Bildschirmkoordinaten (d_1a34e0) zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf das Array mit Position und Größe des gesicherten Ausschnitts
 *   übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d3570(short *p1)
{
    if (d_1bf4ef != 1)
        ((RivaRasterImage*)(d_1bf53c))->f_0faec0((void *)( d_1a34e0), ((volatile short *)p1)[0], p1[1], ((short *)p1)[2], ((short *)p1)[3]);
}
//@ f_0d35b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schneidet vor dem Zeichnen des Mauszeigers an der Position (p1, p2) den
 *   darunterliegenden Bildschirmausschnitt (an den Rändern f_13f8c0/f_13f8d0 geclippt) aus dem Bildschirmpuffer
 *   (d_1cdb78 bzw. d_1a34e0) aus und sichert ihn im Sprite d_1bf53c.
 * - Eingaben: Übergeben werden die linke obere Ecke (p1, p2) sowie das Beschreibungsarray p3 des Cursorbereichs.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d35b0(short p1, short p2, short *p3)
{
    short sVar1;
    short sVar2;
    short sVar3;
    short sVar4;
    if (d_1bf4ef != 1) {
        sVar4 = p3[4];
        sVar3 = p3[5];
        sVar1 = f_13f8c0();
        sVar2 = f_13f8d0();
        if (p1 > sVar1 - p3[4])
            sVar4 = (sVar1 - p1) + 1;
        if (p2 > sVar2 - p3[5])
            sVar3 = (sVar2 - p2) + 1;
        p3[0] = p1;
        p3[1] = p2;
        p3[2] = sVar4;
        p3[3] = sVar3;
        if (*(int *)&d_1bf54c == 1)
            ((RivaRasterImage*)(d_1bf53c))->f_0fb000((void *)( d_1cdb78), p1, p2, sVar4, sVar3);
        else
            ((RivaRasterImage*)(d_1bf53c))->f_0fb000((void *)( d_1a34e0), p1, p2, sVar4, sVar3);
    }
}
//@ f_0d3680
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet das aktuelle Mauszeiger-Sprite d_1bf530 transparent an den Koordinaten (p1,
 *   p2) (an den Bildschirmrändern geclippt) in den aktiven Bildschirmpuffer (d_1cdb78 bzw. d_1a34e0).
 * - Eingaben: Übergeben werden die Zielkoordinaten p1 (X) und p2 (Y) sowie der Zeiger p3 auf die Größenangaben
 *   des Cursors.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d3680(short p1, short p2, char *p3)
{
    short x;
    short y;
    short w;
    short h;
    short maxx;
    short maxy;
    if (d_1bf4ef != 1) {
        x = p1;
        y = p2;
        w = *(volatile short *)(p3 + 8);
        h = *(short *)(p3 + 10);
        maxx = f_13f8c0();
        maxy = f_13f8d0();
        if (x > maxx - *(short *)(p3 + 8))
            w = (maxx - x) + 1;
        if (y > maxy - *(short *)(p3 + 10))
            h = (maxy - y) + 1;
        if (*(int *)&d_1bf54c == 1)
            ((RivaRasterImage*)(d_1bf530))->f_0faf20((void *)( d_1cdb78), x, y, w, h, 1);
        else
            ((RivaRasterImage*)(d_1bf530))->f_0faf20((void *)( d_1a34e0), x, y, w, h, 1);
    }
}
//@ f_0d3750
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt über f_0d3530 für die registrierte Hotspot-Tabelle d_1bf520, über welchem
 *   Bereich sich der Mauszeiger befindet, und ruft damit die Callback-Funktion d_1bf524 auf.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Rückgabewert des Callbacks d_1bf524 (bzw. 1, wenn die Maus deaktiviert
 *   ist).
 === Ende Beschreibung === */
int f_0d3750()
{
    int r;
    short s;
    r = d_1bf4ef;
    if (r != 1) {
        s = f_0d3530(d_1bf520);
        r = d_1bf524(s);
    }
    return r;
}
//@ f_0d3770
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist eine leere Platzhalterfunktion ohne ausführbare Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0d3770()
{
}
//@ f_0d3780
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Abfragefunktion löscht das Änderungsflag d_1bf4cc und gibt zurück, ob die linke Maustaste
 *   aktuell gedrückt gehalten wird (d_1bf4d4).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1 bei gedrückter linker Maustaste, andernfalls 0.
 === Ende Beschreibung === */
int f_0d3780()
{
    d_1bf4cc = 0;
    return d_1bf4d4;
}
//@ f_0d3790
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Abfragefunktion löscht das Änderungsflag d_1bf4cc und prüft, ob die linke Maustaste aktuell
 *   losgelassen ist (d_1bf4d4 == 0).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1, wenn die linke Maustaste nicht gedrückt ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d3790()
{
    d_1bf4cc = 0;
    return d_1bf4d4 == 0;
}
//@ f_0d37b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Abfragefunktion löscht das Änderungsflag d_1bf4dc und gibt zurück, ob die rechte Maustaste
 *   aktuell gedrückt gehalten wird (d_1bf4e4).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1 bei gedrückter rechter Maustaste, andernfalls 0.
 === Ende Beschreibung === */
int f_0d37b0()
{
    d_1bf4dc = 0;
    return d_1bf4e4;
}
//@ f_0d37c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Abfragefunktion löscht das Änderungsflag d_1bf4dc und prüft, ob die rechte Maustaste aktuell
 *   losgelassen ist (d_1bf4e4 == 0).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1, wenn die rechte Maustaste nicht gedrückt ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0d37c0()
{
    d_1bf4dc = 0;
    return d_1bf4e4 == 0;
}
//@ f_0d37e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest das Doppelklick-Flag d_1bf4d0 aus und setzt sowohl d_1bf4d0 als auch d_1bf4cc
 *   auf 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1, wenn ein Doppelklick vorlag, andernfalls 0.
 === Ende Beschreibung === */
int f_0d37e0()
{
    int u;
    u = d_1bf4d0;
    d_1bf4d0 = 0;
    d_1bf4cc = 0;
    return u;
}
//@ f_0d3800
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den aktuellen Stand des Doppelklick-Flags d_1bf4d0 zerstörungsfrei ab.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Wert von d_1bf4d0 (1 bei Doppelklick, sonst 0).
 === Ende Beschreibung === */
int f_0d3800()
{
    return d_1bf4d0;
}
//@ f_0d3810
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob sich die Mauskoordinaten (d_1bf4f0, d_1bf4f2) seit dem letzten Aufruf
 *   (d_1a59cc, d_1a59d0) verändert haben, und aktualisiert die Vergleichswerte.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1, wenn die Maus bewegt wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0d3810()
{
    int r;
    r = 0;
    if (*(volatile short *)&d_1bf4f0 != d_1a59cc) {
        r = 1;
        d_1a59cc = *(volatile short *)&d_1bf4f0;
    }
    if (*(int *)&d_1a59d0 != d_1bf4f2) {
        r = 1;
        *(int *)&d_1a59d0 = d_1bf4f2;
    }
    return r;
}
