/* === Beschreibung (Katalog) ===
 * Einheit castle_t2 (0x0002b520 - 0x0002c7c0)
 *
 * Überblick
 *
 * Die Einheit castle_t2 bildet den zweiten Teil der Orts- und Dungeon-Logik für die Festung / Burg von Riva
 * (CASTLE.CPP). Sie enthält zahlreiche Raum-, Kerker-, Tür- und Dialogszenen innerhalb der Burg, darunter Rast-
 * und Zeitprüfungen, Kampfauslöser gegen Wachen, das Durchsuchen von Truhen und Regalen, ein magisches oder
 * göttliches Heilungsereignis sowie eine Geld-Aufbewahrungs- beziehungsweise Wettkasse (d_1bc880).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 43/43 gleich (suche.py 29.10.2026, Basis castle_t2_P1.CPP)
// F4 Stand (Basis p3 CASTLE_T2_P1.CPP)
// castle.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0286D0-0x02D9C0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0398c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_060360(int p1);                                   // reg eax stapel 0
unsigned short f_0603b0(int p1);                                   // reg eax stapel 0
int f_060770(int p1, int p2);                           // reg eax edx stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_069770(int p1, int p2);                           // reg eax edx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd1d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
int f_0de830(int p1, int p2);                           // reg eax edx stapel 0
int f_0de850(int p1, int p2);                           // reg eax edx stapel 0
int f_0de890(int p1, int p2);                           // reg eax edx stapel 0
int f_0de8d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de930(int p1, int p2);                           // reg eax edx stapel 0
int f_10b890(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149640(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a06a8;                    // 0x1A06A8
extern short d_1a06aa;                  // 0x1A06AA
extern short d_1a06ac;                  // 0x1A06AC
extern short d_1a06ae;                  // 0x1A06AE
extern short d_1a06b0;                  // 0x1A06B0
extern int d_1a9820;                    // 0x1A9820
extern int d_1bc81c;                    // 0x1BC81C
extern signed char d_1bc81d;
extern int d_1bc820;                    // 0x1BC820
extern int d_1bc824;                    // 0x1BC824
extern int d_1bc828;                    // 0x1BC828
extern int d_1bc82c;                    // 0x1BC82C
extern int d_1bc830;                    // 0x1BC830
extern signed char d_1bc834;
extern signed char d_1bc838;
extern signed char d_1bc83c;
extern signed char d_1bc840;
extern signed char d_1bc848;
extern signed char d_1bc84c;
extern signed char d_1bc850;
extern signed char d_1bc854;
extern int d_1bc858;                    // 0x1BC858
extern int d_1bc85c;                    // 0x1BC85C
extern signed char d_1bc860;
extern signed char d_1bc864;
extern signed char d_1bc868;
extern signed char d_1bc86c;
extern int d_1bc870;                    // 0x1BC870
extern int d_1bc874;                    // 0x1BC874
extern int d_1bc878;                    // 0x1BC878
extern int d_1bc87c;                    // 0x1BC87C
extern short d_1bc880;
extern signed char d_1bc884;
extern signed char d_1bc888;
extern int d_1bd91c;                    // 0x1BD91C
extern short d_1bd922;
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c01e8;
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a06f0[];           // Text 0x1A06F0
// --- eigene Funktionen (92), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---



short f_0d54f0(int p1, int p2);
short f_0de480(int p1, int p2);
short f_044900(int p1, int p2, int p3);
short f_0db9a0(int p1);
int f_126410(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_060740(int p1, int p2);
int f_0f2720(int p1, int p2, int p3, int p4);
int f_125dc0(int p1, int p2);
#define EQ(x,v) (((x)==(v))?1:0)
#define GT(x,v) (((x)>(v))?1:0)
static inline int EQI(int x, int v) { return x == v; }
#define A(x) ((int)&(x))
typedef short FNX(int, int, int);
#define VC(p, a) ((*(FNX **)*(int *)((p) + 8))((p), (a), 0))
struct Msg { int h; int *n; int x[2]; int *s; short *t; int pad[9]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
struct MsgO {
    int f_0bf730(long code);
    int f_0bf6f0(long code);
    void f_0bf6c0(int k);
    void f_0bf680();
    void f_0bde40();
    short f_0bfa20(...);
    short f_0bf7b0(int a, int b, int c, int d, int e);
};
extern MsgO d_1c2c64;
short f_0bf820(MsgO *o, ...);
int g_0bf820(MsgO *o, ...);
#pragma aux g_0bf820 "f_0bf820";
struct Obj5f { char b[12]; Obj5f(int k, int id); ~Obj5f(); void f_05f280(int z); void f_05f470(); void f_05f480(); void f_05f4f0(int z); int f_05f560(); int f_05f580(); void f_05f5a0(int z); void f_05f6e0(int z); };
struct Obj112 { char b[20]; Obj112(int a, int b, int c); ~Obj112(); void f_112ec0(); int f_1131b0(); };
struct T9 { char b[9]; ~T9(); };
T9 *f_0606a0(int a, int b);

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_02b520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft innerhalb der Burg die aktuelle Tageszeit (f_126410): Liegt sie zwischen 0x7e90 (09:00
 *   Uhr) und 0x1a5e0 (20:00 Uhr), wird der Spieler gefragt (0x33000019), ob bis zum Abend gewartet werden soll,
 *   woraufhin die Uhrzeit auf 0x1a5e0 vorgespult wird. Anschließend wird eine Zwischensequenz (0x330002) mit dem
 *   Grafikobjekt 0x1f65 abgespielt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden die Spieluhr d_1c2c44, das Textsystem d_1c2c64 und das Szene-Objekt
 *   Obj5f(0, 0x1f65).
 === Ende Beschreibung === */
