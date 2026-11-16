/* === Beschreibung (Katalog) ===
 * Einheit fz_148570 (0x148570 - 0x149292)
 *
 * Überblick
 * Diese Einheit implementiert den direkten Festplatten-Dateisystemtreiber (realdisk.cpp, Klasse RD), der im
 * zentralen Dateimanager (d_1c2098) für lose Dateien im Arbeitsverzeichnis sowie als Basisklasse für
 * verzeichnisbasierte Dateisysteme zuständig ist. Er kapselt die C-Laufzeit-Dateifunktionen (fopen, fclose,
 * fread, fwrite, fseek, ftell, unlink, _chsize) hinter der einheitlichen virtuellen Dateischnittstelle des
 * Spiels und bietet zusätzlich Funktionen zum Einfügen (f_148e00) und Herausschneiden (f_149010) von
 * Datenblöcken mitten in bestehenden Dateien.
 === Ende Beschreibung === */
// P3 23/25 gleich (suche.py 23.10.2026, Basis fz_148570_P1.CPP)
// fz_148570.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x148570-0x149292
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_1664d0(const char *p1, const char *p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1b8cf3[];
extern const char d_1b8cfc[];
extern int d_1bbed4;                    // 0x1BBED4
extern const char d_1a9874[];           // Text 0x1A9874
extern const char d_1b8b44[];           // Text 0x1B8B44
extern const char d_1b8b4c[];           // Text 0x1B8B4C
extern const char d_1b8b63[];           // Text 0x1B8B63
extern const char d_1b8b6a[];           // Text 0x1B8B6A
extern const char d_1b8b81[];           // Text 0x1B8B81
extern const char d_1b8b89[];           // Text 0x1B8B89
extern const char d_1b8ba0[];           // Text 0x1B8BA0
extern const char d_1b8ba8[];           // Text 0x1B8BA8
extern const char d_1b8be8[];           // Text 0x1B8BE8
extern const char d_1b8bff[];           // Text 0x1B8BFF
extern const char d_1b8c07[];           // Text 0x1B8C07
extern const char d_1b8c47[];           // Text 0x1B8C47
extern const char d_1b8c4e[];           // Text 0x1B8C4E
extern const char d_1b8c55[];           // Text 0x1B8C55
extern const char d_1b8c5c[];           // Text 0x1B8C5C
extern const char d_1b8c85[];           // Text 0x1B8C85
extern const char d_1b8c8c[];           // Text 0x1B8C8C
extern const char d_1b8c94[];           // Text 0x1B8C94
extern const char d_1b8c9b[];           // Text 0x1B8C9B
extern const char d_1b8cb2[];           // Text 0x1B8CB2
extern const char d_1b8cba[];           // Text 0x1B8CBA
extern const char d_1b8cc1[];           // Text 0x1B8CC1
extern const char d_1b8cc8[];           // Text 0x1B8CC8
extern const char d_1b8cdf[];           // Text 0x1B8CDF
extern const char d_1b8ce6[];           // Text 0x1B8CE6
extern const char d_1b8cf5[];           // Text 0x1B8CF5
extern const char d_1b8d12[];           // Text 0x1B8D12
extern const char d_1b8d3b[];           // Text 0x1B8D3B
extern const char d_1b8d64[];           // Text 0x1B8D64
extern const char d_1b8d6b[];           // Text 0x1B8D6B
extern const char d_1b8d82[];           // Text 0x1B8D82

#define I(p,o) (*(int *)((p)+(o)))
#define W(p,o) (*(short *)((p)+(o)))
#define M8(p) (*(unsigned char *)((p)+8))
#define ERR(s,l) f_1664d0(s, d_1a9874, l)
struct RD {
  virtual int s00(); virtual int s04(); virtual char *v08(int id); virtual int s0c(); virtual int s10();
  virtual int v14(int id, int m); virtual int s18(); virtual int v1c(int x); virtual int v20(void *b, int n);
  virtual int v24(void *b, int n); virtual int v28(); virtual int s2c(); virtual unsigned v30();
  virtual int s34(); virtual int v38(int n); virtual int s3c(); virtual int v40(int o, int w);
  virtual int s44(); virtual int s48(); virtual int v4c(int x); virtual int s50(); virtual int s54();
  virtual int v58(unsigned short a, unsigned short b);
};
#define V(p) ((RD *)(p))
int f_145300(void *p, int c, unsigned n);
int f_145234(int p1, void *p2);
int f_145254();
int f_15f1e1(int a, int b);
void f_15ebd6(int a);
int f_144fbf(const char *name, int mode, ...); int f_1492b4(const char *n, int a, void *d);
int f_144e8b(int h, void *buf, unsigned n);
int f_144cb6(int h, const void *b, int n);
int f_145259(int h);
int f_1452bc(int h);
int f_1455a4(int h);
int f_145279(int h, int pos, int whence);
int f_149336(const char *n);
int f_16a9da(int h, int n);
int f_145590(int h, unsigned short d, unsigned short t);
extern char d_1bbf7c[];
inline int EQ(int a,int b){return a==b;}

//@ f_148570
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des direkten Festplatten-Dateitreibers (RD). Er ruft den Basiskonstruktor
 *   (f_144610) auf, setzt die virtuelle Methodentabelle (d_1a99c4) und initialisiert das Statusfeld +0x04 mit 0.
 * - Eingaben: p (Zeiger auf das RD-Objekt).
 * - Rückgabewert: Gibt p zurück.
 * - Wichtige Variablen: I(0x04) (Statusfeld).
 === Ende Beschreibung === */
int f_148570(int p, int p2)
{
  I(p,0) = (int)d_1bbf7c;
  I(p,4) = 0;
  I(p,0xe) = p2;
  I(p,0xa) = 0;
  f_145300((void *)(p + 0x12), 0, 0x90);
  int t = f_15f1e1(0, 0);
  V(p)->v4c(t);
  f_15ebd6(t);
  return p;
}
//@ f_1485c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft über eine Dateisuche (_dos_findfirst / f_1492b4, f_149336), ob eine Datei mit dem
 *   Namen p2 im Dateisystem existiert (virtuelle Methode s20).
 * - Eingaben: p (Treiberobjekt), p2 (Dateiname als const char *).
 * - Rückgabewert: 1, wenn die Datei existiert, sonst 0.
 * - Wichtige Variablen: buf (find_t-Struktur auf dem Stack).
 === Ende Beschreibung === */
int f_1485c0(int p, unsigned fl)
{
  if (fl & 4) {
    f_145234(p, &d_1bbed4);
    f_145254();
    return p;
  }
  I(p,0) = (int)d_1bbf7c;
  if (I(p,4) != 0) ERR(d_1b8b44, 0x32);
  if (fl & 2) delete (char *)p;
  return p;
}
//@ f_148620
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schlägt zu einer 16-Bit-Ressourcen-ID id den zugehörigen Dateinamen in der
 *   Dateinamentabelle I(p, 0x0e) des Festplatten-Dateitreibers nach (virtuelle Methode v08). Falls in id eines
 *   der oberen 16 Bits gesetzt ist (id & 0xffff0000), bricht die Funktion mit dem Fehler d_1b8b4c ab.
 * - Eingaben: p (Zeiger auf das RD-Treiberobjekt), id (16-Bit-Datei-ID).
 * - Rückgabewert: Zeiger auf den Dateinamen-String (t[id]).
 * - Wichtige Variablen: t (Zeiger auf das Array der Dateinamen-Strings bei Offset +0x0e).
 === Ende Beschreibung === */
int f_148620(int p, unsigned id)
{
  if (id & 0xffff0000) ERR(d_1b8b4c, 0x3d);
  int *t = (int *)I(p,0xe); return t[id];
}
//@ f_148650
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet eine Datei mit dem Dateinamen p2 entsprechend der Modus-Bitmaske p3 (1 = Lesen
 *   "rb", 2 = Lesen/Schreiben "r+b" bzw. neu anlegen "w+b", 4 = Anhängen "a+b", 8 = Überschreiben "wb") über
 *   fopen (f_149343) und positioniert den Dateizeiger bei Bedarf an den Dateianfang (virtuelle Methode s2).
 * - Eingaben: p (Treiberobjekt), p2 (Dateiname), p3 (Modus-Flags).
 * - Rückgabewert: Geöffneter FILE *-Zeiger oder 0.
 * - Wichtige Variablen: fp (zurückgegebener FILE *-Stream).
 === Ende Beschreibung === */
int f_148650(int p)
{
  if (I(p,4) == 0) ERR(d_1b8b63, 0x4b);
  int i = I(p,0xa); int *t = (int *)I(p,0xe); return t[i];
}
//@ f_148680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die Datei mit der 16-Bit-ID id auf der Festplatte existiert und geöffnet werden
 *   kann, indem probeweise die virtuelle Öffnen-Methode v14(id, 0x200) im Lesemodus aufgerufen und die Datei bei
 *   Erfolg sofort wieder über v28() geschlossen wird.
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID).
 * - Rückgabewert: 1, wenn die Datei geöffnet werden konnte, sonst 0.
 * - Wichtige Variablen: r (Erfolgsflag), I(p, 4) (aktuelles Dateihandle, muss beim Aufruf 0 sein).
 === Ende Beschreibung === */
