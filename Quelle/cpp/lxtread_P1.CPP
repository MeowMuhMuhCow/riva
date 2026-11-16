/* === Beschreibung (Katalog) ===
 * Einheit lxtread (Adresse 0x0bac50 - 0x0baee0)
 *
 * Diese Einheit implementiert den Lader für lokalisierte Textdateien im Attic-eigenen LXT -Format (d_1a5308 =
 * 'LXT '). Eine LXT-Datei enthält ab Datei-Offset +0x1a eine Folge nullterminierter Zeichenketten, deren Anzahl
 * im 16-Bit-Feld bei Offset +0x08 gespeichert ist; beim Laden wird ein Zeiger-Array (tab) aufgebaut, das
 * direkten Zugriff auf jeden Text über seinen Index erlaubt.
 === Ende Beschreibung === */
// P3 1/3 gleich (suche.py 29.10.2026, Basis lxtread_P1.CPP)
// lxtread.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BAC50-0x0BAEE0
#include <string.h>
#include "RIVAMEM.H"



int f_0bab50(int p1, int p2);                           // reg edx stapel 0
void f_15ebd6(int p);
int f_15eaf3(unsigned n);
int f_14d0e4(const char *fmt, ...);
void f_148534(int c);
int f_145234(int p1, int p2);
int f_145254(int p1);
extern int *d_1a5308;                    // 0x1A5308
extern int d_1bb264;                    // 0x1BB264
extern int d_1bb278;                    // 0x1BB278
extern const char d_1a530c[];
struct LX { int hdr; int tab; int vt; int f_0badf0(int name); };
#define FREEQ(P) { LX *q = (P); if (q->tab) { f_15ebd6(q->tab); q->tab = 0; } if (q->hdr) { f_15ebd6(q->hdr); q->hdr = 0; } }
#define FREED(P) { if ((P)->tab) { f_15ebd6((P)->tab); (P)->tab = 0; } if ((P)->hdr) { f_15ebd6((P)->hdr); (P)->hdr = 0; } }
struct Load904 {
 static int load(LX *home,int name) {
  int ok=0;
  {LX *first=home; FREED(first);}
  int *raw=(int*)f_0bab50((int)home,name); home->hdr=(int)raw;
  if(raw && *raw==*d_1a5308){
   LX*q=home;int *h=raw;int passed=1;
   q->tab=f_15eaf3((unsigned)*(unsigned short*)(h+2)*4);
   if(q->tab){char*str=(char*)(q->hdr+0x1a);
    for(short k=0;(int)k<(int)(unsigned)*(unsigned short*)(h+2);++k){
     ((char**)q->tab)[k]=str;str+=strlen(str);++str;
    }
   }
   ok=passed;
  }
  if(!ok){LX *last=home;FREED(last);}
  return ok;
 }
};
//@ f_0bac50
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein LXT-Leserobjekt (vt = &d_1bb278), lädt die angegebene Textdatei
 *   name über die Hilfsfunktion Load1096::load in den Speicher und baut die Zeigertabelle auf die einzelnen
 *   Textzeilen auf. Kann die Datei nicht geladen werden oder stimmt die Dateisignatur 'LXT ' nicht, gibt die
 *   Funktion die Fehlermeldung ERRROR 042: Couldn't load message file "%s"! (d_1a530c) aus und bricht das
 *   Programm mit Fehlercode 0x2a (42) ab.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p auf die LX-Struktur sowie die Dateikennung bzw. den
 *   Dateinamen name entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p zurück.
 === Ende Beschreibung === */
