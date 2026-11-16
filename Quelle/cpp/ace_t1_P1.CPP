/* === Beschreibung (Katalog) ===
 * Einheit: ace_t1
 *
 * Adressbereich: 0x0104b0-0x011680
 * Spielsystem: Grafik / Animationen - Abspieler für ACE-Animationsdateien (Zwischensequenzen, Orts- und
 * Ausrüstungsanimationen; Schwesterklasse Anim in Sternenschweif OVL050.CPP / OVL051.CPP).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAFILE.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 25/33 gleich (suche.py 24.10.2026, Basis ace_t1_P1.CPP)
// ace.cpp (Schatten ueber Riva, Attic 1996) - Teil 1, Code 0x0104B0-0x011680
#include <string.h>
void *f_014540(int size, const char *file, int line);
int __cdecl f_099ef0(char *p, int a, int b);
int f_0a2520(void *sub, unsigned char c, int e, short w, short h, int img, void *buf);
int f_0d26e0();
int f_0d2710();
int f_0d3420(int a, int b, int c, int d);
struct ImgRaw { char d[9]; };
void *f_0fabf0(void *p);

void *f_014710(void *p);

RivaRasterImage *f_0fac80(RivaRasterImage *p, int w, int h);







extern RivaFileManager d_1c2098;
extern int d_1a34e0;
extern char d_1b62ec[];
extern short d_1bc5f4, d_1bc5f8;
extern volatile short d_1bc5f6; // Vom Timer-Interrupt gepflegter Animationszaehler
extern const char d_1a0134[];
#pragma pack(1)
struct H8 { char tag[4]; short ver; unsigned char cnt; char spd; };
struct H6 { short w; char h; char z; unsigned char n; char mode; };
struct E16 { int off; char x4[2]; short w; char h; char pad[5]; unsigned char n; char mode; };
struct FRec { int sz; short a, b, c, d; char f, g; };
struct Rec {
  short x, y, w, h; int e; unsigned char c, d;
  Rec(short a, short b, short c_, short d_, int e_, unsigned char f, unsigned char g) {
    x = a; y = b; w = c_; h = d_; e = e_; d = f; c = g;
  }
  unsigned short gw() { return w; }
  unsigned short gh() { return h; }
  int ge() { return e; }
  unsigned char gc() { return c; }
};
#define Ace f_0104b0
struct Ace {
  char *pal; unsigned short s4; char sub[0x8a];
  short x, w; unsigned char y, h; int i96; char *buf; Rec *rec; unsigned fid;
  short cnt, s8, n, idx; unsigned char spd, c_af, mode, c_b1, c_b2, c_b3;
  RivaRasterImage a, b; char *c6; char *ca; int f_ce; int f_d2; unsigned char tab[100]; int i13a;
  Ace(int p2, short p3, short p4); Ace *f_010590(int p_unused);
  void f_010640(int v); int f_010650(); char *f_010660(); unsigned short f_010670(); short f_010680(); unsigned char f_010690();
  void f_0106a0(int v); void f_0106b0(int v); unsigned char f_0106c0(); short f_0106d0();
  void f_0106e0(); void f_0109d0(); void f_010a20(RivaRasterImage *p2); int f_010a70(); void f_010a90(); void f_010dc0(short p2, short p3);
  int f_010e50(); void f_010f50(); void f_0110f0(short p2);
  void f_011350(short *p2, unsigned short *p3); void f_011370(short *p2, unsigned short *p3, short *p4, unsigned short *p5);
  void f_0113b0(short *p2, short *p3); void f_0113d0(short *p2, short *p3, short *p4, short *p5);
  void f_011410(short p2, short p3); void f_011440(RivaRasterImage *p2); void f_0114a0(short p2, short p3, char *p4);
  void f_0114e0(RivaRasterImage *p2); void f_011540(short p2, short p3, char *p4); void f_011580(); void f_0115a0();
  void f_0115c0(short p2, short p3, short p4);
};
extern Ace *d_1bc5f0;
#define Q(T, o) (*(T *)(q + (o)))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0104b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor eines 0x13e Bytes großen ACE-Animationsobjekts (Schwesterfunktion Anim::Anim
 *   in Sternenschweif OVL051.CPP). Setzt alle Puffer- und Statusfelder zurück, stellt den
 *   Standard-VGA-Zielpuffer d_1a34e0 ein, reserviert 0x300 Bytes für die Palette, trägt das Objekt als aktive
 *   Animation in d_1bc5f0 ein und lädt sofort die angegebene ACE-Ressource über f_010a90.
 * - Eingaben / Rückgabe: Eingaben sind der Objektzeiger (this), die Datei-/Archivkennung, die gewünschte
 *   Startsequenznummer sowie ein Quellenschalter (0 setzt Bit 31 der Kennung für Archivzugriff); gibt den
 *   initialisierten Objektzeiger zurück.
 * - Wichtige Variablen & Daten:
 *   - Animationsobjekt (0x13e Bytes): Palette (+0), Quellenschalter (+4), Entpack-Arbeitsbereich (+6, 0x8a
 *     Bytes), Position/Maße (x, w, y, h), Zielpuffer (+0x96), gepackter Bildpuffer (buf), aktueller
 *     Einzelbildkopf (rec), Ressourcenkennung (fid), Sequenz-/Bildzähler (cnt, s8, n, idx), Geschwindigkeit
 *     (spd), Bildmarke (c_af), Schleifenmodus (mode), Durchlaufzähler (c_b3), Vorder-/Hintergrund-Bitmaps (a,
 *     b), Markenfeld (tab[100] ab +0xd6), maximale gepackte Bildgröße (i13a bei +0x13a).
 *   - d_1bc5f0: Globaler Zeiger auf das aktuelle Animationsobjekt.
 *   - d_1bc5f4, d_1bc5f8: Globale Flags für "Animation läuft" und "keine Bilder überspringen".
 === Ende Beschreibung === */
