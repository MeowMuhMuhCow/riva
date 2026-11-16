/* === Beschreibung (Katalog) ===
 * Einheit diskmenu_t1 (0x05b820 - 0x05d0d0)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil von diskmenu.cpp und enthält die interaktive Hauptschleife des
 * Laden-/Speichern-Menüs (f_05b860) sowie das Einlesen und zeitliche Sortieren der vorhandenen .GAM-Spielstände
 * im Verzeichnis ..\GAMES\.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
// P3 2/4 gleich (suche.py 25.10.2026, Basis diskmenu_t1_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 1 gleich (vorher 1), Rest 1188 (vorher 1213)
// diskmenu.cpp (Schatten ueber Riva, Attic 1996) - Pass 1 Teil 1, Code 0x05B860-0x05D0D0
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Menu {
    char p0[4];
    int f4;
    char p8[4];
    void *f0c;
    char p10[0x10];
    short s20;
    short cur;
    short sel;
    short top;
    char p28[2];
    char buf[0x100];
    char names[100][13];
    char s63e[14];
    void *f64c;
    short f650;
};
struct Ent { char name[9]; unsigned short tm; unsigned short dt; };
struct FT { char r[21]; char attrib; unsigned short wr_time; unsigned short wr_date; unsigned long size; char name[13]; };
struct Tg { int a; int f4; };
struct EdC { ~EdC(); char x[0x45]; };                    // Eingabefeld (editor2 Ed), dtor 0x061CD0 - delete wie Original: test eax / dtor / operator delete
struct ImC { ~ImC(); char x[9]; };                       // Bild (T9/Img), dtor 0x0FAD20
struct O180 { char p[0x10]; Tg *p10; char r[0x28]; };
struct R9 { char x[9]; };
struct S45 { char x[0x45]; };
extern char d_1b6edc[], d_1a17b4[], d_1a17d4[], d_1b6ee1[], d_1b6ee7[], d_1b6eec[], d_1b6ef1[], d_1b6ef7[], d_1b6ef9[];
extern char d_1c2bcc[], d_1c2be0[], d_1c2c64[], d_1c299c[], d_1c21b4[], d_1c27a8[], d_1c3498[], d_1c349c[], d_1c3870[], d_1c38b0[];
extern char *d_1a9678;
extern int d_1a34e0, d_1c0004, d_1bcad0, d_1c0c4c, d_1bfdb8;
extern volatile int d_1c0c94, d_1bf510, d_1bf514; // volatile: Stores nicht umsortiert (Init/Epilog), wie Original
extern int d_1c2a80; // nicht volatile: LOADSEQ-Schluss mit 1 im Register wie Original
extern short d_1bd760, d_1bd766, d_1c129a, d_1c2198, d_1c21a4;
extern volatile short d_1bf4fa;                       // volatile: Globalladung bleibt an Ort (K81), wie Original
extern unsigned short d_1bd762, d_1c20f8, d_1c20fa, d_1c20fc;
int f_068f40(); int f_0d5a90(); int f_0d3860(); int f_0d2710(); int f_0d26e0(); int f_0d3870(); int f_0d37b0();
int f_0d3800(); int f_0d37e0(); int f_0d34b0(int, int, int, int);
int f_0ce7c0(void *); int f_0ce7e0(void *, int);
int f_125400(void *, char *, char *, char *); int f_1254a0(void *, int);
int f_01eb40(char *); int f_01eb50(char *);
int f_0d2f90(int, int);
int f_050580(char *, int, void *, void *);
 
void *f_014540(unsigned, const char *, int);
int f_04feb0(char *, int, void *, int, int, int, void *, void *, int);
 
 
int f_09a540(Menu *, void *, int, int, int);
int f_05e360(char *, short *, short *); int f_05e320(char *, int, int); int f_05e420(char *, int);
void *f_061b10(void *, int, int, int, int, void *, int, int);
void *f_061cd0(void *, int); int f_0619e0(void *, char *); int f_060ae0(void *, char *, int);
void f_05d0d0(Menu *); int f_05d370(Menu *, int); short f_05d460(Menu *, int); int f_05d650(Menu *);
int f_05b340(Menu *, int); int f_05a5c0(Menu *, int, int); int f_05aed0(Menu *, int); int f_05dcd0(Menu *, int);
short f_05cf70(Menu *); int f_05cf20(char *, char *);
int f_0bf6f0(char *, int); int f_0bf730(char *, int); int f_0bfea0(char *, int, int); short f_0bf820(char *, int, ...);
int f_0cdd30(char *, int); int f_14d717(char *, char *); int f_133fe0(char *, char *); int f_144bf0(char *, char *);
int f_144570(); int f_148534(int); int f_0de800(int);
int f_1483f0(int, int, int, int, int);
int f_14572e(char *, char *, ...); int f_144fbf(char *, int, ...);
int f_144e8b(int, char *, int); int f_145279(int, int, int); int f_144cb6(int, char *, int); int f_145259(int);
int f_1492b4(char *, int, void *); int f_1492d1(void *); int f_1492ed(void *);
char *f_145318(char *, char *); int f_0d4850(char *, int, int);
void f_14d7dc(void *, int, int, int (*)(char *, char *));

#pragma aux f_133fe0 modify [esp]; // Aufrufer braucht EBP-Rahmen (sub ebp,0x82) wie im Original
#define TRIMEXT(a) { char *p_ = strchr(a, ' '); if (p_ != 0) *p_ = 0; else { p_ = strchr(a, '.'); if (p_ != 0) *p_ = 0; } }
#define LOADSEQ(m, names, IDX) { \
    sv8e = f_0de800(d_1c0004); (void)&sv8e; \
    ret = ((int (*)(Menu *))f_05aed0)(m); \
    strcpy(d_1c21b4, names[IDX]); \
    strcat(d_1c21b4, d_1b6ee7); \
    f_14572e(d_1c27a8, d_1a9678, d_1c21b4); \
    { int h_ = (short)f_144fbf(d_1c27a8, 2); \
      f_144e8b(h_, (char *)&fb8e, 1); f_145279(h_, 0, 0); f_144cb6(h_, (char *)&fb8e, 1); f_145259(h_); } \
    done = 1; \
    if ((short)f_0de800(d_1c0004) == (short)0 && (short)sv8e != (short)0) d_1c129a = f_0de800(d_1c0004); \
    d_1c2a80 = 0; d_1c2198 = 1; }
#define LOADSEQ87(m, names, IDX) { \
    sv87 = f_0de800(d_1c0004); (void)&sv87; \
    ret = ((int (*)(Menu *))f_05aed0)(m); \
    { int off_=(IDX)*13; {int u_=off_;off_=u_;} char *dst_=(char*)names+off_; {char *u_=dst_;dst_=u_;} strcpy(d_1c21b4,dst_); } \
    strcat(d_1c21b4, d_1b6ee7); \
    f_14572e(d_1c27a8, d_1a9678, d_1c21b4); \
    { int h_ = (short)f_144fbf(d_1c27a8, 2); \
      f_144e8b(h_, (char *)&fb87, 1); f_145279(h_, 0, 0); f_144cb6(h_, (char *)&fb87, 1); f_145259(h_); } \
    done = 1; \
    if ((short)f_0de800(d_1c0004) == (short)0 && (short)sv87 != (short)0) d_1c129a = f_0de800(d_1c0004); \
    d_1c2a80 = 0; d_1c2198 = 1; }
#define LOADSEQ_M(m, names, IDX) { \
    svM = f_0de800(d_1c0004); (void)&svM; \
    ret = ((int (*)(Menu *))f_05aed0)(m); \
    strcpy(d_1c21b4, names[IDX]); \
    strcat(d_1c21b4, d_1b6ee7); \
    {int rt_=d_1c2a80; d_1c2a80=rt_; f_14572e(d_1c27a8,d_1a9678,d_1c21b4);} \
    { int h_ = (short)f_144fbf(d_1c27a8, 2); \
      f_144e8b(h_, (char *)&fbM, 1); f_145279(h_, 0, 0); f_144cb6(h_, (char *)&fbM, 1); f_145259(h_); } \
    done = 1; \
    if ((short)f_0de800(d_1c0004) == (short)0 && (short)svM != (short)0) d_1c129a = f_0de800(d_1c0004); \
    d_1c2a80 = 0; d_1c2198 = 1; }

inline void drawlist(Menu *q)
{
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    short i, x;
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50);
    { void *ms(void *, int, unsigned);   // memset voll wie diskmenu_t2: fl bleibt im Speicher (cmp [fl],1 wie Original)
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(q->buf, 0, 0x100); }
    if (fl == 1) f_0d26e0();
}
inline void redraw(Menu *p)
{
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top));
    drawlist(p);
    f_05d460(p, (short)(p->cur + p->top));
    f_0619e0(p->f0c, p->buf);
}

inline void drawlist3(Menu *q)
{
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    short x, i;
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50);
    { void *ms(void *, int, unsigned);   // memset voll wie diskmenu_t2: fl bleibt im Speicher (cmp [fl],1 wie Original)
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(q->buf, 0, 0x100); }
    if (fl == 1) f_0d26e0();
}
inline void redraw3(Menu *p)
{
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top));
    drawlist3(p);
    f_05d460(p, (short)(p->cur + p->top));
    f_0619e0(p->f0c, p->buf);
}

inline void drawlist2(Menu *q)
{
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    short i, x;
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50);
    { void *ms(void *, int, unsigned);   // memset voll wie diskmenu_t2: fl bleibt im Speicher (cmp [fl],1 wie Original)
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(q->buf, 0, 0x100); }
    if (fl == 1) f_0d26e0();
}
inline void redraw2(Menu *p)
{
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top));
    drawlist2(p);
    f_05d460(p, (short)(p->cur + p->top));
    f_0619e0(p->f0c, p->buf);
}
inline void drawlist4(Menu *q)
{
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    short i, x;
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50);
    { void *ms(void *, int, unsigned);   // memset voll wie diskmenu_t2: fl bleibt im Speicher (cmp [fl],1 wie Original)
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(q->buf, 0, 0x100); }
    if (fl == 1) f_0d26e0();
}
inline void redraw4(Menu *p)
{
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top));
    drawlist4(p);
    f_05d460(p, (short)(p->cur + p->top));
    f_0619e0(p->f0c, p->buf);
}

#define DRAWLIST0(q_) { Menu *q = q_; \
    if (f_0d3860() == 1) { f_0d2710(); flx = 1; } else flx = 0; \
    short x, i; \
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50); \
    memset(q->buf, 0, 0x100); \
    if (flx == 1) f_0d26e0(); }
#define REDRAW0(p_) { Menu *p = p_; \
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top)); \
    DRAWLIST0(p) \
    f_05d460(p, (short)(p->cur + p->top)); \
    f_0619e0(p->f0c, p->buf); }
int FindListCount493(Menu *);
#pragma aux FindListCount493 "f_05cf70";
inline void seek(Menu *q)
{
    q->f650 = FindListCount493(q);
    short i = 0;
    while (f_144bf0(q->names[i++], q->s63e) != 0) {
        q->cur = q->cur + 1;
        if (q->cur >= (short)10) {
            q->top++;
            int t = q->f650 - 10;
            q->cur = 9;
            if (t > 0 && q->top > t) q->top = q->f650 - 10;
        }
    }
}
inline void drawlist5(Menu *q)
{
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    short x, i;
    for (i = 0, x = 0x3a; i < 0x31; i++, x++) f_1483f0(d_1a34e0, 0x76, x, 0xa9, -50);
    { void *ms(void *, int, unsigned);   // memset voll wie diskmenu_t2: fl bleibt im Speicher (cmp [fl],1 wie Original)
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(q->buf, 0, 0x100); }
    if (fl == 1) f_0d26e0();
}
inline void redraw5(Menu *p)
{
    if (p->sel != -1) f_05d370(p, (short)(p->sel + p->top));
    drawlist5(p);
    f_05d460(p, (short)(p->cur + p->top));
    f_0619e0(p->f0c, p->buf);
}

//@ f_05b860  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt das grafische Spielstand-Menü (Laden, Speichern, Beschreibung bearbeiten, Löschen, Neuen
 *   Spielstand anlegen, Spiel beenden, Zurück) aus: lädt das Hintergrundbild aus dem Archiv 0x90004, legt das
 *   6-zeilige Texteditor-Feld (f_061b10) für die Spielstandbeschreibung an, liest und sortiert die .GAM-Dateien
 *   über f_05cf70 und verarbeitet in einer Schleife sämtliche Maus-, Tastatur- und Rechtsklick-Menüaktionen
 *   (0x81..0x8e), bis ein Spielstand geladen oder gespeichert wurde oder der Spieler das Menü verlässt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger m auf das Diskmenü-Objekt (Menu) sowie den
 *   Sperrschalter p2 (1 = Speichern und Neuanlegen sind in der aktuellen Spielsituation verboten, z. B. direkt
 *   nach dem Startmenü). Sie gibt das Ladeergebnis ret (1 nach dem Laden eines Spielstands, 0 sonst) zurück.
 * - Wichtige Variablen: In m verwalten m->names[100][13] die bis zu 100 Spielstandseinträge, m->f650 deren
 *   Anzahl, m->top die erste sichtbare Zeile, m->cur die Cursorzeile (0..9), m->sel den Eintrag mit aktuell
 *   geöffneter Beschreibung und m->f0c das Editor-Objekt für das Beschreibungsfeld.
 === Ende Beschreibung === */
