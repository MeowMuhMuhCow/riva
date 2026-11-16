/* === Beschreibung (Katalog) ===
 * Einheit selector
 *
 * Diese Einheit implementiert das interaktive Helden- und Ziel-Auswahlfenster (selector) der Benutzeroberfläche,
 * mit dem der Spieler ein oder mehrere Gruppenmitglieder für Zauber, Gegenstände, Talentproben oder Handlungen
 * bestimmt.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 6/10 gleich (suche.py 30.10.2026, Basis selector_P1.CPP)
// selector.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F1580-0x0F25C0
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
int f_0f25c0(int p1);                                   // reg eax stapel 0
int f_0f2630(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_145450(int p1);                                   // reg eax stapel 0
int f_1483f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_148450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_149cf0(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern unsigned short d_1bd75c;                    // 0x1BD75C
extern int d_1c3068;                    // 0x1C3068
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a66d8[];           // Text 0x1A66D8
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1a9820;
extern int d_1a66f8;
extern int d_1c2edc;
short f_0e9690(int p1, int p2);
int f_148143(char *d, char *s, int n);
int f_144bf0(char *a, char *b);
int f_145300(char *d, int c, int n);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];

struct T9 { char c[9]; };
void f_0f2080(int p);
unsigned short f_0f2500(int p, char *a, char *b, int n);
#define S16(p,o) (*(short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
#define A38B0 ((int)&d_1c38b0)
#define A3068 ((int)&d_1c3068)

// Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))
extern unsigned char d_1a66fc;
extern unsigned char d_1bd762;
extern unsigned char d_1bd766;
extern unsigned char d_1bf4f2;
extern unsigned char d_1bf514;

extern unsigned char d_1c2198;
extern unsigned char d_1c3078;
int C014540_3(int,int,int);
#pragma aux C014540_3 "f_014540" modify exact [eax ebx edx];
int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C045e10_2(int,int);
#pragma aux C045e10_2 "f_045e10" modify exact [eax edx];
int C05e320_3(int,int,int);
#pragma aux C05e320_3 "f_05e320";
int C05e340_1(int);
#pragma aux C05e340_1 "f_05e340";
int C05e360_3(int,int,int);
#pragma aux C05e360_3 "f_05e360" modify exact [eax];
int C068f40_0();
#pragma aux C068f40_0 "f_068f40" modify exact [eax];
int C0d26e0_0();
#pragma aux C0d26e0_0 "f_0d26e0" modify exact [eax];
int C0d2710_0();
#pragma aux C0d2710_0 "f_0d2710" modify exact [eax];
int C0d3390_4(int,int,int,int);
#pragma aux C0d3390_4 "f_0d3390" modify exact [eax ecx];
int C0d37b0_0();
#pragma aux C0d37b0_0 "f_0d37b0" modify exact [eax];
int C0d37e0_0();
#pragma aux C0d37e0_0 "f_0d37e0" modify exact [eax];
int C0d3860_0();
#pragma aux C0d3860_0 "f_0d3860" modify exact [eax];
int C0e9660_4(int,int,int,int);
#pragma aux C0e9660_4 "f_0e9660" modify exact [ebx ecx];
int C0f1570_2(int,int);
#pragma aux C0f1570_2 "f_0f1570";
int C0f1730_4(int,int,int,int);
#pragma aux C0f1730_4 "f_0f1730" modify exact [eax ebx edx];
int C0f17e0_1(int);
#pragma aux C0f17e0_1 "f_0f17e0" modify exact [eax];
int C0f1e80_1(int);
#pragma aux C0f1e80_1 "f_0f1e80" modify exact [eax];
int C0f2310_1(int);
#pragma aux C0f2310_1 "f_0f2310" modify exact [eax];
int C0f2630_3(int,int,int);
#pragma aux C0f2630_3 "f_0f2630" modify exact [eax ebx edx];
int C0fac80_3(int,int,int);
#pragma aux C0fac80_3 "f_0fac80" modify exact [eax ebx edx];
int C0fad20_2(int,int);
#pragma aux C0fad20_2 "f_0fad20" modify exact [eax edx];
int C0fb0b0_1(int);
#pragma aux C0fb0b0_1 "f_0fb0b0" modify exact [eax];
int C1448b0_3(int,int,int);
#pragma aux C1448b0_3 "f_1448b0" modify exact [eax ebx edx];
int C144920_3(int,int,int);
#pragma aux C144920_3 "f_144920" modify exact [eax ebx edx];
int C1449a0_1(int);
#pragma aux C1449a0_1 "f_1449a0" modify exact [eax];
int C144a00_1(int);
#pragma aux C144a00_1 "f_144a00" modify exact [eax];
int C145300_3(int,int,int);
#pragma aux C145300_3 "f_145300";
int C1459b0_1(int);
#pragma aux C1459b0_1 "f_1459b0";
int C1459d0_2(int,int);
#pragma aux C1459d0_2 "f_1459d0" modify exact [eax];
int C145a10_3(int,int,int);
#pragma aux C145a10_3 "f_145a10" modify exact [eax ebx edx];
int C149cf0_1(int);
#pragma aux C149cf0_1 "f_149cf0";
int C14d7dc_4(int,int,int,int);
#pragma aux C14d7dc_4 "f_14d7dc" modify exact [eax ebp ebx ecx edx];
//@ f_0f1580
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion konstruiert ein Auswahlfenster-Objekt (selector), initialisiert die Listen der
 *   wählbaren und ausgewählten Heldenplätze, legt das Fensterrechteck fest und verknüpft die zugehörigen
 *   Schaltflächen- und Porträtbereiche.
 * - Eingaben: Die Funktion erhält den this-Zeiger des Auswahlfensters (p1) sowie Steuerparameter für Position,
 *   Auswahlmodus und Filter (p2 bis p5).
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_0f1580(int self)
{
    char pcx[164];int bytes;
    C1459b0_1((int)pcx);
    NI(self,0x1a)=NNEW(22,d_1a66d8,0x44);
    NI(self,10)=NNEW(0x898,d_1a66d8,0x45);
    int raw=NOBJ(9,d_1a66d8,0x46); NI(self,6)=raw ? C0fac80_3(raw,158,122) : raw;
    NI(self,0x1e)=C014540_3(0x9880,NA(d_1a66d8),0x47);
    C145a10_3((int)pcx,0x80004,C0fb0b0_1(NI(self,6)));
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0x40080002,0x200);
    bytes=C144a00_1(NA((*(unsigned char*)&d_1c2098)));
    NI(self,14)=C014540_3(bytes,NA(d_1a66d8),0x5b);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),NI(self,14),bytes);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    NW(self,2)=0; NI(self,0x26)=0;
    NW(self,4)=NW(self,2); NI(self,0x22)=NI(self,0x26);
    C1459d0_2((int)pcx,0);
    return self;
}

//@ f_0f16b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der abgeleitete oder freigebende Destruktor des Auswahlfensters, der das Objekt
 *   abbaut und optional dessen Speicherblock über operator delete freigibt.
 * - Eingaben: Die Funktion erhält den this-Zeiger (p1) sowie das Freigabe-Flag (p2).
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_0f16b0(int self, int destructor_flags)
{
    int image = NI(self, 6);
    if (image != 0) C014710_1(C0fad20_2(image, 0));
    C014710_1(NI(self, 0x0a));
    C014710_1(NI(self, 0x1a));
    C014710_1(NI(self, 0x1e));
    C014710_1(NI(self, 0x0e));
    return self;
}

//@ f_0f16f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der Basis-Destruktor des Auswahlfensters, der die intern reservierten Puffer und
 *   Unterfenster wieder freigibt.
 * - Eingaben: Die Funktion erhält den this-Zeiger (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis des Basis-Destruktoraufrufs zurück.
 === Ende Beschreibung === */
