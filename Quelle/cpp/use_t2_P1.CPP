/* === Beschreibung (Katalog) ===
 * Einheit use_t2 (0x136210 - 0x1374F0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von use.cpp und enthält sämtliche Such-, Auswahl-, Kopier- und
 * Lesefunktionen rund um das *Rezeptbuch* (0xbf), das *Notizbuch* (0x1dc), das *Schreibzeug* (0x24) sowie die
 * acht magischen Bücher aus dem Magierturm.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 18/23 gleich (suche.py 26.10.2026, Basis use_t2_P1.CPP)
// use.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x135040-0x13AA40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030850(int p1, int p2);                           // reg eax edx stapel 0
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0458b0(int p1);                                   // reg eax stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068960();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_08ab50();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a080(int p1, int p2);                           // reg eax edx stapel 0 (SICHERT)
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce710(int p1);                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d49b0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10cba0(int p1, int p2);                           // reg eax edx stapel 0
int f_10cbc0(int p1, int p2);                           // reg - stapel 0
int f_10ce80();                       // nicht in clobber.tsv
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b40(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
struct L { short n; short *a; short *b; };
void f_014710(void *p);


short f_03d860(int p1, int p2, int p3);
short f_149360(int p1, int p2);
short f_0d4aa0(int p1, int p2);
int f_0bf820();
int f_0bf820(int p1, ...);
void f_0bf680(int p1);
int f_1389b0(int p1);
void f_135dc0(int p1, int p2, int p3, int p4);
void f_135ef0(int p1, int p2, int p3, int p4);
void f_138330(int p1, int p2);
void f_1374f0(int p1, int p2);
short f_136720(int p1, short p2);
short f_1365d0(int p1, short p2);
short f_1364f0(int p1, short p2);
short f_136af0(int p1, int p2, L *p3, short p4);
short f_136ca0(int p1, int p2, L *p3, short p4);
extern const char d_1a8e28[];
extern short d_1a92d0[];
extern short d_1a92f4[];
extern short d_1a9316[];
extern short d_1a935a[];
extern short d_1a68f4[];
extern short d_1c25fe[];
extern short d_1c2600[];
extern int d_1c259c[];
extern int d_1c29c4[];

extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
#define OB RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498)
#define P10 (*(int *)(p1 + 0x10))
#define MSG(m) f_0bf730((int)d_1c2c64, m)

//@ f_136210
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Kombination von *Schreibzeug* (Slot p2) mit einem *Rezeptbuch* (0xbf in Slot p3)
 *   aus: Nach Prüfung der Schreibzeug-Ladungen (f_1364f0) wählt der Spieler über f_136720 ein Rezept aus dem
 *   Inventar aus, das anschließend über f_135dc0 in das Rezeptbuch eingetragen wird.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) und der Rezeptbuch-Slot (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: s1 ist der geprüfte Schreibzeug-Slot und s2 der ausgewählte Rezept-Slot.
 === Ende Beschreibung === */
void f_136210(int p1, int p2, short p3)
{
    short s1 = f_1364f0(p1, (short)p2);
    if (s1 != -1) {
        short s2 = f_136720(p1, (short)p3);
        if (s2 != -1) f_135dc0(p1, (short)p3, s1, s2);
    }
}
//@ f_136250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Kombination von *Schreibzeug* (Slot p2) mit einem *Notizbuch* (0x1dc in Slot p3)
 *   aus: Nach Prüfung des Schreibzeugs (f_1364f0) wählt der Spieler über f_1365d0 ein Dokument aus dem Inventar
 *   aus, das über f_135ef0 in das Notizbuch abgeschrieben wird.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) und der Notizbuch-Slot (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: s1 ist der Schreibzeug-Slot und s2 der ausgewählte Dokument-Slot.
 === Ende Beschreibung === */
void f_136250(int p1, int p2, int p3)
{
    short s1 = f_1364f0(p1, (short)p2);
    if (s1 != -1) {
        short s2 = f_1365d0(p1, (short)p3);
        if (s2 != -1) f_135ef0(p1, (short)p3, s2, s1);
    }
}

//@ f_136340
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Kombination von *Schreibzeug* (Slot p2) mit einem einzelnen Rezept (Slot p3):
 *   Es wird im Inventar des Helden nach einem *Rezeptbuch* (0xbf) oder einem leeren *Buch* (0x1d) gesucht und
 *   das Rezept bei Erfolg über f_135dc0 eingetragen; fehlt ein Buch, wird die Meldung 0x1e010088 ausgegeben.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) und der Rezept-Slot (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: l14 enthält den Inventarslot des gefundenen Rezept- oder leeren Buches.
 === Ende Beschreibung === */
void f_136340(int p1, int p2, int p3)
{
    register int q;
    short l14;
    p2 = ((int (*)(int, short))f_1364f0)(p1, (short)p2);
    if ((short)p2 != -1) {
        l14 = f_0d4aa0(P10, 0xbf);
        q = p1;
        if (l14 == -1) l14 = f_0d4aa0(P10, 0x1d);
        if (l14 == -1) {
            OB;
            int value = *(int *)(q + 0x10);
            *(int *)(obj.slots[0] + 4) = value;
            MSG(0x1e010088);
        }
        if (l14 != -1) f_135dc0(p1, l14, (short)p2, (short)(*&p3));
    }
}
//@ f_1363f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht im Inventar des handelnden Helden (P10) nach einem *Notizbuch* (0x1dc) oder einem
 *   leeren *Buch* (0x1d) und gibt bei Fehlschlag die Meldung 0x1e010088 aus.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1).
 * - Rückgabewert: Gibt den gefundenen Buch-Slot (r) oder -1 zurück.
 * - Wichtige Variablen: r speichert den Slotindex aus f_0d4aa0.
 === Ende Beschreibung === */
