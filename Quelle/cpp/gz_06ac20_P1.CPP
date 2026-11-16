/* === Beschreibung (Katalog) ===
 * Einheit gz_06ac20 (0x06ac20 - 0x06bdd0)
 *
 * Überblick
 * Die Einheit gz_06ac20 ergänzt die Kampfsprite-Steuerung (Face / Gz) um das Suchen von Sequenzheadern
 * (f_06ac20), das Weiterschalten der Animationsframes und -phasen (f_06acb0), einen Entpack-Wrapper (f_06ae30),
 * die umfangreiche Kampfsound-Zuordnung für Helden, Monster und Effekte (f_06af80) sowie das Erzeugen einer
 * Sterbe-/Treffersequenz (f_06bd70).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 2/4 gleich (suche.py 26.10.2026, Basis gz_06ac20_P1.CPP)
// gz_06ac20.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x06AC20-0x06BDD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_010460(int p1);
short f_010470(int p1);
int f_010480(int p1);                                   // reg eax stapel 0
unsigned char f_010490(int p1);
int f_0a2520(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);


// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
                    // 0x1C2098
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
void *f_145300(void *p, int c, unsigned n);
int f_0727e0(int p1);
unsigned char f_043470(int p1);
char *f_07ea60(char *p1, int p2);
int f_069a00(int p1, void *p2);
struct R16 { int a; short b; short c; char d; char dd; short e; short f; char g; char h; };
//@ f_06ac20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest bis zu a2 16-Byte-Headerdatensätze aus der aktuell geöffneten Animationsdatei (d_1c2098)
 *   und übernimmt beim Treffer auf den Schlüssel a3 Dateioffset (+0xb7), Frameanzahl (+0xc3) und
 *   Geometrieoffsets (+0xbf, +0xc1, +0xbc, +0xbe, +0xa5) in das Kampfsprite p1.
 * - Eingaben und Rückgabe: Eingaben sind der Sprite-Zeiger p1 (eax), die Anzahl der Einträge a2 (edx, short) und
 *   der gesuchte Schlüssel a3 (ebx, int); kein Rückgabewert (void).
 * - Wichtige Variablen: s (R16) puffert jeweils einen 16-Byte-Tabelleneintrag aus d_1c2098.
 === Ende Beschreibung === */
void f_06ac20(char *p1, short a2, int a3)
{
    struct R16 s;
    short i = 0;
    short key;
    short n = a2;
    key = a3;
    for (i = 0; i < n; i++) {
        short t;
        ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( &s), 0x10)));
        t = s.b;
        if (key == t) {
            *(int *)(p1 + 0xb7) = s.a;
            *(char *)(p1 + 0xc3) = s.g;
            *(short *)(p1 + 0xbf) = s.e;
            *(short *)(p1 + 0xc1) = s.f;
            *(short *)(p1 + 0xbc) = s.c;
            *(char *)(p1 + 0xbe) = s.d;
            *(short *)(p1 + 0xa5) = t;
            return;
        }
    }
}
//@ f_06acb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das Kampfsprite p zum nächsten Frame oder zur nächsten Animationsphase weiter:
 *   Solange frame < limit (p[0xcb] < p[0xc3] - 1), wird nur der Frameindex p[0xcb] erhöht; am Ende einer
 *   Teilsequenz wertet die Funktion den Wiederholungsmodus entry[0x0d] (3/4 = Schleife bis entry[0x0e] bzw.
 *   endlos bei 255), den Aktionscode entry[0x0f] und das Folgebyte entry[0x10] aus und schaltet gegebenenfalls
 *   p[0xa4] weiter oder beendet die Sequenz (*(int *)(p + 0xb3) = 0).
 * - Eingaben und Rückgabe: Eingabe ist der Sprite-Zeiger p (eax); zurückgegeben wird der ausgelöste Aktionscode
 *   result (unsigned char in al, 0 wenn kein Code fällig ist).
 * - Wichtige Variablen: p[0xcb] ist der aktuelle Frameindex, p[0xa4] der Phasenindex und p[0xcd] der
 *   Wiederholungszähler.
 === Ende Beschreibung === */
