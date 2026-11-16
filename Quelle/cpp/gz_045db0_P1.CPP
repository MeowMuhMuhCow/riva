/* === Beschreibung (Katalog) ===
 * Einheit gz_045db0 (0x045db0 - 0x046bf0)
 *
 * Überblick
 * Die Einheit gz_045db0 enthält zum einen fünf virtuelle Methoden der in gz_0452a0 konstruierten
 * Schriftart-/Zeichenbreiten-Klasse (f_045db0 bis f_045e90) und zum anderen die zentrale Zeit- und
 * Regenerationssteuerung des Spiels (f_045ef0 bis f_046bc0): Sie verarbeitet das Verstreichen von Spielticks,
 * Minuten, Stunden und Tagen für alle Helden, lässt Fackeln und Laternen herunterbrennen, regeneriert Lebens-
 * und Astralpunkte, erhöht stündlich Hunger und Durst (inklusive automatischem Essen und Trinken aus dem
 * Gruppeninventar) und berechnet die für den nächsten Stufenanstieg nötigen Abenteuerpunkte.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -onatx -zp1 -s
// P3 18/21 gleich (suche.py 30.10.2026, Basis gz_045db0_P1.CPP)
// gz_045db0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x045DB0-0x046BF0
#include <string.h>
#pragma inline_depth(3)
#include "RIVAMEM.H"



int f_031020(int p1);
int f_032470(int p1, short *p2, short *p3);
int f_0324e0(int p1, short *p2, short *p3);
int f_036300(int p1, int p2, int p3);
int f_039cf0(int p1);
int f_040b90(int p1);




















int f_043380(int p1);
int f_043390(int p1, int p2);
int f_0434b0(int p1);
int f_0434e0(int p1, int p2);
int f_043520(int p1);
signed char f_043530(int p1);
int f_043560(int p1, int p2);
int f_043590(int p1, int p2);
int f_043e70(int p1);
int f_043f00(int p1);
int f_043f30(int p1);
signed char f_043f70(int p1);
signed char f_043f80(int p1);
int f_043f90(int p1, int p2);
signed char f_043fa0(int p1);
signed char f_043fb0(int p1);
int f_043fc0(int p1, int p2);
int f_0442b0(int p1, int p2, int p3, int p4);
int f_044300(int p1, int p2);
int f_044670(int p1);
int f_044890(int p1, int p2, int p3, int p4);
void f_060400();
void f_0605c0();
void f_0605e0();
void f_060680();
int f_0bf730(int *p1, int p2);
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1, int p2);
int f_0d49b0(int p1);
short f_0d4aa0(int p1, int p2);
short f_0d4ad0(int p1);
short f_0d4b00(int p1);
short f_0d4b30(int p1);
short f_0d4b60(int p1);
void f_0d4d80(int p1, int p2);
int f_0d54c0(int p1);
short f_0d54f0(int p1, int p2);
int f_0dc110(int p1, int p2, short *p3, short *p4, short *p5);
int f_0dc1f0(int p1, int p2, short *p3, short *p4, short *p5);
short f_0de800(int p1);
short f_0de820(int p1);
int f_0e3360(int *p1);
void f_0ed520();
void f_0ed740();
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_134840(void *p1, int p2, int p3, int p4, int p5, int p6);
void f_1348d0(void *p1, int p2);
int f_13bc30(void *p1);
short f_1457e0(int p1);
extern int d_1a9670;
extern short d_1bbfdc[];
extern int d_1bc8f0;
extern char d_1bc8fc;
extern short d_1bc8fd;
extern int d_1bd90c;
extern char d_1bfaec;
extern char d_1bfdbc[];
extern int d_1c0004;
extern int d_1c0c4c;
extern int d_1c0c58;
extern volatile int d_1c0c60;
extern volatile int d_1c0c64;
extern volatile int d_1c0c68;
extern volatile int d_1c0c6c;
extern volatile int d_1c0c70;
extern int d_1c0c7c;
extern volatile int d_1c0c8c;
extern signed char d_1c1070;
extern short d_1c11d0[];
extern unsigned short d_1c20b2;
extern volatile short d_1c212a;
extern char **d_1c212c;
extern short d_1c2198;
extern int d_1c21b0;
extern int d_1c2a80;
extern int d_1c2c64;
extern char d_1c349c;
extern char d_1c3870;
extern int d_1c3498;
struct Ev { int w0; int *p; char rest[52]; };
void f_0465c0(int p1, int p2);
void f_046b60(int p1, int p2);
void f_046540(int p1);
void f_046570(int p1);
void f_046590(int p1);
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_045db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die Pixelbreite eines darzustellenden Zeichens p2 zuzüglich 1 Pixel Zeichenabstand
 *   aus der Breitentabelle *(p1 + 0x416) des Schriftart-Objekts (Steuerzeichen 0xf0 bis 0xf7 haben die Breite
 *   0).
 * - Eingaben und Rückgabe: Die Funktion erhält das Schriftart-Objekt (p1) sowie den Zeichencode (p2) und gibt
 *   die Zeichenbreite in Pixeln als short zurück.
 * - Wichtige Variablen: Liest die Zeichenbreitentabelle über den Zeiger *(char)(p1 + 0x416).
 === Ende Beschreibung === */