short f_1363f0(int p1)
{
    short r = f_0d4aa0(P10, 0x1dc);
    if (r == -1) r = f_0d4aa0(P10, 0x1d);
    if (r == -1) {
        OB;
        *(int *)(obj.slots[0] + 4) = P10;
        MSG(0x1e010088);
    }
    return r;
}
//@ f_136470
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht im Inventar des handelnden Helden (P10) nach einem *Rezeptbuch* (0xbf) oder einem
 *   leeren *Buch* (0x1d) und gibt bei Fehlschlag die Meldung 0x1e010088 aus.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1).
 * - Rückgabewert: Gibt den gefundenen Buch-Slot (r) oder -1 zurück.
 * - Wichtige Variablen: r speichert den Slotindex aus f_0d4aa0.
 === Ende Beschreibung === */
short f_136470(int p1)
{
    short r = f_0d4aa0(P10, 0xbf);
    if (r == -1) r = f_0d4aa0(P10, 0x1d);
    if (r == -1) {
        OB;
        *(int *)(obj.slots[0] + 4) = P10;
        MSG(0x1e010088);
    }
    return r;
}
//@ f_1364f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht (falls p2 == -1 übergeben wurde) in den Rucksackslots 15 bis 30 des Helden nach
 *   *Schreibzeug* (0x24) mit mindestens einer verbleibenden Ladung und prüft anschließend, ob das gefundene bzw.
 *   in Slot p2 übergebene Schreibzeug noch benutzbar ist; fehlt Schreibzeug, erscheint 0x1e010098, ist es
 *   verbraucht, erscheint 0x1e010050.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie ein bekannter Schreibzeug-Slot (p2) oder -1 für
 *   die automatische Suche.
 * - Rückgabewert: Gibt den gültigen Schreibzeug-Slot (r) oder -1 zurück.
 * - Wichtige Variablen: i durchläuft die Rucksackslots 0xf bis 0x1e, s prüft die Gegenstandskennung (0x24) und
 *   die verbleibende Ladungszahl (f_042ac0).
 === Ende Beschreibung === */
