/* === Beschreibung (Katalog) ===
 * Einheit tdmpal (0x122800 - 0x123080)
 *
 * Diese Einheit verwaltet die tageszeit- und umgebungsabhängigen Farbpaletten sowie die Schattierungs- und
 * Lichtstufen für die 3D-Engine (p:\riva\source\cpp\tdmpal.cpp).
 === Ende Beschreibung === */
// P3 11/13 gleich (suche.py 25.10.2026, Basis tdmpal_P1.CPP)
// tdmpal.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x122800-0x123080
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_1624b4();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a8a00[];           // Text 0x1A8A00
// --- eigene Funktionen (12), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


#define W(p,o,t) (*(t *)((p) + (o)))
typedef void (*VF)(int);
extern int d_1a8a20[];
extern int d_1a8a28[];
extern int d_1a8a78[];
extern signed char d_1a994c;
extern unsigned d_1a9a1c;
extern const char d_1b84c8[];
extern const char d_1b84d2[];
extern const char d_1b84d7[];
extern const char d_1b84dc[];
extern const char d_1b84e2[];
extern const char d_1b84e8[];
extern int d_1bba78;
extern int d_1bba8c;
extern signed char d_1bfb08;
extern int d_1c2c44;
extern int d_1c72f8;
int f_014540(int p1, const char *p2, int p3);
int f_120620(int p1);
int f_126410(int p1);
int f_1230a0(int p1);
int __cdecl f_149eb4(int p1, int p2, int p3);
int f_1622c0(int p1);
int f_16232c(int p1);
int f_16238c(int p1, int p2, int p3);
int f_163a98(int p1);
int f_164d04(int p1);
int f_1624b4(int p1);
int f_145234(int p1, int p2);
void f_145254(void);
int f_15e469(int p1, const char *p2);
int f_15e65b(int p1, int p2, int p3, int p4);
int f_15e836(int p1);
#define FREEF(p,o) if (W(p,o,int)) { operator delete((void *)W(p,o,int)); W(p,o,int) = 0; }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_122800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Agiert als Konstruktor des 3D-Paletten-Managers: Die Methode initialisiert die
 *   Methoden-Sprungtabelle (d_1bba8c), setzt Orts-, Zeitstufen- und Statusfelder zurück, reserviert den 768 Byte
 *   großen RGB-Palettenpuffer (Offset +0x56) und allokiert je nach Modus (p2 == 0 oder 1) zusätzlich den
 *   1.024-Byte-Puffer (+0x4a) sowie im Modus 0 den 480-Byte-Puffer (+0x36).
 * - Eingaben: Übergeben werden ein Zeiger auf die 3D-Palettenstruktur (this) und der Betriebsmodus (p2, 0 oder
 *   1).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die initialisierte 3D-Palettenstruktur zurück.
 === Ende Beschreibung === */
int f_122800(int p1, int p2)
{
  W(p1,0x62,int) = (int)&d_1bba8c;
  W(p1,0x24,short) = -1;
  W(p1,0x2c,short) = -1;
  W(p1,0x2a,short) = -1;
  W(p1,0x26,int) = 0;
  W(p1,0x2e,int) = 0;
  W(p1,0x3a,short) = 0;
  W(p1,0x42,int) = 1;
  W(p1,0x46,int) = 1;
  W(p1,0x32,int) = 1;
  W(p1,0x5a,int) = 0;
  W(p1,0x4e,int) = (int)&d_1c72f8;
  W(p1,0x52,int) = 0;
  W(p1,0x20,int) = p2;
  W(p1,0x56,int) = f_014540(0x300, d_1a8a00, 0x7f);
  switch ((unsigned)p2) {
    case 0:
      W(p1,0x36,int) = f_014540(0x1e0, d_1a8a00, 0x84);
      W(p1,0x4a,int) = f_014540(0x400, d_1a8a00, 0x85);
      break;
    case 1:
      W(p1,0x36,int) = 0;
      W(p1,0x4a,int) = f_014540(0x400, d_1a8a00, 0x8a);
      break;
  }
  return p1;
}
//@ f_1228e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Agiert als virtueller Destruktor des 3D-Paletten-Managers: Die Methode gibt die dynamisch
 *   reservierten Paletten- und Tabellenpuffer an den Offsets +0x36, +0x4a und +0x56 frei und löscht bei
 *   gesetztem Bit 2 in den Destruktor-Flags (p2 & 2) auch das Objekt selbst.
 * - Eingaben: Übergeben werden ein Zeiger auf die 3D-Palettenstruktur (this) und die Destruktor-Steuerflags
 *   (p2).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die 3D-Palettenstruktur zurück.
 === Ende Beschreibung === */