short f_045db0(char *p1, unsigned char p2)
{
    short r = 0;
    if (p2 < 0xf0 || p2 > 0xf7) {
        r = *(unsigned short *)(*(char **)(p1 + 0x416) + p2 * 4);
        ++r;
    }
    return r;
}
//@ f_045de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Zeilenhöhe (p1[0x10]) des Schriftart-Objekts zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Schriftart-Objekt (p1) und gibt die Schrifthöhe als unsigned
 *   char zurück.
 * - Wichtige Variablen: Liest p1[0x10].
 === Ende Beschreibung === */
unsigned char f_045de0(char *p1)
{
    return p1[0x10];
}
//@ f_045df0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der Glyphentabelle ab p1 + 0x16, ob für den Zeichencode p2 eine gültige
 *   Buchstabengrafik im aktuellen Zeichensatz hinterlegt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält das Schriftart-Objekt (p1) sowie den Zeichencode (p2) und gibt 1
 *   zurück, wenn das Zeichen darstellbar ist, sonst 0.
 * - Wichtige Variablen: Vergleicht den Glyphenzeiger *(int*)(p1 + 0x16 + p2 * 4) mit dem Leerzeiger *(int*)(p1 +
 *   0x41a).
 === Ende Beschreibung === */
unsigned short f_045df0(char *p1, int p2)
{
    int r_ = 0;
    if (*(int *)(p1 + 0x16 + (((unsigned char)p2) << 2)) != *(int *)(p1 + 0x41a)) r_ = 1;
    return r_;
}
//@ f_045e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der Zeichentabelle d_1bbfdc (Bitmaske 0xc0), ob das Zeichen p2 ein druckbares
 *   Buchstaben- oder Sonderzeichen (bzw. ein darstellbares Umlautzeichen > 0x7f) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p1) sowie den Zeichencode (p2) und gibt 1 bei
 *   einem gültigen Zeichen zurück, sonst 0.
 * - Wichtige Variablen: Liest die Klassifikationstabelle d_1bbfdc.
 === Ende Beschreibung === */
int f_045e10(int *p1, unsigned char p2)
{
    int r = 0;
    int c = ((signed char *)d_1bbfdc)[(unsigned char)(p2 + 1)];
    if ((c & 0xc0) ||
        (p2 > 0x7f && ((int (**)(int *, int))*p1)[4](p1, p2) == 1))
        r = 1;
    return r;
}
//@ f_045e50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der Zeichentabelle d_1bbfdc (Bitmaske 0xe0, schließt zusätzlich
 *   Ziffern/Trennzeichen ein), ob das Zeichen p2 zum erweiterten druckbaren Zeichensatz gehört.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p1) sowie den Zeichencode (p2) und gibt 1 bei
 *   Zugehörigkeit zurück, sonst 0.
 * - Wichtige Variablen: Liest die Klassifikationstabelle d_1bbfdc.
 === Ende Beschreibung === */
