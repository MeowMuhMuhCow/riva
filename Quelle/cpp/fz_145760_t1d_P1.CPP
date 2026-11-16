/* === Beschreibung (Katalog) ===
 * Einheit fz_145760_t1d (0x1461F4 - 0x146920)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des digitalen Sound-Subsystems (hmi.cpp, Klasse HM) auf Basis des *HMI
 * Sound Operating System (SOS)*. Eine Instanz dieser Klasse repräsentiert einen aktiven digitalen Soundkanal
 * (entweder ein komplett im Speicher liegendes Soundeffekt-Sample oder einen per Doppelpufferung von
 * Festplatte/CD gestreamten Sprach- bzw. Geräuschstrom).
 === Ende Beschreibung === */
// OPT -4r -od -zp1 -s
// Astra650: Teil aus fz_145760_t1, 1461f4 bis 146920 exklusiv.
// P3 8/41 gleich (suche.py 26.10.2026, Basis fz_145760_t1_P1.CPP)
// HINWEIS: nur f_1461f4..f_146900 sind im Original unoptimiert (-od, ebp-Rahmen); f_145760..f_146170 (dice/aifload) sind optimiert (-4r -oneatx -zp1 -s)
// fz_145760_t1 (Schatten ueber Riva) - Pass 1 Einheit 145760-146920
#include <string.h>
#include <stdlib.h>
// Defaultargument von HMFileInterface::m14 muss eingebettet werden.
#pragma inline_depth(1)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
int f_1664d0(const char *a, const char *b, int c);
int f_014540(int sz, const char *file, int line);
int f_099ef0(int, ...);
int f_145547(const char *a, const char *b, int n);
void f_145300(void *p, int v, int n);
void *f_147c84(void *p, int n, int d);
int f_147cd0(int p1);
int f_147ef0(int p1, int p2, char *p3, int p4);
int f_1680f5(int a, int b);
int f_1687c9(int a, int b);
short f_167f75(int a, void *b);
int f_146d86(int a, int b);
extern int d_1a97dc; extern int d_1c3914; extern int d_1a9824; extern short d_1c3918; extern int d_1c391c;
extern int d_1a9698; extern int d_1baac0; extern int d_1c2098;
extern const char d_1b8970[]; extern const char d_1b8979[]; extern const char d_1b8982[]; extern const char d_1b898c[];
extern const char d_1a97e0[]; extern const char d_1a97f4[]; extern const char d_1a980c[]; extern const char d_1b8996[];
struct FO;
struct FT { char z0[0x14]; int (*m14)(FO *, int, short); char z1[8]; int (*m20)(FO *, void *, int); char z2[4];
 int (*m28)(FO *); char z3[4]; int (*m30)(FO *); int (*m34)(FO *, int); char z4[8]; int (*m40)(FO *, int, int); };
struct FO { char z[0x14]; FT *vt; };
struct AIF { char z0[4]; signed char type; signed char f5; short w; short h; short n; short c; char z1[0x10];
 char *buf; int name; char c26; signed char c27; char c28; short idx; int len; char *out; char *tmp; char z2[4];
 char b100[100]; FO *f; };
