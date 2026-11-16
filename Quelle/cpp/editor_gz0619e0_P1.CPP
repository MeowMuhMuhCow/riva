/* === Beschreibung (Katalog) ===
 * Einheit editor_gz0619e0 (0x061080 - 0x061b10)
 *
 * Überblick
 * Diese Einheit enthält den ersten Hauptteil von editor.cpp (einschließlich des Grenzstücks gz_0619e0): den
 * automatischen Fließtext-Zeilenumbruch, das vollständige und zeilenweise Neuzeichnen des Editorfelds, das Ein-
 * und Ausblenden des inversen Textcursors, das Teilen und Zusammenführen von Zeilen bei Eingabetaste und
 * Rückschritt am Zeilenanfang sowie das Laden eines vorhandenen Textes in den Editor.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 5/9 gleich (suche.py 29.10.2026, Basis editor_gz0619e0_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// editor.cpp - Pass 1
#include <string.h>
extern int d_1a34e0;
extern unsigned short d_1bdbd4;
extern unsigned short d_1bdbd6;
extern unsigned short d_1bdbd8;
extern unsigned short d_1bdbda;
extern int d_1c3078;
extern int d_1c38b0;
extern const char d_1a19a4[];
#define SH(o) (*(short *)(p1 + (o)))
#define IN(o) (*(int *)(p1 + (o)))
unsigned char f_045db0(void *p1, int p2);
int f_05e320(void *p1, int p2, int p3);
int f_05e840(void *p1, int p2);
int f_05e850(void *p1);
int f_05ebd0(void *p1, int p2, int p3, int p4);
void f_060fd0(char *p1, char *p2, char *p3, int p4);
short f_061f10(char *p1, char *p2);
short f_061f40(char *p1, char *p2);
short f_061f60(char *p1, char *p2);
int f_061fa0(char *p1);
int f_061fd0(char *p1);
int f_0625e0(char *p1);
int f_099f70(int p1, int p2, int p3, int p4);
int f_099fa0(void *p1);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0e9660(void *p1, int p2, int p3, int p4);

int f_1483f0(int p1, int p2, int p3, int p4, int p5);
int f_061080(char *p1, short p2);
void f_061350(char *p1);
void f_0614d0(char *p1);
void f_061590(char *p1);
void f_0616f0(char *p1);
void f_0617f0(char *p1);
void f_061880(char *p1);

//@ f_061080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ab der Zeile p2 den automatischen Wortumbruch über alle Zeilen des Editors p1 aus:
 *   solange eine Zeile breiter als die nutzbare Editorbreite (w, Offset +2) ist, wird der Überhang ab dem
 *   letzten Leerzeichen (f_061f10, oder bei überlangen Wörtern ab der Breitengrenze f_061f60) abgeschnitten und
 *   über f_060fd0 vor den Anfang der nächsten Zeile geschoben; in der allerletzten Zeile (n - 1) wird
 *   stattdessen das letzte Zeichen verworfen. Steht der Cursor im umgebrochenen Teil, wandert er automatisch an
 *   die entsprechende Stelle der nächsten Zeile mit.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und den Startzeilenindex p2.
 *   Sie gibt 1 zurück, wenn der Cursor an seiner Stelle geblieben ist (sodass der Aufrufer ihn nach dem Einfügen
 *   um ein Zeichen weiterrücken kann), oder 0, wenn der Umbruch den Cursor bereits versetzt hat bzw. das
 *   getippte Zeichen am Textende abgeschnitten wurde.
 * - Wichtige Variablen: Ein temporärer Puffer frame.buffer der Größe bsz nimmt das abgetrennte Wortstück beim
 *   Übertragen in die Folgezeile lines[p2 + 1] auf.
 === Ende Beschreibung === */
