/* === Beschreibung (Katalog) ===
 * Einheit riva_t1
 *
 * Diese Einheit bildet den ersten Teil des zentralen Programmstarts und der Hauptinitialisierung von *Schatten
 * über Riva* (riva, Teil 1) und umfasst den Einstiegspunkt main_, die Auswertung der Kommandozeilenparameter,
 * das Einrichten der Grafik-, Maus-, Ton- und CD-ROM-Treiber sowie das Laden der globalen Spieldateien und
 * Spielstände.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 9/11 gleich (suche.py 25.10.2026, Basis riva_t1_P1.CPP)
// riva.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0EA400-0x0EC070
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int f_019fd0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0391f0(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_03eca0(int p1);                                   // reg eax stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_056930();                                         // reg - stapel 0
int f_056950();                                         // reg - stapel 0
int f_056a30(int p1);                                   // reg eax stapel 0
int f_056a40(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_060a70();                                         // reg - stapel 0
int f_08c920(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09a400();                                         // reg - stapel 0
int f_0b38e0();                                         // reg - stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dbff0(int p1);                                 // reg eax stapel 0
int f_0dc050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd6d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de600(int p1, int p2);                           // reg edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0de800(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1216f0();                                         // reg - stapel 0
int f_121fd0();                                         // reg - stapel 0
int f_1223c0();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_1264f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_126840(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
extern const char d_1a663c[];           // Text 0x1A663C

#pragma inline_depth(0)
#define EQI(x,v) (((x)==(v))?1:0)
#define C64 ((int)&d_1c2c64)
#define C00 ((int)&d_1c2c00)
#define C44 ((int)&d_1c2c44)
#define OBA ((int)&ob)
typedef RivaTextContextData OB;
typedef struct {int z[5];} T14;
extern int d_01046a, d_1a34e0, d_1baac0, d_1c0004, d_1c21b4, d_1c2a84, d_1c2c00, d_1c2c44, d_1c2c64, d_1c3498, d_1c349c, d_1c3870;
extern signed char d_1bcaa0, d_1bed70, d_1bed7c, d_1bedb8, d_1bee00, d_1bee0c, d_1bee18, d_1c00a8, d_1c00ac, d_1c00c4, d_1c00c8, d_1c00e4;
void *f_147c84(void *p, int n, void *t);
void f_1254a0(int p1, int p2);
void __cdecl f_149eb4(void *p, int a, int b);
void __cdecl f_099ef0(void *p, int a, int b);
short f_0bf820(int, ...);
short f_0bfa20(int, ...);

int f_0bde40(int p1);
int f_0db9a0(int p1);
int f_0db9a0(int p1, int p2);
short f_0d54f0(int p1, int p2);
short f_1457e0(int p1);
short f_044c90(int p1, int p2, int p3);
void f_0ea210(void);
void f_0ea220(void);
void f_0ea230(void);
void f_0ea240(void);
//@ f_0ea400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ist der Haupteinstiegspunkt (main_) der ausführbaren Datei RIVA.EXE, initialisiert den
 *   Zufallsgenerator, die Speicherverwaltung, das Dateisystem, die Konfiguration und die Hardwaretreiber,
 *   startet die Intro-Sequenzen sowie die Hauptmenü- und Spielschleife (f_016c10) und räumt beim Programmende
 *   alle Subsysteme sauber wieder auf.
 * - Eingaben: Die Funktion erhält die Anzahl der Kommandozeilenargumente (argc), das Array der Argumentzeiger
 *   (argv) sowie den Zeiger auf die Umgebungsvariablen (envp).
 * - Rückgabewert: Die Funktion gibt den numerischen Rückgabecode des Hauptprogramms an das Betriebssystem DOS
 *   zurück.
 === Ende Beschreibung === */
