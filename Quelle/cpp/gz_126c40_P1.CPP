/* === Beschreibung (Katalog) ===
 * Einheit gz_126c40 (0x126c40 - 0x1275b0)
 *
 * Überblick
 * Diese Einheit schließt das Zeit- und Kalendermodul (timeovl.cpp / time.cpp) ab und leitet zum
 * Magierturm-Dungeon (tower0.cpp, Dungeon-ID 0x12) über. Sie enthält die Speicher- und Laderoutinen für den
 * Spielstandsblock TIME, Zeitstempel-Berechnungsfunktionen für abgelaufene Zeitspannen sowie die Registrierung
 * und den Konstruktor der ersten Ebene des Magierturms (tower0).
 === Ende Beschreibung === */
#include "R_FIX.H"
// P3 6/8 gleich (suche.py 25.10.2026, Basis gz_126c40_P1.CPP)
// gz_126c40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x126C40-0x1275B0
#include <string.h>
#include "RIVAMEM.H"



int f_05ff60(int a, int b);
int f_126410(void *p);
signed char f_126430(void *p);
signed char f_126450(void *p);
signed char f_126460(void *p);
int f_144cb6(int h, const void *b, unsigned n);
int f_144e8b(int h, void *b, unsigned n);
extern char d_1b8508;
extern short d_1c2140;
extern char d_1c2c44;
extern short d_1c212a;
extern char **d_1c212c;
extern int d_1bbb0c;
struct T { int a; signed char b; signed char c; signed char d; };
#define BDECL char b[4];
#define BV b[0]
#define BP b
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_126c40
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die drei Grafikpuffer des Himmels-Overlays an den Offsets +0x0e, +0x12 und +0x16 des
 *   Zeit-Objekts wieder frei.
 * - Eingaben: Die Funktion erhält im Parameter self den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
// Original f_014710 bewahrt alle Register ausser EAX und liefert den Restzeiger.
void *release126c40(void *);
#pragma aux release126c40 "f_014710" modify exact [eax];
void f_126c40(char *self)
{
    *(void **)(self + 0x0e) = release126c40(*(void **)(self + 0x0e));
    *(void **)(self + 0x12) = release126c40(*(void **)(self + 0x12));
    *(void **)(self + 0x16) = release126c40(*(void **)(self + 0x16));
}
//@ f_126c70
/* === Beschreibung (Katalog) ===
 * - Zweck: Schreibt beim Speichern eines Spielstands den 13 Bytes langen Datenblock TIME (Tageszeit in Ticks,
 *   Wochentag, Tag, Monat, Jahr und Zusatzflags) in die Spielstandsdatei (d_1c2140).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt 1 als Erfolgscode zurück.
 === Ende Beschreibung === */
int f_126c70(char *p1)
{
    int lb, la;
    char b;
    la = 0xd;
    f_144cb6(d_1c2140, &d_1b8508, 4);
    f_144cb6(d_1c2140, &la, 2);
    // volatile erzwingt das Laden aus p1 und Schreiben in lb/b jeweils direkt vor dem Aufruf von f_144cb6
    lb = *(volatile int *)(p1 + 1);
    f_144cb6(d_1c2140, &lb, 4);
    b = *(volatile char *)(p1 + 0);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 5);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 7);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 8);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 9);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 6);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 10);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 0x1a);
    f_144cb6(d_1c2140, &b, 1);
    b = *(volatile char *)(p1 + 0x1b);
    f_144cb6(d_1c2140, &b, 1);
    return 1;
}
//@ f_126dd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest beim Laden eines Spielstands den Block TIME (0x454d4954) aus der Spielstandsdatei (d_1c2140)
 *   ein und stellt die gespeicherte Spielzeit sowie das Datum im Zeit-Objekt p1 wieder her.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zeit-Objekt.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Blockkennung TIME gefunden und gelesen wurde, andernfalls
 *   0.
 === Ende Beschreibung === */