int f_061080(char *p1, short p2)
{
    struct Editor1090 {
        short n, w, bsz, x0, y0, lh, s0c, s0e;
        short row, col;
        int changed, cursorchanged, f1c, f20;
        short cx, cy;
        int f28, f2c, f30;
        unsigned char **lines;
        short width(unsigned char *s) {
            short result = 0;
            while (*s) {
                result += f_045db0(&d_1c3078, *s);
                ++s;
            }
            return result;
        }
    };

            struct TextFrame1090 { int blank; unsigned char *text; unsigned char *buffer; } frame;
            short len, cut, distance;
            signed char saved;
            int result = 1;
            frame.buffer = new (mark(d_1a19a4, 0x12f)) unsigned char[((Editor1090 *)p1)->bsz];
            while (p2 < ((Editor1090 *)p1)->n) {
                frame.text = ((Editor1090 *)p1)->lines[p2];
                while (((Editor1090 *)p1)->width(frame.text) > ((Editor1090 *)p1)->w) {
                    if (p2 >= ((Editor1090 *)p1)->n - 1) {
                        if (((Editor1090 *)p1)->row == p2) {
                            int cursor = ((Editor1090 *)p1)->col;
                            if (cursor == (int)strlen((char *)frame.text) - 1) result = 0;
                            ((Editor1090 *)p1)->cursorchanged = 1;
                        } else ((Editor1090 *)p1)->changed = 1;
                        frame.text[strlen((char *)frame.text) - 1] = 0;
                    } else {
                        frame.blank = 0;
                        len = strlen((char *)frame.text);
                        cut = f_061f10(p1, (char *)frame.text);
                        if (cut) {
                            strcpy((char *)frame.buffer, (char *)frame.text + cut + 1);
                            frame.blank = 1;
                        } else {
                            cut = f_061f60(p1, (char *)frame.text);
                            strcpy((char *)frame.buffer, (char *)frame.text + cut);
                        }
                        if (p2 == ((Editor1090 *)p1)->row) saved = frame.text[((Editor1090 *)p1)->col];
                        memset(frame.text + cut, 0, ((Editor1090 *)p1)->bsz - cut);
                        f_060fd0(p1, (char *)((Editor1090 *)p1)->lines[p2 + 1], (char *)frame.buffer, frame.blank);
                        if (p2 == ((Editor1090 *)p1)->row) {
                            if (cut == ((Editor1090 *)p1)->col && saved == ' ' && cut != len - 1) {
                                frame.text[((Editor1090 *)p1)->col] = saved;
                            } else if (cut <= ((Editor1090 *)p1)->col) {
                                result = 0;
                                f_061fa0(p1);
                                distance = ((Editor1090 *)p1)->col - cut;
                                if (!frame.blank) ++distance;
                                unsigned char *nextline = ((Editor1090 *)p1)->lines[p2 + 1];
                                ((Editor1090 *)p1)->col = 0;
                                ((Editor1090 *)p1)->cx = ((Editor1090 *)p1)->x0;
                                while (((Editor1090 *)p1)->col < distance) {
                                    ((Editor1090 *)p1)->cx += f_045db0(&d_1c3078, nextline[((Editor1090 *)p1)->col]);
                                    ++((Editor1090 *)p1)->col;
                                }
                            }
                        }
                        ((Editor1090 *)p1)->changed = 1;
                    }
                }
                int font_copy = d_1c3078; d_1c3078 = font_copy; // Codeloser Registerlisten-Knoten
                ++p2;
            }
            delete frame.buffer;
            return result;
}

//@ f_061350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet sämtliche Zeilen des Editors p1 komplett neu: füllt zuerst alle Zeilenpuffer hinter
 *   ihrem ersten Nullbyte sauber mit Nullen auf, verbirgt Mauszeiger und Textcursor (f_0616f0), stellt für jede
 *   Zeile entweder den Ausschnitt des Hintergrundbilds (+0x28) wieder her oder füllt die Zeilenhöhe mit
 *   waagrechten Linien in der Hintergrundfarbe (+0x0e), gibt den Zeilentext über f_0e9660 aus und blendet den
 *   Textcursor (f_061590) wieder ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Löscht am Ende den Merker IN(0x14) ("alles neu zeichnen") im Editor-Objekt.
 === Ende Beschreibung === */
