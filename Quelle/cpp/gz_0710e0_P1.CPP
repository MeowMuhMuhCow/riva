/* === Beschreibung (Katalog) ===
 * Einheit gz_0710e0 (0710e0 - 071880)
 *
 * Überblick
 * Diese Einheit enthält Hilfsfunktionen für den Kampfbeginn und das Kampfende: die Ausrichtung der Helden zum
 * nächstgelegenen Gegner beim Kampfstart (f_0710e0, f_0711c0) sowie die zentrale Abschluss-, Sieg-/Niederlagen-
 * und Fluchtbehandlung nach einem Kampf (f_0712f0, f_0716e0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 2/4 gleich (suche.py 29.10.2026, Basis gz_0710e0_P1.CPP)
// gz_0710e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0710E0-0x071880
#include <string.h>
#include "RIVAMEM.H"

int f_030b00(int p1);
int f_038c40(int p1);
int f_038c80(int p1);
int f_039040(int p1);
int f_0391b0(int p1, int p2);
short f_040590();
int f_041030(int n, ...);

int f_044300(int p1, int p2);
int f_0701d0(int p1, int p2);
int f_145300(char *p1, int p2, int p3);
int f_071880(int p1);
int f_071bd0(int p1);
int f_071e90(int p1, int *p2, int *p3);
char f_0729c0(int p1);
int f_07a6a0(int p1);
int f_07ab80(int p1);
char f_0ce070(int p1);
int f_0ce650();
short f_0cfa10(int p1);
char f_0cfdc0(int p1);
int f_0cfdd0(int p1, int p2);
char f_0d00a0(int p1);
int f_0d0960(int p1, int p2, int p3);
int f_0d26e0();
int f_0d2710();
int f_0d4a10(int p1);
char f_0d54c0(int p1);
int f_0d64a0();
short f_0db940(int p1);
int f_0ddc70(int p1, int p2);
short f_0ddcf0(int p1);
int f_0de7d0(int p1, int p2);
short f_0de7f0(int p1);
short f_0de820(int p1);
int f_0de8d0(int p1, int p2);
int f_11f6e0();
short f_1457e0(int p1);
struct S73 { char b[0x73]; };
char f_0cf910(int p1);
void f_0716e0(int p1);
int f_0c0020(int p1, int p2);
int f_09a0d0(int p1);
int f_069460();
extern short d_1c21a4;
extern short d_1bd90c;
extern char d_1bd928;
extern short d_1bd922;
extern int d_1bd91c;
extern short d_1bd920;
extern int d_1c0004;
extern S73 *d_1c2ed4;
extern volatile short d_1c219c; // Direkte Speicherzugriffe auf das globale Statuswort
extern volatile short d_1c2198; // Direkte Speicherzugriffe auf das globale Statuswort
extern int d_1c0c4c;
extern int d_1c2a80;
extern char d_1bd90e;
extern int d_1a34e0;
extern short d_1bd766;
extern short d_1bd762;
extern char d_1c0b98;
extern char d_1c002c;
extern char d_1bfdbc[];
extern char d_1a2218[];
extern char d_1c2c64[];

#define ND32(a) (*(int *)&(a))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern unsigned char d_1bd984;
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C0710e0_5(int,int,int,int,int);
#pragma aux C0710e0_5 "f_0710e0" modify exact [eax ebx ecx edx];
int C071e20_4(int,int,int,int);
#pragma aux C071e20_4 "f_071e20" modify exact [eax ebx edx];
extern "C" void ep710(void);
#pragma aux ep710 "L070E41" aborts;
//@ f_0710e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht auf dem Kampfraster d_1bd984 den nächstgelegenen mit 0xca markierten Gegner-Startplatz
 *   relativ zur übergebenen Koordinate (x, y) und liefert dessen Position sowie die Manhattan-Distanz zurück.
 *   Sie ist das exakte Gegenstück zu f_070d70 (welche nach Heldenplätzen 0xc9 sucht).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger self, die Heldenkoordinate x und y sowie die Ausgabezeiger
 *   ox und oy und gibt die minimale Manhattan-Distanz (short, Startwert 99) zurück.
 * - Wichtige Variablen: Durchsucht die 24 x 25 Einträge von d_1bd984 nach dem Marker 0xca und ruft f_071e20 für
 *   die Distanzberechnung auf.
 === Ende Beschreibung === */