void f_0ea400(void)
{
  OB ob;
  int t;
  short a, b;
  void *p;
  t = (int)new (mark(d_1a663c, 0x14a)) char[0x300];
  p = f_147c84((void *)t, 0x100, &d_1baac0);
  p = p ? p : (void *)0;
  a = f_0de7f0(d_1c0004);
  b = a;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  f_0de600(d_1c0004, (int)&d_1c21b4);
  *(int *)(ob.addresses.numbers + 4) = f_133fe0((int)&d_1c3498, (int)&d_1c21b4);
  if (a == 1) {
    f_057220(C00, 0x8030044, 0);
    f_057220(C00, 0x8030045, 0);
  } else if (a > 0) {
    f_057220(C00, 0x8030042, 0);
    f_057220(C00, 0x8030043, 0);
  }
  f_149eb4(p, 0, 0x100);
  f_09a140(0, 0x19);
  f_10b890(9);
  f_09a0d0(d_1a34e0);
  f_099ef0(p, 0, 0x100);
  f_056930();
  f_056a30(2);
  f_056950();
  if (b > 0) {
    d_1c00a8 = 1;
    f_057220(C00, 0x803000b, 0);
    f_091f70(0x35);
  }
  delete p;
  f_1254a0(OBA, 0);
}
//@ f_0ea560
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchläuft sämtliche übergebenen Kommandozeilenparameter, prüft Schalter wie /c
 *   (Kampftestmodus mit Kampfnummer), /p (Speicherpool-Anzeige), /l (Laden eines bestimmten Spielstands), /f
 *   (Freier Speichertest), /i (Systeminformationsanzeige) oder /v (Versionsanzeige) und setzt die entsprechenden
 *   globalen Steuerflags.
 * - Eingaben: Die Funktion erhält die Anzahl der Kommandozeilenargumente (p1) sowie das Array der
 *   Kommandozeilen-Zeichenketten (p2).
 * - Rückgabewert: Die Funktion liefert keinen sinnvollen Rückgabewert (undefiniertes Register am Funktionsende).
 === Ende Beschreibung === */
void f_0ea560(void)
{
  OB ob;
  int p1, a, b, fl, k;
  short t;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  p1 = f_0606a0(0x120001, 0);
  a = f_038c40(d_1c0004);
  b = f_039320(d_1c0004, 0x33);
  fl = 0;
  *(int *)(ob.addresses.objects + 4) = a;
  *(int *)(ob.addresses.objects + 8) = b;
  f_0bf6c0(C64, 6);
  f_0bfa20(C64, p1, 0, 0x12000001, 0);
  f_0bfa20(C64, p1, 0x12000008, 0x12000002, 0);
  t = f_0d54f0(d_1c0004, 0x2d);
  if (t != -1) {
    f_0dd100(d_1c0004, 0x2d);
    f_0bf820(C64, 0x12000003, 0);
    fl = 1;
  }
  f_0bfa20(C64, p1, 0x12000008, 0x12000004, 0);
  k = f_0de7e0(d_1c0004);
  if (k >= 10) {
    f_0db8b0(d_1c0004, 10);
    f_0bfa20(C64, p1, 0x12000008, 0x12000005, 0);
    fl = 1;
  }
  if (!fl) {
    f_0bfa20(C64, p1, 0x12000008, 0x12000006, 0);
    f_0db820(d_1c0004, 10);
    f_0dcf00(d_1c0004, 0x2d, 1);
  }
  f_0bfa20(C64, p1, 0x12000008, 0x12000007, 0);
  f_057220(C00, 0x803000d, 0);
  f_056a50(0x15000e);
  d_1bedb8 = 1;
  f_091f70(0x36);
  f_0bf680(C64);
  if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
  f_1254a0(OBA, 0);
}
//@ f_0ea740
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die grundlegenden Laufzeitstrukturen des Spiels vor dem Treiberstart,
 *   legt den Speicherpool (f_0e25f0), die Text- und Sprachverwaltung (f_0b04f0), die Interrupt- und
 *   Timer-Überwachung (f_0a76e0) sowie den Tastaturpuffer an und prüft auf einen Warmstart oder ein
 *   gespeichertes Notfall-Flag.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Grundinitialisierung erfolgreich war, oder 0 bei einem
 *   Fehler.
 === Ende Beschreibung === */
