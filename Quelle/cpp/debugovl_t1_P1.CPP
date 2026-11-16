/* === Beschreibung (Katalog) ===
 * Einheit debugovl_t1 (052400 - 0538a0)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des Entwickler- und Diagnose-Overlays (debugovl.cpp). Sie stellt
 * interaktive Textmodus-Inspektoren für die interne Speicherverwaltung (f_052400), für geöffnete Dateigrößen
 * (f_052670), für sämtliche registrierten 1-Byte-, 2-Byte- und 4-Byte-Spielstandvariablen (f_052850, f_052c50,
 * f_052f40, f_053230), für das Soundsystem (f_0535a0) sowie für die System- und Versionsübersicht (f_053700)
 * bereit.
 === Ende Beschreibung === */
// P3 8/14 gleich (suche.py 30.10.2026, Basis debugovl_t1_P1.CPP)
// P2 Koepfe Stufe Misch (1 Ueberladungen) (Fable K): 5 gleich (vorher 5), Rest 956 (vorher 973)
// debugovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x052400-0x0538a0
#include <string.h>
#include "RIVAMEM.H"



int f_14d36e(int a); int f_14d36e(int a, int);
int f_14d1c1(short a, short b);
int f_14d27d(const char *fmt, ...);
int f_14572e(char *buf, const char *fmt, ...);
char *f_14d50b(const char *s, const char *t);
int f_1452bc(int h);
int f_014a70();
int f_053a30(short x, short y, const char *fmt, ...);
int f_0538a0(int x, int y, char *buf, const char *msg);
int f_14d5c9(char *buf, int n);
int f_14d5c9(char *buf);
int f_149cf0(int ms);
int f_149d20();
unsigned short f_149d50();
int f_147869(char *o, int i);
short f_1478b4(char *o);
short f_147904(char *o);
void f_1478de(char *o);
void f_14792e(char *o);
int f_05fd00();
int f_14d636();
int f_0144e0();
int f_0bdbc0(char *o);
int f_0bdbf0(char *o);
int f_0bdc20(char *o);
int f_0bdc30(char *o);
int f_059d50(int p);
int f_059d50(int p, int fl);
int f_05a020(int p, const char *s);
struct R5 { int a, b; char *s; int d, e; };
struct A1 { signed char v; unsigned short id; };
struct A2 { short v; unsigned short id; };
struct A3 { int v; unsigned short id; };
struct B80 { int a[20]; };
struct B40 { int a[10]; };
extern short d_1a1490;
extern short d_1bc61c;
extern short d_1bc61e;
extern int d_1bc60c;
extern int d_1bc610;
extern int d_1c0ae0;
extern int d_1c0c4c;
extern int d_1bc97c;
extern int d_1c2a54;
extern int d_1a1950;
extern int d_1bc608;
extern int d_1bc984;
extern R5 *d_1bc614;
extern short d_1c212a;
extern A1 **d_1c212c;
extern short d_1c2132;
extern A2 **d_1c2134;
extern short d_1c213a;
extern A3 **d_1c213c;
extern short d_1bfad6;
extern A1 **d_1bfad8;
extern B80 d_1a1498;
extern B40 d_1a1518;
extern B40 d_1a1540;
extern B40 d_1a1568;
extern char d_1c2edc[];
extern char d_1c11a0[];
extern const char d_1b6709[], d_1b670e[], d_1b6715[], d_1b6723[], d_1b672c[], d_1b6730[], d_1b6735[], d_1b673a[];
extern const char d_1b6764[], d_1b6792[], d_1b67d0[], d_1b67d2[], d_1b67d4[], d_1b67f7[];
extern const char d_1b6825[], d_1b682f[], d_1b684d[], d_1b6883[], d_1b68b9[], d_1b68cc[], d_1b68ec[];
extern const char d_1b6904[], d_1b690f[], d_1b691f[], d_1b6962[], d_1b6964[], d_1b697c[], d_1b699f[], d_1b69b2[];
extern const char d_1a14e8[];
extern const char d_1b69f0[], d_1b69fb[], d_1b6a0b[], d_1b6a1d[], d_1b6a35[], d_1b6a58[], d_1b6a6b[];
extern const char d_1b6aa9[], d_1b6ab4[], d_1b6ac4[], d_1b6ad9[], d_1b6af1[], d_1b6b16[], d_1b6b29[];
extern const char d_1b6b68[], d_1b6b73[], d_1b6b83[], d_1b6b93[], d_1b6bab[], d_1b6bce[], d_1b6be1[];
extern const char d_1b6c05[], d_1b6c14[], d_1a1470[], d_1b6c1a[], d_1b6c1b[], d_1b6c1f[], d_1b6c3b[], d_1b6c3c[], d_1b6c40[], d_1b6c5c[], d_1b6c77[], d_1b6c92[];
extern const char d_1c20b4[], d_1b6c95[], d_1a9644[], d_1a9650[], d_1b6ca7[], d_1b6cbe[], d_1b6cc6[], d_1b6ccc[], d_1b6cd2[], d_1b6cf0[], d_1b6d11[], d_1b6d32[], d_1b6d53[];
//@ f_052400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet den interaktiven Heap- und Speicherblock-Inspektor, der alle bis zu 2500 (0x9c4)
 *   Einträge der internen Speicherverwaltung (d_1bc614) mit Start-/Endadresse, Blockgröße, Quelldateiname und
 *   Zeilennummer seitenweise zu je 18 Zeilen anzeigt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Mit den Pfeiltasten, Bild-auf/ab (±100), Pos1 und Ende blättert der Entwickler durch die
 *   Tabelle d_1bc614, bis die Taste q (0x1071) gedrückt wird.
 === Ende Beschreibung === */
