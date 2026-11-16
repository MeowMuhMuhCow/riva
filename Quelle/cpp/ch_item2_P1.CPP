/* === Beschreibung (Katalog) ===
 * Einheit ch_item2 (0x033d40 - 0x0350b0)
 *
 * Überblick
 * Diese Einheit umfasst die Gegenstands-Untersuchungsfunktion ("Auge"-Symbol im Inventar, in *Schicksalsklinge*
 * und *Sternenschweif* vergleichbar mit den Item-Info-Dialogen), die Berechnung von Rüstungs- und
 * Waffen-Abnutzungsstufen, das Verzaubern/Entfluchen von Waffen im Inventar sowie die Erstausstattung und
 * automatische Vor-Steigerung neu generierter Helden beim Spielstart (f_034ad0, f_034e20).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 4/7 gleich (suche.py 29.10.2026, Basis ch_item2_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 729 (vorher 732)
// ch_item2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x033D40-0x0350B0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e0c0();
int f_032ab0(int p1, int p2, int p3);
int f_0366e0(int p1, int p2, int p3, int p4);
int f_038880(int p1, int p2, int p3);
short f_03d860(int p1, int p2, int p3);
int f_040780(int p1, int p2);
















unsigned short f_043be0(int p1);
int f_045960(int p1, int p2);
int f_046bc0(int p1);
int f_057750(int p1);
int f_057760(int p1);
int f_09a0d0(int p1);
int f_09a140(int p1, int p2);







int f_0bf730(int p1, int p2);
short f_0d4aa0(int p1, int p2);
short f_0de1c0(int p1, int p2, int p3);
int f_0e9300(int p1, int p2, int p3);
int f_0e93f0(int p1, int p2, int p3);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int);
int f_133fe0(int p1, int p2);
int f_145920(int p1, int p2, int p3, void *p4, void *p5);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1bc760;                    // 0x1BC760
extern int d_1c0004;                    // 0x1C0004
extern volatile short d_1c2198;         // 0x1C2198 (volatile: kein Kandidat fuer globale Registerhaltung)
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a082c[];           // Text 0x1A082C

extern short d_1a084c[];
extern signed char d_1a441c[];
extern signed char d_1a47ac[];

extern unsigned short d_1c20b2;
extern short d_1bfaec;
struct W5 { short v[5]; };
struct W48 { short v[12][4]; };
extern W5 d_1a0880;
extern W48 d_1a088a;
extern W5 d_1a08ea;
extern W48 d_1a08f4;
struct E8 { short id; short pad; int code; };
extern E8 d_1a7884[];
struct Lock { Lock(); ~Lock(); int x; };
struct Obj { Obj(); ~Obj(); char pad[0x128]; };
unsigned short f_034920(int p1, short p2);
short f_0bf820(...);
#define A(x) ((int)&(x))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define SB(p,o) (*(signed char*)((p)+(o)))
#define SH(p,o) (*(short*)((p)+(o)))
struct Msg { int h; char *q[14]; };
struct MsgC { int h; char *q[14]; MsgC(void *a, void *b, void *c); ~MsgC(); };   // Ctor f_125400, Dtor f_1254a0
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define QV(m,k) (*(int*)((m).q[k]+4))
#define Q2(m,k) (*(short*)((m).q[k]+2))
#define Q4(m,k) (*(short*)((m).q[k]+4))
#define TX(c) f_0e9300(A(d_1c38b0), A(d_1c21b4), c)
#define NL 0x2000016f

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_033d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft nach dem Untersuchen eines Gegenstands (p1), ob dieser in der
 *   Tabelle d_1a084c einen besonderen Zusatztext besitzt, und zeigt gegebenenfalls das zugehörige Textfenster
 *   (0x5010021 + s) an.
 * - Eingaben und Rückgabe: Die Funktion erhält die Gegenstands-ID p1 (short) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die mit -1 terminierte Tabelle d_1a084c enthält die Gegenstands-IDs, für die beim
 *   Betrachten ein zusätzlicher Beschreibungstext ausgegeben wird.
 === Ende Beschreibung === */
void f_033d40(short p1)
{
    short s;
    s = 0;
    while (1) {
        if (p1 == d_1a084c[s] || d_1a084c[s] == -1) break;
        s = s + 1;
    }
    if (p1 == d_1a084c[s]) f_0bf730(A(d_1c2c64), (short)(s & 0xffff) + 0x5010021); // Haelt das Schleifenregister bis zum Aufruf
}

