/* === Beschreibung (Katalog) ===
 * Einheit tower4_t1 (0x131F30 - 0x1332C0)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil von tower4.cpp und steuert die Ereignisse auf der vierten und obersten
 * Ebene des Magierturms (Eboreus' bzw. Tariks Domizil). Dazu gehören der zentrale Ereignis-Verteiler, die drei
 * identisch aufgebauten magischen Kammern bzw. Zellen samt ihren Teleporter- und Kampffallen, die Begegnung mit
 * dem Magier und seinen Kreaturen, ein Heilbrunnen bzw. Heilungsereignis für verletzte Helden, Beutelager sowie
 * die Prüfung auf den achtkantigen Schlüssel ("Achtkantinbus", Gegenstand 0x199).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 28/30 gleich (suche.py 25.10.2026, Basis tower4_t1_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 19 gleich (vorher 19), Rest 1273 (vorher 1304)
// tower4.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x131F30-0x133DE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_02de00(int p1, int p2);                           // reg eax edx stapel 0
int f_02de20(int p1, int p2);                           // reg eax edx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039a10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_044890(int p1, int p2, int p3, int p4);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
int f_046d90(int p1, int p2);                           // reg eax stapel 0
int f_046de0(int p1);                                   // reg eax stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f470(int p1);                                   // reg eax stapel 0
int f_05f4f0(int p1, int p2);                           // reg eax stapel 0
int f_05f560(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0609d0(int p1, int p2);                           // reg eax edx stapel 0
unsigned short f_069770(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bfea0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_0d13b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d1430();                                         // reg - stapel 0
int f_0d1440(int p1);                                   // reg eax stapel 0
int f_0d1b20(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd4a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd640(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd6d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de070(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de820(int p1);                                   // reg eax stapel 0
int f_0de8c0(int p1);                                   // reg eax stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1454d0(int p1);                                   // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_155934();                                         // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a8d58;                  // 0x1A8D58
extern unsigned short d_1a8d5a;         // 0x1A8D5A
extern short d_1a8d5c;                  // 0x1A8D5C
extern short d_1a8d5e;                  // 0x1A8D5E
extern short d_1a8d60;                  // 0x1A8D60
extern short d_1a8d62;                  // 0x1A8D62
extern const char d_1a8d38[];           // Text 0x1A8D38
// --- eigene Funktionen (41), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

short f_0d4aa0(int p1, int p2);
short f_1457e0(int p1);

int f_0bf980();
int f_0bfa20();
int f_060a70();
int f_0104b0(int p1, int p2, int p3, int p4);
int f_010590(int p1, int);

extern int d_1c0004; extern char *d_1a8d64, *d_1a8d88, *d_1a8dac;
extern char d_1c0da4, d_1c0da8, d_1c0dd0, d_1c0dac; extern short d_1bd6c4, d_1bd91c;
extern signed char d_1c0da0;
extern signed char d_1c0d9c;
extern signed char d_1c0db4;
extern char d_1c2c64[], d_1c349c[], d_1c3870[], d_1c3498[];
typedef short (*SF2)(int, int); typedef short (*SF3)(int, int, int);
void f_1328d0(); void f_132900(int); void f_1329c0(int); void f_132a90(int); void f_132c00(int); void f_132d70(int); void f_132ec0(); void f_132ef0(); void f_132f40(int); void f_1330b0_(); int f_1330b0(int); void f_1330c0(); void f_133190(); void f_1331b0(); void f_133230(); void f_133250(); void f_133270(); void f_1332c0(); void f_133410(int, int); void f_133650(int, int); void f_1337c0(int, int); void f_133890(int, int); void f_133b30(int);
typedef void (*VF3)(int, int, int);
#define U ((unsigned short)p2)
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_131f30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fungiert als zentraler Ereignis-Verteiler der vierten Turmebene und verzweigt anhand der
 *   übergebenen Ereignis- oder Objektkennung (p2) zu den Reaktionen für die Treppe nach unten (0x65), Kampf- und
 *   Dialogsequenzen (0xc9, 0xcd, 0x25b), die drei Zellen- und Teleporterbereiche (0x12e-0x130, 0x192-0x194,
 *   0x1f6-0x1f8), den Sturz in ein tieferes Stockwerk (0x25a), die Heilung eines verwundeten Helden (0x25c),
 *   Raumbeschreibungen und Beutelager (0x25d-0x261) sowie die mit dem "Achtkantinbus" oder Passwörtern
 *   gesicherten Türen (0x1f41-0x1f47).
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1) sowie die 16-Bit-Ereignis- oder Objektkennung (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn die Kennung verarbeitet wurde, andernfalls 0.
 * - Wichtige Variablen: Die lokalen Textkontext-Strukturen (frame.first, frame.second) ermöglichen das Einsetzen
 *   von Heldennamen in Dialogtexte; zahlreiche globale Statusflags (d_1c0d9c, d_1c0da0, d_1c0da4, d_1c0da8,
 *   d_1c0db4, d_1c0dd0) steuern den Fortschritt der Rätsel und Kämpfe.
 === Ende Beschreibung === */
