/* === Beschreibung (Katalog) ===
 * Einheit gz_0bff80 (Adresse 0x0bff80 - 0x0c0e30)
 *
 * Diese Einheit enthält im ersten Teil (f_0bff80 bis f_0c07d0) die Basismethoden des Menü-Overlays (menuovl),
 * die interaktive Ereignisschleife für das Ziffern-Eingabefeld (numinput) sowie die Schatten-Zeichenroutine für
 * Menüfenster, und im zweiten Teil (f_0c07e0 bis f_0c0cd0) die Spielstands-Registrierung sowie Konstruktor und
 * Destruktor für den ersten Teil des Zwergenminen-Dungeons (mine1, Ortskennung 15).
 === Ende Beschreibung === */
#include "RIVAMOUS.H"
// P3 12/14 gleich (suche.py 29.10.2026, Basis gz_0bff80_P1.CPP)
// gz_0bff80.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BFF80-0x0C0E30
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#define EQI(x,v) (((x)==(v))?1:0)
inline int EQ(int a,int b){return a==b;}
#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
int f_145234(int p1, const char *p2);
int f_145254();
int f_057220(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_0697c0(int p1, int p2, int p3);


int f_0d3790();
int f_0d37b0();

short f_0d66f0(int p1);
int f_0d6700(int p1, int p2);
short f_0d6b90(int p1);
short f_0d6ba0(int p1);
int f_0d6bb0(int p1, int p2);
int f_0d6bc0(int p1, int p2);
int f_0d6bd0(int p1);
int f_0d6ce0(int p1);
int f_0e3430(int p1);
int f_0e3580(int p1, int p2);
int f_0e3ba0(int p1, int p2, int p3, int p4, int p5);
int f_0e4370(int p1);
int f_0e9550(int p1, int p2);
int f_1483f0(int p1, int p2, int p3, int p4, int p5);
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);
struct R { short x1, y1, x2, y2, id; };
extern struct R d_1a64fc[];
extern int d_1bf514;
extern short d_1bd75c, d_1bd760, d_1bd766;
extern unsigned short d_1bd762;
extern signed char d_1bd6c8;
extern const char d_1bb308[];
extern const char d_1bb330[];
extern const char d_1bb33c[];
extern const char d_1bb350[];
extern char d_1c38b0[];
extern char d_1c2c00[];
extern char d_1bf264, d_1bf288;
extern short d_1c212a;
extern short d_1c2132;
extern int *d_1c212c;
extern int *d_1c2134;
extern short d_1bf2ac;
extern short d_1bf2ae;
extern char d_1bf248;
extern short d_1bf249;
extern char d_1bf24c;
extern short d_1bf24d;
extern char d_1bf250;
extern short d_1bf251;
extern char d_1bf254;
extern short d_1bf255;
extern char d_1bf258;
extern short d_1bf259;
extern char d_1bf25c;
extern short d_1bf25d;
extern char d_1bf260;
extern short d_1bf261;
extern short d_1bf265;
extern char d_1bf268;
extern short d_1bf269;
extern char d_1bf26c;
extern short d_1bf26d;
extern char d_1bf270;
extern short d_1bf271;
extern char d_1bf274;
extern short d_1bf275;
extern char d_1bf278;
extern short d_1bf279;
extern char d_1bf27c;
extern short d_1bf27d;
extern char d_1bf280;
extern short d_1bf281;
extern char d_1bf284;
extern short d_1bf285;
extern short d_1bf289;
extern char d_1bf28c;
extern short d_1bf28d;
extern char d_1bf290;
extern short d_1bf291;
extern char d_1bf294;
extern short d_1bf295;
extern char d_1bf298;
extern short d_1bf299;
extern char d_1bf29c;
extern short d_1bf29d;
extern char d_1bf2a0;
extern short d_1bf2a1;
extern char d_1bf2a4;
extern short d_1bf2a5;
extern char d_1bf2a8;
extern short d_1bf2a9;
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0bff80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Basis-Menü-Overlay-Objekt (d_1bb330 / d_1bb308) oder ein Array
 *   solcher Objekte (p2 & 4) ab, gibt den 64.000-Byte-Hintergrundpuffer (I(p1, 8)) sowie den Rahmengrafik-Puffer
 *   (I(p1, 0)) über operator delete frei und löscht bei gesetztem Bit p2 & 2 das Objekt selbst.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie die Watcom-Destruktor-Flags p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0bff80(int p1, unsigned p2)
{
    if (p2 & 4) {
        f_145234(p1, d_1bb308);
        f_145254();
        return p1;
    }
    I(p1, 0x48) = (int)d_1bb330;
    operator delete((void *)I(p1, 8));
    operator delete((void *)I(p1, 0));
    if (p2 & 2)
        operator delete((void *)p1);
    return p1;
}
//@ f_0bffd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion gibt den Zeiger auf den 64.000 Byte großen Hintergrund-Sicherungspuffer (I(p1,
 *   8)) des Menü-Objekts p1 zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den Pufferzeiger bei Offset +0x08 zurück.
 === Ende Beschreibung === */
