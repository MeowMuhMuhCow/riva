/* === Beschreibung (Katalog) ===
 * Einheit diary (056d90 - 0580a0)
 *
 * Überblick
 * Diese Einheit (diary.cpp) implementiert das Tagebuch- und Notizbuchsystem von *Schatten über Riva*. Spieler
 * können im Tagebuch durch alle automatisch protokollierten Quest-Einträge sowie eigene handgeschriebene Notizen
 * blättern, direkt zu einer bestimmten Seite springen, eigene Einträge verfassen oder löschen und das Tagebuch
 * gezielt nach Personen, Orten, Gegenständen oder Stichwörtern durchsuchen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
#include "R_FIX.H"
// P3 5/9 gleich (suche.py 30.10.2026, Basis diary_P1.CPP)
// diary.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x056D90-0x0580A0
#include <string.h>
#include <stdlib.h>
int f_014540(int p1, int p2, int p3);
int f_01e0c0();
int f_0580a0(int p1);
int f_058210(int p1, int p2, int p3);
int f_058dc0(int p1, int p2, int p3);
int f_0595f0(int p1);
int f_059630(int p1);
int f_059660(int p1);
int f_059780();
int f_059780(int p);
int f_068f40();
int f_09a140(int p1, int p2);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0bf820(int p1, ...);
int f_0ce7c0(int p1, int p2);
int f_0ce7e0(int p1, int p2);
int f_0d2f90(int p1, int p2);
int f_0d37e0();
int f_0d5b50(int p1);
int f_0da910(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_0da990(int p1, int p2);
int f_0dacc0(int p1);
int f_13fc70(int p1, int p2);
int f_13fcd0(int p1, int p2);







int f_05e320(int p1, int p2, int p3);
int f_05e420(int p1, int p2);

int f_0d3860();
int f_0d2710();

int f_0d26e0();
int f_061b10(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
int f_060ae0(int p1, int p2, int p3);
int f_0d3870();
int f_0d3770();
int f_061cd0(int p1, int p2);

int f_0d37b0();
int f_0d3780();
int f_0d2e70();
int f_0591c0(int p1, int p2);
int f_0f1580(int p1);
int f_0f16f0(int p1, int p2, int p3, int p4);
int f_0f16b0(int p1, int p2);
int f_0e93f0(int p1, int p2, int p3);

int f_133fe0(int p1, int p2, int p3);
int f_133fe0(int p1, int p2);

extern char d_1a169c[];
extern char d_1a16bc[];
extern char d_1a16d4[];
extern unsigned short d_1a16cc;
extern signed char d_1a16cd;
extern signed char d_1a16ce;
extern signed char d_1a16cf;
extern signed char d_1a16d0;
extern signed char d_1a16d1;
extern char d_1a16ca;
struct T7 { int v[7]; };
extern T7 d_1a1738;
extern int d_1a34e0;
extern int d_1a965c;
extern int d_1bc760;
extern int d_1bcabc;
extern int d_1bcac0;
extern int d_1bcac4;
extern short d_1bcac8;
extern unsigned short d_1bd762;
extern short d_1bd766;
extern volatile int d_1bf4e8;
extern int d_1bf514;
extern int d_1bf51c;
extern int d_1bf520;
extern int d_1bf524;
extern int d_1bfdb8;
extern int d_1c0c4c;
extern char d_1c14c4[];

extern unsigned short d_1c20fe;
extern unsigned short d_1c2100;
extern unsigned short d_1c2102;
extern short d_1c2198;
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c38b0[];
#define O98 ((int)((char*)&d_1c2098))
#define O64 ((int)d_1c2c64)
#define O14C4 ((int)d_1c14c4)

union Q { int l; struct { unsigned short lo, hi; } w; };
struct E { int off; int len; };
struct D {
  unsigned short n;        // 0
  unsigned short cur;      // 2
  char *text;              // 4
  char pad8[8];            // 8
  signed char c10;         // 0x10
  unsigned char c11;       // 0x11
  char name[0x15];         // 0x12
  unsigned char b27[1];    // 0x27
  signed char b28[7];      // 0x28
  char pad2f[5];           // 0x2f
  Q q34;                   // 0x34
  Q q38;                   // 0x38
  E *tbl;                  // 0x3c
};
void f_057770(D *p);
void f_057a00(D *p);
void f_0574c0(D *p);
void f_057660(D *p);

//@ f_056d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die grafische Tagebuch-Ansicht, stellt die aktuell gewählte Tagebuchseite dar und
 *   verarbeitet die Benutzeraktionen zum Umblättern, Springen auf eine Seitenzahl, Suchen nach Stichwörtern,
 *   Schreiben eigener Notizen, Löschen von Einträgen und Schließen des Buchs.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Tagebuch-Objekt p sowie ein Startflag p2 (z.
 *   B. ob beim Öffnen geblättert/animiert werden soll) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->n enthält die Gesamtzahl der Tagebucheinträge, p->cur den aktuell
 *   aufgeschlagenen Eintrag (0 bis p->n - 1), und d_1bfdb8 verwaltet die Schaltflächenleiste des
 *   Tagebuchfensters.
 === Ende Beschreibung === */