short f_1364f0(int p1, short p2)
{
    short r = p2;
    short s;
    short i;
    if (p2 == -1) {
        for (i = 0xf; (short)i <= 0x1e; i++) {
            s = f_042a60((struct hero *)(P10), (short)i);
            if (s == 0x24) {
                s = f_042ac0((struct hero *)(P10), (short)i);
                r = i;
                if (0 < s) break;
            }
        }
    }
    OB;
    *(int *)(obj.slots[0] + 4) = P10;
    i = (short)r;
    if (i == -1) {
        MSG(0x1e010098);
    } else {
        s = f_042ac0((struct hero *)(P10), i);
        if (s <= 0) {
            if (*(int *)p1 != 0) {
                s = f_042a60((struct hero *)(P10), i);
                *(int *)(obj.slots[2] + 4) = (*(int **)&d_1c2c40)[s];
                *(short *)(obj.slots[7] + 2) = 1;
                MSG(0x1e010050);
            }
            r = -1;
        }
    }
    return r;
}
//@ f_1365d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchsucht die Rucksackslots (15 bis 30) des Helden nach allen losen Dokumenten aus der
 *   Tabelle d_1a9316, stellt diese über f_136ca0 in einem Auswahlmenü (0x1e01008b) dar und liefert den
 *   Inventarslot des vom Spieler gewählten Dokuments zurück; besitzt der Held kein einziges Dokument, wird
 *   0x1e010097 angezeigt.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Slot des Ziel-Notizbuchs (p2, zur farblichen
 *   Markierung bereits abgeschriebener Dokumente).
 * - Rückgabewert: Gibt den Inventarslot (r) des ausgewählten Dokuments oder -1 zurück.
 * - Wichtige Variablen: Die lokale Listenstruktur loc speichert in loc.a die gefundenen Inventarslots und in
 *   loc.b die zugehörigen Gegenstandskennungen für loc.n gefundene Dokumente.
 === Ende Beschreibung === */
int f_14b10(const char *a, int b);
int f_14ac0(int a, int b);
int f_1389b0(int p1, int p2);
#define AT_T(arr, i) (*(short *)((char *)(arr) + (i) * 2))
short f_1365d0(int p1, short p2)
{
    L loc;
    short r;
    short k;
    short s;
    int q;
    loc.n = 0;
    r = -1;
    loc.a = (short *)f_14ac0(0x50, f_14b10(d_1a8e28, 0xc55));
    q = p1;
    loc.b = (short *)f_14ac0(0x50, f_14b10(d_1a8e28, 0xc56));
    for (k = 0xf; k <= 0x1e; k++) {
        s = f_042a60((struct hero *)(*(int *)(q + 0x10)), k);
        if (s > 0) {
            int ok = 0;
            if (s > 0) {
                if ((short)f_149360(s, (int)d_1a9316) != -1) ok = 1;
            }
            if (ok) {
                AT_T(loc.a, loc.n) = k;
                AT_T(loc.b, loc.n) = s;
                loc.n++;
            }
        }
    }
    if (loc.n == 0) {
        OB;
        *(int *)(obj.slots[0] + 4) = P10;
        MSG(0x1e010097);
    } else {
        int ActionIndex493(int,int,L *,short);
        #pragma aux ActionIndex493 "f_136ca0";
        short t = ActionIndex493(p1, 0x1e01008b, &loc, p2);
        if (t != -1) r = AT_T(loc.a, t);
    }
    f_1389b0((int)&loc, 0);
    return r;
}
//@ f_136720
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchsucht die Rucksackslots (15 bis 30) des Helden nach allen alchemistischen Rezepten aus
 *   der Tabelle d_1a92d0, lässt den Spieler über f_136af0 eines davon auswählen (0x1e01008a) und gibt dessen
 *   Inventarslot zurück; trägt der Held kein Rezept bei sich, erscheint 0x1e010096.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Slot des Ziel-Rezeptbuchs (p2).
 * - Rückgabewert: Gibt den Inventarslot (r) des ausgewählten Rezepts oder -1 zurück.
 * - Wichtige Variablen: Die Listenstruktur loc sammelt die Slotindizes (loc.a) und Gegenstandskennungen (loc.b)
 *   aller gefundenen Rezepte.
 === Ende Beschreibung === */
