/* === Beschreibung (Katalog) ===
 * Einheit virtdisk (0x13F9D0 - 0x13FEF0)
 *
 * Überblick
 *
 * Die Einheit virtdisk (virtdisk.cpp) implementiert das virtuelle Dateicache-System (*Virtual Disk*), das sich
 * zwischen die Archivdatei-Leseroutinen (realdisk / ALF-Archive) und die Spiel-Engine schaltet. Es verwaltet ein
 * Array von 200 Cache-Slots (tab[200]) sowie einen 10-stufigen Markierungsstapel (st[10]), mit dem das Spiel
 * beim Betreten eines Szenarios oder Dialogs eine Speicher-Marke setzen (f_13fc70), geladene Ressourcen im RAM
 * halten (f_13fdd0) und beim Verlassen alle seit dieser Marke geladenen Einträge gezielt wieder freigeben kann
 * (f_13fcd0).
 === Ende Beschreibung === */
// P3 15/18 gleich (suche.py 29.10.2026, Basis virtdisk_P1.CPP)
// virtdisk.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13F9D0-0x13FEF0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014a60();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bbc68;                    // 0x1BBC68
extern const char d_1a944c[];           // Text 0x1A944C
// --- eigene Funktionen (18), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_145300(void *p, int c, unsigned n);
int f_147c84(void *a, int n, void *b, void *c);
struct E { unsigned key; short s; char *ptr; int n; };
struct V { unsigned vp; E tab[200]; void *d; short cur; short st[10]; short cnt; unsigned sel; int pad; int lim; };
#define VT(d,o) (*(int **)(d))[(o)/4]
typedef short (*PF_s_u)(void *, unsigned);
typedef int (*PF_i_u)(void *, unsigned);
typedef int (*PF_i_uu)(void *, unsigned, int);
typedef void (*PF_v_v)(void *);
typedef void (*PF_v_u)(void *, unsigned);
extern unsigned d_1bbc90[];
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_13f9d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Reserviert für einen einzelnen Cache-Eintrag e einen Speicherpuffer der Größe n Bytes auf dem
 *   Heap und speichert bei erfolgreicher Allokation die Ressourcenkennung key, den Archivindex s sowie die
 *   Bytegröße n im Eintrag.
 * - Eingaben: Zeiger e auf den Cache-Eintrag, 32-Bit-Ressourcenkennung key, 16-Bit-Archivindex s und Dateigröße
 *   n (int).
 * - Rückgabewert: Zeiger auf den neu angelegten Datenpuffer (e->ptr) oder 0, falls nicht genügend Speicher frei
 *   war.
 * - Wichtige Variablen:
 *   - e->ptr: Zeiger auf den im Heap reservierten Puffer für den Dateiinhalt.
 === Ende Beschreibung === */
char *f_13f9d0(E *e, unsigned key, short s, int n)
{
  e->ptr = new (mark(d_1a944c, 0x28)) char[n];
  if (e->ptr) {
    e->key = key;
    e->s = s;
    e->n = n;
  }
  return e->ptr;
}
//@ f_13fa10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die 32-Bit-Ressourcenkennung (key) eines Cache-Eintrags zurück.
 * - Eingaben: Zeiger e auf den Cache-Eintrag.
 * - Rückgabewert: Ressourcenkennung e->key (unsigned).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned f_13fa10(E *e) { return e->key; }
