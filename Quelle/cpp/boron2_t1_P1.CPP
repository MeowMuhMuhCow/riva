/* === Beschreibung (Katalog) ===
 * Einheit boron2_t1 (0x00022980 - 0x00023b80)
 *
 * Überblick
 *
 * Die Einheit boron2_t1 implementiert den ersten Teil der Dungeon-Logik für die Katakomben unter dem Boronanger
 * (BORON2.CPP). Hier befinden sich der zentrale Ereignis-Verteiler für die Gruftfelder (Sarkophage, Geheimtüren,
 * Untoten-Begegnungen, magische Barrieren und der Kampf gegen den Nekromanten bzw. Vampir) sowie die ersten
 * Feld-Handler.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 8/11 gleich (suche.py 25.10.2026, Basis boron2_t1_P1.CPP)
// boron2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x022980-0x023B80 (Teil 1)
#include <string.h>
#include "RIVAMEM.H"



int f_038c40(int p1);
int f_039320(int p1, int p2);
int f_039660(int p1, int p2);
int f_039830(int p1, int p2);
short f_03d3d0(int p1, int p2, int p3);

int f_060360(int p1);
int f_0603b0(int p1);
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_091f70(int p1);
int f_0bf6f0(int p1, int p2);
int f_0bf730(int p1, int p2);
short f_0d54f0(int p1, int p2);
short f_0db9a0(int p1);
int f_0dcbb0(int p1, int p2);
short f_0dcf00(int p1, int p2, int p3);
int f_0dd100(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
int f_0de170(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern signed char d_1bc79c, d_1bc7a0, d_1bc7a4, d_1bc7a8, d_1bc7ac, d_1bc7b0, d_1bc7b4;
extern signed char d_1bc7c8, d_1bc7cc, d_1bc7d0, d_1bc7d4, d_1bc7dc, d_1bc7e0, d_1bc7e8, d_1bc7ec;
extern int d_1a9820;
extern int d_1c0004;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a05b4[];
#define A(x) ((int)&(x))
#define FL(zn, on, v) static inline int zn() { return v == 0; } static inline int on() { return v == 1; }
FL(z79c, o79c, d_1bc79c)
FL(z7a0, o7a0, d_1bc7a0)
FL(z7a4, o7a4, d_1bc7a4)
FL(z7a8, o7a8, d_1bc7a8)
FL(z7ac, o7ac, d_1bc7ac)
FL(z7b0, o7b0, d_1bc7b0)
FL(z7b4, o7b4, d_1bc7b4)
FL(z7c8, o7c8, d_1bc7c8)
FL(z7cc, o7cc, d_1bc7cc)
FL(z7d0, o7d0, d_1bc7d0)
FL(z7d4, o7d4, d_1bc7d4)
FL(z7dc, o7dc, d_1bc7dc)
FL(z7e0, o7e0, d_1bc7e0)
FL(z7e8, o7e8, d_1bc7e8)
FL(z7ec, o7ec, d_1bc7ec)
struct MsgC { int h; int *n; int x[2]; int *s; int pad[10]; MsgC(int *a, int *b, int *c); ~MsgC(); };
struct T1 { char b[12]; T1(int k); ~T1(); void f_046de0(); };
struct Obj5f { char b[12]; Obj5f(int k, int id); ~Obj5f(); void f_05f280(int z); };
struct Base8 { int b0, b4; };
struct Host : Base8 {
    virtual short v0(int a, int b);
    int f_022980(unsigned short p2);
    void f_0234a0(); void f_0234d0(); void f_023500(); void f_0237c0(); void f_0237e0();
    void f_023970(); void f_0239a0(); void f_0239f0(); void f_023a40(); void f_023a90();
    void f_023b80(); void f_023d50(); void f_023fc0(); void f_0241a0(); void f_0244d0();
    void f_023f70(); void f_024070(); void f_0240e0(); void f_024150(); void f_0242c0(); void f_024330();
    void f_0243d0(); void f_024420(); void f_024470(); void f_0244c0(); void f_0245f0(); void f_024600(); void f_024630();
    void f_024660(); void f_0246b0(); void f_024700(); void f_024750(); void f_0247a0(); void f_0247f0(); void f_024840();
};
#define MSG MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
#define NEW46(ln, k) { T1 *o = new (mark(d_1a05b4, ln)) T1(k); o->f_046de0(); delete o; }
#define NEW5F(ln, k, id) { Obj5f *o = new (mark(d_1a05b4, ln)) Obj5f(k, id); o->f_05f280(0); delete o; }
#define CM(code) f_0bf730(A(d_1c2c64), code)
#define B_0234A0 if (f_0bf6f0(A(d_1c2c64), 0x24000039) == 1) f_0dd7f0(d_1c0004, 0xd, 0x13ec);
#define B_0234D0 if (f_0bf6f0(A(d_1c2c64), 0x2400003a) == 1) CM(0x2400003b);
#define B_0237C0 CM(0x24000045);
#define B_023970 if (z7b0()) { CM(0x2400004c); d_1bc7b0 = 1; }
#define B_0239A0 NEW46(0x298, 1)
#define B_0239F0 NEW46(0x2b9, 2)
#define B_023A40 NEW46(0x2da, 3)
#define B_023F70 if (z7c8()) { CM(0x2400005e); if (v0(0x52, 0) == 0) d_1bc7c8 = 1; }
#define B_024070 if (z7dc()) { CM(0x24000061); d_1bc7dc = 1; } if (o7dc()) { if (v0(0x54, 0) == 0) d_1bc7dc = 2; }
#define B_0240E0 if (z7d0()) { CM(0x24000062); d_1bc7d0 = 1; } if (o7d0()) { if (v0(0x55, 0) == 0) d_1bc7d0 = 2; }
#define B_024150 if (z7cc()) { CM(0x24000063); if (v0(0x56, 0) == 0) d_1bc7cc = 1; }
#define B_0242C0 if (z7d4()) { CM(0x24000068); d_1bc7d4 = 1; } if (o7d4()) { if (v0(0x57, 0) == 0) d_1bc7d4 = 2; }
#define B_024330 if (z7e0()) { MSG m.n[1] = f_038c40(d_1c0004); CM(0x24000069); d_1bc7e0 = 1; } if (o7e0()) { if (v0(0x58, 0) == 0) d_1bc7e0 = 2; }
#define B_0243D0 NEW46(0x52a, 4)
#define B_024420 NEW46(0x54b, 5)
#define B_024470 NEW46(0x56b, 6)
#define B_0244C0 f_0603b0(0x20);
#define B_0245F0 f_060360(7);
#define B_024600 if (z7e8()) { CM(0x2400006d); d_1bc7e8 = 1; }
#define B_024630 if (z7ec()) { CM(0x2400006e); d_1bc7ec = 1; }
#define B_024660 NEW5F(0x610, 4, 0x1f41)
#define B_0246B0 NEW5F(0x62e, 3, 0x1f42)
#define B_024700 NEW5F(0x64c, 2, 0x1f43)
#define B_024750 NEW5F(0x66a, 1, 0x1f44)
#define B_0247A0 NEW5F(0x688, 7, 0x1f45)
#define B_0247F0 NEW5F(0x6a6, 5, 0x1f46)
#define B_024840 NEW5F(0x6c4, 6, 0x1f47)
#define CALLS(fn, body) fn();
#define RET break;
inline void Host::f_023f70() { B_023F70 }
inline void Host::f_024070() { B_024070 }
inline void Host::f_0240e0() { B_0240E0 }
inline void Host::f_024150() { B_024150 }
inline void Host::f_0242c0() { B_0242C0 }
inline void Host::f_024330() { B_024330 }
inline void Host::f_0243d0() { B_0243D0 }
inline void Host::f_024420() { B_024420 }
inline void Host::f_024470() { B_024470 }
inline void Host::f_0244c0() { B_0244C0 }
inline void Host::f_0245f0() { B_0245F0 }
inline void Host::f_024600() { B_024600 }
inline void Host::f_024630() { B_024630 }
inline void Host::f_024660() { B_024660 }
inline void Host::f_0246b0() { B_0246B0 }
inline void Host::f_024700() { B_024700 }
inline void Host::f_024750() { B_024750 }
inline void Host::f_0247a0() { B_0247A0 }
inline void Host::f_0247f0() { B_0247F0 }
inline void Host::f_024840() { B_024840 }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_022980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet sämtliche Ereignisfelder in den Katakomben unter dem Boronanger (BORON2), darunter
 *   das Untersuchen von Sarkophagen und Nischen, das Auslösen von Untoten-Kämpfen, das Öffnen geheimer
 *   Durchgänge sowie das Entdecken ritueller Spuren.
 * - Eingaben und Rückgabe: Die Funktion erhält die Nummer des betretenen Ereignisfeldes als Parameter und gibt
 *   keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden die lokale Textdatei über d_1bc814, der Gruppenanführer d_1c0004, das
 *   Gruppeninventar und die persistenten Dungeon-Flags im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
static inline int zb0(signed char z) { return (int)d_1bc7b0 == (int)z; }
static inline int zc8(signed char z) { return (int)d_1bc7c8 == (int)z; }
static inline int zdc(signed char z) { return (int)d_1bc7dc == (int)z; }
static inline int zd0(signed char z) { signed char a = 0; a = z; return (int)d_1bc7d0 == (int)a; } // Lokale Zwischenkopie ordnet die Registerzuteilung im Switch-Zweig
static inline int zcc(signed char z) { return (int)d_1bc7cc == (int)z; }
static inline int zd4(signed char z) { return (int)d_1bc7d4 == (int)z; }
static inline int ze0(signed char z) { signed char a = 0; a = z; return (int)d_1bc7e0 == (int)a; } // Lokale Zwischenkopie ordnet die Registerzuteilung im Switch-Zweig
static inline void h_023970() { if (zb0(0)) { CM(0x2400004c); d_1bc7b0 = 1; } }
static inline void h_023f70(Host *p) { if (zc8(0)) { CM(0x2400005e); if (p->v0(0x52, 0) == 0) d_1bc7c8 = 1; } }
static inline void h_024070(Host *p) { if (zdc(0)) { CM(0x24000061); d_1bc7dc = 1; } if (o7dc()) { if (p->v0(0x54, 0) == 0) d_1bc7dc = 2; } }
static inline void h_0240e0(Host *p) { if (zd0(0)) { CM(0x24000062); d_1bc7d0 = 1; } if (o7d0()) { if (p->v0(0x55, 0) == 0) d_1bc7d0 = 2; } }
static inline void h_024150(Host *p) { if (zcc(0)) { CM(0x24000063); if (p->v0(0x56, 0) == 0) d_1bc7cc = 1; } }
static inline void h_0242c0(Host *p) { if (zd4(0)) { CM(0x24000068); d_1bc7d4 = 1; } if (o7d4()) { if (p->v0(0x57, 0) == 0) d_1bc7d4 = 2; } }
static inline void h_024330(Host *p) { if (ze0(0)) { MSG m.n[1] = f_038c40(d_1c0004); CM(0x24000069); d_1bc7e0 = 1; } if (o7e0()) { if (p->v0(0x58, 0) == 0) d_1bc7e0 = 2; } }
int Host::f_022980(unsigned short p2)
{
    int r = 0;
    r = 1;
    switch (p2) {
    case 0x65: CALLS(f_0234a0, B_0234A0) RET
    case 0x66: CALLS(f_0234d0, B_0234D0) RET
    case 0x67: f_023500(); RET
    case 0xc9: CALLS(f_0237c0, B_0237C0) RET
    case 0xca: f_0237e0(); RET
    case 0xcb: RET
    case 0x12d: h_023970(); RET
    case 0x12e: CALLS(f_0239a0, B_0239A0) RET
    case 0x12f: {
        extern void *f_046d10(void *, int);
        unsigned sz = 0xc;
        T1 *o = (T1 *)operator new(sz, mark(d_1a05b4, 0x2b9));
        if (o) o = (T1 *)f_046d10(o, 2);
        o->f_046de0();
        delete o;
    } RET
    case 0x130: CALLS(f_023a40, B_023A40) RET
    case 0x131: f_023a90(); RET
    case 0x132: f_023b80(); RET
    case 0x133: f_023d50(); RET
    case 0x191: h_023f70(this); RET
    case 0x192: f_023fc0(); RET
    case 0x193: h_024070(this); RET
    case 0x194: h_0240e0(this); RET
    case 0x1f5: h_024150(this); RET
    case 0x1f6: f_0241a0(); RET
    case 0x1f7: h_0242c0(this); RET
    case 0x1f8: h_024330(this); RET
    case 0x259: {
        extern void *f_046d10(void *, int);
        unsigned sz4 = 0xc;
        T1 *o = (T1 *)operator new(sz4, mark(d_1a05b4, 0x52a));
        if (o) o = (T1 *)f_046d10(o, 4);
        o->f_046de0();
        delete o;
    } RET
    case 0x25a: {
        void *tag = mark(d_1a05b4, 0x54b);
        T1 *o = new (tag) T1(5);
        o->f_046de0();
        delete o;
    } RET
    case 0x25b: CALLS(f_024470, B_024470) RET
    case 0x2bd: CALLS(f_0244c0, B_0244C0) RET
    case 0x2be: f_0244d0(); RET
    case 0x2bf: CALLS(f_0245f0, B_0245F0) RET
    case 0x2c0: CALLS(f_024600, B_024600) RET
    case 0x321: CALLS(f_024630, B_024630) RET
    case 0x1b59: case 0x1f41: CALLS(f_024660, B_024660) RET
    case 0x1b5a: case 0x1f42: CALLS(f_0246b0, B_0246B0) RET
    case 0x1b5b: case 0x1f43: CALLS(f_024700, B_024700) RET
    case 0x1b5c: case 0x1f44: CALLS(f_024750, B_024750) RET
    case 0x1b5d: case 0x1f45: CALLS(f_0247a0, B_0247A0) RET
    case 0x1b5e: case 0x1f46: CALLS(f_0247f0, B_0247F0) RET
    case 0x1b5f: case 0x1f47: CALLS(f_024840, B_024840) RET
    default: r = 0; break;
    }
    return r;
}
//@ f_0234a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Verlassen des Katakomben-Dungeons den Speicherpuffer für die Grufttexte wieder frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben wird der Textpufferzeiger d_1bc814.
 === Ende Beschreibung === */
