/* === Beschreibung (Katalog) ===
 * Einheit star1_t1 (0x115d80 - 0x116f90)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil der Ereignisbehandlung für die erste Ebene des Bienenstocks
 * (star1.cpp, Dungeon-ID 7). Sie enthält den Haupt-Ereignisverteiler (f_115d80) sowie die Interaktionsfunktionen
 * für die vorderen Kammern, Gänge und Übergänge der Ebene.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 8/10 gleich (suche.py 29.10.2026, Basis star1_t1_P1.CPP)
// star1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x115D80-0x118A10
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int f_0bf730(int p1, int p2);

int f_0bf680(int p1, int p2);
#pragma aux f_0bf680 parm [eax] [edx] modify [eax];
extern int d_1c349c, d_1c3870, d_1c3498, d_1c2c64, d_1c2c44, d_1c2c00;
#define EQI(x,v) (((x)==(v))?1:0)
#define GTI(x,v) (((x)>(v))?1:0)
static inline int EQC(signed char a, signed char b) { return a == b; }
struct Tx { char b[0x13e]; Tx(int a, int b, int c); };
typedef short (*FNV)(int, int, int);
extern signed char d_1c0930, d_1c093c, d_1c0940, d_1c0944, d_1c0948, d_1c094c, d_1c0950, d_1c0954, d_1c0958, d_1c0960, d_1c0978, d_1c0980, d_1c0988, d_1c098c, d_1c0990, d_1c0994, d_1c0998, d_1c09ac, d_1c09b4, d_1c09bc, d_1c09c4, d_1c09e8;
extern volatile unsigned char d_1c09b8; // volatile verhindert das Zusammenfassen von ++d_1c09b8 in den switch-Zweigen von f_115d80
short f_0db9a0(int p1);

int f_0bde40(int p1);
int f_0bfa20(int, ...);
int f_0bf980(int, ...);
int f_0bf820(int, ...);
int f_060740(int p1, int p2);
void f_116670(int p1);
void f_116750(int p1);
void f_1168a0(int p1);
void f_116a20(int p1);
void f_116c00(int p1);
void f_116d60(int p1);
void f_116e40(int p1);
void f_116f90(int p1);
void f_117080(int p1);
void f_117460(int p1, int p2);
void f_117650(int p1);
void f_117930(int p1);
void f_117ad0();
void f_117c60(int p1);
void f_117ed0(int p1);
void f_1180e0(int p1);
void f_1182a0(int p1);
#define MSG(n) f_0bf730((int)&d_1c2c64, n)
#define OBJ RivaTextContext obj(&d_1c349c, &d_1c3870, &d_1c3498)
#define PM(o, k) (*(int *)(obj.slots[k] + (o)))
#define DEL(o) if (o) delete (char *)((int)(((RivaRasterImage*)(o))->f_0fad20( 0)))
int f_0104b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_010590(int p1, int p2);                           // reg eax stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_039580(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_043d70(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0d5ff0();                       // nicht in clobber.tsv
int f_0d64a0();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0dc020(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcd30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_113640(int p1);                                   // reg eax stapel 0
int f_1150b0(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_1155d0(int p1, int p2);                           // reg edx stapel 0
int f_118e50();                                         // reg - stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125e50(int p1, int p2);                           // reg eax edx stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a7c2a;                    // 0x1A7C2A
extern int d_1a7c30;                    // 0x1A7C30
extern int d_1c0004;                    // 0x1C0004
extern int d_1c095c;                    // 0x1C095C
extern int d_1c0964;                    // 0x1C0964
extern int d_1c0968;                    // 0x1C0968
extern int d_1c096c;                    // 0x1C096C
extern int d_1c0970;                    // 0x1C0970
extern int d_1c0974;                    // 0x1C0974
extern int d_1c097c;                    // 0x1C097C
extern int d_1c0984;                    // 0x1C0984
extern int d_1c099c;                    // 0x1C099C
extern int d_1c09a0;                    // 0x1C09A0
extern int d_1c09a8;                    // 0x1C09A8
extern int d_1c09b0;                    // 0x1C09B0
extern int d_1c09c0;                    // 0x1C09C0
extern int d_1c09c8;                    // 0x1C09C8
extern int d_1c219c;                    // 0x1C219C
extern int d_1c21b4;                    // 0x1C21B4
                    // 0x1C2C40
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a7c0c[];           // Text 0x1A7C0C
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_115d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Handler der ersten Bienenstock-Ebene (star1), der beim Betreten von Aktionsfeldern
 *   oder Benutzen von Objekten anhand des Ereigniscodes (p2) die entsprechende Raumroutine, Textmeldung,
 *   Beutetruhe oder einen Ebenenwechsel auslöst.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts und in p2 den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Ereignis verarbeitet wurde, oder 0, falls der Code nicht
 *   behandelt wurde.
 === Ende Beschreibung === */
