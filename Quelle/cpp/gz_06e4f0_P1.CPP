/* === Beschreibung (Katalog) ===
 * Einheit gz_06e4f0 (0x06e4f0 - 0x06fad0)
 *
 * Überblick
 * Die Einheit gz_06e4f0 enthält die zentrale Befehlsausführung für Schritt-, Dreh- und Effektkommandos von
 * Kampfsprites (f_06e4f0) sowie die Kernroutinen zum Aufbau von Dreh-, Stand-, Nahkampfangriffs- und
 * Paradesequenzen für Helden (f_06e9e0-f_06efc0) und Monster (f_06f400-f_06f850).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/10 gleich (suche.py 30.10.2026, Basis gz_06e4f0_P1.CPP)
// gz_06e4f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06E4F0-0x06FAD0
#include <string.h>
#include "RIVAMEM.H"

struct E { char d; char a; char b; char c; };
struct R { int f0; char p4[7]; E e[39]; };
short f_030d00(int p1, int p2);

short f_071f70(int p1, int p2, int p3);
int f_072940(int p1);
int f_07a470(int p1, int p2, int p3);
int f_07a4d0(int p1, int p2, int p3);
int f_07a560(int p1, int p2, R *p3);
void f_0cfc80(int p1, int p2);
unsigned char f_0cfdc0(int p1);
int f_0d06c0(int p1);
int f_0d4a60(int p1);
int f_0727e0(int p1);
void f_06ebf0(int p1, int p2, R *p3, short p4);
signed char f_043470(int p1, int p2);
char *f_07ea60(char *p1, char p2);
void f_069a00(int p1, void *p2);
void f_06e9e0(int p1, int p2, short p3, short p4, short *p5, R *p6, short p7);
int f_0722a0(int p1, int p2);
signed char f_043490(int p1);
int f_0728f0(int p1);
signed char f_072440(int p1, int p2);
short f_071fb0(int p1, int p2);
signed char f_0cfef0(int p1);
signed char f_0cfe30(int p1);
signed char f_0cfc70(int p1);
signed char f_0cf990(int p1);
signed char f_0cfc50(int p1, int p2);
signed char f_0d01a0(int p1);
void f_0d01b0(int p1, int p2);
int f_06d380(int p1, int p2, short *p3, R *p4);
unsigned short f_043450(int p1);
void f_043460(int p1, int p2);
short f_030d80(int p1);
void f_145300(void *p, int c, unsigned n);
extern signed char d_1bd918;
extern short d_1bd920;
extern unsigned short d_1bd928;
extern char d_1a2744[];
extern char d_1a2748[];
extern char d_1a2758[];
extern char d_1a2764[];
extern char d_1a2768[];
extern char d_1a276c[];
extern char d_1a2774[];
extern char d_1a277c[];
extern char d_1a2784[];

#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern unsigned char d_1a2734;
extern unsigned char d_1a274c;
extern unsigned char d_1a2750;
extern unsigned char d_1a2754;
extern unsigned char d_1a9820;
extern unsigned char d_1bd93c;
extern unsigned char d_1c2d1c;
extern unsigned char d_1c2edc;
int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
short C030d80_1(int);
#pragma aux C030d80_1 "f_030d80" modify exact [eax];
int C042470_1(int);
#pragma aux C042470_1 "f_042470" modify exact [eax];
int C0424d0_1(int);
#pragma aux C0424d0_1 "f_0424d0" modify exact [eax];
int C0424e0_1(int);
#pragma aux C0424e0_1 "f_0424e0" modify exact [eax];
int C0425f0_1(int);
#pragma aux C0425f0_1 "f_0425f0" modify exact [eax];
int C043490_1(int);
#pragma aux C043490_1 "f_043490" modify exact [eax];
int C0434a0_2(int,int);
#pragma aux C0434a0_2 "f_0434a0";
int C06a5b0_2(int,int);
#pragma aux C06a5b0_2 "f_06a5b0" modify exact [eax edx];
int C06a670_3(int,int,int);
#pragma aux C06a670_3 "f_06a670" modify exact [eax edx];
int C06a710_2(int,int);
#pragma aux C06a710_2 "f_06a710" modify exact [eax edx];
int C071f20_2(int,int);
#pragma aux C071f20_2 "f_071f20" modify exact [eax edx];
short C071f70_3(int,int,int);
#pragma aux C071f70_3 "f_071f70" modify exact [eax edx];
int C07ea20_2(int,int);
#pragma aux C07ea20_2 "f_07ea20" modify exact [eax edx];
int C07eb00_2(int,int);
#pragma aux C07eb00_2 "f_07eb00" modify exact [eax edx];
int C09c750_1(int);
#pragma aux C09c750_1 "f_09c750";
int C0cfc80_2(int,int);
#pragma aux C0cfc80_2 "f_0cfc80";
int C0d00c0_1(int);
#pragma aux C0d00c0_1 "f_0d00c0" modify exact [eax];
int C0d06a0_1(int);
#pragma aux C0d06a0_1 "f_0d06a0" modify exact [eax];
int C0d0730_1(int);
#pragma aux C0d0730_1 "f_0d0730" modify exact [eax];
int C0d0ac0_1(int);
#pragma aux C0d0ac0_1 "f_0d0ac0" modify exact [eax];
int C147323_7(int,int,int,int,int,int,int);
#pragma aux C147323_7 "f_147323" modify exact [eax ebx ecx edx];
//@ f_06e4f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen von einer Kampfanimation ausgelösten Bewegungs-, Dreh- oder Endbefehl command für
 *   den Kampfraster-Eintrag p (und bei zweiteiligen Großmonstern auch für das gekoppelte Partnerteil mate) aus:
 *   Die Codes 1, 3, 5, 7 verschieben die Figur um ein Feld in die jeweilige Richtung und spielen
 *   Schrittgeräusche (0xc0008, 0xc0015, 0xc0010) ab; Code 29 (0x1d) löscht ein beendetes Effekt-Sprite aus
 *   d_1bd93c; Code 34 (0x22) rechnet Bildschirmkoordinaten eines fliegenden Projektils in Rasterkoordinaten um;
 *   die Codes 30..33 setzen die neue Blickrichtung (0..3) und richten das Partnerteil mate anhand der
 *   Offsettabelle d_1a2734 neu aus.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Kampfraster-Eintrag p (edx, char *) und
 *   der Befehlscode command (ebx, unsigned char); kein Rückgabewert (void).
 * - Wichtige Variablen: rec und mate zeigen auf die beiden Hälften einer Figur (oder nur rec = p bei einfeldigen
 *   Figuren), d_1a2734 enthält die Relativversätze für Großmonster in allen vier Richtungen.
 === Ende Beschreibung === */