int f_126dd0(char *p1)
{
    int m, v;
    int h;
    signed char b[4];
    f_144e8b(d_1c2140, &m, 4);
    if (m == 0x454d4954) {
        f_144e8b(d_1c2140, &h, 2);
        f_144e8b(d_1c2140, &v, 4);
        // volatile erzwingt das sofortige Zurueckschreiben nach p1 vor dem naechsten f_144e8b-Aufruf
        *(volatile int *)(p1 + 1) = v;
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 0) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 5) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 7) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 8) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 9) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 6) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile int *)(p1 + 10) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(volatile char *)(p1 + 0x1a) = b[0];
        f_144e8b(d_1c2140, b, 1);
        *(char *)(p1 + 0x1b) = b[0];
        return 1;
    }
    return 0;
}
//@ f_126f40
/* === Beschreibung (Katalog) ===
 * - Zweck: Speichert die aktuelle Spielzeit (Ticks a, Tag b, Monat c, Jahr d aus d_1c2c44) als Zeitstempel in
 *   der übergebenen Struktur p1.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf eine 7-Byte-Zeitstempelstruktur (struct T).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_126f40(struct T *p1)
{
    p1->a = f_126410(&d_1c2c44);
    p1->b = f_126430(&d_1c2c44);
    p1->c = f_126450(&d_1c2c44);
    p1->d = f_126460(&d_1c2c44);
}
//@ f_126f80
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt einen Zeitstempel p1 entweder direkt auf die übergebenen Werte (p2 != 1) oder berechnet aus der
 *   aktuellen Spielzeit plus einem Offset (p3 Ticks, p4 Tage, p5 Monate, p6 Jahre) einen zukünftigen
 *   Ziel-Zeitstempel (p2 == 1).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf die Zeitstempelstruktur, in p2 den
 *   Berechnungsmodus (1 für relativ zur aktuellen Zeit), in p3 die Ticks, in p4 die Tage, in p5 die Monate und
 *   in p6 die Jahre.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 * - Bekannte Originalfehler: Im relativen Modus (p2 == 1) enthält die Datumsüberlauf-Berechnung zwei
 *   Originalfehler:
 *   1. Verkehrte Subtraktion beim Tagesüberlauf (0x127028-0x127031): Überschreitet p1->b nach Addition von p4
 *     den Wert 30 (0x1e), rechnet der Code p1->b = 0x1e - p1->b (mov al, 0x1e; sub al, bl) statt p1->b = p1->b -
 *     0x1e. Da p1->b > 30 ist, ergibt dies stets einen negativen Tag (z. B. wird Tag 32 zu Tag -2 statt Tag 2
 *     des Folgemonats).
 *   2. Toter Korrekturzweig beim Monatsüberlauf (0x127062-0x127095): Überschreitet p1->c nach Addition von p5
 *     den Monat 12 (0x0c), setzt der Code p1->c = 1 (0x127062, statt p1->c -= 12) und zieht 5 Tage für die
 *     Namenlosen Tage ab (p1->b -= 5). Unmittelbar danach prüft er if (p1->b <= 0 && p1->c != 1)
 *     (0x127078-0x127083). Da p1->c wenige Befehle zuvor fest auf 1 gesetzt wurde, ist p1->c != 1 niemals wahr
 *     und der gesamte Korrekturblock p1->b += 30; p1->c--; (0x127085-0x127095) ist unerreichbarer toter Code.
 === Ende Beschreibung === */
void f_126f80(struct T *p1, short p2, int p3, signed char p4, signed char p5, signed char p6)
{
    if (p2 == 1) {
        p1->a = f_126410(&d_1c2c44);
        p1->b = f_126430(&d_1c2c44);
        p1->c = f_126450(&d_1c2c44);
        p1->d = f_126460(&d_1c2c44);
        p1->a += p3;
        if (p1->a > 0x1fa40) {
            p1->a = 0;
            p1->b++;
            if (p1->b > 0x1e) {
                p1->b = 1;
                p1->c++;
                if (p1->c > 0xc) p1->b = (signed char)0xfb;
            }
            else if (p1->b == 0) {
                p1->b = 1;
                p1->c = 1;
                p1->d++;
            }
        }
        p1->b += p4;
        if (p1->b > 0x1e) {
#if FIX_R072
            p1->b -= 0x1e;
#else
            p1->b = 0x1e - p1->b;
#endif
            p1->c++;
            if (p1->c > 0xc) {
                p1->b -= 5;
                p1->c = 1;
                p1->d++;
            }
        }
        p1->c += p5;
        if (p1->c > 0xc) {
#if FIX_R072
            p1->c -= 0xc;
#else
            p1->c = 1;
#endif
            p1->b -= 5;
            p1->d++;
            if (p1->b <= 0 && p1->c != 1) {
                p1->b += 0x1e;
                p1->c = p1->c - 1;
            }
        }
        p1->d += p6;
        return;
    }
    p1->a = p3;
    p1->b = p4;
    p1->c = p5;
    p1->d = p6;
}
//@ f_1270c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Berechnet die seit dem gespeicherten Zeitstempel p1 verstrichene Gesamtzeit in Ticks bis zum
 *   aktuellen Zeitpunkt (d_1c2c44) unter Berücksichtigung von Jahren (365 Tage), Monaten (30 Tage) und den fünf
 *   Namenlosen Tagen.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf die gespeicherte Zeitstempelstruktur.
 * - Rückgabewert: Die Funktion gibt die Differenz zwischen aktueller Spielzeit und p1 in Ticks zurück.
 === Ende Beschreibung === */
