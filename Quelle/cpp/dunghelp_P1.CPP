/* === Beschreibung (Katalog) ===
 * Einheit dunghelp (0x060360 - 0x060AA0)
 *
 * Überblick
 * Die Einheit dunghelp bündelt allgemeine Hilfsfunktionen für die Dungeon-, Orts- und Sequenzsteuerung:
 * zeitabhängiges Herunterzählen von Buff-/Ereigniszählern (f_060400, f_0605c0, f_0605e0), kurzlebige
 * Dialog-/Grafikfenster (f_060360, f_0603b0), das Laden von Rasterbildern aus Archiven (f_0606a0), das Abspielen
 * von Soundeffekten (f_060740, f_060770) und Flic-Videosequenzen (f_060800), Paletten-Ein-/Ausblendungen
 * (f_060990, f_0609d0) sowie die Prüfung und Bereinigung des freien Speichers (f_060a10).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// I9: aus dunghelp_REST.CPP uebernommen (Stufe-2-Stand), Marken 14 neu
// dunghelp.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x060360-0x060AA0. Kleine Hilfsfunktionen der Hoehlen-/Dungeon-Logik: Zaehler herunterzaehlen, Objekte anlegen, Dateiladen.
// STAND 22.10. (Helfer B, Runde 2): alle Funktionen GLEICH ausser f_0606a0 (a/im: Original a->edi, im->esi, wir umgekehrt; 7 Befehle) und f_060800 (1 Befehl: Original "mov edx,1" VOR "mov [d_1c0b99],al"). 8 Befehle / 11 Bytes. Wirkung: d_1c0b1c NICHT volatile + for(;d_1c0b1c==1;) loest Schleife 1 und cmp edx,[mem].
#include <string.h>
extern const char dunghelp_file[];
#pragma aux dunghelp_file "d_1a1974";   // 0x1A1974
extern short d_1a199c[];                                                      // 0x1A199C
struct Lock { Lock(); ~Lock(); int x; };                 // 0x0CE7C0 / 0x0CE7E0
struct Msg { void f_0bf730(long code); }; extern Msg d_1c2c64;
 extern RivaFileManager d_1c2098;
struct Snd { void f_146dfa(int a); }; extern Snd d_1c2edc;
void f_146dfa(Snd *s, int a);
#pragma aux f_146dfa parm [eax] [edx]

struct Prn { void f_019c90(short a, int b); }; extern Prn d_1c2a84;
struct Cnt; extern Cnt d_1c14c4;
void f_13fd60(Cnt *c);
#pragma aux nomod modify exact [eax]
#pragma aux f_13fd60 parm [eax] modify exact [eax]
struct Sc; struct Vt { void *pad[5]; void (*f5)(Sc *); void (*f6)(Sc *); void (*f7)(Sc *); };
struct Sc { char pad[8]; Vt *vt; };
extern Sc *d_1bd6c0;
struct G { char b[0x61]; G *f_0dd7f0(int a, int b); int f_0de7c0(); };
short f_0de820(G *g); short f_0de800(G *g); int f_0de8a0(G *g); void f_0ddfc0(G *g);
extern G *d_1c0004; extern G d_1bfdbc[6];
struct A46 { A46(short n); ~A46(); char d[12]; };
void f_046de0(A46 *p);
struct Gr { Gr(short n, int b, int c); ~Gr(); char d[20]; };
void f_112ec0(Gr *p);


struct Ent2 { void f_050580(int a, short b, int *c, int *d); void f_04feb0(int a, int b, int c, int p5, int p6, int *p7, int *p8, int p9); }; extern Ent2 d_1c2be0;
struct Tab { int f_126410x; };
int f_126410(void *p);
extern signed char d_1bdcf8, d_1bdd00, d_1c00d4, d_1bdcfc, d_1bdcf4, d_1bd6c8, d_1bd74c, d_1c01c0, d_1c00b4;
extern char d_1bdd04, d_1c0b98;
extern volatile char d_1a8958;
extern char d_1c0b99;
extern short d_1bd90c; extern int d_1a9a1c, d_1bf1ac, d_1a80c8;
extern volatile short d_1a8956;
extern int d_1c0b1c; extern int d_1c0b40;
extern char d_1c2c44[]; extern char *d_1c0afc; extern char *d_1c0af8;
void f_149470(unsigned short a); void f_1223c0();
int f_1496d4(unsigned short a);
void f_149524(unsigned short a); void f_149b44(); int f_149640(unsigned short a); void f_149a14(unsigned short a, int b);
void f_154e78(void *p); int f_154f08(int a, int b); void f_149d20(); void f_1216f0(); void f_120bd0();
void f_155bc8(int a); void f_02dc90();
int f_014a60(); void f_11f5f0(); void f_1566b8(int n); void f_15674c();
#pragma aux (nomod) f_014a60
#pragma aux (nomod) f_11f5f0
#pragma aux (nomod) f_1566b8
#pragma aux (nomod) f_15674c
void f_122190(int a, int b, int c); short f_149360(int a, short *t); short f_1457e0(short n);
extern "C" void *memset(void *, int, unsigned);
#define GT(x,n) (((x)>(n))!=0)
#define EQ(x,n) (((x)==(n))!=0)

struct Ids4 { short v[4]; };
extern Ids4 d_1a1994;   // {0x17dd,0x1a99,0x1853,0x1b0f} - Initialisierungsbild liegt im Original
//@ f_060360
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Legt ein temporäres Hilfsobjekt A46(n) auf dem Heap an, führt dessen Aktion über f_046de0(p)
 *   aus und gibt das Objekt sofort wieder frei.
 * - Eingaben:
 *   - n (Kennung oder Parameter für den Konstruktor A46).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p (Dynamisch angelegtes A46-Objekt).
 === Ende Beschreibung === */