void f_052400()
{
    int len;
    int ee;
    int d;
    int fin;
    int a;
    int b;
    short i;
    short y;
    short idx;
    int page;
    char *p;
    char *name;
    R5 *e;
    unsigned short k;
    idx = 0;
    fin = 0;
    short rt950_0; int rt950_1; short rt950_2; int rt950_3; // Haelt die Roundtrip-Variablen fuer die Schleife
    do {
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        f_053a30(1, 1, d_1b673a, d_1b6735, d_1b6730, d_1b672c, d_1b6723, d_1b6715, d_1b670e, d_1b6709);
        f_053a30(1, 2, d_1b6764, d_1bc60c, (short)f_014a70(), 0x9c4, d_1bc61c, d_1bc61e, d_1bc610, d_1c0ae0);
        f_053a30(8, 4, d_1b6792);
        y = 6;
        // Haelt die Roundtrips um den Seiten-Store
        rt950_0 = d_1a1490;
        rt950_1 = d_1bc60c;
        rt950_3 = d_1bc610;
        page = 0x12;
        d_1a1490 = rt950_0;
        d_1bc60c = rt950_1;
        d_1bc610 = rt950_3;
        for (i = 0; i < (short)0x12 && i + idx < 0x9c4; i++, y++) {
            R5 *t = d_1bc614; e = &t[i + idx];
            a = e->a;
            b = e->b;
            name = e->s;
            d = e->d;
            ee = e->e;
            p = f_14d50b(name, "\\");
            while (p) {
                name = p + 1;
                p = f_14d50b(name, "\\");
            }
            len = a ? b - a - 4 : 0;
            f_053a30(8, y, d_1b67d4, idx + i, a, b, len, ee, name, d);
        }
        f_053a30(1, 0x19, d_1b67f7);
        f_149d20();
        k = f_149d50();
        switch (k) {
        case 0x4700: idx = 0; break;
        case 0x4f00: idx = (d_1bc61c / 10) * 10; break;
        case 0x4800: idx -= page; break;
        case 0x5000: idx += page; break;
        case 0x4900: idx -= 100; break;
        case 0x5100: idx += 100; break;
        case 0x1071: fin = 1; fin = (fin & 0) ? 0 : fin; break; // Haelt fin in eigenem Register
        }
        if (idx < 0) idx = 0;
        else if (idx > 0x9ba) idx = 0x9ba;
    } while (!fin);
    rt950_2 = d_1bc61c; d_1bc61c = rt950_2; // Haelt die Registerfolge nach der Schleife
}

