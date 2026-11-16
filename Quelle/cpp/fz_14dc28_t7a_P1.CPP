/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t7a (0x154E78 - 0x155854)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil von fz_14dc28_t7 und implementiert die Wiedergabe aufgezeichneter
 * 3D-Kamerafahrten (f_154e78 bis f_154f08) sowie die sanft beschleunigte und abgebremste automatische
 * Kameradrehung und -bewegung auf einen Zielpunkt in der 3D-Szene (f_155268, f_155298).
 === Ende Beschreibung === */
// P3 13/25 gleich (suche.py 30.10.2026, Basis fz_14dc28_t7_P1.CPP)
// OPT -5r -oneatx -zp1 -s
// P1 9/25 gleich
// CC wcc386
// fz_14dc28_t7 (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x154E78-0x156370
struct V3 { int x, y, z; };
struct Pose { int x, y, z, w; unsigned short a, b, c, pad; };
struct M { int m[9]; struct V3 t; };
struct Ev { unsigned char t; char p1[3]; int v; };
struct Cam { struct V3 pos; int c; unsigned short a, b, cc; };
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define HI(x) (((unsigned short *)&(x))[1])
int FM(int a, int b);
#pragma aux FM = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify exact [eax edx] value [eax];
int FDIV(int a, int b);
#pragma aux FDIV = "mov edx,eax" "sar edx,16" "shl eax,16" "idiv ebx" parm [eax] [ebx] modify exact [eax edx] value [eax];
int MD(int a, int b, int c);
#pragma aux MD = "imul edx" "idiv ebx" parm [eax] [edx] [ebx] modify exact [eax edx] value [eax];
int MD2(int a, int b, int c);
#pragma aux MD2 = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] modify exact [eax edx] value [eax];
int FMB(int a, int b);
#pragma aux FMB = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int RCP(int a);
#include <stdlib.h>
#pragma intrinsic(abs)
#define ABS(x) abs(x)
extern unsigned char d_1a9b88, d_1a9b89, d_1a9b8a, d_1a9947, d_1a9948, d_1a9942, d_1a9943, d_1a9945, d_1a993a, d_1a993d, d_1a994f;
extern unsigned char d_1a9933;
extern unsigned char d_1a9b8b;
extern int d_1a996c, d_1a99f0, d_1a9b8c, d_1a9b34, d_1a9b40, d_1a9b2c, d_1a9b38, d_1a9b3c, d_1a9b30, d_1a9ab8, d_1a9ac4, d_1a9ae0, d_1a9ab0, d_1a9a14, d_1a9a18;
extern unsigned short d_1a9b04, d_1a9b06;
extern int *d_1cdc40; extern char *d_1cdc30;
extern unsigned d_1cdc48, d_1cdc50, d_1cdb18;
extern int d_1cdb3c, d_1cdb20;
extern struct Pose d_1c90c0, d_1c6c78[10];
extern struct Pose *d_1cd1f8;
extern struct V3 d_1cd23c, d_1cd308, d_1cd294, d_1cd328;
extern struct M d_1cd270;
extern int d_1cd248, d_1cd2a4, d_1cc788, d_1cdda0;
extern unsigned short d_1cdc20, d_1cdc1e, d_1cdc1c, d_1cdc1a;
extern struct Ev d_1cdca0[32];
extern int d_1cdc34, d_1cdc38, d_1cdc3c, d_1cdc9c, d_1cdc98, d_1cdc94, d_1cdc74, d_1cdc70, d_1cdc6c, d_1cdc60, d_1cdc5c, d_1cdc58, d_1cdc54, d_1cdc68, d_1cdc64, d_1cdc80, d_1cdc8c, d_1cdc88, d_1cdc7c, d_1cdc90, d_1cdc84;
extern unsigned char d_1cdc79, d_1cdc78;
extern double d_1b9464;
unsigned f_16fc19(void);
#pragma aux f_16fc19 modify exact [eax ecx edx];
void f_153ac8(void);
void f_1508fc(void);
void f_154ba0(int p1);
void f_155f70(struct Cam *p);
void f_155854(void);
void f_155934(void);
void f_155ab0(unsigned short a, int b);
void f_155c94(int a, int b);
void f_155d74(int p);
void f_155e08(int p);
void f_16b930(struct M *m);
void f_16cbdc(struct M *m, unsigned v);
void f_16cc44(struct M *m, unsigned v);
void f_16ccac(struct M *m, unsigned v);
void f_16cd74(struct M *m, int x, int y, int z);
void f_16cff5(struct V3 *o, struct V3 *v, struct M *m);
int f_16d33f(int a, int b, int c, int d);
int f_16d3d0(int a);
int f_16d4d8(int a, int b);
int f_16d4fc(int a, int b, int c);
int f_16d7e7(int a);
short f_16d8ad(short a, short b);
void f_176f10(int *a, int *b, int *c);
#pragma aux f_16cff5 parm [eax] [edx] [ebx] modify exact [eax edx];
#pragma aux f_16d4d8 parm caller [] modify exact [eax];
#pragma aux f_16d4fc parm caller [] modify exact [eax];
#pragma aux f_16d7e7 parm caller [] modify exact [eax];
#pragma aux f_16d8ad parm caller [];
#pragma aux f_154e78 "*";
#pragma aux f_154eb8 "*";
#pragma aux f_154f00 "*";
#pragma aux f_154f08 "*";
#pragma aux f_155268 "*";
#pragma aux f_155298 "*";
#pragma aux f_155854 "*";
#pragma aux f_155900 "*";
#pragma aux f_155928 "*";
#pragma aux f_155934 "*";
#pragma aux f_155968 "*";
#pragma aux f_1559e0 "*";
#pragma aux f_155ab0 "*";
#pragma aux f_155b20 "*";
#pragma aux f_155b80 "*";
#pragma aux f_155bc8 "*";
#pragma aux f_155bfc "*";
#pragma aux f_155c30 "*";
#pragma aux f_155c64 "*";
#pragma aux f_155c94 "*";
#pragma aux f_155d74 "*";
#pragma aux f_155e08 "*";
#pragma aux f_155ebc "*";
#pragma aux f_155f70 "*";
#pragma aux f_1560ac "*";

