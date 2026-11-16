/* === Beschreibung (Katalog) ===
 * Einheit gz_0625e0 (0x0625e0 - 0x063550)
 *
 * Überblick
 * Diese Grenzeinheit zwischen editor2.cpp und environ1.cpp enthält zunächst die Pufferkopierfunktion f_0625e0
 * des Texteditors und anschließend den ersten Teil des Schauplatzes Ort 4 (environ1, Wildnis-/Umgebungsgebiet
 * mit Textdatei 0x36): die Registrierung der Ortsmerker 0x203..0x209, den Ortskonstruktor, den zentralen
 * Feldereignis-Verteiler f_0627c0 für die Felder 101..704 sowie die ausgelagerten Einzelfunktionen der Felder
 * 101..402.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 19/21 gleich (suche.py 26.10.2026, Basis gz_0625e0_P1.CPP)
#define EQI(x,v) (((x)==(v))?1:0)
// P1 7/21 gleich
// gz_0625e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0625E0-0x063550
#include <string.h>
#include "RIVAMEM.H"



struct Obj { int a; int *b; char rest[52]; };
struct VT { short (*fn)(void *self, int msg, int arg); };
struct X { char pad[8]; VT *vt; };
struct S { char pad[0x2c]; char *buf; };
int f_036300(int p1, int p2, int p3);
int f_038be0(int p1);
int f_038c40(int p1);
int f_039320(int p1, int p2);
short f_039910(int p1, int (*p2)(int));
int f_039a80(int p1, int (*p2)(int));
int f_0641c0(int p1);
int f_0630d0(int p1);
int f_040980(int p1, int p2);


int f_044300(int p1, int p2);
short f_044c90(int p1, int p2, int p3);
void *f_05ff60(void *p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_063550();
int f_063650();
int f_063900(X *p1, int p2);
int f_063f40(X *p1, int p2);
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
short f_0db9a0(int p1);
int f_0dbb20(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
int f_125400(Obj *p1, void *p2, void *p3, void *p4);
int f_1254a0(Obj *p1, int p2);
short f_1457e0(int p1);
int f_147323(void *p1, int p2, unsigned short p3, unsigned short p4, int p5, short p6, unsigned short p7);
extern char *d_1a34e0;
extern int d_1a9820;
extern int d_1bae14[];
extern signed char d_1bd6cc;
extern signed char d_1bd6d0;
extern unsigned short d_1bd6d1;
extern signed char d_1bd6d4;
extern short d_1bd6d5;
extern signed char d_1bd6d8;
extern unsigned short d_1bd6d9;
extern signed char d_1bd6dc;
extern signed char d_1bd6dd;
extern short d_1bd6e0;
extern short d_1bd6e1;
extern signed char d_1bd6e4;
extern short d_1bd6e5;
extern signed char d_1bd6e8;
extern signed char d_1bd6e9;
extern int d_1c0004;
extern signed char d_1c0c9c;
extern signed char d_1c0cd4;
extern unsigned short d_1c212a;
extern void * *d_1c212c;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
//@ f_0625e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert den 64000 Bytes großen 320x200-Zielbildpuffer (p->buf an Offset +0x2c) eines Editor-
 *   oder Grafikobjekts in den VGA-Bildschirmspeicher d_1a34e0, sofern es sich nicht bereits um denselben Puffer
 *   handelt, und blendet für die Dauer des Kopiervorgangs einen sichtbaren Mauszeiger aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf das Objekt mit Bildpufferzeiger an Offset +0x2c
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Prüft p->buf != d_1a34e0 und kopiert 64000 Bytes per memcpy.
 === Ende Beschreibung === */
void f_0625e0(S *p)
{
    if (p->buf != d_1a34e0) {
        MG mg;
        memcpy(d_1a34e0, p->buf, 64000);
    }
}

