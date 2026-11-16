/* === Beschreibung (Katalog) ===
 * Einheit equip (0x068170 - 0x068f40)
 *
 * Überblick
 * Die Einheit equip (equip.cpp) steuert die grafischen Ausrüstungs- und Anlege-Animationen im Inventarbildschirm
 * (Archivbereich d_1c2a80 == 0x30000). Wenn der Spieler im Charakterbogen ein Kleidungs- oder Rüstungsteil
 * anlegt oder ablegt, ermittelt diese Einheit die passende Animationsressource und zoomt das Bild in einer
 * flüssigen 17- bzw. 22-stufigen Skalierungsanimation vom Ausrüstungsslot zur Charakterfigur und wieder zurück.
 === Ende Beschreibung === */
// P3 0/4 gleich (suche.py 24.10.2026, Basis equip_P1.CPP)
// equip.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0681F0-0x068F40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_010a20(int p1, int p2);                           // reg eax edx stapel 0
int f_0113d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_011410(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0114e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0115c0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0116a0(int p1);                                   // reg eax stapel 0
int f_04aee0(int p1);                                   // reg eax stapel 0
int __cdecl f_099ef0(int p1, int p2, int p3);   // cdecl, drei Stack-Argumente
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0fac10(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0fad20(int p1, int p2);                           // reg eax stapel 0
int f_0fade0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fafb0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fb0c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0fb120(int p1);                                   // reg eax stapel 0
int f_0fb220(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0fb3a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_1459d0(int p1, int p2);                                   // reg eax stapel 0
int f_145a00(int p1, int p2);                           // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_145b50(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_145b70(int p1);                                   // reg eax stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
short f_149360(int p1, int p2);
int f_149e2e(int p1, int p2);                           // reg - stapel 0

extern short d_1a1a46;
extern int d_1a1a82;
extern int d_1a34e0;
extern volatile short d_1bc5f6;
extern int d_1bc928;
extern int d_1bdbd4;
extern int d_1c2a80;
extern const char d_1a1a28[];
#define A(x) ((int)&(x))
#define P(x) ((int)&(x))
#define FLT volatile int
struct B12 { char x[12]; };
struct B320 { char x[0x140]; };
struct B164 { char x[164]; };
struct B13e { char x[0x13e]; };

#define BRK break

//@ f_0681f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt zu einem Geschlechtsflag a (0 = männlich, != 0 = weiblich), einem Ausrüstungsslot s
 *   (0, 1, 2/11, 4/13, 6, 7, 8, 14) und einer Gegenstands-ID c die zugehörige Animations-Ressourcenkennung
 *   (0x30010..0x30020), sofern das Inventararchiv d_1c2a80 == 0x30000 aktiv ist und der Gegenstand nicht in der
 *   Ausnahmeliste d_1a1a82 (f_149360) steht.
 * - Eingaben und Rückgabe: Eingaben sind das Geschlechtsflag a (eax, char), der Ausrüstungsslot s (edx, short)
 *   und die Gegenstands-ID c (ebx, short); zurückgegeben wird die Ressourcen-ID (int in eax) oder -1, falls
 *   keine Animation existiert.
 * - Wichtige Variablen: d_1c2a80 bezeichnet das aktuell geladene UI-Archiv (0x30000), d_1a1a82 die
 *   Ausschlusstabelle für Gegenstands-IDs.
 === Ende Beschreibung === */
int f_0681f0(char a, short s, short c)
{
    int r = -1;
    if (d_1c2a80 == 0x30000) {
        short cc = c;
        if (f_149360(cc, A(d_1a1a82)) == r) {
            if (!a) {
                switch (s) {
                case 0:
                    r = 0x30011;
                    if (cc == 0xab || cc == 0xd9 || cc == 0xf5 || cc == 0x109) r = 0x3001f;
                    break;
                case 8: r = 0x30013; BRK;
                case 1: r = 0x3001b; BRK;
                case 2:
                case 0xb: r = 0x30017; BRK;
                case 4:
                case 0xd: r = 0x30015; BRK;
                case 6: r = 0x3001d; BRK;
                case 0xe: r = 0x30019; BRK;
                case 7: r = 0x30020; BRK;
                }
            } else {
                switch (s) {
                case 0:
                    r = 0x30010;
                    if (cc == 0xab || cc == 0xd9 || cc == 0xf5 || cc == 0x109) r = 0x3001e;
                    break;
                case 8: r = 0x30012; BRK;
                case 1: r = 0x3001a; BRK;
                case 2:
                case 0xb: r = 0x30016; BRK;
                case 4:
                case 0xd: r = 0x30014; BRK;
                case 6: r = 0x3001c; BRK;
                case 0xe: r = 0x30018; BRK;
                case 7: r = 0x30020; BRK;
                }
            }
        }
    }
    return r;
}

//@ f_068380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt beim An- oder Ablegen eines Ausrüstungsgegenstands c in Slot s die vollständige Zoom-
 *   und Abspielsequenz ab: Ermittelt über f_0681f0 die Animations-ID, blendet ein 17-stufiges aufwachsendes
 *   Vorschaufenster von den Slot-Koordinaten d_1a1a46[s] zur Bildschirmmitte auf (f_0fb0c0), spielt die
 *   Animation o an Position (213, 127) ab (f_0115c0/f_0116a0) und zoomt das Fenster anschließend in 17 Schritten
 *   wieder zusammen.
 * - Eingaben und Rückgabe: Eingaben sind das Geschlechtsflag a (eax, char), der Slotindex s (edx, int) und die
 *   Gegenstands-ID c (ebx, short); die Funktion gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle d_1a1a46 enthält die Startkoordinaten der einzelnen Ausrüstungsslots,
 *   d_1bc5f6 synchronisiert die Bildschirmausgabe mit dem Timer-Tick und d_1a34e0 ist der VGA-Bildschirmpuffer.
 === Ende Beschreibung === */
void f_068380(char a, int s, short c)
{
    int f_0681f0(int,int,int);
    int __cdecl f_149e2e(void*,int);
    struct F { B320 obj; B12 a,b,c,d,e,f; int flag,offset;
      struct {unsigned char b,g,r,pad;} color;
      int x,y,w; } st; short height,down,up;
#define o st.obj
#define ra st.a
#define rb st.b
#define rc st.c
#define rd st.d
#define re st.e
#define rf st.f
#define fl st.flag
#define off st.offset
#define l2c st.color.b
#define l2b st.color.g
#define l2a st.color.r
#define l28 st.x
#define l24 st.y
#define l20 st.w
#define l1c down
#define l18 up
#define l14 height
    
    int code=0; code=f_0681f0((int)(signed char)a,(int)(short)s,(int)c);
    int p,i;
    l2c=0x28; l2b=0x14; l2a=0;
    p=f_04aee0(d_1bc928);
    d_1bc928=(d_1bc928&0)?0:d_1bc928; d_1a34e0=(d_1a34e0&0)?0:d_1a34e0; // Zwei Namen fuer die originalen Stapelplaetze
    if(code!=-1) {
      if(f_0d3860()==1) { code = (code & 0) ? 0 : code; f_0d2710(); fl=1; } else fl=0; // Haelt die lokale Kopie von code
      f_09ac80(d_1a34e0,0,0);
      f_0104b0(P(o),code,0,0); f_011410(P(o),0,0x21);
      f_149e2e(&l2c,0x21);
      f_0fac80(P(ra),0x67,0x43); f_0fb120(P(ra));
      f_0113d0(P(o),P(l28),P(l24),P(l20),P(l14));
      f_0fac80(P(rb),(short)l20,(short)l14); f_010a20(P(o),P(rb));
      f_0fb3a0(P(ra),P(rb),(short)l28,(short)l24,0); code=(short)s; f_0fad20(P(rb),0);
      d_1bc5f6=1;
      for(l18=0,off=code*4;(i=(short)l18)<=0x10;++l18) {
        union {int v;unsigned short a;} ox; ox.v=off; ox.a=(ox.a&0)?0:ox.a; ox.a=(ox.a&0)?0:ox.a; // Alias-Nutzwert des X-Offsets
        int delta = (short)((0xd4-*(short*)((int)&d_1a1a46+ox.v))*i/16);
        int xpos = *(short*)((int)&d_1a1a46+ox.v)-0x58; xpos += delta; l28=xpos;
        l24=(short)((0x7e-*(short*)((int)&d_1a1a46+off+2))*i/16)+(*(short*)((int)&d_1a1a46+off+2)-0x38);
        l20=(short)(i*0x59/16)+0xe; int h=(short)(i*0x35/16)+0xe; int w=(short)l20; h=(h&0)?0:h; l14=h; // Hoehen-Web vor Aufruf-Konvertierung
        f_0fac80(P(rf),w,(short)h); f_0fb0c0(P(ra),P(rf));
        f_09ade0(p,0,0); f_0fade0(P(rf),p,(short)(l28+0x59),(short)(l24+0x39));
        f_1481a0(A(d_1bdbd4),p,(short)(l28+0x58),(short)(l24+0x38),(short)(l20+2),(short)(l14+2),0x21);
        while(!d_1bc5f6);
        memcpy((void*)d_1a34e0,(void*)p,0xfa00); d_1bc5f6=0; f_0fad20(P(rf),0);
      }
      f_0115c0(P(o),0xd5,0x7f,0); f_0116a0(P(o)); f_0d4800(10);
      f_0fac80(P(rc),0x67,0x43); f_0fb120(P(rc));
      f_0113d0(P(o),P(l28),P(l24),P(l20),P(l14));
      f_0fac80(P(rd),(short)l20,(short)l14); f_010a20(P(o),P(rd));
      f_0fb3a0(P(rc),P(rd),(short)l28,(short)l24,0); f_0fad20(P(rd),0);
      for(l1c=0x10;(i=(short)l1c)>=0;--l1c) {
        l20=(short)(i*0x65/16)+2; l14=(short)(i*0x41/16)+2;
        l28=(0x67-(short)l20)/2+0x7e; l24=(0x43-(short)l14)/2+0x47;
        f_0fac80(P(re),(short)l20,(short)l14); f_0fb0c0(P(rc),P(re));
        f_09ade0(p,0,0); f_0fade0(P(re),p,(short)(l28+0x59),(short)(l24+0x39));
        f_1481a0(A(d_1bdbd4),p,(short)(l28+0x58),(short)(l24+0x38),(short)(l20+2),(short)(l14+2),0x21);
        while(!d_1bc5f6);
        memcpy((void*)d_1a34e0,(void*)p,0xfa00); d_1bc5f6=0; f_0fad20(P(re),0);
      }
      while(!d_1bc5f6);
      f_09ade0(p,0,0); f_09aed0(0); memcpy((void*)d_1a34e0,(void*)p,0xfa00);
      f_0fad20(P(rc),0); f_0fad20(P(ra),0); f_010590(P(o),0);
      if(fl==1) f_0d26e0();
    }
#undef o
#undef ra
#undef rb
#undef rc
#undef rd
#undef re
#undef rf
#undef fl
#undef off
#undef l2c
#undef l2b
#undef l2a
#undef l28
#undef l24
#undef l20
#undef l1c
#undef l18
#undef l14
}
//@ f_068960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt die Spezialanimation 0x30022 mit dem Hintergrundbild 0x30023 im Inventar (d_1c2a80 ==
 *   0x30000) ab: Zoomt das Bild 0x30023 in 22 Schritten (0..21) im Bereich (92, 40) auf, führt die Animation
 *   0x30022 aus und verkleinert den Ausschnitt danach in 22 Schritten wieder, bevor der ursprüngliche
 *   Hintergrund k wiederhergestellt wird.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Die lokalen Bildstrukturen k, h, g, m, m2 und n (RivaRasterImage) verwalten den
 *   gesicherten Hintergrund und die skalierten Zwischenbilder.
 === Ende Beschreibung === */
void f_068960()
{
    struct B320 o;
    struct B164 o2;
    struct B12 g, h, k, m2, m, n;
    FLT fl;
    int v230, v234, v238; short v23c;
    short i, a15;
    if (d_1c2a80 == 0x30000) {
        f_0fac10(P(k), 0x7b, 0x78, f_04aee0(d_1bc928));
        f_0fac10(P(h), 0x7b, 0x78, f_04aee0(d_1bc928) + 0x7d00);
        if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
        f_0fafb0(P(k), d_1a34e0, 0x5c, 0x28);
        f_0fac80(P(g), 0x67, 0x43);
        f_0fb120(P(g));
        f_1459b0(P(o2));
        f_145a00(P(o2), 0x30023);
        f_145b50(P(o2), P(v234), P(v230));
        f_099ef0(f_145b40(P(o2)), 0, 0x20);
        f_0fac10(P(n), (short)v234, (short)v230, f_145b70(P(o2)));
        f_0fb3a0(P(g), P(n), 3, 0, 0);
        f_0fad20(P(n), 0);
        f_1459d0(P(o2), 0);
        d_1bc5f6 = 1;
        for (i = 0; i <= (unsigned short)0x15; i++) {
            v234 = (short)(i * 0x5e / 0x15) + 9;
            v230 = (short)(i * 0x3a / 0x15) + 9;
            a15 = (0x67 - (short)v234) / 2 + 0xf;
            v23c = (0x43 - (short)v230) / 2 + 0x2e;
            f_0fac80(P(m), (short)v234, (short)v230);
            f_0fb0c0(P(g), P(m));
            f_0fb3a0(P(h), P(k), 0, 0, 0);
            f_0fb3a0(P(h), P(m), (short)(a15 + 1), (short)(v23c + 1), 0);
            f_0fb220(P(h), a15, (short)v23c, (short)(v234 + 2), (short)(v230 + 2), 0xb5);
            while (!d_1bc5f6) ;
            d_1bc5f6 = (short)(f_0fade0(P(h), d_1a34e0, 0x5c, 0x28), 0);
            f_0fad20(P(m), 0);
        }
        f_0fad20(P(g), 0);
        f_0104b0(P(o), 0x30022, 0, 0);
        f_0114e0(P(o), P(k));
        f_0115c0(P(o), 0x5c, 0x28, 0);
        f_0116a0(P(o));
        for (i = 0x15; i >= 0; i = i - 1) {
            v234 = (short)(i * 0x65 / 0x15) + 2;
            v230 = (short)(i * 0x41 / 0x15) + 2;
            a15 = (0x67 - (short)v234) / 2 + 0xf;
            v238 = (0x43 - (short)v230) / 2 + 0x2e;
            f_0fac80(P(m2), (short)v234, (short)v230);
            f_0fb3a0(P(h), P(k), 0, 0, 0);
            f_0fb3a0(P(h), P(m2), (short)(a15 + 1), (short)(v238 + 1), 0);
            f_0fb220(P(h), a15, (short)v238, (short)(v234 + 2), (short)(v230 + 2), 0xb5);
            while (!d_1bc5f6) ;
            f_0fade0(P(h), d_1a34e0, 0x5c, 0x28);
            d_1bc5f6 = 0;
            f_0fad20(P(m2), 0);
        }
        while (!d_1bc5f6) ;
        f_0fade0(P(k), d_1a34e0, 0x5c, 0x28);
        f_010590(P(o), 0);
        if (fl == 1) f_0d26e0();
        f_0fad20(P(h), 0);
        f_0fad20(P(k), 0);
    }
}

//@ f_068e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt im Inventarmodus (d_1c2a80 == 0x30000) die Animation 0x30021 im Rechteck (88, 56) der
 *   Größe 144 x 86 Pixel ab, wobei der Bildschirmhintergrund zuvor in einem temporären Puffer r gesichert und
 *   nach Ende der Animation wiederhergestellt wird.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: r (B12) sichert den Bildschirmausschnitt, p (B13e *) ist das temporäre Animationsobjekt.
 === Ende Beschreibung === */
void f_068e40()
{
    struct B12 r;
    FLT fl;
    struct B13e *p;
    struct B13e *t;
    if (d_1c2a80 == 0x30000) {
        f_0fac80(P(r), 0x90, 0x56);
        t = new (mark(d_1a1a28, 0x17c)) B13e;
        p = t ? (struct B13e *)f_0104b0((int)t, 0x30021, 0, 0) : t;
        if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
        f_0fafb0(P(r), d_1a34e0, 0x58, 0x38);
        f_0114e0((int)p, P(r));
        f_0115c0((int)p, 0x58, 0x38, 0);
        f_0116a0((int)p);
        f_0fade0(P(r), d_1a34e0, 0x58, 0x38);
        if (p) delete (void *)f_010590((int)p, 0);
        if (fl == 1) f_0d26e0();
        f_0fad20(P(r), 0);
    }
}