void f_061350(char *p1)
{
  struct MG {
    int flag;
    MG() { if (f_0d3860() == 1) { f_0d2710(); flag = 1; } else flag = 0; }
    ~MG() { if (flag == 1) f_0d26e0(); }
  };
  struct Prep {
    void run() {
      char *p1 = (char *)this;
      short i;
      short j;
      short zero;
      char *line;
      for (i = 0; i < SH(0); i++) {
        line = (*(char ***)(p1 + 0x34))[i];
        zero = 0;
        for (j = 0; j < SH(4); j++) {
          if (*(signed char *)(line + j) == (signed char)0) zero = 1;
          if (zero != (short)0) line[j] = 0;
        }
      }
    }
  };
  struct EditorLines { char pad[0x34]; int *lines; };
  unsigned short y;
  short row;
  short glyph;

  ((Prep *)p1)->run();
  MG mg;
  f_0616f0(p1);
  y = 0;
  for (row = 0; row < SH(0); row++, y += SH(10)) {
    short t_163 = IN(0x28);
    if (IN(0x28) != 0) {
      ((RivaRasterImage*)(IN(0x28)))->f_0fade0((void *)( IN(0x2c)), SH(6), (short)(SH(8) + y));
    } else {
      for (glyph = 0; glyph < SH(10); glyph++) {
        f_1483f0(IN(0x2c), SH(6), (short)(SH(8) + y + glyph), SH(2), (signed char)SH(0xe));
      }
    }
    f_0e9660(&d_1c38b0, ((EditorLines *)p1)->lines[row], SH(6), (short)(SH(8) + y));
  }
  f_061590(p1);
  IN(0x14) = 0;
}

//@ f_061590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht den verschachtelbaren Sichtbarkeitszähler (+0x20) des Textcursors um 1 und zeichnet,
 *   sobald der Zähler 0 erreicht, das Zeichen unter dem Cursor (bzw. ein Leerzeichen am Zeilenende) in
 *   vertauschter Vorder- und Hintergrundfarbe an die Pixelposition (cx, cy) (+0x24/+0x26). Zeichen und Position
 *   werden in +0x40..+0x44 gesichert, damit f_0616f0 den Cursor später wieder sauber löschen kann.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Felder saved_character (+0x40), saved_x (+0x41) und saved_y (+0x43) speichern das
 *   übermalte Zeichen und dessen Pixelkoordinaten.
 === Ende Beschreibung === */
void f_061590(char *p1)
{
  struct Editor {
    short f00, f02, f04, pitch, f08, f0a, color1, color2;
    short row, column;
    int changed, cursor_changed, f1c, nesting;
    short x, y;
    int background, background_data, f30;
    signed char **lines;
    char f38[8];
    signed char saved_character;
    short saved_x, saved_y;
  };
  struct Frame { unsigned short region[4]; int hidden; signed char character; } frame;

  ++((Editor *)p1)->nesting;
  if (((Editor *)p1)->nesting != 0) return;
  int row = ((Editor *)p1)->row;
  int table_base = (row & 0) ? 0 : (int)((Editor *)p1)->lines; // Codelose Webgrenze fuer die Registerfolge
  int offset = row * 4;
  offset += table_base;
  signed char **entry = (signed char **)offset;
  frame.character = (*entry)[((Editor *)p1)->column];
  if (frame.character == 0) frame.character = ' ';
  f_05e320(&d_1c38b0, ((Editor *)p1)->color2, ((Editor *)p1)->color1);
  if (f_0d3860() == 1) {
    f_0d2710();
    frame.hidden = 1;
  } else {
    frame.hidden = 0;
  }
  if (((Editor *)p1)->background) {
    frame.region[0] = d_1bdbd4;
    frame.region[1] = d_1bdbd6;
    frame.region[2] = d_1bdbd8;
    frame.region[3] = d_1bdbda;
    int bottom = d_1bdbda;
    unsigned char width = f_045db0(&d_1c3078, (unsigned char)frame.character);
    f_099f70((unsigned short)((Editor *)p1)->x, d_1bdbd6,
             (unsigned short)(width + ((Editor *)p1)->x - 1), bottom);
    ((RivaRasterImage*)(((Editor *)p1)->background))->f_0fade0((void *)( ((Editor *)p1)->background_data), ((Editor *)p1)->pitch, ((Editor *)p1)->y);
    f_099fa0(frame.region);
  }
  f_05ebd0(&d_1c38b0, frame.character, ((Editor *)p1)->x, ((Editor *)p1)->y);
  if (frame.hidden == 1) f_0d26e0();
  if (((Editor *)p1)->background) f_05e320(&d_1c38b0, ((Editor *)p1)->color1, -1);
  else f_05e320(&d_1c38b0, ((Editor *)p1)->color1, ((Editor *)p1)->color2);
  ((Editor *)p1)->saved_character = frame.character;
  ((Editor *)p1)->saved_x = ((Editor *)p1)->x;
  ((Editor *)p1)->saved_y = ((Editor *)p1)->y;
}

