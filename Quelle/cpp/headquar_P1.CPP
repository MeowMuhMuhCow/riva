/* === Beschreibung (Katalog) ===
 * Einheit headquar (09b0f0-09b900)
 *
 * Überblick
 * Diese Einheit implementiert das Versteck bzw. Hauptquartier der Widerstandsgruppe (Gilde / Untergrund in
 * Riva). Dort kann die Gruppe rasten, das Tagebuch einsehen, die Truhe im Versteck nutzen und zwei zentrale
 * Handlungssequenzen mit Tarik/Mandara (die Untersuchung und Heilung der vergifteten/besessenen Gruppe sowie die
 * Übergabe und Vernichtung verdächtiger Gegenstände gegen Abenteuerpunkte) auslösen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 11/12 gleich (suche.py 25.10.2026, Basis headquar_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 4 gleich (vorher 4), Rest 329 (vorher 334)
// headquar.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x09B0F0-0x09B900
#include <string.h>
#define C64 ((int)&d_1c2c64)
struct SO { int a; int *p; char c[52]; };
struct T14 { char b[0x14]; };
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
unsigned short f_09b570(int p1);
int f_09b750(void);
void f_09b8c0(int p1);
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_02dee0(int p1);                                   // reg eax stapel 0
int f_035180(int p1, int p2);                           // reg eax edx stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
short f_03aa20(int p1, int p2, int p3, int);           // reg eax edx ebx ecx stapel 0
                           // reg eax edx stapel 0
int f_044220(int p1, int p2);                           // reg eax edx stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0b9060(int p1);                                   // reg eax stapel 0
int f_0b90a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfa20(int, ...);                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d64a0();                       // nicht in clobber.tsv
int f_0daa90(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
short f_0db940(int p1);                                   // reg eax stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dbda0(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0f2720(int p1, int p2, int p3, int p4);                       // nicht in clobber.tsv
                           // reg eax stapel 0
int f_10a2e0(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_10a6d0();                                         // reg - stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_113d40(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
short f_149360(int p1, int p2);                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern char d_1a350c;                    // 0x1A350C
extern int d_1bc760;                    // 0x1BC760
extern signed char d_1bdcf4;                    // 0x1BDCF4
extern signed char d_1bdcfc;                    // 0x1BDCFC
extern signed char d_1bdd00;                    // 0x1BDD00
extern signed char d_1bdd04;                    // 0x1BDD04
extern signed char d_1bdd08;                    // 0x1BDD08
extern volatile signed char d_1bed54;                    // 0x1BED54 - haelt den Speicherzugriff wie im Original
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0028;                    // 0x1C0028
extern int d_1c01ec;                    // 0x1C01EC
extern signed char d_1c01f4;                    // 0x1C01F4
extern signed char d_1c0960;                    // 0x1C0960
extern volatile short d_1c2198;                    // 0x1C2198 - haelt den Speicherzugriff wie im Original
extern volatile short d_1c219a;                    // 0x1C219A - haelt den Speicherzugriff wie im Original
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1c349c[];                    // 0x1C349C
extern const char d_1c3870[];
extern const char d_1c3498[];                    // 0x1C3870
extern const char d_1a34ec[];           // Text 0x1A34EC
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_09b0f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert als zentrale Ereignismethode des Hauptquartiers sämtliche Raumaktionen wie das
 *   Betreten (0x81), das Öffnen der Vorratstruhe (0x9d), das Rasten (0x9b), den Blick ins Tagebuch (0x8c) sowie
 *   die beiden Story-Begegnungen (0x9e über f_09b570 und 0x9f über f_09b750).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den Ereigniscode p2 und gibt den
 *   Rückgabewert der jeweiligen Aktion (0 oder 1) zurück (int).
 * - Wichtige Variablen: Die globale Zustandsvariable d_1bdcf4 entscheidet beim Ereignis 0x81, ob die
 *   Standard-Raumbeschreibung (f_0b9060) oder der spezielle Hinweis 0x25000078 angezeigt wird.
 === Ende Beschreibung === */
