/* === Beschreibung (Katalog) ===
 * Einheit gz_13bb70_t1 (0x13BB70 - 0x13D490)
 *
 * Überblick
 *
 * Die Einheit gz_13bb70_t1 enthält die Nachschlagefunktionen für die Gegenstandskombinations- und
 * Einzelbenutzungstabellen sowie sämtliche Verzehr- und Einnahmeroutinen für Nahrung, Getränke, Heil- und
 * Giftkräuter, Eigenschaftselixiere und alchemistische Tränke. Hier werden sowohl das Essen und Trinken
 * (einschließlich Wasserschlauch-Stufen, Alkoholrausch und leerer Glasflaschen) als auch die komplexe Wirkung
 * jedes einzelnen Krauts und Zaubertranks auf Lebensenergie, Astralenergie, Krankheiten, Gifte und temporäre
 * Eigenschaftsmodifikatoren abgewickelt.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 5/8 gleich (suche.py 28.10.2026, Basis gz_13bb70_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 4 gleich (vorher 4), Rest 926 (vorher 928)
// gz_13bb70.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13BB70-0x13E140
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038c40(int p1);                                   // reg eax stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_040a40(int p1);                                   // reg eax stapel 0
int f_040da0(int p1);                                   // reg eax stapel 0
int f_040e00(int p1);                                   // reg eax stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                 // reg eax stapel 0
                                 // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
int f_043d10(int p1);                                   // reg eax stapel 0
int f_043d90(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_043e70(int p1);                                   // reg eax stapel 0
int f_043ea0(int p1);                                   // reg eax stapel 0
int f_043ed0(int p1);                                   // reg eax stapel 0
int f_043f30(int p1);                                   // reg eax stapel 0
int f_044220(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_0442b0(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044890(int p1, int p2);                           // reg eax edx stapel 0
int f_045190(int p1, int p2);                           // reg eax edx stapel 0
int f_0451c0(int p1, int p2);                           // reg eax edx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4840;                    // 0x1A4840
extern int d_1a4864;                    // 0x1A4864
extern int d_1a486e;                    // 0x1A486E
extern int d_1a487a;                    // 0x1A487A
extern int d_1a488a;                    // 0x1A488A
extern int d_1c0004;                    // 0x1C0004
extern int d_1c109c;                    // 0x1C109C
extern int d_1c10a8;                    // 0x1C10A8
extern int d_1c10ac;                    // 0x1C10AC
extern int d_1c10b0;                    // 0x1C10B0
extern int d_1c10bc;                    // 0x1C10BC
extern int d_1c10c4;                    // 0x1C10C4
extern int d_1c10d0;                    // 0x1C10D0
extern unsigned short d_1c1104;         // 0x1C1104
extern int d_1c1108;                    // 0x1C1108
extern int d_1c1110;                    // 0x1C1110
extern int d_1c1150;                    // 0x1C1150
extern int d_1c1154;                    // 0x1C1154
extern int d_1c2198;                    // 0x1C2198
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2a80;                    // 0x1C2A80
// --- eigene Funktionen (25), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct T6 { short a, b, c; };
extern T6 d_1a8e44[];
extern short d_1a933c[];
extern short d_1a934a[];
extern int d_1c2c40;
extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
extern char d_1c27a8[];
extern char d_1c38b0[];
struct Q { int f0; int r4; int r8; int rc; int f10; int f14; short f18; short f1a; };
struct O { int r0; char *a4; int r8; char *ac; char *a10; char *a14; int r18; int r1c; char *a20; char rest[24]; };
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int);
int f_1254a0(void *p1, int p2);
#define DT(x) f_1254a0(&x, 0)
int f_0d5040(int, int, int, int, int, int);
int f_149360(int, int *);









signed char f_043ac0(int, int);
signed char f_043a80(int, int);
signed char f_043e30(int);

short f_0d4c80(int);
short f_0d4b00(int);
short f_0d4ad0(int);


int f_133fe0(const void *, const void *);
int f_0e93f0(void *, void *, int);
int f_0e9300(void *, void *, int);
int f_0bf730(void *, int);
int f_0bf6c0(void *, int);
int f_0bf680(void *);
void f_13c340(Q *q);
void f_13cc50(Q *q);
#define ES(q) (*(int *)(d_1c2c40 + (q)->f1a * 4))
#define EI(q) (*(int *)((q)->f1a * 4 + d_1c2c40))
#define INL(n, s) f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084); if ((n) != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b); uVar7 = f_133fe0(d_1c3498, d_1c27a8); *(int *)(o.a10 + 4) = uVar7; *(int *)(o.a4 + 4) = (s);
#define TAIL(st, ts, msg) *(short *)(o.a14 + 2) = st; *(int *)(o.a10 + 4) = 0x1e010084; if (ts == 1) uVar10 = 0x20000194; else uVar10 = 0x1e010083; iVar11 = msg; *(int *)(o.a10 + 8) = uVar10;
//@ f_13bb70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die globale Gegenstandskombinationstabelle d_1aa70c nach einem Paar aus zwei
 *   Gegenstandskennungen (a1, a2) in beliebiger Reihenfolge und liefert den zugehörigen Aktionscode für die
 *   Sprungtabelle in use_t1. Wird in d_1aa70c kein passendes Paar gefunden, gibt die Funktion -1 zurück.
 * - Eingaben: Zwei 16-Bit-Gegenstandskennungen a1 und a2.
 * - Rückgabewert: Der 16-Bit-Aktionsindex (t->c) bei einem Treffer oder -1, wenn die beiden Gegenstände nicht
 *   direkt über die Tabelle kombinierbar sind.
 * - Wichtige Variablen:
 *   - t: Laufzeiger über die 6-Byte-Einträge (a, b, c) der mit -1 terminierten Kombinationstabelle d_1aa70c.
 === Ende Beschreibung === */
