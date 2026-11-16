/* === Beschreibung (Katalog) ===
 * Einheit gz_069970 (0x069970 - 0x06a790)
 *
 * Überblick
 * Die Einheit gz_069970 implementiert die zentrale Klasse für animierte Kampffiguren und
 * Geschoss-/Effekt-Sprites (Gz / Face, Größe 0xf4 Bytes) im isometrischen Kampfsystem von *Schatten über Riva*.
 * Sie umfasst das Laden von Animationspfaden (f_069970), die Takt- und Phasensteuerung (f_069b10), das Zeichnen
 * eines Sprites inklusive Schattenwurf, Clipping-Boxen und Aktions-Triggern (f_069c10, f_06a240) sowie
 * zahlreiche Getter/Setter und Konstruktor/Destruktor (f_06a6e0, f_06a710).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 24/26 gleich (suche.py 30.10.2026, Basis gz_069970_P1.CPP)
// OPT -4r -onetx -zp1 -s
// P1 20/25 gleich (Fable M, Regelrunde 6)
// gz_069970.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x069970-0x06A790
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
struct E { int a; short b; };
struct T { char b; ~T(); };
struct U { char b; ~U(); };
struct Pre { char b[0xa4]; };
struct Gz {
  int h0;
  char *a4;
  char r8[0x9c];
  char c_a4;
  short a5;
  int a7;
  int ab;
  int af;
  int b3;
  int b7;
  char bb;
  short bc;
  char be;
  short bf;
  short c1;
  char c3;
  unsigned char c4;
  char c5;
  char c6;
  unsigned c7;
  char cb;
  char cc;
  char cd;
  char ce;
  T *cf;
  U *d3;
  Gz *d7;
  char db;
  unsigned char dc;
  int dd;
  char pad[11];
  int ec;
  int f0;
};
int f_010430();
short f_010440(int p1);
short f_010450(int p1);
short f_010460(int p1);
short f_010470(int p1);
int f_07ead0(int p1, int p2);
short f_0bd350(int p1, int p2, int p3);
void f_099fa0(short *p1);





extern int d_1bd768;
extern unsigned d_1bd76c;
extern int d_1bd934;
extern short d_1a2744;
extern short d_1a2746;

void f_069a20(Gz *p);
int f_0fabf0(void *p);





int f_099f70(int a, int b, int c, int d);
int f_0d3420(int x0, int y0, int x1, int y1);
void f_0d2710();
void f_0d26e0();
int f_072810(int p, int id);
signed char f_043dc0(int p);
unsigned char f_0104a0(int p);
unsigned char f_06acb0(Gz *p);
void f_06af80(Gz *p, unsigned char code);
void f_06a790(Gz *p);
void f_06a900(Gz *p);
void f_06a240(Gz *p, signed char direction, short column, short row, int alternate);
void f_09c750(int p);
extern int d_1a34e0, d_1c0004, d_1c2d1c;
extern unsigned char d_1bf4ef;
extern unsigned short d_1bdbd4, d_1bdbd6, d_1bdbd8, d_1bdbda;
extern short d_1bd926;
#pragma inline_depth(0)
//@ f_069970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt aus einer Archivdatei p2 | 0x40000000 über den Dateimanager d_1c2098 den 178-Byte-Kopf,
 *   springt zum Tabelleneintrag p3 (Offset 12 + p3 * 6) und liest *p1 Datensätze zu je 11 Bytes in den
 *   Zielpuffer *(void )(p1 + 1) ein.
 * - Eingaben und Rückgabe: Eingaben sind der Zielstrukturzeiger p1 (eax), die Datei-ID p2 (edx, unsigned) und
 *   der Tabellenindex p3 (ebx, short); zurückgegeben wird 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: d_1c2098 ist der globale Dateimanager (RivaFileManager).
 === Ende Beschreibung === */