int f_14b10(const char *a, int b);
int f_14ac0(int a, int b);
int f_1389b0(int p1, int p2);
#define AT(arr, i) (*(short *)((char *)(arr) + (i) * 2))
short f_136720(int p1, short p2)
{
    L loc;
    short r;
    short k;
    short s;
    int q;
    loc.n = 0;
    r = -1;
    loc.a = (short *)f_14ac0(0x50, f_14b10(d_1a8e28, 0xc55));
    q = p1;
    loc.b = (short *)f_14ac0(0x50, f_14b10(d_1a8e28, 0xc56));
    for (k = 0xf; k <= 0x1e; k++) {
        s = f_042a60((struct hero *)(*(int *)(q + 0x10)), k);
        if (s > 0) {
            int ok = 0;
            if (s > 0) {
                if ((short)f_149360(s, (int)d_1a92d0) != -1) ok = 1;
            }
            if (ok) {
                AT(loc.a, loc.n) = k;
                AT(loc.b, loc.n) = s;
                loc.n++;
            }
        }
    }
    if (loc.n == 0) {
        OB;
        *(int *)(obj.slots[0] + 4) = P10;
        MSG(0x1e010096);
    } else {
        int MenuIndex493(int,int,L *,short);
        #pragma aux MenuIndex493 "f_136af0";
        short t = MenuIndex493(p1, 0x1e01008a, &loc, p2);
        if (t != -1) r = AT(loc.a, t);
    }
    f_1389b0((int)&loc, 0);
    return r;
}
//@ f_136870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gleicht zwei *Rezeptbücher* in den Slots p3 und p4 miteinander ab, indem alle 17 möglichen
 *   Rezepte (d_1a92d0) verglichen und jeweils fehlende Einträge in das andere Buch übertragen werden (f_03d8b0);
 *   wurde mindestens ein neues Rezept ergänzt (fl == 1), erscheint die Erfolgsmeldung 0x1e01008e und es wird
 *   eine Ladung *Schreibzeug* aus Slot p2 abgezogen, andernfalls erscheint 0x1e010091.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) sowie die Slots der beiden
 *   Rezeptbücher (p3, p4).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: i durchläuft alle Einträge von d_1a92d0, a und b enthalten den Kenntnisstand des
 *   jeweiligen Rezepts in Buch p3 bzw. p4, und fl vermerkt, ob mindestens ein Rezept ausgetauscht wurde.
 === Ende Beschreibung === */
void f_136870(int p1, short p2, short p3, short p4)
{
    int fl = 0;
    short i = 0;
    int b;

    for (; (int)d_1a92d0[i] != -1; i++) {
        int a;
        a = f_03d860(P10, (short)p3, i);
        b = f_03d860(P10, (short)p4, i);
        if (a != b) {
            f_03d8b0(P10, (short)p3, i, 1);
            f_03d8b0(P10, (short)p4, i, 1);
            fl = 1;
        }
    }

    OB;
    *(int *)(obj.slots[0] + 4) = P10;
    switch (fl) {
    case 0:
        MSG(0x1e010091);
        break;
    case 1:
        MSG(0x1e01008e);
        f_042b20((struct hero *)(P10), p2, -1);
        break;
    }
}
//@ f_1369b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gleicht zwei *Notizbücher* in den Slots p3 und p4 miteinander ab, indem alle Dokumente aus
 *   d_1a9316 wechselseitig ergänzt werden; falls mindestens ein Dokument übertragen wurde (fl == 1), wird die
 *   Meldung 0x1e01008f angezeigt und eine Ladung *Schreibzeug* (Slot p2) verbraucht, andernfalls erscheint
 *   0x1e010091.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) sowie die Slots der beiden
 *   Notizbücher (p3, p4).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: i läuft über alle Dokumente in d_1a9316, und fl gibt an, ob sich die beiden Notizbücher
 *   unterschieden haben.
 === Ende Beschreibung === */
void f_1369b0(int p1, short p2, short p3, short p4)
{
    int fl = 0;
    short i = 0;
    int b;

    for (; (int)d_1a9316[i] != -1; i++) {
        int a;
        a = f_03d860(P10, (short)p3, i);
        b = f_03d860(P10, (short)p4, i);
        if (a != b) {
            f_03d8b0(P10, (short)p3, i, 1);
            f_03d8b0(P10, (short)p4, i, 1);
            fl = 1;
        }
    }

    OB;
    *(int *)(obj.slots[0] + 4) = P10;
    switch (fl) {
    case 0:
        MSG(0x1e010091);
        break;
    case 1:
        MSG(0x1e01008f);
        f_042b20((struct hero *)(P10), p2, -1);
        break;
    }
}
//@ f_136af0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Baut das Auswahlmenü (f_0bf820) für die im Inventar gefundenen Rezepte (p3) auf, wobei jedes
 *   Rezept nach dem zugehörigen Tranknamen (d_1a92f4) benannt und farblich markiert wird (0xe7 für bereits im
 *   Rezeptbuch p4 vorhandene Rezepte, 0xff für neue Rezepte).
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), die Überschrifts-Textkennung (p2), ein Zeiger auf die
 *   Rezeptliste (p3) sowie der Slot des Ziel-Rezeptbuchs (p4).
 * - Rückgabewert: Gibt den 0-basierten Index (r) des vom Spieler gewählten Listeneintrags oder -1 bei Abbruch
 *   zurück.
 * - Wichtige Variablen: values (d_1c2600) und table (d_1c259c) speichern die formatierten Menüzeilen; selected
 *   hält den Farbcode (0xe7 oder 0xff).
 === Ende Beschreibung === */