short f_13bb70(int a, short b, short c)
{
  short r = -1;
  short i = 0;
  for (;;) {
    if (d_1a8e44[i].a == -1 || r != -1) return r;
    if (b == d_1a8e44[i].a) {
      if (c == d_1a8e44[i].b) r = d_1a8e44[i].c;
    } else if (b == d_1a8e44[i].b) {
      if (c == d_1a8e44[i].a) r = d_1a8e44[i].c;
    }
    i++;
  }
}
//@ f_13bbd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die globale Einzelbenutzungstabelle d_1aa808 nach einer einzelnen
 *   Gegenstandskennung a1 und liefert den zugehörigen Aktionscode für die Sprungtabelle in use_t1. Ist der
 *   Gegenstand dort nicht verzeichnet, wird -1 zurückgegeben.
 * - Eingaben: Gegenstandskennung a1 (short).
 * - Rückgabewert: Der 16-Bit-Aktionsindex (t->b) oder -1 bei erfolgloser Suche.
 * - Wichtige Variablen:
 *   - t: Laufzeiger über die 4-Byte-Einträge (a, b) der mit -1 terminierten Tabelle d_1aa808.
 === Ende Beschreibung === */
int f_13bbd0(short x)
{
  int r = 0;
  short i;
  for (i = 0; i < 8; i++) {
    if (x == d_1a934a[i]) { r = 1; break; }
  }
  return r;
}
//@ f_13bc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft als Vorbedingung vor dem Verzehr von Speisen, Getränken, Kräutern oder Tränken, ob der
 *   Zielheld (p->f10) weder tot (f_03dd00) noch versteinert (f_03ddb0) ist.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_f10), dessen Feld f10 auf den Zielhelden zeigt.
 * - Rückgabewert: 1, wenn der Held lebt und nicht versteinert ist, sonst 0.
 * - Wichtige Variablen:
 *   - p->f10: Zeiger auf die Heldenstruktur des Empfängers.
 === Ende Beschreibung === */
int f_13bc00(short x)
{
  int r = 0;
  short i = 0;
  for (; i < (short)7; i++) {
    if (x == d_1a933c[i]) { r = 1; break; }
  }
  return r;
}
//@ f_13bc30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Essen und Trinken aller normalen Nahrungsmittel, Rationen und Getränke (u. a.
 *   *Proviantpaket* 0x2D, *Wasserschlauch* 0x1E/0xF1/0xF2, *Bier* 0x17, *Weinflasche* 0x5B, *Schnapsflasche*
 *   0x5C sowie Spezialtränke wie 0xB9 und 0x1AD). Prüft Hunger (f_03df30) und Durst (f_03df50) des Zielhelden
 *   (q->f10), stillt diese entsprechend über f_044880 bzw. f_0448d0, spielt Ess- oder Trinkgeräusche (0x1E0001 /
 *   0x1E0002) ab, stuft den *Wasserschlauch* schrittweise von voll (0x1E) über halbvoll (0xF1) und fast leer
 *   (0xF2) bis leer (0xF3) herab, löst bei Alkohol (0x17, 0x5B, 0x5C) die Trunkenheitsprobe f_040a40 aus und
 *   legt nach dem Austrinken einer Flasche eine leere *Glasflasche* (0x1F) ins Inventar (wobei durch einen
 *   Originalfehler auch beim Trinken von *Bier* 0x17 eine leere *Glasflasche* entsteht).
 * - Eingaben: Zeiger q auf den Benutzungskontext (s_use) mit dem verzehrenden Helden f10, dem besitzenden Helden
 *   f14, dem Inventarslot f18 und der Gegenstandskennung f1a.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - item: Gegenstandskennung (q->f1a) des verzehrten Nahrungsmittels oder Getränks.
 *   - msg: Ausgewählte Textkennung (0x1E01007E bis 0x1E010085 bzw. 0x1E0100DB) für die Rückmeldung an den
 *     Spieler.
 *   - o: Lokaler Meldungsparameterblock (s_o20), in dessen Textplatzhalter der Zielheld q->f10 eingetragen wird.
 === Ende Beschreibung === */
