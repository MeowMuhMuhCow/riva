/* === Beschreibung (Katalog) ===
 * Einheit cmask4 (04dbf0 - 04ee60)
 *
 * Überblick
 * Diese Einheit bildet den vierten Teil des Heldenbogens (cmask4.cpp, in Quelle/cpp/p3/CMASK4_P1.CPP zusammen
 * mit dem früher getrennt geführten Abschnitt gz_04e470 von 04e470 bis 04ee60) und steuert zentrale
 * Interaktionen in der Charakter- und Inventarmaske. Sie verarbeitet das Aufnehmen, Ablegen, Tauschen,
 * Untersuchen und Benutzen von Gegenständen im Inventar (f_04dbf0), den Wechsel zum nächsten Helden (f_04e020),
 * die periodische Schmerzensschrei- und Blink-Animation verwundeter oder kranker Helden (f_04e0a0), das Öffnen
 * der gesamten Charaktermaske (f_04e350), das vollständige Neuzeichnen aller fünf Heldenbogen-Reiter (f_04e470)
 * sowie die Umbenennung eines Helden (f_04ed90).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 3/5 gleich (suche.py 24.10.2026, Basis cmask4_P1.CPP)
// cmask4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04DBF0-0x04E470
#include <string.h>
#include <stdlib.h>
extern char d_1bc930; // zusammengelegt: Typ aus Teil 2
typedef int T43;
typedef signed char TD;
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e0c0();                                         // reg - stapel 0
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_033db0(int p1, int p2);                           // reg eax edx stapel 0
int f_0352c0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_039110(int p1, int p2);                           // reg eax edx stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_03d790(int p1, int p2);                           // reg eax edx stapel 0
int f_03d7d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_042380(int p1);                                   // reg eax stapel 0
char f_042470(int p1);                                   // reg eax stapel 0
char f_0424d0(int p1);                                   // reg eax stapel 0
char f_0424e0(int p1);                                   // reg eax stapel 0
signed char f_0425f0(int p1);                                   // reg eax stapel 0
TD f_042900(int p1);                                   // reg eax stapel 0
TD f_042910(int p1);                                   // reg eax stapel 0
char f_042950(int p1);                                   // reg eax stapel 0
short f_042a60(int p1, int p2);                           // reg eax edx stapel 0
T43 f_043170(int p1);                                   // reg eax stapel 0
signed char f_043820(int p1, int p2);                           // reg eax edx stapel 0
int f_04a890(int p1);                                   // reg eax stapel 0
int f_04ad40(int p1, int p2);                           // reg eax stapel 0
int f_04aef0(int p1, int p2);                           // reg eax edx stapel 0
int f_04af60(int p1);                                   // reg eax stapel 0
int f_04af80(int p1);                                   // reg eax stapel 0
int f_04b050(int p1, int p2);                           // reg eax edx stapel 0
int f_04b0d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_04b3a0(int p1);                                   // reg eax stapel 0
int f_04d150(int p1);                                   // reg eax stapel 0
int f_04f3f0(int p1, int p2);                           // reg eax edx stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0c04b0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d37e0();                                         // reg - stapel 0
int f_0d3800();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
short f_0d4ad0(int p1);                                   // reg eax stapel 0
short f_0d4b00(int p1);                                   // reg eax stapel 0
short f_0de7f0(int p1);                                   // reg eax stapel 0
int f_0e3370(int p1);                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
int f_134840(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_1348d0();                                         // reg - stapel 0
short f_13bb70(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern short d_1a9668;                    // 0x1A9668
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc760;                    // 0x1BC760
extern int d_1bc890;                    // 0x1BC890
extern int d_1bc8f4;                    // 0x1BC8F4
 /* zusammengelegt: extern volatile char (*(volatile char *)&d_1bc930); */                    // 0x1BC930
extern int d_1bc934;                    // 0x1BC934
extern int d_1bc938;                    // 0x1BC938
extern unsigned short d_1bc93c;                    // 0x1BC93C
extern unsigned char d_1bc93e;                    // 0x1BC93E
extern int d_1c0004;                    // 0x1C0004
extern short d_1c2198;                    // 0x1C2198
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3914;                    // 0x1C3914
extern const char d_1a1368[];           // Text 0x1A1368
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_04dbf0  groesse 1072 B, 370 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Anklicken oder Bestätigen (Enter) eines Inventarslots im Heldenbogen: Je nach
 *   Modus und gedrückten Zusatztasten wird ein Gegenstand aufgenommen, mit einem zweiten Slot getauscht oder
 *   gestapelt (f_032ab0), an einen anderen Helden übergeben (f_0352c0), untersucht (f_03d790 / f_03d7d0),
 *   benutzt (f_03d820, Slot 32) oder im Mülleimer-Slot (Slot 31, f_033db0) weggeworfen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p (struct O *) entgegen und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->s20 speichert den aktuell hervorgehobenen Inventarslot, p->s22 den für eine
 *   Verschiebung ausgewählten Quellslot (-1, wenn kein Gegenstand am Mauszeiger hängt), p->b den aktuell
 *   angezeigten Helden und p->c den ursprünglichen Besitzer beim Heldenwechsel während eines Transfers.
 === Ende Beschreibung === */