// f_0f1730 liest drei Registerargumente und bewahrt ECX; qsort bewahrt EBP mit ENTER/LEAVE.
int fillSelector(int, signed char, signed char);
#pragma aux fillSelector "f_0f1730" modify exact [eax ebx edx];
int sortSelector(int, int, int, int);
#pragma aux sortSelector "f_14d7dc" modify exact [eax ebx ecx edx];
int f_0f16f0(int self, char *out, signed char low, signed char high)
{
    int compare=(int)C0f1570_2;
    NI(self,0x16)=(int)out;
    NW(self,0)=(short)fillSelector(self,low,high);
    sortSelector(NI(self,10),NW(self,0),22,compare);
    return C0f17e0_1(self);
}

//@ f_0f1730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft für alle Gruppenplätze, welche Helden gemäß den übergebenen Filterkriterien
 *   (beispielsweise lebendig, bei Bewusstsein, magiekundig oder im selben Raum befindlich) überhaupt auswählbar
 *   sind, und belegt die Auswahlliste vor.
 * - Eingaben: Die Funktion erhält den this-Zeiger des Auswahlfensters (p1).
 * - Rückgabewert: Die Funktion gibt die Anzahl der wählbaren Helden zurück.
 === Ende Beschreibung === */
struct SelectorSource8 { unsigned char id; char active; signed char level; char name[20]; };
struct SelectorTarget8 { char name[20]; unsigned char id; char level; };
struct SelectorObject8 { short count,selected,top; char *image; SelectorTarget8 *out; SelectorSource8 *in; };
short f_0f1730(SelectorObject8 *self,signed char low,signed char high)
{
    short index=0,count=0;
    if(high==-1) high=low;
    while(self->in[index].id!=255) {
        if(self->in[index].level>=low && high>=self->in[index].level && self->in[index].active) {
            self->out[count].id=self->in[index].id;
            self->out[count].level=self->in[index].level;
            strcpy(self->out[count].name,self->in[index].name);
            count++;
        }
        index++;
    }
    return count;
}

