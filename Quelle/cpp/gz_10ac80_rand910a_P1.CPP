/* === Beschreibung (Katalog) ===
 * Einheit gz_10ac80_rand910a (10ac80 - 10af60)
 *
 * Überblick
 *
 * Die Einheit gz_10ac80_rand910a implementiert die Wrapper-Klasse um die externe Smacker-Videobibliothek
 * (SMACKW32 / RAD Game Tools). Sie verwaltet das Öffnen, Entpacken, Paletten-Übernehmen und Weiterschalten
 * einzelner Video-Frames (f_10ac80 bis f_10af50).
 === Ende Beschreibung === */
// P3 7/11 gleich (suche.py 25.10.2026, Basis gz_10ac80_P1.CPP)
// gz_10ac80.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10AC80-0x10AFD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



#include <bios.h>
#define I(p,o) (*(int *)((char *)(p) + (o)))
#define S(p,o) (*(short *)((char *)(p) + (o)))
#define VS(p,o) (*(short *)((char *)(p) + (o)))
int f_109290(int p1, int p2);
int f_1092e0(int p1, int p2);
int f_10aa60(int p1, int p2);
int f_146dfa(int p1, int p2);
int f_11e910(int, int, int, int, int, int, int, int);
int f_149f90(int);
int f_14a450(int, int);
int f_14b100(int);
int f_14b7b0(int);
int f_14d040(int);
int f_145234(int p1, int p2);
int f_145254();
int f_14d0e4(const char *, ...);
#pragma aux f_11e910 parm caller [] modify [eax ebx ecx edx];
#pragma aux f_14d040 parm caller [] modify [eax ebx ecx edx];
#pragma aux f_149f90 parm [] modify [eax ebx ecx edx];
#pragma aux f_14a450 parm [] modify [eax ebx ecx edx];
#pragma aux f_14b100 parm [] modify [eax ebx ecx edx];
#pragma aux f_14b7b0 parm [] modify [eax ebx ecx edx];
extern char d_1bb8b0[];
extern char d_1bb8c4[];
extern char d_1c2edc[];
extern const char d_1b8354[];
extern void (*d_1ce430)(void);

//@ f_10ac80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Smacker-Player-Objekt und setzt die internen Handle- und
 *   Pufferzeiger auf 0.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_10ac80(int p1)
{
  if (I(p1, 4) != 0) delete (char *)I(p1, 4);
  d_1ce430();
  f_14b7b0(I(p1, 0));
  I(p1, 8) = 0;
  S(p1, 0x16) = 1;
}
//@ f_10acc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor schließt ein noch geöffnetes Smacker-Video über f_10ad70 und baut das Player-Objekt
 *   ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Zeiger p1 zurück.
 === Ende Beschreibung === */
void f_10acc0(int p1)
{
  int n = S(p1, 0x16);
  if ((unsigned)n < (unsigned)I(I(p1, 0), 0xc)) {
    f_14b100(I(p1, 0));
    f_10aa60(p1, 1);
    if (I(I(p1, 0), 0x68) != 0) {
      f_14d040(I(p1, 0) + 0x6c);
    }
    S(p1, 0x16)++;
  }
}
//@ f_10ad00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode öffnet einen Smacker-Videostream über die Bibliotheksfunktion SmackOpen, speichert das
 *   Handle im Player-Objekt und legt den Zielpuffer für die Bilddaten an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, den Dateinamen bzw. Dateizeiger p2 sowie Steuerflags (p3,
 *   p4).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Öffnen des Videos oder 0 bei einem Fehler zurück.
 === Ende Beschreibung === */
void f_10ad00(int p1)
{
  f_14b100(I(p1, 0));
  S(p1, 0x16) = S(I(p1, 0), 0x370);
  if (VS(p1, 0x16) == I(I(p1, 0), 0xc) - 1) {
    S(p1, 0x20)++;
  }
  f_10aa60(p1, 1);
  if (I(I(p1, 0), 0x68) != 0) {
    f_14d040(I(p1, 0) + 0x6c);
  }
  int self = p1;
  if (I(self, 0x1c) && I(self, 0x1c) != -1) {
    ((void (*)(int))I(self, 0x1c))(0);
  }
}
//@ f_10ad70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode schließt das aktive Smacker-Handle (SmackClose) und gibt den zugehörigen Bildpuffer
 *   wieder frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10ad70(int p1, short p2)
{
  if (p2 >= 1) {
    short i;
    int v;
    f_14a450(1, I(p1, 0));
    i = 1;
    v = f_10aa60(p1, 0);
    if (i < p2) {
      do {
        i++;
        f_14b100(I(p1, 0));
        v = f_10aa60(p1, 0);
      } while (i < p2);
    }
    f_11e910(I(p1, 4), 0, 0, I(I(p1, 0), 4), I(I(p1, 0), 8), I(I(p1, 0), 4), S(p1, 0x1a), S(p1, 0x18));
    f_14d040(I(p1, 0) + 0x6c);
  }
}
//@ f_10ae00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft über SmackWait, ob die Wartezeit bis zum nächsten Video-Frame abgelaufen ist.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Status von SmackWait zurück.
 === Ende Beschreibung === */