//@ f_052670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt eine seitenweise blätterbare Debug-Tabelle über 100 Datei-Handles und deren aktuelle
 *   Dateigrößen (f_1452bc) an.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter (void) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das lokale Array fl[100] speichert die ermittelten Dateigrößen, cnt zählt die gültigen
 *   Einträge (> 0), und mit den Pfeiltasten wird in 10er-Schritten geblättert.
 === Ende Beschreibung === */
void f_052670()
{
    
    short pg = 0;
    int fl[100]; short cnt = 0;
    int fin;
    int len, q;
    short i, s5;
    unsigned short k;
    int quit;

    quit = 0;
    i = 0;
    goto file_body;
file_next:
    i++;
    if (i >= (short)100) goto files_done;
file_body:
    {
        len = f_1452bc(pg + (short)i);
        if (len < (short)0) len = pg;
        fl[i] = len;
        if (len > (short)0) cnt++;
    }
    goto file_next;
files_done:
    fin = 0;
    do {
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        f_14d1c1(3, 0x12);
        f_14d27d(d_1b6825);
        f_14d1c1(4, 8);
        f_14d27d(d_1b682f, (short)cnt);
        f_14d1c1(5, 8);
        f_14d27d(d_1b684d);
        f_14d1c1(8, 8);
        f_14d27d(d_1b6883);

        i = 0xb;
        for (s5 = 0; s5 < 10 && (int)s5 + (int)(short)pg < 100; s5++) {
            q = (int)s5 + (int)(short)pg;
            f_14d1c1(i, 8);
            i++;
            f_14d27d(d_1b68b9, q, fl[q]);
        }

        f_053a30(8, 0x18, d_1b68cc);
        f_053a30(8, 0x19, d_1b68ec);
        f_149d20();
        k = f_149d50();
        switch (k) {
        case 0x4700:
            pg = 0;
            break;
        case 0x4f00:
            pg = (d_1bc61c / 10) * 10;
            break;
        case 0x4800:
            pg -= 10;
            break;
        case 0x5000:
            pg += 10;
            break;
        case 0x1071:
            fin = 1;
            break;
        }
        if (pg < 0)
            pg = 0;
        else if (pg > 0x5a)
            pg = 0x5a;
    } while (!fin);
}

//@ f_052850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt die in der Savegame-Tabelle d_1c212c registrierten 1-Byte-Statusvariablen (signed char,
 *   d_1c212a Einträge) in einer 20 x 4-Matrix nach ihren Kennnummern (id) geordnet an und erlaubt mit der Taste
 *   c (0x2e63) das gezielte Abändern einzelner Variablenwerte zur Laufzeit.
 * - Eingaben und Rückgabe: Die Funktion erhält eine Startzeile p1 (short, die intern aus d_1a1490 überschrieben
 *   wird) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tasten n (weiter), p (id -= 0xa0, eine Seite zu 80 Einträgen zurück), s (id = 1,
 *   Anfang), c (Wert ändern über f_0538a0) und q (Beenden) steuern den Editor.
 === Ende Beschreibung === */