int f_045e50(int *p1, unsigned char p2)
{
    int r = 0;
    int c = ((signed char *)d_1bbfdc)[(unsigned char)(p2 + 1)];
    if ((c & 0xe0) ||
        (p2 > 0x7f && ((int (**)(int *, int))*p1)[4](p1, p2) == 1))
        r = 1;
    return r;
}
//@ f_045e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das einzelne Schriftzeichen p2 an den Bildschirmkoordinaten (p3, p4) mit der Farbe p5
 *   über den Grafiktreiber *(p1 + 4) und rückt die interne X-Cursorposition *(short*)(p1 + 0x41e) um
 *   Zeichenbreite + 1 weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält das Schriftart-Objekt (p1), den Zeichencode (p2), die Koordinaten
 *   (p3, p4), die Farbe (p5) und den Modus (p6) und gibt die angerückte Breite (c + 1) als short zurück.
 * - Wichtige Variablen: Nutzt die Glyphentabelle p1 + 0x16, die Breitentabelle *(p1 + 0x416) und aktualisiert
 *   *(short*)(p1 + 0x41e).
 === Ende Beschreibung === */
short f_045e90(char *p1, unsigned char p2, short p3, short p4, int p5, short p6)
{
    unsigned char c = (*(unsigned char **)(p1 + 0x416))[p2 * 4]; int a2 = *(int *)(p1 + 0x16 + p2 * 4);
    (*(void (**)(char *, int, unsigned char, int, int, int, int, int))(*(char **)(*(char **)(p1 + 4) + 10) + 8))(*(char **)(p1 + 4), a2, c, *(short *)(p1 + 0x10), p3, p4, p5, p6);
    *(short *)(p1 + 0x41e) = p3 + c + 1;
    return c + 1;
}
//@ f_045ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert den globalen Spielstand-Datenblock d_1bc8fc (Wetter-/Begegnungsflag mit Kennung
 *   0x1b) in der Spielstands-Sektionsliste d_1c212c.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Trägt &d_1bc8fc in d_1c212c[d_1c212a] ein und erhöht d_1c212a.
 === Ende Beschreibung === */
void f_045ef0()
{
    d_1bc8fc = 0;
    d_1bc8fd = 0x1b;
    d_1c212c[d_1c212a] = &d_1bc8fc;
    ++d_1c212a;
}
//@ f_045f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht die seit dem letzten Aufruf verstrichene Anzahl an Spielticks (d_1c0c58) von allen 50
 *   globalen Cooldown-Timern im Array d_1c11d0 (z. B. Talent-Sperrzeiten in Tavernen) ab und begrenzt sie nach
 *   unten auf 0.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Dekrementiert die 50 Einträge in d_1c11d0 um d_1c0c58.
 === Ende Beschreibung === */
void f_045f30()
{
    short i;
    for (i = 0; i < (short)0x32; ++i) {
        ((volatile int *)d_1c11d0)[i] -= *(volatile int *)&d_1c0c58;
        if (((int *)d_1c11d0)[i] < 0)
            ((int *)d_1c11d0)[i] = 0;
    }
}
//@ f_045f80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die allgemeinen periodischen Welt-Updates aus (f_0605e0), würfelt bei gesetztem Flag
 *   d_1c0c8c mit 5 % Wahrscheinlichkeit (1W100 <= 5) das Ereignis-Flag d_1bc8fc neu aus und inkrementiert den
 *   laufenden Zähler d_1c1070.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Aktualisiert d_1bc8fc, d_1c0c8c und d_1c1070.
 === Ende Beschreibung === */