int f_069970(unsigned short *p1, unsigned p2, short p3)
{
  char buf[0xb4];
  int r = 0;
  int n = ((RivaFileManager*)((int)&d_1c2098))->f_1448b0( p2 | 0x40000000, 0x202);
  if (n > 0) {
    ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( (int)buf), 0xb2)));
    if (*p1 > 0) {
      ((RivaFileManager*)((int)&d_1c2098))->f_144ab0( *(int *)(buf + 12 + p3 * 6), 0);
      ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( *(int *)(p1 + 1)), (unsigned)*p1 * 0xb)));
    }
    r = 1;
    ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
  }
  return r;
}
//@ f_069a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen 164-Byte-Animationsbefehlsblock (0xa4 Bytes) von p2 in den Anfang des
 *   Kampfsprite-Objekts p1 und setzt anschließend über f_069a20 den Laufzeitzustand des Sprites zurück.
 * - Eingaben und Rückgabe: Eingaben sind der Sprite-Zeiger p1 (eax) und der Quellblock p2 (edx); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: Die ersten 0xa4 Bytes von Gz enthalten die Ressource-ID, den Pfadzeiger a4 und bis zu 38
 *   Animationsphasen-Einträge r8.
 === Ende Beschreibung === */
void f_069a00(int *p1, int *p2)
{
  *(Pre *)p1 = *(Pre *)p2;
  f_069a20((Gz *)p1);
}
//@ f_069a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt alle Laufzeit- und Animationsfelder eines Kampfsprite-Objekts p (Framezähler, Offsets,
 *   Flags, Kind-Zeiger d7) auf ihre Startwerte zurück, gibt einen eventuell vorhandenen Frame-Deskriptor p->cf
 *   frei und speichert den aktuellen Zeitstempel d_1bd76c in p->c7.
 * - Eingaben und Rückgabe: Eingabe ist der Sprite-Zeiger p (eax); kein Rückgabewert (void).
 * - Wichtige Variablen: d_1bd76c liefert den aktuellen Kampftimer-Stand, p->b3 = 1 aktiviert die Sequenz.
 === Ende Beschreibung === */
void f_069a20(Gz *p)
{
  unsigned t;
  if (p->cf) {
    delete p->cf;
    p->cf = 0;
  }
  p->bc = 0;
  p->be = 0;
  p->bf = 0;
  p->c1 = 0;
  p->cb = 0;
  p->c_a4 = 0;
  p->c5 = 0xff;
  p->cc = 0xff;
  p->c4 = 0;
  t = d_1bd76c;
  p->c3 = 0;
  p->cd = 0;
  p->b7 = 0;
  p->ce = 0;
  p->bb = 0;
  p->c6 = 0;
  p->ab = 0;
  p->b3 = 1;
  p->d7 = 0;
  p->db = 0;
  p->dc = 0;
  p->ec = 0;
  p->f0 = 0;
  p->c7 = t;
}
//@ f_069b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand des globalen Kampftimers d_1bd76c, ob das Kampfsprite p zum nächsten
 *   Animationsframe weiterschalten darf (now - p->c7 >= p->c4 oder Zwangsflag p->af == 1), setzt bei Fälligkeit
 *   p->ab = 1 und synchronisiert über die verkettete Liste p->d7 alle angehängten Kind-Sprites (z. B. zweite
 *   Hälfte großer Monster).
 * - Eingaben und Rückgabe: Eingabe ist der Sprite-Zeiger p (eax); zurückgegeben wird das Schrittflag p->ab
 *   (short in ax, 1 = Frame fällig, 0 = warten).
 * - Wichtige Variablen: p->c7 ist der letzte Frame-Zeitpunkt, p->c4 die Framedauer und p->d7 die Verkettung zu
 *   gekoppelten Teil-Sprites.
 === Ende Beschreibung === */
short f_069b10(Gz *p)
{
  unsigned now = d_1bd76c;
  *(volatile unsigned char *)&p->db ^= 1;
  p->ab = 0;
  if (p->a7 != 0 && p->b3 != 0 && (p->af == 1 || (now - p->c7) >= p->c4)) {
    p->ab = 1;
    if (p->af == 0) {
      Gz *q = p;
      Gz *r;
      p->c7 = now;
      while ((r = q->d7) != 0) {
        Gz *next = r;
        char child, parent;
        unsigned cc;
        cc = p->c7;
        r->c7 = cc;
        child = r->db;
        parent = q->db;
        if (child == parent) r->ab = 1; else r->af = 1;
        q = next;
      }
    }
  }
  p->af = 0;
  return p->ab;
}
//@ f_069be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die aktuelle Animationssequenz des Sprites p abgeschlossen oder im Ruhezustand ist
 *   (p->b3 == 0 oder der aktuelle Phasentyp p->r8[5 + p->c_a4 * 4] == 4).
 * - Eingaben und Rückgabe: Eingabe ist der Sprite-Zeiger p (eax); zurückgegeben wird 1 bei Ruhezustand/Ende,
 *   sonst 0.
 * - Wichtige Variablen: p->b3 gibt an, ob die Sequenz noch läuft, p->c_a4 ist der Index der aktuellen
 *   Animationsphase.
 === Ende Beschreibung === */