struct X266 { char d[0x266]; };
int f_145c20(AIF *p); int f_145c80(AIF *p); int f_145d60(AIF *p, int p3); int f_145e30(AIF *p, char *dst);
void f_145ee0(AIF *p, char *dst); void f_146030(AIF *p, char *dst); void f_146170(AIF *p, char *dst);
int f_145a60(AIF *p, int name, int p3, char *buf, char fl);
char f_145df0(AIF *p);
#define ABS(x) abs(x)
#define ROLL(r,e) { short _e = (e); int _t; if (_e <= 0) f_1664d0(d_1b8970, d_1a97e0, 0x2f); _t = (int)_lrotl(_lrotl(d_1a97dc ^ d_1c3914, 2) + d_1c3914 ^ d_1a97dc, 3); d_1a97dc = ABS(_t) + 1; r = ABS(_t) % _e + 1; }
#define MD 0x200
struct REC { int a; char z0[8]; unsigned len; char z1[0xc]; int r1c; char z2[0xc]; int r2c; char z3[4]; int r34; int r38; int r3c; int r40; int r44; int r48; char z4[0x10]; void *r5c; void *r60; char z5[0x8c]; };
struct HM { int a; unsigned short s4; int b; int c; int d; int e; short idx; int pos; short s1c; unsigned short s1e; short s20; int i22; unsigned short mode; int x; FO *f; char *buf[2]; REC rec[2]; short off; };
struct CB { char z[0x28]; unsigned short w; };
void f_146552(HM *p); void f_1466cd(HM *p); void f_146864(HM *p, int *q); void f_1468dc(HM *p); void __cdecl f_146809(CB *a); void __cdecl f_146839(CB *a);
//@ f_1461f4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor eines digitalen Soundkanal-Objekts (HM). Er übernimmt einen geöffneten
 *   Dateistream (p2), die Startparameter (Datenoffset p3, Puffergröße p4, Samplingrate p5, Lautstärke p6,
 *   Panning p7 und Wiederholungszähler p8), reserviert den ersten Lesepuffer (P(0x0c)) und bei gestreamten
 *   Dateien einen zweiten Wechselpuffer (P(0x10)), befüllt den Startpuffer über f_1466cd und registriert das
 *   Sample über f_146552 beim HMI-SOS-Treiber.
 * - Eingaben:
 *   - p: Zeiger auf das HM-Soundkanal-Objekt.
 *   - p2: Zeiger auf das geöffnete Dateiobjekt (F), aus dem die Audiodaten gelesen werden.
 *   - p3: Byte-Offset des Beginns der PCM-Audiodaten innerhalb der Datei (nach einem etwaigen
 *     Attic-Soundheader).
 *   - p4: Maximale Größe eines Streaming-Teilpuffers in Bytes.
 *   - p5: Basis-Abtastrate in Hz (z. B. 11025 oder 22050).
 *   - p6: Startlautstärke des Kanals.
 *   - p7: Stereoposition (Panning, 0..255).
 *   - p8: Anzahl der Wiederholungen (Loops).
 * - Rückgabewert: Gibt den initialisierten Objektzeiger p zurück.
 * - Wichtige Variablen:
 *   - P(0x04): Zeiger auf das zugehörige Dateiobjekt; wird auf 0 gesetzt und sofort geschlossen, wenn das
 *     gesamte Sample in den ersten Puffer passt.
 *   - P(0x0c), P(0x10): Erster und zweiter Audiodatenpuffer für unterbrechungsfreies Double-Buffering.
 *   - I(0x18): Verbleibende noch von Datei nachzuladende Bytes.
 *   - S(0x36): Vom HMI-SOS-Treiber vergebenes Sample-Handle (-1 wenn inaktiv).
 === Ende Beschreibung === */
HM *f_1461f4(HM *p, int a, int f, short off, int b, int s1c, int s1e, int i22, int s20, int mode)
{
 p->a = a; p->f = (FO *)f; p->b = b; p->off = off; p->s1c = s1c; p->s1e = s1e; p->i22 = i22; p->s20 = s20; p->mode = mode;
 p->x = 0;
 f_1466cd(p);
 p->s4 = f_167f75(p->b, &p->rec[0]);
 if ((short)p->s4 == (short)0xffff) { p->d = 1; } else { p->d = 0; }
 p->e = 1; p->idx = 0;
 return p;
}
//@ f_1462d3
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Virtueller Destruktor eines HM-Soundkanals. Er markiert den Kanal über das globale
 *   Verriegelungsflag d_1a9820 als im Abbau befindlich, beendet eine noch laufende Wiedergabe im HMI-SOS-Treiber
 *   (f_155b20 / sosDIGIStopSample), schließt und löscht ein eventuell noch offenes Streaming-Dateiobjekt
 *   (P(0x04)) und gibt die beiden Audiopuffer (P(0x0c), P(0x10)) wieder frei.
 * - Eingaben: p (Zeiger auf das HM-Objekt), fl (Destruktor-Flags).
 * - Rückgabewert: Gibt p zurück.
 * - Wichtige Variablen:
 *   - d_1a9820: Schutzflag gegen konkurrierende Interrupt-Nachladezugriffe während des Abbaus.
 *   - S(0x36): SOS-Sample-Handle, das bei aktivem Kanal (!= -1) gestoppt wird.
 === Ende Beschreibung === */