void f_056d90(D *p, short p2)
{
  struct Loc { char buf[12]; int saved_q38; int first; int guard; int v18; } L;
  int saved_db8;
  short page;
  int z;

  L.v18 = ((int (*)(int))f_13fc70)(O14C4);
  L.saved_q38 = p->q38.l;
  saved_db8 = d_1bfdb8;
  ((int (*)(int))f_0ce7c0)((int)&L.guard);
  d_1c0c4c++;
  L.first = 1;
  d_1bcabc = *(volatile int *)&d_1bf520;
  d_1bcac0 = d_1bf524;
  *(short *)&d_1bcac4 = d_1bf51c;
  *(volatile short *)&d_1bf51c = 0;
  f_0d2f90(0, 1);
  p->q38.l = 1;
  f_09a140(0, 0x19);
  if (d_1bc760) f_01e0c0();
  f_0595f0((int)p);
  d_1c2198 = 1;
  p->q34.l = 0;
  {
    int w = (int)operator new(0x42, mark(d_1a169c, 0xa1));
    d_1bfdb8 = w ? f_0da910(w, 0x80006, 0x280005, 0x280002, 0x280004, 7, 0x17) : 0;
  }
  while (!p->q34.l) {
    if (d_1c2198) {
      int d = p2;
      if (d) {
        f_058dc0((int)p, d, 0);
        p2 = 0;
        { int rt = d_1bfdb8; d_1bfdb8 = rt; } // Haelt die Konfliktzahl fuer den 0x4f00-Vergleich
      } else {
        f_058dc0((int)p, (short)L.first, 0);
      }
      if (L.first) L.first = 0;
      d_1c2198 = 0;
    }
    d_1bf514 = (int)d_1a16d4;
    f_068f40();
    d_1bd766 = ((short (*)(int))f_0dacc0)(d_1bfdb8);
    *(volatile int *)&d_1bf514 = 0;
    if (d_1bd766 == 0x80 || d_1bd762 == 0x5200 || d_1bd762 == 0x1c0d) {
      f_057770(p);
    } else if (d_1bd766 == 0x82 || d_1bd762 == d_1c20fe) {
      f_057a00(p);
    } else if (d_1bd766 == 0x81 || d_1bd762 == d_1c2100) {
      f_0580a0((int)p);
    } else if (d_1bd766 == 0x84 || d_1bd762 == 0x5000 || d_1bd762 == 0x4b00) {
      if (p->cur > 0) {
        if (f_0d37e0()) p->cur = 0;
        else p->cur--;
        d_1c2198 = 1;
      }
    } else if (d_1bd766 == (short)0x7f || d_1bd762 == d_1c2102) {
      page = f_0bf7b0(O64, (short)strlen(itoa(p->n, L.buf, 10)), 0x8030055, 1, (short)p->n, (short)((p->cur >= (p->n >> 1)) ? 1 : p->n));
      if (page != -1 && p->cur != page - 1) {
        if (!page) page = 1;
        p->cur = page - 1;
        d_1c2198 = 1;
      }
    } else if (d_1bd766 == 0x85 || d_1bd762 == 0x4800 || d_1bd762 == 0x4d00) {
      if (f_0d37e0()) {
        { int n = (p->n & 0) ? 0 : p->n; /* Haelt n als Mehrblock-Web und cur in EAX */ if (p->cur < n - 1) {
          p->cur = p->n - 1;
          *(volatile short *)&d_1c2198 = 1;
        } }
      } else {
        if (p->cur < p->n - 1) {
          p->cur++;
          d_1c2198 = 1;
        } else if (f_0bf6f0(O64, 0x8030057) == 1) {
          f_057770(p);
          d_1c2198 = 1;
        }
      }
    } else if (d_1bd762 == 0x4700) {
      if (p->cur) {
        p->cur = 0;
        d_1c2198 = 1;
      }
    } else if (d_1bd766 == 0x83 || d_1bd762 == 0x5300) {
      f_0574c0(p);
    } else if (d_1bd762 == 0x4f00) {
      { int rt3 = d_1bfdb8; d_1bfdb8 = rt3; } // Haelt die Konfliktzahl fuer den 0x7f-Vergleich
      { if (p->cur != p->n - 1) {
        p->cur = p->n - 1;
        d_1c2198 = 1;
      } }
    } else if (d_1bd766 == 0x86 || d_1bd762 == 0x11b) {
      p->q34.l = 1;
    }
  }
  {
    int cw = d_1bfdb8;
    if (cw) operator delete((void *)f_0da990(cw, 0));
  }
  d_1bfdb8 = saved_db8;
  f_059630((int)p);
  p->q38.l = L.saved_q38;
  d_1bd766 = d_1bd762 = 0;
  d_1c2198 = 1;
  d_1bf520 = d_1bcabc;
  d_1bf524 = d_1bcac0;
  *(volatile short *)&d_1bf51c = *(short *)&d_1bcac4;
  f_13fcd0(O14C4, (short)L.v18);
  d_1c0c4c--;
  f_0ce7e0((int)&L.guard, 0);
}