unsigned char f_06acb0(char *p)
{
    unsigned char result = 0;
    p[0xbb] = 1;
    if (*(int *)(p + 0xb3)) {
        int frame = (unsigned char)p[0xcb];
        int limit = (unsigned char)p[0xc3] - 1;
        if (frame < limit) {
            // KRUECKE: zusaetzliche Frame-Nutzung hebt seinen Register-Nutzwert.
            p[0xcb]=(unsigned char)frame;
            p[0xcb]++;
            return result;
        }

        int index = (unsigned char)p[0xa4];
        char *entry = p + 4 * index;
        int kind = (unsigned char)entry[0x0d];
        if (kind == 3 || kind == 4) {
            int end = (unsigned char)p[0x0e + 4 * (unsigned char)p[0xa4]];
            if (end == 255 && (int)(unsigned char)p[0xc3] == 1) {
                p[0xcd]++;
                *(int *)(p + 0xb3) = 0;
                return result;
            }

            entry = p + 4 * (unsigned char)p[0xa4];
            if ((unsigned char)p[0xcd] < (unsigned char)entry[0x0e]) {
                p[0xcd]++;
                p[0xcb] = 0;
                p[0xbb] = 0;
                return result;
            }
            if ((unsigned char)entry[0x0e] == 255) {
                p[0xcb] = 0;
                p[0xbb] = 0;
                return result;
            }
            result = (unsigned char)entry[0x0f];
            if ((unsigned char)entry[0x10] != 255) {
                p[0xcb] = 0;
                p[0xbb] = 0;
                p[0xa4]++;
                return result;
            }
        } else {
            result = (unsigned char)entry[0x0f];
            if ((unsigned char)entry[0x10] != 255) {
                p[0xcb] = 0;
                p[0xbb] = 0;
                p[0xa4]++;
                return result;
            }
        }
        *(int *)(p + 0xb3) = 0;
    }
    return result;
}
//@ f_06ae30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entpackt die komprimierten Frame-Daten p3 anhand des im Sprite p1 gespeicherten
 *   Frame-Deskriptors *(int *)(p1 + 0xcf) über f_0a2520 in das RivaRasterImage p2.
 * - Eingaben und Rückgabe: Eingaben sind der Sprite-Zeiger p1 (eax), das Zielbild p2 (edx) und der komprimierte
 *   Quellpuffer p3 (ebx); kein Rückgabewert (void).
 * - Wichtige Variablen: buf stellt den 140-Byte-Arbeitsbereich für den Entpacker f_0a2520 bereit.
 === Ende Beschreibung === */
void f_06ae30(char *p1, int p2, int p3)
{
    char buf[140];
    f_0a2520(buf, f_010490(*(int *)(p1 + 0xcf)), f_010480(*(int *)(p1 + 0xcf)), f_010460(*(int *)(p1 + 0xcf)), f_010470(*(int *)(p1 + 0xcf)), ((int)(((RivaRasterImage*)(p2))->f_0fb0b0())), p3);
}
//@ f_06af80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt während einer Kampfanimation den zum Aktionscode mode (12..26, z. B. Schlag, Schuss,
 *   Zauber, Treffer, Tod) passenden Kampfsound (0xc0000..0xc0048) über f_147323 ab, sofern das Sprite nicht
 *   stummgeschaltet ist (*(int *)(p + 0xf0) == 0). Die Funktion unterscheidet anhand der Animations-ID *(int *)p
 *   zwischen Helden (0xb0000..0xb0013 und 0xb0055..0xb005c), Monstern/NSCs (0xb0014..0xb0051), Spezialwesen
 *   (0xb0052..0xb0054) und allgemeinen Effekten und wählt den Sound nach Waffentyp und Monsterart aus.
 * - Eingaben und Rückgabe: Eingaben sind der Sprite-Zeiger p (eax) und der Sound-/Aktionscode mode (edx,
 *   unsigned char); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd934 liefert über f_07ead0 die Kampfraster-Zelle des Sprites, d_1c2edc ist das
 *   Soundsystem.
 === Ende Beschreibung === */