static inline int TAB29(){return ND32(d_1bd93c);}
int sound492(int,int,unsigned short,unsigned short,int,short,unsigned short);
#pragma aux sound492 "f_147323" modify exact [eax ebx ecx edx esp];
void f_06e4f0(int self,char *p,unsigned char command)
{
    char *rec,*mate;short y,x,mx,my,i,v;int found,moved,hero,sample;
    found=0;
    if(NB(p,13)!=(unsigned char)255){
        if(NB(p,13)<=20){mate=(char *)C07eb00_2(self+0x39,(unsigned char)(NB(p,13)+20));rec=p;}
        else{rec=(char *)C07eb00_2(self+0x39,(unsigned char)(NB(p,13)-20));mate=p;}
        if(mate){mx=(signed char)mate[0];my=(signed char)mate[1];}
    }else{rec=p;mate=0;mx=my=0;}
    x=(signed char)rec[0];moved=0;y=(signed char)rec[1];
    switch(command){
    case 1:moved=1;x++;mx++;break;
    case 3:moved=1;y--;my--;break;
    case 5:moved=1;x--;mx--;break;
    case 7:moved=1;y++;my++;break;
    case 29:
        if(rec==p){
            for(i=0;i<(short)10;i++){int t=TAB29();int id=NI(rec,15);int *q=(int *)(i*4+t);{int g=ND32(d_1a9820);ND32(d_1a9820)=g;} /* Codefreier Global-Roundtrip fuer die Registerfolge */ if(id==*q){*q=0;break;}}
            {int o=NI(rec,15);if(o){C014710_1(C06a710_2(o,0));}}
            NB(self,0x292)=1;C09c750_1(NA(d_1c2d1c));
        }
        if(C07ea20_2(self+0x39,NB(p,9)))NB(p,31)=1;
        break;
    case 0x23:
        if (rec == p) {
            for (i = 0; i < (short)10; i++) {
                if ((*(int **)&d_1bd93c)[i] == NI(rec, 0xf)) {
                    found = 1;
                    C06a5b0_2((*(int **)&d_1bd93c)[i], 0);
                    break;
                }
            }
            {short w,u;
                if (!found) {
                    C06a5b0_2(NI(rec, 0xf), 0);
                    if (mate) {
                        C06a5b0_2(NI(mate, 0xf), 0);
                    }
                }
                break;
    case 34:
                C06a670_3(NI(p,15),(int)&u,(int)&w);v=(short)(w*2+u-213);if(v<0)v-=19;NB(p,0)=(unsigned char)(v/20-1);
                v=(short)(u-w*2+251);if(v<0)v-=19;NB(p,1)=(unsigned char)(v/20-1);NB(p,32)=1;
            }
        }
        break;
    case 30:
        C0cfc80_2(C0d0ac0_1(NB(rec,9)),0);
        if(mate){mate[0]=(char)(rec[0]+(signed char)NB((void *)NA(d_1a2734),0));mate[1]=(char)(rec[1]+(signed char)NB((void *)NA(d_1a2734),2));NB(mate,32)=1;}break;
    case 31:
        C0cfc80_2(C0d0ac0_1(NB(p,9)),1);
        if(mate){mate[0]=(char)(rec[0]+(signed char)NB((void *)NA(d_1a2734),4));mate[1]=(char)(rec[1]+(signed char)NB((void *)NA(d_1a2734),6));NB(mate,32)=1;}break;
    case 33:
        C0cfc80_2(C0d0ac0_1(NB(p,9)),3);
        if(mate){mate[0]=(char)(rec[0]+(signed char)NB((void *)NA(d_1a2734),12));mate[1]=(char)(rec[1]+(signed char)NB((void *)NA(d_1a2734),14));NB(mate,32)=1;}break;
    case 32:
        C0cfc80_2(C0d0ac0_1(NB(p,9)),2);
        if(mate){mate[0]=(char)(rec[0]+(signed char)NB((void *)NA(d_1a2734),8));mate[1]=(char)(rec[1]+(signed char)NB((void *)NA(d_1a2734),10));NB(mate,32)=1;}break;
    }
    if(moved){
        if((signed char)NB(rec,12)==2) sound492(NA(d_1c2edc),0xc0008,0x7fff,0x8000,(sample=ND32(d_1a9820)),0,1);
        else if((signed char)NB(rec,12)==1){
          hero=C0d0ac0_1(NB(rec,9));
          if((char)C0d00c0_1(hero)||C0d06a0_1(hero)) sound492(NA(d_1c2edc),0xc0015,0x7fff,0x8000,(sample=ND32(d_1a9820)),0,1);
          else if(C0d0730_1(hero)) sound492(NA(d_1c2edc),0xc0008,0x7fff,0x8000,(sample=ND32(d_1a9820)),0,1);
          else sound492(NA(d_1c2edc),0xc0010,0x7fff,0x8000,(sample=ND32(d_1a9820)),0,1);
        }
        if(C071f20_2(x,y)){NB(rec,31)=1;if(mate)NB(mate,31)=1;}
        else{rec[0]=(char)x;rec[1]=(char)y;NB(rec,32)=1;if(mate){mate[0]=(char)mx;mate[1]=(char)my;NB(mate,32)=1;}}
    }
}
//@ f_06e9e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hängt für einen Helden who die Zwischenframes einer Drehung von Blickrichtung from nach to an
 *   den Sequenzpuffer out (ab Index *count) an und aktualisiert die gespeicherte Blickrichtung des Helden über
 *   f_0434a0(who, to).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Heldenzeiger who (edx), die
 *   Startrichtung from (ebx, short), die Zielrichtung to (ecx, short) sowie auf dem Stapel der Indexzeiger count
 *   (short *), der Sequenzpuffer out (R *) und das Schnellflag fast (short); kein Rückgabewert (void).
 * - Wichtige Variablen: base wählt den Basis-Animationsindex je nach Kampftyp (1, 0xb3 bei Typ 4, 0xbb bei Typ
 *   6).
 === Ende Beschreibung === */