//@ f_0617f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Eingabetaste (Return) im Editor: schiebt den Text rechts vom Cursor über
 *   f_060fd0 an den Anfang der nächsten Zeile, bricht ab der Folgezeile neu um (f_061080), schneidet die
 *   aktuelle Zeile an der Cursorspalte ab (wobei ein unmittelbar davorstehendes Leerzeichen ebenfalls entfernt
 *   wird) und setzt den Cursor an den Anfang der nächsten Zeile.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Setzt am Ende den Merker IN(0x14) = 1, damit die Hauptschleife alle Zeilen neu zeichnet.
 === Ende Beschreibung === */
void f_0617f0(char *p1)
{
  char *line;
  char **lines;

  int idx = SH(0x10);
  int off = idx * 4;
  int base = IN(0x34);
  off += base;
  lines = (char **)off;
  line = *lines;
  if (SH(0x10) + 1 < SH(0)) {
    f_060fd0(p1, lines[1], line + SH(0x12), 1);
    f_061080(p1, (short)(SH(0x10) + 1));
  }
  line[SH(0x12)] = 0;
  if (*(signed char *)(line + SH(0x12) - 1) == ' ') {
    line[SH(0x12) - 1] = 0;
  }
  f_0616f0(p1);
  SH(0x24) = SH(6);
  f_061fa0(p1);
  SH(0x12) = 0;
  f_061590(p1);
  IN(0x14) = 1;
}

//@ f_061880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Rückschritt-Taste (Backspace), wenn der Cursor ganz am Zeilenanfang (Spalte 0)
 *   einer Zeile > 0 steht: holt das erste Wort der aktuellen Zeile (f_061f40), hängt es (gegebenenfalls mit
 *   Leerzeichen) an das Ende der vorherigen Zeile an, entfernt es aus der aktuellen Zeile, führt ab der
 *   vorherigen Zeile einen Neuumbruch (f_061080) durch und setzt den Cursor an das alte Ende der vorherigen
 *   Zeile.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Berechnet die alte Pixelbreite der vorherigen Zeile prev in w.full, um die neue
 *   x-Koordinate des Cursors (SH(0x24) = SH(6) + saved_w) exakt zu positionieren.
 === Ende Beschreibung === */
unsigned char fontcall_061880(void *p1, int p2);
#pragma aux fontcall_061880 "f_045db0" parm [eax] [edx] modify exact [eax edx edi];
void f_061880(char *p1)
{
  unsigned char *prev;
  unsigned char *buf;
  short len;
  union Width1172 { int full; unsigned char bytes[4]; };
  Width1172 w; w.full = 0;
  unsigned char **pp;
  unsigned char *cur;
  unsigned char *q;
  short r = 0;

  buf = new (mark(d_1a19a4, 0x263)) unsigned char[SH(4)];
  if (SH(0x10) != (short)0) {
    memset(buf, 0, 4);
    int row = (SH(0x10) & 0) ? 0 : SH(0x10); // Zeilenindex als eigenes Web
    pp = ((unsigned char **)IN(0x34)) + row;
    prev = pp[-1];
    cur = pp[0];
    len = strlen((char *)prev);
    q = prev;
    w.full = 0;
    int w_byte1172 = (unsigned char)w.full; // Definierte Unteransicht fuer Namenssortierung
    int w_high1172 = w.bytes[1]; // Berechnete zweite Unteransicht ohne Zusatzcode
    if (*q) {
        do {
          w.full = w.full + fontcall_061880(&d_1c3078, *q);
          q++;
        } while (*q);
    }
    {
        short saved_w = w.full;
        r = f_061f40(p1, (char *)cur);
        if (*prev) {
          *buf = ' ';
          strncpy((char *)buf + 1, (char *)cur, r);
        }
        else {
          strncpy((char *)buf, (char *)cur, r);
        }
        memmove(cur, cur + r + 1, SH(4) - r - 1);
        strcat((char *)prev, (char *)buf);
        f_061080(p1, SH(0x10) - 1);
        f_0616f0(p1);
        SH(0x24) = SH(6) + saved_w;
    }
    SH(0x12) = len;
    f_061fd0(p1);
    f_061590(p1);
    IN(0x14) = 1;
  }
  delete buf;
}

