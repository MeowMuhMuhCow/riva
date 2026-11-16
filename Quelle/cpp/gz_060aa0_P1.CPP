/* === Beschreibung (Katalog) ===
 * Einheit gz_060aa0 (0x060aa0 - 0x061080)
 *
 * Überblick
 * Diese Einheit enthält die Haupt-Eingabeschleife des mehrzeiligen Texteditors (f_060ae0), der im Spiel für
 * Automap-Notizen (amap_t345), eigene Tagebucheinträge (diary) und Spielstandbeschreibungen (diskmenu_t1)
 * verwendet wird, sowie drei zugehörige Hilfsfunktionen für Tastaturabfrage, Wortumbruch-Verschiebung und
 * Textbreitenmessung.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 3/4 gleich (suche.py 25.10.2026, Basis gz_060aa0_P1.CPP)
// gz_060aa0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x060AA0-0x061080
#include <string.h>
#pragma intrinsic(strlen, strcpy)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
unsigned short f_045db0(void *p1, int p2);                           // reg eax edx stapel 0
int f_045df0(void *p1, int p2);                           // reg eax edx stapel 0
int f_05e2a0(void *p1, short *p2, short *p3, short *p4, short *p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(void *p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e840(void *p1, int p2);                           // reg eax edx stapel 0
int f_05e850(void *p1);                                   // reg eax stapel 0
int f_05ebd0(void *p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_061350(short *p1);                                   // reg eax stapel 0
int f_0614d0(short *p1);                                   // reg eax stapel 0
int f_061590(short *p1);                                   // reg eax stapel 0
int f_0616f0(short *p1);                                   // reg eax stapel 0
int f_0617f0(short *p1);                                   // reg eax stapel 0
int f_061d20(short *p1);                                   // reg eax stapel 0
int f_061e60(short *p1, int p2);                           // reg eax edx stapel 0
int f_061ee0(short *p1);                                   // reg eax stapel 0
int f_062000(short *p1);                                   // reg eax stapel 0
int f_062120(short *p1);                                   // reg eax stapel 0
int f_0621b0(short *p1);                                   // reg eax stapel 0
int f_0622e0(short *p1);                                   // reg eax stapel 0
int f_062390(short *p1);                                   // reg eax stapel 0
int f_0624b0(short *p1);                                   // reg eax stapel 0
int f_0625e0(short *p1);                                   // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_099f70(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_099fa0(void *p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3390(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0dacc0(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
int f_1483f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1bd75c;                    // 0x1BD75C
extern short d_1bd766;                    // 0x1BD766
extern unsigned short d_1bdbd4;                    // 0x1BDBD4
extern unsigned short d_1bdbd6;                    // 0x1BDBD6
extern unsigned short d_1bdbd8;                    // 0x1BDBD8
extern unsigned short d_1bdbda;                    // 0x1BDBDA
extern int d_1bf510;                    // 0x1BF510
extern volatile int d_1bf514;           // 0x1BF514 (haelt die Store-Reihenfolge in f_060ae0)
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c3078;                    // 0x1C3078
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (4), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_060aa0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen einzelnen Eingabeschritt für den Texteditor aus: fragt Tastatur und Maus über
 *   f_068f40() ab, übernimmt bei aktiver Schaltflächenleiste (d_1bfdb8 != 0) deren Aktionscode (f_0dacc0) nach
 *   d_1bd766 und wandelt ein eingegebenes doppeltes Anführungszeichen '"' (0x22) in das Zeichen '>' (0x3e) um.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt das gelesene ASCII-Zeichen nach d_1bd75c und den Tasten- bzw. Aktionscode nach
 *   d_1bd766.
 === Ende Beschreibung === */