void f_060360(short n) {
  A46 *p = new (mark(dunghelp_file, 0x46)) A46(n);
  f_046de0(p);
  delete p;
}
//@ f_0603b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet ein temporäres Grafik-/Animationsfenster Gr(n, 0, 0) für die Bild-/Animationskennung
 *   n, zeigt es über f_112ec0(p) an und zerstört das Fensterobjekt anschließend wieder.
 * - Eingaben:
 *   - n (Kennung der anzuzeigenden Grafik oder Animation).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p (Dynamisch angelegtes Gr-Grafikfensterobjekt).
 === Ende Beschreibung === */
void f_0603b0(short n) {
  Gr *p = new (mark(dunghelp_file, 0x62)) Gr(n, 0, 0);
  f_112ec0(p);
  delete p;
}
//@ f_060400
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeit-Tick-Routine für Dungeons und Orte: Zählt sechs globale Zeitzähler (d_1bdcf8, d_1bdd00,
 *   d_1c00d4, d_1bdcfc, d_1bdcf4, d_1bd6c8) um je 1 herunter (und setzt beim Ablaufen von d_1bdcfc das Flag
 *   d_1bdd04 = 1), versetzt nachts (Tageszeit <= 0xa8c0 oder >= 0x1a5e0) alle Gruppen im Gebiet 0x1a auf einen
 *   von vier zufälligen Startpunkten aus d_1a1994 (mit Meldung 0x23000004), löst um 6:00 Uhr morgens (0xa8c0)
 *   außerhalb von Gebiet 6 f_02dc90() aus und ruft im aktiven Dungeon außerhalb des Kampfes die virtuelle
 *   Tick-Methode vt->f6 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bdcf8, d_1bdd00, d_1c00d4, d_1bdcfc, d_1bdcf4, d_1bd6c8 (Globale Countdown-Zähler für zeitbegrenzte
 *     Orts-/Dungeon-Zustände).
 *   - ids (Kopie der vier Positionskennungen {0x17dd, 0x1a99, 0x1853, 0x1b0f} aus d_1a1994).
 *   - d_1bd6c0 (Zeiger auf das aktuelle Dungeon-/Orts-Steuerobjekt).
 === Ende Beschreibung === */