short f_136af0(int p1, int p2, L *p3, short p4)
{
    struct Lookup493 {static short get(short element){short n=f_149360(element,(int)d_1a92d0);return d_1a92f4[n];}};
    p2 = (p2 & 0) ? 0 : p2; // haelt Nutzungsgewicht von p2 vor der Schleife fuer Register-/Slotwahl wie im Original
    int *values = (int *)d_1c2600;
    int *table = d_1c259c;
    short i;
    short s1, s2;
    unsigned char selected;
    unsigned short input;
    short r;
    OB;

    for (i = 0; i < p3->n; i++) {
        short element;
            element = p3->b[i];
            s1=Lookup493::get(element);
            s2 = f_149360(element, (int)d_1a92d0);
            s2 = f_03d860(P10, (short)p4, s2);
            if (s2 != (short)0)
                selected = 0xe7;
            else
                selected = 0xff;

            f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[s1]),(char *)( (int)d_1c27a8), 1);
            table[i] = (int)(d_1c21b4 + i * 0x32);
            *(int *)(obj.slots[3] + 4) = f_133fe0((int)d_1c3498, (int)d_1c27a8);
            f_0e93f0((int)d_1c38b0, table[i], ((int (*)(int))f_09a080)(selected));
            values[i] = f_133fe0((int)d_1c3498, table[i]);
    }

    input = f_0bf820((int)d_1c2c64, p2, p3->n,
        values[0], values[1], values[2], values[3], values[4], values[5],
        values[6], values[7], values[8], values[9], values[10], values[11],
        values[12], values[13], values[14], values[15], values[16], values[17]);
    r = -1;
    if ((short)input != -1) {
        r = input;
        --r;
    }
    return r;
}
//@ f_136ca0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Baut analog zu f_136af0 das Auswahlmenü für die im Inventar gefundenen Dokumente (p3) auf,
 *   markiert bereits im Notizbuch (p4) enthaltene Schriftstücke farblich (0xe7 statt 0xff) und gibt die Auswahl
 *   des Spielers zurück.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), die Überschrifts-Textkennung (p2), ein Zeiger auf die
 *   Dokumentenliste (p3) sowie der Slot des Ziel-Notizbuchs (p4).
 * - Rückgabewert: Gibt den 0-basierten Index (r) des gewählten Dokuments in p3 oder -1 zurück.
 * - Wichtige Variablen: q (d_1c2600) und table (d_1c259c) nehmen die formatierten Gegenstandsnamen für bis zu 18
 *   Dokumente auf.
 === Ende Beschreibung === */
short f_136ca0(int p1, int p2, L *p3, short p4)
{
    short i, s1; int s2;
    // Beide moeglichen Codes liefern in f_09a080 eine feste 32-Bit-Textkennung;
    // der dortige allgemeine Pufferparameter wird auf diesen Wegen nicht gelesen.
    int ColorToken493(int);
    #pragma aux ColorToken493 "f_09a080" parm [eax] modify exact [eax];
    unsigned char b;
    int *q = (int *)d_1c2600;
    int *table = d_1c259c;
    unsigned short a; short r;
    OB;
    for (i = 0; i < p3->n; i++) {
        s1 = p3->b[i];
        s2 = f_149360(s1, (int)d_1a9316);
        if (f_03d860(P10, (short)p4, (short)s2))
            b = 0xe7;
        else
            b = 0xff;
        f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[s1]),(char *)( (int)d_1c27a8), 1);
        table[i] = (int)(d_1c21b4 + i * 0x32);
        int x = f_133fe0((int)d_1c3498, (int)d_1c27a8);
        char *box = obj.slots[3];
        *(int *)(box + 4) = x;
        f_0e93f0((int)d_1c38b0, table[i], ColorToken493(b));
        q[i] = f_133fe0((int)d_1c3498, table[i]);
    }
    f_0bf6c0((int)d_1c2c64, 5);
    a = f_0bf820((int)d_1c2c64, p2, p3->n,
        q[0], q[1], q[2], q[3], q[4], q[5],
        q[6], q[7], q[8], q[9], q[10], q[11],
        q[12], q[13], q[14], q[15], q[16], q[17]);
    ((int (*)(int))f_0bf680)((int)d_1c2c64);
    r = -1;
    if ((short)a != -1) {
        r = a;
        --r;
    }
    return r;
}
//@ f_136e60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ermittelt zu einer gegebenen Rezept-Gegenstandskennung (p2 aus d_1a92d0) die
 *   Gegenstandskennung des zugehörigen fertigen Tranks aus d_1a92f4.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die Gegenstandskennung des Rezepts (p2).
 * - Rückgabewert: Gibt die Gegenstandskennung des zugehörigen Tranks (d_1a92f4[s]) zurück.
 * - Wichtige Variablen: s ist der in d_1a92d0 gefundene Tabellenindex.
 === Ende Beschreibung === */