void f_045f80()
{
    f_0605e0();
    if (d_1c0c8c != 0) {
        d_1bc8fc = f_1457e0(100) <= 5;
        d_1c0c8c = 0;
    }
    if (d_1c1070 != 0 ? 1 : 0)
        ++d_1c1070;
}
//@ f_045fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet für einen einzelnen Helden (p2) die verstrichenen 5-Minuten-Intervalle (d_1c0c60),
 *   indem bei bestehenden Vergiftungen oder Krankheiten die Verlaufsfunktion f_039cf0 aufgerufen und die beiden
 *   Wirkungsdauer-Timer am Offset 0x9d (f_0434e0) und 0xa1 (f_043390, Trunkenheit) um je 0x1c2 (450) Ticks pro
 *   Einheit reduziert werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) sowie den Heldenzeiger (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Nutzt den Intervallzähler d_1c0c60.
 === Ende Beschreibung === */
void f_045fd0(int p1, int p2)
{
    int i;
    for (i = 0; i < d_1c0c60; i++) {
            if (!((char)(f_042470((struct hero *)(p2)))) && (f_0d4b00(p2) || f_0d4b60(p2))) {
                f_039cf0(p2);
                if ((unsigned)d_1c2a80 == 0x30000u || (unsigned)d_1c2a80 == 0x30001u)
                    d_1c2198 = 1;
            }
    }
    if (f_043520(p2) != 0)
        f_0434e0(p2, d_1c0c60 * 0x1c2);
    if (f_043380(p2))
        f_043390(p2, d_1c0c60 * 0x1c2);
}
//@ f_046090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet für einen Helden (p2) die verstrichenen Viertelstunden-/Regenerationsintervalle
 *   (d_1c0c64): Brennende Fackeln (0x16) werden nach Ablauf ihrer Brenndauer gelöscht (f_036300), ausgebrannte
 *   Laternen (0xf9) in unbeleuchtete Laternen (0x19) umgewandelt, und anschließend regenerieren gesunde,
 *   nüchterne Helden anteilig Astral- und Lebenspunkte über die Prozent-Akkumulatoren (f_043fb0/f_043f80, erhöht
 *   durch Rast-/Herbergs-Flags f_043e70, f_043f00, f_043f30).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) sowie den Heldenzeiger (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Intervallzähler d_1c0c64 und das Rast-Flag d_1bfaec.
 === Ende Beschreibung === */
void f_046090(int p1, int p2)
{
    short i;
    for (i = 0; i < 0x1f; i++) {
        if (f_042a60((struct hero *)(p2), i) == 0x16) {
            f_0430c0((struct hero *)(p2), i, (signed char)(((signed char)(f_043090((struct hero *)(p2), i))) - (signed char)d_1c0c64));
            if (((signed char)(f_043090((struct hero *)(p2), i))) <= 0) {
                f_036300(p2, i, 1);
                if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001)
                    d_1c2198 = 1;
            }
        } else if (f_042a60((struct hero *)(p2), i) == 0xf9) {
            f_0430c0((struct hero *)(p2), i, (signed char)(((signed char)(f_043090((struct hero *)(p2), i))) - (signed char)d_1c0c64));
            if (((signed char)(f_043090((struct hero *)(p2), i))) <= 0) {
                f_0430c0((struct hero *)(p2), i, 0);
                f_042a90((struct hero *)(p2), i, 0x19);
                if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001)
                    d_1c2198 = 1;
            }
        }
    }
    if (((char)(f_042470((struct hero *)(p2)))) || f_043380(p2) || f_0d4ad0(p2) || f_0d4b00(p2))
        return;

    short j;
    for (j = 0; j < d_1c0c64; j++) {
        if (f_042a10((struct hero *)(p2)) && f_0429a0((struct hero *)(p2)) < f_0429b0((struct hero *)(p2))) {
            signed char c = 6;
            c += f_043fa0(p2);
            unsigned char b = f_043fb0(p2);
            signed char flag = d_1bfaec;
            if ((int)flag == 0)
                c += 3;
            if (f_043e70(p2))
                c += 6;
            if (f_043f00(p2))
                c += 10;
            if (f_043f30(p2))
                c += 5;
            if (c > 0)
                b += c;
            while ((unsigned char)b >= 100) {
                b -= 100;
                ((int (*)(int,int))f_0442b0)(p2, 1);
            }
            f_043fc0(p2, b);
        }
        if (f_042960((struct hero *)(p2)) < f_042970((struct hero *)(p2))) {
            signed char c = 8;
            c += f_043f70(p2);
            unsigned char b = f_043f80(p2);
            signed char flag = d_1bfaec;
            if ((int)flag == 0)
                c += 4;
            if (f_043e70(p2))
                c += 6;
            if (f_043f00(p2))
                c += 10;
            if (f_043f30(p2))
                c += 5;
            if (c > 0)
                b += c;
            while ((unsigned char)b >= 100) {
                b -= 100;
                ((int (*)(int,int))f_044890)(p2, 1);
            }
            f_043f90(p2, b);
        }
    }
}
//@ f_046320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft alle sieben möglichen Heldenplätze im globalen Helden-Array d_1bc8f0 (Schrittweite
 *   0x5ef, unter Auslassung des Sonder-NPCs mit npc_id == 4) und ruft für jeden belegten Helden je nach
 *   verstrichenen Zeiteinheiten den Trunkenheitstest (f_040b90), den Buff-Tick (f_0d4d80), den 5-Minuten-Tick
 *   (f_045fd0), den Regenerations-Tick (f_046090), den Stunden-Tick (f_0465c0) sowie den Tages-Tick (f_046b60)
 *   auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Iteriert über das Helden-Array d_1bc8f0 anhand der globalen Zeitzähler d_1c0c58 bis
 *   d_1c0c7c.
 === Ende Beschreibung === */
