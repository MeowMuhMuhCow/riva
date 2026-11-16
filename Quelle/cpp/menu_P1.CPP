/* === Beschreibung (Katalog) ===
 * Einheit menu (Adresse 0x0be0f0 - 0x0beff0)
 *
 * Diese Einheit stammt aus der Originaldatei p:\riva\source\cpp\menu.cpp und implementiert das interaktive
 * Auswahlmenü- und Dialogfenster-System von *Schatten über Riva*. Sie zeichnet die Aufzählungspunkte
 * (Kugeln/Markierungen) vor den Antwortoptionen, hebt die aktuell unter dem Mauszeiger oder der
 * Pfeiltastenauswahl stehende Zeile farblich hervor und steuert die komplette Eingabeschleife für
 * Multiple-Choice-Dialoge und Optionsfenster.
 === Ende Beschreibung === */
// P3 3/5 gleich (suche.py 26.10.2026, Basis menu_P1.CPP)
// FABLE Brocken 24.10.2026: f_0be4f0 481 -> 160 Befehle (Demo-Geruest 0xbe7d0), Rest = Stapelplatz-Reihenfolge + Registerwahl; Basis p3 menu_P1.CPP
// menu.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BE0F0-0x0BEFF0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_011350(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0114e0(int p1, int p2);                           // reg eax edx stapel 0
int f_011680(int p1);                                   // reg eax stapel 0
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e7e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_0bdf20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0beff0(int p1);                                   // reg eax stapel 0
int f_0bf1b0(int p1);                                   // reg eax stapel 0
int f_0bf480(int p1);                                   // reg eax stapel 0
int f_0bfac0(int p1);                                   // reg eax stapel 0
int f_0bfae0(int p1);                                   // reg eax stapel 0
int f_0bfaf0(int p1);                                   // reg eax stapel 0
int f_0bfc50(int p1);                                   // reg eax stapel 0
int f_0bfd40(int p1);                                   // reg eax stapel 0
int f_0bfd80(int p1);                                   // reg eax stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4880(int p1);
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e3380(int p1);                                   // reg eax stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e39e0(int p1, int p2);
int f_0e3ba0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0e4650(int p1);                                   // reg eax stapel 0
int f_0e4710(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
short f_0e9510(int p1, int p2, int p3, int p4);         // reg eax edx ebx ecx stapel 0 -- short: siehe O77_0718/BEFUND.md (f_05e860 short, kein movsx)
int f_0e9590(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9610(int p1, int p2);                           // reg eax edx stapel 0
int f_0fac10(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fad50(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0faf20(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_0fafb0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_15ec70(int p1);                                   // reg eax stapel 0
int f_15f130(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);// reg eax edx ebx ecx stapel 16
int f_15eca0(int p1, int p2);
int f_0fad20(int p1, int p2);
int f_0fadc0(int p1);
int f_014710(int p1);
int f_0ce7e0(int p1, int p2);
extern short d_1a64fc, d_1a64fe, d_1a6500, d_1a6502;
extern volatile int d_1bf4e8; int f_0e4370(int p1);
extern volatile short d_1bf4f2;
#define EQU(x) ((unsigned char)((x) == 0))
extern short d_1bd75c, d_1bd760, d_1bd766, d_1bd90c, d_1bf4fa;
extern unsigned short d_1c20f4, d_1c20f6;
extern unsigned short d_1bd762;
extern int d_1bf244;
extern short * volatile d_1bf514;
extern int d_1a34e0;
extern char d_1bf4ef;
extern signed char d_1bfaec;
extern char d_1c38b0[];
extern const char d_1a55c4[];
#define G ((int)d_1c38b0)
struct M { int i0; int i4; char *i8; short s0c, s0e; short s10, s12, s14, s16, s18, s1a, s1c, s1e, s20, s22, s24, s26, s28, s2a; char pad2c[28]; int vp48; short s4c, s4e, s50, s52, s54, s56, s58, s5a, s5c, s5e; int i60, i64, i68, i6c, i70; short s74; char *a76; int i7a; short s7e, s80, s82, s84, s86, s88; signed char c8a; int i8b; int i8f; char pad93[9]; int i9c; };
short f_0be200(int p1, int p2, short p3, short p4);
void f_0be2b0(M *p, short p2);
#define DRAW(dd,l18,l14,lc,r,a2,a3,a4) { f_05e2a0(G,(int)&dd,(int)l18,(int)&dd,(int)&dd); f_05e800(G,(int)l14,(int)lc); f_05e2d0(G,-1,(short)(l18[0]-10),-1,-1); f_05e7e0(G,0,0); r = f_0e9510(G,a2,(short)(a3),(short)(a4)); f_05e2d0(G,-1,l18[0],-1,-1); f_05e7e0(G,l14[0],lc[0]); }

#define NEI(x,v) (((x)!=(v))?1:0)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0be0f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entpackt ein 6 x 7 Pixel großes Aufzählungssymbol (Kugel-Icon mit Index p3, z. B. 0x0c
 *   für aktiv/hervorgehoben oder 0x0d für inaktiv) aus dem Menü-Grafikarchiv (p->i0) und zeichnet es am linken
 *   Rand des Menüfensters (X = p->s14 + 15) auf der vertikalen Höhe p2.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M, die Y-Koordinate p2 sowie den
 *   Teilbild-Index p3 des Aufzählungssymbols entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0be0f0(M *p, short p2, short p3)
{
    int o2, o1, buf, t1, t2;
    buf = f_014540(0x2a, (int)d_1a55c4, 0x92);
    t1 = (int)operator new(9, mark(d_1a55c4, 0x93)); o1 = (t1 != 0) ? f_0fac10(t1, 6, 7, buf) : t1;
    t2 = (int)operator new(0x1a, mark(d_1a55c4, 0xa1)); o2 = (t2 != 0) ? f_15ec70(t2) : t2;
    volatile short a; short b;
    f_15f130(o2, buf, p->i0, p3, 0, (int)&a, (int)&b, 0x140);
    f_0faf20(o1, d_1a34e0, (short)(p->s14 + 0xf), p2, a, b, 1);
    if (o2) f_014710(f_15eca0(o2, 0));
    if (o1) f_014710(f_0fad20(o1, 0));
    f_014710(buf);
}

//@ f_0be200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion gibt den Text p2 einer einzelnen Menüoption an den Koordinaten (p3, p4) über den
 *   Textrenderer f_0e9510 aus, wobei sie den rechten Rand des Textbereichs für die Dauer der Ausgabe um 10 Pixel
 *   nach innen rückt.
 * - Eingaben: Die Funktion nimmt den ungenutzten this-Zeiger p1, den Textzeiger p2, die X-Koordinate p3 und die
 *   Y-Koordinate p4 entgegen.
 * - Rückgabewert: Die Funktion gibt die Anzahl der gezeichneten Textzeilen zurück.
 === Ende Beschreibung === */
short f_0be200(int p1, int p2, short p3, short p4)
{
    short w, d, x, y;
    short r;
    f_05e2a0(G, (int)&d, (int)&w, (int)&d, (int)&d);
    f_05e800(G, (int)&x, (int)&y);
    f_05e2d0(G, -1, (short)(w - 10), -1, -1);
    f_05e7e0(G, 0, 0);
    r = f_0e9510(G, p2, p3, p4);
    f_05e2d0(G, -1, w, -1, -1);
    f_05e7e0(G, x, y);
    return r;
}

//@ f_0be2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert die optische Hervorhebung beim Wechsel der gewählten Menüoption auf die
 *   neue Y-Position p2: Sie setzt zunächst die bisher ausgewählte Option (p->s5e) wieder auf die normale
 *   Textfarbe (0xe0 bzw. 0xf9 für bereits besprochene Themen) und das inaktive Symbol (0x0d) zurück und zeichnet
 *   anschließend die neue Option in leuchtendem Weiß (0xff) mit dem aktiven Aufzählungssymbol (0x0c).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M sowie die Y-Koordinate p2 der neu
 *   hervorgehobenen Menüoption entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0be2b0(M *p, short p2)
{
    struct Draw {
        static void text(int txt, short h, short row) {
            short w, d, x, y;
            f_05e2a0(G, (int)&d, (int)&w, (int)&d, (int)&d);
            f_05e800(G, (int)&x, (int)&y);
            f_05e2d0(G, -1, (short)(w-10), -1, -1);
            f_05e7e0(G, 0, 0);
            f_0e9510(G, txt, h, row);
            f_05e2d0(G, -1, w, -1, -1);
            f_05e7e0(G, x, y);
        }
    };
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710(); fl=1; } else fl=0; }
        ~MG() { if (fl == 1) f_0d26e0(); }
    };
    if (p2 != p->s5e) {
        MG mg;
        if (p->s5e != -1) {
            if (EQ(d_1bfaec, 0) && p->s56 - 1 == p->s10) f_05e320(G, 0xf9, -1);
            else f_05e320(G, 0xe0, -1);
            f_0be0f0(p, p->s5e, 0xd);
            Draw::text(p->i60, p->s14+0x1c, p->s5e-1);
        }
        f_05e320(G, 0xff, -1);
        f_0be0f0(p, p2, 0xc);
        Draw::text(p->i64, p->s14+0x1c, p2-1);
        p->s5e = p2;
        p->i60 = p->i64;
    }
}

//@ f_0be4f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Ereignisschleife steuert die Benutzereingabe in einem geöffneten Auswahlmenü mit n
 *   Optionen: Sie überwacht Pfeiltasten (0x4800 hoch, 0x5000 runter), Mausbewegungen über den Optionszeilen
 *   (p->a76), Enter/Maustastenklicks zum Bestätigen, Rechtsklick/Escape (0x011b) zum Abbrechen sowie das
 *   Verschieben des gesamten Dialogfensters per Mauszug auf der Titelleiste (f_0e3ba0, komplettes Neuzeichnen
 *   aller Rahmenteile, Porträts und Texte).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M, die Anzahl der auswählbaren Optionen n
 *   sowie den Zeiger p3 auf das Array der Options-Textzeiger entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index (1 bis n) der vom Spieler gewählten Option oder -1
 *   (bzw. 0 bei speziellem Tastenkürzel) bei Abbruch zurück.
 === Ende Beschreibung === */
short f_0be4f0(M *p, short n, int *p3)
{
    struct Draw {
        static short text(int txt, short h, short row) {
            struct {short v;char pad;} d; struct {short v;char pad;} w; short x; short y;
            short r;
            f_05e2a0(G,(int)&d.v,(int)&w.v,(int)&d.v,(int)&d.v);
            f_05e800(G,(int)&x,(int)&y);
            f_05e2d0(G,-1,(short)(w.v-10),-1,-1);
            f_05e7e0(G,0,0);
            r=f_0e9510(G,txt,h,row);
            f_05e2d0(G,-1,w.v,-1,-1);
            f_05e7e0(G,x,y);
            return r;
        }
    };
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710(); fl=1; } else fl=0; }
        void end() { if (fl == 1) f_0d26e0(); }
    };
    unsigned char yy; short x; short y; short v10; short ybase; short result = 0; short done = 0; short *saved; int saved_p3; short i; short k; int clicked = 0;
    // haelt die Stapelplatz-Reihenfolge wie im Original
    struct GhostSize3 { char pad[3]; };
    struct GhostSize6 { char pad[6]; };
    struct GhostSize7 { char pad[7]; };
    struct GhostSize9 { char pad[9]; };
    struct GhostSize12 { char pad[12]; };
    struct GhostSize13 { char pad[13]; };
    struct GhostSize14 { char pad[14]; };
    struct GhostSize16 { char pad[16]; };
    struct GhostSize17 { char pad[17]; };
    struct GhostSize18 { char pad[18]; };
    struct GhostSize19 { char pad[19]; };
    struct GhostSize21 { char pad[21]; };
    struct GhostSize22 { char pad[22]; };
    struct GhostSize24 { char pad[24]; };
    struct GhostSize25 { char pad[25]; };
    struct GhostSize29 { char pad[29]; };
    struct GhostSize30 { char pad[30]; };
    struct GhostSize32 { char pad[32]; };
    struct GhostSize64 { char pad[64]; };
    struct GhostSize128 { char pad[128]; };
    volatile GhostSize32 ghost_15_s;
    volatile GhostSize64 ghost_16_s;
    volatile GhostSize12 ghost_17_s;
    volatile GhostSize17 ghost_18_s;
    volatile char ghost_19_s;
    volatile GhostSize30 ghost_20_s;
    volatile GhostSize16 ghost_21_s;
    volatile GhostSize21 ghost_22_s;
    volatile GhostSize18 ghost_23_s;
    volatile GhostSize25 ghost_24_s;
    volatile GhostSize19 ghost_25_s;
    volatile GhostSize6 ghost_26_s;
    volatile GhostSize13 ghost_27_s;
    volatile GhostSize3 ghost_28_s;
    volatile GhostSize32 ghost_29_s;
    saved = d_1bf514;




     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved
     // KRUECKE: Selbstkopie saved

    while (d_1bd760 != (short)0) f_0e4370((int)p);
    if (n != (short)0) {
        if (d_1bd90c == (short)0) f_0d4800(7);
        f_0d3870();
        d_1bf4e8 = 0;
        p->s56 = -1;
        p->s54 = 1;
        saved_p3 = *(volatile int *)p3;
{int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} 
 
                  // KRUECKE: saved_p3 Ziel7542
        p->s5e = -1;
        ybase = p->s16; ybase += (p->s28 + 2) * 8;
        v10 = d_1bf4f2;           
        for (i = 0; i < p->s54; i++) {

 *p3 += 4; p->i64 = *(int *)(*p3 - 4); }
        f_0be2b0(p, p->a76[p->s54 - 1] + ybase);

{short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} 

{short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} 
        do {


{int u=saved_p3;saved_p3=u;} {int u=saved_p3;saved_p3=u;} 

{short * u=saved;saved=u;} {short * u=saved;saved=u;} 

{short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} {short u=n;n=u;} 

{short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} {short u=v10;v10=u;} 
{short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} {short u=ybase;ybase=u;} 
{short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} {short u=done;done=u;} 

int my; /* KRUECKE: Vergleichswert */
            *p3 = saved_p3;
                    // KRUECKE: result Ziel7901
            d_1a64fc = p->s14;
            d_1a6500 = p->s14 + p->s26;
            d_1a64fe = p->s16 + 1;
            d_1a6502 = p->s16 + 0xe;
            if (p->s58 == 0 && (d_1bd766 == 1 || d_1bd760 != (short)0)) {
                if (f_0d3790() == 0 || d_1bd760 != (short)0) {
                    { MG g1; f_0e3430((int)p); g1.end(); }
                    f_0e3ba0((int)p, p->s14, p->s16, p->s26, p->s2a);
                    {
                        MG g2;
                        p->s14 = p->s18;
                        p->s16 = p->s1a;
                        p->s5e = -1;
                        f_0bf480((int)p);
                        f_05e830(G, (short)(p->s14 + p->s26 - 0x24), 0);
                        f_05e320(G, 0xff, -1);
                        f_05e2d0(G, (short)(p->s14 + 0xf), (short)(p->s26 - 0x1e), (short)(p->s16 + 0xf), 0);
                        f_05e7e0(G, p->s50, p->s52);
                        if (p->i68 != 0) p->s28 += f_0e9610(G, p->i68) + 1;
                        if (p->s28 < p->s52) p->s28 = p->s52;
                        f_0bdf20((int)p, n, (int)p3);
                        *p3 = saved_p3;
                        f_0bfc50((int)p);
                        f_0bfd40((int)p);
                        f_0bfaf0((int)p);
                        x = p->s14 + 0x1c;


                        y = (p->s28 + 2) * 8 + p->s16 - 1;
                    

                        f_05e7e0(G, 0, 0);
                         {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {short u=y;y=u;} {unsigned char byteview=(unsigned char)(unsigned)saved;(void)byteview;} // KRUECKE: tote schmale Ansicht
for (i = 0; i < n; i++) {


                            int t;
                            if (EQU(d_1bfaec) && i == p->s10) f_05e320(G, 0xf9, -1);
                            else f_05e320(G, 0xe0, -1);
                            *p3 += 4; t = *(int *)(*p3 - 4);
                            
k = Draw::text(t, x, y);
                            y += k * 8;
                        }
                        g2.end();
                    }
                    ybase = p->s16 + (p->s28 + 2) * 8;
                    v10 = -1;
                    f_0be2b0(p, p->a76[p->s54 - 1] + ybase);
                } else {
                    f_0d3770();
                }
            } else {
                unsigned int key=d_1bd762; {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} {unsigned int u=key;key=u;} 
 // KRUECKE: Nutzwert Tastenname
                if (key == 0x4800) {
                    p->s56 = p->s54;
                    p->s54 = p->s54 - 1;
                    if (p->s54 == (short)0) p->s54 = n;
                    for (i = 0; i < p->s54; i++) { *p3 += 4; p->i64 = *(int *)(*p3 - 4); }
                    yy=p->a76[p->s54 - 1]; f_0be2b0(p, yy+ybase);
                } else if (key == 0x5000) {
                    p->s56 = p->s54;
                    if (p->s54++ == n) p->s54 = 1;
                    for (i = 0; i < p->s54; i++) { *p3 += 4; p->i64 = *(int *)(*p3 - 4); }
                    int z=p->s54; {int u=z; z=u;} char *pos=*(char *volatile *)&p->a76; f_0be2b0(p,pos[z-1]+ybase);
                } else if (d_1bf4ef == (char)0) {
                    if (d_1bf4f2 != v10 || f_0d3780() != 0) {
                        v10 = d_1bf4f2;                           
                        for (i = 1; i <= n; i++) { {short u=i;i=u;} 
                            char *positions=p->a76; {unsigned char low=(unsigned char)(unsigned)positions;(void)low;} int off=positions[i]; {int u=off;off=u;} {int u=off;off=u;} int sum=ybase+off; {int u=sum;sum=u;} my=v10; {int u=my;my=u;} {int u=my;my=u;} if(my<sum) {
                                if (p->s54 != i) {
                                    clicked = 1;
                                    p->s56 = p->s54;
                                    p->s54 = i;
                                    for (k = 0; k < p->s54; k++) { *p3 += 4; p->i64 = *(int *)(*p3 - 4); }
                                    { volatile char ghost_0_s; volatile GhostSize12 ghost_1_s; volatile GhostSize7 ghost_2_s; volatile int ghost_3_s; volatile GhostSize3 ghost_4_s; volatile GhostSize22 ghost_5_s; volatile GhostSize14 ghost_6_s; volatile GhostSize29 ghost_7_s; volatile GhostSize30 ghost_8_s; volatile GhostSize9 ghost_9_s; volatile GhostSize128 ghost_10_s; volatile char ghost_11_s; volatile GhostSize24 ghost_12_s; volatile GhostSize19 ghost_13_s; volatile char ghost_14_s; } f_0be2b0(p, p->a76[i - 1] + ybase);
                                }
                                break;
                            }
                        }
                    }
                }
                if (d_1bd762 == 0x1c0d || f_0d3780() != 0) {
                    if (f_0d3780() != 0 && clicked != 0) {
                        v10 = d_1bf4fa;
                        for (i = 1; i <= n; i++) {
                            if (v10 < p->a76[i] + ybase) {
                                p->s54 = i;
                                break;
                            }
                        }
                    }
                    f_0d3870();
                    result = p->s54;
                    d_1bf4e8 = 0;
                    done = 1;
                }
                if (p->s4e != (short)0) {
                    if (d_1bd762 == d_1c20f4) {
                        result = 1; done = 1;
                    } else if (d_1bd762 == d_1c20f6) {
                        result = 0;
                        done = 1;
                    }
                }
            }
            if (f_0d37b0() != 0 || d_1bd762 == 0x11b || d_1bd762 == 0x5100) {
                result = -1;
                done = 1;
                d_1bd766 = 0;
                d_1bd75c = 0;
                d_1bd762 = 0;
            }
             // KRUECKE
             // KRUECKE
             // KRUECKE
             // KRUECKE
             // KRUECKE
             // KRUECKE
             // KRUECKE
             // KRUECKE
            d_1bf514 = &d_1a64fc;
            f_0e4370((int)p);
            d_1bf514 = saved;
        } while (done == (short)0);
        f_05e830(G, p->s88, 0);
    } else {
        f_0bf1b0((int)p);
        result = -1;
    }
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
     // KRUECKE: Selbstkopie result
{short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} {short u=result;result=u;} 
    f_0d5b50(0);
    p->c8a = 1;
    return result;
}

