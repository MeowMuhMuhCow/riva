/* === Beschreibung (Katalog) ===
 * Einheit gz_13fef0_t1 (0x13FEF0 - 0x140220)
 *
 * Überblick
 *
 * Die Einheit gz_13fef0_t1 bildet den zweiten Teil der virtuellen RAM-Disk (virtdisk.cpp) und implementiert die
 * virtuellen Dateioperationen zum Öffnen, kompletten oder stückweisen Lesen, Schließen, Größenabfragen und
 * Positionieren (seek / tell) einer Ressource. Je nachdem, ob im aktuellen Datei-Index v->cur das höchste Bit
 * (0x8000, Makro HI80) gesetzt ist, bedienen diese Funktionen die Leseanfragen blitzschnell per memcpy direkt
 * aus dem RAM-Puffer des Cache-Slots oder reichen sie an das unterliegende physische Laufwerk v->d (realdisk)
 * weiter.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 17/22 gleich (suche.py 26.10.2026, Basis gz_13fef0_P1.CPP)
// gz_13fef0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13FEF0-0x1407A0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int f_099ea0();
typedef int GP;
int f_0bd350(int a, int b, int c);


int f_0d3780();

int f_0d38b0(void *p);
int f_0d38d0(void *p);
int f_0d3950(int a, int b, int c, int d);
int f_0d2f40(int a, int b);



void *f_145234(void *p, void *q);
extern int d_1a34e0;
extern int d_1bbc7c;
extern int d_1bf4e8;
extern char d_1bf4ed;
extern signed char d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fe;
struct E { unsigned key; short s; char *ptr; int n; };
struct V { unsigned vp; E tab[200]; void *d; short cur; short st[10]; short cnt; unsigned sel; int pos; int lim; };
struct S { short x, y, h, a, b, p, t, w, m; GP g0, g1, g2, g3; };
#define VT(d,o) (*(int **)(d))[(o)/4]
typedef int (*PF_i_u)(void *, unsigned);
typedef int (*PF_i_uu)(void *, unsigned, int);
typedef void (*PF_v_v)(void *);
typedef void (*PF_v_u)(void *, unsigned);
typedef unsigned (*PF_u_vp)(void *, void *);
typedef unsigned (*PF_u_vpu)(void *, void *, unsigned);
typedef unsigned (*PF_u_v)(void *);
typedef int (*PF_i_ii)(void *, int, int);
unsigned short f_13faf0(V *v, unsigned key);
int f_13fa50(E *e);
int f_13fdd0(V *v, unsigned p2, unsigned p3);
void f_1407a0(S *s, int p);
#define DELP(x) operator delete((void *)(x));

#define HI80 (((unsigned char *)&v->cur)[1] & 0x80)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_13fef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet eine Ressource anhand ihrer Kennung key in der virtuellen RAM-Disk v und setzt den
 *   Lesezeiger v->pos auf 0. Befindet sich die Datei bereits geladen im RAM-Cache (f_13faf0 liefert einen Index
 *   mit gesetztem Bit 0x8000), wird lediglich v->cur auf diesen Slot gesetzt und sofort 1 zurückgegeben; steht
 *   sie noch ohne Puffer in der Tabelle oder existiert sie im unterliegenden Archiv (VT + 0x0C), sucht die
 *   Funktion einen freien Slot in v->tab und lädt bzw. öffnet die Ressource über f_13fdd0.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk, Ressourcenkennung key (unsigned) und ein ungenutzter dritter
 *   Parameter (unused).
 * - Rückgabewert: 1, wenn die Ressource erfolgreich geöffnet oder im Cache aktiviert wurde, sonst 0.
 * - Wichtige Variablen:
 *   - r: Ergebnis der Cache-Suche f_13faf0(v, key).
 *   - found: Index des ersten freien Cache-Slots (0-199) bei einer neu aufzunehmenden Datei.
 === Ende Beschreibung === */