void f_046320(int p1)
{
    int p = d_1bc8f0;
    short i;
    for (i = 0; i <= 6; i++, p += 0x5ef)
    {
        if (f_042350((struct hero *)(p))) {
            if (f_042400((struct hero *)(p)) != 4) {
                if (d_1c0c7c != 0) {
                    if (f_042950((struct hero *)(p)))
                        f_040b90(p);
                }
                f_0d4d80(p, d_1c0c58);
                if (d_1c0c60 != 0)
                    f_045fd0(p1, p);
                if (d_1c0c64 != 0)
                    f_046090(p1, p);
                if (d_1c0c68 != 0)
                    f_0465c0(p1, p);
                if (d_1c0c70 != 0)
                    f_046b60(p1, p);
            }
        }
    }
}
//@ f_0463e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bildet die zentrale Haupt-Zeitschleife des Spiels: Sofern die Zeit nicht pausiert ist
 *   (d_1c0c4c == 0) und kein rekursiver Aufruf vorliegt (*p1 == 0), zieht sie die verstrichenen Ticks von allen
 *   Cooldowns ab, aktualisiert sämtliche Helden über f_046320, stößt die Welt-, Stunden- und Tagesereignisse
 *   (f_060680, f_046540, f_046570, f_046590) an und setzt anschließend alle aufgelaufenen Zeitzähler (d_1c0c58
 *   bis d_1c0c7c) wieder auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Reentranz-Sperrflag (p1) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Steuert und leert die globalen Zeitzähler d_1c0c58, d_1c0c60, d_1c0c64, d_1c0c68,
 *   d_1c0c6c, d_1c0c70 und d_1c0c7c.
 === Ende Beschreibung === */