extern int d_1bd934,d_1c0004,d_1a9820,d_1c2edc;
char *object650(int,char *);
#pragma aux object650 "f_07ead0" modify exact [eax ecx edx];
int character650(int,unsigned char);
#pragma aux character650 "f_072810" modify exact [eax edx];
int npc650(unsigned char);
#pragma aux npc650 "f_0d0ac0" modify exact [eax];
short heroFlag650(int);
#pragma aux heroFlag650 "f_030d00" modify exact [eax];
signed char npcFlag650(int);
#pragma aux npcFlag650 "f_0d00c0" modify exact [eax];
signed char state650(int);
#pragma aux state650 "f_030960" modify exact [eax];
int held650(int);
#pragma aux held650 "f_030890" modify exact [eax];
short stat650(int);
#pragma aux stat650 "f_030d80" modify exact [eax];
short count650(int);
#pragma aux count650 "f_0d00e0" modify exact [eax];
signed char tag650(int);
#pragma aux tag650 "f_0d0180" modify exact [eax];
signed char type650(int);
#pragma aux type650 "f_0d0080" modify exact [eax];
struct Palette650 {static int get(){return d_1a9820;}};
int message650(int *,int,unsigned short=0x7fff,unsigned short=0x8000,int=d_1a9820,short=0,unsigned short=1);
#pragma aux message650 "f_147323" modify [esp];
#define DEFAULTMSG650(n) {message650(&d_1c2edc,0xc0000+(n));return;}
#define MSG650(n) {message650(&d_1c2edc,0xc0000+(n),0x7fff,0x8000,Palette650::get(),0,1);return;}
int pred04e0(int);
#pragma aux pred04e0 "f_0d04e0" modify exact [eax];
int pred0590(int);
#pragma aux pred0590 "f_0d0590" modify exact [eax];
int pred0730(int);
#pragma aux pred0730 "f_0d0730" modify exact [eax];
int pred0500(int);
#pragma aux pred0500 "f_0d0500" modify exact [eax];
int pred0550(int);
#pragma aux pred0550 "f_0d0550" modify exact [eax];
int pred0570(int);
#pragma aux pred0570 "f_0d0570" modify exact [eax];
int pred0660(int);
#pragma aux pred0660 "f_0d0660" modify exact [eax];
int pred05b0(int);
#pragma aux pred05b0 "f_0d05b0" modify exact [eax];
int pred0520(int);
#pragma aux pred0520 "f_0d0520" modify exact [eax];
int pred07b0(int);
#pragma aux pred07b0 "f_0d07b0" modify exact [eax];
int pred06f0(int);
#pragma aux pred06f0 "f_0d06f0" modify exact [eax];
int pred05d0(int);
#pragma aux pred05d0 "f_0d05d0" modify exact [eax];