Ace::Ace(int p2, short p3, short p4) {
  f_ce = 0; f_d2 = 0; n = 0; mode = 0; buf = 0; c6 = 0; ca = 0; rec = 0;
  fid = p2; s8 = p3; d_1bc5f4 = 0; idx = n; i96 = d_1a34e0; s4 = p4;
  void *u = f_014540(0x300, d_1a0134, 0x83);
  d_1bc5f0 = this; i13a = 0; pal = (char *)u; d_1bc5f8 = 0;
  f_010a90();
}
//@ f_010590
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor des ACE-Animationsobjekts (Anim::~Anim). Gibt Palette, gepackten
 *   Bilddatenpuffer, eigene Vorder-/Hintergrund-Pixelpuffer (nur falls nicht als fremd markiert) sowie den
 *   aktuellen Einzelbildkopf frei, hält die Animation an (d_1bc5f4 = 0, d_1bc5f0 = 0) und baut die eingebetteten
 *   Bitmap-Objekte ab.
 * - Eingaben / Rückgabe: Eingaben sind der Objektzeiger (this) und der ungenutzte Watcom-Destruktorschalter;
 *   gibt this zurück.
 * - Wichtige Variablen & Daten: Prüft die Fremdpuffer-Flags (f_ce, f_d2), bevor die Pixelpuffer (c6, ca) über
 *   f_014710 freigegeben werden.
 === Ende Beschreibung === */
Ace *Ace::f_010590(int p_unused) {
  if (pal) pal = (char *)f_014710(pal);
  if (buf) buf = (char *)f_014710(buf);
  if (c6 && !f_ce) c6 = (char *)f_014710(c6);
  if (ca && !f_d2) ca = (char *)f_014710(ca);
  { char *t = (char *)rec; if (t) f_014710(t); }
  d_1bc5f4 = 0; d_1bc5f0 = 0;
  char *q = (char *)b.f_0fad20(0);
  q = (char *)((RivaRasterImage*)(q - 9))->f_0fad20(0);
  return (Ace *)(q - 0xb4);
}
//@ f_010640
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Zielpuffer, in den die Animation bei jedem Taktschritt gezeichnet wird.
 * - Eingaben / Rückgabe: Objektzeiger (this) und Zielpuffer-Adresse/Handle; keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfeld Zielpuffer (+0x96, Standardwert d_1a34e0).
 === Ende Beschreibung === */
void Ace::f_010640(int v) { i96 = v; }
//@ f_010650
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert den aktuell eingestellten Zielpuffer der Animation zurück.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt den Zielpuffer (int) zurück.
 * - Wichtige Variablen & Daten: Objektfeld Zielpuffer (+0x96).
 === Ende Beschreibung === */
int Ace::f_010650() { return i96; }
//@ f_010660
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert den Zeiger auf den Puffer mit den komprimierten Daten des aktuellen Einzelbildes.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt den Datenpuffer-Zeiger (char *) zurück.
 * - Wichtige Variablen & Daten: Objektfeld buf (gepackte Bilddaten).
 === Ende Beschreibung === */
