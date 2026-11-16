/* === Beschreibung (Katalog) ===
 * Einheit charact1 (0x044300 - 0x0452a0)
 *
 * Überblick
 * Die Einheit charact1 enthält die zentralen Spielregeln für Helden in *Schatten über Riva*: das Zufügen und
 * Heilen von Lebenspunkteschaden (inklusive Todesschrei, Bewusstlosigkeit unter 5 LE und Unsterblichkeitsschutz
 * für bestimmte Begleit-NPCs), den stündlichen Hunger-/Durst-Schaden, Eigenschafts- und Talentproben (1W20 bzw.
 * 3W20), die Neuberechnung von Magieresistenz (MR) und Attacke-/Parade-Basiswerten, das Laden des
 * zustandsabhängigen Heldenporträts sowie die Berechnung des Rüstungsschutzes.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// P3 17/18 gleich (suche.py 30.10.2026, Basis charact1_P1.CPP)
// charact1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x044300-0x0452A0
#include <string.h>
typedef RivaTextContextData PL;
struct Q { int x; };
struct T13 { int a, b, c; char d; };
struct S6 { int x; short y; };
struct Ent2 { short f_050710(int id); void f_04feb0(int a, int b, int c, int p5, int p6, int *p7, int *p8, int p9); };
#define T2 short
void *f_014540(int size, const char *file, int line);
int f_030ed0(int p1, int p2);
unsigned short f_03ad80(int p1, int p2);
int f_03af20(int p1, int p2, int p3);

















signed char f_0435c0(int p1, int p2);
int f_0435e0(int p1, int p2, int p3);
int f_043620(int p1, int p2, int p3);
unsigned short f_043820(int p1, int p2);
int f_043840(int p1, int p2, int p3);
int f_043880(int p1, int p2, int p3);
int f_043c90(int p1);
int f_043ca0(int p1);
int f_043dd0(int p1, int p2, int p3);
signed char f_043df0(int p1);
char f_043e30(int p1);
int f_0a78a0x(int p1);


int f_0bcd30(void *p1, int p2, int p3);
int f_0bf730(void *p1, int p2);
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1);
int f_0d4ad0x(int p1);
short f_0d4ad0(int p1);
unsigned short f_0d4b00(int p1);
int f_0d5290(int p1, int p2);
int f_0dbfb0(int p1, int p2);
int f_0e3360(void *p1);
int f_0e93f0(void *p1, void *p2, int p3);

void f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_1254a0(void *p1);
int f_133fe0(void *p1, void *p2);
short f_1457e0(int p1);
int f_057220(void *p1, int p2, int p3);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323 modify [esp];
extern int d_1a47ac_dummy;
extern signed char d_1a47ac[];
extern signed char d_1a6ad0[];
extern signed char d_1a6ad1[];
extern signed char d_1a6ad2[];
extern const T13 d_1a0e10;
extern signed char d_1a0e1d;
extern const S6 d_1a0e1e;
extern unsigned short d_1a9820;
extern int d_1bc88c;
extern int d_1bc8f8;
extern short d_1bd90c;
extern short d_1bd910;
extern int d_1bd914;
extern short d_1bd920;
extern char d_1bd928;
extern int d_1bf230;
extern int d_1c0004;
extern char d_1c0834[];
extern volatile short d_1c2198;
extern short d_1c219a;
extern short d_1c219c;
extern int d_1c21a4;
extern int d_1c2a80;
extern Ent2 d_1c2be0;
extern int d_1c2c00;

extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
extern const char d_1a0df0[];
void f_044a00(int p1, signed char p2);
#define SEL(v) v = 0x20008; if (f_0d4b00(p1) == 0) { if (f_0d4ad0(p1) == 0) { mx = f_042970((struct hero *)(p1)); cu = f_042960((struct hero *)(p1)); if (!(cu < mx / 3 && f_042960((struct hero *)(p1)) < 0x19)) { if (f_042960((struct hero *)(p1)) >= 10) v = 0x20007; } } }
//@ f_044300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht einem lebenden Helden (p1) p2 Lebenspunkte ab (verdoppelt, falls das Flag d_1bd928 aktiv
 *   ist), weckt ihn aus dem Schlaf (Bit 1 in 0xbc), aktualisiert den roten LE-Balken (f_0bcd30) und schützt die
 *   handlungsrelevanten Begleit-NPCs mit npc_id == 4 oder 6 davor, auf 5 oder weniger LE zu fallen. Sinkt die LE
 *   auf <= 0, spielt die Funktion den geschlechtsspezifischen Todesschrei (0x2000a/0x2000b) ab, gibt die
 *   Todesmeldung (0x204002c) aus, markiert den Helden als tot (f_042480) und setzt laufende Krankheiten und
 *   Vergiftungen zurück; bleibt der Held am Leben, spielt sie je nach Schadenshöhe (> 20 oder <= 20) einen
 *   Schmerzenslaut (0x2000c-0x2000f) ab und versetzt ihn beim Unterschreiten von 5 LE in Bewusstlosigkeit
 *   (f_030ed0(p1, 1)).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie den Schadenswert (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert *(short*)(p1 + 0x72) (le), liest d_1bd928 (Schadensverdopplung) und d_1bd914
 *   (Stummschaltung) und setzt bei Tod d_1c219a = 1 sowie d_1c219c = 1.
 === Ende Beschreibung === */