//@ f_154e78
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Bereitet das Abspielen einer zuvor aufgezeichneten 3D-Kamerafahrt aus dem Puffer p vor.
 *   Sofern p != 0 und keine Aufzeichnung aktiv ist (d_1a9947 == 0), setzt sie den Pufferzeiger d_1cdc40 = p, den
 *   Keyframe-Lesezeiger d_1cdc30 = (char *)(p + 10), den aktuellen Keyframe-Index d_1cdb18 = 0 und aktiviert die
 *   Wiedergabeflags d_1a9b88 = 1 und d_1a9b89 = 1.
 * - Eingaben: p (Zeiger auf den Kamerafahrt-Datenpuffer).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc40 (Pufferkopf), d_1cdc30 (Keyframe-Array), d_1a9b88 (Wiedergabe-Aktiv-Flag).
 === Ende Beschreibung === */
void f_154e78(int *p)
{
    if (p == 0 || d_1a9947 != 0) {
        d_1a9b88 = 0;
        return;
    }
    d_1cdc40 = p;
    d_1cdc30 = (char *)(p + 10); d_1cdb18 = 0;
    d_1a9b89 = 1;
    d_1a9b88 = 1;
}

//@ f_154eb8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest aus einem Kamerafahrt-Datenpuffer h die 3D-Startkoordinaten (X, Y, Z) des ersten
 *   Keyframes aus und schreibt sie in die Ausgabeparameter o1, o2 und o3.
 * - Eingaben: h (Kamerafahrt-Puffer), o1, o2, o3 (Ausgabezeiger für die Startposition).
 * - Rückgabewert: 0 bei Erfolg, 0xf005 bei ungültigen Zeigern oder leerem Puffer.
 * - Wichtige Variablen: p (Zeiger auf den Datenbereich ab h + 8).
 === Ende Beschreibung === */
int f_154eb8(int *h, int *o1, int *o2, int *o3)
{
    int v;
    char *p;

    if (h == 0 || o1 == 0 || o2 == 0 || o3 == 0) return 0xf005;
    v = *h;
    p = (char *)h + 8;
    if (v == 0 || h[1] <= 0) return 0xf005;
    *o1 = I32(p, 0x24);
    *o2 = I32(p, 0x28);
    *o3 = I32(p, 0x2c);
    return 0;
}

//@ f_154f00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verschiebt den Referenz-Zeitstempel d_1cdc48 einer laufenden Kamerafahrt-Aufzeichnung oder
 *   -Wiedergabe um v Zeiteinheiten (z. B. um eine Pause herauszurechnen).
 * - Eingaben: v (Zeitdifferenz in Ticks).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1cdc48 (Basis-Zeitstempel).
 === Ende Beschreibung === */