char *Ace::f_010660() { return buf; }
//@ f_010670
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Gesamthöhe der aktuellen Animationssequenz in Pixeln zurück.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die Höhe (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Objektfeld h (Sequenzhöhe).
 === Ende Beschreibung === */
unsigned short Ace::f_010670() { return h; }
//@ f_010680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Gesamtbreite der aktuellen Animationssequenz in Pixeln zurück.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die Breite (short) zurück.
 * - Wichtige Variablen & Daten: Objektfeld w (Sequenzbreite).
 === Ende Beschreibung === */
short Ace::f_010680() { return w; }
//@ f_010690
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert die Synchronisations-/Ereignismarke (cue) des zuletzt gezeigten Einzelbildes,
 *   anhand derer Aufrufer im Spiel (z. B. Zwischensequenzen) Ton- oder Textereignisse zeitgenau auslösen.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die Marke (unsigned char) zurück.
 * - Wichtige Variablen & Daten: Objektfeld c_af (wird in f_0106e0 aus tab[idx] geladen).
 === Ende Beschreibung === */
unsigned char Ace::f_010690() { return c_af; }
//@ f_0106a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Abspielgeschwindigkeit der Animation in Zeitgebertakten pro Einzelbild.
 * - Eingaben / Rückgabe: Objektzeiger (this) und Taktzahl pro Bild; keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfeld spd (Takte je Bild).
 === Ende Beschreibung === */
void Ace::f_0106a0(int v) { spd = v; }
//@ f_0106b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt den Schleifenmodus der Animation ein (3 = Endlosschleife, 0 = einmal abspielen und
 *   am Sequenzende anhalten).
 * - Eingaben / Rückgabe: Objektzeiger (this) und Schleifenmodus; keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfeld mode (0 oder 3).
 === Ende Beschreibung === */
void Ace::f_0106b0(int v) { mode = v; }
//@ f_0106c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt zurück, wie viele vollständige Durchläufe die aktuelle Sequenz seit dem Start bereits
 *   abgeschlossen hat.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die Durchlaufzahl (unsigned char) zurück.
 * - Wichtige Variablen & Daten: Objektfeld c_b3 (Durchlaufzähler).
 === Ende Beschreibung === */
unsigned char Ace::f_0106c0() { return c_b3; }
//@ f_0106d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Gesamtzahl der in der ACE-Datei enthaltenen Animationssequenzen zurück.
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die Sequenzanzahl (short) zurück.
 * - Wichtige Variablen & Daten: Objektfeld cnt (Anzahl der Sequenzen laut ACE-Dateikopf).
 === Ende Beschreibung === */
short Ace::f_0106d0() { return cnt; }
//@ f_0106e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Haupt-Taktschritt der Animation (Anim::tick in Sternenschweif OVL050.CPP). Prüft bei
 *   laufender Animation (d_1bc5f4 == 1), ob das vom Timer hochgezählte Taktguthaben d_1bc5f6 für das nächste
 *   Bild ausreicht, überspringt bei Verzögerung ggf. markenlose Zwischenbilder (sofern d_1bc5f8 == 0), lädt
 *   (f_010f50) und entpackt (f_0a2520) das aktuelle Einzelbild, setzt es auf den Hintergrund- oder geleerten
 *   Bildpuffer, blendet den Mauszeiger bei Überlappung kurz aus und kopiert das fertige Bild an Position (x, y)
 *   in den Zielpuffer. Anschließend wird die Bildmarke c_af aktualisiert und zum nächsten Bild weitergeschaltet.
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - d_1bc5f6: Vom Timer-Interrupt hochgezähltes Taktguthaben.
 *   - d_1bc5f4, d_1bc5f8: Laufstatus und Überspringsperre.
 *   - rec, buf, sub: Kopf und gepackte Daten des Einzelbildes sowie Entpack-Arbeitsbereich.
 *   - a, b, i96: Arbeits-Bitmap, optionale Hintergrund-Bitmap und Zielpuffer.
 === Ende Beschreibung === */
