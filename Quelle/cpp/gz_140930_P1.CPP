/* === Beschreibung (Katalog) ===
 * Einheit gz_140930 (0x140930 - 0x140B40)
 *
 * Überblick
 *
 * Die Einheit gz_140930 bildet das Bindeglied zwischen der vertikalen Bildlaufleiste (vslider) und dem
 * erweiterten Multiple-Choice-Dialogsystem (xdialog.cpp). Sie enthält eine letzte Hilfsmethode zur Neuberechnung
 * der Schiebereglerposition (f_140930) sowie die ersten fünf Hilfsfunktionen des xdialog-Systems: den
 * Maus-Hover-/Klick-Callback für Dialogschaltflächen (f_140980), die Textformatierung und Farbauswahl für
 * Sprecherzeilen (f_1409c0), die Zuordnung einer sichtbaren Menüzeile zum internen Themenindex (f_140aa0), den
 * Zugriff auf den Ungeduldszähler des Gesprächspartners (f_140b00) und die Suche nach einem bestimmten
 * Gesprächsthema in der Dialogtabelle (f_140b10).
 === Ende Beschreibung === */
// P3 3/6 gleich (suche.py 24.10.2026, Basis gz_140930_P1.CPP)
// gz_140930.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x140930-0x140B40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



int f_0d3810();
int f_0d3780();
int f_0d3800();
int f_05e320(void *p, int a, int b);
int f_0bd350(int a, int b, int c);
extern short d_1c1164;
extern short d_1c1166;
extern const char d_1b8708[];
extern int d_1c38b0;
struct S { short x, y, h, a, b, p, t, w, m; int g0, g1, g2, g3; };
//@ f_140930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für eine vertikale Bildlaufleiste s aus der Gesamthöhe s->h, der Reglerhöhe s->t und
 *   dem aktuellen Prozentwert s->b die vertikale Pixelposition s->p neu und begrenzt sie über f_0bd350 auf das
 *   gültige Intervall [0, s->h - s->t].
 * - Eingaben: Zeiger s auf die Bildlaufleiste (S).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s->p: Neu berechneter vertikaler Pixelabstand des Reglers.
 === Ende Beschreibung === */
void f_140930(S *s)
{
  s->p = (s->h - s->t) * s->b / 100;
  s->p = f_0bd350(s->p, 0, s->h - s->t);
}
//@ f_140980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Maus-Rückruffunktion (Callback in d_1bf524) während eines aktiven xdialog-Gesprächs: Befindet
 *   sich der Mauszeiger über einem gültigen Schaltflächen-Rechteck mit der Kennung p1 != 0, unterscheidet sich
 *   p1 von der aktuell hervorgehobenen Auswahl d_1c1164 und ist eine Maustaste bzw. Mausbewegung aktiv
 *   (f_0d3810, f_0d3780 oder f_0d3800), wird d_1c1166 = p1 gesetzt, damit die Dialogschleife (f_142d20) die
 *   optische Hervorhebung aktualisiert.
 * - Eingaben: Schaltflächen-Kennung p1 (short, z. B. 144-146 für Antwortoptionen im Textfenster oder 148-163 für
 *   Themen in der rechten Auswahlspalte).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c1164, d_1c1166: Zuletzt gezeichnete und neu angeforderte Hervorhebungskennung im Dialogfenster.
 === Ende Beschreibung === */
void f_140980(short p1)
{
  if (p1 && (int)p1 != (int)*(volatile short *)&d_1c1164 && (f_0d3810() || f_0d3780() || f_0d3800())) d_1c1166 = p1; // volatile verhindert Verengung auf 16-Bit-cmp statt movsx+32-Bit-cmp
}
//@ f_1409c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert eine Gesprächszeile s in den Ausgabepuffer *(char )(x + 0xAF) des Dialogobjekts x
 *   und stellt die passende Textfarbe am globalen Textrenderer d_1c38b0 ein. Bei Sprechermodus 1 (NSC-Aussage,
 *   Farbe 0xF9) oder 2 (Held-Aussage, Farbe 0xFF) wird die Zeile in spitze Klammern <...> (Anführungszeichen im
 *   Spielzeichensatz, d_1b8708 = ">") eingeschlossen; bei Modus 3 (Erzähler-/Beschreibungstext) wird sie ohne
 *   Klammern in Farbe 0xF0 ausgegeben.
 * - Eingaben: Zeiger x auf das Dialogobjekt, Quellstring s (char *) und Darstellungsmodus mode (short, 1-3).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d: Schreibzeiger in den Textpuffer *(char )(x + 0xAF).
 === Ende Beschreibung === */
