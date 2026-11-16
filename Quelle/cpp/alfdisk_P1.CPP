/* === Beschreibung (Katalog) ===
 * Einheit: alfdisk
 *
 * Adressbereich: 0x0137e0-0x013da0
 * Spielsystem: Datei- & Archivverwaltung (AlfDisk) - Laden der .MOD-Modullisten, Auflösen von
 * 32-Bit-Ressourcenkennungen (Modul + Eintragsindex), Puffern von Modul- und Dateieinträgen in .ALF-Archiven
 * (RIVA.ALF, DUNGEON.ALF, SEQS.ALF, rivahelp.alf) sowie Entpacken einzelner Archivdateien auf die Festplatte.
 === Ende Beschreibung === */
// P3 5/7 gleich (suche.py 26.10.2026, Basis alfdisk_P1.CPP)
// P1 1/7 GLEICH (+013A80/013AD0/013BA0 = 0 Befehle, nur Fixup-Maske), Rest: 0137E0 FOLGE (48), 013A40 REG (lea statt mov/dec), 013C00 STRUKT (29, Groesse 408 statt 480)
// alfdisk.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0137E0-0x013DA0
#include "R_FIX.H"
#include <string.h>
#include "RIVAMEM.H"




#pragma pack(1)
#define PID unsigned long
extern const char d_1a0170[];
extern const char d_1b62f0[], d_1b62f2[], d_1b62f4[];
extern char d_1c11b8[], d_1c1190[];
void *f_0bdd50(void *o, int size, const char *file, int line);
void f_0bdde0(void *o, void *p, const char *file, int line);
void f_0ed8f0(void *obj, long code, const char *s, ...);
int f_144fbf(const char *name, int mode, ...);            // open
int f_144e8b(int h, void *buf, unsigned n);               // read
int f_144cb6(int h, void *buf, unsigned n);               // write
long f_145279(int h, long pos, int whence);               // lseek
int f_145259(int h);                                      // close
int f_1452bc(int h);                                       // filelen
void *f_145300(void *p, int c, unsigned n);               // memset
char *f_145318(char *s, const char *d);                   // strtok
void f_1454d0(char *s);
int f_145547(const void *a, const void *b, unsigned n);   // memicmp
void f_145590(int h, unsigned dt, unsigned tm);           // ftime
struct Rec { char name[14]; unsigned n; unsigned short tm; unsigned short dt; short x; long off; };   // 0x1C Bytes
struct AL {
  void *vp; char *name;
  long magic; char h0c[4]; short s10; long p12; char h16[2]; long l18; short ngrp; long l1e; char h22[2]; long l24; char h28[16];
  int fd; short c3c; short c3e; short s40; short *p42;
  Rec e46; Rec e62; short *p7e;
  void chk(); void ldg(short di);
  void f_0137e0(char *nm); short f_013a40(char *s); void f_013a70(PID p2, short *p3, short *p4); void f_013a80(short di);
  void f_013ad0(short di); void f_013ba0(short di); int f_013c00(char *dir, Rec r);
};
inline void AL::chk() {
  int ok = 0;
  fd = f_144fbf(name, 0x200, 0x180);
  if (fd > 0) { f_144e8b(fd, &magic, 0x30); if (magic == 0x20464c41) ok = 1; }
  if (!ok) f_0ed8f0(d_1c1190, 0x29a000e, name);
}
inline void AL::ldg(short di) {
  if (di != c3e) {
    f_145279(fd, di * 28 + l1e, 0);
    f_144e8b(fd, &e46, 0x1c);
    c3e = di;
    f_145279(fd, e46.off + l24, 0);
    f_144e8b(fd, p7e, e46.n * 2);
    c3e = di;
  }
}