int f_09b0f0(int p1, int p2)
{
  int result = 0;
  int object;
  int original;
  struct T14 *q;
  switch ((unsigned short)p2) {
    case 0: break;
    case 0x81:
      original = p1;
      p1 = d_1bdcf4 > 1;
      if (!p1)
        f_0b9060(original);
      else
        f_0bf730(C64, 0x25000078);
      break;

    case 0x9d:
      f_01cef0(d_1bc760);
      d_1c2a80 = 0;
      q = new (mark(d_1a34ec, 0xde)) T14;
      q = q ? (struct T14 *)f_112df0((int)q, 0x25, 0, 0) : q;
      f_112ec0((int)q);
      do { if (q) delete (char *)f_112e70((int)q, 0); } while (0);
      d_1c2198 = 1;
      break;

    case 0x9b:
      f_0dbda0(d_1c0004);
      f_0bf730(C64, 0x25000077);
      f_10a2e0(p1, 4, 10, 1, 5);
      break;

    case 0x8c:
      object = f_038d70(d_1c0004, 0x200001bf);
      if (object) {
        do {
        if ((int)f_03aa20(object, 0, 3, -1) != -3) {
          d_1c2198 = 0;
          d_1c219a = 1;
          f_125ed0((int)&d_1c2c44, 0x1e);
        }
        } while (0);
      }
      break;

    case 0x8d:
      ((int (*)(int))f_10a6d0)(p1);
      break;

    case 0x9e:
      result = ((int (*)(int))f_09b570)(p1);
      break;

    case 0x9f:
      result = ((int (*)(int))f_09b750)(p1);
      break;

    case 0x80:
      result = 1;
      break;
  }
  return result;
}
//@ f_09b2e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert beim ersten Aufruf die Raumdaten des Hauptquartiers über f_02dee0 und schaltet
 *   anschließend abhängig vom aktuellen Questfortschritt (d_1bdcfc, d_1bdd00, d_1bdd04, d_1bdd08, d_1c0960,
 *   d_1c01f4) die Aktionsschaltflächen 1, 0x1e und 0x1f im Raum-Menü d_1bfdb8 frei oder sperrt sie.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0daaf0 werden Menüoptionen im Menüobjekt d_1bfdb8 aktiviert und über f_0daa90
 *   ausgeblendet.
 === Ende Beschreibung === */
void f_09b2e0(int p1)
{
  if (*(int *)(p1 + 0x60) == 0) {
    f_02dee0(p1);
    *(int *)(p1 + 0x60) = 1;
  }
  if ((((d_1bdd00 > 1) ? 1 : 0) && EQ(d_1bdd08, 0)) || (((d_1bdcfc > 1) ? 1 : 0) && EQ(d_1bdd04, 0))) {
    f_0daa90(d_1bfdb8, 1);
  } else {
    f_0daaf0(d_1bfdb8, 1);
  }
  if (EQ(d_1bdd04, 1) && EQ(d_1c0960, 0)) {
    f_0daaf0(d_1bfdb8, 0x1e);
  } else {
    f_0daa90(d_1bfdb8, 0x1e);
  }
  if (EQ(d_1c01f4, 1)) {
    f_0daaf0(d_1bfdb8, 0x1f);
    return;
  }
  f_0daa90(d_1bfdb8, 0x1f);
}
//@ f_09b3e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt beim Verlassen des Hauptquartiers das globale Statusflag d_1bed54 und das Besuchsflag an
 *   Offset 0x60 des Gebäudeobjekts auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(p1 + 0x60) markiert den Initialisierungszustand des Raumes.
 === Ende Beschreibung === */
void f_09b3e0(int p1)
{
  d_1bed54 = 0;
  *(int *)(p1 + 0x60) = 0;
}
//@ f_09b400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Betreten oder Untersuchen des Hauptquartiers die normale Ortsbeschreibung (f_0b9060)
 *   aus, sofern d_1bdcf4 <= 1 ist, oder zeigt andernfalls die Textmeldung 0x25000078 an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Questvariable d_1bdcf4 steuert die Textauswahl.
 === Ende Beschreibung === */
void f_09b400(int p1)
{
  if (!((d_1bdcf4 > 1) ? 1 : 0)) {
    f_0b9060(p1);
    return;
  }
  f_0bf730(C64, 0x25000078);
}
//@ f_09b430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet die Lagertruhe (T14 mit Kennung 0x25) im Hauptquartier, in der die Gruppe Gegenstände
 *   zwischenlagern kann, und markiert nach dem Schließen den Bildschirm über d_1c2198 = 1 zur Neuzeichnung.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das temporär erzeugte T14-Truhenobjekt q wird über f_112df0 initialisiert und über
 *   f_112ec0 interaktiv bedient.
 === Ende Beschreibung === */
