/* === Beschreibung (Katalog) ===
 * Einheit gz_0222d0_mod1 (0x000222d0 - 0x00022960)
 *
 * Überblick
 *
 * Die Einheit gz_0222d0_mod1 bildet das erste Modul eines kleineren Schauplatzes (vermutlich der Borontempel
 * oder die Vorhalle des Friedhofsgewölbes), das eigene Dialogtexte lädt, Ortsübergänge verwaltet und mehrere
 * Ereignispunkte sowie Gesprächs- oder Segensoptionen bereitstellt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/11 gleich (suche.py 28.10.2026, Basis gz_0222d0_P1.CPP)
// gz_0222d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0222D0-0x022980
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_0600f0(int p1, int p2);                           // reg edx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a9820;                    // 0x1A9820
extern int d_1bab3c;
extern int d_1bab94;                    // 0x1BAB3C
extern signed char d_1bc76c;                    // 0x1BC76C
extern signed char d_1bc77c;                    // 0x1BC77C
extern signed char d_1bc780;                    // 0x1BC780
extern signed char d_1bc788;                    // 0x1BC788
extern signed char d_1bc78c;                    // 0x1BC78C
extern unsigned char d_1bc7f4;                    // 0x1BC7F4
extern signed char d_1bc800;                    // 0x1BC800
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c44;                    // 0x1C2C44
extern short d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern char d_1c3498[];
extern char d_1c349c[];                    // 0x1C349C
extern char d_1c3870[];                    // 0x1C3870
void f_021180();
void f_021190();
int f_145234(int p, int d);
int f_145254();

static inline int EQ(int x, int v) { return x == v; }
#define KV(ok) 0
struct Cell { long a; long b; long c; };
typedef RivaTextContextData Msg;
struct Msg3 { int h; int *n; int pad[4]; int *q; int rest[8]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CX3(m) Msg3 m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define F1(m) (m).tables.p[1]
#define F2(m) (m).tables.p[2]
#define F6(m) (m).q[1]
#define A(x) ((int)&(x))

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0222d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt am Schauplatz ein Gespräch oder eine Ortsuntersuchung über das Textfenster durch, fragt
 *   die Entscheidung des Spielers ab und setzt je nach gewählter Antwort den entsprechenden Fortschrittsmerker.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der lokale Textpuffer d_1bc7b4, der Gruppenanführer d_1c0004 und die
 *   Statusmerker ab d_1bc7a0.
 === Ende Beschreibung === */
void f_0222d0(int p1)
{
    if (EQ(d_1bc76c, 1)) {
        if (EQ(d_1bc780, 0)) {
            d_1bc780 = 1;
            if (EQ(d_1bc78c, 0)) {
                if (EQ(d_1bc788, 1)) f_0bf730(A(d_1c2c64), 0x2400002b); else f_0bf730(A(d_1c2c64), 0x2400002c);
                f_0600f0(p1, 0x15000a);
                d_1bc788 = 1;
                f_060a70();
                f_0bf730(A(d_1c2c64), 0x2400002d);
            } else {
                CX(m);
                if (f_0db9a0(d_1c0004) > 1) {
                    int a = f_038c40(d_1c0004);
                    F1(m) = f_039b70(d_1c0004, a, 6);
                    F2(m) = a;
                    f_0bf730(A(d_1c2c64), 0x2400002e);
                } else {
                    F1(m) = f_039660(d_1c0004, 6);
                    f_0bf730(A(d_1c2c64), 0x2400002f);
                }
                CXEND(m);
            }
            (**(void (***)(int, int, int))(p1 + 8))(p1, 0x1e, 0);
            f_0697c0(p1 + 2, 0x1e, 0);
            return;
        }
        f_125ed0(A(d_1c2c44), 10);
        f_0bf730(A(d_1c2c64), 0x24000030);
        return;
    }
    if (EQ(d_1bc76c, 0)) {
        f_0bf730(A(d_1c2c64), 0x24000031);
    }
}

