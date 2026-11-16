/* === Beschreibung (Katalog) ===
 * Einheit gz_0350b0_t1 (0x0350b0 - 0x036300)
 *
 * Überblick
 * Dieser erste Teil des Inventar-Transfer-Moduls (0x0350b0 - 0x036ee0) enthält Hilfsfunktionen zur Abfrage des
 * Waffentalents der aktuell geführten Waffe (f_0350b0, f_035110), zum gezielten Entfernen einzelner Slots
 * einschließlich Questgegenständen (f_035180), zum Zählen eines bestimmten Gegenstands im gesamten
 * Heldeninventar (f_035260) sowie die zentrale Drag-and-Drop-Austauschfunktion f_0352c0, mit der Gegenstände
 * innerhalb eines Inventars oder zwischen zwei Helden verschoben, gestapelt und getauscht werden.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 2/5 gleich (suche.py 25.10.2026, Basis gz_0350b0_t1_P1.CPP)
// gz_0350b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0350B0-0x036EE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_033250(int p1, int p2);                           // reg edx stapel 0
int f_033260(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_033450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_033590(int p1, int p2);                           // reg eax edx stapel 0
int f_0335d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0338a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
signed char f_042400(int p1);
int f_042870(int p1, int p2);                           // reg eax edx stapel 0
int f_0429c0(int p1, int p2);                           // reg eax edx stapel 0
int f_042a40(int p1, int p2);                           // reg eax edx stapel 0
short f_042a60(int p1, int p2);
int f_042a90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042ac0(int p1, int p2);
int f_042af0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042b20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_042bb0(int p1, int p2);                           // reg eax edx stapel 0
short f_042fd0(int p1, int p2);
int f_043000(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
signed char f_043030(int p1, int p2);
int f_043060(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_043110(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_043170(int p1);
int f_043190(int p1, int p2);                           // reg eax edx stapel 0
int f_0431a0(int p1, int p2);                           // reg eax edx edx stapel 0
int f_0431d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0449d0(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0

                                   // reg eax stapel 0

                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
short f_149360(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a441f;                    // 0x1A441F
extern int d_1a47e9;                    // 0x1A47E9
extern int d_1a48aa;                    // 0x1A48AA
extern int d_1a6ad3;                    // 0x1A6AD3
extern int d_1bc894;                    // 0x1BC894
extern int d_1c2198;                    // 0x1C2198
extern int d_1c2a80;                    // 0x1C2A80

extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;
extern int d_1c3870;

extern int d_1c3498;
#define A(x) ((int)&(x))
#define B(p) (*(unsigned char *)(p))
#define SC(p) (*(signed char *)(p))
#define SH(p) (*(short *)(p))
struct Msg { int h; int *a; int x; int *b; int *c; short *d; int z[2]; short *e; int pad[6]; Msg(int *a, int *b, int *c); ~Msg(); };
struct Item { char b[27]; };
#define CX(m) Msg m(&d_1c349c, &d_1c3870, &d_1c3498)
int f_036300(int p1, int p2, int p3);
void f_036c10(int p1, int p2);
void f_036db0(int p1, int p2);

//@ f_0350b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt das zugehörige Waffentalent (0..8) der Waffe, die der Held p1 aktuell
 *   in der rechten Hand (Slot 3) führt, sofern es sich um eine intakte Waffe (!f_042bb0(p1, 3)) handelt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt den Waffentalent-Index (f_0a78b0())
 *   als short zurück, oder -1, wenn der Held unbewaffnet ist oder eine zerbrochene Waffe in der Hand hält.
 * - Wichtige Variablen: Geprüft wird der Gegenstand in Slot 3 (f_042a60(p1, 3)) über die Gegenstandsdefinition
 *   d_1c2c40[s].
 === Ende Beschreibung === */
short f_0350b0(int p1)
{
    short s = f_042a60(p1, 3);
    if (d_1c2c40[s]->f_0a7990() == 0 || f_042bb0(p1, 3) != 0) {
        return -1;
    }
    return (signed char)d_1c2c40[s]->f_0a78b0();
}

