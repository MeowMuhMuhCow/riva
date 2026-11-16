/* === Beschreibung (Katalog) ===
 * Einheit gz_076a40 (076a40 - 077400)
 *
 * Überblick
 * Diese Einheit enthält den Timer-/Interrupt-Callback für laufende Kampfanimationen (f_076a40), eine
 * Umfärbe-Hilfsfunktion (f_076bb0), die Anzeige und Vertonung von Treffer-, Schadens- und Statusmeldungen im
 * Kampf (f_076bd0) sowie eine Abfrage auf aktive Zauberkundige in der Gruppe (f_0773b0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 2/4 gleich (suche.py 25.10.2026, Basis gz_076a40_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 1 gleich (vorher 1), Rest 461 (vorher 465)
// gz_076a40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x076A40-0x077400
#include <string.h>
#pragma pack(1)
struct Link { char p0[0xb]; signed char c; char p1[3]; int f; char p2[4]; Link *next; };
struct Q { char *buf; char pad[0x35]; Link *l39; char pad2[0x1077 - 0x3d]; int f1077; };
struct E { short a; short b; char c; int d; char e; int f; };
struct P { short z0; short idx; short n; short rst; E e[15]; int f_da; int f_de; int f_e2; char s_e6[16]; };
struct S { int f0; char *f4; char *f8; char pad[16]; char *f1c; char pad2[28]; };
#pragma pack()

int f_04feb0(void *p1, void *p2, int p3, int p4, int p5, int p6, short *p7, short *p8, int p9);
int f_050580(void *p1, void *p2, short p3, short *p4, short *p5);
int f_05ded0(int p1, int p2);
int f_05e320(int p1, int p2, int p3);
int f_05e360(int p1, int p2, int p3);
int f_069460();
unsigned short f_069b10(int p1);
int f_075f10(Q *p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0765a0(Q *p1);
int f_07b7e0(Q *p1);
int f_09c780(P *p1);
signed char f_0cfdc0(int p1);
signed char f_0d00c0(int p1);
signed char f_0d0180(int p1);
int f_0d0500(int p1);
int f_0d0520(int p1);
int f_0d06c0(int p1);
int f_0d0730(int p1);
int f_0d49b0(int p1);
int f_0e3360(void *p1);
int f_0e93f0(void *p1, char *p2, int p3);
int f_0e9660(void *p1, void *p2, int p3, int p4);
short f_0e9670(void *p1, void *p2, int p3, int p4);

int f_10ad00(int p1);
int f_10af20(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(S *p1, int);
char f_145400(int p1, char *p2);
short f_1457e0(int p1);
char *f_148518(int p1, char *p2, int p3);
void *f_145300(void *p1, int p2, int p3);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_076bd0(P *p1);
extern int d_010002;
extern int d_1a34e0;
extern char d_1a3554[];
extern int d_1a9820;
extern int d_1bd7c4;
extern short d_1bd910;
extern signed char d_1bd928;
extern int d_1bd988;
extern char d_1bda50;
extern int d_1bda54;
extern int d_1bda58;
extern char *d_1bda5c;
extern int d_1bda68;
extern char *d_1bdaec;
extern short d_1c219e;
extern int d_1c2be0;
extern int d_1c2c64;
extern P d_1c2d1c;
extern Link *d_1c2ecc;
extern int d_1c2edc;
extern int d_1c3068;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;

//@ f_076a40  groesse 400 B
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird regelmäßig vom Timer/Animationssystem aufgerufen, schaltet alle aktiven
 *   Kampf-Animationsobjekte in der Objektliste obj->l39 über f_069b10 um einen Frame weiter und aktualisiert bei
 *   mindestens einer Bildänderung den gesamten Kampfbildschirm (f_0765a0, f_076bd0, f_075f10). Im Schnellkampf-
 *   oder Hintergrundmodus (d_1bd928 != 0) hält sie stattdessen das Sound-/Streaming-System (f_10af20, f_10ad00,
 *   f_07b7e0) am Laufen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger obj (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwendet die Reentranz-Sperre d_1bd7c4, damit sich Timer-Aufrufe nicht gegenseitig
 *   überlagern.
 === Ende Beschreibung === */
