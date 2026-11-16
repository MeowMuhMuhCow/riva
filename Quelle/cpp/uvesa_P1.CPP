/* === Beschreibung (Katalog) ===
 * Einheit uvesa (0x13E140 - 0x13F9A5)
 *
 * Überblick
 *
 * Die Einheit uvesa (uvesa.cpp) implementiert den laufzeitseitigen VESA-SVGA- und Standard-VGA-Grafiktreiber für
 * den gebankten Videospeicherzugriff. Sie kapselt das Umschalten von Grafikmodi (0x13, Textmodus 0x03 und
 * VESA-Modi über 0x4F02), das Umschalten und Abfragen der 64-KB-Speicherbänke (0x4F05), das Setzen und Lesen des
 * sichtbaren Bildausschnitts (0x4F07) und der logischen Zeilenbreite (0x4F06), einen eigenen Stapel zum Sichern
 * und Wiederherstellen der aktiven Banknummer sowie die vier zentralen zeilen- und bankübergreifenden
 * Grafikoperationen (Rechteck ins VRAM kopieren, Rechteck aus dem VRAM auslesen, Rechteck im VRAM einfarbig
 * füllen und Rechteck transparent ins VRAM kopieren).
 === Ende Beschreibung === */
// P3 16/22 gleich (suche.py 30.10.2026, Basis uvesa_P1.CPP)
// uvesa.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13E140-0x13F9B0
#include <string.h>
#include "R_FIX.H"
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene ---
int f_13d490(void *p1, void *p2, void *p3, void *p4, void *p5);
int f_149cd2(int n, void *in, void *out);   // int386
int f_14d075(int d, int s, int n);          // memmove
int f_145300(int d, int c, int n);          // memset
// --- Daten ---
struct VM { char z0[2]; unsigned char b2; unsigned char b3; short s4; char z6[2]; unsigned short s8; unsigned short sa; char zc[4]; unsigned short s10; unsigned short s12; unsigned short s14; };
extern signed char d_1a9449;
extern unsigned short d_1c10a8;
extern unsigned char d_1c10a9;
extern unsigned short d_1c10ac;
extern unsigned char d_1c10ac_l;
extern unsigned char d_1c10ad;
extern unsigned short d_1c10b0;
extern unsigned short d_1c10b4;
extern struct VM *d_1c1108;
extern unsigned char d_1c1110;
extern unsigned char d_1c1138[];
extern unsigned char d_1c1148;
extern int d_1c114c;
extern unsigned short d_1c1158;
extern volatile unsigned short d_1c115a; // verhindert Register-Konstanten-Wiederverwendung beim Nullsetzen in f_13e140
extern unsigned short d_1c115c;
extern unsigned short d_1c115e;
#define SWB(B) { d_1a9449 = (B); d_1c10a8 = 0x4f05; d_1c10ad = 0; d_1c10ac_l = 0; d_1c10b4 = (unsigned char)(B); f_149cd2(0x10, &d_1c10a8, &d_1c10a8); }
#define SWB1(B) { d_1a9449 = (B); d_1c10a8 = 0x4f05; d_1c10ad = 0; d_1c10ac_l = 0; d_1c10b4 = (unsigned char)(B); f_149cd2(0x10, &d_1c10a8, &d_1c10a8); }
#define SWB2(B) { d_1a9449 = (B); d_1c10a8 = 0x4f05; d_1c10b4 = (unsigned char)(B); d_1c10ad = 0; d_1c10ac_l = 0; f_149cd2(0x10, &d_1c10a8, &d_1c10a8); }
#define SWM(B) { if ((d_1c1108->b3 & 3) == 3) { d_1a9449 = 0xff; d_1c10a8 = 0x4f05; d_1c10b4 = (unsigned char)(B); d_1c10ad = 0; d_1c10ac_l = 1; f_149cd2(0x10, &d_1c10a8, &d_1c10a8); } else if (d_1a9449 != (unsigned char)(B)) SWB(B) }
#define TC2(D, S, N) if ((N) != 0) { unsigned char *d_ = (unsigned char *)(D); unsigned char *s_ = (unsigned char *)(S); unsigned char *e_ = d_ + (N); do { unsigned char c_ = *s_; if (c_ != p8) *d_ = c_; d_++; s_++; } while (d_ < e_); }

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_13e140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet die Grafikkarte in den gewünschten Videomodus mode. Handelt es sich um den
 *   Standard-VGA-Modus 0x13 (320x200x256) oder den Textmodus 0x03, wird der Modus direkt über BIOS-Interrupt
 *   0x10 gesetzt und bei Modus 0x13 der globale Modusbeschreiber d_1c1108 auf 320x200, 64-KB-Granularität und
 *   Segment 0xA000 initialisiert; andernfalls schaltet die Funktion über die VESA-Funktion AX = 0x4F02 in den
 *   angegebenen SVGA-Modus und setzt das Clipping-Rechteck (d_1c1158-d_1c115e) auf die volle
 *   Bildschirmauflösung.
 * - Eingaben: Gewünschte Videomodusnummer mode (short).
 * - Rückgabewert: 1 bei erfolgreichem Moduswechsel, sonst 0.
 * - Wichtige Variablen:
 *   - d_1a9449: Zuletzt eingestellte VESA-Banknummer (wird beim Moduswechsel auf 0xFF = ungültig zurückgesetzt).
 *   - d_1c114c: Flag (1 = aktiver VESA-SVGA-Modus, 0 = Standard-VGA- oder Textmodus).
 *   - d_1c1108: Zeiger auf den globalen Modusbeschreiber (ModeInfoBlock), aus dessen Feldern s12 (Breite) und
 *     s14 (Höhe) das Clipping-Rechteck d_1c1158..d_1c115e bestimmt wird.
 === Ende Beschreibung === */
char f_13e140(short mode)
{
  char r;
  unsigned short h, w;
  VM *p;
  d_1a9449 = 0xff;
  if (mode == 0x13 || mode == 3) {
    d_1c10a8 = mode;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    d_1c114c = 0;
    if (mode == 0x13) {
      d_1c1108->s10 = 0x140;
      d_1c1108->s12 = 0x140;
      d_1c1108->s14 = 200;
      d_1c1108->s4 = 0x40;
      d_1c1108->s8 = 0xa000;
      d_1c1108->b2 = 7;
      d_1c1108->s10 = 0x140;
    }
    r = 1;
  } else {
    if (d_1c1110 == 0) return 0;
    d_1c10a8 = 0x4f02;
    d_1c10ac = mode;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    d_1c114c = !d_1c10a9;
    r = d_1c114c;
  }
  p = d_1c1108;
  d_1c1158 = 0;
  d_1c115a = 0;
  h = p->s14 - 1; w = p->s12 - 1; d_1c115e = h; d_1c115c = w;
  return r;
}

//@ f_13e240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt zurück, ob sich die Grafikausgabe aktuell in einem erweiterten VESA-SVGA-Modus befindet.
 * - Eingaben: Keine.
 * - Rückgabewert: Wert des globalen VESA-Aktiv-Flags d_1c114c (1 = VESA-Modus aktiv, 0 =
 *   Standard-VGA/Textmodus).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13e240(void)
{
  return d_1c114c;
}

//@ f_13e250
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das primäre VESA-Speicherfenster (Fenster A, BL = 0) über die VESA-BIOS-Funktion AX =
 *   0x4F05, BH = 0 auf die Speicherseite (Bank) b um, sofern b nicht bereits in d_1a9449 als aktiv vermerkt ist.
 * - Eingaben: Ziel-Banknummer b (unsigned char).
 * - Rückgabewert: 1 bei Erfolg (oder wenn Bank b bereits aktiv war), 0 bei deaktiviertem VESA-Treiber oder
 *   BIOS-Fehler (d_1c10a9 != 0).
 * - Wichtige Variablen:
 *   - d_1a9449: Zwischengespeicherte aktive Banknummer zur Vermeidung überflüssiger Interrupt-Aufrufe.
 === Ende Beschreibung === */
char f_13e250(unsigned char b)
{
  if (d_1c1110 == 1) {
    const signed char &old = d_1a9449;
    if (old != b) {
      SWB1(b)
      return !d_1c10a9;
    }
    return 1;
  }
  return 0;
}

//@ f_13e2c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet für Lesezugriffe auf den Videospeicher das passende VESA-Speicherfenster auf die Bank
 *   b um. Unterstützt die Grafikkarte laut d_1c1108->b3 ((b3 & 3) == 3) ein separates, lesbares zweites
 *   Speicherfenster (Fenster B), wird dieses über AX = 0x4F05, BH = 0, BL = 1 geschaltet und der Cache d_1a9449
 *   invalidiert (0xFF); andernfalls schaltet die Funktion das primäre Fenster A (BL = 0) auf Bank b.
 * - Eingaben: Ziel-Banknummer b (unsigned char).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehler oder inaktivem VESA-Treiber.
 * - Wichtige Variablen:
 *   - d_1c1108->b3: Attributbyte des zweiten VESA-Speicherfensters (WinBAttributes).
 === Ende Beschreibung === */
struct BankRegs907 { unsigned short ax; unsigned short pad2; unsigned char bl,bh; unsigned short pad6; unsigned short cx,pad10,dx; };
static inline unsigned char swb_13e2c0(unsigned char b)
{
    if (d_1c1110 == 1) {
        if (d_1a9449 != b) {
            d_1a9449 = b;
            ((BankRegs907 *)&d_1c10a8)->ax = 0x4f05;
            ((BankRegs907 *)&d_1c10a8)->bh = 0;
            ((BankRegs907 *)&d_1c10a8)->bl = 0;
            ((BankRegs907 *)&d_1c10a8)->dx = b;
            f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
            return !d_1c10a9;
        }
        return 1;
    }
    return 0;
}
unsigned char f_13e2c0(unsigned char b)
{
    if (d_1c1110 == 1) {
        if ((d_1c1108->b3 & 3) == 3) {
            d_1a9449 = 0xff;
            ((BankRegs907 *)&d_1c10a8)->ax = 0x4f05;
            ((BankRegs907 *)&d_1c10a8)->bh = 0;
            ((BankRegs907 *)&d_1c10a8)->bl = 1;
            ((BankRegs907 *)&d_1c10a8)->dx = b;
            f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
            return !d_1c10a9;
        }
        return swb_13e2c0(b);
    }
    return 0;
}

//@ f_13e3a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet das primäre VESA-Speicherfenster (Fenster A, BL = 0) ohne Rückgabewertprüfung auf die
 *   Bank b um, falls diese noch nicht in d_1a9449 aktiv ist.
 * - Eingaben: Ziel-Banknummer b (unsigned char).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13e3a0(unsigned char b)
{
  if (d_1c1110 == 1 && d_1a9449 != b) {
    SWB1(b)
  }
}