#define N630_STEP(p,n,v) do {NB(p,12+*(n)*4)=(unsigned char)(v);NB(p,13+(*(n))++*4)=0;} while(0)
void f_06e9e0(int self,int who,short from,short to,short *count,R *out,short fast)
{
    short base=1,kind=(short)C030d80_1(who),steps;union { short whole; unsigned char byte; } id;
    unsigned short twice;
    if(kind==4)base=0xb3;else if(kind==6)base=0xbb;
    twice=from*2;
    if(from != to){steps=(short)(C071f70_3(self,from,to)*2);from=(short)twice;id.byte=(char)(base+from);
        // Haelt die Store-Folge bei negativem Schritt wie im Original
        if(steps==-2){if(!fast){N630_STEP(out,count,id.byte);N630_STEP(out,count,id.byte);}from--;if(from<0)from=7;N630_STEP(out,count,(short)(base & 0xffff)+from);{ NB(out,12+*count*4)=(unsigned char)(base+to*2); *(volatile unsigned char *)((char *)out+13+(*count)++*4)=0; }C0434a0_2(who,(signed char)to);return;}
        if(steps==2 && !fast){N630_STEP(out,count,id.byte);N630_STEP(out,count,id.byte);}
        do{from++;if(from>7)from=0;N630_STEP(out,count,base+from);steps--;}while(steps > 0);
        C0434a0_2(who,(signed char)to);
    }else if(!fast){from=(short)twice;NB(out,12+*count*4)=(unsigned char)(base+from);NB(out,14+*count*4)=4;NB(out,13+(*count)++*4)=3;}
}