//@ f_04e020  groesse 128 B, 35 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet im Heldenbogen auf das nächste Gruppenmitglied weiter und merkt sich bei einem
 *   bereits aufgenommenen Gegenstand (p->s22 != -1) den ursprünglichen Besitzer in p->c, damit der Gegenstand
 *   anschließend an den neu gewählten Helden übergeben werden kann.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Auf den Talent-/Zauberreitern (p->k > 3) sucht f_039110 den nächsten passenden Helden in
 *   der Gruppe d_1c0004, auf den übrigen Reitern f_0391b0; der neue Heldenzeiger wird in p->b und d_1bc8f4
 *   eingetragen.
 === Ende Beschreibung === */
//@ f_04e0a0  groesse 672 B, 329 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im Hintergrund des geöffneten Heldenbogens periodisch, ob der angezeigte Held unter
 *   schweren Zuständen leidet (Vergiftung, Krankheit, Hunger/Durst, Versteinerung oder kritischer Schaden),
 *   lässt das Warnsymbol oben rechts blinken und spielt in größeren Zeitabständen geschlechtsabhängige Stöhn-
 *   oder Schmerzenslaute über das Soundsystem ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p entgegen und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die globalen Zeitstempel d_1bc934 und d_1bc938 vergleichen den Systemtimer d_1c3914 für
 *   das Blinkintervall (> 0x12 Ticks) und das Soundintervall (> 1000 Ticks), während f_147323 die Samples
 *   0x3000c bis 0x3000f abspielt.
 === Ende Beschreibung === */
//@ f_04e340  groesse 16 B, 3 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet auf den ersten beiden Reitern des Heldenbogens zwischen der Standard-Werteanzeige und
 *   der alternativen Rüstungs-/Detailansicht (d_1bc930) um und markiert den Teilbereich zum Neuzeichnen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das globale Flag d_1bc930 wird per XOR (^= 1) umgeschaltet und das
 *   Teil-Neuzeichnungsflag p->c1f auf 1 gesetzt.
 === Ende Beschreibung === */
//@ f_04e350  groesse 2624 B, 86 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet aus dem laufenden Spiel heraus das Heldenbogen-Hauptfenster für den aktuell
 *   ausgewählten Helden der Gruppe (sofern die Gruppe mindestens ein Mitglied hat) oder zeigt andernfalls eine
 *   Fehlermeldung an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Sie prüft d_1a9668, d_1c0004 und die Gruppenstärke f_0de7f0(d_1c0004), legt ein
 *   CmaskObj909-Fensterobjekt auf dem Heap an und startet dessen Hauptschleife f_04f3f0 mit dem aktuellen Helden
 *   f_038c80(d_1c0004).
 === Ende Beschreibung === */
#pragma aux f_147323 modify [esp];
struct MG { int x; MG(); ~MG(); };
struct CmaskObj909 { char b[0x128]; CmaskObj909(); ~CmaskObj909(); void f_04f3f0(int); };
struct CmaskS20909 { char b[0x20]; CmaskS20909(int,int,int,int,int); ~CmaskS20909(); };
struct O {
  signed char k; char a1[2]; char c3; char c4; char a5[4];
  short s9; int b; int c; char a13[10];
  short s1d; char c1f; short s20; short s22; char a24[2]; short s26;
  char a28[0xee]; int i116; int i11a;
};
//@ f_04dbf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet das Anklicken oder Bestätigen (Enter) eines Inventarslots im Heldenbogen: Je nach
 *   Modus und gedrückten Zusatztasten wird ein Gegenstand aufgenommen, mit einem zweiten Slot getauscht oder
 *   gestapelt (f_032ab0), an einen anderen Helden übergeben (f_0352c0), untersucht (f_03d790 / f_03d7d0),
 *   benutzt (f_03d820, Slot 32) oder im Mülleimer-Slot (Slot 31, f_033db0) weggeworfen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p (struct O *) entgegen und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p->s20 speichert den aktuell hervorgehobenen Inventarslot, p->s22 den für eine
 *   Verschiebung ausgewählten Quellslot (-1, wenn kein Gegenstand am Mauszeiger hängt), p->b den aktuell
 *   angezeigten Helden und p->c den ursprünglichen Besitzer beim Heldenwechsel während eines Transfers.
 === Ende Beschreibung === */