int f_1228e0(int p1, unsigned p2)
{
  if (p2 & 4) {
    f_145234(p1, (int)&d_1bba78);
    f_145254();
  } else {
    W(p1,0x62,int) = (int)&d_1bba8c;
    FREEF(p1, 0x36)
    FREEF(p1, 0x4a)
    FREEF(p1, 0x56)
    if (p2 & 2) operator delete((void *)p1);
  }
  return p1;
}
//@ f_122970
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt den 3D-Paletten-Manager auf eine neue 3D-Karten- bzw. Umgebungskennung (p2 bei Offset
 *   +0x24) um: Sie prüft gegen die Liste d_1a8a20, ob für diesen Ort spezielle Palettendateien im temporären
 *   Cache (..\ctemp\<name>.ppr bzw. .ppd/n.pix/d.pix) vorliegen, lädt im Modus 0 die 480 Byte großen Zusatzdaten
 *   in den Puffer +0x36 und sichert die 1.024-Byte-Farbtabelle (+0x4e nach +0x4a).
 * - Eingaben: Übergeben werden ein Zeiger auf die 3D-Palettenstruktur (this) und die Kennung der 3D-Umgebung
 *   (short).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Umgebung in d_1a8a20 für tageszeitabhängige Paletten
 *   registriert ist, und sonst 0.
 === Ende Beschreibung === */
int f_122970(int p1, short p2)
{
  short k;
  int h;
  if (W(p1,0x24,short) != p2) {
    W(p1,0x26,int) = 0;
    W(p1,0x2c,short) = -1;
    W(p1,0x2a,short) = -1;
    W(p1,0x2e,int) = 0;
    W(p1,0x46,int) = 1;
    W(p1,0x5a,int) = 1;
    W(p1,0x24,short) = p2;
    for (k = 0; (unsigned)k < 5; k++) {
      if (((signed char *)d_1a8a20)[k] == p2) {
        W(p1,0x26,int) = 1;
        if (W(p1,0x20,int) == 0) {
          strcat(strcpy((char *)p1, d_1b84c8), (char *)f_120620(W(p1,0x24,short)));
          switch (W(p1,0x20,int)) {
          case 0: strcat((char *)p1, d_1b84d2); break;
          case 1: strcat((char *)p1, d_1b84d7); break;
          case 2: strcat((char *)p1, d_1b84dc); break;
          case 3: strcat((char *)p1, d_1b84e2); break;
          }
          h = f_15e469(p1, d_1b84e8);
          if (h) {
            f_15e65b(W(p1,0x36,int), 0x1e0, 1, h);
            f_15e836(h);
          }
        }
        break;
      }
    }
    if ((int)p2 != 0) d_1a9a1c &= ~0x10;
    memcpy((void *)W(p1,0x4a,int), (void *)W(p1,0x4e,int), 0x400);
  }
  return W(p1,0x26,int);
}
//@ f_122b70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt die gespeicherte 3D-Umgebungskennung (Offset +0x24) auf -1 zurück, sodass beim
 *   nächsten Betreten einer Szene ein vollständiges Neuladen erzwungen wird.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122b70(int p1)
{
  W(p1,0x24,short) = -1;
}
//@ f_122b80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt anhand der aktuellen Spieltageszeit (f_126410(&d_1c2c44)) und der 20 Zeitschwellen
 *   in d_1a8a28 den aktuellen Tageszeit-Palettenindex (0-19 bei Offset +0x2c) und schaltet an den
 *   Dämmerungsgrenzen (d_1a8a78 == 2 bzw. 3) das Tag- und Nacht-Flag (Offset +0x42) samt
 *   Aktualisierungsanforderung (+0x46 = 1) um.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn sich der Tageszeit-Palettenindex gegenüber dem zuletzt
 *   geladenen Stand (Offset +0x2a) geändert hat, und sonst 0.
 === Ende Beschreibung === */
