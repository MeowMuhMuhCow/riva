/* === Beschreibung (Katalog) ===
 * Einheit gz_13aa40 (0x13AA40 - 0x13B180)
 *
 * Überblick
 *
 * Die Einheit gz_13aa40 bildet den sechsten Abschnitt des Objektbenutzungssystems (use.cpp) und enthält die
 * Aktionshandler 18 bis 24 der zentralen Sprungtabelle aus use_t1. Sie implementiert den gegenseitigen Abgleich
 * zweier Rezept- oder Notizbücher mit Schreibzeug, einen magischen Reparaturgegenstand für beschädigte Waffen
 * der gesamten Heldengruppe, das *Amulett der Magier* und den *Stadtplan von Riva*, das Schnitzen eines
 * *Blasrohrs* aus einem *Pflanzenstiel*, das Spielen der *Blumenflöte* sowie das Einsetzen eines grünen oder
 * orangen *Prismas* in einen *Stab* im achten Dungeon.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 5/6 gleich (suche.py 26.10.2026, Basis gz_13aa40_P1.CPP)
// gz_13aa40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13AA40-0x13B180
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);

struct SO { int a; int *p; char c[8]; int *q; char d[40]; };
struct IT { char a[16]; int o; char b[4]; short s18; short s1a; short s1c; short s1e; };
struct VTB { char a[0x14]; void (*f)(void *); };
struct VO { char a[8]; VTB *vt; };
#define U1A (*(unsigned short *)&p->s1a)
#define U1E (*(unsigned short *)&p->s1e)
int f_035180(int p1, int p2);
int f_036300(int p1, int p2, int p3);
int f_036a10(int p1, int p2, int p3, int p4, int p5);
int f_038c40(int p1);
int f_0391b0(int p1, int p2);







int f_0bf6f0(const char *p1, int p2);
int f_0bf730(const char *p1, int p2);
short f_0de820(int p1);
unsigned short f_0dd440(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_1348e0(IT *p1, int p2, int p3);
int f_135d40(IT *p1);
int f_135d70(IT *p1, int p2, int p3);
short f_1364f0(IT *p1, int p2);
int f_136870(IT *p1, int p2, int p3, int p4);
int f_1369b0(IT *p1, int p2, int p3, int p4);
void f_147323(void *p, int a, int b, int c, int d, int e, int f);
void h_147323(void *p, int a, int b, int c, int d, int e, int f);
#pragma aux h_147323 modify exact [eax ebx ecx edx esp];
void g_147323(void *p, int a, int b, int c, int d, int e, int f);
int i_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
struct CO { char c[4]; int f_147323(int a, int b, int c, int d, int e, int f); };
extern CO d_x2edc;
extern int d_1a9820;
extern signed char d_1a441f[];
extern int d_1bc940;
extern VO *d_1bd6c0;
extern int d_1c0004;
extern int d_1c1078;
extern int d_1c107c;

extern char d_1c2c64[];
extern char d_1c2edc[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];

//@ f_13aa40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 18 der Objektbenutzungstabelle: Gleicht zwei verschiedene Bücher (0xBF
 *   *Rezeptbuch*, 0x1DC *Buch* oder 0x1D *Notizbuch*) miteinander ab, sodass alle Rezepte und Notizen in beiden
 *   Büchern auf denselben Stand gebracht werden. Sucht dazu über f_1364f0(p, -1) nach einem *Schreibzeug* im
 *   Inventar der Gruppe, vereinigt bei Erfolg über f_136380 die gespeicherten Einträge in beiden Richtungen,
 *   zieht über f_042c40 eine Ladung vom *Schreibzeug* ab und gibt die Textmeldung 0x1E01009D aus (oder
 *   0x1E0100A1, wenn kein *Schreibzeug* vorhanden ist).
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den beiden Buch-Gegenstandskennungen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - k: Gepackte Fundstelle des *Schreibzeugs* aus f_1364f0 (untere 16 Bit Inventarslot, obere 16 Bit
 *     Heldenindex; -1, falls keines gefunden wurde).
 *   - o: Lokaler Meldungsparameterblock (s_o20), in dessen Textplatzhalter a4 + 4 die Kennung des ersten Buches
 *     (p->s1a) für die Erfolgsmeldung 0x1E01009D eingetragen wird.
 === Ende Beschreibung === */