void f_04dbf0(O *p)
{
  int changed = 0;
  int old[2];
  short saved;
  if (p->s22 != -1) {
    if (p->s1d != (short)0 && p->c != p->b) {
      int r902a=d_1a34e0, r902b=d_1a9820, r902c=d_1bc760;
      short mode902 = p->s22;
      d_1a34e0=r902a; d_1a9820=r902b; d_1bc760=r902c; *(unsigned int *)&d_1a34e0=r902a; *(unsigned int *)&d_1a9820=r902b; *(unsigned int *)&d_1bc760=r902c; d_1a34e0=r902a; d_1a9820=r902b; d_1bc760=r902c; *(unsigned int *)&d_1a34e0=r902a; *(unsigned int *)&d_1a9820=r902b; *(unsigned int *)&d_1bc760=r902c;; // Haelt die Registerbelegung fuer mode902
      if (mode902 < (short)31) {
        d_1bc890 = 0;
        if (p->k == 1) {
          old[0] = f_043170(p->b);
          old[1] = f_043170(p->c);
        }
        saved = p->s9;
        f_04af60((int)p);
        if (f_0352c0(p->b, p->c, p->s20, p->s22)) {
          if (d_1bc890 == 0 && p->k == 1 &&
              ((short)old[0] != (short)f_043170(p->b) ||
               (short)old[1] != (short)f_043170(p->c)))
            d_1bc890 = 1;
          if (d_1bc890 == 0) {
            f_04d150((int)p);
            f_04b3a0((int)p);
            p->s1d = 0;
            p->c = p->b;
            changed = 1;
            goto moving_done;
          }
        } else {
          f_04aef0((int)p, saved);
          goto moving_done;
        }
      } else if (mode902 == (short)31) {
        saved = p->s9;
        f_04af60((int)p);
        f_033db0(p->c, p->s20);
        changed = 1;
        f_04aef0((int)p, saved);
        goto moving_done;
      } else if (mode902 == (short)32) {
        { unsigned short x902 = (unsigned char)p->b; *(unsigned char *)&p->b=x902; } // Haelt den ueberlappenden Byte-Store vor dem Aufruf
        f_03d820(p->b, p->c, p->s20);
      } else goto moving_done;
      d_1c2198 = 1;
moving_done:
      if (d_1c2198 != (short)0) {
        p->c = p->b;
        p->s1d = 0;
        f_04b3a0((int)p);
        return;
      }
      if (!changed) d_1c2198 = 1;
      return;
    }
    if (p->s22 < (short)31) {
      if (f_042a60(p->b, p->s20) == (short)0 &&
          f_042a60(p->b, p->s22) == (short)0) {
        changed = 1;
        goto static_done;
      }
      if (f_0d3800()) {
        f_0d37e0();
        f_04af60((int)p);
        if (p->s20 == p->s22) { unsigned short x902 = (unsigned char)p->s20; *(unsigned char *)&p->s20=x902; f_03d790(p->b, p->s20); } // Bricht den WORD-Cache vor dem Aufruf
        else f_03d7d0(p->b, p->s20, p->s22);
        d_1c2198 = 1;
      } else {
        CmaskS20909 *obj = new (mark(d_1a1368, 0xa2)) CmaskS20909(p->b, 0, 0, 0, 0);
        short result = f_13bb70((int)obj, f_042a60(p->b, p->s20),
                                 f_042a60(p->b, p->s22));
        delete obj;
        if (result != -1 && p->s20 != p->s22 &&
            f_0bf6f0((int)&d_1c2c64, 0x304005d) == 1) {
          f_04af60((int)p);
          f_03d7d0(p->b, p->s20, p->s22);
          d_1c2198 = 1;
        } else {
          saved = p->s9;
          d_1bc890 = (result = 0);
          f_04af60((int)p);
          if (f_032ab0(p->b, p->s20, p->s22)) {
            if (d_1bc890 == 0) {
              f_04d150((int)p);
              f_04b3a0((int)p);
              p->s1d = 0;
              changed = 1;
            } else d_1c2198 = 1;
          } else f_04aef0((int)p, saved);
        }
      }
    } else if (p->s22 == (short)31) {
      saved = p->s9;
      f_04af60((int)p);
      f_033db0(p->b, p->s20);
      changed = 1;
      f_04aef0((int)p, saved);
    } else if (p->s22 == (short)32) {
      f_03d820(p->b, p->b, p->s20);
      d_1c2198 = 1;
    }
static_done:
    if (d_1c2198 != (short)0) {
      f_04b3a0((int)p);
      *(short *)&p->c3 = 1;
      p->s1d = 0;
      return;
    }
    if (!changed) d_1c2198 = 1;
    return;
  }
  if (f_0d37e0()) {
    f_03d790(p->b, p->s20);
    d_1c2198 = 1;
    return;
  }
  p->s22 = p->s20;
  f_04b0d0((int)p, d_1a34e0, p->s22, 0xf9);
  f_04af80((int)p);
  if (f_042a60(p->b, p->s20)) {
    short index = f_042a60(p->b, p->s20);
    RivaItemDefinition **table = d_1c2c40;
    f_04aef0((int)p, table[index]->f_0a7800());
  }
  f_04b050((int)p, d_1a34e0);
}
//@ f_04e020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet im Heldenbogen auf das nächste Gruppenmitglied weiter und merkt sich bei einem
 *   bereits aufgenommenen Gegenstand (p->s22 != -1) den ursprünglichen Besitzer in p->c, damit der Gegenstand
 *   anschließend an den neu gewählten Helden übergeben werden kann.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Auf den Talent-/Zauberreitern (p->k > 3) sucht f_039110 den nächsten passenden Helden in
 *   der Gruppe d_1c0004, auf den übrigen Reitern f_0391b0; der neue Heldenzeiger wird in p->b und d_1bc8f4
 *   eingetragen.
 === Ende Beschreibung === */