//@ f_06ebf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt für einen Helden who die zu seinem aktuellen Zustand (tot 9, bewusstlos/versteinert
 *   d_1a2754, gefesselt/gelähmt d_1a2758, sonst waffenabhängig d_1a274c/d_1a2750/d_1a2748) und seiner
 *   Blickrichtung passende Grundpose in den Sequenzeintrag out->e[index].
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem self (eax), der Heldenzeiger who (edx), der
 *   Sequenzpuffer out (ebx, R *) und der Eintragindex index (ecx, short); kein Rückgabewert (void).
 * - Wichtige Variablen: Die Richtungstabellen d_1a2748..d_1a2758 liefern den Animationsindex für die vier
 *   Blickrichtungen.
 === Ende Beschreibung === */
void f_06ebf0(int self,int who,R *out,short index)
{
 if((char)C042470_1(who)) out->e[index].a=9;
 else if((char)C0424d0_1(who)||(char)C0425f0_1(who))out->e[index].a=((char *)&d_1a2754)[(signed char)C043490_1(who)];
 else if((char)C0424e0_1(who)){ out->e[index].a=((char *)&d_1a2758)[(signed char)C043490_1(who)];  }
 else {
  int kind=(short)C030d80_1(who);
  if(kind==4){ out->e[index].a=((char *)&d_1a274c)[(signed char)C043490_1(who)];  }
  else if(kind==6){ out->e[index].a=((char *)&d_1a2750)[(signed char)C043490_1(who)];  }
  else out->e[index].a=((char *)&d_1a2748)[(signed char)C043490_1(who)];
 }
 out->e[index].b=0;
}

//@ f_06ed10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Kampfsprite eines Helden p2 auf seine dauerhafte Ruhe-/Standanimation (ermittelt
 *   über f_06ebf0, mit Endlosmodus b = 4, c = -1) zurück.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Heldenzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, R *); zurückgegeben wird der Zeiger auf das Kampfsprite (int in eax).
 * - Wichtige Variablen: q ist der Kampfraster-Eintrag des Helden (f_07ea60).
 === Ende Beschreibung === */
int f_06ed10(int p1, int p2, R *p3)
{
    unsigned char f_043470(int);
    char *q;
    f_145300(p3, 0, 0xa4);
    p3->f0 = f_0727e0(p2);
    f_06ebf0(p1, p2, p3, 0);
    p3->e[0].b = 4;
    ((char&)p3->e[0].c) = -1;
    p3->e[1].a = -1;
    q = f_07ea60((char *)(p1 + 0x39), f_043470(p2));
    f_069a00(*(int *)(q + 0xf), p3);
    return *(int *)(q + 0xf);
}

//@ f_06ed80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen Helden p2 die Nahkampfangriffs-Sequenz im Puffer p3 auf: Dreht den Helden über
 *   f_06e9e0 zum Ziel (U), trägt die waffenabhängige Schlaganimation aus d_1a276c (bzw. waffenlos d_1a2764) ein
 *   - bei Doppelangriff *(signed char *)(p1 + 0x1ee) zweimal hintereinander -, ergänzt bei tödlichem
 *   Gegentreffer *(signed char *)(p1 + 0x1f0) den Code 0x26 und schließt mit der Grundpose f_06ebf0 ab.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Heldenzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, R *); zurückgegeben wird das Kampfsprite (int in eax).
 * - Wichtige Variablen: v (f_030d00) ist die Waffenanimationsklasse des Helden, p1 + 0x1ee und p1 + 0x1f0 sind
 *   Flags für Doppelschlag und Sturz/Tod.
 === Ende Beschreibung === */