//@ f_0f17e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet das Helden-Auswahlfenster auf dem Bildschirm, führt die interaktive
 *   Ereignisschleife für Maus- und Tastatureingaben (Porträtklicks, Pfeiltasten, Zifferntasten, Bestätigen und
 *   Abbrechen) aus und schließt das Fenster nach getroffener Wahl wieder.
 * - Eingaben: Die Funktion erhält den this-Zeiger des Auswahlfensters (p1).
 * - Rückgabewert: Die Funktion gibt den ausgewählten Heldenindex beziehungsweise die Anzahl oder Maske der
 *   ausgewählten Helden (oder -1 bei Abbruch) zurück.
 === Ende Beschreibung === */
void ModalAbi16_0e9660_4(int,int,int,int);
#pragma aux ModalAbi16_0e9660_4 "f_0e9660" modify [eax ebx ecx edx];
int ModalAbi16_0d3390_4(int,int,int,int);
#pragma aux ModalAbi16_0d3390_4 "f_0d3390" modify [eax ebx ecx edx];
struct ModalRow16 { char name[20];unsigned char id;signed char level; };
struct ModalObject16 {
    short count,selected,top;void *image;ModalRow16 *rows;void *source;
    short width,height;char *out,*search;void *pixels;int dirty,done;
};
// Unlock-Aufruf ohne Registerzusage
int ModalAbi16_05e340_1(int);
#pragma aux ModalAbi16_05e340_1 "f_05e340" modify [eax ebx ecx edx];
// ABI-Zusagen fuer f_0f17e0
void Delay_0f17e0(unsigned);
#pragma aux Delay_0f17e0 "f_149cf0" modify exact [eax];
int Draw2630_0f17e0(int,int,int);
#pragma aux Draw2630_0f17e0 "f_0f2630" modify [eax ebx ecx edx ebp];
#define U16(a) (*(unsigned short *)&(a))
#define V16(a) (*(volatile short *)&(a)) // haelt 16-Bit-Speicherzugriffe in f_0f17e0 wie im Original
#define V32(a) (*(volatile int *)&(a)) // haelt 32-Bit-Speicherzugriffe in f_0f17e0 wie im Original
static inline void blink_0f17e0(ModalObject16 *self)
{
    short count;
    short rowY;
    rowY = (self->selected - self->top) * 8 + 67;
    count = 0;
    C0d2710_0();
    for (; count < 3; count++) {
        Delay_0f17e0(80);
        ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], 94, rowY);
        Delay_0f17e0(80);
        C05e320_3(A38B0, 255, -1);
        ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], 94, rowY);
        ModalAbi16_05e340_1(A38B0);
    }
    Delay_0f17e0(80);
    C0d26e0_0();
}
short f_0f17e0(ModalObject16 *self)
{
    short old_fg, old_bg;
    short ret = 0, old_y;
    short y = 0;
    int m2 = 0;
    ModalRow16 *entry = self->rows+self->selected+self->top; // haelt die Stapelplatz- und Registerfolge wie im Original
    old_y = ND16(d_1bf4f2);
    ret = -1;
    C05e360_3(A38B0, (int)&old_fg, (int)&old_bg);
    C05e320_3(A38B0, 0xe0, -1);
    V16(d_1c2198) = 1;
    while (!self->done) {
        if (ND16(d_1c2198)) {
            C0f1e80_1((int)self);
            ND16(d_1c2198) = 0;
        }
        V32(d_1bf514) = NA(d_1a66fc);
        C068f40_0();
        ND32(d_1bf514) = 0;
        if ((int)old_y != (int)V16(d_1bf4f2)) {
            if (ModalAbi16_0d3390_4(0x59, 0x41, 0xcf, 0x90)) {
                short row = self->top + ((ND16(d_1bf4f2) - 0x41) >> 3);
                if (row != self->selected && row >= 0 && row < self->count) {
                    short x = 0x5e;
                    { short saveA3 = x; x = saveA3; } // haelt x in einem eigenen Register wie im Original
                    y = 0x43;
                    int m;
                    if (C0d3860_0() == 1) {
                        C0d2710_0();
                        m = 1;
                    } else {
                        m = 0;
                    }
                    ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], x, (short)((self->selected - self->top) * 8 + y));
                    self->selected = row;
                    C05e320_3(A38B0, 0xff, -1);
                    ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], x, (short)((self->selected - self->top) * 8 + y));
                    ModalAbi16_05e340_1(A38B0);
                    if (m == 1) {
                        C0d26e0_0();
                    }
                    C145300_3((int)self->search, 0, 0x16);
                    old_y = ND16(d_1bf4f2);
                }
            }
        }
        if (self->dirty) {
            short x2 = 0x5e;
            short y2 = 0x43;
            self->dirty = 0;
            if (C0d3860_0() == 1) {
                C0d2710_0();
                m2 = 1;
            } else {
                m2 = 0;
            }
            C05e320_3(A38B0, 0xff, -1);
            ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], x2, (short)((self->selected - self->top) * 8 + y2));
            Draw2630_0f17e0((int)self, x2, (short)((self->selected - self->top) * 8 + y2));
            ModalAbi16_05e340_1(A38B0);
            if (m2 == 1) {
                C0d26e0_0();
            }
        }
        if (ND16(d_1bd766) == 2 || U16(d_1bd762) == 0x4800) {
            if (self->selected) {
                ND16(d_1c2198) = 1;
                self->selected--;
                if (self->selected < self->top) {
                    self->top -= 9;
                    if (self->top < 0) {
                        self->top = 0;
                    }
                }
            }
            C145300_3((int)self->search, 0, 0x16);
        } else if (ND16(d_1bd766) == 3 || U16(d_1bd762) == 0x5000) {
            if (self->selected < self->count - 1) {
                ND16(d_1c2198) = 1;
                self->selected++;
                if (self->selected > self->top + 9) {
                    if (self->top < self->count - 10) {
                        self->top += 9;
                    }
                }
            }
            C145300_3((int)self->search, 0, 0x16);
        } else if (ND16(d_1bd766) == 4) {
            short my = V16(d_1bf4f2);
            int half = self->width >> 1;
            if (my <= self->height + 0x25 + half) {
                if (C0d37e0_0()) {
                    U16(d_1bd762) = 0x4700;
                } else {
                    U16(d_1bd762) = 0x4900;
                }
            } else {
                if (C0d37e0_0()) {
                    U16(d_1bd762) = 0x4f00;
                } else {
                    U16(d_1bd762) = 0x5100;
                }
            }
        } else if (C0d37b0_0() || U16(d_1bd762) == 0x11b) {
            self->done = 1;
            self->selected = -1;
        } else if (U16(d_1bd762) == 0x1c0d || ND16(d_1bd766) == 1) {
            self->done = 1;
        } else if (C045e10_2(NA(d_1c3078), (unsigned char)d_1bd75c) || (short)d_1bd75c == 8) {
            C0f2310_1((int)self);
        }
        if (U16(d_1bd762) == 0x4900) {
            if (self->top) {
                self->top -= 9;
                if (self->top < 0) {
                    self->top = 0;
                }
                if (self->selected > self->top + 9) {
                    self->selected = self->top + 9;
                }
            } else {
                self->selected = 0;
            }
            C145300_3((int)self->search, 0, 0x16);
            ND16(d_1c2198) = 1;
        } else if (U16(d_1bd762) == 0x5100) {
            if (self->top < self->count - 10) {
                self->top += 9;
                if (self->top > self->count - 10) {
                    self->top = self->count - 10;
                }
                if (self->selected < self->top) {
                    self->selected = self->top;
                }
            } else {
                self->selected = self->count - 1;
            }
            C145300_3((int)self->search, 0, 0x16);
            ND16(d_1c2198) = 1;
        } else if (U16(d_1bd762) == 0x4700) {
            if (self->top) {
                self->top = 0;
            }
            C145300_3((int)self->search, 0, 0x16);
            ND16(d_1c2198) = 1;
            self->selected = 0;
        } else if (U16(d_1bd762) == 0x4f00) {
            if (self->top < self->count - 10) {
                self->top = self->count - 10;
            }
            C145300_3((int)self->search, 0, 0x16);
            ND16(d_1c2198) = 1;
            self->selected = self->count - 1;
        }
    }
    *self->out = 0;
    if (self->selected != -1) {
        blink_0f17e0(self);
        int offA3 = self->selected * 22; int baseA3 = (int)self->rows;
        int addrA3 = baseA3; addrA3 = offA3 + addrA3;
        ModalRow16 *rowA3 = (ModalRow16 *)addrA3;
        ret = (rowA3->level << 8) + rowA3->id;
        strcpy(self->out, rowA3->name);
    }
    C05e320_3(A38B0, old_fg, old_bg);
    return ret;
}