void f_13bc30(Q *q)
{
  struct Hero {
    static int get(Q *q) {
      int rt = d_1c2a80; d_1c2a80 = rt; // haelt die Registerfolge beim Listenplatz-Zugriff wie im Original
      return q->f10;
    }
  };
  int found = 0;
  short up, down;
  O o;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);

  if (f_042400((struct hero *)(q->f10)) == 4) {
    f_0bf730(d_1c2c64, 0x1e0100db);
  } else if (!f_045960(q->f10, q->f1a)) {
    if (q->f0) {
      *(int *)(o.a4 + 4) = q->f10;
      *(int *)(o.ac + 4) = (*(int **)&d_1c2c40)[q->f1a];
      *(short *)(o.a20 + 2) = 1;
      *(int *)(o.a10 + 4) = f_040e90(q->f10);
      f_0bf730(d_1c2c64, 0x20000106);
    }
  } else {
    if (((char)(f_042350((struct hero *)(q->f10)))) &&
        (((char)(f_0425f0((struct hero *)(q->f10)))) || ((char)(f_0424d0((struct hero *)(q->f10))))) &&
        !((char)(f_042470((struct hero *)(q->f10)))) &&
        !((char)(f_0424e0((struct hero *)(q->f10)))) &&
        !((char)(f_0425a0((struct hero *)(q->f10))))) {
      found = 1;
      if (q->f0) {
        int target = q->f14;
        if (!target || target == q->f10)
          target = f_038c40(d_1c0004);
        *(int *)(o.a4 + 4) = q->f10;
        *(int *)(o.a4 + 8) = target;
        f_0bf730(d_1c2c64, 0x1e0100c8);
      }
    }

    if (f_0d49b0(q->f10) || found) {
      int item_offset = q->f1a * sizeof(int);
      int *items = *(int **)&d_1c2c40;
      *(int **)&d_1c2c40 = items; // haelt die Tabellenbasis im Register wie im Original
      if (((RivaItemDefinition*)(*(int *)((char *)items + item_offset)))->f_0a7930()) {
        if ((signed char)((char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[q->f1a]))->f_0a78b0())) == 1) {
          int *food_items = *(int **)&d_1c2c40;
          *(int **)&d_1c2c40 = food_items; // haelt die Tabellenbasis vor der Indexberechnung
          short food = ((signed char)(((RivaItemDefinition*)(food_items[q->f1a]))->f_0a78a0()));
          food = (food & 0) ? (short)0 : food; // haelt den 16-Bit-Zwischenwert fuer das Aufrufargument
          f_045190(q->f10, food);
          if (q->f0)
            f_0bf730(d_1c2c64, 0x1e01006f);
          if (q->f1a != 0xb8)
            f_036300(q->f14, q->f18, 1);
        } else {
          if (!f_042d30((struct hero *)(q->f14), q->f18)) {
            f_0451c0(q->f10, ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[q->f1a]))->f_0a78a0())));
            if (q->f0)
              f_0bf730(d_1c2c64, 0x1e010070);
            int item = q->f1a;
            if ((int)item == 0x1e) {
              if (f_042da0((struct hero *)(q->f14), q->f18)) {
                f_042d60((struct hero *)(q->f14), q->f18, 1);
                f_042dd0((struct hero *)(q->f14), q->f18, 0);
              } else
                f_042dd0((struct hero *)(q->f14), q->f18, 1);
            } else if (item == 0x5c || item == 0x5b || item == 0x17) {
              f_040a40(q->f10);
              f_036300(q->f14, q->f18, 1);
#if FIX_R033
              if (item != 0x17)
                f_036a10(q->f14, 0x1f, 1, q->f18, 0);
#else
              f_036a10(q->f14, 0x1f, 1, q->f18, 0);
#endif
            } else if (item == 0x142) {
              ((int)(f_042930((struct hero *)(q->f10), 0)));
              f_040a40(q->f10);
            } else if (item != 0xb9) {
              f_036300(q->f14, q->f18, 1);
              if (q->f1a != 0x17)
                f_036a10(q->f14, 0x1f, 1, q->f18, 0);
            }
          } else if (q->f0)
            f_0bf730(d_1c2c64, 0x1e010071);
        }
        if (d_1c2a80 == 0x30000) {
          *(volatile short *)&d_1c2198 = 1; // verhindert Tail-Merging beim Setzen des Flags vor dem Destruktor
          DT(o);
          return;
        }
      } else if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[q->f1a]))->f_0a7910()) {
        int direction = (signed char)((char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[q->f1a]))->f_0a78b0()));
        if (direction == 0) {
          if ((short)f_149360(q->f1a, &d_1a486e) != -1) {
            if (q->f0)
              f_0bf730(d_1c2c64, 0x1e010072);
          } else if ((short)f_149360(q->f1a, &d_1a4864) != -1) {
            if (q->f0)
              f_0bf730(d_1c2c64, 0x1e010073);
          } else {
            f_036300(q->f14, q->f18, 1);
            *(char *)&d_1c21b4 = 0;
            f_13c340(q);
          }
        } else {
          short up_value = f_149360(q->f1a, &d_1a487a);
          up = up_value;
          short down_value = f_149360(q->f1a, &d_1a488a);
          down = down_value;
          if ((short)up_value != -1) {
                found = (found & 0) ? 0 : found; // haelt die Registerbelegung von found in diesem Zweig wie im Original
            if (((signed char *)((char *)(f_0429c0((struct hero *)(q->f10), (short)up_value))))[1] >
                ((signed char *)((char *)(f_0429c0((struct hero *)(q->f10), (short)up_value))))[0]) {
              *(int *)(o.a4 + 4) = q->f10;
              *(int *)(o.a10 + 4) = (unsigned int)up + 0x20000143;
              if (q->f0)
                f_0bf730(d_1c2c64, 0x1e0100cb);
            } else {
              f_036300(q->f14, q->f18, 1);
              f_036a10(q->f14, 0x1f, 1, q->f18, 0);
              short amount = f_0d4c80(q->f10);
              f_0d5040(q->f10, amount, 0x1518, (signed char)up, 5, 0);
            }
          } else if ((short)down_value != -1) {
            if (((signed char *)((char *)(f_0429c0((struct hero *)(Hero::get(q)), (short)down_value))))[1] <
                ((signed char *)((char *)(f_0429c0((struct hero *)(Hero::get(q)), (short)down_value))))[0]) {
              *(int *)(o.a4 + 4) = q->f10;
              *(int *)(o.a10 + 4) = (unsigned int)down + 0x20000143;
              if (q->f0)
                f_0bf730(d_1c2c64, 0x1e0100cd);
            } else {
              f_036300(q->f14, q->f18, 1);
              f_036a10(q->f14, 0x2a, 1, q->f18, 0);
              short amount = f_0d4c80(q->f10);
              f_0d5040(q->f10, amount, 0x1518, (signed char)down, -7, 0);
            }
          } else if ((short)f_149360(q->f1a, &d_1a4840) != -1 &&
                     f_042400((struct hero *)(q->f10))) {
            if (q->f0)
              f_0bf730(d_1c2c64, 0x1e0100b4);
          } else {
            f_036300(q->f14, q->f18, 1);
            f_13cc50(q);
          }
        }
        if (d_1c2a80 == 0x30000) {
          *(volatile short *)&d_1c2198 = 1; // verhindert Tail-Merging beim Setzen des Flags vor dem Destruktor
          DT(o);
            d_1c109c = (d_1c109c & 0) ? 0 : d_1c109c; // trennt die beiden Return-Pfade nach dem Destruktor wie im Original
          return;
        }
      } else if (q->f0)
        f_0bf730(d_1c2c64, 0x1e01006d);
    } else if (((char)(f_0424d0((struct hero *)(q->f10)))) || ((char)(f_0425f0((struct hero *)(q->f10))))) {
      *(int *)(o.a4 + 4) = q->f10;
      if (q->f0)
        f_0bf730(d_1c2c64, 0x1e0100c0);
    } else {
      *(int *)(o.a4 + 4) = q->f10;
      if (q->f0)
        f_0bf730(d_1c2c64, 0x1e0100a1);
    }
  }
  DT(o);
}
//@ f_13c290
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hilfsfunktion für Eigenschaftselixiere und Tränke: Legt ein temporäres Modifikator-Ereignis
 *   (Buff oder Debuff) für eine bestimmte Charaktereigenschaft (stat) des Helden hero über die Dauer dur mit der
 *   Veränderung delta an, startet das Ereignis über f_041cb0 und trägt es in die aktive Modifikatorliste (hero +
 *   0x17B) des Helden ein.
 * - Eingaben: Heldenzeiger hero, Eigenschaftsindex stat (int), Wirkungsdauer dur (int) und Eigenschaftsänderung
 *   delta (signed char, z. B. +2 oder -2).
 * - Rückgabewert: Der Rückgabewert des Listeneintrags aus f_035160 (int).
 * - Wichtige Variablen:
 *   - p: Mit f_012a40(0x0E) reservierter 14-Byte-Modifikatorblock (s_buff), der über f_041b40 initialisiert
 *     wird.
 === Ende Beschreibung === */
