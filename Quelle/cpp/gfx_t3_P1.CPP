/* === Beschreibung (Katalog) ===
 * Einheit gfx_t3 (099da0-09af30)
 *
 * Überblick
 * Diese Einheit enthält zentrale Grafik- und VGA-Hilfsfunktionen des Spiels (GFX.CPP): das Setzen der
 * VGA-Hardwarepalette mit VSync-Synchronisation, weiche Palettenüberblendungen (Fade-In/Fade-Out), das Setzen
 * und Abfragen des globalen Clipping-Rechtecks, Bildübergangseffekte (Pseudozufalls-Pixelblende und
 * Jalousie-Wischeffekt), Farbnachbarschaftssuche, Abdunkeln und Vergrauen von Bildausschnitten sowie das Sichern
 * und Wiederherstellen ganzer 320x200-Bildschirme im RAM oder auf Festplatte.
 === Ende Beschreibung === */
// P3 29/34 gleich (suche.py 30.10.2026, Basis gfx_t3_P1.CPP)
// Astra650: privat 20/34 GLEICH; ganze Einheit geprueft.
// OPT -4r -oneatx -zp1 -s
// Astra782: drei Grafikfunktionen vollstaendig aus Original/Ghidra rekonstruiert; normales C++ ohne Assembler.
// gfx_t3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x099DA0-0x09AF30
#include <string.h>
#include <conio.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
int f_014540(int p1, int p2, int p3);
int f_014a60();
int f_068f40();
int f_0b8490(int p1, int p2);
int f_0b8520(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0fade0(void *o, void *b, int x, int y);
int f_144920(int p1, int p2, int p3);
int f_1448b0(int p1, int p2, int p3);
int f_144960(int p1, int p2, int p3);
int f_144ab0(int p1, int p2, int p3);
int f_144af0(int p1, int p2);
int f_1449a0(int p1);
int f_145234(int p1, int p2);
void f_145254(void);
void f_145300(void *p, int c, unsigned n);
void *f_147c84(void *p, int n, void *t);
int f_149cf0(int p1);

int f_149d20();
void __cdecl f_149eb4(int p, int v, int n);
void f_14d075(int d, int s, int n);
int f_15689d(int p1, int p2, int p3, int p4);
int f_1568b9(int p1);
extern short d_1bdbd4, d_1bdbd6, d_1bdbd8, d_1bdbdc;
extern unsigned short d_1bdbda;
extern int d_1bdbe4, d_1bdbe8;
extern int d_1bdcec, d_1bdcf0, d_1a965c, d_1a34e8;
extern signed char d_1a34e4;
extern unsigned char *d_1a34e0;
extern unsigned char d_1bdbec[];
extern int d_1c2098, d_1c2c64;
extern char d_1baac0[];
extern int d_1baf88;
extern int d_1baf9c[];
extern const char d_1a34c4[];
#define FL ((int)&d_1c2098)
#define VSYNC() { outp(0x3d4, 0x11); unsigned b_ = inp(0x3d5) & ~0x20; outp(0x3d4, 0x11); outp(0x3d5, b_); while ((inp(0x3da) & 8) == 0) ; while ((inp(0x3da) & 8) != 0) ; }

struct MG {
    int fl;
    MG()
    { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; } }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
struct SO { char c[12]; SO(int w, int h, void *p); ~SO(); };
struct RGB { unsigned char r, g, b; };
void f_09a180(int p1, int p2, short p3, short p4, int p5);
void f_09a2d0(unsigned char *p1, unsigned char *p2, unsigned char *p3, short p4, short p5);
void f_09a720(short *p1, unsigned char *p2, unsigned char *p3, unsigned char *p4, int p5, int p6);

//@ f_099da0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein abgeleitetes Gebäude- oder Szenenobjekt über den Basiskonstruktor f_0b8490 und
 *   trägt die virtuelle Methodentabelle d_1baf9c an Offset 0x58 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Kennung p2 (short) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(... + 0x58) speichert den Zeiger auf die virtuelle Methodentabelle
 *   d_1baf9c.
 === Ende Beschreibung === */
void f_099da0(int p1, short p2)
{
  *(int *)(f_0b8490(p1, p2) + 0x58) = (int)d_1baf9c;
}

//@ f_099db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des mit f_099da0 erzeugten Objekts, ruft den Basisdestruktor f_0b8520 auf
 *   und gibt bei gesetztem Bit 2 in p2 den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2 und gibt die
 *   Objektadresse zurück (int).
 * - Wichtige Variablen: Der Deskriptor d_1baf88 wird bei Array-Abbau (p2 & 4) an f_145234 übergeben.
 === Ende Beschreibung === */
int f_099db0(int p1, int p2)
{
  int r;
  if (p2 & 4) {
    f_145234(p1, (int)&d_1baf88);
    f_145254();
    return p1;
  }
  *(int *)(p1 + 0x58) = (int)d_1baf9c;
  r = f_0b8520(p1, 1);
  if (p2 & 2) operator delete((void *)r);
  return r;
}

//@ f_099e00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Aktions- oder Ereignisfeld an Offset 0x4e des übergebenen Szenenobjekts p1 auf den
 *   Standardcode 0x81 und gibt den Objektzeiger zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt p1 zurück (int).
 * - Wichtige Variablen: Das 16-Bit-Feld *(short *)(p1 + 0x4e) speichert den zugeordneten Ereigniscode.
 === Ende Beschreibung === */
int f_099e00(int p1)
{
  *(short *)(p1 + 0x4e) = 0x81;
  return p1;
}

//@ f_099e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere virtuelle Platzhalterfunktion ohne Operation.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */
void f_099e10()
{
}

//@ f_099e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Standardereignisse 0x80 und 0x81 eines einfachen Schauplatz-Objekts (p1) und
 *   gibt bei 0x81 abhängig von der Schauplatznummer *p1 einen Beschreibungstext über f_0bf730 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 (unsigned short *) sowie den Ereigniscode p2
 *   (unsigned short) und gibt 1 zurück, wenn das Ereignis behandelt wurde, sonst 0 (int).
 * - Wichtige Variablen: Die ersten zwei Bytes *p1 enthalten die Ortskennung, aus der die Text-ID (0x2201007b für
 *   Kennung 100, sonst *p1 + 0x22010013) abgeleitet wird.
 === Ende Beschreibung === */
int f_099e20(unsigned short *p1, unsigned short p2) {
    unsigned t100_16;
 short r = 0;
 switch(p2) {
 case 0x81: if ((t100_16 = *p1) == 100) f_0bf730((int)&d_1c2c64, 0x2201007b); else f_0bf730((int)&d_1c2c64, *p1 + 0x22010013);
 case 0x80: r = 1; break;
 }
 return r;
}

//@ f_099e70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das globale Bildschirm-Clipping-Rechteck (d_1bdbd4 bis d_1bdbda) auf die volle
 *   VGA-Auflösung von (0, 0) bis (319, 199) zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die vier 16-Bit-Variablen d_1bdbd4 (x1), d_1bdbd6 (y1), d_1bdbd8 (x2 = 319) und d_1bdbda
 *   (y2 = 199) bilden das globale Clipping-Rechteck.
 === Ende Beschreibung === */
void f_099e70()
{
  d_1bdbd4 = 0;
  d_1bdbd6 = 0;
  d_1bdbd8 = 0x13f;
  d_1bdbda = 199;
}

//@ f_099ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wartet über die VGA-Statusregisterabfrage VSYNC() auf den Beginn des nächsten vertikalen
 *   Bildrücklaufs (Vertical Retrace).
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Synchronisation erfolgt direkt über den VGA-Hardwareport 0x3da.
 === Ende Beschreibung === */
void f_099ea0()
{
  VSYNC();
}

//@ f_099ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wartet auf den vertikalen Bildrücklauf der VGA-Karte (Port 0x3da, Bit 3) und überträgt
 *   anschließend n RGB-Farbtripel aus dem Puffer p ab dem Startindex a in die VGA-DAC-Register (0x3c8 / 0x3c9).
 * - Eingaben und Rückgabe: Die Funktion erhält den Palettenpuffer p (unsigned char *), den ersten Farbindex a
 *   (char) sowie die Anzahl der zu setzenden Farben n (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über die CRTC-Ports 0x3d4/0x3d5 (Register 0x11) und die DAC-Ports 0x3c8/0x3c9 wird die
 *   Hardwarepalette flackerfrei aktualisiert.
 === Ende Beschreibung === */
void __cdecl f_099ef0(unsigned char *p, char a, int n)
{
  short count=(short)*(volatile int *)&n; // haelt das Lesen des Stapelparameters n wie im Original
  unsigned char *buffer;
  int i;
  outp(0x3d4,0x11);
  unsigned control=inp(0x3d5)&~0x20;
  outp(0x3d4,0x11);
  buffer=p;
  outp(0x3d5,control);
  while((inp(0x3da)&8)==0) ;
  while((inp(0x3da)&8)!=0) ;
  if(count>0) {
    outp(0x3c8,a);
    for(i=0;i<count*3;++i) { outp(0x3c9,*buffer); ++buffer; }
  }
}

//@ f_099f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das globale Clipping-Rechteck auf die übergebenen Koordinaten (p1, p2) bis (p3, p4) und
 *   reicht diese Werte zugleich an die Low-Level-Zeichenroutine f_15689d weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält die vier Randkoordinaten p1, p2, p3 und p4 (short) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die globalen Variablen d_1bdbd4, d_1bdbd6, d_1bdbd8 und d_1bdbda speichern das aktive
 *   Clipping-Rechteck.
 === Ende Beschreibung === */
void f_099f70(short p1, short p2, short p3, short p4)
{
  d_1bdbd4 = p1;
  d_1bdbd6 = p2;
  d_1bdbd8 = p3;
  d_1bdbda = p4;
  f_15689d(p1, p2, p3, p4);
}

//@ f_099fa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übernimmt die vier Koordinaten eines Rechtecks aus dem Array p1[0..3] in das globale
 *   Clipping-Rechteck und aktualisiert die Low-Level-Clipping-Grenzen über f_15689d.
 * - Eingaben und Rückgabe: Die Funktion erhält einen Zeiger p1 (short *) auf vier 16-Bit-Koordinaten und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die vier Werte p1[0..3] werden nach d_1bdbd4..d_1bdbda kopiert.
 === Ende Beschreibung === */
void f_099fa0(short *p1)
{
  short a = p1[0], b = p1[1], c = p1[2], d = p1[3];
  d_1bdbd4 = a;
  d_1bdbd6 = b;
  d_1bdbd8 = c;
  d_1bdbda = d;
  f_15689d((short)(a & 0xffff), (int)(short)(b & 0xffff), (short)(c & 0xffff), d); // haelt die 16-Bit-Erweiterungen der Argumente wie im Original
}

//@ f_099ff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das aktuell gesetzte globale Clipping-Rechteck (d_1bdbd4..d_1bdbda) aus und schreibt die
 *   vier Koordinaten in das übergebene Array p1[0..3].
 * - Eingaben und Rückgabe: Die Funktion erhält einen Zeiger p1 (short *) auf ein 4-Elemente-Array und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die globalen Variablen d_1bdbd4 bis d_1bdbda liefern die aktuellen Clipping-Grenzen.
 === Ende Beschreibung === */
void f_099ff0(short *p1)
{
  p1[0] = d_1bdbd4;
  p1[1] = d_1bdbd6;
  p1[2] = d_1bdbd8;
  p1[3] = d_1bdbda;
}

//@ f_09a020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuell eingestellten globalen Zeichenmodus bzw. die transparente Farbkennung
 *   d_1bdbdc zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt den Wert von d_1bdbdc zurück (short).
 * - Wichtige Variablen: Die Variable d_1bdbdc hält den aktuellen Low-Level-Zeichenparameter.
 === Ende Beschreibung === */
short f_09a020()
{
  return d_1bdbdc;
}

//@ f_09a030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den globalen Zeichenparameter d_1bdbdc auf den Wert p1 und gibt ihn an die
 *   Low-Level-Grafikroutine f_1568b9 weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält den neuen Wert p1 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bdbdc speichert den gesetzten Wert für spätere Abfragen über
 *   f_09a020.
 === Ende Beschreibung === */
void f_09a030(short p1)
{
  d_1bdbdc = p1;
  f_1568b9((signed char)p1);
}

//@ f_09a040
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt einen internen Farb- oder Textsteuerwert (0xfd, 0xf9, 0xfc, 0xe7, 0xff) in den
 *   zugehörigen Paletten-Basisindex (0xf0 bis 0xf4).
 * - Eingaben und Rückgabe: Die Funktion erhält den Farbcode c (unsigned char) und gibt den zugeordneten
 *   Palettenindex zurück (unsigned char).
 * - Wichtige Variablen: Falls c keinen der fünf erwarteten Fälle trifft, bleibt der Rückgabewert d
 *   uninitialisiert.
 === Ende Beschreibung === */
unsigned char f_09a040(unsigned char c)
{
  unsigned char d;
  switch (c) {
  case 0xfd: d = 0xf1; break;
  case 0xf9: d = 0xf2; break;
  case 0xfc: d = 0xf3; break;
  case 0xe7: d = 0xf4; break;
  case 0xff: d = 0xf0; break;
  }
  return d;
}

//@ f_09a080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt einen der fünf internen Farbcodes (0xfd, 0xf9, 0xfc, 0xe7, 0xff) in die zugehörige
 *   Text-ID (0x20000185 bis 0x20000189).
 * - Eingaben und Rückgabe: Die Funktion erhält den Farbcode c (unsigned char) und gibt die zugehörige Text-ID
 *   zurück (int).
 * - Wichtige Variablen: Wie in f_09a040 fehlt ein default-Zweig, sodass d bei anderen Eingabewerten
 *   uninitialisiert bleibt.
 === Ende Beschreibung === */
int f_09a080(unsigned char c)
{
  int d;
  switch (c) {
  case 0xfd: d = 0x20000186; break;
  case 0xf9: d = 0x20000187; break;
  case 0xfc: d = 0x20000188; break;
  case 0xe7: d = 0x20000189; break;
  case 0xff: d = 0x20000185; break;
  }
  return d;
}

//@ f_09a0d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht einen 320x200-Bildschirmpuffer (64.000 Bytes) unter aktivem Mausschutz (MG) vollständig
 *   auf die Farbe 0 (Schwarz).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (void *) auf den 64.000-Byte-Bildpuffer und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Hilfsobjekt mg blendet den Mauszeiger während des memset-Aufrufs (f_145300) aus.
 === Ende Beschreibung === */
void f_09a0d0(void *p1)
{
  MG mg;
  f_145300(p1, 0, 64000);
}

//@ f_09a120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet die gesamte 256-Farben-Palette in p2 Schritten von Schwarz (d_1bdbe8) auf die
 *   Zielpalette p1 auf (Fade-In).
 * - Eingaben und Rückgabe: Die Funktion erhält die Adresse der Zielpalette p1 sowie die Schrittanzahl p2 (short)
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der globale Puffer d_1bdbe8 enthält eine komplett schwarze 256-Farben-Referenzpalette.
 === Ende Beschreibung === */
void f_09a120(int p1, short p2)
{
  f_09a180(d_1bdbe8, p1, p2, 0x100, 1);
}

//@ f_09a140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet die gesamte 256-Farben-Palette in p2 Schritten von der Palette p1 (oder der aktuell in
 *   der VGA-Karte aktiven Palette, falls p1 == 0) nach Schwarz (d_1bdbe8) ab (Fade-Out).
 * - Eingaben und Rückgabe: Die Funktion erhält die Ausgangspalette p1 (oder 0) sowie die Schrittanzahl p2
 *   (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei p1 == 0 wird die aktuelle Hardwarepalette zunächst über f_149eb4 in den globalen
 *   Puffer d_1bdbe4 ausgelesen.
 === Ende Beschreibung === */
void f_09a140(int p1, short p2)
{
  if (p1 == 0) {
    f_149eb4(d_1bdbe4, 0, 0x100);
    p1 = d_1bdbe4;
  }
  f_09a180(p1, d_1bdbe8, p2, 0x100, 1);
}

//@ f_09a180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine schrittweise Palettenüberblendung von p4 Farben zwischen der Ausgangspalette p1 und
 *   der Zielpalette p2 in p3 Einzelschritten durch, wobei nach jedem Interpolationsschritt (f_09a2d0) auf VSync
 *   gewartet und die Zwischenpalette über f_099ef0 in die VGA-Karte geschrieben wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startpalette p1, die Zielpalette p2, die Schrittanzahl p3
 *   (short), die Farbanzahl p4 (short) sowie ein Flag p5 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das dynamisch reservierte Array buf (p4 * 3 Bytes) nimmt die jeweils interpolierten
 *   RGB-Werte auf.
 === Ende Beschreibung === */
void f_09a180(int p1, int p2, short p3, short p4, int p5)
{
  short i;
  unsigned char *t = (unsigned char *)f_147c84(new (mark(d_1a34c4, 0x14c)) char[p4 * 3], (unsigned)p4, d_1baac0);
  unsigned char *buf = t ? t : 0;
  if (p1 == 0) {
    f_149eb4(d_1bdbe4, 0, 0x100);
    p1 = d_1bdbe4;
  }
  memcpy(buf, (void *)p1, p4 * 3);
  for (i = 0; i <= p3; i++) {
    short prog = (short)((10000 / p3) * i / 100);
    f_09a2d0((unsigned char *)p1, (unsigned char *)p2, buf, prog, p4);
    VSYNC();
    f_099ef0(buf, 0, p4);
    f_149d20();
  }
  delete buf;
}


//@ f_09a2d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für p5 Farben die lineare RGB-Interpolation zwischen der Ausgangspalette p1 und der
 *   Zielpalette p2 zum Prozentsatz p4 (0 bis 100) und schreibt das Ergebnis in den Zielpuffer p3.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startpalette p1, die Zielpalette p2, den Ausgabepuffer p3
 *   (unsigned char *), den Fortschrittswert p4 (short, 0..100) sowie die Farbanzahl p5 (short) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Jeder Farbkanal wird nach der Formel (a[k] - b[k]) * p4 / 100 + b[k] berechnet.
 === Ende Beschreibung === */
void f_09a2d0(unsigned char *p1, unsigned char *p2, unsigned char *p3, short p4, short p5)
{
  short i;
  int o = 0;
  unsigned char *a = p2, *b = p1;
  if (p4 <= 0) {
    memcpy(p3, p1, 3 * p5);
  } else {
    if (p4 >= 100) {
      memcpy(p3, p2, 3 * p5);
      return;
    }
    i = 0;
    if (i < p5) {
      do {
        o = i * 3;
        a = p2 + o;
        b = p1 + o;
        p3[o] = (unsigned char)((a[0] - b[0]) * p4 / 100 + b[0]);
        p3[o + 1] = (unsigned char)((a[1] - b[1]) * p4 / 100 + b[1]);
        p3[o + 2] = (unsigned char)((a[2] - b[2]) * p4 / 100 + b[2]);
        i++;
      } while (i < p5);
    }
  }
}

//@ f_09a400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die Standard-256-Farben-Palette (0x300 Bytes am Dateiende -0x300) aus der Archivdatei
 *   0x140001 in den globalen Puffer d_1bdbe4 und aktiviert sie sofort über f_099ef0 in der VGA-Hardware.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der globale Puffer d_1bdbe4 speichert die geladene Standardpalette (768 Bytes).
 === Ende Beschreibung === */
void f_09a400()
{
  f_1448b0(FL, 0x140001, 0x200);
  f_144ab0(FL, 0xfffffd00, 2);
  f_144920(FL, d_1bdbe4, 0x300);
  f_1449a0(FL);
  f_099ef0((unsigned char *)d_1bdbe4, 0, 0x100);
}

//@ f_09a470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die 256-Farben-Standardpalette (0x300 Bytes am Dateiende -0x300) aus der Archivdatei
 *   0x140001 in den übergebenen Zielpuffer p1, ohne die VGA-Hardwarepalette zu verändern.
 * - Eingaben und Rückgabe: Die Funktion erhält die Zielpufferadresse p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Dateizugriff erfolgt über das globale Archiv-Objekt FL.
 === Ende Beschreibung === */
void f_09a470(int p1)
{
  f_1448b0(FL, 0x140001, 0x200);
  f_144ab0(FL, 0xfffffd00, 2);
  f_144920(FL, p1, 0x300);
  f_1449a0(FL);
}

//@ f_09a4c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert ein 320x200-Vollbild (64.000 Pixel) aus dem Quellpuffer p1 mit einer pseudozufälligen
 *   Pixel-Auflöseblende (next = a * 0x11 + 0x57) in den Bildschirmpuffer d_1a34e0, wobei alle 100 Pixel eine
 *   kurze Pause (f_149cf0) eingelegt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Quellbildzeiger p1 (unsigned char *) sowie die
 *   Verzögerungsdauer p2 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der lineare Kongruenzgenerator a = a * 17 + 87 durchläuft alle 16-Bit-Indizes und
 *   übernimmt Werte < 64000 genau einmal in den Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void f_09a4c0(unsigned char *p1, int p2)
{
  short a;
  unsigned short b, index;
  f_068f40();
  a = 0;
  for (b = 0; b < 64000U; b++) {
    do {
      short next = a * 0x11 + 0x57;
      index = (unsigned short)next;
      a = next;
    } while (index >= 64000U);
    d_1a34e0[index] = p1[index];
    union { int full; short low; } test;
    test.full = p2;
    if (test.low > 0 && b % 100 == 0) f_149cf0((short)p2);
  }
}

//@ f_09a540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet ein Bild der Größe p4 x p5 aus dem Puffer p2 über einen achtstufigen horizontalen
 *   Jalousie-Wischeffekt gegen den Hintergrundpuffer p3 zentriert in den Bildschirmpuffer d_1a34e0 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Status-Array p1 (short *), den neuen Bildpuffer p2, den alten
 *   Bildpuffer p3 (unsigned char *), die Breite p4 (short) sowie die Höhe p5 (short) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Felder p1[0..5] steuern die Phasenverschiebung der geraden und ungeraden Bildzeilen
 *   beim Aufruf der Zeilenmischfunktion f_09a720.
 === Ende Beschreibung === */
void f_09a540(short *p1, unsigned char *p2, unsigned char *p3, short p4, short p5)
{
  short y, x, u;
  int o;
  unsigned char *q1, *q2, *s30;
  SO so(p4, p5, p2);
  x = (short)((0x140 - p4) >> 1);
  y = (short)((200 - p5) >> 1);
  MG mg;
  p1[5] = 0;
  p1[3] = 0;
  p1[4] = 8;
  p1[1] = 0;
  p1[2] = 7;
  o = y * 0x140 + x;
  for (p1[0] = 0; p1[0] < 8; p1[1]++, p1[2]--, p1[0]++) {
    p1[1] = p1[1] & 7;
    if (p1[2] < 0) p1[2] = 7;
    p1[5] = p1[5] + 1;
    if (p1[5] == 1) {
      p1[5] = 0;
      p1[3] = p1[3] + 1;
      if (p1[3] > 8) p1[3] = 8;
      p1[4] = p1[4] - 1;
      if (p1[4] < 0) p1[4] = 0;
    }
    s30 = d_1a34e0 + o;
    q2 = p2;
    q1 = p3;
    for (u = 0; u < p5 - 1; u++) {
      q2 = q2 + p4;
      q1 = q1 + ((p4 + 8) & ~7);
      s30 = s30 + 0x140;
      f_09a720(p1, s30, q2, q1, (u & 1) == 0 ? p1[1] : p1[2], p4);
    }
  }
  f_0fade0(&so, d_1a34e0, x, y);
}

//@ f_09a720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Mischt für den Jalousie-Bildübergang aus f_09a540 eine einzelne Bildzeile der Breite p6 in
 *   8-Pixel-Segmenten aus dem neuen Bild p3 und dem alten Bild p4 in den Zielpuffer p2.
 * - Eingaben und Rückgabe: Die Funktion erhält das Parameterarray p1 (short *), den Zielzeilenzeiger p2, die
 *   beiden Quellzeilenzeiger p3 und p4 (unsigned char *), den Startversatz p5 sowie die Zeilenbreite p6 und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die Werte p1[3] und p1[4] geben an, wie viele Pixel pro 8er-Block bereits aus dem neuen
 *   Bild p3 bzw. noch aus dem alten Bild p4 kopiert werden.
 === Ende Beschreibung === */
void f_09a720(short *p1, unsigned char *p2, unsigned char *p3, unsigned char *p4, int p5, int p6)
{
  short i, j;
  i = 0;
  if ((short)p5 > (short)0) {
    do {
      *p2++ = *p3++;
      i++;
      p4++;
    } while (i < (short)p5);
  }
  i = 0;
  if (p1[4] > (short)0) {
    do {
      *p2++ = *p4++;
      i++;
      p3++;
    } while (i < p1[4]);
  }
  for (j = (short)p5 + 1; j < (short)p6 - 7; j += 8) {
    i = 0;
    if (p1[3] > (short)0) {
      do {
        *p2++ = *p3++;
        i++;
        p4++;
      } while (i < p1[3]);
    }
    i = 0;
    if (p1[4] > (short)0) {
      do {
        *p2++ = *p4++;
        i++;
        p3++;
      } while (i < p1[4]);
    }
  }
}

void f_09a850(unsigned char *, unsigned char *, int);

//@ f_09a7d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hellt einen rechteckigen Bildausschnitt der Größe width x height an Position (x, y) im
 *   Bildpuffer buffer um den Korrekturwert correction auf oder dunkelt ihn ab, indem über f_09a850 eine
 *   256-Byte-Farbübersetzungstabelle (d_1bdbec) berechnet und auf alle Pixel des Rechtecks angewandt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Bildpuffer buffer (unsigned char *), die Koordinaten x und y
 *   (short), die Abmessungen width und height, die Zeilenbreite stride sowie den Helligkeitsversatz correction
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Array d_1bdbec (256 Bytes) dient als Nachschlagetabelle für die
 *   Assembler-Schleife remap983.
 === Ende Beschreibung === */
extern void remap983(unsigned char *buf, int width, int height, int skip, unsigned char *table);
#pragma aux remap983 = "bswap edx" "mov dx,ax" "bswap edx" "xor eax,eax" "z: bswap edx" "mov bx,dx" "bswap edx" "p: mov al,[esi]" "mov al,[edi+eax]" "mov [esi],al" "inc esi" "dec bx" "jne p" "lea esi,[esi+ecx]" "dec dx" "jne z" parm [esi] [eax] [edx] [ecx] [edi] modify [eax ebx ecx edx esi edi];
void f_09a7d0(unsigned char *buffer, short x, short y, int width, int height, int stride, int correction)
{
    int pick_edx(int v);
#pragma aux pick_edx = "" parm [edx] value [edx] modify exact [];
    f_09a850((unsigned char *)d_1bdbe4, d_1bdbec, (short)correction);
    short difference = (short)(stride - width);
    int offset = (short)y;
    int factor = pick_edx((short)stride);
    offset *= factor;
    int skip = difference;
    skip = (skip & 0) ? 0 : skip; // haelt die Registerzuteilung fuer skip wie im Original
    buffer += (short)x;
    buffer += offset;
    width = (width & 0) ? 0 : width; // haelt die Registerzuteilung fuer width wie im Original
    remap983(buffer, width, height, skip, d_1bdbec);
}
//@ f_09a850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt für alle 256 Einträge der Palette palette eine Farbübersetzungstabelle output, indem
 *   zu jedem RGB-Tripel der Helligkeitswert correction addiert (auf 0..63 begrenzt) und der ähnlichste Farbindex
 *   in der Palette gesucht wird.
 * - Eingaben und Rückgabe: Die Funktion erhält die Quellpalette palette (unsigned char *), das
 *   256-Byte-Ausgabearray output (unsigned char *) sowie den Helligkeitsversatz correction (int) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die eingebettete Nachbarschaftssuche prüft für alle 256 Palettenfarben den
 *   Manhattan-Abstand (|dr| + |dg| + |db|) und bricht bei Abstand 0 vorzeitig ab.
 === Ende Beschreibung === */
static inline unsigned int nearest782(signed char red, unsigned char green, unsigned char blue, const unsigned char *palette)
{
    unsigned result=255;
    signed char index=0;
    do {
        unsigned char best=255;
        signed char dr=(signed char)(palette[0]-red);
        if (dr<(signed char)0) dr=-dr;
        signed char dg=(signed char)(palette[1]-green);
        if (dg<(signed char)0) dg=-dg;
        signed char db=(signed char)(palette[2]-blue);
        if (db<(signed char)0) db=-db;
        unsigned char distance=(unsigned char)(dr+dg+db);
        if (distance<best) {
            best=distance; result=index;
            if (distance==(unsigned char)0) break;
        }
        ++index; palette+=3;
    } while ((unsigned short)index<(unsigned short)256);
    return result;
}



void f_09a850(unsigned char *palette, unsigned char *output, int correction)
{
    struct Frame { unsigned char *out; RGB rgb; char pad; int amount, index; } state;
    state.out=output; state.amount=correction;
    RGB &color=state.rgb;
    state.index=0;
    int red,green,blue;
    color.r=0; color.g=0; color.b=0;
    goto load_color;
map_color:
    color.r=(unsigned char)red;
    color.g=(unsigned char)green;
    color.b=(unsigned char)blue;
    state.out[(short)state.index]=(unsigned char)nearest782(color.r,color.g,color.b,palette);
    ++state.index;
load_color:
    if ((short)state.index>=256) return;
    color=((RGB *)palette)[(short)state.index];
    red=color.r+state.amount;
    if (red<0) red=0;
    if (red>63) red=63;
    green=color.g+state.amount;
    if (green<0) green=0;
    if (green > 63) green = 63;
    blue=(unsigned char)state.rgb.b+state.amount;
    if ((short)blue<0) blue=0;
    if ((short)blue>63) blue=63;
    goto map_color;
}





//@ f_09a990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht zu einem gegebenen RGB-Farbtripel color in der 256-Farben-Palette palette den Eintrag
 *   mit dem kleinsten Manhattan-Abstand (|dr| + |dg| + |db|) und gibt dessen Palettenindex zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das gesuchte RGB-Tripel color (const unsigned char
 *   *) sowie die 768-Byte-Palette palette (const unsigned char *) und gibt den gefundenen Farbindex (0..255)
 *   zurück (unsigned int).
 * - Wichtige Variablen: Im Original-Assembler hält DH das bisherige Abstandsminimum (Startwert 0xff) und das
 *   obere Wort von EAX (per bswap) den besten gefundenen Palettenindex.
 === Ende Beschreibung === */
unsigned int f_09a990(const unsigned char *color, const unsigned char *palette)
{
    signed char red=color[0], green=color[1];
    unsigned result=255;
    short index=0;
    do {
        unsigned char dr=(signed char)(palette[0]-red);
        if (dr<(unsigned char)0) dr=-dr;
        signed char dg=(signed char)(palette[1]-green);
        if (dg<(signed char)0) dg=-dg;
        red = color[2];
        signed char db=(signed char)(palette[2]-red);
        if (db<(signed char)0) db=-db;
        unsigned char distance=(unsigned char)(dr+dg+db);
        red = 255;
        if (distance<red) {
            red=distance; result=index;
            if (distance==(unsigned char)0) break;
        }
        ++index; palette+=3;
    } while ((unsigned short)index<(unsigned short)256);
    return result;
}

//@ f_09aa00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wandelt einen rechteckigen Bildausschnitt (w x h ab p3, p4) aus dem Quellpuffer p1 anhand des
 *   Durchschnitts der aktuellen RGB-Werte ((r + g + b) / 3 + add) in Graustufen bzw. einen einfarbigen
 *   Farbverlauf um und schreibt das Ergebnis nach p2 (oder direkt zurück nach p1, falls p2 == 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Quellpuffer p1, den optionalen Zielpuffer p2 (unsigned char
 *   *), die Startkoordinaten p3 und p4, die Breite w, die Höhe h, die Zeilenbreite stride (short) sowie den
 *   Basis-Farbindex add (char) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die aktuelle Hardwarepalette wird über f_149eb4 ausgelesen, um für jeden der 256
 *   Farbindizes den Helligkeitsmittelwert in d_1bdbec zu berechnen.
 === Ende Beschreibung === */
void f_09aa00(unsigned char *p1, unsigned char *p2, short p3, short p4, short w, short h, short stride, char add)
{
  struct GrayPipeline1140 {
    static char shade(unsigned char red, unsigned char green, unsigned char blue, char &add) {
      union Accumulator1140 { unsigned full; unsigned char byte; } accumulator;
      accumulator.full = blue;
      accumulator.byte += (unsigned char)(red + green);
      int quotient = accumulator.byte / 3;
      char adjustment = add;
      add = adjustment; // haelt den Parameterzugriff auf add wie im Original
      adjustment += quotient;
      return adjustment;
    }
  };
  RGB color;
  int separate;
  int remembered_flags;
  unsigned char remembered_zero, remembered_one;
  char *palette;
  short i, row, col;
  unsigned char *src, *dst;
  { RGB *c = &color; c->b = c->g = c->r = 0; } // haelt die im Original vorhandenen Null-Stores auf color
  palette = (char *)f_014540(0x300, (int)d_1a34c4, 0x348);

  f_149eb4((int)palette, 0, 0x100);
  for (i = 0; i < 256; i++) {
    color = ((RGB *)palette)[i];
    d_1bdbec[i] = GrayPipeline1140::shade(color.r, color.g, color.b, add);
  }
  // haelt die im Original vorhandenen Lese-/Schreibzugriffe auf d_1baf9c und d_1bdbec
  remembered_flags = d_1baf9c[0];
  remembered_zero = d_1bdbec[0];
  remembered_one = d_1bdbec[1];
  d_1baf9c[0] = remembered_flags;
  d_1bdbec[0] = remembered_zero;
  d_1bdbec[1] = remembered_one;
  src = p3 + (p1 + p4 * stride);
  if (p2 == 0) {
    dst = src;
    separate = 0;
  } else {
    dst = p2;
    separate = 1;
  }
  for (row = 0; row < h; row++) {
    for (col = 0; col < w; col++)
      { unsigned char index = *(unsigned char *)src; ++src; *dst++ = d_1bdbec[index]; }
    src += stride - w;
    if (separate == 0) dst += stride - w;
  }
  delete palette;
}

//@ f_09ab40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus der aktuell im Dateimanager FL geöffneten Datei optional eine 768-Byte-Palette nach
 *   p2 und anschließend in acht Blöcken zu je 8.000 Bytes ein vollständiges 64.000-Byte-Vollbild in den Puffer
 *   p1 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielbildpuffer p1 (char *) sowie die optionale
 *   Palettenadresse p2 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ein temporärer 8.000-Byte-Puffer buf dient als Zwischenspeicher beim blockweisen Lesen
 *   über f_144920.
 === Ende Beschreibung === */
void f_09ab40(char *p1, int p2)
{
  short i;
  char *buf = new (mark(d_1a34c4, 0x38f)) char[8000];
  if (p2) f_144920(FL, p2, 0x300);
  i = 0;
  do {
    f_144920(FL, (int)buf, 8000);
    memcpy(p1, buf, 8000);
    p1 += 8000;
    i++;
  } while (i < (short)8);
  delete buf;
}

//@ f_09abe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt optional eine 768-Byte-Palette aus p2 und anschließend ein 64.000-Byte-Vollbild aus
 *   p1 in acht Blöcken zu je 8.000 Bytes in die aktuell im Dateimanager FL geöffnete Ausgabedatei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Quellbildpuffer p1 (char *) sowie die optionale
 *   Palettenadresse p2 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Schreiben erfolgt blockweise über f_144960 mit einem temporären 8.000-Byte-Puffer
 *   buf.
 === Ende Beschreibung === */
void f_09abe0(char *p1, int p2)
{
  short i;
  char *buf = new (mark(d_1a34c4, 0x3b6)) char[8000];
  if (p2) f_144960(FL, p2, 0x300);
  i = 0;
  do {
    memcpy(buf, p1, 8000);
    f_144960(FL, (int)buf, 8000);
    p1 += 8000;
    i++;
  } while (i < (short)8);
  delete buf;
}

//@ f_09ac80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sichert einen 64.000-Byte-Bildschirmpuffer p1 entweder in eine benannte Auslagerungsdatei (p2
 *   != 0), bei knappem Arbeitsspeicher in die Standard-Auslagerungsdatei d_1a34e8 oder direkt in den
 *   64.000-Byte-RAM-Sicherungspuffer d_1bdcec.
 * - Eingaben und Rückgabe: Die Funktion erhält den Quellbildpuffer p1 (char *), einen optionalen Dateinamen p2
 *   (int) sowie eine optionale Palettenadresse p3 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1a34e4 merkt sich, ob die Standardsicherung auf Festplatte (1) oder im
 *   RAM-Puffer d_1bdcec (0) abgelegt wurde.
 === Ende Beschreibung === */
void f_09ac80(char *p1, int p2, int p3)
{
  short i;
  if (p2 != 0 || (d_1bdcec == 0 && f_014a60() < 64000)) {
    if (p2 != 0) {
      d_1a965c = p2;
    } else {
      d_1a965c = d_1a34e8;
      d_1a34e4 = 1;
      d_1bdcf0 = 1;
    }
    f_144af0(FL, 0);
    f_1448b0(FL, 0, 0x221);
    char *src = p1;
    char *buf = new (mark(d_1a34c4, 0x3b6)) char[8000];
    if (p3) f_144960(FL, p3, 0x300);
    i = 0;
    do {
      memcpy(buf, src, 8000);
      f_144960(FL, (int)buf, 8000);
      src += 8000;
      i++;
    } while (i < (short)8);
    delete buf;
    f_1449a0(FL);
    return;
  }
  if (d_1bdcec == 0) d_1bdcec = f_014540(64000, (int)d_1a34c4, 0x408);
  f_14d075(d_1bdcec, (int)p1, 64000);
  d_1bdcf0 = 1;
  d_1a34e4 = 0;
}

//@ f_09ade0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt einen zuvor mit f_09ac80 gesicherten 64.000-Byte-Bildschirmpuffer entweder aus dem
 *   RAM-Puffer d_1bdcec (d_1a34e4 == 0 && p2 == 0) oder aus der jeweiligen Auslagerungsdatei (p2 bzw. d_1a34e8)
 *   wieder im Zielpuffer p1 (und optional der Palette p3) her.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielbildpuffer p1 (char *), den optionalen Dateinamen p2
 *   (int) sowie die optionale Palettenadresse p3 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei RAM-Sicherung kopiert f_14d075 die 64.000 Bytes direkt aus d_1bdcec nach p1.
 === Ende Beschreibung === */
void f_09ade0(char *p1, int p2, int p3)
{
  short i;
  if (d_1a34e4 == 0 && p2 == 0) {
    f_14d075((int)p1, d_1bdcec, 64000);
    return;
  }
  if (p2 == 0) p2 = d_1a34e8;
  *(volatile int *)&d_1a965c = p2; // haelt das Schreiben nach d_1a965c vor dem Funktionsaufruf wie im Original
  f_1448b0(FL, 0, 0x200);
  char *dst = p1;
  char *buf = new (mark(d_1a34c4, 0x38f)) char[8000];
  if (p3) f_144920(FL, p3, 0x300);
  i = 0;
  do {
    f_144920(FL, (int)buf, 8000);
    memcpy(dst, buf, 8000);
    dst += 8000;
    i++;
  } while (i < (short)8);
  delete buf;
  f_1449a0(FL);
}

//@ f_09aed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht eine auf Festplatte angelegte Bildschirm-Auslagerungsdatei (p1 bzw. die Standarddatei
 *   d_1a34e8) über f_144af0 und gibt bei p1 == 0 zusätzlich den 64.000-Byte-RAM-Sicherungspuffer d_1bdcec frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den optionalen Dateinamen p1 (int, 0 für die Standardsicherung)
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nach dem Aufräumen der Standardsicherung wird d_1a34e4 auf -1 und d_1bdcf0 auf 0
 *   zurückgesetzt.
 === Ende Beschreibung === */
void f_09aed0(int p1)
{
  if (p1 != 0) {
    d_1a965c = p1;
    f_144af0(FL, 0);
  } else {
    d_1bdcf0 = 0;
    if (d_1bdcec != 0) {
      delete (char *)d_1bdcec;
      d_1bdcec = 0;
    }
    d_1a965c = d_1a34e8;
    f_144af0(FL, 0);
    d_1a34e4 = -1;
  }
}