int f_131f30(int p1, unsigned short p2)
{
void call650_133890(int,int);
#pragma aux call650_133890 "f_133890" parm [edx] [eax] modify exact [eax edx]
void call650_1337c0(int,int);
#pragma aux call650_1337c0 "f_1337c0" parm [edx] [eax] modify exact [eax edx]
    int f_0bf980(int, ...); int f_131e90(); short f_133fc0();
    int f_044890(int, int); void f_1332c0(int);
    struct Raw { int v; char *p[13]; int end; };
    Raw *f_125400(Raw *, void *, void *, void *); int f_1254a0(Raw *, int);
    struct Eq { static int eq(int x, int y) { return x == y ? 1 : 0; }
                static int eq_rev(int x, int y) { return y == x ? 1 : 0; }
                static int lt(int x, int y) { return x < y ? 1 : 0; } };
    struct Frame { Raw first, second; } frame;
    struct R650 {static int eq(const signed char &a,int k){return a==k?1:0;} static int rev(signed char a,const signed char &b){return b==a?1:0;}};
    int self=p1;
    int result = 1;
    short s;
    switch (p2) {
    case 0x65:
        if (f_0bf6f0((int)d_1c2c64, 0x27000138) == 1)
            f_0dd7f0(d_1c0004, 0x15, 0x13f5);
        break;
    case 0xc9: {
        int qthis = self;
        int q;
        if (((int (*)(int, int))f_069770)(qthis + 2, 0x5d)) {
            q = (int)operator new(0x13e, mark(d_1a8d38, 0x16d));
            if (q) q = f_0104b0(q, 0x2c0016, q ^ q, 0); // erzeugt getrenntes xor fuer das dritte Argument ohne Zusatzlokale
            f_0bf980((int)d_1c2c64, q, 0, 0x2700013c, 0);
            if (q) operator delete((void *)f_010590(q, 0));
            (**(SF3 **)(qthis + 8))(qthis, 0x5d, 0);
        }
        break;
    }
    case 0xcd: {
        int qthis = self;
        signed char z = 0;
        int ok = 0;
        z ^= z;
        if (Eq::eq_rev(z, *(signed char *)&d_1c0dd0)) {
            short count = 0;
            if (R650::eq(*(signed char *)&d_1c0da0,1)) count = 1;
            if (R650::eq(*(signed char *)&d_1c0da4,1)) count++;
            if (R650::eq(*(signed char *)&d_1c0da8,1)) count++;
            if ((int)count >= 2) ok = 1;
        }
        if (ok && (s = (**(SF3 **)(qthis + 8))(qthis, 100, 0)) != 2) {
            f_0697c0(qthis + 2, 100, 0);
            d_1c0dd0 = 1;
        }
        break;
    }
    case 0x12e: f_133890(self, 0); break;
    case 0x12f: {
        int qthis = self;
        short ix = 0;
        f_0bf730((int)d_1c2c64, 0x27000140);
        int idx = ix * 9;
        signed char one = 1;
        *(&d_1a8d64)[idx] = one;
        if (Eq::eq_rev(one, (signed char)d_1c0da0) &&
            Eq::eq((signed char)d_1c0da4, 1) &&
            Eq::eq((signed char)d_1c0da8, 1)) f_0dd640(d_1c0004, 0x259);
        else {
            f_0dd640(d_1c0004, 0xcd);
            if (f_131e90() && (s = (**(SF3 **)(qthis + 8))(qthis, 100, f_133fc0())) != 2) {
                f_0697c0(qthis + 2, 100, 0);
                f_02de20((int)&d_1c0dd0, 1);
            }
        }
        if (Eq::lt((signed char)d_1c0d9c, 5) && (s = f_1457e0(100)) < 0x32) ++d_1c0d9c;
        break;
    }
    case 0x130: f_1337c0(self, 0); break;
    case 0x192: call650_133890(1,self); break;
    case 0x193: {
        int qthis = self;
        short ix = 1;
        f_0bf730((int)d_1c2c64, 0x27000140);
        int idx = ix * 9;
        signed char one = 1;
        *(&d_1a8d64)[idx] = one;
        if (Eq::eq_rev(one, (signed char)d_1c0da0) &&
            Eq::eq((signed char)d_1c0da4, 1) &&
            Eq::eq((signed char)d_1c0da8, 1)) f_0dd640(d_1c0004, 0x259);
        else {
            f_0dd640(d_1c0004, 0xcd);
            if (f_131e90() && (s = (**(SF3 **)(qthis + 8))(qthis, 100, f_133fc0())) != 2) {
                f_0697c0(qthis + 2, 100, 0);
                f_02de20((int)&d_1c0dd0, 1);
            }
        }
        if (Eq::lt((signed char)d_1c0d9c, 5) && (s = f_1457e0(100)) < 0x32) ++d_1c0d9c;
        break;
    }
    case 0x194: call650_1337c0(1,self); break;
    case 0x1f6: f_133890(self, 2); break;
    case 0x1f7: {
        int qthis = self;
        short ix = 2;
        f_0bf730((int)d_1c2c64, 0x27000140);
        int idx = ix * 9;
        signed char one = 1;
        *(&d_1a8d64)[idx] = one;
        if (Eq::eq_rev(one, (signed char)d_1c0da0) &&
            Eq::eq((signed char)d_1c0da4, 1) &&
            Eq::eq((signed char)d_1c0da8, 1)) f_0dd640(d_1c0004, 0x259);
        else {
            f_0dd640(d_1c0004, 0xcd);
            if (f_131e90() && (s = (**(SF3 **)(qthis + 8))(qthis, 100, f_133fc0())) != 2) {
                f_0697c0(qthis + 2, 100, 0);
                f_02de20((int)&d_1c0dd0, 1);
            }
        }
        if (Eq::lt((signed char)d_1c0d9c, 5) && (s = f_1457e0(100)) < 0x32) ++d_1c0d9c;
        break;
    }
    case 0x1f8: f_1337c0(self, 2); break;
    case 0x259:
        f_0bf730((int)d_1c2c64, 0x27000146);
        f_060800(0x270004, 0, 0);
        break;
    case 0x25a:
        d_1bd6c4 = 0x259;
        f_0bf730((int)d_1c2c64, 0x27000140);
        f_0dd7f0(d_1c0004, 0x12, 0x14b4);
        f_0609d0(0xf, 3);
        break;
    case 0x25b: f_132f40(self); break;
    case 0x25c: {
        if (f_039ac0(d_1c0004, (int)f_1330b0)) {
            f_125400(&frame.second, d_1c349c, d_1c3870, d_1c3498);
            *(int *)(frame.second.p[0] + 4) = f_039320(d_1c0004, 5);
            f_0bf730((int)d_1c2c64, 0x27000155);
            int t = f_039a10(d_1c0004, 0x27000156, (int)f_1330b0);
            if (t) {
                *(int *)(frame.second.p[0] + 4) = t;
                f_0bf730((int)d_1c2c64, 0x27000157);
                f_044890(t, 6);
                f_042480((struct hero *)(t), 0);
            }
            f_1254a0(&frame.second, 0);
        } else f_0bf730((int)d_1c2c64, 0x27000158);
        break;
    }
    case 0x25d: f_0bf730((int)d_1c2c64, 0x27000159); break;
    case 0x25e: {
        f_125400(&frame.first, d_1c349c, d_1c3870, d_1c3498);
        int v = f_038c40(d_1c0004);
        int t = f_039b00(d_1c0004, v, 0x27);
        *(int *)(frame.first.p[0] + 4) = v;
        *(int *)(frame.first.p[0] + 8) = t;
        f_0bf730((int)d_1c2c64, 0x2700015a);
        if (t) f_0bf730((int)d_1c2c64, 0x2700015b);
        f_1254a0(&frame.first, 0);
        break;
    }
    case 0x25f: f_0bf730((int)d_1c2c64, 0x2700015c); break;
    case 0x260: f_0bf730((int)d_1c2c64, 0x2700015d); f_0603b0(0x3f); break;
    case 0x261:
        if (Eq::eq((signed char)d_1c0db4, 0)) f_0bf730((int)d_1c2c64, 0x2700015e);
        f_0603b0(0x40);
        break;
    case 0x1b59: case 0x1f41: f_1332c0(self); break;
    case 0x1b5a: case 0x1f42: f_133410(self, 0); break;
    case 0x1b5b: case 0x1f43: f_133410(self, 1); break;
    case 0x1b5c: case 0x1f44: f_133410(self, 2); break;
    case 0x1b5d: case 0x1f45: f_133650(self, 0); break;
    case 0x1b5f: case 0x1f47: f_133650(self, 1); break;
    case 0x1b5e: case 0x1f46: f_133650(self, 2); break;
    default: result = 0;
    }
    return result;
}
//@ f_1328d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt den Spieler an der abwärts führenden Treppe (0x27000138), ob die Gruppe die vierte
 *   Turmebene verlassen möchte, und versetzt sie bei Bestätigung zurück auf die dritte Turmebene (0x15, Position
 *   0x13f5).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1328d0()
{
    if (f_0bf6f0((int)d_1c2c64, 0x27000138) == 1) f_0dd7f0(d_1c0004, 0x15, 0x13f5);
}
//@ f_132900
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Löst bei Ereignis 0xc9 einen Kampf (0x5d) aus, sofern dieser noch nicht bestritten wurde
 *   (f_069770): Zunächst wird ein animiertes Gegnerporträt (0x2c0016) geladen und zusammen mit dem Text
 *   0x2700013c angezeigt, bevor die virtuelle Kampffunktion der Ebene für Kampf 0x5d aufgerufen wird.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q (t) verweist auf das temporär geladene Animations- bzw. Porträtobjekt (0x13e Bytes)
 *   für den Dialog f_0bf980.
 === Ende Beschreibung === */