void f_0ea740(void)
{
  OB ob;
  int p1, a;
  short r;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  a = f_038c40(d_1c0004);
  p1 = f_0606a0(0x120001, 1);
  *(int *)(ob.addresses.objects + 4) = a;
  f_0bf6c0(C64, 6);
  r = f_0bfa20(C64, p1, 0, 0x12000009, 2, 0x1200000a, 0x1200000b);
  if (r == 2) f_0bfa20(C64, p1, 0, 0x1200000d, 0); else f_0bfa20(C64, p1, 0, 0x1200000c, 0);
  f_056a50(0x15000f);
  f_056930();
  f_056a30(3);
  f_056950();
  d_1c00ac = 1;
  f_091f70(0x37);
  f_0bf680(C64);
  if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
  f_1254a0(OBA, 0);
}
//@ f_0ea840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet und registriert die Haupt-Archivdateien des Spiels (RIVA.alf beziehungsweise
 *   die CD-Archivpfade aus der Konfigurationsdatei), prüft das Vorhandensein wichtiger Spieldaten (wie fade.tab
 *   und der eingelegten Spiel-CD) und gibt bei fehlenden Dateien oder zu wenig Speicher eine entsprechende
 *   Fehlermeldung aus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn alle benötigten Spieldateien und Archive gefunden wurden,
 *   oder 0 bei einem Abbruch.
 === Ende Beschreibung === */
void f_0ea840(void)
{
  OB ob;
  int p1, a, cur, res, b, c;
  short s;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  p1 = f_0606a0(0x120001, 2);
  a = f_038c40(d_1c0004);
  cur = a;
  res = a;
  do {
    if (f_042380((struct hero *)(cur)) == 1) { res = cur; break; }
    cur = f_0391b0(d_1c0004, cur);
  } while (cur != f_038c40(d_1c0004));
  b = f_039320(d_1c0004, 0x33);
  c = f_038be0(d_1c0004);
  s = f_0db9a0(d_1c0004);
  if (s > 1) while (c == b) c = f_038be0(d_1c0004);
  *(int *)(ob.addresses.objects + 4) = res;
  *(int *)(ob.addresses.objects + 8) = b;
  *(int *)(ob.addresses.objects + 0xc) = c;
  f_0bf6c0(C64, 6);
  f_0bfa20(C64, p1, 0, 0x1200000e, 0);
  f_125ed0(C44, 5);
  f_0bfa20(C64, p1, 0, 0x1200000f, 0);
  f_0bf680(C64);
  if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
  f_1254a0(OBA, 0);
}
//@ f_0ea980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion richtet den VESA-/SVGA-Grafikmodus und die 320x200-Bildschirmpuffer ein, initialisiert
 *   den Maustreiber sowie die Standard-Mauszeigergrafiken und schaltet das Soundsystem samt CD-Audio-Wiedergabe
 *   ein.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn Grafik, Maus und Ton erfolgreich initialisiert wurden, oder
 *   0, falls der Grafiktreiber oder Bildschirmspeicher nicht bereitgestellt werden konnte.
 === Ende Beschreibung === */