void f_04e020(O *p)
{
  int iVar1;
  if (p->k > 3) {
    iVar1 = f_039110(d_1c0004, p->b);
  } else {
    iVar1 = f_0391b0(d_1c0004, p->b);
  }
  if (iVar1 != p->b) {
    ;
    if (p->s22 != -1) {
      if (!p->s1d) p->c = p->b;
      p->s1d = 1;
      p->s26 = -1;
      d_1bc8f4 = iVar1;
      p->b = iVar1;
    } else {
      p->b = iVar1;
      d_1bc8f4 = iVar1;
      p->c = iVar1;
      p->s1d = 0;
      f_04b3a0((int)p);
    }
    d_1c2198 = 1;
  }
}
//@ f_04e0a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im Hintergrund des geöffneten Heldenbogens periodisch, ob der angezeigte Held unter
 *   schweren Zuständen leidet (Vergiftung, Krankheit, Hunger/Durst, Versteinerung oder kritischer Schaden),
 *   lässt das Warnsymbol oben rechts blinken und spielt in größeren Zeitabständen geschlechtsabhängige Stöhn-
 *   oder Schmerzenslaute über das Soundsystem ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p entgegen und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die globalen Zeitstempel d_1bc934 und d_1bc938 vergleichen den Systemtimer d_1c3914 für
 *   das Blinkintervall (> 0x12 Ticks) und das Soundintervall (> 1000 Ticks), während f_147323 die Samples
 *   0x3000c bis 0x3000f abspielt.
 === Ende Beschreibung === */
void f_04e0a0(O *p)
{
    struct MG5 {
        int aktiv;
        MG5() { if (f_0d3860()==1) { f_0d2710(); aktiv=1; } else aktiv=0; }
        ~MG5() { if (aktiv==1) f_0d26e0(); }
    };
    if (!(d_1bc93e & 1)) {
        d_1bc93e |= 1;
        d_1bc934 = d_1c3914;
    }
    if (!(d_1bc93e & 2)) {
        d_1bc93e |= 2;
        d_1bc938 = *(volatile int *)&d_1c3914 + 1000;
    }
    if (f_042470(p->b) || f_0425f0(p->b) || f_042950(p->b) ||
        f_0424d0(p->b) || f_0424e0(p->b) || f_0d4ad0(p->b) ||
        f_0d4b00(p->b) || f_042900(p->b)>=100 || f_042910(p->b)>=100) {
        if (abs(d_1c3914-d_1bc934)>0x12) {
            if (abs(d_1c3914-d_1bc938)>1000) {
                d_1bc938=d_1c3914;
                if (f_043820(p->b,2)==-1) {
                    int z = f_042380(p->b);
                    if (z==0) {
                        int snd;
                        f_147323((int)&d_1c2edc,0x3000d,0x7fff,0x8000,(snd=d_1a9820),z,1);
                    } else {
                        int snd;
                        f_147323((int)&d_1c2edc,0x3000c,0x7fff,0x8000,(snd=d_1a9820),0,1);
                    }
                } else if (f_043820(p->b,3)==-1) {
                    int z = f_042380(p->b);
                    if (z==0) {
                        int snd;
                        f_147323((int)&d_1c2edc,0x3000f,0x7fff,0x8000,(snd=d_1a9820),z,1);
                    } else {
                        int snd;
                        f_147323((int)&d_1c2edc,0x3000e,0x7fff,0x8000,(snd=d_1a9820),0,1);
                    }
                }
            }
            d_1bc934=d_1c3914;
            if (!f_0e3370((int)&d_1c2c64) &&
                !f_0c04b0((int)&d_1c2c64,0x104,4,0x118,0x19)) {
                MG5 m;
                if ((short)d_1bc93c==0) {
                    ((RivaRasterImage*)(p->i116))->f_0fae30((void *)(d_1a34e0),0x104,4,1);
                    d_1bc93c=1;
                } else {
                    ((RivaRasterImage*)(p->i11a))->f_0fade0((void *)(d_1a34e0),0x104,4);
                    d_1bc93c=0;
                }
            }
        }
    }
}
//@ f_04e340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet auf den ersten beiden Reitern des Heldenbogens zwischen der Standard-Werteanzeige und
 *   der alternativen Rüstungs-/Detailansicht (d_1bc930) um und markiert den Teilbereich zum Neuzeichnen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das globale Flag d_1bc930 wird per XOR (^= 1) umgeschaltet und das
 *   Teil-Neuzeichnungsflag p->c1f auf 1 gesetzt.
 === Ende Beschreibung === */