int f_05b860(Menu *m, int p2)
{
    // Deklarationsfolge aus der Stapelsimulation bestimmt die Stapelplaetze
    short e;
    short fb87;
    short svM;
    short fb8e;
    unsigned short h;
    char s90[13];
    int old0;
    short y0;
    short sa;
    int old1;
    short sv8e;
    char s5c[20];
    short sv87;
    char path[52];
    int ret;
    int fl;
    (void)&fl; // fl im Speicher wie im Original (-0x12)
    short sb;
    char b[12];
    short done;
    O180 o;
    short fbM;
    unsigned short wa0;
    short o24;
    short wa1;
    short x0;
    short n;
    short i;
    int flx; // Erster Lebensbereich = r9, zweiter = Mausklammer im ersten Neuzeichnen
    n = 0; // Vorinitialisierung fuer die Registerfolge
    f_0ce7c0(&o24);
    done = 0;
    wa1 = 0;
    ret = 0;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    d_1c0c94 = 0;
    f_01eb40(d_1c2bcc);
    d_1bcad0 = 1;
    d_1c0c4c = d_1c0c4c + 1;
    f_0d2f90(0, 1);
    ((int (*)(char *, int, int, void *, void *))f_050580)(d_1c2be0, 0x90004, 0, &wa0, &h);
    ((void *)(((RivaRasterImage*)(b))->f_0fac80( (short)((wa0 + 8) & 0xfff8), (short)h)));
    char *pix = (char *)f_014540(wa0 * (unsigned short)h, d_1a17b4, 0x90);
    f_04feb0(d_1c2be0, 0x90004, pix, 0, 0, 0, &e, &e, 0x140);
    x0 = (0x140 - (short)wa0) >> 1;
    y0 = (200 - (short)h) >> 1;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    ((RivaRasterImage*)(b))->f_0fafb0((void *)( d_1a34e0), x0, y0);
    if (fl == 1) f_0d26e0();
    f_09a540(m, pix, ((int)(((RivaRasterImage*)(b))->f_0fb0b0())), (short)wa0, (short)h);
    operator delete(pix);
    f_05e360(d_1c38b0, &sa, &sb);
    f_05e320(d_1c38b0, 0xda, 0xce);
    flx = (int)new (mark(d_1a17b4, 0xa1)) R9;
    m->f64c = flx ? ((void *)(((RivaRasterImage*)((R9 *)flx))->f_0fac80( 0xa9, 8))) : (R9 *)flx;
    ((RivaRasterImage*)(m->f64c))->f_0fb150( 0xce);
    S45 *s45 = new (mark(d_1a17b4, 0xb1)) S45;
    m->f0c = s45 ? f_061b10(s45, 6, 0xa9, 0x76, 0x3a, m->f64c, 0, 0) : s45;
    m->s20 = f_05e420(d_1c38b0, -1);
    { void *ms(void *, int, unsigned);
    #pragma aux ms "memset" parm [eax] [edx] [ebx] modify exact [eax ebx ecx edx esi edi];
    ms(m->names, 0, 0x514); }
    old0 = d_1bf510; old1 = d_1bf514;
    d_1bf510 = (int)d_1a17d4;
    d_1bf514 = 0;
    m->f650 = FindListCount493(m);
    m->sel = -1;
    m->cur = 0;
    m->top = 0;
    f_05d0d0(m);
    REDRAW0(m)
    f_0d3870();
    do {
        if (wa1 == 0) { f_068f40(); f_0d5a90(); }
        if (f_0d37b0() != 0 || d_1bd762 == 0x4900) {
            short rr = f_0bf820(d_1c2c64, 0x9030005, 7, 0x9030006, 0x9030008, 0x9030009, 0x903000c, 0x9030007, 0x903000d, 0x903000b) - 1;
            if (rr != -2) { short tab[7] = { 0x82, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c }; d_1bd766 = tab[rr]; }
        }
        wa1 = 0;
        if (d_1bd766 == 0x84 || d_1bd766 == 0x86) { d_1bd760 = 1; d_1bd766 = d_1bd766 - 1; }
        switch ((unsigned short)d_1bd766) {
        case 0x5300: d_1bd766 = 0x89; break;
        case 0x4800: d_1bd766 = 0x83; break;
        case 0x5000: d_1bd766 = 0x85; break;
        case 0x0f09: d_1bd766 = 0x82; break;
        case 0x011b: d_1bd766 = 0x8c; break;
        case 0x2600: d_1bd766 = 0x8e; break;
        default:
            if (d_1bd766 == d_1c20f8) d_1bd766 = 0x87;
            else if (d_1bd766 == d_1c20fa) d_1bd766 = 0x88;
            else if (d_1bd766 == d_1c20fc) d_1bd766 = 0x8a;
            break;
        case 0x1c0d: d_1bd766 = 0x87; break;
        case 0x5200: d_1bd766 = 0x8a; break;
        }
        f_05dcd0(m, d_1bd766);
        switch (d_1bd766) {
        case 0x89:
            if (m->f650 > 0) {
                char s70[16];
                { int c_=m->cur; int sum_=m->top+c_; {int u_=sum_;sum_=u_;} strcpy(s70,m->names[sum_]); }
                strcpy(s90, s70);
                TRIMEXT(s90)
                f_0cdd30(s70, 0x20);
                f_0cdd30(s70, 0x2e);
                strcat(s70, d_1b6edc);
                if (f_14d717(s90, d_1b6ee1) == 0) { f_0bf730(d_1c2c64, 0x903001f); break; }
                o.p10->f4 = f_133fe0(d_1c3498, s90);
                if (f_0bf6f0(d_1c2c64, 0x9030004) == 1) {
                    f_05b340(m, (short)(m->cur + m->top));
                    m->sel = -1;
                    int s_;
                    { int c_ = m->cur; s_ = c_ + m->top; } // c_ benannt: cur vor top laden, eine m-Ladung wie Original
                    { int u_ = s_; s_ = u_; } // Haelt den Nutzwert von s_ (Summe in EAX wie im Original)
                    if (s_ == m->f650 - 1 && !m->top) m->cur--;
                    else if (m->top != (short)0) m->top = m->top - 1;
                    m->f650 = FindListCount493(m);
                    f_05d0d0(m);
                    redraw3(m);
                }
            } else f_0bf730(d_1c2c64, 0x9030014);
            break;
        case 0x83: {
            n = d_1bd760 ? 9 : 1;
            if (n > m->cur + m->top) n = m->cur + m->top;
            for (i = 0; i < n; i++) {
                if (--m->cur < 0) { m->cur = 0; if (--m->top < 0) m->top = 0; }
            }
            f_05d0d0(m);
            redraw(m);
            break; }
        case 0x85: {
            n = d_1bd760 ? 9 : 1;
            { int c_=m->cur; if (n > m->f650 - (m->top + c_)) n = m->f650 - (m->cur + m->top); }
            for (i = 0; i < n; i++) {
                m->cur = m->cur + 1;
                if (m->cur >= (short)10 && m->cur < m->f650) {
                    m->top++;
                    int t = m->f650 - 10;
                    flx = t; // Zuweisung hebt Nutzwert von t (ESI wie im Original)
                    m->cur = 9;
                    if (t > 0 && m->top > t) m->top = m->f650 - 10;
                } else if (m->cur >= m->f650) m->cur--;
            }
            f_05d0d0(m);
            redraw4(m);
            break; }
        case 0x81:
            m->cur = (d_1bf4fa - 0x3c) / m->s20;
            if (m->cur >= m->f650) m->cur = m->f650 - 1;
            if (m->cur >= (short)10) m->cur = 9;
            if (m->cur != m->sel) f_05d0d0(m);
            redraw2(m);
            break;
        case 0x8b:
            if (f_0bf6f0(d_1c2c64, 0x9030002) == 1) { f_144570(); f_148534(0); }
            break;
        case 0x82:
            if ((short)f_05d460(m, (short)(m->cur + m->top)) != 0) {
                int sv = d_1bfdb8;
                d_1bfdb8 = 0;
                f_060ae0(m->f0c, m->buf, 0);
                d_1bfdb8 = sv;
                f_05d370(m, (short)(m->cur + m->top));
            } else f_0bf730(d_1c2c64, 0x903001b);
            m->sel = m->cur;
            if (d_1bd766 == 0x4900 || f_0d37b0() != 0) { wa1 = 1; d_1bd762 = 0x4900; }
            d_1bd766 = 0;
            break;
        case 0x8a:
            if (p2 == 1) f_0bf730(d_1c2c64, 0x9030017);
            else if (f_05d650(m) == 1) {
                m->top = 0;
                m->cur = m->top;
                seek(m);
                f_05d0d0(m);
                redraw5(m);
                f_05a5c0(m, p2, 0);
            }
            break;
        case 0x87:
            if (m->f650 > 0) {
                 
                strcpy(s90, m->names[m->cur + m->top]);
                TRIMEXT(s90)
                o.p10->f4 = f_133fe0(d_1c3498, s90);
                if (f_0bf6f0(d_1c2c64, 0x9030018) == 1) LOADSEQ87(m, m->names, m->top + m->cur)
            } else f_0bf730(d_1c2c64, 0x9030014);
            break;
        case 0x88:
            done = f_05a5c0(m, p2, 1);
            break;
        case 0x8c:
            if (d_1c21a4 == (short)4) f_0bf730(d_1c2c64, 0x903001a);
            else done = 1;
            break;
        case 0x8e:
            if (m->f650 > 0) {
                if ((short)f_0bfea0(d_1c2c64, 8, 0x903001c) != -1) {
                    strcpy(s5c, d_1c299c);
                    strcat(s5c, d_1b6eec);
                    f_14572e(path, d_1a9678, s5c);
                    int h2 = (short)f_144fbf(path, 0x200);
                    if (h2 != -1) {
                        f_145259(h2);
                        strcpy(s5c, m->names[m->cur + m->top]);
                        { int c_=m->cur; int sum_=m->top+c_; {int u_=sum_;sum_=u_;} int off_=sum_*13; {int u_=off_;off_=u_;} char *dst_=(char*)m->names+off_; {char *u_=dst_;dst_=u_;} strcpy(dst_,d_1c299c); }
                        { int c_=m->cur; int off_=(m->top+c_)*13; {int u_=off_;off_=u_;} char *dst_=(char*)m->names+off_; {char *u_=dst_;dst_=u_;} strcpy(s90,dst_); }
                        TRIMEXT(s90)
                        o.p10->f4 = f_133fe0(d_1c3498, s90);
                        if (f_0bf6f0(d_1c2c64, 0x9030018) == 1) {  LOADSEQ(m, m->names, m->top + m->cur) }
                        else { int c_=m->cur; { int off_=(m->top+c_)*13; {int u_=off_;off_=u_;} char *dst_=(char*)m->names+off_; {char *u_=dst_;dst_=u_;} strcpy(dst_,s5c); } }
                    } else {
                        o.p10->f4 = f_133fe0(d_1c3498, s5c);
                        f_0bf730(d_1c2c64, 0x903001d);
                    }
                }
            } else f_0bf730(d_1c2c64, 0x9030014);
            break;
        }
        if (f_0d3800() != 0 && f_0d34b0(0x20, 0x3b, 0x58, 0x8e) != 0) {
            f_0d37e0();
             
            int c = m->cur; d_1c2a80 = (d_1c2a80 & 0) ? 0 : d_1c2a80;
            if (c >= 0 && m->f650 > 0) {
                strcpy(s90, m->names[c + m->top]);
                TRIMEXT(s90)
                o.p10->f4 = f_133fe0(d_1c3498, s90);
                if (f_0bf6f0(d_1c2c64, 0x9030018) == 1) LOADSEQ_M(m, m->names, m->cur + m->top) // Operandenfolge je Kopie
            } else f_0bf730(d_1c2c64, 0x9030014);
        }
    } while (done == 0);
    {
    delete (EdC *)m->f0c;
    delete (ImC *)m->f64c;
    d_1bf510 = old0;
    d_1bf514 = old1;
    f_05e320(d_1c38b0, sa, sb);
        if (f_0d3860() == 1) { f_0d2710(); pix = (char *)1; } else pix = 0;
        void RestoreA4(void*,int,int,int);
        #pragma aux RestoreA4 "f_0fade0" parm [eax] [edx] [ebx] [ecx] modify exact [eax ebx ecx edx esi edi];
        RestoreA4(b,d_1a34e0,x0,y0);
        if (pix == (char *)1) f_0d26e0();
    }
    d_1c0c94 = 1;
    f_01eb50(d_1c2bcc);
    d_1bcad0 = 0;

    d_1c0c4c--;
    ((void *)(((RivaRasterImage*)(b))->f_0fad20( 0)));
    f_1254a0(&o, 0);
    f_0ce7e0(&o24, 0);
    return ret;
}