void f_154f00(int v)
{
    d_1cdc48 += v;
}

#pragma inline_depth(0)
//@ f_154f08
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt einen einzelnen Wiedergabeschritt einer aufgezeichneten 3D-Kamerafahrt (d_1cdc40)
 *   aus. Beim ersten Aufruf (d_1a9b89 != 0) kann optional (flag != 0) ein weicher Übergangs-Keyframe von der
 *   aktuellen Kamerapose d_1c90c0 mit Dauer dt vorangestellt werden. In jedem Schritt bestimmt die Funktion
 *   anhand der verstrichenen Zeit t das aktuelle Keyframe-Paar in d_1cdc30, interpoliert Position (x, y, z) und
 *   Drehwinkel (a, b, c unter Berücksichtigung des 16-Bit-Winkelüberlaufs bei 0x8000) linear und rendert das
 *   neue Bild über f_153ac8.
 * - Eingaben:
 *   - flag: 1, wenn zu Beginn weich von der aktuellen Kameraposition zum ersten Keyframe übergeblendet werden
 *     soll, sonst 0.
 *   - dt: Dauer der Eingangs-Überblendung in Ticks (maximal 0x12c = 300).
 * - Rückgabewert: 1, solange noch weitere Keyframes folgen ((d_1cdc50 - 1) > d_1cdb18), 0 nach Erreichen des
 *   Endes.
 * - Wichtige Variablen:
 *   - d_1cdb18: Aktueller Keyframe-Index.
 *   - f: 16.16-Festkomma-Interpolationsfaktor zwischen zwei Keyframes.
 *   - d_1c90c0: Interpolierte Kamerapose.
 === Ende Beschreibung === */
// BLIND: f_154f08 hier komplett neu aus dem Original-Assembler schreiben (orig.sh fz_14dc28_t7a f_154f08).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
struct KF { unsigned short w; unsigned short pad; struct Pose pose; int dt; };
int f_154f08(int flag, unsigned dt)
{
    
    unsigned ab6_timer(void);
    extern int a2_guard_index;
#pragma aux a2_guard_index "_d_1cdb18";
    int a4_y_mul(int, int);
    int a4_angle_mul(int, int);
#pragma aux (FMB) a4_angle_mul parm __nomemory [eax] [ebx] modify exact __nomemory [eax edx];
#pragma aux (FM) a4_y_mul modify exact __nomemory [eax edx];
    int b1;
    int f;
    int d1;
    int d0;
    int b2;
    int a0;
    int d;
    int d2;
    char *p;
    int b0;
    unsigned k;
    int a1;
    int t;
    int a2;


    if (d_1a9b88 == 0 || d_1a9947 != 0) return 0;
    if (d_1a9b89 != 0) {
        t = 0;
        d_1cdc48 = f_16fc19() / 0x2e97;
        k = *d_1cdc40;
        d_1a9b89 = 0;
        d_1cdc50 = k;
        if (flag != 0) {
            if (dt > 0x12c) dt = 0x12c;
            d_1cdc30 -= 0x20;
            p = d_1cdc30;
            *(unsigned short *)p = U16(p, 0x20);
            *(struct Pose *)(p + 4) = d_1c90c0;
            t = -(int)dt;
            I32(p, 0x1c) = t;
            ++d_1cdc50;
            d_1cdc48 += dt;
        }
    } else {
        t = f_16fc19() / 0x2e97 - d_1cdc48;
    }
    { unsigned timer_copy = d_1cdc48;
      timer_copy = (timer_copy & 0) ? 0 : timer_copy; // haelt die Registerzuteilung wie im Original
      k = d_1cdc50;
      k = (k & 0) ? 0 : k; // haelt die Registerzuteilung wie im Original
      d_1cdc50 += k - d_1cdc50;
      d_1cdc48 += timer_copy - d_1cdc48; }
    a1 = d_1cdc50;
    if ((unsigned)a1 <= a2_guard_index || t >= d_1cdc40[1]) return 0;
    p = d_1cdc30;
    p += d_1cdb18 << 5;
    while ((unsigned)a1 - 1 > d_1cdb18) {
        if (t < I32(p, 0x3c)) break;
        ++d_1cdb18;
        p += 0x20;
    }
    k = d_1cdc50 - 1;
    if (k <= d_1cdb18) {
        p = d_1cdc30 + (k << 5);
        d_1cdb3c = *(unsigned short *)p;
        f_155f70((struct Cam *)(p + 4));
    } else {
        d_1c90c0 = *(struct Pose *)(p + 4);
        d = I32(p, 0x3c) - I32(p, 0x1c);
        if (d <= 0) d = 1;
        f = MD(0x10000, t - I32(p, 0x1c), d);
        d_1c90c0.x += FM(f, I32(p, 0x24) - I32(p, 4));
        d_1c90c0.y += a4_y_mul(f, I32(p, 0x28) - I32(p, 8));
        d_1c90c0.z += FM(f, I32(p, 0x2c) - I32(p, 0xc));
        a0 = U16(p, 0x14);
        a1 = U16(p, 0x16);
        a2 = U16(p, 0x18);
        b0 = U16(p, 0x34);
        b1 = U16(p, 0x36);
        b2 = U16(p, 0x38);
        d0 = b0 - a0;
        d1 = b1 - a1;
        d2 = b2 - a2;
        if (ABS(d0) > 0x8000) {
            if (a0 < 0x8000) {
                a0 += 0x10000;
 // haelt die Registerzuteilung wie im Original
                a0 = (a0 & 0) ? 0 : a0; // haelt die Registerzuteilung wie im Original
            }
            if (b0 < 0x8000) b0 += 0x10000;
            a0 = (a0 & 0) ? 0 : a0; // haelt die Registerzuteilung wie im Original
        }
        if (ABS(d1) > 0x8000) {
            if (a1 < 0x8000) a1 += 0x10000;
            if (b1 < 0x8000) b1 += 0x10000;
        }
        if (ABS(d2) > 0x8000) {
            if (a2 < 0x8000) {
                a2 += 0x10000;
                a2 = (a2 & 0) ? 0 : a2; // haelt die Registerzuteilung wie im Original
                a2 = (a2 & 0) ? 0 : a2; // haelt die Registerzuteilung wie im Original
            }
            if (b2 < 0x8000) b2 += 0x10000;
        }
        a0 += a4_angle_mul(f, b0 - a0);
        a1 += a4_angle_mul(f, b1 - a1);
        a2 += a4_angle_mul(f, b2 - a2);
        d_1c90c0.a = a0;
        d_1c90c0.b = a1;
        d_1c90c0.c = a2;
        d_1cdb3c = f < 0x8000 ? *(unsigned short *)p : U16(p, 0x20);
    }
    d_1cdb20 = d_1cdc50;
    d_1a9948 = 1;
    d_1a9942 = 1;
    f_153ac8();
    d_1a9948 = 0;
    d_1a9942 = 0;
    return (d_1cdc50 - 1) > d_1cdb18;
}