void f_132900(int p1)
{
    int f_0bf980(int, ...);
    int q;
    int t;
    if (((int (*)(int, int))f_069770)(p1 + 2, 0x5d) != 0) {
        t = (int)operator new(0x13e, mark(d_1a8d38, 0x16d));
        q = (t != 0) ? f_0104b0(t, 0x2c0016, 0, 0) : t;
        f_0bf980((int)d_1c2c64, q, 0, 0x2700013c, 0);
        if (q) operator delete((void *)f_010590(q, 0));
        (**(VF3 **)(p1 + 8))(p1, 0x5d, 0);
    }
}
//@ f_132990
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leitet die Türinteraktion für die erste der drei Spezialtüren (Index 0, Objekt 0x1f42) an
 *   die gemeinsame Türroutine f_133410 weiter.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132990(int p1)
{
    f_133410(p1, 0);
}
//@ f_1329a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leitet die Türinteraktion für die zweite Spezialtür (Index 1, Objekt 0x1f43) an die
 *   gemeinsame Türroutine f_133410 weiter.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1329a0(int p1)
{
    f_133410(p1, 1);
}
//@ f_1329b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Leitet die Türinteraktion für die dritte Spezialtür (Index 2, Objekt 0x1f44) an die
 *   gemeinsame Türroutine f_133410 weiter.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1329b0(int p1)
{
    f_133410(p1, 2);
}
//@ f_1329c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft bei Ereignis 0xcd, ob bereits mindestens zwei der drei Zellenflags (d_1c0da0,
 *   d_1c0da4, d_1c0da8) aktiv sind und der zugehörige Wächterkampf (100) noch nicht erledigt wurde (d_1c0dd0 ==
 *   0), und startet in diesem Fall den Kampf 100 über die virtuelle Ebenenmethode.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: c zählt die aktiven Zellenflags; ok gibt an, ob die Bedingung für den Kampfstart erfüllt
 *   ist, und d_1c0dd0 wird nach erfolgreichem Abschluss (s != 2) auf 1 gesetzt.
 === Ende Beschreibung === */