//@ f_022480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Verlassen des Bereichs den angeforderten Textpuffer wieder frei.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben wird der globale Zeiger d_1bc7b4.
 === Ende Beschreibung === */
void f_022480(int p1)
{
    if (f_0d4a60(p1)) f_044090(p1, 0x1fa40, 2);
}

//@ f_0224b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert eine umfangreichere Begegnung oder Untersuchung in diesem Bereich, wertet bisherige
 *   Fortschrittsflags aus und vergibt bei erfüllten Bedingungen Hinweise oder Gegenstände.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden der Textpuffer d_1bc7b4 sowie die Ortsflags im Bereich d_1bc7a0-d_1bc7b0.
 === Ende Beschreibung === */
#pragma aux f_147323 modify [esp];
#pragma aux f_091f70 modify exact [eax];
void f_0224b0()
{
    CX(m);
    if (EQB(d_1bc76c, 1)) {
        int ok = 0;
        if (EQB(d_1bc77c, 0)) {
            d_1bc77c = 1;
            f_125ed0(A(d_1c2c44), 0xf);
            ((int *)m.tables.p)[1] = f_039320(d_1c0004, 0x33);
            f_0bf6c0(A(d_1c2c64), 5);
            f_0bf730(A(d_1c2c64), 0x24000032);
            f_0bf680(A(d_1c2c64));
            if (f_0d54f0(d_1c0004, 0x49) != -1) {
                ((int *)m.tables.p)[1] = f_038c40(d_1c0004);
                int snd = *(int *)&d_1a9820;
                f_147323(A(d_1c2edc), 0x240004, 0x7fff, 0x8000, snd, KV(ok), 1);
                f_0bf730(A(d_1c2c64), 0x24000033);
            } else {
                f_125ed0(A(d_1c2c44), 0xf);
                int snd = *(int *)&d_1a9820;
                f_147323(A(d_1c2edc), 0x240005, 0x7fff, 0x8000, snd, KV(ok), 1);
                f_0bf730(A(d_1c2c64), 0x24000034);
                f_039a80(d_1c0004, (int)f_021180);
                f_039a80(d_1c0004, (int)f_022480);
                f_039a80(d_1c0004, (int)f_021190);
            }
            f_060740(0x1f41, 1);
            f_060740(0x1f43, 1);
            f_0607e0(0x1f41, 1);
            f_091f70(0xb);
            F1(m) = f_039660(d_1c0004, 4);
            if (f_0bf6f0(A(d_1c2c64), 0x24000035) == 1) {
                f_0dcbb0(d_1c0004, 10);
                ok = 1;
            }
        } else {
            int msg = (f_0db9a0(d_1c0004) <= 1) ? 0x24000037 : 0x24000036;
            F1(m) = f_0396f0(d_1c0004, 0);
            if (f_0bf6f0(A(d_1c2c64), msg) == 1) ok = 1;
        }
        if (ok == 1) f_0dd7f0(d_1c0004, 0xe, 0x13a3);
    } else if (EQ((signed char)d_1bc7f4, 0)) {
        CX(m2);
        ((int *)m2.tables.p)[1] = f_038c40(d_1c0004);
        f_0bf730(A(d_1c2c64), 0x24000008);
        d_1bc7f4 = 1;
        CXEND(m2);
    }
    CXEND(m);
}

//@ f_022760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim Betreten des Schauplatzes die zugehörige Textressource in den Speicher und bereitet
 *   die Ereignisbehandlung vor.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Initialisiert wird der Textpufferzeiger d_1bc7b4.
 === Ende Beschreibung === */
void f_022760()
{
    if (EQ(d_1bc800, 0)) {
        d_1bc800 = 1;
        f_0bf730(A(d_1c2c64), 0x24000038);
    }
}