extern int ed493_d_1a34e0;
#pragma aux ed493_d_1a34e0 "d_1a34e0"
extern unsigned short ed493_d_1bdbd4;
#pragma aux ed493_d_1bdbd4 "d_1bdbd4"
extern unsigned short ed493_d_1bdbd6;
#pragma aux ed493_d_1bdbd6 "d_1bdbd6"
extern unsigned short ed493_d_1bdbd8;
#pragma aux ed493_d_1bdbd8 "d_1bdbd8"
extern unsigned short ed493_d_1bdbda;
#pragma aux ed493_d_1bdbda "d_1bdbda"
extern int ed493_d_1c3078;
#pragma aux ed493_d_1c3078 "d_1c3078"
extern int ed493_d_1c38b0;
#pragma aux ed493_d_1c38b0 "d_1c38b0"
extern const char ed493_d_1a19a4[];
#pragma aux ed493_d_1a19a4 "d_1a19a4"
struct ContextEditor493 { public:
// gz_0619e0.cpp - Pass 1
#define SH(o) (*(short *)(p1 + (o)))
#define IN(o) (*(int *)(p1 + (o)))
static unsigned char f_045db0(void *p1, int p2);
static int f_05e320(void *p1, int p2, int p3);
static int f_05e840(void *p1, int p2);
static int f_05e850(void *p1);
static int f_05ebd0(void *p1, int p2, int p3, int p4);
static void f_060fd0(char *p1, char *p2, char *p3, int p4);
static short f_061f10(char *p1, char *p2);
static short f_061f40(char *p1, char *p2);
static short f_061f60(char *p1, char *p2);
static int f_061fa0(char *p1);
static int f_061fd0(char *p1);
static int f_0625e0(char *p1);
static int f_099f70(int p1, int p2, int p3, int p4);
static int f_099fa0(void *p1);
static int f_0d26e0();
static int f_0d2710();
static int f_0d3860();
static int f_0e9660(void *p1, int p2, int p3, int p4);

static int f_1483f0(int p1, int p2, int p3, int p4, int p5);
static int f_061080(char *p1, short p2);
static void f_061350(char *p1);
static void f_0614d0(char *p1);
static void f_061590(char *p1);
static void f_0616f0(char *p1);
static void f_0617f0(char *p1);
static void f_061880(char *p1);
static void f_0619e0(char *p1, char *p2);
static void f_061aa0(char *p1);
};
//@ f_0614d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet nur die aktuelle Cursorzeile (SH(0x10)) des Editors neu, indem der Zeilenhintergrund
 *   wiederhergestellt und der Zeilentext an der vertikalen Cursorposition SH(0x26) über f_0e9660 neu ausgegeben
 *   wird, und setzt anschließend den Merker IN(0x18) ("Cursorzeile neu zeichnen") auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Ein Originalfehler besteht darin, dass der Zweig ohne Hintergrundbild (IN(0x28) == 0)
 *   die Hintergrundlinien über f_1483f0 fest in den VGA-Bildschirmspeicher d_1a34e0 statt in den Zielpuffer
 *   IN(0x2c) des Editors zeichnet (anders als f_061350 und f_060ae0).
 === Ende Beschreibung === */
void f_0614d0(char *p1)
{
  volatile int flag; // Haelt das Maus-Guard-Flag auf dem Stack ohne globale Typnummern zu verschieben
  short i;
  struct EditorLines { char pad[0x34]; int *lines; };

  f_0616f0(p1);
  if (f_0d3860() == 1) {
    f_0d2710();
    flag = 1;
  }
  else {
    flag = 0;
  }
  if (IN(0x28) != 0) {
    ((RivaRasterImage*)(IN(0x28)))->f_0fade0((void *)( IN(0x2c)), SH(6), SH(0x26));
  }
  else {
    for (i = 0; i < SH(10); i++) {
      f_1483f0(*(int *)&d_1a34e0, SH(6), (short)(SH(0x26) + i), SH(2), (signed char)SH(0xe));
    }
  }
  f_0e9660(&d_1c38b0, ((EditorLines *)p1)->lines[SH(0x10)], SH(6), SH(0x26));
  if (flag == 1) {
    f_0d26e0();
  }
  f_061590(p1);
  IN(0x18) = 0;
}

