/* === Beschreibung (Katalog) ===
 * Einheit gz_05dec0 (0x05dec0 - 0x05ec80)
 *
 * Überblick
 * Diese Einheit implementiert das zentrale Textausgabe- und Glyphenzeichenmodul des Spiels (Klassen Buf und
 * Text) und bildet das objektorientierte Gegenstück zu seg096.c (GUI_print_string, GUI_count_lines,
 * GUI_print_char usw.) aus *Schicksalsklinge*. Sie verwaltet Textfenster, Ränder, Zentrierung, Einrückung,
 * Tabulatoren, Farbtabellen, automatische Satzanfang-Großschreibung sowie das Einsetzen von Platzhaltern (ESC +
 * 3 Bytes) und Steuercodes (0xF0..0xF7, @, ~, ^).
 === Ende Beschreibung === */
// P3 32/37 gleich (suche.py 29.10.2026, Basis gz_05dec0_P1.CPP)
// gz_05dec0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x05DEC0-0x05ECF0
#include <string.h>
#include "RIVAMEM.H"



int __cdecl f_11e910(char *a, int b, int c, int d, int e, int f, int g, int h);
int f_1254e0(int p1);
int f_125500(int p1);
int f_125550(int p1, int p2, int p3, int p4);
int f_145400(int p1);
extern char d_1bcad4[];
extern char d_1bd0b0[];
extern char d_1bd68b[];
extern int d_1c0c48;
struct B10 { char b[10]; };
struct Font {
  virtual int v0();
  virtual int v4(unsigned char c, short x, short y, int ptr, short s);
  virtual unsigned char v8(int c);
};
struct Buf {
  short s0;
  short stride;
  char pad4[2];
  char *buf;
  char *f_05dec0();
  void f_05ded0(char *p);
  int f_05dee0();
  int f_05def0(double a);
  short f_05df00(char *s, short w, unsigned char h, short x, short y, char *tbl, short fill);
  int f_05dfc0();
  short f_05dfd0(char *s, short w, short h, short x, short y, char *tbl, short fill);
  short f_05e080(signed char *s, int w, short h, short x, short y, char *tbl, short fill);
};
struct Text {
  Font *f;
  short s4, s6, s8, sa, sc, se, s10, s12, s14;
  short v16[7];
  short s24, s26;
  char b28[10];
  short s32, s34, s36, s38, s3a, s3c, s3e;
  int i40, i44;
  void f_05e170();
  void f_05e1c0(Font *p);
  void f_05e1d0(short a, short b);
  short f_05e1f0();
  short f_05e200();
  short f_05e210(char *s);
  short f_05e270(char *s);
  void f_05e2a0(short *a, short *b, short *c, short *d);
  void f_05e2d0(short a, short b, short c, short d);
  void f_05e320(short a, short b);
  void f_05e340();
  void f_05e360(short *a, short *b);
  void f_05e380(short a, short b, short c, short d, short e);
  void f_05e3d0();
  void f_05e400(int a);
  int f_05e410();
  short f_05e420(short a);
  short f_05e440(char *s);
  char *f_05e490(char *p);
  short f_05e610(char *s);
  short f_05e770(char *s, short a, short b);
  void f_05e7e0(short a, short b);
  void f_05e800(short *a, short *b);
  short f_05e820(short i);
  void f_05e830(short v, short i);
  void f_05e840(int a);
  int f_05e850();
  short f_05e860(char *s, short x, short y);
  short f_05ebd0(signed char ch, short x, short y);
};
//@ f_05dec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den Zeiger auf den aktuellen Zielbildspeicher (buf, Offset +8) einer
 *   Glyphen-Zeichenfläche (Buf).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Buf-Objekts und gibt den Bildspeicherzeiger
 *   char* zurück.
 * - Wichtige Variablen: Liest das Feld this->buf (+0x08), das beispielsweise beim Öffnen des Tagebuchs oder
 *   Editors vorübergehend auf einen Hintergrundpuffer umgelenkt wird.
 === Ende Beschreibung === */
char *Buf::f_05dec0() { return buf; }
//@ f_05ded0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zielbildspeicher (buf, Offset +8) einer Glyphen-Zeichenfläche (Buf) auf den
 *   übergebenen Puffer p.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Buf-Objekts und den neuen Pufferzeiger p. Sie
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt das Feld this->buf (+0x08).
 === Ende Beschreibung === */
void Buf::f_05ded0(char *p) { buf = p; }
//@ f_05dee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Virtuelle Kennungsmethode der ersten Zeichenflächen-Variante (Buf), die konstant den Typwert 1
 *   zurückgibt.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt konstant 1 als int zurück.
 * - Wichtige Variablen: Es werden keine Variablen verändert.
 === Ende Beschreibung === */
