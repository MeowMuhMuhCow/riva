/* === Beschreibung (Katalog) ===
 * Einheit gz_013da0_t1 (0x013da0 - 0x0144e0)
 *
 * Überblick
 * Diese Einheit implementiert den Großteil der Archivklasse AlfDisk (alfdisk.cpp), mit der *Schatten über Riva*
 * komprimierte und gepackte Spielressourcen aus .ALF-Archivdateien (Magic 0x20464c41 = "ALF ") nach Gruppen- und
 * Eintragsnummern durchsucht, öffnet und ausliest.
 === Ende Beschreibung === */
// P3 17/24 gleich (suche.py 25.10.2026, Basis gz_013da0_P1.CPP)
// I9: aus G013DA0_REST.CPP uebernommen (Stufe-2-Stand), Marken 9 neu
// G013DA0 REST: alfdisk.cpp-Teil 0x13DA0-0x144D2 (23 Funktionen, 3 offen: 013DF0/013F20/014020 +0141E0/0142A0/014480 klein). Zweite Einheit alloc.cpp ab 0x144E0 -> G0144E0_OK.CPP
// gz_013da0.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x13DA0-0x14540. Klasse AlfDisk (ALF-Archiv): Datei oeffnen/pruefen, Gruppen- und Eintragstabellen laden, Lesen/Suchen, DPMI-Speicherabfrage.
#include <string.h>
#include <i86.h>
extern char d_1c1190[];                                   // zmain, fremdes Datenstueck 1C1190-1C3914
void f_0ed8f0(void *obj, long code, const char *s, ...);
int f_144fbf(const char *name, int mode, ...);            // open
int f_144e8b(int h, void *buf, unsigned n);               // read
long f_145279(int h, long pos, int whence);               // lseek
int f_145259(int h);                                      // close
long f_1455a4(int h);                                     // tell
void f_1455b5();
int f_145702(int intno, union REGS *in, union REGS *out, struct SREGS *s);
#pragma pack(1)
#define PID long
#define LO(p) ((short)(p))
#define HI(p) ((short)(((p) - (short)(p)) >> 16))
struct Rec { signed char c0; char r1[13]; unsigned n; char r12[6]; long off; };   // 0x1C Bytes
struct VBase {
  virtual void v0(); virtual int v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual int v5(int a, int b); virtual void v6(); virtual void v7(int a); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual int v12(); virtual void v13(); virtual void v14();
  virtual int v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual short v22(); virtual void v23(); virtual void v24();
  virtual void v25(void *out, short n);
};
struct AlfDisk : VBase {
  char *name;
  long magic; char h0c[4]; short s10; long p12; char h16[2]; long l18; char h1c[2]; long l1e; char h22[2]; long l24; char h28[16];
  int fd; short cur3c; short cur3e; short s40; short *p42;
  Rec e46; Rec e62; short *p7e;
  void chk(); void chk2(); void ldg(short di);
  Rec *f_013da0(); int f_013db0(int a); int f_013de0(); int f_013df0(PID p2); short *f_013f20(int g, unsigned *cnt);
  int f_014020(PID p2, int unused); int f_014190(int a, int b); void f_0141d0(void *buf); void f_0141e0(void *buf, unsigned n);
  int f_014210(); void f_014220(); unsigned f_014240(); int f_014250(int a); long f_014280(); long f_0142a0(long pos, short wh);
  short f_014300(); int f_014310(int a); short f_014350(); int f_0143c0(signed char *buf, short idx);
  short f_014410(); int f_014420(signed char *buf, int g); int f_014480(char *p2, int p3);
  int f_013c00(char *p, Rec r);
};
inline void AlfDisk::chk() {
  int ok = 0;
  fd = f_144fbf(name, 0x200, 0x180);
  if (fd > 0) { f_144e8b(fd, &magic, 0x30); if (magic == 0x20464c41) ok = 1; }
  if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, name);
}
inline void AlfDisk::chk2() {
  if (fd == -1) chk();
}
inline void AlfDisk::ldg(short di) {
  if (di != cur3e) {
    f_145279(fd, di * 28 + l1e, 0);
    f_144e8b(fd, &e46, 0x1c);
    cur3e = di;
    f_145279(fd, e46.off + l24, 0);
    f_144e8b(fd, p7e, e46.n * 2);
    cur3e = di;
  }
}
#define CHK if (fd == -1) chk()
Rec *AlfDisk::f_013da0() { return &e62; }
int AlfDisk::f_013db0(int a) { int r = 0; if (v5(a, 0x200) == 1) { r = v1(); v10(); } return r; }
int AlfDisk::f_013de0() { return fd; }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_013df0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x013df0
 * - Aufgabe im Spiel: Prüft, ob eine 32-Bit-Ressourcenkennung p2 (bestehend aus Gruppennummer im High-Word minus
 *   1 und Eintragsindex im Low-Word) im .ALF-Archiv vorhanden ist. Bei Bedarf wird die .ALF-Datei geöffnet, ihre
 *   "ALF "-Kennung geprüft, die zugehörige Gruppentabelle (ldg) nachgeladen und kontrolliert, ob der Index in
 *   p7e[lo] ungleich -1 ist.
 * - Eingaben: Impliziter this-Zeiger und die 32-Bit-Ressourcen-ID (p2).
 * - Rückgabewert: 1, wenn der Eintrag im Archiv existiert, sonst 0.
 * - Wichtige Variablen:
 *   - Instanzfelder p42 (Gruppen-Umsetzungstabelle), e46 (aktueller Gruppenheader), p7e (Index-Array der
 *     aktuellen Gruppe) und cur3e (aktuell geladene Gruppe).
 === Ende Beschreibung === */
