/* === Beschreibung (Katalog) ===
 * Einheit printer_t1
 *
 * Diese Einheit (aus p:\riva\source\cpp\printer.cpp, Teil 1) implementiert den Ausdruck bzw. Dateiexport des
 * Charakterbogens eines Helden. Sie lädt die Vorlagentexte aus dem Archiv und gibt die erste Seite des
 * Heldenbogens (Grundwerte, Eigenschaften, abgeleitete Kampfbasiswerte, Waffentalente, sämtliche Talente sowie
 * die 31 Ausrüstungsplätze) entweder in eine .TXT-Datei oder auf den angeschlossenen Drucker aus.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/2 gleich (suche.py 26.10.2026, Basis printer_t1_P1.CPP)
// printer.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E4CB0-0x0E74E0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
extern const char d_1a6588[];
extern signed char d_1bfaf0;
extern char *d_1c0088;
extern char **d_1c008c;
extern int d_1c0098;
extern char  d_1c27a8[], d_1c2c64[], d_1c3498[];
extern char d_1b82d8[], d_1b82db[], d_1b82dd[], d_1b82df[], d_1b82e1[], d_1b82e3[], d_1b82e5[], d_1b82e7[], d_1b82e9[], d_1b82eb[], d_1b82ed[];
char *f_014540(int, const char *, int);
int f_014a60(void);
signed char f_03ad80(int, int);

short f_045300(int);
short f_0456e0(int, int);
short f_045710(int, int);
int f_069460(void);
int f_0bf730(char *, int);
short f_0bf820(char *, ...);
int f_0ce250(void);
int f_0ce280(int);
int f_0ce2b0(char *);
int f_0e7560(int, int, short *, short *, short *, short *, short *, short *);
int f_0e7720(int);
int f_0e8580(int, int, int);
int f_0e8810(int, char *);
int f_133fe0(char *, char *);

int f_144cb6(int, const char *, unsigned);
int f_144fbf(char *, ...);
int f_145259(int);
int f_14572e(char *, ...);
int f_145300(char *, int, int);
int f_148143(char *, int, int);
#define T(i) d_1c008c[i]
#define PRINT(s) if (d_1bfaf0 == 0) { if (f_144cb6(d_1c0098, (s), strlen(s))) f_144cb6(d_1c0098, d_1b82d8, strlen(d_1b82d8)); } else { f_0ce2b0(s); f_069460(); f_0ce280(0xd); f_0ce280(10); }

struct Choice660 { static void select(int p,int &main,int &extra) { if(f_042a10((struct hero *)(p))) { short s=f_0bf820(d_1c2c64, f_133fe0(d_1c3498, T(0x70)), 3, f_133fe0(d_1c3498, T(0x71)), f_133fe0(d_1c3498, T(0x72)), f_133fe0(d_1c3498, T(0x73))); if(s!=-1){if(s==1)main=1;else if(s==2)extra=1;else if(s==3){main=1;extra=1;}} }else main=1; } };

//@ f_0e4cb0
/* === Beschreibung (Katalog) ===
 * Lädt die Textdatei mit den Druckvorlagen für den Charakterbogen (Archivkennung 0x30024) in den dynamisch
 * reservierten Puffer d_1c0088 und baut in d_1c008c das Zeigerarray für die 158 (0x9d Folgezeiger) Formatstrings
 * auf, sofern genügend freier Heap-Speicher (f_014a60) vorhanden ist.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt 1 zurück, wenn der Textblock erfolgreich geladen wurde (oder die Datei nicht geöffnet
 *   werden konnte), und 0, falls der verfügbare Arbeitsspeicher nicht ausreichte.
 === Ende Beschreibung === */
int f_0e4cb0(void)
{
  int rc = 1; int sz; int limit; char *pc; char **pp; unsigned short n;
  if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x30024, 0x200)) {
    sz = ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144a00()));
    limit = sz + 0x278;
    if (f_014a60() < limit) {
      ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
      rc = 0;
    } else {
      d_1c0088 = f_014540(sz, d_1a6588, 0x62);
      d_1c008c = (char **)f_014540(0x278, d_1a6588, 99);
      ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( d_1c0088), sz)));
      ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
      pp = d_1c008c + 1; pc = d_1c0088; n = 0; *--pp = pc; ++pp;
      do {
        if (!*pc) { *pp++ = pc + 1; ++n; }
        pc++;
      } while (n < (unsigned short)0x9d);
    }
  }
  return rc;
}