void f_076a40(int obj)
{
  // Haelt die Register- und Lebensdauerfolge in der Schleife wie im Original.
  d_010002 = (d_010002 & 0) ? 0 : d_010002;
  int b = 0;
  if (d_1bd7c4 == 0) {
    int one = 1;
    d_1bd7c4 = one;
    if (!d_1bd928) {
      if (d_1bd910 == one) {
        char *rt0 = ((Q *)obj)->buf; ((Q *)obj)->buf = rt0;
        d_1bd7c4 = one;
        Link **pl = &((Q *)obj)->l39;
        int keep = d_1a34e0;
        int z = 0;
        int first = (int)*pl;
        int cursor = first;
        do {
          z |= b & 0;
          obj = (b & 0) ? 0 : obj;
          one = (b & 0) ? 0 : one;
          obj = (b & 0) ? 0 : obj;
          int kind = ((Link *)cursor)->c;
          kind = (kind & 0) ? 0 : kind;
          if (kind == 1) {
              cursor |= b & 0;
              b |= cursor & 0;
              obj |= b & 0;
              one |= b & 0;
              z |= b & 0;
            int f = ((Link *)cursor)->f;
            if (z != f) {
              cursor |= b & 0;
              b |= cursor & 0;
              obj |= b & 0;
              one |= b & 0;
              int rt = d_1bd7c4; rt |= b & 0; d_1bd7c4 = rt;
              short r = f_069b10(f);
              z |= b & 0;
              b |= f ^ f;
              if ((short)r != (short)0) b = one;
            }
          }
          cursor = (int)((Link *)cursor)->next;
          cursor |= b & 0;
          b |= cursor & 0;
        } while (cursor != (int)d_1c2ecc);
        if (b) {
          Q *self = (Q *)obj;
          if (!d_1bd928) {
            Q *q = (Q *)obj;
            if (!d_1bd928) {
              d_1bda50 = d_1bd928;
              f_145300(&d_1bd988, -1, 200);
              d_1bda58 = 0;
              if (d_1bda54 != 0) {
                f_0762e0(0, 0, 0x13f, 199);
                d_1bda58 = 1;
              }
              memcpy(q->buf, d_1bdaec, 0xfa00);
            }
            f_0765a0(self);
            f_076bd0(&d_1c2d1c);
            f_075f10(self);

          } else {
            f_069460();

          }
        }
      }
    } else if (d_1bd928 != 2) {
      if (f_10af20(((Q *)obj)->f1077) == 1) {
        f_10ad00(((Q *)obj)->f1077);
      }
      if (d_1c219e == 1) {
        f_07b7e0((Q *)obj);
      }
    }
    d_1bd7c4 = 0;
  }
}
//@ f_076bb0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ersetzt in einem Pixelpuffer p der Länge n alle von 0 (transparent) verschiedenen Farbwerte
 *   durch den neuen Farbindex v, um einfarbige Symbole oder Treffersterne im Kampf umzufärben.
 * - Eingaben und Rückgabe: Empfängt den Pufferzeiger p (char *), die Byteanzahl n (short) sowie den Zielfarbwert
 *   v (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Arbeitet direkt auf dem übergebenen Bildpuffer.
 === Ende Beschreibung === */
void f_076bb0(char *p, short n, int v)
{
  for (;;) {
    --n; if (n == (short)-1) break;
    if (*p) *p = (char)v;
    p++;
  }
}
//@ f_076bd0  groesse 2016 B
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die Kampfmeldungen (z. B. Trefferstern mit Schadenszahl, Parade, Zauberwirkung oder
 *   Tod) samt farbigem Symbol (0x10002), formatiertem Kampftext (0x1010060 + EN.a) in der unteren Statuszeile
 *   und passendem Soundeffekt (0xc000a..0xc0029 je nach Geschlecht und Gegnertyp) dar und zählt die Anzeigedauer
 *   p1->n herunter.
 * - Eingaben und Rückgabe: Empfängt den Zeiger p1 auf die Kampfmeldungs-Warteschlange (d_1c2d1c) und gibt 1
 *   zurück, solange eine Meldung aktiv angezeigt wird, sonst 0.
 * - Wichtige Variablen: Liest den aktuellen Meldungseintrag p1->e[p1->idx], färbt das Treffer-Sprite über
 *   d_1a3554[EN.a] ein und spielt beim ersten Frame (p1->f_de == 0) über f_147323 den zugehörigen Treffer- oder
 *   Todesschrei ab.
 === Ende Beschreibung === */
#define EN p1->e[p1->idx]
static inline short g_w140() { return 0x140; }
static inline short g_p7() { return 1; }
static inline short g_p6() { return 0; }
static inline int g_p5() { return d_1a9820; }
static inline unsigned short g_p4() { return 0x8000; }
static inline unsigned short g_p3() { return 0x7fff; }
#define SEND(x) f_147323(&d_1c2edc, x, g_p3(), g_p4(), g_p5(), g_p6(), g_p7())
int f_076bd0(P *p1)
{
  int f_125400_frame(void *, const char *, const char *, const char *);
  #pragma aux f_125400_frame "f_125400" modify [esp eax ebx ecx edx];
  #define f_125400 f_125400_frame
  extern int d_1c3498;
  S s;
  char buf[8];
  short old_x, width;
  short height, old_y;
  int parity;
  short text_width;
  int color_index;
  signed char slot2, slot1;
  char *pixels;
  int result;

  f_125400(&s, (const char *)&d_1c349c, (const char *)&d_1c3870, (const char *)&d_1c3498);
  result = 0;
  if (p1->f_da != 1 || *d_1bda5c != (char)0 || f_0e3360(&d_1c2c64) != 0) goto Lend;
  if (EN.a == (short)0) goto Lend;
  result = 1;
  if (--p1->n <= 0) {
    p1->idx++;
    p1->f_de = 0;
    if (EN.a != (short)0) {
      p1->n = p1->rst;
    } else {
      f_0762e0(0, 0x8c, 0x5a, 199);
      f_0762e0(0, 0xc0, 300, 199);
      result = 0;
      p1->idx = 0;
      f_09c780(p1);
    }
  }
  if (result != 1) goto Lend;
  *d_1bda5c = 1;
  d_1bda68 = result;
  f_05e360((int)&d_1c38b0, (int)&old_x, (int)&old_y);
  f_05ded0((int)&d_1c3068, p1->f_e2);
  parity = p1->idx % 2 == 0;
  // Haelt die Blockstruktur fuer die Registerwahl von parity/result wie im Original.
  if (parity) { int *same = (parity & 0) ? 0 : &d_1bda68; result |= d_1bda68 - *same; }
  f_050580(&d_1c2be0, (void *)0x10002, (short)parity, &height, &width);
  {
  RivaRasterImage im(height, width);
  f_04feb0(&d_1c2be0, (void *)0x10002, ((int)(((RivaRasterImage*)(&im))->f_0fb0b0())), 0, (short)parity, 0, &height, &width, g_w140());
  struct Recolor {
    static void run(char *p, unsigned short n, char v) {
      for (;;) {
        --n; if (n == (unsigned short)-1) break;
        if (*p) *p = v;
        p++;
      }
    }
  };
  Recolor::run((char *)((int)(((RivaRasterImage*)(&im))->f_0fb0b0())), (unsigned short)(height * width), d_1a3554[EN.a]);
  ((RivaRasterImage*)((int)&im))->f_0fae30((void *)( p1->f_e2), 8, (short)(0xc3 - width), 1);
  if (EN.b != (short)0) {
    f_05e320((int)&d_1c38b0, 0xff, (signed char)d_1a3554[EN.a]);
    f_148518(EN.b, buf, 10);
    text_width = f_0e9670(&d_1c38b0, buf, 8, (short)height);
    f_0e9660(&d_1c38b0, buf, text_width, (short)(0xbf - width / 2));
  }
  f_05e320((int)&d_1c38b0, 0xff, -1);
  slot1 = 1;
  slot2 = 1;
  if ((signed char)EN.c == 2) {
    *(int *)(s.f4 + (slot1++) * 4) = EN.d;
  } else {
    *(int *)(s.f8 + slot2 * 4) = EN.d;
    *(short *)(s.f1c + slot2++ * 2) = 1;
  }
  if ((signed char)EN.e == 2) {
    *(int *)(s.f4 + (slot1++) * 4) = EN.f;
  } else {
    *(int *)(s.f8 + slot2 * 4) = EN.f;
    *(short *)(s.f1c + slot2++ * 2) = 1;
  }
  f_0e93f0(&d_1c38b0, p1->s_e6, EN.a + 0x1010060);
  p1->s_e6[0] = ((char (*)(int))f_145400)((unsigned char)p1->s_e6[0]);
  f_0e9660(&d_1c38b0, p1->s_e6, 1, 0xc0);
  f_0762e0(0, 0x8c, 0x5a, 199);
  f_0762e0(0, 0xc0, 300, 199);
  f_05e320((int)&d_1c38b0, old_x, old_y);
  f_05ded0((int)&d_1c3068, d_1a34e0);
  if (p1->f_de == 0) {
    p1->f_de = 1;
    if (EN.a == 8 || EN.a == 0x17 || EN.a == 0xf || EN.a == 0x10) {
      if (f_0cfdc0(EN.f) || f_0d06c0(EN.f)) goto Ldone;
      if (f_0d0520(EN.f)) SEND(0xc0020);
      else if (f_0d0500(EN.f)) SEND(0xc0019);
      else if (f_0d00c0(EN.f)) SEND(0xc000c);
      else if (f_0d0730(EN.f)) {
        if (EN.a == 0x17 || EN.a == 8) {
          if ((short)f_0d0180(EN.f) == (short)1) SEND(0xc0026);
          else SEND(0xc0025);
        } else {
          if (f_1457e0(100) > 50) SEND(0xc000a);
          else SEND(0xc000d);
        }
      } else SEND(0xc0011);
    } else if (EN.a == 7) {
      if ((short)f_042380((struct hero *)(EN.f)) == (short)1) SEND(0xc000e);
      else SEND(0xc0013);
    } else if (EN.a == 0x18 || EN.a == 0xb || EN.a == 0xd || EN.a == 0xe) {
      short selected = EN.b;
      short flag = f_042380((struct hero *)(EN.f));
      if (((signed char)(f_042470((struct hero *)(EN.f))))) {
        if (flag == (short)1) SEND(0xc0024);
        else SEND(0xc0018);
      } else if (EN.a == 0x18 || EN.a == 0xb) {
        if (selected > 20) {
          if (flag == (short)1) SEND(0xc0026);
          else SEND(0xc0025);
        } else {
          if (flag == (short)1) SEND(0xc0028);
          else SEND(0xc0027);
        }
      } else {
        SEND(f_1457e0(100) > 50 ? 0xc000a : 0xc000d);
      }
    } else if (EN.a == 6) {
      SEND(0xc0029);
    }
  }
Ldone: ;
  // Die gemeinsame Klasse zerstoert im am Blockende.
  }
Lend:
  f_1254a0(&s, 0);
  return result;
}
#undef f_125400
#undef SEND
//@ f_0773b0  groesse 80 B
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob sich in den 7 Gruppen-Slots a[0..6] mindestens ein lebender, kampffähiger Held (kein
 *   Begleiter-NSC) befindet, der über Magiebegabung verfügt (f_042750 == 1).
 * - Eingaben und Rückgabe: Empfängt das Heldenzeiger-Array a (int *) und gibt 1 bei mindestens einem aktiven
 *   Magiekundigen oder 0 zurück.
 * - Wichtige Variablen: Prüft je Slot f_042400(p) == 0, f_0d49b0(p) == 1 und f_042750(p) == 1.
 === Ende Beschreibung === */
int f_0773b0(int *a)
{
  int r;
  short i;
  int p;
  r = 0;
  for (i = 0; i <= 6; i++) {
    p = a[i];
    if (p != 0 && f_042400((struct hero *)(p)) == 0 && f_0d49b0(p) == 1 && f_042750((struct hero *)(p)) == 1) {
      r = 1; break;
    }
  }
  return r;
}