int Buf::f_05dee0() { return 1; }
//@ f_05def0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere virtuelle Platzhaltermethode der Zeichenflächen-Klasse (Buf), die konstant 0 liefert.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und einen ungenutzten double-Wert a und gibt 0
 *   zurück.
 * - Wichtige Variablen: Es werden keine Variablen verwendet.
 === Ende Beschreibung === */
int Buf::f_05def0(double a) { return 0; }
extern void blit_tr(const unsigned char *s, unsigned char *d, const unsigned char *tbl, unsigned char h, unsigned char w);
#pragma aux blit_tr parm [esi] [edi] [ebx] [cl] [ch] modify [eax ecx edx esi edi] = \
    "    xor  eax,eax"       \
    "    mov  dh,ch"         \
    "z:  push edi"           \
    "p:  mov  al,[esi]"      \
    "    inc  esi"           \
    "    or   al,al"         \
    "    je   n"             \
    "    add  eax,eax"       \
    "    mov  al,[ebx+eax]"  \
    "    mov  [edi],al"      \
    "n:  inc  edi"           \
    "    dec  ch"            \
    "    jne  p"             \
    "    pop  edi"           \
    "    mov  ch,dh"         \
    "    lea  edi,[edi+320]" \
    "    dec  cl"            \
    "    jne  z";

extern void blit_fill(const unsigned char *s, unsigned char *d, const unsigned char *tbl, unsigned char h, unsigned char w, unsigned char fill);
#pragma aux blit_fill parm [esi] [edi] [ebx] [cl] [ch] [dl] modify [eax ecx edx esi edi] = \
    "    xor  eax,eax"       \
    "    mov  dh,ch"         \
    "z:  push edi"           \
    "p:  mov  al,[esi]"      \
    "    inc  esi"           \
    "    or   al,al"         \
    "    je   f"             \
    "    add  eax,eax"       \
    "    mov  al,[ebx+eax]"  \
    "    mov  [edi],al"      \
    "    jmp  n"             \
    "f:  mov  [edi],dl"      \
    "n:  inc  edi"           \
    "    dec  ch"            \
    "    jne  p"             \
    "    pop  edi"           \
    "    mov  ch,dh"         \
    "    lea  edi,[edi+320]" \
    "    dec  cl"            \
    "    jne  z";

//@ f_05df00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet eine einzelne Schriftglyphe (s, Breite w, Höhe h) an die Position (x, y) in einen 320
 *   Pixel breiten Bildspeicher (this->buf), wobei gesetzte Pixel über die Wort-Farbtabelle tbl eingefärbt werden
 *   und leere Pixel (0) entweder transparent bleiben (fill == -1) oder mit der Hintergrundfarbe fill gefüllt
 *   werden (Schwesterfunktion GUI_write_char_to_screen in *Schicksalsklinge* seg096.c).
 * - Eingaben und Rückgabe: Die Methode erhält das Buf-Objekt, die Glyphenbitmap s, Breite w, Höhe h,
 *   Zielkoordinaten x und y (wobei ein Aufschlag y >= 2000 abgezogen wird), die Farbtabelle tbl und die
 *   Hintergrundfarbe fill. Sie gibt die Vorschubbreite w + 1 als short zurück.
 * - Wichtige Variablen: Die beiden Inline-Assemblerschleifen blit_tr und blit_fill kopieren die Glyphenzeilen
 *   mit festem Zeilenabstand 320 (0x140) in den Zielpuffer this->buf.
 === Ende Beschreibung === */
short Buf::f_05df00(char *s, short w, unsigned char h, short x, short y, char *tbl, short fill) {
  if (y >= 2000) y -= 2000;
  {
  unsigned char *d = (unsigned char *)buf + y * 0x140 + x;
  if (fill == -1) blit_tr((const unsigned char *)s, d, (const unsigned char *)tbl, h, w);
  else blit_fill((const unsigned char *)s, d, (const unsigned char *)tbl, h, w, (unsigned char)fill);
  }
  short r = w + 1;
  return r;
}
//@ f_05dfc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Virtuelle Kennungsmethode der zweiten Zeichenflächen-Variante (Buf), die konstant den Typwert
 *   2 zurückgibt.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt konstant 2 als int zurück.
 * - Wichtige Variablen: Es werden keine Variablen verändert.
 === Ende Beschreibung === */
int Buf::f_05dfc0() { return 2; }
//@ f_05dfd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zweite Variante der Glyphenausgabe: liegt y >= 2000 vor, zeichnet sie die Glyphe über f_05e080
 *   bei y - 2000 direkt in den Puffer this->buf; andernfalls färbt sie alle gesetzten Pixel (!= 0) der Glyphe s
 *   auf die Farbe *tbl um und gibt die Glyphe über die allgemeine Blit-Funktion f_11e910 an (x, y) aus.
 * - Eingaben und Rückgabe: Die Methode erhält dieselben Parameter wie f_05df00 (s, w, h, x, y, tbl, fill) und
 *   gibt die Vorschubbreite w + 1 als short zurück.
 * - Wichtige Variablen: Ein bemerkenswerter Originalbefund ist, dass die Schleife for (i = 0, p = s; i < w * h;
 *   i++, p++) if (*p != 0) *p = *tbl; die übergebene Quell-Glyphenbitmap s direkt in-place überschreibt.
 === Ende Beschreibung === */