//@ f_057220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt dem Tagebuch automatisch (etwa aus einem Dialog oder Quest-Ereignis heraus) oder nach
 *   einer Spielereingabe einen neuen Eintrag hinzu, aktualisiert die Offsettabelle in der Tagebuchdatei
 *   (0x40000000) und setzt die Blink-/Hinweis-Markierung für neue Tagebucheinträge.
 * - Eingaben und Rückgabe: Die Funktion erhält das Tagebuch-Objekt p, die Text- oder Ressourcenkennung p2 des
 *   neuen Eintrags sowie ein Flag p3 (eigene Spielernotiz vs. Spieltext) und gibt als int den Wert 1 zurück,
 *   wenn der Eintrag geschrieben wurde, sonst 0.
 * - Wichtige Variablen: Über f_058210 wird der neue Eintragstext formatiert, anschließend werden die
 *   Eintrags-Offsets p->tbl und der Text in der Tagebuchdatei (d_1a16bc, Dateikennung 0x40000000)
 *   fortgeschrieben und bei Erfolg d_1bcac8 = 1 gesetzt.
 === Ende Beschreibung === */
int f_057220(D *p, int p2, short p3)
{
  int v, v2, w, w2;
  short oldn, i;
  int cnt;
  int r = 0;

  if (p->q38.l > 0) {
    f_0595f0((int)p);
    f_059780((int)p);
    d_1a965c = (int)d_1a16bc;
    if (0 < ((RivaFileManager*)(O98))->f_1448b0( 0x40000000, 0x200)) {
      ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)p), 2)));
      ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)p->b27), 2)));
      ((RivaFileManager*)(O98))->f_1449a0();
      if (p->n) p->cur = p->n - 1;
      else p->cur = p->n;
      f_057660(p);
    }
    oldn = p->n;
    cnt = (short)f_058210((int)p, p2, (int)p3);
    if (0 < cnt) {
      d_1a965c = (int)d_1a16bc;
      if (0 < ((RivaFileManager*)(O98))->f_1448b0( 0x40000000, 0x222)) {
        ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)p), 2)));
        ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)p->b27), 2)));
        if (p->n == oldn) {
          int off = p->tbl[p->n - 1].off;
          v = off + cnt;
          ((RivaFileManager*)(O98))->f_144ab0( p->n * 4 + 4, 0);
          ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&v), 4)));
          ((RivaFileManager*)(O98))->f_144ab0( off, 0);
        } else if (p->n > 1) {
          v2 = cnt + 4;
          int n4 = p->n * 4;
          v2 += p->tbl[p->n - 2].off;
          v2 += p->tbl[p->n - 2].len;
          n4 += 4;
          ((RivaFileManager*)(O98))->f_144ab0( 4, 0);
          i = 0;
          do {
            p->tbl[i].off += 4;
            ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&p->tbl[i].off), 4)));
            i++;
          } while (i < p->n);
          ((RivaFileManager*)(O98))->f_144b70( n4,(void *)( (int)&v2), 4);
          ((RivaFileManager*)(O98))->f_144ab0( 0, 2);
        } else {
          w = 12;
          w2 = w + cnt;
          ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&w), 4)));
          ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&w2), 4)));
        }
        ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)p->text), cnt)));
        r = 1;
        ((RivaFileManager*)(O98))->f_1449a0();
      }
    }
    if (p->tbl) {
      delete p->tbl;
      p->tbl = 0;
    }
    d_1a965c = 0;
    f_059630((int)p);
  }
  if (r == 1) {
    *(unsigned char *)&d_1bcac8 = 1;
  }
  return r;
}