void Ace::f_0106e0() {
  // Erzwingt den EBP-Stapelrahmen wie im Original
  void local_frame(void);
#pragma aux local_frame = "" parm [] modify exact nomemory [esp];
  local_frame();
  struct Slot { short v, pad; };
  struct Frame { ImgRaw t; char pad[3]; int fl; Slot lw, lx, ly, lh; } l;
  l.fl = 0;
  if (d_1bc5f4 == 1) {
    int bv = spd;
    if (d_1bc5f6 >= bv) {
      if (d_1bc5f8 == 0) {
        d_1bc5f6 = d_1bc5f6 - (unsigned char)bv;
        if (d_1bc5f6 >= bv) {
          while (0 < d_1bc5f6) {
            d_1bc5f6 = d_1bc5f6 - spd;
            if (idx != (short)0 || c_b3) {
              if (!tab[idx]) f_0109d0();
            }
          }
          d_1bc5f6 = 0;
        }
      } else {
        d_1bc5f6 = 0;
      }
      if (d_1bc5f6 == 0 && d_1bc5f4 == 1) {
        if (idx != (short)0 || c_b3) f_010f50();
        l.lx.v = rec->x;
        l.ly.v = rec->y;
        short ww = rec->w;
        l.lw.v = ww;
        short hh = rec->h;
        l.lh.v = hh;
        f_0fac80((RivaRasterImage *)&l.t, ww, hh);
        f_0a2520(sub, rec->gc(), rec->ge(), rec->gw(), rec->gh(), ((int)(((RivaRasterImage *)&l.t)->f_0fb0b0())), buf);
        if (ca) a.f_0fb3a0((RivaRasterImage *)( &b), 0, 0, 0);
        else a.f_0fb120();
        a.f_0fb3a0((RivaRasterImage *)( &l.t), l.lx.v, l.ly.v, 1);
        int r = f_0d3420(x, y, (short)(x + w), (short)(y + h));
        if (r != 0) { l.fl = 1; f_0d2710(); }
        a.f_0fade0((void *)( i96), x, y);
        if (l.fl != 0) f_0d26e0();
        ((void *)(((RivaRasterImage*)(&l.t))->f_0fad20( 0)));
      }
      c_af = tab[idx];
      short j = (idx += 1);
      if (j >= n) {
        idx = 0;
        c_b3 = c_b3 + 1;
        if (mode == 0) d_1bc5f4 = 0;
      }
    }
  }
}
//@ f_0109d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet den Bildindex idx um 1 weiter (Anim::advance); am Ende der Sequenz (idx >= n)
 *   wird idx auf 0 zurückgesetzt, der Durchlaufzähler c_b3 erhöht und bei Einmal-Abspielung (mode == 0) die
 *   Animation gestoppt (d_1bc5f4 = 0).
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder idx (aktuelles Bild), n (Bilderzahl), c_b3 (Durchläufe), mode
 *   (Schleifenart) und globales Flag d_1bc5f4.
 === Ende Beschreibung === */
void Ace::f_0109d0() {
  short s = idx + 1; idx = s;
  if (n <= s) {
    idx = 0; c_b3 = c_b3 + 1;
    if (mode == 0) d_1bc5f4 = 0;
  }
}
//@ f_010a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entpackt das aktuell im Puffer buf geladene Einzelbild anhand der Maße und Packart aus rec
 *   über f_0a2520 in das übergebene Bitmap-Objekt (Anim::unpack).
 * - Eingaben / Rückgabe: Objektzeiger (this) und Zeiger auf das Ziel-Bitmap-Objekt; keine Rückgabe.
 * - Wichtige Variablen & Daten: Nutzt den objektinternen Arbeitsbereich sub, den Bildkopf rec und den
 *   Datenpuffer buf.
 === Ende Beschreibung === */
void Ace::f_010a20(RivaRasterImage *p2) {
  f_0a2520(sub, rec->gc(), rec->ge(), rec->gw(), rec->gh(), ((int)(p2->f_0fb0b0())), buf);
}
//@ f_010a70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die Animation derzeit aktiv läuft (Anim::running).
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt 1 zurück, wenn d_1bc5f4 == 1, sonst 0.
 * - Wichtige Variablen & Daten: Globales Statusflag d_1bc5f4.
 === Ende Beschreibung === */
int Ace::f_010a70() { return d_1bc5f4 == 1; }
//@ f_010a90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die ACE-Datei über das globale Archivobjekt d_1c2098, prüft die Kennung "ACE" und
 *   Version 1, ermittelt über f_010e50 die größte vorkommende Einzelbildgröße, liest den Sequenzkopf (bzw.
 *   Kurzkopf bei nur einer Sequenz), reserviert den Datenpuffer buf, lädt das erste Einzelbild samt Kopf rec,
 *   liest die Marken (cue) aller Einzelbilder der Sequenz in tab[] ein und lädt abschließend die
 *   256-Farben-Palette (0x300 Bytes) vom Dateiende (Anim::load).
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - d_1c2098: Globales Archiv-/Dateiladeobjekt.
 *   - h, e, h6, fr: Lokale Dateikopf-Strukturen (8-Byte-Kopf, 16-Byte-Sequenzsatz, 6-Byte-Kurzkopf,
 *     14-Byte-Einzelbildkopf).
 *   - tab[100]: Array für die Ereignismarken der Einzelbilder ab Offset +0xd6.
 * - Besonderheiten / Originalfehler: Das Array tab fasst fest 100 Bytes, die Schleife for (i = 0; i < n; i++)
 *   prüft die aus der Datei gelesene Bilderzahl n (0..255) jedoch nicht gegen 100. Bei Sequenzen mit mehr als
 *   100 Bildern werden i13a und nachfolgender Speicher überschrieben (ebenso in f_0110f0).
 === Ende Beschreibung === */