int f_148680(int p, unsigned id)
{
  int r = 0;
  if (id & 0xffff0000) ERR(d_1b8b6a, 0x5d);
  if (I(p,4) != 0) ERR(d_1b8b81, 0x5e);
  if (V(p)->v14(id, 0x200) == 1) {
    V(p)->v28();
    r = 1;
  }
  return r;
}
//@ f_1486f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Legt eine Datei mit der 16-Bit-ID id im Arbeitsverzeichnis p + 0x12 neu zum Lesen und
 *   Schreiben an (open-Modus 0x261 = O_RDWR | O_CREAT | O_TRUNC | O_BINARY, Zugriffsrechte 0x180 über f_144fbf),
 *   liest ihre DOS-Dateiattribute über _dos_findfirst (f_1492b4) nach p + 0xa2 ein und speichert das Dateihandle
 *   in I(p, 4).
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID).
 * - Rückgabewert: 1 bei erfolgreichem Anlegen/Öffnen, sonst 0.
 * - Wichtige Variablen: buf (temporärer 156-Byte-Pfadpuffer aus Verzeichnis p + 0x12 und Dateiname v08(id)),
 *   I(p, 4) (Dateihandle), W(p, 8) (Modus 0x261).
 === Ende Beschreibung === */
int f_1486f0(int p, unsigned id)
{
  int ret = 0;
  if (id & 0xffff0000) ERR(d_1b8b89, 0x74);
  if (I(p,4) != 0) ERR(d_1b8ba0, 0x75);
  I(p,0xa) = id;
  char *buf = new (mark(d_1a9874, 0x79)) char[0x9c];
  strcpy(buf, (char *)(p + 0x12));
  strcat(buf, V(p)->v08(id));
  W(p,8) = 0x261;
  I(p,4) = f_144fbf(buf, W(p,8), 0x180); f_1492b4(buf, 1, (void *)(p + 0xa2));
  if (*(signed char *)(p + 0xb7) == 1 && (W(p,8) == 1 || W(p,8) == 2)) f_1664d0(d_1b8ba8, buf, 0x86);
  delete buf;
  if (I(p,4) <= 0) { I(p,4) = 0; I(p,0xa) = 0; }
  else ret = 1;
  return ret;
}
//@ f_148840
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Datei mit der 16-Bit-ID id im Verzeichnis p + 0x12 mit dem übergebenen
 *   Öffnungsmodus p3 über f_144fbf, prüft über f_1492b4 (_dos_findfirst), ob eine schreibgeschützte Datei
 *   (*(signed char *)(p + 0xb7) == 1) unzulässig im Schreibmodus (p3 == 1 oder p3 == 2) geöffnet wurde, und
 *   speichert das Handle in I(p, 4) (virtuelle Methode v14).
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID), p3 (Öffnungsmodus-Flags).
 * - Rückgabewert: 1 bei Erfolg, sonst 0.
 * - Wichtige Variablen: buf (156-Byte-Pfadpuffer), I(p, 4) (Dateihandle), W(p, 8) (gespeicherter Öffnungsmodus
 *   p3).
 === Ende Beschreibung === */