//@ f_0619e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt einen vorhandenen mehrzeiligen Text p2 (mit Nullbytes, CR oder LF als Zeilentrennern, wie
 *   ihn f_060ae0 zurückschreibt) in die Zeilenpuffer des Editors p1, führt ab Zeile 0 einen Wortumbruch
 *   (f_061080) aus und zeichnet den gesamten Editorinhalt neu auf den Bildschirm (f_061350, f_0625e0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und den Quelltextpuffer p2
 *   (in dem CR/LF-Trennzeichen in-place durch Nullbytes ersetzt werden). Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schaltet während des Ladens und Zeichnens die automatische Satzanfang-Großschreibung
 *   (f_05e840) des Textausgabe-Objekts d_1c38b0 vorübergehend aus.
 === Ende Beschreibung === */
void ContextEditor493::f_0619e0(char *p1, char *p2)
{
  int old = f_05e850(&ed493_d_1c38b0);
  f_05e840(&ed493_d_1c38b0, 0);
  short i = 0;
  for (; i < SH(0); i++) {
    char *start = p2;
    while (*p2 != '\0' && (int)(signed char)*p2 != 13 && (int)(signed char)*p2 != 10) {
      p2++;
    }
    int offset = (int)i * 4;
    *p2 = '\0';
    int base = IN(0x34);
    char *dest = *(char **)(base + offset);
    strcpy(dest, start);
    p2++;
  }
  f_061080(p1, 0);
  f_0616f0(p1);
  f_061350(p1);
  f_0625e0(p1);
  f_05e840(&ed493_d_1c38b0, old);
}

//@ f_061aa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Normalisiert alle n Zeilenpuffer des Editors p1, indem in jeder Zeile sämtliche Bytes hinter
 *   dem ersten Nullbyte bis zur Puffergröße SH(4) (bsz) auf 0 gesetzt werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Durchläuft die Zeilentabelle IN(0x34) über SH(0) Zeilen und SH(4) Bytes je Zeile.
 === Ende Beschreibung === */
void ContextEditor493::f_061aa0(char *p1)
{
  short bVar2 = 0;
  short sVar4, sVar3;
  char **list;
  char *iVar1;

  for (sVar4 = 0; sVar4 < SH(0); sVar4++) {
    bVar2 = 0;
    list = (char **)IN(0x34);
    iVar1 = list[sVar4];
    for (sVar3 = 0; sVar3 < SH(4); sVar3++) {
      if (iVar1[sVar3] == '\0') bVar2 = 1;
      if ((short)bVar2) iVar1[sVar3] = 0;
    }
  }
}

//@ f_0616f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet als Gegenstück zu f_061590 den Textcursor aus: war der Cursor sichtbar (IN(0x20) ==
 *   0), wird das in +0x40 gemerkte Zeichen an der in +0x41/+0x43 gemerkten Position wieder in normalen Farben
 *   (und bei vorhandenem Hintergrundbild nach Wiederherstellung der Zeichenzelle) übermalt; anschließend wird
 *   der Sichtbarkeitszähler IN(0x20) um 1 verringert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Liest *(signed char *)(p1 + 0x40) sowie die gespeicherten Koordinaten *(short *)(p1 +
 *   0x41) und *(short *)(p1 + 0x43) und dekrementiert IN(0x20).
 === Ende Beschreibung === */
void f_0616f0(char *p1)
{
  struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    ~MG() { if (fl == 1) f_0d26e0(); }
  };
  unsigned char bVar1;
  int p4;
  unsigned short rc[4];
  signed char local_14;

  local_14 = *(signed char *)(p1 + 0x40);
  if (IN(0x20) == 0) {
    if (local_14 == 0) {
      local_14 = 0x20;
    }
    MG mg;
    if (IN(0x28) != 0) {
      rc[0] = d_1bdbd4;
      rc[1] = d_1bdbd6;
      rc[2] = d_1bdbd8;
      rc[3] = d_1bdbda;
      p4 = d_1bdbda;
      bVar1 = f_045db0(&d_1c3078, (unsigned char)local_14);
      f_099f70((unsigned short)*(short *)(p1 + 0x41), d_1bdbd6, (unsigned short)(bVar1 + *(short *)(p1 + 0x41) - 1), p4);
      ((RivaRasterImage*)(IN(0x28)))->f_0fade0((void *)( IN(0x2c)), SH(6), *(short *)(p1 + 0x43));
      f_099fa0(rc);
    }
    f_05ebd0(&d_1c38b0, local_14, *(short *)(p1 + 0x41), *(short *)(p1 + 0x43));
  }
  IN(0x20) = IN(0x20) - 1;
}