//@ f_05cf10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt in einem Schritt die Eingabegeräte (f_068f40) und den System-/Sound-Tick (f_0d5a90) ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Aktualisiert über f_068f40 die globalen Tasten- und Aktionsvariablen d_1bd762 und
 *   d_1bd766.
 === Ende Beschreibung === */
void f_05cf10()
{
    f_068f40();
    f_0d5a90();
}

//@ f_05cf20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vergleichsfunktion für qsort (f_14d7dc), die zwei 13-Byte-Spielstandseinträge a und b
 *   absteigend nach ihrem DOS-Änderungsdatum (+0x0b) und bei gleichem Datum absteigend nach ihrer
 *   DOS-Änderungszeit (+0x09) sortiert, sodass der zuletzt gespeicherte oder geladene Spielstand immer ganz oben
 *   in der Liste steht.
 * - Eingaben und Rückgabe: Die Funktion erhält die Zeiger a und b auf zwei 13-Byte-Einträge (Ent) und gibt -1
 *   zurück, wenn a neuer als b ist, 1, wenn a älter als b ist, und 0 bei identischem Zeitstempel.
 * - Wichtige Variablen: Die 16-Bit-Felder *(unsigned short *)(a + 0xb) (DOS-Datum) und *(unsigned short *)(a +
 *   9) (DOS-Uhrzeit) entstammen der find_t-Struktur des Dateisystems.
 === Ende Beschreibung === */