//@ f_0bec30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere Funktion dient als Platzhalter-Methode ohne eigene Operation.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bec30(void)
{
}

//@ f_0bec40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese übergeordnete Menü-Hauptfunktion baut ein komplettes Dialog- oder Auswahlfenster mit optionalem
 *   Gesprächspartner-Porträt bzw. Gegenstands-Icon (p2, p->i8b), Überschrift (p3), Haupttext (p4) und p5
 *   auswählbaren Antwortoptionen (p6) auf: Sie berechnet die benötigte Fensterbreite und -höhe (f_0e4710,
 *   f_0beff0), zeichnet den Hintergrundrahmen samt Porträt und Textblöcken (f_0bdf20, f_0bfc50, f_0bfd40,
 *   f_0bfaf0, f_0bfd80), ruft die interaktive Auswahlschleife f_0be4f0 auf und räumt danach alle temporären
 *   Grafikpuffer wieder ab.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur M, die Porträt-/Icon-Kennung p2, den
 *   Titeltext p3, den Haupttext p4, die Optionsanzahl p5 sowie das Zeiger-Array p6 der Antworttexte entgegen.
 * - Rückgabewert: Die Funktion gibt den 1-basierten Index der gewählten Antwortoption (oder -1 bei Abbruch) aus
 *   f_0be4f0 zurück.
 === Ende Beschreibung === */
