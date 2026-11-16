/* === Beschreibung (Katalog) ===
 * Einheit fz_15f342 (0x15F342 - 0x15F3E5)
 *
 * Überblick
 * Diese Einheit enthält hardwarenahe VGA-Videospeicher-Routinen (0xA0000) zum schnellen Füllen von horizontalen
 * und vertikalen Linien (f_15f342, f_15f35d), zum Auslesen und Beschreiben von VGA-Speicherzeilen (f_15f367,
 * f_15f385) und vertikalen Spalten (f_15f3a0, f_15f3bc) sowie einen Fehler-Wrapper (f_15f3d4).
 === Ende Beschreibung === */
// P3 1/7 gleich (suche.py 25.10.2026, Basis fz_15f342_P1.CPP)
// OPT -4r -oneax -zp1 -s
// CC wcc386
// fz_15f342.cpp - Pass 1
#pragma aux f_15f342 "*";
#pragma aux f_15f35d "*";
#pragma aux f_15f367 "*";
#pragma aux f_15f385 "*";
#pragma aux f_15f3bc "*";
#pragma aux f_15f3d4 "*";
extern const char d_1aa55a[];
void f_16acea(const char *a, int b, int c);
//@ f_15f342
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt n aufeinanderfolgende Bytes ab der Adresse p mit dem Farbwert v, wobei nach einem
 *   eventuellen ungeraden Startbyte paarweise 16-Bit-Wörter (u.w) geschrieben werden.
 * - Eingaben: Zielzeiger p, Byteanzahl n und Füllwert v.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - u: Union zum Verdoppeln des Farbbytes v auf ein 16-Bit-Wort.
 === Ende Beschreibung === */
void f_15f342(char *p, unsigned short n, char v)
{
  union { unsigned short w; unsigned char b[2]; } u;
  if (n & 1) {
    *p = v;
    p++;
  }
  n >>= 1;
  if (n != 0) {
    u.b[1] = (unsigned char)v;
    u.b[0] = (unsigned char)v;
    do {
      *(unsigned short *)p = u.w;
      p += 2;
      n--;
    } while (n != 0);
  }
}
//@ f_15f35d
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt n Pixel mit dem Farbwert v im festen Adressabstand s (z. B. 320 für eine
 *   vertikale Linie) ab der Startadresse p.
 * - Eingaben: Startzeiger p, Pixelanzahl n, Farbwert v und Schrittweite s.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_15f35d(char *p, int n, char v, int s)
{
  do {
    *(volatile char *)p = v;
    --*(short *)&n;
    p = &p[s];
  } while ((short)n != 0);
}
//@ f_15f367
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert eine komplette 320-Pixel-Bildschirmzeile (0x50 = 80 Langwörter zu je 4 Bytes) ab
 *   dem VGA-Videospeicher-Offset 0xA0000 + off in den Zielpuffer dst.
 * - Eingaben: Videospeicher-Offset off und Zielpuffer dst.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Quellzeiger im VGA-Segment 0xA0000 + off.
 === Ende Beschreibung === */
void f_15f367(int off, unsigned *dst)
{
  int z1 = 0;
  int z2;
  int z3;
  union { int n; short w; } c;
  unsigned *s;
  if (!(off & z1))
    s = (unsigned *)0xa0000;
  else
    c.n = off;
  z2 = 0;
  if (!(off & z2))
    s = (unsigned *)((char *)s + off);
  c.w = 0x50;
  z3 = 0;
  do {
    off = (c.n & z3) ? off : *s;
    *(volatile unsigned *)dst = off;
    s++;
    dst++;
    c.w--;
  } while (c.w != 0);
}
//@ f_15f385
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kopiert n Bytes (in n >> 2 32-Bit-Langwörtern) aus dem Quellpuffer src in den
 *   VGA-Videospeicher ab 0xA0000 + off.
 * - Eingaben: Videospeicher-Offset off, Quellpuffer src und Byteanzahl n.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d: Zielzeiger im VGA-Segment 0xA0000 + off.
 *   - k: Anzahl der zu kopierenden 32-Bit-Wörter (n >> 2).
 === Ende Beschreibung === */
#pragma aux f_15f385 "*" modify [esi];
void f_15f385(int off, unsigned *src, unsigned n)
{
  int z1 = 0;
  int z2;
  int z3;
  union { int n; short w; } c;
  unsigned *d;
  short k = (short)(n >> 2);
  if (!(off & z1))
    d = (unsigned *)0xa0000;
  else
    c.n = off;
  z2 = 0;
  if (!(off & z2))
    d = (unsigned *)((char *)d + off);
  z3 = 0;
  do {
    off = (c.n & z3) ? off : *src;
    *(volatile unsigned *)d = off;
    d++;
    src++;
    k--;
  } while (k != 0);
}
//@ f_15f3a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest eine 200 Pixel hohe vertikale Spalte (0xC8 = 200 Zeilen) mit der Zeilenschrittweite
 *   s ab dem VGA-Videospeicher-Offset 0xA0000 + off byteweise in den Puffer dst aus.
 * - Eingaben: Videospeicher-Offset off, Zielpuffer dst, Zeilenschrittweite s und ungenutzter Parameter t.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p: Laufender Lesezeiger im VGA-Speicher 0xA0000 + off.
 === Ende Beschreibung === */
#pragma aux f_15f3a0 "*" parm [eax] [edx] [ebx] [esi] modify [eax edx];
void f_15f3a0(int off, char *dst, int s, int t)
{
  int z1 = 0;
  int z2;
  int z3;
  union { int n; short w; } c;
  char *p;
  if (!(off & z1))
    p = (char *)0xa0000;
  else
    c.n = off;
  z2 = 0;
  if (!(off & z2))
    p += off;
  c.w = 0xc8;
  z3 = 0;
  do {
    *(char *)dst = *p;
    p = (c.n & z3) ? p : p + s;
    dst++;
    c.w--;
  } while (c.w != 0);
}
//@ f_15f3bc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt eine vertikale Pixelspalte aus dem Quellpuffer src mit der Zeilenschrittweite s
 *   in den VGA-Videospeicher ab 0xA0000 + off.
 * - Eingaben: Videospeicher-Offset off, Quellpuffer src, Zähler/Zeiger d und Zeilenschrittweite s.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
#pragma aux f_15f3bc "*" modify [eax ebx ecx edx esi];
void f_15f3bc(int off, char *src, char *d, int s)
{
  int z1 = 0;
  int z2;
  int z3;
  union { int n; short w; } c;
  c.n = (int)d;
  if (!(off & z1))
    d = (char *)0xa0000;
  else { unsigned shadow=(unsigned)src; /* haelt die Registerzuteilung wie im Original */
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    shadow *= (unsigned)s;
    off += shadow;
  }
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; 
   s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
  off = (off & 0) ? 0 : off; s = (s & 0) ? 0 : s;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
  z2 = 0;
  if (!(off & z2))
    d += off;
  z3 = 0;
  do {
    *(char *)d = *src;
    d = ((int)d & z3) ? d : d + s;
    src++;
    c.w--;
  } while (c.w != 0);
}
//@ f_15f3d4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Meldet einen Fehlerzustand mit dem festen Meldungstext d_1aa55a und den beiden
 *   Zusatzwerten a und b an die Fehlerbehandlungsroutine f_16acea.
 * - Eingaben: Fehlerparameter a und b.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1aa55a: Konstante Fehlermeldungs-Zeichenkette.
 === Ende Beschreibung === */
void f_15f3d4(int a, int b)
{
  f_16acea(d_1aa55a, a, b);
}