int actorStar650(int);
#pragma aux actorStar650 "f_1155d0" parm [edx] modify exact [eax edx];
void dispatchStar650(int);
#pragma aux dispatchStar650 "f_117460" parm [edx] modify exact [eax edx];
static inline int compareStar650(const signed char &a,signed char b){return a==b;}

int f_115d80(int p1, unsigned short p2) {
    int r = 1;
    union Command650 { int full; unsigned short word; };
    Command650 command650; command650.word=p2;
    char obj[0xf0];
#define obj_2c1 (obj)
#define obj_2be (obj + 0x3c)
#define obj_12d (obj + 0x78)
#define obj_2bf (obj + 0xb4)
    switch (command650.word) {
    case 0x65:
        f_116670(p1);
        break;
    case 0x66:
        f_116750(p1);
        break;
    case 0x1f41:
        f_1168a0(p1);
        break;
    case 0xca:
        f_116a20(p1);
        break;
    case 0x12d:
        if (compareStar650(d_1c0948, 0)) {
            d_1c0948 = 1;
            f_125400((int)obj_12d, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(*(int *)(obj_12d + 4) + 4) = f_038c40(d_1c0004);
            if (f_0db9a0(d_1c0004) >= 3) {
                *(int *)(*(int *)(obj_12d + 16) + 4) = 0x2e00002d;
            } else {
                *(int *)(*(int *)(obj_12d + 16) + 4) = 0x20000194;
            }
            MSG(0x2e00002e);
            MSG(0x2e00002f);
            MSG(0x2e000030);
            ((int (*)(int, int))f_1254a0)((int)obj_12d, 0);
        }
        break;
    case 0x12e:
        f_116c00(p1);
        break;
    case 0x191:
        f_116d60(p1);
        break;
    case 0x192:
        f_116e40(p1);
        break;
    case 0x1f4:
        f_116f90(p1);
        break;
    case 0x1f5:
        f_117080(p1);
        break;
    case 0x1f6:
        MSG(0x2e000072);
        break;
    case 0x1f7:
        MSG(0x2e000073);
        break;
    case 0x1f9: {
        command650.full = f_1155d0(p1, r);
        if (compareStar650(d_1c09e8, 1) && EQB(d_1c0960, 0) && command650.full) MSG(0x2e00007b);
        break;
    }
    case 0x259:
        if (compareStar650(d_1c0978, 0)) {
            MSG(0x2e00007c);
            d_1c0978 = 1;
        }
        break;
    case 0x25a:
        switch (d_1c09b8) {
        case 0: MSG(0x2e00007d); ++d_1c09b8; break;
        case 1: MSG(0x2e00007c); ++d_1c09b8; break;
        }
        break;
    case 0x25b:
        f_117650(p1);
        break;
    case 0x2bd:
        MSG(0x2e000083);
        break;
    case 0x2be:
        if (compareStar650(d_1c0980, 0)) {
            d_1c0980 = 1;
            f_125400((int)obj_2be, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(*(int *)(obj_2be + 4) + 4) = f_039660(d_1c0004, 10);
            int q = f_0606a0(0x2e0001, 9);
            f_0bde40((int)&d_1c2c64);
            f_0bfa20((int)&d_1c2c64, q, 0, 0x2e000084, 0);
            DEL(q);
            f_0db820(d_1c0004, 300);
            ((int (*)(int, int))f_1254a0)((int)obj_2be, 0);
        }
        break;
    case 0x2bf:
        if (compareStar650(d_1c09b4, 0)) {
            d_1c09b4 = 1;
            f_125400((int)obj_2bf, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            *(int *)(*(int *)(obj_2bf + 4) + 4) = f_038c40(d_1c0004);
            *(int *)(*(int *)(obj_2bf + 4) + 8) = f_039660(d_1c0004, r);
            *(int *)(*(int *)(obj_2bf + 4) + 12) = f_039320(d_1c0004, 0x33);
            MSG(0x2e000085);
            ((int (*)(int, int))f_1254a0)((int)obj_2bf, 0);
        }
        f_0603b0(0x69);
        break;
    case 0x2c0:
        f_117930(p1);
        break;
    case 0x2c1:
        if (EQB(d_1c0988, 0)) {
            f_125400((int)obj_2c1, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            int q = f_039ac0(d_1c0004, (int)f_117ad0);
            if (!q) q = f_0396f0(d_1c0004, 6);
            *(int *)(*(int *)(obj_2c1 + 4) + 4) = q;
            MSG(0x2e00008c);
            d_1c0988 = 1;
            ((int (*)(int, int))f_1254a0)((int)obj_2c1, 0);
        }
        break;
    case 0x2c2:
        if (EQB(d_1c098c, 0)) {
            int q = f_0606a0(0x2e0001, 10);
            f_0bf6c0((int)&d_1c2c64, 5);
            f_0bde40((int)&d_1c2c64);
            f_0bfa20((int)&d_1c2c64, q, 0, 0x2e00008d, 0);
            ((int (*)(int))f_0bf680)((int)&d_1c2c64);
            DEL(q);
            d_1c098c = 1;
        }
        break;
    case 0x2c3:
        if (EQB(d_1c0990, 0)) {
            d_1c0990 = 1;
            MSG(0x2e00008e);
        }
        break;
    case 0x1f42:
        f_117c60(p1);
        break;
    case 0x2c5:
        f_117ed0(p1);
        break;
    case 0x2c6:
        if (EQB(d_1c0998, 0)) {
            d_1c0998 = 1;
            int q = (int)new (mark(d_1a7c0c, 0x6a0)) Tx(0x2c0012, 0, 0);
            f_0bf980((int)&d_1c2c64, q, 0, 0x2e0000a1, 0);
            if (q) delete (char *)f_010590(q, 0);
        }
        break;
    case 0x2c7:
        f_1180e0(p1);
        break;
    case 0x2c8:
        if (EQI(d_1c0994, 0) && EQI(d_1c0958, r)) {
            int q = (int)new (mark(d_1a7c0c, 0x6de)) Tx(0x2c0011, 0, 0);
            f_0bf980((int)&d_1c2c64, q, 0, 0x2e0000a3, 0);
            if (q) delete (char *)f_010590(q, 0);
            d_1c0994 = 1;
        }
        break;
    case 0x2c9:
        MSG(0x2e0000a4);
        break;
    case 0x3e8:
    case 0x3e9:
    case 0x3ea:
    case 0x3eb:
    case 0x3ec:
    case 0x3ed:
        f_117460(p1, (short)command650.word * 2 + 0x2df833);
        break;
    default:
        r = 0;
        break;
    }
    return r;
#undef obj_2c1
#undef obj_2be
#undef obj_12d
#undef obj_2bf
}
//@ f_116670
/* === Beschreibung (Katalog) ===
 * - Zweck: Spielt beim allerersten Betreten der ersten Bienenstock-Ebene (d_1c09bc == 0, Ereignis 0x65 bzw.
 *   f_115d60) die Eingangssequenz ab: Ein Held mit passender Sinnesschärfe (f_039420(..., 0x0e)) bemerkt die
 *   Umgebung (0x2e000020), das Bild 0x10 aus 0x2e0001 wird mit Text 0x2e000021 eingeblendet, der Tagebucheintrag
 *   0x8030035 (f_057220) vermerkt und d_1c09bc = 1 gesetzt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09bc (Einmal-Flag für die Eingangssequenz), o (geladenes Bildobjekt).
 === Ende Beschreibung === */
void f_116670(int p1) {
    if (EQB(d_1c09bc, 0)) {
        OBJ;
        int o;
        PM(4, 0) = f_039420(d_1c0004, 0xe);
        MSG(0x2e000020);
        f_0bf6c0((int)&d_1c2c64, 5);
        o = f_0606a0(0x2e0001, 0x10);
        f_0bde40((int)&d_1c2c64);
        f_0bfa20((int)&d_1c2c64, o, 0, 0x2e000021, 0);
        DEL(o);
        ((int (*)(int))f_0bf680)((int)&d_1c2c64);
        f_057220((int)&d_1c2c00, 0x8030035, 0);
        d_1c09bc = 1;
    }
}
//@ f_116750
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt das einmalige Ereignis 0x66 (d_1c09ac == 0): Die Funktion zeigt Bild 2 aus 0x2e0001 mit der
 *   Meldung 0x2e000022 an und schaltet, sofern das Kartenobjekt 0x39 noch nicht im Zustand 2 steht, dessen
 *   Status über f_0697c0 um, legt den Tagebucheintrag 0x8030036 an und gibt mit einem per Talentprobe 0x22
 *   (f_039320) bestimmten Helden die Meldung 0x2e000025 aus.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c09ac (Besuchsflag), o (Bildobjekt).
 === Ende Beschreibung === */
void f_116750(int p1) {
    if (EQB(d_1c09ac, 0)) {
        int o;
        d_1c09ac = 1;
        o = f_0606a0(0x2e0001, 2);
        f_0bde40((int)&d_1c2c64);
        f_0bfa20((int)&d_1c2c64, o, 0, 0x2e000022, 0);
        DEL(o);
        FNV *vt = *(FNV **)(p1 + 8);
        if (vt[0](p1, 0x39, 0) != 2) {
            f_0697c0(p1 + 2, 0x39, 0);
            f_060a70();
            f_057220((int)&d_1c2c00, 0x8030036, 0);
            OBJ;
            int v = (f_0db9a0(d_1c0004) <= 1) + 0x2e000023;
            PM(4, 3) = v;
            PM(4, 0) = f_039320(d_1c0004, 0x22);
            MSG(0x2e000025);
        }
    }
}
//@ f_116870
/* === Beschreibung (Katalog) ===
 * - Zweck: Rundet eine Gegneranzahl p1 für die Textanzeige auf ein Vielfaches von 5 ab ((p1 / 5) * 5), liefert
 *   jedoch bei positiven Kleinstmengen (p1 / 5 == 0) mindestens 5 zurück.
 * - Eingaben: p1 (tatsächliche Anzahl der Wächter-Insekten).
 * - Rückgabewert: Gerundete Schätzzahl (short, mindestens 5).
 * - Wichtige Variablen: q ((short)p1 / 5).
 === Ende Beschreibung === */
short f_116870(int p1) {
    short q = (short)p1 / 5;
    if (q == 0) q = 1;
    return q * 5;
}
//@ f_1168a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt den Kampf gegen den Wächter-Schwarm d_1c0930 am Durchgang 0x1f41: Solange d_1c0930 > 0 ist,
 *   wird die auf Vielfache von 5 gerundete Schwarmgröße im Rückfragedialog 0x2e000026 angezeigt; greift der
 *   Spieler an, wird ein Kampfbild (0x0d oder 0x0e aus 0x2e0001) mit Text 0x2e000027 eingeblendet, die
 *   Kampfrunde über f_1150b0 berechnet und bei vollständig besiegtem Schwarm (d_1c0930 == 0) der Durchgang
 *   0x1f41/0x1f43 über f_060740 freigegeben sowie 5 AP (f_0dcbb0) vergeben.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0930 (verbleibende Wächter am Durchgang 0x1f41), v (gerundete Anzahl für den
 *   Dialog).
 === Ende Beschreibung === */
void f_1168a0(int p1) {
    if (GTI(d_1c0930, 0)) {
        OBJ;
        signed char c = d_1c0930;
        short q = (short)c / 5;
        if (q == 0) q = 1;
        short v = q * 5;
        *(short *)(obj.slots[4] + 2) = v;
        if (f_0bf6f0((int)&d_1c2c64, 0x2e000026) == 1) {
            int o;
            PM(4, 0) = f_038c40(d_1c0004);
            o = f_0606a0(0x2e0001, (short)((((signed char)f_042380((struct hero *)(f_038c40(d_1c0004))) != 1) ? 1 : 0) + 0xd));
            f_0bde40((int)&d_1c2c64);
            f_0bfa20((int)&d_1c2c64, o, 0, 0x2e000027, 0);
            DEL(o);
            f_1150b0(p1, f_038c40(d_1c0004), (int)&d_1c0930);
            if (EQI(d_1c0930, 0)) {
                f_060740(0x1f41, 1);
                f_060740(0x1f43, 1);
                f_0dcbb0(d_1c0004, 5);
                f_091f70(0x30);
                f_040780(f_038c40(d_1c0004), 10);
            }
        }
    }
}
//@ f_116a20
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert den Übergang am Schacht/Durchgang 0xca: Ist das Ereignis d_1c093c noch nicht ausgelöst, wird
 *   lediglich d_1c0940 = 1 vermerkt; andernfalls gibt die Funktion 0x2e000029 bzw. 0x2e00002a aus, fragt über
 *   0x2e00002b, ob die Gruppe hinabsteigen will, und versetzt sie bei Bestätigung in die Königinnen-Ebene
 *   (Dungeon 9, Position 0x1396 über f_0dd7f0).
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c093c, d_1c0940, d_1c0944 (Fortschrittsflags).
 === Ende Beschreibung === */
void f_116a20(int p1) {
    OBJ;
    if (EQI(d_1c093c, 0)) {
        d_1c0940 = 1;
    } else {
        if (f_0db9a0(d_1c0004) == 1) PM(4, 3) = 0x20000194;
        else PM(4, 3) = 0x2e000028;
        PM(4, 0) = f_039660(d_1c0004, 1);
        if (EQI(d_1c0940, 0)) MSG(0x2e000029);
        else MSG(0x2e00002a);
        if (f_0bf6f0((int)&d_1c2c64, 0x2e00002b) == 1) {
            if (EQI(d_1c0944, 0)) {
                d_1c0944 = 1;
                f_091f70(0x34);
            }
            f_0dd7f0(d_1c0004, 9, 0x1396);
            return;
        }
        MSG(0x2e00002c);
    }
}
//@ f_116b40
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Auslösen (d_1c0948 == 0, entsprechend Ereignis 0x12d) für den Gruppenanführer
 *   (f_038c40) abhängig von der Gruppengröße (>= 3 Helden: 0x2e00002d, sonst 0x20000194) die dreiteilige
 *   Textsequenz 0x2e00002e, 0x2e00002f und 0x2e000030 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0948 (Einmal-Flag).
 === Ende Beschreibung === */
void f_116b40() {
    if (EQI(d_1c0948, 0)) {
        d_1c0948 = 1;
        OBJ;
        PM(4, 0) = f_038c40(d_1c0004);
        if (f_0db9a0(d_1c0004) >= 3) PM(4, 3) = 0x2e00002d;
        else PM(4, 3) = 0x20000194;
        MSG(0x2e00002e);
        MSG(0x2e00002f);
        MSG(0x2e000030);
    }
}
//@ f_116c00
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt beim ersten Betreten eines Raumabschnitts eine einmalige Beschreibungsmeldung (0x2e000072) aus
 *   und setzt das zugehörige Besuchsflag (d_1c09c0).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_116c00(int p1) {
    if (EQI(d_1c093c, 0) && EQI(d_1c0954, 1)) {
        OBJ;
        int t, m;
        if (f_0db9a0(d_1c0004) == 1) PM(4, 3) = 0x20000194;
        else PM(4, 3) = 0x2e000031;
int v=f_039660(d_1c0004,5);int *q=(int *)obj.slots[0];q[1]=v;
        int o = f_0606a0(0x2e0001, 3);
        f_0bfa20((int)&d_1c2c64, o, 0, 0x2e000032, 0);
        DEL(o);
        t = f_1155d0(p1, 1);
if(t!=0){PM(4,0)=t;f_0bf730((int)&d_1c2c64,0x2e000033);}else f_0bf730((int)&d_1c2c64,0x2e000034);
        o = f_0606a0(0x2e0001, 4);
        f_0bfa20((int)&d_1c2c64, o, 0, 0x2e000035, 0);
        DEL(o);
        f_125e50((int)&d_1c2c44, 900);
        d_1c093c = 1;
    }
}
//@ f_116d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Behandelt die zweistufige Untersuchung am Ereignispunkt 0x191 (d_1c0950): Beim ersten Mal (d_1c0950
 *   == 0) wird d_1c0950 = 1 gesetzt und 0x2e000036 mit Teiltext 0x2e000037/0x2e000038 ausgegeben; beim zweiten
 *   Mal (d_1c0950 == 1) wird d_1c0950 = 2 gesetzt, 0x2e000036 mit Teiltext 0x2e000039 angezeigt und die
 *   Spielzeit um 5 Minuten (f_125ed0) vorgerückt.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0950 (Zustandszähler 0 -> 1 -> 2).
 === Ende Beschreibung === */
void f_116d60(int p1) {
    OBJ;
    PM(4, 0) = f_038c40(d_1c0004);
    if (EQI(d_1c0950, 0)) {
        d_1c0950 = 1;
        unsigned char b = f_0db9a0(d_1c0004) != 1;
        PM(4, 3) = b + 0x2e000037;
    } else {
        if (!EQI(d_1c0950, 1)) goto L;
        d_1c0950 = 2;
        PM(4, 3) = 0x2e000039;
        f_125ed0((int)&d_1c2c44, 5);
    }
    MSG(0x2e000036);
L: ;
}
//@ f_116e40
/* === Beschreibung (Katalog) ===
 * - Zweck: Steuert den Übergang zur zweiten Bienenstock-Ebene am Ereignis 0x192 (d_1c094c): Beim ersten Betreten
 *   (d_1c094c == 0) bietet das Auswahlmenü 0x2e00003a drei Optionen (Rückzug, Ausführen von f_1182a0(p1) oder
 *   Hinabsteigen über 0x2e000041/0x2e000042 mit 5 Schadenspunkten und Wechsel nach Dungeon 8, Position 0x13a3
 *   über f_0dd7f0 und f_118e50); bei späteren Besuchen fragt 0x2e000043 direkt nach dem Ebenenwechsel.
 * - Eingaben: p1 (Zeiger auf das Dungeon-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c094c, d_1c09c4 (Zustandsflags für den Übergang nach Ebene 2).
 === Ende Beschreibung === */
void f_116e40(int p1) {
    OBJ;
    if (EQI(d_1c094c, 0)) goto choose;
    if (f_0bf6f0((int)&d_1c2c64, 0x2e000043) == 1) {
        f_0dd7f0(d_1c0004, 8, 0x13a3);
        f_118e50();
    }
done:
    return;
chosen2:
    f_1182a0(p1);
    goto done;
chosen3:
    if (f_0bf6f0((int)&d_1c2c64, 0x2e000041) != 1) goto done;
    {
        int t = f_039660(d_1c0004, 0);
        PM(4, 0) = t;
        MSG(0x2e000042);
        f_040780(t, 5);
        d_1c09c4 = 1;
        f_0dd7f0(d_1c0004, 8, 0x13a3);
        f_118e50();
    }
    return;
choose:
    d_1c094c = 1;
    switch ((unsigned short)(f_0bf820((int)&d_1c2c64, 0x2e00003a, 3, 0x2e00003b, 0x2e00003c, 0x2e00003d) + 1)) {
    case 0: case 1: case 4: goto done;
    case 2: goto chosen2;
    case 3: goto chosen3;
    default: goto done;
    }
}