int f_122b80(int p1)
{
  int iv = f_126410((int)&d_1c2c44);
  short k;
  W(p1,0x2c,short) = 0;
  for (k = 0; k < 0x14; k++) {
    if (iv <= d_1a8a28[k]) {
      W(p1,0x2c,short) = k;
      break;
    }
  }
  if (W(p1,0x42,int) == 1 && d_1a8a78[W(p1,0x2c,short)] == 2) {
    W(p1,0x42,int) = 0;
    W(p1,0x46,int) = 1;
  } else if (W(p1,0x42,int) == 0 && d_1a8a78[W(p1,0x2c,short)] == 3) {
    W(p1,0x42,int) = 1;
    W(p1,0x46,int) = 1;
  }
  return W(p1,0x2c,short) != W(p1,0x2a,short);
}
//@ f_122c10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt den zuletzt angewendeten Tageszeit-Palettenindex (Offset +0x2a) auf -1 zurück, um bei
 *   der nächsten Prüfung eine Aktualisierung der 3D-Palette zu erzwingen.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122c10(int p1)
{
  W(p1,0x2a,short) = -1;
}
//@ f_122c20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktiviert oder deaktiviert über das Flag bei Offset +0x32 die automatische
 *   Palettenaktualisierung des 3D-Paletten-Managers.
 * - Eingaben: Übergeben werden ein Zeiger auf die 3D-Palettenstruktur (this) und der neue Flagwert (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122c20(int p1, int p2)
{
  W(p1,0x32,int) = (unsigned char)p2;
}
//@ f_122c30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt das Bereitschaftsflag der 3D-Palette (Offset +0x5a) auf 0 zurück und liest die aktuell
 *   in der Grafik-Hardware gesetzten 256 Palettenfarben (f_149eb4) in den internen 768-Byte-Puffer (Offset
 *   +0x56) ein.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122c30(int p1)
{
  W(p1,0x5a,int) = 0;
  f_149eb4(W(p1,0x56,int), 0, 0x100);
}
//@ f_122c50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft über die virtuelle Methodentabelle (Offsets +0x18 und +0x30) die
 *   Aktualisierungsroutinen des 3D-Paletten-Managers auf und liefert anschließend die Adresse des
 *   768-Byte-Palettenpuffers (Offset +0x56).
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den 768-Byte-Palettenpuffer (Offset +0x56) zurück.
 === Ende Beschreibung === */
int f_122c50(int p1)
{
  (*(VF *)(W(p1,0x62,int) + 0x18))(p1);
  (*(VF *)(W(p1,0x62,int) + 0x30))(p1);
  return W(p1,0x56,int);
}
//@ f_122c70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt die 1.024-Byte-Farbtabelle an Offset +0x4e aus der Sicherungskopie bei Offset +0x4a
 *   wieder her und übergibt sie an den 3D-Renderer (f_164d04).
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122c70(int p1)
{
  memcpy((void *)W(p1,0x4e,int), (void *)W(p1,0x4a,int), 0x400);
  f_164d04(W(p1,0x4e,int));
}
//@ f_122ca0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt bei einem Wechsel der Tageszeitstufe (Offset +0x2c != +0x2a) und aktivierter Automatik
 *   (+0x32 != 0) im Modus 1 den entsprechenden Datensatz aus der temporären Palettendatei (f_1230a0) und
 *   überträgt Farbtabelle (f_164d04), Nebel- und Lichtparameter (f_16232c, f_16238c, f_1622c0) sowie Tag- und
 *   Nacht-Helligkeit (f_163a98, d_1a9a1c, d_1a994c) an die 3D-Engine.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122ca0(int p1)
{
  int r;
  unsigned m;
  if (W(p1,0x2c,short) == -1) (*(VF *)(W(p1,0x62,int) + 8))(p1);
  if (W(p1,0x2c,short) == W(p1,0x2a,short)) goto ende;
  if (W(p1,0x32,int) != 0) goto pruef;
  goto ende;
aufruf:
  r = f_1230a0(p1);
  goto danach;
pruef:
  m = W(p1,0x20,unsigned);
  r = 0;
  if (m > 0) {
    if (m == 1) goto aufruf;
  }
danach:
  if (r != 1) goto ende;
  W(p1,0x2a,short) = W(p1,0x2c,short);
  f_164d04(W(p1,0x4e,int));
  f_16232c(W(p1,0x3a,unsigned short));
  f_16238c(W(p1,0x3c,unsigned char), W(p1,0x3e,unsigned char), W(p1,0x40,unsigned char));
  f_1622c0(3);
  if (W(p1,0x42,int) == 1) {
    f_163a98(0);
    d_1a9a1c &= 0xfffdfff7u;
    d_1a994c = 1;
  } else {
    f_163a98((unsigned short)(((100 - W(p1,0x5e,unsigned short)) * 0x3f) / 100));
    d_1a9a1c |= 0x20008;
    d_1a994c = 0;
  }
  W(p1,0x5a,int) = 1;
ende:
  return;
}
//@ f_122dc0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert bei gesetztem Änderungsflag (Offset +0x46 == 1) den Dateipfad
 *   (..\ctemp\<name>...) für die zur aktuellen Tageszeitstufe gehörende Textur- und Palettenvariante (d_1a8a78)
 *   und lädt bei Nacht oder in Umgebung 0 - sofern d_1bfb08 aktiv ist - die zugehörige Textur über f_1624b4
 *   nach.
 * - Eingaben: Übergeben wird ein Zeiger auf die 3D-Palettenstruktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122dc0(int p1)
{
  unsigned k;
  char *r;
  if (W(p1,0x46,int) == 1) {
    W(p1,0x46,int) = 0;
    k = d_1a8a78[W(p1,0x2c,short)];
    r = (char *)p1;
    {
      const char *t = (const char *)f_120620(W(p1,0x24,short));
      strcpy(r, d_1b84c8);
      strcat(r, t);
    }
    if (k == (unsigned)-1) k = W(p1,0x20,int);
    switch (k) {
      case 0: strcat(r, d_1b84d2); break;
      case 1: strcat(r, d_1b84d7); break;
      case 2: strcat(r, d_1b84dc); break;
      case 3: strcat(r, d_1b84e2); break;
    }
    if (W(p1,0x24,short) == 0 || W(p1,0x42,int) == 0) {
      signed char c = d_1bfb08;
      if ((int)c) {
        f_1624b4(p1);
        d_1a9a1c |= 0x10;
      } else {
        *(unsigned char *)&d_1a9a1c &= 0xef;
      }
    } else {
      *(unsigned char *)&d_1a9a1c &= 0xef;
    }
  }
}
//@ f_122f50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Baut im Namenspuffer am Anfang der Struktur (this) den relativen Dateipfad
 *   ..\ctemp\<umgebungsname><endung> zusammen, wobei die Dateiendung (.ppr, .ppd, n.pix oder d.pix) über p2
 *   (bzw. bei -1 über den Modus bei Offset +0x20) gewählt wird.
 * - Eingaben: Übergeben werden ein Zeiger auf die 3D-Palettenstruktur (this) und der Endungsindex (0-3 oder -1
 *   für den Standardmodus).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_122f50(int p1, int p2)
{
  const char *t;
  t = (const char *)f_120620(W(p1,0x24,short));
  strcpy((char *)p1, d_1b84c8);
  strcat((char *)p1, t);
  if (p2 == -1) p2 = W(p1,0x20,int);
  switch ((unsigned)p2) {
  case 0: strcat((char *)p1, d_1b84d2); break;
  case 1: strcat((char *)p1, d_1b84d7); break;
  case 2: strcat((char *)p1, d_1b84dc); break;
  case 3: strcat((char *)p1, d_1b84e2); break;
  default: break;
  }
}