inline short lvl(int p1, short p2)
{
    short a = f_042a60((struct hero *)(p1), p2);
    short b = f_042be0((struct hero *)(p1), p2);
    signed char c = ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[a]))->f_0a78a0()));
    short ts = d_1a441c[c * 10 + 3];
    short hh = (0xf - d_1a441c[c * 10 + 3]) / 2;
    if (b <= d_1a441c[c * 10 + 3] + 1) return 1;
    {
        int h = hh;
        if (b <= ts + h) return 2;
    }
    return 3;
}

//@ f_033db0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese umfangreiche Funktion baut den vollständigen Untersuchungstext ("Auge"-Icon im Inventar)
 *   für den Gegenstand im Slot p2 des Helden p1 auf und zeigt ihn in einem Dialogfenster an. Sie gibt Name und
 *   Stückzahl aus, ergänzt bei einem Trinkschlauch (Slot 14) den Füllstand, zeigt bei Waffen das zugehörige
 *   Kampftalent, den Trefferschaden (xW6+y) und den Attacke-/Parade-Modifikator (d_1a441c), bei Rüstungen den
 *   Rüstungsschutz und die Behinderung (d_1a47ac), bei Zauber-/Rezeptbüchern die Anzahl enthaltener Einträge,
 *   den Zustand (zerbrochen, abgenutzt, verflucht, vergiftet, magisch mit Detailtext aus d_1a7884) sowie
 *   abschließend das Gesamtgewicht in Unzen an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den untersuchten Inventarslot p2 (short)
 *   und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Waffentabelle d_1a441c (10 Bytes pro Waffe) und die Rüstungstabelle d_1a47ac (2
 *   Bytes pro Rüstung) liefern die Kampfwerte; die Tabelle d_1a7884 ordnet identifizierten magischen
 *   Gegenständen ihren spezifischen Wissenstext (Analüs-Ergebnis) zu.
 === Ende Beschreibung === */