void f_1409c0(char *x, char *s, short mode)
{
  char *d = *(char **)(x + 0xaf);
  if (mode == 1 || mode == 2) {
    *d = '<';
    d++;
  }
  strcpy(d, s);
  if (mode == 1 || mode == 2) strcat(*(char **)(x + 0xaf), d_1b8708);
  switch ((unsigned short)mode) {
  case 1: f_05e320(&d_1c38b0, 0xf9, -1); break;
  case 2: f_05e320(&d_1c38b0, 0xff, -1); break;
  case 3: f_05e320(&d_1c38b0, 0xf0, -1); break;
  }
}
//@ f_140aa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt die p2-te sichtbare Themenzeile (1-basiert) in der rechten Themenliste des
 *   Dialogfensters in den zugehörigen internen Themenindex b. Durchläuft dazu das Sichtbarkeitsarray *(char )(x
 *   + 0x61) (in dem ausgeblendete Themen den Wert 0xFF tragen) und zählt die freigeschalteten Einträge, bis der
 *   p2-te sichtbare Eintrag erreicht ist.
 * - Eingaben: Zeiger x auf das Dialogobjekt und 1-basierte Zeilennummer p2 (short).
 * - Rückgabewert: Der 0-basierte interne Themenindex b (short) oder -1, wenn weniger als p2 Themen sichtbar
 *   sind.
 * - Wichtige Variablen:
 *   - b: Laufindex über alle Themen (0 bis *(unsigned char *)(x + 0x1A) - 2).
 *   - c: Zähler der bisher angetroffenen sichtbaren Themen (!= 0xFF).
 === Ende Beschreibung === */
short f_140aa0(char *x, short p2)
{
  short r = -1;
  unsigned char b = 0;
  short c = 0;
  if (p2 > 0) {
    while (r == (short)-1 && (int)b < (int)(*(unsigned char *)(x + 0x1a) - 1)) {
      if ((*(char **)(x + 0x61))[b] != (char)0xff) c++;
      if (c == p2) r = b;
      b++;
    }
  }
  return r;
}
//@ f_140b00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Speicheradresse des 16-Bit-Zählers für den aktuellen Gesprächspartner (*(int *)(x
 *   + 0x21) + *(short *)(x + 0x1F) * 2), in dem gezählt wird, wie oft der Spieler diesen NSC bereits nach
 *   unbekannten Themen gefragt hat (Ungeduldszähler).
 * - Eingaben: Zeiger x auf das Dialogobjekt.
 * - Rückgabewert: Adresse des 16-Bit-Zählers (short * als int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_140b00(char *x)
{
  return *(int *)(x + 0x21) + *(short *)(x + 0x1f) * 2;
}
//@ f_140b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die aus 6-Byte-Einträgen bestehende Themen-Zuordnungstabelle *(short )(x + 0x3D)
 *   des Dialogs nach dem Eintrag für das Thema p2 + 1 und rückt anschließend über eventuelle
 *   Platzhalter-Einträge mit Offset -1 (*(int *)(p + 1) == -1) bis zum ersten gültigen Skriptverweis vor.
 * - Eingaben: Zeiger x auf das Dialogobjekt und 0-basierter Themenindex p2 (short).
 * - Rückgabewert: Zeiger p (short * in EAX) auf den gefundenen 6-Byte-Tabelleneintrag in *(short )(x + 0x3D).
 * - Wichtige Variablen:
 *   - p: Laufzeiger in 6-Byte-Schritten (p += 3 bei short *) durch die Themen-Zuordnungstabelle.
 === Ende Beschreibung === */
void f_140b10(char *x, short p2)
{
    int t70_9;
    int t71_9;
  ++p2;
  short *p = *(short **)(x + 0x3d);
  while ((t70_9 = *p) != (short)0 && p2 != *p) p += 3;
  while ((t71_9 = *p) != (short)0 && *(int *)(p + 1) == -1) p += 3;
}