void f_0463e0(int *p1)
{
    if (d_1c0c4c == 0 && *p1 == 0) {
        short i;
        *p1 = 1;
        for (i = 0; i < (short)0x32; i++) {
            ((volatile int *)d_1c11d0)[i] -= *(volatile int *)&d_1c0c58;
            if (((int *)d_1c11d0)[i] < 0)
                ((int *)d_1c11d0)[i] = 0;
        }
        f_046320((int)p1);
        f_060680();
        if (d_1c0c60 != 0) {
            f_0605e0();
            if (d_1c0c8c != 0) {
                d_1bc8fc = f_1457e0(100) <= 5;
                d_1c0c8c = 0;
            }
            if ((d_1c1070 != 0) ? 1 : 0)
                ++d_1c1070;
            if (d_1c0c68 != 0)
                f_046540((int)p1);
            if (d_1c0c6c != 0)
                f_046570((int)p1);
            if (d_1c0c70 != 0)
                f_046590((int)p1);
            d_1c0c70 = 0;
            d_1c0c6c = d_1c0c70;
            d_1c0c68 = d_1c0c6c;
            d_1c0c64 = d_1c0c68;
            d_1c0c60 = d_1c0c64;
            d_1c0c7c = 0;
        }
        d_1c0c58 = 0;
        *p1 = 0;
    }
}
//@ f_046520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert das Zeitsteuerungs-Objekt (p1), indem das Reentranz-Sperrflag *p1 auf 0 gesetzt
 *   wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p1) sowie einen ungenutzten Parameter (p2) und
 *   gibt p1 zurück.
 * - Wichtige Variablen: Setzt *p1 = 0.
 === Ende Beschreibung === */
int *f_046520(int *p1, int p2)
{
    *p1 = 0;
    return p1;
}
//@ f_046530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion (Destruktor-Stub des Zeitsteuerungs-Objekts).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Greift auf keine Variablen zu.
 === Ende Beschreibung === */
void f_046530()
{
}
//@ f_046540
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt für jede verstrichene Spielstunde (d_1c0c68) die stündlichen Welt- und Quest-Updates
 *   (f_060400 und f_0ed520) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Stundenzähler d_1c0c68.
 === Ende Beschreibung === */
void f_046540(int p1)
{
    short i;
    for (i = 0; i < d_1c0c68; i++) {
        f_060400();
        f_0ed520();
    }
}
//@ f_046570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft eine leere Schleife über die verstrichenen 6-Stunden-/Tageszeit-Intervalle
 *   (d_1c0c6c, Platzhalter ohne aktive Aufrufe).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Zähler d_1c0c6c.
 === Ende Beschreibung === */
void f_046570(int p1)
{
    short i;
    for (i = 0; i < d_1c0c6c; i++) { }
}
//@ f_046590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt für jeden verstrichenen Spieltag (d_1c0c70) die täglichen Stadt-, Händler- und
 *   Quest-Updates (f_0ed740 und f_0605c0) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Tageszähler d_1c0c70.
 === Ende Beschreibung === */
void f_046590(int p1)
{
    short i;
    for (i = 0; i < d_1c0c70; i++) {
        f_0ed740();
        f_0605c0();
    }
}