void f_02b520()
{
    int ok = 1;
    if (f_126410(A(d_1c2c44)) < 0x1a5e0) {
        if (f_126410(A(d_1c2c44)) > 0x7e90) {
            if (d_1c2c64.f_0bf6f0(0x33000019) == 1) {
                f_125dc0(A(d_1c2c44), 0x1a5e0);
            } else {
                ok = 0;
            }
        }
    }
    if (ok == 1) {
        Obj5f *o = new (mark(d_1a06f0, 0x463)) Obj5f(0, 0x1f65);
        o->f_05f6e0(0);
        f_060800(0x330002, 1, 0);
        o->f_05f5a0(0);
        delete o;
    }
}

//@ f_02b5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt in der Burg von Riva die animierte Szene 0x330004 unter Verwendung des Grafikobjekts
 *   0x1f65 ab.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Erzeugt temporär ein Obj5f(0, 0x1f65) und ruft f_060800(0x33000c / 0x330004, 1, 0) auf.
 === Ende Beschreibung === */
void f_02b5e0()
{
    Obj5f *o = new (mark(d_1a06f0, 0x489)) Obj5f(0, 0x1f65);
    o->f_05f6e0(0);
    f_060800(0x330004, 1, 0);
    o->f_05f5a0(0);
    delete o;
}

//@ f_02b650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Teilereignis d_1bc860 aktiv und d_1bc840 noch unerledigt ist. Je nach Status von
 *   d_1bc864 und dem Besitz der Gegenstände 0x189 beziehungsweise 0x187 im Gruppeninventar werden Dialogtexte
 *   (0x3300001a-0x3300001e) angezeigt, die Gegenstände 0x187 aus dem Inventar entfernt, 100 Abenteuerpunkte
 *   (0x64) sowie ein Tagebucheintrag (0x1b) vergeben und die Szene 0x33000c abgespielt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft und gesetzt werden die Burgflags d_1bc840, d_1bc860, d_1bc864, d_1bc86c, das
 *   globale Statusbyte d_1c01e8 sowie der Gruppenanführer d_1c0004.
 === Ende Beschreibung === */