int AlfDisk::f_013df0(PID p2) {
  short g, lo;
  struct Split { static void run(PID p, short &hi, short &low) {
    low = (short)p;
    hi = ((p & 0xffff0000UL) >> 16) - 1;
  }};
  Split::run(p2, g, lo);
  short di = p42[g];
  AlfDisk *t = this;
  int r = 0;
  AlfDisk *check;
  if (t->fd == -1) {
    check=t; int ok=0;
    t->fd = f_144fbf(t->name, 0x200, 0x180);
    if (t->fd > 0) {
      f_144e8b(t->fd, &t->magic, 0x30);
      if (t->magic == 0x20464c41) ok = 1;
    }
    if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, check->name);
  }
  t->ldg(di);
  if ((unsigned)(short)lo < e46.n) {
    if (p7e[lo] != -1) r = 1;
  }
  return r;
}
//@ f_013f20
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x013f20
 * - Aufgabe im Spiel: Lädt die Eintrags-Indextabelle (p7e) für die angegebene 1-basierte Archivgruppe g nach,
 *   schreibt die Anzahl der Einträge dieser Gruppe in *cnt und gibt den Zeiger auf das Index-Array p7e zurück.
 * - Eingaben: Impliziter this-Zeiger, die 1-basierte Gruppennummer (g) und ein Ausgabezeiger für die
 *   Eintragsanzahl (cnt).
 * - Rückgabewert: Zeiger auf das 16-Bit-Index-Array p7e der Gruppe.
 * - Wichtige Variablen:
 *   - Instanzfelder p42, e46.n und p7e.
 === Ende Beschreibung === */
short *AlfDisk::f_013f20(int g, unsigned *cnt) {
  AlfDisk *t = this;
  short di = t->p42[--g];
  t->chk2();
  t->ldg(di);
  *cnt = e46.n;
  return p7e;
}

//@ f_014020
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014020
 * - Aufgabe im Spiel: Sucht den Archiveintrag zur 32-Bit-Ressourcenkennung p2, lädt dessen
 *   28-Byte-Eintragsheader in e62 (falls er nicht bereits in cur3c gecacht ist) und positioniert den Dateizeiger
 *   der .ALF-Datei über lseek (f_145279) exakt auf den Beginn der Nutzdaten (l18 + e62.off).
 * - Eingaben: Impliziter this-Zeiger, die 32-Bit-Ressourcen-ID (p2) und ein ungenutzter Modusparameter (unused).
 * - Rückgabewert: 1, wenn der Eintrag gefunden und annavigiert wurde, sonst 0.
 * - Wichtige Variablen:
 *   - Instanzfelder cur3c (Index des aktuell in e62 geladenen Eintrags), e62 (Eintragsheader), p12 (Basisoffset
 *     der Eintragstabelle) und l18 (Basisoffset des Datenbereichs).
 === Ende Beschreibung === */