void f_052850(short p1)
{
    struct Match { static int test(unsigned short field) { return field; } };
    char msg[52];
    B80 buf;
    int fin;
    short lo;
    short hi;
    volatile short id;
    short row;
    short idv;
    short col;
    short y;
    short i;
    short cur;
    short edit_cur;
    short edit_i;
    signed char value;
    int ok;
    unsigned short k;
    A1 *rp, *t;
    extern const char d_1b692f[];
    (void)&idv; (void)&hi; (void)&lo; (void)&col; (void)&row; (void)&y; // Haelt die lokalen Variablen in festen Stack-Slots
    p1 = d_1a1490;
    hi = ++p1;
    id = 1;
    lo = p1 - 2;
    do {
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        fin = 0;
        if (id < 1) id = 1;
        f_053a30(0xe, lo, d_1b6904);
        row = 0;
        do {
            col = 0;
            y = hi + row;
            do {
                const char *fmt = d_1b690f;
                f_14d1c1(y, col * 0x12 + 4);
                cur = id;
                rp = 0;
                for (i = 0; i < d_1c212a && !rp; i++) {
                    A1 **base = d_1c212c;
                    if (Match::test(base[i]->id) == (int)cur) rp = base[i];
                }
                if (rp) {
                    value = rp->v;
                    f_14d27d(fmt, id, value);
                } else {
                    f_14d27d(d_1b691f, id);
                }
                id++;
                col++;
            } while (col < (short)4);
            row++;
        } while (row < (short)0x14);
        do {
            buf = d_1a1498;
            f_053a30(4, 0x19, d_1b692f);
            ok = 1;
            f_149d20();
            k = f_149d50();
            switch (k) {
            case 0x1970: id -= 0xa0; break;
            case 0x1f73: id = 1; break;
            case 0x1071: fin = 1; break;
            case 0x2e63:
                {
                    short x = 1;
                    f_14d1c1(0x17, x);
                    while (x++ < 0x50) f_14d27d(d_1b6962);
                }
                f_0538a0(4, 0x17, (char *)&buf, d_1b6964);
                { int parsed = f_14d5c9((char *)&buf); idv = (short)parsed; edit_cur = (short)parsed; } rp = 0;
                for (edit_i = 0; edit_i < d_1c212a; edit_i++) {
                    if (rp) break;
                    int index = edit_i; A1 **base = d_1c212c; if (index & 0) index = 0; /* Haelt index in eigenem Register */ t = base[index];
                    if ((t->id & 0xffff) == (int)edit_cur) rp = t;
                }
                {
                    A1 *dst = rp;
                    if (dst) {
                    value = dst->v;
                    f_14572e(msg, d_1b697c, idv, value);
                    {
                        short x = 1;
                        f_14d1c1(0x17, x);
                        while (x++ < 0x50) f_14d27d(d_1b6962);
                    }
                    f_0538a0(4, 0x17, (char *)&buf, msg);
                    value = f_14d5c9((char *)&buf);
                    dst->v = value;
                    {
                        short x = 1;
                        f_14d1c1(0x17, x);
                        while (x++ < 0x50) f_14d27d(d_1b6962);
                    }
                    f_053a30(4, 0x17, d_1b699f, idv, value);
                    } else {
                    {
                        short x = 1;
                        f_14d1c1(0x17, x);
                        while (x++ < 0x50) f_14d27d(d_1b6962);
                    }
                    f_053a30(4, 0x17, d_1b69b2);
                    }
                }
                f_149cf0(0x3e8);
                id -= 0x50;
                break;
            case 0x316e: break;
            default: ok = 0;
            }
        } while (!ok);
    } while (fin == 0);
}


//@ f_052c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt die in der Savegame-Tabelle d_1c2134 registrierten 16-Bit-Variablen (short, d_1c2132
 *   Einträge) in einer 20 x 4-Matrix an und erlaubt das interaktive Editieren beliebiger short-Spielstandswerte
 *   über die Taste c.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durchsucht und verändert werden die A2-Einträge (short v; unsigned short id;) im
 *   globalen Zeigerarray d_1c2134.
 === Ende Beschreibung === */