void f_044300(int p1, short p2)
{
void reset670(char*,int);
#pragma aux reset670 "f_043dd0"
struct Sound670 {static void play(int id,volatile int &flags){f_147323(&d_1c2edc,id,0x7fff,0x8000,flags,0,1);}};
    short i = 0;
    short old = 0;
    unsigned short damage = p2;
    PL pl;
    if (!((char)(f_042470((struct hero *)(p1)))) && (short)p2 > 0) {
        if (d_1bd928 != (char)0) p2 += damage;
        old = *(short *)(p1 + 0x72);
        *(short *)(p1 + 0x72) -= p2;
        if (*(unsigned char *)(p1 + 0xbc) & 2)
            *(unsigned char *)(p1 + 0xbc) &= 0xfd;
        f_0bcd30(&d_1bf230, (short)f_043df0(p1), 0);
        if ((int)*(signed char *)(p1 + 0x9b) != 0) {
            switch (*(unsigned char *)(p1 + 0x9b)) {
            case 4:
            case 6:
                if (*(short *)(p1 + 0x72) <= 5)
                    *(short *)(p1 + 0x72) = old;
                break;
            }
        }
        if (*(short *)(p1 + 0x72) <= 0) {
            if (d_1bd914 == 0) {
                if ((int)f_042380((struct hero *)(p1)) == 0)
                    Sound670::play(0x2000b,*(int*)&d_1a9820);
                else
                    Sound670::play(0x2000a,*(int*)&d_1a9820);
            }
            if (!f_0e3360(&d_1c2c64) && d_1bd90c == (short)0) {
                f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
                char *blk = (char *)f_014540(100, d_1a0df0, 0xbd);
                pl.tables.p[1] = p1;
                f_0e93f0(&d_1c38b0, blk, 0x204002c);
                int t = f_133fe0(&d_1c3498, blk);
                f_057220(&d_1c2c00, t, 0);
                f_0bf730(&d_1c2c64, t);
                delete blk;
                f_1254a0(&pl, 0);
            }
            *(short *)(p1 + 0x72) = 0;
            f_042480((struct hero *)(p1), 1);
            f_030ed0(p1, 0);
            reset670((char*)p1,0);
            *(unsigned char *)(p1 + 0x96) = 100;
            *(volatile short*)&d_1c219a = 1;
            for (i = 1; i <= 7; i++) {
                signed char t_152 = f_043820(p1, i);
                if (t_152 == (short)-1) {
                    f_043840(p1, i, 1);
                    f_043880(p1, i, 0);
                }
            }
            for (i = 1; i <= 9; i++) {
                if (f_0435c0(p1, i) == -1) {
                    f_0435e0(p1, i, 1);
                    f_043620(p1, i, 0);
                }
            }
        } else if (d_1bd914 == 0) {
            if ((short)p2 > 20) {
                if ((int)f_042380((struct hero *)(p1)) == 0)
                    Sound670::play(0x2000f,*(int*)&d_1a9820);
                else
                    Sound670::play(0x2000e,*(int*)&d_1a9820);
            } else {
                if ((int)f_042380((struct hero *)(p1)) == 0)
                    Sound670::play(0x2000d,*(int*)&d_1a9820);
                else
                    Sound670::play(0x2000c,*(int*)&d_1a9820);
            }
        }
        if (!((char)(f_042470((struct hero *)(p1)))) && (int)(short)old >= 5 && *(short *)(p1 + 0x72) < 5) {
            f_030ed0(p1, 1);
            f_042800((struct hero *)(p1), 13);
        }
        if ((int)d_1bd920 == 1 && (((char)(f_042470((struct hero *)(p1)))) || ((char)(f_0425f0((struct hero *)(p1)))))) {
            d_1bd90c = 0;
            *(short *)&d_1c21a4 = 6;
        }
        if (((char)(f_042470((struct hero *)(p1)))) && d_1bd90c == (short)0)
            d_1c219c = 1;
    }
}