//@ f_0137e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zweiter Teil der AlfDisk-Initialisierung (aufgerufen aus dem Konstruktor f_013670): liest
 *   die Modultabelle des .ALF-Archivs sowie die zugehörige Textdatei *.MOD (eine Zeile pro logischem Modul wie
 *   ModuleFight, ModuleCharac), zählt die Zeilen (s40), sucht für jede Zeile den passenden 14-Byte-Modulnamen
 *   (ohne Groß-/Kleinschreibung) in der .ALF-Modultabelle und speichert den gefundenen Archiv-Modulindex in
 *   p42[Zeile] (-1, falls das Modul im Archiv fehlt). Anschließend wird die maximale Eintragsanzahl eines Moduls
 *   ermittelt und der Indexpuffer p7e passend angelegt.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this) und Dateiname der .MOD-Datei (nm); keine Rückgabe
 *   (bricht bei fehlender .MOD-Datei über f_0ed8f0 mit Fehlercode 0x29a000e ab).
 * - Wichtige Variablen & Daten:
 *   - ngrp, l1e: Anzahl der Module im .ALF-Archiv und Dateioffset der Modultabelle (je 0x1c Bytes).
 *   - s40, p42: Anzahl der Zeilen in der .MOD-Datei und Zuordnungsfeld MOD-Zeile -> Archiv-Modulindex.
 *   - p7e, c3e: Dynamischer Puffer für die Dateinummernliste des jeweils aktiven Moduls und Index des aktuell
 *     gepufferten Moduls (-1).
 * - Besonderheiten / Originalfehler: Die Schleife zur Berechnung der maximalen Modulgröße mx für den Puffer p7e
 *   läuft über for (i = 0; i < s40; i++) (s40 = Zeilenzahl der .MOD-Datei) und liest dabei direkt die
 *   Archiv-Module 0 .. s40 - 1 (l1e + i * 0x1c), statt über alle ngrp Archivmodule oder über p42[i] zu
 *   iterieren. Hat die .MOD-Datei weniger Zeilen als das Archiv Module besitzt und liegt das größte Modul hinten
 *   im Archiv, wird p7e zu klein reserviert (Pufferüberlauf beim Laden des Moduls); hat die .MOD-Datei mehr
 *   Zeilen als ngrp, liest die Schleife über das Ende der Modultabelle hinaus.
 === Ende Beschreibung === */
void AL::f_0137e0(char *nm)
{
    int sz = ngrp * 0x1c;
    char *g = (char *)f_0bdd50(d_1c11b8, sz, d_1a0170, 0x7e);
    f_145279(fd, l1e, 0);
    f_144e8b(fd, g, sz);
    int h = f_144fbf(nm, 0x200, 0x180);
    if (h > 0) {
        sz = f_1452bc(h) + 1;
        char *buf = (char *)f_0bdd50(d_1c11b8, sz, d_1a0170, 0x89);
        f_145300(buf, 0, sz);
        f_144e8b(h, buf, sz);
        f_145259(h);
        short cnt=0;
        char *t = f_145318(buf, d_1b62f0);
        while (t) {
            f_1454d0(t);
            cnt++;
            t = f_145318(0, d_1b62f2);
        }
        s40 = cnt - 1;
        p42 = (short *)new (mark(d_1a0170, 0x92)) char[s40 * 2];
        { int a0_ = s40 * 2; f_145300(p42, -1, a0_); }
        t = f_145318(buf, d_1b62f4);
        for (short i = 0; i < s40; i++) {
            for (short j = 0; j < ngrp; j++) {
                int t_82 = f_145547(t, g + j * 0x1c, 14);
                if (t_82 == 0) { p42[i] = j; break; }
            }
            while (*(signed char *)t++ != 0) ;
            if ((signed char)*t == (signed char)10) t++;
        }
        f_0bdde0(d_1c11b8, buf, d_1a0170, 0xc9);
    } else {
        f_0ed8f0(d_1c1190, 0x29a000e, nm);
    }
    f_0bdde0(d_1c11b8, g, d_1a0170, 0xd4);
    short mx = 0;
#if FIX_R005   /* R005: Maximale Modulgroesse ueber alle ngrp Archivmodule statt nur ueber s40 .MOD-Zeilen bestimmen */
    for (short i = 0; i < ngrp; i++) {
#else
    for (short i = 0; i < s40; i++) {
#endif
        f_145279(fd, l1e + i * 0x1c, 0);
        f_144e8b(fd, &e46, 0x1c);
        c3e = i;
        if ((unsigned)mx < e46.n) mx = e46.n;
    }
    char *np = new (mark(d_1a0170, 0xdf)) char[mx * 2];
    c3e = -1;
    p7e = (short *)np;
}

//@ f_013a40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hilfsfunktion zum Zählen der Zeilen eines mit CR/LF getrennten Textpuffers: zerlegt den
 *   Puffer mit strtok an "\r", wendet f_1454d0 (Groß-/Kleinschreibungsumwandlung) auf jedes Token an und gibt
 *   die Anzahl der Tokens minus 1 zurück.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this) und Textpuffer (s, wird durch strtok verändert);
 *   gibt die Zeilenanzahl (short) zurück.
 * - Wichtige Variablen & Daten: Trennzeichen-Strings d_1b62f0 und d_1b62f2 ("\r").
 === Ende Beschreibung === */