void f_02b650()
{
    if (EQ(d_1bc840, 0) && EQ(d_1bc860, 1)) {
        if (EQ(d_1bc864, 0)) {
            short s;
            d_1c2c64.f_0bf6c0(6);
            s = f_0d54f0(d_1c0004, 0x189);
            if (s != -1) d_1c2c64.f_0bf730(0x3300001a); else d_1c2c64.f_0bf730(0x3300001b);
            d_1c2c64.f_0bf680();
            Obj5f *o = new (mark(d_1a06f0, 0x4c0)) Obj5f(0, 0x1f65);
            o->f_05f6e0(0);
            f_060800(0x33000c, 1, 0);
            o->f_05f5a0(0);
            delete o;
        } else {
            short s;
            s = f_0de480(d_1c0004, 0x187);
            if (s == 3) {
                int r;
                do {
                    r = f_0dd1d0(d_1c0004, 0x187);
                } while (r == 1);
                d_1bc840 = 1;
                d_1c01e8 = 1;
                d_1c2c64.f_0bf730(0x3300001c);
                f_0dcbb0(d_1c0004, 0x64);
                f_091f70(0x1b);
                f_0dd7f0(d_1c0004, 2, 0x5a);
                f_0de810(d_1c0004, 0x66);
                return;
            }
            d_1c2c64.f_0bf6c0(6);
            if (EQ(d_1bc86c, 1)) d_1c2c64.f_0bf730(0x3300001d); else d_1c2c64.f_0bf730(0x3300001e);
            d_1c2c64.f_0bf680();
            Obj5f *o = new (mark(d_1a06f0, 0x4ff)) Obj5f(0, 0x1f65);
            o->f_05f6e0(0);
            f_060800(0x33000c, 1, 0);
            o->f_05f5a0(0);
            delete o;
        }
    }
}

//@ f_02b880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Auslösen die Meldung 0x3300001f (beim wiederholten Mal 0x33000020) aus, setzt
 *   die Kampfparameter d_1bd91c = 1 und d_1bd922 = 5 und startet über die virtuelle Methode 0x0b des
 *   Dungeon-Objekts p1 den Kampf. Bei erfolgreichem Ausgang wird d_1bc888 = 1 gesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Merker d_1bc888 sowie die Kampfsteuervariablen d_1bd91c und
 *   d_1bd922.
 === Ende Beschreibung === */
void f_02b880(int p1)
{
    if (EQ(d_1bc888, 0)) {
        short s;
        d_1bd91c = 1;
        d_1c2c64.f_0bf730(0x3300001f);
        d_1bd922 = 5;
        s = VC(p1, 0xb);
        if (s == 0) {
            d_1bc888 = 1;
            return;
        }
    } else {
        d_1bd91c = 1;
        d_1c2c64.f_0bf730(0x33000020);
        VC(p1, 0xb);
    }
}

//@ f_02b910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler beim ersten Besuch (d_1bc854 == 0) über Text 0x33000021, ob er den
 *   gefundenen Gegenstand mitnehmen möchte, übergibt bei Bestätigung ein Exemplar von Gegenstand 0x1ce an die
 *   Gruppe und gibt bei späteren Besuchen nur noch Text 0x33000022 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden das Einmal-Flag d_1bc854, die Gegenstandsübergabe f_0dcf00 und d_1c0004.
 === Ende Beschreibung === */
void f_02b910()
{
    if (EQ(d_1bc854, 0)) {
        if (d_1c2c64.f_0bf6f0(0x33000021) == 1) {
            f_0dcf00(d_1c0004, 0x1ce, 1);
            d_1bc854 = 1;
            return;
        }
    } else {
        d_1c2c64.f_0bf730(0x33000022);
    }
}

//@ f_02b970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt, sofern das Flag d_1bc84c noch 0 ist, die virtuelle Aktion 0x0c des Burg-Objekts p1 aus
 *   und setzt bei Erfolg (Rückgabe == 0) das Flag d_1bc84c = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft und gesetzt wird das Statusbyte d_1bc84c.
 === Ende Beschreibung === */
void f_02b970(int p1)
{
    if (EQB(d_1bc84c, 0)) {
        if (VC(p1, 0xc) == 0) d_1bc84c = 1;
    }
}

//@ f_02b9b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet bei d_1bc850 == 0 die virtuelle Aktion 0x0d am Burg-Objekt p1 und markiert sie bei
 *   erfolgreichem Abschluss in d_1bc850 = 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger p1 entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet wird das Statusbyte d_1bc850.
 === Ende Beschreibung === */