HM *f_1462d3(HM *p, int q)
{
 if ((short)p->s4 != (short)0xffff) f_1680f5(p->b, p->s4);
 if (p->buf[0]) delete p->buf[0];
 if (p->buf[1]) delete p->buf[1];
 return p;
}
//@ f_14633d
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das vom HMI-SOS-Treiber vergebene Sample-Handle (p->s4) des digitalen
 *   Soundkanal-Objekts p zurück.
 * - Eingaben: p (Zeiger auf das HM-Soundkanal-Objekt).
 * - Rückgabewert: Das 16-Bit-Sample-Handle (unsigned short).
 * - Wichtige Variablen: p->s4 (SOS-Sample-Handle).
 === Ende Beschreibung === */
unsigned short f_14633d(HM *p)
{
    return p->s4;
}
//@ f_146364
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt die Ressourcen-ID (p->a) der Audiodatei zurück, die im digitalen Soundkanal p
 *   abgespielt wird.
 * - Eingaben: p (Zeiger auf das HM-Soundkanal-Objekt).
 * - Rückgabewert: Die 32-Bit-Ressourcen-ID (int) des Samples.
 * - Wichtige Variablen: p->a (Ressourcen-ID).
 === Ende Beschreibung === */
int f_146364(HM *p)
{
    return p->a;
}
//@ f_146389
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt während des Abspielens eines gestreamten Sounds den nächsten Datenblock aus der Datei
 *   P(0x04) in den inaktiven Wechselpuffer (P(0x0c) oder P(0x10)) nach, sobald der SOS-Interrupt-Callback das
 *   Ende des aktuellen Teilpuffers gemeldet hat (B(0x08) == 1). Sind alle Bytes der Datei eingelesen (I(0x18) ==
 *   0), wird die Datei geschlossen oder bei gesetzter Schleifenwiederholung (S(0x34) != 0) wieder auf den
 *   Datenanfang I(0x28) zurückgespult.
 * - Eingaben: p (Zeiger auf das HM-Soundkanal-Objekt).
 * - Rückgabewert: 1, wenn ein neuer Teilpuffer bereitgestellt wurde, sonst 0.
 * - Wichtige Variablen:
 *   - B(0x08): Flag "Nächster Streaming-Block wurde an SOS übergeben, Gegenpuffer muss nachgeladen werden".
 *   - B(0x09): Index des aktuell abspielenden Puffers (0 oder 1).
 *   - I(0x1c), I(0x20): Tatsächliche Datenlänge im ersten bzw. zweiten Wechselpuffer.
 === Ende Beschreibung === */