void f_1329c0(int p1)
{
    struct E { static int eq(int a, int b) { return a == b ? 1 : 0; } };
    struct R650 {static int eq(const signed char &v,int k){return v==k?1:0;}};
    int ok=0;
    short c;
    short s;
    if (R650::eq(*(signed char *)&d_1c0dd0, 0)) {
        c = 0;
        if (R650::eq(*(signed char *)&d_1c0da0, 1)) c = 1;
        if (R650::eq(*(signed char *)&d_1c0da4, 1)) c++;
        if (R650::eq(*(signed char *)&d_1c0da8, 1)) c++;
        if (c >= 2) ok = 1;
    }
    if (ok && (s = (**(SF3 **)(p1 + 8))(p1, 100, 0)) != 2) {
        f_0697c0(p1+2,100,0);
        d_1c0dd0 = 1;
    }
}
//@ f_132a70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für die erste passwortgeschützte Innentür (Index 0, Objekt 0x1f45) die
 *   Passwort-Türroutine f_133650 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132a70(int p1)
{
    f_133650(p1, 0);
}
//@ f_132a80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für den ersten der drei Zellenbereiche (Index 0, Ereignis 0x12e) die Untersuchungs- und
 *   Kampfroutine f_133890 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132a80(int p1)
{
    f_133890(p1, 0);
}
//@ f_132a90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Betreten des ersten Teleporterfeldes (Ereignis 0x12f): Es zeigt die Meldung
 *   0x27000140, aktiviert das erste Zellenflag (*d_1a8d64 = 1, zeigt auf d_1c0da0) und versetzt die Gruppe
 *   entweder zum Zielpunkt 0x259 (wenn nun alle drei Zellenflags d_1c0da0, d_1c0da4 und d_1c0da8 aktiv sind)
 *   oder zum Sammelpunkt 0xcd (wobei ab zwei aktiven Flags der Kampf 100 ausgelöst wird); außerdem erhöht sich
 *   mit 50 % Wahrscheinlichkeit der Zähler d_1c0d9c bis maximal 5.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: *d_1a8d64 verweist auf das erste Zellenflag d_1c0da0; c zählt die aktiven Flags und
 *   d_1c0d9c steuert die Hinweisstufe für die Kammern.
 === Ende Beschreibung === */