//@ f_13fa20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den 16-Bit-Archivindex (s) eines Cache-Eintrags zurück.
 * - Eingaben: Zeiger e auf den Cache-Eintrag.
 * - Rückgabewert: Archivindex e->s (short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
short f_13fa20(E *e) { return e->s; }
//@ f_13fa30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die gespeicherte Dateigröße (n) eines Cache-Eintrags in Bytes zurück.
 * - Eingaben: Zeiger e auf den Cache-Eintrag.
 * - Rückgabewert: Größe des gepufferten Dateiinhalts e->n (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13fa30(E *e) { return e->n; }
//@ f_13fa40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Datenzeiger (ptr) auf den im RAM gepufferten Dateiinhalt eines Cache-Eintrags zurück.
 * - Eingaben: Zeiger e auf den Cache-Eintrag.
 * - Rückgabewert: Datenzeiger e->ptr (char *).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
char *f_13fa40(E *e) { return e->ptr; }
//@ f_13fa50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob ein Cache-Eintrag e aktuell mit einer gültigen Ressource belegt ist (e->key != 0).
 * - Eingaben: Zeiger e auf den Cache-Eintrag.
 * - Rückgabewert: 1, wenn der Slot belegt ist, sonst 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13fa50(E *e) { return e->key != 0; }
//@ f_13fa60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Datenpuffer e->ptr eines einzelnen Cache-Eintrags über delete frei und setzt ptr, key
 *   und n auf 0 zurück.
 * - Eingaben: Zeiger e auf den freizugebenden Cache-Eintrag.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13fa60(E *e)
{
  delete e->ptr;
  e->ptr = 0;
  e->key = 0;
  e->n = 0;
}
//@ f_13fa90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor der virtuellen RAM-Disk (V): Initialisiert alle 200 Cache-Einträge in v->tab über
 *   den Array-Konstruktor f_147c84 (mit f_13f9b0), trägt die virtuelle Methodentabelle d_1bbc90 ein, setzt den
 *   aktuellen Datei-Index cur und den Stapelzähler cnt auf -1 (0xFFFF), füllt den 10-elementigen
 *   Markierungsstapel st mit -1 und speichert die Mindest-Freispeichergrenze lim.
 * - Eingaben: Zeiger v auf die V-Instanz und Mindest-Freispeicherreserve lim in Bytes (int).
 * - Rückgabewert: Zeiger auf die initialisierte V-Instanz.
 * - Wichtige Variablen:
 *   - q: Zeiger auf das initialisierte V-Objekt.
 === Ende Beschreibung === */
V *f_13fa90(V *v, int lim)
{
  V *q = (V *)((char *)f_147c84((char *)v + 4, 200, &d_1bbc68, v) - 4);
  *(unsigned **)q = d_1bbc90;
  q->d = 0;
  q->cur = 0xffff;
  q->cnt = 0xffff;
  f_145300(q->st, -1, 0x14);
  q->lim = lim;
  return q;
}
//@ f_13faf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in den 200 Slots der virtuellen RAM-Disk nach einer Ressource mit der Kennung key.
 *   Besitzt key eine Archivgruppen-Kennung in den oberen Bits (key & 0x7FFF0000), wird zunächst über die
 *   virtuelle Methode +0x5C des unterliegenden Laufwerks v->d der interne Archivindex s ermittelt und nach
 *   q[i].s == s gesucht; andernfalls wird direkt nach q[i].key == key gesucht. Ist der gefundene Eintrag bereits
 *   mit einem gültigen RAM-Puffer geladen (f_13fa40 != 0), wird zusätzlich Bit 15 (0x8000) im Rückgabewert
 *   gesetzt.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und 32-Bit-Ressourcenkennung key.
 * - Rückgabewert: Der Slot-Index (0-199, bei vorhandenem RAM-Puffer verodert mit 0x8000) oder 0xFFFF, falls die
 *   Datei noch nicht im Cache verzeichnet ist.
 * - Wichtige Variablen:
 *   - r: Gefundener Tabellenindex (0xFFFF bei Nichtfinden).
 *   - s: Vom unterliegenden Archivtreiber gemeldeter interner Dateinummern-Index.
 === Ende Beschreibung === */
unsigned short f_13faf0(V *v, unsigned key)
{
  short t79_12;
  int t75_207;
  unsigned short r = 0xffff;
  unsigned short i;
  short s;
  E *t = v->tab;
  if (key & 0x7fff0000) {
    s = ((PF_s_u)VT(v->d, 0x5c))(v->d, key);
    if (s >= 0) {
      E *q = t;
      for (i = 0; i < 200; i++) {
        if ((t79_12 = q[i].s) == s) { r = i; break; }
      }
    }
  } else {
    E *q = t;
    for (i = 0; i < 200; i++) {
      if ((t75_207 = q[i].key) == key) { r = i; break; }
    }
  }
  if (r != 0xffff && f_13fa40(&v->tab[r]) != 0) r |= 0x8000;
  return r;
}
//@ f_13fba0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der 200 Einträge umfassenden Cache-Tabelle v->tab den ersten freien Slot (f_13fa50 ==
 *   0).
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Index des ersten freien Slots (0-199) oder -1, wenn alle 200 Slots belegt sind.
 * - Wichtige Variablen:
 *   - i: Schleifenzähler über die 200 Tabellenplätze.
 === Ende Beschreibung === */
short f_13fba0(V *v)
{
  short i = 0;
  short r = -1;
  E *t = v->tab;
  for (; i < (short)200; i++) {
    if (f_13fa50(&t[i]) == 0) { r = i; break; }
  }
  return r;
}
//@ f_13fbe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verbindet die virtuelle RAM-Disk v mit dem darunterliegenden physischen Archiv- bzw.
 *   Dateitreiber d (realdisk).
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Zeiger d auf das unterliegende Laufwerksobjekt.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13fbe0(V *v, void *d) { v->d = d; }
//@ f_13fbf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Synchronisiert oder aktiviert die aktuell ausgewählte Ressource im unterliegenden Dateitreiber
 *   v->d: Wurde die aktuelle Datei aus dem RAM-Cache bedient (v->cur & 0x8000), wird die virtuelle Methode +0x08
 *   mit der Kennung v->sel aufgerufen, andernfalls die Methode +0x04.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13fbf0(V *v)
{
  if (((unsigned char *)&v->cur)[1] & 0x80) {
    ((PF_v_u)VT(v->d, 8))(v->d, v->sel);
    return;
  }
  ((PF_v_v)VT(v->d, 4))(v->d);
}
//@ f_13fc30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet den Aufruf zum Setzen des aktiven Archivs oder Pfads (p2) direkt an die virtuelle
 *   Methode +0x08 des unterliegenden Dateitreibers v->d weiter.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Parameter p2 (unsigned).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13fc30(V *v, unsigned p2)
{
  ((PF_v_u)VT(v->d, 8))(v->d, p2);
}
//@ f_13fc40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob eine Ressource key verfügbar ist: Befindet sie sich bereits in der Cache-Tabelle
 *   (f_13faf0(v, key) != 0xFFFF), gibt die Funktion sofort 1 zurück; andernfalls fragt sie die virtuelle
 *   Existenzprüfung (+0x0C) des unterliegenden Dateitreibers v->d ab.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Ressourcenkennung key (unsigned).
 * - Rückgabewert: 1, wenn die Ressource im Cache oder auf der Festplatte/CD existiert, sonst 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13fc40(V *v, unsigned key)
{
  if (f_13faf0(v, key) != 0xffff) return 1;
  return ((PF_i_u)VT(v->d, 0xc))(v->d, key);
}
//@ f_13fc70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt eine neue Cache-Marke (Snapshot) auf dem internen Markierungsstapel v->st: Erhöht die
 *   Stapeltiefe v->cnt, sucht den ersten freien Tabellenplatz (0-199) in v->tab und speichert dessen Index in
 *   v->st[v->cnt]. Alle ab diesem Zeitpunkt geladenen Dateien landen in Slots ab diesem Index.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Die neue Stapelstufe v->cnt (short), die später an f_13fcd0 übergeben werden kann.
 * - Wichtige Variablen:
 *   - r: Index des ersten freien Cache-Slots (-1, falls voll).
 === Ende Beschreibung === */
short f_13fc70(V *v)
{
  short i = 0;
  short r = -1;
  E *t;
  v->cnt++;
  t = v->tab;
  for (; i < (short)200; i++) {
    if (f_13fa50(&t[i]) == 0) { r = i; break; }
  }
  v->st[v->cnt] = r;
  return v->cnt;
}
#pragma inline_depth(0)
//@ f_13fcd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt alle Cache-Einträge ab der auf der Stapelstufe n gespeicherten Marke v->st[n] bis zum
 *   Ende der 200er-Tabelle wieder frei (delete[] ptr), setzt v->st[n] = -1 und verringert die Stapeltiefe v->cnt
 *   um 1.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk und Stapelstufe n (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - j: Laufindex von v->st[n] bis 199 über die freizugebenden Cache-Slots.
 === Ende Beschreibung === */
// Init steht hinter der Schleife, damit CanReach vor dem Hoist den Langsprung waehlt.
// StraightenCode zieht Init spaeter vor Check; der lokale Epilog bleibt erhalten.
void f_13fcd0(V*v,short n){
 E*t;short j;int off,used;
 if((int)v->cnt==-1)goto Exit;
 goto Init;
Check:
 off=(int)j*14;used=f_13fa50((E*)((char*)t+off));
 if(used!=1)goto Next;
 delete [] ((E*)((char*)t+off))->ptr;
 ((E*)((char*)t+off))->ptr=0;
 ((E*)((char*)t+off))->key=0;
 ((E*)((char*)t+off))->n=0;
Next:
 ++j;if(j<(short)200)goto Check;goto Cleanup;
Init:
 j=v->st[n];if(j>=(short)200)goto Cleanup;
 t=v->tab;goto Check;
Cleanup:
 v->st[n]=-1;--v->cnt;
Exit:return;
}
#pragma inline_depth(3)
//@ f_13fd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leert den gesamten RAM-Cache vollständig: Durchläuft alle 200 Slots von v->tab, gibt jeden
 *   belegten Puffer über f_13fa60 frei und setzt den Markierungsstapel (v->cnt = -1, v->st auf -1) in den
 *   Ausgangszustand zurück.
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - j: Schleifenzähler (0 bis 199) über alle Cache-Einträge.
 === Ende Beschreibung === */
void f_13fd60(V *v)
{
  E *t = v->tab;
  short j;
  for (j = 0; j < (short)200; j++) {
    E *p = &t[j];
    int t_164 = f_13fa50(p);
    if (t_164 == 1) f_13fa60(p);
  }
  v->cnt = 0xffff;
  f_145300(v->st, -1, 0x14);
}
//@ f_13fdd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die Ressource p3 über den Cache-Slot p2: Ermittelt über das unterliegende Laufwerk v->d
 *   den internen Archivindex (+0x5C) und die Dateigröße (+0x34). Ist mindestens eine Cache-Marke aktiv (v->cnt
 *   != -1) und bleibt nach Abzug der Dateigröße noch genügend freier Heap-Speicher oberhalb der Mindestreserve
 *   v->lim (f_014a60() - saved >= v->lim), legt die Funktion einen RAM-Puffer im Slot v->tab[p2] an, liest die
 *   gesamte Datei über Methode +0x18 auf einen Schlag in den RAM und markiert v->cur = p2 | 0x8000; andernfalls
 *   öffnet sie die Datei ungepuffert direkt auf dem Datenträger über Methode +0x14 (v->cur = p2).
 * - Eingaben: Zeiger v auf die virtuelle RAM-Disk, Ziel-Tabellenslot p2 (unsigned) und Ressourcenkennung p3
 *   (unsigned).
 * - Rückgabewert: 1 bei erfolgreichem Laden bzw. Öffnen der Ressource, sonst 0.
 * - Wichtige Variablen:
 *   - fr.size, saved: Ermittelte Bytegröße der zu ladenden Ressource.
 *   - fr.loc: Interner Archivindex der Datei (-1, wenn keine Gruppenkennung vorliegt).
 *   - valid: Flag (1 = Datei darf in den RAM-Cache geladen werden, 0 = ungepuffert von Platte lesen).
 *   - data: Zeiger auf den neu allokierten RAM-Puffer im Cache-Slot v->tab[p2].
 === Ende Beschreibung === */
// unsigned-Positionskopie und identische Datenzeiger-Kopien steuern die Registersortierung.
// Groesse als Referenz: die zwei Reads bleiben nach mark/new; saved haelt die Pruefgroesse.
// Virtueller Slot +18 bekommt den Datenpuffer als drittes Argument in EBX.
struct Entry900:E {char*init(unsigned k,short at,const int &bytes){ptr=new(mark(d_1a944c,0x28))char[bytes];if(ptr){key=k;unsigned pos=0; pos=(unsigned short)at;s=(short)pos;n=bytes;}return ptr;}};
int f_13fdd0(V *v, unsigned p2, unsigned p3)
{
  E *entry;
  int result = 0;
  int valid;
  // 3-Byte-Alias verhindert Registerzerlegung des 8-Byte-Rahmens.
  struct Three940 {char bytes[3];}; struct Frame940 {int size; union {int loc; Three940 odd;};} fr; int saved;
  fr.loc = -1;
  char *data = 0;
  short index;

  if (p3 & 0x7fff0000)
    fr.loc = ((PF_i_u)VT(v->d, 0x5c))(v->d, p3);
  fr.size = saved = ((PF_i_u)VT(v->d, 0x34))(v->d, p3);
  fr.odd=fr.odd; // 3-Byte-Alias sperrt Registerbaum fuer Stapelrahmen wie im Original

  valid=1;
  if ((int)v->cnt == -1)
    valid = 0;
  else if (v->lim != 0 && f_014a60() - saved < v->lim)
    valid = 0;

  if (valid == 1) {
    index = (short)p2;
    data=((Entry900*)&v->tab[index])->init(p3,(short)fr.loc,fr.size);
    data=(char*)(((int)data&0)?0:(int)data); // haelt Registerbindung von data ueber beide Zweige
  }else {data=(char*)(((int)data&0)?0:(int)data);}

  if (data) {
    if (((PF_i_uu)VT(v->d, 0x18))(v->d, p3, (int)data) != 0) {
      v->sel = p3;
      result = 1;
      v->cur = (short)(p2|0x8000);
    }
  } else {
    if (((PF_i_uu)VT(v->d, 0x14))(v->d, p3, 0x200) == 1) {
      v->sel = p3;
      v->cur = (short)p2;
      result = 1; result=(result&0)?0:result; // haelt Ergebnis-Web und Registerwahl wie im Original
    }
  }
  return result;
}
