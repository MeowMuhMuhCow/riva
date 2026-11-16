/* === Beschreibung (Katalog) ===
 * Einheit gz_05fbf0_t1 (0x05FBF0 - 0x05FF60)
 *
 * Überblick
 * Die Einheit gz_05fbf0_t1 kapselt die DPMI-Schnittstelle (Interrupt 0x31) für den Zugriff auf den unteren
 * DOS-Konventionalspeicher (Real-Mode-Speicher unterhalb von 1 MB): Sie bietet das Absetzen von
 * Real-Mode-Interrupts (f_05fc00), die Ermittlung des freien DOS-Speichers (f_05fd00), das Reservieren und
 * Freigeben von DOS-Speicherblöcken mit "GUYS"/"GUYE"-Wächtermarkierungen (f_05fd70, f_05fe40) sowie die
 * Methoden einer DosMem-Hüllklasse (f_05fe80 bis f_05ff30).
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
extern const char d_1b6f1c[];
// P3 25/27 gleich (suche.py 25.10.2026, Basis gz_05fbf0_P1.CPP)
// I9: aus gz_05fbf0_REST.CPP uebernommen (Stufe-2-Stand), Marken 25 neu
// gz_05fbf0.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x05FBF0-0x060360. DPMI-Aufrufe (DOS-Speicherblock), Tuer-Objekt mit Vtabelle, kleine Stubs.
// ACHTUNG: zwei OBJ - Modulgrenze bei 0x05FF60 (Nullfuellung davor, R13). Teil A 05FBF0-05FF60, Teil B 05FF60-060360.
// STAND: Rest 060100 (17 Bef.), 060190 (36), 060320 (11), 05FF60 (3), Tail-jmp-Marken 0600F0/060230/0602C0 (je 1, vermutlich nur Maske).
#define int386x f_145702
#include <i86.h>
#include <string.h>
struct Game; struct Door;
int f_051870(const char *s, int z);
short *f_0696b0(short *p);
int f_0696c0(short *p);
void f_0698b0(short *p, long a, int b);
void f_069970(short *p, long a, int b);
void *f_069730(short *p, int idx);
int f_069640(void *s);
int f_0695b0(void *s);
void f_069650(void *s, int v);
void f_069630(void *s, int v);
void f_069670(void *s, int v);
int f_08c920(int a, int b);
short f_1457e0(short n);
void f_11f920(int k, int b, int c);
void f_056a50(int a);
int f_0de7c0(Game *g);
short f_0de820(Game *g);
short f_0de9a0(Game *g);
void f_0dd750(Game *g, unsigned short v);
void f_0de9b0(Game *g, int v);
int f_0de880(Game *g);
int f_0de840(Game *g);
void f_019800(void *p, int a, int b, int c);
void f_019b30(void *p, short *q);
void f_01a490(void *p);
void f_01a470(void *p);
struct Q { void f_0e93f0(char *p, long code); };
struct Msg { void f_0bf730(long code); };


void *f_038c40(Game *g);
extern struct RMs { unsigned edi, esi, ebp, r0, ebx, edx, ecx, eax; unsigned short fl, es, ds, fs, gs, ip, sp, ss; } d_1bd68c;
extern short *d_1bd6c0;
extern struct S3 { char a; short b; } d_1bd6c8;
extern signed char d_1bd90e;
extern int d_1bd91c;
extern signed char d_1c01cc;
extern short d_1c2198;
extern short d_1c212a;
extern Game *d_1c0004;
extern Game d_1bfdbc[6];
extern char d_1c2a84[];
extern char d_1c27a8[];
extern Q d_1c38b0;
extern Msg d_1c2c64;
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern void *d_1badd0[];
struct Game { char b[0x61]; };
struct Door { short id; char b[6]; void (**vt)(); };

//@ f_05fbf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstanter Hilfs-Stub, der stets 1 zurückgibt (Bereitschafts- bzw. Vorhandenseinsprüfung).
 * - Eingaben: Keine.
 * - Rückgabewert: int - Immer 1.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_05fbf0()
{
    return 1;
}

//@ f_05fc00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt über die DPMI-Funktion 0x0300 (int 0x31, Simulate Real Mode Interrupt) den
 *   Real-Mode-Interrupt n aus: Kopiert die Eingaberegister aus in und s in die globale Real-Mode-Call-Struktur
 *   d_1bd68c, ruft int386x(0x31, ...) auf und schreibt die geänderten Registerwerte anschließend nach out und s
 *   zurück.
 * - Eingaben:
 *   - n (Nummer des zu simulierenden Real-Mode-Interrupts).
 *   - in (Zeiger auf die Eingangsregister union REGS).
 *   - out (Zeiger auf die Ausgangsregister union REGS).
 *   - s (Zeiger auf die Segmentregister struct SREGS).
 * - Rückgabewert: int - Rückgabewert von int386x.
 * - Wichtige Variablen:
 *   - d_1bd68c (Globale 50-Byte-DPMI-Real-Mode-Registerstruktur).
 === Ende Beschreibung === */