//@ f_060ae0  groesse 1264 B, 394 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die interaktive Bearbeitung eines mehrzeiligen Textes im Editor-Objekt p1: setzt den
 *   Cursor nach links oben, zeichnet das gesamte Textfeld (f_061350) und verarbeitet in einer Endlosschleife
 *   druckbare Zeichen (f_061e60), Rückschritt (f_061d20), Entf (f_061ee0), Pfeiltasten, Pos1/Ende sowie die
 *   Eingabetaste (f_0617f0), bis der Spieler mit Esc, Rechtsklick, Bild-auf, den Aktionscodes 0x80/0x86 oder
 *   einem Linksklick außerhalb des Editorfelds beendet. Beim Verlassen werden sämtliche Zeilen als
 *   hintereinanderliegende nullterminierte Strings in den Ausgabepuffer p2 kopiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt, den Zielpuffer p2 für den
 *   fertig bearbeiteten Text und eine optionale Mausbereichstabelle p3 für die Dauer der Bearbeitung. Sie gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Ein Originalfehler liegt in der Klick-außerhalb-Prüfung (f_0d3390): als rechte Grenze
 *   wird p1[3] + p1[2] (x0 + bsz, wobei bsz = 4 * w die Zeilenpuffergröße in Bytes ist) statt p1[3] + p1[1] (x0
 *   + w) übergeben, sodass Klicks rechts neben dem Editorfeld noch als innerhalb gelten.
 === Ende Beschreibung === */
//@ f_060fd0  groesse 128 B, 57 Bef, reg edx ebx ecx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schiebt für den automatischen Wortumbruch (f_061080) und das Teilen einer Zeile (f_0617f0) den
 *   bisherigen Inhalt der Zielzeile p2 per memmove (f_14d075) nach rechts und fügt den Überhangtext p3 (ohne
 *   führendes Leerzeichen) am Zeilenanfang ein, bei p4 != 0 getrennt durch ein Leerzeichen.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Editorzeiger p1, den Zeiger p2 auf den Puffer
 *   der Zielzeile, den einzufügenden Text p3 und den Trennschalter p4 (1 = Leerzeichen zwischen p3 und altem
 *   Zeileninhalt einfügen). Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokale Variable sVar5 speichert die Länge strlen(p3) des einzufügenden Textstücks.
 === Ende Beschreibung === */
//@ f_061050  groesse 48 B, 24 Bef, reg edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die gesamte Pixelbreite eines nullterminierten Strings p2 in der Editor-Schrift
 *   d_1c3078 als Summe der Einzelzeichenbreiten (f_045db0).
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Editorzeiger p1 und den String p2 und gibt die
 *   berechnete Breite in Pixeln als int zurück.
 * - Wichtige Variablen: Fragt für jedes Zeichen von p2 die Breite über f_045db0(&d_1c3078, *p2) ab.
 === Ende Beschreibung === */

//@ f_060aa0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen einzelnen Eingabeschritt für den Texteditor aus: fragt Tastatur und Maus über
 *   f_068f40() ab, übernimmt bei aktiver Schaltflächenleiste (d_1bfdb8 != 0) deren Aktionscode (f_0dacc0) nach
 *   d_1bd766 und wandelt ein eingegebenes doppeltes Anführungszeichen '"' (0x22) in das Zeichen '>' (0x3e) um.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt das gelesene ASCII-Zeichen nach d_1bd75c und den Tasten- bzw. Aktionscode nach
 *   d_1bd766.
 === Ende Beschreibung === */
void f_060aa0(void)
{
  f_068f40();
  if (d_1bfdb8 != (short)0) {
    d_1bd766 = f_0dacc0(d_1bfdb8);
  }
  if (d_1bd75c == 0x22) {
    d_1bd75c = 0x3e;
  }
}

//@ f_060ae0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die interaktive Bearbeitung eines mehrzeiligen Textes im Editor-Objekt p1: setzt den
 *   Cursor nach links oben, zeichnet das gesamte Textfeld (f_061350) und verarbeitet in einer Endlosschleife
 *   druckbare Zeichen (f_061e60), Rückschritt (f_061d20), Entf (f_061ee0), Pfeiltasten, Pos1/Ende sowie die
 *   Eingabetaste (f_0617f0), bis der Spieler mit Esc, Rechtsklick, Bild-auf, den Aktionscodes 0x80/0x86 oder
 *   einem Linksklick außerhalb des Editorfelds beendet. Beim Verlassen werden sämtliche Zeilen als
 *   hintereinanderliegende nullterminierte Strings in den Ausgabepuffer p2 kopiert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Editor-Objekt, den Zielpuffer p2 für den
 *   fertig bearbeiteten Text und eine optionale Mausbereichstabelle p3 für die Dauer der Bearbeitung. Sie gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Ein Originalfehler liegt in der Klick-außerhalb-Prüfung (f_0d3390): als rechte Grenze
 *   wird p1[3] + p1[2] (x0 + bsz, wobei bsz = 4 * w die Zeilenpuffergröße in Bytes ist) statt p1[3] + p1[1] (x0
 *   + w) übergeben, sodass Klicks rechts neben dem Editorfeld noch als innerhalb gelten.
 === Ende Beschreibung === */