void f_09b430(void)
{
  struct T14 *q;
  f_01cef0(d_1bc760);
  d_1c2a80 = 0;
  q = new (mark(d_1a34ec, 0xde)) T14;
  q = q ? (struct T14 *)f_112df0((int)q, 0x25, 0, 0) : q;
  f_112ec0((int)q);
  if (q) delete (char *)f_112e70((int)q, 0);
  d_1c2198 = 1;
}
//@ f_09b4a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der Gruppe (d_1c0004) nach einem Helden, der das Tagebuch oder Dokument 0x200001bf
 *   lesen bzw. vorlesen kann (f_038d70), öffnet die zugehörige Ansicht über f_03aa20 und lässt bei Erfolg 30
 *   Spielminuten (0x1e) vergehen.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globalen Flags d_1c2198 und d_1c219a steuern die Aktualisierung der Oberfläche nach
 *   dem Lesen.
 === Ende Beschreibung === */
void f_09b4a0(void)
{
  int sVar1;
  int p1;
  p1 = f_038d70(d_1c0004, 0x200001bf);
  if (p1 != (short)0) {
    sVar1 = f_03aa20(p1, 0, 3, -1);
    if (sVar1 != (short)-3) {
      d_1c2198 = 0;
      d_1c219a = 1;
      f_125ed0((int)&d_1c2c44, 0x1e);
    }
  }
}
//@ f_09b500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine Rast der Gruppe im Hauptquartier durch, indem f_0dbda0 aufgerufen, der Rasttext
 *   0x25000077 ausgegeben und die Regenerationsroutine f_10a2e0 mit den Parametern (4, 10, 1, 5) gestartet wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Gruppenzeiger d_1c0004 verweist auf die aktive Heldengruppe.
 === Ende Beschreibung === */
void f_09b500(int p1)
{
  f_0dbda0(d_1c0004);
  f_0bf730(C64, 0x25000077);
  f_10a2e0(p1, 4, 10, 1, 5);
}
//@ f_09b540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird als Rückruffunktion für jedes Gruppenmitglied aufgerufen, setzt bei dem Helden p1 das
 *   Statusbit 0x48 über f_044220 und führt bei Bedarf (f_0d4a60) die Heilungs- oder Bereinigungsfunktion
 *   f_113d40 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion arbeitet direkt auf der übergebenen Heldenstruktur p1.
 === Ende Beschreibung === */
void f_09b540(int p1)
{
  int iVar1;
  f_044220(p1, 0x48);
  iVar1 = f_0d4a60(p1);
  if (iVar1 != 0) {
    f_113d40(p1);
  }
}
//@ f_09b570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die erste große Handlungssequenz im Hauptquartier aus (sofern d_1c0028 <= 1), bei der
 *   ein NSC-Gespräch mit Porträt 0x250001 abläuft, eine Übergabetruhe (T14 mit Kennung 0x46 und zweimal 0x198
 *   Gegenständen pro Held) geöffnet wird, alle Gruppenmitglieder über f_09b540 behandelt werden und die Gruppe
 *   5.000 Abenteuerpunkte (f_0dd7f0(..., 7, 5000)) erhält.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt 1 zurück, wenn die Szene
 *   durchgeführt wurde, oder 0, wenn sie wegen d_1c0028 > 1 abgelehnt wurde (unsigned short).
 * - Wichtige Variablen: Das Flag d_1c01ec wird nach Abschluss der Szene auf 1 gesetzt, und p hält das geladene
 *   NSC-Porträt 0x250001.
 === Ende Beschreibung === */