void f_033db0(int p1, short p2)
{
    int nl = 1;
    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
    QV(m, 0) = p1;
    short item = f_042a60((struct hero *)(p1), p2);
    int msg;
    short i;
    short j;
    if (item) {
        QV(m, 2) = (*(int **)&d_1c2c40)[item];
        Q2(m, 7) = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7950() ? f_042ac0((struct hero *)(p1), p2) : 1;
        if (*(unsigned short *)(m.q[7] + 2) > 1 || ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7ad0())
            msg = 0x5010003;
        else
            msg = 0x5010004;
        f_0e93f0(A(d_1c38b0), A(d_1c21b4), msg);
        if (p2 == 14) {
            switch ((unsigned short)((short (*)(char *, short))f_043be0)((char *)p1, p2)) { // Aufrufvertrag short(char*, short)
            case 0:
                TX(NL);
                TX(0x5010020);
                break;
            case 1:
            case 2:
            case 3:
                TX(NL);
                TX(0x5010005);
                break;
            case 4:
            case 5:
            case 6:
                TX(NL);
                TX(0x5010006);
                break;
            case 7:
            case 8:
            case 9:
                TX(NL);
                TX(0x5010007);
                break;
            }
        }
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7990() && (!((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7950() || ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a78b0())) == 8)) {
            TX(NL);
            TX(NL);
            QV(m, 3) = ((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a78b0())) + 0x2000005c;
            TX(0x501000a);
            TX(NL);
            signed char *w = &d_1a441c[((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a78a0())) * 10];
            int v1; short v2;
            f_145920(w[0], 6, w[1], &v1, &v2);
            Q2(m, 4) = v1;
            Q4(m, 4) = v2;
            TX(0x501000b);
            TX(NL);
            Q2(m, 4) = w[5];
            Q4(m, 4) = w[6];
            TX(0x501000c);
            TX(NL);
            nl = 0;
        } else if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a79b0()) {
            TX(NL);
            TX(NL);
            signed char *a = &d_1a47ac[((signed char)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a78a0())) * 2];
            int d1 = a[1] / 2;
            short d2 = d1;
            if (a[1] & 1) d1++;
            d2 = -d2;
            d1 = -d1;
            Q2(m, 4) = a[0];
            Q4(m, 4) = a[1];
            TX(0x501000d);
            TX(NL);
            Q2(m, 4) = d2;
            Q4(m, 4) = d1;
            TX(0x501000c);
            TX(NL);
            nl = 0;
        }
        if (item == 0x145 || item == 0x19d || item == 0x19e || item == 0x19f ||
            item == 0x1a0 || item == 0x1a1 || item == 0x1cf || item == 0x1d0) {
            short cnt = 0;
            for (i = 0; i < (short)7; i++) {
                if (f_03d860(p1, p2, i)) cnt++;
            }
            if (cnt) {
                Q2(m, 4) = cnt;
                TX(0x5010001);
            }
        }
        if (item == 0xbf) {
            short cnt2 = 0;
            for (j = 0; j < 17; j++) {
                if (f_03d860(p1, p2, j)) cnt2++;
            }
            if (cnt2) {
                Q2(m, 4) = cnt2;
                TX(0x5010002);
            }
        }
        if (f_042bb0((struct hero *)(p1), p2)) {
            TX(NL);
            TX(0x501000e);
            nl = 1;
        } else if (f_042b50((struct hero *)(p1), p2)) {
            if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a79b0() && item != 0x32 && item != 0x33 && item != 0x138) {
                TX(NL);
                TX(0x5010010);
                nl = 1;
            }
        } else {
            int *t1 = (*(int **)&d_1c2c40);
            if (((RivaItemDefinition*)(t1[item]))->f_0a7990()) {
                short l = lvl(p1, p2);
                if (l > 1) {
                    TX(NL);
                    if (l == 2)
                        TX(0x5010014);
                    else
                        TX(0x5010015);
                    nl = 1;
                }
            }
        }
        if (!f_045960(p1, item)) {
            TX(NL);
            TX(0x5010008);
            nl = 1;
        }
        if (item == 0xc1 || item == 0xc8 || f_042fd0((struct hero *)(p1), p2)) {
            int amount = f_042ac0((struct hero *)(p1), p2);
            nl = (nl & 0) ? 0 : nl; // Haelt nl im selben Stapel-/Registerweb ueber den Giftzweig
            if (amount > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7950()) {
                TX(NL);
                Q2(m, 4) = ((signed char)(f_043030((struct hero *)(p1), p2)));
                TX(0x501001c);
            } else {
                TX(NL);
                TX(0x5010011);
            }
            nl = 1;
        }
        if (item == 0x85) {
            TX(NL);
            Q2(m, 4) = SB(p1, 0x1a7);
            TX(0x5010012);
            nl = 1;
        }
        if (item == 0x102) {
            TX(NL);
            TX(0x501001a);
            nl = 1;
        } else if (item == 0x155) {
            TX(NL);
            TX(0x501001d);
            if (f_0de1c0(d_1c0004, 0x28, 4) > 0)
                TX(0x501001e);
            else
                TX(0x501001f);
            nl = 1;
        }
        if (f_042d30((struct hero *)(p1), p2)) {
            TX(NL);
            TX(0x5010016);
            nl = 1;
        } else if (f_042da0((struct hero *)(p1), p2)) {
            TX(NL);
            TX(0x5010017);
            nl = 1;
        } else if (item == 0x1e || item == 0xb9) {
            TX(NL);
            TX(0x501001b);
            nl = 1;
        }
        if (f_042e10((struct hero *)(p1), p2) && f_042ef0((struct hero *)(p1), p2)) {
            int found = 0;
            if (f_042e80((struct hero *)(p1), p2)) {
                short k = 0;
                while (d_1a7884[k].id != -1) {
                    if (item == d_1a7884[k].id) {
                        found = 1;
                        TX(NL);
                        TX(NL);
                        TX(d_1a7884[k].code);
                        break;
                    }
                    k++;
                }
            }
            if (!found) {
                TX(NL);
                TX(0x501000f);
            }
            nl = 1;
        }
        TX(NL);
        if (nl)
            TX(NL);
        if (f_042ac0((struct hero *)(p1), p2) > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7950()) {
            short wg = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7810() * f_042ac0((struct hero *)(p1), p2);
            Q2(m, 4) = wg;
            QV(m, 3) = (wg == 1) ? 0x20000194 : 0x200001ba;
            TX(0x5010009);
        } else {
            short wg2 = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item]))->f_0a7810();
            Q2(m, 4) = wg2;
            QV(m, 3) = (wg2 == 1) ? 0x20000194 : 0x200001ba;
            TX(0x5010009);
        }
        msg = f_133fe0(A(d_1c3498), A(d_1c21b4));
    } else {
        msg = 0x5010018;
    }
    f_0bf730(A(d_1c2c64), msg);
    f_033d40(item);
}

