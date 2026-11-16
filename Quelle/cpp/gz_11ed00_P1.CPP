/* === Beschreibung (Katalog) ===
 * Einheit gz_11ed00 (0x11ed00 - 0x11f400)
 *
 * Überblick
 * Diese Einheit implementiert die Tavernen- und Wirtshaus-Logik (tavern.cpp), darunter das Betreten einer
 * Taverne, das Bestellen von Bier und Essen für die Gruppe oder die Zeche für die ganze Schenke, die Prüfung auf
 * Trunkenheit und Verkaterung bei übermäßigem Alkoholkonsum, das Aufschnappen von Wirtshausgerüchten sowie die
 * zeitabhängige Berechnung der Gästeanzahl.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 11/13 gleich (suche.py 25.10.2026, Basis gz_11ed00_P1.CPP)
// OPT -4r -onetx -zp1 -s
// P1 6/13 gleich
// gz_11ed00.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11ED00-0x11F400
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_02de80(int p1, int p2);                           // reg edx stapel 0
int f_02de90(int p1, int p2);                           // reg eax edx stapel 0
int f_02dee0(int p1);                                   // reg eax stapel 0
int f_02df40(int p1);                                   // reg eax stapel 0
int f_02dfa0(int p1);                                   // reg eax stapel 0
int f_02dfe0(int p1);                                   // reg eax stapel 0
int f_02e030(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_040a40(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);

short f_044c90(int p1, int p2, int p3);
short f_03aa20(int p1, int p2, int p3, int p4);
signed char f_126420(int p1);
int f_1254a0(int p1, int p2);
short __cdecl f_0bf820(int p1, int p2, int p3, int p4, int p5);
int f_145234(int p1, int p2);
void f_145254(void);
extern char d_1bed50;
extern signed char d_1bed68, d_1bee18, d_1c00b0;
extern volatile short d_1c219a; // haelt Schreibfolge in f_11ed90/f_11f150 wie im Original
extern volatile short d_1c2198; // haelt Schreibfolge in f_11ed90/f_11f150 wie im Original
extern int d_1c0004, d_1c2c44, d_1c2c64, d_1c349c, d_1c3870, d_1c3498, d_1bba18;
extern int d_1bba2c[];
struct Ob { int w0; int p4; int w8; int wc; int p10; char pad[0x28]; };
#define EQM(x,v) (((x)==(v))?1:0)
static inline int EQF(int a, int b) { return a == b; }
static inline char EQC(int a, int b) { return a == b; }
void f_11ed30(int p1, char p2);
void f_11efd0(unsigned short *p1);
void f_11f1b0(int p1);
void f_11f320(int p1);

//@ f_11ed00
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor eines Tavernen-Gebäudeobjekts, der die Gebäude-Basisklasse (f_02de80) initialisiert, die
 *   virtuelle Methodentabelle (d_1bba2c) einträgt und die Zähler für Gästeanzahl und getrunkene Runden auf null
 *   setzt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts und in p2 die Gebäude-ID.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_11ed00(int p1, short p2)
{
    int r;
    r = f_02de80(p1, p2);
    *(int *)(r + 0x58) = (int)d_1bba2c;
    *(short *)(r + 0x60) = 0;
    *(short *)(r + 0x62) = 0;
    *(short *)(r + 0x64) = 0;
    f_11ed30(r, 0);
    return r;
}

//@ f_11ed30
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt das globale Tavernen-Statusflag d_1bed50 auf den übergebenen Wert.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts und in p2 den zu
 *   setzenden Bytewert.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11ed30(int p1, char p2)
{
    d_1bed50 = p2;
}

//@ f_11ed40
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor eines Tavernen-Gebäudeobjekts, der den Basis-Destruktor (f_02de90) aufruft und bei
 *   gesetztem Flag den Objektspeicher freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts und in p2 die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p1) zurück.
 === Ende Beschreibung === */
int f_11ed40(int p1, int p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)&d_1bba18);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0x58) = (int)d_1bba2c;
    r = f_02de90(p1, 1);
    if (p2 & 2) delete (char *)r;
    return r;
}

//@ f_11ed90
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Handler einer Taverne, der Gespräche am Tresen (0x81), Würfelspiele (0x8c), das
 *   Bestellen von Getränken und Essen (0x97) sowie das Verlassen der Schenke (0x80) verarbeitet.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts und in p2 den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 beim Verlassen der Taverne (0x80) zurück, andernfalls 0.
 === Ende Beschreibung === */