//@ f_0574c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht nach einer Sicherheitsabfrage den aktuell aufgeschlagenen Tagebucheintrag aus der
 *   Tagebuchdatei (sofern es sich nicht um den geschützten ersten Eintrag auf Seite 0 handelt) und passt alle
 *   nachfolgenden Dateioffsets an.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Tagebuch-Objekt p entgegen und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Bei p->cur == 0 wird die Fehlermeldung 0x803007c ausgegeben; andernfalls entfernt
 *   f_144bb0 den Textblock sowie den Offset-Eintrag aus der Tagebuchdatei und reduziert p->n um 1.
 === Ende Beschreibung === */
void f_0574c0(D *p)
{
  int local, len, off, r;
  short i, j;

  if (p->cur == 0) {
    f_0bf730(O64, 0x803007c);
  } else {
    r = f_0bf6f0(O64, 0x803007b);
    if (r == 1) {
      local = 0;
      f_057660(p);
      int c0 = (p->cur & 0) ? 0 : p->cur; // Haelt c0 in eigenem Register
      E *entry = p->tbl + c0;
      off = entry->off;
      len = entry->len;
      d_1a965c = (int)d_1a16bc;
      r = ((RivaFileManager*)(O98))->f_1448b0( 0x40000000, 0x222);
      if (0 < r) {
        ((RivaFileManager*)(O98))->f_144ab0( 4, 0);
        i = 0;
        for (i = 0; i <= p->cur; i++) {
          local = p->tbl[i].off - 4;
          ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&local), 4)));
        }
        j = p->cur + 2;
        for (; j <= p->n; j++) {
          E *tb = p->tbl;
          local = tb[j].off - len - 4;
          ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)&local), 4)));
        }
        ((RivaFileManager*)(O98))->f_144bb0( off, len);
        ((RivaFileManager*)(O98))->f_144bb0( (p->n << 2) + 4, 4);
        p->n = p->n - 1;
        ((RivaFileManager*)(O98))->f_144ab0( 0, 0);
        ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)p), 2)));
        ((RivaFileManager*)(O98))->f_1449a0();
        int n0 = p->n;
        int c1 = p->cur;
        int d1 = n0 - 1;
        if (c1 > d1) {
          p->cur = p->n - 1;
        }
        d_1c2198 = 1;
      }
      delete p->tbl;
      p->tbl = 0;
      d_1a965c = 0;
    }
  }
}