//@ f_0348d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion erhöht oder senkt den Rüstungs-Abnutzungszähler eines Rüstungsteils im
 *   Körperslot p2 des Helden p1 um den Differenzwert p3 (positiv bei Rüstungsschaden im Kampf, negativ bei einer
 *   Reparatur).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, den Körperslot p2 (short) und die
 *   Abnutzungsänderung p3 (signed char) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Feld SB(p1 + p2 * 0x1b, 0x1af) speichert die Abnutzung des Rüstungsteils im
 *   jeweiligen Slot, während SB(p1, 0x42) den aktuellen Gesamtrüstungsschutz des Helden hält (siehe auch den
 *   dokumentierten Originalfehler in der Fehlerliste, da SB(p1, 0x42) nur bei p2 == 10 sofort angepasst wird).
 === Ende Beschreibung === */
void f_0348d0(int p1, short p2, signed char p3)
{
    int i2;
    signed char c1;
    if (p2 == 10) {
        if (SB(p1, 0x42) < p3) p3 = SB(p1, 0x42);
        SB(p1, 0x42) = SB(p1, 0x42) - p3;
    }
    i2 = p1 + p2 * 0x1b;
    c1 = SB(i2, 0x1af) + p3;
    SB(i2, 0x1af) = c1;
    if (c1 < 0) SB(i2, 0x1af) = 0;
}

//@ f_034920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion berechnet die dreistufige Abnutzungs- bzw. Bruchgefahr-Kennzahl (1 =
 *   unbeschädigt/gut, 2 = angeschlagen, 3 = stark beschädigt) einer Waffe im Inventarslot p2 anhand ihres
 *   aktuellen Bruchfaktors im Verhältnis zum Grund-Bruchfaktor aus d_1a441c.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Slot-Index p2 (short) und gibt die
 *   Zustandsstufe 1, 2 oder 3 als unsigned short zurück.
 * - Wichtige Variablen: Verglichen wird der aktuelle Waffen-Bruchfaktor f_042be0(p1, p2) mit dem
 *   Grund-Bruchfaktor d_1a441c[c * 10 + 3].
 === Ende Beschreibung === */
unsigned short f_034920(int p1, short p2)
{
    short a = f_042a60((struct hero *)(p1), p2);
    short b = f_042be0((struct hero *)(p1), p2);
    signed char c = (signed char)d_1c2c40[a]->f_0a78a0();
    short ts = d_1a441c[c * 10 + 3];
    short hh = (0xf - d_1a441c[c * 10 + 3]) / 2;
    if (b <= d_1a441c[c * 10 + 3] + 1) return 1;
    if (b <= hh + ts) return 2;
    return 3;
}

//@ f_0349b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion sucht im gesamten Inventar (Slots 0..30) eines Helden p1 nach der ersten
 *   passenden Waffe und verzaubert sie entweder dauerhaft/magisch (p3 == 0: setzt die Flags 0x88 in +0x1ac bei
 *   einer noch nicht verfluchten und noch nicht magischen Waffe) oder hebt einen bestehenden Fluch auf ihr auf
 *   (p3 != 0: löscht das Fluch-Bit 0x01 in +0x1ac). Wurde eine Waffe gefunden und verändert, formatiert die
 *   Funktion die Erfolgsmeldung p2 in den Textpuffer d_1c21b4.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1, die Text-ID p2 und den Modus p3 (0 = Waffe
 *   verzaubern, != 0 = Fluch von Waffe nehmen) und gibt 1 bei Erfolg oder 0 zurück, falls keine geeignete Waffe
 *   im Inventar lag.
 * - Wichtige Variablen: Das Flag-Byte *(signed char *)(p1 + i * 0x1b + 0x1ac) kennzeichnet mit Bit 0x01
 *   verfluchte, mit Bit 0x08 magische und mit Bit 0x80 analysierte Gegenstände.
 === Ende Beschreibung === */