int f_148840(int p, unsigned id, short p3)
{
  int ret = 0;
  if (id & 0xffff0000) ERR(d_1b8be8, 0xa6);
  if (I(p,4) != 0) ERR(d_1b8bff, 0xa7);
  I(p,0xa) = id;
  char *buf = new (mark(d_1a9874, 0xab)) char[0x9c];
  strcpy(buf, (char *)(p + 0x12));
  strcat(buf, V(p)->v08(id));
  W(p,8) = p3;
  I(p,4) = f_144fbf(buf, p3, 0x180); f_1492b4(buf, 1, (void *)(p + 0xa2));
  if (*(signed char *)(p + 0xb7) == 1 && (W(p,8) == 1 || W(p,8) == 2)) f_1664d0(d_1b8c07, buf, 0xb8);
  delete buf;
  if (I(p,4) <= 0) { I(p,4) = 0; I(p,0xa) = 0; }
  else ret = 1;
  return ret;
}
//@ f_148990
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Datei mit der ID id im Lesemodus (v14(id, 0x200)), liest ihren gesamten Inhalt
 *   über die virtuelle Methode v1c(p3) (f_1489d0) in den Zielpuffer p3 ein und schließt die Datei anschließend
 *   wieder (v28()).
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID), p3 (Zielpufferadresse).
 * - Rückgabewert: Rückgabewert von v1c(p3) bzw. 0, wenn die Datei nicht geöffnet werden konnte.
 * - Wichtige Variablen: r (Rückgabewert).
 === Ende Beschreibung === */
