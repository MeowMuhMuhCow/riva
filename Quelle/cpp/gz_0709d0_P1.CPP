/* === Beschreibung (Katalog) ===
 * Einheit gz_0709d0 (0709d0 - 070c50)
 *
 * Überblick
 * Diese Einheit enthält die zentrale Aufbauroutine für zufällig zusammengestellte oder dynamisch erzeugte
 * Kampffelder (Kampfnummern ab 0xa6 = 166, z. B. Zufallsbegegnungen oder besondere Skriptkämpfe), bei denen die
 * Startpositionen der Helden und Gegner anhand einer Vorlagentabelle ausgewürfelt werden.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include <string.h>
struct E5 { char a; char cnt; signed char b; char c; };
struct T { char c0; char pad[2]; E5 e[5]; short s[20]; short x, y, z; };
struct R { char a; char b; char c; char d; char e; char pad[10]; };
extern T d_1a2218[];
extern int d_1c0004;
extern char (*d_1bd984)[25];
int f_038c80(int a);
int f_0391b0(int a, int b);


int f_070c50(char *p, char *a, char *b, char *c);
int f_070e50(char *p, int a, char *b, char *c, char *d, int f);
int f_0711c0(char *p);
int f_072850(int a);
#define F(T,o) (*(T*)(p1 + (o)))
#define LT(v,n) ((v) < (short)(n))
#define RC(i) (*(R*)(p1 + 0xee9 + (i) * 15))
//@ f_0709d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut ein dynamisches Kampfszenario anhand des Vorlageneintrags d_1a2218[kampf_nr - 0xa6] auf.
 *   Die Funktion würfelt über f_070c50 für alle anwesenden Gruppenmitglieder freie Startfelder auf dem 24 x
 *   24-Kampfraster aus (Begleiter/NSCs kommen auf den siebten Slot), platziert anschließend über f_070e50 bis zu
 *   fünf Gegnergruppen (inklusive Prüfung auf zweifeldrige Großgegner über f_072850), richtet die
 *   Blickrichtungen der Helden über f_0711c0 zum jeweils nächsten Gegner aus, bereinigt die temporären
 *   Platzierungsmarkierungen (0xc9 und 0xca) im Kampfraster d_1bd984 und übernimmt die Flucht- und
 *   Kameraparameter der Vorlage.
 * - Eingaben und Rückgabe: Empfängt den Zeiger p1 auf die Hauptkampfstruktur (+0x1ea: Kampfnummer,
 *   +0xee6..+0x1071: Kampffeld- und Aufstellungsdaten) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1a2218 hält die Vorlagen für dynamische Kämpfe ab Index 0xa6, p1 + 0x1015
 *   speichert die bis zu 7 Startplätze der Heldengruppe (je 4 Byte: X, Y, Blickrichtung, Fernkampf-Flag), p1 +
 *   0xee9 enthält die bis zu 20 Gegner-Starteinträge (je 15 Byte) und d_1bd984 (24 x 25 Bytes) ist das globale
 *   Kampfraster.
 === Ende Beschreibung === */
void f_0709d0(char *p1)
{
    short out;
    short i;
    short n = 0;
    int cur;
    T t;

    t = d_1a2218[F(short, 0x1ea) - 0xa6];
    F(char, 0xee6) = t.c0;
    { char tp0_ = t.pad[0]; char tp1_ = t.pad[1]; char tpx_ = (char)t.x; } // Lokale Struktur-Aliase fuer die Slot- und Registerfolge
    memset(p1 + 0x1015, 0, 0x1c);
    for (i = 0; i < 7; i++)
        p1[0x1015 + i * 4] = (char)0xff;

    cur = f_038c80(d_1c0004);
    do {
        char *pp = p1 + 0x1015 + (((char)(f_042400((struct hero *)(cur)))) ? (short)6 : n) * 4;
        f_070c50(p1, pp, pp + 1, pp + 2);
        if (((char)(f_0424d0((struct hero *)(cur)))))
            p1[0x1018 + n * 4] = 1;
        cur = f_0391b0(d_1c0004, cur);
        n++;
    } while (cur != f_038c80(d_1c0004) && f_038c80(d_1c0004));

    out = 0;
    memset(p1 + 0xee9, 0, 0x12c);
    for (n = 0; LT(n, 5); n++) {
        if (t.e[n].cnt != (char)0) {
            for (i = 0; i < (signed char)t.e[n].cnt; i++) {
                RC(out).a = t.e[n].a;
                RC(out).e = t.e[n].c;
                f_070e50(p1, t.e[n].b,
                         p1 + 0xee9 + out * 15 + 1,
                         p1 + 0xee9 + out * 15 + 2,
                         p1 + 0xee9 + out * 15 + 3,
                         f_072850((unsigned char)RC(out).a) != 1);
                out++;
            }
        }
    }

    f_0711c0(p1);
    struct MapRow {
        static char *at(char (*map)[25], short row) { return map[row]; }
    };
    for (n = 0; LT(n, 0x18); n++) {
        for (i = 0; LT(i, 0x19); i++) {
            if (MapRow::at(d_1bd984, n)[i] == (char)0xc9 ||
                MapRow::at(d_1bd984, n)[i] == (char)0xca)
                d_1bd984[n][i] = 0;
        }
    }

    memset(p1 + 0x1031, 0, 0x1e);
    for (n = 0; LT(n, 0x14); n++)
        F(short, 0x1031 + n * 2) = t.s[n];
    F(short, 0x106d) = t.x;
    F(short, 0x106f) = t.y;
    F(short, 0x1071) = t.z;
}