int f_11ed90(int p1, unsigned short p2)
{
  int r = 0;
  switch (p2) {
  case 0:
    break;
  case 0x81:
    f_11efd0((unsigned short *)p1);
    break;
  case 0x8c: {
    int q = f_038d70(d_1c0004, 0x200001bf);
    if (q != 0 && (int)(short)f_03aa20(q, 0, 4, -1) != -3) {
      d_1c2198 = 0;
      d_1c219a = 1;
      f_125ed0((int)&d_1c2c44, 0x1e);
    }
    break;
  }
  case 0x97:
    f_11f1b0(p1);
    break;
  case 0x80:
    r = 1;
    break;
  }
  return r;
}

//@ f_11ee50
/* === Beschreibung (Katalog) ===
 * - Zweck:Initialisiert beim Betreten der Taverne die Basis-Gebäudeansicht (f_02dee0) und berechnet über
 *   f_11f320 die aktuelle Auslastung der Gaststube.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11ee50(int p1)
{
    f_02dee0(p1);
    f_11f320(p1);
}

//@ f_11ee60
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalter-Methode in der virtuellen Methodentabelle des Tavernen-Objekts.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11ee60(void)
{
}

//@ f_11ee70
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft nach mehr als drei bestellten Runden Alkohol (*(short *)(p1 + 0x62) > 3) für jedes
 *   handlungsfähige Gruppenmitglied eine mit jeder weiteren Runde erschwerte Zechen-/Selbstbeherrschungsprobe
 *   (0x12) und versetzt Helden bei Misslingen in den Zustand der Trunkenheit (f_040a40, Text 0x1b000001).
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11ee70(int p1)
{
    struct Ob ob;
    int h;
    int t;
    short a;
    if (*(short *)(p1 + 0x62) > 3) {
        f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        h = f_038c80(d_1c0004);
        do {
            if (f_0d4a60(h)) {
                if (f_042950((struct hero *)(h)) == 0) {
                    t = *(unsigned short *)(p1 + 0x62) - 3;
                    a = t * 4 - 0x14;
                    if (f_044c90(h, 0x12, (signed char)a) <= 0) {
                        *(int *)(ob.p4 + 4) = h;
                        f_0bf730((int)&d_1c2c64, 0x1b000001);
                        f_040a40(h);
                    }
                }
            }
            h = f_0391b0(d_1c0004, h);
        } while (h != f_038c80(d_1c0004));
        f_1254a0((int)&ob, 0);
    }
}

//@ f_11ef30
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt in einer bestimmten Taverne mit 50 Prozent Wahrscheinlichkeit eine spezielle Hinweis- oder
 *   Gerüchtemeldung (0x22000030 bzw. 0x22000031) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Meldung ausgegeben wurde, sonst 0.
 === Ende Beschreibung === */
int f_11ef30(void)
{
    int r;
    int p2;
    r = 0;
    if (f_1457e0(100) <= 0x32) {
        r = 1;
        if (EQM(d_1c00b0, 0)) f_0bf730((int)&d_1c2c64, 0x22000030);
        else f_0bf730((int)&d_1c2c64, 0x22000031);
    }
    return r;
}

//@ f_11ef80
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim Gespräch in der Taverne mit 30 Prozent Wahrscheinlichkeit eines von 20 zufälligen
 *   allgemeinen Wirtshausgerüchten (0x1b00000a bis 0x1b00001d) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein Gerücht ausgegeben wurde, sonst 0.
 === Ende Beschreibung === */
int f_11ef80(void)
{
    int r;
    short s;
    s = f_1457e0(100);
    r = 0;
    if (s <= 0x1e) {
        f_0bf730((int)&d_1c2c64, 0x1b000009);
        s = f_1457e0(0x14);
        r = 1;
        f_0bf730((int)&d_1c2c64, s + 0x1b000009);
    }
    return r;
}

//@ f_11efd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert das Gespräch mit dem Wirt oder den Gästen einer Taverne (0x81), wählt je nach Tavernen-ID und
 *   Spielstand den passenden Dialog (0x150007 ff.) oder ein zufälliges Gerücht (f_11ef30, f_11ef80) aus und
 *   prüft nach bestimmten Trinkdialogen (0x150017) auf Trunkenheit.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Tavernen-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
