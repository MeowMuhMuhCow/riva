/* === Beschreibung (Katalog) ===
 * Einheit use3 (0x13B180 - 0x13BB70)
 *
 * Überblick
 *
 * Die Einheit use3 bildet den siebten Abschnitt des Objektbenutzungssystems (use.cpp) und enthält die
 * Aktionshandler 25 bis 39 der Sprungtabelle aus use_t1. Sie umfasst die interaktive 15-seitige Buch- und
 * Kompendiumsansicht einschließlich einer Druckfunktion über die Druckerschnittstelle, das Schnitzen einer
 * *Blumenflöte* aus einem *Blasrohr*, das Basteln einer *Schleuder* aus *Y-Ast* und *Spinnenseil*, einen
 * speziellen Dungeon-Ereignisschalter (f_13b8f0), das direkte Übertragen einzelner Rezepte oder Schriftstücke in
 * ein Buch sowie neun Platzhalter-Handler (31 bis 39), die lediglich eine Debug-Meldung ausgeben.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
// P3 14/15 gleich (suche.py 26.10.2026, Basis use3_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 13 gleich (vorher 13), Rest 165 (vorher 168)
// use3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13B180-0x13BB70
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
#define EQI(x,v) (((x)==(v))?1:0)
struct SO { int a; int *p; char c[52]; };
struct SO2 { int a; short *p; char c[52]; };
struct IT { char a[16]; int o; char b[4]; short s18; short s1a; short s1c; short s1e; };
int f_036300(int p1, int p2, int p3);
int f_036a10(int p1, int p2, int p3, int p4, int p5);
int f_05dec0(void *p1);
int f_05ded0(void *p1, int p2);
int f_05e1d0(void *p1, int p2, int p3);
short f_05e1f0(void *p1);
int f_05e2d0(void *p1, int p2, int p3, int p4, int p5);
int f_05e320(void *p1, int p2, int p3);
int f_068f40();
int f_09a120(int p1, int p2);
int f_09a140(int p1, int p2);
int f_0bf730(const char *p1, int p2);
int f_0d26e0();
int f_0d2710();
int f_0d2e70();
int f_0d2f90(int p1, int p2);
int f_0d37e0();
int f_0d3860();
int f_0da910(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
void *f_0da990(int p1, int);
int f_0daba0(int p1, int p2);
short f_0dacc0(int p1);
short f_0de820(int p1);
int f_0e8c20(const char *p1);
int f_0e8cd0();
int f_0e8eb0(void *p1, int p2);
int f_0e9240(int p1);
int f_0e93f0(void *p1, void *p2, int p3);
int f_0e9550(void *p1, int p2);
short f_0e9590(void *p1, int p2);




int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(void *p1, const char *p2);
int f_135d40(IT *p1);
int f_135dc0(IT *p1, int p2, int p3, int p4);
int f_135ef0(IT *p1, int p2, int p3, int p4);
short f_1364f0(IT *p1, int p2);
int f_136ea0(IT *p1, int p2);
int f_136ed0(IT *p1, int p2);
int f_1459b0(void *p1);
int f_1459d0(void *p1, int);
int f_145a10(void *p1, int p2, int p3);
int f_145b40(void *p1);
extern char d_1a16d4[];
extern int d_1a34e0;
extern int d_1a965c;
extern int d_1bc940;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern void *d_1bf514;
extern signed char d_1bfaf8;
extern int d_1bfdb8;
extern int d_1c0004;
extern short d_1c0090;
extern signed char d_1c1070;
extern signed char d_1c1074;
extern unsigned short d_1c2100;
extern volatile short d_1c2198; // volatile verhindert Schleifen-CSE auf dem Redraw-Flag d_1c2198 in f_13b180
extern char d_1c21b4[];
extern int d_1c2a80;
extern char d_1c2c64[];
extern char d_1c3068[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
extern const char d_1a93a8[];
extern const char d_1a93c4[];
extern const char d_1b8528[];

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_13b180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 25 der Objektbenutzungstabelle: Öffnet ein mehrseitiges Nachschlagewerk (das
 *   15-seitige alchemistische bzw. kundliche Buch auf dem Buchhintergrund 0x80000), in dem der Spieler
 *   seitenweise vor- und zurückblättern, über ein Inhaltsverzeichnis (page == 0) direkt zu einem der 14 Kapitel
 *   springen oder das gesamte Werk über eine Druckerschaltfläche (0x74, mit Bestätigungsdialog 0x1E01003C und
 *   den Statusmeldungen 0x1E01003D / 0x1E01003E) auf einem angeschlossenen Drucker (f_0e8c20, f_0e8eb0,
 *   f_0e8e90) ausgeben kann.
 * - Eingaben: Keine (wird über die Sprungtabelle aufgerufen; nutzt globale Bildschirm- und Textressourcen).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - page: Aktuell aufgeschlagene Buchseite (0 = Inhaltsverzeichnis auf der linken Seite und erstes Kapitel
 *     rechts; gerade Zahlen 2 bis 14 = Doppelseiten der Textabschnitte 0x1E01002D + page).
 *   - dirty: Flag (1 oder 0), das anzeigt, ob die Doppelseite nach dem Umblättern neu gezeichnet und ihre
 *     Schaltflächen neu angelegt werden müssen.
 *   - hit: Rückgabewert der GUI-Abfrage (f_0ef5a0), der die angeklickte Schaltfläche (0x62 = Schließen, 0x72 =
 *     Weiterblättern, 0x73 = Zurückblättern, 0x74 = Drucken, 0x75 = Zurück zum Inhaltsverzeichnis, 0x3E8-0x3F5 =
 *     Kapitelwahl im Inhaltsverzeichnis) angibt.
 *   - buf: Dynamisch angelegter Textpuffer (0x1400 Bytes) zum Formatieren der beiden Buchspalten und der
 *     Druckausgabe.
 === Ende Beschreibung === */