//@ f_13e400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über die VESA-BIOS-Funktion AX = 0x4F05, BH = 1, BL = 0 die aktuell im Grafiktreiber
 *   eingestellte Speicherbank von Fenster A ab und schreibt sie in *p.
 * - Eingaben: Ausgabezeiger p (unsigned short *) für die ermittelte Banknummer.
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehler oder inaktivem VESA-Treiber.
 * - Wichtige Variablen:
 *   - d_1c10b4: Ausgaberegister DX des BIOS-Aufrufs mit der aktuellen Banknummer.
 === Ende Beschreibung === */
char f_13e400(unsigned short *p)
{
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f05;
    d_1c10ad = 1;
    d_1c10ac_l = 0;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    *(volatile unsigned short *)p = d_1c10b4; // erzwingt die Lade-/Speicherreihenfolge ueber p wie im Original
    return !d_1c10a9;
  }
  return 0;
}

//@ f_13e460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt über die VESA-BIOS-Funktion AX = 0x4F07, BH = 0, BL = 0 den linken oberen Startpunkt (x,
 *   y) des sichtbaren Bildschirmausschnitts im Videospeicher (Hardware-Scrolling bzw. Page-Flipping).
 * - Eingaben: Horizontale Pixelkoordinate x (CX) und vertikale Scanline y (DX) des Anzeigestarts (unsigned
 *   short).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehler oder inaktivem VESA-Treiber.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
char f_13e460(unsigned short x, unsigned short y)
{
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f07;
    d_1c10ad = 0;
    d_1c10b0 = x;
    d_1c10b4 = y;
    d_1c10ac_l = 0;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    return !d_1c10a9;
  }
  return 0;
}

//@ f_13e4c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest über die VESA-BIOS-Funktion AX = 0x4F07, BH = 0, BL = 1 die aktuell eingestellten
 *   Startkoordinaten des sichtbaren Bildschirmausschnitts aus und speichert sie in *px und *py.
 * - Eingaben: Ausgabezeiger px und py (unsigned short *) für Spalte und Zeile des Anzeigestarts.
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehler oder inaktivem VESA-Treiber.
 * - Wichtige Variablen:
 *   - r: Erfolgsstatus (1 bei d_1c10a9 == 0, sonst 0).
 === Ende Beschreibung === */
char f_13e4c0(unsigned short *px, unsigned short *py)
{
  char r;
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f07;
    d_1c10ad = 0;
    d_1c10ac_l = 1;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    if (d_1c10a9 == 0) {
      { unsigned short *q1 = &d_1c10b0; *px = *q1; } // haelt die Registerfolge beim Wortkopieren wie im Original
      r = 1;
      { unsigned short *q2 = &d_1c10b4; *py = *q2; } // haelt die Registerfolge beim Wortkopieren wie im Original
    } else {
      r = 0;
    }
    return r;
  }
  return 0;
}

//@ f_13e530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt über die VESA-BIOS-Funktion AX = 0x4F06, BL = 0 die logische Zeilenbreite
 *   (Scanline-Länge in Pixeln) des Videospeichers auf den Wert x ein.
 * - Eingaben: Gewünschte logische Zeilenbreite x (unsigned short).
 * - Rückgabewert: 1 bei Erfolg, 0 bei Fehler oder inaktivem VESA-Treiber.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
char f_13e530(unsigned short x)
{
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f06;
    d_1c10ac_l = 0;
    d_1c10b0 = x;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    return !d_1c10a9;
  }
  return 0;
}

//@ f_13e580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die aktuelle logische Zeilenbreite in Pixeln: Im aktiven VESA-Modus wird sie über AX
 *   = 0x4F06, BL = 1 (CX) vom BIOS abgefragt, im Standard-VGA-Modus direkt aus d_1c1108->s10 gelesen.
 * - Eingaben: Keine.
 * - Rückgabewert: Logische Scanline-Breite (unsigned short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned short f_13e580(void)
{
  if (d_1c1110 == 1 && d_1c114c == 1) {
    d_1c10a8 = 0x4f06;
    d_1c10ac_l = 1;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    return d_1c10ac;
  }
  return d_1c1108->s10;
}

//@ f_13e5d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über die VESA-BIOS-Funktion AX = 0x4F06, BL = 1 die maximale Anzahl der im aktuellen
 *   Modus verfügbaren logischen Scanlines (DX) ab.
 * - Eingaben: Keine.
 * - Rückgabewert: Anzahl der verfügbaren Scanlines (unsigned short) oder 0, falls VESA nicht aktiv ist.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned short f_13e5d0(void)
{
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f06;
    d_1c10ac_l = 1;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    return d_1c10b4;
  }
  return 0;
}

//@ f_13e620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet über die VESA-BIOS-Funktion AX = 0x4F06, BL = 1 die gesamte logische
 *   Bildspeicherfläche in Bytes (BytesProScanline * MaxScanlines, also BX * DX).
 * - Eingaben: Keine.
 * - Rückgabewert: Produkt aus Bytes pro Scanline (d_1c10ac) und Scanline-Anzahl (d_1c10b4), oder 0 bei einem
 *   Fehler.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13e620(void)
{
  if (d_1c1110 == 1) {
    d_1c10a8 = 0x4f06;
    d_1c10ac_l = 1;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
    if (!d_1c10a9) {
      return d_1c10ac * d_1c10b4;
    }
  }
  return 0;
}

//@ f_13e680
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Bank-Granularität des aktuellen Grafikmodus in Bytes, indem der Kilobyte-Wert
 *   d_1c1108->s4 um 10 Bits nach links geschoben (* 1024) wird.
 * - Eingaben: Keine.
 * - Rückgabewert: Bank-Granularität in Bytes (int, typischerweise 65536).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_13e680(void)
{
  return (int)d_1c1108->s4 << 10;
}

//@ f_13e690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen rechteckigen Bildbereich der Größe w x h ohne Transparenz aus dem Quellpuffer p1
 *   (mit Zeilenabstand stride) an die Zielkoordinaten (x, y) (relativ zum Basisoffset p2) im gebankten
 *   Videospeicher. Beschneidet das Rechteck zunächst über f_13d490 am globalen Clipping-Rechteck d_1c1158,
 *   berechnet die Startbank sowie den Offset innerhalb der Bank und kopiert die Zeilen blockweise über memmove
 *   (f_14d075), wobei an 64-KB-Bankgrenzen automatisch auf die nächste Bank weitergeschaltet und eine
 *   gegebenenfalls mitten in der Bankgrenze geteilte Scanline in zwei Teilkopien zerlegt wird.
 * - Eingaben: Quellpufferadresse p1, Ziel-Basisoffset p2 im VRAM, Zielkoordinaten x, y (short), Breite w
 *   (short), Höhe h (int) und Quell-Zeilenabstand stride (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - pitch: Bytes pro Scanline im Videospeicher (m->s10).
 *   - gran: Bank-Granularität in Bytes (f_13e680()).
 *   - bank, off: Startbank (pos / gran) und Byte-Offset innerhalb der Bank (pos % gran).
 *   - n, rest: Anzahl der noch vollständig in die aktuelle Bank passenden Scanlines ((gran - off) / pitch) und
 *     verbleibende Restbytes am Ende der Bank.
 === Ende Beschreibung === */
static inline void bank_690(unsigned char b)
{
 if(d_1c1110==1&&d_1a9449!=b) {
  d_1a9449=b;
  ((BankRegs907 *)&d_1c10a8)->ax=0x4f05;
  ((BankRegs907 *)&d_1c10a8)->bh=0;
  ((BankRegs907 *)&d_1c10a8)->bl=0;
  ((BankRegs907 *)&d_1c10a8)->dx=b;
  f_149cd2(0x10,&d_1c10a8,&d_1c10a8);
 }
}
static inline void rows_690(short w0,short sp0,int d0,short dp0,short h0,int s0)
{
 int d;
 short sp;
 short dp;
 short w;
 short h;
 int s;
 w=w0;
 sp=sp0;
 d=d0;
 dp=dp0;
 h=h0;
 s=s0;

 for(short i=0;i<h;++i) {
  f_14d075(d,s,w);s+=sp;d+=dp;
 }
}
static inline void rows2_690(short w,short h,short sp,short dp,int s,int d)
{
 short i;
 for(i=0;i<h;++i) {
  f_14d075(d,s,w);s+=sp;d+=dp;
    // KRUECKE Platz
 {short u=w;w=u;}
 {short u=sp;sp=u;}
 {short u=h;h=u;}

 }
   // KRUECKE Platz
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}

 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}

 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}

 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}

 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}

 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}

 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
}
static inline void rows3_690(short w0,short h0,short sp0,int s0,int d0,short dp0)
{
 short h;
 int s;
 short w;
 short dp;
 int d;
 short sp;
 w=w0;
 h=h0;
 sp=sp0;
 s=s0;
 d=d0;
 dp=dp0;

 short i;
 for(i=0;i<h;++i) {
  f_14d075(d,s,w);s+=sp;d+=dp;
 {short u=h;h=u;}
 {short u=sp;sp=u;}
 {short u=dp;dp=u;}

 }
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}
 {short d13_v=sp;sp=d13_v;}

 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}
 {int d13_v=d;d=d13_v;}

 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}
 {short d13_v=i;i=d13_v;}

 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}
 {short d13_v=h;h=d13_v;}

 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}
 {int d13_v=s;s=d13_v;}

 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}
 {short d13_v=dp;dp=d13_v;}

 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
 {short d13_v=w;w=d13_v;}
}
void f_13e690(int p1,int p2,short x,short y,short w,int h,short stride)
{
 unsigned pitch;
 unsigned off;
 VM * m;
 unsigned gran;
 int dy;
 unsigned base;
 unsigned pos;
 unsigned dst;
 int xx;
 unsigned prod;
 int hh;
 unsigned bank;
 unsigned short rows;
 short ox;
 short oy;

 ox=x; oy=y;
 if(!f_13d490(&d_1c1158,&x,&y,&w,&h))return;
 { short u=ox; ox=u; }
 dy=(y-oy)*stride; xx=ox; {int u=xx;xx=u;}
 p1+=dy+(x-xx);
 m=d_1c1108;
 pitch=m->s10;

 prod=y*pitch;
 { unsigned u=prod; prod=u; }
 pos=prod+p2+x;
 gran=f_13e680();
 off=pos%gran;
 bank=pos/gran;
 hh=h;
 rows=hh;
 base=m->s8<<4;
 dst=base+off;
 f_13e3a0(bank++);
 while(rows!=0) {
 {unsigned short u=rows;rows=u;}
 {unsigned short u=rows;rows=u;}
 {unsigned short u=rows;rows=u;}
 {unsigned short u=rows;rows=u;}
 {unsigned short u=rows;rows=u;}
 {unsigned u=bank;bank=u;}
 {unsigned u=bank;bank=u;}
 {unsigned u=gran;gran=u;}
 {unsigned u=gran;gran=u;}
 {unsigned u=gran;gran=u;}
 {int u=p1;p1=u;}
 {int u=p1;p1=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=dst;dst=u;}
 {unsigned u=pitch;pitch=u;}
 {unsigned u=pitch;pitch=u;}
 {unsigned u=pitch;pitch=u;}
 {unsigned u=pitch;pitch=u;}
 {unsigned u=pitch;pitch=u;}
 {unsigned u=pitch;pitch=u;}
 {short u=stride;stride=u;}
 {short u=stride;stride=u;}
 {short u=stride;stride=u;}
 {short u=stride;stride=u;}
 {short u=stride;stride=u;}
 {short u=stride;stride=u;}
 {unsigned u=base;base=u;}
 {unsigned u=base;base=u;}
 {unsigned u=base;base=u;}
 {unsigned u=base;base=u;}
 {unsigned u=base;base=u;}
 {unsigned u=base;base=u;}
 {unsigned u=off;off=u;}
 {unsigned u=off;off=u;}
 {unsigned u=off;off=u;}
 {unsigned u=off;off=u;}

  unsigned short n=(gran-off)/pitch;
  {unsigned short u=n;n=u;}
  {unsigned short u=n;n=u;}
  unsigned rest=gran-n*pitch-off;

  if(n>=rows) {
   rows_690(w,stride,dst,pitch,rows,p1);
   return;
  }
  if((unsigned)(int)w<=rest) {
   ++n;
   rows2_690(w,n,stride,pitch,p1,dst);
   p1+=n*stride;
   dst+=n*pitch-gran;
   off=dst-base;
   swb_13e2c0(bank++);
  } else {
   rows3_690(w,n,stride,p1,dst,pitch);
   p1+=n*stride;
   dst+=n*pitch;
   f_14d075(dst,p1,rest);
   p1+=rest;
   dst=base;
   swb_13e2c0(bank++);
   f_14d075(dst,p1,w-rest);
   p1+=stride-rest;
   dst+=(w-rest)+(pitch-w);
   off=dst-base;
   ++n;
  }
  rows-=n;
 }
 (void)(char)gran;
}