// Debug-Seite Tabelle d_1c2134 (A2-Eintraege): 20 Zeilen x 4 Spalten anzeigen, Wert aendern
void f_052c50(short p1)
{
    char msg[52];
    B40 buf;
    int fin;
    volatile short id;
    short hi;
    short row;
    short y;
    short lo;
    short col;
    short idv;
    short i;
    short cur;
    short value;
    int ok;
    unsigned short k;
    A2 *rp, *rp2, *t;
    extern const char d_1b69d6[];
    p1 = d_1a1490;
    hi = ++p1;
    col = (col & 0) ? 0 : col; // Haelt col vorab im Registerverteiler
    id = 1;
    lo = p1 - 2;
    do {
        fin = 0;
        hi = (hi & 0) ? (short)0 : hi; // Haelt das Schleifengewicht fuer hi
        if (id < 1) id = 1;
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        f_053a30(4, lo, d_1b69d6);
        register const char *fmt = d_1b6a0b;
        row = 0;
        do {
            col = 0;
            y = hi + row;
            do {
                lo = (lo & 0) ? (short)0 : lo; // Haelt das Schleifengewicht fuer lo
                f_14d1c1(y, col * 0x12 + 4);
                cur = id;
                rp = 0;
                for (i = 0; i < d_1c2132 && !rp; i++)
                    if ((d_1c2134[i]->id & 0xffff) == (int)cur) rp = d_1c2134[i];
                if (rp) {
                    value = rp->v;
                    f_14d27d(d_1b69fb, id, value);
                } else {
                    f_14d27d(fmt, id);
                }
                id++;
                col++;
            } while (col < (short)4);
            row++;
        } while (row < (short)0x14);
        do {
            f_053a30(4, 0x19, d_1a14e8);
            ok = 1;
            f_149d20();
            k = f_149d50();
            switch (k) {
            case 0x1970: id -= 0xa0; break;
            case 0x1f73: id = 1; break;
            case 0x1071: fin = 1; break;
            case 0x2e63:
                buf = d_1a1518;
                f_0538a0(4, 0x15, (char *)&buf, d_1b6a1d);
                idv = f_14d5c9((char *)&buf);
                rp2 = 0;
                cur = idv;
                for (i = 0; i < d_1c2132 && rp2 == 0; i++) {
                    A2 **table = d_1c2134;
                    d_1c2134 = table;
                    t = table[i];
                    if ((t->id & 0xffff) == (int)cur) rp2 = t;
                }
                idv = (idv & 0) ? (short)0 : idv; // Haelt das Gewicht fuer idv
                if (rp2) {
                    value = (i & 0) ? (short)0 : rp2->v; // Materialisiert den schmalen Lesewert
                    f_14572e(msg, d_1b6a35, idv, value);
                    f_0538a0(4, 0x16, (char *)&buf, msg);
                    value = f_14d5c9((char *)&buf);
                    rp2->v = value;
                    f_053a30(4, 0x17, d_1b6a58, idv, value);
                } else {
                    f_053a30(4, 0x15, d_1b6a6b);
                }
                f_149cf0(0x1f4);
                id -= 0x50;
                break;
            case 0x316e: break;
            default: ok = 0;
            }
        } while (!ok);
    } while (fin == 0);
}



//@ f_052f40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt die in der Savegame-Tabelle d_1c213c registrierten 32-Bit-Variablen (int, d_1c213a
 *   Einträge, z. B. Timer und Zähler) in einer 20 x 3-Matrix (60 Einträge pro Seite) an und erlaubt das
 *   Editieren einzelner Werte über die Taste c.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Durchsucht werden die A3-Einträge (int v; unsigned short id;) in d_1c213c. Hinweis auf
 *   zwei Originalfehler: Erstens wird beim Editieren (case 0x2e63, 531a3) der eingelesene 32-Bit-Wert über movsx
 *   edi, ax auf 16 Bit (short) abgeschnitten, bevor er in das 32-Bit-Feld rp2->v geschrieben wird (Werte
 *   außerhalb von -32768..32767 laufen über). Zweitens zieht die Taste p (case 0x1970, vorherige Seite) nur 0x3c
 *   (60) statt 0x78 (120) von id ab und zeigt daher immer wieder dieselbe Seite an, statt rückwärts zu blättern.
 === Ende Beschreibung === */