//@ f_0f1e80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet den Rahmen, den Titeltext, die Heldenporträts beziehungsweise Namensfelder
 *   sowie die Hervorhebung der aktuell markierten Helden in das Auswahlfenster.
 * - Eingaben: Die Funktion erhält den this-Zeiger (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der letzten Zeichenoperation zurück.
 === Ende Beschreibung === */
void f_0f1e80(int p)
{
    struct H {
        static int at(int idx, int p)
        {
            int n = idx * 0x16;
            int base = (I32(p,10) & 0) ? 0 : I32(p,10); // haelt die Auswertungsreihenfolge von n + I32(p,10) wie im Original
            return n + base;
        }
    };
    short x;
    short y, i;
    int k, u, o;
    x = 0x50 - (f_0e9690(A38B0, I32(p,0x16)) >> 1);
    y = 0xd;
    u = f_05dec0(A3068);
    f_05ded0(A3068, I32(p,0x1e));
    ((RivaRasterImage*)(I32(p,6)))->f_0fade0((void *)( I32(p,0x1e)), 0, 0);
    f_05e320(A38B0, 0xe7, -1);
    f_0e9660(A38B0, I32(p,0x16), (short)(x + 1), 0xe);
    f_05e340(A38B0);
    f_05e320(A38B0, 0xe0, -1);
    f_0e9660(A38B0, I32(p,0x16), (short)x, y);
    i = 0;
    f_05e340(A38B0);
    y = 0x1e;
    for (; i < 10; i++) {
        k = S16(p,4) + i;
        if (k < S16(p,0)) {
            if (k == S16(p,2)) {
                f_05e320(A38B0, 0xff, -1);
                f_0e9660(A38B0, H::at(i + S16(p,4), p), 0xf, y);
                f_0f2630(p, 0xf, y);
                f_05e340(A38B0);
            } else {
                f_0e9660(A38B0, H::at(k, p), 0xf, y);
            }
        }
        y += 8;
    }
    f_05ded0(A3068, u);
    f_0f2080(p);
    o = (int)new (mark(d_1a66d8, 0x1b8)) T9;
    o = o ? ((int)(((RivaRasterImage*)(o))->f_0fac80( 0x9e, 0x7a))) : o;
    ((RivaRasterImage*)(o))->f_0fafb0((void *)( I32(p,0x1e)), 0, 0);
    f_0d2710();
    ((RivaRasterImage*)(o))->f_0fae30((void *)( d_1a34e0), 0x4f, 0x25, 1);
    f_0d26e0();
    if (o != 0) {
        operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    }
}

//@ f_0f2080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktualisiert die grafische Hervorhebung eines einzelnen Heldenplatzes im
 *   Auswahlfenster, wenn der Spieler den Auswahlbalken bewegt oder einen Helden an- beziehungsweise abwählt.
 * - Eingaben: Die Funktion erhält den this-Zeiger (p1) sowie den Index des zu zeichnenden Heldenplatzes (p2).
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Bildschirmaktualisierung zurück.
 === Ende Beschreibung === */
void f_0f2080(int p)
{
    short b, a;
    int o;
    if (S16(p,0) > 10) {
        a = (S16(p,0) * 100) / 10;
        if (!a) a = 1;
        S16(p,0x12) = 620000 / a;
        S16(p,0x12) /= (short)100;
        S16(p,0x12)++;
        short t_109 = S16(p,0x12);
        if (t_109 < 4) S16(p,0x12) = 4;
        b = (S16(p,0) * 100) / 0x3e;
        if (!b) b = 1;
        S16(p,0x14) = (S16(p,4) * 0x2710) / b;
        S16(p,0x14) /= (short)100;
        S16(p,0x14) += 0x27;
        if (S16(p,0x14) > 99 - S16(p,0x12)) S16(p,0x14) = 99 - S16(p,0x12);
    } else {
        S16(p,0x12) = 0x3e;
        S16(p,0x14) = 0x27;
    }
    o = (int)new (mark(d_1a66d8, 0x200)) T9;
    o = o ? ((int)(((RivaRasterImage*)(o))->f_0fac80( 8, S16(p,0x12)))) : o;
    ((RivaRasterImage*)(o))->f_0fb150( 0xba);
    ((RivaRasterImage*)(o))->f_0fade0((void *)( I32(p,0x1e)), 0x8a, S16(p,0x14));
    if (o != 0) {
        operator delete((void *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0))));
    }
    f_1483f0(I32(p,0x1e), 0x8a, S16(p,0x14), 7, -72);
    f_148450(I32(p,0x1e), 0x8a, S16(p,0x14), (short)(S16(p,0x12) - 1), -72);
    f_1483f0(I32(p,0x1e), 0x8b, (short)(S16(p,0x14) + S16(p,0x12) - 1), 7, -68);
    f_148450(I32(p,0x1e), 0x91, (short)(S16(p,0x14) + 1), (short)(S16(p,0x12) - 1), -68);
}