//@ f_13eab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen rechteckigen Bildbereich der Größe w x h ab den Koordinaten (x, y) (relativ zum
 *   VRAM-Basisoffset p2) aus dem gebankten Videospeicher in den Zielpuffer p1 (mit Zeilenabstand stride) zurück.
 *   Beschneidet den Bereich über f_13d490 am Clipping-Rechteck d_1c1158, nutzt bei Grafikkarten mit lesbarem
 *   Fenster B ((m->b3 & 3) == 3) dessen Segment m->sa << 4 und Bankumschaltung BL = 1 (sonst Fenster A m->s8 <<
 *   4) und behandelt Bankübergänge mitten in einer Zeile durch zweigeteilte memmove-Aufrufe (f_14d075).
 * - Eingaben: Zielpufferadresse p1 im Hauptspeicher, Quell-Basisoffset p2 im VRAM, Quellkoordinaten x, y
 *   (short), Breite w, Höhe h und Ziel-Zeilenabstand stride (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - base: Lineare Basisadresse des genutzten VESA-Speicherfensters (m->sa << 4 oder m->s8 << 4).
 *   - bank, off: Aktuelle Banknummer und Offset innerhalb des Speicherfensters.
 *   - n, rest: Anzahl vollständiger Zeilen in der aktuellen Bank und verbleibende Bytes vor dem Bankende.
 === Ende Beschreibung === */
struct Rd0848 {
 static void rows(int d,int s,short w,short h,short sp,short dp) {
  for(short i=0;i<h;++i) {
   f_14d075(d,s,w);s+=sp;d+=dp;
  }
 }
 static void rows1(short w,short h,short sp,int d,int s,short dp) {
  for(short i=0;i<h;++i) {
   f_14d075(d,s,w);s+=sp;d+=dp;
  }
 }
 static void rows2(short w,short h,short sp,short dp,int d,int s) {
  for(short i=0;i<h;++i) {
   f_14d075(d,s,w);s+=sp;d+=dp;
  }
 }
 static void rows3(int s,int d,short w,short sp,short dp,short h) {
  sp=(sp&0)?(short)0:sp; dp=(dp&0)?(short)0:dp; // haelt die Registergewichtung von sp und dp vor der Schleife
  for(short i=0;i<h;++i) {
   f_14d075(d,s,w);s+=sp;d+=dp;
  }
 }
 static void bank(unsigned char b) {
  if(d_1c1110==1) {
   if((d_1c1108->b3&3)==3) {
    d_1a9449=-1;
    ((BankRegs907 *)&d_1c10a8)->ax=0x4f05;
    ((BankRegs907 *)&d_1c10a8)->bh=0;
    ((BankRegs907 *)&d_1c10a8)->bl=1;
    ((BankRegs907 *)&d_1c10a8)->dx=b;
    f_149cd2(0x10,&d_1c10a8,&d_1c10a8);
   }else if(d_1c1110==1 && d_1a9449!=b) {
    d_1a9449=b;
    ((BankRegs907 *)&d_1c10a8)->ax=0x4f05;
    ((BankRegs907 *)&d_1c10a8)->bh=0;
    ((BankRegs907 *)&d_1c10a8)->bl=0;
    ((BankRegs907 *)&d_1c10a8)->dx=b;
    f_149cd2(0x10,&d_1c10a8,&d_1c10a8);
   }
  }
 }
};
void f_13eab0(int p1,int p2,short x,short y,short w,short h,short stride)
{
 short oy,ox;
 ox=x; oy=y;
 if(!f_13d490(&d_1c1158,&x,&y,&w,&h))return;
 p1+=(x-ox)+(y-oy)*stride;
 VM *m=d_1c1108;
 unsigned pitch=m->s10;
 unsigned pos=x+(p2+y*pitch);
 unsigned g=(int)m->s4<<10;
 unsigned off=pos%g;
 unsigned bank=pos/g;
 unsigned gran=g;
 // Haelt die Registergewichtung vor der Hauptschleife wie im Original
 w=(w&0)?(short)0:w;
 p1=(p1&0)?0:p1;
 gran=(gran&0)?0:gran;
 w=(w&0)?(short)0:w;
 gran=(gran&0)?0:gran;
 unsigned short rows=h;
 unsigned base;
 if((m->b3&3)==3)base=m->sa<<4;else base=m->s8<<4;
 unsigned dst=base+off;
 Rd0848::bank(bank++);
 while(rows!=0) {
  unsigned short n=(gran-off)/pitch;
  unsigned rest=gran-n*pitch-off;
  if(n>=rows) {
   Rd0848::rows1(w,rows,pitch,p1,dst,stride);
   return;
  }
  if((unsigned)(int)w<=rest) {
   ++n;
   Rd0848::rows2(w,n,pitch,stride,p1,dst);
   p1+=n*stride;
   dst+=n*pitch-gran;
   off=dst-base;
   Rd0848::bank(bank++);
  } else {
   Rd0848::rows3(dst,p1,w,pitch,stride,n);
   p1+=n*stride;
   dst+=n*pitch;
   f_14d075(p1,dst,rest);
   p1+=rest;
   dst=base;
   Rd0848::bank(bank++);
   f_14d075(p1,dst,w-rest);
   p1+=stride-rest;
   dst+=(w-rest)+(pitch-w);
   off=dst-base;
   ++n;
   // Haelt die Registergewichtung im Bank-Ueberlauf-Zweig wie im Original
   p1=(p1&0)?0:p1;
   dst=(dst&0)?0:dst;
   pitch=(pitch&0)?0:pitch;
   n=(n&0)?(unsigned short)0:n;
   dst=(dst&0)?0:dst;
  }
  rows-=n;
  // Haelt die Registergewichtung am Schleifenende wie im Original
  w=(w&0)?(short)0:w;
  w=(w&0)?(short)0:w;
  rest=(rest&0)?0:rest;
  pitch=(pitch&0)?0:pitch;
 }
}


//@ f_13efd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Füllt einen rechteckigen Bereich der Größe p4 x p5 an den Koordinaten (p2, p3) (relativ zum
 *   VRAM-Basisoffset p1) im gebankten Videospeicher einfarbig mit dem Farbwert p6. Beschneidet das Rechteck
 *   zuvor an d_1c1158 und füllt die Zeilen über memset (f_145300) einschließlich sauberer Aufteilung an
 *   Bankgrenzen (enthält jedoch einen Originalfehler von Attic: Bei Karten mit (b3 & 3) == 3 wählt die Funktion
 *   als Zieladresse WinBSegment, schaltet beim Bankwechsel aber stets Fenster A mit BL = 0 um).
 * - Eingaben: VRAM-Basisoffset p1, Zielkoordinaten p2 (x) und p3 (y), Breite p4, Höhe p5 (short) sowie Füllfarbe
 *   p6 (unsigned char).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - base: Lineare Fenster-Basisadresse im Videospeicher.
 *   - dst: Laufende Zieladresse im Videospeicherfenster.
 *   - rows, n, rest: Noch zu füllende Zeilenanzahl, in die aktuelle Bank passende Zeilen und Restbytes an der
 *     Bankgrenze.
 === Ende Beschreibung === */
struct Bank907 {