void Host::f_0234a0() { B_0234A0 }
//@ f_0234d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim Abstieg in die Katakomben unter dem Boronanger die Textdatei der Gruft in den
 *   Speicher und initialisiert den Dungeon-Zustand.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gesetzt wird der Textpufferzeiger d_1bc814 über f_0a27a0.
 === Ende Beschreibung === */
void Host::f_0234d0() { B_0234D0 }
//@ f_023500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Untersuchung eines besonderen Sarkophags oder Altars in den Katakomben, führt
 *   notwendige Proben durch und übergibt bei Erfolg gefundene Grabbeigaben oder löst eine Falle beziehungsweise
 *   Begegnung aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden der Textpuffer d_1bc814, der aktive Held d_1c0004 und die Einmal-Flags im
 *   Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void Host::f_023500()
{
    MSG
    if (z79c()) { CM(0x2400003c); d_1bc79c = 1; }
    if (o79c() && z7a0()) {
        if (f_0bf6f0(A(d_1c2c64), 0x2400003d) == 1) {
            if (f_0d54f0(d_1c0004, 0x16e) != -1) {
                int result = f_039320(d_1c0004, 0x30); result = (result & 0) ? 0 : result; // Haelt m.n fuer die Zuweisung m.n[1] in ebx statt edx
                m.n[1] = result;
                CM(0x2400003e);
                d_1bc7a0 = 1;
                f_060740(0x1f4a, 1);
                f_0607e0(0x1f4a, 1);
                f_0dcf00(d_1c0004, 0x16f, 1);
            } else {
                CM(0x2400003f);
            }
        }
    }
    if (o7a0() && z7a4()) {
        int r = f_0de170(d_1c0004, 0x16d);
        if (r != -1) {
            m.n[1] = f_039320(d_1c0004, 0x30);
            { int snd = d_1a9820; f_147323(A(d_1c2edc), 0x240008, 0x7fff, 0x8000, snd, 0, 1); }
            CM(0x24000040);
            f_0dcbb0(d_1c0004, 5);
            d_1bc7a4 = 1;
            CM(0x24000041);
            f_0dd100(d_1c0004, 0x16d);
            f_060740(1000, 1);
            f_060740(0x3e9, 1);
            return;
        }
        int b = f_039830(d_1c0004, 0x1c);
        int c = ((short)f_0d54f0(d_1c0004, 0x23) != -1);
        if (c == 0 && b == 0) {
            CM(0x24000042);
        } else {
            if (c == 1) {
                f_125ed0(A(d_1c2c44), 10);
                m.n[1] = f_039320(d_1c0004, 0x30);
                CM(0x24000043);
            }
            if (b != 0) {
                f_125ed0(A(d_1c2c44), 5);
                m.n[2] = b;
                CM(0x24000044);
            }
        }
    }
}
//@ f_0237c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand eines Dungeon-Merkers, ob ein bestimmtes Ereignis in den Katakomben bereits
 *   ausgelöst wurde.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt den aktuellen Zustandswert zurück.
 * - Wichtige Variablen: Gelesen wird ein Statusbyte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void Host::f_0237c0() { B_0237C0 }
