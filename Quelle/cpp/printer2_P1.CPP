/* === Beschreibung (Katalog) ===
 * Einheit printer2
 *
 * Diese Einheit (aus p:\riva\source\cpp\printer2.cpp) implementiert das Drucken und den Textdatei-Export von
 * Spieltexten, Dokumenten (DOCS<Nr>.TXT) und Tagebucheinträgen einschließlich automatischem Zeilenumbruch an
 * Wortgrenzen, Textzentrierung und Großschreibung am Satzanfang.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 6/9 gleich (suche.py 29.10.2026, Basis printer2_P1.CPP)
// printer2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E8810-0x0E9240
#include <string.h>
#include "RIVAMEM.H"




int f_069460();
int f_0bf730(int p1, int p2);
int f_0bf820(void *p, ...);
int f_0ce250(int p1);
int f_0ce280(int p1);
int f_0ce2b0(char *p1);
int f_0d2e70();
int f_0d2f90(int p1, int p2);
int f_125400(void *p1, int p2, int p3, int p4);
int f_1254a0(void *p1, int p2);
char f_145400(int p1);
void f_145300(char *p, int c, int n);
char *f_148143(char *d, const char *s, unsigned n);
int f_149336(const char *p);
char *f_148518(int p1, char *p2, int p3);
int f_145259(int p1);
int f_144fbf(const char *p, int a, ...);
int f_144cb6(int h, const char *p, unsigned n);
struct OB { int a[15]; };
struct S20 { int a[5]; };
extern int d_1a65c8[5];
extern int d_1a965c;
extern char d_1b830a[];
extern char d_1b830f[];
extern char d_1b8314[];
extern char d_1b8319[];
extern unsigned char d_1bbfdc[];
extern signed char d_1bfaf0, d_1bfaf8;
extern signed char d_1bfaf4;
#define SG(x) (x)
extern unsigned short d_1c0090;
extern char *d_1c0094;
extern int d_1c0098;
extern unsigned char d_1c20b0;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a65a8[];
//@ f_0e8810
/* === Beschreibung (Katalog) ===
 * Erzeugt aus dem Namen eines Helden (p1, abgefragt über f_0422b0) einen gültigen DOS-Dateinamen mit relativem
 * Pfadpräfix ..\ und der Endung .TXT (maximal 8 Zeichen für den Namen, wobei Sonderzeichen bei Bedarf durch
 * Unterstriche _ ersetzt werden) und speichert ihn im Ausgabepuffer p2.
 * - Eingaben: Übergeben werden der Zeiger auf die Heldenstruktur p1 sowie der Zielpuffer p2 für den erzeugten
 *   Dateinamen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8eb0(char *p1, short p2);
void f_0e8cd0(void);
void f_0e8810(int p1, char *p2)
{
  char buf[20];
  short k;
  signed char c;
  *(struct S20 *)buf = *(struct S20 *)d_1a65c8;
  strcat(buf, (char *)((int)(f_0422b0((struct hero *)(p1)))));
  for (k = 3; k < 0xb; ++k) {
    c = buf[k];
    if (c && (((signed char)d_1bbfdc[(unsigned char)(c + 1)] & 0xe0) == 0) &&
        *(unsigned short *)&d_1c20b0 == 1 && c != (signed char)0x99 &&
        c != (signed char)0x8e && c != (signed char)0x9a && c != (signed char)0xe1)
      p2[k] = '_';
  }
  f_148143(p2, buf, 0xb);
  p2[0xb] = 0;
  strcat(p2, d_1b830a);
}
//@ f_0e88f0
/* === Beschreibung (Katalog) ===
 * Gibt den aktuellen Überschriftentext in d_1c27a8 zentriert (f_0e8eb0(..., 1)) und anschließend den Haupttext
 * in d_1c21b4 linksbündig (f_0e8eb0(..., 0)) auf das aktuell geöffnete Ausgabegerät (Datei oder Drucker) aus.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e88f0(void)
{
  struct OB ob;
  f_125400(&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  d_1c0090 = 0;
  d_1c0094 = d_1c27a8;
  f_0e8eb0(d_1c27a8, 1);
  d_1c0094 = d_1c21b4;
  strlen(d_1c21b4);
  f_0e8eb0(d_1c0094, 0);
  f_1254a0(&ob, 0);
}
//@ f_0e8970
/* === Beschreibung (Katalog) ===
 * Schaltet den Mauszeiger auf das Sanduhr-Symbol (f_0d2f90(5, 1)), gibt Überschrift (d_1c27a8, zentriert) und
 * Haupttext (d_1c21b4, linksbündig) über f_0e8eb0 aus, sendet im Druckermodus (d_1bfaf0 > 0) bei
 * unterschrittener Mindestzeilenanzahl (d_1c0090 < d_1bfaf8) einen Seitenvorschub (0x0c) und stellt abschließend
 * den Mauszeiger wieder her (f_0d2e70).
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8970(void)
{
  struct OB ob;
  f_0d2f90(5, 1);
  f_125400(&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  d_1c0090 = 0;
  d_1c0094 = d_1c27a8;
  f_0e8eb0(d_1c27a8, 1);
  d_1c0094 = d_1c21b4;
  strlen(d_1c21b4);
  f_0e8eb0(d_1c0094, 0);
  f_1254a0(&ob, 0);
  signed char modus = d_1bfaf0;
  if ((int)modus > 0) {
    signed char grenze = d_1bfaf8;
    int grenze_i = grenze;
    if ((short)d_1c0090 < grenze_i) f_0ce280(0xc);
  }
  d_1a965c = 0;
  f_0d2e70();
}
//@ f_0e8a30
/* === Beschreibung (Katalog) ===
 * Exportiert oder druckt ein nummeriertes Spieldokument: Im Dateimodus (d_1bfaf0 == 0) legt sie die Datei
 * DOCS<p1>.TXT an, im Druckermodus prüft sie in einer Schleife die Druckerbereitschaft (f_0ce250), gibt danach
 * Überschrift (d_1c27a8) und Dokumenttext (d_1c21b4) über f_0e8eb0 aus und schließt die Datei bzw. sendet einen
 * Seitenvorschub.
 * - Eingaben: Die Funktion erhält die laufende Nummer p1 des zu speichernden oder zu druckenden Dokuments.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8a30(short p1)
{
  struct OB ob;
  char path[20];
  char num[4];
  int failed = 0;
  int choice;
  strcpy(path, d_1b830f);
  f_148518(p1, num, 10);
  strcat(path, num);
  strcat(path, d_1b8314);
  signed char mode = d_1bfaf0;
  int g = mode;
  if (g == 0) {
    f_149336(path);
    d_1c0098 = f_144fbf(path, 0x221, 0x180);
    if (d_1c0098 <= 0) {
      failed = 1;
      f_0bf730((int)&d_1c2c64, 0x8030069);
    }
  } else {
    choice = g;
    for (;;) {
      if (f_0ce250(choice)) break;
      choice = (short)f_0bf820(&d_1c2c64, 0x8030066, 2, 0x803006c, 0x803006d);
      if (choice != 1) {
        failed = 1;
        break;
      }
    }
  }
  if (!failed) {
    f_0d2f90(5, 1);
    f_125400(&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    d_1c0090 = 0;
    d_1c0094 = d_1c27a8;
    f_0e8eb0(d_1c27a8, 1);
    d_1c0094 = d_1c21b4;
    strlen(d_1c21b4);
    f_0e8eb0(d_1c0094, 0);
    f_1254a0(&ob, 0);
    signed char modus = d_1bfaf0;
    if ((int)modus > 0) {
      signed char grenze = d_1bfaf8;
      int grenze_i = grenze;
      if ((short)d_1c0090 < grenze_i) f_0ce280(12);
    }
    d_1a965c = 0;
    f_0d2e70();
    signed char modus2 = d_1bfaf0;
    if ((int)modus2 == 0) f_145259(d_1c0098);
  }
}
//@ f_0e8c20
/* === Beschreibung (Katalog) ===
 * Öffnet das Druckziel für den übergebenen Dateinamen p1: Ist das Drucken deaktiviert (d_1bfaf0 == -1), zeigt
 * sie eine Fehlermeldung (0x8030067); im Dateimodus (d_1bfaf0 == 0) öffnet sie die Ausgabedatei p1 (d_1c0098);
 * im Druckermodus prüft sie über f_0ce250, ob der Drucker bereit ist, und bietet bei einem Fehler einen
 * Wiederholen-Dialog (0x8030066) an.
 * - Eingaben: Die Funktion erhält den Zeiger auf den Dateinamen p1 für den Dateiexport.
 * - Rückgabewert: Sie gibt 0 zurück, wenn die Datei bzw. der Drucker erfolgreich bereitgestellt wurde, oder 1
 *   bei einem Fehler bzw. Abbruch.
 === Ende Beschreibung === */