short f_0710e0(int self,signed char x,signed char y,signed char *ox,signed char *oy)
{
short distance1049(int,int,int,int);
#pragma aux distance1049 "f_071e20" parm [eax] [edx] [ebx] [ecx] modify exact [eax ebx edx]

    signed char rx=(signed char)x;*(signed char *)&x=rx;
    signed char ry=(signed char)y;y=ry;
    short best=99;short col,row,d;
    for(row=0;row<(short)24;row++) for(col=0;col<(short)25;col++){
      if(((signed char (*)[25])ND32(d_1bd984))[row][col]!=(signed char)0xca)continue;
      int yy=y;self=x;d=(short)distance1049(self,yy,col,row);
      if(d>best)continue;
      // Globale Roundtrips und Adressierung halten die Registerfolge wie im Original
      if(d<best || col==self || row==yy){signed char rt0=*(signed char *)&d_1bd984;*(signed char *)&d_1bd984=rt0;short rt1=*(short *)&d_1bd984;*(short *)&d_1bd984=rt1;int rt2=*(int *)&d_1bd984;*(int *)&d_1bd984=rt2;*(*&ox)=(signed char)col;*oy=(signed char)row;best=d;}
    }
    ep710();
}

//@ f_0711c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bestimmt zu Kampfbeginn für alle bis zu 7 Helden-Startplätze (self + 0x1015) anhand des über
 *   f_0710e0 ermittelten nächstgelegenen Gegners die optimale anfängliche Blickrichtung (0..3), sodass jeder
 *   Held beim Start des Kampfes dem nächsten Feind zugewandt steht.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger self und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Liest je Slot die Startkoordinaten x (+0x1015) und y (+0x1016) und schreibt die
 *   berechnete Blickrichtung nach +0x1017 + i * 4.
 === Ende Beschreibung === */
void f_0711c0(int self) {
 union Counter650 {int full;short word;};union Byte650{int full;signed char byte;};struct Frame650 {Counter650 i;Byte650 x,tx,ty,y;} frame650;signed char dir;
 struct Slot650 {char pad[0x1015];signed char x,y,dir;};
 for(frame650.i.full=0;frame650.i.word<7;frame650.i.full++){
  Slot650 *p=(Slot650 *)(self+frame650.i.word*4);
  if(p->x==-1)continue;
  frame650.x.byte=p->x;frame650.y.byte=p->y;
  int ix=frame650.x.byte,iy=frame650.y.byte;C0710e0_5(self,ix,iy,(int)&frame650.tx.byte,(int)&frame650.ty.byte);

  if(frame650.tx.byte==frame650.x.byte) {if(frame650.ty.byte<frame650.y.byte) dir=1;else dir=3;}
  else if(frame650.ty.byte==frame650.y.byte) {if(frame650.x.byte>frame650.tx.byte) dir=2;else goto Zero650;}
  else if(frame650.tx.byte < frame650.x.byte) {
   if(frame650.ty.byte<frame650.y.byte) {iy-=frame650.ty.byte;ix-=frame650.tx.byte;if(iy>ix)dir=1;else dir=2;}
   else {iy=frame650.ty.byte-iy;ix-=frame650.tx.byte;if(iy>ix)dir=3;else dir=2;}
  } else {
   if(frame650.ty.byte<frame650.y.byte) {iy-=frame650.ty.byte;ix=frame650.tx.byte-ix;if(iy>ix)dir=1;else goto Zero650;}
   else {iy=frame650.ty.byte-iy;ix=frame650.tx.byte-ix;if(iy>ix)dir=3;else {Zero650:dir=0;}}
  }

NB(self,0x1017+frame650.i.word*4)=(unsigned char)dir;
 }
}