void f_0ea980(void)
{
  OB ob;
  int p1, a, cur, res, b, c, q; short s;
  f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  p1 = f_0606a0(0x120001, 3);
  a = f_038c40(d_1c0004);
  cur = a;
  res = a;
  do {
    if (f_042380((struct hero *)(cur)) == 1) { res = cur; break; }
    cur = f_0391b0(d_1c0004, cur);
  } while (cur != f_038c40(d_1c0004));
  b = f_039320(d_1c0004, 0x33);
  c = f_038be0(d_1c0004);
  q = res;
  s = f_0db9a0(d_1c0004);
  if (s > 1) while (c == b) c = f_038be0(d_1c0004);
  *(int *)(ob.addresses.objects + 4) = q;
  *(int *)(ob.addresses.objects + 8) = b;
  *(int *)(ob.addresses.objects + 0xc) = c;
  f_0bf6c0(C64, 6);
  f_0bfa20(C64, p1, 0, 0x12000010, 0);
  if (f_0bf6f0(C64, 0x12000011) == 1) {
    f_0bf730(C64, 0x12000012);
    f_0bf730(C64, 0x12000013);
    d_1bee0c = 1;
    f_040780(b, 5);
  }
  f_0bf730(C64, 0x12000014);
  if (EQI(d_1bee0c, 1)) {
    if (s > 1) f_0bf730(C64, 0x12000015); else f_0bf730(C64, 0x12000016);
  }
  d_1c00c4 = 1;
  d_1bee00 = 1;
  f_091f70(0x38);
  f_056930();
  f_056a30(10);
  f_056950();
  f_057220(C00, 0x8030011, 0);
  f_0bf680(C64);
  if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
  f_1254a0(OBA, 0);
}
//@ f_0eab60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fährt das Grafik-, Maus- und Tonsystem beim Verlassen des Spiels kontrolliert
 *   herunter, gibt die Bildschirmpuffer frei und schaltet die Hardware zurück in den DOS-Textmodus.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert den Rückgabewert der Grafikmodus-Wiederherstellung (f_136bc0) zurück.
 === Ende Beschreibung === */
void f_0eab60(void)
{
  if (f_126410(C44) > 0x93a8) {
    if (f_126410(C44) <= 0x190c8) {
      f_0ea840();
      f_0dd6d0(d_1c0004, 0x15e0, 0x7ff8);
      f_060a70();
      f_0ea980();
    }
  }
}
//@ f_0eabb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion beendet die allgemeinen Hintergrunddienste des Spiels, schließt das Textsystem
 *   (f_0b0580), gibt den zentralen Speicherpool (f_0e2750) frei und deinstalliert die Timer- und
 *   Interrupt-Routinen (f_0a77e0).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Interrupt-Deinstallation (f_0a77e0) zurück.
 === Ende Beschreibung === */
void f_0eabb0(void)
{
  if (f_126410(C44) > 0x93a8) {
    if (f_126410(C44) <= 0x190c8) {
      f_0ea840();
      f_060800(0x120002, 1, 0);
      f_0ea980();
    }
  }
}
//@ f_0eac00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt die globalen Spieltabellen und Grundgrafiken in den Speicher, darunter die
 *   Farbumrechnungstabellen (fade.tab, dark.tab), die Gegenstandsdatenbank (items.dat, itemname), die Monster-
 *   und Zaubertabellen, die Standard-Schriftarten sowie die Rahmen- und Kompassgrafiken der Benutzeroberfläche.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn alle Kerndateien geladen werden konnten, oder 0 bei einem
 *   Ladefehler.
 === Ende Beschreibung === */