int f_069be0(Gz *p)
{
  if (p->b3 == 0 || p->r8[5 + p->c_a4 * 4] == 4) return 1;
  return 0;
}
//@ f_069c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hauptzeichen- und Fortschrittsroutine eines Kampfsprites p: Lädt bei Bedarf über
 *   f_06a790/f_06a900 die Grafikdaten des aktuellen Frames, berechnet die Bildschirmkoordinaten (inklusive
 *   Flugbahn p->a4), setzt über f_06a240 das Clipping-Rechteck, zeichnet das Sprite (bei
 *   unsichtbaren/verschobenen Zielen f_043dc0 mehrfach versetzt) in den Zielpuffer buf und wertet anschließend
 *   Frame- und Sequenz-Aktionscodes (0x0c..0x1d für Kampfsounds f_06af80, Geschoss-Start 0x1c und Sequenzende
 *   0x1d) aus.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax), der Zielbildpuffer buf (edx), die Basisposition x
 *   (ebx), y (ecx) sowie auf dem Stapel direction, die Ausgaberechteck-Zeiger x0, y0, x1, y1, der Z-Wert z und
 *   das Clipping-Flag alternate; zurückgegeben wird der verbleibende Aktionscode (int in eax, z. B.
 *   Bewegungs-/Drehcode oder 0x22 bei Pfadbewegung).
 * - Wichtige Variablen: p->cf und p->d3 halten den aktuellen Frame-Header und das entpackte Rasterbild,
 *   d_1bdbd4..d_1bdbda sichern das globale Clipping-Rechteck.
 === Ende Beschreibung === */