//@ f_0712f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette Nachbereitung eines beendeten Kampfes durch. Je nach Abbruch- oder
 *   Ausgangsstatus d_1c21a4 werden zurückgelassene oder bewusstlose Helden behandelt, bei einem regulären Sieg
 *   (*p2 == 0) überlebende/geflohene Gegner ausgewertet, Beute (f_071880) und Abenteuerpunkte (f_071bd0)
 *   verteilt, der Kampfzustand in die temporäre Kampfdatei zurückgeschrieben (f_07ab80, f_07a6a0), bei einer
 *   Flucht (*p2 == 1) die Gruppe über f_0716e0 auf der Karte zurückgesetzt und schließlich Palette, Musik und UI
 *   wiederhergestellt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und den Ein-/Ausgabezeiger p2 für den Kampfausgangscode
 *   (0 = gewonnen, 1 = geflohen, 2 = verloren/abgebrochen) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Statusvariable d_1c21a4 steuert Sonderabbrüche (Tod der Gruppe, Flucht,
 *   Arena-Ende), d_1bd90e zählt die noch lebenden Gegner für nachfolgende Skriptabfragen und d_1bd920/d_1bd922
 *   speichern Spezialkampf-Modi.
 === Ende Beschreibung === */
void f_0712f0(int p1, short *p2)
{
    int v, u;
    short s;
    int fl;
    int c;
    short i, j, k;
    f_0d26e0();
    f_0ce650();
    f_0d2710();
    fl = 0;
    
    if (d_1c21a4 != (short)4) {
        if (d_1c21a4 != 0) {
            d_1bd90c = 1;
            if (d_1c21a4 == (short)6) {
                d_1c21a4 = 5;
                c = f_038c80(d_1c0004);
                do {
                    if ((!((char)(f_042470((struct hero *)(c)))) && f_071e90((unsigned char)(f_0d54c0(c) + 1), &u, &v)) || ((char)(f_0425f0((struct hero *)(c)))) || ((char)(f_0424d0((struct hero *)(c)))))
                        f_042650((struct hero *)(c), 1);
                } while ((c = f_0391b0(d_1c0004, c)) != f_038c80(d_1c0004));
            } else {
                c = f_038c80(d_1c0004);
                do {
                    if ((!((char)(f_042470((struct hero *)(c)))) && f_071e90((unsigned char)(f_0d54c0(c) + 1), &u, &v)) || ((char)(f_0425f0((struct hero *)(c)))) || ((char)(f_0424d0((struct hero *)(c)))))
                        f_044300(c, f_042960((struct hero *)(c)));
                } while ((c = f_0391b0(d_1c0004, c)) != f_038c80(d_1c0004));
            }
            if (f_038c40(d_1c0004) == f_039040(d_1c0004))
                f_0d64a0();
            if (d_1c21a4 != (short)5) {
                if (f_040590()) {
                    d_1c21a4 = 0;
                    fl = 1;
                }
                *p2 = 2;
            } else {
                *p2 = 1;
                d_1c21a4 = 0;
            }
            if (d_1bd928)
                f_0701d0(p1, *p2);
            if (fl)
                d_1c219c = 1;
            d_1bd90c = 0;
        }
        if (*p2 == 0) {
            
            for (i = 0; i < (short)0x14; i++) {
                int m = (int)(d_1c2ed4 + (short)i);
                if (f_0cfdc0(m)) continue;
                if (f_0d00a0(m)) continue;
                if (f_071e90((unsigned char)(f_0729c0(m) + 10), &u, &v))
                    f_0d0960(m, f_0cfa10(m), 0);
            }
        }
        if (*p2 == 0) {
            if (d_1bd928) {
                d_1bd90c = 1;
                f_0701d0(p1, *p2);
                d_1bd90c = 0;
            }
            f_071880(p1);
            f_071bd0(p1);
            if (d_1bd922 && d_1bd91c == 0) {
                
                j = 0;
                do {
                    f_0cfdd0((int)(d_1c2ed4 + (short)j), 1);
                    j++;
                } while (j < (short)0x14);
            }
        }
        if (d_1bd91c == 0) {
            f_07ab80(p1);
            f_07a6a0(p1);
        }
        if (*p2 == 1 && d_1bd920 != 1)
            f_0716e0(p1);
    } else {
        *p2 = 2;
    }
    f_030b00(d_1c0004);
    d_1bd91c = 0;
    d_1bd920 = d_1bd922 = (short)d_1bd91c;
    f_145300(d_1a2218, 0, 0x45);
    for (d_1bd90e = 0, k = 0; k < (short)0x14; k++) {


            int m = (int)(d_1c2ed4 + (short)k);
            if (f_0cf910(m) && !f_0cfdc0(m))
                ++d_1bd90e;
    }
    --d_1c0c4c;
    d_1c2198 = d_1c219c = 1;
    d_1c2a80 = 0;
    f_0c0020((int)&d_1c2c64, *(short *)(p1 + 0x19f));
    f_09a0d0(d_1a34e0);
    f_069460();
    d_1bd766 = 0; d_1bd762 = 0;
}