void f_02b9b0(int p1)
{
    if (EQB(d_1bc850, 0)) {
        if (VC(p1, 0xd) == 0) d_1bc850 = 1;
    }
}

//@ f_02b9f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt im Textfenster die feste Beschreibungsmeldung 0x33000023 der Burg von Riva an.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt den Textmanager d_1c2c64.
 === Ende Beschreibung === */
void f_02b9f0()
{
    d_1c2c64.f_0bf730(0x33000023);
}

//@ f_02ba10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt den aktuellen Gruppenanführer über f_038c40(d_1c0004), trägt ihn als Textplatzhalter
 *   ein und gibt die Meldung 0x33000024 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet den Textkontext Msg (f_125400/f_1254a0) und d_1c0004.
 === Ende Beschreibung === */
void f_02ba10()
{
    CX(m);
    m.n[1] = f_038c40(d_1c0004);
    d_1c2c64.f_0bf730(0x33000024);
    CXEND(m);
}

//@ f_02ba60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bestimmt über f_0396f0(d_1c0004, 0) ein Gruppenmitglied für den Textplatzhalter und zeigt
 *   anschließend die Burgmeldung 0x33000025 an.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02ba60()
{
    CX(m);
    m.n[1] = f_0396f0(d_1c0004, 0);
    d_1c2c64.f_0bf730(0x33000025);
    CXEND(m);
}

//@ f_02bab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt im Dialogfenster die Beschreibung 0x33000026 an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64.
 === Ende Beschreibung === */
void f_02bab0()
{
    d_1c2c64.f_0bf730(0x33000026);
}

//@ f_02bad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt bei d_1bc848 == 0 eine mehrstufige Szene in der Burg aus: Abhängig von der Gruppengröße
 *   (f_0db9a0) und Talent-/Eigenschaftsprüfungen (f_039320, f_039660) werden die Texte 0x33000027-0x3300002a
 *   ausgegeben und anschließend die Begegnung 0x1b gestartet. Gewinnt die Gruppe (s == 0), folgen Musikwechsel,
 *   der Text 0x3300002b, ein Chronik-/Tagebucheintrag (0x8030005), 15 Minuten Zeitfortschritt, 50
 *   Abenteuerpunkte (0x32), der Questfortschritt 0x16 sowie das Setzen von d_1bc848 = 1 und d_1bc860 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert werden d_1bc848, d_1bc860, die Spieluhr d_1c2c44 und das Tagebuch d_1c2c00.
 === Ende Beschreibung === */
int f_0f2720(int p1);
void f_02bad0(int p1)
{
    CX(m);
    if (EQ(d_1bc848, 0)) {
        short s;
        m.n[1] = f_039320(d_1c0004, 0x33);
        s = f_0db9a0(d_1c0004);
        if (s > 1) d_1c2c64.f_0bf730(0x33000027); else d_1c2c64.f_0bf730(0x33000028);
        f_0f2720(8);
        m.n[1] = f_039660(d_1c0004, 0xd);
        s = f_0db9a0(d_1c0004);
        if (s > 1) d_1c2c64.f_0bf730(0x33000029); else d_1c2c64.f_0bf730(0x3300002a);
        s = VC(p1, 0x1b);
        if (s == 0) {
            f_10b890(1);
            f_060a70();
            d_1c2c64.f_0bf730(0x3300002b);
            f_057220(A(d_1c2c00), 0x8030005, 0);
            f_125ed0(A(d_1c2c44), 0xf);
            d_1bc848 = 1;
            d_1bc860 = 1;
            f_0dcbb0(d_1c0004, 0x32);
            f_091f70(0x16);
        }
    }
    CXEND(m);
}
//@ f_02bc20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt den Gruppenanführer in den Textkontext ein, zeigt die Meldung 0x3300002c an und baut den
 *   Textkontext wieder ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt den Rückgabewert des
 *   Textkontext-Abbaus zurück.
 * - Wichtige Variablen: Nutzt d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
int f_02bc20()
{
    CX(m);
    m.n[1] = f_038c40(d_1c0004);
    d_1c2c64.f_0bf730(0x3300002c);
    return (int)CXEND(m);
}

//@ f_02bc70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung im Spiel.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02bc70(void)
{
}