//@ f_057660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Offset-Tabelle aller vorhandenen Tagebucheinträge aus dem Kopf der Tagebuchdatei
 *   (0x40000000) ein und berechnet daraus Dateioffset und Textlänge jedes einzelnen Eintrags.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Tagebuch-Objekt p und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das dynamisch angelegte Array p->tbl speichert für jeden der p->n Einträge den
 *   Startoffset off und die aus der Differenz zum nächsten Offset berechnete Länge len.
 === Ende Beschreibung === */
void f_057660(D *p)
{
  short i = 0;
  unsigned long a = 0, b = 0;
  int *g = &d_1a965c;
  p->tbl = (E *)new (mark(d_1a169c, 0x20b)) char[p->n * 8 + 8];
  *g = (int)d_1a16bc;
  ((RivaFileManager*)(O98))->f_1448b0( 0x40000000, 0x200);
  ((RivaFileManager*)(O98))->f_144ab0( 4, 0);
  ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)&a), 4)));
  ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)&b), 4)));
  while (i < (int)p->n + 1) {
    p->tbl[i].off = a;
    p->tbl[i].len = b - a;
    a = b;
    i++;
    ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)&b), 4)));
  }
  ((RivaFileManager*)(O98))->f_1449a0();
}

//@ f_057750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht den Freigabe-/Sperrzähler des Tagebuchs um 1, damit automatische Tagebucheinträge
 *   protokolliert werden können.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Tagebuch-Objekt p entgegen und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Inkrementiert wird das 32-Bit-Feld p->q38.l.
 === Ende Beschreibung === */
void f_057750(D *p)
{
  ++p->q38.l;
}

//@ f_057760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den Freigabe-/Sperrzähler des Tagebuchs um 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Tagebuch-Objekt p entgegen und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Dekrementiert wird das 32-Bit-Feld p->q38.l.
 === Ende Beschreibung === */
void f_057760(D *p)
{
  --p->q38.l;
}

//@ f_057770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet auf einer leeren Tagebuchseite den mehrzeiligen Texteditor, mit dem der Spieler eine
 *   eigene Notiz (bis zu 2000 Zeichen) in das Tagebuch eintragen und abspeichern kann.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Tagebuch-Objekt p und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Ein 2000 Bytes großer Textpuffer buf nimmt die Eingabe über den Editor f_060ae0 auf; vor
 *   dem Speichern werden eingebettete Nullbytes der Zeilenstruktur durch @ (0x40) ersetzt und der Text über
 *   f_133fe0 und f_057220(p, r2, 1) als Spielernotiz gesichert.
 === Ende Beschreibung === */