short f_136e60(int p1, int p2)
{
    short s = f_149360((short)p2, (int)d_1a92d0);
    return d_1a92f4[s];
}
//@ f_136e80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht den Tabellenindex einer Rezeptkennung (p2) in der Rezeptliste d_1a92d0.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt den Index in d_1a92d0 (in Register AX) oder -1 zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_136e80(int p1, int p2)
{
    f_149360((short)p2, (int)d_1a92d0);
}
//@ f_136e90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sucht den Tabellenindex einer Dokumentkennung (p2) in der Dokumentenliste d_1a9316.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt den Index in d_1a9316 oder -1 zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_136e90(int p1, int p2)
{
    return f_149360((short)p2, (int)d_1a9316);
}
//@ f_136ea0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob eine Gegenstandskennung (p2) ein gültiges abschreibbares Dokument aus der Liste
 *   d_1a9316 ist.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die zu prüfende Gegenstandskennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn p2 > 0 in d_1a9316 vorkommt, sonst 0.
 * - Wichtige Variablen: r speichert das boolesche Ergebnis.
 === Ende Beschreibung === */
int f_136ea0(int p1, int p2)
{
    int r = 0;
    if (0 < (short)p2) {
        if (f_149360((short)p2, (int)d_1a9316) != -1) r = 1;
    }
    return r;
}
//@ f_136ed0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob eine Gegenstandskennung (p2) ein gültiges alchemistisches Rezept aus der Liste
 *   d_1a92d0 ist.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die zu prüfende Gegenstandskennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn p2 > 0 in d_1a92d0 enthalten ist, sonst 0.
 * - Wichtige Variablen: r speichert das boolesche Ergebnis.
 === Ende Beschreibung === */
int f_136ed0(int p1, int p2)
{
    int r = 0;
    if (0 < (short)p2) {
        if (f_149360((short)p2, (int)d_1a92d0) != -1) r = 1;
    }
    return r;
}
//@ f_136f00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sammelt alle alchemistischen Rezepte (d_1a92d0), die der Held (P10) in seinen Rucksackslots
 *   (15 bis 30) trägt, in der übergebenen Listenstruktur p2.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie ein Zeiger auf die zu füllende Listenstruktur
 *   (p2).
 * - Rückgabewert: Gibt die Anzahl der gefundenen Rezepte (p2->n) zurück.
 * - Wichtige Variablen: s4 durchläuft die Slots 0xf bis 0x1e, s2 ist die jeweilige Gegenstandskennung.
 === Ende Beschreibung === */
short f_136f00(int p1, L *p2)
{
    short s2, s3, s4;
    int p, ok;
    for (s4 = 0xf; s4 <= 0x1e; s4++) {
        s2 = f_042a60((struct hero *)(P10), s4);
        p = s2;
        if (0 < p) {
            ok = 0;
            if (0 < p) {
                s3 = f_149360(p, (int)d_1a92d0);
                if (s3 != -1) ok = 1;
            }
            if (ok) {
                p2->a[p2->n] = s4;
                p2->b[p2->n] = s2;
                p2->n = p2->n + 1;
            }
        }
    }
    return p2->n;
}
//@ f_136f70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Sammelt analog zu f_136f00 alle losen Dokumente (d_1a9316) aus den Rucksackslots (15 bis 30)
 *   des Helden (P10) in der Listenstruktur p2.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie ein Zeiger auf die Listenstruktur (p2).
 * - Rückgabewert: Gibt die Anzahl der gefundenen Dokumente (p2->n) zurück.
 * - Wichtige Variablen: s4 ist der Slotindex, s2 die Gegenstandskennung.
 === Ende Beschreibung === */