void f_04e340(O *p)
{
  (*(volatile char *)&d_1bc930) ^= 1;
  p->c1f = 1;
}
//@ f_04e350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet aus dem laufenden Spiel heraus das Heldenbogen-Hauptfenster für den aktuell
 *   ausgewählten Helden der Gruppe (sofern die Gruppe mindestens ein Mitglied hat) oder zeigt andernfalls eine
 *   Fehlermeldung an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Sie prüft d_1a9668, d_1c0004 und die Gruppenstärke f_0de7f0(d_1c0004), legt ein
 *   CmaskObj909-Fensterobjekt auf dem Heap an und startet dessen Hauptschleife f_04f3f0 mit dem aktuellen Helden
 *   f_038c80(d_1c0004).
 === Ende Beschreibung === */
void f_04e350()
{
  char l10[4];
  MG lc;
  if (d_1a9668 && d_1c0004 && f_0de7f0(d_1c0004) > 0) {
      f_09a140(0, 0x19);
      if (d_1bc760 != 0) f_01e0c0();
      {
        f_0ce7c0((int)l10);
        CmaskObj909 *p1 = new (mark(d_1a1368, 0x1a3)) CmaskObj909;
        p1->f_04f3f0(f_038c80(d_1c0004));
        delete p1;
        f_0ce7e0((int)l10, 0);
      }
      f_09a140(0, 0x19);
      f_09a0d0(d_1a34e0);
  } else {
    if (!(d_1c0004 != 0 && f_0de7f0(d_1c0004) > 0)) f_0bf730((int)&d_1c2c64, 0x1c000001);
  }
}

// ===== Teil 2: gz_04e470 (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// P3 2/3 gleich (suche.py 25.10.2026, Basis gz_04e470_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 0 gleich (vorher 0), Rest 257 (vorher 259)
// gz_04e470.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x04E470-0x04EE60
// #include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen




// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern signed char d_1bfa78;                    // 0x1BFA78
extern int d_1c0004;                    // 0x1C0004
 /* zusammengelegt: extern int (*(int *)&d_1c2198); */                    // 0x1C2198
extern int d_1c27a8;                    // 0x1C27A8
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c2be0;                    // 0x1C2BE0
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3068;                    // 0x1C3068
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_01eb40(int); int f_01eb50(int); int f_040370(int, int); int f_040e90(int); int f_0422b0(int); int f_0422c0(int, int);
char f_042400(int); int f_042410(int); char f_042470(int); char f_0424d0(int); char f_0424e0(int); /* zusammengelegt: char ((char)f_0425f0(int)); */
unsigned short f_0428b0(int); short f_0428c0(int); signed char f_0428d0(int); int f_0428f0(int); char f_042950(int);
#pragma aux f_0428b0 modify exact [eax ebx ecx edx];
 /* zusammengelegt: unsigned short ((unsigned short)f_042a60(int, int)); */ short f_042ac0(int, int); int f_042bb0(int, int); int f_044ea0(int); int f_04aef0(int, int);
int f_04af80(int); int f_04b0d0(int, int, int, int); int f_04c7e0(int); int f_04cbc0(int); int f_04cdc0(int); int f_04cdd0(int);
int f_04cff0(int); int f_04d4d0(int); int f_04d730(int); int f_04d9b0(int);
int f_04feb0(int, int, int, int, int, int, int, int, int);
int f_05ded0(int, int); short f_0e9690(int, int); int f_05e320(int, int, int); int f_05e820(int, int);
int f_05e830(int, int, int); int f_05e840(int, int); int f_068f40(); void __cdecl f_099ef0(void *, int, int);  
int f_0bf730(int, int); short f_0bfea0(int, int, int); int f_0d26e0(); int f_0d2710(); int f_0d3860(); short f_0d4ad0(int);
short f_0d4b00(int); int f_0d5a90(); int f_0de7e0(int); int f_0e9510(int, int, int, int); int f_0e9660(int, int, int, int);
  
   int f_125400(int, int, int, int); int f_1254a0(int, int);