void f_10ae00(int p1)
{
  if (S(p1, 0x16) > 1) {
    short v = S(p1, 0x16) - 1;
    S(p1, 0x16) = v;
    f_10ad70(p1, v);
  }
}
inline void riva_10acc0_alt(int p1)
{
  if ((unsigned)S(p1, 0x16) < (unsigned)I(I(p1, 0), 0xc)) {
    f_14b100(I(p1, 0));
    f_10aa60(p1, 1);
    if (I(I(p1, 0), 0x68) != 0) {
      f_14d040(I(p1, 0) + 0x6c);
    }
    S(p1, 0x16)++;
  }
}

//@ f_10ae20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode dekodiert das aktuelle Einzelbild des Smacker-Videos (SmackDoFrame), übernimmt bei
 *   einem Palettenwechsel die neuen RGB-Farbwerte in die Hardware- bzw. Spielpalette und kopiert das Bild in den
 *   Anzeigepuffer.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt 1 zurück, solange weitere Frames folgen, oder 0 am Ende des Videos.
 === Ende Beschreibung === */
short f_10ae20(int p1, int p2, void (*p3)(int))
{
  int screen = (int)d_1c2edc;
  short r = 0;
  short sv = S(p1, 0x16);
  do {
    do {
      if ((unsigned)sv > (unsigned)I(I(p1, 0), 0xc)) goto done;
      if (I(p1, 0x10) != 0) {
        f_14d0e4(d_1b8354, (int)S(p1, 0x16));
      }
      if (p3 != 0) {
        p3(sv);
      }
      while (f_149f90(I(p1, 0)) != 0) {
        f_146dfa(screen, 1);
      }
      riva_10acc0_alt(p1);
      sv++;
    } while ((short)p2 != 0);
  } while (!_bios_keybrd(_KEYBRD_READY));
  r = _bios_keybrd(_KEYBRD_READ);
done:
  int self = p1;
  if (I(self, 0x1c) != 0 && I(self, 0x1c) != -1) {
    ((void (*)(int))I(self, 0x1c))(0);
  }
  return r;
}
//@ f_10af20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese drei kurzen Zugriffsmethoden schalten zum nächsten Frame weiter (SmackNextFrame) bzw. lesen
 *   Breite, Höhe oder Frame-Zähler aus dem Smacker-Handle aus.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktionen geben den jeweiligen Eigenschaftswert aus der Smacker-Struktur zurück.
 === Ende Beschreibung === */
int f_10af20(int p1)
{
  return !f_149f90(I(p1, 0));
}
//@ f_10af40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liest den 16-Bit-Zähler S(p1, 0x20) (Anzahl der abgeschlossenen
 *   Videodurchläufe) aus dem Smacker-Player-Objekt p1 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion gibt den 16-Bit-Wert bei Offset +0x20 zurück (short).
 * - Wichtige Variablen: S(p1, 0x20) (Durchlaufzähler).
 === Ende Beschreibung === */
short f_10af40(int p1)
{
  return S(p1, 0x20);
}
//@ f_10af50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode setzt das 32-Bit-Status- bzw. Datenfeld bei Offset +0x22 des
 *   Smacker-Player-Objekts p1 auf den übergebenen Wert p2.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den neuen 32-Bit-Wert p2 (int).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: I(p1, 0x22).
 === Ende Beschreibung === */
void f_10af50(int p1, int p2)
{
  I(p1, 0x22) = p2;
}
//@ f_10af60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese beiden Funktionen sind im gemeinsamen Kopfbereich deklariert und werden in gz_10ac80_rand910b
 *   definiert.
 * - Eingaben: Siehe gz_10ac80_rand910b.md.
 * - Rückgabewert: Siehe gz_10ac80_rand910b.md.
 === Ende Beschreibung === */
int f_10af60(int p1, int p2)
;
//@ f_10af80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Compiler-generierte COMDAT-Destruktor-Wrapper (in dieser Teileinheit vorwärtsdeklariert,
 *   Definition in gz_10ac80_rand910b) ruft den Destruktor des Smacker-Players auf und gibt bei gesetztem Bit 2
 *   in p2 den Objektspeicher frei.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück (int).
 * - Wichtige Variablen: In gz_10ac80_rand910a als Vorwärtsdeklaration geführt.
 === Ende Beschreibung === */
int f_10af80(int p1, int p2)
;