void BlinkDelay493(unsigned);
#pragma aux BlinkDelay493 "f_149cf0" modify exact [eax];
void BlinkColor493(int,int,int);
#pragma aux BlinkColor493 "f_05e320" modify exact [eax];
void BlinkRestore493(int);
#pragma aux BlinkRestore493 "f_05e340" modify exact [eax];
//@ f_0f2250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet den Auswahlstatus eines einzelnen Heldenplatzes um (unter Berücksichtigung
 *   der minimal und maximal zulässigen Anzahl gleichzeitiger Auswahlen) und veranlasst das Neuzeichnen des
 *   Eintrags.
 * - Eingaben: Die Funktion erhält den this-Zeiger (p1) sowie den Index des betroffenen Heldenplatzes (p2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Auswahl geändert wurde, oder 0, wenn der Platz gesperrt
 *   war.
 === Ende Beschreibung === */
void f_0f2250(ModalObject16 *self)
{
    short count;
    short rowY;
    rowY = (self->selected - self->top) * 8 + 67;
    count = 0;
    C0d2710_0();
    for (; count < 3; count++) {
        BlinkDelay493(80);
        ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], 94, rowY);
        BlinkDelay493(80);
        BlinkColor493(A38B0, 255, -1);
        ModalAbi16_0e9660_4(A38B0, (int)&self->rows[self->selected], 94, rowY);
        BlinkRestore493(A38B0);
    }
    BlinkDelay493(80);
    C0d26e0_0();
}
//@ f_0f2310
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als bequeme Hüllfunktion (Wrapper), die ein temporäres Auswahlfenster-Objekt
 *   erzeugt, den Auswahldialog mit einem Überschriftstext und einer Filterbedingung ausführt und direkt den
 *   gewählten Helden zurückliefert.
 * - Eingaben: Die Funktion erhält unter anderem den Überschriftstext (p1), die Filterflags (p2) sowie optionale
 *   Vorbelegungs- und Modusparameter (p3, p4).
 * - Rückgabewert: Die Funktion gibt den Index oder Zeiger des vom Spieler ausgewählten Helden zurück.
 === Ende Beschreibung === */