// Nichtpolymorphe Basis: vptr liegt wie im Original bei +0x14.
struct HMFileBase { char data[0x14]; };
struct HMFileInterface : HMFileBase {
 virtual int m0(); virtual int m4(); virtual int m8(); virtual int mC(); virtual int m10();
 virtual int m14(int, short = 0x200); virtual int m18(); virtual int m1C();
 virtual int m20(void *, int); virtual int m24(); virtual int m28();
 virtual int m2C(); virtual int m30(); virtual int m34(int);
 virtual int m38(); virtual int m3C(); virtual int m40(int, int);
};
int f_146389(HM *p, int *flag)
{
 int r;
 unsigned n;
 r = 0;
 if (p->mode != 1) {
  if (p->e == 1) {
   p->e = 0;
  } else if (p->d == 1) {
   if (p->s4 != (unsigned short)0xffff) {
    if (f_1687c9(p->b, p->s4) == 0 && d_1c3918 < 16000) {
     d_1c3918++;
    } else {
     d_1c3918 = 0;
     r = 1;
    }
   } else {
    d_1c3918 = 0;
    r = 1;
   }
  } else if (p->c == 0 && *flag == 0) {
   p->idx ^= 1;
   ((HMFileInterface *)p->f)->m14(p->a);
   ((HMFileInterface *)p->f)->m40(p->pos, 0);
   n = ((HMFileInterface *)p->f)->m20(p->buf[p->idx], d_1a9824);
   ((HMFileInterface *)p->f)->m28();
   p->pos += n;
   n &= 0xfffffffe;
   p->rec[p->idx].len = n;
   if (n == 0) { p->d = 1; } else { p->c = 1; }
   *flag = 1;
  }
 } else {
  if (p->d == 1) r = 1;
 }
 return r;
}
//@ f_146552
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Füllt die HMI-SOS-Sample-Startstruktur (_SOS_START_SAMPLE ab Offset +0x3a) mit
 *   Pufferadresse, Länge, Lautstärke, Panning, Kanalzuordnung, Callback-Zeigern (f_146809, f_146839, f_146864)
 *   und Abtastrate aus und startet die Wiedergabe über den SOS-Treiberaufruf f_1558ca (sosDIGIStartSample).
 * - Eingaben: p (Zeiger auf das HM-Objekt).
 * - Rückgabewert: Vom SOS-Treiber zugewiesenes Sample-Handle (S(0x36)) oder -1 bei Fehler.
 * - Wichtige Variablen:
 *   - P(0x3a): Zeiger auf den ersten abzuspielenden PCM-Puffer (P(0x0c)).
 *   - I(0x42): Länge des ersten Blocks in Bytes (I(0x1c)).
 *   - I(0x4a): Kombinierter Lautstärkewert ((vol << 7) | (vol >> 1)).
 *   - I(0x66): Effektive Wiedergaberate in Hz ((rate * pitch) / 100).
 === Ende Beschreibung === */
void f_146552(HM *p)
{
 f_145300(&p->rec[0], 0, 0xf0);
 p->rec[0].r38 = 8; p->rec[0].r3c = 1; p->rec[0].r40 = 0x8000;
 p->rec[0].r44 = p->s1e; p->rec[0].r34 = p->i22; p->rec[0].r48 = p->s20;
 p->rec[0].r1c = 0x1000;
 p->rec[0].r2c = (p->s1c << 16) | p->s1c;
 p->rec[0].r60 = (void *)f_146839;
 if (p->mode == 1) {
  p->buf[0] = (char *)f_014540(p->x, d_1a980c, 0xc1);
  if (p->buf[0] == 0) { p->mode = 0; } else { p->rec[0].a = (int)p->buf[0]; }
 }
 if (p->mode == 0) {
  p->rec[0].r5c = (void *)f_146809;
  p->rec[1] = p->rec[0];
  p->buf[0] = (char *)f_014540(d_1a9824, d_1a980c, 0xd2);
  p->buf[1] = (char *)f_014540(d_1a9824, d_1a980c, 0xd3);
  p->rec[0].a = (int)p->buf[0];
  p->rec[1].a = (int)p->buf[1];
 }
}
//@ f_1466cd
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest beim Start oder nach einem Schleifen-Rücksprung die ersten ein bis zwei Datenblöcke
 *   aus der Audiodatei P(0x04) ab dem Datenoffset I(0x28) in die Puffer P(0x0c) und ggf. P(0x10) ein. Passt die
 *   gesamte restliche Audiodatei bereits in den ersten Puffer, wird die Datei sofort geschlossen und gelöscht,
 *   sodass der Sound als reines Speichersample weiterläuft.
 * - Eingaben: p (Zeiger auf das HM-Objekt).
 * - Rückgabewert: 1 bei erfolgreichem Einlesen, 0 bei Dateifehlern.
 * - Wichtige Variablen:
 *   - I(0x18): Gesamtgröße der verbleibenden Audiodaten (Dateigröße - Datenoffset).
 *   - I(0x24): Maximale Blockgröße pro Puffer.
 === Ende Beschreibung === */