void f_13aa40(IT *p)
{
  SO o;
  short p2 = f_1364f0(p, -1);
  if (p2 != -1) {
    if (p->s1a == p->s1e) {
      switch (U1A) {
      case 0x1d: f_0bf730(d_1c2c64, 0x1e010091); break;
      case 0xbf: f_136870(p, p2, p->s18, p->s1c); break;
      case 0x1dc: f_1369b0(p, p2, p->s18, p->s1c); break;
      }
    } else {
      if (f_135d70(p, 0xbf, 0x1dc) == 1) {
        f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
        o.p[1] = p->o;
        f_0bf730(d_1c2c64, 0x1e010090);
        f_1254a0(&o, 0);
      } else {
        if (p->s1e == 0x1d) f_135d40(p);
        switch (U1E) {
        case 0xbf:
          f_1348e0(p, p->s18, 0xbf);
          f_136870(p, p2, p->s18, p->s1c);
          break;
        case 0x1dc:
          f_1348e0(p, p->s18, 0x1dc);
          f_1369b0(p, p2, p->s18, p->s1c);
          break;
        }
      }
    }
  }
}

//@ f_13abb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 19 der Objektbenutzungstabelle: Benutzt ein magisches Reparaturwerkzeug (oder
 *   Pflegemittel), das alle beschädigten, nicht stapelbaren und nicht magisch unzerstörbaren Waffen im Gepäck
 *   und an den Körperplätzen sämtlicher Helden der aktiven Gruppe (d_1c0004) auf einen zufälligen niedrigeren
 *   Bruchfaktor (0 bis t, mindestens um 1 besser als zuvor) zurücksetzt. Spielt bei mindestens einer reparierten
 *   Waffe den Soundeffekt 0x1E0000 ab, verbraucht über f_042c40 eine Ladung des benutzten Gegenstands und gibt
 *   die Erfolgsmeldung 0x1E0100C6 aus; wurde im gesamten Gruppeninventar keine einzige reparierbare Waffe
 *   gefunden, erscheint stattdessen die Meldung 0x1E0100C7.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit dem Heldenzeiger f14 und dem Inventarslot s18 des
 *   benutzten Reparaturgegenstands.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - found: Zähler der erfolgreich reparierten Waffen über alle Helden der aktiven Gruppe hinweg.
 *   - h: Zeiger auf den aktuell untersuchten Helden aus der Gruppeniteration (f_038c40 / f_0391b0).
 *   - slot: Schleifenzähler (0 bis 30) über alle 31 Ausrüstungs- und Rucksackplätze des jeweiligen Helden.
 *   - id: Gegenstandskennung im untersuchten Inventarslot (f_0367c0), die über f_0a7990 (ist Waffe), !f_0a7950
 *     (nicht stapelbar) und !f_042bb0 (nicht unzerstörbar/magisch) gefiltert wird.
 *   - t: Ausgewürfelter neuer Ziel-Bruchfaktor (f_145760(0, 3)), auf den der aktuelle Bruchfaktor (f_042be0)
 *     gesenkt wird, sofern dieser größer als t + 1 ist.
 === Ende Beschreibung === */
void f_13abb0(IT *p)
{
  SO o;
  short i;
  int cur;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  cur = f_038c40(d_1c0004);
  do {
    for (i = 0; i < 0x1f; i++) {
      short s = f_042a60((struct hero *)(cur), i);
      if (s) {
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7990()) {
          if (!((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a7950()) {
            if (!f_042bb0((struct hero *)(cur), i)) {
              int t = d_1a441f[((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[s]))->f_0a78a0())) * 10];
              if (f_042be0((struct hero *)(cur), i) > t + 1) f_042c40((struct hero *)(cur), i);
            }
          }
        }
      }
    }
    cur = f_0391b0(d_1c0004, cur);
  } while (cur != f_038c40(d_1c0004));
  int id490=d_1a9820; h_147323(d_1c2edc, 0x1e0000, 0x7fff, 0x8000, id490, 0, 1);
  o.p[1] = p->o;
  f_0bf730(d_1c2c64, 0x1e0100c6);
  f_1254a0(&o, 0);
}