void f_060400() {
  if (GT(d_1bdcf8, 1)) d_1bdcf8--;
  if (GT(d_1bdd00, 1)) d_1bdd00--;
  if (GT(d_1c00d4, 1)) d_1c00d4--;
  if (GT(d_1bdcfc, 1) && EQ(--d_1bdcfc, 1)) d_1bdd04 = 1;
  if (GT(d_1bdcf4, 1)) d_1bdcf4--;
  if (GT(d_1bd6c8, 1)) d_1bd6c8--;
  if (f_126410(d_1c2c44) <= 0xa8c0 || f_126410(d_1c2c44) >= 0x1a5e0) {
    Ids4 ids = d_1a1994;
    for (short i = 0; i < 6; i++) {
      G *p = &d_1bfdbc[i];
      if (p->f_0de7c0()) {
        if (f_0de820(p) == 0x1a) {
          p->f_0dd7f0(0, ids.v[(short)(f_1457e0(4) - 1)]);
          if (p == d_1c0004) d_1c2c64.f_0bf730(0x23000004);
        }
      }
    }
  }
  if (f_126410(d_1c2c44) == 0xa8c0) { if (f_0de820(d_1c0004) != 6) f_02dc90(); }
  if (d_1bd6c0) { if (f_0de800(d_1c0004) == -1 && d_1bd90c == 0) d_1bd6c0->vt->f6(d_1bd6c0); }
}
//@ f_0605c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zählt den globalen Sperr- bzw. Verzögerungszähler d_1bd74c um 1 herunter, solange er größer
 *   als 0 ist.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd74c (Globaler Countdown-Zähler).
 === Ende Beschreibung === */
void f_0605c0() {
  if (GT(d_1bd74c, 0)) d_1bd74c--;
}
//@ f_0605e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zweite Zeit-Tick-Routine: Zählt den Zähler d_1c01c0 herunter (und setzt ihn beim Erreichen
 *   von 0 auf -1), schaltet d_1c00b4 nach 6:00 Uhr morgens (> 0xa8c0) von 2 auf 1 um und ruft im aktiven Dungeon
 *   außerhalb des Kampfes die virtuelle Tick-Methode vt->f7 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c01c0, d_1c00b4 (Zeit- und Tageszeit-Zustandsflags).
 *   - d_1bd6c0 (Zeiger auf das aktuelle Dungeon-/Orts-Steuerobjekt).
 === Ende Beschreibung === */
void f_0605e0() {
  if (GT(d_1c01c0, 0) && EQ(--d_1c01c0, 0)) d_1c01c0 = -1;
  if (EQ(d_1c00b4, 2)) { if (f_126410(d_1c2c44) > 0xa8c0) d_1c00b4 = 1; }
  if (d_1bd6c0) { if (f_0de800(d_1c0004) == -1 && d_1bd90c == 0) d_1bd6c0->vt->f7(d_1bd6c0); }
}
//@ f_060680
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft, sofern d_1bf1ac == 0 und ein aktives Orts-/Dungeon-Steuerobjekt d_1bd6c0 vorhanden
 *   ist, dessen virtuelle Methode vt->f5 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bd6c0 (Zeiger auf das aktive Dungeon-/Orts-Steuerobjekt).
 === Ende Beschreibung === */
void f_060680() {
  if (d_1bf1ac == 0) { if (d_1bd6c0) d_1bd6c0->vt->f5(d_1bd6c0); }
}
//@ f_0606a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt für das Bild a (Teilbild v) über d_1c2be0.f_050580 die Höhe und Breite, legt ein
 *   passendes RivaRasterImage-Objekt auf dem Heap an, entpackt die Bilddaten über d_1c2be0.f_04feb0 direkt in
 *   dessen Pixelpuffer und gibt das fertige Rasterbild zurück.
 * - Eingaben:
 *   - a (Archiv-/Bildkennung).
 *   - v (Unterbild- oder Frame-Index).
 * - Rückgabewert: RivaRasterImage * - Zeiger auf das neu erzeugte und mit den entpackten Pixeldaten gefüllte
 *   Rasterbildobjekt.
 * - Wichtige Variablen:
 *   - l1, l0 (Ermittelte Bildhöhe und Bildbreite).
 *   - im (Erzeugtes RivaRasterImage-Objekt).
 === Ende Beschreibung === */