short Buf::f_05dfd0(char *s, short w, short h, short x, short y, char *tbl, short fill) {
  short i;
  signed char c;
  char *p;
  if (y >= 2000) return f_05e080((signed char *)s, w, h, x, y - 2000, tbl, fill);
  // Die (unsigned)-Casts am f_11e910-Aufruf verhindern, dass der
  // Optimierer die short->int-Wandlung von w/h mit der der Schleifenbedingung
  // zu einem Web zusammenlegt (sonst landen w/h statt SI/DI auf dem Stapel).
  for (i = 0, p = s; i < w * h; i++, p++) {
    c = *p;
    if (c != 0) *p = *tbl;
  }
  f_11e910(s, 0, 0, (unsigned)w, (unsigned)h, (unsigned)w, (unsigned)x, (unsigned)y);
  return w + 1;
}
//@ f_05e080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet eine Glyphe (s, Breite w, Höhe h) an die Position (x, y) in einen Bildpuffer
 *   this->buf mit beliebiger Zeilenlänge this->stride (+0x02), wobei gesetzte Pixel die Farbe tbl[2] erhalten
 *   und Hintergrundpixel bei fill == -1 durchsichtig bleiben oder sonst mit fill gefüllt werden.
 * - Eingaben und Rückgabe: Die Methode erhält das Buf-Objekt, die Glyphenbitmap s, Breite w, Höhe h,
 *   Zielkoordinaten x und y, Farbtabelle tbl und Hintergrundfarbe fill. Sie gibt w + 1 als short zurück.
 * - Wichtige Variablen: Das Feld this->stride (+0x02) bestimmt den Zeilenversatz in Bytes innerhalb des
 *   Zielpuffers this->buf.
 === Ende Beschreibung === */
short Buf::f_05e080(signed char *s, int w, short h, short x, short y, char *tbl, short fill) {
  char *d;
  short i, j, k;
  int offset = stride;
  offset *= y;
  d = buf + offset + x;
  if (fill == -1) {
    for (i = 0; i < h; i++) {
      for (j = 0; j < (short)w; j += 1) {
        if (*s++ != 0) *d = tbl[2];
        d++;
      }
      int width = (short)w;
      int step = width;
      step = *(volatile short *)&stride - step;
      d += step;
    }
  } else {
    for (k = 0; k < h; k++) {
      for (j = 0; j < (short)w; j++) {
        if (*s++ != 0) *d++ = tbl[2]; else *d++ = fill;
      }
      int step2 = stride - (short)w;
      d += step2;
    }
  }
  return w + 1;
}
//@ f_05e170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Textausgabe-Objekt (Text) auf seine Standardwerte zurück: Vordergrundfarbe 0xff,
 *   Hintergrundfarbe 0, Farbindex 0, Zeilenabstand 0, keine Einrückung, automatische Satzanfang-Großschreibung
 *   ein (i44 = 1), linker und oberer Rand 1, Zeilenbreite 80 Pixel und linksbündige Ausgabe (se = 0).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Text-Objekts und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Initialisiert die Felder s34..s3e, s10..s14, i44 sowie die Fenstergrenzen s8, sa, sc und
 *   se.
 === Ende Beschreibung === */
void Text::f_05e170() {
  s34 = 0xff;
  s3e = 0;
  s32 = 0;
  s10 = 0;
  s12 = 0;
  s14 = 0;
  i44 = 1;
  s8 = 1;
  sa = 0x50;
  sc = 1;
  se = 0;
}
//@ f_05e1c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Weist dem Textausgabe-Objekt (Text) das zu verwendende Schriftobjekt p (Font*) zu.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und den Zeiger p auf das Schriftobjekt und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Speichert p im Feld this->f (+0x00), über dessen virtuelle Methoden v4 und v8 später
 *   Zeichen gezeichnet und vermessen werden.
 === Ende Beschreibung === */
void Text::f_05e1c0(Font *p) { f = p; }
//@ f_05e1d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuelle Schreibposition (s4, s6) des Textcursors auf (a, b), wobei ein
 *   Parameterwert von -1 die jeweilige Koordinate unverändert lässt.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die neuen Koordinaten a (x) und b (y) und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Aktualisiert die Felder this->s4 (x-Position, entspricht g_textline_posx in
 *   *Schicksalsklinge*) und this->s6 (y-Position, g_textline_posy).
 === Ende Beschreibung === */
