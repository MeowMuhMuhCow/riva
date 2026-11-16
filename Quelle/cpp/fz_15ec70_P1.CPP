/* === Beschreibung (Katalog) ===
 * Einheit fz_15ec70 (0x15EC70 - 0x15F1B4)
 *
 * Überblick
 * Diese Einheit implementiert den Animations- und Grafik-Entpacker (VC) für die mehrbildrigen .BOB-
 * beziehungsweise Sprite-Animationsarchive des Spiels. Sie unterstützt sowohl unkomprimierte Einzelbilder
 * (Formattyp 0 und 1), LZW-/LZ-komprimierte Frames über f_147ef0 (Formattyp 2 bis 5) als auch einen zeilenweisen
 * RLE-Kopiermodus (mode 2..5 mit Fluchtwert 127) einschließlich horizontaler Spiegelung.
 === Ende Beschreibung === */
// P3 3/5 gleich (suche.py 26.10.2026, Basis fz_15ec70_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 3 gleich (vorher 2), Rest 426 (vorher 429)
// fz_15ec70.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x15EC70-0x15F1B4
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a9c70[];           // Text 0x1A9C70
extern const char d_1b95ec[];           // Text 0x1B95EC
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct VC { unsigned char *a; unsigned char *dst; unsigned char *src; short idx; short off; short mode; short *pw; short *ph; };
struct W { char z[0x266]; };
void *f_147cd0(void *p);
void f_147ef0(void *w, void *dst, void *s, unsigned n);
int f_148180(int v);
void f_1664d0(const char *a, const char *b, int c);
int f_15ed20(VC *p);
void f_014710(void *p);
#pragma aux f_014710 "*" parm [eax] modify [edx];
//@ f_15ec70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor einer Entpacker-Instanz p: Reserviert einen 100 Byte großen Arbeits-
 *   beziehungsweise Zeilenpuffer p->a auf dem Heap.
 * - Eingaben: Zeiger p auf die VC-Struktur.
 * - Rückgabewert: VC * - gibt p zurück.
 * - Wichtige Variablen:
 *   - p->a: Dynamisch reservierter Zwischenpuffer (genutzt u. a. beim horizontal gespiegelten Entpacken in
 *     f_15ed20).
 === Ende Beschreibung === */
VC *f_15ec70(VC *p)
{
  p->a = (unsigned char *)new (mark(d_1a9c70, 0x18)) char[100];
  return p;
}
//@ f_15eca0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor einer Entpacker-Instanz p: Gibt den Zwischenpuffer p->a über f_014710 frei.
 * - Eingaben: Zeiger p auf die VC-Struktur und Destruktor-Flag kp2.
 * - Rückgabewert: VC * - gibt p zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
VC *f_15eca0(VC *p, int kp2)
{
  f_014710(p->a);
  return p;
}
//@ f_15ecb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt alle Parameter für einen bevorstehenden Entpackvorgang in die Struktur p ein
 *   (Zielpuffer dst, Quellarchiv src, gewünschter Frame-Index p4, Entpackmodus p5, Rückgabezeiger für Breite pw
 *   und Höhe ph sowie Zeilen-Offset p8) und löst bei src == 0 eine Fehlermeldung über f_1664d0 aus.
 * - Eingaben: Entpacker p, Zielpuffer dst, Quelldaten src, Frame-Index p4, Modus p5, Breitenzeiger pw,
 *   Höhenzeiger ph und Zeilenabstand p8.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15ecb0(VC *p, unsigned char *dst, unsigned char *src, short p4, short p5, short *pw, short *ph, short p8)
{
  if (src == 0) f_1664d0(d_1b95ec, d_1a9c70, 0x28);
  p->dst = dst;
  p->src = src;
  p->idx = p4;
  p->mode = p5;
  p->pw = pw;
  p->ph = ph;
  p->off = p8;
}
//@ f_15ed20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht im Grafikarchiv p->src anhand des Format-Bytes b (0..5) und der Frame-Anzahl frames
 *   die Startadresse s, die Abmessungen (w, h) sowie die Datenlänge n des angeforderten Einzelbildes p->idx
 *   heraus und entpackt es je nach p->mode: Bei mode == 0 per LZ-Dekompression (f_147ef0) oder memcpy, bei mode
 *   2..5 über einen zeilenweisen Lauflängendecoder (Code 127 gefolgt von Anzahl cnt und Bytewert val, bei mode
 *   4/5 horizontal gespiegelt über p->a) und sonst per memmove.
 * - Eingaben: Zeiger p auf die vorbereitete VC-Struktur.
 * - Rückgabewert: int - Größe der entpackten Daten in Bytes.
 * - Wichtige Variablen:
 *   - b, flag: Unterste 7 Bits des ersten Archivbytes (Formattyp 0..5) und oberstes Bit 0x80 (Flag für
 *     komprimierte Größenermittlung am Blockende).
 *   - frames: Gesamtzahl der im Archiv gespeicherten Animationsphasen (*(short *)(p->src + 1)).
 *   - wk: Temporär auf dem Heap angelegter 0x266-Byte-Arbeitsbereich für den Dekompressor f_147ef0.
 === Ende Beschreibung === */