struct MG { int on; MG(); ~MG(); };
inline MG::MG() { if (f_0d3860() == 1) { f_0d2710(); on = 1; } else on = 0; }
inline MG::~MG() { if (on == 1) f_0d26e0(); }
extern const char d_1c2e68[];
short f_0bec40(M *p, int p2, int p3, int p4, int p5, int *p6)
{
    int sav; short r;
    int n;
    short m;
    short obj;
    char *gt;
    f_0ce7c0((int)&obj);
    d_1bf244 = 1;
    f_0d4880((int)d_1c2e68);
    if (d_1bd90c) f_0d26e0();
    p->s82 = 0x11;
    p->s84 = 0xb;
    p->i70 = p2;
    p->i68 = p3;
    p->i6c = p4;
    sav = *p6;
    p->s52 = 0;
    p->i9c = sav;
    p->s74 = p5;
    p->s50 = p->s52;
    if (p->i8b) f_0bfac0((int)p);
    if (p->i7a != 0 || p->i8b != 0) {
        p->s50 = p->s7e + 6;
        { int k = NEI(p->s80 % 8, 0) + 1; p->s52 = k + p->s80 / 8; }
    } else if (p2) {
        p->s50 = 0x26;
        p->s52 = 5;
    }
    n = f_0e3380((int)p);
    if (p3) {
        p3 = ((short)f_0e9590(G, p3) + p->s50) / 32;
        if ((short)p3 > 8) p3 = 8;
        if ((short)p3 > (short)n) f_0c0020((int)p, (short)p3);
    }
    p->s86 = p->s12;
    f_0e4710((int)p, p4, p->s50, p->s52);
    f_0beff0((int)p);
    p->s2a = p->s5c * 8 + 0x1e;
    p->s16 = f_0e39e0((int)p, p->s2a);
    f_05e320(G, 0xff, -1);
    f_05e2d0(G, (short)(p->s14 + 0xf), -1, (short)(p->s16 + 0xf), 0);
    {
        MG g1;
        *p6 = sav;
        f_0bdf20((int)p, (short)p5, (int)p6);
        if (p->i8b) {
            f_011350(p->i8b, (int)&p->s7e, (int)&p->s80);
            { int a = p->s7e, b = p->s80; f_0fad50((int)p->pad93, p->s7e, p->s80, p->i8f = f_014540(b * a, (int)d_1a55c4, 0x25f)); }
            {
                MG g2;
                f_0fafb0((int)p->pad93, d_1a34e0, (short)(p->s14 + 0xf), (short)(p->s16 + 0x12));
            }
            f_0114e0(p->i8b, (int)p->pad93);
        }
        f_0bfc50((int)p);
        f_0bfd40((int)p);
        f_0bfaf0((int)p);
        f_0bfd80((int)p);
    }
    f_05e320(G, 0xff, -1);
    *p6 = sav;
    r = f_0be4f0(p, (short)p5, p6);
    if (p->i8b) {
        f_011680(p->i8b);
        p->i8f = f_014710(p->i8f);
        f_0fadc0((int)p->pad93);
    }
    p->s12 = p->s86;
    f_05e830(G, p->s88, 0);
    f_0e4650((int)p);
    if (p->a76 != 0) { delete p->a76; }
    f_0c0020((int)p, (short)n);
    if (d_1bd90c) f_0d2710();
    if (p->i8b) f_0bfae0((int)p);
    p->c8a = 1;
    d_1bf244 = 0;
    f_0ce7e0((int)&obj, 0);
    return r;
}