struct Box4 {
  short a[4];
};
int f_069c10(Gz *p, int buf, short x, short y, signed char direction,
             short *x0, short *y0, short *x1, short *y1, short *z, int alternate)
{
  
    char s[12];
  Box4 box;
  char *cell;
  int hide;
  int obj;
  short top;
  short row;
  int res;
  short ret;
  short col;
  short height;
  short row_plus;
  short clip_x0;
  short width;
  short left;


  if (0) { (void)&cell; }

  box.a[0] = 0;
  box.a[1] = 0;
  box.a[2] = 0;
  box.a[3] = 0;
  ret = 0;
  f_0fabf0(s);
  cell = (char *)f_07ead0(d_1bd934, (int)p);
  *z = p->cb;
  *x0 = *x1 = x;
  *y0 = *y1 = y;
  if (p->a7 != 0) {
    if (!p->ce) {
      if ((signed char)p->bb == 0) {
        f_06a790(p);
      } else if (p->b3 != 0 && p->cb != p->cc) {
        f_06a900(p);
      }
    }
    left = f_010440((int)p->cf);
    if (0) { (void)*(unsigned long *)&left; } // Alias erhaelt WORD-Store und Slotordnung
    top = f_010450((int)p->cf);
    if (0) { (void)*(unsigned long *)&top; } // Alias erhaelt WORD-Store und Slotordnung
    *(short *)&width = f_010460((int)p->cf);
    if (0) { width = (unsigned char)width; } // Bytealias erhaelt WORD-Store
    height = f_010470((int)p->cf);
    if (0) { *(unsigned char *)&height = (unsigned char)height; } // Bytealias erhaelt WORD-Store
    ((RivaRasterImage*)(s))->f_0fad50( (short)width, (short)height,(void *)( (void *)((int)(((RivaRasterImage*)(p->d3))->f_0fb0b0()))));
    if (p->a4 != 0) {
      x = *(short *)(p->a4 + p->dc * 4);
      y = *(short *)(p->a4 + p->dc * 4 + 2);
      if (p->ab != 0) {
        p->dc++;
      }
    }
    x += p->bf;
    y += p->c1;
    if (p->ec != 0) {
      x = 0x140 - p->bc;
      y = 0;
    }
    col = x + (short)left;
    row = y + (short)top;
    box = *(Box4 *)&d_1bdbd4;
    f_06a240(p, direction, col, row, alternate);
    *x0 = col;
    *x1 = col + (short)width;
    *y0 = row;
    *y1 = row + (short)height;
    hide = 0;
    if (buf == d_1a34e0 && !d_1bf4ef) {
      if (f_0d3420(col, row, (short)(col + (short)width), (short)(row + (short)height))) {
        hide = 1;
        f_0d2710();
      }
    }
    union { unsigned full; unsigned char byte; } id;
    id.full = 0;
    id.byte = (unsigned char)cell[9];
    obj = f_072810(d_1c0004, id.full);
    if (obj != 0) {
      int mode = f_043dc0(obj);
      row_plus = row + 4;
      if (mode == 2) {
        *x0 = col - 4;
        *x1 = col + (short)width + 4;
        *y0 = row - 4;
        *y1 = row + (short)height + 4;
        f_099f70((unsigned short)(clip_x0 = d_1bdbd4 - 4), (unsigned short)(d_1bdbd6 - 4),
                 (unsigned short)(d_1bdbd8 + 4), (unsigned short)(d_1bdbda + 4));
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), (short)(col + 4), (short)(row - 4), 1);
        int draw_y;
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), col, (draw_y = row, row = (short)draw_y, draw_y), 1); // Roundtrip erhoeht ECX-Nutzwert
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), (short)(col - 4), row_plus, 1);
      } else if (f_043dc0(obj)) {
        *x0 = col - 4;
        *x1 = col + (short)width;
        *y0 = row;
        *y1 = row + (short)height + 4;
        f_099f70((unsigned short)(d_1bdbd4 - 4), d_1bdbd6,
                 d_1bdbd8, (unsigned short)(d_1bdbda + 4));
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), col, row, 1);
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), (short)(col - 4), row_plus, 1);
      } else {
        ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), col, row, 1);
      }
    } else {
      ((RivaRasterImage*)(s))->f_0fae30((void *)( buf), col, row, 1);
    }
    if (hide != 0) {
      f_0d26e0();
    }
    ((RivaRasterImage*)(s))->f_0fadc0();
    f_099fa0(box.a);
    if ((char)direction) {
      p->ce++;
      if ((signed char)p->ce == 2) {
        p->ce = 0;
      }
    }
    if (!p->ce) {
      if (p->ab != 0) {
        ret = f_0104a0((int)p->cf);
      } else {
        ret = 0;
      }
      if (p->ab != 0) {
        unsigned char code = f_06acb0(p);
        if (!d_1bd926) {
          if (code != 0) {
            if (code >= 0x0c && code <= 0x1b) {
              f_06af80(p, code);
              code = 0;
            } else if (code == 0x1c) {
              Gz *q = *(Gz **)p->r8;
              q->a7 = 1;
              if (q->a4 != 0) {
                *(char *)(f_07ead0(d_1bd934, (int)q) + 0x20) = 1;
              }
              code = 0;
            } else if (code == 0x1d) {
              p->b3 = 0;
            }
            if (code != 0) {
              ret = code;
            }
          }
          if (p->c3 != 1 && (p->a5 < 0x77 || p->a5 > 0x9e) && p->cb == p->c3 / 2 + 1) {
            f_09c750((int)&d_1c2d1c);
          }
        }
      }
      if (!d_1bd926) {
        if (ret >= 0x0c && ret <= 0x1b) {
          f_06af80(p, (unsigned char)ret);
          ret = 0;
        } else if (ret == 0x1c) {
          Gz *q = *(Gz **)p->r8;
          q->a7 = 1;
          if (q->a4 != 0) {
            *(char *)(f_07ead0(d_1bd934, (int)q) + 0x20) = 1;
          }
          ret = 0;
        } else if (ret == 0x1d) {
          p->b3 = 0;
        }
      }
    }
    if (!p->ce) {
      p->ab = 0;
    }
    if (ret == 0 && p->a4 != 0) {
      ret = 0x22;
    }
  } else {
    ret = 0;
  }
  res = ret;
  ((int)(((RivaRasterImage*)(s))->f_0fad20( 0)));
  return res;
}




//@ f_06a240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet und setzt über f_099fa0 das Bildschirm-Clipping-Rechteck für das Kampfsprite p an
 *   Position (column, row), wobei bei halb verdeckten Feldern (direction = 1..4) und abhängig vom Flag alternate
 *   jeweils nur die vordere oder hintere Hälfte der isometrischen Kachel freigegeben wird.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax), die Verdeckungsrichtung direction (edx), column
 *   (ebx), row (ecx) und auf dem Stapel alternate; kein Rückgabewert (void).
 * - Wichtige Variablen: d_1a2744 und d_1a2746 sind der Bildschirmursprung des isometrischen Kampfrasters.
 === Ende Beschreibung === */