int f_05fc00(int n, union REGS *in, union REGS *out, struct SREGS *s)
{
    d_1bd68c.edi = in->w.di;
    d_1bd68c.esi = in->w.si;
    d_1bd68c.ebx = in->w.bx;
    d_1bd68c.edx = in->w.dx;
    d_1bd68c.ecx = in->w.cx;
    d_1bd68c.eax = in->w.ax;
    d_1bd68c.es = s->es;
    d_1bd68c.ds = s->ds;
    in->w.ax = 0x300;
    in->h.bh = 0;
    in->w.cx = 0;
    in->h.bl = n;
    in->x.edi = (unsigned)&d_1bd68c;
    s->es = FP_SEG(&d_1bd68c);
    s->ds = FP_SEG(&d_1bd68c);
    int rc = int386x(0x31, in, out, s);
    out->w.di = d_1bd68c.edi;
    out->w.si = d_1bd68c.esi;
    out->w.bx = d_1bd68c.ebx;
    out->w.dx = d_1bd68c.edx;
    out->w.cx = d_1bd68c.ecx;
    out->w.ax = d_1bd68c.eax;
    s->es = d_1bd68c.es;
    s->ds = d_1bd68c.ds;
    return rc;
}

//@ f_05fd00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft über die DPMI-Funktion 0x0100 (Allocate DOS Memory Block mit Testgröße 0xe100
 *   Paragraphen = 900 KB), wie viel zusammenhängender DOS-Konventionalspeicher verfügbar ist, gibt die
 *   verfügbare Byteanzahl (r.w.bx << 4) zurück und löst bei zerstörten DOS-Speichersteuerblöcken (ax == 7) über
 *   f_051870 einen Guru-Meditation-Abbruch aus.
 * - Eingaben: Keine.
 * - Rückgabewert: int - Größe des größten freien DOS-Speicherblocks in Bytes (oder 0 bei unbekanntem Fehler).
 * - Wichtige Variablen:
 *   - r (Registerstruktur für den DPMI-Aufruf 0x0100).
 === Ende Beschreibung === */
int f_05fd00()
{
    union REGS r;
    int res;
    r.x.eax = 0x100;
    r.x.ebx = 0xe100;
    int386(0x31, &r, &r);
    if (r.x.cflag != 0) {
        if (r.w.ax == 8) res = r.w.bx << 4;
        else {
            if (r.w.ax == 7) f_051870(d_1b6f1c, 0);
            res = 0;
        }
    } else res = 0xe1000;
    return res;
}

struct Mem { unsigned short sel; unsigned seg; unsigned lin; };
struct DosMem { unsigned short size; Mem m; };

//@ f_05fd70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Reserviert über DPMI 0x0100 einen mindestens 0x400 Bytes großen, auf 16-Byte-Paragraphen
 *   aufgerundeten Block im unteren DOS-Speicher (size + 8 Bytes), trägt am Blockanfang die Wächterkennung "GUYS"
 *   (0x53595547) und am Blockende "GUYE" (0x45595547) ein und speichert Selektor, Real-Mode-Segmentadresse (+4)
 *   sowie lineare Adresse (+4) in der Struktur m.
 * - Eingaben:
 *   - size (Gewünschte Nutzdatengröße in Bytes).
 *   - m (Ausgabezeiger auf die Mem-Struktur für Selektor, Segment und lineare Adresse).
 *   - sz (Ausgabezeiger auf die tatsächlich reservierte Blockgröße in Bytes).
 * - Rückgabewert: int - 1 bei erfolgreicher Reservierung, 0 bei Fehlschlag.
 * - Wichtige Variablen:
 *   - v (Mit 8 Wächterbytes erweiterte und auf mindestens 0x400 angehobene Größe).
 *   - lin (Lineare Adresse des DOS-Speicherblocks).
 === Ende Beschreibung === */