int f_144bf0(const char *a, const char *b);
void Ace::f_010a90() {
  E16 e; FRec fr; H8 h; H6 h6;
  short i;
  unsigned id;
  if (!(short)s4) id = fid | 0x80000000; else id = fid;
  if (d_1c2098.f_1448b0(id, 0x200)) {
    d_1c2098.f_144920(&h, 8);
    if (f_144bf0(h.tag, d_1b62ec) == 0) {
      spd = h.spd;
      if (h.ver == 1) {
        cnt = h.cnt;
        f_010e50();
        d_1c2098.f_144ab0(8, 0);
        if (h.cnt > 1) {
          for (i = 0; i <= s8; i++) d_1c2098.f_144920(&e, 0x10);
          w = e.w;
          this->h = e.h;
          n = e.n;
          mode = e.mode;
          if (mode == 1) mode = 3;
          if (mode != 0 && mode != 3) mode = 0;
          if (buf == 0) buf = (char *)f_014540(i13a, d_1a0134, 0x1ab);
          d_1c2098.f_144ab0(e.off, 0);
        } else {
          d_1c2098.f_144920(&h6, 6);
          w = h6.w;
          this->h = h6.h;
          n = h6.n;
          mode = h6.mode;
          if (mode == 1) mode = 3;
          if (mode != 0 && mode != 3) mode = 0;
          if (buf == 0) buf = (char *)f_014540(i13a, d_1a0134, 0x1c5);
          d_1c2098.f_144ab0(0xe, 0);
        }
        for (i = 0; i < n; i++) {
          d_1c2098.f_144920(&fr, 0xe);
          if (i == (short)0) {
            d_1c2098.f_144920(buf, fr.sz);
            rec = new (mark(d_1a0134, 0x1d3)) Rec(fr.a, fr.b, fr.c, fr.d, fr.sz, fr.g, fr.f);
          } else {
            d_1c2098.f_144ab0(fr.sz, 1);
          }
#if FIX_R006   /* R006: Markenfeld tab[100] vor Ueberlauf bei ACE-Sequenzen mit mehr als 100 Bildern schuetzen */
          if (i < 100) tab[i] = fr.g;
#else
          tab[i] = fr.g;
#endif
        }
        d_1c2098.f_144ab0(-0x300, 2);
        d_1c2098.f_144920(pal, 0x300);
      }
    }
    d_1c2098.f_1449a0();
  }
}
//@ f_010dc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt einen Teilbereich der 256-Farben-Palette aus den letzten 0x300 Bytes der ACE-Datei in
 *   den Palettenpuffer pal des Animationsobjekts nach (Anim::load_pal).
 * - Eingaben / Rückgabe: Objektzeiger (this), Index der ersten Farbe (p2) und Anzahl der zu ladenden Farben
 *   (p3); keine Rückgabe.
 * - Wichtige Variablen & Daten: Positioniert den Dateizeiger relativ zum Dateiende auf -(256 - p2) * 3 und liest
 *   p3 * 3 Bytes nach pal + p2 * 3.
 === Ende Beschreibung === */
void Ace::f_010dc0(short p2, short p3) {
  unsigned id;
  if (!s4) id = fid | 0x80000000; else id = fid;
  if (d_1c2098.f_1448b0(id, 0x200) != 0) {
    d_1c2098.f_144ab0(-(0x100 - p2) * 3, 2);
    d_1c2098.f_144920(pal + p2 * 3, p3 * 3);
    d_1c2098.f_1449a0();
  }
}
//@ f_010e50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchläuft alle Sequenzen und Einzelbildköpfe der geöffneten ACE-Datei und ermittelt die
 *   größte gepackte Einzelbildgröße, damit der Datenpuffer buf ausreichend groß dimensioniert werden kann
 *   (Anim::max_frame_size).
 * - Eingaben / Rückgabe: Objektzeiger (this); gibt die maximale gepackte Bildgröße in Bytes (i13a) zurück.
 * - Wichtige Variablen & Daten: Aktualisiert das Objektfeld i13a (+0x13a) und verändert dabei vorübergehend auch
 *   n.
 === Ende Beschreibung === */
int Ace::f_010e50() {
  E16 e; H6 h6; FRec fr; short s, t;
  for (s = 0; s < cnt; s = s + 1) {
    d_1c2098.f_144ab0(8, 0);
    if (cnt > 1) {
      d_1c2098.f_144ab0((int)s << 4, 1);
      d_1c2098.f_144920(&e, 0x10);
      d_1c2098.f_144ab0(e.off, 0);
      n = e.n;
    } else {
      d_1c2098.f_144920(&h6, 6);
      n = h6.n;
    }
    for (t = 0; t < n; t = t + 1) {
      d_1c2098.f_144920(&fr, 0xe);
      if (fr.sz > i13a) i13a = fr.sz;
      d_1c2098.f_144ab0(fr.sz, 1);
    }
  }
  return i13a;
}
//@ f_010f50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die ACE-Datei, springt zur aktuellen Sequenz s8 und zum Einzelbild idx, liest
 *   dessen komprimierte Bilddaten in buf ein und legt einen neuen Einzelbildkopf rec im Speicher an
 *   (Anim::load_frame).
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Ersetzt den bisherigen Einzelbildkopf rec durch eine neue 14-Byte-Instanz und
 *   füllt buf mit fr.sz Bytes.
 === Ende Beschreibung === */