void f_052f40(short p1)
{
    struct Match { static int test(unsigned short field) { return field; } };
    char msg[52];
    B40 buf;
    int fin;
    volatile short id;
    short hi;
    short row;
    short y;
    short lo;
    short col;
    short idv;
    short i;
    short cur;
    int value;
    int ok;
    unsigned short k;
    A3 *rp, *rp2;
    extern const char d_1b6a8e[];
    p1 = d_1a1490;
    hi = ++p1;
    id = 1;
    lo = p1 - 2;
    do {
        fin = 0;
        if (id < 1) id = 1;
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        f_053a30(4, lo, d_1b6a8e);
        row = 0;
        do {
            col = 0;
            y = hi + row;
            do {
                const char *fmt = d_1b6ab4;
                { short rt1=d_1c213a;
                  d_1c213a=rt1; } // Haelt die Vorlisten-Sortierung fuer d_1c213a
                f_14d1c1(y, col * 0x16 + 4);
                cur = id;
                rp = 0;
                for (i = 0; i < d_1c213a && !rp; i++) {
                    A3 **base = d_1c213c;
                    if (Match::test(base[i]->id) == (int)cur) rp = base[i];
                }
                if (rp) {
                    value = rp->v;
                    f_14d27d(fmt, id, value);
                } else {
                    f_14d27d(d_1b6ac4, id);
                }
                id++;
                col++;
            } while (col < (short)3);
            row++;
        } while (row < (short)0x14);
        do {
            (int &)ok = 1;
            f_053a30(4, 0x19, d_1a14e8);
            f_149d20();
            k = f_149d50();
            switch (k) {
            case 0x1970: id -= 0x3c; break;
            case 0x1f73: id = 1; break;
            case 0x1071: fin = 1; break;
            case 0x2e63:
                buf = d_1a1540;
                f_0538a0(4, 0x15, (char *)&buf, d_1b6ad9);
                idv = f_14d5c9((char *)&buf);
                rp2 = 0;
                cur = idv;
                for (i = 0; i < d_1c213a && !rp2; i++) {
                    { short rt2=d_1a1490; short rt3=d_1c213a; A3 **rt4=d_1c213c;
                      d_1a1490=rt2; d_1c213a=rt3; d_1c213c=rt4; } // Haelt die Vorlisten-Sortierung in der Suchschleife
                    if ((d_1c213c[i]->id & 0xffff) == (int)cur) rp2 = d_1c213c[i];
                }
                if (rp2) {
                    value = (i & 0) ? 0 : rp2->v; // Materialisiert den Lesewert
                    f_14572e(msg, d_1b6af1, idv, value);
                    f_0538a0(4, 0x16, (char *)&buf, msg);
                    value = (short)f_14d5c9((char *)&buf);
                    rp2->v = value;
                    f_053a30(4, 0x17, d_1b6b16, idv, (short)value);
                } else {
                    f_053a30(4, 0x16, d_1b6b29);
                }
                f_149cf0(0x1f4);
                id -= 0x3c;
                break;
            case 0x316e: break;
            default: ok = 0;
            }
        } while (!ok);
    } while (fin == 0);
}