//@ f_044670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht einem lebenden Helden (p1) 1 Lebenspunkt durch Verhungern oder Verdursten ab, prüft, ob
 *   sich dadurch das Porträt von gesund (0x20007) auf geschwächt (0x20008) ändert, spielt einen Schmerzenslaut
 *   ab und reduziert bei LE <= 0, statt den Helden sofort zu töten, dessen maximale Lebenspunkte (le_max, Offset
 *   0x70) um 1 (und erhöht im Gegenzug le_mod am Offset 0x8c), solange le_max >= 2 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Verringert le (0x72), verschiebt bei LE <= 0 Punkte von le_max (0x70) nach le_mod (0x8c)
 *   und setzt d_1c219a bzw. d_1c2198.
 === Ende Beschreibung === */
void f_044670(int p1)
{
    int f_147323_clean(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
#pragma aux f_147323_clean "f_147323"
struct SoundFamily670 {static void play(int id,volatile int &flags){int play670(void*,int,int,int,int,int,int);
#pragma aux play670 "f_147323"
play670(&d_1c2edc,id,0x7fff,0x8000,flags,0,1);}};
    int old_state, new_state;
    if (!((char)(f_042470((struct hero *)(p1))))) {
        int q1 = p1;
        old_state = (f_0d4b00(p1) || f_0d4ad0(p1) ||
            (f_042960((struct hero *)(p1)) < f_042970((struct hero *)(p1)) / 3 && f_042960((struct hero *)(p1)) < 25) ||
            f_042960((struct hero *)(q1)) < 10) ? 0x20008 : 0x20007;
        int q2 = p1;
        *(short *)(p1 + 0x72) = *(short *)(p1 + 0x72) - 1;
        new_state = (f_0d4b00(p1) || f_0d4ad0(p1) ||
            (f_042960((struct hero *)(p1)) < f_042970((struct hero *)(p1)) / 3 && f_042960((struct hero *)(p1)) < 25) ||
            f_042960((struct hero *)(q2)) < 10) ? 0x20008 : 0x20007;
        if (old_state != new_state) d_1c219a = 1;
        if (*(short *)(p1 + 0x72) < 5 && !((char)(f_0425f0((struct hero *)(p1))))) {
            f_030ed0(p1, 1);
        } else if (d_1bd914 == 0 || (short)d_1bd910 == 1) {
            if (f_0dbfb0(*(int *)&d_1c0004, p1)) {
                if (!(int)f_042380((struct hero *)(p1)))
                    SoundFamily670::play(0x2000d,*(int*)&d_1a9820);
                else
                    SoundFamily670::play(0x2000c,*(int*)&d_1a9820);
            }
        }
        if (*(short *)(p1 + 0x72) <= 0) {
            *(short *)(p1 + 0x72) = 1;
            if (*(short *)(p1 + 0x70) >= 2) {
                --*(short *)(p1 + 0x70);
                ++*(unsigned char *)(p1 + 0x8c);
            }
        }
    }
    if (d_1c2a80 == 0x30000) d_1c2198 = 1;
}
//@ f_044850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht einem Helden (p1) über f_044300 maximal soviel Schaden (p2) ab, dass ihm mindestens p3
 *   Lebenspunkte verbleiben (nicht-tödlicher Schaden, z. B. bei bestimmten Fallen oder Prügeleien).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), den gewünschten Schaden (p2) sowie die
 *   Mindest-Rest-LE (p3) und gibt den tatsächlich abgezogenen Schaden als short zurück.
 * - Wichtige Variablen: Liest die aktuelle LE über f_042960 und ruft bei positivem Schaden f_044300 auf.
 === Ende Beschreibung === */
short f_044850(int p1, T2 p2, T2 p3)
{
    short cur = f_042960((struct hero *)(p1));
    if ((short)p2 >= cur - (short)p3) p2 = cur - (short)p3;
    if ((short)p2 > 0) f_044300(p1, (short)p2);
    else p2 = 0;
    return p2;
}
//@ f_044890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Heilt einen lebenden Helden (p1) um p2 Lebenspunkte bis maximal zu seinem Höchstwert (le_max,
 *   Offset 0x70) und hebt eine bestehende Bewusstlosigkeit (f_030ed0(p1, 0)) wieder auf, sobald der Held
 *   mindestens 5 Lebenspunkte erreicht. *(Hinweis: Enthält den redundanten Vergleich d_1c2a80 == 0x30000 ||
 *   d_1c2a80 == 0x30000 statt 0x30001, siehe Fehlerliste).*
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Heilmenge (p2) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Erhöht *(short*)(p1 + 0x72) (le) bis *(short*)(p1 + 0x70) (le_max) und setzt d_1c219a =
 *   1.
 === Ende Beschreibung === */