#pragma aux f_0a7990 parm [eax] modify exact [eax]
int f_0349b0(int p1, int p2, short p3)
{
    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
    short i;
    short item;
    short result;
    QV(m, 0) = p1;
    result = 0;
    for (i = 0; i < 31; i++) {
        item = *(short*)(p1 + i * 0x1b + 0x1a8);
        if (item == 0) continue;
        if (!d_1c2c40[item]->f_0a7990()) continue;
        if (!p3) {
            if (*(signed char*)(p1 + i * 0x1b + 0x1ac) & 1) continue;
            if (*(signed char*)(p1 + i * 0x1b + 0x1ac) & 8) continue;
            *(signed char*)(p1 + i * 0x1b + 0x1ac) |= 0x88;
            QV(m, 2) = (int)d_1c2c40[item];
            Q2(m, 7) = 1;
            result = 1;
        } else {
            if (!(*(signed char*)(p1 + i * 0x1b + 0x1ac) & 1)) continue;
            *(signed char*)(p1 + i * 0x1b + 0x1ac) &= ~1;
            QV(m, 2) = (int)d_1c2c40[item];
            Q2(m, 7) = 1;
            result = 1;
        }
        break;
    }
    if (result == 1)
        f_0e93f0(A(d_1c38b0), A(d_1c21b4), p2);
    return result;
}

//@ f_034ad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion stattet einen neu erstellten Helden p1 mit der Grundausrüstung aus den Tabellen
 *   d_1a0880 (allgemeines Reisegepäck) und d_1a088a (klassenspezifische Waffen und Rüstung) aus, legt die
 *   Gegenstände an die passenden Körperslots (f_032ab0) und hebt den Helden anschließend durch wiederholte
 *   Vergabe von Abenteuerpunkten (f_040780) und Aufrufe des Stufenaufstiegs (f_038880) auf die für *Schatten
 *   über Riva* vorgesehene Startstufe 6 an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Steigerungsmodus p2 (1 = Spieler
 *   steigert die Stufen selbst, 2 = Computer steigert automatisch im Hintergrund) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Schleife läuft, solange die Erfahrungsstufe f_0428d0(p1) kleiner als 6 ist, und
 *   berechnet die jeweils bis zur nächsten Stufe md fehlenden Abenteuerpunkte aus der Stufenschwellentabelle
 *   f_046bc0(md).
 === Ende Beschreibung === */
int f_0ce7c0(void *p1);

int f_04a890(int p1);

int f_04ad40(int p1, int p2);

int f_0ce7e0(void *p1, int p2);

void f_034ad0(int p1, short p2)
{
    short s;
    short v = 0x12;
    W5 a = d_1a0880;
    W48 t = d_1a088a;
    signed char c;
    int iv;
    int x;
    int sv;
    short o;
    int memory;
    short md;

    c = f_042350((struct hero *)(p1));
    int rt950_0; int rt950_1; short rt950_2; // Haelt globale Konfliktgewichte fuer die Registerzuteilung
    for (s = 0; s < 5; s = s + 1)
        f_0366e0(p1, a.v[s], 1, 1);
    f_032ab0(p1, 5, v);
    f_0366e0(p1, 0x32, 1, 1);
    f_032ab0(p1, 0xe, v);
    if (((char)(f_042380((struct hero *)(p1)))) && (c == 1 || c == 2 || c == 7 || c == 8)) {
        f_0366e0(p1, 0x30, 1, 1);
        f_032ab0(p1, 0xa, v);
    }
    s = 0;
    for (; (x = *(short *)((char *)t.v[c - 1] + s * 2)) != -1 && s < 4; ) {
        s = s + 1;
        f_0366e0(p1, x, 1, 1);
        if (s == 1) f_032ab0(p1, 3, v);
    }
    if (c == 5 || c == 6 || c == 4 || c == 10 || c == 12 || c == 11)
        f_032ab0(p1, 0xa, f_0d4aa0(p1, 0x35));
    if (c == 3)
        f_032ab0(p1, 0xa, f_0d4aa0(p1, 0x50));
    if (c == 9)
        f_032ab0(p1, 0xa, f_0d4aa0(p1, 0x4c));
    if (c == 2 || c == 10 || c == 12) {
        f_0366e0(p1, 10, 1, 0x28);
        f_032ab0(p1, 0xc, f_0d4aa0(p1, 10));
    }
    if (p2 != 1) f_09a140(0, 0x19);
    if (p2 == 2 && d_1bc760) f_01e0c0();
    sv = d_1c2a80;
    f_0ce7c0(&o);
    memory = (int)operator new(0x128, mark(d_1a082c, 0x29c));
    memory = memory ? f_04a890(memory) : memory;
    while ((signed char)f_0428d0((struct hero *)(p1)) < 6) {
        md = (signed char)f_0428d0((struct hero *)(p1)) + 1; iv = f_046bc0(md) - ((int)(f_0428f0((struct hero *)(p1))));
        unsigned short *gq = &d_1c20b2; iv = iv / *gq; // Erzwingt Zeiger-Dereferenzierung fuer die Divisionsform
        iv = iv + 1;
        signed char z = d_1bfaec;
        if (z == 0) iv = iv / 2;
        f_040780(p1, (short)iv);
        md = (short)(p2 != 2) + 1;
        f_038880(memory, p1, md);
    }
    if (memory) operator delete((void *)f_04ad40(memory, 0));
    f_0ce7e0(&o, 0);
    if (p2 == 1) {
        d_1c2a80 = sv;
        d_1c2198 = 0;
    }
    if (p2 == 2) {
        f_09a140(0, 0x19);
        f_09a0d0(d_1a34e0);
        d_1c2198 = 1;
    }
    rt950_0 = d_1a34e0; d_1a34e0 = rt950_0; // Haelt globale Konfliktgewichte fuer die Registerzuteilung
    rt950_1 = d_1bc760; d_1bc760 = rt950_1;
    rt950_2 = d_1bfaec; d_1bfaec = rt950_2;
}