int f_06ed80(int p1, int p2, R *p3)
{
    int f_030d00_x(int);
    unsigned char f_042470_x(int);
    short f_042a60_x(int, int);
    unsigned char f_043470(int);
    #pragma aux f_030d00_x "f_030d00" parm [eax] modify exact [eax]
    #pragma aux f_042470_x "f_042470" parm [eax] modify exact [eax]
    #pragma aux f_042a60_x "f_042a60" parm [eax] [edx] modify exact [eax edx]
    short v; short U; short idx;
    idx = 0;
    if (f_0d4a60(p2) || f_042470_x(p2)) {
        v = f_030d00_x(p2);
        if (f_042a60_x(p2, 3) == 0x85 || (f_042a10((struct hero *)(p2)) && v == 1)) v = -1;
        if (f_042400((struct hero *)(p2)) == 7 || f_042400((struct hero *)(p2)) == 8) v = -1;
        f_145300(p3, 0, 0xa4);
        p3->f0 = f_0727e0(p2);
        short b = f_043490(p2);
        U = f_0722a0(p1, p2);
        f_06e9e0(p1, p2, b, U, &idx, p3, 0);
        if (v != -1) p3->e[idx].a = d_1a276c[v * 4 + U]; else p3->e[idx].a = d_1a2764[U];
        p3->e[idx++].b = 0;
        if (*(signed char *)(p1 + 0x1ee)) {
            if (v != -1) p3->e[idx].a = d_1a276c[v * 4 + U]; else p3->e[idx].a = d_1a2764[U];
            p3->e[idx++].b = 0;
        }
        if (*(signed char *)(p1 + 0x1f0)) {
            p3->e[idx].a = 0x26;
            p3->e[idx++].b = 0;
        }
        f_06ebf0(p1, p2, p3, idx);
        p3->e[++idx].a = -1;
        char *q = f_07ea60((char *)(p1 + 0x39), f_043470(p2));
        f_069a00(*(int *)(q + 0xf), p3);
        return *(int *)(q + 0xf);
    }
    return f_06ed10(p1, p2, p3);
}

//@ f_06efc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für einen Helden p2 die Parade-, Treffer- oder Sterbesequenz gegen einen Angriff aus
 *   Richtung p4 auf: Dreht den Helden in Abwehrrichtung to = f_071fb0(p1, p4), fügt bei aktiver Parade
 *   (!f_043450(p2)) die Paradeanimation aus d_1a277c/d_1a2768 ein, bei erlittenem Treffer (p1 + 0x1ef) die
 *   Trefferreaktion d_1a276c/d_1a2764 und bei Tod (d_1bd918) die Sterbesequenz 0x26 bzw. bei Flucht/Ohnmacht
 *   0xaf + Richtung.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Heldenzeiger p2 (edx), der Sequenzpuffer
 *   p3 (ebx, R *) und die Angriffsrichtung p4 (ecx, short); zurückgegeben wird das Kampfsprite (int in eax).
 * - Wichtige Variablen: d_1bd918 kennzeichnet einen tödlichen Treffer, p1 + 0x1ef einen Schadens-Treffer.
 === Ende Beschreibung === */