void f_044890(int p1, T2 p2)
{
    if (!((char)(f_042470((struct hero *)(p1)))) && (short)p2 > 0) {
        *(short *)(p1 + 0x72) += p2;
        if (*(short *)(p1 + 0x72) > *(short *)(p1 + 0x70))
            *(short *)(p1 + 0x72) = *(short *)(p1 + 0x70);
        if (*(short *)(p1 + 0x72) >= 5 && ((char)(f_0425f0((struct hero *)(p1)))))
            f_030ed0(p1, 0);
    }
#if FIX_R013
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) d_1c2198 = 1;
#else
    if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30000) d_1c2198 = 1;
#endif
    d_1c219a = 1;
}
//@ f_044900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine DSA-Eigenschaftsprobe (1W20) auf das Attribut p2 des Helden p1 mit der Erschwernis
 *   p3 durch. Bei einer gewürfelten 20 gilt die Probe automatisch als gepatzt (-99), andernfalls wird die
 *   übrigbehaltene Differenz Attributwert - (Erschwernis + Wurf) + 1 zurückgegeben (> 0 bedeutet bestanden).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), den Attribut-Index (p2) und die
 *   Probenerschwernis (p3) und gibt die übrigbehaltenen Punkte (> 0 = Erfolg, <= 0 = Misserfolg, -99 = Patzer)
 *   als short zurück.
 * - Wichtige Variablen: Würfelt mit f_1457e0(20) und liest den effektiven Attributwert über f_042a40.
 === Ende Beschreibung === */
short f_044900(int p1, T2 p2, int p3)
{
    short r = f_1457e0(20);
#if FIX_BUGS >= 1
    int wert = f_042a40((struct hero *)(p1), (short)p2);
    short erg = (r == 20) ? -99 : (short)(wert - (p3 + r) + 1);
    PLOG_1W20((const char *)(p1 + 0x22), (short)p2, wert, p3, r, erg);
    return erg;
#else
    if (r == 20) return -99;
    return f_042a40((struct hero *)(p1), (short)p2) - (p3 + r) + 1;
#endif
}
//@ f_044940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine dreifache Eigenschaftsprobe (3W20) auf die drei Attribute p2, p3 und p4 des Helden
 *   p1 mit dem Gesamtmodifikator p5 durch. Fallen mindestens zwei Zwanziger, wird -99 (Patzer) zurückgegeben;
 *   andernfalls liefert die Funktion (Attr1 + Attr2 + Attr3) - (Wurfsumme + p5) + 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), drei Attribut-Indizes (p2, p3, p4) sowie
 *   die Erschwernis (p5) und gibt das Probenergebnis als short zurück.
 * - Wichtige Variablen: Nutzt f_1457e0(20) für die drei Würfelwürfe und f_042a40 für die drei Eigenschaftswerte.
 === Ende Beschreibung === */