int f_13c290(short p)
{
  if (p != 0x37) {
    if (p == 0x38) return 2;
    if (p == 0x39) return 3;
    if (p == 0x3a) return 4;
    if (p == 0x8e) return 8;
    if (p == 0x90) return 6;
  }
  return 1;
}
//@ f_13c2e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der mit -1 terminierten Kräuter-Kennungstabelle d_1aa8d8, ob es sich bei der
 *   Gegenstandskennung id um ein einnehmbares Kraut oder Pflanzenpräparat handelt.
 * - Eingaben: Gegenstandskennung id (short).
 * - Rückgabewert: 1, wenn id in der Kräutertabelle d_1aa8d8 enthalten ist, sonst 0.
 * - Wichtige Variablen:
 *   - p: Laufzeiger über die 16-Bit-Kräuterkennungen in d_1aa8d8.
 === Ende Beschreibung === */
void f_13c2e0(O *o, short n, int s)
{
  int r;
  f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084);
  if (n != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b);
  r = f_133fe0(d_1c3498, d_1c27a8);
  *(int *)(o->a10 + 4) = r;
  *(int *)(o->a4 + 4) = s;
  *(short *)(o->a14 + 2) = n;
}
//@ f_13c340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Essen sämtlicher Heil-, Gift- und Zauberkräuter (u. a. *Einbeere* 0x3E,
 *   *Wirselkraut* 0x3F/0x7C, *Eitriger Krötenschemel* 0x40, *Gulmondblatt* 0x41, *Tarnele* 0x42, *Vierblättrige
 *   Einbeere* 0x7A, *Belmart* 0x7B, *Menchal-Kaktus* 0x7D, *Atmon* 0x7E, *Olginwurz* 0x7F, *Joruga* 0x80,
 *   *Kajubo* 0x81, *Rauschgurke* 0x82, *Mandragora* 0x83, *Schwarzer Lotos* 0xFA, *Donf* 0xFD). Spielt das
 *   Essgeräusch 0x1E0001 ab, prüft über f_040cb0, ob der Held bereits unter einer frischen Kräuterwirkung steht
 *   (0x1E010086), verbraucht das Kraut aus dem Inventar (f_042c40) und wendet je nach Pflanze
 *   Lebensenergie-Heilung (f_044260), Giftschaden (f_044300), Entgiftung (f_03dd20/f_044000), Krankheitsheilung,
 *   Ausdauer-/Rauschzustände (f_0409d0) oder temporäre Eigenschaftsboni an.
 * - Eingaben: Zeiger q auf den Benutzungskontext (s_use) mit dem einnehmenden Helden f10, dem besitzenden Helden
 *   f14, dem Inventarslot f18 und der Krautkennung f1a.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - msg: Ausgewählte Textkennung (0x1E010087 bis 0x1E010099 bzw. 0x1E0100CE/0x1E0100CF) für die
 *     Wirkungsbeschreibung des jeweiligen Krauts.
 *   - dmg: Ausgewürfelter Giftschaden bei giftigen Pflanzen (z. B. f_145760(3, 0x12) beim *Eitrigen
 *     Krötenschemel* 0x40 oder f_145760(10, 0x3C) beim *Schwarzen Lotos* 0xFA), der nach der Textausgabe über
 *     f_044300 abgezogen wird.
 *   - r: Temporärer Zufallswurf zur Bestimmung von Heil- oder Schadenspunkten.
 === Ende Beschreibung === */