int f_030d00(int);
char f_043450(long);
unsigned char f_043470(int);
int f_06efc0(int p1, int p2, R *p3, short p4)
{
    short idx;
    short to;
    int W;
    short v;
    short from;

    idx = 0;
    W = 0;
    if ((f_0d4a60(p2) && !((signed char)(f_0424d0((struct hero *)(p2))))) || ((char)(f_042470((struct hero *)((long)p2)))) || f_0425f0((struct hero *)(p2))) {
        v = ((short (*)(int))(int (*)(int))f_030d00)(p2); // Rueckgabebreite short fuer f_030d00(int)
        if (f_042a60((struct hero *)(p2), 3L) == 0x85 || (f_042a10((struct hero *)(p2)) && v == 1)) v = -1;
        if (f_042400((struct hero *)(p2)) == 7 || f_042400((struct hero *)(p2)) == 8) v = -1;
        f_145300(p3, 0, 0xa4);
        p3->f0 = f_0727e0(p2);
        from = f_043490(p2);
        to = f_071fb0(p1, p4);
        if (!f_043450((long)p2)) {
            f_043460(p2, 1);
            f_06e9e0(p1, p2, from, to, &idx, p3, 0);
            if (v != -1) p3->e[idx].a = d_1a277c[v * 4 + to];
            else p3->e[idx].a = d_1a2768[to];
            p3->e[idx++].b = 0;
        } else W = 1;
        if (*(signed char *)(p1 + 0x1ef)) {
            W = 0;
            from = f_043490(p2);
            if (from != to) f_06e9e0(p1, p2, from, to, &idx, p3, 0);
            if (v != -1) p3->e[idx].a = d_1a276c[v * 4 + to];
            else p3->e[idx].a = d_1a2764[to];
            p3->e[idx++].b = 0;
        }
        if (d_1bd918) {
            if (W) {
                short k = 0;
                if ((short)f_030d80(p2) == 4) k = 1;
                p3->e[idx].a = d_1a2748[k * 4 + (signed char)f_043490(p2)];
                p3->e[idx].c = 8;
                p3->e[idx++].b = 3;
            }
            if ((signed char)f_043490(p2) != 1)
                f_06e9e0(p1, p2, f_043490(p2), 1, &idx, p3, 0);
            p3->e[idx].a = 0x26;
            p3->e[idx++].b = 0;
        } else if (f_0425f0((struct hero *)(p2))) {
            if (W) {
                short k = 0;
                if ((short)f_030d80(p2) == 4) k = 1;
                p3->e[idx].a = d_1a2748[k * 4 + (signed char)f_043490(p2)];
                p3->e[idx].c = 8;
                p3->e[idx++].b = 3;
            }
            p3->e[idx].a = f_043490(p2) + 0xaf;
            p3->e[idx++].b = 0;
        }
        if (idx != 0) {
            char *q;
            f_06ebf0(p1, p2, p3, idx);
            p3->e[++idx].a = -1;
            q = f_07ea60((char *)(p1 + 0x39), f_043470(p2));
            f_069a00(*(int *)(q + 0xf), p3);
            return *(int *)(q + 0xf);
        }
        return f_06ed10(p1, p2, p3);
    }
    return f_06ed10(p1, p2, p3);
}

//@ f_06f400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gegenstück zu f_06e9e0 für einfeldige Monster: Hängt die Drehschritte von Richtung *p3 zur
 *   Zielrichtung p4 an den Sequenzpuffer p6 (ab Index *p5) an und setzt am Ende den Richtungsbefehl 0x1e + p4
 *   (oder trägt bei Schnellmodus d_1bd928 != 0 die Richtung sofort über f_0cfc80 ein).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Monsterzeiger p2 (edx), der
 *   Richtungszeiger p3 (ebx, signed char *), die Zielrichtung p4 (ecx, short) sowie auf dem Stapel p5 (short *),
 *   p6 (R *) und p7 (short); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd928 schaltet während des schnellen Kampfaufbaus die Einzelbild-Drehung ab.
 === Ende Beschreibung === */
void f_06f400(int p1, int p2, signed char *p3, short p4, short *p5, R *p6, short p7)
{
    signed char c;
    short d; int w4;
    unsigned char flag; int wc;
    c = *p3;
    flag = *(unsigned char *)&d_1bd928;
    if (flag) {
        f_0cfc80(p2, (signed char)p4);
        *p3 = p4;
        return;
    }
    w4 = p4; wc = c;
    if (wc != w4) {
        d = f_071f70(p1, wc, w4);
        c = c * 2;
        d = d * 2;
        if (d == -2) {
            if (p7 == (short)0) {
                p6->e[*p5].a = c + 1;
                p6->e[(*p5)++].b = 0;
                p6->e[*p5].a = c + 1;
                p6->e[(*p5)++].b = 0;
            }
            c = c - 1;
            if (c < 0) c = 7;
            p6->e[*p5].a = c + 1;
            c = (c & 0) ? 0 : c; // Haelt die Registerfolge fuer c wie im Original
            p6->e[(*p5)++].b = 0;
            p6->e[*p5].a = p4 * 2 + 1;
            p6->e[(*p5)++].b = 0;
        } else {
            if (d == 2 && p7 == (short)0) {
                p6->e[*p5].a = c + 1;
                p6->e[(*p5)++].b = 0;
                p6->e[*p5].a = c + 1;
                p6->e[(*p5)++].b = 0;
            }
            do {
                c = c + 1;
                if (c > 7) c = 0;
                p6->e[*p5].a = c + 1;
                p6->e[(*p5)++].b = 0;
                d = d - 1;
            } while (d > 0);
        }
        *p3 = p4;
        p6->e[*p5].d = p4 + 0x1e;
    } else if (p7 == (short)0) {
        c = c * 2;
        p6->e[*p5].a = c + 1;
        p6->e[*p5].c = 4;
        p6->e[(*p5)++].b = 3;
    }
}