 static char set(unsigned char bank) {
  if(d_1c1110==1) {
   const signed char &old=d_1a9449;
   int nb=bank; {int q=nb;nb=q;} if(old!=nb) { // haelt nb im Originalregister beim Bank-Vergleich
    d_1a9449=bank;((BankRegs907 *)&d_1c10a8)->ax=0x4f05;((BankRegs907 *)&d_1c10a8)->bh=0;((BankRegs907 *)&d_1c10a8)->bl=0;((BankRegs907 *)&d_1c10a8)->dx=bank;
    f_149cd2(0x10,&d_1c10a8,&d_1c10a8); return !d_1c10a9;
   }
   return 1;
  }
  return 0;
 }
 static char setB(unsigned char bank) {
  if(d_1c1110==1) {
   const signed char &old=d_1a9449;
   if(bank!=old) {
    d_1a9449=bank;((BankRegs907 *)&d_1c10a8)->ax=0x4f05;((BankRegs907 *)&d_1c10a8)->bh=0;((BankRegs907 *)&d_1c10a8)->bl=0;((BankRegs907 *)&d_1c10a8)->dx=bank;
    f_149cd2(0x10,&d_1c10a8,&d_1c10a8); return !d_1c10a9;
   }
   return 1;
  }
  return 0;
 }
 static char setA2(unsigned char bank) {
  if(d_1c1110==1) {
   const signed char &old=d_1a9449;
   if(old != ((bank&0)?(unsigned char)0:bank)) { // haelt bank im selben Register wie im zweiten Inlining-Zweig
    d_1a9449=bank;((BankRegs907 *)&d_1c10a8)->ax=0x4f05;((BankRegs907 *)&d_1c10a8)->bh=0;((BankRegs907 *)&d_1c10a8)->bl=0;((BankRegs907 *)&d_1c10a8)->dx=bank;
    f_149cd2(0x10,&d_1c10a8,&d_1c10a8); return !d_1c10a9;
   }
   return 1;
  }
  return 0;
 }
};
void f_13efd0(int p1, short p2, short p3, short p4, short p5, unsigned char p6)
{
 
    unsigned pitch,gran,rest,bank,pos,off,g;
 int base;
 int yterm;
 int t;
 
 int dst; short hC;(void)&hC; // haelt die Stapel- und Registerfolge der inlined Hilfsvariablen wie im Original

 
 unsigned char b;
    short sg;

 if(!f_13d490(&d_1c1158,&p2,&p3,&p4,&p5))return;
 // Haelt die globale Konflikt- und Registerfolge im Prolog wie im Original
 { unsigned char gv=d_1c1110; d_1c1110=gv; }
{signed char extra0=d_1a9449;d_1a9449=extra0;}{int extra1=d_1c10a8;d_1c10a8=extra1;}{unsigned short extra2=d_1c10b4;d_1c10b4=extra2;}{int extra3=d_1c10ad;d_1c10ad=extra3;}{int extra4=d_1c10ac_l;d_1c10ac_l=extra4;}{unsigned short extra5=d_1c1108->s10;d_1c1108->s10=extra5;} pitch=d_1c1108->s10;
 yterm=(int)p3;
 yterm*=(int)pitch;
 t=p1; p1=t; // haelt p1 im Originalregister
 yterm+=p1;
 g=(unsigned)((int)d_1c1108->s4<<10);
 int g2=(int)g;
 pos=yterm+(int)p2;
 off=pos%(unsigned)g2;
 off=(off&0)?(unsigned)0:off; // haelt die Lebensdauergrenze von off nach der Modulo-Rechnung
 bank=pos/(unsigned)g2;
 gran=(unsigned)g2;
#if FIX_R002   /* R002: f_13efd0 schaltet stets VESA-Fenster A (BL = 0) um, muss daher immer WinASegment (s8) nutzen */
 base=(unsigned)d_1c1108->s8<<4;
#else
 if((unsigned char)(d_1c1108->b3&3)==(unsigned char)3)
  base=(unsigned)d_1c1108->sa<<4;
 else
  base=(unsigned)d_1c1108->s8<<4;
#endif
 { unsigned short rows; short wB; short hB;(void)&rows;(void)&wB;(void)&hB; // haelt die Stapelheimaten wie im Original
 rows=p5;
 dst=base+off;
 b=bank++;
 Bank907::set(b);
 { signed char og=d_1a9449; d_1a9449=og; } // haelt die Konfliktfolge nach Bank907::set
 for(;;) { {unsigned q=pitch;pitch=q;} short hA; unsigned short n; short dpA;(void)&hA;(void)&n;(void)&dpA; // haelt die Stapel- und Registerfolge im Schleifenkopf
  if((unsigned short)rows==0)return;
  n=(gran-off)/pitch;
  rest=gran-(unsigned short)n*pitch-off;
  if((unsigned short)n>=(unsigned short)rows) {
   { unsigned d=dst; short w=p4; dpA=pitch; unsigned char c=p6; hA=rows;
 c=(c&0)?(unsigned char)0:c; d=(d&0)?(unsigned)0:d; // haelt die Registerfolge im letzten Zeilenblock
 short i; for(i=0;i<hA;i++) {f_145300(d,c,w);d+=dpA;}}

   return;
  }
  if((unsigned)(int)p4<=rest) {
   short a2dp; wB=p4; hB=++n; a2dp=pitch;  unsigned a2d=dst; unsigned char a2c=p6; short a2i=0;
   while(a2i<hB) { f_145300(a2d,a2c,wB); a2d+=a2dp; ++a2i; }
   dst+=(unsigned short)n*pitch-gran;
   off=(unsigned)dst-base;
   b=bank++;
   Bank907::set(b);
  } else {
 dst=(dst&0)?0:dst; // haelt dst im Originalregister im Ueberlaufzweig
   { unsigned char gv3=d_1c1110; d_1c1110=gv3; } // haelt die Konfliktfolge im Ueberlaufzweig
   { short dpC;(void)&dpC; unsigned d=dst; hC=n; dpC=pitch; short w=p4; unsigned char c=p6; // haelt dpC auf dem Stapel
 short i; for(i=0;i<hC;i++) {f_145300(d,c,w);d+=dpC;}}

   f_145300(dst+(unsigned short)n*pitch,p6,rest);
   dst=base;
   b=bank++;
   Bank907::setA2(b);
   f_145300(dst,p6,p4-rest);
   { int w=(int)p4; int a=w-(int)rest; int c=(int)pitch-w; dst+=c+a; }
   off=(unsigned)dst-base;
   ++n;
p4=(p4&0)?(short)0:p4; // haelt die Registergewichtung von p4 am Zweigende

  }
  rows-=n;
// Haelt die Registergewichtung am Schleifenende wie im Original
dst=(dst&0)?(int)0:dst;
rest=(rest&0)?(unsigned)0:rest;
rows=(rows&0)?(unsigned short)0:rows;

 }
}
}



//@ f_13f360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen rechteckigen Bildbereich der Größe p5 x p6 aus dem Quellpuffer p1 (Zeilenabstand
 *   p7) mit Transparenzmaskierung an die Position (p3, p4) (relativ zum VRAM-Basisoffset p2) im gebankten
 *   Videospeicher, wobei alle Pixel mit der Transparenzfarbe p8 ausgelassen werden. Beschneidet das Rechteck
 *   über f_13d490 an d_1c1158 und verarbeitet sowohl ganze Zeilenblöcke innerhalb einer Bank als auch an einer
 *   64-KB-Bankgrenze geteilte Zeilen.
 * - Eingaben: Quellpufferadresse p1, VRAM-Basisoffset p2, Zielkoordinaten p3 (x) und p4 (y), Breite p5, Höhe p6,
 *   Quell-Pitch p7 (short) und transparente Farbe p8 (char).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - ox, oy: Ursprüngliche unbeschnittene Zielkoordinaten zur Korrektur des Quellzeigers p1 nach dem Clipping.
 *   - bank, off, gran: Aktuelle VESA-Bank, Offset innerhalb des Fensters (m->s8 << 4) und Bank-Granularität.
 *   - n, rest: Anzahl ganzer Zeilen bis zum Bankende und Restbytes in der angeschnittenen Zeile.
 === Ende Beschreibung === */
extern "C" int bankcall30_A20T(int,void *,void *);
#pragma aux bankcall30_A20T "f_149cd2" parm [eax] [ebx] [edx] value [eax] modify exact [eax ebx ecx edx];