short AL::f_013a40(char *s)
{
    char *t = f_145318(s, d_1b62f0);
    short n = 0;
    while (t) {
        f_1454d0(t);
        n++;
        t = f_145318(0, d_1b62f2);
    }
    n--; return n;
}

//@ f_013a70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zerlegt eine 32-Bit-Ressourcen-/Datei-ID (PID) in den 0-basierten Modulindex (Hochwort -
 *   1, als Index in p42) und die Eintragsnummer innerhalb des Moduls (Tiefwort, als Index in p7e).
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this), 32-Bit-Datei-ID (p2) sowie zwei Ausgabezeiger für
 *   Modulzeile (*p3) und Eintragsnummer (*p4); keine Rückgabe.
 * - Wichtige Variablen & Daten: Berechnet *p3 = ((p2 & 0xffff0000) >> 16) - 1 und *p4 = (short)p2.
 === Ende Beschreibung === */
void AL::f_013a70(PID p2, short *p3, short *p4)
{
    *p4 = (short)p2;
    *p3 = ((p2 & 0xffff0000) >> 16) - 1;
}

//@ f_013a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 28-Byte-Moduleintrag mit Archivindex di aus der Modultabelle (l1e + di * 28) in
 *   das Pufferfeld e46 und setzt den Merker c3e = di, lädt jedoch die zugehörige Datei-Indexliste p7e *nicht*
 *   nach.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this) und Archiv-Modulnummer (di); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder fd, l1e, e46 (aktueller Moduleintrag) und c3e (gepufferte
 *   Modulnummer).
 * - Besonderheiten / Originalfehler: Setzt c3e = di, obwohl p7e nicht aktualisiert wurde. Ein nachfolgender
 *   Aufruf von ldg(di) / f_013ad0(di) prüft if (di != c3e) und überspringt dann das Laden von p7e, sodass mit
 *   einer falschen Indexliste weitergearbeitet würde.
 === Ende Beschreibung === */
void AL::f_013a80(short di)
{
    f_145279(fd, di * 28 + l1e, 0);
    f_144e8b(fd, &e46, 0x1c);
#if FIX_R005   /* R005: c3e auf -1 setzen, da p7e in f_013a80 nicht nachgeladen wird */
    c3e = -1;
#else
    c3e = di;
#endif
}