void f_132a90(int p1)
{
    int saved = p1;
    short c;
    int ok;
    short s;
    f_0bf730((int)d_1c2c64, 0x27000140);
    *d_1a8d64 = 1;
    if (((signed char)d_1c0da0 == 1 ? 1 : 0) && ((signed char)d_1c0da4 == 1 ? 1 : 0) && ((signed char)d_1c0da8 == 1 ? 1 : 0)) {
        f_0dd640(d_1c0004, 0x259);
    } else {
        f_0dd640(d_1c0004, 0xcd);
        ok = 0;
        if (((int (*)(int, int))f_02de00)((int)&d_1c0dd0, 0) != 0) {
            c = 0;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da0, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da4, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da8, 1) != 0) c++;
            if ((int)c >= 2) ok = 1;
        }
        if (ok && (s = (**(SF3 **)(saved + 8))(saved, 100, 0)) != 2) {
            f_0697c0(saved + 2, 100, 0);
            d_1c0dd0 = 1;
        }
    }
    if ((d_1c0d9c < 5 ? 1 : 0) && (s = f_1457e0(100)) < 0x32) d_1c0d9c = d_1c0d9c + 1;
}
//@ f_132bd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für den ersten Zellenbereich (Index 0, Ereignis 0x130) die Schließ- und
 *   Teleporterroutine f_1337c0 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132bd0(int p1)
{
    f_1337c0(p1, 0);
}
//@ f_132be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für die zweite passwortgeschützte Innentür (Index 1, Objekt 0x1f47) die
 *   Passwort-Türroutine f_133650 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132be0(int p1)
{
    f_133650(p1, 1);
}
//@ f_132bf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für den zweiten Zellenbereich (Index 1, Ereignis 0x192) die Untersuchungs- und
 *   Kampfroutine f_133890 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132bf0(int p1)
{
    f_133890(p1, 1);
}
//@ f_132c00
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Betreten des zweiten Teleporterfeldes (Ereignis 0x193) analog zu f_132a90,
 *   setzt dabei jedoch das zweite Zellenflag (*d_1a8d88 = 1, zeigt auf d_1c0da4) und teleportiert die Gruppe je
 *   nach Gesamtstatus zu 0x259 oder 0xcd.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: *d_1a8d88 verweist auf das zweite Zellenflag d_1c0da4.
 === Ende Beschreibung === */