void Ace::f_010f50() {
  E16 e;
  FRec fr;
  short i;
  unsigned id;
  if (!s4) id = fid | 0x80000000; else id = fid;
  if (d_1c2098.f_1448b0(id, 0x200)) {
    if (cnt > 1) {
      int o;
      d_1c2098.f_144ab0(8, 0);
      i = 0;
      if (s8 >= (short)0) {
        do {
          d_1c2098.f_144920(&e, 0x10);
          i++;
        } while (i <= s8);
      }
      o = e.off;
      d_1c2098.f_144ab0(o, 0);
    } else {
      d_1c2098.f_144ab0(0xe, 0);
    }
    i = 0;
    if (idx > (short)0) {
      do {
        d_1c2098.f_144920(&fr, 0xe);
        d_1c2098.f_144ab0(fr.sz, 1);
        i++;
      } while (i < idx);
    }
    d_1c2098.f_144920(&fr, 0xe);
    d_1c2098.f_144920(buf, fr.sz);
    Rec *old = rec;
    if (old) f_014710(old);
    rec = new (mark(d_1a0134, 0x25c)) Rec(fr.a, fr.b, fr.c, fr.d, fr.sz, fr.g, fr.f);
    d_1c2098.f_1449a0();
  }
}
//@ f_0110f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wechselt die aktive Animationssequenz auf die Nummer p2 (sofern p2 < cnt), hält die
 *   laufende Animation an, gibt eigene Bild-/Hintergrundpuffer sowie den alten Einzelbildkopf rec frei, liest
 *   den neuen Sequenzsatz, das erste Einzelbild und die Markenliste tab[] aus der ACE-Datei und startet die
 *   Animation über f_0115c0(-1, -1, 0) neu (Anim::select_seq).
 * - Eingaben / Rückgabe: Objektzeiger (this) und gewünschte Sequenznummer (p2); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder s8 (Sequenznummer), w, h, n, mode, rec, buf, tab[100].
 * - Besonderheiten / Originalfehler: Gibt rec vor dem Dateiöffnen mit delete rec; frei, ohne rec = 0 zu setzen.
 *   Schlägt das Öffnen der Datei fehl oder hat die Sequenz n == 0 Bilder, bleibt rec als Dangling Pointer stehen
 *   (führt später zu Zugriff auf freien Speicher oder Double Free; identisch zu Sternenschweif OVL050.CPP).
 *   Zudem fehlt wie in f_010a90 die Prüfung n <= 100 beim Beschreiben von tab[s].
 === Ende Beschreibung === */
void Ace::f_0110f0(short p2) {
  E16 e; FRec fr; short s; unsigned id;
  if (p2 < cnt) {
    s8 = p2; d_1bc5f4 = 0;
    a.f_0fadc0();
    if (c6 && !f_ce) c6 = (char *)f_014710(c6);
    b.f_0fadc0();
    if (ca && !f_d2) ca = (char *)f_014710(ca);
#if FIX_R006   /* R006: rec nach delete auf 0 setzen (verhindert Dangling Pointer) und tab[100] begrenzen */
    if (rec) { delete rec; rec = 0; }
#else
    if (rec) delete rec;
#endif
    if (!s4) id = fid | 0x80000000; else id = fid;
    if (d_1c2098.f_1448b0(id, 0x200) != 0) {
      d_1c2098.f_144ab0(8, 0);
      s = 0;
      if (p2 >= (short)0) {
        do {
          s = s + 1;
          d_1c2098.f_144920(&e, 0x10);
        } while (s <= p2);
      }
      w = e.w; h = e.h; n = e.n; mode = e.mode;
      if (mode == 1) mode = 3;
      if (mode != 0 && mode != 3) mode = 0;
      d_1c2098.f_144ab0(e.off, 0);
      for (s = 0; s < n; s++) {
          d_1c2098.f_144920(&fr, 0xe);
          if (s == (short)0) {
            d_1c2098.f_144920(buf, fr.sz);
            rec = new (mark(d_1a0134, 0x2b0)) Rec(fr.a, fr.b, fr.c, fr.d, fr.sz, fr.g, fr.f);
          } else {
            d_1c2098.f_144ab0(fr.sz, 1);
          }
#if FIX_R006
          if (s < 100) tab[s] = fr.g;
#else
          tab[s] = fr.g;
#endif
      }
      d_1c2098.f_1449a0();
    }
    f_0115c0(-1, -1, 0);
  }
}
//@ f_011350
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt Gesamtbreite und Gesamthöhe der aktuellen Animationssequenz in zwei übergebene
 *   Ausgabevariablen (Anim::size).
 * - Eingaben / Rückgabe: Objektzeiger (this) sowie Zeiger für Breite und Höhe; keine Rückgabe.
 * - Wichtige Variablen & Daten: Liest Objektfelder w und h.
 === Ende Beschreibung === */