//@ f_022790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verzweigt anhand der betretenen Ereignisfeldnummer auf die zugehörige Szenenfunktion innerhalb
 *   dieser Einheit.
 * - Eingaben und Rückgabe: Die Funktion erhält die Nummer des Ereignisfeldes als Parameter und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Verglichen wird die übergebene Feldnummer mit den unterstützten Ereignis-IDs des Orts.
 === Ende Beschreibung === */
void f_022790()
{
    if (EQ(d_1bc800, 0)) {
        d_1bc800 = 1;
        f_0bf730(A(d_1c2c64), 0x24000038);
    }
}
//@ f_0227c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen einzelnen Fortschrittsmerker dieses Schauplatzes aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den Wert des Statusbytes zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte im Bereich d_1bc7a0-d_1bc7b0.
 === Ende Beschreibung === */
void f_0227c0()
{
}


//@ f_0227d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Gruppe einen Durchgang passieren darf, gibt gegebenenfalls einen Hinweistext aus
 *   und löst den Ortswechsel aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden der Textpuffer d_1bc7b4 und der Öffnungsstatus des Durchgangs.
 === Ende Beschreibung === */
unsigned short f_0227d0()
{
    int n;
    short r = 0;
    CX3(m);
    n = f_0de7e0(d_1c0004) / 10;
    if (n > 0) {
        short a = 0;
        int b = 0;
        a = (n > 999) ? 999 : (short)n;
        b = a;
        if (b > (short)100) b = 100;
        F6(m) = n;
        r = f_0bf7b0(A(d_1c2c64), 3, 0x24000016, r, a, (short)b);
        if (r < 0) r = 0;
    } else {
        f_0bf730(A(d_1c2c64), 0x24000015);
    }
    CXEND(m);
    return r;
}

//@ f_022880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Markiert ein Teilereignis des Schauplatzes als erledigt, indem das zugehörige Flag gesetzt
 *   wird.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter (oder den neuen Zustandswert) und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Beschrieben wird ein Statusbyte im Bereich d_1bc7a0-d_1bc7b0.
 === Ende Beschreibung === */
int f_022880()
{
    int r = f_0dd3a0(d_1c0004, 6, 0);
    if (r == 0) r = f_039320(d_1c0004, 0x25);
    return r;
}

//@ f_0228b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim Betreten eines Hinweisfeldes eine Textmeldung aus dem geladenen Ortspuffer an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt wird der Textpuffer d_1bc7b4 zusammen mit der Dialogfunktion f_056000.
 === Ende Beschreibung === */
int f_0228b0(int p1)
{
    int p = f_038c80(d_1c0004);
    int b = 0;
    do {
        if (f_0d4a60(p) == 1 && f_042350((struct hero *)(p)) != 6 && p != p1) b = p;
        if (b == 0) p = f_0391b0(d_1c0004, p);
    } while (b == 0 && p != f_038c80(d_1c0004));
    return b;
}

//@ f_022950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zustand eines weiteren Ortsflags zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert den Flagwert als Ganzzahl.
 * - Wichtige Variablen: Gelesen wird ein Statusbyte im Bereich d_1bc7a0-d_1bc7b0.
 === Ende Beschreibung === */
inline int f_022950() { return 0; }
//@ f_022910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt beim Programmstart die persistenten Flags dieses Schauplatzes in die globale
 *   Spielstand-Tabelle ein, damit sie beim Speichern und Laden erhalten bleiben.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Kopiert werden die Adressen und Kennungen der Ortsmerker ab d_1bc7a0 in das globale
 *   Register d_1c212a.
 === Ende Beschreibung === */
int f_022910(int p1, unsigned fl)
{
    if (fl & 4) {
        f_145234(p1, A(d_1bab3c));
        f_145254();
        return p1;
    }
    int r = f_060030(p1, 1);
    if (fl & 2) delete (void *)r;
    (void)f_022950;
    return r;
}