short f_044940(int p1, short p2, short p3, short p4, signed char p5)
{
    unsigned short sum = 0;
    short ones = 0;
    short i;
    short r;
    short c;
#if FIX_BUGS >= 1
    short w[3] = { 0, 0, 0 };
    for (i = 0; i < 3; i++) {
        r = f_1457e0(20);
        w[i] = r;
        if (r == 20) {
            ones = ones + 1;
            if (ones == 2) break;
        }
        sum = sum + r;
    }
    sum += p5;
    r = (signed char)f_042a40((struct hero *)(p1), p2);
    ones = (ones == 2) ? -99 : (signed char)f_042a40((struct hero *)(p1), p3);
    c = f_042a40((struct hero *)(p1), p4);
    short erg = (ones == -99) ? -99 : (short)((ones + r) + c - sum + 1);
    PLOG_3W20('T', (const char *)(p1 + 0x22), 0, 0, p5, p2, r, w[0], p3, (signed char)f_042a40((struct hero *)(p1), p3), w[1], p4, c, w[2], erg);
    return erg;
#else
    for (i = 0; i < 3; i++) {
        r = f_1457e0(20);
        if (r == 20) {
            ones = ones + 1;
            if (ones == 2) return -99;
        }
        sum = sum + r;
    }
    sum += p5;
    r = (signed char)f_042a40((struct hero *)(p1), p2);
    ones = (signed char)f_042a40((struct hero *)(p1), p3);
    c = f_042a40((struct hero *)(p1), p4);
    return (ones + r) + c - sum + 1;
#endif
}
//@ f_0449d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert den temporären Magieresistenz-Modifikator (mr_mod, Offset 0xbb) des Helden um p2 und
 *   berechnet anschließend über f_044a00 die gesamte Magieresistenz neu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die MR-Änderung (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert *(signed char*)(p1 + 0xbb) und übergibt den alten Gesamtwert an f_044a00.
 === Ende Beschreibung === */
void f_0449d0(int p1, signed char p2)
{
    signed char old = *(signed char *)(p1 + 0x78) + *(signed char *)(p1 + 0xbb);
    *(signed char *)(p1 + 0xbb) += p2;
    f_044a00(p1, old);
}
//@ f_044a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Grund-Magieresistenz (mr, Offset 0x78) des Helden nach der DSA-Formel (KL + MU +
 *   Stufe) / 3 - 2 * AG + Klassenbonus (aus der Tabelle d_1a0e10) neu. Hat sich die gesamte Magieresistenz (mr +
 *   mr_mod) gegenüber dem Vorwert p2 verändert, gibt die Funktion bei nicht stummgeschalteten Meldungen
 *   (d_1bc88c == 0) den Hinweis 0x20000182 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie den bisherigen MR-Gesamtwert (p2) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest MU (0), KL (1), AG (7), level und type, aktualisiert *(char*)(p1 + 0x78) und nutzt
 *   die Klassentabelle d_1a0e10.
 === Ende Beschreibung === */
int f_0ce7e0(void *p1, int p2);
struct MsgA { int h; char *q[14]; };   // Fable 30.10.: ctor/dtor explizit (keine COMDAT-Kopien)
struct SOa { int d; };
void f_044a00(int p1, signed char p2)
{
    T13 tbl = d_1a0e10;
    MsgA m; f_125400(&m, (void *)&d_1c349c, (void *)&d_1c3870, (void *)&d_1c3498);
    SOa o; f_0ce7c0(&o);
    { int *q_vb = *(int * *)&m.q[0]; q_vb[1] = p1; }
    int erster = (signed char)f_042a40((struct hero *)(p1),1);
    int wert = (signed char)f_042a40((struct hero *)(p1),0);
    int s = erster + wert;
    wert = (signed char)f_0428d0((struct hero *)(p1));
    s += wert;
    int v = s / 3;
    wert = (signed char)f_042a40((struct hero *)(p1),7);
    v -= wert * 2;
    *(char *)(p1 + 0x78) = (char)v;
    wert = (signed char)f_042350((struct hero *)(p1));
    char t = ((char *)&tbl)[wert];
    *(char *)(p1 + 0x78) += t;
    if (p2 != *(signed char *)(p1 + 0x78) + *(signed char *)(p1 + 0xbb)) {
        short k = (short)*(signed char *)(p1 + 0x78);
        short b = (short)*(signed char *)(p1 + 0xbb);
        short *q_vb_ = *(short * volatile *)&m.q[4];
        k += b;
        int quiet = d_1bc88c;
        q_vb_[1] = k;
        if (quiet == 0 && !((char)(f_042470((struct hero *)(p1)))) && !f_043e30(p1)) {
            f_0bf730((void *)&d_1c2c64, 0x20000182);
        } else {
            if ((signed char)f_043e30(p1) == 5)
                f_0e93f0((void *)&d_1c38b0, (void *)d_1c0834, 0x20000182);
        }
        if (d_1c2a80 == 0x30000) d_1c2198 = 1;
    }
    f_0ce7e0(&o, 0);
    f_1254a0(&m, 0);
}
//@ f_044b60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den Attacke-/Parade-Basiswert (atpa_base, Offset 0x79) des Helden nach der
 *   kaufmännisch gerundeten DSA-Formel (IN + KK + GE) / 5 neu. Hat sich der Basiswert geändert, werden alle
 *   sieben Attacke- und Paradewerte (0x7a-0x87) um die Differenz angepasst und die Meldung 0x20000023
 *   ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest GE (0x53), IN (0x56) und KK (0x59), aktualisiert p1 + 0x79 sowie die Arrays p1 +
 *   0x7a und p1 + 0x81.
 === Ende Beschreibung === */