LX *f_0bac50(LX *p,int name) {
struct Load1096 {
 static void put(char **data, int off, char *text) { *(char**)((char*)data+off)=text; }
 static int load(LX *home,int name) {
  int ok=0;
  {LX *first=home; FREED(first);}
  int *raw=(int*)f_0bab50((int)home,name); home->hdr=(int)raw;
  if(raw && *raw==*d_1a5308){
   LX*q=home;int *h=raw;
   int keepMagic=d_1bb264;
   unsigned short keepTable=*(unsigned short*)&d_1bb278;
   int passed=1;
   d_1bb264=keepMagic; *(unsigned short*)&d_1bb278=keepTable; // haelt die Registerzuteilung wie im Original
   q->tab=f_15eaf3((unsigned)*(unsigned short*)(h+2)*4);
   if(q->tab){char*str=(char*)(q->hdr+0x1a);
    for(short k=0;(int)k<(int)(unsigned)*(unsigned short*)(h+2);++k){
     int off=(int)k*4; put(*(char***)&q->tab,off,str);str+=strlen(str);++str;
    }
   }
   ok=passed;
  }
  if(!ok){LX *last=home;FREED(last);}
  return ok;
 }
};

 d_1a5308 = (int *)(((int)d_1a5308 & 0) ? 0 : (int)d_1a5308); // haelt die Ladereihenfolge wie im Original
 p->vt=(int)&d_1bb278;p->tab=0;p->hdr=0;
 int ok=Load1096::load(p,name);
 if(!ok){f_14d0e4(d_1a530c,name);f_148534(0x2a);}
 return p;
}
//@ f_0bad80  groesse 112 B, 40 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein LXT-Leserobjekt oder ein Array solcher Objekte (f & 4) ab, gibt
 *   den geladenen Dateipuffer (hdr) sowie die Zeigertabelle (tab) über free (f_15ebd6) frei und löscht bei
 *   gesetztem Flag f & 2 das Objekt selbst vom Heap.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p sowie die Watcom-Destruktor-Flags f entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p zurück.
 === Ende Beschreibung === */
LX *f_0bad80(LX *p, unsigned f)
{
    if (f & 4) {
        f_145254(f_145234((int)p, (int)&d_1bb264));
    } else {
        p->vt = (int)&d_1bb278;
        FREEQ(p);
        if (f & 2) operator delete(p);
    }
    return p;
}
//@ f_0badf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode lädt eine neue LXT-Textdatei name in ein bereits bestehendes LXT-Leserobjekt: Sie gibt
 *   zunächst eventuell vorhandene alte Puffer frei, liest die Rohdatei mit f_0bab50, prüft die 4-Byte-Signatur
 *   'LXT ' (d_1a5308) und füllt das neu reservierte Zeiger-Array tab mit den Startadressen aller
 *   nullterminierten Teilstrings ab Offset +0x1a.
 * - Eingaben: Die Funktion nimmt den impliziten this-Zeiger des LX-Objekts sowie die Dateikennung name entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Datei erfolgreich geladen und indiziert wurde, oder 0 bei
 *   einem Fehler.
 === Ende Beschreibung === */
int LX::f_0badf0(int name)
{
    struct Ops922 {
        static void release(LX *self) {
            if (self->tab) { f_15ebd6(self->tab); self->tab=0; }
            if (self->hdr) { f_15ebd6(self->hdr); self->hdr=0; }
        }
        static void put(char **data, short i, char *text) { data[i]=text; }
        static int build(LX *self, int *head) {
            self=((int)self&0)?(LX*)0:self; // haelt die Registerzuteilung wie im Original
            int keepMagic=d_1bb264;
            unsigned short keepTable=*(unsigned short*)&d_1bb278;
            keepMagic=(keepMagic&0)?0:keepMagic; // haelt die Registerzuteilung wie im Original
            int success=1;
            d_1bb264=keepMagic; *(unsigned short*)&d_1bb278=keepTable; // haelt die Registerzuteilung wie im Original
            self->tab=f_15eaf3((unsigned)*(unsigned short*)(head+2)*sizeof(char*));
            if (self->tab) {
                char *text=(char*)(self->hdr+0x1a);
                for(short i=0; (int)i < (int)(unsigned)*(unsigned short*)(head+2); ++i) {
                    put(*(char ***)&self->tab,i,text);
                    text+=strlen(text);
                    ++text;
                }
            }
            return success;
        }
    };
    int success=0;
    Ops922::release(this);
    int *head=(int*)f_0bab50((int)this,name);
    hdr=(int)head;
    if (head && *head == *d_1a5308)
        success=Ops922::build(this,head);
    if (!success) Ops922::release(this);
    return success;
}