//@ f_0237e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt dem Gruppenanführer auf Feld 202 der Katakomben, eine unheimliche Stelle mit *Odem
 *   Arcanum* (0x28) oder *Analüs Arcanstruktur* (0x27) magisch zu durchleuchten, und gibt je nach Erfolg der
 *   Zauberprobe den entsprechenden Erkenntnistext aus. *(Hinweis: Hier liegt ein Originalfehler vor, da beim
 *   Analüs-Zauber nach der Probe der Abzug der Astralpunkte über f_044230 vergessen wurde.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Gruppenanführer d_1c0004, die Astralpunktprüfung f_039830, die
 *   Zauberprobe f_03d3d0, der AE-Abzug f_044230 (nur im Odem-Zweig aufgerufen) und der Textpuffer d_1bc814.
 === Ende Beschreibung === */
void Host::f_0237e0()
{
    MSG
    if (z7a8()) {
        CM(0x24000046);
        d_1bc7a8 = 1;
        int a = f_039830(d_1c0004, 0x27);
        if (a != 0) {
            if (f_03d3d0(a, 0x27, 10) > 0) {
                f_125ed0(A(d_1c2c44), 0xf);
                m.n[1] = a;
                CM(0x24000047);
            }
        }
    }
    if (o7a8()) {
        if (z7ac()) {
            if (f_0bf6f0(A(d_1c2c64), 0x24000048) == 1) {
                m.n[1] = f_038c40(d_1c0004);
                CM(0x24000049);
                f_0dcf00(d_1c0004, 0x16f, 4);
                f_060740(0x1f49, 1);
                f_0607e0(0x1f49, 1);
                d_1bc7ac = 1;
            }
        }
        if (o7ac()) {
            if (f_0bf6f0(A(d_1c2c64), 0x2400004a) == 1) CM(0x2400004b);
        }
    }
}

//@ f_023960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Wert eines Fortschrittsmerkers aus den Katakomben zurück.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und liefert das Statusbyte als Ganzzahl.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void f_023960(void)
{
}

//@ f_023970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt an einer Stelle der Katakomben einen Beschreibungstext aus und setzt bei Bedarf das
 *   zugehörige Besuchsflag.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc814 und ein Statusbyte des Katakomben-Zustandsblocks.
 === Ende Beschreibung === */
void Host::f_023970() { B_023970 }
//@ f_0239a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim Betreten eines bestimmten Korridors oder Raums in den Katakomben eine
 *   atmosphärische Meldung an und vermerkt, dass die Gruppe diesen Ort gesehen hat.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Textpuffer d_1bc814 und ein Einmal-Flag im Bereich
 *   d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void Host::f_0239a0() { B_0239A0 }
//@ f_0239f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Präsentiert den Spielern eine Inschrift oder Beobachtung an einer Gruftwand und aktualisiert
 *   den zugehörigen Ereignismerker.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Zugegriffen wird auf d_1bc814 sowie die Ortsflags der Katakomben.
 === Ende Beschreibung === */
void Host::f_0239f0() { B_0239F0 }
//@ f_023a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt an einem weiteren Ereignispunkt der Katakomben eine Textbeschreibung aus und speichert
 *   den Besuch im Ortsstatus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Textpuffer d_1bc814 und die Statusmerker im Bereich
 *   d_1bc7b8-d_1bc810.
 === Ende Beschreibung === */
void Host::f_023a40() { B_023A40 }
//@ f_023a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an einer Nische oder einem Versteck in der Gruft, ob der Ort durchsucht
 *   werden soll, und händigt beim ersten Durchsuchen die dort versteckten Gegenstände aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden der Textpuffer d_1bc814, die Beuteübergabe f_051360 und das zugehörige
 *   Einmal-Flag im Katakomben-Datenblock.
 === Ende Beschreibung === */
void Host::f_023a90()
{
    if (z7b4()) {
        int u = f_039660(d_1c0004, 0xc);
        if (f_0bf6f0(A(d_1c2c64), 0x2400004d) == 1) {
            MSG
            m.n[1] = u;
            CM(0x2400004e);
            if (f_0db9a0(d_1c0004) > 1) {
                signed char c = f_042380((struct hero *)(u));
                int b = (unsigned char)(c != 0);
                b += 0x2400004f;
                m.s[1] = b;
                CM(0x24000051);
            } else {
                CM(0x24000052);
            }
            d_1bc7b4 = 1;
            f_0dcbb0(d_1c0004, 5);
            f_091f70(0xc);
        }
    }
}