void f_057770(D *p)
{
  char A_[0x48]; char B_[12];  signed char ch;
  struct Guard {
    int flag;
    Guard() { if (f_0d3860() == 1) { int one = 1; f_0d2710(); flag = one; } else flag = 0; }
    ~Guard() { if (flag == 1) f_0d26e0(); }
  };
  signed char *buf, *scan;
  short r, i;
  unsigned short j, k;
  int found, done, r2;

  buf = (signed char *)f_014540(2000, (int)d_1a169c, 0x244);
  p->cur = p->n;
  p->n = p->n + 1;
  f_058dc0((int)p, 2, 0);
  p->n = p->n - 1;
  memset(buf, 0, 2000);
  f_05e320((int)d_1c38b0, 0xbb, 0xfe);
  r = f_05e420((int)d_1c38b0, -1);
  ((int)(((RivaRasterImage*)((int)B_))->f_0fac80( 0xed, r)));
  { Guard guard;
    ((RivaRasterImage*)((int)B_))->f_0fafb0((void *)( d_1a34e0), 0x19, 0x4b);
  }
  f_061b10((int)A_, 0x12, 0xcc, 0x19, 0x2e, (int)B_, d_1a34e0, 0);
  f_060ae0((int)A_, (int)buf, (int)d_1a16d4);
  scan = buf;
  i = 0;
  found = 0;
  do {
    int c = scan[i]; if (c) found = 1;
    i++;
  } while (!found && i < (short)2000);
  if (found) {
    done = 0;
    while (done == 0) {
      r = f_0bf820(O64, 0x8030079, 2, 0x200001a8, 0x200001a9);
      switch (r) {
      case -1:
        f_060ae0((int)A_, (int)buf, 0);
        break;
      case 1:
        k = 1999;
        ch = 0x40;
        while (!buf[k]) k--;
        for (j = 0; j <= k + 1; j++) if (!buf[j]) buf[j] = ch;
        r2 = f_133fe0((int)d_1c3498, (int)buf);
        f_057220(p, r2, 1);
        done = 1;
        break;
      default: done = 1;
      }
    }
  }
  p->cur = p->n - 1;
  *(volatile short *)&d_1c2198 = 1;
  delete buf;
  f_0d3870();
  f_0d3770();
  f_0d3770();
  d_1bf4e8 = 0;
  f_061cd0((int)A_, 0);
  ((int)(((RivaRasterImage*)((int)B_))->f_0fad20( 0)));
}

//@ f_0579b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein 2000-Byte-Notizpuffer mindestens ein sichtbares Zeichen ungleich 0 enthält.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1 sowie den Pufferzeiger s und gibt
 *   als int den Wert 1 zurück, wenn der Puffer nicht leer ist, sonst 0.
 * - Wichtige Variablen: Die Schleife durchsucht bis zu 2000 Bytes in s nach dem ersten Byte != 0.
 === Ende Beschreibung === */
int f_0579b0(int p1, signed char *s)
{
  short i;
  int r, c;

  i = 0;
  r = 0;
  do {
    c = s[i]; if (c) r = 1;
    i++;
  } while (r == 0 && i < (short)2000);
  return r;
}

//@ f_057a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Stichwort- und Kategoriensuche im Tagebuch aus (nach Personen, Orten, Gegenständen,
 *   allgemeinen Stichwörtern oder eigenen Notizen), sammelt alle passenden Seitenindizes und lässt den Spieler
 *   durch die Trefferliste blättern oder verwaiste Stichwörter löschen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Tagebuch-Objekt p entgegen und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das Array l.arr20 sammelt die Seitennummern aller Treffer, p->c10 (signed char)
 *   speichert das Kategoriesymbol und p->c11 (unsigned char) die Stichwort-ID. Hinweis auf Originalfehler: In
 *   der Treffersuche (57d59-57d61) wird das Textbyte p->text[j] vorzeichenbehaftet (signed char, movsx ecx, byte
 *   ptr) erweitert, während p->c11 (unsigned char, xor ebx, ebx; mov bl, [ebp+0x11]) nullerweitert wird;
 *   Stichwort-IDs >= 128 (0x80..0xFF) können dadurch niemals gefunden werden und werden fälschlich als unbenutzt
 *   zum Löschen vorgeschlagen.
 === Ende Beschreibung === */