//@ f_035110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt analog zu f_0350b0 das Waffentalent der in der rechten Hand (Slot 3)
 *   geführten intakten Waffe, schließt jedoch Fernkampfwaffen (Talent 7 = Schusswaffen und Talent 8 =
 *   Wurfwaffen) aus, um ausschließlich das aktive *Nahkampf*-Waffentalent (0..6) zu liefern.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und gibt den Nahkampf-Talentindex (0..6) oder
 *   -1 (bei Fernkampfwaffe, zerbrochener Waffe oder Waffenlosigkeit) zurück.
 * - Wichtige Variablen: Bei c == 7 oder c == 8 wird der Rückgabewert v auf -1 gesetzt.
 === Ende Beschreibung === */
short f_035110(int p1)
{
    short s = f_042a60(p1, 3);
    signed char c;
    short v;
    if (d_1c2c40[s]->f_0a7990() != 0 && f_042bb0(p1, 3) == 0) {
        c = (signed char)d_1c2c40[s]->f_0a78b0();
        v = c;
        if (c == 7 || v == 8) v = -1;
    } else {
        v = -1;
    }
    return v;
}

//@ f_035180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion entfernt den gesamten Gegenstand bzw. Stapel im Inventarslot p2 eines Helden p1
 *   ohne Rückfrage (etwa durch ein Skript-Ereignis), wobei im Gegensatz zu f_036300 auch unwegwerfbare
 *   Questgegenstände (f_0a78f0() != 0) sauber samt Körperslot-Effekten (f_0335d0) und Gewicht gelöscht werden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und den Slot-Index p2 (unsigned short) und
 *   gibt 1 beim Löschen eines Questgegenstands oder 0 zurück.
 * - Wichtige Variablen: Bei normalen Gegenständen (f_0a78f0() == 0) delegiert die Funktion an f_036300(p1, p2,
 *   f_042ac0(p1, p2)) (wobei der Rückgabewert r im else-Zweig nicht gesetzt wird).
 === Ende Beschreibung === */
int f_035180(int p1, unsigned short p2)
{
    short r = 0;
    short s;
    s = SH(p1 + 0x1a8 + (short)p2 * 0x1b);
    if (s != (short)0) {
        if (d_1c2c40[s]->f_0a78f0() != 0) {
            if ((short)p2 < 0xf) {
                f_0335d0(p1, s, (short)p2);
            }
            B(p1 + 0x32) = B(p1 + 0x32) - 1;
            SH(p1 + 0x4ed) -= (int)d_1c2c40[s]->f_0a7810();
            memset((void *)(p1 + 0x1a8 + (short)p2 * 0x1b), 0, 0x1b);
            r = 1;
        } else {
            f_036300(p1, (short)p2, ((short (*)(int,int))f_042ac0)(p1, (short)p2));
        }
    }
    return r;
}