void f_06a240(Gz *p, signed char direction, short column, short row, int alternate)
{
  short local_010470(int, int);
  #pragma aux local_010470 "f_010470" parm [eax] [edx] value [eax] modify exact [eax]
  struct {
    short box[4];
    short top[2];
    short bottom[2];
    short right[2];
    short left[2];
  } fr;
  fr.box[0] = 0;
  fr.box[1] = 0;
  fr.box[2] = 0;
  fr.box[3] = 0;
  char *cell = (char *)f_07ead0(d_1bd934, (int)p);
  short first = (signed char)cell[0];
  short second = (signed char)cell[1];
  short x = (first + second) * 10 + d_1a2744;
  unsigned short yoff490 = d_1a2746; unsigned short y = (first - second) * 5;
  fr.left[0] = f_010440((int)p->cf);
  fr.top[0] = f_010450((int)p->cf);
  fr.right[0] = f_010460((int)*(T *volatile *)&p->cf); // Erzwingt erneutes Laden von p->cf
  y += yoff490;
  fr.bottom[0] = local_010470((int)p->cf, 0); // Lokale Clobber-Signatur haelt die Registerfolge
  fr.box[0] = f_0bd350(column, 0, 0x13f);
  fr.box[2] = f_0bd350(fr.right[0] + column, 0, 0x13f);
  fr.box[1] = f_0bd350(row, 0, 0xc7);
  d_1bd934 = (d_1bd934 & 0) ? 0 : d_1bd934; // Haelt d_1bd934 in der Registerfolge
  fr.box[3] = f_0bd350(fr.bottom[0] + row, 0, 0xc7);
  alternate = (alternate & 0) ? 0 : alternate; // Haelt alternate fuer die Verzweigungsfolge
  if (alternate != 0) {
    switch ((unsigned char)direction) {
    case 1:
      fr.box[0] = f_0bd350(column, 0, 0x13f);
      fr.box[2] = f_0bd350((short)x - 5, 0, 0x13f);
      f_099fa0(fr.box);
      return;
    case 2:
      fr.box[0] = f_0bd350((short)x + 5, 0, 0x13f);
      fr.box[2] = f_0bd350(fr.right[0] + column, 0, 0x13f);
      f_099fa0(fr.box);
      return;
    case 3:
      fr.box[1] = f_0bd350((short)y, 0, 0xc7);
      fr.box[3] = f_0bd350(fr.bottom[0] + row, 0, 0xc7);
      f_099fa0(fr.box);
      return;
    case 4:
      fr.box[1] = f_0bd350(row, 0, 0xc7);
      fr.box[3] = f_0bd350((short)y - 5, 0, 0xc7);
      f_099fa0(fr.box);
      return;
    }
  } else {
    switch ((unsigned char)direction) {
    case 1:
      fr.box[0] = f_0bd350(column, 0, 0x13f);
      fr.box[2] = f_0bd350((short)x + 5, 0, 0x13f);
      f_099fa0(fr.box);
      return;
    case 2:
      fr.box[0] = f_0bd350((short)x - 5, 0, 0x13f);
      fr.box[2] = f_0bd350(fr.right[0] + column, 0, 0x13f);
      f_099fa0(fr.box);
      return;
    case 3:
      fr.box[1] = f_0bd350((short)y - 5, 0, 0xc7);
      fr.box[3] = f_0bd350(fr.bottom[0] + row, 0, 0xc7);
      f_099fa0(fr.box);
      return;
    case 4:
      fr.box[1] = f_0bd350(row, 0, 0xc7);
      fr.box[3] = f_0bd350((short)y, 0, 0xc7);
      f_099fa0(fr.box);
      return;
    }
  }
  f_099fa0(fr.box);
}
//@ f_06a550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus dem aktuellen Frame-Deskriptor p->cf die vier Geometpiewerte (X-Offset, Y-Offset,
 *   Breite und Höhe) aus und schreibt sie in die vier Zeigerparameter p2..p5.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax), p2 (edx), p3 (ebx), p4 (ecx) und auf dem Stapel p5;
 *   kein Rückgabewert (void).
 * - Wichtige Variablen: Greift über f_010440..f_010470 auf p->cf zu.
 === Ende Beschreibung === */