static inline void barrier15(D *p) { if(p) { int v=p->q34.l; p->q34.l=v; } } // Haelt die Lebensdauer von p->q34.l

void f_057a00(D *p)
{
  struct Rec { unsigned char c0; unsigned char c1; signed char c2; char name[20]; };
  struct Loc {
    T7 tbl;
    char *s1c;
    unsigned short *arr20;
    int obj24;
  } l;
  int done;
  short i;
  short i2;
  short r;
  short cnt = 0;
  signed char c3c = -1;
  short n = ((short (*)(D *))f_059660)(p);
  signed char mode;
  short len, j, res = 0, idx;
  int sz;
  Rec *tab;

  (void)&c3c; // Haelt c3c im Stapel-Slot
  l.tbl = d_1a1738;
  r = f_0bf820(O64, 0x8030058, (int)n,
               l.tbl.v[p->b28[0]], l.tbl.v[p->b28[1]], l.tbl.v[p->b28[2]], l.tbl.v[p->b28[3]],
               l.tbl.v[p->b28[4]], l.tbl.v[p->b28[5]], l.tbl.v[p->b28[6]]);
  if (r != -1) {
    switch (p->b28[r - 1]) {
    case 0: mode = *(signed char *)&d_1a16cc; break;
    case 1: mode = d_1a16cd; break;
    case 2: mode = d_1a16ce; break;
    case 3: mode = d_1a16cf; break;
    case 4: mode = d_1a16d0; break;
    case 5:
      c3c = d_1a16d0;
      mode = *(signed char *)&d_1a16cc;
      break;
    case 6: mode = 0; break;
    default: mode = -1; break;
    }
  } else {
    mode = -1;
  }
  if (mode != -1) {
    cnt = 0;
    {
      void *stamp=mark(d_1a169c, 0x2ec);
      done = 0;
      unsigned count=p->n;
      unsigned short *a = new (stamp) unsigned short[count];
      memset(l.arr20 = a, 0, p->n * 2);
    }
    if (!mode) {
      f_0d2f90(5, 1);
      p->c10 = -1;
      for (i = 0; ((i & 0) ? 0 : i) < p->n; i++) {
        if (f_0591c0((int)p, (unsigned short)i)) {
          j = 0;
          len = strlen(p->text);
          while (j < len) {
            if (((signed char *)p->text)[j] >= *(signed char *)&d_1a16cc &&
                ((signed char *)p->text)[j] <= d_1a16d1) {
              j += 2;
            }
            if (((signed char *)p->text)[j++] == *(signed char *)&d_1a16ca) {
              l.arr20[cnt++] = i;
              break;
            }
          }
        }
      }
      f_0d2e70();
      if (!cnt) {
        f_0bf730(O64, 0x8030074);
        done = 1;
      }
    } else {
      {
        int w = (int)operator new(0x2a, mark(d_1a169c, 0x323));
        if (w) l.obj24 = f_0f1580(w);
        else { int o = w; l.obj24 = o; }
      }
      char *dst=p->name;
      dst=((int)dst&0)?0:dst; // Haelt dst in eigenem Register-Web
      f_0e93f0((int)d_1c38b0, (int)(l.s1c = new (mark(d_1a169c, 0x324)) char[100]), 0x803004d);
      {
        char *s;
        res=f_0f16f0((barrier15(p),s=l.s1c,l.obj24),(int)l.s1c,mode,c3c);
        strcpy(dst, s);
      }
      delete l.s1c;
      {
        int o = l.obj24;
        if (o) operator delete((void *)f_0f16b0(o, 0));
      }
      int expanded = res;
      if (expanded != -1) {
        f_0d2f90(5, 1);
        p->c11 = res;
        expanded >>= 8;
        p->c10 = expanded;
        for (i2 = 0; ((i2 & 0) ? 0 : i2) < p->n; i2++) {
          if (f_0591c0((int)p, (unsigned short)i2)) {
{ int v1 = p->q34.l; p->q34.l = v1; } // Haelt die Listenlaenge ueber den Aufruf
            j = 0;
            len = strlen(p->text);
            while (j < len) {
              if (((signed char *)p->text)[j++] == p->c10) {
#if FIX_R084   /* R084: Stichwort-ID im Text als unsigned char lesen, damit IDs >= 128 gefunden werden */
                if (((unsigned char *)p->text)[j++] == p->c11) {
#else
                if (((signed char *)p->text)[j++] == p->c11) {
#endif
                  l.arr20[cnt++] = i2;
                  break;
                }
              }
            }
          }
        }
        f_0d2e70();
      } else {
        done = 1;
      }
    }
    if (!done && !(sz = cnt)) {
      if (f_0bf6f0(O64, 0x803007d) == 1) {
        short k;
        ((RivaFileManager*)(O98))->f_1448b0( 0x40080002, 0x200);
        sz = ((int)(((RivaFileManager*)(O98))->f_144a00()));
        tab = (Rec *)f_014540(sz, (int)d_1a169c, 0x365);
        ((int)(((RivaFileManager*)(O98))->f_144920((void *)( (int)tab), sz)));
        ((RivaFileManager*)(O98))->f_1449a0();
        k = 0;
        while (tab[k].c0 != p->c11 || tab[k].c2 != p->c10) k++;
        tab[k].c1 = 0;
        ((RivaFileManager*)(O98))->f_1448b0( 0x40080002, 0x201);
        ((int)(((RivaFileManager*)(O98))->f_144960((void *)( (int)tab), sz)));
        ((RivaFileManager*)(O98))->f_1449a0();
        delete tab;
      }
      done = 1;
    }
    { short t=(r&0)?0:r; r ^= t ^ t; } // Haelt die Wort-Registerwahl fuer r
    idx = 0;
    *(volatile short *)&d_1c2198 = 1; // Haelt die Planerkante vor der Schleife
    while (!done) {
      if (d_1c2198) {
        p->cur = l.arr20[idx];
        f_058dc0((int)p, 0, 0);
        f_0d3770();
        f_0d3770();
        r = 0;
        d_1c2198 = r;
      }
      f_068f40();
      if (cnt == 1) {
        if (d_1bd762 || f_0d37b0() || f_0d3780()) {
          if (d_1bd762 != 0x11b) {
            f_0bf730(O64, 0x8030078);
          }
          done = 1;
        }
      } else {
        if ((d_1bd762 == 0x4800 || d_1bd762 == 0x4d00) && idx < cnt - 1) {
{ int v0 = p->q34.l; p->q34.l = v0; } // Haelt die Listenlaenge im Zweig
          r = 1;
        } else if ((d_1bd762 == 0x5000 || d_1bd762 == 0x4b00) && idx > 0) {
          r = 2;
        } else if (d_1bd762 == 0x11b) {
          r = 3;
        } else if (d_1bd762 || f_0d37b0() || f_0d3780()) {
          if (idx == 0) {
            r = f_0bf820(O64, 0x8030062, 2, 0x8030063, 0x8030065);
            if (r == 2) r++;
          } else if (idx == cnt - 1) {
            r = f_0bf820(O64, 0x8030062, 2, 0x8030064, 0x8030065) + 1;
          } else {
            r = f_0bf820(O64, 0x8030062, 3, 0x8030063, 0x8030064, 0x8030065);
          }
        }
        if (r == 1) {
          if (idx < cnt - 1) {
            d_1c2198 = 1;
            idx++;
          }
        } else if (r == 2) {
          if (idx > 0) {
            d_1c2198 = 1;
            idx--;
          }
        } else if (r == 3) {
          done = 1;
        }
      }
    }
    delete l.arr20;
    p->c10 = p->c11 = 0;
    d_1c2198 = 1;
  }
  f_0d5b50(0);
}