unsigned short f_09b570(int p1)
{
  short sVar1, v;
  int ret, p, sp;
  struct SO o;
  struct T14 *q;
  signed char b = *(signed char *)&d_1c0028;
  ret = 1;
  sp = p1;
  if (b > ret) {
    f_0bf730(C64, 0x220101bf);
    ret = 0;
  } else {
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    v = f_0de7f0(d_1c0004);
    p = f_0606a0(0x250001, 4);
    q = new (mark(d_1a34ec, 0x13a)) T14;
    q = q ? (struct T14 *)f_112df0((int)q, 0x46, 0, 1) : q;
    f_113640((int)q);
    { int t_ = (int)(d_1c0004); sVar1 = f_0db940(t_); }
    f_113340((int)q, 0x198, (short)(sVar1 * 2), 0);
    o.p[1] = f_038c40(d_1c0004);
    f_0bf730(C64, 0x25000079);
    f_0bfa20(C64, p, 0, 0x2500007a, 0);
    f_0bf730(C64, 0x2500007b);
    f_112ec0((int)q);
    f_0b90a0(p1, 1);
    f_0bf730(C64, 0x2500007c);
    f_039a80(d_1c0004, (int)f_09b540);
    f_0bf730(C64, 0x2500007d);
    if (1 < v) {
      f_0bf730(C64, 0x2500007e);
    }
    f_0bf730(C64, 0x2500007f);
    if (q) delete (char *)f_112e70((int)q, 0);
    *(signed char *)&d_1c01ec = 1;
    if (p) delete (char *)((int)(((RivaRasterImage*)(p))->f_0fad20( 0)));
    f_0d64a0();
    f_0dd7f0(d_1c0004, 7, 5000);
    f_1254a0(&o, 0);
  }
  return ret;
}
//@ f_09b750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die zweite große Handlungssequenz im Hauptquartier aus (sofern d_1c0028 <= 1), zeigt den
 *   Dialog mit dem Porträt 0x250001 (0x25000087 bis 0x2500008d), entfernt über f_09b8c0 alle nicht in der
 *   Ausnahmeliste d_1a350c erlaubten Gegenstände aus den Heldeninventaren, setzt das Questflag 0x176 und vergibt
 *   5.020 (0x139c) Abenteuerpunkte.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt 1 bei Erfolg oder 0 bei Ablehnung
 *   zurück (int).
 * - Wichtige Variablen: Die Tabelle d_1a350c definiert die Gegenstands-IDs, die die Helden bei dieser
 *   Bereinigung behalten dürfen.
 === Ende Beschreibung === */
int f_039a80(int p1, int p2, int p3);
int f_0dcf00(int p1, int p2);
int f_0f2720(int p1);
int f_0bfa20(int, ...);
int f_09b750(void)
{
  signed char condition = *(signed char *)&d_1c0028;
  int r = 0;
  SO o;
  if (condition > 1) {
    f_0bf730(C64, 0x25000086);
  } else {
    int h;
    int q;
    int c;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    h = f_0606a0(0x250001, 4);
    q = h;
    o.p[1] = f_038c40(d_1c0004);
    f_0bf730(C64, 0x25000087);
    f_0bfa20(C64, h, 0, 0x25000088, 0);
    f_0bf730(C64, 0x25000089);
    f_0bfa20(C64, h, 0, 0x2500008a, 0);
    if (f_0db9a0(d_1c0004) > 1) {
      f_0bf730(C64, 0x2500008b);
    } else {
      f_0bf730(C64, 0x2500008c);
    }
    f_0bf730(C64, 0x2500008d);
    if (q != 0) {
      void *t = (void *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0)));
      operator delete(t);
    }
    f_0d64a0();
    f_0f2720(3);
    c = d_1c0004;
    ((int (*)(int,int))f_039a80)(c, (int)f_09b8c0);
    ((int (*)(int,int,int))f_0dcf00)(c, 0x176, 1);
    f_0dd7f0(d_1c0004, 0xa, 0x139c);
    r = 1;
    f_1254a0(&o, 0);
  }
  return r;
}
//@ f_09b8b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt als virtuelle Abfragefunktion des Hauptquartiers konstant -1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt -1 zurück (int).
 * - Wichtige Variablen: Die Funktion verwendet keine Variablen.
 === Ende Beschreibung === */
int f_09b8b0(void)
{
  return -1;
}
//@ f_09b8c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft alle 31 Inventarplätze (0 bis 0x1e) des Helden p1 und löscht über f_035180 jeden
 *   Gegenstand, dessen ID nicht in der Positivliste d_1a350c (f_149360) enthalten ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Schleifenvariable i prüft sämtliche Ausrüstungs- und Rucksackplätze (0..30) des
 *   Helden.
 === Ende Beschreibung === */
void f_09b8c0(int p1)
{
  short sVar1;
  short i;
  int p2;
  for (i = 0; i < 0x1f; i = i + 1) {
    p2 = i;
    sVar1 = f_042a60((struct hero *)(p1), p2);
    sVar1 = f_149360(sVar1, (int)&d_1a350c);
    if (sVar1 == -1) {
      f_035180(p1, p2);
    }
  }
}