#include <stdlib.h>
#pragma aux f_044b60 modify exact [eax];
int f_0ce7e0(void *p1, int p2);
struct MsgC { int h; char *q[14]; };
struct SOb { int d; };
void f_044b60(int p1)
{
    MsgC m; f_125400(&m, (void *)&d_1c349c, (void *)&d_1c3870, (void *)&d_1c3498);
    SOb o; f_0ce7c0(&o);
    *(int *)(m.q[0] + 4) = p1;
    f_0d5290(p1, 2);
    f_0d5290(p1, 3);
    div_t d = div((*(signed char *)(p1 + 0x56) + *(signed char *)(p1 + 0x59)) + *(signed char *)(p1 + 0x53), 5);
    if (d.rem >= 3) d.quot++;
    short k = (short)d.quot;
    k -= (short)*(signed char *)(p1 + 0x79);
    if (k) {
        *(char *)(p1 + 0x79) = (char)d.quot;
        *(short *)(m.q[4] + 2) = (signed char)d.quot;
        if (*(volatile int *)&d_1bc88c == 0 && !((char)(f_042470((struct hero *)(p1)))) && !f_043e30(p1)) {
            f_0bf730((void *)&d_1c2c64, 0x20000023);
        } else {
            if ((signed char)f_043e30(p1) == 5)
                f_0e93f0((void *)&d_1c38b0, (void *)d_1c0834, 0x20000023);
        }
        short i;
        for (i = 0; i < 7; i++) {
            *(char *)(p1 + i + 0x7a) += k;
            *(char *)(p1 + i + 0x81) += k;
        }
    }
    f_0ce7e0(&o, 0);
    f_1254a0(&m, 0);
}
//@ f_044c90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine DSA-Talentprobe für den Helden p1 auf das Talent p2 (7 bis 51) mit der Erschwernis
 *   p3 durch. Bei den Fernkampftalenten (p2 == 7 Schusswaffen oder p2 == 8 Wurfwaffen) wird eine 1W20-Probe auf
 *   (KL + FF + KK) / 4 + TaW - p3 gewürfelt (1 = 99, 20 = -1), während für alle übrigen Talente eine 3W20-Probe
 *   auf die drei in den Tabellen d_1a6ad0, d_1a6ad1, d_1a6ad2 hinterlegten Eigenschaften abzüglich des
 *   Talentwerts (f_03ad80) ausgeführt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), die Talentkennung (p2) sowie den
 *   Probenmodifikator (p3) und gibt die übrigbehaltenen Punkte (> 0 = bestanden, <= 0 = misslungen) als short
 *   zurück.
 * - Wichtige Variablen: Liest die Talent-Eigenschaftszuordnungen aus d_1a6ad0, d_1a6ad1 und d_1a6ad2 sowie den
 *   Talentwert über f_03ad80.
 === Ende Beschreibung === */
short f_044c90(int p1,short p2,signed char p3) {
 signed char skillBase491(int,short);
 #pragma aux skillBase491 "f_03ad80" parm [eax] [edx] value [al] modify exact [eax edx]
struct TalentProbe491 {static short run(int p1,short p2,short p3,signed char p5,short p4)
{
    unsigned short sum = 0;
    short ones = 0;
    short i;
    short r;
    short c;
    for (i = 0; i < 3; i++) {
        r = f_1457e0(20);
        if (r == 20) {
            ones = ones + 1;
            if (ones == 2) return -99;
        }
        sum = sum + r;
    }
    sum += p5;
    i=f_042a40((struct hero *)(p1),p2);
    r=f_042a40((struct hero *)(p1),p3);
    c=f_042a40((struct hero *)(p1),p4);
    return (r+i)+c-sum+1;
}};

 short result=0;
 short value=0,total=0;
 if(p2>=7 && p2<=0x33) {
  if(p2==7 || p2==8) {
   total=(f_042a40((struct hero *)(p1),1)+f_042a40((struct hero *)(p1),4)+f_042a40((struct hero *)(p1),6))/4;
   total+=skillBase491(p1,p2);
   total-=p3;
   value=f_1457e0(20);
   if(value==20)result=-1;
   else if(value==1)result=99;
   else if(value<=total)result=total-value+1;
#if FIX_BUGS >= 1
   PLOG_KAMPF('F', (const char *)(p1 + 0x22), total, p3, value, (value == 20) ? -1 : (value == 1) ? 2 : (result > 0 ? 1 : 0));
#endif
  }else {
#if FIX_BUGS >= 1
   signed char mod = p3;
   signed char tw = skillBase491(p1,p2);
   short a1 = d_1a6ad0[p2*4], a2 = d_1a6ad1[p2*4], a3 = d_1a6ad2[p2*4];
   short w[3] = { 0, 0, 0 };
   unsigned short sum = 0;
   short ones = 0, i, r;
   p3 -= tw;
   for (i = 0; i < 3; i++) {
    r = f_1457e0(20);
    w[i] = r;
    if (r == 20) {
     ones = ones + 1;
     if (ones == 2) break;
    }
    sum = sum + r;
   }
   sum += p3;
   short v1 = f_042a40((struct hero *)(p1), a1);
   short v2 = f_042a40((struct hero *)(p1), a2);
   short v3 = f_042a40((struct hero *)(p1), a3);
   result = (ones == 2) ? -99 : (short)((v2 + v1) + v3 - sum + 1);
   PLOG_3W20('T', (const char *)(p1 + 0x22), p2, tw, mod, a1, v1, w[0], a2, v2, w[1], a3, v3, w[2], result);
#else
   p3-=skillBase491(p1,p2);
   result=TalentProbe491::run(p1,d_1a6ad0[p2*4],d_1a6ad1[p2*4],p3,d_1a6ad2[p2*4]);
#endif
  }
 }
 return result;
}
//@ f_044e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entscheidet anhand des Gesundheitszustands des Helden p1, ob sein Porträt aus dem regulären
 *   Porträtarchiv (0x20007) oder aus dem Archiv für kranke/geschwächte Helden (0x20008, bei Vergiftung,
 *   Krankheit, < 10 LE oder < 1/3 LE und zugleich < 25 LE) geladen werden muss.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt die Archivkennung (0x20007 oder
 *   0x20008) als int zurück.
 * - Wichtige Variablen: Prüft f_0d4b00 (vergiftet), f_0d4ad0 (krank) sowie die Lebenspunkte über f_042960 und
 *   f_042970.
 === Ende Beschreibung === */