//@ f_0465c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet für einen Helden (p2) die stündlichen Auswirkungen (d_1c0c68): Trägt der Held
 *   verfluchte Stiefel (0xc5 in Slot 10), erleidet er 1 SP pro Stunde; danach steigen Hunger (f_043560) und
 *   Durst (f_043590, außer die Gruppe besitzt den Endlosen Brotbeutel 0xb8, den Trinkhorn-Gegenstand 0xb9 oder
 *   der Held trägt den Ring 0xaf). Überschreiten Hunger oder Durst 90 %, sucht der Held über f_0dc110/f_0dc1f0
 *   automatisch im eigenen oder im Gruppeninventar nach Proviant bzw. Getränken und verzehrt diese; bei 100 %
 *   Hunger oder Durst verliert er stündlich 1 LE über f_044670, und es wird eine passende Hunger-/Durstmeldung
 *   (0x2040025-0x204002e) ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) sowie den Heldenzeiger (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Stundenzähler d_1c0c68, das Rast-Flag d_1c21b0 und gibt Meldungen über
 *   d_1c2c64 aus.
 === Ende Beschreibung === */
void f_0465c0(int p1, int p2)
{
    short code;
    int count = 0; // Startwert steuert die Registerkopplung der Meldungskette wie im Original.
    Ev ev;
    signed char before;
    int origin;
    short y;
    short tmp;
    short x;
    short index;
    char right[32];
    char left[32];

    f_125400(&ev, &d_1c349c, &d_1c3870, &d_1c3498);
    origin = (int)(d_1bfdbc + (signed char)f_042430((struct hero *)(p2)) * 0x61);
    code = 0;
    unsigned short kind = (unsigned short)f_0de820(origin);
switch(kind){ case 7:case 8:case 9: f_1254a0(&ev,0); return; case 10:case 11: break; default: {
    int target = p2;
    if (f_0d49b0(p2)) {
        if (f_042a60((struct hero *)(p2), 10) == 0xc5)
            f_044300(p2, (short)d_1c0c68);
    }
    count = 0;
    for (; count < d_1c0c68; count++, f_0ce7e0(&tmp, 0)) {
        before = ((signed char)(f_0425f0((struct hero *)(p2))));
        if (!((char)(f_042470((struct hero *)(p2)))) && !((char)(f_0424e0((struct hero *)(p2))))) {
            if (f_0d54f0(origin, 0xb8) == -1) {
                if (f_0d4aa0(p2, 0xaf) == -1) {
                    if (f_042900((struct hero *)(p2)) > 90) {
                        if (((signed char)(f_0425f0((struct hero *)(p2)))))
                            *(char *)&d_1a9670 = (char)f_0d54c0(p2);
                        if (f_0dc110(origin, p2, &index, &x, &y)) {
                            target = d_1bc8f0 + index * 0x5ef;
                            f_134840(right, p2, target, x, y, 0);
                            f_13bc30(right);
                            if (p2 == target) {
                                if (!f_032470(p2, &x, &y))
                                    code = 6;
                                else if (f_042900((struct hero *)(p2)) < 100)
                                    code = 4;
                            } else {
                                code = 7;
                            }
                            f_1348d0(right, 0);
                        }
                    }
                    if (f_042900((struct hero *)(p2)) < 100) {
                        int motion = f_043530(p2);
                        int divisor = d_1c21b0 * 2 + 1;
                        if (motion <= 0)
                            f_043560(p2, (signed char)(2 / divisor));
                        else
                            f_043560(p2, (signed char)(1 / divisor));
                        if (f_042900((struct hero *)(p2)) > 100)
                            ((int)(f_042920((struct hero *)(p2), 100)));
                    } else if (f_043530(p2) <= 0) {
                        if (d_1c21b0 == 0)
                            f_044670(p2);
                        code = 2;
                    }
                } else {
                    ((int)(f_042920((struct hero *)(p2), 0)));
                }
            } else {
                ((int)(f_042920((struct hero *)(p2), 0)));
            }
            if (f_0d54f0(origin, 0xb9) == -1 && (int)f_0de820(origin) != 0) {
                if (f_0d4aa0(p2, 0xaf) == -1) {
                    if (f_042910((struct hero *)(p2)) > 90) {
                        if (((signed char)(f_0425f0((struct hero *)(p2)))))
                            *(char *)&d_1a9670 = (char)f_0d54c0(p2);
                        if (f_0dc1f0(origin, p2, &index, &x, &y)) {
                            int off = index * 0x5ef; int base = d_1bc8f0; target = base + off;
                            f_134840(left, p2, target, x, y, 0);
                            f_13bc30(left);
                            if (p2 == target) {
                                if (!f_0324e0(p2, &x, &y))
                                    code = 5;
                                else if (f_042910((struct hero *)(p2)) < 100)
                                    code = 3;
                            } else {
                                code = 8;
                            }
                            f_1348d0(left, 0);
                        }
                    }
                    if (f_042910((struct hero *)(p2)) < 100) {
                        int motion = f_043530(p2);
                        int divisor = d_1c21b0 * 2 + 1;
                        if (motion <= 0)
                            f_043590(p2, (signed char)(4 / divisor));
                        else
                            f_043590(p2, (signed char)(2 / divisor));
                        if (f_042910((struct hero *)(p2)) > 100)
                            ((int)(f_042930((struct hero *)(p2), 100)));
                    } else if (f_043530(p2) <= 0) {
                        if (d_1c21b0 == 0)
                            f_044670(p2);
                        code = 1;
                    }
                } else {
                    ((int)(f_042930((struct hero *)(p2), 0)));
                }
            } else {
                ((int)(f_042930((struct hero *)(p2), 0)));
            }
        }
        f_0ce7c0(&tmp);
        if (code != (short)0 && !f_0e3360(&d_1c2c64) &&
            *(short *)&d_1bd90c == (short)0 &&
            (!f_0de800(d_1c0004) || d_1c21b0 == 0)) {
            if (!((char)(f_042470((struct hero *)(p2)))) && !((char)(f_0424e0((struct hero *)(p2))))) {
                ev.p[1] = p2;
                ev.p[2] = target;
                f_0bf730(&d_1c2c64,
                    code == 1 ? 0x2040025 :
                    code == 2 ? 0x2040026 :
                    code == 3 ? 0x2040027 :
                    code == 4 ? 0x2040028 :
                    code == 5 ? 0x2040029 :
                    code == 6 ? 0x204002a :
                    (code != 7) + 0x204002d);
            }
            code = 0;
        }
        if (((signed char)(f_0425f0((struct hero *)(p2)))) != before && !f_0e3360(&d_1c2c64)) {
            ev.p[1] = p2;
            f_0bf730(&d_1c2c64, 0x204002b);
            if (d_1c2a80 == 0x30000)
                d_1c2198 = 1;
        }
    }
    }}
    f_1254a0(&ev,0);
}
//@ f_046b60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet für einen Helden (p2) jeden verstrichenen Spieltag (d_1c0c70), indem der
 *   Alchemie-Brautimer (f_0434b0) um 1 Tag verringert und bei bestehenden Krankheiten der tägliche
 *   Krankheitsverlauf (f_031020) berechnet wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeitkontext (p1) sowie den Heldenzeiger (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Tageszähler d_1c0c70.
 === Ende Beschreibung === */
void f_046b60(int p1, int p2)
{
    int i;
    for (i = 0; i < d_1c0c70; i++, f_0434b0(p2)) {
        if (!((char)(f_042470((struct hero *)(p2)))) && (f_0d4ad0(p2) || f_0d4b30(p2)))
            f_031020(p2);
    }
}
//@ f_046bc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet rekursiv die nach DSA-Stufentabelle für das Erreichen der Erfahrungsstufe p1
 *   erforderlichen Abenteuerpunkte nach der Dreieckszahl-Formel AP(n) = n * (n - 1) / 2 * (d_1c20b2 * 100)
 *   (Standardbasis 100 AP für Stufe 2, 300 für Stufe 3, 600 für Stufe 4 usw.).
 * - Eingaben und Rückgabe: Die Funktion erhält die Zielstufe (p1) und gibt die dafür benötigten
 *   Gesamtabenteuerpunkte als int zurück.
 * - Wichtige Variablen: Multipliziert mit dem globalen AP-Faktor d_1c20b2 (normalerweise 1).
 === Ende Beschreibung === */
int f_046bc0(short p1)
{
    int t = d_1c20b2 * 100;
    if (p1 <= 2)
        return t;
    return f_046bc0(p1 - 1) + (p1 - 1) * t;
}