//@ f_062650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert beim Programmstart die sieben Ortsmerker d_1bd6d0..d_1bd6e8 des Ortes 4 mit dem
 *   Wert 0 sowie den Kennnummern 0x203..0x209 und hängt sie an die globale BVAR-Variablenliste
 *   (d_1c212c/d_1c212a) an, damit erledigte Ereignisse und Kämpfe dieses Gebiets im Spielstand gespeichert
 *   werden.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die sieben Ortsmerker d_1bd6d0 (0x203, Feld 104), d_1bd6d4 (0x204, Feld 302), d_1bd6d8
 *   (0x205, Feld 303), d_1bd6dc (0x206, Feld 304), d_1bd6e0 (0x207, Feld 401), d_1bd6e4 (0x208, Kampf 0x94 auf
 *   Feld 402) und d_1bd6e8 (0x209, Feld 501) werden registriert, während d_1bd6cc (Feld 101) unregistriert
 *   bleibt.
 === Ende Beschreibung === */
struct RegObj_062650 { signed char a; short b; };
struct RegObjV_062650 { signed char a; short b; };
struct RegList_062650 { short count; RegObj_062650 **list; };
extern RegObj_062650 d_o0_062650, d_o4_062650, d_o8_062650, d_oc_062650, d_o10_062650, d_o14_062650, d_o18_062650;
extern RegObjV_062650 d_ocv_062650;
extern RegList_062650 d_r_062650;
#pragma aux d_o0_062650 "d_1bd6d0"
#pragma aux d_o4_062650 "d_1bd6d4"
#pragma aux d_o8_062650 "d_1bd6d8"
#pragma aux d_oc_062650 "d_1bd6dc"
#pragma aux d_ocv_062650 "d_1bd6dc"
#pragma aux d_o10_062650 "d_1bd6e0"
#pragma aux d_o14_062650 "d_1bd6e4"
#pragma aux d_o18_062650 "d_1bd6e8"
#pragma aux d_r_062650 "d_1c212a"
inline signed char z_062650() { signed char c = 0; return c; }
inline short id_062650() { short id = 0x206; return id; }
inline void add_062650(RegObj_062650 &o, RegList_062650 &r, short id)
{
    o.a = z_062650();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
void f_062650(void)
{
    add_062650(d_o0_062650, d_r_062650, 0x203);
    add_062650(d_o4_062650, d_r_062650, 0x204);
    d_o8_062650.a = z_062650();
    d_o8_062650.b = 0x205;
    d_r_062650.list[d_r_062650.count] = &d_o8_062650;
    d_r_062650.count++;
    d_oc_062650.a = z_062650();
    d_oc_062650.b = 0x206;
    d_r_062650.list[d_r_062650.count] = &d_oc_062650;
    d_r_062650.count++;
    d_o10_062650.a = z_062650();
    d_o10_062650.b = 0x207;
    d_r_062650.list[d_r_062650.count] = &d_o10_062650;
    d_o14_062650.a = z_062650();
    d_r_062650.count += 1;
    d_o14_062650.b = 0x208;
    d_r_062650.list[d_r_062650.count] = &d_o14_062650;
    d_r_062650.count++;
    d_o18_062650.a = z_062650();
    d_o18_062650.b = 0x209;
    d_r_062650.list[d_r_062650.count] = &d_o18_062650;
    d_r_062650.count++;
}

//@ f_0627a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor des Ortsobjekts für Ort 4 (aufgerufen aus der Ortsfabrik dodungeo f_05ecf0): ruft
 *   den Basis-Ortskonstruktor f_05ff60(p1, 4) auf und trägt die virtuelle Methodentabelle d_1bae14 an Offset +8
 *   ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das neu angelegte Ortsobjekt und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Setzt den Vtable-Zeiger *(void )(r + 8) = d_1bae14.
 === Ende Beschreibung === */
void f_0627a0(void *p1)
{
    char *r = (char *)f_05ff60(p1, 4);
    *(void **)(r + 8) = d_1bae14;
}

//@ f_0627c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentraler Feldereignis-Verteiler des Ortes 4 (Textdatei 0x36): wertet die Feldkennung msg
 *   (101..704, d. h. 0x65..0x2c0) aus und löst die zugehörigen Gebietsereignisse aus, darunter einmalige
 *   Hinweismeldungen (Felder 101, 104, 301..305, 701, 704), schwere Gruppengefahren und Gepäckverlust (Felder
 *   102, 103), Belastungsproben f_063900 mit Erschwernis 12/10/8/4 (Felder 201..204), eine Gefahrensinn-Falle
 *   mit Wundfieber (Feld 205), eine Wildnisbegegnung f_063f40 (Feld 401), die Kämpfe 0x94 (Feld 402) und 0x96
 *   (Feld 702) sowie Gebietsübergänge nach Ort 5 (Feld 501, f_063550) und Ort 0x12 (Felder 702, 703).
 * - Eingaben und Rückgabe: Die Methode erhält den Zeiger p1 auf das Ortsobjekt und die Feldkennung msg. Sie gibt
 *   1 zurück, wenn das Feldereignis behandelt wurde, oder 0 bei einer unbekannten Kennung.
 * - Wichtige Variablen: Prüft und setzt die Ortsmerker d_1bd6cc..d_1bd6e4 sowie die spielweiten Merker d_1c0c9c
 *   (Kampf 0x96 auf Feld 702 erledigt) und d_1c0cd4 (Übergang auf Feld 703 freigeschaltet).
 === Ende Beschreibung === */
int f_063900_z(X *p1, int p2);
#pragma aux f_063900_z "f_063900" modify [esi];
static inline unsigned short h_627u(unsigned short x){return x;}
static inline int h_627eq(int x, int v){return x==v;}
static inline short h_627s(short x){return x;}
static inline int h_627d(){return d_1a9820;}
static inline void h_627v(X *p1){
        if (EQB(d_1bd6e4,0)) {
            f_0bf730(&d_1c2c64, 0x3600002a);
            if (p1->vt->fn(p1, 0x94, 0) == 0) d_1bd6e4 = 1;
        }

}
static inline void h_627w(X*p1,Obj&ob){int u;

        if (EQB(d_1c0c9c,0)) {
            f_125400(&ob, &d_1c349c, &d_1c3870, &d_1c3498);
            u = f_038c40(d_1c0004);
            ob.b[1] = u;
            f_0bf730(&d_1c2c64, 0x36000033);
            p1->vt->fn(p1, 0x96, 0);
            d_1c0c9c = 1;
            f_1254a0(&ob, 0);
            return;
        }
        if (f_0bf6f0(&d_1c2c64, 0x36000034) == 1) f_0dd7f0(d_1c0004, 0x12, 0x66);
        return;
}
int f_0627c0(X *p1, int msg)
{
    short t = 0;
    int r = 1;
    struct L {
        Obj o1BC, o180, o144, o108, oCC, o90, o54;
        short s18;
    } l;
    int ucase;
    switch ((unsigned short)msg) {
    case 0x65:
        if (d_1bd6cc != 0) break;
        d_1bd6cc = 1;
        f_0bf730(&d_1c2c64, 0x36000001);
        return 1;
    case 0x66:
        f_147323(&d_1c2edc, 0x360005, h_627u(0x7fff), h_627u(0x8000), h_627d(), h_627s(0), h_627u(1));
        f_0bf730(&d_1c2c64, 0x36000002);
        f_039a80(d_1c0004, f_0641c0);
        if (f_0db9a0(d_1c0004) <= r) break;
        f_0bf730(&d_1c2c64, 0x36000003);
        f_060800(0x360002, 1, 0);
        return r;
    case 0x67: {
        f_125400(&l.o108, &d_1c349c, &d_1c3870, &d_1c3498);
        t = f_039910(d_1c0004, f_0630d0);
        f_147323(&d_1c2edc, 0x360006, h_627u(0x7fff), h_627u(0x8000), h_627d(), h_627s(0), h_627u(1));
        if (t > 0) {
            f_0bf730(&d_1c2c64, 0x36000004);
            ucase = 5;
        } else {
            f_0bf730(&d_1c2c64, 0x36000005);
            ucase = 10;
        }
        f_0dbb20(d_1c0004, ucase);
        f_1254a0(&l.o108, 0);
        return r;
    }
    case 0x68:
        if (!h_627eq(d_1bd6d0, (signed char)(msg ^ msg))) break;
        f_0bf730(&d_1c2c64, 0x36000006);
        d_1bd6d0 = 1;
        return r;
    case 0xc9: f_063900_z(p1, 12); return r;
    case 0xca: f_063900_z(p1, 10); return r;
    case 0xcb: f_063900_z(p1, 8); return r;
    case 0xcc: f_063900_z(p1, 4); return r;
    case 0xcd:
        l.s18 = 5;
        {
        int ucd;
        short limit = 10;
        if (f_1457e0(100) > limit) break;
        f_125400(&l.o54, &d_1c349c, &d_1c3870, &d_1c3498);
        ucd = f_038be0(d_1c0004);
        l.o54.b[1] = ucd;
        f_147323(&d_1c2edc, 0x360007, h_627u(0x7fff), h_627u(0x8000), h_627d(), h_627s(0), h_627u(1));
        if (f_044c90(ucd, 0x32, (signed char)l.s18) > 0) {
            f_0bf730(&d_1c2c64, 0x3600001d);
        } else {
            f_0bf730(&d_1c2c64, 0x3600001e);
            f_044300(ucd, 2);
            f_040980(ucd, 1);
        }
        f_1254a0(&l.o54, 0);
        return r;
        }
    case 0x12d:
        f_125400(&l.oCC, &d_1c349c, &d_1c3870, &d_1c3498);
        l.oCC.b[1] = f_039320(d_1c0004, 0x1f);
        f_0bf730(&d_1c2c64, 0x3600001f);
        f_1254a0(&l.oCC, 0);
        return r;
    case 0x12e:
        if (!EQB(d_1bd6d4,0)) break;
        f_125400(&l.o180, &d_1c349c, &d_1c3870, &d_1c3498);
        l.o180.b[1] = f_039320(d_1c0004, 0x1a);
        f_0bf730(&d_1c2c64, 0x36000020);
        d_1bd6d4 = 1;
        f_1254a0(&l.o180, 0);
        return r;
    case 0x12f:
        if (EQB(d_1bd6d8,0) && f_0db9a0(d_1c0004) > 1) {
            f_125400(&l.o1BC, &d_1c349c, &d_1c3870, &d_1c3498);
            l.o1BC.b[1] = f_039320(d_1c0004, 0x1c);
            f_0bf730(&d_1c2c64, 0x36000021);
            d_1bd6d8 = 1;
            f_1254a0(&l.o1BC, 0);
        }
        return r;
    case 0x130:
        if (EQB(d_1bd6dc,0)) {
            f_125400(&l.o90, &d_1c349c, &d_1c3870, &d_1c3498);
            l.o90.b[1] = f_039320(d_1c0004, 0x1a);
            f_0bf730(&d_1c2c64, 0x36000020);
            d_1bd6dc = 1;
            f_1254a0(&l.o90, 0);
        }
        return r;
    case 0x131: f_0bf730(&d_1c2c64, 0x36000022); return r;
    case 0x191: f_063f40(p1, 15); return r;
    case 0x192: h_627v(p1); return r;
    case 0x1f5: ((int(*)(X*))f_063550)(p1); return r;
    case 0x259: ((int(*)(X*))f_063650)(p1); return r;
    case 0x2bd: f_0bf730(&d_1c2c64, 0x36000032); return r;
    case 0x2be: h_627w(p1,l.o144); return r;
    case 0x2bf:
        if (EQB(d_1c0cd4,0)) {
            f_0bf730(&d_1c2c64, 0x36000035);
            return r;
        }
        if (f_0bf6f0(&d_1c2c64, 0x36000036) == 1) f_0dd7f0(d_1c0004, 0x12, 0x14b4);
        return r;
    case 0x2c0:
        f_0bf730(&d_1c2c64, 0x36000037);
        return r;
    default:
        r = 0;
    }
    return r;
}

#define Q147(a) { int v5 = d_1a9820; f_147323(&d_1c2edc, a, 0x7fff, 0x8000, v5, 0, 1); }
//@ f_063020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 101: zeigt beim ersten Betreten (d_1bd6cc == 0) die
 *   Meldung 0x36000001 an und setzt den Merker d_1bd6cc = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwendet den im Spielstand nicht mitgespeicherten Sitzungsmerker d_1bd6cc.
 === Ende Beschreibung === */
void f_063020()
{
    if (d_1bd6cc == 0) {
        d_1bd6cc = 1;
        f_0bf730(&d_1c2c64, 0x36000001);
    }
}

//@ f_063050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 102: spielt den Klang 0x360005 ab, zeigt die Meldung
 *   0x36000002, wendet auf jeden Helden der aktiven Gruppe die schwere Auswirkung f_0641c0 an (Verlust der
 *   Gegenstände auf den Plätzen 9/10, 30 LE Schaden, Charisma -1) und zeigt, falls danach noch mehr als ein Held
 *   handlungsfähig ist (f_0db9a0 > 1), zusätzlich die Meldung 0x36000003 und die Szene 0x360002 (f_060800).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ruft über f_039a80(d_1c0004, f_0641c0) die Schadensfunktion für alle Gruppenmitglieder
 *   auf.
 === Ende Beschreibung === */
void f_063050()
{
    int v;
    ((int (*)(void *, int, int, int, int, int, int))f_147323)(&d_1c2edc, 0x360005, 0x7fff, 0x8000, (v = d_1a9820), 0, 1);
    f_0bf730(&d_1c2c64, 0x36000002);
    f_039a80(d_1c0004, f_0641c0);
    if (f_0db9a0(d_1c0004) > 1) {
        f_0bf730(&d_1c2c64, 0x36000003);
        f_060800(0x360002, 1, 0);
    }
}
#pragma aux f_147323 modify [esp];

//@ f_0630d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüf- und Wirkfunktion für f_039910 auf Feld 103: prüft für einen lebenden Helden p1, ob auf
 *   dessen Inventarplatz 14 (0x0e) ein Gegenstand liegt (f_042a60), wirft in diesem Fall ein Stück davon ab
 *   (f_036300) und meldet 1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 zurück, wenn der Held einen
 *   Gegenstand von Platz 14 abgeworfen hat, sonst 0.
 * - Wichtige Variablen: Prüft den Tod-Status über f_042470(p1) und den Inventarplatz 0x0e über f_042a60(p1,
 *   0x0e).
 === Ende Beschreibung === */
int f_0630d0(int p1)
{
    char c = ((char)(f_042470((struct hero *)(p1))));
    int u = 0;
    if (!c) {
        if (f_042a60((struct hero *)(p1), 0xe) > 0) {
            f_036300(p1, 0xe, 1);
            u = 1;
        }
    }
    return u;
}

//@ f_063110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 103: lässt alle Helden der aktiven Gruppe über f_0630d0
 *   ihren Gegenstand auf Platz 14 abwerfen, spielt den Klang 0x360006 ab und zieht jedem Helden der Gruppe über
 *   f_0dbb20 entweder 5 LE (wenn mindestens ein Held etwas abgeworfen hat, Meldung 0x36000004) oder 10 LE (wenn
 *   niemand etwas abwerfen konnte, Meldung 0x36000005) ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokale Variable t zählt über f_039910(d_1c0004, f_0630d0), wie viele Helden einen
 *   Gegenstand von Platz 14 verloren haben.
 === Ende Beschreibung === */
void f_063110()
{
    Obj o;
    int u;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    short t = f_039910(d_1c0004, f_0630d0);
    Q147(0x360006)
    if ((short)t > 0) {
        f_0bf730(&d_1c2c64, 0x36000004);
        u = 5;
    } else {
        f_0bf730(&d_1c2c64, 0x36000005);
        u = 10;
    }
    f_0dbb20(d_1c0004, u);
    f_1254a0(&o, 0);
}

//@ f_0631c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 104: zeigt beim ersten Betreten (d_1bd6d0 == 0) die
 *   Meldung 0x36000006 an und setzt den Ortsmerker d_1bd6d0 = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt den registrierten Ortsmerker d_1bd6d0 (Kennnummer 0x203).
 === Ende Beschreibung === */
void f_0631c0()
{
    if (EQI(d_1bd6d0, 0)) {
        f_0bf730(&d_1c2c64, 0x36000006);
        d_1bd6d0 = 1;
    }
}

//@ f_0631f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 201: löst über f_063900(p1, 12) eine Belastungsprobe des
 *   am schwersten beladenen Helden mit Erschwernis +12 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Leitet direkt an f_063900 (environ1) mit dem Erschwerniswert 12 weiter.
 === Ende Beschreibung === */
void f_0631f0(X *p1)
{
    f_063900(p1, 0xc);
}

//@ f_063200
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 202: löst über f_063900(p1, 10) eine Belastungsprobe mit
 *   Erschwernis +10 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Leitet an f_063900 (environ1) mit Erschwernis 10 weiter.
 === Ende Beschreibung === */
void f_063200(X *p1)
{
    f_063900(p1, 10);
}

//@ f_063210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 203: löst über f_063900(p1, 8) eine Belastungsprobe mit
 *   Erschwernis +8 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Leitet an f_063900 (environ1) mit Erschwernis 8 weiter.
 === Ende Beschreibung === */
void f_063210(X *p1)
{
    f_063900(p1, 8);
}

//@ f_063220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 204: löst über f_063900(p1, 4) eine Belastungsprobe mit
 *   Erschwernis +4 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Leitet an f_063900 (environ1) mit Erschwernis 4 weiter.
 === Ende Beschreibung === */
void f_063220(X *p1)
{
    f_063900(p1, 4);
}

//@ f_063230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 205: mit 10 % Wahrscheinlichkeit (1W100 <= 10) gerät ein
 *   zufälliger handlungsfähiger Held (f_038be0) in eine Gefahr (Klang 0x360007) und legt eine Gefahrensinn-Probe
 *   (Talent 0x32) mit Erschwernis +5 ab; bei Erfolg erscheint die Warnmeldung 0x3600001d, bei Misserfolg die
 *   Meldung 0x3600001e und der Held erleidet 2 LE Schaden (f_044300) sowie Wundfieber (f_040980(u, 1)).
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Setzt den betroffenen Helden u in o.b[1] als Namensplatzhalter für die Meldungstexte
 *   0x3600001d/0x3600001e.
 === Ende Beschreibung === */
void f_063230()
{
    short s = 5;
    Obj o;
    int u;
    short t_389 = f_1457e0(100);
    if (t_389 <= (short)10) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        u = f_038be0(d_1c0004);
        o.b[1] = u;
        Q147(0x360007)
        if (f_044c90(u, 0x32, (signed char)s) > 0) {
            f_0bf730(&d_1c2c64, 0x3600001d);
        } else {
            f_0bf730(&d_1c2c64, 0x3600001e);
            f_044300(u, 2);
            f_040980(u, 1);
        }
        f_1254a0(&o, 0);
    }
}