int f_05fd70(unsigned size, Mem *m, unsigned short *sz)
{
    int ok = 0;
    union REGS r;
    unsigned short v = size + 8;
    if (v < 0x400) v = 0x400;
    *sz = ((v + 15) >> 4) << 4;
    m->sel = 0;
    m->seg = 0;
    m->lin = 0;
    r.x.eax = 0x100;
    r.x.ebx = *sz >> 4;
    int386(0x31, &r, &r);
    if (r.x.cflag == 0) {
        m->sel = r.w.dx;
        m->seg = r.w.ax << 16;
        unsigned lin = r.w.ax << 4;
        m->lin = lin;
        *(unsigned *)lin = 0x53595547;
        lin = lin + *sz;
        lin = lin - 4;
        *(unsigned *)lin = 0x45595547;
        m->seg = m->seg + 4;
        m->lin = m->lin + 4;
        ok = 1;
    } else {
        *sz = 0;
    }
    return ok;
}

//@ f_05fe40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt einen zuvor reservierten DOS-Speicherblock anhand seines DPMI-Selektors sel über die
 *   DPMI-Funktion 0x0101 (Free DOS Memory Block) wieder frei.
 * - Eingaben:
 *   - sel (DPMI-Selektor des freizugebenden DOS-Speicherblocks; bei 0 passiert nichts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r (Registerstruktur für den DPMI-Aufruf 0x0101).
 === Ende Beschreibung === */
void f_05fe40(unsigned short sel)
{
    union REGS r;
    if (sel != 0) {
        r.x.eax = 0x101;
        r.x.edx = sel;
        int386(0x31, &r, &r);
    }
}

//@ f_05fe80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor der DosMem-Hüllklasse: Reserviert über f_05fd70 einen DOS-Speicherblock der
 *   Größe n und speichert dessen Deskriptor und Größe im Objekt m.
 * - Eingaben:
 *   - m (Zeiger auf das zu initialisierende DosMem-Objekt).
 *   - n (Gewünschte Größe in Bytes).
 * - Rückgabewert: DosMem * - Der initialisierte Objektzeiger m.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
DosMem *f_05fe80(DosMem *m, unsigned short n)
{
    f_05fd70(n, &m->m, &m->size);
    return m;
}

//@ f_05fea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor der DosMem-Hüllklasse: Gibt den im Objekt m gespeicherten DOS-Speicherblock
 *   (sofern m->m.sel != 0) über die DPMI-Funktion 0x0101 frei.
 * - Eingaben:
 *   - m (Zeiger auf das DosMem-Objekt).
 *   - z (Destruktor-Steuerflags von Watcom C++).
 * - Rückgabewert: DosMem * - Der Objektzeiger m.
 * - Wichtige Variablen:
 *   - sel (Gespeicherter DPMI-Selektor m->m.sel).
 === Ende Beschreibung === */
DosMem *f_05fea0(DosMem *m, int z)
{
    union REGS r;
    unsigned short sel = m->m.sel;
    if (sel != 0) {
        r.x.eax = 0x101;
        r.x.edx = sel;
        int386(0x31, &r, &r);
    }
    return m;
}

unsigned f_05fee0(DosMem *m) { return m->m.seg; }
unsigned f_05fef0(DosMem *m) { return m->m.lin; }

//@ f_05ff00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert n Bytes aus dem Protected-Mode-Puffer src in den unteren DOS-Speicherblock m
 *   (m->m.lin).
 * - Eingaben:
 *   - m (Zeiger auf das Ziel-DosMem-Objekt).
 *   - src (Quellpuffer im regulären Speicher).
 *   - n (Anzahl der zu kopierenden Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_05ff00(DosMem *m, void *src, unsigned short n)
{
    memcpy((void *)m->m.lin, src, n);
}

//@ f_05ff30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert n Bytes aus dem unteren DOS-Speicherblock m (m->m.lin) in den
 *   Protected-Mode-Zielpuffer dst.
 * - Eingaben:
 *   - m (Zeiger auf das Quell-DosMem-Objekt).
 *   - dst (Zielpuffer im regulären Speicher).
 *   - n (Anzahl der zu kopierenden Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_05ff30(DosMem *m, void *dst, unsigned short n)
{
    memcpy(dst, (void *)m->m.lin, n);
}