short f_136f70(int p1, L *p2)
{
    short s2, s3, s4;
    int p, ok;
    for (s4 = 0xf; s4 <= 0x1e; s4++) {
        s2 = f_042a60((struct hero *)(P10), s4);
        p = s2;
        if (0 < p) {
            ok = 0;
            if (0 < p) {
                s3 = f_149360(p, (int)d_1a9316);
                if (s3 != -1) ok = 1;
            }
            if (ok) {
                p2->a[p2->n] = s4;
                p2->b[p2->n] = s2;
                p2->n = p2->n + 1;
            }
        }
    }
    return p2->n;
}
//@ f_136fe0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet beim Benutzen eines *Notizbuchs* (0x1dc in Slot p2) das Inhaltsverzeichnis aller
 *   darin eingetragenen Dokumente (f_03d860) und lässt den Spieler in einer Schleife beliebige Einträge über die
 *   Pergament-Ansicht f_1374f0 lesen; ist das Notizbuch noch leer (cnt == 0), erscheint 0x1e010089, und bei
 *   genau einem Eintrag (cnt == 1) wird dieser sofort ohne Auswahlmenü angezeigt.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Inventarslot des Notizbuchs (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: cnt zählt die im Notizbuch gespeicherten Dokumente, texts (d_1c259c) und values
 *   (d_1c2600) halten deren Namen und Gegenstandskennungen, und done beendet die Leseschleife bei Abbruch oder
 *   Einzelanzeige.
 === Ende Beschreibung === */
void f_136fe0(int p1, short p2)
{
    short cnt = 0;
    short *values;
    int *texts;
    texts = d_1c259c;
    values = d_1c2600;
    short idx;
    int done = 1; // toter Startwert fuer Registerwahl wie im Original (Argon 851)
    short r = -1;

    for (idx = 0; d_1a9316[idx] != -1; idx++) {
        int *text = (int *)(d_1c21b4 + idx * 0x32);
        if (f_03d860(P10, (short)p2, idx)) {
            f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[d_1a9316[idx]]),(char *)( (int)text), 1);
            texts[cnt] = f_133fe0((int)d_1c3498, (int)text);
            values[cnt] = d_1a9316[idx];
            cnt++;
        }
    }

    do {
        r = -1;
        done = 1;
        if (cnt == 0) {
            MSG(0x1e010089);
        } else if (cnt == 1) {
            r = values[0];
        } else {
            int input;
            f_0bf6c0((int)d_1c2c64, 5);
            input = f_0bf820((int)d_1c2c64, 0x1e010093, cnt,
                                    texts[0], texts[1], texts[2], texts[3],
                                    texts[4], texts[5], texts[6], texts[7],
                                    texts[8], texts[9], texts[10], texts[11],
                                    texts[12], texts[13], texts[14], texts[15],
                                    texts[16], texts[17]);
            f_0bf680((int)d_1c2c64);
            if ((short)input != -1) {
                r = values[(short)input - 1];
                done = 0;
            }
        }
        if (r != -1)
            f_1374f0(p1, r);
    } while (!done);
}
//@ f_137180
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet beim Benutzen eines *Rezeptbuchs* (0xbf in Slot p2) das Inhaltsverzeichnis aller bis
 *   zu 17 darin eingetragenen alchemistischen Rezepte und zeigt das vom Spieler gewählte Rezept über f_138330
 *   auf einer Pergamentrolle an; ist das Rezeptbuch noch leer (count == 0), erscheint die Meldung 0x1e010089.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie der Inventarslot des Rezeptbuchs (p2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: count zählt die eingetragenen Rezepte, names und d_1c29c4 speichern die Tranknamen aus
 *   d_1a92f4, und indices bildet die Menüauswahl auf die Rezepttabelle d_1a68f4 ab.
 === Ende Beschreibung === */
void f_137180(int p1, short p2)
{
    short selection = 0;
    short count = 0;
    short index = 0;
    char names[340];
    char indices[20];

    for (index = 0; index < 17; index++) {
        if (f_03d860(P10, p2, index)) {
            f_0a7840((RivaItemDefinition *)((*(int **)&d_1c2c40)[d_1a92f4[index]]),(char *)( (int)(names + count * 20)), 1);
            d_1c29c4[count] = f_133fe0((int)d_1c3498, (int)(names + count * 20));
            indices[count] = (char)index;
            count++;
        }
    }

    if (count) {
        while (selection != -1) {
            if (count > 1) {
                selection = (short)f_0bf820((int)d_1c2c64, 0x1e010092, count,
                    d_1c29c4[0], d_1c29c4[1], d_1c29c4[2], d_1c29c4[3],
                    d_1c29c4[4], d_1c29c4[5], d_1c29c4[6], d_1c29c4[7],
                    d_1c29c4[8], d_1c29c4[9], d_1c29c4[10], d_1c29c4[11],
                    d_1c29c4[12], d_1c29c4[13], d_1c29c4[14], d_1c29c4[15],
                    d_1c29c4[16]);
                if (selection != -1) selection--;
            } else {
                selection = 0;
            }
            if (selection != -1) {
                short value = d_1a68f4[(signed char)indices[selection] * 14];
                f_138330(p1, value);
                if (count == 1) selection = -1;
            }
        }
    } else {
        f_0bf730((int)d_1c2c64, 0x1e010089);
    }
}
//@ f_137350
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob eine Gegenstandskennung (p2) zu den acht magischen Büchern in der Tabelle d_1a935a
 *   gehört.
 * - Eingaben: Ein ungenutzter Kontextzeiger (p1) sowie die Gegenstandskennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn p2 > 0 in d_1a935a vorkommt, sonst 0.
 * - Wichtige Variablen: r speichert das Prüfergebnis.
 === Ende Beschreibung === */
int f_137350(int p1, int p2)
{
    int r = 0;
    if (0 < (short)p2) {
        if (f_149360((short)p2, (int)d_1a935a) != -1) r = 1;
    }
    return r;
}

//@ f_1373a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt beim Lesen eines der acht magischen Bücher (0x1bd bis 0x1c4) den zugehörigen Buchtext
 *   (0x1e0100a5 bis 0x1e0100ac) mit dem Namen des lesenden Helden (P10) in einem Dialogfenster aus.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1) sowie die Buchkennung (action).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: obj ist der lokale Textkontext für den Heldennamen.
 === Ende Beschreibung === */