int f_133fe0(int, int); char f_145400(int); int f_145450(int); int f_145a40(int, int, int); int f_145b40(int);
int f_148450(int, int, int, int, int); char *f_148518(int, char *, int);
/* nach vorn: extern char d_1bc930; */ extern char d_1bfaec; extern signed char d_1c299c[]; extern char d_1c21b4[];
struct XY { short x, y; };
extern XY d_1a0f50[];
struct P { char k; char pad1[6]; char a7[2]; short f09; int f0b; int f0f; char pad13[12]; char f1f; short f20; short f22;
  char pad24[0x23]; char a47[0xa3]; int fea, fee, ff2, ff6, ffa, ffe; char pad102[0x10]; int f112; char pad116[4]; int f11a; int f11e; };
struct Obj { char x[16]; char *m10; char *m14; char *m18; };
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_04e470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das komplette Heldenbogen-Fenster für den aktuellen Reiter (p1->k von 1 bis 5) neu:
 *   Auf den Inventarreitern (k < 3) werden Porträt, Name, Typus, Lebensdaten (Stufe, Abenteuerpunkte, Gold,
 *   Größe, Gewicht, Krankheits-/Giftstatus) sowie die Rucksackslots 15 bis 30 samt Stapelzahlen und beschädigten
 *   Gegenständen ausgegeben, anschließend wird die reiterspezifische Zeichenfunktion (f_04c7e0 bis f_04cff0)
 *   aufgerufen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p1 (struct P *) entgegen und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld p1->k wählt den aktiven Reiter (1 = Grundwerte/Körperinventar, 2 =
 *   Kampftalente/Rucksack, 3..5 = Talente und Zauber), p1->f0b verweist auf den angezeigten Helden, und d_1a0f50
 *   enthält die Bildschirmkoordinaten der Inventarslots.
 === Ende Beschreibung === */