//@ f_013ad0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt sicher, dass das .ALF-Archiv geöffnet ist (öffnet es bei fd == -1 neu und prüft die
 *   "ALF "-Kennung), und lädt bei einem Modulwechsel (di != c3e) sowohl den Moduleintrag e46 als auch dessen
 *   Datei-Indexliste p7e in den Speicher.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this) und Archiv-Modulnummer (di); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder fd, c3e, e46, p7e, l1e und l24 (Dateioffset der Modul-Indexlisten).
 === Ende Beschreibung === */
void AL::f_013ad0(short di)
{
    if (fd == -1) chk();
    ldg(di);
}

//@ f_013ba0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt bei Bedarf (di != c3c) den 28-Byte-Dateieintrag di aus der Dateitabelle (p12 + di *
 *   28) in das Feld e62 und positioniert den Dateizeiger des .ALF-Archivs auf das erste Datenbyte dieser
 *   eingebetteten Datei (l18 + e62.off).
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this) und Dateinummer im Archiv (di); keine Rückgabe.
 * - Wichtige Variablen & Daten: Objektfelder c3c (aktuell gepufferte Dateinummer), e62 (aktueller Dateieintrag
 *   mit off und Länge n), p12 (Offset Dateitabelle) und l18 (Offset Datenbereich).
 === Ende Beschreibung === */
void AL::f_013ba0(short di)
{
    if (di != c3c) {
        f_145279(fd, di * 28 + p12, 0);
        f_144e8b(fd, &e62, 0x1c);
        c3c = di;
    }
    f_145279(fd, l18 + e62.off, 0);
}

//@ f_013c00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Extrahiert eine einzelne im .ALF-Archiv enthaltene Datei als eigenständige Datei in ein
 *   Zielverzeichnis (dir\name), kopiert ihren Inhalt in 16-KB-Blöcken (0x4000 Bytes) und übernimmt abschließend
 *   den originalen DOS-Zeitstempel (dt/tm) des Archiveintrags.
 * - Eingaben / Rückgabe: Zeiger auf das AlfDisk-Objekt (this), Zielverzeichnis-String (dir) und Kopie des
 *   28-Byte-Dateieintrags (r); gibt 1 bei vollständigem Kopiererfolg, 0 bei Dateiöffnungs-, Lese- oder
 *   Schreibfehler zurück.
 * - Wichtige Variablen & Daten:
 *   - buf: Dynamischer 16-KB-Kopierpuffer (0x4000 Bytes).
 *   - path: Dynamischer Zielpfadpuffer (0x118 Bytes), ergänzt bei Bedarf einen fehlenden Backslash '\\'.
 *   - r: Archiveintrag (r.name Dateiname, r.off Datenoffset relativ zu l18, r.n Dateigröße in Bytes, r.dt/r.tm
 *     DOS-Datum und -Uhrzeit).
 === Ende Beschreibung === */
#pragma intrinsic(strcpy, strcat, strlen)
int AL::f_013c00(char *dir, Rec r)
{
    int ok = 1;
    char *buf = new(mark(d_1a0170, 0x160)) char[0x4000];
    char *path = new(mark(d_1a0170, 0x161)) char[0x118];
    int h;
    unsigned i;
    unsigned c;
    int len;
    strcpy(path, dir);
    len = strlen(path);
    if (len > 0 && path[len - 1] != ':' && path[len - 1] != '\\') {
        path[len] = '\\';
        path[len + 1] = 0;
    }
    strcat(path, r.name);
    h = f_144fbf(path, 0x261, 0x180);
    if (h >= 0) {
        f_145279(fd, l18 + r.off, 0);
        i = 0;
        while (i < r.n && ok == 1) {
            c = r.n - i;
            if (c >= 0x4000) c = 0x4000;
            if (f_144e8b(fd, buf, c) != c) {
                ok = 0;
            } else if (f_144cb6(h, buf, c) != c) {
                ok = 0;
            } else {
                i += c;
            }
        }
        f_145590(h, r.dt, r.tm);
        f_145259(h);
    } else {
        ok = 0;
    }
    delete path;
    delete buf;
    return ok;
}