void f_13c340(Q *q)
{
  short id;
  short i;
  short n;
  short extra;
  short diff = 0;
  short v20;
  int msg;
  O o;
  signed char saved;
#define S42970(x) f_042970((struct hero *)(x))
#define S42960(x) f_042960((struct hero *)(x))

  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  msg = 0;
  extra = 0;
  id = q->f1a;
  switch (id) {
  case 0x3f:
    {
      signed char *p = (signed char *)((char *)(f_0429c0((struct hero *)(q->f10), 6)));
      *(int *)(o.a4 + 4) = q->f10;
      if (p[0] < p[1]) {
        f_0bf730(d_1c2c64, 0x1e0100ad);
      } else {
        int t;
        f_0bf730(d_1c2c64, 0x1e010074);
        n = f_0d4c80(q->f10);
        f_0d5040(q->f10, n, 0xfd20, 6, t = 2, 0);
        f_044890(q->f10, 2);
      }
    }
    break;
  case 0x3c:
    n = f_1457e0(6);
    diff = S42970(q->f10) - S42960(q->f10);
    if (n > diff) n = diff;
    f_044890(q->f10, n);
    { char *destination = o.a14;
      o.a14 = destination; // haelt die Registerfolge beim Beschreiben von o.a14 wie im Original
      *(short *)(destination + 2) = n; }
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010075;
    break;
  case 0x7b:
    if (f_043ea0(q->f10) == 0) {
      if ((v20 = f_0d4b00(q->f10)) != (short)0 && v20 <= 5) f_040e00(q->f10);
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x1fa40, 0, 1, 0x1a);
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e010076;
    } else {
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e0100d4;
    }
    break;
  case 0x7d:
    if (f_043ed0(q->f10) == 0) {
      if ((v20 = f_0d4b00(q->f10)) != (short)0 && v20 <= 10) f_040e00(q->f10);
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x1fa40, 0, 2, 0x1b);
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e010076;
    } else {
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e0100d5;
    }
    break;
  case 0x7f:
    for (i = 9; i < 19; i++) {
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 27000, (signed char)i, 2, 1);
    }
    *(int *)(o.a4 + 4) = q->f10;
    msg = 0x1e010077;
    break;
  case 0x3d:
    n = 10;
    diff = S42970(q->f10) - S42960(q->f10);
    if (diff < n) n = diff;
    f_044890(q->f10, n);
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010078;
    break;
  case 0x10b:
    n = f_145760(10, 18);
    diff = S42970(q->f10) - S42960(q->f10);
    if (diff < n) n = diff;
    f_044890(q->f10, n);
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010078;
    break;
  case 0x135:
    n = f_145850(2, 6, 0);
    diff = S42970(q->f10) - S42960(q->f10);
    if (diff < n) n = diff;
    f_044890(q->f10, n);
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010075;
    break;
  case 0x136:
    n = f_145850(2, 6, 0);
    extra = n;
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e0100a3;
    break;
  case 0x40:
    if (f_043e70(q->f10) == 0) {
      int t, effect;
      i = f_0d4c80(q->f10);
      f_0d5040(q->f10, i, 0xa8c0, 0, t = 1, effect = 0x17);
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e0100b9;
    } else {
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e0100d3;
    }
    break;
  case 0x83:
    *(int *)(o.a4 + 4) = q->f10;
    msg = 0x1e0100ba;
    break;
  case 0x183:
    {
      short d;
      n = i = 40;
      d = diff = S42970(q->f10) - S42960(q->f10);
      if (diff < n) n = d;
    }
    f_044890(q->f10, n);
    diff = f_0429b0((struct hero *)(q->f10)) - f_0429a0((struct hero *)(q->f10));
    if (diff < i) i = diff;
    f_0442b0(q->f10, i);
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    *(short *)(o.a14 + 4) = i;
    *(int *)(o.a10 + 12) = 0x1e010084;
    *(int *)(o.a10 + 16) = i == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010007;
    break;
  case 0x182:
    n = i = 20;
    diff = S42970(q->f10) - S42960(q->f10);
    if (diff < n) n = diff;
    f_044890(q->f10, n);
    diff = f_0429b0((struct hero *)(q->f10)) - f_0429a0((struct hero *)(q->f10));
    if (diff < i) i = diff;
    f_0442b0(q->f10, i);
    *(short *)(o.a14 + 2) = n;
    *(int *)(o.a10 + 4) = 0x1e010084;
    *(int *)(o.a10 + 8) = n == 1 ? 0x20000194 : 0x1e010083;
    *(short *)(o.a14 + 4) = i;
    *(int *)(o.a10 + 12) = 0x1e010084;
    *(int *)(o.a10 + 16) = i == 1 ? 0x20000194 : 0x1e010083;
    msg = 0x1e010008;
    break;
  case 0x173:
    *(int *)(o.a4 + 4) = q->f10;
    if (f_043ac0(q->f10, 6) < f_043a80(q->f10, 6) &&
        f_043ac0(q->f10, 0) < f_043a80(q->f10, 0) &&
        f_043ac0(q->f10, 1) > f_043a80(q->f10, 1)) {
      msg = 0x1e010004;
    } else {
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x2a30, 6, 3, 0);
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x5460, 0, 5, 0);
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x5460, 1, -5, 0);
      msg = 0x1e010003;
    }
    break;
  case 0x171:
    {
      *(int *)(o.a4 + 4) = q->f10;
      if (f_043d10(q->f10)) {
      msg = 0x1e010005;
    } else {
      saved = f_043e30(q->f10);
      f_043e20(q->f10, 1);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 0, 1, 20);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 2, 3, 0);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 1, 3, 0);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 5, -2, 0);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 3, -2, 0);
      f_0d5040(q->f10, f_0d4c80(q->f10), 0x7e90, 4, -2, 0);
      f_043e20(q->f10, saved);
      msg = 0x1e010006;
    }
    }
    break;
  case 0x198:
    { int hero = q->f10;
      hero = (hero & 0) ? 0 : hero; // haelt den Zeiger im selben Register wie im Original
      f_044220(hero, 30); }
    break;
  case 0x7c:
    if (f_0d4ad0(q->f10) == 4) {
      f_040da0(q->f10);
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x204000d;
    }
    break;
  }
  if (q->f0 && msg) f_0bf730(d_1c2c64, msg);
  if (extra) f_044300(q->f10, extra);
  f_1254a0(&o, 0);
}
//@ f_13cc50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Trinken aller alchemistischen Elixiere, Heil- und Zaubertränke sowie Gifte
 *   (0x92 *Heiltrank*, 0x93 *Starker Heiltrank*, 0x94-0x9A *MU/KL/CH/FF/GE/IN/KK-Elixier*, 0x9B *Zaubertrank*,
 *   0x9C *Starker Zaubertrank*, 0xA6 *Expurgicum*, 0xA8 *Vomicum*, 0xEC *Wundkur*, 0xED *Schlaftrunk*, 0xEE
 *   *Starker Schlaftrunk*, 0xEF *Gegengift*, 0xF0 *Krankheitselixier*, 0xFB/0xFC *Schlechte
 *   Eigenschaftselixiere*, 0xFE *Kukris*, 0xFF *Bannstaub*). Spielt das Trinkgeräusch 0x1E0002 ab, verbraucht
 *   die volle Phiole (f_042c40), legt dafür eine leere *Glasflasche* (0x1F, oder bei 0xFE/0xFF den Behälter
 *   0x20) in das Inventar des spendenden Helden q->f14 und wendet die jeweilige Trankwirkung sowie die
 *   Textmeldung (0x1E0100AE bis 0x1E0100BE) auf den trinkenden Helden q->f10 an (mit einem Originalfehler bei
 *   0xA6 *Expurgicum*, bei dem der Schaden fälschlich q->f14 statt q->f10 zugefügt wird).
 * - Eingaben: Zeiger q auf den Benutzungskontext (s_use) mit dem trinkenden Helden f10, dem spendenden Helden
 *   f14, dem Inventarslot f18 und der Trankkennung f1a.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - extra: Nachgelagerter Schadensbetrag (z. B. 5000 beim tödlichen Gift *Kukris* 0xFE), der nach dem
 *     Schließen des Meldungsfensters über f_044300(q->f10, extra) auf den Trinkenden angewendet wird.
 *   - msg: Textkennung der Trankwirkung für das Dialogfenster f_119040.
 *   - empty: Kennung des zurückbleibenden Leerbehälters (0x1F *Glasflasche* für normale Elixiere, 0x20 für
 *     0xFE/0xFF).
 === Ende Beschreibung === */