//@ f_0716e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Positioniert die Heldengruppe nach einer Flucht aus dem Kampf auf der 3D-/Dungeonkarte neu.
 *   Während ein Teil der Gruppe auf das vorherige Schrittfeld zurückkehrt, werden aus dem Kampf geflohene
 *   einzelne Helden (f_042640) als eigene Teilgruppen (f_041030) auf frühere Wegpunkte der Schrittspur
 *   (f_0ddc70) mit zufälliger Blickrichtung verteilt.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt die Schrittspur-Funktionen f_0ddcf0, f_0ddc70 und f_0de8d0 auf dem Gruppenzeiger
 *   d_1c0004 sowie das Gruppenarray d_1bfdbc.
 === Ende Beschreibung === */
void f_0716e0(int p1)
{
    int arr[7]; short a, n, i, r, lim; int t, o, p; signed char c;
    a = f_0de820(d_1c0004);
    if (d_1c0b98) f_11f6e0();
    if (a == 7 || a == 8 || a == 9 || a == 0x17 || a == 0x18 || a == 0x19) {
        f_0ddcf0(d_1c0004); r = f_1457e0(0x168); f_0de8d0(d_1c0004, (unsigned short)(r * 0xb6));
    } else {
        n = f_0de7f0(d_1c0004); a = 0; lim = f_039040(d_1c0004) ? 2 : 1;
        for (i = 0; i < 7; i++) { arr[i] = 0; o = f_0de7d0(d_1c0004, i);
            if (o && f_0d4a10(o) && !((char)(f_042400((struct hero *)(o)))) && ((char)(f_042640((struct hero *)(o)))) && n > (short)lim) { arr[a] = o; n--; a++; }
        }
        n = f_0ddcf0(d_1c0004); n--;
        goto loop_test;
    loop_body:
        a--; p = f_041030(1, arr[a]); f_0ddc70(p, n); r = f_1457e0(0x168); n--; f_0de8d0(p, (unsigned short)(r * 0xb6));
    loop_test:
        if (n > 0 && a > 0) goto loop_body;
        if (f_0db940(d_1c0004) == 0) { c = 0; do { o = (int)d_1bfdbc + c * 0x61; if (f_0db940(o) > 0) { d_1c0004 = o; d_1c002c = f_0ce070(o); return; } c++; } while (c < 6); }
    }
}