void f_060ae0(short *p1, char *p2, int p3)
{
  int f_05e2a0(void *, int *, int *, int *, int *);
  struct {
    unsigned short rect[4];
    int screen;
    int saved_b;
    int state;
    int saved_a;
    int done;
  } f;
  short col, row, old_col, old_row;

  f.screen = f_05e850(&d_1c38b0);
  f.done = 0;
  f_05e2a0(&d_1c38b0, &old_col, &col,
             &row, &old_row);
  f_05e2d0(&d_1c38b0, 0, 0x140, 0, 0);
  f_05e840(&d_1c38b0, 0);

  p1[8] = 0;
  p1[9] = 0;
  p1[0x12] = p1[3];
  p1[0x13] = p1[4];
  f.saved_a = d_1bf510;
  f.saved_b = d_1bf514;
  d_1bf510 = p3;
  d_1bf514 = 0;
  *(int *)(p1 + 0x10) = -1;
  f_061350(p1);
  f_061590(p1);
  f_0625e0(p1);

  for (;;) {
    *(int *)(p1 + 0xa) = 0;
    *(int *)(p1 + 0xc) = 0;
    *(int *)(p1 + 0xe) = 0;
    f_068f40();
    if (d_1bfdb8 != 0)
      d_1bd766 = f_0dacc0(d_1bfdb8);
    if (d_1bd75c == 0x22)
      d_1bd75c = 0x3e;
    int t_117 = f_045df0(&d_1c3078, (unsigned char)d_1bd75c);
    if (t_117 == 1) {
      f_0616f0(p1);
      f_061e60(p1, (unsigned char)d_1bd75c);
      f_061590(p1);
      f_0625e0(p1);
    }
    if (f_0d37b0())
      d_1bd766 = 0x11b;
    if (d_1bd75c == 0xd || d_1bd75c == 8)
      d_1bd766 = d_1bd75c;

    switch ((unsigned short)d_1bd766) {
    case 0x80:
    case 0x86:
    case 0x11b:
    case 0x4900:
      f.done = 1;
      break;
    case 8: f_061d20(p1); break;
    case 0x5300: f_061ee0(p1); break;
    case 0x4b00: f_062000(p1); break;
    case 0x4d00: f_0621b0(p1); break;
    case 0x4800: f_062390(p1); break;
    case 0x5000: f_0624b0(p1); break;
    case 0x4f00: f_0622e0(p1); break;
    case 0x4700: f_062120(p1); break;
    case 0xd:
      if (p1[8] + 1 < (int)p1[0])
        f_0617f0(p1);
      break;
    }

    if (d_1bfdb8 == 0 && f_0d3780()) {
      if (f_0d3390(p1[3], p1[4],
                    (short)(p1[3] + p1[2]),
                    (short)(p1[0] * p1[5] + p1[4])) == 0)
        f.done = 1;
    }

    if (*(int *)(p1 + 0xa) == 1) {
      f_061350(p1);
      goto paint_end;
    }
    if (*(int *)(p1 + 0xc) == 1)
      goto paint_other;
    if (*(int *)(p1 + 0xe) == 1) {
      if ((*(char ***)(p1 + 0x1a))[p1[8]][p1[9]] == '\0') {
        unsigned short x = *(unsigned short *)(p1 + 0x12) - (unsigned char)f_045db0(&d_1c3078, (unsigned char)d_1bd75c);
        f_0616f0(p1);
        if (f_0d3860() == 1) {
          f_0d2710();
          f.state = 1;
        } else {
          f.state = 0;
        }
        f.rect[0] = d_1bdbd4;
        f.rect[1] = d_1bdbd6;
        f.rect[2] = d_1bdbd8;
        f.rect[3] = d_1bdbda;
        f_099f70((unsigned short)x, d_1bdbd6,
                  (unsigned short)((unsigned char)f_045db0(
                    &d_1c3078, (unsigned char)d_1bd75c) + x - 1),
                  d_1bdbda);
        if (*(int *)(p1 + 0x14)) {
          ((RivaRasterImage*)(*(int *)(p1 + 0x14)))->f_0fade0((void *)( *(int *)(p1 + 0x16)),
                     p1[3], p1[0x13]);
        } else {
          short i = 0;
          if (p1[5] > (short)0) {
            do {
              f_1483f0(*(int *)(p1 + 0x16), p1[3],
                          (short)(p1[0x13] + i),
                          p1[1], *(signed char *)(p1 + 7));
              i++;
            } while (i < p1[5]);
          }
        }
        f_099fa0(f.rect);
        f_05ebd0(&d_1c38b0, *(signed char *)&d_1bd75c,
                   (short)x, p1[0x13]);
        if (f.state == 1)
          f_0d26e0();
        f_061590(p1);
        goto paint_end;
      }
      goto paint_other;
    }
    goto check_done;

paint_other:
    f_0614d0(p1);
paint_end:
    f_0625e0(p1);
check_done:
    if (!f.done)
      continue;

    f_0616f0(p1);
    d_1bf510 = f.saved_a;
    d_1bf514 = f.saved_b;
    f_05e840(&d_1c38b0, f.screen);
    f_05e2d0(&d_1c38b0, (short)old_col, (short)col,
               (short)row, (short)old_row);

    short i = 0;
    if (p1[0] > (short)0) {
      do {
        short length = strlen((*(char ***)(p1 + 0x1a))[i]) + 1;
        strcpy(p2, (*(char ***)(p1 + 0x1a))[i]);
        i = i + 1;
        p2 = p2 + length;
      } while (i < p1[0]);
    }
    return;
  }
}

