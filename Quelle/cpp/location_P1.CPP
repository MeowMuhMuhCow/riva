/* === Beschreibung (Katalog) ===
 * Einheit location (Adresse 0x0b8530 - 0x0b9940)
 *
 * Diese Einheit stammt aus der Originaldatei p:\riva\source\cpp\location.cpp und implementiert die zentrale
 * Steuerung für alle zweidimensionalen Gebäude- und Ortsbildschirme in Riva. Sie regelt das Betreten eines Ortes
 * (einschließlich Öffnungszeitenprüfung, Warte-Nachfrage bis zum Öffnen und Stadtalarm-Reaktion), das Laden der
 * passenden Hintergrundgrafiken und Animationen je nach Tageszeit und Wetter, die Anzeige von Hotspots sowie die
 * interaktive Hauptschleife innerhalb eines Gebäudes.
 === Ende Beschreibung === */
// P3 17/18 gleich (suche.py 29.10.2026, Basis location_P1.CPP)
// location.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B8530-0x0B9940
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01c000(int p1);                                   // reg eax stapel 0
int f_01c120(int p1, int p2);                           // reg eax edx stapel 0
int f_01d160(int p1, int p2);                           // reg eax edx stapel 0
int f_01df90(int p1);                                   // reg eax stapel 0
int f_01dfd0(int p1);                                   // reg eax stapel 0
int f_01ebc0(int p1, int p2);                           // reg edx stapel 0
int f_020970(int p1, int p2);                           // reg edx stapel 0
int f_0248d0(int p1, int p2);                           // reg edx stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_060a10(int p1);                                   // reg eax stapel 0
int f_099da0(int p1, int p2);                           // reg edx stapel 0
int f_09a180(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_09b080(int p1, int p2);                           // reg edx stapel 0
int f_09b980(int p1, int p2);                           // reg edx stapel 0
int f_0a5730(int p1, int p2);                           // reg edx stapel 0
int f_0b2900(int p1, int p2);                           // reg edx stapel 0
int f_0b3950(int p1, int p2);                           // reg eax edx stapel 0
int f_0b7d60(int p1, int p2);                           // reg edx stapel 0
int f_0bc060(int p1);                                   // reg eax stapel 0
int f_0bcae0(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_0bcfc0(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0cd9e0(int p1, int p2);                           // reg edx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d5780(int p1);                                         // reg - stapel 0
int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7c0(int p1);                                   // reg eax stapel 0
int f_0e96e0(int p1, int p2);                           // reg edx stapel 0
int f_0e9b40(int p1, int p2);                           // reg edx stapel 0
int f_109290(int p1, int p2);                           // reg edx stapel 0
int f_10af60(int p1, int p2);                           // reg edx stapel 0
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_11ea90(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_11ed00(int p1, int p2);                           // reg edx stapel 0
int f_121ec0();                                         // reg - stapel 0
int f_121fd0();                                         // reg - stapel 0
int f_123850(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_126840(int p1, int p2);                           // reg eax edx stapel 0
int f_126f40(int p1);                                   // reg eax stapel 0
unsigned short f_1271f0(int p1);                                   // reg eax stapel 0
int f_13fc70(int p1);                                   // reg eax stapel 0
signed char f_126420(int p1);
int f_1254a0(int p1, int p2);
int f_099ef0(int p1, int p2, int p3);
#pragma aux f_099ef0 parm caller [];
int f_149eb4(int p1, int p2, int p3);
#pragma aux f_149eb4 parm caller [];
short f_0bf820(int, int, int, int, int);
#pragma aux f_0bf820 parm caller [];
short f_0de800(int p1);
short f_0de820(int p1);
int f_0de8c0(int p1);
short f_0dacc0(int p1);
short f_1457e0(int p1);
int f_0de810(int p1, int p2);
int f_0de8d0(int p1, int p2);
int f_147c84(int p, int n, int ctor);
int f_0da910(int a, int b, int c, int d, int e, int f, int g);
int f_0da990(int p, int fl);
int f_01c080(int p, int fl);
int f_01cef0(int p);
int f_01cf10(int p);
int f_0bc2c0(int p);
int f_0bc1e0(int p, int q);
struct V3 { int a, b, c; };
extern struct V3 d_1bee34[];
extern struct V3 d_1bf158[];
extern short d_1c21a4;
extern int d_1bf1b0, d_1bf1b4, d_1c2a80, d_1bfaec, d_1bfdb8, d_1bc760, d_1bf1ac, d_1bdbe8, d_1c0004, d_1a34e0;
extern volatile int d_1c2198;
extern signed char d_1c00bc;
extern char d_1bfb1c, d_1c00a8;
extern short d_1bf51c;
extern char d_1c14c4[], d_1c2c44[], d_1c2c64[], d_1c2e78[], d_1bf230[], d_1baac0[], d_1c349c[], d_1c3870[], d_1c3498[], d_1bfdbc[];
extern short d_1a52b4[], d_1a52be[];
#define W16(p,o) (*(short *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define EQI(x,v) (((x)==(v))?1:0)
#define OBJ(ln) ((int)operator new(1, mark(d_1a5294, ln)))
#define DEL(o) operator delete((void *)(o))
typedef int (*FN1)(int);
typedef int (*FN2)(int, int);
extern const char d_1a5294[];
void f_0b8a40(int p);
int f_0b8d40(int p);
void f_0b8b20(int p);
void f_0b8b70(int p);
void f_0b90a0(int p, int q);
int f_0b8f70(int p);
void f_0b91e0(void);
void f_0b8cc0(int p);

#pragma inline_depth(0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0b8530
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Hauptfunktion steuert den kompletten Besuch eines 2D-Gebäudes oder Schauplatzes: Sie
 *   lädt die Gebäudedaten (f_0b8a40), bietet dem Spieler bei kurz bevorstehender Öffnung an, vor der Tür zu
 *   warten (0x200001c8), ruft den ortsspezifischen Eintritts-Handler oder die Öffnungszeitenprüfung (f_0b8d40)
 *   auf, startet die passende Hintergrundmusik (f_0d3f25) und führt anschließend die interaktive
 *   Ereignisschleife mit Mausklick- und Hotspot-Auswertung aus, bis der Spieler das Gebäude wieder verlässt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das aktuelle Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct LocPal { char b[3]; LocPal(); };
#include <stdlib.h>
#pragma intrinsic(abs)
void f_0b8530(int p)
{
  extern int f_060a80(int);
  extern int f_0d4880(int);
  extern int f_0ce7e0(int, int);
  extern int f_13fcd0(int, int);
  extern char d_1c2e68[];
  struct SlotBlock { int callback; int saved_sound; char local[4]; } slots;
  int result = 0;
  int x, y, o, cursor, again, difference, sound, old;
  int ident;
  signed char c;

  f_060a10(0x7a120);
  W16(&d_1bf1b0, 0) = f_13fc70((int)d_1c14c4);
  d_1bf1b4 = 0;
  f_0b8a40(p);
  again = 1;
  if (d_1c21a4 != 0) return;
  f_0ce7c0((int)slots.local);
  c = f_126420((int)d_1c2c44);
  x = W16(p, 0x32 + c * 2) * 0x1518;
  c = f_126420((int)d_1c2c44);
  y = W16(p, 0x40 + c * 2) * 0x1518;
  if (f_0b3950(x, y) == 0) {
    if (x < 0x1fa40) {
      difference = x - f_126410((int)d_1c2c44);
      if ((unsigned)abs(difference) < 0x3f48) {
        if (f_0bf6f0((int)d_1c2c64, 0x200001c8) == 1) {
          sound = (int)d_1c2c44;
          while (f_126410(sound) < x) {
            f_125f70(sound, 1);
            f_126840(sound, 0);
          }
        } else result = 1;
      }
    }
  }
  if (result == 0) {
    if (I32(p, 0x0a)) {
      int *handler = (int *)(p + 0x0a);
      int self = p + handler[1];
      slots.callback = ((FN1)handler[0])(self);
      result = ((FN1)slots.callback)(self);
    } else result = f_0b8d40(p);
    d_1bf1b4 = result == 0;
  }
  if (result == 0) {
    slots.saved_sound = f_0d40b6((int)d_1c2e78);
    ident = U16(p, 0);
    if (ident == 0x19) f_0d3f25((int)d_1c2e78, 4);
    else if (ident == 0x26 || I32(p, 0x54) == 5 || I32(p, 0x54) == 6)
      f_0d3f25((int)d_1c2e78, 6);
    f_0d2f90(0, 1);
    f_0b8b70(p);
    W16(&d_1c2198, 0) = 1;
    if (EQ((signed char)d_1bfb1c, 1) || d_1c2a80 == 0x40001)
      d_1c2a80 = 0;
    else f_0bcfc0((int)d_1bf230);
    {
      signed char nb = d_1c00a8;
      sound = nb;
    }
    while (result == 0) {
      if (d_1c2a80 == 0) again = 1;
      if (W16(&d_1c2198, 0) == 1 || again == 1) {
        W16(&d_1c2198, 0) = 0;
        f_0b90a0(p, again);
        again = 0;
      } else f_01dfd0(I32(p, 0x22));
      if (sound == 0) {
        *(char *)&d_1bfaec = f_0bf820((int)d_1c2c64, 0x2000000c, 2,
                              0x2000000d, 0x2000000e) == 2;
        sound = 1;
      }
      if (result == 0) result = f_0b8f70(p);
      if (I32(p, 0x16) && result == 0) {
        int *handler = (int *)(p + 0x16);
        int self = p + handler[1];
        slots.callback = ((FN1)handler[0])(self);
        result = ((FN1)slots.callback)(self);
      }
      if (result == 0) {
        if (W16(p, 0x4e) == 0) {
          f_0d5780((int)d_1bf230);
          W16(p, 0x4e) = f_0dacc0(d_1bfdb8);
        }
        result = ((FN2)I32(I32(p, 0x58), 0))(p, W16(p, 0x4e));
        W16(p, 0x4e) = 0;
      }
    }
    if (d_1bc760) {
      cursor = (int)new (mark(d_1a5294, 0x386)) LocPal[256];
      f_09a180(0, cursor, 0x19, 0xa0, 1);
      DEL(cursor);
      f_01cef0(d_1bc760);
      f_01cf10(d_1bc760);
      old = d_1bc760;
      if (old) DEL(f_01c080(old, 0));
      d_1bc760 = 0;
      f_0bc2c0((int)d_1bf230);
      f_0bc1e0((int)d_1bf230, d_1a34e0);
    }
    o = OBJ(0x293);
    f_11ea90(o, 0x220002, W16(p, 0), p + 0x22, 4);
    f_11ea90(o, 0x220005, W16(p, 0), p + 0x26, 4);
    DEL(o);
    ((FN1)I32(I32(p, 0x58), 8))(p);
    old = d_1bfdb8;
    if (old) DEL(f_0da990(old, 0));
    d_1bfdb8 = 0;
    if (EQ((signed char)d_1bfb1c, 1)) d_1c2a80 = 0;
    if (f_060a80(f_0de820(d_1c0004))) f_0bcfc0((int)d_1bf230);
    ident = U16(p, 0);
    if (ident == 0x19 || ident == 0x26 || I32(p, 0x54) == 5 || I32(p, 0x54) == 6)
      f_0d3f25((int)d_1c2e78, (short)slots.saved_sound);
    W16(&d_1c2198, 0) = 1;
  }
  o = OBJ(0x240);
  f_11ea90(o, 0x220003, W16(p, 0), p + 0x2a, 8);
  DEL(o);
  f_13fcd0((int)d_1c14c4, W16(&d_1bf1b0, 0));
  f_0d4880((int)d_1c2e68);
  f_0ce7e0((int)slots.local, 0);
}
//@ f_0b8a00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion setzt das 32-Bit-Feld bei Offset +0x2e (Schwellenwert für Witterungs- oder
 *   Zutrittsbedingungen) des Location-Objekts p auf den übergebenen Wert v.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt sowie den 32-Bit-Wert v entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8a00(int p, int v)
{
  I32(p, 0x2e) = v;
}
//@ f_0b8a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest die 16-Bit-Ortskennung bei Offset +0 des Location-Objekts p aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt die 16-Bit-Ortskennung (short) zurück.
 === Ende Beschreibung === */
short f_0b8a10(int p)
{
  return W16(p, 0);
}
//@ f_0b8a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Standard-Aktionsmethode des Location-Objekts dient als Platzhalter und gibt konstant
 *   0 zurück, sodass das Gebäude geöffnet bleibt.
 * - Eingaben: Die Funktion nimmt den Objektzeiger a sowie den Aktionscode b entgegen.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
int f_0b8a20(int a, int b)
{
  return 0;
}
//@ f_0b8a30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere virtuelle Methode des Location-Objekts dient als Standard-Platzhalter ohne eigene
 *   Operation.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8a30(void)
{
}
//@ f_0b8a40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert die Metadaten eines Gebäudeobjekts p anhand seiner Kennung bei Offset
 *   +0, indem sie die zugehörige Beschreibungsstruktur aus dem globalen Gebäude-Array d_1c212c sucht, den
 *   Gebäudetyp (+0x54) sowie das Flag für waffenfreie Zonen (d_1bfaec) setzt und die ortsspezifische
 *   Setup-Methode über den Memberfunktionszeiger in der globalen Tabelle d_1bee34 aufruft.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8a40(int p)
{
  int loc;
  short s;
  int o = OBJ(0x217);
  loc = 0;
  f_11ea00(o, 0x220009, W16(p, 0), p + 2, 4);
  f_11ea00(o, 0x220011, W16(p, 0), p + 6, 4);
  f_11ea00(o, 0x220003, W16(p, 0), p + 0x2a, 8);
  f_11ea00(o, 0x22000a, W16(p, 0), p + 0x32, 0x1c);
  f_11ea00(o, 0x220006, W16(p, 0), (int)&loc, 4);
  s = (short)loc;
  if (s != 0) {
    struct V3 *dst = (struct V3 *)(p + 10);
    struct V3 *src = &d_1bee34[s];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
  }
  DEL(o);
  W16(p, 0x4e) = 0;
}
//@ f_0b8b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion sichert den 8-Byte-Statusblock ab Offset +0x2a (Öffnungs- und Alarmdaten) des
 *   Gebäudes mit der Kennung W16(p, 0) über f_11ea90 unter dem Schlüssel 0x220003.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8b20(int p)
{
  int o = OBJ(0x240);
  f_11ea90(o, 0x220003, W16(p, 0), p + 0x2a, 8);
  DEL(o);
}
//@ f_0b8b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt beim Betreten eines Gebäudes das passende Hintergrundbild (unter Berücksichtigung
 *   von Tageszeit f_126420 und Regenwetter f_1271f0), legt bei Bedarf das Animations-Steuerungsobjekt (f_01de90)
 *   für Raum-Animationen an und lädt das Hotspot-Menü-Overlay (f_0bf1d0).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8b70(int p)
{
  int loc = 0;
  int s;
  int o = OBJ(0x25d);
  f_11ea00(o, 0x220002, W16(p, 0), p + 0x22, 4);
  int t_277 = U16(p, 0x26);
  if (t_277 == 0) f_11ea00(o, 0x220005, W16(p, 0), p + 0x26, 4);
  f_11ea00(o, 0x22000b, W16(p, 0), p + 0x28, 2);
  f_11ea00(o, 0x220010, W16(p, 0), (int)&loc, 4);
  DEL(o);
  if (d_1bc760 == 0) {
    int t = (int)operator new(0xcf, mark(d_1a5294, 0x278));
    int o2 = t ? f_01c000(t) : t;
    d_1bc760 = o2;
  }
  s = (short)loc;
  if (s != 0) {
    struct V3 *src = &d_1bf158[s];
    struct V3 *dst = (struct V3 *)(p + 0x16);
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
  }
  {
    int t = (int)operator new(0x42, mark(d_1a5294, 0x282));
    int o3 = t ? f_0da910(t, 0x280000, 0x280001, 0x280002, 0x280003, 9, W16(p, 0x28)) : t;
    d_1bfdb8 = o3;
  }
  ((FN1)I32(I32(p, 0x58), 4))(p);
}
//@ f_0b8cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion gibt beim Verlassen eines Gebäudes das geladene Hotspot-Menü-Overlay
 *   (f_0bf2c0), das Animations-Steuerungsobjekt (f_01deb0) sowie das Hintergrundbild (f_050330) wieder frei.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b8cc0(int p)
{
  int o = OBJ(0x293);
  f_11ea90(o, 0x220002, W16(p, 0), p + 0x22, 4);
  f_11ea90(o, 0x220005, W16(p, 0), p + 0x26, 4);
  DEL(o);
  ((FN1)I32(I32(p, 0x58), 8))(p);
  { int t = d_1bfdb8; if (t) { DEL(f_0da990(t, 0)); } }
  d_1bfdb8 = 0;
}
//@ f_0b8d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Versuch, ein Gebäude ohne eigenen Eintritts-Handler zu betreten, ob in Riva
 *   Stadtalarm herrscht (d_1c00bc == 1, wobei mit steigender Wahrscheinlichkeit U16(p, 0x2c) die Tür verriegelt
 *   wird oder Wachen erscheinen) und ob das Gebäude zur aktuellen Tageszeit (f_126420) geöffnet hat. Ist das
 *   Gebäude geschlossen, wird die Schließungsmeldung (W16(p, 0x26) oder Standardtext 0x22000001) ausgegeben und
 *   5 Minuten Spielzeit addiert.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 0 zurück, wenn die Gruppe das Gebäude betreten darf, oder 1, wenn ihr der
 *   Zutritt verwehrt wird.
 === Ende Beschreibung === */
int g_1271f0(int p1);
#pragma aux g_1271f0 "f_1271f0" parm [eax] modify [eax ebx ecx edx] value [eax];
struct MsgC {
  int h;
  int *q[14];
  MsgC(void *a, void *b, void *c) { f_125400((int)this, (int)a, (int)b, (int)c); }
  ~MsgC() { f_1254a0((int)this, 0); }
};
int f_0b8d40(int p)
{
  int o[2];
  signed char c;
  int a, b;
  unsigned code;
  int r;
  c = f_126420((int)d_1c2c44);
  a = W16(p, 0x32 + c * 2) * 0x1518;
  b = W16(p, 0x40 + f_126420((int)d_1c2c44) * 2) * 0x1518;
  code = 0;
  r = 0;
  if (d_1c21a4 != 0) {
    r = 1;
  } else {
    if (!f_0b3950(a, b)) {
      f_0bf730((int)d_1c2c64, 0x22000001);
      r = 1;
    } else {
      if (EQI(d_1c00bc, 1)) {
        int h = U16(p, 0x2c);
        if (h > 0) {
          if (h == 100) {
            code = 0x22000002;
          } else {
            if (!(f_1457e0(100) > h)) {
              code = 0x22000003;
              W16(p, 0x2c) = 100;
            }
          }
        }
      } else {
        f_126f40((int)o);
        if (I32(p, 0x2e) == -1) {
          code = 0x22000005;
          r = 1;
        } else if (I32(p, 0x2e) != 0) {
          if (g_1271f0((int)o) > I32(p, 0x2e)) {
            code = 0x22000005;
            r = 1;
          }
        }
      }
    }
  }
  if (code > 0) {
    MsgC m(d_1c349c, d_1c3870, d_1c3498);
    int s;
    m.q[3][1] = I32(p, 2);
    s = U16(p, 0x2a);
    if (s == 0) {
      m.q[3][2] = 0x20000001;
    } else {
      if (s == 1) m.q[3][2] = 0x20000002;
    }
    f_0bf730((int)d_1c2c64, code);
  }
  if (U16(p, 0x2c) == 0x64) {
    f_0bf730((int)d_1c2c64, 0x22000004);
    r = 1;
  }
  return r;
}
//@ f_0b8ef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest anhand der aktuellen Tageszeit (f_126420(d_1c2c44)) den zweiten Zeitwert
 *   (Schließungszeit bzw. Ende des Zeitfensters) aus dem Array ab Offset +0x40 und rechnet ihn durch
 *   Multiplikation mit 0x1518 (5400 Ticks pro Stunde) in Spielzeit-Ticks um.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeitwert in Spielzeit-Ticks zurück.
 === Ende Beschreibung === */
void f_0b8ef0(int p)
{
  signed char c;
  int a;
  c = f_126420((int)d_1c2c44);
  a = W16(p, 0x32 + c * 2) * 0x1518;
  c = f_126420((int)d_1c2c44);
  f_0b3950(a, W16(p, 0x40 + c * 2) * 0x1518);
}
//@ f_0b8f70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft während des laufenden Gebäudebesuchs in jeder Schleifeniteration, ob die Gruppe
 *   das Gebäude verlassen muss, weil d_1c21a4 gesetzt ist, eine Sperrbedingung in I32(p, 0x2e) eingetreten ist
 *   (Meldung 0x2200000c) oder die Schließungszeit erreicht wurde (f_0b3950 == 0, Meldung 0x2200000b mit dem
 *   Gebäudenamen I32(p, 2)).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Gebäude geschlossen bzw. verlassen werden muss, oder 0,
 *   wenn der Aufenthalt fortdauert.
 === Ende Beschreibung === */
int f_0b8f70(int p)
{
  signed char c;
  int a;
  char ob[0x3c];
  int r = 0;
  if (d_1c21a4 != 0) r = 1;
  if (I32(p, 0x2e) != 0) {
    r = 1;
    f_0bf730((int)d_1c2c64, 0x2200000c);
  } else {
    c = f_126420((int)d_1c2c44);
    a = W16(p, 0x32 + c * 2) * 0x1518;
    c = f_126420((int)d_1c2c44);
    if (f_0b3950(a, W16(p, 0x40 + c * 2) * 0x1518) == 0) {
      f_125400((int)ob, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498);
      I32(I32(ob, 0x10), 4) = I32(p, 2);
      f_0bf730((int)d_1c2c64, 0x2200000b);
      r = 1;
      f_1254a0((int)ob, 0);
    }
  }
  return r;
}
//@ f_0b9060
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lädt oder aktiviert anhand des Teilindex U16(p, 0x26) die zugehörige Grafikressource
 *   U16(p, 0x26) + 0x150007 über f_056a50.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b9060(int p)
{
  f_056a50(U16(p, 0x26) + 0x150007);
}
//@ f_0b9080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion aktualisiert die Bildschirmdarstellung (f_0d5780(d_1bf230)) und liest
 *   anschließend über f_0dacc0(d_1bfdb8) den vom Spieler angeklickten Hotspot- oder Menüpunkt im Gebäude ein.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den gewählten 16-Bit-Aktionscode (short) zurück.
 === Ende Beschreibung === */
short f_0b9080(void)
{
  f_0d5780((int)d_1bf230);
  return f_0dacc0(d_1bfdb8);
}
//@ f_0b90a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Darstellungsfunktion zeichnet das Hintergrundbild des aktuellen Gebäudes in den
 *   Bildschirmpuffer, blendet bei neuem Bildaufbau (flag == 1) das Bild weich über (f_0bce10), aktualisiert die
 *   Raum-Animation (f_01df10) und gibt beim erstmaligen Betreten eines Raumes dessen Beschreibungstext (I32(p,
 *   0x50)) aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das Location-Objekt sowie das Überblend-Flag flag (1 für
 *   Neuaufbau mit Überblendung, 0 für direktes Zeichnen) entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct Pal { char c[3]; Pal(); };
void f_0b90a0(int p, int q)
{
  extern void readPalette494(int,int,int);
  #pragma aux readPalette494 "f_149eb4" parm caller [] modify exact [eax ecx edx]
  Pal *a;
  f_0bc060((int)d_1bf230);
  f_0daba0(d_1bfdb8, d_1a34e0);
  f_0bcae0((int)d_1bf230, I32(p, 6), 0xff, d_1a34e0);
  f_099ef0(d_1bdbe8, 0, 0xa0);
  if (d_1bc760 == 0) {
    int t = (int)operator new(0xcf, mark(d_1a5294, 0x368));
    d_1bc760 = t ? f_01c000(t) : t;
  }
  f_01d160(d_1bc760, I32(p, 0x22));
  if (q == 1) {
    a = new (mark(d_1a5294, 0x36f)) Pal[256];
    f_01c120(d_1bc760, 4);
    f_01c120(d_1bc760, 5);
    readPalette494((int)a,0,0x100);
    f_09a180((int)a, f_01df90(d_1bc760), 0x19, 0xa0, 1);
    DEL(a);
  } else {
    f_01c120(d_1bc760, 0);
  }
}
//@ f_0b91e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion blendet beim Verlassen einer Gebäudeansicht die Palette aus (f_09a180), beendet
 *   und löscht das aktive Raum-Animationsobjekt d_1bc760 (f_01cef0, f_01cf10, f_01c080) und stellt den
 *   Bildschirmhintergrund über f_0bc2c0 und f_0bc1e0 wieder her.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b91e0(void)
{
  Pal *o = new (mark(d_1a5294, 0x386)) Pal[256];
  f_09a180(0, (int)o, 0x19, 0xa0, 1);
  DEL(o);
  f_01cef0(d_1bc760);
  f_01cf10(d_1bc760);
  { int t = d_1bc760; if (t) { DEL(f_01c080(t, 0)); } }
  d_1bc760 = 0;
  f_0bc2c0((int)d_1bf230);
  f_0bc1e0((int)d_1bf230, d_1a34e0);
}
//@ f_0b9280
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Fabrik- und Steuerfunktion ermittelt die aktuelle Gebäudekennung id
 *   (f_0de800(d_1c0004)), instanziiert über eine große switch-Verzweigung die passende abgeleitete Gebäudeklasse
 *   in d_1bf1ac (z. B. Taverne, Tempel, Heiler, Händler, Markthalle oder Wohnhaus), führt den gesamten
 *   Gebäudebesuch über f_0b8530 aus, gibt das Objekt anschließend frei, dreht die Blickrichtung der Gruppe beim
 *   Verlassen ins Freie um 180 Grad ((angle + 0xb4) % 0x168) und setzt die Ortskennung aller Gruppenmitglieder
 *   in d_1bfdbc auf -1 zurück.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#pragma inline_depth(255)
static inline char get_1bfb1c() { return d_1bfb1c; }
struct LocPad {
  char pad[0x54];
  int type;
};
struct LocBase : LocPad {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual ~LocBase();
};
struct Factory494 {
  struct f_123850 { char body[0x66]; f_123850(int); };
  struct f_109290 { char body[0x72]; f_109290(int); };
  struct f_09b980 { char body[0x72]; f_09b980(int); };
  struct f_10af60 { char body[0x78]; f_10af60(int); };
  struct f_0e96e0 { char body[0x5c]; f_0e96e0(int); };
  struct f_01ebc0 { char body[0x5c]; f_01ebc0(int); };
  struct f_0b2900 { char body[0x5c]; f_0b2900(int); };
  struct f_0b7d60 { char body[0x5c]; f_0b7d60(int); };
  struct f_099da0 { char body[0x5c]; f_099da0(int); };
  struct f_11ed00 { char body[0x66]; f_11ed00(int); };
  struct f_0248d0 { char body[0x60]; f_0248d0(int); };
  struct f_0a5730 { char body[0x73]; f_0a5730(int); };
  struct f_09b080 { char body[0x64]; f_09b080(int); };
  struct f_0e9b40 { char body[0x60]; f_0e9b40(int); };
  struct f_0cd9e0 { char body[0x5e]; f_0cd9e0(int); };
  struct f_020970 { char body[0x5c]; f_020970(int); };
};
void f_0b9280(void)
{
  short dir = 0; // haelt die Registerzuteilung wie im Original
  short id = f_0de800(d_1c0004);
  dir = f_0de820(d_1c0004);
  int type = 8;
  short saved_1bf51c;
  unsigned short angle;
  short i;

  switch (id) {
  case 6:
  case 22:
  case 23:
  case 24:
  case 25:
  case 26:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3bf)) Factory494::f_123850(id);
    type = 1;
    break;
  case 9:
  case 21:
  case 27:
  case 28:
  case 29:
  case 31:
  case 114:
  case 115:
  case 116:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3cc)) Factory494::f_109290(id);
    type = 2;
    break;
  case 18:
  case 37:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3d2)) Factory494::f_09b980(id);
    type = 4;
    break;
  case 19:
  case 20:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3d8)) Factory494::f_10af60(id);
    type = 3;
    break;
  case 17:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3dd)) Factory494::f_0e96e0(id);
    type = 0;
    break;
  case 39:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x3e2)) Factory494::f_01ebc0(id);
    type = 7;
    break;
  case 3:
  case 5:
  case 30:
  case 36:
  case 40:
  case 50:
  case 51:
  case 52:
  case 53:
  case 54:
  case 55:
  case 56:
  case 57:
  case 58:
  case 59:
  case 60:
  case 61:
  case 62:
  case 63:
  case 64:
  case 65:
  case 66:
  case 70:
  case 71:
  case 72:
  case 75:
  case 76:
  case 77:
  case 78:
  case 79:
  case 80:
  case 81:
  case 82:
  case 83:
  case 84:
  case 85:
  case 86:
  case 87:
  case 88:
  case 89:
  case 90:
  case 91:
  case 92:
  case 93:
  case 94:
  case 95:
  case 96:
  case 97:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x416)) Factory494::f_0b2900(id);
    type = 0;
    break;
  case 1:
  case 33:
  case 34:
  case 35:
  case 41:
  case 42:
  case 43:
  case 44:
  case 45:
  case 46:
  case 47:
  case 48:
  case 49:
  case 67:
  case 68:
  case 69:
  case 73:
  case 74:
  case 98:
  case 99:
  case 101:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x42f)) Factory494::f_0b7d60(id);
    break;
  case 100:
  case 105:
  case 106:
  case 107:
  case 108:
  case 109:
  case 110:
  case 111:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x43a)) Factory494::f_099da0(id);
    type = 0;
    break;
  case 10:
  case 11:
  case 12:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x441)) Factory494::f_11ed00(id);
    type = 6;
    break;
  case 13:
  case 14:
  case 15:
  case 16:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x44e)) Factory494::f_0a5730(id);
    type = 5;
    break;
  case 38:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x446)) Factory494::f_0248d0(id);
    type = 0;
    break;
  case 102:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x453)) Factory494::f_09b080(id);
    break;
  case 103:
  case 104:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x458)) Factory494::f_0e9b40(id);
    type = 0;
    break;
  case 112:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x45d)) Factory494::f_0cd9e0(id);
  angle = (angle & 0) ? 0 : angle; // haelt die Registerzuteilung wie im Original
    break;
  case 113:
    d_1bf1ac = (int)new (mark(d_1a5294, 0x461)) Factory494::f_020970(id);
    break;
  case -1:
  default:
    d_1bf1ac = 0;
    break;
  }

  id = f_0de800(d_1c0004);
  if (get_1bfb1c()) f_121ec0();
  saved_1bf51c = d_1bf51c;
  d_1bf51c = 0;
  ((LocBase *)d_1bf1ac)->type = type;
  f_0b8530(d_1bf1ac);
  delete (LocBase *)d_1bf1ac;
  d_1bf1ac = 0;
  *(volatile short *)&d_1bf51c = saved_1bf51c; // haelt die Speicherreihenfolge wie im Original

  if (f_0de820(d_1c0004) == 0 && f_0de820(d_1c0004) == dir && type != 1 && d_1bf1b4 == 1) {
    angle = (unsigned short)f_0de8c0(d_1c0004) / 0xb6;
    angle = ((angle + 0xb4) % 0x168) * 0xb6;
    f_0de8d0(d_1c0004, angle);
  }
  if (get_1bfb1c()) f_121fd0();
  {
    int j;
    for (i = 0; (j = i) < 6; i++) {
      j *= 0x61;
      if (f_0de7c0((int)(d_1bfdbc + j)) && f_0de800((int)(d_1bfdbc + j)) == id) {
        f_0de810((int)(d_1bfdbc + j), -1);
      }
    }
  }
}


//@ f_0b9890
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchläuft je nach Parameter p1 (1 für die Tabelle d_1a52b4, sonst d_1a52be) eine
 *   -1-terminierte Liste von Gebäudekennungen und setzt in deren unter 0x220003 gespeichertem 8-Byte-Statusblock
 *   (f_11ea00 / f_11ea90) das zweite 32-Bit-Wort (buf[1]) auf 0 zurück.
 * - Eingaben: Die Funktion nimmt die Tabellenauswahl p1 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b9890(int p1)
{
  int o = OBJ(0x4dc);
  short *ps;
  short *base;
  short k;
  short sv;
  short p3;
  int buf[2];
  if ((short)p1 == 1) ps = d_1a52b4;
  else ps = d_1a52be;
  base = ps;
  k = 0;
  sv = *ps;
  while ((p3 = sv) != -1) {
    f_11ea00(o, 0x220003, p3, (int)buf, 8);
    buf[1] = 0;
    f_11ea90(o, 0x220003, p3, (int)buf, 8);
    k = k + 1;
    sv = base[k];
  }
  DEL(o);
}