void f_1373a0(int p1, int action)
{
    OB;
    int code=action;
    { int *q = *(int * volatile *)&obj.slots[0]; q[1] = P10; } // erzwingt Laden von obj.slots[0] vor *(p1 + 0x10)
    switch ((short)code) {
    case 0x1bd: MSG(action = 0x1e0100a5); return;
    case 0x1be: MSG(action = 0x1e0100a6); return;
    case 0x1bf: MSG(action = 0x1e0100a7); return;
    case 0x1c0: MSG(action = 0x1e0100a8); return;
    case 0x1c1: MSG(action = 0x1e0100a9); return;
    case 0x1c2: MSG(action = 0x1e0100aa); return;
    case 0x1c3: MSG(action = 0x1e0100ab); return;
    case 0x1c4: MSG(action = 0x1e0100ac); break;
    }
}

//@ f_136290
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt die Kombination von *Schreibzeug* (Slot p2) mit einem einzelnen Dokument (Slot
 *   p3): Die Funktion sucht im Inventar des Helden nach einem vorhandenen *Notizbuch* (0x1dc) oder ersatzweise
 *   einem leeren *Buch* (0x1d) und trägt das Dokument über f_135ef0 dort ein; besitzt der Held kein passendes
 *   Buch, erscheint die Fehlermeldung 0x1e010088.
 * - Eingaben: Ein Zeiger auf den Benutzungskontext (p1), der Schreibzeug-Slot (p2) und der Dokument-Slot (p3).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: l14 speichert den gefundenen Inventarslot des Notiz- bzw. leeren Buches (-1, falls
 *   keines vorhanden ist). *(Hinweis: Im Quelltext use_t2_P1.CPP steht f_136290 am Dateiende, liegt im Binärcode
 *   aber zwischen f_136250 und f_136340).*
 === Ende Beschreibung === */
void f_136290(int p1, int p2, int p3)
{
    register int q;
    short l14;
    p2 = ((int (*)(int, short))f_1364f0)(p1, (short)p2);
    if ((short)p2 != -1) {
        l14 = f_0d4aa0(P10, 0x1dc);
        q = p1;
        if (l14 == -1) l14 = f_0d4aa0(P10, 0x1d);
        if (l14 == -1) {
            OB;
            int value = *(int *)(q + 0x10);
            *(int *)(obj.slots[0] + 4) = value;
            MSG(0x1e010088);
        }
        if (l14 != -1) f_135ef0(p1, l14, (short)(*&p3), (short)p2);
    }
}
