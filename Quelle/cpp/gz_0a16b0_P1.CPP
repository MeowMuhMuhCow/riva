/* === Beschreibung (Katalog) ===
 * Einheit gz_0a16b0 (0a1618-0a1d00)
 *
 * Überblick
 * Diese Einheit enthält den zentralen Einstiegspunkt f_0a16b0 der kontextsensitiven Online-Hilfe (Taste F1 bzw.
 * Umschalt+F1 für das Lösungs-/Hinweisbuch), der anhand des aktuellen Spielzustands, Menüs, Gebäudes oder
 * Dungeons das passende Hilfethema auswählt und f_0a01a0 startet, sowie mehrere kleine Hilfsfunktionen für
 * Rechteck- und Strukturkopien.
 === Ende Beschreibung === */
// P3 6/8 gleich (suche.py 26.10.2026, Basis gz_0a16b0_P1.CPP)
// gz_0a16b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A16B0-0x0A1D00
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_0e000a;                    // 0x0E000A
extern int d_1a1388;                    // 0x1A1388
extern int d_1bb02c;                    // 0x1BB02C
extern int d_1bc760;                    // 0x1BC760
extern int d_1bcad0;                    // 0x1BCAD0
extern int d_1bd90c;                    // 0x1BD90C
extern int d_1bdfac;                    // 0x1BDFAC
extern int d_1be038;                    // 0x1BE038
extern int d_1be0bc;                    // 0x1BE0BC
extern int d_1be0c0;                    // 0x1BE0C0
extern int d_1be0d8;                    // 0x1BE0D8
extern int d_1be0dc;                    // 0x1BE0DC
extern int d_1be160;                    // 0x1BE160
extern int d_1be178;                    // 0x1BE178
extern int d_1bf1ac;                    // 0x1BF1AC
extern int d_1bf244;                    // 0x1BF244
extern volatile int d_1bf520;                    // 0x1BF520 haelt die Ladereihenfolge wie im Original
extern int d_1bf524;                    // 0x1BF524
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0ae8;                    // 0x1C0AE8
extern int d_1c0bac;                    // 0x1C0BAC
extern int d_1c14c4;                    // 0x1C14C4
extern int d_1c2e78;                    // 0x1C2E78
extern const char d_1b70b2[];           // Text 0x1B70B2
extern const char d_1b70bd[];           // Text 0x1B70BD
extern const char d_1b70c8[];           // Text 0x1B70C8
extern const char d_1b70d3[];           // Text 0x1B70D3
extern const char d_1b70de[];           // Text 0x1B70DE
extern const char d_1b70e9[];           // Text 0x1B70E9
extern const char d_1b70f4[];           // Text 0x1B70F4
extern const char d_1b70ff[];           // Text 0x1B70FF
extern const char d_1b710b[];           // Text 0x1B710B
extern const char d_1b7116[];           // Text 0x1B7116
extern const char d_1b7122[];           // Text 0x1B7122
extern const char d_1b712d[];           // Text 0x1B712D
extern const char d_1b7139[];           // Text 0x1B7139
extern const char d_1b7144[];           // Text 0x1B7144
extern const char d_1b7150[];           // Text 0x1B7150
extern const char d_1b715b[];           // Text 0x1B715B
extern const char d_1b7167[];           // Text 0x1B7167
extern const char d_1b7172[];           // Text 0x1B7172
extern const char d_1b717e[];           // Text 0x1B717E
extern const char d_1b7189[];           // Text 0x1B7189
extern const char d_1b7195[];           // Text 0x1B7195
extern const char d_1b71a0[];           // Text 0x1B71A0
extern const char d_1b71ac[];           // Text 0x1B71AC
extern const char d_1b71b7[];           // Text 0x1B71B7
extern const char d_1b71c3[];           // Text 0x1B71C3
extern const char d_1b71ce[];           // Text 0x1B71CE
extern const char d_1b71d9[];           // Text 0x1B71D9
extern const char d_1b71e4[];           // Text 0x1B71E4
extern const char d_1b71ef[];           // Text 0x1B71EF
extern const char d_1b71fa[];           // Text 0x1B71FA
extern const char d_1b7205[];           // Text 0x1B7205
extern const char d_1b7210[];           // Text 0x1B7210
extern const char d_1b721b[];           // Text 0x1B721B
extern const char d_1b7226[];           // Text 0x1B7226
extern const char d_1b7231[];           // Text 0x1B7231
extern const char d_1b723c[];           // Text 0x1B723C
extern const char d_1b7247[];           // Text 0x1B7247
extern const char d_1b7252[];           // Text 0x1B7252
extern const char d_1b725d[];           // Text 0x1B725D
extern const char d_1b7268[];           // Text 0x1B7268
extern const char d_1b7273[];           // Text 0x1B7273
extern const char d_1b727e[];           // Text 0x1B727E
extern const char d_1b728a[];           // Text 0x1B728A
extern const char d_1b7295[];           // Text 0x1B7295
extern const char d_1b72a0[];           // Text 0x1B72A0
extern const char d_1b72ab[];           // Text 0x1B72AB
extern const char d_1b72b6[];           // Text 0x1B72B6
extern const char d_1b72c1[];           // Text 0x1B72C1
extern const char d_1b72cc[];           // Text 0x1B72CC
extern const char d_1b72d7[];           // Text 0x1B72D7
extern const char d_1b72e2[];           // Text 0x1B72E2
extern const char d_1b72ed[];           // Text 0x1B72ED
extern const char d_1b72f8[];           // Text 0x1B72F8
extern const char d_1b7303[];           // Text 0x1B7303
extern const char d_1b730e[];           // Text 0x1B730E
extern const char d_1b7319[];           // Text 0x1B7319
extern const char d_1b7324[];           // Text 0x1B7324
extern const char d_1b732f[];           // Text 0x1B732F
extern const char d_1b733a[];           // Text 0x1B733A
extern const char d_1b7344[];           // Text 0x1B7344
extern const char d_1b734f[];           // Text 0x1B734F
extern const char d_1b735a[];           // Text 0x1B735A
extern const char d_1b7365[];           // Text 0x1B7365
extern const char d_1b738a[];           // Text 0x1B738A
extern const char d_1b739d[];           // Text 0x1B739D
extern const char d_1b73af[];           // Text 0x1B73AF
extern const char d_1b73c4[];           // Text 0x1B73C4
extern const char d_1b73f7[];           // Text 0x1B73F7
extern const char d_1b7401[];           // Text 0x1B7401
extern const char d_1b740b[];           // Text 0x1B740B
extern const char d_1b7415[];           // Text 0x1B7415
extern const char d_1b7420[];           // Text 0x1B7420
extern const char d_1b742a[];           // Text 0x1B742A