// Astra925: unabhaengig aus Demo1533d0..153970, gegen Original15ed20 abgeglichen.
// Opus W06: if(!mode) ordnet die Bloecke fuer den LatePick wie im Original; Tabellenform ohne Helfer.
int f_15ed20(VC *p)
{
    signed char b, val, cnt, code;
    short w, i, flag, h, j, x, frames;
    unsigned char *d, *s, *q, *t;
    long ret, n, acc;
    W *wk;
    { W *temp=new (mark(d_1a9c70,0x4f)) W;
      wk=temp ? (W *)f_147cd0(temp) : temp; }
    b=*(signed char *)p->src;
    flag=(signed char)(b&0x80);
    b&=0x7f;
    frames=*(short *)(p->src+1);
    { short fc=frames; frames=fc; } // haelt die Registerzuteilung wie im Original
    if(p->idx<0) p->idx=0;
    if(p->idx>frames-1) p->idx=frames-1;
    switch(b) {
    case 0:
        w=*(short *)(p->src+3);
        h=*(short *)(p->src+5);
        n=w*h;
        s=p->src+7+n*p->idx;
        break;
    case 1:
        acc=frames*4+3;
        for(i=0;i<p->idx;i++) {
            w=*(short *)(p->src+i*4+3);
            h=*(short *)(p->src+i*4+5);
            acc+=w*h;
        }
        w=*(short *)(p->src+p->idx*4+3);
        h=*(short *)(p->src+p->idx*4+5);
        n=w*h;
        s=p->src+acc;
        break;
    case 2: case 4:
        w=*(short *)(p->src+3);
        h=*(short *)(p->src+5);
        acc=frames*4+7;
        for(i=0;i<p->idx;i++) acc+=*(long *)(p->src+i*4+7);
        n=*(long *)(p->src+p->idx*4+7);
        s=p->src+acc;
        break;
    case 3: case 5:
        acc=frames*8+3;
        for(i=0;i<p->idx;i++) acc+=*(long *)(p->src+i*8+7);
        w=*(short *)(p->src+p->idx*8+3);
        h=*(short *)(p->src+p->idx*8+5);
        n=*(long *)(p->src+i*8+7);
        s=p->src+acc;
        break;
    }
    if(!p->mode) {
        if(flag) {
            ret=*(long *)s;
            q=s;
            q+=ret-4;
            ret=*(long *)q;
            ret=f_148180(ret)>>8;
        } else ret=w*h;
        if(b!=0 && b!=1) f_147ef0(wk,p->dst,s,n);
        else memcpy(p->dst,s,n);
    } else if(p->mode>=2 && p->mode<=5) {
        d=p->dst;
        for(i=0;i<h;i++) {
            if(p->mode==4 || p->mode==5) t=p->a; else t=d;
            x=0;
            while(x<w) {
                code=*s++;
                if(code==127) {
                    cnt=*s++;
                    val=*s++;
                    for(j=0;j<cnt;j++) *(t+x+j)=val;
                    x+=cnt;
                } else {
                    *(t+x)=code;
                    x++;
                }
            }
            if(p->mode==4 || p->mode==5) {
                t+=w-1;
                for(j=0;j<w;j++) *d++=*t--;
            }
            if(p->mode==2) d+=p->off;
            else if(p->mode==4) d+=p->off-w;
            else if(p->mode==3) d+=w;
        }
    } else {
        memmove(p->dst,s,n);
        ret=n;
    }
    *p->pw=w;
    *p->ph=h;
    delete wk;
    return ret;
}
//@ f_15f130
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Komfortfunktion, die über f_15ecb0 sämtliche Entpackparameter in p setzt und anschließend
 *   sofort das Entpacken über f_15ed20(p) ausführt.
 * - Eingaben: Entpacker p, Zielpuffer dst, Quelldaten src, Frame-Index p4, Modus p5, Breitenzeiger pw,
 *   Höhenzeiger ph und Zeilenabstand p8.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15f130(VC *p, unsigned char *dst, unsigned char *src, int p4, int p5, short *pw, short *ph, int p8)
{
  f_15ecb0(p, dst, src, p4, p5, pw, ph, p8);
  p8 = (p8 & 0) ? 0 : p8; // haelt die Registerzuteilung wie im Original
  f_15ed20(p);
}