void f_132c00(int p1)
{
    int saved = p1;
    short c;
    int ok;
    short s;
    f_0bf730((int)d_1c2c64, 0x27000140);
    *d_1a8d88 = 1;
    if (((signed char)d_1c0da0 == 1 ? 1 : 0) && ((signed char)d_1c0da4 == 1 ? 1 : 0) && ((signed char)d_1c0da8 == 1 ? 1 : 0)) {
        f_0dd640(d_1c0004, 0x259);
    } else {
        f_0dd640(d_1c0004, 0xcd);
        ok = 0;
        if (((int (*)(int, int))f_02de00)((int)&d_1c0dd0, 0) != 0) {
            c = 0;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da0, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da4, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da8, 1) != 0) c++;
            if ((int)c >= 2) ok = 1;
        }
        if (ok && (s = (**(SF3 **)(saved + 8))(saved, 100, 0)) != 2) {
            f_0697c0(saved + 2, 100, 0);
            d_1c0dd0 = 1;
        }
    }
    if ((d_1c0d9c < 5 ? 1 : 0) && (s = f_1457e0(100)) < 0x32) d_1c0d9c = d_1c0d9c + 1;
}
//@ f_132d40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für den zweiten Zellenbereich (Index 1, Ereignis 0x194) die Schließ- und
 *   Teleporterroutine f_1337c0 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132d40(int p1)
{
    f_1337c0(p1, 1);
}
//@ f_132d50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für die dritte passwortgeschützte Innentür (Index 2, Objekt 0x1f46) die
 *   Passwort-Türroutine f_133650 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132d50(int p1)
{
    f_133650(p1, 2);
}
//@ f_132d60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ruft für den dritten Zellenbereich (Index 2, Ereignis 0x1f6) die Untersuchungs- und
 *   Kampfroutine f_133890 auf.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132d60(int p1)
{
    f_133890(p1, 2);
}
//@ f_132d70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Betreten des dritten Teleporterfeldes (Ereignis 0x1f7) analog zu f_132a90,
 *   setzt dabei das dritte Zellenflag (*d_1a8dac = 1, zeigt auf d_1c0da8) und teleportiert die Gruppe zu 0x259
 *   (wenn alle drei Flags gesetzt sind) oder zu 0xcd.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: *d_1a8dac verweist auf das dritte Zellenflag d_1c0da8.
 === Ende Beschreibung === */
void f_132d70(int p1)
{
    int saved = p1;
    short c;
    int ok;
    short s;
    f_0bf730((int)d_1c2c64, 0x27000140);
    *d_1a8dac = 1;
    if (((signed char)d_1c0da0 == 1 ? 1 : 0) && ((signed char)d_1c0da4 == 1 ? 1 : 0) && ((signed char)d_1c0da8 == 1 ? 1 : 0)) {
        f_0dd640(d_1c0004, 0x259);
    } else {
        f_0dd640(d_1c0004, 0xcd);
        ok = 0;
        if (((int (*)(int, int))f_02de00)((int)&d_1c0dd0, 0) != 0) {
            c = 0;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da0, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da4, 1) != 0) c++;
            if (((int (*)(int, int))f_02de00)((int)&d_1c0da8, 1) != 0) c++;
            if ((int)c >= 2) ok = 1;
        }
        if (ok && (s = (**(SF3 **)(saved + 8))(saved, 100, 0)) != 2) {
            f_0697c0(saved + 2, 100, 0);
            d_1c0dd0 = 1;
        }
    }
    if ((d_1c0d9c < 5 ? 1 : 0) && (s = f_1457e0(100)) < 0x32) d_1c0d9c = d_1c0d9c + 1;
}
void f_132eb0(int p1)
{
    f_1337c0(p1, 2);
}
//@ f_132ec0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Erreichen des Zielpunkts 0x259 den Text 0x27000146 an und schaltet die Licht-
 *   bzw. Umgebungseinstellung 0x270004 um.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_132ec0()
{
    f_0bf730((int)d_1c2c64, 0x27000146);
    f_060800(0x270004, 0, 0);
}
//@ f_132ef0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Sturz- bzw. Teleporterereignis 0x25a, indem die Meldung 0x27000140 ausgegeben,
 *   die aktive Gruppe auf Ebene 0x12 (Position 0x14b4) versetzt und über f_0609d0(0xf, 3) Fallschaden oder ein
 *   Sturzereignis ausgelöst wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Setzt vor dem Ebenenwechsel die globale Kennung d_1bd6c4 = 0x259.
 === Ende Beschreibung === */