#pragma inline_depth(3)

//@ f_155268
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Registriert einen neuen Zielpunkt (a, b, c) für eine automatische, weich gesteuerte
 *   Kamerabewegung (f_155298) und setzt das Startflag d_1a9b8a = 1, sofern nicht bereits eine solche Bewegung
 *   gesperrt ist (d_1a9b8b == 0).
 * - Eingaben: a, b, c (Zielkoordinaten X, Y, Z im 16.16-Festkommaformat).
 * - Rückgabewert: 1 bei Annahme des Ziels, 0 wenn bereits gesperrt.
 * - Wichtige Variablen: d_1cdc34, d_1cdc38, d_1cdc3c (Zielkoordinaten X, Y, Z), d_1a9b8a (Initialisierungsflag).
 === Ende Beschreibung === */
int f_155268(int a, int b, int c)
{
    if (d_1a9b8b) return 0;
    d_1cdc34 = a;
    d_1cdc38 = b;
    d_1cdc3c = c;
    d_1a9b8a = 1;
    return 1;
}

//@ f_155298
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt eine zweistufige, sanft beschleunigte und abgebremste Kamera-/Spielerbewegung von
 *   der aktuellen Position d_1cd308 zum in f_155268 gesetzten Zielpunkt (d_1cdc34, d_1cdc38, d_1cdc3c) mit der
 *   Grundgeschwindigkeit incoming_sp durch. In der ersten Phase (d_1cdc79 != 0) dreht die Funktion die Kamera
 *   mit Anfahr- und Bremsrampe in Richtung des Zielpunkts (d_1c90c0.a, d_1c90c0.b); in der zweiten Phase
 *   (d_1cdc79 == 0) fährt sie die Kamera entlang des Differenzvektors (d_1cdc74, d_1cdc70, d_1cdc6c) zum Ziel
 *   und rendert jeden Zwischenschritt über f_153ac8.
 * - Eingaben: incoming_sp (Geschwindigkeitsfaktor, mindestens 0xa3d).
 * - Rückgabewert: 1, solange die Dreh- oder Fahrbewegung noch andauert (oberstes Byte von d_1a9b88), 0 nach
 *   Erreichen des Ziels.
 * - Wichtige Variablen:
 *   - progressD10 (d_1cdc84): Laufender Fortschrittsparameter (0 bis 0x10000) der aktuellen Phase.
 *   - d_1cdc79: Phasenflag (1 = Rotationsphase zum Ziel, 0 = Translationsphase zum Ziel).
 *   - c90298.v (d_1cdc90): Momentane Winkel- bzw. Fahrgeschwindigkeit.
 === Ende Beschreibung === */