void f_0eac00(void)
{
  OB ob;
  int p1, a;
  void *q;
  if (f_126410(C44) >= 0xa8c0) {
    if (f_126410(C44) <= 0x17bb0) {
      f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      a = f_038be0(d_1c0004);
      p1 = f_0606a0(0x120001, 4);
      q = f_147c84(new (mark(d_1a663c, 0x28f)) char[0x300], 0x100, &d_1baac0);
      if (q == 0) q = 0;
      *(int *)(ob.addresses.objects + 4) = a;
      f_0bf6c0(C64, 6);
      f_0bfa20(C64, p1, 0, 0x12000017, 0);
      f_0bfa20(C64, p1, 0, 0x12000018, 0);
      f_0bfa20(C64, p1, 0, 0x12000019, 0);
      f_0bfa20(C64, p1, 0, 0x1200001a, 0);
      f_0bfa20(C64, p1, 0, 0x1200001b, 0);
      f_149eb4(q, 0, 0x100);
      f_09a140((int)q, 0x19);
      f_0dd750(d_1c0004, 0x1cc);
      f_1223c0();
      f_09a120((int)q, 0x19);
      f_0bfa20(C64, p1, 0, 0x1200001c, 0);
      d_1bcaa0 = 1;
      f_091f70(0x39);
      f_057220(C00, 0x8030013, 0);
      f_0bf680(C64);
      d_1c00e4 = 5;
      delete q;
      if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
      f_1254a0(OBA, 0);
    }
  }
}
//@ f_0eadd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt alle in f_0eac00 reservierten globalen Tabellen, Schriftarten, Gegenstandslisten
 *   und Oberflächen-Grafikobjekte beim Programmende oder Neustart wieder frei.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt den Statuswert des letzten Aufräumschritts zurück.
 === Ende Beschreibung === */
void f_0eadd0(void)
{
  OB ob;
  int n, a, b, c, e, cur, id;
  short r, k;
  if (EQI(d_1c00e4, 1)) {
    d_1c00e4 = 0;
    f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    a = f_038be0(d_1c0004);
    b = f_039320(d_1c0004, 0x33);
    c = f_038be0(d_1c0004);
    cur = e = f_038c40(d_1c0004);
    n = f_0db9a0(d_1c0004);
    r = f_044c90(b, 0x33, 0xf);
    k = 1;
    if (r == -99) k = 4;
    else if (r <= 0) k = 2;
    if ((short)n > 1) while (c == b) c = f_038be0(d_1c0004);
    if ((short)n > 1) id = (k != 1) + 0x1200001d;
    else id = (k != 1) + 0x1200001f;
    *(int *)(ob.addresses.objects + 4) = a;
    *(int *)(ob.addresses.objects + 8) = b;
    *(int *)(ob.addresses.objects + 0xc) = c;
    f_0bf730(C64, id);
    do {
      short t = f_1457e0(10);
      f_044850(cur, (short)(t + k * 5), 5);
      short u = f_1457e0(0x32);
      f_0d4800(u);
      cur = f_0391b0(d_1c0004, cur);
    } while (cur != e);
    f_0bf730(C64, 0x12000021);
    f_039a80(d_1c0004, (int)f_0ea230);
    d_1c00c8 = 1;
    f_057220(C00, 0x803000c, 0);
    f_091f70(0x3a);
    f_1254a0(OBA, 0);
  }
}
//@ f_0eafa0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion bereitet einen neuen oder zu ladenden Spieldurchlauf vor, indem sie die Gruppen- und
 *   Heldenstrukturen (d_1bb970), das Automap- und Reisesystem, die Quest- und Dialogzustände sowie die Musik-
 *   und Lichtparameter auf ihre Ausgangswerte setzt und bei Bedarf direkt einen per Kommandozeile übergebenen
 *   Spielstand lädt.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreicher Spielinitialisierung zurück oder 0, wenn ein Speicher-
 *   oder Spielstandsfehler auftritt.
 === Ende Beschreibung === */