struct Blit360 {
 static void line1(char *p1, char *p2, unsigned n, char key) {
  if (n > 0) {
   char *src;
   char *dst;
   char *e;
   dst=p2;e=dst+n;src=p1;
   do {
    char px=*src;*src=px; if (key != px) *dst=px;
    dst++;
    src++;
   } while (dst < e);
  }
 }
 static void line2(char *p1, char *p2, unsigned n, char key) {
  if (n > 0) {
   char *e;
   char *dst;
   char *src;
   src=p1;dst=p2;e=dst+n;
   do {
    if (key != *src) *dst = *src;
    dst++;
    src++;
   } while (dst < e);
  }
 }
 static void rows1(char *p1, char *p2, short p4, short p3, short p5, short p6, char key) {
  short i;
  char *dst;
  char *src;
  int n;
  dst=p2; src=p1; i=0;
  if (i < p4) goto again;
  return;
 again:
  n = p3;
  if ((unsigned)n > 0) goto copy;
 step:
  src += p5;
  dst += p6;
  i++;
  if (i >= p4) return;
  goto again;
 copy:
  {
   char k = key;
   char *d;
   char *s = src;
   d = dst;
   char *e = dst + n;
   do {
    if (k != *s) *d = *s;
    d++;
    s++;
   } while (d < e);
  }
  goto step;
 }
 static void rows2(char *p1, char *p2, short p3, short p5, short p4, short p6, char key) {
  int n;
  char *dst;
  char *src;
  short i;
  dst=p2; src=p1; i=0;
  if (i < p4) goto again;
  return;
 again:
  n = p3;
  if ((unsigned)n > 0) goto copy;
 step:
  src += p5;
  dst += p6;
  i++;
  if (i >= p4) return;
  goto again;
 copy:
  {
   char k = key;
   char *d;
   char *s = src;
   d = dst;
   char *e = dst + n;
   do {
    if (k != *s) *d = *s;
    d++;
    s++;
   } while (d < e);
  }
  goto step;
 }
 static void rows3(char *p1, char *p2, short p3, short p4, short p5, short p6, char key) {
  int n;
  char *src;
  char *dst;
  int t;
  short i;
  dst=p2; src=p1; i=0;
  if (i < p4) goto again;
  return;
 again:
  t=p3; n=t;
  if ((unsigned)t > 0) goto copy;
 step:
  src += p5;
  dst += p6;
  i++;
  if (i >= p4) return;
  goto again;
 copy:
  t=0;
  {
   char *e;
   char k;
   char *d;
   char *s;
   k=key;s=src;d=dst;e=dst+n;
   do {
    char px=*s;*s=px; if (k != px) *d=px;
    d++;
    s++;
   } while (d < e);
  }
  goto step;
 }
 static void bank1(unsigned char b) {
  if (d_1c1110 == 1) {
   const signed char &old = d_1a9449;
   int bb=b; {int u=bb;bb=u;} // haelt bb beim Bank-Vergleich im Originalregister
   if (old != bb) {
    d_1a9449 = b;
    ((BankRegs907 *)&d_1c10a8)->ax = 0x4f05;
    ((BankRegs907 *)&d_1c10a8)->bh = 0;
    ((BankRegs907 *)&d_1c10a8)->bl = 0;
    ((BankRegs907 *)&d_1c10a8)->dx = b;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
   }
  }
 }
 static void bank2(unsigned char b) {
  if (d_1c1110 == 1) {
   const signed char &old = d_1a9449;
   int bb=b; {int u=bb;bb=u;} // haelt bb beim Bank-Vergleich im Originalregister
   if (old != bb) {
    d_1a9449 = b;
    ((BankRegs907 *)&d_1c10a8)->ax = 0x4f05;
    ((BankRegs907 *)&d_1c10a8)->bh = 0;
    ((BankRegs907 *)&d_1c10a8)->bl = 0;
    ((BankRegs907 *)&d_1c10a8)->dx = b;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
   }
  }
 }
 static void bank3(unsigned char b) {
  if (d_1c1110 == 1) {
   const signed char &old = d_1a9449;
   unsigned char bb = b;
   { unsigned char u = bb; bb = u; } // haelt bb beim Bank-Vergleich im Originalregister
   if (old != bb) {
    d_1a9449 = b;
    ((BankRegs907 *)&d_1c10a8)->ax = 0x4f05;
    ((BankRegs907 *)&d_1c10a8)->bh = 0;
    ((BankRegs907 *)&d_1c10a8)->dx = b;
    ((BankRegs907 *)&d_1c10a8)->bl = 0;
    f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
   }
  }
 }
};
void f_13f360(int p1, int p2, short p3, short p4, short p5, short p6, short p7, char p8)
{
// Haelt die Register- und Stapelfolge wie im Original: unbenutzte volatile Sortierknoten; nativ ohne eigenen Stapelplatz oder Befehle.
struct GWB_A20T_3 {char pad[3];};
struct GWB_A20T_5 {char pad[5];};
struct GWB_A20T_6 {char pad[6];};
struct GWB_A20T_7 {char pad[7];};
struct GWB_A20T_9 {char pad[9];};
struct GWB_A20T_10 {char pad[10];};
struct GWB_A20T_11 {char pad[11];};
struct GWB_A20T_12 {char pad[12];};
struct GWB_A20T_13 {char pad[13];};
struct GWB_A20T_14 {char pad[14];};
struct GWB_A20T_15 {char pad[15];};
struct GWB_A20T_16 {char pad[16];};
struct GWB_A20T_17 {char pad[17];};
struct GWB_A20T_18 {char pad[18];};
struct GWB_A20T_19 {char pad[19];};
struct GWB_A20T_20 {char pad[20];};
struct GWB_A20T_21 {char pad[21];};
struct GWB_A20T_22 {char pad[22];};
struct GWB_A20T_23 {char pad[23];};
struct GWB_A20T_24 {char pad[24];};
struct GWB_A20T_25 {char pad[25];};
struct GWB_A20T_26 {char pad[26];};
struct GWB_A20T_27 {char pad[27];};
struct GWB_A20T_28 {char pad[28];};
struct GWB_A20T_29 {char pad[29];};
struct GWB_A20T_30 {char pad[30];};
struct GWB_A20T_31 {char pad[31];};
struct GWB_A20T_32 {char pad[32];};
struct GWB_A20T_40 {char pad[40];};
struct GWB_A20T_48 {char pad[48];};
struct GWB_A20T_56 {char pad[56];};
struct GWB_A20T_64 {char pad[64];};
struct GWB_A20T_72 {char pad[72];};
struct GWB_A20T_80 {char pad[80];};
struct GWB_A20T_88 {char pad[88];};
struct GWB_A20T_96 {char pad[96];};
struct GWB_A20T_104 {char pad[104];};
struct GWB_A20T_112 {char pad[112];};
struct GWB_A20T_120 {char pad[120];};
struct GWB_A20T_128 {char pad[128];};
struct GWB_A20T_136 {char pad[136];};
struct GWB_A20T_144 {char pad[144];};
struct GWB_A20T_152 {char pad[152];};
struct GWB_A20T_160 {char pad[160];};
struct GWB_A20T_168 {char pad[168];};
struct GWB_A20T_176 {char pad[176];};
struct GWB_A20T_184 {char pad[184];};
struct GWB_A20T_192 {char pad[192];};
struct GWB_A20T_200 {char pad[200];};
struct GWB_A20T_208 {char pad[208];};
struct GWB_A20T_216 {char pad[216];};
struct GWB_A20T_224 {char pad[224];};
struct GWB_A20T_232 {char pad[232];};
struct GWB_A20T_240 {char pad[240];};
struct GWB_A20T_248 {char pad[248];};
struct GWB_A20T_256 {char pad[256];};
struct GWB_A20T_264 {char pad[264];};
struct GWB_A20T_272 {char pad[272];};
struct GWB_A20T_280 {char pad[280];};
struct GWB_A20T_288 {char pad[288];};
struct GWB_A20T_512 {char pad[512];};
struct GWB_A20T_1024 {char pad[1024];};
struct GWB_A20T_1536 {char pad[1536];};
struct GWB_A20T_1952 {char pad[1952];};
struct GWB_A20T_2048 {char pad[2048];};

struct GCT_A20T_3 {char pad[3];};
struct GCT_A20T_5 {char pad[5];};
struct GCT_A20T_6 {char pad[6];};
struct GCT_A20T_7 {char pad[7];};
struct GCT_A20T_9 {char pad[9];};
struct GCT_A20T_10 {char pad[10];};
struct GCT_A20T_11 {char pad[11];};
struct GCT_A20T_12 {char pad[12];};
struct GCT_A20T_13 {char pad[13];};
struct GCT_A20T_14 {char pad[14];};
struct GCT_A20T_15 {char pad[15];};
struct GCT_A20T_16 {char pad[16];};
struct GCT_A20T_17 {char pad[17];};
struct GCT_A20T_18 {char pad[18];};
struct GCT_A20T_19 {char pad[19];};
struct GCT_A20T_20 {char pad[20];};
struct GCT_A20T_21 {char pad[21];};
struct GCT_A20T_22 {char pad[22];};
struct GCT_A20T_23 {char pad[23];};
struct GCT_A20T_24 {char pad[24];};
struct GCT_A20T_25 {char pad[25];};
struct GCT_A20T_26 {char pad[26];};
struct GCT_A20T_27 {char pad[27];};
struct GCT_A20T_28 {char pad[28];};
struct GCT_A20T_29 {char pad[29];};
struct GCT_A20T_30 {char pad[30];};
struct GCT_A20T_31 {char pad[31];};
struct GCT_A20T_32 {char pad[32];};
struct GCT_A20T_40 {char pad[40];};
struct GCT_A20T_48 {char pad[48];};
struct GCT_A20T_56 {char pad[56];};
struct GCT_A20T_64 {char pad[64];};
struct GCT_A20T_72 {char pad[72];};
struct GCT_A20T_80 {char pad[80];};
struct GCT_A20T_88 {char pad[88];};
struct GCT_A20T_96 {char pad[96];};
struct GCT_A20T_104 {char pad[104];};
struct GCT_A20T_112 {char pad[112];};
struct GCT_A20T_120 {char pad[120];};
struct GCT_A20T_128 {char pad[128];};
struct GCT_A20T_136 {char pad[136];};
struct GCT_A20T_144 {char pad[144];};
struct GCT_A20T_152 {char pad[152];};
struct GCT_A20T_160 {char pad[160];};
struct GCT_A20T_168 {char pad[168];};
struct GCT_A20T_176 {char pad[176];};
struct GCT_A20T_184 {char pad[184];};
struct GCT_A20T_192 {char pad[192];};
struct GCT_A20T_200 {char pad[200];};
struct GCT_A20T_208 {char pad[208];};
struct GCT_A20T_216 {char pad[216];};
struct GCT_A20T_224 {char pad[224];};
struct GCT_A20T_232 {char pad[232];};
struct GCT_A20T_240 {char pad[240];};
struct GCT_A20T_248 {char pad[248];};
struct GCT_A20T_256 {char pad[256];};
struct GCT_A20T_264 {char pad[264];};
struct GCT_A20T_272 {char pad[272];};
struct GCT_A20T_280 {char pad[280];};
struct GCT_A20T_288 {char pad[288];};
struct GCT_A20T_512 {char pad[512];};
struct GCT_A20T_1024 {char pad[1024];};
struct GCT_A20T_1536 {char pad[1536];};
struct GCT_A20T_1952 {char pad[1952];};
struct GCT_A20T_2048 {char pad[2048];};

 volatile char c1ghost_A20T_0;
volatile short c1ghost_A20T_1;
volatile GCT_A20T_9 c1ghost_A20T_2;
volatile GCT_A20T_11 c1ghost_A20T_3;
volatile GCT_A20T_5 c1ghost_A20T_4;
volatile GCT_A20T_96 c1ghost_A20T_5;
volatile GCT_A20T_5 c1ghost_A20T_6;
volatile GCT_A20T_16 c1ghost_A20T_7;
volatile GCT_A20T_3 c1ghost_A20T_8;
volatile GCT_A20T_25 c1ghost_A20T_9;
volatile GCT_A20T_23 c1ghost_A20T_10;
volatile GCT_A20T_21 c1ghost_A20T_11;
volatile short c1ghost_A20T_12;
volatile GCT_A20T_32 c1ghost_A20T_13;
volatile short c1ghost_A20T_14;
volatile char c1ghost_A20T_15;
volatile GCT_A20T_5 c1ghost_A20T_16;
volatile GCT_A20T_10 c1ghost_A20T_17;
volatile GCT_A20T_5 c1ghost_A20T_18;
volatile GCT_A20T_26 c1ghost_A20T_19;
volatile GCT_A20T_25 c1ghost_A20T_20;
volatile double c1ghost_A20T_21;
volatile char c1ghost_A20T_22;
volatile GCT_A20T_3 c1ghost_A20T_23;
volatile char c1ghost_A20T_24;
volatile GCT_A20T_31 c1ghost_A20T_25;
volatile GCT_A20T_12 c1ghost_A20T_26;
volatile GCT_A20T_29 c1ghost_A20T_27;
volatile GCT_A20T_16 c1ghost_A20T_28;
volatile GCT_A20T_23 c1ghost_A20T_29;
volatile GCT_A20T_64 c1ghost_A20T_30;
volatile char c1ghost_A20T_31;
volatile char c1ghost_A20T_32;
volatile GCT_A20T_19 c1ghost_A20T_33;
volatile GCT_A20T_21 c1ghost_A20T_34;
volatile int c1ghost_A20T_35;
volatile GCT_A20T_12 c1ghost_A20T_36;
volatile char c1ghost_A20T_37;
volatile char c1ghost_A20T_38;
volatile char c1ghost_A20T_39;
volatile int c1ghost_A20T_40;
volatile int c1ghost_A20T_41;
volatile double c1ghost_A20T_42;
volatile char c1ghost_A20T_43;
volatile GCT_A20T_6 c1ghost_A20T_44;
volatile int c1ghost_A20T_45;
volatile GCT_A20T_3 c1ghost_A20T_46;
volatile GCT_A20T_96 c1ghost_A20T_47;
volatile GCT_A20T_15 c1ghost_A20T_48;
volatile GCT_A20T_6 c1ghost_A20T_49;
volatile int c1ghost_A20T_50;
volatile GCT_A20T_23 c1ghost_A20T_51;
volatile GCT_A20T_16 c1ghost_A20T_52;
volatile short c1ghost_A20T_53;
volatile char c1ghost_A20T_54;
volatile char c1ghost_A20T_55;
volatile GCT_A20T_27 c1ghost_A20T_56;
volatile int c1ghost_A20T_57;
volatile GCT_A20T_21 c1ghost_A20T_58;
volatile int c1ghost_A20T_59;
volatile char c1ghost_A20T_60;
volatile short c1ghost_A20T_61;
volatile GCT_A20T_11 c1ghost_A20T_62;
volatile short c1ghost_A20T_63;
volatile short c1ghost_A20T_64;
volatile short c1ghost_A20T_65;
volatile GCT_A20T_27 c1ghost_A20T_66;
volatile short c1ghost_A20T_67;
volatile GCT_A20T_7 c1ghost_A20T_68;
volatile char c1ghost_A20T_69;
volatile GCT_A20T_3 c1ghost_A20T_70;
volatile GCT_A20T_3 c1ghost_A20T_71;
volatile GCT_A20T_16 c1ghost_A20T_72;
volatile GCT_A20T_24 c1ghost_A20T_73;
volatile GCT_A20T_80 c1ghost_A20T_74;
volatile GCT_A20T_13 c1ghost_A20T_75;
volatile GCT_A20T_23 c1ghost_A20T_76;
volatile GCT_A20T_13 c1ghost_A20T_77;
volatile char c1ghost_A20T_78;
volatile GCT_A20T_24 c1ghost_A20T_79;
volatile GCT_A20T_12 c1ghost_A20T_80;
volatile GCT_A20T_21 c1ghost_A20T_81;
volatile int c1ghost_A20T_82;
volatile GCT_A20T_21 c1ghost_A20T_83;
volatile double c1ghost_A20T_84;
volatile GCT_A20T_3 c1ghost_A20T_85;
volatile char c1ghost_A20T_86;
volatile GCT_A20T_23 c1ghost_A20T_87;
volatile GCT_A20T_17 c1ghost_A20T_88;
volatile short c1ghost_A20T_89;
volatile GCT_A20T_23 c1ghost_A20T_90;
volatile short c1ghost_A20T_91;
volatile GCT_A20T_12 c1ghost_A20T_92;
volatile GCT_A20T_7 c1ghost_A20T_93;
volatile GCT_A20T_32 c1ghost_A20T_94;
volatile GCT_A20T_144 c1ghost_A20T_95;
volatile GCT_A20T_9 c1ghost_A20T_96;
volatile GCT_A20T_25 c1ghost_A20T_97;
volatile GCT_A20T_64 c1ghost_A20T_98;
volatile int c1ghost_A20T_99;
 int cy;
volatile double c1ghost_A20T_100;
volatile GCT_A20T_64 c1ghost_A20T_101;
volatile GCT_A20T_20 c1ghost_A20T_102;
volatile GCT_A20T_6 c1ghost_A20T_103;
volatile short c1ghost_A20T_104;
volatile GCT_A20T_5 c1ghost_A20T_105;
volatile char c1ghost_A20T_106;
volatile GCT_A20T_11 c1ghost_A20T_107;
volatile GCT_A20T_27 c1ghost_A20T_108;
volatile GCT_A20T_11 c1ghost_A20T_109;
volatile char c1ghost_A20T_110;
volatile GCT_A20T_5 c1ghost_A20T_111;
volatile GCT_A20T_21 c1ghost_A20T_112;
volatile GCT_A20T_96 c1ghost_A20T_113;
volatile char c1ghost_A20T_114;
volatile char c1ghost_A20T_115;
volatile GCT_A20T_64 c1ghost_A20T_116;
volatile GCT_A20T_128 c1ghost_A20T_117;
volatile GCT_A20T_23 c1ghost_A20T_118;
volatile GCT_A20T_6 c1ghost_A20T_119;
volatile GCT_A20T_23 c1ghost_A20T_120;
volatile GCT_A20T_21 c1ghost_A20T_121;
volatile GCT_A20T_48 c1ghost_A20T_122;
volatile char c1ghost_A20T_123;
volatile short c1ghost_A20T_124;
volatile int c1ghost_A20T_125;
volatile char c1ghost_A20T_126;
volatile GCT_A20T_15 c1ghost_A20T_127;
volatile GCT_A20T_12 c1ghost_A20T_128;
volatile char c1ghost_A20T_129;
volatile GCT_A20T_64 c1ghost_A20T_130;
volatile double c1ghost_A20T_131;
volatile GCT_A20T_20 c1ghost_A20T_132;
volatile GCT_A20T_12 c1ghost_A20T_133;
volatile GCT_A20T_168 c1ghost_A20T_134;
volatile GCT_A20T_104 c1ghost_A20T_135;
volatile GCT_A20T_23 c1ghost_A20T_136;
volatile GCT_A20T_20 c1ghost_A20T_137;
volatile GCT_A20T_16 c1ghost_A20T_138;
volatile GCT_A20T_23 c1ghost_A20T_139;
volatile GCT_A20T_20 c1ghost_A20T_140;
volatile GCT_A20T_32 c1ghost_A20T_141;
volatile GCT_A20T_23 c1ghost_A20T_142;
volatile char c1ghost_A20T_143;
volatile GCT_A20T_21 c1ghost_A20T_144;
volatile short c1ghost_A20T_145;
volatile GCT_A20T_128 c1ghost_A20T_146;
volatile GCT_A20T_23 c1ghost_A20T_147;
volatile GCT_A20T_152 c1ghost_A20T_148;
volatile GCT_A20T_3 c1ghost_A20T_149;
volatile GCT_A20T_6 c1ghost_A20T_150;
volatile double c1ghost_A20T_151;
volatile GCT_A20T_7 c1ghost_A20T_152;
volatile GCT_A20T_3 c1ghost_A20T_153;
volatile char c1ghost_A20T_154;
volatile GCT_A20T_5 c1ghost_A20T_155;
volatile GCT_A20T_12 c1ghost_A20T_156;
volatile GCT_A20T_25 c1ghost_A20T_157;
volatile GCT_A20T_12 c1ghost_A20T_158;
volatile char c1ghost_A20T_159;
volatile GCT_A20T_6 c1ghost_A20T_160;
volatile char c1ghost_A20T_161;
volatile char c1ghost_A20T_162;
volatile GCT_A20T_152 c1ghost_A20T_163;
volatile GCT_A20T_24 c1ghost_A20T_164;
volatile double c1ghost_A20T_165;
volatile GCT_A20T_7 c1ghost_A20T_166;
volatile GCT_A20T_25 c1ghost_A20T_167;
volatile char c1ghost_A20T_168;
volatile GCT_A20T_112 c1ghost_A20T_169;
volatile GCT_A20T_5 c1ghost_A20T_170;
volatile GCT_A20T_3 c1ghost_A20T_171;
volatile GCT_A20T_12 c1ghost_A20T_172;
volatile GCT_A20T_10 c1ghost_A20T_173;
volatile GCT_A20T_10 c1ghost_A20T_174;
volatile GCT_A20T_7 c1ghost_A20T_175;
volatile int c1ghost_A20T_176;
volatile int c1ghost_A20T_177;
volatile char c1ghost_A20T_178;
volatile char c1ghost_A20T_179;
volatile GCT_A20T_16 c1ghost_A20T_180;
volatile GCT_A20T_24 c1ghost_A20T_181;
volatile GCT_A20T_29 c1ghost_A20T_182;
volatile short c1ghost_A20T_183;
volatile char c1ghost_A20T_184;
volatile GCT_A20T_24 c1ghost_A20T_185;
volatile GCT_A20T_3 c1ghost_A20T_186;
volatile int c1ghost_A20T_187;
volatile GCT_A20T_21 c1ghost_A20T_188;
volatile GCT_A20T_160 c1ghost_A20T_189;
volatile GCT_A20T_11 c1ghost_A20T_190;
volatile GCT_A20T_19 c1ghost_A20T_191;
volatile GCT_A20T_30 c1ghost_A20T_192;
volatile GCT_A20T_72 c1ghost_A20T_193;
volatile GCT_A20T_56 c1ghost_A20T_194;
volatile GCT_A20T_3 c1ghost_A20T_195;
volatile GCT_A20T_21 c1ghost_A20T_196;
volatile GCT_A20T_6 c1ghost_A20T_197;
volatile GCT_A20T_136 c1ghost_A20T_198;
volatile short c1ghost_A20T_199;
volatile double c1ghost_A20T_200;
volatile double c1ghost_A20T_201;
volatile GCT_A20T_20 c1ghost_A20T_202;
volatile GCT_A20T_25 c1ghost_A20T_203;
volatile char c1ghost_A20T_204;
volatile GCT_A20T_144 c1ghost_A20T_205;
volatile GCT_A20T_25 c1ghost_A20T_206;
volatile GCT_A20T_7 c1ghost_A20T_207;
volatile GCT_A20T_3 c1ghost_A20T_208;
volatile GCT_A20T_27 c1ghost_A20T_209;
volatile GCT_A20T_5 c1ghost_A20T_210;
volatile GCT_A20T_160 c1ghost_A20T_211;
volatile GCT_A20T_25 c1ghost_A20T_212;
volatile short c1ghost_A20T_213;
volatile GCT_A20T_23 c1ghost_A20T_214;
volatile GCT_A20T_160 c1ghost_A20T_215;
volatile int c1ghost_A20T_216;
volatile short c1ghost_A20T_217;
volatile GCT_A20T_64 c1ghost_A20T_218;
volatile GCT_A20T_12 c1ghost_A20T_219;
volatile GCT_A20T_6 c1ghost_A20T_220;
volatile GCT_A20T_25 c1ghost_A20T_221;
volatile char c1ghost_A20T_222;
volatile GCT_A20T_6 c1ghost_A20T_223;
volatile GCT_A20T_24 c1ghost_A20T_224;
volatile char c1ghost_A20T_225;
volatile short c1ghost_A20T_226;
volatile double c1ghost_A20T_227;
volatile GCT_A20T_17 c1ghost_A20T_228;
volatile short c1ghost_A20T_229;
volatile short c1ghost_A20T_230;
volatile GCT_A20T_25 c1ghost_A20T_231;
volatile GCT_A20T_7 c1ghost_A20T_232;
volatile char c1ghost_A20T_233;
volatile char c1ghost_A20T_234;
volatile GCT_A20T_6 c1ghost_A20T_235;
volatile GCT_A20T_3 c1ghost_A20T_236;
volatile GCT_A20T_20 c1ghost_A20T_237;
volatile char c1ghost_A20T_238;
volatile GCT_A20T_112 c1ghost_A20T_239;
volatile char c1ghost_A20T_240;
volatile GCT_A20T_56 c1ghost_A20T_241;
volatile GCT_A20T_23 c1ghost_A20T_242;
volatile GCT_A20T_24 c1ghost_A20T_243;
volatile GCT_A20T_11 c1ghost_A20T_244;
volatile char c1ghost_A20T_245;
volatile GCT_A20T_24 c1ghost_A20T_246;
volatile GCT_A20T_12 c1ghost_A20T_247;
volatile GCT_A20T_16 c1ghost_A20T_248;
volatile char c1ghost_A20T_249;
volatile int c1ghost_A20T_250;
volatile GCT_A20T_24 c1ghost_A20T_251;
volatile GCT_A20T_17 c1ghost_A20T_252;
volatile GCT_A20T_7 c1ghost_A20T_253;
volatile GCT_A20T_12 c1ghost_A20T_254;
volatile GCT_A20T_21 c1ghost_A20T_255;
volatile char c1ghost_A20T_256;
volatile short c1ghost_A20T_257;
volatile short c1ghost_A20T_258;
volatile GCT_A20T_21 c1ghost_A20T_259;
volatile GCT_A20T_31 c1ghost_A20T_260;
volatile char c1ghost_A20T_261;
volatile GCT_A20T_7 c1ghost_A20T_262;
volatile int c1ghost_A20T_263;
volatile GCT_A20T_13 c1ghost_A20T_264;
volatile GCT_A20T_27 c1ghost_A20T_265;
volatile GCT_A20T_3 c1ghost_A20T_266;
volatile double c1ghost_A20T_267;
volatile int c1ghost_A20T_268;
volatile GCT_A20T_15 c1ghost_A20T_269;
volatile GCT_A20T_22 c1ghost_A20T_270;
volatile GCT_A20T_23 c1ghost_A20T_271;
volatile GCT_A20T_6 c1ghost_A20T_272;
volatile short c1ghost_A20T_273;
volatile GCT_A20T_20 c1ghost_A20T_274;
volatile short c1ghost_A20T_275;
volatile GCT_A20T_40 c1ghost_A20T_276;
volatile GCT_A20T_120 c1ghost_A20T_277;
volatile GCT_A20T_21 c1ghost_A20T_278;
volatile short c1ghost_A20T_279;
volatile short c1ghost_A20T_280;
volatile GCT_A20T_3 c1ghost_A20T_281;
volatile GCT_A20T_64 c1ghost_A20T_282;
volatile GCT_A20T_72 c1ghost_A20T_283;
volatile short c1ghost_A20T_284;
volatile GCT_A20T_25 c1ghost_A20T_285;
volatile GCT_A20T_15 c1ghost_A20T_286;
volatile GCT_A20T_3 c1ghost_A20T_287;
volatile GCT_A20T_6 c1ghost_A20T_288;
volatile GCT_A20T_17 c1ghost_A20T_289;
volatile GCT_A20T_14 c1ghost_A20T_290;
volatile GCT_A20T_21 c1ghost_A20T_291;
volatile GCT_A20T_14 c1ghost_A20T_292;
volatile GCT_A20T_16 c1ghost_A20T_293;
volatile GCT_A20T_64 c1ghost_A20T_294;
volatile GCT_A20T_5 c1ghost_A20T_295;
volatile char c1ghost_A20T_296;
volatile double c1ghost_A20T_297;
volatile GCT_A20T_12 c1ghost_A20T_298;
volatile GCT_A20T_152 c1ghost_A20T_299;
volatile GCT_A20T_7 c1ghost_A20T_300;
volatile GCT_A20T_24 c1ghost_A20T_301;
volatile GCT_A20T_64 c1ghost_A20T_302;
volatile int c1ghost_A20T_303;
volatile GCT_A20T_23 c1ghost_A20T_304;
volatile int c1ghost_A20T_305;
volatile GCT_A20T_18 c1ghost_A20T_306;
volatile GCT_A20T_5 c1ghost_A20T_307;
volatile char c1ghost_A20T_308;
volatile GCT_A20T_21 c1ghost_A20T_309;
volatile GCT_A20T_40 c1ghost_A20T_310;
volatile double c1ghost_A20T_311;
volatile short c1ghost_A20T_312;
volatile char c1ghost_A20T_313;
volatile GCT_A20T_19 c1ghost_A20T_314;
volatile short c1ghost_A20T_315;
volatile GCT_A20T_21 c1ghost_A20T_316;
volatile int c1ghost_A20T_317;
volatile short c1ghost_A20T_318;
volatile short c1ghost_A20T_319;
volatile short c1ghost_A20T_320;
volatile GCT_A20T_25 c1ghost_A20T_321;
volatile GCT_A20T_12 c1ghost_A20T_322;
volatile char c1ghost_A20T_323;
volatile GCT_A20T_28 c1ghost_A20T_324;
volatile double c1ghost_A20T_325;
volatile GCT_A20T_23 c1ghost_A20T_326;
volatile GCT_A20T_104 c1ghost_A20T_327;
volatile GCT_A20T_23 c1ghost_A20T_328;
volatile GCT_A20T_3 c1ghost_A20T_329;
volatile GCT_A20T_136 c1ghost_A20T_330;
volatile char c1ghost_A20T_331;
volatile int c1ghost_A20T_332;
volatile GCT_A20T_16 c1ghost_A20T_333;
volatile double c1ghost_A20T_334;
volatile GCT_A20T_10 c1ghost_A20T_335;
volatile GCT_A20T_21 c1ghost_A20T_336;
volatile short c1ghost_A20T_337;
volatile short c1ghost_A20T_338;
volatile GCT_A20T_14 c1ghost_A20T_339;
volatile char c1ghost_A20T_340;
volatile GCT_A20T_5 c1ghost_A20T_341;
volatile double c1ghost_A20T_342;
volatile GCT_A20T_5 c1ghost_A20T_343;
volatile GCT_A20T_72 c1ghost_A20T_344;
volatile short c1ghost_A20T_345;
volatile GCT_A20T_12 c1ghost_A20T_346;
volatile char c1ghost_A20T_347;
volatile GCT_A20T_152 c1ghost_A20T_348;
volatile GCT_A20T_3 c1ghost_A20T_349;
volatile GCT_A20T_20 c1ghost_A20T_350;
volatile short c1ghost_A20T_351;
volatile short c1ghost_A20T_352;
volatile GCT_A20T_120 c1ghost_A20T_353;
volatile GCT_A20T_3 c1ghost_A20T_354;
volatile GCT_A20T_12 c1ghost_A20T_355;
volatile GCT_A20T_6 c1ghost_A20T_356;
volatile GCT_A20T_56 c1ghost_A20T_357;
volatile double c1ghost_A20T_358;
volatile GCT_A20T_5 c1ghost_A20T_359;
volatile GCT_A20T_6 c1ghost_A20T_360;
volatile GCT_A20T_21 c1ghost_A20T_361;
volatile GCT_A20T_5 c1ghost_A20T_362;
volatile short c1ghost_A20T_363;
volatile double c1ghost_A20T_364;
volatile GCT_A20T_6 c1ghost_A20T_365;
volatile GCT_A20T_13 c1ghost_A20T_366;
volatile GCT_A20T_21 c1ghost_A20T_367;
volatile int c1ghost_A20T_368;
volatile char c1ghost_A20T_369;
volatile char c1ghost_A20T_370;
volatile short c1ghost_A20T_371;
volatile GCT_A20T_64 c1ghost_A20T_372;
volatile GCT_A20T_5 c1ghost_A20T_373;
volatile GCT_A20T_20 c1ghost_A20T_374;
volatile GCT_A20T_27 c1ghost_A20T_375;
volatile GCT_A20T_19 c1ghost_A20T_376;
volatile GCT_A20T_3 c1ghost_A20T_377;
volatile char c1ghost_A20T_378;
volatile GCT_A20T_20 c1ghost_A20T_379;
volatile GCT_A20T_27 c1ghost_A20T_380;
volatile GCT_A20T_23 c1ghost_A20T_381;
volatile char c1ghost_A20T_382;
volatile char c1ghost_A20T_383;
volatile short c1ghost_A20T_384;
volatile GCT_A20T_64 c1ghost_A20T_385;
volatile char c1ghost_A20T_386;
volatile GCT_A20T_13 c1ghost_A20T_387;
volatile GCT_A20T_16 c1ghost_A20T_388;
volatile GCT_A20T_12 c1ghost_A20T_389;
volatile short c1ghost_A20T_390;
volatile int c1ghost_A20T_391;
volatile GCT_A20T_28 c1ghost_A20T_392;
volatile int c1ghost_A20T_393;
volatile GCT_A20T_23 c1ghost_A20T_394;
volatile GCT_A20T_6 c1ghost_A20T_395;
volatile char c1ghost_A20T_396;
volatile GCT_A20T_64 c1ghost_A20T_397;
volatile GCT_A20T_5 c1ghost_A20T_398;
volatile GCT_A20T_5 c1ghost_A20T_399;
volatile int c1ghost_A20T_400;
volatile char c1ghost_A20T_401;
volatile char c1ghost_A20T_402;
volatile short c1ghost_A20T_403;
volatile char c1ghost_A20T_404;
volatile short c1ghost_A20T_405;
volatile GCT_A20T_64 c1ghost_A20T_406;
volatile GCT_A20T_17 c1ghost_A20T_407;
volatile char c1ghost_A20T_408;
volatile GCT_A20T_7 c1ghost_A20T_409;
volatile char c1ghost_A20T_410;
volatile char c1ghost_A20T_411;
volatile GCT_A20T_23 c1ghost_A20T_412;
volatile GCT_A20T_25 c1ghost_A20T_413;
volatile GCT_A20T_27 c1ghost_A20T_414;
volatile GCT_A20T_12 c1ghost_A20T_415;
volatile GCT_A20T_16 c1ghost_A20T_416;
volatile GCT_A20T_12 c1ghost_A20T_417;
volatile GCT_A20T_21 c1ghost_A20T_418;
volatile GCT_A20T_24 c1ghost_A20T_419;
volatile GCT_A20T_31 c1ghost_A20T_420;
volatile GCT_A20T_5 c1ghost_A20T_421;
volatile GCT_A20T_88 c1ghost_A20T_422;
volatile GCT_A20T_7 c1ghost_A20T_423;
volatile double c1ghost_A20T_424;
volatile GCT_A20T_32 c1ghost_A20T_425;
volatile short c1ghost_A20T_426;
volatile short c1ghost_A20T_427;
volatile GCT_A20T_20 c1ghost_A20T_428;
volatile GCT_A20T_152 c1ghost_A20T_429;
volatile GCT_A20T_21 c1ghost_A20T_430;
volatile GCT_A20T_64 c1ghost_A20T_431;
volatile short c1ghost_A20T_432;
volatile GCT_A20T_3 c1ghost_A20T_433;
volatile char c1ghost_A20T_434;
volatile GCT_A20T_16 c1ghost_A20T_435;
volatile GCT_A20T_27 c1ghost_A20T_436;
volatile GCT_A20T_16 c1ghost_A20T_437;
volatile short c1ghost_A20T_438;
volatile GCT_A20T_27 c1ghost_A20T_439;
volatile GCT_A20T_24 c1ghost_A20T_440;
volatile char c1ghost_A20T_441;
volatile char c1ghost_A20T_442;
volatile GCT_A20T_112 c1ghost_A20T_443;
volatile char c1ghost_A20T_444;
volatile short c1ghost_A20T_445;
volatile char c1ghost_A20T_446;
volatile GCT_A20T_21 c1ghost_A20T_447;
volatile GCT_A20T_6 c1ghost_A20T_448;
volatile GCT_A20T_24 c1ghost_A20T_449;
volatile GCT_A20T_3 c1ghost_A20T_450;
volatile GCT_A20T_27 c1ghost_A20T_451;
volatile GCT_A20T_27 c1ghost_A20T_452;
volatile GCT_A20T_20 c1ghost_A20T_453;
volatile GCT_A20T_25 c1ghost_A20T_454;
volatile GCT_A20T_27 c1ghost_A20T_455;
volatile char c1ghost_A20T_456;
volatile GCT_A20T_23 c1ghost_A20T_457;
volatile short c1ghost_A20T_458;
volatile GCT_A20T_31 c1ghost_A20T_459;
volatile GCT_A20T_96 c1ghost_A20T_460;
volatile char c1ghost_A20T_461;
volatile GCT_A20T_12 c1ghost_A20T_462;
volatile GCT_A20T_19 c1ghost_A20T_463;
volatile GCT_A20T_22 c1ghost_A20T_464;
volatile GCT_A20T_23 c1ghost_A20T_465;
volatile int c1ghost_A20T_466;
volatile GCT_A20T_104 c1ghost_A20T_467;
volatile char c1ghost_A20T_468;
volatile char c1ghost_A20T_469;
volatile GCT_A20T_64 c1ghost_A20T_470;
volatile GCT_A20T_16 c1ghost_A20T_471;
volatile short c1ghost_A20T_472;
volatile int c1ghost_A20T_473;
volatile double c1ghost_A20T_474;
volatile GCT_A20T_80 c1ghost_A20T_475;
volatile GCT_A20T_112 c1ghost_A20T_476;
volatile short c1ghost_A20T_477;
volatile GCT_A20T_5 c1ghost_A20T_478;
volatile GCT_A20T_24 c1ghost_A20T_479;
volatile short c1ghost_A20T_480;
volatile char c1ghost_A20T_481;
volatile GCT_A20T_104 c1ghost_A20T_482;
volatile GCT_A20T_160 c1ghost_A20T_483;
 short ox;
 int xx;
 int dy;
 short oy;
 ox = p3; oy = p4;
 if (!f_13d490(&d_1c1158, &p3, &p4, &p5, &p6)) return;
 cy=p4; {int u=cy;cy=u;}dy=(cy-oy)*p7; xx=ox; {int u=xx;xx=u;} {int off18=dy+(p3-xx);{int u=off18;off18=u;}p1+=off18;} // haelt die Registerfolge der Offsetberechnung wie im Original
 VM *m = d_1c1108;
 unsigned pitch = m->s10;
 unsigned pos = p4 * pitch + p2 + p3;
 unsigned g = (int)m->s4 << 10;
 { unsigned u = pos; pos = u; } // haelt pos im Originalregister vor der Division
 { unsigned u = g; g = u; } // haelt g im Originalregister vor der Division
 unsigned off = pos % g;
 unsigned bank = pos / g;
 unsigned gran = g;
 unsigned short rows = p6;
 unsigned dst = ((unsigned)m->s8 << 4) + off;
 unsigned char b = bank++;
 unsigned short n;
 unsigned rest;
 Blit360::bank1(b);
 while ((unsigned short)rows != 0) {
  n = (gran - off) / pitch;
  rest = gran - (unsigned short)n * pitch - off;
  if ((unsigned short)n >= (unsigned short)rows) {
   Blit360::rows1((char *)p1, (char *)dst, rows, p5, p7, pitch, p8);
   return;
  }
  if ((unsigned)(int)p5 <= rest) {
   ++n;
   Blit360::rows2((char *)p1, (char *)dst, p5, p7, n, pitch, p8);
   {int product18=p7*(unsigned short)n;{int u=product18;product18=u;}unsigned short gh18_0=((BankRegs907*)&d_1c10a8)->ax;unsigned short gh18_1=((BankRegs907*)&d_1c10a8)->dx;unsigned short gh18_2=((BankRegs907*)&d_1c10a8)->cx;unsigned short gh18_3=((BankRegs907*)&d_1c10a8)->pad2;p1+=product18;((BankRegs907*)&d_1c10a8)->ax=gh18_0;((BankRegs907*)&d_1c10a8)->dx=gh18_1;((BankRegs907*)&d_1c10a8)->cx=gh18_2;((BankRegs907*)&d_1c10a8)->pad2=gh18_3;} // haelt die Register- und Konfliktfolge bei der Zeigerfortschaltung
   dst += (unsigned short)n * pitch - gran;
   unsigned vb=(unsigned short)d_1c1108->s8; {unsigned u=vb;vb=u;} // haelt vb im Originalregister
   off=dst-((unsigned)vb<<4); {unsigned u=off;off=u;} // haelt off im Originalregister

   b = bank++;
   Blit360::bank2(b);
  } else {
   Blit360::rows3((char *)p1, (char *)dst, p5, n, p7, pitch, p8);
   p1 += (unsigned short)n * p7;
   dst += (unsigned short)n * pitch;
   Blit360::line1((char *)p1, (char *)dst, rest, p8);
   p1 += rest;
   dst = (unsigned)d_1c1108->s8 << 4;
   b = bank++;
   Blit360::bank3(b);
   Blit360::line2((char *)p1, (char *)dst, p5 - rest, p8);
   p1 += p7 - rest;
   dst += (p5 - rest) + (pitch - p5);
   off = dst - ((unsigned)d_1c1108->s8 << 4);
   ++n;
  }
  rows -= n;
 }
}