int f_044e30(int p1)
{
    if (f_0d4b00(p1) || f_0d4ad0(p1) ||
        (f_042960((struct hero *)(p1)) < f_042970((struct hero *)(p1)) / 3 && f_042960((struct hero *)(p1)) < 0x19) ||
        f_042960((struct hero *)(p1)) < 10)
        return 0x20008;
    return 0x20007;
}
//@ f_044ea0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das zum aktuellen Zustand des Helden p1 passende Porträtbild (Totenschädel bei Tod,
 *   Sonderporträt bei Statusbit f12/f19, krankes Porträt aus 0x20008 oder gesundes Porträt aus 0x20007) in den
 *   globalen Porträtpuffer d_1bc8f8 und gibt dessen Adresse zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den Zeiger/Handle des geladenen
 *   Porträtbildes (d_1bc8f8) zurück.
 * - Wichtige Variablen: Nutzt den Archiv-Manager d_1c2be0, den Zielpuffer d_1bc8f8 und die Porträtnummer
 *   *(short*)(p1 + 0x10).
 === Ende Beschreibung === */
int f_044ea0(int p1)
{
    int l18 = 0;
    short s;
    int id;

    if (((char)(f_042470((struct hero *)(p1))))) {
        s = d_1c2be0.f_050710(0x20007);
        d_1c2be0.f_04feb0(0x20007, d_1bc8f8, 0,
                          (short)(s - 8 - *(signed char *)&d_1a0e1d - 1),
                          0, &l18, &l18, 0x140);
    } else if (f_043c90(p1)) {
        s = d_1c2be0.f_050710(0x20008);
        d_1c2be0.f_04feb0(0x20008, d_1bc8f8, 0,
                          (short)(s - (f_042380((struct hero *)(p1)) ?
                                       *(signed char *)&d_1a0e1d - 1 :
                                       *(signed char *)&d_1a0e1d)),
                          0, &l18, &l18, 0x140);
    } else if (f_043ca0(p1)) {
        s = d_1c2be0.f_050710(0x20008);
        d_1c2be0.f_04feb0(0x20008, d_1bc8f8, 0, (short)(s - 1),
                          0, &l18, &l18, 0x140);
    } else {
        id = f_044e30(p1);

        if (((char)(f_042400((struct hero *)(p1))))) {
            s = d_1c2be0.f_050710(id);
            d_1c2be0.f_04feb0(id, d_1bc8f8, 0,
                              (short)((short)(s - 8 -
                                              *(signed char *)&d_1a0e1d - 1) +
                                      *(signed char *)(p1 + 0x9b)),
                              0, &l18, &l18, 0x140);
        } else {
            d_1c2be0.f_04feb0(id, d_1bc8f8, 0,
                              *(short *)(p1 + 0x10),
                              0, &l18, &l18, 0x140);
        }
    }
    return d_1bc8f8;
}
//@ f_045080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das gesunde (0x20007) oder geschwächte (0x20008) Porträt des Helden p1 direkt in das
 *   übergebene Rasterbild-Objekt p2 (ohne die Sonderfälle für Totenschädel oder Verwandlung).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie das Ziel-Rasterbild (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Lädt das Porträt über d_1c2be0.f_04feb0 in den Pixelpuffer f_0fb0b0(p2).
 === Ende Beschreibung === */
void f_045080(int p1, void *p2)
{
    int l14 = 0;
    int id = f_044e30(p1);
    if (((char)(f_042400((struct hero *)(p1))))) {
        short s = d_1c2be0.f_050710(id);
        d_1c2be0.f_04feb0(id, ((int)(((RivaRasterImage*)(p2))->f_0fb0b0())), 0,
                          (short)((short)(s - 8 -
                                          *(signed char *)&d_1a0e1d - 1) +
                                  *(signed char *)(p1 + 0x9b)),
                          0, &l14, &l14, 0x140);
    } else {
        d_1c2be0.f_04feb0(id, ((int)(((RivaRasterImage*)(p2))->f_0fb0b0())), 0,
                          *(short *)(p1 + 0x10),
                          0, &l14, &l14, 0x140);
    }
}
//@ f_045170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht die Abenteuerpunkte eines lebenden Helden (p1) über f_03af20 um p2 Punkte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die AP-Menge (p2) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Prüft f_042470 (nicht tot) und ruft f_03af20(p1, p2, 1) auf.
 === Ende Beschreibung === */
void f_045170(int p1, T2 p2)
{
    if (!((char)(f_042470((struct hero *)(p1))))) f_03af20(p1, (short)p2, 1);
}
//@ f_045190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den Hungerwert (hunger) eines lebenden Helden (p1) um p2 Prozentpunkte bis minimal
 *   0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Hungerminderung (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Hunger über f_042900 und schreibt den neuen Wert über f_042920.
 === Ende Beschreibung === */
void f_045190(int p1, T2 p2)
{
    short v;
    if (!((char)(f_042470((struct hero *)(p1))))) {
        v = f_042900((struct hero *)(p1)) - (short)p2;
        if (v < 0) v = 0;
        ((int)(f_042920((struct hero *)(p1), (signed char)v)));
    }
}
//@ f_0451c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den Durstwert (thirst) eines lebenden Helden (p1) um p2 Prozentpunkte bis minimal
 *   0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Durstminderung (p2) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest den Durst über f_042910 und schreibt den neuen Wert über f_042930.
 === Ende Beschreibung === */
void f_0451c0(int p1, T2 p2)
{
    short v;
    if (!((char)(f_042470((struct hero *)(p1))))) {
        v = f_042910((struct hero *)(p1)) - (short)p2;
        if (v < 0) v = 0;
        ((int)(f_042930((struct hero *)(p1), (signed char)v)));
    }
}
#pragma function(memset)
//@ f_0451f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Füllt das 8 Byte große Kampffeld ab Offset 0x553 der Heldenstruktur mit dem Wert p2.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie den Füllwert (p2) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Überschreibt 8 Bytes ab p1 + 0x553 per memset.
 === Ende Beschreibung === */
void f_0451f0(int p1, signed char p2)
{
    memset((char *)(p1 + 0x553), p2, 8);
}
//@ f_045210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Summe des Rüstungsschutzes der drei in d_1a0e1e hinterlegten Körperzonen-Slots
 *   des Helden p1 (unter Abzug etwaiger Rüstungsbeschädigungen f_042b50).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den summierten Rüstungsschutz als
 *   short zurück.
 * - Wichtige Variablen: Liest die Gegenstandsdefinitionen über d_1c2c40 und die Rüstungsschutztabelle d_1a47ac.
 === Ende Beschreibung === */
short f_045210(int p1)
{
    short res = 0;
    int sv = 0;
    short i;
    S6 loc = d_1a0e1e;
    union { int n; short w; } cc;
    for (i = 0; i < (short)3; i = i + 1) {
        sv = f_042a60((struct hero *)(p1), ((short *)&loc)[i]);
        if (sv > 0) {
            int off = sv * 4;
            if (((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + off)))->f_0a79b0() != 0) {
                cc.n = ((signed char)(((RivaItemDefinition*)(*(int *)((*(int*)&d_1c2c40) + off)))->f_0a78a0()));
                cc.w = d_1a47ac[cc.n * 2];
                res += cc.n;
                res -= ((int)(f_042b50((struct hero *)(p1), ((short *)&loc)[i])));
            }
        }
    }
    return res;
}