//@ f_06f5c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt ein Monster p2 auf seine dauerhafte Stand-/Ruhesequenz im Puffer p3 zurück (bei großen
 *   Monstern f_0d06c0 über f_07a470, bei Spezialeffekt f_0cfef0 auf Animation 0xd9 in 0x1000b, bei Toten auf 9,
 *   bei Gefesselten auf d_1a2758, sonst auf d_1a2748).
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Monsterzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, R *); zurückgegeben wird das Monster-Sprite (int in eax).
 * - Wichtige Variablen: q ist der Kampfraster-Eintrag des Monsters (f_07ea60).
 === Ende Beschreibung === */
int f_06f5c0(int p1, int p2, R *p3)
{
    unsigned char f_0cfc50(int);
    char *f_07ea60(char *, int);
    if (f_0d06c0(p2) != 0) return f_07a470(p1, p2, p1 + 0x45);
    f_145300(p3, 0, 0xa4);
    if (f_0cfef0(p2)) {
        p3->f0 = 0x1000b;
        p3->e[0].a = 0xd9;
    } else {
        p3->f0 = f_0728f0(p2);
        if (f_0cfdc0(p2)) p3->e[0].a = 9;
        else if (f_0cfe30(p2)) p3->e[0].a = d_1a2758[f_0cfc70(p2)];
        else p3->e[0].a = d_1a2748[f_0cfc70(p2)];
    }
    p3->e[0].b = 4;
    ((char&)p3->e[0].c) = -1;
    p3->e[1].a = -1;
    char *q = f_07ea60((char *)(p1 + 0x39), f_0cfc50(p2));
    f_069a00(*(int *)(q + 0xf), p3);
    return *(int *)(q + 0xf);
}

//@ f_06f690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für ein Monster p2 die Nahkampfangriffs-Sequenz im Puffer p3 auf (bei Großmonstern über
 *   f_07a4d0): Dreht das Monster über f_06f400 zum Ziel (b), wählt die Angriffsanimation aus d_1a2764 (oder die
 *   Spezialattacke d_1a2774 bei d_1bd920 == 2 und f_0cf990(p2) != 0), verdoppelt sie bei *(signed char *)(p1 +
 *   0x1ee) und hängt bei *(char *)(p1 + 0x1f0) die Sterbesequenz 0x26 samt f_06d380 an.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Monsterzeiger p2 (edx) und der
 *   Sequenzpuffer p3 (ebx, R *); zurückgegeben wird das Effekt-Sprite W bzw. das Monster-Sprite.
 * - Wichtige Variablen: d_1bd920 unterscheidet zwischen normalem Schlag und Zweit-/Spezialangriff des Monsters.
 === Ende Beschreibung === */
int f_06f690(int p1, int p2, R *p3)
{
    unsigned char f_0cfc50(int);
    char *f_07ea60(char *, int);
    short idx; int W; int x;
    idx = 0;
    W = 0;
    x = f_072940(p2);
    if (x != 0 || (signed char)f_0cfdc0(p2)) {
    if (f_0d06c0(p2)) return f_07a4d0(p1, p2, p1 + 0x45);
    f_145300(p3, 0, 0xa4);
    p3->f0 = f_0728f0(p2);
    {
        signed char c1 = f_0cfc70(p2);
        signed char b = f_072440(p1, p2);
        char t = d_1a2764[b];
        if (d_1bd920 == 2 && f_0cf990(p2) != 0) t = d_1a2774[b];
        f_06f400(p1, p2, &c1, b, &idx, p3, 0);
        p3->e[idx].a = t;
        p3->e[idx++].b = 0;
        if (*(signed char *)(p1 + 0x1ee)) {
            p3->e[idx].a = t;
            p3->e[idx++].b = 0;
        }
        if (*(char *)(p1 + 0x1f0)) {
            if (c1 != 1) f_06f400(p1, p2, &c1, 1, &idx, p3, 0);
            p3->e[idx].a = 0x26;
            p3->e[idx++].b = 0;
            W = f_06d380(p1, p2, &idx, p3);
        }
    }
    p3->e[idx].a = -1;
    char *q = f_07ea60((char *)(p1 + 0x39), f_0cfc50(p2));
    f_069a00(*(int *)(q + 0xf), p3);
    if (W != 0) return W;
    return *(int *)(q + 0xf);
    }
    return f_06f5c0(p1, p2, p3);
}