//@ f_13acf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 20 der Objektbenutzungstabelle: Ruft ohne weitere Vorbedingungen die globale
 *   Ereignis- oder Schnittstellenfunktion f_0646b0 auf.
 * - Eingaben: Zeiger auf den Benutzungskontext (wird nicht ausgewertet).
 * - Rückgabewert: Rückgabewert von f_0646b0 (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_0646b0(IT *p);
void f_13acf0(IT *p) { f_0646b0(p); }

//@ f_13ad00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 21 der Objektbenutzungstabelle: Behandelt die Benutzung des *Amuletts der
 *   Magier* (0x176) sowie des *Stadtplans* (0x16A). Wird das *Amulett der Magier* innerhalb der Dungeons 10 oder
 *   11 (d_1bc944 == 10 || d_1bc944 == 11, z. B. Magierturm) aktiviert und die Rückfrage 0x1E010009 vom Spieler
 *   bestätigt, setzt die Funktion das Verlassen-Flag d_1bc940 = 1 und hinterlegt den Auslöser p->o in d_1c1078;
 *   beim Lesen des *Stadtplans* (0x16A) wird der Beschreibungstext 0x1E0100DC angezeigt, andernfalls die
 *   Standardmeldung 0x1E010079.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit der Gegenstandskennung s1a und dem Auslöserfeld o.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bc944: Kennung des aktuellen Dungeons (10 oder 11 für die beiden Bereiche, in denen das *Amulett der
 *     Magier* anspricht).
 *   - d_1bc940, d_1c1078: Globale Steuerflags für den ausgelösten Ortswechsel bzw. Teleport durch das Amulett.
 === Ende Beschreibung === */
void f_13ad00(IT *p)
{
  SO o;
  short s;
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  switch (U1A) {
  case 0x176:
    s = f_0de820(d_1c0004);
    if (s == 10 || s == 11) {
      int r = f_0bf6f0(d_1c2c64, 0x1e010009);
      if (r == 1) { d_1bc940 = 1; d_1c1078 = p->o; }
    }
    break;
  case 0x16a:
    o.p[1] = p->o;
    f_0bf730(d_1c2c64, 0x1e0100dc);
    f_1254a0(&o, 0);
    return;
  }
  f_1254a0(&o, 0);
}

//@ f_13adb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 22 der Objektbenutzungstabelle: Schnitzt aus einem *Pflanzenstiel* (0x17B)
 *   mithilfe eines Messers oder Dolches ein *Blasrohr* (0x17D). Bestimmt zunächst, welcher der beiden
 *   kombinierten Gegenstände (s1a oder s1e) der *Pflanzenstiel* ist, legt über f_036a10 ein *Blasrohr* (0x17D)
 *   in das Inventar des betreffenden Helden, verbraucht über f_042c40 den *Pflanzenstiel* und zeigt die
 *   Erfolgsmeldung 0x1E01000A an.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den beiden beteiligten Heldenzeigern f10 und f14,
 *   den Slots s18 und s1c sowie den Gegenstandskennungen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p->s1a, p->s1e: Gegenstandskennungen der beiden kombinierten Objekte, anhand derer entschieden wird, ob
 *     der *Pflanzenstiel* (0x17B) im ersten Slot (s18 bei Held f14) oder im zweiten Slot (s1c bei Held f10)
 *     liegt.
 === Ende Beschreibung === */
void f_13adb0(IT *p)
{
  SO o;
  short s;
  if (p->s1a == 0x17b) s = p->s18; else s = p->s1c;
  f_036300(p->o, s, 1);
  f_036a10(p->o, 0x17d, 1, s, 0);
  f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
  o.p[1] = p->o;
  f_0bf730(d_1c2c64, 0x1e01000a);
  f_1254a0(&o, 0);
}

//@ f_13ae40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 23 der Objektbenutzungstabelle: Spielt die *Blumenflöte* (0x17C), indem zuerst
 *   der Flötenklang 0x1E0003 über f_136050 ausgegeben und anschließend (sofern sich die Gruppe in einem Dungeon
 *   mit aktivem Level-Objekt d_1bd6c0 befindet) die virtuelle Ereignismethode d_1bd6c0->vt->f mit dem
 *   Gegenstandskontext aufgerufen wird.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use), dessen eingebetteter Aktionsblock p->o an den
 *   Level-Handler übergeben wird.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd6c0: Globales Zeigerfeld auf das aktive Dungeon-/Level-Steuerobjekt, das auf das Flötenspiel
 *     reagiert.
 === Ende Beschreibung === */
void f_13ae40(IT *p)
{
  int id;
  if (p->s1a == 0x17c) {
    g_147323(d_1c2edc, 0x1e0003, 0x7fff, 0x8000, (id = *(int *)&d_1a9820), 0, 1);
    if (d_1bd6c0 != 0) {
      d_1c107c = p->o;
      d_1bd6c0->vt->f(d_1bd6c0);
    }
  }
}