int f_0bffd0(int p1)
{
    return I(p1, 8);
}
//@ f_0bffe0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt das Sperrflag bei Offset +0x20 des Menü-Objekts p1 auf 1 und gibt den
 *   vorherigen 16-Bit-Wert zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den alten Wert des 16-Bit-Felds bei Offset +0x20 zurück.
 === Ende Beschreibung === */
int f_0bffe0(int p1)
{
    int t = W(p1, 0x20);
    W(p1, 0x20) = 1;
    return t;
}
//@ f_0bfff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt das Sperrflag bei Offset +0x20 des Menü-Objekts p1 wieder auf 0 zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bfff0(int p1)
{
    W(p1, 0x20) = 0;
}
//@ f_0c0000
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die horizontale Vorgabekoordinate bei Offset +0x22 des Menü-Objekts p1 auf p2
 *   und gibt den bisherigen Wert zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt sowie den neuen 16-Bit-Wert p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den vorherigen Wert bei Offset +0x22 zurück.
 === Ende Beschreibung === */
short f_0c0000(int p1, short p2)
{
    short t = W(p1, 0x22);
    W(p1, 0x22) = p2;
    return t;
}
//@ f_0c0010
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die vertikale Vorgabekoordinate bei Offset +0x24 des Menü-Objekts p1 auf p2 und
 *   gibt den bisherigen Wert zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt sowie den neuen 16-Bit-Wert p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den vorherigen Wert bei Offset +0x24 zurück.
 === Ende Beschreibung === */
short f_0c0010(int p1, short p2)
{
    short t = W(p1, 0x24);
    W(p1, 0x24) = p2;
    return t;
}
//@ f_0c0020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt die Fensterbreiten-Stufe bei Offset +0x12 des Menü-Objekts p1 auf p2 und gibt
 *   den bisherigen Wert zurück.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt sowie die neue Breitenstufe p2 entgegen.
 * - Rückgabewert: Die Funktion gibt die vorherige Breitenstufe bei Offset +0x12 zurück.
 === Ende Beschreibung === */