//@ f_060fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schiebt für den automatischen Wortumbruch (f_061080) und das Teilen einer Zeile (f_0617f0) den
 *   bisherigen Inhalt der Zielzeile p2 per memmove (f_14d075) nach rechts und fügt den Überhangtext p3 (ohne
 *   führendes Leerzeichen) am Zeilenanfang ein, bei p4 != 0 getrennt durch ein Leerzeichen.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Editorzeiger p1, den Zeiger p2 auf den Puffer
 *   der Zielzeile, den einzufügenden Text p3 und den Trennschalter p4 (1 = Leerzeichen zwischen p3 und altem
 *   Zeileninhalt einfügen). Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokale Variable sVar5 speichert die Länge strlen(p3) des einzufügenden Textstücks.
 === Ende Beschreibung === */
void f_060fd0(int p1, char *p2, char *p3, int p4)
{
  int f_14d075(void *, void *, int);
  short sVar5;

  if ((int)(signed char)*p3 == 0x20) {
    p3 = p3 + 1;
  }
  sVar5 = strlen(p3);
  if (p4 != 0) {
    f_14d075(p2 + sVar5 + 1, p2, strlen(p2));
    if (p2[sVar5 + 1] != '\0') {
      p2[sVar5] = ' ';
    }
  } else {
    f_14d075(p2 + sVar5, p2, strlen(p2));
  }
  while (*p3 != '\0') {
    *p2 = *p3;
    p2 = p2 + 1;
      p3 = p3 + 1;
  }
}

//@ f_061050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die gesamte Pixelbreite eines nullterminierten Strings p2 in der Editor-Schrift
 *   d_1c3078 als Summe der Einzelzeichenbreiten (f_045db0).
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Editorzeiger p1 und den String p2 und gibt die
 *   berechnete Breite in Pixeln als int zurück.
 * - Wichtige Variablen: Fragt für jedes Zeichen von p2 die Breite über f_045db0(&d_1c3078, *p2) ab.
 === Ende Beschreibung === */
int f_061050(int p1, unsigned char *p2)
{
  int iVar3;

  iVar3 = 0;
  while (*p2) {
    iVar3 = iVar3 + (unsigned char)f_045db0(&d_1c3078, (unsigned)*p2);
    p2 = p2 + 1;
  }
  return iVar3;
}