int f_13fef0(V *v, unsigned key, int unused)
{
  unsigned r = f_13faf0(v, key);
  int ret = 0;
  short found;
  E *tab;
  short i;
  int occupied;
  if (r != 0xffff) {
    v->sel = key;
    if (r & 0x8000) {
      ret = 1;
      v->cur = r;
      goto L;
    }
    ret = f_13fdd0(v, (short)r, key);
    goto L;
  } else {
    if (((PF_i_u)VT(v->d, 0xc))(v->d, key) == 1) goto INIT;
    goto L;
UPDATE:
    i++;
    if (i < (short)200) goto BODY;
    goto AFTER;
INIT:
    found = -1;
    tab = v->tab;
    i = 0;
BODY:
    occupied = tab[(short)i].key != 0;
    if (occupied) goto UPDATE;
    found = i;
AFTER:
    if ((unsigned short)found == (unsigned)-1) goto L;
    r = (short)found;
  }
  ret = f_13fdd0(v, (short)found, key);
L:
  v->pos = 0;
  return ret;
}
//@ f_13ffa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt eine Ressource p2 am Cache vorbei direkt über das übergebene Laufwerksobjekt d in den
 *   Zielpuffer p3, indem nacheinander die virtuellen Methoden +0x14 (Öffnen mit Modus 0x200), +0x1C
 *   (Komplettlesen nach p3) und +0x28 (Schließen) aufgerufen werden.
 * - Eingaben: Zeiger d auf ein Laufwerksobjekt, Ressourcenkennung p2 (unsigned) und Zielpufferadresse p3
 *   (unsigned).
 * - Rückgabewert: 1 bei erfolgreichem Lesevorgang, sonst 0.
 * - Wichtige Variablen:
 *   - ret: Erfolgsflag (1 nach erfolgreichem Öffnen und Lesen, sonst 0).
 === Ende Beschreibung === */
int f_13ffa0(void *d, unsigned p2, unsigned p3)
{
  int ret = 0;
  if (((PF_i_uu)VT(d, 0x14))(d, p2, 0x200) == 1) {
    ((PF_v_u)VT(d, 0x1c))(d, p3);
    ret = 1;
    ((PF_v_v)VT(d, 0x28))(d);
  }
  return ret;
}
//@ f_13ffe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den gesamten Inhalt der aktuell geöffneten Ressource in den Zielpuffer p2. Liegt die
 *   Datei im RAM-Cache (HI80), kopiert die Funktion alle t->n Bytes per memcpy aus t->ptr nach p2; andernfalls
 *   ruft sie die virtuelle Komplettlesemethode +0x1C des unterliegenden Laufwerks v->d auf und aktualisiert
 *   anschließend v->pos.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Zielpufferzeiger p2 (void *).
 * - Rückgabewert: Anzahl der gelesenen Bytes (unsigned).
 * - Wichtige Variablen:
 *   - idx: Bereinigter Cache-Slot-Index (v->cur & 0x7FFF).
 *   - t: Zeiger auf den aktiven Cache-Eintrag v->tab[idx].
 === Ende Beschreibung === */
unsigned f_13ffe0(V *v, void *p2)
{
  int n;
  int ret;
  E *t;
  unsigned idx;
  if (HI80) {
    idx = (unsigned short)(v->cur & 0x7fff);
    t = v->tab + idx;
    n = t->n;
    ret = n;
    memcpy(p2, t->ptr, n);
  } else {
    ret = ((PF_u_vp)VT(v->d, 0x1c))(v->d, p2);
  }
  v->pos = ret;
  return ret;
}
//@ f_140050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest p3 Bytes ab der aktuellen Leseposition v->pos aus der geöffneten Ressource in den Puffer
 *   p2 und rückt v->pos um die gelesene Byteanzahl weiter. Bei einer im RAM-Cache liegenden Datei (HI80) erfolgt
 *   das Lesen per memcpy ab t->ptr + v->pos, sonst über die virtuelle Lesemethode +0x20 des Laufwerks v->d.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk, Zielpuffer p2 (void *) und zu lesende Byteanzahl p3
 *   (unsigned).
 * - Rückgabewert: Anzahl der tatsächlich gelesenen Bytes (unsigned).
 * - Wichtige Variablen:
 *   - idx, t: Index und Zeiger des aktiven Cache-Eintrags.
 === Ende Beschreibung === */
unsigned f_140050(V *v, void *p2, unsigned p3)
{
  unsigned idx;
  E *t;
  if (HI80) {
    idx = (unsigned short)(v->cur & 0x7fff);
    t = v->tab + idx;
    memcpy(p2, t->ptr + v->pos, p3);
  } else {
    p3 = ((PF_u_vpu)VT(v->d, 0x20))(v->d, p2, p3);
  }
  v->pos = v->pos + p3;
  return p3;
}
//@ f_1400c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt die aktuell in der virtuellen RAM-Disk geöffnete Datei: Wurde sie aus dem RAM-Cache
 *   bedient (HI80), bleibt der Cache-Puffer erhalten und es wird sofort 1 gemeldet; kam sie direkt vom Laufwerk
 *   v->d, wird dessen virtuelle Schließmethode +0x28 aufgerufen. In beiden Fällen werden v->cur = 0xFFFF und
 *   v->pos = 0 zurückgesetzt.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: 1 (bzw. Rückgabewert des Laufwerks-Schließaufrufs).
 * - Wichtige Variablen:
 *   - r: Rückgabewert des Schließvorgangs.
 === Ende Beschreibung === */