int f_05cf20(char *a, char *b)
{
    unsigned short u2;
    unsigned short u1 = *(unsigned short *)(a + 0xb);
    u2 = *(unsigned short *)(b + 0xb);
    if (u1 > u2) return -1;
    if (u1 < u2) return 1;
    if (u1 == u2) {
        if (*(unsigned short *)(a + 9) > *(unsigned short *)(b + 9)) return -1;
        if (*(unsigned short *)(a + 9) < *(unsigned short *)(b + 9)) return 1;
    }
    return 0;
}

//@ f_05cf70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht das Verzeichnis ..\GAMES\*.GAM per _dos_findfirst/_dos_findnext nach bis zu 100
 *   Spielstanddateien, trägt deren auf 8 Zeichen mit Leerzeichen aufgefüllte Stammnamen samt Änderungszeit und
 *   Änderungsdatum in das Array m->names ein und sortiert die Liste anschließend über f_14d7dc (qsort) mit
 *   f_05cf20 nach Aktualität.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger m auf das Diskmenü-Objekt und gibt die Anzahl n der
 *   gefundenen Spielstände (0..100) als short zurück.
 * - Wichtige Variablen: Die lokale DOS-Suchstruktur ft (FT) liefert für jede gefundene Datei den Dateinamen
 *   ft.name, die Uhrzeit ft.wr_time und das Datum ft.wr_date.
 === Ende Beschreibung === */
short f_05cf70(Menu *m)
{
    FT ft;
    FT *pf = &ft;
    unsigned short n = 0;
    char *dst;
    f_14572e(d_1c21b4, d_1a9678, d_1b6ef1);
    if (f_1492b4(d_1c21b4, 0, pf) == 0) {
        f_145318(ft.name, d_1b6ef7);
        dst = m->names[0];
        f_0d4850(ft.name, 8, 0x20);
        strcpy(dst, ft.name);
        ((Ent *)m->names)[0].tm = ft.wr_time;
        n = 1;
        ((Ent *)m->names)[0].dt = ft.wr_date;
        while (f_1492d1(&ft) == 0) {
            int k;
            short j = n;
            if (j >= (short)100) break;
            f_145318(ft.name, d_1b6ef9);
            f_0d4850(ft.name, 8, 0x20);
            k = j * 13;
            strcpy(k + dst, ft.name);
            *(unsigned short *)((char *)m + k + 0x133) = ft.wr_time;
            n++;
            *(unsigned short *)((char *)m + k + 0x135) = ft.wr_date;
        }
    }
    f_1492ed(&ft);
    f_14d7dc(m->names, (short)n, 13, f_05cf20);
    return n;
}