void f_13b180(void)
{
  struct Image { char head[20]; short *p; char tail[36]; };
  char canvas[0xa4];
  Image image;
  char palette[60];
  signed char item;
  struct Loc { int finished; int music; int saved; int oldColor; int first; } L;
  L.saved = d_1bfdb8;
  int control;
  int surface;
  unsigned short scan;
  short selected = 0;

  L.finished = 0;
  L.first = 0;
  L.oldColor = f_05dec0(d_1c3068);
  f_125400(&image, d_1c349c, d_1c3870, d_1c3498);
  f_1459b0(canvas);
  int window = (int)operator new(0x42, mark(d_1a93a8, 0x2b8));
  d_1bfdb8 = window ? f_0da910(window, 0x80006, 0x280005, 0x280002, 0x280004, 7, 0x18) : 0;
  d_1c2198 = 1;

  while (!L.finished) {
    if (d_1c2198 == 1) {
      d_1c2198 = 0;
      if (!L.first) f_09a140(L.first, 0x19);
      if (f_0d3860() == 1) {
        f_0d2710();
        L.music = 1;
      } else L.music = 0;

      int rawPopup = (int)operator new(9, mark(d_1a93a8, 0x2d4));
      int popup;
      if (rawPopup) popup = ((int)(((RivaRasterImage*)(rawPopup))->f_0fac80( 0x140, 200)));
      else popup = rawPopup;
      control = popup;
      surface = ((int)(((RivaRasterImage*)(popup))->f_0fb0b0()));
      d_1c2a80 = 0x80000;
      f_145a10(canvas, 0x80000, surface);
      int panelSurface = ((int)(((RivaRasterImage*)(popup))->f_0fb0b0()));
      f_0daba0(d_1bfdb8, panelSurface);
      f_05ded0(d_1c3068, ((int)(((RivaRasterImage*)(popup))->f_0fb0b0())));

      f_05e2d0(d_1c38b0, 0x19, 0xce, 0x1e, -1);
      f_05e320(d_1c38b0, 0xbb, -1);
      short highlight = selected ? 0x24 : 0x2c;
      f_05e1d0(d_1c38b0, f_05e1f0(d_1c38b0), highlight);
      f_0e9550(d_1c38b0, 0x8030056);
      f_05e320(d_1c38b0, 0xfe, -1);
      image.p[1] = selected + 1;
      image.p[2] = 15;
      short width = f_0e9590(d_1c38b0, 0x8030060);
      f_05e2d0(d_1c38b0, (short)(0x82 - width / 2), (short)(width + 1), 0x10, -1);
      f_0e9550(d_1c38b0, 0x8030060);
      f_05e2d0(d_1c38b0, 0x19, 0xce, 0x1e, -1);
      f_05e1d0(d_1c38b0, 0x19, 0x1e);
      f_0e9550(d_1c38b0, selected + 0x1e01002d);
      f_05ded0(d_1c3068, L.oldColor);
      ((RivaRasterImage*)(control))->f_0fade0((void *)( d_1a34e0), 0, 0);
      if (control) operator delete(((void *)(((RivaRasterImage*)(control))->f_0fad20( 0))));
      if (L.music == 1) f_0d26e0();
      if (!L.first) {
        f_09a120(f_145b40(canvas), 0x19);
        L.first = 1;
      }
    }

    d_1bf514 = d_1a16d4;
    f_068f40();
    short event = f_0dacc0(d_1bfdb8);
    d_1bd766 = event;
    *(void * volatile *)&d_1bf514 = 0; // volatile verhindert das Zusammenfassen mit der vorangehenden Zuweisung an d_1bf514
    if (event == 0x81 || d_1bd762 == d_1c2100) {
      int result = f_0e8c20(d_1b8528);
      f_125400(palette, d_1c349c, d_1c3870, d_1c3498);
      if (!result) {
        f_0d2f90(5, 1);
        f_0e93f0(d_1c38b0, d_1c21b4, 0x803007e);
        f_0e8eb0(d_1c21b4, 1);
        f_0e93f0(d_1c38b0, d_1c21b4, 0x803006b);
        f_0e8eb0(d_1c21b4, 1);
        f_0e9240(0);
        for (short row = 0; row < 15; ++row) {
          d_1c0090 = 0;
          item = row;
          f_0e93f0(d_1c38b0, d_1c21b4, (short)(row + (item - item)) + 0x1e01002d); // (item - item) erzwingt die 16-Bit-Zwischenerweiterung von row vor der Addition
          f_0e8eb0(d_1c21b4, 0);
          f_0e9240(0);
          short delay = (signed char)(d_1bfaf8 / 5);
          while (d_1c0090 > delay) d_1c0090 -= delay;
          while (d_1c0090 < delay) f_0e9240(0);
        }
        f_0e8cd0();
        f_0d2e70();
      }
      d_1a965c = 0;
      f_1254a0(palette, 0);
    } else {
      scan = d_1bd762;
      if (event == 0x87 || scan == 0x5000 || scan == 0x4b00) {
        if (selected > 0) {
          if (f_0d37e0()) selected = 0;
          else --selected;
          d_1c2198 = 1;
        }
      } else if (event == 0x88 || scan == 0x4800 || scan == 0x4d00) {
        if (selected < 14) {
          if (f_0d37e0()) {
            if (selected < 14) selected = 14;
          } else ++selected;
          d_1c2198 = 1;
        }
      } else if (scan == 0x4700) {
        if (selected > 0) { selected = 0; d_1c2198 = 1; }
      } else if (scan == 0x4f00) {
        if (selected != 14) { selected = 14; d_1c2198 = 1; }
      } else if (event == 0x86 || scan == 0x11b) {
        L.finished = 1;
      }
    }
  }
  {
    int closingWindow = d_1bfdb8;
    if (closingWindow) operator delete(f_0da990(closingWindow, 0));
  }
  d_1bfdb8 = L.saved;
  f_1459d0(canvas, 0);
  f_1254a0(&image, 0);
}