int f_1400c0(V *v)
{
  int r;
  if (HI80) r = 1;
  else r = ((PF_u_v)VT(v->d, 0x28))(v->d);
  v->cur = 0xffff;
  v->pos = 0;
  return r;
}
//@ f_140100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die Gesamtgröße der aktuell geöffneten Datei in Bytes: Bei einer im RAM-Cache
 *   liegenden Datei (HI80) wird die im Slot gespeicherte Länge n zurückgegeben, andernfalls die virtuelle
 *   Größenabfrage +0x30 des Laufwerks v->d aufgerufen.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Dateigröße in Bytes (int).
 * - Wichtige Variablen:
 *   - c: Aktueller Slot-Index (v->cur).
 === Ende Beschreibung === */
int f_140100(V *v)
{
  if (HI80) {
    short c = v->cur;
    v = (V *)((char *)v + 4);
    return ((E *)v)[(unsigned short)(c & 0x7fff)].n;
  }
  return ((PF_u_v)VT(v->d, 0x30))(v->d);
}
//@ f_140140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt die Dateigröße einer beliebigen Ressource p2 über die virtuelle Methode +0x34 des
 *   unterliegenden Laufwerks v->d ab, ohne dass die Datei zuvor geöffnet sein muss.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Ressourcenkennung p2 (unsigned).
 * - Rückgabewert: Rückgabewert der virtuellen Methode +0x34 (Dateigröße in Bytes).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_140140(V *v, unsigned p2)
{
  ((PF_v_u)VT(v->d, 0x34))(v->d, p2);
}
//@ f_140150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle Leseposition (tell) innerhalb der geöffneten Datei zurück: Bei einer Datei
 *   im RAM-Cache (HI80) wird direkt v->pos geliefert, andernfalls die virtuelle Positionsabfrage +0x3C des
 *   unterliegenden Laufwerks v->d.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Aktueller Byte-Offset innerhalb der Datei (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_140150(V *v)
{
  if (HI80) return v->pos;
  return ((PF_u_v)VT(v->d, 0x3c))(v->d);
}
//@ f_1401f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vom Compiler erzeugter skalarer bzw. vektorisierter Destruktor-Helfer für die virtdisk-Klasse:
 *   Ruft bei gesetztem Bit 4 in fl den Array-Destruktor f_145234 über die Member-Elemente und anschließend
 *   f_145254 auf, oder gibt bei gesetztem Bit 2 den Objektspeicher über f_014710 frei.
 * - Eingaben: Objektzeiger p (void *) und Destruktor-Steuerflags fl (unsigned).
 * - Rückgabewert: Der übergebene Objektzeiger p.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
inline void *f_1401f0(void *p, unsigned fl)
{
  extern void f_145254(void *);
  extern void f_014710(void *);
  if (fl & 4) {
    f_145254(f_145234(p, &d_1bbc7c));
    return p;
  }
  if (fl & 2) f_014710(p);
  return p;
}
inline int f_1401e0();
//@ f_140170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verschiebt den Lesezeiger (seek) innerhalb der geöffneten Datei um den Offset p2 gemäß dem
 *   Modus p3 (0 = SEEK_SET ab Dateianfang, 1 = SEEK_CUR relativ zur aktuellen Position v->pos, 2 = SEEK_END
 *   relativ zum Dateiende t->n). Bei einer gecachten Datei (HI80) wird v->pos direkt im Speicher neu berechnet,
 *   sonst über die virtuelle Seek-Methode +0x40 des Laufwerks v->d.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk, Byte-Offset p2 (int) und Positionierungsmodus p3 (short).
 * - Rückgabewert: Die neue Leseposition v->pos (int).
 * - Wichtige Variablen:
 *   - n: Gesamtgröße der gecachten Datei (t->n) für die Berechnung bei SEEK_END (p3 == 2).
 === Ende Beschreibung === */
int f_140170(V *v, int p2, short p3)
{
  unsigned idx;
  E *t;
  int n;
  if (HI80) {
    idx = (unsigned short)(v->cur & 0x7fff);
    t = v->tab + idx;
    n = t->n;
    if (p3 == 0) {
      v->pos = p2;
    } else if (p3 == 2) {
      v->pos = n + p2;
    } else {
      v->pos = v->pos + p2;
    }
  } else {
    v->pos = ((PF_i_ii)VT(v->d, 0x40))(v->d, p2, p3);
  }
  (void)f_1401e0; (void)f_1401f0;
  return v->pos;
}
//@ f_1401e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere virtuelle Standardmethode der virtdisk-Klassenhierarchie, die konstant 0 zurückgibt.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
inline int f_1401e0() { return 0; }