RivaRasterImage *f_0606a0(int a, short v) {
  int l0, l1, l2; l1 = 0; l0 = 0; l2 = 0;
  d_1c2be0.f_050580(a, v, &l1, &l0);
  struct LocalImg : RivaRasterImage { LocalImg(short h, short w) : RivaRasterImage(h, w) {} static void *operator new(unsigned, void *p) { return p; } };
  void *raw = operator new(9, mark(dunghelp_file, 0x13c));
  struct Build { static RivaRasterImage *make(void *p, short h, short w) { return new (p) LocalImg(h, w); } };
  RivaRasterImage *im = Build::make(raw, (short)l1, (short)l0);
  d_1c2be0.f_04feb0(a, ((int)(((RivaRasterImage*)(im))->f_0fb0b0())), 0, (short)v, 0, &l2, &l2, 0x140);
  return im;
}
//@ f_060740
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Startet die Wiedergabe des Soundeffekts a über f_149470(a) und führt bei b == 1 zusätzlich
 *   einen System-/Grafik-Update-Schritt f_1223c0() aus.
 * - Eingaben:
 *   - a (Kennung des abzuspielenden Soundeffekts).
 *   - b (Steuerflag: 1 ruft nach dem Start f_1223c0() auf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_060740(unsigned short a, int b) {
  f_149470(a);
  if (b == 1) f_1223c0();
}
int f_060760(unsigned short a) { return f_1496d4(a); }
//@ f_060770
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Spielt den Soundeffekt p synchron unter einem Lock ab: Bereitet den Sound über f_149524(p)
 *   (und bei b == 1 über f_149b44()) vor, wartet in einer Schleife mit f_1223c0(), solange der Status
 *   f_149640(p) >= 3 ist, und schließt die Wiedergabe je nach Endstatus (1 oder 2) über f_149a14 ab.
 * - Eingaben:
 *   - p (Kennung des Soundeffekts).
 *   - b (Steuerflag: 1 ruft zusätzlich f_149b44() auf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - l (Lokales Lock-Objekt).
 *   - r (Statuscode des Soundkanals aus f_149640(p)).
 === Ende Beschreibung === */
void f_060770(unsigned short p, int b) {
  Lock l;
  f_149524(p);
  if (b == 1) f_149b44();
  int r;
  do { r = f_149640(p); f_1223c0(); } while (r >= 3);
  r = f_149640(p);
  if (r == 1) f_149a14(p, 1); else if (r == 2) f_149a14(p, 0);
}
//@ f_0607e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt auf der Automap (d_1c2a84) für die um 8000 verschobene Kennung a - 8000 den
 *   Markierungs- oder Sichtbarkeitswert b über f_019c90.
 * - Eingaben:
 *   - a (Automap-Markierungskennung ab Basis 8000).
 *   - b (Zu setzender Zustandswert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0607e0(int a, signed char b) {
  d_1c2a84.f_019c90((short)(a - 8000), b);
}
//@ f_060800
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt und spielt eine komplette animierte Zwischensequenz (bestehend aus den zwei
 *   aufeinanderfolgenden Archivressourcen a und a + 1 in d_1c2098) ab: Lädt die Steuerdaten nach d_1c0afc (0x13c
 *   Bytes) und d_1c0af8 (0x2710 Bytes), startet die Sequenz über f_154e78/f_154f08 und führt anschließend die
 *   Hauptschleife (f_1216f0, f_149d20, f_146dfa, optionaler Callback c()) aus, solange d_1c0b1c == 1 ist.
 * - Eingaben:
 *   - a (Archivkennung der ersten Ressource der Sequenz; a + 1 ist die zugehörige zweite Ressource).
 *   - b (Optionsflags: Bit 0 schaltet Bit 0x40 in d_1a9a1c ein oder aus).
 *   - c (Optionaler Funktionszeiger auf eine pro Frame aufzurufende Rückruffunktion oder 0).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0afc, d_1c0af8 (Puffer für Header-/Steuerdaten und Animationsskript der Sequenz).
 *   - sv (Gesicherter Wert von d_1a9a1c).
 *   - d_1c0b1c (Schleifenflag für die aktive Wiedergabe der Sequenz).
 === Ende Beschreibung === */
void f_060800(unsigned long a, short b, void (*c)()) {
  long r = -1;
  memset(d_1c0afc, 0, 0x13c);
  memset(d_1c0af8, 0, 0x2710);
  if (a & 0xffff0000) {
    if (d_1c2098.f_144870(a)) {
      unsigned long a2 = a + 1;
      if (d_1c2098.f_144870(a2) && d_1c2098.f_1448d0(a, d_1c0afc) && d_1c2098.f_1448d0(a2, d_1c0af8)) r = d_1c2098.f_144a30(a2);
    }
  }
  if (r != -1) {
    int sv = d_1a9a1c;
    if (b & 1) d_1a9a1c = sv | 0x40; else d_1a9a1c = sv & ~0x40;
    d_1a8956 = (short)r;
    f_154e78(d_1c0afc);
    int q;
    do { q = f_154f08(1, 200); f_149d20(); f_1223c0(); f_146dfa(&d_1c2edc, 1); } while (q == 1);
    d_1a8958 = 0x64;
    d_1c0b99 = f_0de8a0(d_1c0004) >> 16;
    *(volatile int*)&d_1c0b1c = 1;
    int sb = d_1c0b40;
    f_120bd0();
    G *g = d_1c0004;
    d_1c0b40 = sb;
    f_0ddfc0(g);
    for (; (d_1c0b1c == 1); ) { f_1216f0(); f_149d20(); f_146dfa(&d_1c2edc, 1); if (c) c(); }
    f_149d20();
    d_1a9a1c = sv;
  }
}
//@ f_060990
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Blendet die Bildschirmhelligkeit bzw. Palette in n Schritten mit der Schrittweite -s
 *   schrittweise über f_155bc8(x * d_1a80c8) und f_1223c0() ab.
 * - Eingaben:
 *   - n (Anzahl der Blendenschritte).
 *   - s (Schrittweite pro Durchlauf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - x (Kumulierte Helligkeitsänderung).
 === Ende Beschreibung === */
void f_060990(int n, int s) {
  short i; short x = 0; i = 0;
  if ((short)n > (short)0) do { x = x - s; i++; f_155bc8(x * d_1a80c8); f_1223c0(); } while (i < (short)n);
}
//@ f_0609d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Blendet die Bildschirmhelligkeit bzw. Palette in n Schritten mit der Schrittweite +s
 *   schrittweise über f_155bc8(x * d_1a80c8) und f_1223c0() auf.
 * - Eingaben:
 *   - n (Anzahl der Blendenschritte).
 *   - s (Schrittweite pro Durchlauf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - x (Kumulierte Helligkeitsänderung).
 === Ende Beschreibung === */
void f_0609d0(int n, int s) {
  short i; short x = 0; i = 0;
  if ((short)n > (short)0) do { x = x + s; i++; f_155bc8(x * d_1a80c8); f_1223c0(); } while (i < (short)n);
}
//@ f_060a10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Stellt sicher, dass mindestens n Bytes freier Heap-Speicher (f_014a60()) verfügbar sind:
 *   Reicht der freie Speicher nicht aus, werden stufenweise gecachte Ressourcen über f_13fd60(&d_1c14c4),
 *   f_11f5f0(), f_1566b8(n - t) und zuletzt f_15674c() freigegeben.
 * - Eingaben:
 *   - n (Benötigte Mindestmenge an freiem Speicher in Bytes).
 * - Rückgabewert: int - 1, wenn nach der Bereinigung mindestens n Bytes verfügbar sind, sonst 0.
 * - Wichtige Variablen:
 *   - t (Nach der ersten Bereinigungsstufe verfügbarer freier Speicher).
 === Ende Beschreibung === */
int f_060a10(int n) {
  int r = 1;
  if (f_014a60() < n) {
    f_13fd60(&d_1c14c4);
    int t = f_014a60();
    if (t < n) {
      f_11f5f0(); f_1566b8(n - t); d_1c0b98 = 1;
      if (f_014a60() < n) { f_15674c(); if (f_014a60() < n) r = 0; }
    }
  }
  return r;
}
void f_060a70(int a, int b, int c) { f_122190(a, b, c); }
int f_060a80(short a) { return f_149360(a, d_1a199c) != -1; }