//@ f_13f8c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die horizontale Bildschirmauflösung (XResolution) des aktuell eingestellten Grafikmodus
 *   aus dem Modusbeschreiber d_1c1108 zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Bildschirmbreite in Pixeln (d_1c1108->s12, unsigned short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned short f_13f8c0(void)
{
  return d_1c1108->s12;
}

//@ f_13f8d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die vertikale Bildschirmauflösung (YResolution) des aktuell eingestellten Grafikmodus aus
 *   dem Modusbeschreiber d_1c1108 zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Bildschirmhöhe in Pixeln (d_1c1108->s14, unsigned short).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned short f_13f8d0(void)
{
  return d_1c1108->s14;
}

//@ f_13f8e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt das globale Clipping-Rechteck (d_1c1158, d_1c115a, d_1c115c, d_1c115e) fest, an dem alle
 *   nachfolgenden VESA-Zeichenoperationen (f_13e690, f_13eab0, f_13efd0, f_13f360) beschnitten werden.
 * - Eingaben: Linke Grenze a (x0), obere Grenze b (y0), rechte Grenze c (x1) und untere Grenze d (y1) als
 *   unsigned short.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_13f8e0(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
  d_1c1158 = a;
  d_1c115a = b;
  d_1c115c = c;
  d_1c115e = d;
}

//@ f_13f900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt im aktiven VESA-Modus (d_1c114c == 1) die aktuell eingestellte Banknummer d_1a9449 auf
 *   dem internen Bank-Stapel d_1c1138 ab und erhöht den Stapelzeiger d_1c1148 (wird z. B. vor
 *   Maus-Interrupt-Zeichenroutinen genutzt, um die unterbrochene Bank zu sichern).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - index: Aktueller Schreibindex (d_1c1148) im Bank-Stapel d_1c1138.
 === Ende Beschreibung === */
void f_13f900(void)
{
  if (d_1c114c == 1) {
    unsigned char index = d_1c1148;
    d_1c1138[index] = d_1a9449;
    d_1c1148 = index + 1;
  }
}
//@ f_13f930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Holt im aktiven VESA-Modus (d_1c114c == 1) die zuletzt mit f_13f900 gesicherte Banknummer vom
 *   Stapel d_1c1138 herunter und schaltet das primäre VESA-Speicherfenster über AX = 0x4F05 wieder auf diese
 *   Bank zurück, sofern sie sich von d_1a9449 unterscheidet.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - b: Vom Stapel d_1c1138[--d_1c1148] gelesene Banknummer.
 === Ende Beschreibung === */
void f_13f930(void)
{
  unsigned char b;
  if (d_1c114c == 1) {
    b = d_1c1138[--d_1c1148];
    if (d_1c1110 == 1) {
      const signed char &old = d_1a9449;
      if (old != b) {
        d_1a9449 = b;
        d_1c10a8 = 0x4f05;
        d_1c10ac_l = d_1c10ad = 0;
        d_1c10b4 = b;
        f_149cd2(0x10, &d_1c10a8, &d_1c10a8);
      }
    }
  }
}