void f_06a550(Gz *p, unsigned short *p2, unsigned short *p3, unsigned short *p4, unsigned short *p5)
{
  *p2 = f_010440((int)p->cf);
  *p3 = f_010450((int)p->cf);
  *p4 = f_010460((int)p->cf);
  *p5 = f_010470((int)p->cf);
}
//@ f_06a5a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Wiederholungszähler p->cd der laufenden Animationsphase zurück.
 * - Eingaben und Rückgabe: Eingabe ist der Sprite-Zeiger p (eax); Rückgabewert ist p->cd (char in al).
 * - Wichtige Variablen: Feld p->cd (Offset +0xcd).
 === Ende Beschreibung === */
char f_06a5a0(Gz *p)
{
    return p->cd;
}
//@ f_06a5b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Sichtbarkeits-/Aktivitätsflag p->a7 = p2 des Kampfsprites und markiert bei
 *   Aktivierung (p2 == 1) und vorhandener Bewegungsbahn (p->a4 != 0) das zugehörige Kampfraster-Objekt (+0x20)
 *   als veränderungsbedürftig.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der neue Status p2 (edx); kein Rückgabewert
 *   (void).
 * - Wichtige Variablen: p->a7 steuert, ob das Sprite gezeichnet wird.
 === Ende Beschreibung === */
void f_06a5b0(Gz *p, int p2)
{
  int r;
  p->a7 = p2;
  if (p2 == 1 && p->a4 != 0) {
    r = f_07ead0(d_1bd934, (int)p);
    *(char *)(r + 0x20) = 1;
  }
}
//@ f_06a5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Zeitstempel p->c7 des Kampfsprites auf den Wert p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der Zeitstempel p2 (edx, unsigned); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: Feld p->c7 (Offset +0xc7).
 === Ende Beschreibung === */
void f_06a5e0(Gz *p, unsigned p2)
{
    p->c7 = p2;
}
//@ f_06a5f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Initialisierungsflag p->bb des aktuellen Animationsabschnitts zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->bb (char in al).
 * - Wichtige Variablen: Feld p->bb (Offset +0xbb).
 === Ende Beschreibung === */
char f_06a5f0(Gz *p)
{
    return p->bb;
}
//@ f_06a600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die explizite Frame-Geschwindigkeitsvorgabe p->c5 des Sprites auf p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der Geschwindigkeitswert p2 (edx, char); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: Feld p->c5 (Offset +0xc5).
 === Ende Beschreibung === */
void f_06a600(Gz *p, char p2)
{
    p->c5 = p2;
}
//@ f_06a610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Kennung p->a5 der aktuell geladenen Teil-Animation zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->a5 (short in ax).
 * - Wichtige Variablen: Feld p->a5 (Offset +0xa5).
 === Ende Beschreibung === */
short f_06a610(Gz *p)
{
    return p->a5;
}
//@ f_06a620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verknüpft das Kampfsprite p mit einem gekoppelten Nachfolge-/Kind-Sprite p2 (p->d7 = p2).
 * - Eingaben und Rückgabe: Eingaben sind das Haupt-Sprite p (eax) und das Kind-Sprite p2 (edx); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: Feld p->d7 (Offset +0xd7).
 === Ende Beschreibung === */
void f_06a620(Gz *p, Gz *p2)
{
    p->d7 = p2;
}
//@ f_06a630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zeiger p->d7 auf das gekoppelte Kind-Sprite zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->d7 (Gz * in eax).
 * - Wichtige Variablen: Feld p->d7 (Offset +0xd7).
 === Ende Beschreibung === */
Gz *f_06a630(Gz *p)
{
    return p->d7;
}
//@ f_06a640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Synchronisationsflag p->af des Sprites auf p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und das Flag p2 (edx, signed char); kein
 *   Rückgabewert (void).
 * - Wichtige Variablen: Feld p->af (Offset +0xaf).
 === Ende Beschreibung === */
void f_06a640(Gz *p, signed char p2)
{
    p->af = p2;
}
//@ f_06a650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Frame-Fälligkeitsflag p->ab des Sprites auf p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der Wert p2 (edx, int); kein Rückgabewert
 *   (void).
 * - Wichtige Variablen: Feld p->ab (Offset +0xab).
 === Ende Beschreibung === */
void f_06a650(Gz *p, int p2)
{
    p->ab = p2;
}
//@ f_06a660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Paritäts-/Taktbit p->db des Sprites zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->db (char in al).
 * - Wichtige Variablen: Feld p->db (Offset +0xdb).
 === Ende Beschreibung === */