void f_132ef0()
{
    d_1bd6c4 = 0x259;
    f_0bf730((int)d_1c2c64, 0x27000140);
    f_0dd7f0(d_1c0004, 0x12, 0x14b4);
    f_0609d0(0xf, 3);
}
//@ f_132f40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Inszeniert die mehrstufige Hauptkonfrontation auf der vierten Turmebene (Ereignis 0x25b),
 *   sofern diese noch nicht abgeschlossen ist (d_1c0dac == 0): Nach dem Einleitungstext 0x27000147 folgt der
 *   erste Kampf (0x3d), danach ein animierter Dialog mit dem Porträt 0x2c0017 (0x27000148) sowie ein
 *   Ereignisbild (0x270001, Index 9, Text 0x27000149), gefolgt vom zweiten Kampf (0x3e) und schließlich dem
 *   Übergang in die Endsequenz f_133b30.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q hält das animierte Sprecherporträt (0x2c0017), w das geladene Ereignisbild (0x270001,
 *   Index 9), und d_1c0dac verhindert eine Wiederholung nach dem Sieg.
 === Ende Beschreibung === */
int f_0bf980(int, ...);
int f_0bfa20(int, ...);
void f_132f40(int p1)
{
    if ((((signed char)d_1c0dac) == 0) ? 1 : 0) {
        RivaTextContext o(d_1c349c, d_1c3870, d_1c3498);
        f_0bf730((int)d_1c2c64, 0x27000147);
        *(int *)&d_1bd91c = 1;
        if (((SF3)**(int **)(p1 + 8))(p1, 0x3d, 0) == 0) {
            f_060a70();
            int t = (int)operator new(0x13e, mark(d_1a8d38, 0x2d4));
            int q = t ? f_0104b0(t, 0x2c0017, 0, 0) : t;
            f_0bf980((int)d_1c2c64, q, 0, 0x27000148, 0);
            if (q)
                operator delete((void *)f_010590(q, 0));
            int w = f_0606a0(0x270001, 9);
            f_0bfa20((int)d_1c2c64, w, 0, 0x27000149, 0);
            if (w)
                operator delete((void *)((int)(((RivaRasterImage*)(w))->f_0fad20( 0))));
            *(int *)&d_1bd91c = 1;
            if (((SF3)**(int **)(p1 + 8))(p1, 0x3e, 0) == 0) {
                *(int *)(o.slots[0] + 4) = f_039660(d_1c0004, 0);
                f_060a70();
                f_0bf730((int)d_1c2c64, 0x2700014a);
                f_060800(0x270006, 1, 0);
                f_133b30(p1);
            }
        }
    }
}
//@ f_1330b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft als Filterfunktion für einen Helden (p1), ob dieser an einer bestimmten Verletzung
 *   oder einem Zustand leidet (f_042470), der an der Heilstation (0x25c) geheilt werden kann.
 * - Eingaben: Ein Zeiger auf den zu prüfenden Helden (p1).
 * - Rückgabewert: Gibt einen Wert ungleich 0 zurück, wenn der Zustand beim Helden vorliegt, sonst 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_1330b0(int p1)
{
    return ((signed char)(f_042470((struct hero *)(p1))));
}
//@ f_1330c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Behandelt das Heilungsereignis 0x25c: Befindet sich mindestens ein betroffener Held
 *   (f_1330b0) in der Gruppe, lässt das Spiel den Spieler einen solchen Helden auswählen (0x27000156), heilt ihn
 *   um 6 Punkte (f_044890(t, 6)) und hebt den negativen Zustand auf (f_042480(t, 0)); ist niemand betroffen,
 *   erscheint die Meldung 0x27000158.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: t speichert den vom Spieler ausgewählten Helden; der Textkontext obj nimmt zunächst den
 *   Helden mit dem höchsten Wert in Talent 5 und danach den Geheilten (t) auf.
 === Ende Beschreibung === */