//@ f_02bc80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Textmeldung 0x3300002d im Dialogfenster aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64.
 === Ende Beschreibung === */
void f_02bc80()
{
    d_1c2c64.f_0bf730(0x3300002d);
}

//@ f_02bca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt die Meldung 0x3300002e an und löst danach über f_0603b0(0x0c) die zugehörige Karten-
 *   oder Türfunktion 12 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02bca0()
{
    d_1c2c64.f_0bf730(0x3300002e);
    f_0603b0(0xc);
}

//@ f_02bcc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Text 0x3300002f aus und ruft anschließend f_0603b0(0x0d) auf.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02bcc0()
{
    d_1c2c64.f_0bf730(0x3300002f);
    f_0603b0(0xd);
}

//@ f_02bce0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Aktion.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02bce0(void)
{
}

//@ f_02bcf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bestimmt beim ersten Betreten (d_1bc81d == 0) über f_039320(d_1c0004, 0x12) einen passenden
 *   Helden, gibt die Meldung 0x33000031 aus und setzt d_1bc81d = 1. *(Hinweis: d_1bc81d gehört zu den beiden in
 *   f_0281d0 vergessenen Spielstand-Merkern.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert d_1bc81d und liest d_1c0004.
 === Ende Beschreibung === */
void f_02bcf0()
{
    CX(m);
    if (d_1bc81d == 0) {
        d_1bc81d = 1;
        m.n[1] = f_039320(d_1c0004, 0x12);
        d_1c2c64.f_0bf730(0x33000031);
    }
    CXEND(m);
}

//@ f_02bd60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Auslösen (d_1bc83c == 0) ein Porträtfenster (0x330001, Index 0) mit Text
 *   0x33000032 an, zieht dem Anführer über f_040780(c, 5) Punkte ab und würfelt eine Eigenschaftsprobe
 *   f_044900(c, 4, 5) (GE +5): Bei Erfolg erscheint Text 0x33000033, bei Misserfolg Text 0x33000034 samt
 *   zusätzlichem Schaden (f_044850) und Wund-/Zustandsfolge (f_040900). Bei späteren Besuchen wird nur Text
 *   0x33000035 ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Setzt das Einmal-Flag d_1bc83c = 1 und modifiziert die Werte des Gruppenanführers c.
 === Ende Beschreibung === */
void f_02bd60()
{
    CX(m);
    int c;
    c = f_038c40(d_1c0004); m.n[1] = c;
    if (EQB(d_1bc83c, 0)) {
        T9 *p1 = f_0606a0(0x330001, 0);
        d_1c2c64.f_0bf6c0(5);
        d_1c2c64.f_0bde40();
        d_1c2c64.f_0bfa20(p1, 0, 0x33000032, 0);
        d_1c2c64.f_0bf680();
        f_040780(c, 5);
        short s = f_044900(c, 4, 5);
        if (s > 0) {
            d_1c2c64.f_0bf730(0x33000033);
        } else {
            d_1c2c64.f_0bf730(0x33000034);
            f_044850(c, 5, 5);
            f_040900(c, 2);
        }
        d_1bc83c = 1;
        delete p1;
    } else {
        d_1c2c64.f_0bf730(0x33000035);
    }
    CXEND(m);
}

//@ f_02be90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt über f_039320(d_1c0004, 0x20) einen Helden der Gruppe aus und gibt mit dessen Namen die
 *   Meldung 0x33000036 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02be90()
{
    CX(m);
    m.n[1] = f_039320(d_1c0004, 0x20);
    d_1c2c64.f_0bf730(0x33000036);
    CXEND(m);
}

//@ f_02bef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet in der Burg den Behälter mit der Kennung 0x0e (Obj112(0xe, 0, 0)). Gelingt das Öffnen
 *   (f_1131b0() == 1), wird beim ersten Mal (d_1bc884 == 0) die Entdeckungsmeldung 0x33000037 ausgegeben und
 *   anschließend der Truheninhalt über f_112ec0() angezeigt.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert das Einmal-Flag d_1bc884.
 === Ende Beschreibung === */
void f_02bef0()
{
    Obj112 *p1 = new (mark(d_1a06f0, 0x700)) Obj112(0xe, 0, 0);
    int r = p1->f_1131b0();
    if (r == 1) {
        if (EQ(d_1bc884, 0)) {
            d_1c2c64.f_0bf730(0x33000037);
            d_1bc884 = 1;
        }
        p1->f_112ec0();
    }
    delete p1;
}

//@ f_02bf80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt über f_039320(d_1c0004, 0x33) den besten Helden für das geforderte Talent und zeigt
 *   mit dessen Namen die Meldung 0x33000038 an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02bf80()
{
    CX(m);
    m.n[1] = f_039320(d_1c0004, 0x33);
    d_1c2c64.f_0bf730(0x33000038);
    CXEND(m);
}

//@ f_02bfe0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft f_060360(0x0c) auf, um einen Durchgang oder Kartenzustand in der Burg umzuschalten.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_060360.
 === Ende Beschreibung === */
void f_02bfe0()
{
    f_060360(0xc);
}

//@ f_02bff0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt im Dialogfenster die Meldung 0x33000039 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt den Rückgabewert von f_0bf730
 *   zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64.
 === Ende Beschreibung === */
int f_02bff0()
{
    return d_1c2c64.f_0bf730(0x33000039);
}

//@ f_02c010
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Wirkung.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Keine Variablenzugriffe.
 === Ende Beschreibung === */
void f_02c010(void)
{
}

//@ f_02c020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet über f_060360(0x0d) das zugehörige Objekt in der Burg um.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert an f_060360.
 === Ende Beschreibung === */
void f_02c020()
{
    f_060360(0xd);
}

//@ f_02c030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft als Callback für f_039ac0, ob ein Gruppenmitglied handlungsfähig (f_0d4a60 != 0) und
 *   weiblich (f_042380 == 1) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt 1 bei einer handlungsfähigen Heldin
 *   zurück, sonst 0.
 * - Wichtige Variablen: Liest den Charakterstatus und das Geschlecht des übergebenen Helden.
 === Ende Beschreibung === */
int f_02c030(int p1)
{
    if (f_0d4a60(p1) != 0) {
        if (f_042380((struct hero *)(p1)) == 1) return 1;
    }
    return 0;
}

//@ f_02c050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt zunächst die Meldung 0x33000039 aus und prüft dann, ob der Gruppenanführer der
 *   Charakterklasse 6 (Krieger) angehört, männlich ist (f_042380 == 0), ein bestimmtes Flag (f_042950) besitzt
 *   und die Eigenschaftsprobe f_044900(p1, 0xc, 0) besteht. Ist dies der Fall, wird eine Sonderszene
 *   (0x3300003a, und falls eine weibliche Gefährtin f_02c030 in der Gruppe ist, zusätzlich 0x3300003b) samt 50
 *   Punkten Bonus (f_0d4800(0x32)) ausgelöst.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden der Gruppenanführer d_1c0004 und die Gruppenmitglieder über f_039ac0.
 === Ende Beschreibung === */
void f_02c050()
{
    d_1c2c64.f_0bf730(0x33000039);
    int p1 = f_038c40(d_1c0004);
    if (f_042350((struct hero *)(p1)) == 6) {
        if (f_042380((struct hero *)(p1)) == 0) {
            if (((char)(f_042950((struct hero *)(p1))))) {
                short s = f_044900(p1, 0xc, 0);
                if (s > 0) {
                    CX(m);
                    int r = f_039ac0(d_1c0004, (int)f_02c030);
                    m.n[1] = p1;
                    f_060740(0x1267, 1);
                    f_0d4800(0x32);
                    d_1c2c64.f_0bf730(0x3300003a);
                    if (r != 0) {
                        m.n[2] = r;
                        d_1c2c64.f_0bf730(0x3300003b);
                    }
                    f_060740(0x1267, 1);
                    CXEND(m);
                }
            }
        }
    }
}

//@ f_02c150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verwaltet das Objekt Obj5f(0xf, 0x1f51) in der Burg: Ist d_1bc860 == 1 und d_1bc838 == 0,
 *   erscheint ein Dialogporträt (0x330001, Index 1) mit Text 0x3300003c, gefolgt vom Kampf 0x0f. Bei einem Sieg
 *   (s == 0) wird der Queststatus 0x17 (f_091f70) sowie d_1bc838 = 1 gesetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Objektzeiger p1 und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft und gesetzt werden d_1bc860 und d_1bc838.
 === Ende Beschreibung === */
void f_02c150(int p1)
{
    Obj5f *o = new (mark(d_1a06f0, 0x7bf)) Obj5f(0xf, 0x1f51);
    if (o->f_05f560() != 0 && EQ(d_1bc860, 1)) o->f_05f470();
    o->f_05f280(0);
    if (o->f_05f580() != 0 && EQ(d_1bc860, 1) && EQ(d_1bc838, 0)) {
        T9 *t = f_0606a0(0x330001, 1);
        d_1c2c64.f_0bde40();
        d_1c2c64.f_0bfa20(t, 0, 0x3300003c, 0);
        delete t;
        short s = VC(p1, 0xf);
        if (s == 0) {
            f_091f70(0x17);
            d_1bc838 = 1;
        } else {
            o->f_05f5a0(1);
        }
    }
    delete o;
}

//@ f_02c280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten (d_1bc868 == 0) mit dem Namen des Gruppenanführers den Text
 *   0x3300003d aus, trägt den Hinweis 0x8030006 ins Tagebuch ein und setzt d_1bc868 = 1. Ist später auch
 *   d_1bc86c == 1, wird stattdessen 0x3300003e angezeigt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1bc868, d_1bc86c, d_1c0004 und das Tagebuch d_1c2c00.
 === Ende Beschreibung === */
void f_02c280()
{
    if (EQ(d_1bc868, 0)) {
        CX(m);
        m.n[1] = f_038c40(d_1c0004);
        d_1c2c64.f_0bf730(0x3300003d);
        f_057220(A(d_1c2c00), 0x8030006, 0);
        d_1bc868 = 1;
        CXEND(m);
    } else if (EQ(d_1bc86c, 1)) {
        d_1c2c64.f_0bf730(0x3300003e);
    }
}

//@ f_02c320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt im Dialogfenster die Meldung 0x3300003f an.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_02c320()
{
    d_1c2c64.f_0bf730(0x3300003f);
}

//@ f_02c340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Beschreibungstext 0x33000040 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_02c340()
{
    d_1c2c64.f_0bf730(0x33000040);
}

//@ f_02c360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt ebenfalls den Beschreibungstext 0x33000040 an.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_02c360()
{
    d_1c2c64.f_0bf730(0x33000040);
}

//@ f_02c380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Meldung 0x33000041 aus und führt anschließend f_0603b0(0x68) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02c380()
{
    d_1c2c64.f_0bf730(0x33000041);
    f_0603b0(0x68);
}

//@ f_02c3a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt dem Spieler bei d_1bc834 == 0 mit dem Porträt 0x330001 (Index 2) die Frage 0x33000042
 *   mit zwei Antwortmöglichkeiten (0x33000043, 0x33000044). Antwort 1 gibt 0x33000045 aus und setzt d_1bc834 =
 *   1; Antwort 2 (oder Abbruch) spielt die Animationssequenz 0x330006 am Objekt 0x1f49 ab.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet das Einmal-Flag d_1bc834 und Obj5f(0, 0x1f49).
 === Ende Beschreibung === */
void f_02c3a0()
{
    if (EQ(d_1bc834, 0)) {
        T9 *t = f_0606a0(0x330001, 2);
        short s = d_1c2c64.f_0bfa20(t, 0, 0x33000042, 2, 0x33000043, 0x33000044);
        delete t;
        switch (s) {
        case 1:
            d_1c2c64.f_0bf730(0x33000045);
            d_1bc834 = 1;
            break;
        case -1:
        case 2: {
            Obj5f *o = new (mark(d_1a06f0, 0x86e)) Obj5f(0, 0x1f49);
            if (EQ(o->f_05f580(), 0)) o->f_05f480();
            f_060800(0x330006, 1, 0);
            o->f_05f4f0(0);
            delete o;
            break;
        }
        }
    }
}

//@ f_02c4c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt den Gruppenanführer in den Textkontext ein und gibt die Meldung 0x33000046 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c0004 und d_1c2c64.
 === Ende Beschreibung === */
void f_02c4c0()
{
    CX(m);
    m.n[1] = f_038c40(d_1c0004);
    d_1c2c64.f_0bf730(0x33000046);
    CXEND(m);
}

//@ f_02c510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt den Text 0x33000047 an und löst f_0603b0(0x0f) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02c510()
{
    d_1c2c64.f_0bf730(0x33000047);
    f_0603b0(0xf);
}

//@ f_02c530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt den Text 0x33000047 an und löst f_0603b0(0x10) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02c530()
{
    d_1c2c64.f_0bf730(0x33000047);
    f_0603b0(0x10);
}

//@ f_02c550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt den Text 0x33000047 an und löst f_0603b0(0x11) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02c550()
{
    d_1c2c64.f_0bf730(0x33000047);
    f_0603b0(0x11);
}

//@ f_02c570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt den Text 0x33000047 an und löst f_0603b0(0x12) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet d_1c2c64 und f_0603b0.
 === Ende Beschreibung === */
void f_02c570()
{
    d_1c2c64.f_0bf730(0x33000047);
    f_0603b0(0x12);
}

//@ f_02c590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Beschreibungsmeldung 0x33000048 im Textfenster aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Nutzt d_1c2c64.
 === Ende Beschreibung === */
void f_02c590()
{
    d_1c2c64.f_0bf730(0x33000048);
}

//@ f_02c5b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verwaltet eine Stelle in der Burg, an der die Gruppe Dukaten (je 10 Silbertaler = 100 Heller,
 *   über f_0de7e0(d_1c0004) / 10) hinterlegen oder wieder entnehmen kann. Liegt bereits Geld darin (d_1bc880 >
 *   0), kann der Spieler zwischen weiterem Einzahlen (Option 1, zieht k * 10 vom Gruppenvermögen ab und erhöht
 *   den Gunst-/Tempelwert über f_054ca0(1, k)) und Entnehmen (Option 2, zahlt k * 10 aus und senkt den Wert über
 *   f_054ca0(1, -k)) wählen; ist der Stand 0, wird direkt das Einzahlen angeboten.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwaltet den gespeicherten Betrag in d_1bc880, das Gruppenvermögen über
 *   f_0de7e0/f_0db8b0/f_0db820 und den Gunstzähler über f_054ca0.
 === Ende Beschreibung === */