void Text::f_05e1d0(short a, short b) {
  if (a != -1) s4 = a;
  if (b != -1) s6 = b;
}
//@ f_05e1f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die aktuelle x-Schreibposition (s4) des Textausgabe-Objekts zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt this->s4 als short zurück.
 * - Wichtige Variablen: Liest das Feld this->s4 (+0x04).
 === Ende Beschreibung === */
short Text::f_05e1f0() { return s4; }
//@ f_05e200
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die aktuelle y-Schreibposition (s6) des Textausgabe-Objekts zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt this->s6 als short zurück.
 * - Wichtige Variablen: Liest das Feld this->s6 (+0x06).
 === Ende Beschreibung === */
short Text::f_05e200() { return s6; }
//@ f_05e210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereitet den Text s über f_05e490 auf (Platzhalter einsetzen) und berechnet die Pixelbreite
 *   der breitesten durch '@' getrennten Teilzeile in der aktuellen Schrift this->f.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den String s und gibt die größte gemessene
 *   Zeilenbreite in Pixeln als short zurück.
 * - Wichtige Variablen: Summiert für jedes Zeichen die über this->f->v8(c) abgefragte Zeichenbreite in w und
 *   merkt das Maximum in best.
 === Ende Beschreibung === */
short Text::f_05e210(char *s) {
  short best = 0;
  short w = 0;
  unsigned char *p = (unsigned char *)f_05e490(s);
  unsigned char c;
  for (;;) {
    c = *p++;
    if (c == (signed char)0) break;
    w += (int)f->v8(c);
    if (c == '@') {
      if ((short)w > (short)best) best = w;
      w = 0;
    }
  }
  if ((short)w > (short)best) best = w;
  return best;
}
//@ f_05e270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereitet den Text s über f_05e490 auf und liefert die gesamte Pixelbreite des Strings als
 *   Summe aller Zeichenbreiten (Schwesterfunktion GUI_get_space_for_string in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den String s und gibt dessen Pixelbreite als
 *   short zurück.
 * - Wichtige Variablen: Ruft für jedes Zeichen bis zum Nullbyte die virtuelle Breitenmethode this->f->v8(c) auf.
 === Ende Beschreibung === */
short Text::f_05e270(char *s) {
  unsigned char *p = (unsigned char *)f_05e490(s);
  unsigned char c;
  short w = 0;
  for (;;) {
    c = *p++;
    if (c == 0) break;
    w += (unsigned short)f->v8(c);
  }
  return w;
}
//@ f_05e2a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die vier aktuellen Einstellungen des Textfensters aus: den linken Rand (s8), die
 *   maximale Zeilenbreite (sa), den oberen Rand (sc) und den Zentrierschalter (se).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt sowie vier short-Ausgabezeiger a, b, c, d und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Dient zum Sichern des Textfensters auf dem Stack, bevor eine Funktion vorübergehend
 *   eigene Fenstergrenzen über f_05e2d0 setzt.
 === Ende Beschreibung === */
void Text::f_05e2a0(short *a, short *b, short *c, short *d) {
  *a = s8;
  *b = sa;
  *c = sc;
  *d = se;
}
//@ f_05e2d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Parameter des Textfensters: den linken Rand s8 (samt x-Position s4), die maximale
 *   Zeilenbreite sa, den oberen Rand sc (samt y-Position s6) und den Zentrierschalter se, wobei -1 den
 *   jeweiligen Wert unverändert lässt.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt sowie die vier short-Werte a (links), b (Breite),
 *   c (oben) und d (zentriert) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Entspricht dem Setzen von g_textline_posx, g_textline_maxlen, g_textline_posy und
 *   g_gui_text_centered in *Schicksalsklinge*.
 === Ende Beschreibung === */
void Text::f_05e2d0(short a, short b, short c, short d) {
  if (a != -1) { s4 = a; s8 = a; }
  if (b != -1) sa = b;
  if (c != -1) { s6 = c; sc = c; }
  if (d != -1) se = d;
}
//@ f_05e320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sichert die bisherige Vorder- und Hintergrundfarbe in s26/s24 und setzt die aktive
 *   Vordergrundfarbe s34 auf a sowie die Hintergrundfarbe s32 auf b (-1 = transparenter Hintergrund;
 *   Schwesterfunktion set_textcolor in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, die Vordergrundfarbe a und die Hintergrundfarbe b
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verändert this->s34 (Grundfarbe) und this->s32 (Hintergrundfarbe) nach Sicherung in
 *   this->s26 und this->s24.
 === Ende Beschreibung === */
void Text::f_05e320(short a, short b) {
  s24 = s32;
  s26 = s34;
  s32 = b;
  s34 = a;
}
//@ f_05e340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die vor dem letzten Aufruf von f_05e320 in s26 und s24 gesicherte Vorder- und
 *   Hintergrundfarbe wieder her.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Kopiert this->s26 zurück nach this->s34 und this->s24 zurück nach this->s32.
 === Ende Beschreibung === */
void Text::f_05e340() {
  s34 = s26;
  s32 = s24;
}
//@ f_05e360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuell eingestellte Vordergrundfarbe (s34) und Hintergrundfarbe (s32) aus
 *   (Schwesterfunktion get_textcolor in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt sowie zwei short-Ausgabezeiger a (Vordergrund) und
 *   b (Hintergrund) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt this->s34 nach *a und this->s32 nach *b.
 === Ende Beschreibung === */
void Text::f_05e360(short *a, short *b) {
  *a = s34;
  *b = s32;
}
//@ f_05e380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sichert die fünf Vordergrundfarben s34..s3c (10 Bytes) in das Pufferfeld b28 und belegt sie
 *   neu mit der Grundfarbe a sowie den vier Hervorhebungsfarben b, c, d, e für die Textsteuercodes 0xF1..0xF4.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und die fünf Farbindizes a..e als short und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array this->b28[10] sichert die 5 Farb-Shorts s34, s36, s38, s3a, s3c.
 === Ende Beschreibung === */
void Text::f_05e380(short a, short b, short c, short d, short e) {
  memcpy(b28, &s34, 10);
  s34 = a;
  s38 = c;
  s36 = b;
  s3a = d;
  s3c = e;
}
//@ f_05e3d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die zuvor mit f_05e380 in b28 gesicherten fünf Textfarben s34..s3c wieder her.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Kopiert die 10 Bytes aus this->b28 zurück ab &this->s34.
 === Ende Beschreibung === */
void Text::f_05e3d0() {
  memcpy(&s34, b28, 10);
}
//@ f_05e400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Textschalter i40 (der im Text auch durch die Steuercodes 0xF5 ein- und 0xF0
 *   ausgeschaltet wird) auf den Wert a.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den Schalterwert a und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Schreibt das Feld this->i40 (+0x40).
 === Ende Beschreibung === */
void Text::f_05e400(int a) { i40 = a; }
//@ f_05e410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den aktuellen Wert des Textschalters i40 ab.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt this->i40 als int zurück.
 * - Wichtige Variablen: Liest das Feld this->i40 (+0x40).
 === Ende Beschreibung === */
int Text::f_05e410() { return i40; }
//@ f_05e420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen Zeilenabstand s10 (in Pixeln) aus und setzt ihn bei a != -1 auf den neuen
 *   Wert a.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den neuen Zeilenabstand a (oder -1 zum bloßen
 *   Abfragen) und gibt den bisherigen Zeilenabstand als short zurück.
 * - Wichtige Variablen: Das Feld this->s10 (+0x10) bestimmt den vertikalen Zeilenvorschub beim Textdruck
 *   (f_05e860) und im Editor (f_061b10).
 === Ende Beschreibung === */
short Text::f_05e420(short a) {
  short old = s10;
  if (a != -1) s10 = a;
  return old;
}
//@ f_05e440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereitet den Text s auf (f_05e490), bricht ihn auf die Fensterbreite um (f_05e610), gibt ihn
 *   am linken Fensterrand s8 und der aktuellen vertikalen Position s6 aus (f_05e860) und rückt s6 anschließend
 *   um Zeilenzahl * Zeilenabstand nach unten weiter.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den auszugebenden String s und gibt die Anzahl
 *   der gedruckten Zeilen als short zurück.
 * - Wichtige Variablen: Aktualisiert die vertikale Schreibposition this->s6 anhand der gedruckten Zeilenzahl r
 *   und des Zeilenabstands this->s10.
 === Ende Beschreibung === */
short Text::f_05e440(char *s) {
  char *t = f_05e490(s);
  short r = f_05e610(t);
  f_05e860(t, s8, s6);
  s6 = s6 + (short)r * s10;
  return r;
}
//@ f_05e490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen Rohtext p in den globalen 1500-Byte-Arbeitspuffer d_1bcad4 und ersetzt dabei
 *   alle 4-Byte-Platzhaltersequenzen (0x1b gefolgt von 3 Steuerbytes) über den Textcode-Dekoder d_1c0c48
 *   (f_125550/f_125500) durch Namen oder Zahlen; falls die eingesetzten Texte selbst wieder Platzhalter
 *   enthalten, wird über den Zweitpuffer d_1bd0b0 rekursiv weiterersetzt. Ist die automatische Großschreibung
 *   (i44 == 1) aktiv, wandelt die Funktion zuvor das erste Zeichen (bzw. nach einem Farbcode 0xF0..0xF5 das
 *   zweite Zeichen) über f_145400 in einen Großbuchstaben um.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den Quellstring p und gibt den Zeiger auf den
 *   aufbereiteten Text in d_1bcad4 zurück (oder p selbst, falls p bereits im Pufferbereich d_1bcad4..d_1bd68b
 *   liegt).
 * - Wichtige Variablen: Ein Originalbefund ist, dass die Großschreibung am Textanfang (p[1] = f_145400(p[1])
 *   bzw. *s = f_145400(c)) direkt in den vom Aufrufer übergebenen Quellstring p zurückschreibt statt nur in den
 *   Ausgabepuffer d_1bcad4.
 === Ende Beschreibung === */
char *Text::f_05e490(char *p) {
  if (p >= d_1bcad4 && p <= d_1bd68b) return p;
start:
  char *out = d_1bcad4;
  char *s = p;
  short i = 0;
  unsigned char c = *s;
  if (i44 == 1) {
    if (c == 0xf1 || c == 0xf2 || c == 0xf3 || c == 0xf4 || c == 0xf5 || c == 0xf0)
      p[1] = f_145400((unsigned char)p[1]);
    else
      *s = f_145400(c);
  }
read:
  if (f_1254e0(d_1c0c48) == 1) {
    c = f_125500(d_1c0c48);
  } else {
    c = s[i];
    if (c == 0) goto finish;
    while (c == 0x1b) {
      i++;
      signed char a = s[i++];
      signed char b = s[i++];
      signed char d = s[i++];
      f_125550(d_1c0c48, a, b, d);
      c = f_125500(d_1c0c48);
      i--;
      if (c == 0) c = s[++i];
    }
  }
  if (c == 0) goto finish;
  *out++ = c;
  if (f_1254e0(d_1c0c48) == 0) i++;
  goto read;
finish:
  *out = 0;
  if (strchr(d_1bcad4, 0x1b)) {
    p = d_1bd0b0;
    memcpy(d_1bd0b0, d_1bcad4, out - d_1bcad4 + 1);
    goto start;
  }
  return d_1bcad4;
}
//@ f_05e610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereitet den Text s über f_05e490 auf, wandelt vorhandene CR/LF-Zeichen in Leerzeichen um und
 *   fügt an den Wortgrenzen (letztes Leerzeichen vor Überschreiten der Zeilenbreite sa) Zeilenumbrüche ('\r')
 *   ein, wobei erzwungene Umbrüche ('@') sowie eine eventuelle Erstzeilen-Einrückung (s12 Pixel für s14 Zeilen)
 *   berücksichtigt werden (Schwesterfunktion GUI_count_lines in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den Textzeiger s und gibt die Gesamtzahl der
 *   umbrochenen Zeilen (lines + 1) als short zurück.
 * - Wichtige Variablen: Verändert die Zeichen im Puffer d_1bcad4 in-place (setzt '\r' an Umbruchstellen) und
 *   stellt die vorübergehend um s12 verringerte Zeilenbreite this->sa am Ende wieder her.
 === Ende Beschreibung === */
short Text::f_05e610(char *s) {
  short lines = 0;
  signed char *t = (signed char *)f_05e490(s);
  signed char *p = t;
  unsigned char c;
  int ch;
  int brk;
  short old, line, w, space, i;

  while ((ch = *p) != 0) {
    if (ch == '\r' || ch == '\n') *p = ' ';
    p++;
  }
  p = t;
  i = space = line = 0;
  old = sa;
  if (s12) sa = sa - s12;
  { short j; w = j ^ j; } // Haelt die Registerwahl fuer w wie im Original
  w = 0;
  while ((c = p[i]) != 0) {
    if (c == 0) break;
    w = w + f->v8(c);
    if (p[i] == ' ') space = i;
    if (p[i] == '@') {
      p += i + 1;
      i = -1;
      line = space = w = 0;
      lines++;
      if (lines == s14) sa = sa + s12;
    }
    if (w >= sa) {
      brk = 1;
      if (space != line) {
        p[space] = '\r';
        p += space;
      }
      if (brk == 1) {
        lines++;
        if (lines == s14) sa = sa + s12;
        line = i = space = w = 0;
      }
    }
    i++;
  }
  if (w >= sa && line != space) {
    p[space] = '\r';
    lines++;
    if (lines == s14) sa = sa + s12;
  }
  sa = old;
  return lines + 1;
}

//@ f_05e770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die horizontale Startkoordinate x, ab der die erste Zeile des Textes s (bis zum
 *   ersten Nullbyte, '@', '\r' oder '\n') innerhalb eines Bereichs ab linkem Rand a mit Breite b zentriert
 *   dargestellt wird (Schwesterfunktion GUI_get_first_pos_centered in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, den Text s, den linken Rand a und die verfügbare
 *   Breite b und gibt die berechnete x-Koordinate a + (b - w) / 2 als short zurück.
 * - Wichtige Variablen: Summiert die Zeichenbreiten this->f->v8(c) der ersten Zeile in der lokalen Variablen w.
 === Ende Beschreibung === */
short Text::f_05e770(char *s, short a, short b) {
  unsigned char *p = (unsigned char *)f_05e490(s);
  unsigned char c;
  short w = 0;
  for (;;) {
    c = *p++;
    if (c == 0 || c == '@' || c == '\r' || c == '\n') break;
    w += (unsigned short)f->v8(c);
  }
  b = b - w;
  b /= 2;
  b = b + a;
  return b;
}
//@ f_05e7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Einrückungsbreite s12 (in Pixeln) und die Anzahl der einzurückenden Zeilen s14 (z.
 *   B. neben einem Charakterporträt oder Icon in Dialogfenstern; -1 lässt den jeweiligen Wert unverändert).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, die Einrückungsbreite a und die Zeilenanzahl b
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Entspricht g_dialogbox_indent_width (s12) und g_dialogbox_indent_height (s14) in
 *   *Schicksalsklinge*.
 === Ende Beschreibung === */
void Text::f_05e7e0(short a, short b) {
  if (a != -1) s12 = a;
  if (b != -1) s14 = b;
}
//@ f_05e800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuell eingestellte Einrückungsbreite (s12) und die Anzahl einzurückender Zeilen
 *   (s14) aus.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt sowie zwei short-Ausgabezeiger a und b und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt this->s12 nach *a und this->s14 nach *b.
 === Ende Beschreibung === */
void Text::f_05e800(short *a, short *b) {
  *a = s12;
  *b = s14;
}
//@ f_05e820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die gespeicherte x-Koordinate des Tabulatorstopps mit Index i (0..6).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den Tabulatorindex i und gibt die
 *   Tabulatorposition v16[i] als short zurück.
 * - Wichtige Variablen: Liest aus dem Array this->v16[7] (entspricht g_txt_tabpos in *Schicksalsklinge*).
 === Ende Beschreibung === */
short Text::f_05e820(short i) { return v16[i]; }
//@ f_05e830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Tabulatorstopp mit Index i (0..6) auf die x-Koordinate v.
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, die x-Position v und den Tabulatorindex i und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt in das Array this->v16[i].
 === Ende Beschreibung === */
void Text::f_05e830(short v, short i) { v16[i] = v; }
//@ f_05e840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet die automatische Großschreibung am Text- und Satzanfang (i44) ein (a == 1) oder aus
 *   (a == 0).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt und den Schalterwert a und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Schreibt das Feld this->i44 (+0x44).
 === Ende Beschreibung === */
void Text::f_05e840(int a) { i44 = a; }
//@ f_05e850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert den aktuellen Zustand der automatischen Satzanfang-Großschreibung (i44).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt this->i44 als int zurück.
 * - Wichtige Variablen: Liest das Feld this->i44 (+0x44).
 === Ende Beschreibung === */
int Text::f_05e850() { return i44; }
//@ f_05e860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hauptfunktion der Textausgabe: bereitet den Text s auf (f_05e490), bricht ihn auf Zeilenbreite
 *   um (f_05e610) und zeichnet ihn ab (x, y) Zeichen für Zeichen über die aktuelle Schrift this->f->v4, wobei
 *   Zeilenumbrüche ('\r', '\n', '@'), Zentrierung (se), Einrückung (s12/s14), Tabulatoren ('~'), Farb- und
 *   Schaltercodes (0xF0..0xF7), geschützte Leerzeichen ('^') sowie die Großschreibung nach Satzendezeichen ('.',
 *   '!', '?' bei i44 == 1) ausgewertet werden (Schwesterfunktion GUI_print_string in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, den auszugebenden String s sowie die
 *   Startkoordinaten x und y und gibt die Anzahl der ausgegebenen Zeilen (lines + 1) als short zurück.
 * - Wichtige Variablen: Das Feld this->s3e wählt den aktuellen Farbindex (0..4) innerhalb der Farbtabelle
 *   s34..s3c, und first merkt, ob nach einem Satzende das nächste druckbare Zeichen großgeschrieben werden soll.
 === Ende Beschreibung === */
short Text::f_05e860(char *s, short x, short y) {
  struct FirstCenter {
    static inline short run(Text *self, char *s, short a, short b) {
      unsigned char *p = (unsigned char *)self->f_05e490(s);
      unsigned char c;
      short w = 0; 
      { unsigned char alias_p11 = (unsigned char)(unsigned int)p; (void)alias_p11; } // Steuert die Register- und Stapelsortierung
      for (;;) {
        c = *p++;
        if (c == 0 || c == '@' || c == '\r' || c == '\n') break;
        Font *font = self->f;
        { unsigned short alias_font2 = (unsigned short)(unsigned int)font; (void)alias_font2; } // Steuert die Registerwahl
        unsigned short wide = font->v8(c); w += wide;
      }
      { unsigned char alias_w11 = (unsigned char)(unsigned int)w; (void)alias_w11; } // Steuert die Registerwahl
      b = b - w;
      b /= 2;
      b = b + a;
      return b;
    }
  };
  struct NextCenter {
    static inline short run(Text *self, char *s, short a, short b) {
      unsigned char *p = (unsigned char *)self->f_05e490(s);
      unsigned char c;
      short w = 0; 
      for (;;) {
        c = *p++;
        if (c == 0 || c == '@' || c == '\r' || c == '\n') break;
        Font *font = self->f;
        { unsigned char alias_font1 = (unsigned char)(unsigned int)font; (void)alias_font1; } // Steuert die Registerwahl
        { unsigned short alias_font2 = (unsigned short)(unsigned int)font; (void)alias_font2; } // Steuert die Registerwahl
        unsigned short wide = font->v8(c); w += wide;
      }
      b = b - w;
      b /= 2;
      b = b + a;
      return b;
    }
  };

  short lines; unsigned char c; char *t; short lx; short idx; short result; short first; 
  lines = 0; lines = 0; lines = 0; 
  idx = 0; idx = 0; 
  first = 1; first = 1; first = 1; first = 1; first = 1; first = 1; 
  t = f_05e490(s);
  f_05e610(t);
  if (se == 1) x = FirstCenter::run(this, t, x, sa);
  else if (s12) x += s12;
  lx = x;
  for (;;) {
    y = (y & 0) ? (short)0 : y; // Haelt y am Schleifenkopf
    int off = idx++;
    off += (int)t;
    c = *(unsigned char *)off;
    if (!c) break;
    if (c == '\r' || c == '\n' || c == '@') {
      if (++lines == s14) lx = (*&lx) - s12;
      y = y + s10;
      x = se == 1 ? NextCenter::run(this, t + idx, s8, sa) : lx;
    } else if (c == '~') {
      if (x < v16[0]) x = v16[0];
      else if (x < v16[1]) x = v16[1];
      else if (x < v16[2]) x = v16[2];
      else if (x < v16[3]) x = v16[3];
      else if (x < v16[4]) x = v16[4];
      else if (x < v16[5]) x = v16[5];
      else if (x < v16[6]) x = v16[6];
    } else if (c == 0xf1 || c == 0xf2 || c == 0xf3 || c == 0xf4) {
      s3e = c - 0xf0;
    } else if (c == 0xf5) {
      i40 = 1;
    } else if (c == 0xf0) {
      i40 = 0;
      s3e = 0;
    } else if (c == 0xf6) {
      first = 1;
    } else if (c == 0xf7) {
      first = 0;
    } else {
      if (c == '^') c = ' ';
      if (first && i44 == 1) {
        if (c >= 0x21 && c != '@' && c != '.' && c != '!' && c != '?' && c != '<' && c != ':' && c <= 0xf0) {
          first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; first = 0; 
          c = f_145400(c);
        }
      } else if (c == '.' || c == '!' || c == '?') {
        first = 1;
      }
      x = x + f->v4(c, x, y, (int)((char *)&s34 + s3e * 2 - 2), s32);
    }
  }
  { unsigned char alias_t1 = (unsigned char)(unsigned int)t; (void)alias_t1; } // Steuert die Register- und Stapelsortierung
  { unsigned short alias_this2 = (unsigned short)(unsigned int)this; (void)alias_this2; } // Steuert die Register- und Stapelsortierung
  result = lines + 1;
  return result;
}
//@ f_05ebd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein einzelnes Zeichen ch an der Pixelposition (x, y) aus, wobei die Farb- und
 *   Schaltercodes 0xF0..0xF5 nur den Zustand (s3e, i40) umschalten (Breite 0) und '^' als Leerzeichen ' '
 *   gedruckt wird (Schwesterfunktion GUI_print_char in *Schicksalsklinge*).
 * - Eingaben und Rückgabe: Die Methode erhält das Text-Objekt, das Zeichen ch sowie die Koordinaten x und y und
 *   gibt die gezeichnete Zeichenbreite (Vorschub in Pixeln) als short zurück.
 * - Wichtige Variablen: Ruft this->f->v4((unsigned char)ch, x, y, (int)((char *)&s34 + s3e * 2 - 2), s32) auf.
 === Ende Beschreibung === */
short Text::f_05ebd0(signed char ch, short x, short y) {
  short r = 0;
  if (ch == 0xf1 || ch == 0xf2 || ch == 0xf3 || ch == 0xf4) {
    s3e = ch - 0xf0;
  } else if (ch == 0xf5) {
    i40 = 1;
  } else if (ch == 0xf0) {
    i40 = 0;
    s3e = r;
  } else {
    if ((unsigned char)ch == (unsigned char)'^') ch = ' ';
    r = f->v4((unsigned char)ch, x, y, (int)((char *)&s34 + s3e * 2 - 2), s32);
  }
  return r;
}