short f_0e8c20(char *p1)
{
  int r = 0;
  signed char modus = d_1bfaf0;
  int g = modus;
  short s;
  if (g == -1) {
    r = 1; f_0bf730((int)&d_1c2c64, 0x8030067); return r;
  }
  if (g == 0) {
    f_149336(p1);
    d_1c0098 = f_144fbf(p1, 0x221, 0x180);
    if (d_1c0098 <= 0) {
      r = 1; f_0bf730((int)&d_1c2c64, 0x8030069); return r;
    }
  } else {
    do {
      if (f_0ce250(g)) return r;
      s = f_0bf820(&d_1c2c64, 0x8030066, 2, 0x803006c, 0x803006d);
      g = s;
    } while (g == 1);
    r = 1;
  }
  return r;
}
//@ f_0e8cd0
/* === Beschreibung (Katalog) ===
 * Sendet im Druckermodus (d_1bfaf0 > 0) ein Seitenvorschub-Steuerzeichen (0x0c, Form Feed) an den Drucker
 * (f_0ce280), sofern die bisher gedruckte Zeilenanzahl d_1c0090 kleiner als der Schwellenwert d_1bfaf8 ist.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8cd0(void)
{
  signed char modus = d_1bfaf0;
  if ((int)modus > 0) {
    signed char grenze = d_1bfaf8;
    int grenze_i = grenze;
    if ((short)d_1c0090 < grenze_i) f_0ce280(0xc);
  }
}
//@ f_0e8d00
/* === Beschreibung (Katalog) ===
 * Zentriert eine Textzeile p1 innerhalb der konfigurierten Druckspaltenbreite d_1bfaf4, indem vor den Text
 * (d_1bfaf4 - strlen(p1)) / 2 Leerzeichen (0x20) eingefügt werden.
 * - Eingaben: Die Funktion erhält den Zeiger auf die zu zentrierende Zeichenkette p1, die direkt vor Ort
 *   überschrieben wird.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8d00(char *p1)
{
  unsigned char c;
  short h;
  char *buf;
  c = SG(d_1bfaf4) - strlen(p1);
  h = (signed char)c >> 1;
  buf = new (mark(d_1a65a8, 0x19a)) char[(signed char)(SG(d_1bfaf4) + 1)];
  if ((int)h > 0) f_145300(buf, 0x20, (short)(h & 0xffff));
  strcat(buf, p1);
  strcpy(p1, buf);
  delete buf;
}
//@ f_0e8dc0
/* === Beschreibung (Katalog) ===
 * Führt einen automatischen Zeilenumbruch an Wortgrenzen für den Fließtext p1 auf die Druckspaltenbreite
 * d_1bfaf4 durch: Vorhandene Zeilenumbrüche (\r, \n) werden zunächst in Leerzeichen umgewandelt, harte
 * Umbruchmarken (@) setzen den Spaltenzähler zurück, und beim Erreichen der maximalen Zeilenbreite wird das
 * letzte Leerzeichen der Zeile durch ein Wagenrücklaufzeichen (\r, 13) ersetzt.
 * - Eingaben: Die Funktion erhält den Zeiger auf den umzubrechenden Textpuffer p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8dc0(char *p1)
{
    short i = 0;
    short sp = 0;
    short z = 0;
    char *start = p1;
    short n = 0;
    char *q;
    if (!p1) return;
    if (*p1) do {
        if ((signed char)*p1 == 13 || (signed char)*p1 == 10) *p1 = 32;
        signed char next = p1[1];
        p1++;
        if (!next) break;
    } while (1);
    p1 = start;
    int width;
    while (*(q = p1 + i)) {
        signed char w = d_1bfaf4;
        width = w;
        if (++n >= width) {
            if (sp != z) {
                p1 += sp;
                *p1 = 13;
            } else {
                *q = 13;
                p1 += i + 1;
            }
            n = 0;
            z = 0;
            sp = 0;
            i = 0;
        }
        if ((signed char)p1[i] == 32) sp = i;
        int old = i;
        if ((signed char)p1[i] == 64) {
            i = -1;
            n = 0;
            z = 0;
            sp = 0;
            p1 += old + 1;
        }
        i++;
    }
    int w2 = 0;
    signed char w = d_1bfaf4;
    (void)(((int)p1 & 0) ? 1 : 0); // haelt p1 am Schleifenende im Register wie im Original
    w2 = w;
    (void)(((int)q & 0) ? 1 : 0); // haelt q am Schleifenende im Register wie im Original
    if (n >= w2) {
        if (sp == z) q[-1] = 0;
        else p1[sp] = 13;
    }
}
//@ f_0e8eb0
/* === Beschreibung (Katalog) ===
 * Formatiert und druckt einen mehrzeiligen Textblock p1 (optional zentriert, wenn p2 != 0): Nach dem Wortumbruch
 * über f_0e8dc0 zerlegt die Funktion den Text an @- und \r-Zeichen in Einzelzeilen, filtert Farbsteuerzeichen
 * (0xf0..0xf5) heraus, wandelt geschützte Leerzeichen (^) in normale Leerzeichen um, schreibt Satzanfänge nach
 * ., !, ? oder Steuerzeichen 0xf6 groß (f_145400) und gibt jede Zeile in die Ausgabedatei (d_1c0098) oder an den
 * Drucker aus, wobei der Zeilenzähler d_1c0090 mitgeführt wird.
 * - Eingaben: Übergeben werden der auszugebende Textpuffer p1 sowie das Zentrierungsflag p2 (1 für zentrierte
 *   Ausgabe, 0 für linksbündige Ausgabe).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e8eb0(char *p1, short p2)
{
    struct Druck {
        static signed char modus() { return d_1bfaf0; }
        static void zeile(char *s) {
            if (modus() == 0) {
                char *nl = d_1b8319;
                if (s) f_144cb6(d_1c0098, s, strlen(s));
                f_144cb6(d_1c0098, nl, strlen(nl));
            } else {
                if (s) {
                    f_0ce2b0(s);
                    f_069460();
                }
                f_0ce280(13);
                f_0ce280(10);
            }
        }
        static void zentrieren(char *s) {
            unsigned char c;
            short h = 0; // haelt die Lebensdauer fuer die Registervergabe wie im Original
            char *buf;
            c = SG(d_1bfaf4) - strlen(s);
            h = (signed char)c >> 1;
            // haelt die Registervergabe zusammen mit dem Rueckschreiben am Funktionsende wie im Original
            buf = new (mark(d_1a65a8, 0x19a)) char[(SG(d_1bfaf4) & 0) ? 0U : (unsigned)(signed char)(SG(d_1bfaf4) + 1)];
            if ((int)h > 0) f_145300(buf, 0x20, (short)(h & 0xffff));
            strcat(buf, s);
            strcpy(s, buf);
            delete buf;
        }
    };
    short i = 0;
    short len = strlen(p1);
    unsigned short flag = 0;
    unsigned char c;

    f_0e8dc0(p1);
    for (; i < len; ) {
        short j;
        j = 0;
        c = p1[i];
        while (c != '@' && c != '\r' && i < len) {
            if (c == 0xf1 || c == 0xf2 || c == 0xf3 || c == 0xf4 ||
                c == 0xf5 || c == 0xf0) {
            } else if (c == 0xf6) {
                flag = 1;
            } else if (c == 0xf7) {
                flag = 0;
            } else if (c == '^') {
                d_1c27a8[j++] = ' ';
            } else if (flag) {
                if (c >= '!' && c <= 0xf0 && c != '@' && c != '.' &&
                    c != '!' && c != '?' && c != '<' && c != ':') {
                    d_1c27a8[j++] = f_145400(c);
                    flag = 0;
                } else {
                    d_1c27a8[j++] = c;
                }
            } else {
                if (c == '.' || c == '!' || c == '?') flag = 1;
                d_1c27a8[j++] = c;
            }
            c = p1[++i];
        }
        d_1c27a8[j] = 0;
        if (p2 != (short)0) Druck::zentrieren(d_1c27a8);
        Druck::zeile(d_1c27a8);
        d_1c0090 = d_1c0090 + 1;
        if (c == '@' || c == '\r') {
            c = p1[++i];
        }
        while (c == '@' || c == '\r') {
            Druck::zeile(0);
            d_1c0090 = d_1c0090 + 1;
            c = p1[++i];
        }
        while (c == ' ' || c == '^') {
            c = p1[++i];
        }
    }{ signed char rt905 = d_1bfaf4; d_1bfaf4 = rt905; } // haelt das Gewicht von d_1bfaf4 fuer die Registervergabe wie im Original

}