int f_11ee70(unsigned short *p1);
int f_11ef30(void);
int f_11ef80(void);
void f_11efd0(unsigned short *p1)
{
    int code;
    int w;
    code = p1[0x13] + 0x150007;
    if (p1[0] == 0xb && EQM(d_1bed68, 2)) {
        if (EQM(d_1bee18, 0)) code = 0x150034;
        else code = 0x150035;
    } else {
        w = (short)p1[0x32];
        if (w == 0) {
            if (p1[0] == 0xb) {
                if (f_11ef30() || f_11ef80() == 1) code = -1;
            } else {
                if (f_11ef80() == 1) code = -1;
            }
        } else {
            code = w + 0x150060;
        }
    }
    if (code != -1) {
        f_056a50(code);
        if (code == 0x150017) f_11ee70(p1);
    }
}
//@ f_11f150
/* === Beschreibung (Katalog) ===
 * - Zweck: Lässt den Spieler einen Helden für ein Glücks- oder Würfelspiel in der Taverne auswählen
 *   (0x200001bf), führt das Minispiel (f_03aa20) aus und spult bei Durchführung die Spielzeit um 30 Minuten vor.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11f150(void)
{
    int h;
    h = f_038d70(d_1c0004, 0x200001bf);
    if (h != 0) {
        if (f_03aa20(h, 0, 4, -1) != -3) {
            d_1c2198 = 0;
            d_1c219a = 1;
            f_125ed0((int)&d_1c2c44, 0x1e);
        }
    }
}

//@ f_11f1b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die Bestellung beim Wirt (0x97), bei der die Gruppe entweder eine Runde Getränke (case 1,
 *   erhöht den Alkoholzähler und prüft auf Trunkenheit) oder eine warme Mahlzeit (case 2, senkt den
 *   Alkoholzähler um 1 und sättigt die Helden) kaufen kann.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
int f_0dbfe0(int p1);
void f_11ee70(int p1);
struct MsgC {
    int h;
    int q[14];
    MsgC(int a, int b, int c) { f_125400((int)this, a, b, c); }
    ~MsgC() { f_1254a0((int)this, 0); }
};
void f_11f1b0(int p1)
{
    MsgC m((int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    short v;
    short t;
    unsigned b;
    int *q;
    int w;
    v = f_0dbfe0(d_1c0004);
    switch ((unsigned short)f_0bf820(
        ((*(short *)(m.q[4] + 2) = v), (int)&d_1c2c64),
        0x1b000002, 2, 0x1b000003, 0x1b000004)) {
    case 1:
        b = f_02dfa0(p1);
        if ((unsigned)f_0de7e0(d_1c0004) >= b) {
            q = (int *)m.q[3];
            w = *(int *)(p1 + 2);
            q[1] = w;
            f_0bf730((int)&d_1c2c64, 0x1b000005);
            f_0db8b0(d_1c0004, b);
            f_02e030(p1);
        } else {
            f_0bf730((int)&d_1c2c64, 0x20000010);
        }
        f_11ee70((*(short *)(p1 + 0x62) = *(short *)(p1 + 0x62) + 1, p1));
        break;
    case 2:
        b = f_02df40(p1);
        if ((unsigned)f_0de7e0(d_1c0004) >= b) {
            f_0bf730((int)&d_1c2c64, 0x1b000006);
            f_0db8b0(d_1c0004, b);
            f_02dfe0(p1);
            if (*(short *)(p1 + 0x62) > 0)
                --*(short *)(p1 + 0x62);
        } else {
            f_0bf730((int)&d_1c2c64, 0x20000010);
        }
        break;
    }
}
//@ f_11f320
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet anhand der aktuellen Tagesstunde, des Wochentags, der Öffnungszeiten der Taverne und ihres
 *   Qualitätswerts (+0x5c) mit einer leichten Zufallsstreuung den prozentualen Füllgrad der Gaststube (10 bis
 *   100 Prozent) und speichert ihn im Feld +0x60.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Tavernen-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11f320(int p1)
{
    int t, a, b, c, x;
    short y;
    t = f_126410((int)&d_1c2c44) / 0x1518;
    a = (short)*(short *)(p1 + 0x32 + f_126420((int)&d_1c2c44) * 2);
    b = (short)*(short *)(p1 + 0x40 + f_126420((int)&d_1c2c44) * 2);
    c = 50;
    x = 0;
    y = 0;
    t -= a;
    b -= a;
    a = 0;
    if (b < 0) b += 24;
    x = (t - 2) * (t - (b - 2));
    c /= b * 2 - b * b / 4 - 4;
    y = *(short *)(p1 + 0x5c);
    y *= 2;
    y = 70 - y;
    y += x * c;
    y += 10 - f_145760(0, 20);
    if (y < 10) y = 10;
    else if (y > 100) y = 100;
    *(short *)(p1 + 0x60) = y;
}