#pragma aux f_06af80 "*" modify exact [eax edx];
void f_06af80(char *p,unsigned char mode)
{
 if(*(int *)(p+0xf0))return;
 char *object=object650(d_1bd934,p);
 if((unsigned)*(int *)p>=0xb0000 && (unsigned)*(int *)p<=0xb0013 ||
    (unsigned)*(int *)p>=0xb0055 && (unsigned)*(int *)p<=0xb005c) {
  int who=character650(d_1c0004,(unsigned char)object[9]);
  short flag=heroFlag650(who);
  switch(mode) {
  case 13:case 14: {
   if(state650(who)==1 || state650(who)==4 || state650(who)==0) {
    if(pred07b0(held650(who))==1 || state650(who)==0) {
     switch(flag) {
      case 1:MSG650(9);
      case -1:case 0:MSG650(1);
      default:MSG650(10);
     }
    } else {
     switch(flag) {case -1:MSG650(1);case 0:MSG650(4);case 1:MSG650(9);case 3:MSG650(5);default:MSG650(6);}
    }
   } else {
    switch(flag) {case -1:MSG650(1);case 0:MSG650(4);case 1:MSG650(9);case 3:MSG650(5);default:MSG650(6);}
   }
  }
  case 17:MSG650(35);
  case 20:if(stat650(who)==4)MSG650(0);MSG650(10);
  case 12:case 15:case 16:case 18:case 19:case 21:case 22:case 23:case 24:
  default:return;
  }
 } else if((unsigned)*(int *)p>=0xb0014 && (unsigned)*(int *)p<=0xb0051) {
  int who=npc650((unsigned char)object[9]);
  signed char flag=npcFlag650(who);
  switch(mode) {
  case 12:
   if(flag==1)DEFAULTMSG650(15);
   if(pred04e0(who)==1)DEFAULTMSG650(22);
   if(pred0590(who)==1)DEFAULTMSG650(23);
   if(pred0730(who)==1) {if(tag650(who)==1)DEFAULTMSG650(36);DEFAULTMSG650(24);}
   if(type650(who)==4){DEFAULTMSG650(15);}else{DEFAULTMSG650(15);}
  case 14:
   if(pred0500(who)==1)MSG650(25);
   if(pred0550(who)==1)MSG650(26);
   if(pred0570(who)==1)MSG650(27);
   if(pred04e0(who)==1)MSG650(28);
   if(pred0660(who)==1)MSG650(29);
   if(pred0590(who)==1)MSG650(30);
   if(pred05b0(who)==1)MSG650(31);
   if(pred0520(who)==1)MSG650(32);
   if(flag==1)MSG650(11);
   if(pred07b0(who)==1)MSG650(1);
   MSG650(7);
  case 13:
   if(pred0500(who)==1)DEFAULTMSG650(25);
   if(pred0550(who)==1)DEFAULTMSG650(26);
   if(pred0570(who)==1)DEFAULTMSG650(33);
   if(pred04e0(who)==1)DEFAULTMSG650(28);
   if(pred0660(who)==1)DEFAULTMSG650(29);
   if(pred0590(who)==1)DEFAULTMSG650(30);
   if(pred05b0(who)==1)DEFAULTMSG650(34);
   if(pred0520(who)==1)DEFAULTMSG650(32);
   if(flag==1)DEFAULTMSG650(11);
   if(pred07b0(who)==1)DEFAULTMSG650(10);
   DEFAULTMSG650(7);
  case 20:
   if(count650(who)>0 && !pred05d0(who))MSG650(0);
   MSG650(10);
  case 15:case 16:case 17:case 18:case 19:case 21:case 22:case 23:case 24:case 25:
  default:return;
  }
 } else if((unsigned)*(int *)p>=0xb0052 && (unsigned)*(int *)p<=0xb0054) {
  int who=npc650((unsigned char)object[9]);
  switch(mode) {
   case 14:if(pred04e0(who)==1)MSG650(64);if(pred06f0(who)==1)MSG650(59);MSG650(68);
   case 13:if(pred04e0(who)==1)MSG650(65);if(pred06f0(who)==1)MSG650(60);MSG650(69);
   case 21:MSG650(61);
   case 16:if(pred04e0(who)==1)MSG650(66);MSG650(70);
   case 19:if(pred04e0(who))MSG650(67);if(pred06f0(who))MSG650(62);MSG650(71);
   case 23:if(pred06f0(who))MSG650(63);MSG650(72);
   default:return;
  }
 } else {
  switch(mode) {case 22:MSG650(3);case 23:MSG650(2);case 26:MSG650(18);case 15:MSG650(52);default:return;}
 }
}
#undef MSG650


#undef DEFAULTMSG650
//@ f_06bd70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erstellt für den Helden p2 im Kampfkontext p1 eine kurze Einzelsequenz mit dem Animationscode
 *   0x26 (Treffer-/Sterbephase) im Puffer p3 und weist sie dem Kampfsprite der Figur (*(int *)(r + 0xf)) über
 *   f_069a00 zu.
 * - Eingaben und Rückgabe: Eingaben sind der Kampfkontext p1 (eax), der Heldenzeiger p2 (edx) und der
 *   164-Byte-Sequenzpuffer p3 (ebx, char *); zurückgegeben wird der Zeiger auf das aktualisierte Kampfsprite
 *   (int in eax).
 * - Wichtige Variablen: r zeigt auf den Kampfraster-Eintrag (f_07ea60) des Helden.
 === Ende Beschreibung === */
int f_06bd70(int p1, int p2, char *p3)
{
    char *r;
    f_145300(p3, 0, 0xa4);
    *(int *)p3 = f_0727e0(p2);
    p3[0xc] = 0x26;
    p3[0xd] = 0;
    p3[0x10] = 0xff;
    r = f_07ea60((char *)(p1 + 0x39), f_043470(p2));
    f_069a00(*(int *)(r + 0xf), p3);
    return *(int *)(r + 0xf);
}