void f_0eafa0(void)
{
  OB ob;
  int p1, a, b, c;
  short s, t;
  if (f_126410(C44) >= 0xa8c0) {
    if (f_126410(C44) <= 0x17bb0) {
      f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
      p1 = f_0606a0(0x120001, 0);
      a = f_038c40(d_1c0004);
      b = f_039320(d_1c0004, 0x10);
      c = f_038be0(d_1c0004);
      s = f_0db9a0(d_1c0004);
      if (s > 1) while (c == b) c = f_038be0(d_1c0004);
      *(int *)(ob.addresses.objects + 4) = a;
      *(int *)(ob.addresses.objects + 8) = b;
      *(int *)(ob.addresses.objects + 0xc) = c;
      f_0bf6c0(C64, 6);
      f_0bfa20(C64, p1, 0x12000008, 0x12000001, 0);
      if (s > 1) {
        f_0bfa20(C64, p1, 0x12000008, 0x12000022, 0);
        f_0bfa20(C64, p1, 0x12000008, 0x12000023, 0);
        f_0bfa20(C64, p1, 0x12000008, 0x12000024, 0);
      } else {
        f_0bfa20(C64, p1, 0x12000008, 0x12000025, 0);
        f_0bfa20(C64, p1, 0x12000008, 0x12000026, 0);
        f_0bfa20(C64, p1, 0x12000008, 0x12000027, 0);
      }
      t = f_0d54f0(d_1c0004, 0x2d);
      if (t != -1) {
        f_0dd100(d_1c0004, 0x2d);
        f_0bfa20(C64, p1, 0x12000008, 0x12000028, 0);
      } else {
        f_0bfa20(C64, p1, 0x12000008, 0x12000029, 0);
        f_0dcf00(d_1c0004, 0x2d, 1);
      }
      f_0bfa20(C64, p1, 0x12000008, 0x1200002a, 0);
      if (s > 1) f_0bf730(C64, 0x1200002b);
      d_1bed7c = 1;
      f_057220(C00, 0x8030014, 0);
      f_091f70(0x3b);
      f_056930();
      f_056a40(9);
      f_056950();
      f_056930();
      f_056a40(10);
      f_056950();
      f_0bf680(C64);
      if (p1) delete (char *)((int)(((RivaRasterImage*)(p1))->f_0fad20( 0)));
      f_1254a0(OBA, 0);
    }
  }
}
//@ f_0eb230
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion räumt sämtliche dynamischen Daten eines laufenden Spiels (Helden- und
 *   Gruppenstrukturen, geladene Orts- und Dungeon-Daten, aktive Timer-Ereignisse und Musikstücke) wieder ab,
 *   wenn der Spieler ins Hauptmenü zurückkehrt oder das Spiel beendet.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion liefert das Ergebnis des abschließenden Aufräumaufrufs zurück.
 === Ende Beschreibung === */