int AlfDisk::f_014020(PID p2, int unused) {
    int t124_6;
  {
      short lo, g;
      struct Split { static void run(PID p, short &hi, short &low) {
        low = (short)p;
        hi = ((p & 0xffff0000UL) >> 16) - 1;
      }};
      Split::run(p2, g, lo);
      short di = p42[g];
      AlfDisk *t = this;
      chk2();
      t->ldg(di);
      if ((t124_6 = p7e[lo]) != -1) {
        short e = p7e[lo];
        AlfDisk *u = this;
        do {
        if (e != cur3c) {
          f_145279(fd, p12 + e * 28, 0);
          f_144e8b(fd, &e62, 0x1c);
          cur3c = e;
        }
        } while (0);
        f_145279(u->fd, u->l18 + u->e62.off, 0);
        return 1;
      }
  }
  return 0;
}
int AlfDisk::f_014190(int a, int b) { int r = 0; if (v5(a, 0x200) == 1) { v7(b); r = 1; v10(); } return r; }
void AlfDisk::f_0141d0(void *buf) { f_144e8b(fd, buf, e62.n); }
//@ f_0141e0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0141e0
 * - Aufgabe im Spiel: Liest bis zu n Bytes aus dem aktuell geöffneten Archiveintrag in den Puffer buf, begrenzt
 *   die Leselänge (rem) jedoch automatisch auf die ab der aktuellen Leseposition (v15()) noch im Eintrag
 *   verbleibenden Bytes (e62.n - t).
 * - Eingaben: Impliziter this-Zeiger, Zielpuffer (buf) und gewünschte Byteanzahl (n).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Lokale aktuelle Relativposition (t) und verbleibende Byteanzahl (rem).
 === Ende Beschreibung === */
void AlfDisk::f_0141e0(void *buf, unsigned n) {
  unsigned b = n;
  n = b;
  unsigned t = v15();
  unsigned rem = e62.n - t;
  if (b < rem) rem = b;
  f_144e8b(fd, buf, rem);
}
int AlfDisk::f_014210() { cur3c = -1; return 1; }
void AlfDisk::f_014220() { f_145259(fd); fd = -1; cur3e = -1; }
unsigned AlfDisk::f_014240() { return e62.n; }
int AlfDisk::f_014250(int a) { int r = 0; if (v5(a, 0x200) == 1) { r = v12(); v10(); } return r; }
long AlfDisk::f_014280() { long t = f_1455a4(fd); return t - (e62.off + l18); }
//@ f_0142a0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0142a0
 * - Aufgabe im Spiel: Verschiebt den Lesezeiger innerhalb des aktuell ausgewählten Archiveintrags analog zu
 *   lseek (wh == 0 relativ zum Eintragsanfang e62.off + l18, wh == 2 relativ zum Eintragsende e62.off + e62.n +
 *   l18, sonst relativ zur aktuellen Position) und gibt die neue relative Position innerhalb des Eintrags
 *   zurück.
 * - Eingaben: Impliziter this-Zeiger, Zieloffset (pos) und Positionierungsmodus (wh).
 * - Rückgabewert: Die neue Leseposition relativ zum Beginn des Archiveintrags.
 * - Wichtige Variablen:
 *   - Instanzfelder fd, e62.off, e62.n und l18.
 === Ende Beschreibung === */
