/* === Beschreibung (Katalog) ===
 * Einheit gz_10ac80_rand910b (10af60 - 10afd0)
 *
 * Überblick
 *
 * Die Einheit gz_10ac80_rand910b bildet den Abschluss der Smacker-Video-Wrapper-Klasse und enthält eine
 * Zugriffsmethode sowie den COMDAT-Destruktor-Wrapper (f_10af60, f_10af80).
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
 * - Zweck: Diese neun Funktionen gehören zum ersten Teil der gesplitteten Einheit und sind in
 *   gz_10ac80_rand910a.md beschrieben.
 * - Eingaben: Siehe gz_10ac80_rand910a.md.
 * - Rückgabewert: Siehe gz_10ac80_rand910a.md.
 === Ende Beschreibung === */
void f_10ac80(int p1)
;
//@ f_10acc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode schaltet im Smacker-Video-Player p1 um ein Einzelbild weiter (f_14b100), sofern der
 *   aktuelle Frame-Zähler S(p1, 0x16) noch kleiner als die Gesamtframezahl I(I(p1, 0), 0xc) ist, kopiert den
 *   neuen Frame über f_10aa60(p1, 1) in den Ausgabepuffer, aktualisiert bei Palettenwechsel (+0x68) die
 *   Farbpalette (f_14d040) und erhöht den Frame-Zähler.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10acc0(int p1)
;
//@ f_10ad00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode rückt im Smacker-Stream um einen Frame vor (f_14b100), übernimmt die Frame-Nummer aus
 *   dem Smacker-Handle (+0x370), inkrementiert am Ende des Videos den Durchlaufzähler S(p1, 0x20), gibt das Bild
 *   samt eventueller neuer Palette aus und ruft bei gesetztem Callback (+0x1c) diesen mit 0 auf.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10ad00(int p1)
;
//@ f_10ad70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Such-Methode positioniert das Smacker-Video in p1 auf den Ziel-Frame p2 (>= 1), indem sie zum
 *   Videoanfang zurückspringt (f_14a450), in einer Schleife bis zum Frame p2 dekodiert (f_14b100, f_10aa60) und
 *   anschließend das resultierende Bild (f_11e910) sowie die Palette (f_14d040) darstellt.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die 1-basierte Ziel-Frame-Nummer p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10ad70(int p1, short p2)
;
//@ f_10ae00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode springt im Smacker-Video um ein Einzelbild zurück, indem sie den aktuellen Frame-Index
 *   S(p1, 0x16) (sofern > 1) um 1 verringert und den neuen Ziel-Frame über f_10ad70 ansteuert.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10ae00(int p1)
;
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
 * - Zweck: Diese Methode spielt das Smacker-Video in einer Schleife ab, wartet vor jedem Frame über f_149f90 und
 *   f_146dfa das Frame-Timing ab, ruft optional die pro Frame übergebene Callback-Funktion p3 auf und beendet
 *   die Wiedergabe am Videoende oder bei einem Tastendruck (_bios_keybrd).
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, das Schleifen-Flag p2 sowie den optionalen Frame-Callback
 *   p3.
 * - Rückgabewert: Die Funktion gibt den gelesenen Tastencode bei Tastaturabbruch oder 0 bei regulärem Ende
 *   zurück (short).
 === Ende Beschreibung === */
short f_10ae20(int p1, int p2, void (*p3)(int))
;
//@ f_10af20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode prüft über f_149f90(I(p1, 0)) (SmackWait), ob der nächste Video-Frame bereits fällig
 *   ist.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Wartezeit abgelaufen ist, sonst 0.
 === Ende Beschreibung === */
int f_10af20(int p1)
;
//@ f_10af40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liest den 16-Bit-Zähler S(p1, 0x20) (Anzahl der abgeschlossenen
 *   Videodurchläufe) aus dem Smacker-Player-Objekt p1 aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Smacker-Players.
 * - Rückgabewert: Die Funktion gibt den 16-Bit-Wert bei Offset +0x20 zurück (short).
 === Ende Beschreibung === */
short f_10af40(int p1)
;
//@ f_10af50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_10ac80_rand910a)
 *   setzt das 32-Bit-Status- bzw. Datenfeld bei Offset +0x22 des Smacker-Player-Objekts p1 auf den Wert p2.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den neuen 32-Bit-Wert p2 (int).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: I(p1, 0x22).
 === Ende Beschreibung === */
void f_10af50(int p1, int p2)
;
//@ f_10af60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liest den aktuellen Frame-Zähler oder Statuswert aus der im Player-Objekt p1
 *   gespeicherten Smacker-Struktur aus.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den gelesenen Statuswert zurück.
 === Ende Beschreibung === */
int f_10af60(int p1, int p2)
{
  int t = f_109290(p1, (short)p2);
  I(t, 0x58) = (int)d_1bb8c4;
  S(t, 0x72) = 0;
  I(t, 0x74) = 0;
  return t;
}
//@ f_10af80
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Compiler-generierte COMDAT-Destruktor-Wrapper ruft f_10acc0 zum Schließen des Smacker-Players
 *   auf und gibt bei gesetztem Bit 2 in p2 den Objektspeicher mit operator delete frei.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_10af80(int p1, int p2)
{
  if (p2 & 4) {
    f_145234(p1, (int)d_1bb8b0);
    f_145254();
    return p1;
  }
  I(p1, 0x58) = (int)d_1bb8c4;
  int r = f_1092e0(p1, 1);
  if (p2 & 2) delete (char *)r;
  return r;
}