//@ f_13b7b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 26 der Objektbenutzungstabelle: Schnitzt aus einem *Blasrohr* (0x17D) mithilfe
 *   einer Klinge eine *Blumenflöte* (0x17C). Ermittelt, welcher der beiden kombinierten Gegenstände (s1a oder
 *   s1e) das *Blasrohr* ist, legt über f_036a10 die *Blumenflöte* (0x17C) in das Inventar des betreffenden
 *   Helden, verbraucht über f_042c40 das *Blasrohr* und gibt die Erfolgsmeldung 0x1E01000B aus.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den Heldenzeigern f10 und f14, den Slots s18 und
 *   s1c sowie den Gegenstandskennungen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p->s1a, p->s1e: Gegenstandskennungen der beiden kombinierten Objekte zur Bestimmung, in welchem Slot das
 *     *Blasrohr* (0x17D) liegt.
 === Ende Beschreibung === */
void f_13b7b0(IT *p)
{
  SO o;
  short s;
  if (p->s1a == 0x17d) s = p->s18; else s = p->s1c;
  f_036300(p->o, s, 1);
  f_036a10(p->o, 0x17c, 1, s, 0);
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  o.p[1] = p->o;
  f_0bf730(d_1c2c64, 0x1e01000b);
  f_1254a0(&o, 0);
}

//@ f_13b840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 27 der Objektbenutzungstabelle: Verbindet einen *Y-Ast* (0x180) und ein
 *   *Spinnenseil* (0x181) zu einer *Schleuder* (0x1D1). Verbraucht beide Ausgangsgegenstände über f_042c40 aus
 *   den Inventarslots s18 und s1c, erzeugt über f_036a10 eine *Schleuder* (0x1D1) im Slot des ersten Gegenstands
 *   und zeigt die Erfolgsmeldung 0x1E01000C an.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den beiden Heldenzeigern f10 und f14, den Slots s18
 *   und s1c sowie den Gegenstandskennungen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - o: Lokaler Meldungsparameterblock (s_o20) für die Ausgabe der Erfolgsmeldung 0x1E01000C.
 === Ende Beschreibung === */