void bar298(void);
#pragma aux bar298 = "" parm [] modify exact [];
int rcp298(int hi, int lo, int a);
#pragma aux rcp298 = "idiv ebx" parm __nomemory [edx] [eax] [ebx] modify exact __nomemory [eax edx] value [eax];
int div298(int a, int b);
#pragma aux div298 = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm __nomemory [edx] [ebx] value [eax] modify exact __nomemory [eax ebx edx];
int fm298(int a, int b);
#pragma aux (FM) fm298 parm __nomemory [eax] [edx] modify exact __nomemory [eax edx];
int fmb298(int a, int b);
#pragma aux (FMB) fmb298 parm __nomemory [eax] [ebx] modify exact __nomemory [eax ebx edx];
int md298(int a, int b, int c);
#pragma aux (MD) md298 parm __nomemory [eax] [edx] [ebx] modify exact __nomemory [eax edx];


struct V298 { int v; };
extern struct V298 c90298;
#pragma aux c90298 "_d_1cdc90";

extern struct V298 c54298;
#pragma aux c54298 "_d_1cdc54";
extern struct V298 c90b298;
#pragma aux c90b298 "_d_1cdc90";
int same_b298(int v);
#pragma aux (bar298) same_b298 parm __nomemory [ebx] value [ebx] modify exact __nomemory [];
int same_c298(int v);
#pragma aux (bar298) same_c298 parm __nomemory [ecx] value [ecx] modify exact __nomemory [ecx];
unsigned short same_dx298(unsigned short v);
#pragma aux (bar298) same_dx298 parm [dx] value [dx] modify exact [dx];
int same_di298(int v);
#pragma aux (bar298) same_di298 parm __nomemory [edi] value [edi] modify exact __nomemory [edi];
int same_si298(int v);
#pragma aux (bar298) same_si298 parm __nomemory [esi] value [esi] modify exact __nomemory [esi];
int same_a298(int v);
#pragma aux (bar298) same_a298 parm __nomemory [eax] value [eax] modify exact __nomemory [eax];
void hold_d298(int v);
#pragma aux (bar298) hold_d298 parm __nomemory [edx] modify exact __nomemory [];
int same_d298(int v);
#pragma aux (bar298) same_d298 parm __nomemory [edx] value [edx] modify exact __nomemory [edx];
extern volatile int cmp90298;
#pragma aux cmp90298 "_d_1cdc90";
int pair_a298(int low, int high);
#pragma aux (bar298) pair_a298 parm __nomemory [eax] [edx] value [eax] modify exact __nomemory [eax];
int result_before_di298(int value);
#pragma aux (bar298) result_before_di298 parm __nomemory [eax] value [eax] modify exact __nomemory [eax edi];
int angle_mem298(int angle);
#pragma aux (bar298) angle_mem298 parm [eax] value [eax] modify exact [eax edi];
unsigned char same_al298(unsigned char value);
#pragma aux (bar298) same_al298 parm __nomemory [al] value [al] modify exact __nomemory [al];
unsigned char same_ah298(unsigned char value);
#pragma aux (bar298) same_ah298 parm __nomemory [ah] value [ah] modify exact __nomemory [ah];
unsigned char same_bl298(unsigned char value);
#pragma aux (bar298) same_bl298 parm __nomemory [bl] value [bl] modify exact __nomemory [bl];
unsigned char same_bh298(unsigned char value);
#pragma aux (bar298) same_bh298 parm __nomemory [bh] value [bh] modify exact __nomemory [bh];
unsigned char same_cl298(unsigned char value);
#pragma aux (bar298) same_cl298 parm __nomemory [cl] value [cl] modify exact __nomemory [cl];
unsigned char same_ch298(unsigned char value);
#pragma aux (bar298) same_ch298 parm __nomemory [ch] value [ch] modify exact __nomemory [ch];
unsigned char same_dl298(unsigned char value);
#pragma aux (bar298) same_dl298 parm [dl] value [dl] modify exact [dl];
unsigned char same_dh298(unsigned char value);
#pragma aux (bar298) same_dh298 parm __nomemory [dh] value [dh] modify exact __nomemory [dh];
unsigned short angle_before_bh298(unsigned short angle);
#pragma aux (bar298) angle_before_bh298 parm [dx] value [dx] modify exact [dx bh];
int fmb_pose298(int a, int b);
#pragma aux (fmb298) fmb_pose298 parm [eax] [ebx] modify exact [eax ebx edx];
int threshold_no_si298(int value);
#pragma aux (bar298) threshold_no_si298 parm __nomemory [ecx] value [ecx] modify exact __nomemory [ecx esi];
void entry_before_bp298(void);
#pragma aux (bar298) entry_before_bp298 parm [] modify exact [ebp];
void forget_a298(void);
#pragma aux (bar298) forget_a298 parm __nomemory [] modify exact __nomemory [eax ebx ecx edx esi];
int init_d_mem298(int value);
#pragma aux (bar298) init_d_mem298 parm [edx] value [edx] modify exact [edx];
int f_155298(int incoming_sp)
{
    int spd, k, r, len, hxy, d3, c, q0, x, q2, y, z, tt;
    int s[3];
    short h0, h2;
    int maxangle;
    volatile int scratch;
    int m;

    int sp;
    int progressD10 = d_1cdc84;
    int result;
    entry_before_bp298();
    sp = same_a298(incoming_sp);
    forget_a298();
    if (d_1a9947) { result = 0; goto done_d10; }
    {
        if (d_1a9b8a) {
            int dx, dy, dz, denominator, quarter_y, raw_denominator, quarter_z;
            if (sp < 0xa3d) sp = 0xa3d;
             /* haelt die Registerzuteilung wie im Original */
            { int keep_sp_priority = sp; sp = keep_sp_priority; } /* haelt die Registerzuteilung wie im Original */
            { int keep_local_sp = sp; sp = keep_local_sp; } /* haelt die Registerzuteilung wie im Original */
            x = d_1cd308.x;
             /* haelt die Registerzuteilung wie im Original */
            
            
            y = d_1cd308.y;
            d_1a9b8a = same_dh298(0);
            d_1cdc9c = x;
            d_1cdc98 = y;
            dx = d_1cdc34;
            dx -= x;
            { int keep_dx = dx; dx = keep_dx; } /* haelt die Registerzuteilung wie im Original */
            z = d_1cd308.z;
            { int keep_z0 = z; z = keep_z0; } /* haelt die Registerzuteilung wie im Original */
            { int keep_z1 = z; z = keep_z1; }
            { int keep_z2 = z; z = keep_z2; }
            d_1cdc74 = dx;
            d_1cdc94 = z;
            dy = d_1cdc38;
            dy -= y;
            { int keep_dy0 = dy; dy = keep_dy0; } /* haelt die Registerzuteilung wie im Original */
            { int keep_dy1 = dy; dy = keep_dy1; }
            { int keep_dy2 = dy; dy = keep_dy2; }
            d_1cdc70 = dy;
            dz = d_1cdc3c;
            s[0] = dx >> 2;
            dz -= z;
            d_1cdc6c = dz;
            quarter_z = same_d298(dz);
            s[1] = dy >> 2;
            quarter_y = same_b298(s[1]);
            { unsigned char init_flag = same_cl298(1); d_1cdc79 = init_flag;
              ((unsigned char *)&d_1a9b88)[3] = init_flag; }
            s[2] = quarter_z >> 2;
            { int dot_value = f_16d33f(s[0], s[0], quarter_y, s[1]);
              int len_z = same_d298(s[2]);
              hxy = f_16d3d0(dot_value);
              len = f_16d4fc(s[0], s[1], len_z); }
            raw_denominator = f_16d4d8(s[1], hxy);
            denominator = raw_denominator;
            if (raw_denominator > 2) {
                r = rcp298(1, 0, denominator);
                scratch = r;
                { int product_c = fmb298(s[1], r);
                r = scratch; c = product_c;
                m = fmb298(hxy, r); }
                { int keep_slope = m; m = keep_slope; } /* haelt die Registerzuteilung wie im Original */
            } else {
                c = 0x7fff;
                m = denominator ^ same_a298(raw_denominator);
            }
            { int keep_slope_join = m; m = keep_slope_join; } /* haelt die Registerzuteilung wie im Original */
            { int keep_length = len; len = keep_length; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_0 = len; len = rank_len_0; } /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
            { int rank_len_4 = len; len = rank_len_4; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_5 = len; len = rank_len_5; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_6 = len; len = rank_len_6; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_7 = len; len = rank_len_7; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_8 = len; len = rank_len_8; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_9 = len; len = rank_len_9; } /* haelt die Registerzuteilung wie im Original */
            { int rank_len_10 = len; len = rank_len_10; } /* haelt die Registerzuteilung wie im Original */

            q0 = div298(s[0], len);
            q0 = pair_a298(q0, s[1]);
            scratch = q0;
            s[0] = q0;
            s[1] = div298(s[1], len);
            z = div298(s[2], len);
            { int u_ = c; c = u_; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_0 = c; c = rank_c_0; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_1 = c; c = rank_c_1; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_2 = c; c = rank_c_2; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_3 = c; c = rank_c_3; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_4 = c; c = rank_c_4; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_5 = c; c = rank_c_5; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_6 = c; c = rank_c_6; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_7 = c; c = rank_c_7; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_8 = c; c = rank_c_8; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_9 = c; c = rank_c_9; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_10 = c; c = rank_c_10; } /* haelt die Registerzuteilung wie im Original */
            { int rank_c_11 = c; c = rank_c_11; } /* haelt die Registerzuteilung wie im Original */
 
            q0 = -scratch;
            z = same_a298(z);
            { int keep_neg0 = q0; q0 = keep_neg0; } { int keep_neg1 = q0; q0 = keep_neg1; } 
            
            h0 = q0 / 2;
            h2 = -z / 2;
            q2 = same_c298(c) / 2;
            d3 = m / 2;
            c = d_1cdc1a + d_1cdc20;
            d_1cdc60 = c;
            d_1cdc5c = d_1cdc1e;
            d_1cdc58 = (unsigned short)f_16d8ad(q2, d3);
            same_di298(progressD10); /* haelt die Registerzuteilung wie im Original */
            { int angle_value, startB, deltaA, deltaB; unsigned short angle_raw;
              angle_raw = (unsigned short)f_16d8ad(h0, h2);
              c = d_1cdc60;
              bar298();
              angle_value = angle_mem298(angle_raw);
              startB = same_di298(d_1cdc5c);
              c54298.v = angle_value;
              deltaA = d_1cdc58;
              deltaB = *(volatile int *)&c54298.v;
              deltaA -= c;
              deltaB -= startB;
              d_1cdc68 = deltaA;
              d_1cdc64 = deltaB; }
            if (ABS(d_1cdc68) > 0x8000) {
                bar298(); /* haelt die Registerzuteilung wie im Original */ if (c < 0x8000) d_1cdc60 += 0x10000;
                if (d_1cdc58 < 0x8000) d_1cdc58 += 0x10000;
            }
            if (ABS(d_1cdc64) > 0x8000) {
                bar298(); /* haelt die Registerzuteilung wie im Original */ if (d_1cdc5c < 0x8000) d_1cdc5c += 0x10000;
                if (d_1cdc54 < 0x8000) d_1cdc54 += 0x10000;
            }
            { int angle_left = d_1cdc58;
              bar298();
              d_1cdc68 = tt = angle_left - same_di298(d_1cdc60); }
             /* haelt die Registerzuteilung wie im Original */
            d_1cdc64 = d_1cdc54 - d_1cdc5c;
            r = ABS(d_1cdc64);
            maxangle = ABS(tt);
            r = same_b298(r); /* haelt die Registerzuteilung wie im Original */
            if (maxangle < r) maxangle = r;
             /* haelt die Registerzuteilung wie im Original */
            scratch = maxangle;
            k = maxangle;
            if (scratch <= d_1b9464) k = 0x28f;
            d_1cdc80 = same_a298(0x8000);
            { int dividend = same_d298(0x4ccc);
              int high = dividend >> 16;
              int low = pair_a298(dividend, high);
              d_1cdc8c = rcp298(high, low << 16, k); }
            d_1cdc88 = md298(0xa0000, sp, same_si298(len));
            progressD10 = 0;
            d_1cdc7c = d_1cdc8c / 3;
            d_1cdc78 = same_al298(1);
            c90298.v = 0;
        }
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
         /* haelt die Registerzuteilung wie im Original */
        spd = d_1a9ab0;
        if (spd < 0xccc) spd = 0xccc;
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */
             /* haelt die Registerzuteilung wie im Original */

        r = same_a298(0x10000);
        r -= progressD10;
         /* haelt die Registerzuteilung wie im Original */
        { int keep_remaining3 = r; r = keep_remaining3; }
        k = d_1cdc7c;
        bar298();
        { unsigned char phase_flag = same_dl298(d_1cdc79);
          k += 0xccc;
        if (phase_flag != 0) {
            if (progressD10 < d_1cdc80) {
                len = same_si298(d_1cdc8c);
                c = c90298.v;
                if (c < len) {
                    c += fm298(d_1cdc7c, spd);
                    c90298.v = c;
                } else if (d_1cdc78 != 0 && progressD10 < 0x8000) {
                    d_1cdc80 = same_a298(r);
                    d_1cdc78 = same_dh298(0);
                }
            } else {
                int threshold_now = same_c298(k);
                if (threshold_now < cmp90298) {
                    int brake_amount = fm298(d_1cdc7c, spd);
                    c90b298.v -= brake_amount;
                }
            }
            progressD10 = same_di298(progressD10 + fm298(c90298.v, spd));
            if (progressD10 > 0x10000) {
                progressD10 = 0x10000;
                d_1cdc79 = same_bl298(0);
            }
            d_1c90c0.a = (unsigned short)d_1cdc60 + fmb298(progressD10, d_1cdc68);
            { int angle_product; unsigned short angle_base;
              angle_product = fmb_pose298(progressD10, d_1cdc64);
              angle_base = (unsigned short)d_1cdc5c;
              d_1cdc84 = progressD10;
              angle_base = same_dx298(angle_base);
               /* haelt die Registerzuteilung wie im Original */
               /* haelt die Registerzuteilung wie im Original */
               /* haelt die Registerzuteilung wie im Original */
              angle_base += angle_product;
              angle_base = angle_before_bh298(angle_base);
              d_1c90c0.b = angle_base; }
            if (same_bh298(d_1cdc79) == 0) {
                int new_rate;
                d_1cdc80 = same_a298(0x8000);
                new_rate = same_d298(d_1cdc88) / 8;
                progressD10 = same_di298(0);
                c90298.v = progressD10;
                d_1cdc78 = same_cl298(1);
                d_1cdc84 = progressD10;
                d_1cdc7c = new_rate;
            }
        } else {
            len = same_si298(d_1cdc80);
            hold_d298(progressD10);
            if (progressD10 < len) {
                len = same_si298(d_1cdc88);
                c = c90298.v;
                if (c < len) {
                    c += fm298(d_1cdc7c, spd);
                    c90298.v = c;
                } else if (d_1cdc78 != 0 && progressD10 < 0x8000) {
                    d_1cdc80 = same_a298(r);
                    d_1cdc78 = same_ch298(0);
                }
            } else {
                int saved_speed = c90298.v;
                if (threshold_no_si298(k) < saved_speed) {
                    int brake_amount = fm298(d_1cdc7c, spd);
                    c90298.v = same_d298(saved_speed) - brake_amount;
                }
            }
            progressD10 = same_di298(progressD10 + fm298(c90298.v, spd));
            if (progressD10 > 0x10000) {
                progressD10 = 0x10000;
                ((unsigned char *)&d_1a9b88)[3] = same_al298(0);
            }
            d_1c90c0.x = fm298(progressD10, d_1cdc74) + d_1cdc9c;
            d_1c90c0.y = fm298(progressD10, d_1cdc70) + d_1cdc98;
            d_1c90c0.z = fm298(progressD10, d_1cdc6c) + d_1cdc94;
            d_1cdc84 = progressD10;
        }
        }
        { unsigned char draw_flag = same_ch298(1); d_1a9948 = draw_flag;
          d_1a9942 = draw_flag; }
        f_153ac8();
        { unsigned char draw_flag = same_ah298(0); d_1a9948 = draw_flag;
          d_1a9942 = draw_flag; }
        result = *(int *)&d_1a9b88 >> 24;
        result = result_before_di298(result);
    }
done_d10:
    same_di298(d_1cdc84);
     /* haelt die Registerzuteilung wie im Original */
     /* haelt die Registerzuteilung wie im Original */
    { int keep_result3 = result; result = keep_result3; } /* haelt die Registerzuteilung wie im Original */
    { int keep_result4 = result; result = keep_result4; }
    return result;
}