char *Strncpy_0f2310(char *d, const char *s, unsigned int n);
#pragma aux Strncpy_0f2310 "f_148143";
int Call_0f2500(ModalObject16 *p, char *a, char *b, int n);
#pragma aux Call_0f2500 "f_0f2500";
void f_0f2310(ModalObject16 *self)
{
    short n;
    short old;
    char *b1, *b2;
    old = self->selected;
    n = strlen(self->search);
    b1 = new (mark(d_1a66d8, 0x23d)) char[0x14];
    b2 = new (mark(d_1a66d8, 0x23e)) char[0x14];
    if ((short)d_1bd75c == 8 && n) {
        n--;
        d_1bd75c = 0;
        self->search[n] = (char)d_1bd75c;
        Strncpy_0f2310(b1, self->search, n);
        f_145450((int)b1);
        Strncpy_0f2310(b2, self->rows[self->selected].name, n);
        f_145450((int)b2);
        Call_0f2500(self, b1, b2, n);
        strcpy(self->search, b1);
    }
    if (d_1bd75c) {
        if (n < 0x13) {
            Strncpy_0f2310(b1, self->search, n);
            b1[n] = (char)d_1bd75c;
            n++;
            f_145450((int)b1);
            while (Call_0f2500(self, b1, b2, n) == 0) {
                n--;
                b1[n] = 0;
            }
            strcpy(self->search, b1);
        }
    }
    if (self->selected != old) f_0f25c0((int)self);
    self->dirty = 1;
    operator delete(b1);
    operator delete(b2);
}