void Ace::f_011350(short *p2, unsigned short *p3) { *p2 = w; *p3 = h; }
//@ f_011370
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt Anzeigeposition (x, y) und Gesamtgröße (w, h) der Animation in vier
 *   Ausgabevariablen (Anim::area).
 * - Eingaben / Rückgabe: Objektzeiger (this) sowie Zeiger für x, y, w, h; keine Rückgabe.
 * - Wichtige Variablen & Daten: Liest Objektfelder x, y, w, h.
 === Ende Beschreibung === */
void Ace::f_011370(short *p2, unsigned short *p3, short *p4, unsigned short *p5) { *p2 = x; unsigned int yy = y; *p3 = yy; *p4 = w; *p5 = h; }
//@ f_0113b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert Breite und Höhe des aktuellen Einzelbildes aus dessen Bildkopf rec
 *   (Anim::frame_size).
 * - Eingaben / Rückgabe: Objektzeiger (this) sowie Zeiger für Einzelbild-Breite und -Höhe; keine Rückgabe.
 * - Wichtige Variablen & Daten: Liest rec->w und rec->h.
 === Ende Beschreibung === */
void Ace::f_0113b0(short *p2, short *p3) { *p2 = rec->w; *p3 = rec->h; }
//@ f_0113d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liefert Relativversatz (x, y) sowie Breite und Höhe (w, h) des aktuellen Einzelbildes aus
 *   dem Bildkopf rec (Anim::rect).
 * - Eingaben / Rückgabe: Objektzeiger (this) sowie vier short-Zeiger für x, y, w, h; keine Rückgabe.
 * - Wichtige Variablen & Daten: Liest rec->x, rec->y, rec->w, rec->h.
 === Ende Beschreibung === */
void Ace::f_0113d0(short *p2, short *p3, short *p4, short *p5) { *p2 = rec->x; *p3 = rec->y; *p4 = rec->w; *p5 = rec->h; }
//@ f_011410
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Aktiviert einen Ausschnitt der Animationspalette am Bildschirm über f_099ef0
 *   (Anim::pal_set, z. B. beim Öffnen des Ausrüstungsbildschirms in equip).
 * - Eingaben / Rückgabe: Objektzeiger (this), erster Farbindex (p2) und Anzahl der Farben (p3); keine Rückgabe.
 * - Wichtige Variablen & Daten: Übergibt pal + p2 * 3 an die Palettenfunktion f_099ef0.
 === Ende Beschreibung === */
void Ace::f_011410(short p2, short p3) { f_099ef0(pal + p2 * 3, p2, p3); }
//@ f_011440
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löst den bisherigen Arbeits-Bildpuffer der Animation und übernimmt den Pixelpuffer sowie
 *   die Maße eines übergebenen Bitmap-Objekts als fremden (nicht vom Destruktor freizugebenden) Bildpuffer
 *   (Anim::setbuf(Bmp*)).
 * - Eingaben / Rückgabe: Objektzeiger (this) und Zeiger auf das Quell-Bitmap-Objekt; keine Rückgabe.
 * - Wichtige Variablen & Daten: Setzt das Fremdpuffer-Flag f_ce = 1, speichert den Pixelzeiger in c6 und
 *   initialisiert die eingebettete Bitmap a.
 === Ende Beschreibung === */
void Ace::f_011440(RivaRasterImage *p2) {
  short l14, l18;
  f_ce = 0;
  a.f_0fadc0();
  p2->f_0fb210((short *)( &l14),(short *)( &l18));
  f_ce = 1;
  c6 = p2->f_0fb0b0();
  a.f_0fad50( l14, l18,(void *)( c6));
}
//@ f_0114a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Übernimmt einen rohen Pixelpuffer gegebener Breite und Höhe als fremden Arbeits-Bildpuffer
 *   der Animation (Anim::setbuf(w, h, p)).
 * - Eingaben / Rückgabe: Objektzeiger (this), Breite (p2), Höhe (p3) und Pixelpuffer-Zeiger (p4); keine
 *   Rückgabe.
 * - Wichtige Variablen & Daten: Setzt f_ce = 1, c6 = p4 und initialisiert Bitmap a.
 === Ende Beschreibung === */