//@ f_13aea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktionshandler 24 der Objektbenutzungstabelle: Kombiniert im achten Dungeon (d_1bc944 == 8,
 *   außerhalb der gesperrten Kartenposition d_1c0020 == 0xCB) einen *Stab* (0x105) mit einem grünen *Prisma*
 *   (0x1B6) oder einem orangen *Prisma* (0x1B7), oder tauscht an einem bereits zusammengesetzten *Leuchtstab
 *   (grün)* (0x106) bzw. *Leuchtstab (orange)* (0x107) das eingesetzte Prisma gegen das jeweils andere aus.
 *   Verbraucht die Ausgangsgegenstände über f_042c40, erzeugt den entsprechenden *Leuchtstab* (0x106 oder 0x107)
 *   sowie bei einem Tausch das freiwerdende *Prisma* (0x1B6 oder 0x1B7) über f_036a10 und gibt die passende
 *   Meldung (0x1E01000F, 0x1E010010 oder außerhalb des Dungeons die Ablehnung 0x1E01000E) aus.
 * - Eingaben: Zeiger p auf den Benutzungskontext (s_use) mit den beiden Heldenzeigern f10 und f14, den Slots s18
 *   und s1c sowie den Gegenstandskennungen s1a und s1e.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Kennung des Gegenstands im ersten Slot (p->s1a), der im ersten Zweig der *Stab* (0x105) bzw.
 *     *Leuchtstab* (0x106/0x107) und im symmetrischen zweiten Zweig das *Prisma* (0x1B6/0x1B7) ist.
 *   - s2: Kennung des Gegenstands im zweiten Slot (p->s1e).
 *   - o: Lokaler Meldungsparameterblock (s_o20), in dessen Textplatzhalter a4 + 4 die Kennung des eingesetzten
 *     Prismas für die Textmeldung eingetragen wird.
 === Ende Beschreibung === */
void f_13aea0(IT *p)
{
  SO o;
  int id;
  if (p->s1e == -1) {
    id = 0x1e0100da;
  } else {
    if (f_0de820(d_1c0004) != 8) {
      id = 0x1e01001f;
    } else {
      f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
      if (f_0dd440(d_1c0004) != 0xcb) {
        if ((p->s1a == 0x105 && p->s1e == 0x1b6) || (p->s1a == 0x1b6 && p->s1e == 0x105)) {
          o.q[1] = 0x1e010021;
          f_0bf730(d_1c2c64, 0x1e010022);
          if (p->s1a == 0x105) {
            f_035180(p->o, p->s18);
            f_036a10(p->o, 0x107, 1, p->s18, 0);
            p->s1a = 0x107;
            f_035180(p->o, p->s1c);
            f_036a10(p->o, 0x1b7, 1, p->s1c, 0);
            p->s1e = 0x1b7;
          } else {
            f_035180(p->o, p->s18);
            f_036a10(p->o, 0x1b7, 1, p->s18, 0);
            p->s1a = 0x1b7;
            f_035180(p->o, p->s1c);
            f_036a10(p->o, 0x107, 1, p->s1c, 0);
            p->s1e = 0x107;
          }
        } else if ((p->s1a == 0x105 && p->s1e == 0x1b7) || (p->s1a == 0x1b7 && p->s1e == 0x105)) {
          o.q[1] = 0x1e010020;
          f_0bf730(d_1c2c64, 0x1e010022);
          if (p->s1a == 0x105) {
            f_035180(p->o, p->s18);
            f_036a10(p->o, 0x106, 1, p->s18, 0);
            p->s1a = 0x106;
            f_035180(p->o, p->s1c);
            f_036a10(p->o, 0x1b6, 1, p->s1c, 0);
            p->s1e = 0x1b6;
          } else {
            f_035180(p->o, p->s18);
            f_036a10(p->o, 0x1b6, 1, p->s18, 0);
            p->s1a = 0x1b6;
            f_035180(p->o, p->s1c);
            f_036a10(p->o, 0x106, 1, p->s1c, 0);
            p->s1e = 0x106;
          }
        } else {
          f_0bf730(d_1c2c64, 0x1e01001f);
        }
      } else {
        f_0bf730(d_1c2c64, 0x1e01001f);
      }
      f_1254a0(&o, 0);
      return;
    }
  }
  f_0bf730(d_1c2c64, id);
}