long AlfDisk::f_0142a0(long pos, short wh) {
  int org;
  v15();
  if (wh == 0) { org = 0; pos = pos + (e62.off + l18); }
  else if (wh == 2) { long t = f_145279(fd, pos + (e62.off + e62.n + l18), 0); return t - (e62.off + l18); }
  else org = 1;
  long result = f_145279(fd, pos, org);
  result -= e62.off + l18;
  return result;
}
short AlfDisk::f_014300() { return cur3c; }
int AlfDisk::f_014310(int a) { int r = -1; if (v5(a, 0x200) == 1) { r = v22(); v10(); } return r; }
//@ f_014350
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014350
 * - Aufgabe im Spiel: Stellt sicher, dass die .ALF-Archivdatei geöffnet und ihr Header geladen ist (CHK), und
 *   gibt anschließend die Gesamtzahl der Dateieinträge (s10) im Archiv zurück.
 * - Eingaben: Impliziter this-Zeiger.
 * - Rückgabewert: Die Gesamtzahl der Einträge (s10).
 * - Wichtige Variablen:
 *   - Instanzfelder fd und s10 (Anzahl der Einträge im ALF-Header).
 === Ende Beschreibung === */
short AlfDisk::f_014350() {
  CHK;
  return s10;
}
//@ f_0143c0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0143c0
 * - Aufgabe im Spiel: Liest den 28-Byte-Eintragsdatensatz mit dem Index idx direkt aus der Eintragstabelle (p12
 *   + idx * 28) der .ALF-Datei in den Puffer buf ein.
 * - Eingaben: Impliziter this-Zeiger, Zielpuffer (buf, 28 Bytes) und Eintragsindex (idx).
 * - Rückgabewert: 1, wenn das erste Byte des gelesenen Datensatzes ungleich 0 ist, sonst 0.
 * - Wichtige Variablen:
 *   - Instanzfelder fd und p12.
 === Ende Beschreibung === */
int AlfDisk::f_0143c0(signed char *buf, short idx) {
  f_145279(fd, p12 + idx * 28, 0);
  f_144e8b(fd, buf, 0x1c);
  return *buf != 0;
}
short AlfDisk::f_014410() { return s40; }
//@ f_014420
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014420
 * - Aufgabe im Spiel: Liest den 28-Byte-Gruppenheader der 1-basierten Gruppe g (über e = p42[g - 1]) aus der
 *   Gruppentabelle (l1e + e * 28) in den Puffer buf ein oder füllt buf mit Nullen, falls die Gruppe im Archiv
 *   nicht belegt ist (e < 0).
 * - Eingaben: Impliziter this-Zeiger, Zielpuffer (buf, 28 Bytes) und 1-basierte Gruppennummer (g).
 * - Rückgabewert: 1, wenn das erste Byte in buf ungleich 0 ist, sonst 0.
 * - Wichtige Variablen:
 *   - Instanzfelder p42, fd und l1e.
 === Ende Beschreibung === */
int AlfDisk::f_014420(signed char *buf, int g) {
  g = g - 1; int e = p42[g];
  if (e < 0) memset(buf, 0, 0x1c);
  else {
    f_145279(fd, l1e + e * 28, 0);
    f_144e8b(fd, buf, 0x1c);
  }
  return *buf != 0;
}
//@ f_014480
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014480
 * - Aufgabe im Spiel: Liest über die virtuelle Methode v25(&tmp, p3) einen 28-Byte-Datensatz (Rec) ein und ruft,
 *   sofern dieser gültig ist (tmp.c0 != 0), die Formatierungsfunktion f_013c00(p2, tmp) auf.
 * - Eingaben: Impliziter this-Zeiger, Ausgabepuffer (p2) und Index (p3).
 * - Rückgabewert: Der Rückgabewert von f_013c00 bzw. 0, wenn tmp.c0 == 0 ist.
 * - Wichtige Variablen:
 *   - Lokale Struktur tmp vom Typ Rec (28 Bytes).
 === Ende Beschreibung === */
int AlfDisk::f_014480(char *p2, int p3) {
  Rec tmp;
  v25(&tmp, (short)p3);
  if(tmp.c0!=0)return f_013c00(p2,tmp);return 0;
}
//@ f_0144d0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0144d0
 * - Aufgabe im Spiel: Leere Platzhalter-Methode am Ende von alfdisk.cpp, die konstant 0 zurückgibt.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_0144d0() { return 0; }