short f_0c0020(int p1, short p2)
{
    short t = W(p1, 0x12);
    W(p1, 0x12) = p2;
    return t;
}
//@ f_0c0030
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert die interaktive Eingabeschleife für ein mehrstelliges Ziffern-Zählwerk
 *   (numinput, Objekt p2 im Menüfenster p1): Sie baut die klickbaren Rechtecke (d_1a64fc) für die
 *   Aufwärts-Pfeile (IDs 2-6), die Abwärts-Pfeile (IDs 7-11) jeder Dezimalstelle sowie den OK-Schalter (ID 12)
 *   auf, verarbeitet Mausklicks und Pfeiltasten zum Verstellen der Ziffern (f_0d6700) und unterstützt auch das
 *   Verschieben des Eingabefensters per Maus (f_0e3ba0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt sowie den Zeiger p2 auf das
 *   Zifferneingabe-Objekt (numinput) entgegen.
 * - Rückgabewert: Die Funktion gibt den Tastatur-/Abschlussstatus d_1bd75c (z. B. 0x1b bei Abbruch oder den
 *   Bestätigungscode) zurück.
 === Ende Beschreibung === */

short f_0c0030(int p1, int p2)
{
    int fl = 1;
    volatile int sv = d_1bf514;
    short n = f_0d66f0(p2);
    short y;
    short i;
    short left, x2;
    short dx;
    while (d_1bd760 != (short)0)
        f_0e4370(p1);
    do {
        if (fl) {
    int product;
            short idx = 0;
            fl = 0;
            idx = 0;
            d_1a64fc[0].x1 = W(p1, 0x14);
            d_1a64fc[0].x2 = W(p1, 0x14) + W(p1, 0x26);
            d_1a64fc[0].y1 = W(p1, 0x16) + 1;
            d_1a64fc[0].y2 = W(p1, 0x16) + 14;
            idx++;
            y = (W(p1, 0x28) - 1) * 8 + W(p1, 0x16) - 4;
            for (i = 0; i < n; i++) {
                product=n; product*=15; left=((W(p1, 0x26) - product - 42) >> 1) + W(p1, 0x14) - 8;
                left += i * 14;
                x2 = left + 14;
                d_1a64fc[idx].x1 = left;
                d_1a64fc[idx].x2 = x2;
                d_1a64fc[idx].y2 = (d_1a64fc[idx].y1 = y - 13) + 13;
                d_1a64fc[idx++].id = i + 2;
                d_1a64fc[idx].x1 = left;
                d_1a64fc[idx].x2 = x2;
                d_1a64fc[idx].y2 = (d_1a64fc[idx].y1 = y + 17) + 13;
                d_1a64fc[idx++].id = i + 7;
            }
            d_1a64fc[idx].x1 = x2 + 16;
            d_1a64fc[idx].x2 = x2 + 50;
            d_1a64fc[idx].y1 = y;
            d_1a64fc[idx].y2 = y + 16;
            d_1a64fc[idx++].id = 12;
            d_1a64fc[idx].x1 = 0;
            d_1a64fc[idx].x2 = 0x13f;
            d_1a64fc[idx].y1 = 0;
            d_1a64fc[idx].y2 = 199;
            d_1a64fc[idx].id = 13;
        }
        *(volatile int *)&d_1bf514 = (int)&d_1a64fc;
        f_0e4370(p1);
        d_1bf514 = sv;
        if (d_1bd762 == 0x4900 || d_1bd762 == 0x5100 || f_0d37b0() != 0) {
            d_1bd766 = 12;
            d_1bd75c = 0x1b;
        }
        if (W(p1, 0x20) == 0 && (d_1bd766 == 1 || d_1bd760 != (short)0) && (f_0d3790() == 0 || d_1bd760 != (short)0)) {
            {
                RivaMouseGuard mg;
                f_0e3430(p1);
            }
            f_0e3ba0(p1, W(p1, 0x14), W(p1, 0x16), W(p1, 0x26), W(p1, 0x2a));
            f_0d2710();
            dx = f_0d6b90(p2) - (W(p1, 0x14) - W(p1, 0x18));
            f_0d6bb0(p2, dx);
            dx = f_0d6ba0(p2) - (W(p1, 0x16) - W(p1, 0x1a));
            f_0d6bc0(p2, dx);
            W(p1, 0x14) = W(p1, 0x18);
            W(p1, 0x16) = W(p1, 0x1a);
            f_05e2d0((int)d_1c38b0, (short)(W(p1, 0x14) + 15), -1, (short)(W(p1, 0x16) + 15), 1);
            f_0e3580(p1, W(p1, 0x28));
            f_0e9550((int)d_1c38b0, I(p1, 0xc));
            f_0d6bd0(p2);
            fl = 1;
            f_0d6ce0(p2);
            d_1bd766 = 0;
            f_0d26e0();
        }
        if (d_1bd766 >= (short)2 && d_1bd766 <= (short)6) {
            f_0d6700(p2, (short)(d_1bd766 - 2));
            d_1bd766 = 0x4800;
        }
        if (d_1bd766 >= (short)7 && d_1bd766 <= (short)11) {
            f_0d6700(p2, (short)(d_1bd766 - 7));
            d_1bd766 = 0x5000;
        }
        if (d_1bd766 == 0x4d00 || d_1bd766 == 0x4b00 || d_1bd766 == 0x4800 || d_1bd766 == 0x5000)
            d_1bd75c = 1;
    } while (d_1bd766 != (short)12 && d_1bd75c == (short)0);
    d_1a64fc[1].x1 = 0;
    d_1a64fc[1].x2 = 0x13f;
    d_1a64fc[1].y1 = 0;
    d_1a64fc[1].y2 = 199;
    d_1a64fc[1].id = 2;
    return d_1bd75c;
}
//@ f_0c04b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft bei geöffnetem Menüfenster (W(p1, 0x1c) != 0), ob sich das durch (p2, p3) bis
 *   (p4, p5) gegebene Bildschirmrechteck mit dem aktuellen Rechteck des Menüfensters (+0x14, +0x16, Breite
 *   +0x26, Höhe +0x2a) überschneidet.
 * - Eingaben: Die Funktion nimmt den Menü-Zeiger p1 sowie die vier Eckkoordinaten p2 (x1), p3 (y1), p4 (x2) und
 *   p5 (y2) entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn eine Überlappung mit dem geöffneten Menüfenster vorliegt,
 *   andernfalls 0.
 === Ende Beschreibung === */
#define CND (((W(p1,0x14) <= p2 && p2 <= W(p1,0x14) + W(p1,0x26)) || (W(p1,0x14) <= p4 && p4 <= W(p1,0x14) + W(p1,0x26))) && ((W(p1,0x16) <= p3 && p3 <= W(p1,0x16) + W(p1,0x2a)) || (p5 >= W(p1,0x16) && p5 <= W(p1,0x16) + W(p1,0x2a))))
int f_0c04b0(int p1, short p2, short p3, short p4, short p5)
{
    int r = 0;
    if (!W(p1, 0x1c)) {
        return 0;
    }
    if (CND) {
        r = 1;
    }
    return r;
}
//@ f_0c0550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Grafikfunktion zeichnet den halbtransparenten Schlagschatten bzw. die abgedunkelte Innenfläche
 *   eines Menüfensters p1 in den Bildschirmpuffer p2, indem sie zeilenweise horizontale Schattenstreifen über
 *   f_1483f0 an den vier abgerundeten Ecken und im Hauptbereich des Fensters zieht.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt sowie den Ziel-Bildschirmpuffer p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c0550(int p1, int p2)
{
 short a4,a7,y2,y3,y1,y2a,y0,y4,y6,y5,a8,a0,len,a6,x2,a1,a2,a5,a3;
 short y7,y8;
 x2=W(p1,0x14)+W(p1,0x26);
 y2=W(p1,0x16)+W(p1,0x2a);
 a0=W(p1,0x14)+6; len=W(p1,0x26)-12;
 for(y0=W(p1,0x16)+7;(short)y0<=W(p1,0x16)+W(p1,0x2a)-3;y0++)
  f_1483f0(p2,a0,(short)y0,(short)len,-1);
 a1=W(p1,0x14)+3;
 for(y1=W(p1,0x16)+4;(short)y1<=W(p1,0x16)+6;y1++)
  f_1483f0(p2,(short)a1,(short)y1,10,-1);
 a2=W(p1,0x14)+3;
 for(y2a=W(p1,0x16)+7;(short)y2a<=W(p1,0x16)+13;y2a++)
  f_1483f0(p2,(short)a2,(short)y2a,3,-1);
 a3=W(p1,0x14)+3;
 for(y3=y2-3;(short)y3<=(short)y2;y3++)
  f_1483f0(p2,(short)a3,(short)y3,10,-1);
 a4=W(p1,0x14)+3;
 for(y4=y2-9;(short)y4<=(short)y2-4;y4++)
  f_1483f0(p2,(short)a4,(short)y4,3,-1);
 a5=x2-13;
 for(y5=W(p1,0x16)+4;(short)y5<=W(p1,0x16)+6;y5++)
  f_1483f0(p2,(short)a5,(short)y5,10,-1);
 a6=(short)(x2 & 0xffff)-6;
 for(y6=W(p1,0x16)+7;(short)y6<=W(p1,0x16)+13;y6++)
  f_1483f0(p2,(short)a6,(short)y6,3,-1);
 a7=x2-13;
 for(y7=y2-3;(short)y7<=(short)y2;y7++)
  f_1483f0(p2,(short)a7,(short)y7,10,-1);
 a8=x2-6;
 for(y8=y2-9;(short)y8<=(short)y2-4;y8++)
  f_1483f0(p2,(short)a8,(short)y8,3,-1);
}
//@ f_0c07d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion markiert ein Menüfenster p1 als sichtbar und aktiv (W(p1, 0x1c) = 1 und W(p1,
 *   0x4c) = 1).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Menü-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c07d0(int p1)
{
    W(p1, 0x1c) = 1;
    W(p1, 0x4c) = 1;
}
struct Obj7 { char a; short b; };
struct Reg7 { short count; Obj7 **list; };
extern Reg7 reg7;
#pragma aux reg7 "d_1c212a"
inline void add7(Obj7 &o, Reg7 &r, short id) { o.a=0; o.b=id; r.list[r.count]=&o; ++r.count; }
struct ObjFinal7 { short a; short b; };
struct RegFinal7 { short count; int *list; };
extern ObjFinal7 finalo7;
#pragma aux finalo7 "d_1bf2ac"
extern RegFinal7 finalr7;
#pragma aux finalr7 "d_1c2132"
inline void finalmake7(ObjFinal7 &o, RegFinal7 &r,short id,short zero) { o.a=zero; o.b=id; r.list[r.count]=(int)&o; ++r.count; }
inline void zeroNext7(Obj7 &o) { o.a=0; }
inline void add7a(Obj7 &o, Reg7 &r, short id) { o.a=0; o.b=id; Obj7 **list=r.list; list[r.count]=&o; ++r.count; }
extern Obj7 ob7_d_1bf248;
#pragma aux ob7_d_1bf248 "d_1bf248"
extern Obj7 ob7_d_1bf24c;
#pragma aux ob7_d_1bf24c "d_1bf24c"
extern Obj7 ob7_d_1bf250;
#pragma aux ob7_d_1bf250 "d_1bf250"
extern Obj7 ob7_d_1bf254;
#pragma aux ob7_d_1bf254 "d_1bf254"
extern Obj7 ob7_d_1bf258;
#pragma aux ob7_d_1bf258 "d_1bf258"
extern Obj7 ob7_d_1bf25c;
#pragma aux ob7_d_1bf25c "d_1bf25c"
extern Obj7 ob7_d_1bf260;
#pragma aux ob7_d_1bf260 "d_1bf260"
extern Obj7 ob7_d_1bf264;
#pragma aux ob7_d_1bf264 "d_1bf264"
extern Obj7 ob7_d_1bf268;
#pragma aux ob7_d_1bf268 "d_1bf268"
extern Obj7 ob7_d_1bf26c;
#pragma aux ob7_d_1bf26c "d_1bf26c"
extern Obj7 ob7_d_1bf270;
#pragma aux ob7_d_1bf270 "d_1bf270"
extern Obj7 ob7_d_1bf274;
#pragma aux ob7_d_1bf274 "d_1bf274"
extern Obj7 ob7_d_1bf278;
#pragma aux ob7_d_1bf278 "d_1bf278"
extern Obj7 ob7_d_1bf27c;
#pragma aux ob7_d_1bf27c "d_1bf27c"
extern Obj7 ob7_d_1bf280;
#pragma aux ob7_d_1bf280 "d_1bf280"
extern Obj7 ob7_d_1bf284;
#pragma aux ob7_d_1bf284 "d_1bf284"
extern Obj7 ob7_d_1bf288;
#pragma aux ob7_d_1bf288 "d_1bf288"
extern Obj7 ob7_d_1bf28c;
#pragma aux ob7_d_1bf28c "d_1bf28c"
extern Obj7 ob7_d_1bf290;
#pragma aux ob7_d_1bf290 "d_1bf290"
extern Obj7 ob7_d_1bf294;
#pragma aux ob7_d_1bf294 "d_1bf294"
extern Obj7 ob7_d_1bf298;
#pragma aux ob7_d_1bf298 "d_1bf298"
extern Obj7 ob7_d_1bf29c;
#pragma aux ob7_d_1bf29c "d_1bf29c"
extern Obj7 ob7_d_1bf2a0;
#pragma aux ob7_d_1bf2a0 "d_1bf2a0"
extern Obj7 ob7_d_1bf2a4;
#pragma aux ob7_d_1bf2a4 "d_1bf2a4"
extern Obj7 ob7_d_1bf2a8;
#pragma aux ob7_d_1bf2a8 "d_1bf2a8"
//@ f_0c07e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese statische Initialisierungsfunktion (__STI) registriert beim Programmstart 25
 *   8-Bit-Zustandsvariablen (d_1bf248 bis d_1bf2a8, Kennungen 0x1b5 bis 0x260) in der globalen
 *   Byte-Persistenzliste d_1c212a sowie das 16-Bit-Spind-Bitfeld d_1bf2ac (Kennung 3) in der
 *   Wort-Persistenzliste d_1c2132 für die erste Ebene der Zwergenmine (mine1).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct RF700_0c07e0B;