void f_13cc50(Q *q)
{
  short vc;
  short extra;
  short id;
  short v18;
  short n;
  int msg;
  O o;

  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  msg = 0;
  extra = 0;
  id = q->f1a;

  switch (id) {
  case 0x91:
    n = f_042970((struct hero *)(q->f10));
    n -= f_042960((struct hero *)(q->f10));
    if (n > 10) n = 10;
    f_044890(q->f10, n);
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    {
      int held_91 = q->f10;
      short zahl_91 = n;
      int text_91;
      f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084);
      if (zahl_91 != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b);
      text_91 = f_133fe0(d_1c3498, d_1c27a8);
      *(int *)(o.a10 + 4) = text_91;
      *(int *)(o.a4 + 4) = held_91;
      *(short *)(o.a14 + 2) = zahl_91;
    }
    msg = 0x1e01007c;
    break;

  case 0x92:
    n = f_145850(1, 0x14, 10);
    if (f_042970((struct hero *)(q->f10)) - f_042960((struct hero *)(q->f10)) < n)
      n = f_042970((struct hero *)(q->f10)) - f_042960((struct hero *)(q->f10));
    f_044890(q->f10, n);
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    {
      int held_92 = q->f10;
      short zahl_92 = n;
      int text_92;
      f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084);
      if (zahl_92 != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b);
      text_92 = f_133fe0(d_1c3498, d_1c27a8);
      *(int *)(o.a10 + 4) = text_92;
      *(int *)(o.a4 + 4) = held_92;
      *(short *)(o.a14 + 2) = zahl_92;
    }
    msg = 0x1e01007c;
    break;

  case 0x128:
    n = 0x28;
    if (f_042970((struct hero *)(q->f10)) - f_042960((struct hero *)(q->f10)) < n)
      n = f_042970((struct hero *)(q->f10)) - f_042960((struct hero *)(q->f10));
    f_044890(q->f10, n);
    f_036a10(q->f14, 0x2a, 1, q->f18, 0);
    {
      short zahl_128 = n;
      int held_128 = q->f10;
      int text_128;
      f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084);
      if (zahl_128 != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b);
      text_128 = f_133fe0(d_1c3498, d_1c27a8);
      *(int *)(o.a10 + 4) = text_128;
      *(int *)(o.a4 + 4) = held_128;
      *(short *)(o.a14 + 2) = zahl_128;
    }
    msg = 0x1e01007c;
    break;

  case 0x10c:
    extra = 0x1e;
    f_036a10(q->f14, 0x2a, 1, q->f18, 0);
    { int heldstore0=q->f10; *(int *)(o.a4+4)=heldstore0; }
    msg = 0x1e0100a2;
    break;

  case 0xec:
    { int kopie2=d_1c10ac; d_1c10ac=kopie2; } // steuert die Konfliktlistenreihenfolge der Register in f_13cc50
    f_043210((struct hero *)(q->f10));
    f_044890(q->f10, f_042970((struct hero *)(q->f10)));
    vc = f_0d4ad0(q->f10);
    if (vc == 2 || vc == 3) f_040da0(q->f10);
    v18 = f_0d4b00(q->f10);
    if (v18 && v18 < 7) f_040e00(q->f10);
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    { int heldstore1=q->f10; *(int *)(o.a4+4)=heldstore1; }
    if (!f_0d4ad0(q->f10) && !f_0d4b00(q->f10))
      msg = 0x1e01007d;
    else
      msg = 0x1e0100c9;
    break;

  case 0xed:
    if (!f_043f30(q->f10)) {
      n = f_0d4c80(q->f10);
      f_0d5040(q->f10, n, 0x1fa40, 0, 1, 0x19);
      msg = 0x1e01007e;
    } else {
      msg = 0x1e0100d6;
    }
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    { int heldstore2=q->f10; *(int *)(o.a4+4)=heldstore2; }
    break;

  case 0x9a:
  case 0x9b:
  case 0x196:
    n = f_0429b0((struct hero *)(q->f10)) - f_0429a0((struct hero *)(q->f10));
    if (f_042a10((struct hero *)(q->f10)) && n != 0) {
      if (q->f1a == 0x196) {
        if (n > 0x32) n = 0x32;
      } else if (q->f1a == 0x9b) {
        if (n > 0x1e) n = 0x1e;
      }
      if (q->f1a == 0x9a) {
        if (n > 10) n = 10;
      }
      f_0442b0(q->f10, n);
      {
      short zahl_9a = n;
      int held_9a = q->f10;
      int text_9a;
      f_0e93f0(d_1c38b0, d_1c27a8, 0x1e010084);
      if (zahl_9a != 1) f_0e9300(d_1c38b0, d_1c27a8, 0x1e01007b);
      text_9a = f_133fe0(d_1c3498, d_1c27a8);
      *(int *)(o.a10 + 4) = text_9a;
      *(int *)(o.a4 + 4) = held_9a;
      *(short *)(o.a14 + 2) = zahl_9a;
    }
      msg = 0x1e01007f;
    } else {
      msg = 0x1e010080;
    }
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    break;

  case 0xb4:
    v18 = f_0d4b00(q->f10);
    *(int *)(o.a4 + 4) = q->f10;
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    if (v18) {
      if (v18 < 5) {
        f_040e00(q->f10);
        msg = 0x1e0100d9;
      } else {
        msg = 0x1e0100bb;
      }
    } else {
      msg = 0x1e0100bd;
    }
    break;

  case 0x155:
    f_043d90(q->f10, 1);
    { int heldstore4=q->f10; *(int *)(o.a4+4)=heldstore4; }
    msg = 0x1e0100c7;
    break;

  case 0xdf:
    if ((vc = f_0d4ad0(q->f10)) != 0) {
      do {
        f_040da0(q->f10);
        { int kopie0=d_1c109c; int kopie1=d_1c10a8; d_1c109c=kopie0; d_1c10a8=kopie1; } // haelt die Registerfolge in der Schleife wie im Original
      } while ((vc = f_0d4ad0(q->f10)) != 0);
      *(int *)(o.a4 + 4) = q->f10;
      msg = 0x1e010082;
    } else {
      msg = 0x1e010080;
    }
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    break;

  case 0x3b:
    { int t_ = (int)(q->f10); f_040900(t_, 5); }
    extra = f_145760(1, 0x14);
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    { int heldstore6=q->f10; q->f10=heldstore6; /* haelt den Feldwert im Register; Store wird nach Registervergabe geloescht */ *(int *)(o.a4+4)=heldstore6; }
    msg = 0x1e0100af;
    break;

  case 0x8d:
    f_040900(q->f10, 7);
    extra = f_145760(10, 0x28);
    *(int *)(o.a4 + 4) = q->f10;
    msg = 0x1e0100b0;
    break;

  case 0x8f:
    *(int *)(o.a4 + 4) = q->f10;
    if (f_042a10((struct hero *)(q->f10)) && f_0429a0((struct hero *)(q->f10)) > 0) {
      f_044230(q->f10, (short)f_145760(10, 0x14));
      msg = 0x1e0100b1;
    } else {
      msg = 0x1e0100b2;
    }
    break;

  case 0xa6:
    f_036a10(q->f14, 0x2a, 1, q->f18, 0);
    { int heldstore9=q->f10; *(int *)(o.a4+4)=heldstore9; }
#if FIX_R033
    f_044300(q->f10, (short)f_145760(5, 0x19));
#else
    f_044300(q->f14, (short)f_145760(5, 0x19));
#endif
    msg = 0x1e0100b6;
    break;

  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x8e:
  case 0x90:
    f_040900(q->f10, (short)f_13c290(q->f1a));
    f_036a10(q->f14, 0x1f, 1, q->f18, 0);
    *(int *)(o.a4 + 4) = q->f10;
    msg = 0x1e0100b6;
    break;
  }

  f_0bf6c0(d_1c2c64, 5);
  if (q->f0 != 0) f_0bf730(d_1c2c64, msg);
  f_0bf680(d_1c2c64);
  if (extra) f_044300(q->f10, extra);
  DT(o);
}