void f_0eb230(void)
{
  OB ob;
  int p0, p5, p6, p7, p8 = 0;
  int a, b, c, cur, o;
  short n;
  int be0(int);
  #pragma aux be0 "f_038be0" modify [eax edx]
  extern volatile int d_v1c0004; // haelt das Laden von d_1c0004 vor dem Aufruf von f_0db9a0 wie im Original
  #pragma aux d_v1c0004 "W?d_1c0004$ni"
  if (EQI(d_1bed7c, 1) && EQI(d_1bee18, 0) &&
      (EQI(d_1bed70, 1) || f_1264f0(C44, 0x1e528, 0x5460) == 1)) {
    f_060a10(0x1046a);
    f_125400(OBA, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    p0 = f_0606a0(0x120001, 0);
    p5 = f_0606a0(0x120001, 5);
    p6 = f_0606a0(0x120001, 6);
    p7 = f_0606a0(0x120001, 7);
    p8 = f_0606a0(0x120001, 8);
    a = f_038c40(d_1c0004);
    b = f_039660(d_1c0004, 0xd);
    c = be0(d_1c0004);
    n = f_0db9a0(d_v1c0004, a);
    do {
      cur = f_0391f0(d_1c0004);
    } while (!f_0d4a60(cur));
    if (n > 1) while (c == b) c = f_038be0(d_1c0004);
    *(int *)(ob.addresses.objects + 4) = a;
    *(int *)(ob.addresses.objects + 8) = cur;
    *(int *)(ob.addresses.objects + 0xc) = b;
    *(int *)(ob.addresses.objects + 0x10) = c;
    f_0bf6c0(C64, 6);
    if (f_0bf820(C64, 0x1200002c, 2, 0x1200002d, 0x1200002e) == 1) {
      f_125ed0(C44, 0x1e);
      f_0bf730(C64, 0x1200002f);
    }
    if (EQI(d_1bed70, 1)) {
      f_0bf730(C64, 0x12000030);
      f_0bfa20(C64, p0, 0x12000008, 0x12000031, 0);
      if (n > 1) f_0bfa20(C64, p0, 0x12000008, 0x12000032, 0);
      else f_0bfa20(C64, p0, 0x12000008, 0x12000033, 0);
      f_0bfa20(C64, p0, 0x12000008, 0x12000034, 0);
      f_0bf730(C64, 0x12000035);
    } else {
      f_0bf730(C64, 0x12000036);
      if (n > 1) {
        f_0bfa20(C64, p5, 0, 0x12000037, 0);
        f_0bfa20(C64, p5, 0, 0x12000038, 0);
      } else {
        f_0bfa20(C64, p5, 0, 0x12000039, 0);
        f_0bfa20(C64, p5, 0, 0x1200003a, 0);
      }
    }
    f_039a80(d_1c0004, (int)f_0ea210);
    f_03eca0(1);
    f_125f70(C44, 1);
    f_0dd7f0(d_1c0004, 1, 0x1654);
    f_039a80(d_1c0004, (int)f_0ea220);
    f_039a80(d_1c0004, (int)f_0ea240);
    f_0bf6c0(C64, 7);
    f_0bde40(C64);
    f_0bfa20(C64, p6, 0, 0x1200003b, 0);
    f_0bf680(C64);
    if (n > 1) f_0bfa20(C64, p7, 0, 0x1200003c, 0);
    f_0bf6c0(C64, 7);
    f_0bfa20(C64, p7, 0, 0x1200003d, 0);
    f_0bf680(C64);
    f_125f70(C44, 3);
    f_0bf730(C64, 0x1200003e);
    f_10b890(0xd);
    f_0bde40(C64);
    if (n > 1) f_0bfa20(C64, p8, 0, 0x1200003f, 0);
    else f_0bfa20(C64, p8, 0, 0x12000040, 0);
    {
      int t = (int)new (mark(d_1a663c, 1000)) T14;
      o = t ? f_112df0(t, 0x46, 0, 1) : t;
    }
    f_113640(o);
    f_113340(o, 0x1a2, f_0dbff0(d_1c0004), 0);
    f_112ec0(o);
    if (o) delete (char *)f_112e70(o, 0);
    f_0bf730(C64, 0x12000041);
    f_0bfa20(C64, p7, 0, 0x12000042, 0);
    if (n > 1) f_0bf730(C64, 0x12000043);
    f_019fd0((int)&d_1c2a84, 0, 0xfce50000, 0x7940000, 0x12000044);
    d_1bee18 = 1;
    f_057220(C00, 0x8030015, 0);
    f_056930(); f_056a40(3); f_056950();
    f_056930(); f_056a40(4); f_056950();
    f_056930(); f_056a40(5); f_056950();
    f_056930(); f_056a40(6); f_056950();
    f_056930(); f_056a30(7); f_056950();
    f_0bf680(C64);
    if (p8) delete (char *)((int)(((RivaRasterImage*)(p8))->f_0fad20( 0)));
    if (p7) delete (char *)((int)(((RivaRasterImage*)(p7))->f_0fad20( 0)));
    if (p6) delete (char *)((int)(((RivaRasterImage*)(p6))->f_0fad20( 0)));
    if (p5) delete (char *)((int)(((RivaRasterImage*)(p5))->f_0fad20( 0)));
    if (p0) delete (char *)((int)(((RivaRasterImage*)(p0))->f_0fad20( 0)));
    f_1254a0(OBA, 0);
  }
}