// ---- eigene Deklarationen ----
extern const char d_1b7377[];
extern const char d_1b73d8[];
extern volatile short d_1bf51c;
extern short d_1bf4bc;
extern volatile short d_1bf4be; // haelt die Ladereihenfolge wie im Original
extern unsigned int d_1c2a80;
extern int d_1c2e68;
struct R { short a, b, c, d; };
struct S3 { short a; char b; };
struct Q4 { int a, b, c, d; };
#define A(x) ((int)&(x))
typedef int (*PF)(int);
int f_013df0(int p1);
int f_01e0c0(void);
int f_060a10(int p1);
int f_09a120(void);
int f_0a01a0(const char *p1, const char *p2);
int f_0d2f90(int p1, int p2);
struct R *f_0d38b0(void *p1);
int f_0d38d0(void *p1, int p2);
int f_0d3950(int p1, int p2, int p3, int p4);
int f_0d3f25(int p1);
int f_0d40b6(int p1, int p2);
int f_0d4880(int p1, int p2);
short f_0de800(int p1);
short f_0de820(int p1);
int f_122b70(int p1);
int f_122c50(int p1, int p2);
int f_1232e0(int p1);
int f_13fc70(int p1, int p_h);
int f_13fcd0(int p1, int p2);
void *f_145234(void *p1, void *p2);
void f_145254(void *p1);
void f_014710(void *p);