int f_148990(int p, int id, int p3)
{
  int r = 0;
  if (V(p)->v14(id, 0x200) == 1) {
    r = V(p)->v1c(p3);
    V(p)->v28();
  }
  return r;
}
//@ f_1489d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den kompletten Inhalt der aktuell in I(p, 4) geöffneten Datei in den Puffer buf,
 *   indem zuerst per v40(0, 0) an den Dateianfang gesprungen, dann über f_1452bc (filelength) die Dateigröße n
 *   ermittelt und schließlich n Bytes über f_144e8b (read) eingelesen werden (virtuelle Methode v1c).
 * - Eingaben: p (RD-Treiberobjekt), buf (Zielpufferadresse).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: n (ermittelte Gesamtgröße der geöffneten Datei).
 === Ende Beschreibung === */
void f_1489d0(int p, int buf)
{
  if (I(p,4) == 0) ERR(d_1b8c47, 0xe9);
  V(p)->v40(0, 0);
  int n = f_1452bc(I(p,4));
  f_144e8b(I(p,4), (void *)buf, n);
}
//@ f_148a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest n Bytes ab der aktuellen Dateiposition aus dem geöffneten Dateihandle I(p, 4) über
 *   f_144e8b (read) in den Puffer buf ein (virtuelle Methode v20). Ist keine Datei geöffnet (I(p, 4) == 0), wird
 *   mit Fehler d_1b8c4e abgebrochen.
 * - Eingaben: p (RD-Treiberobjekt), buf (Zielpuffer), n (Anzahl der zu lesenden Bytes).
 * - Rückgabewert: Keiner (void, im Assembler Rückgabewert von f_144e8b in EAX).
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
void f_148a20(int p, int buf, int n)
{
  int b = buf;
  buf = b;
  if (I(p,4) == 0) ERR(d_1b8c4e, 0xf8);
  f_144e8b(I(p,4), (void *)b, n);
}
//@ f_148a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt n Bytes aus dem Puffer buf über f_144cb6 (write) in die aktuell geöffnete Datei
 *   I(p, 4) (virtuelle Methode v24), nachdem geprüft wurde, dass eine Datei geöffnet ist und im Modusbyte M8(p)
 *   Schreibzugriff (Bit 0 oder Bit 1) erlaubt ist.
 * - Eingaben: p (RD-Treiberobjekt), buf (Quellpuffer), n (Anzahl der zu schreibenden Bytes).
 * - Rückgabewert: Keiner (void, im Assembler Rückgabewert von f_144cb6 in EAX).
 * - Wichtige Variablen: I(p, 4) (Dateihandle), M8(p) (Öffnungsmodus-Flags bei Offset +8).
 === Ende Beschreibung === */
void f_148a60(int p, int buf, int n)
{
  int b = buf;
  buf = b;
  if (I(p,4) == 0) ERR(d_1b8c55, 0x106);
  if ((M8(p) & 1) == 0 && (M8(p) & 2) == 0) ERR(d_1b8c5c, 0x107);
  f_144cb6(I(p,4), (void *)b, n);
}
//@ f_148ac0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schließt das aktuell geöffnete Dateihandle I(p, 4) über f_145259 (close) und setzt sowohl
 *   das Handle I(p, 4) als auch die aktive Datei-ID I(p, 0x0a) auf 0 zurück (virtuelle Methode v28).
 * - Eingaben: p (RD-Treiberobjekt).
 * - Rückgabewert: 1, wenn close fehlerfrei (0) abgeschlossen wurde, sonst 0.
 * - Wichtige Variablen: r (Erfolgsflag).
 === Ende Beschreibung === */