void f_13b840(IT *p)
{
  SO o;
  short s1;
  short s2;
  if (p->s1a == 0x181) s1 = p->s18; else s1 = p->s1c;
  if (p->s1a == 0x180) s2 = p->s18; else s2 = p->s1c;
  f_036300(p->o, s1, 1);
  f_036300(p->o, s2, 1);
  f_036a10(p->o, 0x1d1, 1, s2, 0);
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  int v = p->o; o.p[1] = v;
  f_0bf730(d_1c2c64, 0x1e01000c);
  f_1254a0(&o, 0);
}

//@ f_13b8f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 28 der Objektbenutzungstabelle: Prüft das globale Ereignisflag d_1c1070 bei der
 *   Benutzung eines besonderen Questgegenstands. Ist d_1c1070 == 0, wird im dritten Dungeon (d_1bc944 == 3) die
 *   Meldung 0x1E0100D8 und an allen anderen Orten die Meldung 0x1E0100D7 ausgegeben; ist d_1c1070 hingegen
 *   gesetzt, löscht die Funktion d_1c1070 = 0 und aktiviert die beiden globalen
 *   Fortschritts-/Szenenwechsel-Flags d_1c1074 = 1 und d_1bc940 = 1.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c1070, d_1c1074, d_1bc940: Globale Zustandsvariablen zur Steuerung des ausgelösten Dungeon-Ereignisses.
 === Ende Beschreibung === */
void f_13b8f0(IT *p)
{
  SO o;
  int u;
  if (EQB(d_1c1070, 0)) {
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    if (f_0de820(d_1c0004) == 3) {
      o.p[1] = p->o;
      f_0bf730(d_1c2c64, 0x1e0100d8);
    } else {
      o.p[1] = p->o;
      f_0bf730(d_1c2c64, 0x1e0100d7);
    }
    f_1254a0(&o, 0);
  } else {
    d_1c1070 = 0;
    d_1c1074 = 1;
    d_1bc940 = 1;
  }
}

//@ f_13b990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 29 der Objektbenutzungstabelle: Platzhalter-Handler, der über f_1191a0
 *   lediglich die statische Standard- bzw. Debug-Zeichenkette d_1a93c4 in einem einfachen Dialogfenster anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13b990(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13b9b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 30 der Objektbenutzungstabelle: Erlaubt das direkte Kombinieren eines einzelnen
 *   Rezepts (f_136ed0) oder Schriftstücks (f_136ea0) mit einem Buch (0xBF, 0x1DC oder 0x1D), ohne dass der
 *   Spieler das *Schreibzeug* selbst in die Hand nehmen muss. Sucht über f_1364f0(p, -1) nach einem
 *   *Schreibzeug* im Gruppeninventar und ruft bei Erfolg je nach Dokumenttyp die Übertragungsroutine f_135dc0
 *   (Rezept eintragen) oder f_135ef0 (Notiz/Dokument eintragen) auf; fehlt das *Schreibzeug*, erscheint die
 *   Meldung 0x1E0100A1.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den beiden kombinierten Gegenständen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - k: Gepackte Fundstelle des *Schreibzeugs* (-1, wenn keines im Gruppeninventar vorhanden ist).
 === Ende Beschreibung === */
void f_13b9b0(IT *p)
{
  short s;
  if (f_136ed0(p, p->s1a) != 0 || f_136ea0(p, p->s1a) != 0) f_135d40(p);
  if (f_136ed0(p, p->s1e) != 0) {
    s = f_1364f0(p, -1);
    if (s != -1) {
      f_135dc0(p, p->s18, s, p->s1c);
      return;
    }
  } else {
    if (f_136ea0(p, p->s1e) != 0) {
      s = f_1364f0(p, -1);
      if (s != -1) f_135ef0(p, p->s18, p->s1c, s);
    }
  }
}

//@ f_13ba50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 31 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13ba50(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13ba70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 32 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13ba70(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13ba90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 33 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13ba90(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13bab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 34 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13bab0(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13bad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 35 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13bad0(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13baf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 36 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13baf0(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13bb10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 37 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13bb10(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13bb30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 38 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13bb30(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}

//@ f_13bb50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 39 der Objektbenutzungstabelle: Unbenutzter Platzhalter-Handler, der über
 *   f_1191a0 die statische Debug-Zeichenkette d_1a93c4 anzeigt.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13bb50(void)
{
  f_0bf730(d_1c2c64, f_133fe0(d_1c3498, d_1a93c4));
}