struct OF700_0c07e0B { signed char flag; short number; char pad; OF700_0c07e0B *init(RF700_0c07e0B &r,short id,signed char f); };
struct RF700_0c07e0B {short count; OF700_0c07e0B **list; void append(OF700_0c07e0B *o) {list[count]=o;count++;}};
inline OF700_0c07e0B *OF700_0c07e0B::init(RF700_0c07e0B &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RF700_0c07e0B regF700_0c07e0B;
#pragma aux regF700_0c07e0B "d_1c212a"
extern OF700_0c07e0B obF700_0c07e0_1bf248;
#pragma aux obF700_0c07e0_1bf248 "d_1bf248"
extern OF700_0c07e0B obF700_0c07e0_1bf24c;
#pragma aux obF700_0c07e0_1bf24c "d_1bf24c"
extern OF700_0c07e0B obF700_0c07e0_1bf250;
#pragma aux obF700_0c07e0_1bf250 "d_1bf250"
extern OF700_0c07e0B obF700_0c07e0_1bf254;
#pragma aux obF700_0c07e0_1bf254 "d_1bf254"
extern OF700_0c07e0B obF700_0c07e0_1bf258;
#pragma aux obF700_0c07e0_1bf258 "d_1bf258"
extern OF700_0c07e0B obF700_0c07e0_1bf25c;
#pragma aux obF700_0c07e0_1bf25c "d_1bf25c"
extern OF700_0c07e0B obF700_0c07e0_1bf260;
#pragma aux obF700_0c07e0_1bf260 "d_1bf260"
extern OF700_0c07e0B obF700_0c07e0_1bf264;
#pragma aux obF700_0c07e0_1bf264 "d_1bf264"
extern OF700_0c07e0B obF700_0c07e0_1bf268;
#pragma aux obF700_0c07e0_1bf268 "d_1bf268"
extern OF700_0c07e0B obF700_0c07e0_1bf26c;
#pragma aux obF700_0c07e0_1bf26c "d_1bf26c"
extern OF700_0c07e0B obF700_0c07e0_1bf270;
#pragma aux obF700_0c07e0_1bf270 "d_1bf270"
extern OF700_0c07e0B obF700_0c07e0_1bf274;
#pragma aux obF700_0c07e0_1bf274 "d_1bf274"
extern OF700_0c07e0B obF700_0c07e0_1bf278;
#pragma aux obF700_0c07e0_1bf278 "d_1bf278"
extern OF700_0c07e0B obF700_0c07e0_1bf27c;
#pragma aux obF700_0c07e0_1bf27c "d_1bf27c"
extern OF700_0c07e0B obF700_0c07e0_1bf280;
#pragma aux obF700_0c07e0_1bf280 "d_1bf280"
extern OF700_0c07e0B obF700_0c07e0_1bf284;
#pragma aux obF700_0c07e0_1bf284 "d_1bf284"
extern OF700_0c07e0B obF700_0c07e0_1bf288;
#pragma aux obF700_0c07e0_1bf288 "d_1bf288"
extern OF700_0c07e0B obF700_0c07e0_1bf28c;
#pragma aux obF700_0c07e0_1bf28c "d_1bf28c"
extern OF700_0c07e0B obF700_0c07e0_1bf290;
#pragma aux obF700_0c07e0_1bf290 "d_1bf290"
extern OF700_0c07e0B obF700_0c07e0_1bf294;
#pragma aux obF700_0c07e0_1bf294 "d_1bf294"
extern OF700_0c07e0B obF700_0c07e0_1bf298;
#pragma aux obF700_0c07e0_1bf298 "d_1bf298"
extern OF700_0c07e0B obF700_0c07e0_1bf29c;
#pragma aux obF700_0c07e0_1bf29c "d_1bf29c"
extern OF700_0c07e0B obF700_0c07e0_1bf2a0;
#pragma aux obF700_0c07e0_1bf2a0 "d_1bf2a0"
extern OF700_0c07e0B obF700_0c07e0_1bf2a4;
#pragma aux obF700_0c07e0_1bf2a4 "d_1bf2a4"
extern OF700_0c07e0B obF700_0c07e0_1bf2a8;
#pragma aux obF700_0c07e0_1bf2a8 "d_1bf2a8"
struct RF700_0c07e0W;
struct OF700_0c07e0W { short flag; short number;  OF700_0c07e0W *init(RF700_0c07e0W &r,short id,short f); };
struct RF700_0c07e0W {short count; OF700_0c07e0W **list; void append(OF700_0c07e0W *o) {list[count]=o;count++;}};
inline OF700_0c07e0W *OF700_0c07e0W::init(RF700_0c07e0W &r,short id,short f) {flag=f;number=id;r.append(this);return this;}
extern RF700_0c07e0W regF700_0c07e0W;
#pragma aux regF700_0c07e0W "d_1c2132"
extern OF700_0c07e0W obF700_0c07e0_1bf2ac;
#pragma aux obF700_0c07e0_1bf2ac "d_1bf2ac"
void f_0c07e0(void) {
obF700_0c07e0_1bf248.init(regF700_0c07e0B,0x1b5,0);
obF700_0c07e0_1bf24c.init(regF700_0c07e0B,0x1b6,0);
obF700_0c07e0_1bf250.init(regF700_0c07e0B,0x1b7,0);
obF700_0c07e0_1bf254.init(regF700_0c07e0B,0x1b8,0);
obF700_0c07e0_1bf258.init(regF700_0c07e0B,0x1b9,0);
obF700_0c07e0_1bf25c.init(regF700_0c07e0B,0x1ba,0);
obF700_0c07e0_1bf260.init(regF700_0c07e0B,0x1bb,0);
obF700_0c07e0_1bf264.init(regF700_0c07e0B,0x1bc,0);
obF700_0c07e0_1bf268.init(regF700_0c07e0B,0x1bd,0);
obF700_0c07e0_1bf26c.init(regF700_0c07e0B,0x1be,0);
obF700_0c07e0_1bf270.init(regF700_0c07e0B,0x1bf,0);
obF700_0c07e0_1bf274.init(regF700_0c07e0B,0x1c0,0);
obF700_0c07e0_1bf278.init(regF700_0c07e0B,0x1c1,0);
obF700_0c07e0_1bf27c.init(regF700_0c07e0B,0x1c2,0);
obF700_0c07e0_1bf280.init(regF700_0c07e0B,0x1c3,0);
obF700_0c07e0_1bf284.init(regF700_0c07e0B,0x1c4,0);
obF700_0c07e0_1bf288.init(regF700_0c07e0B,0x1c5,0);
obF700_0c07e0_1bf28c.init(regF700_0c07e0B,0x1c6,0);
obF700_0c07e0_1bf290.init(regF700_0c07e0B,0x1c7,0);
obF700_0c07e0_1bf294.init(regF700_0c07e0B,0x1f8,0);
obF700_0c07e0_1bf298.init(regF700_0c07e0B,0x1f9,0);
obF700_0c07e0_1bf29c.init(regF700_0c07e0B,0x1fc,0);
obF700_0c07e0_1bf2a0.init(regF700_0c07e0B,0x1fd,0);
obF700_0c07e0_1bf2a4.init(regF700_0c07e0B,0x22a,0);
obF700_0c07e0_1bf2a8.init(regF700_0c07e0B,0x260,0);
obF700_0c07e0_1bf2ac.init(regF700_0c07e0W,0x3,0);
}

//@ f_0c0c80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Schauplatz-Objekt für die erste Ebene der Zwergenmine (mine1,
 *   Ortskennung 15 über f_05ff60), setzt die virtuelle Methodentabelle d_1bb350 und legt beim erstmaligen
 *   Betreten (d_1bd6c8 == 0) den Tagebucheintrag 0x803003d (f_057220) an.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0c0c80(int p1)
{
    p1 = f_05ff60(p1, 15);
    I(p1, 8) = (int)d_1bb350;
    if (EQB(d_1bd6c8, 0)) {
        d_1bd6c8 = 5;
        f_057220((int)d_1c2c00, 0x803003d, 0);
    }
    return p1;
}
//@ f_0c0cd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut das Schauplatz-Objekt der ersten Zwergenminen-Ebene (d_1bb350 /
 *   d_1bb33c) beim Verlassen des Dungeons wieder ab, setzt die temporären Statusflags d_1bf288 und d_1bf264 auf
 *   0 zurück, löscht die lokale Ereignismarkierung 0x79 (f_0697c0) und ruft den Basisdestruktor f_060030 auf.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie die Watcom-Destruktor-Flags p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0c0cd0(int p1, unsigned p2)
{
    if ((unsigned char)p2 & 4) {
        f_145234(p1, d_1bb33c);
        f_145254();
    } else {
        int member = p1 + 2;
        *(volatile int *)(p1 + 8) = (int)d_1bb350;
        d_1bf288 = 0;
        d_1bf264 = 0;
        f_0697c0(member, 0x79, 0);
        p1 = f_060030(p1, 1);
        if ((unsigned char)p2 & 2)
            operator delete((void *)p1);
    }
    return p1;
}