signed char Direction493(int);
#pragma aux Direction493 "f_0cfc70" parm [eax] modify exact [eax];
signed char Facing493(void *,short);
#pragma aux Facing493 "f_071fb0" parm [eax] [edx] modify exact [eax];
int Fallback493(int,int,R *);
#pragma aux Fallback493 "f_06f5c0";
//@ f_06f850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut für ein Monster p2 die Parade-, Treffer- oder Sterbesequenz gegen einen Angriff aus
 *   Richtung p4 auf (bei Großmonstern über f_07a560): Dreht das Monster in Abwehrrichtung b, fügt bei Parade
 *   (!f_0d01a0(p2)) die Abwehrpose d_1a2768/d_1a2784 ein, bei erlittenem Treffer (p1 + 0x1ef) die Trefferpose
 *   d_1a2764/d_1a2774 und bei Tod (d_1bd918) die Drehung auf Richtung 1, den Sterbecode 0x26 sowie f_06d380.
 * - Eingaben und Rückgabe: Eingaben sind das Kampfsystem p1 (eax), der Monsterzeiger p2 (edx), der Sequenzpuffer
 *   p3 (ebx, R *) und die Angriffsrichtung p4 (ecx, short); zurückgegeben wird das Effekt-Sprite W2 bzw. das
 *   Monster-Sprite.
 * - Wichtige Variablen: d_1bd918 signalisiert den Tod des Monsters, W2 hält ein eventuell von f_06d380 erzeugtes
 *   Todessprite.
 === Ende Beschreibung === */
int f_06f850(int p1, int p2, R *p3, short p4)
{
    char f_0cfc50(void *);
    signed char c1; char t2; char t1; signed char b;
    short idx; int W2; int W1; int x;
    idx = 0;
    W1 = 0; W2 = 0;
    x = f_072940(p2);
    if (x != 0 || f_0cfdc0(p2)) {
        if (f_0d06c0(p2) != 0) return f_07a560(p1, p2, p3);
    f_145300(p3, 0, 0xa4);
    p3->f0 = f_0728f0(p2);
    c1 = Direction493(p2);
    b = Facing493((void *)p1,p4);
    t2 = d_1a2768[b];
    t1 = d_1a2764[b];
    if (d_1bd920 == 2 && f_0cf990(p2) != 0) {
        t2 = d_1a2784[b];
        t1 = d_1a2774[b];
    }
    if (!f_0d01a0(p2)) {
        f_0d01b0(p2, 1);
        f_06f400(p1, p2, &c1, b, &idx, p3, 0);
        p3->e[idx].a = t2;
        p3->e[idx++].b = 0;
    } else W1 = 1;
    if (*(char *)(p1 + 0x1ef)) {
        W1 = 0;
        if (c1 != b) f_06f400(p1, p2, &c1, b, &idx, p3, 0);
        p3->e[idx].a = t1;
        p3->e[idx++].b = 0;
    }
    if (*(char *)&d_1bd918) {
        if (W1 != 0) {
            int ci = c1;
            char *dst = (char *)p3 + (short)idx * 4;
            char ch = d_1a2748[ci];
            dst[0xc] = ch;
            p3->e[idx].c = 6;
            p3->e[idx++].b = 3;
        }
        if (c1 != 1) f_06f400(p1, p2, &c1, 1, &idx, p3, 0);
        p3->e[idx].a = 0x26;
        p3->e[idx++].b = 0;
        W2 = f_06d380(p1, p2, &idx, p3);
    }
    p3->e[idx].a = -1;
    if (idx != 0) {
        char *q = f_07ea60((char *)(p1 + 0x39), f_0cfc50((void *)p2));
        int w = W2;
        f_069a00(*(int *)(q + 0xf), p3);
        if (w != 0) return w;
        return *(int *)(q + 0xf);
    }
    return f_06f5c0(p1, p2, p3);
    } else return Fallback493(p1,p2,p3);
}