int f_1270c0(struct T *p1)
{
    int iv, sv;
    iv = f_126460(&d_1c2c44) * 0x16d;
    if (f_126430(&d_1c2c44) < 0) {
        if (f_126450(&d_1c2c44) == 0xd) {
            iv += f_126430(&d_1c2c44) + 0x16e;
        } else {
            iv += f_126430(&d_1c2c44);
        }
    } else {
        int m1 = (iv & 0) ? 0 : (f_126450(&d_1c2c44) - 1) * 0x1e + f_126430(&d_1c2c44); // haelt lea ebx,[eax-1] statt dec ebx
        iv += m1;
    }
    sv = p1->d * 0x16d;
    if (p1->b < 0) {
        if (p1->c == 0xd) {
            sv += p1->b + 0x16e;
        } else {
            sv += p1->b;
        }
    } else {
        int m = (iv & 0) ? 0 : (p1->c - 1) * 0x1e; // haelt Tail-Merging von sv += p1->b wie im Original
        sv += p1->b + m;
    }
    return (iv - sv) * 0x1fa40 + (f_126410(&d_1c2c44) - p1->a);
}
//@ f_1271f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Rechnet eine Zeitspanne in der Struktur p1 (Ticks, Tage, Monate, Jahre) in einen einzigen Gesamtwert
 *   in Ticks um.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf die Zeitstruktur.
 * - Rückgabewert: Die Funktion gibt die entsprechende Gesamtzahl an Ticks zurück.
 === Ende Beschreibung === */
int f_1271f0(struct T *p1)
{
    int v = p1->a;
    int b = p1->b;
    v += b * 0x1fa40;
    v += p1->c * 0x3b5380;
    v += p1->d * 0x2d1cd40;
    if (b < 0) v += 0x1fa40;
    return v;
}
//@ f_127280
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die 17 persistenten Zustandsvariablen der ersten Ebene des Magierturms (d_1c0c9c bis
 *   d_1c0cdc, Kennungen 0xb8 bis 0x24d) in der globalen Spielstands-Tabelle (d_1c212a).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