void Ace::f_0114a0(short p2, short p3, char *p4) {
  f_ce = 0;
  a.f_0fadc0();
  f_ce = 1;
  c6 = p4;
  a.f_0fad50( p2, p3,(void *)( p4));
}
//@ f_0114e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Übernimmt Maße und Pixelpuffer eines Bitmap-Objekts als fremden Hintergrundpuffer b, der
 *   bei jedem Taktschritt unter das Einzelbild gelegt wird (Anim::setbg(Bmp*)).
 * - Eingaben / Rückgabe: Objektzeiger (this) und Zeiger auf das Hintergrund-Bitmap-Objekt; keine Rückgabe.
 * - Wichtige Variablen & Daten: Setzt das Fremdpuffer-Flag f_d2 = 1, speichert den Pixelzeiger in ca und
 *   initialisiert die eingebettete Hintergrund-Bitmap b.
 === Ende Beschreibung === */
void Ace::f_0114e0(RivaRasterImage *p2) {
  short l14, l18;
  f_d2 = 0;
  b.f_0fadc0();
  p2->f_0fb210((short *)( &l14),(short *)( &l18));
  f_d2 = 1;
  ca = p2->f_0fb0b0();
  b.f_0fad50( l14, l18,(void *)( ca));
}
//@ f_011540
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Übernimmt einen rohen Pixelpuffer gegebener Breite und Höhe als fremden Hintergrundpuffer
 *   der Animation (Anim::setbg(w, h, p)).
 * - Eingaben / Rückgabe: Objektzeiger (this), Breite (p2), Höhe (p3) und Pixelpuffer-Zeiger (p4); keine
 *   Rückgabe.
 * - Wichtige Variablen & Daten: Setzt f_d2 = 1, ca = p4 und initialisiert Bitmap b.
 === Ende Beschreibung === */
void Ace::f_011540(short p2, short p3, char *p4) {
  f_d2 = 0;
  b.f_0fadc0();
  f_d2 = 1;
  ca = p4;
  b.f_0fad50( p2, p3,(void *)( p4));
}
//@ f_011580
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löst die Zuordnung des Arbeits-Bildpuffers a und gibt dessen Zeilenverzeichnis frei
 *   (Anim::clr_buf).
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Setzt f_ce = 0 und ruft f_0fadc0(&a) auf.
 === Ende Beschreibung === */
void Ace::f_011580() { f_ce = 0; a.f_0fadc0(); }
//@ f_0115a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löst die Zuordnung des Hintergrundpuffers b und gibt dessen Zeilenverzeichnis frei
 *   (Anim::clr_bg).
 * - Eingaben / Rückgabe: Objektzeiger (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Setzt f_d2 = 0 und ruft f_0fadc0(&b) auf.
 === Ende Beschreibung === */
void Ace::f_0115a0() { f_d2 = 0; b.f_0fadc0(); }
//@ f_0115c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Startet das Abspielen der geladenen Animation (Anim::start): übernimmt neue
 *   Bildschirmkoordinaten x/y (falls >= 0), legt bei fehlendem Arbeits-Bildpuffer c6 einen eigenen Puffer der
 *   Größe w * h an, erzwingt eine Mindestgeschwindigkeit spd >= 1, setzt Durchlaufzähler und Bildmarke auf 0 und
 *   schaltet die globale Abspielsteuerung (d_1bc5f6 = spd, d_1bc5f8 = p4, d_1bc5f4 = 1) scharf.
 * - Eingaben / Rückgabe: Objektzeiger (this), X-Koordinate (p2, < 0 behält alten Wert), Y-Koordinate (p3, < 0
 *   behält alten Wert) und Flag "keine Bilder überspringen" (p4); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder x, y, c6, a, spd, c_b3, c_af, c_b1 sowie globale
 *   Animationssteuerung d_1bc5f4, d_1bc5f6, d_1bc5f8.
 === Ende Beschreibung === */
void Ace::f_0115c0(short p2, short p3, short p4) {
  if (p2 >= 0) x = p2;
  if (p3 >= 0) y = p3;
  if (c6 == 0) {
    c6 = (char *)f_014540((int)w * (unsigned)h, d_1a0134, 0x34b);
    a.f_0fad50( w, h,(void *)( c6));
  }
  if (n != (short)0) {
    if (!spd) spd = 1;
    c_b3 = 0; c_af = 0;
    d_1bc5f6 = spd;
    d_1bc5f8 = p4;
    c_b1 = 0;
    d_1bc5f4 = 1;
  }
}