int f_148ac0(int p)
{
  int r = 0;
  if (I(p,4) == 0) ERR(d_1b8c85, 0x118);
  if (f_145259(I(p,4)) == 0) r = 1;
  I(p,4) = 0;
  I(p,0xa) = 0;
  return r;
}
//@ f_148b10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt p4 Bytes aus dem Puffer p5 an den Dateioffset p3 der geöffneten Datei p2
 *   (virtuelle Methode s11). Liegt der Zieloffset p3 hinter dem bisherigen Dateiende, füllt die Funktion die
 *   Lücke zuvor mit Nullbytes auf.
 * - Eingaben: p (Treiberobjekt), p2 (FILE *), p3 (Zieloffset), p4 (Byteanzahl), p5 (Quellpuffer).
 * - Rückgabewert: Anzahl der geschriebenen Nutzbytes (p4) oder 0 bei Fehlern.
 * - Wichtige Variablen: sz (bisherige Dateigröße), diff (Größe einer eventuellen Lücke vor p3).
 === Ende Beschreibung === */
void f_148b10(int p)
{
  if (I(p,4) != 0) ERR(d_1b8c8c, 0x12c);
  I(p,0xa) = 0;
}
//@ f_148b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt über f_1452bc (filelength) die aktuelle Größe der geöffneten Datei I(p, 4) in
 *   Bytes (virtuelle Methode v30).
 * - Eingaben: p (RD-Treiberobjekt).
 * - Rückgabewert: Dateigröße in Bytes (int).
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
int f_148b40(int p)
{
  if (I(p,4) == 0) ERR(d_1b8c94, 0x139);
  return f_1452bc(I(p,4));
}
//@ f_148b70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt die Dateigröße einer nicht geöffneten Datei anhand ihrer 16-Bit-ID id, indem die
 *   Datei kurzzeitig im Lesemodus geöffnet (v14(id, 0x200)), ihre Länge über v30() (f_148b40) abgefragt und die
 *   Datei sofort wieder geschlossen wird (v28()).
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID).
 * - Rückgabewert: Dateigröße in Bytes oder 0, falls die Datei nicht geöffnet werden konnte.
 * - Wichtige Variablen: r (ermittelte Dateigröße).
 === Ende Beschreibung === */
int f_148b70(int p, unsigned id)
{
  int r = 0;
  if (id & 0xffff0000) ERR(d_1b8c9b, 0x14a);
  if (I(p,4) != 0) ERR(d_1b8cb2, 0x14b);
  if (V(p)->v14(id, 0x200) == 1) {
    r = V(p)->v30();
    V(p)->v28();
  }
  return r;
}
//@ f_148be0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt über f_1455a4 (tell) die aktuelle Lese-/Schreibposition des Dateizeigers in der
 *   geöffneten Datei I(p, 4) zurück.
 * - Eingaben: p (RD-Treiberobjekt).
 * - Rückgabewert: Aktueller Byte-Offset in der Datei (int).
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
int f_148be0(int p)
{
  if (I(p,4) == 0) ERR(d_1b8cba, 0x160);
  return f_1455a4(I(p,4));
}
//@ f_148c10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Positioniert den Dateizeiger der geöffneten Datei I(p, 4) über f_145279 (lseek) um off
 *   Bytes relativ zum Modus wh (SEEK_SET, SEEK_CUR, SEEK_END; virtuelle Methode v40).
 * - Eingaben: p (RD-Treiberobjekt), off (Byte-Offset), wh (Positionierungsmodus short).
 * - Rückgabewert: Neue Dateizeigerposition (int).
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
int f_148c10(int p, int off, short wh)
{
  if (I(p,4) == 0) ERR(d_1b8cc1, 0x172);
  return f_145279(I(p,4), off, wh);
}
//@ f_148c50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löscht die zur 16-Bit-ID id gehörige Datei im Verzeichnis p + 0x12 über f_149336 (unlink /
 *   remove) von der Festplatte.
 * - Eingaben: p (RD-Treiberobjekt), id (16-Bit-Datei-ID).
 * - Rückgabewert: 1 bei erfolgreichem Löschen (f_149336(buf) == 0), sonst 0.
 * - Wichtige Variablen: buf (temporärer 156-Byte-Pfadpuffer für Verzeichnis + Dateiname).
 === Ende Beschreibung === */