//@ f_0f2500
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet ein vereinfachtes Auswahlfenster für Mehrfach- oder Gruppenauswahlen und
 *   schreibt die getroffene Auswahl in das übergebene Ergebnis-Array.
 * - Eingaben: Die Funktion erhält den Überschriftstext (p1), das Ergebnis-Array (p2) sowie die Filter- und
 *   Anzahlparameter (p3, p4).
 * - Rückgabewert: Die Funktion gibt die Anzahl der ausgewählten Helden oder den Statuscode des Dialogs zurück.
 === Ende Beschreibung === */
int Z145300_3(char *, int, int);
#pragma aux Z145300_3 "f_145300" parm [eax] [edx] [ebx] modify [eax edx ebx ecx];
int f_0f2500(int p, char *a, char *b, short n)
{
    short i;
    int found = 0;
    Z145300_3(b, 0, 0x14);
    f_148143(b, (char *)I32(p, 0xa), n);
    i = 0;
    f_145450((int)b);
    while (f_144bf0(a, b) > 0 && i < S16(p, 0) - 1) {
        i++;
        f_148143(b, (char *)(I32(p, 0xa) + i * 0x16), n);
        f_145450((int)b);
    }
    S16(p, 2) = i;
    if (f_144bf0(a, b) == 0) found = 1;
    else {
        int snd = d_1a9820;
        f_147323((int)&d_1c2edc, d_1a66f8, 0x7fff, 0x8000, snd, 0, 1);
    }
    return found;
}