//@ f_053230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt die in der zweiten 1-Byte-Tabelle d_1bfad8 (d_1bfad6 Einträge) registrierten Statusbytes
 *   in einer 20 x 4-Matrix an und ermöglicht deren gezielte Änderung über die Taste c.
 * - Eingaben und Rückgabe: Die Funktion erhält p1 (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bearbeitet werden die A1-Einträge im globalen Array d_1bfad8.
 === Ende Beschreibung === */
void f_053230(short p1)
{
    char msg[52];
    B40 buf;
    int fin;
    volatile short id;
    short hi;
    short row;
    short y;
    short lo;
    short col;
    short idv;
    short i = 0;
    short cur;
    signed char v1;
    signed char value;
    int ok;
    unsigned short k;
    A1 *rp, *rp2, *t;
    extern const char d_1b6b4c[];
    p1 = (short)(unsigned long)d_1b6b83; // Legt die Adresse des Fehlformats frueh an
    p1 = d_1a1490;
    hi = ++p1;
    id = 1;
    lo = p1 - 2;
    do {
        fin = 0;
        hi = (hi & 0) ? (short)0 : hi; // Haelt das Schleifengewicht fuer hi
        if (id < 1) id = 1;
        f_14d36e(0);
        f_14d1c1(1, 1);
        d_1a1490 = 1;
        f_053a30(4, lo, d_1b6b4c);
        row = 0;
        do {
            col = 0;
            y = hi + row;
        const char *fmtA6 = d_1b6b73;
            do {
                f_14d1c1(y, col * 0x12 + 4);
                cur = id;
                rp = 0;
                for (i = 0; i < d_1bfad6 && !rp; i++) {
                    A1 **base = d_1bfad8;
                    if ((base[i]->id & 0xffff) == (int)cur) rp = base[i];
                }
                if (rp) {
                    row = (row & 0) ? (short)0 : row; // Haelt das Schleifengewicht fuer row
                    v1 = rp->v;
                    f_14d27d(fmtA6, id, v1);
                } else {
                    row = (row & 0) ? (short)0 : row; // Haelt das Schleifengewicht fuer row
                    f_14d27d(d_1b6b83, id);
                }
                id++;
                col++;
            } while (col < (short)4);
            row++;
        } while (row < (short)0x14);
        do {
            f_053a30(4, 0x19, d_1a14e8);
            ok = 1;
            f_149d20();
            k = f_149d50();
            switch (k) {
            case 0x1970: id -= 0xa0; break;
            case 0x1f73: id = 1; break;
            case 0x1071: fin = 1; break;
            case 0x2e63:
                buf = d_1a1568;
                f_0538a0(4, 0x15, (char *)&buf, d_1b6b93);
                idv = f_14d5c9((char *)&buf);
                idv = (idv & 0) ? (short)0 : idv; // Haelt das Gewicht fuer idv
                rp2 = 0;
                cur = idv;
                for (i = 0; i < d_1bfad6 && rp2 == 0; i++) {
                    A1 **base2 = d_1bfad8;
                    d_1bfad8 = base2; // Haelt die Tabellenbasis in der Schleife
                    t = base2[i];
                    if ((t->id & 0xffff) == (int)cur) rp2 = t;
                }
                if (rp2) {
                    value = rp2->v;
                    f_14572e(msg, d_1b6bab, idv, value);
                    f_0538a0(4, 0x16, (char *)&buf, msg);
                    value = f_14d5c9((char *)&buf);
                    rp2->v = value;
                    rp2 = ((unsigned long)rp2 & 0) ? (A1 *)0 : rp2; // Haelt rp2 bis nach dem Store
                    f_053a30(4, 0x17, d_1b6bce, idv, value);
                } else {
                    f_053a30(4, 0x16, d_1b6be1);
                }
                f_149cf0(0x1f4);
                id -= 0x50;
                break;
            case 0x316e: break;
            default: ok = 0;
            }
        } while (!ok);
    } while (fin == 0);
}


//@ f_053520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine Abschiedsmeldung im Debug-Monitor aus, wartet eine halbe Sekunde (500 ms) und setzt
 *   das Beendigungsflag d_1bc984 = 1, um die Debug-Konsole zu schließen.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Gesetzt wird d_1bc984 = 1.
 === Ende Beschreibung === */
void f_053520()
{
    f_053a30(5, 0x12, d_1b6c05);
    f_149cf0(0x1f4);
    d_1bc984 = 1;
}
//@ f_053550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt temporär ein Datei-/Verzeichnis-Auswahlobjekt (0x652 Bytes) an, führt die
 *   Debug-Dateifunktion f_05a020 mit dem Muster d_1b6c14 aus und gibt das Objekt anschließend wieder frei.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das temporäre Objekt wird über f_059d50 konstruiert und abgebaut.
 === Ende Beschreibung === */
void f_053550()
{
    int t_ = (int)operator new(0x652, mark(d_1a1470, 0x8e0));
    int p = (t_ != 0) ? f_059d50(t_) : t_;
    f_05a020(p, d_1b6c14);
    if (p) operator delete((void *)f_059d50(p, 0));
}
//@ f_0535a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine Diagnoseübersicht über die 16 digitalen Soundkanäle des Audiosystems (d_1c2edc)
 *   sowie aktive Sound-Handles aus und wartet auf einen Tastendruck.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Für die Kanäle 0 bis 15 fragt f_147869(d_1c2edc, i) den Kanalstatus ab, während f_1478b4
 *   und f_147904 globale Sound-Statuswerte liefern.
 === Ende Beschreibung === */
void f_0535a0()
{
    short n = 0x10;
    short r1 = 4;
    short r3 = 4;
    short i, j;
    int f_14d1c1_local(short, short);
    #pragma aux f_14d1c1_local "f_14d1c1" parm [eax] [edx] value [eax] modify [esi];
    for (i = 0; i < 8; i++) {
        f_14d1c1(r3, 4);
        f_14d27d(d_1b6c1f, (int)i, f_147869(d_1c2edc, i) ? d_1b6c1a : d_1b6c1b);
        r3++;
    }
    j = 8;
    const char *msg;
    if (j >= n) goto end_loop;
    r3 = r1;
second_loop:
        f_14d1c1_local(r3, 0x28);
        if (!f_147869(d_1c2edc, j)) goto false_msg;
        msg = d_1b6c3b;
second_print:
        f_14d27d(d_1b6c40, (int)j, msg);
        r3++;
        j++;
        if (j >= n) goto end_loop;
        goto second_loop;
false_msg:
    msg = d_1b6c3c;
    goto second_print;
end_loop:
    f_14d1c1(r1 + n / 2 + 1, 4);
    f_14d27d(d_1b6c5c, (int)f_1478b4(d_1c2edc));
    f_14d1c1(r1 + n / 2 + 2, 4);
    f_14d27d(d_1b6c77, (int)f_147904(d_1c2edc));
    f_1478de(d_1c2edc);
    f_14792e(d_1c2edc);
    f_149d50();
}
//@ f_0536e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Verschachtelungszähler d_1c0c4c auf dem Debug-Bildschirm aus.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ausgegeben wird die globale Variable d_1c0c4c.
 === Ende Beschreibung === */
void f_0536e0()
{
    f_14d27d(d_1b6c92, d_1c0c4c);
}
//@ f_053700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Kopfbereich des Debug-Monitors mit Programmversion, Übersetzungsdatum (d_1a9650,
 *   d_1a9644), freiem DOS-/DPMI-Speicher und aktuellen Systemzählern auf dem Textbildschirm aus und setzt die
 *   aktuelle Ausgabezeile d_1a1490 auf 14 (0x0e).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0bdc20, f_0bdbc0, f_0bdc30 und f_0bdbf0 werden Speicher- und Systemwerte aus
 *   d_1c11a0 abgefragt und mit f_053a30 ausgegeben.
 === Ende Beschreibung === */