int f_148c50(int p, unsigned id)
{
  int r = 0;
  if (id & 0xffff0000) ERR(d_1b8cc8, 0x182);
  char *buf = new (mark(d_1a9874, 0x184)) char[0x9c];
  strcpy(buf, (char *)(p + 0x12));
  strcat(buf, V(p)->v08(id));
  if (f_149336(buf) == 0) r = 1;
  delete buf;
  return r;
}
//@ f_148d20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Dateigröße der aktuell geöffneten Datei I(p, 4) über f_16a9da (chsize) auf len
 *   Bytes (virtuelle Methode v38).
 * - Eingaben: p (RD-Treiberobjekt), len (neue Dateigröße in Bytes).
 * - Rückgabewert: 1 bei Erfolg (f_16a9da == 0), sonst 0.
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
int f_148d20(int p, int len)
{
  int r = 0;
  if (I(p,4) == 0) ERR(d_1b8cdf, 0x19d);
  if (f_16a9da(I(p,4), len) == 0) r = 1;
  return r;
}
//@ f_148d60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt einen Zeiger auf den im Treiberobjekt p ab Offset +0x12 gespeicherten
 *   Basisverzeichnispfad zurück.
 * - Eingaben: p (RD-Treiberobjekt).
 * - Rückgabewert: Zeiger auf den Pfad-String (p + 0x12).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_148d60(int p)
{
  return p + 0x12;
}
//@ f_148d70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert den Verzeichnispfad s in das Pfadfeld p + 0x12 des Treiberobjekts und hängt
 *   automatisch einen Backslash '\' (d_1b8cf3) an, falls s noch nicht mit '\' endet (virtuelle Methode v4c).
 * - Eingaben: p (RD-Treiberobjekt), s (Verzeichnispfad als const char *).
 * - Rückgabewert: Immer 1.
 * - Wichtige Variablen: (char *)(p + 0x12) (144-Byte-Pfadpuffer im Objekt).
 === Ende Beschreibung === */
int f_148d70(int p, const char *s)
{
  if (s == 0) ERR(d_1b8ce6, 0x1bc);
  strcpy((char *)(p + 0x12), s);
  if (((char *)(p + 0x12))[strlen((char *)(p + 0x12)) - 1] != '\\') strcat((char *)(p + 0x12), d_1b8cf3);
  return 1;
}
//@ f_148e00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt p4 Bytes aus dem Puffer p5 mitten in die geöffnete Datei p2 am Offset p3 ein, indem
 *   der nachfolgende Dateiteil blockweise (in 2048-Byte-Schritten von hinten nach vorne) nach hinten verschoben
 *   und anschließend der neue Block an Position p3 geschrieben wird (virtuelle Methode s14).
 * - Eingaben: p (Treiberobjekt), p2 (FILE *), p3 (Einfügeoffset), p4 (Länge des einzufügenden Blocks), p5
 *   (Quellpuffer).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehlern.
 * - Wichtige Variablen:
 *   - buf: Temporärer 2048-Byte-Verschiebepuffer.
 *   - rem: Noch zu verschiebende Bytes des hinteren Dateiteils.
 === Ende Beschreibung === */