//@ f_035260
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion zählt über alle 31 Inventarslots (0..30) eines Helden p1 hinweg, wie viele
 *   Exemplare des Gegenstands p2 der Held insgesamt bei sich trägt (unter Berücksichtigung von Stapelgrößen bei
 *   stapelbaren Gegenständen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger p1 und die gesuchte Gegenstands-ID p2 und gibt
 *   die gefundene Gesamtstückzahl n zurück.
 * - Wichtige Variablen: Für stapelbare Gegenstände (f_0a7950() != 0) wird die Stückzahl f_042ac0(p1, i) addiert,
 *   für Einzelgegenstände jeweils 1.
 === Ende Beschreibung === */
int f_035260(int p1, int p2)
{
    int n = 0;
    short i;
    for (i = 0; i < 0x1f; i++) {
        if ((short)p2 == SH(p1 + 0x1a8 + i * 0x1b)) {
            if (d_1c2c40[(short)p2]->f_0a7950() != 0) {
                n = n + f_042ac0(p1, i);
            } else {
                n = n + 1;
            }
        }
    }
    return n;
}

//@ f_0352c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese große Kernfunktion führt das Verschieben, Stapeln und Tauschen von Gegenständen zwischen
 *   einem Quellhelden src (Slot from) und einem Zielhelden dst (Slot to) aus. Sie prüft vorab
 *   Handlungsfähigkeit, Traglastgrenzen, verfluchte Gegenstände, Magier-/Klassenverbote sowie Körperslot-Regeln
 *   (f_033450), fragt bei Stapeln die gewünschte Stückzahl ab, überträgt Giftladungen auf Waffen und ruft beim
 *   An- und Ablegen bzw. beim Besitzerwechsel die entsprechenden Bonusfunktionen (f_0335d0, f_0338a0, f_036c10,
 *   f_036db0) auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielhelden dst, den Quellhelden src, den Quellslot from
 *   (short) und den Zielslot to (short) und gibt 1 bei erfolgreichem Transfer oder 0 bei Abbruch bzw. Fehler
 *   zurück.
 * - Wichtige Variablen: item_from und item_to speichern die Gegenstands-IDs der beiden beteiligten Slots; w_from
 *   und w_to halten deren Gesamtgewicht für die Traglastprüfung gegen Tragkraft * 100 (siehe auch den
 *   dokumentierten Originalfehler in der Fehlerliste bei der Pluralabfrage im Rücktausch-Zweig).
 === Ende Beschreibung === */
#define COUNT(h,s) (((short (*)(int,int))f_042ac0)(h,s))
#define WEIGHT(i) (((RivaItemDefinition*)((*(int **)&d_1c2c40)[i]))->f_0a7810())
int f_0352c0(int dst, int src, short from, short to)
{
    struct GhostShape1_A19G{char pad[1];};
    struct GhostShape2_A19G{char pad[2];};
    struct GhostShape3_A19G{char pad[3];};
    struct GhostShape4_A19G{char pad[4];};
    struct GhostShape5_A19G{char pad[5];};
    struct GhostShape6_A19G{char pad[6];};
    struct GhostShape7_A19G{char pad[7];};
    struct GhostShape8_A19G{char pad[8];};
    struct GhostShape9_A19G{char pad[9];};
    struct GhostShape10_A19G{char pad[10];};
    struct GhostShape11_A19G{char pad[11];};
    struct GhostShape12_A19G{char pad[12];};
    struct GhostShape13_A19G{char pad[13];};
    struct GhostShape14_A19G{char pad[14];};
    struct GhostShape15_A19G{char pad[15];};
    struct GhostShape16_A19G{char pad[16];};
    struct GhostShape17_A19G{char pad[17];};
    struct GhostShape18_A19G{char pad[18];};
    struct GhostShape19_A19G{char pad[19];};
    struct GhostShape20_A19G{char pad[20];};
    struct GhostShape21_A19G{char pad[21];};
    struct GhostShape22_A19G{char pad[22];};
    struct GhostShape23_A19G{char pad[23];};
    struct GhostShape24_A19G{char pad[24];};
    struct GhostShape25_A19G{char pad[25];};
    struct GhostShape26_A19G{char pad[26];};
    struct GhostShape27_A19G{char pad[27];};
    struct GhostShape28_A19G{char pad[28];};
    struct GhostShape29_A19G{char pad[29];};
    struct GhostShape30_A19G{char pad[30];};
    struct GhostShape31_A19G{char pad[31];};
    struct GhostShape32_A19G{char pad[32];};
    struct GhostShape64_A19G{char pad[64];};
    struct GhostShape128_A19G{char pad[128];};
    volatile GhostShape1_A19G ghost_0_A19G;
    short cnt;
    short v90;
    volatile GhostShape3_A19G ghost_1_A19G;
    short st_to;
    short item_to;
    short v_to;
    short v6c;
    short item_from;
    short w_from;
    short w_to;
    int r=1;
    short st_from;
    short do_swap;
    short v;
    // KRUECKE A20T: unbenutzte volatile Sortierknoten, ohne Laufzeitwirkung.
    struct LocalMsg{int h;int*a;int x;int*b;int*c;short*d;int z[2];short*e;int pad[6];LocalMsg(int *p,int *q,int *r){f_125400((int)this,(int)p,(int)q,(int)r);}~LocalMsg(){((int(*)(int,int))f_1254a0)((int)this,0);}};LocalMsg m(&d_1c349c,&d_1c3870,&d_1c3498);  // KRUECKE: kurze Kontextaliase steuern die Namens-/Stapelplatzliste
    {volatile GhostShape18_A19G ghost_2_A19G; volatile GhostShape1_A19G ghost_3_A19G; volatile GhostShape1_A19G ghost_4_A19G; volatile GhostShape27_A19G ghost_5_A19G; volatile GhostShape8_A19G ghost_6_A19G; volatile GhostShape4_A19G ghost_7_A19G; volatile GhostShape2_A19G ghost_8_A19G; volatile GhostShape1_A19G ghost_9_A19G; volatile GhostShape1_A19G ghost_10_A19G; volatile GhostShape1_A19G ghost_11_A19G; volatile GhostShape1_A19G ghost_12_A19G; volatile GhostShape1_A19G ghost_13_A19G; volatile GhostShape64_A19G ghost_14_A19G; volatile GhostShape2_A19G ghost_15_A19G; volatile GhostShape1_A19G ghost_16_A19G; volatile GhostShape1_A19G ghost_17_A19G; volatile GhostShape1_A19G ghost_18_A19G; volatile GhostShape1_A19G ghost_19_A19G; volatile GhostShape1_A19G ghost_20_A19G; volatile GhostShape6_A19G ghost_21_A19G; volatile GhostShape1_A19G ghost_22_A19G; volatile GhostShape64_A19G ghost_23_A19G; volatile GhostShape1_A19G ghost_24_A19G; volatile GhostShape3_A19G ghost_25_A19G; volatile GhostShape2_A19G ghost_26_A19G; volatile GhostShape1_A19G ghost_27_A19G; volatile GhostShape4_A19G ghost_28_A19G; volatile GhostShape1_A19G ghost_29_A19G; volatile GhostShape1_A19G ghost_30_A19G; volatile GhostShape12_A19G ghost_31_A19G; volatile GhostShape2_A19G ghost_32_A19G; volatile GhostShape2_A19G ghost_33_A19G; volatile GhostShape4_A19G ghost_34_A19G; volatile GhostShape2_A19G ghost_35_A19G; volatile GhostShape7_A19G ghost_36_A19G; volatile GhostShape64_A19G ghost_37_A19G; volatile GhostShape16_A19G ghost_38_A19G; volatile GhostShape17_A19G ghost_39_A19G; volatile GhostShape1_A19G ghost_40_A19G; volatile GhostShape23_A19G ghost_41_A19G; volatile GhostShape1_A19G ghost_42_A19G; volatile GhostShape1_A19G ghost_43_A19G; volatile GhostShape25_A19G ghost_44_A19G; volatile GhostShape4_A19G ghost_45_A19G; volatile GhostShape4_A19G ghost_46_A19G; volatile GhostShape1_A19G ghost_47_A19G; volatile GhostShape3_A19G ghost_48_A19G; volatile GhostShape1_A19G ghost_49_A19G; volatile GhostShape1_A19G ghost_50_A19G; short unused_=(short)(m.h);(void)unused_;} // KRUECKE: Quellposition steuert Namensliste
    item_to = 0; // KRUECKE: tote Vorinitialisierung (Platzliste)
    if (dst == src && to == from) {
        return 1;
    }
    item_from = f_042a60(src, from);
    item_to = f_042a60(dst, to);
    if (SC(f_0431a0(src, from) + 9) > 0 && SC(dst + 0x33) == 3) {
        f_0bf730(A(d_1c2c64), 0x501003a);
        return 0;
    }
    if (dst != src && (item_from == 0x1bc || item_to == 0x1bc)) {
        d_1bc894 = 1;
    }
    if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_from]))->f_0a78f0() != 0 && (f_149360(item_from, A(d_1a48aa)) == -1 || f_042400(dst) != 0)) {
        m.a[1] = src;
        m.b[1] = (*(int **)&d_1c2c40)[item_from];
        m.e[1] = 1;
        f_0bf730(A(d_1c2c64), 0x20000032);
    } else {
        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a78f0() != 0 && (f_149360(item_to, A(d_1a48aa)) == -1 || f_042400(src) != 0)) {
            m.a[1] = dst; { volatile GhostShape6_A19G ghost_51_A19G; volatile GhostShape4_A19G ghost_52_A19G; volatile GhostShape1_A19G ghost_53_A19G; volatile GhostShape15_A19G ghost_54_A19G; int *g_ = (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = g_; } // KRUECKE: Global-Roundtrip (Nutzwertliste)
            m.b[1] = (*(int **)&d_1c2c40)[item_to];
            m.e[1] = 1;
            f_0bf730(A(d_1c2c64), 0x20000032);
            return 0;
        }
        if (to < 0xf) {
            if (f_033250(dst, item_from) == 0) {
                m.a[1] = dst;
                {int*h_=(*(int **)&d_1c2c40);(*(int **)&d_1c2c40)=h_;}m.b[1]=(*(int **)&d_1c2c40)[item_from]; // KRUECKE: Global-Roundtrip (Nutzwertliste)
                m.e[1] = 1;
                m.c[1] = f_040e90(dst);
                f_0bf730(A(d_1c2c64), 0x20000106);
                return 0;
            }
            if (f_033260(dst, item_from, to) == 0) {
                m.b[1] = (*(int **)&d_1c2c40)[item_from];
                m.e[1] = 1;
                if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_from]))->f_0a7ad0() != 0 || (COUNT(src, from) > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_from]))->f_0a7950() != 0)) {
                    m.c[1] = 0x20000108;
                    m.e[1] = COUNT(src, from);
                } else {
                    m.c[1] = 0x20000109;
                }
                f_0bf730(A(d_1c2c64), 0x20000107);
                return 0;
            }
            if (f_033450(dst, item_from, to, src, from) != 0) {
                m.a[1] = dst;
                f_0bf730(A(d_1c2c64), 0x2000010a);
                return 0;
            }
        }
        if (item_to && from < 0xf) {
            if (f_033250(src, item_to) == 0) {
                m.a[1] = src;
                struct Cell{int x;int&get(){return x;}};m.b[1]=((Cell*)&(*(int **)&d_1c2c40)[item_to])->get(); // KRUECKE
                m.e[1] = 1;
                m.c[1] = f_040e90(src);
                f_0bf730(A(d_1c2c64), 0x20000106);
                return 0;
            }
            if (f_033260(src, item_to, from) == 0) {
                struct C{int x;int&get(){int*p=(*(int **)&d_1c2c40);(*(int **)&d_1c2c40)=p;return x;}};m.b[1]=((C*)&(*(int **)&d_1c2c40)[item_to])->get();
                m.e[1] = 1;
#if FIX_R021   /* R021: Pluralpruefung beim Gegenstandstausch auf item_to statt Kopierfehler item_from */
                if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a7ad0() != 0 || (COUNT(dst, to) > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a7950() != 0)) {
#else
                if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a7ad0() != 0 || (COUNT(dst, to) > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_from]))->f_0a7950() != 0)) {
#endif
                    m.c[1] = 0x20000108;
                    m.e[1] = COUNT(dst, to);
                } else {
                    m.c[1] = 0x20000109;
                }
                f_0bf730(A(d_1c2c64), 0x20000107);
                return 0;
            }
            if (f_033450(src, item_to, from, dst, to) != 0) {
                m.a[1] = src;
                f_0bf730(A(d_1c2c64), 0x2000010a);
                return 0;
            }
        }
        if (item_to) {
            short v_from; { short *pwf_ = &w_from; (void)pwf_; } do_swap = 1; // KRUECKE: do_swap im Speicher wie Original
            if (item_to == item_from && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a7950() != 0) {
                do_swap = 0;
                cnt = 1;
                if (COUNT(src, from) > 1) {
                    m.a[1] = src;
                    m.d[1] = COUNT(src, from);
                    m.b[1] = (*(int **)&d_1c2c40)[item_from];
                    m.e[1] = 2;
                    cnt = f_0bf7b0(A(d_1c2c64), 2, 0x2000010e, 0, COUNT(src, from), COUNT(src, from));
                }
                if (COUNT(src, from) < cnt) {
                    cnt = COUNT(src, from);
                }
                if (cnt > 0 && COUNT(dst, to) < 99) {
                    if (COUNT(dst, to) + cnt > 99) {
                        cnt = 99 - COUNT(dst, to);
                    }
struct Tab{static int* get(){int*p=(*(int **)&d_1c2c40);(*(int **)&d_1c2c40)=p;return p;}};

                    while (!((((RivaItemDefinition*)(Tab::get()[item_from]))->f_0a7810()) * cnt + SH(dst + 0x4ed) < SC(f_0429c0(dst, 6) + 1) * 100) && cnt > 0) {
                        cnt--;
                    }
                    if (cnt > 0) {
                        if (f_043030(src, from) > 0) {
                             v_from = f_043030(src, from);
                            st_from = f_042fd0(src, from);
                            v_to = f_043030(dst, to); {short u_=v_to;v_to=u_;} // KRUECKE: kurze Kopie erhoeht die Registerprioritaet
                            st_to = f_042fd0(dst, to);
                            v=v_from;v_from=0;if(v<cnt){}else v=cnt;

                            if (st_from == st_to) {
                                v_to += v;
                            } else {
                                v_to = v;
                            }
                            st_to = st_from;
                            f_043000(dst, to, (signed char)st_to);
                            f_043060(dst, to, (signed char)v_to);
                        }
                        f_043190(dst, (short)(WEIGHT(item_from) * cnt));
                        f_042b20(dst, to, (signed char)cnt);
                        f_036300(src, from, cnt);
                    } else {
                        m.a[1] = dst;
                        f_0bf730(A(d_1c2c64), 0x2000010f);
                    }
                } else {
                    r = 0;
                }
                if (COUNT(src, from)) {
                    SH(A(d_1c2198)) = r = 0;
                }
            } else if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_to]))->f_0a7950() != 0 && !item_from) {
                do_swap = 0;
                cnt = 1;
                if (COUNT(dst, to) > 1) {
                    m.a[1] = dst;
                    m.d[1] = COUNT(dst, to);
                    m.b[1] = (*(int **)&d_1c2c40)[item_to];
                    m.e[1] = 2;
                    cnt = f_0bf7b0(A(d_1c2c64), 2, 0x2000010e, 0, COUNT(dst, to), COUNT(dst, to));
                }
                if (cnt > 0) {
                    if (COUNT(dst, to) < cnt) {
                        cnt = COUNT(dst, to);
                    }
struct Scale{static int n(short i){int q=i*4;{int p=q;q=p;}return q;}};
                    while ((((RivaItemDefinition*)(*(int*)((char*)(*(int **)&d_1c2c40)+Scale::n(item_to))))->f_0a7810()) * cnt + f_043170(src) >= SC(f_0429c0(src, 6) + 1) * 100 && cnt > 0) {
                        cnt--;
                    }
                    if (cnt > 0) {
                        f_0431d0(src, from, f_0431a0(dst, to));
                        if (f_043030(dst, to) > 0) {
                            short n = f_043030(dst, to);
                            short st = f_042fd0(dst, to);
                            if (n >= cnt) n = cnt;
                            {short *vp=&v90;(void)vp;} v90 = n;
                            f_043000(src, from, (signed char)st);
                            f_043060(src, from, (signed char)v90);
                        }
                        f_043190(src, (short)(WEIGHT(item_to) * cnt));
                        f_042af0(src, from, (signed char)cnt);
                        f_036300(dst, to, cnt);
                        f_042870(src, 1);
                    } else {
                        m.a[1] = src;
                        f_0bf730(A(d_1c2c64), 0x2000010f);
                    }
                } else {
                    r = 0;
                }
            }
            if (do_swap == 1) {
                v_to = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[item_from]))->f_0a7950() ? COUNT(src, from) * WEIGHT(item_from) : WEIGHT(item_from);  // KRUECKE: Nutzwert fuer Stapelplatzfolge

                // KRUECKE: Inline-Kurzparameter erhalten die fuer die Register-/Platzvergabe benoetigten Rueckgabenamen.
                {struct H {static int n(short x){return x;}};int q_,w_;int entry=(*(int **)&d_1c2c40)[item_to];w_from=v_to;w_to=((RivaItemDefinition*)entry)->f_0a7950() ? (q_=H::n(COUNT(dst,to)),w_=H::n(WEIGHT(item_to)),w_*q_) : WEIGHT(item_to);}
                { int wf_,wt_; if ((cnt=f_043170(dst),wf_=w_from,wt_=w_to,cnt + wf_ - wt_) >= SC(f_0429c0(dst, 6) + 1) * 100) {
                    m.a[1] = dst;
                    f_0bf730(A(d_1c2c64), 0x2000010f);
                } else if (f_043170(src) + wt_ - wf_ >= SC(f_0429c0(src, 6) + 1) * 100) {
                    m.a[1] = src;
                    f_0bf730(A(d_1c2c64), 0x2000010f);
                } else {
                    if (from < 0xf) {
                        f_0335d0(src, item_from, from);
                        f_0338a0(src, dst, item_to, to, from);
                    }
                    if (to < 0xf) {
                        f_0335d0(dst, item_to, to);
                        f_0338a0(dst, src, item_from, from, to);
                    }
                    Item tmp = *(Item *)f_0431a0(dst, to);
                    f_043190(dst, (short)-w_to);
                    f_0431d0(dst, to, f_0431a0(src, from));
                    f_043190(dst, w_from);
                    f_043190(src, (short)-w_from);
                    f_0431d0(src, from, (int)&tmp);
                    f_043190(src, w_to); if ((to=(item_from&0)?0:item_from)) {
                        f_042870(src, -1);
                        f_042870(dst, 1);
                    }
                    if (item_to) {
                        f_042870(src, 1);
                        f_042870(dst, -1);
                    }
                    { int from_item = (item_from & 0) ? 0 : item_from; // KRUECKE
                    int to_item = (item_to & 0) ? 0 : item_to;
                    f_036db0(dst, to_item);
                    f_036c10(dst, from_item);
                    f_036db0(src, from_item);
                    f_036c10(src, to_item);
                    }
                }
            }
            }
        } else {
            struct T{static int*get(){int*p=(*(int **)&d_1c2c40);(*(int **)&d_1c2c40)=p;return p;}};if(((RivaItemDefinition*)(T::get()[item_from]))->f_0a7950()!=0){
                cnt = 1;
                if (COUNT(src, from) > 1) {
                    m.a[1] = src;
                    m.d[1] = COUNT(src, from);
                    m.b[1] = (*(int **)&d_1c2c40)[item_from];
                    m.e[1] = 2;
                    cnt = f_0bf7b0(A(d_1c2c64), 2, 0x2000010e, 0, COUNT(src, from), COUNT(src, from));
                }
                if (cnt > 0) {
                    if (COUNT(src, from) < cnt) {
                        cnt = COUNT(src, from);
                    }
                    while (!(f_043170(dst) + WEIGHT(item_from) * cnt < SC(f_0429c0(dst, 6) + 1) * 100) && cnt > 0) {
                        cnt--;
                    }
                    if (cnt > 0) {
                        f_0431d0(dst, to, f_0431a0(src, from));
                        if (f_043030(src, from) > 0) {
                            short n = f_043030(src, from); {short u_0=n;n=u_0;}
                            short st = f_042fd0(src, from);
                            if (n >= cnt) n = cnt;
                            {short *vq=&v6c;(void)vq;} v6c = n;
                            f_043000(dst, to, (signed char)st);
                            f_043060(dst, to, (signed char)v6c);
                        }
                        f_043190(dst, (short)(WEIGHT(item_from) * cnt));
                        f_042af0(dst, to, (signed char)cnt);
                        f_036300(src, from, cnt);
                        f_042870(dst, 1);
                    } else {
                        m.a[1] = dst;
    {short unused_=(short)(m.x);(void)unused_;} // KRUECKE: Quellposition steuert Namensliste
                        f_0bf730(A(d_1c2c64), 0x2000010f);
                    }
                } else {
                    r = 0;
                }
            } else {
                if (f_043170(dst) + WEIGHT(item_from) >= SC(f_0429c0(dst, 6) + 1) * 100) {
                    m.a[1] = dst;
                    f_0bf730(A(d_1c2c64), 0x2000010f);
                } else {
                    if (from < 0xf) {
                        f_0335d0(src, item_from, from);
                    }
                    if (to < 0xf) {
                        f_0338a0(dst, src, item_from, from, to);
                    }
                    f_0431d0(dst, to, f_0431a0(src, from));
                    f_043190(dst, WEIGHT(item_from));
                    f_043190(src, (short)-WEIGHT(item_from));
                    f_042870(src, -1);
                    f_042870(dst, 1);
                    memset((void *)(src + 0x1a8 + from * 0x1b), 0, 0x1b);
                    f_036c10(dst, item_from);
                    f_036db0(src, item_from);
                }
            }
            if (COUNT(src, from)) {
                SH(A(d_1c2198)) = r = 0;
            }
        }
    }
    return r;
}



#undef COUNT
#undef WEIGHT