//@ f_063310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 301: ermittelt den Helden mit dem höchsten Talentwert in
 *   Wildnisleben (Talent 0x1f, f_039320) und gibt mit seinem Namen die Hinweismeldung 0x3600001f aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Übergibt den besten Wildnisleben-Helden in o.b[1] an das Meldungsfenster d_1c2c64.
 === Ende Beschreibung === */
void f_063310()
{
    Obj o;
    int u;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    u = f_039320(d_1c0004, 0x1f);
    o.b[1] = u;
    f_0bf730(&d_1c2c64, 0x3600001f);
    f_1254a0(&o, 0);
}

//@ f_063370
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 302: nennt beim ersten Betreten (d_1bd6d4 == 0) den
 *   besten Fährtensucher der Gruppe (Talent 0x1a) in der Meldung 0x36000020 und setzt den Ortsmerker d_1bd6d4 =
 *   1.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt den registrierten Ortsmerker d_1bd6d4 (Kennnummer 0x204).
 === Ende Beschreibung === */
void f_063370()
{
    Obj o;
    int u;
    if (EQI(d_1bd6d4, 0)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        u = f_039320(d_1c0004, 0x1a);
        o.b[1] = u;
        f_0bf730(&d_1c2c64, 0x36000020);
        d_1bd6d4 = 1;
        f_1254a0(&o, 0);
    }
}