void f_053700()
{
    f_05fd00();
    f_14d636();
    f_053a30(4, 3, d_1b6c95, d_1c20b4);
    f_053a30(4, 5, d_1b6ca7, d_1a9650, d_1a9644);
    f_053a30(10, 7, d_1b6cd2, d_1b6ccc, d_1b6cc6, d_1b6cbe);
    f_053a30(10, 9, d_1b6cf0, f_0bdc20(d_1c11a0), d_1c2a54, d_1bc97c);
    f_053a30(10, 0xb, d_1b6d11, f_0bdbc0(d_1c11a0), f_0144e0(), f_05fd00());
    f_053a30(10, 0xa, d_1b6d32, f_0bdc30(d_1c11a0), d_1bc608, d_1a1950);
    f_053a30(10, 0xc, d_1b6d53, f_0bdbf0(d_1c11a0));
    d_1a1490 = 0xe;
}
//@ f_053810
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht eine Textzeile auf dem Debug-Bildschirm ab Spalte x in Zeile y bis zum rechten
 *   Bildschirmrand (Spalte 80) durch Überschreiben mit Leerzeichen.
 * - Eingaben und Rückgabe: Die Funktion erhält die Startspalte x (short) und die Zeile y (short) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Eine Schleife gibt bis x == 0x50 jeweils das Leerzeichen d_1b6962 über f_14d27d aus.
 === Ende Beschreibung === */
void f_053810(short x, short y)
{
    f_14d1c1(y, x);
    while (x++ < 0x50) f_14d27d(d_1b6962);
}
//@ f_053840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht den gesamten Textbildschirm, setzt den Cursor in die linke obere Ecke (1, 1), gibt den
 *   Systemkopf f_053700 aus und positioniert den Cursor anschließend in Zeile d_1a1490.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwendet und aktualisiert wird die globale Zeilennummer d_1a1490.
 === Ende Beschreibung === */
#pragma aux f_053700 "*"
void f_053840()
{
    f_14d36e(0);
    f_14d1c1(1, 1);
    d_1a1490 = 1;
    f_053700();
    short t = d_1a1490;
    f_14d1c1(t, 1);
}
//@ f_053880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht den gesamten Textbildschirm und setzt den Cursor sowie die Zeilennummer d_1a1490 auf
 *   (1, 1) zurück.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sie ruft f_14d36e(0) und f_14d1c1(1, 1) auf und setzt d_1a1490 = 1.
 === Ende Beschreibung === */
void f_053880()
{
    f_14d36e(0);
    f_14d1c1(1, 1);
    d_1a1490 = 1;
}