//@ f_034e20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion wird beim erstmaligen Indienststellen eines neu generierten Helden (B(p1, 0x8e)
 *   == 0) aufgerufen und fragt den Spieler in einem Auswahlfenster (0x0e14004a), ob der Held auf Stufe 6
 *   vor-gesteigert werden soll (manuell code == 1 oder automatisch code == 2 über f_034ad0) oder ob er als
 *   Stufe-1-Held mit einfacherer Startausrüstung (code == 3, Tabellen d_1a08ea und d_1a08f4) beginnen soll.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 nach erfolgter Ausstattung (oder
 *   wenn der Held bereits ausgestattet war) bzw. 0 bei Abbruch des Auswahldialogs zurück.
 * - Wichtige Variablen: Das Byte B(p1, 0x8e) markiert, dass der Held seine Startausrüstung bereits erhalten hat;
 *   die Tabellen d_1a08ea und d_1a08f4 enthalten die leichtere Startausrüstung für Stufe-1-Charaktere.
 === Ende Beschreibung === */
int f_034e20(int p1)
{
    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
    short s;
    short v = 0x12;
    W5 a = d_1a08ea;
    W48 t = d_1a08f4;
    signed char c;
    int iv;
    if ((signed char)B(p1, 0x8e) == 0) {
        f_057760(A(d_1c2c00));
        c = f_042350((struct hero *)(p1));
        B(p1, 0x8e) = 1;
        QV(m, 0) = p1;
        short code = f_0bf820(A(d_1c2c64), 0x0e14004a, 3, 0x0e14004d, 0x0e14004c, 0x0e14004b);
        if (code == -1) return 0;
        if (code == 3) {
            for (s = 0; s < 5; s = s + 1) f_0366e0(p1, a.v[s], 1, 1);
            iv = (short)v;
            f_032ab0(p1, 5, iv);
            f_0366e0(p1, 0x32, 1, 1);
            f_032ab0(p1, 0xe, iv);
            if (((char)(f_042380((struct hero *)(p1)))) && c != 3 && c != 9) {
                f_0366e0(p1, 0x30, 1, 1);
                f_032ab0(p1, 10, iv);
            }
            s = 0;
            for (; (iv = t.v[c - 1][s]) != -1 && s < 4; ) {
                s = s + 1;
                f_0366e0(p1, iv, 1, 1);
                if (s == 1) f_032ab0(p1, 3, (short)v);
            }
            if (c == 3) {
                s = f_0d4aa0(p1, 0x35);
                f_032ab0(p1, 10, s);
            }
            if (c == 9) {
                s = f_0d4aa0(p1, 0x4b);
                f_032ab0(p1, 10, s);
            }
            if (c == 2 || c == 10 || c == 12) {
                f_0366e0(p1, 10, 1, 0x14);
                s = f_0d4aa0(p1, 10);
                f_032ab0(p1, 0xc, s);
            }
        } else {
            f_034ad0(p1, code);
        }
        f_057750(A(d_1c2c00));
    }
    return 1;
}