//@ f_0633e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 303: nennt beim ersten Betreten (d_1bd6d8 == 0), sofern
 *   mehr als ein Held handlungsfähig ist (f_0db9a0 > 1), den Helden mit dem höchsten Orientierungswert (Talent
 *   0x1c) in der Meldung 0x36000021 und setzt den Ortsmerker d_1bd6d8 = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt den registrierten Ortsmerker d_1bd6d8 (Kennnummer 0x205).
 === Ende Beschreibung === */
void f_0633e0()
{
    Obj o;
    int u;
    if (EQI(d_1bd6d8, 0)) {
        if (f_0db9a0(d_1c0004) > 1) {
            f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
            u = f_039320(d_1c0004, 0x1c);
            o.b[1] = u;
            f_0bf730(&d_1c2c64, 0x36000021);
            d_1bd6d8 = 1;
            f_1254a0(&o, 0);
        }
    }
}

//@ f_063460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 304: nennt beim ersten Betreten (d_1bd6dc == 0) wie auf
 *   Feld 302 den besten Fährtensucher (Talent 0x1a) in der Meldung 0x36000020 und setzt den eigenen Ortsmerker
 *   d_1bd6dc = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt den registrierten Ortsmerker d_1bd6dc (Kennnummer 0x206).
 === Ende Beschreibung === */