int f_148e00(int p, unsigned off, int data, int len)
{
  int ok = 0;
  unsigned rem, chunk, end, pos;
  if (I(p,4) == 0) ERR(d_1b8cf5, 0x1df);
  if (V(p)->v30() < off) ERR(d_1b8cfc, 0x1e0);
  if ((M8(p) & 1) == 0 && (M8(p) & 2) == 0) ERR(d_1b8d12, 0x1e1);
  end = len + V(p)->v30();
  if (V(p)->v38(end) == 1) {
    char *buf = new (mark(d_1a9874, 0x1e7)) char[0x1000];
    rem = end - off - len;
    chunk = rem > 0x1000 ? 0x1000 : rem;
    pos = end - chunk;
    ok = 1;
    while (rem > 0 && ok == 1) {
      if (rem > 0x1000) {
        V(p)->v40(pos - len, 0);
        if (V(p)->v20(buf, 0x1000) != 0x1000) ok = 0;
        V(p)->v40(pos, 0);
        if (V(p)->v24(buf, 0x1000) != 0x1000) ok = 0;
        rem -= 0x1000;
        chunk = rem > 0x1000 ? 0x1000 : rem;
        pos -= chunk;
      } else {
        V(p)->v40(pos - len, 0);
        if ((unsigned)V(p)->v20(buf, rem) != rem) ok = 0;
        V(p)->v40(pos, 0);
        if ((unsigned)V(p)->v24(buf, rem) != rem) ok = 0;
        rem = 0;
      }
    }
    delete buf;
  }
  if (ok == 1 && data != 0) {
    V(p)->v40(off, 0);
    if (V(p)->v24((void *)data, len) != len) ok = 0;
  }
  return ok;
}
//@ f_149010
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schneidet einen Bereich von p4 Bytes ab Offset p3 aus der geöffneten Datei p2 heraus,
 *   indem alle dahinter liegenden Daten in 2048-Byte-Blöcken nach vorne kopiert werden und die Datei
 *   anschließend über _chsize (f_14c005) auf die neue kürzere Länge gekürzt wird (virtuelle Methode s15).
 * - Eingaben: p (Treiberobjekt), p2 (FILE *), p3 (Startoffset des zu löschenden Bereichs), p4 (Anzahl der zu
 *   entfernenden Bytes).
 * - Rückgabewert: Neue Gesamtgröße der Datei nach dem Kürzen.
 * - Wichtige Variablen: buf (2048-Byte-Kopierpuffer), rem (nachrückende Bytes hinter dem gelöschten Bereich).
 === Ende Beschreibung === */
int f_149010(int p, int off, int len)
{
  int ok = 0;
  unsigned rem;
  int src, n, dst;
  if ((M8(p) & 1) == 0 && (M8(p) & 2) == 0) ERR(d_1b8d3b, 0x235);
  dst = off;
  src = len + off;
  if (V(p)->v40(src, 0) == src) {
    rem = V(p)->v30() - src;
    if (rem == 0) ok = 1;
    else {
      char *buf = new (mark(d_1a9874, 0x244)) char[0x1000];
      while (rem > 0) {
        if (rem >= 0x1000) {
          if (V(p)->v20(buf, 0x1000) == 0x1000) {
            src += 0x1000;
            V(p)->v40(dst, 0);
            n = V(p)->v24(buf, 0x1000);
            if (n == 0x1000) {
              dst += n;
              V(p)->v40(src, 0);
              ok = 1;
              rem -= 0x1000;
            } else { rem = 0; ok = 0; }
          } else { rem = 0; ok = 0; }
        } else {
          if ((unsigned)V(p)->v20(buf, rem) == rem) {
            V(p)->v40(dst, 0);
            if ((unsigned)V(p)->v24(buf, rem) == rem) { ok = 1; rem = 0; }
            else ok = 0;
          } else ok = 0;
        }
      }
      delete buf;
    }
    if (ok == 1) {
      if (V(p)->v38(V(p)->v30() - len) == 1) ok = 1;
      else ok = 0;
    }
  }
  return ok;
}
//@ f_1491c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das DOS-Änderungsdatum a und die Änderungszeit b der aktuell geöffneten Datei I(p,
 *   4) über _dos_setftime (f_145590; virtuelle Methode v58).
 * - Eingaben: p (RD-Treiberobjekt), a (DOS-Datumswert), b (DOS-Zeitwert).
 * - Rückgabewert: 1, wenn f_145590 0 liefert, sonst 0.
 * - Wichtige Variablen: I(p, 4) (Dateihandle).
 === Ende Beschreibung === */
int f_1491c0(int p, int a, int b)
{
  if (I(p,4) == 0) ERR(d_1b8d64, 0x297);
  return f_145590(I(p,4), a, b) == 0;
}
//@ f_149210
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leert die Dateipuffer eines geöffneten Streams (s17, hier als Platzhalter implementiert,
 *   der immer 1 zurückgibt).
 * - Eingaben: p (Treiberobjekt), p2 (FILE *).
 * - Rückgabewert: Immer 1.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_149210(int p, unsigned id, unsigned short a, unsigned short b)
{
  int r = 0;
  if (id & 0xffff0000) ERR(d_1b8d6b, 0x2ae);
  if (I(p,4) != 0) ERR(d_1b8d82, 0x2af);
  if (V(p)->v14(id, 0x200) == 1) {
    r = V(p)->v58(a, b);
    V(p)->v28();
  }
  return r;
}