//@ f_0a16b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt beim Aufruf der Hilfefunktion (je nach Tastencode p1 entweder die reguläre
 *   Spielhilfe oder bei vorhandenem Zusatzarchiv d_1be0dc und p1 == 0x2300/0x5400 das kontextsensitive
 *   Lösungsbuch d_1bdfac = 1) anhand des aktuellen Orts, Menüs (d_1c2a80), Kampfs (d_1bd90c) oder
 *   Gebäudezustands die passende Hilfedatei (text und zusatz) und ruft den Hypertext-Viewer f_0a01a0 auf. Vorher
 *   und nachher werden Musikposition, Mauszeiger, Clipping-Rechteck und Bildschirmpalette gesichert und
 *   wiederhergestellt.
 * - Eingaben und Rückgabe: Die Funktion erhält den auslösenden Tastencode p1 (short) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Flag d_1bdfac unterscheidet zwischen Handbuch-Hilfe (0, Archiv d_1be038) und
 *   Lösungsbuch (1, Archiv d_1be0dc), f_0de820(d_1c0004) liefert die aktuelle Orts-/Dungeonkennung für das
 *   Lösungsbuch und d_1c2a80 bezeichnet das aktuell geöffnete Spielmenü.
 === Ende Beschreibung === */
void f_0a1c90(void)
{
}