extern char d_1c0c9c, d_1c0ca0, d_1c0ca4, d_1c0ca8, d_1c0cac, d_1c0cb0, d_1c0cb4, d_1c0cb8, d_1c0cbc, d_1c0cc0, d_1c0cc4, d_1c0cc8, d_1c0ccc, d_1c0cd0, d_1c0cd4, d_1c0cd8, d_1c0cdc;
extern short d_1c0c9d, d_1c0ca1, d_1c0ca5, d_1c0ca9, d_1c0cad, d_1c0cb1, d_1c0cb5, d_1c0cb9, d_1c0cbd, d_1c0cc1, d_1c0cc5, d_1c0cc9, d_1c0ccd, d_1c0cd1, d_1c0cd5, d_1c0cd9, d_1c0cdd;
// Demo/Original: Parameter 0/0, Lokale und Slots 0/0; 14 Aufrufe -> 14 Inline-Eintraege, danach 3 neue.
inline void put127280(char &v, short &id, short k, short &n, char **&t)
{ v = 0; id = k; t[n] = &v; n++; }
inline void put127280r(char &v, short &id, short k, short &n, char **&t)
{ id = k; v = 0; t[n] = &v; n++; }
struct RR700V3_1272808;
struct OR700V3_1272808 { signed char flag; short number; char pad; OR700V3_1272808 *init(RR700V3_1272808 &r,short id,signed char f); };
struct RR700V3_1272808 { short count; OR700V3_1272808 **list; void append(OR700V3_1272808 *o) {list[count]=o;count++;} };
inline OR700V3_1272808 *OR700V3_1272808::init(RR700V3_1272808 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_1272808 regR700V3_1272808;
#pragma aux regR700V3_1272808 "d_1c212a"
extern OR700V3_1272808 obR700V3_127280_1c0c9c;
#pragma aux obR700V3_127280_1c0c9c "d_1c0c9c"
extern OR700V3_1272808 obR700V3_127280_1c0ca0;
#pragma aux obR700V3_127280_1c0ca0 "d_1c0ca0"
extern OR700V3_1272808 obR700V3_127280_1c0ca4;
#pragma aux obR700V3_127280_1c0ca4 "d_1c0ca4"
extern OR700V3_1272808 obR700V3_127280_1c0ca8;
#pragma aux obR700V3_127280_1c0ca8 "d_1c0ca8"
extern OR700V3_1272808 obR700V3_127280_1c0cac;
#pragma aux obR700V3_127280_1c0cac "d_1c0cac"
extern OR700V3_1272808 obR700V3_127280_1c0cb0;
#pragma aux obR700V3_127280_1c0cb0 "d_1c0cb0"
extern OR700V3_1272808 obR700V3_127280_1c0cb4;
#pragma aux obR700V3_127280_1c0cb4 "d_1c0cb4"
extern OR700V3_1272808 obR700V3_127280_1c0cb8;
#pragma aux obR700V3_127280_1c0cb8 "d_1c0cb8"
extern OR700V3_1272808 obR700V3_127280_1c0cbc;
#pragma aux obR700V3_127280_1c0cbc "d_1c0cbc"
extern OR700V3_1272808 obR700V3_127280_1c0cc0;
#pragma aux obR700V3_127280_1c0cc0 "d_1c0cc0"
extern OR700V3_1272808 obR700V3_127280_1c0cc4;
#pragma aux obR700V3_127280_1c0cc4 "d_1c0cc4"
extern OR700V3_1272808 obR700V3_127280_1c0cc8;
#pragma aux obR700V3_127280_1c0cc8 "d_1c0cc8"
extern OR700V3_1272808 obR700V3_127280_1c0ccc;
#pragma aux obR700V3_127280_1c0ccc "d_1c0ccc"
extern OR700V3_1272808 obR700V3_127280_1c0cd0;
#pragma aux obR700V3_127280_1c0cd0 "d_1c0cd0"
extern OR700V3_1272808 obR700V3_127280_1c0cd4;
#pragma aux obR700V3_127280_1c0cd4 "d_1c0cd4"
extern OR700V3_1272808 obR700V3_127280_1c0cd8;
#pragma aux obR700V3_127280_1c0cd8 "d_1c0cd8"
extern OR700V3_1272808 obR700V3_127280_1c0cdc;
#pragma aux obR700V3_127280_1c0cdc "d_1c0cdc"
void f_127280(void) {
obR700V3_127280_1c0c9c.init(regR700V3_1272808,0xb8,0);
obR700V3_127280_1c0ca0.init(regR700V3_1272808,0xb9,0);
obR700V3_127280_1c0ca4.init(regR700V3_1272808,0xba,0);
obR700V3_127280_1c0ca8.init(regR700V3_1272808,0xbb,0);
obR700V3_127280_1c0cac.init(regR700V3_1272808,0xbc,0);
obR700V3_127280_1c0cb0.init(regR700V3_1272808,0xbd,0);
obR700V3_127280_1c0cb4.init(regR700V3_1272808,0xbe,0);
obR700V3_127280_1c0cb8.init(regR700V3_1272808,0xbf,0);
obR700V3_127280_1c0cbc.init(regR700V3_1272808,0xc0,0);
obR700V3_127280_1c0cc0.init(regR700V3_1272808,0xc1,0);
obR700V3_127280_1c0cc4.init(regR700V3_1272808,0xc2,0);
obR700V3_127280_1c0cc8.init(regR700V3_1272808,0xc3,0);
obR700V3_127280_1c0ccc.init(regR700V3_1272808,0x1fe,0);
obR700V3_127280_1c0cd0.init(regR700V3_1272808,0x229,0);
obR700V3_127280_1c0cd4.init(regR700V3_1272808,0x243,0);
obR700V3_127280_1c0cd8.init(regR700V3_1272808,0x247,0);
obR700V3_127280_1c0cdc.init(regR700V3_1272808,0x24d,0);
}

//@ f_127590
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor des Dungeon-Objekts für die erste Ebene des Magierturms (tower0, Dungeon-ID 0x12), der
 *   die Basisklasse (f_05ff60) initialisiert, die virtuelle Methodentabelle (d_1bbb0c) einträgt und den internen
 *   Zähler an Offset +0x0c auf 0 setzt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_127590(int p1)
{
    int r = f_05ff60(p1, 0x12);
    *(int *)(r + 8) = (int)&d_1bbb0c;
    *(short *)(r + 0xc) = 0;
}