//@ f_0e4d80
/* === Beschreibung (Katalog) ===
 * Steuert den kompletten Ausdruck oder Dateiexport des Charakterbogens für den Helden p: Sie lädt die
 * Formatvorlagen (0x30024), öffnet je nach Ausgabemodus d_1bfaf0 entweder eine nach dem Helden benannte
 * .TXT-Datei (f_0e8810) oder prüft die Druckerbereitschaft (f_0ce250), lässt bei magiebegabten Helden (f_042a10)
 * auswählen, ob das Hauptblatt (fa), das Zauberblatt (fb) oder beide gedruckt werden sollen, und gibt auf dem
 * Hauptblatt Name, Typus, Geschlecht, Stufe, Erfahrungspunkte, Gottheit, Geld, positive und negative
 * Eigenschaften, Lebens-/Astralenergie, Ausdauer, Magieresistenz, Kampftalente (AT/PA), sämtliche Talente sowie
 * über f_0e8580 und f_0e7560 alle 31 Inventarplätze aus, bevor optional f_0e7720 für das Zauberblatt aufgerufen
 * wird.
 * - Eingaben: Die Funktion erhält den Zeiger auf die Heldenstruktur p, deren Charakterbogen ausgegeben werden
 *   soll.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
extern char *volatile text790; // haelt das erneute Laden von d_1c0088 in Loader790 wie im Original
#pragma aux text790 "d_1c0088";
struct Loader790 { static void load() { 
  int sz; char *pc; char **pp; unsigned short n;
  if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x30024, 0x200)) {
    sz = ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144a00()));
    int limit = sz + 0x278;
    if (f_014a60() < limit) {
      ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    } else {
      d_1c0088 = f_014540(sz, d_1a6588, 0x62);
      d_1c008c = (char **)f_014540(0x278, d_1a6588, 99);
      ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( d_1c0088), sz)));
      ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
      pp = d_1c008c + 1; pc = text790; n = 0; pp[-1] = pc;
      do {
        if (!*pc) { *pp++ = pc + 1; ++n; }
        pc++;
      } while (n < (unsigned short)0x9d);
    }
  }
} };

struct Print660 { void f_0e4d80(); int print(char*s){int r=0;
    signed char fl=d_1bfaf0;
    if(fl==0){int written=f_144cb6(d_1c0098,s,strlen(s));if(written!=0){r=1;f_144cb6(d_1c0098,d_1b82d8,strlen(d_1b82d8));}}
    else{f_0ce2b0(s);f_069460();f_0ce280(0xd);r=f_0ce280(10);}
    return r;} };


#undef PRINT
#define PRINT(s) ((Print660 *)p)->print((s))
void f_0e4d80(int p)
{
  struct PrinterFlag { static signed char get() { return d_1bfaf0; } };
#define d_1bfaf0 PrinterFlag::get()
  char *ptr; int err; int fa; int fb; short sv;
  short avg;
  char b2[8]; char b1[12]; char name[20];
  int sz; char *pc; char **pp; unsigned short n; char *t; int r;
  fb = 0; fa = 0; err = 0;
  Loader790::load();
  if (d_1bfaf0 == 0) {
    ptr = new (mark(d_1a6588, 0x85)) char[20];
    int name790(int,char*);
#pragma aux name790 "f_0e8810" parm [eax] [edx] value [eax] modify exact [eax edx ebx];
    name790(p, ptr);
    d_1c0098 = f_144fbf(ptr, 0x261, 0x180);
    if (d_1c0098 <= 0) {
      err = 1;
      f_0bf730(d_1c2c64, f_133fe0(d_1c3498, T(0x6e)));
      operator delete(ptr);
    }
  } else {
    if (f_0ce250() == 0) {
      err = 1;
      f_0bf730(d_1c2c64, f_133fe0(d_1c3498, T(1)));
    } else {
      f_0bf820(d_1c2c64, f_133fe0(d_1c3498, T(0)), 1, f_133fe0(d_1c3498, T(0x6d)));
    }
  }
  if (err == 0) {
    Choice660::select(p,fa,fb);
    if (fa != 0) {
      t = T(3); PRINT(t); PRINT(d_1b82db);
      f_14572e(d_1c27a8, T(4), ((int)(f_0422b0((struct hero *)(p)))), T(f_042350((struct hero *)(p)) + (((char)(f_042380((struct hero *)(p)))) ? 0x8f : 0x83)), !((char)(f_042380((struct hero *)(p)))) ? T(0x74) : T(0x75));
      PRINT(d_1c27a8); PRINT(d_1b82dd);
      f_14572e(d_1c27a8, T(5), f_0428b0((struct hero *)(p)), f_0428c0((struct hero *)(p)), T(0x75 + f_042390((struct hero *)(p))));
      PRINT(d_1c27a8); PRINT(d_1b82df);
      f_14572e(d_1c27a8, T(6), ((int)(f_0428f0((struct hero *)(p)))), f_0428d0((struct hero *)(p)));
      PRINT(d_1c27a8); PRINT(d_1b82e1);
      f_14572e(d_1c27a8, T(7), f_042a40((struct hero *)(p), 0), *((signed char *)(f_0429c0((struct hero *)(p), 0))), f_042a40((struct hero *)(p), 7), *((signed char *)(f_0429c0((struct hero *)(p), 7))), f_042890((struct hero *)(p)));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(8), f_042a40((struct hero *)(p), 1), *((signed char *)(f_0429c0((struct hero *)(p), 1))), f_042a40((struct hero *)(p), 8), *((signed char *)(f_0429c0((struct hero *)(p), 8))));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(9), f_042a40((struct hero *)(p), 2), *((signed char *)(f_0429c0((struct hero *)(p), 2))), f_042a40((struct hero *)(p), 9), *((signed char *)(f_0429c0((struct hero *)(p), 9))), f_0456e0(p, 0), f_045710(p, 0));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(10), f_042a40((struct hero *)(p), 3), *((signed char *)(f_0429c0((struct hero *)(p), 3))), f_042a40((struct hero *)(p), 10), *((signed char *)(f_0429c0((struct hero *)(p), 10))), f_0456e0(p, 1), f_045710(p, 1));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(11), f_042a40((struct hero *)(p), 4), *((signed char *)(f_0429c0((struct hero *)(p), 4))), f_042a40((struct hero *)(p), 11), *((signed char *)(f_0429c0((struct hero *)(p), 11))), f_0456e0(p, 2), f_045710(p, 2));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(12), f_042a40((struct hero *)(p), 5), *((signed char *)(f_0429c0((struct hero *)(p), 5))), f_042a40((struct hero *)(p), 12), *((signed char *)(f_0429c0((struct hero *)(p), 12))), f_0456e0(p, 3), f_045710(p, 3));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(13), f_042a40((struct hero *)(p), 6), *((signed char *)(f_0429c0((struct hero *)(p), 6))), f_042a40((struct hero *)(p), 13), *((signed char *)(f_0429c0((struct hero *)(p), 13))), f_0456e0(p, 4), f_045710(p, 4));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(14), f_0456e0(p, 5), f_045710(p, 5));
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(15), f_042970((struct hero *)(p)), f_0429b0((struct hero *)(p)), f_0456e0(p, 6), f_045710(p, 6));
      PRINT(d_1c27a8); PRINT(d_1b82e3);
      avg = (f_042a40((struct hero *)(p), 1) + f_042a40((struct hero *)(p), 4) + f_042a40((struct hero *)(p), 6)) / 4;
      f_14572e(d_1c27a8, T(16), f_0423a0((struct hero *)(p)), f_0423c0((struct hero *)(p)), f_03ad80(p, 7) + avg);
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(17), f_042960((struct hero *)(p)) + f_042a40((struct hero *)(p), 6), f_045300(p), f_03ad80(p, 8) + avg);
      PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(18), f_042a40((struct hero *)(p), 6) * 100, f_043170((struct hero *)(p)));
      PRINT(d_1c27a8);
      t = T(0x13); PRINT(t); PRINT(d_1b82e5);
      t = T(0x14); PRINT(t);
      f_14572e(d_1c27a8, T(0x15), f_03ad80(p, 0), f_03ad80(p, 0x29), f_03ad80(p, 0x20)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x16), f_03ad80(p, 1), f_03ad80(p, 0x2a), f_03ad80(p, 0x21)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x17), f_03ad80(p, 2), f_03ad80(p, 0x2b), f_03ad80(p, 0x22)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x18), f_03ad80(p, 3), f_03ad80(p, 0x2c), f_03ad80(p, 0x23)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x19), f_03ad80(p, 4), f_03ad80(p, 0x2d), f_03ad80(p, 0x24)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x1a), f_03ad80(p, 5), f_03ad80(p, 0x2e), f_03ad80(p, 0x25)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x1b), f_03ad80(p, 6), f_03ad80(p, 0x2f), f_03ad80(p, 0x26)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x1c), f_03ad80(p, 7), f_03ad80(p, 0x30), f_03ad80(p, 0x27)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x1d), f_03ad80(p, 8), f_03ad80(p, 0x31), f_03ad80(p, 0x28)); PRINT(d_1c27a8);
      PRINT(d_1b82e7);
      t = T(0x1e); PRINT(t);
      f_14572e(d_1c27a8, T(0x1f), f_03ad80(p, 9), f_03ad80(p, 0x13), f_03ad80(p, 0x1a)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x20), f_03ad80(p, 10), f_03ad80(p, 0x14), f_03ad80(p, 0x1b)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x21), f_03ad80(p, 11), f_03ad80(p, 0x15), f_03ad80(p, 0x1c)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x22), f_03ad80(p, 12), f_03ad80(p, 0x16), f_03ad80(p, 0x1d)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x23), f_03ad80(p, 13), f_03ad80(p, 0x17), f_03ad80(p, 0x1e)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x24), f_03ad80(p, 14), f_03ad80(p, 0x18), f_03ad80(p, 0x1f)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x25), f_03ad80(p, 15), f_03ad80(p, 0x19)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x26), f_03ad80(p, 0x11), f_03ad80(p, 0x10)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x27), f_03ad80(p, 0x12)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x28), f_03ad80(p, 0x32)); PRINT(d_1c27a8);
      f_14572e(d_1c27a8, T(0x29), f_043340((struct hero *)(p)), f_03ad80(p, 0x33)); PRINT(d_1c27a8);
      t = T(0x2a); PRINT(t);
      t = T(0x2b); PRINT(t);
      PRINT(d_1b82e9);
      f_0e8580(p, 0, 1); f_0e8580(p, 2, 3); f_0e8580(p, 4, 5); f_0e8580(p, 6, 7);
      f_0e8580(p, 8, 9); f_0e8580(p, 10, 11); f_0e8580(p, 12, 13); f_0e8580(p, 14, 15);
      f_0e8580(p, 16, 17); f_0e8580(p, 18, 19); f_0e8580(p, 20, 21); f_0e8580(p, 22, 23);
      f_0e8580(p, 24, 25); f_0e8580(p, 26, 27); f_0e8580(p, 28, 29);
      short s14; short s18; short s10; short s0c; short s1c; short s08;
      r = f_0e7560(p, 0x1e, &s10, &s14, &s18, &s08, &s0c, &s1c);
      f_14572e(b1, s0c != -1 ? T(0x32) : T(0x33), s0c, s1c);
      f_14572e(b2, s08 != -1 ? T(0x34) : T(0x35), s08);
      f_145300(name, 0, 0x14);
      f_148143(name, r, 0xe);
      f_14572e(d_1c27a8, !s10 ? T(0x31) : T(0x2d), s14, name, s18, b2, b1);
      PRINT(d_1c27a8);
      if (d_1bfaf0 == 0) {
        PRINT(d_1b82eb);
        t = T(0x6f); PRINT(t);
        PRINT(d_1b82ed);
      } else { f_0ce280(0xc); }
    }
    if (fb != 0) f_0e7720(p);
    if (d_1bfaf0 == 0) {
      f_145259(d_1c0098);
      operator delete(ptr);
    }
  }
  operator delete(d_1c0088);
  operator delete(d_1c008c);
#undef d_1bfaf0
}

#undef PRINT