void f_0a16b0(short p1)
{
    int alterWert524;
    int gefunden;
    short bild;
    short alterWert51c;
    short position;
    short alterWert4be;
    int kennung;
    const char *zusatz;
    const char *text;
    int alterWert1388;
    short alterWert4bc;
    int alterWert520;
    int modus;
    int aktiv;
    struct { struct R kopie, ablage, zeichnung; } lokal;
    // echte Prototypen der Aufgerufenen (wie in den anderen Einheiten, Aufgerufenen-ASM belegt)
    int f_013df0(int p1, int p2);
    int f_13fc70(int p1);
    int f_0d4880(int p1);
    int f_122c50(int p1);
    int f_09a120(int p1, int p2);
    void f_0d3f25(int p1, short p2);
    int f_0d40b6(int p1);
    void f_0d38d0(void *p1);

    lokal.zeichnung.a = 0;
    lokal.zeichnung.b = 0;
    lokal.zeichnung.c = 0;
    lokal.zeichnung.d = 0;
    aktiv = 1;
    if (d_1bf244) return;
    alterWert1388 = d_1a1388;
    d_1a1388 = 0;
    if (d_1bc760) f_01e0c0();
    bild = f_0d40b6(A(d_1c2e78));
    f_0d3f25(A(d_1c2e78), 4);
    alterWert51c = d_1bf51c;
    alterWert524 = d_1bf524;
    alterWert520 = d_1bf520;
    d_1bf51c = 0;
    alterWert4bc = d_1bf4bc;
    alterWert4be = d_1bf4be;
    f_0d2f90(0, 1);
    lokal.zeichnung = *f_0d38b0(&lokal.ablage);
    f_0d3950(0, 0, 0x13f, 199);
    f_060a10(0x2625a0);
    position = f_13fc70(A(d_1c14c4));
    f_0d4880(A(d_1c2e68));
    d_1bdfac = 0;
    d_1be178 = 0;
    gefunden = 0;
    if (f_013df0(A(d_1be0dc), 0x10001)) gefunden = 1;
    if (gefunden) {
        switch ((unsigned short)p1) {
        case 0x2308:
        case 0x3b00:
            d_1bdfac = 0;
            break;
        case 0x2300:
        case 0x5400:
            d_1bdfac = 1;
            break;
        }
    }
    if (aktiv == 1) {
        if (d_1bdfac) {
            d_1be0d8 = A(d_1be160);
            d_1be0bc = A(d_1be0dc);
            switch ((unsigned short)f_0de820(d_1c0004)) {
            case 7: zusatz=d_1b70b2; text=d_1b70bd; break;
            case 8: zusatz=d_1b70c8; text=d_1b70d3; break;
            case 9: zusatz=d_1b70de; text=d_1b70e9; break;
            case 13: zusatz=d_1b70f4; text=d_1b70ff; break;
            case 14: zusatz=d_1b710b; text=d_1b7116; break;
            case 6: zusatz=d_1b7122; text=d_1b712d; break;
            case 10: zusatz=d_1b7139; text=d_1b7144; break;
            case 11: zusatz=d_1b7150; text=d_1b715b; break;
            case 27: zusatz=d_1b7167; text=d_1b7172; break;
            case 1: zusatz=d_1b717e; text=d_1b7189; break;
            case 2: zusatz=d_1b7195; text=d_1b71a0; break;
            case 3: zusatz=d_1b71ac; text=d_1b71b7; break;
            case 18: zusatz=d_1b71c3; text=d_1b71ce; break;
            case 19: zusatz=d_1b71d9; text=d_1b71e4; break;
            case 20: zusatz=d_1b71ef; text=d_1b71fa; break;
            case 21: zusatz=d_1b7205; text=d_1b7210; break;
            case 22: zusatz=d_1b721b; text=d_1b7226; break;
            case 15: zusatz=d_1b7231; text=d_1b723c; break;
            case 16: zusatz=d_1b7247; text=d_1b7252; break;
            case 17: zusatz=d_1b725d; text=d_1b7268; break;
            case 0: zusatz=d_1b7273; text=d_1b727e; break;
            case 23: zusatz=d_1b728a; text=d_1b7295; break;
            case 24: zusatz=d_1b72a0; text=d_1b72ab; break;
            case 25: zusatz=d_1b72b6; text=d_1b72c1; break;
            case 4: zusatz=d_1b72cc; text=d_1b72d7; break;
            case 5: zusatz=d_1b72e2; text=d_1b72ed; break;
            default: zusatz=d_1b72f8; text=d_1b7303; break;
            }
        } else {
            d_1be0d8 = A(d_1be0c0);
            d_1be0bc = A(d_1be038);
            modus = 8;
            if (f_0de800(d_1c0004) != -1)
                modus = ((PF)*(int *)(*(int *)(d_1bf1ac + 0x58) + 0x18))(d_1bf1ac);
            if (d_1c2a80 == 0x210000) text = d_1b730e;
            else if (d_1c2a80 == 0x180000) text = d_1b7319;
            else if (d_1c2a80 == 0x80000) text = d_1b7324;
            else if (d_1c2a80 >= 0xe0000 && d_1c2a80 <= 0xe000a) text = d_1b732f;
            else if (d_1c2a80 >= 0x30000 && d_1c2a80 <= 0x30001) {
                if (d_1c2a80 == 0x30001) text = d_1b733a;
                else text = d_1b7344;
            } else if (d_1c2a80 == 0x150004) text = d_1b734f;
            else if (d_1bcad0 == 1) text = d_1b735a;
            else if (modus != 8) {
                switch (modus) {
                case 1: text=d_1b7365; break;
                case 2: text=d_1b7377; break;
                case 3: text=d_1b738a; break;
                case 4: text=d_1b739d; break;
                case 5: text=d_1b73af; break;
                case 6: text=d_1b73c4; break;
                case 7: text=d_1b73d8; break;
                case 0: text=d_1b73f7; break;
                default: text=d_1b7401; break;
                }
            } else if ((short)d_1bd90c != 0) text = d_1b740b;
            else {
                kennung = f_0de820(d_1c0004);
                if (kennung == -1) goto kein_kennung;
                if (d_1c0ae8 == 1) {
                    text = d_1b7415;
                    goto text_gesetzt;
                }
                d_1be178 = 1;
                f_0a01a0(d_1b7420, 0);
                f_122b70(A(d_1c0bac));
                f_1232e0(A(d_1c0bac));
                f_09a120(f_122c50(A(d_1c0bac)), 0x19);
                goto fertig;
kein_kennung:
                text = d_1b742a;
text_gesetzt:;
            }
            zusatz = 0;
        }
        f_0a01a0(text, zusatz);
    }
fertig:
    f_13fcd0(A(d_1c14c4), position);
    f_0d2f90(alterWert4bc, 1);
    d_1bf4be = alterWert4be;
    lokal.kopie.a = lokal.zeichnung.a;
    lokal.kopie.b = lokal.zeichnung.b;
    lokal.kopie.c = lokal.zeichnung.c;
    lokal.kopie.d = lokal.zeichnung.d;
    f_0d38d0(&lokal.kopie);
    f_0d3f25(A(d_1c2e78), bild);
    d_1bf51c = alterWert51c;
    d_1bf524 = alterWert524;
    d_1bf520 = alterWert520;
    d_1a1388 = alterWert1388;
}