void f_1466cd(HM *p)
{
 int n;
 p->x = ((HMFileInterface *)p->f)->m34(p->a) - p->off;
 f_146552(p);
 ((HMFileInterface *)p->f)->m14(p->a);
 ((HMFileInterface *)p->f)->m40(p->off, 0);
 switch(p->mode) {
 case 1:
  n = ((HMFileInterface *)p->f)->m20(p->buf[0], p->x);
  break;
 default:
  n = ((HMFileInterface *)p->f)->m20(p->buf[0], d_1a9824);
  break;
 }
 ((HMFileInterface *)p->f)->m28();
 p->pos = n + p->off;
 n &= 0xfffffffe;
 p->rec[0].len = n;
}
//@ f_146809
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: HMI-SOS-Callback-Routine (Sample-Processed-Callback), die vom Soundtreiber aufgerufen
 *   wird, wenn ein einzelner Sampleblock verarbeitet wurde. Falls die Wiedergabe pausiert werden soll (B(0x0b)
 *   != 0), stoppt sie das Sample im Treiber und setzt S(0x36) = -1.
 * - Eingaben: a (SOS-Callback-Strukturzeiger; das HM-Objekt liegt im Benutzerfeld P(a, 0x4e)).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: B(0x0b) (Abbruch-/Stoppflag), S(0x36) (Sample-Handle).
 === Ende Beschreibung === */
void __cdecl f_146809(CB *a)
{
    f_146864((HM *)f_146d86(d_1a9698, a->w), (int *)a);
}
//@ f_146839
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: HMI-SOS-Callback-Routine für das Ende eines Samplepuffers beim Streaming. Wenn im
 *   Wechselpuffer (1 - B(0x09)) bereits nachgeladene Daten bereitstehen, schaltet sie die SOS-Startstruktur a
 *   nahtlos auf diesen zweiten Puffer um und setzt B(0x08) = 1, damit die Hauptschleife (f_146389) den frei
 *   gewordenen Puffer nachfüllt.
 * - Eingaben: a (SOS-Sample-Strukturzeiger mit HM-Zeiger in P(a, 0x4e)).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: B(0x09) (aktiver Pufferindex 0/1), B(0x08) (Nachladeanforderung).
 === Ende Beschreibung === */
void __cdecl f_146839(CB *a)
{
    f_1468dc((HM *)f_146d86(d_1a9698, a->w));
}
//@ f_146864
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: HMI-SOS-Callback-Routine, die beim endgültigen Ausklingen eines Samples aufgerufen wird
 *   (sosSampleDone). Sie markiert das Sample-Handle S(0x36) als beendet (-1), setzt das Fertig-Flag B(0x0a) = 1
 *   und deaktiviert einen eventuell gekoppelten dynamischen Effektkanal im Soundmanager (d_1c2edc).
 * - Eingaben: a (SOS-Sample-Strukturzeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: B(0x0a) (Sample-Beendet-Flag), S(0x36) (Sample-Handle).
 === Ende Beschreibung === */
void f_146864(HM *p, int *q)
{
 if (p->rec[p->idx].len > 0) {
  q[0] = p->rec[p->idx].a; q[3] = p->rec[p->idx].len; p->c = 0;
 } else { p->d = 1; }
}
//@ f_1468dc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob dieser Soundkanal noch aktiv abgespielt wird, indem abgefragt wird, ob das
 *   Sample-Beendet-Flag B(0x0a) noch 0 ist und der SOS-Treiber das Sample noch nicht als fertig (f_155c35)
 *   meldet.
 * - Eingaben: p (Zeiger auf das HM-Objekt).
 * - Rückgabewert: 1, wenn das Sample noch läuft, sonst 0.
 * - Wichtige Variablen: B(0x0a), S(0x36).
 === Ende Beschreibung === */
void f_1468dc(HM *p)
{
    p->d = 1;
}
//@ f_146900
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Kleiner Timer-Interrupt-Callback des Soundmanagers, der den globalen Sekundenzähler
 *   d_1c3918 hochzählt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c3918 (globaler Zähler).
 === Ende Beschreibung === */
void f_146900(void)
{
 (*(volatile int *)&d_1c391c)++; // erzwingt unter -od das Laden/Inkrementieren/Speichern ueber eax wie im Original
}