#define SWHEAD switch (f_0bf820(&d_1c2c64, 0x33000049, 2, 0x3300004a, 0x3300004b))
#define SWNEG case -1: break;
void f_02c5b0()
{
    CX(m);
    m.t[1] = d_1bc880;
    short s = d_1bc880;
    if (s > 0 ? 1 : 0) {
        SWHEAD {
        SWNEG
        case 1: {
            int n = f_0de7e0(d_1c0004);
            short v = (short)(n / 10);
            if (v > 999) v = 999;
            short r = d_1c2c64.f_0bf7b0(3, 0x3300004c, 0, v, 0);
            int k = r;
            if (k > 0) {
                d_1bc880 = d_1bc880 + r;
                f_0db8b0(d_1c0004, k * 10);
                f_054ca0(1, k);
            }
            break;
        }
        case 2: {
            short n = d_1bc880;
            short v = n;
            if (v > 999) v = 999;
            short r = d_1c2c64.f_0bf7b0(3, 0x3300004d, 0, v, 0);
            int k = r;
            if (k > 0) {
                d_1bc880 = d_1bc880 - r;
                f_0db820(d_1c0004, k * 10);
                f_054ca0(1, -k);
            }
            break;
        }
        }
    } else {
        if (d_1c2c64.f_0bf6f0(0x3300004e) == 1) {
            int n = f_0de7e0(d_1c0004);
            short v = (short)(n / 10);
            if (v > 999) v = 999;
            short r = d_1c2c64.f_0bf7b0(3, 0x3300004c, 0, v, 0);
            int k = r;
            if (k > 0) {
                d_1bc880 = d_1bc880 + r;
                f_0db8b0(d_1c0004, k * 10);
                f_054ca0(1, k);
            }
        }
    }
    CXEND(m);
}