//@ f_0a1c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine 12-Byte-Struktur (struct S3) von *q nach *p.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielzeiger p sowie den Quellzeiger q (struct S3 *) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden ausschließlich die Strukturdaten zwischen q und p übertragen.
 === Ende Beschreibung === */
void f_0a1c50(struct S3 *p, struct S3 *q)
{
    *p = *q;
}

//@ f_0a1c60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine 16-Byte-Rechteckstruktur (struct Q4) von *q nach *p.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielzeiger p sowie den Quellzeiger q (struct Q4 *) und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Die vier 32-Bit-Felder a, b, c und d werden komplett kopiert.
 === Ende Beschreibung === */
void f_0a1c60(struct Q4 *p, struct Q4 *q)
{
    *p = *q;
}

//@ f_0a1c70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert die vier 32-Bit-Felder (a, b, c, d) einer Q4-Rechteckstruktur p mit den
 *   übergebenen Werten.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger p (struct Q4 *) sowie die vier Werte a, b, c
 *   und d (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Felder p->a bis p->d nehmen die vier Koordinaten auf.
 === Ende Beschreibung === */
void f_0a1c70(struct Q4 *p, int a, int b, int c, int d)
{
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}

//@ f_0a1c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Hilfsfunktion ohne Operation.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */


//@ f_0a1ca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den konstanten Wert 25 (0x19) zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt 0x19 zurück (int).
 * - Wichtige Variablen: Die Funktion verwendet keine Variablen.
 === Ende Beschreibung === */
int f_0a1ca0(void)
{
    return 0x19;
}

//@ f_0a1cb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor eines Hilfsobjekts p und gibt je nach gesetztem Flag fl entweder ein
 *   Array über f_145234/f_145254 (fl & 4) oder den einzelnen Speicherblock über f_014710 (fl & 2) frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p (void *) sowie die Destruktor-Flags fl
 *   (unsigned) und gibt p zurück (void *).
 * - Wichtige Variablen: Der Typdeskriptor d_1bb02c beschreibt die Elementgröße beim Array-Abbau.
 === Ende Beschreibung === */
void *f_0a1cb0(void *p, unsigned fl)
{
    if (fl & 4) {
        f_145254(f_145234(p, &d_1bb02c));
        return p;
    }
    if (fl & 2) f_014710(p);
    return p;
}

//@ f_0a1ce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die vier 16-Bit-Koordinaten (a, b, c, d) einer Rechteckstruktur p auf die übergebenen
 *   Werte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Rechteckzeiger p (struct R *) sowie die vier Koordinaten a,
 *   b, c und d (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Felder p->a bis p->d speichern die Rechteckgrenzen.
 === Ende Beschreibung === */
void f_0a1ce0(struct R *p, short a, short b, short c, short d)
{
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