void f_04e470(P *p1)
{
    int t178_6;
  int codex_arg_0_93;
  struct LocalObj { char x[16]; char *m10; char *m14; char *m18; char rest[0x20]; } o;
  int wasOld = 0;
  short setting1;
  short setting0;
  short setting2;
  short setting3;
  short i;
  int image;
  char *buffer;
  int result;
  f_125400((int)&o, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
  {
  struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    ~MG() { if (fl == 1) f_0d26e0(); }
  } mg;
  f_01eb40((int)&d_1c2bcc);
  if (d_1c2a80 != 0x30000 && d_1c2a80 != 0x30001) {
    ((RivaRasterImage*)(p1->fea))->f_0fb120();
    ((RivaRasterImage*)(p1->fea))->f_0fade0((void *)( d_1a34e0), 0, 0);
    wasOld = 1;
  }
  f_04af80((int)p1);
  f_05ded0((int)&d_1c3068, p1->f11e);
  setting0 = f_05e820((int)&d_1c38b0, 0);
  setting1 = f_05e820((int)&d_1c38b0, 1);
  setting2 = f_05e820((int)&d_1c38b0, 2);
  setting3 = f_05e820((int)&d_1c38b0, 3);
  if ((signed char)p1->k < 3 && (EQ((signed char)d_1bc930, 1) || (signed char)p1->f1f == 1)) f_04d4d0((int)p1);
  f_05e320((int)&d_1c38b0, 0xff, -1);
  d_1c2a80 = (signed char)p1->k >= 3 ? 0x30001 : 0x30000;
  f_145a40((int)p1->a47, d_1c2a80, p1->f11e);
  f_099ef0((void *)f_145b40((int)p1->a47), 0, 0x100);
  ((RivaRasterImage*)(p1->f11a))->f_0fafb0((void *)( p1->f11e), 0x104, 4);
  if (wasOld == 1) ((RivaRasterImage*)(p1->ffe))->f_0fafb0((void *)( p1->f11e), 0x43, 0x14);
  f_05e320((int)&d_1c38b0, 0xf9, -1);
  f_0e9660((int)&d_1c38b0, f_0422b0(p1->f0b), 0x59, 4);
  f_05e320((int)&d_1c38b0, 0xff, -1);
  f_0e9510((int)&d_1c38b0, f_040e90(p1->f0b), 0x59, 0xc);
  if ((signed char)p1->k < 3) {
    ((RivaRasterImage*)((codex_arg_0_93 = p1->fee)))->f_0fb060((void *)( f_044ea0(p1->f0b)));
    ((RivaRasterImage*)(p1->fee))->f_0fade0((void *)( p1->f11e), 0xc, 0x10);
    ((RivaRasterImage*)(p1->ffa))->f_0fae30((void *)( p1->f11e), 0x43, 0x14, 1);
    signed char state;
    if ((state = d_1bc930) == 1 && (signed char)p1->f1f == 0) {
      ((RivaRasterImage*)(p1->ff6))->f_0fae30((void *)( p1->f11e), 0x55, 0x22, 1);
  } else {
    f_05e830((int)&d_1c38b0, 0x87, 0);
    f_0e9510((int)&d_1c38b0, 0x3040029, 0x5b, 0x41);
    f_0e9510((int)&d_1c38b0, 0x304002a, 0x5b, 0x48);
    *(int *)(o.m18 + 4) = f_0428f0(p1->f0b);
    f_0e9510((int)&d_1c38b0, 0x3040021, 0x5b, 0x56);
    *(short *)(o.m14 + 2) = (short)f_0428d0(p1->f0b);
    f_0e9510((int)&d_1c38b0, 0x304001f, 0x5b, 0x5d);
    if (f_042400(p1->f0b)) f_040370((int)&d_1c27a8, f_042410(p1->f0b)); else f_040370((int)&d_1c27a8, f_0de7e0(d_1c0004));
    *(int *)(o.m10 + 4) = f_133fe0((int)&d_1c3498, (int)&d_1c27a8);
    f_0e9510((int)&d_1c38b0, 0x3040020, 0x5b, 0x6b);
    *(unsigned short *)(o.m14 + 2) = (unsigned char)f_0428b0(p1->f0b);
    f_0e9510((int)&d_1c38b0, 0x304001d, 0x5b, 0x80);
    *(short *)(o.m14 + 2) = f_0428c0(p1->f0b);
    f_0e9510((int)&d_1c38b0, 0x304001e, 0x5b, 0x87);
    f_05e840((int)&d_1c38b0, 0);
    if (f_042470(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040022, 0x5b, 0x95);
    else if (((char)f_0425f0(p1->f0b))) f_0e9510((int)&d_1c38b0, 0x3040027, 0x5b, 0x9c);
    else if (f_042950(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040028, 0x5b, 0xa3);
    if (f_0424d0(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040023, 0x5b, 0xaa);
    if (f_0424e0(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040024, 0x5b, 0xb1);
    if (f_0d4ad0(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040026, 0x5b, 0xb8);
    if (f_0d4b00(p1->f0b)) f_0e9510((int)&d_1c38b0, 0x3040025, 0x5b, 0xbf);
    f_05e840((int)&d_1c38b0, 1);
    }
    image = ((int)(((RivaRasterImage*)(p1->ff2))->f_0fb0b0()));
    buffer = p1->a7;
    i = 15;
    for (; i < 31; i++) {
      if (((unsigned short)f_042a60(p1->f0b, i))) {
        f_04feb0((int)&d_1c2be0, 0x50002, image, 0,
          d_1c2c40[(short)((unsigned short)f_042a60(p1->f0b, i))]->f_0a7800(), 0, (int)buffer, (int)buffer, 0x140);
        ((RivaRasterImage*)(p1->ff2))->f_0fade0((void *)( p1->f11e), (short)(d_1a0f50[i].x + 1), (short)(d_1a0f50[i].y + 1));
        if (d_1c2c40[(short)((unsigned short)f_042a60(p1->f0b, i))]->f_0a7950()) {
          f_05e320((int)&d_1c38b0, 0xff, 0);
          f_148518(f_042ac0(p1->f0b, i), d_1c21b4, 10);
          f_0e9660((int)&d_1c38b0, (int)d_1c21b4,
            (short)(d_1a0f50[i].x + 15 - f_0e9690((int)&d_1c38b0, (int)d_1c21b4)),
            (short)(d_1a0f50[i].y + 8));
          f_05e320((int)&d_1c38b0, 0xff, -1);
        }
        if (f_042bb0(p1->f0b, i) == 1) {
          f_04feb0((int)&d_1c2be0, 0x50002, image, 0, 1000, 0, (int)buffer, (int)buffer, 0x140);
          ((RivaRasterImage*)(p1->ff2))->f_0fae30((void *)( p1->f11e), (short)(d_1a0f50[i].x + 1), (short)(d_1a0f50[i].y + 1), 1);
        }
        f_04b0d0((int)p1, p1->f11e, i, 0);
      }
    }
  } else {
    ((RivaRasterImage*)(p1->fee))->f_0fb060((void *)( f_044ea0(p1->f0b)));
    ((RivaRasterImage*)(p1->fee))->f_0fade0((void *)( p1->f11e), 10, 3);
  }
  switch (p1->k) {
  case 1: f_04c7e0((int)p1); break;
  case 2: f_04cbc0((int)p1); break;
  case 3: f_04cdc0((int)p1); break;
  case 4: f_04cdd0((int)p1); break;
  case 5: f_04cff0((int)p1); break;
  }
  if ((signed char)p1->k >= 3) {
    f_148450(p1->f11e, 0x6b, 0x28, 0xa0, -1);
    f_148450(p1->f11e, 0xd4, 0x28, 0xa0, -1);
  }
  f_05ded0((int)&d_1c3068, d_1a34e0);
  f_05e830((int)&d_1c38b0, setting0, 0);
  f_05e830((int)&d_1c38b0, setting1, 1);
  f_05e830((int)&d_1c38b0, *(short *)(signed char *)&setting2, 2);
  f_05e830((int)&d_1c38b0, setting3, 3);
  if ((signed char)p1->f1f == 1 && (signed char)p1->k < 3) {
    ((RivaRasterImage*)(p1->f112))->f_0fade0((void *)( d_1a34e0), 0, 0xc0);
    signed char state;
    if ((state = d_1bc930) == 1) f_04d9b0((int)p1);
    else f_04d730((int)p1);
  } else {
    ((RivaRasterImage*)(p1->fea))->f_0fade0((void *)( d_1a34e0), 0, 0);
  }
  p1->f1f = 0;
  if ((signed char)p1->k < 3) ((RivaRasterImage*)(p1->f112))->f_0fafb0((void *)( d_1a34e0), 0, 0xc0);
  if ((t178_6 = p1->f20) != -1 && p1->f0f == p1->f0b && (signed char)p1->k < 3) f_04b0d0((int)p1, d_1a34e0, p1->f20, 0xfd);
  if (p1->f22 != -1 && (signed char)p1->k < 3) f_04b0d0((int)p1, d_1a34e0, p1->f22, 0xf9);
  signed char state;
  if (!(state = d_1bc930) && (signed char)p1->k < 3) f_01eb50((int)&d_1c2bcc);
  }
  f_1254a0((int)&o, 0);
}
//@ f_04ed40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt während der Heldenbogen-Schleife die periodische System- und Eingabeaktualisierung aus,
 *   erkennt einen externen Heldenwechsel (d_1bfaec) und stellt den Mauszeiger für einen aufgenommenen Gegenstand
 *   wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Heldenbogen-Objekt p1 und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Verglichen wird der gespeicherte Gruppenindex d_1bfaec; hat er sich bei aktivem Flag
 *   d_1bfa78 == 1 geändert, wird auf Reiter 1 zurückgeschaltet und d_1c2198 = 1 gesetzt.
 === Ende Beschreibung === */
void f_04ed40(P *p1)
{
  char c = d_1bfaec;
  char current;
  f_068f40();
  f_0d5a90();
  if (*(int *)&d_1bfa78 == 1) {
    current = d_1bfaec;
    if (c != current) {
      p1->k = 1;
      *(short *)&(*(int *)&d_1c2198) = 1;
    }
    if (p1->f09 != -1) f_04aef0((int)p1, p1->f09);
  }
}
//@ f_04ed90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt dem Spieler im Heldenbogen das Umbenennen des aktuellen Helden über ein
 *   Texteingabefeld (sofern es sich nicht um einen nicht umbenennbaren NPC handelt) und formatiert den neuen
 *   Namen automatisch mit großen Anfangsbuchstaben je Wort.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger auf das Heldenbogen-Objekt p1 entgegen und gibt als int
 *   den Wert 1 zurück, wenn der Name geändert wurde, sonst 0.
 * - Wichtige Variablen: Bei gesetztem NPC-Flag f_042400(p1->f0b) wird die Meldung 0x3040037 angezeigt;
 *   andernfalls liest f_0bfea0 den neuen Namen in d_1c299c ein, wandelt Wortanfänge über f_145400 in
 *   Großbuchstaben um, entfernt nachgestellte Leerzeichen und speichert den Namen mit f_0422c0.
 === Ende Beschreibung === */
int f_04ed90(P *p1)
{
  short i;
  signed char c;
  int r = 0;
  if (!(!f_042400(p1->f0b))) {
    f_0bf730((int)&d_1c2c64, 0x3040037);
  } else {
    if (f_0bfea0((int)&d_1c2c64, 0xf, 0x3040038) != -1) {
      f_145450((int)d_1c299c);
      i = 1;
      d_1c299c[0] = f_145400((unsigned char)d_1c299c[0]);
      while (d_1c299c[i] != 0) {
        if (d_1c299c[i] == ' ' && d_1c299c[i + 1]) d_1c299c[i + 1] = f_145400((unsigned char)d_1c299c[i + 1]);
        i++;
      }
      i--;
      while (d_1c299c[i] == ' ') {
        d_1c299c[i] = 0;
        i--;
      }
      r = 1;
      f_0422c0(p1->f0b, (int)d_1c299c);
    }
  }
  return r;
}