void f_063460()
{
    Obj o;
    int u;
    if (EQI(d_1bd6dc, 0)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        u = f_039320(d_1c0004, 0x1a);
        o.b[1] = u;
        f_0bf730(&d_1c2c64, 0x36000020);
        d_1bd6dc = 1;
        f_1254a0(&o, 0);
    }
}

//@ f_0634d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 305: gibt die Meldung 0x36000022 im Textfenster aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ruft f_0bf730(&d_1c2c64, 0x36000022) auf.
 === Ende Beschreibung === */
void f_0634d0()
{
    f_0bf730(&d_1c2c64, 0x36000022);
}

//@ f_0634f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 401: ruft f_063f40(p1, 15) (environ1) auf, wodurch beim
 *   ersten Mal sicher (d_1bd6e0) und später mit 15 % Wahrscheinlichkeit eine Tierkunde-Begegnung mit Bild
 *   0x2c0001 ausgelöst wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Leitet mit dem Prozentwert 15 (0x0f) an f_063f40 weiter.
 === Ende Beschreibung === */
void f_0634f0(X *p1)
{
    f_063f40(p1, 0xf);
}

//@ f_063500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ausgelagerte Einzelfunktion für Feld 402: zeigt, solange der Kampfmerker d_1bd6e4 noch 0 ist,
 *   die Meldung 0x3600002a an, startet über den Vtable-Slot 0 des Ortsobjekts den Kampf 0x94 und setzt nach
 *   gewonnenem Kampf (fn(p1, 0x94, 0) == 0) den Merker d_1bd6e4 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Ortsobjekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Nutzt den registrierten Ortsmerker d_1bd6e4 (Kennnummer 0x208).
 === Ende Beschreibung === */
void f_063500(X *p1)
{
    if (EQB(d_1bd6e4, 0)) {
        f_0bf730(&d_1c2c64, 0x3600002a);
        if (p1->vt->fn(p1, 0x94, 0) == 0) d_1bd6e4 = 1;
    }
}