void f_1330c0()
{
    int f_044890(int, int);
    int t;
    if (f_039ac0(d_1c0004, (int)f_1330b0) != 0) {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        *(int *)(obj.slots[0] + 4) = f_039320(d_1c0004, 5);
        f_0bf730((int)d_1c2c64, 0x27000155);
        t = f_039a10(d_1c0004, 0x27000156, (int)f_1330b0);
        if (t != 0) {
            *(int *)(obj.slots[0] + 4) = t;
            f_0bf730((int)d_1c2c64, 0x27000157);
            f_044890(t, 6);
            f_042480((struct hero *)(t), 0);
        }
        return;
    }
    f_0bf730((int)d_1c2c64, 0x27000158);
}
//@ f_133190
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt beim Untersuchen von Ereignis 0x25d den Beschreibungstext 0x27000159 an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_133190()
{
    f_0bf730((int)d_1c2c64, 0x27000159);
}
//@ f_1331b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Gibt bei Ereignis 0x25e eine Beobachtungsmeldung (0x2700015a) mit dem Namen des
 *   Gruppenanführers aus und lässt bei Anwesenheit eines zweiten scharfsinnigen Helden (0x27) diesen einen
 *   ergänzenden Kommentar (0x2700015b) sprechen.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: p2 ist der Gruppenanführer und t der zweite Held mit hoher Sinnenschärfe (0x27).
 === Ende Beschreibung === */
void f_1331b0()
{
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    int p2 = f_038c40(d_1c0004);
    int t = f_039b00(d_1c0004, p2, 0x27);
    *(int *)(obj.slots[0] + 4) = p2;
    *(int *)(obj.slots[0] + 8) = t;
    f_0bf730((int)d_1c2c64, 0x2700015a);
    if (t != 0) f_0bf730((int)d_1c2c64, 0x2700015b);
}
//@ f_133230
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt bei Ereignis 0x25f den Raumtext 0x2700015c an.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_133230()
{
    f_0bf730((int)d_1c2c64, 0x2700015c);
}
//@ f_133250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt bei Ereignis 0x260 den Fundtext 0x2700015d an und öffnet anschließend das Beutelager
 *   0x3f.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_133250()
{
    f_0bf730((int)d_1c2c64, 0x2700015d);
    f_0603b0(0x3f);
}
//@ f_133270
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeigt bei Ereignis 0x261, sofern das Flag d_1c0db4 noch 0 ist, den Text 0x2700015e an und
 *   öffnet danach das Beutelager 0x40.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Prüft das globale Statusflag d_1c0db4.
 === Ende Beschreibung === */
void f_133270()
{
    if (EQ(d_1c0db4, 0)) f_0bf730((int)d_1c2c64, 0x2700015e);
    f_0603b0(0x40);
}
//@ f_1332a0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft als Filterfunktion, ob ein Held (p1) den achtkantigen Schlüssel ("Achtkantinbus",
 *   Gegenstand 0x199) in seinem Inventar trägt (f_0d4aa0).
 * - Eingaben: Ein Zeiger auf den zu prüfenden Helden (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn der Held den "Achtkantinbus" (0x199) besitzt, andernfalls 0.
 * - Wichtige Variablen: r_ speichert das boolesche Prüfergebnis.
 === Ende Beschreibung === */
int f_1332a0(int p1)
{
    int r_ = 0;
    if (f_0d4aa0(p1, 0x199) != -1) r_ = 1;
    return r_;
}