char f_06a660(Gz *p)
{
    return p->db;
}
//@ f_06a670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die zuletzt durchlaufene X/Y-Koordinate (p->dc - 1) aus der Bewegungsbahn p->a4 aus und
 *   schreibt sie nach *p2 und *p3.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) sowie die Ausgabezeiger p2 (edx, short *) und p3
 *   (ebx, short *); kein Rückgabewert (void).
 * - Wichtige Variablen: p->a4 zeigt auf das Punkt-Array der Flug-/Bewegungsbahn, p->dc ist der aktuelle
 *   Schrittindex.
 === Ende Beschreibung === */
void f_06a670(Gz *p, short *p2, short *p3)
{
  *p2 = *(short *)(p->a4 + p->dc * 4 - 4);
  *p3 = *(short *)(p->a4 + p->dc * 4 - 2);
}
//@ f_06a6a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Spezial-Positionierungsflag p->ec des Sprites auf p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der Wert p2 (edx); kein Rückgabewert (void).
 * - Wichtige Variablen: Feld p->ec (Offset +0xec).
 === Ende Beschreibung === */
void f_06a6a0(Gz *p, int p2)
{
    p->ec = p2;
}
//@ f_06a6b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Wert des Spezial-Positionierungsflags p->ec zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->ec (int in eax).
 * - Wichtige Variablen: Feld p->ec (Offset +0xec).
 === Ende Beschreibung === */
int f_06a6b0(Gz *p)
{
    return p->ec;
}
//@ f_06a6c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Stummschaltungs-/Sound-Sperrflag p->f0 des Sprites auf p2.
 * - Eingaben und Rückgabe: Eingaben sind das Sprite p (eax) und der Wert p2 (edx); kein Rückgabewert (void).
 * - Wichtige Variablen: Feld p->f0 (Offset +0xf0).
 === Ende Beschreibung === */
void f_06a6c0(Gz *p, int p2)
{
    p->f0 = p2;
}
//@ f_06a6d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Sound-Sperrflag p->f0 des Sprites zurück.
 * - Eingaben und Rückgabe: Eingabe ist das Sprite p (eax); Rückgabewert ist p->f0 (int in eax).
 * - Wichtige Variablen: Feld p->f0 (Offset +0xf0).
 === Ende Beschreibung === */
int f_06a6d0(Gz *p)
{
    return p->f0;
}
//@ f_06a6e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor eines Kampfsprite-Objekts Gz: Initialisiert die Zeiger cf und d3 mit 0, übernimmt
 *   über f_069a00 den Animationsbefehlsblock p2 und setzt das Sichtbarkeitsflag p->a7 = p3.
 * - Eingaben und Rückgabe: Eingaben sind der Objektzeiger p (eax), der Befehlsblock p2 (edx) und das Aktivflag
 *   p3 (ebx); zurückgegeben wird p (Gz * in eax).
 * - Wichtige Variablen: Belegt die 0xf4 Bytes große Struktur Gz.
 === Ende Beschreibung === */
Gz *f_06a6e0(Gz *p, int *p2, int p3)
{
  p->cf = 0;
  p->d3 = 0;
  f_069a00((int *)p, p2);
  p->a7 = p3;
  return p;
}
//@ f_06a710
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor eines Kampfsprite-Objekts Gz: Gibt den Frame-Deskriptor p->cf, das Rasterbild p->d3
 *   samt zugehörigem Pixelpuffer p->dd (sofern p->dd != d_1bd768) sowie ein eventuell alloziertes Pfad-Array
 *   p->a4 frei.
 * - Eingaben und Rückgabe: Eingaben sind der Objektzeiger p (eax) und ein unbenutztes Flag (edx); zurückgegeben
 *   wird p (Gz * in eax).
 * - Wichtige Variablen: d_1bd768 bezeichnet einen gemeinsam genutzten Standardpuffer, der nicht einzeln
 *   freigegeben werden darf.
 === Ende Beschreibung === */
Gz *f_06a710(Gz *p, int p_unused1)
{
  if (p->cf) {
    delete p->cf;
    p->cf = 0;
  }
  if (p->d3) {
    delete p->d3;
    if (p->dd != d_1bd768) operator delete((void *)p->dd);
    p->d3 = 0;
  }
  if (p->a4) {
    operator delete(p->a4);
    p->a4 = 0;
  }
  return p;
}
